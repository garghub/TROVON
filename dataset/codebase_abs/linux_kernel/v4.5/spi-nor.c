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
* V_75 = V_21 -> V_47 - * V_63 ;
}
}
static int F_33 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 ,
T_1 V_35 )
{
T_4 V_81 ;
T_5 V_82 ;
F_31 ( V_2 , V_35 , & V_81 , & V_82 ) ;
return ( V_75 + V_63 <= V_81 + V_82 ) && ( V_75 >= V_81 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_83 , V_84 ;
T_1 V_76 = V_77 | V_78 | V_79 ;
T_1 V_80 = F_32 ( V_76 ) - 1 , pow , V_4 ;
int V_3 ;
V_83 = F_1 ( V_2 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_75 + V_63 != V_21 -> V_47 ) {
if ( ! F_33 ( V_2 , V_75 + V_63 , V_21 -> V_47 - V_75 - V_63 ,
V_83 ) )
return - V_66 ;
V_63 = V_21 -> V_47 - V_75 ;
}
pow = F_35 ( V_21 -> V_47 ) - F_35 ( V_63 ) ;
V_4 = V_76 - ( pow << V_80 ) ;
if ( V_4 & ~ V_76 )
return - V_66 ;
if ( ! ( V_4 & V_76 ) )
return - V_66 ;
V_84 = ( V_83 & ~ V_76 ) | V_4 ;
if ( ( V_84 & V_76 ) <= ( V_83 & V_76 ) )
return - V_66 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_84 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_83 , V_84 ;
T_1 V_76 = V_77 | V_78 | V_79 ;
T_1 V_80 = F_32 ( V_76 ) - 1 , pow , V_4 ;
int V_3 ;
V_83 = F_1 ( V_2 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( F_33 ( V_2 , V_75 - V_21 -> V_65 , V_21 -> V_65 ,
V_83 ) )
return - V_66 ;
pow = F_35 ( V_21 -> V_47 ) - F_37 ( V_21 -> V_47 - ( V_75 + V_63 ) ) ;
if ( V_75 + V_63 == V_21 -> V_47 ) {
V_4 = 0 ;
} else {
V_4 = V_76 - ( pow << V_80 ) ;
if ( V_4 & ~ V_76 )
return - V_66 ;
}
V_84 = ( V_83 & ~ V_76 ) | V_4 ;
if ( ( V_84 & V_76 ) >= ( V_83 & V_76 ) )
return - V_66 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_84 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_4 V_75 , T_5 V_63 )
{
int V_26 ;
V_26 = F_1 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_33 ( V_2 , V_75 , V_63 , V_26 ) ;
}
static int F_39 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_85 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_86 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_87 ) ;
return V_3 ;
}
static int F_40 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_87 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_88 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_85 ) ;
return V_3 ;
}
static int F_41 ( struct V_20 * V_21 , T_4 V_75 , T_5 V_63 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_87 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_89 ( V_2 , V_75 , V_63 ) ;
F_25 ( V_2 , V_85 ) ;
return V_3 ;
}
static const struct V_23 * F_42 ( struct V_1 * V_2 )
{
int V_90 ;
T_1 V_91 [ V_92 ] ;
const struct V_23 * V_24 ;
V_90 = V_2 -> V_5 ( V_2 , V_93 , V_91 , V_92 ) ;
if ( V_90 < 0 ) {
F_21 ( V_2 -> V_9 , L_8 , V_90 ) ;
return F_43 ( V_90 ) ;
}
for ( V_90 = 0 ; V_90 < F_44 ( V_94 ) - 1 ; V_90 ++ ) {
V_24 = & V_94 [ V_90 ] ;
if ( V_24 -> V_95 ) {
if ( ! memcmp ( V_24 -> V_91 , V_91 , V_24 -> V_95 ) )
return & V_94 [ V_90 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_91 [ 0 ] , V_91 [ 1 ] , V_91 [ 2 ] ) ;
return F_43 ( - V_96 ) ;
}
static int F_45 ( struct V_20 * V_21 , T_4 V_97 , T_6 V_63 ,
T_6 * V_98 , T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_10 , ( T_2 ) V_97 , V_63 ) ;
V_3 = F_22 ( V_2 , V_99 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_100 ( V_2 , V_97 , V_63 , V_98 , V_55 ) ;
F_25 ( V_2 , V_99 ) ;
return V_3 ;
}
static int F_46 ( struct V_20 * V_21 , T_4 V_101 , T_6 V_63 ,
T_6 * V_98 , const T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_6 V_102 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_101 , V_63 ) ;
V_3 = F_22 ( V_2 , V_103 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_104 = false ;
V_102 = V_101 % 2 ;
if ( V_102 ) {
V_2 -> V_105 = V_106 ;
V_2 -> V_107 ( V_2 , V_101 , 1 , V_98 , V_55 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_108;
}
V_101 += V_102 ;
for (; V_102 < V_63 - 1 ; V_102 += 2 ) {
V_2 -> V_105 = V_109 ;
V_2 -> V_107 ( V_2 , V_101 , 2 , V_98 , V_55 + V_102 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_108;
V_101 += 2 ;
V_2 -> V_104 = true ;
}
V_2 -> V_104 = false ;
F_9 ( V_2 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_108;
if ( V_102 != V_63 ) {
F_8 ( V_2 ) ;
V_2 -> V_105 = V_106 ;
V_2 -> V_107 ( V_2 , V_101 , 1 , V_98 , V_55 + V_102 ) ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_108;
F_9 ( V_2 ) ;
}
V_108:
F_25 ( V_2 , V_103 ) ;
return V_3 ;
}
static int F_47 ( struct V_20 * V_21 , T_4 V_101 , T_6 V_63 ,
T_6 * V_98 , const T_7 * V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_110 , V_111 , V_57 ;
int V_3 ;
F_21 ( V_2 -> V_9 , L_11 , ( T_2 ) V_101 , V_63 ) ;
V_3 = F_22 ( V_2 , V_103 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_110 = V_101 & ( V_2 -> V_111 - 1 ) ;
if ( V_110 + V_63 <= V_2 -> V_111 ) {
V_2 -> V_107 ( V_2 , V_101 , V_63 , V_98 , V_55 ) ;
} else {
V_111 = V_2 -> V_111 - V_110 ;
V_2 -> V_107 ( V_2 , V_101 , V_111 , V_98 , V_55 ) ;
for ( V_57 = V_111 ; V_57 < V_63 ; V_57 += V_111 ) {
V_111 = V_63 - V_57 ;
if ( V_111 > V_2 -> V_111 )
V_111 = V_2 -> V_111 ;
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
goto V_112;
F_8 ( V_2 ) ;
V_2 -> V_107 ( V_2 , V_101 + V_57 , V_111 , V_98 , V_55 + V_57 ) ;
}
}
V_3 = F_19 ( V_2 ) ;
V_112:
F_25 ( V_2 , V_103 ) ;
return V_3 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_4 | V_113 ) ;
if ( F_19 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_113 ) ) ) {
F_5 ( V_2 -> V_9 , L_12 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_8 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_3 ;
int V_114 = V_115 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_49 ( V_2 , V_114 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_13 ) ;
return - V_66 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_115 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_116 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 & ~ V_117 ;
V_3 = V_2 -> V_16 ( V_2 , V_118 , V_2 -> V_15 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return V_3 ;
}
V_3 = F_19 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_116 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
if ( V_4 & V_117 ) {
F_5 ( V_2 -> V_9 , L_17 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
int V_26 ;
switch ( F_12 ( V_24 ) ) {
case V_30 :
V_26 = F_48 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_18 ) ;
return - V_66 ;
}
return V_26 ;
case V_29 :
V_26 = F_51 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_66 ;
}
return V_26 ;
default:
V_26 = F_50 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_20 ) ;
return - V_66 ;
}
return V_26 ;
}
}
static int F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_100 || ! V_2 -> V_107 ||
! V_2 -> V_5 || ! V_2 -> V_16 ) {
F_2 ( L_21 ) ;
return - V_66 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 , const char * V_119 , enum V_120 V_121 )
{
const struct V_23 * V_24 = NULL ;
struct V_122 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_123 * V_124 = F_55 ( V_2 ) ;
int V_3 ;
int V_57 ;
V_3 = F_53 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_119 )
V_24 = F_56 ( V_119 ) ;
if ( ! V_24 )
V_24 = F_42 ( V_2 ) ;
if ( F_57 ( V_24 ) )
return - V_125 ;
if ( V_119 && V_24 -> V_95 ) {
const struct V_23 * V_126 ;
V_126 = F_42 ( V_2 ) ;
if ( F_58 ( V_126 ) ) {
return F_59 ( V_126 ) ;
} else if ( V_126 != V_24 ) {
F_60 ( V_9 , L_22 ,
V_126 -> V_119 , V_24 -> V_119 ) ;
V_24 = V_126 ;
}
}
F_61 ( & V_2 -> V_51 ) ;
if ( F_12 ( V_24 ) == V_127 ||
F_12 ( V_24 ) == V_128 ||
F_12 ( V_24 ) == V_129 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( ! V_21 -> V_119 )
V_21 -> V_119 = F_62 ( V_9 ) ;
V_21 -> V_22 = V_2 ;
V_21 -> type = V_130 ;
V_21 -> V_131 = 1 ;
V_21 -> V_39 = V_132 ;
V_21 -> V_47 = V_24 -> V_133 * V_24 -> V_134 ;
V_21 -> V_135 = F_27 ;
V_21 -> V_136 = F_45 ;
if ( F_12 ( V_24 ) == V_29 ) {
V_2 -> V_86 = F_34 ;
V_2 -> V_88 = F_36 ;
V_2 -> V_89 = F_38 ;
}
if ( V_2 -> V_86 && V_2 -> V_88 && V_2 -> V_89 ) {
V_21 -> V_137 = F_39 ;
V_21 -> V_138 = F_40 ;
V_21 -> V_139 = F_41 ;
}
if ( V_24 -> V_39 & V_140 )
V_21 -> V_141 = F_46 ;
else
V_21 -> V_141 = F_47 ;
if ( V_24 -> V_39 & V_142 )
V_2 -> V_39 |= V_40 ;
#ifdef F_63
if ( V_24 -> V_39 & V_143 ) {
V_2 -> V_60 = V_144 ;
V_21 -> V_65 = 4096 ;
} else if ( V_24 -> V_39 & V_145 ) {
V_2 -> V_60 = V_146 ;
V_21 -> V_65 = 4096 ;
} else
#endif
{
V_2 -> V_60 = V_147 ;
V_21 -> V_65 = V_24 -> V_133 ;
}
if ( V_24 -> V_39 & V_148 )
V_21 -> V_39 |= V_149 ;
V_21 -> V_9 . V_150 = V_9 ;
V_2 -> V_111 = V_24 -> V_111 ;
V_21 -> V_151 = V_2 -> V_111 ;
if ( V_124 ) {
if ( F_64 ( V_124 , L_23 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_39 & V_152 )
V_2 -> V_10 = V_14 ;
if ( V_121 == V_13 && V_24 -> V_39 & V_153 ) {
V_3 = F_52 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_24 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_121 == V_12 && V_24 -> V_39 & V_154 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_155 = V_156 ;
break;
case V_12 :
V_2 -> V_155 = V_157 ;
break;
case V_11 :
V_2 -> V_155 = V_158 ;
break;
case V_14 :
V_2 -> V_155 = V_159 ;
break;
default:
F_5 ( V_9 , L_25 ) ;
return - V_66 ;
}
V_2 -> V_105 = V_160 ;
if ( V_24 -> V_59 )
V_2 -> V_59 = V_24 -> V_59 ;
else if ( V_21 -> V_47 > 0x1000000 ) {
V_2 -> V_59 = 4 ;
if ( F_12 ( V_24 ) == V_161 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_155 = V_162 ;
break;
case V_12 :
V_2 -> V_155 = V_163 ;
break;
case V_11 :
V_2 -> V_155 = V_164 ;
break;
case V_14 :
V_2 -> V_155 = V_165 ;
break;
}
V_2 -> V_105 = V_166 ;
V_2 -> V_60 = V_167 ;
V_21 -> V_65 = V_24 -> V_133 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_59 = 3 ;
}
if ( V_2 -> V_59 > V_56 ) {
F_5 ( V_9 , L_26 ,
V_2 -> V_59 ) ;
return - V_66 ;
}
V_2 -> V_168 = F_6 ( V_2 ) ;
F_65 ( V_9 , L_27 , V_24 -> V_119 ,
( long long ) V_21 -> V_47 >> 10 ) ;
F_21 ( V_9 ,
L_28
L_29 ,
V_21 -> V_119 , ( long long ) V_21 -> V_47 , ( long long ) ( V_21 -> V_47 >> 20 ) ,
V_21 -> V_65 , V_21 -> V_65 / 1024 , V_21 -> V_169 ) ;
if ( V_21 -> V_169 )
for ( V_57 = 0 ; V_57 < V_21 -> V_169 ; V_57 ++ )
F_21 ( V_9 ,
L_30
L_31
L_32 ,
V_57 , ( long long ) V_21 -> V_170 [ V_57 ] . V_171 ,
V_21 -> V_170 [ V_57 ] . V_65 ,
V_21 -> V_170 [ V_57 ] . V_65 / 1024 ,
V_21 -> V_170 [ V_57 ] . V_172 ) ;
return 0 ;
}
static const struct V_23 * F_56 ( const char * V_119 )
{
const struct V_23 * V_91 = V_94 ;
while ( V_91 -> V_119 ) {
if ( ! strcmp ( V_119 , V_91 -> V_119 ) )
return V_91 ;
V_91 ++ ;
}
return NULL ;
}
