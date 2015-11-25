#pragma once 
#include "Register/Utility.hpp"
namespace Kvasir {
//Product name title=UM10430 Chapter title=LPC18xx USB0 Host/Device/OTG controller Modification date=1/19/2011 Major revision=0 Minor revision=7 
    namespace Nonecaplength{    ///<Capability register length
        using Addr = Register::Address<0x40006100,0xff000000,0,unsigned>;
        ///Indicates offset to add to the register base address at the beginning of the Operational Register
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> caplength{}; 
        ///BCD encoding of the EHCI revision number supported by this host controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,8),Register::ReadWriteAccess,unsigned> hciversion{}; 
    }
    namespace Nonehcsparams{    ///<Host controller structural parameters
        using Addr = Register::Address<0x40006104,0xf00e00e0,0,unsigned>;
        ///Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> nPorts{}; 
        ///Port Power Control. This field indicates whether the host controller implementation includes port power control.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ppc{}; 
        ///Number of Ports per Companion Controller. This field indicates the number of ports supported per internal Companion Controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> nPcc{}; 
        ///Number of Companion Controller. This field indicates the number of companion controllers associated with this USB2.0 host controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,unsigned> nCc{}; 
        ///Port indicators. This bit indicates whether the ports support port indicator control.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> pi{}; 
        ///Number of Ports per Transaction Translator. This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> nPtt{}; 
        ///Number of Transaction Translators. This field indicates the number of embedded transaction translators associated with the USB2.0 host controller.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,24),Register::ReadWriteAccess,unsigned> nTt{}; 
    }
    namespace Nonehccparams{    ///<Host controller capability parameters
        using Addr = Register::Address<0x40006108,0xffff0008,0,unsigned>;
        ///64-bit Addressing Capability. If zero, no 64-bit addressing capability is supported.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> adc{}; 
        ///Programmable Frame List Flag. If set to one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-boundary. This requirement ensures that the frame list is always physically contiguous.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pfl{}; 
        ///Asynchronous Schedule Park Capability. If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule.The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> asp{}; 
        ///Isochronous Scheduling Threshold. This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> ist{}; 
        ///EHCI Extended Capabilities Pointer. This optional field indicates the existence of a capabilities list.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,8),Register::ReadWriteAccess,unsigned> eecp{}; 
    }
    namespace Nonedciversion{    ///<Device interface version number
        using Addr = Register::Address<0x40006120,0xffff0000,0,unsigned>;
        ///The device controller interface conforms to the two-byte BCD encoding of the interface version number contained in this register.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> dciversion{}; 
    }
    namespace NoneusbcmdD{    ///<USB command (device mode)
        using Addr = Register::Address<0x40006140,0xff009ffc,0,unsigned>;
        ///Run/Stop
        enum class rsVal {
            detach=0x00000000,     ///<Writing a 0 to this bit will cause a detach event.
            attach=0x00000001,     ///<Writing a one to this bit will cause the device controller to enable a pull-up on USB_DP and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the device controller has been properly initialized.
        };
        namespace rsValC{
            constexpr MPL::Value<rsVal,rsVal::detach> detach{};
            constexpr MPL::Value<rsVal,rsVal::attach> attach{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rsVal> rs{}; 
        ///Controller reset. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register.
        enum class rstVal {
            resetcomplete=0x00000000,     ///<Set to 0 by hardware when the reset process is complete.
            reset=0x00000001,     ///<When software writes a one to this bit, the Device Controller resets its internal pipelines, timers, counters, state machines etc. to their initial values. Writing a one to this bit when the device is in the attached state is not recommended, since the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        };
        namespace rstValC{
            constexpr MPL::Value<rstVal,rstVal::resetcomplete> resetcomplete{};
            constexpr MPL::Value<rstVal,rstVal::reset> reset{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rstVal> rst{}; 
        ///Setup trip wire  During handling a setup packet, this bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (see USBMODE register) then there exists a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software and will be cleared by hardware when a hazard exists. (See Section 18.10).
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> sutw{}; 
        ///Add dTD trip wire This bit is used as a semaphore to ensure the to proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software during the process of adding a new dTD. See also Section 18.10. This bit shall also be cleared by hardware when its state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> atdtw{}; 
        ///Interrupt threshold control. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. All other values are reserved. 0x0 = Immediate (no threshold) 0x1 = 1 micro frame. 0x2 = 2 micro frames. 0x8 = 8 micro frames. 0x10 = 16 micro frames. 0x20 = 32 micro frames. 0x40 = 64 micro frames.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> itc{}; 
    }
    namespace NoneusbcmdH{    ///<USB command (host mode)
        using Addr = Register::Address<0x40006140,0xff007480,0,unsigned>;
        ///Run/Stop
        enum class rsVal {
            halt=0x00000000,     ///<When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Host Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the host controller is in the Halted state (i.e. HCHalted in the USBSTS register is a one).
            proceed=0x00000001,     ///<When set to a 1, the Host Controller proceeds with the execution of the schedule. The Host Controller continues execution as long as this bit is set to a one.
        };
        namespace rsValC{
            constexpr MPL::Value<rsVal,rsVal::halt> halt{};
            constexpr MPL::Value<rsVal,rsVal::proceed> proceed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rsVal> rs{}; 
        ///Controller reset.  Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register.
        enum class rstVal {
            resetcomplete=0x00000000,     ///<This bit is set to zero by hardware when the reset process is complete.
            reset=0x00000001,     ///<When software writes a one to this bit, the Host Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior.
        };
        namespace rstValC{
            constexpr MPL::Value<rstVal,rstVal::resetcomplete> resetcomplete{};
            constexpr MPL::Value<rstVal,rstVal::reset> reset{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,rstVal> rst{}; 
        ///Bit 0 of the Frame List Size bits. See Table 220. This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index. Note that this field is made up from USBCMD bits 15, 3, and 2.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> fs0{}; 
        ///Bit 1 of the Frame List Size bits. See Table 220.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> fs1{}; 
        ///This bit controls whether the host controller skips processing the periodic schedule.
        enum class pseVal {
            doNotProcessTheP=0x00000000,     ///<Do not process the periodic schedule.
            useThePeriodiclist=0x00000001,     ///<Use the PERIODICLISTBASE register to access the periodic schedule.
        };
        namespace pseValC{
            constexpr MPL::Value<pseVal,pseVal::doNotProcessTheP> doNotProcessTheP{};
            constexpr MPL::Value<pseVal,pseVal::useThePeriodiclist> useThePeriodiclist{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,pseVal> pse{}; 
        ///This bit controls whether the host controller skips processing the asynchronous schedule.
        enum class aseVal {
            doNotProcessTheA=0x00000000,     ///<Do not process the asynchronous schedule.
            useTheAsynclistadd=0x00000001,     ///<Use the ASYNCLISTADDR to access the asynchronous schedule.
        };
        namespace aseValC{
            constexpr MPL::Value<aseVal,aseVal::doNotProcessTheA> doNotProcessTheA{};
            constexpr MPL::Value<aseVal,aseVal::useTheAsynclistadd> useTheAsynclistadd{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,aseVal> ase{}; 
        ///This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule.
        enum class iaaVal {
            theHostController=0x00000000,     ///<The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one.
            softwareMustWrite=0x00000001,     ///<Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results.
        };
        namespace iaaValC{
            constexpr MPL::Value<iaaVal,iaaVal::theHostController> theHostController{};
            constexpr MPL::Value<iaaVal,iaaVal::softwareMustWrite> softwareMustWrite{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,iaaVal> iaa{}; 
        ///Asynchronous schedule park mode Contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 0x1 to 0x3.  Software must not write 00 to this bit when Park Mode Enable is one as this will result in undefined behavior.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,8),Register::ReadWriteAccess,unsigned> asp10{}; 
        ///Asynchronous Schedule Park Mode Enable
        enum class aspeVal {
            parkModeIsDisable=0x00000000,     ///<Park mode is disabled.
            parkModeIsEnabled=0x00000001,     ///<Park mode is enabled.
        };
        namespace aspeValC{
            constexpr MPL::Value<aspeVal,aspeVal::parkModeIsDisable> parkModeIsDisable{};
            constexpr MPL::Value<aspeVal,aspeVal::parkModeIsEnabled> parkModeIsEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,aspeVal> aspe{}; 
        ///Bit 2 of the Frame List Size bits. See Table 220.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,unsigned> fs2{}; 
        ///Interrupt threshold control. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. All other values are reserved. 0x0 = Immediate (no threshold) 0x1 = 1 micro frame. 0x2 = 2 micro frames. 0x8 = 8 micro frames. 0x10 = 16 micro frames. 0x20 = 32 micro frames. 0x40 = 64 micro frames.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> itc{}; 
    }
    namespace NoneusbstsD{    ///<USB status (device mode)
        using Addr = Register::Address<0x40006144,0xfffefe18,0,unsigned>;
        ///USB interrupt
        enum class uiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        };
        namespace uiValC{
            constexpr MPL::Value<uiVal,uiVal::st> st{};
            constexpr MPL::Value<uiVal,uiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,uiVal> ui{}; 
        ///USB error interrupt
        enum class ueiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set. The device controller detects resume signaling only (see  Section 18.10.11.6).
        };
        namespace ueiValC{
            constexpr MPL::Value<ueiVal,ueiVal::st> st{};
            constexpr MPL::Value<ueiVal,ueiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,ueiVal> uei{}; 
        ///Port change detect.
        enum class pciVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit (URI) and the DCSuspend bits (SLI) respectively.
        };
        namespace pciValC{
            constexpr MPL::Value<pciVal,pciVal::st> st{};
            constexpr MPL::Value<pciVal,pciVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,pciVal> pci{}; 
        ///Not used in Device mode.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> aai{}; 
        ///USB reset received
        enum class uriVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<When the device controller detects a USB Reset and enters the default state, this bit will be set to a one.
        };
        namespace uriValC{
            constexpr MPL::Value<uriVal,uriVal::st> st{};
            constexpr MPL::Value<uriVal,uriVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,uriVal> uri{}; 
        ///SOF received
        enum class sriVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1 ms in device FS mode and every 125  ms in HS mode and will be synchronized to the actual SOF that is received. Since the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp.
        };
        namespace sriValC{
            constexpr MPL::Value<sriVal,sriVal::st> st{};
            constexpr MPL::Value<sriVal,sriVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,sriVal> sri{}; 
        ///DCSuspend
        enum class sliVal {
            st=0x00000000,     ///<The device controller clears the bit upon exiting from a suspend state. This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<When a device controller enters a suspend state from an active state, this bit will be set to a one.
        };
        namespace sliValC{
            constexpr MPL::Value<sliVal,sliVal::st> st{};
            constexpr MPL::Value<sliVal,sliVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,sliVal> sli{}; 
        ///NAK interrupt bit
        enum class nakiVal {
            st=0x00000000,     ///<This bit is automatically cleared by hardware when the all the enabled TX/RX Endpoint NAK bits are cleared.
            clear=0x00000001,     ///<It is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and the corresponding TX/RX Endpoint NAK Enable bit are set.
        };
        namespace nakiValC{
            constexpr MPL::Value<nakiVal,nakiVal::st> st{};
            constexpr MPL::Value<nakiVal,nakiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,nakiVal> naki{}; 
    }
    namespace NoneusbstsH{    ///<USB status (host mode)
        using Addr = Register::Address<0x40006144,0xfff30f50,0,unsigned>;
        ///USB interrupt (USBINT)
        enum class uiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        };
        namespace uiValC{
            constexpr MPL::Value<uiVal,uiVal::st> st{};
            constexpr MPL::Value<uiVal,uiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,uiVal> ui{}; 
        ///USB error interrupt (USBERRINT)
        enum class ueiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set.
        };
        namespace ueiValC{
            constexpr MPL::Value<ueiVal,ueiVal::st> st{};
            constexpr MPL::Value<ueiVal,ueiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,ueiVal> uei{}; 
        ///Port change detect.
        enum class pciVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port.
        };
        namespace pciValC{
            constexpr MPL::Value<pciVal,pciVal::st> st{};
            constexpr MPL::Value<pciVal,pciVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,pciVal> pci{}; 
        ///Frame list roll-over
        enum class friVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example, if the frame list size (as programmed in the Frame List Size field of the USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX bit 13 toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FRINDEX bit 12 toggles (see Section 18.6.6).
        };
        namespace friValC{
            constexpr MPL::Value<friVal,friVal::st> st{};
            constexpr MPL::Value<friVal,friVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,friVal> fri{}; 
        ///Interrupt on async advance
        enum class aaiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the USBCMD register. This status bit indicates the assertion of that interrupt source.
        };
        namespace aaiValC{
            constexpr MPL::Value<aaiVal,aaiVal::st> st{};
            constexpr MPL::Value<aaiVal,aaiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,aaiVal> aai{}; 
        ///SOF received
        enum class sriVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<In host mode, this bit will be set every 125 ms and can be used by host controller driver as a time base.
        };
        namespace sriValC{
            constexpr MPL::Value<sriVal,sriVal::st> st{};
            constexpr MPL::Value<sriVal,sriVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,sriVal> sri{}; 
        ///HCHalted
        enum class hchVal {
            rs=0x00000000,     ///<The RS bit in USBCMD is set to zero. Set by the host controller.
            halt=0x00000001,     ///<The Host Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Host Controller hardware (e.g. because of an internal error).
        };
        namespace hchValC{
            constexpr MPL::Value<hchVal,hchVal::rs> rs{};
            constexpr MPL::Value<hchVal,hchVal::halt> halt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,hchVal> hch{}; 
        ///Reclamation
        enum class rclVal {
            noEmptyAsynchronou=0x00000000,     ///<No empty asynchronous schedule detected.
            emptyAsynchronou=0x00000001,     ///<An empty asynchronous schedule is detected. Set by the host controller.
        };
        namespace rclValC{
            constexpr MPL::Value<rclVal,rclVal::noEmptyAsynchronou> noEmptyAsynchronou{};
            constexpr MPL::Value<rclVal,rclVal::emptyAsynchronou> emptyAsynchronou{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,rclVal> rcl{}; 
        ///Periodic schedule status This bit reports the current real status of the Periodic Schedule. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (if both are 1) or disabled (if both are 0).
        enum class psVal {
            disabled=0x00000000,     ///<The periodic schedule status is disabled.
            disabled=0x00000001,     ///<The periodic schedule status is enabled.
        };
        namespace psValC{
            constexpr MPL::Value<psVal,psVal::disabled> disabled{};
            constexpr MPL::Value<psVal,psVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,psVal> ps{}; 
        ///Asynchronous schedule status This bit reports the current real status of the Asynchronous Schedule. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (if both are 1) or disabled (if both are 0).
        enum class asVal {
            disabled=0x00000000,     ///<Asynchronous schedule status is disabled.
            disabled=0x00000001,     ///<Asynchronous schedule status is enabled.
        };
        namespace asValC{
            constexpr MPL::Value<asVal,asVal::disabled> disabled{};
            constexpr MPL::Value<asVal,asVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,15),Register::ReadWriteAccess,asVal> as{}; 
        ///USB host asynchronous interrupt (USBHSTASYNCINT)
        enum class uaiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<This bit is set by the Host Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set and the TD was from the asynchronous schedule. This bit is also set by the Host when a short packet is detected and the packet is on the asynchronous schedule. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        };
        namespace uaiValC{
            constexpr MPL::Value<uaiVal,uaiVal::st> st{};
            constexpr MPL::Value<uaiVal,uaiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,uaiVal> uai{}; 
        ///USB host periodic interrupt (USBHSTPERINT)
        enum class upiVal {
            st=0x00000000,     ///<This bit is cleared by software writing a one to it.
            clear=0x00000001,     ///<This bit is set by the Host Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set and the TD was from the periodic schedule. This bit is also set by the Host Controller when a short packet is detected and the packet is on the periodic schedule. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        };
        namespace upiValC{
            constexpr MPL::Value<upiVal,upiVal::st> st{};
            constexpr MPL::Value<upiVal,upiVal::clear> clear{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,upiVal> upi{}; 
    }
    namespace NoneusbintrD{    ///<USB interrupt enable (device mode)
        using Addr = Register::Address<0x40006148,0xfffefe38,0,unsigned>;
        ///USB interrupt enable When this bit is one, and the USBINT bit in the USBSTS register is one, the host/device controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBINT bit in USBSTS.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ue{}; 
        ///USB error interrupt enable When this bit is a one, and the USBERRINT bit in the USBSTS register is a one, the host/device controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBERRINT bit in the USBSTS register.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> uee{}; 
        ///Port change detect enable When this bit is a one, and the Port Change Detect bit in the USBSTS register is a one, the host/device controller will issue an interrupt. The interrupt is acknowledged by software clearing the Port Change Detect bit in USBSTS.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pce{}; 
        ///USB reset enable When this bit is a one, and the USB Reset Received bit in the USBSTS register is a one, the device controller will issue an interrupt. The interrupt is acknowledged by software clearing the USB Reset Received bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> ure{}; 
        ///SOF received enable When this bit is a one, and the SOF Received bit in the USBSTS register is a one, the device controller will issue an interrupt. The interrupt is acknowledged by software clearing the SOF Received bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> sre{}; 
        ///Sleep enable When this bit is a one, and the DCSuspend bit in the USBSTS register transitions, the device controller will issue an interrupt. The interrupt is acknowledged by software writing a one to the DCSuspend bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> sle{}; 
        ///NAK interrupt enable This bit is set by software if it wants to enable the hardware interrupt for the NAK Interrupt bit. If both this bit and the corresponding NAK Interrupt bit are set, a hardware interrupt is generated.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> nake{}; 
    }
    namespace NoneusbintrH{    ///<USB interrupt enable (host mode)
        using Addr = Register::Address<0x40006148,0xfff3ff50,0,unsigned>;
        ///USB interrupt enable When this bit is one, and the USBINT bit in the USBSTS register is one, the host/device controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBINT bit in USBSTS.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ue{}; 
        ///USB error interrupt enable When this bit is a one, and the USBERRINT bit in the USBSTS register is a one, the host/device controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBERRINT bit in the USBSTS register.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> uee{}; 
        ///Port change detect enable When this bit is a one, and the Port Change Detect bit in the USBSTS register is a one, the host/device controller will issue an interrupt. The interrupt is acknowledged by software clearing the Port Change Detect bit in USBSTS.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pce{}; 
        ///Frame list rollover enable When this bit is a one, and the Frame List Rollover bit in the USBSTS register is a one, the host controller will issue an interrupt. The interrupt is acknowledged by software clearing the Frame List Rollover bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> fre{}; 
        ///Interrupt on asynchronous advance enable When this bit is a one, and the Interrupt on Async Advance bit in the USBSTS register is a one, the host controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the Interrupt on Async Advance bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> aae{}; 
        ///If this bit is one and the SRI bit in the USBSTS register is one, the host controller will issue an interrupt. In host mode, the SRI bit will be set every 125 ms and can be used by the host controller as a time base. The interrupt is acknowledged by software clearing the SRI bit in the USBSTS register.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> sre{}; 
        ///USB host asynchronous interrupt enable When this bit is a one, and the USBHSTASYNCINT bit in the USBSTS register is a one, the host controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBHSTASYNCINT bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> uaie{}; 
        ///USB host periodic interrupt enable When this bit is a one, and the USBHSTPERINT bit in the USBSTS register is a one, the host controller will issue an interrupt at the next interrupt threshold. The interrupt is acknowledged by software clearing the USBHSTPERINT bit.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> upia{}; 
    }
    namespace NonefrindexD{    ///<USB frame index (device mode)
        using Addr = Register::Address<0x4000614c,0xffffc000,0,unsigned>;
        ///Current micro frame number
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> frindex20{}; 
        ///Current frame number of the last frame transmitted
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,3),Register::ReadWriteAccess,unsigned> frindex133{}; 
    }
    namespace NonefrindexH{    ///<USB frame index (host mode)
        using Addr = Register::Address<0x4000614c,0xffffe000,0,unsigned>;
        ///Current micro frame number
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,0),Register::ReadWriteAccess,unsigned> frindex20{}; 
        ///Frame list current index.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,3),Register::ReadWriteAccess,unsigned> frindex123{}; 
    }
    namespace Nonedeviceaddr{    ///<USB device address (device mode)
        using Addr = Register::Address<0x40006154,0x00ffffff,0,unsigned>;
        ///Device address advance
        enum class usbadraVal {
            instantaneous=0x00000000,     ///<Any write to USBADR are instantaneous.
            delayed=0x00000001,     ///<When the user writes a one to this bit at the same time or before USBADR is written, the write to USBADR fields is staged and held in a hidden register. After an IN occurs on endpoint 0 and is acknowledged, USBADR will be loaded from the holding register. Hardware will automatically clear this bit on the following conditions: IN is ACKed to endpoint 0. USBADR is updated from the staging register. OUT/SETUP occurs on endpoint 0. USBADR is not updated. Device reset occurs. USBADR is set to 0. After the status phase of the SET_ADDRESS descriptor, the DCD has 2 ms to program the USBADR field. This mechanism will ensure this specification is met when the DCD can not write the device address within 2 ms from the SET_ADDRESS status phase. If the DCD writes the USBADR with USBADRA=1 after the SET_ADDRESS data phase (before the prime of the status phase), the USBADR will be programmed instantly at the correct time and meet the 2 ms USB requirement.
        };
        namespace usbadraValC{
            constexpr MPL::Value<usbadraVal,usbadraVal::instantaneous> instantaneous{};
            constexpr MPL::Value<usbadraVal,usbadraVal::delayed> delayed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,usbadraVal> usbadra{}; 
        ///USB device address
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,25),Register::ReadWriteAccess,unsigned> usbadr{}; 
    }
    namespace Noneperiodiclistbase{    ///<Frame list base address (host mode)
        using Addr = Register::Address<0x40006154,0x00000fff,0,unsigned>;
        ///Base Address (Low) These bits correspond to the memory address signals 31:12.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,12),Register::ReadWriteAccess,unsigned> perbase3112{}; 
    }
    namespace Noneendpointlistaddr{    ///<Address of endpoint list in memory
        using Addr = Register::Address<0x40006158,0x000007ff,0,unsigned>;
        ///Endpoint list pointer (low) These bits correspond to memory address signals 31:11, respectively. This field will reference a list of up to 4 Queue Heads (QH). (i.e. one queue head per endpoint and direction.)
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,11),Register::ReadWriteAccess,unsigned> epbase3111{}; 
    }
    namespace Noneasynclistaddr{    ///<Address of endpoint list in memory
        using Addr = Register::Address<0x40006158,0x0000001f,0,unsigned>;
        ///Link pointer (Low) LPL These bits correspond to memory address signals 31:5, respectively. This field may only reference a Queue Head (OH).
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,5),Register::ReadWriteAccess,unsigned> asybase315{}; 
    }
    namespace Nonettctrl{    ///<Asynchronous buffer status for embedded TT (host mode)
        using Addr = Register::Address<0x4000615c,0x80ffffff,0,unsigned>;
        ///Hub address when FS or LS device are connected directly.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(30,24),Register::ReadWriteAccess,unsigned> ttha{}; 
    }
    namespace Noneburstsize{    ///<Programmable burst size
        using Addr = Register::Address<0x40006160,0xffff0000,0,unsigned>;
        ///Programmable RX burst length This register represents the maximum length of a burst in 32-bit words while moving data from the USB bus to system memory.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> rxpburst{}; 
        ///Programmable TX burst length This register represents the maximum length of a burst in 32-bit words while moving data from system memory to the USB bus.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,8),Register::ReadWriteAccess,unsigned> txpburst{}; 
    }
    namespace Nonetxfilltuning{    ///<Host transmit pre-buffer packet tuning (host mode)
        using Addr = Register::Address<0x40006164,0xffc0e000,0,unsigned>;
        ///FIFO burst threshold This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in USBMODE register is set.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> txschoh{}; 
        ///Scheduler health counter This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame . This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter. The maximum value is 31.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,8),Register::ReadWriteAccess,unsigned> txscheatlth{}; 
        ///Scheduler overhead This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267  ms when a device is connected in High-Speed Mode for OTG and SPH. The time unit represented in this register is 6.333  ms when a device is connected in Low/Full Speed Mode for OTG and SPH.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,16),Register::ReadWriteAccess,unsigned> txfifothres{}; 
    }
    namespace Nonebinterval{    ///<Length of virtual frame
        using Addr = Register::Address<0x40006174,0xfffffff0,0,unsigned>;
        ///bInterval value (see Section 18.7.7)
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> bint{}; 
    }
    namespace Noneendptnak{    ///<Endpoint NAK (device mode)
        using Addr = Register::Address<0x40006178,0xffc0ffc0,0,unsigned>;
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> eprn0{}; 
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> eprn1{}; 
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> eprn2{}; 
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> eprn3{}; 
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> eprn4{}; 
        ///Rx endpoint NAK Each RX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> eprn5{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> eptn0{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> eptn1{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> eptn2{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> eptn3{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> eptn4{}; 
        ///Tx endpoint NAK Each TX endpoint has one bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit 3 corresponds to endpoint 3. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> eptn5{}; 
    }
    namespace Noneendptnaken{    ///<Endpoint NAK Enable (device mode)
        using Addr = Register::Address<0x4000617c,0xffc0ffc0,0,unsigned>;
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> eprne0{}; 
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> eprne1{}; 
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> eprne2{}; 
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> eprne3{}; 
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> eprne4{}; 
        ///Rx endpoint NAK enable Each bit enables the corresponding RX NAK bit. If this bit is set and the corresponding RX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> eprne5{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> eptne0{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> eptne1{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> eptne2{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> eptne3{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> eptne4{}; 
        ///Tx endpoint NAK Each bit enables the corresponding TX NAK bit. If this bit is set and the corresponding TX endpoint NAK bit is set, the NAK interrupt bit is set. Bit 5 corresponds to endpoint 5. ... Bit 1 corresponds to endpoint 1. Bit 0 corresponds to endpoint 0.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> eptne5{}; 
    }
    namespace Noneportsc1D{    ///<Port 1 status/control (device mode)
        using Addr = Register::Address<0x40006184,0xf2703c32,0,unsigned>;
        ///Current connect status
        enum class ccsVal {
            deviceNotAttached=0x00000000,     ///<Device not attached A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
            deviceAttachedA=0x00000001,     ///<Device attached.  A one indicates that the device successfully attached and is operating in either high-speed mode or full-speed mode as indicated by the High Speed Port bit in this register.
        };
        namespace ccsValC{
            constexpr MPL::Value<ccsVal,ccsVal::deviceNotAttached> deviceNotAttached{};
            constexpr MPL::Value<ccsVal,ccsVal::deviceAttachedA> deviceAttachedA{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ccsVal> ccs{}; 
        ///Port enable. This bit is always 1. The device port is always enabled.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> pe{}; 
        ///Port enable/disable change This bit is always 0. The device port is always enabled.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> pec{}; 
        ///Force port resume After the device has been in Suspend State for 5 ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. When this bit transitions to a one because a J-to-K transition detected, the Port Change Detect bit in the USBSTS register is set to one as well.
        enum class fprVal {
            noResumeKState=0x00000000,     ///<No resume (K-state) detected/driven on port.
            resumeDetecteddriv=0x00000001,     ///<Resume detected/driven on port.
        };
        namespace fprValC{
            constexpr MPL::Value<fprVal,fprVal::noResumeKState> noResumeKState{};
            constexpr MPL::Value<fprVal,fprVal::resumeDetecteddriv> resumeDetecteddriv{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,fprVal> fpr{}; 
        ///Suspend In device mode, this is a read-only status bit .
        enum class suspVal {
            portNotInSuspend=0x00000000,     ///<Port not in suspend state
            portInSuspendStat=0x00000001,     ///<Port in suspend state
        };
        namespace suspValC{
            constexpr MPL::Value<suspVal,suspVal::portNotInSuspend> portNotInSuspend{};
            constexpr MPL::Value<suspVal,suspVal::portInSuspendStat> portInSuspendStat{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,suspVal> susp{}; 
        ///Port reset In device mode, this is a read-only status bit. A device reset from the USB bus is also indicated in the USBSTS register.
        enum class prVal {
            portIsNotInTheR=0x00000000,     ///<Port is not in the reset state.
            portIsInTheReset=0x00000001,     ///<Port is in the reset state.
        };
        namespace prValC{
            constexpr MPL::Value<prVal,prVal::portIsNotInTheR> portIsNotInTheR{};
            constexpr MPL::Value<prVal,prVal::portIsInTheReset> portIsInTheReset{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,prVal> pr{}; 
        ///High-speed status This bit is redundant with bits 27:26 (PSPD) in this register. It is implemented for compatibility reasons.
        enum class hspVal {
            notHighsspeed=0x00000000,     ///<Host/device connected to the port is not in High-speed mode.
            highspeed=0x00000001,     ///<Host/device connected to the port is in High-speed mode.
        };
        namespace hspValC{
            constexpr MPL::Value<hspVal,hspVal::notHighsspeed> notHighsspeed{};
            constexpr MPL::Value<hspVal,hspVal::highspeed> highspeed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,hspVal> hsp{}; 
        ///Port indicator control Writing to this field effects the value of the USB0_IND[1:0] pins.
        enum class pic10Val {
            off=0x00000000,     ///<Port indicators are off.
            amber=0x00000001,     ///<amber
            green=0x00000002,     ///<green
            undefined=0x00000003,     ///<undefined
        };
        namespace pic10ValC{
            constexpr MPL::Value<pic10Val,pic10Val::off> off{};
            constexpr MPL::Value<pic10Val,pic10Val::amber> amber{};
            constexpr MPL::Value<pic10Val,pic10Val::green> green{};
            constexpr MPL::Value<pic10Val,pic10Val::undefined> undefined{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,14),Register::ReadWriteAccess,pic10Val> pic10{}; 
        ///Port test control Any value other than 0000 indicates that the port is operating in test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_HS/FS/LS values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Values 0111 to 1111 are not valid.
        enum class ptc30Val {
            testModeDisable=0x00000000,     ///<TEST_MODE_DISABLE
            jState=0x00000001,     ///<J_STATE
            kState=0x00000002,     ///<K_STATE
            se0HostnakDevi=0x00000003,     ///<SE0 (host)/NAK (device)
            packet=0x00000004,     ///<Packet
            forceEnableHs=0x00000005,     ///<FORCE_ENABLE_HS
            forceEnableFs=0x00000006,     ///<FORCE_ENABLE_FS
        };
        namespace ptc30ValC{
            constexpr MPL::Value<ptc30Val,ptc30Val::testModeDisable> testModeDisable{};
            constexpr MPL::Value<ptc30Val,ptc30Val::jState> jState{};
            constexpr MPL::Value<ptc30Val,ptc30Val::kState> kState{};
            constexpr MPL::Value<ptc30Val,ptc30Val::se0HostnakDevi> se0HostnakDevi{};
            constexpr MPL::Value<ptc30Val,ptc30Val::packet> packet{};
            constexpr MPL::Value<ptc30Val,ptc30Val::forceEnableHs> forceEnableHs{};
            constexpr MPL::Value<ptc30Val,ptc30Val::forceEnableFs> forceEnableFs{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,ptc30Val> ptc30{}; 
        ///PHY low power suspend - clock disable (PLPSCD) In device mode, The PHY can be put into Low Power Suspend - Clock Disable when the device is not running (USBCMD Run/Stop = 0) or the host has signaled suspend (PORTSC SUSPEND = 1). Low power suspend will be cleared automatically when the host has signaled resume. Before forcing a resume from the device, the device controller driver must clear this bit.
        enum class phcdVal {
            enable=0x00000000,     ///<Writing a 0 enables the PHY clock. Reading a 0 indicates the status of the PHY clock (enabled).
            disable=0x00000001,     ///<Writing a 1 disables the PHY clock. Reading a 1 indicates the status of the PHY clock (disabled).
        };
        namespace phcdValC{
            constexpr MPL::Value<phcdVal,phcdVal::enable> enable{};
            constexpr MPL::Value<phcdVal,phcdVal::disable> disable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,phcdVal> phcd{}; 
        ///Port force full speed connect
        enum class pfscVal {
            anyspeed=0x00000000,     ///<Port connects at any speed.
            fullspeed=0x00000001,     ///<Writing this bit to a 1 will force the port to only connect at full speed. It disables the chirp sequence that allows the port to identify itself as High-speed. This is useful for testing FS configurations with a HS host, hub or device.
        };
        namespace pfscValC{
            constexpr MPL::Value<pfscVal,pfscVal::anyspeed> anyspeed{};
            constexpr MPL::Value<pfscVal,pfscVal::fullspeed> fullspeed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,pfscVal> pfsc{}; 
        ///Port speed This register field indicates the speed at which the port is operating.
        enum class pspdVal {
            fullSpeed=0x00000000,     ///<Full-speed
            invalidInDeviceMo=0x00000001,     ///<invalid in device mode
            highSpeed=0x00000002,     ///<High-speed
        };
        namespace pspdValC{
            constexpr MPL::Value<pspdVal,pspdVal::fullSpeed> fullSpeed{};
            constexpr MPL::Value<pspdVal,pspdVal::invalidInDeviceMo> invalidInDeviceMo{};
            constexpr MPL::Value<pspdVal,pspdVal::highSpeed> highSpeed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,26),Register::ReadWriteAccess,pspdVal> pspd{}; 
    }
    namespace Noneportsc1H{    ///<Port 1 status/control (host mode)
        using Addr = Register::Address<0x40006184,0xf2002000,0,unsigned>;
        ///Current connect status This value reflects the current state of the port and may not correspond directly to the event that caused the CSC bit to be set. This bit is 0 if PP (Port Power bit) is 0. Software clears this bit by writing a 1 to it.
        enum class ccsVal {
            noDeviceIsPresent=0x00000000,     ///<No device is present.
            deviceIsPresentOn=0x00000001,     ///<Device is present on the port.
        };
        namespace ccsValC{
            constexpr MPL::Value<ccsVal,ccsVal::noDeviceIsPresent> noDeviceIsPresent{};
            constexpr MPL::Value<ccsVal,ccsVal::deviceIsPresentOn> deviceIsPresentOn{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,ccsVal> ccs{}; 
        ///Connect status change Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be setting an already-set bit (i.e., the bit will remain set). Software clears this bit by writing a one to it. This bit is 0 if PP (Port Power bit) is 0
        enum class cscVal {
            noChangeInCurrent=0x00000000,     ///<No change in current status.
            changeInCurrentSt=0x00000001,     ///<Change in current status.
        };
        namespace cscValC{
            constexpr MPL::Value<cscVal,cscVal::noChangeInCurrent> noChangeInCurrent{};
            constexpr MPL::Value<cscVal,cscVal::changeInCurrentSt> changeInCurrentSt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,cscVal> csc{}; 
        ///Port enable. Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events. When the port is disabled. downstream propagation of data is blocked except for reset. This bit is 0 if PP (Port Power bit) is 0.
        enum class peVal {
            portDisabled=0x00000000,     ///<Port disabled.
            portEnabled=0x00000001,     ///<Port enabled.
        };
        namespace peValC{
            constexpr MPL::Value<peVal,peVal::portDisabled> portDisabled{};
            constexpr MPL::Value<peVal,peVal::portEnabled> portEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,peVal> pe{}; 
        ///Port disable/enable change For the root hub, this bit gets set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it. This bit is 0 if PP (Port Power bit) is 0,
        enum class pecVal {
            noChange=0x00000000,     ///<No change.
            portEnableddisable=0x00000001,     ///<Port enabled/disabled status has changed.
        };
        namespace pecValC{
            constexpr MPL::Value<pecVal,pecVal::noChange> noChange{};
            constexpr MPL::Value<pecVal,pecVal::portEnableddisable> portEnableddisable{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,pecVal> pec{}; 
        ///Over-current active This bit will automatically transition from 1 to 0 when the over-current condition is removed.
        enum class ocaVal {
            thePortDoesNotHa=0x00000000,     ///<The port does not have an over-current condition.
            thePortHasCurrent=0x00000001,     ///<The port has currently an over-current condition.
        };
        namespace ocaValC{
            constexpr MPL::Value<ocaVal,ocaVal::thePortDoesNotHa> thePortDoesNotHa{};
            constexpr MPL::Value<ocaVal,ocaVal::thePortHasCurrent> thePortHasCurrent{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,ocaVal> oca{}; 
        ///Over-current change This bit gets set to one when there is a change to Over-current Active. Software clears this bit by writing a one to this bit position.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> occ{}; 
        ///Force port resume Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver. Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed K) is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle. This bit is 0 if PP (Port Power bit) is 0.
        enum class fprVal {
            noResumeKState=0x00000000,     ///<No resume (K-state) detected/driven on port.
            resumeDetecteddriv=0x00000001,     ///<Resume detected/driven on port.
        };
        namespace fprValC{
            constexpr MPL::Value<fprVal,fprVal::noResumeKState> noResumeKState{};
            constexpr MPL::Value<fprVal,fprVal::resumeDetecteddriv> resumeDetecteddriv{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,fprVal> fpr{}; 
        ///Suspend Together with the PE (Port enabled bit), this bit describes the port states, see Table 240. The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit. If host software sets this bit to a one when the port is not enabled (i.e. Port enabled bit is a zero) the results are undefined. This bit is 0 if PP (Port Power bit) is 0.
        enum class suspVal {
            portNotInSuspend=0x00000000,     ///<Port not in suspend state
            portInSuspendStat=0x00000001,     ///<Port in suspend state When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the USB.
        };
        namespace suspValC{
            constexpr MPL::Value<suspVal,suspVal::portNotInSuspend> portNotInSuspend{};
            constexpr MPL::Value<suspVal,suspVal::portInSuspendStat> portInSuspendStat{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,suspVal> susp{}; 
        ///Port reset When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver. This bit is 0 if PP (Port Power bit) is 0.
        enum class prVal {
            portIsNotInTheR=0x00000000,     ///<Port is not in the reset state.
            portIsInTheReset=0x00000001,     ///<Port is in the reset state.
        };
        namespace prValC{
            constexpr MPL::Value<prVal,prVal::portIsNotInTheR> portIsNotInTheR{};
            constexpr MPL::Value<prVal,prVal::portIsInTheReset> portIsInTheReset{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,prVal> pr{}; 
        ///High-speed status
        enum class hspVal {
            hostdeviceConnecte=0x00000000,     ///<Host/device connected to the port is not in High-speed mode.
            hostdeviceConnecte=0x00000001,     ///<Host/device connected to the port is in High-speed mode.
        };
        namespace hspValC{
            constexpr MPL::Value<hspVal,hspVal::hostdeviceConnecte> hostdeviceConnecte{};
            constexpr MPL::Value<hspVal,hspVal::hostdeviceConnecte> hostdeviceConnecte{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,hspVal> hsp{}; 
        ///Line status These bits reflect the current logical levels of the USB_DP and USB_DM signal lines. USB_DP corresponds to bit 11 and USB_DM to bit 10. In host mode, the use of linestate by the host controller driver is not necessary for this controller (unlike EHCI) because the controller hardware manages the connection of LS and FS.
        enum class lsVal {
            se0UsbDpAndUsb=0x00000000,     ///<SE0 (USB_DP and USB_DM LOW)
            jStateUsbDpHigh=0x00000001,     ///<J-state (USB_DP HIGH and USB_DM LOW)
            kStateUsbDpLow=0x00000002,     ///<K-state (USB_DP LOW and USB_DM HIGH)
            undefined=0x00000003,     ///<Undefined
        };
        namespace lsValC{
            constexpr MPL::Value<lsVal,lsVal::se0UsbDpAndUsb> se0UsbDpAndUsb{};
            constexpr MPL::Value<lsVal,lsVal::jStateUsbDpHigh> jStateUsbDpHigh{};
            constexpr MPL::Value<lsVal,lsVal::kStateUsbDpLow> kStateUsbDpLow{};
            constexpr MPL::Value<lsVal,lsVal::undefined> undefined{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,10),Register::ReadWriteAccess,lsVal> ls{}; 
        ///Port power control Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (i.e. PP equals a 0), the port is non-functional and will not report attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitioned by the host controller driver from a one to a zero (removing power from the port).
        enum class ppVal {
            portPowerOff=0x00000000,     ///<Port power off.
            portPowerOn=0x00000001,     ///<Port power on.
        };
        namespace ppValC{
            constexpr MPL::Value<ppVal,ppVal::portPowerOff> portPowerOff{};
            constexpr MPL::Value<ppVal,ppVal::portPowerOn> portPowerOn{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,ppVal> pp{}; 
        ///Port indicator control Writing to this field effects the value of the pins USB0_IND1 and USB0_IND0.
        enum class pic10Val {
            portIndicatorsAre=0x00000000,     ///<Port indicators are off.
            amber=0x00000001,     ///<Amber
            green=0x00000002,     ///<Green
            undefined=0x00000003,     ///<Undefined
        };
        namespace pic10ValC{
            constexpr MPL::Value<pic10Val,pic10Val::portIndicatorsAre> portIndicatorsAre{};
            constexpr MPL::Value<pic10Val,pic10Val::amber> amber{};
            constexpr MPL::Value<pic10Val,pic10Val::green> green{};
            constexpr MPL::Value<pic10Val,pic10Val::undefined> undefined{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,14),Register::ReadWriteAccess,pic10Val> pic10{}; 
        ///Port test control Any value other than 0000 indicates that the port is operating in test mode.  The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Values 0x8 to 0xF are reserved.
        enum class ptc30Val {
            testModeDisable=0x00000000,     ///<TEST_MODE_DISABLE
            jState=0x00000001,     ///<J_STATE
            kState=0x00000002,     ///<K_STATE
            se0HostnakDevi=0x00000003,     ///<SE0 (host)/NAK (device)
            packet=0x00000004,     ///<Packet
            forceEnableHs=0x00000005,     ///<FORCE_ENABLE_HS
            forceEnableFs=0x00000006,     ///<FORCE_ENABLE_FS
            forceEnableLs=0x00000007,     ///<FORCE_ENABLE_LS
        };
        namespace ptc30ValC{
            constexpr MPL::Value<ptc30Val,ptc30Val::testModeDisable> testModeDisable{};
            constexpr MPL::Value<ptc30Val,ptc30Val::jState> jState{};
            constexpr MPL::Value<ptc30Val,ptc30Val::kState> kState{};
            constexpr MPL::Value<ptc30Val,ptc30Val::se0HostnakDevi> se0HostnakDevi{};
            constexpr MPL::Value<ptc30Val,ptc30Val::packet> packet{};
            constexpr MPL::Value<ptc30Val,ptc30Val::forceEnableHs> forceEnableHs{};
            constexpr MPL::Value<ptc30Val,ptc30Val::forceEnableFs> forceEnableFs{};
            constexpr MPL::Value<ptc30Val,ptc30Val::forceEnableLs> forceEnableLs{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,ptc30Val> ptc30{}; 
        ///Wake on connect enable (WKCNNT_E) This bit is 0 if PP (Port Power bit) is 0
        enum class wkcnVal {
            disablesThePortTo=0x00000000,     ///<Disables the port to wake up on device connects.
            writingThisBitTo=0x00000001,     ///<Writing this bit to a one enables the port to be sensitive to device connects as wake-up events.
        };
        namespace wkcnValC{
            constexpr MPL::Value<wkcnVal,wkcnVal::disablesThePortTo> disablesThePortTo{};
            constexpr MPL::Value<wkcnVal,wkcnVal::writingThisBitTo> writingThisBitTo{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,wkcnVal> wkcn{}; 
        ///Wake on disconnect enable (WKDSCNNT_E) This bit is 0 if PP (Port Power bit) is 0.
        enum class wkdcVal {
            disablesThePortTo=0x00000000,     ///<Disables the port to wake up on device disconnects.
            writingThisBitTo=0x00000001,     ///<Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events.
        };
        namespace wkdcValC{
            constexpr MPL::Value<wkdcVal,wkdcVal::disablesThePortTo> disablesThePortTo{};
            constexpr MPL::Value<wkdcVal,wkdcVal::writingThisBitTo> writingThisBitTo{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,wkdcVal> wkdc{}; 
        ///Wake on over-current enable (WKOC_E)
        enum class wkocVal {
            disablesThePortTo=0x00000000,     ///<Disables the port to wake up on over-current events.
            writingAOneToThi=0x00000001,     ///<Writing a one to this bit enabled the port to be sensitive to over-current conditions as wake-up events.
        };
        namespace wkocValC{
            constexpr MPL::Value<wkocVal,wkocVal::disablesThePortTo> disablesThePortTo{};
            constexpr MPL::Value<wkocVal,wkocVal::writingAOneToThi> writingAOneToThi{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,wkocVal> wkoc{}; 
        ///PHY low power suspend - clock disable (PLPSCD) In host mode, the PHY can be put into Low Power Suspend - Clock Disable when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        enum class phcdVal {
            writingA0Enables=0x00000000,     ///<Writing a 0 enables the PHY clock. Reading a 0 indicates the status of the PHY clock (enabled).
            writingA1Disables=0x00000001,     ///<Writing a 1 disables the PHY clock. Reading a 1 indicates the status of the PHY clock (disabled).
        };
        namespace phcdValC{
            constexpr MPL::Value<phcdVal,phcdVal::writingA0Enables> writingA0Enables{};
            constexpr MPL::Value<phcdVal,phcdVal::writingA1Disables> writingA1Disables{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,phcdVal> phcd{}; 
        ///Port force full speed connect
        enum class pfscVal {
            portConnectsAtAny=0x00000000,     ///<Port connects at any speed.
            writingThisBitTo=0x00000001,     ///<Writing this bit to a 1 will force the port to only connect at Full Speed. It disables the chirp sequence that allows the port to identify itself as High Speed. This is useful for testing FS configurations with a HS host, hub or device.
        };
        namespace pfscValC{
            constexpr MPL::Value<pfscVal,pfscVal::portConnectsAtAny> portConnectsAtAny{};
            constexpr MPL::Value<pfscVal,pfscVal::writingThisBitTo> writingThisBitTo{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,pfscVal> pfsc{}; 
        ///Port speed This register field indicates the speed at which the port is operating. For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        enum class pspdVal {
            fullSpeed=0x00000000,     ///<Full-speed
            lowSpeed=0x00000001,     ///<Low-speed
            highSpeed=0x00000002,     ///<High-speed
        };
        namespace pspdValC{
            constexpr MPL::Value<pspdVal,pspdVal::fullSpeed> fullSpeed{};
            constexpr MPL::Value<pspdVal,pspdVal::lowSpeed> lowSpeed{};
            constexpr MPL::Value<pspdVal,pspdVal::highSpeed> highSpeed{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,26),Register::ReadWriteAccess,pspdVal> pspd{}; 
    }
    namespace Noneotgsc{    ///<OTG status and control
        using Addr = Register::Address<0x400061a4,0x80808000,0,unsigned>;
        ///VBUS_Discharge Setting this bit to 1 causes VBUS to discharge through a resistor.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> vd{}; 
        ///VBUS_Charge Setting this bit to 1 causes the VBUS line to be charged. This is used for VBUS pulsing during SRP.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> vc{}; 
        ///Hardware assist auto_reset
        enum class haarVal {
            disabled=0x00000000,     ///<Disabled
            enableAutomaticRes=0x00000001,     ///<Enable automatic reset after connect on host port.
        };
        namespace haarValC{
            constexpr MPL::Value<haarVal,haarVal::disabled> disabled{};
            constexpr MPL::Value<haarVal,haarVal::enableAutomaticRes> enableAutomaticRes{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,haarVal> haar{}; 
        ///OTG termination This bit must be set to 1 when the OTG controller is in device mode. This controls the pull-down on USB_DM.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ot{}; 
        ///Data pulsing Setting this bit to 1 causes the pull-up on USB_DP to be asserted for data pulsing during SRP.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> dp{}; 
        ///ID pull-up. This bit provides control over the pull-up resistor.
        enum class idpuVal {
            pullUpOffTheId=0x00000000,     ///<Pull-up off. The ID bit will not be sampled.
            pullUpOn=0x00000001,     ///<Pull-up on.
        };
        namespace idpuValC{
            constexpr MPL::Value<idpuVal,idpuVal::pullUpOffTheId> pullUpOffTheId{};
            constexpr MPL::Value<idpuVal,idpuVal::pullUpOn> pullUpOn{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,idpuVal> idpu{}; 
        ///Hardware assist data pulse Write a 1 to start data pulse sequence.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> hadp{}; 
        ///Hardware assist B-disconnect to A-connect
        enum class habaVal {
            disabled=0x00000000,     ///<Disabled.
            enableAutomaticBD=0x00000001,     ///<Enable automatic B-disconnect to A-connect sequence.
        };
        namespace habaValC{
            constexpr MPL::Value<habaVal,habaVal::disabled> disabled{};
            constexpr MPL::Value<habaVal,habaVal::enableAutomaticBD> enableAutomaticBD{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,habaVal> haba{}; 
        ///USB ID
        enum class idVal {
            aDevice=0x00000000,     ///<A-device
            bDevice=0x00000001,     ///<B-device
        };
        namespace idValC{
            constexpr MPL::Value<idVal,idVal::aDevice> aDevice{};
            constexpr MPL::Value<idVal,idVal::bDevice> bDevice{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,idVal> id{}; 
        ///A-VBUS valid Reading 1 indicates that VBUS is above the A-VBUS valid threshold.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> avv{}; 
        ///A-session valid Reading 1 indicates that VBUS is above the A-session valid threshold.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,unsigned> asv{}; 
        ///B-session valid Reading 1 indicates that VBUS is above the B-session valid threshold.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> bsv{}; 
        ///B-session end Reading 1 indicates that VBUS is below the B-session end threshold.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> bse{}; 
        ///1 millisecond timer toggle This bit toggles once per millisecond.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> ms1t{}; 
        ///Data bus pulsing status Reading a 1 indicates that data bus pulsing is detected on the port.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(14,14),Register::ReadWriteAccess,unsigned> dps{}; 
        ///USB ID interrupt status This bit is set when a change on the ID input has been detected. Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> idis{}; 
        ///A-VBUS valid interrupt status This bit is set then VBUS has either risen above or fallen below the A-VBUS valid threshold (4.4 V on an A-device). Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> avvis{}; 
        ///A-Session valid interrupt status This bit is set then VBUS has either risen above or fallen below the A-session valid threshold (0.8 V).  Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> asvis{}; 
        ///B-Session valid interrupt status This bit is set then VBUS has either risen above or fallen below the B-session valid threshold (0.8 V). Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> bsvis{}; 
        ///B-Session end interrupt status This bit is set then VBUS has fallen below the B-session end threshold.  Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> bseis{}; 
        ///1 millisecond timer interrupt status This bit is set once every millisecond. Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> ms1s{}; 
        ///Data pulse interrupt status This bit is set when data bus pulsing occurs on DP or DM. Data bus pulsing is only detected when the CM bit in USBMODE = Host (11) and the PortPower bit in PORTSC = Off (0). Software must write a 1 to this bit to clear it.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> dpis{}; 
        ///USB ID interrupt enable Setting this bit enables the interrupt. Writing a 0 disables the interrupt.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> idie{}; 
        ///A-VBUS valid interrupt enable Setting this bit enables the A-VBUS valid interrupt. Writing a 0 disables the interrupt.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(25,25),Register::ReadWriteAccess,unsigned> avvie{}; 
        ///A-session valid interrupt enable Setting this bit enables the A-session valid interrupt. Writing a 0 disables the interrupt
        constexpr Register::BitLocation<Addr,Register::maskFromRange(26,26),Register::ReadWriteAccess,unsigned> asvie{}; 
        ///B-session valid interrupt enable Setting this bit enables the B-session valid interrupt. Writing a 0 disables the interrupt.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(27,27),Register::ReadWriteAccess,unsigned> bsvie{}; 
        ///B-session end interrupt enable Setting this bit enables the B-session end interrupt. Writing a 0 disables the interrupt.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(28,28),Register::ReadWriteAccess,unsigned> bseie{}; 
        ///1 millisecond timer interrupt enable Setting this bit enables the 1 millisecond timer interrupt. Writing a 0 disables the interrupt.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(29,29),Register::ReadWriteAccess,unsigned> ms1e{}; 
        ///Data pulse interrupt enable Setting this bit enables the data pulse interrupt. Writing a 0 disables the interrupt
        constexpr Register::BitLocation<Addr,Register::maskFromRange(30,30),Register::ReadWriteAccess,unsigned> dpie{}; 
    }
    namespace NoneusbmodeD{    ///<USB device mode (device mode)
        using Addr = Register::Address<0x400061a8,0xffffffe0,0,unsigned>;
        ///Controller mode The controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. This register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register.
        enum class cm10Val {
            idle=0x00000000,     ///<Idle
            reserved=0x00000001,     ///<Reserved
            deviceController=0x00000002,     ///<Device controller
            hostController=0x00000003,     ///<Host controller
        };
        namespace cm10ValC{
            constexpr MPL::Value<cm10Val,cm10Val::idle> idle{};
            constexpr MPL::Value<cm10Val,cm10Val::reserved> reserved{};
            constexpr MPL::Value<cm10Val,cm10Val::deviceController> deviceController{};
            constexpr MPL::Value<cm10Val,cm10Val::hostController> hostController{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,cm10Val> cm10{}; 
        ///Endian select This bit can change the byte ordering of the transfer buffers to match the host microprocessor bus architecture. The bit fields in the microprocessor interface and the DMA data structures (including the setup buffer within the device QH) are unaffected by the value of this bit, because they are based upon 32-bit words.
        enum class esVal {
            littleEndianFirst=0x00000000,     ///<Little endian: first byte referenced in least significant byte of 32-bit word.
            bigEndianFirstBy=0x00000001,     ///<Big endian: first byte referenced in most significant byte of 32-bit word.
        };
        namespace esValC{
            constexpr MPL::Value<esVal,esVal::littleEndianFirst> littleEndianFirst{};
            constexpr MPL::Value<esVal,esVal::bigEndianFirstBy> bigEndianFirstBy{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,esVal> es{}; 
        ///Setup Lockout mode In device mode, this bit controls behavior of the setup lock mechanism. See Section 18.10.8.
        enum class slomVal {
            setupLockoutsOn=0x00000000,     ///<Setup Lockouts on
            setupLockoutsOff=0x00000001,     ///<Setup Lockouts Off (DCD requires the use of Setup Buffer Tripwire in USBCMD)
        };
        namespace slomValC{
            constexpr MPL::Value<slomVal,slomVal::setupLockoutsOn> setupLockoutsOn{};
            constexpr MPL::Value<slomVal,slomVal::setupLockoutsOff> setupLockoutsOff{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,slomVal> slom{}; 
        ///Stream disable mode  The use of this feature substantially limits the overall USB performance that can be achieved.
        enum class sdisVal {
            notDisabled=0x00000000,     ///<Not disabled
            disabledSettingTh=0x00000001,     ///<Disabled. Setting this bit to one disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received will be responded to with a NYET handshake when stream disable is active.
        };
        namespace sdisValC{
            constexpr MPL::Value<sdisVal,sdisVal::notDisabled> notDisabled{};
            constexpr MPL::Value<sdisVal,sdisVal::disabledSettingTh> disabledSettingTh{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,sdisVal> sdis{}; 
    }
    namespace NoneusbmodeH{    ///<USB mode (host mode)
        using Addr = Register::Address<0x400061a8,0xffffffc8,0,unsigned>;
        ///Controller mode The controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. This register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register.
        enum class cmVal {
            idle=0x00000000,     ///<Idle
            reserved=0x00000001,     ///<Reserved
            deviceController=0x00000002,     ///<Device controller
            hostController=0x00000003,     ///<Host controller
        };
        namespace cmValC{
            constexpr MPL::Value<cmVal,cmVal::idle> idle{};
            constexpr MPL::Value<cmVal,cmVal::reserved> reserved{};
            constexpr MPL::Value<cmVal,cmVal::deviceController> deviceController{};
            constexpr MPL::Value<cmVal,cmVal::hostController> hostController{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,cmVal> cm{}; 
        ///Endian select This bit can change the byte ordering of the transfer buffers. The bit fields in the microprocessor interface and the DMA data structures (including the setup buffer within the device QH) are unaffected by the value of this bit, because they are based upon 32-bit words.
        enum class esVal {
            littleEndianFirst=0x00000000,     ///<Little endian: first byte referenced in least significant byte of 32-bit word.
            bigEndianFirstBy=0x00000001,     ///<Big endian: first byte referenced in most significant byte of 32-bit word.
        };
        namespace esValC{
            constexpr MPL::Value<esVal,esVal::littleEndianFirst> littleEndianFirst{};
            constexpr MPL::Value<esVal,esVal::bigEndianFirstBy> bigEndianFirstBy{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,esVal> es{}; 
        ///Stream disable mode  The use of this feature substantially limits the overall USB performance that can be achieved.
        enum class sdisVal {
            notDisabled=0x00000000,     ///<Not disabled
            disabledSettingTo=0x00000001,     ///<Disabled. Setting to a 1 ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the the TX latency is filled to capacity before the packet is launched onto the USB. Note: Time duration to pre-fill the FIFO becomes significant when stream disable is active. See TXFILLTUNING to characterize the adjustments needed for the scheduler when using this feature.
        };
        namespace sdisValC{
            constexpr MPL::Value<sdisVal,sdisVal::notDisabled> notDisabled{};
            constexpr MPL::Value<sdisVal,sdisVal::disabledSettingTo> disabledSettingTo{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,sdisVal> sdis{}; 
        ///VBUS power select
        enum class vbpsVal {
            low=0x00000000,     ///<vbus_pwr_select is set LOW.
            high=0x00000001,     ///<vbus_pwr_select is set HIGH
        };
        namespace vbpsValC{
            constexpr MPL::Value<vbpsVal,vbpsVal::low> low{};
            constexpr MPL::Value<vbpsVal,vbpsVal::high> high{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,vbpsVal> vbps{}; 
    }
    namespace Noneendptsetupstat{    ///<Endpoint setup status
        using Addr = Register::Address<0x400061ac,0xffffffc0,0,unsigned>;
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> endptsetupstat0{}; 
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> endptsetupstat1{}; 
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> endptsetupstat2{}; 
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> endptsetupstat3{}; 
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> endptsetupstat4{}; 
        ///Setup endpoint status for logical endpoints 0 to 5. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lockout mechanism is engaged.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> endptsetupstat5{}; 
    }
    namespace Noneendptprime{    ///<Endpoint initialization
        using Addr = Register::Address<0x400061b0,0xffc0ffc0,0,unsigned>;
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> perb0{}; 
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> perb1{}; 
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> perb2{}; 
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> perb3{}; 
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> perb4{}; 
        ///Prime endpoint receive buffer for physical OUT endpoints 5 to 0. For each OUT endpoint, a corresponding bit is set to 1 by software to request a buffer be prepared for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed. PERB0 = endpoint 0 ... PERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> perb5{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> petb0{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> petb1{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> petb2{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> petb3{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> petb4{}; 
        ///Prime endpoint transmit buffer for physical IN endpoints 5 to 0. For each IN endpoint a corresponding bit is set to one by software to request a buffer be prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware will automatically use this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware will clear this bit when the associated endpoint(s) is (are) successfully primed.  PETB0 = endpoint 0 ... PETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> petb5{}; 
    }
    namespace Noneendptflush{    ///<Endpoint de-initialization
        using Addr = Register::Address<0x400061b4,0xffc0ffc0,0,unsigned>;
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> ferb0{}; 
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> ferb1{}; 
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> ferb2{}; 
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> ferb3{}; 
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> ferb4{}; 
        ///Flush endpoint receive buffer for physical OUT endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers. FERB0 = endpoint 0 ... FERB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> ferb5{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> fetb0{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> fetb1{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> fetb2{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> fetb3{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> fetb4{}; 
        ///Flush endpoint transmit buffer for physical IN endpoints 5 to 0. Writing a one to a bit(s) will clear any primed buffers.  FETB0 = endpoint 0 ... FETB5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> fetb5{}; 
    }
    namespace Noneendptstat{    ///<Endpoint status
        using Addr = Register::Address<0x400061b8,0xffc0ffc0,0,unsigned>;
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> erbr0{}; 
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> erbr1{}; 
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> erbr2{}; 
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> erbr3{}; 
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> erbr4{}; 
        ///Endpoint receive buffer ready for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ERBR0 = endpoint 0 ... ERBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> erbr5{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> etbr0{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> etbr1{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> etbr2{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> etbr3{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> etbr4{}; 
        ///Endpoint transmit buffer ready for physical IN endpoints 3 to 0. This bit is set to 1 by hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. ETBR0 = endpoint 0 ... ETBR5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> etbr5{}; 
    }
    namespace Noneendptcomplete{    ///<Endpoint complete
        using Addr = Register::Address<0x400061bc,0xffc0ffc0,0,unsigned>;
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> erce0{}; 
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> erce1{}; 
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> erce2{}; 
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> erce3{}; 
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> erce4{}; 
        ///Endpoint receive complete event for physical OUT endpoints 5 to 0. This bit is set to 1 by hardware when receive event (OUT/SETUP) occurred. ERCE0 = endpoint 0 ... ERCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> erce5{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> etce0{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> etce1{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> etce2{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> etce3{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> etce4{}; 
        ///Endpoint transmit complete event for physical IN endpoints 5 to 0. This bit is set to 1 by hardware when a transmit event (IN/INTERRUPT) occurred. ETCE0 = endpoint 0 ... ETCE5 = endpoint 5
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,unsigned> etce5{}; 
    }
    namespace Noneendptctrl0{    ///<Endpoint control 0
        using Addr = Register::Address<0x400061c0,0xff72ff72,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOk=0x00000000,     ///<Endpoint ok.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request. After receiving a SETUP request, this bit will continue to be cleared by hardware until the associated ENDSETUPSTAT bit is cleared.[1]
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOk> endpointOk{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type Endpoint 0 is always a control endpoint.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,unsigned> rxt10{}; 
        ///Rx endpoint enable Endpoint enabled. Control endpoint 0 is always enabled. This bit is always 1.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOk=0x00000000,     ///<Endpoint ok.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request. After receiving a SETUP request, this bit will continue to be cleared by hardware until the associated ENDSETUPSTAT bit is cleared.[1]
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOk> endpointOk{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Endpoint type Endpoint 0 is always a control endpoint.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,unsigned> txt10{}; 
        ///Tx endpoint enable Endpoint enabled. Control endpoint 0 is always enabled. This bit is always 1.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,unsigned> txe{}; 
    }
    namespace Noneendptctrl1{    ///<Endpoint control 
        using Addr = Register::Address<0x400061c4,0xff12ff12,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type
        enum class rxtVal {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            reserved=0x00000003,     ///<Reserved
        };
        namespace rxtValC{
            constexpr MPL::Value<rxtVal,rxtVal::control> control{};
            constexpr MPL::Value<rxtVal,rxtVal::isochronous> isochronous{};
            constexpr MPL::Value<rxtVal,rxtVal::bulk> bulk{};
            constexpr MPL::Value<rxtVal,rxtVal::reserved> reserved{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,rxtVal> rxt{}; 
        ///Rx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class rxiVal {
            disabled=0x00000000,     ///<Disabled
            enabled=0x00000001,     ///<Enabled
        };
        namespace rxiValC{
            constexpr MPL::Value<rxiVal,rxiVal::disabled> disabled{};
            constexpr MPL::Value<rxiVal,rxiVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,rxiVal> rxi{}; 
        ///Rx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rxr{}; 
        ///Rx endpoint enable An endpoint should be enabled only after it has been configured.
        enum class rxeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace rxeValC{
            constexpr MPL::Value<rxeVal,rxeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<rxeVal,rxeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxeVal> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint, and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Tx endpoint type
        enum class txt10Val {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            interrupt=0x00000003,     ///<Interrupt
        };
        namespace txt10ValC{
            constexpr MPL::Value<txt10Val,txt10Val::control> control{};
            constexpr MPL::Value<txt10Val,txt10Val::isochronous> isochronous{};
            constexpr MPL::Value<txt10Val,txt10Val::bulk> bulk{};
            constexpr MPL::Value<txt10Val,txt10Val::interrupt> interrupt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,txt10Val> txt10{}; 
        ///Tx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class txiVal {
            enabled=0x00000000,     ///<Enabled
            disabled=0x00000001,     ///<Disabled
        };
        namespace txiValC{
            constexpr MPL::Value<txiVal,txiVal::enabled> enabled{};
            constexpr MPL::Value<txiVal,txiVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txiVal> txi{}; 
        ///Tx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> txr{}; 
        ///Tx endpoint enable An endpoint should be enabled only after it has been configured
        enum class txeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace txeValC{
            constexpr MPL::Value<txeVal,txeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<txeVal,txeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,txeVal> txe{}; 
    }
    namespace Noneendptctrl2{    ///<Endpoint control 
        using Addr = Register::Address<0x400061c8,0xff12ff12,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type
        enum class rxtVal {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            reserved=0x00000003,     ///<Reserved
        };
        namespace rxtValC{
            constexpr MPL::Value<rxtVal,rxtVal::control> control{};
            constexpr MPL::Value<rxtVal,rxtVal::isochronous> isochronous{};
            constexpr MPL::Value<rxtVal,rxtVal::bulk> bulk{};
            constexpr MPL::Value<rxtVal,rxtVal::reserved> reserved{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,rxtVal> rxt{}; 
        ///Rx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class rxiVal {
            disabled=0x00000000,     ///<Disabled
            enabled=0x00000001,     ///<Enabled
        };
        namespace rxiValC{
            constexpr MPL::Value<rxiVal,rxiVal::disabled> disabled{};
            constexpr MPL::Value<rxiVal,rxiVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,rxiVal> rxi{}; 
        ///Rx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rxr{}; 
        ///Rx endpoint enable An endpoint should be enabled only after it has been configured.
        enum class rxeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace rxeValC{
            constexpr MPL::Value<rxeVal,rxeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<rxeVal,rxeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxeVal> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint, and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Tx endpoint type
        enum class txt10Val {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            interrupt=0x00000003,     ///<Interrupt
        };
        namespace txt10ValC{
            constexpr MPL::Value<txt10Val,txt10Val::control> control{};
            constexpr MPL::Value<txt10Val,txt10Val::isochronous> isochronous{};
            constexpr MPL::Value<txt10Val,txt10Val::bulk> bulk{};
            constexpr MPL::Value<txt10Val,txt10Val::interrupt> interrupt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,txt10Val> txt10{}; 
        ///Tx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class txiVal {
            enabled=0x00000000,     ///<Enabled
            disabled=0x00000001,     ///<Disabled
        };
        namespace txiValC{
            constexpr MPL::Value<txiVal,txiVal::enabled> enabled{};
            constexpr MPL::Value<txiVal,txiVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txiVal> txi{}; 
        ///Tx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> txr{}; 
        ///Tx endpoint enable An endpoint should be enabled only after it has been configured
        enum class txeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace txeValC{
            constexpr MPL::Value<txeVal,txeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<txeVal,txeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,txeVal> txe{}; 
    }
    namespace Noneendptctrl3{    ///<Endpoint control 
        using Addr = Register::Address<0x400061cc,0xff12ff12,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type
        enum class rxtVal {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            reserved=0x00000003,     ///<Reserved
        };
        namespace rxtValC{
            constexpr MPL::Value<rxtVal,rxtVal::control> control{};
            constexpr MPL::Value<rxtVal,rxtVal::isochronous> isochronous{};
            constexpr MPL::Value<rxtVal,rxtVal::bulk> bulk{};
            constexpr MPL::Value<rxtVal,rxtVal::reserved> reserved{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,rxtVal> rxt{}; 
        ///Rx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class rxiVal {
            disabled=0x00000000,     ///<Disabled
            enabled=0x00000001,     ///<Enabled
        };
        namespace rxiValC{
            constexpr MPL::Value<rxiVal,rxiVal::disabled> disabled{};
            constexpr MPL::Value<rxiVal,rxiVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,rxiVal> rxi{}; 
        ///Rx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rxr{}; 
        ///Rx endpoint enable An endpoint should be enabled only after it has been configured.
        enum class rxeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace rxeValC{
            constexpr MPL::Value<rxeVal,rxeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<rxeVal,rxeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxeVal> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint, and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Tx endpoint type
        enum class txt10Val {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            interrupt=0x00000003,     ///<Interrupt
        };
        namespace txt10ValC{
            constexpr MPL::Value<txt10Val,txt10Val::control> control{};
            constexpr MPL::Value<txt10Val,txt10Val::isochronous> isochronous{};
            constexpr MPL::Value<txt10Val,txt10Val::bulk> bulk{};
            constexpr MPL::Value<txt10Val,txt10Val::interrupt> interrupt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,txt10Val> txt10{}; 
        ///Tx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class txiVal {
            enabled=0x00000000,     ///<Enabled
            disabled=0x00000001,     ///<Disabled
        };
        namespace txiValC{
            constexpr MPL::Value<txiVal,txiVal::enabled> enabled{};
            constexpr MPL::Value<txiVal,txiVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txiVal> txi{}; 
        ///Tx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> txr{}; 
        ///Tx endpoint enable An endpoint should be enabled only after it has been configured
        enum class txeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace txeValC{
            constexpr MPL::Value<txeVal,txeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<txeVal,txeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,txeVal> txe{}; 
    }
    namespace Noneendptctrl4{    ///<Endpoint control 
        using Addr = Register::Address<0x400061d0,0xff12ff12,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type
        enum class rxtVal {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            reserved=0x00000003,     ///<Reserved
        };
        namespace rxtValC{
            constexpr MPL::Value<rxtVal,rxtVal::control> control{};
            constexpr MPL::Value<rxtVal,rxtVal::isochronous> isochronous{};
            constexpr MPL::Value<rxtVal,rxtVal::bulk> bulk{};
            constexpr MPL::Value<rxtVal,rxtVal::reserved> reserved{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,rxtVal> rxt{}; 
        ///Rx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class rxiVal {
            disabled=0x00000000,     ///<Disabled
            enabled=0x00000001,     ///<Enabled
        };
        namespace rxiValC{
            constexpr MPL::Value<rxiVal,rxiVal::disabled> disabled{};
            constexpr MPL::Value<rxiVal,rxiVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,rxiVal> rxi{}; 
        ///Rx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rxr{}; 
        ///Rx endpoint enable An endpoint should be enabled only after it has been configured.
        enum class rxeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace rxeValC{
            constexpr MPL::Value<rxeVal,rxeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<rxeVal,rxeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxeVal> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint, and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Tx endpoint type
        enum class txt10Val {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            interrupt=0x00000003,     ///<Interrupt
        };
        namespace txt10ValC{
            constexpr MPL::Value<txt10Val,txt10Val::control> control{};
            constexpr MPL::Value<txt10Val,txt10Val::isochronous> isochronous{};
            constexpr MPL::Value<txt10Val,txt10Val::bulk> bulk{};
            constexpr MPL::Value<txt10Val,txt10Val::interrupt> interrupt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,txt10Val> txt10{}; 
        ///Tx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class txiVal {
            enabled=0x00000000,     ///<Enabled
            disabled=0x00000001,     ///<Disabled
        };
        namespace txiValC{
            constexpr MPL::Value<txiVal,txiVal::enabled> enabled{};
            constexpr MPL::Value<txiVal,txiVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txiVal> txi{}; 
        ///Tx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> txr{}; 
        ///Tx endpoint enable An endpoint should be enabled only after it has been configured
        enum class txeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace txeValC{
            constexpr MPL::Value<txeVal,txeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<txeVal,txeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,txeVal> txe{}; 
    }
    namespace Noneendptctrl5{    ///<Endpoint control 
        using Addr = Register::Address<0x400061d4,0xff12ff12,0,unsigned>;
        ///Rx endpoint stall
        enum class rxsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace rxsValC{
            constexpr MPL::Value<rxsVal,rxsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<rxsVal,rxsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,rxsVal> rxs{}; 
        ///Endpoint type
        enum class rxtVal {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            reserved=0x00000003,     ///<Reserved
        };
        namespace rxtValC{
            constexpr MPL::Value<rxtVal,rxtVal::control> control{};
            constexpr MPL::Value<rxtVal,rxtVal::isochronous> isochronous{};
            constexpr MPL::Value<rxtVal,rxtVal::bulk> bulk{};
            constexpr MPL::Value<rxtVal,rxtVal::reserved> reserved{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,rxtVal> rxt{}; 
        ///Rx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class rxiVal {
            disabled=0x00000000,     ///<Disabled
            enabled=0x00000001,     ///<Enabled
        };
        namespace rxiValC{
            constexpr MPL::Value<rxiVal,rxiVal::disabled> disabled{};
            constexpr MPL::Value<rxiVal,rxiVal::enabled> enabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,rxiVal> rxi{}; 
        ///Rx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rxr{}; 
        ///Rx endpoint enable An endpoint should be enabled only after it has been configured.
        enum class rxeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace rxeValC{
            constexpr MPL::Value<rxeVal,rxeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<rxeVal,rxeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,rxeVal> rxe{}; 
        ///Tx endpoint stall
        enum class txsVal {
            endpointOkThisBi=0x00000000,     ///<Endpoint ok. This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint, and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared.
            endpointStalledSof=0x00000001,     ///<Endpoint stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It will continue returning STALL until the bit is cleared by software, or it will automatically be cleared upon receipt of a new SETUP request.
        };
        namespace txsValC{
            constexpr MPL::Value<txsVal,txsVal::endpointOkThisBi> endpointOkThisBi{};
            constexpr MPL::Value<txsVal,txsVal::endpointStalledSof> endpointStalledSof{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,txsVal> txs{}; 
        ///Tx endpoint type
        enum class txt10Val {
            control=0x00000000,     ///<Control
            isochronous=0x00000001,     ///<Isochronous
            bulk=0x00000002,     ///<Bulk
            interrupt=0x00000003,     ///<Interrupt
        };
        namespace txt10ValC{
            constexpr MPL::Value<txt10Val,txt10Val::control> control{};
            constexpr MPL::Value<txt10Val,txt10Val::isochronous> isochronous{};
            constexpr MPL::Value<txt10Val,txt10Val::bulk> bulk{};
            constexpr MPL::Value<txt10Val,txt10Val::interrupt> interrupt{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(19,18),Register::ReadWriteAccess,txt10Val> txt10{}; 
        ///Tx data toggle inhibit This bit is only used for test and should always be written as zero. Writing a one to this bit will cause this endpoint to ignore the data toggle sequence and always accept data packets regardless of their data PID.
        enum class txiVal {
            enabled=0x00000000,     ///<Enabled
            disabled=0x00000001,     ///<Disabled
        };
        namespace txiValC{
            constexpr MPL::Value<txiVal,txiVal::enabled> enabled{};
            constexpr MPL::Value<txiVal,txiVal::disabled> disabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(21,21),Register::ReadWriteAccess,txiVal> txi{}; 
        ///Tx data toggle reset Write 1 to reset the PID sequence. Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PIDs between the host and device.
        constexpr Register::BitLocation<Addr,Register::maskFromRange(22,22),Register::ReadWriteAccess,unsigned> txr{}; 
        ///Tx endpoint enable An endpoint should be enabled only after it has been configured
        enum class txeVal {
            endpointDisabled=0x00000000,     ///<Endpoint disabled.
            endpointEnabled=0x00000001,     ///<Endpoint enabled.
        };
        namespace txeValC{
            constexpr MPL::Value<txeVal,txeVal::endpointDisabled> endpointDisabled{};
            constexpr MPL::Value<txeVal,txeVal::endpointEnabled> endpointEnabled{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,23),Register::ReadWriteAccess,txeVal> txe{}; 
    }
}