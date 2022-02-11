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
if ( ! V_13 || ! V_53 )
return false ;
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
int V_30 = 0 ;
F_14 ( V_7 , V_29 , 0 ) ;
F_74 (fmt) {
if ( F_75 ( V_112 ) || V_30 ++ < V_7 -> V_20 . V_137 )
continue;
if ( V_117 && V_7 -> V_20 . V_138 ) {
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
if ( ! V_7 -> V_20 . V_138 )
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
if ( V_5 . V_139 )
V_91 = V_133 -> V_140 -> V_141 ;
else
V_91 = V_133 -> V_142 . V_141 ;
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
static int F_77 ( struct V_110 * V_111 , int V_143 )
{
F_71 ( V_111 , V_143 ) ;
return V_111 -> V_119 <= 0 ;
}
static int F_78 ( struct V_1 * V_7 , char * V_118 , T_8 V_119 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_110 V_144 = {
. V_118 = V_118 ,
. V_119 = V_119 ,
} ;
struct V_135 * V_112 ;
T_8 V_115 = 0 ;
int V_30 = 0 ;
if ( V_5 . V_136 ) {
V_115 = F_70 ( V_118 , V_119 , L_14 ) ;
if ( F_77 ( & V_144 , V_115 ) )
return V_115 ;
}
F_74 (fmt) {
if ( F_75 ( V_112 ) || V_30 ++ < V_7 -> V_20 . V_137 )
continue;
V_115 = V_112 -> V_145 ( V_112 , & V_144 , F_79 ( V_3 ) ) ;
if ( F_77 ( & V_144 , V_115 ) )
break;
V_115 = F_70 ( V_144 . V_118 , V_144 . V_119 , L_14 ) ;
if ( F_77 ( & V_144 , V_115 ) )
break;
}
return V_115 ;
}
static void F_80 ( struct V_1 * V_7 )
{
char V_146 [ 1024 ] ;
F_78 ( V_7 , V_146 , sizeof( V_146 ) ) ;
F_15 ( & V_7 -> V_20 , 0 , 0 ) ;
F_57 ( & V_7 -> V_20 , V_147 ) ;
F_58 ( & V_7 -> V_20 , V_146 , V_7 -> V_20 . V_28 + 1 ) ;
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
V_2 -> V_51 = NULL ;
V_2 -> V_54 = NULL ;
for ( V_9 = V_7 -> V_71 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_104 ;
if ( V_70 -> V_148 )
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
if ( ! V_70 -> V_148 && V_104 >= V_4 )
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
if ( ! V_70 -> V_148 && V_104 >= V_4 )
return V_9 ;
V_9 = F_85 ( V_9 ) ;
}
return NULL ;
}
static void F_86 ( struct V_19 * V_7 ,
T_7 V_76 , int V_149 )
{
struct V_12 * V_70 ;
struct V_8 * V_9 ;
bool V_42 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
if ( V_7 -> V_16 == 0 )
return;
F_81 ( V_7 ) ;
switch ( V_149 ) {
case V_150 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_151 :
V_9 = V_7 -> V_71 ;
goto V_152;
case V_153 :
V_9 = F_84 ( F_87 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
V_42 = false ;
break;
default:
return;
}
V_70 = F_7 ( V_7 -> V_71 , struct V_12 , V_8 ) ;
V_70 -> V_72 = 0 ;
V_152:
if ( ! V_9 )
return;
if ( V_76 > 0 ) {
do {
V_70 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_70 -> V_14 ) {
T_2 V_154 = V_70 -> V_15 - V_70 -> V_72 ;
if ( V_76 > V_154 ) {
V_76 -= V_154 ;
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
if ( V_5 . V_139 )
V_91 = V_13 -> V_140 -> V_141 ;
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
char V_155 [ 64 ] ;
T_9 * V_89 ;
while ( 1 ) {
F_70 ( V_155 , sizeof( V_155 ) , L_17 , V_7 -> V_156 ) ;
if ( F_93 ( V_155 , V_157 ) )
break;
if ( ++ V_7 -> V_156 == 8192 ) {
F_52 ( L_18 ) ;
return - 1 ;
}
}
V_89 = fopen ( V_155 , L_19 ) ;
if ( V_89 == NULL ) {
char V_100 [ 64 ] ;
const char * V_158 = F_94 ( V_159 , V_100 , sizeof( V_100 ) ) ;
F_52 ( L_20 , V_155 , V_158 ) ;
return - 1 ;
}
++ V_7 -> V_156 ;
F_91 ( V_7 , V_89 ) ;
fclose ( V_89 ) ;
F_52 ( L_21 , V_155 ) ;
return 0 ;
}
static struct V_1 * F_95 ( struct V_3 * V_3 ,
struct V_58 * V_59 ,
struct V_160 * V_161 )
{
struct V_1 * V_7 = F_96 ( sizeof( * V_7 ) ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_20 . V_61 = F_82 ;
V_7 -> V_20 . V_162 = F_10 ;
V_7 -> V_20 . V_163 = F_86 ;
V_7 -> V_20 . V_164 = true ;
V_7 -> V_22 = V_5 . V_165 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_161 = V_161 ;
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
static struct V_166 * F_99 ( struct V_1 * V_7 )
{
return V_7 -> V_51 -> V_166 ;
}
static inline bool F_100 ( void * V_63 )
{
return V_63 == NULL ;
}
static int F_46 ( struct V_3 * V_3 ,
struct V_58 * V_59 ,
char * V_100 , T_8 V_119 )
{
char V_167 ;
int V_88 ;
const struct V_168 * V_168 = V_3 -> V_169 ;
const struct V_166 * V_166 = V_3 -> V_170 ;
int V_171 = V_3 -> V_172 ;
unsigned long V_173 = V_3 -> V_65 . V_67 [ V_174 ] ;
T_3 V_67 = V_3 -> V_65 . V_175 ;
struct V_176 * V_177 = F_79 ( V_3 ) ;
const char * V_178 = F_101 ( V_177 ) ;
char V_118 [ 512 ] ;
T_8 V_179 = sizeof( V_118 ) ;
char V_180 [ 30 ] = L_22 ;
bool V_181 = false ;
if ( V_5 . V_182 ) {
V_173 = V_3 -> V_65 . V_183 ;
V_67 = V_3 -> V_65 . V_184 ;
}
if ( F_102 ( V_177 ) ) {
struct V_176 * V_185 ;
F_103 ( V_177 , V_118 , V_179 ) ;
V_178 = V_118 ;
F_104 (pos, evsel) {
struct V_3 * V_186 = F_105 ( V_185 ) ;
if ( V_5 . V_182 ) {
V_173 += V_186 -> V_65 . V_183 ;
V_67 += V_186 -> V_65 . V_184 ;
} else {
V_173 += V_186 -> V_65 . V_67 [ V_174 ] ;
V_67 += V_186 -> V_65 . V_175 ;
}
}
}
if ( V_5 . V_187 &&
strstr ( V_178 , L_23 ) )
V_181 = true ;
V_173 = F_106 ( V_173 , & V_167 ) ;
V_88 = F_70 ( V_100 , V_119 ,
L_24 V_188 ,
V_173 , V_167 , V_178 , V_181 ? V_180 : L_7 , V_67 ) ;
if ( V_3 -> V_189 )
V_88 += snprintf ( V_100 + V_88 , V_119 - V_88 ,
L_25 , V_3 -> V_189 ) ;
if ( V_166 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 ,
L_26 ,
( V_166 -> V_190 ? F_107 ( V_166 ) : L_15 ) ,
V_166 -> V_191 ) ;
if ( V_168 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 ,
L_27 , V_168 -> V_192 ) ;
if ( V_171 > - 1 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 ,
L_28 , V_171 ) ;
if ( ! F_100 ( V_59 ) ) {
struct V_193 * V_71 = V_59 -> V_64 ;
if ( V_71 -> V_194 )
V_88 += F_70 ( V_100 + V_88 , V_119 - V_88 , L_29 ) ;
}
return V_88 ;
}
static inline void F_108 ( char * * V_195 , int V_37 )
{
int V_196 ;
for ( V_196 = 0 ; V_196 < V_37 ; ++ V_196 )
F_109 ( & V_195 [ V_196 ] ) ;
}
static int F_110 ( void )
{
char * V_197 , * V_195 [ 32 ] , * V_198 [ 32 ] , * V_199 ;
T_10 * V_200 ;
int V_201 = 0 , V_202 = - 1 , V_115 = - 1 ;
struct V_203 * V_204 ;
V_197 = getenv ( L_30 ) ;
if ( ! V_197 )
return V_115 ;
V_200 = F_111 ( V_197 ) ;
if ( ! V_200 )
return V_115 ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
memset ( V_195 , 0 , sizeof( V_198 ) ) ;
while ( ( V_204 = F_112 ( V_200 ) ) ) {
char V_205 [ V_206 ] ;
T_3 V_207 ;
char * V_208 = V_204 -> V_209 ;
T_9 * V_210 ;
if ( ! ( V_204 -> V_211 == V_212 ) )
continue;
snprintf ( V_205 , sizeof( V_205 ) , L_31 , V_197 , V_208 ) ;
V_210 = fopen ( V_205 , L_32 ) ;
if ( ! V_210 )
continue;
if ( fread ( & V_207 , 1 , 8 , V_210 ) < 8 )
goto V_213;
if ( F_113 ( V_207 ) ) {
V_195 [ V_201 ] = F_114 ( V_208 ) ;
if ( ! V_195 [ V_201 ] )
goto V_213;
V_198 [ V_201 ] = F_114 ( V_205 ) ;
if ( ! V_198 [ V_201 ] ) {
F_109 ( & V_195 [ V_201 ] ) ;
F_115 ( L_33 ) ;
fclose ( V_210 ) ;
break;
}
V_201 ++ ;
}
V_213:
fclose ( V_210 ) ;
if ( V_201 >= 32 ) {
F_115 ( L_34
L_35 ) ;
break;
}
}
F_116 ( V_200 ) ;
if ( V_201 ) {
V_202 = F_117 ( V_201 , V_195 ) ;
if ( V_202 < V_201 && V_202 >= 0 ) {
V_199 = F_114 ( V_198 [ V_202 ] ) ;
if ( V_199 ) {
if ( V_214 )
free ( ( void * ) V_215 ) ;
V_215 = V_199 ;
V_214 = true ;
V_115 = 0 ;
} else
F_115 ( L_36 ) ;
}
}
F_108 ( V_195 , V_201 ) ;
F_108 ( V_198 , V_201 ) ;
return V_115 ;
}
static int
F_118 ( struct V_1 * V_7 , struct V_216 * V_217 )
{
struct V_176 * V_177 ;
struct V_218 * V_219 ;
struct V_12 * V_13 ;
int V_158 ;
if ( ! V_220 && F_119 ( V_7 -> V_161 ) )
return 0 ;
V_219 = F_55 ( V_217 -> V_53 . V_81 ) ;
if ( ! V_219 -> V_82 )
return 0 ;
V_177 = F_79 ( V_7 -> V_3 ) ;
V_158 = F_120 ( & V_217 -> V_53 , V_177 , V_7 -> V_59 ) ;
V_13 = F_98 ( V_7 ) ;
if ( ( V_158 == 'q' || V_158 == F_121 ( 'c' ) ) && V_13 -> V_221 )
return 1 ;
F_49 ( & V_7 -> V_20 , V_7 -> V_3 -> V_16 ) ;
if ( V_158 )
F_122 ( & V_7 -> V_20 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 , char * * V_222 ,
struct V_223 * V_223 , struct V_224 * V_81 )
{
if ( V_81 == NULL || V_223 -> V_168 -> V_225 )
return 0 ;
if ( F_67 ( V_222 , L_37 , V_81 -> V_208 ) < 0 )
return 0 ;
V_217 -> V_53 . V_223 = V_223 ;
V_217 -> V_53 . V_81 = V_81 ;
V_217 -> V_226 = F_118 ;
return 1 ;
}
static int
F_124 ( struct V_1 * V_7 , struct V_216 * V_217 )
{
struct V_166 * V_166 = V_217 -> V_166 ;
if ( V_7 -> V_3 -> V_170 ) {
F_125 ( V_7 -> V_227 , & V_7 -> V_3 -> V_170 ) ;
F_126 ( V_228 , false ) ;
F_127 ( V_7 -> V_3 -> V_170 ) ;
F_51 () ;
} else {
F_52 ( L_38 ,
V_166 -> V_190 ? F_107 ( V_166 ) : L_15 ,
V_166 -> V_191 ) ;
V_7 -> V_3 -> V_170 = F_128 ( V_166 ) ;
F_126 ( V_228 , false ) ;
F_129 ( V_7 -> V_227 , & V_7 -> V_3 -> V_170 ) ;
}
F_130 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_131 ( struct V_1 * V_7 , struct V_216 * V_217 ,
char * * V_222 , struct V_166 * V_166 )
{
if ( V_166 == NULL )
return 0 ;
if ( F_67 ( V_222 , L_39 ,
V_7 -> V_3 -> V_170 ? L_40 : L_41 ,
V_166 -> V_190 ? F_107 ( V_166 ) : L_15 ,
V_166 -> V_191 ) < 0 )
return 0 ;
V_217 -> V_166 = V_166 ;
V_217 -> V_226 = F_124 ;
return 1 ;
}
static int
F_132 ( struct V_1 * V_7 , struct V_216 * V_217 )
{
struct V_223 * V_223 = V_217 -> V_53 . V_223 ;
if ( V_7 -> V_3 -> V_169 ) {
F_125 ( V_7 -> V_227 , & V_7 -> V_3 -> V_169 ) ;
F_126 ( V_229 , false ) ;
V_7 -> V_3 -> V_169 = NULL ;
F_51 () ;
} else {
if ( V_223 == NULL )
return 0 ;
F_52 ( L_42 ,
F_133 ( V_223 ) ? L_43 : V_223 -> V_168 -> V_192 ) ;
V_7 -> V_3 -> V_169 = V_223 -> V_168 ;
F_126 ( V_229 , true ) ;
F_129 ( V_7 -> V_227 , & V_7 -> V_3 -> V_169 ) ;
}
F_134 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_135 ( struct V_1 * V_7 , struct V_216 * V_217 ,
char * * V_222 , struct V_223 * V_223 )
{
if ( V_223 == NULL )
return 0 ;
if ( F_67 ( V_222 , L_44 ,
V_7 -> V_3 -> V_169 ? L_40 : L_41 ,
F_133 ( V_223 ) ? L_43 : V_223 -> V_168 -> V_192 ) < 0 )
return 0 ;
V_217 -> V_53 . V_223 = V_223 ;
V_217 -> V_226 = F_132 ;
return 1 ;
}
static int
F_136 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 )
{
F_137 ( V_217 -> V_53 . V_223 ) ;
return 0 ;
}
static int
F_138 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 , char * * V_222 , struct V_223 * V_223 )
{
if ( V_223 == NULL )
return 0 ;
if ( F_67 ( V_222 , L_45 ) < 0 )
return 0 ;
V_217 -> V_53 . V_223 = V_223 ;
V_217 -> V_226 = F_136 ;
return 1 ;
}
static int
F_139 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 )
{
char V_230 [ 64 ] ;
memset ( V_230 , 0 , sizeof( V_230 ) ) ;
if ( V_217 -> V_166 ) {
F_70 ( V_230 , sizeof( V_230 ) , L_46 ,
F_107 ( V_217 -> V_166 ) ) ;
} else if ( V_217 -> V_53 . V_81 ) {
F_70 ( V_230 , sizeof( V_230 ) , L_47 ,
V_217 -> V_53 . V_81 -> V_208 ) ;
}
F_140 ( V_230 ) ;
return 0 ;
}
static int
F_141 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 , char * * V_222 ,
struct V_166 * V_166 , struct V_224 * V_81 )
{
if ( V_166 ) {
if ( F_67 ( V_222 , L_48 ,
F_107 ( V_166 ) ) < 0 )
return 0 ;
} else if ( V_81 ) {
if ( F_67 ( V_222 , L_49 ,
V_81 -> V_208 ) < 0 )
return 0 ;
} else {
if ( F_67 ( V_222 , L_50 ) < 0 )
return 0 ;
}
V_217 -> V_166 = V_166 ;
V_217 -> V_53 . V_81 = V_81 ;
V_217 -> V_226 = F_139 ;
return 1 ;
}
static int
F_142 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 V_87 )
{
if ( F_110 () ) {
F_115 ( L_51
L_52 ) ;
return 0 ;
}
return V_231 ;
}
static int
F_143 ( struct V_1 * V_7 ,
struct V_216 * V_217 , char * * V_222 )
{
if ( ! F_100 ( V_7 -> V_59 ) )
return 0 ;
if ( F_67 ( V_222 , L_53 ) < 0 )
return 0 ;
V_217 -> V_226 = F_142 ;
return 1 ;
}
static int
F_144 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 V_87 )
{
return 0 ;
}
static int
F_145 ( struct V_1 * V_7 V_87 ,
struct V_216 * V_217 , char * * V_222 )
{
if ( F_67 ( V_222 , L_54 ) < 0 )
return 0 ;
V_217 -> V_226 = F_144 ;
return 1 ;
}
static int
F_146 ( struct V_1 * V_7 , struct V_216 * V_217 )
{
if ( V_7 -> V_3 -> V_172 > - 1 ) {
F_125 ( V_7 -> V_227 , & V_7 -> V_3 -> V_172 ) ;
V_7 -> V_3 -> V_172 = - 1 ;
F_126 ( V_232 , false ) ;
} else {
V_7 -> V_3 -> V_172 = V_217 -> V_233 ;
F_126 ( V_232 , true ) ;
F_129 ( V_7 -> V_227 , & V_7 -> V_3 -> V_172 ) ;
}
F_147 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_148 ( struct V_1 * V_7 , struct V_216 * V_217 ,
char * * V_222 , int V_171 )
{
if ( V_171 < 0 )
return 0 ;
if ( F_67 ( V_222 , L_55 ,
( V_7 -> V_3 -> V_172 > - 1 ) ? L_40 : L_41 ,
V_171 ) < 0 )
return 0 ;
V_217 -> V_233 = V_171 ;
V_217 -> V_226 = F_146 ;
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
static int F_149 ( struct V_176 * V_177 , int V_67 ,
const char * V_234 ,
bool V_235 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_160 * V_161 )
{
struct V_3 * V_3 = F_105 ( V_177 ) ;
struct V_1 * V_7 = F_95 ( V_3 , V_59 , V_161 ) ;
struct V_221 * V_236 ;
#define F_150 16
char * V_195 [ F_150 ] ;
struct V_216 V_237 [ F_150 ] ;
int V_201 = 0 ;
int V_56 = - 1 ;
char V_118 [ 64 ] ;
int V_60 = V_59 ? V_59 -> V_61 : 0 ;
struct V_135 * V_112 ;
#define F_151 \
"h/?/F1 Show this window\n" \
"UP/DOWN/PGUP\n" \
"PGDN/SPACE Navigate\n" \
"q/ESC/CTRL+C Exit browser\n\n" \
"For multiple event sessions:\n\n" \
"TAB/UNTAB Switch events\n\n" \
"For symbolic views (--sort has sym):\n\n" \
"ENTER Zoom into DSO/Threads & Annotate current symbol\n" \
"ESC Zoom out\n" \
"a Annotate current symbol\n" \
"C Collapse all callchains\n" \
"d Zoom into current DSO\n" \
"E Expand all callchains\n" \
"F Toggle percentage of filtered entries\n" \
"H Display column headers\n" \
"m Display context menu\n" \
"S Zoom into current Processor Socket\n" \
const char V_238 [] = F_151
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ;
const char V_239 [] = F_151
L_57
L_60
L_61
L_63
L_64
L_62 ;
if ( V_7 == NULL )
return - 1 ;
F_152 () ;
F_153 ( 0 , 0 , 0 ) ;
if ( V_4 ) {
V_7 -> V_4 = V_4 ;
F_17 ( V_7 ) ;
}
V_7 -> V_227 = F_154 ( 3 ) ;
if ( V_7 -> V_227 == NULL )
goto V_74;
F_155 ( V_234 ) ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
F_74 (fmt) {
F_156 ( V_112 , V_3 ) ;
++ V_7 -> V_20 . V_240 ;
}
if ( V_5 . V_241 )
F_157 ( V_5 . V_241 ) ;
while ( 1 ) {
struct V_166 * V_166 = NULL ;
struct V_223 * V_223 = NULL ;
int V_202 = 0 ;
int V_242 = - 1 ;
V_201 = 0 ;
V_56 = F_45 ( V_7 , V_234 ) ;
if ( V_7 -> V_51 != NULL ) {
V_166 = F_99 ( V_7 ) ;
V_223 = V_7 -> V_54 -> V_223 ;
V_242 = V_7 -> V_51 -> V_233 ;
}
switch ( V_56 ) {
case V_243 :
case V_244 :
if ( V_67 == 1 )
continue;
goto V_245;
case 'a' :
if ( ! V_246 ) {
F_44 ( & V_7 -> V_20 , V_60 * 2 ,
L_65
L_66 ) ;
continue;
}
if ( V_7 -> V_54 == NULL ||
V_7 -> V_54 -> V_81 == NULL ||
V_7 -> V_54 -> V_223 -> V_168 -> V_225 )
continue;
V_237 -> V_53 . V_223 = V_7 -> V_54 -> V_223 ;
V_237 -> V_53 . V_81 = V_7 -> V_54 -> V_81 ;
F_118 ( V_7 , V_237 ) ;
continue;
case 'P' :
F_92 ( V_7 ) ;
continue;
case 'd' :
V_237 -> V_53 . V_223 = V_223 ;
F_132 ( V_7 , V_237 ) ;
continue;
case 'V' :
V_7 -> V_80 = ! V_7 -> V_80 ;
continue;
case 't' :
V_237 -> V_166 = V_166 ;
F_124 ( V_7 , V_237 ) ;
continue;
case 'S' :
V_237 -> V_233 = V_242 ;
F_146 ( V_7 , V_237 ) ;
continue;
case '/' :
if ( F_158 ( L_67 ,
L_68
L_69 ,
V_118 , L_70 ,
V_60 * 2 ) == V_73 ) {
V_3 -> V_247 = * V_118 ? V_118 : NULL ;
F_159 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_100 ( V_59 ) ) {
V_237 -> V_166 = NULL ;
V_237 -> V_53 . V_81 = NULL ;
F_139 ( V_7 , V_237 ) ;
}
continue;
case 's' :
if ( F_100 ( V_59 ) ) {
V_56 = F_142 ( V_7 , V_237 ) ;
if ( V_56 == V_231 )
goto V_245;
}
continue;
case 'i' :
if ( V_161 -> V_248 )
F_160 ( V_161 ) ;
continue;
case 'F' :
V_5 . V_182 ^= 1 ;
continue;
case 'z' :
if ( ! F_100 ( V_59 ) ) {
struct V_193 * V_71 = V_59 -> V_64 ;
V_71 -> V_194 = ! V_71 -> V_194 ;
}
continue;
case V_249 :
case 'h' :
case '?' :
F_161 ( & V_7 -> V_20 ,
F_100 ( V_59 ) ? V_238 : V_239 ) ;
continue;
case V_73 :
case V_250 :
case 'm' :
break;
case V_251 :
case V_252 : {
const void * V_71 ;
if ( F_162 ( V_7 -> V_227 ) ) {
if ( V_235 )
goto V_245;
if ( V_56 == V_251 &&
F_163 ( & V_7 -> V_20 ,
L_71 ) )
goto V_245;
continue;
}
V_71 = F_164 ( V_7 -> V_227 ) ;
if ( V_71 == & V_7 -> V_3 -> V_169 ) {
F_132 ( V_7 , V_237 ) ;
} else if ( V_71 == & V_7 -> V_3 -> V_170 ) {
F_124 ( V_7 , V_237 ) ;
} else if ( V_71 == & V_7 -> V_3 -> V_172 ) {
F_146 ( V_7 , V_237 ) ;
}
continue;
}
case 'q' :
case F_121 ( 'c' ) :
goto V_245;
case 'f' :
if ( ! F_100 ( V_59 ) ) {
struct V_193 * V_71 = V_59 -> V_64 ;
F_165 ( V_71 -> V_253 ) ;
if ( V_71 -> V_253 -> V_254 ) {
V_234 = L_72 ;
V_59 -> V_61 = V_60 ;
} else {
V_234 = L_73 ;
V_59 -> V_61 = 0 ;
}
continue;
}
default:
V_234 = L_74 ;
continue;
}
if ( ! V_246 )
goto V_255;
if ( V_7 -> V_54 == NULL )
goto V_256;
if ( V_257 == V_258 ) {
V_236 = V_7 -> V_51 -> V_221 ;
if ( V_236 == NULL )
goto V_256;
V_201 += F_123 ( V_7 ,
& V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_236 -> V_259 . V_223 ,
V_236 -> V_259 . V_81 ) ;
if ( V_236 -> V_260 . V_81 != V_236 -> V_259 . V_81 )
V_201 += F_123 ( V_7 ,
& V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_236 -> V_260 . V_223 ,
V_236 -> V_260 . V_81 ) ;
} else {
V_201 += F_123 ( V_7 ,
& V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_7 -> V_54 -> V_223 ,
V_7 -> V_54 -> V_81 ) ;
}
V_256:
V_201 += F_131 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] , V_166 ) ;
V_201 += F_135 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] , V_223 ) ;
V_201 += F_138 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_7 -> V_54 ?
V_7 -> V_54 -> V_223 : NULL ) ;
V_201 += F_148 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_242 ) ;
if ( V_7 -> V_51 ) {
V_201 += F_141 ( V_7 ,
& V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
V_166 , NULL ) ;
V_201 += F_141 ( V_7 ,
& V_237 [ V_201 ] ,
& V_195 [ V_201 ] ,
NULL , V_7 -> V_54 -> V_81 ) ;
}
V_201 += F_141 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] , NULL , NULL ) ;
V_201 += F_143 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] ) ;
V_255:
V_201 += F_145 ( V_7 , & V_237 [ V_201 ] ,
& V_195 [ V_201 ] ) ;
do {
struct V_216 * V_217 ;
V_202 = F_117 ( V_201 , V_195 ) ;
if ( V_202 == - 1 || V_202 >= V_201 )
break;
V_217 = & V_237 [ V_202 ] ;
V_56 = V_217 -> V_226 ( V_7 , V_217 ) ;
} while ( V_56 == 1 );
if ( V_56 == V_231 )
break;
}
V_245:
F_166 ( V_7 -> V_227 ) ;
V_74:
F_97 ( V_7 ) ;
F_108 ( V_195 , F_150 ) ;
return V_56 ;
}
static void F_167 ( struct V_19 * V_7 ,
void * V_133 , int V_29 )
{
struct V_261 * V_262 = F_11 ( V_7 ,
struct V_261 , V_20 ) ;
struct V_176 * V_177 = F_32 ( V_133 , struct V_176 , V_36 ) ;
struct V_3 * V_3 = F_105 ( V_177 ) ;
bool V_117 = F_56 ( V_7 , V_29 ) ;
unsigned long V_67 = V_3 -> V_65 . V_67 [ V_174 ] ;
const char * V_178 = F_101 ( V_177 ) ;
char V_100 [ 256 ] , V_167 ;
const char * V_263 = L_7 ;
T_8 V_88 ;
F_57 ( V_7 , V_117 ? V_84 :
V_83 ) ;
if ( F_102 ( V_177 ) ) {
struct V_176 * V_185 ;
V_178 = F_168 ( V_177 ) ;
F_104 (pos, evsel) {
struct V_3 * V_186 = F_105 ( V_185 ) ;
V_67 += V_186 -> V_65 . V_67 [ V_174 ] ;
}
}
V_67 = F_106 ( V_67 , & V_167 ) ;
V_88 = F_70 ( V_100 , sizeof( V_100 ) , L_75 , V_67 ,
V_167 , V_167 == ' ' ? L_15 : L_7 , V_178 ) ;
F_59 ( V_7 , L_12 , V_100 ) ;
V_67 = V_3 -> V_65 . V_67 [ V_68 ] ;
if ( V_67 != 0 ) {
V_262 -> V_264 = true ;
if ( ! V_117 )
F_57 ( V_7 , V_265 ) ;
V_67 = F_106 ( V_67 , & V_167 ) ;
V_88 += F_70 ( V_100 , sizeof( V_100 ) , L_76 ,
V_67 , V_167 , V_167 == ' ' ? L_15 : L_7 ) ;
V_263 = V_100 ;
}
F_58 ( V_7 , V_263 , V_7 -> V_28 - V_88 ) ;
if ( V_117 )
V_262 -> V_54 = V_177 ;
}
static int F_169 ( struct V_261 * V_262 ,
int V_67 , const char * V_55 ,
struct V_58 * V_59 )
{
struct V_266 * V_253 = V_262 -> V_20 . V_267 ;
struct V_176 * V_185 ;
const char * V_57 = L_77 ;
int V_60 = V_59 ? V_59 -> V_61 : 0 ;
int V_56 ;
if ( F_47 ( & V_262 -> V_20 , V_57 ,
L_78 ) < 0 )
return - 1 ;
while ( 1 ) {
V_56 = F_48 ( & V_262 -> V_20 , V_60 ) ;
switch ( V_56 ) {
case V_62 :
V_59 -> V_63 ( V_59 -> V_64 ) ;
if ( ! V_262 -> V_268 && V_262 -> V_264 ) {
F_43 ( & V_262 -> V_20 ) ;
V_262 -> V_268 = true ;
}
continue;
case V_250 :
case V_73 :
if ( ! V_262 -> V_54 )
continue;
V_185 = V_262 -> V_54 ;
V_269:
F_170 ( V_253 , V_185 ) ;
if ( V_59 )
V_59 -> V_63 ( V_59 -> V_64 ) ;
V_56 = F_149 ( V_185 , V_67 , V_55 ,
true , V_59 ,
V_262 -> V_4 ,
V_262 -> V_161 ) ;
F_50 ( & V_262 -> V_20 , V_57 ) ;
switch ( V_56 ) {
case V_243 :
if ( V_185 -> V_36 . V_44 == & V_253 -> V_11 )
V_185 = F_171 ( V_253 ) ;
else
V_185 = F_172 ( V_185 ) ;
goto V_269;
case V_244 :
if ( V_185 -> V_36 . V_47 == & V_253 -> V_11 )
V_185 = F_173 ( V_253 ) ;
else
V_185 = F_174 ( V_185 ) ;
goto V_269;
case V_231 :
case 'q' :
case F_121 ( 'c' ) :
goto V_74;
case V_251 :
default:
continue;
}
case V_252 :
continue;
case V_251 :
if ( ! F_163 ( & V_262 -> V_20 ,
L_71 ) )
continue;
case 'q' :
case F_121 ( 'c' ) :
goto V_74;
default:
continue;
}
}
V_74:
F_53 ( & V_262 -> V_20 ) ;
return V_56 ;
}
static bool F_175 ( struct V_19 * V_7 V_87 ,
void * V_133 )
{
struct V_176 * V_177 = F_32 ( V_133 , struct V_176 , V_36 ) ;
if ( V_5 . V_270 && ! F_176 ( V_177 ) )
return true ;
return false ;
}
static int F_177 ( struct V_266 * V_253 ,
int V_16 , const char * V_55 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_160 * V_161 )
{
struct V_176 * V_185 ;
struct V_261 V_262 = {
. V_20 = {
. V_11 = & V_253 -> V_11 ,
. V_61 = V_271 ,
. V_163 = V_272 ,
. V_273 = F_167 ,
. V_274 = F_175 ,
. V_16 = V_16 ,
. V_267 = V_253 ,
} ,
. V_4 = V_4 ,
. V_161 = V_161 ,
} ;
F_155 ( L_79 ) ;
F_178 (evlist, pos) {
const char * V_178 = F_101 ( V_185 ) ;
T_8 V_275 = strlen ( V_178 ) + 7 ;
if ( V_262 . V_20 . V_28 < V_275 )
V_262 . V_20 . V_28 = V_275 ;
}
return F_169 ( & V_262 , V_16 , V_55 , V_59 ) ;
}
int F_179 ( struct V_266 * V_253 , const char * V_55 ,
struct V_58 * V_59 ,
float V_4 ,
struct V_160 * V_161 )
{
int V_16 = V_253 -> V_16 ;
V_276:
if ( V_16 == 1 ) {
struct V_176 * V_42 = F_171 ( V_253 ) ;
return F_149 ( V_42 , V_16 , V_55 ,
false , V_59 , V_4 ,
V_161 ) ;
}
if ( V_5 . V_270 ) {
struct V_176 * V_185 ;
V_16 = 0 ;
F_178 (evlist, pos) {
if ( F_176 ( V_185 ) )
V_16 ++ ;
}
if ( V_16 == 1 )
goto V_276;
}
return F_177 ( V_253 , V_16 , V_55 ,
V_59 , V_4 , V_161 ) ;
}
