T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
V_3 <<= 16 ;
V_3 += F_2 ( V_2 -> V_4 . V_6 ) ;
V_3 += 1 ;
V_3 *= sizeof( T_1 ) ;
return V_3 ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 ;
struct V_12 * V_13 ;
T_3 V_14 , V_15 , V_16 , V_17 ;
V_11 = V_18 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_4 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 ;
F_5 ( L_1 ,
F_6 ( V_8 -> V_2 -> V_4 . V_21 ) ) ;
goto V_23;
}
V_14 = F_7 ( V_13 -> V_24 -> V_25 , V_26 [ V_27 ] ) ;
V_16 = F_7 ( V_13 -> V_24 -> V_25 , V_28 [ V_27 ] ) ;
V_15 = F_7 ( V_13 -> V_24 -> V_25 , V_26 [ V_29 ] ) ;
V_17 = F_7 ( V_13 -> V_24 -> V_25 , V_28 [ V_29 ] ) ;
F_8 ( V_14 , & V_10 -> V_14 [ 0 ] ) ;
F_8 ( V_16 , & V_10 -> V_16 [ 0 ] ) ;
F_8 ( V_15 , & V_10 -> V_15 [ 0 ] ) ;
F_8 ( V_17 , & V_10 -> V_17 [ 0 ] ) ;
F_9 ( V_13 ) ;
V_23:
return V_11 ;
}
static T_2 F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 ;
T_3 V_14 = 0 , V_15 = 0 ;
T_3 V_16 = 0 , V_17 = 0 ;
struct V_12 * V_13 ;
struct V_30 * V_20 ;
V_11 = V_18 ;
V_20 = V_8 -> V_19 -> V_20 ;
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
V_14 += F_7 ( V_13 -> V_24 -> V_25 , V_26 [ V_27 ] ) ;
V_16 +=
F_7 ( V_13 -> V_24 -> V_25 , V_28 [ V_27 ] ) ;
V_15 += F_7 ( V_13 -> V_24 -> V_25 , V_26 [ V_29 ] ) ;
V_17 +=
F_7 ( V_13 -> V_24 -> V_25 , V_28 [ V_29 ] ) ;
}
F_13 () ;
F_8 ( V_14 , & V_10 -> V_14 [ 0 ] ) ;
F_8 ( V_16 , & V_10 -> V_16 [ 0 ] ) ;
F_8 ( V_15 , & V_10 -> V_15 [ 0 ] ) ;
F_8 ( V_17 , & V_10 -> V_17 [ 0 ] ) ;
return V_11 ;
}
static T_2 F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 ;
F_15 ( V_8 == NULL || V_10 == NULL ) ;
if ( V_8 -> V_2 -> V_4 . V_21 == 0xFFFFFFFF )
V_11 = F_10 ( V_8 , V_10 ) ;
else
V_11 = F_3 ( V_8 , V_10 ) ;
return V_11 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_9 * V_31 ;
T_4 V_32 = F_1 ( V_8 -> V_2 ) ;
void * V_33 ;
T_2 V_11 = 0 ;
V_33 = F_17 ( V_32 , V_34 ) ;
if ( ! V_33 ) {
V_11 = V_35 ;
goto V_23;
}
switch ( V_8 -> V_2 -> V_4 . V_36 ) {
case 0x01 :
break;
case 0x02 :
if ( V_32 != sizeof( * V_31 ) ) {
V_11 = V_35 ;
goto V_37;
}
V_31 = V_33 ;
V_11 = F_14 ( V_8 , V_31 ) ;
if ( V_11 ) {
memset ( V_33 , '\0' , V_32 ) ;
goto V_37;
}
break;
case 0x03 :
break;
default:
F_18 () ;
}
V_11 = F_19 ( V_8 , 0 , V_33 , V_32 ) ;
V_37:
F_20 ( V_33 ) ;
V_23:
F_21 ( V_8 , V_11 ) ;
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_38 * V_39 ;
T_2 V_11 = 0 ;
V_39 = F_17 ( sizeof( * V_39 ) , V_34 ) ;
if ( ! V_39 ) {
V_11 = V_35 ;
goto V_23;
}
V_39 -> V_40 = 0 ;
V_39 -> V_41 = 0 ;
memset ( V_39 -> V_42 , ' ' , sizeof( V_39 -> V_42 ) ) ;
snprintf ( V_39 -> V_42 , sizeof( V_39 -> V_42 ) , L_2 , V_20 -> V_43 ) ;
memset ( V_39 -> V_44 , ' ' , sizeof( V_39 -> V_44 ) ) ;
strncpy ( ( char * ) V_39 -> V_44 , L_3 , sizeof( V_39 -> V_44 ) ) ;
memset ( V_39 -> V_45 , ' ' , sizeof( V_39 -> V_45 ) ) ;
strncpy ( ( char * ) V_39 -> V_45 , V_46 , sizeof( V_39 -> V_45 ) ) ;
V_39 -> V_47 = 6 ;
V_39 -> V_48 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_39 -> V_49 = 0 ;
V_39 -> V_50 = F_23 ( V_20 -> V_50 ) ;
V_39 -> V_51 = F_24 ( V_20 -> V_52 -> V_51 ) ;
V_39 -> V_53 = F_24 ( 1 << 8 ) ;
V_39 -> V_54 = F_24 ( 1 << 0 ) ;
V_39 -> V_55 = 0 ;
V_39 -> V_56 = 3 ;
V_39 -> V_57 = V_58 - 1 ;
V_39 -> V_59 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_39 -> V_60 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_39 -> V_61 = V_62 - 1 ;
V_39 -> V_63 = 0 ;
V_39 -> V_64 = F_23 ( V_65 ) ;
V_39 -> V_66 = ( 0x6 << 4 ) | 0x6 ;
V_39 -> V_67 = ( 0x4 << 4 ) | 0x4 ;
V_39 -> V_68 = F_23 ( V_69 ) ;
V_39 -> V_70 = F_24 ( V_20 -> V_52 -> V_71 ) ;
V_39 -> V_72 = F_23 ( V_73 ) ;
V_39 -> V_74 = V_75 ;
V_39 -> V_76 = 0 ;
V_39 -> V_77 = 0 ;
V_39 -> V_78 = F_24 ( 1 << 0 ) ;
if ( V_20 -> V_79 -> V_80 )
V_39 -> V_78 |= F_24 ( 1 << 2 ) ;
if ( V_20 -> V_79 -> V_81 )
V_39 -> V_78 |= F_24 ( 1 << 20 ) ;
strcpy ( V_39 -> V_82 , V_20 -> V_52 -> V_83 ) ;
V_39 -> V_84 = F_24 ( ( sizeof( struct V_1 ) +
V_20 -> V_79 -> V_81 ) / 16 ) ;
V_39 -> V_85 = F_24 ( sizeof( struct V_86 ) / 16 ) ;
V_39 -> V_87 = V_20 -> V_79 -> V_87 ;
V_39 -> V_88 [ 0 ] . V_89 = F_23 ( 0x9c4 ) ;
V_39 -> V_88 [ 0 ] . V_90 = F_24 ( 0x10 ) ;
V_39 -> V_88 [ 0 ] . V_91 = F_24 ( 0x4 ) ;
V_11 = F_19 ( V_8 , 0 , V_39 , sizeof( * V_39 ) ) ;
F_20 ( V_39 ) ;
V_23:
F_21 ( V_8 , V_11 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_92 * V_39 ;
T_2 V_11 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_93 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_94 ;
goto V_23;
}
V_39 = F_17 ( sizeof( * V_39 ) , V_34 ) ;
if ( ! V_39 ) {
V_11 = V_35 ;
goto V_95;
}
V_39 -> V_96 = V_39 -> V_97 = V_39 -> V_98 =
F_26 ( V_13 -> V_99 >> V_13 -> V_100 ) ;
V_39 -> V_101 = 0 ;
V_39 -> V_102 = 0 ;
V_39 -> V_103 = ( 1 << 0 ) ;
memcpy ( & V_39 -> V_104 , & V_13 -> V_104 , sizeof( V_105 ) ) ;
V_39 -> V_106 [ 0 ] . V_107 = V_13 -> V_100 ;
V_11 = F_19 ( V_8 , 0 , V_39 , sizeof( * V_39 ) ) ;
F_20 ( V_39 ) ;
V_95:
F_9 ( V_13 ) ;
V_23:
F_21 ( V_8 , V_11 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
static const int V_108 = 4096 ;
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_12 * V_13 ;
T_1 V_109 = F_6 ( V_8 -> V_2 -> V_93 . V_21 ) ;
T_5 * V_110 ;
T_2 V_11 = 0 ;
int V_111 = 0 ;
V_110 = F_17 ( V_108 , V_34 ) ;
if ( ! V_110 ) {
V_11 = V_35 ;
goto V_23;
}
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_13 -> V_21 <= V_109 )
continue;
V_110 [ V_111 ++ ] = F_24 ( V_13 -> V_21 ) ;
if ( V_111 == V_108 / sizeof( T_5 ) )
break;
}
F_13 () ;
V_11 = F_19 ( V_8 , 0 , V_110 , V_108 ) ;
F_20 ( V_110 ) ;
V_23:
F_21 ( V_8 , V_11 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
F_29 ( V_8 , 1 ) ;
F_21 ( V_8 , 0 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_112 * V_52 = V_8 -> V_19 -> V_20 -> V_52 ;
T_1 V_113 = F_6 ( V_8 -> V_2 -> V_114 . V_113 [ 0 ] ) ;
T_3 V_115 ;
T_1 V_116 ;
T_2 V_11 = 0 ;
switch ( V_113 & 0xf ) {
case V_117 :
F_29 ( V_8 ,
( V_52 -> V_118 - 1 ) | ( ( V_52 -> V_118 - 1 ) << 16 ) ) ;
break;
case V_119 :
V_115 = F_31 ( V_8 -> V_2 -> V_120 . V_121 ) ;
V_116 = V_115 & 0xffff ;
V_8 -> V_19 -> V_20 -> V_122 = F_32 ( V_116 , 1000 ) ;
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_122 ) ;
break;
default:
V_11 = V_123 | V_94 ;
break;
}
F_21 ( V_8 , V_11 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_112 * V_52 = V_8 -> V_19 -> V_20 -> V_52 ;
T_1 V_113 = F_6 ( V_8 -> V_2 -> V_114 . V_113 [ 0 ] ) ;
T_2 V_11 = 0 ;
switch ( V_113 & 0xf ) {
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
case V_124 :
F_29 ( V_8 , 1 ) ;
break;
case V_117 :
F_29 ( V_8 ,
( V_52 -> V_118 - 1 ) | ( ( V_52 -> V_118 - 1 ) << 16 ) ) ;
break;
case V_119 :
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_122 * 1000 ) ;
break;
default:
V_11 = V_123 | V_94 ;
break;
}
F_21 ( V_8 , V_11 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_35 ( & V_20 -> V_125 ) ;
if ( V_20 -> V_126 >= V_58 ) {
F_36 ( & V_20 -> V_125 ) ;
F_21 ( V_8 , V_127 | V_94 ) ;
return;
}
V_20 -> V_128 [ V_20 -> V_126 ++ ] = V_8 ;
F_36 ( & V_20 -> V_125 ) ;
F_37 ( & V_20 -> V_129 ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_39 ( L_4 ,
V_20 -> V_50 , V_20 -> V_122 ) ;
F_40 ( V_130 , & V_20 -> V_131 , V_20 -> V_122 * V_132 ) ;
F_21 ( V_8 , 0 ) ;
}
int F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_13 = NULL ;
if ( F_42 ( ! ( V_8 -> V_19 -> V_20 -> V_133 & V_134 ) ) ) {
F_5 ( L_5 ,
V_2 -> V_114 . V_135 ) ;
return V_136 | V_94 ;
}
if ( F_42 ( ! ( V_8 -> V_19 -> V_20 -> V_137 & V_138 ) ) ) {
F_5 ( L_6 ,
V_2 -> V_114 . V_135 ) ;
return V_136 | V_94 ;
}
switch ( V_2 -> V_114 . V_135 ) {
case V_139 :
V_8 -> V_32 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_36 ) {
case 0x01 :
case 0x02 :
case 0x03 :
V_8 -> V_140 = F_16 ;
return 0 ;
}
break;
case V_141 :
V_8 -> V_32 = 4096 ;
switch ( F_6 ( V_2 -> V_93 . V_142 ) ) {
case V_143 :
V_8 -> V_140 = F_25 ;
return 0 ;
case V_144 :
V_8 -> V_140 = F_22 ;
return 0 ;
case V_145 :
V_8 -> V_140 = F_27 ;
return 0 ;
}
break;
case V_146 :
V_8 -> V_140 = F_28 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_147 :
V_8 -> V_140 = F_30 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_148 :
V_8 -> V_140 = F_33 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_149 :
V_8 -> V_140 = F_34 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_150 :
V_8 -> V_140 = F_38 ;
V_8 -> V_32 = 0 ;
return 0 ;
}
F_5 ( L_7 , V_2 -> V_114 . V_135 ) ;
return V_151 | V_94 ;
}
