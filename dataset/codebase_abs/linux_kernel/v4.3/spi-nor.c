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
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_18 , NULL , 0 , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_19 , NULL , 0 , 0 ) ;
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
case 0xEF :
if ( V_27 )
F_8 ( V_2 ) ;
V_28 = V_25 ? V_31 : V_32 ;
V_26 = V_2 -> V_16 ( V_2 , V_28 , NULL , 0 , 0 ) ;
if ( V_27 )
F_9 ( V_2 ) ;
return V_26 ;
default:
V_2 -> V_15 [ 0 ] = V_25 << 7 ;
return V_2 -> V_16 ( V_2 , V_33 , V_2 -> V_15 , 1 , 0 ) ;
}
}
static inline int F_13 ( struct V_1 * V_2 )
{
int V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
else
return ! ( V_34 & V_35 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
int V_36 = F_3 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
else
return V_36 & V_37 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_34 , V_36 ;
V_34 = F_13 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_36 = V_2 -> V_38 & V_39 ? F_14 ( V_2 ) : 1 ;
if ( V_36 < 0 )
return V_36 ;
return V_34 && V_36 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
int V_41 = 0 , V_3 ;
V_40 = V_42 + V_43 ;
while ( ! V_41 ) {
if ( F_17 ( V_42 , V_40 ) )
V_41 = 1 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_18 () ;
}
F_5 ( V_2 -> V_9 , L_4 ) ;
return - V_44 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_9 , L_5 , ( long long ) ( V_2 -> V_21 -> V_45 >> 10 ) ) ;
return V_2 -> V_16 ( V_2 , V_46 , NULL , 0 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , enum V_47 V_48 )
{
int V_3 = 0 ;
F_22 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_50 ) {
V_3 = V_2 -> V_50 ( V_2 , V_48 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_6 ) ;
F_23 ( & V_2 -> V_49 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_24 ( struct V_1 * V_2 , enum V_47 V_48 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 ( V_2 , V_48 ) ;
F_23 ( & V_2 -> V_49 ) ;
}
static int F_25 ( struct V_20 * V_21 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_54 , V_55 ;
T_3 V_56 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_7 , ( long long ) V_53 -> V_54 ,
( long long ) V_53 -> V_55 ) ;
F_26 ( V_53 -> V_55 , V_21 -> V_57 , & V_56 ) ;
if ( V_56 )
return - V_58 ;
V_54 = V_53 -> V_54 ;
V_55 = V_53 -> V_55 ;
V_3 = F_21 ( V_2 , V_59 ) ;
if ( V_3 )
return V_3 ;
if ( V_55 == V_21 -> V_45 ) {
F_8 ( V_2 ) ;
if ( F_19 ( V_2 ) ) {
V_3 = - V_60 ;
goto V_61;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_61;
} else {
while ( V_55 ) {
F_8 ( V_2 ) ;
if ( V_2 -> V_62 ( V_2 , V_54 ) ) {
V_3 = - V_60 ;
goto V_61;
}
V_54 += V_21 -> V_57 ;
V_55 -= V_21 -> V_57 ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_61;
}
}
F_9 ( V_2 ) ;
F_24 ( V_2 , V_59 ) ;
V_53 -> V_63 = V_64 ;
F_27 ( V_53 ) ;
return V_3 ;
V_61:
F_24 ( V_2 , V_59 ) ;
V_53 -> V_63 = V_65 ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 , T_4 V_66 , T_5 V_55 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
T_3 V_67 = V_66 ;
T_6 V_68 , V_69 ;
int V_3 = 0 ;
V_68 = F_1 ( V_2 ) ;
if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 2 ) )
V_69 = V_68 | V_70 | V_71 | V_72 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 4 ) )
V_69 = ( V_68 & ~ V_72 ) | V_70 | V_71 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 8 ) )
V_69 = ( V_68 & ~ V_71 ) | V_70 | V_72 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 16 ) )
V_69 = ( V_68 & ~ ( V_72 | V_71 ) ) | V_70 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 32 ) )
V_69 = ( V_68 & ~ V_70 ) | V_71 | V_72 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 64 ) )
V_69 = ( V_68 & ~ ( V_70 | V_72 ) ) | V_71 ;
else
V_69 = ( V_68 & ~ ( V_70 | V_71 ) ) | V_72 ;
if ( ( V_69 & ( V_70 | V_71 | V_72 ) ) >
( V_68 & ( V_70 | V_71 | V_72 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_69 ) ;
}
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 , T_4 V_66 , T_5 V_55 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
T_3 V_67 = V_66 ;
T_6 V_68 , V_69 ;
int V_3 = 0 ;
V_68 = F_1 ( V_2 ) ;
if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 64 ) )
V_69 = V_68 & ~ ( V_70 | V_71 | V_72 ) ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 32 ) )
V_69 = ( V_68 & ~ ( V_70 | V_71 ) ) | V_72 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 16 ) )
V_69 = ( V_68 & ~ ( V_70 | V_72 ) ) | V_71 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 8 ) )
V_69 = ( V_68 & ~ V_70 ) | V_71 | V_72 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 4 ) )
V_69 = ( V_68 & ~ ( V_72 | V_71 ) ) | V_70 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 2 ) )
V_69 = ( V_68 & ~ V_71 ) | V_70 | V_72 ;
else
V_69 = ( V_68 & ~ V_72 ) | V_70 | V_71 ;
if ( ( V_69 & ( V_70 | V_71 | V_72 ) ) <
( V_68 & ( V_70 | V_71 | V_72 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_69 ) ;
}
return V_3 ;
}
static int F_30 ( struct V_20 * V_21 , T_4 V_66 , T_5 V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_21 ( V_2 , V_73 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_74 ( V_2 , V_66 , V_55 ) ;
F_24 ( V_2 , V_75 ) ;
return V_3 ;
}
static int F_31 ( struct V_20 * V_21 , T_4 V_66 , T_5 V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_21 ( V_2 , V_75 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_76 ( V_2 , V_66 , V_55 ) ;
F_24 ( V_2 , V_73 ) ;
return V_3 ;
}
static const struct V_23 * F_32 ( struct V_1 * V_2 )
{
int V_77 ;
T_1 V_78 [ V_79 ] ;
const struct V_23 * V_24 ;
V_77 = V_2 -> V_5 ( V_2 , V_80 , V_78 , V_79 ) ;
if ( V_77 < 0 ) {
F_20 ( V_2 -> V_9 , L_8 , V_77 ) ;
return F_33 ( V_77 ) ;
}
for ( V_77 = 0 ; V_77 < F_34 ( V_81 ) - 1 ; V_77 ++ ) {
V_24 = & V_81 [ V_77 ] ;
if ( V_24 -> V_82 ) {
if ( ! memcmp ( V_24 -> V_78 , V_78 , V_24 -> V_82 ) )
return & V_81 [ V_77 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] ) ;
return F_33 ( - V_83 ) ;
}
static int F_35 ( struct V_20 * V_21 , T_4 V_84 , T_7 V_55 ,
T_7 * V_85 , T_8 * V_86 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_10 , ( T_2 ) V_84 , V_55 ) ;
V_3 = F_21 ( V_2 , V_87 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_88 ( V_2 , V_84 , V_55 , V_85 , V_86 ) ;
F_24 ( V_2 , V_87 ) ;
return V_3 ;
}
static int F_36 ( struct V_20 * V_21 , T_4 V_89 , T_7 V_55 ,
T_7 * V_85 , const T_8 * V_86 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_7 V_90 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_89 , V_55 ) ;
V_3 = F_21 ( V_2 , V_91 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_92 = false ;
V_90 = V_89 % 2 ;
if ( V_90 ) {
V_2 -> V_93 = V_94 ;
V_2 -> V_95 ( V_2 , V_89 , 1 , V_85 , V_86 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_96;
}
V_89 += V_90 ;
for (; V_90 < V_55 - 1 ; V_90 += 2 ) {
V_2 -> V_93 = V_97 ;
V_2 -> V_95 ( V_2 , V_89 , 2 , V_85 , V_86 + V_90 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_96;
V_89 += 2 ;
V_2 -> V_92 = true ;
}
V_2 -> V_92 = false ;
F_9 ( V_2 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_96;
if ( V_90 != V_55 ) {
F_8 ( V_2 ) ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 ( V_2 , V_89 , 1 , V_85 , V_86 + V_90 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_96;
F_9 ( V_2 ) ;
}
V_96:
F_24 ( V_2 , V_91 ) ;
return V_3 ;
}
static int F_37 ( struct V_20 * V_21 , T_4 V_89 , T_7 V_55 ,
T_7 * V_85 , const T_8 * V_86 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_98 , V_99 , V_100 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_89 , V_55 ) ;
V_3 = F_21 ( V_2 , V_91 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_98 = V_89 & ( V_2 -> V_99 - 1 ) ;
if ( V_98 + V_55 <= V_2 -> V_99 ) {
V_2 -> V_95 ( V_2 , V_89 , V_55 , V_85 , V_86 ) ;
} else {
V_99 = V_2 -> V_99 - V_98 ;
V_2 -> V_95 ( V_2 , V_89 , V_99 , V_85 , V_86 ) ;
for ( V_100 = V_99 ; V_100 < V_55 ; V_100 += V_99 ) {
V_99 = V_55 - V_100 ;
if ( V_99 > V_2 -> V_99 )
V_99 = V_2 -> V_99 ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_101;
F_8 ( V_2 ) ;
V_2 -> V_95 ( V_2 , V_89 + V_100 , V_99 , V_85 , V_86 + V_100 ) ;
}
}
V_3 = F_16 ( V_2 ) ;
V_101:
F_24 ( V_2 , V_91 ) ;
return V_3 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 | V_102 ;
V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
if ( F_16 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_102 ) ) ) {
F_5 ( V_2 -> V_9 , L_12 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_9 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 , 0 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_3 ;
int V_103 = V_104 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_39 ( V_2 , V_103 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_13 ) ;
return - V_58 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_104 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_105 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 & ~ V_106 ;
V_3 = V_2 -> V_16 ( V_2 , V_107 , V_2 -> V_15 , 1 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_105 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
if ( V_4 & V_106 ) {
F_5 ( V_2 -> V_9 , L_17 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
int V_26 ;
switch ( F_12 ( V_24 ) ) {
case V_30 :
V_26 = F_38 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_18 ) ;
return - V_58 ;
}
return V_26 ;
case V_29 :
V_26 = F_41 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_58 ;
}
return V_26 ;
default:
V_26 = F_40 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_20 ) ;
return - V_58 ;
}
return V_26 ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_88 || ! V_2 -> V_95 ||
! V_2 -> V_5 || ! V_2 -> V_16 || ! V_2 -> V_62 ) {
F_2 ( L_21 ) ;
return - V_58 ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 , const char * V_108 , enum V_109 V_110 )
{
const struct V_23 * V_24 = NULL ;
struct V_111 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_112 * V_113 = V_9 -> V_114 ;
int V_3 ;
int V_100 ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_108 )
V_24 = F_45 ( V_108 ) ;
if ( ! V_24 )
V_24 = F_32 ( V_2 ) ;
if ( F_46 ( V_24 ) )
return - V_115 ;
if ( V_108 && V_24 -> V_82 ) {
const struct V_23 * V_116 ;
V_116 = F_32 ( V_2 ) ;
if ( F_47 ( V_116 ) ) {
return F_48 ( V_116 ) ;
} else if ( V_116 != V_24 ) {
F_49 ( V_9 , L_22 ,
V_116 -> V_108 , V_24 -> V_108 ) ;
V_24 = V_116 ;
}
}
F_50 ( & V_2 -> V_49 ) ;
if ( F_12 ( V_24 ) == V_117 ||
F_12 ( V_24 ) == V_118 ||
F_12 ( V_24 ) == V_119 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( ! V_21 -> V_108 )
V_21 -> V_108 = F_51 ( V_9 ) ;
V_21 -> type = V_120 ;
V_21 -> V_121 = 1 ;
V_21 -> V_38 = V_122 ;
V_21 -> V_45 = V_24 -> V_123 * V_24 -> V_124 ;
V_21 -> V_125 = F_25 ;
V_21 -> V_126 = F_35 ;
if ( F_12 ( V_24 ) == V_29 ) {
V_2 -> V_74 = F_28 ;
V_2 -> V_76 = F_29 ;
}
if ( V_2 -> V_74 && V_2 -> V_76 ) {
V_21 -> V_127 = F_30 ;
V_21 -> V_128 = F_31 ;
}
if ( V_24 -> V_38 & V_129 )
V_21 -> V_130 = F_36 ;
else
V_21 -> V_130 = F_37 ;
if ( V_24 -> V_38 & V_131 )
V_2 -> V_38 |= V_39 ;
#ifdef F_52
if ( V_24 -> V_38 & V_132 ) {
V_2 -> V_133 = V_134 ;
V_21 -> V_57 = 4096 ;
} else if ( V_24 -> V_38 & V_135 ) {
V_2 -> V_133 = V_136 ;
V_21 -> V_57 = 4096 ;
} else
#endif
{
V_2 -> V_133 = V_137 ;
V_21 -> V_57 = V_24 -> V_123 ;
}
if ( V_24 -> V_38 & V_138 )
V_21 -> V_38 |= V_139 ;
V_21 -> V_9 . V_140 = V_9 ;
V_2 -> V_99 = V_24 -> V_99 ;
V_21 -> V_141 = V_2 -> V_99 ;
if ( V_113 ) {
if ( F_53 ( V_113 , L_23 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_38 & V_142 )
V_2 -> V_10 = V_14 ;
if ( V_110 == V_13 && V_24 -> V_38 & V_143 ) {
V_3 = F_42 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_24 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_110 == V_12 && V_24 -> V_38 & V_144 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_145 = V_146 ;
break;
case V_12 :
V_2 -> V_145 = V_147 ;
break;
case V_11 :
V_2 -> V_145 = V_148 ;
break;
case V_14 :
V_2 -> V_145 = V_149 ;
break;
default:
F_5 ( V_9 , L_25 ) ;
return - V_58 ;
}
V_2 -> V_93 = V_150 ;
if ( V_24 -> V_151 )
V_2 -> V_151 = V_24 -> V_151 ;
else if ( V_21 -> V_45 > 0x1000000 ) {
V_2 -> V_151 = 4 ;
if ( F_12 ( V_24 ) == V_152 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_145 = V_153 ;
break;
case V_12 :
V_2 -> V_145 = V_154 ;
break;
case V_11 :
V_2 -> V_145 = V_155 ;
break;
case V_14 :
V_2 -> V_145 = V_156 ;
break;
}
V_2 -> V_93 = V_157 ;
V_2 -> V_133 = V_158 ;
V_21 -> V_57 = V_24 -> V_123 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_151 = 3 ;
}
V_2 -> V_159 = F_6 ( V_2 ) ;
F_54 ( V_9 , L_26 , V_24 -> V_108 ,
( long long ) V_21 -> V_45 >> 10 ) ;
F_20 ( V_9 ,
L_27
L_28 ,
V_21 -> V_108 , ( long long ) V_21 -> V_45 , ( long long ) ( V_21 -> V_45 >> 20 ) ,
V_21 -> V_57 , V_21 -> V_57 / 1024 , V_21 -> V_160 ) ;
if ( V_21 -> V_160 )
for ( V_100 = 0 ; V_100 < V_21 -> V_160 ; V_100 ++ )
F_20 ( V_9 ,
L_29
L_30
L_31 ,
V_100 , ( long long ) V_21 -> V_161 [ V_100 ] . V_67 ,
V_21 -> V_161 [ V_100 ] . V_57 ,
V_21 -> V_161 [ V_100 ] . V_57 / 1024 ,
V_21 -> V_161 [ V_100 ] . V_162 ) ;
return 0 ;
}
static const struct V_23 * F_45 ( const char * V_108 )
{
const struct V_23 * V_78 = V_81 ;
while ( V_78 -> V_108 ) {
if ( ! strcmp ( V_108 , V_78 -> V_108 ) )
return V_78 ;
V_78 ++ ;
}
return NULL ;
}
