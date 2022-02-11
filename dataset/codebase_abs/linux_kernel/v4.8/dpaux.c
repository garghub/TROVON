static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_6 ,
unsigned long V_7 )
{
return F_5 ( V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_6 ,
T_1 V_9 , unsigned long V_7 )
{
F_7 ( V_9 , V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static void F_8 ( struct V_1 * V_6 , const T_2 * V_10 ,
T_3 V_11 )
{
T_3 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_11 , 4 ) ; V_12 ++ ) {
T_3 V_14 = F_10 ( T_3 , V_11 - V_12 * 4 , 4 ) ;
T_1 V_9 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_9 |= V_10 [ V_12 * 4 + V_13 ] << ( V_13 * 8 ) ;
F_6 ( V_6 , V_9 , F_11 ( V_12 ) ) ;
}
}
static void F_12 ( struct V_1 * V_6 , T_2 * V_10 ,
T_3 V_11 )
{
T_3 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_11 , 4 ) ; V_12 ++ ) {
T_3 V_14 = F_10 ( T_3 , V_11 - V_12 * 4 , 4 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , F_13 ( V_12 ) ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_10 [ V_12 * 4 + V_13 ] = V_9 >> ( V_13 * 8 ) ;
}
}
static T_4 F_14 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
unsigned long V_17 = F_15 ( 250 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_18 ;
T_4 V_19 = 0 ;
T_1 V_9 ;
if ( V_16 -> V_11 > 16 )
return - V_20 ;
if ( V_16 -> V_11 < 1 ) {
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_23 :
case V_24 :
case V_25 :
V_9 = V_26 ;
break;
default:
return - V_20 ;
}
} else {
V_9 = F_16 ( V_16 -> V_11 - 1 ) ;
}
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_24 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_27 ;
else
V_9 |= V_28 ;
break;
case V_25 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_29 ;
else
V_9 |= V_30 ;
break;
case V_23 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_31 ;
else
V_9 |= V_32 ;
break;
case V_33 :
V_9 |= V_34 ;
break;
case V_35 :
V_9 |= V_36 ;
break;
default:
return - V_20 ;
}
F_6 ( V_6 , V_16 -> V_37 , V_38 ) ;
F_6 ( V_6 , V_9 , V_39 ) ;
if ( ( V_16 -> V_21 & V_25 ) == 0 ) {
F_8 ( V_6 , V_16 -> V_10 , V_16 -> V_11 ) ;
V_19 = V_16 -> V_11 ;
}
V_9 = F_4 ( V_6 , V_39 ) ;
V_9 |= V_40 ;
F_6 ( V_6 , V_9 , V_39 ) ;
V_18 = F_17 ( & V_6 -> V_41 , V_17 ) ;
if ( ! V_18 )
return - V_42 ;
V_9 = F_4 ( V_6 , V_43 ) ;
F_6 ( V_6 , 0xf00 , V_43 ) ;
if ( V_9 & V_44 )
return - V_42 ;
if ( ( V_9 & V_45 ) ||
( V_9 & V_46 ) ||
( V_9 & V_47 ) )
return - V_48 ;
switch ( ( V_9 & V_49 ) >> 16 ) {
case 0x00 :
V_16 -> V_50 = V_51 ;
break;
case 0x01 :
V_16 -> V_50 = V_52 ;
break;
case 0x02 :
V_16 -> V_50 = V_53 ;
break;
case 0x04 :
V_16 -> V_50 = V_54 ;
break;
case 0x08 :
V_16 -> V_50 = V_55 ;
break;
}
if ( ( V_16 -> V_11 > 0 ) && ( V_16 -> V_50 == V_51 ) ) {
if ( V_16 -> V_21 & V_25 ) {
T_3 V_56 = V_9 & V_57 ;
if ( F_18 ( V_56 != V_16 -> V_11 ) )
V_56 = F_10 ( T_3 , V_56 , V_16 -> V_11 ) ;
F_12 ( V_6 , V_16 -> V_10 , V_56 ) ;
V_19 = V_56 ;
}
}
return V_19 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_58 )
F_20 ( V_6 -> V_58 -> V_59 . V_60 ) ;
}
static T_5 F_21 ( int V_61 , void * V_62 )
{
struct V_1 * V_6 = V_62 ;
T_5 V_19 = V_63 ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_64 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
if ( V_9 & ( V_65 | V_66 ) )
F_22 ( & V_6 -> V_5 ) ;
if ( V_9 & V_67 ) {
}
if ( V_9 & V_68 )
V_41 ( & V_6 -> V_41 ) ;
return V_19 ;
}
static void F_23 ( struct V_1 * V_6 )
{
T_1 V_9 = F_4 ( V_6 , V_69 ) ;
V_9 |= V_70 ;
F_6 ( V_6 , V_9 , V_69 ) ;
}
static void F_24 ( struct V_1 * V_6 )
{
T_1 V_9 = F_4 ( V_6 , V_69 ) ;
V_9 &= ~ V_70 ;
F_6 ( V_6 , V_9 , V_69 ) ;
}
static int F_25 ( struct V_1 * V_6 , unsigned V_71 )
{
T_1 V_9 ;
switch ( V_71 ) {
case V_72 :
V_9 = F_26 ( 2 ) |
F_27 ( 4 ) |
F_28 ( 0x18 ) |
V_73 |
V_74 ;
break;
case V_75 :
V_9 = V_76 |
V_77 |
V_78 ;
break;
case V_79 :
F_23 ( V_6 ) ;
return 0 ;
default:
return - V_80 ;
}
F_6 ( V_6 , V_9 , V_81 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int F_29 ( struct V_82 * V_83 )
{
return F_30 ( V_84 ) ;
}
static const char * F_31 ( struct V_82 * V_83 ,
unsigned int V_85 )
{
return V_84 [ V_85 ] ;
}
static int F_32 ( struct V_82 * V_83 ,
unsigned V_85 , const unsigned * * V_86 ,
unsigned * V_87 )
{
* V_86 = V_88 ;
* V_87 = F_30 ( V_88 ) ;
return 0 ;
}
static int F_33 ( struct V_82 * V_83 )
{
return F_30 ( V_89 ) ;
}
static const char * F_34 ( struct V_82 * V_83 ,
unsigned int V_71 )
{
return V_89 [ V_71 ] ;
}
static int F_35 ( struct V_82 * V_83 ,
unsigned int V_71 ,
const char * const * * V_90 ,
unsigned * const V_91 )
{
* V_91 = F_30 ( V_84 ) ;
* V_90 = V_84 ;
return 0 ;
}
static int F_36 ( struct V_82 * V_83 ,
unsigned int V_71 , unsigned int V_85 )
{
struct V_1 * V_6 = F_37 ( V_83 ) ;
return F_25 ( V_6 , V_71 ) ;
}
static int F_38 ( struct V_92 * V_93 )
{
struct V_1 * V_6 ;
struct V_94 * V_8 ;
T_1 V_9 ;
int V_95 ;
V_6 = F_39 ( & V_93 -> V_60 , sizeof( * V_6 ) , V_96 ) ;
if ( ! V_6 )
return - V_97 ;
F_40 ( & V_6 -> V_5 , F_19 ) ;
F_41 ( & V_6 -> V_41 ) ;
F_42 ( & V_6 -> V_98 ) ;
V_6 -> V_60 = & V_93 -> V_60 ;
V_8 = F_43 ( V_93 , V_99 , 0 ) ;
V_6 -> V_8 = F_44 ( & V_93 -> V_60 , V_8 ) ;
if ( F_45 ( V_6 -> V_8 ) )
return F_46 ( V_6 -> V_8 ) ;
V_6 -> V_61 = F_47 ( V_93 , 0 ) ;
if ( V_6 -> V_61 < 0 ) {
F_48 ( & V_93 -> V_60 , L_1 ) ;
return - V_100 ;
}
if ( ! V_93 -> V_60 . V_101 ) {
V_6 -> V_102 = F_49 ( & V_93 -> V_60 , L_2 ) ;
if ( F_45 ( V_6 -> V_102 ) ) {
F_48 ( & V_93 -> V_60 ,
L_3 ,
F_46 ( V_6 -> V_102 ) ) ;
return F_46 ( V_6 -> V_102 ) ;
}
}
V_6 -> V_103 = F_50 ( & V_93 -> V_60 , NULL ) ;
if ( F_45 ( V_6 -> V_103 ) ) {
F_48 ( & V_93 -> V_60 , L_4 ,
F_46 ( V_6 -> V_103 ) ) ;
return F_46 ( V_6 -> V_103 ) ;
}
V_95 = F_51 ( V_6 -> V_103 ) ;
if ( V_95 < 0 ) {
F_48 ( & V_93 -> V_60 , L_5 ,
V_95 ) ;
return V_95 ;
}
if ( V_6 -> V_102 )
F_52 ( V_6 -> V_102 ) ;
V_6 -> V_104 = F_50 ( & V_93 -> V_60 , L_6 ) ;
if ( F_45 ( V_6 -> V_104 ) ) {
F_48 ( & V_93 -> V_60 , L_7 ,
F_46 ( V_6 -> V_104 ) ) ;
V_95 = F_46 ( V_6 -> V_104 ) ;
goto V_105;
}
V_95 = F_51 ( V_6 -> V_104 ) ;
if ( V_95 < 0 ) {
F_48 ( & V_93 -> V_60 , L_8 ,
V_95 ) ;
goto V_105;
}
V_95 = F_53 ( V_6 -> V_104 , 270000000 ) ;
if ( V_95 < 0 ) {
F_48 ( & V_93 -> V_60 , L_9 ,
V_95 ) ;
goto V_106;
}
V_6 -> V_107 = F_54 ( & V_93 -> V_60 , L_10 ) ;
if ( F_45 ( V_6 -> V_107 ) ) {
F_48 ( & V_93 -> V_60 , L_11 ,
F_46 ( V_6 -> V_107 ) ) ;
V_95 = F_46 ( V_6 -> V_107 ) ;
goto V_106;
}
V_95 = F_55 ( V_6 -> V_60 , V_6 -> V_61 , F_21 , 0 ,
F_56 ( V_6 -> V_60 ) , V_6 ) ;
if ( V_95 < 0 ) {
F_48 ( V_6 -> V_60 , L_12 ,
V_6 -> V_61 , V_95 ) ;
goto V_106;
}
F_57 ( V_6 -> V_61 ) ;
V_6 -> V_3 . V_108 = F_14 ;
V_6 -> V_3 . V_60 = & V_93 -> V_60 ;
V_95 = F_58 ( & V_6 -> V_3 ) ;
if ( V_95 < 0 )
goto V_106;
V_95 = F_25 ( V_6 , V_78 ) ;
if ( V_95 < 0 )
return V_95 ;
#ifdef F_59
V_6 -> V_109 . V_110 = F_56 ( & V_93 -> V_60 ) ;
V_6 -> V_109 . V_86 = V_111 ;
V_6 -> V_109 . V_112 = F_30 ( V_111 ) ;
V_6 -> V_109 . V_113 = & V_114 ;
V_6 -> V_109 . V_115 = & V_116 ;
V_6 -> V_109 . V_117 = V_118 ;
V_6 -> V_83 = F_60 ( & V_93 -> V_60 , & V_6 -> V_109 , V_6 ) ;
if ( ! V_6 -> V_83 ) {
F_48 ( & V_93 -> V_60 , L_13 ) ;
return - V_119 ;
}
#endif
V_9 = V_68 | V_67 |
V_66 | V_65 ;
F_6 ( V_6 , V_9 , V_120 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
F_61 ( & V_121 ) ;
F_62 ( & V_6 -> V_98 , & V_122 ) ;
F_63 ( & V_121 ) ;
F_64 ( V_93 , V_6 ) ;
return 0 ;
V_106:
F_65 ( V_6 -> V_104 ) ;
V_105:
if ( V_6 -> V_102 )
F_66 ( V_6 -> V_102 ) ;
F_65 ( V_6 -> V_103 ) ;
return V_95 ;
}
static int F_67 ( struct V_92 * V_93 )
{
struct V_1 * V_6 = F_68 ( V_93 ) ;
F_23 ( V_6 ) ;
F_69 ( & V_6 -> V_3 ) ;
F_61 ( & V_121 ) ;
F_70 ( & V_6 -> V_98 ) ;
F_63 ( & V_121 ) ;
F_71 ( & V_6 -> V_5 ) ;
F_65 ( V_6 -> V_104 ) ;
if ( V_6 -> V_102 )
F_66 ( V_6 -> V_102 ) ;
F_65 ( V_6 -> V_103 ) ;
return 0 ;
}
struct V_2 * F_72 ( struct V_123 * V_124 )
{
struct V_1 * V_6 ;
F_61 ( & V_121 ) ;
F_73 (dpaux, &dpaux_list, list)
if ( V_124 == V_6 -> V_60 -> V_125 ) {
F_63 ( & V_121 ) ;
return & V_6 -> V_3 ;
}
F_63 ( & V_121 ) ;
return NULL ;
}
int F_74 ( struct V_2 * V_3 , struct V_126 * V_58 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_17 ;
int V_95 ;
V_58 -> V_59 . V_127 = V_128 ;
V_6 -> V_58 = V_58 ;
V_95 = F_75 ( V_6 -> V_107 ) ;
if ( V_95 < 0 )
return V_95 ;
V_17 = V_129 + F_15 ( 250 ) ;
while ( F_76 ( V_129 , V_17 ) ) {
enum V_130 V_18 ;
V_18 = F_77 ( V_3 ) ;
if ( V_18 == V_131 ) {
F_78 ( V_6 -> V_61 ) ;
return 0 ;
}
F_79 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_17 ;
int V_95 ;
F_57 ( V_6 -> V_61 ) ;
V_95 = F_81 ( V_6 -> V_107 ) ;
if ( V_95 < 0 )
return V_95 ;
V_17 = V_129 + F_15 ( 250 ) ;
while ( F_76 ( V_129 , V_17 ) ) {
enum V_130 V_18 ;
V_18 = F_77 ( V_3 ) ;
if ( V_18 == V_132 ) {
V_6 -> V_58 = NULL ;
return 0 ;
}
F_79 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
enum V_130 F_77 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_43 ) ;
if ( V_9 & V_133 )
return V_131 ;
return V_132 ;
}
int F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_25 ( V_6 , V_72 ) ;
}
int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_23 ( V_6 ) ;
return 0 ;
}
int F_84 ( struct V_2 * V_3 , T_2 V_134 )
{
int V_95 ;
V_95 = F_85 ( V_3 , V_135 ,
V_134 ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
int F_86 ( struct V_2 * V_3 , struct V_136 * V_137 ,
T_2 V_138 )
{
T_2 V_139 = V_138 & V_140 ;
T_2 V_18 [ V_141 ] , V_142 [ 4 ] ;
unsigned int V_12 ;
int V_95 ;
V_95 = F_85 ( V_3 , V_143 , V_138 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_139 == V_144 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_137 -> V_145 ; V_12 ++ )
V_142 [ V_12 ] = V_146 |
V_147 |
V_148 |
V_149 ;
V_95 = F_87 ( V_3 , V_150 , V_142 ,
V_137 -> V_145 ) ;
if ( V_95 < 0 )
return V_95 ;
F_79 ( 500 , 1000 ) ;
V_95 = F_88 ( V_3 , V_18 ) ;
if ( V_95 < 0 )
return V_95 ;
switch ( V_139 ) {
case V_151 :
if ( ! F_89 ( V_18 , V_137 -> V_145 ) )
return - V_152 ;
break;
case V_153 :
if ( ! F_90 ( V_18 , V_137 -> V_145 ) )
return - V_152 ;
break;
default:
F_48 ( V_3 -> V_60 , L_14 , V_139 ) ;
return - V_20 ;
}
V_95 = F_85 ( V_3 , V_154 , 0 ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
