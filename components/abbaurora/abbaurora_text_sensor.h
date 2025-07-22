#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "ABBAurora.h"
#include "ABBAuroraStrings.h"

namespace esphome {
namespace abbaurora {

class ABBAuroraTextSensor : public PollingComponent, public text_sensor::TextSensor {
 public:
  ABBAuroraTextSensor() : PollingComponent(120000) {}

  void setup() override;
  void update() override;
  void dump_config() override;

  void set_version_sensor(text_sensor::TextSensor *version_sensor) { version_sensor_ = version_sensor; }
  void set_inverter_state_sensor(text_sensor::TextSensor *inverter_state_sensor) { inverter_state_sensor_ = inverter_state_sensor; }
  void set_global_state_sensor(text_sensor::TextSensor *global_state_sensor) { global_state_sensor_ = global_state_sensor; }
  void set_channel1_state_sensor(text_sensor::TextSensor *channel1_state_sensor) { channel1_state_sensor_ = channel1_state_sensor; }
  void set_channel2_state_sensor(text_sensor::TextSensor *channel2_state_sensor) { channel2_state_sensor_ = channel2_state_sensor; }
  void set_alarm_sensor(text_sensor::TextSensor *alarm_sensor) { alarm_sensor_ = alarm_sensor; }

 protected:
  ABBAurora *inverter_;
  ABBAuroraStrings *inverterStrings_;
  text_sensor::TextSensor *version_sensor_{nullptr};
  text_sensor::TextSensor *inverter_state_sensor_{nullptr};
  text_sensor::TextSensor *global_state_sensor_{nullptr};
  text_sensor::TextSensor *channel1_state_sensor_{nullptr};
  text_sensor::TextSensor *channel2_state_sensor_{nullptr};
  text_sensor::TextSensor *alarm_sensor_{nullptr};
};

}  // namespace abbaurora
}  // namespace esphome