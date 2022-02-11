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
void (* F_33)( void * V_38 ) , void * V_38 , int V_39 )
{
int V_40 ;
char V_41 [ 160 ] ;
V_2 -> V_3 . V_35 = & V_2 -> V_5 -> V_35 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_1 ( V_2 ) ;
F_34 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
if ( F_35 ( & V_2 -> V_3 , V_41 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_36 ( & V_2 -> V_3 , V_39 ) ;
switch ( V_40 ) {
case V_42 :
F_33 ( V_38 ) ;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_2 -> V_5 -> V_43 . V_44 !=
V_2 -> V_5 -> V_43 . V_45 [ V_46 ] ) {
V_2 -> V_5 -> V_43 . V_44 =
V_2 -> V_5 -> V_43 . V_45 [ V_46 ] ;
F_30 ( & V_2 -> V_3 ) ;
}
F_34 ( V_2 -> V_5 , V_41 , sizeof( V_41 ) , V_37 ) ;
F_38 ( & V_2 -> V_3 , V_41 ) ;
continue;
case 'D' : {
static int V_47 ;
struct V_11 * V_48 = F_13 ( V_2 -> V_3 . V_49 ,
struct V_11 , V_19 ) ;
F_39 () ;
F_40 ( L_7 ,
V_47 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_50 ,
V_2 -> V_3 . V_51 ,
V_2 -> V_3 . V_52 ,
V_48 -> V_53 , V_48 -> V_34 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_54 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_55;
}
}
V_55:
F_41 ( & V_2 -> V_3 ) ;
return V_40 ;
}
static char * F_42 ( struct V_13 * V_14 ,
char * V_56 , T_1 V_57 , bool V_58 )
{
int V_59 ;
if ( V_14 -> V_9 . V_60 )
V_59 = F_43 ( V_56 , V_57 , L_8 , V_14 -> V_9 . V_60 -> V_61 ) ;
else
V_59 = F_43 ( V_56 , V_57 , L_9 V_62 , V_14 -> V_63 ) ;
if ( V_58 )
F_43 ( V_56 + V_59 , V_57 - V_59 , L_10 ,
V_14 -> V_9 . V_64 ? V_14 -> V_9 . V_64 -> V_65 -> V_66 : L_11 ) ;
return V_56 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_67 ,
T_2 V_68 , int V_69 ,
unsigned short V_70 ,
T_3 * V_53 ,
bool * V_71 )
{
struct V_19 * V_17 ;
int V_72 = V_70 , V_4 , V_73 = V_69 * V_74 ;
T_2 V_75 , V_76 ;
if ( V_77 . V_78 == V_79 )
V_75 = V_67 -> V_80 ;
else
V_75 = V_68 ;
V_76 = V_75 ;
V_17 = F_11 ( & V_67 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_81 = F_45 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_82 = 0 ;
V_76 -= V_81 ;
F_14 (chain, &child->val, list) {
char V_56 [ 1024 ] , * V_83 ;
const char * V_84 ;
int V_85 ;
bool V_86 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_82 = V_74 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_53 != 0 ) {
-- * V_53 ;
goto V_87;
}
V_83 = NULL ;
V_84 = F_42 ( V_23 , V_56 , sizeof( V_56 ) ,
V_2 -> V_58 ) ;
if ( V_86 ) {
double V_88 = V_81 * 100.0 / V_75 ;
if ( F_46 ( & V_83 , L_12 , V_88 , V_84 ) < 0 )
V_84 = L_13 ;
else
V_84 = V_83 ;
}
V_85 = V_89 ;
V_4 = V_2 -> V_3 . V_4 - ( V_73 + V_82 + 2 ) ;
if ( F_47 ( & V_2 -> V_3 , V_70 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_85 = V_90 ;
* V_71 = true ;
}
F_48 ( & V_2 -> V_3 , V_85 ) ;
F_49 ( & V_2 -> V_3 , V_70 , 0 ) ;
F_50 ( L_14 , V_73 + V_82 ) ;
F_51 ( L_15 , V_24 ) ;
F_50 ( V_84 , V_4 ) ;
free ( V_83 ) ;
if ( ++ V_70 == V_2 -> V_3 . V_50 )
goto V_55;
V_87:
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_91 = V_69 + ( V_82 ? 2 : 1 ) ;
V_70 += F_44 ( V_2 , V_22 , V_75 ,
V_91 , V_70 , V_53 ,
V_71 ) ;
}
if ( V_70 == V_2 -> V_3 . V_50 )
goto V_55;
V_17 = V_27 ;
}
V_55:
return V_70 - V_72 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_69 , unsigned short V_70 ,
T_3 * V_53 ,
bool * V_71 )
{
struct V_13 * V_23 ;
int V_72 = V_70 ,
V_73 = V_69 * V_74 ,
V_4 = V_2 -> V_3 . V_4 - V_73 ;
char V_24 = ' ' ;
F_14 (chain, &node->val, list) {
char V_56 [ 1024 ] , * V_92 ;
int V_85 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_53 != 0 ) {
-- * V_53 ;
continue;
}
V_85 = V_89 ;
if ( F_47 ( & V_2 -> V_3 , V_70 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_85 = V_90 ;
* V_71 = true ;
}
V_92 = F_42 ( V_23 , V_56 , sizeof( V_56 ) ,
V_2 -> V_58 ) ;
F_49 ( & V_2 -> V_3 , V_70 , 0 ) ;
F_48 ( & V_2 -> V_3 , V_85 ) ;
F_50 ( L_14 , V_73 ) ;
F_51 ( L_15 , V_24 ) ;
F_50 ( V_92 , V_4 - 2 ) ;
if ( ++ V_70 == V_2 -> V_3 . V_50 )
goto V_55;
}
if ( V_24 == '-' )
V_70 += F_44 ( V_2 , V_17 ,
V_2 -> V_5 -> V_43 . V_93 ,
V_69 + 1 , V_70 ,
V_53 ,
V_71 ) ;
V_55:
return V_70 - V_72 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
int V_69 , unsigned short V_70 ,
T_3 * V_53 ,
bool * V_71 )
{
struct V_19 * V_20 ;
int V_72 = V_70 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_70 += F_52 ( V_2 , V_17 , V_69 ,
V_70 , V_53 ,
V_71 ) ;
if ( V_70 == V_2 -> V_3 . V_50 )
break;
}
return V_70 - V_72 ;
}
void F_54 ( void )
{
F_55 () ;
V_94 [ V_95 ] . V_85 =
V_96 ;
V_94 [ V_97 ] . V_85 =
V_98 ;
V_94 [ V_99 ] . V_85 =
V_100 ;
V_94 [ V_101 ] . V_85 =
V_102 ;
V_94 [ V_103 ] . V_85 =
V_104 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_11 * V_105 ,
unsigned short V_70 )
{
char V_92 [ 256 ] ;
double V_88 ;
int V_106 , V_59 = 0 ;
int V_4 = V_2 -> V_3 . V_4 ;
char V_24 = ' ' ;
bool V_107 = F_47 ( & V_2 -> V_3 , V_70 ) ;
T_3 V_53 = V_105 -> V_53 ;
bool V_25 = true ;
if ( V_107 ) {
V_2 -> V_33 = V_105 ;
V_2 -> V_32 = & V_105 -> V_9 ;
}
if ( V_108 . V_109 ) {
F_22 ( V_105 ) ;
V_24 = F_7 ( V_105 ) ;
}
if ( V_53 == 0 ) {
struct V_110 V_111 = {
. V_112 = V_92 ,
. V_113 = sizeof( V_92 ) ,
} ;
F_49 ( & V_2 -> V_3 , V_70 , 0 ) ;
for ( V_106 = 0 ; V_106 < V_114 ; V_106 ++ ) {
if ( ! V_94 [ V_106 ] . V_115 )
continue;
if ( ! V_25 ) {
F_51 ( L_16 ) ;
V_4 -= 2 ;
}
V_25 = false ;
if ( V_94 [ V_106 ] . V_85 ) {
V_111 . V_116 = & V_88 ;
V_4 -= V_94 [ V_106 ] . V_85 ( & V_111 , V_105 ) ;
F_57 ( & V_2 -> V_3 , V_88 , V_107 ) ;
if ( V_106 == V_95 && V_108 . V_109 ) {
F_51 ( L_15 , V_24 ) ;
V_4 -= 2 ;
}
F_51 ( L_8 , V_92 ) ;
if ( ! V_107 || ! V_2 -> V_3 . V_117 )
F_48 ( & V_2 -> V_3 , V_89 ) ;
} else {
V_4 -= V_94 [ V_106 ] . V_105 ( & V_111 , V_105 ) ;
F_51 ( L_8 , V_92 ) ;
}
}
if ( ! V_2 -> V_3 . V_117 )
V_4 += 1 ;
F_58 ( V_105 , V_92 , sizeof( V_92 ) , V_2 -> V_5 ) ;
F_50 ( V_92 , V_4 ) ;
++ V_70 ;
++ V_59 ;
} else
-- V_53 ;
if ( V_24 == '-' && V_70 != V_2 -> V_3 . V_50 ) {
V_59 += F_53 ( V_2 , & V_105 -> V_31 ,
1 , V_70 , & V_53 ,
& V_107 ) ;
if ( V_107 )
V_2 -> V_33 = V_105 ;
}
return V_59 ;
}
static void F_59 ( struct V_36 * V_2 )
{
if ( V_2 -> V_49 == NULL ) {
struct V_1 * V_118 ;
V_118 = F_60 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_49 = F_11 ( & V_118 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_61 ( struct V_36 * V_2 )
{
unsigned V_70 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_118 = F_60 ( V_2 , struct V_1 , V_3 ) ;
F_59 ( V_2 ) ;
for ( V_20 = V_2 -> V_49 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_119 )
continue;
V_70 += F_56 ( V_118 , V_48 , V_70 ) ;
if ( V_70 == V_2 -> V_50 )
break;
}
return V_70 ;
}
static struct V_19 * F_62 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_48 -> V_119 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_63 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_48 -> V_119 )
return V_20 ;
V_20 = F_64 ( V_20 ) ;
}
return NULL ;
}
static void F_65 ( struct V_36 * V_2 ,
T_3 V_73 , int V_120 )
{
struct V_11 * V_48 ;
struct V_19 * V_20 ;
bool V_25 = true ;
if ( V_2 -> V_6 == 0 )
return;
F_59 ( V_2 ) ;
switch ( V_120 ) {
case V_121 :
V_20 = F_62 ( F_11 ( V_2 -> V_35 ) ) ;
break;
case V_122 :
V_20 = V_2 -> V_49 ;
goto V_123;
case V_124 :
V_20 = F_63 ( F_66 ( V_2 -> V_35 ) ) ;
V_25 = false ;
break;
default:
return;
}
V_48 = F_13 ( V_2 -> V_49 , struct V_11 , V_19 ) ;
V_48 -> V_53 = 0 ;
V_123:
if ( V_73 > 0 ) {
do {
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_9 . V_7 ) {
T_4 V_76 = V_48 -> V_34 - V_48 -> V_53 ;
if ( V_73 > V_76 ) {
V_73 -= V_76 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 += V_73 ;
V_73 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
}
V_20 = F_62 ( F_12 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
-- V_73 ;
V_2 -> V_49 = V_20 ;
} while ( V_73 != 0 );
} else if ( V_73 < 0 ) {
while ( 1 ) {
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_9 . V_7 ) {
if ( V_25 ) {
if ( - V_73 > V_48 -> V_53 ) {
V_73 += V_48 -> V_53 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 += V_73 ;
V_73 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
} else {
if ( - V_73 > V_48 -> V_34 ) {
V_73 += V_48 -> V_34 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 = V_48 -> V_34 + V_73 ;
V_73 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
}
}
V_20 = F_63 ( F_64 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
++ V_73 ;
V_2 -> V_49 = V_20 ;
if ( V_73 == 0 ) {
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_9 . V_7 )
V_48 -> V_53 = V_48 -> V_34 ;
break;
}
V_25 = false ;
}
} else {
V_2 -> V_49 = V_20 ;
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_48 -> V_53 = 0 ;
}
}
static int F_67 ( struct V_1 * V_2 ,
struct V_16 * V_67 ,
T_2 V_68 , int V_69 ,
T_5 * V_125 )
{
struct V_19 * V_17 ;
int V_73 = V_69 * V_74 ;
T_2 V_75 , V_76 ;
int V_59 = 0 ;
if ( V_77 . V_78 == V_79 )
V_75 = V_67 -> V_80 ;
else
V_75 = V_68 ;
V_76 = V_75 ;
V_17 = F_11 ( & V_67 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_81 = F_45 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_82 = 0 ;
V_76 -= V_81 ;
F_14 (chain, &child->val, list) {
char V_56 [ 1024 ] , * V_83 ;
const char * V_84 ;
bool V_86 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_82 = V_74 ;
V_24 = F_8 ( V_23 ) ;
V_83 = NULL ;
V_84 = F_42 ( V_23 , V_56 , sizeof( V_56 ) ,
V_2 -> V_58 ) ;
if ( V_86 ) {
double V_88 = V_81 * 100.0 / V_75 ;
if ( F_46 ( & V_83 , L_12 , V_88 , V_84 ) < 0 )
V_84 = L_13 ;
else
V_84 = V_83 ;
}
V_59 += fprintf ( V_125 , L_17 , V_73 + V_82 , L_14 , V_24 , V_84 ) ;
free ( V_83 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_91 = V_69 + ( V_82 ? 2 : 1 ) ;
V_59 += F_67 ( V_2 , V_22 , V_75 ,
V_91 , V_125 ) ;
}
V_17 = V_27 ;
}
return V_59 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_69 , T_5 * V_125 )
{
struct V_13 * V_23 ;
int V_73 = V_69 * V_74 ;
char V_24 = ' ' ;
int V_59 = 0 ;
F_14 (chain, &node->val, list) {
char V_56 [ 1024 ] , * V_92 ;
V_24 = F_8 ( V_23 ) ;
V_92 = F_42 ( V_23 , V_56 , sizeof( V_56 ) , V_2 -> V_58 ) ;
V_59 += fprintf ( V_125 , L_17 , V_73 , L_14 , V_24 , V_92 ) ;
}
if ( V_24 == '-' )
V_59 += F_67 ( V_2 , V_17 ,
V_2 -> V_5 -> V_43 . V_93 ,
V_69 + 1 , V_125 ) ;
return V_59 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_69 , T_5 * V_125 )
{
struct V_19 * V_20 ;
int V_59 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_59 += F_68 ( V_2 , V_17 , V_69 , V_125 ) ;
}
return V_59 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_125 )
{
char V_92 [ 8192 ] ;
double V_88 ;
int V_59 = 0 ;
char V_24 = ' ' ;
if ( V_108 . V_109 )
V_24 = F_7 ( V_12 ) ;
F_58 ( V_12 , V_92 , sizeof( V_92 ) , V_2 -> V_5 ) ;
V_88 = ( V_12 -> V_126 . V_127 * 100.0 ) / V_2 -> V_5 -> V_43 . V_93 ;
if ( V_108 . V_109 )
V_59 += fprintf ( V_125 , L_15 , V_24 ) ;
V_59 += fprintf ( V_125 , L_18 , V_88 ) ;
if ( V_108 . V_128 )
V_59 += fprintf ( V_125 , L_19 , V_12 -> V_126 . V_45 ) ;
if ( V_108 . V_129 )
V_59 += fprintf ( V_125 , L_20 V_130 , V_12 -> V_126 . V_127 ) ;
V_59 += fprintf ( V_125 , L_21 , F_71 ( V_92 ) ) ;
if ( V_24 == '-' )
V_59 += F_69 ( V_2 , & V_12 -> V_31 , 1 , V_125 ) ;
return V_59 ;
}
static int F_72 ( struct V_1 * V_2 , T_5 * V_125 )
{
struct V_19 * V_20 = F_62 ( F_11 ( V_2 -> V_3 . V_35 ) ) ;
int V_59 = 0 ;
while ( V_20 ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_59 += F_70 ( V_2 , V_48 , V_125 ) ;
V_20 = F_62 ( F_12 ( V_20 ) ) ;
}
return V_59 ;
}
static int F_73 ( struct V_1 * V_2 )
{
char V_131 [ 64 ] ;
T_5 * V_125 ;
while ( 1 ) {
F_43 ( V_131 , sizeof( V_131 ) , L_22 , V_2 -> V_132 ) ;
if ( F_74 ( V_131 , V_133 ) )
break;
if ( ++ V_2 -> V_132 == 8192 ) {
F_40 ( L_23 ) ;
return - 1 ;
}
}
V_125 = fopen ( V_131 , L_24 ) ;
if ( V_125 == NULL ) {
char V_56 [ 64 ] ;
const char * V_134 = F_75 ( V_135 , V_56 , sizeof( V_56 ) ) ;
F_40 ( L_25 , V_131 , V_134 ) ;
return - 1 ;
}
++ V_2 -> V_132 ;
F_72 ( V_2 , V_125 ) ;
fclose ( V_125 ) ;
F_40 ( L_26 , V_131 ) ;
return 0 ;
}
static struct V_1 * F_76 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_77 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_136 = F_61 ;
V_2 -> V_3 . V_137 = F_65 ;
V_2 -> V_3 . V_138 = true ;
if ( V_139 == 1 )
V_2 -> V_140 = V_141 . V_26 . V_27 != NULL ;
else
V_2 -> V_140 = V_142 . V_26 . V_27 != NULL ;
}
return V_2 ;
}
static void F_78 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_143 * F_80 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_143 ;
}
static int F_34 ( struct V_5 * V_5 , char * V_56 , T_1 V_113 ,
const char * V_37 )
{
char V_144 ;
int V_59 ;
const struct V_65 * V_65 = V_5 -> V_145 ;
const struct V_143 * V_143 = V_5 -> V_146 ;
unsigned long V_147 = V_5 -> V_43 . V_45 [ V_148 ] ;
T_2 V_45 = V_5 -> V_43 . V_93 ;
V_147 = F_81 ( V_147 , & V_144 ) ;
V_59 = F_43 ( V_56 , V_113 ,
L_27 ,
V_147 , V_144 , V_37 , V_45 ) ;
if ( V_5 -> V_149 )
V_59 += snprintf ( V_56 + V_59 , V_113 - V_59 ,
L_28 , V_5 -> V_149 ) ;
if ( V_143 )
V_59 += F_43 ( V_56 + V_59 , V_113 - V_59 ,
L_29 ,
( V_143 -> V_150 ? V_143 -> V_151 : L_30 ) ,
V_143 -> V_152 ) ;
if ( V_65 )
V_59 += F_43 ( V_56 + V_59 , V_113 - V_59 ,
L_31 , V_65 -> V_66 ) ;
return V_59 ;
}
static inline void F_82 ( char * * V_153 , int V_18 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_18 ; ++ V_106 ) {
free ( V_153 [ V_106 ] ) ;
V_153 [ V_106 ] = NULL ;
}
}
static int F_83 ( struct V_154 * V_155 , int V_45 ,
const char * V_156 , const char * V_37 ,
bool V_157 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_5 * V_5 = & V_155 -> V_5 ;
struct V_1 * V_2 = F_76 ( V_5 ) ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
char * V_153 [ 16 ] ;
int V_162 = 0 ;
int V_40 = - 1 ;
char V_112 [ 64 ] ;
if ( V_2 == NULL )
return - 1 ;
V_161 = F_84 ( 2 ) ;
if ( V_161 == NULL )
goto V_55;
F_85 ( V_156 ) ;
memset ( V_153 , 0 , sizeof( V_153 ) ) ;
while ( 1 ) {
const struct V_143 * V_143 = NULL ;
const struct V_65 * V_65 = NULL ;
int V_163 = 0 ,
V_164 = - 2 , V_165 = - 2 , V_166 = - 2 ,
V_167 = - 2 , V_168 = - 2 , V_169 = - 2 ;
V_162 = 0 ;
V_40 = F_32 ( V_2 , V_37 , F_33 , V_38 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_143 = F_80 ( V_2 ) ;
V_65 = V_2 -> V_32 -> V_64 ? V_2 -> V_32 -> V_64 -> V_65 : NULL ;
}
switch ( V_40 ) {
case V_170 :
case V_171 :
if ( V_45 == 1 )
continue;
goto V_172;
case 'a' :
if ( ! V_2 -> V_140 ) {
F_31 ( & V_2 -> V_3 , V_39 * 2 ,
L_32
L_33 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_60 == NULL ||
V_2 -> V_32 -> V_64 -> V_65 -> V_173 )
continue;
goto V_174;
case 'P' :
F_73 ( V_2 ) ;
continue;
case 'd' :
goto V_165;
case 'V' :
V_2 -> V_58 = ! V_2 -> V_58 ;
continue;
case 't' :
goto V_166;
case '/' :
if ( F_86 ( L_34 ,
L_35 ,
V_112 , L_36 ,
V_39 * 2 ) == V_54 ) {
V_5 -> V_175 = * V_112 ? V_112 : NULL ;
F_87 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case V_176 :
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
L_53 ) ;
continue;
case V_54 :
case V_177 :
break;
case V_178 : {
const void * V_49 ;
if ( F_89 ( V_161 ) ) {
if ( V_157 )
goto V_172;
continue;
}
V_49 = F_90 ( V_161 ) ;
if ( V_49 == & V_2 -> V_5 -> V_145 )
goto V_179;
if ( V_49 == & V_2 -> V_5 -> V_146 )
goto V_180;
continue;
}
case V_181 :
if ( ! V_157 &&
! F_91 ( & V_2 -> V_3 ,
L_54 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_172;
default:
continue;
}
if ( ! V_2 -> V_140 )
goto V_182;
if ( V_139 == 1 ) {
V_159 = V_2 -> V_33 -> V_158 ;
if ( V_2 -> V_32 != NULL &&
V_159 &&
V_159 -> V_183 . V_60 != NULL &&
! V_159 -> V_183 . V_64 -> V_65 -> V_173 &&
F_46 ( & V_153 [ V_162 ] , L_55 ,
V_159 -> V_183 . V_60 -> V_61 ) > 0 )
V_167 = V_162 ++ ;
if ( V_2 -> V_32 != NULL &&
V_159 &&
V_159 -> V_184 . V_60 != NULL &&
! V_159 -> V_184 . V_64 -> V_65 -> V_173 &&
( V_159 -> V_184 . V_60 != V_159 -> V_183 . V_60 ||
V_159 -> V_184 . V_64 -> V_65 != V_159 -> V_183 . V_64 -> V_65 ) &&
F_46 ( & V_153 [ V_162 ] , L_55 ,
V_159 -> V_184 . V_60 -> V_61 ) > 0 )
V_168 = V_162 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_60 != NULL &&
! V_2 -> V_32 -> V_64 -> V_65 -> V_173 &&
F_46 ( & V_153 [ V_162 ] , L_55 ,
V_2 -> V_32 -> V_60 -> V_61 ) > 0 )
V_164 = V_162 ++ ;
}
if ( V_143 != NULL &&
F_46 ( & V_153 [ V_162 ] , L_56 ,
( V_2 -> V_5 -> V_146 ? L_57 : L_58 ) ,
( V_143 -> V_150 ? V_143 -> V_151 : L_30 ) ,
V_143 -> V_152 ) > 0 )
V_166 = V_162 ++ ;
if ( V_65 != NULL &&
F_46 ( & V_153 [ V_162 ] , L_59 ,
( V_2 -> V_5 -> V_145 ? L_57 : L_58 ) ,
( V_65 -> V_185 ? L_60 : V_65 -> V_66 ) ) > 0 )
V_165 = V_162 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_64 != NULL &&
F_46 ( & V_153 [ V_162 ] , L_61 ) > 0 )
V_169 = V_162 ++ ;
V_182:
V_153 [ V_162 ++ ] = ( char * ) L_62 ;
V_186:
V_163 = F_93 ( V_162 , V_153 ) ;
if ( V_163 == V_162 - 1 )
break;
if ( V_163 == - 1 ) {
F_82 ( V_153 , V_162 - 1 ) ;
continue;
}
if ( V_163 == V_164 || V_163 == V_168 || V_163 == V_167 ) {
struct V_11 * V_12 ;
int V_134 ;
V_174:
V_12 = F_79 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_163 == V_167 ) {
V_12 -> V_9 . V_60 = V_12 -> V_158 -> V_183 . V_60 ;
V_12 -> V_9 . V_64 = V_12 -> V_158 -> V_183 . V_64 ;
} else if ( V_163 == V_168 ) {
V_12 -> V_9 . V_60 = V_12 -> V_158 -> V_184 . V_60 ;
V_12 -> V_9 . V_64 = V_12 -> V_158 -> V_184 . V_64 ;
}
V_12 -> V_187 = true ;
V_134 = F_94 ( V_12 , V_155 -> V_188 ,
F_33 , V_38 , V_39 ) ;
V_12 -> V_187 = false ;
if ( ( V_134 == 'q' || V_134 == F_92 ( 'c' ) )
&& V_168 != - 2 && V_167 != - 2 )
goto V_186;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_134 )
F_95 ( & V_2 -> V_3 ) ;
} else if ( V_163 == V_169 )
F_96 ( V_2 -> V_32 -> V_64 ) ;
else if ( V_163 == V_165 ) {
V_165:
if ( V_2 -> V_5 -> V_145 ) {
F_97 ( V_161 , & V_2 -> V_5 -> V_145 ) ;
V_179:
F_39 () ;
V_2 -> V_5 -> V_145 = NULL ;
V_189 . V_190 = false ;
} else {
if ( V_65 == NULL )
continue;
F_40 ( L_63 ,
V_65 -> V_185 ? L_60 : V_65 -> V_66 ) ;
V_2 -> V_5 -> V_145 = V_65 ;
V_189 . V_190 = true ;
F_98 ( V_161 , & V_2 -> V_5 -> V_145 ) ;
}
F_99 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_163 == V_166 ) {
V_166:
if ( V_2 -> V_5 -> V_146 ) {
F_97 ( V_161 , & V_2 -> V_5 -> V_146 ) ;
V_180:
F_39 () ;
V_2 -> V_5 -> V_146 = NULL ;
V_191 . V_190 = false ;
} else {
F_40 ( L_64 ,
V_143 -> V_150 ? V_143 -> V_151 : L_30 ,
V_143 -> V_152 ) ;
V_2 -> V_5 -> V_146 = V_143 ;
V_191 . V_190 = true ;
F_98 ( V_161 , & V_2 -> V_5 -> V_146 ) ;
}
F_100 ( V_5 ) ;
F_3 ( V_2 ) ;
}
}
V_172:
F_101 ( V_161 ) ;
V_55:
F_78 ( V_2 ) ;
F_82 ( V_153 , V_162 - 1 ) ;
return V_40 ;
}
static void F_102 ( struct V_36 * V_2 ,
void * V_105 , int V_70 )
{
struct V_192 * V_193 = F_60 ( V_2 ,
struct V_192 , V_3 ) ;
struct V_154 * V_155 = F_103 ( V_105 , struct V_154 , V_17 ) ;
bool V_107 = F_47 ( V_2 , V_70 ) ;
unsigned long V_45 = V_155 -> V_5 . V_43 . V_45 [ V_148 ] ;
const char * V_37 = F_104 ( V_155 ) ;
char V_56 [ 256 ] , V_144 ;
const char * V_194 = L_14 ;
T_1 V_59 ;
F_48 ( V_2 , V_107 ? V_90 :
V_89 ) ;
V_45 = F_81 ( V_45 , & V_144 ) ;
V_59 = F_43 ( V_56 , sizeof( V_56 ) , L_65 , V_45 ,
V_144 , V_144 == ' ' ? L_30 : L_14 , V_37 ) ;
F_51 ( L_8 , V_56 ) ;
V_45 = V_155 -> V_5 . V_43 . V_45 [ V_46 ] ;
if ( V_45 != 0 ) {
V_193 -> V_195 = true ;
if ( ! V_107 )
F_48 ( V_2 , V_196 ) ;
V_45 = F_81 ( V_45 , & V_144 ) ;
V_59 += F_43 ( V_56 , sizeof( V_56 ) , L_66 ,
V_45 , V_144 , V_144 == ' ' ? L_30 : L_14 ) ;
V_194 = V_56 ;
}
F_50 ( V_194 , V_2 -> V_4 - V_59 ) ;
if ( V_107 )
V_193 -> V_32 = V_155 ;
}
static int F_105 ( struct V_192 * V_193 ,
int V_45 , const char * V_197 ,
void (* F_33)( void * V_38 ) , void * V_38 , int V_39 )
{
struct V_198 * V_199 = V_193 -> V_3 . V_200 ;
struct V_154 * V_201 ;
const char * V_37 , * V_41 = L_67 ;
int V_40 ;
if ( F_35 ( & V_193 -> V_3 , V_41 ,
L_68 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_36 ( & V_193 -> V_3 , V_39 ) ;
switch ( V_40 ) {
case V_42 :
F_33 ( V_38 ) ;
if ( ! V_193 -> V_202 && V_193 -> V_195 ) {
F_30 ( & V_193 -> V_3 ) ;
V_193 -> V_202 = true ;
}
continue;
case V_177 :
case V_54 :
if ( ! V_193 -> V_32 )
continue;
V_201 = V_193 -> V_32 ;
V_203:
F_106 ( V_199 , V_201 ) ;
if ( F_33 )
F_33 ( V_38 ) ;
V_37 = F_104 ( V_201 ) ;
V_40 = F_83 ( V_201 , V_45 , V_197 ,
V_37 , true , F_33 ,
V_38 , V_39 ) ;
F_38 ( & V_193 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_170 :
if ( V_201 -> V_17 . V_27 == & V_199 -> V_35 )
V_201 = F_103 ( V_199 -> V_35 . V_27 , struct V_154 , V_17 ) ;
else
V_201 = F_103 ( V_201 -> V_17 . V_27 , struct V_154 , V_17 ) ;
goto V_203;
case V_171 :
if ( V_201 -> V_17 . V_204 == & V_199 -> V_35 )
V_201 = F_103 ( V_199 -> V_35 . V_204 , struct V_154 , V_17 ) ;
else
V_201 = F_103 ( V_201 -> V_17 . V_204 , struct V_154 , V_17 ) ;
goto V_203;
case V_181 :
if ( ! F_91 ( & V_193 -> V_3 ,
L_54 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_55;
default:
continue;
}
case V_178 :
continue;
case V_181 :
if ( ! F_91 ( & V_193 -> V_3 ,
L_54 ) )
continue;
case 'q' :
case F_92 ( 'c' ) :
goto V_55;
default:
continue;
}
}
V_55:
F_41 ( & V_193 -> V_3 ) ;
return V_40 ;
}
static int F_107 ( struct V_198 * V_199 ,
const char * V_197 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_154 * V_201 ;
struct V_192 V_193 = {
. V_3 = {
. V_35 = & V_199 -> V_35 ,
. V_136 = V_205 ,
. V_137 = V_206 ,
. V_207 = F_102 ,
. V_6 = V_199 -> V_6 ,
. V_200 = V_199 ,
} ,
} ;
F_85 ( L_69 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_104 ( V_201 ) ;
T_1 V_208 = strlen ( V_37 ) + 7 ;
if ( V_193 . V_3 . V_4 < V_208 )
V_193 . V_3 . V_4 = V_208 ;
}
return F_105 ( & V_193 , V_199 -> V_6 , V_197 , F_33 ,
V_38 , V_39 ) ;
}
int F_108 ( struct V_198 * V_199 , const char * V_197 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
if ( V_199 -> V_6 == 1 ) {
struct V_154 * V_25 = F_103 ( V_199 -> V_35 . V_27 ,
struct V_154 , V_17 ) ;
const char * V_37 = F_104 ( V_25 ) ;
return F_83 ( V_25 , V_199 -> V_6 , V_197 ,
V_37 , false , F_33 , V_38 ,
V_39 ) ;
}
return F_107 ( V_199 , V_197 ,
F_33 , V_38 , V_39 ) ;
}
