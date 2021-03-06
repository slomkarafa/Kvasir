#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//MCTM
    namespace MctmMctmCntcfr{    ///<MCTM_CNTCFR
        using Addr = Register::Address<0x4002c000,0x00fcfcfc,0x00000000,unsigned>;
        ///UEV1DIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> uev1dis{}; 
        ///UGDIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ugdis{}; 
        ///CKDIV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,8),Register::ReadWriteAccess,unsigned> ckdiv{}; 
        ///CMSEL
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> cmsel{}; 
        ///DIR
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> dir{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,25),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmMdcfr{    ///<MCTM_MDCFR
        using Addr = Register::Address<0x4002c004,0x00f8f8fe,0x00000000,unsigned>;
        ///TSE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> tse{}; 
        ///SMSEL
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,8),Register::ReadWriteAccess,unsigned> smsel{}; 
        ///MMSEL
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,16),Register::ReadWriteAccess,unsigned> mmsel{}; 
        ///SPMSET
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> spmset{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,25),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmTrcfr{    ///<MCTM_TRCFR
        using Addr = Register::Address<0x4002c008,0x00fec0f0,0x00000000,unsigned>;
        ///TRSEL
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> trsel{}; 
        ///ETF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> etf{}; 
        ///ETIPSC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,12),Register::ReadWriteAccess,unsigned> etipsc{}; 
        ///ETIPOL
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> etipol{}; 
        ///ECME
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> ecme{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,25),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCtr{    ///<MCTM_CTR
        using Addr = Register::Address<0x4002c010,0x0000fcfc,0x00000000,unsigned>;
        ///TME
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> tme{}; 
        ///CRBE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> crbe{}; 
        ///COMPRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> compre{}; 
        ///COMUS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> comus{}; 
        ///CHCCDS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> chccds{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,17),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh0icfr{    ///<MCTM_CH0ICFR
        using Addr = Register::Address<0x4002c020,0x7ff0fff0,0x00000000,unsigned>;
        ///TI0F
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> ti0f{}; 
        ///CH0CCS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> ch0ccs{}; 
        ///CH0PSC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,unsigned> ch0psc{}; 
        ///TI0SRC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,unsigned> ti0src{}; 
    }
    namespace MctmMctmCh1icfr{    ///<MCTM_CH1ICFR
        using Addr = Register::Address<0x4002c024,0x0000fff0,0x00000000,unsigned>;
        ///TI1F
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> ti1f{}; 
        ///CH1CCS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> ch1ccs{}; 
        ///CH1PSC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,unsigned> ch1psc{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,20),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh2icfr{    ///<MCTM_CH2ICFR
        using Addr = Register::Address<0x4002c028,0x0000fff0,0x00000000,unsigned>;
        ///TI2F
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> ti2f{}; 
        ///CH2CCS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> ch2ccs{}; 
        ///CH2PSC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,unsigned> ch2psc{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,20),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh3icfr{    ///<MCTM_CH3ICFR
        using Addr = Register::Address<0x4002c02c,0x0000fff0,0x00000000,unsigned>;
        ///TI3F
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> ti3f{}; 
        ///CH3CCS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> ch3ccs{}; 
        ///CH3PSC
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,unsigned> ch3psc{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,20),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh0ocfr{    ///<MCTM_CH0OCFR
        using Addr = Register::Address<0x4002c040,0x00000000,0x00000000,unsigned>;
        ///CH0OM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> ch0om{}; 
        ///REF0CE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ref0ce{}; 
        ///CH0PRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch0pre{}; 
        ///CH0IMAE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch0imae{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh1ocfr{    ///<MCTM_CH1OCFR
        using Addr = Register::Address<0x4002c044,0x00000000,0x00000000,unsigned>;
        ///CH1OM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> ch1om{}; 
        ///REF1CE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ref1ce{}; 
        ///CH1PRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch1pre{}; 
        ///CH1IMAE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch1imae{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh2ocfr{    ///<MCTM_CH2OCFR
        using Addr = Register::Address<0x4002c048,0x00000000,0x00000000,unsigned>;
        ///CH2OM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> ch2om{}; 
        ///REF2CE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ref2ce{}; 
        ///CH2PRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch2pre{}; 
        ///CH2IMAE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch2imae{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh3ocfr{    ///<MCTM_CH3OCFR
        using Addr = Register::Address<0x4002c04c,0x00000000,0x00000000,unsigned>;
        ///CH3OM
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> ch3om{}; 
        ///REF3CE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ref3ce{}; 
        ///CH3PRE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch3pre{}; 
        ///CH3IMAE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch3imae{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,6),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmChctr{    ///<MCTM_CHCTR
        using Addr = Register::Address<0x4002c050,0x00000000,0x00000000,unsigned>;
        ///CH0E
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0e{}; 
        ///CH0NE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch0ne{}; 
        ///CH1E
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch1e{}; 
        ///CH1NE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch1ne{}; 
        ///CH2E
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch2e{}; 
        ///CH2NE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch2ne{}; 
        ///CH3E
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> ch3e{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,7),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmChpolr{    ///<MCTM_CHPOLR
        using Addr = Register::Address<0x4002c054,0x00000000,0x00000000,unsigned>;
        ///CH0P
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0p{}; 
        ///CH0NP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch0np{}; 
        ///CH1P
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch1p{}; 
        ///CH1NP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch1np{}; 
        ///CH2P
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch2p{}; 
        ///CH2NP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch2np{}; 
        ///CH3P
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> ch3p{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,7),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmChbrkcfr{    ///<MCTM_CHBRKCFR
        using Addr = Register::Address<0x4002c06c,0x00000000,0x00000000,unsigned>;
        ///CH0OIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0ois{}; 
        ///CH0OISN
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch0oisn{}; 
        ///CH1OIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch1ois{}; 
        ///CH1OISN
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch1oisn{}; 
        ///CH2OIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch2ois{}; 
        ///CH2OISN
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch2oisn{}; 
        ///CH3OIS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> ch3ois{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,7),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmChbrkctr{    ///<MCTM_CHBRKCTR
        using Addr = Register::Address<0x4002c070,0x00ccf0cc,0x00000000,unsigned>;
        ///BKE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> bke{}; 
        ///BKP
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> bkp{}; 
        ///CHMOE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> chmoe{}; 
        ///CHAOE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> chaoe{}; 
        ///BKF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> bkf{}; 
        ///LOCKLV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,16),Register::ReadWriteAccess,unsigned> locklv{}; 
        ///CHOSSI
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> chossi{}; 
        ///CHOSSR
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> chossr{}; 
        ///CHDTG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> chdtg{}; 
    }
    namespace MctmMctmDictr{    ///<MCTM_DICTR
        using Addr = Register::Address<0x4002c074,0x00f0f0f0,0x00000000,unsigned>;
        ///CH0CCIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0ccie{}; 
        ///CH1CCIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch1ccie{}; 
        ///CH2CCIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch2ccie{}; 
        ///CH3CCIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch3ccie{}; 
        ///UEV1IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> uev1ie{}; 
        ///UEV2IE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> uev2ie{}; 
        ///TEVIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> tevie{}; 
        ///BRKIE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> brkie{}; 
        ///CH0CCDE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> ch0ccde{}; 
        ///CH1CCDE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> ch1ccde{}; 
        ///CH2CCDE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> ch2ccde{}; 
        ///CH3CCDE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> ch3ccde{}; 
        ///UEV1DE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> uev1de{}; 
        ///UEV2DE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,unsigned> uev2de{}; 
        ///TEVDE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,unsigned> tevde{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,27),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmEvgr{    ///<MCTM_EVGR
        using Addr = Register::Address<0x4002c078,0x000000f0,0x00000000,unsigned>;
        ///CH0CCG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0ccg{}; 
        ///CH1CCG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch1ccg{}; 
        ///CH2CCG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch2ccg{}; 
        ///CH3CCG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch3ccg{}; 
        ///UEV1G
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> uev1g{}; 
        ///UEV2G
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> uev2g{}; 
        ///TEVG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> tevg{}; 
        ///BRKG
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> brkg{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,12),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmIntsr{    ///<MCTM_INTSR
        using Addr = Register::Address<0x4002c07c,0x00000000,0x00000000,unsigned>;
        ///CH0CCIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ch0ccif{}; 
        ///CH1CCIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ch1ccif{}; 
        ///CH2CCIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ch2ccif{}; 
        ///CH3CCIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ch3ccif{}; 
        ///CH0OCF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ch0ocf{}; 
        ///CH1OCF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ch1ocf{}; 
        ///CH2OCF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> ch2ocf{}; 
        ///CH3OCF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> ch3ocf{}; 
        ///UEV1IF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> uev1if{}; 
        ///UEV2IF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> uev2if{}; 
        ///TEVIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> tevif{}; 
        ///BRKIF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> brkif{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,12),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCntr{    ///<MCTM_CNTR
        using Addr = Register::Address<0x4002c080,0x00000000,0x00000000,unsigned>;
        ///CNTV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cntv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmPscr{    ///<MCTM_PSCR
        using Addr = Register::Address<0x4002c084,0x00000000,0x00000000,unsigned>;
        ///PSCV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> pscv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCrr{    ///<MCTM_CRR
        using Addr = Register::Address<0x4002c088,0x00000000,0x00000000,unsigned>;
        ///CRV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> crv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmRepr{    ///<MCTM_REPR
        using Addr = Register::Address<0x4002c08c,0x00000000,0x00000000,unsigned>;
        ///REPV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> repv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh0ccr{    ///<MCTM_CH0CCR
        using Addr = Register::Address<0x4002c090,0x00000000,0x00000000,unsigned>;
        ///CH0CCV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> ch0ccv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh1ccr{    ///<MCTM_CH1CCR
        using Addr = Register::Address<0x4002c094,0x00000000,0x00000000,unsigned>;
        ///CH1CCV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> ch1ccv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh2ccr{    ///<MCTM_CH2CCR
        using Addr = Register::Address<0x4002c098,0x00000000,0x00000000,unsigned>;
        ///CH2CCV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> ch2ccv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace MctmMctmCh3ccr{    ///<MCTM_CH3CCR
        using Addr = Register::Address<0x4002c09c,0x00000000,0x00000000,unsigned>;
        ///CH3CCV
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> ch3ccv{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
