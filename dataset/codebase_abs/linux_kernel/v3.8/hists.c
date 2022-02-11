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
F_1 ( V_2 ) ;
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
if ( F_34 ( & V_2 -> V_3 , V_41 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_2 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_44 :
V_39 -> V_45 ( V_39 -> V_46 ) ;
F_36 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_2 -> V_5 -> V_47 . V_48 !=
V_2 -> V_5 -> V_47 . V_49 [ V_50 ] ) {
V_2 -> V_5 -> V_47 . V_48 =
V_2 -> V_5 -> V_47 . V_49 [ V_50 ] ;
F_30 ( & V_2 -> V_3 ) ;
}
F_33 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
F_37 ( & V_2 -> V_3 , V_41 ) ;
continue;
case 'D' : {
static int V_51 ;
struct V_11 * V_52 = F_13 ( V_2 -> V_3 . V_53 ,
struct V_11 , V_19 ) ;
F_38 () ;
F_39 ( L_7 ,
V_51 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_54 ,
V_2 -> V_3 . V_55 ,
V_2 -> V_3 . V_56 ,
V_52 -> V_57 , V_52 -> V_34 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_58 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_59;
}
}
V_59:
F_40 ( & V_2 -> V_3 ) ;
return V_40 ;
}
static char * F_41 ( struct V_13 * V_14 ,
char * V_60 , T_1 V_61 , bool V_62 )
{
int V_63 ;
if ( V_14 -> V_9 . V_64 )
V_63 = F_42 ( V_60 , V_61 , L_8 , V_14 -> V_9 . V_64 -> V_65 ) ;
else
V_63 = F_42 ( V_60 , V_61 , L_9 V_66 , V_14 -> V_67 ) ;
if ( V_62 )
F_42 ( V_60 + V_63 , V_61 - V_63 , L_10 ,
V_14 -> V_9 . V_68 ? V_14 -> V_9 . V_68 -> V_69 -> V_70 : L_11 ) ;
return V_60 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_71 ,
T_2 V_72 , int V_73 ,
unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_19 * V_17 ;
int V_76 = V_74 , V_4 , V_77 = V_73 * V_78 ;
T_2 V_79 , V_80 ;
if ( V_81 . V_82 == V_83 )
V_79 = V_71 -> V_84 ;
else
V_79 = V_72 ;
V_80 = V_79 ;
V_17 = F_11 ( & V_71 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_85 = F_44 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_86 = 0 ;
V_80 -= V_85 ;
F_14 (chain, &child->val, list) {
char V_60 [ 1024 ] , * V_87 ;
const char * V_88 ;
int V_89 ;
bool V_90 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_86 = V_78 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_57 != 0 ) {
-- * V_57 ;
goto V_91;
}
V_87 = NULL ;
V_88 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
if ( V_90 ) {
double V_92 = V_85 * 100.0 / V_79 ;
if ( F_45 ( & V_87 , L_12 , V_92 , V_88 ) < 0 )
V_88 = L_13 ;
else
V_88 = V_87 ;
}
V_89 = V_93 ;
V_4 = V_2 -> V_3 . V_4 - ( V_77 + V_86 + 2 ) ;
if ( F_46 ( & V_2 -> V_3 , V_74 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_89 = V_94 ;
* V_75 = true ;
}
F_47 ( & V_2 -> V_3 , V_89 ) ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
F_49 ( L_14 , V_77 + V_86 ) ;
F_50 ( L_15 , V_24 ) ;
F_49 ( V_88 , V_4 ) ;
free ( V_87 ) ;
if ( ++ V_74 == V_2 -> V_3 . V_54 )
goto V_59;
V_91:
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_95 = V_73 + ( V_86 ? 2 : 1 ) ;
V_74 += F_43 ( V_2 , V_22 , V_79 ,
V_95 , V_74 , V_57 ,
V_75 ) ;
}
if ( V_74 == V_2 -> V_3 . V_54 )
goto V_59;
V_17 = V_27 ;
}
V_59:
return V_74 - V_76 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_73 , unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_13 * V_23 ;
int V_76 = V_74 ,
V_77 = V_73 * V_78 ,
V_4 = V_2 -> V_3 . V_4 - V_77 ;
char V_24 = ' ' ;
F_14 (chain, &node->val, list) {
char V_60 [ 1024 ] , * V_96 ;
int V_89 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_57 != 0 ) {
-- * V_57 ;
continue;
}
V_89 = V_93 ;
if ( F_46 ( & V_2 -> V_3 , V_74 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_89 = V_94 ;
* V_75 = true ;
}
V_96 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
F_47 ( & V_2 -> V_3 , V_89 ) ;
F_49 ( L_14 , V_77 ) ;
F_50 ( L_15 , V_24 ) ;
F_49 ( V_96 , V_4 - 2 ) ;
if ( ++ V_74 == V_2 -> V_3 . V_54 )
goto V_59;
}
if ( V_24 == '-' )
V_74 += F_43 ( V_2 , V_17 ,
V_2 -> V_5 -> V_47 . V_97 ,
V_73 + 1 , V_74 ,
V_57 ,
V_75 ) ;
V_59:
return V_74 - V_76 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
int V_73 , unsigned short V_74 ,
T_3 * V_57 ,
bool * V_75 )
{
struct V_19 * V_20 ;
int V_76 = V_74 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_74 += F_51 ( V_2 , V_17 , V_73 ,
V_74 , V_57 ,
V_75 ) ;
if ( V_74 == V_2 -> V_3 . V_54 )
break;
}
return V_74 - V_76 ;
}
void F_53 ( void )
{
F_54 () ;
V_98 [ V_99 ] . V_89 =
V_100 ;
V_98 [ V_101 ] . V_89 =
V_102 ;
V_98 [ V_103 ] . V_89 =
V_104 ;
V_98 [ V_105 ] . V_89 =
V_106 ;
V_98 [ V_107 ] . V_89 =
V_108 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_11 * V_109 ,
unsigned short V_74 )
{
char V_96 [ 256 ] ;
double V_92 ;
int V_110 , V_63 = 0 ;
int V_4 = V_2 -> V_3 . V_4 ;
char V_24 = ' ' ;
bool V_111 = F_46 ( & V_2 -> V_3 , V_74 ) ;
T_3 V_57 = V_109 -> V_57 ;
bool V_25 = true ;
if ( V_111 ) {
V_2 -> V_33 = V_109 ;
V_2 -> V_32 = & V_109 -> V_9 ;
}
if ( V_112 . V_113 ) {
F_22 ( V_109 ) ;
V_24 = F_7 ( V_109 ) ;
}
if ( V_57 == 0 ) {
struct V_114 V_115 = {
. V_116 = V_96 ,
. V_117 = sizeof( V_96 ) ,
} ;
F_48 ( & V_2 -> V_3 , V_74 , 0 ) ;
for ( V_110 = 0 ; V_110 < V_118 ; V_110 ++ ) {
if ( ! V_98 [ V_110 ] . V_119 )
continue;
if ( ! V_25 ) {
F_50 ( L_16 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_98 [ V_110 ] . V_89 ) {
V_115 . V_120 = & V_92 ;
V_4 -= V_98 [ V_110 ] . V_89 ( & V_115 , V_109 ) ;
F_56 ( & V_2 -> V_3 , V_92 , V_111 ) ;
if ( V_110 == V_99 && V_112 . V_113 ) {
F_50 ( L_15 , V_24 ) ;
V_4 -= 2 ;
}
F_50 ( L_8 , V_96 ) ;
if ( ! V_111 || ! V_2 -> V_3 . V_121 )
F_47 ( & V_2 -> V_3 , V_93 ) ;
} else {
V_4 -= V_98 [ V_110 ] . V_109 ( & V_115 , V_109 ) ;
F_50 ( L_8 , V_96 ) ;
}
}
if ( ! V_2 -> V_3 . V_121 )
V_4 += 1 ;
F_57 ( V_109 , V_96 , sizeof( V_96 ) , V_2 -> V_5 ) ;
F_49 ( V_96 , V_4 ) ;
++ V_74 ;
++ V_63 ;
} else
-- V_57 ;
if ( V_24 == '-' && V_74 != V_2 -> V_3 . V_54 ) {
V_63 += F_52 ( V_2 , & V_109 -> V_31 ,
1 , V_74 , & V_57 ,
& V_111 ) ;
if ( V_111 )
V_2 -> V_33 = V_109 ;
}
return V_63 ;
}
static void F_58 ( struct V_36 * V_2 )
{
if ( V_2 -> V_53 == NULL ) {
struct V_1 * V_122 ;
V_122 = F_59 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_53 = F_11 ( & V_122 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_60 ( struct V_36 * V_2 )
{
unsigned V_74 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_122 = F_59 ( V_2 , struct V_1 , V_3 ) ;
F_58 ( V_2 ) ;
for ( V_20 = V_2 -> V_53 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_123 )
continue;
V_74 += F_55 ( V_122 , V_52 , V_74 ) ;
if ( V_74 == V_2 -> V_54 )
break;
}
return V_74 ;
}
static struct V_19 * F_61 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_52 -> V_123 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_62 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_52 -> V_123 )
return V_20 ;
V_20 = F_63 ( V_20 ) ;
}
return NULL ;
}
static void F_64 ( struct V_36 * V_2 ,
T_3 V_77 , int V_124 )
{
struct V_11 * V_52 ;
struct V_19 * V_20 ;
bool V_25 = true ;
if ( V_2 -> V_6 == 0 )
return;
F_58 ( V_2 ) ;
switch ( V_124 ) {
case V_125 :
V_20 = F_61 ( F_11 ( V_2 -> V_35 ) ) ;
break;
case V_126 :
V_20 = V_2 -> V_53 ;
goto V_127;
case V_128 :
V_20 = F_62 ( F_65 ( V_2 -> V_35 ) ) ;
V_25 = false ;
break;
default:
return;
}
V_52 = F_13 ( V_2 -> V_53 , struct V_11 , V_19 ) ;
V_52 -> V_57 = 0 ;
V_127:
if ( V_77 > 0 ) {
do {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 ) {
T_4 V_80 = V_52 -> V_34 - V_52 -> V_57 ;
if ( V_77 > V_80 ) {
V_77 -= V_80 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 += V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
}
V_20 = F_61 ( F_12 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
-- V_77 ;
V_2 -> V_53 = V_20 ;
} while ( V_77 != 0 );
} else if ( V_77 < 0 ) {
while ( 1 ) {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 ) {
if ( V_25 ) {
if ( - V_77 > V_52 -> V_57 ) {
V_77 += V_52 -> V_57 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 += V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
} else {
if ( - V_77 > V_52 -> V_34 ) {
V_77 += V_52 -> V_34 ;
V_52 -> V_57 = 0 ;
} else {
V_52 -> V_57 = V_52 -> V_34 + V_77 ;
V_77 = 0 ;
V_2 -> V_53 = V_20 ;
break;
}
}
}
V_20 = F_62 ( F_63 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
++ V_77 ;
V_2 -> V_53 = V_20 ;
if ( V_77 == 0 ) {
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_52 -> V_9 . V_7 )
V_52 -> V_57 = V_52 -> V_34 ;
break;
}
V_25 = false ;
}
} else {
V_2 -> V_53 = V_20 ;
V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_52 -> V_57 = 0 ;
}
}
static int F_66 ( struct V_1 * V_2 ,
struct V_16 * V_71 ,
T_2 V_72 , int V_73 ,
T_5 * V_129 )
{
struct V_19 * V_17 ;
int V_77 = V_73 * V_78 ;
T_2 V_79 , V_80 ;
int V_63 = 0 ;
if ( V_81 . V_82 == V_83 )
V_79 = V_71 -> V_84 ;
else
V_79 = V_72 ;
V_80 = V_79 ;
V_17 = F_11 ( & V_71 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_85 = F_44 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_86 = 0 ;
V_80 -= V_85 ;
F_14 (chain, &child->val, list) {
char V_60 [ 1024 ] , * V_87 ;
const char * V_88 ;
bool V_90 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_86 = V_78 ;
V_24 = F_8 ( V_23 ) ;
V_87 = NULL ;
V_88 = F_41 ( V_23 , V_60 , sizeof( V_60 ) ,
V_2 -> V_62 ) ;
if ( V_90 ) {
double V_92 = V_85 * 100.0 / V_79 ;
if ( F_45 ( & V_87 , L_12 , V_92 , V_88 ) < 0 )
V_88 = L_13 ;
else
V_88 = V_87 ;
}
V_63 += fprintf ( V_129 , L_17 , V_77 + V_86 , L_14 , V_24 , V_88 ) ;
free ( V_87 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_95 = V_73 + ( V_86 ? 2 : 1 ) ;
V_63 += F_66 ( V_2 , V_22 , V_79 ,
V_95 , V_129 ) ;
}
V_17 = V_27 ;
}
return V_63 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_73 , T_5 * V_129 )
{
struct V_13 * V_23 ;
int V_77 = V_73 * V_78 ;
char V_24 = ' ' ;
int V_63 = 0 ;
F_14 (chain, &node->val, list) {
char V_60 [ 1024 ] , * V_96 ;
V_24 = F_8 ( V_23 ) ;
V_96 = F_41 ( V_23 , V_60 , sizeof( V_60 ) , V_2 -> V_62 ) ;
V_63 += fprintf ( V_129 , L_17 , V_77 , L_14 , V_24 , V_96 ) ;
}
if ( V_24 == '-' )
V_63 += F_66 ( V_2 , V_17 ,
V_2 -> V_5 -> V_47 . V_97 ,
V_73 + 1 , V_129 ) ;
return V_63 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_73 , T_5 * V_129 )
{
struct V_19 * V_20 ;
int V_63 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_63 += F_67 ( V_2 , V_17 , V_73 , V_129 ) ;
}
return V_63 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_129 )
{
char V_96 [ 8192 ] ;
double V_92 ;
int V_63 = 0 ;
char V_24 = ' ' ;
if ( V_112 . V_113 )
V_24 = F_7 ( V_12 ) ;
F_57 ( V_12 , V_96 , sizeof( V_96 ) , V_2 -> V_5 ) ;
V_92 = ( V_12 -> V_130 . V_131 * 100.0 ) / V_2 -> V_5 -> V_47 . V_97 ;
if ( V_112 . V_113 )
V_63 += fprintf ( V_129 , L_15 , V_24 ) ;
V_63 += fprintf ( V_129 , L_18 , V_92 ) ;
if ( V_112 . V_132 )
V_63 += fprintf ( V_129 , L_19 , V_12 -> V_130 . V_49 ) ;
if ( V_112 . V_133 )
V_63 += fprintf ( V_129 , L_20 V_134 , V_12 -> V_130 . V_131 ) ;
V_63 += fprintf ( V_129 , L_21 , F_70 ( V_96 ) ) ;
if ( V_24 == '-' )
V_63 += F_68 ( V_2 , & V_12 -> V_31 , 1 , V_129 ) ;
return V_63 ;
}
static int F_71 ( struct V_1 * V_2 , T_5 * V_129 )
{
struct V_19 * V_20 = F_61 ( F_11 ( V_2 -> V_3 . V_35 ) ) ;
int V_63 = 0 ;
while ( V_20 ) {
struct V_11 * V_52 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_63 += F_69 ( V_2 , V_52 , V_129 ) ;
V_20 = F_61 ( F_12 ( V_20 ) ) ;
}
return V_63 ;
}
static int F_72 ( struct V_1 * V_2 )
{
char V_135 [ 64 ] ;
T_5 * V_129 ;
while ( 1 ) {
F_42 ( V_135 , sizeof( V_135 ) , L_22 , V_2 -> V_136 ) ;
if ( F_73 ( V_135 , V_137 ) )
break;
if ( ++ V_2 -> V_136 == 8192 ) {
F_39 ( L_23 ) ;
return - 1 ;
}
}
V_129 = fopen ( V_135 , L_24 ) ;
if ( V_129 == NULL ) {
char V_60 [ 64 ] ;
const char * V_138 = F_74 ( V_139 , V_60 , sizeof( V_60 ) ) ;
F_39 ( L_25 , V_135 , V_138 ) ;
return - 1 ;
}
++ V_2 -> V_136 ;
F_71 ( V_2 , V_129 ) ;
fclose ( V_129 ) ;
F_39 ( L_26 , V_135 ) ;
return 0 ;
}
static struct V_1 * F_75 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_76 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_43 = F_60 ;
V_2 -> V_3 . V_140 = F_64 ;
V_2 -> V_3 . V_141 = true ;
if ( V_142 == 1 )
V_2 -> V_143 = V_144 . V_26 . V_27 != NULL ;
else
V_2 -> V_143 = V_145 . V_26 . V_27 != NULL ;
}
return V_2 ;
}
static void F_77 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_78 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_146 * F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_146 ;
}
static int F_33 ( struct V_5 * V_5 , char * V_60 , T_1 V_117 ,
const char * V_37 )
{
char V_147 ;
int V_63 ;
const struct V_69 * V_69 = V_5 -> V_148 ;
const struct V_146 * V_146 = V_5 -> V_149 ;
unsigned long V_150 = V_5 -> V_47 . V_49 [ V_151 ] ;
T_2 V_49 = V_5 -> V_47 . V_97 ;
V_150 = F_80 ( V_150 , & V_147 ) ;
V_63 = F_42 ( V_60 , V_117 ,
L_27 ,
V_150 , V_147 , V_37 , V_49 ) ;
if ( V_5 -> V_152 )
V_63 += snprintf ( V_60 + V_63 , V_117 - V_63 ,
L_28 , V_5 -> V_152 ) ;
if ( V_146 )
V_63 += F_42 ( V_60 + V_63 , V_117 - V_63 ,
L_29 ,
( V_146 -> V_153 ? V_146 -> V_154 : L_30 ) ,
V_146 -> V_155 ) ;
if ( V_69 )
V_63 += F_42 ( V_60 + V_63 , V_117 - V_63 ,
L_31 , V_69 -> V_70 ) ;
return V_63 ;
}
static inline void F_81 ( char * * V_156 , int V_18 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_18 ; ++ V_110 ) {
free ( V_156 [ V_110 ] ) ;
V_156 [ V_110 ] = NULL ;
}
}
static inline bool F_82 ( void * V_45 )
{
return V_45 == NULL ;
}
static int F_83 ( struct V_157 * V_158 , int V_49 ,
const char * V_159 , const char * V_37 ,
bool V_160 ,
struct V_38 * V_39 ,
struct V_161 * V_162 )
{
struct V_5 * V_5 = & V_158 -> V_5 ;
struct V_1 * V_2 = F_75 ( V_5 ) ;
struct V_163 * V_164 ;
struct V_165 * V_166 ;
char * V_156 [ 16 ] ;
int V_167 = 0 ;
int V_40 = - 1 ;
char V_116 [ 64 ] ;
char V_168 [ 64 ] ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
if ( V_2 == NULL )
return - 1 ;
V_166 = F_84 ( 2 ) ;
if ( V_166 == NULL )
goto V_59;
F_85 ( V_159 ) ;
memset ( V_156 , 0 , sizeof( V_156 ) ) ;
while ( 1 ) {
const struct V_146 * V_146 = NULL ;
const struct V_69 * V_69 = NULL ;
int V_169 = 0 ,
V_170 = - 2 , V_171 = - 2 , V_172 = - 2 ,
V_173 = - 2 , V_174 = - 2 , V_175 = - 2 ;
int V_176 = - 2 , V_177 = - 2 , V_178 = - 2 ;
V_167 = 0 ;
V_40 = F_32 ( V_2 , V_37 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_146 = F_79 ( V_2 ) ;
V_69 = V_2 -> V_32 -> V_68 ? V_2 -> V_32 -> V_68 -> V_69 : NULL ;
}
switch ( V_40 ) {
case V_179 :
case V_180 :
if ( V_49 == 1 )
continue;
goto V_181;
case 'a' :
if ( ! V_2 -> V_143 ) {
F_31 ( & V_2 -> V_3 , V_42 * 2 ,
L_32
L_33 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_64 == NULL ||
V_2 -> V_32 -> V_68 -> V_69 -> V_182 )
continue;
goto V_183;
case 'P' :
F_72 ( V_2 ) ;
continue;
case 'd' :
goto V_171;
case 'V' :
V_2 -> V_62 = ! V_2 -> V_62 ;
continue;
case 't' :
goto V_172;
case '/' :
if ( F_86 ( L_34 ,
L_35 ,
V_116 , L_36 ,
V_42 * 2 ) == V_58 ) {
V_5 -> V_184 = * V_116 ? V_116 : NULL ;
F_87 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case 'r' :
if ( F_82 ( V_39 ) )
goto V_185;
continue;
case V_186 :
case 'h' :
case '?' :
F_88 ( & V_2 -> V_3 ,
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54 ) ;
continue;
case V_58 :
case V_187 :
break;
case V_188 : {
const void * V_53 ;
if ( F_89 ( V_166 ) ) {
if ( V_160 )
goto V_181;
continue;
}
V_53 = F_90 ( V_166 ) ;
if ( V_53 == & V_2 -> V_5 -> V_148 )
goto V_189;
if ( V_53 == & V_2 -> V_5 -> V_149 )
goto V_190;
continue;
}
case V_191 :
if ( ! V_160 &&
! F_91 ( & V_2 -> V_3 ,
L_55 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_181;
default:
continue;
}
if ( ! V_2 -> V_143 )
goto V_192;
if ( V_142 == 1 ) {
V_164 = V_2 -> V_33 -> V_163 ;
if ( V_2 -> V_32 != NULL &&
V_164 &&
V_164 -> V_193 . V_64 != NULL &&
! V_164 -> V_193 . V_68 -> V_69 -> V_182 &&
F_45 ( & V_156 [ V_167 ] , L_56 ,
V_164 -> V_193 . V_64 -> V_65 ) > 0 )
V_173 = V_167 ++ ;
if ( V_2 -> V_32 != NULL &&
V_164 &&
V_164 -> V_194 . V_64 != NULL &&
! V_164 -> V_194 . V_68 -> V_69 -> V_182 &&
( V_164 -> V_194 . V_64 != V_164 -> V_193 . V_64 ||
V_164 -> V_194 . V_68 -> V_69 != V_164 -> V_193 . V_68 -> V_69 ) &&
F_45 ( & V_156 [ V_167 ] , L_56 ,
V_164 -> V_194 . V_64 -> V_65 ) > 0 )
V_174 = V_167 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_64 != NULL &&
! V_2 -> V_32 -> V_68 -> V_69 -> V_182 &&
F_45 ( & V_156 [ V_167 ] , L_56 ,
V_2 -> V_32 -> V_64 -> V_65 ) > 0 )
V_170 = V_167 ++ ;
}
if ( V_146 != NULL &&
F_45 ( & V_156 [ V_167 ] , L_57 ,
( V_2 -> V_5 -> V_149 ? L_58 : L_59 ) ,
( V_146 -> V_153 ? V_146 -> V_154 : L_30 ) ,
V_146 -> V_155 ) > 0 )
V_172 = V_167 ++ ;
if ( V_69 != NULL &&
F_45 ( & V_156 [ V_167 ] , L_60 ,
( V_2 -> V_5 -> V_148 ? L_58 : L_59 ) ,
( V_69 -> V_195 ? L_61 : V_69 -> V_70 ) ) > 0 )
V_171 = V_167 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_68 != NULL &&
F_45 ( & V_156 [ V_167 ] , L_62 ) > 0 )
V_175 = V_167 ++ ;
if ( V_2 -> V_33 ) {
struct V_196 * V_64 ;
if ( F_45 ( & V_156 [ V_167 ] , L_63 ,
V_2 -> V_33 -> V_146 -> V_154 ) > 0 )
V_176 = V_167 ++ ;
V_64 = V_2 -> V_33 -> V_9 . V_64 ;
if ( V_64 && V_64 -> V_197 &&
F_45 ( & V_156 [ V_167 ] , L_64 ,
V_64 -> V_65 ) > 0 )
V_177 = V_167 ++ ;
}
if ( F_45 ( & V_156 [ V_167 ] , L_65 ) > 0 )
V_178 = V_167 ++ ;
V_192:
V_156 [ V_167 ++ ] = ( char * ) L_66 ;
V_198:
V_169 = F_93 ( V_167 , V_156 ) ;
if ( V_169 == V_167 - 1 )
break;
if ( V_169 == - 1 ) {
F_81 ( V_156 , V_167 - 1 ) ;
continue;
}
if ( V_169 == V_170 || V_169 == V_174 || V_169 == V_173 ) {
struct V_11 * V_12 ;
int V_138 ;
V_183:
if ( ! V_199 && F_94 ( V_162 ) )
continue;
V_12 = F_78 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_169 == V_173 ) {
V_12 -> V_9 . V_64 = V_12 -> V_163 -> V_193 . V_64 ;
V_12 -> V_9 . V_68 = V_12 -> V_163 -> V_193 . V_68 ;
} else if ( V_169 == V_174 ) {
V_12 -> V_9 . V_64 = V_12 -> V_163 -> V_194 . V_64 ;
V_12 -> V_9 . V_68 = V_12 -> V_163 -> V_194 . V_68 ;
}
V_12 -> V_200 = true ;
V_138 = F_95 ( V_12 , V_158 -> V_201 , V_39 ) ;
V_12 -> V_200 = false ;
if ( ( V_138 == 'q' || V_138 == F_92 ( 'c' ) )
&& V_174 != - 2 && V_173 != - 2 )
goto V_198;
F_36 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_138 )
F_96 ( & V_2 -> V_3 ) ;
} else if ( V_169 == V_175 )
F_97 ( V_2 -> V_32 -> V_68 ) ;
else if ( V_169 == V_171 ) {
V_171:
if ( V_2 -> V_5 -> V_148 ) {
F_98 ( V_166 , & V_2 -> V_5 -> V_148 ) ;
V_189:
F_38 () ;
V_2 -> V_5 -> V_148 = NULL ;
V_202 . V_203 = false ;
} else {
if ( V_69 == NULL )
continue;
F_39 ( L_67 ,
V_69 -> V_195 ? L_61 : V_69 -> V_70 ) ;
V_2 -> V_5 -> V_148 = V_69 ;
V_202 . V_203 = true ;
F_99 ( V_166 , & V_2 -> V_5 -> V_148 ) ;
}
F_100 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_169 == V_172 ) {
V_172:
if ( V_2 -> V_5 -> V_149 ) {
F_98 ( V_166 , & V_2 -> V_5 -> V_149 ) ;
V_190:
F_38 () ;
V_2 -> V_5 -> V_149 = NULL ;
V_204 . V_203 = false ;
} else {
F_39 ( L_68 ,
V_146 -> V_153 ? V_146 -> V_154 : L_30 ,
V_146 -> V_155 ) ;
V_2 -> V_5 -> V_149 = V_146 ;
V_204 . V_203 = true ;
F_99 ( V_166 , & V_2 -> V_5 -> V_149 ) ;
}
F_101 ( V_5 ) ;
F_3 ( V_2 ) ;
}
else if ( V_169 == V_178 || V_169 == V_176 ||
V_169 == V_177 ) {
V_185:
memset ( V_168 , 0 , 64 ) ;
if ( V_169 == V_176 )
sprintf ( V_168 , L_69 , V_2 -> V_33 -> V_146 -> V_154 ) ;
if ( V_169 == V_177 )
sprintf ( V_168 , L_70 , V_2 -> V_33 -> V_9 . V_64 -> V_65 ) ;
F_102 ( V_168 ) ;
}
}
V_181:
F_103 ( V_166 ) ;
V_59:
F_77 ( V_2 ) ;
F_81 ( V_156 , V_167 - 1 ) ;
return V_40 ;
}
static void F_104 ( struct V_36 * V_2 ,
void * V_109 , int V_74 )
{
struct V_205 * V_206 = F_59 ( V_2 ,
struct V_205 , V_3 ) ;
struct V_157 * V_158 = F_105 ( V_109 , struct V_157 , V_17 ) ;
bool V_111 = F_46 ( V_2 , V_74 ) ;
unsigned long V_49 = V_158 -> V_5 . V_47 . V_49 [ V_151 ] ;
const char * V_37 = F_106 ( V_158 ) ;
char V_60 [ 256 ] , V_147 ;
const char * V_207 = L_14 ;
T_1 V_63 ;
F_47 ( V_2 , V_111 ? V_94 :
V_93 ) ;
V_49 = F_80 ( V_49 , & V_147 ) ;
V_63 = F_42 ( V_60 , sizeof( V_60 ) , L_71 , V_49 ,
V_147 , V_147 == ' ' ? L_30 : L_14 , V_37 ) ;
F_50 ( L_8 , V_60 ) ;
V_49 = V_158 -> V_5 . V_47 . V_49 [ V_50 ] ;
if ( V_49 != 0 ) {
V_206 -> V_208 = true ;
if ( ! V_111 )
F_47 ( V_2 , V_209 ) ;
V_49 = F_80 ( V_49 , & V_147 ) ;
V_63 += F_42 ( V_60 , sizeof( V_60 ) , L_72 ,
V_49 , V_147 , V_147 == ' ' ? L_30 : L_14 ) ;
V_207 = V_60 ;
}
F_49 ( V_207 , V_2 -> V_4 - V_63 ) ;
if ( V_111 )
V_206 -> V_32 = V_158 ;
}
static int F_107 ( struct V_205 * V_206 ,
int V_49 , const char * V_210 ,
struct V_38 * V_39 )
{
struct V_211 * V_212 = V_206 -> V_3 . V_213 ;
struct V_157 * V_214 ;
const char * V_37 , * V_41 = L_73 ;
int V_42 = V_39 ? V_39 -> V_43 : 0 ;
int V_40 ;
if ( F_34 ( & V_206 -> V_3 , V_41 ,
L_74 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_35 ( & V_206 -> V_3 , V_42 ) ;
switch ( V_40 ) {
case V_44 :
V_39 -> V_45 ( V_39 -> V_46 ) ;
if ( ! V_206 -> V_215 && V_206 -> V_208 ) {
F_30 ( & V_206 -> V_3 ) ;
V_206 -> V_215 = true ;
}
continue;
case V_187 :
case V_58 :
if ( ! V_206 -> V_32 )
continue;
V_214 = V_206 -> V_32 ;
V_216:
F_108 ( V_212 , V_214 ) ;
if ( V_39 )
V_39 -> V_45 ( V_39 -> V_46 ) ;
V_37 = F_106 ( V_214 ) ;
V_40 = F_83 ( V_214 , V_49 , V_210 ,
V_37 , true , V_39 ,
V_206 -> V_162 ) ;
F_37 ( & V_206 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_179 :
if ( V_214 -> V_17 . V_27 == & V_212 -> V_35 )
V_214 = F_105 ( V_212 -> V_35 . V_27 , struct V_157 , V_17 ) ;
else
V_214 = F_105 ( V_214 -> V_17 . V_27 , struct V_157 , V_17 ) ;
goto V_216;
case V_180 :
if ( V_214 -> V_17 . V_217 == & V_212 -> V_35 )
V_214 = F_105 ( V_212 -> V_35 . V_217 , struct V_157 , V_17 ) ;
else
V_214 = F_105 ( V_214 -> V_17 . V_217 , struct V_157 , V_17 ) ;
goto V_216;
case V_191 :
if ( ! F_91 ( & V_206 -> V_3 ,
L_55 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_59;
default:
continue;
}
case V_188 :
continue;
case V_191 :
if ( ! F_91 ( & V_206 -> V_3 ,
L_55 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_59;
default:
continue;
}
}
V_59:
F_40 ( & V_206 -> V_3 ) ;
return V_40 ;
}
static int F_109 ( struct V_211 * V_212 ,
const char * V_210 ,
struct V_38 * V_39 ,
struct V_161 * V_162 )
{
struct V_157 * V_214 ;
struct V_205 V_206 = {
. V_3 = {
. V_35 = & V_212 -> V_35 ,
. V_43 = V_218 ,
. V_140 = V_219 ,
. V_220 = F_104 ,
. V_6 = V_212 -> V_6 ,
. V_213 = V_212 ,
} ,
. V_162 = V_162 ,
} ;
F_85 ( L_75 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_106 ( V_214 ) ;
T_1 V_221 = strlen ( V_37 ) + 7 ;
if ( V_206 . V_3 . V_4 < V_221 )
V_206 . V_3 . V_4 = V_221 ;
}
return F_107 ( & V_206 , V_212 -> V_6 , V_210 , V_39 ) ;
}
int F_110 ( struct V_211 * V_212 , const char * V_210 ,
struct V_38 * V_39 ,
struct V_161 * V_162 )
{
if ( V_212 -> V_6 == 1 ) {
struct V_157 * V_25 = F_105 ( V_212 -> V_35 . V_27 ,
struct V_157 , V_17 ) ;
const char * V_37 = F_106 ( V_25 ) ;
return F_83 ( V_25 , V_212 -> V_6 , V_210 ,
V_37 , false , V_39 , V_162 ) ;
}
return F_109 ( V_212 , V_210 , V_39 , V_162 ) ;
}
