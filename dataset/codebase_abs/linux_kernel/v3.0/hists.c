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
static char F_6 ( const struct V_8 * V_2 )
{
return V_2 -> V_9 ? F_5 ( V_2 -> V_7 ) : ' ' ;
}
static char F_7 ( const struct V_10 * V_2 )
{
return F_6 ( & V_2 -> V_11 ) ;
}
static char F_8 ( const struct V_12 * V_2 )
{
return F_6 ( & V_2 -> V_11 ) ;
}
static void F_9 ( struct V_8 * V_2 , bool V_13 )
{
V_2 -> V_7 = V_13 ? V_2 -> V_9 : false ;
}
static int F_10 ( struct V_14 * V_2 )
{
int V_15 = 0 ;
struct V_16 * V_17 ;
for ( V_17 = F_11 ( & V_2 -> V_18 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_19 = F_13 ( V_17 , struct V_14 , V_16 ) ;
struct V_12 * V_20 ;
char V_21 = ' ' ;
F_14 (chain, &child->val, list) {
++ V_15 ;
V_21 = F_8 ( V_20 ) ;
if ( V_21 == '+' )
break;
}
if ( V_21 == '-' )
V_15 += F_10 ( V_19 ) ;
}
return V_15 ;
}
static int F_15 ( struct V_14 * V_22 )
{
struct V_12 * V_20 ;
bool V_7 = false ;
int V_15 = 0 ;
F_14 (chain, &node->val, list) {
++ V_15 ;
V_7 = V_20 -> V_11 . V_7 ;
}
if ( V_7 )
V_15 += F_10 ( V_22 ) ;
return V_15 ;
}
static int F_16 ( struct V_18 * V_20 )
{
struct V_16 * V_17 ;
int V_15 = 0 ;
for ( V_17 = F_11 ( V_20 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_22 = F_13 ( V_17 , struct V_14 , V_16 ) ;
V_15 += F_15 ( V_22 ) ;
}
return V_15 ;
}
static bool F_17 ( struct V_8 * V_2 )
{
if ( ! V_2 -> V_9 )
return false ;
V_2 -> V_7 = ! V_2 -> V_7 ;
return true ;
}
static void F_18 ( struct V_14 * V_2 )
{
struct V_16 * V_17 = F_11 ( & V_2 -> V_18 ) ;
for ( V_17 = F_11 ( & V_2 -> V_18 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_19 = F_13 ( V_17 , struct V_14 , V_16 ) ;
struct V_12 * V_20 ;
bool V_23 = true ;
F_14 (chain, &child->val, list) {
if ( V_23 ) {
V_23 = false ;
V_20 -> V_11 . V_9 = V_20 -> V_24 . V_25 != & V_19 -> V_26 ||
! F_19 ( & V_19 -> V_18 ) ;
} else
V_20 -> V_11 . V_9 = V_20 -> V_24 . V_25 == & V_19 -> V_26 &&
! F_19 ( & V_19 -> V_18 ) ;
}
F_18 ( V_19 ) ;
}
}
static void F_20 ( struct V_14 * V_2 )
{
struct V_12 * V_20 ;
F_14 (chain, &self->val, list)
V_20 -> V_11 . V_9 = ! F_19 ( & V_2 -> V_18 ) ;
F_18 ( V_2 ) ;
}
static void F_21 ( struct V_18 * V_2 )
{
struct V_16 * V_17 ;
for ( V_17 = F_11 ( V_2 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_22 = F_13 ( V_17 , struct V_14 , V_16 ) ;
F_20 ( V_22 ) ;
}
}
static void F_22 ( struct V_10 * V_2 )
{
if ( ! V_2 -> V_27 ) {
V_2 -> V_11 . V_9 = ! F_19 ( & V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_28 ) ;
V_2 -> V_27 = true ;
}
}
static bool F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_29 ) ) {
struct V_10 * V_30 = V_2 -> V_31 ;
F_22 ( V_30 ) ;
V_2 -> V_5 -> V_6 -= V_30 -> V_32 ;
if ( V_30 -> V_11 . V_7 )
V_30 -> V_32 = F_16 ( & V_30 -> V_28 ) ;
else
V_30 -> V_32 = 0 ;
V_2 -> V_5 -> V_6 += V_30 -> V_32 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
return true ;
}
return false ;
}
static int F_24 ( struct V_14 * V_2 , bool V_13 )
{
int V_15 = 0 ;
struct V_16 * V_17 ;
for ( V_17 = F_11 ( & V_2 -> V_18 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_19 = F_13 ( V_17 , struct V_14 , V_16 ) ;
struct V_12 * V_20 ;
bool V_9 = false ;
F_14 (chain, &child->val, list) {
++ V_15 ;
F_9 ( & V_20 -> V_11 , V_13 ) ;
V_9 = V_20 -> V_11 . V_9 ;
}
if ( V_9 )
V_15 += F_24 ( V_19 , V_13 ) ;
}
return V_15 ;
}
static int F_25 ( struct V_14 * V_22 , bool V_13 )
{
struct V_12 * V_20 ;
bool V_9 = false ;
int V_15 = 0 ;
F_14 (chain, &node->val, list) {
++ V_15 ;
F_9 ( & V_20 -> V_11 , V_13 ) ;
V_9 = V_20 -> V_11 . V_9 ;
}
if ( V_9 )
V_15 += F_24 ( V_22 , V_13 ) ;
return V_15 ;
}
static int F_26 ( struct V_18 * V_20 , bool V_13 )
{
struct V_16 * V_17 ;
int V_15 = 0 ;
for ( V_17 = F_11 ( V_20 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_22 = F_13 ( V_17 , struct V_14 , V_16 ) ;
V_15 += F_25 ( V_22 , V_13 ) ;
}
return V_15 ;
}
static void F_27 ( struct V_10 * V_2 , bool V_13 )
{
F_22 ( V_2 ) ;
F_9 ( & V_2 -> V_11 , V_13 ) ;
if ( V_2 -> V_11 . V_9 ) {
int V_15 = F_26 ( & V_2 -> V_28 , V_13 ) ;
V_2 -> V_32 = V_13 ? V_15 : 0 ;
} else
V_2 -> V_32 = 0 ;
}
static void F_28 ( struct V_5 * V_2 , bool V_13 )
{
struct V_16 * V_17 ;
V_2 -> V_6 = 0 ;
for ( V_17 = F_11 ( & V_2 -> V_33 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_10 * V_30 = F_13 ( V_17 , struct V_10 , V_16 ) ;
F_27 ( V_30 , V_13 ) ;
V_2 -> V_6 += 1 + V_30 -> V_32 ;
}
}
static void F_29 ( struct V_1 * V_2 , bool V_13 )
{
F_28 ( V_2 -> V_5 , V_13 ) ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_4 ( & V_2 -> V_3 ) ;
}
static int F_30 ( struct V_1 * V_2 , const char * V_34 )
{
int V_35 ;
int V_36 [] = { 'a' , '?' , 'h' , 'C' , 'd' , 'D' , 'E' , 't' ,
V_37 , V_38 , V_39 ,
V_40 , V_41 , 0 , } ;
V_2 -> V_3 . V_33 = & V_2 -> V_5 -> V_33 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_1 ( V_2 ) ;
if ( F_31 ( & V_2 -> V_3 , V_34 ,
L_2 ) < 0 )
return - 1 ;
F_32 ( & V_2 -> V_3 , V_36 ) ;
while ( 1 ) {
V_35 = F_33 ( & V_2 -> V_3 ) ;
switch ( V_35 ) {
case 'D' : {
static int V_42 ;
struct V_10 * V_43 = F_13 ( V_2 -> V_3 . V_44 ,
struct V_10 , V_16 ) ;
F_34 () ;
F_35 ( L_3 ,
V_42 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_45 ,
V_2 -> V_3 . V_46 ,
V_2 -> V_3 . V_47 ,
V_43 -> V_48 , V_43 -> V_32 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_37 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_49;
}
}
V_49:
F_36 ( & V_2 -> V_3 ) ;
return V_35 ;
}
static char * F_37 ( struct V_12 * V_2 ,
char * V_50 , T_1 V_51 )
{
if ( V_2 -> V_11 . V_52 )
return V_2 -> V_11 . V_52 -> V_53 ;
snprintf ( V_50 , V_51 , L_4 V_54 , V_2 -> V_55 ) ;
return V_50 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_14 * V_56 ,
T_2 V_57 , int V_58 ,
unsigned short V_59 ,
T_3 * V_48 ,
bool * V_60 )
{
struct V_16 * V_22 ;
int V_61 = V_59 , V_4 , V_62 = V_58 * V_63 ;
T_2 V_64 , V_65 ;
if ( V_66 . V_67 == V_68 )
V_64 = V_56 -> V_69 ;
else
V_64 = V_57 ;
V_65 = V_64 ;
V_22 = F_11 ( & V_56 -> V_18 ) ;
while ( V_22 ) {
struct V_14 * V_19 = F_13 ( V_22 , struct V_14 , V_16 ) ;
struct V_16 * V_25 = F_12 ( V_22 ) ;
T_2 V_70 = F_39 ( V_19 ) ;
struct V_12 * V_20 ;
char V_21 = ' ' ;
int V_23 = true ;
int V_71 = 0 ;
V_65 -= V_70 ;
F_14 (chain, &child->val, list) {
char V_72 [ V_73 / 4 + 1 ] , * V_74 ;
const char * V_75 ;
int V_76 ;
bool V_77 = V_23 ;
if ( V_23 )
V_23 = false ;
else
V_71 = V_63 ;
V_21 = F_8 ( V_20 ) ;
if ( * V_48 != 0 ) {
-- * V_48 ;
goto V_78;
}
V_74 = NULL ;
V_75 = F_37 ( V_20 , V_72 , sizeof( V_72 ) ) ;
if ( V_77 ) {
double V_79 = V_70 * 100.0 / V_64 ;
if ( F_40 ( & V_74 , L_5 , V_79 , V_75 ) < 0 )
V_75 = L_6 ;
else
V_75 = V_74 ;
}
V_76 = V_80 ;
V_4 = V_2 -> V_3 . V_4 - ( V_62 + V_71 + 2 ) ;
if ( F_41 ( & V_2 -> V_3 , V_59 ) ) {
V_2 -> V_29 = & V_20 -> V_11 ;
V_76 = V_81 ;
* V_60 = true ;
}
F_42 ( & V_2 -> V_3 , V_76 ) ;
F_43 ( & V_2 -> V_3 , V_59 , 0 ) ;
F_44 ( L_7 , V_62 + V_71 ) ;
F_45 ( L_8 , V_21 ) ;
F_44 ( V_75 , V_4 ) ;
free ( V_74 ) ;
if ( ++ V_59 == V_2 -> V_3 . V_45 )
goto V_49;
V_78:
if ( V_21 == '+' )
break;
}
if ( V_21 == '-' ) {
const int V_82 = V_58 + ( V_71 ? 2 : 1 ) ;
V_59 += F_38 ( V_2 , V_19 , V_64 ,
V_82 , V_59 , V_48 ,
V_60 ) ;
}
if ( V_59 == V_2 -> V_3 . V_45 )
goto V_49;
V_22 = V_25 ;
}
V_49:
return V_59 - V_61 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_14 * V_22 ,
int V_58 , unsigned short V_59 ,
T_3 * V_48 ,
bool * V_60 )
{
struct V_12 * V_20 ;
int V_61 = V_59 ,
V_62 = V_58 * V_63 ,
V_4 = V_2 -> V_3 . V_4 - V_62 ;
char V_21 = ' ' ;
F_14 (chain, &node->val, list) {
char V_72 [ V_73 / 4 + 1 ] , * V_83 ;
int V_76 ;
V_21 = F_8 ( V_20 ) ;
if ( * V_48 != 0 ) {
-- * V_48 ;
continue;
}
V_76 = V_80 ;
if ( F_41 ( & V_2 -> V_3 , V_59 ) ) {
V_2 -> V_29 = & V_20 -> V_11 ;
V_76 = V_81 ;
* V_60 = true ;
}
V_83 = F_37 ( V_20 , V_72 , sizeof( V_72 ) ) ;
F_43 ( & V_2 -> V_3 , V_59 , 0 ) ;
F_42 ( & V_2 -> V_3 , V_76 ) ;
F_44 ( L_7 , V_62 ) ;
F_45 ( L_8 , V_21 ) ;
F_44 ( V_83 , V_4 - 2 ) ;
if ( ++ V_59 == V_2 -> V_3 . V_45 )
goto V_49;
}
if ( V_21 == '-' )
V_59 += F_38 ( V_2 , V_22 ,
V_2 -> V_5 -> V_84 . V_85 ,
V_58 + 1 , V_59 ,
V_48 ,
V_60 ) ;
V_49:
return V_59 - V_61 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_18 * V_20 ,
int V_58 , unsigned short V_59 ,
T_3 * V_48 ,
bool * V_60 )
{
struct V_16 * V_17 ;
int V_61 = V_59 ;
for ( V_17 = F_11 ( V_20 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_22 = F_13 ( V_17 , struct V_14 , V_16 ) ;
V_59 += F_46 ( V_2 , V_22 , V_58 ,
V_59 , V_48 ,
V_60 ) ;
if ( V_59 == V_2 -> V_3 . V_45 )
break;
}
return V_59 - V_61 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_10 * V_86 ,
unsigned short V_59 )
{
char V_83 [ 256 ] ;
double V_79 ;
int V_87 = 0 ;
int V_76 , V_4 = V_2 -> V_3 . V_4 ;
char V_21 = ' ' ;
bool V_88 = F_41 ( & V_2 -> V_3 , V_59 ) ;
T_3 V_48 = V_86 -> V_48 ;
if ( V_88 ) {
V_2 -> V_31 = V_86 ;
V_2 -> V_29 = & V_86 -> V_11 ;
}
if ( V_89 . V_90 ) {
F_22 ( V_86 ) ;
V_21 = F_7 ( V_86 ) ;
}
if ( V_48 == 0 ) {
F_49 ( V_86 , V_83 , sizeof( V_83 ) , V_2 -> V_5 , NULL , false ,
0 , false , V_2 -> V_5 -> V_84 . V_85 ) ;
V_79 = ( V_86 -> V_91 * 100.0 ) / V_2 -> V_5 -> V_84 . V_85 ;
V_76 = V_81 ;
if ( ! V_88 ) {
if ( V_79 >= V_92 )
V_76 = V_93 ;
else if ( V_79 >= V_94 )
V_76 = V_95 ;
else
V_76 = V_80 ;
}
F_42 ( & V_2 -> V_3 , V_76 ) ;
F_43 ( & V_2 -> V_3 , V_59 , 0 ) ;
if ( V_89 . V_90 ) {
F_45 ( L_8 , V_21 ) ;
V_4 -= 2 ;
}
F_44 ( V_83 , V_4 ) ;
++ V_59 ;
++ V_87 ;
} else
-- V_48 ;
if ( V_21 == '-' && V_59 != V_2 -> V_3 . V_45 ) {
V_87 += F_47 ( V_2 , & V_86 -> V_28 ,
1 , V_59 , & V_48 ,
& V_88 ) ;
if ( V_88 )
V_2 -> V_31 = V_86 ;
}
return V_87 ;
}
static unsigned int F_50 ( struct V_96 * V_2 )
{
unsigned V_59 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_97 = F_51 ( V_2 , struct V_1 , V_3 ) ;
if ( V_2 -> V_44 == NULL )
V_2 -> V_44 = F_11 ( & V_97 -> V_5 -> V_33 ) ;
for ( V_17 = V_2 -> V_44 ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_10 * V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_43 -> V_98 )
continue;
V_59 += F_48 ( V_97 , V_43 , V_59 ) ;
if ( V_59 == V_2 -> V_45 )
break;
}
return V_59 ;
}
static struct V_16 * F_52 ( struct V_16 * V_17 )
{
while ( V_17 != NULL ) {
struct V_10 * V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( ! V_43 -> V_98 )
return V_17 ;
V_17 = F_12 ( V_17 ) ;
}
return NULL ;
}
static struct V_16 * F_53 ( struct V_16 * V_17 )
{
while ( V_17 != NULL ) {
struct V_10 * V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( ! V_43 -> V_98 )
return V_17 ;
V_17 = F_54 ( V_17 ) ;
}
return NULL ;
}
static void F_55 ( struct V_96 * V_2 ,
T_3 V_62 , int V_99 )
{
struct V_10 * V_43 ;
struct V_16 * V_17 ;
bool V_23 = true ;
if ( V_2 -> V_6 == 0 )
return;
switch ( V_99 ) {
case V_100 :
V_17 = F_52 ( F_11 ( V_2 -> V_33 ) ) ;
break;
case V_101 :
V_17 = V_2 -> V_44 ;
goto V_102;
case V_103 :
V_17 = F_53 ( F_56 ( V_2 -> V_33 ) ) ;
V_23 = false ;
break;
default:
return;
}
V_43 = F_13 ( V_2 -> V_44 , struct V_10 , V_16 ) ;
V_43 -> V_48 = 0 ;
V_102:
if ( V_62 > 0 ) {
do {
V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_43 -> V_11 . V_7 ) {
T_4 V_65 = V_43 -> V_32 - V_43 -> V_48 ;
if ( V_62 > V_65 ) {
V_62 -= V_65 ;
V_43 -> V_48 = 0 ;
} else {
V_43 -> V_48 += V_62 ;
V_62 = 0 ;
V_2 -> V_44 = V_17 ;
break;
}
}
V_17 = F_52 ( F_12 ( V_17 ) ) ;
if ( V_17 == NULL )
break;
-- V_62 ;
V_2 -> V_44 = V_17 ;
} while ( V_62 != 0 );
} else if ( V_62 < 0 ) {
while ( 1 ) {
V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_43 -> V_11 . V_7 ) {
if ( V_23 ) {
if ( - V_62 > V_43 -> V_48 ) {
V_62 += V_43 -> V_48 ;
V_43 -> V_48 = 0 ;
} else {
V_43 -> V_48 += V_62 ;
V_62 = 0 ;
V_2 -> V_44 = V_17 ;
break;
}
} else {
if ( - V_62 > V_43 -> V_32 ) {
V_62 += V_43 -> V_32 ;
V_43 -> V_48 = 0 ;
} else {
V_43 -> V_48 = V_43 -> V_32 + V_62 ;
V_62 = 0 ;
V_2 -> V_44 = V_17 ;
break;
}
}
}
V_17 = F_53 ( F_54 ( V_17 ) ) ;
if ( V_17 == NULL )
break;
++ V_62 ;
V_2 -> V_44 = V_17 ;
if ( V_62 == 0 ) {
V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_43 -> V_11 . V_7 )
V_43 -> V_48 = V_43 -> V_32 ;
break;
}
V_23 = false ;
}
} else {
V_2 -> V_44 = V_17 ;
V_43 = F_13 ( V_17 , struct V_10 , V_16 ) ;
V_43 -> V_48 = 0 ;
}
}
static struct V_1 * F_57 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_58 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_104 = F_50 ;
V_2 -> V_3 . V_105 = F_55 ;
}
return V_2 ;
}
static void F_59 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_10 * F_60 ( struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static struct V_106 * F_61 ( struct V_1 * V_2 )
{
return V_2 -> V_31 -> V_106 ;
}
static int F_62 ( struct V_5 * V_2 , char * V_50 , T_1 V_107 ,
const char * V_108 , const struct V_109 * V_109 ,
const struct V_106 * V_106 )
{
char V_110 ;
int V_87 ;
unsigned long V_111 = V_2 -> V_84 . V_111 [ V_112 ] ;
V_111 = F_63 ( V_111 , & V_110 ) ;
V_87 = snprintf ( V_50 , V_107 , L_9 , V_111 , V_110 , V_108 ) ;
if ( V_106 )
V_87 += snprintf ( V_50 + V_87 , V_107 - V_87 ,
L_10 ,
( V_106 -> V_113 ? V_106 -> V_114 : L_11 ) ,
V_106 -> V_115 ) ;
if ( V_109 )
V_87 += snprintf ( V_50 + V_87 , V_107 - V_87 ,
L_12 , V_109 -> V_116 ) ;
return V_87 ;
}
static int F_64 ( struct V_117 * V_118 ,
const char * V_119 , const char * V_108 ,
bool V_120 )
{
struct V_5 * V_2 = & V_118 -> V_5 ;
struct V_1 * V_121 = F_57 ( V_2 ) ;
struct V_122 * V_123 ;
const struct V_106 * V_124 = NULL ;
const struct V_109 * V_125 = NULL ;
char V_126 [ 160 ] ;
int V_35 = - 1 ;
if ( V_121 == NULL )
return - 1 ;
V_123 = F_65 ( 2 ) ;
if ( V_123 == NULL )
goto V_49;
F_66 ( V_119 ) ;
F_62 ( V_2 , V_126 , sizeof( V_126 ) , V_108 ,
V_125 , V_124 ) ;
while ( 1 ) {
const struct V_106 * V_106 = NULL ;
const struct V_109 * V_109 = NULL ;
char * V_127 [ 16 ] ;
int V_128 = 0 , V_129 = 0 , V_130 ,
V_131 = - 2 , V_132 = - 2 , V_133 = - 2 ,
V_134 = - 2 ;
V_35 = F_30 ( V_121 , V_126 ) ;
if ( V_121 -> V_31 != NULL ) {
V_106 = F_61 ( V_121 ) ;
V_109 = V_121 -> V_29 -> V_135 ? V_121 -> V_29 -> V_135 -> V_109 : NULL ;
}
switch ( V_35 ) {
case V_40 :
case V_41 :
goto V_136;
case 'a' :
if ( V_121 -> V_29 == NULL ||
V_121 -> V_29 -> V_52 == NULL ||
V_121 -> V_29 -> V_135 -> V_109 -> V_137 )
continue;
goto V_138;
case 'd' :
goto V_132;
case 't' :
goto V_133;
case V_139 :
case 'h' :
case '?' :
F_67 ( L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ) ;
continue;
case V_37 :
case V_38 :
break;
case V_39 : {
const void * V_44 ;
if ( F_68 ( V_123 ) ) {
if ( V_120 )
goto V_136;
continue;
}
V_44 = F_69 ( V_123 ) ;
if ( V_44 == & V_125 )
goto V_140;
if ( V_44 == & V_124 )
goto V_141;
continue;
}
case V_142 :
if ( ! V_120 &&
! F_70 ( L_23 ) )
continue;
default:
goto V_136;
}
if ( V_121 -> V_29 != NULL &&
V_121 -> V_29 -> V_52 != NULL &&
! V_121 -> V_29 -> V_135 -> V_109 -> V_137 &&
F_40 ( & V_127 [ V_128 ] , L_24 ,
V_121 -> V_29 -> V_52 -> V_53 ) > 0 )
V_131 = V_128 ++ ;
if ( V_106 != NULL &&
F_40 ( & V_127 [ V_128 ] , L_25 ,
( V_124 ? L_26 : L_27 ) ,
( V_106 -> V_113 ? V_106 -> V_114 : L_11 ) ,
V_106 -> V_115 ) > 0 )
V_133 = V_128 ++ ;
if ( V_109 != NULL &&
F_40 ( & V_127 [ V_128 ] , L_28 ,
( V_125 ? L_26 : L_27 ) ,
( V_109 -> V_143 ? L_29 : V_109 -> V_116 ) ) > 0 )
V_132 = V_128 ++ ;
if ( V_121 -> V_29 != NULL &&
V_121 -> V_29 -> V_135 != NULL &&
F_40 ( & V_127 [ V_128 ] , L_30 ) > 0 )
V_134 = V_128 ++ ;
V_127 [ V_128 ++ ] = ( char * ) L_31 ;
V_129 = F_71 ( V_128 , V_127 ) ;
for ( V_130 = 0 ; V_130 < V_128 - 1 ; ++ V_130 )
free ( V_127 [ V_130 ] ) ;
if ( V_129 == V_128 - 1 )
break;
if ( V_129 == - 1 )
continue;
if ( V_129 == V_131 ) {
struct V_10 * V_30 ;
V_138:
V_30 = F_60 ( V_121 ) ;
if ( V_30 == NULL )
continue;
F_72 ( V_30 , V_118 -> V_144 ) ;
} else if ( V_129 == V_134 )
F_73 ( V_121 -> V_29 -> V_135 ) ;
else if ( V_129 == V_132 ) {
V_132:
if ( V_125 ) {
F_74 ( V_123 , & V_125 ) ;
V_140:
F_34 () ;
V_125 = NULL ;
} else {
if ( V_109 == NULL )
continue;
F_35 ( L_32 ,
V_109 -> V_143 ? L_29 : V_109 -> V_116 ) ;
V_125 = V_109 ;
F_75 ( V_123 , & V_125 ) ;
}
F_76 ( V_2 , V_125 ) ;
F_62 ( V_2 , V_126 , sizeof( V_126 ) , V_108 ,
V_125 , V_124 ) ;
F_3 ( V_121 ) ;
} else if ( V_129 == V_133 ) {
V_133:
if ( V_124 ) {
F_74 ( V_123 , & V_124 ) ;
V_141:
F_34 () ;
V_124 = NULL ;
} else {
F_35 ( L_33 ,
V_106 -> V_113 ? V_106 -> V_114 : L_11 ,
V_106 -> V_115 ) ;
V_124 = V_106 ;
F_75 ( V_123 , & V_124 ) ;
}
F_77 ( V_2 , V_124 ) ;
F_62 ( V_2 , V_126 , sizeof( V_126 ) , V_108 ,
V_125 , V_124 ) ;
F_3 ( V_121 ) ;
}
}
V_136:
F_78 ( V_123 ) ;
V_49:
F_59 ( V_121 ) ;
return V_35 ;
}
static void F_79 ( struct V_96 * V_121 ,
void * V_86 , int V_59 )
{
struct V_145 * V_146 = F_51 ( V_121 ,
struct V_145 , V_3 ) ;
struct V_117 * V_118 = F_80 ( V_86 , struct V_117 , V_22 ) ;
bool V_88 = F_41 ( V_121 , V_59 ) ;
unsigned long V_111 = V_118 -> V_5 . V_84 . V_111 [ V_112 ] ;
const char * V_108 = F_81 ( V_118 ) ;
char V_50 [ 256 ] , V_110 ;
F_42 ( V_121 , V_88 ? V_81 :
V_80 ) ;
V_111 = F_63 ( V_111 , & V_110 ) ;
snprintf ( V_50 , sizeof( V_50 ) , L_34 , V_111 ,
V_110 , V_110 == ' ' ? L_11 : L_7 , V_108 ) ;
F_44 ( V_50 , V_121 -> V_4 ) ;
if ( V_88 )
V_146 -> V_29 = V_118 ;
}
static int F_82 ( struct V_145 * V_146 , const char * V_147 )
{
int V_36 [] = { V_37 , V_38 , 0 , } ;
struct V_148 * V_149 = V_146 -> V_3 . V_150 ;
struct V_117 * V_151 ;
const char * V_108 , * V_34 = L_35 ;
int V_35 ;
if ( F_31 ( & V_146 -> V_3 , V_34 ,
L_36 ) < 0 )
return - 1 ;
F_32 ( & V_146 -> V_3 , V_36 ) ;
while ( 1 ) {
V_35 = F_33 ( & V_146 -> V_3 ) ;
switch ( V_35 ) {
case V_38 :
case V_37 :
if ( ! V_146 -> V_29 )
continue;
V_151 = V_146 -> V_29 ;
V_152:
V_108 = F_81 ( V_151 ) ;
V_35 = F_64 ( V_151 , V_147 , V_108 , true ) ;
F_83 ( & V_146 -> V_3 , V_34 ) ;
break;
case V_39 :
continue;
case V_142 :
if ( ! F_70 ( L_23 ) )
continue;
default:
goto V_49;
}
switch ( V_35 ) {
case V_40 :
if ( V_151 -> V_22 . V_25 == & V_149 -> V_33 )
V_151 = F_80 ( V_149 -> V_33 . V_25 , struct V_117 , V_22 ) ;
else
V_151 = F_80 ( V_151 -> V_22 . V_25 , struct V_117 , V_22 ) ;
goto V_152;
case V_41 :
if ( V_151 -> V_22 . V_153 == & V_149 -> V_33 )
V_151 = F_80 ( V_149 -> V_33 . V_153 , struct V_117 , V_22 ) ;
else
V_151 = F_80 ( V_151 -> V_22 . V_153 , struct V_117 , V_22 ) ;
goto V_152;
case 'q' :
case F_84 ( 'c' ) :
goto V_49;
default:
break;
}
}
V_49:
F_36 ( & V_146 -> V_3 ) ;
return V_35 ;
}
static int F_85 ( struct V_148 * V_149 ,
const char * V_147 )
{
struct V_117 * V_151 ;
struct V_145 V_146 = {
. V_3 = {
. V_33 = & V_149 -> V_33 ,
. V_104 = V_154 ,
. V_105 = V_155 ,
. V_156 = F_79 ,
. V_6 = V_149 -> V_6 ,
. V_150 = V_149 ,
} ,
} ;
F_66 ( L_37 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_108 = F_81 ( V_151 ) ;
T_1 V_157 = strlen ( V_108 ) + 7 ;
if ( V_146 . V_3 . V_4 < V_157 )
V_146 . V_3 . V_4 = V_157 ;
if ( V_151 -> V_53 == NULL )
V_151 -> V_53 = F_86 ( V_108 ) ;
}
return F_82 ( & V_146 , V_147 ) ;
}
int F_87 ( struct V_148 * V_149 , const char * V_147 )
{
if ( V_149 -> V_6 == 1 ) {
struct V_117 * V_23 = F_80 ( V_149 -> V_33 . V_25 ,
struct V_117 , V_22 ) ;
const char * V_108 = F_81 ( V_23 ) ;
return F_64 ( V_23 , V_147 , V_108 , false ) ;
}
return F_85 ( V_149 , V_147 ) ;
}
