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
case V_37 :
break;
case V_38 :
if ( V_32 != sizeof( * V_31 ) ) {
V_11 = V_35 ;
goto V_39;
}
V_31 = V_33 ;
V_11 = F_14 ( V_8 , V_31 ) ;
if ( V_11 ) {
memset ( V_33 , '\0' , V_32 ) ;
goto V_39;
}
break;
case V_40 :
break;
default:
F_19 () ;
}
V_11 = F_20 ( V_8 , 0 , V_33 , V_32 ) ;
V_39:
F_21 ( V_33 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_41 * V_42 ;
T_2 V_11 = 0 ;
V_42 = F_18 ( sizeof( * V_42 ) , V_34 ) ;
if ( ! V_42 ) {
V_11 = V_35 ;
goto V_23;
}
V_42 -> V_43 = 0 ;
V_42 -> V_44 = 0 ;
memset ( V_42 -> V_45 , ' ' , sizeof( V_42 -> V_45 ) ) ;
snprintf ( V_42 -> V_45 , sizeof( V_42 -> V_45 ) , L_2 , V_20 -> V_46 ) ;
memset ( V_42 -> V_47 , ' ' , sizeof( V_42 -> V_47 ) ) ;
strncpy ( ( char * ) V_42 -> V_47 , L_3 , sizeof( V_42 -> V_47 ) ) ;
memset ( V_42 -> V_48 , ' ' , sizeof( V_42 -> V_48 ) ) ;
strncpy ( ( char * ) V_42 -> V_48 , V_49 , sizeof( V_42 -> V_48 ) ) ;
V_42 -> V_50 = 6 ;
V_42 -> V_51 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_42 -> V_52 = 0 ;
V_42 -> V_53 = F_24 ( V_20 -> V_53 ) ;
V_42 -> V_54 = F_16 ( V_20 -> V_55 -> V_54 ) ;
V_42 -> V_56 = F_16 ( 1 << 8 ) ;
V_42 -> V_57 = F_16 ( 1 << 0 ) ;
V_42 -> V_58 = 0 ;
V_42 -> V_59 = 3 ;
V_42 -> V_60 = V_61 - 1 ;
V_42 -> V_62 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_42 -> V_63 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_42 -> V_64 = V_65 - 1 ;
V_42 -> V_66 = 0 ;
V_42 -> V_67 = F_24 ( V_68 ) ;
V_42 -> V_69 = ( 0x6 << 4 ) | 0x6 ;
V_42 -> V_70 = ( 0x4 << 4 ) | 0x4 ;
V_42 -> V_71 = F_24 ( V_72 ) ;
V_42 -> V_73 = F_16 ( V_20 -> V_55 -> V_74 ) ;
V_42 -> V_75 = F_24 ( V_76 |
V_77 ) ;
V_42 -> V_78 = V_79 ;
V_42 -> V_80 = 0 ;
V_42 -> V_81 = 0 ;
V_42 -> V_82 = F_16 ( 1 << 0 ) ;
if ( V_20 -> V_83 -> V_84 )
V_42 -> V_82 |= F_16 ( 1 << 2 ) ;
if ( V_20 -> V_83 -> V_85 )
V_42 -> V_82 |= F_16 ( 1 << 20 ) ;
strcpy ( V_42 -> V_86 , V_20 -> V_55 -> V_87 ) ;
V_42 -> V_88 = F_16 ( ( sizeof( struct V_1 ) +
V_20 -> V_83 -> V_85 ) / 16 ) ;
V_42 -> V_89 = F_16 ( sizeof( struct V_90 ) / 16 ) ;
V_42 -> V_91 = V_20 -> V_83 -> V_91 ;
V_42 -> V_92 [ 0 ] . V_93 = F_24 ( 0x9c4 ) ;
V_42 -> V_92 [ 0 ] . V_94 = F_16 ( 0x10 ) ;
V_42 -> V_92 [ 0 ] . V_95 = F_16 ( 0x4 ) ;
V_11 = F_20 ( V_8 , 0 , V_42 , sizeof( * V_42 ) ) ;
F_21 ( V_42 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_96 * V_42 ;
T_2 V_11 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_97 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_98 ;
goto V_23;
}
V_42 = F_18 ( sizeof( * V_42 ) , V_34 ) ;
if ( ! V_42 ) {
V_11 = V_35 ;
goto V_99;
}
V_42 -> V_100 = V_42 -> V_101 = V_42 -> V_102 =
F_26 ( V_13 -> V_103 >> V_13 -> V_104 ) ;
V_42 -> V_105 = 0 ;
V_42 -> V_106 = 0 ;
V_42 -> V_107 = ( 1 << 0 ) ;
memcpy ( & V_42 -> V_108 , & V_13 -> V_108 , sizeof( V_109 ) ) ;
V_42 -> V_110 [ 0 ] . V_111 = V_13 -> V_104 ;
V_11 = F_20 ( V_8 , 0 , V_42 , sizeof( * V_42 ) ) ;
F_21 ( V_42 ) ;
V_99:
F_9 ( V_13 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
static const int V_112 = 4096 ;
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_12 * V_13 ;
T_1 V_113 = F_6 ( V_8 -> V_2 -> V_97 . V_21 ) ;
T_5 * V_114 ;
T_2 V_11 = 0 ;
int V_115 = 0 ;
V_114 = F_18 ( V_112 , V_34 ) ;
if ( ! V_114 ) {
V_11 = V_35 ;
goto V_23;
}
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_13 -> V_21 <= V_113 )
continue;
V_114 [ V_115 ++ ] = F_16 ( V_13 -> V_21 ) ;
if ( V_115 == V_112 / sizeof( T_5 ) )
break;
}
F_13 () ;
V_11 = F_20 ( V_8 , 0 , V_114 , V_112 ) ;
F_21 ( V_114 ) ;
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
struct V_116 * V_55 = V_8 -> V_19 -> V_20 -> V_55 ;
T_1 V_117 = F_6 ( V_8 -> V_2 -> V_118 . V_117 [ 0 ] ) ;
T_1 V_119 ;
T_2 V_11 = 0 ;
switch ( V_117 & 0xf ) {
case V_120 :
F_29 ( V_8 ,
( V_55 -> V_121 - 1 ) | ( ( V_55 -> V_121 - 1 ) << 16 ) ) ;
break;
case V_122 :
V_119 = F_6 ( V_8 -> V_2 -> V_118 . V_117 [ 1 ] ) ;
V_8 -> V_19 -> V_20 -> V_123 = F_31 ( V_119 , 1000 ) ;
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_123 ) ;
break;
default:
V_11 = V_124 | V_98 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_116 * V_55 = V_8 -> V_19 -> V_20 -> V_55 ;
T_1 V_117 = F_6 ( V_8 -> V_2 -> V_118 . V_117 [ 0 ] ) ;
T_2 V_11 = 0 ;
switch ( V_117 & 0xf ) {
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
case V_125 :
F_29 ( V_8 , 1 ) ;
break;
case V_120 :
F_29 ( V_8 ,
( V_55 -> V_121 - 1 ) | ( ( V_55 -> V_121 - 1 ) << 16 ) ) ;
break;
case V_122 :
F_29 ( V_8 , V_8 -> V_19 -> V_20 -> V_123 * 1000 ) ;
break;
default:
V_11 = V_124 | V_98 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_34 ( & V_20 -> V_126 ) ;
if ( V_20 -> V_127 >= V_61 ) {
F_35 ( & V_20 -> V_126 ) ;
F_22 ( V_8 , V_128 | V_98 ) ;
return;
}
V_20 -> V_129 [ V_20 -> V_127 ++ ] = V_8 ;
F_35 ( & V_20 -> V_126 ) ;
F_36 ( & V_20 -> V_130 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_38 ( L_4 ,
V_20 -> V_53 , V_20 -> V_123 ) ;
F_39 ( V_131 , & V_20 -> V_132 , V_20 -> V_123 * V_133 ) ;
F_22 ( V_8 , 0 ) ;
}
T_2 F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_2 V_134 ;
V_8 -> V_13 = NULL ;
V_134 = F_41 ( V_8 , V_2 ) ;
if ( F_42 ( V_134 ) )
return V_134 ;
switch ( V_2 -> V_118 . V_135 ) {
case V_136 :
V_8 -> V_32 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_36 ) {
case V_37 :
case V_38 :
case V_40 :
V_8 -> V_137 = F_17 ;
return 0 ;
}
break;
case V_138 :
V_8 -> V_32 = 4096 ;
switch ( V_2 -> V_97 . V_139 ) {
case V_140 :
V_8 -> V_137 = F_25 ;
return 0 ;
case V_141 :
V_8 -> V_137 = F_23 ;
return 0 ;
case V_142 :
V_8 -> V_137 = F_27 ;
return 0 ;
}
break;
case V_143 :
V_8 -> V_137 = F_28 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_144 :
V_8 -> V_137 = F_30 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_145 :
V_8 -> V_137 = F_32 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_146 :
V_8 -> V_137 = F_33 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_147 :
V_8 -> V_137 = F_37 ;
V_8 -> V_32 = 0 ;
return 0 ;
}
F_5 ( L_5 , V_2 -> V_118 . V_135 ,
V_8 -> V_19 -> V_148 ) ;
return V_149 | V_98 ;
}
