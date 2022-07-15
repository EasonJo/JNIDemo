//
// Created by eason on 2022/7/15.
//

#ifndef JNIDEMO_SOAHACIMPL_H
#define JNIDEMO_SOAHACIMPL_H

#include "SoaInterface.h"

class SoaHacImpl : public SoaHACInterface {

private:
    //SoAAPClient* soaApClient;
public:

    explicit SoaHacImpl();

    ~SoaHacImpl() override;

    virtual void initSoaHAC() override;

    virtual float getTemperature() override;

    virtual int getHacLevel() override;
};

#endif //JNIDEMO_SOAHACIMPL_H
