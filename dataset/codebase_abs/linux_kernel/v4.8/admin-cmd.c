T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
V_3 <<= 16 ;
V_3 += F_2 ( V_2 -> V_4 . V_6 ) ;
V_3 += 1 ;
V_3 *= sizeof( T_1 ) ;
return V_3 ;
}
static void F_3 ( struct V_7 * V_8 )
{
T_2 V_9 = F_1 ( V_8 -> V_2 ) ;
void * V_10 ;
T_3 V_11 = 0 ;
V_10 = F_4 ( V_9 , V_12 ) ;
if ( ! V_10 ) {
V_11 = V_13 ;
goto V_14;
}
switch ( V_8 -> V_2 -> V_4 . V_15 ) {
case 0x01 :
break;
case 0x02 :
break;
case 0x03 :
break;
default:
F_5 () ;
}
V_11 = F_6 ( V_8 , 0 , V_10 , V_9 ) ;
F_7 ( V_10 ) ;
V_14:
F_8 ( V_8 , V_11 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 -> V_17 ;
struct V_19 * V_20 ;
T_3 V_11 = 0 ;
V_20 = F_4 ( sizeof( * V_20 ) , V_12 ) ;
if ( ! V_20 ) {
V_11 = V_13 ;
goto V_14;
}
V_20 -> V_21 = 0 ;
V_20 -> V_22 = 0 ;
memset ( V_20 -> V_23 , ' ' , sizeof( V_20 -> V_23 ) ) ;
snprintf ( V_20 -> V_23 , sizeof( V_20 -> V_23 ) , L_1 , V_17 -> V_24 ) ;
memset ( V_20 -> V_25 , ' ' , sizeof( V_20 -> V_25 ) ) ;
strncpy ( ( char * ) V_20 -> V_25 , L_2 , sizeof( V_20 -> V_25 ) ) ;
memset ( V_20 -> V_26 , ' ' , sizeof( V_20 -> V_26 ) ) ;
strncpy ( ( char * ) V_20 -> V_26 , V_27 , sizeof( V_20 -> V_26 ) ) ;
V_20 -> V_28 = 6 ;
V_20 -> V_29 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_20 -> V_30 = 0 ;
V_20 -> V_31 = F_10 ( V_17 -> V_31 ) ;
V_20 -> V_32 = F_11 ( V_17 -> V_33 -> V_32 ) ;
V_20 -> V_34 = F_11 ( 1 << 8 ) ;
V_20 -> V_35 = F_11 ( 1 << 0 ) ;
V_20 -> V_36 = 0 ;
V_20 -> V_37 = 3 ;
V_20 -> V_38 = V_39 - 1 ;
V_20 -> V_40 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_20 -> V_41 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_20 -> V_42 = V_43 - 1 ;
V_20 -> V_44 = 0 ;
V_20 -> V_45 = F_10 ( V_46 ) ;
V_20 -> V_47 = ( 0x6 << 4 ) | 0x6 ;
V_20 -> V_48 = ( 0x4 << 4 ) | 0x4 ;
V_20 -> V_49 = F_10 ( V_50 ) ;
V_20 -> V_51 = F_11 ( V_17 -> V_33 -> V_52 ) ;
V_20 -> V_53 = F_10 ( V_54 ) ;
V_20 -> V_55 = V_56 ;
V_20 -> V_57 = 0 ;
V_20 -> V_58 = 0 ;
V_20 -> V_59 = F_11 ( 1 << 0 ) ;
if ( V_17 -> V_60 -> V_61 )
V_20 -> V_59 |= F_11 ( 1 << 2 ) ;
if ( V_17 -> V_60 -> V_62 )
V_20 -> V_59 |= F_11 ( 1 << 20 ) ;
strcpy ( V_20 -> V_63 , V_17 -> V_33 -> V_64 ) ;
V_20 -> V_65 = F_11 ( ( sizeof( struct V_1 ) +
V_17 -> V_60 -> V_62 ) / 16 ) ;
V_20 -> V_66 = F_11 ( sizeof( struct V_67 ) / 16 ) ;
V_20 -> V_68 = V_17 -> V_60 -> V_68 ;
V_20 -> V_69 [ 0 ] . V_70 = F_10 ( 0x9c4 ) ;
V_20 -> V_69 [ 0 ] . V_71 = F_11 ( 0x10 ) ;
V_20 -> V_69 [ 0 ] . V_72 = F_11 ( 0x4 ) ;
V_11 = F_6 ( V_8 , 0 , V_20 , sizeof( * V_20 ) ) ;
F_7 ( V_20 ) ;
V_14:
F_8 ( V_8 , V_11 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_73 * V_74 ;
struct V_75 * V_20 ;
T_3 V_11 = 0 ;
V_74 = F_13 ( V_8 -> V_18 -> V_17 , V_8 -> V_2 -> V_76 . V_77 ) ;
if ( ! V_74 ) {
V_11 = V_78 | V_79 ;
goto V_14;
}
V_20 = F_4 ( sizeof( * V_20 ) , V_12 ) ;
if ( ! V_20 ) {
V_11 = V_13 ;
goto V_80;
}
V_20 -> V_81 = V_20 -> V_82 = V_20 -> V_83 =
F_14 ( V_74 -> V_84 >> V_74 -> V_85 ) ;
V_20 -> V_86 = 0 ;
V_20 -> V_87 = 0 ;
V_20 -> V_88 = ( 1 << 0 ) ;
memcpy ( & V_20 -> V_89 , & V_74 -> V_89 , sizeof( V_90 ) ) ;
V_20 -> V_91 [ 0 ] . V_92 = V_74 -> V_85 ;
V_11 = F_6 ( V_8 , 0 , V_20 , sizeof( * V_20 ) ) ;
F_7 ( V_20 ) ;
V_80:
F_15 ( V_74 ) ;
V_14:
F_8 ( V_8 , V_11 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
static const int V_93 = 4096 ;
struct V_16 * V_17 = V_8 -> V_18 -> V_17 ;
struct V_73 * V_74 ;
T_1 V_94 = F_17 ( V_8 -> V_2 -> V_76 . V_77 ) ;
T_4 * V_95 ;
T_3 V_11 = 0 ;
int V_96 = 0 ;
V_95 = F_4 ( V_93 , V_12 ) ;
if ( ! V_95 ) {
V_11 = V_13 ;
goto V_14;
}
F_18 () ;
F_19 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_74 -> V_77 <= V_94 )
continue;
V_95 [ V_96 ++ ] = F_11 ( V_74 -> V_77 ) ;
if ( V_96 == V_93 / sizeof( T_4 ) )
break;
}
F_20 () ;
V_11 = F_6 ( V_8 , 0 , V_95 , V_93 ) ;
F_7 ( V_95 ) ;
V_14:
F_8 ( V_8 , V_11 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_22 ( V_8 , 1 ) ;
F_8 ( V_8 , 0 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_97 * V_33 = V_8 -> V_18 -> V_17 -> V_33 ;
T_1 V_98 = F_17 ( V_8 -> V_2 -> V_99 . V_98 [ 0 ] ) ;
T_5 V_100 ;
T_1 V_101 ;
T_3 V_11 = 0 ;
switch ( V_98 & 0xf ) {
case V_102 :
F_22 ( V_8 ,
( V_33 -> V_103 - 1 ) | ( ( V_33 -> V_103 - 1 ) << 16 ) ) ;
break;
case V_104 :
V_100 = F_24 ( V_8 -> V_2 -> V_105 . V_106 ) ;
V_101 = V_100 & 0xffff ;
V_8 -> V_18 -> V_17 -> V_107 = F_25 ( V_101 , 1000 ) ;
F_22 ( V_8 , V_8 -> V_18 -> V_17 -> V_107 ) ;
break;
default:
V_11 = V_108 | V_79 ;
break;
}
F_8 ( V_8 , V_11 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_97 * V_33 = V_8 -> V_18 -> V_17 -> V_33 ;
T_1 V_98 = F_17 ( V_8 -> V_2 -> V_99 . V_98 [ 0 ] ) ;
T_3 V_11 = 0 ;
switch ( V_98 & 0xf ) {
#if 0
case NVME_FEAT_ARBITRATION:
break;
case NVME_FEAT_POWER_MGMT:
break;
case NVME_FEAT_TEMP_THRESH:
break;
case NVME_FEAT_ERR_RECOVERY:
break;
case NVME_FEAT_IRQ_COALESCE:
break;
case NVME_FEAT_IRQ_CONFIG:
break;
case NVME_FEAT_WRITE_ATOMIC:
break;
case NVME_FEAT_ASYNC_EVENT:
break;
#endif
case V_109 :
F_22 ( V_8 , 1 ) ;
break;
case V_102 :
F_22 ( V_8 ,
( V_33 -> V_103 - 1 ) | ( ( V_33 -> V_103 - 1 ) << 16 ) ) ;
break;
case V_104 :
F_22 ( V_8 , V_8 -> V_18 -> V_17 -> V_107 * 1000 ) ;
break;
default:
V_11 = V_108 | V_79 ;
break;
}
F_8 ( V_8 , V_11 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 -> V_17 ;
F_28 ( & V_17 -> V_110 ) ;
if ( V_17 -> V_111 >= V_39 ) {
F_29 ( & V_17 -> V_110 ) ;
F_8 ( V_8 , V_112 | V_79 ) ;
return;
}
V_17 -> V_113 [ V_17 -> V_111 ++ ] = V_8 ;
F_29 ( & V_17 -> V_110 ) ;
F_30 ( & V_17 -> V_114 ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 -> V_17 ;
F_32 ( L_3 ,
V_17 -> V_31 , V_17 -> V_107 ) ;
F_33 ( V_115 , & V_17 -> V_116 , V_17 -> V_107 * V_117 ) ;
F_8 ( V_8 , 0 ) ;
}
int F_34 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_74 = NULL ;
if ( F_35 ( ! ( V_8 -> V_18 -> V_17 -> V_118 & V_119 ) ) ) {
F_36 ( L_4 ,
V_2 -> V_99 . V_120 ) ;
return V_121 | V_79 ;
}
if ( F_35 ( ! ( V_8 -> V_18 -> V_17 -> V_122 & V_123 ) ) ) {
F_36 ( L_5 ,
V_2 -> V_99 . V_120 ) ;
return V_121 | V_79 ;
}
switch ( V_2 -> V_99 . V_120 ) {
case V_124 :
V_8 -> V_9 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_15 ) {
case 0x01 :
case 0x02 :
case 0x03 :
V_8 -> V_125 = F_3 ;
return 0 ;
}
break;
case V_126 :
V_8 -> V_9 = 4096 ;
switch ( F_17 ( V_2 -> V_76 . V_127 ) ) {
case 0x00 :
V_8 -> V_125 = F_12 ;
return 0 ;
case 0x01 :
V_8 -> V_125 = F_9 ;
return 0 ;
case 0x02 :
V_8 -> V_125 = F_16 ;
return 0 ;
}
break;
case V_128 :
V_8 -> V_125 = F_21 ;
V_8 -> V_9 = 0 ;
return 0 ;
case V_129 :
V_8 -> V_125 = F_23 ;
V_8 -> V_9 = 0 ;
return 0 ;
case V_130 :
V_8 -> V_125 = F_26 ;
V_8 -> V_9 = 0 ;
return 0 ;
case V_131 :
V_8 -> V_125 = F_27 ;
V_8 -> V_9 = 0 ;
return 0 ;
case V_132 :
V_8 -> V_125 = F_31 ;
V_8 -> V_9 = 0 ;
return 0 ;
}
F_36 ( L_6 , V_2 -> V_99 . V_120 ) ;
return V_133 | V_79 ;
}
