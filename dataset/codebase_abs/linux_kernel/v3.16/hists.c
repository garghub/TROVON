static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) || V_2 -> V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( F_1 ( V_2 ) )
V_5 = V_2 -> V_6 ;
else
V_5 = V_2 -> V_3 -> V_5 ;
return V_5 + V_2 -> V_7 ;
}
static void F_4 ( struct V_1 * V_8 )
{
V_8 -> V_9 . V_10 = 3 + ( F_5 ( V_8 -> V_3 ) +
sizeof( L_1 ) ) ;
}
static void F_6 ( struct V_1 * V_8 )
{
V_8 -> V_7 = 0 ;
F_7 ( V_8 ) ;
V_8 -> V_9 . V_5 = F_3 ( V_8 ) ;
F_4 ( V_8 ) ;
F_8 ( & V_8 -> V_9 ) ;
}
static char F_9 ( bool V_11 )
{
return V_11 ? '-' : '+' ;
}
static char F_10 ( const struct V_12 * V_13 )
{
return V_13 -> V_14 ? F_9 ( V_13 -> V_11 ) : ' ' ;
}
static char F_11 ( const struct V_15 * V_16 )
{
return F_10 ( & V_16 -> V_13 ) ;
}
static char F_12 ( const struct V_17 * V_18 )
{
return F_10 ( & V_18 -> V_13 ) ;
}
static void F_13 ( struct V_12 * V_13 , bool V_19 )
{
V_13 -> V_11 = V_19 ? V_13 -> V_14 : false ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_22 = 0 ;
struct V_23 * V_24 ;
for ( V_24 = F_15 ( & V_21 -> V_25 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_26 = F_17 ( V_24 , struct V_20 , V_23 ) ;
struct V_17 * V_27 ;
char V_28 = ' ' ;
F_18 (chain, &child->val, list) {
++ V_22 ;
V_28 = F_12 ( V_27 ) ;
if ( V_28 == '+' )
break;
}
if ( V_28 == '-' )
V_22 += F_14 ( V_26 ) ;
}
return V_22 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_17 * V_27 ;
bool V_11 = false ;
int V_22 = 0 ;
F_18 (chain, &node->val, list) {
++ V_22 ;
V_11 = V_27 -> V_13 . V_11 ;
}
if ( V_11 )
V_22 += F_14 ( V_21 ) ;
return V_22 ;
}
static int F_20 ( struct V_25 * V_27 )
{
struct V_23 * V_24 ;
int V_22 = 0 ;
for ( V_24 = F_15 ( V_27 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_21 = F_17 ( V_24 , struct V_20 , V_23 ) ;
V_22 += F_19 ( V_21 ) ;
}
return V_22 ;
}
static bool F_21 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return false ;
if ( ! V_13 -> V_14 )
return false ;
V_13 -> V_11 = ! V_13 -> V_11 ;
return true ;
}
static void F_22 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = F_15 ( & V_21 -> V_25 ) ;
for ( V_24 = F_15 ( & V_21 -> V_25 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_26 = F_17 ( V_24 , struct V_20 , V_23 ) ;
struct V_17 * V_27 ;
bool V_29 = true ;
F_18 (chain, &child->val, list) {
if ( V_29 ) {
V_29 = false ;
V_27 -> V_13 . V_14 = V_27 -> V_30 . V_31 != & V_26 -> V_32 ||
! F_23 ( & V_26 -> V_25 ) ;
} else
V_27 -> V_13 . V_14 = V_27 -> V_30 . V_31 == & V_26 -> V_32 &&
! F_23 ( & V_26 -> V_25 ) ;
}
F_22 ( V_26 ) ;
}
}
static void F_24 ( struct V_20 * V_21 )
{
struct V_17 * V_27 ;
F_18 (chain, &node->val, list)
V_27 -> V_13 . V_14 = ! F_23 ( & V_21 -> V_25 ) ;
F_22 ( V_21 ) ;
}
static void F_25 ( struct V_25 * V_33 )
{
struct V_23 * V_24 ;
for ( V_24 = F_15 ( V_33 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_21 = F_17 ( V_24 , struct V_20 , V_23 ) ;
F_24 ( V_21 ) ;
}
}
static void F_26 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_34 ) {
V_16 -> V_13 . V_14 = ! F_23 ( & V_16 -> V_35 ) ;
F_25 ( & V_16 -> V_35 ) ;
V_16 -> V_34 = true ;
}
}
static bool F_27 ( struct V_1 * V_8 )
{
if ( F_21 ( V_8 -> V_36 ) ) {
struct V_15 * V_16 = V_8 -> V_37 ;
F_26 ( V_16 ) ;
V_8 -> V_9 . V_5 -= V_16 -> V_38 ;
V_8 -> V_7 -= V_16 -> V_38 ;
if ( V_16 -> V_13 . V_11 )
V_16 -> V_38 = F_20 ( & V_16 -> V_35 ) ;
else
V_16 -> V_38 = 0 ;
V_8 -> V_9 . V_5 += V_16 -> V_38 ;
V_8 -> V_7 += V_16 -> V_38 ;
return true ;
}
return false ;
}
static int F_28 ( struct V_20 * V_21 , bool V_19 )
{
int V_22 = 0 ;
struct V_23 * V_24 ;
for ( V_24 = F_15 ( & V_21 -> V_25 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_26 = F_17 ( V_24 , struct V_20 , V_23 ) ;
struct V_17 * V_27 ;
bool V_14 = false ;
F_18 (chain, &child->val, list) {
++ V_22 ;
F_13 ( & V_27 -> V_13 , V_19 ) ;
V_14 = V_27 -> V_13 . V_14 ;
}
if ( V_14 )
V_22 += F_28 ( V_26 , V_19 ) ;
}
return V_22 ;
}
static int F_29 ( struct V_20 * V_21 , bool V_19 )
{
struct V_17 * V_27 ;
bool V_14 = false ;
int V_22 = 0 ;
F_18 (chain, &node->val, list) {
++ V_22 ;
F_13 ( & V_27 -> V_13 , V_19 ) ;
V_14 = V_27 -> V_13 . V_14 ;
}
if ( V_14 )
V_22 += F_28 ( V_21 , V_19 ) ;
return V_22 ;
}
static int F_30 ( struct V_25 * V_27 , bool V_19 )
{
struct V_23 * V_24 ;
int V_22 = 0 ;
for ( V_24 = F_15 ( V_27 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_21 = F_17 ( V_24 , struct V_20 , V_23 ) ;
V_22 += F_29 ( V_21 , V_19 ) ;
}
return V_22 ;
}
static void F_31 ( struct V_15 * V_16 , bool V_19 )
{
F_26 ( V_16 ) ;
F_13 ( & V_16 -> V_13 , V_19 ) ;
if ( V_16 -> V_13 . V_14 ) {
int V_22 = F_30 ( & V_16 -> V_35 , V_19 ) ;
V_16 -> V_38 = V_19 ? V_22 : 0 ;
} else
V_16 -> V_38 = 0 ;
}
static void
F_32 ( struct V_1 * V_8 , bool V_19 )
{
struct V_23 * V_24 ;
struct V_3 * V_3 = V_8 -> V_3 ;
for ( V_24 = F_15 ( & V_3 -> V_39 ) ;
( V_24 = F_33 ( V_24 , V_8 -> V_4 ) ) != NULL ;
V_24 = F_16 ( V_24 ) ) {
struct V_15 * V_16 = F_17 ( V_24 , struct V_15 , V_23 ) ;
F_31 ( V_16 , V_19 ) ;
V_8 -> V_7 += V_16 -> V_38 ;
}
}
static void F_34 ( struct V_1 * V_8 , bool V_19 )
{
V_8 -> V_7 = 0 ;
F_32 ( V_8 , V_19 ) ;
V_8 -> V_9 . V_5 = F_3 ( V_8 ) ;
F_8 ( & V_8 -> V_9 ) ;
}
static void F_35 ( struct V_40 * V_8 )
{
F_36 ( V_8 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_37 ( struct V_1 * V_8 , const char * V_41 ,
struct V_42 * V_43 )
{
int V_44 ;
char V_45 [ 160 ] ;
int V_46 = V_43 ? V_43 -> V_47 : 0 ;
V_8 -> V_9 . V_39 = & V_8 -> V_3 -> V_39 ;
V_8 -> V_9 . V_5 = F_3 ( V_8 ) ;
F_4 ( V_8 ) ;
F_38 ( V_8 -> V_3 , V_45 , sizeof( V_45 ) , V_41 ) ;
if ( F_39 ( & V_8 -> V_9 , V_45 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_44 = F_40 ( & V_8 -> V_9 , V_46 ) ;
switch ( V_44 ) {
case V_48 : {
T_2 V_5 ;
V_43 -> V_49 ( V_43 -> V_50 ) ;
if ( F_1 ( V_8 ) )
F_7 ( V_8 ) ;
V_5 = F_3 ( V_8 ) ;
F_41 ( & V_8 -> V_9 , V_5 ) ;
if ( V_8 -> V_3 -> V_51 . V_52 !=
V_8 -> V_3 -> V_51 . V_53 [ V_54 ] ) {
V_8 -> V_3 -> V_51 . V_52 =
V_8 -> V_3 -> V_51 . V_53 [ V_54 ] ;
F_35 ( & V_8 -> V_9 ) ;
}
F_38 ( V_8 -> V_3 , V_45 , sizeof( V_45 ) , V_41 ) ;
F_42 ( & V_8 -> V_9 , V_45 ) ;
continue;
}
case 'D' : {
static int V_55 ;
struct V_15 * V_56 = F_17 ( V_8 -> V_9 . V_57 ,
struct V_15 , V_23 ) ;
F_43 () ;
F_44 ( L_7 ,
V_55 ++ , V_8 -> V_9 . V_5 ,
V_8 -> V_3 -> V_5 ,
V_8 -> V_9 . V_58 ,
V_8 -> V_9 . V_59 ,
V_8 -> V_9 . V_60 ,
V_56 -> V_61 , V_56 -> V_38 ) ;
}
break;
case 'C' :
F_34 ( V_8 , false ) ;
break;
case 'E' :
F_34 ( V_8 , true ) ;
break;
case V_62 :
if ( F_27 ( V_8 ) )
break;
default:
goto V_63;
}
}
V_63:
F_45 ( & V_8 -> V_9 ) ;
return V_44 ;
}
static char * F_46 ( struct V_17 * V_18 ,
char * V_64 , T_3 V_65 , bool V_66 )
{
int V_67 ;
if ( V_18 -> V_13 . V_68 )
V_67 = F_47 ( V_64 , V_65 , L_8 , V_18 -> V_13 . V_68 -> V_69 ) ;
else
V_67 = F_47 ( V_64 , V_65 , L_9 V_70 , V_18 -> V_71 ) ;
if ( V_66 )
F_47 ( V_64 + V_67 , V_65 - V_67 , L_10 ,
V_18 -> V_13 . V_72 ? V_18 -> V_13 . V_72 -> V_73 -> V_74 : L_11 ) ;
return V_64 ;
}
static int F_48 ( struct V_1 * V_8 ,
struct V_20 * V_75 ,
T_2 V_76 , int V_77 ,
unsigned short V_78 ,
T_4 * V_61 ,
bool * V_79 )
{
struct V_23 * V_21 ;
int V_80 = V_78 , V_10 , V_81 = V_77 * V_82 ;
T_2 V_83 , V_84 ;
if ( V_85 . V_86 == V_87 )
V_83 = V_75 -> V_88 ;
else
V_83 = V_76 ;
V_84 = V_83 ;
V_21 = F_15 ( & V_75 -> V_25 ) ;
while ( V_21 ) {
struct V_20 * V_26 = F_17 ( V_21 , struct V_20 , V_23 ) ;
struct V_23 * V_31 = F_16 ( V_21 ) ;
T_2 V_89 = F_49 ( V_26 ) ;
struct V_17 * V_27 ;
char V_28 = ' ' ;
int V_29 = true ;
int V_90 = 0 ;
V_84 -= V_89 ;
F_18 (chain, &child->val, list) {
char V_64 [ 1024 ] , * V_91 ;
const char * V_92 ;
int V_93 ;
bool V_94 = V_29 ;
if ( V_29 )
V_29 = false ;
else
V_90 = V_82 ;
V_28 = F_12 ( V_27 ) ;
if ( * V_61 != 0 ) {
-- * V_61 ;
goto V_95;
}
V_91 = NULL ;
V_92 = F_46 ( V_27 , V_64 , sizeof( V_64 ) ,
V_8 -> V_66 ) ;
if ( V_94 ) {
double V_96 = V_89 * 100.0 / V_83 ;
if ( F_50 ( & V_91 , L_12 , V_96 , V_92 ) < 0 )
V_92 = L_13 ;
else
V_92 = V_91 ;
}
V_93 = V_97 ;
V_10 = V_8 -> V_9 . V_10 - ( V_81 + V_90 + 2 ) ;
if ( F_51 ( & V_8 -> V_9 , V_78 ) ) {
V_8 -> V_36 = & V_27 -> V_13 ;
V_93 = V_98 ;
* V_79 = true ;
}
F_52 ( & V_8 -> V_9 , V_93 ) ;
F_53 ( & V_8 -> V_9 , V_78 , 0 ) ;
F_54 ( L_14 , V_81 + V_90 ) ;
F_55 ( L_15 , V_28 ) ;
F_54 ( V_92 , V_10 ) ;
free ( V_91 ) ;
if ( ++ V_78 == V_8 -> V_9 . V_58 )
goto V_63;
V_95:
if ( V_28 == '+' )
break;
}
if ( V_28 == '-' ) {
const int V_99 = V_77 + ( V_90 ? 2 : 1 ) ;
V_78 += F_48 ( V_8 , V_26 , V_83 ,
V_99 , V_78 , V_61 ,
V_79 ) ;
}
if ( V_78 == V_8 -> V_9 . V_58 )
goto V_63;
V_21 = V_31 ;
}
V_63:
return V_78 - V_80 ;
}
static int F_56 ( struct V_1 * V_8 ,
struct V_20 * V_21 ,
int V_77 , unsigned short V_78 ,
T_4 * V_61 ,
bool * V_79 )
{
struct V_17 * V_27 ;
int V_80 = V_78 ,
V_81 = V_77 * V_82 ,
V_10 = V_8 -> V_9 . V_10 - V_81 ;
char V_28 = ' ' ;
F_18 (chain, &node->val, list) {
char V_64 [ 1024 ] , * V_100 ;
int V_93 ;
V_28 = F_12 ( V_27 ) ;
if ( * V_61 != 0 ) {
-- * V_61 ;
continue;
}
V_93 = V_97 ;
if ( F_51 ( & V_8 -> V_9 , V_78 ) ) {
V_8 -> V_36 = & V_27 -> V_13 ;
V_93 = V_98 ;
* V_79 = true ;
}
V_100 = F_46 ( V_27 , V_64 , sizeof( V_64 ) ,
V_8 -> V_66 ) ;
F_53 ( & V_8 -> V_9 , V_78 , 0 ) ;
F_52 ( & V_8 -> V_9 , V_93 ) ;
F_54 ( L_14 , V_81 ) ;
F_55 ( L_15 , V_28 ) ;
F_54 ( V_100 , V_10 - 2 ) ;
if ( ++ V_78 == V_8 -> V_9 . V_58 )
goto V_63;
}
if ( V_28 == '-' )
V_78 += F_48 ( V_8 , V_21 ,
V_8 -> V_3 -> V_51 . V_101 ,
V_77 + 1 , V_78 ,
V_61 ,
V_79 ) ;
V_63:
return V_78 - V_80 ;
}
static int F_57 ( struct V_1 * V_8 ,
struct V_25 * V_27 ,
int V_77 , unsigned short V_78 ,
T_4 * V_61 ,
bool * V_79 )
{
struct V_23 * V_24 ;
int V_80 = V_78 ;
for ( V_24 = F_15 ( V_27 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_21 = F_17 ( V_24 , struct V_20 , V_23 ) ;
V_78 += F_56 ( V_8 , V_21 , V_77 ,
V_78 , V_61 ,
V_79 ) ;
if ( V_78 == V_8 -> V_9 . V_58 )
break;
}
return V_78 - V_80 ;
}
static int F_58 ( struct V_102 * V_103 , const char * V_104 , ... )
{
struct V_105 * V_50 = V_103 -> V_106 ;
int V_107 ;
T_5 args ;
double V_96 ;
va_start ( args , V_104 ) ;
V_96 = va_arg ( args , double ) ;
va_end ( args ) ;
F_59 ( V_50 -> V_9 , V_96 , V_50 -> V_108 ) ;
V_107 = F_47 ( V_103 -> V_109 , V_103 -> V_110 , V_104 , V_96 ) ;
F_55 ( L_8 , V_103 -> V_109 ) ;
F_60 ( V_103 , V_107 ) ;
return V_107 ;
}
void F_61 ( void )
{
V_111 [ V_112 ] . V_93 =
V_113 ;
V_111 [ V_114 ] . V_93 =
V_115 ;
V_111 [ V_116 ] . V_93 =
V_117 ;
V_111 [ V_118 ] . V_93 =
V_119 ;
V_111 [ V_120 ] . V_93 =
V_121 ;
V_111 [ V_122 ] . V_93 =
V_123 ;
}
static int F_62 ( struct V_1 * V_8 ,
struct V_15 * V_124 ,
unsigned short V_78 )
{
char V_100 [ 256 ] ;
int V_67 = 0 ;
int V_10 = V_8 -> V_9 . V_10 ;
char V_28 = ' ' ;
bool V_108 = F_51 ( & V_8 -> V_9 , V_78 ) ;
T_4 V_61 = V_124 -> V_61 ;
bool V_29 = true ;
struct V_125 * V_104 ;
if ( V_108 ) {
V_8 -> V_37 = V_124 ;
V_8 -> V_36 = & V_124 -> V_13 ;
}
if ( V_126 . V_127 ) {
F_26 ( V_124 ) ;
V_28 = F_11 ( V_124 ) ;
}
if ( V_61 == 0 ) {
struct V_105 V_50 = {
. V_9 = & V_8 -> V_9 ,
. V_28 = V_28 ,
. V_108 = V_108 ,
} ;
struct V_102 V_103 = {
. V_109 = V_100 ,
. V_110 = sizeof( V_100 ) ,
. V_106 = & V_50 ,
} ;
F_53 ( & V_8 -> V_9 , V_78 , 0 ) ;
F_63 (fmt) {
if ( F_64 ( V_104 ) )
continue;
if ( V_108 && V_8 -> V_9 . V_128 ) {
F_52 ( & V_8 -> V_9 ,
V_98 ) ;
} else {
F_52 ( & V_8 -> V_9 ,
V_97 ) ;
}
if ( V_29 ) {
if ( V_126 . V_127 ) {
F_55 ( L_15 , V_28 ) ;
V_10 -= 2 ;
}
V_29 = false ;
} else {
F_55 ( L_16 ) ;
V_10 -= 2 ;
}
if ( V_104 -> V_93 ) {
V_10 -= V_104 -> V_93 ( V_104 , & V_103 , V_124 ) ;
} else {
V_10 -= V_104 -> V_124 ( V_104 , & V_103 , V_124 ) ;
F_55 ( L_8 , V_100 ) ;
}
}
if ( ! V_8 -> V_9 . V_128 )
V_10 += 1 ;
F_54 ( L_17 , V_10 ) ;
++ V_78 ;
++ V_67 ;
} else
-- V_61 ;
if ( V_28 == '-' && V_78 != V_8 -> V_9 . V_58 ) {
V_67 += F_57 ( V_8 , & V_124 -> V_35 ,
1 , V_78 , & V_61 ,
& V_108 ) ;
if ( V_108 )
V_8 -> V_37 = V_124 ;
}
return V_67 ;
}
static void F_65 ( struct V_40 * V_8 )
{
if ( V_8 -> V_57 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_66 ( V_8 , struct V_1 , V_9 ) ;
V_8 -> V_57 = F_15 ( & V_2 -> V_3 -> V_39 ) ;
}
}
static unsigned int F_67 ( struct V_40 * V_8 )
{
unsigned V_78 = 0 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = F_66 ( V_8 , struct V_1 , V_9 ) ;
F_65 ( V_8 ) ;
for ( V_24 = V_8 -> V_57 ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_15 * V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
float V_96 ;
if ( V_56 -> V_129 )
continue;
V_96 = F_68 ( V_56 ) ;
if ( V_96 < V_2 -> V_4 )
continue;
V_78 += F_62 ( V_2 , V_56 , V_78 ) ;
if ( V_78 == V_8 -> V_58 )
break;
}
return V_78 ;
}
static struct V_23 * F_33 ( struct V_23 * V_24 ,
float V_4 )
{
while ( V_24 != NULL ) {
struct V_15 * V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
float V_96 = F_68 ( V_56 ) ;
if ( ! V_56 -> V_129 && V_96 >= V_4 )
return V_24 ;
V_24 = F_16 ( V_24 ) ;
}
return NULL ;
}
static struct V_23 * F_69 ( struct V_23 * V_24 ,
float V_4 )
{
while ( V_24 != NULL ) {
struct V_15 * V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
float V_96 = F_68 ( V_56 ) ;
if ( ! V_56 -> V_129 && V_96 >= V_4 )
return V_24 ;
V_24 = F_70 ( V_24 ) ;
}
return NULL ;
}
static void F_71 ( struct V_40 * V_8 ,
T_4 V_81 , int V_130 )
{
struct V_15 * V_56 ;
struct V_23 * V_24 ;
bool V_29 = true ;
struct V_1 * V_2 ;
V_2 = F_66 ( V_8 , struct V_1 , V_9 ) ;
if ( V_8 -> V_5 == 0 )
return;
F_65 ( V_8 ) ;
switch ( V_130 ) {
case V_131 :
V_24 = F_33 ( F_15 ( V_8 -> V_39 ) ,
V_2 -> V_4 ) ;
break;
case V_132 :
V_24 = V_8 -> V_57 ;
goto V_133;
case V_134 :
V_24 = F_69 ( F_72 ( V_8 -> V_39 ) ,
V_2 -> V_4 ) ;
V_29 = false ;
break;
default:
return;
}
V_56 = F_17 ( V_8 -> V_57 , struct V_15 , V_23 ) ;
V_56 -> V_61 = 0 ;
V_133:
if ( V_81 > 0 ) {
do {
V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
if ( V_56 -> V_13 . V_11 ) {
T_6 V_84 = V_56 -> V_38 - V_56 -> V_61 ;
if ( V_81 > V_84 ) {
V_81 -= V_84 ;
V_56 -> V_61 = 0 ;
} else {
V_56 -> V_61 += V_81 ;
V_81 = 0 ;
V_8 -> V_57 = V_24 ;
break;
}
}
V_24 = F_33 ( F_16 ( V_24 ) , V_2 -> V_4 ) ;
if ( V_24 == NULL )
break;
-- V_81 ;
V_8 -> V_57 = V_24 ;
} while ( V_81 != 0 );
} else if ( V_81 < 0 ) {
while ( 1 ) {
V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
if ( V_56 -> V_13 . V_11 ) {
if ( V_29 ) {
if ( - V_81 > V_56 -> V_61 ) {
V_81 += V_56 -> V_61 ;
V_56 -> V_61 = 0 ;
} else {
V_56 -> V_61 += V_81 ;
V_81 = 0 ;
V_8 -> V_57 = V_24 ;
break;
}
} else {
if ( - V_81 > V_56 -> V_38 ) {
V_81 += V_56 -> V_38 ;
V_56 -> V_61 = 0 ;
} else {
V_56 -> V_61 = V_56 -> V_38 + V_81 ;
V_81 = 0 ;
V_8 -> V_57 = V_24 ;
break;
}
}
}
V_24 = F_69 ( F_70 ( V_24 ) ,
V_2 -> V_4 ) ;
if ( V_24 == NULL )
break;
++ V_81 ;
V_8 -> V_57 = V_24 ;
if ( V_81 == 0 ) {
V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
if ( V_56 -> V_13 . V_11 )
V_56 -> V_61 = V_56 -> V_38 ;
break;
}
V_29 = false ;
}
} else {
V_8 -> V_57 = V_24 ;
V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
V_56 -> V_61 = 0 ;
}
}
static int F_73 ( struct V_1 * V_8 ,
struct V_20 * V_75 ,
T_2 V_76 , int V_77 ,
T_7 * V_135 )
{
struct V_23 * V_21 ;
int V_81 = V_77 * V_82 ;
T_2 V_83 , V_84 ;
int V_67 = 0 ;
if ( V_85 . V_86 == V_87 )
V_83 = V_75 -> V_88 ;
else
V_83 = V_76 ;
V_84 = V_83 ;
V_21 = F_15 ( & V_75 -> V_25 ) ;
while ( V_21 ) {
struct V_20 * V_26 = F_17 ( V_21 , struct V_20 , V_23 ) ;
struct V_23 * V_31 = F_16 ( V_21 ) ;
T_2 V_89 = F_49 ( V_26 ) ;
struct V_17 * V_27 ;
char V_28 = ' ' ;
int V_29 = true ;
int V_90 = 0 ;
V_84 -= V_89 ;
F_18 (chain, &child->val, list) {
char V_64 [ 1024 ] , * V_91 ;
const char * V_92 ;
bool V_94 = V_29 ;
if ( V_29 )
V_29 = false ;
else
V_90 = V_82 ;
V_28 = F_12 ( V_27 ) ;
V_91 = NULL ;
V_92 = F_46 ( V_27 , V_64 , sizeof( V_64 ) ,
V_8 -> V_66 ) ;
if ( V_94 ) {
double V_96 = V_89 * 100.0 / V_83 ;
if ( F_50 ( & V_91 , L_12 , V_96 , V_92 ) < 0 )
V_92 = L_13 ;
else
V_92 = V_91 ;
}
V_67 += fprintf ( V_135 , L_18 , V_81 + V_90 , L_14 , V_28 , V_92 ) ;
free ( V_91 ) ;
if ( V_28 == '+' )
break;
}
if ( V_28 == '-' ) {
const int V_99 = V_77 + ( V_90 ? 2 : 1 ) ;
V_67 += F_73 ( V_8 , V_26 , V_83 ,
V_99 , V_135 ) ;
}
V_21 = V_31 ;
}
return V_67 ;
}
static int F_74 ( struct V_1 * V_8 ,
struct V_20 * V_21 ,
int V_77 , T_7 * V_135 )
{
struct V_17 * V_27 ;
int V_81 = V_77 * V_82 ;
char V_28 = ' ' ;
int V_67 = 0 ;
F_18 (chain, &node->val, list) {
char V_64 [ 1024 ] , * V_100 ;
V_28 = F_12 ( V_27 ) ;
V_100 = F_46 ( V_27 , V_64 , sizeof( V_64 ) , V_8 -> V_66 ) ;
V_67 += fprintf ( V_135 , L_18 , V_81 , L_14 , V_28 , V_100 ) ;
}
if ( V_28 == '-' )
V_67 += F_73 ( V_8 , V_21 ,
V_8 -> V_3 -> V_51 . V_101 ,
V_77 + 1 , V_135 ) ;
return V_67 ;
}
static int F_75 ( struct V_1 * V_8 ,
struct V_25 * V_27 , int V_77 , T_7 * V_135 )
{
struct V_23 * V_24 ;
int V_67 = 0 ;
for ( V_24 = F_15 ( V_27 ) ; V_24 ; V_24 = F_16 ( V_24 ) ) {
struct V_20 * V_21 = F_17 ( V_24 , struct V_20 , V_23 ) ;
V_67 += F_74 ( V_8 , V_21 , V_77 , V_135 ) ;
}
return V_67 ;
}
static int F_76 ( struct V_1 * V_8 ,
struct V_15 * V_16 , T_7 * V_135 )
{
char V_100 [ 8192 ] ;
int V_67 = 0 ;
char V_28 = ' ' ;
struct V_102 V_103 = {
. V_109 = V_100 ,
. V_110 = sizeof( V_100 ) ,
} ;
struct V_125 * V_104 ;
bool V_29 = true ;
int V_107 ;
if ( V_126 . V_127 )
V_28 = F_11 ( V_16 ) ;
if ( V_126 . V_127 )
V_67 += fprintf ( V_135 , L_15 , V_28 ) ;
F_63 (fmt) {
if ( F_64 ( V_104 ) )
continue;
if ( ! V_29 ) {
V_107 = F_47 ( V_103 . V_109 , V_103 . V_110 , L_16 ) ;
F_60 ( & V_103 , V_107 ) ;
} else
V_29 = false ;
V_107 = V_104 -> V_124 ( V_104 , & V_103 , V_16 ) ;
F_60 ( & V_103 , V_107 ) ;
}
V_67 += fprintf ( V_135 , L_19 , F_77 ( V_100 ) ) ;
if ( V_28 == '-' )
V_67 += F_75 ( V_8 , & V_16 -> V_35 , 1 , V_135 ) ;
return V_67 ;
}
static int F_78 ( struct V_1 * V_8 , T_7 * V_135 )
{
struct V_23 * V_24 = F_33 ( F_15 ( V_8 -> V_9 . V_39 ) ,
V_8 -> V_4 ) ;
int V_67 = 0 ;
while ( V_24 ) {
struct V_15 * V_56 = F_17 ( V_24 , struct V_15 , V_23 ) ;
V_67 += F_76 ( V_8 , V_56 , V_135 ) ;
V_24 = F_33 ( F_16 ( V_24 ) , V_8 -> V_4 ) ;
}
return V_67 ;
}
static int F_79 ( struct V_1 * V_8 )
{
char V_136 [ 64 ] ;
T_7 * V_135 ;
while ( 1 ) {
F_47 ( V_136 , sizeof( V_136 ) , L_20 , V_8 -> V_137 ) ;
if ( F_80 ( V_136 , V_138 ) )
break;
if ( ++ V_8 -> V_137 == 8192 ) {
F_44 ( L_21 ) ;
return - 1 ;
}
}
V_135 = fopen ( V_136 , L_22 ) ;
if ( V_135 == NULL ) {
char V_64 [ 64 ] ;
const char * V_139 = F_81 ( V_140 , V_64 , sizeof( V_64 ) ) ;
F_44 ( L_23 , V_136 , V_139 ) ;
return - 1 ;
}
++ V_8 -> V_137 ;
F_78 ( V_8 , V_135 ) ;
fclose ( V_135 ) ;
F_44 ( L_24 , V_136 ) ;
return 0 ;
}
static struct V_1 * F_82 ( struct V_3 * V_3 )
{
struct V_1 * V_8 = F_83 ( sizeof( * V_8 ) ) ;
if ( V_8 ) {
V_8 -> V_3 = V_3 ;
V_8 -> V_9 . V_47 = F_67 ;
V_8 -> V_9 . V_141 = F_71 ;
V_8 -> V_9 . V_142 = true ;
}
return V_8 ;
}
static void F_84 ( struct V_1 * V_8 )
{
free ( V_8 ) ;
}
static struct V_15 * F_85 ( struct V_1 * V_8 )
{
return V_8 -> V_37 ;
}
static struct V_143 * F_86 ( struct V_1 * V_8 )
{
return V_8 -> V_37 -> V_143 ;
}
static int F_38 ( struct V_3 * V_3 , char * V_64 , T_3 V_110 ,
const char * V_41 )
{
char V_144 ;
int V_67 ;
const struct V_73 * V_73 = V_3 -> V_145 ;
const struct V_143 * V_143 = V_3 -> V_146 ;
unsigned long V_147 = V_3 -> V_51 . V_53 [ V_148 ] ;
T_2 V_53 = V_3 -> V_51 . V_101 ;
struct V_149 * V_150 = F_87 ( V_3 ) ;
char V_109 [ 512 ] ;
T_3 V_151 = sizeof( V_109 ) ;
if ( V_126 . V_152 ) {
V_147 = V_3 -> V_51 . V_153 ;
V_53 = V_3 -> V_51 . V_154 ;
}
if ( F_88 ( V_150 ) ) {
struct V_149 * V_155 ;
F_89 ( V_150 , V_109 , V_151 ) ;
V_41 = V_109 ;
F_90 (pos, evsel) {
if ( V_126 . V_152 ) {
V_147 += V_155 -> V_3 . V_51 . V_153 ;
V_53 += V_155 -> V_3 . V_51 . V_154 ;
} else {
V_147 += V_155 -> V_3 . V_51 . V_53 [ V_148 ] ;
V_53 += V_155 -> V_3 . V_51 . V_101 ;
}
}
}
V_147 = F_91 ( V_147 , & V_144 ) ;
V_67 = F_47 ( V_64 , V_110 ,
L_25 ,
V_147 , V_144 , V_41 , V_53 ) ;
if ( V_3 -> V_156 )
V_67 += snprintf ( V_64 + V_67 , V_110 - V_67 ,
L_26 , V_3 -> V_156 ) ;
if ( V_143 )
V_67 += F_47 ( V_64 + V_67 , V_110 - V_67 ,
L_27 ,
( V_143 -> V_157 ? F_92 ( V_143 ) : L_17 ) ,
V_143 -> V_158 ) ;
if ( V_73 )
V_67 += F_47 ( V_64 + V_67 , V_110 - V_67 ,
L_28 , V_73 -> V_74 ) ;
return V_67 ;
}
static inline void F_93 ( char * * V_159 , int V_22 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_22 ; ++ V_160 )
F_94 ( & V_159 [ V_160 ] ) ;
}
static inline bool F_95 ( void * V_49 )
{
return V_49 == NULL ;
}
static int F_96 ( void )
{
char * V_161 , * V_159 [ 32 ] , * V_162 [ 32 ] , * V_163 ;
T_8 * V_164 ;
int V_165 = 0 , V_166 = - 1 , V_107 = - 1 ;
struct V_167 * V_168 ;
V_161 = getenv ( L_29 ) ;
if ( ! V_161 )
return V_107 ;
V_164 = F_97 ( V_161 ) ;
if ( ! V_164 )
return V_107 ;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
memset ( V_159 , 0 , sizeof( V_162 ) ) ;
while ( ( V_168 = F_98 ( V_164 ) ) ) {
char V_169 [ V_170 ] ;
T_2 V_171 ;
char * V_69 = V_168 -> V_172 ;
T_7 * V_173 ;
if ( ! ( V_168 -> V_174 == V_175 ) )
continue;
snprintf ( V_169 , sizeof( V_169 ) , L_30 , V_161 , V_69 ) ;
V_173 = fopen ( V_169 , L_31 ) ;
if ( ! V_173 )
continue;
if ( fread ( & V_171 , 1 , 8 , V_173 ) < 8 )
goto V_176;
if ( F_99 ( V_171 ) ) {
V_159 [ V_165 ] = F_100 ( V_69 ) ;
if ( ! V_159 [ V_165 ] )
goto V_176;
V_162 [ V_165 ] = F_100 ( V_169 ) ;
if ( ! V_162 [ V_165 ] ) {
F_94 ( & V_159 [ V_165 ] ) ;
F_101 ( L_32 ) ;
fclose ( V_173 ) ;
break;
}
V_165 ++ ;
}
V_176:
fclose ( V_173 ) ;
if ( V_165 >= 32 ) {
F_101 ( L_33
L_34 ) ;
break;
}
}
F_102 ( V_164 ) ;
if ( V_165 ) {
V_166 = F_103 ( V_165 , V_159 ) ;
if ( V_166 < V_165 && V_166 >= 0 ) {
V_163 = F_100 ( V_162 [ V_166 ] ) ;
if ( V_163 ) {
if ( V_177 )
free ( ( void * ) V_178 ) ;
V_178 = V_163 ;
V_177 = true ;
V_107 = 0 ;
} else
F_101 ( L_35 ) ;
}
}
F_93 ( V_159 , V_165 ) ;
F_93 ( V_162 , V_165 ) ;
return V_107 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
struct V_23 * V_24 = F_15 ( & V_2 -> V_3 -> V_39 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_6 = V_2 -> V_3 -> V_6 ;
return;
}
while ( ( V_24 = F_33 ( V_24 , V_2 -> V_4 ) ) != NULL ) {
V_5 ++ ;
V_24 = F_16 ( V_24 ) ;
}
V_2 -> V_6 = V_5 ;
}
static int F_104 ( struct V_149 * V_150 , int V_53 ,
const char * V_179 , const char * V_41 ,
bool V_180 ,
struct V_42 * V_43 ,
float V_4 ,
struct V_181 * V_182 )
{
struct V_3 * V_3 = & V_150 -> V_3 ;
struct V_1 * V_8 = F_82 ( V_3 ) ;
struct V_183 * V_184 ;
struct V_185 * V_186 ;
char * V_159 [ 16 ] ;
int V_165 = 0 ;
int V_44 = - 1 ;
char V_109 [ 64 ] ;
char V_187 [ 64 ] ;
int V_46 = V_43 ? V_43 -> V_47 : 0 ;
#define F_105 \
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
"F Toggle percentage of filtered entries\n" \
const char V_188 [] = F_105
L_36
L_37
L_38
L_39
L_40
L_41
L_42 ;
const char V_189 [] = F_105
L_37
L_40
L_41
L_42 ;
if ( V_8 == NULL )
return - 1 ;
if ( V_4 ) {
V_8 -> V_4 = V_4 ;
F_7 ( V_8 ) ;
}
V_186 = F_106 ( 2 ) ;
if ( V_186 == NULL )
goto V_63;
F_107 ( V_179 ) ;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
while ( 1 ) {
const struct V_143 * V_143 = NULL ;
const struct V_73 * V_73 = NULL ;
int V_166 = 0 ,
V_190 = - 2 , V_191 = - 2 , V_192 = - 2 ,
V_193 = - 2 , V_194 = - 2 , V_195 = - 2 ;
int V_196 = - 2 , V_197 = - 2 ,
V_198 = - 2 , V_199 = - 2 ;
V_165 = 0 ;
V_44 = F_37 ( V_8 , V_41 , V_43 ) ;
if ( V_8 -> V_37 != NULL ) {
V_143 = F_86 ( V_8 ) ;
V_73 = V_8 -> V_36 -> V_72 ? V_8 -> V_36 -> V_72 -> V_73 : NULL ;
}
switch ( V_44 ) {
case V_200 :
case V_201 :
if ( V_53 == 1 )
continue;
goto V_202;
case 'a' :
if ( ! V_203 ) {
F_36 ( & V_8 -> V_9 , V_46 * 2 ,
L_43
L_44 ) ;
continue;
}
if ( V_8 -> V_36 == NULL ||
V_8 -> V_36 -> V_68 == NULL ||
V_8 -> V_36 -> V_72 -> V_73 -> V_204 )
continue;
goto V_205;
case 'P' :
F_79 ( V_8 ) ;
continue;
case 'd' :
goto V_191;
case 'V' :
V_8 -> V_66 = ! V_8 -> V_66 ;
continue;
case 't' :
goto V_192;
case '/' :
if ( F_108 ( L_45 ,
L_46 ,
V_109 , L_47 ,
V_46 * 2 ) == V_62 ) {
V_3 -> V_206 = * V_109 ? V_109 : NULL ;
F_109 ( V_3 ) ;
F_6 ( V_8 ) ;
}
continue;
case 'r' :
if ( F_95 ( V_43 ) )
goto V_207;
continue;
case 's' :
if ( F_95 ( V_43 ) )
goto V_208;
continue;
case 'i' :
if ( V_182 -> V_209 )
F_110 ( V_182 ) ;
continue;
case 'F' :
V_126 . V_152 ^= 1 ;
continue;
case V_210 :
case 'h' :
case '?' :
F_111 ( & V_8 -> V_9 ,
F_95 ( V_43 ) ? V_188 : V_189 ) ;
continue;
case V_62 :
case V_211 :
break;
case V_212 : {
const void * V_57 ;
if ( F_112 ( V_186 ) ) {
if ( V_180 )
goto V_202;
continue;
}
V_57 = F_113 ( V_186 ) ;
if ( V_57 == & V_8 -> V_3 -> V_145 )
goto V_213;
if ( V_57 == & V_8 -> V_3 -> V_146 )
goto V_214;
continue;
}
case V_215 :
if ( ! V_180 &&
! F_114 ( & V_8 -> V_9 ,
L_48 ) )
continue;
case 'q' :
case F_115 ( 'c' ) :
goto V_202;
default:
continue;
}
if ( ! V_203 )
goto V_216;
if ( V_217 == V_218 ) {
V_184 = V_8 -> V_37 -> V_183 ;
if ( V_8 -> V_36 != NULL &&
V_184 &&
V_184 -> V_219 . V_68 != NULL &&
! V_184 -> V_219 . V_72 -> V_73 -> V_204 &&
F_50 ( & V_159 [ V_165 ] , L_49 ,
V_184 -> V_219 . V_68 -> V_69 ) > 0 )
V_193 = V_165 ++ ;
if ( V_8 -> V_36 != NULL &&
V_184 &&
V_184 -> V_220 . V_68 != NULL &&
! V_184 -> V_220 . V_72 -> V_73 -> V_204 &&
( V_184 -> V_220 . V_68 != V_184 -> V_219 . V_68 ||
V_184 -> V_220 . V_72 -> V_73 != V_184 -> V_219 . V_72 -> V_73 ) &&
F_50 ( & V_159 [ V_165 ] , L_49 ,
V_184 -> V_220 . V_68 -> V_69 ) > 0 )
V_194 = V_165 ++ ;
} else {
if ( V_8 -> V_36 != NULL &&
V_8 -> V_36 -> V_68 != NULL &&
! V_8 -> V_36 -> V_72 -> V_73 -> V_204 ) {
struct V_221 * V_222 ;
V_222 = F_116 ( V_8 -> V_36 -> V_68 ) ;
if ( V_222 -> V_223 &&
F_50 ( & V_159 [ V_165 ] , L_49 ,
V_8 -> V_36 -> V_68 -> V_69 ) > 0 )
V_190 = V_165 ++ ;
}
}
if ( V_143 != NULL &&
F_50 ( & V_159 [ V_165 ] , L_50 ,
( V_8 -> V_3 -> V_146 ? L_51 : L_52 ) ,
( V_143 -> V_157 ? F_92 ( V_143 ) : L_17 ) ,
V_143 -> V_158 ) > 0 )
V_192 = V_165 ++ ;
if ( V_73 != NULL &&
F_50 ( & V_159 [ V_165 ] , L_53 ,
( V_8 -> V_3 -> V_145 ? L_51 : L_52 ) ,
( V_73 -> V_224 ? L_54 : V_73 -> V_74 ) ) > 0 )
V_191 = V_165 ++ ;
if ( V_8 -> V_36 != NULL &&
V_8 -> V_36 -> V_72 != NULL &&
F_50 ( & V_159 [ V_165 ] , L_55 ) > 0 )
V_195 = V_165 ++ ;
if ( V_8 -> V_37 ) {
struct V_225 * V_68 ;
if ( F_50 ( & V_159 [ V_165 ] , L_56 ,
F_92 ( V_8 -> V_37 -> V_143 ) ) > 0 )
V_196 = V_165 ++ ;
V_68 = V_8 -> V_37 -> V_13 . V_68 ;
if ( V_68 && V_68 -> V_226 &&
F_50 ( & V_159 [ V_165 ] , L_57 ,
V_68 -> V_69 ) > 0 )
V_197 = V_165 ++ ;
}
if ( F_50 ( & V_159 [ V_165 ] , L_58 ) > 0 )
V_198 = V_165 ++ ;
if ( F_95 ( V_43 ) && F_50 ( & V_159 [ V_165 ] ,
L_59 ) > 0 )
V_199 = V_165 ++ ;
V_216:
V_159 [ V_165 ++ ] = ( char * ) L_60 ;
V_227:
V_166 = F_103 ( V_165 , V_159 ) ;
if ( V_166 == V_165 - 1 )
break;
if ( V_166 == - 1 ) {
F_93 ( V_159 , V_165 - 1 ) ;
continue;
}
if ( V_166 == V_190 || V_166 == V_194 || V_166 == V_193 ) {
struct V_15 * V_16 ;
struct V_221 * V_222 ;
int V_139 ;
V_205:
if ( ! V_228 && F_117 ( V_182 ) )
continue;
V_16 = F_85 ( V_8 ) ;
if ( V_16 == NULL )
continue;
if ( V_166 == V_193 ) {
V_16 -> V_13 . V_68 = V_16 -> V_183 -> V_219 . V_68 ;
V_16 -> V_13 . V_72 = V_16 -> V_183 -> V_219 . V_72 ;
} else if ( V_166 == V_194 ) {
V_16 -> V_13 . V_68 = V_16 -> V_183 -> V_220 . V_68 ;
V_16 -> V_13 . V_72 = V_16 -> V_183 -> V_220 . V_72 ;
}
V_222 = F_116 ( V_16 -> V_13 . V_68 ) ;
if ( ! V_222 -> V_223 )
continue;
V_16 -> V_229 = true ;
V_139 = F_118 ( V_16 , V_150 , V_43 ) ;
V_16 -> V_229 = false ;
if ( ( V_139 == 'q' || V_139 == F_115 ( 'c' ) )
&& V_194 != - 2 && V_193 != - 2 )
goto V_227;
F_41 ( & V_8 -> V_9 , V_8 -> V_3 -> V_5 ) ;
if ( V_139 )
F_119 ( & V_8 -> V_9 ) ;
} else if ( V_166 == V_195 )
F_120 ( V_8 -> V_36 -> V_72 ) ;
else if ( V_166 == V_191 ) {
V_191:
if ( V_8 -> V_3 -> V_145 ) {
F_121 ( V_186 , & V_8 -> V_3 -> V_145 ) ;
V_213:
F_43 () ;
V_8 -> V_3 -> V_145 = NULL ;
F_122 ( V_230 , false ) ;
} else {
if ( V_73 == NULL )
continue;
F_44 ( L_61 ,
V_73 -> V_224 ? L_54 : V_73 -> V_74 ) ;
V_8 -> V_3 -> V_145 = V_73 ;
F_122 ( V_230 , true ) ;
F_123 ( V_186 , & V_8 -> V_3 -> V_145 ) ;
}
F_124 ( V_3 ) ;
F_6 ( V_8 ) ;
} else if ( V_166 == V_192 ) {
V_192:
if ( V_8 -> V_3 -> V_146 ) {
F_121 ( V_186 , & V_8 -> V_3 -> V_146 ) ;
V_214:
F_43 () ;
V_8 -> V_3 -> V_146 = NULL ;
F_122 ( V_231 , false ) ;
} else {
F_44 ( L_62 ,
V_143 -> V_157 ? F_92 ( V_143 ) : L_17 ,
V_143 -> V_158 ) ;
V_8 -> V_3 -> V_146 = V_143 ;
F_122 ( V_231 , false ) ;
F_123 ( V_186 , & V_8 -> V_3 -> V_146 ) ;
}
F_125 ( V_3 ) ;
F_6 ( V_8 ) ;
}
else if ( V_166 == V_198 || V_166 == V_196 ||
V_166 == V_197 ) {
V_207:
memset ( V_187 , 0 , 64 ) ;
if ( V_166 == V_196 )
sprintf ( V_187 , L_63 , F_92 ( V_8 -> V_37 -> V_143 ) ) ;
if ( V_166 == V_197 )
sprintf ( V_187 , L_64 , V_8 -> V_37 -> V_13 . V_68 -> V_69 ) ;
F_126 ( V_187 ) ;
}
else if ( V_166 == V_199 ) {
V_208:
if ( ! F_96 () ) {
V_44 = V_232 ;
break;
} else
F_101 ( L_65
L_66 ) ;
}
}
V_202:
F_127 ( V_186 ) ;
V_63:
F_84 ( V_8 ) ;
F_93 ( V_159 , V_165 - 1 ) ;
return V_44 ;
}
static void F_128 ( struct V_40 * V_8 ,
void * V_124 , int V_78 )
{
struct V_233 * V_234 = F_66 ( V_8 ,
struct V_233 , V_9 ) ;
struct V_149 * V_150 = F_129 ( V_124 , struct V_149 , V_21 ) ;
bool V_108 = F_51 ( V_8 , V_78 ) ;
unsigned long V_53 = V_150 -> V_3 . V_51 . V_53 [ V_148 ] ;
const char * V_41 = F_130 ( V_150 ) ;
char V_64 [ 256 ] , V_144 ;
const char * V_235 = L_14 ;
T_3 V_67 ;
F_52 ( V_8 , V_108 ? V_98 :
V_97 ) ;
if ( F_88 ( V_150 ) ) {
struct V_149 * V_155 ;
V_41 = F_131 ( V_150 ) ;
F_90 (pos, evsel) {
V_53 += V_155 -> V_3 . V_51 . V_53 [ V_148 ] ;
}
}
V_53 = F_91 ( V_53 , & V_144 ) ;
V_67 = F_47 ( V_64 , sizeof( V_64 ) , L_67 , V_53 ,
V_144 , V_144 == ' ' ? L_17 : L_14 , V_41 ) ;
F_55 ( L_8 , V_64 ) ;
V_53 = V_150 -> V_3 . V_51 . V_53 [ V_54 ] ;
if ( V_53 != 0 ) {
V_234 -> V_236 = true ;
if ( ! V_108 )
F_52 ( V_8 , V_237 ) ;
V_53 = F_91 ( V_53 , & V_144 ) ;
V_67 += F_47 ( V_64 , sizeof( V_64 ) , L_68 ,
V_53 , V_144 , V_144 == ' ' ? L_17 : L_14 ) ;
V_235 = V_64 ;
}
F_54 ( V_235 , V_8 -> V_10 - V_67 ) ;
if ( V_108 )
V_234 -> V_36 = V_150 ;
}
static int F_132 ( struct V_233 * V_234 ,
int V_53 , const char * V_238 ,
struct V_42 * V_43 )
{
struct V_239 * V_240 = V_234 -> V_9 . V_241 ;
struct V_149 * V_155 ;
const char * V_41 , * V_45 = L_69 ;
int V_46 = V_43 ? V_43 -> V_47 : 0 ;
int V_44 ;
if ( F_39 ( & V_234 -> V_9 , V_45 ,
L_70 ) < 0 )
return - 1 ;
while ( 1 ) {
V_44 = F_40 ( & V_234 -> V_9 , V_46 ) ;
switch ( V_44 ) {
case V_48 :
V_43 -> V_49 ( V_43 -> V_50 ) ;
if ( ! V_234 -> V_242 && V_234 -> V_236 ) {
F_35 ( & V_234 -> V_9 ) ;
V_234 -> V_242 = true ;
}
continue;
case V_211 :
case V_62 :
if ( ! V_234 -> V_36 )
continue;
V_155 = V_234 -> V_36 ;
V_243:
F_133 ( V_240 , V_155 ) ;
if ( V_43 )
V_43 -> V_49 ( V_43 -> V_50 ) ;
V_41 = F_130 ( V_155 ) ;
V_44 = F_104 ( V_155 , V_53 , V_238 ,
V_41 , true , V_43 ,
V_234 -> V_4 ,
V_234 -> V_182 ) ;
F_42 ( & V_234 -> V_9 , V_45 ) ;
switch ( V_44 ) {
case V_200 :
if ( V_155 -> V_21 . V_31 == & V_240 -> V_39 )
V_155 = F_134 ( V_240 ) ;
else
V_155 = F_135 ( V_155 ) ;
goto V_243;
case V_201 :
if ( V_155 -> V_21 . V_244 == & V_240 -> V_39 )
V_155 = F_136 ( V_240 ) ;
else
V_155 = F_137 ( V_155 ) ;
goto V_243;
case V_215 :
if ( ! F_114 ( & V_234 -> V_9 ,
L_48 ) )
continue;
case V_232 :
case 'q' :
case F_115 ( 'c' ) :
goto V_63;
default:
continue;
}
case V_212 :
continue;
case V_215 :
if ( ! F_114 ( & V_234 -> V_9 ,
L_48 ) )
continue;
case 'q' :
case F_115 ( 'c' ) :
goto V_63;
default:
continue;
}
}
V_63:
F_45 ( & V_234 -> V_9 ) ;
return V_44 ;
}
static bool F_138 ( struct V_40 * V_8 V_245 ,
void * V_124 )
{
struct V_149 * V_150 = F_129 ( V_124 , struct V_149 , V_21 ) ;
if ( V_126 . V_246 && ! F_139 ( V_150 ) )
return true ;
return false ;
}
static int F_140 ( struct V_239 * V_240 ,
int V_5 , const char * V_238 ,
struct V_42 * V_43 ,
float V_4 ,
struct V_181 * V_182 )
{
struct V_149 * V_155 ;
struct V_233 V_234 = {
. V_9 = {
. V_39 = & V_240 -> V_39 ,
. V_47 = V_247 ,
. V_141 = V_248 ,
. V_249 = F_128 ,
. V_250 = F_138 ,
. V_5 = V_5 ,
. V_241 = V_240 ,
} ,
. V_4 = V_4 ,
. V_182 = V_182 ,
} ;
F_107 ( L_71 ) ;
F_141 (evlist, pos) {
const char * V_41 = F_130 ( V_155 ) ;
T_3 V_251 = strlen ( V_41 ) + 7 ;
if ( V_234 . V_9 . V_10 < V_251 )
V_234 . V_9 . V_10 = V_251 ;
}
return F_132 ( & V_234 , V_5 , V_238 , V_43 ) ;
}
int F_142 ( struct V_239 * V_240 , const char * V_238 ,
struct V_42 * V_43 ,
float V_4 ,
struct V_181 * V_182 )
{
int V_5 = V_240 -> V_5 ;
V_252:
if ( V_5 == 1 ) {
struct V_149 * V_29 = F_134 ( V_240 ) ;
const char * V_41 = F_130 ( V_29 ) ;
return F_104 ( V_29 , V_5 , V_238 ,
V_41 , false , V_43 , V_4 ,
V_182 ) ;
}
if ( V_126 . V_246 ) {
struct V_149 * V_155 ;
V_5 = 0 ;
F_141 (evlist, pos) {
if ( F_139 ( V_155 ) )
V_5 ++ ;
}
if ( V_5 == 1 )
goto V_252;
}
return F_140 ( V_240 , V_5 , V_238 ,
V_43 , V_4 , V_182 ) ;
}
