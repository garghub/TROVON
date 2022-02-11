static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_10 ;
unsigned long V_11 = 0 ;
int V_12 , V_13 ;
F_3 ( V_8 ) ;
V_13 = F_4 ( V_4 , V_14 ) ;
if ( V_13 < 0 ) {
F_5 ( V_8 ) ;
return V_15 ;
}
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 <= 0 ) {
F_5 ( V_8 ) ;
return V_15 ;
}
if ( V_12 & V_17 ) {
V_12 &= ~ V_17 ;
V_13 &= ~ V_18 ;
V_11 |= V_19 ;
}
if ( V_11 ) {
F_6 ( V_6 -> V_9 , 1 , V_11 ) ;
F_7 ( V_4 , V_16 , V_12 ) ;
F_7 ( V_4 , V_14 ,
V_13 ) ;
}
F_5 ( V_8 ) ;
return V_20 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
unsigned char V_23 [ 8 ] ;
int V_24 , V_12 ;
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & V_25 ) {
F_9 ( & V_4 -> V_26 , L_1 ) ;
return - V_27 ;
}
V_24 = F_10 ( V_4 , V_28 ,
sizeof( V_23 ) , V_23 ) ;
if ( V_24 < 0 ) {
F_9 ( & V_4 -> V_26 , L_2 ) ;
return - V_29 ;
}
V_22 -> V_30 = F_11 ( V_23 [ V_31 ] & 0x7f ) ;
V_22 -> V_32 = F_11 ( V_23 [ V_33 ] & 0x7f ) ;
V_22 -> V_34 = F_11 ( V_23 [ V_35 ] & 0x3f ) ;
V_22 -> V_36 = F_11 ( V_23 [ V_37 ] & 0x3f ) ;
V_22 -> V_38 = V_23 [ V_39 ] & 0x07 ;
V_22 -> V_40 = F_11 ( V_23 [ V_41 ] & 0x1f ) - 1 ;
V_22 -> V_42 = F_11 ( V_23 [ V_43 ] ) + 100 ;
return F_12 ( V_22 ) ;
}
static int F_13 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
struct V_5 * V_44 = F_2 ( V_4 ) ;
unsigned char V_23 [ 8 ] ;
int V_24 , V_12 ;
if ( V_22 -> V_42 < 100 || V_22 -> V_42 > 199 )
return - V_27 ;
V_23 [ V_28 ] = 0 ;
V_23 [ V_31 ] = F_14 ( V_22 -> V_30 ) ;
V_23 [ V_33 ] = F_14 ( V_22 -> V_32 ) ;
V_23 [ V_35 ] = F_14 ( V_22 -> V_34 ) ;
V_23 [ V_37 ] = F_14 ( V_22 -> V_36 ) ;
V_23 [ V_41 ] = F_14 ( V_22 -> V_40 + 1 ) ;
V_23 [ V_43 ] = F_14 ( V_22 -> V_42 - 100 ) ;
V_23 [ V_39 ] = V_22 -> V_38 ;
if ( V_44 -> V_45 & V_46 ) {
int V_47 ;
V_47 = F_4 ( V_4 , V_39 ) ;
if ( V_47 < 0 )
return V_47 ;
V_23 [ V_39 ] |= ( V_47 & 0xf0 ) ;
}
V_24 = F_15 ( V_4 , V_28 ,
sizeof( V_23 ) , V_23 ) ;
if ( V_24 < 0 ) {
F_9 ( & V_4 -> V_26 , L_3 ) ;
return V_24 ;
}
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_7 ( V_4 , V_16 ,
V_12 & ~ V_25 ) ) {
F_9 ( & V_4 -> V_26 , L_4 ) ;
return - V_29 ;
}
return V_24 ;
}
static int F_16 ( struct V_48 * V_26 , struct V_49 * V_50 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_5 * V_44 = F_2 ( V_4 ) ;
T_2 V_51 ;
if ( V_44 -> V_45 & V_52 ) {
V_51 = F_4 ( V_4 , V_16 ) ;
F_18 ( V_50 , L_5 ,
( V_51 & V_53 ) ? L_6 : L_7 ) ;
}
return 0 ;
}
static int F_19 ( struct V_48 * V_26 , struct V_21 * V_22 )
{
return F_8 ( F_17 ( V_26 ) , V_22 ) ;
}
static int F_20 ( struct V_48 * V_26 , struct V_21 * V_22 )
{
return F_13 ( F_17 ( V_26 ) , V_22 ) ;
}
static int F_21 ( struct V_48 * V_26 , unsigned int V_54 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_12 , V_55 ;
V_12 = F_4 ( V_4 , V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_54 )
V_12 |= V_18 ;
else
V_12 &= ~ V_18 ;
V_55 = F_7 ( V_4 , V_14 , V_12 ) ;
if ( V_55 < 0 ) {
F_9 ( V_26 , L_8 , V_55 ) ;
return V_55 ;
}
return 0 ;
}
static int F_22 ( struct V_48 * V_26 , struct V_56 * V_57 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
T_2 V_58 [ 5 ] ;
int V_59 , V_24 ;
V_58 [ 0 ] = F_14 ( V_57 -> time . V_40 + 1 ) ;
V_58 [ 1 ] = F_14 ( V_57 -> time . V_36 ) ;
V_58 [ 2 ] = F_14 ( V_57 -> time . V_34 ) ;
V_58 [ 3 ] = F_14 ( V_57 -> time . V_32 ) ;
V_58 [ 4 ] = F_14 ( V_57 -> time . V_30 ) ;
V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return V_59 ;
V_24 = F_7 ( V_4 , V_14 ,
V_59 & ~ ( V_18 ) ) ;
if ( V_24 < 0 ) {
F_9 ( V_26 , L_9 ) ;
return V_24 ;
}
V_58 [ 0 ] |= ( V_59 & V_60 ) ;
V_59 = F_4 ( V_4 , V_16 ) ;
if ( V_59 < 0 )
return V_59 ;
V_24 = F_7 ( V_4 , V_16 ,
V_59 & ~ ( V_17 ) ) ;
if ( V_24 < 0 ) {
F_9 ( V_26 , L_10 ) ;
return V_24 ;
}
V_24 = F_15 ( V_4 , V_14 ,
5 , V_58 ) ;
if ( V_24 )
return V_24 ;
if ( V_57 -> V_54 ) {
V_58 [ 0 ] |= V_18 ;
V_24 = F_7 ( V_4 , V_14 ,
V_58 [ 0 ] ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_23 ( struct V_48 * V_26 , struct V_56 * V_57 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
T_2 V_58 [ 5 ] ;
int V_12 , V_59 ;
V_59 = F_10 ( V_4 , V_14 ,
5 , V_58 ) ;
if ( V_59 != 5 )
return V_59 < 0 ? V_59 : - V_29 ;
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_57 -> time . V_30 = F_11 ( V_58 [ 4 ] & 0x7f ) ;
V_57 -> time . V_32 = F_11 ( V_58 [ 3 ] & 0x7f ) ;
V_57 -> time . V_34 = F_11 ( V_58 [ 2 ] & 0x3f ) ;
V_57 -> time . V_36 = F_11 ( V_58 [ 1 ] & 0x3f ) ;
V_57 -> time . V_40 = F_11 ( V_58 [ 0 ] & 0x3f ) ;
V_57 -> V_54 = ! ! ( V_58 [ 0 ] & V_18 ) ;
V_57 -> V_61 = ( V_12 & V_17 ) && V_57 -> V_54 ;
return 0 ;
}
static int F_24 ( struct V_48 * V_26 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
if ( V_4 -> V_1 >= 0 && F_25 ( V_26 ) )
F_26 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_27 ( struct V_48 * V_26 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
if ( V_4 -> V_1 >= 0 && F_25 ( V_26 ) )
F_28 ( V_4 -> V_1 ) ;
return 0 ;
}
static unsigned long F_29 ( struct V_62 * V_63 ,
unsigned long V_64 )
{
struct V_5 * V_6 = F_30 ( V_63 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_65 = ( V_6 -> V_45 & V_46 ) ?
V_39 : V_66 ;
int V_59 = F_4 ( V_4 , V_65 ) ;
unsigned long V_47 = V_67 ;
if ( V_59 < 0 )
return 0 ;
V_59 >>= 4 ;
if ( V_59 == 0 )
V_47 = 0 ;
else if ( V_59 > 1 )
V_47 = V_47 / ( 1 << V_59 ) ;
return V_47 ;
}
static long F_31 ( struct V_62 * V_63 , unsigned long V_68 ,
unsigned long * V_69 )
{
int V_70 , V_71 = V_67 ;
if ( V_71 <= V_68 )
return V_71 ;
for ( V_70 = 2 ; V_70 <= F_32 ( V_67 ) ; V_70 ++ ) {
V_71 /= 1 << V_70 ;
if ( V_71 <= V_68 )
return V_71 ;
}
return 0 ;
}
static int F_33 ( struct V_62 * V_63 , unsigned long V_68 ,
unsigned long V_64 )
{
struct V_5 * V_6 = F_30 ( V_63 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_65 = ( V_6 -> V_45 & V_46 ) ?
V_39 : V_66 ;
int V_51 , V_59 , V_47 = 0 ;
if ( V_68 ) {
if ( ! F_34 ( V_68 ) )
return - V_27 ;
V_47 = F_32 ( V_68 ) ;
if ( V_47 == F_32 ( V_67 ) )
V_47 = 1 ;
else if ( V_47 < ( F_32 ( V_67 ) - 1 ) )
V_47 = F_32 ( V_67 ) - V_47 ;
else
return - V_27 ;
}
V_51 = F_4 ( V_4 , V_65 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = ( V_51 & 0x0f ) | ( V_47 << 4 ) ;
V_59 = F_7 ( V_4 , V_65 , V_51 ) ;
if ( V_59 < 0 )
return V_59 ;
return - V_27 ;
}
static int F_35 ( struct V_62 * V_63 , bool V_72 )
{
struct V_5 * V_6 = F_30 ( V_63 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_72 )
V_59 |= V_60 ;
else
V_59 &= ~ V_60 ;
return F_7 ( V_4 , V_14 , V_59 ) ;
}
static int F_36 ( struct V_62 * V_63 )
{
return F_35 ( V_63 , 1 ) ;
}
static void F_37 ( struct V_62 * V_63 )
{
F_35 ( V_63 , 0 ) ;
}
static int F_38 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_30 ( V_63 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return V_59 ;
return ! ! ( V_59 & V_60 ) ;
}
static struct V_73 * F_39 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_74 * V_75 = V_4 -> V_26 . V_76 ;
struct V_73 * V_73 ;
struct V_77 V_78 ;
int V_59 ;
V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return F_40 ( V_59 ) ;
V_59 = F_7 ( V_4 , V_14 ,
V_59 & ~ ( V_60 ) ) ;
if ( V_59 < 0 )
return F_40 ( V_59 ) ;
V_78 . V_79 = L_11 ;
V_78 . V_80 = & V_81 ;
V_78 . V_12 = 0 ;
V_78 . V_82 = NULL ;
V_78 . V_83 = 0 ;
V_6 -> V_84 . V_78 = & V_78 ;
F_41 ( V_75 , L_12 , & V_78 . V_79 ) ;
V_73 = F_42 ( & V_4 -> V_26 , & V_6 -> V_84 ) ;
if ( ! F_43 ( V_73 ) )
F_44 ( V_75 , V_85 , V_73 ) ;
return V_73 ;
}
static void F_45 ( void )
{
unsigned char V_86 [ 2 ] ;
struct V_87 V_88 [ 1 ] = {
{
. V_89 = V_90 -> V_89 ,
. V_12 = 0 ,
. V_91 = 2 ,
. V_23 = V_86 ,
} ,
} ;
struct V_5 * V_44 = F_2 ( V_90 ) ;
V_86 [ 0 ] = 0x09 ;
if ( V_92 > 31 )
V_86 [ 1 ] = ( V_92 & 0xFC ) | 0x83 ;
else
V_86 [ 1 ] = V_92 << 2 | 0x82 ;
if ( V_44 -> V_45 & V_93 )
V_86 [ 1 ] &= ~ V_94 ;
F_46 ( V_90 -> V_95 , V_88 , 1 ) ;
}
static void F_47 ( void )
{
unsigned char V_86 [ 2 ] , V_96 [ 0x10 ] ;
struct V_87 V_97 [ 2 ] = {
{
. V_89 = V_90 -> V_89 ,
. V_12 = 0 ,
. V_91 = 1 ,
. V_23 = V_86 ,
} ,
{
. V_89 = V_90 -> V_89 ,
. V_12 = V_98 ,
. V_91 = 1 ,
. V_23 = V_96 ,
} ,
} ;
struct V_87 V_88 [ 1 ] = {
{
. V_89 = V_90 -> V_89 ,
. V_12 = 0 ,
. V_91 = 2 ,
. V_23 = V_86 ,
} ,
} ;
V_86 [ 0 ] = 0x09 ;
F_46 ( V_90 -> V_95 , V_97 , 2 ) ;
V_86 [ 0 ] = 0x09 ;
V_86 [ 1 ] = 0x00 ;
F_46 ( V_90 -> V_95 , V_88 , 1 ) ;
}
static T_3 F_48 ( struct V_99 * V_99 , const char T_4 * V_23 ,
T_5 V_100 , T_6 * V_101 )
{
if ( V_100 ) {
F_45 () ;
return 1 ;
}
return 0 ;
}
static T_3 F_49 ( struct V_99 * V_99 , char T_4 * V_23 ,
T_5 V_100 , T_6 * V_101 )
{
return 0 ;
}
static int F_50 ( struct V_99 * V_99 , unsigned int V_102 ,
unsigned long V_103 )
{
int V_104 , V_105 ;
static struct V_106 V_107 = {
. V_108 = V_109 | V_110 |
V_111 ,
. V_112 = 1 ,
. V_113 = L_13
} ;
switch ( V_102 ) {
case V_114 :
return F_51 ( (struct V_106 T_4 * ) V_103 , & V_107 ,
sizeof( V_107 ) ) ? - V_115 : 0 ;
case V_116 :
case V_117 :
return F_52 ( V_118 , ( int T_4 * ) V_103 ) ;
case V_119 :
F_45 () ;
return 0 ;
case V_120 :
if ( F_53 ( V_104 , ( int T_4 * ) V_103 ) )
return - V_115 ;
if ( V_104 < 1 || V_104 > 124 )
return - V_27 ;
V_92 = V_104 ;
F_45 () ;
case V_121 :
return F_52 ( V_92 , ( int T_4 * ) V_103 ) ;
case V_122 :
if ( F_54 ( & V_105 , ( int T_4 * ) V_103 , sizeof( int ) ) )
return - V_115 ;
if ( V_105 & V_123 ) {
F_55 ( L_14 ) ;
F_47 () ;
}
if ( V_105 & V_124 ) {
F_55 ( L_15 ) ;
F_45 () ;
}
return - V_27 ;
}
return - V_125 ;
}
static long F_56 ( struct V_99 * V_99 , unsigned int V_102 ,
unsigned long V_103 )
{
int V_59 ;
F_3 ( & V_126 ) ;
V_59 = F_50 ( V_99 , V_102 , V_103 ) ;
F_5 ( & V_126 ) ;
return V_59 ;
}
static int F_57 ( struct V_127 * V_127 , struct V_99 * V_99 )
{
if ( F_58 ( V_127 -> V_128 ) == V_129 ) {
F_3 ( & V_126 ) ;
if ( F_59 ( 0 , & V_130 ) ) {
F_5 ( & V_126 ) ;
return - V_131 ;
}
V_130 = 1 ;
F_5 ( & V_126 ) ;
return F_60 ( V_127 , V_99 ) ;
}
return - V_132 ;
}
static int F_61 ( struct V_127 * V_127 , struct V_99 * V_99 )
{
if ( F_58 ( V_127 -> V_128 ) == V_129 )
F_62 ( 0 , & V_130 ) ;
return 0 ;
}
static int F_63 ( struct V_133 * V_134 , unsigned long V_135 ,
void * V_136 )
{
if ( V_135 == V_137 || V_135 == V_138 )
F_47 () ;
return V_139 ;
}
static int F_64 ( struct V_3 * V_4 ,
const struct V_140 * V_141 )
{
struct V_142 * V_95 = F_65 ( V_4 -> V_26 . V_143 ) ;
int V_144 = 0 ;
struct V_145 * V_9 = NULL ;
struct V_21 V_22 ;
struct V_5 * V_5 = NULL ;
bool V_146 = false ;
if ( ! F_66 ( V_4 -> V_95 , V_147 |
V_148 ) ) {
F_9 ( & V_95 -> V_26 , L_16 ) ;
return - V_132 ;
}
V_5 = F_67 ( & V_4 -> V_26 , sizeof( * V_5 ) ,
V_149 ) ;
if ( ! V_5 )
return - V_150 ;
V_5 -> V_4 = V_4 ;
if ( V_4 -> V_26 . V_76 )
V_5 -> V_45 = ( unsigned long )
F_68 ( & V_4 -> V_26 ) ;
else
V_5 -> V_45 = V_141 -> V_151 ;
F_69 ( V_4 , V_5 ) ;
#ifdef F_70
V_146 = F_71 ( V_4 -> V_26 . V_76 ,
L_17 ) ;
#endif
if ( V_4 -> V_1 > 0 ) {
V_144 = F_72 ( & V_4 -> V_26 , V_4 -> V_1 ,
NULL , F_1 ,
V_152 | V_153 ,
L_18 , V_4 ) ;
if ( V_144 ) {
F_73 ( & V_4 -> V_26 , L_19 ) ;
V_4 -> V_1 = 0 ;
V_146 = false ;
}
}
if ( V_4 -> V_1 > 0 || V_146 ) {
V_154 . V_155 = F_23 ;
V_154 . V_156 = F_22 ;
V_154 . V_157 = F_21 ;
F_74 ( & V_4 -> V_26 , true ) ;
}
V_9 = F_75 ( & V_4 -> V_26 , V_4 -> V_79 ,
& V_154 , V_158 ) ;
if ( F_43 ( V_9 ) )
return F_76 ( V_9 ) ;
V_5 -> V_9 = V_9 ;
if ( V_4 -> V_1 <= 0 ) {
V_9 -> V_159 = 1 ;
}
V_144 = F_4 ( V_4 , V_160 ) ;
if ( V_144 >= 0 && V_144 & V_161 ) {
if ( V_5 -> V_45 & V_162 ) {
F_8 ( V_4 , & V_22 ) ;
F_77 ( & V_4 -> V_26 , L_20 ) ;
F_77 ( & V_4 -> V_26 ,
L_21 ,
V_22 . V_42 + 1900 ,
V_22 . V_40 + 1 , V_22 . V_36 , V_22 . V_34 ,
V_22 . V_32 , V_22 . V_30 ) ;
}
V_144 = F_7 ( V_4 , V_160 ,
V_144 & ~ V_161 ) ;
}
if ( V_144 < 0 ) {
F_9 ( & V_4 -> V_26 , L_22 ) ;
return V_144 ;
}
V_144 = F_4 ( V_4 , V_31 ) ;
if ( V_144 >= 0 && V_144 & V_163 )
V_144 = F_7 ( V_4 , V_31 ,
V_144 & ~ V_163 ) ;
if ( V_144 < 0 ) {
F_9 ( & V_4 -> V_26 , L_23 ) ;
return V_144 ;
}
#ifdef F_78
if ( V_5 -> V_45 & V_162 ) {
V_90 = V_4 ;
V_144 = F_79 ( & V_164 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_80 ( & V_165 ) ;
if ( V_144 ) {
F_81 ( & V_164 ) ;
return V_144 ;
}
}
#endif
#ifdef F_82
if ( V_5 -> V_45 & V_166 )
F_39 ( V_5 ) ;
#endif
return 0 ;
}
static int F_83 ( struct V_3 * V_4 )
{
#ifdef F_78
struct V_5 * V_44 = F_2 ( V_4 ) ;
if ( V_44 -> V_45 & V_162 ) {
F_81 ( & V_164 ) ;
F_84 ( & V_165 ) ;
}
#endif
return 0 ;
}
