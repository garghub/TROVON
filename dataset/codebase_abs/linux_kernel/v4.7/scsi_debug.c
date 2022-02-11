static inline bool F_1 ( void )
{
return 0 == V_1 &&
( V_2 || V_3 || V_4 ) ;
}
static void * F_2 ( unsigned long long V_5 )
{
V_5 = F_3 ( V_5 , V_6 ) ;
return V_7 + V_5 * V_8 ;
}
static struct V_9 * F_4 ( T_1 V_10 )
{
V_10 = F_5 ( V_10 , V_6 ) ;
return V_11 + V_10 ;
}
static void F_6 ( void )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_7 ( & V_16 ) ;
F_8 (sdbg_host, &sdebug_host_list, host_list) {
V_15 = V_13 -> V_17 ;
if ( ( V_15 -> V_18 >= 0 ) &&
( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 + 1 ;
}
F_9 ( & V_16 ) ;
}
static void F_10 ( struct V_23 * V_24 ,
enum V_25 V_26 ,
int V_27 , int V_28 )
{
unsigned char * V_29 ;
T_2 V_30 [ 4 ] ;
int V_31 , V_32 ;
V_29 = V_24 -> V_33 ;
if ( ! V_29 ) {
F_11 ( V_34 , V_24 -> V_35 ,
L_1 , V_36 ) ;
return;
}
V_32 = V_26 ? V_37 : V_38 ;
memset ( V_29 , 0 , V_39 ) ;
F_12 ( V_40 , V_29 , V_41 , V_32 , 0 ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
V_30 [ 0 ] = 0x80 ;
if ( V_26 )
V_30 [ 0 ] |= 0x40 ;
if ( V_28 >= 0 ) {
V_30 [ 0 ] |= 0x8 ;
V_30 [ 0 ] |= 0x7 & V_28 ;
}
F_13 ( V_27 , V_30 + 1 ) ;
if ( V_40 ) {
V_31 = V_29 [ 7 ] + 8 ;
V_29 [ 7 ] = V_31 ;
V_29 [ V_31 ] = 0x2 ;
V_29 [ V_31 + 1 ] = 0x6 ;
memcpy ( V_29 + V_31 + 4 , V_30 , 3 ) ;
} else
memcpy ( V_29 + 15 , V_30 , 3 ) ;
if ( V_42 )
F_11 ( V_43 , V_24 -> V_35 , L_2
L_3 ,
V_44 , V_32 , V_26 ? 'C' : 'D' , V_27 , V_28 ) ;
}
static void F_14 ( struct V_23 * V_24 , int V_45 , int V_32 , int V_46 )
{
unsigned char * V_29 ;
V_29 = V_24 -> V_33 ;
if ( ! V_29 ) {
F_11 ( V_34 , V_24 -> V_35 ,
L_1 , V_36 ) ;
return;
}
memset ( V_29 , 0 , V_39 ) ;
F_12 ( V_40 , V_29 , V_45 , V_32 , V_46 ) ;
if ( V_42 )
F_11 ( V_43 , V_24 -> V_35 ,
L_4 ,
V_44 , V_45 , V_32 , V_46 ) ;
}
static void F_15 ( struct V_23 * V_24 )
{
F_14 ( V_24 , V_41 , V_47 , 0 ) ;
}
static int F_16 ( struct V_48 * V_49 , int V_50 , void T_3 * V_51 )
{
if ( V_42 ) {
if ( 0x1261 == V_50 )
F_11 ( V_43 , V_49 ,
L_5 , V_36 ) ;
else if ( 0x5331 == V_50 )
F_11 ( V_43 , V_49 ,
L_6 ,
V_36 ) ;
else
F_11 ( V_43 , V_49 , L_7 ,
V_36 , V_50 ) ;
}
return - V_52 ;
}
static void F_17 ( struct V_53 * V_54 )
{
struct V_12 * V_55 ;
struct V_53 * V_56 ;
F_7 ( & V_16 ) ;
F_8 (sdhp, &sdebug_host_list, host_list) {
F_8 (dp, &sdhp->dev_info_list, dev_list) {
if ( ( V_54 -> V_13 == V_56 -> V_13 ) &&
( V_54 -> V_57 == V_56 -> V_57 ) )
F_18 ( V_58 , V_56 -> V_59 ) ;
}
}
F_9 ( & V_16 ) ;
}
static int F_19 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
int V_60 ;
V_60 = F_20 ( V_54 -> V_59 , V_61 ) ;
if ( V_60 != V_61 ) {
const char * V_62 = NULL ;
switch ( V_60 ) {
case V_63 :
F_14 ( V_24 , V_64 , V_65 ,
V_66 ) ;
if ( V_42 )
V_62 = L_8 ;
break;
case V_67 :
F_14 ( V_24 , V_64 , V_65 ,
V_68 ) ;
if ( V_42 )
V_62 = L_9 ;
break;
case V_69 :
F_14 ( V_24 , V_64 , V_70 ,
V_71 ) ;
if ( V_42 )
V_62 = L_10 ;
break;
case V_72 :
F_14 ( V_24 , V_64 , V_70 ,
V_73 ) ;
if ( V_42 )
V_62 = L_11 ;
break;
case V_74 :
F_14 ( V_24 , V_64 ,
V_75 ,
V_76 ) ;
if ( V_42 )
V_62 = L_12 ;
break;
case V_77 :
F_14 ( V_24 , V_64 ,
V_75 ,
V_78 ) ;
if ( V_42 )
V_62 = L_13 ;
break;
case V_58 :
if ( V_79 >= 6 )
F_17 ( V_54 ) ;
F_14 ( V_24 , V_64 ,
V_75 ,
V_80 ) ;
if ( V_42 )
V_62 = L_14 ;
break;
default:
F_21 ( L_15 , V_60 ) ;
if ( V_42 )
V_62 = L_16 ;
break;
}
F_18 ( V_60 , V_54 -> V_59 ) ;
if ( V_42 )
F_11 ( V_43 , V_24 -> V_35 ,
L_17 ,
V_44 , V_62 ) ;
return V_81 ;
}
return 0 ;
}
static int F_22 ( struct V_23 * V_24 , unsigned char * V_82 ,
int V_83 )
{
int V_84 ;
struct V_85 * V_86 = F_23 ( V_24 ) ;
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_24 ( V_24 ) || V_24 -> V_88 == V_89 ) )
return V_90 << 16 ;
V_84 = F_25 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_82 , V_83 ) ;
V_86 -> V_94 = F_26 ( V_24 ) - V_84 ;
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , unsigned char * V_82 ,
int V_83 )
{
if ( ! F_26 ( V_24 ) )
return 0 ;
if ( ! ( F_24 ( V_24 ) || V_24 -> V_88 == V_95 ) )
return - 1 ;
return F_28 ( V_24 , V_82 , V_83 ) ;
}
static int F_29 ( unsigned char * V_82 , int V_96 ,
int V_97 , int V_98 ,
const char * V_99 , int V_100 ,
const T_4 * V_101 )
{
int V_102 , V_103 ;
char V_104 [ 32 ] ;
V_103 = V_97 + 1 ;
V_82 [ 0 ] = 0x2 ;
V_82 [ 1 ] = 0x1 ;
V_82 [ 2 ] = 0x0 ;
memcpy ( & V_82 [ 4 ] , V_105 , 8 ) ;
memcpy ( & V_82 [ 12 ] , V_106 , 16 ) ;
memcpy ( & V_82 [ 28 ] , V_99 , V_100 ) ;
V_102 = 8 + 16 + V_100 ;
V_82 [ 3 ] = V_102 ;
V_102 += 4 ;
if ( V_98 >= 0 ) {
if ( V_107 ) {
V_82 [ V_102 ++ ] = 0x1 ;
V_82 [ V_102 ++ ] = 0xa ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x12 ;
V_82 [ V_102 ++ ] = 0x10 ;
V_82 [ V_102 ++ ] = 0x0 ;
memcpy ( V_82 + V_102 , V_101 , 16 ) ;
V_102 += 16 ;
} else {
V_82 [ V_102 ++ ] = 0x1 ;
V_82 [ V_102 ++ ] = 0x3 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x8 ;
F_30 ( V_108 + V_98 , V_82 + V_102 ) ;
V_102 += 8 ;
}
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0x94 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x4 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x1 ;
}
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0x93 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x8 ;
F_30 ( V_109 + V_103 , V_82 + V_102 ) ;
V_102 += 8 ;
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0x95 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x4 ;
V_82 [ V_102 ++ ] = 0 ;
V_82 [ V_102 ++ ] = 0 ;
F_13 ( V_96 , V_82 + V_102 ) ;
V_102 += 2 ;
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0xa3 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x8 ;
F_30 ( V_109 + V_97 , V_82 + V_102 ) ;
V_102 += 8 ;
V_82 [ V_102 ++ ] = 0x63 ;
V_82 [ V_102 ++ ] = 0xa8 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 24 ;
memcpy ( V_82 + V_102 , L_18 , 12 ) ;
V_102 += 12 ;
snprintf ( V_104 , sizeof( V_104 ) , L_19 , V_97 ) ;
memcpy ( V_82 + V_102 , V_104 , 8 ) ;
V_102 += 8 ;
memset ( V_82 + V_102 , 0 , 4 ) ;
V_102 += 4 ;
return V_102 ;
}
static int F_31 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_110 , sizeof( V_110 ) ) ;
return sizeof( V_110 ) ;
}
static int F_32 ( unsigned char * V_82 )
{
int V_102 = 0 ;
const char * V_111 = L_20 ;
const char * V_112 = L_21 ;
int V_113 , V_114 ;
V_82 [ V_102 ++ ] = 0x1 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_114 = strlen ( V_111 ) ;
V_113 = V_114 + 1 ;
if ( V_113 % 4 )
V_113 = ( ( V_113 / 4 ) + 1 ) * 4 ;
V_82 [ V_102 ++ ] = V_113 ;
memcpy ( V_82 + V_102 , V_111 , V_114 ) ;
memset ( V_82 + V_102 + V_114 , 0 , V_113 - V_114 ) ;
V_102 += V_113 ;
V_82 [ V_102 ++ ] = 0x4 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_114 = strlen ( V_112 ) ;
V_113 = V_114 + 1 ;
if ( V_113 % 4 )
V_113 = ( ( V_113 / 4 ) + 1 ) * 4 ;
V_82 [ V_102 ++ ] = V_113 ;
memcpy ( V_82 + V_102 , V_112 , V_114 ) ;
memset ( V_82 + V_102 + V_114 , 0 , V_113 - V_114 ) ;
V_102 += V_113 ;
return V_102 ;
}
static int F_33 ( unsigned char * V_82 , int V_97 )
{
int V_102 = 0 ;
int V_103 , V_115 ;
V_103 = V_97 + 1 ;
V_115 = V_103 + 1 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x1 ;
memset ( V_82 + V_102 , 0 , 6 ) ;
V_102 += 6 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 12 ;
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0x93 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x8 ;
F_30 ( V_109 + V_103 , V_82 + V_102 ) ;
V_102 += 8 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x2 ;
memset ( V_82 + V_102 , 0 , 6 ) ;
V_102 += 6 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 12 ;
V_82 [ V_102 ++ ] = 0x61 ;
V_82 [ V_102 ++ ] = 0x93 ;
V_82 [ V_102 ++ ] = 0x0 ;
V_82 [ V_102 ++ ] = 0x8 ;
F_30 ( V_109 + V_115 , V_82 + V_102 ) ;
V_102 += 8 ;
return V_102 ;
}
static int F_34 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_116 , sizeof( V_116 ) ) ;
return sizeof( V_116 ) ;
}
static int F_35 ( unsigned char * V_82 )
{
unsigned int V_117 ;
memcpy ( V_82 , V_118 , sizeof( V_118 ) ) ;
V_117 = 1 << V_119 ;
F_13 ( V_117 , V_82 + 2 ) ;
if ( V_6 > 0x400 )
F_36 ( V_6 , V_82 + 4 ) ;
F_36 ( V_120 , & V_82 [ 8 ] ) ;
if ( V_2 ) {
F_36 ( V_121 , & V_82 [ 16 ] ) ;
F_36 ( V_122 , & V_82 [ 20 ] ) ;
}
if ( V_123 ) {
F_36 ( V_123 , & V_82 [ 28 ] ) ;
V_82 [ 28 ] |= 0x80 ;
}
F_36 ( V_124 , & V_82 [ 24 ] ) ;
F_30 ( V_125 , & V_82 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_118 ) ;
}
static int F_37 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x3c ) ;
V_82 [ 0 ] = 0 ;
V_82 [ 1 ] = 1 ;
V_82 [ 2 ] = 0 ;
V_82 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_38 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x4 ) ;
V_82 [ 0 ] = 0 ;
if ( V_2 )
V_82 [ 1 ] = 1 << 7 ;
if ( V_3 )
V_82 [ 1 ] |= 1 << 6 ;
if ( V_4 )
V_82 [ 1 ] |= 1 << 5 ;
if ( V_126 && F_1 () )
V_82 [ 1 ] |= ( V_126 & 0x7 ) << 2 ;
return 0x4 ;
}
static int F_39 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char V_127 ;
unsigned char * V_82 ;
unsigned char * V_50 = V_24 -> V_128 ;
int V_129 , V_130 , V_131 ;
bool V_132 , V_133 ;
V_129 = F_40 ( V_50 + 3 ) ;
V_82 = F_41 ( V_134 , V_135 ) ;
if ( ! V_82 )
return V_136 << 16 ;
V_133 = ( V_137 == V_138 ) ;
V_132 = F_42 ( V_24 -> V_35 -> V_139 ) ;
if ( V_132 )
V_127 = V_140 ;
else if ( V_141 && ( V_54 -> V_139 == V_142 ) )
V_127 = 0x7f ;
else
V_127 = ( V_137 & 0x1f ) ;
V_82 [ 0 ] = V_127 ;
if ( 0x2 & V_50 [ 1 ] ) {
F_10 ( V_24 , V_143 , 1 , 1 ) ;
F_43 ( V_82 ) ;
return V_81 ;
} else if ( 0x1 & V_50 [ 1 ] ) {
int V_144 , V_96 , V_97 , V_145 ;
char V_146 [ 6 ] ;
int V_147 = V_54 -> V_13 -> V_17 -> V_147 ;
V_96 = ( ( ( V_147 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_148 & 0x7f ) ;
if ( V_149 == 0 )
V_147 = 0 ;
V_144 = V_132 ? - 1 : ( ( ( V_147 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) + V_54 -> V_139 ) ;
V_97 = ( ( V_147 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
V_145 = F_44 ( V_146 , 6 , L_22 , V_144 ) ;
if ( 0 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_130 = 4 ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0x80 ;
V_82 [ V_130 ++ ] = 0x83 ;
V_82 [ V_130 ++ ] = 0x84 ;
V_82 [ V_130 ++ ] = 0x85 ;
V_82 [ V_130 ++ ] = 0x86 ;
V_82 [ V_130 ++ ] = 0x87 ;
V_82 [ V_130 ++ ] = 0x88 ;
if ( V_133 ) {
V_82 [ V_130 ++ ] = 0x89 ;
V_82 [ V_130 ++ ] = 0xb0 ;
V_82 [ V_130 ++ ] = 0xb1 ;
V_82 [ V_130 ++ ] = 0xb2 ;
}
V_82 [ 3 ] = V_130 - 4 ;
} else if ( 0x80 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = V_145 ;
memcpy ( & V_82 [ 4 ] , V_146 , V_145 ) ;
} else if ( 0x83 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_29 ( & V_82 [ 4 ] , V_96 ,
V_97 , V_144 ,
V_146 , V_145 ,
& V_54 -> V_101 ) ;
} else if ( 0x84 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_31 ( & V_82 [ 4 ] ) ;
} else if ( 0x85 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_32 ( & V_82 [ 4 ] ) ;
} else if ( 0x86 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = 0x3c ;
if ( V_150 == V_151 )
V_82 [ 4 ] = 0x4 ;
else if ( V_152 )
V_82 [ 4 ] = 0x5 ;
else
V_82 [ 4 ] = 0x0 ;
V_82 [ 5 ] = 0x7 ;
} else if ( 0x87 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = 0x8 ;
V_82 [ 4 ] = 0x2 ;
V_82 [ 6 ] = 0x80 ;
V_82 [ 8 ] = 0x18 ;
V_82 [ 10 ] = 0x82 ;
} else if ( 0x88 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_33 ( & V_82 [ 4 ] , V_97 ) ;
} else if ( V_133 && 0x89 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_130 = F_34 ( & V_82 [ 4 ] ) ;
F_13 ( V_130 , V_82 + 2 ) ;
} else if ( V_133 && 0xb0 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_35 ( & V_82 [ 4 ] ) ;
} else if ( V_133 && 0xb1 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_37 ( & V_82 [ 4 ] ) ;
} else if ( V_133 && 0xb2 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_38 ( & V_82 [ 4 ] ) ;
} else {
F_10 ( V_24 , V_143 , 2 , - 1 ) ;
F_43 ( V_82 ) ;
return V_81 ;
}
V_145 = F_45 ( F_40 ( V_82 + 2 ) + 4 , V_129 ) ;
V_131 = F_22 ( V_24 , V_82 ,
F_45 ( V_145 , V_134 ) ) ;
F_43 ( V_82 ) ;
return V_131 ;
}
V_82 [ 1 ] = V_153 ? 0x80 : 0 ;
V_82 [ 2 ] = V_79 ;
V_82 [ 3 ] = 2 ;
V_82 [ 4 ] = V_154 - 5 ;
V_82 [ 5 ] = ( int ) V_152 ;
if ( V_149 == 0 )
V_82 [ 5 ] = 0x10 ;
V_82 [ 6 ] = 0x10 ;
V_82 [ 7 ] = 0xa ;
memcpy ( & V_82 [ 8 ] , V_105 , 8 ) ;
memcpy ( & V_82 [ 16 ] , V_106 , 16 ) ;
memcpy ( & V_82 [ 32 ] , V_155 , 4 ) ;
F_13 ( 0xc0 , V_82 + 58 ) ;
F_13 ( 0x5c0 , V_82 + 60 ) ;
V_130 = 62 ;
if ( V_133 ) {
F_13 ( 0x600 , V_82 + V_130 ) ;
V_130 += 2 ;
} else if ( V_137 == V_156 ) {
F_13 ( 0x525 , V_82 + V_130 ) ;
V_130 += 2 ;
}
F_13 ( 0x2100 , V_82 + V_130 ) ;
V_131 = F_22 ( V_24 , V_82 ,
F_45 ( V_129 , V_154 ) ) ;
F_43 ( V_82 ) ;
return V_131 ;
}
static int F_46 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_29 ;
unsigned char * V_50 = V_24 -> V_128 ;
unsigned char V_82 [ V_39 ] ;
bool V_157 ;
int V_145 = 18 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_157 = ! ! ( V_50 [ 1 ] & 1 ) ;
V_29 = V_24 -> V_33 ;
if ( ( V_158 [ 2 ] & 0x4 ) && ( 6 == ( V_158 [ 3 ] & 0xf ) ) ) {
if ( V_157 ) {
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = 0x0 ;
V_82 [ 2 ] = V_159 ;
V_82 [ 3 ] = 0xff ;
V_145 = 8 ;
} else {
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = 0x0 ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_159 ;
V_82 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_82 , V_29 , V_39 ) ;
if ( V_82 [ 0 ] >= 0x70 && V_157 == V_40 )
;
else if ( V_82 [ 0 ] <= 0x70 ) {
if ( V_157 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_145 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 7 ] = 0xa ;
}
} else if ( V_157 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = V_29 [ 2 ] ;
V_82 [ 2 ] = V_29 [ 12 ] ;
V_82 [ 3 ] = V_29 [ 13 ] ;
V_145 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = V_29 [ 1 ] ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_29 [ 1 ] ;
V_82 [ 13 ] = V_29 [ 3 ] ;
}
}
F_14 ( V_24 , 0 , V_160 , 0 ) ;
return F_22 ( V_24 , V_82 , V_145 ) ;
}
static int F_47 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_128 ;
int V_161 , V_162 ;
V_161 = ( V_50 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_161 ) {
F_10 ( V_24 , V_143 , 4 , 7 ) ;
return V_81 ;
}
V_162 = ! ( V_50 [ 4 ] & 1 ) ;
F_48 ( & V_54 -> V_163 , V_162 ) ;
return 0 ;
}
static T_1 F_49 ( void )
{
static const unsigned int V_164 = 1073741824 ;
if ( V_165 > 0 )
return ( T_1 ) V_165 *
( V_164 / V_8 ) ;
else
return V_6 ;
}
static int F_50 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char V_82 [ V_166 ] ;
unsigned int V_167 ;
V_168 = F_49 () ;
memset ( V_82 , 0 , V_166 ) ;
if ( V_168 < 0xffffffff ) {
V_167 = ( unsigned int ) V_168 - 1 ;
F_36 ( V_167 , V_82 + 0 ) ;
} else
F_36 ( 0xffffffff , V_82 + 0 ) ;
F_13 ( V_8 , V_82 + 6 ) ;
return F_22 ( V_24 , V_82 , V_166 ) ;
}
static int F_51 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_128 ;
unsigned char V_82 [ V_169 ] ;
int V_129 ;
V_129 = F_52 ( V_50 + 10 ) ;
V_168 = F_49 () ;
memset ( V_82 , 0 , V_169 ) ;
F_30 ( ( V_170 ) ( V_168 - 1 ) , V_82 + 0 ) ;
F_36 ( V_8 , V_82 + 8 ) ;
V_82 [ 13 ] = V_119 & 0xf ;
V_82 [ 14 ] = ( V_171 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_82 [ 14 ] |= 0x80 ;
if ( V_126 & 1 )
V_82 [ 14 ] |= 0x40 ;
}
V_82 [ 15 ] = V_171 & 0xff ;
if ( V_152 ) {
V_82 [ 12 ] = ( V_150 - 1 ) << 1 ;
V_82 [ 12 ] |= 1 ;
}
return F_22 ( V_24 , V_82 ,
F_45 ( V_129 , V_169 ) ) ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_128 ;
unsigned char * V_82 ;
int V_147 = V_54 -> V_13 -> V_17 -> V_147 ;
int V_130 , V_131 , V_172 , V_173 ;
int V_174 , V_175 , V_103 , V_115 ;
V_172 = F_52 ( V_50 + 6 ) ;
V_82 = F_41 ( V_176 , V_135 ) ;
if ( ! V_82 )
return V_136 << 16 ;
V_103 = 0x1 ;
V_115 = 0x2 ;
V_174 = ( ( ( V_147 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_148 & 0x7f ) ;
V_175 = ( ( ( V_147 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_148 & 0x7f ) + 0x80 ;
V_130 = 4 ;
if ( V_149 == 0 ) {
V_82 [ V_130 ++ ] = V_147 % 3 ;
V_82 [ V_130 ++ ] = 0x0F ;
} else {
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0x01 ;
}
F_13 ( V_174 , V_82 + V_130 ) ;
V_130 += 2 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0x1 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
F_13 ( V_103 , V_82 + V_130 ) ;
V_130 += 2 ;
V_82 [ V_130 ++ ] = 3 ;
V_82 [ V_130 ++ ] = 0x08 ;
F_13 ( V_175 , V_82 + V_130 ) ;
V_130 += 2 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0x1 ;
V_82 [ V_130 ++ ] = 0 ;
V_82 [ V_130 ++ ] = 0 ;
F_13 ( V_115 , V_82 + V_130 ) ;
V_130 += 2 ;
V_173 = V_130 - 4 ;
F_36 ( V_173 , V_82 + 0 ) ;
V_173 = F_45 ( V_172 , V_130 ) ;
V_131 = F_22 ( V_24 , V_82 ,
F_45 ( V_173 , V_176 ) ) ;
F_43 ( V_82 ) ;
return V_131 ;
}
static int F_54 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_177 ;
T_2 V_178 , V_179 , V_180 , V_181 ;
T_5 V_182 , V_183 ;
T_6 V_129 , V_184 ;
int V_60 , V_185 , V_145 , V_186 , V_187 , V_188 , V_189 ;
const struct V_190 * V_191 ;
const struct V_190 * V_192 ;
T_2 * V_82 ;
T_2 * V_50 = V_24 -> V_128 ;
V_177 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_178 = V_50 [ 2 ] & 0x7 ;
V_179 = V_50 [ 3 ] ;
V_182 = F_40 ( V_50 + 4 ) ;
V_129 = F_52 ( V_50 + 6 ) ;
if ( V_129 < 4 || V_129 > 0xffff ) {
F_10 ( V_24 , V_143 , 6 , - 1 ) ;
return V_81 ;
}
if ( V_129 > 8192 )
V_184 = 8192 ;
else
V_184 = V_129 ;
V_82 = F_41 ( ( V_184 < 256 ) ? 320 : V_184 + 64 , V_135 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
switch ( V_178 ) {
case 0 :
for ( V_187 = 0 , V_191 = V_195 ;
V_191 -> V_196 != 0xff ; ++ V_191 ) {
if ( V_197 & V_191 -> V_198 )
continue;
V_187 += ( V_191 -> V_196 + 1 ) ;
}
V_188 = V_177 ? 20 : 8 ;
F_36 ( V_187 * V_188 , V_82 ) ;
for ( V_185 = 4 , V_191 = V_195 ;
V_191 -> V_196 != 0xff && V_185 < V_184 ; ++ V_191 ) {
if ( V_197 & V_191 -> V_198 )
continue;
V_189 = V_191 -> V_196 ;
V_82 [ V_185 ] = V_191 -> V_199 ;
F_13 ( V_191 -> V_200 , V_82 + V_185 + 2 ) ;
if ( V_177 )
V_82 [ V_185 + 5 ] |= 0x2 ;
if ( V_201 & V_191 -> V_198 )
V_82 [ V_185 + 5 ] |= 0x1 ;
F_13 ( V_191 -> V_202 [ 0 ] , V_82 + V_185 + 6 ) ;
if ( V_177 )
F_13 ( 0xa , V_82 + V_185 + 8 ) ;
V_192 = V_191 ;
for ( V_60 = 0 , V_191 = V_191 -> V_203 ; V_60 < V_189 ; ++ V_60 , ++ V_191 ) {
if ( V_197 & V_191 -> V_198 )
continue;
V_185 += V_188 ;
V_82 [ V_185 ] = V_191 -> V_199 ;
F_13 ( V_191 -> V_200 , V_82 + V_185 + 2 ) ;
if ( V_177 )
V_82 [ V_185 + 5 ] |= 0x2 ;
if ( V_201 & V_191 -> V_198 )
V_82 [ V_185 + 5 ] |= 0x1 ;
F_13 ( V_191 -> V_202 [ 0 ] ,
V_82 + V_185 + 6 ) ;
if ( V_177 )
F_13 ( 0xa ,
V_82 + V_185 + 8 ) ;
}
V_191 = V_192 ;
V_185 += V_188 ;
}
break;
case 1 :
case 2 :
case 3 :
V_180 = V_204 [ V_179 ] ;
V_191 = & V_195 [ V_180 ] ;
if ( V_197 & V_191 -> V_198 ) {
V_181 = 1 ;
V_185 = 4 ;
} else {
if ( 1 == V_178 ) {
if ( V_201 & V_191 -> V_198 ) {
F_10 ( V_24 , V_143 ,
2 , 2 ) ;
F_43 ( V_82 ) ;
return V_81 ;
}
V_182 = 0 ;
} else if ( 2 == V_178 &&
0 == ( V_201 & V_191 -> V_198 ) ) {
F_10 ( V_24 , V_143 , 4 , - 1 ) ;
F_43 ( V_82 ) ;
return V_81 ;
}
if ( 0 == ( V_201 & V_191 -> V_198 ) &&
V_179 == V_191 -> V_199 )
V_181 = 3 ;
else if ( 0 == ( V_201 & V_191 -> V_198 ) ) {
V_189 = V_191 -> V_196 ;
for ( V_60 = 0 , V_191 = V_191 -> V_203 ; V_60 < V_189 ;
++ V_60 , ++ V_191 ) {
if ( V_179 == V_191 -> V_199 )
break;
}
V_181 = ( V_60 >= V_189 ) ? 1 : 3 ;
} else if ( V_182 != V_191 -> V_200 ) {
V_189 = V_191 -> V_196 ;
for ( V_60 = 0 , V_191 = V_191 -> V_203 ; V_60 < V_189 ;
++ V_60 , ++ V_191 ) {
if ( V_182 == V_191 -> V_200 )
break;
}
V_181 = ( V_60 >= V_189 ) ? 1 : 3 ;
} else
V_181 = 3 ;
if ( 3 == V_181 ) {
V_183 = V_191 -> V_202 [ 0 ] ;
F_13 ( V_183 , V_82 + 2 ) ;
V_82 [ 4 ] = V_191 -> V_199 ;
for ( V_60 = 1 ; V_60 < V_183 ; ++ V_60 )
V_82 [ 4 + V_60 ] = ( V_60 < 16 ) ?
V_191 -> V_202 [ V_60 ] : 0xff ;
V_185 = 4 + V_183 ;
} else
V_185 = 4 ;
}
V_82 [ 1 ] = ( V_177 ? 0x80 : 0 ) | V_181 ;
if ( V_177 ) {
F_13 ( 0xa , V_82 + V_185 ) ;
V_185 += 12 ;
}
break;
default:
F_10 ( V_24 , V_143 , 2 , 2 ) ;
F_43 ( V_82 ) ;
return V_81 ;
}
V_185 = ( V_185 < V_184 ) ? V_185 : V_184 ;
V_145 = ( V_185 < V_129 ) ? V_185 : V_129 ;
V_186 = F_22 ( V_24 , V_82 , V_145 ) ;
F_43 ( V_82 ) ;
return V_186 ;
}
static int F_55 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_205 ;
T_6 V_129 , V_145 ;
T_2 V_82 [ 16 ] ;
T_2 * V_50 = V_24 -> V_128 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_205 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_129 = F_52 ( V_50 + 6 ) ;
if ( V_129 < 4 ) {
F_10 ( V_24 , V_143 , 6 , - 1 ) ;
return V_81 ;
}
V_82 [ 0 ] = 0xc8 ;
V_82 [ 1 ] = 0x1 ;
if ( V_205 ) {
V_82 [ 3 ] = 0xc ;
V_145 = 16 ;
} else
V_145 = 4 ;
V_145 = ( V_145 < V_129 ) ? V_145 : V_129 ;
return F_22 ( V_24 , V_82 , V_145 ) ;
}
static int F_56 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_208 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_206 , V_208 , sizeof( V_208 ) ) ;
if ( 1 == V_207 )
memset ( V_206 + 2 , 0 , sizeof( V_208 ) - 2 ) ;
return sizeof( V_208 ) ;
}
static int F_57 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_209 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_206 , V_209 , sizeof( V_209 ) ) ;
if ( 1 == V_207 )
memset ( V_206 + 2 , 0 , sizeof( V_209 ) - 2 ) ;
return sizeof( V_209 ) ;
}
static int F_58 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_210 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_206 , V_210 , sizeof( V_210 ) ) ;
F_13 ( V_211 , V_206 + 10 ) ;
F_13 ( V_8 , V_206 + 12 ) ;
if ( V_153 )
V_206 [ 20 ] |= 0x20 ;
if ( 1 == V_207 )
memset ( V_206 + 2 , 0 , sizeof( V_210 ) - 2 ) ;
return sizeof( V_210 ) ;
}
static int F_59 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_212 [] = { 0x4 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned char V_213 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_214 & V_215 )
V_216 [ 2 ] &= ~ 0x4 ;
memcpy ( V_206 , V_216 , sizeof( V_216 ) ) ;
if ( 1 == V_207 )
memcpy ( V_206 + 2 , V_212 , sizeof( V_212 ) ) ;
else if ( 2 == V_207 )
memcpy ( V_206 , V_213 , sizeof( V_213 ) ) ;
return sizeof( V_216 ) ;
}
static int F_60 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_217 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_218 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_40 )
V_219 [ 2 ] |= 0x4 ;
else
V_219 [ 2 ] &= ~ 0x4 ;
if ( V_220 )
V_219 [ 5 ] |= 0x80 ;
memcpy ( V_206 , V_219 , sizeof( V_219 ) ) ;
if ( 1 == V_207 )
memcpy ( V_206 + 2 , V_217 , sizeof( V_217 ) ) ;
else if ( 2 == V_207 )
memcpy ( V_206 , V_218 , sizeof( V_218 ) ) ;
return sizeof( V_219 ) ;
}
static int F_61 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_221 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_222 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_206 , V_158 , sizeof( V_158 ) ) ;
if ( 1 == V_207 )
memcpy ( V_206 + 2 , V_221 , sizeof( V_221 ) ) ;
else if ( 2 == V_207 )
memcpy ( V_206 , V_222 , sizeof( V_222 ) ) ;
return sizeof( V_158 ) ;
}
static int F_62 ( unsigned char * V_206 , int V_207 , int V_57 )
{
unsigned char V_223 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_206 , V_223 , sizeof( V_223 ) ) ;
if ( 1 == V_207 )
memset ( V_206 + 2 , 0 , sizeof( V_223 ) - 2 ) ;
return sizeof( V_223 ) ;
}
static int F_63 ( unsigned char * V_206 , int V_207 , int V_57 ,
int V_97 )
{
unsigned char V_224 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
0 , 0 , 0 , 0 , 0x10 , 0x9 , 0x8 , 0x0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x88 , 0x99 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 1 , 0 , 0 , 0x10 , 0x9 , 0x8 , 0x0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x88 , 0x99 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_103 , V_115 ;
F_30 ( V_109 , V_224 + 16 ) ;
F_30 ( V_225 + 1 , V_224 + 24 ) ;
F_30 ( V_109 , V_224 + 64 ) ;
F_30 ( V_225 + 1 , V_224 + 72 ) ;
V_103 = V_97 + 1 ;
V_115 = V_103 + 1 ;
memcpy ( V_206 , V_224 , sizeof( V_224 ) ) ;
F_36 ( V_103 , V_206 + 20 ) ;
F_36 ( V_115 , V_206 + 48 + 20 ) ;
if ( 1 == V_207 )
memset ( V_206 + 4 , 0 , sizeof( V_224 ) - 4 ) ;
return sizeof( V_224 ) ;
}
static int F_64 ( unsigned char * V_206 , int V_207 )
{
unsigned char V_226 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_206 , V_226 , sizeof( V_226 ) ) ;
if ( 1 == V_207 )
memset ( V_206 + 4 , 0 , sizeof( V_226 ) - 4 ) ;
return sizeof( V_226 ) ;
}
static int F_65 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_207 , V_227 , V_228 , V_229 ;
unsigned char V_230 ;
int V_129 , V_185 , V_145 , V_97 ;
int V_57 = V_24 -> V_35 -> V_231 ;
unsigned char * V_232 ;
unsigned char V_82 [ V_233 ] ;
unsigned char * V_50 = V_24 -> V_128 ;
bool V_234 , V_235 , V_236 , V_133 , V_237 ;
V_234 = ! ! ( V_50 [ 1 ] & 0x8 ) ;
V_207 = ( V_50 [ 2 ] & 0xc0 ) >> 6 ;
V_227 = V_50 [ 2 ] & 0x3f ;
V_228 = V_50 [ 3 ] ;
V_236 = ( V_238 == V_50 [ 0 ] ) ;
V_235 = V_236 ? false : ! ! ( V_50 [ 1 ] & 0x10 ) ;
V_133 = ( V_137 == V_138 ) ;
if ( V_133 && ! V_234 )
V_229 = V_235 ? 16 : 8 ;
else
V_229 = 0 ;
V_129 = V_236 ? V_50 [ 4 ] : F_40 ( V_50 + 7 ) ;
memset ( V_82 , 0 , V_233 ) ;
if ( 0x3 == V_207 ) {
F_14 ( V_24 , V_41 , V_239 , 0 ) ;
return V_81 ;
}
V_97 = ( ( V_54 -> V_13 -> V_17 -> V_147 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
if ( V_133 )
V_230 = 0x10 ;
else
V_230 = 0x0 ;
if ( V_236 ) {
V_82 [ 2 ] = V_230 ;
V_82 [ 3 ] = V_229 ;
V_185 = 4 ;
} else {
V_82 [ 3 ] = V_230 ;
if ( 16 == V_229 )
V_82 [ 4 ] = 0x1 ;
V_82 [ 7 ] = V_229 ;
V_185 = 8 ;
}
V_232 = V_82 + V_185 ;
if ( ( V_229 > 0 ) && ( ! V_168 ) )
V_168 = F_49 () ;
if ( 8 == V_229 ) {
if ( V_168 > 0xfffffffe )
F_36 ( 0xffffffff , V_232 + 0 ) ;
else
F_36 ( V_168 , V_232 + 0 ) ;
F_13 ( V_8 , V_232 + 6 ) ;
V_185 += V_229 ;
V_232 = V_82 + V_185 ;
} else if ( 16 == V_229 ) {
F_30 ( ( V_170 ) V_168 , V_232 + 0 ) ;
F_36 ( V_8 , V_232 + 12 ) ;
V_185 += V_229 ;
V_232 = V_82 + V_185 ;
}
if ( ( V_228 > 0x0 ) && ( V_228 < 0xff ) && ( 0x19 != V_227 ) ) {
F_10 ( V_24 , V_143 , 3 , - 1 ) ;
return V_81 ;
}
V_237 = false ;
switch ( V_227 ) {
case 0x1 :
V_145 = F_56 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
break;
case 0x2 :
V_145 = F_57 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
break;
case 0x3 :
if ( V_133 ) {
V_145 = F_58 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
} else
V_237 = true ;
break;
case 0x8 :
if ( V_133 ) {
V_145 = F_59 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
} else
V_237 = true ;
break;
case 0xa :
V_145 = F_60 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
break;
case 0x19 :
if ( ( V_228 > 0x2 ) && ( V_228 < 0xff ) ) {
F_10 ( V_24 , V_143 , 3 , - 1 ) ;
return V_81 ;
}
V_145 = 0 ;
if ( ( 0x0 == V_228 ) || ( 0xff == V_228 ) )
V_145 += F_62 ( V_232 + V_145 , V_207 , V_57 ) ;
if ( ( 0x1 == V_228 ) || ( 0xff == V_228 ) )
V_145 += F_63 ( V_232 + V_145 , V_207 , V_57 ,
V_97 ) ;
if ( ( 0x2 == V_228 ) || ( 0xff == V_228 ) )
V_145 += F_64 ( V_232 + V_145 , V_207 ) ;
V_185 += V_145 ;
break;
case 0x1c :
V_145 = F_61 ( V_232 , V_207 , V_57 ) ;
V_185 += V_145 ;
break;
case 0x3f :
if ( ( 0 == V_228 ) || ( 0xff == V_228 ) ) {
V_145 = F_56 ( V_232 , V_207 , V_57 ) ;
V_145 += F_57 ( V_232 + V_145 , V_207 , V_57 ) ;
if ( V_133 ) {
V_145 += F_58 ( V_232 + V_145 , V_207 ,
V_57 ) ;
V_145 += F_59 ( V_232 + V_145 , V_207 ,
V_57 ) ;
}
V_145 += F_60 ( V_232 + V_145 , V_207 , V_57 ) ;
V_145 += F_62 ( V_232 + V_145 , V_207 , V_57 ) ;
if ( 0xff == V_228 ) {
V_145 += F_63 ( V_232 + V_145 , V_207 ,
V_57 , V_97 ) ;
V_145 += F_64 ( V_232 + V_145 , V_207 ) ;
}
V_145 += F_61 ( V_232 + V_145 , V_207 , V_57 ) ;
V_185 += V_145 ;
} else {
F_10 ( V_24 , V_143 , 3 , - 1 ) ;
return V_81 ;
}
break;
default:
V_237 = true ;
break;
}
if ( V_237 ) {
F_10 ( V_24 , V_143 , 2 , 5 ) ;
return V_81 ;
}
if ( V_236 )
V_82 [ 0 ] = V_185 - 1 ;
else
F_13 ( ( V_185 - 2 ) , V_82 + 0 ) ;
return F_22 ( V_24 , V_82 , F_45 ( V_129 , V_185 ) ) ;
}
static int F_66 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_240 , V_241 , V_242 , V_243 , V_229 , V_244 , V_245 , V_246 ;
int V_247 , V_248 , V_249 ;
unsigned char V_82 [ V_250 ] ;
unsigned char * V_50 = V_24 -> V_128 ;
int V_251 = ( V_252 == V_50 [ 0 ] ) ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_240 = V_50 [ 1 ] & 0x10 ;
V_241 = V_50 [ 1 ] & 0x1 ;
V_247 = V_251 ? V_50 [ 4 ] : F_40 ( V_50 + 7 ) ;
if ( ( 0 == V_240 ) || V_241 || ( V_247 > V_250 ) ) {
F_10 ( V_24 , V_143 , V_251 ? 4 : 7 , - 1 ) ;
return V_81 ;
}
V_248 = F_27 ( V_24 , V_82 , V_247 ) ;
if ( - 1 == V_248 )
return V_90 << 16 ;
else if ( V_42 && ( V_248 < V_247 ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_23 ,
V_36 , V_247 , V_248 ) ;
V_243 = V_251 ? ( V_82 [ 0 ] + 1 ) : ( F_40 ( V_82 + 0 ) + 2 ) ;
V_229 = V_251 ? V_82 [ 3 ] : F_40 ( V_82 + 6 ) ;
if ( V_243 > 2 ) {
F_10 ( V_24 , V_253 , 0 , - 1 ) ;
return V_81 ;
}
V_244 = V_229 + ( V_251 ? 4 : 8 ) ;
V_249 = V_82 [ V_244 ] & 0x3f ;
V_242 = ! ! ( V_82 [ V_244 ] & 0x80 ) ;
if ( V_242 ) {
F_10 ( V_24 , V_253 , V_244 , 7 ) ;
return V_81 ;
}
V_245 = ! ! ( V_82 [ V_244 ] & 0x40 ) ;
V_246 = V_245 ? ( F_40 ( V_82 + V_244 + 2 ) + 4 ) :
( V_82 [ V_244 + 1 ] + 2 ) ;
if ( ( V_246 + V_244 ) > V_247 ) {
F_14 ( V_24 , V_41 ,
V_254 , 0 ) ;
return V_81 ;
}
switch ( V_249 ) {
case 0x8 :
if ( V_216 [ 1 ] == V_82 [ V_244 + 1 ] ) {
memcpy ( V_216 + 2 , V_82 + V_244 + 2 ,
sizeof( V_216 ) - 2 ) ;
goto V_255;
}
break;
case 0xa :
if ( V_219 [ 1 ] == V_82 [ V_244 + 1 ] ) {
memcpy ( V_219 + 2 , V_82 + V_244 + 2 ,
sizeof( V_219 ) - 2 ) ;
V_40 = ! ! ( V_219 [ 2 ] & 0x4 ) ;
goto V_255;
}
break;
case 0x1c :
if ( V_158 [ 1 ] == V_82 [ V_244 + 1 ] ) {
memcpy ( V_158 + 2 , V_82 + V_244 + 2 ,
sizeof( V_158 ) - 2 ) ;
goto V_255;
}
break;
default:
break;
}
F_10 ( V_24 , V_253 , V_244 , 5 ) ;
return V_81 ;
V_255:
F_67 ( V_69 , V_54 -> V_59 ) ;
return 0 ;
}
static int F_68 ( unsigned char * V_82 )
{
unsigned char V_256 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_82 , V_256 , sizeof( V_256 ) ) ;
return sizeof( V_256 ) ;
}
static int F_69 ( unsigned char * V_82 )
{
unsigned char V_257 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_82 , V_257 , sizeof( V_257 ) ) ;
if ( V_158 [ 2 ] & 0x4 ) {
V_82 [ 4 ] = V_159 ;
V_82 [ 5 ] = 0xff ;
}
return sizeof( V_257 ) ;
}
static int F_70 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_258 , V_241 , V_207 , V_227 , V_228 , V_129 , V_145 , V_130 ;
unsigned char V_82 [ V_259 ] ;
unsigned char * V_50 = V_24 -> V_128 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_258 = V_50 [ 1 ] & 0x2 ;
V_241 = V_50 [ 1 ] & 0x1 ;
if ( V_258 || V_241 ) {
F_10 ( V_24 , V_143 , 1 , V_258 ? 1 : 0 ) ;
return V_81 ;
}
V_207 = ( V_50 [ 2 ] & 0xc0 ) >> 6 ;
V_227 = V_50 [ 2 ] & 0x3f ;
V_228 = V_50 [ 3 ] & 0xff ;
V_129 = F_40 ( V_50 + 7 ) ;
V_82 [ 0 ] = V_227 ;
if ( 0 == V_228 ) {
switch ( V_227 ) {
case 0x0 :
V_130 = 4 ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0xd ;
V_82 [ V_130 ++ ] = 0x2f ;
V_82 [ 3 ] = V_130 - 4 ;
break;
case 0xd :
V_82 [ 3 ] = F_68 ( V_82 + 4 ) ;
break;
case 0x2f :
V_82 [ 3 ] = F_69 ( V_82 + 4 ) ;
break;
default:
F_10 ( V_24 , V_143 , 2 , 5 ) ;
return V_81 ;
}
} else if ( 0xff == V_228 ) {
V_82 [ 0 ] |= 0x40 ;
V_82 [ 1 ] = V_228 ;
switch ( V_227 ) {
case 0x0 :
V_130 = 4 ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0xff ;
V_82 [ V_130 ++ ] = 0xd ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ V_130 ++ ] = 0x2f ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ 3 ] = V_130 - 4 ;
break;
case 0xd :
V_130 = 4 ;
V_82 [ V_130 ++ ] = 0xd ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ 3 ] = V_130 - 4 ;
break;
case 0x2f :
V_130 = 4 ;
V_82 [ V_130 ++ ] = 0x2f ;
V_82 [ V_130 ++ ] = 0x0 ;
V_82 [ 3 ] = V_130 - 4 ;
break;
default:
F_10 ( V_24 , V_143 , 2 , 5 ) ;
return V_81 ;
}
} else {
F_10 ( V_24 , V_143 , 3 , - 1 ) ;
return V_81 ;
}
V_145 = F_45 ( F_40 ( V_82 + 2 ) + 4 , V_129 ) ;
return F_22 ( V_24 , V_82 ,
F_45 ( V_145 , V_134 ) ) ;
}
static int F_71 ( struct V_23 * V_24 ,
unsigned long long V_5 , unsigned int V_102 )
{
if ( V_5 + V_102 > V_168 ) {
F_14 ( V_24 , V_41 , V_260 , 0 ) ;
return V_81 ;
}
if ( V_102 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
return 0 ;
}
static int F_72 ( struct V_23 * V_261 , V_170 V_5 , T_6 V_102 ,
bool V_262 )
{
int V_131 ;
V_170 V_263 , V_264 = 0 ;
struct V_85 * V_86 ;
enum V_265 V_266 ;
if ( V_262 ) {
V_86 = F_73 ( V_261 ) ;
V_266 = V_95 ;
} else {
V_86 = F_23 ( V_261 ) ;
V_266 = V_89 ;
}
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_24 ( V_261 ) || V_261 -> V_88 == V_266 ) )
return - 1 ;
V_263 = F_3 ( V_5 , V_6 ) ;
if ( V_263 + V_102 > V_6 )
V_264 = V_263 + V_102 - V_6 ;
V_131 = F_74 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 + ( V_263 * V_8 ) ,
( V_102 - V_264 ) * V_8 , 0 , V_262 ) ;
if ( V_131 != ( V_102 - V_264 ) * V_8 )
return V_131 ;
if ( V_264 ) {
V_131 += F_74 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 , V_264 * V_8 ,
( V_102 - V_264 ) * V_8 , V_262 ) ;
}
return V_131 ;
}
static bool F_75 ( V_170 V_5 , T_6 V_102 , const T_2 * V_82 )
{
bool V_248 ;
V_170 V_263 , V_264 = 0 ;
T_6 V_267 = V_6 ;
T_6 V_268 = V_8 ;
V_263 = F_3 ( V_5 , V_267 ) ;
if ( V_263 + V_102 > V_267 )
V_264 = V_263 + V_102 - V_267 ;
V_248 = ! memcmp ( V_7 + ( V_263 * V_268 ) , V_82 ,
( V_102 - V_264 ) * V_268 ) ;
if ( ! V_248 )
return V_248 ;
if ( V_264 )
V_248 = memcmp ( V_7 , V_82 + ( ( V_102 - V_264 ) * V_268 ) ,
V_264 * V_268 ) ;
if ( ! V_248 )
return V_248 ;
V_82 += V_102 * V_268 ;
memcpy ( V_7 + ( V_263 * V_268 ) , V_82 , ( V_102 - V_264 ) * V_268 ) ;
if ( V_264 )
memcpy ( V_7 , V_82 + ( ( V_102 - V_264 ) * V_268 ) ,
V_264 * V_268 ) ;
return V_248 ;
}
static T_7 F_76 ( const void * V_269 , int V_145 )
{
T_7 V_270 ;
if ( V_271 )
V_270 = ( V_272 T_7 ) F_77 ( V_269 , V_145 ) ;
else
V_270 = F_78 ( F_79 ( V_269 , V_145 ) ) ;
return V_270 ;
}
static int F_80 ( struct V_9 * V_273 , const void * V_274 ,
T_1 V_10 , T_6 V_275 )
{
T_7 V_270 = F_76 ( V_274 , V_8 ) ;
if ( V_273 -> V_276 != V_270 ) {
F_81 ( L_24 ,
( unsigned long ) V_10 ,
F_82 ( V_273 -> V_276 ) ,
F_82 ( V_270 ) ) ;
return 0x01 ;
}
if ( V_150 == V_277 &&
F_83 ( V_273 -> V_278 ) != ( V_10 & 0xffffffff ) ) {
F_81 ( L_25 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
if ( V_150 == V_279 &&
F_83 ( V_273 -> V_278 ) != V_275 ) {
F_81 ( L_25 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
return 0 ;
}
static void F_84 ( struct V_23 * V_280 , T_1 V_10 ,
unsigned int V_281 , bool V_282 )
{
T_8 V_94 ;
void * V_283 ;
const void * V_284 = V_11 + V_6 ;
struct V_285 V_286 ;
V_94 = V_281 * sizeof( * V_11 ) ;
F_85 ( & V_286 , F_86 ( V_280 ) ,
F_87 ( V_280 ) , V_287 |
( V_282 ? V_288 : V_289 ) ) ;
while ( F_88 ( & V_286 ) && V_94 > 0 ) {
T_8 V_145 = F_45 ( V_286 . V_87 , V_94 ) ;
void * V_290 = F_4 ( V_10 ) ;
T_8 V_264 = 0 ;
if ( V_284 < V_290 + V_145 )
V_264 = V_290 + V_145 - V_284 ;
V_283 = V_286 . V_291 ;
if ( V_282 )
memcpy ( V_283 , V_290 , V_145 - V_264 ) ;
else
memcpy ( V_290 , V_283 , V_145 - V_264 ) ;
if ( V_264 ) {
if ( V_282 )
memcpy ( V_283 + V_145 - V_264 , V_11 , V_264 ) ;
else
memcpy ( V_11 , V_283 + V_145 - V_264 , V_264 ) ;
}
V_10 += V_145 / sizeof( * V_11 ) ;
V_94 -= V_145 ;
}
F_89 ( & V_286 ) ;
}
static int F_90 ( struct V_23 * V_280 , T_1 V_292 ,
unsigned int V_281 , T_6 V_275 )
{
unsigned int V_293 ;
struct V_9 * V_273 ;
T_1 V_10 ;
for ( V_293 = 0 ; V_293 < V_281 ; V_293 ++ , V_275 ++ ) {
int V_131 ;
V_10 = V_292 + V_293 ;
V_273 = F_4 ( V_10 ) ;
if ( V_273 -> V_294 == F_78 ( 0xffff ) )
continue;
V_131 = F_80 ( V_273 , F_2 ( V_10 ) , V_10 , V_275 ) ;
if ( V_131 ) {
V_295 ++ ;
return V_131 ;
}
}
F_84 ( V_280 , V_292 , V_281 , true ) ;
V_296 ++ ;
return 0 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
struct V_297 * V_298 ;
V_170 V_5 ;
T_6 V_102 ;
T_6 V_275 ;
unsigned long V_299 ;
int V_131 ;
bool V_300 ;
switch ( V_50 [ 0 ] ) {
case V_301 :
V_275 = 0 ;
V_5 = F_92 ( V_50 + 2 ) ;
V_102 = F_52 ( V_50 + 10 ) ;
V_300 = true ;
break;
case V_302 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
V_300 = true ;
break;
case V_303 :
V_275 = 0 ;
V_5 = ( T_6 ) V_50 [ 3 ] | ( T_6 ) V_50 [ 2 ] << 8 |
( T_6 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_102 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_300 = true ;
break;
case V_304 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_52 ( V_50 + 6 ) ;
V_300 = true ;
break;
case V_305 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
V_300 = false ;
break;
default:
V_5 = F_92 ( V_50 + 12 ) ;
V_275 = F_52 ( V_50 + 20 ) ;
V_102 = F_52 ( V_50 + 28 ) ;
V_300 = false ;
break;
}
if ( F_93 ( V_152 && V_300 ) ) {
if ( V_150 == V_279 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_150 == V_277 ||
V_150 == V_151 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_26
L_27 ) ;
}
if ( F_93 ( V_306 ) ) {
V_298 = (struct V_297 * ) V_24 -> V_307 ;
if ( V_298 ) {
if ( V_298 -> V_308 )
V_102 /= 2 ;
}
} else
V_298 = NULL ;
if ( F_93 ( V_5 + V_102 > V_168 ) ) {
F_14 ( V_24 , V_41 , V_260 , 0 ) ;
return V_81 ;
}
if ( F_93 ( V_102 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
if ( F_93 ( ( V_309 & V_215 ) &&
( V_5 <= ( V_310 + V_311 - 1 ) ) &&
( ( V_5 + V_102 ) > V_310 ) ) ) {
F_14 ( V_24 , V_312 , V_313 , 0 ) ;
if ( 0x70 == ( V_24 -> V_33 [ 0 ] & 0x7f ) ) {
V_24 -> V_33 [ 0 ] |= 0x80 ;
V_131 = ( V_5 < V_310 )
? V_310 : ( int ) V_5 ;
F_36 ( V_131 , V_24 -> V_33 + 3 ) ;
}
F_94 ( V_24 , F_26 ( V_24 ) ) ;
return V_81 ;
}
F_95 ( & V_314 , V_299 ) ;
if ( F_93 ( V_315 && F_87 ( V_24 ) ) ) {
int V_316 = F_90 ( V_24 , V_5 , V_102 , V_275 ) ;
if ( V_316 ) {
F_96 ( & V_314 , V_299 ) ;
F_14 ( V_24 , V_317 , 0x10 , V_316 ) ;
return V_318 ;
}
}
V_131 = F_72 ( V_24 , V_5 , V_102 , false ) ;
F_96 ( & V_314 , V_299 ) ;
if ( F_93 ( V_131 == - 1 ) )
return V_90 << 16 ;
F_23 ( V_24 ) -> V_94 = F_26 ( V_24 ) - V_131 ;
if ( F_93 ( V_298 ) ) {
if ( V_298 -> V_319 ) {
F_14 ( V_24 , V_320 ,
V_159 , 0 ) ;
return V_81 ;
} else if ( V_298 -> V_321 ) {
F_14 ( V_24 , V_317 ,
V_322 , V_323 ) ;
return V_81 ;
} else if ( V_298 -> V_324 ) {
F_14 ( V_24 , V_317 , 0x10 , 1 ) ;
return V_318 ;
} else if ( V_298 -> V_325 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_318 ;
}
}
return 0 ;
}
static void F_97 ( unsigned char * V_269 , int V_145 )
{
int V_293 , V_326 , V_130 ;
F_81 ( L_28 ) ;
for ( V_293 = 0 ; V_293 < V_145 ; V_293 += 16 ) {
char V_104 [ 128 ] ;
for ( V_326 = 0 , V_130 = 0 ; V_326 < 16 ; V_326 ++ ) {
unsigned char V_327 = V_269 [ V_293 + V_326 ] ;
if ( V_327 >= 0x20 && V_327 < 0x7e )
V_130 += F_44 ( V_104 + V_130 , sizeof( V_104 ) - V_130 ,
L_29 , V_269 [ V_293 + V_326 ] ) ;
else
V_130 += F_44 ( V_104 + V_130 , sizeof( V_104 ) - V_130 ,
L_30 , V_269 [ V_293 + V_326 ] ) ;
}
F_81 ( L_31 , V_293 , V_104 ) ;
}
}
static int F_98 ( struct V_23 * V_280 , T_1 V_292 ,
unsigned int V_281 , T_6 V_275 )
{
int V_131 ;
struct V_9 * V_273 ;
void * V_328 ;
T_1 V_10 = V_292 ;
int V_329 ;
int V_330 ;
struct V_285 V_331 ;
struct V_285 V_332 ;
F_99 ( F_100 ( V_280 ) == 0 ) ;
F_99 ( F_87 ( V_280 ) == 0 ) ;
F_85 ( & V_332 , F_86 ( V_280 ) ,
F_87 ( V_280 ) ,
V_287 | V_289 ) ;
F_85 ( & V_331 , F_101 ( V_280 ) , F_100 ( V_280 ) ,
V_287 | V_289 ) ;
while ( F_88 ( & V_332 ) ) {
V_330 = 0 ;
if ( F_102 ( ! F_88 ( & V_331 ) ) ) {
V_131 = 0x01 ;
goto V_333;
}
for ( V_329 = 0 ; V_329 < V_332 . V_87 ;
V_329 += sizeof( struct V_9 ) ) {
if ( V_330 >= V_331 . V_87 ) {
if ( F_102 ( ! F_88 ( & V_331 ) ) ) {
V_131 = 0x01 ;
goto V_333;
}
V_330 = 0 ;
}
V_273 = V_332 . V_291 + V_329 ;
V_328 = V_331 . V_291 + V_330 ;
V_131 = F_80 ( V_273 , V_328 , V_10 , V_275 ) ;
if ( V_131 ) {
F_97 ( V_328 , V_8 ) ;
goto V_333;
}
V_10 ++ ;
V_275 ++ ;
V_330 += V_8 ;
}
V_331 . V_334 = V_330 ;
F_89 ( & V_331 ) ;
}
F_89 ( & V_332 ) ;
F_84 ( V_280 , V_292 , V_281 , false ) ;
V_335 ++ ;
return 0 ;
V_333:
V_295 ++ ;
F_89 ( & V_331 ) ;
F_89 ( & V_332 ) ;
return V_131 ;
}
static unsigned long F_103 ( T_1 V_5 )
{
if ( V_123 )
V_5 += V_124 - V_123 ;
F_5 ( V_5 , V_124 ) ;
return V_5 ;
}
static T_1 F_104 ( unsigned long V_336 )
{
T_1 V_5 = V_336 * V_124 ;
if ( V_123 )
V_5 -= V_124 - V_123 ;
return V_5 ;
}
static unsigned int F_105 ( T_1 V_5 , unsigned int * V_102 )
{
T_1 V_337 ;
unsigned int V_338 ;
unsigned long V_336 ;
unsigned long V_339 ;
V_336 = F_103 ( V_5 ) ;
V_338 = F_106 ( V_336 , V_340 ) ;
if ( V_338 )
V_339 = F_107 ( V_340 , V_341 , V_336 ) ;
else
V_339 = F_108 ( V_340 , V_341 , V_336 ) ;
V_337 = F_109 ( T_1 , V_6 , F_104 ( V_339 ) ) ;
* V_102 = V_337 - V_5 ;
return V_338 ;
}
static void F_110 ( T_1 V_5 , unsigned int V_145 )
{
T_1 V_337 = V_5 + V_145 ;
while ( V_5 < V_337 ) {
unsigned long V_336 = F_103 ( V_5 ) ;
if ( V_336 < V_341 )
F_67 ( V_336 , V_340 ) ;
V_5 = F_104 ( V_336 + 1 ) ;
}
}
static void F_111 ( T_1 V_5 , unsigned int V_145 )
{
T_1 V_337 = V_5 + V_145 ;
while ( V_5 < V_337 ) {
unsigned long V_336 = F_103 ( V_5 ) ;
if ( V_5 == F_104 ( V_336 ) &&
V_5 + V_124 <= V_337 &&
V_336 < V_341 ) {
F_18 ( V_336 , V_340 ) ;
if ( V_126 ) {
memset ( V_7 +
V_5 * V_8 ,
( V_126 & 1 ) ? 0 : 0xff ,
V_8 *
V_124 ) ;
}
if ( V_11 ) {
memset ( V_11 + V_5 , 0xff ,
sizeof( * V_11 ) *
V_124 ) ;
}
}
V_5 = F_104 ( V_336 + 1 ) ;
}
}
static int F_112 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
V_170 V_5 ;
T_6 V_102 ;
T_6 V_275 ;
unsigned long V_299 ;
int V_131 ;
bool V_300 ;
switch ( V_50 [ 0 ] ) {
case V_342 :
V_275 = 0 ;
V_5 = F_92 ( V_50 + 2 ) ;
V_102 = F_52 ( V_50 + 10 ) ;
V_300 = true ;
break;
case V_343 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
V_300 = true ;
break;
case V_344 :
V_275 = 0 ;
V_5 = ( T_6 ) V_50 [ 3 ] | ( T_6 ) V_50 [ 2 ] << 8 |
( T_6 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_102 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_300 = true ;
break;
case V_345 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_52 ( V_50 + 6 ) ;
V_300 = true ;
break;
case 0x53 :
V_275 = 0 ;
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
V_300 = false ;
break;
default:
V_5 = F_92 ( V_50 + 12 ) ;
V_275 = F_52 ( V_50 + 20 ) ;
V_102 = F_52 ( V_50 + 28 ) ;
V_300 = false ;
break;
}
if ( F_93 ( V_152 && V_300 ) ) {
if ( V_150 == V_279 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_150 == V_277 ||
V_150 == V_151 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_32
L_27 ) ;
}
if ( F_93 ( V_5 + V_102 > V_168 ) ) {
F_14 ( V_24 , V_41 , V_260 , 0 ) ;
return V_81 ;
}
if ( F_93 ( V_102 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
F_113 ( & V_314 , V_299 ) ;
if ( F_93 ( V_315 && F_87 ( V_24 ) ) ) {
int V_316 = F_98 ( V_24 , V_5 , V_102 , V_275 ) ;
if ( V_316 ) {
F_114 ( & V_314 , V_299 ) ;
F_14 ( V_24 , V_41 , 0x10 , V_316 ) ;
return V_318 ;
}
}
V_131 = F_72 ( V_24 , V_5 , V_102 , true ) ;
if ( F_93 ( F_1 () ) )
F_110 ( V_5 , V_102 ) ;
F_114 ( & V_314 , V_299 ) ;
if ( F_93 ( - 1 == V_131 ) )
return V_90 << 16 ;
else if ( F_93 ( V_42 &&
( V_131 < ( V_102 * V_8 ) ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_33 ,
V_44 , V_102 * V_8 , V_131 ) ;
if ( F_93 ( V_306 ) ) {
struct V_297 * V_298 =
(struct V_297 * ) V_24 -> V_307 ;
if ( V_298 ) {
if ( V_298 -> V_319 ) {
F_14 ( V_24 , V_320 ,
V_159 , 0 ) ;
return V_81 ;
} else if ( V_298 -> V_324 ) {
F_14 ( V_24 , V_317 , 0x10 , 1 ) ;
return V_318 ;
} else if ( V_298 -> V_325 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_318 ;
}
}
}
return 0 ;
}
static int F_115 ( struct V_23 * V_24 , V_170 V_5 , T_6 V_102 ,
T_6 V_275 , bool V_346 , bool V_347 )
{
unsigned long V_299 ;
unsigned long long V_293 ;
int V_131 ;
V_170 V_348 ;
V_131 = F_71 ( V_24 , V_5 , V_102 ) ;
if ( V_131 )
return V_131 ;
F_113 ( & V_314 , V_299 ) ;
if ( V_346 && F_1 () ) {
F_111 ( V_5 , V_102 ) ;
goto V_333;
}
V_348 = V_5 * V_8 ;
if ( V_347 ) {
memset ( V_7 + V_348 , 0 , V_8 ) ;
V_131 = 0 ;
} else
V_131 = F_27 ( V_24 , V_7 + V_348 ,
V_8 ) ;
if ( - 1 == V_131 ) {
F_114 ( & V_314 , V_299 ) ;
return V_90 << 16 ;
} else if ( V_42 && ( V_131 < ( V_102 * V_8 ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_34 ,
V_44 , L_35 ,
V_102 * V_8 , V_131 ) ;
for ( V_293 = 1 ; V_293 < V_102 ; V_293 ++ )
memcpy ( V_7 + ( ( V_5 + V_293 ) * V_8 ) ,
V_7 + V_348 ,
V_8 ) ;
if ( F_1 () )
F_110 ( V_5 , V_102 ) ;
V_333:
F_114 ( & V_314 , V_299 ) ;
return 0 ;
}
static int F_116 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
T_6 V_5 ;
T_5 V_102 ;
T_6 V_275 = 0 ;
bool V_346 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_4 == 0 ) {
F_10 ( V_24 , V_143 , 1 , 3 ) ;
return V_81 ;
} else
V_346 = true ;
}
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
if ( V_102 > V_125 ) {
F_10 ( V_24 , V_143 , 7 , - 1 ) ;
return V_81 ;
}
return F_115 ( V_24 , V_5 , V_102 , V_275 , V_346 , false ) ;
}
static int F_117 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
V_170 V_5 ;
T_6 V_102 ;
T_6 V_275 = 0 ;
bool V_346 = false ;
bool V_347 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_3 == 0 ) {
F_10 ( V_24 , V_143 , 1 , 3 ) ;
return V_81 ;
} else
V_346 = true ;
}
if ( V_50 [ 1 ] & 0x1 )
V_347 = true ;
V_5 = F_92 ( V_50 + 2 ) ;
V_102 = F_52 ( V_50 + 10 ) ;
if ( V_102 > V_125 ) {
F_10 ( V_24 , V_143 , 10 , - 1 ) ;
return V_81 ;
}
return F_115 ( V_24 , V_5 , V_102 , V_275 , V_346 , V_347 ) ;
}
static int F_118 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
struct V_48 * V_349 = V_24 -> V_35 ;
struct V_53 * V_56 ;
T_2 V_350 ;
V_350 = V_50 [ 1 ] & 0x1f ;
switch ( V_350 ) {
case 0x4 :
F_67 ( V_67 , V_54 -> V_59 ) ;
F_67 ( V_74 , V_54 -> V_59 ) ;
break;
case 0x5 :
F_67 ( V_77 , V_54 -> V_59 ) ;
break;
case 0x6 :
F_8 (dp,
&devip->sdbg_host->dev_info_list,
dev_list)
if ( V_56 -> V_57 == V_349 -> V_231 ) {
F_67 ( V_67 , V_56 -> V_59 ) ;
if ( V_54 != V_56 )
F_67 ( V_74 ,
V_56 -> V_59 ) ;
}
break;
case 0x7 :
F_8 (dp,
&devip->sdbg_host->dev_info_list,
dev_list)
if ( V_56 -> V_57 == V_349 -> V_231 )
F_67 ( V_77 ,
V_56 -> V_59 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_119 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
T_2 * V_82 ;
T_2 * V_351 ;
V_170 V_5 ;
T_6 V_352 ;
T_6 V_268 = V_8 ;
T_2 V_102 ;
unsigned long V_299 ;
int V_131 ;
int V_353 = 0 ;
V_5 = F_92 ( V_50 + 2 ) ;
V_102 = V_50 [ 13 ] ;
if ( 0 == V_102 )
return 0 ;
if ( V_150 == V_279 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_150 == V_277 ||
V_150 == V_151 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_32
L_27 ) ;
if ( V_5 + V_102 > V_168 ) {
F_14 ( V_24 , V_41 , V_260 , 0 ) ;
return V_81 ;
}
if ( V_102 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
V_352 = 2 * V_102 ;
V_82 = F_41 ( V_352 * V_268 , V_135 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
F_113 ( & V_314 , V_299 ) ;
V_351 = V_7 ;
V_7 = V_82 ;
V_131 = F_72 ( V_24 , 0 , V_352 , true ) ;
V_7 = V_351 ;
if ( V_131 == - 1 ) {
V_353 = V_90 << 16 ;
goto V_354;
} else if ( V_42 && ( V_131 < ( V_352 * V_268 ) ) )
F_11 ( V_43 , V_24 -> V_35 , L_36
L_37 , V_44 ,
V_352 * V_268 , V_131 ) ;
if ( ! F_75 ( V_5 , V_102 , V_82 ) ) {
F_14 ( V_24 , V_355 , V_356 , 0 ) ;
V_353 = V_81 ;
goto V_354;
}
if ( F_1 () )
F_110 ( V_5 , V_102 ) ;
V_354:
F_114 ( & V_314 , V_299 ) ;
F_43 ( V_82 ) ;
return V_353 ;
}
static int F_120 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char * V_269 ;
struct V_357 * V_358 ;
unsigned int V_293 , V_359 , V_360 ;
int V_131 ;
unsigned long V_299 ;
if ( ! F_1 () )
return 0 ;
V_359 = F_40 ( V_24 -> V_128 + 7 ) ;
F_99 ( F_26 ( V_24 ) != V_359 ) ;
V_360 = ( V_359 - 8 ) / 16 ;
if ( V_360 > V_122 ) {
F_10 ( V_24 , V_143 , 7 , - 1 ) ;
return V_81 ;
}
V_269 = F_41 ( F_26 ( V_24 ) , V_135 ) ;
if ( ! V_269 ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
F_28 ( V_24 , V_269 , F_26 ( V_24 ) ) ;
F_99 ( F_40 ( & V_269 [ 0 ] ) != V_359 - 2 ) ;
F_99 ( F_40 ( & V_269 [ 2 ] ) != V_360 * 16 ) ;
V_358 = ( void * ) & V_269 [ 8 ] ;
F_113 ( & V_314 , V_299 ) ;
for ( V_293 = 0 ; V_293 < V_360 ; V_293 ++ ) {
unsigned long long V_5 = F_92 ( & V_358 [ V_293 ] . V_5 ) ;
unsigned int V_102 = F_52 ( & V_358 [ V_293 ] . V_361 ) ;
V_131 = F_71 ( V_24 , V_5 , V_102 ) ;
if ( V_131 )
goto V_333;
F_111 ( V_5 , V_102 ) ;
}
V_131 = 0 ;
V_333:
F_114 ( & V_314 , V_299 ) ;
F_43 ( V_269 ) ;
return V_131 ;
}
static int F_121 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
V_170 V_5 ;
T_6 V_129 , V_338 , V_102 ;
T_2 V_82 [ V_362 ] ;
int V_131 ;
V_5 = F_92 ( V_50 + 2 ) ;
V_129 = F_52 ( V_50 + 10 ) ;
if ( V_129 < 24 )
return 0 ;
V_131 = F_71 ( V_24 , V_5 , 1 ) ;
if ( V_131 )
return V_131 ;
if ( F_1 () )
V_338 = F_105 ( V_5 , & V_102 ) ;
else {
V_338 = 1 ;
V_168 = F_49 () ;
if ( V_168 - V_5 <= 0xffffffff )
V_102 = V_168 - V_5 ;
else
V_102 = 0xffffffff ;
}
memset ( V_82 , 0 , V_362 ) ;
F_36 ( 20 , V_82 ) ;
F_30 ( V_5 , V_82 + 8 ) ;
F_36 ( V_102 , V_82 + 16 ) ;
V_82 [ 20 ] = ! V_338 ;
return F_22 ( V_24 , V_82 , V_362 ) ;
}
static int F_122 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_128 ;
unsigned int V_129 ;
unsigned char V_363 ;
V_170 V_139 ;
struct V_364 * V_365 ;
T_2 * V_82 ;
unsigned int V_366 ;
unsigned int V_367 ;
unsigned int V_368 ;
unsigned int V_173 ;
int V_293 , V_248 ;
F_17 ( V_54 ) ;
V_363 = V_50 [ 2 ] ;
V_129 = F_52 ( V_50 + 6 ) ;
if ( V_129 < 4 ) {
F_81 ( L_38 , V_129 ) ;
F_10 ( V_24 , V_143 , 6 , - 1 ) ;
return V_81 ;
}
switch ( V_363 ) {
case 0 :
V_366 = V_369 ;
V_367 = 0 ;
break;
case 1 :
V_366 = 0 ;
V_367 = 1 ;
break;
case 2 :
V_366 = V_369 ;
V_367 = 1 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
default:
F_123 ( L_39 , V_363 ) ;
F_10 ( V_24 , V_143 , 2 , - 1 ) ;
return V_81 ;
}
if ( V_141 && ( V_366 > 0 ) )
-- V_366 ;
V_368 = V_366 + V_367 ;
V_173 = ( V_368 * sizeof( struct V_364 ) ) + 8 ;
V_82 = F_124 ( V_173 ) ;
if ( ! V_82 ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
memset ( V_82 , 0 , V_173 ) ;
F_123 ( L_40 ,
V_363 , V_366 , V_367 , V_141 ) ;
V_365 = (struct V_364 * ) & V_82 [ 8 ] ;
V_139 = V_141 ? 1 : 0 ;
for ( V_293 = 0 ; V_293 < V_366 ; V_293 ++ )
F_125 ( V_139 ++ , V_365 ++ ) ;
if ( V_367 )
F_125 ( V_22 , V_365 ++ ) ;
F_36 ( V_173 - 8 , & V_82 [ 0 ] ) ;
V_248 = F_22 ( V_24 , V_82 , V_173 ) ;
F_126 ( V_82 ) ;
return V_248 ;
}
static int F_127 ( struct V_23 * V_24 , unsigned long long V_5 ,
unsigned int V_102 , struct V_53 * V_54 )
{
int V_326 ;
unsigned char * V_370 , * V_269 ;
unsigned int V_185 ;
struct V_85 * V_86 = F_23 ( V_24 ) ;
struct V_285 V_286 ;
V_269 = F_41 ( F_26 ( V_24 ) , V_135 ) ;
if ( ! V_269 ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
F_28 ( V_24 , V_269 , F_26 ( V_24 ) ) ;
V_185 = 0 ;
F_85 ( & V_286 , V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_287 | V_288 ) ;
while ( F_88 ( & V_286 ) ) {
V_370 = V_286 . V_291 ;
for ( V_326 = 0 ; V_326 < V_286 . V_87 ; V_326 ++ )
* ( V_370 + V_326 ) ^= * ( V_269 + V_185 + V_326 ) ;
V_185 += V_286 . V_87 ;
}
F_89 ( & V_286 ) ;
F_43 ( V_269 ) ;
return 0 ;
}
static int F_128 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_128 ;
V_170 V_5 ;
T_6 V_102 ;
int V_186 ;
if ( ! F_24 ( V_24 ) ) {
F_14 ( V_24 , V_41 , V_193 ,
V_194 ) ;
return V_81 ;
}
V_186 = F_91 ( V_24 , V_54 ) ;
if ( V_186 )
return V_186 ;
if ( ! ( V_50 [ 1 ] & 0x4 ) ) {
V_186 = F_112 ( V_24 , V_54 ) ;
if ( V_186 )
return V_186 ;
}
V_5 = F_52 ( V_50 + 2 ) ;
V_102 = F_40 ( V_50 + 7 ) ;
return F_127 ( V_24 , V_5 , V_102 , V_54 ) ;
}
static struct V_371 * F_129 ( struct V_23 * V_128 )
{
struct V_371 * V_372 = V_373 ;
if ( V_374 ) {
T_6 V_375 = F_130 ( V_128 -> V_376 ) ;
T_5 V_377 = F_131 ( V_375 ) ;
if ( F_93 ( V_377 >= V_378 ) ) {
F_21 ( L_41 , V_377 ) ;
V_377 %= V_378 ;
}
F_123 ( L_42 , V_375 , V_377 ) ;
return V_372 + V_377 ;
} else
return V_372 ;
}
static void F_132 ( struct V_379 * V_380 )
{
int V_381 ;
int V_382 = 0 ;
unsigned long V_299 ;
struct V_371 * V_372 ;
struct V_297 * V_298 ;
struct V_23 * V_24 ;
struct V_53 * V_54 ;
V_381 = V_380 -> V_381 ;
V_372 = V_373 + V_380 -> V_383 ;
if ( V_384 ) {
F_133 ( & V_385 ) ;
if ( F_134 () != V_380 -> V_386 )
F_133 ( & V_387 ) ;
}
if ( F_93 ( ( V_381 < 0 ) || ( V_381 >= V_388 ) ) ) {
F_81 ( L_43 , V_381 ) ;
return;
}
F_135 ( & V_372 -> V_389 , V_299 ) ;
V_298 = & V_372 -> V_390 [ V_381 ] ;
V_24 = V_298 -> V_391 ;
if ( F_93 ( V_24 == NULL ) ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
F_81 ( L_44 ,
V_380 -> V_383 , V_381 ) ;
return;
}
V_54 = (struct V_53 * ) V_24 -> V_35 -> V_392 ;
if ( F_137 ( V_54 ) )
F_138 ( & V_54 -> V_393 ) ;
else
F_81 ( L_45 ) ;
if ( F_93 ( F_139 ( & V_394 ) > 0 ) )
V_382 = 1 ;
V_298 -> V_391 = NULL ;
if ( F_93 ( ! F_140 ( V_381 , V_372 -> V_395 ) ) ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
F_81 ( L_46 ) ;
return;
}
if ( F_93 ( V_382 ) ) {
int V_60 , V_353 ;
V_353 = F_139 ( & V_394 ) ;
if ( V_381 >= V_353 ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
F_81 ( L_47 , V_353 ) ;
return;
}
V_60 = F_141 ( V_372 -> V_395 , V_353 ) ;
if ( ( V_60 < V_396 ) || ( V_60 == V_353 ) )
F_142 ( & V_394 , 0 ) ;
else
F_142 ( & V_394 , V_60 + 1 ) ;
}
F_136 ( & V_372 -> V_389 , V_299 ) ;
V_24 -> V_397 ( V_24 ) ;
}
static enum V_398 F_143 ( struct V_399 * V_400 )
{
struct V_379 * V_380 = F_144 ( V_400 , struct V_379 ,
V_401 ) ;
F_132 ( V_380 ) ;
return V_402 ;
}
static void F_145 ( struct V_403 * V_404 )
{
struct V_379 * V_380 = F_144 ( V_404 , struct V_379 ,
V_405 . V_404 ) ;
F_132 ( V_380 ) ;
}
static struct V_53 * F_146 (
struct V_12 * V_13 , T_9 V_198 )
{
struct V_53 * V_54 ;
V_54 = F_41 ( sizeof( * V_54 ) , V_198 ) ;
if ( V_54 ) {
if ( V_107 == 1 )
F_147 ( & V_54 -> V_101 ) ;
else if ( V_107 == 2 ) {
if ( V_406 )
V_54 -> V_101 = V_407 ;
else {
F_147 ( & V_407 ) ;
V_406 = true ;
V_54 -> V_101 = V_407 ;
}
}
V_54 -> V_13 = V_13 ;
F_148 ( & V_54 -> V_408 , & V_13 -> V_409 ) ;
}
return V_54 ;
}
static struct V_53 * F_149 ( struct V_48 * V_410 )
{
struct V_12 * V_13 ;
struct V_53 * V_411 = NULL ;
struct V_53 * V_54 ;
V_13 = * (struct V_12 * * ) F_150 ( V_410 -> V_412 ) ;
if ( ! V_13 ) {
F_81 ( L_48 ) ;
return NULL ;
}
F_8 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_54 -> V_413 ) && ( V_54 -> V_148 == V_410 -> V_148 ) &&
( V_54 -> V_57 == V_410 -> V_231 ) &&
( V_54 -> V_139 == V_410 -> V_139 ) )
return V_54 ;
else {
if ( ( ! V_54 -> V_413 ) && ( ! V_411 ) )
V_411 = V_54 ;
}
}
if ( ! V_411 ) {
V_411 = F_146 ( V_13 , V_135 ) ;
if ( ! V_411 ) {
F_81 ( L_49 , __LINE__ ) ;
return NULL ;
}
}
V_411 -> V_148 = V_410 -> V_148 ;
V_411 -> V_57 = V_410 -> V_231 ;
V_411 -> V_139 = V_410 -> V_139 ;
V_411 -> V_13 = V_13 ;
F_142 ( & V_411 -> V_393 , 0 ) ;
F_67 ( V_63 , V_411 -> V_59 ) ;
V_411 -> V_413 = true ;
return V_411 ;
}
static int F_151 ( struct V_48 * V_349 )
{
if ( V_42 )
F_152 ( L_50 ,
V_349 -> V_412 -> V_147 , V_349 -> V_148 , V_349 -> V_231 , V_349 -> V_139 ) ;
F_153 ( V_414 , V_349 -> V_415 ) ;
return 0 ;
}
static int F_154 ( struct V_48 * V_349 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_349 -> V_392 ;
if ( V_42 )
F_152 ( L_51 ,
V_349 -> V_412 -> V_147 , V_349 -> V_148 , V_349 -> V_231 , V_349 -> V_139 ) ;
if ( V_349 -> V_412 -> V_416 != V_417 )
V_349 -> V_412 -> V_416 = V_417 ;
if ( V_54 == NULL ) {
V_54 = F_149 ( V_349 ) ;
if ( V_54 == NULL )
return 1 ;
}
V_349 -> V_392 = V_54 ;
F_155 ( V_349 -> V_415 , - 1U ) ;
if ( V_418 )
V_349 -> V_419 = 1 ;
return 0 ;
}
static void F_156 ( struct V_48 * V_349 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_349 -> V_392 ;
if ( V_42 )
F_152 ( L_52 ,
V_349 -> V_412 -> V_147 , V_349 -> V_148 , V_349 -> V_231 , V_349 -> V_139 ) ;
if ( V_54 ) {
V_54 -> V_413 = false ;
V_349 -> V_392 = NULL ;
}
}
static void F_157 ( struct V_379 * V_380 )
{
if ( ! V_380 )
return;
if ( ( V_420 > 0 ) || ( V_421 > 0 ) )
F_158 ( & V_380 -> V_401 ) ;
else if ( V_420 < 0 )
F_159 ( & V_380 -> V_405 . V_404 ) ;
}
static bool F_160 ( struct V_23 * V_128 )
{
unsigned long V_299 ;
int V_326 , V_60 , V_422 , V_423 ;
struct V_371 * V_372 ;
struct V_297 * V_298 ;
struct V_53 * V_54 ;
struct V_379 * V_380 ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ; ++ V_326 , ++ V_372 ) {
F_135 ( & V_372 -> V_389 , V_299 ) ;
V_422 = V_396 ;
V_423 = F_139 ( & V_394 ) ;
if ( V_423 > V_422 )
V_422 = V_423 ;
for ( V_60 = 0 ; V_60 < V_422 ; ++ V_60 ) {
if ( F_106 ( V_60 , V_372 -> V_395 ) ) {
V_298 = & V_372 -> V_390 [ V_60 ] ;
if ( V_128 != V_298 -> V_391 )
continue;
V_54 = (struct V_53 * )
V_128 -> V_35 -> V_392 ;
if ( V_54 )
F_138 ( & V_54 -> V_393 ) ;
V_298 -> V_391 = NULL ;
V_380 = V_298 -> V_380 ;
F_136 ( & V_372 -> V_389 , V_299 ) ;
F_157 ( V_380 ) ;
F_18 ( V_60 , V_372 -> V_395 ) ;
return true ;
}
}
F_136 ( & V_372 -> V_389 , V_299 ) ;
}
return false ;
}
static void F_161 ( void )
{
unsigned long V_299 ;
int V_326 , V_60 ;
struct V_371 * V_372 ;
struct V_297 * V_298 ;
struct V_53 * V_54 ;
struct V_379 * V_380 ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ; ++ V_326 , ++ V_372 ) {
F_135 ( & V_372 -> V_389 , V_299 ) ;
for ( V_60 = 0 ; V_60 < V_388 ; ++ V_60 ) {
if ( F_106 ( V_60 , V_372 -> V_395 ) ) {
V_298 = & V_372 -> V_390 [ V_60 ] ;
if ( V_298 -> V_391 == NULL )
continue;
V_54 = (struct V_53 * )
V_298 -> V_391 -> V_35 -> V_392 ;
if ( V_54 )
F_138 ( & V_54 -> V_393 ) ;
V_298 -> V_391 = NULL ;
V_380 = V_298 -> V_380 ;
F_136 ( & V_372 -> V_389 , V_299 ) ;
F_157 ( V_380 ) ;
F_18 ( V_60 , V_372 -> V_395 ) ;
F_135 ( & V_372 -> V_389 , V_299 ) ;
}
}
F_136 ( & V_372 -> V_389 , V_299 ) ;
}
}
static void F_162 ( void )
{
int V_326 , V_60 ;
struct V_371 * V_372 ;
struct V_297 * V_298 ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ; ++ V_326 , ++ V_372 ) {
for ( V_60 = 0 ; V_60 < V_388 ; ++ V_60 ) {
V_298 = & V_372 -> V_390 [ V_60 ] ;
F_43 ( V_298 -> V_380 ) ;
V_298 -> V_380 = NULL ;
}
}
}
static int F_163 ( struct V_23 * V_280 )
{
bool V_424 ;
++ V_425 ;
if ( V_280 ) {
V_424 = F_160 ( V_280 ) ;
if ( V_280 -> V_35 && ( V_426 & V_215 ) )
F_11 ( V_43 , V_280 -> V_35 ,
L_53 , V_36 ,
V_424 ? L_54 : L_55 ) ;
}
return V_427 ;
}
static int F_164 ( struct V_23 * V_280 )
{
++ V_428 ;
if ( V_280 && V_280 -> V_35 ) {
struct V_48 * V_349 = V_280 -> V_35 ;
struct V_53 * V_54 =
(struct V_53 * ) V_349 -> V_392 ;
if ( V_426 & V_215 )
F_11 ( V_43 , V_349 , L_56 , V_36 ) ;
if ( V_54 )
F_67 ( V_63 , V_54 -> V_59 ) ;
}
return V_427 ;
}
static int F_165 ( struct V_23 * V_280 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_349 ;
struct V_14 * V_429 ;
int V_60 = 0 ;
++ V_430 ;
if ( ! V_280 )
goto V_431;
V_349 = V_280 -> V_35 ;
if ( ! V_349 )
goto V_431;
if ( V_426 & V_215 )
F_11 ( V_43 , V_349 , L_56 , V_36 ) ;
V_429 = V_349 -> V_412 ;
if ( ! V_429 )
goto V_431;
V_13 = * (struct V_12 * * ) F_150 ( V_429 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list)
if ( V_54 -> V_57 == V_349 -> V_231 ) {
F_67 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
if ( V_432 & V_215 )
F_11 ( V_43 , V_349 ,
L_57 , V_36 , V_60 ) ;
V_431:
return V_427 ;
}
static int F_166 ( struct V_23 * V_280 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_349 ;
struct V_14 * V_429 ;
int V_60 = 0 ;
++ V_433 ;
if ( ! ( V_280 && V_280 -> V_35 ) )
goto V_431;
V_349 = V_280 -> V_35 ;
if ( V_426 & V_215 )
F_11 ( V_43 , V_349 , L_56 , V_36 ) ;
V_429 = V_349 -> V_412 ;
if ( V_429 ) {
V_13 = * (struct V_12 * * ) F_150 ( V_429 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list) {
F_67 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
}
if ( V_432 & V_215 )
F_11 ( V_43 , V_349 ,
L_58 , V_36 , V_60 ) ;
V_431:
return V_427 ;
}
static int F_167 ( struct V_23 * V_280 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
int V_60 = 0 ;
++ V_434 ;
if ( ( V_280 -> V_35 ) && ( V_426 & V_215 ) )
F_11 ( V_43 , V_280 -> V_35 , L_56 , V_36 ) ;
F_7 ( & V_16 ) ;
F_8 (sdbg_host, &sdebug_host_list, host_list) {
F_8 (devip, &sdbg_host->dev_info_list,
dev_list) {
F_67 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
F_9 ( & V_16 ) ;
F_161 () ;
if ( V_432 & V_215 )
F_11 ( V_43 , V_280 -> V_35 ,
L_59 , V_36 , V_60 ) ;
return V_427 ;
}
static void T_10 F_168 ( unsigned char * V_435 ,
unsigned long V_436 )
{
struct V_437 * V_438 ;
int V_439 [ V_440 + 2 ] ;
int V_441 , V_442 , V_60 ;
int V_443 , V_292 , V_444 ;
if ( ( V_445 < 1 ) || ( V_436 < 1048576 ) )
return;
if ( V_445 > V_440 ) {
V_445 = V_440 ;
F_21 ( L_60 , V_440 ) ;
}
V_442 = ( int ) V_6 ;
V_441 = ( V_442 - V_211 )
/ V_445 ;
V_443 = V_446 * V_211 ;
V_439 [ 0 ] = V_211 ;
for ( V_60 = 1 ; V_60 < V_445 ; ++ V_60 )
V_439 [ V_60 ] = ( ( V_60 * V_441 ) / V_443 )
* V_443 ;
V_439 [ V_445 ] = V_442 ;
V_439 [ V_445 + 1 ] = 0 ;
V_435 [ 510 ] = 0x55 ;
V_435 [ 511 ] = 0xAA ;
V_438 = (struct V_437 * ) ( V_435 + 0x1be ) ;
for ( V_60 = 0 ; V_439 [ V_60 + 1 ] ; ++ V_60 , ++ V_438 ) {
V_292 = V_439 [ V_60 ] ;
V_444 = V_439 [ V_60 + 1 ] - 1 ;
V_438 -> V_447 = 0 ;
V_438 -> V_448 = V_292 / V_443 ;
V_438 -> V_449 = ( V_292 - ( V_438 -> V_448 * V_443 ) )
/ V_211 ;
V_438 -> V_10 = ( V_292 % V_211 ) + 1 ;
V_438 -> V_450 = V_444 / V_443 ;
V_438 -> V_451 = ( V_444 - ( V_438 -> V_450 * V_443 ) )
/ V_211 ;
V_438 -> V_452 = ( V_444 % V_211 ) + 1 ;
V_438 -> V_453 = F_169 ( V_292 ) ;
V_438 -> V_454 = F_169 ( V_444 - V_292 + 1 ) ;
V_438 -> V_455 = 0x83 ;
}
}
static void F_170 ( bool V_263 )
{
int V_326 ;
struct V_371 * V_372 ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ; ++ V_326 , ++ V_372 )
F_142 ( & V_372 -> V_456 , ( int ) V_263 ) ;
}
static void F_171 ( void )
{
int V_187 , V_457 ;
V_457 = abs ( V_458 ) ;
if ( V_457 < 2 )
return;
F_170 ( true ) ;
V_187 = F_139 ( & V_459 ) ;
F_142 ( & V_459 , ( V_187 / V_457 ) * V_457 ) ;
F_170 ( false ) ;
}
static void F_172 ( void )
{
F_142 ( & V_459 , 0 ) ;
F_142 ( & V_385 , 0 ) ;
F_142 ( & V_387 , 0 ) ;
F_142 ( & V_460 , 0 ) ;
}
static void F_173 ( struct V_371 * V_372 ,
struct V_297 * V_298 )
{
if ( ( F_139 ( & V_459 ) % abs ( V_458 ) ) > 0 )
return;
V_298 -> V_319 = ! ! ( V_461 & V_215 ) ;
V_298 -> V_321 = ! ! ( V_462 & V_215 ) ;
V_298 -> V_324 = ! ! ( V_463 & V_215 ) ;
V_298 -> V_325 = ! ! ( V_464 & V_215 ) ;
V_298 -> V_308 = ! ! ( V_465 & V_215 ) ;
}
static int F_174 ( struct V_23 * V_128 , struct V_53 * V_54 ,
int V_466 , int V_467 )
{
unsigned long V_299 ;
int V_60 , V_393 , V_468 , V_469 ;
struct V_371 * V_372 ;
struct V_297 * V_298 ;
struct V_48 * V_349 ;
struct V_379 * V_380 ;
if ( F_93 ( V_54 == NULL ) ) {
if ( V_466 == 0 )
V_466 = V_470 << 16 ;
goto V_471;
}
V_349 = V_128 -> V_35 ;
if ( F_93 ( V_42 && V_466 ) )
F_11 ( V_43 , V_349 , L_61 ,
V_36 , V_466 ) ;
if ( V_467 == 0 )
goto V_471;
V_372 = F_129 ( V_128 ) ;
F_135 ( & V_372 -> V_389 , V_299 ) ;
if ( F_93 ( F_139 ( & V_372 -> V_456 ) ) ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
return V_472 ;
}
V_393 = F_139 ( & V_54 -> V_393 ) ;
V_468 = V_128 -> V_35 -> V_473 ;
V_469 = 0 ;
if ( F_93 ( ( V_468 > 0 ) && ( V_393 >= V_468 ) ) ) {
if ( V_466 ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
goto V_471;
} else
V_466 = V_474 ;
} else if ( F_93 ( V_458 &&
( V_475 & V_215 ) &&
( V_466 == 0 ) ) ) {
if ( ( V_393 == ( V_468 - 1 ) ) &&
( F_175 ( & V_460 ) >=
abs ( V_458 ) ) ) {
F_142 ( & V_460 , 0 ) ;
V_469 = 1 ;
V_466 = V_474 ;
}
}
V_60 = F_176 ( V_372 -> V_395 , V_396 ) ;
if ( F_93 ( V_60 >= V_396 ) ) {
F_136 ( & V_372 -> V_389 , V_299 ) ;
if ( V_466 )
goto V_471;
else if ( V_476 & V_215 )
V_466 = V_474 ;
if ( V_477 & V_215 )
F_11 ( V_43 , V_349 ,
L_62 ,
V_36 , V_396 ,
( V_466 ? L_63 :
L_64 ) ) ;
if ( V_466 )
goto V_471;
else
return V_472 ;
}
F_177 ( V_60 , V_372 -> V_395 ) ;
F_133 ( & V_54 -> V_393 ) ;
V_298 = & V_372 -> V_390 [ V_60 ] ;
V_298 -> V_391 = V_128 ;
V_128 -> V_307 = ( unsigned char * ) V_298 ;
V_128 -> V_478 = V_466 ;
V_380 = V_298 -> V_380 ;
F_136 ( & V_372 -> V_389 , V_299 ) ;
if ( F_93 ( V_458 && V_306 ) )
F_173 ( V_372 , V_298 ) ;
if ( V_467 > 0 || V_421 > 0 ) {
T_11 V_479 ;
if ( V_467 > 0 ) {
struct V_480 V_481 ;
F_178 ( V_467 , & V_481 ) ;
V_479 = F_179 ( V_481 . V_482 , V_481 . V_483 ) ;
} else
V_479 = F_179 ( 0 , V_421 ) ;
if ( NULL == V_380 ) {
V_380 = F_41 ( sizeof( * V_380 ) , V_135 ) ;
if ( NULL == V_380 )
return V_472 ;
V_298 -> V_380 = V_380 ;
F_180 ( & V_380 -> V_401 , V_484 ,
V_485 ) ;
V_380 -> V_401 . V_486 = F_143 ;
V_380 -> V_383 = V_372 - V_373 ;
V_380 -> V_381 = V_60 ;
}
if ( V_384 )
V_380 -> V_386 = F_134 () ;
F_181 ( & V_380 -> V_401 , V_479 , V_485 ) ;
} else {
if ( NULL == V_380 ) {
V_380 = F_41 ( sizeof( * V_298 -> V_380 ) , V_135 ) ;
if ( NULL == V_380 )
return V_472 ;
V_298 -> V_380 = V_380 ;
V_380 -> V_383 = V_372 - V_373 ;
V_380 -> V_381 = V_60 ;
F_182 ( & V_380 -> V_405 . V_404 , F_145 ) ;
}
if ( V_384 )
V_380 -> V_386 = F_134 () ;
F_183 ( & V_380 -> V_405 . V_404 ) ;
}
if ( F_93 ( ( V_477 & V_215 ) &&
( V_466 == V_474 ) ) )
F_11 ( V_43 , V_349 ,
L_65 , V_36 ,
V_393 , ( V_469 ? L_66 : L_54 ) ,
L_63 ) ;
return 0 ;
V_471:
V_128 -> V_478 = V_466 ;
V_128 -> V_397 ( V_128 ) ;
return 0 ;
}
static const char * F_184 ( struct V_14 * V_487 )
{
int V_60 ;
V_60 = F_44 ( V_488 , V_489 , L_67 ,
V_44 , V_490 , V_491 ) ;
if ( V_60 >= ( V_489 - 1 ) )
return V_488 ;
F_44 ( V_488 + V_60 , V_489 - V_60 ,
L_68 ,
V_492 , V_215 , V_378 ,
L_69 , ( int ) V_384 ) ;
return V_488 ;
}
static int F_185 ( struct V_14 * V_412 , char * V_493 ,
int V_87 )
{
char V_82 [ 16 ] ;
int V_494 ;
int V_495 = V_87 > 15 ? 15 : V_87 ;
if ( ! F_186 ( V_496 ) || ! F_186 ( V_497 ) )
return - V_498 ;
memcpy ( V_82 , V_493 , V_495 ) ;
V_82 [ V_495 ] = '\0' ;
if ( 1 != sscanf ( V_82 , L_22 , & V_494 ) )
return - V_52 ;
V_215 = V_494 ;
V_42 = ! ! ( V_499 & V_494 ) ;
V_306 = ! ! ( V_500 & V_494 ) ;
if ( V_458 != 0 )
F_171 () ;
return V_87 ;
}
static int F_187 ( struct V_501 * V_502 , struct V_14 * V_412 )
{
int V_503 , V_326 , V_504 ;
struct V_371 * V_372 ;
F_188 ( V_502 , L_70 ,
V_490 , V_491 ) ;
F_188 ( V_502 , L_71 ,
V_19 , L_72 , V_492 ,
V_215 , V_458 ) ;
F_188 ( V_502 , L_73 ,
V_420 , V_421 , V_369 ,
V_8 , L_74 ) ;
F_188 ( V_502 , L_75 ,
V_505 , V_446 , V_211 ,
V_425 ) ;
F_188 ( V_502 , L_76 ,
V_428 , V_430 , V_433 ,
V_434 ) ;
F_188 ( V_502 , L_77 ,
V_296 , V_335 , V_295 ) ;
F_188 ( V_502 , L_78 ,
V_506 / 1000 , L_69 , V_384 ,
V_374 ) ;
F_188 ( V_502 , L_79 ,
F_139 ( & V_459 ) ,
F_139 ( & V_385 ) ,
L_80 , F_139 ( & V_387 ) ,
F_139 ( & V_460 ) ) ;
F_188 ( V_502 , L_81 , V_378 ) ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ; ++ V_326 , ++ V_372 ) {
F_188 ( V_502 , L_82 , V_326 ) ;
V_503 = F_20 ( V_372 -> V_395 , V_396 ) ;
if ( V_503 != V_396 ) {
V_504 = F_141 ( V_372 -> V_395 , V_396 ) ;
F_188 ( V_502 , L_83 ,
L_84 , V_503 , V_504 ) ;
}
}
return 0 ;
}
static T_12 F_189 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_420 ) ;
}
static T_12 F_190 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_510 , V_248 ;
if ( V_187 > 0 && sscanf ( V_269 , L_22 , & V_510 ) == 1 ) {
V_248 = V_187 ;
if ( V_420 != V_510 ) {
int V_326 , V_60 ;
struct V_371 * V_372 ;
F_170 ( true ) ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ;
++ V_326 , ++ V_372 ) {
V_60 = F_20 ( V_372 -> V_395 ,
V_396 ) ;
if ( V_60 != V_396 ) {
V_248 = - V_511 ;
break;
}
}
if ( V_248 > 0 ) {
F_162 () ;
V_420 = V_510 ;
V_421 = 0 ;
}
F_170 ( false ) ;
}
return V_248 ;
}
return - V_52 ;
}
static T_12 F_191 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_421 ) ;
}
static T_12 F_192 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_512 , V_248 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_512 ) ) &&
( V_512 >= 0 ) && ( V_512 < ( 1000 * 1000 * 1000 ) ) ) {
V_248 = V_187 ;
if ( V_421 != V_512 ) {
int V_326 , V_60 ;
struct V_371 * V_372 ;
F_170 ( true ) ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ;
++ V_326 , ++ V_372 ) {
V_60 = F_20 ( V_372 -> V_395 ,
V_396 ) ;
if ( V_60 != V_396 ) {
V_248 = - V_511 ;
break;
}
}
if ( V_248 > 0 ) {
F_162 () ;
V_421 = V_512 ;
V_420 = V_512 ? V_513
: V_514 ;
}
F_170 ( false ) ;
}
return V_248 ;
}
return - V_52 ;
}
static T_12 F_193 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_86 , V_215 ) ;
}
static T_12 F_194 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_494 ;
char V_404 [ 20 ] ;
if ( 1 == sscanf ( V_269 , L_87 , V_404 ) ) {
if ( 0 == strncasecmp ( V_404 , L_88 , 2 ) ) {
if ( 1 == sscanf ( & V_404 [ 2 ] , L_89 , & V_494 ) )
goto V_515;
} else {
if ( 1 == sscanf ( V_404 , L_22 , & V_494 ) )
goto V_515;
}
}
return - V_52 ;
V_515:
V_215 = V_494 ;
V_42 = ! ! ( V_499 & V_494 ) ;
V_306 = ! ! ( V_500 & V_494 ) ;
F_171 () ;
return V_187 ;
}
static T_12 F_195 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_137 ) ;
}
static T_12 F_196 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_137 = V_130 ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_197 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_40 ) ;
}
static T_12 F_198 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_40 = V_130 ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_199 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_1 ) ;
}
static T_12 F_200 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_130 = ( V_130 > 0 ) ;
V_1 = ( V_1 > 0 ) ;
if ( V_1 != V_130 ) {
if ( ( 0 == V_130 ) && ( NULL == V_7 ) ) {
unsigned long V_516 =
( unsigned long ) V_492 *
1048576 ;
V_7 = F_124 ( V_516 ) ;
if ( NULL == V_7 ) {
F_81 ( L_90 ) ;
return - V_517 ;
}
memset ( V_7 , 0 , V_516 ) ;
}
V_1 = V_130 ;
}
return V_187 ;
}
return - V_52 ;
}
static T_12 F_201 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_141 ) ;
}
static T_12 F_202 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_141 = V_130 ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_203 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_19 ) ;
}
static T_12 F_204 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_19 = V_130 ;
F_6 () ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_205 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_492 ) ;
}
static T_12 F_206 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_445 ) ;
}
static T_12 F_207 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_458 ) ;
}
static T_12 F_208 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_518 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_518 ) ) ) {
V_458 = V_518 ;
if ( V_518 && ! V_384 ) {
F_152 ( L_91 ) ;
V_384 = true ;
}
F_171 () ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_209 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_369 ) ;
}
static T_12 F_210 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
bool V_519 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
if ( V_130 > 256 ) {
F_21 ( L_92 ) ;
return - V_52 ;
}
V_519 = ( V_369 != V_130 ) ;
V_369 = V_130 ;
F_6 () ;
if ( V_519 && ( V_79 >= 5 ) ) {
struct V_12 * V_55 ;
struct V_53 * V_56 ;
F_7 ( & V_16 ) ;
F_8 (sdhp, &sdebug_host_list,
host_list) {
F_8 (dp, &sdhp->dev_info_list,
dev_list) {
F_67 ( V_58 ,
V_56 -> V_59 ) ;
}
}
F_9 ( & V_16 ) ;
}
return V_187 ;
}
return - V_52 ;
}
static T_12 F_211 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_396 ) ;
}
static T_12 F_212 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_326 , V_130 , V_60 , V_520 ;
struct V_371 * V_372 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 > 0 ) &&
( V_130 <= V_388 ) ) {
F_170 ( true ) ;
V_60 = 0 ;
for ( V_326 = 0 , V_372 = V_373 ; V_326 < V_378 ;
++ V_326 , ++ V_372 ) {
V_520 = F_141 ( V_372 -> V_395 , V_388 ) ;
if ( V_520 > V_60 )
V_60 = V_520 ;
}
V_396 = V_130 ;
if ( V_60 == V_388 )
F_142 ( & V_394 , 0 ) ;
else if ( V_60 >= V_130 )
F_142 ( & V_394 , V_60 + 1 ) ;
else
F_142 ( & V_394 , 0 ) ;
F_170 ( false ) ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_213 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_418 ) ;
}
static T_12 F_214 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_79 ) ;
}
static T_12 F_215 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_165 ) ;
}
static T_12 F_216 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
bool V_519 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_519 = ( V_165 != V_130 ) ;
V_165 = V_130 ;
V_168 = F_49 () ;
if ( V_519 ) {
struct V_12 * V_55 ;
struct V_53 * V_56 ;
F_7 ( & V_16 ) ;
F_8 (sdhp, &sdebug_host_list,
host_list) {
F_8 (dp, &sdhp->dev_info_list,
dev_list) {
F_67 ( V_72 ,
V_56 -> V_59 ) ;
}
}
F_9 ( & V_16 ) ;
}
return V_187 ;
}
return - V_52 ;
}
static T_12 F_217 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_521 ) ;
}
static T_12 F_218 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_522 ;
if ( sscanf ( V_269 , L_22 , & V_522 ) != 1 )
return - V_52 ;
if ( V_522 > 0 ) {
do {
F_219 () ;
} while ( -- V_522 );
} else if ( V_522 < 0 ) {
do {
F_220 () ;
} while ( ++ V_522 );
}
return V_187 ;
}
static T_12 F_221 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_149 ) ;
}
static T_12 F_222 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_149 = V_130 ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_223 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , ( int ) V_384 ) ;
}
static T_12 F_224 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( sscanf ( V_269 , L_22 , & V_130 ) == 1 ) && ( V_130 >= 0 ) ) {
if ( V_130 > 0 )
V_384 = true ;
else {
F_172 () ;
V_384 = false ;
}
return V_187 ;
}
return - V_52 ;
}
static T_12 F_225 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_93 , V_8 ) ;
}
static T_12 F_226 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_378 ) ;
}
static T_12 F_227 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_315 ) ;
}
static T_12 F_228 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_150 ) ;
}
static T_12 F_229 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_93 , V_271 ) ;
}
static T_12 F_230 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_220 ) ;
}
static T_12 F_231 ( struct V_507 * V_508 , char * V_269 )
{
T_12 V_187 ;
if ( ! F_1 () )
return F_44 ( V_269 , V_509 , L_94 ,
V_6 ) ;
V_187 = F_44 ( V_269 , V_509 - 1 , L_95 ,
( int ) V_341 , V_340 ) ;
V_269 [ V_187 ++ ] = '\n' ;
V_269 [ V_187 ] = '\0' ;
return V_187 ;
}
static T_12 F_232 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , V_153 ? 1 : 0 ) ;
}
static T_12 F_233 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_153 = ( V_130 > 0 ) ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_234 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , ! ! V_523 ) ;
}
static T_12 F_235 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_523 = ( V_130 > 0 ) ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_236 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , ! ! V_524 ) ;
}
static T_12 F_237 ( struct V_507 * V_508 , const char * V_269 ,
T_8 V_187 )
{
int V_130 ;
if ( ( V_187 > 0 ) && ( 1 == sscanf ( V_269 , L_22 , & V_130 ) ) && ( V_130 >= 0 ) ) {
V_524 = ( V_130 > 0 ) ;
return V_187 ;
}
return - V_52 ;
}
static T_12 F_238 ( struct V_507 * V_508 , char * V_269 )
{
return F_44 ( V_269 , V_509 , L_85 , ! ! V_107 ) ;
}
static int T_10 F_239 ( void )
{
unsigned long V_516 ;
int V_525 ;
int V_60 ;
int V_131 ;
F_142 ( & V_394 , 0 ) ;
if ( V_421 >= 1000 * 1000 * 1000 ) {
F_21 ( L_96 ) ;
V_421 = 0 ;
} else if ( V_421 > 0 )
V_420 = V_513 ;
switch ( V_8 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_81 ( L_97 , V_8 ) ;
return - V_52 ;
}
switch ( V_150 ) {
case V_526 :
break;
case V_277 :
case V_279 :
case V_151 :
V_152 = true ;
break;
default:
F_81 ( L_98 ) ;
return - V_52 ;
}
if ( V_271 > 1 ) {
F_81 ( L_99 ) ;
return - V_52 ;
}
if ( V_220 > 1 ) {
F_81 ( L_100 ) ;
return - V_52 ;
}
if ( V_119 > 15 ) {
F_81 ( L_101 , V_119 ) ;
return - V_52 ;
}
if ( V_369 > 256 ) {
F_21 ( L_102 ) ;
V_369 = V_527 ;
}
if ( V_171 > 0x3fff ) {
F_81 ( L_103 , V_171 ) ;
return - V_52 ;
}
if ( V_378 < 1 ) {
F_81 ( L_104 ) ;
return - V_52 ;
}
V_373 = F_240 ( V_378 , sizeof( struct V_371 ) ,
V_528 ) ;
if ( V_373 == NULL )
return - V_517 ;
for ( V_60 = 0 ; V_60 < V_378 ; ++ V_60 )
F_241 ( & V_373 [ V_60 ] . V_389 ) ;
if ( V_492 < 1 )
V_492 = 1 ;
V_516 = ( unsigned long ) V_492 * 1048576 ;
V_6 = V_516 / V_8 ;
V_168 = F_49 () ;
V_446 = 8 ;
V_211 = 32 ;
if ( V_492 >= 256 )
V_446 = 64 ;
else if ( V_492 >= 16 )
V_446 = 32 ;
V_505 = ( unsigned long ) V_168 /
( V_211 * V_446 ) ;
if ( V_505 >= 1024 ) {
V_446 = 255 ;
V_211 = 63 ;
V_505 = ( unsigned long ) V_168 /
( V_211 * V_446 ) ;
}
if ( V_1 == 0 ) {
V_7 = F_124 ( V_516 ) ;
if ( NULL == V_7 ) {
F_81 ( L_105 ) ;
V_131 = - V_517 ;
goto V_529;
}
memset ( V_7 , 0 , V_516 ) ;
if ( V_445 > 0 )
F_168 ( V_7 , V_516 ) ;
}
if ( V_315 ) {
int V_530 ;
V_530 = V_6 * sizeof( struct V_9 ) ;
V_11 = F_124 ( V_530 ) ;
F_81 ( L_106 , V_530 , V_11 ) ;
if ( V_11 == NULL ) {
F_81 ( L_107 ) ;
V_131 = - V_517 ;
goto V_531;
}
memset ( V_11 , 0xff , V_530 ) ;
}
if ( F_1 () ) {
V_121 =
F_242 ( V_121 , 0U , 0xffffffffU ) ;
V_122 =
F_242 ( V_122 , 0U , 256U ) ;
V_124 =
F_242 ( V_124 , 1U , 0xffffffffU ) ;
if ( V_123 &&
V_124 <=
V_123 ) {
F_81 ( L_108 ) ;
V_131 = - V_52 ;
goto V_531;
}
V_341 = F_103 ( V_6 - 1 ) + 1 ;
V_340 = F_124 ( F_243 ( V_341 ) * sizeof( long ) ) ;
F_152 ( L_109 , V_341 ) ;
if ( V_340 == NULL ) {
F_81 ( L_110 ) ;
V_131 = - V_517 ;
goto V_531;
}
F_244 ( V_340 , V_341 ) ;
if ( V_445 )
F_110 ( 0 , 2 ) ;
}
V_532 = F_245 ( L_111 ) ;
if ( F_246 ( V_532 ) ) {
F_21 ( L_112 ) ;
V_131 = F_247 ( V_532 ) ;
goto V_531;
}
V_131 = F_248 ( & V_533 ) ;
if ( V_131 < 0 ) {
F_21 ( L_113 , V_131 ) ;
goto V_534;
}
V_131 = F_249 ( & V_535 ) ;
if ( V_131 < 0 ) {
F_21 ( L_114 , V_131 ) ;
goto V_536;
}
V_525 = V_521 ;
V_521 = 0 ;
for ( V_60 = 0 ; V_60 < V_525 ; V_60 ++ ) {
if ( F_219 () ) {
F_81 ( L_115 , V_60 ) ;
break;
}
}
if ( V_42 )
F_152 ( L_116 , V_521 ) ;
return 0 ;
V_536:
F_250 ( & V_533 ) ;
V_534:
F_251 ( V_532 ) ;
V_531:
F_126 ( V_340 ) ;
F_126 ( V_11 ) ;
F_126 ( V_7 ) ;
V_529:
F_43 ( V_373 ) ;
return V_131 ;
}
static void T_13 F_252 ( void )
{
int V_60 = V_521 ;
F_161 () ;
F_162 () ;
for (; V_60 ; V_60 -- )
F_220 () ;
F_253 ( & V_535 ) ;
F_250 ( & V_533 ) ;
F_251 ( V_532 ) ;
F_126 ( V_11 ) ;
F_126 ( V_7 ) ;
F_43 ( V_373 ) ;
}
static void F_254 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
V_13 = F_255 ( V_49 ) ;
F_43 ( V_13 ) ;
}
static int F_219 ( void )
{
int V_60 , V_537 ;
int error = 0 ;
struct V_12 * V_13 ;
struct V_53 * V_538 , * V_539 ;
V_13 = F_41 ( sizeof( * V_13 ) , V_528 ) ;
if ( NULL == V_13 ) {
F_81 ( L_49 , __LINE__ ) ;
return - V_517 ;
}
F_256 ( & V_13 -> V_409 ) ;
V_537 = V_19 * V_369 ;
for ( V_60 = 0 ; V_60 < V_537 ; V_60 ++ ) {
V_538 = F_146 ( V_13 , V_528 ) ;
if ( ! V_538 ) {
F_81 ( L_49 , __LINE__ ) ;
error = - V_517 ;
goto V_540;
}
}
F_7 ( & V_16 ) ;
F_148 ( & V_13 -> V_541 , & V_542 ) ;
F_9 ( & V_16 ) ;
V_13 -> V_49 . V_543 = & V_533 ;
V_13 -> V_49 . V_544 = V_532 ;
V_13 -> V_49 . V_545 = & F_254 ;
F_257 ( & V_13 -> V_49 , L_117 , V_521 ) ;
error = F_258 ( & V_13 -> V_49 ) ;
if ( error )
goto V_540;
++ V_521 ;
return error ;
V_540:
F_259 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_260 ( & V_538 -> V_408 ) ;
F_43 ( V_538 ) ;
}
F_43 ( V_13 ) ;
return error ;
}
static void F_220 ( void )
{
struct V_12 * V_13 = NULL ;
F_7 ( & V_16 ) ;
if ( ! F_261 ( & V_542 ) ) {
V_13 = F_262 ( V_542 . V_546 ,
struct V_12 , V_541 ) ;
F_260 ( & V_13 -> V_541 ) ;
}
F_9 ( & V_16 ) ;
if ( ! V_13 )
return;
F_263 ( & V_13 -> V_49 ) ;
-- V_521 ;
}
static int F_264 ( struct V_48 * V_410 , int V_468 )
{
int V_393 = 0 ;
struct V_53 * V_54 ;
F_170 ( true ) ;
V_54 = (struct V_53 * ) V_410 -> V_392 ;
if ( NULL == V_54 ) {
F_170 ( false ) ;
return - V_547 ;
}
V_393 = F_139 ( & V_54 -> V_393 ) ;
if ( V_468 < 1 )
V_468 = 1 ;
if ( V_468 > V_388 + 10 )
V_468 = V_388 + 10 ;
F_265 ( V_410 , V_468 ) ;
if ( V_477 & V_215 ) {
F_11 ( V_43 , V_410 , L_118 ,
V_36 , V_468 , V_393 ) ;
}
F_170 ( false ) ;
return V_410 -> V_473 ;
}
static bool F_266 ( struct V_23 * V_24 )
{
if ( 0 == ( F_139 ( & V_459 ) % abs ( V_458 ) ) ) {
if ( V_458 < - 1 )
V_458 = - 1 ;
if ( V_548 & V_215 )
return true ;
else if ( V_549 & V_215 &&
F_267 ( V_24 ) )
return true ;
}
return false ;
}
static int F_268 ( struct V_14 * V_17 ,
struct V_23 * V_24 )
{
T_2 V_180 ;
struct V_48 * V_349 = V_24 -> V_35 ;
const struct V_190 * V_191 ;
const struct V_190 * V_192 ;
struct V_53 * V_54 ;
T_2 * V_50 = V_24 -> V_128 ;
int (* F_269)( struct V_23 * , struct V_53 * );
int V_60 , V_189 ;
int V_186 = 0 ;
T_6 V_198 ;
T_5 V_200 ;
T_2 V_199 = V_50 [ 0 ] ;
bool V_550 ;
F_94 ( V_24 , 0 ) ;
if ( V_384 )
F_133 ( & V_459 ) ;
if ( F_93 ( V_42 &&
! ( V_551 & V_215 ) ) ) {
char V_104 [ 120 ] ;
int V_130 , V_145 , V_552 ;
V_145 = V_24 -> V_553 ;
V_552 = ( int ) sizeof( V_104 ) ;
if ( V_145 > 32 )
strcpy ( V_104 , L_119 ) ;
else {
for ( V_60 = 0 , V_130 = 0 ; V_60 < V_145 && V_130 < V_552 ; ++ V_60 )
V_130 += F_44 ( V_104 + V_130 , V_552 - V_130 , L_30 ,
( T_6 ) V_50 [ V_60 ] ) ;
}
if ( V_374 )
F_11 ( V_43 , V_349 , L_120 ,
V_44 , F_130 ( V_24 -> V_376 ) ,
V_104 ) ;
else
F_11 ( V_43 , V_349 , L_121 , V_44 ,
V_104 ) ;
}
V_550 = ( V_349 -> V_139 == V_22 ) ;
if ( F_93 ( ( V_349 -> V_139 >= V_369 ) && ! V_550 ) )
goto V_554;
V_180 = V_204 [ V_199 ] ;
V_191 = & V_195 [ V_180 ] ;
V_54 = (struct V_53 * ) V_349 -> V_392 ;
if ( F_93 ( ! V_54 ) ) {
V_54 = F_149 ( V_349 ) ;
if ( NULL == V_54 )
goto V_554;
}
V_189 = V_191 -> V_196 ;
F_269 = V_191 -> V_555 ;
if ( V_189 ) {
V_192 = V_191 ;
if ( V_201 & V_192 -> V_198 ) {
if ( V_556 & V_191 -> V_198 )
V_200 = 0x1f & V_50 [ 1 ] ;
else
V_200 = F_40 ( V_50 + 8 ) ;
for ( V_60 = 0 ; V_60 <= V_189 ; V_191 = V_192 -> V_203 + V_60 ++ ) {
if ( V_199 == V_191 -> V_199 && V_200 == V_191 -> V_200 )
break;
}
} else {
for ( V_60 = 0 ; V_60 <= V_189 ; V_191 = V_192 -> V_203 + V_60 ++ ) {
if ( V_199 == V_191 -> V_199 )
break;
}
}
if ( V_60 > V_189 ) {
if ( V_556 & V_192 -> V_198 )
F_10 ( V_24 , V_143 , 1 , 4 ) ;
else if ( V_557 & V_192 -> V_198 )
F_10 ( V_24 , V_143 , 8 , 7 ) ;
else
F_15 ( V_24 ) ;
goto V_558;
}
}
V_198 = V_191 -> V_198 ;
if ( F_93 ( V_197 & V_198 ) ) {
F_15 ( V_24 ) ;
goto V_558;
}
if ( F_93 ( V_550 && ! ( V_559 & V_198 ) ) ) {
if ( V_42 )
F_11 ( V_43 , V_349 , L_122 ,
V_44 , V_199 , L_123 ) ;
F_15 ( V_24 ) ;
goto V_558;
}
if ( F_93 ( V_524 ) ) {
T_2 V_560 ;
int V_326 ;
for ( V_60 = 1 ; V_60 < V_191 -> V_202 [ 0 ] && V_60 < 16 ; ++ V_60 ) {
V_560 = ~ V_191 -> V_202 [ V_60 ] & V_50 [ V_60 ] ;
if ( V_560 ) {
for ( V_326 = 7 ; V_326 >= 0 ; -- V_326 , V_560 <<= 1 ) {
if ( 0x80 & V_560 )
break;
}
F_10 ( V_24 , V_143 , V_60 , V_326 ) ;
goto V_558;
}
}
}
if ( F_93 ( ! ( V_561 & V_198 ) &&
F_20 ( V_54 -> V_59 ,
V_61 ) != V_61 ) ) {
V_186 = F_19 ( V_24 , V_54 ) ;
if ( V_186 )
goto V_558;
}
if ( F_93 ( ( V_562 & V_198 ) && F_139 ( & V_54 -> V_163 ) ) ) {
F_14 ( V_24 , V_563 , V_564 , 0x2 ) ;
if ( V_42 )
F_11 ( V_43 , V_349 , L_124
L_56 , V_44 , L_125
L_126 ) ;
V_186 = V_81 ;
goto V_565;
}
if ( V_1 && ( V_566 & V_198 ) )
goto V_565;
if ( F_93 ( V_458 ) ) {
if ( F_266 ( V_24 ) )
return 0 ;
}
if ( F_137 ( V_191 -> V_555 ) )
V_186 = V_191 -> V_555 ( V_24 , V_54 ) ;
else if ( F_269 )
V_186 = F_269 ( V_24 , V_54 ) ;
V_565:
return F_174 ( V_24 , V_54 , V_186 ,
( ( V_567 & V_198 ) ? 0 : V_420 ) ) ;
V_558:
return F_174 ( V_24 , V_54 , V_81 , 0 ) ;
V_554:
return F_174 ( V_24 , NULL , V_470 << 16 , 0 ) ;
}
static int F_270 ( struct V_35 * V_49 )
{
int error = 0 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_568 ;
V_13 = F_255 ( V_49 ) ;
V_569 . V_570 = V_396 ;
if ( V_571 )
V_569 . V_572 = V_573 ;
V_15 = F_271 ( & V_569 , sizeof( V_13 ) ) ;
if ( NULL == V_15 ) {
F_81 ( L_127 ) ;
error = - V_547 ;
return error ;
}
if ( V_378 > V_574 ) {
F_21 ( L_128 ,
V_44 , V_378 , V_574 ) ;
V_378 = V_574 ;
}
V_374 = F_272 ( V_15 ) && ( V_378 > 1 ) ;
if ( V_374 )
V_15 -> V_575 = V_378 ;
V_13 -> V_17 = V_15 ;
* ( (struct V_12 * * ) V_15 -> V_392 ) = V_13 ;
if ( ( V_15 -> V_18 >= 0 ) && ( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 + 1 ;
V_568 = 0 ;
switch ( V_150 ) {
case V_277 :
V_568 = V_576 ;
if ( V_315 )
V_568 |= V_577 ;
break;
case V_279 :
V_568 = V_578 ;
if ( V_315 )
V_568 |= V_579 ;
break;
case V_151 :
V_568 = V_580 ;
if ( V_315 )
V_568 |= V_581 ;
break;
default:
if ( V_315 )
V_568 |= V_582 ;
break;
}
F_273 ( V_15 , V_568 ) ;
if ( V_152 || V_315 )
F_152 ( L_129 ,
( V_568 & V_576 ) ? L_130 : L_54 ,
( V_568 & V_578 ) ? L_131 : L_54 ,
( V_568 & V_580 ) ? L_132 : L_54 ,
( V_568 & V_582 ) ? L_133 : L_54 ,
( V_568 & V_577 ) ? L_134 : L_54 ,
( V_568 & V_579 ) ? L_135 : L_54 ,
( V_568 & V_581 ) ? L_136 : L_54 ) ;
if ( V_271 == 1 )
F_274 ( V_15 , V_583 ) ;
else
F_274 ( V_15 , V_584 ) ;
V_42 = ! ! ( V_499 & V_215 ) ;
V_306 = ! ! ( V_500 & V_215 ) ;
if ( V_458 )
V_384 = true ;
error = F_275 ( V_15 , & V_13 -> V_49 ) ;
if ( error ) {
F_81 ( L_137 ) ;
error = - V_547 ;
F_276 ( V_15 ) ;
} else
F_277 ( V_15 ) ;
return error ;
}
static int F_278 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
struct V_53 * V_538 , * V_539 ;
V_13 = F_255 ( V_49 ) ;
if ( ! V_13 ) {
F_81 ( L_138 ) ;
return - V_547 ;
}
F_279 ( V_13 -> V_17 ) ;
F_259 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_260 ( & V_538 -> V_408 ) ;
F_43 ( V_538 ) ;
}
F_276 ( V_13 -> V_17 ) ;
return 0 ;
}
static int F_280 ( struct V_35 * V_49 ,
struct V_507 * V_585 )
{
return 1 ;
}
