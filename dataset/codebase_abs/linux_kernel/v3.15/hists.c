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
if ( V_2 -> V_44 )
V_2 -> V_3 . V_6 = V_2 -> V_45 ;
F_1 ( V_2 ) ;
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
if ( F_34 ( & V_2 -> V_3 , V_41 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_2 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_46 : {
T_1 V_6 ;
V_39 -> V_47 ( V_39 -> V_48 ) ;
if ( V_2 -> V_44 ) {
F_36 ( V_2 ) ;
V_6 = V_2 -> V_45 ;
} else {
V_6 = V_2 -> V_5 -> V_6 ;
}
F_37 ( & V_2 -> V_3 , V_6 ) ;
if ( V_2 -> V_5 -> V_49 . V_50 !=
V_2 -> V_5 -> V_49 . V_51 [ V_52 ] ) {
V_2 -> V_5 -> V_49 . V_50 =
V_2 -> V_5 -> V_49 . V_51 [ V_52 ] ;
F_30 ( & V_2 -> V_3 ) ;
}
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
F_38 ( & V_2 -> V_3 , V_41 ) ;
continue;
}
case 'D' : {
static int V_53 ;
struct V_11 * V_54 = F_13 ( V_2 -> V_3 . V_55 ,
struct V_11 , V_19 ) ;
F_39 () ;
F_40 ( L_7 ,
V_53 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_56 ,
V_2 -> V_3 . V_57 ,
V_2 -> V_3 . V_58 ,
V_54 -> V_59 , V_54 -> V_34 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_60 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_61;
}
}
V_61:
F_41 ( & V_2 -> V_3 ) ;
return V_40 ;
}
static char * F_42 ( struct V_13 * V_14 ,
char * V_62 , T_2 V_63 , bool V_64 )
{
int V_65 ;
if ( V_14 -> V_9 . V_66 )
V_65 = F_43 ( V_62 , V_63 , L_8 , V_14 -> V_9 . V_66 -> V_67 ) ;
else
V_65 = F_43 ( V_62 , V_63 , L_9 V_68 , V_14 -> V_69 ) ;
if ( V_64 )
F_43 ( V_62 + V_65 , V_63 - V_65 , L_10 ,
V_14 -> V_9 . V_70 ? V_14 -> V_9 . V_70 -> V_71 -> V_72 : L_11 ) ;
return V_62 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_73 ,
T_1 V_74 , int V_75 ,
unsigned short V_76 ,
T_3 * V_59 ,
bool * V_77 )
{
struct V_19 * V_17 ;
int V_78 = V_76 , V_4 , V_79 = V_75 * V_80 ;
T_1 V_81 , V_82 ;
if ( V_83 . V_84 == V_85 )
V_81 = V_73 -> V_86 ;
else
V_81 = V_74 ;
V_82 = V_81 ;
V_17 = F_11 ( & V_73 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_1 V_87 = F_45 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_88 = 0 ;
V_82 -= V_87 ;
F_14 (chain, &child->val, list) {
char V_62 [ 1024 ] , * V_89 ;
const char * V_90 ;
int V_91 ;
bool V_92 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_88 = V_80 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_59 != 0 ) {
-- * V_59 ;
goto V_93;
}
V_89 = NULL ;
V_90 = F_42 ( V_23 , V_62 , sizeof( V_62 ) ,
V_2 -> V_64 ) ;
if ( V_92 ) {
double V_94 = V_87 * 100.0 / V_81 ;
if ( F_46 ( & V_89 , L_12 , V_94 , V_90 ) < 0 )
V_90 = L_13 ;
else
V_90 = V_89 ;
}
V_91 = V_95 ;
V_4 = V_2 -> V_3 . V_4 - ( V_79 + V_88 + 2 ) ;
if ( F_47 ( & V_2 -> V_3 , V_76 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_91 = V_96 ;
* V_77 = true ;
}
F_48 ( & V_2 -> V_3 , V_91 ) ;
F_49 ( & V_2 -> V_3 , V_76 , 0 ) ;
F_50 ( L_14 , V_79 + V_88 ) ;
F_51 ( L_15 , V_24 ) ;
F_50 ( V_90 , V_4 ) ;
free ( V_89 ) ;
if ( ++ V_76 == V_2 -> V_3 . V_56 )
goto V_61;
V_93:
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_97 = V_75 + ( V_88 ? 2 : 1 ) ;
V_76 += F_44 ( V_2 , V_22 , V_81 ,
V_97 , V_76 , V_59 ,
V_77 ) ;
}
if ( V_76 == V_2 -> V_3 . V_56 )
goto V_61;
V_17 = V_27 ;
}
V_61:
return V_76 - V_78 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_75 , unsigned short V_76 ,
T_3 * V_59 ,
bool * V_77 )
{
struct V_13 * V_23 ;
int V_78 = V_76 ,
V_79 = V_75 * V_80 ,
V_4 = V_2 -> V_3 . V_4 - V_79 ;
char V_24 = ' ' ;
F_14 (chain, &node->val, list) {
char V_62 [ 1024 ] , * V_98 ;
int V_91 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_59 != 0 ) {
-- * V_59 ;
continue;
}
V_91 = V_95 ;
if ( F_47 ( & V_2 -> V_3 , V_76 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_91 = V_96 ;
* V_77 = true ;
}
V_98 = F_42 ( V_23 , V_62 , sizeof( V_62 ) ,
V_2 -> V_64 ) ;
F_49 ( & V_2 -> V_3 , V_76 , 0 ) ;
F_48 ( & V_2 -> V_3 , V_91 ) ;
F_50 ( L_14 , V_79 ) ;
F_51 ( L_15 , V_24 ) ;
F_50 ( V_98 , V_4 - 2 ) ;
if ( ++ V_76 == V_2 -> V_3 . V_56 )
goto V_61;
}
if ( V_24 == '-' )
V_76 += F_44 ( V_2 , V_17 ,
V_2 -> V_5 -> V_49 . V_99 ,
V_75 + 1 , V_76 ,
V_59 ,
V_77 ) ;
V_61:
return V_76 - V_78 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
int V_75 , unsigned short V_76 ,
T_3 * V_59 ,
bool * V_77 )
{
struct V_19 * V_20 ;
int V_78 = V_76 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_76 += F_52 ( V_2 , V_17 , V_75 ,
V_76 , V_59 ,
V_77 ) ;
if ( V_76 == V_2 -> V_3 . V_56 )
break;
}
return V_76 - V_78 ;
}
static int F_54 ( struct V_100 * V_101 , bool V_102 )
{
struct V_103 * V_48 = V_101 -> V_104 ;
if ( V_48 -> V_105 && V_48 -> V_3 -> V_106 )
F_48 ( V_48 -> V_3 , V_96 ) ;
else
F_48 ( V_48 -> V_3 , V_95 ) ;
if ( V_102 ) {
if ( ! V_107 . V_108 )
return 0 ;
F_51 ( L_15 , V_48 -> V_24 ) ;
return 2 ;
}
return 0 ;
}
static int F_55 ( struct V_100 * V_101 , bool V_102 V_109 )
{
struct V_103 * V_48 = V_101 -> V_104 ;
if ( ! V_48 -> V_105 || ! V_48 -> V_3 -> V_106 )
F_48 ( V_48 -> V_3 , V_95 ) ;
return 0 ;
}
static int F_56 ( struct V_100 * V_101 , const char * V_110 , ... )
{
struct V_103 * V_48 = V_101 -> V_104 ;
int V_111 ;
T_4 args ;
double V_94 ;
va_start ( args , V_110 ) ;
V_94 = va_arg ( args , double ) ;
va_end ( args ) ;
F_57 ( V_48 -> V_3 , V_94 , V_48 -> V_105 ) ;
V_111 = F_43 ( V_101 -> V_112 , V_101 -> V_113 , V_110 , V_94 ) ;
F_51 ( L_8 , V_101 -> V_112 ) ;
F_58 ( V_101 , V_111 ) ;
return V_111 ;
}
void F_59 ( void )
{
F_60 () ;
V_114 [ V_115 ] . V_91 =
V_116 ;
V_114 [ V_117 ] . V_91 =
V_118 ;
V_114 [ V_119 ] . V_91 =
V_120 ;
V_114 [ V_121 ] . V_91 =
V_122 ;
V_114 [ V_123 ] . V_91 =
V_124 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_11 * V_125 ,
unsigned short V_76 )
{
char V_98 [ 256 ] ;
int V_65 = 0 ;
int V_4 = V_2 -> V_3 . V_4 ;
char V_24 = ' ' ;
bool V_105 = F_47 ( & V_2 -> V_3 , V_76 ) ;
T_3 V_59 = V_125 -> V_59 ;
bool V_25 = true ;
struct V_126 * V_110 ;
if ( V_105 ) {
V_2 -> V_33 = V_125 ;
V_2 -> V_32 = & V_125 -> V_9 ;
}
if ( V_107 . V_108 ) {
F_22 ( V_125 ) ;
V_24 = F_7 ( V_125 ) ;
}
if ( V_59 == 0 ) {
struct V_103 V_48 = {
. V_3 = & V_2 -> V_3 ,
. V_24 = V_24 ,
. V_105 = V_105 ,
} ;
struct V_100 V_101 = {
. V_112 = V_98 ,
. V_113 = sizeof( V_98 ) ,
. V_104 = & V_48 ,
} ;
F_49 ( & V_2 -> V_3 , V_76 , 0 ) ;
F_62 (fmt) {
if ( ! V_25 ) {
F_51 ( L_16 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_110 -> V_91 ) {
V_4 -= V_110 -> V_91 ( V_110 , & V_101 , V_125 ) ;
} else {
V_4 -= V_110 -> V_125 ( V_110 , & V_101 , V_125 ) ;
F_51 ( L_8 , V_98 ) ;
}
}
if ( ! V_2 -> V_3 . V_106 )
V_4 += 1 ;
F_63 ( V_125 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
F_50 ( V_98 , V_4 ) ;
++ V_76 ;
++ V_65 ;
} else
-- V_59 ;
if ( V_24 == '-' && V_76 != V_2 -> V_3 . V_56 ) {
V_65 += F_53 ( V_2 , & V_125 -> V_31 ,
1 , V_76 , & V_59 ,
& V_105 ) ;
if ( V_105 )
V_2 -> V_33 = V_125 ;
}
return V_65 ;
}
static void F_64 ( struct V_36 * V_2 )
{
if ( V_2 -> V_55 == NULL ) {
struct V_1 * V_127 ;
V_127 = F_65 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_55 = F_11 ( & V_127 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_66 ( struct V_36 * V_2 )
{
unsigned V_76 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_127 = F_65 ( V_2 , struct V_1 , V_3 ) ;
F_64 ( V_2 ) ;
for ( V_20 = V_2 -> V_55 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_128 . V_129 * 100.0 /
V_127 -> V_5 -> V_49 . V_99 ;
if ( V_54 -> V_130 )
continue;
if ( V_94 < V_127 -> V_44 )
continue;
V_76 += F_61 ( V_127 , V_54 , V_76 ) ;
if ( V_76 == V_2 -> V_56 )
break;
}
return V_76 ;
}
static struct V_19 * F_67 ( struct V_19 * V_20 ,
struct V_5 * V_5 ,
float V_44 )
{
while ( V_20 != NULL ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_128 . V_129 * 100.0 /
V_5 -> V_49 . V_99 ;
if ( V_94 < V_44 )
return NULL ;
if ( ! V_54 -> V_130 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_68 ( struct V_19 * V_20 ,
struct V_5 * V_5 ,
float V_44 )
{
while ( V_20 != NULL ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_128 . V_129 * 100.0 /
V_5 -> V_49 . V_99 ;
if ( ! V_54 -> V_130 && V_94 >= V_44 )
return V_20 ;
V_20 = F_69 ( V_20 ) ;
}
return NULL ;
}
static void F_70 ( struct V_36 * V_2 ,
T_3 V_79 , int V_131 )
{
struct V_11 * V_54 ;
struct V_19 * V_20 ;
bool V_25 = true ;
struct V_1 * V_127 ;
V_127 = F_65 ( V_2 , struct V_1 , V_3 ) ;
if ( V_2 -> V_6 == 0 )
return;
F_64 ( V_2 ) ;
switch ( V_131 ) {
case V_132 :
V_20 = F_67 ( F_11 ( V_2 -> V_35 ) ,
V_127 -> V_5 , V_127 -> V_44 ) ;
break;
case V_133 :
V_20 = V_2 -> V_55 ;
goto V_134;
case V_135 :
V_20 = F_68 ( F_71 ( V_2 -> V_35 ) ,
V_127 -> V_5 , V_127 -> V_44 ) ;
V_25 = false ;
break;
default:
return;
}
V_54 = F_13 ( V_2 -> V_55 , struct V_11 , V_19 ) ;
V_54 -> V_59 = 0 ;
V_134:
if ( V_79 > 0 ) {
do {
V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_54 -> V_9 . V_7 ) {
T_5 V_82 = V_54 -> V_34 - V_54 -> V_59 ;
if ( V_79 > V_82 ) {
V_79 -= V_82 ;
V_54 -> V_59 = 0 ;
} else {
V_54 -> V_59 += V_79 ;
V_79 = 0 ;
V_2 -> V_55 = V_20 ;
break;
}
}
V_20 = F_67 ( F_12 ( V_20 ) , V_127 -> V_5 ,
V_127 -> V_44 ) ;
if ( V_20 == NULL )
break;
-- V_79 ;
V_2 -> V_55 = V_20 ;
} while ( V_79 != 0 );
} else if ( V_79 < 0 ) {
while ( 1 ) {
V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_54 -> V_9 . V_7 ) {
if ( V_25 ) {
if ( - V_79 > V_54 -> V_59 ) {
V_79 += V_54 -> V_59 ;
V_54 -> V_59 = 0 ;
} else {
V_54 -> V_59 += V_79 ;
V_79 = 0 ;
V_2 -> V_55 = V_20 ;
break;
}
} else {
if ( - V_79 > V_54 -> V_34 ) {
V_79 += V_54 -> V_34 ;
V_54 -> V_59 = 0 ;
} else {
V_54 -> V_59 = V_54 -> V_34 + V_79 ;
V_79 = 0 ;
V_2 -> V_55 = V_20 ;
break;
}
}
}
V_20 = F_68 ( F_69 ( V_20 ) , V_127 -> V_5 ,
V_127 -> V_44 ) ;
if ( V_20 == NULL )
break;
++ V_79 ;
V_2 -> V_55 = V_20 ;
if ( V_79 == 0 ) {
V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_54 -> V_9 . V_7 )
V_54 -> V_59 = V_54 -> V_34 ;
break;
}
V_25 = false ;
}
} else {
V_2 -> V_55 = V_20 ;
V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_54 -> V_59 = 0 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_16 * V_73 ,
T_1 V_74 , int V_75 ,
T_6 * V_136 )
{
struct V_19 * V_17 ;
int V_79 = V_75 * V_80 ;
T_1 V_81 , V_82 ;
int V_65 = 0 ;
if ( V_83 . V_84 == V_85 )
V_81 = V_73 -> V_86 ;
else
V_81 = V_74 ;
V_82 = V_81 ;
V_17 = F_11 ( & V_73 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_1 V_87 = F_45 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_88 = 0 ;
V_82 -= V_87 ;
F_14 (chain, &child->val, list) {
char V_62 [ 1024 ] , * V_89 ;
const char * V_90 ;
bool V_92 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_88 = V_80 ;
V_24 = F_8 ( V_23 ) ;
V_89 = NULL ;
V_90 = F_42 ( V_23 , V_62 , sizeof( V_62 ) ,
V_2 -> V_64 ) ;
if ( V_92 ) {
double V_94 = V_87 * 100.0 / V_81 ;
if ( F_46 ( & V_89 , L_12 , V_94 , V_90 ) < 0 )
V_90 = L_13 ;
else
V_90 = V_89 ;
}
V_65 += fprintf ( V_136 , L_17 , V_79 + V_88 , L_14 , V_24 , V_90 ) ;
free ( V_89 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_97 = V_75 + ( V_88 ? 2 : 1 ) ;
V_65 += F_72 ( V_2 , V_22 , V_81 ,
V_97 , V_136 ) ;
}
V_17 = V_27 ;
}
return V_65 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_75 , T_6 * V_136 )
{
struct V_13 * V_23 ;
int V_79 = V_75 * V_80 ;
char V_24 = ' ' ;
int V_65 = 0 ;
F_14 (chain, &node->val, list) {
char V_62 [ 1024 ] , * V_98 ;
V_24 = F_8 ( V_23 ) ;
V_98 = F_42 ( V_23 , V_62 , sizeof( V_62 ) , V_2 -> V_64 ) ;
V_65 += fprintf ( V_136 , L_17 , V_79 , L_14 , V_24 , V_98 ) ;
}
if ( V_24 == '-' )
V_65 += F_72 ( V_2 , V_17 ,
V_2 -> V_5 -> V_49 . V_99 ,
V_75 + 1 , V_136 ) ;
return V_65 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_75 , T_6 * V_136 )
{
struct V_19 * V_20 ;
int V_65 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_65 += F_73 ( V_2 , V_17 , V_75 , V_136 ) ;
}
return V_65 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_6 * V_136 )
{
char V_98 [ 8192 ] ;
double V_94 ;
int V_65 = 0 ;
char V_24 = ' ' ;
if ( V_107 . V_108 )
V_24 = F_7 ( V_12 ) ;
F_63 ( V_12 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
V_94 = ( V_12 -> V_128 . V_129 * 100.0 ) / V_2 -> V_5 -> V_49 . V_99 ;
if ( V_107 . V_108 )
V_65 += fprintf ( V_136 , L_15 , V_24 ) ;
V_65 += fprintf ( V_136 , L_18 , V_94 ) ;
if ( V_107 . V_137 )
V_65 += fprintf ( V_136 , L_19 , V_12 -> V_128 . V_51 ) ;
if ( V_107 . V_138 )
V_65 += fprintf ( V_136 , L_20 V_139 , V_12 -> V_128 . V_129 ) ;
V_65 += fprintf ( V_136 , L_21 , F_76 ( V_98 ) ) ;
if ( V_24 == '-' )
V_65 += F_74 ( V_2 , & V_12 -> V_31 , 1 , V_136 ) ;
return V_65 ;
}
static int F_77 ( struct V_1 * V_2 , T_6 * V_136 )
{
struct V_19 * V_20 = F_67 ( F_11 ( V_2 -> V_3 . V_35 ) ,
V_2 -> V_5 ,
V_2 -> V_44 ) ;
int V_65 = 0 ;
while ( V_20 ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_65 += F_75 ( V_2 , V_54 , V_136 ) ;
V_20 = F_67 ( F_12 ( V_20 ) , V_2 -> V_5 ,
V_2 -> V_44 ) ;
}
return V_65 ;
}
static int F_78 ( struct V_1 * V_2 )
{
char V_140 [ 64 ] ;
T_6 * V_136 ;
while ( 1 ) {
F_43 ( V_140 , sizeof( V_140 ) , L_22 , V_2 -> V_141 ) ;
if ( F_79 ( V_140 , V_142 ) )
break;
if ( ++ V_2 -> V_141 == 8192 ) {
F_40 ( L_23 ) ;
return - 1 ;
}
}
V_136 = fopen ( V_140 , L_24 ) ;
if ( V_136 == NULL ) {
char V_62 [ 64 ] ;
const char * V_143 = F_80 ( V_144 , V_62 , sizeof( V_62 ) ) ;
F_40 ( L_25 , V_140 , V_143 ) ;
return - 1 ;
}
++ V_2 -> V_141 ;
F_77 ( V_2 , V_136 ) ;
fclose ( V_136 ) ;
F_40 ( L_26 , V_140 ) ;
return 0 ;
}
static struct V_1 * F_81 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_82 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_43 = F_66 ;
V_2 -> V_3 . V_145 = F_70 ;
V_2 -> V_3 . V_146 = true ;
}
return V_2 ;
}
static void F_83 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_84 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_147 * F_85 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_147 ;
}
static int F_33 ( struct V_5 * V_5 , char * V_62 , T_2 V_113 ,
const char * V_37 )
{
char V_148 ;
int V_65 ;
const struct V_71 * V_71 = V_5 -> V_149 ;
const struct V_147 * V_147 = V_5 -> V_150 ;
unsigned long V_151 = V_5 -> V_49 . V_51 [ V_152 ] ;
T_1 V_51 = V_5 -> V_49 . V_99 ;
struct V_153 * V_154 = F_86 ( V_5 ) ;
char V_112 [ 512 ] ;
T_2 V_155 = sizeof( V_112 ) ;
if ( F_87 ( V_154 ) ) {
struct V_153 * V_156 ;
F_88 ( V_154 , V_112 , V_155 ) ;
V_37 = V_112 ;
F_89 (pos, evsel) {
V_151 += V_156 -> V_5 . V_49 . V_51 [ V_152 ] ;
V_51 += V_156 -> V_5 . V_49 . V_99 ;
}
}
V_151 = F_90 ( V_151 , & V_148 ) ;
V_65 = F_43 ( V_62 , V_113 ,
L_27 ,
V_151 , V_148 , V_37 , V_51 ) ;
if ( V_5 -> V_157 )
V_65 += snprintf ( V_62 + V_65 , V_113 - V_65 ,
L_28 , V_5 -> V_157 ) ;
if ( V_147 )
V_65 += F_43 ( V_62 + V_65 , V_113 - V_65 ,
L_29 ,
( V_147 -> V_158 ? F_91 ( V_147 ) : L_30 ) ,
V_147 -> V_159 ) ;
if ( V_71 )
V_65 += F_43 ( V_62 + V_65 , V_113 - V_65 ,
L_31 , V_71 -> V_72 ) ;
return V_65 ;
}
static inline void F_92 ( char * * V_160 , int V_18 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_18 ; ++ V_161 )
F_93 ( & V_160 [ V_161 ] ) ;
}
static inline bool F_94 ( void * V_47 )
{
return V_47 == NULL ;
}
static int F_95 ( void )
{
char * V_162 , * V_160 [ 32 ] , * V_163 [ 32 ] , * V_164 ;
T_7 * V_165 ;
int V_166 = 0 , V_167 = - 1 , V_111 = - 1 ;
struct V_168 * V_169 ;
V_162 = getenv ( L_32 ) ;
if ( ! V_162 )
return V_111 ;
V_165 = F_96 ( V_162 ) ;
if ( ! V_165 )
return V_111 ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
memset ( V_160 , 0 , sizeof( V_163 ) ) ;
while ( ( V_169 = F_97 ( V_165 ) ) ) {
char V_170 [ V_171 ] ;
T_1 V_172 ;
char * V_67 = V_169 -> V_173 ;
T_6 * V_174 ;
if ( ! ( V_169 -> V_175 == V_176 ) )
continue;
snprintf ( V_170 , sizeof( V_170 ) , L_33 , V_162 , V_67 ) ;
V_174 = fopen ( V_170 , L_34 ) ;
if ( ! V_174 )
continue;
if ( fread ( & V_172 , 1 , 8 , V_174 ) < 8 )
goto V_177;
if ( F_98 ( V_172 ) ) {
V_160 [ V_166 ] = F_99 ( V_67 ) ;
if ( ! V_160 [ V_166 ] )
goto V_177;
V_163 [ V_166 ] = F_99 ( V_170 ) ;
if ( ! V_163 [ V_166 ] ) {
F_93 ( & V_160 [ V_166 ] ) ;
F_100 ( L_35 ) ;
fclose ( V_174 ) ;
break;
}
V_166 ++ ;
}
V_177:
fclose ( V_174 ) ;
if ( V_166 >= 32 ) {
F_100 ( L_36
L_37 ) ;
break;
}
}
F_101 ( V_165 ) ;
if ( V_166 ) {
V_167 = F_102 ( V_166 , V_160 ) ;
if ( V_167 < V_166 && V_167 >= 0 ) {
V_164 = F_99 ( V_163 [ V_167 ] ) ;
if ( V_164 ) {
if ( V_178 )
free ( ( void * ) V_179 ) ;
V_179 = V_164 ;
V_178 = true ;
V_111 = 0 ;
} else
F_100 ( L_38 ) ;
}
}
F_92 ( V_160 , V_166 ) ;
F_92 ( V_163 , V_166 ) ;
return V_111 ;
}
static void F_36 ( struct V_1 * V_127 )
{
T_1 V_6 = 0 ;
struct V_19 * V_20 = F_11 ( & V_127 -> V_5 -> V_35 ) ;
while ( V_20 ) {
V_6 ++ ;
V_20 = F_67 ( F_12 ( V_20 ) , V_127 -> V_5 ,
V_127 -> V_44 ) ;
}
V_127 -> V_45 = V_6 ;
}
static int F_103 ( struct V_153 * V_154 , int V_51 ,
const char * V_180 , const char * V_37 ,
bool V_181 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_182 * V_183 )
{
struct V_5 * V_5 = & V_154 -> V_5 ;
struct V_1 * V_2 = F_81 ( V_5 ) ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
char * V_160 [ 16 ] ;
int V_166 = 0 ;
int V_40 = - 1 ;
char V_112 [ 64 ] ;
char V_188 [ 64 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
#define F_104 \
"h/?/F1 Show this window\n" \
"UP/DOWN/PGUP\n" \
"PGDN/SPACE Navigate\n" \
"q/ESC/CTRL+C Exit browser\n\n" \
"For multiple event sessions:\n\n" \
"TAB/UNTAB Switch events\n\n" \
"For symbolic views (--sort has sym):\n\n" \
"-> Zoom into DSO/Threads & Annotate current symbol\n" \
"<- Zoom out\n" \
"a Annotate current symbol\n" \
"C Collapse all callchains\n" \
"d Zoom into current DSO\n" \
"E Expand all callchains\n" \
const char V_189 [] = F_104
L_39
L_40
L_41
L_42
L_43
L_44
L_45 ;
const char V_190 [] = F_104
L_40
L_43
L_44
L_45 ;
if ( V_2 == NULL )
return - 1 ;
if ( V_44 ) {
V_2 -> V_44 = V_44 ;
F_36 ( V_2 ) ;
}
V_187 = F_105 ( 2 ) ;
if ( V_187 == NULL )
goto V_61;
F_106 ( V_180 ) ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
while ( 1 ) {
const struct V_147 * V_147 = NULL ;
const struct V_71 * V_71 = NULL ;
int V_167 = 0 ,
V_191 = - 2 , V_192 = - 2 , V_193 = - 2 ,
V_194 = - 2 , V_195 = - 2 , V_196 = - 2 ;
int V_197 = - 2 , V_198 = - 2 ,
V_199 = - 2 , V_200 = - 2 ;
V_166 = 0 ;
V_40 = F_32 ( V_2 , V_37 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_147 = F_85 ( V_2 ) ;
V_71 = V_2 -> V_32 -> V_70 ? V_2 -> V_32 -> V_70 -> V_71 : NULL ;
}
switch ( V_40 ) {
case V_201 :
case V_202 :
if ( V_51 == 1 )
continue;
goto V_203;
case 'a' :
if ( ! V_204 ) {
F_31 ( & V_2 -> V_3 , V_42 * 2 ,
L_46
L_47 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_66 == NULL ||
V_2 -> V_32 -> V_70 -> V_71 -> V_205 )
continue;
goto V_206;
case 'P' :
F_78 ( V_2 ) ;
continue;
case 'd' :
goto V_192;
case 'V' :
V_2 -> V_64 = ! V_2 -> V_64 ;
continue;
case 't' :
goto V_193;
case '/' :
if ( F_107 ( L_48 ,
L_49 ,
V_112 , L_50 ,
V_42 * 2 ) == V_60 ) {
V_5 -> V_207 = * V_112 ? V_112 : NULL ;
F_108 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case 'r' :
if ( F_94 ( V_39 ) )
goto V_208;
continue;
case 's' :
if ( F_94 ( V_39 ) )
goto V_209;
continue;
case 'i' :
if ( V_183 -> V_210 )
F_109 ( V_183 ) ;
continue;
case V_211 :
case 'h' :
case '?' :
F_110 ( & V_2 -> V_3 ,
F_94 ( V_39 ) ? V_189 : V_190 ) ;
continue;
case V_60 :
case V_212 :
break;
case V_213 : {
const void * V_55 ;
if ( F_111 ( V_187 ) ) {
if ( V_181 )
goto V_203;
continue;
}
V_55 = F_112 ( V_187 ) ;
if ( V_55 == & V_2 -> V_5 -> V_149 )
goto V_214;
if ( V_55 == & V_2 -> V_5 -> V_150 )
goto V_215;
continue;
}
case V_216 :
if ( ! V_181 &&
! F_113 ( & V_2 -> V_3 ,
L_51 ) )
continue;
case 'q' :
case F_114 ( 'c' ) :
goto V_203;
default:
continue;
}
if ( ! V_204 )
goto V_217;
if ( V_218 == V_219 ) {
V_185 = V_2 -> V_33 -> V_184 ;
if ( V_2 -> V_32 != NULL &&
V_185 &&
V_185 -> V_220 . V_66 != NULL &&
! V_185 -> V_220 . V_70 -> V_71 -> V_205 &&
F_46 ( & V_160 [ V_166 ] , L_52 ,
V_185 -> V_220 . V_66 -> V_67 ) > 0 )
V_194 = V_166 ++ ;
if ( V_2 -> V_32 != NULL &&
V_185 &&
V_185 -> V_221 . V_66 != NULL &&
! V_185 -> V_221 . V_70 -> V_71 -> V_205 &&
( V_185 -> V_221 . V_66 != V_185 -> V_220 . V_66 ||
V_185 -> V_221 . V_70 -> V_71 != V_185 -> V_220 . V_70 -> V_71 ) &&
F_46 ( & V_160 [ V_166 ] , L_52 ,
V_185 -> V_221 . V_66 -> V_67 ) > 0 )
V_195 = V_166 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_66 != NULL &&
! V_2 -> V_32 -> V_70 -> V_71 -> V_205 &&
F_46 ( & V_160 [ V_166 ] , L_52 ,
V_2 -> V_32 -> V_66 -> V_67 ) > 0 )
V_191 = V_166 ++ ;
}
if ( V_147 != NULL &&
F_46 ( & V_160 [ V_166 ] , L_53 ,
( V_2 -> V_5 -> V_150 ? L_54 : L_55 ) ,
( V_147 -> V_158 ? F_91 ( V_147 ) : L_30 ) ,
V_147 -> V_159 ) > 0 )
V_193 = V_166 ++ ;
if ( V_71 != NULL &&
F_46 ( & V_160 [ V_166 ] , L_56 ,
( V_2 -> V_5 -> V_149 ? L_54 : L_55 ) ,
( V_71 -> V_222 ? L_57 : V_71 -> V_72 ) ) > 0 )
V_192 = V_166 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_70 != NULL &&
F_46 ( & V_160 [ V_166 ] , L_58 ) > 0 )
V_196 = V_166 ++ ;
if ( V_2 -> V_33 ) {
struct V_223 * V_66 ;
if ( F_46 ( & V_160 [ V_166 ] , L_59 ,
F_91 ( V_2 -> V_33 -> V_147 ) ) > 0 )
V_197 = V_166 ++ ;
V_66 = V_2 -> V_33 -> V_9 . V_66 ;
if ( V_66 && V_66 -> V_224 &&
F_46 ( & V_160 [ V_166 ] , L_60 ,
V_66 -> V_67 ) > 0 )
V_198 = V_166 ++ ;
}
if ( F_46 ( & V_160 [ V_166 ] , L_61 ) > 0 )
V_199 = V_166 ++ ;
if ( F_94 ( V_39 ) && F_46 ( & V_160 [ V_166 ] ,
L_62 ) > 0 )
V_200 = V_166 ++ ;
V_217:
V_160 [ V_166 ++ ] = ( char * ) L_63 ;
V_225:
V_167 = F_102 ( V_166 , V_160 ) ;
if ( V_167 == V_166 - 1 )
break;
if ( V_167 == - 1 ) {
F_92 ( V_160 , V_166 - 1 ) ;
continue;
}
if ( V_167 == V_191 || V_167 == V_195 || V_167 == V_194 ) {
struct V_11 * V_12 ;
int V_143 ;
V_206:
if ( ! V_226 && F_115 ( V_183 ) )
continue;
V_12 = F_84 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_167 == V_194 ) {
V_12 -> V_9 . V_66 = V_12 -> V_184 -> V_220 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_184 -> V_220 . V_70 ;
} else if ( V_167 == V_195 ) {
V_12 -> V_9 . V_66 = V_12 -> V_184 -> V_221 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_184 -> V_221 . V_70 ;
}
V_12 -> V_227 = true ;
V_143 = F_116 ( V_12 , V_154 , V_39 ) ;
V_12 -> V_227 = false ;
if ( ( V_143 == 'q' || V_143 == F_114 ( 'c' ) )
&& V_195 != - 2 && V_194 != - 2 )
goto V_225;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_143 )
F_117 ( & V_2 -> V_3 ) ;
} else if ( V_167 == V_196 )
F_118 ( V_2 -> V_32 -> V_70 ) ;
else if ( V_167 == V_192 ) {
V_192:
if ( V_2 -> V_5 -> V_149 ) {
F_119 ( V_187 , & V_2 -> V_5 -> V_149 ) ;
V_214:
F_39 () ;
V_2 -> V_5 -> V_149 = NULL ;
V_228 . V_229 = false ;
} else {
if ( V_71 == NULL )
continue;
F_40 ( L_64 ,
V_71 -> V_222 ? L_57 : V_71 -> V_72 ) ;
V_2 -> V_5 -> V_149 = V_71 ;
V_228 . V_229 = true ;
F_120 ( V_187 , & V_2 -> V_5 -> V_149 ) ;
}
F_121 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_167 == V_193 ) {
V_193:
if ( V_2 -> V_5 -> V_150 ) {
F_119 ( V_187 , & V_2 -> V_5 -> V_150 ) ;
V_215:
F_39 () ;
V_2 -> V_5 -> V_150 = NULL ;
V_230 . V_229 = false ;
} else {
F_40 ( L_65 ,
V_147 -> V_158 ? F_91 ( V_147 ) : L_30 ,
V_147 -> V_159 ) ;
V_2 -> V_5 -> V_150 = V_147 ;
V_230 . V_229 = true ;
F_120 ( V_187 , & V_2 -> V_5 -> V_150 ) ;
}
F_122 ( V_5 ) ;
F_3 ( V_2 ) ;
}
else if ( V_167 == V_199 || V_167 == V_197 ||
V_167 == V_198 ) {
V_208:
memset ( V_188 , 0 , 64 ) ;
if ( V_167 == V_197 )
sprintf ( V_188 , L_66 , F_91 ( V_2 -> V_33 -> V_147 ) ) ;
if ( V_167 == V_198 )
sprintf ( V_188 , L_67 , V_2 -> V_33 -> V_9 . V_66 -> V_67 ) ;
F_123 ( V_188 ) ;
}
else if ( V_167 == V_200 ) {
V_209:
if ( ! F_95 () ) {
V_40 = V_231 ;
break;
} else
F_100 ( L_68
L_69 ) ;
}
}
V_203:
F_124 ( V_187 ) ;
V_61:
F_83 ( V_2 ) ;
F_92 ( V_160 , V_166 - 1 ) ;
return V_40 ;
}
static void F_125 ( struct V_36 * V_2 ,
void * V_125 , int V_76 )
{
struct V_232 * V_233 = F_65 ( V_2 ,
struct V_232 , V_3 ) ;
struct V_153 * V_154 = F_126 ( V_125 , struct V_153 , V_17 ) ;
bool V_105 = F_47 ( V_2 , V_76 ) ;
unsigned long V_51 = V_154 -> V_5 . V_49 . V_51 [ V_152 ] ;
const char * V_37 = F_127 ( V_154 ) ;
char V_62 [ 256 ] , V_148 ;
const char * V_234 = L_14 ;
T_2 V_65 ;
F_48 ( V_2 , V_105 ? V_96 :
V_95 ) ;
if ( F_87 ( V_154 ) ) {
struct V_153 * V_156 ;
V_37 = F_128 ( V_154 ) ;
F_89 (pos, evsel) {
V_51 += V_156 -> V_5 . V_49 . V_51 [ V_152 ] ;
}
}
V_51 = F_90 ( V_51 , & V_148 ) ;
V_65 = F_43 ( V_62 , sizeof( V_62 ) , L_70 , V_51 ,
V_148 , V_148 == ' ' ? L_30 : L_14 , V_37 ) ;
F_51 ( L_8 , V_62 ) ;
V_51 = V_154 -> V_5 . V_49 . V_51 [ V_52 ] ;
if ( V_51 != 0 ) {
V_233 -> V_235 = true ;
if ( ! V_105 )
F_48 ( V_2 , V_236 ) ;
V_51 = F_90 ( V_51 , & V_148 ) ;
V_65 += F_43 ( V_62 , sizeof( V_62 ) , L_71 ,
V_51 , V_148 , V_148 == ' ' ? L_30 : L_14 ) ;
V_234 = V_62 ;
}
F_50 ( V_234 , V_2 -> V_4 - V_65 ) ;
if ( V_105 )
V_233 -> V_32 = V_154 ;
}
static int F_129 ( struct V_232 * V_233 ,
int V_51 , const char * V_237 ,
struct V_38 * V_39 )
{
struct V_238 * V_239 = V_233 -> V_3 . V_240 ;
struct V_153 * V_156 ;
const char * V_37 , * V_41 = L_72 ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
int V_40 ;
if ( F_34 ( & V_233 -> V_3 , V_41 ,
L_73 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_233 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_46 :
V_39 -> V_47 ( V_39 -> V_48 ) ;
if ( ! V_233 -> V_241 && V_233 -> V_235 ) {
F_30 ( & V_233 -> V_3 ) ;
V_233 -> V_241 = true ;
}
continue;
case V_212 :
case V_60 :
if ( ! V_233 -> V_32 )
continue;
V_156 = V_233 -> V_32 ;
V_242:
F_130 ( V_239 , V_156 ) ;
if ( V_39 )
V_39 -> V_47 ( V_39 -> V_48 ) ;
V_37 = F_127 ( V_156 ) ;
V_40 = F_103 ( V_156 , V_51 , V_237 ,
V_37 , true , V_39 ,
V_233 -> V_44 ,
V_233 -> V_183 ) ;
F_38 ( & V_233 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_201 :
if ( V_156 -> V_17 . V_27 == & V_239 -> V_35 )
V_156 = F_131 ( V_239 ) ;
else
V_156 = F_132 ( V_156 ) ;
goto V_242;
case V_202 :
if ( V_156 -> V_17 . V_243 == & V_239 -> V_35 )
V_156 = F_133 ( V_239 ) ;
else
V_156 = F_134 ( V_156 ) ;
goto V_242;
case V_216 :
if ( ! F_113 ( & V_233 -> V_3 ,
L_51 ) )
continue;
case V_231 :
case 'q' :
case F_114 ( 'c' ) :
goto V_61;
default:
continue;
}
case V_213 :
continue;
case V_216 :
if ( ! F_113 ( & V_233 -> V_3 ,
L_51 ) )
continue;
case 'q' :
case F_114 ( 'c' ) :
goto V_61;
default:
continue;
}
}
V_61:
F_41 ( & V_233 -> V_3 ) ;
return V_40 ;
}
static bool F_135 ( struct V_36 * V_2 V_109 ,
void * V_125 )
{
struct V_153 * V_154 = F_126 ( V_125 , struct V_153 , V_17 ) ;
if ( V_107 . V_244 && ! F_136 ( V_154 ) )
return true ;
return false ;
}
static int F_137 ( struct V_238 * V_239 ,
int V_6 , const char * V_237 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_182 * V_183 )
{
struct V_153 * V_156 ;
struct V_232 V_233 = {
. V_3 = {
. V_35 = & V_239 -> V_35 ,
. V_43 = V_245 ,
. V_145 = V_246 ,
. V_247 = F_125 ,
. V_248 = F_135 ,
. V_6 = V_6 ,
. V_240 = V_239 ,
} ,
. V_44 = V_44 ,
. V_183 = V_183 ,
} ;
F_106 ( L_74 ) ;
F_138 (evlist, pos) {
const char * V_37 = F_127 ( V_156 ) ;
T_2 V_249 = strlen ( V_37 ) + 7 ;
if ( V_233 . V_3 . V_4 < V_249 )
V_233 . V_3 . V_4 = V_249 ;
}
return F_129 ( & V_233 , V_6 , V_237 , V_39 ) ;
}
int F_139 ( struct V_238 * V_239 , const char * V_237 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_182 * V_183 )
{
int V_6 = V_239 -> V_6 ;
V_250:
if ( V_6 == 1 ) {
struct V_153 * V_25 = F_131 ( V_239 ) ;
const char * V_37 = F_127 ( V_25 ) ;
return F_103 ( V_25 , V_6 , V_237 ,
V_37 , false , V_39 , V_44 ,
V_183 ) ;
}
if ( V_107 . V_244 ) {
struct V_153 * V_156 ;
V_6 = 0 ;
F_138 (evlist, pos) {
if ( F_136 ( V_156 ) )
V_6 ++ ;
}
if ( V_6 == 1 )
goto V_250;
}
return F_137 ( V_239 , V_6 , V_237 ,
V_39 , V_44 , V_183 ) ;
}
