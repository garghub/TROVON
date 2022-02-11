static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) || V_2 -> V_4 ;
}
static int F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 ;
struct V_3 * V_3 = V_5 -> V_3 ;
int V_8 = 0 ;
for ( V_7 = F_4 ( & V_3 -> V_9 ) ;
( V_7 = F_5 ( V_7 , V_5 -> V_4 ) ) != NULL ;
V_7 = F_6 ( V_7 ) ) {
struct V_10 * V_11 =
F_7 ( V_7 , struct V_10 , V_6 ) ;
if ( V_11 -> V_12 . V_13 )
V_8 += V_11 -> V_14 ;
}
return V_8 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( F_1 ( V_2 ) )
V_15 = V_2 -> V_16 ;
else
V_15 = V_2 -> V_3 -> V_15 ;
V_2 -> V_17 = F_3 ( V_2 ) ;
return V_15 + V_2 -> V_17 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_18 * V_5 = & V_2 -> V_19 ;
T_2 V_20 = V_2 -> V_21 ? 1 : 0 , V_22 ;
V_5 -> V_23 = V_5 -> V_24 - V_20 ;
V_22 = V_5 -> V_25 - V_5 -> V_26 ;
if ( V_22 >= V_5 -> V_23 )
V_5 -> V_25 -= V_22 - V_5 -> V_23 + 1 ;
}
static void F_10 ( struct V_18 * V_5 )
{
struct V_1 * V_2 = F_11 ( V_5 , struct V_1 , V_19 ) ;
V_5 -> V_27 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_5 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_5 , int V_28 , int V_29 )
{
T_2 V_20 = V_5 -> V_21 ? 1 : 0 ;
F_15 ( & V_5 -> V_19 , V_28 + V_20 , V_29 ) ;
}
static void F_16 ( struct V_1 * V_5 )
{
V_5 -> V_17 = 0 ;
F_17 ( V_5 ) ;
V_5 -> V_19 . V_15 = F_8 ( V_5 ) ;
F_10 ( & V_5 -> V_19 ) ;
F_18 ( & V_5 -> V_19 ) ;
}
static char F_19 ( bool V_13 )
{
return V_13 ? '-' : '+' ;
}
static char F_20 ( const struct V_30 * V_12 )
{
return V_12 -> V_31 ? F_19 ( V_12 -> V_13 ) : ' ' ;
}
static char F_21 ( const struct V_10 * V_11 )
{
return F_20 ( & V_11 -> V_12 ) ;
}
static char F_22 ( const struct V_32 * V_33 )
{
return F_20 ( & V_33 -> V_12 ) ;
}
static void F_23 ( struct V_30 * V_12 , bool V_34 )
{
V_12 -> V_13 = V_34 ? V_12 -> V_31 : false ;
}
static int F_24 ( struct V_35 * V_36 )
{
int V_37 = 0 ;
struct V_6 * V_7 ;
for ( V_7 = F_4 ( & V_36 -> V_38 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_39 = F_7 ( V_7 , struct V_35 , V_6 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
F_25 (chain, &child->val, list) {
++ V_37 ;
V_41 = F_22 ( V_40 ) ;
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' )
V_37 += F_24 ( V_39 ) ;
}
return V_37 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_32 * V_40 ;
bool V_13 = false ;
int V_37 = 0 ;
F_25 (chain, &node->val, list) {
++ V_37 ;
V_13 = V_40 -> V_12 . V_13 ;
}
if ( V_13 )
V_37 += F_24 ( V_36 ) ;
return V_37 ;
}
static int F_27 ( struct V_38 * V_40 )
{
struct V_6 * V_7 ;
int V_37 = 0 ;
for ( V_7 = F_4 ( V_40 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_36 = F_7 ( V_7 , struct V_35 , V_6 ) ;
V_37 += F_26 ( V_36 ) ;
}
return V_37 ;
}
static bool F_28 ( struct V_30 * V_12 )
{
if ( ! V_12 )
return false ;
if ( ! V_12 -> V_31 )
return false ;
V_12 -> V_13 = ! V_12 -> V_13 ;
return true ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_4 ( & V_36 -> V_38 ) ;
for ( V_7 = F_4 ( & V_36 -> V_38 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_39 = F_7 ( V_7 , struct V_35 , V_6 ) ;
struct V_32 * V_40 ;
bool V_42 = true ;
F_25 (chain, &child->val, list) {
if ( V_42 ) {
V_42 = false ;
V_40 -> V_12 . V_31 = V_40 -> V_43 . V_44 != & V_39 -> V_45 ||
! F_30 ( & V_39 -> V_38 ) ;
} else
V_40 -> V_12 . V_31 = V_40 -> V_43 . V_44 == & V_39 -> V_45 &&
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
V_40 -> V_12 . V_31 = V_46 ;
if ( ! F_33 ( & V_36 -> V_45 ) ) {
V_40 = F_32 ( V_36 -> V_45 . V_47 , struct V_32 , V_43 ) ;
V_40 -> V_12 . V_31 = ! F_30 ( & V_36 -> V_38 ) ;
}
F_29 ( V_36 ) ;
}
static void F_34 ( struct V_38 * V_48 )
{
struct V_6 * V_7 = F_4 ( V_48 ) ;
bool V_46 = V_7 && F_6 ( V_7 ) ;
for ( V_7 = F_4 ( V_48 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_36 = F_7 ( V_7 , struct V_35 , V_6 ) ;
F_31 ( V_36 , V_46 ) ;
}
}
static void F_35 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_49 ) {
V_11 -> V_12 . V_31 = ! F_30 ( & V_11 -> V_50 ) ;
F_34 ( & V_11 -> V_50 ) ;
V_11 -> V_49 = true ;
}
}
static bool F_36 ( struct V_1 * V_5 )
{
if ( F_28 ( V_5 -> V_51 ) ) {
struct V_10 * V_11 = V_5 -> V_52 ;
F_35 ( V_11 ) ;
V_5 -> V_19 . V_15 -= V_11 -> V_14 ;
V_5 -> V_17 -= V_11 -> V_14 ;
if ( V_11 -> V_12 . V_13 )
V_11 -> V_14 = F_27 ( & V_11 -> V_50 ) ;
else
V_11 -> V_14 = 0 ;
V_5 -> V_19 . V_15 += V_11 -> V_14 ;
V_5 -> V_17 += V_11 -> V_14 ;
return true ;
}
return false ;
}
static int F_37 ( struct V_35 * V_36 , bool V_34 )
{
int V_37 = 0 ;
struct V_6 * V_7 ;
for ( V_7 = F_4 ( & V_36 -> V_38 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_39 = F_7 ( V_7 , struct V_35 , V_6 ) ;
struct V_32 * V_40 ;
bool V_31 = false ;
F_25 (chain, &child->val, list) {
++ V_37 ;
F_23 ( & V_40 -> V_12 , V_34 ) ;
V_31 = V_40 -> V_12 . V_31 ;
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
F_25 (chain, &node->val, list) {
++ V_37 ;
F_23 ( & V_40 -> V_12 , V_34 ) ;
V_31 = V_40 -> V_12 . V_31 ;
}
if ( V_31 )
V_37 += F_37 ( V_36 , V_34 ) ;
return V_37 ;
}
static int F_39 ( struct V_38 * V_40 , bool V_34 )
{
struct V_6 * V_7 ;
int V_37 = 0 ;
for ( V_7 = F_4 ( V_40 ) ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_35 * V_36 = F_7 ( V_7 , struct V_35 , V_6 ) ;
V_37 += F_38 ( V_36 , V_34 ) ;
}
return V_37 ;
}
static void F_40 ( struct V_10 * V_11 , bool V_34 )
{
F_35 ( V_11 ) ;
F_23 ( & V_11 -> V_12 , V_34 ) ;
if ( V_11 -> V_12 . V_31 ) {
int V_37 = F_39 ( & V_11 -> V_50 , V_34 ) ;
V_11 -> V_14 = V_34 ? V_37 : 0 ;
} else
V_11 -> V_14 = 0 ;
}
static void
F_41 ( struct V_1 * V_5 , bool V_34 )
{
struct V_6 * V_7 ;
struct V_3 * V_3 = V_5 -> V_3 ;
for ( V_7 = F_4 ( & V_3 -> V_9 ) ;
( V_7 = F_5 ( V_7 , V_5 -> V_4 ) ) != NULL ;
V_7 = F_6 ( V_7 ) ) {
struct V_10 * V_11 = F_7 ( V_7 , struct V_10 , V_6 ) ;
F_40 ( V_11 , V_34 ) ;
V_5 -> V_17 += V_11 -> V_14 ;
}
}
static void F_42 ( struct V_1 * V_5 , bool V_34 )
{
V_5 -> V_17 = 0 ;
F_41 ( V_5 , V_34 ) ;
V_5 -> V_19 . V_15 = F_8 ( V_5 ) ;
F_18 ( & V_5 -> V_19 ) ;
}
static void F_43 ( struct V_18 * V_5 )
{
F_44 ( V_5 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_45 ( struct V_1 * V_5 ,
struct V_53 * V_54 )
{
int V_55 ;
char V_56 [ 160 ] ;
int V_57 = V_54 ? V_54 -> V_58 : 0 ;
V_5 -> V_19 . V_9 = & V_5 -> V_3 -> V_9 ;
V_5 -> V_19 . V_15 = F_8 ( V_5 ) ;
F_46 ( V_5 -> V_3 , V_54 , V_56 , sizeof( V_56 ) ) ;
if ( F_47 ( & V_5 -> V_19 , V_56 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_55 = F_48 ( & V_5 -> V_19 , V_57 ) ;
switch ( V_55 ) {
case V_59 : {
T_3 V_15 ;
V_54 -> V_60 ( V_54 -> V_61 ) ;
if ( F_1 ( V_5 ) )
F_17 ( V_5 ) ;
V_15 = F_8 ( V_5 ) ;
F_49 ( & V_5 -> V_19 , V_15 ) ;
if ( V_5 -> V_3 -> V_62 . V_63 !=
V_5 -> V_3 -> V_62 . V_64 [ V_65 ] ) {
V_5 -> V_3 -> V_62 . V_63 =
V_5 -> V_3 -> V_62 . V_64 [ V_65 ] ;
F_43 ( & V_5 -> V_19 ) ;
}
F_46 ( V_5 -> V_3 ,
V_54 , V_56 , sizeof( V_56 ) ) ;
F_50 ( & V_5 -> V_19 , V_56 ) ;
continue;
}
case 'D' : {
static int V_66 ;
struct V_10 * V_67 = F_7 ( V_5 -> V_19 . V_68 ,
struct V_10 , V_6 ) ;
F_51 () ;
F_52 ( L_7 ,
V_66 ++ , V_5 -> V_19 . V_15 ,
V_5 -> V_3 -> V_15 ,
V_5 -> V_19 . V_23 ,
V_5 -> V_19 . V_25 ,
V_5 -> V_19 . V_26 ,
V_67 -> V_69 , V_67 -> V_14 ) ;
}
break;
case 'C' :
F_42 ( V_5 , false ) ;
break;
case 'E' :
F_42 ( V_5 , true ) ;
break;
case 'H' :
V_5 -> V_21 = ! V_5 -> V_21 ;
F_9 ( V_5 ) ;
break;
case V_70 :
if ( F_36 ( V_5 ) )
break;
default:
goto V_71;
}
}
V_71:
F_53 ( & V_5 -> V_19 ) ;
return V_55 ;
}
static void F_54 ( struct V_1 * V_5 ,
struct V_32 * V_40 ,
const char * V_72 , int V_73 ,
unsigned short V_28 ,
struct V_74 * V_61 )
{
int V_75 , V_27 ;
char V_41 = F_22 ( V_40 ) ;
bool V_76 = V_5 -> V_77 && V_40 -> V_12 . V_78 && F_55 ( V_40 -> V_12 . V_78 ) -> V_79 ;
V_75 = V_80 ;
V_27 = V_5 -> V_19 . V_27 - ( V_73 + 2 ) ;
if ( F_56 ( & V_5 -> V_19 , V_28 ) ) {
V_5 -> V_51 = & V_40 -> V_12 ;
V_75 = V_81 ;
V_61 -> V_82 = true ;
}
F_57 ( & V_5 -> V_19 , V_75 ) ;
F_14 ( V_5 , V_28 , 0 ) ;
F_58 ( L_8 , V_73 ) ;
F_59 ( L_9 , V_41 ) ;
F_60 ( & V_5 -> V_19 , V_76 ? V_83 : ' ' ) ;
F_58 ( V_72 , V_27 ) ;
}
static void F_61 ( struct V_1 * V_19 V_84 ,
struct V_32 * V_40 ,
const char * V_72 , int V_73 ,
unsigned short V_28 V_84 ,
struct V_74 * V_61 )
{
char V_41 = F_22 ( V_40 ) ;
V_61 -> V_85 += fprintf ( V_61 -> V_86 , L_10 , V_73 , L_8 ,
V_41 , V_72 ) ;
}
static bool F_62 ( struct V_1 * V_5 ,
unsigned short V_28 )
{
return V_5 -> V_19 . V_23 == V_28 ;
}
static bool F_63 ( struct V_1 * V_5 V_84 ,
unsigned short V_28 V_84 )
{
return false ;
}
static int F_64 ( struct V_1 * V_5 ,
struct V_38 * V_48 , int V_87 ,
unsigned short V_28 , T_3 V_88 ,
T_4 V_89 ,
struct V_74 * V_61 ,
T_5 V_90 )
{
struct V_6 * V_36 ;
int V_91 = V_28 , V_73 = V_87 * V_92 ;
T_3 V_93 ;
bool V_94 ;
V_36 = F_4 ( V_48 ) ;
V_94 = V_36 && F_6 ( V_36 ) ;
while ( V_36 ) {
struct V_35 * V_39 = F_7 ( V_36 , struct V_35 , V_6 ) ;
struct V_6 * V_44 = F_6 ( V_36 ) ;
T_3 V_95 = F_65 ( V_39 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
int V_42 = true ;
int V_96 = 0 ;
F_25 (chain, &child->val, list) {
char V_97 [ 1024 ] , * V_98 ;
const char * V_72 ;
bool V_99 = V_42 ;
if ( V_42 )
V_42 = false ;
else if ( V_94 )
V_96 = V_92 ;
V_41 = F_22 ( V_40 ) ;
if ( V_61 -> V_69 != 0 ) {
V_61 -> V_69 -- ;
goto V_100;
}
V_98 = NULL ;
V_72 = F_66 ( V_40 , V_97 , sizeof( V_97 ) ,
V_5 -> V_77 ) ;
if ( V_99 && V_94 ) {
double V_101 = V_95 * 100.0 / V_88 ;
if ( F_67 ( & V_98 , L_11 , V_101 , V_72 ) < 0 )
V_72 = L_12 ;
else
V_72 = V_98 ;
}
V_89 ( V_5 , V_40 , V_72 , V_73 + V_96 , V_28 , V_61 ) ;
free ( V_98 ) ;
if ( V_90 ( V_5 , ++ V_28 ) )
goto V_71;
V_100:
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' ) {
const int V_102 = V_87 + ( V_96 ? 2 : 1 ) ;
if ( V_103 . V_104 == V_105 )
V_93 = V_39 -> V_106 ;
else
V_93 = V_88 ;
V_28 += F_64 ( V_5 , & V_39 -> V_38 ,
V_102 , V_28 , V_93 ,
V_89 , V_61 , V_90 ) ;
}
if ( V_90 ( V_5 , V_28 ) )
break;
V_36 = V_44 ;
}
V_71:
return V_28 - V_91 ;
}
static int F_68 ( struct V_107 * V_108 , const char * V_109 , ... )
{
struct V_110 * V_61 = V_108 -> V_111 ;
int V_112 , V_113 ;
T_6 args ;
double V_101 ;
va_start ( args , V_109 ) ;
V_113 = va_arg ( args , int ) ;
V_101 = va_arg ( args , double ) ;
va_end ( args ) ;
F_69 ( V_61 -> V_19 , V_101 , V_61 -> V_114 ) ;
V_112 = F_70 ( V_108 -> V_115 , V_108 -> V_116 , V_109 , V_113 , V_101 ) ;
F_59 ( L_13 , V_108 -> V_115 ) ;
F_71 ( V_108 , V_112 ) ;
return V_112 ;
}
void F_72 ( void )
{
V_117 [ V_118 ] . V_75 =
V_119 ;
V_117 [ V_120 ] . V_75 =
V_121 ;
V_117 [ V_122 ] . V_75 =
V_123 ;
V_117 [ V_124 ] . V_75 =
V_125 ;
V_117 [ V_126 ] . V_75 =
V_127 ;
V_117 [ V_128 ] . V_75 =
V_129 ;
}
static int F_73 ( struct V_1 * V_5 ,
struct V_10 * V_130 ,
unsigned short V_28 )
{
char V_131 [ 256 ] ;
int V_85 = 0 ;
int V_27 = V_5 -> V_19 . V_27 ;
char V_41 = ' ' ;
bool V_114 = F_56 ( & V_5 -> V_19 , V_28 ) ;
T_7 V_69 = V_130 -> V_69 ;
bool V_42 = true ;
struct V_132 * V_109 ;
if ( V_114 ) {
V_5 -> V_52 = V_130 ;
V_5 -> V_51 = & V_130 -> V_12 ;
}
if ( V_133 . V_134 ) {
F_35 ( V_130 ) ;
V_41 = F_21 ( V_130 ) ;
}
if ( V_69 == 0 ) {
struct V_110 V_61 = {
. V_19 = & V_5 -> V_19 ,
. V_41 = V_41 ,
. V_114 = V_114 ,
} ;
struct V_107 V_108 = {
. V_115 = V_131 ,
. V_116 = sizeof( V_131 ) ,
. V_111 = & V_61 ,
} ;
F_14 ( V_5 , V_28 , 0 ) ;
F_74 (fmt) {
if ( F_75 ( V_109 ) )
continue;
if ( V_114 && V_5 -> V_19 . V_135 ) {
F_57 ( & V_5 -> V_19 ,
V_81 ) ;
} else {
F_57 ( & V_5 -> V_19 ,
V_80 ) ;
}
if ( V_42 ) {
if ( V_133 . V_134 ) {
F_59 ( L_14 , V_41 ) ;
V_27 -= 2 ;
}
V_42 = false ;
} else {
F_59 ( L_15 ) ;
V_27 -= 2 ;
}
if ( V_109 -> V_75 ) {
V_27 -= V_109 -> V_75 ( V_109 , & V_108 , V_130 ) ;
} else {
V_27 -= V_109 -> V_130 ( V_109 , & V_108 , V_130 ) ;
F_59 ( L_13 , V_131 ) ;
}
}
if ( ! V_5 -> V_19 . V_135 )
V_27 += 1 ;
F_58 ( L_16 , V_27 ) ;
++ V_28 ;
++ V_85 ;
} else
-- V_69 ;
if ( V_41 == '-' && V_28 != V_5 -> V_19 . V_23 ) {
T_3 V_88 = F_76 ( V_130 -> V_3 ) ;
struct V_74 V_61 = {
. V_69 = V_69 ,
. V_82 = V_114 ,
} ;
if ( V_103 . V_104 == V_105 ) {
if ( V_133 . V_136 )
V_88 = V_130 -> V_137 -> V_138 ;
else
V_88 = V_130 -> V_139 . V_138 ;
}
V_85 += F_64 ( V_5 ,
& V_130 -> V_50 , 1 , V_28 , V_88 ,
F_54 , & V_61 ,
F_62 ) ;
if ( V_61 . V_82 )
V_5 -> V_52 = V_130 ;
}
return V_85 ;
}
static int F_77 ( struct V_107 * V_108 , int V_140 )
{
F_71 ( V_108 , V_140 ) ;
return V_108 -> V_116 <= 0 ;
}
static int F_78 ( char * V_115 , T_8 V_116 , struct V_3 * V_3 )
{
struct V_107 V_141 = {
. V_115 = V_115 ,
. V_116 = V_116 ,
} ;
struct V_132 * V_109 ;
T_8 V_112 = 0 ;
if ( V_133 . V_134 ) {
V_112 = F_70 ( V_115 , V_116 , L_15 ) ;
if ( F_77 ( & V_141 , V_112 ) )
return V_112 ;
}
F_74 (fmt) {
if ( F_75 ( V_109 ) )
continue;
V_112 = V_109 -> V_142 ( V_109 , & V_141 , F_79 ( V_3 ) ) ;
if ( F_77 ( & V_141 , V_112 ) )
break;
V_112 = F_70 ( V_141 . V_115 , V_141 . V_116 , L_15 ) ;
if ( F_77 ( & V_141 , V_112 ) )
break;
}
return V_112 ;
}
static void F_80 ( struct V_1 * V_5 )
{
char V_143 [ 1024 ] ;
F_78 ( V_143 , sizeof( V_143 ) , V_5 -> V_3 ) ;
F_15 ( & V_5 -> V_19 , 0 , 0 ) ;
F_57 ( & V_5 -> V_19 , V_144 ) ;
F_58 ( V_143 , V_5 -> V_19 . V_27 + 1 ) ;
}
static void F_81 ( struct V_18 * V_5 )
{
if ( V_5 -> V_68 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_5 , struct V_1 , V_19 ) ;
V_5 -> V_68 = F_4 ( & V_2 -> V_3 -> V_9 ) ;
}
}
static unsigned int F_82 ( struct V_18 * V_5 )
{
unsigned V_28 = 0 ;
T_2 V_20 = 0 ;
struct V_6 * V_7 ;
struct V_1 * V_2 = F_11 ( V_5 , struct V_1 , V_19 ) ;
if ( V_2 -> V_21 ) {
F_80 ( V_2 ) ;
V_20 = 1 ;
}
F_81 ( V_5 ) ;
for ( V_7 = V_5 -> V_68 ; V_7 ; V_7 = F_6 ( V_7 ) ) {
struct V_10 * V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
float V_101 ;
if ( V_67 -> V_145 )
continue;
V_101 = F_83 ( V_67 ) ;
if ( V_101 < V_2 -> V_4 )
continue;
V_28 += F_73 ( V_2 , V_67 , V_28 ) ;
if ( V_28 == V_5 -> V_23 )
break;
}
return V_28 + V_20 ;
}
static struct V_6 * F_5 ( struct V_6 * V_7 ,
float V_4 )
{
while ( V_7 != NULL ) {
struct V_10 * V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
float V_101 = F_83 ( V_67 ) ;
if ( ! V_67 -> V_145 && V_101 >= V_4 )
return V_7 ;
V_7 = F_6 ( V_7 ) ;
}
return NULL ;
}
static struct V_6 * F_84 ( struct V_6 * V_7 ,
float V_4 )
{
while ( V_7 != NULL ) {
struct V_10 * V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
float V_101 = F_83 ( V_67 ) ;
if ( ! V_67 -> V_145 && V_101 >= V_4 )
return V_7 ;
V_7 = F_85 ( V_7 ) ;
}
return NULL ;
}
static void F_86 ( struct V_18 * V_5 ,
T_7 V_73 , int V_146 )
{
struct V_10 * V_67 ;
struct V_6 * V_7 ;
bool V_42 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_5 , struct V_1 , V_19 ) ;
if ( V_5 -> V_15 == 0 )
return;
F_81 ( V_5 ) ;
switch ( V_146 ) {
case V_147 :
V_7 = F_5 ( F_4 ( V_5 -> V_9 ) ,
V_2 -> V_4 ) ;
break;
case V_148 :
V_7 = V_5 -> V_68 ;
goto V_149;
case V_150 :
V_7 = F_84 ( F_87 ( V_5 -> V_9 ) ,
V_2 -> V_4 ) ;
V_42 = false ;
break;
default:
return;
}
V_67 = F_7 ( V_5 -> V_68 , struct V_10 , V_6 ) ;
V_67 -> V_69 = 0 ;
V_149:
if ( V_73 > 0 ) {
do {
V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
if ( V_67 -> V_12 . V_13 ) {
T_2 V_151 = V_67 -> V_14 - V_67 -> V_69 ;
if ( V_73 > V_151 ) {
V_73 -= V_151 ;
V_67 -> V_69 = 0 ;
} else {
V_67 -> V_69 += V_73 ;
V_73 = 0 ;
V_5 -> V_68 = V_7 ;
break;
}
}
V_7 = F_5 ( F_6 ( V_7 ) , V_2 -> V_4 ) ;
if ( V_7 == NULL )
break;
-- V_73 ;
V_5 -> V_68 = V_7 ;
} while ( V_73 != 0 );
} else if ( V_73 < 0 ) {
while ( 1 ) {
V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
if ( V_67 -> V_12 . V_13 ) {
if ( V_42 ) {
if ( - V_73 > V_67 -> V_69 ) {
V_73 += V_67 -> V_69 ;
V_67 -> V_69 = 0 ;
} else {
V_67 -> V_69 += V_73 ;
V_73 = 0 ;
V_5 -> V_68 = V_7 ;
break;
}
} else {
if ( - V_73 > V_67 -> V_14 ) {
V_73 += V_67 -> V_14 ;
V_67 -> V_69 = 0 ;
} else {
V_67 -> V_69 = V_67 -> V_14 + V_73 ;
V_73 = 0 ;
V_5 -> V_68 = V_7 ;
break;
}
}
}
V_7 = F_84 ( F_85 ( V_7 ) ,
V_2 -> V_4 ) ;
if ( V_7 == NULL )
break;
++ V_73 ;
V_5 -> V_68 = V_7 ;
if ( V_73 == 0 ) {
V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
if ( V_67 -> V_12 . V_13 )
V_67 -> V_69 = V_67 -> V_14 ;
break;
}
V_42 = false ;
}
} else {
V_5 -> V_68 = V_7 ;
V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
V_67 -> V_69 = 0 ;
}
}
static int F_88 ( struct V_1 * V_5 ,
struct V_10 * V_11 , T_9 * V_86 )
{
T_3 V_88 = F_76 ( V_11 -> V_3 ) ;
struct V_74 V_61 = {
. V_86 = V_86 ,
} ;
if ( V_133 . V_136 )
V_88 = V_11 -> V_137 -> V_138 ;
F_64 ( V_5 , & V_11 -> V_50 , 1 , 0 , V_88 ,
F_61 , & V_61 ,
F_63 ) ;
return V_61 . V_85 ;
}
static int F_89 ( struct V_1 * V_5 ,
struct V_10 * V_11 , T_9 * V_86 )
{
char V_131 [ 8192 ] ;
int V_85 = 0 ;
char V_41 = ' ' ;
struct V_107 V_108 = {
. V_115 = V_131 ,
. V_116 = sizeof( V_131 ) ,
} ;
struct V_132 * V_109 ;
bool V_42 = true ;
int V_112 ;
if ( V_133 . V_134 )
V_41 = F_21 ( V_11 ) ;
if ( V_133 . V_134 )
V_85 += fprintf ( V_86 , L_14 , V_41 ) ;
F_74 (fmt) {
if ( F_75 ( V_109 ) )
continue;
if ( ! V_42 ) {
V_112 = F_70 ( V_108 . V_115 , V_108 . V_116 , L_15 ) ;
F_71 ( & V_108 , V_112 ) ;
} else
V_42 = false ;
V_112 = V_109 -> V_130 ( V_109 , & V_108 , V_11 ) ;
F_71 ( & V_108 , V_112 ) ;
}
V_85 += fprintf ( V_86 , L_17 , F_90 ( V_131 ) ) ;
if ( V_41 == '-' )
V_85 += F_88 ( V_5 , V_11 , V_86 ) ;
return V_85 ;
}
static int F_91 ( struct V_1 * V_5 , T_9 * V_86 )
{
struct V_6 * V_7 = F_5 ( F_4 ( V_5 -> V_19 . V_9 ) ,
V_5 -> V_4 ) ;
int V_85 = 0 ;
while ( V_7 ) {
struct V_10 * V_67 = F_7 ( V_7 , struct V_10 , V_6 ) ;
V_85 += F_89 ( V_5 , V_67 , V_86 ) ;
V_7 = F_5 ( F_6 ( V_7 ) , V_5 -> V_4 ) ;
}
return V_85 ;
}
static int F_92 ( struct V_1 * V_5 )
{
char V_152 [ 64 ] ;
T_9 * V_86 ;
while ( 1 ) {
F_70 ( V_152 , sizeof( V_152 ) , L_18 , V_5 -> V_153 ) ;
if ( F_93 ( V_152 , V_154 ) )
break;
if ( ++ V_5 -> V_153 == 8192 ) {
F_52 ( L_19 ) ;
return - 1 ;
}
}
V_86 = fopen ( V_152 , L_20 ) ;
if ( V_86 == NULL ) {
char V_97 [ 64 ] ;
const char * V_155 = F_94 ( V_156 , V_97 , sizeof( V_97 ) ) ;
F_52 ( L_21 , V_152 , V_155 ) ;
return - 1 ;
}
++ V_5 -> V_153 ;
F_91 ( V_5 , V_86 ) ;
fclose ( V_86 ) ;
F_52 ( L_22 , V_152 ) ;
return 0 ;
}
static struct V_1 * F_95 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_96 ( sizeof( * V_5 ) ) ;
if ( V_5 ) {
V_5 -> V_3 = V_3 ;
V_5 -> V_19 . V_58 = F_82 ;
V_5 -> V_19 . V_157 = F_10 ;
V_5 -> V_19 . V_158 = F_86 ;
V_5 -> V_19 . V_159 = true ;
V_5 -> V_21 = V_133 . V_160 ;
}
return V_5 ;
}
static void F_97 ( struct V_1 * V_5 )
{
free ( V_5 ) ;
}
static struct V_10 * F_98 ( struct V_1 * V_5 )
{
return V_5 -> V_52 ;
}
static struct V_161 * F_99 ( struct V_1 * V_5 )
{
return V_5 -> V_52 -> V_161 ;
}
static inline bool F_100 ( void * V_60 )
{
return V_60 == NULL ;
}
static int F_46 ( struct V_3 * V_3 ,
struct V_53 * V_54 ,
char * V_97 , T_8 V_116 )
{
char V_162 ;
int V_85 ;
const struct V_163 * V_163 = V_3 -> V_164 ;
const struct V_161 * V_161 = V_3 -> V_165 ;
unsigned long V_166 = V_3 -> V_62 . V_64 [ V_167 ] ;
T_3 V_64 = V_3 -> V_62 . V_168 ;
struct V_169 * V_170 = F_79 ( V_3 ) ;
const char * V_171 = F_101 ( V_170 ) ;
char V_115 [ 512 ] ;
T_8 V_172 = sizeof( V_115 ) ;
if ( V_133 . V_173 ) {
V_166 = V_3 -> V_62 . V_174 ;
V_64 = V_3 -> V_62 . V_175 ;
}
if ( F_102 ( V_170 ) ) {
struct V_169 * V_176 ;
F_103 ( V_170 , V_115 , V_172 ) ;
V_171 = V_115 ;
F_104 (pos, evsel) {
struct V_3 * V_177 = F_105 ( V_176 ) ;
if ( V_133 . V_173 ) {
V_166 += V_177 -> V_62 . V_174 ;
V_64 += V_177 -> V_62 . V_175 ;
} else {
V_166 += V_177 -> V_62 . V_64 [ V_167 ] ;
V_64 += V_177 -> V_62 . V_168 ;
}
}
}
V_166 = F_106 ( V_166 , & V_162 ) ;
V_85 = F_70 ( V_97 , V_116 ,
L_23 V_178 ,
V_166 , V_162 , V_171 , V_64 ) ;
if ( V_3 -> V_179 )
V_85 += snprintf ( V_97 + V_85 , V_116 - V_85 ,
L_24 , V_3 -> V_179 ) ;
if ( V_161 )
V_85 += F_70 ( V_97 + V_85 , V_116 - V_85 ,
L_25 ,
( V_161 -> V_180 ? F_107 ( V_161 ) : L_16 ) ,
V_161 -> V_181 ) ;
if ( V_163 )
V_85 += F_70 ( V_97 + V_85 , V_116 - V_85 ,
L_26 , V_163 -> V_182 ) ;
if ( ! F_100 ( V_54 ) ) {
struct V_183 * V_68 = V_54 -> V_61 ;
if ( V_68 -> V_184 )
V_85 += F_70 ( V_97 + V_85 , V_116 - V_85 , L_27 ) ;
}
return V_85 ;
}
static inline void F_108 ( char * * V_185 , int V_37 )
{
int V_186 ;
for ( V_186 = 0 ; V_186 < V_37 ; ++ V_186 )
F_109 ( & V_185 [ V_186 ] ) ;
}
static int F_110 ( void )
{
char * V_187 , * V_185 [ 32 ] , * V_188 [ 32 ] , * V_189 ;
T_10 * V_190 ;
int V_191 = 0 , V_192 = - 1 , V_112 = - 1 ;
struct V_193 * V_194 ;
V_187 = getenv ( L_28 ) ;
if ( ! V_187 )
return V_112 ;
V_190 = F_111 ( V_187 ) ;
if ( ! V_190 )
return V_112 ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_185 , 0 , sizeof( V_188 ) ) ;
while ( ( V_194 = F_112 ( V_190 ) ) ) {
char V_195 [ V_196 ] ;
T_3 V_197 ;
char * V_198 = V_194 -> V_199 ;
T_9 * V_200 ;
if ( ! ( V_194 -> V_201 == V_202 ) )
continue;
snprintf ( V_195 , sizeof( V_195 ) , L_29 , V_187 , V_198 ) ;
V_200 = fopen ( V_195 , L_30 ) ;
if ( ! V_200 )
continue;
if ( fread ( & V_197 , 1 , 8 , V_200 ) < 8 )
goto V_203;
if ( F_113 ( V_197 ) ) {
V_185 [ V_191 ] = F_114 ( V_198 ) ;
if ( ! V_185 [ V_191 ] )
goto V_203;
V_188 [ V_191 ] = F_114 ( V_195 ) ;
if ( ! V_188 [ V_191 ] ) {
F_109 ( & V_185 [ V_191 ] ) ;
F_115 ( L_31 ) ;
fclose ( V_200 ) ;
break;
}
V_191 ++ ;
}
V_203:
fclose ( V_200 ) ;
if ( V_191 >= 32 ) {
F_115 ( L_32
L_33 ) ;
break;
}
}
F_116 ( V_190 ) ;
if ( V_191 ) {
V_192 = F_117 ( V_191 , V_185 ) ;
if ( V_192 < V_191 && V_192 >= 0 ) {
V_189 = F_114 ( V_188 [ V_192 ] ) ;
if ( V_189 ) {
if ( V_204 )
free ( ( void * ) V_205 ) ;
V_205 = V_189 ;
V_204 = true ;
V_112 = 0 ;
} else
F_115 ( L_34 ) ;
}
}
F_108 ( V_185 , V_191 ) ;
F_108 ( V_188 , V_191 ) ;
return V_112 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 V_15 = 0 ;
struct V_6 * V_7 = F_4 ( & V_2 -> V_3 -> V_9 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_16 = V_2 -> V_3 -> V_16 ;
return;
}
while ( ( V_7 = F_5 ( V_7 , V_2 -> V_4 ) ) != NULL ) {
V_15 ++ ;
V_7 = F_6 ( V_7 ) ;
}
V_2 -> V_16 = V_15 ;
}
static int F_118 ( struct V_169 * V_170 , int V_64 ,
const char * V_206 ,
bool V_207 ,
struct V_53 * V_54 ,
float V_4 ,
struct V_208 * V_209 )
{
struct V_3 * V_3 = F_105 ( V_170 ) ;
struct V_1 * V_5 = F_95 ( V_3 ) ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
char * V_185 [ 16 ] ;
int V_191 = 0 ;
int V_55 = - 1 ;
char V_115 [ 64 ] ;
char V_214 [ 64 ] ;
int V_57 = V_54 ? V_54 -> V_58 : 0 ;
struct V_132 * V_109 ;
#define F_119 \
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
const char V_215 [] = F_119
L_35
L_36
L_37
L_38
L_39
L_40
L_41 ;
const char V_216 [] = F_119
L_36
L_39
L_40
L_42
L_41 ;
if ( V_5 == NULL )
return - 1 ;
if ( V_4 ) {
V_5 -> V_4 = V_4 ;
F_17 ( V_5 ) ;
}
V_213 = F_120 ( 2 ) ;
if ( V_213 == NULL )
goto V_71;
F_121 ( V_206 ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
F_74 (fmt)
F_122 ( V_109 , V_3 ) ;
if ( V_133 . V_217 )
F_123 ( V_133 . V_217 ) ;
while ( 1 ) {
struct V_161 * V_161 = NULL ;
const struct V_163 * V_163 = NULL ;
int V_192 = 0 ,
V_218 = - 2 , V_219 = - 2 , V_220 = - 2 ,
V_221 = - 2 , V_222 = - 2 , V_223 = - 2 ;
int V_224 = - 2 , V_225 = - 2 ,
V_226 = - 2 , V_227 = - 2 ;
V_191 = 0 ;
V_55 = F_45 ( V_5 , V_54 ) ;
if ( V_5 -> V_52 != NULL ) {
V_161 = F_99 ( V_5 ) ;
V_163 = V_5 -> V_51 -> V_228 ? V_5 -> V_51 -> V_228 -> V_163 : NULL ;
}
switch ( V_55 ) {
case V_229 :
case V_230 :
if ( V_64 == 1 )
continue;
goto V_231;
case 'a' :
if ( ! V_232 ) {
F_44 ( & V_5 -> V_19 , V_57 * 2 ,
L_43
L_44 ) ;
continue;
}
if ( V_5 -> V_51 == NULL ||
V_5 -> V_51 -> V_78 == NULL ||
V_5 -> V_51 -> V_228 -> V_163 -> V_233 )
continue;
goto V_234;
case 'P' :
F_92 ( V_5 ) ;
continue;
case 'd' :
goto V_219;
case 'V' :
V_5 -> V_77 = ! V_5 -> V_77 ;
continue;
case 't' :
goto V_220;
case '/' :
if ( F_124 ( L_45 ,
L_46 ,
V_115 , L_47 ,
V_57 * 2 ) == V_70 ) {
V_3 -> V_235 = * V_115 ? V_115 : NULL ;
F_125 ( V_3 ) ;
F_16 ( V_5 ) ;
}
continue;
case 'r' :
if ( F_100 ( V_54 ) )
goto V_236;
continue;
case 's' :
if ( F_100 ( V_54 ) )
goto V_237;
continue;
case 'i' :
if ( V_209 -> V_238 )
F_126 ( V_209 ) ;
continue;
case 'F' :
V_133 . V_173 ^= 1 ;
continue;
case 'z' :
if ( ! F_100 ( V_54 ) ) {
struct V_183 * V_68 = V_54 -> V_61 ;
V_68 -> V_184 = ! V_68 -> V_184 ;
}
continue;
case V_239 :
case 'h' :
case '?' :
F_127 ( & V_5 -> V_19 ,
F_100 ( V_54 ) ? V_215 : V_216 ) ;
continue;
case V_70 :
case V_240 :
break;
case V_241 : {
const void * V_68 ;
if ( F_128 ( V_213 ) ) {
if ( V_207 )
goto V_231;
continue;
}
V_68 = F_129 ( V_213 ) ;
if ( V_68 == & V_5 -> V_3 -> V_164 )
goto V_242;
if ( V_68 == & V_5 -> V_3 -> V_165 )
goto V_243;
continue;
}
case V_244 :
if ( ! V_207 &&
! F_130 ( & V_5 -> V_19 ,
L_48 ) )
continue;
case 'q' :
case F_131 ( 'c' ) :
goto V_231;
default:
continue;
}
if ( ! V_232 )
goto V_245;
if ( V_5 -> V_51 == NULL )
goto V_246;
if ( V_247 == V_248 ) {
V_211 = V_5 -> V_52 -> V_210 ;
if ( V_211 == NULL )
goto V_246;
if ( V_211 -> V_249 . V_78 != NULL &&
! V_211 -> V_249 . V_228 -> V_163 -> V_233 &&
F_67 ( & V_185 [ V_191 ] , L_49 , V_211 -> V_249 . V_78 -> V_198 ) > 0 ) {
V_221 = V_191 ++ ;
}
if ( V_211 -> V_250 . V_78 != NULL &&
! V_211 -> V_250 . V_228 -> V_163 -> V_233 &&
( V_211 -> V_250 . V_78 != V_211 -> V_249 . V_78 ||
V_211 -> V_250 . V_228 -> V_163 != V_211 -> V_249 . V_228 -> V_163 ) &&
F_67 ( & V_185 [ V_191 ] , L_49 , V_211 -> V_250 . V_78 -> V_198 ) > 0 ) {
V_222 = V_191 ++ ;
}
} else {
if ( V_5 -> V_51 -> V_78 != NULL &&
! V_5 -> V_51 -> V_228 -> V_163 -> V_233 ) {
struct V_251 * V_252 ;
V_252 = F_55 ( V_5 -> V_51 -> V_78 ) ;
if ( V_252 -> V_79 &&
F_67 ( & V_185 [ V_191 ] , L_49 ,
V_5 -> V_51 -> V_78 -> V_198 ) > 0 ) {
V_218 = V_191 ++ ;
}
}
}
V_246:
if ( V_161 != NULL &&
F_67 ( & V_185 [ V_191 ] , L_50 ,
( V_5 -> V_3 -> V_165 ? L_51 : L_52 ) ,
( V_161 -> V_180 ? F_107 ( V_161 ) : L_16 ) ,
V_161 -> V_181 ) > 0 )
V_220 = V_191 ++ ;
if ( V_163 != NULL &&
F_67 ( & V_185 [ V_191 ] , L_53 ,
( V_5 -> V_3 -> V_164 ? L_51 : L_52 ) ,
( V_163 -> V_253 ? L_54 : V_163 -> V_182 ) ) > 0 )
V_219 = V_191 ++ ;
if ( V_5 -> V_51 != NULL &&
V_5 -> V_51 -> V_228 != NULL &&
F_67 ( & V_185 [ V_191 ] , L_55 ) > 0 )
V_223 = V_191 ++ ;
if ( V_5 -> V_52 ) {
struct V_254 * V_78 ;
if ( F_67 ( & V_185 [ V_191 ] , L_56 ,
F_107 ( V_5 -> V_52 -> V_161 ) ) > 0 )
V_224 = V_191 ++ ;
V_78 = V_5 -> V_52 -> V_12 . V_78 ;
if ( V_78 && V_78 -> V_255 &&
F_67 ( & V_185 [ V_191 ] , L_57 ,
V_78 -> V_198 ) > 0 )
V_225 = V_191 ++ ;
}
if ( F_67 ( & V_185 [ V_191 ] , L_58 ) > 0 )
V_226 = V_191 ++ ;
if ( F_100 ( V_54 ) && F_67 ( & V_185 [ V_191 ] ,
L_59 ) > 0 )
V_227 = V_191 ++ ;
V_245:
V_185 [ V_191 ++ ] = ( char * ) L_60 ;
V_256:
V_192 = F_117 ( V_191 , V_185 ) ;
if ( V_192 == V_191 - 1 )
break;
if ( V_192 == - 1 ) {
F_108 ( V_185 , V_191 - 1 ) ;
continue;
}
if ( V_192 == V_218 || V_192 == V_222 || V_192 == V_221 ) {
struct V_10 * V_11 ;
struct V_251 * V_252 ;
struct V_30 V_12 ;
int V_155 ;
V_234:
if ( ! V_257 && F_132 ( V_209 ) )
continue;
V_11 = F_98 ( V_5 ) ;
if ( V_11 == NULL )
continue;
if ( V_192 == V_221 ) {
V_12 . V_228 = V_11 -> V_210 -> V_249 . V_228 ;
V_12 . V_78 = V_11 -> V_210 -> V_249 . V_78 ;
} else if ( V_192 == V_222 ) {
V_12 . V_228 = V_11 -> V_210 -> V_250 . V_228 ;
V_12 . V_78 = V_11 -> V_210 -> V_250 . V_78 ;
} else {
V_12 = * V_5 -> V_51 ;
}
V_252 = F_55 ( V_12 . V_78 ) ;
if ( ! V_252 -> V_79 )
continue;
V_155 = F_133 ( & V_12 , V_170 , V_54 ) ;
if ( ( V_155 == 'q' || V_155 == F_131 ( 'c' ) )
&& V_222 != - 2 && V_221 != - 2 )
goto V_256;
F_49 ( & V_5 -> V_19 , V_5 -> V_3 -> V_15 ) ;
if ( V_155 )
F_134 ( & V_5 -> V_19 ) ;
} else if ( V_192 == V_223 )
F_135 ( V_5 -> V_51 -> V_228 ) ;
else if ( V_192 == V_219 ) {
V_219:
if ( V_5 -> V_3 -> V_164 ) {
F_136 ( V_213 , & V_5 -> V_3 -> V_164 ) ;
V_242:
F_51 () ;
V_5 -> V_3 -> V_164 = NULL ;
F_137 ( V_258 , false ) ;
} else {
if ( V_163 == NULL )
continue;
F_52 ( L_61 ,
V_163 -> V_253 ? L_54 : V_163 -> V_182 ) ;
V_5 -> V_3 -> V_164 = V_163 ;
F_137 ( V_258 , true ) ;
F_138 ( V_213 , & V_5 -> V_3 -> V_164 ) ;
}
F_139 ( V_3 ) ;
F_16 ( V_5 ) ;
} else if ( V_192 == V_220 ) {
V_220:
if ( V_5 -> V_3 -> V_165 ) {
F_136 ( V_213 , & V_5 -> V_3 -> V_165 ) ;
V_243:
F_51 () ;
F_140 ( V_5 -> V_3 -> V_165 ) ;
F_137 ( V_259 , false ) ;
} else {
F_52 ( L_62 ,
V_161 -> V_180 ? F_107 ( V_161 ) : L_16 ,
V_161 -> V_181 ) ;
V_5 -> V_3 -> V_165 = F_141 ( V_161 ) ;
F_137 ( V_259 , false ) ;
F_138 ( V_213 , & V_5 -> V_3 -> V_165 ) ;
}
F_142 ( V_3 ) ;
F_16 ( V_5 ) ;
}
else if ( V_192 == V_226 || V_192 == V_224 ||
V_192 == V_225 ) {
V_236:
memset ( V_214 , 0 , 64 ) ;
if ( V_192 == V_224 )
sprintf ( V_214 , L_63 , F_107 ( V_5 -> V_52 -> V_161 ) ) ;
if ( V_192 == V_225 )
sprintf ( V_214 , L_64 , V_5 -> V_52 -> V_12 . V_78 -> V_198 ) ;
F_143 ( V_214 ) ;
}
else if ( V_192 == V_227 ) {
V_237:
if ( ! F_110 () ) {
V_55 = V_260 ;
break;
} else
F_115 ( L_65
L_66 ) ;
}
}
V_231:
F_144 ( V_213 ) ;
V_71:
F_97 ( V_5 ) ;
F_108 ( V_185 , V_191 - 1 ) ;
return V_55 ;
}
static void F_145 ( struct V_18 * V_5 ,
void * V_130 , int V_28 )
{
struct V_261 * V_262 = F_11 ( V_5 ,
struct V_261 , V_19 ) ;
struct V_169 * V_170 = F_32 ( V_130 , struct V_169 , V_36 ) ;
struct V_3 * V_3 = F_105 ( V_170 ) ;
bool V_114 = F_56 ( V_5 , V_28 ) ;
unsigned long V_64 = V_3 -> V_62 . V_64 [ V_167 ] ;
const char * V_171 = F_101 ( V_170 ) ;
char V_97 [ 256 ] , V_162 ;
const char * V_263 = L_8 ;
T_8 V_85 ;
F_57 ( V_5 , V_114 ? V_81 :
V_80 ) ;
if ( F_102 ( V_170 ) ) {
struct V_169 * V_176 ;
V_171 = F_146 ( V_170 ) ;
F_104 (pos, evsel) {
struct V_3 * V_177 = F_105 ( V_176 ) ;
V_64 += V_177 -> V_62 . V_64 [ V_167 ] ;
}
}
V_64 = F_106 ( V_64 , & V_162 ) ;
V_85 = F_70 ( V_97 , sizeof( V_97 ) , L_67 , V_64 ,
V_162 , V_162 == ' ' ? L_16 : L_8 , V_171 ) ;
F_59 ( L_13 , V_97 ) ;
V_64 = V_3 -> V_62 . V_64 [ V_65 ] ;
if ( V_64 != 0 ) {
V_262 -> V_264 = true ;
if ( ! V_114 )
F_57 ( V_5 , V_265 ) ;
V_64 = F_106 ( V_64 , & V_162 ) ;
V_85 += F_70 ( V_97 , sizeof( V_97 ) , L_68 ,
V_64 , V_162 , V_162 == ' ' ? L_16 : L_8 ) ;
V_263 = V_97 ;
}
F_58 ( V_263 , V_5 -> V_27 - V_85 ) ;
if ( V_114 )
V_262 -> V_51 = V_170 ;
}
static int F_147 ( struct V_261 * V_262 ,
int V_64 , const char * V_266 ,
struct V_53 * V_54 )
{
struct V_267 * V_268 = V_262 -> V_19 . V_269 ;
struct V_169 * V_176 ;
const char * V_56 = L_69 ;
int V_57 = V_54 ? V_54 -> V_58 : 0 ;
int V_55 ;
if ( F_47 ( & V_262 -> V_19 , V_56 ,
L_70 ) < 0 )
return - 1 ;
while ( 1 ) {
V_55 = F_48 ( & V_262 -> V_19 , V_57 ) ;
switch ( V_55 ) {
case V_59 :
V_54 -> V_60 ( V_54 -> V_61 ) ;
if ( ! V_262 -> V_270 && V_262 -> V_264 ) {
F_43 ( & V_262 -> V_19 ) ;
V_262 -> V_270 = true ;
}
continue;
case V_240 :
case V_70 :
if ( ! V_262 -> V_51 )
continue;
V_176 = V_262 -> V_51 ;
V_271:
F_148 ( V_268 , V_176 ) ;
if ( V_54 )
V_54 -> V_60 ( V_54 -> V_61 ) ;
V_55 = F_118 ( V_176 , V_64 , V_266 ,
true , V_54 ,
V_262 -> V_4 ,
V_262 -> V_209 ) ;
F_50 ( & V_262 -> V_19 , V_56 ) ;
switch ( V_55 ) {
case V_229 :
if ( V_176 -> V_36 . V_44 == & V_268 -> V_9 )
V_176 = F_149 ( V_268 ) ;
else
V_176 = F_150 ( V_176 ) ;
goto V_271;
case V_230 :
if ( V_176 -> V_36 . V_47 == & V_268 -> V_9 )
V_176 = F_151 ( V_268 ) ;
else
V_176 = F_152 ( V_176 ) ;
goto V_271;
case V_244 :
if ( ! F_130 ( & V_262 -> V_19 ,
L_48 ) )
continue;
case V_260 :
case 'q' :
case F_131 ( 'c' ) :
goto V_71;
default:
continue;
}
case V_241 :
continue;
case V_244 :
if ( ! F_130 ( & V_262 -> V_19 ,
L_48 ) )
continue;
case 'q' :
case F_131 ( 'c' ) :
goto V_71;
default:
continue;
}
}
V_71:
F_53 ( & V_262 -> V_19 ) ;
return V_55 ;
}
static bool F_153 ( struct V_18 * V_5 V_84 ,
void * V_130 )
{
struct V_169 * V_170 = F_32 ( V_130 , struct V_169 , V_36 ) ;
if ( V_133 . V_272 && ! F_154 ( V_170 ) )
return true ;
return false ;
}
static int F_155 ( struct V_267 * V_268 ,
int V_15 , const char * V_266 ,
struct V_53 * V_54 ,
float V_4 ,
struct V_208 * V_209 )
{
struct V_169 * V_176 ;
struct V_261 V_262 = {
. V_19 = {
. V_9 = & V_268 -> V_9 ,
. V_58 = V_273 ,
. V_158 = V_274 ,
. V_275 = F_145 ,
. V_276 = F_153 ,
. V_15 = V_15 ,
. V_269 = V_268 ,
} ,
. V_4 = V_4 ,
. V_209 = V_209 ,
} ;
F_121 ( L_71 ) ;
F_156 (evlist, pos) {
const char * V_171 = F_101 ( V_176 ) ;
T_8 V_277 = strlen ( V_171 ) + 7 ;
if ( V_262 . V_19 . V_27 < V_277 )
V_262 . V_19 . V_27 = V_277 ;
}
return F_147 ( & V_262 , V_15 , V_266 , V_54 ) ;
}
int F_157 ( struct V_267 * V_268 , const char * V_266 ,
struct V_53 * V_54 ,
float V_4 ,
struct V_208 * V_209 )
{
int V_15 = V_268 -> V_15 ;
V_278:
if ( V_15 == 1 ) {
struct V_169 * V_42 = F_149 ( V_268 ) ;
return F_118 ( V_42 , V_15 , V_266 ,
false , V_54 , V_4 ,
V_209 ) ;
}
if ( V_133 . V_272 ) {
struct V_169 * V_176 ;
V_15 = 0 ;
F_156 (evlist, pos) {
if ( F_154 ( V_176 ) )
V_15 ++ ;
}
if ( V_15 == 1 )
goto V_278;
}
return F_155 ( V_268 , V_15 , V_266 ,
V_54 , V_4 , V_209 ) ;
}
