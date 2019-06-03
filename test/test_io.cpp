
#include <stdio.h>
#include <string.h>

#include "pnut.h"

extern "C"
{
 #include "exec_module.h"
// #include "common_module.h"
// #include "hal_module.h"
#include "io_module.h"
// #include "cli_module.h"
#include "hal_sim.h"
}



//--------------------------------------------------------------//
UT_SUITE(CMOD_DIG_IO, "Test digital read/write.")
{
    status_t status = STATUS_OK;

    // Init modules.
    status = exec_init();
    UT_EQUAL(status, STATUS_OK);

    // Some basic checks.
    bool value;

    // Good.
    status = io_getDigInput(DIG_IN_SWITCH1, &value);
    UT_EQUAL(status, STATUS_OK);
    UT_FALSE(value);
    // Bad.
    status = io_getDigInput((digInput_t)99, &value);
    UT_EQUAL(status, STATUS_ERROR);

    // Good.
        
    UT_EQUAL(hal_sim_getOutputPin(DIG_OUT_LED1), false);
    status = io_setDigOutput(DIG_OUT_LED1, true);
    UT_EQUAL(status, STATUS_OK);
    UT_EQUAL(hal_sim_getOutputPin(DIG_OUT_LED1), true);
    // Bad.
    status = io_setDigOutput((digOutput_t)99, true);
    UT_EQUAL(status, STATUS_ERROR);

    // Exit.
    status = exec_exit();
    UT_EQUAL(status, STATUS_OK);
}


//--------------------------------------------------------------//
UT_SUITE(CMOD_ANA_IO, "Test analog read/write.")
{
    status_t status = STATUS_OK;

    // Init modules.
    status = exec_init();
    UT_EQUAL(status, STATUS_OK);


    /////////// stuff here ///////////////


    // Exit.
    status = exec_exit();
    UT_EQUAL(status, STATUS_OK);
}