#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "ABBAurora.h"

namespace esphome {
namespace abbaurora {

class ABBAuroraSensor : public PollingComponent, public sensor::Sensor {
 public:
  ABBAuroraSensor() : PollingComponent(60000) {}

  void setup() override;
  void update() override;
  void dump_config() override;

  void set_power_sensor(sensor::Sensor *power_sensor) { power_sensor_ = power_sensor; }
  void set_voltage_sensor(sensor::Sensor *voltage_sensor) { voltage_sensor_ = voltage_sensor; }
  void set_current_sensor(sensor::Sensor *current_sensor) { current_sensor_ = current_sensor; }
  void set_frequency_sensor(sensor::Sensor *frequency_sensor) { frequency_sensor_ = frequency_sensor; }
  void set_riso_sensor(sensor::Sensor *riso_sensor) { riso_sensor_ = riso_sensor; }
  void set_ileak_sensor(sensor::Sensor *ileak_sensor) { ileak_sensor_ = ileak_sensor; }
  void set_power_peak_sensor(sensor::Sensor *power_peak_sensor) { power_peak_sensor_ = power_peak_sensor; }
  void set_power_peak_today_sensor(sensor::Sensor *power_peak_today_sensor) { power_peak_today_sensor_ = power_peak_today_sensor; }
  void set_temp_inverter_sensor(sensor::Sensor *temp_inverter_sensor) { temp_inverter_sensor_ = temp_inverter_sensor; }
  void set_temp_booster_sensor(sensor::Sensor *temp_booster_sensor) { temp_booster_sensor_ = temp_booster_sensor; }
  void set_power_1_sensor(sensor::Sensor *power_1_sensor) { power_1_sensor_ = power_1_sensor; }
  void set_power_2_sensor(sensor::Sensor *power_2_sensor) { power_2_sensor_ = power_2_sensor; }
  void set_voltage_1_sensor(sensor::Sensor *voltage_1_sensor) { voltage_1_sensor_ = voltage_1_sensor; }
  void set_voltage_2_sensor(sensor::Sensor *voltage_2_sensor) { voltage_2_sensor_ = voltage_2_sensor; }
  void set_current_1_sensor(sensor::Sensor *current_1_sensor) { current_1_sensor_ = current_1_sensor; }
  void set_current_2_sensor(sensor::Sensor *current_2_sensor) { current_2_sensor_ = current_2_sensor; }
  void set_energy_daily_sensor(sensor::Sensor *energy_daily_sensor) { energy_daily_sensor_ = energy_daily_sensor; }
  void set_energy_total_sensor(sensor::Sensor *energy_total_sensor) { energy_total_sensor_ = energy_total_sensor; }

 protected:
  ABBAurora *inverter_;
  sensor::Sensor *power_sensor_{nullptr};
  sensor::Sensor *voltage_sensor_{nullptr};
  sensor::Sensor *current_sensor_{nullptr};
  sensor::Sensor *frequency_sensor_{nullptr};
  sensor::Sensor *riso_sensor_{nullptr};
  sensor::Sensor *ileak_sensor_{nullptr};
  sensor::Sensor *power_peak_sensor_{nullptr};
  sensor::Sensor *power_peak_today_sensor_{nullptr};
  sensor::Sensor *temp_inverter_sensor_{nullptr};
  sensor::Sensor *temp_booster_sensor_{nullptr};
  sensor::Sensor *power_1_sensor_{nullptr};
  sensor::Sensor *power_2_sensor_{nullptr};
  sensor::Sensor *voltage_1_sensor_{nullptr};
  sensor::Sensor *voltage_2_sensor_{nullptr};
  sensor::Sensor *current_1_sensor_{nullptr};
  sensor::Sensor *current_2_sensor_{nullptr};
  sensor::Sensor *energy_daily_sensor_{nullptr};
  sensor::Sensor *energy_total_sensor_{nullptr};
};

}  // namespace abbaurora
}  // namespace esphome