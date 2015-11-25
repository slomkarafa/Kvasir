#pragma once 
#include "Register/Utility.hpp"
namespace Kvasir {
//Supply Controller
    namespace SupcCr{    ///<Supply Controller Control Register
        using Addr = Register::Address<0x400e1210,0x00fffff3,0,unsigned>;
        ///Voltage Regulator Off
        enum class vroffVal {
            noEffect=0x00000000,     ///<no effect.
            stopVreg=0x00000001,     ///<if KEY is correct, asserts vddcore_nreset and stops the voltage regulator.
        };
        namespace vroffValC{
            constexpr MPL::Value<vroffVal,vroffVal::noEffect> noEffect{};
            constexpr MPL::Value<vroffVal,vroffVal::stopVreg> stopVreg{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,vroffVal> vroff{}; 
        ///Crystal Oscillator Select
        enum class xtalselVal {
            noEffect=0x00000000,     ///<no effect.
            crystalSel=0x00000001,     ///<if KEY is correct, switches the slow clock on the crystal oscillator output.
        };
        namespace xtalselValC{
            constexpr MPL::Value<xtalselVal,xtalselVal::noEffect> noEffect{};
            constexpr MPL::Value<xtalselVal,xtalselVal::crystalSel> crystalSel{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,xtalselVal> xtalsel{}; 
        ///Password
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> key{}; 
    }
    namespace SupcSmmr{    ///<Supply Controller Supply Monitor Mode Register
        using Addr = Register::Address<0x400e1214,0xffffc8f0,0,unsigned>;
        ///Supply Monitor Threshold
        enum class smthVal {
            v19v=0x00000000,     ///<1.9 V
            v20v=0x00000001,     ///<2.0 V
            v21v=0x00000002,     ///<2.1 V
            v22v=0x00000003,     ///<2.2 V
            v23v=0x00000004,     ///<2.3 V
            v24v=0x00000005,     ///<2.4 V
            v25v=0x00000006,     ///<2.5 V
            v26v=0x00000007,     ///<2.6 V
            v27v=0x00000008,     ///<2.7 V
            v28v=0x00000009,     ///<2.8 V
            v29v=0x0000000a,     ///<2.9 V
            v30v=0x0000000b,     ///<3.0 V
            v31v=0x0000000c,     ///<3.1 V
            v32v=0x0000000d,     ///<3.2 V
            v33v=0x0000000e,     ///<3.3 V
            v34v=0x0000000f,     ///<3.4 V
        };
        namespace smthValC{
            constexpr MPL::Value<smthVal,smthVal::v19v> v19v{};
            constexpr MPL::Value<smthVal,smthVal::v20v> v20v{};
            constexpr MPL::Value<smthVal,smthVal::v21v> v21v{};
            constexpr MPL::Value<smthVal,smthVal::v22v> v22v{};
            constexpr MPL::Value<smthVal,smthVal::v23v> v23v{};
            constexpr MPL::Value<smthVal,smthVal::v24v> v24v{};
            constexpr MPL::Value<smthVal,smthVal::v25v> v25v{};
            constexpr MPL::Value<smthVal,smthVal::v26v> v26v{};
            constexpr MPL::Value<smthVal,smthVal::v27v> v27v{};
            constexpr MPL::Value<smthVal,smthVal::v28v> v28v{};
            constexpr MPL::Value<smthVal,smthVal::v29v> v29v{};
            constexpr MPL::Value<smthVal,smthVal::v30v> v30v{};
            constexpr MPL::Value<smthVal,smthVal::v31v> v31v{};
            constexpr MPL::Value<smthVal,smthVal::v32v> v32v{};
            constexpr MPL::Value<smthVal,smthVal::v33v> v33v{};
            constexpr MPL::Value<smthVal,smthVal::v34v> v34v{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,smthVal> smth{}; 
        ///Supply Monitor Sampling Period
        enum class smsmplVal {
            smd=0x00000000,     ///<Supply Monitor disabled
            csm=0x00000001,     ///<Continuous Supply Monitor
            v32slck=0x00000002,     ///<Supply Monitor enabled one SLCK period every 32 SLCK periods
            v256slck=0x00000003,     ///<Supply Monitor enabled one SLCK period every 256 SLCK periods
            v2048slck=0x00000004,     ///<Supply Monitor enabled one SLCK period every 2,048 SLCK periods
        };
        namespace smsmplValC{
            constexpr MPL::Value<smsmplVal,smsmplVal::smd> smd{};
            constexpr MPL::Value<smsmplVal,smsmplVal::csm> csm{};
            constexpr MPL::Value<smsmplVal,smsmplVal::v32slck> v32slck{};
            constexpr MPL::Value<smsmplVal,smsmplVal::v256slck> v256slck{};
            constexpr MPL::Value<smsmplVal,smsmplVal::v2048slck> v2048slck{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(10,8),Register::ReadWriteAccess,smsmplVal> smsmpl{}; 
        ///Supply Monitor Reset Enable
        enum class smrstenVal {
            notEnable=0x00000000,     ///<the core reset signal "vddcore_nreset" is not affected when a supply monitor detection occurs.
            enable=0x00000001,     ///<the core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs.
        };
        namespace smrstenValC{
            constexpr MPL::Value<smrstenVal,smrstenVal::notEnable> notEnable{};
            constexpr MPL::Value<smrstenVal,smrstenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,smrstenVal> smrsten{}; 
        ///Supply Monitor Interrupt Enable
        enum class smienVal {
            notEnable=0x00000000,     ///<the SUPC interrupt signal is not affected when a supply monitor detection occurs.
            enable=0x00000001,     ///<the SUPC interrupt signal is asserted when a supply monitor detection occurs.
        };
        namespace smienValC{
            constexpr MPL::Value<smienVal,smienVal::notEnable> notEnable{};
            constexpr MPL::Value<smienVal,smienVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,smienVal> smien{}; 
    }
    namespace SupcMr{    ///<Supply Controller Mode Register
        using Addr = Register::Address<0x400e1218,0x00ef8fff,0,unsigned>;
        ///Brownout Detector Reset Enable
        enum class bodrstenVal {
            notEnable=0x00000000,     ///<the core reset signal "vddcore_nreset" is not affected when a brownout detection occurs.
            enable=0x00000001,     ///<the core reset signal, vddcore_nreset is asserted when a brownout detection occurs.
        };
        namespace bodrstenValC{
            constexpr MPL::Value<bodrstenVal,bodrstenVal::notEnable> notEnable{};
            constexpr MPL::Value<bodrstenVal,bodrstenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,bodrstenVal> bodrsten{}; 
        ///Brownout Detector Disable
        enum class boddisVal {
            enable=0x00000000,     ///<the core brownout detector is enabled.
            disable=0x00000001,     ///<the core brownout detector is disabled.
        };
        namespace boddisValC{
            constexpr MPL::Value<boddisVal,boddisVal::enable> enable{};
            constexpr MPL::Value<boddisVal,boddisVal::disable> disable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,boddisVal> boddis{}; 
        ///None
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> vddiordyonreg{}; 
        ///Oscillator Bypass
        enum class oscbypassVal {
            noEffect=0x00000000,     ///<no effect. Clock selection depends on XTALSEL value.
            bypass=0x00000001,     ///<the 32-KHz XTAL oscillator is selected and is put in bypass mode.
        };
        namespace oscbypassValC{
            constexpr MPL::Value<oscbypassVal,oscbypassVal::noEffect> noEffect{};
            constexpr MPL::Value<oscbypassVal,oscbypassVal::bypass> bypass{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,oscbypassVal> oscbypass{}; 
        ///Password Key
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> key{}; 
    }
    namespace SupcWumr{    ///<Supply Controller Wake Up Mode Register
        using Addr = Register::Address<0x400e121c,0xffff88f0,0,unsigned>;
        ///Force Wake Up Enable
        enum class fwupenVal {
            notEnable=0x00000000,     ///<the Force Wake Up pin has no wake up effect.
            enable=0x00000001,     ///<the Force Wake Up pin low forces the wake up of the core power supply.
        };
        namespace fwupenValC{
            constexpr MPL::Value<fwupenVal,fwupenVal::notEnable> notEnable{};
            constexpr MPL::Value<fwupenVal,fwupenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,fwupenVal> fwupen{}; 
        ///Supply Monitor Wake Up Enable
        enum class smenVal {
            notEnable=0x00000000,     ///<the supply monitor detection has no wake up effect.
            enable=0x00000001,     ///<the supply monitor detection forces the wake up of the core power supply.
        };
        namespace smenValC{
            constexpr MPL::Value<smenVal,smenVal::notEnable> notEnable{};
            constexpr MPL::Value<smenVal,smenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,smenVal> smen{}; 
        ///Real Time Timer Wake Up Enable
        enum class rttenVal {
            notEnable=0x00000000,     ///<the RTT alarm signal has no wake up effect.
            enable=0x00000001,     ///<the RTT alarm signal forces the wake up of the core power supply.
        };
        namespace rttenValC{
            constexpr MPL::Value<rttenVal,rttenVal::notEnable> notEnable{};
            constexpr MPL::Value<rttenVal,rttenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,rttenVal> rtten{}; 
        ///Real Time Clock Wake Up Enable
        enum class rtcenVal {
            notEnable=0x00000000,     ///<the RTC alarm signal has no wake up effect.
            enable=0x00000001,     ///<the RTC alarm signal forces the wake up of the core power supply.
        };
        namespace rtcenValC{
            constexpr MPL::Value<rtcenVal,rtcenVal::notEnable> notEnable{};
            constexpr MPL::Value<rtcenVal,rtcenVal::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,rtcenVal> rtcen{}; 
        ///Force Wake Up Debouncer Period
        enum class fwupdbcVal {
            immediate=0x00000000,     ///<Immediate, no debouncing, detected active at least on one Slow Clock edge.
            v3Sclk=0x00000001,     ///<FWUP shall be low for at least 3 SLCK periods
            v32Sclk=0x00000002,     ///<FWUP shall be low for at least 32 SLCK periods
            v512Sclk=0x00000003,     ///<FWUP shall be low for at least 512 SLCK periods
            v4096Sclk=0x00000004,     ///<FWUP shall be low for at least 4,096 SLCK periods
            v32768Sclk=0x00000005,     ///<FWUP shall be low for at least 32,768 SLCK periods
        };
        namespace fwupdbcValC{
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::immediate> immediate{};
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::v3Sclk> v3Sclk{};
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::v32Sclk> v32Sclk{};
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::v512Sclk> v512Sclk{};
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::v4096Sclk> v4096Sclk{};
            constexpr MPL::Value<fwupdbcVal,fwupdbcVal::v32768Sclk> v32768Sclk{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(10,8),Register::ReadWriteAccess,fwupdbcVal> fwupdbc{}; 
        ///Wake Up Inputs Debouncer Period
        enum class wkupdbcVal {
            immediate=0x00000000,     ///<Immediate, no debouncing, detected active at least on one Slow Clock edge.
            v3Sclk=0x00000001,     ///<WKUPx shall be in its active state for at least 3 SLCK periods
            v32Sclk=0x00000002,     ///<WKUPx shall be in its active state for at least 32 SLCK periods
            v512Sclk=0x00000003,     ///<WKUPx shall be in its active state for at least 512 SLCK periods
            v4096Sclk=0x00000004,     ///<WKUPx shall be in its active state for at least 4,096 SLCK periods
            v32768Sclk=0x00000005,     ///<WKUPx shall be in its active state for at least 32,768 SLCK periods
        };
        namespace wkupdbcValC{
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::immediate> immediate{};
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::v3Sclk> v3Sclk{};
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::v32Sclk> v32Sclk{};
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::v512Sclk> v512Sclk{};
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::v4096Sclk> v4096Sclk{};
            constexpr MPL::Value<wkupdbcVal,wkupdbcVal::v32768Sclk> v32768Sclk{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,12),Register::ReadWriteAccess,wkupdbcVal> wkupdbc{}; 
    }
    namespace SupcWuir{    ///<Supply Controller Wake Up Inputs Register
        using Addr = Register::Address<0x400e1220,0x00000000,0,unsigned>;
        ///Wake Up Input Enable 0
        enum class wkupen0Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen0ValC{
            constexpr MPL::Value<wkupen0Val,wkupen0Val::disable> disable{};
            constexpr MPL::Value<wkupen0Val,wkupen0Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,wkupen0Val> wkupen0{}; 
        ///Wake Up Input Enable 1
        enum class wkupen1Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen1ValC{
            constexpr MPL::Value<wkupen1Val,wkupen1Val::disable> disable{};
            constexpr MPL::Value<wkupen1Val,wkupen1Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,wkupen1Val> wkupen1{}; 
        ///Wake Up Input Enable 2
        enum class wkupen2Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen2ValC{
            constexpr MPL::Value<wkupen2Val,wkupen2Val::disable> disable{};
            constexpr MPL::Value<wkupen2Val,wkupen2Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,wkupen2Val> wkupen2{}; 
        ///Wake Up Input Enable 3
        enum class wkupen3Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen3ValC{
            constexpr MPL::Value<wkupen3Val,wkupen3Val::disable> disable{};
            constexpr MPL::Value<wkupen3Val,wkupen3Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,wkupen3Val> wkupen3{}; 
        ///Wake Up Input Enable 4
        enum class wkupen4Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen4ValC{
            constexpr MPL::Value<wkupen4Val,wkupen4Val::disable> disable{};
            constexpr MPL::Value<wkupen4Val,wkupen4Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,wkupen4Val> wkupen4{}; 
        ///Wake Up Input Enable 5
        enum class wkupen5Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen5ValC{
            constexpr MPL::Value<wkupen5Val,wkupen5Val::disable> disable{};
            constexpr MPL::Value<wkupen5Val,wkupen5Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,wkupen5Val> wkupen5{}; 
        ///Wake Up Input Enable 6
        enum class wkupen6Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen6ValC{
            constexpr MPL::Value<wkupen6Val,wkupen6Val::disable> disable{};
            constexpr MPL::Value<wkupen6Val,wkupen6Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,wkupen6Val> wkupen6{}; 
        ///Wake Up Input Enable 7
        enum class wkupen7Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen7ValC{
            constexpr MPL::Value<wkupen7Val,wkupen7Val::disable> disable{};
            constexpr MPL::Value<wkupen7Val,wkupen7Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,wkupen7Val> wkupen7{}; 
        ///Wake Up Input Enable 8
        enum class wkupen8Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen8ValC{
            constexpr MPL::Value<wkupen8Val,wkupen8Val::disable> disable{};
            constexpr MPL::Value<wkupen8Val,wkupen8Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,wkupen8Val> wkupen8{}; 
        ///Wake Up Input Enable 9
        enum class wkupen9Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen9ValC{
            constexpr MPL::Value<wkupen9Val,wkupen9Val::disable> disable{};
            constexpr MPL::Value<wkupen9Val,wkupen9Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,wkupen9Val> wkupen9{}; 
        ///Wake Up Input Enable 10
        enum class wkupen10Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen10ValC{
            constexpr MPL::Value<wkupen10Val,wkupen10Val::disable> disable{};
            constexpr MPL::Value<wkupen10Val,wkupen10Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,wkupen10Val> wkupen10{}; 
        ///Wake Up Input Enable 11
        enum class wkupen11Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen11ValC{
            constexpr MPL::Value<wkupen11Val,wkupen11Val::disable> disable{};
            constexpr MPL::Value<wkupen11Val,wkupen11Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,wkupen11Val> wkupen11{}; 
        ///Wake Up Input Enable 12
        enum class wkupen12Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen12ValC{
            constexpr MPL::Value<wkupen12Val,wkupen12Val::disable> disable{};
            constexpr MPL::Value<wkupen12Val,wkupen12Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,wkupen12Val> wkupen12{}; 
        ///Wake Up Input Enable 13
        enum class wkupen13Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen13ValC{
            constexpr MPL::Value<wkupen13Val,wkupen13Val::disable> disable{};
            constexpr MPL::Value<wkupen13Val,wkupen13Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,wkupen13Val> wkupen13{}; 
        ///Wake Up Input Enable 14
        enum class wkupen14Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen14ValC{
            constexpr MPL::Value<wkupen14Val,wkupen14Val::disable> disable{};
            constexpr MPL::Value<wkupen14Val,wkupen14Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,wkupen14Val> wkupen14{}; 
        ///Wake Up Input Enable 15
        enum class wkupen15Val {
            disable=0x00000000,     ///<the corresponding wake-up input has no wake up effect.
            enable=0x00000001,     ///<the corresponding wake-up input forces the wake up of the core power supply.
        };
        namespace wkupen15ValC{
            constexpr MPL::Value<wkupen15Val,wkupen15Val::disable> disable{};
            constexpr MPL::Value<wkupen15Val,wkupen15Val::enable> enable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,wkupen15Val> wkupen15{}; 
        ///Wake Up Input Type 0
        enum class wkupt0Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt0ValC{
            constexpr MPL::Value<wkupt0Val,wkupt0Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt0Val,wkupt0Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,wkupt0Val> wkupt0{}; 
        ///Wake Up Input Type 1
        enum class wkupt1Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt1ValC{
            constexpr MPL::Value<wkupt1Val,wkupt1Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt1Val,wkupt1Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,wkupt1Val> wkupt1{}; 
        ///Wake Up Input Type 2
        enum class wkupt2Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt2ValC{
            constexpr MPL::Value<wkupt2Val,wkupt2Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt2Val,wkupt2Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,wkupt2Val> wkupt2{}; 
        ///Wake Up Input Type 3
        enum class wkupt3Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt3ValC{
            constexpr MPL::Value<wkupt3Val,wkupt3Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt3Val,wkupt3Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,wkupt3Val> wkupt3{}; 
        ///Wake Up Input Type 4
        enum class wkupt4Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt4ValC{
            constexpr MPL::Value<wkupt4Val,wkupt4Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt4Val,wkupt4Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,wkupt4Val> wkupt4{}; 
        ///Wake Up Input Type 5
        enum class wkupt5Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt5ValC{
            constexpr MPL::Value<wkupt5Val,wkupt5Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt5Val,wkupt5Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,wkupt5Val> wkupt5{}; 
        ///Wake Up Input Type 6
        enum class wkupt6Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt6ValC{
            constexpr MPL::Value<wkupt6Val,wkupt6Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt6Val,wkupt6Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,wkupt6Val> wkupt6{}; 
        ///Wake Up Input Type 7
        enum class wkupt7Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt7ValC{
            constexpr MPL::Value<wkupt7Val,wkupt7Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt7Val,wkupt7Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,wkupt7Val> wkupt7{}; 
        ///Wake Up Input Type 8
        enum class wkupt8Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt8ValC{
            constexpr MPL::Value<wkupt8Val,wkupt8Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt8Val,wkupt8Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,wkupt8Val> wkupt8{}; 
        ///Wake Up Input Type 9
        enum class wkupt9Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt9ValC{
            constexpr MPL::Value<wkupt9Val,wkupt9Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt9Val,wkupt9Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,wkupt9Val> wkupt9{}; 
        ///Wake Up Input Type 10
        enum class wkupt10Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt10ValC{
            constexpr MPL::Value<wkupt10Val,wkupt10Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt10Val,wkupt10Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,wkupt10Val> wkupt10{}; 
        ///Wake Up Input Type 11
        enum class wkupt11Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt11ValC{
            constexpr MPL::Value<wkupt11Val,wkupt11Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt11Val,wkupt11Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,wkupt11Val> wkupt11{}; 
        ///Wake Up Input Type 12
        enum class wkupt12Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt12ValC{
            constexpr MPL::Value<wkupt12Val,wkupt12Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt12Val,wkupt12Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,wkupt12Val> wkupt12{}; 
        ///Wake Up Input Type 13
        enum class wkupt13Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt13ValC{
            constexpr MPL::Value<wkupt13Val,wkupt13Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt13Val,wkupt13Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,wkupt13Val> wkupt13{}; 
        ///Wake Up Input Type 14
        enum class wkupt14Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt14ValC{
            constexpr MPL::Value<wkupt14Val,wkupt14Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt14Val,wkupt14Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(30,30),Register::ReadWriteAccess,wkupt14Val> wkupt14{}; 
        ///Wake Up Input Type 15
        enum class wkupt15Val {
            highToLow=0x00000000,     ///<a high to low level transition for a period defined by WKUPDBC on the corresponding wake-up input forces the wake up of the core power supply.
            lowToHigh=0x00000001,     ///<a low to high level transition for a period defined by WKUPDBC on the correspond-ing wake-up input forces the wake up of the core power supply.
        };
        namespace wkupt15ValC{
            constexpr MPL::Value<wkupt15Val,wkupt15Val::highToLow> highToLow{};
            constexpr MPL::Value<wkupt15Val,wkupt15Val::lowToHigh> lowToHigh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,wkupt15Val> wkupt15{}; 
    }
    namespace SupcSr{    ///<Supply Controller Status Register
        using Addr = Register::Address<0x400e1224,0x0000ef00,0,unsigned>;
        ///FWUP Wake Up Status
        enum class fwupsVal {
            no=0x00000000,     ///<no wake up due to the assertion of the FWUP pin has occurred since the last read of SUPC_SR.
            present=0x00000001,     ///<at least one wake up due to the assertion of the FWUP pin has occurred since the last read of SUPC_SR.
        };
        namespace fwupsValC{
            constexpr MPL::Value<fwupsVal,fwupsVal::no> no{};
            constexpr MPL::Value<fwupsVal,fwupsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,fwupsVal> fwups{}; 
        ///WKUP Wake Up Status
        enum class wkupsVal {
            no=0x00000000,     ///<no wake up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.
            present=0x00000001,     ///<at least one wake up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.
        };
        namespace wkupsValC{
            constexpr MPL::Value<wkupsVal,wkupsVal::no> no{};
            constexpr MPL::Value<wkupsVal,wkupsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,wkupsVal> wkups{}; 
        ///Supply Monitor Detection Wake Up Status
        enum class smwsVal {
            no=0x00000000,     ///<no wake up due to a supply monitor detection has occurred since the last read of SUPC_SR.
            present=0x00000001,     ///<at least one wake up due to a supply monitor detection has occurred since the last read of SUPC_SR.
        };
        namespace smwsValC{
            constexpr MPL::Value<smwsVal,smwsVal::no> no{};
            constexpr MPL::Value<smwsVal,smwsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,smwsVal> smws{}; 
        ///Brownout Detector Reset Status
        enum class bodrstsVal {
            no=0x00000000,     ///<no core brownout rising edge event has been detected since the last read of the SUPC_SR.
            present=0x00000001,     ///<at least one brownout output rising edge event has been detected since the last read of the SUPC_SR.
        };
        namespace bodrstsValC{
            constexpr MPL::Value<bodrstsVal,bodrstsVal::no> no{};
            constexpr MPL::Value<bodrstsVal,bodrstsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,bodrstsVal> bodrsts{}; 
        ///Supply Monitor Reset Status
        enum class smrstsVal {
            no=0x00000000,     ///<no supply monitor detection has generated a core reset since the last read of the SUPC_SR.
            present=0x00000001,     ///<at least one supply monitor detection has generated a core reset since the last read of the SUPC_SR.
        };
        namespace smrstsValC{
            constexpr MPL::Value<smrstsVal,smrstsVal::no> no{};
            constexpr MPL::Value<smrstsVal,smrstsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,smrstsVal> smrsts{}; 
        ///Supply Monitor Status
        enum class smsVal {
            no=0x00000000,     ///<no supply monitor detection since the last read of SUPC_SR.
            present=0x00000001,     ///<at least one supply monitor detection since the last read of SUPC_SR.
        };
        namespace smsValC{
            constexpr MPL::Value<smsVal,smsVal::no> no{};
            constexpr MPL::Value<smsVal,smsVal::present> present{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,smsVal> sms{}; 
        ///Supply Monitor Output Status
        enum class smosVal {
            high=0x00000000,     ///<the supply monitor detected VDDUTMI higher than its threshold at its last measurement.
            low=0x00000001,     ///<the supply monitor detected VDDUTMI lower than its threshold at its last measurement.
        };
        namespace smosValC{
            constexpr MPL::Value<smosVal,smosVal::high> high{};
            constexpr MPL::Value<smosVal,smosVal::low> low{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,smosVal> smos{}; 
        ///32-kHz Oscillator Selection Status
        enum class oscselVal {
            rc=0x00000000,     ///<the slow clock, SLCK is generated by the embedded 32-kHz RC oscillator.
            cryst=0x00000001,     ///<the slow clock, SLCK is generated by the 32-kHz crystal oscillator.
        };
        namespace oscselValC{
            constexpr MPL::Value<oscselVal,oscselVal::rc> rc{};
            constexpr MPL::Value<oscselVal,oscselVal::cryst> cryst{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,oscselVal> oscsel{}; 
        ///FWUP Input Status
        enum class fwupisVal {
            low=0x00000000,     ///<FWUP input is tied low.
            high=0x00000001,     ///<FWUP input is tied high.
        };
        namespace fwupisValC{
            constexpr MPL::Value<fwupisVal,fwupisVal::low> low{};
            constexpr MPL::Value<fwupisVal,fwupisVal::high> high{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,fwupisVal> fwupis{}; 
        ///WKUP Input Status 0
        enum class wkupis0Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis0ValC{
            constexpr MPL::Value<wkupis0Val,wkupis0Val::dis> dis{};
            constexpr MPL::Value<wkupis0Val,wkupis0Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,wkupis0Val> wkupis0{}; 
        ///WKUP Input Status 1
        enum class wkupis1Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis1ValC{
            constexpr MPL::Value<wkupis1Val,wkupis1Val::dis> dis{};
            constexpr MPL::Value<wkupis1Val,wkupis1Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,wkupis1Val> wkupis1{}; 
        ///WKUP Input Status 2
        enum class wkupis2Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis2ValC{
            constexpr MPL::Value<wkupis2Val,wkupis2Val::dis> dis{};
            constexpr MPL::Value<wkupis2Val,wkupis2Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,wkupis2Val> wkupis2{}; 
        ///WKUP Input Status 3
        enum class wkupis3Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis3ValC{
            constexpr MPL::Value<wkupis3Val,wkupis3Val::dis> dis{};
            constexpr MPL::Value<wkupis3Val,wkupis3Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,wkupis3Val> wkupis3{}; 
        ///WKUP Input Status 4
        enum class wkupis4Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis4ValC{
            constexpr MPL::Value<wkupis4Val,wkupis4Val::dis> dis{};
            constexpr MPL::Value<wkupis4Val,wkupis4Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,wkupis4Val> wkupis4{}; 
        ///WKUP Input Status 5
        enum class wkupis5Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis5ValC{
            constexpr MPL::Value<wkupis5Val,wkupis5Val::dis> dis{};
            constexpr MPL::Value<wkupis5Val,wkupis5Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,wkupis5Val> wkupis5{}; 
        ///WKUP Input Status 6
        enum class wkupis6Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis6ValC{
            constexpr MPL::Value<wkupis6Val,wkupis6Val::dis> dis{};
            constexpr MPL::Value<wkupis6Val,wkupis6Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,wkupis6Val> wkupis6{}; 
        ///WKUP Input Status 7
        enum class wkupis7Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis7ValC{
            constexpr MPL::Value<wkupis7Val,wkupis7Val::dis> dis{};
            constexpr MPL::Value<wkupis7Val,wkupis7Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,wkupis7Val> wkupis7{}; 
        ///WKUP Input Status 8
        enum class wkupis8Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis8ValC{
            constexpr MPL::Value<wkupis8Val,wkupis8Val::dis> dis{};
            constexpr MPL::Value<wkupis8Val,wkupis8Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,wkupis8Val> wkupis8{}; 
        ///WKUP Input Status 9
        enum class wkupis9Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis9ValC{
            constexpr MPL::Value<wkupis9Val,wkupis9Val::dis> dis{};
            constexpr MPL::Value<wkupis9Val,wkupis9Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,wkupis9Val> wkupis9{}; 
        ///WKUP Input Status 10
        enum class wkupis10Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis10ValC{
            constexpr MPL::Value<wkupis10Val,wkupis10Val::dis> dis{};
            constexpr MPL::Value<wkupis10Val,wkupis10Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,wkupis10Val> wkupis10{}; 
        ///WKUP Input Status 11
        enum class wkupis11Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis11ValC{
            constexpr MPL::Value<wkupis11Val,wkupis11Val::dis> dis{};
            constexpr MPL::Value<wkupis11Val,wkupis11Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,wkupis11Val> wkupis11{}; 
        ///WKUP Input Status 12
        enum class wkupis12Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis12ValC{
            constexpr MPL::Value<wkupis12Val,wkupis12Val::dis> dis{};
            constexpr MPL::Value<wkupis12Val,wkupis12Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,wkupis12Val> wkupis12{}; 
        ///WKUP Input Status 13
        enum class wkupis13Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis13ValC{
            constexpr MPL::Value<wkupis13Val,wkupis13Val::dis> dis{};
            constexpr MPL::Value<wkupis13Val,wkupis13Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,wkupis13Val> wkupis13{}; 
        ///WKUP Input Status 14
        enum class wkupis14Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis14ValC{
            constexpr MPL::Value<wkupis14Val,wkupis14Val::dis> dis{};
            constexpr MPL::Value<wkupis14Val,wkupis14Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(30,30),Register::ReadWriteAccess,wkupis14Val> wkupis14{}; 
        ///WKUP Input Status 15
        enum class wkupis15Val {
            dis=0x00000000,     ///<the corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake up event.
            en=0x00000001,     ///<the corresponding wake-up input was active at the time the debouncer triggered a wake up event.
        };
        namespace wkupis15ValC{
            constexpr MPL::Value<wkupis15Val,wkupis15Val::dis> dis{};
            constexpr MPL::Value<wkupis15Val,wkupis15Val::en> en{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,wkupis15Val> wkupis15{}; 
    }
}