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
if ( V_122 != 0 &&
V_123 < V_122 )
V_120 = 1 << V_122 ;
else
V_120 = 1 << V_123 ;
F_13 ( V_120 , V_82 + 2 ) ;
if ( V_6 > 0x400 )
F_40 ( V_6 , V_82 + 4 ) ;
F_40 ( V_124 , & V_82 [ 8 ] ) ;
if ( V_2 ) {
F_40 ( V_125 , & V_82 [ 16 ] ) ;
F_40 ( V_126 , & V_82 [ 20 ] ) ;
}
if ( V_127 ) {
F_40 ( V_127 , & V_82 [ 28 ] ) ;
V_82 [ 28 ] |= 0x80 ;
}
F_40 ( V_128 , & V_82 [ 24 ] ) ;
F_34 ( V_129 , & V_82 [ 32 ] ) ;
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
if ( V_130 && F_1 () )
V_82 [ 1 ] |= ( V_130 & 0x7 ) << 2 ;
return 0x4 ;
}
static int F_43 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char V_131 ;
unsigned char * V_82 ;
unsigned char * V_50 = V_24 -> V_132 ;
int V_133 , V_96 , V_134 ;
bool V_135 , V_136 ;
V_133 = F_44 ( V_50 + 3 ) ;
V_82 = F_45 ( V_137 , V_138 ) ;
if ( ! V_82 )
return V_139 << 16 ;
V_136 = ( V_140 == V_141 ) ;
V_135 = F_46 ( V_24 -> V_35 -> V_142 ) ;
if ( V_135 )
V_131 = V_143 ;
else if ( V_144 && ( V_54 -> V_142 == V_145 ) )
V_131 = 0x7f ;
else
V_131 = ( V_140 & 0x1f ) ;
V_82 [ 0 ] = V_131 ;
if ( 0x2 & V_50 [ 1 ] ) {
F_10 ( V_24 , V_146 , 1 , 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
} else if ( 0x1 & V_50 [ 1 ] ) {
int V_147 , V_99 , V_100 , V_148 ;
char V_149 [ 6 ] ;
int V_150 = V_54 -> V_13 -> V_17 -> V_150 ;
V_99 = ( ( ( V_150 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_151 & 0x7f ) ;
if ( V_152 == 0 )
V_150 = 0 ;
V_147 = V_135 ? - 1 : ( ( ( V_150 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) + V_54 -> V_142 ) ;
V_100 = ( ( V_150 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
V_148 = F_48 ( V_149 , 6 , L_23 , V_147 ) ;
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
if ( V_136 ) {
V_82 [ V_96 ++ ] = 0x89 ;
V_82 [ V_96 ++ ] = 0xb0 ;
V_82 [ V_96 ++ ] = 0xb1 ;
V_82 [ V_96 ++ ] = 0xb2 ;
}
V_82 [ 3 ] = V_96 - 4 ;
} else if ( 0x80 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = V_148 ;
memcpy ( & V_82 [ 4 ] , V_149 , V_148 ) ;
} else if ( 0x83 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_33 ( & V_82 [ 4 ] , V_99 ,
V_100 , V_147 ,
V_149 , V_148 ,
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
if ( V_153 == V_154 )
V_82 [ 4 ] = 0x4 ;
else if ( V_155 )
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
} else if ( V_136 && 0x89 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_96 = F_38 ( & V_82 [ 4 ] ) ;
F_13 ( V_96 , V_82 + 2 ) ;
} else if ( V_136 && 0xb0 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_39 ( & V_82 [ 4 ] ) ;
} else if ( V_136 && 0xb1 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_41 ( & V_82 [ 4 ] ) ;
} else if ( V_136 && 0xb2 == V_50 [ 2 ] ) {
V_82 [ 1 ] = V_50 [ 2 ] ;
V_82 [ 3 ] = F_42 ( & V_82 [ 4 ] ) ;
} else {
F_10 ( V_24 , V_146 , 2 , - 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_148 = F_30 ( F_44 ( V_82 + 2 ) + 4 , V_133 ) ;
V_134 = F_22 ( V_24 , V_82 ,
F_30 ( V_148 , V_137 ) ) ;
F_47 ( V_82 ) ;
return V_134 ;
}
V_82 [ 1 ] = V_156 ? 0x80 : 0 ;
V_82 [ 2 ] = V_79 ;
V_82 [ 3 ] = 2 ;
V_82 [ 4 ] = V_157 - 5 ;
V_82 [ 5 ] = ( int ) V_155 ;
if ( V_152 == 0 )
V_82 [ 5 ] |= 0x10 ;
V_82 [ 6 ] = 0x10 ;
V_82 [ 7 ] = 0xa ;
memcpy ( & V_82 [ 8 ] , V_108 , 8 ) ;
memcpy ( & V_82 [ 16 ] , V_109 , 16 ) ;
memcpy ( & V_82 [ 32 ] , V_158 , 4 ) ;
F_13 ( 0xc0 , V_82 + 58 ) ;
F_13 ( 0x5c0 , V_82 + 60 ) ;
V_96 = 62 ;
if ( V_136 ) {
F_13 ( 0x600 , V_82 + V_96 ) ;
V_96 += 2 ;
} else if ( V_140 == V_159 ) {
F_13 ( 0x525 , V_82 + V_96 ) ;
V_96 += 2 ;
}
F_13 ( 0x2100 , V_82 + V_96 ) ;
V_134 = F_22 ( V_24 , V_82 ,
F_30 ( V_133 , V_157 ) ) ;
F_47 ( V_82 ) ;
return V_134 ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_29 ;
unsigned char * V_50 = V_24 -> V_132 ;
unsigned char V_82 [ V_39 ] ;
bool V_160 ;
int V_148 = 18 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_160 = ! ! ( V_50 [ 1 ] & 1 ) ;
V_29 = V_24 -> V_33 ;
if ( ( V_161 [ 2 ] & 0x4 ) && ( 6 == ( V_161 [ 3 ] & 0xf ) ) ) {
if ( V_160 ) {
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = 0x0 ;
V_82 [ 2 ] = V_162 ;
V_82 [ 3 ] = 0xff ;
V_148 = 8 ;
} else {
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = 0x0 ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_162 ;
V_82 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_82 , V_29 , V_39 ) ;
if ( V_82 [ 0 ] >= 0x70 && V_160 == V_40 )
;
else if ( V_82 [ 0 ] <= 0x70 ) {
if ( V_160 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_148 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 7 ] = 0xa ;
}
} else if ( V_160 ) {
memset ( V_82 , 0 , 8 ) ;
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = V_29 [ 2 ] ;
V_82 [ 2 ] = V_29 [ 12 ] ;
V_82 [ 3 ] = V_29 [ 13 ] ;
V_148 = 8 ;
} else {
memset ( V_82 , 0 , 18 ) ;
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = V_29 [ 1 ] ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_29 [ 1 ] ;
V_82 [ 13 ] = V_29 [ 3 ] ;
}
}
F_14 ( V_24 , 0 , V_163 , 0 ) ;
return F_22 ( V_24 , V_82 , V_148 ) ;
}
static int F_50 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_132 ;
int V_164 , V_165 ;
V_164 = ( V_50 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_164 ) {
F_10 ( V_24 , V_146 , 4 , 7 ) ;
return V_81 ;
}
V_165 = ! ( V_50 [ 4 ] & 1 ) ;
F_51 ( & V_54 -> V_166 , V_165 ) ;
return 0 ;
}
static T_1 F_52 ( void )
{
static const unsigned int V_167 = 1073741824 ;
if ( V_168 > 0 )
return ( T_1 ) V_168 *
( V_167 / V_8 ) ;
else
return V_6 ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char V_82 [ V_169 ] ;
unsigned int V_170 ;
V_171 = F_52 () ;
memset ( V_82 , 0 , V_169 ) ;
if ( V_171 < 0xffffffff ) {
V_170 = ( unsigned int ) V_171 - 1 ;
F_40 ( V_170 , V_82 + 0 ) ;
} else
F_40 ( 0xffffffff , V_82 + 0 ) ;
F_13 ( V_8 , V_82 + 6 ) ;
return F_22 ( V_24 , V_82 , V_169 ) ;
}
static int F_54 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_132 ;
unsigned char V_82 [ V_172 ] ;
int V_133 ;
V_133 = F_55 ( V_50 + 10 ) ;
V_171 = F_52 () ;
memset ( V_82 , 0 , V_172 ) ;
F_34 ( ( V_173 ) ( V_171 - 1 ) , V_82 + 0 ) ;
F_40 ( V_8 , V_82 + 8 ) ;
V_82 [ 13 ] = V_123 & 0xf ;
V_82 [ 14 ] = ( V_174 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_82 [ 14 ] |= 0x80 ;
if ( V_130 & 1 )
V_82 [ 14 ] |= 0x40 ;
}
V_82 [ 15 ] = V_174 & 0xff ;
if ( V_155 ) {
V_82 [ 12 ] = ( V_153 - 1 ) << 1 ;
V_82 [ 12 ] |= 1 ;
}
return F_22 ( V_24 , V_82 ,
F_30 ( V_133 , V_172 ) ) ;
}
static int F_56 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_132 ;
unsigned char * V_82 ;
int V_150 = V_54 -> V_13 -> V_17 -> V_150 ;
int V_96 , V_134 , V_175 , V_176 ;
int V_177 , V_178 , V_106 , V_118 ;
V_175 = F_55 ( V_50 + 6 ) ;
V_82 = F_45 ( V_179 , V_138 ) ;
if ( ! V_82 )
return V_139 << 16 ;
V_106 = 0x1 ;
V_118 = 0x2 ;
V_177 = ( ( ( V_150 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_151 & 0x7f ) ;
V_178 = ( ( ( V_150 + 1 ) & 0x7f ) << 8 ) +
( V_54 -> V_151 & 0x7f ) + 0x80 ;
V_96 = 4 ;
if ( V_152 == 0 ) {
V_82 [ V_96 ++ ] = V_150 % 3 ;
V_82 [ V_96 ++ ] = 0x0F ;
} else {
V_82 [ V_96 ++ ] = 0x0 ;
V_82 [ V_96 ++ ] = 0x01 ;
}
F_13 ( V_177 , V_82 + V_96 ) ;
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
F_13 ( V_178 , V_82 + V_96 ) ;
V_96 += 2 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0x1 ;
V_82 [ V_96 ++ ] = 0 ;
V_82 [ V_96 ++ ] = 0 ;
F_13 ( V_118 , V_82 + V_96 ) ;
V_96 += 2 ;
V_176 = V_96 - 4 ;
F_40 ( V_176 , V_82 + 0 ) ;
V_176 = F_30 ( V_175 , V_96 ) ;
V_134 = F_22 ( V_24 , V_82 ,
F_30 ( V_176 , V_179 ) ) ;
F_47 ( V_82 ) ;
return V_134 ;
}
static int F_57 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_180 ;
T_2 V_181 , V_182 , V_183 , V_184 ;
T_6 V_185 , V_186 ;
T_7 V_133 , V_187 ;
int V_60 , V_188 , V_148 , V_189 , V_190 , V_191 , V_192 ;
const struct V_193 * V_194 ;
const struct V_193 * V_195 ;
T_2 * V_82 ;
T_2 * V_50 = V_24 -> V_132 ;
V_180 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_181 = V_50 [ 2 ] & 0x7 ;
V_182 = V_50 [ 3 ] ;
V_185 = F_44 ( V_50 + 4 ) ;
V_133 = F_55 ( V_50 + 6 ) ;
if ( V_133 < 4 || V_133 > 0xffff ) {
F_10 ( V_24 , V_146 , 6 , - 1 ) ;
return V_81 ;
}
if ( V_133 > 8192 )
V_187 = 8192 ;
else
V_187 = V_133 ;
V_82 = F_45 ( ( V_187 < 256 ) ? 320 : V_187 + 64 , V_138 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_196 ,
V_197 ) ;
return V_81 ;
}
switch ( V_181 ) {
case 0 :
for ( V_190 = 0 , V_194 = V_198 ;
V_194 -> V_199 != 0xff ; ++ V_194 ) {
if ( V_200 & V_194 -> V_201 )
continue;
V_190 += ( V_194 -> V_199 + 1 ) ;
}
V_191 = V_180 ? 20 : 8 ;
F_40 ( V_190 * V_191 , V_82 ) ;
for ( V_188 = 4 , V_194 = V_198 ;
V_194 -> V_199 != 0xff && V_188 < V_187 ; ++ V_194 ) {
if ( V_200 & V_194 -> V_201 )
continue;
V_192 = V_194 -> V_199 ;
V_82 [ V_188 ] = V_194 -> V_202 ;
F_13 ( V_194 -> V_203 , V_82 + V_188 + 2 ) ;
if ( V_180 )
V_82 [ V_188 + 5 ] |= 0x2 ;
if ( V_204 & V_194 -> V_201 )
V_82 [ V_188 + 5 ] |= 0x1 ;
F_13 ( V_194 -> V_205 [ 0 ] , V_82 + V_188 + 6 ) ;
if ( V_180 )
F_13 ( 0xa , V_82 + V_188 + 8 ) ;
V_195 = V_194 ;
for ( V_60 = 0 , V_194 = V_194 -> V_206 ; V_60 < V_192 ; ++ V_60 , ++ V_194 ) {
if ( V_200 & V_194 -> V_201 )
continue;
V_188 += V_191 ;
V_82 [ V_188 ] = V_194 -> V_202 ;
F_13 ( V_194 -> V_203 , V_82 + V_188 + 2 ) ;
if ( V_180 )
V_82 [ V_188 + 5 ] |= 0x2 ;
if ( V_204 & V_194 -> V_201 )
V_82 [ V_188 + 5 ] |= 0x1 ;
F_13 ( V_194 -> V_205 [ 0 ] ,
V_82 + V_188 + 6 ) ;
if ( V_180 )
F_13 ( 0xa ,
V_82 + V_188 + 8 ) ;
}
V_194 = V_195 ;
V_188 += V_191 ;
}
break;
case 1 :
case 2 :
case 3 :
V_183 = V_207 [ V_182 ] ;
V_194 = & V_198 [ V_183 ] ;
if ( V_200 & V_194 -> V_201 ) {
V_184 = 1 ;
V_188 = 4 ;
} else {
if ( 1 == V_181 ) {
if ( V_204 & V_194 -> V_201 ) {
F_10 ( V_24 , V_146 ,
2 , 2 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_185 = 0 ;
} else if ( 2 == V_181 &&
0 == ( V_204 & V_194 -> V_201 ) ) {
F_10 ( V_24 , V_146 , 4 , - 1 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
if ( 0 == ( V_204 & V_194 -> V_201 ) &&
V_182 == V_194 -> V_202 )
V_184 = 3 ;
else if ( 0 == ( V_204 & V_194 -> V_201 ) ) {
V_192 = V_194 -> V_199 ;
for ( V_60 = 0 , V_194 = V_194 -> V_206 ; V_60 < V_192 ;
++ V_60 , ++ V_194 ) {
if ( V_182 == V_194 -> V_202 )
break;
}
V_184 = ( V_60 >= V_192 ) ? 1 : 3 ;
} else if ( V_185 != V_194 -> V_203 ) {
V_192 = V_194 -> V_199 ;
for ( V_60 = 0 , V_194 = V_194 -> V_206 ; V_60 < V_192 ;
++ V_60 , ++ V_194 ) {
if ( V_185 == V_194 -> V_203 )
break;
}
V_184 = ( V_60 >= V_192 ) ? 1 : 3 ;
} else
V_184 = 3 ;
if ( 3 == V_184 ) {
V_186 = V_194 -> V_205 [ 0 ] ;
F_13 ( V_186 , V_82 + 2 ) ;
V_82 [ 4 ] = V_194 -> V_202 ;
for ( V_60 = 1 ; V_60 < V_186 ; ++ V_60 )
V_82 [ 4 + V_60 ] = ( V_60 < 16 ) ?
V_194 -> V_205 [ V_60 ] : 0xff ;
V_188 = 4 + V_186 ;
} else
V_188 = 4 ;
}
V_82 [ 1 ] = ( V_180 ? 0x80 : 0 ) | V_184 ;
if ( V_180 ) {
F_13 ( 0xa , V_82 + V_188 ) ;
V_188 += 12 ;
}
break;
default:
F_10 ( V_24 , V_146 , 2 , 2 ) ;
F_47 ( V_82 ) ;
return V_81 ;
}
V_188 = ( V_188 < V_187 ) ? V_188 : V_187 ;
V_148 = ( V_188 < V_133 ) ? V_188 : V_133 ;
V_189 = F_22 ( V_24 , V_82 , V_148 ) ;
F_47 ( V_82 ) ;
return V_189 ;
}
static int F_58 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
bool V_208 ;
T_7 V_133 , V_148 ;
T_2 V_82 [ 16 ] ;
T_2 * V_50 = V_24 -> V_132 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_208 = ! ! ( V_50 [ 2 ] & 0x80 ) ;
V_133 = F_55 ( V_50 + 6 ) ;
if ( V_133 < 4 ) {
F_10 ( V_24 , V_146 , 6 , - 1 ) ;
return V_81 ;
}
V_82 [ 0 ] = 0xc8 ;
V_82 [ 1 ] = 0x1 ;
if ( V_208 ) {
V_82 [ 3 ] = 0xc ;
V_148 = 16 ;
} else
V_148 = 4 ;
V_148 = ( V_148 < V_133 ) ? V_148 : V_133 ;
return F_22 ( V_24 , V_82 , V_148 ) ;
}
static int F_59 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_211 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_209 , V_211 , sizeof( V_211 ) ) ;
if ( 1 == V_210 )
memset ( V_209 + 2 , 0 , sizeof( V_211 ) - 2 ) ;
return sizeof( V_211 ) ;
}
static int F_60 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_212 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_209 , V_212 , sizeof( V_212 ) ) ;
if ( 1 == V_210 )
memset ( V_209 + 2 , 0 , sizeof( V_212 ) - 2 ) ;
return sizeof( V_212 ) ;
}
static int F_61 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_213 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_209 , V_213 , sizeof( V_213 ) ) ;
F_13 ( V_214 , V_209 + 10 ) ;
F_13 ( V_8 , V_209 + 12 ) ;
if ( V_156 )
V_209 [ 20 ] |= 0x20 ;
if ( 1 == V_210 )
memset ( V_209 + 2 , 0 , sizeof( V_213 ) - 2 ) ;
return sizeof( V_213 ) ;
}
static int F_62 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_215 [] = { 0x4 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned char V_216 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_217 & V_218 )
V_219 [ 2 ] &= ~ 0x4 ;
memcpy ( V_209 , V_219 , sizeof( V_219 ) ) ;
if ( 1 == V_210 )
memcpy ( V_209 + 2 , V_215 , sizeof( V_215 ) ) ;
else if ( 2 == V_210 )
memcpy ( V_209 , V_216 , sizeof( V_216 ) ) ;
return sizeof( V_219 ) ;
}
static int F_63 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_220 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_221 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_40 )
V_222 [ 2 ] |= 0x4 ;
else
V_222 [ 2 ] &= ~ 0x4 ;
if ( V_223 )
V_222 [ 5 ] |= 0x80 ;
memcpy ( V_209 , V_222 , sizeof( V_222 ) ) ;
if ( 1 == V_210 )
memcpy ( V_209 + 2 , V_220 , sizeof( V_220 ) ) ;
else if ( 2 == V_210 )
memcpy ( V_209 , V_221 , sizeof( V_221 ) ) ;
return sizeof( V_222 ) ;
}
static int F_64 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_224 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_225 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_209 , V_161 , sizeof( V_161 ) ) ;
if ( 1 == V_210 )
memcpy ( V_209 + 2 , V_224 , sizeof( V_224 ) ) ;
else if ( 2 == V_210 )
memcpy ( V_209 , V_225 , sizeof( V_225 ) ) ;
return sizeof( V_161 ) ;
}
static int F_65 ( unsigned char * V_209 , int V_210 , int V_57 )
{
unsigned char V_226 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_209 , V_226 , sizeof( V_226 ) ) ;
if ( 1 == V_210 )
memset ( V_209 + 2 , 0 , sizeof( V_226 ) - 2 ) ;
return sizeof( V_226 ) ;
}
static int F_66 ( unsigned char * V_209 , int V_210 , int V_57 ,
int V_100 )
{
unsigned char V_227 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
F_34 ( V_112 , V_227 + 16 ) ;
F_34 ( V_228 + 1 , V_227 + 24 ) ;
F_34 ( V_112 , V_227 + 64 ) ;
F_34 ( V_228 + 1 , V_227 + 72 ) ;
V_106 = V_100 + 1 ;
V_118 = V_106 + 1 ;
memcpy ( V_209 , V_227 , sizeof( V_227 ) ) ;
F_40 ( V_106 , V_209 + 20 ) ;
F_40 ( V_118 , V_209 + 48 + 20 ) ;
if ( 1 == V_210 )
memset ( V_209 + 4 , 0 , sizeof( V_227 ) - 4 ) ;
return sizeof( V_227 ) ;
}
static int F_67 ( unsigned char * V_209 , int V_210 )
{
unsigned char V_229 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_209 , V_229 , sizeof( V_229 ) ) ;
if ( 1 == V_210 )
memset ( V_209 + 4 , 0 , sizeof( V_229 ) - 4 ) ;
return sizeof( V_229 ) ;
}
static int F_68 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_210 , V_230 , V_231 , V_232 ;
unsigned char V_233 ;
int V_133 , V_188 , V_148 , V_100 ;
int V_57 = V_24 -> V_35 -> V_234 ;
unsigned char * V_235 ;
unsigned char V_82 [ V_236 ] ;
unsigned char * V_50 = V_24 -> V_132 ;
bool V_237 , V_238 , V_239 , V_136 , V_240 ;
V_237 = ! ! ( V_50 [ 1 ] & 0x8 ) ;
V_210 = ( V_50 [ 2 ] & 0xc0 ) >> 6 ;
V_230 = V_50 [ 2 ] & 0x3f ;
V_231 = V_50 [ 3 ] ;
V_239 = ( V_241 == V_50 [ 0 ] ) ;
V_238 = V_239 ? false : ! ! ( V_50 [ 1 ] & 0x10 ) ;
V_136 = ( V_140 == V_141 ) ;
if ( V_136 && ! V_237 )
V_232 = V_238 ? 16 : 8 ;
else
V_232 = 0 ;
V_133 = V_239 ? V_50 [ 4 ] : F_44 ( V_50 + 7 ) ;
memset ( V_82 , 0 , V_236 ) ;
if ( 0x3 == V_210 ) {
F_14 ( V_24 , V_41 , V_242 , 0 ) ;
return V_81 ;
}
V_100 = ( ( V_54 -> V_13 -> V_17 -> V_150 + 1 ) * 2000 ) +
( V_54 -> V_57 * 1000 ) - 3 ;
if ( V_136 )
V_233 = 0x10 ;
else
V_233 = 0x0 ;
if ( V_239 ) {
V_82 [ 2 ] = V_233 ;
V_82 [ 3 ] = V_232 ;
V_188 = 4 ;
} else {
V_82 [ 3 ] = V_233 ;
if ( 16 == V_232 )
V_82 [ 4 ] = 0x1 ;
V_82 [ 7 ] = V_232 ;
V_188 = 8 ;
}
V_235 = V_82 + V_188 ;
if ( ( V_232 > 0 ) && ( ! V_171 ) )
V_171 = F_52 () ;
if ( 8 == V_232 ) {
if ( V_171 > 0xfffffffe )
F_40 ( 0xffffffff , V_235 + 0 ) ;
else
F_40 ( V_171 , V_235 + 0 ) ;
F_13 ( V_8 , V_235 + 6 ) ;
V_188 += V_232 ;
V_235 = V_82 + V_188 ;
} else if ( 16 == V_232 ) {
F_34 ( ( V_173 ) V_171 , V_235 + 0 ) ;
F_40 ( V_8 , V_235 + 12 ) ;
V_188 += V_232 ;
V_235 = V_82 + V_188 ;
}
if ( ( V_231 > 0x0 ) && ( V_231 < 0xff ) && ( 0x19 != V_230 ) ) {
F_10 ( V_24 , V_146 , 3 , - 1 ) ;
return V_81 ;
}
V_240 = false ;
switch ( V_230 ) {
case 0x1 :
V_148 = F_59 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
break;
case 0x2 :
V_148 = F_60 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
break;
case 0x3 :
if ( V_136 ) {
V_148 = F_61 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
} else
V_240 = true ;
break;
case 0x8 :
if ( V_136 ) {
V_148 = F_62 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
} else
V_240 = true ;
break;
case 0xa :
V_148 = F_63 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
break;
case 0x19 :
if ( ( V_231 > 0x2 ) && ( V_231 < 0xff ) ) {
F_10 ( V_24 , V_146 , 3 , - 1 ) ;
return V_81 ;
}
V_148 = 0 ;
if ( ( 0x0 == V_231 ) || ( 0xff == V_231 ) )
V_148 += F_65 ( V_235 + V_148 , V_210 , V_57 ) ;
if ( ( 0x1 == V_231 ) || ( 0xff == V_231 ) )
V_148 += F_66 ( V_235 + V_148 , V_210 , V_57 ,
V_100 ) ;
if ( ( 0x2 == V_231 ) || ( 0xff == V_231 ) )
V_148 += F_67 ( V_235 + V_148 , V_210 ) ;
V_188 += V_148 ;
break;
case 0x1c :
V_148 = F_64 ( V_235 , V_210 , V_57 ) ;
V_188 += V_148 ;
break;
case 0x3f :
if ( ( 0 == V_231 ) || ( 0xff == V_231 ) ) {
V_148 = F_59 ( V_235 , V_210 , V_57 ) ;
V_148 += F_60 ( V_235 + V_148 , V_210 , V_57 ) ;
if ( V_136 ) {
V_148 += F_61 ( V_235 + V_148 , V_210 ,
V_57 ) ;
V_148 += F_62 ( V_235 + V_148 , V_210 ,
V_57 ) ;
}
V_148 += F_63 ( V_235 + V_148 , V_210 , V_57 ) ;
V_148 += F_65 ( V_235 + V_148 , V_210 , V_57 ) ;
if ( 0xff == V_231 ) {
V_148 += F_66 ( V_235 + V_148 , V_210 ,
V_57 , V_100 ) ;
V_148 += F_67 ( V_235 + V_148 , V_210 ) ;
}
V_148 += F_64 ( V_235 + V_148 , V_210 , V_57 ) ;
V_188 += V_148 ;
} else {
F_10 ( V_24 , V_146 , 3 , - 1 ) ;
return V_81 ;
}
break;
default:
V_240 = true ;
break;
}
if ( V_240 ) {
F_10 ( V_24 , V_146 , 2 , 5 ) ;
return V_81 ;
}
if ( V_239 )
V_82 [ 0 ] = V_188 - 1 ;
else
F_13 ( ( V_188 - 2 ) , V_82 + 0 ) ;
return F_22 ( V_24 , V_82 , F_30 ( V_133 , V_188 ) ) ;
}
static int F_69 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_243 , V_244 , V_245 , V_246 , V_232 , V_247 , V_248 , V_249 ;
int V_250 , V_251 , V_252 ;
unsigned char V_82 [ V_253 ] ;
unsigned char * V_50 = V_24 -> V_132 ;
int V_254 = ( V_255 == V_50 [ 0 ] ) ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_243 = V_50 [ 1 ] & 0x10 ;
V_244 = V_50 [ 1 ] & 0x1 ;
V_250 = V_254 ? V_50 [ 4 ] : F_44 ( V_50 + 7 ) ;
if ( ( 0 == V_243 ) || V_244 || ( V_250 > V_253 ) ) {
F_10 ( V_24 , V_146 , V_254 ? 4 : 7 , - 1 ) ;
return V_81 ;
}
V_251 = F_31 ( V_24 , V_82 , V_250 ) ;
if ( - 1 == V_251 )
return V_90 << 16 ;
else if ( V_42 && ( V_251 < V_250 ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_24 ,
V_36 , V_250 , V_251 ) ;
V_246 = V_254 ? ( V_82 [ 0 ] + 1 ) : ( F_44 ( V_82 + 0 ) + 2 ) ;
V_232 = V_254 ? V_82 [ 3 ] : F_44 ( V_82 + 6 ) ;
if ( V_246 > 2 ) {
F_10 ( V_24 , V_256 , 0 , - 1 ) ;
return V_81 ;
}
V_247 = V_232 + ( V_254 ? 4 : 8 ) ;
V_252 = V_82 [ V_247 ] & 0x3f ;
V_245 = ! ! ( V_82 [ V_247 ] & 0x80 ) ;
if ( V_245 ) {
F_10 ( V_24 , V_256 , V_247 , 7 ) ;
return V_81 ;
}
V_248 = ! ! ( V_82 [ V_247 ] & 0x40 ) ;
V_249 = V_248 ? ( F_44 ( V_82 + V_247 + 2 ) + 4 ) :
( V_82 [ V_247 + 1 ] + 2 ) ;
if ( ( V_249 + V_247 ) > V_250 ) {
F_14 ( V_24 , V_41 ,
V_257 , 0 ) ;
return V_81 ;
}
switch ( V_252 ) {
case 0x8 :
if ( V_219 [ 1 ] == V_82 [ V_247 + 1 ] ) {
memcpy ( V_219 + 2 , V_82 + V_247 + 2 ,
sizeof( V_219 ) - 2 ) ;
goto V_258;
}
break;
case 0xa :
if ( V_222 [ 1 ] == V_82 [ V_247 + 1 ] ) {
memcpy ( V_222 + 2 , V_82 + V_247 + 2 ,
sizeof( V_222 ) - 2 ) ;
V_40 = ! ! ( V_222 [ 2 ] & 0x4 ) ;
goto V_258;
}
break;
case 0x1c :
if ( V_161 [ 1 ] == V_82 [ V_247 + 1 ] ) {
memcpy ( V_161 + 2 , V_82 + V_247 + 2 ,
sizeof( V_161 ) - 2 ) ;
goto V_258;
}
break;
default:
break;
}
F_10 ( V_24 , V_256 , V_247 , 5 ) ;
return V_81 ;
V_258:
F_70 ( V_69 , V_54 -> V_59 ) ;
return 0 ;
}
static int F_71 ( unsigned char * V_82 )
{
unsigned char V_259 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_82 , V_259 , sizeof( V_259 ) ) ;
return sizeof( V_259 ) ;
}
static int F_72 ( unsigned char * V_82 )
{
unsigned char V_260 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_82 , V_260 , sizeof( V_260 ) ) ;
if ( V_161 [ 2 ] & 0x4 ) {
V_82 [ 4 ] = V_162 ;
V_82 [ 5 ] = 0xff ;
}
return sizeof( V_260 ) ;
}
static int F_73 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_261 , V_244 , V_230 , V_231 , V_133 , V_148 , V_96 ;
unsigned char V_82 [ V_262 ] ;
unsigned char * V_50 = V_24 -> V_132 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_261 = V_50 [ 1 ] & 0x2 ;
V_244 = V_50 [ 1 ] & 0x1 ;
if ( V_261 || V_244 ) {
F_10 ( V_24 , V_146 , 1 , V_261 ? 1 : 0 ) ;
return V_81 ;
}
V_230 = V_50 [ 2 ] & 0x3f ;
V_231 = V_50 [ 3 ] & 0xff ;
V_133 = F_44 ( V_50 + 7 ) ;
V_82 [ 0 ] = V_230 ;
if ( 0 == V_231 ) {
switch ( V_230 ) {
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
F_10 ( V_24 , V_146 , 2 , 5 ) ;
return V_81 ;
}
} else if ( 0xff == V_231 ) {
V_82 [ 0 ] |= 0x40 ;
V_82 [ 1 ] = V_231 ;
switch ( V_230 ) {
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
F_10 ( V_24 , V_146 , 2 , 5 ) ;
return V_81 ;
}
} else {
F_10 ( V_24 , V_146 , 3 , - 1 ) ;
return V_81 ;
}
V_148 = F_30 ( F_44 ( V_82 + 2 ) + 4 , V_133 ) ;
return F_22 ( V_24 , V_82 ,
F_30 ( V_148 , V_137 ) ) ;
}
static int F_74 ( struct V_23 * V_24 ,
unsigned long long V_5 , unsigned int V_105 )
{
if ( V_5 + V_105 > V_171 ) {
F_14 ( V_24 , V_41 , V_263 , 0 ) ;
return V_81 ;
}
if ( V_105 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
return 0 ;
}
static int F_75 ( struct V_23 * V_264 , V_173 V_5 , T_7 V_105 ,
bool V_265 )
{
int V_134 ;
V_173 V_266 , V_267 = 0 ;
struct V_85 * V_86 ;
enum V_268 V_269 ;
if ( V_265 ) {
V_86 = F_76 ( V_264 ) ;
V_269 = V_98 ;
} else {
V_86 = F_23 ( V_264 ) ;
V_269 = V_89 ;
}
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_24 ( V_264 ) || V_264 -> V_88 == V_269 ) )
return - 1 ;
V_266 = F_3 ( V_5 , V_6 ) ;
if ( V_266 + V_105 > V_6 )
V_267 = V_266 + V_105 - V_6 ;
V_134 = F_77 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 + ( V_266 * V_8 ) ,
( V_105 - V_267 ) * V_8 , 0 , V_265 ) ;
if ( V_134 != ( V_105 - V_267 ) * V_8 )
return V_134 ;
if ( V_267 ) {
V_134 += F_77 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 , V_267 * V_8 ,
( V_105 - V_267 ) * V_8 , V_265 ) ;
}
return V_134 ;
}
static bool F_78 ( V_173 V_5 , T_7 V_105 , const T_2 * V_82 )
{
bool V_251 ;
V_173 V_266 , V_267 = 0 ;
T_7 V_270 = V_6 ;
T_7 V_271 = V_8 ;
V_266 = F_3 ( V_5 , V_270 ) ;
if ( V_266 + V_105 > V_270 )
V_267 = V_266 + V_105 - V_270 ;
V_251 = ! memcmp ( V_7 + ( V_266 * V_271 ) , V_82 ,
( V_105 - V_267 ) * V_271 ) ;
if ( ! V_251 )
return V_251 ;
if ( V_267 )
V_251 = memcmp ( V_7 , V_82 + ( ( V_105 - V_267 ) * V_271 ) ,
V_267 * V_271 ) ;
if ( ! V_251 )
return V_251 ;
V_82 += V_105 * V_271 ;
memcpy ( V_7 + ( V_266 * V_271 ) , V_82 , ( V_105 - V_267 ) * V_271 ) ;
if ( V_267 )
memcpy ( V_7 , V_82 + ( ( V_105 - V_267 ) * V_271 ) ,
V_267 * V_271 ) ;
return V_251 ;
}
static T_8 F_79 ( const void * V_272 , int V_148 )
{
T_8 V_273 ;
if ( V_274 )
V_273 = ( V_275 T_8 ) F_80 ( V_272 , V_148 ) ;
else
V_273 = F_81 ( F_82 ( V_272 , V_148 ) ) ;
return V_273 ;
}
static int F_83 ( struct V_9 * V_276 , const void * V_277 ,
T_1 V_10 , T_7 V_278 )
{
T_8 V_273 = F_79 ( V_277 , V_8 ) ;
if ( V_276 -> V_279 != V_273 ) {
F_84 ( L_25 ,
( unsigned long ) V_10 ,
F_85 ( V_276 -> V_279 ) ,
F_85 ( V_273 ) ) ;
return 0x01 ;
}
if ( V_153 == V_280 &&
F_86 ( V_276 -> V_281 ) != ( V_10 & 0xffffffff ) ) {
F_84 ( L_26 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
if ( V_153 == V_282 &&
F_86 ( V_276 -> V_281 ) != V_278 ) {
F_84 ( L_26 ,
( unsigned long ) V_10 ) ;
return 0x03 ;
}
return 0 ;
}
static void F_87 ( struct V_23 * V_283 , T_1 V_10 ,
unsigned int V_284 , bool V_285 )
{
T_9 V_94 ;
void * V_286 ;
const void * V_287 = V_11 + V_6 ;
struct V_288 V_289 ;
V_94 = V_284 * sizeof( * V_11 ) ;
F_88 ( & V_289 , F_89 ( V_283 ) ,
F_90 ( V_283 ) , V_290 |
( V_285 ? V_291 : V_292 ) ) ;
while ( F_91 ( & V_289 ) && V_94 > 0 ) {
T_9 V_148 = F_30 ( V_289 . V_87 , V_94 ) ;
void * V_293 = F_4 ( V_10 ) ;
T_9 V_267 = 0 ;
if ( V_287 < V_293 + V_148 )
V_267 = V_293 + V_148 - V_287 ;
V_286 = V_289 . V_294 ;
if ( V_285 )
memcpy ( V_286 , V_293 , V_148 - V_267 ) ;
else
memcpy ( V_293 , V_286 , V_148 - V_267 ) ;
if ( V_267 ) {
if ( V_285 )
memcpy ( V_286 + V_148 - V_267 , V_11 , V_267 ) ;
else
memcpy ( V_11 , V_286 + V_148 - V_267 , V_267 ) ;
}
V_10 += V_148 / sizeof( * V_11 ) ;
V_94 -= V_148 ;
}
F_92 ( & V_289 ) ;
}
static int F_93 ( struct V_23 * V_283 , T_1 V_295 ,
unsigned int V_284 , T_7 V_278 )
{
unsigned int V_296 ;
struct V_9 * V_276 ;
T_1 V_10 ;
for ( V_296 = 0 ; V_296 < V_284 ; V_296 ++ , V_278 ++ ) {
int V_134 ;
V_10 = V_295 + V_296 ;
V_276 = F_4 ( V_10 ) ;
if ( V_276 -> V_297 == F_81 ( 0xffff ) )
continue;
V_134 = F_83 ( V_276 , F_2 ( V_10 ) , V_10 , V_278 ) ;
if ( V_134 ) {
V_298 ++ ;
return V_134 ;
}
}
F_87 ( V_283 , V_295 , V_284 , true ) ;
V_299 ++ ;
return 0 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
struct V_300 * V_301 ;
V_173 V_5 ;
T_7 V_105 ;
T_7 V_278 ;
unsigned long V_302 ;
int V_134 ;
bool V_303 ;
switch ( V_50 [ 0 ] ) {
case V_304 :
V_278 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
V_303 = true ;
break;
case V_305 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_303 = true ;
break;
case V_306 :
V_278 = 0 ;
V_5 = ( T_7 ) V_50 [ 3 ] | ( T_7 ) V_50 [ 2 ] << 8 |
( T_7 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_105 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_303 = true ;
break;
case V_307 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 6 ) ;
V_303 = true ;
break;
case V_308 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_303 = false ;
break;
default:
V_5 = F_95 ( V_50 + 12 ) ;
V_278 = F_55 ( V_50 + 20 ) ;
V_105 = F_55 ( V_50 + 28 ) ;
V_303 = false ;
break;
}
if ( F_96 ( V_155 && V_303 ) ) {
if ( V_153 == V_282 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_153 == V_280 ||
V_153 == V_154 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_27
L_28 ) ;
}
if ( F_96 ( V_309 ) ) {
V_301 = (struct V_300 * ) V_24 -> V_310 ;
if ( V_301 ) {
if ( V_301 -> V_311 )
V_105 /= 2 ;
}
} else
V_301 = NULL ;
if ( F_96 ( V_5 + V_105 > V_171 ) ) {
F_14 ( V_24 , V_41 , V_263 , 0 ) ;
return V_81 ;
}
if ( F_96 ( V_105 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
if ( F_96 ( ( V_312 & V_218 ) &&
( V_5 <= ( V_313 + V_314 - 1 ) ) &&
( ( V_5 + V_105 ) > V_313 ) ) ) {
F_14 ( V_24 , V_315 , V_316 , 0 ) ;
if ( 0x70 == ( V_24 -> V_33 [ 0 ] & 0x7f ) ) {
V_24 -> V_33 [ 0 ] |= 0x80 ;
V_134 = ( V_5 < V_313 )
? V_313 : ( int ) V_5 ;
F_40 ( V_134 , V_24 -> V_33 + 3 ) ;
}
F_97 ( V_24 , F_26 ( V_24 ) ) ;
return V_81 ;
}
F_98 ( & V_317 , V_302 ) ;
if ( F_96 ( V_318 && F_90 ( V_24 ) ) ) {
int V_319 = F_93 ( V_24 , V_5 , V_105 , V_278 ) ;
if ( V_319 ) {
F_99 ( & V_317 , V_302 ) ;
F_14 ( V_24 , V_320 , 0x10 , V_319 ) ;
return V_321 ;
}
}
V_134 = F_75 ( V_24 , V_5 , V_105 , false ) ;
F_99 ( & V_317 , V_302 ) ;
if ( F_96 ( V_134 == - 1 ) )
return V_90 << 16 ;
F_23 ( V_24 ) -> V_94 = F_26 ( V_24 ) - V_134 ;
if ( F_96 ( V_301 ) ) {
if ( V_301 -> V_322 ) {
F_14 ( V_24 , V_323 ,
V_162 , 0 ) ;
return V_81 ;
} else if ( V_301 -> V_324 ) {
F_14 ( V_24 , V_320 ,
V_325 , V_326 ) ;
return V_81 ;
} else if ( V_301 -> V_327 ) {
F_14 ( V_24 , V_320 , 0x10 , 1 ) ;
return V_321 ;
} else if ( V_301 -> V_328 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_321 ;
}
}
return 0 ;
}
static void F_100 ( unsigned char * V_272 , int V_148 )
{
int V_296 , V_329 , V_96 ;
F_84 ( L_29 ) ;
for ( V_296 = 0 ; V_296 < V_148 ; V_296 += 16 ) {
char V_107 [ 128 ] ;
for ( V_329 = 0 , V_96 = 0 ; V_329 < 16 ; V_329 ++ ) {
unsigned char V_330 = V_272 [ V_296 + V_329 ] ;
if ( V_330 >= 0x20 && V_330 < 0x7e )
V_96 += F_48 ( V_107 + V_96 , sizeof( V_107 ) - V_96 ,
L_30 , V_272 [ V_296 + V_329 ] ) ;
else
V_96 += F_48 ( V_107 + V_96 , sizeof( V_107 ) - V_96 ,
L_31 , V_272 [ V_296 + V_329 ] ) ;
}
F_84 ( L_32 , V_296 , V_107 ) ;
}
}
static int F_101 ( struct V_23 * V_283 , T_1 V_295 ,
unsigned int V_284 , T_7 V_278 )
{
int V_134 ;
struct V_9 * V_276 ;
void * V_331 ;
T_1 V_10 = V_295 ;
int V_332 ;
int V_333 ;
struct V_288 V_334 ;
struct V_288 V_335 ;
F_102 ( F_103 ( V_283 ) == 0 ) ;
F_102 ( F_90 ( V_283 ) == 0 ) ;
F_88 ( & V_335 , F_89 ( V_283 ) ,
F_90 ( V_283 ) ,
V_290 | V_292 ) ;
F_88 ( & V_334 , F_104 ( V_283 ) , F_103 ( V_283 ) ,
V_290 | V_292 ) ;
while ( F_91 ( & V_335 ) ) {
V_333 = 0 ;
if ( F_105 ( ! F_91 ( & V_334 ) ) ) {
V_134 = 0x01 ;
goto V_336;
}
for ( V_332 = 0 ; V_332 < V_335 . V_87 ;
V_332 += sizeof( struct V_9 ) ) {
if ( V_333 >= V_334 . V_87 ) {
if ( F_105 ( ! F_91 ( & V_334 ) ) ) {
V_134 = 0x01 ;
goto V_336;
}
V_333 = 0 ;
}
V_276 = V_335 . V_294 + V_332 ;
V_331 = V_334 . V_294 + V_333 ;
V_134 = F_83 ( V_276 , V_331 , V_10 , V_278 ) ;
if ( V_134 ) {
F_100 ( V_331 , V_8 ) ;
goto V_336;
}
V_10 ++ ;
V_278 ++ ;
V_333 += V_8 ;
}
V_334 . V_337 = V_333 ;
F_92 ( & V_334 ) ;
}
F_92 ( & V_335 ) ;
F_87 ( V_283 , V_295 , V_284 , false ) ;
V_338 ++ ;
return 0 ;
V_336:
V_298 ++ ;
F_92 ( & V_334 ) ;
F_92 ( & V_335 ) ;
return V_134 ;
}
static unsigned long F_106 ( T_1 V_5 )
{
if ( V_127 )
V_5 += V_128 - V_127 ;
F_5 ( V_5 , V_128 ) ;
return V_5 ;
}
static T_1 F_107 ( unsigned long V_339 )
{
T_1 V_5 = V_339 * V_128 ;
if ( V_127 )
V_5 -= V_128 - V_127 ;
return V_5 ;
}
static unsigned int F_108 ( T_1 V_5 , unsigned int * V_105 )
{
T_1 V_340 ;
unsigned int V_341 ;
unsigned long V_339 ;
unsigned long V_342 ;
V_339 = F_106 ( V_5 ) ;
V_341 = F_109 ( V_339 , V_343 ) ;
if ( V_341 )
V_342 = F_110 ( V_343 , V_344 , V_339 ) ;
else
V_342 = F_111 ( V_343 , V_344 , V_339 ) ;
V_340 = F_112 ( T_1 , V_6 , F_107 ( V_342 ) ) ;
* V_105 = V_340 - V_5 ;
return V_341 ;
}
static void F_113 ( T_1 V_5 , unsigned int V_148 )
{
T_1 V_340 = V_5 + V_148 ;
while ( V_5 < V_340 ) {
unsigned long V_339 = F_106 ( V_5 ) ;
if ( V_339 < V_344 )
F_70 ( V_339 , V_343 ) ;
V_5 = F_107 ( V_339 + 1 ) ;
}
}
static void F_114 ( T_1 V_5 , unsigned int V_148 )
{
T_1 V_340 = V_5 + V_148 ;
while ( V_5 < V_340 ) {
unsigned long V_339 = F_106 ( V_5 ) ;
if ( V_5 == F_107 ( V_339 ) &&
V_5 + V_128 <= V_340 &&
V_339 < V_344 ) {
F_18 ( V_339 , V_343 ) ;
if ( V_130 ) {
memset ( V_7 +
V_5 * V_8 ,
( V_130 & 1 ) ? 0 : 0xff ,
V_8 *
V_128 ) ;
}
if ( V_11 ) {
memset ( V_11 + V_5 , 0xff ,
sizeof( * V_11 ) *
V_128 ) ;
}
}
V_5 = F_107 ( V_339 + 1 ) ;
}
}
static int F_115 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
V_173 V_5 ;
T_7 V_105 ;
T_7 V_278 ;
unsigned long V_302 ;
int V_134 ;
bool V_303 ;
switch ( V_50 [ 0 ] ) {
case V_345 :
V_278 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
V_303 = true ;
break;
case V_346 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_303 = true ;
break;
case V_347 :
V_278 = 0 ;
V_5 = ( T_7 ) V_50 [ 3 ] | ( T_7 ) V_50 [ 2 ] << 8 |
( T_7 ) ( V_50 [ 1 ] & 0x1f ) << 16 ;
V_105 = ( 0 == V_50 [ 4 ] ) ? 256 : V_50 [ 4 ] ;
V_303 = true ;
break;
case V_348 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 6 ) ;
V_303 = true ;
break;
case 0x53 :
V_278 = 0 ;
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
V_303 = false ;
break;
default:
V_5 = F_95 ( V_50 + 12 ) ;
V_278 = F_55 ( V_50 + 20 ) ;
V_105 = F_55 ( V_50 + 28 ) ;
V_303 = false ;
break;
}
if ( F_96 ( V_155 && V_303 ) ) {
if ( V_153 == V_282 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_153 == V_280 ||
V_153 == V_154 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_33
L_28 ) ;
}
if ( F_96 ( V_5 + V_105 > V_171 ) ) {
F_14 ( V_24 , V_41 , V_263 , 0 ) ;
return V_81 ;
}
if ( F_96 ( V_105 > V_6 ) ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
F_116 ( & V_317 , V_302 ) ;
if ( F_96 ( V_318 && F_90 ( V_24 ) ) ) {
int V_319 = F_101 ( V_24 , V_5 , V_105 , V_278 ) ;
if ( V_319 ) {
F_117 ( & V_317 , V_302 ) ;
F_14 ( V_24 , V_41 , 0x10 , V_319 ) ;
return V_321 ;
}
}
V_134 = F_75 ( V_24 , V_5 , V_105 , true ) ;
if ( F_96 ( F_1 () ) )
F_113 ( V_5 , V_105 ) ;
F_117 ( & V_317 , V_302 ) ;
if ( F_96 ( - 1 == V_134 ) )
return V_90 << 16 ;
else if ( F_96 ( V_42 &&
( V_134 < ( V_105 * V_8 ) ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_34 ,
V_44 , V_105 * V_8 , V_134 ) ;
if ( F_96 ( V_309 ) ) {
struct V_300 * V_301 =
(struct V_300 * ) V_24 -> V_310 ;
if ( V_301 ) {
if ( V_301 -> V_322 ) {
F_14 ( V_24 , V_323 ,
V_162 , 0 ) ;
return V_81 ;
} else if ( V_301 -> V_327 ) {
F_14 ( V_24 , V_320 , 0x10 , 1 ) ;
return V_321 ;
} else if ( V_301 -> V_328 ) {
F_14 ( V_24 , V_41 , 0x10 , 1 ) ;
return V_321 ;
}
}
}
return 0 ;
}
static int F_118 ( struct V_23 * V_24 , V_173 V_5 , T_7 V_105 ,
T_7 V_278 , bool V_349 , bool V_350 )
{
unsigned long V_302 ;
unsigned long long V_296 ;
int V_134 ;
V_173 V_351 ;
V_134 = F_74 ( V_24 , V_5 , V_105 ) ;
if ( V_134 )
return V_134 ;
F_116 ( & V_317 , V_302 ) ;
if ( V_349 && F_1 () ) {
F_114 ( V_5 , V_105 ) ;
goto V_336;
}
V_351 = V_5 * V_8 ;
if ( V_350 ) {
memset ( V_7 + V_351 , 0 , V_8 ) ;
V_134 = 0 ;
} else
V_134 = F_31 ( V_24 , V_7 + V_351 ,
V_8 ) ;
if ( - 1 == V_134 ) {
F_117 ( & V_317 , V_302 ) ;
return V_90 << 16 ;
} else if ( V_42 && ( V_134 < ( V_105 * V_8 ) ) )
F_11 ( V_43 , V_24 -> V_35 ,
L_35 ,
V_44 , L_36 ,
V_105 * V_8 , V_134 ) ;
for ( V_296 = 1 ; V_296 < V_105 ; V_296 ++ )
memcpy ( V_7 + ( ( V_5 + V_296 ) * V_8 ) ,
V_7 + V_351 ,
V_8 ) ;
if ( F_1 () )
F_113 ( V_5 , V_105 ) ;
V_336:
F_117 ( & V_317 , V_302 ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
T_7 V_5 ;
T_6 V_105 ;
T_7 V_278 = 0 ;
bool V_349 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_4 == 0 ) {
F_10 ( V_24 , V_146 , 1 , 3 ) ;
return V_81 ;
} else
V_349 = true ;
}
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
if ( V_105 > V_129 ) {
F_10 ( V_24 , V_146 , 7 , - 1 ) ;
return V_81 ;
}
return F_118 ( V_24 , V_5 , V_105 , V_278 , V_349 , false ) ;
}
static int F_120 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
V_173 V_5 ;
T_7 V_105 ;
T_7 V_278 = 0 ;
bool V_349 = false ;
bool V_350 = false ;
if ( V_50 [ 1 ] & 0x8 ) {
if ( V_3 == 0 ) {
F_10 ( V_24 , V_146 , 1 , 3 ) ;
return V_81 ;
} else
V_349 = true ;
}
if ( V_50 [ 1 ] & 0x1 )
V_350 = true ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = F_55 ( V_50 + 10 ) ;
if ( V_105 > V_129 ) {
F_10 ( V_24 , V_146 , 10 , - 1 ) ;
return V_81 ;
}
return F_118 ( V_24 , V_5 , V_105 , V_278 , V_349 , V_350 ) ;
}
static int F_121 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
struct V_48 * V_352 = V_24 -> V_35 ;
struct V_53 * V_56 ;
T_2 V_353 ;
V_353 = V_50 [ 1 ] & 0x1f ;
switch ( V_353 ) {
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
if ( V_56 -> V_57 == V_352 -> V_234 ) {
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
if ( V_56 -> V_57 == V_352 -> V_234 )
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
T_2 * V_50 = V_24 -> V_132 ;
T_2 * V_82 ;
T_2 * V_354 ;
V_173 V_5 ;
T_7 V_355 ;
T_7 V_271 = V_8 ;
T_2 V_105 ;
unsigned long V_302 ;
int V_134 ;
int V_356 = 0 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_105 = V_50 [ 13 ] ;
if ( 0 == V_105 )
return 0 ;
if ( V_153 == V_282 &&
( V_50 [ 1 ] & 0xe0 ) ) {
F_15 ( V_24 ) ;
return V_81 ;
}
if ( ( V_153 == V_280 ||
V_153 == V_154 ) &&
( V_50 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_34 , V_24 -> V_35 , L_33
L_28 ) ;
if ( V_5 + V_105 > V_171 ) {
F_14 ( V_24 , V_41 , V_263 , 0 ) ;
return V_81 ;
}
if ( V_105 > V_6 ) {
F_14 ( V_24 , V_41 , V_37 , 0 ) ;
return V_81 ;
}
V_355 = 2 * V_105 ;
V_82 = F_45 ( V_355 * V_271 , V_138 ) ;
if ( NULL == V_82 ) {
F_14 ( V_24 , V_41 , V_196 ,
V_197 ) ;
return V_81 ;
}
F_116 ( & V_317 , V_302 ) ;
V_354 = V_7 ;
V_7 = V_82 ;
V_134 = F_75 ( V_24 , 0 , V_355 , true ) ;
V_7 = V_354 ;
if ( V_134 == - 1 ) {
V_356 = V_90 << 16 ;
goto V_357;
} else if ( V_42 && ( V_134 < ( V_355 * V_271 ) ) )
F_11 ( V_43 , V_24 -> V_35 , L_37
L_38 , V_44 ,
V_355 * V_271 , V_134 ) ;
if ( ! F_78 ( V_5 , V_105 , V_82 ) ) {
F_14 ( V_24 , V_358 , V_359 , 0 ) ;
V_356 = V_81 ;
goto V_357;
}
if ( F_1 () )
F_113 ( V_5 , V_105 ) ;
V_357:
F_117 ( & V_317 , V_302 ) ;
F_47 ( V_82 ) ;
return V_356 ;
}
static int F_123 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
unsigned char * V_272 ;
struct V_360 * V_361 ;
unsigned int V_296 , V_362 , V_363 ;
int V_134 ;
unsigned long V_302 ;
if ( ! F_1 () )
return 0 ;
V_362 = F_44 ( V_24 -> V_132 + 7 ) ;
F_102 ( F_26 ( V_24 ) != V_362 ) ;
V_363 = ( V_362 - 8 ) / 16 ;
if ( V_363 > V_126 ) {
F_10 ( V_24 , V_146 , 7 , - 1 ) ;
return V_81 ;
}
V_272 = F_45 ( F_26 ( V_24 ) , V_138 ) ;
if ( ! V_272 ) {
F_14 ( V_24 , V_41 , V_196 ,
V_197 ) ;
return V_81 ;
}
F_32 ( V_24 , V_272 , F_26 ( V_24 ) ) ;
F_102 ( F_44 ( & V_272 [ 0 ] ) != V_362 - 2 ) ;
F_102 ( F_44 ( & V_272 [ 2 ] ) != V_363 * 16 ) ;
V_361 = ( void * ) & V_272 [ 8 ] ;
F_116 ( & V_317 , V_302 ) ;
for ( V_296 = 0 ; V_296 < V_363 ; V_296 ++ ) {
unsigned long long V_5 = F_95 ( & V_361 [ V_296 ] . V_5 ) ;
unsigned int V_105 = F_55 ( & V_361 [ V_296 ] . V_364 ) ;
V_134 = F_74 ( V_24 , V_5 , V_105 ) ;
if ( V_134 )
goto V_336;
F_114 ( V_5 , V_105 ) ;
}
V_134 = 0 ;
V_336:
F_117 ( & V_317 , V_302 ) ;
F_47 ( V_272 ) ;
return V_134 ;
}
static int F_124 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
V_173 V_5 ;
T_7 V_133 , V_341 , V_105 ;
T_2 V_82 [ V_365 ] ;
int V_134 ;
V_5 = F_95 ( V_50 + 2 ) ;
V_133 = F_55 ( V_50 + 10 ) ;
if ( V_133 < 24 )
return 0 ;
V_134 = F_74 ( V_24 , V_5 , 1 ) ;
if ( V_134 )
return V_134 ;
if ( F_1 () )
V_341 = F_108 ( V_5 , & V_105 ) ;
else {
V_341 = 1 ;
V_171 = F_52 () ;
if ( V_171 - V_5 <= 0xffffffff )
V_105 = V_171 - V_5 ;
else
V_105 = 0xffffffff ;
}
memset ( V_82 , 0 , V_365 ) ;
F_40 ( 20 , V_82 ) ;
F_34 ( V_5 , V_82 + 8 ) ;
F_40 ( V_105 , V_82 + 16 ) ;
V_82 [ 20 ] = ! V_341 ;
return F_22 ( V_24 , V_82 , V_365 ) ;
}
static int F_125 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
unsigned char * V_50 = V_24 -> V_132 ;
unsigned int V_133 ;
unsigned char V_366 ;
V_173 V_142 ;
struct V_367 * V_368 ;
T_2 V_82 [ V_369 * sizeof( struct V_367 ) ] ;
unsigned int V_370 ;
unsigned int V_371 ;
unsigned int V_372 ;
unsigned int V_176 ;
int V_60 , V_329 , V_96 , V_251 ;
unsigned int V_373 = 0 ;
const int V_374 = sizeof( struct V_367 ) ;
F_17 ( V_54 ) ;
V_366 = V_50 [ 2 ] ;
V_133 = F_55 ( V_50 + 6 ) ;
if ( V_133 < 4 ) {
F_84 ( L_39 , V_133 ) ;
F_10 ( V_24 , V_146 , 6 , - 1 ) ;
return V_81 ;
}
switch ( V_366 ) {
case 0 :
V_370 = V_375 ;
V_371 = 0 ;
break;
case 1 :
V_370 = 0 ;
V_371 = 1 ;
break;
case 2 :
V_370 = V_375 ;
V_371 = 1 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
default:
F_29 ( L_40 , V_366 ) ;
F_10 ( V_24 , V_146 , 2 , - 1 ) ;
return V_81 ;
}
if ( V_144 && ( V_370 > 0 ) )
-- V_370 ;
V_372 = V_370 + V_371 ;
V_176 = V_372 * V_374 ;
F_97 ( V_24 , F_26 ( V_24 ) ) ;
F_29 ( L_41 ,
V_366 , V_370 , V_371 , V_144 ) ;
V_142 = V_144 ? 1 : 0 ;
for ( V_60 = 0 , V_329 = 0 , V_251 = 0 ; true ; ++ V_60 , V_329 = 0 ) {
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_368 = (struct V_367 * ) & V_82 [ 0 ] ;
if ( V_60 == 0 ) {
F_40 ( V_176 , & V_82 [ 0 ] ) ;
++ V_368 ;
V_329 = 1 ;
}
for ( ; V_329 < V_369 ; ++ V_329 , ++ V_368 ) {
if ( ( V_60 * V_369 ) + V_329 > V_370 )
break;
F_126 ( V_142 ++ , V_368 ) ;
}
if ( V_329 < V_369 )
break;
V_96 = V_329 * V_374 ;
V_251 = F_27 ( V_24 , V_82 , V_96 , V_373 ) ;
if ( V_251 )
return V_251 ;
V_373 += V_96 ;
}
if ( V_371 ) {
F_126 ( V_22 , V_368 ) ;
++ V_329 ;
}
if ( V_329 > 0 )
V_251 = F_27 ( V_24 , V_82 , V_329 * V_374 , V_373 ) ;
return V_251 ;
}
static int F_127 ( struct V_23 * V_24 , unsigned long long V_5 ,
unsigned int V_105 , struct V_53 * V_54 )
{
int V_329 ;
unsigned char * V_376 , * V_272 ;
unsigned int V_188 ;
struct V_85 * V_86 = F_23 ( V_24 ) ;
struct V_288 V_289 ;
V_272 = F_45 ( F_26 ( V_24 ) , V_138 ) ;
if ( ! V_272 ) {
F_14 ( V_24 , V_41 , V_196 ,
V_197 ) ;
return V_81 ;
}
F_32 ( V_24 , V_272 , F_26 ( V_24 ) ) ;
V_188 = 0 ;
F_88 ( & V_289 , V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_290 | V_291 ) ;
while ( F_91 ( & V_289 ) ) {
V_376 = V_289 . V_294 ;
for ( V_329 = 0 ; V_329 < V_289 . V_87 ; V_329 ++ )
* ( V_376 + V_329 ) ^= * ( V_272 + V_188 + V_329 ) ;
V_188 += V_289 . V_87 ;
}
F_92 ( & V_289 ) ;
F_47 ( V_272 ) ;
return 0 ;
}
static int F_128 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
T_2 * V_50 = V_24 -> V_132 ;
V_173 V_5 ;
T_7 V_105 ;
int V_189 ;
if ( ! F_24 ( V_24 ) ) {
F_14 ( V_24 , V_41 , V_196 ,
V_197 ) ;
return V_81 ;
}
V_189 = F_94 ( V_24 , V_54 ) ;
if ( V_189 )
return V_189 ;
if ( ! ( V_50 [ 1 ] & 0x4 ) ) {
V_189 = F_115 ( V_24 , V_54 ) ;
if ( V_189 )
return V_189 ;
}
V_5 = F_55 ( V_50 + 2 ) ;
V_105 = F_44 ( V_50 + 7 ) ;
return F_127 ( V_24 , V_5 , V_105 , V_54 ) ;
}
static struct V_377 * F_129 ( struct V_23 * V_132 )
{
struct V_377 * V_378 = V_379 ;
if ( V_380 ) {
T_7 V_381 = F_130 ( V_132 -> V_382 ) ;
T_6 V_383 = F_131 ( V_381 ) ;
if ( F_96 ( V_383 >= V_384 ) ) {
F_21 ( L_42 , V_383 ) ;
V_383 %= V_384 ;
}
F_29 ( L_43 , V_381 , V_383 ) ;
return V_378 + V_383 ;
} else
return V_378 ;
}
static void F_132 ( struct V_385 * V_386 )
{
int V_387 ;
int V_388 = 0 ;
unsigned long V_302 ;
struct V_377 * V_378 ;
struct V_300 * V_301 ;
struct V_23 * V_24 ;
struct V_53 * V_54 ;
V_387 = V_386 -> V_387 ;
V_378 = V_379 + V_386 -> V_389 ;
if ( V_390 ) {
F_133 ( & V_391 ) ;
if ( F_134 () != V_386 -> V_392 )
F_133 ( & V_393 ) ;
}
if ( F_96 ( ( V_387 < 0 ) || ( V_387 >= V_394 ) ) ) {
F_84 ( L_44 , V_387 ) ;
return;
}
F_135 ( & V_378 -> V_395 , V_302 ) ;
V_301 = & V_378 -> V_396 [ V_387 ] ;
V_24 = V_301 -> V_397 ;
if ( F_96 ( V_24 == NULL ) ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
F_84 ( L_45 ,
V_386 -> V_389 , V_387 ) ;
return;
}
V_54 = (struct V_53 * ) V_24 -> V_35 -> V_398 ;
if ( F_137 ( V_54 ) )
F_138 ( & V_54 -> V_399 ) ;
else
F_84 ( L_46 ) ;
if ( F_96 ( F_139 ( & V_400 ) > 0 ) )
V_388 = 1 ;
V_301 -> V_397 = NULL ;
if ( F_96 ( ! F_140 ( V_387 , V_378 -> V_401 ) ) ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
F_84 ( L_47 ) ;
return;
}
if ( F_96 ( V_388 ) ) {
int V_60 , V_356 ;
V_356 = F_139 ( & V_400 ) ;
if ( V_387 >= V_356 ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
F_84 ( L_48 , V_356 ) ;
return;
}
V_60 = F_141 ( V_378 -> V_401 , V_356 ) ;
if ( ( V_60 < V_402 ) || ( V_60 == V_356 ) )
F_142 ( & V_400 , 0 ) ;
else
F_142 ( & V_400 , V_60 + 1 ) ;
}
F_136 ( & V_378 -> V_395 , V_302 ) ;
V_24 -> V_403 ( V_24 ) ;
}
static enum V_404 F_143 ( struct V_405 * V_406 )
{
struct V_385 * V_386 = F_144 ( V_406 , struct V_385 ,
V_407 ) ;
F_132 ( V_386 ) ;
return V_408 ;
}
static void F_145 ( struct V_409 * V_410 )
{
struct V_385 * V_386 = F_144 ( V_410 , struct V_385 ,
V_411 . V_410 ) ;
F_132 ( V_386 ) ;
}
static struct V_53 * F_146 (
struct V_12 * V_13 , T_10 V_201 )
{
struct V_53 * V_54 ;
V_54 = F_45 ( sizeof( * V_54 ) , V_201 ) ;
if ( V_54 ) {
if ( V_110 == 1 )
F_147 ( & V_54 -> V_104 ) ;
else if ( V_110 == 2 ) {
if ( V_412 )
V_54 -> V_104 = V_413 ;
else {
F_147 ( & V_413 ) ;
V_412 = true ;
V_54 -> V_104 = V_413 ;
}
}
V_54 -> V_13 = V_13 ;
F_148 ( & V_54 -> V_414 , & V_13 -> V_415 ) ;
}
return V_54 ;
}
static struct V_53 * F_149 ( struct V_48 * V_416 )
{
struct V_12 * V_13 ;
struct V_53 * V_417 = NULL ;
struct V_53 * V_54 ;
V_13 = * (struct V_12 * * ) F_150 ( V_416 -> V_418 ) ;
if ( ! V_13 ) {
F_84 ( L_49 ) ;
return NULL ;
}
F_8 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_54 -> V_419 ) && ( V_54 -> V_151 == V_416 -> V_151 ) &&
( V_54 -> V_57 == V_416 -> V_234 ) &&
( V_54 -> V_142 == V_416 -> V_142 ) )
return V_54 ;
else {
if ( ( ! V_54 -> V_419 ) && ( ! V_417 ) )
V_417 = V_54 ;
}
}
if ( ! V_417 ) {
V_417 = F_146 ( V_13 , V_138 ) ;
if ( ! V_417 ) {
F_84 ( L_50 , __LINE__ ) ;
return NULL ;
}
}
V_417 -> V_151 = V_416 -> V_151 ;
V_417 -> V_57 = V_416 -> V_234 ;
V_417 -> V_142 = V_416 -> V_142 ;
V_417 -> V_13 = V_13 ;
F_142 ( & V_417 -> V_399 , 0 ) ;
F_70 ( V_63 , V_417 -> V_59 ) ;
V_417 -> V_419 = true ;
return V_417 ;
}
static int F_151 ( struct V_48 * V_352 )
{
if ( V_42 )
F_152 ( L_51 ,
V_352 -> V_418 -> V_150 , V_352 -> V_151 , V_352 -> V_234 , V_352 -> V_142 ) ;
F_153 ( V_420 , V_352 -> V_421 ) ;
return 0 ;
}
static int F_154 ( struct V_48 * V_352 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_352 -> V_398 ;
if ( V_42 )
F_152 ( L_52 ,
V_352 -> V_418 -> V_150 , V_352 -> V_151 , V_352 -> V_234 , V_352 -> V_142 ) ;
if ( V_352 -> V_418 -> V_422 != V_423 )
V_352 -> V_418 -> V_422 = V_423 ;
if ( V_54 == NULL ) {
V_54 = F_149 ( V_352 ) ;
if ( V_54 == NULL )
return 1 ;
}
V_352 -> V_398 = V_54 ;
F_155 ( V_352 -> V_421 , - 1U ) ;
if ( V_424 )
V_352 -> V_425 = 1 ;
return 0 ;
}
static void F_156 ( struct V_48 * V_352 )
{
struct V_53 * V_54 =
(struct V_53 * ) V_352 -> V_398 ;
if ( V_42 )
F_152 ( L_53 ,
V_352 -> V_418 -> V_150 , V_352 -> V_151 , V_352 -> V_234 , V_352 -> V_142 ) ;
if ( V_54 ) {
V_54 -> V_419 = false ;
V_352 -> V_398 = NULL ;
}
}
static void F_157 ( struct V_385 * V_386 )
{
if ( ! V_386 )
return;
if ( ( V_426 > 0 ) || ( V_427 > 0 ) )
F_158 ( & V_386 -> V_407 ) ;
else if ( V_426 < 0 )
F_159 ( & V_386 -> V_411 . V_410 ) ;
}
static bool F_160 ( struct V_23 * V_132 )
{
unsigned long V_302 ;
int V_329 , V_60 , V_428 , V_429 ;
struct V_377 * V_378 ;
struct V_300 * V_301 ;
struct V_53 * V_54 ;
struct V_385 * V_386 ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ; ++ V_329 , ++ V_378 ) {
F_135 ( & V_378 -> V_395 , V_302 ) ;
V_428 = V_402 ;
V_429 = F_139 ( & V_400 ) ;
if ( V_429 > V_428 )
V_428 = V_429 ;
for ( V_60 = 0 ; V_60 < V_428 ; ++ V_60 ) {
if ( F_109 ( V_60 , V_378 -> V_401 ) ) {
V_301 = & V_378 -> V_396 [ V_60 ] ;
if ( V_132 != V_301 -> V_397 )
continue;
V_54 = (struct V_53 * )
V_132 -> V_35 -> V_398 ;
if ( V_54 )
F_138 ( & V_54 -> V_399 ) ;
V_301 -> V_397 = NULL ;
V_386 = V_301 -> V_386 ;
F_136 ( & V_378 -> V_395 , V_302 ) ;
F_157 ( V_386 ) ;
F_18 ( V_60 , V_378 -> V_401 ) ;
return true ;
}
}
F_136 ( & V_378 -> V_395 , V_302 ) ;
}
return false ;
}
static void F_161 ( void )
{
unsigned long V_302 ;
int V_329 , V_60 ;
struct V_377 * V_378 ;
struct V_300 * V_301 ;
struct V_53 * V_54 ;
struct V_385 * V_386 ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ; ++ V_329 , ++ V_378 ) {
F_135 ( & V_378 -> V_395 , V_302 ) ;
for ( V_60 = 0 ; V_60 < V_394 ; ++ V_60 ) {
if ( F_109 ( V_60 , V_378 -> V_401 ) ) {
V_301 = & V_378 -> V_396 [ V_60 ] ;
if ( V_301 -> V_397 == NULL )
continue;
V_54 = (struct V_53 * )
V_301 -> V_397 -> V_35 -> V_398 ;
if ( V_54 )
F_138 ( & V_54 -> V_399 ) ;
V_301 -> V_397 = NULL ;
V_386 = V_301 -> V_386 ;
F_136 ( & V_378 -> V_395 , V_302 ) ;
F_157 ( V_386 ) ;
F_18 ( V_60 , V_378 -> V_401 ) ;
F_135 ( & V_378 -> V_395 , V_302 ) ;
}
}
F_136 ( & V_378 -> V_395 , V_302 ) ;
}
}
static void F_162 ( void )
{
int V_329 , V_60 ;
struct V_377 * V_378 ;
struct V_300 * V_301 ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ; ++ V_329 , ++ V_378 ) {
for ( V_60 = 0 ; V_60 < V_394 ; ++ V_60 ) {
V_301 = & V_378 -> V_396 [ V_60 ] ;
F_47 ( V_301 -> V_386 ) ;
V_301 -> V_386 = NULL ;
}
}
}
static int F_163 ( struct V_23 * V_283 )
{
bool V_430 ;
++ V_431 ;
if ( V_283 ) {
V_430 = F_160 ( V_283 ) ;
if ( V_283 -> V_35 && ( V_432 & V_218 ) )
F_11 ( V_43 , V_283 -> V_35 ,
L_54 , V_36 ,
V_430 ? L_55 : L_56 ) ;
}
return V_433 ;
}
static int F_164 ( struct V_23 * V_283 )
{
++ V_434 ;
if ( V_283 && V_283 -> V_35 ) {
struct V_48 * V_352 = V_283 -> V_35 ;
struct V_53 * V_54 =
(struct V_53 * ) V_352 -> V_398 ;
if ( V_432 & V_218 )
F_11 ( V_43 , V_352 , L_57 , V_36 ) ;
if ( V_54 )
F_70 ( V_63 , V_54 -> V_59 ) ;
}
return V_433 ;
}
static int F_165 ( struct V_23 * V_283 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_352 ;
struct V_14 * V_435 ;
int V_60 = 0 ;
++ V_436 ;
if ( ! V_283 )
goto V_437;
V_352 = V_283 -> V_35 ;
if ( ! V_352 )
goto V_437;
if ( V_432 & V_218 )
F_11 ( V_43 , V_352 , L_57 , V_36 ) ;
V_435 = V_352 -> V_418 ;
if ( ! V_435 )
goto V_437;
V_13 = * (struct V_12 * * ) F_150 ( V_435 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list)
if ( V_54 -> V_57 == V_352 -> V_234 ) {
F_70 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
if ( V_438 & V_218 )
F_11 ( V_43 , V_352 ,
L_58 , V_36 , V_60 ) ;
V_437:
return V_433 ;
}
static int F_166 ( struct V_23 * V_283 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
struct V_48 * V_352 ;
struct V_14 * V_435 ;
int V_60 = 0 ;
++ V_439 ;
if ( ! ( V_283 && V_283 -> V_35 ) )
goto V_437;
V_352 = V_283 -> V_35 ;
if ( V_432 & V_218 )
F_11 ( V_43 , V_352 , L_57 , V_36 ) ;
V_435 = V_352 -> V_418 ;
if ( V_435 ) {
V_13 = * (struct V_12 * * ) F_150 ( V_435 ) ;
if ( V_13 ) {
F_8 (devip,
&sdbg_host->dev_info_list,
dev_list) {
F_70 ( V_67 , V_54 -> V_59 ) ;
++ V_60 ;
}
}
}
if ( V_438 & V_218 )
F_11 ( V_43 , V_352 ,
L_59 , V_36 , V_60 ) ;
V_437:
return V_433 ;
}
static int F_167 ( struct V_23 * V_283 )
{
struct V_12 * V_13 ;
struct V_53 * V_54 ;
int V_60 = 0 ;
++ V_440 ;
if ( ( V_283 -> V_35 ) && ( V_432 & V_218 ) )
F_11 ( V_43 , V_283 -> V_35 , L_57 , V_36 ) ;
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
if ( V_438 & V_218 )
F_11 ( V_43 , V_283 -> V_35 ,
L_60 , V_36 , V_60 ) ;
return V_433 ;
}
static void T_11 F_168 ( unsigned char * V_441 ,
unsigned long V_442 )
{
struct V_443 * V_444 ;
int V_445 [ V_446 + 2 ] ;
int V_447 , V_448 , V_60 ;
int V_449 , V_295 , V_450 ;
if ( ( V_451 < 1 ) || ( V_442 < 1048576 ) )
return;
if ( V_451 > V_446 ) {
V_451 = V_446 ;
F_21 ( L_61 , V_446 ) ;
}
V_448 = ( int ) V_6 ;
V_447 = ( V_448 - V_214 )
/ V_451 ;
V_449 = V_452 * V_214 ;
V_445 [ 0 ] = V_214 ;
for ( V_60 = 1 ; V_60 < V_451 ; ++ V_60 )
V_445 [ V_60 ] = ( ( V_60 * V_447 ) / V_449 )
* V_449 ;
V_445 [ V_451 ] = V_448 ;
V_445 [ V_451 + 1 ] = 0 ;
V_441 [ 510 ] = 0x55 ;
V_441 [ 511 ] = 0xAA ;
V_444 = (struct V_443 * ) ( V_441 + 0x1be ) ;
for ( V_60 = 0 ; V_445 [ V_60 + 1 ] ; ++ V_60 , ++ V_444 ) {
V_295 = V_445 [ V_60 ] ;
V_450 = V_445 [ V_60 + 1 ] - 1 ;
V_444 -> V_453 = 0 ;
V_444 -> V_454 = V_295 / V_449 ;
V_444 -> V_455 = ( V_295 - ( V_444 -> V_454 * V_449 ) )
/ V_214 ;
V_444 -> V_10 = ( V_295 % V_214 ) + 1 ;
V_444 -> V_456 = V_450 / V_449 ;
V_444 -> V_457 = ( V_450 - ( V_444 -> V_456 * V_449 ) )
/ V_214 ;
V_444 -> V_458 = ( V_450 % V_214 ) + 1 ;
V_444 -> V_459 = F_169 ( V_295 ) ;
V_444 -> V_460 = F_169 ( V_450 - V_295 + 1 ) ;
V_444 -> V_461 = 0x83 ;
}
}
static void F_170 ( bool V_266 )
{
int V_329 ;
struct V_377 * V_378 ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ; ++ V_329 , ++ V_378 )
F_142 ( & V_378 -> V_462 , ( int ) V_266 ) ;
}
static void F_171 ( void )
{
int V_190 , V_463 ;
V_463 = abs ( V_464 ) ;
if ( V_463 < 2 )
return;
F_170 ( true ) ;
V_190 = F_139 ( & V_465 ) ;
F_142 ( & V_465 , ( V_190 / V_463 ) * V_463 ) ;
F_170 ( false ) ;
}
static void F_172 ( void )
{
F_142 ( & V_465 , 0 ) ;
F_142 ( & V_391 , 0 ) ;
F_142 ( & V_393 , 0 ) ;
F_142 ( & V_466 , 0 ) ;
}
static void F_173 ( struct V_377 * V_378 ,
struct V_300 * V_301 )
{
if ( ( F_139 ( & V_465 ) % abs ( V_464 ) ) > 0 )
return;
V_301 -> V_322 = ! ! ( V_467 & V_218 ) ;
V_301 -> V_324 = ! ! ( V_468 & V_218 ) ;
V_301 -> V_327 = ! ! ( V_469 & V_218 ) ;
V_301 -> V_328 = ! ! ( V_470 & V_218 ) ;
V_301 -> V_311 = ! ! ( V_471 & V_218 ) ;
}
static int F_174 ( struct V_23 * V_132 , struct V_53 * V_54 ,
int V_472 , int V_473 )
{
unsigned long V_302 ;
int V_60 , V_399 , V_474 , V_475 ;
struct V_377 * V_378 ;
struct V_300 * V_301 ;
struct V_48 * V_352 ;
struct V_385 * V_386 ;
if ( F_96 ( V_54 == NULL ) ) {
if ( V_472 == 0 )
V_472 = V_476 << 16 ;
goto V_477;
}
V_352 = V_132 -> V_35 ;
if ( F_96 ( V_42 && V_472 ) )
F_11 ( V_43 , V_352 , L_62 ,
V_36 , V_472 ) ;
if ( V_473 == 0 )
goto V_477;
V_378 = F_129 ( V_132 ) ;
F_135 ( & V_378 -> V_395 , V_302 ) ;
if ( F_96 ( F_139 ( & V_378 -> V_462 ) ) ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
return V_478 ;
}
V_399 = F_139 ( & V_54 -> V_399 ) ;
V_474 = V_132 -> V_35 -> V_479 ;
V_475 = 0 ;
if ( F_96 ( ( V_474 > 0 ) && ( V_399 >= V_474 ) ) ) {
if ( V_472 ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
goto V_477;
} else
V_472 = V_480 ;
} else if ( F_96 ( V_464 &&
( V_481 & V_218 ) &&
( V_472 == 0 ) ) ) {
if ( ( V_399 == ( V_474 - 1 ) ) &&
( F_175 ( & V_466 ) >=
abs ( V_464 ) ) ) {
F_142 ( & V_466 , 0 ) ;
V_475 = 1 ;
V_472 = V_480 ;
}
}
V_60 = F_176 ( V_378 -> V_401 , V_402 ) ;
if ( F_96 ( V_60 >= V_402 ) ) {
F_136 ( & V_378 -> V_395 , V_302 ) ;
if ( V_472 )
goto V_477;
else if ( V_482 & V_218 )
V_472 = V_480 ;
if ( V_483 & V_218 )
F_11 ( V_43 , V_352 ,
L_63 ,
V_36 , V_402 ,
( V_472 ? L_64 :
L_65 ) ) ;
if ( V_472 )
goto V_477;
else
return V_478 ;
}
F_177 ( V_60 , V_378 -> V_401 ) ;
F_133 ( & V_54 -> V_399 ) ;
V_301 = & V_378 -> V_396 [ V_60 ] ;
V_301 -> V_397 = V_132 ;
V_132 -> V_310 = ( unsigned char * ) V_301 ;
V_132 -> V_484 = V_472 ;
V_386 = V_301 -> V_386 ;
F_136 ( & V_378 -> V_395 , V_302 ) ;
if ( F_96 ( V_464 && V_309 ) )
F_173 ( V_378 , V_301 ) ;
if ( V_473 > 0 || V_427 > 0 ) {
T_12 V_485 ;
if ( V_473 > 0 ) {
struct V_486 V_487 ;
F_178 ( V_473 , & V_487 ) ;
V_485 = F_179 ( V_487 . V_488 , V_487 . V_489 ) ;
} else
V_485 = V_427 ;
if ( NULL == V_386 ) {
V_386 = F_45 ( sizeof( * V_386 ) , V_138 ) ;
if ( NULL == V_386 )
return V_478 ;
V_301 -> V_386 = V_386 ;
F_180 ( & V_386 -> V_407 , V_490 ,
V_491 ) ;
V_386 -> V_407 . V_492 = F_143 ;
V_386 -> V_389 = V_378 - V_379 ;
V_386 -> V_387 = V_60 ;
}
if ( V_390 )
V_386 -> V_392 = F_134 () ;
F_181 ( & V_386 -> V_407 , V_485 , V_491 ) ;
} else {
if ( NULL == V_386 ) {
V_386 = F_45 ( sizeof( * V_301 -> V_386 ) , V_138 ) ;
if ( NULL == V_386 )
return V_478 ;
V_301 -> V_386 = V_386 ;
V_386 -> V_389 = V_378 - V_379 ;
V_386 -> V_387 = V_60 ;
F_182 ( & V_386 -> V_411 . V_410 , F_145 ) ;
}
if ( V_390 )
V_386 -> V_392 = F_134 () ;
F_183 ( & V_386 -> V_411 . V_410 ) ;
}
if ( F_96 ( ( V_483 & V_218 ) &&
( V_472 == V_480 ) ) )
F_11 ( V_43 , V_352 ,
L_66 , V_36 ,
V_399 , ( V_475 ? L_67 : L_55 ) ,
L_64 ) ;
return 0 ;
V_477:
V_132 -> V_484 = V_472 ;
V_132 -> V_403 ( V_132 ) ;
return 0 ;
}
static const char * F_184 ( struct V_14 * V_493 )
{
int V_60 ;
V_60 = F_48 ( V_494 , V_495 , L_68 ,
V_44 , V_496 , V_497 ) ;
if ( V_60 >= ( V_495 - 1 ) )
return V_494 ;
F_48 ( V_494 + V_60 , V_495 - V_60 ,
L_69 ,
V_498 , V_218 , V_384 ,
L_70 , ( int ) V_390 ) ;
return V_494 ;
}
static int F_185 ( struct V_14 * V_418 , char * V_499 ,
int V_87 )
{
char V_82 [ 16 ] ;
int V_500 ;
int V_501 = V_87 > 15 ? 15 : V_87 ;
if ( ! F_186 ( V_502 ) || ! F_186 ( V_503 ) )
return - V_504 ;
memcpy ( V_82 , V_499 , V_501 ) ;
V_82 [ V_501 ] = '\0' ;
if ( 1 != sscanf ( V_82 , L_23 , & V_500 ) )
return - V_52 ;
V_218 = V_500 ;
V_42 = ! ! ( V_505 & V_500 ) ;
V_309 = ! ! ( V_506 & V_500 ) ;
if ( V_464 != 0 )
F_171 () ;
return V_87 ;
}
static int F_187 ( struct V_507 * V_508 , struct V_14 * V_418 )
{
int V_509 , V_329 , V_510 ;
struct V_377 * V_378 ;
F_188 ( V_508 , L_71 ,
V_496 , V_497 ) ;
F_188 ( V_508 , L_72 ,
V_19 , L_73 , V_498 ,
V_218 , V_464 ) ;
F_188 ( V_508 , L_74 ,
V_426 , V_427 , V_375 ,
V_8 , L_75 ) ;
F_188 ( V_508 , L_76 ,
V_511 , V_452 , V_214 ,
V_431 ) ;
F_188 ( V_508 , L_77 ,
V_434 , V_436 , V_439 ,
V_440 ) ;
F_188 ( V_508 , L_78 ,
V_299 , V_338 , V_298 ) ;
F_188 ( V_508 , L_79 ,
V_512 / 1000 , L_70 , V_390 ,
V_380 ) ;
F_188 ( V_508 , L_80 ,
F_139 ( & V_465 ) ,
F_139 ( & V_391 ) ,
L_81 , F_139 ( & V_393 ) ,
F_139 ( & V_466 ) ) ;
F_188 ( V_508 , L_82 , V_384 ) ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ; ++ V_329 , ++ V_378 ) {
F_188 ( V_508 , L_83 , V_329 ) ;
V_509 = F_20 ( V_378 -> V_401 , V_402 ) ;
if ( V_509 != V_402 ) {
V_510 = F_141 ( V_378 -> V_401 , V_402 ) ;
F_188 ( V_508 , L_84 ,
L_85 , V_509 , V_510 ) ;
}
}
return 0 ;
}
static T_13 F_189 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_426 ) ;
}
static T_13 F_190 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_516 , V_251 ;
if ( V_190 > 0 && sscanf ( V_272 , L_23 , & V_516 ) == 1 ) {
V_251 = V_190 ;
if ( V_426 != V_516 ) {
int V_329 , V_60 ;
struct V_377 * V_378 ;
F_170 ( true ) ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ;
++ V_329 , ++ V_378 ) {
V_60 = F_20 ( V_378 -> V_401 ,
V_402 ) ;
if ( V_60 != V_402 ) {
V_251 = - V_517 ;
break;
}
}
if ( V_251 > 0 ) {
F_162 () ;
V_426 = V_516 ;
V_427 = 0 ;
}
F_170 ( false ) ;
}
return V_251 ;
}
return - V_52 ;
}
static T_13 F_191 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_427 ) ;
}
static T_13 F_192 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_518 , V_251 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_518 ) ) &&
( V_518 >= 0 ) && ( V_518 < ( 1000 * 1000 * 1000 ) ) ) {
V_251 = V_190 ;
if ( V_427 != V_518 ) {
int V_329 , V_60 ;
struct V_377 * V_378 ;
F_170 ( true ) ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ;
++ V_329 , ++ V_378 ) {
V_60 = F_20 ( V_378 -> V_401 ,
V_402 ) ;
if ( V_60 != V_402 ) {
V_251 = - V_517 ;
break;
}
}
if ( V_251 > 0 ) {
F_162 () ;
V_427 = V_518 ;
V_426 = V_518 ? V_519
: V_520 ;
}
F_170 ( false ) ;
}
return V_251 ;
}
return - V_52 ;
}
static T_13 F_193 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_87 , V_218 ) ;
}
static T_13 F_194 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_500 ;
char V_410 [ 20 ] ;
if ( 1 == sscanf ( V_272 , L_88 , V_410 ) ) {
if ( 0 == strncasecmp ( V_410 , L_89 , 2 ) ) {
if ( 1 == sscanf ( & V_410 [ 2 ] , L_90 , & V_500 ) )
goto V_521;
} else {
if ( 1 == sscanf ( V_410 , L_23 , & V_500 ) )
goto V_521;
}
}
return - V_52 ;
V_521:
V_218 = V_500 ;
V_42 = ! ! ( V_505 & V_500 ) ;
V_309 = ! ! ( V_506 & V_500 ) ;
F_171 () ;
return V_190 ;
}
static T_13 F_195 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_140 ) ;
}
static T_13 F_196 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_140 = V_96 ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_197 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_40 ) ;
}
static T_13 F_198 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_40 = V_96 ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_199 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_1 ) ;
}
static T_13 F_200 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_96 = ( V_96 > 0 ) ;
V_1 = ( V_1 > 0 ) ;
if ( V_1 != V_96 ) {
if ( ( 0 == V_96 ) && ( NULL == V_7 ) ) {
unsigned long V_522 =
( unsigned long ) V_498 *
1048576 ;
V_7 = F_201 ( V_522 ) ;
if ( NULL == V_7 ) {
F_84 ( L_91 ) ;
return - V_523 ;
}
memset ( V_7 , 0 , V_522 ) ;
}
V_1 = V_96 ;
}
return V_190 ;
}
return - V_52 ;
}
static T_13 F_202 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_144 ) ;
}
static T_13 F_203 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_144 = V_96 ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_204 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_19 ) ;
}
static T_13 F_205 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_19 = V_96 ;
F_6 () ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_206 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_498 ) ;
}
static T_13 F_207 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_451 ) ;
}
static T_13 F_208 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_464 ) ;
}
static T_13 F_209 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_524 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_524 ) ) ) {
V_464 = V_524 ;
if ( V_524 && ! V_390 ) {
F_152 ( L_92 ) ;
V_390 = true ;
}
F_171 () ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_210 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_375 ) ;
}
static T_13 F_211 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
bool V_525 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
if ( V_96 > 256 ) {
F_21 ( L_93 ) ;
return - V_52 ;
}
V_525 = ( V_375 != V_96 ) ;
V_375 = V_96 ;
F_6 () ;
if ( V_525 && ( V_79 >= 5 ) ) {
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
return V_190 ;
}
return - V_52 ;
}
static T_13 F_212 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_402 ) ;
}
static T_13 F_213 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_329 , V_96 , V_60 , V_526 ;
struct V_377 * V_378 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 > 0 ) &&
( V_96 <= V_394 ) ) {
F_170 ( true ) ;
V_60 = 0 ;
for ( V_329 = 0 , V_378 = V_379 ; V_329 < V_384 ;
++ V_329 , ++ V_378 ) {
V_526 = F_141 ( V_378 -> V_401 , V_394 ) ;
if ( V_526 > V_60 )
V_60 = V_526 ;
}
V_402 = V_96 ;
if ( V_60 == V_394 )
F_142 ( & V_400 , 0 ) ;
else if ( V_60 >= V_96 )
F_142 ( & V_400 , V_60 + 1 ) ;
else
F_142 ( & V_400 , 0 ) ;
F_170 ( false ) ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_214 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_424 ) ;
}
static T_13 F_215 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_79 ) ;
}
static T_13 F_216 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_168 ) ;
}
static T_13 F_217 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
bool V_525 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_525 = ( V_168 != V_96 ) ;
V_168 = V_96 ;
V_171 = F_52 () ;
if ( V_525 ) {
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
return V_190 ;
}
return - V_52 ;
}
static T_13 F_218 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_527 ) ;
}
static T_13 F_219 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_528 ;
if ( sscanf ( V_272 , L_23 , & V_528 ) != 1 )
return - V_52 ;
if ( V_528 > 0 ) {
do {
F_220 () ;
} while ( -- V_528 );
} else if ( V_528 < 0 ) {
do {
F_221 () ;
} while ( ++ V_528 );
}
return V_190 ;
}
static T_13 F_222 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_152 ) ;
}
static T_13 F_223 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_152 = V_96 ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_224 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , ( int ) V_390 ) ;
}
static T_13 F_225 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( sscanf ( V_272 , L_23 , & V_96 ) == 1 ) && ( V_96 >= 0 ) ) {
if ( V_96 > 0 )
V_390 = true ;
else {
F_172 () ;
V_390 = false ;
}
return V_190 ;
}
return - V_52 ;
}
static T_13 F_226 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_94 , V_8 ) ;
}
static T_13 F_227 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_384 ) ;
}
static T_13 F_228 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_318 ) ;
}
static T_13 F_229 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_153 ) ;
}
static T_13 F_230 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_94 , V_274 ) ;
}
static T_13 F_231 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_223 ) ;
}
static T_13 F_232 ( struct V_513 * V_514 , char * V_272 )
{
T_13 V_190 ;
if ( ! F_1 () )
return F_48 ( V_272 , V_515 , L_95 ,
V_6 ) ;
V_190 = F_48 ( V_272 , V_515 - 1 , L_96 ,
( int ) V_344 , V_343 ) ;
V_272 [ V_190 ++ ] = '\n' ;
V_272 [ V_190 ] = '\0' ;
return V_190 ;
}
static T_13 F_233 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , V_156 ? 1 : 0 ) ;
}
static T_13 F_234 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_156 = ( V_96 > 0 ) ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_235 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , ! ! V_529 ) ;
}
static T_13 F_236 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_529 = ( V_96 > 0 ) ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_237 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , ! ! V_530 ) ;
}
static T_13 F_238 ( struct V_513 * V_514 , const char * V_272 ,
T_9 V_190 )
{
int V_96 ;
if ( ( V_190 > 0 ) && ( 1 == sscanf ( V_272 , L_23 , & V_96 ) ) && ( V_96 >= 0 ) ) {
V_530 = ( V_96 > 0 ) ;
return V_190 ;
}
return - V_52 ;
}
static T_13 F_239 ( struct V_513 * V_514 , char * V_272 )
{
return F_48 ( V_272 , V_515 , L_86 , ! ! V_110 ) ;
}
static int T_11 F_240 ( void )
{
unsigned long V_522 ;
int V_531 ;
int V_60 ;
int V_134 ;
F_142 ( & V_400 , 0 ) ;
if ( V_427 >= 1000 * 1000 * 1000 ) {
F_21 ( L_97 ) ;
V_427 = 0 ;
} else if ( V_427 > 0 )
V_426 = V_519 ;
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
switch ( V_153 ) {
case V_532 :
break;
case V_280 :
case V_282 :
case V_154 :
V_155 = true ;
break;
default:
F_84 ( L_99 ) ;
return - V_52 ;
}
if ( V_274 > 1 ) {
F_84 ( L_100 ) ;
return - V_52 ;
}
if ( V_223 > 1 ) {
F_84 ( L_101 ) ;
return - V_52 ;
}
if ( V_123 > 15 ) {
F_84 ( L_102 , V_123 ) ;
return - V_52 ;
}
if ( V_375 > 256 ) {
F_21 ( L_103 ) ;
V_375 = V_533 ;
}
if ( V_174 > 0x3fff ) {
F_84 ( L_104 , V_174 ) ;
return - V_52 ;
}
if ( V_384 < 1 ) {
F_84 ( L_105 ) ;
return - V_52 ;
}
V_379 = F_241 ( V_384 , sizeof( struct V_377 ) ,
V_534 ) ;
if ( V_379 == NULL )
return - V_523 ;
for ( V_60 = 0 ; V_60 < V_384 ; ++ V_60 )
F_242 ( & V_379 [ V_60 ] . V_395 ) ;
if ( V_498 < 1 )
V_498 = 1 ;
V_522 = ( unsigned long ) V_498 * 1048576 ;
V_6 = V_522 / V_8 ;
V_171 = F_52 () ;
V_452 = 8 ;
V_214 = 32 ;
if ( V_498 >= 256 )
V_452 = 64 ;
else if ( V_498 >= 16 )
V_452 = 32 ;
V_511 = ( unsigned long ) V_171 /
( V_214 * V_452 ) ;
if ( V_511 >= 1024 ) {
V_452 = 255 ;
V_214 = 63 ;
V_511 = ( unsigned long ) V_171 /
( V_214 * V_452 ) ;
}
if ( V_1 == 0 ) {
V_7 = F_201 ( V_522 ) ;
if ( NULL == V_7 ) {
F_84 ( L_106 ) ;
V_134 = - V_523 ;
goto V_535;
}
memset ( V_7 , 0 , V_522 ) ;
if ( V_451 > 0 )
F_168 ( V_7 , V_522 ) ;
}
if ( V_318 ) {
int V_536 ;
V_536 = V_6 * sizeof( struct V_9 ) ;
V_11 = F_201 ( V_536 ) ;
F_84 ( L_107 , V_536 , V_11 ) ;
if ( V_11 == NULL ) {
F_84 ( L_108 ) ;
V_134 = - V_523 ;
goto V_537;
}
memset ( V_11 , 0xff , V_536 ) ;
}
if ( F_1 () ) {
V_125 =
F_243 ( V_125 , 0U , 0xffffffffU ) ;
V_126 =
F_243 ( V_126 , 0U , 256U ) ;
V_128 =
F_243 ( V_128 , 1U , 0xffffffffU ) ;
if ( V_127 &&
V_128 <=
V_127 ) {
F_84 ( L_109 ) ;
V_134 = - V_52 ;
goto V_537;
}
V_344 = F_106 ( V_6 - 1 ) + 1 ;
V_343 = F_201 ( F_244 ( V_344 ) * sizeof( long ) ) ;
F_152 ( L_110 , V_344 ) ;
if ( V_343 == NULL ) {
F_84 ( L_111 ) ;
V_134 = - V_523 ;
goto V_537;
}
F_245 ( V_343 , V_344 ) ;
if ( V_451 )
F_113 ( 0 , 2 ) ;
}
V_538 = F_246 ( L_112 ) ;
if ( F_247 ( V_538 ) ) {
F_21 ( L_113 ) ;
V_134 = F_248 ( V_538 ) ;
goto V_537;
}
V_134 = F_249 ( & V_539 ) ;
if ( V_134 < 0 ) {
F_21 ( L_114 , V_134 ) ;
goto V_540;
}
V_134 = F_250 ( & V_541 ) ;
if ( V_134 < 0 ) {
F_21 ( L_115 , V_134 ) ;
goto V_542;
}
V_531 = V_527 ;
V_527 = 0 ;
for ( V_60 = 0 ; V_60 < V_531 ; V_60 ++ ) {
if ( F_220 () ) {
F_84 ( L_116 , V_60 ) ;
break;
}
}
if ( V_42 )
F_152 ( L_117 , V_527 ) ;
return 0 ;
V_542:
F_251 ( & V_539 ) ;
V_540:
F_252 ( V_538 ) ;
V_537:
F_253 ( V_343 ) ;
F_253 ( V_11 ) ;
F_253 ( V_7 ) ;
V_535:
F_47 ( V_379 ) ;
return V_134 ;
}
static void T_14 F_254 ( void )
{
int V_60 = V_527 ;
F_161 () ;
F_162 () ;
for (; V_60 ; V_60 -- )
F_221 () ;
F_255 ( & V_541 ) ;
F_251 ( & V_539 ) ;
F_252 ( V_538 ) ;
F_253 ( V_343 ) ;
F_253 ( V_11 ) ;
F_253 ( V_7 ) ;
F_47 ( V_379 ) ;
}
static void F_256 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
V_13 = F_257 ( V_49 ) ;
F_47 ( V_13 ) ;
}
static int F_220 ( void )
{
int V_60 , V_543 ;
int error = 0 ;
struct V_12 * V_13 ;
struct V_53 * V_544 , * V_545 ;
V_13 = F_45 ( sizeof( * V_13 ) , V_534 ) ;
if ( NULL == V_13 ) {
F_84 ( L_50 , __LINE__ ) ;
return - V_523 ;
}
F_258 ( & V_13 -> V_415 ) ;
V_543 = V_19 * V_375 ;
for ( V_60 = 0 ; V_60 < V_543 ; V_60 ++ ) {
V_544 = F_146 ( V_13 , V_534 ) ;
if ( ! V_544 ) {
F_84 ( L_50 , __LINE__ ) ;
error = - V_523 ;
goto V_546;
}
}
F_7 ( & V_16 ) ;
F_148 ( & V_13 -> V_547 , & V_548 ) ;
F_9 ( & V_16 ) ;
V_13 -> V_49 . V_549 = & V_539 ;
V_13 -> V_49 . V_550 = V_538 ;
V_13 -> V_49 . V_551 = & F_256 ;
F_259 ( & V_13 -> V_49 , L_118 , V_527 ) ;
error = F_260 ( & V_13 -> V_49 ) ;
if ( error )
goto V_546;
++ V_527 ;
return error ;
V_546:
F_261 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_262 ( & V_544 -> V_414 ) ;
F_47 ( V_544 ) ;
}
F_47 ( V_13 ) ;
return error ;
}
static void F_221 ( void )
{
struct V_12 * V_13 = NULL ;
F_7 ( & V_16 ) ;
if ( ! F_263 ( & V_548 ) ) {
V_13 = F_264 ( V_548 . V_552 ,
struct V_12 , V_547 ) ;
F_262 ( & V_13 -> V_547 ) ;
}
F_9 ( & V_16 ) ;
if ( ! V_13 )
return;
F_265 ( & V_13 -> V_49 ) ;
-- V_527 ;
}
static int F_266 ( struct V_48 * V_416 , int V_474 )
{
int V_399 = 0 ;
struct V_53 * V_54 ;
F_170 ( true ) ;
V_54 = (struct V_53 * ) V_416 -> V_398 ;
if ( NULL == V_54 ) {
F_170 ( false ) ;
return - V_553 ;
}
V_399 = F_139 ( & V_54 -> V_399 ) ;
if ( V_474 < 1 )
V_474 = 1 ;
if ( V_474 > V_394 + 10 )
V_474 = V_394 + 10 ;
F_267 ( V_416 , V_474 ) ;
if ( V_483 & V_218 ) {
F_11 ( V_43 , V_416 , L_119 ,
V_36 , V_474 , V_399 ) ;
}
F_170 ( false ) ;
return V_416 -> V_479 ;
}
static bool F_268 ( struct V_23 * V_24 )
{
if ( 0 == ( F_139 ( & V_465 ) % abs ( V_464 ) ) ) {
if ( V_464 < - 1 )
V_464 = - 1 ;
if ( V_554 & V_218 )
return true ;
else if ( V_555 & V_218 &&
F_269 ( V_24 ) )
return true ;
}
return false ;
}
static int F_270 ( struct V_14 * V_17 ,
struct V_23 * V_24 )
{
T_2 V_183 ;
struct V_48 * V_352 = V_24 -> V_35 ;
const struct V_193 * V_194 ;
const struct V_193 * V_195 ;
struct V_53 * V_54 ;
T_2 * V_50 = V_24 -> V_132 ;
int (* F_271)( struct V_23 * , struct V_53 * );
int V_60 , V_192 ;
int V_189 = 0 ;
T_7 V_201 ;
T_6 V_203 ;
T_2 V_202 = V_50 [ 0 ] ;
bool V_556 ;
F_97 ( V_24 , 0 ) ;
if ( V_390 )
F_133 ( & V_465 ) ;
if ( F_96 ( V_42 &&
! ( V_557 & V_218 ) ) ) {
char V_107 [ 120 ] ;
int V_96 , V_148 , V_558 ;
V_148 = V_24 -> V_559 ;
V_558 = ( int ) sizeof( V_107 ) ;
if ( V_148 > 32 )
strcpy ( V_107 , L_120 ) ;
else {
for ( V_60 = 0 , V_96 = 0 ; V_60 < V_148 && V_96 < V_558 ; ++ V_60 )
V_96 += F_48 ( V_107 + V_96 , V_558 - V_96 , L_31 ,
( T_7 ) V_50 [ V_60 ] ) ;
}
if ( V_380 )
F_11 ( V_43 , V_352 , L_121 ,
V_44 , F_130 ( V_24 -> V_382 ) ,
V_107 ) ;
else
F_11 ( V_43 , V_352 , L_122 , V_44 ,
V_107 ) ;
}
V_556 = ( V_352 -> V_142 == V_22 ) ;
if ( F_96 ( ( V_352 -> V_142 >= V_375 ) && ! V_556 ) )
goto V_560;
V_183 = V_207 [ V_202 ] ;
V_194 = & V_198 [ V_183 ] ;
V_54 = (struct V_53 * ) V_352 -> V_398 ;
if ( F_96 ( ! V_54 ) ) {
V_54 = F_149 ( V_352 ) ;
if ( NULL == V_54 )
goto V_560;
}
V_192 = V_194 -> V_199 ;
F_271 = V_194 -> V_561 ;
if ( V_192 ) {
V_195 = V_194 ;
if ( V_204 & V_195 -> V_201 ) {
if ( V_562 & V_194 -> V_201 )
V_203 = 0x1f & V_50 [ 1 ] ;
else
V_203 = F_44 ( V_50 + 8 ) ;
for ( V_60 = 0 ; V_60 <= V_192 ; V_194 = V_195 -> V_206 + V_60 ++ ) {
if ( V_202 == V_194 -> V_202 && V_203 == V_194 -> V_203 )
break;
}
} else {
for ( V_60 = 0 ; V_60 <= V_192 ; V_194 = V_195 -> V_206 + V_60 ++ ) {
if ( V_202 == V_194 -> V_202 )
break;
}
}
if ( V_60 > V_192 ) {
if ( V_562 & V_195 -> V_201 )
F_10 ( V_24 , V_146 , 1 , 4 ) ;
else if ( V_563 & V_195 -> V_201 )
F_10 ( V_24 , V_146 , 8 , 7 ) ;
else
F_15 ( V_24 ) ;
goto V_564;
}
}
V_201 = V_194 -> V_201 ;
if ( F_96 ( V_200 & V_201 ) ) {
F_15 ( V_24 ) ;
goto V_564;
}
if ( F_96 ( V_556 && ! ( V_565 & V_201 ) ) ) {
if ( V_42 )
F_11 ( V_43 , V_352 , L_123 ,
V_44 , V_202 , L_124 ) ;
F_15 ( V_24 ) ;
goto V_564;
}
if ( F_96 ( V_530 ) ) {
T_2 V_566 ;
int V_329 ;
for ( V_60 = 1 ; V_60 < V_194 -> V_205 [ 0 ] && V_60 < 16 ; ++ V_60 ) {
V_566 = ~ V_194 -> V_205 [ V_60 ] & V_50 [ V_60 ] ;
if ( V_566 ) {
for ( V_329 = 7 ; V_329 >= 0 ; -- V_329 , V_566 <<= 1 ) {
if ( 0x80 & V_566 )
break;
}
F_10 ( V_24 , V_146 , V_60 , V_329 ) ;
goto V_564;
}
}
}
if ( F_96 ( ! ( V_567 & V_201 ) &&
F_20 ( V_54 -> V_59 ,
V_61 ) != V_61 ) ) {
V_189 = F_19 ( V_24 , V_54 ) ;
if ( V_189 )
goto V_564;
}
if ( F_96 ( ( V_568 & V_201 ) && F_139 ( & V_54 -> V_166 ) ) ) {
F_14 ( V_24 , V_569 , V_570 , 0x2 ) ;
if ( V_42 )
F_11 ( V_43 , V_352 , L_125
L_57 , V_44 , L_126
L_127 ) ;
V_189 = V_81 ;
goto V_571;
}
if ( V_1 && ( V_572 & V_201 ) )
goto V_571;
if ( F_96 ( V_464 ) ) {
if ( F_268 ( V_24 ) )
return 0 ;
}
if ( F_137 ( V_194 -> V_561 ) )
V_189 = V_194 -> V_561 ( V_24 , V_54 ) ;
else if ( F_271 )
V_189 = F_271 ( V_24 , V_54 ) ;
V_571:
return F_174 ( V_24 , V_54 , V_189 ,
( ( V_573 & V_201 ) ? 0 : V_426 ) ) ;
V_564:
return F_174 ( V_24 , V_54 , V_81 , 0 ) ;
V_560:
return F_174 ( V_24 , NULL , V_476 << 16 , 0 ) ;
}
static int F_272 ( struct V_35 * V_49 )
{
int error = 0 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_574 ;
V_13 = F_257 ( V_49 ) ;
V_575 . V_576 = V_402 ;
if ( V_577 )
V_575 . V_578 = V_579 ;
V_15 = F_273 ( & V_575 , sizeof( V_13 ) ) ;
if ( NULL == V_15 ) {
F_84 ( L_128 ) ;
error = - V_553 ;
return error ;
}
if ( V_384 > V_580 ) {
F_21 ( L_129 ,
V_44 , V_384 , V_580 ) ;
V_384 = V_580 ;
}
V_380 = F_274 ( V_15 ) && ( V_384 > 1 ) ;
if ( V_380 )
V_15 -> V_581 = V_384 ;
V_13 -> V_17 = V_15 ;
* ( (struct V_12 * * ) V_15 -> V_398 ) = V_13 ;
if ( ( V_15 -> V_18 >= 0 ) && ( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 + 1 ;
V_574 = 0 ;
switch ( V_153 ) {
case V_280 :
V_574 = V_582 ;
if ( V_318 )
V_574 |= V_583 ;
break;
case V_282 :
V_574 = V_584 ;
if ( V_318 )
V_574 |= V_585 ;
break;
case V_154 :
V_574 = V_586 ;
if ( V_318 )
V_574 |= V_587 ;
break;
default:
if ( V_318 )
V_574 |= V_588 ;
break;
}
F_275 ( V_15 , V_574 ) ;
if ( V_155 || V_318 )
F_152 ( L_130 ,
( V_574 & V_582 ) ? L_131 : L_55 ,
( V_574 & V_584 ) ? L_132 : L_55 ,
( V_574 & V_586 ) ? L_133 : L_55 ,
( V_574 & V_588 ) ? L_134 : L_55 ,
( V_574 & V_583 ) ? L_135 : L_55 ,
( V_574 & V_585 ) ? L_136 : L_55 ,
( V_574 & V_587 ) ? L_137 : L_55 ) ;
if ( V_274 == 1 )
F_276 ( V_15 , V_589 ) ;
else
F_276 ( V_15 , V_590 ) ;
V_42 = ! ! ( V_505 & V_218 ) ;
V_309 = ! ! ( V_506 & V_218 ) ;
if ( V_464 )
V_390 = true ;
error = F_277 ( V_15 , & V_13 -> V_49 ) ;
if ( error ) {
F_84 ( L_138 ) ;
error = - V_553 ;
F_278 ( V_15 ) ;
} else
F_279 ( V_15 ) ;
return error ;
}
static int F_280 ( struct V_35 * V_49 )
{
struct V_12 * V_13 ;
struct V_53 * V_544 , * V_545 ;
V_13 = F_257 ( V_49 ) ;
if ( ! V_13 ) {
F_84 ( L_139 ) ;
return - V_553 ;
}
F_281 ( V_13 -> V_17 ) ;
F_261 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_262 ( & V_544 -> V_414 ) ;
F_47 ( V_544 ) ;
}
F_278 ( V_13 -> V_17 ) ;
return 0 ;
}
static int F_282 ( struct V_35 * V_49 ,
struct V_513 * V_591 )
{
return 1 ;
}
