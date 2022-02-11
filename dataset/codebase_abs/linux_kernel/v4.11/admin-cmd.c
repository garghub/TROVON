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
if ( V_8 -> V_2 -> V_4 . V_21 == F_16 ( 0xFFFFFFFF ) )
V_11 = F_10 ( V_8 , V_10 ) ;
else
V_11 = F_3 ( V_8 , V_10 ) ;
return V_11 ;
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_31 ;
T_4 V_32 = F_1 ( V_8 -> V_2 ) ;
void * V_33 ;
T_2 V_11 = 0 ;
V_33 = F_18 ( V_32 , V_34 ) ;
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
F_19 () ;
}
V_11 = F_20 ( V_8 , 0 , V_33 , V_32 ) ;
V_37:
F_21 ( V_33 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_38 * V_39 ;
T_2 V_11 = 0 ;
V_39 = F_18 ( sizeof( * V_39 ) , V_34 ) ;
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
V_39 -> V_50 = F_24 ( V_20 -> V_50 ) ;
V_39 -> V_51 = F_16 ( V_20 -> V_52 -> V_51 ) ;
V_39 -> V_53 = F_16 ( 1 << 8 ) ;
V_39 -> V_54 = F_16 ( 1 << 0 ) ;
V_39 -> V_55 = 0 ;
V_39 -> V_56 = 3 ;
V_39 -> V_57 = V_58 - 1 ;
V_39 -> V_59 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_39 -> V_60 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_39 -> V_61 = V_62 - 1 ;
V_39 -> V_63 = 0 ;
V_39 -> V_64 = F_24 ( V_65 ) ;
V_39 -> V_66 = ( 0x6 << 4 ) | 0x6 ;
V_39 -> V_67 = ( 0x4 << 4 ) | 0x4 ;
V_39 -> V_68 = F_24 ( V_69 ) ;
V_39 -> V_70 = F_16 ( V_20 -> V_52 -> V_71 ) ;
V_39 -> V_72 = F_24 ( V_73 |
V_74 ) ;
V_39 -> V_75 = V_76 ;
V_39 -> V_77 = 0 ;
V_39 -> V_78 = 0 ;
V_39 -> V_79 = F_16 ( 1 << 0 ) ;
if ( V_20 -> V_80 -> V_81 )
V_39 -> V_79 |= F_16 ( 1 << 2 ) ;
if ( V_20 -> V_80 -> V_82 )
V_39 -> V_79 |= F_16 ( 1 << 20 ) ;
strcpy ( V_39 -> V_83 , V_20 -> V_52 -> V_84 ) ;
V_39 -> V_85 = F_16 ( ( sizeof( struct V_1 ) +
V_20 -> V_80 -> V_82 ) / 16 ) ;
V_39 -> V_86 = F_16 ( sizeof( struct V_87 ) / 16 ) ;
V_39 -> V_88 = V_20 -> V_80 -> V_88 ;
V_39 -> V_89 [ 0 ] . V_90 = F_24 ( 0x9c4 ) ;
V_39 -> V_89 [ 0 ] . V_91 = F_16 ( 0x10 ) ;
V_39 -> V_89 [ 0 ] . V_92 = F_16 ( 0x4 ) ;
V_11 = F_20 ( V_8 , 0 , V_39 , sizeof( * V_39 ) ) ;
F_21 ( V_39 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_93 * V_39 ;
T_2 V_11 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_94 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_95 ;
goto V_23;
}
V_39 = F_18 ( sizeof( * V_39 ) , V_34 ) ;
if ( ! V_39 ) {
V_11 = V_35 ;
goto V_96;
}
V_39 -> V_97 = V_39 -> V_98 = V_39 -> V_99 =
F_26 ( V_13 -> V_100 >> V_13 -> V_101 ) ;
V_39 -> V_102 = 0 ;
V_39 -> V_103 = 0 ;
V_39 -> V_104 = ( 1 << 0 ) ;
memcpy ( & V_39 -> V_105 , & V_13 -> V_105 , sizeof( V_106 ) ) ;
V_39 -> V_107 [ 0 ] . V_108 = V_13 -> V_101 ;
V_11 = F_20 ( V_8 , 0 , V_39 , sizeof( * V_39 ) ) ;
F_21 ( V_39 ) ;
V_96:
F_9 ( V_13 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
static const int V_109 = 4096 ;
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_12 * V_13 ;
T_1 V_110 = F_6 ( V_8 -> V_2 -> V_94 . V_21 ) ;
T_5 * V_111 ;
T_2 V_11 = 0 ;
int V_112 = 0 ;
V_111 = F_18 ( V_109 , V_34 ) ;
if ( ! V_111 ) {
V_11 = V_35 ;
goto V_23;
}
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_13 -> V_21 <= V_110 )
continue;
V_111 [ V_112 ++ ] = F_16 ( V_13 -> V_21 ) ;
if ( V_112 == V_109 / sizeof( T_5 ) )
break;
}
F_13 () ;
V_11 = F_20 ( V_8 , 0 , V_111 , V_109 ) ;
F_21 ( V_111 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
F_29 ( V_8 , 1 ) ;
F_22 ( V_8 , 0 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_113 * V_52 = V_8 -> V_19 -> V_20 -> V_52 ;
T_1 V_114 = F_6 ( V_8 -> V_2 -> V_115 . V_114 [ 0 ] ) ;
T_1 V_116 ;
T_2 V_11 = 0 ;
switch ( V_114 & 0xf ) {
case V_117 :
F_29 ( V_8 ,
( V_52 -> V_118 - 1 ) | ( ( V_52 -> V_118 - 1 ) << 16 ) ) ;
break;
case V_119 :
V_116 = F_6 ( V_8 -> V_2 -> V_115 . V_114 [ 1 ] ) ;
V_8 -> V_19 -> V_20 -> V_120 = F_31 ( V_116 , 1000 ) ;
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_120 ) ;
break;
default:
V_11 = V_121 | V_95 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_113 * V_52 = V_8 -> V_19 -> V_20 -> V_52 ;
T_1 V_114 = F_6 ( V_8 -> V_2 -> V_115 . V_114 [ 0 ] ) ;
T_2 V_11 = 0 ;
switch ( V_114 & 0xf ) {
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
case V_122 :
F_29 ( V_8 , 1 ) ;
break;
case V_117 :
F_29 ( V_8 ,
( V_52 -> V_118 - 1 ) | ( ( V_52 -> V_118 - 1 ) << 16 ) ) ;
break;
case V_119 :
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_120 * 1000 ) ;
break;
default:
V_11 = V_121 | V_95 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_34 ( & V_20 -> V_123 ) ;
if ( V_20 -> V_124 >= V_58 ) {
F_35 ( & V_20 -> V_123 ) ;
F_22 ( V_8 , V_125 | V_95 ) ;
return;
}
V_20 -> V_126 [ V_20 -> V_124 ++ ] = V_8 ;
F_35 ( & V_20 -> V_123 ) ;
F_36 ( & V_20 -> V_127 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_38 ( L_4 ,
V_20 -> V_50 , V_20 -> V_120 ) ;
F_39 ( V_128 , & V_20 -> V_129 , V_20 -> V_120 * V_130 ) ;
F_22 ( V_8 , 0 ) ;
}
int F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_13 = NULL ;
if ( F_41 ( ! ( V_8 -> V_19 -> V_20 -> V_131 & V_132 ) ) ) {
F_5 ( L_5 ,
V_2 -> V_115 . V_133 ) ;
return V_134 | V_95 ;
}
if ( F_41 ( ! ( V_8 -> V_19 -> V_20 -> V_135 & V_136 ) ) ) {
F_5 ( L_6 ,
V_2 -> V_115 . V_133 ) ;
return V_134 | V_95 ;
}
switch ( V_2 -> V_115 . V_133 ) {
case V_137 :
V_8 -> V_32 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_36 ) {
case 0x01 :
case 0x02 :
case 0x03 :
V_8 -> V_138 = F_17 ;
return 0 ;
}
break;
case V_139 :
V_8 -> V_32 = 4096 ;
switch ( V_2 -> V_94 . V_140 ) {
case V_141 :
V_8 -> V_138 = F_25 ;
return 0 ;
case V_142 :
V_8 -> V_138 = F_23 ;
return 0 ;
case V_143 :
V_8 -> V_138 = F_27 ;
return 0 ;
}
break;
case V_144 :
V_8 -> V_138 = F_28 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_145 :
V_8 -> V_138 = F_30 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_146 :
V_8 -> V_138 = F_32 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_147 :
V_8 -> V_138 = F_33 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_148 :
V_8 -> V_138 = F_37 ;
V_8 -> V_32 = 0 ;
return 0 ;
}
F_5 ( L_7 , V_2 -> V_115 . V_133 ) ;
return V_149 | V_95 ;
}
