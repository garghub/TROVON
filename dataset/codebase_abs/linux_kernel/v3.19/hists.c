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
static void F_29 ( struct V_30 * V_31 ,
bool V_43 )
{
struct V_27 * V_37 ;
V_37 = F_30 ( V_31 -> V_42 . V_41 , struct V_27 , V_40 ) ;
V_37 -> V_23 . V_24 = V_43 ;
if ( ! F_31 ( & V_31 -> V_42 ) ) {
V_37 = F_30 ( V_31 -> V_42 . V_44 , struct V_27 , V_40 ) ;
V_37 -> V_23 . V_24 = ! F_28 ( & V_31 -> V_35 ) ;
}
F_27 ( V_31 ) ;
}
static void F_32 ( struct V_35 * V_45 )
{
struct V_33 * V_34 = F_20 ( V_45 ) ;
bool V_43 = V_34 && F_21 ( V_34 ) ;
for ( V_34 = F_20 ( V_45 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
F_29 ( V_31 , V_43 ) ;
}
}
static void F_33 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_46 ) {
V_26 -> V_23 . V_24 = ! F_28 ( & V_26 -> V_47 ) ;
F_32 ( & V_26 -> V_47 ) ;
V_26 -> V_46 = true ;
}
}
static bool F_34 ( struct V_1 * V_9 )
{
if ( F_26 ( V_9 -> V_48 ) ) {
struct V_25 * V_26 = V_9 -> V_49 ;
F_33 ( V_26 ) ;
V_9 -> V_10 . V_5 -= V_26 -> V_50 ;
V_9 -> V_7 -= V_26 -> V_50 ;
if ( V_26 -> V_23 . V_21 )
V_26 -> V_50 = F_25 ( & V_26 -> V_47 ) ;
else
V_26 -> V_50 = 0 ;
V_9 -> V_10 . V_5 += V_26 -> V_50 ;
V_9 -> V_7 += V_26 -> V_50 ;
return true ;
}
return false ;
}
static int F_35 ( struct V_30 * V_31 , bool V_29 )
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
V_32 += F_35 ( V_36 , V_29 ) ;
}
return V_32 ;
}
static int F_36 ( struct V_30 * V_31 , bool V_29 )
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
V_32 += F_35 ( V_31 , V_29 ) ;
return V_32 ;
}
static int F_37 ( struct V_35 * V_37 , bool V_29 )
{
struct V_33 * V_34 ;
int V_32 = 0 ;
for ( V_34 = F_20 ( V_37 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
V_32 += F_36 ( V_31 , V_29 ) ;
}
return V_32 ;
}
static void F_38 ( struct V_25 * V_26 , bool V_29 )
{
F_33 ( V_26 ) ;
F_18 ( & V_26 -> V_23 , V_29 ) ;
if ( V_26 -> V_23 . V_24 ) {
int V_32 = F_37 ( & V_26 -> V_47 , V_29 ) ;
V_26 -> V_50 = V_29 ? V_32 : 0 ;
} else
V_26 -> V_50 = 0 ;
}
static void
F_39 ( struct V_1 * V_9 , bool V_29 )
{
struct V_33 * V_34 ;
struct V_3 * V_3 = V_9 -> V_3 ;
for ( V_34 = F_20 ( & V_3 -> V_51 ) ;
( V_34 = F_40 ( V_34 , V_9 -> V_4 ) ) != NULL ;
V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_26 = F_22 ( V_34 , struct V_25 , V_33 ) ;
F_38 ( V_26 , V_29 ) ;
V_9 -> V_7 += V_26 -> V_50 ;
}
}
static void F_41 ( struct V_1 * V_9 , bool V_29 )
{
V_9 -> V_7 = 0 ;
F_39 ( V_9 , V_29 ) ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_13 ( & V_9 -> V_10 ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
F_43 ( V_9 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_44 ( struct V_1 * V_9 ,
struct V_52 * V_53 )
{
int V_54 ;
char V_55 [ 160 ] ;
int V_56 = V_53 ? V_53 -> V_57 : 0 ;
V_9 -> V_10 . V_51 = & V_9 -> V_3 -> V_51 ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_45 ( V_9 -> V_3 , V_53 , V_55 , sizeof( V_55 ) ) ;
if ( F_46 ( & V_9 -> V_10 , V_55 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_54 = F_47 ( & V_9 -> V_10 , V_56 ) ;
switch ( V_54 ) {
case V_58 : {
T_3 V_5 ;
V_53 -> V_59 ( V_53 -> V_60 ) ;
if ( F_1 ( V_9 ) )
F_12 ( V_9 ) ;
V_5 = F_3 ( V_9 ) ;
F_48 ( & V_9 -> V_10 , V_5 ) ;
if ( V_9 -> V_3 -> V_61 . V_62 !=
V_9 -> V_3 -> V_61 . V_63 [ V_64 ] ) {
V_9 -> V_3 -> V_61 . V_62 =
V_9 -> V_3 -> V_61 . V_63 [ V_64 ] ;
F_42 ( & V_9 -> V_10 ) ;
}
F_45 ( V_9 -> V_3 ,
V_53 , V_55 , sizeof( V_55 ) ) ;
F_49 ( & V_9 -> V_10 , V_55 ) ;
continue;
}
case 'D' : {
static int V_65 ;
struct V_25 * V_66 = F_22 ( V_9 -> V_10 . V_67 ,
struct V_25 , V_33 ) ;
F_50 () ;
F_51 ( L_7 ,
V_65 ++ , V_9 -> V_10 . V_5 ,
V_9 -> V_3 -> V_5 ,
V_9 -> V_10 . V_14 ,
V_9 -> V_10 . V_16 ,
V_9 -> V_10 . V_17 ,
V_66 -> V_68 , V_66 -> V_50 ) ;
}
break;
case 'C' :
F_41 ( V_9 , false ) ;
break;
case 'E' :
F_41 ( V_9 , true ) ;
break;
case 'H' :
V_9 -> V_12 = ! V_9 -> V_12 ;
F_4 ( V_9 ) ;
break;
case V_69 :
if ( F_34 ( V_9 ) )
break;
default:
goto V_70;
}
}
V_70:
F_52 ( & V_9 -> V_10 ) ;
return V_54 ;
}
static void F_53 ( struct V_1 * V_9 ,
struct V_27 * V_37 ,
const char * V_71 , int V_72 ,
unsigned short V_19 ,
struct V_73 * V_60 )
{
int V_74 , V_18 ;
char V_38 = F_17 ( V_37 ) ;
V_74 = V_75 ;
V_18 = V_9 -> V_10 . V_18 - ( V_72 + 2 ) ;
if ( F_54 ( & V_9 -> V_10 , V_19 ) ) {
V_9 -> V_48 = & V_37 -> V_23 ;
V_74 = V_76 ;
V_60 -> V_77 = true ;
}
F_55 ( & V_9 -> V_10 , V_74 ) ;
F_9 ( V_9 , V_19 , 0 ) ;
F_56 ( L_8 , V_72 ) ;
F_57 ( L_9 , V_38 ) ;
F_56 ( V_71 , V_18 ) ;
}
static void F_58 ( struct V_1 * V_10 V_78 ,
struct V_27 * V_37 ,
const char * V_71 , int V_72 ,
unsigned short V_19 V_78 ,
struct V_73 * V_60 )
{
char V_38 = F_17 ( V_37 ) ;
V_60 -> V_79 += fprintf ( V_60 -> V_80 , L_10 , V_72 , L_8 ,
V_38 , V_71 ) ;
}
static bool F_59 ( struct V_1 * V_9 ,
unsigned short V_19 )
{
return V_9 -> V_10 . V_14 == V_19 ;
}
static bool F_60 ( struct V_1 * V_9 V_78 ,
unsigned short V_19 V_78 )
{
return false ;
}
static int F_61 ( struct V_1 * V_9 ,
struct V_35 * V_45 , int V_81 ,
unsigned short V_19 , T_3 V_82 ,
T_4 V_83 ,
struct V_73 * V_60 ,
T_5 V_84 )
{
struct V_33 * V_31 ;
int V_85 = V_19 , V_72 = V_81 * V_86 ;
T_3 V_87 ;
bool V_88 ;
V_31 = F_20 ( V_45 ) ;
V_88 = V_31 && F_21 ( V_31 ) ;
while ( V_31 ) {
struct V_30 * V_36 = F_22 ( V_31 , struct V_30 , V_33 ) ;
struct V_33 * V_41 = F_21 ( V_31 ) ;
T_3 V_89 = F_62 ( V_36 ) ;
struct V_27 * V_37 ;
char V_38 = ' ' ;
int V_39 = true ;
int V_90 = 0 ;
F_23 (chain, &child->val, list) {
char V_91 [ 1024 ] , * V_92 ;
const char * V_71 ;
bool V_93 = V_39 ;
if ( V_39 )
V_39 = false ;
else if ( V_88 )
V_90 = V_86 ;
V_38 = F_17 ( V_37 ) ;
if ( V_60 -> V_68 != 0 ) {
V_60 -> V_68 -- ;
goto V_94;
}
V_92 = NULL ;
V_71 = F_63 ( V_37 , V_91 , sizeof( V_91 ) ,
V_9 -> V_95 ) ;
if ( V_93 && V_88 ) {
double V_96 = V_89 * 100.0 / V_82 ;
if ( F_64 ( & V_92 , L_11 , V_96 , V_71 ) < 0 )
V_71 = L_12 ;
else
V_71 = V_92 ;
}
V_83 ( V_9 , V_37 , V_71 , V_72 + V_90 , V_19 , V_60 ) ;
free ( V_92 ) ;
if ( V_84 ( V_9 , ++ V_19 ) )
goto V_70;
V_94:
if ( V_38 == '+' )
break;
}
if ( V_38 == '-' ) {
const int V_97 = V_81 + ( V_90 ? 2 : 1 ) ;
if ( V_98 . V_99 == V_100 )
V_87 = V_36 -> V_101 ;
else
V_87 = V_82 ;
V_19 += F_61 ( V_9 , & V_36 -> V_35 ,
V_97 , V_19 , V_87 ,
V_83 , V_60 , V_84 ) ;
}
if ( V_84 ( V_9 , V_19 ) )
break;
V_31 = V_41 ;
}
V_70:
return V_19 - V_85 ;
}
static int F_65 ( struct V_102 * V_103 , const char * V_104 , ... )
{
struct V_105 * V_60 = V_103 -> V_106 ;
int V_107 , V_108 ;
T_6 args ;
double V_96 ;
va_start ( args , V_104 ) ;
V_108 = va_arg ( args , int ) ;
V_96 = va_arg ( args , double ) ;
va_end ( args ) ;
F_66 ( V_60 -> V_10 , V_96 , V_60 -> V_109 ) ;
V_107 = F_67 ( V_103 -> V_110 , V_103 -> V_111 , V_104 , V_108 , V_96 ) ;
F_57 ( L_13 , V_103 -> V_110 ) ;
F_68 ( V_103 , V_107 ) ;
return V_107 ;
}
void F_69 ( void )
{
V_112 [ V_113 ] . V_74 =
V_114 ;
V_112 [ V_115 ] . V_74 =
V_116 ;
V_112 [ V_117 ] . V_74 =
V_118 ;
V_112 [ V_119 ] . V_74 =
V_120 ;
V_112 [ V_121 ] . V_74 =
V_122 ;
V_112 [ V_123 ] . V_74 =
V_124 ;
}
static int F_70 ( struct V_1 * V_9 ,
struct V_25 * V_125 ,
unsigned short V_19 )
{
char V_126 [ 256 ] ;
int V_79 = 0 ;
int V_18 = V_9 -> V_10 . V_18 ;
char V_38 = ' ' ;
bool V_109 = F_54 ( & V_9 -> V_10 , V_19 ) ;
T_7 V_68 = V_125 -> V_68 ;
bool V_39 = true ;
struct V_127 * V_104 ;
if ( V_109 ) {
V_9 -> V_49 = V_125 ;
V_9 -> V_48 = & V_125 -> V_23 ;
}
if ( V_128 . V_129 ) {
F_33 ( V_125 ) ;
V_38 = F_16 ( V_125 ) ;
}
if ( V_68 == 0 ) {
struct V_105 V_60 = {
. V_10 = & V_9 -> V_10 ,
. V_38 = V_38 ,
. V_109 = V_109 ,
} ;
struct V_102 V_103 = {
. V_110 = V_126 ,
. V_111 = sizeof( V_126 ) ,
. V_106 = & V_60 ,
} ;
F_9 ( V_9 , V_19 , 0 ) ;
F_71 (fmt) {
if ( F_72 ( V_104 ) )
continue;
if ( V_109 && V_9 -> V_10 . V_130 ) {
F_55 ( & V_9 -> V_10 ,
V_76 ) ;
} else {
F_55 ( & V_9 -> V_10 ,
V_75 ) ;
}
if ( V_39 ) {
if ( V_128 . V_129 ) {
F_57 ( L_9 , V_38 ) ;
V_18 -= 2 ;
}
V_39 = false ;
} else {
F_57 ( L_14 ) ;
V_18 -= 2 ;
}
if ( V_104 -> V_74 ) {
V_18 -= V_104 -> V_74 ( V_104 , & V_103 , V_125 ) ;
} else {
V_18 -= V_104 -> V_125 ( V_104 , & V_103 , V_125 ) ;
F_57 ( L_13 , V_126 ) ;
}
}
if ( ! V_9 -> V_10 . V_130 )
V_18 += 1 ;
F_56 ( L_15 , V_18 ) ;
++ V_19 ;
++ V_79 ;
} else
-- V_68 ;
if ( V_38 == '-' && V_19 != V_9 -> V_10 . V_14 ) {
T_3 V_82 = F_73 ( V_125 -> V_3 ) ;
struct V_73 V_60 = {
. V_68 = V_68 ,
. V_77 = V_109 ,
} ;
if ( V_98 . V_99 == V_100 ) {
if ( V_128 . V_131 )
V_82 = V_125 -> V_132 -> V_133 ;
else
V_82 = V_125 -> V_134 . V_133 ;
}
V_79 += F_61 ( V_9 ,
& V_125 -> V_47 , 1 , V_19 , V_82 ,
F_53 , & V_60 ,
F_59 ) ;
if ( V_60 . V_77 )
V_9 -> V_49 = V_125 ;
}
return V_79 ;
}
static int F_74 ( struct V_102 * V_103 , int V_135 )
{
F_68 ( V_103 , V_135 ) ;
return V_103 -> V_111 <= 0 ;
}
static int F_75 ( char * V_110 , T_8 V_111 , struct V_3 * V_3 )
{
struct V_102 V_136 = {
. V_110 = V_110 ,
. V_111 = V_111 ,
} ;
struct V_127 * V_104 ;
T_8 V_107 = 0 ;
if ( V_128 . V_129 ) {
V_107 = F_67 ( V_110 , V_111 , L_14 ) ;
if ( F_74 ( & V_136 , V_107 ) )
return V_107 ;
}
F_71 (fmt) {
if ( F_72 ( V_104 ) )
continue;
V_107 = V_104 -> V_137 ( V_104 , & V_136 , F_76 ( V_3 ) ) ;
if ( F_74 ( & V_136 , V_107 ) )
break;
V_107 = F_67 ( V_136 . V_110 , V_136 . V_111 , L_14 ) ;
if ( F_74 ( & V_136 , V_107 ) )
break;
}
return V_107 ;
}
static void F_77 ( struct V_1 * V_9 )
{
char V_138 [ 1024 ] ;
F_75 ( V_138 , sizeof( V_138 ) , V_9 -> V_3 ) ;
F_10 ( & V_9 -> V_10 , 0 , 0 ) ;
F_55 ( & V_9 -> V_10 , V_139 ) ;
F_56 ( V_138 , V_9 -> V_10 . V_18 + 1 ) ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( V_9 -> V_67 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
V_9 -> V_67 = F_20 ( & V_2 -> V_3 -> V_51 ) ;
}
}
static unsigned int F_79 ( struct V_8 * V_9 )
{
unsigned V_19 = 0 ;
T_2 V_11 = 0 ;
struct V_33 * V_34 ;
struct V_1 * V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
if ( V_2 -> V_12 ) {
F_77 ( V_2 ) ;
V_11 = 1 ;
}
F_78 ( V_9 ) ;
for ( V_34 = V_9 -> V_67 ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_96 ;
if ( V_66 -> V_140 )
continue;
V_96 = F_80 ( V_66 ) ;
if ( V_96 < V_2 -> V_4 )
continue;
V_19 += F_70 ( V_2 , V_66 , V_19 ) ;
if ( V_19 == V_9 -> V_14 )
break;
}
return V_19 + V_11 ;
}
static struct V_33 * F_40 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_96 = F_80 ( V_66 ) ;
if ( ! V_66 -> V_140 && V_96 >= V_4 )
return V_34 ;
V_34 = F_21 ( V_34 ) ;
}
return NULL ;
}
static struct V_33 * F_81 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_96 = F_80 ( V_66 ) ;
if ( ! V_66 -> V_140 && V_96 >= V_4 )
return V_34 ;
V_34 = F_82 ( V_34 ) ;
}
return NULL ;
}
static void F_83 ( struct V_8 * V_9 ,
T_7 V_72 , int V_141 )
{
struct V_25 * V_66 ;
struct V_33 * V_34 ;
bool V_39 = true ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
if ( V_9 -> V_5 == 0 )
return;
F_78 ( V_9 ) ;
switch ( V_141 ) {
case V_142 :
V_34 = F_40 ( F_20 ( V_9 -> V_51 ) ,
V_2 -> V_4 ) ;
break;
case V_143 :
V_34 = V_9 -> V_67 ;
goto V_144;
case V_145 :
V_34 = F_81 ( F_84 ( V_9 -> V_51 ) ,
V_2 -> V_4 ) ;
V_39 = false ;
break;
default:
return;
}
V_66 = F_22 ( V_9 -> V_67 , struct V_25 , V_33 ) ;
V_66 -> V_68 = 0 ;
V_144:
if ( V_72 > 0 ) {
do {
V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_66 -> V_23 . V_21 ) {
T_2 V_146 = V_66 -> V_50 - V_66 -> V_68 ;
if ( V_72 > V_146 ) {
V_72 -= V_146 ;
V_66 -> V_68 = 0 ;
} else {
V_66 -> V_68 += V_72 ;
V_72 = 0 ;
V_9 -> V_67 = V_34 ;
break;
}
}
V_34 = F_40 ( F_21 ( V_34 ) , V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
-- V_72 ;
V_9 -> V_67 = V_34 ;
} while ( V_72 != 0 );
} else if ( V_72 < 0 ) {
while ( 1 ) {
V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_66 -> V_23 . V_21 ) {
if ( V_39 ) {
if ( - V_72 > V_66 -> V_68 ) {
V_72 += V_66 -> V_68 ;
V_66 -> V_68 = 0 ;
} else {
V_66 -> V_68 += V_72 ;
V_72 = 0 ;
V_9 -> V_67 = V_34 ;
break;
}
} else {
if ( - V_72 > V_66 -> V_50 ) {
V_72 += V_66 -> V_50 ;
V_66 -> V_68 = 0 ;
} else {
V_66 -> V_68 = V_66 -> V_50 + V_72 ;
V_72 = 0 ;
V_9 -> V_67 = V_34 ;
break;
}
}
}
V_34 = F_81 ( F_82 ( V_34 ) ,
V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
++ V_72 ;
V_9 -> V_67 = V_34 ;
if ( V_72 == 0 ) {
V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_66 -> V_23 . V_21 )
V_66 -> V_68 = V_66 -> V_50 ;
break;
}
V_39 = false ;
}
} else {
V_9 -> V_67 = V_34 ;
V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_66 -> V_68 = 0 ;
}
}
static int F_85 ( struct V_1 * V_9 ,
struct V_25 * V_26 , T_9 * V_80 )
{
T_3 V_82 = F_73 ( V_26 -> V_3 ) ;
struct V_73 V_60 = {
. V_80 = V_80 ,
} ;
if ( V_128 . V_131 )
V_82 = V_26 -> V_132 -> V_133 ;
F_61 ( V_9 , & V_26 -> V_47 , 1 , 0 , V_82 ,
F_58 , & V_60 ,
F_60 ) ;
return V_60 . V_79 ;
}
static int F_86 ( struct V_1 * V_9 ,
struct V_25 * V_26 , T_9 * V_80 )
{
char V_126 [ 8192 ] ;
int V_79 = 0 ;
char V_38 = ' ' ;
struct V_102 V_103 = {
. V_110 = V_126 ,
. V_111 = sizeof( V_126 ) ,
} ;
struct V_127 * V_104 ;
bool V_39 = true ;
int V_107 ;
if ( V_128 . V_129 )
V_38 = F_16 ( V_26 ) ;
if ( V_128 . V_129 )
V_79 += fprintf ( V_80 , L_9 , V_38 ) ;
F_71 (fmt) {
if ( F_72 ( V_104 ) )
continue;
if ( ! V_39 ) {
V_107 = F_67 ( V_103 . V_110 , V_103 . V_111 , L_14 ) ;
F_68 ( & V_103 , V_107 ) ;
} else
V_39 = false ;
V_107 = V_104 -> V_125 ( V_104 , & V_103 , V_26 ) ;
F_68 ( & V_103 , V_107 ) ;
}
V_79 += fprintf ( V_80 , L_16 , F_87 ( V_126 ) ) ;
if ( V_38 == '-' )
V_79 += F_85 ( V_9 , V_26 , V_80 ) ;
return V_79 ;
}
static int F_88 ( struct V_1 * V_9 , T_9 * V_80 )
{
struct V_33 * V_34 = F_40 ( F_20 ( V_9 -> V_10 . V_51 ) ,
V_9 -> V_4 ) ;
int V_79 = 0 ;
while ( V_34 ) {
struct V_25 * V_66 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_79 += F_86 ( V_9 , V_66 , V_80 ) ;
V_34 = F_40 ( F_21 ( V_34 ) , V_9 -> V_4 ) ;
}
return V_79 ;
}
static int F_89 ( struct V_1 * V_9 )
{
char V_147 [ 64 ] ;
T_9 * V_80 ;
while ( 1 ) {
F_67 ( V_147 , sizeof( V_147 ) , L_17 , V_9 -> V_148 ) ;
if ( F_90 ( V_147 , V_149 ) )
break;
if ( ++ V_9 -> V_148 == 8192 ) {
F_51 ( L_18 ) ;
return - 1 ;
}
}
V_80 = fopen ( V_147 , L_19 ) ;
if ( V_80 == NULL ) {
char V_91 [ 64 ] ;
const char * V_150 = F_91 ( V_151 , V_91 , sizeof( V_91 ) ) ;
F_51 ( L_20 , V_147 , V_150 ) ;
return - 1 ;
}
++ V_9 -> V_148 ;
F_88 ( V_9 , V_80 ) ;
fclose ( V_80 ) ;
F_51 ( L_21 , V_147 ) ;
return 0 ;
}
static struct V_1 * F_92 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_93 ( sizeof( * V_9 ) ) ;
if ( V_9 ) {
V_9 -> V_3 = V_3 ;
V_9 -> V_10 . V_57 = F_79 ;
V_9 -> V_10 . V_152 = F_5 ;
V_9 -> V_10 . V_153 = F_83 ;
V_9 -> V_10 . V_154 = true ;
V_9 -> V_12 = V_128 . V_155 ;
}
return V_9 ;
}
static void F_94 ( struct V_1 * V_9 )
{
free ( V_9 ) ;
}
static struct V_25 * F_95 ( struct V_1 * V_9 )
{
return V_9 -> V_49 ;
}
static struct V_156 * F_96 ( struct V_1 * V_9 )
{
return V_9 -> V_49 -> V_156 ;
}
static inline bool F_97 ( void * V_59 )
{
return V_59 == NULL ;
}
static int F_45 ( struct V_3 * V_3 ,
struct V_52 * V_53 ,
char * V_91 , T_8 V_111 )
{
char V_157 ;
int V_79 ;
const struct V_158 * V_158 = V_3 -> V_159 ;
const struct V_156 * V_156 = V_3 -> V_160 ;
unsigned long V_161 = V_3 -> V_61 . V_63 [ V_162 ] ;
T_3 V_63 = V_3 -> V_61 . V_163 ;
struct V_164 * V_165 = F_76 ( V_3 ) ;
const char * V_166 = F_98 ( V_165 ) ;
char V_110 [ 512 ] ;
T_8 V_167 = sizeof( V_110 ) ;
if ( V_128 . V_168 ) {
V_161 = V_3 -> V_61 . V_169 ;
V_63 = V_3 -> V_61 . V_170 ;
}
if ( F_99 ( V_165 ) ) {
struct V_164 * V_171 ;
F_100 ( V_165 , V_110 , V_167 ) ;
V_166 = V_110 ;
F_101 (pos, evsel) {
struct V_3 * V_172 = F_102 ( V_171 ) ;
if ( V_128 . V_168 ) {
V_161 += V_172 -> V_61 . V_169 ;
V_63 += V_172 -> V_61 . V_170 ;
} else {
V_161 += V_172 -> V_61 . V_63 [ V_162 ] ;
V_63 += V_172 -> V_61 . V_163 ;
}
}
}
V_161 = F_103 ( V_161 , & V_157 ) ;
V_79 = F_67 ( V_91 , V_111 ,
L_22 V_173 ,
V_161 , V_157 , V_166 , V_63 ) ;
if ( V_3 -> V_174 )
V_79 += snprintf ( V_91 + V_79 , V_111 - V_79 ,
L_23 , V_3 -> V_174 ) ;
if ( V_156 )
V_79 += F_67 ( V_91 + V_79 , V_111 - V_79 ,
L_24 ,
( V_156 -> V_175 ? F_104 ( V_156 ) : L_15 ) ,
V_156 -> V_176 ) ;
if ( V_158 )
V_79 += F_67 ( V_91 + V_79 , V_111 - V_79 ,
L_25 , V_158 -> V_177 ) ;
if ( ! F_97 ( V_53 ) ) {
struct V_178 * V_67 = V_53 -> V_60 ;
if ( V_67 -> V_179 )
V_79 += F_67 ( V_91 + V_79 , V_111 - V_79 , L_26 ) ;
}
return V_79 ;
}
static inline void F_105 ( char * * V_180 , int V_32 )
{
int V_181 ;
for ( V_181 = 0 ; V_181 < V_32 ; ++ V_181 )
F_106 ( & V_180 [ V_181 ] ) ;
}
static int F_107 ( void )
{
char * V_182 , * V_180 [ 32 ] , * V_183 [ 32 ] , * V_184 ;
T_10 * V_185 ;
int V_186 = 0 , V_187 = - 1 , V_107 = - 1 ;
struct V_188 * V_189 ;
V_182 = getenv ( L_27 ) ;
if ( ! V_182 )
return V_107 ;
V_185 = F_108 ( V_182 ) ;
if ( ! V_185 )
return V_107 ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_180 , 0 , sizeof( V_183 ) ) ;
while ( ( V_189 = F_109 ( V_185 ) ) ) {
char V_190 [ V_191 ] ;
T_3 V_192 ;
char * V_193 = V_189 -> V_194 ;
T_9 * V_195 ;
if ( ! ( V_189 -> V_196 == V_197 ) )
continue;
snprintf ( V_190 , sizeof( V_190 ) , L_28 , V_182 , V_193 ) ;
V_195 = fopen ( V_190 , L_29 ) ;
if ( ! V_195 )
continue;
if ( fread ( & V_192 , 1 , 8 , V_195 ) < 8 )
goto V_198;
if ( F_110 ( V_192 ) ) {
V_180 [ V_186 ] = F_111 ( V_193 ) ;
if ( ! V_180 [ V_186 ] )
goto V_198;
V_183 [ V_186 ] = F_111 ( V_190 ) ;
if ( ! V_183 [ V_186 ] ) {
F_106 ( & V_180 [ V_186 ] ) ;
F_112 ( L_30 ) ;
fclose ( V_195 ) ;
break;
}
V_186 ++ ;
}
V_198:
fclose ( V_195 ) ;
if ( V_186 >= 32 ) {
F_112 ( L_31
L_32 ) ;
break;
}
}
F_113 ( V_185 ) ;
if ( V_186 ) {
V_187 = F_114 ( V_186 , V_180 ) ;
if ( V_187 < V_186 && V_187 >= 0 ) {
V_184 = F_111 ( V_183 [ V_187 ] ) ;
if ( V_184 ) {
if ( V_199 )
free ( ( void * ) V_200 ) ;
V_200 = V_184 ;
V_199 = true ;
V_107 = 0 ;
} else
F_112 ( L_33 ) ;
}
}
F_105 ( V_180 , V_186 ) ;
F_105 ( V_183 , V_186 ) ;
return V_107 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_3 V_5 = 0 ;
struct V_33 * V_34 = F_20 ( & V_2 -> V_3 -> V_51 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_6 = V_2 -> V_3 -> V_6 ;
return;
}
while ( ( V_34 = F_40 ( V_34 , V_2 -> V_4 ) ) != NULL ) {
V_5 ++ ;
V_34 = F_21 ( V_34 ) ;
}
V_2 -> V_6 = V_5 ;
}
static int F_115 ( struct V_164 * V_165 , int V_63 ,
const char * V_201 ,
bool V_202 ,
struct V_52 * V_53 ,
float V_4 ,
struct V_203 * V_204 )
{
struct V_3 * V_3 = F_102 ( V_165 ) ;
struct V_1 * V_9 = F_92 ( V_3 ) ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
char * V_180 [ 16 ] ;
int V_186 = 0 ;
int V_54 = - 1 ;
char V_110 [ 64 ] ;
char V_209 [ 64 ] ;
int V_56 = V_53 ? V_53 -> V_57 : 0 ;
struct V_127 * V_104 ;
#define F_116 \
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
const char V_210 [] = F_116
L_34
L_35
L_36
L_37
L_38
L_39
L_40 ;
const char V_211 [] = F_116
L_35
L_38
L_39
L_41
L_40 ;
if ( V_9 == NULL )
return - 1 ;
if ( V_4 ) {
V_9 -> V_4 = V_4 ;
F_12 ( V_9 ) ;
}
V_208 = F_117 ( 2 ) ;
if ( V_208 == NULL )
goto V_70;
F_118 ( V_201 ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
F_71 (fmt)
F_119 ( V_104 , V_3 ) ;
if ( V_128 . V_212 )
F_120 ( V_128 . V_212 ) ;
while ( 1 ) {
const struct V_156 * V_156 = NULL ;
const struct V_158 * V_158 = NULL ;
int V_187 = 0 ,
V_213 = - 2 , V_214 = - 2 , V_215 = - 2 ,
V_216 = - 2 , V_217 = - 2 , V_218 = - 2 ;
int V_219 = - 2 , V_220 = - 2 ,
V_221 = - 2 , V_222 = - 2 ;
V_186 = 0 ;
V_54 = F_44 ( V_9 , V_53 ) ;
if ( V_9 -> V_49 != NULL ) {
V_156 = F_96 ( V_9 ) ;
V_158 = V_9 -> V_48 -> V_223 ? V_9 -> V_48 -> V_223 -> V_158 : NULL ;
}
switch ( V_54 ) {
case V_224 :
case V_225 :
if ( V_63 == 1 )
continue;
goto V_226;
case 'a' :
if ( ! V_227 ) {
F_43 ( & V_9 -> V_10 , V_56 * 2 ,
L_42
L_43 ) ;
continue;
}
if ( V_9 -> V_48 == NULL ||
V_9 -> V_48 -> V_228 == NULL ||
V_9 -> V_48 -> V_223 -> V_158 -> V_229 )
continue;
goto V_230;
case 'P' :
F_89 ( V_9 ) ;
continue;
case 'd' :
goto V_214;
case 'V' :
V_9 -> V_95 = ! V_9 -> V_95 ;
continue;
case 't' :
goto V_215;
case '/' :
if ( F_121 ( L_44 ,
L_45 ,
V_110 , L_46 ,
V_56 * 2 ) == V_69 ) {
V_3 -> V_231 = * V_110 ? V_110 : NULL ;
F_122 ( V_3 ) ;
F_11 ( V_9 ) ;
}
continue;
case 'r' :
if ( F_97 ( V_53 ) )
goto V_232;
continue;
case 's' :
if ( F_97 ( V_53 ) )
goto V_233;
continue;
case 'i' :
if ( V_204 -> V_234 )
F_123 ( V_204 ) ;
continue;
case 'F' :
V_128 . V_168 ^= 1 ;
continue;
case 'z' :
if ( ! F_97 ( V_53 ) ) {
struct V_178 * V_67 = V_53 -> V_60 ;
V_67 -> V_179 = ! V_67 -> V_179 ;
}
continue;
case V_235 :
case 'h' :
case '?' :
F_124 ( & V_9 -> V_10 ,
F_97 ( V_53 ) ? V_210 : V_211 ) ;
continue;
case V_69 :
case V_236 :
break;
case V_237 : {
const void * V_67 ;
if ( F_125 ( V_208 ) ) {
if ( V_202 )
goto V_226;
continue;
}
V_67 = F_126 ( V_208 ) ;
if ( V_67 == & V_9 -> V_3 -> V_159 )
goto V_238;
if ( V_67 == & V_9 -> V_3 -> V_160 )
goto V_239;
continue;
}
case V_240 :
if ( ! V_202 &&
! F_127 ( & V_9 -> V_10 ,
L_47 ) )
continue;
case 'q' :
case F_128 ( 'c' ) :
goto V_226;
default:
continue;
}
if ( ! V_227 )
goto V_241;
if ( V_242 == V_243 ) {
V_206 = V_9 -> V_49 -> V_205 ;
if ( V_9 -> V_48 != NULL &&
V_206 &&
V_206 -> V_244 . V_228 != NULL &&
! V_206 -> V_244 . V_223 -> V_158 -> V_229 &&
F_64 ( & V_180 [ V_186 ] , L_48 ,
V_206 -> V_244 . V_228 -> V_193 ) > 0 )
V_216 = V_186 ++ ;
if ( V_9 -> V_48 != NULL &&
V_206 &&
V_206 -> V_245 . V_228 != NULL &&
! V_206 -> V_245 . V_223 -> V_158 -> V_229 &&
( V_206 -> V_245 . V_228 != V_206 -> V_244 . V_228 ||
V_206 -> V_245 . V_223 -> V_158 != V_206 -> V_244 . V_223 -> V_158 ) &&
F_64 ( & V_180 [ V_186 ] , L_48 ,
V_206 -> V_245 . V_228 -> V_193 ) > 0 )
V_217 = V_186 ++ ;
} else {
if ( V_9 -> V_48 != NULL &&
V_9 -> V_48 -> V_228 != NULL &&
! V_9 -> V_48 -> V_223 -> V_158 -> V_229 ) {
struct V_246 * V_247 ;
V_247 = F_129 ( V_9 -> V_48 -> V_228 ) ;
if ( V_247 -> V_248 &&
F_64 ( & V_180 [ V_186 ] , L_48 ,
V_9 -> V_48 -> V_228 -> V_193 ) > 0 )
V_213 = V_186 ++ ;
}
}
if ( V_156 != NULL &&
F_64 ( & V_180 [ V_186 ] , L_49 ,
( V_9 -> V_3 -> V_160 ? L_50 : L_51 ) ,
( V_156 -> V_175 ? F_104 ( V_156 ) : L_15 ) ,
V_156 -> V_176 ) > 0 )
V_215 = V_186 ++ ;
if ( V_158 != NULL &&
F_64 ( & V_180 [ V_186 ] , L_52 ,
( V_9 -> V_3 -> V_159 ? L_50 : L_51 ) ,
( V_158 -> V_249 ? L_53 : V_158 -> V_177 ) ) > 0 )
V_214 = V_186 ++ ;
if ( V_9 -> V_48 != NULL &&
V_9 -> V_48 -> V_223 != NULL &&
F_64 ( & V_180 [ V_186 ] , L_54 ) > 0 )
V_218 = V_186 ++ ;
if ( V_9 -> V_49 ) {
struct V_250 * V_228 ;
if ( F_64 ( & V_180 [ V_186 ] , L_55 ,
F_104 ( V_9 -> V_49 -> V_156 ) ) > 0 )
V_219 = V_186 ++ ;
V_228 = V_9 -> V_49 -> V_23 . V_228 ;
if ( V_228 && V_228 -> V_251 &&
F_64 ( & V_180 [ V_186 ] , L_56 ,
V_228 -> V_193 ) > 0 )
V_220 = V_186 ++ ;
}
if ( F_64 ( & V_180 [ V_186 ] , L_57 ) > 0 )
V_221 = V_186 ++ ;
if ( F_97 ( V_53 ) && F_64 ( & V_180 [ V_186 ] ,
L_58 ) > 0 )
V_222 = V_186 ++ ;
V_241:
V_180 [ V_186 ++ ] = ( char * ) L_59 ;
V_252:
V_187 = F_114 ( V_186 , V_180 ) ;
if ( V_187 == V_186 - 1 )
break;
if ( V_187 == - 1 ) {
F_105 ( V_180 , V_186 - 1 ) ;
continue;
}
if ( V_187 == V_213 || V_187 == V_217 || V_187 == V_216 ) {
struct V_25 * V_26 ;
struct V_246 * V_247 ;
int V_150 ;
V_230:
if ( ! V_253 && F_130 ( V_204 ) )
continue;
V_26 = F_95 ( V_9 ) ;
if ( V_26 == NULL )
continue;
if ( V_187 == V_216 ) {
V_26 -> V_23 . V_228 = V_26 -> V_205 -> V_244 . V_228 ;
V_26 -> V_23 . V_223 = V_26 -> V_205 -> V_244 . V_223 ;
} else if ( V_187 == V_217 ) {
V_26 -> V_23 . V_228 = V_26 -> V_205 -> V_245 . V_228 ;
V_26 -> V_23 . V_223 = V_26 -> V_205 -> V_245 . V_223 ;
}
V_247 = F_129 ( V_26 -> V_23 . V_228 ) ;
if ( ! V_247 -> V_248 )
continue;
V_26 -> V_254 = true ;
V_150 = F_131 ( V_26 , V_165 , V_53 ) ;
V_26 -> V_254 = false ;
if ( ( V_150 == 'q' || V_150 == F_128 ( 'c' ) )
&& V_217 != - 2 && V_216 != - 2 )
goto V_252;
F_48 ( & V_9 -> V_10 , V_9 -> V_3 -> V_5 ) ;
if ( V_150 )
F_132 ( & V_9 -> V_10 ) ;
} else if ( V_187 == V_218 )
F_133 ( V_9 -> V_48 -> V_223 ) ;
else if ( V_187 == V_214 ) {
V_214:
if ( V_9 -> V_3 -> V_159 ) {
F_134 ( V_208 , & V_9 -> V_3 -> V_159 ) ;
V_238:
F_50 () ;
V_9 -> V_3 -> V_159 = NULL ;
F_135 ( V_255 , false ) ;
} else {
if ( V_158 == NULL )
continue;
F_51 ( L_60 ,
V_158 -> V_249 ? L_53 : V_158 -> V_177 ) ;
V_9 -> V_3 -> V_159 = V_158 ;
F_135 ( V_255 , true ) ;
F_136 ( V_208 , & V_9 -> V_3 -> V_159 ) ;
}
F_137 ( V_3 ) ;
F_11 ( V_9 ) ;
} else if ( V_187 == V_215 ) {
V_215:
if ( V_9 -> V_3 -> V_160 ) {
F_134 ( V_208 , & V_9 -> V_3 -> V_160 ) ;
V_239:
F_50 () ;
V_9 -> V_3 -> V_160 = NULL ;
F_135 ( V_256 , false ) ;
} else {
F_51 ( L_61 ,
V_156 -> V_175 ? F_104 ( V_156 ) : L_15 ,
V_156 -> V_176 ) ;
V_9 -> V_3 -> V_160 = V_156 ;
F_135 ( V_256 , false ) ;
F_136 ( V_208 , & V_9 -> V_3 -> V_160 ) ;
}
F_138 ( V_3 ) ;
F_11 ( V_9 ) ;
}
else if ( V_187 == V_221 || V_187 == V_219 ||
V_187 == V_220 ) {
V_232:
memset ( V_209 , 0 , 64 ) ;
if ( V_187 == V_219 )
sprintf ( V_209 , L_62 , F_104 ( V_9 -> V_49 -> V_156 ) ) ;
if ( V_187 == V_220 )
sprintf ( V_209 , L_63 , V_9 -> V_49 -> V_23 . V_228 -> V_193 ) ;
F_139 ( V_209 ) ;
}
else if ( V_187 == V_222 ) {
V_233:
if ( ! F_107 () ) {
V_54 = V_257 ;
break;
} else
F_112 ( L_64
L_65 ) ;
}
}
V_226:
F_140 ( V_208 ) ;
V_70:
F_94 ( V_9 ) ;
F_105 ( V_180 , V_186 - 1 ) ;
return V_54 ;
}
static void F_141 ( struct V_8 * V_9 ,
void * V_125 , int V_19 )
{
struct V_258 * V_259 = F_6 ( V_9 ,
struct V_258 , V_10 ) ;
struct V_164 * V_165 = F_30 ( V_125 , struct V_164 , V_31 ) ;
struct V_3 * V_3 = F_102 ( V_165 ) ;
bool V_109 = F_54 ( V_9 , V_19 ) ;
unsigned long V_63 = V_3 -> V_61 . V_63 [ V_162 ] ;
const char * V_166 = F_98 ( V_165 ) ;
char V_91 [ 256 ] , V_157 ;
const char * V_260 = L_8 ;
T_8 V_79 ;
F_55 ( V_9 , V_109 ? V_76 :
V_75 ) ;
if ( F_99 ( V_165 ) ) {
struct V_164 * V_171 ;
V_166 = F_142 ( V_165 ) ;
F_101 (pos, evsel) {
struct V_3 * V_172 = F_102 ( V_171 ) ;
V_63 += V_172 -> V_61 . V_63 [ V_162 ] ;
}
}
V_63 = F_103 ( V_63 , & V_157 ) ;
V_79 = F_67 ( V_91 , sizeof( V_91 ) , L_66 , V_63 ,
V_157 , V_157 == ' ' ? L_15 : L_8 , V_166 ) ;
F_57 ( L_13 , V_91 ) ;
V_63 = V_3 -> V_61 . V_63 [ V_64 ] ;
if ( V_63 != 0 ) {
V_259 -> V_261 = true ;
if ( ! V_109 )
F_55 ( V_9 , V_262 ) ;
V_63 = F_103 ( V_63 , & V_157 ) ;
V_79 += F_67 ( V_91 , sizeof( V_91 ) , L_67 ,
V_63 , V_157 , V_157 == ' ' ? L_15 : L_8 ) ;
V_260 = V_91 ;
}
F_56 ( V_260 , V_9 -> V_18 - V_79 ) ;
if ( V_109 )
V_259 -> V_48 = V_165 ;
}
static int F_143 ( struct V_258 * V_259 ,
int V_63 , const char * V_263 ,
struct V_52 * V_53 )
{
struct V_264 * V_265 = V_259 -> V_10 . V_266 ;
struct V_164 * V_171 ;
const char * V_55 = L_68 ;
int V_56 = V_53 ? V_53 -> V_57 : 0 ;
int V_54 ;
if ( F_46 ( & V_259 -> V_10 , V_55 ,
L_69 ) < 0 )
return - 1 ;
while ( 1 ) {
V_54 = F_47 ( & V_259 -> V_10 , V_56 ) ;
switch ( V_54 ) {
case V_58 :
V_53 -> V_59 ( V_53 -> V_60 ) ;
if ( ! V_259 -> V_267 && V_259 -> V_261 ) {
F_42 ( & V_259 -> V_10 ) ;
V_259 -> V_267 = true ;
}
continue;
case V_236 :
case V_69 :
if ( ! V_259 -> V_48 )
continue;
V_171 = V_259 -> V_48 ;
V_268:
F_144 ( V_265 , V_171 ) ;
if ( V_53 )
V_53 -> V_59 ( V_53 -> V_60 ) ;
V_54 = F_115 ( V_171 , V_63 , V_263 ,
true , V_53 ,
V_259 -> V_4 ,
V_259 -> V_204 ) ;
F_49 ( & V_259 -> V_10 , V_55 ) ;
switch ( V_54 ) {
case V_224 :
if ( V_171 -> V_31 . V_41 == & V_265 -> V_51 )
V_171 = F_145 ( V_265 ) ;
else
V_171 = F_146 ( V_171 ) ;
goto V_268;
case V_225 :
if ( V_171 -> V_31 . V_44 == & V_265 -> V_51 )
V_171 = F_147 ( V_265 ) ;
else
V_171 = F_148 ( V_171 ) ;
goto V_268;
case V_240 :
if ( ! F_127 ( & V_259 -> V_10 ,
L_47 ) )
continue;
case V_257 :
case 'q' :
case F_128 ( 'c' ) :
goto V_70;
default:
continue;
}
case V_237 :
continue;
case V_240 :
if ( ! F_127 ( & V_259 -> V_10 ,
L_47 ) )
continue;
case 'q' :
case F_128 ( 'c' ) :
goto V_70;
default:
continue;
}
}
V_70:
F_52 ( & V_259 -> V_10 ) ;
return V_54 ;
}
static bool F_149 ( struct V_8 * V_9 V_78 ,
void * V_125 )
{
struct V_164 * V_165 = F_30 ( V_125 , struct V_164 , V_31 ) ;
if ( V_128 . V_269 && ! F_150 ( V_165 ) )
return true ;
return false ;
}
static int F_151 ( struct V_264 * V_265 ,
int V_5 , const char * V_263 ,
struct V_52 * V_53 ,
float V_4 ,
struct V_203 * V_204 )
{
struct V_164 * V_171 ;
struct V_258 V_259 = {
. V_10 = {
. V_51 = & V_265 -> V_51 ,
. V_57 = V_270 ,
. V_153 = V_271 ,
. V_272 = F_141 ,
. V_273 = F_149 ,
. V_5 = V_5 ,
. V_266 = V_265 ,
} ,
. V_4 = V_4 ,
. V_204 = V_204 ,
} ;
F_118 ( L_70 ) ;
F_152 (evlist, pos) {
const char * V_166 = F_98 ( V_171 ) ;
T_8 V_274 = strlen ( V_166 ) + 7 ;
if ( V_259 . V_10 . V_18 < V_274 )
V_259 . V_10 . V_18 = V_274 ;
}
return F_143 ( & V_259 , V_5 , V_263 , V_53 ) ;
}
int F_153 ( struct V_264 * V_265 , const char * V_263 ,
struct V_52 * V_53 ,
float V_4 ,
struct V_203 * V_204 )
{
int V_5 = V_265 -> V_5 ;
V_275:
if ( V_5 == 1 ) {
struct V_164 * V_39 = F_145 ( V_265 ) ;
return F_115 ( V_39 , V_5 , V_263 ,
false , V_53 , V_4 ,
V_204 ) ;
}
if ( V_128 . V_269 ) {
struct V_164 * V_171 ;
V_5 = 0 ;
F_152 (evlist, pos) {
if ( F_150 ( V_171 ) )
V_5 ++ ;
}
if ( V_5 == 1 )
goto V_275;
}
return F_151 ( V_265 , V_5 , V_263 ,
V_53 , V_4 , V_204 ) ;
}
