#include "abbaurora_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace abbaurora {

static const char *const TAG = "abbaurora.sensor";

#define INVERTER_ADDRESS 2

void ABBAuroraSensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up ABBAurora Sensor...");
  ABBAurora::setup(Serial);
  this->inverter_ = new ABBAurora(INVERTER_ADDRESS);
}

void ABBAuroraSensor::update() {
  if (this->power_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(GRID_POWER, GLOBAL_MESSUREMENT)) {
      this->power_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->voltage_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(GRID_VOLTAGE, GLOBAL_MESSUREMENT)) {
      this->voltage_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->current_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(GRID_CURRENT, GLOBAL_MESSUREMENT)) {
      this->current_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->frequency_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(FREQUENCY, GLOBAL_MESSUREMENT)) {
      this->frequency_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->riso_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(ISOLATION_RESISTANCE, GLOBAL_MESSUREMENT)) {
      this->riso_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->ileak_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(I_LEAK_INVERTER, GLOBAL_MESSUREMENT)) {
      this->ileak_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->power_peak_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(POWER_PEAK, GLOBAL_MESSUREMENT)) {
      this->power_peak_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->power_peak_today_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(POWER_PEAK_TODAY, GLOBAL_MESSUREMENT)) {
      this->power_peak_today_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->temp_inverter_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(TEMPERATURE_INVERTER, GLOBAL_MESSUREMENT)) {
      this->temp_inverter_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->temp_booster_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(TEMPERATURE_BOOSTER, GLOBAL_MESSUREMENT)) {
      this->temp_booster_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->power_1_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(POWER_IN_1, MODULE_MESSUREMENT)) {
      this->power_1_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->power_2_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(POWER_IN_2, MODULE_MESSUREMENT)) {
      this->power_2_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->voltage_1_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(V_IN_1, MODULE_MESSUREMENT)) {
      this->voltage_1_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->voltage_2_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(V_IN_2, MODULE_MESSUREMENT)) {
      this->voltage_2_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->current_1_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(I_IN_1, MODULE_MESSUREMENT)) {
      this->current_1_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->current_2_sensor_ != nullptr) {
    if (inverter_->ReadDSPValue(I_IN_2, MODULE_MESSUREMENT)) {
      this->current_2_sensor_->publish_state(inverter_->DSP.Value);
    }
  }
  
  if (this->energy_daily_sensor_ != nullptr) {
    if (inverter_->ReadCumulatedEnergy(CURRENT_DAY)) {
      unsigned long energyD = inverter_->CumulatedEnergy.Energy;
      this->energy_daily_sensor_->publish_state(energyD/1000.0);
    }
  }
  
  if (this->energy_total_sensor_ != nullptr) {
    if (inverter_->ReadCumulatedEnergy(TOTAL)) {
      unsigned long energyT = inverter_->CumulatedEnergy.Energy;
      this->energy_total_sensor_->publish_state(energyT/1000.0);
    }
  }
}

void ABBAuroraSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "ABBAurora Sensor:");
  LOG_UPDATE_INTERVAL(this);
}

}  // namespace abbaurora
}  // namespace esphome