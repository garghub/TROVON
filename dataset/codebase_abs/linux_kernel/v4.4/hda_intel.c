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
if ( V_2 -> V_31 & V_52 )
F_24 ( V_51 , true ) ;
F_25 ( V_2 , V_49 ) ;
if ( V_2 -> V_31 & V_52 )
F_24 ( V_51 , false ) ;
if ( F_26 ( V_25 ) )
F_19 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_53 )
{
struct V_21 * V_22 = V_20 -> V_54 . V_22 ;
int V_55 = V_22 -> V_55 ;
unsigned int V_56 = F_28 ( V_2 , V_20 ) ;
int V_57 ;
if ( V_55 == V_58 )
V_57 = V_53 - V_56 ;
else
V_57 = V_56 - V_53 ;
if ( V_57 < 0 ) {
if ( V_57 >= V_20 -> V_54 . V_59 )
V_57 = 0 ;
else
V_57 += V_20 -> V_54 . V_60 ;
}
if ( V_57 >= V_20 -> V_54 . V_61 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_7 ,
V_57 , V_20 -> V_54 . V_61 ) ;
V_57 = 0 ;
V_2 -> V_31 &= ~ V_62 ;
V_2 -> V_63 [ V_55 ] = NULL ;
}
return F_30 ( V_22 -> V_64 , V_57 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
int V_67 ;
V_67 = F_33 ( V_2 , V_20 ) ;
if ( V_67 == 1 ) {
V_20 -> V_68 = 0 ;
return V_67 ;
} else if ( V_67 == 0 ) {
V_20 -> V_68 = 1 ;
F_34 ( & V_66 -> V_69 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , bool V_70 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
return F_36 ( V_51 , V_70 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_54 . V_22 ;
int V_55 = V_22 -> V_55 ;
T_1 V_71 ;
unsigned int V_53 ;
V_71 = F_20 ( V_2 , V_72 ) - V_20 -> V_54 . V_73 ;
if ( V_71 < ( V_20 -> V_54 . V_74 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_75 [ V_55 ] )
V_53 = V_2 -> V_75 [ V_55 ] ( V_2 , V_20 ) ;
else {
V_53 = F_37 ( V_2 , V_20 ) ;
if ( ! V_53 || V_53 == ( T_1 ) - 1 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_8 ) ;
V_2 -> V_75 [ V_55 ] = F_28 ;
if ( V_2 -> V_75 [ 0 ] == F_28 &&
V_2 -> V_75 [ 1 ] == F_28 )
F_23 ( V_2 ) -> V_76 = false ;
V_53 = F_28 ( V_2 , V_20 ) ;
V_2 -> V_63 [ V_55 ] = NULL ;
} else {
V_2 -> V_75 [ V_55 ] = F_37 ;
if ( V_2 -> V_31 & V_62 )
V_2 -> V_63 [ V_55 ] = F_27 ;
}
}
if ( V_53 >= V_20 -> V_54 . V_60 )
V_53 = 0 ;
if ( F_38 ( ! V_20 -> V_54 . V_61 ,
L_9 ) )
return - 1 ;
if ( V_71 < ( V_20 -> V_54 . V_74 * 5 ) / 4 &&
V_53 % V_20 -> V_54 . V_61 > V_20 -> V_54 . V_61 / 2 )
return V_2 -> V_77 [ V_2 -> V_78 ] ? 0 : - 1 ;
V_20 -> V_54 . V_73 += V_71 ;
return 1 ;
}
static void F_39 ( struct V_79 * V_80 )
{
struct V_65 * V_66 = F_32 ( V_80 , struct V_65 , V_69 ) ;
struct V_1 * V_2 = & V_66 -> V_2 ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_81 * V_82 ;
int V_83 , V_67 ;
if ( ! V_66 -> V_84 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_10 ,
V_2 -> V_33 -> V_85 ) ;
V_66 -> V_84 = 1 ;
}
for (; ; ) {
V_83 = 0 ;
F_40 ( & V_51 -> V_86 ) ;
F_41 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_42 ( V_82 ) ;
if ( ! V_20 -> V_68 ||
! V_82 -> V_22 ||
! V_82 -> V_87 )
continue;
V_67 = F_33 ( V_2 , V_20 ) ;
if ( V_67 > 0 ) {
V_20 -> V_68 = 0 ;
F_43 ( & V_51 -> V_86 ) ;
F_44 ( V_82 -> V_22 ) ;
F_45 ( & V_51 -> V_86 ) ;
} else if ( V_67 < 0 ) {
V_83 = 0 ;
} else
V_83 ++ ;
}
F_46 ( & V_51 -> V_86 ) ;
if ( ! V_83 )
return;
F_47 ( 1 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_81 * V_82 ;
F_40 ( & V_51 -> V_86 ) ;
F_41 (s, &bus->stream_list, list) {
struct V_20 * V_20 = F_42 ( V_82 ) ;
V_20 -> V_68 = 0 ;
}
F_46 ( & V_51 -> V_86 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_88 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
if ( F_50 ( V_2 -> V_25 -> V_89 , V_90 ,
V_2 -> V_91 ? 0 : V_92 ,
V_93 , V_2 ) ) {
F_51 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_89 ) ;
if ( V_88 )
F_52 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_51 -> V_89 = V_2 -> V_25 -> V_89 ;
F_53 ( V_2 -> V_25 , ! V_2 -> V_91 ) ;
return 0 ;
}
static unsigned int F_54 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_94 , V_95 , V_96 ;
unsigned int V_97 , V_98 , V_99 ;
unsigned int V_100 ;
V_94 = F_55 ( F_56 ( V_20 ) ) ;
if ( V_20 -> V_54 . V_22 -> V_55 == V_58 ) {
return V_94 ;
}
V_98 = F_57 ( * V_20 -> V_54 . V_101 ) ;
V_98 %= V_20 -> V_54 . V_61 ;
V_100 = F_58 ( F_23 ( V_2 ) -> V_102 +
V_103 ) ;
if ( V_20 -> V_104 ) {
if ( V_94 <= V_100 )
return 0 ;
V_20 -> V_104 = 0 ;
}
if ( V_94 <= V_100 )
V_95 = V_20 -> V_54 . V_60 + V_94 - V_100 ;
else
V_95 = V_94 - V_100 ;
V_99 = V_95 % V_20 -> V_54 . V_61 ;
V_97 = V_94 % V_20 -> V_54 . V_61 ;
if ( V_97 >= V_100 )
V_96 = V_94 - V_97 ;
else if ( V_98 >= V_99 )
V_96 = V_95 - V_99 ;
else {
V_96 = V_95 - V_99 + V_20 -> V_54 . V_61 ;
if ( V_96 >= V_20 -> V_54 . V_60 )
V_96 = 0 ;
}
return V_96 + V_98 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
F_60 ( & V_105 ) ;
F_61 ( & V_66 -> V_106 , & V_107 ) ;
F_62 ( & V_105 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
F_60 ( & V_105 ) ;
F_64 ( & V_66 -> V_106 ) ;
F_62 ( & V_105 ) ;
}
static int F_65 ( const char * V_28 , const struct V_108 * V_109 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
int V_110 = V_111 ;
int V_112 = F_66 ( V_28 , V_109 ) ;
if ( V_112 || V_110 == V_111 )
return V_112 ;
F_60 ( & V_105 ) ;
F_41 (hda, &card_list, list) {
V_2 = & V_66 -> V_2 ;
if ( ! V_66 -> V_113 || V_2 -> V_114 )
continue;
F_67 ( & V_2 -> V_51 , V_111 * 1000 ) ;
}
F_62 ( & V_105 ) ;
return 0 ;
}
static void F_68 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = & V_66 -> V_2 ;
int V_115 ;
unsigned int V_116 , V_117 ;
if ( ! V_66 -> V_118 )
return;
V_115 = F_69 ( F_23 ( V_2 ) ) ;
switch ( V_115 ) {
case 337500 :
V_116 = 16 ;
V_117 = 225 ;
break;
case 450000 :
default:
V_116 = 4 ;
V_117 = 75 ;
break;
case 540000 :
V_116 = 4 ;
V_117 = 90 ;
break;
case 675000 :
V_116 = 8 ;
V_117 = 225 ;
break;
}
F_70 ( V_2 , V_119 , V_116 ) ;
F_70 ( V_2 , V_120 , V_117 ) ;
}
static int F_71 ( struct V_121 * V_9 )
{
struct V_122 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_50 * V_51 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
if ( V_2 -> V_114 || V_66 -> V_123 || ! V_2 -> V_87 )
return 0 ;
V_51 = F_23 ( V_2 ) ;
F_73 ( V_33 , V_124 ) ;
F_48 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_51 -> V_89 >= 0 ) {
F_76 ( V_51 -> V_89 , V_2 ) ;
V_51 -> V_89 = - 1 ;
}
if ( V_2 -> V_91 )
F_77 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_52
&& V_66 -> V_118 )
F_36 ( V_51 , false ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_121 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
struct V_122 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
if ( V_2 -> V_114 || V_66 -> V_123 || ! V_2 -> V_87 )
return 0 ;
if ( V_2 -> V_31 & V_52
&& V_66 -> V_118 ) {
F_36 ( F_23 ( V_2 ) , true ) ;
F_68 ( V_66 ) ;
}
if ( V_2 -> V_91 )
if ( F_81 ( V_25 ) < 0 )
V_2 -> V_91 = 0 ;
if ( F_49 ( V_2 , 1 ) < 0 )
return - V_125 ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
F_73 ( V_33 , V_126 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_121 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
if ( F_84 ( V_25 ) )
F_85 ( V_25 , V_127 ) ;
return 0 ;
}
static int F_86 ( struct V_121 * V_9 )
{
struct V_24 * V_25 = F_80 ( V_9 ) ;
if ( F_84 ( V_25 ) )
F_85 ( V_25 , V_128 ) ;
return 0 ;
}
static int F_87 ( struct V_121 * V_9 )
{
struct V_122 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
if ( V_2 -> V_114 || V_66 -> V_123 )
return 0 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
F_70 ( V_2 , V_129 , F_89 ( V_2 , V_129 ) |
V_130 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_2 -> V_31 & V_52
&& V_66 -> V_118 )
F_36 ( F_23 ( V_2 ) , false ) ;
F_90 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_121 * V_9 )
{
struct V_122 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_50 * V_51 ;
struct V_131 * V_132 ;
int V_133 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
if ( V_2 -> V_114 || V_66 -> V_123 )
return 0 ;
if ( ! F_88 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_52 ) {
V_51 = F_23 ( V_2 ) ;
if ( V_66 -> V_118 ) {
F_36 ( V_51 , true ) ;
F_68 ( V_66 ) ;
} else {
F_24 ( V_51 , true ) ;
F_24 ( V_51 , false ) ;
}
}
V_133 = F_89 ( V_2 , V_134 ) ;
F_14 ( V_2 ) ;
F_22 ( V_2 , true ) ;
if ( V_133 ) {
F_92 (codec, &chip->bus)
if ( V_133 & ( 1 << V_132 -> V_135 ) )
F_93 ( & V_132 -> V_136 ,
V_132 -> V_137 ) ;
}
F_70 ( V_2 , V_129 , F_89 ( V_2 , V_129 ) &
~ V_130 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_121 * V_9 )
{
struct V_122 * V_33 = F_72 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
if ( V_2 -> V_114 || V_66 -> V_123 )
return 0 ;
if ( ! V_138 || ! F_88 ( V_2 ) ||
F_23 ( V_2 ) -> V_139 || ! V_2 -> V_87 )
return - V_140 ;
return 0 ;
}
static void F_96 ( struct V_24 * V_25 ,
enum V_141 V_142 )
{
struct V_122 * V_33 = F_97 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
bool V_114 ;
F_98 ( & V_66 -> V_143 ) ;
if ( V_66 -> V_123 )
return;
V_114 = ( V_142 == V_144 ) ;
if ( V_2 -> V_114 == V_114 )
return;
if ( ! V_66 -> V_113 ) {
V_2 -> V_114 = V_114 ;
if ( ! V_114 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_99 ( V_2 ) < 0 ) {
F_51 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_66 -> V_123 = true ;
}
}
} else {
F_29 ( V_2 -> V_33 -> V_9 , L_14 ,
V_114 ? L_15 : L_16 ) ;
if ( V_114 ) {
F_100 ( V_33 -> V_9 ) ;
F_71 ( V_33 -> V_9 ) ;
V_25 -> V_145 = V_146 ;
V_2 -> V_114 = true ;
if ( F_101 ( & V_2 -> V_51 ) )
F_102 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_103 ( & V_2 -> V_51 ) ;
F_104 ( V_33 -> V_9 ) ;
V_2 -> V_114 = false ;
F_79 ( V_33 -> V_9 ) ;
}
}
}
static bool F_105 ( struct V_24 * V_25 )
{
struct V_122 * V_33 = F_97 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
F_98 ( & V_66 -> V_143 ) ;
if ( V_66 -> V_123 )
return false ;
if ( V_2 -> V_114 || ! V_66 -> V_113 )
return true ;
if ( F_101 ( & V_2 -> V_51 ) )
return false ;
F_103 ( & V_2 -> V_51 ) ;
return true ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
struct V_24 * V_147 = F_107 ( V_2 -> V_25 ) ;
if ( V_147 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_66 -> V_148 = 1 ;
F_108 ( V_147 ) ;
}
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
int V_149 ;
if ( ! V_66 -> V_148 )
return 0 ;
V_149 = F_110 ( V_2 -> V_25 , & V_150 ,
V_151 ) ;
if ( V_149 < 0 )
return V_149 ;
V_66 -> V_152 = 1 ;
F_111 ( V_2 -> V_33 -> V_9 ,
& V_66 -> V_153 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
if ( F_88 ( V_2 ) && V_2 -> V_87 )
F_104 ( & V_25 -> V_9 ) ;
F_63 ( V_2 ) ;
V_66 -> V_123 = 1 ;
F_113 ( & V_66 -> V_143 ) ;
if ( V_148 ( V_66 ) ) {
if ( V_2 -> V_114 && V_66 -> V_113 )
F_103 ( & V_2 -> V_51 ) ;
if ( V_66 -> V_152 )
F_114 ( V_2 -> V_25 ) ;
}
if ( V_51 -> V_154 ) {
F_48 ( V_2 ) ;
F_115 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_51 -> V_89 >= 0 )
F_76 ( V_51 -> V_89 , ( void * ) V_2 ) ;
if ( V_2 -> V_91 )
F_77 ( V_2 -> V_25 ) ;
F_116 ( V_51 -> V_102 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_51 ) ;
if ( V_2 -> V_155 )
F_120 ( V_2 -> V_25 ) ;
F_121 ( V_2 -> V_25 ) ;
#ifdef F_122
F_123 ( V_2 -> V_156 ) ;
#endif
if ( V_2 -> V_31 & V_52 ) {
if ( V_66 -> V_118 )
F_36 ( V_51 , false ) ;
F_124 ( V_51 ) ;
}
F_125 ( V_66 ) ;
return 0 ;
}
static int F_126 ( struct V_157 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_158 ;
V_2 -> V_51 . V_159 = 1 ;
return 0 ;
}
static int F_127 ( struct V_157 * V_121 )
{
return F_112 ( V_121 -> V_158 ) ;
}
static struct V_24 * F_107 ( struct V_24 * V_25 )
{
struct V_24 * V_147 ;
switch ( V_25 -> V_160 ) {
case V_161 :
case V_162 :
case V_163 :
if ( V_25 -> V_164 == 1 ) {
V_147 = F_128 ( F_129 ( V_25 -> V_51 ) ,
V_25 -> V_51 -> V_85 , 0 ) ;
if ( V_147 ) {
if ( ( V_147 -> V_165 >> 8 ) == V_166 )
return V_147 ;
F_108 ( V_147 ) ;
}
}
break;
}
return NULL ;
}
static bool F_130 ( struct V_24 * V_25 )
{
bool V_167 = false ;
struct V_24 * V_147 = F_107 ( V_25 ) ;
if ( V_147 ) {
if ( F_131 ( V_147 ) == V_144 )
V_167 = true ;
F_108 ( V_147 ) ;
}
return V_167 ;
}
static int F_132 ( struct V_1 * V_2 , int V_168 )
{
const struct V_169 * V_170 ;
switch ( V_168 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
return V_168 ;
}
V_170 = F_133 ( V_2 -> V_25 , V_176 ) ;
if ( V_170 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_170 -> V_177 , V_170 -> V_178 , V_170 -> V_179 ) ;
return V_170 -> V_177 ;
}
if ( V_2 -> V_31 & V_180 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_174 ;
}
if ( V_2 -> V_31 & V_181 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_172 ;
}
return V_171 ;
}
static void F_134 ( struct V_1 * V_2 , int V_168 )
{
static T_2 V_182 [] = {
[ V_171 ] = NULL ,
[ V_172 ] = F_28 ,
[ V_173 ] = F_37 ,
[ V_174 ] = F_54 ,
[ V_175 ] = F_28 ,
} ;
V_2 -> V_75 [ 0 ] = V_2 -> V_75 [ 1 ] = V_182 [ V_168 ] ;
if ( V_168 == V_175 )
V_2 -> V_75 [ 1 ] = NULL ;
if ( V_168 == V_173 &&
( V_2 -> V_31 & V_62 ) ) {
V_2 -> V_63 [ 0 ] = V_2 -> V_63 [ 1 ] =
F_27 ;
}
}
static void F_135 ( struct V_1 * V_2 , int V_9 )
{
const struct V_169 * V_170 ;
V_2 -> V_183 = V_184 [ V_9 ] ;
if ( V_2 -> V_183 == - 1 ) {
V_170 = F_133 ( V_2 -> V_25 , V_185 ) ;
if ( V_170 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_170 -> V_177 , V_170 -> V_178 , V_170 -> V_179 ) ;
V_2 -> V_183 = V_170 -> V_177 ;
}
}
if ( V_2 -> V_183 != - 1 &&
( V_2 -> V_183 & V_186 ) ) {
F_23 ( V_2 ) -> V_187 = V_2 -> V_183 & 0xff ;
F_29 ( V_2 -> V_33 -> V_9 , L_23 ,
( int ) F_23 ( V_2 ) -> V_187 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
const struct V_169 * V_170 ;
if ( V_188 >= 0 ) {
V_2 -> V_91 = ! ! V_188 ;
return;
}
V_2 -> V_91 = 1 ;
V_170 = F_133 ( V_2 -> V_25 , V_189 ) ;
if ( V_170 ) {
F_29 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_170 -> V_178 , V_170 -> V_179 , V_170 -> V_177 ) ;
V_2 -> V_91 = V_170 -> V_177 ;
return;
}
if ( V_2 -> V_31 & V_190 ) {
F_29 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_91 = 0 ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
int V_45 = V_191 ;
if ( V_45 >= 0 ) {
F_29 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_192 &&
V_2 -> V_14 == V_193 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_194 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_195 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_29 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_138 ( struct V_79 * V_80 )
{
struct V_65 * V_66 = F_32 ( V_80 , struct V_65 , V_196 ) ;
F_99 ( & V_66 -> V_2 ) ;
}
static int F_139 ( struct V_122 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
struct V_1 * * V_197 )
{
static struct V_198 V_199 = {
. V_200 = F_126 ,
. V_201 = F_127 ,
} ;
struct V_65 * V_66 ;
struct V_1 * V_2 ;
int V_149 ;
* V_197 = NULL ;
V_149 = F_140 ( V_25 ) ;
if ( V_149 < 0 )
return V_149 ;
V_66 = F_141 ( sizeof( * V_66 ) , V_202 ) ;
if ( ! V_66 ) {
F_121 ( V_25 ) ;
return - V_203 ;
}
V_2 = & V_66 -> V_2 ;
F_142 ( & V_2 -> V_204 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_199 = & V_205 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_136 ( V_2 ) ;
V_2 -> V_78 = V_9 ;
V_2 -> V_206 = V_206 ;
F_143 ( & V_2 -> V_207 ) ;
F_144 ( & V_66 -> V_69 , F_39 ) ;
F_143 ( & V_66 -> V_106 ) ;
F_106 ( V_2 ) ;
F_145 ( & V_66 -> V_143 ) ;
F_134 ( V_2 , F_132 ( V_2 , V_208 [ V_9 ] ) ) ;
F_135 ( V_2 , V_9 ) ;
V_2 -> V_209 = V_209 ;
F_137 ( V_2 ) ;
if ( V_77 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_210 :
case V_211 :
V_77 [ V_9 ] = 1 ;
break;
default:
V_77 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_77 = V_77 ;
V_149 = F_146 ( V_2 , V_212 [ V_9 ] , & V_213 ) ;
if ( V_149 < 0 ) {
F_125 ( V_66 ) ;
F_121 ( V_25 ) ;
return V_149 ;
}
V_149 = F_147 ( V_33 , V_214 , V_2 , & V_199 ) ;
if ( V_149 < 0 ) {
F_51 ( V_33 -> V_9 , L_30 ) ;
F_112 ( V_2 ) ;
return V_149 ;
}
F_144 ( & V_66 -> V_196 , F_138 ) ;
* V_197 = V_2 ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_78 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_122 * V_33 = V_2 -> V_33 ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_149 ;
unsigned short V_215 ;
unsigned int V_216 = 64 ;
#if V_217 != 64
if ( V_2 -> V_14 == V_218 ) {
T_4 V_219 ;
F_17 ( V_25 , 0x40 , & V_219 ) ;
F_18 ( V_25 , 0x40 , V_219 | 0x10 ) ;
F_149 ( V_25 , V_220 , 0 ) ;
}
#endif
V_149 = F_150 ( V_25 , L_31 ) ;
if ( V_149 < 0 )
return V_149 ;
V_2 -> V_155 = 1 ;
V_51 -> V_135 = F_151 ( V_25 , 0 ) ;
V_51 -> V_102 = F_152 ( V_25 , 0 ) ;
if ( V_51 -> V_102 == NULL ) {
F_51 ( V_33 -> V_9 , L_32 ) ;
return - V_221 ;
}
if ( V_2 -> V_91 ) {
if ( V_2 -> V_31 & V_222 ) {
F_16 ( V_33 -> V_9 , L_33 ) ;
V_25 -> V_223 = true ;
}
if ( F_81 ( V_25 ) < 0 )
V_2 -> V_91 = 0 ;
}
if ( F_49 ( V_2 , 0 ) < 0 )
return - V_140 ;
F_153 ( V_25 ) ;
F_154 ( V_51 -> V_89 ) ;
V_215 = F_89 ( V_2 , V_224 ) ;
F_16 ( V_33 -> V_9 , L_34 , V_215 ) ;
if ( V_2 -> V_25 -> V_160 == V_162 )
V_216 = 40 ;
if ( V_2 -> V_25 -> V_160 == V_161 ) {
struct V_24 * V_225 ;
V_216 = 40 ;
V_225 = F_155 ( V_161 ,
V_226 ,
NULL ) ;
if ( V_225 ) {
if ( V_225 -> V_194 < 0x30 )
V_215 &= ~ V_227 ;
F_108 ( V_225 ) ;
}
}
if ( V_2 -> V_31 & V_228 ) {
F_16 ( V_33 -> V_9 , L_35 ) ;
V_215 &= ~ V_227 ;
}
if ( V_229 >= 0 )
V_2 -> V_229 = ! ! V_229 ;
else {
if ( V_2 -> V_31 & V_230 )
V_2 -> V_229 = 0 ;
else
V_2 -> V_229 = 1 ;
}
if ( ! ( V_215 & V_227 ) )
V_216 = 32 ;
if ( ! F_156 ( & V_25 -> V_9 , F_157 ( V_216 ) ) ) {
F_158 ( & V_25 -> V_9 , F_157 ( V_216 ) ) ;
} else {
F_156 ( & V_25 -> V_9 , F_157 ( 32 ) ) ;
F_158 ( & V_25 -> V_9 , F_157 ( 32 ) ) ;
}
V_2 -> V_231 = ( V_215 >> 8 ) & 0x0f ;
V_2 -> V_232 = ( V_215 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_232 && ! V_2 -> V_231 ) {
switch ( V_2 -> V_14 ) {
case V_218 :
V_2 -> V_232 = V_233 ;
V_2 -> V_231 = V_234 ;
break;
case V_235 :
case V_236 :
V_2 -> V_232 = V_237 ;
V_2 -> V_231 = V_238 ;
break;
case V_239 :
default:
V_2 -> V_232 = V_240 ;
V_2 -> V_231 = V_241 ;
break;
}
}
V_2 -> V_242 = 0 ;
V_2 -> V_243 = V_2 -> V_231 ;
V_2 -> V_244 = V_2 -> V_232 + V_2 -> V_231 ;
V_149 = F_159 ( V_2 ) ;
if ( V_149 < 0 )
return V_149 ;
V_149 = F_160 ( V_2 ) ;
if ( V_149 < 0 )
return V_149 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_52 ) {
struct V_65 * V_66 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
F_68 ( V_66 ) ;
}
F_22 ( V_2 , ( V_245 [ V_9 ] & 2 ) == 0 ) ;
if ( ! F_23 ( V_2 ) -> V_187 ) {
F_51 ( V_33 -> V_9 , L_36 ) ;
return - V_246 ;
}
strcpy ( V_33 -> V_247 , L_37 ) ;
F_161 ( V_33 -> V_248 , V_249 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_248 ) ) ;
snprintf ( V_33 -> V_250 , sizeof( V_33 -> V_250 ) ,
L_38 ,
V_33 -> V_248 , V_51 -> V_135 , V_51 -> V_89 ) ;
return 0 ;
}
static void F_162 ( const struct V_251 * V_156 , void * V_252 )
{
struct V_122 * V_33 = V_252 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_156 ) {
F_51 ( V_33 -> V_9 , L_39 ) ;
goto error;
}
V_2 -> V_156 = V_156 ;
if ( ! V_2 -> V_114 ) {
if ( F_99 ( V_2 ) )
goto error;
}
return;
error:
F_163 ( V_33 ) ;
F_164 ( V_25 , NULL ) ;
}
static void F_165 ( T_1 V_177 , T_1 T_5 * V_135 )
{
F_166 ( V_177 , V_135 ) ;
}
static T_1 F_167 ( T_1 T_5 * V_135 )
{
return F_168 ( V_135 ) ;
}
static void F_169 ( T_4 V_177 , T_4 T_5 * V_135 )
{
F_170 ( V_177 , V_135 ) ;
}
static T_4 F_171 ( T_4 T_5 * V_135 )
{
return F_58 ( V_135 ) ;
}
static void F_172 ( T_3 V_177 , T_3 T_5 * V_135 )
{
F_173 ( V_177 , V_135 ) ;
}
static T_3 F_174 ( T_3 T_5 * V_135 )
{
return F_175 ( V_135 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_23 ( V_2 ) ;
int V_149 ;
F_76 ( V_51 -> V_89 , V_2 ) ;
V_51 -> V_89 = - 1 ;
F_77 ( V_2 -> V_25 ) ;
V_2 -> V_91 = 0 ;
V_149 = F_49 ( V_2 , 1 ) ;
if ( V_149 < 0 )
return V_149 ;
return 0 ;
}
static int F_177 ( struct V_50 * V_51 ,
int type ,
T_6 V_253 ,
struct V_3 * V_19 )
{
struct V_1 * V_2 = F_178 ( V_51 ) ;
int V_149 ;
V_149 = F_179 ( type ,
V_51 -> V_9 ,
V_253 , V_19 ) ;
if ( V_149 < 0 )
return V_149 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_180 ( struct V_50 * V_51 , struct V_3 * V_19 )
{
struct V_1 * V_2 = F_178 ( V_51 ) ;
F_8 ( V_2 , V_19 , false ) ;
F_181 ( V_19 ) ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_253 )
{
struct V_20 * V_20 = F_183 ( V_22 ) ;
int V_112 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_112 = F_184 ( V_22 , V_253 ) ;
if ( V_112 < 0 )
return V_112 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_183 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_186 ( V_22 ) ;
}
static void F_187 ( struct V_21 * V_22 ,
struct V_254 * V_7 )
{
#ifdef F_188
struct V_255 * V_256 = F_189 ( V_22 ) ;
struct V_1 * V_2 = V_256 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_257 = F_190 ( V_7 -> V_257 ) ;
#endif
}
static int F_191 ( struct V_24 * V_25 ,
const struct V_258 * V_259 )
{
static int V_9 ;
struct V_122 * V_33 ;
struct V_65 * V_66 ;
struct V_1 * V_2 ;
bool V_260 ;
int V_149 ;
if ( V_9 >= V_261 )
return - V_246 ;
if ( ! V_70 [ V_9 ] ) {
V_9 ++ ;
return - V_262 ;
}
V_149 = F_192 ( & V_25 -> V_9 , V_263 [ V_9 ] , V_264 [ V_9 ] , V_265 ,
0 , & V_33 ) ;
if ( V_149 < 0 ) {
F_51 ( & V_25 -> V_9 , L_40 ) ;
return V_149 ;
}
V_149 = F_139 ( V_33 , V_25 , V_9 , V_259 -> V_266 , & V_2 ) ;
if ( V_149 < 0 )
goto V_267;
V_33 -> V_13 = V_2 ;
V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
F_164 ( V_25 , V_33 ) ;
V_149 = F_109 ( V_2 ) ;
if ( V_149 < 0 ) {
F_51 ( V_33 -> V_9 , L_41 ) ;
goto V_267;
}
if ( F_130 ( V_25 ) ) {
F_29 ( V_33 -> V_9 , L_42 ) ;
F_29 ( V_33 -> V_9 , L_43 ) ;
V_2 -> V_114 = true ;
}
V_260 = ! V_2 -> V_114 ;
#ifdef F_122
if ( V_268 [ V_9 ] && * V_268 [ V_9 ] ) {
F_29 ( V_33 -> V_9 , L_44 ,
V_268 [ V_9 ] ) ;
V_149 = F_193 ( V_265 , true , V_268 [ V_9 ] ,
& V_25 -> V_9 , V_202 , V_33 ,
F_162 ) ;
if ( V_149 < 0 )
goto V_267;
V_260 = false ;
}
#endif
#ifndef F_194
if ( V_2 -> V_31 & V_52 )
F_51 ( V_33 -> V_9 , L_45 ) ;
#endif
if ( V_260 )
F_34 ( & V_66 -> V_196 ) ;
V_9 ++ ;
if ( V_2 -> V_114 )
F_113 ( & V_66 -> V_143 ) ;
return 0 ;
V_267:
F_163 ( V_33 ) ;
return V_149 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 , struct V_65 , V_2 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_78 ;
int V_149 ;
V_66 -> V_113 = 1 ;
if ( V_2 -> V_31 & V_52 ) {
if ( F_195 ( V_25 ) )
V_66 -> V_118 = 1 ;
V_149 = F_196 ( V_51 ) ;
if ( V_149 < 0 ) {
if ( F_195 ( V_25 ) )
goto V_267;
else
goto V_269;
}
V_149 = F_36 ( V_51 , true ) ;
if ( V_149 < 0 ) {
F_51 ( V_2 -> V_33 -> V_9 ,
L_46 ) ;
goto V_270;
}
}
V_269:
V_149 = F_148 ( V_2 ) ;
if ( V_149 < 0 )
goto V_267;
#ifdef F_197
V_2 -> V_271 = V_271 [ V_9 ] ;
#endif
V_149 = F_198 ( V_2 , V_272 [ V_2 -> V_14 ] ) ;
if ( V_149 < 0 )
goto V_267;
#ifdef F_122
if ( V_2 -> V_156 ) {
V_149 = F_199 ( & V_2 -> V_51 , V_2 -> V_156 -> V_253 ,
V_2 -> V_156 -> V_29 ) ;
if ( V_149 < 0 )
goto V_267;
#ifndef F_200
F_123 ( V_2 -> V_156 ) ;
V_2 -> V_156 = NULL ;
#endif
}
#endif
if ( ( V_245 [ V_9 ] & 1 ) == 0 ) {
V_149 = F_201 ( V_2 ) ;
if ( V_149 < 0 )
goto V_267;
}
V_149 = F_202 ( V_2 -> V_33 ) ;
if ( V_149 < 0 )
goto V_267;
V_2 -> V_87 = 1 ;
F_59 ( V_2 ) ;
F_67 ( & V_2 -> V_51 , V_111 * 1000 ) ;
if ( F_88 ( V_2 ) || V_66 -> V_148 )
F_203 ( & V_25 -> V_9 ) ;
V_267:
if ( V_2 -> V_31 & V_52
&& ! V_66 -> V_118 )
F_36 ( V_51 , false ) ;
V_270:
if ( V_149 < 0 )
V_66 -> V_123 = 1 ;
F_113 ( & V_66 -> V_143 ) ;
return V_149 ;
}
static void F_204 ( struct V_24 * V_25 )
{
struct V_122 * V_33 = F_97 ( V_25 ) ;
if ( V_33 )
F_163 ( V_33 ) ;
}
static void F_205 ( struct V_24 * V_25 )
{
struct V_122 * V_33 = F_97 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_87 )
F_74 ( V_2 ) ;
}
