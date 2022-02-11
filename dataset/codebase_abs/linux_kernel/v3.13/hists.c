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
F_62 () ;
V_119 [ V_120 ] . V_91 =
V_121 ;
V_119 [ V_122 ] . V_91 =
V_123 ;
V_119 [ V_124 ] . V_91 =
V_125 ;
V_119 [ V_126 ] . V_91 =
V_127 ;
V_119 [ V_128 ] . V_91 =
V_129 ;
}
static int F_63 ( struct V_1 * V_2 ,
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
F_64 (fmt) {
if ( ! V_25 ) {
F_51 ( L_18 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_132 -> V_91 ) {
V_4 -= V_132 -> V_91 ( V_132 , & V_104 , V_130 ) ;
} else {
V_4 -= V_132 -> V_130 ( V_132 , & V_104 , V_130 ) ;
F_51 ( L_8 , V_98 ) ;
}
}
if ( ! V_2 -> V_3 . V_118 )
V_4 += 1 ;
F_65 ( V_130 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
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
static void F_66 ( struct V_36 * V_2 )
{
if ( V_2 -> V_55 == NULL ) {
struct V_1 * V_133 ;
V_133 = F_67 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_55 = F_11 ( & V_133 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_68 ( struct V_36 * V_2 )
{
unsigned V_76 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_133 = F_67 ( V_2 , struct V_1 , V_3 ) ;
F_66 ( V_2 ) ;
for ( V_20 = V_2 -> V_55 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_134 . V_117 * 100.0 /
V_133 -> V_5 -> V_49 . V_99 ;
if ( V_54 -> V_135 )
continue;
if ( V_94 < V_133 -> V_44 )
continue;
V_76 += F_63 ( V_133 , V_54 , V_76 ) ;
if ( V_76 == V_2 -> V_56 )
break;
}
return V_76 ;
}
static struct V_19 * F_69 ( struct V_19 * V_20 ,
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
static struct V_19 * F_70 ( struct V_19 * V_20 ,
struct V_5 * V_5 ,
float V_44 )
{
while ( V_20 != NULL ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
float V_94 = V_54 -> V_134 . V_117 * 100.0 /
V_5 -> V_49 . V_99 ;
if ( ! V_54 -> V_135 && V_94 >= V_44 )
return V_20 ;
V_20 = F_71 ( V_20 ) ;
}
return NULL ;
}
static void F_72 ( struct V_36 * V_2 ,
T_3 V_79 , int V_136 )
{
struct V_11 * V_54 ;
struct V_19 * V_20 ;
bool V_25 = true ;
struct V_1 * V_133 ;
V_133 = F_67 ( V_2 , struct V_1 , V_3 ) ;
if ( V_2 -> V_6 == 0 )
return;
F_66 ( V_2 ) ;
switch ( V_136 ) {
case V_137 :
V_20 = F_69 ( F_11 ( V_2 -> V_35 ) ,
V_133 -> V_5 , V_133 -> V_44 ) ;
break;
case V_138 :
V_20 = V_2 -> V_55 ;
goto V_139;
case V_140 :
V_20 = F_70 ( F_73 ( V_2 -> V_35 ) ,
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
V_20 = F_69 ( F_12 ( V_20 ) , V_133 -> V_5 ,
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
V_20 = F_70 ( F_71 ( V_20 ) , V_133 -> V_5 ,
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
static int F_74 ( struct V_1 * V_2 ,
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
V_65 += F_74 ( V_2 , V_22 , V_81 ,
V_97 , V_141 ) ;
}
V_17 = V_27 ;
}
return V_65 ;
}
static int F_75 ( struct V_1 * V_2 ,
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
V_65 += F_74 ( V_2 , V_17 ,
V_2 -> V_5 -> V_49 . V_99 ,
V_75 + 1 , V_141 ) ;
return V_65 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_75 , T_5 * V_141 )
{
struct V_19 * V_20 ;
int V_65 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_65 += F_75 ( V_2 , V_17 , V_75 , V_141 ) ;
}
return V_65 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_141 )
{
char V_98 [ 8192 ] ;
double V_94 ;
int V_65 = 0 ;
char V_24 = ' ' ;
if ( V_101 . V_102 )
V_24 = F_7 ( V_12 ) ;
F_65 ( V_12 , V_98 , sizeof( V_98 ) , V_2 -> V_5 ) ;
V_94 = ( V_12 -> V_134 . V_117 * 100.0 ) / V_2 -> V_5 -> V_49 . V_99 ;
if ( V_101 . V_102 )
V_65 += fprintf ( V_141 , L_15 , V_24 ) ;
V_65 += fprintf ( V_141 , L_20 , V_94 ) ;
if ( V_101 . V_142 )
V_65 += fprintf ( V_141 , L_21 , V_12 -> V_134 . V_51 ) ;
if ( V_101 . V_143 )
V_65 += fprintf ( V_141 , L_22 V_144 , V_12 -> V_134 . V_117 ) ;
V_65 += fprintf ( V_141 , L_23 , F_78 ( V_98 ) ) ;
if ( V_24 == '-' )
V_65 += F_76 ( V_2 , & V_12 -> V_31 , 1 , V_141 ) ;
return V_65 ;
}
static int F_79 ( struct V_1 * V_2 , T_5 * V_141 )
{
struct V_19 * V_20 = F_69 ( F_11 ( V_2 -> V_3 . V_35 ) ,
V_2 -> V_5 ,
V_2 -> V_44 ) ;
int V_65 = 0 ;
while ( V_20 ) {
struct V_11 * V_54 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_65 += F_77 ( V_2 , V_54 , V_141 ) ;
V_20 = F_69 ( F_12 ( V_20 ) , V_2 -> V_5 ,
V_2 -> V_44 ) ;
}
return V_65 ;
}
static int F_80 ( struct V_1 * V_2 )
{
char V_145 [ 64 ] ;
T_5 * V_141 ;
while ( 1 ) {
F_43 ( V_145 , sizeof( V_145 ) , L_24 , V_2 -> V_146 ) ;
if ( F_81 ( V_145 , V_147 ) )
break;
if ( ++ V_2 -> V_146 == 8192 ) {
F_40 ( L_25 ) ;
return - 1 ;
}
}
V_141 = fopen ( V_145 , L_26 ) ;
if ( V_141 == NULL ) {
char V_62 [ 64 ] ;
const char * V_148 = F_82 ( V_149 , V_62 , sizeof( V_62 ) ) ;
F_40 ( L_27 , V_145 , V_148 ) ;
return - 1 ;
}
++ V_2 -> V_146 ;
F_79 ( V_2 , V_141 ) ;
fclose ( V_141 ) ;
F_40 ( L_28 , V_145 ) ;
return 0 ;
}
static struct V_1 * F_83 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_84 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_43 = F_68 ;
V_2 -> V_3 . V_150 = F_72 ;
V_2 -> V_3 . V_151 = true ;
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
static struct V_152 * F_87 ( struct V_1 * V_2 )
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
if ( F_88 ( V_114 ) ) {
struct V_113 * V_159 ;
F_89 ( V_114 , V_108 , V_158 ) ;
V_37 = V_108 ;
F_90 (pos, evsel) {
V_156 += V_159 -> V_5 . V_49 . V_51 [ V_157 ] ;
V_51 += V_159 -> V_5 . V_49 . V_99 ;
}
}
V_156 = F_91 ( V_156 , & V_153 ) ;
V_65 = F_43 ( V_62 , V_109 ,
L_29 ,
V_156 , V_153 , V_37 , V_51 ) ;
if ( V_5 -> V_160 )
V_65 += snprintf ( V_62 + V_65 , V_109 - V_65 ,
L_30 , V_5 -> V_160 ) ;
if ( V_152 )
V_65 += F_43 ( V_62 + V_65 , V_109 - V_65 ,
L_31 ,
( V_152 -> V_161 ? F_92 ( V_152 ) : L_32 ) ,
V_152 -> V_162 ) ;
if ( V_71 )
V_65 += F_43 ( V_62 + V_65 , V_109 - V_65 ,
L_33 , V_71 -> V_72 ) ;
return V_65 ;
}
static inline void F_93 ( char * * V_163 , int V_18 )
{
int V_164 ;
for ( V_164 = 0 ; V_164 < V_18 ; ++ V_164 ) {
free ( V_163 [ V_164 ] ) ;
V_163 [ V_164 ] = NULL ;
}
}
static inline bool F_94 ( void * V_47 )
{
return V_47 == NULL ;
}
static int F_95 ( void )
{
char * V_165 , * V_163 [ 32 ] , * V_166 [ 32 ] , * V_167 ;
T_6 * V_168 ;
int V_169 = 0 , V_170 = - 1 , V_105 = - 1 ;
struct V_171 * V_172 ;
V_165 = getenv ( L_34 ) ;
if ( ! V_165 )
return V_105 ;
V_168 = F_96 ( V_165 ) ;
if ( ! V_168 )
return V_105 ;
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
memset ( V_163 , 0 , sizeof( V_166 ) ) ;
while ( ( V_172 = F_97 ( V_168 ) ) ) {
char V_173 [ V_174 ] ;
T_1 V_175 ;
char * V_67 = V_172 -> V_176 ;
T_5 * V_177 ;
if ( ! ( V_172 -> V_178 == V_179 ) )
continue;
snprintf ( V_173 , sizeof( V_173 ) , L_35 , V_165 , V_67 ) ;
V_177 = fopen ( V_173 , L_36 ) ;
if ( ! V_177 )
continue;
if ( fread ( & V_175 , 1 , 8 , V_177 ) < 8 )
goto V_180;
if ( F_98 ( V_175 ) ) {
V_163 [ V_169 ] = F_99 ( V_67 ) ;
if ( ! V_163 [ V_169 ] )
goto V_180;
V_166 [ V_169 ] = F_99 ( V_173 ) ;
if ( ! V_166 [ V_169 ] ) {
free ( V_163 [ V_169 ] ) ;
F_100 ( L_37 ) ;
fclose ( V_177 ) ;
break;
}
V_169 ++ ;
}
V_180:
fclose ( V_177 ) ;
if ( V_169 >= 32 ) {
F_100 ( L_38
L_39 ) ;
break;
}
}
F_101 ( V_168 ) ;
if ( V_169 ) {
V_170 = F_102 ( V_169 , V_163 ) ;
if ( V_170 < V_169 && V_170 >= 0 ) {
V_167 = F_99 ( V_166 [ V_170 ] ) ;
if ( V_167 ) {
if ( V_181 )
free ( ( void * ) V_182 ) ;
V_182 = V_167 ;
V_181 = true ;
V_105 = 0 ;
} else
F_100 ( L_40 ) ;
}
}
F_93 ( V_163 , V_169 ) ;
F_93 ( V_166 , V_169 ) ;
return V_105 ;
}
static void F_36 ( struct V_1 * V_133 )
{
T_1 V_6 = 0 ;
struct V_19 * V_20 = F_11 ( & V_133 -> V_5 -> V_35 ) ;
while ( V_20 ) {
V_6 ++ ;
V_20 = F_69 ( F_12 ( V_20 ) , V_133 -> V_5 ,
V_133 -> V_44 ) ;
}
V_133 -> V_45 = V_6 ;
}
static int F_103 ( struct V_113 * V_114 , int V_51 ,
const char * V_183 , const char * V_37 ,
bool V_184 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_185 * V_186 )
{
struct V_5 * V_5 = & V_114 -> V_5 ;
struct V_1 * V_2 = F_83 ( V_5 ) ;
struct V_187 * V_188 ;
struct V_189 * V_190 ;
char * V_163 [ 16 ] ;
int V_169 = 0 ;
int V_40 = - 1 ;
char V_108 [ 64 ] ;
char V_191 [ 64 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
if ( V_2 == NULL )
return - 1 ;
if ( V_44 ) {
V_2 -> V_44 = V_44 ;
F_36 ( V_2 ) ;
}
V_190 = F_104 ( 2 ) ;
if ( V_190 == NULL )
goto V_61;
F_105 ( V_183 ) ;
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
while ( 1 ) {
const struct V_152 * V_152 = NULL ;
const struct V_71 * V_71 = NULL ;
int V_170 = 0 ,
V_192 = - 2 , V_193 = - 2 , V_194 = - 2 ,
V_195 = - 2 , V_196 = - 2 , V_197 = - 2 ;
int V_198 = - 2 , V_199 = - 2 ,
V_200 = - 2 , V_201 = - 2 ;
V_169 = 0 ;
V_40 = F_32 ( V_2 , V_37 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_152 = F_87 ( V_2 ) ;
V_71 = V_2 -> V_32 -> V_70 ? V_2 -> V_32 -> V_70 -> V_71 : NULL ;
}
switch ( V_40 ) {
case V_202 :
case V_203 :
if ( V_51 == 1 )
continue;
goto V_204;
case 'a' :
if ( ! V_205 ) {
F_31 ( & V_2 -> V_3 , V_42 * 2 ,
L_41
L_42 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_66 == NULL ||
V_2 -> V_32 -> V_70 -> V_71 -> V_206 )
continue;
goto V_207;
case 'P' :
F_80 ( V_2 ) ;
continue;
case 'd' :
goto V_193;
case 'V' :
V_2 -> V_64 = ! V_2 -> V_64 ;
continue;
case 't' :
goto V_194;
case '/' :
if ( F_106 ( L_43 ,
L_44 ,
V_108 , L_45 ,
V_42 * 2 ) == V_60 ) {
V_5 -> V_208 = * V_108 ? V_108 : NULL ;
F_107 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case 'r' :
if ( F_94 ( V_39 ) )
goto V_209;
continue;
case 's' :
if ( F_94 ( V_39 ) )
goto V_210;
continue;
case V_211 :
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
case V_212 :
break;
case V_213 : {
const void * V_55 ;
if ( F_109 ( V_190 ) ) {
if ( V_184 )
goto V_204;
continue;
}
V_55 = F_110 ( V_190 ) ;
if ( V_55 == & V_2 -> V_5 -> V_154 )
goto V_214;
if ( V_55 == & V_2 -> V_5 -> V_155 )
goto V_215;
continue;
}
case V_216 :
if ( ! V_184 &&
! F_111 ( & V_2 -> V_3 ,
L_65 ) )
continue;
case 'q' :
case F_112 ( 'c' ) :
goto V_204;
default:
continue;
}
if ( ! V_205 )
goto V_217;
if ( V_218 == V_219 ) {
V_188 = V_2 -> V_33 -> V_187 ;
if ( V_2 -> V_32 != NULL &&
V_188 &&
V_188 -> V_220 . V_66 != NULL &&
! V_188 -> V_220 . V_70 -> V_71 -> V_206 &&
F_46 ( & V_163 [ V_169 ] , L_66 ,
V_188 -> V_220 . V_66 -> V_67 ) > 0 )
V_195 = V_169 ++ ;
if ( V_2 -> V_32 != NULL &&
V_188 &&
V_188 -> V_221 . V_66 != NULL &&
! V_188 -> V_221 . V_70 -> V_71 -> V_206 &&
( V_188 -> V_221 . V_66 != V_188 -> V_220 . V_66 ||
V_188 -> V_221 . V_70 -> V_71 != V_188 -> V_220 . V_70 -> V_71 ) &&
F_46 ( & V_163 [ V_169 ] , L_66 ,
V_188 -> V_221 . V_66 -> V_67 ) > 0 )
V_196 = V_169 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_66 != NULL &&
! V_2 -> V_32 -> V_70 -> V_71 -> V_206 &&
F_46 ( & V_163 [ V_169 ] , L_66 ,
V_2 -> V_32 -> V_66 -> V_67 ) > 0 )
V_192 = V_169 ++ ;
}
if ( V_152 != NULL &&
F_46 ( & V_163 [ V_169 ] , L_67 ,
( V_2 -> V_5 -> V_155 ? L_68 : L_69 ) ,
( V_152 -> V_161 ? F_92 ( V_152 ) : L_32 ) ,
V_152 -> V_162 ) > 0 )
V_194 = V_169 ++ ;
if ( V_71 != NULL &&
F_46 ( & V_163 [ V_169 ] , L_70 ,
( V_2 -> V_5 -> V_154 ? L_68 : L_69 ) ,
( V_71 -> V_222 ? L_71 : V_71 -> V_72 ) ) > 0 )
V_193 = V_169 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_70 != NULL &&
F_46 ( & V_163 [ V_169 ] , L_72 ) > 0 )
V_197 = V_169 ++ ;
if ( V_2 -> V_33 ) {
struct V_223 * V_66 ;
if ( F_46 ( & V_163 [ V_169 ] , L_73 ,
F_92 ( V_2 -> V_33 -> V_152 ) ) > 0 )
V_198 = V_169 ++ ;
V_66 = V_2 -> V_33 -> V_9 . V_66 ;
if ( V_66 && V_66 -> V_224 &&
F_46 ( & V_163 [ V_169 ] , L_74 ,
V_66 -> V_67 ) > 0 )
V_199 = V_169 ++ ;
}
if ( F_46 ( & V_163 [ V_169 ] , L_75 ) > 0 )
V_200 = V_169 ++ ;
if ( F_94 ( V_39 ) && F_46 ( & V_163 [ V_169 ] ,
L_76 ) > 0 )
V_201 = V_169 ++ ;
V_217:
V_163 [ V_169 ++ ] = ( char * ) L_77 ;
V_225:
V_170 = F_102 ( V_169 , V_163 ) ;
if ( V_170 == V_169 - 1 )
break;
if ( V_170 == - 1 ) {
F_93 ( V_163 , V_169 - 1 ) ;
continue;
}
if ( V_170 == V_192 || V_170 == V_196 || V_170 == V_195 ) {
struct V_11 * V_12 ;
int V_148 ;
V_207:
if ( ! V_226 && F_113 ( V_186 ) )
continue;
V_12 = F_86 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_170 == V_195 ) {
V_12 -> V_9 . V_66 = V_12 -> V_187 -> V_220 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_187 -> V_220 . V_70 ;
} else if ( V_170 == V_196 ) {
V_12 -> V_9 . V_66 = V_12 -> V_187 -> V_221 . V_66 ;
V_12 -> V_9 . V_70 = V_12 -> V_187 -> V_221 . V_70 ;
}
V_12 -> V_227 = true ;
V_148 = F_114 ( V_12 , V_114 , V_39 ) ;
V_12 -> V_227 = false ;
if ( ( V_148 == 'q' || V_148 == F_112 ( 'c' ) )
&& V_196 != - 2 && V_195 != - 2 )
goto V_225;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_148 )
F_115 ( & V_2 -> V_3 ) ;
} else if ( V_170 == V_197 )
F_116 ( V_2 -> V_32 -> V_70 ) ;
else if ( V_170 == V_193 ) {
V_193:
if ( V_2 -> V_5 -> V_154 ) {
F_117 ( V_190 , & V_2 -> V_5 -> V_154 ) ;
V_214:
F_39 () ;
V_2 -> V_5 -> V_154 = NULL ;
V_228 . V_229 = false ;
} else {
if ( V_71 == NULL )
continue;
F_40 ( L_78 ,
V_71 -> V_222 ? L_71 : V_71 -> V_72 ) ;
V_2 -> V_5 -> V_154 = V_71 ;
V_228 . V_229 = true ;
F_118 ( V_190 , & V_2 -> V_5 -> V_154 ) ;
}
F_119 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_170 == V_194 ) {
V_194:
if ( V_2 -> V_5 -> V_155 ) {
F_117 ( V_190 , & V_2 -> V_5 -> V_155 ) ;
V_215:
F_39 () ;
V_2 -> V_5 -> V_155 = NULL ;
V_230 . V_229 = false ;
} else {
F_40 ( L_79 ,
V_152 -> V_161 ? F_92 ( V_152 ) : L_32 ,
V_152 -> V_162 ) ;
V_2 -> V_5 -> V_155 = V_152 ;
V_230 . V_229 = true ;
F_118 ( V_190 , & V_2 -> V_5 -> V_155 ) ;
}
F_120 ( V_5 ) ;
F_3 ( V_2 ) ;
}
else if ( V_170 == V_200 || V_170 == V_198 ||
V_170 == V_199 ) {
V_209:
memset ( V_191 , 0 , 64 ) ;
if ( V_170 == V_198 )
sprintf ( V_191 , L_80 , F_92 ( V_2 -> V_33 -> V_152 ) ) ;
if ( V_170 == V_199 )
sprintf ( V_191 , L_81 , V_2 -> V_33 -> V_9 . V_66 -> V_67 ) ;
F_121 ( V_191 ) ;
}
else if ( V_170 == V_201 ) {
V_210:
if ( ! F_95 () ) {
V_40 = V_231 ;
break;
} else
F_100 ( L_82
L_83 ) ;
}
}
V_204:
F_122 ( V_190 ) ;
V_61:
F_85 ( V_2 ) ;
F_93 ( V_163 , V_169 - 1 ) ;
return V_40 ;
}
static void F_123 ( struct V_36 * V_2 ,
void * V_130 , int V_76 )
{
struct V_232 * V_233 = F_67 ( V_2 ,
struct V_232 , V_3 ) ;
struct V_113 * V_114 = F_124 ( V_130 , struct V_113 , V_17 ) ;
bool V_107 = F_47 ( V_2 , V_76 ) ;
unsigned long V_51 = V_114 -> V_5 . V_49 . V_51 [ V_157 ] ;
const char * V_37 = F_125 ( V_114 ) ;
char V_62 [ 256 ] , V_153 ;
const char * V_234 = L_14 ;
T_2 V_65 ;
F_48 ( V_2 , V_107 ? V_96 :
V_95 ) ;
if ( F_88 ( V_114 ) ) {
struct V_113 * V_159 ;
V_37 = F_126 ( V_114 ) ;
F_90 (pos, evsel) {
V_51 += V_159 -> V_5 . V_49 . V_51 [ V_157 ] ;
}
}
V_51 = F_91 ( V_51 , & V_153 ) ;
V_65 = F_43 ( V_62 , sizeof( V_62 ) , L_84 , V_51 ,
V_153 , V_153 == ' ' ? L_32 : L_14 , V_37 ) ;
F_51 ( L_8 , V_62 ) ;
V_51 = V_114 -> V_5 . V_49 . V_51 [ V_52 ] ;
if ( V_51 != 0 ) {
V_233 -> V_235 = true ;
if ( ! V_107 )
F_48 ( V_2 , V_236 ) ;
V_51 = F_91 ( V_51 , & V_153 ) ;
V_65 += F_43 ( V_62 , sizeof( V_62 ) , L_85 ,
V_51 , V_153 , V_153 == ' ' ? L_32 : L_14 ) ;
V_234 = V_62 ;
}
F_50 ( V_234 , V_2 -> V_4 - V_65 ) ;
if ( V_107 )
V_233 -> V_32 = V_114 ;
}
static int F_127 ( struct V_232 * V_233 ,
int V_51 , const char * V_237 ,
struct V_38 * V_39 )
{
struct V_238 * V_239 = V_233 -> V_3 . V_240 ;
struct V_113 * V_159 ;
const char * V_37 , * V_41 = L_86 ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
int V_40 ;
if ( F_34 ( & V_233 -> V_3 , V_41 ,
L_87 ) < 0 )
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
V_159 = V_233 -> V_32 ;
V_242:
F_128 ( V_239 , V_159 ) ;
if ( V_39 )
V_39 -> V_47 ( V_39 -> V_48 ) ;
V_37 = F_125 ( V_159 ) ;
V_40 = F_103 ( V_159 , V_51 , V_237 ,
V_37 , true , V_39 ,
V_233 -> V_44 ,
V_233 -> V_186 ) ;
F_38 ( & V_233 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_202 :
if ( V_159 -> V_17 . V_27 == & V_239 -> V_35 )
V_159 = F_129 ( V_239 ) ;
else
V_159 = F_130 ( V_159 ) ;
goto V_242;
case V_203 :
if ( V_159 -> V_17 . V_243 == & V_239 -> V_35 )
V_159 = F_131 ( V_239 ) ;
else
V_159 = F_132 ( V_159 ) ;
goto V_242;
case V_216 :
if ( ! F_111 ( & V_233 -> V_3 ,
L_65 ) )
continue;
case V_231 :
case 'q' :
case F_112 ( 'c' ) :
goto V_61;
default:
continue;
}
case V_213 :
continue;
case V_216 :
if ( ! F_111 ( & V_233 -> V_3 ,
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
F_41 ( & V_233 -> V_3 ) ;
return V_40 ;
}
static bool F_133 ( struct V_36 * V_2 V_244 ,
void * V_130 )
{
struct V_113 * V_114 = F_124 ( V_130 , struct V_113 , V_17 ) ;
if ( V_101 . V_110 && ! F_134 ( V_114 ) )
return true ;
return false ;
}
static int F_135 ( struct V_238 * V_239 ,
int V_6 , const char * V_237 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_185 * V_186 )
{
struct V_113 * V_159 ;
struct V_232 V_233 = {
. V_3 = {
. V_35 = & V_239 -> V_35 ,
. V_43 = V_245 ,
. V_150 = V_246 ,
. V_247 = F_123 ,
. V_248 = F_133 ,
. V_6 = V_6 ,
. V_240 = V_239 ,
} ,
. V_44 = V_44 ,
. V_186 = V_186 ,
} ;
F_105 ( L_88 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_125 ( V_159 ) ;
T_2 V_249 = strlen ( V_37 ) + 7 ;
if ( V_233 . V_3 . V_4 < V_249 )
V_233 . V_3 . V_4 = V_249 ;
}
return F_127 ( & V_233 , V_6 , V_237 , V_39 ) ;
}
int F_136 ( struct V_238 * V_239 , const char * V_237 ,
struct V_38 * V_39 ,
float V_44 ,
struct V_185 * V_186 )
{
int V_6 = V_239 -> V_6 ;
V_250:
if ( V_6 == 1 ) {
struct V_113 * V_25 = F_129 ( V_239 ) ;
const char * V_37 = F_125 ( V_25 ) ;
return F_103 ( V_25 , V_6 , V_237 ,
V_37 , false , V_39 , V_44 ,
V_186 ) ;
}
if ( V_101 . V_110 ) {
struct V_113 * V_159 ;
V_6 = 0 ;
F_14 (pos, &evlist->entries, node)
if ( F_134 ( V_159 ) )
V_6 ++ ;
if ( V_6 == 1 )
goto V_250;
}
return F_135 ( V_239 , V_6 , V_237 ,
V_39 , V_44 , V_186 ) ;
}
