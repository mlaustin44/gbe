#include <cstdint>


class Register {
  public:
    // 8 bit register functions
    uint8_t   getRegister8(char c);
    void      setRegister8(char c, uint8_t data);
    // 16 bit register functions
    uint16_t  getRegisterAF();
    uint16_t  getRegisterBC();
    uint16_t  getRegisterDE();
    uint16_t  getRegisterHL();
    void      setRegisterAF(uint16_t data);
    void      setRegisterBC(uint16_t data);
    void      setRegisterDE(uint16_t data);
    void      setRegisterHL(uint16_t data);
    // flag register functions
    void      setFlagZero();
    void      setFlagSub();
    void      setFlagHalfCarry();
    void      setFlagCarry();
    void      unSetFlagZero();
    void      unSetFlagSub();
    void      unSetFlagHalfCarry();
    void      unSetFlagCarry();
    bool      getFlagZero();
    bool      getFlagSub();
    bool      getFlagHalfCarry();
    bool      getFlagCarry();
  private:
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t h;
    uint8_t l;
};