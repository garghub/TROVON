static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( strcmp ( V_3 -> V_8 [ V_6 ] . V_4 , V_4 ) )
continue;
V_5 = & V_3 -> V_8 [ V_6 ] ;
F_2 ( V_3 -> V_9 , L_1 , V_4 , V_5 -> V_10 , V_5 -> V_11 [ 0 ] ) ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_7 ;
}
static const char * F_5 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_8 [ V_14 ] . V_4 ;
}
static int F_6 ( struct V_12 * V_13 , unsigned V_14 ,
const unsigned * * V_11 ,
unsigned * V_10 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
if ( V_14 >= V_3 -> V_7 )
return - V_15 ;
* V_11 = V_3 -> V_8 [ V_14 ] . V_11 ;
* V_10 = V_3 -> V_8 [ V_14 ] . V_10 ;
return 0 ;
}
static void F_7 ( struct V_12 * V_13 , struct V_16 * V_17 ,
unsigned V_18 )
{
F_8 ( V_17 , L_2 , F_9 ( V_13 -> V_9 ) ) ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_19 * V_20 ,
struct V_21 * * V_22 , unsigned * V_23 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_1 * V_5 ;
struct V_21 * V_24 ;
struct V_19 * V_25 ;
int V_26 = 1 ;
int V_6 ;
V_5 = F_1 ( V_3 , V_20 -> V_4 ) ;
if ( ! V_5 ) {
F_11 ( V_3 -> V_9 , L_3 ,
V_20 -> V_4 ) ;
return - V_15 ;
}
V_26 += V_5 -> V_10 ;
V_24 = F_12 ( V_13 -> V_9 , sizeof( * V_24 ) * V_26 , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
* V_22 = V_24 ;
* V_23 = V_26 ;
V_25 = F_13 ( V_20 ) ;
if ( ! V_25 ) {
F_14 ( V_13 -> V_9 , V_24 ) ;
return - V_15 ;
}
V_24 [ 0 ] . type = V_29 ;
V_24 [ 0 ] . V_30 . V_31 . V_32 = V_25 -> V_4 ;
V_24 [ 0 ] . V_30 . V_31 . V_33 = V_20 -> V_4 ;
F_15 ( V_25 ) ;
V_24 ++ ;
for ( V_6 = 0 ; V_6 < V_5 -> V_10 ; V_6 ++ ) {
V_24 [ V_6 ] . type = V_34 ;
V_24 [ V_6 ] . V_30 . V_35 . V_36 =
F_16 ( V_13 , V_5 -> V_11 [ V_6 ] ) ;
V_24 [ V_6 ] . V_30 . V_35 . V_35 = & V_5 -> V_37 [ V_6 ] . V_38 ;
V_24 [ V_6 ] . V_30 . V_35 . V_39 = 1 ;
}
F_2 ( V_13 -> V_9 , L_4 ,
( * V_22 ) -> V_30 . V_31 . V_32 , ( * V_22 ) -> V_30 . V_31 . V_33 , V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 ,
struct V_21 * V_22 , unsigned V_23 )
{
}
static void T_1 * F_18 ( struct V_2 * V_3 ,
unsigned int V_40 )
{
return V_41 [ V_40 ] -> V_42 ;
}
static inline int F_19 ( unsigned V_43 )
{
return V_43 /= V_44 ;
}
static unsigned F_20 ( unsigned int V_43 )
{
return 1 << V_43 ;
}
static void F_21 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( V_46 , V_45 + V_47 ) ;
}
static unsigned F_23 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_24 ( V_45 + V_48 ) >> V_43 ) & 0x1 ;
}
static void F_25 ( void T_1 * V_45 , unsigned V_46 , bool V_49 )
{
F_22 ( V_46 , V_45 + ( V_49 ? V_50 : V_51 ) ) ;
}
static unsigned F_26 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_24 ( V_45 + V_52 ) >> V_43 ) & 0x1 ;
}
static void F_27 ( void T_1 * V_45 , unsigned V_46 , bool V_49 )
{
F_22 ( V_46 , V_45 + ( V_49 ? V_53 : V_54 ) ) ;
}
static void F_28 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( V_46 , V_45 + V_55 ) ;
}
static void F_29 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( V_46 , V_45 + V_56 ) ;
}
static void F_30 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( F_24 ( V_45 + V_57 ) & ~ V_46 ,
V_45 + V_57 ) ;
F_22 ( F_24 ( V_45 + V_58 ) & ~ V_46 ,
V_45 + V_58 ) ;
}
static void F_31 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( F_24 ( V_45 + V_57 ) | V_46 ,
V_45 + V_57 ) ;
F_22 ( F_24 ( V_45 + V_58 ) & ~ V_46 ,
V_45 + V_58 ) ;
}
static void F_32 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( F_24 ( V_45 + V_57 ) & ~ V_46 , V_45 + V_57 ) ;
F_22 ( F_24 ( V_45 + V_58 ) | V_46 , V_45 + V_58 ) ;
}
static void F_33 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( F_24 ( V_45 + V_57 ) | V_46 , V_45 + V_57 ) ;
F_22 ( F_24 ( V_45 + V_58 ) | V_46 , V_45 + V_58 ) ;
}
static enum V_59 F_34 ( void T_1 * V_45 , unsigned V_46 )
{
unsigned V_60 ;
if ( F_24 ( V_45 + V_61 ) & V_46 )
return V_62 ;
V_60 = ! ! ( F_24 ( V_45 + V_57 ) & V_46 ) ;
V_60 |= ( ! ! ( F_24 ( V_45 + V_58 ) & V_46 ) << 1 ) ;
return V_60 + 1 ;
}
static enum V_59 F_35 ( void T_1 * V_45 , unsigned V_46 )
{
unsigned V_60 ;
if ( F_24 ( V_45 + V_61 ) & V_46 )
return V_62 ;
V_60 = F_24 ( V_45 + V_63 ) & V_46 ;
return V_60 + 1 ;
}
static bool F_36 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_37 ( V_45 + V_64 ) >> V_43 ) & 0x1 ;
}
static void F_38 ( void T_1 * V_45 , unsigned V_46 , bool V_65 )
{
F_39 ( V_46 , V_45 + ( V_65 ? V_66 : V_67 ) ) ;
}
static void F_40 ( void T_1 * V_45 , unsigned V_46 , bool V_65 )
{
if ( V_65 )
F_39 ( V_46 , V_45 + V_68 ) ;
F_38 ( V_45 , V_46 , V_65 ) ;
}
static bool F_41 ( void T_1 * V_45 , unsigned V_43 , T_2 * div )
{
* div = F_37 ( V_45 + V_69 ) ;
return ( F_37 ( V_45 + V_70 ) >> V_43 ) & 0x1 ;
}
static void F_42 ( void T_1 * V_45 , unsigned V_46 ,
bool V_65 , T_2 div )
{
if ( V_65 ) {
F_39 ( V_46 , V_45 + V_71 ) ;
F_39 ( div & V_72 , V_45 + V_69 ) ;
F_39 ( V_46 , V_45 + V_66 ) ;
} else {
F_39 ( V_46 , V_45 + V_67 ) ;
}
}
static bool F_43 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_37 ( V_45 + V_73 ) >> V_43 ) & 0x1 ;
}
static void F_44 ( void T_1 * V_45 , unsigned V_46 , bool V_65 )
{
F_39 ( V_46 , V_45 + ( V_65 ? V_74 : V_75 ) ) ;
}
static void F_45 ( void T_1 * V_45 , unsigned V_46 )
{
F_39 ( F_37 ( V_45 + V_76 ) | V_46 , V_45 + V_76 ) ;
}
static bool F_46 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_37 ( V_45 + V_76 ) >> V_43 ) & 0x1 ;
}
static void F_47 ( const struct V_77 * V_9 , const struct V_78 * V_43 )
{
if ( V_43 -> V_31 ) {
F_2 ( V_9 , L_5 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_31 - 1 + 'A' , V_43 -> V_38 ) ;
} else {
F_2 ( V_9 , L_6 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_38 ) ;
}
}
static int F_48 ( struct V_2 * V_3 , const char * V_4 ,
int V_79 , const struct V_78 * V_43 )
{
int V_31 ;
if ( V_43 -> V_40 >= V_3 -> V_80 ) {
F_11 ( V_3 -> V_9 , L_7 ,
V_4 , V_79 , V_43 -> V_40 , V_3 -> V_80 ) ;
return - V_15 ;
}
if ( V_43 -> V_43 >= V_44 ) {
F_11 ( V_3 -> V_9 , L_8 ,
V_4 , V_79 , V_43 -> V_43 , V_44 ) ;
return - V_15 ;
}
if ( ! V_43 -> V_31 )
return 0 ;
V_31 = V_43 -> V_31 - 1 ;
if ( V_31 >= V_3 -> V_81 ) {
F_11 ( V_3 -> V_9 , L_9 ,
V_4 , V_79 , V_31 , V_3 -> V_81 ) ;
return - V_15 ;
}
if ( ! ( V_3 -> V_82 [ V_43 -> V_40 * V_3 -> V_81 + V_31 ] & 1 << V_43 -> V_43 ) ) {
F_11 ( V_3 -> V_9 , L_10 ,
V_4 , V_79 , V_31 , V_43 -> V_40 + 'A' , V_43 -> V_43 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_49 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( V_46 , V_45 + V_83 ) ;
}
static void F_50 ( void T_1 * V_45 , unsigned V_46 , bool V_84 )
{
F_22 ( V_46 , V_45 + V_85 ) ;
F_22 ( V_46 , V_45 + ( V_84 ? V_86 : V_87 ) ) ;
}
static int F_51 ( struct V_12 * V_13 , unsigned V_14 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_78 * V_37 = V_3 -> V_8 [ V_33 ] . V_37 ;
const struct V_78 * V_43 ;
T_3 V_10 = V_3 -> V_8 [ V_33 ] . V_10 ;
int V_6 , V_88 ;
unsigned V_46 ;
void T_1 * V_45 ;
F_2 ( V_3 -> V_9 , L_11 ,
V_3 -> V_89 [ V_14 ] . V_4 , V_3 -> V_8 [ V_33 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
V_88 = F_48 ( V_3 , V_3 -> V_8 [ V_33 ] . V_4 , V_6 , V_43 ) ;
if ( V_88 )
return V_88 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_47 ( V_3 -> V_9 , V_43 ) ;
V_45 = F_18 ( V_3 , V_43 -> V_40 ) ;
V_46 = F_20 ( V_43 -> V_43 ) ;
F_21 ( V_45 , V_46 ) ;
switch ( V_43 -> V_31 ) {
case V_62 :
F_50 ( V_45 , V_46 , 1 ) ;
break;
case V_90 :
V_3 -> V_91 -> V_92 ( V_45 , V_46 ) ;
break;
case V_93 :
V_3 -> V_91 -> V_94 ( V_45 , V_46 ) ;
break;
case V_95 :
if ( ! V_3 -> V_91 -> V_96 )
return - V_15 ;
V_3 -> V_91 -> V_96 ( V_45 , V_46 ) ;
break;
case V_97 :
if ( ! V_3 -> V_91 -> V_98 )
return - V_15 ;
V_3 -> V_91 -> V_98 ( V_45 , V_46 ) ;
break;
}
if ( V_43 -> V_31 )
F_49 ( V_45 , V_46 ) ;
}
return 0 ;
}
static void F_52 ( struct V_12 * V_13 , unsigned V_14 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_78 * V_37 = V_3 -> V_8 [ V_33 ] . V_37 ;
const struct V_78 * V_43 ;
T_3 V_10 = V_3 -> V_8 [ V_33 ] . V_10 ;
int V_6 ;
unsigned V_46 ;
void T_1 * V_45 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_47 ( V_3 -> V_9 , V_43 ) ;
V_45 = F_18 ( V_3 , V_43 -> V_40 ) ;
V_46 = F_20 ( V_43 -> V_43 ) ;
F_50 ( V_45 , V_46 , 1 ) ;
}
}
static int F_53 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_99 ;
}
static const char * F_54 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_89 [ V_14 ] . V_4 ;
}
static int F_55 ( struct V_12 * V_13 , unsigned V_14 ,
const char * const * * V_8 ,
unsigned * const V_100 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_8 = V_3 -> V_89 [ V_14 ] . V_8 ;
* V_100 = V_3 -> V_89 [ V_14 ] . V_7 ;
return 0 ;
}
static int F_56 ( struct V_12 * V_13 ,
struct V_101 * V_102 ,
unsigned V_18 )
{
struct V_2 * V_103 = F_4 ( V_13 ) ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
unsigned V_46 ;
if ( ! V_102 ) {
F_11 ( V_103 -> V_9 , L_12 ) ;
return - V_15 ;
}
if ( ! V_102 -> V_108 ) {
F_11 ( V_103 -> V_9 , L_13 ) ;
return - V_15 ;
}
V_107 = V_102 -> V_108 ;
V_105 = F_57 ( V_107 , struct V_104 , V_107 ) ;
F_2 ( V_103 -> V_9 , L_14 , V_18 ) ;
V_46 = 1 << ( V_18 - V_107 -> V_109 ) ;
F_2 ( V_103 -> V_9 , L_15 ,
V_18 , 'A' + V_102 -> V_110 , V_18 - V_107 -> V_109 , V_46 ) ;
F_22 ( V_46 , V_105 -> V_42 + V_85 ) ;
return 0 ;
}
static void F_58 ( struct V_12 * V_13 ,
struct V_101 * V_102 ,
unsigned V_18 )
{
struct V_2 * V_103 = F_4 ( V_13 ) ;
F_2 ( V_103 -> V_9 , L_16 , V_18 ) ;
}
static int F_59 ( struct V_12 * V_13 ,
unsigned V_111 , unsigned long * V_112 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
void T_1 * V_45 ;
unsigned V_43 ;
int div ;
F_2 ( V_3 -> V_9 , L_17 , V_113 , __LINE__ , V_111 , * V_112 ) ;
V_45 = F_18 ( V_3 , F_19 ( V_111 ) ) ;
V_43 = V_111 % V_44 ;
if ( F_26 ( V_45 , V_43 ) )
* V_112 |= V_114 ;
if ( F_23 ( V_45 , V_43 ) )
* V_112 |= V_115 ;
if ( V_3 -> V_91 -> V_116 && V_3 -> V_91 -> V_116 ( V_45 , V_43 ) )
* V_112 |= V_117 ;
if ( V_3 -> V_91 -> V_118 && V_3 -> V_91 -> V_118 ( V_45 , V_43 , & div ) )
* V_112 |= V_119 | ( div << V_120 ) ;
if ( V_3 -> V_91 -> V_121 && V_3 -> V_91 -> V_121 ( V_45 , V_43 ) )
* V_112 |= V_122 ;
if ( V_3 -> V_91 -> V_123 && V_3 -> V_91 -> V_123 ( V_45 , V_43 ) )
* V_112 |= V_124 ;
return 0 ;
}
static int F_60 ( struct V_12 * V_13 ,
unsigned V_111 , unsigned long V_112 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
unsigned V_46 ;
void T_1 * V_45 ;
F_2 ( V_3 -> V_9 , L_17 , V_113 , __LINE__ , V_111 , V_112 ) ;
V_45 = F_18 ( V_3 , F_19 ( V_111 ) ) ;
V_46 = F_20 ( V_111 % V_44 ) ;
if ( V_112 & V_115 && V_112 & V_122 )
return - V_15 ;
F_25 ( V_45 , V_46 , V_112 & V_115 ) ;
F_27 ( V_45 , V_46 , V_112 & V_114 ) ;
if ( V_3 -> V_91 -> V_125 )
V_3 -> V_91 -> V_125 ( V_45 , V_46 , V_112 & V_117 ) ;
if ( V_3 -> V_91 -> V_126 )
V_3 -> V_91 -> V_126 ( V_45 , V_46 , V_112 & V_119 ,
( V_112 & V_127 ) >> V_120 ) ;
if ( V_3 -> V_91 -> V_128 )
V_3 -> V_91 -> V_128 ( V_45 , V_46 , V_112 & V_122 ) ;
if ( V_3 -> V_91 -> V_129 && V_112 & V_124 )
V_3 -> V_91 -> V_129 ( V_45 , V_46 ) ;
return 0 ;
}
static void F_61 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_111 )
{
}
static void F_62 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_33 )
{
}
static void F_63 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_19 * V_130 ;
F_64 (np, child) {
if ( F_65 ( V_130 , V_131 ) ) {
V_3 -> V_80 ++ ;
} else {
V_3 -> V_99 ++ ;
V_3 -> V_7 += F_66 ( V_130 ) ;
}
}
}
static int F_67 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
int V_88 = 0 ;
int V_132 ;
const T_4 * V_133 ;
V_133 = F_68 ( V_20 , L_18 , & V_132 ) ;
if ( ! V_133 ) {
F_11 ( V_3 -> V_9 , L_19 , V_132 ) ;
return - V_15 ;
}
V_132 /= sizeof( * V_133 ) ;
if ( ! V_132 || V_132 % V_3 -> V_80 ) {
F_11 ( V_3 -> V_9 , L_20 , V_3 -> V_80 ) ;
return - V_15 ;
}
V_3 -> V_81 = V_132 / V_3 -> V_80 ;
V_3 -> V_82 = F_12 ( V_3 -> V_9 , sizeof( T_2 ) * V_132 , V_27 ) ;
if ( ! V_3 -> V_82 ) {
F_11 ( V_3 -> V_9 , L_21 ) ;
return - V_28 ;
}
V_88 = F_69 ( V_20 , L_18 ,
V_3 -> V_82 , V_132 ) ;
if ( V_88 )
F_11 ( V_3 -> V_9 , L_19 , V_132 ) ;
return V_88 ;
}
static int F_70 ( struct V_19 * V_20 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_2 V_79 )
{
struct V_78 * V_43 ;
int V_132 ;
const T_4 * V_133 ;
int V_6 , V_134 ;
F_2 ( V_3 -> V_9 , L_22 , V_79 , V_20 -> V_4 ) ;
V_5 -> V_4 = V_20 -> V_4 ;
V_133 = F_68 ( V_20 , L_23 , & V_132 ) ;
V_132 /= sizeof( * V_133 ) ;
if ( ! V_132 || V_132 % 4 ) {
F_11 ( V_3 -> V_9 , L_24 ) ;
return - V_15 ;
}
V_5 -> V_10 = V_132 / 4 ;
V_43 = V_5 -> V_37 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( struct V_78 ) ,
V_27 ) ;
V_5 -> V_11 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( unsigned int ) ,
V_27 ) ;
if ( ! V_5 -> V_37 || ! V_5 -> V_11 )
return - V_28 ;
for ( V_6 = 0 , V_134 = 0 ; V_6 < V_132 ; V_6 += 4 , V_134 ++ ) {
V_43 -> V_40 = F_71 ( * V_133 ++ ) ;
V_43 -> V_43 = F_71 ( * V_133 ++ ) ;
V_5 -> V_11 [ V_134 ] = V_43 -> V_40 * V_44 + V_43 -> V_43 ;
V_43 -> V_31 = F_71 ( * V_133 ++ ) ;
V_43 -> V_38 = F_71 ( * V_133 ++ ) ;
F_47 ( V_3 -> V_9 , V_43 ) ;
V_43 ++ ;
}
return 0 ;
}
static int F_72 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_2 V_79 )
{
struct V_19 * V_130 ;
struct V_135 * V_136 ;
struct V_1 * V_5 ;
int V_88 ;
static T_2 V_137 ;
T_2 V_6 = 0 ;
F_2 ( V_3 -> V_9 , L_25 , V_79 , V_20 -> V_4 ) ;
V_136 = & V_3 -> V_89 [ V_79 ] ;
V_136 -> V_4 = V_20 -> V_4 ;
V_136 -> V_7 = F_66 ( V_20 ) ;
if ( V_136 -> V_7 <= 0 ) {
F_11 ( V_3 -> V_9 , L_26 ) ;
return - V_15 ;
}
V_136 -> V_8 = F_12 ( V_3 -> V_9 ,
V_136 -> V_7 * sizeof( char * ) , V_27 ) ;
if ( ! V_136 -> V_8 )
return - V_28 ;
F_64 (np, child) {
V_136 -> V_8 [ V_6 ] = V_130 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_137 ++ ] ;
V_88 = F_70 ( V_130 , V_5 , V_3 , V_6 ++ ) ;
if ( V_88 )
return V_88 ;
}
return 0 ;
}
static int F_73 ( struct V_138 * V_139 ,
struct V_2 * V_3 )
{
int V_88 = 0 ;
int V_6 , V_134 ;
T_3 * V_140 ;
struct V_19 * V_20 = V_139 -> V_9 . V_141 ;
struct V_19 * V_130 ;
if ( ! V_20 )
return - V_142 ;
V_3 -> V_9 = & V_139 -> V_9 ;
V_3 -> V_91 = (struct V_143 * )
F_74 ( V_144 , & V_139 -> V_9 ) -> V_30 ;
F_63 ( V_3 , V_20 ) ;
if ( V_3 -> V_80 < 1 ) {
F_11 ( & V_139 -> V_9 , L_27 ) ;
return - V_15 ;
}
V_88 = F_67 ( V_3 , V_20 ) ;
if ( V_88 )
return V_88 ;
F_2 ( & V_139 -> V_9 , L_28 , V_3 -> V_81 ) ;
F_2 ( & V_139 -> V_9 , L_29 ) ;
V_140 = V_3 -> V_82 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
for ( V_134 = 0 ; V_134 < V_3 -> V_81 ; V_134 ++ , V_140 ++ ) {
F_2 ( & V_139 -> V_9 , L_30 , V_6 , V_134 , V_140 [ 0 ] ) ;
}
}
F_2 ( & V_139 -> V_9 , L_31 , V_3 -> V_99 ) ;
F_2 ( & V_139 -> V_9 , L_32 , V_3 -> V_7 ) ;
V_3 -> V_89 = F_12 ( & V_139 -> V_9 , V_3 -> V_99 * sizeof( struct V_135 ) ,
V_27 ) ;
if ( ! V_3 -> V_89 )
return - V_28 ;
V_3 -> V_8 = F_12 ( & V_139 -> V_9 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_3 -> V_8 )
return - V_28 ;
F_2 ( & V_139 -> V_9 , L_33 , V_3 -> V_80 ) ;
F_2 ( & V_139 -> V_9 , L_31 , V_3 -> V_99 ) ;
F_2 ( & V_139 -> V_9 , L_32 , V_3 -> V_7 ) ;
V_6 = 0 ;
F_64 (np, child) {
if ( F_65 ( V_130 , V_131 ) )
continue;
V_88 = F_72 ( V_130 , V_3 , V_6 ++ ) ;
if ( V_88 ) {
F_11 ( & V_139 -> V_9 , L_34 ) ;
return V_88 ;
}
}
return 0 ;
}
static int F_75 ( struct V_138 * V_139 )
{
struct V_2 * V_3 ;
struct V_145 * V_146 ;
int V_88 , V_6 , V_134 , V_147 ;
V_3 = F_12 ( & V_139 -> V_9 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_88 = F_73 ( V_139 , V_3 ) ;
if ( V_88 )
return V_88 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
if ( ! V_41 [ V_6 ] ) {
F_76 ( & V_139 -> V_9 , L_35 , V_6 ) ;
F_14 ( & V_139 -> V_9 , V_3 ) ;
return - V_148 ;
}
}
V_149 . V_4 = F_9 ( & V_139 -> V_9 ) ;
V_149 . V_10 = V_3 -> V_80 * V_44 ;
V_149 . V_11 = V_146 =
F_12 ( & V_139 -> V_9 , sizeof( * V_146 ) * V_149 . V_10 , V_27 ) ;
if ( ! V_149 . V_11 )
return - V_28 ;
for ( V_6 = 0 , V_147 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
for ( V_134 = 0 ; V_134 < V_44 ; V_134 ++ , V_147 ++ ) {
V_146 -> V_150 = V_147 ;
V_146 -> V_4 = F_77 ( V_27 , L_36 , V_6 + 'A' , V_134 ) ;
V_146 ++ ;
}
}
F_78 ( V_139 , V_3 ) ;
V_3 -> V_151 = F_79 ( & V_149 , & V_139 -> V_9 , V_3 ) ;
if ( ! V_3 -> V_151 ) {
F_11 ( & V_139 -> V_9 , L_37 ) ;
V_88 = - V_15 ;
goto V_152;
}
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ )
F_80 ( V_3 -> V_151 , & V_41 [ V_6 ] -> V_102 ) ;
F_81 ( & V_139 -> V_9 , L_38 ) ;
return 0 ;
V_152:
return V_88 ;
}
static int F_82 ( struct V_138 * V_139 )
{
struct V_2 * V_3 = F_83 ( V_139 ) ;
F_84 ( V_3 -> V_151 ) ;
return 0 ;
}
static int F_85 ( struct V_106 * V_107 , unsigned V_18 )
{
int V_153 = V_107 -> V_109 + V_18 ;
int V_40 = V_107 -> V_109 / V_107 -> V_154 ;
F_2 ( V_107 -> V_9 , L_39 , V_113 , __LINE__ ,
'A' + V_40 , V_18 , V_153 ) ;
return F_86 ( V_153 ) ;
}
static void F_87 ( struct V_106 * V_107 , unsigned V_18 )
{
int V_153 = V_107 -> V_109 + V_18 ;
F_88 ( V_153 ) ;
}
static int F_89 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_155 = F_90 ( V_107 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + V_86 ) ;
return 0 ;
}
static int F_91 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_155 = F_90 ( V_107 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
T_2 V_156 ;
V_156 = F_24 ( V_45 + V_157 ) ;
return ( V_156 & V_46 ) != 0 ;
}
static void F_92 ( struct V_106 * V_107 , unsigned V_18 ,
int V_158 )
{
struct V_104 * V_155 = F_90 ( V_107 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + ( V_158 ? V_159 : V_160 ) ) ;
}
static int F_93 ( struct V_106 * V_107 , unsigned V_18 ,
int V_158 )
{
struct V_104 * V_155 = F_90 ( V_107 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + ( V_158 ? V_159 : V_160 ) ) ;
F_22 ( V_46 , V_45 + V_87 ) ;
return 0 ;
}
static int F_94 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_155 = F_90 ( V_107 ) ;
int V_161 ;
if ( V_18 < V_107 -> V_154 )
V_161 = F_95 ( V_155 -> V_162 , V_18 ) ;
else
V_161 = - V_163 ;
F_2 ( V_107 -> V_9 , L_40 ,
V_107 -> V_164 , V_18 + V_107 -> V_109 , V_161 ) ;
return V_161 ;
}
static void F_96 ( struct V_16 * V_17 , struct V_106 * V_107 )
{
enum V_59 V_165 ;
int V_6 ;
struct V_104 * V_155 = F_90 ( V_107 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
for ( V_6 = 0 ; V_6 < V_107 -> V_154 ; V_6 ++ ) {
unsigned V_43 = V_107 -> V_109 + V_6 ;
unsigned V_46 = F_20 ( V_43 ) ;
const char * V_166 ;
T_2 V_156 ;
V_166 = F_97 ( V_107 , V_6 ) ;
if ( ! V_166 )
continue;
V_165 = V_155 -> V_91 -> V_167 ( V_45 , V_46 ) ;
F_8 ( V_17 , L_41 ,
V_166 , V_107 -> V_164 , V_6 ) ;
if ( V_165 == V_62 ) {
V_156 = F_24 ( V_45 + V_157 ) ;
F_8 ( V_17 , L_42 ,
V_156 & V_46 ?
L_43 : L_44 ) ;
} else {
F_8 ( V_17 , L_45 ,
V_165 + 'A' - 1 ) ;
}
}
}
static void F_98 ( struct V_168 * V_169 )
{
struct V_104 * V_155 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
if ( V_45 )
F_22 ( V_46 , V_45 + V_47 ) ;
}
static void F_100 ( struct V_168 * V_169 )
{
struct V_104 * V_155 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
if ( V_45 )
F_22 ( V_46 , V_45 + V_171 ) ;
}
static int F_101 ( struct V_168 * V_169 , unsigned type )
{
switch ( type ) {
case V_172 :
case V_173 :
return 0 ;
default:
return - V_15 ;
}
}
static int F_102 ( struct V_168 * V_169 , unsigned type )
{
struct V_104 * V_155 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
switch ( type ) {
case V_174 :
F_22 ( V_46 , V_45 + V_175 ) ;
F_22 ( V_46 , V_45 + V_176 ) ;
break;
case V_177 :
F_22 ( V_46 , V_45 + V_175 ) ;
F_22 ( V_46 , V_45 + V_178 ) ;
break;
case V_179 :
F_22 ( V_46 , V_45 + V_180 ) ;
F_22 ( V_46 , V_45 + V_178 ) ;
break;
case V_181 :
F_22 ( V_46 , V_45 + V_180 ) ;
F_22 ( V_46 , V_45 + V_176 ) ;
break;
case V_173 :
F_22 ( V_46 , V_45 + V_182 ) ;
return 0 ;
case V_172 :
default:
F_103 ( L_46 , F_104 ( V_169 -> V_183 ) ) ;
return - V_15 ;
}
F_22 ( V_46 , V_45 + V_184 ) ;
return 0 ;
}
static int F_105 ( struct V_168 * V_169 , unsigned V_185 )
{
struct V_104 * V_155 = F_99 ( V_169 ) ;
unsigned V_40 = V_155 -> V_186 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
if ( F_106 ( V_40 >= V_187 ) )
return - V_15 ;
if ( V_185 )
V_188 [ V_40 ] |= V_46 ;
else
V_188 [ V_40 ] &= ~ V_46 ;
F_107 ( V_155 -> V_189 , V_185 ) ;
return 0 ;
}
void F_108 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_190 ; V_6 ++ ) {
void T_1 * V_45 ;
if ( ! V_41 [ V_6 ] )
continue;
V_45 = V_41 [ V_6 ] -> V_42 ;
V_191 [ V_6 ] = F_37 ( V_45 + V_192 ) ;
F_39 ( V_191 [ V_6 ] , V_45 + V_47 ) ;
F_39 ( V_188 [ V_6 ] , V_45 + V_171 ) ;
if ( ! V_188 [ V_6 ] ) {
F_109 ( V_41 [ V_6 ] -> clock ) ;
F_110 ( V_41 [ V_6 ] -> clock ) ;
} else {
F_111 ( V_193 L_47 ,
'A' + V_6 , V_188 [ V_6 ] ) ;
}
}
}
void F_112 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_190 ; V_6 ++ ) {
void T_1 * V_45 ;
if ( ! V_41 [ V_6 ] )
continue;
V_45 = V_41 [ V_6 ] -> V_42 ;
if ( ! V_188 [ V_6 ] ) {
if ( F_113 ( V_41 [ V_6 ] -> clock ) == 0 )
F_114 ( V_41 [ V_6 ] -> clock ) ;
}
F_39 ( V_188 [ V_6 ] , V_45 + V_47 ) ;
F_39 ( V_191 [ V_6 ] , V_45 + V_171 ) ;
}
}
static void F_115 ( unsigned V_183 , struct V_194 * V_195 )
{
struct V_196 * V_107 = F_116 ( V_195 ) ;
struct V_168 * V_197 = F_117 ( V_195 ) ;
struct V_104 * V_155 = F_99 ( V_197 ) ;
void T_1 * V_45 = V_155 -> V_42 ;
unsigned long V_198 ;
int V_199 ;
F_118 ( V_107 , V_195 ) ;
for (; ; ) {
V_198 = F_24 ( V_45 + V_200 ) & F_24 ( V_45 + V_192 ) ;
if ( ! V_198 ) {
if ( ! V_155 -> V_201 )
break;
V_155 = V_155 -> V_201 ;
V_45 = V_155 -> V_42 ;
continue;
}
F_119 (n, &isr, BITS_PER_LONG) {
F_120 ( F_121 ( V_155 -> V_162 , V_199 ) ) ;
}
}
F_122 ( V_107 , V_195 ) ;
}
static int F_123 ( struct V_202 * V_203 , unsigned int V_161 ,
T_5 V_204 )
{
struct V_104 * V_155 = V_203 -> V_205 ;
F_124 ( V_161 , & V_206 ) ;
F_125 ( V_161 , & V_207 ,
V_208 ) ;
F_126 ( V_161 , V_209 ) ;
F_127 ( V_161 , V_155 ) ;
return 0 ;
}
static int F_128 ( struct V_202 * V_169 ,
struct V_19 * V_210 ,
const T_2 * V_211 , unsigned int V_212 ,
T_5 * V_213 ,
unsigned int * V_214 )
{
struct V_104 * V_155 = V_169 -> V_205 ;
int V_88 ;
int V_43 = V_155 -> V_107 . V_109 + V_211 [ 0 ] ;
if ( F_129 ( V_212 < 2 ) )
return - V_15 ;
* V_213 = V_211 [ 0 ] ;
* V_214 = V_211 [ 1 ] & V_215 ;
V_88 = F_130 ( V_43 , V_210 -> V_216 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_131 ( V_43 ) ;
if ( V_88 )
return V_88 ;
return 0 ;
}
static int F_132 ( struct V_19 * V_217 ,
struct V_104 * V_155 )
{
struct V_104 * V_218 = NULL ;
struct V_168 * V_169 = F_133 ( V_155 -> V_189 ) ;
V_155 -> V_219 = F_134 ( V_169 ) ;
V_207 . V_220 = V_155 -> V_91 -> V_221 ;
F_22 ( ~ 0 , V_155 -> V_42 + V_47 ) ;
V_155 -> V_162 = F_135 ( V_217 , V_155 -> V_107 . V_154 ,
& V_222 , V_155 ) ;
if ( ! V_155 -> V_162 )
F_136 ( L_48 ,
V_155 -> V_186 ) ;
if ( V_155 -> V_186 )
V_218 = V_41 [ V_155 -> V_186 - 1 ] ;
if ( V_218 && V_218 -> V_201 == V_155 )
return 0 ;
F_127 ( V_155 -> V_189 , V_155 ) ;
F_137 ( V_155 -> V_189 , F_115 ) ;
return 0 ;
}
static void F_138 ( void )
{
unsigned V_6 ;
struct V_104 * V_155 , * V_223 = NULL ;
for ( V_6 = 0 ; V_6 < V_190 ; V_6 ++ ) {
V_155 = V_41 [ V_6 ] ;
if ( V_223 && V_223 -> V_189 == V_155 -> V_189 )
V_223 -> V_201 = V_155 ;
V_223 = V_155 ;
}
}
static int F_139 ( struct V_138 * V_139 )
{
struct V_19 * V_20 = V_139 -> V_9 . V_141 ;
struct V_224 * V_225 ;
struct V_104 * V_105 = NULL ;
struct V_106 * V_107 ;
struct V_101 * V_102 ;
int V_88 = 0 ;
int V_183 , V_6 ;
int V_226 = F_140 ( V_20 , L_49 ) ;
T_3 V_154 ;
char * * V_227 ;
F_141 ( V_226 >= F_142 ( V_41 ) ) ;
if ( V_41 [ V_226 ] ) {
V_88 = - V_228 ;
goto V_152;
}
V_183 = F_143 ( V_139 , 0 ) ;
if ( V_183 < 0 ) {
V_88 = V_183 ;
goto V_152;
}
V_105 = F_12 ( & V_139 -> V_9 , sizeof( * V_105 ) , V_27 ) ;
if ( ! V_105 ) {
V_88 = - V_28 ;
goto V_152;
}
V_225 = F_144 ( V_139 , V_229 , 0 ) ;
V_105 -> V_42 = F_145 ( & V_139 -> V_9 , V_225 ) ;
if ( F_146 ( V_105 -> V_42 ) ) {
V_88 = F_147 ( V_105 -> V_42 ) ;
goto V_152;
}
V_105 -> V_91 = (struct V_143 * )
F_74 ( V_230 , & V_139 -> V_9 ) -> V_30 ;
V_105 -> V_189 = V_183 ;
V_105 -> V_186 = V_226 ;
V_105 -> clock = F_148 ( & V_139 -> V_9 , NULL ) ;
if ( F_146 ( V_105 -> clock ) ) {
F_11 ( & V_139 -> V_9 , L_50 ) ;
goto V_152;
}
if ( F_113 ( V_105 -> clock ) )
goto V_231;
if ( F_114 ( V_105 -> clock ) ) {
F_11 ( & V_139 -> V_9 , L_51 ) ;
goto V_232;
}
V_105 -> V_107 = V_233 ;
V_107 = & V_105 -> V_107 ;
V_107 -> V_141 = V_20 ;
V_107 -> V_164 = F_9 ( & V_139 -> V_9 ) ;
V_107 -> V_9 = & V_139 -> V_9 ;
V_107 -> V_234 = V_235 ;
V_107 -> V_109 = V_226 * V_44 ;
if ( ! F_149 ( V_20 , L_52 , & V_154 ) ) {
if ( V_154 >= V_44 )
F_150 ( L_53 ,
V_226 , V_44 , V_44 ) ;
else
V_107 -> V_154 = V_154 ;
}
V_227 = F_12 ( & V_139 -> V_9 , sizeof( char * ) * V_107 -> V_154 ,
V_27 ) ;
if ( ! V_227 ) {
V_88 = - V_28 ;
goto V_232;
}
for ( V_6 = 0 ; V_6 < V_107 -> V_154 ; V_6 ++ )
V_227 [ V_6 ] = F_77 ( V_27 , L_36 , V_226 + 'A' , V_6 ) ;
V_107 -> V_227 = ( const char * const * ) V_227 ;
V_102 = & V_105 -> V_102 ;
V_102 -> V_4 = V_107 -> V_164 ;
V_102 -> V_110 = V_226 ;
V_102 -> V_236 = V_102 -> V_109 = V_102 -> V_110 * V_44 ;
V_102 -> V_10 = V_107 -> V_154 ;
V_102 -> V_108 = V_107 ;
V_88 = F_151 ( V_107 ) ;
if ( V_88 )
goto V_232;
V_41 [ V_226 ] = V_105 ;
V_190 = F_152 ( V_190 , V_226 + 1 ) ;
F_138 () ;
F_132 ( V_20 , V_105 ) ;
F_81 ( & V_139 -> V_9 , L_54 , V_105 -> V_42 ) ;
return 0 ;
V_232:
F_109 ( V_105 -> clock ) ;
V_231:
F_153 ( V_105 -> clock ) ;
V_152:
F_11 ( & V_139 -> V_9 , L_55 , V_88 , V_226 ) ;
return V_88 ;
}
static int T_6 F_154 ( void )
{
int V_88 ;
V_88 = F_155 ( & V_237 ) ;
if ( V_88 )
return V_88 ;
return F_155 ( & V_238 ) ;
}
static void T_7 F_156 ( void )
{
F_157 ( & V_238 ) ;
}
