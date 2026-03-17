#pragma once

#include <array>
#include <cstdint>
#include <utility>

namespace esphome::hayward::protocol {

struct FaultDescriptor {
  uint16_t address;
  uint16_t mask;
  const char *code;
  const char *description;
};

static constexpr uint8_t FC_READ_HOLDING = 0x03;
static constexpr uint8_t FC_READ_INPUT = 0x04;
static constexpr uint8_t FC_WRITE_SINGLE = 0x06;
static constexpr uint8_t FC_WRITE_MULTIPLE = 0x10;

static constexpr uint16_t REG_POWER_COMMAND = 1011;
static constexpr uint16_t REG_MODE_COMMAND = 1012;
static constexpr uint16_t REG_TARGET_TEMPERATURE = 1013;
static constexpr uint16_t REG_POWER_COMMAND_2 = 1014;
static constexpr uint16_t REG_CAPABILITY_MODE = 1019;
static constexpr uint16_t REG_SILENT_SCHEDULE_START_HOUR = 1068;
static constexpr uint16_t REG_SILENT_SCHEDULE_STOP_HOUR = 1069;
static constexpr uint16_t REG_SILENT_SCHEDULE_ACTIVE = 1072;
static constexpr uint16_t REG_SILENT_ACTIVE = 1076;
static constexpr uint16_t REG_SAVED_COOL_TEMPERATURE = 1135;
static constexpr uint16_t REG_SAVED_HEAT_TEMPERATURE = 1136;
static constexpr uint16_t REG_SAVED_AUTO_TEMPERATURE = 1137;
static constexpr uint16_t REG_POWER_ON_HOUR = 1150;
static constexpr uint16_t REG_POWER_OFF_HOUR = 1152;
static constexpr uint16_t REG_POWER_ON_SCHEDULE_ACTIVE = 1158;
static constexpr uint16_t REG_POWER_OFF_SCHEDULE_ACTIVE = 1159;
static constexpr uint16_t REG_POWER_STATUS = 2011;
static constexpr uint16_t REG_MODE_STATUS = 2012;
static constexpr uint16_t REG_OUTPUT_FLAGS = 2019;
static constexpr uint16_t REG_COMPRESSOR_OUTPUT_CURRENT = 2022;
static constexpr uint16_t REG_SWITCH_FLAGS = 2034;
static constexpr uint16_t REG_SUCTION_TEMPERATURE = 2045;
static constexpr uint16_t REG_INLET_TEMPERATURE = 2046;
static constexpr uint16_t REG_OUTLET_TEMPERATURE = 2047;
static constexpr uint16_t REG_COIL_TEMPERATURE = 2048;
static constexpr uint16_t REG_AMBIENT_TEMPERATURE = 2049;
static constexpr uint16_t REG_EXHAUST_TEMPERATURE = 2050;
static constexpr uint16_t REG_COMPRESSOR_CURRENT = 2051;
static constexpr uint16_t REG_AC_FAN_OUTPUT = 2052;
static constexpr uint16_t REG_PRESSURE_SENSOR = 2054;
static constexpr uint16_t REG_SUPER_HEAT = 2060;
static constexpr uint16_t REG_TARGET_SPEED_FAN_MOTOR = 2061;
static constexpr uint16_t REG_OVER_HEAT_AFTER_COMMPEN = 2062;
static constexpr uint16_t REG_INVERTER_PLATE_AC_VOLTAGE = 2063;
static constexpr uint16_t REG_ANTIFREEZE_TEMPERATURE = 2064;
static constexpr uint16_t REG_SPEED_FAN_MOTOR_1 = 2067;
static constexpr uint16_t REG_FAILURE_FLAGS = 2074;
static constexpr uint16_t REG_PROTECTION_FLAGS = 2075;
static constexpr uint16_t REG_INVERTER_FAILURE_FLAGS = 2076;
static constexpr uint16_t REG_FAN_FAILURE_FLAGS = 2077;
static constexpr uint16_t REG_STATUS_ADDRESS = 3010;
static constexpr uint16_t REG_PANEL_STATUS_FLAGS = 3011;
static constexpr uint16_t REG_PANEL_HOUR = 3015;
static constexpr uint16_t REG_PANEL_MINUTE = 3016;
static constexpr uint16_t REG_PANEL_SECOND = 3017;

static constexpr uint16_t SETTINGS_START = 1001;
static constexpr uint16_t SETTINGS_END = 1090;
static constexpr uint16_t SETTINGS_COUNT = 90;
static constexpr uint16_t EXTRA_SETTINGS_START = 1091;
static constexpr uint16_t EXTRA_SETTINGS_END = 1180;
static constexpr uint16_t EXTRA_SETTINGS_COUNT = 90;
static constexpr uint16_t STATUS_START = 3001;
static constexpr uint16_t STATUS_END = 3090;
static constexpr uint16_t STATUS_COUNT = 90;

static constexpr uint16_t FLAG_SETTINGS_APPLYING = 0x0001;
static constexpr uint16_t FLAG_SETTINGS_UPDATE = 0x0004;
static constexpr uint16_t FLAG_EXTRA_SETTINGS_UPDATE = 0x0010;
static constexpr uint16_t FLAG_NEEDS_UPDATES = 0x8000;

static constexpr std::array<FaultDescriptor, 53> FAULT_DESCRIPTORS{{
    {2074, 0x0001, "P01", "Inlet water temperature failure"},
    {2074, 0x0002, "P02", "Water outlet temperature failure"},
    {2074, 0x0004, "P04", "Ambient temperature failure"},
    {2074, 0x0008, "P05", "Coil temperature failure"},
    {2074, 0x0010, "P07", "Suction temperature failure"},
    {2074, 0x0020, "P081", "Discharge temperature failure"},
    {2074, 0x0040, "E051", "Compressor over current protection"},
    {2074, 0x0080, "E01", "High pressure protection"},
    {2074, 0x0100, "E02", "Low pressure protection"},
    {2074, 0x0200, "E03", "Water flow failure"},
    {2074, 0x0400, "E19", "Primary winter antifreeze protection"},
    {2074, 0x0800, "E29", "Secondary winter antifreeze protection"},
    {2074, 0x1000, "E07", "Antifreeze protection"},
    {2074, 0x2000, "R2074B13", "High discharge temperature protection system 1"},
    {2074, 0x4000, "E06", "Too big difference between inlet and outlet water temperature"},
    {2075, 0x0001, "R2075B0", "Compressor overload protection more than 3 times"},
    {2075, 0x0002, "R2075B1", "High pressure protection more than 3 times"},
    {2075, 0x0004, "R2075B2", "Low pressure protection more than 3 times"},
    {2075, 0x0008, "R2075B3", "Water flow protection more than 3 times"},
    {2075, 0x0010, "R2075B4", "Antifreezing protection more than 3 times"},
    {2075, 0x0020, "R2075B5", "High discharge temperature protection more than 3 times"},
    {2075, 0x0040, "F01", "MOP drive warning"},
    {2075, 0x0080, "F02", "Converter board off-line"},
    {2075, 0x0100, "F03", "IPM protection"},
    {2075, 0x0200, "F04", "Compressor start-up failure"},
    {2075, 0x0400, "F17", "Converter input lost phase"},
    {2075, 0x0800, "F18", "IPM sampling current failure"},
    {2075, 0x1000, "F20", "Converter overheat protection"},
    {2075, 0x2000, "F07", "Converter DC over voltage"},
    {2075, 0x4000, "F08", "Converter DC under voltage"},
    {2075, 0x8000, "R2075B15", "Input under voltage"},
    {2076, 0x0001, "R2076B0", "Input over voltage"},
    {2076, 0x0002, "R2076B1", "Sampling voltage failure"},
    {2076, 0x0004, "F12", "DSP and PFC connection failure"},
    {2076, 0x0008, "F19", "Radiator temperature sensing failure"},
    {2076, 0x0010, "F28", "V15V over or under voltage failure"},
    {2076, 0x0020, "F27", "PFC failure"},
    {2076, 0x0040, "F15", "IPM overheat protection"},
    {2076, 0x0080, "F16", "Weak magnetic protection"},
    {2076, 0x0100, "F24", "Input over current warning"},
    {2076, 0x0200, "F22", "Converter overheat warning"},
    {2076, 0x0400, "R2076B10", "Input overcurrent protection"},
    {2076, 0x0800, "F25", "EEPROM error warning"},
    {2076, 0x1000, "R2076B12", "IPM protection"},
    {2076, 0x2000, "R2076B13", "DC fan motor driver board protection"},
    {2076, 0x4000, "PP", "Pressure sensor failure"},
    {2076, 0x8000, "F26", "Input over current"},
    {2077, 0x0001, "R2077B0", "Antifreezing protection"},
    {2077, 0x0002, "R2077B1", "Antifreezing protection in heating mode"},
    {2077, 0x0004, "R2077B2", "EC fan motor feedback signal failure"},
    {2077, 0x0008, "R2077B3", "Fan motor 1 failure"},
    {2077, 0x0010, "R2077B4", "Fan motor 2 failure"},
    {2077, 0x0020, "R2077B5", "DC fan motor communication failure"},
}};

static constexpr std::array<std::pair<uint16_t, const char *>, 6> SWITCH_FLAG_DESCRIPTORS{{
    {0x0001, "HP switch open"},
    {0x0002, "LP switch open"},
    {0x0004, "Water flow switch open"},
    {0x0008, "Remote ON/OFF open"},
    {0x0010, "Mode remote open"},
    {0x0020, "Master and slave open"},
}};

}  // namespace esphome::hayward::protocol
