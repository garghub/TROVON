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
if ( F_33 ( V_25 ) ) {
F_34 ( V_25 , V_69 , & V_28 ) ;
V_28 = V_28 & ~ V_70 ;
F_35 ( V_25 , V_69 , V_28 ) ;
}
F_36 ( V_2 , V_67 ) ;
if ( F_33 ( V_25 ) ) {
F_34 ( V_25 , V_69 , & V_28 ) ;
V_28 = V_28 | V_70 ;
F_35 ( V_25 , V_69 , V_28 ) ;
}
if ( V_2 -> V_31 & V_68 )
F_32 ( V_50 , false ) ;
if ( F_37 ( V_25 ) )
F_19 ( V_2 ) ;
if ( V_50 -> V_54 != NULL )
F_30 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_71 )
{
struct V_21 * V_22 = V_20 -> V_72 . V_22 ;
int V_73 = V_22 -> V_73 ;
unsigned int V_74 = F_39 ( V_2 , V_20 ) ;
int V_75 ;
if ( V_73 == V_76 )
V_75 = V_71 - V_74 ;
else
V_75 = V_74 - V_71 ;
if ( V_75 < 0 ) {
if ( V_75 >= V_20 -> V_72 . V_77 )
V_75 = 0 ;
else
V_75 += V_20 -> V_72 . V_78 ;
}
if ( V_75 >= V_20 -> V_72 . V_79 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_8 ,
V_75 , V_20 -> V_72 . V_79 ) ;
V_75 = 0 ;
V_2 -> V_31 &= ~ V_80 ;
V_2 -> V_81 [ V_73 ] = NULL ;
}
return F_41 ( V_22 -> V_82 , V_75 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
int V_85 ;
V_85 = F_44 ( V_2 , V_20 ) ;
if ( V_85 == 1 ) {
V_20 -> V_86 = 0 ;
return V_85 ;
} else if ( V_85 == 0 ) {
V_20 -> V_86 = 1 ;
F_45 ( & V_84 -> V_87 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , bool V_88 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
return F_47 ( V_50 , V_88 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_72 . V_22 ;
int V_73 = V_22 -> V_73 ;
T_1 V_89 ;
unsigned int V_71 ;
V_89 = F_20 ( V_2 , V_90 ) - V_20 -> V_72 . V_91 ;
if ( V_89 < ( V_20 -> V_72 . V_92 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_93 [ V_73 ] )
V_71 = V_2 -> V_93 [ V_73 ] ( V_2 , V_20 ) ;
else {
V_71 = F_48 ( V_2 , V_20 ) ;
if ( ! V_71 || V_71 == ( T_1 ) - 1 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_9 ) ;
V_2 -> V_93 [ V_73 ] = F_39 ;
if ( V_2 -> V_93 [ 0 ] == F_39 &&
V_2 -> V_93 [ 1 ] == F_39 )
F_23 ( V_2 ) -> V_94 = false ;
V_71 = F_39 ( V_2 , V_20 ) ;
V_2 -> V_81 [ V_73 ] = NULL ;
} else {
V_2 -> V_93 [ V_73 ] = F_48 ;
if ( V_2 -> V_31 & V_80 )
V_2 -> V_81 [ V_73 ] = F_38 ;
}
}
if ( V_71 >= V_20 -> V_72 . V_78 )
V_71 = 0 ;
if ( F_49 ( ! V_20 -> V_72 . V_79 ,
L_10 ) )
return - 1 ;
if ( V_89 < ( V_20 -> V_72 . V_92 * 5 ) / 4 &&
V_71 % V_20 -> V_72 . V_79 > V_20 -> V_72 . V_79 / 2 )
return V_2 -> V_95 ? 0 : - 1 ;
V_20 -> V_72 . V_91 += V_89 ;
return 1 ;
}
static void F_50 ( struct V_96 * V_97 )
{
struct V_83 * V_84 = F_43 ( V_97 , struct V_83 , V_87 ) ;
struct V_1 * V_2 = & V_84 -> V_2 ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_98 * V_99 ;
int V_100 , V_85 ;
if ( ! V_84 -> V_101 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_33 -> V_102 ) ;
V_84 -> V_101 = 1 ;
}
for (; ; ) {
V_100 = 0 ;
F_51 ( & V_50 -> V_103 ) ;
F_52 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_53 ( V_99 ) ;
if ( ! V_20 -> V_86 ||
! V_99 -> V_22 ||
! V_99 -> V_104 )
continue;
V_85 = F_44 ( V_2 , V_20 ) ;
if ( V_85 > 0 ) {
V_20 -> V_86 = 0 ;
F_54 ( & V_50 -> V_103 ) ;
F_55 ( V_99 -> V_22 ) ;
F_56 ( & V_50 -> V_103 ) ;
} else if ( V_85 < 0 ) {
V_100 = 0 ;
} else
V_100 ++ ;
}
F_57 ( & V_50 -> V_103 ) ;
if ( ! V_100 )
return;
F_58 ( 1 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_98 * V_99 ;
F_51 ( & V_50 -> V_103 ) ;
F_52 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_53 ( V_99 ) ;
V_20 -> V_86 = 0 ;
}
F_57 ( & V_50 -> V_103 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_105 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
if ( F_61 ( V_2 -> V_25 -> V_106 , V_107 ,
V_2 -> V_108 ? 0 : V_109 ,
V_2 -> V_33 -> V_110 , V_2 ) ) {
F_62 ( V_2 -> V_33 -> V_9 ,
L_12 ,
V_2 -> V_25 -> V_106 ) ;
if ( V_105 )
F_63 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_50 -> V_106 = V_2 -> V_25 -> V_106 ;
F_64 ( V_2 -> V_25 , ! V_2 -> V_108 ) ;
return 0 ;
}
static unsigned int F_65 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_111 , V_112 , V_113 ;
unsigned int V_114 , V_115 , V_116 ;
unsigned int V_117 ;
V_111 = F_66 ( F_67 ( V_20 ) ) ;
if ( V_20 -> V_72 . V_22 -> V_73 == V_76 ) {
return V_111 ;
}
V_115 = F_68 ( * V_20 -> V_72 . V_118 ) ;
V_115 %= V_20 -> V_72 . V_79 ;
V_117 = F_69 ( F_23 ( V_2 ) -> V_119 +
V_120 ) ;
if ( V_20 -> V_121 ) {
if ( V_111 <= V_117 )
return 0 ;
V_20 -> V_121 = 0 ;
}
if ( V_111 <= V_117 )
V_112 = V_20 -> V_72 . V_78 + V_111 - V_117 ;
else
V_112 = V_111 - V_117 ;
V_116 = V_112 % V_20 -> V_72 . V_79 ;
V_114 = V_111 % V_20 -> V_72 . V_79 ;
if ( V_114 >= V_117 )
V_113 = V_111 - V_114 ;
else if ( V_115 >= V_116 )
V_113 = V_112 - V_116 ;
else {
V_113 = V_112 - V_116 + V_20 -> V_72 . V_79 ;
if ( V_113 >= V_20 -> V_72 . V_78 )
V_113 = 0 ;
}
return V_113 + V_115 ;
}
static unsigned int F_70 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
return F_71 ( F_23 ( V_2 ) ,
V_122 +
( V_123 *
V_20 -> V_72 . V_124 ) ) ;
}
static unsigned int F_72 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
if ( V_20 -> V_72 . V_22 -> V_73 == V_76 )
return F_70 ( V_2 , V_20 ) ;
F_29 ( 20 ) ;
F_70 ( V_2 , V_20 ) ;
return F_48 ( V_2 , V_20 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
F_74 ( & V_125 ) ;
F_75 ( & V_84 -> V_126 , & V_127 ) ;
F_76 ( & V_125 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
F_74 ( & V_125 ) ;
F_78 ( & V_84 -> V_126 ) ;
F_76 ( & V_125 ) ;
}
static int F_79 ( const char * V_28 , const struct V_128 * V_129 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 ;
int V_130 = V_131 ;
int V_64 = F_80 ( V_28 , V_129 ) ;
if ( V_64 || V_130 == V_131 )
return V_64 ;
F_74 ( & V_125 ) ;
F_52 (hda, &card_list, list) {
V_2 = & V_84 -> V_2 ;
if ( ! V_84 -> V_132 || V_2 -> V_133 )
continue;
F_81 ( & V_2 -> V_50 , V_131 * 1000 ) ;
}
F_76 ( & V_125 ) ;
return 0 ;
}
static int F_82 ( struct V_134 * V_9 )
{
struct V_135 * V_33 = F_83 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_49 * V_50 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
if ( V_2 -> V_133 || V_84 -> V_136 || ! V_2 -> V_104 )
return 0 ;
V_50 = F_23 ( V_2 ) ;
F_84 ( V_33 , V_137 ) ;
F_59 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_50 -> V_106 >= 0 ) {
F_87 ( V_50 -> V_106 , V_2 ) ;
V_50 -> V_106 = - 1 ;
}
if ( V_2 -> V_108 )
F_88 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_68
&& V_84 -> V_138 )
F_47 ( V_50 , false ) ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_134 * V_9 )
{
struct V_24 * V_25 = F_91 ( V_9 ) ;
struct V_135 * V_33 = F_83 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_49 * V_50 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
V_50 = F_23 ( V_2 ) ;
if ( V_2 -> V_133 || V_84 -> V_136 || ! V_2 -> V_104 )
return 0 ;
if ( V_2 -> V_31 & V_68 ) {
F_47 ( V_50 , true ) ;
if ( V_84 -> V_138 )
F_92 ( V_50 ) ;
}
if ( V_2 -> V_108 )
if ( F_93 ( V_25 ) < 0 )
V_2 -> V_108 = 0 ;
if ( F_60 ( V_2 , 1 ) < 0 )
return - V_139 ;
F_14 ( V_2 ) ;
F_31 ( V_2 , true ) ;
if ( ( V_2 -> V_31 & V_68 ) &&
! V_84 -> V_138 )
F_47 ( V_50 , false ) ;
F_84 ( V_33 , V_140 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_134 * V_9 )
{
struct V_24 * V_25 = F_91 ( V_9 ) ;
if ( F_33 ( V_25 ) )
F_96 ( V_25 , V_141 ) ;
return 0 ;
}
static int F_97 ( struct V_134 * V_9 )
{
struct V_24 * V_25 = F_91 ( V_9 ) ;
if ( F_33 ( V_25 ) )
F_96 ( V_25 , V_142 ) ;
return 0 ;
}
static int F_98 ( struct V_134 * V_9 )
{
struct V_135 * V_33 = F_83 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
if ( V_2 -> V_133 || V_84 -> V_136 )
return 0 ;
if ( ! F_99 ( V_2 ) )
return 0 ;
F_100 ( V_2 , V_143 , F_101 ( V_2 , V_143 ) |
V_144 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_31 & V_68
&& V_84 -> V_138 )
F_47 ( F_23 ( V_2 ) , false ) ;
F_102 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_134 * V_9 )
{
struct V_135 * V_33 = F_83 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_49 * V_50 ;
struct V_145 * V_146 ;
int V_147 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
V_50 = F_23 ( V_2 ) ;
if ( V_2 -> V_133 || V_84 -> V_136 )
return 0 ;
if ( ! F_99 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_68 ) {
F_47 ( V_50 , true ) ;
if ( V_84 -> V_138 )
F_92 ( V_50 ) ;
}
V_147 = F_101 ( V_2 , V_148 ) ;
F_14 ( V_2 ) ;
F_31 ( V_2 , true ) ;
if ( V_147 ) {
F_104 (codec, &chip->bus)
if ( V_147 & ( 1 << V_146 -> V_149 ) )
F_105 ( & V_146 -> V_150 ,
V_146 -> V_151 ) ;
}
F_100 ( V_2 , V_143 , F_101 ( V_2 , V_143 ) &
~ V_144 ) ;
if ( ( V_2 -> V_31 & V_68 ) &&
! V_84 -> V_138 )
F_47 ( V_50 , false ) ;
F_106 ( V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_134 * V_9 )
{
struct V_135 * V_33 = F_83 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
if ( V_2 -> V_133 || V_84 -> V_136 )
return 0 ;
if ( ! V_152 || ! F_99 ( V_2 ) ||
F_23 ( V_2 ) -> V_153 || ! V_2 -> V_104 )
return - V_154 ;
return 0 ;
}
static void F_108 ( struct V_24 * V_25 ,
enum V_155 V_57 )
{
struct V_135 * V_33 = F_109 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
bool V_133 ;
F_110 ( & V_84 -> V_156 ) ;
if ( V_84 -> V_136 )
return;
V_133 = ( V_57 == V_157 ) ;
if ( V_2 -> V_133 == V_133 )
return;
if ( ! V_84 -> V_132 ) {
V_2 -> V_133 = V_133 ;
if ( ! V_133 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_13 ) ;
if ( F_111 ( V_2 ) < 0 ) {
F_62 ( V_2 -> V_33 -> V_9 , L_14 ) ;
V_84 -> V_136 = true ;
}
}
} else {
F_40 ( V_2 -> V_33 -> V_9 , L_15 ,
V_133 ? L_16 : L_17 ) ;
if ( V_133 ) {
F_112 ( V_33 -> V_9 ) ;
F_82 ( V_33 -> V_9 ) ;
V_25 -> V_158 = V_159 ;
V_2 -> V_133 = true ;
if ( F_113 ( & V_2 -> V_50 ) )
F_26 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
} else {
F_114 ( & V_2 -> V_50 ) ;
F_115 ( V_33 -> V_9 ) ;
V_2 -> V_133 = false ;
F_90 ( V_33 -> V_9 ) ;
}
}
}
static bool F_116 ( struct V_24 * V_25 )
{
struct V_135 * V_33 = F_109 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
F_110 ( & V_84 -> V_156 ) ;
if ( V_84 -> V_136 )
return false ;
if ( V_2 -> V_133 || ! V_84 -> V_132 )
return true ;
if ( F_113 ( & V_2 -> V_50 ) )
return false ;
F_114 ( & V_2 -> V_50 ) ;
return true ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
struct V_24 * V_160 = F_118 ( V_2 -> V_25 ) ;
if ( V_160 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_19 ) ;
V_84 -> V_161 = 1 ;
F_119 ( V_160 ) ;
}
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
int V_162 ;
if ( ! V_84 -> V_161 )
return 0 ;
V_162 = F_121 ( V_2 -> V_25 , & V_163 ,
V_164 ) ;
if ( V_162 < 0 )
return V_162 ;
V_84 -> V_165 = 1 ;
F_122 ( V_2 -> V_33 -> V_9 ,
& V_84 -> V_166 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
if ( F_99 ( V_2 ) && V_2 -> V_104 )
F_115 ( & V_25 -> V_9 ) ;
F_77 ( V_2 ) ;
V_84 -> V_136 = 1 ;
F_124 ( & V_84 -> V_156 ) ;
if ( V_161 ( V_84 ) ) {
if ( V_2 -> V_133 && V_84 -> V_132 )
F_114 ( & V_2 -> V_50 ) ;
if ( V_84 -> V_165 ) {
F_125 ( V_2 -> V_25 ) ;
F_126 ( V_2 -> V_33 -> V_9 ) ;
}
}
if ( V_50 -> V_167 ) {
F_59 ( V_2 ) ;
F_127 ( V_2 ) ;
F_85 ( V_2 ) ;
}
if ( V_50 -> V_106 >= 0 )
F_87 ( V_50 -> V_106 , ( void * ) V_2 ) ;
if ( V_2 -> V_108 )
F_88 ( V_2 -> V_25 ) ;
F_128 ( V_50 -> V_119 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_50 ) ;
if ( V_2 -> V_168 )
F_132 ( V_2 -> V_25 ) ;
F_133 ( V_2 -> V_25 ) ;
#ifdef F_134
F_135 ( V_2 -> V_169 ) ;
#endif
if ( V_2 -> V_31 & V_68 ) {
if ( V_84 -> V_138 )
F_47 ( V_50 , false ) ;
F_136 ( V_50 ) ;
}
F_137 ( V_84 ) ;
return 0 ;
}
static int F_138 ( struct V_170 * V_134 )
{
struct V_1 * V_2 = V_134 -> V_171 ;
V_2 -> V_50 . V_172 = 1 ;
return 0 ;
}
static int F_139 ( struct V_170 * V_134 )
{
return F_123 ( V_134 -> V_171 ) ;
}
static struct V_24 * F_118 ( struct V_24 * V_25 )
{
struct V_24 * V_160 ;
switch ( V_25 -> V_173 ) {
case V_174 :
case V_175 :
case V_176 :
if ( V_25 -> V_177 == 1 ) {
V_160 = F_140 ( F_141 ( V_25 -> V_50 ) ,
V_25 -> V_50 -> V_102 , 0 ) ;
if ( V_160 ) {
if ( ( V_160 -> V_178 >> 8 ) == V_179 )
return V_160 ;
F_119 ( V_160 ) ;
}
}
break;
}
return NULL ;
}
static bool F_142 ( struct V_24 * V_25 )
{
bool V_180 = false ;
struct V_24 * V_160 = F_118 ( V_25 ) ;
if ( V_160 ) {
if ( F_143 ( V_160 ) == V_157 )
V_180 = true ;
F_119 ( V_160 ) ;
}
return V_180 ;
}
static int F_144 ( struct V_1 * V_2 , int V_181 )
{
const struct V_182 * V_183 ;
switch ( V_181 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
return V_181 ;
}
V_183 = F_145 ( V_2 -> V_25 , V_190 ) ;
if ( V_183 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_20 ,
V_183 -> V_191 , V_183 -> V_192 , V_183 -> V_193 ) ;
return V_183 -> V_191 ;
}
if ( V_2 -> V_14 == V_194 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_187 ;
}
if ( V_2 -> V_31 & V_195 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_22 ) ;
return V_185 ;
}
if ( F_33 ( V_2 -> V_25 ) ) {
F_16 ( V_2 -> V_33 -> V_9 , L_23 ) ;
return V_189 ;
}
return V_184 ;
}
static void F_146 ( struct V_1 * V_2 , int V_181 )
{
static T_2 V_196 [] = {
[ V_184 ] = NULL ,
[ V_185 ] = F_39 ,
[ V_186 ] = F_48 ,
[ V_187 ] = F_65 ,
[ V_188 ] = F_39 ,
[ V_189 ] = F_72 ,
} ;
V_2 -> V_93 [ 0 ] = V_2 -> V_93 [ 1 ] = V_196 [ V_181 ] ;
if ( V_181 == V_188 )
V_2 -> V_93 [ 1 ] = NULL ;
if ( ( V_181 == V_186 || V_181 == V_189 ) &&
( V_2 -> V_31 & V_80 ) ) {
V_2 -> V_81 [ 0 ] = V_2 -> V_81 [ 1 ] =
F_38 ;
}
}
static void F_147 ( struct V_1 * V_2 , int V_9 )
{
const struct V_182 * V_183 ;
V_2 -> V_197 = V_198 [ V_9 ] ;
if ( V_2 -> V_197 == - 1 ) {
V_183 = F_145 ( V_2 -> V_25 , V_199 ) ;
if ( V_183 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_183 -> V_191 , V_183 -> V_192 , V_183 -> V_193 ) ;
V_2 -> V_197 = V_183 -> V_191 ;
}
}
if ( V_2 -> V_197 != - 1 &&
( V_2 -> V_197 & V_200 ) ) {
F_23 ( V_2 ) -> V_201 = V_2 -> V_197 & 0xff ;
F_40 ( V_2 -> V_33 -> V_9 , L_25 ,
( int ) F_23 ( V_2 ) -> V_201 ) ;
}
}
static void F_148 ( struct V_1 * V_2 )
{
const struct V_182 * V_183 ;
if ( V_202 >= 0 ) {
V_2 -> V_108 = ! ! V_202 ;
return;
}
V_2 -> V_108 = 1 ;
V_183 = F_145 ( V_2 -> V_25 , V_203 ) ;
if ( V_183 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_26 ,
V_183 -> V_192 , V_183 -> V_193 , V_183 -> V_191 ) ;
V_2 -> V_108 = V_183 -> V_191 ;
return;
}
if ( V_2 -> V_31 & V_204 ) {
F_40 ( V_2 -> V_33 -> V_9 , L_27 ) ;
V_2 -> V_108 = 0 ;
}
}
static void F_149 ( struct V_1 * V_2 )
{
int V_45 = V_205 ;
if ( V_45 >= 0 ) {
F_40 ( V_2 -> V_33 -> V_9 , L_28 ,
V_45 ? L_29 : L_30 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_206 &&
V_2 -> V_14 == V_194 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_207 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_208 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_40 ( V_2 -> V_33 -> V_9 , L_31 ) ;
}
static void F_150 ( struct V_96 * V_97 )
{
struct V_83 * V_84 = F_43 ( V_97 , struct V_83 , V_209 ) ;
F_111 ( & V_84 -> V_2 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_173 == V_210 ) {
switch ( V_2 -> V_25 -> V_134 ) {
case 0x0f04 :
case 0x2284 :
return 32 ;
}
}
switch ( V_2 -> V_14 ) {
case V_211 :
case V_212 :
return 1 ;
default:
return 32 ;
}
}
static int F_152 ( struct V_135 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_213 )
{
static struct V_214 V_215 = {
. V_216 = F_138 ,
. V_217 = F_139 ,
} ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
int V_162 ;
* V_213 = NULL ;
V_162 = F_153 ( V_25 ) ;
if ( V_162 < 0 )
return V_162 ;
V_84 = F_154 ( sizeof( * V_84 ) , V_218 ) ;
if ( ! V_84 ) {
F_133 ( V_25 ) ;
return - V_219 ;
}
V_2 = & V_84 -> V_2 ;
F_155 ( & V_2 -> V_220 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_215 = & V_221 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_148 ( V_2 ) ;
V_2 -> V_222 = V_9 ;
V_2 -> V_223 = V_223 ;
F_156 ( & V_2 -> V_224 ) ;
F_157 ( & V_84 -> V_87 , F_50 ) ;
F_156 ( & V_84 -> V_126 ) ;
F_117 ( V_2 ) ;
F_158 ( & V_84 -> V_156 ) ;
F_146 ( V_2 , F_144 ( V_2 , V_225 [ V_9 ] ) ) ;
F_147 ( V_2 , V_9 ) ;
if ( V_226 < 0 )
V_2 -> V_227 = 1 ;
else
V_2 -> V_226 = V_226 ;
F_149 ( V_2 ) ;
if ( V_95 [ V_9 ] < 0 )
V_2 -> V_95 = F_151 ( V_2 ) ;
else
V_2 -> V_95 = V_95 [ V_9 ] ;
V_162 = F_159 ( V_2 , V_228 [ V_9 ] , & V_229 ) ;
if ( V_162 < 0 ) {
F_137 ( V_84 ) ;
F_133 ( V_25 ) ;
return V_162 ;
}
if ( V_2 -> V_14 == V_230 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_32 ) ;
V_2 -> V_50 . V_231 = 1 ;
}
V_162 = F_160 ( V_33 , V_232 , V_2 , & V_215 ) ;
if ( V_162 < 0 ) {
F_62 ( V_33 -> V_9 , L_33 ) ;
F_123 ( V_2 ) ;
return V_162 ;
}
F_157 ( & V_84 -> V_209 , F_150 ) ;
* V_213 = V_2 ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_222 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_135 * V_33 = V_2 -> V_33 ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
int V_162 ;
unsigned short V_233 ;
unsigned int V_234 = 64 ;
#if V_235 != 64
if ( V_2 -> V_14 == V_236 ) {
T_4 V_237 ;
F_17 ( V_25 , 0x40 , & V_237 ) ;
F_18 ( V_25 , 0x40 , V_237 | 0x10 ) ;
F_35 ( V_25 , V_238 , 0 ) ;
}
#endif
V_162 = F_162 ( V_25 , L_34 ) ;
if ( V_162 < 0 )
return V_162 ;
V_2 -> V_168 = 1 ;
V_50 -> V_149 = F_163 ( V_25 , 0 ) ;
V_50 -> V_119 = F_164 ( V_25 , 0 ) ;
if ( V_50 -> V_119 == NULL ) {
F_62 ( V_33 -> V_9 , L_35 ) ;
return - V_239 ;
}
if ( F_33 ( V_25 ) )
F_165 ( V_50 ) ;
V_2 -> V_240 = false ;
#ifdef F_166
if ( V_50 -> V_241 && F_167 ( V_242 ) )
V_2 -> V_240 = true ;
#endif
if ( V_2 -> V_108 ) {
if ( V_2 -> V_31 & V_243 ) {
F_16 ( V_33 -> V_9 , L_36 ) ;
V_25 -> V_244 = true ;
}
if ( F_93 ( V_25 ) < 0 )
V_2 -> V_108 = 0 ;
}
if ( F_60 ( V_2 , 0 ) < 0 )
return - V_154 ;
F_168 ( V_25 ) ;
F_169 ( V_50 -> V_106 ) ;
V_233 = F_101 ( V_2 , V_245 ) ;
F_16 ( V_33 -> V_9 , L_37 , V_233 ) ;
if ( V_2 -> V_25 -> V_173 == V_175 )
V_234 = 40 ;
if ( V_2 -> V_25 -> V_173 == V_174 ) {
struct V_24 * V_246 ;
V_234 = 40 ;
V_246 = F_170 ( V_174 ,
V_247 ,
NULL ) ;
if ( V_246 ) {
if ( V_246 -> V_207 < 0x30 )
V_233 &= ~ V_248 ;
F_119 ( V_246 ) ;
}
}
if ( V_2 -> V_25 -> V_173 == V_176 )
V_234 = 40 ;
if ( V_2 -> V_31 & V_249 ) {
F_16 ( V_33 -> V_9 , L_38 ) ;
V_233 &= ~ V_248 ;
}
if ( V_250 >= 0 )
V_2 -> V_250 = ! ! V_250 ;
else {
if ( V_2 -> V_31 & V_251 )
V_2 -> V_250 = 0 ;
else
V_2 -> V_250 = 1 ;
}
if ( ! ( V_233 & V_248 ) )
V_234 = 32 ;
if ( ! F_171 ( & V_25 -> V_9 , F_172 ( V_234 ) ) ) {
F_173 ( & V_25 -> V_9 , F_172 ( V_234 ) ) ;
} else {
F_171 ( & V_25 -> V_9 , F_172 ( 32 ) ) ;
F_173 ( & V_25 -> V_9 , F_172 ( 32 ) ) ;
}
V_2 -> V_252 = ( V_233 >> 8 ) & 0x0f ;
V_2 -> V_253 = ( V_233 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_253 && ! V_2 -> V_252 ) {
switch ( V_2 -> V_14 ) {
case V_236 :
V_2 -> V_253 = V_254 ;
V_2 -> V_252 = V_255 ;
break;
case V_256 :
case V_257 :
V_2 -> V_253 = V_258 ;
V_2 -> V_252 = V_259 ;
break;
case V_260 :
default:
V_2 -> V_253 = V_261 ;
V_2 -> V_252 = V_262 ;
break;
}
}
V_2 -> V_263 = 0 ;
V_2 -> V_264 = V_2 -> V_252 ;
V_2 -> V_265 = V_2 -> V_253 + V_2 -> V_252 ;
if ( V_2 -> V_265 > 15 &&
( V_2 -> V_31 & V_266 ) == 0 ) {
F_26 ( V_2 -> V_33 -> V_9 , L_39
L_40 , V_2 -> V_265 ) ;
V_2 -> V_31 |= V_266 ;
}
V_162 = F_174 ( V_2 ) ;
if ( V_162 < 0 )
return V_162 ;
V_162 = F_175 ( V_2 ) ;
if ( V_162 < 0 )
return V_162 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_68 )
F_92 ( V_50 ) ;
F_31 ( V_2 , ( V_267 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_23 ( V_2 ) -> V_201 ) {
F_62 ( V_33 -> V_9 , L_41 ) ;
return - V_268 ;
}
strcpy ( V_33 -> V_269 , L_42 ) ;
F_176 ( V_33 -> V_270 , V_271 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_270 ) ) ;
snprintf ( V_33 -> V_272 , sizeof( V_33 -> V_272 ) ,
L_43 ,
V_33 -> V_270 , V_50 -> V_149 , V_50 -> V_106 ) ;
return 0 ;
}
static void F_177 ( const struct V_273 * V_169 , void * V_274 )
{
struct V_135 * V_33 = V_274 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_169 ) {
F_62 ( V_33 -> V_9 , L_44 ) ;
goto error;
}
V_2 -> V_169 = V_169 ;
if ( ! V_2 -> V_133 ) {
if ( F_111 ( V_2 ) )
goto error;
}
return;
error:
F_178 ( V_33 ) ;
F_179 ( V_25 , NULL ) ;
}
static void F_180 ( T_1 V_191 , T_1 T_5 * V_149 )
{
F_28 ( V_191 , V_149 ) ;
}
static T_1 F_181 ( T_1 T_5 * V_149 )
{
return F_24 ( V_149 ) ;
}
static void F_182 ( T_4 V_191 , T_4 T_5 * V_149 )
{
F_183 ( V_191 , V_149 ) ;
}
static T_4 F_184 ( T_4 T_5 * V_149 )
{
return F_69 ( V_149 ) ;
}
static void F_185 ( T_3 V_191 , T_3 T_5 * V_149 )
{
F_186 ( V_191 , V_149 ) ;
}
static T_3 F_187 ( T_3 T_5 * V_149 )
{
return F_188 ( V_149 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_23 ( V_2 ) ;
int V_162 ;
F_87 ( V_50 -> V_106 , V_2 ) ;
V_50 -> V_106 = - 1 ;
F_88 ( V_2 -> V_25 ) ;
V_2 -> V_108 = 0 ;
V_162 = F_60 ( V_2 , 1 ) ;
if ( V_162 < 0 )
return V_162 ;
return 0 ;
}
static int F_190 ( struct V_49 * V_50 ,
int type ,
T_6 V_275 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_191 ( V_50 ) ;
int V_162 ;
V_162 = F_192 ( type ,
V_50 -> V_9 ,
V_275 , V_19 ) ;
if ( V_162 < 0 )
return V_162 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_193 ( struct V_49 * V_50 , struct V_3 * V_19 )
{
struct V_1 * V_2 = F_191 ( V_50 ) ;
F_8 ( V_2 , V_19 , false ) ;
F_194 ( V_19 ) ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_275 )
{
struct V_20 * V_20 = F_196 ( V_22 ) ;
int V_64 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_64 = F_197 ( V_22 , V_275 ) ;
if ( V_64 < 0 )
return V_64 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_196 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_199 ( V_22 ) ;
}
static void F_200 ( struct V_21 * V_22 ,
struct V_276 * V_7 )
{
#ifdef F_166
struct V_277 * V_278 = F_201 ( V_22 ) ;
struct V_1 * V_2 = V_278 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_279 = F_202 ( V_7 -> V_279 ) ;
#endif
}
static int F_203 ( struct V_24 * V_25 ,
const struct V_280 * V_281 )
{
static int V_9 ;
struct V_135 * V_33 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
bool V_282 ;
int V_162 ;
if ( V_9 >= V_283 )
return - V_268 ;
if ( ! V_88 [ V_9 ] ) {
V_9 ++ ;
return - V_284 ;
}
V_162 = F_204 ( & V_25 -> V_9 , V_124 [ V_9 ] , V_285 [ V_9 ] , V_286 ,
0 , & V_33 ) ;
if ( V_162 < 0 ) {
F_62 ( & V_25 -> V_9 , L_45 ) ;
return V_162 ;
}
V_162 = F_152 ( V_33 , V_25 , V_9 , V_281 -> V_287 , & V_2 ) ;
if ( V_162 < 0 )
goto V_288;
V_33 -> V_13 = V_2 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
F_179 ( V_25 , V_33 ) ;
V_162 = F_120 ( V_2 ) ;
if ( V_162 < 0 ) {
F_62 ( V_33 -> V_9 , L_46 ) ;
goto V_288;
}
if ( F_142 ( V_25 ) ) {
F_40 ( V_33 -> V_9 , L_47 ) ;
F_40 ( V_33 -> V_9 , L_48 ) ;
V_2 -> V_133 = true ;
}
V_282 = ! V_2 -> V_133 ;
#ifdef F_134
if ( V_289 [ V_9 ] && * V_289 [ V_9 ] ) {
F_40 ( V_33 -> V_9 , L_49 ,
V_289 [ V_9 ] ) ;
V_162 = F_205 ( V_286 , true , V_289 [ V_9 ] ,
& V_25 -> V_9 , V_218 , V_33 ,
F_177 ) ;
if ( V_162 < 0 )
goto V_288;
V_282 = false ;
}
#endif
#ifndef F_206
if ( F_207 ( V_25 ) )
F_62 ( V_33 -> V_9 , L_50 ) ;
#endif
if ( V_282 )
F_45 ( & V_84 -> V_209 ) ;
V_9 ++ ;
if ( V_2 -> V_133 )
F_124 ( & V_84 -> V_156 ) ;
return 0 ;
V_288:
F_178 ( V_33 ) ;
return V_162 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
struct V_49 * V_50 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_222 ;
int V_162 ;
V_84 -> V_132 = 1 ;
if ( V_2 -> V_31 & V_68 ) {
if ( F_207 ( V_25 ) )
V_84 -> V_138 = 1 ;
V_162 = F_208 ( V_50 ) ;
if ( V_162 < 0 ) {
if ( F_207 ( V_25 ) ) {
F_62 ( V_2 -> V_33 -> V_9 ,
L_51 ) ;
goto V_288;
} else
goto V_290;
}
V_162 = F_47 ( V_50 , true ) ;
if ( V_162 < 0 ) {
F_62 ( V_2 -> V_33 -> V_9 ,
L_52 ) ;
goto V_291;
}
}
V_290:
V_162 = F_161 ( V_2 ) ;
if ( V_162 < 0 )
goto V_288;
#ifdef F_209
V_2 -> V_292 = V_292 [ V_9 ] ;
#endif
V_162 = F_210 ( V_2 , V_293 [ V_2 -> V_14 ] ) ;
if ( V_162 < 0 )
goto V_288;
#ifdef F_134
if ( V_2 -> V_169 ) {
V_162 = F_211 ( & V_2 -> V_50 , V_2 -> V_169 -> V_275 ,
V_2 -> V_169 -> V_29 ) ;
if ( V_162 < 0 )
goto V_288;
#ifndef F_212
F_135 ( V_2 -> V_169 ) ;
V_2 -> V_169 = NULL ;
#endif
}
#endif
if ( ( V_267 [ V_9 ] & 1 ) == 0 ) {
V_162 = F_213 ( V_2 ) ;
if ( V_162 < 0 )
goto V_288;
}
V_162 = F_214 ( V_2 -> V_33 ) ;
if ( V_162 < 0 )
goto V_288;
V_2 -> V_104 = 1 ;
F_73 ( V_2 ) ;
F_81 ( & V_2 -> V_50 , V_131 * 1000 ) ;
if ( F_99 ( V_2 ) || V_84 -> V_161 )
F_215 ( & V_25 -> V_9 ) ;
V_288:
if ( V_2 -> V_31 & V_68
&& ! V_84 -> V_138 )
F_47 ( V_50 , false ) ;
V_291:
if ( V_162 < 0 )
V_84 -> V_136 = 1 ;
F_124 ( & V_84 -> V_156 ) ;
return V_162 ;
}
static void F_216 ( struct V_24 * V_25 )
{
struct V_135 * V_33 = F_109 ( V_25 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
if ( V_33 ) {
V_2 = V_33 -> V_13 ;
V_84 = F_43 ( V_2 , struct V_83 , V_2 ) ;
F_217 ( & V_25 -> V_9 ) ;
F_218 ( & V_84 -> V_209 ) ;
F_219 ( & V_25 -> V_9 ) ;
F_178 ( V_33 ) ;
}
}
static void F_220 ( struct V_24 * V_25 )
{
struct V_135 * V_33 = F_109 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_104 )
F_85 ( V_2 ) ;
}
