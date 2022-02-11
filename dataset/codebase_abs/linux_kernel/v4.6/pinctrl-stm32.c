static inline int F_1 ( int V_1 )
{
return V_1 % V_2 ;
}
static inline T_1 F_2 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return 2 ;
case V_5 :
return 3 ;
}
return 0 ;
}
static inline T_1 F_4 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return V_3 - 1 ;
case V_5 :
return 0 ;
}
return 0 ;
}
static inline void F_5 ( struct V_6 * V_7 ,
unsigned V_8 , int V_9 )
{
if ( ! V_9 )
V_8 += V_2 ;
F_6 ( V_7 -> V_10 ) ;
F_7 ( F_8 ( V_8 ) , V_7 -> V_11 + V_12 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_10 ( struct V_13 * V_14 , unsigned V_8 )
{
return F_11 ( V_14 -> V_11 + V_8 ) ;
}
static void F_12 ( struct V_13 * V_14 , unsigned V_8 )
{
F_13 ( V_14 -> V_11 + V_8 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned V_8 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
int V_15 ;
F_6 ( V_7 -> V_10 ) ;
V_15 = ! ! ( F_16 ( V_7 -> V_11 + V_16 ) & F_8 ( V_8 ) ) ;
F_9 ( V_7 -> V_10 ) ;
return V_15 ;
}
static void F_17 ( struct V_13 * V_14 , unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
}
static int F_18 ( struct V_13 * V_14 , unsigned V_8 )
{
return F_19 ( V_14 -> V_11 + V_8 ) ;
}
static int F_20 ( struct V_13 * V_14 ,
unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
F_21 ( V_14 -> V_11 + V_8 ) ;
return 0 ;
}
static struct V_17 *
F_22 ( struct V_18 * V_19 , T_1 V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_22 ; V_21 ++ ) {
struct V_17 * V_23 = V_19 -> V_24 + V_21 ;
if ( V_23 -> V_20 == V_20 )
return V_23 ;
}
return NULL ;
}
static bool F_23 ( struct V_18 * V_19 ,
T_1 V_25 , T_1 V_26 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_27 -> V_28 ; V_21 ++ ) {
const struct V_29 * V_20 = V_19 -> V_27 -> V_30 + V_21 ;
const struct V_31 * V_32 = V_20 -> V_33 ;
if ( V_20 -> V_20 . V_34 != V_25 )
continue;
while ( V_32 && V_32 -> V_35 ) {
if ( V_32 -> V_36 == V_26 )
return true ;
V_32 ++ ;
}
break;
}
return false ;
}
static int F_24 ( struct V_18 * V_19 ,
T_1 V_20 , T_1 V_26 , struct V_17 * V_23 ,
struct V_37 * * V_38 , unsigned * V_39 ,
unsigned * V_40 )
{
if ( * V_40 == * V_39 )
return - V_41 ;
( * V_38 ) [ * V_40 ] . type = V_42 ;
( * V_38 ) [ * V_40 ] . V_43 . V_44 . V_45 = V_23 -> V_35 ;
if ( ! F_23 ( V_19 , V_20 , V_26 ) ) {
F_25 ( V_19 -> V_46 , L_1 ,
V_26 , V_20 ) ;
return - V_47 ;
}
( * V_38 ) [ * V_40 ] . V_43 . V_44 . V_3 = V_48 [ V_26 ] ;
( * V_40 ) ++ ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_37 * * V_38 ,
unsigned * V_39 ,
unsigned * V_40 )
{
struct V_18 * V_19 ;
struct V_17 * V_23 ;
struct V_53 * V_30 ;
T_1 V_54 , V_20 , V_32 ;
unsigned long * V_55 ;
unsigned int V_56 ;
bool V_57 = 0 ;
unsigned V_58 = 0 ;
int V_59 , V_60 , V_61 , V_21 , V_62 ;
V_19 = F_27 ( V_50 ) ;
V_30 = F_28 ( V_52 , L_2 , NULL ) ;
if ( ! V_30 ) {
F_25 ( V_19 -> V_46 , L_3 ,
V_52 -> V_35 ) ;
return - V_47 ;
}
V_62 = F_29 ( V_52 , V_50 , & V_55 ,
& V_56 ) ;
if ( V_62 )
return V_62 ;
if ( V_56 )
V_57 = 1 ;
V_59 = V_30 -> V_63 / sizeof( T_1 ) ;
V_60 = V_59 ;
V_61 = 0 ;
if ( V_60 )
V_61 ++ ;
if ( V_57 && V_59 >= 1 )
V_61 ++ ;
if ( ! V_59 || ! V_61 )
return - V_47 ;
V_58 = V_59 * V_61 ;
V_62 = F_30 ( V_50 , V_38 ,
V_39 , V_40 , V_58 ) ;
if ( V_62 )
return V_62 ;
for ( V_21 = 0 ; V_21 < V_59 ; V_21 ++ ) {
V_62 = F_31 ( V_52 , L_2 ,
V_21 , & V_54 ) ;
if ( V_62 )
return V_62 ;
V_20 = F_32 ( V_54 ) ;
V_32 = F_33 ( V_54 ) ;
if ( V_20 >= V_19 -> V_27 -> V_28 ) {
F_25 ( V_19 -> V_46 , L_4 ) ;
return - V_47 ;
}
if ( ! F_23 ( V_19 , V_20 , V_32 ) ) {
F_25 ( V_19 -> V_46 , L_5 ) ;
return - V_47 ;
}
V_23 = F_22 ( V_19 , V_20 ) ;
if ( ! V_23 ) {
F_25 ( V_19 -> V_46 , L_6 ,
V_20 ) ;
return - V_47 ;
}
V_62 = F_24 ( V_19 , V_20 , V_32 , V_23 , V_38 ,
V_39 , V_40 ) ;
if ( V_62 )
return V_62 ;
if ( V_57 ) {
V_62 = F_34 ( V_50 , V_38 ,
V_39 , V_40 , V_23 -> V_35 ,
V_55 , V_56 ,
V_64 ) ;
if ( V_62 )
return V_62 ;
}
}
return 0 ;
}
static int F_35 ( struct V_49 * V_50 ,
struct V_51 * V_65 ,
struct V_37 * * V_38 , unsigned * V_40 )
{
struct V_51 * V_66 ;
unsigned V_39 ;
int V_15 ;
* V_38 = NULL ;
* V_40 = 0 ;
V_39 = 0 ;
F_36 (np_config, np) {
V_15 = F_26 ( V_50 , V_66 , V_38 ,
& V_39 , V_40 ) ;
if ( V_15 < 0 ) {
F_37 ( V_50 , * V_38 , * V_40 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_38 ( struct V_49 * V_50 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
return V_19 -> V_22 ;
}
static const char * F_39 ( struct V_49 * V_50 ,
unsigned V_45 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
return V_19 -> V_24 [ V_45 ] . V_35 ;
}
static int F_40 ( struct V_49 * V_50 ,
unsigned V_45 ,
const unsigned * * V_30 ,
unsigned * V_59 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
* V_30 = ( unsigned * ) & V_19 -> V_24 [ V_45 ] . V_20 ;
* V_59 = 1 ;
return 0 ;
}
static int F_41 ( struct V_49 * V_50 )
{
return F_42 ( V_48 ) ;
}
static const char * F_43 ( struct V_49 * V_50 ,
unsigned V_67 )
{
return V_48 [ V_67 ] ;
}
static int F_44 ( struct V_49 * V_50 ,
unsigned V_3 ,
const char * const * * V_24 ,
unsigned * const V_68 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
* V_24 = V_19 -> V_69 ;
* V_68 = V_19 -> V_22 ;
return 0 ;
}
static void F_45 ( struct V_6 * V_7 ,
int V_20 , T_1 V_70 , T_1 V_71 )
{
T_1 V_72 ;
int V_73 = ( V_20 % 8 ) * 4 ;
int V_74 = V_75 + ( V_20 / 8 ) * 4 ;
unsigned long V_76 ;
F_6 ( V_7 -> V_10 ) ;
F_46 ( & V_7 -> V_77 , V_76 ) ;
V_72 = F_16 ( V_7 -> V_11 + V_74 ) ;
V_72 &= ~ F_47 ( V_73 + 3 , V_73 ) ;
V_72 |= ( V_71 << V_73 ) ;
F_7 ( V_72 , V_7 -> V_11 + V_74 ) ;
V_72 = F_16 ( V_7 -> V_11 + V_78 ) ;
V_72 &= ~ F_47 ( V_20 * 2 + 1 , V_20 * 2 ) ;
V_72 |= V_70 << ( V_20 * 2 ) ;
F_7 ( V_72 , V_7 -> V_11 + V_78 ) ;
F_48 ( & V_7 -> V_77 , V_76 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_49 ( struct V_49 * V_50 ,
unsigned V_3 ,
unsigned V_45 )
{
bool V_15 ;
struct V_18 * V_19 = F_27 ( V_50 ) ;
struct V_17 * V_79 = V_19 -> V_24 + V_45 ;
struct V_80 * V_81 ;
struct V_6 * V_7 ;
T_1 V_70 , V_71 ;
int V_20 ;
V_15 = F_23 ( V_19 , V_79 -> V_20 , V_3 ) ;
if ( ! V_15 ) {
F_25 ( V_19 -> V_46 , L_7 ,
V_3 , V_45 ) ;
return - V_47 ;
}
V_81 = F_50 ( V_50 , V_79 -> V_20 ) ;
V_7 = F_51 ( V_81 ) ;
V_20 = F_1 ( V_79 -> V_20 ) ;
V_70 = F_2 ( V_3 ) ;
V_71 = F_4 ( V_3 ) ;
F_45 ( V_7 , V_20 , V_70 , V_71 ) ;
return 0 ;
}
static int F_52 ( struct V_49 * V_50 ,
struct V_80 * V_81 , unsigned V_1 ,
bool V_82 )
{
struct V_6 * V_7 = F_51 ( V_81 ) ;
int V_20 = F_1 ( V_1 ) ;
F_45 ( V_7 , V_20 , ! V_82 , 0 ) ;
return 0 ;
}
static void F_53 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_83 )
{
unsigned long V_76 ;
T_1 V_72 ;
F_6 ( V_7 -> V_10 ) ;
F_46 ( & V_7 -> V_77 , V_76 ) ;
V_72 = F_16 ( V_7 -> V_11 + V_84 ) ;
V_72 &= ~ F_8 ( V_8 ) ;
V_72 |= V_83 << V_8 ;
F_7 ( V_72 , V_7 -> V_11 + V_84 ) ;
F_48 ( & V_7 -> V_77 , V_76 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static void F_54 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_85 )
{
unsigned long V_76 ;
T_1 V_72 ;
F_6 ( V_7 -> V_10 ) ;
F_46 ( & V_7 -> V_77 , V_76 ) ;
V_72 = F_16 ( V_7 -> V_11 + V_86 ) ;
V_72 &= ~ F_47 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_72 |= V_85 << ( V_8 * 2 ) ;
F_7 ( V_72 , V_7 -> V_11 + V_86 ) ;
F_48 ( & V_7 -> V_77 , V_76 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static void F_55 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_87 )
{
unsigned long V_76 ;
T_1 V_72 ;
F_6 ( V_7 -> V_10 ) ;
F_46 ( & V_7 -> V_77 , V_76 ) ;
V_72 = F_16 ( V_7 -> V_11 + V_88 ) ;
V_72 &= ~ F_47 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_72 |= V_87 << ( V_8 * 2 ) ;
F_7 ( V_72 , V_7 -> V_11 + V_88 ) ;
F_48 ( & V_7 -> V_77 , V_76 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_56 ( struct V_49 * V_50 ,
unsigned int V_20 , enum V_89 V_90 ,
enum V_89 V_91 )
{
struct V_80 * V_81 ;
struct V_6 * V_7 ;
int V_8 , V_15 = 0 ;
V_81 = F_50 ( V_50 , V_20 ) ;
V_7 = F_51 ( V_81 ) ;
V_8 = F_1 ( V_20 ) ;
switch ( V_90 ) {
case V_92 :
F_53 ( V_7 , V_8 , 0 ) ;
break;
case V_93 :
F_53 ( V_7 , V_8 , 1 ) ;
break;
case V_94 :
F_54 ( V_7 , V_8 , V_91 ) ;
break;
case V_95 :
F_55 ( V_7 , V_8 , 0 ) ;
break;
case V_96 :
F_55 ( V_7 , V_8 , 1 ) ;
break;
case V_97 :
F_55 ( V_7 , V_8 , 2 ) ;
break;
case V_98 :
F_5 ( V_7 , V_8 , V_91 ) ;
V_15 = F_52 ( V_50 , NULL , V_20 , false ) ;
break;
default:
V_15 = - V_47 ;
}
return V_15 ;
}
static int F_57 ( struct V_49 * V_50 ,
unsigned V_45 ,
unsigned long * V_99 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
* V_99 = V_19 -> V_24 [ V_45 ] . V_99 ;
return 0 ;
}
static int F_58 ( struct V_49 * V_50 , unsigned V_45 ,
unsigned long * V_55 , unsigned V_56 )
{
struct V_18 * V_19 = F_27 ( V_50 ) ;
struct V_17 * V_79 = & V_19 -> V_24 [ V_45 ] ;
int V_21 , V_15 ;
for ( V_21 = 0 ; V_21 < V_56 ; V_21 ++ ) {
V_15 = F_56 ( V_50 , V_79 -> V_20 ,
F_59 ( V_55 [ V_21 ] ) ,
F_60 ( V_55 [ V_21 ] ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_79 -> V_99 = V_55 [ V_21 ] ;
}
return 0 ;
}
static int F_61 ( struct V_18 * V_19 ,
struct V_51 * V_66 )
{
int V_100 = V_19 -> V_101 ;
struct V_6 * V_7 = & V_19 -> V_102 [ V_100 ] ;
struct V_80 * V_81 = & V_7 -> V_81 ;
struct V_103 * V_46 = V_19 -> V_46 ;
struct V_104 V_105 ;
struct V_106 * V_107 ;
int V_62 , V_28 ;
V_107 = F_62 ( V_66 , NULL ) ;
if ( ! F_63 ( V_107 ) )
F_64 ( V_107 ) ;
if ( F_65 ( V_66 , 0 , & V_105 ) )
return - V_108 ;
V_7 -> V_11 = F_66 ( V_46 , & V_105 ) ;
if ( F_63 ( V_7 -> V_11 ) )
return F_67 ( V_7 -> V_11 ) ;
V_7 -> V_10 = F_68 ( V_66 , NULL ) ;
if ( F_63 ( V_7 -> V_10 ) ) {
F_25 ( V_46 , L_8 , F_67 ( V_7 -> V_10 ) ) ;
return F_67 ( V_7 -> V_10 ) ;
}
V_62 = F_69 ( V_7 -> V_10 ) ;
if ( V_62 ) {
F_25 ( V_46 , L_9 , V_62 ) ;
return V_62 ;
}
V_28 = V_19 -> V_27 -> V_28 ;
V_28 -= V_100 * V_2 ;
if ( V_28 < 0 )
return - V_47 ;
else if ( V_28 > V_2 )
V_28 = V_2 ;
V_7 -> V_13 = V_109 ;
V_7 -> V_13 . V_11 = V_100 * V_2 ;
V_7 -> V_13 . V_110 = V_28 ;
V_7 -> V_13 . V_111 = V_66 ;
V_7 -> V_13 . V_112 = V_46 ;
F_70 ( & V_7 -> V_77 ) ;
F_71 ( V_66 , L_10 , & V_81 -> V_35 ) ;
V_7 -> V_13 . V_113 = V_81 -> V_35 ;
V_81 -> V_114 = V_100 ;
V_81 -> V_115 = V_81 -> V_11 = V_81 -> V_114 * V_2 ;
V_81 -> V_28 = V_7 -> V_13 . V_110 ;
V_81 -> V_116 = & V_7 -> V_13 ;
V_62 = F_72 ( & V_7 -> V_13 , V_7 ) ;
if ( V_62 ) {
F_25 ( V_46 , L_11 , V_100 ) ;
return V_62 ;
}
F_73 ( V_46 , L_12 , V_81 -> V_35 ) ;
return 0 ;
}
static int F_74 ( struct V_117 * V_118 )
{
struct V_18 * V_19 = F_75 ( V_118 ) ;
int V_21 ;
V_19 -> V_22 = V_19 -> V_27 -> V_28 ;
V_19 -> V_24 = F_76 ( & V_118 -> V_46 , V_19 -> V_22 ,
sizeof( * V_19 -> V_24 ) , V_119 ) ;
if ( ! V_19 -> V_24 )
return - V_120 ;
V_19 -> V_69 = F_76 ( & V_118 -> V_46 , V_19 -> V_22 ,
sizeof( * V_19 -> V_69 ) , V_119 ) ;
if ( ! V_19 -> V_69 )
return - V_120 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_27 -> V_28 ; V_21 ++ ) {
const struct V_29 * V_20 = V_19 -> V_27 -> V_30 + V_21 ;
struct V_17 * V_45 = V_19 -> V_24 + V_21 ;
V_45 -> V_35 = V_20 -> V_20 . V_35 ;
V_45 -> V_20 = V_20 -> V_20 . V_34 ;
V_19 -> V_69 [ V_21 ] = V_20 -> V_20 . V_35 ;
}
return 0 ;
}
int F_77 ( struct V_117 * V_118 )
{
struct V_51 * V_66 = V_118 -> V_46 . V_111 ;
struct V_51 * V_121 ;
const struct V_122 * V_123 ;
struct V_103 * V_46 = & V_118 -> V_46 ;
struct V_18 * V_19 ;
struct V_124 * V_30 ;
int V_21 , V_15 , V_102 = 0 ;
if ( ! V_66 )
return - V_47 ;
V_123 = F_78 ( V_46 -> V_125 -> V_126 , V_46 ) ;
if ( ! V_123 || ! V_123 -> V_43 )
return - V_47 ;
if ( ! F_28 ( V_66 , L_13 , NULL ) ) {
F_25 ( V_46 , L_14 ) ;
return - V_47 ;
}
V_19 = F_79 ( V_46 , sizeof( * V_19 ) , V_119 ) ;
if ( ! V_19 )
return - V_120 ;
F_80 ( V_118 , V_19 ) ;
V_19 -> V_46 = V_46 ;
V_19 -> V_27 = V_123 -> V_43 ;
V_15 = F_74 ( V_118 ) ;
if ( V_15 ) {
F_25 ( V_46 , L_15 , V_15 ) ;
return - V_47 ;
}
F_36 (np, child)
if ( F_81 ( V_121 , L_16 ) )
V_102 ++ ;
if ( ! V_102 ) {
F_25 ( V_46 , L_17 ) ;
return - V_47 ;
}
V_19 -> V_102 = F_76 ( V_46 , V_102 , sizeof( * V_19 -> V_102 ) ,
V_119 ) ;
if ( ! V_19 -> V_102 )
return - V_120 ;
F_36 (np, child) {
if ( F_81 ( V_121 , L_16 ) ) {
V_15 = F_61 ( V_19 , V_121 ) ;
if ( V_15 )
return V_15 ;
V_19 -> V_101 ++ ;
}
}
V_30 = F_76 ( & V_118 -> V_46 , V_19 -> V_27 -> V_28 , sizeof( * V_30 ) ,
V_119 ) ;
if ( ! V_30 )
return - V_120 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_27 -> V_28 ; V_21 ++ )
V_30 [ V_21 ] = V_19 -> V_27 -> V_30 [ V_21 ] . V_20 ;
V_19 -> V_127 . V_35 = F_82 ( & V_118 -> V_46 ) ;
V_19 -> V_127 . V_128 = V_129 ;
V_19 -> V_127 . V_30 = V_30 ;
V_19 -> V_127 . V_28 = V_19 -> V_27 -> V_28 ;
V_19 -> V_127 . V_130 = & V_131 ;
V_19 -> V_127 . V_132 = & V_133 ;
V_19 -> V_127 . V_134 = & V_135 ;
V_19 -> V_46 = & V_118 -> V_46 ;
V_19 -> V_136 = F_83 ( & V_19 -> V_127 , & V_118 -> V_46 , V_19 ) ;
if ( ! V_19 -> V_136 ) {
F_25 ( & V_118 -> V_46 , L_18 ) ;
return - V_47 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_101 ; V_21 ++ )
F_84 ( V_19 -> V_136 , & V_19 -> V_102 [ V_21 ] . V_81 ) ;
F_73 ( V_46 , L_19 ) ;
return 0 ;
}
