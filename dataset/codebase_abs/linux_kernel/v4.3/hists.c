static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) || V_2 -> V_4 || V_5 . V_6 ;
}
static int F_3 ( struct V_1 * V_7 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 = V_7 -> V_3 ;
int V_10 = 0 ;
for ( V_9 = F_4 ( & V_3 -> V_11 ) ;
( V_9 = F_5 ( V_9 , V_7 -> V_4 ) ) != NULL ;
V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_13 =
F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_13 -> V_14 )
V_10 += V_13 -> V_15 ;
}
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_16 ;
if ( F_1 ( V_2 ) )
V_16 = V_2 -> V_17 ;
else
V_16 = V_2 -> V_3 -> V_16 ;
V_2 -> V_18 = F_3 ( V_2 ) ;
return V_16 + V_2 -> V_18 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_19 * V_7 = & V_2 -> V_20 ;
T_2 V_21 = V_2 -> V_22 ? 1 : 0 , V_23 ;
V_7 -> V_24 = V_7 -> V_25 - V_21 ;
V_23 = V_7 -> V_26 - V_7 -> V_27 ;
if ( V_23 >= V_7 -> V_24 )
V_7 -> V_26 -= V_23 - V_7 -> V_24 + 1 ;
}
static void F_10 ( struct V_19 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
V_7 -> V_28 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_7 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_7 , int V_29 , int V_30 )
{
T_2 V_21 = V_7 -> V_22 ? 1 : 0 ;
F_15 ( & V_7 -> V_20 , V_29 + V_21 , V_30 ) ;
}
static void F_16 ( struct V_1 * V_7 )
{
V_7 -> V_18 = 0 ;
F_17 ( V_7 ) ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_10 ( & V_7 -> V_20 ) ;
F_18 ( & V_7 -> V_20 ) ;
}
static char F_19 ( bool V_14 )
{
return V_14 ? '-' : '+' ;
}
static char F_20 ( const struct V_12 * V_13 )
{
return V_13 -> V_31 ? F_19 ( V_13 -> V_14 ) : ' ' ;
}
static char F_21 ( const struct V_32 * V_33 )
{
return V_33 -> V_31 ? F_19 ( V_33 -> V_14 ) : ' ' ;
}
static void F_22 ( struct V_32 * V_33 , bool V_34 )
{
V_33 -> V_14 = V_34 ? V_33 -> V_31 : false ;
}
static int F_23 ( struct V_35 * V_36 )
{
int V_37 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
F_24 (chain, &child->val, list) {
++ V_37 ;
V_41 = F_21 ( V_40 ) ;
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' )
V_37 += F_23 ( V_39 ) ;
}
return V_37 ;
}
static int F_25 ( struct V_35 * V_36 )
{
struct V_32 * V_40 ;
bool V_14 = false ;
int V_37 = 0 ;
F_24 (chain, &node->val, list) {
++ V_37 ;
V_14 = V_40 -> V_14 ;
}
if ( V_14 )
V_37 += F_23 ( V_36 ) ;
return V_37 ;
}
static int F_26 ( struct V_38 * V_40 )
{
struct V_8 * V_9 ;
int V_37 = 0 ;
for ( V_9 = F_4 ( V_40 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
V_37 += F_25 ( V_36 ) ;
}
return V_37 ;
}
static bool F_27 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return false ;
if ( ! V_13 -> V_31 )
return false ;
V_13 -> V_14 = ! V_13 -> V_14 ;
return true ;
}
static bool F_28 ( struct V_32 * V_33 )
{
if ( ! V_33 )
return false ;
if ( ! V_33 -> V_31 )
return false ;
V_33 -> V_14 = ! V_33 -> V_14 ;
return true ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_4 ( & V_36 -> V_38 ) ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
bool V_42 = true ;
F_24 (chain, &child->val, list) {
if ( V_42 ) {
V_42 = false ;
V_40 -> V_31 = V_40 -> V_43 . V_44 != & V_39 -> V_45 ||
! F_30 ( & V_39 -> V_38 ) ;
} else
V_40 -> V_31 = V_40 -> V_43 . V_44 == & V_39 -> V_45 &&
! F_30 ( & V_39 -> V_38 ) ;
}
F_29 ( V_39 ) ;
}
}
static void F_31 ( struct V_35 * V_36 ,
bool V_46 )
{
struct V_32 * V_40 ;
V_40 = F_32 ( V_36 -> V_45 . V_44 , struct V_32 , V_43 ) ;
V_40 -> V_31 = V_46 ;
if ( ! F_33 ( & V_36 -> V_45 ) ) {
V_40 = F_32 ( V_36 -> V_45 . V_47 , struct V_32 , V_43 ) ;
V_40 -> V_31 = ! F_30 ( & V_36 -> V_38 ) ;
}
F_29 ( V_36 ) ;
}
static void F_34 ( struct V_38 * V_48 )
{
struct V_8 * V_9 = F_4 ( V_48 ) ;
bool V_46 = V_9 && F_6 ( V_9 ) ;
for ( V_9 = F_4 ( V_48 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
F_31 ( V_36 , V_46 ) ;
}
}
static void F_35 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_49 ) {
V_13 -> V_31 = ! F_30 ( & V_13 -> V_50 ) ;
F_34 ( & V_13 -> V_50 ) ;
V_13 -> V_49 = true ;
}
}
static bool F_36 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_51 ;
struct V_52 * V_53 = V_7 -> V_54 ;
struct V_32 * V_33 = F_11 ( V_53 , struct V_32 , V_53 ) ;
bool V_31 ;
if ( V_53 == & V_13 -> V_53 )
V_31 = F_27 ( V_13 ) ;
else
V_31 = F_28 ( V_33 ) ;
if ( V_31 ) {
F_35 ( V_13 ) ;
V_7 -> V_20 . V_16 -= V_13 -> V_15 ;
V_7 -> V_18 -= V_13 -> V_15 ;
if ( V_13 -> V_14 )
V_13 -> V_15 = F_26 ( & V_13 -> V_50 ) ;
else
V_13 -> V_15 = 0 ;
V_7 -> V_20 . V_16 += V_13 -> V_15 ;
V_7 -> V_18 += V_13 -> V_15 ;
return true ;
}
return false ;
}
static int F_37 ( struct V_35 * V_36 , bool V_34 )
{
int V_37 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
bool V_31 = false ;
F_24 (chain, &child->val, list) {
++ V_37 ;
F_22 ( V_40 , V_34 ) ;
V_31 = V_40 -> V_31 ;
}
if ( V_31 )
V_37 += F_37 ( V_39 , V_34 ) ;
}
return V_37 ;
}
static int F_38 ( struct V_35 * V_36 , bool V_34 )
{
struct V_32 * V_40 ;
bool V_31 = false ;
int V_37 = 0 ;
F_24 (chain, &node->val, list) {
++ V_37 ;
F_22 ( V_40 , V_34 ) ;
V_31 = V_40 -> V_31 ;
}
if ( V_31 )
V_37 += F_37 ( V_36 , V_34 ) ;
return V_37 ;
}
static int F_39 ( struct V_38 * V_40 , bool V_34 )
{
struct V_8 * V_9 ;
int V_37 = 0 ;
for ( V_9 = F_4 ( V_40 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
V_37 += F_38 ( V_36 , V_34 ) ;
}
return V_37 ;
}
static void F_40 ( struct V_12 * V_13 , bool V_34 )
{
F_35 ( V_13 ) ;
V_13 -> V_14 = V_34 ? V_13 -> V_31 : false ;
if ( V_13 -> V_31 ) {
int V_37 = F_39 ( & V_13 -> V_50 , V_34 ) ;
V_13 -> V_15 = V_34 ? V_37 : 0 ;
} else
V_13 -> V_15 = 0 ;
}
static void
F_41 ( struct V_1 * V_7 , bool V_34 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 = V_7 -> V_3 ;
for ( V_9 = F_4 ( & V_3 -> V_11 ) ;
( V_9 = F_5 ( V_9 , V_7 -> V_4 ) ) != NULL ;
V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
F_40 ( V_13 , V_34 ) ;
V_7 -> V_18 += V_13 -> V_15 ;
}
}
static void F_42 ( struct V_1 * V_7 , bool V_34 )
{
V_7 -> V_18 = 0 ;
F_41 ( V_7 , V_34 ) ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_18 ( & V_7 -> V_20 ) ;
}
static void F_43 ( struct V_19 * V_7 )
{
F_44 ( V_7 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_45 ( struct V_1 * V_7 , const char * V_55 )
{
int V_56 ;
char V_57 [ 160 ] ;
struct V_58 * V_59 = V_7 -> V_59 ;
int V_60 = V_59 ? V_59 -> V_61 : 0 ;
V_7 -> V_20 . V_11 = & V_7 -> V_3 -> V_11 ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_46 ( V_7 -> V_3 , V_59 , V_57 , sizeof( V_57 ) ) ;
if ( F_47 ( & V_7 -> V_20 , V_57 , V_55 ) < 0 )
return - 1 ;
while ( 1 ) {
V_56 = F_48 ( & V_7 -> V_20 , V_60 ) ;
switch ( V_56 ) {
case V_62 : {
T_3 V_16 ;
V_59 -> V_63 ( V_59 -> V_64 ) ;
if ( F_1 ( V_7 ) )
F_17 ( V_7 ) ;
V_16 = F_8 ( V_7 ) ;
F_49 ( & V_7 -> V_20 , V_16 ) ;
if ( V_7 -> V_3 -> V_65 . V_66 !=
V_7 -> V_3 -> V_65 . V_67 [ V_68 ] ) {
V_7 -> V_3 -> V_65 . V_66 =
V_7 -> V_3 -> V_65 . V_67 [ V_68 ] ;
F_43 ( & V_7 -> V_20 ) ;
}
F_46 ( V_7 -> V_3 ,
V_59 , V_57 , sizeof( V_57 ) ) ;
F_50 ( & V_7 -> V_20 , V_57 ) ;
continue;
}
case 'D' : {
static int V_69 ;
struct V_12 * V_70 = F_7 ( V_7 -> V_20 . V_71 ,
struct V_12 , V_8 ) ;
F_51 () ;
F_52 ( L_6 ,
V_69 ++ , V_7 -> V_20 . V_16 ,
V_7 -> V_3 -> V_16 ,
V_7 -> V_20 . V_24 ,
V_7 -> V_20 . V_26 ,
V_7 -> V_20 . V_27 ,
V_70 -> V_72 , V_70 -> V_15 ) ;
}
break;
case 'C' :
F_42 ( V_7 , false ) ;
break;
case 'E' :
F_42 ( V_7 , true ) ;
break;
case 'H' :
V_7 -> V_22 = ! V_7 -> V_22 ;
F_9 ( V_7 ) ;
break;
case V_73 :
if ( F_36 ( V_7 ) )
break;
default:
goto V_74;
}
}
V_74:
F_53 ( & V_7 -> V_20 ) ;
return V_56 ;
}
static void F_54 ( struct V_1 * V_7 ,
struct V_32 * V_40 ,
const char * V_75 , int V_76 ,
unsigned short V_29 ,
struct V_77 * V_64 )
{
int V_78 , V_28 ;
char V_41 = F_21 ( V_40 ) ;
bool V_79 = V_7 -> V_80 && V_40 -> V_53 . V_81 && F_55 ( V_40 -> V_53 . V_81 ) -> V_82 ;
V_78 = V_83 ;
V_28 = V_7 -> V_20 . V_28 - ( V_76 + 2 ) ;
if ( F_56 ( & V_7 -> V_20 , V_29 ) ) {
V_7 -> V_54 = & V_40 -> V_53 ;
V_78 = V_84 ;
V_64 -> V_85 = true ;
}
F_57 ( & V_7 -> V_20 , V_78 ) ;
F_14 ( V_7 , V_29 , 0 ) ;
F_58 ( & V_7 -> V_20 , L_7 , V_76 ) ;
F_59 ( & V_7 -> V_20 , L_8 , V_41 ) ;
F_60 ( & V_7 -> V_20 , V_79 ? V_86 : ' ' ) ;
F_58 ( & V_7 -> V_20 , V_75 , V_28 ) ;
}
static void F_61 ( struct V_1 * V_20 V_87 ,
struct V_32 * V_40 ,
const char * V_75 , int V_76 ,
unsigned short V_29 V_87 ,
struct V_77 * V_64 )
{
char V_41 = F_21 ( V_40 ) ;
V_64 -> V_88 += fprintf ( V_64 -> V_89 , L_9 , V_76 , L_7 ,
V_41 , V_75 ) ;
}
static bool F_62 ( struct V_1 * V_7 ,
unsigned short V_29 )
{
return V_7 -> V_20 . V_24 == V_29 ;
}
static bool F_63 ( struct V_1 * V_7 V_87 ,
unsigned short V_29 V_87 )
{
return false ;
}
static int F_64 ( struct V_1 * V_7 ,
struct V_38 * V_48 , int V_90 ,
unsigned short V_29 , T_3 V_91 ,
T_4 V_92 ,
struct V_77 * V_64 ,
T_5 V_93 )
{
struct V_8 * V_36 ;
int V_94 = V_29 , V_76 = V_90 * V_95 ;
T_3 V_96 ;
bool V_97 ;
V_36 = F_4 ( V_48 ) ;
V_97 = V_36 && F_6 ( V_36 ) ;
while ( V_36 ) {
struct V_35 * V_39 = F_7 ( V_36 , struct V_35 , V_8 ) ;
struct V_8 * V_44 = F_6 ( V_36 ) ;
T_3 V_98 = F_65 ( V_39 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
int V_42 = true ;
int V_99 = 0 ;
F_24 (chain, &child->val, list) {
char V_100 [ 1024 ] , * V_101 ;
const char * V_75 ;
bool V_102 = V_42 ;
if ( V_42 )
V_42 = false ;
else if ( V_97 )
V_99 = V_95 ;
V_41 = F_21 ( V_40 ) ;
if ( V_64 -> V_72 != 0 ) {
V_64 -> V_72 -- ;
goto V_103;
}
V_101 = NULL ;
V_75 = F_66 ( V_40 , V_100 , sizeof( V_100 ) ,
V_7 -> V_80 ) ;
if ( V_102 && V_97 ) {
double V_104 = V_98 * 100.0 / V_91 ;
if ( F_67 ( & V_101 , L_10 , V_104 , V_75 ) < 0 )
V_75 = L_11 ;
else
V_75 = V_101 ;
}
V_92 ( V_7 , V_40 , V_75 , V_76 + V_99 , V_29 , V_64 ) ;
free ( V_101 ) ;
if ( V_93 ( V_7 , ++ V_29 ) )
goto V_74;
V_103:
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' ) {
const int V_105 = V_90 + ( V_99 ? 2 : 1 ) ;
if ( V_106 . V_107 == V_108 )
V_96 = V_39 -> V_109 ;
else
V_96 = V_91 ;
V_29 += F_64 ( V_7 , & V_39 -> V_38 ,
V_105 , V_29 , V_96 ,
V_92 , V_64 , V_93 ) ;
}
if ( V_93 ( V_7 , V_29 ) )
break;
V_36 = V_44 ;
}
V_74:
return V_29 - V_94 ;
}
static int F_68 ( struct V_110 * V_111 , const char * V_112 , ... )
{
struct V_113 * V_64 = V_111 -> V_114 ;
int V_115 , V_116 ;
T_6 args ;
double V_104 ;
va_start ( args , V_112 ) ;
V_116 = va_arg ( args , int ) ;
V_104 = va_arg ( args , double ) ;
va_end ( args ) ;
F_69 ( V_64 -> V_20 , V_104 , V_64 -> V_117 ) ;
V_115 = F_70 ( V_111 -> V_118 , V_111 -> V_119 , V_112 , V_116 , V_104 ) ;
F_59 ( V_64 -> V_20 , L_12 , V_111 -> V_118 ) ;
F_71 ( V_111 , V_115 ) ;
return V_115 ;
}
void F_72 ( void )
{
V_120 [ V_121 ] . V_78 =
V_122 ;
V_120 [ V_123 ] . V_78 =
V_124 ;
V_120 [ V_125 ] . V_78 =
V_126 ;
V_120 [ V_127 ] . V_78 =
V_128 ;
V_120 [ V_129 ] . V_78 =
V_130 ;
V_120 [ V_131 ] . V_78 =
V_132 ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_12 * V_133 ,
unsigned short V_29 )
{
char V_134 [ 256 ] ;
int V_88 = 0 ;
int V_28 = V_7 -> V_20 . V_28 ;
char V_41 = ' ' ;
bool V_117 = F_56 ( & V_7 -> V_20 , V_29 ) ;
T_7 V_72 = V_133 -> V_72 ;
bool V_42 = true ;
struct V_135 * V_112 ;
if ( V_117 ) {
V_7 -> V_51 = V_133 ;
V_7 -> V_54 = & V_133 -> V_53 ;
}
if ( V_5 . V_136 ) {
F_35 ( V_133 ) ;
V_41 = F_20 ( V_133 ) ;
}
if ( V_72 == 0 ) {
struct V_113 V_64 = {
. V_20 = & V_7 -> V_20 ,
. V_41 = V_41 ,
. V_117 = V_117 ,
} ;
struct V_110 V_111 = {
. V_118 = V_134 ,
. V_119 = sizeof( V_134 ) ,
. V_114 = & V_64 ,
} ;
F_14 ( V_7 , V_29 , 0 ) ;
F_74 (fmt) {
if ( F_75 ( V_112 ) )
continue;
if ( V_117 && V_7 -> V_20 . V_137 ) {
F_57 ( & V_7 -> V_20 ,
V_84 ) ;
} else {
F_57 ( & V_7 -> V_20 ,
V_83 ) ;
}
if ( V_42 ) {
if ( V_5 . V_136 ) {
F_59 ( & V_7 -> V_20 , L_13 , V_41 ) ;
V_28 -= 2 ;
}
V_42 = false ;
} else {
F_59 ( & V_7 -> V_20 , L_14 ) ;
V_28 -= 2 ;
}
if ( V_112 -> V_78 ) {
V_28 -= V_112 -> V_78 ( V_112 , & V_111 , V_133 ) ;
} else {
V_28 -= V_112 -> V_133 ( V_112 , & V_111 , V_133 ) ;
F_59 ( & V_7 -> V_20 , L_12 , V_134 ) ;
}
}
if ( ! V_7 -> V_20 . V_137 )
V_28 += 1 ;
F_58 ( & V_7 -> V_20 , L_15 , V_28 ) ;
++ V_29 ;
++ V_88 ;
} else
-- V_72 ;
if ( V_41 == '-' && V_29 != V_7 -> V_20 . V_24 ) {
T_3 V_91 = F_76 ( V_133 -> V_3 ) ;
struct V_77 V_64 = {
. V_72 = V_72 ,
. V_85 = V_117 ,
} ;
if ( V_106 . V_107 == V_108 ) {
if ( V_5 . V_138 )
V_91 = V_133 -> V_139 -> V_140 ;
else
V_91 = V_133 -> V_141 . V_140 ;
}
V_88 += F_64 ( V_7 ,
& V_133 -> V_50 , 1 , V_29 , V_91 ,
F_54 , & V_64 ,
F_62 ) ;
if ( V_64 . V_85 )
V_7 -> V_51 = V_133 ;
}
return V_88 ;
}
static int F_77 ( struct V_110 * V_111 , int V_142 )
{
F_71 ( V_111 , V_142 ) ;
return V_111 -> V_119 <= 0 ;
}
static int F_78 ( char * V_118 , T_8 V_119 , struct V_3 * V_3 )
{
struct V_110 V_143 = {
. V_118 = V_118 ,
. V_119 = V_119 ,
} ;
struct V_135 * V_112 ;
T_8 V_115 = 0 ;
if ( V_5 . V_136 ) {
V_115 = F_70 ( V_118 , V_119 , L_14 ) ;
if ( F_77 ( & V_143 , V_115 ) )
return V_115 ;
}
F_74 (fmt) {
if ( F_75 ( V_112 ) )
continue;
V_115 = V_112 -> V_144 ( V_112 , & V_143 , F_79 ( V_3 ) ) ;
if ( F_77 ( & V_143 , V_115 ) )
break;
V_115 = F_70 ( V_143 . V_118 , V_143 . V_119 , L_14 ) ;
if ( F_77 ( & V_143 , V_115 ) )
break;
}
return V_115 ;
}
static void F_80 ( struct V_1 * V_7 )
{
char V_145 [ 1024 ] ;
F_78 ( V_145 , sizeof( V_145 ) , V_7 -> V_3 ) ;
F_15 ( & V_7 -> V_20 , 0 , 0 ) ;
F_57 ( & V_7 -> V_20 , V_146 ) ;
F_58 ( & V_7 -> V_20 , V_145 , V_7 -> V_20 . V_28 + 1 ) ;
}
static void F_81 ( struct V_19 * V_7 )
{
if ( V_7 -> V_71 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
V_7 -> V_71 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
}
}
static unsigned int F_82 ( struct V_19 * V_7 )
{
unsigned V_29 = 0 ;
T_2 V_21 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
if ( V_2 -> V_22 ) {
F_80 ( V_2 ) ;
V_21 = 1 ;
}
F_81 ( V_7 ) ;
for ( V_9 = V_7 -> V_71 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_104 ;
if ( V_70 -> V_147 )
continue;
V_104 = F_83 ( V_70 ) ;
if ( V_104 < V_2 -> V_4 )
continue;
V_29 += F_73 ( V_2 , V_70 , V_29 ) ;
if ( V_29 == V_7 -> V_24 )
break;
}
return V_29 + V_21 ;
}
static struct V_8 * F_5 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_104 = F_83 ( V_70 ) ;
if ( ! V_70 -> V_147 && V_104 >= V_4 )
return V_9 ;
V_9 = F_6 ( V_9 ) ;
}
return NULL ;
}
static struct V_8 * F_84 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_104 = F_83 ( V_70 ) ;
if ( ! V_70 -> V_147 && V_104 >= V_4 )
return V_9 ;
V_9 = F_85 ( V_9 ) ;
}
return NULL ;
}
static void F_86 ( struct V_19 * V_7 ,
T_7 V_76 , int V_148 )
{
struct V_12 * V_70 ;
struct V_8 * V_9 ;
bool V_42 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
if ( V_7 -> V_16 == 0 )
return;
F_81 ( V_7 ) ;
switch ( V_148 ) {
case V_149 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_150 :
V_9 = V_7 -> V_71 ;
goto V_151;
case V_152 :
V_9 = F_84 ( F_87 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
V_42 = false ;
break;
default:
return;
}
V_70 = F_7 ( V_7 -> V_71 , struct V_12 , V_8 ) ;
V_70 -> V_72 = 0 ;
V_151:
if ( V_76 > 0 ) {
do {
V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_70 -> V_14 ) {
T_2 V_153 = V_70 -> V_15 - V_70 -> V_72 ;
if ( V_76 > V_153 ) {
V_76 -= V_153 ;
V_70 -> V_72 = 0 ;
} else {
V_70 -> V_72 += V_76 ;
V_76 = 0 ;
V_7 -> V_71 = V_9 ;
break;
}
}
V_9 = F_5 ( F_6 ( V_9 ) , V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
-- V_76 ;
V_7 -> V_71 = V_9 ;
} while ( V_76 != 0 );
} else if ( V_76 < 0 ) {
while ( 1 ) {
V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_70 -> V_14 ) {
if ( V_42 ) {
if ( - V_76 > V_70 -> V_72 ) {
V_76 += V_70 -> V_72 ;
V_70 -> V_72 = 0 ;
} else {
V_70 -> V_72 += V_76 ;
V_76 = 0 ;
V_7 -> V_71 = V_9 ;
break;
}
} else {
if ( - V_76 > V_70 -> V_15 ) {
V_76 += V_70 -> V_15 ;
V_70 -> V_72 = 0 ;
} else {
V_70 -> V_72 = V_70 -> V_15 + V_76 ;
V_76 = 0 ;
V_7 -> V_71 = V_9 ;
break;
}
}
}
V_9 = F_84 ( F_85 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
++ V_76 ;
V_7 -> V_71 = V_9 ;
if ( V_76 == 0 ) {
V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_70 -> V_14 )
V_70 -> V_72 = V_70 -> V_15 ;
break;
}
V_42 = false ;
}
} else {
V_7 -> V_71 = V_9 ;
V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_70 -> V_72 = 0 ;
}
}
static int F_88 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_89 )
{
T_3 V_91 = F_76 ( V_13 -> V_3 ) ;
struct V_77 V_64 = {
. V_89 = V_89 ,
} ;
if ( V_5 . V_138 )
V_91 = V_13 -> V_139 -> V_140 ;
F_64 ( V_7 , & V_13 -> V_50 , 1 , 0 , V_91 ,
F_61 , & V_64 ,
F_63 ) ;
return V_64 . V_88 ;
}
static int F_89 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_89 )
{
char V_134 [ 8192 ] ;
int V_88 = 0 ;
char V_41 = ' ' ;
struct V_110 V_111 = {
. V_118 = V_134 ,
. V_119 = sizeof( V_134 ) ,
} ;
struct V_135 * V_112 ;
bool V_42 = true ;
int V_115 ;
if ( V_5 . V_136 )
V_41 = F_20 ( V_13 ) ;
if ( V_5 . V_136 )
V_88 += fprintf ( V_89 , L_13 , V_41 ) ;
F_74 (fmt) {
if ( F_75 ( V_112 ) )
continue;
if ( ! V_42 ) {
V_115 = F_70 ( V_111 . V_118 , V_111 . V_119 , L_14 ) ;
F_71 ( & V_111 , V_115 ) ;
} else
V_42 = false ;
V_115 = V_112 -> V_133 ( V_112 , & V_111 , V_13 ) ;
F_71 ( & V_111 , V_115 ) ;
}
V_88 += fprintf ( V_89 , L_16 , F_90 ( V_134 ) ) ;
if ( V_41 == '-' )
V_88 += F_88 ( V_7 , V_13 , V_89 ) ;
return V_88 ;
}
static int F_91 ( struct V_1 * V_7 , T_9 * V_89 )
{
struct V_8 * V_9 = F_5 ( F_4 ( V_7 -> V_20 . V_11 ) ,
V_7 -> V_4 ) ;
int V_88 = 0 ;
while ( V_9 ) {
struct V_12 * V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_88 += F_89 ( V_7 , V_70 , V_89 ) ;
V_9 = F_5 ( F_6 ( V_9 ) , V_7 -> V_4 ) ;
}
return V_88 ;
}
static int F_92 ( struct V_1 * V_7 )
{
char V_154 [ 64 ] ;
T_9 * V_89 ;
while ( 1 ) {
F_70 ( V_154 , sizeof( V_154 ) , L_17 , V_7 -> V_155 ) ;
if ( F_93 ( V_154 , V_156 ) )
break;
if ( ++ V_7 -> V_155 == 8192 ) {
F_52 ( L_18 ) ;
return - 1 ;
}
}
V_89 = fopen ( V_154 , L_19 ) ;
if ( V_89 == NULL ) {
char V_100 [ 64 ] ;
const char * V_157 = F_94 ( V_158 , V_100 , sizeof( V_100 ) ) ;
F_52 ( L_20 , V_154 , V_157 ) ;
return - 1 ;
}
++ V_7 -> V_155 ;
F_91 ( V_7 , V_89 ) ;
fclose ( V_89 ) ;
F_52 ( L_21 , V_154 ) ;
return 0 ;
}
static struct V_1 * F_95 ( struct V_3 * V_3 ,
struct V_58 * V_59 ,
struct V_159 * V_160 )
{
struct V_1 * V_7 = F_96 ( sizeof( * V_7 ) ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_20 . V_61 = F_82 ;
V_7 -> V_20 . V_161 = F_10 ;
V_7 -> V_20 . V_162 = F_86 ;
V_7 -> V_20 . V_163 = true ;
V_7 -> V_22 = V_5 . V_164 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_160 = V_160 ;
}
return V_7 ;
}
static void F_97 ( struct V_1 * V_7 )
{
free ( V_7 ) ;
}
static struct V_12 * F_98 ( struct V_1 * V_7 )
{
return V_7 -> V_51 ;
}
static struct V_165 * F_99 ( struct V_1 * V_7 )
{
return V_7 -> V_51 -> V_165 ;
}
static inline bool F_100 ( void * V_63 )
{
return V_63 == NULL ;
}
static int F_46 ( struct V_3 * V_3 ,
struct V_58 * V_59 ,
char * V_100 , T_8 V_119 )
{
char V_166 ;
int V_88 ;
const struct V_167 * V_167 = V_3 -> V_168 ;
const struct V_165 * V_165 = V_3 -> V_169 ;
unsigned long V_170 = V_3 -> V_65 . V_67 [ V_171 ] ;
T_3 V_67 = V_3 -> V_65 . V_172 ;
struct V_173 * V_174 = F_79 ( V_3 ) ;
const char * V_175 = F_101 ( V_174 ) ;
char V_118 [ 512 ] ;
T_8 V_176 = sizeof( V_118 ) ;
char V_177 [ 30 ] = L_22 ;
bool V_178 = false ;
if ( V_5 . V_179 ) {
V_170 = V_3 -> V_65 . V_180 ;
V_67 = V_3 -> V_65 . V_181 ;
}
if ( F_102 ( V_174 ) ) {
struct V_173 * V_182 ;
F_103 ( V_174 , V_118 , V_176 ) ;
V_175 = V_118 ;
F_104 (pos, evsel) {
struct V_3 * V_183 = F_105 ( V_182 ) ;
if ( V_5 . V_179 ) {
V_170 += V_183 -> V_65 . V_180 ;
V_67 += V_183 -> V_65 . V_181 ;
} else {
V_170 += V_183 -> V_65 . V_67 [ V_171 ] ;
V_67 += V_183 -> V_65 . V_172 ;
}
}
}
if ( V_5 . V_184 &&
strstr ( V_175 , L_23 ) )
V_178 = true ;
V_170 = F_106 ( V_170 , & V_166 ) ;
V_88 = F_70 ( V_100 , V_119 ,
L_24 V_185 ,
V_170 , V_166 , V_175 , V_178 ? V_177 : L_7 , V_67 ) ;
if ( V_3 -> V_186 )
V_88 += snprintf ( V_100 + V_88 , V_119 - V_88 ,
L_25 , V_3 -> V_186 ) ;
if ( V_165 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 ,
L_26 ,
( V_165 -> V_187 ? F_107 ( V_165 ) : L_15 ) ,
V_165 -> V_188 ) ;
if ( V_167 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 ,
L_27 , V_167 -> V_189 ) ;
if ( ! F_100 ( V_59 ) ) {
struct V_190 * V_71 = V_59 -> V_64 ;
if ( V_71 -> V_191 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 , L_28 ) ;
}
return V_88 ;
}
static inline void F_108 ( char * * V_192 , int V_37 )
{
int V_193 ;
for ( V_193 = 0 ; V_193 < V_37 ; ++ V_193 )
F_109 ( & V_192 [ V_193 ] ) ;
}
static int F_110 ( void )
{
char * V_194 , * V_192 [ 32 ] , * V_195 [ 32 ] , * V_196 ;
T_10 * V_197 ;
int V_198 = 0 , V_199 = - 1 , V_115 = - 1 ;
struct V_200 * V_201 ;
V_194 = getenv ( L_29 ) ;
if ( ! V_194 )
return V_115 ;
V_197 = F_111 ( V_194 ) ;
if ( ! V_197 )
return V_115 ;
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
memset ( V_192 , 0 , sizeof( V_195 ) ) ;
while ( ( V_201 = F_112 ( V_197 ) ) ) {
char V_202 [ V_203 ] ;
T_3 V_204 ;
char * V_205 = V_201 -> V_206 ;
T_9 * V_207 ;
if ( ! ( V_201 -> V_208 == V_209 ) )
continue;
snprintf ( V_202 , sizeof( V_202 ) , L_30 , V_194 , V_205 ) ;
V_207 = fopen ( V_202 , L_31 ) ;
if ( ! V_207 )
continue;
if ( fread ( & V_204 , 1 , 8 , V_207 ) < 8 )
goto V_210;
if ( F_113 ( V_204 ) ) {
V_192 [ V_198 ] = F_114 ( V_205 ) ;
if ( ! V_192 [ V_198 ] )
goto V_210;
V_195 [ V_198 ] = F_114 ( V_202 ) ;
if ( ! V_195 [ V_198 ] ) {
F_109 ( & V_192 [ V_198 ] ) ;
F_115 ( L_32 ) ;
fclose ( V_207 ) ;
break;
}
V_198 ++ ;
}
V_210:
fclose ( V_207 ) ;
if ( V_198 >= 32 ) {
F_115 ( L_33
L_34 ) ;
break;
}
}
F_116 ( V_197 ) ;
if ( V_198 ) {
V_199 = F_117 ( V_198 , V_192 ) ;
if ( V_199 < V_198 && V_199 >= 0 ) {
V_196 = F_114 ( V_195 [ V_199 ] ) ;
if ( V_196 ) {
if ( V_211 )
free ( ( void * ) V_212 ) ;
V_212 = V_196 ;
V_211 = true ;
V_115 = 0 ;
} else
F_115 ( L_35 ) ;
}
}
F_108 ( V_192 , V_198 ) ;
F_108 ( V_195 , V_198 ) ;
return V_115 ;
}
static int
F_118 ( struct V_1 * V_7 , struct V_213 * V_214 )
{
struct V_173 * V_174 ;
struct V_215 * V_216 ;
struct V_12 * V_13 ;
int V_157 ;
if ( ! V_217 && F_119 ( V_7 -> V_160 ) )
return 0 ;
V_216 = F_55 ( V_214 -> V_53 . V_81 ) ;
if ( ! V_216 -> V_82 )
return 0 ;
V_174 = F_79 ( V_7 -> V_3 ) ;
V_157 = F_120 ( & V_214 -> V_53 , V_174 , V_7 -> V_59 ) ;
V_13 = F_98 ( V_7 ) ;
if ( ( V_157 == 'q' || V_157 == F_121 ( 'c' ) ) && V_13 -> V_218 )
return 1 ;
F_49 ( & V_7 -> V_20 , V_7 -> V_3 -> V_16 ) ;
if ( V_157 )
F_122 ( & V_7 -> V_20 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 , char * * V_219 ,
struct V_220 * V_220 , struct V_221 * V_81 )
{
if ( V_81 == NULL || V_220 -> V_167 -> V_222 )
return 0 ;
if ( F_67 ( V_219 , L_36 , V_81 -> V_205 ) < 0 )
return 0 ;
V_214 -> V_53 . V_220 = V_220 ;
V_214 -> V_53 . V_81 = V_81 ;
V_214 -> V_223 = F_118 ;
return 1 ;
}
static int
F_124 ( struct V_1 * V_7 , struct V_213 * V_214 )
{
struct V_165 * V_165 = V_214 -> V_165 ;
if ( V_7 -> V_3 -> V_169 ) {
F_125 ( V_7 -> V_224 , & V_7 -> V_3 -> V_169 ) ;
F_126 ( V_225 , false ) ;
F_127 ( V_7 -> V_3 -> V_169 ) ;
F_51 () ;
} else {
F_52 ( L_37 ,
V_165 -> V_187 ? F_107 ( V_165 ) : L_15 ,
V_165 -> V_188 ) ;
V_7 -> V_3 -> V_169 = F_128 ( V_165 ) ;
F_126 ( V_225 , false ) ;
F_129 ( V_7 -> V_224 , & V_7 -> V_3 -> V_169 ) ;
}
F_130 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_131 ( struct V_1 * V_7 , struct V_213 * V_214 ,
char * * V_219 , struct V_165 * V_165 )
{
if ( V_165 == NULL )
return 0 ;
if ( F_67 ( V_219 , L_38 ,
V_7 -> V_3 -> V_169 ? L_39 : L_40 ,
V_165 -> V_187 ? F_107 ( V_165 ) : L_15 ,
V_165 -> V_188 ) < 0 )
return 0 ;
V_214 -> V_165 = V_165 ;
V_214 -> V_223 = F_124 ;
return 1 ;
}
static int
F_132 ( struct V_1 * V_7 , struct V_213 * V_214 )
{
struct V_167 * V_167 = V_214 -> V_167 ;
if ( V_7 -> V_3 -> V_168 ) {
F_125 ( V_7 -> V_224 , & V_7 -> V_3 -> V_168 ) ;
F_126 ( V_226 , false ) ;
V_7 -> V_3 -> V_168 = NULL ;
F_51 () ;
} else {
if ( V_167 == NULL )
return 0 ;
F_52 ( L_41 ,
V_167 -> V_227 ? L_42 : V_167 -> V_189 ) ;
V_7 -> V_3 -> V_168 = V_167 ;
F_126 ( V_226 , true ) ;
F_129 ( V_7 -> V_224 , & V_7 -> V_3 -> V_168 ) ;
}
F_133 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_134 ( struct V_1 * V_7 , struct V_213 * V_214 ,
char * * V_219 , struct V_167 * V_167 )
{
if ( V_167 == NULL )
return 0 ;
if ( F_67 ( V_219 , L_43 ,
V_7 -> V_3 -> V_168 ? L_39 : L_40 ,
V_167 -> V_227 ? L_42 : V_167 -> V_189 ) < 0 )
return 0 ;
V_214 -> V_167 = V_167 ;
V_214 -> V_223 = F_132 ;
return 1 ;
}
static int
F_135 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 )
{
F_136 ( V_214 -> V_53 . V_220 ) ;
return 0 ;
}
static int
F_137 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 , char * * V_219 , struct V_220 * V_220 )
{
if ( V_220 == NULL )
return 0 ;
if ( F_67 ( V_219 , L_44 ) < 0 )
return 0 ;
V_214 -> V_53 . V_220 = V_220 ;
V_214 -> V_223 = F_135 ;
return 1 ;
}
static int
F_138 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 )
{
char V_228 [ 64 ] ;
memset ( V_228 , 0 , sizeof( V_228 ) ) ;
if ( V_214 -> V_165 ) {
F_70 ( V_228 , sizeof( V_228 ) , L_45 ,
F_107 ( V_214 -> V_165 ) ) ;
} else if ( V_214 -> V_53 . V_81 ) {
F_70 ( V_228 , sizeof( V_228 ) , L_46 ,
V_214 -> V_53 . V_81 -> V_205 ) ;
}
F_139 ( V_228 ) ;
return 0 ;
}
static int
F_140 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 , char * * V_219 ,
struct V_165 * V_165 , struct V_221 * V_81 )
{
if ( V_165 ) {
if ( F_67 ( V_219 , L_47 ,
F_107 ( V_165 ) ) < 0 )
return 0 ;
} else if ( V_81 ) {
if ( F_67 ( V_219 , L_48 ,
V_81 -> V_205 ) < 0 )
return 0 ;
} else {
if ( F_67 ( V_219 , L_49 ) < 0 )
return 0 ;
}
V_214 -> V_165 = V_165 ;
V_214 -> V_53 . V_81 = V_81 ;
V_214 -> V_223 = F_138 ;
return 1 ;
}
static int
F_141 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 V_87 )
{
if ( F_110 () ) {
F_115 ( L_50
L_51 ) ;
return 0 ;
}
return V_229 ;
}
static int
F_142 ( struct V_1 * V_7 ,
struct V_213 * V_214 , char * * V_219 )
{
if ( ! F_100 ( V_7 -> V_59 ) )
return 0 ;
if ( F_67 ( V_219 , L_52 ) < 0 )
return 0 ;
V_214 -> V_223 = F_141 ;
return 1 ;
}
static int
F_143 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 V_87 )
{
return 0 ;
}
static int
F_144 ( struct V_1 * V_7 V_87 ,
struct V_213 * V_214 , char * * V_219 )
{
if ( F_67 ( V_219 , L_53 ) < 0 )
return 0 ;
V_214 -> V_223 = F_143 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 V_16 = 0 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_17 = V_2 -> V_3 -> V_17 ;
return;
}
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_16 ++ ;
V_9 = F_6 ( V_9 ) ;
}
V_2 -> V_17 = V_16 ;
}
static int F_145 ( struct V_173 * V_174 , int V_67 ,
const char * V_230 ,
bool V_231 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_159 * V_160 )
{
struct V_3 * V_3 = F_105 ( V_174 ) ;
struct V_1 * V_7 = F_95 ( V_3 , V_59 , V_160 ) ;
struct V_218 * V_232 ;
#define F_146 16
char * V_192 [ F_146 ] ;
struct V_213 V_233 [ F_146 ] ;
int V_198 = 0 ;
int V_56 = - 1 ;
char V_118 [ 64 ] ;
int V_60 = V_59 ? V_59 -> V_61 : 0 ;
struct V_135 * V_112 ;
#define F_147 \
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
const char V_234 [] = F_147
L_54
L_55
L_56
L_57
L_58
L_59
L_60 ;
const char V_235 [] = F_147
L_55
L_58
L_59
L_61
L_62
L_60 ;
if ( V_7 == NULL )
return - 1 ;
F_148 () ;
F_149 ( 0 , 0 , 0 ) ;
if ( V_4 ) {
V_7 -> V_4 = V_4 ;
F_17 ( V_7 ) ;
}
V_7 -> V_224 = F_150 ( 2 ) ;
if ( V_7 -> V_224 == NULL )
goto V_74;
F_151 ( V_230 ) ;
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
memset ( V_233 , 0 , sizeof( V_233 ) ) ;
F_74 (fmt)
F_152 ( V_112 , V_3 ) ;
if ( V_5 . V_236 )
F_153 ( V_5 . V_236 ) ;
while ( 1 ) {
struct V_165 * V_165 = NULL ;
struct V_167 * V_167 = NULL ;
int V_199 = 0 ;
V_198 = 0 ;
V_56 = F_45 ( V_7 , V_230 ) ;
if ( V_7 -> V_51 != NULL ) {
V_165 = F_99 ( V_7 ) ;
V_167 = V_7 -> V_54 -> V_220 ? V_7 -> V_54 -> V_220 -> V_167 : NULL ;
}
switch ( V_56 ) {
case V_237 :
case V_238 :
if ( V_67 == 1 )
continue;
goto V_239;
case 'a' :
if ( ! V_240 ) {
F_44 ( & V_7 -> V_20 , V_60 * 2 ,
L_63
L_64 ) ;
continue;
}
if ( V_7 -> V_54 == NULL ||
V_7 -> V_54 -> V_81 == NULL ||
V_7 -> V_54 -> V_220 -> V_167 -> V_222 )
continue;
V_233 -> V_53 . V_220 = V_7 -> V_54 -> V_220 ;
V_233 -> V_53 . V_81 = V_7 -> V_54 -> V_81 ;
F_118 ( V_7 , V_233 ) ;
continue;
case 'P' :
F_92 ( V_7 ) ;
continue;
case 'd' :
V_233 -> V_167 = V_167 ;
F_132 ( V_7 , V_233 ) ;
continue;
case 'V' :
V_7 -> V_80 = ! V_7 -> V_80 ;
continue;
case 't' :
V_233 -> V_165 = V_165 ;
F_124 ( V_7 , V_233 ) ;
continue;
case '/' :
if ( F_154 ( L_65 ,
L_66 ,
V_118 , L_67 ,
V_60 * 2 ) == V_73 ) {
V_3 -> V_241 = * V_118 ? V_118 : NULL ;
F_155 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_100 ( V_59 ) ) {
V_233 -> V_165 = NULL ;
V_233 -> V_53 . V_81 = NULL ;
F_138 ( V_7 , V_233 ) ;
}
continue;
case 's' :
if ( F_100 ( V_59 ) ) {
V_56 = F_141 ( V_7 , V_233 ) ;
if ( V_56 == V_229 )
goto V_239;
}
continue;
case 'i' :
if ( V_160 -> V_242 )
F_156 ( V_160 ) ;
continue;
case 'F' :
V_5 . V_179 ^= 1 ;
continue;
case 'z' :
if ( ! F_100 ( V_59 ) ) {
struct V_190 * V_71 = V_59 -> V_64 ;
V_71 -> V_191 = ! V_71 -> V_191 ;
}
continue;
case V_243 :
case 'h' :
case '?' :
F_157 ( & V_7 -> V_20 ,
F_100 ( V_59 ) ? V_234 : V_235 ) ;
continue;
case V_73 :
case V_244 :
break;
case V_245 :
case V_246 : {
const void * V_71 ;
if ( F_158 ( V_7 -> V_224 ) ) {
if ( V_231 )
goto V_239;
if ( V_56 == V_245 &&
F_159 ( & V_7 -> V_20 ,
L_68 ) )
goto V_239;
continue;
}
V_71 = F_160 ( V_7 -> V_224 ) ;
if ( V_71 == & V_7 -> V_3 -> V_168 ) {
F_132 ( V_7 , V_233 ) ;
}
if ( V_71 == & V_7 -> V_3 -> V_169 )
F_124 ( V_7 , V_233 ) ;
continue;
}
case 'q' :
case F_121 ( 'c' ) :
goto V_239;
case 'f' :
if ( ! F_100 ( V_59 ) ) {
struct V_190 * V_71 = V_59 -> V_64 ;
F_161 ( V_71 -> V_247 ) ;
if ( V_71 -> V_247 -> V_248 ) {
V_230 = L_69 ;
V_59 -> V_61 = V_60 ;
} else {
V_230 = L_70 ;
V_59 -> V_61 = 0 ;
}
continue;
}
default:
V_230 = L_71 ;
continue;
}
if ( ! V_240 )
goto V_249;
if ( V_7 -> V_54 == NULL )
goto V_250;
if ( V_251 == V_252 ) {
V_232 = V_7 -> V_51 -> V_218 ;
if ( V_232 == NULL )
goto V_250;
V_198 += F_123 ( V_7 ,
& V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
V_232 -> V_253 . V_220 ,
V_232 -> V_253 . V_81 ) ;
if ( V_232 -> V_254 . V_81 != V_232 -> V_253 . V_81 )
V_198 += F_123 ( V_7 ,
& V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
V_232 -> V_254 . V_220 ,
V_232 -> V_254 . V_81 ) ;
} else {
V_198 += F_123 ( V_7 ,
& V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
V_7 -> V_54 -> V_220 ,
V_7 -> V_54 -> V_81 ) ;
}
V_250:
V_198 += F_131 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] , V_165 ) ;
V_198 += F_134 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] , V_167 ) ;
V_198 += F_137 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
V_7 -> V_54 ?
V_7 -> V_54 -> V_220 : NULL ) ;
if ( V_7 -> V_51 ) {
V_198 += F_140 ( V_7 ,
& V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
V_165 , NULL ) ;
V_198 += F_140 ( V_7 ,
& V_233 [ V_198 ] ,
& V_192 [ V_198 ] ,
NULL , V_7 -> V_54 -> V_81 ) ;
}
V_198 += F_140 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] , NULL , NULL ) ;
V_198 += F_142 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] ) ;
V_249:
V_198 += F_144 ( V_7 , & V_233 [ V_198 ] ,
& V_192 [ V_198 ] ) ;
do {
struct V_213 * V_214 ;
V_199 = F_117 ( V_198 , V_192 ) ;
if ( V_199 == - 1 || V_199 >= V_198 )
break;
V_214 = & V_233 [ V_199 ] ;
V_56 = V_214 -> V_223 ( V_7 , V_214 ) ;
} while ( V_56 == 1 );
if ( V_56 == V_229 )
break;
}
V_239:
F_162 ( V_7 -> V_224 ) ;
V_74:
F_97 ( V_7 ) ;
F_108 ( V_192 , F_146 ) ;
return V_56 ;
}
static void F_163 ( struct V_19 * V_7 ,
void * V_133 , int V_29 )
{
struct V_255 * V_256 = F_11 ( V_7 ,
struct V_255 , V_20 ) ;
struct V_173 * V_174 = F_32 ( V_133 , struct V_173 , V_36 ) ;
struct V_3 * V_3 = F_105 ( V_174 ) ;
bool V_117 = F_56 ( V_7 , V_29 ) ;
unsigned long V_67 = V_3 -> V_65 . V_67 [ V_171 ] ;
const char * V_175 = F_101 ( V_174 ) ;
char V_100 [ 256 ] , V_166 ;
const char * V_257 = L_7 ;
T_8 V_88 ;
F_57 ( V_7 , V_117 ? V_84 :
V_83 ) ;
if ( F_102 ( V_174 ) ) {
struct V_173 * V_182 ;
V_175 = F_164 ( V_174 ) ;
F_104 (pos, evsel) {
struct V_3 * V_183 = F_105 ( V_182 ) ;
V_67 += V_183 -> V_65 . V_67 [ V_171 ] ;
}
}
V_67 = F_106 ( V_67 , & V_166 ) ;
V_88 = F_70 ( V_100 , sizeof( V_100 ) , L_72 , V_67 ,
V_166 , V_166 == ' ' ? L_15 : L_7 , V_175 ) ;
F_59 ( V_7 , L_12 , V_100 ) ;
V_67 = V_3 -> V_65 . V_67 [ V_68 ] ;
if ( V_67 != 0 ) {
V_256 -> V_258 = true ;
if ( ! V_117 )
F_57 ( V_7 , V_259 ) ;
V_67 = F_106 ( V_67 , & V_166 ) ;
V_88 += F_70 ( V_100 , sizeof( V_100 ) , L_73 ,
V_67 , V_166 , V_166 == ' ' ? L_15 : L_7 ) ;
V_257 = V_100 ;
}
F_58 ( V_7 , V_257 , V_7 -> V_28 - V_88 ) ;
if ( V_117 )
V_256 -> V_54 = V_174 ;
}
static int F_165 ( struct V_255 * V_256 ,
int V_67 , const char * V_55 ,
struct V_58 * V_59 )
{
struct V_260 * V_247 = V_256 -> V_20 . V_261 ;
struct V_173 * V_182 ;
const char * V_57 = L_74 ;
int V_60 = V_59 ? V_59 -> V_61 : 0 ;
int V_56 ;
if ( F_47 ( & V_256 -> V_20 , V_57 ,
L_75 ) < 0 )
return - 1 ;
while ( 1 ) {
V_56 = F_48 ( & V_256 -> V_20 , V_60 ) ;
switch ( V_56 ) {
case V_62 :
V_59 -> V_63 ( V_59 -> V_64 ) ;
if ( ! V_256 -> V_262 && V_256 -> V_258 ) {
F_43 ( & V_256 -> V_20 ) ;
V_256 -> V_262 = true ;
}
continue;
case V_244 :
case V_73 :
if ( ! V_256 -> V_54 )
continue;
V_182 = V_256 -> V_54 ;
V_263:
F_166 ( V_247 , V_182 ) ;
if ( V_59 )
V_59 -> V_63 ( V_59 -> V_64 ) ;
V_56 = F_145 ( V_182 , V_67 , V_55 ,
true , V_59 ,
V_256 -> V_4 ,
V_256 -> V_160 ) ;
F_50 ( & V_256 -> V_20 , V_57 ) ;
switch ( V_56 ) {
case V_237 :
if ( V_182 -> V_36 . V_44 == & V_247 -> V_11 )
V_182 = F_167 ( V_247 ) ;
else
V_182 = F_168 ( V_182 ) ;
goto V_263;
case V_238 :
if ( V_182 -> V_36 . V_47 == & V_247 -> V_11 )
V_182 = F_169 ( V_247 ) ;
else
V_182 = F_170 ( V_182 ) ;
goto V_263;
case V_229 :
case 'q' :
case F_121 ( 'c' ) :
goto V_74;
case V_245 :
default:
continue;
}
case V_246 :
continue;
case V_245 :
if ( ! F_159 ( & V_256 -> V_20 ,
L_68 ) )
continue;
case 'q' :
case F_121 ( 'c' ) :
goto V_74;
default:
continue;
}
}
V_74:
F_53 ( & V_256 -> V_20 ) ;
return V_56 ;
}
static bool F_171 ( struct V_19 * V_7 V_87 ,
void * V_133 )
{
struct V_173 * V_174 = F_32 ( V_133 , struct V_173 , V_36 ) ;
if ( V_5 . V_264 && ! F_172 ( V_174 ) )
return true ;
return false ;
}
static int F_173 ( struct V_260 * V_247 ,
int V_16 , const char * V_55 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_159 * V_160 )
{
struct V_173 * V_182 ;
struct V_255 V_256 = {
. V_20 = {
. V_11 = & V_247 -> V_11 ,
. V_61 = V_265 ,
. V_162 = V_266 ,
. V_267 = F_163 ,
. V_268 = F_171 ,
. V_16 = V_16 ,
. V_261 = V_247 ,
} ,
. V_4 = V_4 ,
. V_160 = V_160 ,
} ;
F_151 ( L_76 ) ;
F_174 (evlist, pos) {
const char * V_175 = F_101 ( V_182 ) ;
T_8 V_269 = strlen ( V_175 ) + 7 ;
if ( V_256 . V_20 . V_28 < V_269 )
V_256 . V_20 . V_28 = V_269 ;
}
return F_165 ( & V_256 , V_16 , V_55 , V_59 ) ;
}
int F_175 ( struct V_260 * V_247 , const char * V_55 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_159 * V_160 )
{
int V_16 = V_247 -> V_16 ;
V_270:
if ( V_16 == 1 ) {
struct V_173 * V_42 = F_167 ( V_247 ) ;
return F_145 ( V_42 , V_16 , V_55 ,
false , V_59 , V_4 ,
V_160 ) ;
}
if ( V_5 . V_264 ) {
struct V_173 * V_182 ;
V_16 = 0 ;
F_174 (evlist, pos) {
if ( F_172 ( V_182 ) )
V_16 ++ ;
}
if ( V_16 == 1 )
goto V_270;
}
return F_173 ( V_247 , V_16 , V_55 ,
V_59 , V_4 , V_160 ) ;
}
