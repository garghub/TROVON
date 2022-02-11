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
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_20 ( V_2 , V_48 ) ;
V_28 &= ( 0x3 << 20 ) ;
F_21 ( V_2 , V_48 , V_28 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
static int V_51 [] = { 2 , 3 , 1 , 4 , 5 } ;
T_1 V_28 , V_52 ;
int V_53 ;
V_28 = F_24 ( V_50 -> V_54 + V_55 + V_56 ) ;
for ( V_53 = 0 ; V_53 < F_25 ( V_51 ) ; V_53 ++ ) {
V_52 = V_51 [ V_53 ] ;
if ( V_28 & ( 1 << V_52 ) )
return V_52 ;
}
F_26 ( V_2 -> V_33 -> V_9 , L_7 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_57 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
T_1 V_28 ;
int V_58 ;
V_28 = F_24 ( V_50 -> V_54 + V_55 + V_59 ) ;
V_28 &= ~ V_60 ;
V_28 |= V_57 << V_61 ;
F_28 ( V_28 , V_50 -> V_54 + V_55 + V_59 ) ;
V_58 = 50 ;
while ( V_58 ) {
if ( ( ( F_24 ( V_50 -> V_54 + V_55 + V_59 ) ) &
V_62 ) == ( V_57 << V_63 ) )
return 0 ;
V_58 -- ;
F_29 ( 10 ) ;
}
return - 1 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
T_1 V_28 ;
int V_64 ;
V_28 = F_24 ( V_50 -> V_54 + V_55 + V_59 ) ;
if ( ( V_28 & V_65 ) != 0 )
return;
if ( ( ( V_28 & V_60 ) >> V_61 ) !=
( ( V_28 & V_62 ) >> V_63 ) )
return;
V_64 = F_27 ( V_2 , 0 ) ;
F_29 ( 100 ) ;
if ( V_64 )
goto V_66;
V_28 &= ~ V_65 ;
V_28 |= F_22 ( V_2 ) ;
F_28 ( V_28 , V_50 -> V_54 + V_55 + V_59 ) ;
V_66:
F_27 ( V_2 , 1 ) ;
F_29 ( 100 ) ;
}
static void F_31 ( struct V_1 * V_2 , bool V_67 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
T_1 V_28 ;
if ( V_2 -> V_31 & V_68 )
F_32 ( V_50 , true ) ;
if ( V_2 -> V_14 == V_69 ) {
F_33 ( V_25 , V_70 , & V_28 ) ;
V_28 = V_28 & ~ V_71 ;
F_34 ( V_25 , V_70 , V_28 ) ;
}
F_35 ( V_2 , V_67 ) ;
if ( V_2 -> V_14 == V_69 ) {
F_33 ( V_25 , V_70 , & V_28 ) ;
V_28 = V_28 | V_71 ;
F_34 ( V_25 , V_70 , V_28 ) ;
}
if ( V_2 -> V_31 & V_68 )
F_32 ( V_50 , false ) ;
if ( F_36 ( V_25 ) )
F_19 ( V_2 ) ;
if ( V_50 -> V_54 != NULL )
F_30 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_72 )
{
struct V_21 * V_22 = V_20 -> V_73 . V_22 ;
int V_74 = V_22 -> V_74 ;
unsigned int V_75 = F_38 ( V_2 , V_20 ) ;
int V_76 ;
if ( V_74 == V_77 )
V_76 = V_72 - V_75 ;
else
V_76 = V_75 - V_72 ;
if ( V_76 < 0 ) {
if ( V_76 >= V_20 -> V_73 . V_78 )
V_76 = 0 ;
else
V_76 += V_20 -> V_73 . V_79 ;
}
if ( V_76 >= V_20 -> V_73 . V_80 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_8 ,
V_76 , V_20 -> V_73 . V_80 ) ;
V_76 = 0 ;
V_2 -> V_31 &= ~ V_81 ;
V_2 -> V_82 [ V_74 ] = NULL ;
}
return F_40 ( V_22 -> V_83 , V_76 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
int V_86 ;
V_86 = F_43 ( V_2 , V_20 ) ;
if ( V_86 == 1 ) {
V_20 -> V_87 = 0 ;
return V_86 ;
} else if ( V_86 == 0 ) {
V_20 -> V_87 = 1 ;
F_44 ( & V_85 -> V_88 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_89 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
return F_46 ( V_50 , V_89 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_73 . V_22 ;
int V_74 = V_22 -> V_74 ;
T_1 V_90 ;
unsigned int V_72 ;
V_90 = F_20 ( V_2 , V_91 ) - V_20 -> V_73 . V_92 ;
if ( V_90 < ( V_20 -> V_73 . V_93 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_94 [ V_74 ] )
V_72 = V_2 -> V_94 [ V_74 ] ( V_2 , V_20 ) ;
else {
V_72 = F_47 ( V_2 , V_20 ) ;
if ( ! V_72 || V_72 == ( T_1 ) - 1 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_9 ) ;
V_2 -> V_94 [ V_74 ] = F_38 ;
if ( V_2 -> V_94 [ 0 ] == F_38 &&
V_2 -> V_94 [ 1 ] == F_38 )
F_23 ( V_2 ) -> V_95 = false ;
V_72 = F_38 ( V_2 , V_20 ) ;
V_2 -> V_82 [ V_74 ] = NULL ;
} else {
V_2 -> V_94 [ V_74 ] = F_47 ;
if ( V_2 -> V_31 & V_81 )
V_2 -> V_82 [ V_74 ] = F_37 ;
}
}
if ( V_72 >= V_20 -> V_73 . V_79 )
V_72 = 0 ;
if ( F_48 ( ! V_20 -> V_73 . V_80 ,
L_10 ) )
return - 1 ;
if ( V_90 < ( V_20 -> V_73 . V_93 * 5 ) / 4 &&
V_72 % V_20 -> V_73 . V_80 > V_20 -> V_73 . V_80 / 2 )
return V_2 -> V_96 ? 0 : - 1 ;
V_20 -> V_73 . V_92 += V_90 ;
return 1 ;
}
static void F_49 ( struct V_97 * V_98 )
{
struct V_84 * V_85 = F_42 ( V_98 , struct V_84 , V_88 ) ;
struct V_1 * V_2 = & V_85 -> V_2 ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_99 * V_100 ;
int V_101 , V_86 ;
if ( ! V_85 -> V_102 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_33 -> V_103 ) ;
V_85 -> V_102 = 1 ;
}
for (; ; ) {
V_101 = 0 ;
F_50 ( & V_50 -> V_104 ) ;
F_51 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_52 ( V_100 ) ;
if ( ! V_20 -> V_87 ||
! V_100 -> V_22 ||
! V_100 -> V_105 )
continue;
V_86 = F_43 ( V_2 , V_20 ) ;
if ( V_86 > 0 ) {
V_20 -> V_87 = 0 ;
F_53 ( & V_50 -> V_104 ) ;
F_54 ( V_100 -> V_22 ) ;
F_55 ( & V_50 -> V_104 ) ;
} else if ( V_86 < 0 ) {
V_101 = 0 ;
} else
V_101 ++ ;
}
F_56 ( & V_50 -> V_104 ) ;
if ( ! V_101 )
return;
F_57 ( 1 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_99 * V_100 ;
F_50 ( & V_50 -> V_104 ) ;
F_51 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_52 ( V_100 ) ;
V_20 -> V_87 = 0 ;
}
F_56 ( & V_50 -> V_104 ) ;
}
static int F_59 ( struct V_1 * V_2 , int V_106 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
if ( F_60 ( V_2 -> V_25 -> V_107 , V_108 ,
V_2 -> V_109 ? 0 : V_110 ,
V_2 -> V_33 -> V_111 , V_2 ) ) {
F_61 ( V_2 -> V_33 -> V_9 ,
L_12 ,
V_2 -> V_25 -> V_107 ) ;
if ( V_106 )
F_62 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_50 -> V_107 = V_2 -> V_25 -> V_107 ;
F_63 ( V_2 -> V_25 , ! V_2 -> V_109 ) ;
return 0 ;
}
static unsigned int F_64 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_112 , V_113 , V_114 ;
unsigned int V_115 , V_116 , V_117 ;
unsigned int V_118 ;
V_112 = F_65 ( F_66 ( V_20 ) ) ;
if ( V_20 -> V_73 . V_22 -> V_74 == V_77 ) {
return V_112 ;
}
V_116 = F_67 ( * V_20 -> V_73 . V_119 ) ;
V_116 %= V_20 -> V_73 . V_80 ;
V_118 = F_68 ( F_23 ( V_2 ) -> V_120 +
V_121 ) ;
if ( V_20 -> V_122 ) {
if ( V_112 <= V_118 )
return 0 ;
V_20 -> V_122 = 0 ;
}
if ( V_112 <= V_118 )
V_113 = V_20 -> V_73 . V_79 + V_112 - V_118 ;
else
V_113 = V_112 - V_118 ;
V_117 = V_113 % V_20 -> V_73 . V_80 ;
V_115 = V_112 % V_20 -> V_73 . V_80 ;
if ( V_115 >= V_118 )
V_114 = V_112 - V_115 ;
else if ( V_116 >= V_117 )
V_114 = V_113 - V_117 ;
else {
V_114 = V_113 - V_117 + V_20 -> V_73 . V_80 ;
if ( V_114 >= V_20 -> V_73 . V_79 )
V_114 = 0 ;
}
return V_114 + V_116 ;
}
static unsigned int F_69 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
return F_70 ( F_23 ( V_2 ) ,
V_123 +
( V_124 *
V_20 -> V_73 . V_125 ) ) ;
}
static unsigned int F_71 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
if ( V_20 -> V_73 . V_22 -> V_74 == V_77 )
return F_69 ( V_2 , V_20 ) ;
F_29 ( 20 ) ;
F_69 ( V_2 , V_20 ) ;
return F_47 ( V_2 , V_20 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
F_73 ( & V_126 ) ;
F_74 ( & V_85 -> V_127 , & V_128 ) ;
F_75 ( & V_126 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
F_73 ( & V_126 ) ;
F_77 ( & V_85 -> V_127 ) ;
F_75 ( & V_126 ) ;
}
static int F_78 ( const char * V_28 , const struct V_129 * V_130 )
{
struct V_84 * V_85 ;
struct V_1 * V_2 ;
int V_131 = V_132 ;
int V_64 = F_79 ( V_28 , V_130 ) ;
if ( V_64 || V_131 == V_132 )
return V_64 ;
F_73 ( & V_126 ) ;
F_51 (hda, &card_list, list) {
V_2 = & V_85 -> V_2 ;
if ( ! V_85 -> V_133 || V_2 -> V_134 )
continue;
F_80 ( & V_2 -> V_50 , V_132 * 1000 ) ;
}
F_75 ( & V_126 ) ;
return 0 ;
}
static int F_81 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_49 * V_50 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
if ( V_2 -> V_134 || V_85 -> V_137 || ! V_2 -> V_105 )
return 0 ;
V_50 = F_23 ( V_2 ) ;
F_83 ( V_33 , V_138 ) ;
F_58 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
if ( V_50 -> V_107 >= 0 ) {
F_86 ( V_50 -> V_107 , V_2 ) ;
V_50 -> V_107 = - 1 ;
}
if ( V_2 -> V_109 )
F_87 ( V_2 -> V_25 ) ;
if ( ( V_2 -> V_31 & V_68 )
&& V_85 -> V_139 )
F_46 ( V_50 , false ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_135 * V_9 )
{
struct V_24 * V_25 = F_90 ( V_9 ) ;
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_49 * V_50 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
V_50 = F_23 ( V_2 ) ;
if ( V_2 -> V_134 || V_85 -> V_137 || ! V_2 -> V_105 )
return 0 ;
if ( V_2 -> V_31 & V_68 ) {
F_46 ( V_50 , true ) ;
if ( V_85 -> V_139 )
F_91 ( V_50 ) ;
}
if ( V_2 -> V_109 )
if ( F_92 ( V_25 ) < 0 )
V_2 -> V_109 = 0 ;
if ( F_59 ( V_2 , 1 ) < 0 )
return - V_140 ;
F_14 ( V_2 ) ;
F_31 ( V_2 , true ) ;
if ( ( V_2 -> V_31 & V_68 ) &&
! V_85 -> V_139 )
F_46 ( V_50 , false ) ;
F_83 ( V_33 , V_141 ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = F_90 ( V_9 ) ;
if ( V_2 -> V_14 == V_69 )
F_95 ( V_25 , V_142 ) ;
return 0 ;
}
static int F_96 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = F_90 ( V_9 ) ;
if ( V_2 -> V_14 == V_69 )
F_95 ( V_25 , V_143 ) ;
return 0 ;
}
static int F_97 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
if ( V_2 -> V_134 || V_85 -> V_137 )
return 0 ;
if ( ! F_98 ( V_2 ) )
return 0 ;
F_99 ( V_2 , V_144 , F_100 ( V_2 , V_144 ) |
V_145 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( ( V_2 -> V_31 & V_68 )
&& V_85 -> V_139 )
F_46 ( F_23 ( V_2 ) , false ) ;
F_101 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_49 * V_50 ;
struct V_146 * V_147 ;
int V_148 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
V_50 = F_23 ( V_2 ) ;
if ( V_2 -> V_134 || V_85 -> V_137 )
return 0 ;
if ( ! F_98 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_68 ) {
F_46 ( V_50 , true ) ;
if ( V_85 -> V_139 )
F_91 ( V_50 ) ;
}
V_148 = F_100 ( V_2 , V_149 ) ;
F_14 ( V_2 ) ;
F_31 ( V_2 , true ) ;
if ( V_148 ) {
F_103 (codec, &chip->bus)
if ( V_148 & ( 1 << V_147 -> V_150 ) )
F_104 ( & V_147 -> V_151 ,
V_147 -> V_152 ) ;
}
F_99 ( V_2 , V_144 , F_100 ( V_2 , V_144 ) &
~ V_145 ) ;
if ( ( V_2 -> V_31 & V_68 ) &&
! V_85 -> V_139 )
F_46 ( V_50 , false ) ;
F_105 ( V_2 ) ;
return 0 ;
}
static int F_106 ( struct V_135 * V_9 )
{
struct V_136 * V_33 = F_82 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
if ( V_2 -> V_134 || V_85 -> V_137 )
return 0 ;
if ( ! V_153 || ! F_98 ( V_2 ) ||
F_23 ( V_2 ) -> V_154 || ! V_2 -> V_105 )
return - V_155 ;
return 0 ;
}
static void F_107 ( struct V_24 * V_25 ,
enum V_156 V_57 )
{
struct V_136 * V_33 = F_108 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
bool V_134 ;
F_109 ( & V_85 -> V_157 ) ;
if ( V_85 -> V_137 )
return;
V_134 = ( V_57 == V_158 ) ;
if ( V_2 -> V_134 == V_134 )
return;
if ( ! V_85 -> V_133 ) {
V_2 -> V_134 = V_134 ;
if ( ! V_134 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_13 ) ;
if ( F_110 ( V_2 ) < 0 ) {
F_61 ( V_2 -> V_33 -> V_9 , L_14 ) ;
V_85 -> V_137 = true ;
}
}
} else {
F_39 ( V_2 -> V_33 -> V_9 , L_15 ,
V_134 ? L_16 : L_17 ) ;
if ( V_134 ) {
F_111 ( V_33 -> V_9 ) ;
F_81 ( V_33 -> V_9 ) ;
V_25 -> V_159 = V_160 ;
V_2 -> V_134 = true ;
if ( F_112 ( & V_2 -> V_50 ) )
F_26 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
} else {
F_113 ( & V_2 -> V_50 ) ;
F_114 ( V_33 -> V_9 ) ;
V_2 -> V_134 = false ;
F_89 ( V_33 -> V_9 ) ;
}
}
}
static bool F_115 ( struct V_24 * V_25 )
{
struct V_136 * V_33 = F_108 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
F_109 ( & V_85 -> V_157 ) ;
if ( V_85 -> V_137 )
return false ;
if ( V_2 -> V_134 || ! V_85 -> V_133 )
return true ;
if ( F_112 ( & V_2 -> V_50 ) )
return false ;
F_113 ( & V_2 -> V_50 ) ;
return true ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
struct V_24 * V_161 = F_117 ( V_2 -> V_25 ) ;
if ( V_161 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_19 ) ;
V_85 -> V_162 = 1 ;
F_118 ( V_161 ) ;
}
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
int V_163 ;
if ( ! V_85 -> V_162 )
return 0 ;
V_163 = F_120 ( V_2 -> V_25 , & V_164 ,
V_165 ) ;
if ( V_163 < 0 )
return V_163 ;
V_85 -> V_166 = 1 ;
F_121 ( V_2 -> V_33 -> V_9 ,
& V_85 -> V_167 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
if ( F_98 ( V_2 ) && V_2 -> V_105 )
F_114 ( & V_25 -> V_9 ) ;
F_76 ( V_2 ) ;
V_85 -> V_137 = 1 ;
F_123 ( & V_85 -> V_157 ) ;
if ( V_162 ( V_85 ) ) {
if ( V_2 -> V_134 && V_85 -> V_133 )
F_113 ( & V_2 -> V_50 ) ;
if ( V_85 -> V_166 ) {
F_124 ( V_2 -> V_25 ) ;
F_125 ( V_2 -> V_33 -> V_9 ) ;
}
}
if ( V_50 -> V_168 ) {
F_58 ( V_2 ) ;
F_126 ( V_2 ) ;
F_84 ( V_2 ) ;
}
if ( V_50 -> V_107 >= 0 )
F_86 ( V_50 -> V_107 , ( void * ) V_2 ) ;
if ( V_2 -> V_109 )
F_87 ( V_2 -> V_25 ) ;
F_127 ( V_50 -> V_120 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_50 ) ;
if ( V_2 -> V_169 )
F_131 ( V_2 -> V_25 ) ;
F_132 ( V_2 -> V_25 ) ;
#ifdef F_133
F_134 ( V_2 -> V_170 ) ;
#endif
if ( V_2 -> V_31 & V_68 ) {
if ( V_85 -> V_139 )
F_46 ( V_50 , false ) ;
}
if ( V_2 -> V_31 & V_171 )
F_135 ( V_50 ) ;
F_136 ( V_85 ) ;
return 0 ;
}
static int F_137 ( struct V_172 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_173 ;
V_2 -> V_50 . V_174 = 1 ;
return 0 ;
}
static int F_138 ( struct V_172 * V_135 )
{
return F_122 ( V_135 -> V_173 ) ;
}
static struct V_24 * F_117 ( struct V_24 * V_25 )
{
struct V_24 * V_161 ;
switch ( V_25 -> V_175 ) {
case V_176 :
case V_177 :
case V_178 :
if ( V_25 -> V_179 == 1 ) {
V_161 = F_139 ( F_140 ( V_25 -> V_50 ) ,
V_25 -> V_50 -> V_103 , 0 ) ;
if ( V_161 ) {
if ( ( V_161 -> V_180 >> 8 ) == V_181 )
return V_161 ;
F_118 ( V_161 ) ;
}
}
break;
}
return NULL ;
}
static bool F_141 ( struct V_24 * V_25 )
{
bool V_182 = false ;
struct V_24 * V_161 = F_117 ( V_25 ) ;
if ( V_161 ) {
if ( F_142 ( V_161 ) == V_158 )
V_182 = true ;
F_118 ( V_161 ) ;
}
return V_182 ;
}
static int F_143 ( struct V_1 * V_2 , int V_183 )
{
const struct V_184 * V_185 ;
switch ( V_183 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
return V_183 ;
}
V_185 = F_144 ( V_2 -> V_25 , V_192 ) ;
if ( V_185 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_20 ,
V_185 -> V_193 , V_185 -> V_194 , V_185 -> V_195 ) ;
return V_185 -> V_193 ;
}
if ( V_2 -> V_14 == V_196 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_189 ;
}
if ( V_2 -> V_31 & V_197 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_22 ) ;
return V_187 ;
}
if ( V_2 -> V_14 == V_69 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_23 ) ;
return V_191 ;
}
return V_186 ;
}
static void F_145 ( struct V_1 * V_2 , int V_183 )
{
static T_2 V_198 [] = {
[ V_186 ] = NULL ,
[ V_187 ] = F_38 ,
[ V_188 ] = F_47 ,
[ V_189 ] = F_64 ,
[ V_190 ] = F_38 ,
[ V_191 ] = F_71 ,
} ;
V_2 -> V_94 [ 0 ] = V_2 -> V_94 [ 1 ] = V_198 [ V_183 ] ;
if ( V_183 == V_190 )
V_2 -> V_94 [ 1 ] = NULL ;
if ( ( V_183 == V_188 || V_183 == V_191 ) &&
( V_2 -> V_31 & V_81 ) ) {
V_2 -> V_82 [ 0 ] = V_2 -> V_82 [ 1 ] =
F_37 ;
}
}
static void F_146 ( struct V_1 * V_2 , int V_9 )
{
const struct V_184 * V_185 ;
V_2 -> V_199 = V_200 [ V_9 ] ;
if ( V_2 -> V_199 == - 1 ) {
V_185 = F_144 ( V_2 -> V_25 , V_201 ) ;
if ( V_185 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_185 -> V_193 , V_185 -> V_194 , V_185 -> V_195 ) ;
V_2 -> V_199 = V_185 -> V_193 ;
}
}
if ( V_2 -> V_199 != - 1 &&
( V_2 -> V_199 & V_202 ) ) {
F_23 ( V_2 ) -> V_203 = V_2 -> V_199 & 0xff ;
F_39 ( V_2 -> V_33 -> V_9 , L_25 ,
( int ) F_23 ( V_2 ) -> V_203 ) ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
const struct V_184 * V_185 ;
if ( V_204 >= 0 ) {
V_2 -> V_109 = ! ! V_204 ;
return;
}
V_2 -> V_109 = 1 ;
V_185 = F_144 ( V_2 -> V_25 , V_205 ) ;
if ( V_185 ) {
F_39 ( V_2 -> V_33 -> V_9 ,
L_26 ,
V_185 -> V_194 , V_185 -> V_195 , V_185 -> V_193 ) ;
V_2 -> V_109 = V_185 -> V_193 ;
return;
}
if ( V_2 -> V_31 & V_206 ) {
F_39 ( V_2 -> V_33 -> V_9 , L_27 ) ;
V_2 -> V_109 = 0 ;
}
}
static void F_148 ( struct V_1 * V_2 )
{
int V_45 = V_207 ;
if ( V_45 >= 0 ) {
F_39 ( V_2 -> V_33 -> V_9 , L_28 ,
V_45 ? L_29 : L_30 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_208 &&
V_2 -> V_14 == V_196 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_209 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_210 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_39 ( V_2 -> V_33 -> V_9 , L_31 ) ;
}
static void F_149 ( struct V_97 * V_98 )
{
struct V_84 * V_85 = F_42 ( V_98 , struct V_84 , V_211 ) ;
F_110 ( & V_85 -> V_2 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_175 == V_212 ) {
switch ( V_2 -> V_25 -> V_135 ) {
case 0x0f04 :
case 0x2284 :
return 32 ;
}
}
switch ( V_2 -> V_14 ) {
case V_213 :
case V_214 :
return 1 ;
default:
return 32 ;
}
}
static int F_151 ( struct V_136 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_215 )
{
static struct V_216 V_217 = {
. V_218 = F_137 ,
. V_219 = F_138 ,
} ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
int V_163 ;
* V_215 = NULL ;
V_163 = F_152 ( V_25 ) ;
if ( V_163 < 0 )
return V_163 ;
V_85 = F_153 ( sizeof( * V_85 ) , V_220 ) ;
if ( ! V_85 ) {
F_132 ( V_25 ) ;
return - V_221 ;
}
V_2 = & V_85 -> V_2 ;
F_154 ( & V_2 -> V_222 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_217 = & V_223 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_147 ( V_2 ) ;
V_2 -> V_224 = V_9 ;
V_2 -> V_225 = V_225 ;
F_155 ( & V_2 -> V_226 ) ;
F_156 ( & V_85 -> V_88 , F_49 ) ;
F_155 ( & V_85 -> V_127 ) ;
F_116 ( V_2 ) ;
F_157 ( & V_85 -> V_157 ) ;
F_145 ( V_2 , F_143 ( V_2 , V_227 [ V_9 ] ) ) ;
F_146 ( V_2 , V_9 ) ;
if ( V_228 < 0 )
V_2 -> V_229 = 1 ;
else
V_2 -> V_228 = V_228 ;
F_148 ( V_2 ) ;
if ( V_96 [ V_9 ] < 0 )
V_2 -> V_96 = F_150 ( V_2 ) ;
else
V_2 -> V_96 = V_96 [ V_9 ] ;
V_163 = F_158 ( V_2 , V_230 [ V_9 ] , & V_231 ) ;
if ( V_163 < 0 ) {
F_136 ( V_85 ) ;
F_132 ( V_25 ) ;
return V_163 ;
}
if ( V_2 -> V_14 == V_232 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_32 ) ;
V_2 -> V_50 . V_233 = 1 ;
}
V_163 = F_159 ( V_33 , V_234 , V_2 , & V_217 ) ;
if ( V_163 < 0 ) {
F_61 ( V_33 -> V_9 , L_33 ) ;
F_122 ( V_2 ) ;
return V_163 ;
}
F_156 ( & V_85 -> V_211 , F_149 ) ;
* V_215 = V_2 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_224 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_136 * V_33 = V_2 -> V_33 ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
int V_163 ;
unsigned short V_235 ;
unsigned int V_236 = 64 ;
#if V_237 != 64
if ( V_2 -> V_14 == V_238 ) {
T_4 V_239 ;
F_17 ( V_25 , 0x40 , & V_239 ) ;
F_18 ( V_25 , 0x40 , V_239 | 0x10 ) ;
F_34 ( V_25 , V_240 , 0 ) ;
}
#endif
V_163 = F_161 ( V_25 , L_34 ) ;
if ( V_163 < 0 )
return V_163 ;
V_2 -> V_169 = 1 ;
V_50 -> V_150 = F_162 ( V_25 , 0 ) ;
V_50 -> V_120 = F_163 ( V_25 , 0 ) ;
if ( V_50 -> V_120 == NULL ) {
F_61 ( V_33 -> V_9 , L_35 ) ;
return - V_241 ;
}
if ( V_2 -> V_14 == V_69 )
F_164 ( V_50 ) ;
V_2 -> V_242 = false ;
#ifdef F_165
if ( V_50 -> V_243 && F_166 ( V_244 ) )
V_2 -> V_242 = true ;
#endif
if ( V_2 -> V_109 ) {
if ( V_2 -> V_31 & V_245 ) {
F_16 ( V_33 -> V_9 , L_36 ) ;
V_25 -> V_246 = true ;
}
if ( F_92 ( V_25 ) < 0 )
V_2 -> V_109 = 0 ;
}
if ( F_59 ( V_2 , 0 ) < 0 )
return - V_155 ;
F_167 ( V_25 ) ;
F_168 ( V_50 -> V_107 ) ;
V_235 = F_100 ( V_2 , V_247 ) ;
F_16 ( V_33 -> V_9 , L_37 , V_235 ) ;
if ( V_2 -> V_25 -> V_175 == V_177 )
V_236 = 40 ;
if ( V_2 -> V_25 -> V_175 == V_176 ) {
struct V_24 * V_248 ;
V_236 = 40 ;
V_248 = F_169 ( V_176 ,
V_249 ,
NULL ) ;
if ( V_248 ) {
if ( V_248 -> V_209 < 0x30 )
V_235 &= ~ V_250 ;
F_118 ( V_248 ) ;
}
}
if ( V_2 -> V_25 -> V_175 == V_178 )
V_236 = 40 ;
if ( V_2 -> V_31 & V_251 ) {
F_16 ( V_33 -> V_9 , L_38 ) ;
V_235 &= ~ V_250 ;
}
if ( V_252 >= 0 )
V_2 -> V_252 = ! ! V_252 ;
else {
if ( V_2 -> V_31 & V_253 )
V_2 -> V_252 = 0 ;
else
V_2 -> V_252 = 1 ;
}
if ( ! ( V_235 & V_250 ) )
V_236 = 32 ;
if ( ! F_170 ( & V_25 -> V_9 , F_171 ( V_236 ) ) ) {
F_172 ( & V_25 -> V_9 , F_171 ( V_236 ) ) ;
} else {
F_170 ( & V_25 -> V_9 , F_171 ( 32 ) ) ;
F_172 ( & V_25 -> V_9 , F_171 ( 32 ) ) ;
}
V_2 -> V_254 = ( V_235 >> 8 ) & 0x0f ;
V_2 -> V_255 = ( V_235 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_255 && ! V_2 -> V_254 ) {
switch ( V_2 -> V_14 ) {
case V_238 :
V_2 -> V_255 = V_256 ;
V_2 -> V_254 = V_257 ;
break;
case V_258 :
case V_259 :
V_2 -> V_255 = V_260 ;
V_2 -> V_254 = V_261 ;
break;
case V_262 :
default:
V_2 -> V_255 = V_263 ;
V_2 -> V_254 = V_264 ;
break;
}
}
V_2 -> V_265 = 0 ;
V_2 -> V_266 = V_2 -> V_254 ;
V_2 -> V_267 = V_2 -> V_255 + V_2 -> V_254 ;
if ( V_2 -> V_267 > 15 &&
( V_2 -> V_31 & V_268 ) == 0 ) {
F_26 ( V_2 -> V_33 -> V_9 , L_39
L_40 , V_2 -> V_267 ) ;
V_2 -> V_31 |= V_268 ;
}
V_163 = F_173 ( V_2 ) ;
if ( V_163 < 0 )
return V_163 ;
V_163 = F_174 ( V_2 ) ;
if ( V_163 < 0 )
return V_163 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_68 )
F_91 ( V_50 ) ;
F_31 ( V_2 , ( V_269 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_23 ( V_2 ) -> V_203 ) {
F_61 ( V_33 -> V_9 , L_41 ) ;
return - V_270 ;
}
strcpy ( V_33 -> V_271 , L_42 ) ;
F_175 ( V_33 -> V_272 , V_273 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_272 ) ) ;
snprintf ( V_33 -> V_274 , sizeof( V_33 -> V_274 ) ,
L_43 ,
V_33 -> V_272 , V_50 -> V_150 , V_50 -> V_107 ) ;
return 0 ;
}
static void F_176 ( const struct V_275 * V_170 , void * V_276 )
{
struct V_136 * V_33 = V_276 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_170 ) {
F_61 ( V_33 -> V_9 , L_44 ) ;
goto error;
}
V_2 -> V_170 = V_170 ;
if ( ! V_2 -> V_134 ) {
if ( F_110 ( V_2 ) )
goto error;
}
return;
error:
F_177 ( V_33 ) ;
F_178 ( V_25 , NULL ) ;
}
static void F_179 ( T_1 V_193 , T_1 T_5 * V_150 )
{
F_28 ( V_193 , V_150 ) ;
}
static T_1 F_180 ( T_1 T_5 * V_150 )
{
return F_24 ( V_150 ) ;
}
static void F_181 ( T_4 V_193 , T_4 T_5 * V_150 )
{
F_182 ( V_193 , V_150 ) ;
}
static T_4 F_183 ( T_4 T_5 * V_150 )
{
return F_68 ( V_150 ) ;
}
static void F_184 ( T_3 V_193 , T_3 T_5 * V_150 )
{
F_185 ( V_193 , V_150 ) ;
}
static T_3 F_186 ( T_3 T_5 * V_150 )
{
return F_187 ( V_150 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
int V_163 ;
F_86 ( V_50 -> V_107 , V_2 ) ;
V_50 -> V_107 = - 1 ;
F_87 ( V_2 -> V_25 ) ;
V_2 -> V_109 = 0 ;
V_163 = F_59 ( V_2 , 1 ) ;
if ( V_163 < 0 )
return V_163 ;
return 0 ;
}
static int F_189 ( struct V_49 * V_50 ,
int type ,
T_6 V_277 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_190 ( V_50 ) ;
int V_163 ;
V_163 = F_191 ( type ,
V_50 -> V_9 ,
V_277 , V_19 ) ;
if ( V_163 < 0 )
return V_163 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_192 ( struct V_49 * V_50 , struct V_3 * V_19 )
{
struct V_1 * V_2 = F_190 ( V_50 ) ;
F_8 ( V_2 , V_19 , false ) ;
F_193 ( V_19 ) ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_277 )
{
struct V_20 * V_20 = F_195 ( V_22 ) ;
int V_64 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_64 = F_196 ( V_22 , V_277 ) ;
if ( V_64 < 0 )
return V_64 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_195 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_198 ( V_22 ) ;
}
static void F_199 ( struct V_21 * V_22 ,
struct V_278 * V_7 )
{
#ifdef F_165
struct V_279 * V_280 = F_200 ( V_22 ) ;
struct V_1 * V_2 = V_280 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_281 = F_201 ( V_7 -> V_281 ) ;
#endif
}
static int F_202 ( struct V_24 * V_25 ,
const struct V_282 * V_283 )
{
static int V_9 ;
struct V_136 * V_33 ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
bool V_284 ;
int V_163 ;
if ( V_9 >= V_285 )
return - V_270 ;
if ( ! V_89 [ V_9 ] ) {
V_9 ++ ;
return - V_286 ;
}
V_163 = F_203 ( & V_25 -> V_9 , V_125 [ V_9 ] , V_287 [ V_9 ] , V_288 ,
0 , & V_33 ) ;
if ( V_163 < 0 ) {
F_61 ( & V_25 -> V_9 , L_45 ) ;
return V_163 ;
}
V_163 = F_151 ( V_33 , V_25 , V_9 , V_283 -> V_289 , & V_2 ) ;
if ( V_163 < 0 )
goto V_290;
V_33 -> V_13 = V_2 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
F_178 ( V_25 , V_33 ) ;
V_163 = F_119 ( V_2 ) ;
if ( V_163 < 0 ) {
F_61 ( V_33 -> V_9 , L_46 ) ;
goto V_290;
}
if ( F_141 ( V_25 ) ) {
F_39 ( V_33 -> V_9 , L_47 ) ;
F_39 ( V_33 -> V_9 , L_48 ) ;
V_2 -> V_134 = true ;
}
V_284 = ! V_2 -> V_134 ;
#ifdef F_133
if ( V_291 [ V_9 ] && * V_291 [ V_9 ] ) {
F_39 ( V_33 -> V_9 , L_49 ,
V_291 [ V_9 ] ) ;
V_163 = F_204 ( V_288 , true , V_291 [ V_9 ] ,
& V_25 -> V_9 , V_220 , V_33 ,
F_176 ) ;
if ( V_163 < 0 )
goto V_290;
V_284 = false ;
}
#endif
#ifndef F_205
if ( F_206 ( V_25 ) )
F_61 ( V_33 -> V_9 , L_50 ) ;
#endif
if ( V_284 )
F_44 ( & V_85 -> V_211 ) ;
V_9 ++ ;
if ( V_2 -> V_134 )
F_123 ( & V_85 -> V_157 ) ;
return 0 ;
V_290:
F_177 ( V_33 ) ;
return V_163 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_224 ;
int V_163 ;
V_85 -> V_133 = 1 ;
if ( V_2 -> V_31 & V_171 ) {
V_163 = F_207 ( V_50 ) ;
if ( V_163 < 0 ) {
if ( F_206 ( V_25 ) ) {
F_61 ( V_2 -> V_33 -> V_9 ,
L_51 ) ;
goto V_290;
} else {
V_2 -> V_31 &=
~ ( V_171 | V_68 ) ;
}
}
}
if ( V_2 -> V_31 & V_68 ) {
if ( F_206 ( V_25 ) )
V_85 -> V_139 = 1 ;
V_163 = F_46 ( V_50 , true ) ;
if ( V_163 < 0 ) {
F_61 ( V_2 -> V_33 -> V_9 ,
L_52 ) ;
goto V_292;
}
}
V_163 = F_160 ( V_2 ) ;
if ( V_163 < 0 )
goto V_290;
#ifdef F_208
V_2 -> V_293 = V_293 [ V_9 ] ;
#endif
V_163 = F_209 ( V_2 , V_294 [ V_2 -> V_14 ] ) ;
if ( V_163 < 0 )
goto V_290;
#ifdef F_133
if ( V_2 -> V_170 ) {
V_163 = F_210 ( & V_2 -> V_50 , V_2 -> V_170 -> V_277 ,
V_2 -> V_170 -> V_29 ) ;
if ( V_163 < 0 )
goto V_290;
#ifndef F_211
F_134 ( V_2 -> V_170 ) ;
V_2 -> V_170 = NULL ;
#endif
}
#endif
if ( ( V_269 [ V_9 ] & 1 ) == 0 ) {
V_163 = F_212 ( V_2 ) ;
if ( V_163 < 0 )
goto V_290;
}
V_163 = F_213 ( V_2 -> V_33 ) ;
if ( V_163 < 0 )
goto V_290;
V_2 -> V_105 = 1 ;
F_72 ( V_2 ) ;
F_80 ( & V_2 -> V_50 , V_132 * 1000 ) ;
if ( F_98 ( V_2 ) || V_85 -> V_162 )
F_214 ( & V_25 -> V_9 ) ;
V_290:
if ( ( V_2 -> V_31 & V_68 )
&& ! V_85 -> V_139 )
F_46 ( V_50 , false ) ;
V_292:
if ( V_163 < 0 )
V_85 -> V_137 = 1 ;
F_123 ( & V_85 -> V_157 ) ;
return V_163 ;
}
static void F_215 ( struct V_24 * V_25 )
{
struct V_136 * V_33 = F_108 ( V_25 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
if ( V_33 ) {
V_2 = V_33 -> V_13 ;
V_85 = F_42 ( V_2 , struct V_84 , V_2 ) ;
F_216 ( & V_25 -> V_9 ) ;
F_217 ( & V_85 -> V_211 ) ;
F_218 ( & V_25 -> V_9 ) ;
F_177 ( V_33 ) ;
}
}
static void F_219 ( struct V_24 * V_25 )
{
struct V_136 * V_33 = F_108 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_105 )
F_84 ( V_2 ) ;
}
