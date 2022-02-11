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
struct V_112 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_113 * V_114 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
F_59 ( V_33 , V_116 ) ;
F_37 ( V_2 ) ;
F_55 (p, &chip->pcm_list, list)
F_60 ( V_114 -> V_117 ) ;
if ( V_2 -> V_118 )
F_61 ( V_2 -> V_63 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_83 >= 0 ) {
F_64 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
}
if ( V_2 -> V_85 )
F_65 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_119 )
F_66 ( V_60 , false ) ;
return 0 ;
}
static int F_67 ( struct V_111 * V_9 )
{
struct V_24 * V_25 = F_68 ( V_9 ) ;
struct V_112 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( V_2 -> V_31 & V_119 ) {
F_66 ( V_60 , true ) ;
F_69 ( V_60 ) ;
}
if ( V_2 -> V_85 )
if ( F_70 ( V_25 ) < 0 )
V_2 -> V_85 = 0 ;
if ( F_38 ( V_2 , 1 ) < 0 )
return - V_120 ;
F_14 ( V_2 ) ;
F_71 ( V_2 , true ) ;
F_72 ( V_2 -> V_63 ) ;
F_59 ( V_33 , V_121 ) ;
return 0 ;
}
static int F_73 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! ( V_2 -> V_31 & V_122 ) )
return 0 ;
F_74 ( V_2 , V_123 , F_75 ( V_2 , V_123 ) |
V_124 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_31 & V_119 )
F_66 ( V_60 , false ) ;
return 0 ;
}
static int F_76 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_125 * V_63 ;
struct V_105 * V_126 ;
int V_127 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! ( V_2 -> V_31 & V_122 ) )
return 0 ;
if ( V_2 -> V_31 & V_119 ) {
F_66 ( V_60 , true ) ;
F_69 ( V_60 ) ;
}
V_127 = F_75 ( V_2 , V_128 ) ;
F_14 ( V_2 ) ;
F_71 ( V_2 , true ) ;
V_63 = V_2 -> V_63 ;
if ( V_127 && V_63 ) {
F_55 (codec, &bus->codec_list, list)
if ( V_127 & ( 1 << V_126 -> V_129 ) )
F_77 ( V_126 -> V_63 -> V_64 ,
& V_126 -> V_130 , V_126 -> V_131 ) ;
}
F_74 ( V_2 , V_123 , F_75 ( V_2 , V_123 ) &
~ V_124 ) ;
return 0 ;
}
static int F_78 ( struct V_111 * V_9 )
{
struct V_112 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_110 || V_60 -> V_115 )
return 0 ;
if ( ! V_132 ||
! ( V_2 -> V_31 & V_122 ) )
return - V_133 ;
return 0 ;
}
static void F_79 ( struct V_24 * V_25 ,
enum V_134 V_135 )
{
struct V_112 * V_33 = F_80 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
bool V_110 ;
F_81 ( & V_60 -> V_136 ) ;
if ( V_60 -> V_115 )
return;
V_110 = ( V_135 == V_137 ) ;
if ( V_2 -> V_110 == V_110 )
return;
if ( ! V_2 -> V_63 ) {
V_2 -> V_110 = V_110 ;
if ( ! V_110 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_82 ( V_2 ) < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_60 -> V_115 = true ;
}
}
} else {
F_21 ( V_2 -> V_33 -> V_9 , L_14 ,
V_110 ? L_15 : L_16 ) ;
if ( V_110 ) {
F_83 ( V_33 -> V_9 ) ;
F_57 ( V_33 -> V_9 ) ;
V_25 -> V_138 = V_139 ;
V_2 -> V_110 = true ;
if ( F_84 ( V_2 -> V_63 ) )
F_85 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_86 ( V_2 -> V_63 ) ;
F_87 ( V_33 -> V_9 ) ;
V_2 -> V_110 = false ;
F_67 ( V_33 -> V_9 ) ;
}
}
}
static bool F_88 ( struct V_24 * V_25 )
{
struct V_112 * V_33 = F_80 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_81 ( & V_60 -> V_136 ) ;
if ( V_60 -> V_115 )
return false ;
if ( V_2 -> V_110 || ! V_2 -> V_63 )
return true ;
if ( F_84 ( V_2 -> V_63 ) )
return false ;
F_86 ( V_2 -> V_63 ) ;
return true ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_114 = F_90 ( V_2 -> V_25 ) ;
if ( V_114 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_60 -> V_140 = 1 ;
F_91 ( V_114 ) ;
}
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_141 ;
if ( ! V_60 -> V_140 )
return 0 ;
V_141 = F_93 ( V_2 -> V_25 , & V_142 ,
V_143 ,
V_2 -> V_63 != NULL ) ;
if ( V_141 < 0 )
return V_141 ;
V_60 -> V_144 = 1 ;
F_94 ( V_2 -> V_33 -> V_9 ,
& V_60 -> V_145 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_75 ;
if ( ( V_2 -> V_31 & V_122 )
&& V_2 -> V_81 )
F_87 ( & V_25 -> V_9 ) ;
F_51 ( V_2 ) ;
F_96 ( V_2 ) ;
V_60 -> V_115 = 1 ;
F_97 ( & V_60 -> V_136 ) ;
if ( V_140 ( V_60 ) ) {
if ( V_2 -> V_110 && V_2 -> V_63 )
F_86 ( V_2 -> V_63 ) ;
if ( V_60 -> V_144 )
F_98 ( V_2 -> V_25 ) ;
}
if ( V_2 -> V_118 ) {
F_37 ( V_2 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 ; V_75 ++ )
F_99 ( V_2 , & V_2 -> V_20 [ V_75 ] ) ;
F_62 ( V_2 ) ;
}
if ( V_2 -> V_83 >= 0 )
F_64 ( V_2 -> V_83 , ( void * ) V_2 ) ;
if ( V_2 -> V_85 )
F_65 ( V_2 -> V_25 ) ;
F_100 ( V_2 -> V_97 ) ;
F_101 ( V_2 ) ;
if ( V_2 -> V_146 )
F_102 ( V_2 -> V_25 ) ;
F_103 ( V_2 -> V_25 ) ;
F_104 ( V_2 -> V_20 ) ;
#ifdef F_105
F_106 ( V_2 -> V_147 ) ;
#endif
if ( V_2 -> V_31 & V_119 ) {
F_66 ( V_60 , false ) ;
F_107 ( V_60 ) ;
}
F_104 ( V_60 ) ;
return 0 ;
}
static int F_108 ( struct V_148 * V_111 )
{
return F_95 ( V_111 -> V_149 ) ;
}
static struct V_24 * F_90 ( struct V_24 * V_25 )
{
struct V_24 * V_114 ;
switch ( V_25 -> V_150 ) {
case V_151 :
case V_152 :
case V_153 :
if ( V_25 -> V_154 == 1 ) {
V_114 = F_109 ( F_110 ( V_25 -> V_63 ) ,
V_25 -> V_63 -> V_78 , 0 ) ;
if ( V_114 ) {
if ( ( V_114 -> V_155 >> 8 ) == V_156 )
return V_114 ;
F_91 ( V_114 ) ;
}
}
break;
}
return NULL ;
}
static bool F_111 ( struct V_24 * V_25 )
{
bool V_157 = false ;
struct V_24 * V_114 = F_90 ( V_25 ) ;
if ( V_114 ) {
if ( F_112 ( V_114 ) == V_137 )
V_157 = true ;
F_91 ( V_114 ) ;
}
return V_157 ;
}
static int F_113 ( struct V_1 * V_2 , int V_158 )
{
const struct V_159 * V_160 ;
switch ( V_158 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
return V_158 ;
}
V_160 = F_114 ( V_2 -> V_25 , V_166 ) ;
if ( V_160 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_160 -> V_167 , V_160 -> V_168 , V_160 -> V_169 ) ;
return V_160 -> V_167 ;
}
if ( V_2 -> V_31 & V_170 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_164 ;
}
if ( V_2 -> V_31 & V_171 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_162 ;
}
return V_161 ;
}
static void F_115 ( struct V_1 * V_2 , int V_158 )
{
static T_2 V_172 [] = {
[ V_161 ] = NULL ,
[ V_162 ] = F_20 ,
[ V_163 ] = F_28 ,
[ V_164 ] = F_43 ,
[ V_165 ] = F_20 ,
} ;
V_2 -> V_70 [ 0 ] = V_2 -> V_70 [ 1 ] = V_172 [ V_158 ] ;
if ( V_158 == V_165 )
V_2 -> V_70 [ 1 ] = NULL ;
if ( V_158 == V_163 &&
( V_2 -> V_31 & V_56 ) ) {
V_2 -> V_57 [ 0 ] = V_2 -> V_57 [ 1 ] =
F_19 ;
}
}
static void F_116 ( struct V_1 * V_2 , int V_9 )
{
const struct V_159 * V_160 ;
V_2 -> V_173 = V_174 [ V_9 ] ;
if ( V_2 -> V_173 == - 1 ) {
V_160 = F_114 ( V_2 -> V_25 , V_175 ) ;
if ( V_160 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_160 -> V_167 , V_160 -> V_168 , V_160 -> V_169 ) ;
V_2 -> V_173 = V_160 -> V_167 ;
}
}
if ( V_2 -> V_173 != - 1 &&
( V_2 -> V_173 & V_176 ) ) {
V_2 -> V_177 = V_2 -> V_173 & 0xff ;
F_21 ( V_2 -> V_33 -> V_9 , L_23 ,
V_2 -> V_177 ) ;
}
}
static void F_117 ( struct V_1 * V_2 )
{
const struct V_159 * V_160 ;
if ( V_178 >= 0 ) {
V_2 -> V_85 = ! ! V_178 ;
return;
}
V_2 -> V_85 = 1 ;
V_160 = F_114 ( V_2 -> V_25 , V_179 ) ;
if ( V_160 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_160 -> V_168 , V_160 -> V_169 , V_160 -> V_167 ) ;
V_2 -> V_85 = V_160 -> V_167 ;
return;
}
if ( V_2 -> V_31 & V_180 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_85 = 0 ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
int V_45 = V_181 ;
if ( V_45 >= 0 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_182 &&
V_2 -> V_14 == V_183 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_184 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_185 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_21 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_119 ( struct V_73 * V_74 )
{
struct V_59 * V_60 = F_24 ( V_74 , struct V_59 , V_186 ) ;
F_82 ( & V_60 -> V_2 ) ;
}
static int F_120 ( struct V_112 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
const struct V_187 * V_188 ,
struct V_1 * * V_189 )
{
static struct V_190 V_191 = {
. V_192 = F_108 ,
} ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
int V_141 ;
* V_189 = NULL ;
V_141 = F_121 ( V_25 ) ;
if ( V_141 < 0 )
return V_141 ;
V_60 = F_122 ( sizeof( * V_60 ) , V_193 ) ;
if ( ! V_60 ) {
F_40 ( V_33 -> V_9 , L_30 ) ;
F_103 ( V_25 ) ;
return - V_194 ;
}
V_2 = & V_60 -> V_2 ;
F_123 ( & V_2 -> V_79 ) ;
F_124 ( & V_2 -> V_195 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_191 = V_188 ;
V_2 -> V_83 = - 1 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_117 ( V_2 ) ;
V_2 -> V_72 = V_9 ;
V_2 -> V_196 = V_196 ;
F_125 ( & V_2 -> V_197 ) ;
F_126 ( & V_60 -> V_65 , F_30 ) ;
F_125 ( & V_60 -> V_101 ) ;
F_89 ( V_2 ) ;
F_127 ( & V_60 -> V_136 ) ;
F_115 ( V_2 , F_113 ( V_2 , V_198 [ V_9 ] ) ) ;
F_116 ( V_2 , V_9 ) ;
V_2 -> V_199 = V_199 ;
F_118 ( V_2 ) ;
if ( V_71 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_200 :
case V_201 :
V_71 [ V_9 ] = 1 ;
break;
default:
V_71 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_71 = V_71 ;
V_141 = F_128 ( V_33 , V_202 , V_2 , & V_191 ) ;
if ( V_141 < 0 ) {
F_40 ( V_33 -> V_9 , L_31 ) ;
F_95 ( V_2 ) ;
return V_141 ;
}
F_126 ( & V_60 -> V_186 , F_119 ) ;
* V_189 = V_2 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_72 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_112 * V_33 = V_2 -> V_33 ;
int V_141 ;
unsigned short V_203 ;
unsigned int V_204 = 64 ;
#if V_205 != 64
if ( V_2 -> V_14 == V_206 ) {
T_4 V_207 ;
F_17 ( V_25 , 0x40 , & V_207 ) ;
F_18 ( V_25 , 0x40 , V_207 | 0x10 ) ;
F_130 ( V_25 , V_208 , 0 ) ;
}
#endif
V_141 = F_131 ( V_25 , L_32 ) ;
if ( V_141 < 0 )
return V_141 ;
V_2 -> V_146 = 1 ;
V_2 -> V_129 = F_132 ( V_25 , 0 ) ;
V_2 -> V_97 = F_133 ( V_25 , 0 ) ;
if ( V_2 -> V_97 == NULL ) {
F_40 ( V_33 -> V_9 , L_33 ) ;
return - V_209 ;
}
if ( V_2 -> V_85 ) {
if ( V_2 -> V_31 & V_210 ) {
F_16 ( V_33 -> V_9 , L_34 ) ;
V_25 -> V_211 = true ;
}
if ( F_70 ( V_25 ) < 0 )
V_2 -> V_85 = 0 ;
}
if ( F_38 ( V_2 , 0 ) < 0 )
return - V_133 ;
F_134 ( V_25 ) ;
F_135 ( V_2 -> V_83 ) ;
V_203 = F_75 ( V_2 , V_212 ) ;
F_16 ( V_33 -> V_9 , L_35 , V_203 ) ;
if ( V_2 -> V_25 -> V_150 == V_152 )
V_204 = 40 ;
if ( V_2 -> V_25 -> V_150 == V_151 ) {
struct V_24 * V_213 ;
V_204 = 40 ;
V_213 = F_136 ( V_151 ,
V_214 ,
NULL ) ;
if ( V_213 ) {
if ( V_213 -> V_184 < 0x30 )
V_203 &= ~ V_215 ;
F_91 ( V_213 ) ;
}
}
if ( V_2 -> V_31 & V_216 ) {
F_16 ( V_33 -> V_9 , L_36 ) ;
V_203 &= ~ V_215 ;
}
if ( V_217 >= 0 )
V_2 -> V_217 = ! ! V_217 ;
else {
if ( V_2 -> V_31 & V_218 )
V_2 -> V_217 = 0 ;
else
V_2 -> V_217 = 1 ;
}
if ( ! ( V_203 & V_215 ) )
V_204 = 32 ;
if ( ! F_137 ( V_25 , F_138 ( V_204 ) ) ) {
F_139 ( V_25 , F_138 ( V_204 ) ) ;
} else {
F_137 ( V_25 , F_138 ( 32 ) ) ;
F_139 ( V_25 , F_138 ( 32 ) ) ;
}
V_2 -> V_219 = ( V_203 >> 8 ) & 0x0f ;
V_2 -> V_220 = ( V_203 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_220 && ! V_2 -> V_219 ) {
switch ( V_2 -> V_14 ) {
case V_206 :
V_2 -> V_220 = V_221 ;
V_2 -> V_219 = V_222 ;
break;
case V_223 :
case V_224 :
V_2 -> V_220 = V_225 ;
V_2 -> V_219 = V_226 ;
break;
case V_227 :
default:
V_2 -> V_220 = V_228 ;
V_2 -> V_219 = V_229 ;
break;
}
}
V_2 -> V_230 = 0 ;
V_2 -> V_231 = V_2 -> V_219 ;
V_2 -> V_80 = V_2 -> V_220 + V_2 -> V_219 ;
V_2 -> V_20 = F_140 ( V_2 -> V_80 , sizeof( * V_2 -> V_20 ) ,
V_193 ) ;
if ( ! V_2 -> V_20 ) {
F_40 ( V_33 -> V_9 , L_37 ) ;
return - V_194 ;
}
V_141 = F_141 ( V_2 ) ;
if ( V_141 < 0 )
return V_141 ;
F_142 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_119 ) {
struct V_59 * V_60 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_69 ( V_60 ) ;
}
F_71 ( V_2 , ( V_232 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_177 ) {
F_40 ( V_33 -> V_9 , L_38 ) ;
return - V_233 ;
}
strcpy ( V_33 -> V_234 , L_39 ) ;
F_143 ( V_33 -> V_235 , V_236 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_235 ) ) ;
snprintf ( V_33 -> V_237 , sizeof( V_33 -> V_237 ) ,
L_40 ,
V_33 -> V_235 , V_2 -> V_129 , V_2 -> V_83 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
#ifdef F_145
struct V_105 * V_126 ;
F_55 (codec, &chip->bus->codec_list, list) {
F_146 ( V_126 ) ;
}
#endif
}
static void F_147 ( const struct V_238 * V_147 , void * V_239 )
{
struct V_112 * V_33 = V_239 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_147 ) {
F_40 ( V_33 -> V_9 , L_41 ) ;
goto error;
}
V_2 -> V_147 = V_147 ;
if ( ! V_2 -> V_110 ) {
if ( F_82 ( V_2 ) )
goto error;
}
return;
error:
F_148 ( V_33 ) ;
F_149 ( V_25 , NULL ) ;
}
static void F_150 ( T_1 V_167 , T_1 T_5 * V_129 )
{
F_151 ( V_167 , V_129 ) ;
}
static T_1 F_152 ( T_1 T_5 * V_129 )
{
return F_153 ( V_129 ) ;
}
static void F_154 ( T_4 V_167 , T_4 T_5 * V_129 )
{
F_155 ( V_167 , V_129 ) ;
}
static T_4 F_156 ( T_4 T_5 * V_129 )
{
return F_46 ( V_129 ) ;
}
static void F_157 ( T_3 V_167 , T_3 T_5 * V_129 )
{
F_158 ( V_167 , V_129 ) ;
}
static T_3 F_159 ( T_3 T_5 * V_129 )
{
return F_160 ( V_129 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_141 ;
F_64 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
F_65 ( V_2 -> V_25 ) ;
V_2 -> V_85 = 0 ;
V_141 = F_38 ( V_2 , 1 ) ;
if ( V_141 < 0 )
return V_141 ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
int type ,
T_6 V_240 ,
struct V_3 * V_19 )
{
int V_141 ;
V_141 = F_163 ( type ,
V_2 -> V_33 -> V_9 ,
V_240 , V_19 ) ;
if ( V_141 < 0 )
return V_141 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_164 ( struct V_1 * V_2 , struct V_3 * V_19 )
{
F_8 ( V_2 , V_19 , false ) ;
F_165 ( V_19 ) ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_240 )
{
struct V_20 * V_20 = F_167 ( V_22 ) ;
int V_109 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_20 -> V_54 = 0 ;
V_20 -> V_55 = 0 ;
V_20 -> V_241 = 0 ;
V_109 = F_168 ( V_22 , V_240 ) ;
if ( V_109 < 0 )
return V_109 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_167 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_170 ( V_22 ) ;
}
static void F_171 ( struct V_21 * V_22 ,
struct V_242 * V_7 )
{
#ifdef F_172
struct V_113 * V_243 = F_173 ( V_22 ) ;
struct V_1 * V_2 = V_243 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_244 = F_174 ( V_7 -> V_244 ) ;
#endif
}
static int F_175 ( struct V_24 * V_25 ,
const struct V_245 * V_246 )
{
static int V_9 ;
struct V_112 * V_33 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
bool V_247 ;
int V_141 ;
if ( V_9 >= V_248 )
return - V_233 ;
if ( ! V_249 [ V_9 ] ) {
V_9 ++ ;
return - V_250 ;
}
V_141 = F_176 ( & V_25 -> V_9 , V_251 [ V_9 ] , V_252 [ V_9 ] , V_253 ,
0 , & V_33 ) ;
if ( V_141 < 0 ) {
F_40 ( & V_25 -> V_9 , L_42 ) ;
return V_141 ;
}
V_141 = F_120 ( V_33 , V_25 , V_9 , V_246 -> V_254 ,
& V_255 , & V_2 ) ;
if ( V_141 < 0 )
goto V_256;
V_33 -> V_13 = V_2 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_149 ( V_25 , V_33 ) ;
V_141 = F_92 ( V_2 ) ;
if ( V_141 < 0 ) {
F_40 ( V_33 -> V_9 , L_43 ) ;
goto V_256;
}
if ( F_111 ( V_25 ) ) {
F_21 ( V_33 -> V_9 , L_44 ) ;
F_21 ( V_33 -> V_9 , L_45 ) ;
V_2 -> V_110 = true ;
}
V_247 = ! V_2 -> V_110 ;
#ifdef F_105
if ( V_257 [ V_9 ] && * V_257 [ V_9 ] ) {
F_21 ( V_33 -> V_9 , L_46 ,
V_257 [ V_9 ] ) ;
V_141 = F_177 ( V_253 , true , V_257 [ V_9 ] ,
& V_25 -> V_9 , V_193 , V_33 ,
F_147 ) ;
if ( V_141 < 0 )
goto V_256;
V_247 = false ;
}
#endif
#ifndef F_178
if ( V_2 -> V_31 & V_119 )
F_40 ( V_33 -> V_9 , L_47 ) ;
#endif
if ( V_247 )
F_179 ( & V_60 -> V_186 ) ;
V_9 ++ ;
if ( V_2 -> V_110 )
F_97 ( & V_60 -> V_136 ) ;
return 0 ;
V_256:
F_148 ( V_33 ) ;
return V_141 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_72 ;
int V_141 ;
if ( V_2 -> V_31 & V_119 ) {
#ifdef F_178
V_141 = F_180 ( V_60 ) ;
if ( V_141 < 0 )
goto V_256;
V_141 = F_66 ( V_60 , true ) ;
if ( V_141 < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_48 ) ;
goto V_256;
}
#endif
}
V_141 = F_129 ( V_2 ) ;
if ( V_141 < 0 )
goto V_256;
#ifdef F_181
V_2 -> V_258 = V_258 [ V_9 ] ;
#endif
V_141 = F_182 ( V_2 , V_259 [ V_9 ] ,
V_260 [ V_2 -> V_14 ] ,
V_261 ) ;
if ( V_141 < 0 )
goto V_256;
#ifdef F_105
if ( V_2 -> V_147 ) {
V_141 = F_183 ( V_2 -> V_63 , V_2 -> V_147 -> V_240 ,
V_2 -> V_147 -> V_29 ) ;
if ( V_141 < 0 )
goto V_256;
#ifndef F_145
F_106 ( V_2 -> V_147 ) ;
V_2 -> V_147 = NULL ;
#endif
}
#endif
if ( ( V_232 [ V_9 ] & 1 ) == 0 ) {
V_141 = F_184 ( V_2 ) ;
if ( V_141 < 0 )
goto V_256;
}
V_141 = F_185 ( V_2 -> V_63 ) ;
if ( V_141 < 0 )
goto V_256;
V_141 = F_186 ( V_2 ) ;
if ( V_141 < 0 )
goto V_256;
V_141 = F_187 ( V_2 -> V_33 ) ;
if ( V_141 < 0 )
goto V_256;
V_2 -> V_81 = 1 ;
F_144 ( V_2 ) ;
F_188 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ( V_2 -> V_31 & V_122 ) || V_60 -> V_140 )
F_189 ( & V_25 -> V_9 ) ;
V_256:
if ( V_141 < 0 )
V_60 -> V_115 = 1 ;
F_97 ( & V_60 -> V_136 ) ;
return V_141 ;
}
static void F_190 ( struct V_24 * V_25 )
{
struct V_112 * V_33 = F_80 ( V_25 ) ;
if ( V_33 )
F_148 ( V_33 ) ;
}
