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
if ( V_47 )
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
static void F_34 ( struct V_46 * V_47 ,
unsigned V_79 , unsigned V_85 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
const struct V_86 * V_87 ;
V_87 = & V_7 -> V_23 -> V_82 [ V_85 ] ;
if ( V_87 -> V_88 < 0 )
return;
F_20 ( V_7 -> V_11 , L_29 , V_87 -> V_81 , V_87 -> V_89 ) ;
}
static int F_35 ( struct V_46 * V_47 ,
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
F_6 ( V_7 -> V_11 , L_30 , V_13 ) ;
return - V_97 ;
}
F_20 ( V_7 -> V_11 , L_31 ,
V_94 -> V_98 , V_5 ) ;
V_10 = F_18 ( V_7 -> V_47 , & V_7 -> V_3 ,
V_5 , V_94 -> V_98 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_32 , V_13 ) ;
return V_10 ;
}
static void F_36 ( struct V_46 * V_47 ,
struct V_91 * V_92 ,
unsigned V_5 )
{
}
static int F_37 ( struct V_46 * V_47 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_84 ;
}
static const char * F_38 ( struct V_46 * V_47 ,
unsigned V_99 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
return V_7 -> V_23 -> V_82 [ V_99 ] . V_81 ;
}
static int F_39 ( struct V_46 * V_47 ,
unsigned V_99 ,
const unsigned * * V_90 ,
unsigned * V_100 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
* V_90 = V_7 -> V_23 -> V_82 [ V_99 ] . V_90 ;
* V_100 = V_7 -> V_23 -> V_82 [ V_99 ] . V_89 ;
return 0 ;
}
static void F_40 ( struct V_46 * V_47 ,
struct V_67 * V_68 , unsigned V_5 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_22 ( V_68 , V_47 , V_3 , V_5 ,
V_3 -> V_76 + V_5 - 1 ) ;
}
static void F_41 ( struct V_46 * V_47 ,
struct V_101 * V_102 , unsigned V_103 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_103 ; V_36 ++ )
if ( V_102 [ V_36 ] . type == V_104 )
F_42 ( V_102 [ V_36 ] . V_105 . V_106 . V_106 ) ;
F_42 ( V_102 ) ;
}
static int F_43 ( struct V_101 * * V_102 ,
unsigned * V_107 ,
unsigned * V_103 ,
unsigned V_108 )
{
unsigned V_109 = * V_107 ;
unsigned V_110 = * V_103 + V_108 ;
struct V_101 * V_111 ;
if ( V_109 >= V_110 )
return 0 ;
V_111 = F_44 ( * V_102 , sizeof( * V_111 ) * V_110 , V_112 ) ;
if ( ! V_111 )
return - V_113 ;
memset ( V_111 + V_109 , 0 , ( V_110 - V_109 ) * sizeof( * V_111 ) ) ;
* V_102 = V_111 ;
* V_107 = V_110 ;
return 0 ;
}
static int F_45 ( struct V_101 * * V_102 ,
unsigned * V_107 ,
unsigned * V_103 , const char * V_85 ,
const char * V_79 )
{
if ( * V_103 == * V_107 )
return - V_114 ;
( * V_102 ) [ * V_103 ] . type = V_115 ;
( * V_102 ) [ * V_103 ] . V_105 . V_116 . V_85 = V_85 ;
( * V_102 ) [ * V_103 ] . V_105 . V_116 . V_79 = V_79 ;
( * V_103 ) ++ ;
return 0 ;
}
static int F_46 ( struct V_101 * * V_102 ,
unsigned * V_107 ,
unsigned * V_103 , const char * V_85 ,
unsigned long * V_106 , unsigned V_117 )
{
unsigned long * V_118 ;
if ( * V_103 == * V_107 )
return - V_114 ;
V_118 = F_47 ( V_106 , V_117 * sizeof( * V_118 ) ,
V_112 ) ;
if ( ! V_118 )
return - V_113 ;
( * V_102 ) [ * V_103 ] . type = V_104 ;
( * V_102 ) [ * V_103 ] . V_105 . V_106 . V_119 = V_85 ;
( * V_102 ) [ * V_103 ] . V_105 . V_106 . V_106 = V_118 ;
( * V_102 ) [ * V_103 ] . V_105 . V_106 . V_117 = V_117 ;
( * V_103 ) ++ ;
return 0 ;
}
static const char * F_48 ( struct V_46 * V_47 ,
const char * V_120 )
{
int V_36 , V_121 ;
struct V_1 * V_122 = F_19 ( V_47 ) ;
if ( sscanf ( ( char * ) V_120 , L_33 , & V_121 ) == 1 )
for ( V_36 = 0 ; V_36 < V_122 -> V_23 -> V_89 ; V_36 ++ )
if ( V_122 -> V_23 -> V_90 [ V_36 ] . V_123 == V_121 )
return V_122 -> V_23 -> V_90 [ V_36 ] . V_81 ;
return NULL ;
}
static int F_49 ( struct V_46 * V_47 ,
struct V_124 * V_125 ,
struct V_101 * * V_102 ,
unsigned * V_107 ,
unsigned * V_103 )
{
int V_10 ;
const char * V_79 = NULL ;
unsigned long * V_106 ;
unsigned int V_126 = 0 ;
bool V_127 = 0 ;
unsigned V_108 = 0 ;
struct V_128 * V_129 ;
const char * V_85 , * V_130 ;
struct V_124 * V_131 ;
V_10 = F_50 ( V_125 , L_34 , & V_79 ) ;
if ( V_10 >= 0 )
V_108 = 1 ;
V_10 = F_51 ( V_125 , & V_106 , & V_126 ) ;
if ( V_126 )
V_127 = 1 ;
V_131 = F_52 ( V_125 , L_35 , 0 ) ;
if ( V_131 ) {
V_10 = F_51 ( V_131 , & V_106 ,
& V_126 ) ;
if ( V_10 )
goto exit;
V_127 |= V_126 ;
}
V_10 = F_53 ( V_125 , L_36 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_127 )
V_108 ++ ;
V_108 *= V_10 ;
V_10 = F_43 ( V_102 , V_107 , V_103 , V_108 ) ;
if ( V_10 < 0 )
goto exit;
F_54 (np, L_36 , prop, group) {
if ( V_79 ) {
V_10 = F_45 ( V_102 , V_107 ,
V_103 , V_85 , V_79 ) ;
if ( V_10 < 0 )
goto exit;
}
if ( V_127 ) {
V_130 = F_48 ( V_47 , V_85 ) ;
V_10 = F_46 ( V_102 , V_107 ,
V_103 , V_130 , V_106 , 1 ) ;
if ( V_10 < 0 )
goto exit;
}
}
exit:
return V_10 ;
}
static int F_55 ( struct V_46 * V_47 ,
struct V_124 * V_131 ,
struct V_101 * * V_102 , unsigned * V_103 )
{
unsigned V_107 ;
struct V_124 * V_125 ;
int V_10 ;
V_107 = 0 ;
* V_102 = NULL ;
* V_103 = 0 ;
F_56 (np_config, np) {
V_10 = F_49 ( V_47 , V_125 , V_102 ,
& V_107 , V_103 ) ;
if ( V_10 < 0 ) {
F_41 ( V_47 , * V_102 , * V_103 ) ;
return V_10 ;
}
}
return 0 ;
}
static int F_57 ( struct V_46 * V_47 ,
unsigned V_132 ,
unsigned long * V_133 )
{
return - V_134 ;
}
static int F_58 ( struct V_46 * V_47 ,
unsigned V_132 ,
unsigned long * V_106 ,
unsigned V_117 )
{
struct V_1 * V_7 = F_19 ( V_47 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
unsigned V_5 ;
int V_10 = - V_27 ;
int V_36 ;
enum V_135 V_136 ;
enum V_135 V_137 ;
for ( V_36 = 0 ; V_36 < V_117 ; V_36 ++ ) {
V_136 = F_59 ( V_106 [ V_36 ] ) ;
V_137 = F_60 ( V_106 [ V_36 ] ) ;
F_20 ( V_3 -> V_11 , L_37 ,
V_132 , V_106 [ V_36 ] ,
( V_136 == V_138 ) ? L_38 : L_39 ,
( V_136 == V_138 ) ?
( V_137 ? L_40 : L_41 ) :
( V_137 ? L_16 : L_14 ) ) ;
V_5 = V_132 - 1 ;
switch ( V_136 ) {
case V_139 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
if ( F_13 ( V_3 , V_132 ) )
V_10 = F_12 ( V_7 ,
V_132 ,
V_33 ) ;
else
V_10 = F_7 ( V_3 ,
V_32 , V_5 ,
V_33 ) ;
break;
case V_140 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
if ( F_13 ( V_3 , V_132 ) )
V_10 = F_12 ( V_7 ,
V_132 ,
V_137 ? V_73 :
V_33 ) ;
else
V_10 = F_7 ( V_3 ,
V_32 ,
V_5 ,
V_137 ? V_73 :
V_33 ) ;
break;
case V_141 :
V_10 = F_15 ( V_3 , V_5 ) ;
if ( V_10 < 0 )
goto V_17;
V_10 = F_15 ( V_3 , V_5 ) ;
if ( F_13 ( V_3 , V_132 ) )
V_10 = F_12 ( V_7 ,
V_132 ,
V_137 ? V_74 :
V_33 ) ;
break;
case V_138 :
V_10 = F_14 ( V_3 , V_5 ,
V_137 ) ;
break;
default:
F_6 ( V_3 -> V_11 , L_42 ) ;
}
}
V_17:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_3 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_61 ( struct V_142 * V_23 )
{
unsigned int V_143 = 0 ;
unsigned int V_144 = 0 ;
unsigned int V_89 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_23 -> V_95 ; V_36 ++ ) {
unsigned V_145 ;
unsigned V_146 ;
const struct V_93 * V_94 ;
V_94 = & V_23 -> V_96 [ V_36 ] ;
V_145 = V_94 -> V_5 ;
V_146 = V_94 -> V_5 + V_94 -> V_89 - 1 ;
if ( V_36 == 0 ) {
V_143 = V_145 ;
V_144 = V_146 ;
} else {
if ( V_145 < V_143 )
V_143 = V_145 ;
if ( V_146 > V_144 )
V_144 = V_146 ;
}
}
V_89 = V_144 - V_143 + 1 ;
return V_89 ;
}
static int F_62 ( struct V_147 * V_148 )
{
struct V_149 * V_150 =
F_63 ( V_148 -> V_11 . V_44 ) ;
struct V_151 * V_152 = NULL ;
struct V_124 * V_125 = V_148 -> V_11 . V_153 ;
struct V_1 * V_7 ;
const struct V_154 * V_155 = F_64 ( V_148 ) ;
unsigned int V_156 = - 1 ;
int V_10 , V_157 ;
int V_36 ;
if ( V_150 )
V_152 = V_150 -> V_30 ;
if ( ! ( V_152 || V_125 ) ) {
F_6 ( & V_148 -> V_11 , L_43 ) ;
return - V_97 ;
}
V_7 = F_65 ( & V_148 -> V_11 , sizeof( struct V_1 ) ,
V_112 ) ;
if ( V_7 == NULL ) {
F_6 ( & V_148 -> V_11 ,
L_44 ) ;
return - V_113 ;
}
V_7 -> V_11 = & V_148 -> V_11 ;
V_7 -> V_44 = F_66 ( V_148 -> V_11 . V_44 ) ;
V_7 -> V_3 = V_158 ;
V_7 -> V_3 . V_11 = & V_148 -> V_11 ;
V_7 -> V_3 . V_76 = ( V_125 ) ? - 1 : V_152 -> V_159 ;
if ( V_155 )
V_156 = V_155 -> V_160 ;
else if ( V_125 ) {
const struct V_161 * V_162 ;
V_162 = F_67 ( V_163 , & V_148 -> V_11 ) ;
if ( V_162 )
V_156 = ( unsigned long ) V_162 -> V_105 ;
}
switch ( V_156 ) {
case V_164 :
F_68 ( & V_7 -> V_23 ) ;
break;
case V_165 :
F_69 ( & V_7 -> V_23 ) ;
break;
case V_166 :
F_70 ( & V_7 -> V_23 ) ;
break;
case V_167 :
F_71 ( & V_7 -> V_23 ) ;
break;
default:
F_6 ( & V_148 -> V_11 , L_45 , V_156 ) ;
return - V_27 ;
}
if ( ! V_7 -> V_23 ) {
F_6 ( & V_148 -> V_11 , L_46 ) ;
return - V_27 ;
}
V_7 -> V_3 . V_77 = F_61 ( V_7 -> V_23 ) ;
V_7 -> V_40 = V_7 -> V_23 -> V_168 ;
V_7 -> V_37 = V_7 -> V_23 -> V_169 ;
V_10 = F_72 ( & V_7 -> V_3 ) ;
if ( V_10 ) {
F_6 ( & V_148 -> V_11 , L_47 , V_10 ) ;
return V_10 ;
}
F_73 ( & V_148 -> V_11 , L_48 ) ;
V_170 . V_90 = V_7 -> V_23 -> V_90 ;
V_170 . V_89 = V_7 -> V_23 -> V_89 ;
V_7 -> V_47 = F_74 ( & V_170 , & V_148 -> V_11 , V_7 ) ;
if ( ! V_7 -> V_47 ) {
F_6 ( & V_148 -> V_11 ,
L_49 ) ;
V_10 = - V_27 ;
goto V_171;
}
F_73 ( & V_148 -> V_11 , L_50 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_23 -> V_95 ; V_36 ++ ) {
const struct V_93 * V_94 = & V_7 -> V_23 -> V_96 [ V_36 ] ;
V_10 = F_75 ( & V_7 -> V_3 ,
F_76 ( & V_148 -> V_11 ) ,
V_94 -> V_5 - 1 , V_94 -> V_5 , V_94 -> V_89 ) ;
if ( V_10 < 0 )
goto V_171;
}
F_77 ( V_148 , V_7 ) ;
F_73 ( & V_148 -> V_11 , L_51 ) ;
return 0 ;
V_171:
V_157 = F_78 ( & V_7 -> V_3 ) ;
if ( V_157 )
F_73 ( & V_148 -> V_11 , L_52 ) ;
return V_10 ;
}
static int F_79 ( struct V_147 * V_148 )
{
struct V_1 * V_7 = F_80 ( V_148 ) ;
int V_10 ;
V_10 = F_78 ( & V_7 -> V_3 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_53 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int T_2 F_81 ( void )
{
return F_82 ( & V_172 ) ;
}
