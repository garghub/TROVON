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
static int F_54 ( struct V_100 * V_48 )
{
if ( ! V_101 . V_102 )
return 0 ;
F_51 ( L_15 , V_48 -> V_24 ) ;
return 2 ;
}
static int F_55 ( struct V_103 * V_104 , struct V_11 * V_12 ,
T_1 (* F_56)( struct V_11 * ) ,
int (* F_57)( struct V_100 * ) )
{
int V_105 = 0 ;
double V_94 = 0.0 ;
struct V_5 * V_5 = V_12 -> V_5 ;
struct V_100 * V_48 = V_104 -> V_106 ;
if ( V_5 -> V_49 . V_99 )
V_94 = 100.0 * F_56 ( V_12 ) / V_5 -> V_49 . V_99 ;
F_58 ( V_48 -> V_3 , V_94 , V_48 -> V_107 ) ;
if ( F_57 )
V_105 += F_57 ( V_48 ) ;
V_105 += F_43 ( V_104 -> V_108 , V_104 -> V_109 , L_16 , V_94 ) ;
F_51 ( L_8 , V_104 -> V_108 ) ;
if ( V_101 . V_110 ) {
int V_111 , V_112 ;
struct V_113 * V_114 = F_59 ( V_5 ) ;
struct V_11 * V_115 ;
int V_116 = V_114 -> V_116 ;
if ( V_116 <= 1 )
goto V_61;
V_111 = F_60 ( V_114 ) ;
F_14 (pair, &he->pairs.head, pairs.node) {
T_1 V_117 = F_56 ( V_115 ) ;
T_1 V_74 = V_115 -> V_5 -> V_49 . V_99 ;
if ( ! V_74 )
continue;
V_114 = F_59 ( V_115 -> V_5 ) ;
V_112 = F_60 ( V_114 ) - V_111 - 1 ;
while ( V_112 -- ) {
F_58 ( V_48 -> V_3 , 0.0 ,
V_48 -> V_107 ) ;
V_105 += F_43 ( V_104 -> V_108 , V_104 -> V_109 ,
L_17 , 0.0 ) ;
F_51 ( L_8 , V_104 -> V_108 ) ;
}
V_94 = 100.0 * V_117 / V_74 ;
F_58 ( V_48 -> V_3 , V_94 ,
V_48 -> V_107 ) ;
V_105 += F_43 ( V_104 -> V_108 , V_104 -> V_109 ,
L_17 , V_94 ) ;
F_51 ( L_8 , V_104 -> V_108 ) ;
V_111 = F_60 ( V_114 ) ;
}
V_112 = V_116 - V_111 - 1 ;
while ( V_112 -- ) {
F_58 ( V_48 -> V_3 , 0.0 ,
V_48 -> V_107 ) ;
V_105 += F_43 ( V_104 -> V_108 , V_104 -> V_109 ,
L_17 , 0.0 ) ;
F_51 ( L_8 , V_104 -> V_108 ) ;
}
}
V_61:
if ( ! V_48 -> V_107 || ! V_48 -> V_3 -> V_118 )
F_48 ( V_48 -> V_3 , V_95 ) ;
return V_105 ;
}
void F_61 ( void )
{
F_62 ( V_119 ) ;
F_63 () ;
V_120 [ V_119 ] . V_91 =
V_121 ;
V_120 [ V_122 ] . V_91 =
V_123 ;
V_120 [ V_124 ] . V_91 =
V_125 ;
V_120 [ V_126 ] . V_91 =
V_127 ;
V_120 [ V_128 ] . V_91 =
V_129 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_11 * V_130 ,
unsigned short V_76 )
{
char V_98 [ 256 ] ;
int V_65 = 0 ;
int V_4 = V_2 -> V_3 . V_4 ;
char V_24 = ' ' ;
bool V_107 = F_47 ( & V_2 -> V_3 , V_76 ) ;
T_3 V_59 = V_130 -> V_59 ;
bool V_25 = true ;
struct V_131 * V_132 ;
if ( V_107 ) {
V_2 -> V_33 = V_130 ;
V_2 -> V_32 = & V_130 -> V_9 ;
}
if ( V_101 . V_102 ) {
F_22 ( V_130 ) ;
V_24 = F_7 ( V_130 ) ;
}
if ( V_59 == 0 ) {
struct V_100 V_48 = {
. V_3 = & V_2 -> V_3 ,
. V_24 = V_24 ,
. V_107 = V_107 ,
} ;
struct V_103 V_104 = {
. V_108 = V_98 ,
. V_109 = sizeof( V_98 ) ,
. V_106 = & V_48 ,
} ;
F_49 ( & V_2 -> V_3 , V_76 , 0 ) ;
F_65 (fmt) {
if ( ! V_25 ) {
F_51 ( L_18 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_132 -> V_91 ) {
V_4 -= V_132 -> V_91 ( & V_104 , V_130 ) ;
} else {
V_4 -= V_132 -> V_130 ( & V_104 , V_130 ) ;
F_51 ( L_8 , V_98 ) ;
}
}
if ( ! V_2 -> V_3 . V_118 )
V_4 += 1 ;
F_66 ( V_130 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
F_50 ( V_98 , V_4 ) ;
++ V_76 ;
++ V_65 ;
} else
-- V_59 ;
if ( V_24 == '-' && V_76 != V_2 -> V_3 . V_56 ) {
V_65 += F_53 ( V_2 , & V_130 -> V_31 ,
1 , V_76 , & V_59 ,
& V_107 ) ;
if ( V_107 )
V_2 -> V_33 = V_130 ;
}
return V_65 ;
}
static void F_67 ( struct V_36 * V_2 )
{
if ( V_2 -> V_55 == NULL ) {
struct V_1 * V_133 ;
V_133 = F_68 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_55 = F_11 ( & V_133 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_69 ( struct V_36 * V_2 )
{
unsigned V_76 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_133 = F_68 ( V_2 , struct V_1 , V_3 ) ;
F_67 ( V_2 ) ;
for ( V_20 = V_2 -> V_55 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_134 . V_117 * 100.0 /
V_133 -> V_5 -> V_49 . V_99 ;
if ( V_54 -> V_135 )
continue;
if ( V_94 < V_133 -> V_44 )
continue;
V_76 += F_64 ( V_133 , V_54 , V_76 ) ;
if ( V_76 == V_2 -> V_56 )
break;
}
return V_76 ;
}
static struct V_19 * F_70 ( struct V_19 * V_20 ,
struct V_5 * V_5 ,
float V_44 )
{
while ( V_20 != NULL ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_134 . V_117 * 100.0 /
V_5 -> V_49 . V_99 ;
if ( V_94 < V_44 )
return NULL ;
if ( ! V_54 -> V_135 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_71 ( struct V_19 * V_20 ,
struct V_5 * V_5 ,
float V_44 )
{
while ( V_20 != NULL ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_134 . V_117 * 100.0 /
V_5 -> V_49 . V_99 ;
if ( ! V_54 -> V_135 && V_94 >= V_44 )
return V_20 ;
V_20 = F_72 ( V_20 ) ;
}
return NULL ;
}
static void F_73 ( struct V_36 * V_2 ,
T_3 V_79 , int V_136 )
{
struct V_11 * V_54 ;
struct V_19 * V_20 ;
bool V_25 = true ;
struct V_1 * V_133 ;
V_133 = F_68 ( V_2 , struct V_1 , V_3 ) ;
if ( V_2 -> V_6 == 0 )
return;
F_67 ( V_2 ) ;
switch ( V_136 ) {
case V_137 :
V_20 = F_70 ( F_11 ( V_2 -> V_35 ) ,
V_133 -> V_5 , V_133 -> V_44 ) ;
break;
case V_138 :
V_20 = V_2 -> V_55 ;
goto V_139;
case V_140 :
V_20 = F_71 ( F_74 ( V_2 -> V_35 ) ,
V_133 -> V_5 , V_133 -> V_44 ) ;
V_25 = false ;
break;
default:
return;
}
V_54 = F_13 ( V_2 -> V_55 , struct V_11 , V_19 ) ;
V_54 -> V_59 = 0 ;
V_139:
if ( V_79 > 0 ) {
do {
V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_54 -> V_9 . V_7 ) {
T_4 V_82 = V_54 -> V_34 - V_54 -> V_59 ;
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
V_20 = F_70 ( F_12 ( V_20 ) , V_133 -> V_5 ,
V_133 -> V_44 ) ;
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
V_20 = F_71 ( F_72 ( V_20 ) , V_133 -> V_5 ,
V_133 -> V_44 ) ;
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
static int F_75 ( struct V_1 * V_2 ,
struct V_16 * V_73 ,
T_1 V_74 , int V_75 ,
T_5 * V_141 )
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
V_65 += fprintf ( V_141 , L_19 , V_79 + V_88 , L_14 , V_24 , V_90 ) ;
free ( V_89 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_97 = V_75 + ( V_88 ? 2 : 1 ) ;
V_65 += F_75 ( V_2 , V_22 , V_81 ,
V_97 , V_141 ) ;
}
V_17 = V_27 ;
}
return V_65 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_75 , T_5 * V_141 )
{
struct V_13 * V_23 ;
int V_79 = V_75 * V_80 ;
char V_24 = ' ' ;
int V_65 = 0 ;
F_14 (chain, &node->val, list) {
char V_62 [ 1024 ] , * V_98 ;
V_24 = F_8 ( V_23 ) ;
V_98 = F_42 ( V_23 , V_62 , sizeof( V_62 ) , V_2 -> V_64 ) ;
V_65 += fprintf ( V_141 , L_19 , V_79 , L_14 , V_24 , V_98 ) ;
}
if ( V_24 == '-' )
V_65 += F_75 ( V_2 , V_17 ,
V_2 -> V_5 -> V_49 . V_99 ,
V_75 + 1 , V_141 ) ;
return V_65 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_75 , T_5 * V_141 )
{
struct V_19 * V_20 ;
int V_65 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_65 += F_76 ( V_2 , V_17 , V_75 , V_141 ) ;
}
return V_65 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_141 )
{
char V_98 [ 8192 ] ;
double V_94 ;
int V_65 = 0 ;
char V_24 = ' ' ;
if ( V_101 . V_102 )
V_24 = F_7 ( V_12 ) ;
F_66 ( V_12 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
V_94 = ( V_12 -> V_134 . V_117 * 100.0 ) / V_2 -> V_5 -> V_49 . V_99 ;
if ( V_101 . V_102 )
V_65 += fprintf ( V_141 , L_15 , V_24 ) ;
V_65 += fprintf ( V_141 , L_20 , V_94 ) ;
if ( V_101 . V_142 )
V_65 += fprintf ( V_141 , L_21 , V_12 -> V_134 . V_51 ) ;
if ( V_101 . V_143 )
V_65 += fprintf ( V_141 , L_22 V_144 , V_12 -> V_134 . V_117 ) ;
V_65 += fprintf ( V_141 , L_23 , F_79 ( V_98 ) ) ;
if ( V_24 == '-' )
V_65 += F_77 ( V_2 , & V_12 -> V_31 , 1 , V_141 ) ;
return V_65 ;
}
static int F_80 ( struct V_1 * V_2 , T_5 * V_141 )
{
struct V_19 * V_20 = F_70 ( F_11 ( V_2 -> V_3 . V_35 ) ,
V_2 -> V_5 ,
V_2 -> V_44 ) ;
int V_65 = 0 ;
while ( V_20 ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_65 += F_78 ( V_2 , V_54 , V_141 ) ;
V_20 = F_70 ( F_12 ( V_20 ) , V_2 -> V_5 ,
V_2 -> V_44 ) ;
}
return V_65 ;
}
static int F_81 ( struct V_1 * V_2 )
{
char V_145 [ 64 ] ;
T_5 * V_141 ;
while ( 1 ) {
F_43 ( V_145 , sizeof( V_145 ) , L_24 , V_2 -> V_146 ) ;
if ( F_82 ( V_145 , V_147 ) )
break;
if ( ++ V_2 -> V_146 == 8192 ) {
F_40 ( L_25 ) ;
return - 1 ;
}
}
V_141 = fopen ( V_145 , L_26 ) ;
if ( V_141 == NULL ) {
char V_62 [ 64 ] ;
const char * V_148 = F_83 ( V_149 , V_62 , sizeof( V_62 ) ) ;
F_40 ( L_27 , V_145 , V_148 ) ;
return - 1 ;
}
++ V_2 -> V_146 ;
F_80 ( V_2 , V_141 ) ;
fclose ( V_141 ) ;
F_40 ( L_28 , V_145 ) ;
return 0 ;
}
static struct V_1 * F_84 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_85 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_43 = F_69 ;
V_2 -> V_3 . V_150 = F_73 ;
V_2 -> V_3 . V_151 = true ;
}
return V_2 ;
}
static void F_86 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_87 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_152 * F_88 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_152 ;
}
static int F_33 ( struct V_5 * V_5 , char * V_62 , T_2 V_109 ,
const char * V_37 )
{
char V_153 ;
int V_65 ;
const struct V_71 * V_71 = V_5 -> V_154 ;
const struct V_152 * V_152 = V_5 -> V_155 ;
unsigned long V_156 = V_5 -> V_49 . V_51 [ V_157 ] ;
T_1 V_51 = V_5 -> V_49 . V_99 ;
struct V_113 * V_114 = F_59 ( V_5 ) ;
char V_108 [ 512 ] ;
T_2 V_158 = sizeof( V_108 ) ;
if ( F_89 ( V_114 ) ) {
struct V_113 * V_159 ;
F_90 ( V_114 , V_108 , V_158 ) ;
V_37 = V_108 ;
F_91 (pos, evsel) {
V_156 += V_159 -> V_5 . V_49 . V_51 [ V_157 ] ;
V_51 += V_159 -> V_5 . V_49 . V_99 ;
}
}
V_156 = F_92 ( V_156 , & V_153 ) ;
V_65 = F_43 ( V_62 , V_109 ,
L_29 ,
V_156 , V_153 , V_37 , V_51 ) ;
if ( V_5 -> V_160 )
V_65 += snprintf ( V_62 + V_65 , V_109 - V_65 ,
L_30 , V_5 -> V_160 ) ;
if ( V_152 )
V_65 += F_43 ( V_62 + V_65 , V_109 - V_65 ,
L_31 ,
( V_152 -> V_161 ? V_152 -> V_162 : L_32 ) ,
V_152 -> V_163 ) ;
if ( V_71 )
V_65 += F_43 ( V_62 + V_65 , V_109 - V_65 ,
L_33 , V_71 -> V_72 ) ;
return V_65 ;
}
static inline void F_93 ( char * * V_164 , int V_18 )
{
int V_165 ;
for ( V_165 = 0 ; V_165 < V_18 ; ++ V_165 ) {
free ( V_164 [ V_165 ] ) ;
V_164 [ V_165 ] = NULL ;
}
}
static inline bool F_94 ( void * V_47 )
{
return V_47 == NULL ;
}
static int F_95 ( void )
{
char * V_166 , * V_164 [ 32 ] , * V_167 [ 32 ] , * V_168 ;
T_6 * V_169 ;
int V_170 = 0 , V_171 = - 1 , V_105 = - 1 ;
struct V_172 * V_173 ;
V_166 = getenv ( L_34 ) ;
if ( ! V_166 )
return V_105 ;
V_169 = F_96 ( V_166 ) ;
if ( ! V_169 )
return V_105 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
memset ( V_164 , 0 , sizeof( V_167 ) ) ;
while ( ( V_173 = F_97 ( V_169 ) ) ) {
char V_174 [ V_175 ] ;
T_1 V_176 ;
char * V_67 = V_173 -> V_177 ;
T_5 * V_178 ;
if ( ! ( V_173 -> V_179 == V_180 ) )
continue;
snprintf ( V_174 , sizeof( V_174 ) , L_35 , V_166 , V_67 ) ;
V_178 = fopen ( V_174 , L_36 ) ;
if ( ! V_178 )
continue;
if ( fread ( & V_176 , 1 , 8 , V_178 ) < 8 )
goto V_181;
if ( F_98 ( V_176 ) ) {
V_164 [ V_170 ] = F_99 ( V_67 ) ;
if ( ! V_164 [ V_170 ] )
goto V_181;
V_167 [ V_170 ] = F_99 ( V_174 ) ;
if ( ! V_167 [ V_170 ] ) {
free ( V_164 [ V_170 ] ) ;
F_100 ( L_37 ) ;
fclose ( V_178 ) ;
break;
}
V_170 ++ ;
}
V_181:
fclose ( V_178 ) ;
if ( V_170 >= 32 ) {
F_100 ( L_38
L_39 ) ;
break;
}
}
F_101 ( V_169 ) ;
if ( V_170 ) {
V_171 = F_102 ( V_170 , V_164 ) ;
if ( V_171 < V_170 && V_171 >= 0 ) {
V_168 = F_99 ( V_167 [ V_171 ] ) ;
if ( V_168 ) {
if ( V_182 )
free ( ( void * ) V_183 ) ;
V_183 = V_168 ;
V_182 = true ;
V_105 = 0 ;
} else
F_100 ( L_40 ) ;
}
}
F_93 ( V_164 , V_170 ) ;
F_93 ( V_167 , V_170 ) ;
return V_105 ;
}
static void F_36 ( struct V_1 * V_133 )
{
T_1 V_6 = 0 ;
struct V_19 * V_20 = F_11 ( & V_133 -> V_5 -> V_35 ) ;
while ( V_20 ) {
V_6 ++ ;
V_20 = F_70 ( F_12 ( V_20 ) , V_133 -> V_5 ,
V_133 -> V_44 ) ;
}
V_133 -> V_45 = V_6 ;
}
static int F_103 ( struct V_113 * V_114 , int V_51 ,
const char * V_184 , const char * V_37 ,
bool V_185 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_186 * V_187 )
{
struct V_5 * V_5 = & V_114 -> V_5 ;
struct V_1 * V_2 = F_84 ( V_5 ) ;
struct V_188 * V_189 ;
struct V_190 * V_191 ;
char * V_164 [ 16 ] ;
int V_170 = 0 ;
int V_40 = - 1 ;
char V_108 [ 64 ] ;
char V_192 [ 64 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
if ( V_2 == NULL )
return - 1 ;
if ( V_44 ) {
V_2 -> V_44 = V_44 ;
F_36 ( V_2 ) ;
}
V_191 = F_104 ( 2 ) ;
if ( V_191 == NULL )
goto V_61;
F_105 ( V_184 ) ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
while ( 1 ) {
const struct V_152 * V_152 = NULL ;
const struct V_71 * V_71 = NULL ;
int V_171 = 0 ,
V_193 = - 2 , V_194 = - 2 , V_195 = - 2 ,
V_196 = - 2 , V_197 = - 2 , V_198 = - 2 ;
int V_199 = - 2 , V_200 = - 2 ,
V_201 = - 2 , V_202 = - 2 ;
V_170 = 0 ;
V_40 = F_32 ( V_2 , V_37 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_152 = F_88 ( V_2 ) ;
V_71 = V_2 -> V_32 -> V_70 ? V_2 -> V_32 -> V_70 -> V_71 : NULL ;
}
switch ( V_40 ) {
case V_203 :
case V_204 :
if ( V_51 == 1 )
continue;
goto V_205;
case 'a' :
if ( ! V_206 ) {
F_31 ( & V_2 -> V_3 , V_42 * 2 ,
L_41
L_42 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_66 == NULL ||
V_2 -> V_32 -> V_70 -> V_71 -> V_207 )
continue;
goto V_208;
case 'P' :
F_81 ( V_2 ) ;
continue;
case 'd' :
goto V_194;
case 'V' :
V_2 -> V_64 = ! V_2 -> V_64 ;
continue;
case 't' :
goto V_195;
case '/' :
if ( F_106 ( L_43 ,
L_44 ,
V_108 , L_45 ,
V_42 * 2 ) == V_60 ) {
V_5 -> V_209 = * V_108 ? V_108 : NULL ;
F_107 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case 'r' :
if ( F_94 ( V_39 ) )
goto V_210;
continue;
case 's' :
if ( F_94 ( V_39 ) )
goto V_211;
continue;
case V_212 :
case 'h' :
case '?' :
F_108 ( & V_2 -> V_3 ,
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
case V_60 :
case V_213 :
break;
case V_214 : {
const void * V_55 ;
if ( F_109 ( V_191 ) ) {
if ( V_185 )
goto V_205;
continue;
}
V_55 = F_110 ( V_191 ) ;
if ( V_55 == & V_2 -> V_5 -> V_154 )
goto V_215;
if ( V_55 == & V_2 -> V_5 -> V_155 )
goto V_216;
continue;
}
case V_217 :
if ( ! V_185 &&
! F_111 ( & V_2 -> V_3 ,
L_65 ) )
continue;
case 'q' :
case F_112 ( 'c' ) :
goto V_205;
default:
continue;
}
if ( ! V_206 )
goto V_218;
if ( V_219 == V_220 ) {
V_189 = V_2 -> V_33 -> V_188 ;
if ( V_2 -> V_32 != NULL &&
V_189 &&
V_189 -> V_221 . V_66 != NULL &&
! V_189 -> V_221 . V_70 -> V_71 -> V_207 &&
F_46 ( & V_164 [ V_170 ] , L_66 ,
V_189 -> V_221 . V_66 -> V_67 ) > 0 )
V_196 = V_170 ++ ;
if ( V_2 -> V_32 != NULL &&
V_189 &&
V_189 -> V_222 . V_66 != NULL &&
! V_189 -> V_222 . V_70 -> V_71 -> V_207 &&
( V_189 -> V_222 . V_66 != V_189 -> V_221 . V_66 ||
V_189 -> V_222 . V_70 -> V_71 != V_189 -> V_221 . V_70 -> V_71 ) &&
F_46 ( & V_164 [ V_170 ] , L_66 ,
V_189 -> V_222 . V_66 -> V_67 ) > 0 )
V_197 = V_170 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_66 != NULL &&
! V_2 -> V_32 -> V_70 -> V_71 -> V_207 &&
F_46 ( & V_164 [ V_170 ] , L_66 ,
V_2 -> V_32 -> V_66 -> V_67 ) > 0 )
V_193 = V_170 ++ ;
}
if ( V_152 != NULL &&
F_46 ( & V_164 [ V_170 ] , L_67 ,
( V_2 -> V_5 -> V_155 ? L_68 : L_69 ) ,
( V_152 -> V_161 ? V_152 -> V_162 : L_32 ) ,
V_152 -> V_163 ) > 0 )
V_195 = V_170 ++ ;
if ( V_71 != NULL &&
F_46 ( & V_164 [ V_170 ] , L_70 ,
( V_2 -> V_5 -> V_154 ? L_68 : L_69 ) ,
( V_71 -> V_223 ? L_71 : V_71 -> V_72 ) ) > 0 )
V_194 = V_170 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_70 != NULL &&
F_46 ( & V_164 [ V_170 ] , L_72 ) > 0 )
V_198 = V_170 ++ ;
if ( V_2 -> V_33 ) {
struct V_224 * V_66 ;
if ( F_46 ( & V_164 [ V_170 ] , L_73 ,
V_2 -> V_33 -> V_152 -> V_162 ) > 0 )
V_199 = V_170 ++ ;
V_66 = V_2 -> V_33 -> V_9 . V_66 ;
if ( V_66 && V_66 -> V_225 &&
F_46 ( & V_164 [ V_170 ] , L_74 ,
V_66 -> V_67 ) > 0 )
V_200 = V_170 ++ ;
}
if ( F_46 ( & V_164 [ V_170 ] , L_75 ) > 0 )
V_201 = V_170 ++ ;
if ( F_94 ( V_39 ) && F_46 ( & V_164 [ V_170 ] ,
L_76 ) > 0 )
V_202 = V_170 ++ ;
V_218:
V_164 [ V_170 ++ ] = ( char * ) L_77 ;
V_226:
V_171 = F_102 ( V_170 , V_164 ) ;
if ( V_171 == V_170 - 1 )
break;
if ( V_171 == - 1 ) {
F_93 ( V_164 , V_170 - 1 ) ;
continue;
}
if ( V_171 == V_193 || V_171 == V_197 || V_171 == V_196 ) {
struct V_11 * V_12 ;
int V_148 ;
V_208:
if ( ! V_227 && F_113 ( V_187 ) )
continue;
V_12 = F_87 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_171 == V_196 ) {
V_12 -> V_9 . V_66 = V_12 -> V_188 -> V_221 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_188 -> V_221 . V_70 ;
} else if ( V_171 == V_197 ) {
V_12 -> V_9 . V_66 = V_12 -> V_188 -> V_222 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_188 -> V_222 . V_70 ;
}
V_12 -> V_228 = true ;
V_148 = F_114 ( V_12 , V_114 , V_39 ) ;
V_12 -> V_228 = false ;
if ( ( V_148 == 'q' || V_148 == F_112 ( 'c' ) )
&& V_197 != - 2 && V_196 != - 2 )
goto V_226;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_148 )
F_115 ( & V_2 -> V_3 ) ;
} else if ( V_171 == V_198 )
F_116 ( V_2 -> V_32 -> V_70 ) ;
else if ( V_171 == V_194 ) {
V_194:
if ( V_2 -> V_5 -> V_154 ) {
F_117 ( V_191 , & V_2 -> V_5 -> V_154 ) ;
V_215:
F_39 () ;
V_2 -> V_5 -> V_154 = NULL ;
V_229 . V_230 = false ;
} else {
if ( V_71 == NULL )
continue;
F_40 ( L_78 ,
V_71 -> V_223 ? L_71 : V_71 -> V_72 ) ;
V_2 -> V_5 -> V_154 = V_71 ;
V_229 . V_230 = true ;
F_118 ( V_191 , & V_2 -> V_5 -> V_154 ) ;
}
F_119 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_171 == V_195 ) {
V_195:
if ( V_2 -> V_5 -> V_155 ) {
F_117 ( V_191 , & V_2 -> V_5 -> V_155 ) ;
V_216:
F_39 () ;
V_2 -> V_5 -> V_155 = NULL ;
V_231 . V_230 = false ;
} else {
F_40 ( L_79 ,
V_152 -> V_161 ? V_152 -> V_162 : L_32 ,
V_152 -> V_163 ) ;
V_2 -> V_5 -> V_155 = V_152 ;
V_231 . V_230 = true ;
F_118 ( V_191 , & V_2 -> V_5 -> V_155 ) ;
}
F_120 ( V_5 ) ;
F_3 ( V_2 ) ;
}
else if ( V_171 == V_201 || V_171 == V_199 ||
V_171 == V_200 ) {
V_210:
memset ( V_192 , 0 , 64 ) ;
if ( V_171 == V_199 )
sprintf ( V_192 , L_80 , V_2 -> V_33 -> V_152 -> V_162 ) ;
if ( V_171 == V_200 )
sprintf ( V_192 , L_81 , V_2 -> V_33 -> V_9 . V_66 -> V_67 ) ;
F_121 ( V_192 ) ;
}
else if ( V_171 == V_202 ) {
V_211:
if ( ! F_95 () ) {
V_40 = V_232 ;
break;
} else
F_100 ( L_82
L_83 ) ;
}
}
V_205:
F_122 ( V_191 ) ;
V_61:
F_86 ( V_2 ) ;
F_93 ( V_164 , V_170 - 1 ) ;
return V_40 ;
}
static void F_123 ( struct V_36 * V_2 ,
void * V_130 , int V_76 )
{
struct V_233 * V_234 = F_68 ( V_2 ,
struct V_233 , V_3 ) ;
struct V_113 * V_114 = F_124 ( V_130 , struct V_113 , V_17 ) ;
bool V_107 = F_47 ( V_2 , V_76 ) ;
unsigned long V_51 = V_114 -> V_5 . V_49 . V_51 [ V_157 ] ;
const char * V_37 = F_125 ( V_114 ) ;
char V_62 [ 256 ] , V_153 ;
const char * V_235 = L_14 ;
T_2 V_65 ;
F_48 ( V_2 , V_107 ? V_96 :
V_95 ) ;
if ( F_89 ( V_114 ) ) {
struct V_113 * V_159 ;
V_37 = F_126 ( V_114 ) ;
F_91 (pos, evsel) {
V_51 += V_159 -> V_5 . V_49 . V_51 [ V_157 ] ;
}
}
V_51 = F_92 ( V_51 , & V_153 ) ;
V_65 = F_43 ( V_62 , sizeof( V_62 ) , L_84 , V_51 ,
V_153 , V_153 == ' ' ? L_32 : L_14 , V_37 ) ;
F_51 ( L_8 , V_62 ) ;
V_51 = V_114 -> V_5 . V_49 . V_51 [ V_52 ] ;
if ( V_51 != 0 ) {
V_234 -> V_236 = true ;
if ( ! V_107 )
F_48 ( V_2 , V_237 ) ;
V_51 = F_92 ( V_51 , & V_153 ) ;
V_65 += F_43 ( V_62 , sizeof( V_62 ) , L_85 ,
V_51 , V_153 , V_153 == ' ' ? L_32 : L_14 ) ;
V_235 = V_62 ;
}
F_50 ( V_235 , V_2 -> V_4 - V_65 ) ;
if ( V_107 )
V_234 -> V_32 = V_114 ;
}
static int F_127 ( struct V_233 * V_234 ,
int V_51 , const char * V_238 ,
struct V_38 * V_39 )
{
struct V_239 * V_240 = V_234 -> V_3 . V_241 ;
struct V_113 * V_159 ;
const char * V_37 , * V_41 = L_86 ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
int V_40 ;
if ( F_34 ( & V_234 -> V_3 , V_41 ,
L_87 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_234 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_46 :
V_39 -> V_47 ( V_39 -> V_48 ) ;
if ( ! V_234 -> V_242 && V_234 -> V_236 ) {
F_30 ( & V_234 -> V_3 ) ;
V_234 -> V_242 = true ;
}
continue;
case V_213 :
case V_60 :
if ( ! V_234 -> V_32 )
continue;
V_159 = V_234 -> V_32 ;
V_243:
F_128 ( V_240 , V_159 ) ;
if ( V_39 )
V_39 -> V_47 ( V_39 -> V_48 ) ;
V_37 = F_125 ( V_159 ) ;
V_40 = F_103 ( V_159 , V_51 , V_238 ,
V_37 , true , V_39 ,
V_234 -> V_44 ,
V_234 -> V_187 ) ;
F_38 ( & V_234 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_203 :
if ( V_159 -> V_17 . V_27 == & V_240 -> V_35 )
V_159 = F_124 ( V_240 -> V_35 . V_27 , struct V_113 , V_17 ) ;
else
V_159 = F_124 ( V_159 -> V_17 . V_27 , struct V_113 , V_17 ) ;
goto V_243;
case V_204 :
if ( V_159 -> V_17 . V_244 == & V_240 -> V_35 )
V_159 = F_124 ( V_240 -> V_35 . V_244 , struct V_113 , V_17 ) ;
else
V_159 = F_124 ( V_159 -> V_17 . V_244 , struct V_113 , V_17 ) ;
goto V_243;
case V_217 :
if ( ! F_111 ( & V_234 -> V_3 ,
L_65 ) )
continue;
case V_232 :
case 'q' :
case F_112 ( 'c' ) :
goto V_61;
default:
continue;
}
case V_214 :
continue;
case V_217 :
if ( ! F_111 ( & V_234 -> V_3 ,
L_65 ) )
continue;
case 'q' :
case F_112 ( 'c' ) :
goto V_61;
default:
continue;
}
}
V_61:
F_41 ( & V_234 -> V_3 ) ;
return V_40 ;
}
static bool F_129 ( struct V_36 * T_7 V_245 ,
void * V_130 )
{
struct V_113 * V_114 = F_124 ( V_130 , struct V_113 , V_17 ) ;
if ( V_101 . V_110 && ! F_130 ( V_114 ) )
return true ;
return false ;
}
static int F_131 ( struct V_239 * V_240 ,
int V_6 , const char * V_238 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_186 * V_187 )
{
struct V_113 * V_159 ;
struct V_233 V_234 = {
. V_3 = {
. V_35 = & V_240 -> V_35 ,
. V_43 = V_246 ,
. V_150 = V_247 ,
. V_248 = F_123 ,
. V_249 = F_129 ,
. V_6 = V_6 ,
. V_241 = V_240 ,
} ,
. V_44 = V_44 ,
. V_187 = V_187 ,
} ;
F_105 ( L_88 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_125 ( V_159 ) ;
T_2 V_250 = strlen ( V_37 ) + 7 ;
if ( V_234 . V_3 . V_4 < V_250 )
V_234 . V_3 . V_4 = V_250 ;
}
return F_127 ( & V_234 , V_6 , V_238 , V_39 ) ;
}
int F_132 ( struct V_239 * V_240 , const char * V_238 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_186 * V_187 )
{
int V_6 = V_240 -> V_6 ;
V_251:
if ( V_6 == 1 ) {
struct V_113 * V_25 = F_124 ( V_240 -> V_35 . V_27 ,
struct V_113 , V_17 ) ;
const char * V_37 = F_125 ( V_25 ) ;
return F_103 ( V_25 , V_6 , V_238 ,
V_37 , false , V_39 , V_44 ,
V_187 ) ;
}
if ( V_101 . V_110 ) {
struct V_113 * V_159 ;
V_6 = 0 ;
F_14 (pos, &evlist->entries, node)
if ( F_130 ( V_159 ) )
V_6 ++ ;
if ( V_6 == 1 )
goto V_251;
}
return F_131 ( V_240 , V_6 , V_238 ,
V_39 , V_44 , V_187 ) ;
}
