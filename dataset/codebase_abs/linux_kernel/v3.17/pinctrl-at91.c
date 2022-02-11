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
return ! ( ( F_24 ( V_45 + V_48 ) >> V_43 ) & 0x1 ) ;
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
static bool F_40 ( void T_1 * V_45 , unsigned V_43 )
{
if ( ( F_37 ( V_45 + V_64 ) >> V_43 ) & 0x1 )
return ! ( ( F_37 ( V_45 + V_68 ) >> V_43 ) & 0x1 ) ;
return false ;
}
static void F_41 ( void T_1 * V_45 , unsigned V_46 , bool V_65 )
{
if ( V_65 )
F_39 ( V_46 , V_45 + V_69 ) ;
F_38 ( V_45 , V_46 , V_65 ) ;
}
static bool F_42 ( void T_1 * V_45 , unsigned V_43 , T_2 * div )
{
* div = F_37 ( V_45 + V_70 ) ;
return ( ( F_37 ( V_45 + V_64 ) >> V_43 ) & 0x1 ) &&
( ( F_37 ( V_45 + V_68 ) >> V_43 ) & 0x1 ) ;
}
static void F_43 ( void T_1 * V_45 , unsigned V_46 ,
bool V_65 , T_2 div )
{
if ( V_65 ) {
F_39 ( V_46 , V_45 + V_71 ) ;
F_39 ( div & V_72 , V_45 + V_70 ) ;
F_39 ( V_46 , V_45 + V_66 ) ;
} else
F_39 ( V_46 , V_45 + V_69 ) ;
}
static bool F_44 ( void T_1 * V_45 , unsigned V_43 )
{
return ! ( ( F_37 ( V_45 + V_73 ) >> V_43 ) & 0x1 ) ;
}
static void F_45 ( void T_1 * V_45 , unsigned V_46 , bool V_65 )
{
F_39 ( V_46 , V_45 + ( V_65 ? V_74 : V_75 ) ) ;
}
static void F_46 ( void T_1 * V_45 , unsigned V_46 )
{
F_39 ( F_37 ( V_45 + V_76 ) | V_46 , V_45 + V_76 ) ;
}
static bool F_47 ( void T_1 * V_45 , unsigned V_43 )
{
return ( F_37 ( V_45 + V_76 ) >> V_43 ) & 0x1 ;
}
static void F_48 ( const struct V_77 * V_9 , const struct V_78 * V_43 )
{
if ( V_43 -> V_31 ) {
F_2 ( V_9 , L_5 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_31 - 1 + 'A' , V_43 -> V_38 ) ;
} else {
F_2 ( V_9 , L_6 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_38 ) ;
}
}
static int F_49 ( struct V_2 * V_3 , const char * V_4 ,
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
static void F_50 ( void T_1 * V_45 , unsigned V_46 )
{
F_22 ( V_46 , V_45 + V_83 ) ;
}
static void F_51 ( void T_1 * V_45 , unsigned V_46 , bool V_84 )
{
F_22 ( V_46 , V_45 + V_85 ) ;
F_22 ( V_46 , V_45 + ( V_84 ? V_86 : V_87 ) ) ;
}
static int F_52 ( struct V_12 * V_13 , unsigned V_14 ,
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
V_88 = F_49 ( V_3 , V_3 -> V_8 [ V_33 ] . V_4 , V_6 , V_43 ) ;
if ( V_88 )
return V_88 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_48 ( V_3 -> V_9 , V_43 ) ;
V_45 = F_18 ( V_3 , V_43 -> V_40 ) ;
V_46 = F_20 ( V_43 -> V_43 ) ;
F_21 ( V_45 , V_46 ) ;
switch ( V_43 -> V_31 ) {
case V_62 :
F_51 ( V_45 , V_46 , 1 ) ;
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
F_50 ( V_45 , V_46 ) ;
}
return 0 ;
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
* V_112 = 0 ;
F_2 ( V_3 -> V_9 , L_17 , V_113 , __LINE__ , V_111 ) ;
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
unsigned V_111 , unsigned long * V_35 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
unsigned V_46 ;
void T_1 * V_45 ;
int V_6 ;
unsigned long V_112 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
V_112 = V_35 [ V_6 ] ;
F_2 ( V_3 -> V_9 ,
L_18 ,
V_113 , __LINE__ , V_111 , V_112 ) ;
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
}
return 0 ;
}
static void F_61 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_111 )
{
unsigned long V_112 ;
int V_130 , V_131 = 0 ;
F_59 ( V_13 , V_111 , & V_112 ) ;
F_62 ( V_114 ) ;
F_62 ( V_115 ) ;
F_62 ( V_122 ) ;
F_62 ( V_124 ) ;
F_62 ( V_117 ) ;
F_62 ( V_119 ) ;
if ( V_112 & V_119 ) {
V_130 = V_112 >> V_120 ;
F_8 ( V_17 , L_19 , V_130 ) ;
}
return;
}
static void F_63 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_33 )
{
}
static void F_64 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_19 * V_132 ;
F_65 (np, child) {
if ( F_66 ( V_132 , V_133 ) ) {
V_3 -> V_80 ++ ;
} else {
V_3 -> V_99 ++ ;
V_3 -> V_7 += F_67 ( V_132 ) ;
}
}
}
static int F_68 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
int V_88 = 0 ;
int V_134 ;
const T_4 * V_135 ;
V_135 = F_69 ( V_20 , L_20 , & V_134 ) ;
if ( ! V_135 ) {
F_11 ( V_3 -> V_9 , L_21 , V_134 ) ;
return - V_15 ;
}
V_134 /= sizeof( * V_135 ) ;
if ( ! V_134 || V_134 % V_3 -> V_80 ) {
F_11 ( V_3 -> V_9 , L_22 , V_3 -> V_80 ) ;
return - V_15 ;
}
V_3 -> V_81 = V_134 / V_3 -> V_80 ;
V_3 -> V_82 = F_12 ( V_3 -> V_9 , sizeof( T_2 ) * V_134 , V_27 ) ;
if ( ! V_3 -> V_82 ) {
F_11 ( V_3 -> V_9 , L_23 ) ;
return - V_28 ;
}
V_88 = F_70 ( V_20 , L_20 ,
V_3 -> V_82 , V_134 ) ;
if ( V_88 )
F_11 ( V_3 -> V_9 , L_21 , V_134 ) ;
return V_88 ;
}
static int F_71 ( struct V_19 * V_20 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_2 V_79 )
{
struct V_78 * V_43 ;
int V_134 ;
const T_4 * V_135 ;
int V_6 , V_136 ;
F_2 ( V_3 -> V_9 , L_24 , V_79 , V_20 -> V_4 ) ;
V_5 -> V_4 = V_20 -> V_4 ;
V_135 = F_69 ( V_20 , L_25 , & V_134 ) ;
V_134 /= sizeof( * V_135 ) ;
if ( ! V_134 || V_134 % 4 ) {
F_11 ( V_3 -> V_9 , L_26 ) ;
return - V_15 ;
}
V_5 -> V_10 = V_134 / 4 ;
V_43 = V_5 -> V_37 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( struct V_78 ) ,
V_27 ) ;
V_5 -> V_11 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( unsigned int ) ,
V_27 ) ;
if ( ! V_5 -> V_37 || ! V_5 -> V_11 )
return - V_28 ;
for ( V_6 = 0 , V_136 = 0 ; V_6 < V_134 ; V_6 += 4 , V_136 ++ ) {
V_43 -> V_40 = F_72 ( * V_135 ++ ) ;
V_43 -> V_43 = F_72 ( * V_135 ++ ) ;
V_5 -> V_11 [ V_136 ] = V_43 -> V_40 * V_44 + V_43 -> V_43 ;
V_43 -> V_31 = F_72 ( * V_135 ++ ) ;
V_43 -> V_38 = F_72 ( * V_135 ++ ) ;
F_48 ( V_3 -> V_9 , V_43 ) ;
V_43 ++ ;
}
return 0 ;
}
static int F_73 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_2 V_79 )
{
struct V_19 * V_132 ;
struct V_137 * V_138 ;
struct V_1 * V_5 ;
int V_88 ;
static T_2 V_139 ;
T_2 V_6 = 0 ;
F_2 ( V_3 -> V_9 , L_27 , V_79 , V_20 -> V_4 ) ;
V_138 = & V_3 -> V_89 [ V_79 ] ;
V_138 -> V_4 = V_20 -> V_4 ;
V_138 -> V_7 = F_67 ( V_20 ) ;
if ( V_138 -> V_7 == 0 ) {
F_11 ( V_3 -> V_9 , L_28 ) ;
return - V_15 ;
}
V_138 -> V_8 = F_12 ( V_3 -> V_9 ,
V_138 -> V_7 * sizeof( char * ) , V_27 ) ;
if ( ! V_138 -> V_8 )
return - V_28 ;
F_65 (np, child) {
V_138 -> V_8 [ V_6 ] = V_132 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_139 ++ ] ;
V_88 = F_71 ( V_132 , V_5 , V_3 , V_6 ++ ) ;
if ( V_88 )
return V_88 ;
}
return 0 ;
}
static int F_74 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
int V_88 = 0 ;
int V_6 , V_136 ;
T_3 * V_142 ;
struct V_19 * V_20 = V_141 -> V_9 . V_143 ;
struct V_19 * V_132 ;
if ( ! V_20 )
return - V_144 ;
V_3 -> V_9 = & V_141 -> V_9 ;
V_3 -> V_91 = (struct V_145 * )
F_75 ( V_146 , & V_141 -> V_9 ) -> V_30 ;
F_64 ( V_3 , V_20 ) ;
if ( V_3 -> V_80 < 1 ) {
F_11 ( & V_141 -> V_9 , L_29 ) ;
return - V_15 ;
}
V_88 = F_68 ( V_3 , V_20 ) ;
if ( V_88 )
return V_88 ;
F_2 ( & V_141 -> V_9 , L_30 , V_3 -> V_81 ) ;
F_2 ( & V_141 -> V_9 , L_31 ) ;
V_142 = V_3 -> V_82 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
for ( V_136 = 0 ; V_136 < V_3 -> V_81 ; V_136 ++ , V_142 ++ ) {
F_2 ( & V_141 -> V_9 , L_32 , V_6 , V_136 , V_142 [ 0 ] ) ;
}
}
F_2 ( & V_141 -> V_9 , L_33 , V_3 -> V_99 ) ;
F_2 ( & V_141 -> V_9 , L_34 , V_3 -> V_7 ) ;
V_3 -> V_89 = F_12 ( & V_141 -> V_9 , V_3 -> V_99 * sizeof( struct V_137 ) ,
V_27 ) ;
if ( ! V_3 -> V_89 )
return - V_28 ;
V_3 -> V_8 = F_12 ( & V_141 -> V_9 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_3 -> V_8 )
return - V_28 ;
F_2 ( & V_141 -> V_9 , L_35 , V_3 -> V_80 ) ;
F_2 ( & V_141 -> V_9 , L_33 , V_3 -> V_99 ) ;
F_2 ( & V_141 -> V_9 , L_34 , V_3 -> V_7 ) ;
V_6 = 0 ;
F_65 (np, child) {
if ( F_66 ( V_132 , V_133 ) )
continue;
V_88 = F_73 ( V_132 , V_3 , V_6 ++ ) ;
if ( V_88 ) {
F_11 ( & V_141 -> V_9 , L_36 ) ;
return V_88 ;
}
}
return 0 ;
}
static int F_76 ( struct V_140 * V_141 )
{
struct V_2 * V_3 ;
struct V_147 * V_148 ;
int V_88 , V_6 , V_136 , V_149 ;
V_3 = F_12 ( & V_141 -> V_9 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_88 = F_74 ( V_141 , V_3 ) ;
if ( V_88 )
return V_88 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
if ( ! V_41 [ V_6 ] ) {
F_77 ( & V_141 -> V_9 , L_37 , V_6 ) ;
F_14 ( & V_141 -> V_9 , V_3 ) ;
return - V_150 ;
}
}
V_151 . V_4 = F_9 ( & V_141 -> V_9 ) ;
V_151 . V_10 = V_3 -> V_80 * V_44 ;
V_151 . V_11 = V_148 =
F_12 ( & V_141 -> V_9 , sizeof( * V_148 ) * V_151 . V_10 , V_27 ) ;
if ( ! V_151 . V_11 )
return - V_28 ;
for ( V_6 = 0 , V_149 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ ) {
for ( V_136 = 0 ; V_136 < V_44 ; V_136 ++ , V_149 ++ ) {
V_148 -> V_152 = V_149 ;
V_148 -> V_4 = F_78 ( V_27 , L_38 , V_6 + 'A' , V_136 ) ;
V_148 ++ ;
}
}
F_79 ( V_141 , V_3 ) ;
V_3 -> V_153 = F_80 ( & V_151 , & V_141 -> V_9 , V_3 ) ;
if ( ! V_3 -> V_153 ) {
F_11 ( & V_141 -> V_9 , L_39 ) ;
V_88 = - V_15 ;
goto V_154;
}
for ( V_6 = 0 ; V_6 < V_3 -> V_80 ; V_6 ++ )
F_81 ( V_3 -> V_153 , & V_41 [ V_6 ] -> V_102 ) ;
F_82 ( & V_141 -> V_9 , L_40 ) ;
return 0 ;
V_154:
return V_88 ;
}
static int F_83 ( struct V_140 * V_141 )
{
struct V_2 * V_3 = F_84 ( V_141 ) ;
F_85 ( V_3 -> V_153 ) ;
return 0 ;
}
static int F_86 ( struct V_106 * V_107 , unsigned V_18 )
{
int V_155 = V_107 -> V_109 + V_18 ;
int V_40 = V_107 -> V_109 / V_107 -> V_156 ;
F_2 ( V_107 -> V_9 , L_41 , V_113 , __LINE__ ,
'A' + V_40 , V_18 , V_155 ) ;
return F_87 ( V_155 ) ;
}
static void F_88 ( struct V_106 * V_107 , unsigned V_18 )
{
int V_155 = V_107 -> V_109 + V_18 ;
F_89 ( V_155 ) ;
}
static int F_90 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
T_2 V_158 ;
V_158 = F_24 ( V_45 + V_159 ) ;
return ! ( V_158 & V_46 ) ;
}
static int F_92 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + V_86 ) ;
return 0 ;
}
static int F_93 ( struct V_106 * V_107 , unsigned V_18 )
{
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
T_2 V_160 ;
V_160 = F_24 ( V_45 + V_161 ) ;
return ( V_160 & V_46 ) != 0 ;
}
static void F_94 ( struct V_106 * V_107 , unsigned V_18 ,
int V_130 )
{
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + ( V_130 ? V_162 : V_163 ) ) ;
}
static int F_95 ( struct V_106 * V_107 , unsigned V_18 ,
int V_130 )
{
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_18 ;
F_22 ( V_46 , V_45 + ( V_130 ? V_162 : V_163 ) ) ;
F_22 ( V_46 , V_45 + V_87 ) ;
return 0 ;
}
static void F_96 ( struct V_16 * V_17 , struct V_106 * V_107 )
{
enum V_59 V_164 ;
int V_6 ;
struct V_104 * V_157 = F_91 ( V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
for ( V_6 = 0 ; V_6 < V_107 -> V_156 ; V_6 ++ ) {
unsigned V_46 = F_20 ( V_6 ) ;
const char * V_165 ;
T_2 V_160 ;
V_165 = F_97 ( V_107 , V_6 ) ;
if ( ! V_165 )
continue;
V_164 = V_157 -> V_91 -> V_166 ( V_45 , V_46 ) ;
F_8 ( V_17 , L_42 ,
V_165 , V_107 -> V_167 , V_6 ) ;
if ( V_164 == V_62 ) {
V_160 = F_24 ( V_45 + V_161 ) ;
F_8 ( V_17 , L_43 ,
V_160 & V_46 ?
L_44 : L_45 ) ;
} else {
F_8 ( V_17 , L_46 ,
V_164 + 'A' - 1 ) ;
}
}
}
static void F_98 ( struct V_168 * V_169 )
{
struct V_104 * V_157 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
if ( V_45 )
F_22 ( V_46 , V_45 + V_47 ) ;
}
static void F_100 ( struct V_168 * V_169 )
{
struct V_104 * V_157 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
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
struct V_104 * V_157 = F_99 ( V_169 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
switch ( type ) {
case V_174 :
F_103 ( V_169 -> V_175 , V_176 ) ;
F_22 ( V_46 , V_45 + V_177 ) ;
F_22 ( V_46 , V_45 + V_178 ) ;
break;
case V_179 :
F_103 ( V_169 -> V_175 , V_176 ) ;
F_22 ( V_46 , V_45 + V_177 ) ;
F_22 ( V_46 , V_45 + V_180 ) ;
break;
case V_181 :
F_103 ( V_169 -> V_175 , V_182 ) ;
F_22 ( V_46 , V_45 + V_183 ) ;
F_22 ( V_46 , V_45 + V_180 ) ;
break;
case V_184 :
F_103 ( V_169 -> V_175 , V_182 ) ;
F_22 ( V_46 , V_45 + V_183 ) ;
F_22 ( V_46 , V_45 + V_178 ) ;
break;
case V_173 :
F_103 ( V_169 -> V_175 , V_176 ) ;
F_22 ( V_46 , V_45 + V_185 ) ;
return 0 ;
case V_172 :
default:
F_104 ( L_47 , F_105 ( V_169 -> V_175 ) ) ;
return - V_15 ;
}
F_22 ( V_46 , V_45 + V_186 ) ;
return 0 ;
}
static void F_106 ( struct V_168 * V_169 )
{
}
static unsigned int F_107 ( struct V_168 * V_169 )
{
struct V_104 * V_157 = F_99 ( V_169 ) ;
unsigned V_43 = V_169 -> V_170 ;
int V_88 ;
V_88 = F_108 ( & V_157 -> V_107 , V_43 ) ;
if ( V_88 ) {
F_11 ( V_157 -> V_107 . V_9 , L_48 ,
V_169 -> V_170 ) ;
return V_88 ;
}
F_100 ( V_169 ) ;
return 0 ;
}
static void F_109 ( struct V_168 * V_169 )
{
struct V_104 * V_157 = F_99 ( V_169 ) ;
unsigned V_43 = V_169 -> V_170 ;
F_98 ( V_169 ) ;
F_110 ( & V_157 -> V_107 , V_43 ) ;
}
static int F_111 ( struct V_168 * V_169 , unsigned V_187 )
{
struct V_104 * V_157 = F_99 ( V_169 ) ;
unsigned V_40 = V_157 -> V_188 ;
unsigned V_46 = 1 << V_169 -> V_170 ;
if ( F_112 ( V_40 >= V_189 ) )
return - V_15 ;
if ( V_187 )
V_190 [ V_40 ] |= V_46 ;
else
V_190 [ V_40 ] &= ~ V_46 ;
F_113 ( V_157 -> V_191 , V_187 ) ;
return 0 ;
}
void F_114 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_192 ; V_6 ++ ) {
void T_1 * V_45 ;
if ( ! V_41 [ V_6 ] )
continue;
V_45 = V_41 [ V_6 ] -> V_42 ;
V_193 [ V_6 ] = F_37 ( V_45 + V_194 ) ;
F_39 ( V_193 [ V_6 ] , V_45 + V_47 ) ;
F_39 ( V_190 [ V_6 ] , V_45 + V_171 ) ;
if ( ! V_190 [ V_6 ] )
F_115 ( V_41 [ V_6 ] -> clock ) ;
else
F_116 ( V_195 L_49 ,
'A' + V_6 , V_190 [ V_6 ] ) ;
}
}
void F_117 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_192 ; V_6 ++ ) {
void T_1 * V_45 ;
if ( ! V_41 [ V_6 ] )
continue;
V_45 = V_41 [ V_6 ] -> V_42 ;
if ( ! V_190 [ V_6 ] )
F_118 ( V_41 [ V_6 ] -> clock ) ;
F_39 ( V_190 [ V_6 ] , V_45 + V_47 ) ;
F_39 ( V_193 [ V_6 ] , V_45 + V_171 ) ;
}
}
static void F_119 ( unsigned V_175 , struct V_196 * V_197 )
{
struct V_198 * V_107 = F_120 ( V_175 ) ;
struct V_106 * V_106 = F_121 ( V_197 ) ;
struct V_104 * V_157 = F_57 ( V_106 ,
struct V_104 , V_107 ) ;
void T_1 * V_45 = V_157 -> V_42 ;
unsigned long V_199 ;
int V_200 ;
F_122 ( V_107 , V_197 ) ;
for (; ; ) {
V_199 = F_24 ( V_45 + V_201 ) & F_24 ( V_45 + V_194 ) ;
if ( ! V_199 ) {
if ( ! V_157 -> V_202 )
break;
V_157 = V_157 -> V_202 ;
V_45 = V_157 -> V_42 ;
V_106 = & V_157 -> V_107 ;
continue;
}
F_123 (n, &isr, BITS_PER_LONG) {
F_124 ( F_125 (
V_106 -> V_203 , V_200 ) ) ;
}
}
F_126 ( V_107 , V_197 ) ;
}
static int F_127 ( struct V_19 * V_204 ,
struct V_104 * V_157 )
{
struct V_104 * V_205 = NULL ;
struct V_168 * V_169 = F_128 ( V_157 -> V_191 ) ;
int V_88 ;
V_157 -> V_206 = F_129 ( V_169 ) ;
V_207 . V_208 = V_157 -> V_91 -> V_209 ;
F_22 ( ~ 0 , V_157 -> V_42 + V_47 ) ;
V_88 = F_130 ( & V_157 -> V_107 ,
& V_207 ,
0 ,
V_210 ,
V_173 ) ;
if ( V_88 )
F_131 ( L_50 ,
V_157 -> V_188 ) ;
if ( V_157 -> V_188 )
V_205 = V_41 [ V_157 -> V_188 - 1 ] ;
if ( V_205 && V_205 -> V_202 == V_157 )
return 0 ;
F_132 ( & V_157 -> V_107 ,
& V_207 ,
V_157 -> V_191 ,
F_119 ) ;
return 0 ;
}
static void F_133 ( void )
{
unsigned V_6 ;
struct V_104 * V_157 , * V_211 = NULL ;
for ( V_6 = 0 ; V_6 < V_192 ; V_6 ++ ) {
V_157 = V_41 [ V_6 ] ;
if ( V_211 && V_211 -> V_191 == V_157 -> V_191 )
V_211 -> V_202 = V_157 ;
V_211 = V_157 ;
}
}
static int F_134 ( struct V_140 * V_141 )
{
struct V_19 * V_20 = V_141 -> V_9 . V_143 ;
struct V_212 * V_213 ;
struct V_104 * V_105 = NULL ;
struct V_106 * V_107 ;
struct V_101 * V_102 ;
int V_88 = 0 ;
int V_175 , V_6 ;
int V_214 = F_135 ( V_20 , L_51 ) ;
T_3 V_156 ;
char * * V_215 ;
F_136 ( V_214 >= F_137 ( V_41 ) ) ;
if ( V_41 [ V_214 ] ) {
V_88 = - V_216 ;
goto V_154;
}
V_175 = F_138 ( V_141 , 0 ) ;
if ( V_175 < 0 ) {
V_88 = V_175 ;
goto V_154;
}
V_105 = F_12 ( & V_141 -> V_9 , sizeof( * V_105 ) , V_27 ) ;
if ( ! V_105 ) {
V_88 = - V_28 ;
goto V_154;
}
V_213 = F_139 ( V_141 , V_217 , 0 ) ;
V_105 -> V_42 = F_140 ( & V_141 -> V_9 , V_213 ) ;
if ( F_141 ( V_105 -> V_42 ) ) {
V_88 = F_142 ( V_105 -> V_42 ) ;
goto V_154;
}
V_105 -> V_91 = (struct V_145 * )
F_75 ( V_218 , & V_141 -> V_9 ) -> V_30 ;
V_105 -> V_191 = V_175 ;
V_105 -> V_188 = V_214 ;
V_105 -> clock = F_143 ( & V_141 -> V_9 , NULL ) ;
if ( F_141 ( V_105 -> clock ) ) {
F_11 ( & V_141 -> V_9 , L_52 ) ;
goto V_154;
}
if ( F_144 ( V_105 -> clock ) )
goto V_219;
if ( F_145 ( V_105 -> clock ) ) {
F_11 ( & V_141 -> V_9 , L_53 ) ;
goto V_220;
}
V_105 -> V_107 = V_221 ;
V_107 = & V_105 -> V_107 ;
V_107 -> V_143 = V_20 ;
V_107 -> V_167 = F_9 ( & V_141 -> V_9 ) ;
V_107 -> V_9 = & V_141 -> V_9 ;
V_107 -> V_222 = V_223 ;
V_107 -> V_109 = V_214 * V_44 ;
if ( ! F_146 ( V_20 , L_54 , & V_156 ) ) {
if ( V_156 >= V_44 )
F_147 ( L_55 ,
V_214 , V_44 , V_44 ) ;
else
V_107 -> V_156 = V_156 ;
}
V_215 = F_12 ( & V_141 -> V_9 , sizeof( char * ) * V_107 -> V_156 ,
V_27 ) ;
if ( ! V_215 ) {
V_88 = - V_28 ;
goto V_220;
}
for ( V_6 = 0 ; V_6 < V_107 -> V_156 ; V_6 ++ )
V_215 [ V_6 ] = F_78 ( V_27 , L_38 , V_214 + 'A' , V_6 ) ;
V_107 -> V_215 = ( const char * const * ) V_215 ;
V_102 = & V_105 -> V_102 ;
V_102 -> V_4 = V_107 -> V_167 ;
V_102 -> V_110 = V_214 ;
V_102 -> V_224 = V_102 -> V_109 = V_102 -> V_110 * V_44 ;
V_102 -> V_10 = V_107 -> V_156 ;
V_102 -> V_108 = V_107 ;
V_88 = F_148 ( V_107 ) ;
if ( V_88 )
goto V_220;
V_41 [ V_214 ] = V_105 ;
V_192 = F_149 ( V_192 , V_214 + 1 ) ;
F_133 () ;
F_127 ( V_20 , V_105 ) ;
F_82 ( & V_141 -> V_9 , L_56 , V_105 -> V_42 ) ;
return 0 ;
V_220:
F_150 ( V_105 -> clock ) ;
V_219:
F_151 ( V_105 -> clock ) ;
V_154:
F_11 ( & V_141 -> V_9 , L_57 , V_88 , V_214 ) ;
return V_88 ;
}
static int T_5 F_152 ( void )
{
int V_88 ;
V_88 = F_153 ( & V_225 ) ;
if ( V_88 )
return V_88 ;
return F_153 ( & V_226 ) ;
}
static void T_6 F_154 ( void )
{
F_155 ( & V_226 ) ;
}
