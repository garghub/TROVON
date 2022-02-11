T_1 F_1 ( void )
{
static T_2 V_1 ;
if ( ! F_2 ( & V_1 ) )
F_3 ( & V_1 , ( ( T_1 ) F_4 () ) << 32 ) ;
return F_5 ( & V_1 ) ;
}
const char * F_6 ( unsigned int V_2 )
{
return V_2 < F_7 ( V_3 ) ?
V_3 [ V_2 ] : L_1 ;
}
void F_8 ( const char * V_4 , unsigned int V_5 ,
const char * const V_6 [] , unsigned int V_7 )
{
int V_8 , V_9 = 0 ;
const char * V_10 ;
char V_11 [ 84 ] ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( ! ( V_5 & ( 1U << V_8 ) ) )
continue;
V_10 = V_6 [ V_8 ] ;
if ( ! V_10 )
continue;
if ( V_9 && V_9 + strlen ( V_10 ) + 2 > 80 ) {
F_9 ( L_2 , V_11 ) ;
V_9 = 0 ;
}
if ( ! V_9 )
V_9 = snprintf ( V_11 , sizeof( V_11 ) , L_3 , V_4 , V_10 ) ;
else
V_9 += snprintf ( V_11 + V_9 , sizeof( V_11 ) - V_9 , L_4 , V_10 ) ;
}
if ( V_9 )
F_9 ( L_2 , V_11 ) ;
}
static void F_10 ( const char * V_4 ,
const struct V_12 * V_13 )
{
if ( V_13 -> V_14 & V_15 )
F_9 ( L_5processor_type: %d, %s\nL_6unknownL_7%sL_8processor_isa: %d, %s\nL_9unknownL_10%sL_8error_type: 0x%02x\nL_11%sL_8operation: %d, %s\nL_12unknownL_13%sL_8flags: 0x%02x\nL_14%sL_8level: %d\nL_15%sL_8version_info: 0x%016llx\nL_16%sL_8processor_id: 0x%016llx\nL_17%sL_8target_address: 0x%016llx\nL_18%sL_8requestor_id: 0x%016llx\nL_19%sL_8responder_id: 0x%016llx\nL_20%sL_8IP: 0x%016llx\nL_21AArch32 general purpose registersL_22AArch32 EL1 context registersL_22AArch32 EL2 context registersL_22AArch32 secure context registersL_22AArch64 general purpose registersL_22AArch64 EL1 context registersL_22AArch64 EL2 context registersL_22AArch64 EL3 context registersL_22Misc. system register structureL_23%sMIDR: 0x%016llx\nL_24%ssection length: %d\nL_25%ssection length is too small\nL_26%sfirmware-generated error record is incorrect\nL_26%sERR_INFO_NUM is %d\nL_27%sMultiprocessor Affinity Register (MPIDR): 0x%016llx\nL_28%serror affinity level: %d\nL_29%srunning state: 0x%x\nL_30%sPower State Coordination Interface state: %d\nL_31%s%sL_32%sError info structure %d:\nL_33%snum errors: %d\nL_34%sfirst error captured\nL_35%slast error captured\nL_36%spropagated error captured\nL_37%soverflow occurred, error info is incomplete\nL_38%serror_type: %d, %s\nL_39unknownL_40%serror_info: 0x%016llx\nL_41%svirtual fault address: 0x%016llx\nL_42%sphysical fault address: 0x%016llx\nL_43%sContext info structure %d:\nL_44%ssection length is too small\nL_45%sfirmware-generated error record is incorrect\nL_46%sInvalid context type: %d (max: %d)\nL_47%sregister context type: %s\nL_48 , DUMP_PREFIX_OFFSET, 16 , 4 ,
(ctx_info + 1), ctx_info->size, 0 ) ;
V_9 -= V_16 ;
V_17 = (struct V_18 * ) ( ( long ) V_17 + V_16 ) ;
}
const char * F_11 ( unsigned int V_19 )
{
return V_19 < F_7 ( V_20 ) ?
V_20 [ V_19 ] : L_1 ;
}
static int F_12 ( struct V_21 * V_22 , char * V_23 )
{
T_3 V_9 , V_24 ;
if ( ! V_23 )
return 0 ;
V_24 = 0 ;
V_9 = V_25 - 1 ;
if ( V_22 -> V_14 & V_26 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_49 , V_22 -> V_27 ) ;
if ( V_22 -> V_14 & V_28 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_50 , V_22 -> V_29 ) ;
if ( V_22 -> V_14 & V_30 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_51 , V_22 -> V_31 ) ;
if ( V_22 -> V_14 & V_32 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_52 , V_22 -> V_33 ) ;
if ( V_22 -> V_14 & V_34 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_53 , V_22 -> V_35 ) ;
if ( V_22 -> V_14 & V_36 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_54 , V_22 -> V_37 ) ;
if ( V_22 -> V_14 & V_38 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_55 , V_22 -> V_39 ) ;
if ( V_22 -> V_14 & V_40 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_56 , V_22 -> V_41 ) ;
if ( V_22 -> V_14 & V_42 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_57 ,
V_22 -> V_43 ) ;
if ( V_22 -> V_14 & V_44 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_58 ,
V_22 -> V_45 ) ;
if ( V_22 -> V_14 & V_46 )
V_24 += F_13 ( V_23 + V_24 , V_9 - V_24 , L_59 ,
V_22 -> V_47 ) ;
if ( V_22 -> V_14 & V_48 )
F_13 ( V_23 + V_24 , V_9 - V_24 , L_60 ,
V_22 -> V_49 ) ;
V_23 [ V_24 ] = '\0' ;
return V_24 ;
}
static int F_14 ( struct V_21 * V_22 , char * V_23 )
{
T_3 V_9 , V_24 ;
const char * V_35 = NULL , * V_37 = NULL ;
if ( ! V_23 || ! ( V_22 -> V_14 & V_50 ) )
return 0 ;
V_24 = 0 ;
V_9 = V_25 - 1 ;
F_15 ( V_22 -> V_51 , & V_35 , & V_37 ) ;
if ( V_35 && V_37 )
V_24 = snprintf ( V_23 , V_9 , L_61 , V_35 , V_37 ) ;
else
V_24 = snprintf ( V_23 , V_9 ,
L_62 ,
V_22 -> V_51 ) ;
V_23 [ V_24 ] = '\0' ;
return V_24 ;
}
void F_16 ( const struct V_52 * V_22 ,
struct V_21 * V_53 )
{
V_53 -> V_14 = V_22 -> V_14 ;
V_53 -> V_27 = V_22 -> V_27 ;
V_53 -> V_29 = V_22 -> V_29 ;
V_53 -> V_31 = V_22 -> V_31 ;
V_53 -> V_35 = V_22 -> V_35 ;
V_53 -> V_37 = V_22 -> V_37 ;
V_53 -> V_39 = V_22 -> V_39 ;
V_53 -> V_41 = V_22 -> V_41 ;
V_53 -> V_43 = V_22 -> V_43 ;
V_53 -> V_45 = V_22 -> V_45 ;
V_53 -> V_47 = V_22 -> V_47 ;
V_53 -> V_49 = V_22 -> V_49 ;
V_53 -> V_33 = V_22 -> V_33 ;
V_53 -> V_54 = V_22 -> V_54 ;
V_53 -> V_51 = V_22 -> V_51 ;
}
const char * F_17 ( struct V_55 * V_56 ,
struct V_21 * V_53 )
{
const char * V_57 = F_18 ( V_56 ) ;
if ( F_12 ( V_53 , V_58 ) )
F_19 ( V_56 , L_63 , V_58 ) ;
if ( F_14 ( V_53 , V_58 ) )
F_19 ( V_56 , L_63 , V_58 ) ;
F_20 ( V_56 , '\0' ) ;
return V_57 ;
}
static void F_21 ( const char * V_4 , const struct V_52 * V_22 ,
int V_9 )
{
struct V_21 V_53 ;
if ( V_9 == sizeof( struct V_59 ) &&
( V_22 -> V_14 & ~ ( V_32 - 1 ) ) ) {
F_22 ( V_60 L_64 ) ;
return;
}
if ( V_22 -> V_14 & V_61 )
F_9 ( L_5error_status: 0x%016llx\nL_65%sL_8physical_address: 0x%016llx\nL_66%sL_8physical_address_mask: 0x%016llx\nL_67%s%s\nL_68%sL_8error_type: %d, %s\nL_69%s%s\nL_70PCIe end pointL_22legacy PCI end pointL_22unknownL_22unknownL_22root portL_22upstream switch portL_22downstream switch portL_22PCIe to PCI/PCI-X bridgeL_22PCI/PCI-X to PCIe bridgeL_22root complex integrated endpoint deviceL_22root complex event collectorL_71%sL_8port_type: %d, %s\nL_72unknownL_73%sL_8version: %d.%d\nL_74%sL_8command: 0x%04x , status: 0x%04x\nL_75%sL_8device_id: %04x:%02x:%02x.%x\nL_76%sL_8slot: %d\nL_77%sL_8secondary_bus: 0x%02x\nL_78%sL_8vendor_id: 0x%04x , device_id: 0x%04x\nL_79%sL_8class_code: %02x%02x%02x\nL_80%sL_8serial number: 0x%04x , 0x%04x\nL_81%sL_8bridge: secondary_status: 0x%04x , control: 0x%04x\nL_82%s%ststamp: %02d%02d-%02d-%02d %02d:%02d:%02d\nL_83precise L_84imprecise L_85%sL_8Error %d, type: %s\nL_86%sL_8fru_id: %pUl\nL_87%sL_8fru_text: %.20s\nL_88%s%sL_89%sL_8section_type: general processor error\nL_90%sL_8section_type: memory error\nL_91%sL_8section_type: PCIe error\nL_92%ssection_type: ARM processor error\nL_93%ssection type: unknown, %pUl\nL_94%ssection length: %#x\nL_95 , DUMP_PREFIX_OFFSET, 16 , 4 , err,
gdata->error_data_length, true) ;
}
