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
static void F_19 ( struct V_1 * V_2 , bool V_48 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
if ( V_2 -> V_31 & V_51 )
F_21 ( V_50 , true ) ;
F_22 ( V_2 , V_48 ) ;
if ( V_2 -> V_31 & V_51 )
F_21 ( V_50 , false ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_52 )
{
struct V_21 * V_22 = V_20 -> V_53 . V_22 ;
int V_54 = V_22 -> V_54 ;
unsigned int V_55 = F_24 ( V_2 , V_20 ) ;
int V_56 ;
if ( V_54 == V_57 )
V_56 = V_52 - V_55 ;
else
V_56 = V_55 - V_52 ;
if ( V_56 < 0 ) {
if ( V_56 >= V_20 -> V_53 . V_58 )
V_56 = 0 ;
else
V_56 += V_20 -> V_53 . V_59 ;
}
if ( V_56 >= V_20 -> V_53 . V_60 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_7 ,
V_56 , V_20 -> V_53 . V_60 ) ;
V_56 = 0 ;
V_2 -> V_31 &= ~ V_61 ;
V_2 -> V_62 [ V_54 ] = NULL ;
}
return F_26 ( V_22 -> V_63 , V_56 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
int V_66 ;
V_66 = F_29 ( V_2 , V_20 ) ;
if ( V_66 == 1 ) {
V_20 -> V_67 = 0 ;
return V_66 ;
} else if ( V_66 == 0 ) {
V_20 -> V_67 = 1 ;
F_30 ( & V_65 -> V_68 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , bool V_69 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
return F_32 ( V_50 , V_69 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_53 . V_22 ;
int V_54 = V_22 -> V_54 ;
T_1 V_70 ;
unsigned int V_52 ;
V_70 = F_33 ( V_2 , V_71 ) - V_20 -> V_53 . V_72 ;
if ( V_70 < ( V_20 -> V_53 . V_73 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_74 [ V_54 ] )
V_52 = V_2 -> V_74 [ V_54 ] ( V_2 , V_20 ) ;
else {
V_52 = F_34 ( V_2 , V_20 ) ;
if ( ! V_52 || V_52 == ( T_1 ) - 1 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_8 ) ;
V_2 -> V_74 [ V_54 ] = F_24 ;
if ( V_2 -> V_74 [ 0 ] == F_24 &&
V_2 -> V_74 [ 1 ] == F_24 )
F_20 ( V_2 ) -> V_75 = false ;
V_52 = F_24 ( V_2 , V_20 ) ;
V_2 -> V_62 [ V_54 ] = NULL ;
} else {
V_2 -> V_74 [ V_54 ] = F_34 ;
if ( V_2 -> V_31 & V_61 )
V_2 -> V_62 [ V_54 ] = F_23 ;
}
}
if ( V_52 >= V_20 -> V_53 . V_59 )
V_52 = 0 ;
if ( F_35 ( ! V_20 -> V_53 . V_60 ,
L_9 ) )
return - 1 ;
if ( V_70 < ( V_20 -> V_53 . V_73 * 5 ) / 4 &&
V_52 % V_20 -> V_53 . V_60 > V_20 -> V_53 . V_60 / 2 )
return V_2 -> V_76 [ V_2 -> V_77 ] ? 0 : - 1 ;
V_20 -> V_53 . V_72 += V_70 ;
return 1 ;
}
static void F_36 ( struct V_78 * V_79 )
{
struct V_64 * V_65 = F_28 ( V_79 , struct V_64 , V_68 ) ;
struct V_1 * V_2 = & V_65 -> V_2 ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
struct V_80 * V_81 ;
int V_82 , V_66 ;
if ( ! V_65 -> V_83 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_10 ,
V_2 -> V_33 -> V_84 ) ;
V_65 -> V_83 = 1 ;
}
for (; ; ) {
V_82 = 0 ;
F_37 ( & V_50 -> V_85 ) ;
F_38 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_39 ( V_81 ) ;
if ( ! V_20 -> V_67 ||
! V_81 -> V_22 ||
! V_81 -> V_86 )
continue;
V_66 = F_29 ( V_2 , V_20 ) ;
if ( V_66 > 0 ) {
V_20 -> V_67 = 0 ;
F_40 ( & V_50 -> V_85 ) ;
F_41 ( V_81 -> V_22 ) ;
F_42 ( & V_50 -> V_85 ) ;
} else if ( V_66 < 0 ) {
V_82 = 0 ;
} else
V_82 ++ ;
}
F_43 ( & V_50 -> V_85 ) ;
if ( ! V_82 )
return;
F_44 ( 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
struct V_80 * V_81 ;
F_37 ( & V_50 -> V_85 ) ;
F_38 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_39 ( V_81 ) ;
V_20 -> V_67 = 0 ;
}
F_43 ( & V_50 -> V_85 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_87 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
if ( F_47 ( V_2 -> V_25 -> V_88 , V_89 ,
V_2 -> V_90 ? 0 : V_91 ,
V_92 , V_2 ) ) {
F_48 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_88 ) ;
if ( V_87 )
F_49 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_50 -> V_88 = V_2 -> V_25 -> V_88 ;
F_50 ( V_2 -> V_25 , ! V_2 -> V_90 ) ;
return 0 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_93 , V_94 , V_95 ;
unsigned int V_96 , V_97 , V_98 ;
unsigned int V_99 ;
V_93 = F_52 ( F_53 ( V_20 ) ) ;
if ( V_20 -> V_53 . V_22 -> V_54 == V_57 ) {
return V_93 ;
}
V_97 = F_54 ( * V_20 -> V_53 . V_100 ) ;
V_97 %= V_20 -> V_53 . V_60 ;
V_99 = F_55 ( F_20 ( V_2 ) -> V_101 +
V_102 ) ;
if ( V_20 -> V_103 ) {
if ( V_93 <= V_99 )
return 0 ;
V_20 -> V_103 = 0 ;
}
if ( V_93 <= V_99 )
V_94 = V_20 -> V_53 . V_59 + V_93 - V_99 ;
else
V_94 = V_93 - V_99 ;
V_98 = V_94 % V_20 -> V_53 . V_60 ;
V_96 = V_93 % V_20 -> V_53 . V_60 ;
if ( V_96 >= V_99 )
V_95 = V_93 - V_96 ;
else if ( V_97 >= V_98 )
V_95 = V_94 - V_98 ;
else {
V_95 = V_94 - V_98 + V_20 -> V_53 . V_60 ;
if ( V_95 >= V_20 -> V_53 . V_59 )
V_95 = 0 ;
}
return V_95 + V_97 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
F_57 ( & V_104 ) ;
F_58 ( & V_65 -> V_105 , & V_106 ) ;
F_59 ( & V_104 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
F_57 ( & V_104 ) ;
F_61 ( & V_65 -> V_105 ) ;
F_59 ( & V_104 ) ;
}
static int F_62 ( const char * V_28 , const struct V_107 * V_108 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
int V_109 = V_110 ;
int V_111 = F_63 ( V_28 , V_108 ) ;
if ( V_111 || V_109 == V_110 )
return V_111 ;
F_57 ( & V_104 ) ;
F_38 (hda, &card_list, list) {
V_2 = & V_65 -> V_2 ;
if ( ! V_65 -> V_112 || V_2 -> V_113 )
continue;
F_64 ( & V_2 -> V_50 , V_110 * 1000 ) ;
}
F_59 ( & V_104 ) ;
return 0 ;
}
static void F_65 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = & V_65 -> V_2 ;
int V_114 ;
unsigned int V_115 , V_116 ;
if ( ! V_65 -> V_117 )
return;
V_114 = F_66 ( F_20 ( V_2 ) ) ;
switch ( V_114 ) {
case 337500 :
V_115 = 16 ;
V_116 = 225 ;
break;
case 450000 :
default:
V_115 = 4 ;
V_116 = 75 ;
break;
case 540000 :
V_115 = 4 ;
V_116 = 90 ;
break;
case 675000 :
V_115 = 8 ;
V_116 = 225 ;
break;
}
F_67 ( V_2 , V_118 , V_115 ) ;
F_67 ( V_2 , V_119 , V_116 ) ;
}
static int F_68 ( struct V_120 * V_9 )
{
struct V_121 * V_33 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
struct V_49 * V_50 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
if ( V_2 -> V_113 || V_65 -> V_122 || ! V_2 -> V_86 )
return 0 ;
V_50 = F_20 ( V_2 ) ;
F_70 ( V_33 , V_123 ) ;
F_45 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_50 -> V_88 >= 0 ) {
F_73 ( V_50 -> V_88 , V_2 ) ;
V_50 -> V_88 = - 1 ;
}
if ( V_2 -> V_90 )
F_74 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_51
&& V_65 -> V_117 )
F_32 ( V_50 , false ) ;
F_75 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_120 * V_9 )
{
struct V_24 * V_25 = F_77 ( V_9 ) ;
struct V_121 * V_33 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
if ( V_2 -> V_113 || V_65 -> V_122 || ! V_2 -> V_86 )
return 0 ;
if ( V_2 -> V_31 & V_51
&& V_65 -> V_117 ) {
F_32 ( F_20 ( V_2 ) , true ) ;
F_65 ( V_65 ) ;
}
if ( V_2 -> V_90 )
if ( F_78 ( V_25 ) < 0 )
V_2 -> V_90 = 0 ;
if ( F_46 ( V_2 , 1 ) < 0 )
return - V_124 ;
F_14 ( V_2 ) ;
F_19 ( V_2 , true ) ;
F_70 ( V_33 , V_125 ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_120 * V_9 )
{
struct V_121 * V_33 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
if ( V_2 -> V_113 || V_65 -> V_122 )
return 0 ;
if ( ! F_81 ( V_2 ) )
return 0 ;
F_67 ( V_2 , V_126 , F_82 ( V_2 , V_126 ) |
V_127 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( V_2 -> V_31 & V_51
&& V_65 -> V_117 )
F_32 ( F_20 ( V_2 ) , false ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_120 * V_9 )
{
struct V_121 * V_33 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
struct V_49 * V_50 ;
struct V_128 * V_129 ;
int V_130 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
if ( V_2 -> V_113 || V_65 -> V_122 )
return 0 ;
if ( ! F_81 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_51 ) {
V_50 = F_20 ( V_2 ) ;
if ( V_65 -> V_117 ) {
F_32 ( V_50 , true ) ;
F_65 ( V_65 ) ;
} else {
F_21 ( V_50 , true ) ;
F_21 ( V_50 , false ) ;
}
}
V_130 = F_82 ( V_2 , V_131 ) ;
F_14 ( V_2 ) ;
F_19 ( V_2 , true ) ;
if ( V_130 ) {
F_85 (codec, &chip->bus)
if ( V_130 & ( 1 << V_129 -> V_132 ) )
F_86 ( & V_129 -> V_133 ,
V_129 -> V_134 ) ;
}
F_67 ( V_2 , V_126 , F_82 ( V_2 , V_126 ) &
~ V_127 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_120 * V_9 )
{
struct V_121 * V_33 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
if ( V_2 -> V_113 || V_65 -> V_122 )
return 0 ;
if ( ! V_135 || ! F_81 ( V_2 ) ||
F_20 ( V_2 ) -> V_136 || ! V_2 -> V_86 )
return - V_137 ;
return 0 ;
}
static void F_89 ( struct V_24 * V_25 ,
enum V_138 V_139 )
{
struct V_121 * V_33 = F_90 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
bool V_113 ;
F_91 ( & V_65 -> V_140 ) ;
if ( V_65 -> V_122 )
return;
V_113 = ( V_139 == V_141 ) ;
if ( V_2 -> V_113 == V_113 )
return;
if ( ! V_65 -> V_112 ) {
V_2 -> V_113 = V_113 ;
if ( ! V_113 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_92 ( V_2 ) < 0 ) {
F_48 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_65 -> V_122 = true ;
}
}
} else {
F_25 ( V_2 -> V_33 -> V_9 , L_14 ,
V_113 ? L_15 : L_16 ) ;
if ( V_113 ) {
F_93 ( V_33 -> V_9 ) ;
F_68 ( V_33 -> V_9 ) ;
V_25 -> V_142 = V_143 ;
V_2 -> V_113 = true ;
if ( F_94 ( & V_2 -> V_50 ) )
F_95 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_96 ( & V_2 -> V_50 ) ;
F_97 ( V_33 -> V_9 ) ;
V_2 -> V_113 = false ;
F_76 ( V_33 -> V_9 ) ;
}
}
}
static bool F_98 ( struct V_24 * V_25 )
{
struct V_121 * V_33 = F_90 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
F_91 ( & V_65 -> V_140 ) ;
if ( V_65 -> V_122 )
return false ;
if ( V_2 -> V_113 || ! V_65 -> V_112 )
return true ;
if ( F_94 ( & V_2 -> V_50 ) )
return false ;
F_96 ( & V_2 -> V_50 ) ;
return true ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
struct V_24 * V_144 = F_100 ( V_2 -> V_25 ) ;
if ( V_144 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_65 -> V_145 = 1 ;
F_101 ( V_144 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
int V_146 ;
if ( ! V_65 -> V_145 )
return 0 ;
V_146 = F_103 ( V_2 -> V_25 , & V_147 ,
V_148 ,
V_65 -> V_112 ) ;
if ( V_146 < 0 )
return V_146 ;
V_65 -> V_149 = 1 ;
F_104 ( V_2 -> V_33 -> V_9 ,
& V_65 -> V_150 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
if ( F_81 ( V_2 ) && V_2 -> V_86 )
F_97 ( & V_25 -> V_9 ) ;
F_60 ( V_2 ) ;
V_65 -> V_122 = 1 ;
F_106 ( & V_65 -> V_140 ) ;
if ( V_145 ( V_65 ) ) {
if ( V_2 -> V_113 && V_65 -> V_112 )
F_96 ( & V_2 -> V_50 ) ;
if ( V_65 -> V_149 )
F_107 ( V_2 -> V_25 ) ;
}
if ( V_50 -> V_151 ) {
F_45 ( V_2 ) ;
F_108 ( V_2 ) ;
F_71 ( V_2 ) ;
}
if ( V_50 -> V_88 >= 0 )
F_73 ( V_50 -> V_88 , ( void * ) V_2 ) ;
if ( V_2 -> V_90 )
F_74 ( V_2 -> V_25 ) ;
F_109 ( V_50 -> V_101 ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_50 ) ;
if ( V_2 -> V_152 )
F_113 ( V_2 -> V_25 ) ;
F_114 ( V_2 -> V_25 ) ;
#ifdef F_115
F_116 ( V_2 -> V_153 ) ;
#endif
if ( V_2 -> V_31 & V_51 ) {
if ( V_65 -> V_117 )
F_32 ( V_50 , false ) ;
F_117 ( V_50 ) ;
}
F_118 ( V_65 ) ;
return 0 ;
}
static int F_119 ( struct V_154 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_155 ;
V_2 -> V_50 . V_156 = 1 ;
return 0 ;
}
static int F_120 ( struct V_154 * V_120 )
{
return F_105 ( V_120 -> V_155 ) ;
}
static struct V_24 * F_100 ( struct V_24 * V_25 )
{
struct V_24 * V_144 ;
switch ( V_25 -> V_157 ) {
case V_158 :
case V_159 :
case V_160 :
if ( V_25 -> V_161 == 1 ) {
V_144 = F_121 ( F_122 ( V_25 -> V_50 ) ,
V_25 -> V_50 -> V_84 , 0 ) ;
if ( V_144 ) {
if ( ( V_144 -> V_162 >> 8 ) == V_163 )
return V_144 ;
F_101 ( V_144 ) ;
}
}
break;
}
return NULL ;
}
static bool F_123 ( struct V_24 * V_25 )
{
bool V_164 = false ;
struct V_24 * V_144 = F_100 ( V_25 ) ;
if ( V_144 ) {
if ( F_124 ( V_144 ) == V_141 )
V_164 = true ;
F_101 ( V_144 ) ;
}
return V_164 ;
}
static int F_125 ( struct V_1 * V_2 , int V_165 )
{
const struct V_166 * V_167 ;
switch ( V_165 ) {
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
return V_165 ;
}
V_167 = F_126 ( V_2 -> V_25 , V_173 ) ;
if ( V_167 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_167 -> V_174 , V_167 -> V_175 , V_167 -> V_176 ) ;
return V_167 -> V_174 ;
}
if ( V_2 -> V_31 & V_177 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_171 ;
}
if ( V_2 -> V_31 & V_178 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_169 ;
}
return V_168 ;
}
static void F_127 ( struct V_1 * V_2 , int V_165 )
{
static T_2 V_179 [] = {
[ V_168 ] = NULL ,
[ V_169 ] = F_24 ,
[ V_170 ] = F_34 ,
[ V_171 ] = F_51 ,
[ V_172 ] = F_24 ,
} ;
V_2 -> V_74 [ 0 ] = V_2 -> V_74 [ 1 ] = V_179 [ V_165 ] ;
if ( V_165 == V_172 )
V_2 -> V_74 [ 1 ] = NULL ;
if ( V_165 == V_170 &&
( V_2 -> V_31 & V_61 ) ) {
V_2 -> V_62 [ 0 ] = V_2 -> V_62 [ 1 ] =
F_23 ;
}
}
static void F_128 ( struct V_1 * V_2 , int V_9 )
{
const struct V_166 * V_167 ;
V_2 -> V_180 = V_181 [ V_9 ] ;
if ( V_2 -> V_180 == - 1 ) {
V_167 = F_126 ( V_2 -> V_25 , V_182 ) ;
if ( V_167 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_167 -> V_174 , V_167 -> V_175 , V_167 -> V_176 ) ;
V_2 -> V_180 = V_167 -> V_174 ;
}
}
if ( V_2 -> V_180 != - 1 &&
( V_2 -> V_180 & V_183 ) ) {
F_20 ( V_2 ) -> V_184 = V_2 -> V_180 & 0xff ;
F_25 ( V_2 -> V_33 -> V_9 , L_23 ,
( int ) F_20 ( V_2 ) -> V_184 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
const struct V_166 * V_167 ;
if ( V_185 >= 0 ) {
V_2 -> V_90 = ! ! V_185 ;
return;
}
V_2 -> V_90 = 1 ;
V_167 = F_126 ( V_2 -> V_25 , V_186 ) ;
if ( V_167 ) {
F_25 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_167 -> V_175 , V_167 -> V_176 , V_167 -> V_174 ) ;
V_2 -> V_90 = V_167 -> V_174 ;
return;
}
if ( V_2 -> V_31 & V_187 ) {
F_25 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_90 = 0 ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
int V_45 = V_188 ;
if ( V_45 >= 0 ) {
F_25 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_189 &&
V_2 -> V_14 == V_190 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_191 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_192 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_25 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_131 ( struct V_78 * V_79 )
{
struct V_64 * V_65 = F_28 ( V_79 , struct V_64 , V_193 ) ;
F_92 ( & V_65 -> V_2 ) ;
}
static int F_132 ( struct V_121 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_194 )
{
static struct V_195 V_196 = {
. V_197 = F_119 ,
. V_198 = F_120 ,
} ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
int V_146 ;
* V_194 = NULL ;
V_146 = F_133 ( V_25 ) ;
if ( V_146 < 0 )
return V_146 ;
V_65 = F_134 ( sizeof( * V_65 ) , V_199 ) ;
if ( ! V_65 ) {
F_114 ( V_25 ) ;
return - V_200 ;
}
V_2 = & V_65 -> V_2 ;
F_135 ( & V_2 -> V_201 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_196 = & V_202 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_129 ( V_2 ) ;
V_2 -> V_77 = V_9 ;
V_2 -> V_203 = V_203 ;
F_136 ( & V_2 -> V_204 ) ;
F_137 ( & V_65 -> V_68 , F_36 ) ;
F_136 ( & V_65 -> V_105 ) ;
F_99 ( V_2 ) ;
F_138 ( & V_65 -> V_140 ) ;
F_127 ( V_2 , F_125 ( V_2 , V_205 [ V_9 ] ) ) ;
F_128 ( V_2 , V_9 ) ;
V_2 -> V_206 = V_206 ;
F_130 ( V_2 ) ;
if ( V_76 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_207 :
case V_208 :
V_76 [ V_9 ] = 1 ;
break;
default:
V_76 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_76 = V_76 ;
V_146 = F_139 ( V_2 , V_209 [ V_9 ] , & V_210 ) ;
if ( V_146 < 0 ) {
F_118 ( V_65 ) ;
F_114 ( V_25 ) ;
return V_146 ;
}
V_146 = F_140 ( V_33 , V_211 , V_2 , & V_196 ) ;
if ( V_146 < 0 ) {
F_48 ( V_33 -> V_9 , L_30 ) ;
F_105 ( V_2 ) ;
return V_146 ;
}
F_137 ( & V_65 -> V_193 , F_131 ) ;
* V_194 = V_2 ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_77 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_121 * V_33 = V_2 -> V_33 ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
int V_146 ;
unsigned short V_212 ;
unsigned int V_213 = 64 ;
#if V_214 != 64
if ( V_2 -> V_14 == V_215 ) {
T_4 V_216 ;
F_17 ( V_25 , 0x40 , & V_216 ) ;
F_18 ( V_25 , 0x40 , V_216 | 0x10 ) ;
F_142 ( V_25 , V_217 , 0 ) ;
}
#endif
V_146 = F_143 ( V_25 , L_31 ) ;
if ( V_146 < 0 )
return V_146 ;
V_2 -> V_152 = 1 ;
V_50 -> V_132 = F_144 ( V_25 , 0 ) ;
V_50 -> V_101 = F_145 ( V_25 , 0 ) ;
if ( V_50 -> V_101 == NULL ) {
F_48 ( V_33 -> V_9 , L_32 ) ;
return - V_218 ;
}
if ( V_2 -> V_90 ) {
if ( V_2 -> V_31 & V_219 ) {
F_16 ( V_33 -> V_9 , L_33 ) ;
V_25 -> V_220 = true ;
}
if ( F_78 ( V_25 ) < 0 )
V_2 -> V_90 = 0 ;
}
if ( F_46 ( V_2 , 0 ) < 0 )
return - V_137 ;
F_146 ( V_25 ) ;
F_147 ( V_50 -> V_88 ) ;
V_212 = F_82 ( V_2 , V_221 ) ;
F_16 ( V_33 -> V_9 , L_34 , V_212 ) ;
if ( V_2 -> V_25 -> V_157 == V_159 )
V_213 = 40 ;
if ( V_2 -> V_25 -> V_157 == V_158 ) {
struct V_24 * V_222 ;
V_213 = 40 ;
V_222 = F_148 ( V_158 ,
V_223 ,
NULL ) ;
if ( V_222 ) {
if ( V_222 -> V_191 < 0x30 )
V_212 &= ~ V_224 ;
F_101 ( V_222 ) ;
}
}
if ( V_2 -> V_31 & V_225 ) {
F_16 ( V_33 -> V_9 , L_35 ) ;
V_212 &= ~ V_224 ;
}
if ( V_226 >= 0 )
V_2 -> V_226 = ! ! V_226 ;
else {
if ( V_2 -> V_31 & V_227 )
V_2 -> V_226 = 0 ;
else
V_2 -> V_226 = 1 ;
}
if ( ! ( V_212 & V_224 ) )
V_213 = 32 ;
if ( ! F_149 ( & V_25 -> V_9 , F_150 ( V_213 ) ) ) {
F_151 ( & V_25 -> V_9 , F_150 ( V_213 ) ) ;
} else {
F_149 ( & V_25 -> V_9 , F_150 ( 32 ) ) ;
F_151 ( & V_25 -> V_9 , F_150 ( 32 ) ) ;
}
V_2 -> V_228 = ( V_212 >> 8 ) & 0x0f ;
V_2 -> V_229 = ( V_212 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_229 && ! V_2 -> V_228 ) {
switch ( V_2 -> V_14 ) {
case V_215 :
V_2 -> V_229 = V_230 ;
V_2 -> V_228 = V_231 ;
break;
case V_232 :
case V_233 :
V_2 -> V_229 = V_234 ;
V_2 -> V_228 = V_235 ;
break;
case V_236 :
default:
V_2 -> V_229 = V_237 ;
V_2 -> V_228 = V_238 ;
break;
}
}
V_2 -> V_239 = 0 ;
V_2 -> V_240 = V_2 -> V_228 ;
V_2 -> V_241 = V_2 -> V_229 + V_2 -> V_228 ;
V_146 = F_152 ( V_2 ) ;
if ( V_146 < 0 )
return V_146 ;
V_146 = F_153 ( V_2 ) ;
if ( V_146 < 0 )
return V_146 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_51 ) {
struct V_64 * V_65 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
F_65 ( V_65 ) ;
}
F_19 ( V_2 , ( V_242 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_20 ( V_2 ) -> V_184 ) {
F_48 ( V_33 -> V_9 , L_36 ) ;
return - V_243 ;
}
strcpy ( V_33 -> V_244 , L_37 ) ;
F_154 ( V_33 -> V_245 , V_246 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_245 ) ) ;
snprintf ( V_33 -> V_247 , sizeof( V_33 -> V_247 ) ,
L_38 ,
V_33 -> V_245 , V_50 -> V_132 , V_50 -> V_88 ) ;
return 0 ;
}
static void F_155 ( const struct V_248 * V_153 , void * V_249 )
{
struct V_121 * V_33 = V_249 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_153 ) {
F_48 ( V_33 -> V_9 , L_39 ) ;
goto error;
}
V_2 -> V_153 = V_153 ;
if ( ! V_2 -> V_113 ) {
if ( F_92 ( V_2 ) )
goto error;
}
return;
error:
F_156 ( V_33 ) ;
F_157 ( V_25 , NULL ) ;
}
static void F_158 ( T_1 V_174 , T_1 T_5 * V_132 )
{
F_159 ( V_174 , V_132 ) ;
}
static T_1 F_160 ( T_1 T_5 * V_132 )
{
return F_161 ( V_132 ) ;
}
static void F_162 ( T_4 V_174 , T_4 T_5 * V_132 )
{
F_163 ( V_174 , V_132 ) ;
}
static T_4 F_164 ( T_4 T_5 * V_132 )
{
return F_55 ( V_132 ) ;
}
static void F_165 ( T_3 V_174 , T_3 T_5 * V_132 )
{
F_166 ( V_174 , V_132 ) ;
}
static T_3 F_167 ( T_3 T_5 * V_132 )
{
return F_168 ( V_132 ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
int V_146 ;
F_73 ( V_50 -> V_88 , V_2 ) ;
V_50 -> V_88 = - 1 ;
F_74 ( V_2 -> V_25 ) ;
V_2 -> V_90 = 0 ;
V_146 = F_46 ( V_2 , 1 ) ;
if ( V_146 < 0 )
return V_146 ;
return 0 ;
}
static int F_170 ( struct V_49 * V_50 ,
int type ,
T_6 V_250 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_171 ( V_50 ) ;
int V_146 ;
V_146 = F_172 ( type ,
V_50 -> V_9 ,
V_250 , V_19 ) ;
if ( V_146 < 0 )
return V_146 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_173 ( struct V_49 * V_50 , struct V_3 * V_19 )
{
struct V_1 * V_2 = F_171 ( V_50 ) ;
F_8 ( V_2 , V_19 , false ) ;
F_174 ( V_19 ) ;
}
static int F_175 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_250 )
{
struct V_20 * V_20 = F_176 ( V_22 ) ;
int V_111 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_111 = F_177 ( V_22 , V_250 ) ;
if ( V_111 < 0 )
return V_111 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_176 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_179 ( V_22 ) ;
}
static void F_180 ( struct V_21 * V_22 ,
struct V_251 * V_7 )
{
#ifdef F_181
struct V_252 * V_253 = F_182 ( V_22 ) ;
struct V_1 * V_2 = V_253 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_254 = F_183 ( V_7 -> V_254 ) ;
#endif
}
static int F_184 ( struct V_24 * V_25 ,
const struct V_255 * V_256 )
{
static int V_9 ;
struct V_121 * V_33 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
bool V_257 ;
int V_146 ;
if ( V_9 >= V_258 )
return - V_243 ;
if ( ! V_69 [ V_9 ] ) {
V_9 ++ ;
return - V_259 ;
}
V_146 = F_185 ( & V_25 -> V_9 , V_260 [ V_9 ] , V_261 [ V_9 ] , V_262 ,
0 , & V_33 ) ;
if ( V_146 < 0 ) {
F_48 ( & V_25 -> V_9 , L_40 ) ;
return V_146 ;
}
V_146 = F_132 ( V_33 , V_25 , V_9 , V_256 -> V_263 , & V_2 ) ;
if ( V_146 < 0 )
goto V_264;
V_33 -> V_13 = V_2 ;
V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
F_157 ( V_25 , V_33 ) ;
V_146 = F_102 ( V_2 ) ;
if ( V_146 < 0 ) {
F_48 ( V_33 -> V_9 , L_41 ) ;
goto V_264;
}
if ( F_123 ( V_25 ) ) {
F_25 ( V_33 -> V_9 , L_42 ) ;
F_25 ( V_33 -> V_9 , L_43 ) ;
V_2 -> V_113 = true ;
}
V_257 = ! V_2 -> V_113 ;
#ifdef F_115
if ( V_265 [ V_9 ] && * V_265 [ V_9 ] ) {
F_25 ( V_33 -> V_9 , L_44 ,
V_265 [ V_9 ] ) ;
V_146 = F_186 ( V_262 , true , V_265 [ V_9 ] ,
& V_25 -> V_9 , V_199 , V_33 ,
F_155 ) ;
if ( V_146 < 0 )
goto V_264;
V_257 = false ;
}
#endif
#ifndef F_187
if ( V_2 -> V_31 & V_51 )
F_48 ( V_33 -> V_9 , L_45 ) ;
#endif
if ( V_257 )
F_30 ( & V_65 -> V_193 ) ;
V_9 ++ ;
if ( V_2 -> V_113 )
F_106 ( & V_65 -> V_140 ) ;
return 0 ;
V_264:
F_156 ( V_33 ) ;
return V_146 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_28 ( V_2 , struct V_64 , V_2 ) ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_77 ;
int V_146 ;
V_65 -> V_112 = 1 ;
if ( V_2 -> V_31 & V_51 ) {
if ( F_188 ( V_25 ) )
V_65 -> V_117 = 1 ;
V_146 = F_189 ( V_50 ) ;
if ( V_146 < 0 ) {
if ( F_188 ( V_25 ) )
goto V_264;
else
goto V_266;
}
V_146 = F_32 ( V_50 , true ) ;
if ( V_146 < 0 ) {
F_48 ( V_2 -> V_33 -> V_9 ,
L_46 ) ;
goto V_267;
}
}
V_266:
V_146 = F_141 ( V_2 ) ;
if ( V_146 < 0 )
goto V_264;
#ifdef F_190
V_2 -> V_268 = V_268 [ V_9 ] ;
#endif
V_146 = F_191 ( V_2 , V_269 [ V_2 -> V_14 ] ) ;
if ( V_146 < 0 )
goto V_264;
#ifdef F_115
if ( V_2 -> V_153 ) {
V_146 = F_192 ( & V_2 -> V_50 , V_2 -> V_153 -> V_250 ,
V_2 -> V_153 -> V_29 ) ;
if ( V_146 < 0 )
goto V_264;
#ifndef F_193
F_116 ( V_2 -> V_153 ) ;
V_2 -> V_153 = NULL ;
#endif
}
#endif
if ( ( V_242 [ V_9 ] & 1 ) == 0 ) {
V_146 = F_194 ( V_2 ) ;
if ( V_146 < 0 )
goto V_264;
}
V_146 = F_195 ( V_2 -> V_33 ) ;
if ( V_146 < 0 )
goto V_264;
V_2 -> V_86 = 1 ;
F_56 ( V_2 ) ;
F_64 ( & V_2 -> V_50 , V_110 * 1000 ) ;
if ( F_81 ( V_2 ) || V_65 -> V_145 )
F_196 ( & V_25 -> V_9 ) ;
V_264:
if ( V_2 -> V_31 & V_51
&& ! V_65 -> V_117 )
F_32 ( V_50 , false ) ;
V_267:
if ( V_146 < 0 )
V_65 -> V_122 = 1 ;
F_106 ( & V_65 -> V_140 ) ;
return V_146 ;
}
static void F_197 ( struct V_24 * V_25 )
{
struct V_121 * V_33 = F_90 ( V_25 ) ;
if ( V_33 )
F_156 ( V_33 ) ;
}
static void F_198 ( struct V_24 * V_25 )
{
struct V_121 * V_33 = F_90 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_86 )
F_71 ( V_2 ) ;
}
