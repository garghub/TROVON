static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( F_2 ( V_2 ) )
return;
if ( ! V_4 || ! V_4 -> V_7 || ! V_4 -> V_8 )
return;
#ifdef F_3
if ( V_4 -> V_9 . type == V_10 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
if ( V_2 -> V_14 == V_15 )
return;
if ( V_5 )
F_4 ( V_12 -> V_16 , V_12 -> V_6 ) ;
else
F_5 ( V_12 -> V_16 , V_12 -> V_6 ) ;
return;
}
#endif
V_6 = ( V_4 -> V_8 + V_17 - 1 ) >> V_18 ;
if ( V_5 )
F_6 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
else
F_7 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_19 ,
bool V_5 )
{
F_1 ( V_2 , V_19 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_20 ,
struct V_21 * V_22 , bool V_5 )
{
if ( V_20 -> V_23 != V_5 ) {
F_1 ( V_2 , F_10 ( V_22 ) , V_5 ) ;
V_20 -> V_23 = V_5 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_19 ,
bool V_5 )
{
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_20 ,
struct V_21 * V_22 , bool V_5 )
{
}
static void F_11 ( struct V_24 * V_25 , unsigned int V_26 ,
unsigned char V_27 , unsigned char V_28 )
{
unsigned char V_29 ;
F_12 ( V_25 , V_26 , & V_29 ) ;
V_29 &= ~ V_27 ;
V_29 |= ( V_28 & V_27 ) ;
F_13 ( V_25 , V_26 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_30 = F_15 ( V_2 ) ;
if ( ! ( V_2 -> V_31 & V_32 ) ) {
F_16 ( V_2 -> V_33 -> V_9 , L_1 ) ;
F_11 ( V_2 -> V_25 , V_34 , 0x07 , 0 ) ;
}
if ( V_30 == V_35 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_2 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_36 , 0x07 ,
F_2 ( V_2 ) ? V_37 : 0 ) ;
}
if ( V_30 == V_38 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_3 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_39 ,
0x0f , V_40 ) ;
F_11 ( V_2 -> V_25 ,
V_41 ,
0x01 , V_42 ) ;
F_11 ( V_2 -> V_25 ,
V_43 ,
0x01 , V_42 ) ;
}
if ( V_30 == V_44 ) {
unsigned short V_45 ;
F_17 ( V_2 -> V_25 , V_46 , & V_45 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_45 & V_47 ) ) ||
( F_2 ( V_2 ) && ( V_45 & V_47 ) ) ) {
V_45 &= ~ V_47 ;
if ( ! F_2 ( V_2 ) )
V_45 |= V_47 ;
F_18 ( V_2 -> V_25 , V_46 , V_45 ) ;
F_17 ( V_2 -> V_25 ,
V_46 , & V_45 ) ;
}
F_16 ( V_2 -> V_33 -> V_9 , L_4 ,
( V_45 & V_47 ) ?
L_5 : L_6 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_48 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_49 = V_22 -> V_49 ;
unsigned int V_50 = F_20 ( V_2 , V_20 ) ;
int V_51 ;
if ( V_49 == V_52 )
V_51 = V_48 - V_50 ;
else
V_51 = V_50 - V_48 ;
if ( V_51 < 0 ) {
if ( V_51 >= V_20 -> V_53 )
V_51 = 0 ;
else
V_51 += V_20 -> V_54 ;
}
if ( V_51 >= V_20 -> V_55 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_7 ,
V_51 , V_20 -> V_55 ) ;
V_51 = 0 ;
V_2 -> V_31 &= ~ V_56 ;
V_2 -> V_57 [ V_49 ] = NULL ;
}
return F_22 ( V_22 -> V_58 , V_51 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_61 ;
V_61 = F_25 ( V_2 , V_20 ) ;
if ( V_61 == 1 ) {
V_20 -> V_62 = 0 ;
return V_61 ;
} else if ( V_61 == 0 && V_2 -> V_63 && V_2 -> V_63 -> V_64 ) {
V_20 -> V_62 = 1 ;
F_26 ( V_2 -> V_63 -> V_64 , & V_60 -> V_65 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_49 = V_22 -> V_49 ;
T_1 V_66 ;
unsigned int V_48 ;
V_66 = F_27 ( V_2 , V_67 ) - V_20 -> V_68 ;
if ( V_66 < ( V_20 -> V_69 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_70 [ V_49 ] )
V_48 = V_2 -> V_70 [ V_49 ] ( V_2 , V_20 ) ;
else {
V_48 = F_28 ( V_2 , V_20 ) ;
if ( ! V_48 || V_48 == ( T_1 ) - 1 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_8 ) ;
V_2 -> V_70 [ V_49 ] = F_20 ;
V_48 = F_20 ( V_2 , V_20 ) ;
V_2 -> V_57 [ V_49 ] = NULL ;
} else {
V_2 -> V_70 [ V_49 ] = F_28 ;
if ( V_2 -> V_31 & V_56 )
V_2 -> V_57 [ V_49 ] = F_19 ;
}
}
if ( V_48 >= V_20 -> V_54 )
V_48 = 0 ;
if ( F_29 ( ! V_20 -> V_55 ,
L_9 ) )
return - 1 ;
if ( V_66 < ( V_20 -> V_69 * 5 ) / 4 &&
V_48 % V_20 -> V_55 > V_20 -> V_55 / 2 )
return V_2 -> V_71 [ V_2 -> V_72 ] ? 0 : - 1 ;
V_20 -> V_68 += V_66 ;
return 1 ;
}
static void F_30 ( struct V_73 * V_74 )
{
struct V_59 * V_60 = F_24 ( V_74 , struct V_59 , V_65 ) ;
struct V_1 * V_2 = & V_60 -> V_2 ;
int V_75 , V_76 , V_61 ;
if ( ! V_60 -> V_77 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_10 ,
V_2 -> V_33 -> V_78 ) ;
V_60 -> V_77 = 1 ;
}
for (; ; ) {
V_76 = 0 ;
F_31 ( & V_2 -> V_79 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 ; V_75 ++ ) {
struct V_20 * V_20 = & V_2 -> V_20 [ V_75 ] ;
if ( ! V_20 -> V_62 ||
! V_20 -> V_22 ||
! V_20 -> V_81 )
continue;
V_61 = F_25 ( V_2 , V_20 ) ;
if ( V_61 > 0 ) {
V_20 -> V_62 = 0 ;
F_32 ( & V_2 -> V_79 ) ;
F_33 ( V_20 -> V_22 ) ;
F_34 ( & V_2 -> V_79 ) ;
} else if ( V_61 < 0 ) {
V_76 = 0 ;
} else
V_76 ++ ;
}
F_35 ( & V_2 -> V_79 ) ;
if ( ! V_76 )
return;
F_36 ( 1 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
int V_75 ;
F_31 ( & V_2 -> V_79 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 ; V_75 ++ )
V_2 -> V_20 [ V_75 ] . V_62 = 0 ;
F_35 ( & V_2 -> V_79 ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_82 )
{
if ( F_39 ( V_2 -> V_25 -> V_83 , V_84 ,
V_2 -> V_85 ? 0 : V_86 ,
V_87 , V_2 ) ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_83 ) ;
if ( V_82 )
F_41 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_2 -> V_83 = V_2 -> V_25 -> V_83 ;
F_42 ( V_2 -> V_25 , ! V_2 -> V_85 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_88 , V_89 , V_90 ;
unsigned int V_91 , V_92 , V_93 ;
unsigned int V_94 ;
V_88 = F_44 ( V_2 , V_20 , V_95 ) ;
if ( V_20 -> V_22 -> V_49 == V_52 ) {
return V_88 ;
}
V_92 = F_45 ( * V_20 -> V_96 ) ;
V_92 %= V_20 -> V_55 ;
V_94 = F_46 ( V_2 -> V_97 + V_98 ) ;
if ( V_20 -> V_99 ) {
if ( V_88 <= V_94 )
return 0 ;
V_20 -> V_99 = 0 ;
}
if ( V_88 <= V_94 )
V_89 = V_20 -> V_54 + V_88 - V_94 ;
else
V_89 = V_88 - V_94 ;
V_93 = V_89 % V_20 -> V_55 ;
V_91 = V_88 % V_20 -> V_55 ;
if ( V_91 >= V_94 )
V_90 = V_88 - V_91 ;
else if ( V_92 >= V_93 )
V_90 = V_89 - V_93 ;
else {
V_90 = V_89 - V_93 + V_20 -> V_55 ;
if ( V_90 >= V_20 -> V_54 )
V_90 = 0 ;
}
return V_90 + V_92 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_48 ( & V_100 ) ;
F_49 ( & V_60 -> V_101 , & V_102 ) ;
F_50 ( & V_100 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_48 ( & V_100 ) ;
F_52 ( & V_60 -> V_101 ) ;
F_50 ( & V_100 ) ;
}
static int F_53 ( const char * V_28 , const struct V_103 * V_104 )
{
struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
int V_107 = V_108 ;
int V_109 = F_54 ( V_28 , V_104 ) ;
if ( V_109 || V_107 == V_108 )
return V_109 ;
F_48 ( & V_100 ) ;
F_55 (hda, &card_list, list) {
V_2 = & V_60 -> V_2 ;
if ( ! V_2 -> V_63 || V_2 -> V_110 )
continue;
F_55 (c, &chip->bus->codec_list, list)
F_56 ( V_106 ) ;
}
F_50 ( & V_100 ) ;
return 0 ;
}
static int F_57 ( struct V_111 * V_9 )
{
struct V_24 * V_25 = F_58 ( V_9 ) ;
struct V_112 * V_33 = F_59 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_113 * V_114 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
F_60 ( V_33 , V_116 ) ;
F_37 ( V_2 ) ;
F_55 (p, &chip->pcm_list, list)
F_61 ( V_114 -> V_117 ) ;
if ( V_2 -> V_118 )
F_62 ( V_2 -> V_63 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
if ( V_2 -> V_83 >= 0 ) {
F_65 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
}
if ( V_2 -> V_85 )
F_66 ( V_2 -> V_25 ) ;
F_67 ( V_25 ) ;
F_68 ( V_25 ) ;
F_69 ( V_25 , V_119 ) ;
if ( V_2 -> V_31 & V_120 )
F_70 ( false ) ;
return 0 ;
}
static int F_71 ( struct V_111 * V_9 )
{
struct V_24 * V_25 = F_58 ( V_9 ) ;
struct V_112 * V_33 = F_59 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( V_2 -> V_31 & V_120 ) {
F_70 ( true ) ;
F_72 ( V_2 ) ;
}
F_69 ( V_25 , V_121 ) ;
F_73 ( V_25 ) ;
if ( F_74 ( V_25 ) < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
F_41 ( V_33 ) ;
return - V_122 ;
}
F_75 ( V_25 ) ;
if ( V_2 -> V_85 )
if ( F_76 ( V_25 ) < 0 )
V_2 -> V_85 = 0 ;
if ( F_38 ( V_2 , 1 ) < 0 )
return - V_122 ;
F_14 ( V_2 ) ;
F_77 ( V_2 , true ) ;
F_78 ( V_2 -> V_63 ) ;
F_60 ( V_33 , V_123 ) ;
return 0 ;
}
static int F_79 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_59 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! ( V_2 -> V_31 & V_124 ) )
return 0 ;
F_80 ( V_2 , V_125 , F_81 ( V_2 , V_125 ) |
V_126 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_31 & V_120 )
F_70 ( false ) ;
return 0 ;
}
static int F_82 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_59 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_127 * V_63 ;
struct V_105 * V_128 ;
int V_129 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! ( V_2 -> V_31 & V_124 ) )
return 0 ;
if ( V_2 -> V_31 & V_120 ) {
F_70 ( true ) ;
F_72 ( V_2 ) ;
}
V_129 = F_81 ( V_2 , V_130 ) ;
F_14 ( V_2 ) ;
F_77 ( V_2 , true ) ;
V_63 = V_2 -> V_63 ;
if ( V_129 && V_63 ) {
F_55 (codec, &bus->codec_list, list)
if ( V_129 & ( 1 << V_128 -> V_131 ) )
F_83 ( V_128 -> V_63 -> V_64 ,
& V_128 -> V_132 , V_128 -> V_133 ) ;
}
F_80 ( V_2 , V_125 , F_81 ( V_2 , V_125 ) &
~ V_126 ) ;
return 0 ;
}
static int F_84 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_59 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! V_134 ||
! ( V_2 -> V_31 & V_124 ) )
return - V_135 ;
return 0 ;
}
static void F_85 ( struct V_24 * V_25 ,
enum V_136 V_137 )
{
struct V_112 * V_33 = F_86 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
bool V_110 ;
F_87 ( & V_60 -> V_138 ) ;
if ( V_60 -> V_115 )
return;
V_110 = ( V_137 == V_139 ) ;
if ( V_2 -> V_110 == V_110 )
return;
if ( ! V_2 -> V_63 ) {
V_2 -> V_110 = V_110 ;
if ( ! V_110 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_13 ) ;
if ( F_88 ( V_2 ) < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 , L_14 ) ;
V_60 -> V_115 = true ;
}
}
} else {
F_21 ( V_2 -> V_33 -> V_9 , L_15 ,
V_110 ? L_16 : L_17 ) ;
if ( V_110 ) {
F_89 ( V_33 -> V_9 ) ;
F_57 ( V_33 -> V_9 ) ;
V_25 -> V_140 = V_141 ;
V_2 -> V_110 = true ;
if ( F_90 ( V_2 -> V_63 ) )
F_91 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
} else {
F_92 ( V_2 -> V_63 ) ;
F_93 ( V_33 -> V_9 ) ;
V_2 -> V_110 = false ;
F_71 ( V_33 -> V_9 ) ;
}
}
}
static bool F_94 ( struct V_24 * V_25 )
{
struct V_112 * V_33 = F_86 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_87 ( & V_60 -> V_138 ) ;
if ( V_60 -> V_115 )
return false ;
if ( V_2 -> V_110 || ! V_2 -> V_63 )
return true ;
if ( F_90 ( V_2 -> V_63 ) )
return false ;
F_92 ( V_2 -> V_63 ) ;
return true ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_114 = F_96 ( V_2 -> V_25 ) ;
if ( V_114 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_19 ) ;
V_60 -> V_142 = 1 ;
F_97 ( V_114 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_143 ;
if ( ! V_60 -> V_142 )
return 0 ;
V_143 = F_99 ( V_2 -> V_25 , & V_144 ,
V_145 ,
V_2 -> V_63 != NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_60 -> V_146 = 1 ;
F_100 ( V_2 -> V_33 -> V_9 ,
& V_60 -> V_147 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_75 ;
if ( ( V_2 -> V_31 & V_124 )
&& V_2 -> V_81 )
F_93 ( & V_25 -> V_9 ) ;
F_51 ( V_2 ) ;
F_102 ( V_2 ) ;
V_60 -> V_115 = 1 ;
F_103 ( & V_60 -> V_138 ) ;
if ( V_142 ( V_60 ) ) {
if ( V_2 -> V_110 && V_2 -> V_63 )
F_92 ( V_2 -> V_63 ) ;
if ( V_60 -> V_146 )
F_104 ( V_2 -> V_25 ) ;
}
if ( V_2 -> V_118 ) {
F_37 ( V_2 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 ; V_75 ++ )
F_105 ( V_2 , & V_2 -> V_20 [ V_75 ] ) ;
F_63 ( V_2 ) ;
}
if ( V_2 -> V_83 >= 0 )
F_65 ( V_2 -> V_83 , ( void * ) V_2 ) ;
if ( V_2 -> V_85 )
F_66 ( V_2 -> V_25 ) ;
if ( V_2 -> V_97 )
F_106 ( V_2 -> V_97 ) ;
F_107 ( V_2 ) ;
if ( V_2 -> V_148 )
F_108 ( V_2 -> V_25 ) ;
F_67 ( V_2 -> V_25 ) ;
F_109 ( V_2 -> V_20 ) ;
#ifdef F_110
F_111 ( V_2 -> V_149 ) ;
#endif
if ( V_2 -> V_31 & V_120 ) {
F_70 ( false ) ;
F_112 () ;
}
F_109 ( V_60 ) ;
return 0 ;
}
static int F_113 ( struct V_150 * V_111 )
{
return F_101 ( V_111 -> V_151 ) ;
}
static struct V_24 * F_96 ( struct V_24 * V_25 )
{
struct V_24 * V_114 ;
switch ( V_25 -> V_152 ) {
case V_153 :
case V_154 :
case V_155 :
if ( V_25 -> V_156 == 1 ) {
V_114 = F_114 ( F_115 ( V_25 -> V_63 ) ,
V_25 -> V_63 -> V_78 , 0 ) ;
if ( V_114 ) {
if ( ( V_114 -> V_157 >> 8 ) == V_158 )
return V_114 ;
F_97 ( V_114 ) ;
}
}
break;
}
return NULL ;
}
static bool F_116 ( struct V_24 * V_25 )
{
bool V_159 = false ;
struct V_24 * V_114 = F_96 ( V_25 ) ;
if ( V_114 ) {
if ( F_117 ( V_114 ) == V_139 )
V_159 = true ;
F_97 ( V_114 ) ;
}
return V_159 ;
}
static int F_118 ( struct V_1 * V_2 , int V_160 )
{
const struct V_161 * V_162 ;
switch ( V_160 ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
return V_160 ;
}
V_162 = F_119 ( V_2 -> V_25 , V_168 ) ;
if ( V_162 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_20 ,
V_162 -> V_169 , V_162 -> V_170 , V_162 -> V_171 ) ;
return V_162 -> V_169 ;
}
if ( V_2 -> V_31 & V_172 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_166 ;
}
if ( V_2 -> V_31 & V_173 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_22 ) ;
return V_164 ;
}
return V_163 ;
}
static void F_120 ( struct V_1 * V_2 , int V_160 )
{
static T_2 V_174 [] = {
[ V_163 ] = NULL ,
[ V_164 ] = F_20 ,
[ V_165 ] = F_28 ,
[ V_166 ] = F_43 ,
[ V_167 ] = F_20 ,
} ;
V_2 -> V_70 [ 0 ] = V_2 -> V_70 [ 1 ] = V_174 [ V_160 ] ;
if ( V_160 == V_167 )
V_2 -> V_70 [ 1 ] = NULL ;
if ( V_160 == V_165 &&
( V_2 -> V_31 & V_56 ) ) {
V_2 -> V_57 [ 0 ] = V_2 -> V_57 [ 1 ] =
F_19 ;
}
}
static void F_121 ( struct V_1 * V_2 , int V_9 )
{
const struct V_161 * V_162 ;
V_2 -> V_175 = V_176 [ V_9 ] ;
if ( V_2 -> V_175 == - 1 ) {
V_162 = F_119 ( V_2 -> V_25 , V_177 ) ;
if ( V_162 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_23 ,
V_162 -> V_169 , V_162 -> V_170 , V_162 -> V_171 ) ;
V_2 -> V_175 = V_162 -> V_169 ;
}
}
if ( V_2 -> V_175 != - 1 &&
( V_2 -> V_175 & V_178 ) ) {
V_2 -> V_179 = V_2 -> V_175 & 0xff ;
F_21 ( V_2 -> V_33 -> V_9 , L_24 ,
V_2 -> V_179 ) ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
const struct V_161 * V_162 ;
if ( V_180 >= 0 ) {
V_2 -> V_85 = ! ! V_180 ;
return;
}
V_2 -> V_85 = 1 ;
V_162 = F_119 ( V_2 -> V_25 , V_181 ) ;
if ( V_162 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_25 ,
V_162 -> V_170 , V_162 -> V_171 , V_162 -> V_169 ) ;
V_2 -> V_85 = V_162 -> V_169 ;
return;
}
if ( V_2 -> V_31 & V_182 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_26 ) ;
V_2 -> V_85 = 0 ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
int V_45 = V_183 ;
if ( V_45 >= 0 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_27 ,
V_45 ? L_28 : L_29 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_184 &&
V_2 -> V_14 == V_185 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_186 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_187 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_21 ( V_2 -> V_33 -> V_9 , L_30 ) ;
}
static void F_124 ( struct V_73 * V_74 )
{
struct V_59 * V_60 = F_24 ( V_74 , struct V_59 , V_188 ) ;
F_88 ( & V_60 -> V_2 ) ;
}
static int F_125 ( struct V_112 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
const struct V_189 * V_190 ,
struct V_1 * * V_191 )
{
static struct V_192 V_193 = {
. V_194 = F_113 ,
} ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
int V_143 ;
* V_191 = NULL ;
V_143 = F_74 ( V_25 ) ;
if ( V_143 < 0 )
return V_143 ;
V_60 = F_126 ( sizeof( * V_60 ) , V_195 ) ;
if ( ! V_60 ) {
F_40 ( V_33 -> V_9 , L_31 ) ;
F_67 ( V_25 ) ;
return - V_196 ;
}
V_2 = & V_60 -> V_2 ;
F_127 ( & V_2 -> V_79 ) ;
F_128 ( & V_2 -> V_197 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_193 = V_190 ;
V_2 -> V_83 = - 1 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_122 ( V_2 ) ;
V_2 -> V_72 = V_9 ;
V_2 -> V_198 = V_198 ;
F_129 ( & V_2 -> V_199 ) ;
F_130 ( & V_60 -> V_65 , F_30 ) ;
F_129 ( & V_60 -> V_101 ) ;
F_95 ( V_2 ) ;
F_131 ( & V_60 -> V_138 ) ;
F_120 ( V_2 , F_118 ( V_2 , V_200 [ V_9 ] ) ) ;
F_121 ( V_2 , V_9 ) ;
V_2 -> V_201 = V_201 ;
F_123 ( V_2 ) ;
if ( V_71 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_202 :
case V_203 :
V_71 [ V_9 ] = 1 ;
break;
default:
V_71 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_71 = V_71 ;
V_143 = F_132 ( V_33 , V_204 , V_2 , & V_193 ) ;
if ( V_143 < 0 ) {
F_40 ( V_33 -> V_9 , L_32 ) ;
F_101 ( V_2 ) ;
return V_143 ;
}
F_130 ( & V_60 -> V_188 , F_124 ) ;
* V_191 = V_2 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_72 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_112 * V_33 = V_2 -> V_33 ;
int V_143 ;
unsigned short V_205 ;
unsigned int V_206 = 64 ;
#if V_207 != 64
if ( V_2 -> V_14 == V_208 ) {
T_4 V_209 ;
F_17 ( V_25 , 0x40 , & V_209 ) ;
F_18 ( V_25 , 0x40 , V_209 | 0x10 ) ;
F_134 ( V_25 , V_210 , 0 ) ;
}
#endif
V_143 = F_135 ( V_25 , L_33 ) ;
if ( V_143 < 0 )
return V_143 ;
V_2 -> V_148 = 1 ;
V_2 -> V_131 = F_136 ( V_25 , 0 ) ;
V_2 -> V_97 = F_137 ( V_25 , 0 ) ;
if ( V_2 -> V_97 == NULL ) {
F_40 ( V_33 -> V_9 , L_34 ) ;
return - V_211 ;
}
if ( V_2 -> V_85 ) {
if ( V_2 -> V_31 & V_212 ) {
F_16 ( V_33 -> V_9 , L_35 ) ;
V_25 -> V_213 = true ;
}
if ( F_76 ( V_25 ) < 0 )
V_2 -> V_85 = 0 ;
}
if ( F_38 ( V_2 , 0 ) < 0 )
return - V_135 ;
F_75 ( V_25 ) ;
F_138 ( V_2 -> V_83 ) ;
V_205 = F_81 ( V_2 , V_214 ) ;
F_16 ( V_33 -> V_9 , L_36 , V_205 ) ;
if ( V_2 -> V_25 -> V_152 == V_154 )
V_206 = 40 ;
if ( V_2 -> V_25 -> V_152 == V_153 ) {
struct V_24 * V_215 ;
V_206 = 40 ;
V_215 = F_139 ( V_153 ,
V_216 ,
NULL ) ;
if ( V_215 ) {
if ( V_215 -> V_186 < 0x30 )
V_205 &= ~ V_217 ;
F_97 ( V_215 ) ;
}
}
if ( V_2 -> V_31 & V_218 ) {
F_16 ( V_33 -> V_9 , L_37 ) ;
V_205 &= ~ V_217 ;
}
if ( V_219 >= 0 )
V_2 -> V_219 = ! ! V_219 ;
else {
if ( V_2 -> V_31 & V_220 )
V_2 -> V_219 = 0 ;
else
V_2 -> V_219 = 1 ;
}
if ( ! ( V_205 & V_217 ) )
V_206 = 32 ;
if ( ! F_140 ( V_25 , F_141 ( V_206 ) ) ) {
F_142 ( V_25 , F_141 ( V_206 ) ) ;
} else {
F_140 ( V_25 , F_141 ( 32 ) ) ;
F_142 ( V_25 , F_141 ( 32 ) ) ;
}
V_2 -> V_221 = ( V_205 >> 8 ) & 0x0f ;
V_2 -> V_222 = ( V_205 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_222 && ! V_2 -> V_221 ) {
switch ( V_2 -> V_14 ) {
case V_208 :
V_2 -> V_222 = V_223 ;
V_2 -> V_221 = V_224 ;
break;
case V_225 :
case V_226 :
V_2 -> V_222 = V_227 ;
V_2 -> V_221 = V_228 ;
break;
case V_229 :
default:
V_2 -> V_222 = V_230 ;
V_2 -> V_221 = V_231 ;
break;
}
}
V_2 -> V_232 = 0 ;
V_2 -> V_233 = V_2 -> V_221 ;
V_2 -> V_80 = V_2 -> V_222 + V_2 -> V_221 ;
V_2 -> V_20 = F_143 ( V_2 -> V_80 , sizeof( * V_2 -> V_20 ) ,
V_195 ) ;
if ( ! V_2 -> V_20 ) {
F_40 ( V_33 -> V_9 , L_38 ) ;
return - V_196 ;
}
V_143 = F_144 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
F_145 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_120 )
F_72 ( V_2 ) ;
F_77 ( V_2 , ( V_234 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_179 ) {
F_40 ( V_33 -> V_9 , L_39 ) ;
return - V_235 ;
}
strcpy ( V_33 -> V_236 , L_40 ) ;
F_146 ( V_33 -> V_237 , V_238 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_237 ) ) ;
snprintf ( V_33 -> V_239 , sizeof( V_33 -> V_239 ) ,
L_41 ,
V_33 -> V_237 , V_2 -> V_131 , V_2 -> V_83 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
#ifdef F_148
struct V_105 * V_128 ;
F_55 (codec, &chip->bus->codec_list, list) {
F_149 ( V_128 ) ;
}
#endif
}
static void F_150 ( const struct V_240 * V_149 , void * V_241 )
{
struct V_112 * V_33 = V_241 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_149 ) {
F_40 ( V_33 -> V_9 , L_42 ) ;
goto error;
}
V_2 -> V_149 = V_149 ;
if ( ! V_2 -> V_110 ) {
if ( F_88 ( V_2 ) )
goto error;
}
return;
error:
F_151 ( V_33 ) ;
F_152 ( V_25 , NULL ) ;
}
static void F_153 ( T_1 V_169 , T_1 T_5 * V_131 )
{
F_154 ( V_169 , V_131 ) ;
}
static T_1 F_155 ( T_1 T_5 * V_131 )
{
return F_156 ( V_131 ) ;
}
static void F_157 ( T_4 V_169 , T_4 T_5 * V_131 )
{
F_158 ( V_169 , V_131 ) ;
}
static T_4 F_159 ( T_4 T_5 * V_131 )
{
return F_46 ( V_131 ) ;
}
static void F_160 ( T_3 V_169 , T_3 T_5 * V_131 )
{
F_161 ( V_169 , V_131 ) ;
}
static T_3 F_162 ( T_3 T_5 * V_131 )
{
return F_163 ( V_131 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
int V_143 ;
F_65 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
F_66 ( V_2 -> V_25 ) ;
V_2 -> V_85 = 0 ;
V_143 = F_38 ( V_2 , 1 ) ;
if ( V_143 < 0 )
return V_143 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 ,
int type ,
T_6 V_242 ,
struct V_3 * V_19 )
{
int V_143 ;
V_143 = F_166 ( type ,
V_2 -> V_33 -> V_9 ,
V_242 , V_19 ) ;
if ( V_143 < 0 )
return V_143 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 , struct V_3 * V_19 )
{
F_8 ( V_2 , V_19 , false ) ;
F_168 ( V_19 ) ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_242 )
{
struct V_20 * V_20 = F_170 ( V_22 ) ;
int V_109 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_20 -> V_54 = 0 ;
V_20 -> V_55 = 0 ;
V_20 -> V_243 = 0 ;
V_109 = F_171 ( V_22 , V_242 ) ;
if ( V_109 < 0 )
return V_109 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_170 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_173 ( V_22 ) ;
}
static void F_174 ( struct V_21 * V_22 ,
struct V_244 * V_7 )
{
#ifdef F_175
struct V_113 * V_245 = F_176 ( V_22 ) ;
struct V_1 * V_2 = V_245 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_246 = F_177 ( V_7 -> V_246 ) ;
#endif
}
static int F_178 ( struct V_24 * V_25 ,
const struct V_247 * V_248 )
{
static int V_9 ;
struct V_112 * V_33 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
bool V_249 ;
int V_143 ;
if ( V_9 >= V_250 )
return - V_235 ;
if ( ! V_251 [ V_9 ] ) {
V_9 ++ ;
return - V_252 ;
}
V_143 = F_179 ( & V_25 -> V_9 , V_253 [ V_9 ] , V_254 [ V_9 ] , V_255 ,
0 , & V_33 ) ;
if ( V_143 < 0 ) {
F_40 ( & V_25 -> V_9 , L_43 ) ;
return V_143 ;
}
V_143 = F_125 ( V_33 , V_25 , V_9 , V_248 -> V_256 ,
& V_257 , & V_2 ) ;
if ( V_143 < 0 )
goto V_258;
V_33 -> V_13 = V_2 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_152 ( V_25 , V_33 ) ;
V_143 = F_98 ( V_2 ) ;
if ( V_143 < 0 ) {
F_40 ( V_33 -> V_9 , L_44 ) ;
goto V_258;
}
if ( F_116 ( V_25 ) ) {
F_21 ( V_33 -> V_9 , L_45 ) ;
F_21 ( V_33 -> V_9 , L_46 ) ;
V_2 -> V_110 = true ;
}
V_249 = ! V_2 -> V_110 ;
#ifdef F_110
if ( V_259 [ V_9 ] && * V_259 [ V_9 ] ) {
F_21 ( V_33 -> V_9 , L_47 ,
V_259 [ V_9 ] ) ;
V_143 = F_180 ( V_255 , true , V_259 [ V_9 ] ,
& V_25 -> V_9 , V_195 , V_33 ,
F_150 ) ;
if ( V_143 < 0 )
goto V_258;
V_249 = false ;
}
#endif
#ifndef F_181
if ( V_2 -> V_31 & V_120 )
F_40 ( V_33 -> V_9 , L_48 ) ;
#endif
if ( V_249 )
F_182 ( & V_60 -> V_188 ) ;
V_9 ++ ;
if ( V_2 -> V_110 )
F_103 ( & V_60 -> V_138 ) ;
return 0 ;
V_258:
F_151 ( V_33 ) ;
return V_143 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_72 ;
int V_143 ;
if ( V_2 -> V_31 & V_120 ) {
#ifdef F_181
V_143 = F_183 () ;
if ( V_143 < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_49 ) ;
goto V_258;
}
V_143 = F_70 ( true ) ;
if ( V_143 < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_50 ) ;
goto V_258;
}
#endif
}
V_143 = F_133 ( V_2 ) ;
if ( V_143 < 0 )
goto V_258;
#ifdef F_184
V_2 -> V_260 = V_260 [ V_9 ] ;
#endif
V_143 = F_185 ( V_2 , V_261 [ V_9 ] ,
V_262 [ V_2 -> V_14 ] ,
V_263 ) ;
if ( V_143 < 0 )
goto V_258;
#ifdef F_110
if ( V_2 -> V_149 ) {
V_143 = F_186 ( V_2 -> V_63 , V_2 -> V_149 -> V_242 ,
V_2 -> V_149 -> V_29 ) ;
if ( V_143 < 0 )
goto V_258;
#ifndef F_148
F_111 ( V_2 -> V_149 ) ;
V_2 -> V_149 = NULL ;
#endif
}
#endif
if ( ( V_234 [ V_9 ] & 1 ) == 0 ) {
V_143 = F_187 ( V_2 ) ;
if ( V_143 < 0 )
goto V_258;
}
V_143 = F_188 ( V_2 -> V_63 ) ;
if ( V_143 < 0 )
goto V_258;
V_143 = F_189 ( V_2 ) ;
if ( V_143 < 0 )
goto V_258;
V_143 = F_190 ( V_2 -> V_33 ) ;
if ( V_143 < 0 )
goto V_258;
V_2 -> V_81 = 1 ;
F_147 ( V_2 ) ;
F_191 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ( V_2 -> V_31 & V_124 ) || V_60 -> V_142 )
F_192 ( & V_25 -> V_9 ) ;
V_258:
if ( V_143 < 0 )
V_60 -> V_115 = 1 ;
F_103 ( & V_60 -> V_138 ) ;
return V_143 ;
}
static void F_193 ( struct V_24 * V_25 )
{
struct V_112 * V_33 = F_86 ( V_25 ) ;
if ( V_33 )
F_151 ( V_33 ) ;
}
