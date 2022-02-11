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
static void F_23 ( char * V_41 , int V_42 , const char * V_43 , int V_44 )
{
int V_3 = F_24 ( V_44 , V_42 ) ;
memcpy ( V_41 , V_43 , V_3 ) ;
if ( V_42 > V_3 )
memset ( V_41 + V_3 , ' ' , V_42 - V_3 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_45 * V_46 ;
T_2 V_11 = 0 ;
const char V_47 [] = L_2 ;
V_46 = F_18 ( sizeof( * V_46 ) , V_34 ) ;
if ( ! V_46 ) {
V_11 = V_35 ;
goto V_23;
}
V_46 -> V_48 = 0 ;
V_46 -> V_49 = 0 ;
F_26 ( V_46 -> V_50 , & V_20 -> V_51 -> V_52 ,
F_24 ( sizeof( V_20 -> V_51 -> V_52 ) , sizeof( V_46 -> V_50 ) / 2 ) ) ;
F_23 ( V_46 -> V_53 , sizeof( V_46 -> V_53 ) , V_47 , sizeof( V_47 ) - 1 ) ;
F_23 ( V_46 -> V_54 , sizeof( V_46 -> V_54 ) , V_55 , strlen ( V_55 ) ) ;
V_46 -> V_56 = 6 ;
V_46 -> V_57 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_46 -> V_58 = 0 ;
V_46 -> V_59 = F_27 ( V_20 -> V_59 ) ;
V_46 -> V_60 = F_16 ( V_20 -> V_51 -> V_60 ) ;
V_46 -> V_61 = F_16 ( 1 << 8 ) ;
V_46 -> V_62 = F_16 ( 1 << 0 ) ;
V_46 -> V_63 = 0 ;
V_46 -> V_64 = 3 ;
V_46 -> V_65 = V_66 - 1 ;
V_46 -> V_67 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_46 -> V_68 = ( 1 << 0 ) | ( 1 << 2 ) ;
V_46 -> V_69 = V_70 - 1 ;
V_46 -> V_71 = 0 ;
V_46 -> V_72 = F_27 ( V_73 ) ;
V_46 -> V_74 = ( 0x6 << 4 ) | 0x6 ;
V_46 -> V_75 = ( 0x4 << 4 ) | 0x4 ;
V_46 -> V_76 = F_27 ( V_77 ) ;
V_46 -> V_78 = F_16 ( V_20 -> V_51 -> V_79 ) ;
V_46 -> V_80 = F_27 ( V_81 |
V_82 ) ;
V_46 -> V_83 = V_84 ;
V_46 -> V_85 = 0 ;
V_46 -> V_86 = 0 ;
V_46 -> V_87 = F_16 ( 1 << 0 ) ;
if ( V_20 -> V_88 -> V_89 )
V_46 -> V_87 |= F_16 ( 1 << 2 ) ;
if ( V_20 -> V_88 -> V_90 )
V_46 -> V_87 |= F_16 ( 1 << 20 ) ;
strcpy ( V_46 -> V_91 , V_20 -> V_51 -> V_92 ) ;
V_46 -> V_93 = F_16 ( ( sizeof( struct V_1 ) +
V_20 -> V_88 -> V_90 ) / 16 ) ;
V_46 -> V_94 = F_16 ( sizeof( struct V_95 ) / 16 ) ;
V_46 -> V_96 = V_20 -> V_88 -> V_96 ;
V_46 -> V_97 [ 0 ] . V_98 = F_27 ( 0x9c4 ) ;
V_46 -> V_97 [ 0 ] . V_99 = F_16 ( 0x10 ) ;
V_46 -> V_97 [ 0 ] . V_100 = F_16 ( 0x4 ) ;
V_11 = F_20 ( V_8 , 0 , V_46 , sizeof( * V_46 ) ) ;
F_21 ( V_46 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_101 * V_46 ;
T_2 V_11 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_102 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_103 ;
goto V_23;
}
V_46 = F_18 ( sizeof( * V_46 ) , V_34 ) ;
if ( ! V_46 ) {
V_11 = V_35 ;
goto V_104;
}
V_46 -> V_105 = V_46 -> V_106 = V_46 -> V_107 =
F_29 ( V_13 -> V_108 >> V_13 -> V_109 ) ;
V_46 -> V_110 = 0 ;
V_46 -> V_111 = 0 ;
V_46 -> V_112 = ( 1 << 0 ) ;
memcpy ( & V_46 -> V_113 , & V_13 -> V_113 , sizeof( V_114 ) ) ;
V_46 -> V_115 [ 0 ] . V_116 = V_13 -> V_109 ;
V_11 = F_20 ( V_8 , 0 , V_46 , sizeof( * V_46 ) ) ;
F_21 ( V_46 ) ;
V_104:
F_9 ( V_13 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
static const int V_117 = V_118 ;
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
struct V_12 * V_13 ;
T_1 V_119 = F_6 ( V_8 -> V_2 -> V_102 . V_21 ) ;
T_5 * V_120 ;
T_2 V_11 = 0 ;
int V_121 = 0 ;
V_120 = F_18 ( V_117 , V_34 ) ;
if ( ! V_120 ) {
V_11 = V_35 ;
goto V_23;
}
F_11 () ;
F_12 (ns, &ctrl->subsys->namespaces, dev_link) {
if ( V_13 -> V_21 <= V_119 )
continue;
V_120 [ V_121 ++ ] = F_16 ( V_13 -> V_21 ) ;
if ( V_121 == V_117 / sizeof( T_5 ) )
break;
}
F_13 () ;
V_11 = F_20 ( V_8 , 0 , V_120 , V_117 ) ;
F_21 ( V_120 ) ;
V_23:
F_22 ( V_8 , V_11 ) ;
}
static T_2 F_31 ( struct V_7 * V_8 , T_6 type , T_6 V_3 ,
void * V_46 , T_7 * V_122 )
{
struct V_123 V_124 = {
. V_125 = type ,
. V_126 = V_3 ,
} ;
T_2 V_11 ;
V_11 = F_20 ( V_8 , * V_122 , & V_124 , sizeof( V_124 ) ) ;
if ( V_11 )
return V_11 ;
* V_122 += sizeof( V_124 ) ;
V_11 = F_20 ( V_8 , * V_122 , V_46 , V_3 ) ;
if ( V_11 )
return V_11 ;
* V_122 += V_3 ;
return 0 ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
T_2 V_11 = 0 ;
T_7 V_122 = 0 ;
V_13 = F_4 ( V_8 -> V_19 -> V_20 , V_8 -> V_2 -> V_102 . V_21 ) ;
if ( ! V_13 ) {
V_11 = V_22 | V_103 ;
goto V_23;
}
if ( F_33 ( & V_13 -> V_127 , 0 , sizeof( V_13 -> V_127 ) ) ) {
V_11 = F_31 ( V_8 , V_128 ,
V_129 ,
& V_13 -> V_127 , & V_122 ) ;
if ( V_11 )
goto V_104;
}
if ( F_33 ( V_13 -> V_113 , 0 , sizeof( V_13 -> V_113 ) ) ) {
V_11 = F_31 ( V_8 , V_130 ,
V_131 ,
& V_13 -> V_113 , & V_122 ) ;
if ( V_11 )
goto V_104;
}
if ( F_34 ( V_8 -> V_132 , V_8 -> V_133 , V_118 - V_122 ,
V_122 ) != V_118 - V_122 )
V_11 = V_35 | V_103 ;
V_104:
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
struct V_134 * V_51 = V_8 -> V_19 -> V_20 -> V_51 ;
T_1 V_135 = F_6 ( V_8 -> V_2 -> V_136 . V_135 [ 0 ] ) ;
T_1 V_137 ;
T_2 V_11 = 0 ;
switch ( V_135 & 0xf ) {
case V_138 :
F_36 ( V_8 ,
( V_51 -> V_139 - 1 ) | ( ( V_51 -> V_139 - 1 ) << 16 ) ) ;
break;
case V_140 :
V_137 = F_6 ( V_8 -> V_2 -> V_136 . V_135 [ 1 ] ) ;
V_8 -> V_19 -> V_20 -> V_141 = F_38 ( V_137 , 1000 ) ;
F_36 ( V_8 , V_8 -> V_19 -> V_20 -> V_141 ) ;
break;
default:
V_11 = V_142 | V_103 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_134 * V_51 = V_8 -> V_19 -> V_20 -> V_51 ;
T_1 V_135 = F_6 ( V_8 -> V_2 -> V_136 . V_135 [ 0 ] ) ;
T_2 V_11 = 0 ;
switch ( V_135 & 0xf ) {
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
case V_143 :
F_36 ( V_8 , 1 ) ;
break;
case V_138 :
F_36 ( V_8 ,
( V_51 -> V_139 - 1 ) | ( ( V_51 -> V_139 - 1 ) << 16 ) ) ;
break;
case V_140 :
F_36 ( V_8 , V_8 -> V_19 -> V_20 -> V_141 * 1000 ) ;
break;
default:
V_11 = V_142 | V_103 ;
break;
}
F_22 ( V_8 , V_11 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_30 * V_20 = V_8 -> V_19 -> V_20 ;
F_41 ( & V_20 -> V_144 ) ;
if ( V_20 -> V_145 >= V_66 ) {
F_42 ( & V_20 -> V_144 ) ;
F_22 ( V_8 , V_146 | V_103 ) ;
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
V_20 -> V_59 , V_20 -> V_141 ) ;
F_46 ( V_149 , & V_20 -> V_150 , V_20 -> V_141 * V_151 ) ;
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
switch ( V_2 -> V_136 . V_153 ) {
case V_154 :
V_8 -> V_32 = F_1 ( V_2 ) ;
switch ( V_2 -> V_4 . V_36 ) {
case V_37 :
case V_38 :
case V_40 :
V_8 -> V_155 = F_17 ;
return 0 ;
}
break;
case V_156 :
V_8 -> V_32 = V_118 ;
switch ( V_2 -> V_102 . V_157 ) {
case V_158 :
V_8 -> V_155 = F_28 ;
return 0 ;
case V_159 :
V_8 -> V_155 = F_25 ;
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
V_8 -> V_32 = 0 ;
return 0 ;
case V_163 :
V_8 -> V_155 = F_37 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_164 :
V_8 -> V_155 = F_39 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_165 :
V_8 -> V_155 = F_40 ;
V_8 -> V_32 = 0 ;
return 0 ;
case V_166 :
V_8 -> V_155 = F_44 ;
V_8 -> V_32 = 0 ;
return 0 ;
}
F_5 ( L_4 , V_2 -> V_136 . V_153 ,
V_8 -> V_19 -> V_167 ) ;
return V_168 | V_103 ;
}
