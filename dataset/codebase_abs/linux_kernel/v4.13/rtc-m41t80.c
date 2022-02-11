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
static T_3 F_29 ( struct V_48 * V_26 ,
struct V_62 * V_63 , char * V_23 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_47 ;
V_47 = F_4 ( V_4 , V_16 ) ;
if ( V_47 < 0 )
return V_47 ;
return sprintf ( V_23 , L_11 , V_47 ) ;
}
static unsigned long F_30 ( struct V_64 * V_65 ,
unsigned long V_66 )
{
struct V_5 * V_6 = F_31 ( V_65 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_67 = ( V_6 -> V_45 & V_46 ) ?
V_39 : V_68 ;
int V_59 = F_4 ( V_4 , V_67 ) ;
unsigned long V_47 = V_69 ;
if ( V_59 < 0 )
return 0 ;
V_59 >>= 4 ;
if ( V_59 == 0 )
V_47 = 0 ;
else if ( V_59 > 1 )
V_47 = V_47 / ( 1 << V_59 ) ;
return V_47 ;
}
static long F_32 ( struct V_64 * V_65 , unsigned long V_70 ,
unsigned long * V_71 )
{
int V_72 , V_73 = V_69 ;
if ( V_73 <= V_70 )
return V_73 ;
for ( V_72 = 2 ; V_72 <= F_33 ( V_69 ) ; V_72 ++ ) {
V_73 /= 1 << V_72 ;
if ( V_73 <= V_70 )
return V_73 ;
}
return 0 ;
}
static int F_34 ( struct V_64 * V_65 , unsigned long V_70 ,
unsigned long V_66 )
{
struct V_5 * V_6 = F_31 ( V_65 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_67 = ( V_6 -> V_45 & V_46 ) ?
V_39 : V_68 ;
int V_51 , V_59 , V_47 = 0 ;
if ( V_70 ) {
if ( ! F_35 ( V_70 ) )
return - V_27 ;
V_47 = F_33 ( V_70 ) ;
if ( V_47 == F_33 ( V_69 ) )
V_47 = 1 ;
else if ( V_47 < ( F_33 ( V_69 ) - 1 ) )
V_47 = F_33 ( V_69 ) - V_47 ;
else
return - V_27 ;
}
V_51 = F_4 ( V_4 , V_67 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = ( V_51 & 0x0f ) | ( V_47 << 4 ) ;
V_59 = F_7 ( V_4 , V_67 , V_51 ) ;
if ( V_59 < 0 )
return V_59 ;
return - V_27 ;
}
static int F_36 ( struct V_64 * V_65 , bool V_74 )
{
struct V_5 * V_6 = F_31 ( V_65 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_74 )
V_59 |= V_60 ;
else
V_59 &= ~ V_60 ;
return F_7 ( V_4 , V_14 , V_59 ) ;
}
static int F_37 ( struct V_64 * V_65 )
{
return F_36 ( V_65 , 1 ) ;
}
static void F_38 ( struct V_64 * V_65 )
{
F_36 ( V_65 , 0 ) ;
}
static int F_39 ( struct V_64 * V_65 )
{
struct V_5 * V_6 = F_31 ( V_65 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return V_59 ;
return ! ! ( V_59 & V_60 ) ;
}
static struct V_75 * F_40 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_76 * V_77 = V_4 -> V_26 . V_78 ;
struct V_75 * V_75 ;
struct V_79 V_80 ;
int V_59 ;
V_59 = F_4 ( V_4 , V_14 ) ;
if ( V_59 < 0 )
return F_41 ( V_59 ) ;
V_59 = F_7 ( V_4 , V_14 ,
V_59 & ~ ( V_60 ) ) ;
if ( V_59 < 0 )
return F_41 ( V_59 ) ;
V_80 . V_81 = L_12 ;
V_80 . V_82 = & V_83 ;
V_80 . V_12 = 0 ;
V_80 . V_84 = NULL ;
V_80 . V_85 = 0 ;
V_6 -> V_86 . V_80 = & V_80 ;
F_42 ( V_77 , L_13 , & V_80 . V_81 ) ;
V_75 = F_43 ( & V_4 -> V_26 , & V_6 -> V_86 ) ;
if ( ! F_44 ( V_75 ) )
F_45 ( V_77 , V_87 , V_75 ) ;
return V_75 ;
}
static void F_46 ( void )
{
unsigned char V_88 [ 2 ] ;
struct V_89 V_90 [ 1 ] = {
{
. V_91 = V_92 -> V_91 ,
. V_12 = 0 ,
. V_93 = 2 ,
. V_23 = V_88 ,
} ,
} ;
struct V_5 * V_44 = F_2 ( V_92 ) ;
V_88 [ 0 ] = 0x09 ;
if ( V_94 > 31 )
V_88 [ 1 ] = ( V_94 & 0xFC ) | 0x83 ;
else
V_88 [ 1 ] = V_94 << 2 | 0x82 ;
if ( V_44 -> V_45 & V_95 )
V_88 [ 1 ] &= ~ V_96 ;
F_47 ( V_92 -> V_97 , V_90 , 1 ) ;
}
static void F_48 ( void )
{
unsigned char V_88 [ 2 ] , V_98 [ 0x10 ] ;
struct V_89 V_99 [ 2 ] = {
{
. V_91 = V_92 -> V_91 ,
. V_12 = 0 ,
. V_93 = 1 ,
. V_23 = V_88 ,
} ,
{
. V_91 = V_92 -> V_91 ,
. V_12 = V_100 ,
. V_93 = 1 ,
. V_23 = V_98 ,
} ,
} ;
struct V_89 V_90 [ 1 ] = {
{
. V_91 = V_92 -> V_91 ,
. V_12 = 0 ,
. V_93 = 2 ,
. V_23 = V_88 ,
} ,
} ;
V_88 [ 0 ] = 0x09 ;
F_47 ( V_92 -> V_97 , V_99 , 2 ) ;
V_88 [ 0 ] = 0x09 ;
V_88 [ 1 ] = 0x00 ;
F_47 ( V_92 -> V_97 , V_90 , 1 ) ;
}
static T_3 F_49 ( struct V_101 * V_101 , const char T_4 * V_23 ,
T_5 V_102 , T_6 * V_103 )
{
if ( V_102 ) {
F_46 () ;
return 1 ;
}
return 0 ;
}
static T_3 F_50 ( struct V_101 * V_101 , char T_4 * V_23 ,
T_5 V_102 , T_6 * V_103 )
{
return 0 ;
}
static int F_51 ( struct V_101 * V_101 , unsigned int V_104 ,
unsigned long V_105 )
{
int V_106 , V_107 ;
static struct V_108 V_109 = {
. V_110 = V_111 | V_112 |
V_113 ,
. V_114 = 1 ,
. V_115 = L_14
} ;
switch ( V_104 ) {
case V_116 :
return F_52 ( (struct V_108 T_4 * ) V_105 , & V_109 ,
sizeof( V_109 ) ) ? - V_117 : 0 ;
case V_118 :
case V_119 :
return F_53 ( V_120 , ( int T_4 * ) V_105 ) ;
case V_121 :
F_46 () ;
return 0 ;
case V_122 :
if ( F_54 ( V_106 , ( int T_4 * ) V_105 ) )
return - V_117 ;
if ( V_106 < 1 || V_106 > 124 )
return - V_27 ;
V_94 = V_106 ;
F_46 () ;
case V_123 :
return F_53 ( V_94 , ( int T_4 * ) V_105 ) ;
case V_124 :
if ( F_55 ( & V_107 , ( int T_4 * ) V_105 , sizeof( int ) ) )
return - V_117 ;
if ( V_107 & V_125 ) {
F_56 ( L_15 ) ;
F_48 () ;
}
if ( V_107 & V_126 ) {
F_56 ( L_16 ) ;
F_46 () ;
}
return - V_27 ;
}
return - V_127 ;
}
static long F_57 ( struct V_101 * V_101 , unsigned int V_104 ,
unsigned long V_105 )
{
int V_59 ;
F_3 ( & V_128 ) ;
V_59 = F_51 ( V_101 , V_104 , V_105 ) ;
F_5 ( & V_128 ) ;
return V_59 ;
}
static int F_58 ( struct V_129 * V_129 , struct V_101 * V_101 )
{
if ( F_59 ( V_129 -> V_130 ) == V_131 ) {
F_3 ( & V_128 ) ;
if ( F_60 ( 0 , & V_132 ) ) {
F_5 ( & V_128 ) ;
return - V_133 ;
}
V_132 = 1 ;
F_5 ( & V_128 ) ;
return F_61 ( V_129 , V_101 ) ;
}
return - V_134 ;
}
static int F_62 ( struct V_129 * V_129 , struct V_101 * V_101 )
{
if ( F_59 ( V_129 -> V_130 ) == V_131 )
F_63 ( 0 , & V_132 ) ;
return 0 ;
}
static int F_64 ( struct V_135 * V_136 , unsigned long V_137 ,
void * V_138 )
{
if ( V_137 == V_139 || V_137 == V_140 )
F_48 () ;
return V_141 ;
}
static void F_65 ( void * V_142 )
{
struct V_48 * V_26 = V_142 ;
F_66 ( & V_26 -> V_143 , & V_144 ) ;
}
static int F_67 ( struct V_3 * V_4 ,
const struct V_145 * V_146 )
{
struct V_147 * V_97 = F_68 ( V_4 -> V_26 . V_148 ) ;
int V_149 = 0 ;
struct V_150 * V_9 = NULL ;
struct V_21 V_22 ;
struct V_5 * V_5 = NULL ;
if ( ! F_69 ( V_4 -> V_97 , V_151 |
V_152 ) ) {
F_9 ( & V_97 -> V_26 , L_17 ) ;
return - V_134 ;
}
V_5 = F_70 ( & V_4 -> V_26 , sizeof( * V_5 ) ,
V_153 ) ;
if ( ! V_5 )
return - V_154 ;
V_5 -> V_4 = V_4 ;
if ( V_4 -> V_26 . V_78 )
V_5 -> V_45 = ( unsigned long )
F_71 ( & V_4 -> V_26 ) ;
else
V_5 -> V_45 = V_146 -> V_155 ;
F_72 ( V_4 , V_5 ) ;
if ( V_4 -> V_1 > 0 ) {
V_149 = F_73 ( & V_4 -> V_26 , V_4 -> V_1 ,
NULL , F_1 ,
V_156 | V_157 ,
L_18 , V_4 ) ;
if ( V_149 ) {
F_74 ( & V_4 -> V_26 , L_19 ) ;
V_4 -> V_1 = 0 ;
} else {
V_158 . V_159 = F_23 ;
V_158 . V_160 = F_22 ;
V_158 . V_161 = F_21 ;
F_75 ( & V_4 -> V_26 , true ) ;
}
}
V_9 = F_76 ( & V_4 -> V_26 , V_4 -> V_81 ,
& V_158 , V_162 ) ;
if ( F_44 ( V_9 ) )
return F_77 ( V_9 ) ;
V_5 -> V_9 = V_9 ;
V_149 = F_4 ( V_4 , V_163 ) ;
if ( V_149 >= 0 && V_149 & V_164 ) {
if ( V_5 -> V_45 & V_165 ) {
F_8 ( V_4 , & V_22 ) ;
F_78 ( & V_4 -> V_26 , L_20 ) ;
F_78 ( & V_4 -> V_26 ,
L_21 ,
V_22 . V_42 + 1900 ,
V_22 . V_40 + 1 , V_22 . V_36 , V_22 . V_34 ,
V_22 . V_32 , V_22 . V_30 ) ;
}
V_149 = F_7 ( V_4 , V_163 ,
V_149 & ~ V_164 ) ;
}
if ( V_149 < 0 ) {
F_9 ( & V_4 -> V_26 , L_22 ) ;
return V_149 ;
}
V_149 = F_4 ( V_4 , V_31 ) ;
if ( V_149 >= 0 && V_149 & V_166 )
V_149 = F_7 ( V_4 , V_31 ,
V_149 & ~ V_166 ) ;
if ( V_149 < 0 ) {
F_9 ( & V_4 -> V_26 , L_23 ) ;
return V_149 ;
}
V_149 = F_79 ( & ( & V_4 -> V_26 ) -> V_143 , & V_144 ) ;
if ( V_149 ) {
F_9 ( & V_4 -> V_26 , L_24 , V_149 ) ;
return V_149 ;
}
V_149 = F_80 ( & V_4 -> V_26 , F_65 ,
& V_4 -> V_26 ) ;
if ( V_149 ) {
F_9 ( & V_4 -> V_26 ,
L_25 , V_149 ) ;
return V_149 ;
}
#ifdef F_81
if ( V_5 -> V_45 & V_165 ) {
V_92 = V_4 ;
V_149 = F_82 ( & V_167 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_83 ( & V_168 ) ;
if ( V_149 ) {
F_84 ( & V_167 ) ;
return V_149 ;
}
}
#endif
#ifdef F_85
if ( V_5 -> V_45 & V_169 )
F_40 ( V_5 ) ;
#endif
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
#ifdef F_81
struct V_5 * V_44 = F_2 ( V_4 ) ;
if ( V_44 -> V_45 & V_165 ) {
F_84 ( & V_167 ) ;
F_87 ( & V_168 ) ;
}
#endif
return 0 ;
}
