static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_7 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_10 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_8 ,
const unsigned * * V_11 , unsigned * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_11 = V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_11 ;
* V_12 = V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_13 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_14 * V_15 ,
unsigned V_16 )
{
F_6 ( V_15 , L_1 , V_17 ) ;
}
static int F_7 ( struct V_18 * V_19 ,
const char * V_20 ,
enum V_21 type ,
unsigned long * V_22 ,
unsigned int V_23 )
{
unsigned long * V_24 ;
V_24 = F_8 ( V_22 , V_23 * sizeof( * V_24 ) ,
V_25 ) ;
if ( V_24 == NULL )
return - V_26 ;
V_19 -> type = type ;
V_19 -> V_27 . V_22 . V_20 = V_20 ;
V_19 -> V_27 . V_22 . V_22 = V_24 ;
V_19 -> V_27 . V_22 . V_23 = V_23 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_18 * * V_19 ,
unsigned int * V_30 , unsigned int * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 = V_4 -> V_5 -> V_33 ;
struct V_18 * V_34 = * V_19 ;
unsigned int V_35 = * V_30 ;
unsigned int V_36 = * V_31 ;
unsigned int V_23 ;
const char * V_37 = NULL ;
unsigned long * V_22 ;
struct V_38 * V_39 ;
unsigned int V_40 ;
unsigned int V_12 ;
const char * V_41 ;
const char * V_42 ;
int V_43 ;
if ( ! V_4 -> V_44 ) {
if ( F_10 ( V_29 , L_2 , NULL ) ||
F_10 ( V_29 , L_3 , NULL ) ) {
V_4 -> V_44 = L_4 ;
V_4 -> V_45 = L_2 ;
V_4 -> V_46 = L_3 ;
} else {
V_4 -> V_44 = L_5 ;
V_4 -> V_45 = L_6 ;
V_4 -> V_46 = L_7 ;
}
}
V_43 = F_11 ( V_29 , V_4 -> V_44 , & V_37 ) ;
if ( V_43 < 0 && V_43 != - V_47 ) {
F_12 ( V_33 , L_8 ) ;
return V_43 ;
}
V_43 = F_13 ( V_29 , NULL , & V_22 , & V_23 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_37 && V_23 == 0 ) {
F_12 ( V_33 ,
L_9 ) ;
V_43 = - V_48 ;
goto V_49;
}
V_43 = F_14 ( V_29 , V_4 -> V_46 ) ;
if ( V_43 == - V_47 ) {
V_12 = 0 ;
} else if ( V_43 < 0 ) {
F_12 ( V_33 , L_10 ) ;
goto V_49;
} else {
V_12 = V_43 ;
}
V_43 = F_14 ( V_29 , V_4 -> V_45 ) ;
if ( V_43 == - V_47 ) {
V_40 = 0 ;
} else if ( V_43 < 0 ) {
F_12 ( V_33 , L_11 ) ;
goto V_49;
} else {
V_40 = V_43 ;
}
if ( ! V_12 && ! V_40 ) {
F_12 ( V_33 , L_12 ) ;
V_43 = - V_48 ;
goto V_49;
}
if ( V_37 )
V_35 += V_40 ;
if ( V_22 )
V_35 += V_12 + V_40 ;
V_34 = F_15 ( V_34 , sizeof( * V_34 ) * V_35 , V_25 ) ;
if ( V_34 == NULL ) {
V_43 = - V_26 ;
goto V_49;
}
* V_19 = V_34 ;
* V_30 = V_35 ;
F_16 (np, pmx->groups_prop_name, prop, group) {
if ( V_37 ) {
V_34 [ V_36 ] . type = V_50 ;
V_34 [ V_36 ] . V_27 . V_51 . V_41 = V_41 ;
V_34 [ V_36 ] . V_27 . V_51 . V_37 = V_37 ;
V_36 ++ ;
}
if ( V_22 ) {
V_43 = F_7 ( & V_34 [ V_36 ] , V_41 ,
V_52 ,
V_22 , V_23 ) ;
if ( V_43 < 0 )
goto V_49;
V_36 ++ ;
}
}
if ( ! V_22 ) {
V_43 = 0 ;
goto V_49;
}
F_16 (np, pmx->pins_prop_name, prop, pin) {
V_43 = F_7 ( & V_34 [ V_36 ] , V_42 ,
V_53 ,
V_22 , V_23 ) ;
if ( V_43 < 0 )
goto V_49;
V_36 ++ ;
}
V_49:
* V_31 = V_36 ;
F_17 ( V_22 ) ;
return V_43 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_18 * V_19 , unsigned V_30 )
{
unsigned int V_54 ;
if ( V_19 == NULL )
return;
for ( V_54 = 0 ; V_54 < V_30 ; ++ V_54 ) {
if ( V_19 [ V_54 ] . type == V_52 ||
V_19 [ V_54 ] . type == V_53 )
F_17 ( V_19 [ V_54 ] . V_27 . V_22 . V_22 ) ;
}
F_17 ( V_19 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_18 * * V_19 , unsigned * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 = V_4 -> V_5 -> V_33 ;
struct V_28 * V_55 ;
unsigned int V_31 ;
int V_43 ;
* V_19 = NULL ;
* V_30 = 0 ;
V_31 = 0 ;
F_20 (np, child) {
V_43 = F_9 ( V_2 , V_55 , V_19 , V_30 ,
& V_31 ) ;
if ( V_43 < 0 ) {
F_21 ( V_55 ) ;
goto V_49;
}
}
if ( * V_30 == 0 ) {
V_43 = F_9 ( V_2 , V_29 , V_19 , V_30 ,
& V_31 ) ;
if ( V_43 < 0 )
goto V_49;
}
if ( * V_30 )
return 0 ;
F_12 ( V_33 , L_13 , V_29 -> V_56 ) ;
V_43 = - V_47 ;
V_49:
if ( V_43 < 0 )
F_18 ( V_2 , * V_19 , * V_30 ) ;
return V_43 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_57 ;
}
static const char * F_23 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_58 [ V_8 ] . V_10 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned V_8 ,
const char * const * * V_9 ,
unsigned * const V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_5 -> V_6 -> V_58 [ V_8 ] . V_9 ;
* V_40 = V_4 -> V_5 -> V_6 -> V_58 [ V_8 ] . V_7 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_8 ,
unsigned V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
const struct V_60 * V_61 = & V_5 -> V_6 -> V_9 [ V_41 ] ;
unsigned long V_62 ;
unsigned int V_54 ;
int V_43 = 0 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
for ( V_54 = 0 ; V_54 < V_61 -> V_13 ; ++ V_54 ) {
int V_36 = F_27 ( V_5 , V_61 -> V_11 [ V_54 ] ) ;
struct V_64 * V_65 = & V_4 -> V_22 [ V_36 ] ;
if ( V_65 -> type != V_66 ) {
V_43 = - V_67 ;
goto V_49;
}
}
for ( V_54 = 0 ; V_54 < V_61 -> V_13 ; ++ V_54 ) {
V_43 = F_28 ( V_5 , V_61 -> V_51 [ V_54 ] , V_68 ) ;
if ( V_43 < 0 )
break;
}
V_49:
F_29 ( & V_5 -> V_63 , V_62 ) ;
return V_43 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
int V_36 = F_27 ( V_5 , V_16 ) ;
struct V_64 * V_65 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_62 ;
int V_43 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
if ( V_65 -> type != V_66 ) {
F_12 ( V_5 -> V_33 ,
L_14 ,
V_16 ) ;
V_43 = - V_67 ;
goto V_49;
}
if ( ! V_5 -> V_71 ) {
const struct V_72 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
V_43 = F_28 ( V_5 , V_42 -> V_73 , V_74 ) ;
if ( V_43 < 0 )
goto V_49;
}
V_65 -> type = V_74 ;
V_43 = 0 ;
V_49:
F_29 ( & V_5 -> V_63 , V_62 ) ;
return V_43 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
int V_36 = F_27 ( V_5 , V_16 ) ;
struct V_64 * V_65 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_62 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_65 -> type = V_66 ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
unsigned V_16 , bool V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
int V_76 = V_75 ? V_77 : V_78 ;
int V_36 = F_27 ( V_5 , V_16 ) ;
const struct V_72 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
struct V_64 * V_65 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_62 ;
unsigned int V_79 ;
int V_43 ;
if ( V_42 -> V_22 ) {
V_79 = V_75 ? V_80 : V_81 ;
if ( ! ( V_42 -> V_22 & V_79 ) )
return - V_47 ;
}
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_43 = F_28 ( V_5 , V_42 -> V_73 , V_76 ) ;
if ( V_43 < 0 )
goto V_49;
V_65 -> type = V_76 ;
V_49:
F_29 ( & V_5 -> V_63 , V_62 ) ;
return V_43 ;
}
static T_1 F_33 ( struct V_59 * V_5 ,
unsigned int V_42 , unsigned int * V_16 , unsigned int * V_82 )
{
const struct V_83 * V_84 ;
const struct V_85 * V_86 ;
unsigned int V_54 ;
for ( V_86 = V_5 -> V_6 -> V_87 ; V_86 -> V_86 ; ++ V_86 ) {
for ( V_54 = 0 ; V_54 < F_34 ( V_86 -> V_88 ) ; ++ V_54 ) {
V_84 = & V_86 -> V_88 [ V_54 ] ;
if ( V_84 -> V_82 && V_84 -> V_42 == V_42 ) {
* V_16 = V_84 -> V_16 ;
* V_82 = V_84 -> V_82 ;
return V_86 -> V_86 ;
}
}
}
return 0 ;
}
static int F_35 ( struct V_59 * V_5 ,
unsigned int V_42 )
{
unsigned long V_62 ;
unsigned int V_16 ;
unsigned int V_82 ;
T_1 V_86 ;
T_1 V_89 ;
V_86 = F_33 ( V_5 , V_42 , & V_16 , & V_82 ) ;
if ( ! V_86 )
return - V_47 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_89 = F_36 ( V_5 , V_86 , 32 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
V_89 = ( V_89 >> V_16 ) & F_37 ( V_82 - 1 , 0 ) ;
return ( V_89 + 1 ) * ( V_82 == 2 ? 6 : 3 ) ;
}
static int F_38 ( struct V_59 * V_5 ,
unsigned int V_42 , T_2 V_90 )
{
unsigned long V_62 ;
unsigned int V_16 ;
unsigned int V_82 ;
unsigned int V_91 ;
T_1 V_86 ;
T_1 V_89 ;
V_86 = F_33 ( V_5 , V_42 , & V_16 , & V_82 ) ;
if ( ! V_86 )
return - V_47 ;
V_91 = V_82 == 2 ? 6 : 3 ;
if ( V_90 < V_91 || V_90 > 24 )
return - V_47 ;
V_90 = V_90 / V_91 - 1 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_89 = F_36 ( V_5 , V_86 , 32 ) ;
V_89 &= ~ F_37 ( V_16 + V_82 - 1 , V_16 ) ;
V_89 |= V_90 << V_16 ;
F_39 ( V_5 , V_86 , 32 , V_89 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
return 0 ;
}
static bool F_40 ( struct V_59 * V_5 , unsigned int V_92 ,
enum V_93 V_94 )
{
int V_36 = F_27 ( V_5 , V_92 ) ;
const struct V_72 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
switch ( V_94 ) {
case V_95 :
return V_42 -> V_22 &
( V_96 | V_97 ) ;
case V_98 :
return V_42 -> V_22 & V_96 ;
case V_99 :
return V_42 -> V_22 & V_97 ;
case V_100 :
return V_42 -> V_22 & V_101 ;
case V_102 :
return V_42 -> V_22 & V_103 ;
default:
return false ;
}
}
static int F_41 ( struct V_1 * V_2 , unsigned V_92 ,
unsigned long * V_104 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
enum V_93 V_94 = F_42 ( * V_104 ) ;
unsigned long V_62 ;
unsigned int V_105 ;
if ( ! F_40 ( V_5 , V_92 , V_94 ) )
return - V_106 ;
switch ( V_94 ) {
case V_95 :
case V_98 :
case V_99 : {
unsigned int V_107 ;
if ( ! V_5 -> V_6 -> V_108 || ! V_5 -> V_6 -> V_108 -> V_109 )
return - V_106 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_107 = V_5 -> V_6 -> V_108 -> V_109 ( V_5 , V_92 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
if ( V_107 != V_94 )
return - V_47 ;
V_105 = 0 ;
break;
}
case V_100 : {
int V_43 ;
V_43 = F_35 ( V_5 , V_92 ) ;
if ( V_43 < 0 )
return V_43 ;
V_105 = V_43 ;
break;
}
case V_102 : {
T_1 V_110 , V_89 ;
int V_111 ;
if ( ! V_5 -> V_6 -> V_108 || ! V_5 -> V_6 -> V_108 -> V_112 )
return - V_106 ;
V_111 = V_5 -> V_6 -> V_108 -> V_112 ( V_5 , V_92 , & V_110 ) ;
if ( F_43 ( V_111 < 0 , L_15 , V_92 ) )
return V_111 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_89 = F_36 ( V_5 , V_110 , 32 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
V_105 = ( V_89 & F_44 ( V_111 ) ) ? 3300 : 1800 ;
break;
}
default:
return - V_106 ;
}
* V_104 = F_45 ( V_94 , V_105 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned V_92 ,
unsigned long * V_22 , unsigned V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_5 = V_4 -> V_5 ;
enum V_93 V_94 ;
unsigned long V_62 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_23 ; V_54 ++ ) {
V_94 = F_42 ( V_22 [ V_54 ] ) ;
if ( ! F_40 ( V_5 , V_92 , V_94 ) )
return - V_106 ;
switch ( V_94 ) {
case V_98 :
case V_99 :
case V_95 :
if ( ! V_5 -> V_6 -> V_108 || ! V_5 -> V_6 -> V_108 -> V_113 )
return - V_106 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_5 -> V_6 -> V_108 -> V_113 ( V_5 , V_92 , V_94 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
break;
case V_100 : {
unsigned int V_105 =
F_47 ( V_22 [ V_54 ] ) ;
int V_43 ;
V_43 = F_38 ( V_5 , V_92 , V_105 ) ;
if ( V_43 < 0 )
return V_43 ;
break;
}
case V_102 : {
unsigned int V_114 = F_47 ( V_22 [ V_54 ] ) ;
T_1 V_110 , V_89 ;
int V_111 ;
if ( ! V_5 -> V_6 -> V_108 || ! V_5 -> V_6 -> V_108 -> V_112 )
return - V_106 ;
V_111 = V_5 -> V_6 -> V_108 -> V_112 ( V_5 , V_92 , & V_110 ) ;
if ( F_43 ( V_111 < 0 , L_15 , V_92 ) )
return V_111 ;
if ( V_114 != 1800 && V_114 != 3300 )
return - V_47 ;
F_26 ( & V_5 -> V_63 , V_62 ) ;
V_89 = F_36 ( V_5 , V_110 , 32 ) ;
if ( V_114 == 3300 )
V_89 |= F_44 ( V_111 ) ;
else
V_89 &= ~ F_44 ( V_111 ) ;
F_39 ( V_5 , V_110 , 32 , V_89 ) ;
F_29 ( & V_5 -> V_63 , V_62 ) ;
break;
}
default:
return - V_106 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned V_41 ,
unsigned long * V_22 ,
unsigned V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned int * V_11 ;
unsigned int V_12 ;
unsigned int V_54 ;
V_11 = V_4 -> V_5 -> V_6 -> V_9 [ V_41 ] . V_11 ;
V_12 = V_4 -> V_5 -> V_6 -> V_9 [ V_41 ] . V_13 ;
for ( V_54 = 0 ; V_54 < V_12 ; ++ V_54 )
F_46 ( V_2 , V_11 [ V_54 ] , V_22 , V_23 ) ;
return 0 ;
}
static int F_49 ( struct V_59 * V_5 , struct V_3 * V_4 )
{
unsigned int V_54 ;
V_4 -> V_11 = F_50 ( V_5 -> V_33 ,
sizeof( * V_4 -> V_11 ) * V_5 -> V_6 -> V_13 ,
V_25 ) ;
if ( F_51 ( ! V_4 -> V_11 ) )
return - V_26 ;
V_4 -> V_22 = F_50 ( V_5 -> V_33 ,
sizeof( * V_4 -> V_22 ) * V_5 -> V_6 -> V_13 ,
V_25 ) ;
if ( F_51 ( ! V_4 -> V_22 ) )
return - V_26 ;
for ( V_54 = 0 ; V_54 < V_5 -> V_6 -> V_13 ; ++ V_54 ) {
const struct V_72 * V_6 = & V_5 -> V_6 -> V_11 [ V_54 ] ;
struct V_64 * V_65 = & V_4 -> V_22 [ V_54 ] ;
struct V_115 * V_42 = & V_4 -> V_11 [ V_54 ] ;
V_42 -> V_116 = V_6 -> V_42 != ( T_2 ) - 1 ? V_6 -> V_42 : V_54 ;
V_42 -> V_10 = V_6 -> V_10 ;
V_65 -> type = V_66 ;
}
return 0 ;
}
int F_52 ( struct V_59 * V_5 )
{
struct V_3 * V_4 ;
int V_43 ;
V_4 = F_50 ( V_5 -> V_33 , sizeof( * V_4 ) , V_25 ) ;
if ( F_51 ( ! V_4 ) )
return - V_26 ;
V_4 -> V_5 = V_5 ;
V_43 = F_49 ( V_5 , V_4 ) ;
if ( V_43 < 0 )
return V_43 ;
V_4 -> V_117 . V_10 = V_17 ;
V_4 -> V_117 . V_118 = V_119 ;
V_4 -> V_117 . V_120 = & V_121 ;
V_4 -> V_117 . V_122 = & V_123 ;
V_4 -> V_117 . V_124 = & V_125 ;
V_4 -> V_117 . V_11 = V_4 -> V_11 ;
V_4 -> V_117 . V_126 = V_5 -> V_6 -> V_13 ;
V_43 = F_53 ( V_5 -> V_33 , & V_4 -> V_117 , V_4 ,
& V_4 -> V_127 ) ;
if ( V_43 ) {
F_12 ( V_5 -> V_33 , L_16 , V_43 ) ;
return V_43 ;
}
return F_54 ( V_4 -> V_127 ) ;
}
