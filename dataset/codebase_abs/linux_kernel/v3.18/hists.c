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
if ( ! F_30 ( & V_31 -> V_42 ) ) {
V_37 = F_31 ( V_31 -> V_42 . V_43 , struct V_27 , V_40 ) ;
V_37 -> V_23 . V_24 = ! F_28 ( & V_31 -> V_35 ) ;
}
F_27 ( V_31 ) ;
}
static void F_32 ( struct V_35 * V_44 )
{
struct V_33 * V_34 ;
for ( V_34 = F_20 ( V_44 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_30 * V_31 = F_22 ( V_34 , struct V_30 , V_33 ) ;
F_29 ( V_31 ) ;
}
}
static void F_33 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_45 ) {
V_26 -> V_23 . V_24 = ! F_28 ( & V_26 -> V_46 ) ;
F_32 ( & V_26 -> V_46 ) ;
V_26 -> V_45 = true ;
}
}
static bool F_34 ( struct V_1 * V_9 )
{
if ( F_26 ( V_9 -> V_47 ) ) {
struct V_25 * V_26 = V_9 -> V_48 ;
F_33 ( V_26 ) ;
V_9 -> V_10 . V_5 -= V_26 -> V_49 ;
V_9 -> V_7 -= V_26 -> V_49 ;
if ( V_26 -> V_23 . V_21 )
V_26 -> V_49 = F_25 ( & V_26 -> V_46 ) ;
else
V_26 -> V_49 = 0 ;
V_9 -> V_10 . V_5 += V_26 -> V_49 ;
V_9 -> V_7 += V_26 -> V_49 ;
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
int V_32 = F_37 ( & V_26 -> V_46 , V_29 ) ;
V_26 -> V_49 = V_29 ? V_32 : 0 ;
} else
V_26 -> V_49 = 0 ;
}
static void
F_39 ( struct V_1 * V_9 , bool V_29 )
{
struct V_33 * V_34 ;
struct V_3 * V_3 = V_9 -> V_3 ;
for ( V_34 = F_20 ( & V_3 -> V_50 ) ;
( V_34 = F_40 ( V_34 , V_9 -> V_4 ) ) != NULL ;
V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_26 = F_22 ( V_34 , struct V_25 , V_33 ) ;
F_38 ( V_26 , V_29 ) ;
V_9 -> V_7 += V_26 -> V_49 ;
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
struct V_51 * V_52 )
{
int V_53 ;
char V_54 [ 160 ] ;
int V_55 = V_52 ? V_52 -> V_56 : 0 ;
V_9 -> V_10 . V_50 = & V_9 -> V_3 -> V_50 ;
V_9 -> V_10 . V_5 = F_3 ( V_9 ) ;
F_45 ( V_9 -> V_3 , V_52 , V_54 , sizeof( V_54 ) ) ;
if ( F_46 ( & V_9 -> V_10 , V_54 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_53 = F_47 ( & V_9 -> V_10 , V_55 ) ;
switch ( V_53 ) {
case V_57 : {
T_3 V_5 ;
V_52 -> V_58 ( V_52 -> V_59 ) ;
if ( F_1 ( V_9 ) )
F_12 ( V_9 ) ;
V_5 = F_3 ( V_9 ) ;
F_48 ( & V_9 -> V_10 , V_5 ) ;
if ( V_9 -> V_3 -> V_60 . V_61 !=
V_9 -> V_3 -> V_60 . V_62 [ V_63 ] ) {
V_9 -> V_3 -> V_60 . V_61 =
V_9 -> V_3 -> V_60 . V_62 [ V_63 ] ;
F_42 ( & V_9 -> V_10 ) ;
}
F_45 ( V_9 -> V_3 ,
V_52 , V_54 , sizeof( V_54 ) ) ;
F_49 ( & V_9 -> V_10 , V_54 ) ;
continue;
}
case 'D' : {
static int V_64 ;
struct V_25 * V_65 = F_22 ( V_9 -> V_10 . V_66 ,
struct V_25 , V_33 ) ;
F_50 () ;
F_51 ( L_7 ,
V_64 ++ , V_9 -> V_10 . V_5 ,
V_9 -> V_3 -> V_5 ,
V_9 -> V_10 . V_14 ,
V_9 -> V_10 . V_16 ,
V_9 -> V_10 . V_17 ,
V_65 -> V_67 , V_65 -> V_49 ) ;
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
case V_68 :
if ( F_34 ( V_9 ) )
break;
default:
goto V_69;
}
}
V_69:
F_52 ( & V_9 -> V_10 ) ;
return V_53 ;
}
static char * F_53 ( struct V_27 * V_28 ,
char * V_70 , T_4 V_71 , bool V_72 )
{
int V_73 ;
if ( V_28 -> V_23 . V_74 )
V_73 = F_54 ( V_70 , V_71 , L_8 , V_28 -> V_23 . V_74 -> V_75 ) ;
else
V_73 = F_54 ( V_70 , V_71 , L_9 V_76 , V_28 -> V_77 ) ;
if ( V_72 )
F_54 ( V_70 + V_73 , V_71 - V_73 , L_10 ,
V_28 -> V_23 . V_78 ? V_28 -> V_23 . V_78 -> V_79 -> V_80 : L_11 ) ;
return V_70 ;
}
static void F_55 ( struct V_1 * V_9 ,
struct V_27 * V_37 ,
const char * V_81 , int V_82 ,
unsigned short V_19 ,
struct V_83 * V_59 )
{
int V_84 , V_18 ;
char V_38 = F_17 ( V_37 ) ;
V_84 = V_85 ;
V_18 = V_9 -> V_10 . V_18 - ( V_82 + 2 ) ;
if ( F_56 ( & V_9 -> V_10 , V_19 ) ) {
V_9 -> V_47 = & V_37 -> V_23 ;
V_84 = V_86 ;
V_59 -> V_87 = true ;
}
F_57 ( & V_9 -> V_10 , V_84 ) ;
F_9 ( V_9 , V_19 , 0 ) ;
F_58 ( L_12 , V_82 ) ;
F_59 ( L_13 , V_38 ) ;
F_58 ( V_81 , V_18 ) ;
}
static void F_60 ( struct V_1 * V_10 V_88 ,
struct V_27 * V_37 ,
const char * V_81 , int V_82 ,
unsigned short V_19 V_88 ,
struct V_83 * V_59 )
{
char V_38 = F_17 ( V_37 ) ;
V_59 -> V_73 += fprintf ( V_59 -> V_89 , L_14 , V_82 , L_12 ,
V_38 , V_81 ) ;
}
static bool F_61 ( struct V_1 * V_9 ,
unsigned short V_19 )
{
return V_9 -> V_10 . V_14 == V_19 ;
}
static bool F_62 ( struct V_1 * V_9 V_88 ,
unsigned short V_19 V_88 )
{
return false ;
}
static int F_63 ( struct V_1 * V_9 ,
struct V_35 * V_44 , int V_90 ,
unsigned short V_19 , T_3 V_91 ,
T_5 V_92 ,
struct V_83 * V_59 ,
T_6 V_93 )
{
struct V_33 * V_31 ;
int V_94 = V_19 , V_82 = V_90 * V_95 ;
T_3 V_96 ;
V_31 = F_20 ( V_44 ) ;
while ( V_31 ) {
struct V_30 * V_36 = F_22 ( V_31 , struct V_30 , V_33 ) ;
struct V_33 * V_41 = F_21 ( V_31 ) ;
T_3 V_97 = F_64 ( V_36 ) ;
struct V_27 * V_37 ;
char V_38 = ' ' ;
int V_39 = true ;
int V_98 = 0 ;
F_23 (chain, &child->val, list) {
char V_70 [ 1024 ] , * V_99 ;
const char * V_81 ;
bool V_100 = V_39 ;
if ( V_39 )
V_39 = false ;
else if ( V_90 > 1 )
V_98 = V_95 ;
V_38 = F_17 ( V_37 ) ;
if ( V_59 -> V_67 != 0 ) {
V_59 -> V_67 -- ;
goto V_101;
}
V_99 = NULL ;
V_81 = F_53 ( V_37 , V_70 , sizeof( V_70 ) ,
V_9 -> V_72 ) ;
if ( V_100 && V_90 > 1 ) {
double V_102 = V_97 * 100.0 / V_91 ;
if ( F_65 ( & V_99 , L_15 , V_102 , V_81 ) < 0 )
V_81 = L_16 ;
else
V_81 = V_99 ;
}
V_92 ( V_9 , V_37 , V_81 , V_82 + V_98 , V_19 , V_59 ) ;
free ( V_99 ) ;
if ( V_93 ( V_9 , ++ V_19 ) )
goto V_69;
V_101:
if ( V_38 == '+' )
break;
}
if ( V_38 == '-' ) {
const int V_103 = V_90 + ( V_98 ? 2 : 1 ) ;
if ( V_104 . V_105 == V_106 )
V_96 = V_36 -> V_107 ;
else
V_96 = V_91 ;
V_19 += F_63 ( V_9 , & V_36 -> V_35 ,
V_103 , V_19 , V_96 ,
V_92 , V_59 , V_93 ) ;
}
if ( V_93 ( V_9 , V_19 ) )
break;
V_31 = V_41 ;
}
V_69:
return V_19 - V_94 ;
}
static int F_66 ( struct V_108 * V_109 , const char * V_110 , ... )
{
struct V_111 * V_59 = V_109 -> V_112 ;
int V_113 , V_114 ;
T_7 args ;
double V_102 ;
va_start ( args , V_110 ) ;
V_114 = va_arg ( args , int ) ;
V_102 = va_arg ( args , double ) ;
va_end ( args ) ;
F_67 ( V_59 -> V_10 , V_102 , V_59 -> V_115 ) ;
V_113 = F_54 ( V_109 -> V_116 , V_109 -> V_117 , V_110 , V_114 , V_102 ) ;
F_59 ( L_8 , V_109 -> V_116 ) ;
F_68 ( V_109 , V_113 ) ;
return V_113 ;
}
void F_69 ( void )
{
V_118 [ V_119 ] . V_84 =
V_120 ;
V_118 [ V_121 ] . V_84 =
V_122 ;
V_118 [ V_123 ] . V_84 =
V_124 ;
V_118 [ V_125 ] . V_84 =
V_126 ;
V_118 [ V_127 ] . V_84 =
V_128 ;
V_118 [ V_129 ] . V_84 =
V_130 ;
}
static int F_70 ( struct V_1 * V_9 ,
struct V_25 * V_131 ,
unsigned short V_19 )
{
char V_132 [ 256 ] ;
int V_73 = 0 ;
int V_18 = V_9 -> V_10 . V_18 ;
char V_38 = ' ' ;
bool V_115 = F_56 ( & V_9 -> V_10 , V_19 ) ;
T_8 V_67 = V_131 -> V_67 ;
bool V_39 = true ;
struct V_133 * V_110 ;
if ( V_115 ) {
V_9 -> V_48 = V_131 ;
V_9 -> V_47 = & V_131 -> V_23 ;
}
if ( V_134 . V_135 ) {
F_33 ( V_131 ) ;
V_38 = F_16 ( V_131 ) ;
}
if ( V_67 == 0 ) {
struct V_111 V_59 = {
. V_10 = & V_9 -> V_10 ,
. V_38 = V_38 ,
. V_115 = V_115 ,
} ;
struct V_108 V_109 = {
. V_116 = V_132 ,
. V_117 = sizeof( V_132 ) ,
. V_112 = & V_59 ,
} ;
F_9 ( V_9 , V_19 , 0 ) ;
F_71 (fmt) {
if ( F_72 ( V_110 ) )
continue;
if ( V_115 && V_9 -> V_10 . V_136 ) {
F_57 ( & V_9 -> V_10 ,
V_86 ) ;
} else {
F_57 ( & V_9 -> V_10 ,
V_85 ) ;
}
if ( V_39 ) {
if ( V_134 . V_135 ) {
F_59 ( L_13 , V_38 ) ;
V_18 -= 2 ;
}
V_39 = false ;
} else {
F_59 ( L_17 ) ;
V_18 -= 2 ;
}
if ( V_110 -> V_84 ) {
V_18 -= V_110 -> V_84 ( V_110 , & V_109 , V_131 ) ;
} else {
V_18 -= V_110 -> V_131 ( V_110 , & V_109 , V_131 ) ;
F_59 ( L_8 , V_132 ) ;
}
}
if ( ! V_9 -> V_10 . V_136 )
V_18 += 1 ;
F_58 ( L_18 , V_18 ) ;
++ V_19 ;
++ V_73 ;
} else
-- V_67 ;
if ( V_38 == '-' && V_19 != V_9 -> V_10 . V_14 ) {
T_3 V_91 = F_73 ( V_131 -> V_3 ) ;
struct V_83 V_59 = {
. V_67 = V_67 ,
. V_87 = V_115 ,
} ;
V_73 += F_63 ( V_9 ,
& V_131 -> V_46 , 1 , V_19 , V_91 ,
F_55 , & V_59 ,
F_61 ) ;
if ( V_59 . V_87 )
V_9 -> V_48 = V_131 ;
}
return V_73 ;
}
static int F_74 ( struct V_108 * V_109 , int V_137 )
{
F_68 ( V_109 , V_137 ) ;
return V_109 -> V_117 <= 0 ;
}
static int F_75 ( char * V_116 , T_4 V_117 , struct V_3 * V_3 )
{
struct V_108 V_138 = {
. V_116 = V_116 ,
. V_117 = V_117 ,
} ;
struct V_133 * V_110 ;
T_4 V_113 = 0 ;
if ( V_134 . V_135 ) {
V_113 = F_54 ( V_116 , V_117 , L_17 ) ;
if ( F_74 ( & V_138 , V_113 ) )
return V_113 ;
}
F_71 (fmt) {
if ( F_72 ( V_110 ) )
continue;
V_113 = V_110 -> V_139 ( V_110 , & V_138 , F_76 ( V_3 ) ) ;
if ( F_74 ( & V_138 , V_113 ) )
break;
V_113 = F_54 ( V_138 . V_116 , V_138 . V_117 , L_17 ) ;
if ( F_74 ( & V_138 , V_113 ) )
break;
}
return V_113 ;
}
static void F_77 ( struct V_1 * V_9 )
{
char V_140 [ 1024 ] ;
F_75 ( V_140 , sizeof( V_140 ) , V_9 -> V_3 ) ;
F_10 ( & V_9 -> V_10 , 0 , 0 ) ;
F_57 ( & V_9 -> V_10 , V_141 ) ;
F_58 ( V_140 , V_9 -> V_10 . V_18 + 1 ) ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( V_9 -> V_66 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
V_9 -> V_66 = F_20 ( & V_2 -> V_3 -> V_50 ) ;
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
for ( V_34 = V_9 -> V_66 ; V_34 ; V_34 = F_21 ( V_34 ) ) {
struct V_25 * V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_102 ;
if ( V_65 -> V_142 )
continue;
V_102 = F_80 ( V_65 ) ;
if ( V_102 < V_2 -> V_4 )
continue;
V_19 += F_70 ( V_2 , V_65 , V_19 ) ;
if ( V_19 == V_9 -> V_14 )
break;
}
return V_19 + V_11 ;
}
static struct V_33 * F_40 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_102 = F_80 ( V_65 ) ;
if ( ! V_65 -> V_142 && V_102 >= V_4 )
return V_34 ;
V_34 = F_21 ( V_34 ) ;
}
return NULL ;
}
static struct V_33 * F_81 ( struct V_33 * V_34 ,
float V_4 )
{
while ( V_34 != NULL ) {
struct V_25 * V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
float V_102 = F_80 ( V_65 ) ;
if ( ! V_65 -> V_142 && V_102 >= V_4 )
return V_34 ;
V_34 = F_82 ( V_34 ) ;
}
return NULL ;
}
static void F_83 ( struct V_8 * V_9 ,
T_8 V_82 , int V_143 )
{
struct V_25 * V_65 ;
struct V_33 * V_34 ;
bool V_39 = true ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , struct V_1 , V_10 ) ;
if ( V_9 -> V_5 == 0 )
return;
F_78 ( V_9 ) ;
switch ( V_143 ) {
case V_144 :
V_34 = F_40 ( F_20 ( V_9 -> V_50 ) ,
V_2 -> V_4 ) ;
break;
case V_145 :
V_34 = V_9 -> V_66 ;
goto V_146;
case V_147 :
V_34 = F_81 ( F_84 ( V_9 -> V_50 ) ,
V_2 -> V_4 ) ;
V_39 = false ;
break;
default:
return;
}
V_65 = F_22 ( V_9 -> V_66 , struct V_25 , V_33 ) ;
V_65 -> V_67 = 0 ;
V_146:
if ( V_82 > 0 ) {
do {
V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_65 -> V_23 . V_21 ) {
T_2 V_148 = V_65 -> V_49 - V_65 -> V_67 ;
if ( V_82 > V_148 ) {
V_82 -= V_148 ;
V_65 -> V_67 = 0 ;
} else {
V_65 -> V_67 += V_82 ;
V_82 = 0 ;
V_9 -> V_66 = V_34 ;
break;
}
}
V_34 = F_40 ( F_21 ( V_34 ) , V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
-- V_82 ;
V_9 -> V_66 = V_34 ;
} while ( V_82 != 0 );
} else if ( V_82 < 0 ) {
while ( 1 ) {
V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_65 -> V_23 . V_21 ) {
if ( V_39 ) {
if ( - V_82 > V_65 -> V_67 ) {
V_82 += V_65 -> V_67 ;
V_65 -> V_67 = 0 ;
} else {
V_65 -> V_67 += V_82 ;
V_82 = 0 ;
V_9 -> V_66 = V_34 ;
break;
}
} else {
if ( - V_82 > V_65 -> V_49 ) {
V_82 += V_65 -> V_49 ;
V_65 -> V_67 = 0 ;
} else {
V_65 -> V_67 = V_65 -> V_49 + V_82 ;
V_82 = 0 ;
V_9 -> V_66 = V_34 ;
break;
}
}
}
V_34 = F_81 ( F_82 ( V_34 ) ,
V_2 -> V_4 ) ;
if ( V_34 == NULL )
break;
++ V_82 ;
V_9 -> V_66 = V_34 ;
if ( V_82 == 0 ) {
V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
if ( V_65 -> V_23 . V_21 )
V_65 -> V_67 = V_65 -> V_49 ;
break;
}
V_39 = false ;
}
} else {
V_9 -> V_66 = V_34 ;
V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_65 -> V_67 = 0 ;
}
}
static int F_85 ( struct V_1 * V_9 ,
struct V_25 * V_26 , T_9 * V_89 )
{
T_3 V_91 = F_73 ( V_26 -> V_3 ) ;
struct V_83 V_59 = {
. V_89 = V_89 ,
} ;
if ( V_134 . V_149 )
V_91 = V_26 -> V_150 -> V_151 ;
F_63 ( V_9 , & V_26 -> V_46 , 1 , 0 , V_91 ,
F_60 , & V_59 ,
F_62 ) ;
return V_59 . V_73 ;
}
static int F_86 ( struct V_1 * V_9 ,
struct V_25 * V_26 , T_9 * V_89 )
{
char V_132 [ 8192 ] ;
int V_73 = 0 ;
char V_38 = ' ' ;
struct V_108 V_109 = {
. V_116 = V_132 ,
. V_117 = sizeof( V_132 ) ,
} ;
struct V_133 * V_110 ;
bool V_39 = true ;
int V_113 ;
if ( V_134 . V_135 )
V_38 = F_16 ( V_26 ) ;
if ( V_134 . V_135 )
V_73 += fprintf ( V_89 , L_13 , V_38 ) ;
F_71 (fmt) {
if ( F_72 ( V_110 ) )
continue;
if ( ! V_39 ) {
V_113 = F_54 ( V_109 . V_116 , V_109 . V_117 , L_17 ) ;
F_68 ( & V_109 , V_113 ) ;
} else
V_39 = false ;
V_113 = V_110 -> V_131 ( V_110 , & V_109 , V_26 ) ;
F_68 ( & V_109 , V_113 ) ;
}
V_73 += fprintf ( V_89 , L_19 , F_87 ( V_132 ) ) ;
if ( V_38 == '-' )
V_73 += F_85 ( V_9 , V_26 , V_89 ) ;
return V_73 ;
}
static int F_88 ( struct V_1 * V_9 , T_9 * V_89 )
{
struct V_33 * V_34 = F_40 ( F_20 ( V_9 -> V_10 . V_50 ) ,
V_9 -> V_4 ) ;
int V_73 = 0 ;
while ( V_34 ) {
struct V_25 * V_65 = F_22 ( V_34 , struct V_25 , V_33 ) ;
V_73 += F_86 ( V_9 , V_65 , V_89 ) ;
V_34 = F_40 ( F_21 ( V_34 ) , V_9 -> V_4 ) ;
}
return V_73 ;
}
static int F_89 ( struct V_1 * V_9 )
{
char V_152 [ 64 ] ;
T_9 * V_89 ;
while ( 1 ) {
F_54 ( V_152 , sizeof( V_152 ) , L_20 , V_9 -> V_153 ) ;
if ( F_90 ( V_152 , V_154 ) )
break;
if ( ++ V_9 -> V_153 == 8192 ) {
F_51 ( L_21 ) ;
return - 1 ;
}
}
V_89 = fopen ( V_152 , L_22 ) ;
if ( V_89 == NULL ) {
char V_70 [ 64 ] ;
const char * V_155 = F_91 ( V_156 , V_70 , sizeof( V_70 ) ) ;
F_51 ( L_23 , V_152 , V_155 ) ;
return - 1 ;
}
++ V_9 -> V_153 ;
F_88 ( V_9 , V_89 ) ;
fclose ( V_89 ) ;
F_51 ( L_24 , V_152 ) ;
return 0 ;
}
static struct V_1 * F_92 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_93 ( sizeof( * V_9 ) ) ;
if ( V_9 ) {
V_9 -> V_3 = V_3 ;
V_9 -> V_10 . V_56 = F_79 ;
V_9 -> V_10 . V_157 = F_5 ;
V_9 -> V_10 . V_158 = F_83 ;
V_9 -> V_10 . V_159 = true ;
V_9 -> V_12 = V_134 . V_160 ;
}
return V_9 ;
}
static void F_94 ( struct V_1 * V_9 )
{
free ( V_9 ) ;
}
static struct V_25 * F_95 ( struct V_1 * V_9 )
{
return V_9 -> V_48 ;
}
static struct V_161 * F_96 ( struct V_1 * V_9 )
{
return V_9 -> V_48 -> V_161 ;
}
static inline bool F_97 ( void * V_58 )
{
return V_58 == NULL ;
}
static int F_45 ( struct V_3 * V_3 ,
struct V_51 * V_52 ,
char * V_70 , T_4 V_117 )
{
char V_162 ;
int V_73 ;
const struct V_79 * V_79 = V_3 -> V_163 ;
const struct V_161 * V_161 = V_3 -> V_164 ;
unsigned long V_165 = V_3 -> V_60 . V_62 [ V_166 ] ;
T_3 V_62 = V_3 -> V_60 . V_167 ;
struct V_168 * V_169 = F_76 ( V_3 ) ;
const char * V_170 = F_98 ( V_169 ) ;
char V_116 [ 512 ] ;
T_4 V_171 = sizeof( V_116 ) ;
if ( V_134 . V_172 ) {
V_165 = V_3 -> V_60 . V_173 ;
V_62 = V_3 -> V_60 . V_174 ;
}
if ( F_99 ( V_169 ) ) {
struct V_168 * V_175 ;
F_100 ( V_169 , V_116 , V_171 ) ;
V_170 = V_116 ;
F_101 (pos, evsel) {
struct V_3 * V_176 = F_102 ( V_175 ) ;
if ( V_134 . V_172 ) {
V_165 += V_176 -> V_60 . V_173 ;
V_62 += V_176 -> V_60 . V_174 ;
} else {
V_165 += V_176 -> V_60 . V_62 [ V_166 ] ;
V_62 += V_176 -> V_60 . V_167 ;
}
}
}
V_165 = F_103 ( V_165 , & V_162 ) ;
V_73 = F_54 ( V_70 , V_117 ,
L_25 ,
V_165 , V_162 , V_170 , V_62 ) ;
if ( V_3 -> V_177 )
V_73 += snprintf ( V_70 + V_73 , V_117 - V_73 ,
L_26 , V_3 -> V_177 ) ;
if ( V_161 )
V_73 += F_54 ( V_70 + V_73 , V_117 - V_73 ,
L_27 ,
( V_161 -> V_178 ? F_104 ( V_161 ) : L_18 ) ,
V_161 -> V_179 ) ;
if ( V_79 )
V_73 += F_54 ( V_70 + V_73 , V_117 - V_73 ,
L_28 , V_79 -> V_80 ) ;
if ( ! F_97 ( V_52 ) ) {
struct V_180 * V_66 = V_52 -> V_59 ;
if ( V_66 -> V_181 )
V_73 += F_54 ( V_70 + V_73 , V_117 - V_73 , L_29 ) ;
}
return V_73 ;
}
static inline void F_105 ( char * * V_182 , int V_32 )
{
int V_183 ;
for ( V_183 = 0 ; V_183 < V_32 ; ++ V_183 )
F_106 ( & V_182 [ V_183 ] ) ;
}
static int F_107 ( void )
{
char * V_184 , * V_182 [ 32 ] , * V_185 [ 32 ] , * V_186 ;
T_10 * V_187 ;
int V_188 = 0 , V_189 = - 1 , V_113 = - 1 ;
struct V_190 * V_191 ;
V_184 = getenv ( L_30 ) ;
if ( ! V_184 )
return V_113 ;
V_187 = F_108 ( V_184 ) ;
if ( ! V_187 )
return V_113 ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_182 , 0 , sizeof( V_185 ) ) ;
while ( ( V_191 = F_109 ( V_187 ) ) ) {
char V_192 [ V_193 ] ;
T_3 V_194 ;
char * V_75 = V_191 -> V_195 ;
T_9 * V_196 ;
if ( ! ( V_191 -> V_197 == V_198 ) )
continue;
snprintf ( V_192 , sizeof( V_192 ) , L_31 , V_184 , V_75 ) ;
V_196 = fopen ( V_192 , L_32 ) ;
if ( ! V_196 )
continue;
if ( fread ( & V_194 , 1 , 8 , V_196 ) < 8 )
goto V_199;
if ( F_110 ( V_194 ) ) {
V_182 [ V_188 ] = F_111 ( V_75 ) ;
if ( ! V_182 [ V_188 ] )
goto V_199;
V_185 [ V_188 ] = F_111 ( V_192 ) ;
if ( ! V_185 [ V_188 ] ) {
F_106 ( & V_182 [ V_188 ] ) ;
F_112 ( L_33 ) ;
fclose ( V_196 ) ;
break;
}
V_188 ++ ;
}
V_199:
fclose ( V_196 ) ;
if ( V_188 >= 32 ) {
F_112 ( L_34
L_35 ) ;
break;
}
}
F_113 ( V_187 ) ;
if ( V_188 ) {
V_189 = F_114 ( V_188 , V_182 ) ;
if ( V_189 < V_188 && V_189 >= 0 ) {
V_186 = F_111 ( V_185 [ V_189 ] ) ;
if ( V_186 ) {
if ( V_200 )
free ( ( void * ) V_201 ) ;
V_201 = V_186 ;
V_200 = true ;
V_113 = 0 ;
} else
F_112 ( L_36 ) ;
}
}
F_105 ( V_182 , V_188 ) ;
F_105 ( V_185 , V_188 ) ;
return V_113 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_3 V_5 = 0 ;
struct V_33 * V_34 = F_20 ( & V_2 -> V_3 -> V_50 ) ;
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
static int F_115 ( struct V_168 * V_169 , int V_62 ,
const char * V_202 ,
bool V_203 ,
struct V_51 * V_52 ,
float V_4 ,
struct V_204 * V_205 )
{
struct V_3 * V_3 = F_102 ( V_169 ) ;
struct V_1 * V_9 = F_92 ( V_3 ) ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
char * V_182 [ 16 ] ;
int V_188 = 0 ;
int V_53 = - 1 ;
char V_116 [ 64 ] ;
char V_210 [ 64 ] ;
int V_55 = V_52 ? V_52 -> V_56 : 0 ;
struct V_133 * V_110 ;
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
const char V_211 [] = F_116
L_37
L_38
L_39
L_40
L_41
L_42
L_43 ;
const char V_212 [] = F_116
L_38
L_41
L_42
L_44
L_43 ;
if ( V_9 == NULL )
return - 1 ;
if ( V_4 ) {
V_9 -> V_4 = V_4 ;
F_12 ( V_9 ) ;
}
V_209 = F_117 ( 2 ) ;
if ( V_209 == NULL )
goto V_69;
F_118 ( V_202 ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
F_71 (fmt)
F_119 ( V_110 , V_3 ) ;
if ( V_134 . V_213 )
F_120 ( V_134 . V_213 ) ;
while ( 1 ) {
const struct V_161 * V_161 = NULL ;
const struct V_79 * V_79 = NULL ;
int V_189 = 0 ,
V_214 = - 2 , V_215 = - 2 , V_216 = - 2 ,
V_217 = - 2 , V_218 = - 2 , V_219 = - 2 ;
int V_220 = - 2 , V_221 = - 2 ,
V_222 = - 2 , V_223 = - 2 ;
V_188 = 0 ;
V_53 = F_44 ( V_9 , V_52 ) ;
if ( V_9 -> V_48 != NULL ) {
V_161 = F_96 ( V_9 ) ;
V_79 = V_9 -> V_47 -> V_78 ? V_9 -> V_47 -> V_78 -> V_79 : NULL ;
}
switch ( V_53 ) {
case V_224 :
case V_225 :
if ( V_62 == 1 )
continue;
goto V_226;
case 'a' :
if ( ! V_227 ) {
F_43 ( & V_9 -> V_10 , V_55 * 2 ,
L_45
L_46 ) ;
continue;
}
if ( V_9 -> V_47 == NULL ||
V_9 -> V_47 -> V_74 == NULL ||
V_9 -> V_47 -> V_78 -> V_79 -> V_228 )
continue;
goto V_229;
case 'P' :
F_89 ( V_9 ) ;
continue;
case 'd' :
goto V_215;
case 'V' :
V_9 -> V_72 = ! V_9 -> V_72 ;
continue;
case 't' :
goto V_216;
case '/' :
if ( F_121 ( L_47 ,
L_48 ,
V_116 , L_49 ,
V_55 * 2 ) == V_68 ) {
V_3 -> V_230 = * V_116 ? V_116 : NULL ;
F_122 ( V_3 ) ;
F_11 ( V_9 ) ;
}
continue;
case 'r' :
if ( F_97 ( V_52 ) )
goto V_231;
continue;
case 's' :
if ( F_97 ( V_52 ) )
goto V_232;
continue;
case 'i' :
if ( V_205 -> V_233 )
F_123 ( V_205 ) ;
continue;
case 'F' :
V_134 . V_172 ^= 1 ;
continue;
case 'z' :
if ( ! F_97 ( V_52 ) ) {
struct V_180 * V_66 = V_52 -> V_59 ;
V_66 -> V_181 = ! V_66 -> V_181 ;
}
continue;
case V_234 :
case 'h' :
case '?' :
F_124 ( & V_9 -> V_10 ,
F_97 ( V_52 ) ? V_211 : V_212 ) ;
continue;
case V_68 :
case V_235 :
break;
case V_236 : {
const void * V_66 ;
if ( F_125 ( V_209 ) ) {
if ( V_203 )
goto V_226;
continue;
}
V_66 = F_126 ( V_209 ) ;
if ( V_66 == & V_9 -> V_3 -> V_163 )
goto V_237;
if ( V_66 == & V_9 -> V_3 -> V_164 )
goto V_238;
continue;
}
case V_239 :
if ( ! V_203 &&
! F_127 ( & V_9 -> V_10 ,
L_50 ) )
continue;
case 'q' :
case F_128 ( 'c' ) :
goto V_226;
default:
continue;
}
if ( ! V_227 )
goto V_240;
if ( V_241 == V_242 ) {
V_207 = V_9 -> V_48 -> V_206 ;
if ( V_9 -> V_47 != NULL &&
V_207 &&
V_207 -> V_243 . V_74 != NULL &&
! V_207 -> V_243 . V_78 -> V_79 -> V_228 &&
F_65 ( & V_182 [ V_188 ] , L_51 ,
V_207 -> V_243 . V_74 -> V_75 ) > 0 )
V_217 = V_188 ++ ;
if ( V_9 -> V_47 != NULL &&
V_207 &&
V_207 -> V_244 . V_74 != NULL &&
! V_207 -> V_244 . V_78 -> V_79 -> V_228 &&
( V_207 -> V_244 . V_74 != V_207 -> V_243 . V_74 ||
V_207 -> V_244 . V_78 -> V_79 != V_207 -> V_243 . V_78 -> V_79 ) &&
F_65 ( & V_182 [ V_188 ] , L_51 ,
V_207 -> V_244 . V_74 -> V_75 ) > 0 )
V_218 = V_188 ++ ;
} else {
if ( V_9 -> V_47 != NULL &&
V_9 -> V_47 -> V_74 != NULL &&
! V_9 -> V_47 -> V_78 -> V_79 -> V_228 ) {
struct V_245 * V_246 ;
V_246 = F_129 ( V_9 -> V_47 -> V_74 ) ;
if ( V_246 -> V_247 &&
F_65 ( & V_182 [ V_188 ] , L_51 ,
V_9 -> V_47 -> V_74 -> V_75 ) > 0 )
V_214 = V_188 ++ ;
}
}
if ( V_161 != NULL &&
F_65 ( & V_182 [ V_188 ] , L_52 ,
( V_9 -> V_3 -> V_164 ? L_53 : L_54 ) ,
( V_161 -> V_178 ? F_104 ( V_161 ) : L_18 ) ,
V_161 -> V_179 ) > 0 )
V_216 = V_188 ++ ;
if ( V_79 != NULL &&
F_65 ( & V_182 [ V_188 ] , L_55 ,
( V_9 -> V_3 -> V_163 ? L_53 : L_54 ) ,
( V_79 -> V_248 ? L_56 : V_79 -> V_80 ) ) > 0 )
V_215 = V_188 ++ ;
if ( V_9 -> V_47 != NULL &&
V_9 -> V_47 -> V_78 != NULL &&
F_65 ( & V_182 [ V_188 ] , L_57 ) > 0 )
V_219 = V_188 ++ ;
if ( V_9 -> V_48 ) {
struct V_249 * V_74 ;
if ( F_65 ( & V_182 [ V_188 ] , L_58 ,
F_104 ( V_9 -> V_48 -> V_161 ) ) > 0 )
V_220 = V_188 ++ ;
V_74 = V_9 -> V_48 -> V_23 . V_74 ;
if ( V_74 && V_74 -> V_250 &&
F_65 ( & V_182 [ V_188 ] , L_59 ,
V_74 -> V_75 ) > 0 )
V_221 = V_188 ++ ;
}
if ( F_65 ( & V_182 [ V_188 ] , L_60 ) > 0 )
V_222 = V_188 ++ ;
if ( F_97 ( V_52 ) && F_65 ( & V_182 [ V_188 ] ,
L_61 ) > 0 )
V_223 = V_188 ++ ;
V_240:
V_182 [ V_188 ++ ] = ( char * ) L_62 ;
V_251:
V_189 = F_114 ( V_188 , V_182 ) ;
if ( V_189 == V_188 - 1 )
break;
if ( V_189 == - 1 ) {
F_105 ( V_182 , V_188 - 1 ) ;
continue;
}
if ( V_189 == V_214 || V_189 == V_218 || V_189 == V_217 ) {
struct V_25 * V_26 ;
struct V_245 * V_246 ;
int V_155 ;
V_229:
if ( ! V_252 && F_130 ( V_205 ) )
continue;
V_26 = F_95 ( V_9 ) ;
if ( V_26 == NULL )
continue;
if ( V_189 == V_217 ) {
V_26 -> V_23 . V_74 = V_26 -> V_206 -> V_243 . V_74 ;
V_26 -> V_23 . V_78 = V_26 -> V_206 -> V_243 . V_78 ;
} else if ( V_189 == V_218 ) {
V_26 -> V_23 . V_74 = V_26 -> V_206 -> V_244 . V_74 ;
V_26 -> V_23 . V_78 = V_26 -> V_206 -> V_244 . V_78 ;
}
V_246 = F_129 ( V_26 -> V_23 . V_74 ) ;
if ( ! V_246 -> V_247 )
continue;
V_26 -> V_253 = true ;
V_155 = F_131 ( V_26 , V_169 , V_52 ) ;
V_26 -> V_253 = false ;
if ( ( V_155 == 'q' || V_155 == F_128 ( 'c' ) )
&& V_218 != - 2 && V_217 != - 2 )
goto V_251;
F_48 ( & V_9 -> V_10 , V_9 -> V_3 -> V_5 ) ;
if ( V_155 )
F_132 ( & V_9 -> V_10 ) ;
} else if ( V_189 == V_219 )
F_133 ( V_9 -> V_47 -> V_78 ) ;
else if ( V_189 == V_215 ) {
V_215:
if ( V_9 -> V_3 -> V_163 ) {
F_134 ( V_209 , & V_9 -> V_3 -> V_163 ) ;
V_237:
F_50 () ;
V_9 -> V_3 -> V_163 = NULL ;
F_135 ( V_254 , false ) ;
} else {
if ( V_79 == NULL )
continue;
F_51 ( L_63 ,
V_79 -> V_248 ? L_56 : V_79 -> V_80 ) ;
V_9 -> V_3 -> V_163 = V_79 ;
F_135 ( V_254 , true ) ;
F_136 ( V_209 , & V_9 -> V_3 -> V_163 ) ;
}
F_137 ( V_3 ) ;
F_11 ( V_9 ) ;
} else if ( V_189 == V_216 ) {
V_216:
if ( V_9 -> V_3 -> V_164 ) {
F_134 ( V_209 , & V_9 -> V_3 -> V_164 ) ;
V_238:
F_50 () ;
V_9 -> V_3 -> V_164 = NULL ;
F_135 ( V_255 , false ) ;
} else {
F_51 ( L_64 ,
V_161 -> V_178 ? F_104 ( V_161 ) : L_18 ,
V_161 -> V_179 ) ;
V_9 -> V_3 -> V_164 = V_161 ;
F_135 ( V_255 , false ) ;
F_136 ( V_209 , & V_9 -> V_3 -> V_164 ) ;
}
F_138 ( V_3 ) ;
F_11 ( V_9 ) ;
}
else if ( V_189 == V_222 || V_189 == V_220 ||
V_189 == V_221 ) {
V_231:
memset ( V_210 , 0 , 64 ) ;
if ( V_189 == V_220 )
sprintf ( V_210 , L_65 , F_104 ( V_9 -> V_48 -> V_161 ) ) ;
if ( V_189 == V_221 )
sprintf ( V_210 , L_66 , V_9 -> V_48 -> V_23 . V_74 -> V_75 ) ;
F_139 ( V_210 ) ;
}
else if ( V_189 == V_223 ) {
V_232:
if ( ! F_107 () ) {
V_53 = V_256 ;
break;
} else
F_112 ( L_67
L_68 ) ;
}
}
V_226:
F_140 ( V_209 ) ;
V_69:
F_94 ( V_9 ) ;
F_105 ( V_182 , V_188 - 1 ) ;
return V_53 ;
}
static void F_141 ( struct V_8 * V_9 ,
void * V_131 , int V_19 )
{
struct V_257 * V_258 = F_6 ( V_9 ,
struct V_257 , V_10 ) ;
struct V_168 * V_169 = F_31 ( V_131 , struct V_168 , V_31 ) ;
struct V_3 * V_3 = F_102 ( V_169 ) ;
bool V_115 = F_56 ( V_9 , V_19 ) ;
unsigned long V_62 = V_3 -> V_60 . V_62 [ V_166 ] ;
const char * V_170 = F_98 ( V_169 ) ;
char V_70 [ 256 ] , V_162 ;
const char * V_259 = L_12 ;
T_4 V_73 ;
F_57 ( V_9 , V_115 ? V_86 :
V_85 ) ;
if ( F_99 ( V_169 ) ) {
struct V_168 * V_175 ;
V_170 = F_142 ( V_169 ) ;
F_101 (pos, evsel) {
struct V_3 * V_176 = F_102 ( V_175 ) ;
V_62 += V_176 -> V_60 . V_62 [ V_166 ] ;
}
}
V_62 = F_103 ( V_62 , & V_162 ) ;
V_73 = F_54 ( V_70 , sizeof( V_70 ) , L_69 , V_62 ,
V_162 , V_162 == ' ' ? L_18 : L_12 , V_170 ) ;
F_59 ( L_8 , V_70 ) ;
V_62 = V_3 -> V_60 . V_62 [ V_63 ] ;
if ( V_62 != 0 ) {
V_258 -> V_260 = true ;
if ( ! V_115 )
F_57 ( V_9 , V_261 ) ;
V_62 = F_103 ( V_62 , & V_162 ) ;
V_73 += F_54 ( V_70 , sizeof( V_70 ) , L_70 ,
V_62 , V_162 , V_162 == ' ' ? L_18 : L_12 ) ;
V_259 = V_70 ;
}
F_58 ( V_259 , V_9 -> V_18 - V_73 ) ;
if ( V_115 )
V_258 -> V_47 = V_169 ;
}
static int F_143 ( struct V_257 * V_258 ,
int V_62 , const char * V_262 ,
struct V_51 * V_52 )
{
struct V_263 * V_264 = V_258 -> V_10 . V_265 ;
struct V_168 * V_175 ;
const char * V_54 = L_71 ;
int V_55 = V_52 ? V_52 -> V_56 : 0 ;
int V_53 ;
if ( F_46 ( & V_258 -> V_10 , V_54 ,
L_72 ) < 0 )
return - 1 ;
while ( 1 ) {
V_53 = F_47 ( & V_258 -> V_10 , V_55 ) ;
switch ( V_53 ) {
case V_57 :
V_52 -> V_58 ( V_52 -> V_59 ) ;
if ( ! V_258 -> V_266 && V_258 -> V_260 ) {
F_42 ( & V_258 -> V_10 ) ;
V_258 -> V_266 = true ;
}
continue;
case V_235 :
case V_68 :
if ( ! V_258 -> V_47 )
continue;
V_175 = V_258 -> V_47 ;
V_267:
F_144 ( V_264 , V_175 ) ;
if ( V_52 )
V_52 -> V_58 ( V_52 -> V_59 ) ;
V_53 = F_115 ( V_175 , V_62 , V_262 ,
true , V_52 ,
V_258 -> V_4 ,
V_258 -> V_205 ) ;
F_49 ( & V_258 -> V_10 , V_54 ) ;
switch ( V_53 ) {
case V_224 :
if ( V_175 -> V_31 . V_41 == & V_264 -> V_50 )
V_175 = F_145 ( V_264 ) ;
else
V_175 = F_146 ( V_175 ) ;
goto V_267;
case V_225 :
if ( V_175 -> V_31 . V_43 == & V_264 -> V_50 )
V_175 = F_147 ( V_264 ) ;
else
V_175 = F_148 ( V_175 ) ;
goto V_267;
case V_239 :
if ( ! F_127 ( & V_258 -> V_10 ,
L_50 ) )
continue;
case V_256 :
case 'q' :
case F_128 ( 'c' ) :
goto V_69;
default:
continue;
}
case V_236 :
continue;
case V_239 :
if ( ! F_127 ( & V_258 -> V_10 ,
L_50 ) )
continue;
case 'q' :
case F_128 ( 'c' ) :
goto V_69;
default:
continue;
}
}
V_69:
F_52 ( & V_258 -> V_10 ) ;
return V_53 ;
}
static bool F_149 ( struct V_8 * V_9 V_88 ,
void * V_131 )
{
struct V_168 * V_169 = F_31 ( V_131 , struct V_168 , V_31 ) ;
if ( V_134 . V_268 && ! F_150 ( V_169 ) )
return true ;
return false ;
}
static int F_151 ( struct V_263 * V_264 ,
int V_5 , const char * V_262 ,
struct V_51 * V_52 ,
float V_4 ,
struct V_204 * V_205 )
{
struct V_168 * V_175 ;
struct V_257 V_258 = {
. V_10 = {
. V_50 = & V_264 -> V_50 ,
. V_56 = V_269 ,
. V_158 = V_270 ,
. V_271 = F_141 ,
. V_272 = F_149 ,
. V_5 = V_5 ,
. V_265 = V_264 ,
} ,
. V_4 = V_4 ,
. V_205 = V_205 ,
} ;
F_118 ( L_73 ) ;
F_152 (evlist, pos) {
const char * V_170 = F_98 ( V_175 ) ;
T_4 V_273 = strlen ( V_170 ) + 7 ;
if ( V_258 . V_10 . V_18 < V_273 )
V_258 . V_10 . V_18 = V_273 ;
}
return F_143 ( & V_258 , V_5 , V_262 , V_52 ) ;
}
int F_153 ( struct V_263 * V_264 , const char * V_262 ,
struct V_51 * V_52 ,
float V_4 ,
struct V_204 * V_205 )
{
int V_5 = V_264 -> V_5 ;
V_274:
if ( V_5 == 1 ) {
struct V_168 * V_39 = F_145 ( V_264 ) ;
return F_115 ( V_39 , V_5 , V_262 ,
false , V_52 , V_4 ,
V_205 ) ;
}
if ( V_134 . V_268 ) {
struct V_168 * V_175 ;
V_5 = 0 ;
F_152 (evlist, pos) {
if ( F_150 ( V_175 ) )
V_5 ++ ;
}
if ( V_5 == 1 )
goto V_274;
}
return F_151 ( V_264 , V_5 , V_262 ,
V_52 , V_4 , V_205 ) ;
}
