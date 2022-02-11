static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_6 ,
unsigned int V_7 )
{
T_1 V_8 = F_5 ( V_6 -> V_9 + ( V_7 << 2 ) ) ;
F_6 ( V_6 -> V_10 , V_7 , V_8 ) ;
return V_8 ;
}
static inline void F_7 ( struct V_1 * V_6 ,
T_1 V_8 , unsigned int V_7 )
{
F_8 ( V_6 -> V_10 , V_7 , V_8 ) ;
F_9 ( V_8 , V_6 -> V_9 + ( V_7 << 2 ) ) ;
}
static void F_10 ( struct V_1 * V_6 , const T_2 * V_11 ,
T_3 V_12 )
{
T_3 V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_12 , 4 ) ; V_13 ++ ) {
T_3 V_15 = F_12 ( T_3 , V_12 - V_13 * 4 , 4 ) ;
T_1 V_8 = 0 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
V_8 |= V_11 [ V_13 * 4 + V_14 ] << ( V_14 * 8 ) ;
F_7 ( V_6 , V_8 , F_13 ( V_13 ) ) ;
}
}
static void F_14 ( struct V_1 * V_6 , T_2 * V_11 ,
T_3 V_12 )
{
T_3 V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_12 , 4 ) ; V_13 ++ ) {
T_3 V_15 = F_12 ( T_3 , V_12 - V_13 * 4 , 4 ) ;
T_1 V_8 ;
V_8 = F_4 ( V_6 , F_15 ( V_13 ) ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
V_11 [ V_13 * 4 + V_14 ] = V_8 >> ( V_14 * 8 ) ;
}
}
static T_4 F_16 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
unsigned long V_18 = F_17 ( 250 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_19 ;
T_4 V_20 = 0 ;
T_1 V_8 ;
if ( V_17 -> V_12 > 16 )
return - V_21 ;
if ( V_17 -> V_12 < 1 ) {
switch ( V_17 -> V_22 & ~ V_23 ) {
case V_24 :
case V_25 :
case V_26 :
V_8 = V_27 ;
break;
default:
return - V_21 ;
}
} else {
V_8 = F_18 ( V_17 -> V_12 - 1 ) ;
}
switch ( V_17 -> V_22 & ~ V_23 ) {
case V_25 :
if ( V_17 -> V_22 & V_23 )
V_8 |= V_28 ;
else
V_8 |= V_29 ;
break;
case V_26 :
if ( V_17 -> V_22 & V_23 )
V_8 |= V_30 ;
else
V_8 |= V_31 ;
break;
case V_24 :
if ( V_17 -> V_22 & V_23 )
V_8 |= V_32 ;
else
V_8 |= V_33 ;
break;
case V_34 :
V_8 |= V_35 ;
break;
case V_36 :
V_8 |= V_37 ;
break;
default:
return - V_21 ;
}
F_7 ( V_6 , V_17 -> V_38 , V_39 ) ;
F_7 ( V_6 , V_8 , V_40 ) ;
if ( ( V_17 -> V_22 & V_26 ) == 0 ) {
F_10 ( V_6 , V_17 -> V_11 , V_17 -> V_12 ) ;
V_20 = V_17 -> V_12 ;
}
V_8 = F_4 ( V_6 , V_40 ) ;
V_8 |= V_41 ;
F_7 ( V_6 , V_8 , V_40 ) ;
V_19 = F_19 ( & V_6 -> V_42 , V_18 ) ;
if ( ! V_19 )
return - V_43 ;
V_8 = F_4 ( V_6 , V_44 ) ;
F_7 ( V_6 , 0xf00 , V_44 ) ;
if ( V_8 & V_45 )
return - V_43 ;
if ( ( V_8 & V_46 ) ||
( V_8 & V_47 ) ||
( V_8 & V_48 ) )
return - V_49 ;
switch ( ( V_8 & V_50 ) >> 16 ) {
case 0x00 :
V_17 -> V_51 = V_52 ;
break;
case 0x01 :
V_17 -> V_51 = V_53 ;
break;
case 0x02 :
V_17 -> V_51 = V_54 ;
break;
case 0x04 :
V_17 -> V_51 = V_55 ;
break;
case 0x08 :
V_17 -> V_51 = V_56 ;
break;
}
if ( ( V_17 -> V_12 > 0 ) && ( V_17 -> V_51 == V_52 ) ) {
if ( V_17 -> V_22 & V_26 ) {
T_3 V_57 = V_8 & V_58 ;
if ( F_20 ( V_57 != V_17 -> V_12 ) )
V_57 = F_12 ( T_3 , V_57 , V_17 -> V_12 ) ;
F_14 ( V_6 , V_17 -> V_11 , V_57 ) ;
V_20 = V_57 ;
}
}
return V_20 ;
}
static void F_21 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_59 )
F_22 ( V_6 -> V_59 -> V_60 . V_10 ) ;
}
static T_5 F_23 ( int V_61 , void * V_62 )
{
struct V_1 * V_6 = V_62 ;
T_5 V_20 = V_63 ;
T_1 V_8 ;
V_8 = F_4 ( V_6 , V_64 ) ;
F_7 ( V_6 , V_8 , V_64 ) ;
if ( V_8 & ( V_65 | V_66 ) )
F_24 ( & V_6 -> V_5 ) ;
if ( V_8 & V_67 ) {
}
if ( V_8 & V_68 )
V_42 ( & V_6 -> V_42 ) ;
return V_20 ;
}
static void F_25 ( struct V_1 * V_6 )
{
T_1 V_8 = F_4 ( V_6 , V_69 ) ;
V_8 |= V_70 ;
F_7 ( V_6 , V_8 , V_69 ) ;
}
static void F_26 ( struct V_1 * V_6 )
{
T_1 V_8 = F_4 ( V_6 , V_69 ) ;
V_8 &= ~ V_70 ;
F_7 ( V_6 , V_8 , V_69 ) ;
}
static int F_27 ( struct V_1 * V_6 , unsigned V_71 )
{
T_1 V_8 ;
switch ( V_71 ) {
case V_72 :
V_8 = F_28 ( 2 ) |
F_29 ( 4 ) |
F_30 ( 0x18 ) |
V_73 |
V_74 ;
break;
case V_75 :
V_8 = V_76 |
V_77 |
V_78 ;
break;
case V_79 :
F_25 ( V_6 ) ;
return 0 ;
default:
return - V_80 ;
}
F_7 ( V_6 , V_8 , V_81 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 )
{
return F_32 ( V_84 ) ;
}
static const char * F_33 ( struct V_82 * V_83 ,
unsigned int V_85 )
{
return V_84 [ V_85 ] ;
}
static int F_34 ( struct V_82 * V_83 ,
unsigned V_85 , const unsigned * * V_86 ,
unsigned * V_87 )
{
* V_86 = V_88 ;
* V_87 = F_32 ( V_88 ) ;
return 0 ;
}
static int F_35 ( struct V_82 * V_83 )
{
return F_32 ( V_89 ) ;
}
static const char * F_36 ( struct V_82 * V_83 ,
unsigned int V_71 )
{
return V_89 [ V_71 ] ;
}
static int F_37 ( struct V_82 * V_83 ,
unsigned int V_71 ,
const char * const * * V_90 ,
unsigned * const V_91 )
{
* V_91 = F_32 ( V_84 ) ;
* V_90 = V_84 ;
return 0 ;
}
static int F_38 ( struct V_82 * V_83 ,
unsigned int V_71 , unsigned int V_85 )
{
struct V_1 * V_6 = F_39 ( V_83 ) ;
return F_27 ( V_6 , V_71 ) ;
}
static int F_40 ( struct V_92 * V_93 )
{
struct V_1 * V_6 ;
struct V_94 * V_9 ;
T_1 V_8 ;
int V_95 ;
V_6 = F_41 ( & V_93 -> V_10 , sizeof( * V_6 ) , V_96 ) ;
if ( ! V_6 )
return - V_97 ;
F_42 ( & V_6 -> V_5 , F_21 ) ;
F_43 ( & V_6 -> V_42 ) ;
F_44 ( & V_6 -> V_98 ) ;
V_6 -> V_10 = & V_93 -> V_10 ;
V_9 = F_45 ( V_93 , V_99 , 0 ) ;
V_6 -> V_9 = F_46 ( & V_93 -> V_10 , V_9 ) ;
if ( F_47 ( V_6 -> V_9 ) )
return F_48 ( V_6 -> V_9 ) ;
V_6 -> V_61 = F_49 ( V_93 , 0 ) ;
if ( V_6 -> V_61 < 0 ) {
F_50 ( & V_93 -> V_10 , L_1 ) ;
return - V_100 ;
}
if ( ! V_93 -> V_10 . V_101 ) {
V_6 -> V_102 = F_51 ( & V_93 -> V_10 , L_2 ) ;
if ( F_47 ( V_6 -> V_102 ) ) {
F_50 ( & V_93 -> V_10 ,
L_3 ,
F_48 ( V_6 -> V_102 ) ) ;
return F_48 ( V_6 -> V_102 ) ;
}
}
V_6 -> V_103 = F_52 ( & V_93 -> V_10 , NULL ) ;
if ( F_47 ( V_6 -> V_103 ) ) {
F_50 ( & V_93 -> V_10 , L_4 ,
F_48 ( V_6 -> V_103 ) ) ;
return F_48 ( V_6 -> V_103 ) ;
}
V_95 = F_53 ( V_6 -> V_103 ) ;
if ( V_95 < 0 ) {
F_50 ( & V_93 -> V_10 , L_5 ,
V_95 ) ;
return V_95 ;
}
if ( V_6 -> V_102 )
F_54 ( V_6 -> V_102 ) ;
V_6 -> V_104 = F_52 ( & V_93 -> V_10 , L_6 ) ;
if ( F_47 ( V_6 -> V_104 ) ) {
F_50 ( & V_93 -> V_10 , L_7 ,
F_48 ( V_6 -> V_104 ) ) ;
V_95 = F_48 ( V_6 -> V_104 ) ;
goto V_105;
}
V_95 = F_53 ( V_6 -> V_104 ) ;
if ( V_95 < 0 ) {
F_50 ( & V_93 -> V_10 , L_8 ,
V_95 ) ;
goto V_105;
}
V_95 = F_55 ( V_6 -> V_104 , 270000000 ) ;
if ( V_95 < 0 ) {
F_50 ( & V_93 -> V_10 , L_9 ,
V_95 ) ;
goto V_106;
}
V_6 -> V_107 = F_56 ( & V_93 -> V_10 , L_10 ) ;
if ( F_47 ( V_6 -> V_107 ) ) {
F_50 ( & V_93 -> V_10 , L_11 ,
F_48 ( V_6 -> V_107 ) ) ;
V_95 = F_48 ( V_6 -> V_107 ) ;
goto V_106;
}
V_95 = F_57 ( V_6 -> V_10 , V_6 -> V_61 , F_23 , 0 ,
F_58 ( V_6 -> V_10 ) , V_6 ) ;
if ( V_95 < 0 ) {
F_50 ( V_6 -> V_10 , L_12 ,
V_6 -> V_61 , V_95 ) ;
goto V_106;
}
F_59 ( V_6 -> V_61 ) ;
V_6 -> V_3 . V_108 = F_16 ;
V_6 -> V_3 . V_10 = & V_93 -> V_10 ;
V_95 = F_60 ( & V_6 -> V_3 ) ;
if ( V_95 < 0 )
goto V_106;
V_95 = F_27 ( V_6 , V_78 ) ;
if ( V_95 < 0 )
return V_95 ;
#ifdef F_61
V_6 -> V_109 . V_110 = F_58 ( & V_93 -> V_10 ) ;
V_6 -> V_109 . V_86 = V_111 ;
V_6 -> V_109 . V_112 = F_32 ( V_111 ) ;
V_6 -> V_109 . V_113 = & V_114 ;
V_6 -> V_109 . V_115 = & V_116 ;
V_6 -> V_109 . V_117 = V_118 ;
V_6 -> V_83 = F_62 ( & V_93 -> V_10 , & V_6 -> V_109 , V_6 ) ;
if ( F_47 ( V_6 -> V_83 ) ) {
F_50 ( & V_93 -> V_10 , L_13 ) ;
return F_48 ( V_6 -> V_83 ) ;
}
#endif
V_8 = V_68 | V_67 |
V_66 | V_65 ;
F_7 ( V_6 , V_8 , V_119 ) ;
F_7 ( V_6 , V_8 , V_64 ) ;
F_63 ( & V_120 ) ;
F_64 ( & V_6 -> V_98 , & V_121 ) ;
F_65 ( & V_120 ) ;
F_66 ( V_93 , V_6 ) ;
return 0 ;
V_106:
F_67 ( V_6 -> V_104 ) ;
V_105:
if ( V_6 -> V_102 )
F_68 ( V_6 -> V_102 ) ;
F_67 ( V_6 -> V_103 ) ;
return V_95 ;
}
static int F_69 ( struct V_92 * V_93 )
{
struct V_1 * V_6 = F_70 ( V_93 ) ;
F_25 ( V_6 ) ;
F_71 ( & V_6 -> V_3 ) ;
F_63 ( & V_120 ) ;
F_72 ( & V_6 -> V_98 ) ;
F_65 ( & V_120 ) ;
F_73 ( & V_6 -> V_5 ) ;
F_67 ( V_6 -> V_104 ) ;
if ( V_6 -> V_102 )
F_68 ( V_6 -> V_102 ) ;
F_67 ( V_6 -> V_103 ) ;
return 0 ;
}
struct V_2 * F_74 ( struct V_122 * V_123 )
{
struct V_1 * V_6 ;
F_63 ( & V_120 ) ;
F_75 (dpaux, &dpaux_list, list)
if ( V_123 == V_6 -> V_10 -> V_124 ) {
F_65 ( & V_120 ) ;
return & V_6 -> V_3 ;
}
F_65 ( & V_120 ) ;
return NULL ;
}
int F_76 ( struct V_2 * V_3 , struct V_125 * V_59 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_18 ;
int V_95 ;
V_59 -> V_60 . V_126 = V_127 ;
V_6 -> V_59 = V_59 ;
V_95 = F_77 ( V_6 -> V_107 ) ;
if ( V_95 < 0 )
return V_95 ;
V_18 = V_128 + F_17 ( 250 ) ;
while ( F_78 ( V_128 , V_18 ) ) {
enum V_129 V_19 ;
V_19 = F_79 ( V_3 ) ;
if ( V_19 == V_130 ) {
F_80 ( V_6 -> V_61 ) ;
return 0 ;
}
F_81 ( 1000 , 2000 ) ;
}
return - V_43 ;
}
int F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_18 ;
int V_95 ;
F_59 ( V_6 -> V_61 ) ;
V_95 = F_83 ( V_6 -> V_107 ) ;
if ( V_95 < 0 )
return V_95 ;
V_18 = V_128 + F_17 ( 250 ) ;
while ( F_78 ( V_128 , V_18 ) ) {
enum V_129 V_19 ;
V_19 = F_79 ( V_3 ) ;
if ( V_19 == V_131 ) {
V_6 -> V_59 = NULL ;
return 0 ;
}
F_81 ( 1000 , 2000 ) ;
}
return - V_43 ;
}
enum V_129 F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_8 ;
V_8 = F_4 ( V_6 , V_44 ) ;
if ( V_8 & V_132 )
return V_130 ;
return V_131 ;
}
int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_27 ( V_6 , V_72 ) ;
}
int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
int F_86 ( struct V_2 * V_3 , T_2 V_133 )
{
int V_95 ;
V_95 = F_87 ( V_3 , V_134 ,
V_133 ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
int F_88 ( struct V_2 * V_3 , struct V_135 * V_136 ,
T_2 V_137 )
{
T_2 V_138 = V_137 & V_139 ;
T_2 V_19 [ V_140 ] , V_141 [ 4 ] ;
unsigned int V_13 ;
int V_95 ;
V_95 = F_87 ( V_3 , V_142 , V_137 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_138 == V_143 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_136 -> V_144 ; V_13 ++ )
V_141 [ V_13 ] = V_145 |
V_146 |
V_147 |
V_148 ;
V_95 = F_89 ( V_3 , V_149 , V_141 ,
V_136 -> V_144 ) ;
if ( V_95 < 0 )
return V_95 ;
F_81 ( 500 , 1000 ) ;
V_95 = F_90 ( V_3 , V_19 ) ;
if ( V_95 < 0 )
return V_95 ;
switch ( V_138 ) {
case V_150 :
if ( ! F_91 ( V_19 , V_136 -> V_144 ) )
return - V_151 ;
break;
case V_152 :
if ( ! F_92 ( V_19 , V_136 -> V_144 ) )
return - V_151 ;
break;
default:
F_50 ( V_3 -> V_10 , L_14 , V_138 ) ;
return - V_21 ;
}
V_95 = F_87 ( V_3 , V_153 , 0 ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
