static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 3 + ( F_2 ( V_2 -> V_5 ) +
sizeof( L_1 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_1 ( V_2 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static char F_5 ( bool V_7 )
{
return V_7 ? '-' : '+' ;
}
static char F_6 ( const struct V_8 * V_9 )
{
return V_9 -> V_10 ? F_5 ( V_9 -> V_7 ) : ' ' ;
}
static char F_7 ( const struct V_11 * V_12 )
{
return F_6 ( & V_12 -> V_9 ) ;
}
static char F_8 ( const struct V_13 * V_14 )
{
return F_6 ( & V_14 -> V_9 ) ;
}
static void F_9 ( struct V_8 * V_9 , bool V_15 )
{
V_9 -> V_7 = V_15 ? V_9 -> V_10 : false ;
}
static int F_10 ( struct V_16 * V_17 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
for ( V_20 = F_11 ( & V_17 -> V_21 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_22 = F_13 ( V_20 , struct V_16 , V_19 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
F_14 (chain, &child->val, list) {
++ V_18 ;
V_24 = F_8 ( V_23 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' )
V_18 += F_10 ( V_22 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_13 * V_23 ;
bool V_7 = false ;
int V_18 = 0 ;
F_14 (chain, &node->val, list) {
++ V_18 ;
V_7 = V_23 -> V_9 . V_7 ;
}
if ( V_7 )
V_18 += F_10 ( V_17 ) ;
return V_18 ;
}
static int F_16 ( struct V_21 * V_23 )
{
struct V_19 * V_20 ;
int V_18 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_18 += F_15 ( V_17 ) ;
}
return V_18 ;
}
static bool F_17 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return false ;
if ( ! V_9 -> V_10 )
return false ;
V_9 -> V_7 = ! V_9 -> V_7 ;
return true ;
}
static void F_18 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_11 ( & V_17 -> V_21 ) ;
for ( V_20 = F_11 ( & V_17 -> V_21 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_22 = F_13 ( V_20 , struct V_16 , V_19 ) ;
struct V_13 * V_23 ;
bool V_25 = true ;
F_14 (chain, &child->val, list) {
if ( V_25 ) {
V_25 = false ;
V_23 -> V_9 . V_10 = V_23 -> V_26 . V_27 != & V_22 -> V_28 ||
! F_19 ( & V_22 -> V_21 ) ;
} else
V_23 -> V_9 . V_10 = V_23 -> V_26 . V_27 == & V_22 -> V_28 &&
! F_19 ( & V_22 -> V_21 ) ;
}
F_18 ( V_22 ) ;
}
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_13 * V_23 ;
F_14 (chain, &node->val, list)
V_23 -> V_9 . V_10 = ! F_19 ( & V_17 -> V_21 ) ;
F_18 ( V_17 ) ;
}
static void F_21 ( struct V_21 * V_29 )
{
struct V_19 * V_20 ;
for ( V_20 = F_11 ( V_29 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
F_20 ( V_17 ) ;
}
}
static void F_22 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_30 ) {
V_12 -> V_9 . V_10 = ! F_19 ( & V_12 -> V_31 ) ;
F_21 ( & V_12 -> V_31 ) ;
V_12 -> V_30 = true ;
}
}
static bool F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_32 ) ) {
struct V_11 * V_12 = V_2 -> V_33 ;
F_22 ( V_12 ) ;
V_2 -> V_5 -> V_6 -= V_12 -> V_34 ;
if ( V_12 -> V_9 . V_7 )
V_12 -> V_34 = F_16 ( & V_12 -> V_31 ) ;
else
V_12 -> V_34 = 0 ;
V_2 -> V_5 -> V_6 += V_12 -> V_34 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
return true ;
}
return false ;
}
static int F_24 ( struct V_16 * V_17 , bool V_15 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
for ( V_20 = F_11 ( & V_17 -> V_21 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_22 = F_13 ( V_20 , struct V_16 , V_19 ) ;
struct V_13 * V_23 ;
bool V_10 = false ;
F_14 (chain, &child->val, list) {
++ V_18 ;
F_9 ( & V_23 -> V_9 , V_15 ) ;
V_10 = V_23 -> V_9 . V_10 ;
}
if ( V_10 )
V_18 += F_24 ( V_22 , V_15 ) ;
}
return V_18 ;
}
static int F_25 ( struct V_16 * V_17 , bool V_15 )
{
struct V_13 * V_23 ;
bool V_10 = false ;
int V_18 = 0 ;
F_14 (chain, &node->val, list) {
++ V_18 ;
F_9 ( & V_23 -> V_9 , V_15 ) ;
V_10 = V_23 -> V_9 . V_10 ;
}
if ( V_10 )
V_18 += F_24 ( V_17 , V_15 ) ;
return V_18 ;
}
static int F_26 ( struct V_21 * V_23 , bool V_15 )
{
struct V_19 * V_20 ;
int V_18 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_18 += F_25 ( V_17 , V_15 ) ;
}
return V_18 ;
}
static void F_27 ( struct V_11 * V_12 , bool V_15 )
{
F_22 ( V_12 ) ;
F_9 ( & V_12 -> V_9 , V_15 ) ;
if ( V_12 -> V_9 . V_10 ) {
int V_18 = F_26 ( & V_12 -> V_31 , V_15 ) ;
V_12 -> V_34 = V_15 ? V_18 : 0 ;
} else
V_12 -> V_34 = 0 ;
}
static void F_28 ( struct V_5 * V_5 , bool V_15 )
{
struct V_19 * V_20 ;
V_5 -> V_6 = 0 ;
for ( V_20 = F_11 ( & V_5 -> V_35 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_12 = F_13 ( V_20 , struct V_11 , V_19 ) ;
F_27 ( V_12 , V_15 ) ;
V_5 -> V_6 += 1 + V_12 -> V_34 ;
}
}
static void F_29 ( struct V_1 * V_2 , bool V_15 )
{
F_28 ( V_2 -> V_5 , V_15 ) ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_4 ( & V_2 -> V_3 ) ;
}
static void F_30 ( struct V_36 * V_2 )
{
F_31 ( V_2 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_32 ( struct V_1 * V_2 , const char * V_37 ,
struct V_38 * V_39 )
{
int V_40 ;
char V_41 [ 160 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
V_2 -> V_3 . V_35 = & V_2 -> V_5 -> V_35 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_1 ( V_2 ) ;
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
if ( F_34 ( & V_2 -> V_3 , V_41 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_2 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_44 :
V_39 -> V_45 ( V_39 -> V_46 ) ;
F_36 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_2 -> V_5 -> V_47 . V_48 !=
V_2 -> V_5 -> V_47 . V_49 [ V_50 ] ) {
V_2 -> V_5 -> V_47 . V_48 =
V_2 -> V_5 -> V_47 . V_49 [ V_50 ] ;
F_30 ( & V_2 -> V_3 ) ;
}
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
F_37 ( & V_2 -> V_3 , V_41 ) ;
continue;
case 'D' : {
static int V_51 ;
struct V_11 * V_52 = F_13 ( V_2 -> V_3 . V_53 ,
struct V_11 , V_19 ) ;
F_38 () ;
F_39 ( L_7 ,
V_51 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_54 ,
V_2 -> V_3 . V_55 ,
V_2 -> V_3 . V_56 ,
V_52 -> V_57 , V_52 -> V_34 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_58 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_59;
}
}
V_59:
F_40 ( & V_2 -> V_3 ) ;
return V_40 ;
}
static char * F_41 ( struct V_13 * V_14 ,
char * V_60 , T_1 V_61 , bool V_62 )
{
int V_63 ;
if ( V_14 -> V_9 . V_64 )
V_63 = F_42 ( V_60 , V_61 , L_8 , V_14 -> V_9 . V_64 -> V_65 ) ;
else
V_63 = F_42 ( V_60 , V_61 , L_9 V_66 , V_14 -> V_67 ) ;
if ( V_62 )
F_42 ( V_60 + V_63 , V_61 - V_63 , L_10 ,
V_14 -> V_9 . V_68 ? V_14 -> V_9 . V_68 -> V_69 -> V_70 : L_11 ) ;
return V_60 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_71 ,
T_2 V_72 , int V_73 ,
unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_19 * V_17 ;
int V_76 = V_74 , V_4 , V_77 = V_73 * V_78 ;
T_2 V_79 , V_80 ;
if ( V_81 . V_82 == V_83 )
V_79 = V_71 -> V_84 ;
else
V_79 = V_72 ;
V_80 = V_79 ;
V_17 = F_11 ( & V_71 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_85 = F_44 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_86 = 0 ;
V_80 -= V_85 ;
F_14 (chain, &child->val, list) {
char V_60 [ 1024 ] , * V_87 ;
const char * V_88 ;
int V_89 ;
bool V_90 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_86 = V_78 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_57 != 0 ) {
-- * V_57 ;
goto V_91;
}
V_87 = NULL ;
V_88 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
if ( V_90 ) {
double V_92 = V_85 * 100.0 / V_79 ;
if ( F_45 ( & V_87 , L_12 , V_92 , V_88 ) < 0 )
V_88 = L_13 ;
else
V_88 = V_87 ;
}
V_89 = V_93 ;
V_4 = V_2 -> V_3 . V_4 - ( V_77 + V_86 + 2 ) ;
if ( F_46 ( & V_2 -> V_3 , V_74 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_89 = V_94 ;
* V_75 = true ;
}
F_47 ( & V_2 -> V_3 , V_89 ) ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
F_49 ( L_14 , V_77 + V_86 ) ;
F_50 ( L_15 , V_24 ) ;
F_49 ( V_88 , V_4 ) ;
free ( V_87 ) ;
if ( ++ V_74 == V_2 -> V_3 . V_54 )
goto V_59;
V_91:
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_95 = V_73 + ( V_86 ? 2 : 1 ) ;
V_74 += F_43 ( V_2 , V_22 , V_79 ,
V_95 , V_74 , V_57 ,
V_75 ) ;
}
if ( V_74 == V_2 -> V_3 . V_54 )
goto V_59;
V_17 = V_27 ;
}
V_59:
return V_74 - V_76 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_73 , unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_13 * V_23 ;
int V_76 = V_74 ,
V_77 = V_73 * V_78 ,
V_4 = V_2 -> V_3 . V_4 - V_77 ;
char V_24 = ' ' ;
F_14 (chain, &node->val, list) {
char V_60 [ 1024 ] , * V_96 ;
int V_89 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_57 != 0 ) {
-- * V_57 ;
continue;
}
V_89 = V_93 ;
if ( F_46 ( & V_2 -> V_3 , V_74 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_89 = V_94 ;
* V_75 = true ;
}
V_96 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
F_47 ( & V_2 -> V_3 , V_89 ) ;
F_49 ( L_14 , V_77 ) ;
F_50 ( L_15 , V_24 ) ;
F_49 ( V_96 , V_4 - 2 ) ;
if ( ++ V_74 == V_2 -> V_3 . V_54 )
goto V_59;
}
if ( V_24 == '-' )
V_74 += F_43 ( V_2 , V_17 ,
V_2 -> V_5 -> V_47 . V_97 ,
V_73 + 1 , V_74 ,
V_57 ,
V_75 ) ;
V_59:
return V_74 - V_76 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
int V_73 , unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_19 * V_20 ;
int V_76 = V_74 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_74 += F_51 ( V_2 , V_17 , V_73 ,
V_74 , V_57 ,
V_75 ) ;
if ( V_74 == V_2 -> V_3 . V_54 )
break;
}
return V_74 - V_76 ;
}
static int F_53 ( struct V_98 * V_46 )
{
if ( ! V_99 . V_100 )
return 0 ;
F_50 ( L_15 , V_46 -> V_24 ) ;
return 2 ;
}
static int F_54 ( struct V_101 * V_102 , struct V_11 * V_12 ,
T_2 (* F_55)( struct V_11 * ) ,
int (* F_56)( struct V_98 * ) )
{
int V_103 = 0 ;
double V_92 = 0.0 ;
struct V_5 * V_5 = V_12 -> V_5 ;
struct V_98 * V_46 = V_102 -> V_104 ;
if ( V_5 -> V_47 . V_97 )
V_92 = 100.0 * F_55 ( V_12 ) / V_5 -> V_47 . V_97 ;
F_57 ( V_46 -> V_3 , V_92 , V_46 -> V_105 ) ;
if ( F_56 )
V_103 += F_56 ( V_46 ) ;
V_103 += F_42 ( V_102 -> V_106 , V_102 -> V_107 , L_16 , V_92 ) ;
F_50 ( L_8 , V_102 -> V_106 ) ;
if ( V_99 . V_108 ) {
int V_109 , V_110 ;
struct V_111 * V_112 = F_58 ( V_5 ) ;
struct V_11 * V_113 ;
int V_114 = V_112 -> V_114 ;
if ( V_114 <= 1 )
goto V_59;
V_109 = F_59 ( V_112 ) ;
F_14 (pair, &he->pairs.head, pairs.node) {
T_2 V_115 = F_55 ( V_113 ) ;
T_2 V_72 = V_113 -> V_5 -> V_47 . V_97 ;
if ( ! V_72 )
continue;
V_112 = F_58 ( V_113 -> V_5 ) ;
V_110 = F_59 ( V_112 ) - V_109 - 1 ;
while ( V_110 -- ) {
F_57 ( V_46 -> V_3 , 0.0 ,
V_46 -> V_105 ) ;
V_103 += F_42 ( V_102 -> V_106 , V_102 -> V_107 ,
L_17 , 0.0 ) ;
F_50 ( L_8 , V_102 -> V_106 ) ;
}
V_92 = 100.0 * V_115 / V_72 ;
F_57 ( V_46 -> V_3 , V_92 ,
V_46 -> V_105 ) ;
V_103 += F_42 ( V_102 -> V_106 , V_102 -> V_107 ,
L_17 , V_92 ) ;
F_50 ( L_8 , V_102 -> V_106 ) ;
V_109 = F_59 ( V_112 ) ;
}
V_110 = V_114 - V_109 - 1 ;
while ( V_110 -- ) {
F_57 ( V_46 -> V_3 , 0.0 ,
V_46 -> V_105 ) ;
V_103 += F_42 ( V_102 -> V_106 , V_102 -> V_107 ,
L_17 , 0.0 ) ;
F_50 ( L_8 , V_102 -> V_106 ) ;
}
}
V_59:
if ( ! V_46 -> V_105 || ! V_46 -> V_3 -> V_116 )
F_47 ( V_46 -> V_3 , V_93 ) ;
return V_103 ;
}
void F_60 ( void )
{
F_61 ( V_117 ) ;
F_62 () ;
V_118 [ V_117 ] . V_89 =
V_119 ;
V_118 [ V_120 ] . V_89 =
V_121 ;
V_118 [ V_122 ] . V_89 =
V_123 ;
V_118 [ V_124 ] . V_89 =
V_125 ;
V_118 [ V_126 ] . V_89 =
V_127 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_11 * V_128 ,
unsigned short V_74 )
{
char V_96 [ 256 ] ;
int V_63 = 0 ;
int V_4 = V_2 -> V_3 . V_4 ;
char V_24 = ' ' ;
bool V_105 = F_46 ( & V_2 -> V_3 , V_74 ) ;
T_3 V_57 = V_128 -> V_57 ;
bool V_25 = true ;
struct V_129 * V_130 ;
if ( V_105 ) {
V_2 -> V_33 = V_128 ;
V_2 -> V_32 = & V_128 -> V_9 ;
}
if ( V_99 . V_100 ) {
F_22 ( V_128 ) ;
V_24 = F_7 ( V_128 ) ;
}
if ( V_57 == 0 ) {
struct V_98 V_46 = {
. V_3 = & V_2 -> V_3 ,
. V_24 = V_24 ,
. V_105 = V_105 ,
} ;
struct V_101 V_102 = {
. V_106 = V_96 ,
. V_107 = sizeof( V_96 ) ,
. V_104 = & V_46 ,
} ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
F_64 (fmt) {
if ( ! V_25 ) {
F_50 ( L_18 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_130 -> V_89 ) {
V_4 -= V_130 -> V_89 ( & V_102 , V_128 ) ;
} else {
V_4 -= V_130 -> V_128 ( & V_102 , V_128 ) ;
F_50 ( L_8 , V_96 ) ;
}
}
if ( ! V_2 -> V_3 . V_116 )
V_4 += 1 ;
F_65 ( V_128 , V_96 , sizeof( V_96 ) , V_2 -> V_5 ) ;
F_49 ( V_96 , V_4 ) ;
++ V_74 ;
++ V_63 ;
} else
-- V_57 ;
if ( V_24 == '-' && V_74 != V_2 -> V_3 . V_54 ) {
V_63 += F_52 ( V_2 , & V_128 -> V_31 ,
1 , V_74 , & V_57 ,
& V_105 ) ;
if ( V_105 )
V_2 -> V_33 = V_128 ;
}
return V_63 ;
}
static void F_66 ( struct V_36 * V_2 )
{
if ( V_2 -> V_53 == NULL ) {
struct V_1 * V_131 ;
V_131 = F_67 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_53 = F_11 ( & V_131 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_68 ( struct V_36 * V_2 )
{
unsigned V_74 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_131 = F_67 ( V_2 , struct V_1 , V_3 ) ;
F_66 ( V_2 ) ;
for ( V_20 = V_2 -> V_53 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_132 )
continue;
V_74 += F_63 ( V_131 , V_52 , V_74 ) ;
if ( V_74 == V_2 -> V_54 )
break;
}
return V_74 ;
}
static struct V_19 * F_69 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_52 -> V_132 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_70 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_52 -> V_132 )
return V_20 ;
V_20 = F_71 ( V_20 ) ;
}
return NULL ;
}
static void F_72 ( struct V_36 * V_2 ,
T_3 V_77 , int V_133 )
{
struct V_11 * V_52 ;
struct V_19 * V_20 ;
bool V_25 = true ;
if ( V_2 -> V_6 == 0 )
return;
F_66 ( V_2 ) ;
switch ( V_133 ) {
case V_134 :
V_20 = F_69 ( F_11 ( V_2 -> V_35 ) ) ;
break;
case V_135 :
V_20 = V_2 -> V_53 ;
goto V_136;
case V_137 :
V_20 = F_70 ( F_73 ( V_2 -> V_35 ) ) ;
V_25 = false ;
break;
default:
return;
}
V_52 = F_13 ( V_2 -> V_53 , struct V_11 , V_19 ) ;
V_52 -> V_57 = 0 ;
V_136:
if ( V_77 > 0 ) {
do {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 ) {
T_4 V_80 = V_52 -> V_34 - V_52 -> V_57 ;
if ( V_77 > V_80 ) {
V_77 -= V_80 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 += V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
}
V_20 = F_69 ( F_12 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
-- V_77 ;
V_2 -> V_53 = V_20 ;
} while ( V_77 != 0 );
} else if ( V_77 < 0 ) {
while ( 1 ) {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 ) {
if ( V_25 ) {
if ( - V_77 > V_52 -> V_57 ) {
V_77 += V_52 -> V_57 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 += V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
} else {
if ( - V_77 > V_52 -> V_34 ) {
V_77 += V_52 -> V_34 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 = V_52 -> V_34 + V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
}
}
V_20 = F_70 ( F_71 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
++ V_77 ;
V_2 -> V_53 = V_20 ;
if ( V_77 == 0 ) {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 )
V_52 -> V_57 = V_52 -> V_34 ;
break;
}
V_25 = false ;
}
} else {
V_2 -> V_53 = V_20 ;
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_52 -> V_57 = 0 ;
}
}
static int F_74 ( struct V_1 * V_2 ,
struct V_16 * V_71 ,
T_2 V_72 , int V_73 ,
T_5 * V_138 )
{
struct V_19 * V_17 ;
int V_77 = V_73 * V_78 ;
T_2 V_79 , V_80 ;
int V_63 = 0 ;
if ( V_81 . V_82 == V_83 )
V_79 = V_71 -> V_84 ;
else
V_79 = V_72 ;
V_80 = V_79 ;
V_17 = F_11 ( & V_71 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_85 = F_44 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_86 = 0 ;
V_80 -= V_85 ;
F_14 (chain, &child->val, list) {
char V_60 [ 1024 ] , * V_87 ;
const char * V_88 ;
bool V_90 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_86 = V_78 ;
V_24 = F_8 ( V_23 ) ;
V_87 = NULL ;
V_88 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
if ( V_90 ) {
double V_92 = V_85 * 100.0 / V_79 ;
if ( F_45 ( & V_87 , L_12 , V_92 , V_88 ) < 0 )
V_88 = L_13 ;
else
V_88 = V_87 ;
}
V_63 += fprintf ( V_138 , L_19 , V_77 + V_86 , L_14 , V_24 , V_88 ) ;
free ( V_87 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_95 = V_73 + ( V_86 ? 2 : 1 ) ;
V_63 += F_74 ( V_2 , V_22 , V_79 ,
V_95 , V_138 ) ;
}
V_17 = V_27 ;
}
return V_63 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_73 , T_5 * V_138 )
{
struct V_13 * V_23 ;
int V_77 = V_73 * V_78 ;
char V_24 = ' ' ;
int V_63 = 0 ;
F_14 (chain, &node->val, list) {
char V_60 [ 1024 ] , * V_96 ;
V_24 = F_8 ( V_23 ) ;
V_96 = F_41 ( V_23 , V_60 , sizeof( V_60 ) , V_2 -> V_62 ) ;
V_63 += fprintf ( V_138 , L_19 , V_77 , L_14 , V_24 , V_96 ) ;
}
if ( V_24 == '-' )
V_63 += F_74 ( V_2 , V_17 ,
V_2 -> V_5 -> V_47 . V_97 ,
V_73 + 1 , V_138 ) ;
return V_63 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_73 , T_5 * V_138 )
{
struct V_19 * V_20 ;
int V_63 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_63 += F_75 ( V_2 , V_17 , V_73 , V_138 ) ;
}
return V_63 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_138 )
{
char V_96 [ 8192 ] ;
double V_92 ;
int V_63 = 0 ;
char V_24 = ' ' ;
if ( V_99 . V_100 )
V_24 = F_7 ( V_12 ) ;
F_65 ( V_12 , V_96 , sizeof( V_96 ) , V_2 -> V_5 ) ;
V_92 = ( V_12 -> V_139 . V_115 * 100.0 ) / V_2 -> V_5 -> V_47 . V_97 ;
if ( V_99 . V_100 )
V_63 += fprintf ( V_138 , L_15 , V_24 ) ;
V_63 += fprintf ( V_138 , L_20 , V_92 ) ;
if ( V_99 . V_140 )
V_63 += fprintf ( V_138 , L_21 , V_12 -> V_139 . V_49 ) ;
if ( V_99 . V_141 )
V_63 += fprintf ( V_138 , L_22 V_142 , V_12 -> V_139 . V_115 ) ;
V_63 += fprintf ( V_138 , L_23 , F_78 ( V_96 ) ) ;
if ( V_24 == '-' )
V_63 += F_76 ( V_2 , & V_12 -> V_31 , 1 , V_138 ) ;
return V_63 ;
}
static int F_79 ( struct V_1 * V_2 , T_5 * V_138 )
{
struct V_19 * V_20 = F_69 ( F_11 ( V_2 -> V_3 . V_35 ) ) ;
int V_63 = 0 ;
while ( V_20 ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_63 += F_77 ( V_2 , V_52 , V_138 ) ;
V_20 = F_69 ( F_12 ( V_20 ) ) ;
}
return V_63 ;
}
static int F_80 ( struct V_1 * V_2 )
{
char V_143 [ 64 ] ;
T_5 * V_138 ;
while ( 1 ) {
F_42 ( V_143 , sizeof( V_143 ) , L_24 , V_2 -> V_144 ) ;
if ( F_81 ( V_143 , V_145 ) )
break;
if ( ++ V_2 -> V_144 == 8192 ) {
F_39 ( L_25 ) ;
return - 1 ;
}
}
V_138 = fopen ( V_143 , L_26 ) ;
if ( V_138 == NULL ) {
char V_60 [ 64 ] ;
const char * V_146 = F_82 ( V_147 , V_60 , sizeof( V_60 ) ) ;
F_39 ( L_27 , V_143 , V_146 ) ;
return - 1 ;
}
++ V_2 -> V_144 ;
F_79 ( V_2 , V_138 ) ;
fclose ( V_138 ) ;
F_39 ( L_28 , V_143 ) ;
return 0 ;
}
static struct V_1 * F_83 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_84 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_43 = F_68 ;
V_2 -> V_3 . V_148 = F_72 ;
V_2 -> V_3 . V_149 = true ;
if ( V_150 == 1 )
V_2 -> V_151 = V_152 . V_26 . V_27 != NULL ;
else
V_2 -> V_151 = V_153 . V_26 . V_27 != NULL ;
}
return V_2 ;
}
static void F_85 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_86 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_154 * F_87 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_154 ;
}
static int F_33 ( struct V_5 * V_5 , char * V_60 , T_1 V_107 ,
const char * V_37 )
{
char V_155 ;
int V_63 ;
const struct V_69 * V_69 = V_5 -> V_156 ;
const struct V_154 * V_154 = V_5 -> V_157 ;
unsigned long V_158 = V_5 -> V_47 . V_49 [ V_159 ] ;
T_2 V_49 = V_5 -> V_47 . V_97 ;
struct V_111 * V_112 = F_58 ( V_5 ) ;
char V_106 [ 512 ] ;
T_1 V_160 = sizeof( V_106 ) ;
if ( F_88 ( V_112 ) ) {
struct V_111 * V_161 ;
F_89 ( V_112 , V_106 , V_160 ) ;
V_37 = V_106 ;
F_90 (pos, evsel) {
V_158 += V_161 -> V_5 . V_47 . V_49 [ V_159 ] ;
V_49 += V_161 -> V_5 . V_47 . V_97 ;
}
}
V_158 = F_91 ( V_158 , & V_155 ) ;
V_63 = F_42 ( V_60 , V_107 ,
L_29 ,
V_158 , V_155 , V_37 , V_49 ) ;
if ( V_5 -> V_162 )
V_63 += snprintf ( V_60 + V_63 , V_107 - V_63 ,
L_30 , V_5 -> V_162 ) ;
if ( V_154 )
V_63 += F_42 ( V_60 + V_63 , V_107 - V_63 ,
L_31 ,
( V_154 -> V_163 ? V_154 -> V_164 : L_32 ) ,
V_154 -> V_165 ) ;
if ( V_69 )
V_63 += F_42 ( V_60 + V_63 , V_107 - V_63 ,
L_33 , V_69 -> V_70 ) ;
return V_63 ;
}
static inline void F_92 ( char * * V_166 , int V_18 )
{
int V_167 ;
for ( V_167 = 0 ; V_167 < V_18 ; ++ V_167 ) {
free ( V_166 [ V_167 ] ) ;
V_166 [ V_167 ] = NULL ;
}
}
static inline bool F_93 ( void * V_45 )
{
return V_45 == NULL ;
}
static int F_94 ( void )
{
char * V_168 , * V_166 [ 32 ] , * V_169 [ 32 ] , * V_170 ;
T_6 * V_171 ;
int V_172 = 0 , V_173 = - 1 , V_103 = - 1 ;
struct V_174 * V_175 ;
V_168 = getenv ( L_34 ) ;
if ( ! V_168 )
return V_103 ;
V_171 = F_95 ( V_168 ) ;
if ( ! V_171 )
return V_103 ;
memset ( V_166 , 0 , sizeof( V_166 ) ) ;
memset ( V_166 , 0 , sizeof( V_169 ) ) ;
while ( ( V_175 = F_96 ( V_171 ) ) ) {
char V_176 [ V_177 ] ;
T_2 V_178 ;
char * V_65 = V_175 -> V_179 ;
T_5 * V_180 ;
if ( ! ( V_175 -> V_181 == V_182 ) )
continue;
snprintf ( V_176 , sizeof( V_176 ) , L_35 , V_168 , V_65 ) ;
V_180 = fopen ( V_176 , L_36 ) ;
if ( ! V_180 )
continue;
if ( fread ( & V_178 , 1 , 8 , V_180 ) < 8 )
goto V_183;
if ( F_97 ( V_178 ) ) {
V_166 [ V_172 ] = F_98 ( V_65 ) ;
if ( ! V_166 [ V_172 ] )
goto V_183;
V_169 [ V_172 ] = F_98 ( V_176 ) ;
if ( ! V_169 [ V_172 ] ) {
free ( V_166 [ V_172 ] ) ;
F_99 ( L_37 ) ;
fclose ( V_180 ) ;
break;
}
V_172 ++ ;
}
V_183:
fclose ( V_180 ) ;
if ( V_172 >= 32 ) {
F_99 ( L_38
L_39 ) ;
break;
}
}
F_100 ( V_171 ) ;
if ( V_172 ) {
V_173 = F_101 ( V_172 , V_166 ) ;
if ( V_173 < V_172 && V_173 >= 0 ) {
V_170 = F_98 ( V_169 [ V_173 ] ) ;
if ( V_170 ) {
if ( V_184 )
free ( ( void * ) V_185 ) ;
V_185 = V_170 ;
V_184 = true ;
V_103 = 0 ;
} else
F_99 ( L_40 ) ;
}
}
F_92 ( V_166 , V_172 ) ;
F_92 ( V_169 , V_172 ) ;
return V_103 ;
}
static int F_102 ( struct V_111 * V_112 , int V_49 ,
const char * V_186 , const char * V_37 ,
bool V_187 ,
struct V_38 * V_39 ,
struct V_188 * V_189 )
{
struct V_5 * V_5 = & V_112 -> V_5 ;
struct V_1 * V_2 = F_83 ( V_5 ) ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
char * V_166 [ 16 ] ;
int V_172 = 0 ;
int V_40 = - 1 ;
char V_106 [ 64 ] ;
char V_194 [ 64 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
if ( V_2 == NULL )
return - 1 ;
V_193 = F_103 ( 2 ) ;
if ( V_193 == NULL )
goto V_59;
F_104 ( V_186 ) ;
memset ( V_166 , 0 , sizeof( V_166 ) ) ;
while ( 1 ) {
const struct V_154 * V_154 = NULL ;
const struct V_69 * V_69 = NULL ;
int V_173 = 0 ,
V_195 = - 2 , V_196 = - 2 , V_197 = - 2 ,
V_198 = - 2 , V_199 = - 2 , V_200 = - 2 ;
int V_201 = - 2 , V_202 = - 2 ,
V_203 = - 2 , V_204 = - 2 ;
V_172 = 0 ;
V_40 = F_32 ( V_2 , V_37 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_154 = F_87 ( V_2 ) ;
V_69 = V_2 -> V_32 -> V_68 ? V_2 -> V_32 -> V_68 -> V_69 : NULL ;
}
switch ( V_40 ) {
case V_205 :
case V_206 :
if ( V_49 == 1 )
continue;
goto V_207;
case 'a' :
if ( ! V_2 -> V_151 ) {
F_31 ( & V_2 -> V_3 , V_42 * 2 ,
L_41
L_42 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_64 == NULL ||
V_2 -> V_32 -> V_68 -> V_69 -> V_208 )
continue;
goto V_209;
case 'P' :
F_80 ( V_2 ) ;
continue;
case 'd' :
goto V_196;
case 'V' :
V_2 -> V_62 = ! V_2 -> V_62 ;
continue;
case 't' :
goto V_197;
case '/' :
if ( F_105 ( L_43 ,
L_44 ,
V_106 , L_45 ,
V_42 * 2 ) == V_58 ) {
V_5 -> V_210 = * V_106 ? V_106 : NULL ;
F_106 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case 'r' :
if ( F_93 ( V_39 ) )
goto V_211;
continue;
case 's' :
if ( F_93 ( V_39 ) )
goto V_212;
continue;
case V_213 :
case 'h' :
case '?' :
F_107 ( & V_2 -> V_3 ,
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64 ) ;
continue;
case V_58 :
case V_214 :
break;
case V_215 : {
const void * V_53 ;
if ( F_108 ( V_193 ) ) {
if ( V_187 )
goto V_207;
continue;
}
V_53 = F_109 ( V_193 ) ;
if ( V_53 == & V_2 -> V_5 -> V_156 )
goto V_216;
if ( V_53 == & V_2 -> V_5 -> V_157 )
goto V_217;
continue;
}
case V_218 :
if ( ! V_187 &&
! F_110 ( & V_2 -> V_3 ,
L_65 ) )
continue;
case 'q' :
case F_111 ( 'c' ) :
goto V_207;
default:
continue;
}
if ( ! V_2 -> V_151 )
goto V_219;
if ( V_150 == 1 ) {
V_191 = V_2 -> V_33 -> V_190 ;
if ( V_2 -> V_32 != NULL &&
V_191 &&
V_191 -> V_220 . V_64 != NULL &&
! V_191 -> V_220 . V_68 -> V_69 -> V_208 &&
F_45 ( & V_166 [ V_172 ] , L_66 ,
V_191 -> V_220 . V_64 -> V_65 ) > 0 )
V_198 = V_172 ++ ;
if ( V_2 -> V_32 != NULL &&
V_191 &&
V_191 -> V_221 . V_64 != NULL &&
! V_191 -> V_221 . V_68 -> V_69 -> V_208 &&
( V_191 -> V_221 . V_64 != V_191 -> V_220 . V_64 ||
V_191 -> V_221 . V_68 -> V_69 != V_191 -> V_220 . V_68 -> V_69 ) &&
F_45 ( & V_166 [ V_172 ] , L_66 ,
V_191 -> V_221 . V_64 -> V_65 ) > 0 )
V_199 = V_172 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_64 != NULL &&
! V_2 -> V_32 -> V_68 -> V_69 -> V_208 &&
F_45 ( & V_166 [ V_172 ] , L_66 ,
V_2 -> V_32 -> V_64 -> V_65 ) > 0 )
V_195 = V_172 ++ ;
}
if ( V_154 != NULL &&
F_45 ( & V_166 [ V_172 ] , L_67 ,
( V_2 -> V_5 -> V_157 ? L_68 : L_69 ) ,
( V_154 -> V_163 ? V_154 -> V_164 : L_32 ) ,
V_154 -> V_165 ) > 0 )
V_197 = V_172 ++ ;
if ( V_69 != NULL &&
F_45 ( & V_166 [ V_172 ] , L_70 ,
( V_2 -> V_5 -> V_156 ? L_68 : L_69 ) ,
( V_69 -> V_222 ? L_71 : V_69 -> V_70 ) ) > 0 )
V_196 = V_172 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_68 != NULL &&
F_45 ( & V_166 [ V_172 ] , L_72 ) > 0 )
V_200 = V_172 ++ ;
if ( V_2 -> V_33 ) {
struct V_223 * V_64 ;
if ( F_45 ( & V_166 [ V_172 ] , L_73 ,
V_2 -> V_33 -> V_154 -> V_164 ) > 0 )
V_201 = V_172 ++ ;
V_64 = V_2 -> V_33 -> V_9 . V_64 ;
if ( V_64 && V_64 -> V_224 &&
F_45 ( & V_166 [ V_172 ] , L_74 ,
V_64 -> V_65 ) > 0 )
V_202 = V_172 ++ ;
}
if ( F_45 ( & V_166 [ V_172 ] , L_75 ) > 0 )
V_203 = V_172 ++ ;
if ( F_93 ( V_39 ) && F_45 ( & V_166 [ V_172 ] ,
L_76 ) > 0 )
V_204 = V_172 ++ ;
V_219:
V_166 [ V_172 ++ ] = ( char * ) L_77 ;
V_225:
V_173 = F_101 ( V_172 , V_166 ) ;
if ( V_173 == V_172 - 1 )
break;
if ( V_173 == - 1 ) {
F_92 ( V_166 , V_172 - 1 ) ;
continue;
}
if ( V_173 == V_195 || V_173 == V_199 || V_173 == V_198 ) {
struct V_11 * V_12 ;
int V_146 ;
V_209:
if ( ! V_226 && F_112 ( V_189 ) )
continue;
V_12 = F_86 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_173 == V_198 ) {
V_12 -> V_9 . V_64 = V_12 -> V_190 -> V_220 . V_64 ;
V_12 -> V_9 . V_68 = V_12 -> V_190 -> V_220 . V_68 ;
} else if ( V_173 == V_199 ) {
V_12 -> V_9 . V_64 = V_12 -> V_190 -> V_221 . V_64 ;
V_12 -> V_9 . V_68 = V_12 -> V_190 -> V_221 . V_68 ;
}
V_12 -> V_227 = true ;
V_146 = F_113 ( V_12 , V_112 , V_39 ) ;
V_12 -> V_227 = false ;
if ( ( V_146 == 'q' || V_146 == F_111 ( 'c' ) )
&& V_199 != - 2 && V_198 != - 2 )
goto V_225;
F_36 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_146 )
F_114 ( & V_2 -> V_3 ) ;
} else if ( V_173 == V_200 )
F_115 ( V_2 -> V_32 -> V_68 ) ;
else if ( V_173 == V_196 ) {
V_196:
if ( V_2 -> V_5 -> V_156 ) {
F_116 ( V_193 , & V_2 -> V_5 -> V_156 ) ;
V_216:
F_38 () ;
V_2 -> V_5 -> V_156 = NULL ;
V_228 . V_229 = false ;
} else {
if ( V_69 == NULL )
continue;
F_39 ( L_78 ,
V_69 -> V_222 ? L_71 : V_69 -> V_70 ) ;
V_2 -> V_5 -> V_156 = V_69 ;
V_228 . V_229 = true ;
F_117 ( V_193 , & V_2 -> V_5 -> V_156 ) ;
}
F_118 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_173 == V_197 ) {
V_197:
if ( V_2 -> V_5 -> V_157 ) {
F_116 ( V_193 , & V_2 -> V_5 -> V_157 ) ;
V_217:
F_38 () ;
V_2 -> V_5 -> V_157 = NULL ;
V_230 . V_229 = false ;
} else {
F_39 ( L_79 ,
V_154 -> V_163 ? V_154 -> V_164 : L_32 ,
V_154 -> V_165 ) ;
V_2 -> V_5 -> V_157 = V_154 ;
V_230 . V_229 = true ;
F_117 ( V_193 , & V_2 -> V_5 -> V_157 ) ;
}
F_119 ( V_5 ) ;
F_3 ( V_2 ) ;
}
else if ( V_173 == V_203 || V_173 == V_201 ||
V_173 == V_202 ) {
V_211:
memset ( V_194 , 0 , 64 ) ;
if ( V_173 == V_201 )
sprintf ( V_194 , L_80 , V_2 -> V_33 -> V_154 -> V_164 ) ;
if ( V_173 == V_202 )
sprintf ( V_194 , L_81 , V_2 -> V_33 -> V_9 . V_64 -> V_65 ) ;
F_120 ( V_194 ) ;
}
else if ( V_173 == V_204 ) {
V_212:
if ( ! F_94 () ) {
V_40 = V_231 ;
break;
} else
F_99 ( L_82
L_83 ) ;
}
}
V_207:
F_121 ( V_193 ) ;
V_59:
F_85 ( V_2 ) ;
F_92 ( V_166 , V_172 - 1 ) ;
return V_40 ;
}
static void F_122 ( struct V_36 * V_2 ,
void * V_128 , int V_74 )
{
struct V_232 * V_233 = F_67 ( V_2 ,
struct V_232 , V_3 ) ;
struct V_111 * V_112 = F_123 ( V_128 , struct V_111 , V_17 ) ;
bool V_105 = F_46 ( V_2 , V_74 ) ;
unsigned long V_49 = V_112 -> V_5 . V_47 . V_49 [ V_159 ] ;
const char * V_37 = F_124 ( V_112 ) ;
char V_60 [ 256 ] , V_155 ;
const char * V_234 = L_14 ;
T_1 V_63 ;
F_47 ( V_2 , V_105 ? V_94 :
V_93 ) ;
if ( F_88 ( V_112 ) ) {
struct V_111 * V_161 ;
V_37 = F_125 ( V_112 ) ;
F_90 (pos, evsel) {
V_49 += V_161 -> V_5 . V_47 . V_49 [ V_159 ] ;
}
}
V_49 = F_91 ( V_49 , & V_155 ) ;
V_63 = F_42 ( V_60 , sizeof( V_60 ) , L_84 , V_49 ,
V_155 , V_155 == ' ' ? L_32 : L_14 , V_37 ) ;
F_50 ( L_8 , V_60 ) ;
V_49 = V_112 -> V_5 . V_47 . V_49 [ V_50 ] ;
if ( V_49 != 0 ) {
V_233 -> V_235 = true ;
if ( ! V_105 )
F_47 ( V_2 , V_236 ) ;
V_49 = F_91 ( V_49 , & V_155 ) ;
V_63 += F_42 ( V_60 , sizeof( V_60 ) , L_85 ,
V_49 , V_155 , V_155 == ' ' ? L_32 : L_14 ) ;
V_234 = V_60 ;
}
F_49 ( V_234 , V_2 -> V_4 - V_63 ) ;
if ( V_105 )
V_233 -> V_32 = V_112 ;
}
static int F_126 ( struct V_232 * V_233 ,
int V_49 , const char * V_237 ,
struct V_38 * V_39 )
{
struct V_238 * V_239 = V_233 -> V_3 . V_240 ;
struct V_111 * V_161 ;
const char * V_37 , * V_41 = L_86 ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
int V_40 ;
if ( F_34 ( & V_233 -> V_3 , V_41 ,
L_87 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_233 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_44 :
V_39 -> V_45 ( V_39 -> V_46 ) ;
if ( ! V_233 -> V_241 && V_233 -> V_235 ) {
F_30 ( & V_233 -> V_3 ) ;
V_233 -> V_241 = true ;
}
continue;
case V_214 :
case V_58 :
if ( ! V_233 -> V_32 )
continue;
V_161 = V_233 -> V_32 ;
V_242:
F_127 ( V_239 , V_161 ) ;
if ( V_39 )
V_39 -> V_45 ( V_39 -> V_46 ) ;
V_37 = F_124 ( V_161 ) ;
V_40 = F_102 ( V_161 , V_49 , V_237 ,
V_37 , true , V_39 ,
V_233 -> V_189 ) ;
F_37 ( & V_233 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_205 :
if ( V_161 -> V_17 . V_27 == & V_239 -> V_35 )
V_161 = F_123 ( V_239 -> V_35 . V_27 , struct V_111 , V_17 ) ;
else
V_161 = F_123 ( V_161 -> V_17 . V_27 , struct V_111 , V_17 ) ;
goto V_242;
case V_206 :
if ( V_161 -> V_17 . V_243 == & V_239 -> V_35 )
V_161 = F_123 ( V_239 -> V_35 . V_243 , struct V_111 , V_17 ) ;
else
V_161 = F_123 ( V_161 -> V_17 . V_243 , struct V_111 , V_17 ) ;
goto V_242;
case V_218 :
if ( ! F_110 ( & V_233 -> V_3 ,
L_65 ) )
continue;
case V_231 :
case 'q' :
case F_111 ( 'c' ) :
goto V_59;
default:
continue;
}
case V_215 :
continue;
case V_218 :
if ( ! F_110 ( & V_233 -> V_3 ,
L_65 ) )
continue;
case 'q' :
case F_111 ( 'c' ) :
goto V_59;
default:
continue;
}
}
V_59:
F_40 ( & V_233 -> V_3 ) ;
return V_40 ;
}
static bool F_128 ( struct V_36 * T_7 V_244 ,
void * V_128 )
{
struct V_111 * V_112 = F_123 ( V_128 , struct V_111 , V_17 ) ;
if ( V_99 . V_108 && ! F_129 ( V_112 ) )
return true ;
return false ;
}
static int F_130 ( struct V_238 * V_239 ,
int V_6 , const char * V_237 ,
struct V_38 * V_39 ,
struct V_188 * V_189 )
{
struct V_111 * V_161 ;
struct V_232 V_233 = {
. V_3 = {
. V_35 = & V_239 -> V_35 ,
. V_43 = V_245 ,
. V_148 = V_246 ,
. V_247 = F_122 ,
. V_248 = F_128 ,
. V_6 = V_6 ,
. V_240 = V_239 ,
} ,
. V_189 = V_189 ,
} ;
F_104 ( L_88 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_124 ( V_161 ) ;
T_1 V_249 = strlen ( V_37 ) + 7 ;
if ( V_233 . V_3 . V_4 < V_249 )
V_233 . V_3 . V_4 = V_249 ;
}
return F_126 ( & V_233 , V_6 , V_237 , V_39 ) ;
}
int F_131 ( struct V_238 * V_239 , const char * V_237 ,
struct V_38 * V_39 ,
struct V_188 * V_189 )
{
int V_6 = V_239 -> V_6 ;
V_250:
if ( V_6 == 1 ) {
struct V_111 * V_25 = F_123 ( V_239 -> V_35 . V_27 ,
struct V_111 , V_17 ) ;
const char * V_37 = F_124 ( V_25 ) ;
return F_102 ( V_25 , V_6 , V_237 ,
V_37 , false , V_39 , V_189 ) ;
}
if ( V_99 . V_108 ) {
struct V_111 * V_161 ;
V_6 = 0 ;
F_14 (pos, &evlist->entries, node)
if ( F_129 ( V_161 ) )
V_6 ++ ;
if ( V_6 == 1 )
goto V_250;
}
return F_130 ( V_239 , V_6 , V_237 ,
V_39 , V_189 ) ;
}
