static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned V_5 , bool * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = V_5 % 8 ;
T_1 V_9 ;
int V_10 ;
V_4 += V_5 / 8 ;
V_10 = F_4 ( V_7 -> V_11 ,
V_12 , V_4 , & V_9 ) ;
* V_6 = ! ! ( V_9 & F_5 ( V_8 ) ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 ,
L_1 ,
V_13 , V_4 , V_5 , V_10 ) ;
return V_10 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned V_5 , int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = V_5 % 8 ;
int V_10 ;
V_4 += V_5 / 8 ;
V_10 = F_8 ( V_7 -> V_11 ,
V_12 , V_4 , F_5 ( V_8 ) , V_9 << V_8 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_2 ,
V_13 , V_4 , V_5 , V_10 ) ;
return V_10 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_6 ;
bool V_14 ;
T_1 V_15 = V_5 - 1 ;
int V_10 ;
V_10 = F_3 ( V_3 , V_16 ,
V_15 , & V_14 ) ;
if ( V_10 < 0 )
goto V_17;
if ( V_14 )
V_10 = F_3 ( V_3 , V_18 ,
V_15 , & V_6 ) ;
else
V_10 = F_3 ( V_3 , V_19 ,
V_15 , & V_6 ) ;
V_17:
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
return V_6 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_5 , int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_10 ;
V_10 = F_7 ( V_3 , V_18 , V_5 , V_9 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_4 , V_13 , V_10 ) ;
}
static int F_11 ( struct V_1 * V_7 , int V_5 ,
enum V_20 * V_21 )
{
T_1 V_8 ;
T_1 V_9 ;
int V_10 ;
struct V_22 * V_22 ;
if ( ! V_7 -> V_23 -> V_22 ) {
F_6 ( V_7 -> V_11 , L_5 ,
V_13 ) ;
V_10 = - V_24 ;
goto V_17;
}
V_22 = V_7 -> V_23 -> V_22 ;
if ( ( V_5 < V_22 -> V_25 )
|| ( V_5 > V_22 -> V_26 ) ) {
V_10 = - V_27 ;
goto V_17;
}
V_10 = F_4 ( V_7 -> V_11 ,
V_12 , V_28 , & V_9 ) ;
V_8 = ( V_5 - V_22 -> V_25 ) << 1 ;
* V_21 = ( V_9 >> V_8 ) & V_29 ;
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_7 ,
int V_5 , enum V_20 V_9 )
{
T_1 V_8 ;
int V_10 ;
struct V_22 * V_22 ;
if ( ! V_7 -> V_23 -> V_22 ) {
F_6 ( V_7 -> V_11 , L_5 ,
V_13 ) ;
V_10 = - V_24 ;
goto V_17;
}
V_22 = V_7 -> V_23 -> V_22 ;
if ( ( V_5 < V_22 -> V_25 )
|| ( V_5 > V_22 -> V_26 ) ) {
V_10 = - V_27 ;
goto V_17;
}
V_8 = ( V_5 - V_22 -> V_25 ) << 1 ;
V_10 = F_8 ( V_7 -> V_11 ,
V_12 , V_28 ,
V_29 << V_8 , V_9 << V_8 ) ;
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static bool F_13 ( struct V_2 * V_3 , unsigned V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_22 * V_22 = V_7 -> V_23 -> V_22 ;
return ( V_22 &&
V_30 >= V_22 -> V_25 &&
V_30 <= V_22 -> V_26 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned V_5 ,
int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned V_30 ;
int V_10 ;
V_10 = F_7 ( V_3 ,
V_16 ,
V_5 ,
V_31 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_7 ( V_3 ,
V_32 ,
V_5 ,
V_33 ) ;
if ( V_10 < 0 )
goto V_17;
V_30 = V_5 + 1 ;
if ( F_13 ( V_3 , V_30 ) ) {
V_10 = F_12 ( V_7 ,
V_30 ,
V_33 ) ;
}
V_17:
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
return F_7 ( V_3 , V_18 , V_5 , V_9 ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_5 )
{
return F_7 ( V_3 ,
V_16 ,
V_5 ,
V_34 ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_30 = V_5 + 1 ;
int V_35 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_37 ; V_36 ++ ) {
struct V_38 * V_39 =
& V_7 -> V_40 [ V_36 ] ;
if ( V_30 >= V_39 -> V_41 && V_30 <= V_39 -> V_42 ) {
V_35 = V_30 - V_39 -> V_41 + V_39 -> V_43 ;
return F_17 ( V_7 -> V_44 -> V_45 , V_35 ) ;
}
}
return - V_27 ;
}
static int F_18 ( struct V_46 * V_47 , struct V_2 * V_3 ,
unsigned V_30 , int V_48 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_49 V_50 = V_7 -> V_23 -> V_49 [ V_30 ] ;
int V_10 ;
int V_9 ;
unsigned V_5 ;
const char * V_51 [] = {
[ V_52 ] = L_6 ,
[ V_53 ] = L_7 ,
[ V_54 ] = L_8 ,
[ V_55 ] = L_9 ,
} ;
if ( ( ( V_48 == V_53 ) && ( V_50 . V_56 == V_57 ) ) ||
( ( V_48 == V_54 ) && ( V_50 . V_58 == V_57 ) ) ||
( ( V_48 == V_55 ) && ( V_50 . V_59 == V_57 ) ) ) {
F_20 ( V_7 -> V_11 , L_10 , V_30 ,
V_51 [ V_48 ] ) ;
return - V_27 ;
}
V_5 = V_30 - 1 ;
switch ( V_48 ) {
case V_52 :
V_9 = 0 ;
if ( V_50 . V_58 != V_57 )
V_9 ++ ;
V_10 = F_7 ( V_3 , V_60 ,
V_5 , V_9 ) ;
break;
case V_53 :
if ( V_50 . V_58 != V_57 ) {
V_10 = F_7 ( V_3 , V_60 ,
V_5 , 0 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_7 ( V_3 ,
V_61 ,
V_50 . V_58 ,
! ! ( V_50 . V_62 & F_5 ( 0 ) ) ) ;
if ( V_10 < 0 )
goto V_17;
if ( V_50 . V_59 != V_57 )
V_10 = F_7 ( V_3 ,
V_61 ,
V_50 . V_59 ,
! ! ( V_50 . V_62 & F_5 ( 1 ) ) ) ;
} else
V_10 = F_7 ( V_3 , V_60 ,
V_5 , 1 ) ;
break;
case V_54 :
V_10 = F_7 ( V_3 , V_60 ,
V_5 , 0 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_7 ( V_3 , V_61 ,
V_50 . V_58 , ! ! ( V_50 . V_63 & F_5 ( 0 ) ) ) ;
if ( V_10 < 0 )
goto V_17;
if ( V_50 . V_59 != V_57 )
V_10 = F_7 ( V_3 ,
V_61 ,
V_50 . V_59 ,
! ! ( V_50 . V_63 & F_5 ( 1 ) ) ) ;
break;
case V_55 :
V_10 = F_7 ( V_3 , V_60 ,
V_5 , 0 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_7 ( V_3 , V_61 ,
V_50 . V_59 , ! ! ( V_50 . V_64 & F_5 ( 0 ) ) ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_7 ( V_3 , V_61 ,
V_50 . V_59 , ! ! ( V_50 . V_64 & F_5 ( 1 ) ) ) ;
break;
default:
F_20 ( V_7 -> V_11 , L_11 , V_48 ) ;
return - V_27 ;
}
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_21 ( struct V_46 * V_47 , struct V_2 * V_3 ,
unsigned V_30 )
{
T_1 V_65 ;
bool V_66 ;
bool V_58 ;
bool V_59 ;
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_49 V_50 = V_7 -> V_23 -> V_49 [ V_30 ] ;
unsigned V_5 = V_30 - 1 ;
int V_10 ;
if ( V_50 . V_56 == V_57 )
return V_52 ;
V_10 = F_3 ( V_3 , V_60 + ( V_5 / 8 ) ,
V_50 . V_56 , & V_66 ) ;
if ( V_10 < 0 )
goto V_17;
V_65 = V_66 ;
if ( ( V_50 . V_58 < V_57 ) || ( V_50 . V_58 > 7 ) ||
( V_50 . V_59 < V_57 ) || ( V_50 . V_59 > 7 ) ) {
F_6 ( V_7 -> V_11 ,
L_12 ) ;
return - V_27 ;
}
if ( ( V_50 . V_59 != V_57 ) && ( V_50 . V_58 == V_57 ) ) {
F_6 ( V_7 -> V_11 ,
L_13 ) ;
return - V_27 ;
}
if ( ( V_50 . V_58 == V_57 ) && ( V_50 . V_59 == V_57 ) )
return V_65 ;
if ( V_65 )
return V_52 ;
V_10 = F_3 ( V_3 , V_61 ,
V_50 . V_58 , & V_58 ) ;
if ( V_10 < 0 )
goto V_17;
if ( V_50 . V_59 != V_57 ) {
V_10 = F_3 ( V_3 , V_61 ,
V_50 . V_59 ,
& V_59 ) ;
if ( V_10 < 0 )
goto V_17;
} else
V_59 = 0 ;
V_65 = ( V_59 << 1 ) + V_58 ;
if ( V_65 == V_50 . V_62 )
return V_53 ;
else if ( V_65 == V_50 . V_63 )
return V_54 ;
else
return V_55 ;
V_17:
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static void F_22 ( struct V_67 * V_68 ,
struct V_46 * V_47 ,
struct V_2 * V_3 ,
unsigned V_5 , unsigned V_30 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
const char * V_69 = F_23 ( V_3 , V_5 - 1 ) ;
T_1 V_15 = V_5 - 1 ;
int V_65 = - 1 ;
bool V_14 ;
bool V_70 ;
enum V_20 V_71 = 0 ;
int V_10 ;
const char * V_51 [] = {
[ V_52 ] = L_6 ,
[ V_53 ] = L_7 ,
[ V_54 ] = L_8 ,
[ V_55 ] = L_9 ,
} ;
const char * V_72 [] = {
[ V_73 ] = L_14 ,
[ V_33 ] = L_15 ,
[ V_33 + 1 ] = L_15 ,
[ V_74 ] = L_16 ,
} ;
V_10 = F_3 ( V_3 , V_16 ,
V_15 , & V_14 ) ;
if ( V_10 < 0 )
goto V_17;
F_24 ( V_68 , L_17 ,
V_30 , V_69 ? : L_18 ,
V_14 ? L_19 : L_20 ) ;
if ( ! V_14 ) {
if ( F_13 ( V_3 , V_5 ) ) {
V_10 = F_11 ( V_7 , V_5 , & V_71 ) ;
if ( V_10 < 0 )
goto V_17;
F_24 ( V_68 , L_21 , V_72 [ V_71 ] ) ;
} else {
V_10 = F_3 ( V_3 , V_32 ,
V_15 , & V_70 ) ;
if ( V_10 < 0 )
goto V_17;
F_24 ( V_68 , L_21 , V_72 [ V_70 ] ) ;
}
} else
F_24 ( V_68 , L_21 , V_3 -> V_75 ( V_3 , V_5 ) ? L_22 : L_23 ) ;
V_65 = F_21 ( V_47 , V_3 , V_5 ) ;
F_24 ( V_68 , L_24 , ( V_65 < 0 ) ? L_25 : V_51 [ V_65 ] ) ;
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
}
static void F_25 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
unsigned V_36 ;
unsigned V_30 = V_3 -> V_76 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_46 * V_47 = V_7 -> V_47 ;
for ( V_36 = 0 ; V_36 < V_3 -> V_77 ; V_36 ++ , V_30 ++ ) {
F_22 ( V_68 , V_47 , V_3 , V_36 + 1 , V_30 ) ;
F_24 ( V_68 , L_26 ) ;
}
}
static inline void F_22 ( struct V_67 * V_68 ,
struct V_46 * V_47 ,
struct V_2 * V_3 ,
unsigned V_5 , unsigned V_30 )
{
}
static int F_26 ( struct V_2 * V_3 , unsigned V_5 )
{
int V_30 = V_3 -> V_76 + V_5 ;
return F_27 ( V_30 ) ;
}
static void F_28 ( struct V_2 * V_3 , unsigned V_5 )
{
int V_30 = V_3 -> V_76 + V_5 ;
F_29 ( V_30 ) ;
}
static int F_30 ( struct V_46 * V_47 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_78 ;
}
static const char * F_31 ( struct V_46 * V_47 ,
unsigned V_79 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_80 [ V_79 ] . V_81 ;
}
static int F_32 ( struct V_46 * V_47 ,
unsigned V_79 ,
const char * const * * V_82 ,
unsigned * const V_83 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
* V_82 = V_7 -> V_23 -> V_80 [ V_79 ] . V_82 ;
* V_83 = V_7 -> V_23 -> V_80 [ V_79 ] . V_84 ;
return 0 ;
}
static int F_33 ( struct V_46 * V_47 , unsigned V_79 ,
unsigned V_85 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
const struct V_86 * V_87 ;
int V_36 ;
int V_10 = 0 ;
V_87 = & V_7 -> V_23 -> V_82 [ V_85 ] ;
if ( V_87 -> V_88 < 0 )
return - V_27 ;
F_20 ( V_7 -> V_11 , L_27 , V_87 -> V_81 , V_87 -> V_89 ) ;
for ( V_36 = 0 ; V_36 < V_87 -> V_89 ; V_36 ++ ) {
F_20 ( V_7 -> V_11 , L_28 ,
V_87 -> V_90 [ V_36 ] , V_87 -> V_88 ) ;
V_10 = F_18 ( V_47 , V_3 , V_87 -> V_90 [ V_36 ] , V_87 -> V_88 ) ;
}
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_34 ( struct V_46 * V_47 ,
struct V_91 * V_92 ,
unsigned V_5 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
const struct V_93 * V_94 ;
int V_10 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_23 -> V_95 ; V_36 ++ ) {
V_94 = & V_7 -> V_23 -> V_96 [ V_36 ] ;
if ( ( V_5 >= V_94 -> V_5 ) &&
( V_5 < ( V_94 -> V_5 + V_94 -> V_89 ) ) )
break;
}
if ( V_36 == V_7 -> V_23 -> V_95 ) {
F_6 ( V_7 -> V_11 , L_29 , V_13 ) ;
return - V_97 ;
}
F_20 ( V_7 -> V_11 , L_30 ,
V_94 -> V_98 , V_5 ) ;
V_10 = F_18 ( V_7 -> V_47 , & V_7 -> V_3 ,
V_5 , V_94 -> V_98 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_31 , V_13 ) ;
return V_10 ;
}
static void F_35 ( struct V_46 * V_47 ,
struct V_91 * V_92 ,
unsigned V_5 )
{
}
static int F_36 ( struct V_46 * V_47 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_84 ;
}
static const char * F_37 ( struct V_46 * V_47 ,
unsigned V_99 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_82 [ V_99 ] . V_81 ;
}
static int F_38 ( struct V_46 * V_47 ,
unsigned V_99 ,
const unsigned * * V_90 ,
unsigned * V_100 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
* V_90 = V_7 -> V_23 -> V_82 [ V_99 ] . V_90 ;
* V_100 = V_7 -> V_23 -> V_82 [ V_99 ] . V_89 ;
return 0 ;
}
static void F_39 ( struct V_46 * V_47 ,
struct V_67 * V_68 , unsigned V_5 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_22 ( V_68 , V_47 , V_3 , V_5 ,
V_3 -> V_76 + V_5 - 1 ) ;
}
static int F_40 ( struct V_101 * * V_102 ,
unsigned * V_103 ,
unsigned * V_104 , const char * V_85 ,
const char * V_79 )
{
if ( * V_104 == * V_103 )
return - V_105 ;
( * V_102 ) [ * V_104 ] . type = V_106 ;
( * V_102 ) [ * V_104 ] . V_107 . V_108 . V_85 = V_85 ;
( * V_102 ) [ * V_104 ] . V_107 . V_108 . V_79 = V_79 ;
( * V_104 ) ++ ;
return 0 ;
}
static int F_41 ( struct V_101 * * V_102 ,
unsigned * V_103 ,
unsigned * V_104 , const char * V_85 ,
unsigned long * V_109 , unsigned V_110 )
{
unsigned long * V_111 ;
if ( * V_104 == * V_103 )
return - V_105 ;
V_111 = F_42 ( V_109 , V_110 * sizeof( * V_111 ) ,
V_112 ) ;
if ( ! V_111 )
return - V_113 ;
( * V_102 ) [ * V_104 ] . type = V_114 ;
( * V_102 ) [ * V_104 ] . V_107 . V_109 . V_115 = V_85 ;
( * V_102 ) [ * V_104 ] . V_107 . V_109 . V_109 = V_111 ;
( * V_102 ) [ * V_104 ] . V_107 . V_109 . V_110 = V_110 ;
( * V_104 ) ++ ;
return 0 ;
}
static const char * F_43 ( struct V_46 * V_47 ,
const char * V_116 )
{
int V_36 , V_117 ;
struct V_1 * V_118 = F_19 ( V_47 ) ;
if ( sscanf ( ( char * ) V_116 , L_32 , & V_117 ) == 1 )
for ( V_36 = 0 ; V_36 < V_118 -> V_23 -> V_89 ; V_36 ++ )
if ( V_118 -> V_23 -> V_90 [ V_36 ] . V_119 == V_117 )
return V_118 -> V_23 -> V_90 [ V_36 ] . V_81 ;
return NULL ;
}
static int F_44 ( struct V_46 * V_47 ,
struct V_120 * V_121 ,
struct V_101 * * V_102 ,
unsigned * V_103 ,
unsigned * V_104 )
{
int V_10 ;
const char * V_79 = NULL ;
unsigned long * V_109 ;
unsigned int V_122 = 0 ;
struct V_123 * V_124 ;
V_10 = F_45 ( V_121 , L_33 , & V_79 ) ;
if ( V_10 >= 0 ) {
const char * V_85 ;
V_10 = F_46 ( V_121 , L_34 ) ;
if ( V_10 < 0 )
goto exit;
V_10 = F_47 ( V_47 , V_102 , V_103 ,
V_104 , V_10 ) ;
if ( V_10 < 0 )
goto exit;
F_48 (np, L_34 , prop, group) {
V_10 = F_40 ( V_102 , V_103 ,
V_104 , V_85 , V_79 ) ;
if ( V_10 < 0 )
goto exit;
}
}
V_10 = F_49 ( V_121 , & V_109 , & V_122 ) ;
if ( V_122 ) {
const char * V_125 ;
const char * V_126 ;
V_10 = F_46 ( V_121 , L_35 ) ;
if ( V_10 < 0 )
goto exit;
V_10 = F_47 ( V_47 , V_102 ,
V_103 ,
V_104 , V_10 ) ;
if ( V_10 < 0 )
goto exit;
F_48 (np, L_35 , prop, pin) {
V_125 = F_43 ( V_47 , V_126 ) ;
V_10 = F_41 ( V_102 , V_103 ,
V_104 , V_125 , V_109 , 1 ) ;
if ( V_10 < 0 )
goto exit;
}
}
exit:
return V_10 ;
}
static int F_50 ( struct V_46 * V_47 ,
struct V_120 * V_127 ,
struct V_101 * * V_102 , unsigned * V_104 )
{
unsigned V_103 ;
struct V_120 * V_121 ;
int V_10 ;
V_103 = 0 ;
* V_102 = NULL ;
* V_104 = 0 ;
F_51 (np_config, np) {
V_10 = F_44 ( V_47 , V_121 , V_102 ,
& V_103 , V_104 ) ;
if ( V_10 < 0 ) {
F_52 ( V_47 , * V_102 , * V_104 ) ;
return V_10 ;
}
}
return 0 ;
}
static int F_53 ( struct V_46 * V_47 ,
unsigned V_126 ,
unsigned long * V_128 )
{
return - V_129 ;
}
static int F_54 ( struct V_46 * V_47 ,
unsigned V_126 ,
unsigned long * V_109 ,
unsigned V_110 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
unsigned V_5 ;
int V_10 = - V_27 ;
int V_36 ;
enum V_130 V_131 ;
enum V_130 V_132 ;
for ( V_36 = 0 ; V_36 < V_110 ; V_36 ++ ) {
V_131 = F_55 ( V_109 [ V_36 ] ) ;
V_132 = F_56 ( V_109 [ V_36 ] ) ;
F_20 ( V_3 -> V_11 , L_36 ,
V_126 , V_109 [ V_36 ] ,
( V_131 == V_133 ) ? L_37 : L_38 ,
( V_131 == V_133 ) ?
( V_132 ? L_39 : L_40 ) :
( V_132 ? L_16 : L_14 ) ) ;
V_5 = V_126 - 1 ;
switch ( V_131 ) {
case V_134 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
if ( F_13 ( V_3 , V_126 ) )
V_10 = F_12 ( V_7 ,
V_126 ,
V_33 ) ;
else
V_10 = F_7 ( V_3 ,
V_32 , V_5 ,
V_33 ) ;
break;
case V_135 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
if ( F_13 ( V_3 , V_126 ) )
V_10 = F_12 ( V_7 ,
V_126 ,
V_132 ? V_73 :
V_33 ) ;
else
V_10 = F_7 ( V_3 ,
V_32 ,
V_5 ,
V_132 ? V_73 :
V_33 ) ;
break;
case V_136 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_15 ( V_3 , V_5 ) ;
if ( F_13 ( V_3 , V_126 ) )
V_10 = F_12 ( V_7 ,
V_126 ,
V_132 ? V_74 :
V_33 ) ;
break;
case V_133 :
V_10 = F_14 ( V_3 , V_5 ,
V_132 ) ;
break;
default:
F_6 ( V_3 -> V_11 , L_41 ) ;
}
}
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_57 ( struct V_137 * V_23 )
{
unsigned int V_138 = 0 ;
unsigned int V_139 = 0 ;
unsigned int V_89 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_23 -> V_95 ; V_36 ++ ) {
unsigned V_140 ;
unsigned V_141 ;
const struct V_93 * V_94 ;
V_94 = & V_23 -> V_96 [ V_36 ] ;
V_140 = V_94 -> V_5 ;
V_141 = V_94 -> V_5 + V_94 -> V_89 - 1 ;
if ( V_36 == 0 ) {
V_138 = V_140 ;
V_139 = V_141 ;
} else {
if ( V_140 < V_138 )
V_138 = V_140 ;
if ( V_141 > V_139 )
V_139 = V_141 ;
}
}
V_89 = V_139 - V_138 + 1 ;
return V_89 ;
}
static int F_58 ( struct V_142 * V_143 )
{
struct V_120 * V_121 = V_143 -> V_11 . V_144 ;
const struct V_145 * V_146 ;
struct V_1 * V_7 ;
unsigned int V_147 = - 1 ;
int V_10 ;
int V_36 ;
if ( ! V_121 ) {
F_6 ( & V_143 -> V_11 , L_42 ) ;
return - V_97 ;
}
V_7 = F_59 ( & V_143 -> V_11 , sizeof( struct V_1 ) ,
V_112 ) ;
if ( V_7 == NULL ) {
F_6 ( & V_143 -> V_11 ,
L_43 ) ;
return - V_113 ;
}
V_7 -> V_11 = & V_143 -> V_11 ;
V_7 -> V_44 = F_60 ( V_143 -> V_11 . V_44 ) ;
V_7 -> V_3 = V_148 ;
V_7 -> V_3 . V_11 = & V_143 -> V_11 ;
V_7 -> V_3 . V_76 = - 1 ;
V_146 = F_61 ( V_149 , & V_143 -> V_11 ) ;
if ( ! V_146 ) {
F_6 ( & V_143 -> V_11 , L_44 ) ;
return - V_97 ;
}
V_147 = ( unsigned long ) V_146 -> V_107 ;
switch ( V_147 ) {
case V_150 :
F_62 ( & V_7 -> V_23 ) ;
break;
case V_151 :
F_63 ( & V_7 -> V_23 ) ;
break;
case V_152 :
F_64 ( & V_7 -> V_23 ) ;
break;
case V_153 :
F_65 ( & V_7 -> V_23 ) ;
break;
default:
F_6 ( & V_143 -> V_11 , L_45 , V_147 ) ;
return - V_27 ;
}
if ( ! V_7 -> V_23 ) {
F_6 ( & V_143 -> V_11 , L_46 ) ;
return - V_27 ;
}
V_7 -> V_3 . V_77 = F_57 ( V_7 -> V_23 ) ;
V_7 -> V_40 = V_7 -> V_23 -> V_154 ;
V_7 -> V_37 = V_7 -> V_23 -> V_155 ;
V_10 = F_66 ( & V_7 -> V_3 ) ;
if ( V_10 ) {
F_6 ( & V_143 -> V_11 , L_47 , V_10 ) ;
return V_10 ;
}
F_67 ( & V_143 -> V_11 , L_48 ) ;
V_156 . V_90 = V_7 -> V_23 -> V_90 ;
V_156 . V_89 = V_7 -> V_23 -> V_89 ;
V_7 -> V_47 = F_68 ( & V_156 , & V_143 -> V_11 , V_7 ) ;
if ( ! V_7 -> V_47 ) {
F_6 ( & V_143 -> V_11 ,
L_49 ) ;
V_10 = - V_27 ;
goto V_157;
}
F_67 ( & V_143 -> V_11 , L_50 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_23 -> V_95 ; V_36 ++ ) {
const struct V_93 * V_94 = & V_7 -> V_23 -> V_96 [ V_36 ] ;
V_10 = F_69 ( & V_7 -> V_3 ,
F_70 ( & V_143 -> V_11 ) ,
V_94 -> V_5 - 1 , V_94 -> V_5 , V_94 -> V_89 ) ;
if ( V_10 < 0 )
goto V_157;
}
F_71 ( V_143 , V_7 ) ;
F_67 ( & V_143 -> V_11 , L_51 ) ;
return 0 ;
V_157:
F_72 ( & V_7 -> V_3 ) ;
return V_10 ;
}
static int F_73 ( struct V_142 * V_143 )
{
struct V_1 * V_7 = F_74 ( V_143 ) ;
F_72 ( & V_7 -> V_3 ) ;
return 0 ;
}
static int T_2 F_75 ( void )
{
return F_76 ( & V_158 ) ;
}
