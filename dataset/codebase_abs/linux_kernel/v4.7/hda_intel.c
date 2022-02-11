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
static void F_22 ( struct V_1 * V_2 , bool V_49 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
T_1 V_28 ;
if ( V_2 -> V_31 & V_52 )
F_24 ( V_51 , true ) ;
if ( F_25 ( V_25 ) ) {
F_26 ( V_25 , V_53 , & V_28 ) ;
V_28 = V_28 & ~ V_54 ;
F_27 ( V_25 , V_53 , V_28 ) ;
}
F_28 ( V_2 , V_49 ) ;
if ( F_25 ( V_25 ) ) {
F_26 ( V_25 , V_53 , & V_28 ) ;
V_28 = V_28 | V_54 ;
F_27 ( V_25 , V_53 , V_28 ) ;
}
if ( V_2 -> V_31 & V_52 )
F_24 ( V_51 , false ) ;
if ( F_29 ( V_25 ) )
F_19 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_55 )
{
struct V_21 * V_22 = V_20 -> V_56 . V_22 ;
int V_57 = V_22 -> V_57 ;
unsigned int V_58 = F_31 ( V_2 , V_20 ) ;
int V_59 ;
if ( V_57 == V_60 )
V_59 = V_55 - V_58 ;
else
V_59 = V_58 - V_55 ;
if ( V_59 < 0 ) {
if ( V_59 >= V_20 -> V_56 . V_61 )
V_59 = 0 ;
else
V_59 += V_20 -> V_56 . V_62 ;
}
if ( V_59 >= V_20 -> V_56 . V_63 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_7 ,
V_59 , V_20 -> V_56 . V_63 ) ;
V_59 = 0 ;
V_2 -> V_31 &= ~ V_64 ;
V_2 -> V_65 [ V_57 ] = NULL ;
}
return F_33 ( V_22 -> V_66 , V_59 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
int V_69 ;
V_69 = F_36 ( V_2 , V_20 ) ;
if ( V_69 == 1 ) {
V_20 -> V_70 = 0 ;
return V_69 ;
} else if ( V_69 == 0 ) {
V_20 -> V_70 = 1 ;
F_37 ( & V_68 -> V_71 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , bool V_72 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
return F_39 ( V_51 , V_72 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_56 . V_22 ;
int V_57 = V_22 -> V_57 ;
T_1 V_73 ;
unsigned int V_55 ;
V_73 = F_20 ( V_2 , V_74 ) - V_20 -> V_56 . V_75 ;
if ( V_73 < ( V_20 -> V_56 . V_76 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_77 [ V_57 ] )
V_55 = V_2 -> V_77 [ V_57 ] ( V_2 , V_20 ) ;
else {
V_55 = F_40 ( V_2 , V_20 ) ;
if ( ! V_55 || V_55 == ( T_1 ) - 1 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_8 ) ;
V_2 -> V_77 [ V_57 ] = F_31 ;
if ( V_2 -> V_77 [ 0 ] == F_31 &&
V_2 -> V_77 [ 1 ] == F_31 )
F_23 ( V_2 ) -> V_78 = false ;
V_55 = F_31 ( V_2 , V_20 ) ;
V_2 -> V_65 [ V_57 ] = NULL ;
} else {
V_2 -> V_77 [ V_57 ] = F_40 ;
if ( V_2 -> V_31 & V_64 )
V_2 -> V_65 [ V_57 ] = F_30 ;
}
}
if ( V_55 >= V_20 -> V_56 . V_62 )
V_55 = 0 ;
if ( F_41 ( ! V_20 -> V_56 . V_63 ,
L_9 ) )
return - 1 ;
if ( V_73 < ( V_20 -> V_56 . V_76 * 5 ) / 4 &&
V_55 % V_20 -> V_56 . V_63 > V_20 -> V_56 . V_63 / 2 )
return V_2 -> V_79 ? 0 : - 1 ;
V_20 -> V_56 . V_75 += V_73 ;
return 1 ;
}
static void F_42 ( struct V_80 * V_81 )
{
struct V_67 * V_68 = F_35 ( V_81 , struct V_67 , V_71 ) ;
struct V_1 * V_2 = & V_68 -> V_2 ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_82 * V_83 ;
int V_84 , V_69 ;
if ( ! V_68 -> V_85 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_10 ,
V_2 -> V_33 -> V_86 ) ;
V_68 -> V_85 = 1 ;
}
for (; ; ) {
V_84 = 0 ;
F_43 ( & V_51 -> V_87 ) ;
F_44 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_45 ( V_83 ) ;
if ( ! V_20 -> V_70 ||
! V_83 -> V_22 ||
! V_83 -> V_88 )
continue;
V_69 = F_36 ( V_2 , V_20 ) ;
if ( V_69 > 0 ) {
V_20 -> V_70 = 0 ;
F_46 ( & V_51 -> V_87 ) ;
F_47 ( V_83 -> V_22 ) ;
F_48 ( & V_51 -> V_87 ) ;
} else if ( V_69 < 0 ) {
V_84 = 0 ;
} else
V_84 ++ ;
}
F_49 ( & V_51 -> V_87 ) ;
if ( ! V_84 )
return;
F_50 ( 1 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_82 * V_83 ;
F_43 ( & V_51 -> V_87 ) ;
F_44 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_45 ( V_83 ) ;
V_20 -> V_70 = 0 ;
}
F_49 ( & V_51 -> V_87 ) ;
}
static int F_52 ( struct V_1 * V_2 , int V_89 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
if ( F_53 ( V_2 -> V_25 -> V_90 , V_91 ,
V_2 -> V_92 ? 0 : V_93 ,
V_2 -> V_33 -> V_94 , V_2 ) ) {
F_54 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_90 ) ;
if ( V_89 )
F_55 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_51 -> V_90 = V_2 -> V_25 -> V_90 ;
F_56 ( V_2 -> V_25 , ! V_2 -> V_92 ) ;
return 0 ;
}
static unsigned int F_57 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_95 , V_96 , V_97 ;
unsigned int V_98 , V_99 , V_100 ;
unsigned int V_101 ;
V_95 = F_58 ( F_59 ( V_20 ) ) ;
if ( V_20 -> V_56 . V_22 -> V_57 == V_60 ) {
return V_95 ;
}
V_99 = F_60 ( * V_20 -> V_56 . V_102 ) ;
V_99 %= V_20 -> V_56 . V_63 ;
V_101 = F_61 ( F_23 ( V_2 ) -> V_103 +
V_104 ) ;
if ( V_20 -> V_105 ) {
if ( V_95 <= V_101 )
return 0 ;
V_20 -> V_105 = 0 ;
}
if ( V_95 <= V_101 )
V_96 = V_20 -> V_56 . V_62 + V_95 - V_101 ;
else
V_96 = V_95 - V_101 ;
V_100 = V_96 % V_20 -> V_56 . V_63 ;
V_98 = V_95 % V_20 -> V_56 . V_63 ;
if ( V_98 >= V_101 )
V_97 = V_95 - V_98 ;
else if ( V_99 >= V_100 )
V_97 = V_96 - V_100 ;
else {
V_97 = V_96 - V_100 + V_20 -> V_56 . V_63 ;
if ( V_97 >= V_20 -> V_56 . V_62 )
V_97 = 0 ;
}
return V_97 + V_99 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_63 ( & V_106 ) ;
F_64 ( & V_68 -> V_107 , & V_108 ) ;
F_65 ( & V_106 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_63 ( & V_106 ) ;
F_67 ( & V_68 -> V_107 ) ;
F_65 ( & V_106 ) ;
}
static int F_68 ( const char * V_28 , const struct V_109 * V_110 )
{
struct V_67 * V_68 ;
struct V_1 * V_2 ;
int V_111 = V_112 ;
int V_113 = F_69 ( V_28 , V_110 ) ;
if ( V_113 || V_111 == V_112 )
return V_113 ;
F_63 ( & V_106 ) ;
F_44 (hda, &card_list, list) {
V_2 = & V_68 -> V_2 ;
if ( ! V_68 -> V_114 || V_2 -> V_115 )
continue;
F_70 ( & V_2 -> V_51 , V_112 * 1000 ) ;
}
F_65 ( & V_106 ) ;
return 0 ;
}
static int F_71 ( struct V_116 * V_9 )
{
struct V_117 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
struct V_50 * V_51 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_118 || ! V_2 -> V_88 )
return 0 ;
V_51 = F_23 ( V_2 ) ;
F_73 ( V_33 , V_119 ) ;
F_51 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_51 -> V_90 >= 0 ) {
F_76 ( V_51 -> V_90 , V_2 ) ;
V_51 -> V_90 = - 1 ;
}
if ( V_2 -> V_92 )
F_77 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_120 )
F_39 ( V_51 , false ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_116 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
struct V_117 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_118 || ! V_2 -> V_88 )
return 0 ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_120 ) {
F_39 ( F_23 ( V_2 ) , true ) ;
F_81 ( F_23 ( V_2 ) ) ;
}
if ( V_2 -> V_92 )
if ( F_82 ( V_25 ) < 0 )
V_2 -> V_92 = 0 ;
if ( F_52 ( V_2 , 1 ) < 0 )
return - V_121 ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
F_73 ( V_33 , V_122 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_116 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
if ( F_25 ( V_25 ) )
F_85 ( V_25 , V_123 ) ;
return 0 ;
}
static int F_86 ( struct V_116 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
if ( F_25 ( V_25 ) )
F_85 ( V_25 , V_124 ) ;
return 0 ;
}
static int F_87 ( struct V_116 * V_9 )
{
struct V_117 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_118 )
return 0 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
F_89 ( V_2 , V_125 , F_90 ( V_2 , V_125 ) |
V_126 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_120 )
F_39 ( F_23 ( V_2 ) , false ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_116 * V_9 )
{
struct V_117 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
struct V_50 * V_51 ;
struct V_127 * V_128 ;
int V_129 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_118 )
return 0 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_52 ) {
V_51 = F_23 ( V_2 ) ;
if ( V_68 -> V_120 ) {
F_39 ( V_51 , true ) ;
F_81 ( V_51 ) ;
} else {
F_24 ( V_51 , true ) ;
F_24 ( V_51 , false ) ;
}
}
V_129 = F_90 ( V_2 , V_130 ) ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
if ( V_129 ) {
F_93 (codec, &chip->bus)
if ( V_129 & ( 1 << V_128 -> V_131 ) )
F_94 ( & V_128 -> V_132 ,
V_128 -> V_133 ) ;
}
F_89 ( V_2 , V_125 , F_90 ( V_2 , V_125 ) &
~ V_126 ) ;
F_95 ( V_2 ) ;
return 0 ;
}
static int F_96 ( struct V_116 * V_9 )
{
struct V_117 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_118 )
return 0 ;
if ( ! V_134 || ! F_88 ( V_2 ) ||
F_23 ( V_2 ) -> V_135 || ! V_2 -> V_88 )
return - V_136 ;
return 0 ;
}
static void F_97 ( struct V_24 * V_25 ,
enum V_137 V_138 )
{
struct V_117 * V_33 = F_98 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
bool V_115 ;
F_99 ( & V_68 -> V_139 ) ;
if ( V_68 -> V_118 )
return;
V_115 = ( V_138 == V_140 ) ;
if ( V_2 -> V_115 == V_115 )
return;
if ( ! V_68 -> V_114 ) {
V_2 -> V_115 = V_115 ;
if ( ! V_115 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_100 ( V_2 ) < 0 ) {
F_54 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_68 -> V_118 = true ;
}
}
} else {
F_32 ( V_2 -> V_33 -> V_9 , L_14 ,
V_115 ? L_15 : L_16 ) ;
if ( V_115 ) {
F_101 ( V_33 -> V_9 ) ;
F_71 ( V_33 -> V_9 ) ;
V_25 -> V_141 = V_142 ;
V_2 -> V_115 = true ;
if ( F_102 ( & V_2 -> V_51 ) )
F_103 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_104 ( & V_2 -> V_51 ) ;
F_105 ( V_33 -> V_9 ) ;
V_2 -> V_115 = false ;
F_79 ( V_33 -> V_9 ) ;
}
}
}
static bool F_106 ( struct V_24 * V_25 )
{
struct V_117 * V_33 = F_98 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_99 ( & V_68 -> V_139 ) ;
if ( V_68 -> V_118 )
return false ;
if ( V_2 -> V_115 || ! V_68 -> V_114 )
return true ;
if ( F_102 ( & V_2 -> V_51 ) )
return false ;
F_104 ( & V_2 -> V_51 ) ;
return true ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_24 * V_143 = F_108 ( V_2 -> V_25 ) ;
if ( V_143 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_68 -> V_144 = 1 ;
F_109 ( V_143 ) ;
}
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
int V_145 ;
if ( ! V_68 -> V_144 )
return 0 ;
V_145 = F_111 ( V_2 -> V_25 , & V_146 ,
V_147 ) ;
if ( V_145 < 0 )
return V_145 ;
V_68 -> V_148 = 1 ;
F_112 ( V_2 -> V_33 -> V_9 ,
& V_68 -> V_149 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
if ( F_88 ( V_2 ) && V_2 -> V_88 )
F_105 ( & V_25 -> V_9 ) ;
F_66 ( V_2 ) ;
V_68 -> V_118 = 1 ;
F_114 ( & V_68 -> V_139 ) ;
if ( V_144 ( V_68 ) ) {
if ( V_2 -> V_115 && V_68 -> V_114 )
F_104 ( & V_2 -> V_51 ) ;
if ( V_68 -> V_148 ) {
F_115 ( V_2 -> V_25 ) ;
F_116 ( V_2 -> V_33 -> V_9 ) ;
}
}
if ( V_51 -> V_150 ) {
F_51 ( V_2 ) ;
F_117 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_51 -> V_90 >= 0 )
F_76 ( V_51 -> V_90 , ( void * ) V_2 ) ;
if ( V_2 -> V_92 )
F_77 ( V_2 -> V_25 ) ;
F_118 ( V_51 -> V_103 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_51 ) ;
if ( V_2 -> V_151 )
F_122 ( V_2 -> V_25 ) ;
F_123 ( V_2 -> V_25 ) ;
#ifdef F_124
F_125 ( V_2 -> V_152 ) ;
#endif
if ( V_2 -> V_31 & V_52 ) {
if ( V_68 -> V_120 )
F_39 ( V_51 , false ) ;
F_126 ( V_51 ) ;
}
F_127 ( V_68 ) ;
return 0 ;
}
static int F_128 ( struct V_153 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_154 ;
V_2 -> V_51 . V_155 = 1 ;
return 0 ;
}
static int F_129 ( struct V_153 * V_116 )
{
return F_113 ( V_116 -> V_154 ) ;
}
static struct V_24 * F_108 ( struct V_24 * V_25 )
{
struct V_24 * V_143 ;
switch ( V_25 -> V_156 ) {
case V_157 :
case V_158 :
case V_159 :
if ( V_25 -> V_160 == 1 ) {
V_143 = F_130 ( F_131 ( V_25 -> V_51 ) ,
V_25 -> V_51 -> V_86 , 0 ) ;
if ( V_143 ) {
if ( ( V_143 -> V_161 >> 8 ) == V_162 )
return V_143 ;
F_109 ( V_143 ) ;
}
}
break;
}
return NULL ;
}
static bool F_132 ( struct V_24 * V_25 )
{
bool V_163 = false ;
struct V_24 * V_143 = F_108 ( V_25 ) ;
if ( V_143 ) {
if ( F_133 ( V_143 ) == V_140 )
V_163 = true ;
F_109 ( V_143 ) ;
}
return V_163 ;
}
static int F_134 ( struct V_1 * V_2 , int V_164 )
{
const struct V_165 * V_166 ;
switch ( V_164 ) {
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
return V_164 ;
}
V_166 = F_135 ( V_2 -> V_25 , V_172 ) ;
if ( V_166 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_166 -> V_173 , V_166 -> V_174 , V_166 -> V_175 ) ;
return V_166 -> V_173 ;
}
if ( V_2 -> V_14 == V_176 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_170 ;
}
if ( V_2 -> V_31 & V_177 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_168 ;
}
return V_167 ;
}
static void F_136 ( struct V_1 * V_2 , int V_164 )
{
static T_2 V_178 [] = {
[ V_167 ] = NULL ,
[ V_168 ] = F_31 ,
[ V_169 ] = F_40 ,
[ V_170 ] = F_57 ,
[ V_171 ] = F_31 ,
} ;
V_2 -> V_77 [ 0 ] = V_2 -> V_77 [ 1 ] = V_178 [ V_164 ] ;
if ( V_164 == V_171 )
V_2 -> V_77 [ 1 ] = NULL ;
if ( V_164 == V_169 &&
( V_2 -> V_31 & V_64 ) ) {
V_2 -> V_65 [ 0 ] = V_2 -> V_65 [ 1 ] =
F_30 ;
}
}
static void F_137 ( struct V_1 * V_2 , int V_9 )
{
const struct V_165 * V_166 ;
V_2 -> V_179 = V_180 [ V_9 ] ;
if ( V_2 -> V_179 == - 1 ) {
V_166 = F_135 ( V_2 -> V_25 , V_181 ) ;
if ( V_166 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_166 -> V_173 , V_166 -> V_174 , V_166 -> V_175 ) ;
V_2 -> V_179 = V_166 -> V_173 ;
}
}
if ( V_2 -> V_179 != - 1 &&
( V_2 -> V_179 & V_182 ) ) {
F_23 ( V_2 ) -> V_183 = V_2 -> V_179 & 0xff ;
F_32 ( V_2 -> V_33 -> V_9 , L_23 ,
( int ) F_23 ( V_2 ) -> V_183 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
const struct V_165 * V_166 ;
if ( V_184 >= 0 ) {
V_2 -> V_92 = ! ! V_184 ;
return;
}
V_2 -> V_92 = 1 ;
V_166 = F_135 ( V_2 -> V_25 , V_185 ) ;
if ( V_166 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_166 -> V_174 , V_166 -> V_175 , V_166 -> V_173 ) ;
V_2 -> V_92 = V_166 -> V_173 ;
return;
}
if ( V_2 -> V_31 & V_186 ) {
F_32 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_92 = 0 ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
int V_45 = V_187 ;
if ( V_45 >= 0 ) {
F_32 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_188 &&
V_2 -> V_14 == V_176 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_189 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_190 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_32 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_140 ( struct V_80 * V_81 )
{
struct V_67 * V_68 = F_35 ( V_81 , struct V_67 , V_191 ) ;
F_100 ( & V_68 -> V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_156 == V_192 ) {
switch ( V_2 -> V_25 -> V_116 ) {
case 0x0f04 :
case 0x2284 :
return 32 ;
}
}
switch ( V_2 -> V_14 ) {
case V_193 :
case V_194 :
return 1 ;
default:
return 32 ;
}
}
static int F_142 ( struct V_117 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_195 )
{
static struct V_196 V_197 = {
. V_198 = F_128 ,
. V_199 = F_129 ,
} ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
int V_145 ;
* V_195 = NULL ;
V_145 = F_143 ( V_25 ) ;
if ( V_145 < 0 )
return V_145 ;
V_68 = F_144 ( sizeof( * V_68 ) , V_200 ) ;
if ( ! V_68 ) {
F_123 ( V_25 ) ;
return - V_201 ;
}
V_2 = & V_68 -> V_2 ;
F_145 ( & V_2 -> V_202 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_197 = & V_203 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_138 ( V_2 ) ;
V_2 -> V_204 = V_9 ;
V_2 -> V_205 = V_205 ;
F_146 ( & V_2 -> V_206 ) ;
F_147 ( & V_68 -> V_71 , F_42 ) ;
F_146 ( & V_68 -> V_107 ) ;
F_107 ( V_2 ) ;
F_148 ( & V_68 -> V_139 ) ;
F_136 ( V_2 , F_134 ( V_2 , V_207 [ V_9 ] ) ) ;
F_137 ( V_2 , V_9 ) ;
V_2 -> V_208 = V_208 ;
F_139 ( V_2 ) ;
if ( V_79 [ V_9 ] < 0 )
V_2 -> V_79 = F_141 ( V_2 ) ;
else
V_2 -> V_79 = V_79 [ V_9 ] ;
V_145 = F_149 ( V_2 , V_209 [ V_9 ] , & V_210 ) ;
if ( V_145 < 0 ) {
F_127 ( V_68 ) ;
F_123 ( V_25 ) ;
return V_145 ;
}
if ( V_2 -> V_14 == V_211 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_30 ) ;
V_2 -> V_51 . V_212 = 1 ;
}
V_145 = F_150 ( V_33 , V_213 , V_2 , & V_197 ) ;
if ( V_145 < 0 ) {
F_54 ( V_33 -> V_9 , L_31 ) ;
F_113 ( V_2 ) ;
return V_145 ;
}
F_147 ( & V_68 -> V_191 , F_140 ) ;
* V_195 = V_2 ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_204 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_117 * V_33 = V_2 -> V_33 ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_145 ;
unsigned short V_214 ;
unsigned int V_215 = 64 ;
#if V_216 != 64
if ( V_2 -> V_14 == V_217 ) {
T_4 V_218 ;
F_17 ( V_25 , 0x40 , & V_218 ) ;
F_18 ( V_25 , 0x40 , V_218 | 0x10 ) ;
F_27 ( V_25 , V_219 , 0 ) ;
}
#endif
V_145 = F_152 ( V_25 , L_32 ) ;
if ( V_145 < 0 )
return V_145 ;
V_2 -> V_151 = 1 ;
V_51 -> V_131 = F_153 ( V_25 , 0 ) ;
V_51 -> V_103 = F_154 ( V_25 , 0 ) ;
if ( V_51 -> V_103 == NULL ) {
F_54 ( V_33 -> V_9 , L_33 ) ;
return - V_220 ;
}
if ( V_2 -> V_92 ) {
if ( V_2 -> V_31 & V_221 ) {
F_16 ( V_33 -> V_9 , L_34 ) ;
V_25 -> V_222 = true ;
}
if ( F_82 ( V_25 ) < 0 )
V_2 -> V_92 = 0 ;
}
if ( F_52 ( V_2 , 0 ) < 0 )
return - V_136 ;
F_155 ( V_25 ) ;
F_156 ( V_51 -> V_90 ) ;
V_214 = F_90 ( V_2 , V_223 ) ;
F_16 ( V_33 -> V_9 , L_35 , V_214 ) ;
if ( V_2 -> V_25 -> V_156 == V_158 )
V_215 = 40 ;
if ( V_2 -> V_25 -> V_156 == V_157 ) {
struct V_24 * V_224 ;
V_215 = 40 ;
V_224 = F_157 ( V_157 ,
V_225 ,
NULL ) ;
if ( V_224 ) {
if ( V_224 -> V_189 < 0x30 )
V_214 &= ~ V_226 ;
F_109 ( V_224 ) ;
}
}
if ( V_2 -> V_31 & V_227 ) {
F_16 ( V_33 -> V_9 , L_36 ) ;
V_214 &= ~ V_226 ;
}
if ( V_228 >= 0 )
V_2 -> V_228 = ! ! V_228 ;
else {
if ( V_2 -> V_31 & V_229 )
V_2 -> V_228 = 0 ;
else
V_2 -> V_228 = 1 ;
}
if ( ! ( V_214 & V_226 ) )
V_215 = 32 ;
if ( ! F_158 ( & V_25 -> V_9 , F_159 ( V_215 ) ) ) {
F_160 ( & V_25 -> V_9 , F_159 ( V_215 ) ) ;
} else {
F_158 ( & V_25 -> V_9 , F_159 ( 32 ) ) ;
F_160 ( & V_25 -> V_9 , F_159 ( 32 ) ) ;
}
V_2 -> V_230 = ( V_214 >> 8 ) & 0x0f ;
V_2 -> V_231 = ( V_214 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_231 && ! V_2 -> V_230 ) {
switch ( V_2 -> V_14 ) {
case V_217 :
V_2 -> V_231 = V_232 ;
V_2 -> V_230 = V_233 ;
break;
case V_234 :
case V_235 :
V_2 -> V_231 = V_236 ;
V_2 -> V_230 = V_237 ;
break;
case V_238 :
default:
V_2 -> V_231 = V_239 ;
V_2 -> V_230 = V_240 ;
break;
}
}
V_2 -> V_241 = 0 ;
V_2 -> V_242 = V_2 -> V_230 ;
V_2 -> V_243 = V_2 -> V_231 + V_2 -> V_230 ;
V_145 = F_161 ( V_2 ) ;
if ( V_145 < 0 )
return V_145 ;
V_145 = F_162 ( V_2 ) ;
if ( V_145 < 0 )
return V_145 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_52 )
F_81 ( V_51 ) ;
F_22 ( V_2 , ( V_244 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_23 ( V_2 ) -> V_183 ) {
F_54 ( V_33 -> V_9 , L_37 ) ;
return - V_245 ;
}
strcpy ( V_33 -> V_246 , L_38 ) ;
F_163 ( V_33 -> V_247 , V_248 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_247 ) ) ;
snprintf ( V_33 -> V_249 , sizeof( V_33 -> V_249 ) ,
L_39 ,
V_33 -> V_247 , V_51 -> V_131 , V_51 -> V_90 ) ;
return 0 ;
}
static void F_164 ( const struct V_250 * V_152 , void * V_251 )
{
struct V_117 * V_33 = V_251 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_152 ) {
F_54 ( V_33 -> V_9 , L_40 ) ;
goto error;
}
V_2 -> V_152 = V_152 ;
if ( ! V_2 -> V_115 ) {
if ( F_100 ( V_2 ) )
goto error;
}
return;
error:
F_165 ( V_33 ) ;
F_166 ( V_25 , NULL ) ;
}
static void F_167 ( T_1 V_173 , T_1 T_5 * V_131 )
{
F_168 ( V_173 , V_131 ) ;
}
static T_1 F_169 ( T_1 T_5 * V_131 )
{
return F_170 ( V_131 ) ;
}
static void F_171 ( T_4 V_173 , T_4 T_5 * V_131 )
{
F_172 ( V_173 , V_131 ) ;
}
static T_4 F_173 ( T_4 T_5 * V_131 )
{
return F_61 ( V_131 ) ;
}
static void F_174 ( T_3 V_173 , T_3 T_5 * V_131 )
{
F_175 ( V_173 , V_131 ) ;
}
static T_3 F_176 ( T_3 T_5 * V_131 )
{
return F_177 ( V_131 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_145 ;
F_76 ( V_51 -> V_90 , V_2 ) ;
V_51 -> V_90 = - 1 ;
F_77 ( V_2 -> V_25 ) ;
V_2 -> V_92 = 0 ;
V_145 = F_52 ( V_2 , 1 ) ;
if ( V_145 < 0 )
return V_145 ;
return 0 ;
}
static int F_179 ( struct V_50 * V_51 ,
int type ,
T_6 V_252 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_180 ( V_51 ) ;
int V_145 ;
V_145 = F_181 ( type ,
V_51 -> V_9 ,
V_252 , V_19 ) ;
if ( V_145 < 0 )
return V_145 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_182 ( struct V_50 * V_51 , struct V_3 * V_19 )
{
struct V_1 * V_2 = F_180 ( V_51 ) ;
F_8 ( V_2 , V_19 , false ) ;
F_183 ( V_19 ) ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_252 )
{
struct V_20 * V_20 = F_185 ( V_22 ) ;
int V_113 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_113 = F_186 ( V_22 , V_252 ) ;
if ( V_113 < 0 )
return V_113 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_185 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_188 ( V_22 ) ;
}
static void F_189 ( struct V_21 * V_22 ,
struct V_253 * V_7 )
{
#ifdef F_190
struct V_254 * V_255 = F_191 ( V_22 ) ;
struct V_1 * V_2 = V_255 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_256 = F_192 ( V_7 -> V_256 ) ;
#endif
}
static int F_193 ( struct V_24 * V_25 ,
const struct V_257 * V_258 )
{
static int V_9 ;
struct V_117 * V_33 ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
bool V_259 ;
int V_145 ;
if ( V_9 >= V_260 )
return - V_245 ;
if ( ! V_72 [ V_9 ] ) {
V_9 ++ ;
return - V_261 ;
}
V_145 = F_194 ( & V_25 -> V_9 , V_262 [ V_9 ] , V_263 [ V_9 ] , V_264 ,
0 , & V_33 ) ;
if ( V_145 < 0 ) {
F_54 ( & V_25 -> V_9 , L_41 ) ;
return V_145 ;
}
V_145 = F_142 ( V_33 , V_25 , V_9 , V_258 -> V_265 , & V_2 ) ;
if ( V_145 < 0 )
goto V_266;
V_33 -> V_13 = V_2 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_166 ( V_25 , V_33 ) ;
V_145 = F_110 ( V_2 ) ;
if ( V_145 < 0 ) {
F_54 ( V_33 -> V_9 , L_42 ) ;
goto V_266;
}
if ( F_132 ( V_25 ) ) {
F_32 ( V_33 -> V_9 , L_43 ) ;
F_32 ( V_33 -> V_9 , L_44 ) ;
V_2 -> V_115 = true ;
}
V_259 = ! V_2 -> V_115 ;
#ifdef F_124
if ( V_267 [ V_9 ] && * V_267 [ V_9 ] ) {
F_32 ( V_33 -> V_9 , L_45 ,
V_267 [ V_9 ] ) ;
V_145 = F_195 ( V_264 , true , V_267 [ V_9 ] ,
& V_25 -> V_9 , V_200 , V_33 ,
F_164 ) ;
if ( V_145 < 0 )
goto V_266;
V_259 = false ;
}
#endif
#ifndef F_196
if ( F_197 ( V_25 ) )
F_54 ( V_33 -> V_9 , L_46 ) ;
#endif
if ( V_259 )
F_37 ( & V_68 -> V_191 ) ;
V_9 ++ ;
if ( V_2 -> V_115 )
F_114 ( & V_68 -> V_139 ) ;
return 0 ;
V_266:
F_165 ( V_33 ) ;
return V_145 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_204 ;
int V_145 ;
V_68 -> V_114 = 1 ;
if ( V_2 -> V_31 & V_52 ) {
if ( F_197 ( V_25 ) )
V_68 -> V_120 = 1 ;
V_145 = F_198 ( V_51 ) ;
if ( V_145 < 0 ) {
if ( F_197 ( V_25 ) ) {
F_54 ( V_2 -> V_33 -> V_9 ,
L_47 ) ;
goto V_266;
} else
goto V_268;
}
V_145 = F_39 ( V_51 , true ) ;
if ( V_145 < 0 ) {
F_54 ( V_2 -> V_33 -> V_9 ,
L_48 ) ;
goto V_269;
}
}
V_268:
V_145 = F_151 ( V_2 ) ;
if ( V_145 < 0 )
goto V_266;
#ifdef F_199
V_2 -> V_270 = V_270 [ V_9 ] ;
#endif
V_145 = F_200 ( V_2 , V_271 [ V_2 -> V_14 ] ) ;
if ( V_145 < 0 )
goto V_266;
#ifdef F_124
if ( V_2 -> V_152 ) {
V_145 = F_201 ( & V_2 -> V_51 , V_2 -> V_152 -> V_252 ,
V_2 -> V_152 -> V_29 ) ;
if ( V_145 < 0 )
goto V_266;
#ifndef F_202
F_125 ( V_2 -> V_152 ) ;
V_2 -> V_152 = NULL ;
#endif
}
#endif
if ( ( V_244 [ V_9 ] & 1 ) == 0 ) {
V_145 = F_203 ( V_2 ) ;
if ( V_145 < 0 )
goto V_266;
}
V_145 = F_204 ( V_2 -> V_33 ) ;
if ( V_145 < 0 )
goto V_266;
V_2 -> V_88 = 1 ;
F_62 ( V_2 ) ;
F_70 ( & V_2 -> V_51 , V_112 * 1000 ) ;
if ( F_88 ( V_2 ) || V_68 -> V_144 )
F_205 ( & V_25 -> V_9 ) ;
V_266:
if ( V_2 -> V_31 & V_52
&& ! V_68 -> V_120 )
F_39 ( V_51 , false ) ;
V_269:
if ( V_145 < 0 )
V_68 -> V_118 = 1 ;
F_114 ( & V_68 -> V_139 ) ;
return V_145 ;
}
static void F_206 ( struct V_24 * V_25 )
{
struct V_117 * V_33 = F_98 ( V_25 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( V_33 ) {
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_207 ( & V_68 -> V_191 ) ;
F_165 ( V_33 ) ;
}
}
static void F_208 ( struct V_24 * V_25 )
{
struct V_117 * V_33 = F_98 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_88 )
F_74 ( V_2 ) ;
}
