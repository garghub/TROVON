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
static int F_26 ( struct V_20 * V_21 , struct V_54 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_56 , V_57 ;
T_3 V_58 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_7 , ( long long ) V_55 -> V_56 ,
( long long ) V_55 -> V_57 ) ;
F_27 ( V_55 -> V_57 , V_21 -> V_59 , & V_58 ) ;
if ( V_58 )
return - V_60 ;
V_56 = V_55 -> V_56 ;
V_57 = V_55 -> V_57 ;
V_3 = F_22 ( V_2 , V_61 ) ;
if ( V_3 )
return V_3 ;
if ( V_57 == V_21 -> V_47 ) {
unsigned long V_43 ;
F_8 ( V_2 ) ;
if ( F_20 ( V_2 ) ) {
V_3 = - V_62 ;
goto V_63;
}
V_43 = F_28 ( V_64 ,
V_64 *
( unsigned long ) ( V_21 -> V_47 / V_65 ) ) ;
V_3 = F_16 ( V_2 , V_43 ) ;
if ( V_3 )
goto V_63;
} else {
while ( V_57 ) {
F_8 ( V_2 ) ;
if ( V_2 -> V_66 ( V_2 , V_56 ) ) {
V_3 = - V_62 ;
goto V_63;
}
V_56 += V_21 -> V_59 ;
V_57 -= V_21 -> V_59 ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_63;
}
}
F_9 ( V_2 ) ;
F_25 ( V_2 , V_61 ) ;
V_55 -> V_67 = V_68 ;
F_29 ( V_55 ) ;
return V_3 ;
V_63:
F_25 ( V_2 , V_61 ) ;
V_55 -> V_67 = V_69 ;
return V_3 ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_35 , T_4 * V_70 ,
T_5 * V_57 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_1 V_71 = V_72 | V_73 | V_74 ;
int V_75 = F_31 ( V_71 ) - 1 ;
int pow ;
if ( ! ( V_35 & V_71 ) ) {
* V_70 = 0 ;
* V_57 = 0 ;
} else {
pow = ( ( V_35 & V_71 ) ^ V_71 ) >> V_75 ;
* V_57 = V_21 -> V_47 >> pow ;
* V_70 = V_21 -> V_47 - * V_57 ;
}
}
static int F_32 ( struct V_1 * V_2 , T_4 V_70 , T_5 V_57 ,
T_1 V_35 )
{
T_4 V_76 ;
T_5 V_77 ;
F_30 ( V_2 , V_35 , & V_76 , & V_77 ) ;
return ( V_70 + V_57 <= V_76 + V_77 ) && ( V_70 >= V_76 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_4 V_70 , T_5 V_57 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_1 V_78 , V_79 ;
T_1 V_71 = V_72 | V_73 | V_74 ;
T_1 V_75 = F_31 ( V_71 ) - 1 , pow , V_4 ;
V_78 = F_1 ( V_2 ) ;
if ( V_70 + V_57 != V_21 -> V_47 ) {
if ( ! F_32 ( V_2 , V_70 + V_57 , V_21 -> V_47 - V_70 - V_57 ,
V_78 ) )
return - V_60 ;
V_57 = V_21 -> V_47 - V_70 ;
}
pow = F_34 ( V_21 -> V_47 ) - F_34 ( V_57 ) ;
V_4 = V_71 - ( pow << V_75 ) ;
if ( V_4 & ~ V_71 )
return - V_60 ;
if ( ! ( V_4 & V_71 ) )
return - V_60 ;
V_79 = ( V_78 & ~ V_71 ) | V_4 ;
if ( ( V_79 & V_71 ) <= ( V_78 & V_71 ) )
return - V_60 ;
F_8 ( V_2 ) ;
return F_7 ( V_2 , V_79 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_4 V_70 , T_5 V_57 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_6 V_78 , V_79 ;
T_1 V_71 = V_72 | V_73 | V_74 ;
T_1 V_75 = F_31 ( V_71 ) - 1 , pow , V_4 ;
V_78 = F_1 ( V_2 ) ;
if ( F_32 ( V_2 , V_70 - V_21 -> V_59 , V_21 -> V_59 ,
V_78 ) )
return - V_60 ;
pow = F_34 ( V_21 -> V_47 ) - F_36 ( V_21 -> V_47 - ( V_70 + V_57 ) ) ;
if ( V_70 + V_57 == V_21 -> V_47 ) {
V_4 = 0 ;
} else {
V_4 = V_71 - ( pow << V_75 ) ;
if ( V_4 & ~ V_71 )
return - V_60 ;
}
V_79 = ( V_78 & ~ V_71 ) | V_4 ;
if ( ( V_79 & V_71 ) >= ( V_78 & V_71 ) )
return - V_60 ;
F_8 ( V_2 ) ;
return F_7 ( V_2 , V_79 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_4 V_70 , T_5 V_57 )
{
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_32 ( V_2 , V_70 , V_57 , V_26 ) ;
}
static int F_38 ( struct V_20 * V_21 , T_4 V_70 , T_5 V_57 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_80 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_81 ( V_2 , V_70 , V_57 ) ;
F_25 ( V_2 , V_82 ) ;
return V_3 ;
}
static int F_39 ( struct V_20 * V_21 , T_4 V_70 , T_5 V_57 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_82 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_83 ( V_2 , V_70 , V_57 ) ;
F_25 ( V_2 , V_80 ) ;
return V_3 ;
}
static int F_40 ( struct V_20 * V_21 , T_4 V_70 , T_5 V_57 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_82 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_84 ( V_2 , V_70 , V_57 ) ;
F_25 ( V_2 , V_80 ) ;
return V_3 ;
}
static const struct V_23 * F_41 ( struct V_1 * V_2 )
{
int V_85 ;
T_1 V_86 [ V_87 ] ;
const struct V_23 * V_24 ;
V_85 = V_2 -> V_5 ( V_2 , V_88 , V_86 , V_87 ) ;
if ( V_85 < 0 ) {
F_21 ( V_2 -> V_9 , L_8 , V_85 ) ;
return F_42 ( V_85 ) ;
}
for ( V_85 = 0 ; V_85 < F_43 ( V_89 ) - 1 ; V_85 ++ ) {
V_24 = & V_89 [ V_85 ] ;
if ( V_24 -> V_90 ) {
if ( ! memcmp ( V_24 -> V_86 , V_86 , V_24 -> V_90 ) )
return & V_89 [ V_85 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] ) ;
return F_42 ( - V_91 ) ;
}
static int F_44 ( struct V_20 * V_21 , T_4 V_92 , T_7 V_57 ,
T_7 * V_93 , T_8 * V_94 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_10 , ( T_2 ) V_92 , V_57 ) ;
V_3 = F_22 ( V_2 , V_95 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_96 ( V_2 , V_92 , V_57 , V_93 , V_94 ) ;
F_25 ( V_2 , V_95 ) ;
return V_3 ;
}
static int F_45 ( struct V_20 * V_21 , T_4 V_97 , T_7 V_57 ,
T_7 * V_93 , const T_8 * V_94 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_7 V_98 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_97 , V_57 ) ;
V_3 = F_22 ( V_2 , V_99 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_100 = false ;
V_98 = V_97 % 2 ;
if ( V_98 ) {
V_2 -> V_101 = V_102 ;
V_2 -> V_103 ( V_2 , V_97 , 1 , V_93 , V_94 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_104;
}
V_97 += V_98 ;
for (; V_98 < V_57 - 1 ; V_98 += 2 ) {
V_2 -> V_101 = V_105 ;
V_2 -> V_103 ( V_2 , V_97 , 2 , V_93 , V_94 + V_98 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_104;
V_97 += 2 ;
V_2 -> V_100 = true ;
}
V_2 -> V_100 = false ;
F_9 ( V_2 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_104;
if ( V_98 != V_57 ) {
F_8 ( V_2 ) ;
V_2 -> V_101 = V_102 ;
V_2 -> V_103 ( V_2 , V_97 , 1 , V_93 , V_94 + V_98 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_104;
F_9 ( V_2 ) ;
}
V_104:
F_25 ( V_2 , V_99 ) ;
return V_3 ;
}
static int F_46 ( struct V_20 * V_21 , T_4 V_97 , T_7 V_57 ,
T_7 * V_93 , const T_8 * V_94 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_106 , V_107 , V_108 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_97 , V_57 ) ;
V_3 = F_22 ( V_2 , V_99 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_106 = V_97 & ( V_2 -> V_107 - 1 ) ;
if ( V_106 + V_57 <= V_2 -> V_107 ) {
V_2 -> V_103 ( V_2 , V_97 , V_57 , V_93 , V_94 ) ;
} else {
V_107 = V_2 -> V_107 - V_106 ;
V_2 -> V_103 ( V_2 , V_97 , V_107 , V_93 , V_94 ) ;
for ( V_108 = V_107 ; V_108 < V_57 ; V_108 += V_107 ) {
V_107 = V_57 - V_108 ;
if ( V_107 > V_2 -> V_107 )
V_107 = V_2 -> V_107 ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_109;
F_8 ( V_2 ) ;
V_2 -> V_103 ( V_2 , V_97 + V_108 , V_107 , V_93 , V_94 + V_108 ) ;
}
}
V_3 = F_19 ( V_2 ) ;
V_109:
F_25 ( V_2 , V_99 ) ;
return V_3 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_4 | V_110 ) ;
if ( F_19 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_110 ) ) ) {
F_5 ( V_2 -> V_9 , L_12 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_9 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_3 ;
int V_111 = V_112 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_48 ( V_2 , V_111 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_13 ) ;
return - V_60 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_112 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_113 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 & ~ V_114 ;
V_3 = V_2 -> V_16 ( V_2 , V_115 , V_2 -> V_15 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return V_3 ;
}
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_113 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
if ( V_4 & V_114 ) {
F_5 ( V_2 -> V_9 , L_17 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
int V_26 ;
switch ( F_12 ( V_24 ) ) {
case V_30 :
V_26 = F_47 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_18 ) ;
return - V_60 ;
}
return V_26 ;
case V_29 :
V_26 = F_50 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_60 ;
}
return V_26 ;
default:
V_26 = F_49 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_20 ) ;
return - V_60 ;
}
return V_26 ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_96 || ! V_2 -> V_103 ||
! V_2 -> V_5 || ! V_2 -> V_16 || ! V_2 -> V_66 ) {
F_2 ( L_21 ) ;
return - V_60 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 , const char * V_116 , enum V_117 V_118 )
{
const struct V_23 * V_24 = NULL ;
struct V_119 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_120 * V_121 = V_2 -> V_122 ;
int V_3 ;
int V_108 ;
V_3 = F_52 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_116 )
V_24 = F_54 ( V_116 ) ;
if ( ! V_24 )
V_24 = F_41 ( V_2 ) ;
if ( F_55 ( V_24 ) )
return - V_123 ;
if ( V_116 && V_24 -> V_90 ) {
const struct V_23 * V_124 ;
V_124 = F_41 ( V_2 ) ;
if ( F_56 ( V_124 ) ) {
return F_57 ( V_124 ) ;
} else if ( V_124 != V_24 ) {
F_58 ( V_9 , L_22 ,
V_124 -> V_116 , V_24 -> V_116 ) ;
V_24 = V_124 ;
}
}
F_59 ( & V_2 -> V_51 ) ;
if ( F_12 ( V_24 ) == V_125 ||
F_12 ( V_24 ) == V_126 ||
F_12 ( V_24 ) == V_127 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( ! V_21 -> V_116 )
V_21 -> V_116 = F_60 ( V_9 ) ;
V_21 -> V_22 = V_2 ;
V_21 -> type = V_128 ;
V_21 -> V_129 = 1 ;
V_21 -> V_39 = V_130 ;
V_21 -> V_47 = V_24 -> V_131 * V_24 -> V_132 ;
V_21 -> V_133 = F_26 ;
V_21 -> V_134 = F_44 ;
if ( F_12 ( V_24 ) == V_29 ) {
V_2 -> V_81 = F_33 ;
V_2 -> V_83 = F_35 ;
V_2 -> V_84 = F_37 ;
}
if ( V_2 -> V_81 && V_2 -> V_83 && V_2 -> V_84 ) {
V_21 -> V_135 = F_38 ;
V_21 -> V_136 = F_39 ;
V_21 -> V_137 = F_40 ;
}
if ( V_24 -> V_39 & V_138 )
V_21 -> V_139 = F_45 ;
else
V_21 -> V_139 = F_46 ;
if ( V_24 -> V_39 & V_140 )
V_2 -> V_39 |= V_40 ;
#ifdef F_61
if ( V_24 -> V_39 & V_141 ) {
V_2 -> V_142 = V_143 ;
V_21 -> V_59 = 4096 ;
} else if ( V_24 -> V_39 & V_144 ) {
V_2 -> V_142 = V_145 ;
V_21 -> V_59 = 4096 ;
} else
#endif
{
V_2 -> V_142 = V_146 ;
V_21 -> V_59 = V_24 -> V_131 ;
}
if ( V_24 -> V_39 & V_147 )
V_21 -> V_39 |= V_148 ;
V_21 -> V_9 . V_149 = V_9 ;
V_2 -> V_107 = V_24 -> V_107 ;
V_21 -> V_150 = V_2 -> V_107 ;
if ( V_121 ) {
if ( F_62 ( V_121 , L_23 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_39 & V_151 )
V_2 -> V_10 = V_14 ;
if ( V_118 == V_13 && V_24 -> V_39 & V_152 ) {
V_3 = F_51 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_24 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_118 == V_12 && V_24 -> V_39 & V_153 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_154 = V_155 ;
break;
case V_12 :
V_2 -> V_154 = V_156 ;
break;
case V_11 :
V_2 -> V_154 = V_157 ;
break;
case V_14 :
V_2 -> V_154 = V_158 ;
break;
default:
F_5 ( V_9 , L_25 ) ;
return - V_60 ;
}
V_2 -> V_101 = V_159 ;
if ( V_24 -> V_160 )
V_2 -> V_160 = V_24 -> V_160 ;
else if ( V_21 -> V_47 > 0x1000000 ) {
V_2 -> V_160 = 4 ;
if ( F_12 ( V_24 ) == V_161 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_154 = V_162 ;
break;
case V_12 :
V_2 -> V_154 = V_163 ;
break;
case V_11 :
V_2 -> V_154 = V_164 ;
break;
case V_14 :
V_2 -> V_154 = V_165 ;
break;
}
V_2 -> V_101 = V_166 ;
V_2 -> V_142 = V_167 ;
V_21 -> V_59 = V_24 -> V_131 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_160 = 3 ;
}
V_2 -> V_168 = F_6 ( V_2 ) ;
F_63 ( V_9 , L_26 , V_24 -> V_116 ,
( long long ) V_21 -> V_47 >> 10 ) ;
F_21 ( V_9 ,
L_27
L_28 ,
V_21 -> V_116 , ( long long ) V_21 -> V_47 , ( long long ) ( V_21 -> V_47 >> 20 ) ,
V_21 -> V_59 , V_21 -> V_59 / 1024 , V_21 -> V_169 ) ;
if ( V_21 -> V_169 )
for ( V_108 = 0 ; V_108 < V_21 -> V_169 ; V_108 ++ )
F_21 ( V_9 ,
L_29
L_30
L_31 ,
V_108 , ( long long ) V_21 -> V_170 [ V_108 ] . V_171 ,
V_21 -> V_170 [ V_108 ] . V_59 ,
V_21 -> V_170 [ V_108 ] . V_59 / 1024 ,
V_21 -> V_170 [ V_108 ] . V_172 ) ;
return 0 ;
}
static const struct V_23 * F_54 ( const char * V_116 )
{
const struct V_23 * V_86 = V_89 ;
while ( V_86 -> V_116 ) {
if ( ! strcmp ( V_116 , V_86 -> V_116 ) )
return V_86 ;
V_86 ++ ;
}
return NULL ;
}
