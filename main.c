#include "mcc.h"

static void setDef ()
{
    strcpy(inFilepath, "main.mc");
    strcpy(outFilepath, "$");
    mode = 1; // default mode (compiler debug)s
    doBenchmarking = false;
    doRun = false;
    doParsing = true;
    doAssemble = true;
    doLinker = true;
    doWarnings = true;
}

int main (int argc, char* argv[])
{
    setDef();
    mccDoArgs(argc,argv);
    mccLog("Chaidhat Chaimongkol on %s %s", __DATE__, __TIME__);
    mccLog("reading from %s", inFilepath);
    mccLog("writing to %s", outFilepath);
    mccLog("verbose debugger enabled");
    inpOpen(inFilepath);
    printf("\n");

    Tree t;
    t = *crtTree("a");
    Tree child = *crtTree("zucker");
    Tree child2 = *crtTree("gummy");
    Tree child3 = *crtTree("bon bon");
    appendTree(&t, &child);
    logTree(&t);
    mccLog("1");
    appendTree(&t, &child2);
    logTree(&t);
    mccLog("2");
    appendTree(&t, &child3);
    logTree(&t);
    mccLog("3");

    deleteTree(&t, "zucker");


    next();
    logTree(&t);
    //preprocess();
    // do code
    //dataBuffer[2] = 'B';
    inpClose();
    inpOutput(outFilepath);
    mccExit(0, __LINE__);
}


