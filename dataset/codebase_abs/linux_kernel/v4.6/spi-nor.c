static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_6 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_1 , ( int ) V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_7 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_2 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_8 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_3 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
return 8 ;
case V_14 :
return 0 ;
}
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_18 , NULL , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_19 , NULL , 0 ) ;
}
static inline struct V_1 * F_10 ( struct V_20 * V_21 )
{
return V_21 -> V_22 ;
}
static inline int F_11 ( struct V_1 * V_2 , const struct V_23 * V_24 ,
int V_25 )
{
int V_26 ;
bool V_27 = false ;
T_1 V_28 ;
switch ( F_12 ( V_24 ) ) {
case V_29 :
V_27 = true ;
case V_30 :
case V_31 :
if ( V_27 )
F_8 ( V_2 ) ;
V_28 = V_25 ? V_32 : V_33 ;
V_26 = V_2 -> V_16 ( V_2 , V_28 , NULL , 0 ) ;
if ( V_27 )
F_9 ( V_2 ) ;
return V_26 ;
default:
V_2 -> V_15 [ 0 ] = V_25 << 7 ;
return V_2 -> V_16 ( V_2 , V_34 , V_2 -> V_15 , 1 ) ;
}
}
static inline int F_13 ( struct V_1 * V_2 )
{
int V_35 = F_1 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
else
return ! ( V_35 & V_36 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
int V_37 = F_3 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
else
return V_37 & V_38 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_35 , V_37 ;
V_35 = F_13 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_37 = V_2 -> V_39 & V_40 ? F_14 ( V_2 ) : 1 ;
if ( V_37 < 0 )
return V_37 ;
return V_35 && V_37 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_41 )
{
unsigned long V_42 ;
int V_43 = 0 , V_3 ;
V_42 = V_44 + V_41 ;
while ( ! V_43 ) {
if ( F_17 ( V_44 , V_42 ) )
V_43 = 1 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_18 () ;
}
F_5 ( V_2 -> V_9 , L_4 ) ;
return - V_45 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ,
V_46 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_9 , L_5 , ( long long ) ( V_2 -> V_21 . V_47 >> 10 ) ) ;
return V_2 -> V_16 ( V_2 , V_48 , NULL , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , enum V_49 V_50 )
{
int V_3 = 0 ;
F_23 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_52 ) {
V_3 = V_2 -> V_52 ( V_2 , V_50 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_6 ) ;
F_24 ( & V_2 -> V_51 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_25 ( struct V_1 * V_2 , enum V_49 V_50 )
{
if ( V_2 -> V_53 )
V_2 -> V_53 ( V_2 , V_50 ) ;
F_24 ( & V_2 -> V_51 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_2 V_54 )
{
T_1 V_55 [ V_56 ] ;
int V_57 ;
if ( V_2 -> V_58 )
return V_2 -> V_58 ( V_2 , V_54 ) ;
for ( V_57 = V_2 -> V_59 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_55 [ V_57 ] = V_54 & 0xff ;
V_54 >>= 8 ;
}
return V_2 -> V_16 ( V_2 , V_2 -> V_60 , V_55 , V_2 -> V_59 ) ;
}
static int F_27 ( struct V_20 * V_21 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_54 , V_63 ;
T_3 V_64 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_7 , ( long long ) V_62 -> V_54 ,
( long long ) V_62 -> V_63 ) ;
F_28 ( V_62 -> V_63 , V_21 -> V_65 , & V_64 ) ;
if ( V_64 )
return - V_66 ;
V_54 = V_62 -> V_54 ;
V_63 = V_62 -> V_63 ;
V_3 = F_22 ( V_2 , V_67 ) ;
if ( V_3 )
return V_3 ;
if ( V_63 == V_21 -> V_47 ) {
unsigned long V_43 ;
F_8 ( V_2 ) ;
if ( F_20 ( V_2 ) ) {
V_3 = - V_68 ;
goto V_69;
}
V_43 = F_29 ( V_70 ,
V_70 *
( unsigned long ) ( V_21 -> V_47 / V_71 ) ) ;
V_3 = F_16 ( V_2 , V_43 ) ;
if ( V_3 )
goto V_69;
} else {
while ( V_63 ) {
F_8 ( V_2 ) ;
V_3 = F_26 ( V_2 , V_54 ) ;
if ( V_3 )
goto V_69;
V_54 += V_21 -> V_65 ;
V_63 -= V_21 -> V_65 ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_69;
}
}
F_9 ( V_2 ) ;
V_69:
F_25 ( V_2 , V_67 ) ;
V_62 -> V_72 = V_3 ? V_73 : V_74 ;
F_30 ( V_62 ) ;
return V_3 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_35 , T_4 * V_75 ,
T_5 * V_63 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_1 V_76 = V_77 | V_78 | V_79 ;
int V_80 = F_32 ( V_76 ) - 1 ;
int pow ;
if ( ! ( V_35 & V_76 ) ) {
* V_75 = 0 ;
* V_63 = 0 ;
} else {
pow = ( ( V_35 & V_76 ) ^ V_76 ) >> V_80 ;
* V_63 = V_21 -> V_47 >> pow ;
if ( V_2 -> V_39 & V_81 && V_35 & V_82 )
* V_75 = 0 ;
else
* V_75 = V_21 -> V_47 - * V_63 ;
}
}
static int F_33 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 ,
T_1 V_35 , bool V_83 )
{
T_4 V_84 ;
T_5 V_85 ;
if ( ! V_63 )
return 1 ;
F_31 ( V_2 , V_35 , & V_84 , & V_85 ) ;
if ( V_83 )
return ( V_75 + V_63 <= V_84 + V_85 ) && ( V_75 >= V_84 ) ;
else
return ( V_75 >= V_84 + V_85 ) || ( V_75 + V_63 <= V_84 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 ,
T_1 V_35 )
{
return F_33 ( V_2 , V_75 , V_63 , V_35 , true ) ;
}
static int F_35 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 ,
T_1 V_35 )
{
return F_33 ( V_2 , V_75 , V_63 , V_35 , false ) ;
}
static int F_36 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_86 , V_87 ;
T_1 V_76 = V_77 | V_78 | V_79 ;
T_1 V_80 = F_32 ( V_76 ) - 1 , pow , V_4 ;
T_4 V_85 ;
bool V_88 = true , V_89 = V_2 -> V_39 & V_81 ;
bool V_90 ;
int V_3 ;
V_86 = F_1 ( V_2 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( F_34 ( V_2 , V_75 , V_63 , V_86 ) )
return 0 ;
if ( ! F_34 ( V_2 , 0 , V_75 , V_86 ) )
V_89 = false ;
if ( ! F_34 ( V_2 , V_75 + V_63 , V_21 -> V_47 - ( V_75 + V_63 ) ,
V_86 ) )
V_88 = false ;
if ( ! V_89 && ! V_88 )
return - V_66 ;
V_90 = V_88 ;
if ( V_90 )
V_85 = V_21 -> V_47 - V_75 ;
else
V_85 = V_75 + V_63 ;
pow = F_37 ( V_21 -> V_47 ) - F_37 ( V_85 ) ;
V_4 = V_76 - ( pow << V_80 ) ;
if ( V_4 & ~ V_76 )
return - V_66 ;
if ( ! ( V_4 & V_76 ) )
return - V_66 ;
V_87 = ( V_86 & ~ V_76 & ~ V_82 ) | V_4 ;
V_87 |= V_91 ;
if ( ! V_90 )
V_87 |= V_82 ;
if ( V_87 == V_86 )
return 0 ;
if ( ( V_87 & V_76 ) < ( V_86 & V_76 ) )
return - V_66 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_87 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_86 , V_87 ;
T_1 V_76 = V_77 | V_78 | V_79 ;
T_1 V_80 = F_32 ( V_76 ) - 1 , pow , V_4 ;
T_4 V_85 ;
bool V_88 = true , V_89 = V_2 -> V_39 & V_81 ;
bool V_90 ;
int V_3 ;
V_86 = F_1 ( V_2 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( F_35 ( V_2 , V_75 , V_63 , V_86 ) )
return 0 ;
if ( ! F_35 ( V_2 , 0 , V_75 , V_86 ) )
V_88 = false ;
if ( ! F_35 ( V_2 , V_75 + V_63 , V_21 -> V_47 - ( V_75 + V_63 ) ,
V_86 ) )
V_89 = false ;
if ( ! V_89 && ! V_88 )
return - V_66 ;
V_90 = V_88 ;
if ( V_90 )
V_85 = V_21 -> V_47 - ( V_75 + V_63 ) ;
else
V_85 = V_75 ;
pow = F_37 ( V_21 -> V_47 ) - F_39 ( V_85 ) ;
if ( V_85 == 0 ) {
V_4 = 0 ;
} else {
V_4 = V_76 - ( pow << V_80 ) ;
if ( V_4 & ~ V_76 )
return - V_66 ;
}
V_87 = ( V_86 & ~ V_76 & ~ V_82 ) | V_4 ;
if ( V_85 == V_21 -> V_47 )
V_87 &= ~ V_91 ;
if ( ! V_90 )
V_87 |= V_82 ;
if ( V_87 == V_86 )
return 0 ;
if ( ( V_87 & V_76 ) > ( V_86 & V_76 ) )
return - V_66 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_87 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_34 ( V_2 , V_75 , V_63 , V_26 ) ;
}
static int F_41 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_92 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_93 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_94 ) ;
return V_3 ;
}
static int F_42 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_94 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_95 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_92 ) ;
return V_3 ;
}
static int F_43 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_94 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_96 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_92 ) ;
return V_3 ;
}
static const struct V_23 * F_44 ( struct V_1 * V_2 )
{
int V_97 ;
T_1 V_98 [ V_99 ] ;
const struct V_23 * V_24 ;
V_97 = V_2 -> V_5 ( V_2 , V_100 , V_98 , V_99 ) ;
if ( V_97 < 0 ) {
F_21 ( V_2 -> V_9 , L_8 , V_97 ) ;
return F_45 ( V_97 ) ;
}
for ( V_97 = 0 ; V_97 < F_46 ( V_101 ) - 1 ; V_97 ++ ) {
V_24 = & V_101 [ V_97 ] ;
if ( V_24 -> V_102 ) {
if ( ! memcmp ( V_24 -> V_98 , V_98 , V_24 -> V_102 ) )
return & V_101 [ V_97 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_98 [ 0 ] , V_98 [ 1 ] , V_98 [ 2 ] ) ;
return F_45 ( - V_103 ) ;
}
static int F_47 ( struct V_20 * V_21 , T_4 V_104 , T_6 V_63 ,
T_6 * V_105 , T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_10 , ( T_2 ) V_104 , V_63 ) ;
V_3 = F_22 ( V_2 , V_106 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_107 ( V_2 , V_104 , V_63 , V_105 , V_55 ) ;
F_25 ( V_2 , V_106 ) ;
return V_3 ;
}
static int F_48 ( struct V_20 * V_21 , T_4 V_108 , T_6 V_63 ,
T_6 * V_105 , const T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_6 V_109 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_108 , V_63 ) ;
V_3 = F_22 ( V_2 , V_110 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_111 = false ;
V_109 = V_108 % 2 ;
if ( V_109 ) {
V_2 -> V_112 = V_113 ;
V_2 -> V_114 ( V_2 , V_108 , 1 , V_105 , V_55 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_115;
}
V_108 += V_109 ;
for (; V_109 < V_63 - 1 ; V_109 += 2 ) {
V_2 -> V_112 = V_116 ;
V_2 -> V_114 ( V_2 , V_108 , 2 , V_105 , V_55 + V_109 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_115;
V_108 += 2 ;
V_2 -> V_111 = true ;
}
V_2 -> V_111 = false ;
F_9 ( V_2 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_115;
if ( V_109 != V_63 ) {
F_8 ( V_2 ) ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 ( V_2 , V_108 , 1 , V_105 , V_55 + V_109 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_115;
F_9 ( V_2 ) ;
}
V_115:
F_25 ( V_2 , V_110 ) ;
return V_3 ;
}
static int F_49 ( struct V_20 * V_21 , T_4 V_108 , T_6 V_63 ,
T_6 * V_105 , const T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_117 , V_118 , V_57 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_108 , V_63 ) ;
V_3 = F_22 ( V_2 , V_110 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_117 = V_108 & ( V_2 -> V_118 - 1 ) ;
if ( V_117 + V_63 <= V_2 -> V_118 ) {
V_2 -> V_114 ( V_2 , V_108 , V_63 , V_105 , V_55 ) ;
} else {
V_118 = V_2 -> V_118 - V_117 ;
V_2 -> V_114 ( V_2 , V_108 , V_118 , V_105 , V_55 ) ;
for ( V_57 = V_118 ; V_57 < V_63 ; V_57 += V_118 ) {
V_118 = V_63 - V_57 ;
if ( V_118 > V_2 -> V_118 )
V_118 = V_2 -> V_118 ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_119;
F_8 ( V_2 ) ;
V_2 -> V_114 ( V_2 , V_108 + V_57 , V_118 , V_105 , V_55 + V_57 ) ;
}
}
V_3 = F_19 ( V_2 ) ;
V_119:
F_25 ( V_2 , V_110 ) ;
return V_3 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_4 | V_120 ) ;
if ( F_19 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_120 ) ) ) {
F_5 ( V_2 -> V_9 , L_12 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_8 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_3 ;
int V_121 = V_122 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_51 ( V_2 , V_121 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_13 ) ;
return - V_66 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_122 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
int V_26 ;
switch ( F_12 ( V_24 ) ) {
case V_30 :
V_26 = F_50 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_15 ) ;
return - V_66 ;
}
return V_26 ;
case V_29 :
return 0 ;
default:
V_26 = F_52 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return - V_66 ;
}
return V_26 ;
}
}
static int F_54 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_107 || ! V_2 -> V_114 ||
! V_2 -> V_5 || ! V_2 -> V_16 ) {
F_2 ( L_17 ) ;
return - V_66 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 , const char * V_123 , enum V_124 V_125 )
{
const struct V_23 * V_24 = NULL ;
struct V_126 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_127 * V_128 = F_56 ( V_2 ) ;
int V_3 ;
int V_57 ;
V_3 = F_54 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_123 )
V_24 = F_57 ( V_123 ) ;
if ( ! V_24 )
V_24 = F_44 ( V_2 ) ;
if ( F_58 ( V_24 ) )
return - V_129 ;
if ( V_123 && V_24 -> V_102 ) {
const struct V_23 * V_130 ;
V_130 = F_44 ( V_2 ) ;
if ( F_59 ( V_130 ) ) {
return F_60 ( V_130 ) ;
} else if ( V_130 != V_24 ) {
F_61 ( V_9 , L_18 ,
V_130 -> V_123 , V_24 -> V_123 ) ;
V_24 = V_130 ;
}
}
F_62 ( & V_2 -> V_51 ) ;
if ( F_12 ( V_24 ) == V_131 ||
F_12 ( V_24 ) == V_132 ||
F_12 ( V_24 ) == V_133 ||
V_24 -> V_39 & V_134 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
F_19 ( V_2 ) ;
}
if ( ! V_21 -> V_123 )
V_21 -> V_123 = F_63 ( V_9 ) ;
V_21 -> V_22 = V_2 ;
V_21 -> type = V_135 ;
V_21 -> V_136 = 1 ;
V_21 -> V_39 = V_137 ;
V_21 -> V_47 = V_24 -> V_138 * V_24 -> V_139 ;
V_21 -> V_140 = F_27 ;
V_21 -> V_141 = F_47 ;
if ( F_12 ( V_24 ) == V_29 ||
V_24 -> V_39 & V_134 ) {
V_2 -> V_93 = F_36 ;
V_2 -> V_95 = F_38 ;
V_2 -> V_96 = F_40 ;
}
if ( V_2 -> V_93 && V_2 -> V_95 && V_2 -> V_96 ) {
V_21 -> V_142 = F_41 ;
V_21 -> V_143 = F_42 ;
V_21 -> V_144 = F_43 ;
}
if ( V_24 -> V_39 & V_145 )
V_21 -> V_146 = F_48 ;
else
V_21 -> V_146 = F_49 ;
if ( V_24 -> V_39 & V_147 )
V_2 -> V_39 |= V_40 ;
if ( V_24 -> V_39 & V_148 )
V_2 -> V_39 |= V_81 ;
#ifdef F_64
if ( V_24 -> V_39 & V_149 ) {
V_2 -> V_60 = V_150 ;
V_21 -> V_65 = 4096 ;
} else if ( V_24 -> V_39 & V_151 ) {
V_2 -> V_60 = V_152 ;
V_21 -> V_65 = 4096 ;
} else
#endif
{
V_2 -> V_60 = V_153 ;
V_21 -> V_65 = V_24 -> V_138 ;
}
if ( V_24 -> V_39 & V_154 )
V_21 -> V_39 |= V_155 ;
V_21 -> V_9 . V_156 = V_9 ;
V_2 -> V_118 = V_24 -> V_118 ;
V_21 -> V_157 = V_2 -> V_118 ;
if ( V_128 ) {
if ( F_65 ( V_128 , L_19 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_39 & V_158 )
V_2 -> V_10 = V_14 ;
if ( V_125 == V_13 && V_24 -> V_39 & V_159 ) {
V_3 = F_53 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_20 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_125 == V_12 && V_24 -> V_39 & V_160 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_161 = V_162 ;
break;
case V_12 :
V_2 -> V_161 = V_163 ;
break;
case V_11 :
V_2 -> V_161 = V_164 ;
break;
case V_14 :
V_2 -> V_161 = V_165 ;
break;
default:
F_5 ( V_9 , L_21 ) ;
return - V_66 ;
}
V_2 -> V_112 = V_166 ;
if ( V_24 -> V_59 )
V_2 -> V_59 = V_24 -> V_59 ;
else if ( V_21 -> V_47 > 0x1000000 ) {
V_2 -> V_59 = 4 ;
if ( F_12 ( V_24 ) == V_167 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_161 = V_168 ;
break;
case V_12 :
V_2 -> V_161 = V_169 ;
break;
case V_11 :
V_2 -> V_161 = V_170 ;
break;
case V_14 :
V_2 -> V_161 = V_171 ;
break;
}
V_2 -> V_112 = V_172 ;
V_2 -> V_60 = V_173 ;
V_21 -> V_65 = V_24 -> V_138 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_59 = 3 ;
}
if ( V_2 -> V_59 > V_56 ) {
F_5 ( V_9 , L_22 ,
V_2 -> V_59 ) ;
return - V_66 ;
}
V_2 -> V_174 = F_6 ( V_2 ) ;
F_66 ( V_9 , L_23 , V_24 -> V_123 ,
( long long ) V_21 -> V_47 >> 10 ) ;
F_21 ( V_9 ,
L_24
L_25 ,
V_21 -> V_123 , ( long long ) V_21 -> V_47 , ( long long ) ( V_21 -> V_47 >> 20 ) ,
V_21 -> V_65 , V_21 -> V_65 / 1024 , V_21 -> V_175 ) ;
if ( V_21 -> V_175 )
for ( V_57 = 0 ; V_57 < V_21 -> V_175 ; V_57 ++ )
F_21 ( V_9 ,
L_26
L_27
L_28 ,
V_57 , ( long long ) V_21 -> V_176 [ V_57 ] . V_177 ,
V_21 -> V_176 [ V_57 ] . V_65 ,
V_21 -> V_176 [ V_57 ] . V_65 / 1024 ,
V_21 -> V_176 [ V_57 ] . V_178 ) ;
return 0 ;
}
static const struct V_23 * F_57 ( const char * V_123 )
{
const struct V_23 * V_98 = V_101 ;
while ( V_98 -> V_123 ) {
if ( ! strcmp ( V_123 , V_98 -> V_123 ) )
return V_98 ;
V_98 ++ ;
}
return NULL ;
}
