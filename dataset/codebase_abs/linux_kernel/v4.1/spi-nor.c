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
static inline int F_11 ( struct V_1 * V_2 , struct V_23 * V_24 ,
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
static const struct V_77 * F_32 ( struct V_1 * V_2 )
{
int V_78 ;
T_1 V_79 [ V_80 ] ;
struct V_23 * V_24 ;
V_78 = V_2 -> V_5 ( V_2 , V_81 , V_79 , V_80 ) ;
if ( V_78 < 0 ) {
F_20 ( V_2 -> V_9 , L_8 , V_78 ) ;
return F_33 ( V_78 ) ;
}
for ( V_78 = 0 ; V_78 < F_34 ( V_82 ) - 1 ; V_78 ++ ) {
V_24 = ( void * ) V_82 [ V_78 ] . V_83 ;
if ( V_24 -> V_84 ) {
if ( ! memcmp ( V_24 -> V_79 , V_79 , V_24 -> V_84 ) )
return & V_82 [ V_78 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_79 [ 0 ] , V_79 [ 1 ] , V_79 [ 2 ] ) ;
return F_33 ( - V_85 ) ;
}
static int F_35 ( struct V_20 * V_21 , T_4 V_86 , T_7 V_55 ,
T_7 * V_87 , T_8 * V_88 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_10 , ( T_2 ) V_86 , V_55 ) ;
V_3 = F_21 ( V_2 , V_89 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_90 ( V_2 , V_86 , V_55 , V_87 , V_88 ) ;
F_24 ( V_2 , V_89 ) ;
return V_3 ;
}
static int F_36 ( struct V_20 * V_21 , T_4 V_91 , T_7 V_55 ,
T_7 * V_87 , const T_8 * V_88 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_7 V_92 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_91 , V_55 ) ;
V_3 = F_21 ( V_2 , V_93 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_94 = false ;
V_92 = V_91 % 2 ;
if ( V_92 ) {
V_2 -> V_95 = V_96 ;
V_2 -> V_97 ( V_2 , V_91 , 1 , V_87 , V_88 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_98;
}
V_91 += V_92 ;
for (; V_92 < V_55 - 1 ; V_92 += 2 ) {
V_2 -> V_95 = V_99 ;
V_2 -> V_97 ( V_2 , V_91 , 2 , V_87 , V_88 + V_92 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_98;
V_91 += 2 ;
V_2 -> V_94 = true ;
}
V_2 -> V_94 = false ;
F_9 ( V_2 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_98;
if ( V_92 != V_55 ) {
F_8 ( V_2 ) ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 ( V_2 , V_91 , 1 , V_87 , V_88 + V_92 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_98;
F_9 ( V_2 ) ;
}
V_98:
F_24 ( V_2 , V_93 ) ;
return V_3 ;
}
static int F_37 ( struct V_20 * V_21 , T_4 V_91 , T_7 V_55 ,
T_7 * V_87 , const T_8 * V_88 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_100 , V_101 , V_102 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_91 , V_55 ) ;
V_3 = F_21 ( V_2 , V_93 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_100 = V_91 & ( V_2 -> V_101 - 1 ) ;
if ( V_100 + V_55 <= V_2 -> V_101 ) {
V_2 -> V_97 ( V_2 , V_91 , V_55 , V_87 , V_88 ) ;
} else {
V_101 = V_2 -> V_101 - V_100 ;
V_2 -> V_97 ( V_2 , V_91 , V_101 , V_87 , V_88 ) ;
for ( V_102 = V_101 ; V_102 < V_55 ; V_102 += V_101 ) {
V_101 = V_55 - V_102 ;
if ( V_101 > V_2 -> V_101 )
V_101 = V_2 -> V_101 ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_103;
F_8 ( V_2 ) ;
V_2 -> V_97 ( V_2 , V_91 + V_102 , V_101 , V_87 , V_88 + V_102 ) ;
}
}
V_3 = F_16 ( V_2 ) ;
V_103:
F_24 ( V_2 , V_93 ) ;
return V_3 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 | V_104 ;
V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
if ( F_16 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_104 ) ) ) {
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
int V_105 = V_106 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_39 ( V_2 , V_105 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_13 ) ;
return - V_58 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_106 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_107 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 & ~ V_108 ;
V_3 = V_2 -> V_16 ( V_2 , V_109 , V_2 -> V_15 , 1 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_107 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
if ( V_4 & V_108 ) {
F_5 ( V_2 -> V_9 , L_17 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_23 * V_24 )
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
if ( ! V_2 -> V_9 || ! V_2 -> V_90 || ! V_2 -> V_97 ||
! V_2 -> V_5 || ! V_2 -> V_16 || ! V_2 -> V_62 ) {
F_2 ( L_21 ) ;
return - V_58 ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 , const char * V_110 , enum V_111 V_112 )
{
const struct V_77 * V_79 = NULL ;
struct V_23 * V_24 ;
struct V_113 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_114 * V_115 = V_9 -> V_116 ;
int V_3 ;
int V_102 ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( ! V_110 )
V_79 = F_32 ( V_2 ) ;
else
V_79 = F_45 ( V_110 ) ;
if ( F_46 ( V_79 ) )
return - V_117 ;
V_24 = ( void * ) V_79 -> V_83 ;
if ( V_110 && V_24 -> V_84 ) {
const struct V_77 * V_118 ;
V_118 = F_32 ( V_2 ) ;
if ( F_47 ( V_118 ) ) {
return F_48 ( V_118 ) ;
} else if ( V_118 != V_79 ) {
F_49 ( V_9 , L_22 ,
V_118 -> V_110 , V_79 -> V_110 ) ;
V_79 = V_118 ;
V_24 = ( void * ) V_118 -> V_83 ;
}
}
F_50 ( & V_2 -> V_49 ) ;
if ( F_12 ( V_24 ) == V_119 ||
F_12 ( V_24 ) == V_120 ||
F_12 ( V_24 ) == V_121 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( ! V_21 -> V_110 )
V_21 -> V_110 = F_51 ( V_9 ) ;
V_21 -> type = V_122 ;
V_21 -> V_123 = 1 ;
V_21 -> V_38 = V_124 ;
V_21 -> V_45 = V_24 -> V_125 * V_24 -> V_126 ;
V_21 -> V_127 = F_25 ;
V_21 -> V_128 = F_35 ;
if ( F_12 ( V_24 ) == V_29 ) {
V_2 -> V_74 = F_28 ;
V_2 -> V_76 = F_29 ;
}
if ( V_2 -> V_74 && V_2 -> V_76 ) {
V_21 -> V_129 = F_30 ;
V_21 -> V_130 = F_31 ;
}
if ( V_24 -> V_38 & V_131 )
V_21 -> V_132 = F_36 ;
else
V_21 -> V_132 = F_37 ;
if ( V_24 -> V_38 & V_133 )
V_2 -> V_38 |= V_39 ;
#ifdef F_52
if ( V_24 -> V_38 & V_134 ) {
V_2 -> V_135 = V_136 ;
V_21 -> V_57 = 4096 ;
} else if ( V_24 -> V_38 & V_137 ) {
V_2 -> V_135 = V_138 ;
V_21 -> V_57 = 4096 ;
} else
#endif
{
V_2 -> V_135 = V_139 ;
V_21 -> V_57 = V_24 -> V_125 ;
}
if ( V_24 -> V_38 & V_140 )
V_21 -> V_38 |= V_141 ;
V_21 -> V_9 . V_142 = V_9 ;
V_2 -> V_101 = V_24 -> V_101 ;
V_21 -> V_143 = V_2 -> V_101 ;
if ( V_115 ) {
if ( F_53 ( V_115 , L_23 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_38 & V_144 )
V_2 -> V_10 = V_14 ;
if ( V_112 == V_13 && V_24 -> V_38 & V_145 ) {
V_3 = F_42 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_24 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_112 == V_12 && V_24 -> V_38 & V_146 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_147 = V_148 ;
break;
case V_12 :
V_2 -> V_147 = V_149 ;
break;
case V_11 :
V_2 -> V_147 = V_150 ;
break;
case V_14 :
V_2 -> V_147 = V_151 ;
break;
default:
F_5 ( V_9 , L_25 ) ;
return - V_58 ;
}
V_2 -> V_95 = V_152 ;
if ( V_24 -> V_153 )
V_2 -> V_153 = V_24 -> V_153 ;
else if ( V_21 -> V_45 > 0x1000000 ) {
V_2 -> V_153 = 4 ;
if ( F_12 ( V_24 ) == V_154 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_147 = V_155 ;
break;
case V_12 :
V_2 -> V_147 = V_156 ;
break;
case V_11 :
V_2 -> V_147 = V_157 ;
break;
case V_14 :
V_2 -> V_147 = V_158 ;
break;
}
V_2 -> V_95 = V_159 ;
V_2 -> V_135 = V_160 ;
V_21 -> V_57 = V_24 -> V_125 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_153 = 3 ;
}
V_2 -> V_161 = F_6 ( V_2 ) ;
F_54 ( V_9 , L_26 , V_79 -> V_110 ,
( long long ) V_21 -> V_45 >> 10 ) ;
F_20 ( V_9 ,
L_27
L_28 ,
V_21 -> V_110 , ( long long ) V_21 -> V_45 , ( long long ) ( V_21 -> V_45 >> 20 ) ,
V_21 -> V_57 , V_21 -> V_57 / 1024 , V_21 -> V_162 ) ;
if ( V_21 -> V_162 )
for ( V_102 = 0 ; V_102 < V_21 -> V_162 ; V_102 ++ )
F_20 ( V_9 ,
L_29
L_30
L_31 ,
V_102 , ( long long ) V_21 -> V_163 [ V_102 ] . V_67 ,
V_21 -> V_163 [ V_102 ] . V_57 ,
V_21 -> V_163 [ V_102 ] . V_57 / 1024 ,
V_21 -> V_163 [ V_102 ] . V_164 ) ;
return 0 ;
}
static const struct V_77 * F_45 ( const char * V_110 )
{
const struct V_77 * V_79 = V_82 ;
while ( V_79 -> V_110 [ 0 ] ) {
if ( ! strcmp ( V_110 , V_79 -> V_110 ) )
return V_79 ;
V_79 ++ ;
}
return NULL ;
}
