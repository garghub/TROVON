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
static void F_71 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = & V_68 -> V_2 ;
int V_116 ;
unsigned int V_117 , V_118 ;
if ( ! V_68 -> V_119 )
return;
V_116 = F_72 ( F_23 ( V_2 ) ) ;
switch ( V_116 ) {
case 337500 :
V_117 = 16 ;
V_118 = 225 ;
break;
case 450000 :
default:
V_117 = 4 ;
V_118 = 75 ;
break;
case 540000 :
V_117 = 4 ;
V_118 = 90 ;
break;
case 675000 :
V_117 = 8 ;
V_118 = 225 ;
break;
}
F_73 ( V_2 , V_120 , V_117 ) ;
F_73 ( V_2 , V_121 , V_118 ) ;
}
static int F_74 ( struct V_122 * V_9 )
{
struct V_123 * V_33 = F_75 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
struct V_50 * V_51 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_124 || ! V_2 -> V_88 )
return 0 ;
V_51 = F_23 ( V_2 ) ;
F_76 ( V_33 , V_125 ) ;
F_51 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_51 -> V_90 >= 0 ) {
F_79 ( V_51 -> V_90 , V_2 ) ;
V_51 -> V_90 = - 1 ;
}
if ( V_2 -> V_92 )
F_80 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_119 )
F_39 ( V_51 , false ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_122 * V_9 )
{
struct V_24 * V_25 = F_83 ( V_9 ) ;
struct V_123 * V_33 = F_75 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_124 || ! V_2 -> V_88 )
return 0 ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_119 ) {
F_39 ( F_23 ( V_2 ) , true ) ;
F_71 ( V_68 ) ;
}
if ( V_2 -> V_92 )
if ( F_84 ( V_25 ) < 0 )
V_2 -> V_92 = 0 ;
if ( F_52 ( V_2 , 1 ) < 0 )
return - V_126 ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
F_76 ( V_33 , V_127 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_122 * V_9 )
{
struct V_24 * V_25 = F_83 ( V_9 ) ;
if ( F_25 ( V_25 ) )
F_87 ( V_25 , V_128 ) ;
return 0 ;
}
static int F_88 ( struct V_122 * V_9 )
{
struct V_24 * V_25 = F_83 ( V_9 ) ;
if ( F_25 ( V_25 ) )
F_87 ( V_25 , V_129 ) ;
return 0 ;
}
static int F_89 ( struct V_122 * V_9 )
{
struct V_123 * V_33 = F_75 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_124 )
return 0 ;
if ( ! F_90 ( V_2 ) )
return 0 ;
F_73 ( V_2 , V_130 , F_91 ( V_2 , V_130 ) |
V_131 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_31 & V_52
&& V_68 -> V_119 )
F_39 ( F_23 ( V_2 ) , false ) ;
F_92 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_122 * V_9 )
{
struct V_123 * V_33 = F_75 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
struct V_50 * V_51 ;
struct V_132 * V_133 ;
int V_134 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_124 )
return 0 ;
if ( ! F_90 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_52 ) {
V_51 = F_23 ( V_2 ) ;
if ( V_68 -> V_119 ) {
F_39 ( V_51 , true ) ;
F_71 ( V_68 ) ;
} else {
F_24 ( V_51 , true ) ;
F_24 ( V_51 , false ) ;
}
}
V_134 = F_91 ( V_2 , V_135 ) ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
if ( V_134 ) {
F_94 (codec, &chip->bus)
if ( V_134 & ( 1 << V_133 -> V_136 ) )
F_95 ( & V_133 -> V_137 ,
V_133 -> V_138 ) ;
}
F_73 ( V_2 , V_130 , F_91 ( V_2 , V_130 ) &
~ V_131 ) ;
F_96 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_122 * V_9 )
{
struct V_123 * V_33 = F_75 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
if ( V_2 -> V_115 || V_68 -> V_124 )
return 0 ;
if ( ! V_139 || ! F_90 ( V_2 ) ||
F_23 ( V_2 ) -> V_140 || ! V_2 -> V_88 )
return - V_141 ;
return 0 ;
}
static void F_98 ( struct V_24 * V_25 ,
enum V_142 V_143 )
{
struct V_123 * V_33 = F_99 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
bool V_115 ;
F_100 ( & V_68 -> V_144 ) ;
if ( V_68 -> V_124 )
return;
V_115 = ( V_143 == V_145 ) ;
if ( V_2 -> V_115 == V_115 )
return;
if ( ! V_68 -> V_114 ) {
V_2 -> V_115 = V_115 ;
if ( ! V_115 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_101 ( V_2 ) < 0 ) {
F_54 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_68 -> V_124 = true ;
}
}
} else {
F_32 ( V_2 -> V_33 -> V_9 , L_14 ,
V_115 ? L_15 : L_16 ) ;
if ( V_115 ) {
F_102 ( V_33 -> V_9 ) ;
F_74 ( V_33 -> V_9 ) ;
V_25 -> V_146 = V_147 ;
V_2 -> V_115 = true ;
if ( F_103 ( & V_2 -> V_51 ) )
F_104 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_105 ( & V_2 -> V_51 ) ;
F_106 ( V_33 -> V_9 ) ;
V_2 -> V_115 = false ;
F_82 ( V_33 -> V_9 ) ;
}
}
}
static bool F_107 ( struct V_24 * V_25 )
{
struct V_123 * V_33 = F_99 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_100 ( & V_68 -> V_144 ) ;
if ( V_68 -> V_124 )
return false ;
if ( V_2 -> V_115 || ! V_68 -> V_114 )
return true ;
if ( F_103 ( & V_2 -> V_51 ) )
return false ;
F_105 ( & V_2 -> V_51 ) ;
return true ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_24 * V_148 = F_109 ( V_2 -> V_25 ) ;
if ( V_148 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_68 -> V_149 = 1 ;
F_110 ( V_148 ) ;
}
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
int V_150 ;
if ( ! V_68 -> V_149 )
return 0 ;
V_150 = F_112 ( V_2 -> V_25 , & V_151 ,
V_152 ) ;
if ( V_150 < 0 )
return V_150 ;
V_68 -> V_153 = 1 ;
F_113 ( V_2 -> V_33 -> V_9 ,
& V_68 -> V_154 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
if ( F_90 ( V_2 ) && V_2 -> V_88 )
F_106 ( & V_25 -> V_9 ) ;
F_66 ( V_2 ) ;
V_68 -> V_124 = 1 ;
F_115 ( & V_68 -> V_144 ) ;
if ( V_149 ( V_68 ) ) {
if ( V_2 -> V_115 && V_68 -> V_114 )
F_105 ( & V_2 -> V_51 ) ;
if ( V_68 -> V_153 )
F_116 ( V_2 -> V_25 ) ;
}
if ( V_51 -> V_155 ) {
F_51 ( V_2 ) ;
F_117 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_51 -> V_90 >= 0 )
F_79 ( V_51 -> V_90 , ( void * ) V_2 ) ;
if ( V_2 -> V_92 )
F_80 ( V_2 -> V_25 ) ;
F_118 ( V_51 -> V_103 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_51 ) ;
if ( V_2 -> V_156 )
F_122 ( V_2 -> V_25 ) ;
F_123 ( V_2 -> V_25 ) ;
#ifdef F_124
F_125 ( V_2 -> V_157 ) ;
#endif
if ( V_2 -> V_31 & V_52 ) {
if ( V_68 -> V_119 )
F_39 ( V_51 , false ) ;
F_126 ( V_51 ) ;
}
F_127 ( V_68 ) ;
return 0 ;
}
static int F_128 ( struct V_158 * V_122 )
{
struct V_1 * V_2 = V_122 -> V_159 ;
V_2 -> V_51 . V_160 = 1 ;
return 0 ;
}
static int F_129 ( struct V_158 * V_122 )
{
return F_114 ( V_122 -> V_159 ) ;
}
static struct V_24 * F_109 ( struct V_24 * V_25 )
{
struct V_24 * V_148 ;
switch ( V_25 -> V_161 ) {
case V_162 :
case V_163 :
case V_164 :
if ( V_25 -> V_165 == 1 ) {
V_148 = F_130 ( F_131 ( V_25 -> V_51 ) ,
V_25 -> V_51 -> V_86 , 0 ) ;
if ( V_148 ) {
if ( ( V_148 -> V_166 >> 8 ) == V_167 )
return V_148 ;
F_110 ( V_148 ) ;
}
}
break;
}
return NULL ;
}
static bool F_132 ( struct V_24 * V_25 )
{
bool V_168 = false ;
struct V_24 * V_148 = F_109 ( V_25 ) ;
if ( V_148 ) {
if ( F_133 ( V_148 ) == V_145 )
V_168 = true ;
F_110 ( V_148 ) ;
}
return V_168 ;
}
static int F_134 ( struct V_1 * V_2 , int V_169 )
{
const struct V_170 * V_171 ;
switch ( V_169 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
return V_169 ;
}
V_171 = F_135 ( V_2 -> V_25 , V_177 ) ;
if ( V_171 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_171 -> V_178 , V_171 -> V_179 , V_171 -> V_180 ) ;
return V_171 -> V_178 ;
}
if ( V_2 -> V_14 == V_181 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_175 ;
}
if ( V_2 -> V_31 & V_182 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_173 ;
}
return V_172 ;
}
static void F_136 ( struct V_1 * V_2 , int V_169 )
{
static T_2 V_183 [] = {
[ V_172 ] = NULL ,
[ V_173 ] = F_31 ,
[ V_174 ] = F_40 ,
[ V_175 ] = F_57 ,
[ V_176 ] = F_31 ,
} ;
V_2 -> V_77 [ 0 ] = V_2 -> V_77 [ 1 ] = V_183 [ V_169 ] ;
if ( V_169 == V_176 )
V_2 -> V_77 [ 1 ] = NULL ;
if ( V_169 == V_174 &&
( V_2 -> V_31 & V_64 ) ) {
V_2 -> V_65 [ 0 ] = V_2 -> V_65 [ 1 ] =
F_30 ;
}
}
static void F_137 ( struct V_1 * V_2 , int V_9 )
{
const struct V_170 * V_171 ;
V_2 -> V_184 = V_185 [ V_9 ] ;
if ( V_2 -> V_184 == - 1 ) {
V_171 = F_135 ( V_2 -> V_25 , V_186 ) ;
if ( V_171 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_171 -> V_178 , V_171 -> V_179 , V_171 -> V_180 ) ;
V_2 -> V_184 = V_171 -> V_178 ;
}
}
if ( V_2 -> V_184 != - 1 &&
( V_2 -> V_184 & V_187 ) ) {
F_23 ( V_2 ) -> V_188 = V_2 -> V_184 & 0xff ;
F_32 ( V_2 -> V_33 -> V_9 , L_23 ,
( int ) F_23 ( V_2 ) -> V_188 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
const struct V_170 * V_171 ;
if ( V_189 >= 0 ) {
V_2 -> V_92 = ! ! V_189 ;
return;
}
V_2 -> V_92 = 1 ;
V_171 = F_135 ( V_2 -> V_25 , V_190 ) ;
if ( V_171 ) {
F_32 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_171 -> V_179 , V_171 -> V_180 , V_171 -> V_178 ) ;
V_2 -> V_92 = V_171 -> V_178 ;
return;
}
if ( V_2 -> V_31 & V_191 ) {
F_32 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_92 = 0 ;
}
}
static void F_139 ( struct V_1 * V_2 )
{
int V_45 = V_192 ;
if ( V_45 >= 0 ) {
F_32 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_193 &&
V_2 -> V_14 == V_181 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_194 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_195 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_32 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_140 ( struct V_80 * V_81 )
{
struct V_67 * V_68 = F_35 ( V_81 , struct V_67 , V_196 ) ;
F_101 ( & V_68 -> V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_161 == V_197 ) {
switch ( V_2 -> V_25 -> V_122 ) {
case 0x0f04 :
case 0x2284 :
return 32 ;
}
}
switch ( V_2 -> V_14 ) {
case V_198 :
case V_199 :
return 1 ;
default:
return 32 ;
}
}
static int F_142 ( struct V_123 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_200 )
{
static struct V_201 V_202 = {
. V_203 = F_128 ,
. V_204 = F_129 ,
} ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
int V_150 ;
* V_200 = NULL ;
V_150 = F_143 ( V_25 ) ;
if ( V_150 < 0 )
return V_150 ;
V_68 = F_144 ( sizeof( * V_68 ) , V_205 ) ;
if ( ! V_68 ) {
F_123 ( V_25 ) ;
return - V_206 ;
}
V_2 = & V_68 -> V_2 ;
F_145 ( & V_2 -> V_207 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_202 = & V_208 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_138 ( V_2 ) ;
V_2 -> V_209 = V_9 ;
V_2 -> V_210 = V_210 ;
F_146 ( & V_2 -> V_211 ) ;
F_147 ( & V_68 -> V_71 , F_42 ) ;
F_146 ( & V_68 -> V_107 ) ;
F_108 ( V_2 ) ;
F_148 ( & V_68 -> V_144 ) ;
F_136 ( V_2 , F_134 ( V_2 , V_212 [ V_9 ] ) ) ;
F_137 ( V_2 , V_9 ) ;
V_2 -> V_213 = V_213 ;
F_139 ( V_2 ) ;
if ( V_79 [ V_9 ] < 0 )
V_2 -> V_79 = F_141 ( V_2 ) ;
else
V_2 -> V_79 = V_79 [ V_9 ] ;
V_150 = F_149 ( V_2 , V_214 [ V_9 ] , & V_215 ) ;
if ( V_150 < 0 ) {
F_127 ( V_68 ) ;
F_123 ( V_25 ) ;
return V_150 ;
}
if ( V_2 -> V_14 == V_216 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_30 ) ;
V_2 -> V_51 . V_217 = 1 ;
}
V_150 = F_150 ( V_33 , V_218 , V_2 , & V_202 ) ;
if ( V_150 < 0 ) {
F_54 ( V_33 -> V_9 , L_31 ) ;
F_114 ( V_2 ) ;
return V_150 ;
}
F_147 ( & V_68 -> V_196 , F_140 ) ;
* V_200 = V_2 ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_209 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_123 * V_33 = V_2 -> V_33 ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_150 ;
unsigned short V_219 ;
unsigned int V_220 = 64 ;
#if V_221 != 64
if ( V_2 -> V_14 == V_222 ) {
T_4 V_223 ;
F_17 ( V_25 , 0x40 , & V_223 ) ;
F_18 ( V_25 , 0x40 , V_223 | 0x10 ) ;
F_27 ( V_25 , V_224 , 0 ) ;
}
#endif
V_150 = F_152 ( V_25 , L_32 ) ;
if ( V_150 < 0 )
return V_150 ;
V_2 -> V_156 = 1 ;
V_51 -> V_136 = F_153 ( V_25 , 0 ) ;
V_51 -> V_103 = F_154 ( V_25 , 0 ) ;
if ( V_51 -> V_103 == NULL ) {
F_54 ( V_33 -> V_9 , L_33 ) ;
return - V_225 ;
}
if ( V_2 -> V_92 ) {
if ( V_2 -> V_31 & V_226 ) {
F_16 ( V_33 -> V_9 , L_34 ) ;
V_25 -> V_227 = true ;
}
if ( F_84 ( V_25 ) < 0 )
V_2 -> V_92 = 0 ;
}
if ( F_52 ( V_2 , 0 ) < 0 )
return - V_141 ;
F_155 ( V_25 ) ;
F_156 ( V_51 -> V_90 ) ;
V_219 = F_91 ( V_2 , V_228 ) ;
F_16 ( V_33 -> V_9 , L_35 , V_219 ) ;
if ( V_2 -> V_25 -> V_161 == V_163 )
V_220 = 40 ;
if ( V_2 -> V_25 -> V_161 == V_162 ) {
struct V_24 * V_229 ;
V_220 = 40 ;
V_229 = F_157 ( V_162 ,
V_230 ,
NULL ) ;
if ( V_229 ) {
if ( V_229 -> V_194 < 0x30 )
V_219 &= ~ V_231 ;
F_110 ( V_229 ) ;
}
}
if ( V_2 -> V_31 & V_232 ) {
F_16 ( V_33 -> V_9 , L_36 ) ;
V_219 &= ~ V_231 ;
}
if ( V_233 >= 0 )
V_2 -> V_233 = ! ! V_233 ;
else {
if ( V_2 -> V_31 & V_234 )
V_2 -> V_233 = 0 ;
else
V_2 -> V_233 = 1 ;
}
if ( ! ( V_219 & V_231 ) )
V_220 = 32 ;
if ( ! F_158 ( & V_25 -> V_9 , F_159 ( V_220 ) ) ) {
F_160 ( & V_25 -> V_9 , F_159 ( V_220 ) ) ;
} else {
F_158 ( & V_25 -> V_9 , F_159 ( 32 ) ) ;
F_160 ( & V_25 -> V_9 , F_159 ( 32 ) ) ;
}
V_2 -> V_235 = ( V_219 >> 8 ) & 0x0f ;
V_2 -> V_236 = ( V_219 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_236 && ! V_2 -> V_235 ) {
switch ( V_2 -> V_14 ) {
case V_222 :
V_2 -> V_236 = V_237 ;
V_2 -> V_235 = V_238 ;
break;
case V_239 :
case V_240 :
V_2 -> V_236 = V_241 ;
V_2 -> V_235 = V_242 ;
break;
case V_243 :
default:
V_2 -> V_236 = V_244 ;
V_2 -> V_235 = V_245 ;
break;
}
}
V_2 -> V_246 = 0 ;
V_2 -> V_247 = V_2 -> V_235 ;
V_2 -> V_248 = V_2 -> V_236 + V_2 -> V_235 ;
V_150 = F_161 ( V_2 ) ;
if ( V_150 < 0 )
return V_150 ;
V_150 = F_162 ( V_2 ) ;
if ( V_150 < 0 )
return V_150 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_52 ) {
struct V_67 * V_68 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_71 ( V_68 ) ;
}
F_22 ( V_2 , ( V_249 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_23 ( V_2 ) -> V_188 ) {
F_54 ( V_33 -> V_9 , L_37 ) ;
return - V_250 ;
}
strcpy ( V_33 -> V_251 , L_38 ) ;
F_163 ( V_33 -> V_252 , V_253 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_252 ) ) ;
snprintf ( V_33 -> V_254 , sizeof( V_33 -> V_254 ) ,
L_39 ,
V_33 -> V_252 , V_51 -> V_136 , V_51 -> V_90 ) ;
return 0 ;
}
static void F_164 ( const struct V_255 * V_157 , void * V_256 )
{
struct V_123 * V_33 = V_256 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_157 ) {
F_54 ( V_33 -> V_9 , L_40 ) ;
goto error;
}
V_2 -> V_157 = V_157 ;
if ( ! V_2 -> V_115 ) {
if ( F_101 ( V_2 ) )
goto error;
}
return;
error:
F_165 ( V_33 ) ;
F_166 ( V_25 , NULL ) ;
}
static void F_167 ( T_1 V_178 , T_1 T_5 * V_136 )
{
F_168 ( V_178 , V_136 ) ;
}
static T_1 F_169 ( T_1 T_5 * V_136 )
{
return F_170 ( V_136 ) ;
}
static void F_171 ( T_4 V_178 , T_4 T_5 * V_136 )
{
F_172 ( V_178 , V_136 ) ;
}
static T_4 F_173 ( T_4 T_5 * V_136 )
{
return F_61 ( V_136 ) ;
}
static void F_174 ( T_3 V_178 , T_3 T_5 * V_136 )
{
F_175 ( V_178 , V_136 ) ;
}
static T_3 F_176 ( T_3 T_5 * V_136 )
{
return F_177 ( V_136 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_150 ;
F_79 ( V_51 -> V_90 , V_2 ) ;
V_51 -> V_90 = - 1 ;
F_80 ( V_2 -> V_25 ) ;
V_2 -> V_92 = 0 ;
V_150 = F_52 ( V_2 , 1 ) ;
if ( V_150 < 0 )
return V_150 ;
return 0 ;
}
static int F_179 ( struct V_50 * V_51 ,
int type ,
T_6 V_257 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_180 ( V_51 ) ;
int V_150 ;
V_150 = F_181 ( type ,
V_51 -> V_9 ,
V_257 , V_19 ) ;
if ( V_150 < 0 )
return V_150 ;
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
T_6 V_257 )
{
struct V_20 * V_20 = F_185 ( V_22 ) ;
int V_113 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_113 = F_186 ( V_22 , V_257 ) ;
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
struct V_258 * V_7 )
{
#ifdef F_190
struct V_259 * V_260 = F_191 ( V_22 ) ;
struct V_1 * V_2 = V_260 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_261 = F_192 ( V_7 -> V_261 ) ;
#endif
}
static int F_193 ( struct V_24 * V_25 ,
const struct V_262 * V_263 )
{
static int V_9 ;
struct V_123 * V_33 ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
bool V_264 ;
int V_150 ;
if ( V_9 >= V_265 )
return - V_250 ;
if ( ! V_72 [ V_9 ] ) {
V_9 ++ ;
return - V_266 ;
}
V_150 = F_194 ( & V_25 -> V_9 , V_267 [ V_9 ] , V_268 [ V_9 ] , V_269 ,
0 , & V_33 ) ;
if ( V_150 < 0 ) {
F_54 ( & V_25 -> V_9 , L_41 ) ;
return V_150 ;
}
V_150 = F_142 ( V_33 , V_25 , V_9 , V_263 -> V_270 , & V_2 ) ;
if ( V_150 < 0 )
goto V_271;
V_33 -> V_13 = V_2 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_166 ( V_25 , V_33 ) ;
V_150 = F_111 ( V_2 ) ;
if ( V_150 < 0 ) {
F_54 ( V_33 -> V_9 , L_42 ) ;
goto V_271;
}
if ( F_132 ( V_25 ) ) {
F_32 ( V_33 -> V_9 , L_43 ) ;
F_32 ( V_33 -> V_9 , L_44 ) ;
V_2 -> V_115 = true ;
}
V_264 = ! V_2 -> V_115 ;
#ifdef F_124
if ( V_272 [ V_9 ] && * V_272 [ V_9 ] ) {
F_32 ( V_33 -> V_9 , L_45 ,
V_272 [ V_9 ] ) ;
V_150 = F_195 ( V_269 , true , V_272 [ V_9 ] ,
& V_25 -> V_9 , V_205 , V_33 ,
F_164 ) ;
if ( V_150 < 0 )
goto V_271;
V_264 = false ;
}
#endif
#ifndef F_196
if ( F_197 ( V_25 ) )
F_54 ( V_33 -> V_9 , L_46 ) ;
#endif
if ( V_264 )
F_37 ( & V_68 -> V_196 ) ;
V_9 ++ ;
if ( V_2 -> V_115 )
F_115 ( & V_68 -> V_144 ) ;
return 0 ;
V_271:
F_165 ( V_33 ) ;
return V_150 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_209 ;
int V_150 ;
V_68 -> V_114 = 1 ;
if ( V_2 -> V_31 & V_52 ) {
if ( F_197 ( V_25 ) )
V_68 -> V_119 = 1 ;
V_150 = F_198 ( V_51 ) ;
if ( V_150 < 0 ) {
if ( F_197 ( V_25 ) ) {
F_54 ( V_2 -> V_33 -> V_9 ,
L_47 ) ;
goto V_271;
} else
goto V_273;
}
V_150 = F_39 ( V_51 , true ) ;
if ( V_150 < 0 ) {
F_54 ( V_2 -> V_33 -> V_9 ,
L_48 ) ;
goto V_274;
}
}
V_273:
V_150 = F_151 ( V_2 ) ;
if ( V_150 < 0 )
goto V_271;
#ifdef F_199
V_2 -> V_275 = V_275 [ V_9 ] ;
#endif
V_150 = F_200 ( V_2 , V_276 [ V_2 -> V_14 ] ) ;
if ( V_150 < 0 )
goto V_271;
#ifdef F_124
if ( V_2 -> V_157 ) {
V_150 = F_201 ( & V_2 -> V_51 , V_2 -> V_157 -> V_257 ,
V_2 -> V_157 -> V_29 ) ;
if ( V_150 < 0 )
goto V_271;
#ifndef F_202
F_125 ( V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
#endif
}
#endif
if ( ( V_249 [ V_9 ] & 1 ) == 0 ) {
V_150 = F_203 ( V_2 ) ;
if ( V_150 < 0 )
goto V_271;
}
V_150 = F_204 ( V_2 -> V_33 ) ;
if ( V_150 < 0 )
goto V_271;
V_2 -> V_88 = 1 ;
F_62 ( V_2 ) ;
F_70 ( & V_2 -> V_51 , V_112 * 1000 ) ;
if ( F_90 ( V_2 ) || V_68 -> V_149 )
F_205 ( & V_25 -> V_9 ) ;
V_271:
if ( V_2 -> V_31 & V_52
&& ! V_68 -> V_119 )
F_39 ( V_51 , false ) ;
V_274:
if ( V_150 < 0 )
V_68 -> V_124 = 1 ;
F_115 ( & V_68 -> V_144 ) ;
return V_150 ;
}
static void F_206 ( struct V_24 * V_25 )
{
struct V_123 * V_33 = F_99 ( V_25 ) ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
if ( V_33 ) {
V_2 = V_33 -> V_13 ;
V_68 = F_35 ( V_2 , struct V_67 , V_2 ) ;
F_207 ( & V_68 -> V_196 ) ;
F_165 ( V_33 ) ;
}
}
static void F_208 ( struct V_24 * V_25 )
{
struct V_123 * V_33 = F_99 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_88 )
F_77 ( V_2 ) ;
}
