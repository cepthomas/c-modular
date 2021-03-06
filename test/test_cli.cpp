
#include <stdio.h>
#include <string.h>

#include "pnut.h"

extern "C"
{
#include "exec_module.h"
#include "cli_module.h"
#include "io_module.h"
#include "hal_board_mock.h"
}


//--------------------------------------------------------------//
UT_SUITE(CMOD_CLI, "Test cli functions.")
{
    status_t status = STATUS_OK;

    // Init modules.
    status = exec_init();
    UT_EQUAL(status, STATUS_OK);

    char resp[CLI_BUFF_LEN];
    resp[0] = 0;

    // Bad.
    status = cli_process("FOO BAR", resp);
    UT_EQUAL(status, STATUS_WARN);
    UT_STR_EQUAL(resp, "NG");
    // Good.
    status = cli_process("SET LED1", resp);
    UT_EQUAL(status, STATUS_OK);
    UT_STR_EQUAL(resp, "OK");
    UT_TRUE(hal_mock_getDigPin(DIG_OUT_LED1));
    // Good.
    status = cli_process("CLR LED1", resp);
    UT_EQUAL(status, STATUS_OK);
    UT_STR_EQUAL(resp, "OK");

    // Exit.
    status = exec_destroy();
    UT_EQUAL(status, STATUS_OK);
}
