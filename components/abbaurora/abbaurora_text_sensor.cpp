#include "abbaurora_text_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace abbaurora {

static const char *const TAG = "abbaurora.text_sensor";

#define INVERTER_ADDRESS 2

void ABBAuroraTextSensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up ABBAurora Text Sensor...");
  ABBAurora::setup(Serial);
  this->inverter_ = new ABBAurora(INVERTER_ADDRESS);
  this->inverterStrings_ = new ABBAuroraStrings();
}

void ABBAuroraTextSensor::update() {
  if (this->version_sensor_ != nullptr) {
    if (inverter_->ReadVersion()) {
      String versione = String(inverter_->Version.Par1 + " " + inverter_->Version.Par2 + " " + inverter_->Version.Par3 + " " + inverter_->Version.Par4);
      this->version_sensor_->publish_state(versione.c_str());
    }
  }
  
  if (inverter_->ReadState()) {
    if (this->inverter_state_sensor_ != nullptr) {
      String inverterState = String(inverterStrings_->InverterState(inverter_->State.InverterState));
      this->inverter_state_sensor_->publish_state(inverterState.c_str());
    }
    
    if (this->global_state_sensor_ != nullptr) {
      String globalState = String(inverterStrings_->GlobalState(inverter_->State.GlobalState));
      this->global_state_sensor_->publish_state(globalState.c_str());
    }
    
    if (this->channel1_state_sensor_ != nullptr) {
      String channel1 = String(inverterStrings_->DcDcState(inverter_->State.Channel1State));
      this->channel1_state_sensor_->publish_state(channel1.c_str());
    }
    
    if (this->channel2_state_sensor_ != nullptr) {
      String channel2 = String(inverterStrings_->DcDcState(inverter_->State.Channel2State));
      this->channel2_state_sensor_->publish_state(channel2.c_str());
    }
    
    if (this->alarm_sensor_ != nullptr) {
      String alarm = String(inverterStrings_->AlarmState(inverter_->State.AlarmState));
      this->alarm_sensor_->publish_state(alarm.c_str());
    }
  }
}

void ABBAuroraTextSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "ABBAurora Text Sensor:");
  LOG_UPDATE_INTERVAL(this);
}

}  // namespace abbaurora
}  // namespace esphome