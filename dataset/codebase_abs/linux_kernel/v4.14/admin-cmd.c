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
if ( V_8 -> V_2 -> V_4 . V_21 == F_16 ( V_31 ) )
V_11 = F_10 ( V_8 , V_10 ) ;
else
V_11 = F_3 ( V_8 , V_10 ) ;
return V_11 ;
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_32 ;
T_4 V_33 = F_1 ( V_8 -> V_2 ) ;
void * V_34 ;
T_2 V_11 = 0 ;
V_34 = F_18 ( V_33 , V_35 ) ;
if ( ! V_34 ) {
V_11 = V_36 ;
goto V_23;
}
switch ( V_8 -> V_2 -> V_4 . V_37 ) {
case V_38 :
break;
case V_39 :
if ( V_33 != sizeof( * V_32 ) ) {
V_11 = V_36 ;
goto V_40;
}
V_32 = V_34 ;
V_11 = F_14 ( V_8 , V_32 ) ;
if ( V_11 ) {
memset ( V_34 , '\0' , V_33 ) ;
goto V_40;
}
break;
case V_41 :
break;
default:
F_19 () ;
}
V_11 = F_20 ( V_8 , 0 , V_34 , V_33 ) ;
V_40:
F_21 ( V_34 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_42 * V_43 ;
T_2 V_11 = 0 ;
const char V_44 [] = L_2 ;
V_43 = F_18 ( sizeof( * V_43 ) , V_35 ) ;
if ( ! V_43 ) {
V_11 = V_36 ;
goto V_23;
}
V_43 -> V_45 = 0 ;
V_43 -> V_46 = 0 ;
F_24 ( V_43 -> V_47 , & V_20 -> V_48 -> V_49 ,
F_25 ( sizeof( V_20 -> V_48 -> V_49 ) , sizeof( V_43 -> V_47 ) / 2 ) ) ;
F_26 ( V_43 -> V_50 , sizeof( V_43 -> V_50 ) , V_44 , sizeof( V_44 ) - 1 , ' ' ) ;
F_26 ( V_43 -> V_51 , sizeof( V_43 -> V_51 ) ,
V_52 , strlen ( V_52 ) , ' ' ) ;
V_43 -> V_53 = 6 ;
V_43 -> V_54 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_43 -> V_55 = 0 ;
V_43 -> V_56 = F_27 ( V_20 -> V_56 ) ;
V_43 -> V_57 = F_16 ( V_20 -> V_48 -> V_57 ) ;
V_43 -> V_58 = F_16 ( 1 << 8 ) ;
V_43 -> V_59 = F_16 ( 1 << 0 ) ;
V_43 -> V_60 = 0 ;
V_43 -> V_61 = 3 ;
V_43 -> V_62 = V_63 - 1 ;
V_43 -> V_64 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_43 -> V_65 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_43 -> V_66 = V_67 - 1 ;
V_43 -> V_68 = 0 ;
V_43 -> V_69 = F_27 ( V_70 ) ;
V_43 -> V_71 = ( 0x6 << 4 ) | 0x6 ;
V_43 -> V_72 = ( 0x4 << 4 ) | 0x4 ;
V_43 -> V_73 = F_27 ( V_74 ) ;
V_43 -> V_75 = F_16 ( V_20 -> V_48 -> V_76 ) ;
V_43 -> V_77 = F_27 ( V_78 |
V_79 ) ;
V_43 -> V_80 = V_81 ;
V_43 -> V_82 = 0 ;
V_43 -> V_83 = 0 ;
V_43 -> V_84 = F_16 ( 1 << 0 ) ;
if ( V_20 -> V_85 -> V_86 )
V_43 -> V_84 |= F_16 ( 1 << 2 ) ;
if ( V_20 -> V_85 -> V_87 )
V_43 -> V_84 |= F_16 ( 1 << 20 ) ;
strcpy ( V_43 -> V_88 , V_20 -> V_48 -> V_89 ) ;
V_43 -> V_90 = F_16 ( ( sizeof( struct V_1 ) +
V_20 -> V_85 -> V_87 ) / 16 ) ;
V_43 -> V_91 = F_16 ( sizeof( struct V_92 ) / 16 ) ;
V_43 -> V_93 = V_20 -> V_85 -> V_93 ;
V_43 -> V_94 [ 0 ] . V_95 = F_27 ( 0x9c4 ) ;
V_43 -> V_94 [ 0 ] . V_96 = F_16 ( 0x10 ) ;
V_43 -> V_94 [ 0 ] . V_97 = F_16 ( 0x4 ) ;
V_11 = F_20 ( V_8 , 0 , V_43 , sizeof( * V_43 ) ) ;
F_21 ( V_43 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_98 * V_43 ;
T_2 V_11 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_99 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_100 ;
goto V_23;
}
V_43 = F_18 ( sizeof( * V_43 ) , V_35 ) ;
if ( ! V_43 ) {
V_11 = V_36 ;
goto V_101;
}
V_43 -> V_102 = V_43 -> V_103 = V_43 -> V_104 =
F_29 ( V_13 -> V_105 >> V_13 -> V_106 ) ;
V_43 -> V_107 = 0 ;
V_43 -> V_108 = 0 ;
V_43 -> V_109 = ( 1 << 0 ) ;
memcpy ( & V_43 -> V_110 , & V_13 -> V_110 , sizeof( V_111 ) ) ;
V_43 -> V_112 [ 0 ] . V_113 = V_13 -> V_106 ;
V_11 = F_20 ( V_8 , 0 , V_43 , sizeof( * V_43 ) ) ;
F_21 ( V_43 ) ;
V_101:
F_9 ( V_13 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
static const int V_114 = V_115 ;
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_12 * V_13 ;
T_1 V_116 = F_6 ( V_8 -> V_2 -> V_99 . V_21 ) ;
T_5 * V_117 ;
T_2 V_11 = 0 ;
int V_118 = 0 ;
V_117 = F_18 ( V_114 , V_35 ) ;
if ( ! V_117 ) {
V_11 = V_36 ;
goto V_23;
}
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_13 -> V_21 <= V_116 )
continue;
V_117 [ V_118 ++ ] = F_16 ( V_13 -> V_21 ) ;
if ( V_118 == V_114 / sizeof( T_5 ) )
break;
}
F_13 () ;
V_11 = F_20 ( V_8 , 0 , V_117 , V_114 ) ;
F_21 ( V_117 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static T_2 F_31 ( struct V_7 * V_8 , T_6 type , T_6 V_3 ,
void * V_43 , T_7 * V_119 )
{
struct V_120 V_121 = {
. V_122 = type ,
. V_123 = V_3 ,
} ;
T_2 V_11 ;
V_11 = F_20 ( V_8 , * V_119 , & V_121 , sizeof( V_121 ) ) ;
if ( V_11 )
return V_11 ;
* V_119 += sizeof( V_121 ) ;
V_11 = F_20 ( V_8 , * V_119 , V_43 , V_3 ) ;
if ( V_11 )
return V_11 ;
* V_119 += V_3 ;
return 0 ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
T_2 V_11 = 0 ;
T_7 V_119 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_99 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_100 ;
goto V_23;
}
if ( F_33 ( & V_13 -> V_124 , 0 , sizeof( V_13 -> V_124 ) ) ) {
V_11 = F_31 ( V_8 , V_125 ,
V_126 ,
& V_13 -> V_124 , & V_119 ) ;
if ( V_11 )
goto V_101;
}
if ( F_33 ( V_13 -> V_110 , 0 , sizeof( V_13 -> V_110 ) ) ) {
V_11 = F_31 ( V_8 , V_127 ,
V_128 ,
& V_13 -> V_110 , & V_119 ) ;
if ( V_11 )
goto V_101;
}
if ( F_34 ( V_8 -> V_129 , V_8 -> V_130 , V_115 - V_119 ,
V_119 ) != V_115 - V_119 )
V_11 = V_36 | V_100 ;
V_101:
F_9 ( V_13 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
F_36 ( V_8 , 1 ) ;
F_22 ( V_8 , 0 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_131 * V_48 = V_8 -> V_19 -> V_20 -> V_48 ;
T_1 V_132 = F_6 ( V_8 -> V_2 -> V_133 . V_132 [ 0 ] ) ;
T_1 V_134 ;
T_2 V_11 = 0 ;
switch ( V_132 & 0xff ) {
case V_135 :
F_36 ( V_8 ,
( V_48 -> V_136 - 1 ) | ( ( V_48 -> V_136 - 1 ) << 16 ) ) ;
break;
case V_137 :
V_134 = F_6 ( V_8 -> V_2 -> V_133 . V_132 [ 1 ] ) ;
V_8 -> V_19 -> V_20 -> V_138 = F_38 ( V_134 , 1000 ) ;
F_36 ( V_8 , V_8 -> V_19 -> V_20 -> V_138 ) ;
break;
case V_139 :
V_11 = V_140 | V_100 ;
break;
default:
V_11 = V_141 | V_100 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_131 * V_48 = V_8 -> V_19 -> V_20 -> V_48 ;
T_1 V_132 = F_6 ( V_8 -> V_2 -> V_133 . V_132 [ 0 ] ) ;
T_2 V_11 = 0 ;
switch ( V_132 & 0xff ) {
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
case V_142 :
F_36 ( V_8 , 1 ) ;
break;
case V_135 :
F_36 ( V_8 ,
( V_48 -> V_136 - 1 ) | ( ( V_48 -> V_136 - 1 ) << 16 ) ) ;
break;
case V_137 :
F_36 ( V_8 , V_8 -> V_19 -> V_20 -> V_138 * 1000 ) ;
break;
case V_139 :
if ( ! ( V_8 -> V_2 -> V_133 . V_132 [ 1 ] & F_16 ( 1 << 0 ) ) ) {
V_11 = V_141 | V_100 ;
break;
}
V_11 = F_20 ( V_8 , 0 , & V_8 -> V_19 -> V_20 -> V_143 ,
sizeof( V_8 -> V_19 -> V_20 -> V_143 ) ) ;
break;
default:
V_11 = V_141 | V_100 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_41 ( & V_20 -> V_144 ) ;
if ( V_20 -> V_145 >= V_63 ) {
F_42 ( & V_20 -> V_144 ) ;
F_22 ( V_8 , V_146 | V_100 ) ;
return;
}
V_20 -> V_147 [ V_20 -> V_145 ++ ] = V_8 ;
F_42 ( & V_20 -> V_144 ) ;
F_43 ( & V_20 -> V_148 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_45 ( L_3 ,
V_20 -> V_56 , V_20 -> V_138 ) ;
F_46 ( V_149 , & V_20 -> V_150 , V_20 -> V_138 * V_151 ) ;
F_22 ( V_8 , 0 ) ;
}
T_2 F_47 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_2 V_152 ;
V_8 -> V_13 = NULL ;
V_152 = F_48 ( V_8 , V_2 ) ;
if ( F_49 ( V_152 ) )
return V_152 ;
switch ( V_2 -> V_133 . V_153 ) {
case V_154 :
V_8 -> V_33 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_37 ) {
case V_38 :
case V_39 :
case V_41 :
V_8 -> V_155 = F_17 ;
return 0 ;
}
break;
case V_156 :
V_8 -> V_33 = V_115 ;
switch ( V_2 -> V_99 . V_157 ) {
case V_158 :
V_8 -> V_155 = F_28 ;
return 0 ;
case V_159 :
V_8 -> V_155 = F_23 ;
return 0 ;
case V_160 :
V_8 -> V_155 = F_30 ;
return 0 ;
case V_161 :
V_8 -> V_155 = F_32 ;
return 0 ;
}
break;
case V_162 :
V_8 -> V_155 = F_35 ;
V_8 -> V_33 = 0 ;
return 0 ;
case V_163 :
V_8 -> V_155 = F_37 ;
V_8 -> V_33 = 0 ;
return 0 ;
case V_164 :
V_8 -> V_155 = F_39 ;
V_8 -> V_33 = 0 ;
return 0 ;
case V_165 :
V_8 -> V_155 = F_40 ;
V_8 -> V_33 = 0 ;
return 0 ;
case V_166 :
V_8 -> V_155 = F_44 ;
V_8 -> V_33 = 0 ;
return 0 ;
}
F_5 ( L_4 , V_2 -> V_133 . V_153 ,
V_8 -> V_19 -> V_167 ) ;
return V_168 | V_100 ;
}
