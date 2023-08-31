#include "register.h"

Register::Register() {
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  f = 0;
  h = 0;
  l = 0;
}

uint8_t Register::getRegister8(char c) {
  switch(c) {
    case 'a':
      return a;
    case 'b':
      return b;
    case 'c':
      return c;
    case 'd':
      return d;
    case 'e':
      return e;
    case 'f':
      return f;
    case 'h':
      return h;
    case 'l':
      return l;
  }
  return -1;
}

void Register::setRegister8(char c, uint8_t data) {
  switch(c) {
    case 'a':
      a = data;
    case 'b':
      b = data;
    case 'c':
      c = data;
    case 'd':
      d = data;
    case 'e':
      e = data;
    case 'f':
      f = data;
    case 'h':
      h = data;
    case 'l':
      l = data;
  }
}

uint16_t Register::getRegisterAF() {
  uint16_t response = (uint16_t) a;
  response << 8;
  return (response & f);
}

uint16_t Register::getRegisterBC() {
  uint16_t response = (uint16_t) b;
  response << 8;
  return (response & c);
}

uint16_t Register::getRegisterDE() {
  uint16_t response = (uint16_t) d;
  response << 8;
  return (response & e);
}

uint16_t Register::getRegisterHL() {
  uint16_t response = (uint16_t) h;
  response << 8;
  return (response & l);
}

void Register::setRegisterAF(uint16_t data) {
  a = static_cast<uint8_t>((data & 0xFF00) >> 8);
  f = static_cast<uint8_t>(data & 0x00FF);
}

void Register::setRegisterBC(uint16_t data) {
  b = static_cast<uint8_t>((data & 0xFF00) >> 8);
  c = static_cast<uint8_t>(data & 0x00FF);
}

void Register::setRegisterDE(uint16_t data) {
  d = static_cast<uint8_t>((data & 0xFF00) >> 8);
  e = static_cast<uint8_t>(data & 0x00FF);
}

void Register::setRegisterHL(uint16_t data) {
  h = static_cast<uint8_t>((data & 0xFF00) >> 8);
  l = static_cast<uint8_t>(data & 0x00FF);
}

void Register::setFlagZero() {
  uint8_t mask = 0b10000000;
  f = f & mask;
}

void Register::setFlagSub() {
  uint8_t mask = 0b01000000;
  f = f & mask;
}

void Register::setFlagHalfCarry() {
  uint8_t mask = 0b00100000;
  f = f & mask;
}

void Register::setFlagCarry() {
  uint8_t mask = 0b00010000;
  f = f & mask;
}

void Register::unSetFlagZero() {
  uint8_t mask = 0b01111111;
  f = f & mask;
}

void Register::unSetFlagSub() {
  uint8_t mask = 0b10111111;
  f = f & mask;
}

void Register::unSetFlagHalfCarry() {
  uint8_t mask = 0b11011111;
  f = f & mask;
}

void Register::unSetFlagCarry() {
  uint8_t mask = 0b11101111;
  f = f & mask;
}

bool Register::getFlagZero() {
  uint8_t mask = 0b10000000;
  return (f & mask);
}

bool Register::getFlagSub() {
  uint8_t mask = 0b01000000;
  return (f & mask);
}

bool Register::getFlagHalfCarry() {
  uint8_t mask = 0b00100000;
  return (f & mask);
}

bool Register::getFlagCarry() {
  uint8_t mask = 0b00010000;
  return (f & mask);
}