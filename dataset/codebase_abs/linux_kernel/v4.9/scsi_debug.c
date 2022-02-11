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
static int F_27 ( struct V_23 * V_24 , const void * V_82 ,
int V_83 , unsigned int V_95 )
{
int V_84 , V_96 ;
struct V_85 * V_86 = F_23 ( V_24 ) ;
T_4 V_97 = V_95 ;
if ( V_86 -> V_87 <= V_95 )
return 0 ;
if ( ! ( F_24 ( V_24 ) || V_24 -> V_88 == V_89 ) )
return V_90 << 16 ;
V_84 = F_28 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_82 , V_83 , V_97 ) ;
F_29 ( L_18 ,
V_36 , V_95 , F_26 ( V_24 ) , V_84 , V_86 -> V_94 ) ;
V_96 = ( int ) F_26 ( V_24 ) - ( ( int ) V_95 + V_84 ) ;
V_86 -> V_94 = F_30 ( V_86 -> V_94 , V_96 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 , unsigned char * V_82 ,
int V_83 )
{
if ( ! F_26 ( V_24 ) )
return 0 ;
if ( ! ( F_24 ( V_24 ) || V_24 -> V_88 == V_98 ) )
return - 1 ;
return F_32 ( V_24 , V_82 , V_83 ) ;
}
static int F_33 ( unsigned char * V_82 , int V_99 ,
int V_100 , int V_101 ,
const char * V_102 , int V_103 ,
const T_5 * V_104 )
{
int V_105 , V_106 ;
char V_107 [ 32 ] ;
V_106 = V_100 + 1 ;
V_82 [ 0 ] = 0x2 ;
V_82 [ 1 ] = 0x1 ;
V_82 [ 2 ] = 0x0 ;
memcpy ( & V_82 [ 4 ] , V_108 , 8 ) ;
memcpy ( & V_82 [ 12 ] , V_109 , 16 ) ;
memcpy ( & V_82 [ 28 ] , V_102 , V_103 ) ;
V_105 = 8 + 16 + V_103 ;
V_82 [ 3 ] = V_105 ;
V_105 += 4 ;
if ( V_101 >= 0 ) {
if ( V_110 ) {
V_82 [ V_105 ++ ] = 0x1 ;
V_82 [ V_105 ++ ] = 0xa ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x12 ;
V_82 [ V_105 ++ ] = 0x10 ;
V_82 [ V_105 ++ ] = 0x0 ;
memcpy ( V_82 + V_105 , V_104 , 16 ) ;
V_105 += 16 ;
} else {
V_82 [ V_105 ++ ] = 0x1 ;
V_82 [ V_105 ++ ] = 0x3 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x8 ;
F_34 ( V_111 + V_101 , V_82 + V_105 ) ;
V_105 += 8 ;
}
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0x94 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x4 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x1 ;
}
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0x93 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x8 ;
F_34 ( V_112 + V_106 , V_82 + V_105 ) ;
V_105 += 8 ;
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0x95 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x4 ;
V_82 [ V_105 ++ ] = 0 ;
V_82 [ V_105 ++ ] = 0 ;
F_13 ( V_99 , V_82 + V_105 ) ;
V_105 += 2 ;
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0xa3 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x8 ;
F_34 ( V_112 + V_100 , V_82 + V_105 ) ;
V_105 += 8 ;
V_82 [ V_105 ++ ] = 0x63 ;
V_82 [ V_105 ++ ] = 0xa8 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 24 ;
memcpy ( V_82 + V_105 , L_19 , 12 ) ;
V_105 += 12 ;
snprintf ( V_107 , sizeof( V_107 ) , L_20 , V_100 ) ;
memcpy ( V_82 + V_105 , V_107 , 8 ) ;
V_105 += 8 ;
memset ( V_82 + V_105 , 0 , 4 ) ;
V_105 += 4 ;
return V_105 ;
}
static int F_35 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_113 , sizeof( V_113 ) ) ;
return sizeof( V_113 ) ;
}
static int F_36 ( unsigned char * V_82 )
{
int V_105 = 0 ;
const char * V_114 = L_21 ;
const char * V_115 = L_22 ;
int V_116 , V_117 ;
V_82 [ V_105 ++ ] = 0x1 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_117 = strlen ( V_114 ) ;
V_116 = V_117 + 1 ;
if ( V_116 % 4 )
V_116 = ( ( V_116 / 4 ) + 1 ) * 4 ;
V_82 [ V_105 ++ ] = V_116 ;
memcpy ( V_82 + V_105 , V_114 , V_117 ) ;
memset ( V_82 + V_105 + V_117 , 0 , V_116 - V_117 ) ;
V_105 += V_116 ;
V_82 [ V_105 ++ ] = 0x4 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_117 = strlen ( V_115 ) ;
V_116 = V_117 + 1 ;
if ( V_116 % 4 )
V_116 = ( ( V_116 / 4 ) + 1 ) * 4 ;
V_82 [ V_105 ++ ] = V_116 ;
memcpy ( V_82 + V_105 , V_115 , V_117 ) ;
memset ( V_82 + V_105 + V_117 , 0 , V_116 - V_117 ) ;
V_105 += V_116 ;
return V_105 ;
}
static int F_37 ( unsigned char * V_82 , int V_100 )
{
int V_105 = 0 ;
int V_106 , V_118 ;
V_106 = V_100 + 1 ;
V_118 = V_106 + 1 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x1 ;
memset ( V_82 + V_105 , 0 , 6 ) ;
V_105 += 6 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 12 ;
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0x93 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x8 ;
F_34 ( V_112 + V_106 , V_82 + V_105 ) ;
V_105 += 8 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x2 ;
memset ( V_82 + V_105 , 0 , 6 ) ;
V_105 += 6 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 12 ;
V_82 [ V_105 ++ ] = 0x61 ;
V_82 [ V_105 ++ ] = 0x93 ;
V_82 [ V_105 ++ ] = 0x0 ;
V_82 [ V_105 ++ ] = 0x8 ;
F_34 ( V_112 + V_118 , V_82 + V_105 ) ;
V_105 += 8 ;
return V_105 ;
}
static int F_38 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_119 , sizeof( V_119 ) ) ;
return sizeof( V_119 ) ;
}
static int F_39 ( unsigned char * V_82 )
{
unsigned int V_120 ;
memcpy ( V_82 , V_121 , sizeof( V_121 ) ) ;
V_120 = 1 << V_122 ;
F_13 ( V_120 , V_82 + 2 ) ;
if ( V_6 > 0x400 )
F_40 ( V_6 , V_82 + 4 ) ;
F_40 ( V_123 , & V_82 [ 8 ] ) ;
if ( V_2 ) {
F_40 ( V_124 , & V_82 [ 16 ] ) ;
F_40 ( V_125 , & V_82 [ 20 ] ) ;
}
if ( V_126 ) {
F_40 ( V_126 , & V_82 [ 28 ] ) ;
V_82 [ 28 ] |= 0x80 ;
}
F_40 ( V_127 , & V_82 [ 24 ] ) ;
F_34 ( V_128 , & V_82 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_121 ) ;
}
static int F_41 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x3c ) ;
V_82 [ 0 ] = 0 ;
V_82 [ 1 ] = 1 ;
V_82 [ 2 ] = 0 ;
V_82 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_42 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x4 ) ;
V_82 [ 0 ] = 0 ;
if ( V_2 )
V_82 [ 1 ] = 1 << 7 ;
if ( V_3 )
V_82 [ 1 ] |= 1 << 6 ;
if ( V_4 )
V_82 [ 1 ] |= 1 << 5 ;
if ( V_129 && F_1 () )
V_82 [ 1 ] |= ( V_129 & 0x7 ) << 2 ;
return 0x4 ;
}
static int F_43 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char V_130 ;
unsigned char * V_82 ;
unsigned char * V_50 = V_24 -> V_131 ;
int V_132 , V_96 , V_133 ;
bool V_134 , V_135 ;
V_132 = F_44 ( V_50 + 3 ) ;
V_82 = F_45 ( V_136 , V_137 ) ;
if ( ! V_82 )
return V_138 << 16 ;
V_135 = ( V_139 == V_140 ) ;
V_134 = F_46 ( V_24 -> V_35 -> V_141 ) ;
if ( V_134 )
V_130 = V_142 ;
else if ( V_143 && ( V_54 -> V_141 == V_144 ) )
V_130 = 0x7f ;
else
V_130 = ( V_139 & 0x1f ) ;
V_82 [ 0 ] = V_130 ;
if ( 0x2 & V_50 [ 1 ] ) {
F_10 ( V_24 , V_145 , 1 , 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
} else if ( 0x1 & V_50 [ 1 ] ) {
int V_146 , V_99 , V_100 , V_147 ;
char V_148 [ 6 ] ;
int V_149 = V_54 -> V_13 -> V_17 -> V_149 ;
V_99 = ( ( ( V_149 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_150 & 0x7f ) ;
if ( V_151 == 0 )
V_149 = 0 ;
V_146 = V_134 ? - 1 : ( ( ( V_149 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) + V_54 -> V_141 ) ;
V_100 = ( ( V_149 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
V_147 = F_48 ( V_148 , 6 , L_23 , V_146 ) ;
if ( 0 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_96 = 4 ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x80 ;
V_82 [ V_96 ++ ] = 0x83 ;
V_82 [ V_96 ++ ] = 0x84 ;
V_82 [ V_96 ++ ] = 0x85 ;
V_82 [ V_96 ++ ] = 0x86 ;
V_82 [ V_96 ++ ] = 0x87 ;
V_82 [ V_96 ++ ] = 0x88 ;
if ( V_135 ) {
V_82 [ V_96 ++ ] = 0x89 ;
V_82 [ V_96 ++ ] = 0xb0 ;
V_82 [ V_96 ++ ] = 0xb1 ;
V_82 [ V_96 ++ ] = 0xb2 ;
}
V_82 [ 3 ] = V_96 - 4 ;
} else if ( 0x80 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = V_147 ;
memcpy ( & V_82 [ 4 ] , V_148 , V_147 ) ;
} else if ( 0x83 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_33 ( & V_82 [ 4 ] , V_99 ,
V_100 , V_146 ,
V_148 , V_147 ,
& V_54 -> V_104 ) ;
} else if ( 0x84 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_35 ( & V_82 [ 4 ] ) ;
} else if ( 0x85 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_36 ( & V_82 [ 4 ] ) ;
} else if ( 0x86 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = 0x3c ;
if ( V_152 == V_153 )
V_82 [ 4 ] = 0x4 ;
else if ( V_154 )
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
V_82 [ 3 ] = F_37 ( & V_82 [ 4 ] , V_100 ) ;
} else if ( V_135 && 0x89 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_96 = F_38 ( & V_82 [ 4 ] ) ;
F_13 ( V_96 , V_82 + 2 ) ;
} else if ( V_135 && 0xb0 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_39 ( & V_82 [ 4 ] ) ;
} else if ( V_135 && 0xb1 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_41 ( & V_82 [ 4 ] ) ;
} else if ( V_135 && 0xb2 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_42 ( & V_82 [ 4 ] ) ;
} else {
F_10 ( V_24 , V_145 , 2 , - 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_147 = F_30 ( F_44 ( V_82 + 2 ) + 4 , V_132 ) ;
V_133 = F_22 ( V_24 , V_82 ,
F_30 ( V_147 , V_136 ) ) ;
F_47 ( V_82 ) ;
return V_133 ;
}
V_82 [ 1 ] = V_155 ? 0x80 : 0 ;
V_82 [ 2 ] = V_79 ;
V_82 [ 3 ] = 2 ;
V_82 [ 4 ] = V_156 - 5 ;
V_82 [ 5 ] = ( int ) V_154 ;
if ( V_151 == 0 )
V_82 [ 5 ] = 0x10 ;
V_82 [ 6 ] = 0x10 ;
V_82 [ 7 ] = 0xa ;
memcpy ( & V_82 [ 8 ] , V_108 , 8 ) ;
memcpy ( & V_82 [ 16 ] , V_109 , 16 ) ;
memcpy ( & V_82 [ 32 ] , V_157 , 4 ) ;
F_13 ( 0xc0 , V_82 + 58 ) ;
F_13 ( 0x5c0 , V_82 + 60 ) ;
V_96 = 62 ;
if ( V_135 ) {
F_13 ( 0x600 , V_82 + V_96 ) ;
V_96 += 2 ;
} else if ( V_139 == V_158 ) {
F_13 ( 0x525 , V_82 + V_96 ) ;
V_96 += 2 ;
}
F_13 ( 0x2100 , V_82 + V_96 ) ;
V_133 = F_22 ( V_24 , V_82 ,
F_30 ( V_132 , V_156 ) ) ;
F_47 ( V_82 ) ;
return V_133 ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_29 ;
unsigned char * V_50 = V_24 -> V_131 ;
unsigned char V_82 [ V_39 ] ;
bool V_159 ;
int V_147 = 18 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_159 = ! ! ( V_50 [ 1 ] & 1 ) ;
V_29 = V_24 -> V_33 ;
if ( ( V_160 [ 2 ] & 0x4 ) && ( 6 == ( V_160 [ 3 ] & 0xf ) ) ) {
if ( V_159 ) {
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = 0x0 ;
V_82 [ 2 ] = V_161 ;
V_82 [ 3 ] = 0xff ;
V_147 = 8 ;
} else {
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = 0x0 ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_161 ;
V_82 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_82 , V_29 , V_39 ) ;
if ( V_82 [ 0 ] >= 0x70 && V_159 == V_40 )
;
else if ( V_82 [ 0 ] <= 0x70 ) {
if ( V_159 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_147 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 7 ] = 0xa ;
}
} else if ( V_159 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = V_29 [ 2 ] ;
V_82 [ 2 ] = V_29 [ 12 ] ;
V_82 [ 3 ] = V_29 [ 13 ] ;
V_147 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = V_29 [ 1 ] ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_29 [ 1 ] ;
V_82 [ 13 ] = V_29 [ 3 ] ;
}
}
F_14 ( V_24 , 0 , V_162 , 0 ) ;
return F_22 ( V_24 , V_82 , V_147 ) ;
}
static int F_50 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_131 ;
int V_163 , V_164 ;
V_163 = ( V_50 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_163 ) {
F_10 ( V_24 , V_145 , 4 , 7 ) ;
return V_81 ;
}
V_164 = ! ( V_50 [ 4 ] & 1 ) ;
F_51 ( & V_54 -> V_165 , V_164 ) ;
return 0 ;
}
static T_1 F_52 ( void )
{
static const unsigned int V_166 = 1073741824 ;
if ( V_167 > 0 )
return ( T_1 ) V_167 *
( V_166 / V_8 ) ;
else
return V_6 ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char V_82 [ V_168 ] ;
unsigned int V_169 ;
V_170 = F_52 () ;
memset ( V_82 , 0 , V_168 ) ;
if ( V_170 < 0xffffffff ) {
V_169 = ( unsigned int ) V_170 - 1 ;
F_40 ( V_169 , V_82 + 0 ) ;
} else
F_40 ( 0xffffffff , V_82 + 0 ) ;
F_13 ( V_8 , V_82 + 6 ) ;
return F_22 ( V_24 , V_82 , V_168 ) ;
}
static int F_54 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_131 ;
unsigned char V_82 [ V_171 ] ;
int V_132 ;
V_132 = F_55 ( V_50 + 10 ) ;
V_170 = F_52 () ;
memset ( V_82 , 0 , V_171 ) ;
F_34 ( ( V_172 ) ( V_170 - 1 ) , V_82 + 0 ) ;
F_40 ( V_8 , V_82 + 8 ) ;
V_82 [ 13 ] = V_122 & 0xf ;
V_82 [ 14 ] = ( V_173 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_82 [ 14 ] |= 0x80 ;
if ( V_129 & 1 )
V_82 [ 14 ] |= 0x40 ;
}
V_82 [ 15 ] = V_173 & 0xff ;
if ( V_154 ) {
V_82 [ 12 ] = ( V_152 - 1 ) << 1 ;
V_82 [ 12 ] |= 1 ;
}
return F_22 ( V_24 , V_82 ,
F_30 ( V_132 , V_171 ) ) ;
}
static int F_56 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_131 ;
unsigned char * V_82 ;
int V_149 = V_54 -> V_13 -> V_17 -> V_149 ;
int V_96 , V_133 , V_174 , V_175 ;
int V_176 , V_177 , V_106 , V_118 ;
V_174 = F_55 ( V_50 + 6 ) ;
V_82 = F_45 ( V_178 , V_137 ) ;
if ( ! V_82 )
return V_138 << 16 ;
V_106 = 0x1 ;
V_118 = 0x2 ;
V_176 = ( ( ( V_149 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_150 & 0x7f ) ;
V_177 = ( ( ( V_149 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_150 & 0x7f ) + 0x80 ;
V_96 = 4 ;
if ( V_151 == 0 ) {
V_82 [ V_96 ++ ] = V_149 % 3 ;
V_82 [ V_96 ++ ] = 0x0F ;
} else {
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x01 ;
}
F_13 ( V_176 , V_82 + V_96 ) ;
V_96 += 2 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0x1 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
F_13 ( V_106 , V_82 + V_96 ) ;
V_96 += 2 ;
V_82 [ V_96 ++ ] = 3 ;
V_82 [ V_96 ++ ] = 0x08 ;
F_13 ( V_177 , V_82 + V_96 ) ;
V_96 += 2 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0x1 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
F_13 ( V_118 , V_82 + V_96 ) ;
V_96 += 2 ;
V_175 = V_96 - 4 ;
F_40 ( V_175 , V_82 + 0 ) ;
V_175 = F_30 ( V_174 , V_96 ) ;
V_133 = F_22 ( V_24 , V_82 ,
F_30 ( V_175 , V_178 ) ) ;
F_47 ( V_82 ) ;
return V_133 ;
}
static int F_57 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_179 ;
T_2 V_180 , V_181 , V_182 , V_183 ;
T_6 V_184 , V_185 ;
T_7 V_132 , V_186 ;
int V_60 , V_187 , V_147 , V_188 , V_189 , V_190 , V_191 ;
const struct V_192 * V_193 ;
const struct V_192 * V_194 ;
T_2 * V_82 ;
T_2 * V_50 = V_24 -> V_131 ;
V_179 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_180 = V_50 [ 2 ] & 0x7 ;
V_181 = V_50 [ 3 ] ;
V_184 = F_44 ( V_50 + 4 ) ;
V_132 = F_55 ( V_50 + 6 ) ;
if ( V_132 < 4 || V_132 > 0xffff ) {
F_10 ( V_24 , V_145 , 6 , - 1 ) ;
return V_81 ;
}
if ( V_132 > 8192 )
V_186 = 8192 ;
else
V_186 = V_132 ;
V_82 = F_45 ( ( V_186 < 256 ) ? 320 : V_186 + 64 , V_137 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_195 ,
V_196 ) ;
return V_81 ;
}
switch ( V_180 ) {
case 0 :
for ( V_189 = 0 , V_193 = V_197 ;
V_193 -> V_198 != 0xff ; ++ V_193 ) {
if ( V_199 & V_193 -> V_200 )
continue;
V_189 += ( V_193 -> V_198 + 1 ) ;
}
V_190 = V_179 ? 20 : 8 ;
F_40 ( V_189 * V_190 , V_82 ) ;
for ( V_187 = 4 , V_193 = V_197 ;
V_193 -> V_198 != 0xff && V_187 < V_186 ; ++ V_193 ) {
if ( V_199 & V_193 -> V_200 )
continue;
V_191 = V_193 -> V_198 ;
V_82 [ V_187 ] = V_193 -> V_201 ;
F_13 ( V_193 -> V_202 , V_82 + V_187 + 2 ) ;
if ( V_179 )
V_82 [ V_187 + 5 ] |= 0x2 ;
if ( V_203 & V_193 -> V_200 )
V_82 [ V_187 + 5 ] |= 0x1 ;
F_13 ( V_193 -> V_204 [ 0 ] , V_82 + V_187 + 6 ) ;
if ( V_179 )
F_13 ( 0xa , V_82 + V_187 + 8 ) ;
V_194 = V_193 ;
for ( V_60 = 0 , V_193 = V_193 -> V_205 ; V_60 < V_191 ; ++ V_60 , ++ V_193 ) {
if ( V_199 & V_193 -> V_200 )
continue;
V_187 += V_190 ;
V_82 [ V_187 ] = V_193 -> V_201 ;
F_13 ( V_193 -> V_202 , V_82 + V_187 + 2 ) ;
if ( V_179 )
V_82 [ V_187 + 5 ] |= 0x2 ;
if ( V_203 & V_193 -> V_200 )
V_82 [ V_187 + 5 ] |= 0x1 ;
F_13 ( V_193 -> V_204 [ 0 ] ,
V_82 + V_187 + 6 ) ;
if ( V_179 )
F_13 ( 0xa ,
V_82 + V_187 + 8 ) ;
}
V_193 = V_194 ;
V_187 += V_190 ;
}
break;
case 1 :
case 2 :
case 3 :
V_182 = V_206 [ V_181 ] ;
V_193 = & V_197 [ V_182 ] ;
if ( V_199 & V_193 -> V_200 ) {
V_183 = 1 ;
V_187 = 4 ;
} else {
if ( 1 == V_180 ) {
if ( V_203 & V_193 -> V_200 ) {
F_10 ( V_24 , V_145 ,
2 , 2 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_184 = 0 ;
} else if ( 2 == V_180 &&
0 == ( V_203 & V_193 -> V_200 ) ) {
F_10 ( V_24 , V_145 , 4 , - 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
if ( 0 == ( V_203 & V_193 -> V_200 ) &&
V_181 == V_193 -> V_201 )
V_183 = 3 ;
else if ( 0 == ( V_203 & V_193 -> V_200 ) ) {
V_191 = V_193 -> V_198 ;
for ( V_60 = 0 , V_193 = V_193 -> V_205 ; V_60 < V_191 ;
++ V_60 , ++ V_193 ) {
if ( V_181 == V_193 -> V_201 )
break;
}
V_183 = ( V_60 >= V_191 ) ? 1 : 3 ;
} else if ( V_184 != V_193 -> V_202 ) {
V_191 = V_193 -> V_198 ;
for ( V_60 = 0 , V_193 = V_193 -> V_205 ; V_60 < V_191 ;
++ V_60 , ++ V_193 ) {
if ( V_184 == V_193 -> V_202 )
break;
}
V_183 = ( V_60 >= V_191 ) ? 1 : 3 ;
} else
V_183 = 3 ;
if ( 3 == V_183 ) {
V_185 = V_193 -> V_204 [ 0 ] ;
F_13 ( V_185 , V_82 + 2 ) ;
V_82 [ 4 ] = V_193 -> V_201 ;
for ( V_60 = 1 ; V_60 < V_185 ; ++ V_60 )
V_82 [ 4 + V_60 ] = ( V_60 < 16 ) ?
V_193 -> V_204 [ V_60 ] : 0xff ;
V_187 = 4 + V_185 ;
} else
V_187 = 4 ;
}
V_82 [ 1 ] = ( V_179 ? 0x80 : 0 ) | V_183 ;
if ( V_179 ) {
F_13 ( 0xa , V_82 + V_187 ) ;
V_187 += 12 ;
}
break;
default:
F_10 ( V_24 , V_145 , 2 , 2 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_187 = ( V_187 < V_186 ) ? V_187 : V_186 ;
V_147 = ( V_187 < V_132 ) ? V_187 : V_132 ;
V_188 = F_22 ( V_24 , V_82 , V_147 ) ;
F_47 ( V_82 ) ;
return V_188 ;
}
static int F_58 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_207 ;
T_7 V_132 , V_147 ;
T_2 V_82 [ 16 ] ;
T_2 * V_50 = V_24 -> V_131 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_207 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_132 = F_55 ( V_50 + 6 ) ;
if ( V_132 < 4 ) {
F_10 ( V_24 , V_145 , 6 , - 1 ) ;
return V_81 ;
}
V_82 [ 0 ] = 0xc8 ;
V_82 [ 1 ] = 0x1 ;
if ( V_207 ) {
V_82 [ 3 ] = 0xc ;
V_147 = 16 ;
} else
V_147 = 4 ;
V_147 = ( V_147 < V_132 ) ? V_147 : V_132 ;
return F_22 ( V_24 , V_82 , V_147 ) ;
}
static int F_59 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_210 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_208 , V_210 , sizeof( V_210 ) ) ;
if ( 1 == V_209 )
memset ( V_208 + 2 , 0 , sizeof( V_210 ) - 2 ) ;
return sizeof( V_210 ) ;
}
static int F_60 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_211 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_208 , V_211 , sizeof( V_211 ) ) ;
if ( 1 == V_209 )
memset ( V_208 + 2 , 0 , sizeof( V_211 ) - 2 ) ;
return sizeof( V_211 ) ;
}
static int F_61 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_212 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_208 , V_212 , sizeof( V_212 ) ) ;
F_13 ( V_213 , V_208 + 10 ) ;
F_13 ( V_8 , V_208 + 12 ) ;
if ( V_155 )
V_208 [ 20 ] |= 0x20 ;
if ( 1 == V_209 )
memset ( V_208 + 2 , 0 , sizeof( V_212 ) - 2 ) ;
return sizeof( V_212 ) ;
}
static int F_62 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_214 [] = { 0x4 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned char V_215 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_216 & V_217 )
V_218 [ 2 ] &= ~ 0x4 ;
memcpy ( V_208 , V_218 , sizeof( V_218 ) ) ;
if ( 1 == V_209 )
memcpy ( V_208 + 2 , V_214 , sizeof( V_214 ) ) ;
else if ( 2 == V_209 )
memcpy ( V_208 , V_215 , sizeof( V_215 ) ) ;
return sizeof( V_218 ) ;
}
static int F_63 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_219 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_220 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_40 )
V_221 [ 2 ] |= 0x4 ;
else
V_221 [ 2 ] &= ~ 0x4 ;
if ( V_222 )
V_221 [ 5 ] |= 0x80 ;
memcpy ( V_208 , V_221 , sizeof( V_221 ) ) ;
if ( 1 == V_209 )
memcpy ( V_208 + 2 , V_219 , sizeof( V_219 ) ) ;
else if ( 2 == V_209 )
memcpy ( V_208 , V_220 , sizeof( V_220 ) ) ;
return sizeof( V_221 ) ;
}
static int F_64 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_223 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_224 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_208 , V_160 , sizeof( V_160 ) ) ;
if ( 1 == V_209 )
memcpy ( V_208 + 2 , V_223 , sizeof( V_223 ) ) ;
else if ( 2 == V_209 )
memcpy ( V_208 , V_224 , sizeof( V_224 ) ) ;
return sizeof( V_160 ) ;
}
static int F_65 ( unsigned char * V_208 , int V_209 , int V_57 )
{
unsigned char V_225 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_208 , V_225 , sizeof( V_225 ) ) ;
if ( 1 == V_209 )
memset ( V_208 + 2 , 0 , sizeof( V_225 ) - 2 ) ;
return sizeof( V_225 ) ;
}
static int F_66 ( unsigned char * V_208 , int V_209 , int V_57 ,
int V_100 )
{
unsigned char V_226 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
int V_106 , V_118 ;
F_34 ( V_112 , V_226 + 16 ) ;
F_34 ( V_227 + 1 , V_226 + 24 ) ;
F_34 ( V_112 , V_226 + 64 ) ;
F_34 ( V_227 + 1 , V_226 + 72 ) ;
V_106 = V_100 + 1 ;
V_118 = V_106 + 1 ;
memcpy ( V_208 , V_226 , sizeof( V_226 ) ) ;
F_40 ( V_106 , V_208 + 20 ) ;
F_40 ( V_118 , V_208 + 48 + 20 ) ;
if ( 1 == V_209 )
memset ( V_208 + 4 , 0 , sizeof( V_226 ) - 4 ) ;
return sizeof( V_226 ) ;
}
static int F_67 ( unsigned char * V_208 , int V_209 )
{
unsigned char V_228 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_208 , V_228 , sizeof( V_228 ) ) ;
if ( 1 == V_209 )
memset ( V_208 + 4 , 0 , sizeof( V_228 ) - 4 ) ;
return sizeof( V_228 ) ;
}
static int F_68 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_209 , V_229 , V_230 , V_231 ;
unsigned char V_232 ;
int V_132 , V_187 , V_147 , V_100 ;
int V_57 = V_24 -> V_35 -> V_233 ;
unsigned char * V_234 ;
unsigned char V_82 [ V_235 ] ;
unsigned char * V_50 = V_24 -> V_131 ;
bool V_236 , V_237 , V_238 , V_135 , V_239 ;
V_236 = ! ! ( V_50 [ 1 ] & 0x8 ) ;
V_209 = ( V_50 [ 2 ] & 0xc0 ) >> 6 ;
V_229 = V_50 [ 2 ] & 0x3f ;
V_230 = V_50 [ 3 ] ;
V_238 = ( V_240 == V_50 [ 0 ] ) ;
V_237 = V_238 ? false : ! ! ( V_50 [ 1 ] & 0x10 ) ;
V_135 = ( V_139 == V_140 ) ;
if ( V_135 && ! V_236 )
V_231 = V_237 ? 16 : 8 ;
else
V_231 = 0 ;
V_132 = V_238 ? V_50 [ 4 ] : F_44 ( V_50 + 7 ) ;
memset ( V_82 , 0 , V_235 ) ;
if ( 0x3 == V_209 ) {
F_14 ( V_24 , V_41 , V_241 , 0 ) ;
return V_81 ;
}
V_100 = ( ( V_54 -> V_13 -> V_17 -> V_149 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
if ( V_135 )
V_232 = 0x10 ;
else
V_232 = 0x0 ;
if ( V_238 ) {
V_82 [ 2 ] = V_232 ;
V_82 [ 3 ] = V_231 ;
V_187 = 4 ;
} else {
V_82 [ 3 ] = V_232 ;
if ( 16 == V_231 )
V_82 [ 4 ] = 0x1 ;
V_82 [ 7 ] = V_231 ;
V_187 = 8 ;
}
V_234 = V_82 + V_187 ;
if ( ( V_231 > 0 ) && ( ! V_170 ) )
V_170 = F_52 () ;
if ( 8 == V_231 ) {
if ( V_170 > 0xfffffffe )
F_40 ( 0xffffffff , V_234 + 0 ) ;
else
F_40 ( V_170 , V_234 + 0 ) ;
F_13 ( V_8 , V_234 + 6 ) ;
V_187 += V_231 ;
V_234 = V_82 + V_187 ;
} else if ( 16 == V_231 ) {
F_34 ( ( V_172 ) V_170 , V_234 + 0 ) ;
F_40 ( V_8 , V_234 + 12 ) ;
V_187 += V_231 ;
V_234 = V_82 + V_187 ;
}
if ( ( V_230 > 0x0 ) && ( V_230 < 0xff ) && ( 0x19 != V_229 ) ) {
F_10 ( V_24 , V_145 , 3 , - 1 ) ;
return V_81 ;
}
V_239 = false ;
switch ( V_229 ) {
case 0x1 :
V_147 = F_59 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
break;
case 0x2 :
V_147 = F_60 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
break;
case 0x3 :
if ( V_135 ) {
V_147 = F_61 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
} else
V_239 = true ;
break;
case 0x8 :
if ( V_135 ) {
V_147 = F_62 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
} else
V_239 = true ;
break;
case 0xa :
V_147 = F_63 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
break;
case 0x19 :
if ( ( V_230 > 0x2 ) && ( V_230 < 0xff ) ) {
F_10 ( V_24 , V_145 , 3 , - 1 ) ;
return V_81 ;
}
V_147 = 0 ;
if ( ( 0x0 == V_230 ) || ( 0xff == V_230 ) )
V_147 += F_65 ( V_234 + V_147 , V_209 , V_57 ) ;
if ( ( 0x1 == V_230 ) || ( 0xff == V_230 ) )
V_147 += F_66 ( V_234 + V_147 , V_209 , V_57 ,
V_100 ) ;
if ( ( 0x2 == V_230 ) || ( 0xff == V_230 ) )
V_147 += F_67 ( V_234 + V_147 , V_209 ) ;
V_187 += V_147 ;
break;
case 0x1c :
V_147 = F_64 ( V_234 , V_209 , V_57 ) ;
V_187 += V_147 ;
break;
case 0x3f :
if ( ( 0 == V_230 ) || ( 0xff == V_230 ) ) {
V_147 = F_59 ( V_234 , V_209 , V_57 ) ;
V_147 += F_60 ( V_234 + V_147 , V_209 , V_57 ) ;
if ( V_135 ) {
V_147 += F_61 ( V_234 + V_147 , V_209 ,
V_57 ) ;
V_147 += F_62 ( V_234 + V_147 , V_209 ,
V_57 ) ;
}
V_147 += F_63 ( V_234 + V_147 , V_209 , V_57 ) ;
V_147 += F_65 ( V_234 + V_147 , V_209 , V_57 ) ;
if ( 0xff == V_230 ) {
V_147 += F_66 ( V_234 + V_147 , V_209 ,
V_57 , V_100 ) ;
V_147 += F_67 ( V_234 + V_147 , V_209 ) ;
}
V_147 += F_64 ( V_234 + V_147 , V_209 , V_57 ) ;
V_187 += V_147 ;
} else {
F_10 ( V_24 , V_145 , 3 , - 1 ) ;
return V_81 ;
}
break;
default:
V_239 = true ;
break;
}
if ( V_239 ) {
F_10 ( V_24 , V_145 , 2 , 5 ) ;
return V_81 ;
}
if ( V_238 )
V_82 [ 0 ] = V_187 - 1 ;
else
F_13 ( ( V_187 - 2 ) , V_82 + 0 ) ;
return F_22 ( V_24 , V_82 , F_30 ( V_132 , V_187 ) ) ;
}
static int F_69 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_242 , V_243 , V_244 , V_245 , V_231 , V_246 , V_247 , V_248 ;
int V_249 , V_250 , V_251 ;
unsigned char V_82 [ V_252 ] ;
unsigned char * V_50 = V_24 -> V_131 ;
int V_253 = ( V_254 == V_50 [ 0 ] ) ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_242 = V_50 [ 1 ] & 0x10 ;
V_243 = V_50 [ 1 ] & 0x1 ;
V_249 = V_253 ? V_50 [ 4 ] : F_44 ( V_50 + 7 ) ;
if ( ( 0 == V_242 ) || V_243 || ( V_249 > V_252 ) ) {
F_10 ( V_24 , V_145 , V_253 ? 4 : 7 , - 1 ) ;
return V_81 ;
}
V_250 = F_31 ( V_24 , V_82 , V_249 ) ;
if ( - 1 == V_250 )
return V_90 << 16 ;
else if ( V_42 && ( V_250 < V_249 ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_24 ,
V_36 , V_249 , V_250 ) ;
V_245 = V_253 ? ( V_82 [ 0 ] + 1 ) : ( F_44 ( V_82 + 0 ) + 2 ) ;
V_231 = V_253 ? V_82 [ 3 ] : F_44 ( V_82 + 6 ) ;
if ( V_245 > 2 ) {
F_10 ( V_24 , V_255 , 0 , - 1 ) ;
return V_81 ;
}
V_246 = V_231 + ( V_253 ? 4 : 8 ) ;
V_251 = V_82 [ V_246 ] & 0x3f ;
V_244 = ! ! ( V_82 [ V_246 ] & 0x80 ) ;
if ( V_244 ) {
F_10 ( V_24 , V_255 , V_246 , 7 ) ;
return V_81 ;
}
V_247 = ! ! ( V_82 [ V_246 ] & 0x40 ) ;
V_248 = V_247 ? ( F_44 ( V_82 + V_246 + 2 ) + 4 ) :
( V_82 [ V_246 + 1 ] + 2 ) ;
if ( ( V_248 + V_246 ) > V_249 ) {
F_14 ( V_24 , V_41 ,
V_256 , 0 ) ;
return V_81 ;
}
switch ( V_251 ) {
case 0x8 :
if ( V_218 [ 1 ] == V_82 [ V_246 + 1 ] ) {
memcpy ( V_218 + 2 , V_82 + V_246 + 2 ,
sizeof( V_218 ) - 2 ) ;
goto V_257;
}
break;
case 0xa :
if ( V_221 [ 1 ] == V_82 [ V_246 + 1 ] ) {
memcpy ( V_221 + 2 , V_82 + V_246 + 2 ,
sizeof( V_221 ) - 2 ) ;
V_40 = ! ! ( V_221 [ 2 ] & 0x4 ) ;
goto V_257;
}
break;
case 0x1c :
if ( V_160 [ 1 ] == V_82 [ V_246 + 1 ] ) {
memcpy ( V_160 + 2 , V_82 + V_246 + 2 ,
sizeof( V_160 ) - 2 ) ;
goto V_257;
}
break;
default:
break;
}
F_10 ( V_24 , V_255 , V_246 , 5 ) ;
return V_81 ;
V_257:
F_70 ( V_69 , V_54 -> V_59 ) ;
return 0 ;
}
static int F_71 ( unsigned char * V_82 )
{
unsigned char V_258 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_82 , V_258 , sizeof( V_258 ) ) ;
return sizeof( V_258 ) ;
}
static int F_72 ( unsigned char * V_82 )
{
unsigned char V_259 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_82 , V_259 , sizeof( V_259 ) ) ;
if ( V_160 [ 2 ] & 0x4 ) {
V_82 [ 4 ] = V_161 ;
V_82 [ 5 ] = 0xff ;
}
return sizeof( V_259 ) ;
}
static int F_73 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_260 , V_243 , V_209 , V_229 , V_230 , V_132 , V_147 , V_96 ;
unsigned char V_82 [ V_261 ] ;
unsigned char * V_50 = V_24 -> V_131 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_260 = V_50 [ 1 ] & 0x2 ;
V_243 = V_50 [ 1 ] & 0x1 ;
if ( V_260 || V_243 ) {
F_10 ( V_24 , V_145 , 1 , V_260 ? 1 : 0 ) ;
return V_81 ;
}
V_209 = ( V_50 [ 2 ] & 0xc0 ) >> 6 ;
V_229 = V_50 [ 2 ] & 0x3f ;
V_230 = V_50 [ 3 ] & 0xff ;
V_132 = F_44 ( V_50 + 7 ) ;
V_82 [ 0 ] = V_229 ;
if ( 0 == V_230 ) {
switch ( V_229 ) {
case 0x0 :
V_96 = 4 ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0xd ;
V_82 [ V_96 ++ ] = 0x2f ;
V_82 [ 3 ] = V_96 - 4 ;
break;
case 0xd :
V_82 [ 3 ] = F_71 ( V_82 + 4 ) ;
break;
case 0x2f :
V_82 [ 3 ] = F_72 ( V_82 + 4 ) ;
break;
default:
F_10 ( V_24 , V_145 , 2 , 5 ) ;
return V_81 ;
}
} else if ( 0xff == V_230 ) {
V_82 [ 0 ] |= 0x40 ;
V_82 [ 1 ] = V_230 ;
switch ( V_229 ) {
case 0x0 :
V_96 = 4 ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0xff ;
V_82 [ V_96 ++ ] = 0xd ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x2f ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ 3 ] = V_96 - 4 ;
break;
case 0xd :
V_96 = 4 ;
V_82 [ V_96 ++ ] = 0xd ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ 3 ] = V_96 - 4 ;
break;
case 0x2f :
V_96 = 4 ;
V_82 [ V_96 ++ ] = 0x2f ;
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ 3 ] = V_96 - 4 ;
break;
default:
F_10 ( V_24 , V_145 , 2 , 5 ) ;
return V_81 ;
}
} else {
F_10 ( V_24 , V_145 , 3 , - 1 ) ;
return V_81 ;
}
V_147 = F_30 ( F_44 ( V_82 + 2 ) + 4 , V_132 ) ;
return F_22 ( V_24 , V_82 ,
F_30 ( V_147 , V_136 ) ) ;
}
static int F_74 ( struct V_23 * V_24 ,
unsigned long long V_5 , unsigned int V_105 )
{
if ( V_5 + V_105 > V_170 ) {
F_14 ( V_24 , V_41 , V_262 , 0 ) ;
return V_81 ;
}
if ( V_105 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
return 0 ;
}
static int F_75 ( struct V_23 * V_263 , V_172 V_5 , T_7 V_105 ,
bool V_264 )
{
int V_133 ;
V_172 V_265 , V_266 = 0 ;
struct V_85 * V_86 ;
enum V_267 V_268 ;
if ( V_264 ) {
V_86 = F_76 ( V_263 ) ;
V_268 = V_98 ;
} else {
V_86 = F_23 ( V_263 ) ;
V_268 = V_89 ;
}
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_24 ( V_263 ) || V_263 -> V_88 == V_268 ) )
return - 1 ;
V_265 = F_3 ( V_5 , V_6 ) ;
if ( V_265 + V_105 > V_6 )
V_266 = V_265 + V_105 - V_6 ;
V_133 = F_77 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 + ( V_265 * V_8 ) ,
( V_105 - V_266 ) * V_8 , 0 , V_264 ) ;
if ( V_133 != ( V_105 - V_266 ) * V_8 )
return V_133 ;
if ( V_266 ) {
V_133 += F_77 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 , V_266 * V_8 ,
( V_105 - V_266 ) * V_8 , V_264 ) ;
}
return V_133 ;
}
static bool F_78 ( V_172 V_5 , T_7 V_105 , const T_2 * V_82 )
{
bool V_250 ;
V_172 V_265 , V_266 = 0 ;
T_7 V_269 = V_6 ;
T_7 V_270 = V_8 ;
V_265 = F_3 ( V_5 , V_269 ) ;
if ( V_265 + V_105 > V_269 )
V_266 = V_265 + V_105 - V_269 ;
V_250 = ! memcmp ( V_7 + ( V_265 * V_270 ) , V_82 ,
( V_105 - V_266 ) * V_270 ) ;
if ( ! V_250 )
return V_250 ;
if ( V_266 )
V_250 = memcmp ( V_7 , V_82 + ( ( V_105 - V_266 ) * V_270 ) ,
V_266 * V_270 ) ;
if ( ! V_250 )
return V_250 ;
V_82 += V_105 * V_270 ;
memcpy ( V_7 + ( V_265 * V_270 ) , V_82 , ( V_105 - V_266 ) * V_270 ) ;
if ( V_266 )
memcpy ( V_7 , V_82 + ( ( V_105 - V_266 ) * V_270 ) ,
V_266 * V_270 ) ;
return V_250 ;
}
static T_8 F_79 ( const void * V_271 , int V_147 )
{
T_8 V_272 ;
if ( V_273 )
V_272 = ( V_274 T_8 ) F_80 ( V_271 , V_147 ) ;
else
V_272 = F_81 ( F_82 ( V_271 , V_147 ) ) ;
return V_272 ;
}
static int F_83 ( struct V_9 * V_275 , const void * V_276 ,
T_1 V_10 , T_7 V_277 )
{
T_8 V_272 = F_79 ( V_276 , V_8 ) ;
if ( V_275 -> V_278 != V_272 ) {
F_84 ( L_25 ,
( unsigned long ) V_10 ,
F_85 ( V_275 -> V_278 ) ,
F_85 ( V_272 ) ) ;
return 0x01 ;
}
if ( V_152 == V_279 &&
F_86 ( V_275 -> V_280 ) != ( V_10 & 0xffffffff ) ) {
F_84 ( L_26 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
if ( V_152 == V_281 &&
F_86 ( V_275 -> V_280 ) != V_277 ) {
F_84 ( L_26 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
return 0 ;
}
static void F_87 ( struct V_23 * V_282 , T_1 V_10 ,
unsigned int V_283 , bool V_284 )
{
T_9 V_94 ;
void * V_285 ;
const void * V_286 = V_11 + V_6 ;
struct V_287 V_288 ;
V_94 = V_283 * sizeof( * V_11 ) ;
F_88 ( & V_288 , F_89 ( V_282 ) ,
F_90 ( V_282 ) , V_289 |
( V_284 ? V_290 : V_291 ) ) ;
while ( F_91 ( & V_288 ) && V_94 > 0 ) {
T_9 V_147 = F_30 ( V_288 . V_87 , V_94 ) ;
void * V_292 = F_4 ( V_10 ) ;
T_9 V_266 = 0 ;
if ( V_286 < V_292 + V_147 )
V_266 = V_292 + V_147 - V_286 ;
V_285 = V_288 . V_293 ;
if ( V_284 )
memcpy ( V_285 , V_292 , V_147 - V_266 ) ;
else
memcpy ( V_292 , V_285 , V_147 - V_266 ) ;
if ( V_266 ) {
if ( V_284 )
memcpy ( V_285 + V_147 - V_266 , V_11 , V_266 ) ;
else
memcpy ( V_11 , V_285 + V_147 - V_266 , V_266 ) ;
}
V_10 += V_147 / sizeof( * V_11 ) ;
V_94 -= V_147 ;
}
F_92 ( & V_288 ) ;
}
static int F_93 ( struct V_23 * V_282 , T_1 V_294 ,
unsigned int V_283 , T_7 V_277 )
{
unsigned int V_295 ;
struct V_9 * V_275 ;
T_1 V_10 ;
for ( V_295 = 0 ; V_295 < V_283 ; V_295 ++ , V_277 ++ ) {
int V_133 ;
V_10 = V_294 + V_295 ;
V_275 = F_4 ( V_10 ) ;
if ( V_275 -> V_296 == F_81 ( 0xffff ) )
continue;
V_133 = F_83 ( V_275 , F_2 ( V_10 ) , V_10 , V_277 ) ;
if ( V_133 ) {
V_297 ++ ;
return V_133 ;
}
}
F_87 ( V_282 , V_294 , V_283 , true ) ;
V_298 ++ ;
return 0 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
struct V_299 * V_300 ;
V_172 V_5 ;
T_7 V_105 ;
T_7 V_277 ;
unsigned long V_301 ;
int V_133 ;
bool V_302 ;
switch ( V_50 [ 0 ] ) {
case V_303 :
V_277 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
V_302 = true ;
break;
case V_304 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_302 = true ;
break;
case V_305 :
V_277 = 0 ;
V_5 = ( T_7 ) V_50 [ 3 ] | ( T_7 ) V_50 [ 2 ] << 8 |
( T_7 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_105 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_302 = true ;
break;
case V_306 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 6 ) ;
V_302 = true ;
break;
case V_307 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_302 = false ;
break;
default:
V_5 = F_95 ( V_50 + 12 ) ;
V_277 = F_55 ( V_50 + 20 ) ;
V_105 = F_55 ( V_50 + 28 ) ;
V_302 = false ;
break;
}
if ( F_96 ( V_154 && V_302 ) ) {
if ( V_152 == V_281 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_152 == V_279 ||
V_152 == V_153 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_27
L_28 ) ;
}
if ( F_96 ( V_308 ) ) {
V_300 = (struct V_299 * ) V_24 -> V_309 ;
if ( V_300 ) {
if ( V_300 -> V_310 )
V_105 /= 2 ;
}
} else
V_300 = NULL ;
if ( F_96 ( V_5 + V_105 > V_170 ) ) {
F_14 ( V_24 , V_41 , V_262 , 0 ) ;
return V_81 ;
}
if ( F_96 ( V_105 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
if ( F_96 ( ( V_311 & V_217 ) &&
( V_5 <= ( V_312 + V_313 - 1 ) ) &&
( ( V_5 + V_105 ) > V_312 ) ) ) {
F_14 ( V_24 , V_314 , V_315 , 0 ) ;
if ( 0x70 == ( V_24 -> V_33 [ 0 ] & 0x7f ) ) {
V_24 -> V_33 [ 0 ] |= 0x80 ;
V_133 = ( V_5 < V_312 )
? V_312 : ( int ) V_5 ;
F_40 ( V_133 , V_24 -> V_33 + 3 ) ;
}
F_97 ( V_24 , F_26 ( V_24 ) ) ;
return V_81 ;
}
F_98 ( & V_316 , V_301 ) ;
if ( F_96 ( V_317 && F_90 ( V_24 ) ) ) {
int V_318 = F_93 ( V_24 , V_5 , V_105 , V_277 ) ;
if ( V_318 ) {
F_99 ( & V_316 , V_301 ) ;
F_14 ( V_24 , V_319 , 0x10 , V_318 ) ;
return V_320 ;
}
}
V_133 = F_75 ( V_24 , V_5 , V_105 , false ) ;
F_99 ( & V_316 , V_301 ) ;
if ( F_96 ( V_133 == - 1 ) )
return V_90 << 16 ;
F_23 ( V_24 ) -> V_94 = F_26 ( V_24 ) - V_133 ;
if ( F_96 ( V_300 ) ) {
if ( V_300 -> V_321 ) {
F_14 ( V_24 , V_322 ,
V_161 , 0 ) ;
return V_81 ;
} else if ( V_300 -> V_323 ) {
F_14 ( V_24 , V_319 ,
V_324 , V_325 ) ;
return V_81 ;
} else if ( V_300 -> V_326 ) {
F_14 ( V_24 , V_319 , 0x10 , 1 ) ;
return V_320 ;
} else if ( V_300 -> V_327 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_320 ;
}
}
return 0 ;
}
static void F_100 ( unsigned char * V_271 , int V_147 )
{
int V_295 , V_328 , V_96 ;
F_84 ( L_29 ) ;
for ( V_295 = 0 ; V_295 < V_147 ; V_295 += 16 ) {
char V_107 [ 128 ] ;
for ( V_328 = 0 , V_96 = 0 ; V_328 < 16 ; V_328 ++ ) {
unsigned char V_329 = V_271 [ V_295 + V_328 ] ;
if ( V_329 >= 0x20 && V_329 < 0x7e )
V_96 += F_48 ( V_107 + V_96 , sizeof( V_107 ) - V_96 ,
L_30 , V_271 [ V_295 + V_328 ] ) ;
else
V_96 += F_48 ( V_107 + V_96 , sizeof( V_107 ) - V_96 ,
L_31 , V_271 [ V_295 + V_328 ] ) ;
}
F_84 ( L_32 , V_295 , V_107 ) ;
}
}
static int F_101 ( struct V_23 * V_282 , T_1 V_294 ,
unsigned int V_283 , T_7 V_277 )
{
int V_133 ;
struct V_9 * V_275 ;
void * V_330 ;
T_1 V_10 = V_294 ;
int V_331 ;
int V_332 ;
struct V_287 V_333 ;
struct V_287 V_334 ;
F_102 ( F_103 ( V_282 ) == 0 ) ;
F_102 ( F_90 ( V_282 ) == 0 ) ;
F_88 ( & V_334 , F_89 ( V_282 ) ,
F_90 ( V_282 ) ,
V_289 | V_291 ) ;
F_88 ( & V_333 , F_104 ( V_282 ) , F_103 ( V_282 ) ,
V_289 | V_291 ) ;
while ( F_91 ( & V_334 ) ) {
V_332 = 0 ;
if ( F_105 ( ! F_91 ( & V_333 ) ) ) {
V_133 = 0x01 ;
goto V_335;
}
for ( V_331 = 0 ; V_331 < V_334 . V_87 ;
V_331 += sizeof( struct V_9 ) ) {
if ( V_332 >= V_333 . V_87 ) {
if ( F_105 ( ! F_91 ( & V_333 ) ) ) {
V_133 = 0x01 ;
goto V_335;
}
V_332 = 0 ;
}
V_275 = V_334 . V_293 + V_331 ;
V_330 = V_333 . V_293 + V_332 ;
V_133 = F_83 ( V_275 , V_330 , V_10 , V_277 ) ;
if ( V_133 ) {
F_100 ( V_330 , V_8 ) ;
goto V_335;
}
V_10 ++ ;
V_277 ++ ;
V_332 += V_8 ;
}
V_333 . V_336 = V_332 ;
F_92 ( & V_333 ) ;
}
F_92 ( & V_334 ) ;
F_87 ( V_282 , V_294 , V_283 , false ) ;
V_337 ++ ;
return 0 ;
V_335:
V_297 ++ ;
F_92 ( & V_333 ) ;
F_92 ( & V_334 ) ;
return V_133 ;
}
static unsigned long F_106 ( T_1 V_5 )
{
if ( V_126 )
V_5 += V_127 - V_126 ;
F_5 ( V_5 , V_127 ) ;
return V_5 ;
}
static T_1 F_107 ( unsigned long V_338 )
{
T_1 V_5 = V_338 * V_127 ;
if ( V_126 )
V_5 -= V_127 - V_126 ;
return V_5 ;
}
static unsigned int F_108 ( T_1 V_5 , unsigned int * V_105 )
{
T_1 V_339 ;
unsigned int V_340 ;
unsigned long V_338 ;
unsigned long V_341 ;
V_338 = F_106 ( V_5 ) ;
V_340 = F_109 ( V_338 , V_342 ) ;
if ( V_340 )
V_341 = F_110 ( V_342 , V_343 , V_338 ) ;
else
V_341 = F_111 ( V_342 , V_343 , V_338 ) ;
V_339 = F_112 ( T_1 , V_6 , F_107 ( V_341 ) ) ;
* V_105 = V_339 - V_5 ;
return V_340 ;
}
static void F_113 ( T_1 V_5 , unsigned int V_147 )
{
T_1 V_339 = V_5 + V_147 ;
while ( V_5 < V_339 ) {
unsigned long V_338 = F_106 ( V_5 ) ;
if ( V_338 < V_343 )
F_70 ( V_338 , V_342 ) ;
V_5 = F_107 ( V_338 + 1 ) ;
}
}
static void F_114 ( T_1 V_5 , unsigned int V_147 )
{
T_1 V_339 = V_5 + V_147 ;
while ( V_5 < V_339 ) {
unsigned long V_338 = F_106 ( V_5 ) ;
if ( V_5 == F_107 ( V_338 ) &&
V_5 + V_127 <= V_339 &&
V_338 < V_343 ) {
F_18 ( V_338 , V_342 ) ;
if ( V_129 ) {
memset ( V_7 +
V_5 * V_8 ,
( V_129 & 1 ) ? 0 : 0xff ,
V_8 *
V_127 ) ;
}
if ( V_11 ) {
memset ( V_11 + V_5 , 0xff ,
sizeof( * V_11 ) *
V_127 ) ;
}
}
V_5 = F_107 ( V_338 + 1 ) ;
}
}
static int F_115 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
V_172 V_5 ;
T_7 V_105 ;
T_7 V_277 ;
unsigned long V_301 ;
int V_133 ;
bool V_302 ;
switch ( V_50 [ 0 ] ) {
case V_344 :
V_277 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
V_302 = true ;
break;
case V_345 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_302 = true ;
break;
case V_346 :
V_277 = 0 ;
V_5 = ( T_7 ) V_50 [ 3 ] | ( T_7 ) V_50 [ 2 ] << 8 |
( T_7 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_105 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_302 = true ;
break;
case V_347 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 6 ) ;
V_302 = true ;
break;
case 0x53 :
V_277 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_302 = false ;
break;
default:
V_5 = F_95 ( V_50 + 12 ) ;
V_277 = F_55 ( V_50 + 20 ) ;
V_105 = F_55 ( V_50 + 28 ) ;
V_302 = false ;
break;
}
if ( F_96 ( V_154 && V_302 ) ) {
if ( V_152 == V_281 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_152 == V_279 ||
V_152 == V_153 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_33
L_28 ) ;
}
if ( F_96 ( V_5 + V_105 > V_170 ) ) {
F_14 ( V_24 , V_41 , V_262 , 0 ) ;
return V_81 ;
}
if ( F_96 ( V_105 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
F_116 ( & V_316 , V_301 ) ;
if ( F_96 ( V_317 && F_90 ( V_24 ) ) ) {
int V_318 = F_101 ( V_24 , V_5 , V_105 , V_277 ) ;
if ( V_318 ) {
F_117 ( & V_316 , V_301 ) ;
F_14 ( V_24 , V_41 , 0x10 , V_318 ) ;
return V_320 ;
}
}
V_133 = F_75 ( V_24 , V_5 , V_105 , true ) ;
if ( F_96 ( F_1 () ) )
F_113 ( V_5 , V_105 ) ;
F_117 ( & V_316 , V_301 ) ;
if ( F_96 ( - 1 == V_133 ) )
return V_90 << 16 ;
else if ( F_96 ( V_42 &&
( V_133 < ( V_105 * V_8 ) ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_34 ,
V_44 , V_105 * V_8 , V_133 ) ;
if ( F_96 ( V_308 ) ) {
struct V_299 * V_300 =
(struct V_299 * ) V_24 -> V_309 ;
if ( V_300 ) {
if ( V_300 -> V_321 ) {
F_14 ( V_24 , V_322 ,
V_161 , 0 ) ;
return V_81 ;
} else if ( V_300 -> V_326 ) {
F_14 ( V_24 , V_319 , 0x10 , 1 ) ;
return V_320 ;
} else if ( V_300 -> V_327 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_320 ;
}
}
}
return 0 ;
}
static int F_118 ( struct V_23 * V_24 , V_172 V_5 , T_7 V_105 ,
T_7 V_277 , bool V_348 , bool V_349 )
{
unsigned long V_301 ;
unsigned long long V_295 ;
int V_133 ;
V_172 V_350 ;
V_133 = F_74 ( V_24 , V_5 , V_105 ) ;
if ( V_133 )
return V_133 ;
F_116 ( & V_316 , V_301 ) ;
if ( V_348 && F_1 () ) {
F_114 ( V_5 , V_105 ) ;
goto V_335;
}
V_350 = V_5 * V_8 ;
if ( V_349 ) {
memset ( V_7 + V_350 , 0 , V_8 ) ;
V_133 = 0 ;
} else
V_133 = F_31 ( V_24 , V_7 + V_350 ,
V_8 ) ;
if ( - 1 == V_133 ) {
F_117 ( & V_316 , V_301 ) ;
return V_90 << 16 ;
} else if ( V_42 && ( V_133 < ( V_105 * V_8 ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_35 ,
V_44 , L_36 ,
V_105 * V_8 , V_133 ) ;
for ( V_295 = 1 ; V_295 < V_105 ; V_295 ++ )
memcpy ( V_7 + ( ( V_5 + V_295 ) * V_8 ) ,
V_7 + V_350 ,
V_8 ) ;
if ( F_1 () )
F_113 ( V_5 , V_105 ) ;
V_335:
F_117 ( & V_316 , V_301 ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
T_7 V_5 ;
T_6 V_105 ;
T_7 V_277 = 0 ;
bool V_348 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_4 == 0 ) {
F_10 ( V_24 , V_145 , 1 , 3 ) ;
return V_81 ;
} else
V_348 = true ;
}
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
if ( V_105 > V_128 ) {
F_10 ( V_24 , V_145 , 7 , - 1 ) ;
return V_81 ;
}
return F_118 ( V_24 , V_5 , V_105 , V_277 , V_348 , false ) ;
}
static int F_120 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
V_172 V_5 ;
T_7 V_105 ;
T_7 V_277 = 0 ;
bool V_348 = false ;
bool V_349 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_3 == 0 ) {
F_10 ( V_24 , V_145 , 1 , 3 ) ;
return V_81 ;
} else
V_348 = true ;
}
if ( V_50 [ 1 ] & 0x1 )
V_349 = true ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
if ( V_105 > V_128 ) {
F_10 ( V_24 , V_145 , 10 , - 1 ) ;
return V_81 ;
}
return F_118 ( V_24 , V_5 , V_105 , V_277 , V_348 , V_349 ) ;
}
static int F_121 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
struct V_48 * V_351 = V_24 -> V_35 ;
struct V_53 * V_56 ;
T_2 V_352 ;
V_352 = V_50 [ 1 ] & 0x1f ;
switch ( V_352 ) {
case 0x4 :
F_70 ( V_67 , V_54 -> V_59 ) ;
F_70 ( V_74 , V_54 -> V_59 ) ;
break;
case 0x5 :
F_70 ( V_77 , V_54 -> V_59 ) ;
break;
case 0x6 :
F_8 (dp,
&devip->sdbg_host->dev_info_list,
dev_list)
if ( V_56 -> V_57 == V_351 -> V_233 ) {
F_70 ( V_67 , V_56 -> V_59 ) ;
if ( V_54 != V_56 )
F_70 ( V_74 ,
V_56 -> V_59 ) ;
}
break;
case 0x7 :
F_8 (dp,
&devip->sdbg_host->dev_info_list,
dev_list)
if ( V_56 -> V_57 == V_351 -> V_233 )
F_70 ( V_77 ,
V_56 -> V_59 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_122 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
T_2 * V_82 ;
T_2 * V_353 ;
V_172 V_5 ;
T_7 V_354 ;
T_7 V_270 = V_8 ;
T_2 V_105 ;
unsigned long V_301 ;
int V_133 ;
int V_355 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = V_50 [ 13 ] ;
if ( 0 == V_105 )
return 0 ;
if ( V_152 == V_281 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_152 == V_279 ||
V_152 == V_153 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_33
L_28 ) ;
if ( V_5 + V_105 > V_170 ) {
F_14 ( V_24 , V_41 , V_262 , 0 ) ;
return V_81 ;
}
if ( V_105 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
V_354 = 2 * V_105 ;
V_82 = F_45 ( V_354 * V_270 , V_137 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_195 ,
V_196 ) ;
return V_81 ;
}
F_116 ( & V_316 , V_301 ) ;
V_353 = V_7 ;
V_7 = V_82 ;
V_133 = F_75 ( V_24 , 0 , V_354 , true ) ;
V_7 = V_353 ;
if ( V_133 == - 1 ) {
V_355 = V_90 << 16 ;
goto V_356;
} else if ( V_42 && ( V_133 < ( V_354 * V_270 ) ) )
F_11 ( V_43 , V_24 -> V_35 , L_37
L_38 , V_44 ,
V_354 * V_270 , V_133 ) ;
if ( ! F_78 ( V_5 , V_105 , V_82 ) ) {
F_14 ( V_24 , V_357 , V_358 , 0 ) ;
V_355 = V_81 ;
goto V_356;
}
if ( F_1 () )
F_113 ( V_5 , V_105 ) ;
V_356:
F_117 ( & V_316 , V_301 ) ;
F_47 ( V_82 ) ;
return V_355 ;
}
static int F_123 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char * V_271 ;
struct V_359 * V_360 ;
unsigned int V_295 , V_361 , V_362 ;
int V_133 ;
unsigned long V_301 ;
if ( ! F_1 () )
return 0 ;
V_361 = F_44 ( V_24 -> V_131 + 7 ) ;
F_102 ( F_26 ( V_24 ) != V_361 ) ;
V_362 = ( V_361 - 8 ) / 16 ;
if ( V_362 > V_125 ) {
F_10 ( V_24 , V_145 , 7 , - 1 ) ;
return V_81 ;
}
V_271 = F_45 ( F_26 ( V_24 ) , V_137 ) ;
if ( ! V_271 ) {
F_14 ( V_24 , V_41 , V_195 ,
V_196 ) ;
return V_81 ;
}
F_32 ( V_24 , V_271 , F_26 ( V_24 ) ) ;
F_102 ( F_44 ( & V_271 [ 0 ] ) != V_361 - 2 ) ;
F_102 ( F_44 ( & V_271 [ 2 ] ) != V_362 * 16 ) ;
V_360 = ( void * ) & V_271 [ 8 ] ;
F_116 ( & V_316 , V_301 ) ;
for ( V_295 = 0 ; V_295 < V_362 ; V_295 ++ ) {
unsigned long long V_5 = F_95 ( & V_360 [ V_295 ] . V_5 ) ;
unsigned int V_105 = F_55 ( & V_360 [ V_295 ] . V_363 ) ;
V_133 = F_74 ( V_24 , V_5 , V_105 ) ;
if ( V_133 )
goto V_335;
F_114 ( V_5 , V_105 ) ;
}
V_133 = 0 ;
V_335:
F_117 ( & V_316 , V_301 ) ;
F_47 ( V_271 ) ;
return V_133 ;
}
static int F_124 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
V_172 V_5 ;
T_7 V_132 , V_340 , V_105 ;
T_2 V_82 [ V_364 ] ;
int V_133 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_132 = F_55 ( V_50 + 10 ) ;
if ( V_132 < 24 )
return 0 ;
V_133 = F_74 ( V_24 , V_5 , 1 ) ;
if ( V_133 )
return V_133 ;
if ( F_1 () )
V_340 = F_108 ( V_5 , & V_105 ) ;
else {
V_340 = 1 ;
V_170 = F_52 () ;
if ( V_170 - V_5 <= 0xffffffff )
V_105 = V_170 - V_5 ;
else
V_105 = 0xffffffff ;
}
memset ( V_82 , 0 , V_364 ) ;
F_40 ( 20 , V_82 ) ;
F_34 ( V_5 , V_82 + 8 ) ;
F_40 ( V_105 , V_82 + 16 ) ;
V_82 [ 20 ] = ! V_340 ;
return F_22 ( V_24 , V_82 , V_364 ) ;
}
static int F_125 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_131 ;
unsigned int V_132 ;
unsigned char V_365 ;
V_172 V_141 ;
struct V_366 * V_367 ;
T_2 V_82 [ V_368 * sizeof( struct V_366 ) ] ;
unsigned int V_369 ;
unsigned int V_370 ;
unsigned int V_371 ;
unsigned int V_175 ;
int V_60 , V_328 , V_96 , V_250 ;
unsigned int V_372 = 0 ;
const int V_373 = sizeof( struct V_366 ) ;
F_17 ( V_54 ) ;
V_365 = V_50 [ 2 ] ;
V_132 = F_55 ( V_50 + 6 ) ;
if ( V_132 < 4 ) {
F_84 ( L_39 , V_132 ) ;
F_10 ( V_24 , V_145 , 6 , - 1 ) ;
return V_81 ;
}
switch ( V_365 ) {
case 0 :
V_369 = V_374 ;
V_370 = 0 ;
break;
case 1 :
V_369 = 0 ;
V_370 = 1 ;
break;
case 2 :
V_369 = V_374 ;
V_370 = 1 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
default:
F_29 ( L_40 , V_365 ) ;
F_10 ( V_24 , V_145 , 2 , - 1 ) ;
return V_81 ;
}
if ( V_143 && ( V_369 > 0 ) )
-- V_369 ;
V_371 = V_369 + V_370 ;
V_175 = V_371 * V_373 ;
F_97 ( V_24 , F_26 ( V_24 ) ) ;
F_29 ( L_41 ,
V_365 , V_369 , V_370 , V_143 ) ;
V_141 = V_143 ? 1 : 0 ;
for ( V_60 = 0 , V_328 = 0 , V_250 = 0 ; true ; ++ V_60 , V_328 = 0 ) {
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_367 = (struct V_366 * ) & V_82 [ 0 ] ;
if ( V_60 == 0 ) {
F_40 ( V_175 , & V_82 [ 0 ] ) ;
++ V_367 ;
V_328 = 1 ;
}
for ( ; V_328 < V_368 ; ++ V_328 , ++ V_367 ) {
if ( ( V_60 * V_368 ) + V_328 > V_369 )
break;
F_126 ( V_141 ++ , V_367 ) ;
}
if ( V_328 < V_368 )
break;
V_96 = V_328 * V_373 ;
V_250 = F_27 ( V_24 , V_82 , V_96 , V_372 ) ;
if ( V_250 )
return V_250 ;
V_372 += V_96 ;
}
if ( V_370 ) {
F_126 ( V_22 , V_367 ) ;
++ V_328 ;
}
if ( V_328 > 0 )
V_250 = F_27 ( V_24 , V_82 , V_328 * V_373 , V_372 ) ;
return V_250 ;
}
static int F_127 ( struct V_23 * V_24 , unsigned long long V_5 ,
unsigned int V_105 , struct V_53 * V_54 )
{
int V_328 ;
unsigned char * V_375 , * V_271 ;
unsigned int V_187 ;
struct V_85 * V_86 = F_23 ( V_24 ) ;
struct V_287 V_288 ;
V_271 = F_45 ( F_26 ( V_24 ) , V_137 ) ;
if ( ! V_271 ) {
F_14 ( V_24 , V_41 , V_195 ,
V_196 ) ;
return V_81 ;
}
F_32 ( V_24 , V_271 , F_26 ( V_24 ) ) ;
V_187 = 0 ;
F_88 ( & V_288 , V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_289 | V_290 ) ;
while ( F_91 ( & V_288 ) ) {
V_375 = V_288 . V_293 ;
for ( V_328 = 0 ; V_328 < V_288 . V_87 ; V_328 ++ )
* ( V_375 + V_328 ) ^= * ( V_271 + V_187 + V_328 ) ;
V_187 += V_288 . V_87 ;
}
F_92 ( & V_288 ) ;
F_47 ( V_271 ) ;
return 0 ;
}
static int F_128 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_131 ;
V_172 V_5 ;
T_7 V_105 ;
int V_188 ;
if ( ! F_24 ( V_24 ) ) {
F_14 ( V_24 , V_41 , V_195 ,
V_196 ) ;
return V_81 ;
}
V_188 = F_94 ( V_24 , V_54 ) ;
if ( V_188 )
return V_188 ;
if ( ! ( V_50 [ 1 ] & 0x4 ) ) {
V_188 = F_115 ( V_24 , V_54 ) ;
if ( V_188 )
return V_188 ;
}
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
return F_127 ( V_24 , V_5 , V_105 , V_54 ) ;
}
static struct V_376 * F_129 ( struct V_23 * V_131 )
{
struct V_376 * V_377 = V_378 ;
if ( V_379 ) {
T_7 V_380 = F_130 ( V_131 -> V_381 ) ;
T_6 V_382 = F_131 ( V_380 ) ;
if ( F_96 ( V_382 >= V_383 ) ) {
F_21 ( L_42 , V_382 ) ;
V_382 %= V_383 ;
}
F_29 ( L_43 , V_380 , V_382 ) ;
return V_377 + V_382 ;
} else
return V_377 ;
}
static void F_132 ( struct V_384 * V_385 )
{
int V_386 ;
int V_387 = 0 ;
unsigned long V_301 ;
struct V_376 * V_377 ;
struct V_299 * V_300 ;
struct V_23 * V_24 ;
struct V_53 * V_54 ;
V_386 = V_385 -> V_386 ;
V_377 = V_378 + V_385 -> V_388 ;
if ( V_389 ) {
F_133 ( & V_390 ) ;
if ( F_134 () != V_385 -> V_391 )
F_133 ( & V_392 ) ;
}
if ( F_96 ( ( V_386 < 0 ) || ( V_386 >= V_393 ) ) ) {
F_84 ( L_44 , V_386 ) ;
return;
}
F_135 ( & V_377 -> V_394 , V_301 ) ;
V_300 = & V_377 -> V_395 [ V_386 ] ;
V_24 = V_300 -> V_396 ;
if ( F_96 ( V_24 == NULL ) ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
F_84 ( L_45 ,
V_385 -> V_388 , V_386 ) ;
return;
}
V_54 = (struct V_53 * ) V_24 -> V_35 -> V_397 ;
if ( F_137 ( V_54 ) )
F_138 ( & V_54 -> V_398 ) ;
else
F_84 ( L_46 ) ;
if ( F_96 ( F_139 ( & V_399 ) > 0 ) )
V_387 = 1 ;
V_300 -> V_396 = NULL ;
if ( F_96 ( ! F_140 ( V_386 , V_377 -> V_400 ) ) ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
F_84 ( L_47 ) ;
return;
}
if ( F_96 ( V_387 ) ) {
int V_60 , V_355 ;
V_355 = F_139 ( & V_399 ) ;
if ( V_386 >= V_355 ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
F_84 ( L_48 , V_355 ) ;
return;
}
V_60 = F_141 ( V_377 -> V_400 , V_355 ) ;
if ( ( V_60 < V_401 ) || ( V_60 == V_355 ) )
F_142 ( & V_399 , 0 ) ;
else
F_142 ( & V_399 , V_60 + 1 ) ;
}
F_136 ( & V_377 -> V_394 , V_301 ) ;
V_24 -> V_402 ( V_24 ) ;
}
static enum V_403 F_143 ( struct V_404 * V_405 )
{
struct V_384 * V_385 = F_144 ( V_405 , struct V_384 ,
V_406 ) ;
F_132 ( V_385 ) ;
return V_407 ;
}
static void F_145 ( struct V_408 * V_409 )
{
struct V_384 * V_385 = F_144 ( V_409 , struct V_384 ,
V_410 . V_409 ) ;
F_132 ( V_385 ) ;
}
static struct V_53 * F_146 (
struct V_12 * V_13 , T_10 V_200 )
{
struct V_53 * V_54 ;
V_54 = F_45 ( sizeof( * V_54 ) , V_200 ) ;
if ( V_54 ) {
if ( V_110 == 1 )
F_147 ( & V_54 -> V_104 ) ;
else if ( V_110 == 2 ) {
if ( V_411 )
V_54 -> V_104 = V_412 ;
else {
F_147 ( & V_412 ) ;
V_411 = true ;
V_54 -> V_104 = V_412 ;
}
}
V_54 -> V_13 = V_13 ;
F_148 ( & V_54 -> V_413 , & V_13 -> V_414 ) ;
}
return V_54 ;
}
static struct V_53 * F_149 ( struct V_48 * V_415 )
{
struct V_12 * V_13 ;
struct V_53 * V_416 = NULL ;
struct V_53 * V_54 ;
V_13 = * (struct V_12 * * ) F_150 ( V_415 -> V_417 ) ;
if ( ! V_13 ) {
F_84 ( L_49 ) ;
return NULL ;
}
F_8 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_54 -> V_418 ) && ( V_54 -> V_150 == V_415 -> V_150 ) &&
( V_54 -> V_57 == V_415 -> V_233 ) &&
( V_54 -> V_141 == V_415 -> V_141 ) )
return V_54 ;
else {
if ( ( ! V_54 -> V_418 ) && ( ! V_416 ) )
V_416 = V_54 ;
}
}
if ( ! V_416 ) {
V_416 = F_146 ( V_13 , V_137 ) ;
if ( ! V_416 ) {
F_84 ( L_50 , __LINE__ ) ;
return NULL ;
}
}
V_416 -> V_150 = V_415 -> V_150 ;
V_416 -> V_57 = V_415 -> V_233 ;
V_416 -> V_141 = V_415 -> V_141 ;
V_416 -> V_13 = V_13 ;
F_142 ( & V_416 -> V_398 , 0 ) ;
F_70 ( V_63 , V_416 -> V_59 ) ;
V_416 -> V_418 = true ;
return V_416 ;
}
static int F_151 ( struct V_48 * V_351 )
{
if ( V_42 )
F_152 ( L_51 ,
V_351 -> V_417 -> V_149 , V_351 -> V_150 , V_351 -> V_233 , V_351 -> V_141 ) ;
F_153 ( V_419 , V_351 -> V_420 ) ;
return 0 ;
}
static int F_154 ( struct V_48 * V_351 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_351 -> V_397 ;
if ( V_42 )
F_152 ( L_52 ,
V_351 -> V_417 -> V_149 , V_351 -> V_150 , V_351 -> V_233 , V_351 -> V_141 ) ;
if ( V_351 -> V_417 -> V_421 != V_422 )
V_351 -> V_417 -> V_421 = V_422 ;
if ( V_54 == NULL ) {
V_54 = F_149 ( V_351 ) ;
if ( V_54 == NULL )
return 1 ;
}
V_351 -> V_397 = V_54 ;
F_155 ( V_351 -> V_420 , - 1U ) ;
if ( V_423 )
V_351 -> V_424 = 1 ;
return 0 ;
}
static void F_156 ( struct V_48 * V_351 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_351 -> V_397 ;
if ( V_42 )
F_152 ( L_53 ,
V_351 -> V_417 -> V_149 , V_351 -> V_150 , V_351 -> V_233 , V_351 -> V_141 ) ;
if ( V_54 ) {
V_54 -> V_418 = false ;
V_351 -> V_397 = NULL ;
}
}
static void F_157 ( struct V_384 * V_385 )
{
if ( ! V_385 )
return;
if ( ( V_425 > 0 ) || ( V_426 > 0 ) )
F_158 ( & V_385 -> V_406 ) ;
else if ( V_425 < 0 )
F_159 ( & V_385 -> V_410 . V_409 ) ;
}
static bool F_160 ( struct V_23 * V_131 )
{
unsigned long V_301 ;
int V_328 , V_60 , V_427 , V_428 ;
struct V_376 * V_377 ;
struct V_299 * V_300 ;
struct V_53 * V_54 ;
struct V_384 * V_385 ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ; ++ V_328 , ++ V_377 ) {
F_135 ( & V_377 -> V_394 , V_301 ) ;
V_427 = V_401 ;
V_428 = F_139 ( & V_399 ) ;
if ( V_428 > V_427 )
V_427 = V_428 ;
for ( V_60 = 0 ; V_60 < V_427 ; ++ V_60 ) {
if ( F_109 ( V_60 , V_377 -> V_400 ) ) {
V_300 = & V_377 -> V_395 [ V_60 ] ;
if ( V_131 != V_300 -> V_396 )
continue;
V_54 = (struct V_53 * )
V_131 -> V_35 -> V_397 ;
if ( V_54 )
F_138 ( & V_54 -> V_398 ) ;
V_300 -> V_396 = NULL ;
V_385 = V_300 -> V_385 ;
F_136 ( & V_377 -> V_394 , V_301 ) ;
F_157 ( V_385 ) ;
F_18 ( V_60 , V_377 -> V_400 ) ;
return true ;
}
}
F_136 ( & V_377 -> V_394 , V_301 ) ;
}
return false ;
}
static void F_161 ( void )
{
unsigned long V_301 ;
int V_328 , V_60 ;
struct V_376 * V_377 ;
struct V_299 * V_300 ;
struct V_53 * V_54 ;
struct V_384 * V_385 ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ; ++ V_328 , ++ V_377 ) {
F_135 ( & V_377 -> V_394 , V_301 ) ;
for ( V_60 = 0 ; V_60 < V_393 ; ++ V_60 ) {
if ( F_109 ( V_60 , V_377 -> V_400 ) ) {
V_300 = & V_377 -> V_395 [ V_60 ] ;
if ( V_300 -> V_396 == NULL )
continue;
V_54 = (struct V_53 * )
V_300 -> V_396 -> V_35 -> V_397 ;
if ( V_54 )
F_138 ( & V_54 -> V_398 ) ;
V_300 -> V_396 = NULL ;
V_385 = V_300 -> V_385 ;
F_136 ( & V_377 -> V_394 , V_301 ) ;
F_157 ( V_385 ) ;
F_18 ( V_60 , V_377 -> V_400 ) ;
F_135 ( & V_377 -> V_394 , V_301 ) ;
}
}
F_136 ( & V_377 -> V_394 , V_301 ) ;
}
}
static void F_162 ( void )
{
int V_328 , V_60 ;
struct V_376 * V_377 ;
struct V_299 * V_300 ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ; ++ V_328 , ++ V_377 ) {
for ( V_60 = 0 ; V_60 < V_393 ; ++ V_60 ) {
V_300 = & V_377 -> V_395 [ V_60 ] ;
F_47 ( V_300 -> V_385 ) ;
V_300 -> V_385 = NULL ;
}
}
}
static int F_163 ( struct V_23 * V_282 )
{
bool V_429 ;
++ V_430 ;
if ( V_282 ) {
V_429 = F_160 ( V_282 ) ;
if ( V_282 -> V_35 && ( V_431 & V_217 ) )
F_11 ( V_43 , V_282 -> V_35 ,
L_54 , V_36 ,
V_429 ? L_55 : L_56 ) ;
}
return V_432 ;
}
static int F_164 ( struct V_23 * V_282 )
{
++ V_433 ;
if ( V_282 && V_282 -> V_35 ) {
struct V_48 * V_351 = V_282 -> V_35 ;
struct V_53 * V_54 =
(struct V_53 * ) V_351 -> V_397 ;
if ( V_431 & V_217 )
F_11 ( V_43 , V_351 , L_57 , V_36 ) ;
if ( V_54 )
F_70 ( V_63 , V_54 -> V_59 ) ;
}
return V_432 ;
}
static int F_165 ( struct V_23 * V_282 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_351 ;
struct V_14 * V_434 ;
int V_60 = 0 ;
++ V_435 ;
if ( ! V_282 )
goto V_436;
V_351 = V_282 -> V_35 ;
if ( ! V_351 )
goto V_436;
if ( V_431 & V_217 )
F_11 ( V_43 , V_351 , L_57 , V_36 ) ;
V_434 = V_351 -> V_417 ;
if ( ! V_434 )
goto V_436;
V_13 = * (struct V_12 * * ) F_150 ( V_434 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list)
if ( V_54 -> V_57 == V_351 -> V_233 ) {
F_70 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
if ( V_437 & V_217 )
F_11 ( V_43 , V_351 ,
L_58 , V_36 , V_60 ) ;
V_436:
return V_432 ;
}
static int F_166 ( struct V_23 * V_282 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_351 ;
struct V_14 * V_434 ;
int V_60 = 0 ;
++ V_438 ;
if ( ! ( V_282 && V_282 -> V_35 ) )
goto V_436;
V_351 = V_282 -> V_35 ;
if ( V_431 & V_217 )
F_11 ( V_43 , V_351 , L_57 , V_36 ) ;
V_434 = V_351 -> V_417 ;
if ( V_434 ) {
V_13 = * (struct V_12 * * ) F_150 ( V_434 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list) {
F_70 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
}
if ( V_437 & V_217 )
F_11 ( V_43 , V_351 ,
L_59 , V_36 , V_60 ) ;
V_436:
return V_432 ;
}
static int F_167 ( struct V_23 * V_282 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
int V_60 = 0 ;
++ V_439 ;
if ( ( V_282 -> V_35 ) && ( V_431 & V_217 ) )
F_11 ( V_43 , V_282 -> V_35 , L_57 , V_36 ) ;
F_7 ( & V_16 ) ;
F_8 (sdbg_host, &sdebug_host_list, host_list) {
F_8 (devip, &sdbg_host->dev_info_list,
dev_list) {
F_70 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
F_9 ( & V_16 ) ;
F_161 () ;
if ( V_437 & V_217 )
F_11 ( V_43 , V_282 -> V_35 ,
L_60 , V_36 , V_60 ) ;
return V_432 ;
}
static void T_11 F_168 ( unsigned char * V_440 ,
unsigned long V_441 )
{
struct V_442 * V_443 ;
int V_444 [ V_445 + 2 ] ;
int V_446 , V_447 , V_60 ;
int V_448 , V_294 , V_449 ;
if ( ( V_450 < 1 ) || ( V_441 < 1048576 ) )
return;
if ( V_450 > V_445 ) {
V_450 = V_445 ;
F_21 ( L_61 , V_445 ) ;
}
V_447 = ( int ) V_6 ;
V_446 = ( V_447 - V_213 )
/ V_450 ;
V_448 = V_451 * V_213 ;
V_444 [ 0 ] = V_213 ;
for ( V_60 = 1 ; V_60 < V_450 ; ++ V_60 )
V_444 [ V_60 ] = ( ( V_60 * V_446 ) / V_448 )
* V_448 ;
V_444 [ V_450 ] = V_447 ;
V_444 [ V_450 + 1 ] = 0 ;
V_440 [ 510 ] = 0x55 ;
V_440 [ 511 ] = 0xAA ;
V_443 = (struct V_442 * ) ( V_440 + 0x1be ) ;
for ( V_60 = 0 ; V_444 [ V_60 + 1 ] ; ++ V_60 , ++ V_443 ) {
V_294 = V_444 [ V_60 ] ;
V_449 = V_444 [ V_60 + 1 ] - 1 ;
V_443 -> V_452 = 0 ;
V_443 -> V_453 = V_294 / V_448 ;
V_443 -> V_454 = ( V_294 - ( V_443 -> V_453 * V_448 ) )
/ V_213 ;
V_443 -> V_10 = ( V_294 % V_213 ) + 1 ;
V_443 -> V_455 = V_449 / V_448 ;
V_443 -> V_456 = ( V_449 - ( V_443 -> V_455 * V_448 ) )
/ V_213 ;
V_443 -> V_457 = ( V_449 % V_213 ) + 1 ;
V_443 -> V_458 = F_169 ( V_294 ) ;
V_443 -> V_459 = F_169 ( V_449 - V_294 + 1 ) ;
V_443 -> V_460 = 0x83 ;
}
}
static void F_170 ( bool V_265 )
{
int V_328 ;
struct V_376 * V_377 ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ; ++ V_328 , ++ V_377 )
F_142 ( & V_377 -> V_461 , ( int ) V_265 ) ;
}
static void F_171 ( void )
{
int V_189 , V_462 ;
V_462 = abs ( V_463 ) ;
if ( V_462 < 2 )
return;
F_170 ( true ) ;
V_189 = F_139 ( & V_464 ) ;
F_142 ( & V_464 , ( V_189 / V_462 ) * V_462 ) ;
F_170 ( false ) ;
}
static void F_172 ( void )
{
F_142 ( & V_464 , 0 ) ;
F_142 ( & V_390 , 0 ) ;
F_142 ( & V_392 , 0 ) ;
F_142 ( & V_465 , 0 ) ;
}
static void F_173 ( struct V_376 * V_377 ,
struct V_299 * V_300 )
{
if ( ( F_139 ( & V_464 ) % abs ( V_463 ) ) > 0 )
return;
V_300 -> V_321 = ! ! ( V_466 & V_217 ) ;
V_300 -> V_323 = ! ! ( V_467 & V_217 ) ;
V_300 -> V_326 = ! ! ( V_468 & V_217 ) ;
V_300 -> V_327 = ! ! ( V_469 & V_217 ) ;
V_300 -> V_310 = ! ! ( V_470 & V_217 ) ;
}
static int F_174 ( struct V_23 * V_131 , struct V_53 * V_54 ,
int V_471 , int V_472 )
{
unsigned long V_301 ;
int V_60 , V_398 , V_473 , V_474 ;
struct V_376 * V_377 ;
struct V_299 * V_300 ;
struct V_48 * V_351 ;
struct V_384 * V_385 ;
if ( F_96 ( V_54 == NULL ) ) {
if ( V_471 == 0 )
V_471 = V_475 << 16 ;
goto V_476;
}
V_351 = V_131 -> V_35 ;
if ( F_96 ( V_42 && V_471 ) )
F_11 ( V_43 , V_351 , L_62 ,
V_36 , V_471 ) ;
if ( V_472 == 0 )
goto V_476;
V_377 = F_129 ( V_131 ) ;
F_135 ( & V_377 -> V_394 , V_301 ) ;
if ( F_96 ( F_139 ( & V_377 -> V_461 ) ) ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
return V_477 ;
}
V_398 = F_139 ( & V_54 -> V_398 ) ;
V_473 = V_131 -> V_35 -> V_478 ;
V_474 = 0 ;
if ( F_96 ( ( V_473 > 0 ) && ( V_398 >= V_473 ) ) ) {
if ( V_471 ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
goto V_476;
} else
V_471 = V_479 ;
} else if ( F_96 ( V_463 &&
( V_480 & V_217 ) &&
( V_471 == 0 ) ) ) {
if ( ( V_398 == ( V_473 - 1 ) ) &&
( F_175 ( & V_465 ) >=
abs ( V_463 ) ) ) {
F_142 ( & V_465 , 0 ) ;
V_474 = 1 ;
V_471 = V_479 ;
}
}
V_60 = F_176 ( V_377 -> V_400 , V_401 ) ;
if ( F_96 ( V_60 >= V_401 ) ) {
F_136 ( & V_377 -> V_394 , V_301 ) ;
if ( V_471 )
goto V_476;
else if ( V_481 & V_217 )
V_471 = V_479 ;
if ( V_482 & V_217 )
F_11 ( V_43 , V_351 ,
L_63 ,
V_36 , V_401 ,
( V_471 ? L_64 :
L_65 ) ) ;
if ( V_471 )
goto V_476;
else
return V_477 ;
}
F_177 ( V_60 , V_377 -> V_400 ) ;
F_133 ( & V_54 -> V_398 ) ;
V_300 = & V_377 -> V_395 [ V_60 ] ;
V_300 -> V_396 = V_131 ;
V_131 -> V_309 = ( unsigned char * ) V_300 ;
V_131 -> V_483 = V_471 ;
V_385 = V_300 -> V_385 ;
F_136 ( & V_377 -> V_394 , V_301 ) ;
if ( F_96 ( V_463 && V_308 ) )
F_173 ( V_377 , V_300 ) ;
if ( V_472 > 0 || V_426 > 0 ) {
T_12 V_484 ;
if ( V_472 > 0 ) {
struct V_485 V_486 ;
F_178 ( V_472 , & V_486 ) ;
V_484 = F_179 ( V_486 . V_487 , V_486 . V_488 ) ;
} else
V_484 = F_179 ( 0 , V_426 ) ;
if ( NULL == V_385 ) {
V_385 = F_45 ( sizeof( * V_385 ) , V_137 ) ;
if ( NULL == V_385 )
return V_477 ;
V_300 -> V_385 = V_385 ;
F_180 ( & V_385 -> V_406 , V_489 ,
V_490 ) ;
V_385 -> V_406 . V_491 = F_143 ;
V_385 -> V_388 = V_377 - V_378 ;
V_385 -> V_386 = V_60 ;
}
if ( V_389 )
V_385 -> V_391 = F_134 () ;
F_181 ( & V_385 -> V_406 , V_484 , V_490 ) ;
} else {
if ( NULL == V_385 ) {
V_385 = F_45 ( sizeof( * V_300 -> V_385 ) , V_137 ) ;
if ( NULL == V_385 )
return V_477 ;
V_300 -> V_385 = V_385 ;
V_385 -> V_388 = V_377 - V_378 ;
V_385 -> V_386 = V_60 ;
F_182 ( & V_385 -> V_410 . V_409 , F_145 ) ;
}
if ( V_389 )
V_385 -> V_391 = F_134 () ;
F_183 ( & V_385 -> V_410 . V_409 ) ;
}
if ( F_96 ( ( V_482 & V_217 ) &&
( V_471 == V_479 ) ) )
F_11 ( V_43 , V_351 ,
L_66 , V_36 ,
V_398 , ( V_474 ? L_67 : L_55 ) ,
L_64 ) ;
return 0 ;
V_476:
V_131 -> V_483 = V_471 ;
V_131 -> V_402 ( V_131 ) ;
return 0 ;
}
static const char * F_184 ( struct V_14 * V_492 )
{
int V_60 ;
V_60 = F_48 ( V_493 , V_494 , L_68 ,
V_44 , V_495 , V_496 ) ;
if ( V_60 >= ( V_494 - 1 ) )
return V_493 ;
F_48 ( V_493 + V_60 , V_494 - V_60 ,
L_69 ,
V_497 , V_217 , V_383 ,
L_70 , ( int ) V_389 ) ;
return V_493 ;
}
static int F_185 ( struct V_14 * V_417 , char * V_498 ,
int V_87 )
{
char V_82 [ 16 ] ;
int V_499 ;
int V_500 = V_87 > 15 ? 15 : V_87 ;
if ( ! F_186 ( V_501 ) || ! F_186 ( V_502 ) )
return - V_503 ;
memcpy ( V_82 , V_498 , V_500 ) ;
V_82 [ V_500 ] = '\0' ;
if ( 1 != sscanf ( V_82 , L_23 , & V_499 ) )
return - V_52 ;
V_217 = V_499 ;
V_42 = ! ! ( V_504 & V_499 ) ;
V_308 = ! ! ( V_505 & V_499 ) ;
if ( V_463 != 0 )
F_171 () ;
return V_87 ;
}
static int F_187 ( struct V_506 * V_507 , struct V_14 * V_417 )
{
int V_508 , V_328 , V_509 ;
struct V_376 * V_377 ;
F_188 ( V_507 , L_71 ,
V_495 , V_496 ) ;
F_188 ( V_507 , L_72 ,
V_19 , L_73 , V_497 ,
V_217 , V_463 ) ;
F_188 ( V_507 , L_74 ,
V_425 , V_426 , V_374 ,
V_8 , L_75 ) ;
F_188 ( V_507 , L_76 ,
V_510 , V_451 , V_213 ,
V_430 ) ;
F_188 ( V_507 , L_77 ,
V_433 , V_435 , V_438 ,
V_439 ) ;
F_188 ( V_507 , L_78 ,
V_298 , V_337 , V_297 ) ;
F_188 ( V_507 , L_79 ,
V_511 / 1000 , L_70 , V_389 ,
V_379 ) ;
F_188 ( V_507 , L_80 ,
F_139 ( & V_464 ) ,
F_139 ( & V_390 ) ,
L_81 , F_139 ( & V_392 ) ,
F_139 ( & V_465 ) ) ;
F_188 ( V_507 , L_82 , V_383 ) ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ; ++ V_328 , ++ V_377 ) {
F_188 ( V_507 , L_83 , V_328 ) ;
V_508 = F_20 ( V_377 -> V_400 , V_401 ) ;
if ( V_508 != V_401 ) {
V_509 = F_141 ( V_377 -> V_400 , V_401 ) ;
F_188 ( V_507 , L_84 ,
L_85 , V_508 , V_509 ) ;
}
}
return 0 ;
}
static T_13 F_189 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_425 ) ;
}
static T_13 F_190 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_515 , V_250 ;
if ( V_189 > 0 && sscanf ( V_271 , L_23 , & V_515 ) == 1 ) {
V_250 = V_189 ;
if ( V_425 != V_515 ) {
int V_328 , V_60 ;
struct V_376 * V_377 ;
F_170 ( true ) ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ;
++ V_328 , ++ V_377 ) {
V_60 = F_20 ( V_377 -> V_400 ,
V_401 ) ;
if ( V_60 != V_401 ) {
V_250 = - V_516 ;
break;
}
}
if ( V_250 > 0 ) {
F_162 () ;
V_425 = V_515 ;
V_426 = 0 ;
}
F_170 ( false ) ;
}
return V_250 ;
}
return - V_52 ;
}
static T_13 F_191 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_426 ) ;
}
static T_13 F_192 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_517 , V_250 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_517 ) ) &&
( V_517 >= 0 ) && ( V_517 < ( 1000 * 1000 * 1000 ) ) ) {
V_250 = V_189 ;
if ( V_426 != V_517 ) {
int V_328 , V_60 ;
struct V_376 * V_377 ;
F_170 ( true ) ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ;
++ V_328 , ++ V_377 ) {
V_60 = F_20 ( V_377 -> V_400 ,
V_401 ) ;
if ( V_60 != V_401 ) {
V_250 = - V_516 ;
break;
}
}
if ( V_250 > 0 ) {
F_162 () ;
V_426 = V_517 ;
V_425 = V_517 ? V_518
: V_519 ;
}
F_170 ( false ) ;
}
return V_250 ;
}
return - V_52 ;
}
static T_13 F_193 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_87 , V_217 ) ;
}
static T_13 F_194 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_499 ;
char V_409 [ 20 ] ;
if ( 1 == sscanf ( V_271 , L_88 , V_409 ) ) {
if ( 0 == strncasecmp ( V_409 , L_89 , 2 ) ) {
if ( 1 == sscanf ( & V_409 [ 2 ] , L_90 , & V_499 ) )
goto V_520;
} else {
if ( 1 == sscanf ( V_409 , L_23 , & V_499 ) )
goto V_520;
}
}
return - V_52 ;
V_520:
V_217 = V_499 ;
V_42 = ! ! ( V_504 & V_499 ) ;
V_308 = ! ! ( V_505 & V_499 ) ;
F_171 () ;
return V_189 ;
}
static T_13 F_195 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_139 ) ;
}
static T_13 F_196 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_139 = V_96 ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_197 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_40 ) ;
}
static T_13 F_198 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_40 = V_96 ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_199 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_1 ) ;
}
static T_13 F_200 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_96 = ( V_96 > 0 ) ;
V_1 = ( V_1 > 0 ) ;
if ( V_1 != V_96 ) {
if ( ( 0 == V_96 ) && ( NULL == V_7 ) ) {
unsigned long V_521 =
( unsigned long ) V_497 *
1048576 ;
V_7 = F_201 ( V_521 ) ;
if ( NULL == V_7 ) {
F_84 ( L_91 ) ;
return - V_522 ;
}
memset ( V_7 , 0 , V_521 ) ;
}
V_1 = V_96 ;
}
return V_189 ;
}
return - V_52 ;
}
static T_13 F_202 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_143 ) ;
}
static T_13 F_203 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_143 = V_96 ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_204 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_19 ) ;
}
static T_13 F_205 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_19 = V_96 ;
F_6 () ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_206 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_497 ) ;
}
static T_13 F_207 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_450 ) ;
}
static T_13 F_208 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_463 ) ;
}
static T_13 F_209 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_523 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_523 ) ) ) {
V_463 = V_523 ;
if ( V_523 && ! V_389 ) {
F_152 ( L_92 ) ;
V_389 = true ;
}
F_171 () ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_210 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_374 ) ;
}
static T_13 F_211 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
bool V_524 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
if ( V_96 > 256 ) {
F_21 ( L_93 ) ;
return - V_52 ;
}
V_524 = ( V_374 != V_96 ) ;
V_374 = V_96 ;
F_6 () ;
if ( V_524 && ( V_79 >= 5 ) ) {
struct V_12 * V_55 ;
struct V_53 * V_56 ;
F_7 ( & V_16 ) ;
F_8 (sdhp, &sdebug_host_list,
host_list) {
F_8 (dp, &sdhp->dev_info_list,
dev_list) {
F_70 ( V_58 ,
V_56 -> V_59 ) ;
}
}
F_9 ( & V_16 ) ;
}
return V_189 ;
}
return - V_52 ;
}
static T_13 F_212 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_401 ) ;
}
static T_13 F_213 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_328 , V_96 , V_60 , V_525 ;
struct V_376 * V_377 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 > 0 ) &&
( V_96 <= V_393 ) ) {
F_170 ( true ) ;
V_60 = 0 ;
for ( V_328 = 0 , V_377 = V_378 ; V_328 < V_383 ;
++ V_328 , ++ V_377 ) {
V_525 = F_141 ( V_377 -> V_400 , V_393 ) ;
if ( V_525 > V_60 )
V_60 = V_525 ;
}
V_401 = V_96 ;
if ( V_60 == V_393 )
F_142 ( & V_399 , 0 ) ;
else if ( V_60 >= V_96 )
F_142 ( & V_399 , V_60 + 1 ) ;
else
F_142 ( & V_399 , 0 ) ;
F_170 ( false ) ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_214 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_423 ) ;
}
static T_13 F_215 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_79 ) ;
}
static T_13 F_216 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_167 ) ;
}
static T_13 F_217 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
bool V_524 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_524 = ( V_167 != V_96 ) ;
V_167 = V_96 ;
V_170 = F_52 () ;
if ( V_524 ) {
struct V_12 * V_55 ;
struct V_53 * V_56 ;
F_7 ( & V_16 ) ;
F_8 (sdhp, &sdebug_host_list,
host_list) {
F_8 (dp, &sdhp->dev_info_list,
dev_list) {
F_70 ( V_72 ,
V_56 -> V_59 ) ;
}
}
F_9 ( & V_16 ) ;
}
return V_189 ;
}
return - V_52 ;
}
static T_13 F_218 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_526 ) ;
}
static T_13 F_219 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_527 ;
if ( sscanf ( V_271 , L_23 , & V_527 ) != 1 )
return - V_52 ;
if ( V_527 > 0 ) {
do {
F_220 () ;
} while ( -- V_527 );
} else if ( V_527 < 0 ) {
do {
F_221 () ;
} while ( ++ V_527 );
}
return V_189 ;
}
static T_13 F_222 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_151 ) ;
}
static T_13 F_223 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_151 = V_96 ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_224 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , ( int ) V_389 ) ;
}
static T_13 F_225 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( sscanf ( V_271 , L_23 , & V_96 ) == 1 ) && ( V_96 >= 0 ) ) {
if ( V_96 > 0 )
V_389 = true ;
else {
F_172 () ;
V_389 = false ;
}
return V_189 ;
}
return - V_52 ;
}
static T_13 F_226 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_94 , V_8 ) ;
}
static T_13 F_227 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_383 ) ;
}
static T_13 F_228 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_317 ) ;
}
static T_13 F_229 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_152 ) ;
}
static T_13 F_230 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_94 , V_273 ) ;
}
static T_13 F_231 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_222 ) ;
}
static T_13 F_232 ( struct V_512 * V_513 , char * V_271 )
{
T_13 V_189 ;
if ( ! F_1 () )
return F_48 ( V_271 , V_514 , L_95 ,
V_6 ) ;
V_189 = F_48 ( V_271 , V_514 - 1 , L_96 ,
( int ) V_343 , V_342 ) ;
V_271 [ V_189 ++ ] = '\n' ;
V_271 [ V_189 ] = '\0' ;
return V_189 ;
}
static T_13 F_233 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , V_155 ? 1 : 0 ) ;
}
static T_13 F_234 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_155 = ( V_96 > 0 ) ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_235 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , ! ! V_528 ) ;
}
static T_13 F_236 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_528 = ( V_96 > 0 ) ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_237 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , ! ! V_529 ) ;
}
static T_13 F_238 ( struct V_512 * V_513 , const char * V_271 ,
T_9 V_189 )
{
int V_96 ;
if ( ( V_189 > 0 ) && ( 1 == sscanf ( V_271 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_529 = ( V_96 > 0 ) ;
return V_189 ;
}
return - V_52 ;
}
static T_13 F_239 ( struct V_512 * V_513 , char * V_271 )
{
return F_48 ( V_271 , V_514 , L_86 , ! ! V_110 ) ;
}
static int T_11 F_240 ( void )
{
unsigned long V_521 ;
int V_530 ;
int V_60 ;
int V_133 ;
F_142 ( & V_399 , 0 ) ;
if ( V_426 >= 1000 * 1000 * 1000 ) {
F_21 ( L_97 ) ;
V_426 = 0 ;
} else if ( V_426 > 0 )
V_425 = V_518 ;
switch ( V_8 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_84 ( L_98 , V_8 ) ;
return - V_52 ;
}
switch ( V_152 ) {
case V_531 :
break;
case V_279 :
case V_281 :
case V_153 :
V_154 = true ;
break;
default:
F_84 ( L_99 ) ;
return - V_52 ;
}
if ( V_273 > 1 ) {
F_84 ( L_100 ) ;
return - V_52 ;
}
if ( V_222 > 1 ) {
F_84 ( L_101 ) ;
return - V_52 ;
}
if ( V_122 > 15 ) {
F_84 ( L_102 , V_122 ) ;
return - V_52 ;
}
if ( V_374 > 256 ) {
F_21 ( L_103 ) ;
V_374 = V_532 ;
}
if ( V_173 > 0x3fff ) {
F_84 ( L_104 , V_173 ) ;
return - V_52 ;
}
if ( V_383 < 1 ) {
F_84 ( L_105 ) ;
return - V_52 ;
}
V_378 = F_241 ( V_383 , sizeof( struct V_376 ) ,
V_533 ) ;
if ( V_378 == NULL )
return - V_522 ;
for ( V_60 = 0 ; V_60 < V_383 ; ++ V_60 )
F_242 ( & V_378 [ V_60 ] . V_394 ) ;
if ( V_497 < 1 )
V_497 = 1 ;
V_521 = ( unsigned long ) V_497 * 1048576 ;
V_6 = V_521 / V_8 ;
V_170 = F_52 () ;
V_451 = 8 ;
V_213 = 32 ;
if ( V_497 >= 256 )
V_451 = 64 ;
else if ( V_497 >= 16 )
V_451 = 32 ;
V_510 = ( unsigned long ) V_170 /
( V_213 * V_451 ) ;
if ( V_510 >= 1024 ) {
V_451 = 255 ;
V_213 = 63 ;
V_510 = ( unsigned long ) V_170 /
( V_213 * V_451 ) ;
}
if ( V_1 == 0 ) {
V_7 = F_201 ( V_521 ) ;
if ( NULL == V_7 ) {
F_84 ( L_106 ) ;
V_133 = - V_522 ;
goto V_534;
}
memset ( V_7 , 0 , V_521 ) ;
if ( V_450 > 0 )
F_168 ( V_7 , V_521 ) ;
}
if ( V_317 ) {
int V_535 ;
V_535 = V_6 * sizeof( struct V_9 ) ;
V_11 = F_201 ( V_535 ) ;
F_84 ( L_107 , V_535 , V_11 ) ;
if ( V_11 == NULL ) {
F_84 ( L_108 ) ;
V_133 = - V_522 ;
goto V_536;
}
memset ( V_11 , 0xff , V_535 ) ;
}
if ( F_1 () ) {
V_124 =
F_243 ( V_124 , 0U , 0xffffffffU ) ;
V_125 =
F_243 ( V_125 , 0U , 256U ) ;
V_127 =
F_243 ( V_127 , 1U , 0xffffffffU ) ;
if ( V_126 &&
V_127 <=
V_126 ) {
F_84 ( L_109 ) ;
V_133 = - V_52 ;
goto V_536;
}
V_343 = F_106 ( V_6 - 1 ) + 1 ;
V_342 = F_201 ( F_244 ( V_343 ) * sizeof( long ) ) ;
F_152 ( L_110 , V_343 ) ;
if ( V_342 == NULL ) {
F_84 ( L_111 ) ;
V_133 = - V_522 ;
goto V_536;
}
F_245 ( V_342 , V_343 ) ;
if ( V_450 )
F_113 ( 0 , 2 ) ;
}
V_537 = F_246 ( L_112 ) ;
if ( F_247 ( V_537 ) ) {
F_21 ( L_113 ) ;
V_133 = F_248 ( V_537 ) ;
goto V_536;
}
V_133 = F_249 ( & V_538 ) ;
if ( V_133 < 0 ) {
F_21 ( L_114 , V_133 ) ;
goto V_539;
}
V_133 = F_250 ( & V_540 ) ;
if ( V_133 < 0 ) {
F_21 ( L_115 , V_133 ) ;
goto V_541;
}
V_530 = V_526 ;
V_526 = 0 ;
for ( V_60 = 0 ; V_60 < V_530 ; V_60 ++ ) {
if ( F_220 () ) {
F_84 ( L_116 , V_60 ) ;
break;
}
}
if ( V_42 )
F_152 ( L_117 , V_526 ) ;
return 0 ;
V_541:
F_251 ( & V_538 ) ;
V_539:
F_252 ( V_537 ) ;
V_536:
F_253 ( V_342 ) ;
F_253 ( V_11 ) ;
F_253 ( V_7 ) ;
V_534:
F_47 ( V_378 ) ;
return V_133 ;
}
static void T_14 F_254 ( void )
{
int V_60 = V_526 ;
F_161 () ;
F_162 () ;
for (; V_60 ; V_60 -- )
F_221 () ;
F_255 ( & V_540 ) ;
F_251 ( & V_538 ) ;
F_252 ( V_537 ) ;
F_253 ( V_342 ) ;
F_253 ( V_11 ) ;
F_253 ( V_7 ) ;
F_47 ( V_378 ) ;
}
static void F_256 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
V_13 = F_257 ( V_49 ) ;
F_47 ( V_13 ) ;
}
static int F_220 ( void )
{
int V_60 , V_542 ;
int error = 0 ;
struct V_12 * V_13 ;
struct V_53 * V_543 , * V_544 ;
V_13 = F_45 ( sizeof( * V_13 ) , V_533 ) ;
if ( NULL == V_13 ) {
F_84 ( L_50 , __LINE__ ) ;
return - V_522 ;
}
F_258 ( & V_13 -> V_414 ) ;
V_542 = V_19 * V_374 ;
for ( V_60 = 0 ; V_60 < V_542 ; V_60 ++ ) {
V_543 = F_146 ( V_13 , V_533 ) ;
if ( ! V_543 ) {
F_84 ( L_50 , __LINE__ ) ;
error = - V_522 ;
goto V_545;
}
}
F_7 ( & V_16 ) ;
F_148 ( & V_13 -> V_546 , & V_547 ) ;
F_9 ( & V_16 ) ;
V_13 -> V_49 . V_548 = & V_538 ;
V_13 -> V_49 . V_549 = V_537 ;
V_13 -> V_49 . V_550 = & F_256 ;
F_259 ( & V_13 -> V_49 , L_118 , V_526 ) ;
error = F_260 ( & V_13 -> V_49 ) ;
if ( error )
goto V_545;
++ V_526 ;
return error ;
V_545:
F_261 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_262 ( & V_543 -> V_413 ) ;
F_47 ( V_543 ) ;
}
F_47 ( V_13 ) ;
return error ;
}
static void F_221 ( void )
{
struct V_12 * V_13 = NULL ;
F_7 ( & V_16 ) ;
if ( ! F_263 ( & V_547 ) ) {
V_13 = F_264 ( V_547 . V_551 ,
struct V_12 , V_546 ) ;
F_262 ( & V_13 -> V_546 ) ;
}
F_9 ( & V_16 ) ;
if ( ! V_13 )
return;
F_265 ( & V_13 -> V_49 ) ;
-- V_526 ;
}
static int F_266 ( struct V_48 * V_415 , int V_473 )
{
int V_398 = 0 ;
struct V_53 * V_54 ;
F_170 ( true ) ;
V_54 = (struct V_53 * ) V_415 -> V_397 ;
if ( NULL == V_54 ) {
F_170 ( false ) ;
return - V_552 ;
}
V_398 = F_139 ( & V_54 -> V_398 ) ;
if ( V_473 < 1 )
V_473 = 1 ;
if ( V_473 > V_393 + 10 )
V_473 = V_393 + 10 ;
F_267 ( V_415 , V_473 ) ;
if ( V_482 & V_217 ) {
F_11 ( V_43 , V_415 , L_119 ,
V_36 , V_473 , V_398 ) ;
}
F_170 ( false ) ;
return V_415 -> V_478 ;
}
static bool F_268 ( struct V_23 * V_24 )
{
if ( 0 == ( F_139 ( & V_464 ) % abs ( V_463 ) ) ) {
if ( V_463 < - 1 )
V_463 = - 1 ;
if ( V_553 & V_217 )
return true ;
else if ( V_554 & V_217 &&
F_269 ( V_24 ) )
return true ;
}
return false ;
}
static int F_270 ( struct V_14 * V_17 ,
struct V_23 * V_24 )
{
T_2 V_182 ;
struct V_48 * V_351 = V_24 -> V_35 ;
const struct V_192 * V_193 ;
const struct V_192 * V_194 ;
struct V_53 * V_54 ;
T_2 * V_50 = V_24 -> V_131 ;
int (* F_271)( struct V_23 * , struct V_53 * );
int V_60 , V_191 ;
int V_188 = 0 ;
T_7 V_200 ;
T_6 V_202 ;
T_2 V_201 = V_50 [ 0 ] ;
bool V_555 ;
F_97 ( V_24 , 0 ) ;
if ( V_389 )
F_133 ( & V_464 ) ;
if ( F_96 ( V_42 &&
! ( V_556 & V_217 ) ) ) {
char V_107 [ 120 ] ;
int V_96 , V_147 , V_557 ;
V_147 = V_24 -> V_558 ;
V_557 = ( int ) sizeof( V_107 ) ;
if ( V_147 > 32 )
strcpy ( V_107 , L_120 ) ;
else {
for ( V_60 = 0 , V_96 = 0 ; V_60 < V_147 && V_96 < V_557 ; ++ V_60 )
V_96 += F_48 ( V_107 + V_96 , V_557 - V_96 , L_31 ,
( T_7 ) V_50 [ V_60 ] ) ;
}
if ( V_379 )
F_11 ( V_43 , V_351 , L_121 ,
V_44 , F_130 ( V_24 -> V_381 ) ,
V_107 ) ;
else
F_11 ( V_43 , V_351 , L_122 , V_44 ,
V_107 ) ;
}
V_555 = ( V_351 -> V_141 == V_22 ) ;
if ( F_96 ( ( V_351 -> V_141 >= V_374 ) && ! V_555 ) )
goto V_559;
V_182 = V_206 [ V_201 ] ;
V_193 = & V_197 [ V_182 ] ;
V_54 = (struct V_53 * ) V_351 -> V_397 ;
if ( F_96 ( ! V_54 ) ) {
V_54 = F_149 ( V_351 ) ;
if ( NULL == V_54 )
goto V_559;
}
V_191 = V_193 -> V_198 ;
F_271 = V_193 -> V_560 ;
if ( V_191 ) {
V_194 = V_193 ;
if ( V_203 & V_194 -> V_200 ) {
if ( V_561 & V_193 -> V_200 )
V_202 = 0x1f & V_50 [ 1 ] ;
else
V_202 = F_44 ( V_50 + 8 ) ;
for ( V_60 = 0 ; V_60 <= V_191 ; V_193 = V_194 -> V_205 + V_60 ++ ) {
if ( V_201 == V_193 -> V_201 && V_202 == V_193 -> V_202 )
break;
}
} else {
for ( V_60 = 0 ; V_60 <= V_191 ; V_193 = V_194 -> V_205 + V_60 ++ ) {
if ( V_201 == V_193 -> V_201 )
break;
}
}
if ( V_60 > V_191 ) {
if ( V_561 & V_194 -> V_200 )
F_10 ( V_24 , V_145 , 1 , 4 ) ;
else if ( V_562 & V_194 -> V_200 )
F_10 ( V_24 , V_145 , 8 , 7 ) ;
else
F_15 ( V_24 ) ;
goto V_563;
}
}
V_200 = V_193 -> V_200 ;
if ( F_96 ( V_199 & V_200 ) ) {
F_15 ( V_24 ) ;
goto V_563;
}
if ( F_96 ( V_555 && ! ( V_564 & V_200 ) ) ) {
if ( V_42 )
F_11 ( V_43 , V_351 , L_123 ,
V_44 , V_201 , L_124 ) ;
F_15 ( V_24 ) ;
goto V_563;
}
if ( F_96 ( V_529 ) ) {
T_2 V_565 ;
int V_328 ;
for ( V_60 = 1 ; V_60 < V_193 -> V_204 [ 0 ] && V_60 < 16 ; ++ V_60 ) {
V_565 = ~ V_193 -> V_204 [ V_60 ] & V_50 [ V_60 ] ;
if ( V_565 ) {
for ( V_328 = 7 ; V_328 >= 0 ; -- V_328 , V_565 <<= 1 ) {
if ( 0x80 & V_565 )
break;
}
F_10 ( V_24 , V_145 , V_60 , V_328 ) ;
goto V_563;
}
}
}
if ( F_96 ( ! ( V_566 & V_200 ) &&
F_20 ( V_54 -> V_59 ,
V_61 ) != V_61 ) ) {
V_188 = F_19 ( V_24 , V_54 ) ;
if ( V_188 )
goto V_563;
}
if ( F_96 ( ( V_567 & V_200 ) && F_139 ( & V_54 -> V_165 ) ) ) {
F_14 ( V_24 , V_568 , V_569 , 0x2 ) ;
if ( V_42 )
F_11 ( V_43 , V_351 , L_125
L_57 , V_44 , L_126
L_127 ) ;
V_188 = V_81 ;
goto V_570;
}
if ( V_1 && ( V_571 & V_200 ) )
goto V_570;
if ( F_96 ( V_463 ) ) {
if ( F_268 ( V_24 ) )
return 0 ;
}
if ( F_137 ( V_193 -> V_560 ) )
V_188 = V_193 -> V_560 ( V_24 , V_54 ) ;
else if ( F_271 )
V_188 = F_271 ( V_24 , V_54 ) ;
V_570:
return F_174 ( V_24 , V_54 , V_188 ,
( ( V_572 & V_200 ) ? 0 : V_425 ) ) ;
V_563:
return F_174 ( V_24 , V_54 , V_81 , 0 ) ;
V_559:
return F_174 ( V_24 , NULL , V_475 << 16 , 0 ) ;
}
static int F_272 ( struct V_35 * V_49 )
{
int error = 0 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_573 ;
V_13 = F_257 ( V_49 ) ;
V_574 . V_575 = V_401 ;
if ( V_576 )
V_574 . V_577 = V_578 ;
V_15 = F_273 ( & V_574 , sizeof( V_13 ) ) ;
if ( NULL == V_15 ) {
F_84 ( L_128 ) ;
error = - V_552 ;
return error ;
}
if ( V_383 > V_579 ) {
F_21 ( L_129 ,
V_44 , V_383 , V_579 ) ;
V_383 = V_579 ;
}
V_379 = F_274 ( V_15 ) && ( V_383 > 1 ) ;
if ( V_379 )
V_15 -> V_580 = V_383 ;
V_13 -> V_17 = V_15 ;
* ( (struct V_12 * * ) V_15 -> V_397 ) = V_13 ;
if ( ( V_15 -> V_18 >= 0 ) && ( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 + 1 ;
V_573 = 0 ;
switch ( V_152 ) {
case V_279 :
V_573 = V_581 ;
if ( V_317 )
V_573 |= V_582 ;
break;
case V_281 :
V_573 = V_583 ;
if ( V_317 )
V_573 |= V_584 ;
break;
case V_153 :
V_573 = V_585 ;
if ( V_317 )
V_573 |= V_586 ;
break;
default:
if ( V_317 )
V_573 |= V_587 ;
break;
}
F_275 ( V_15 , V_573 ) ;
if ( V_154 || V_317 )
F_152 ( L_130 ,
( V_573 & V_581 ) ? L_131 : L_55 ,
( V_573 & V_583 ) ? L_132 : L_55 ,
( V_573 & V_585 ) ? L_133 : L_55 ,
( V_573 & V_587 ) ? L_134 : L_55 ,
( V_573 & V_582 ) ? L_135 : L_55 ,
( V_573 & V_584 ) ? L_136 : L_55 ,
( V_573 & V_586 ) ? L_137 : L_55 ) ;
if ( V_273 == 1 )
F_276 ( V_15 , V_588 ) ;
else
F_276 ( V_15 , V_589 ) ;
V_42 = ! ! ( V_504 & V_217 ) ;
V_308 = ! ! ( V_505 & V_217 ) ;
if ( V_463 )
V_389 = true ;
error = F_277 ( V_15 , & V_13 -> V_49 ) ;
if ( error ) {
F_84 ( L_138 ) ;
error = - V_552 ;
F_278 ( V_15 ) ;
} else
F_279 ( V_15 ) ;
return error ;
}
static int F_280 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
struct V_53 * V_543 , * V_544 ;
V_13 = F_257 ( V_49 ) ;
if ( ! V_13 ) {
F_84 ( L_139 ) ;
return - V_552 ;
}
F_281 ( V_13 -> V_17 ) ;
F_261 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_262 ( & V_543 -> V_413 ) ;
F_47 ( V_543 ) ;
}
F_278 ( V_13 -> V_17 ) ;
return 0 ;
}
static int F_282 ( struct V_35 * V_49 ,
struct V_512 * V_590 )
{
return 1 ;
}
