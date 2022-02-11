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
static void F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 ;
T_2 V_11 = V_2 -> V_12 ? 1 : 0 , V_13 ;
V_9 -> V_14 = V_9 -> V_15 - V_11 ;
V_13 = V_9 -> V_16 - V_9 -> V_17 ;
if ( V_13 >= V_9 -> V_14 )
V_9 -> V_16 -= V_13 - V_9 -> V_14 + 1 ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
V_9 -> V_18 = 3 + ( F_7 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_8 ( V_9 ) ;
F_4 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_9 , int V_19 , int V_20 )
{
T_2 V_11 = V_9 -> V_12 ? 1 : 0 ;
F_10 ( & V_9 -> V_10 , V_19 + V_11 , V_20 ) ;
}
static void F_11 ( struct V_1 * V_9 )
{
V_9 -> V_7 = 0 ;
F_12 ( V_9 ) ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_5 ( & V_9 -> V_10 ) ;
F_13 ( & V_9 -> V_10 ) ;
}
static char F_14 ( bool V_21 )
{
return V_21 ? '-' : '+' ;
}
static char F_15 ( const struct V_22 * V_23 )
{
return V_23 -> V_24 ? F_14 ( V_23 -> V_21 ) : ' ' ;
}
static char F_16 ( const struct V_25 * V_26 )
{
return F_15 ( & V_26 -> V_23 ) ;
}
static char F_17 ( const struct V_27 * V_28 )
{
return F_15 ( & V_28 -> V_23 ) ;
}
static void F_18 ( struct V_22 * V_23 , bool V_29 )
{
V_23 -> V_21 = V_29 ? V_23 -> V_24 : false ;
}
static int F_19 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
struct V_33 * V_34 ;
for ( V_34 = F_20 ( & V_31 -> V_35 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_36 = F_22 ( V_34 , struct V_30 , V_33 ) ;
struct V_27 * V_37 ;
char V_38 = ' ' ;
F_23 (chain, &child->val, list) {
++ V_32 ;
V_38 = F_17 ( V_37 ) ;
if ( V_38 == '+' )
break;
}
if ( V_38 == '-' )
V_32 += F_19 ( V_36 ) ;
}
return V_32 ;
}
static int F_24 ( struct V_30 * V_31 )
{
struct V_27 * V_37 ;
bool V_21 = false ;
int V_32 = 0 ;
F_23 (chain, &node->val, list) {
++ V_32 ;
V_21 = V_37 -> V_23 . V_21 ;
}
if ( V_21 )
V_32 += F_19 ( V_31 ) ;
return V_32 ;
}
static int F_25 ( struct V_35 * V_37 )
{
struct V_33 * V_34 ;
int V_32 = 0 ;
for ( V_34 = F_20 ( V_37 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
V_32 += F_24 ( V_31 ) ;
}
return V_32 ;
}
static bool F_26 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return false ;
if ( ! V_23 -> V_24 )
return false ;
V_23 -> V_21 = ! V_23 -> V_21 ;
return true ;
}
static void F_27 ( struct V_30 * V_31 )
{
struct V_33 * V_34 = F_20 ( & V_31 -> V_35 ) ;
for ( V_34 = F_20 ( & V_31 -> V_35 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_36 = F_22 ( V_34 , struct V_30 , V_33 ) ;
struct V_27 * V_37 ;
bool V_39 = true ;
F_23 (chain, &child->val, list) {
if ( V_39 ) {
V_39 = false ;
V_37 -> V_23 . V_24 = V_37 -> V_40 . V_41 != & V_36 -> V_42 ||
! F_28 ( & V_36 -> V_35 ) ;
} else
V_37 -> V_23 . V_24 = V_37 -> V_40 . V_41 == & V_36 -> V_42 &&
! F_28 ( & V_36 -> V_35 ) ;
}
F_27 ( V_36 ) ;
}
}
static void F_29 ( struct V_30 * V_31 )
{
struct V_27 * V_37 ;
F_23 (chain, &node->val, list)
V_37 -> V_23 . V_24 = ! F_28 ( & V_31 -> V_35 ) ;
F_27 ( V_31 ) ;
}
static void F_30 ( struct V_35 * V_43 )
{
struct V_33 * V_34 ;
for ( V_34 = F_20 ( V_43 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
F_29 ( V_31 ) ;
}
}
static void F_31 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_44 ) {
V_26 -> V_23 . V_24 = ! F_28 ( & V_26 -> V_45 ) ;
F_30 ( & V_26 -> V_45 ) ;
V_26 -> V_44 = true ;
}
}
static bool F_32 ( struct V_1 * V_9 )
{
if ( F_26 ( V_9 -> V_46 ) ) {
struct V_25 * V_26 = V_9 -> V_47 ;
F_31 ( V_26 ) ;
V_9 -> V_10 . V_5 -= V_26 -> V_48 ;
V_9 -> V_7 -= V_26 -> V_48 ;
if ( V_26 -> V_23 . V_21 )
V_26 -> V_48 = F_25 ( & V_26 -> V_45 ) ;
else
V_26 -> V_48 = 0 ;
V_9 -> V_10 . V_5 += V_26 -> V_48 ;
V_9 -> V_7 += V_26 -> V_48 ;
return true ;
}
return false ;
}
static int F_33 ( struct V_30 * V_31 , bool V_29 )
{
int V_32 = 0 ;
struct V_33 * V_34 ;
for ( V_34 = F_20 ( & V_31 -> V_35 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_36 = F_22 ( V_34 , struct V_30 , V_33 ) ;
struct V_27 * V_37 ;
bool V_24 = false ;
F_23 (chain, &child->val, list) {
++ V_32 ;
F_18 ( & V_37 -> V_23 , V_29 ) ;
V_24 = V_37 -> V_23 . V_24 ;
}
if ( V_24 )
V_32 += F_33 ( V_36 , V_29 ) ;
}
return V_32 ;
}
static int F_34 ( struct V_30 * V_31 , bool V_29 )
{
struct V_27 * V_37 ;
bool V_24 = false ;
int V_32 = 0 ;
F_23 (chain, &node->val, list) {
++ V_32 ;
F_18 ( & V_37 -> V_23 , V_29 ) ;
V_24 = V_37 -> V_23 . V_24 ;
}
if ( V_24 )
V_32 += F_33 ( V_31 , V_29 ) ;
return V_32 ;
}
static int F_35 ( struct V_35 * V_37 , bool V_29 )
{
struct V_33 * V_34 ;
int V_32 = 0 ;
for ( V_34 = F_20 ( V_37 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
V_32 += F_34 ( V_31 , V_29 ) ;
}
return V_32 ;
}
static void F_36 ( struct V_25 * V_26 , bool V_29 )
{
F_31 ( V_26 ) ;
F_18 ( & V_26 -> V_23 , V_29 ) ;
if ( V_26 -> V_23 . V_24 ) {
int V_32 = F_35 ( & V_26 -> V_45 , V_29 ) ;
V_26 -> V_48 = V_29 ? V_32 : 0 ;
} else
V_26 -> V_48 = 0 ;
}
static void
F_37 ( struct V_1 * V_9 , bool V_29 )
{
struct V_33 * V_34 ;
struct V_3 * V_3 = V_9 -> V_3 ;
for ( V_34 = F_20 ( & V_3 -> V_49 ) ;
( V_34 = F_38 ( V_34 , V_9 -> V_4 ) ) != NULL ;
V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_26 = F_22 ( V_34 , struct V_25 , V_33 ) ;
F_36 ( V_26 , V_29 ) ;
V_9 -> V_7 += V_26 -> V_48 ;
}
}
static void F_39 ( struct V_1 * V_9 , bool V_29 )
{
V_9 -> V_7 = 0 ;
F_37 ( V_9 , V_29 ) ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_13 ( & V_9 -> V_10 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_41 ( V_9 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_42 ( struct V_1 * V_9 ,
struct V_50 * V_51 )
{
int V_52 ;
char V_53 [ 160 ] ;
int V_54 = V_51 ? V_51 -> V_55 : 0 ;
V_9 -> V_10 . V_49 = & V_9 -> V_3 -> V_49 ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_43 ( V_9 -> V_3 , V_53 , sizeof( V_53 ) ) ;
if ( F_44 ( & V_9 -> V_10 , V_53 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_52 = F_45 ( & V_9 -> V_10 , V_54 ) ;
switch ( V_52 ) {
case V_56 : {
T_3 V_5 ;
V_51 -> V_57 ( V_51 -> V_58 ) ;
if ( F_1 ( V_9 ) )
F_12 ( V_9 ) ;
V_5 = F_3 ( V_9 ) ;
F_46 ( & V_9 -> V_10 , V_5 ) ;
if ( V_9 -> V_3 -> V_59 . V_60 !=
V_9 -> V_3 -> V_59 . V_61 [ V_62 ] ) {
V_9 -> V_3 -> V_59 . V_60 =
V_9 -> V_3 -> V_59 . V_61 [ V_62 ] ;
F_40 ( & V_9 -> V_10 ) ;
}
F_43 ( V_9 -> V_3 , V_53 , sizeof( V_53 ) ) ;
F_47 ( & V_9 -> V_10 , V_53 ) ;
continue;
}
case 'D' : {
static int V_63 ;
struct V_25 * V_64 = F_22 ( V_9 -> V_10 . V_65 ,
struct V_25 , V_33 ) ;
F_48 () ;
F_49 ( L_7 ,
V_63 ++ , V_9 -> V_10 . V_5 ,
V_9 -> V_3 -> V_5 ,
V_9 -> V_10 . V_14 ,
V_9 -> V_10 . V_16 ,
V_9 -> V_10 . V_17 ,
V_64 -> V_66 , V_64 -> V_48 ) ;
}
break;
case 'C' :
F_39 ( V_9 , false ) ;
break;
case 'E' :
F_39 ( V_9 , true ) ;
break;
case 'H' :
V_9 -> V_12 = ! V_9 -> V_12 ;
F_4 ( V_9 ) ;
break;
case V_67 :
if ( F_32 ( V_9 ) )
break;
default:
goto V_68;
}
}
V_68:
F_50 ( & V_9 -> V_10 ) ;
return V_52 ;
}
static char * F_51 ( struct V_27 * V_28 ,
char * V_69 , T_4 V_70 , bool V_71 )
{
int V_72 ;
if ( V_28 -> V_23 . V_73 )
V_72 = F_52 ( V_69 , V_70 , L_8 , V_28 -> V_23 . V_73 -> V_74 ) ;
else
V_72 = F_52 ( V_69 , V_70 , L_9 V_75 , V_28 -> V_76 ) ;
if ( V_71 )
F_52 ( V_69 + V_72 , V_70 - V_72 , L_10 ,
V_28 -> V_23 . V_77 ? V_28 -> V_23 . V_77 -> V_78 -> V_79 : L_11 ) ;
return V_69 ;
}
static int F_53 ( struct V_1 * V_9 ,
struct V_30 * V_80 ,
T_3 V_81 , int V_82 ,
unsigned short V_19 ,
T_5 * V_66 ,
bool * V_83 )
{
struct V_33 * V_31 ;
int V_84 = V_19 , V_18 , V_85 = V_82 * V_86 ;
T_3 V_87 , V_88 ;
if ( V_89 . V_90 == V_91 )
V_87 = V_80 -> V_92 ;
else
V_87 = V_81 ;
V_88 = V_87 ;
V_31 = F_20 ( & V_80 -> V_35 ) ;
while ( V_31 ) {
struct V_30 * V_36 = F_22 ( V_31 , struct V_30 , V_33 ) ;
struct V_33 * V_41 = F_21 ( V_31 ) ;
T_3 V_93 = F_54 ( V_36 ) ;
struct V_27 * V_37 ;
char V_38 = ' ' ;
int V_39 = true ;
int V_94 = 0 ;
V_88 -= V_93 ;
F_23 (chain, &child->val, list) {
char V_69 [ 1024 ] , * V_95 ;
const char * V_96 ;
int V_97 ;
bool V_98 = V_39 ;
if ( V_39 )
V_39 = false ;
else
V_94 = V_86 ;
V_38 = F_17 ( V_37 ) ;
if ( * V_66 != 0 ) {
-- * V_66 ;
goto V_99;
}
V_95 = NULL ;
V_96 = F_51 ( V_37 , V_69 , sizeof( V_69 ) ,
V_9 -> V_71 ) ;
if ( V_98 ) {
double V_100 = V_93 * 100.0 / V_87 ;
if ( F_55 ( & V_95 , L_12 , V_100 , V_96 ) < 0 )
V_96 = L_13 ;
else
V_96 = V_95 ;
}
V_97 = V_101 ;
V_18 = V_9 -> V_10 . V_18 - ( V_85 + V_94 + 2 ) ;
if ( F_56 ( & V_9 -> V_10 , V_19 ) ) {
V_9 -> V_46 = & V_37 -> V_23 ;
V_97 = V_102 ;
* V_83 = true ;
}
F_57 ( & V_9 -> V_10 , V_97 ) ;
F_9 ( V_9 , V_19 , 0 ) ;
F_58 ( L_14 , V_85 + V_94 ) ;
F_59 ( L_15 , V_38 ) ;
F_58 ( V_96 , V_18 ) ;
free ( V_95 ) ;
if ( ++ V_19 == V_9 -> V_10 . V_14 )
goto V_68;
V_99:
if ( V_38 == '+' )
break;
}
if ( V_38 == '-' ) {
const int V_103 = V_82 + ( V_94 ? 2 : 1 ) ;
V_19 += F_53 ( V_9 , V_36 , V_87 ,
V_103 , V_19 , V_66 ,
V_83 ) ;
}
if ( V_19 == V_9 -> V_10 . V_14 )
goto V_68;
V_31 = V_41 ;
}
V_68:
return V_19 - V_84 ;
}
static int F_60 ( struct V_1 * V_9 ,
struct V_30 * V_31 ,
int V_82 , unsigned short V_19 ,
T_5 * V_66 ,
bool * V_83 )
{
struct V_27 * V_37 ;
int V_84 = V_19 ,
V_85 = V_82 * V_86 ,
V_18 = V_9 -> V_10 . V_18 - V_85 ;
char V_38 = ' ' ;
F_23 (chain, &node->val, list) {
char V_69 [ 1024 ] , * V_104 ;
int V_97 ;
V_38 = F_17 ( V_37 ) ;
if ( * V_66 != 0 ) {
-- * V_66 ;
continue;
}
V_97 = V_101 ;
if ( F_56 ( & V_9 -> V_10 , V_19 ) ) {
V_9 -> V_46 = & V_37 -> V_23 ;
V_97 = V_102 ;
* V_83 = true ;
}
V_104 = F_51 ( V_37 , V_69 , sizeof( V_69 ) ,
V_9 -> V_71 ) ;
F_9 ( V_9 , V_19 , 0 ) ;
F_57 ( & V_9 -> V_10 , V_97 ) ;
F_58 ( L_14 , V_85 ) ;
F_59 ( L_15 , V_38 ) ;
F_58 ( V_104 , V_18 - 2 ) ;
if ( ++ V_19 == V_9 -> V_10 . V_14 )
goto V_68;
}
if ( V_38 == '-' )
V_19 += F_53 ( V_9 , V_31 ,
V_9 -> V_3 -> V_59 . V_105 ,
V_82 + 1 , V_19 ,
V_66 ,
V_83 ) ;
V_68:
return V_19 - V_84 ;
}
static int F_61 ( struct V_1 * V_9 ,
struct V_35 * V_37 ,
int V_82 , unsigned short V_19 ,
T_5 * V_66 ,
bool * V_83 )
{
struct V_33 * V_34 ;
int V_84 = V_19 ;
for ( V_34 = F_20 ( V_37 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
V_19 += F_60 ( V_9 , V_31 , V_82 ,
V_19 , V_66 ,
V_83 ) ;
if ( V_19 == V_9 -> V_10 . V_14 )
break;
}
return V_19 - V_84 ;
}
static int F_62 ( struct V_106 * V_107 , const char * V_108 , ... )
{
struct V_109 * V_58 = V_107 -> V_110 ;
int V_111 ;
T_6 args ;
double V_100 ;
va_start ( args , V_108 ) ;
V_100 = va_arg ( args , double ) ;
va_end ( args ) ;
F_63 ( V_58 -> V_10 , V_100 , V_58 -> V_112 ) ;
V_111 = F_52 ( V_107 -> V_113 , V_107 -> V_114 , V_108 , V_100 ) ;
F_59 ( L_8 , V_107 -> V_113 ) ;
F_64 ( V_107 , V_111 ) ;
return V_111 ;
}
void F_65 ( void )
{
V_115 [ V_116 ] . V_97 =
V_117 ;
V_115 [ V_118 ] . V_97 =
V_119 ;
V_115 [ V_120 ] . V_97 =
V_121 ;
V_115 [ V_122 ] . V_97 =
V_123 ;
V_115 [ V_124 ] . V_97 =
V_125 ;
V_115 [ V_126 ] . V_97 =
V_127 ;
}
static int F_66 ( struct V_1 * V_9 ,
struct V_25 * V_128 ,
unsigned short V_19 )
{
char V_104 [ 256 ] ;
int V_72 = 0 ;
int V_18 = V_9 -> V_10 . V_18 ;
char V_38 = ' ' ;
bool V_112 = F_56 ( & V_9 -> V_10 , V_19 ) ;
T_5 V_66 = V_128 -> V_66 ;
bool V_39 = true ;
struct V_129 * V_108 ;
if ( V_112 ) {
V_9 -> V_47 = V_128 ;
V_9 -> V_46 = & V_128 -> V_23 ;
}
if ( V_130 . V_131 ) {
F_31 ( V_128 ) ;
V_38 = F_16 ( V_128 ) ;
}
if ( V_66 == 0 ) {
struct V_109 V_58 = {
. V_10 = & V_9 -> V_10 ,
. V_38 = V_38 ,
. V_112 = V_112 ,
} ;
struct V_106 V_107 = {
. V_113 = V_104 ,
. V_114 = sizeof( V_104 ) ,
. V_110 = & V_58 ,
} ;
F_9 ( V_9 , V_19 , 0 ) ;
F_67 (fmt) {
if ( F_68 ( V_108 ) )
continue;
if ( V_112 && V_9 -> V_10 . V_132 ) {
F_57 ( & V_9 -> V_10 ,
V_102 ) ;
} else {
F_57 ( & V_9 -> V_10 ,
V_101 ) ;
}
if ( V_39 ) {
if ( V_130 . V_131 ) {
F_59 ( L_15 , V_38 ) ;
V_18 -= 2 ;
}
V_39 = false ;
} else {
F_59 ( L_16 ) ;
V_18 -= 2 ;
}
if ( V_108 -> V_97 ) {
V_18 -= V_108 -> V_97 ( V_108 , & V_107 , V_128 ) ;
} else {
V_18 -= V_108 -> V_128 ( V_108 , & V_107 , V_128 ) ;
F_59 ( L_8 , V_104 ) ;
}
}
if ( ! V_9 -> V_10 . V_132 )
V_18 += 1 ;
F_58 ( L_17 , V_18 ) ;
++ V_19 ;
++ V_72 ;
} else
-- V_66 ;
if ( V_38 == '-' && V_19 != V_9 -> V_10 . V_14 ) {
V_72 += F_61 ( V_9 , & V_128 -> V_45 ,
1 , V_19 , & V_66 ,
& V_112 ) ;
if ( V_112 )
V_9 -> V_47 = V_128 ;
}
return V_72 ;
}
static int F_69 ( struct V_106 * V_107 , int V_133 )
{
F_64 ( V_107 , V_133 ) ;
return V_107 -> V_114 <= 0 ;
}
static int F_70 ( char * V_113 , T_4 V_114 , struct V_3 * V_3 )
{
struct V_106 V_134 = {
. V_113 = V_113 ,
. V_114 = V_114 ,
} ;
struct V_129 * V_108 ;
T_4 V_111 = 0 ;
if ( V_130 . V_131 ) {
V_111 = F_52 ( V_113 , V_114 , L_16 ) ;
if ( F_69 ( & V_134 , V_111 ) )
return V_111 ;
}
F_67 (fmt) {
if ( F_68 ( V_108 ) )
continue;
F_71 ( V_108 , V_3 ) ;
V_111 = V_108 -> V_135 ( V_108 , & V_134 , F_72 ( V_3 ) ) ;
if ( F_69 ( & V_134 , V_111 ) )
break;
V_111 = F_52 ( V_134 . V_113 , V_134 . V_114 , L_16 ) ;
if ( F_69 ( & V_134 , V_111 ) )
break;
}
return V_111 ;
}
static void F_73 ( struct V_1 * V_9 )
{
char V_136 [ 1024 ] ;
F_70 ( V_136 , sizeof( V_136 ) , V_9 -> V_3 ) ;
F_10 ( & V_9 -> V_10 , 0 , 0 ) ;
F_57 ( & V_9 -> V_10 , V_137 ) ;
F_58 ( V_136 , V_9 -> V_10 . V_18 + 1 ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
if ( V_9 -> V_65 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
V_9 -> V_65 = F_20 ( & V_2 -> V_3 -> V_49 ) ;
}
}
static unsigned int F_75 ( struct V_8 * V_9 )
{
unsigned V_19 = 0 ;
T_2 V_11 = 0 ;
struct V_33 * V_34 ;
struct V_1 * V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
if ( V_2 -> V_12 ) {
F_73 ( V_2 ) ;
V_11 = 1 ;
}
F_74 ( V_9 ) ;
for ( V_34 = V_9 -> V_65 ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_100 ;
if ( V_64 -> V_138 )
continue;
V_100 = F_76 ( V_64 ) ;
if ( V_100 < V_2 -> V_4 )
continue;
V_19 += F_66 ( V_2 , V_64 , V_19 ) ;
if ( V_19 == V_9 -> V_14 )
break;
}
return V_19 + V_11 ;
}
static struct V_33 * F_38 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_100 = F_76 ( V_64 ) ;
if ( ! V_64 -> V_138 && V_100 >= V_4 )
return V_34 ;
V_34 = F_21 ( V_34 ) ;
}
return NULL ;
}
static struct V_33 * F_77 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_100 = F_76 ( V_64 ) ;
if ( ! V_64 -> V_138 && V_100 >= V_4 )
return V_34 ;
V_34 = F_78 ( V_34 ) ;
}
return NULL ;
}
static void F_79 ( struct V_8 * V_9 ,
T_5 V_85 , int V_139 )
{
struct V_25 * V_64 ;
struct V_33 * V_34 ;
bool V_39 = true ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
if ( V_9 -> V_5 == 0 )
return;
F_74 ( V_9 ) ;
switch ( V_139 ) {
case V_140 :
V_34 = F_38 ( F_20 ( V_9 -> V_49 ) ,
V_2 -> V_4 ) ;
break;
case V_141 :
V_34 = V_9 -> V_65 ;
goto V_142;
case V_143 :
V_34 = F_77 ( F_80 ( V_9 -> V_49 ) ,
V_2 -> V_4 ) ;
V_39 = false ;
break;
default:
return;
}
V_64 = F_22 ( V_9 -> V_65 , struct V_25 , V_33 ) ;
V_64 -> V_66 = 0 ;
V_142:
if ( V_85 > 0 ) {
do {
V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_64 -> V_23 . V_21 ) {
T_2 V_88 = V_64 -> V_48 - V_64 -> V_66 ;
if ( V_85 > V_88 ) {
V_85 -= V_88 ;
V_64 -> V_66 = 0 ;
} else {
V_64 -> V_66 += V_85 ;
V_85 = 0 ;
V_9 -> V_65 = V_34 ;
break;
}
}
V_34 = F_38 ( F_21 ( V_34 ) , V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
-- V_85 ;
V_9 -> V_65 = V_34 ;
} while ( V_85 != 0 );
} else if ( V_85 < 0 ) {
while ( 1 ) {
V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_64 -> V_23 . V_21 ) {
if ( V_39 ) {
if ( - V_85 > V_64 -> V_66 ) {
V_85 += V_64 -> V_66 ;
V_64 -> V_66 = 0 ;
} else {
V_64 -> V_66 += V_85 ;
V_85 = 0 ;
V_9 -> V_65 = V_34 ;
break;
}
} else {
if ( - V_85 > V_64 -> V_48 ) {
V_85 += V_64 -> V_48 ;
V_64 -> V_66 = 0 ;
} else {
V_64 -> V_66 = V_64 -> V_48 + V_85 ;
V_85 = 0 ;
V_9 -> V_65 = V_34 ;
break;
}
}
}
V_34 = F_77 ( F_78 ( V_34 ) ,
V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
++ V_85 ;
V_9 -> V_65 = V_34 ;
if ( V_85 == 0 ) {
V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_64 -> V_23 . V_21 )
V_64 -> V_66 = V_64 -> V_48 ;
break;
}
V_39 = false ;
}
} else {
V_9 -> V_65 = V_34 ;
V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_64 -> V_66 = 0 ;
}
}
static int F_81 ( struct V_1 * V_9 ,
struct V_30 * V_80 ,
T_3 V_81 , int V_82 ,
T_7 * V_144 )
{
struct V_33 * V_31 ;
int V_85 = V_82 * V_86 ;
T_3 V_87 , V_88 ;
int V_72 = 0 ;
if ( V_89 . V_90 == V_91 )
V_87 = V_80 -> V_92 ;
else
V_87 = V_81 ;
V_88 = V_87 ;
V_31 = F_20 ( & V_80 -> V_35 ) ;
while ( V_31 ) {
struct V_30 * V_36 = F_22 ( V_31 , struct V_30 , V_33 ) ;
struct V_33 * V_41 = F_21 ( V_31 ) ;
T_3 V_93 = F_54 ( V_36 ) ;
struct V_27 * V_37 ;
char V_38 = ' ' ;
int V_39 = true ;
int V_94 = 0 ;
V_88 -= V_93 ;
F_23 (chain, &child->val, list) {
char V_69 [ 1024 ] , * V_95 ;
const char * V_96 ;
bool V_98 = V_39 ;
if ( V_39 )
V_39 = false ;
else
V_94 = V_86 ;
V_38 = F_17 ( V_37 ) ;
V_95 = NULL ;
V_96 = F_51 ( V_37 , V_69 , sizeof( V_69 ) ,
V_9 -> V_71 ) ;
if ( V_98 ) {
double V_100 = V_93 * 100.0 / V_87 ;
if ( F_55 ( & V_95 , L_12 , V_100 , V_96 ) < 0 )
V_96 = L_13 ;
else
V_96 = V_95 ;
}
V_72 += fprintf ( V_144 , L_18 , V_85 + V_94 , L_14 , V_38 , V_96 ) ;
free ( V_95 ) ;
if ( V_38 == '+' )
break;
}
if ( V_38 == '-' ) {
const int V_103 = V_82 + ( V_94 ? 2 : 1 ) ;
V_72 += F_81 ( V_9 , V_36 , V_87 ,
V_103 , V_144 ) ;
}
V_31 = V_41 ;
}
return V_72 ;
}
static int F_82 ( struct V_1 * V_9 ,
struct V_30 * V_31 ,
int V_82 , T_7 * V_144 )
{
struct V_27 * V_37 ;
int V_85 = V_82 * V_86 ;
char V_38 = ' ' ;
int V_72 = 0 ;
F_23 (chain, &node->val, list) {
char V_69 [ 1024 ] , * V_104 ;
V_38 = F_17 ( V_37 ) ;
V_104 = F_51 ( V_37 , V_69 , sizeof( V_69 ) , V_9 -> V_71 ) ;
V_72 += fprintf ( V_144 , L_18 , V_85 , L_14 , V_38 , V_104 ) ;
}
if ( V_38 == '-' )
V_72 += F_81 ( V_9 , V_31 ,
V_9 -> V_3 -> V_59 . V_105 ,
V_82 + 1 , V_144 ) ;
return V_72 ;
}
static int F_83 ( struct V_1 * V_9 ,
struct V_35 * V_37 , int V_82 , T_7 * V_144 )
{
struct V_33 * V_34 ;
int V_72 = 0 ;
for ( V_34 = F_20 ( V_37 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
V_72 += F_82 ( V_9 , V_31 , V_82 , V_144 ) ;
}
return V_72 ;
}
static int F_84 ( struct V_1 * V_9 ,
struct V_25 * V_26 , T_7 * V_144 )
{
char V_104 [ 8192 ] ;
int V_72 = 0 ;
char V_38 = ' ' ;
struct V_106 V_107 = {
. V_113 = V_104 ,
. V_114 = sizeof( V_104 ) ,
} ;
struct V_129 * V_108 ;
bool V_39 = true ;
int V_111 ;
if ( V_130 . V_131 )
V_38 = F_16 ( V_26 ) ;
if ( V_130 . V_131 )
V_72 += fprintf ( V_144 , L_15 , V_38 ) ;
F_67 (fmt) {
if ( F_68 ( V_108 ) )
continue;
if ( ! V_39 ) {
V_111 = F_52 ( V_107 . V_113 , V_107 . V_114 , L_16 ) ;
F_64 ( & V_107 , V_111 ) ;
} else
V_39 = false ;
V_111 = V_108 -> V_128 ( V_108 , & V_107 , V_26 ) ;
F_64 ( & V_107 , V_111 ) ;
}
V_72 += fprintf ( V_144 , L_19 , F_85 ( V_104 ) ) ;
if ( V_38 == '-' )
V_72 += F_83 ( V_9 , & V_26 -> V_45 , 1 , V_144 ) ;
return V_72 ;
}
static int F_86 ( struct V_1 * V_9 , T_7 * V_144 )
{
struct V_33 * V_34 = F_38 ( F_20 ( V_9 -> V_10 . V_49 ) ,
V_9 -> V_4 ) ;
int V_72 = 0 ;
while ( V_34 ) {
struct V_25 * V_64 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_72 += F_84 ( V_9 , V_64 , V_144 ) ;
V_34 = F_38 ( F_21 ( V_34 ) , V_9 -> V_4 ) ;
}
return V_72 ;
}
static int F_87 ( struct V_1 * V_9 )
{
char V_145 [ 64 ] ;
T_7 * V_144 ;
while ( 1 ) {
F_52 ( V_145 , sizeof( V_145 ) , L_20 , V_9 -> V_146 ) ;
if ( F_88 ( V_145 , V_147 ) )
break;
if ( ++ V_9 -> V_146 == 8192 ) {
F_49 ( L_21 ) ;
return - 1 ;
}
}
V_144 = fopen ( V_145 , L_22 ) ;
if ( V_144 == NULL ) {
char V_69 [ 64 ] ;
const char * V_148 = F_89 ( V_149 , V_69 , sizeof( V_69 ) ) ;
F_49 ( L_23 , V_145 , V_148 ) ;
return - 1 ;
}
++ V_9 -> V_146 ;
F_86 ( V_9 , V_144 ) ;
fclose ( V_144 ) ;
F_49 ( L_24 , V_145 ) ;
return 0 ;
}
static struct V_1 * F_90 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_91 ( sizeof( * V_9 ) ) ;
if ( V_9 ) {
V_9 -> V_3 = V_3 ;
V_9 -> V_10 . V_55 = F_75 ;
V_9 -> V_10 . V_150 = F_5 ;
V_9 -> V_10 . V_151 = F_79 ;
V_9 -> V_10 . V_152 = true ;
V_9 -> V_12 = V_130 . V_153 ;
}
return V_9 ;
}
static void F_92 ( struct V_1 * V_9 )
{
free ( V_9 ) ;
}
static struct V_25 * F_93 ( struct V_1 * V_9 )
{
return V_9 -> V_47 ;
}
static struct V_154 * F_94 ( struct V_1 * V_9 )
{
return V_9 -> V_47 -> V_154 ;
}
static int F_43 ( struct V_3 * V_3 , char * V_69 , T_4 V_114 )
{
char V_155 ;
int V_72 ;
const struct V_78 * V_78 = V_3 -> V_156 ;
const struct V_154 * V_154 = V_3 -> V_157 ;
unsigned long V_158 = V_3 -> V_59 . V_61 [ V_159 ] ;
T_3 V_61 = V_3 -> V_59 . V_105 ;
struct V_160 * V_161 = F_72 ( V_3 ) ;
const char * V_162 = F_95 ( V_161 ) ;
char V_113 [ 512 ] ;
T_4 V_163 = sizeof( V_113 ) ;
if ( V_130 . V_164 ) {
V_158 = V_3 -> V_59 . V_165 ;
V_61 = V_3 -> V_59 . V_166 ;
}
if ( F_96 ( V_161 ) ) {
struct V_160 * V_167 ;
F_97 ( V_161 , V_113 , V_163 ) ;
V_162 = V_113 ;
F_98 (pos, evsel) {
if ( V_130 . V_164 ) {
V_158 += V_167 -> V_3 . V_59 . V_165 ;
V_61 += V_167 -> V_3 . V_59 . V_166 ;
} else {
V_158 += V_167 -> V_3 . V_59 . V_61 [ V_159 ] ;
V_61 += V_167 -> V_3 . V_59 . V_105 ;
}
}
}
V_158 = F_99 ( V_158 , & V_155 ) ;
V_72 = F_52 ( V_69 , V_114 ,
L_25 ,
V_158 , V_155 , V_162 , V_61 ) ;
if ( V_3 -> V_168 )
V_72 += snprintf ( V_69 + V_72 , V_114 - V_72 ,
L_26 , V_3 -> V_168 ) ;
if ( V_154 )
V_72 += F_52 ( V_69 + V_72 , V_114 - V_72 ,
L_27 ,
( V_154 -> V_169 ? F_100 ( V_154 ) : L_17 ) ,
V_154 -> V_170 ) ;
if ( V_78 )
V_72 += F_52 ( V_69 + V_72 , V_114 - V_72 ,
L_28 , V_78 -> V_79 ) ;
return V_72 ;
}
static inline void F_101 ( char * * V_171 , int V_32 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_32 ; ++ V_172 )
F_102 ( & V_171 [ V_172 ] ) ;
}
static inline bool F_103 ( void * V_57 )
{
return V_57 == NULL ;
}
static int F_104 ( void )
{
char * V_173 , * V_171 [ 32 ] , * V_174 [ 32 ] , * V_175 ;
T_8 * V_176 ;
int V_177 = 0 , V_178 = - 1 , V_111 = - 1 ;
struct V_179 * V_180 ;
V_173 = getenv ( L_29 ) ;
if ( ! V_173 )
return V_111 ;
V_176 = F_105 ( V_173 ) ;
if ( ! V_176 )
return V_111 ;
memset ( V_171 , 0 , sizeof( V_171 ) ) ;
memset ( V_171 , 0 , sizeof( V_174 ) ) ;
while ( ( V_180 = F_106 ( V_176 ) ) ) {
char V_181 [ V_182 ] ;
T_3 V_183 ;
char * V_74 = V_180 -> V_184 ;
T_7 * V_185 ;
if ( ! ( V_180 -> V_186 == V_187 ) )
continue;
snprintf ( V_181 , sizeof( V_181 ) , L_30 , V_173 , V_74 ) ;
V_185 = fopen ( V_181 , L_31 ) ;
if ( ! V_185 )
continue;
if ( fread ( & V_183 , 1 , 8 , V_185 ) < 8 )
goto V_188;
if ( F_107 ( V_183 ) ) {
V_171 [ V_177 ] = F_108 ( V_74 ) ;
if ( ! V_171 [ V_177 ] )
goto V_188;
V_174 [ V_177 ] = F_108 ( V_181 ) ;
if ( ! V_174 [ V_177 ] ) {
F_102 ( & V_171 [ V_177 ] ) ;
F_109 ( L_32 ) ;
fclose ( V_185 ) ;
break;
}
V_177 ++ ;
}
V_188:
fclose ( V_185 ) ;
if ( V_177 >= 32 ) {
F_109 ( L_33
L_34 ) ;
break;
}
}
F_110 ( V_176 ) ;
if ( V_177 ) {
V_178 = F_111 ( V_177 , V_171 ) ;
if ( V_178 < V_177 && V_178 >= 0 ) {
V_175 = F_108 ( V_174 [ V_178 ] ) ;
if ( V_175 ) {
if ( V_189 )
free ( ( void * ) V_190 ) ;
V_190 = V_175 ;
V_189 = true ;
V_111 = 0 ;
} else
F_109 ( L_35 ) ;
}
}
F_101 ( V_171 , V_177 ) ;
F_101 ( V_174 , V_177 ) ;
return V_111 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_3 V_5 = 0 ;
struct V_33 * V_34 = F_20 ( & V_2 -> V_3 -> V_49 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_6 = V_2 -> V_3 -> V_6 ;
return;
}
while ( ( V_34 = F_38 ( V_34 , V_2 -> V_4 ) ) != NULL ) {
V_5 ++ ;
V_34 = F_21 ( V_34 ) ;
}
V_2 -> V_6 = V_5 ;
}
static int F_112 ( struct V_160 * V_161 , int V_61 ,
const char * V_191 ,
bool V_192 ,
struct V_50 * V_51 ,
float V_4 ,
struct V_193 * V_194 )
{
struct V_3 * V_3 = & V_161 -> V_3 ;
struct V_1 * V_9 = F_90 ( V_3 ) ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
char * V_171 [ 16 ] ;
int V_177 = 0 ;
int V_52 = - 1 ;
char V_113 [ 64 ] ;
char V_199 [ 64 ] ;
int V_54 = V_51 ? V_51 -> V_55 : 0 ;
#define F_113 \
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
"H Display column headers\n" \
const char V_200 [] = F_113
L_36
L_37
L_38
L_39
L_40
L_41
L_42 ;
const char V_201 [] = F_113
L_37
L_40
L_41
L_42 ;
if ( V_9 == NULL )
return - 1 ;
if ( V_4 ) {
V_9 -> V_4 = V_4 ;
F_12 ( V_9 ) ;
}
V_198 = F_114 ( 2 ) ;
if ( V_198 == NULL )
goto V_68;
F_115 ( V_191 ) ;
memset ( V_171 , 0 , sizeof( V_171 ) ) ;
while ( 1 ) {
const struct V_154 * V_154 = NULL ;
const struct V_78 * V_78 = NULL ;
int V_178 = 0 ,
V_202 = - 2 , V_203 = - 2 , V_204 = - 2 ,
V_205 = - 2 , V_206 = - 2 , V_207 = - 2 ;
int V_208 = - 2 , V_209 = - 2 ,
V_210 = - 2 , V_211 = - 2 ;
V_177 = 0 ;
V_52 = F_42 ( V_9 , V_51 ) ;
if ( V_9 -> V_47 != NULL ) {
V_154 = F_94 ( V_9 ) ;
V_78 = V_9 -> V_46 -> V_77 ? V_9 -> V_46 -> V_77 -> V_78 : NULL ;
}
switch ( V_52 ) {
case V_212 :
case V_213 :
if ( V_61 == 1 )
continue;
goto V_214;
case 'a' :
if ( ! V_215 ) {
F_41 ( & V_9 -> V_10 , V_54 * 2 ,
L_43
L_44 ) ;
continue;
}
if ( V_9 -> V_46 == NULL ||
V_9 -> V_46 -> V_73 == NULL ||
V_9 -> V_46 -> V_77 -> V_78 -> V_216 )
continue;
goto V_217;
case 'P' :
F_87 ( V_9 ) ;
continue;
case 'd' :
goto V_203;
case 'V' :
V_9 -> V_71 = ! V_9 -> V_71 ;
continue;
case 't' :
goto V_204;
case '/' :
if ( F_116 ( L_45 ,
L_46 ,
V_113 , L_47 ,
V_54 * 2 ) == V_67 ) {
V_3 -> V_218 = * V_113 ? V_113 : NULL ;
F_117 ( V_3 ) ;
F_11 ( V_9 ) ;
}
continue;
case 'r' :
if ( F_103 ( V_51 ) )
goto V_219;
continue;
case 's' :
if ( F_103 ( V_51 ) )
goto V_220;
continue;
case 'i' :
if ( V_194 -> V_221 )
F_118 ( V_194 ) ;
continue;
case 'F' :
V_130 . V_164 ^= 1 ;
continue;
case V_222 :
case 'h' :
case '?' :
F_119 ( & V_9 -> V_10 ,
F_103 ( V_51 ) ? V_200 : V_201 ) ;
continue;
case V_67 :
case V_223 :
break;
case V_224 : {
const void * V_65 ;
if ( F_120 ( V_198 ) ) {
if ( V_192 )
goto V_214;
continue;
}
V_65 = F_121 ( V_198 ) ;
if ( V_65 == & V_9 -> V_3 -> V_156 )
goto V_225;
if ( V_65 == & V_9 -> V_3 -> V_157 )
goto V_226;
continue;
}
case V_227 :
if ( ! V_192 &&
! F_122 ( & V_9 -> V_10 ,
L_48 ) )
continue;
case 'q' :
case F_123 ( 'c' ) :
goto V_214;
default:
continue;
}
if ( ! V_215 )
goto V_228;
if ( V_229 == V_230 ) {
V_196 = V_9 -> V_47 -> V_195 ;
if ( V_9 -> V_46 != NULL &&
V_196 &&
V_196 -> V_231 . V_73 != NULL &&
! V_196 -> V_231 . V_77 -> V_78 -> V_216 &&
F_55 ( & V_171 [ V_177 ] , L_49 ,
V_196 -> V_231 . V_73 -> V_74 ) > 0 )
V_205 = V_177 ++ ;
if ( V_9 -> V_46 != NULL &&
V_196 &&
V_196 -> V_232 . V_73 != NULL &&
! V_196 -> V_232 . V_77 -> V_78 -> V_216 &&
( V_196 -> V_232 . V_73 != V_196 -> V_231 . V_73 ||
V_196 -> V_232 . V_77 -> V_78 != V_196 -> V_231 . V_77 -> V_78 ) &&
F_55 ( & V_171 [ V_177 ] , L_49 ,
V_196 -> V_232 . V_73 -> V_74 ) > 0 )
V_206 = V_177 ++ ;
} else {
if ( V_9 -> V_46 != NULL &&
V_9 -> V_46 -> V_73 != NULL &&
! V_9 -> V_46 -> V_77 -> V_78 -> V_216 ) {
struct V_233 * V_234 ;
V_234 = F_124 ( V_9 -> V_46 -> V_73 ) ;
if ( V_234 -> V_235 &&
F_55 ( & V_171 [ V_177 ] , L_49 ,
V_9 -> V_46 -> V_73 -> V_74 ) > 0 )
V_202 = V_177 ++ ;
}
}
if ( V_154 != NULL &&
F_55 ( & V_171 [ V_177 ] , L_50 ,
( V_9 -> V_3 -> V_157 ? L_51 : L_52 ) ,
( V_154 -> V_169 ? F_100 ( V_154 ) : L_17 ) ,
V_154 -> V_170 ) > 0 )
V_204 = V_177 ++ ;
if ( V_78 != NULL &&
F_55 ( & V_171 [ V_177 ] , L_53 ,
( V_9 -> V_3 -> V_156 ? L_51 : L_52 ) ,
( V_78 -> V_236 ? L_54 : V_78 -> V_79 ) ) > 0 )
V_203 = V_177 ++ ;
if ( V_9 -> V_46 != NULL &&
V_9 -> V_46 -> V_77 != NULL &&
F_55 ( & V_171 [ V_177 ] , L_55 ) > 0 )
V_207 = V_177 ++ ;
if ( V_9 -> V_47 ) {
struct V_237 * V_73 ;
if ( F_55 ( & V_171 [ V_177 ] , L_56 ,
F_100 ( V_9 -> V_47 -> V_154 ) ) > 0 )
V_208 = V_177 ++ ;
V_73 = V_9 -> V_47 -> V_23 . V_73 ;
if ( V_73 && V_73 -> V_238 &&
F_55 ( & V_171 [ V_177 ] , L_57 ,
V_73 -> V_74 ) > 0 )
V_209 = V_177 ++ ;
}
if ( F_55 ( & V_171 [ V_177 ] , L_58 ) > 0 )
V_210 = V_177 ++ ;
if ( F_103 ( V_51 ) && F_55 ( & V_171 [ V_177 ] ,
L_59 ) > 0 )
V_211 = V_177 ++ ;
V_228:
V_171 [ V_177 ++ ] = ( char * ) L_60 ;
V_239:
V_178 = F_111 ( V_177 , V_171 ) ;
if ( V_178 == V_177 - 1 )
break;
if ( V_178 == - 1 ) {
F_101 ( V_171 , V_177 - 1 ) ;
continue;
}
if ( V_178 == V_202 || V_178 == V_206 || V_178 == V_205 ) {
struct V_25 * V_26 ;
struct V_233 * V_234 ;
int V_148 ;
V_217:
if ( ! V_240 && F_125 ( V_194 ) )
continue;
V_26 = F_93 ( V_9 ) ;
if ( V_26 == NULL )
continue;
if ( V_178 == V_205 ) {
V_26 -> V_23 . V_73 = V_26 -> V_195 -> V_231 . V_73 ;
V_26 -> V_23 . V_77 = V_26 -> V_195 -> V_231 . V_77 ;
} else if ( V_178 == V_206 ) {
V_26 -> V_23 . V_73 = V_26 -> V_195 -> V_232 . V_73 ;
V_26 -> V_23 . V_77 = V_26 -> V_195 -> V_232 . V_77 ;
}
V_234 = F_124 ( V_26 -> V_23 . V_73 ) ;
if ( ! V_234 -> V_235 )
continue;
V_26 -> V_241 = true ;
V_148 = F_126 ( V_26 , V_161 , V_51 ) ;
V_26 -> V_241 = false ;
if ( ( V_148 == 'q' || V_148 == F_123 ( 'c' ) )
&& V_206 != - 2 && V_205 != - 2 )
goto V_239;
F_46 ( & V_9 -> V_10 , V_9 -> V_3 -> V_5 ) ;
if ( V_148 )
F_127 ( & V_9 -> V_10 ) ;
} else if ( V_178 == V_207 )
F_128 ( V_9 -> V_46 -> V_77 ) ;
else if ( V_178 == V_203 ) {
V_203:
if ( V_9 -> V_3 -> V_156 ) {
F_129 ( V_198 , & V_9 -> V_3 -> V_156 ) ;
V_225:
F_48 () ;
V_9 -> V_3 -> V_156 = NULL ;
F_130 ( V_242 , false ) ;
} else {
if ( V_78 == NULL )
continue;
F_49 ( L_61 ,
V_78 -> V_236 ? L_54 : V_78 -> V_79 ) ;
V_9 -> V_3 -> V_156 = V_78 ;
F_130 ( V_242 , true ) ;
F_131 ( V_198 , & V_9 -> V_3 -> V_156 ) ;
}
F_132 ( V_3 ) ;
F_11 ( V_9 ) ;
} else if ( V_178 == V_204 ) {
V_204:
if ( V_9 -> V_3 -> V_157 ) {
F_129 ( V_198 , & V_9 -> V_3 -> V_157 ) ;
V_226:
F_48 () ;
V_9 -> V_3 -> V_157 = NULL ;
F_130 ( V_243 , false ) ;
} else {
F_49 ( L_62 ,
V_154 -> V_169 ? F_100 ( V_154 ) : L_17 ,
V_154 -> V_170 ) ;
V_9 -> V_3 -> V_157 = V_154 ;
F_130 ( V_243 , false ) ;
F_131 ( V_198 , & V_9 -> V_3 -> V_157 ) ;
}
F_133 ( V_3 ) ;
F_11 ( V_9 ) ;
}
else if ( V_178 == V_210 || V_178 == V_208 ||
V_178 == V_209 ) {
V_219:
memset ( V_199 , 0 , 64 ) ;
if ( V_178 == V_208 )
sprintf ( V_199 , L_63 , F_100 ( V_9 -> V_47 -> V_154 ) ) ;
if ( V_178 == V_209 )
sprintf ( V_199 , L_64 , V_9 -> V_47 -> V_23 . V_73 -> V_74 ) ;
F_134 ( V_199 ) ;
}
else if ( V_178 == V_211 ) {
V_220:
if ( ! F_104 () ) {
V_52 = V_244 ;
break;
} else
F_109 ( L_65
L_66 ) ;
}
}
V_214:
F_135 ( V_198 ) ;
V_68:
F_92 ( V_9 ) ;
F_101 ( V_171 , V_177 - 1 ) ;
return V_52 ;
}
static void F_136 ( struct V_8 * V_9 ,
void * V_128 , int V_19 )
{
struct V_245 * V_246 = F_6 ( V_9 ,
struct V_245 , V_10 ) ;
struct V_160 * V_161 = F_137 ( V_128 , struct V_160 , V_31 ) ;
bool V_112 = F_56 ( V_9 , V_19 ) ;
unsigned long V_61 = V_161 -> V_3 . V_59 . V_61 [ V_159 ] ;
const char * V_162 = F_95 ( V_161 ) ;
char V_69 [ 256 ] , V_155 ;
const char * V_247 = L_14 ;
T_4 V_72 ;
F_57 ( V_9 , V_112 ? V_102 :
V_101 ) ;
if ( F_96 ( V_161 ) ) {
struct V_160 * V_167 ;
V_162 = F_138 ( V_161 ) ;
F_98 (pos, evsel) {
V_61 += V_167 -> V_3 . V_59 . V_61 [ V_159 ] ;
}
}
V_61 = F_99 ( V_61 , & V_155 ) ;
V_72 = F_52 ( V_69 , sizeof( V_69 ) , L_67 , V_61 ,
V_155 , V_155 == ' ' ? L_17 : L_14 , V_162 ) ;
F_59 ( L_8 , V_69 ) ;
V_61 = V_161 -> V_3 . V_59 . V_61 [ V_62 ] ;
if ( V_61 != 0 ) {
V_246 -> V_248 = true ;
if ( ! V_112 )
F_57 ( V_9 , V_249 ) ;
V_61 = F_99 ( V_61 , & V_155 ) ;
V_72 += F_52 ( V_69 , sizeof( V_69 ) , L_68 ,
V_61 , V_155 , V_155 == ' ' ? L_17 : L_14 ) ;
V_247 = V_69 ;
}
F_58 ( V_247 , V_9 -> V_18 - V_72 ) ;
if ( V_112 )
V_246 -> V_46 = V_161 ;
}
static int F_139 ( struct V_245 * V_246 ,
int V_61 , const char * V_250 ,
struct V_50 * V_51 )
{
struct V_251 * V_252 = V_246 -> V_10 . V_253 ;
struct V_160 * V_167 ;
const char * V_53 = L_69 ;
int V_54 = V_51 ? V_51 -> V_55 : 0 ;
int V_52 ;
if ( F_44 ( & V_246 -> V_10 , V_53 ,
L_70 ) < 0 )
return - 1 ;
while ( 1 ) {
V_52 = F_45 ( & V_246 -> V_10 , V_54 ) ;
switch ( V_52 ) {
case V_56 :
V_51 -> V_57 ( V_51 -> V_58 ) ;
if ( ! V_246 -> V_254 && V_246 -> V_248 ) {
F_40 ( & V_246 -> V_10 ) ;
V_246 -> V_254 = true ;
}
continue;
case V_223 :
case V_67 :
if ( ! V_246 -> V_46 )
continue;
V_167 = V_246 -> V_46 ;
V_255:
F_140 ( V_252 , V_167 ) ;
if ( V_51 )
V_51 -> V_57 ( V_51 -> V_58 ) ;
V_52 = F_112 ( V_167 , V_61 , V_250 ,
true , V_51 ,
V_246 -> V_4 ,
V_246 -> V_194 ) ;
F_47 ( & V_246 -> V_10 , V_53 ) ;
switch ( V_52 ) {
case V_212 :
if ( V_167 -> V_31 . V_41 == & V_252 -> V_49 )
V_167 = F_141 ( V_252 ) ;
else
V_167 = F_142 ( V_167 ) ;
goto V_255;
case V_213 :
if ( V_167 -> V_31 . V_256 == & V_252 -> V_49 )
V_167 = F_143 ( V_252 ) ;
else
V_167 = F_144 ( V_167 ) ;
goto V_255;
case V_227 :
if ( ! F_122 ( & V_246 -> V_10 ,
L_48 ) )
continue;
case V_244 :
case 'q' :
case F_123 ( 'c' ) :
goto V_68;
default:
continue;
}
case V_224 :
continue;
case V_227 :
if ( ! F_122 ( & V_246 -> V_10 ,
L_48 ) )
continue;
case 'q' :
case F_123 ( 'c' ) :
goto V_68;
default:
continue;
}
}
V_68:
F_50 ( & V_246 -> V_10 ) ;
return V_52 ;
}
static bool F_145 ( struct V_8 * V_9 V_257 ,
void * V_128 )
{
struct V_160 * V_161 = F_137 ( V_128 , struct V_160 , V_31 ) ;
if ( V_130 . V_258 && ! F_146 ( V_161 ) )
return true ;
return false ;
}
static int F_147 ( struct V_251 * V_252 ,
int V_5 , const char * V_250 ,
struct V_50 * V_51 ,
float V_4 ,
struct V_193 * V_194 )
{
struct V_160 * V_167 ;
struct V_245 V_246 = {
. V_10 = {
. V_49 = & V_252 -> V_49 ,
. V_55 = V_259 ,
. V_151 = V_260 ,
. V_261 = F_136 ,
. V_262 = F_145 ,
. V_5 = V_5 ,
. V_253 = V_252 ,
} ,
. V_4 = V_4 ,
. V_194 = V_194 ,
} ;
F_115 ( L_71 ) ;
F_148 (evlist, pos) {
const char * V_162 = F_95 ( V_167 ) ;
T_4 V_263 = strlen ( V_162 ) + 7 ;
if ( V_246 . V_10 . V_18 < V_263 )
V_246 . V_10 . V_18 = V_263 ;
}
return F_139 ( & V_246 , V_5 , V_250 , V_51 ) ;
}
int F_149 ( struct V_251 * V_252 , const char * V_250 ,
struct V_50 * V_51 ,
float V_4 ,
struct V_193 * V_194 )
{
int V_5 = V_252 -> V_5 ;
V_264:
if ( V_5 == 1 ) {
struct V_160 * V_39 = F_141 ( V_252 ) ;
return F_112 ( V_39 , V_5 , V_250 ,
false , V_51 , V_4 ,
V_194 ) ;
}
if ( V_130 . V_258 ) {
struct V_160 * V_167 ;
V_5 = 0 ;
F_148 (evlist, pos) {
if ( F_146 ( V_167 ) )
V_5 ++ ;
}
if ( V_5 == 1 )
goto V_264;
}
return F_147 ( V_252 , V_5 , V_250 ,
V_51 , V_4 , V_194 ) ;
}
