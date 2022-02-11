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
static void F_30 ( struct V_34 * V_35 )
{
F_31 ( V_35 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_32 ( struct V_1 * V_2 , const char * V_36 ,
void (* F_33)( void * V_37 ) , void * V_37 , int V_38 )
{
int V_39 ;
char V_40 [ 160 ] ;
V_2 -> V_3 . V_33 = & V_2 -> V_5 -> V_33 ;
V_2 -> V_3 . V_6 = V_2 -> V_5 -> V_6 ;
F_1 ( V_2 ) ;
F_34 ( V_2 -> V_5 , V_40 , sizeof( V_40 ) , V_36 ) ;
if ( F_35 ( & V_2 -> V_3 , V_40 ,
L_6 ) < 0 )
return - 1 ;
while ( 1 ) {
V_39 = F_36 ( & V_2 -> V_3 , V_38 ) ;
switch ( V_39 ) {
case V_41 :
F_33 ( V_37 ) ;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_2 -> V_5 -> V_42 . V_43 !=
V_2 -> V_5 -> V_42 . V_44 [ V_45 ] ) {
V_2 -> V_5 -> V_42 . V_43 =
V_2 -> V_5 -> V_42 . V_44 [ V_45 ] ;
F_30 ( & V_2 -> V_3 ) ;
}
F_34 ( V_2 -> V_5 , V_40 , sizeof( V_40 ) , V_36 ) ;
F_38 ( & V_2 -> V_3 , V_40 ) ;
continue;
case 'D' : {
static int V_46 ;
struct V_10 * V_47 = F_13 ( V_2 -> V_3 . V_48 ,
struct V_10 , V_16 ) ;
F_39 () ;
F_40 ( L_7 ,
V_46 ++ , V_2 -> V_3 . V_6 ,
V_2 -> V_5 -> V_6 ,
V_2 -> V_3 . V_49 ,
V_2 -> V_3 . V_50 ,
V_2 -> V_3 . V_51 ,
V_47 -> V_52 , V_47 -> V_32 ) ;
}
break;
case 'C' :
F_29 ( V_2 , false ) ;
break;
case 'E' :
F_29 ( V_2 , true ) ;
break;
case V_53 :
if ( F_23 ( V_2 ) )
break;
default:
goto V_54;
}
}
V_54:
F_41 ( & V_2 -> V_3 ) ;
return V_39 ;
}
static char * F_42 ( struct V_12 * V_2 ,
char * V_55 , T_1 V_56 )
{
if ( V_2 -> V_11 . V_57 )
return V_2 -> V_11 . V_57 -> V_58 ;
snprintf ( V_55 , V_56 , L_8 V_59 , V_2 -> V_60 ) ;
return V_55 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_14 * V_61 ,
T_2 V_62 , int V_63 ,
unsigned short V_64 ,
T_3 * V_52 ,
bool * V_65 )
{
struct V_16 * V_22 ;
int V_66 = V_64 , V_4 , V_67 = V_63 * V_68 ;
T_2 V_69 , V_70 ;
if ( V_71 . V_72 == V_73 )
V_69 = V_61 -> V_74 ;
else
V_69 = V_62 ;
V_70 = V_69 ;
V_22 = F_11 ( & V_61 -> V_18 ) ;
while ( V_22 ) {
struct V_14 * V_19 = F_13 ( V_22 , struct V_14 , V_16 ) ;
struct V_16 * V_25 = F_12 ( V_22 ) ;
T_2 V_75 = F_44 ( V_19 ) ;
struct V_12 * V_20 ;
char V_21 = ' ' ;
int V_23 = true ;
int V_76 = 0 ;
V_70 -= V_75 ;
F_14 (chain, &child->val, list) {
char V_77 [ V_78 / 4 + 1 ] , * V_79 ;
const char * V_80 ;
int V_81 ;
bool V_82 = V_23 ;
if ( V_23 )
V_23 = false ;
else
V_76 = V_68 ;
V_21 = F_8 ( V_20 ) ;
if ( * V_52 != 0 ) {
-- * V_52 ;
goto V_83;
}
V_79 = NULL ;
V_80 = F_42 ( V_20 , V_77 , sizeof( V_77 ) ) ;
if ( V_82 ) {
double V_84 = V_75 * 100.0 / V_69 ;
if ( F_45 ( & V_79 , L_9 , V_84 , V_80 ) < 0 )
V_80 = L_10 ;
else
V_80 = V_79 ;
}
V_81 = V_85 ;
V_4 = V_2 -> V_3 . V_4 - ( V_67 + V_76 + 2 ) ;
if ( F_46 ( & V_2 -> V_3 , V_64 ) ) {
V_2 -> V_29 = & V_20 -> V_11 ;
V_81 = V_86 ;
* V_65 = true ;
}
F_47 ( & V_2 -> V_3 , V_81 ) ;
F_48 ( & V_2 -> V_3 , V_64 , 0 ) ;
F_49 ( L_11 , V_67 + V_76 ) ;
F_50 ( L_12 , V_21 ) ;
F_49 ( V_80 , V_4 ) ;
free ( V_79 ) ;
if ( ++ V_64 == V_2 -> V_3 . V_49 )
goto V_54;
V_83:
if ( V_21 == '+' )
break;
}
if ( V_21 == '-' ) {
const int V_87 = V_63 + ( V_76 ? 2 : 1 ) ;
V_64 += F_43 ( V_2 , V_19 , V_69 ,
V_87 , V_64 , V_52 ,
V_65 ) ;
}
if ( V_64 == V_2 -> V_3 . V_49 )
goto V_54;
V_22 = V_25 ;
}
V_54:
return V_64 - V_66 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_14 * V_22 ,
int V_63 , unsigned short V_64 ,
T_3 * V_52 ,
bool * V_65 )
{
struct V_12 * V_20 ;
int V_66 = V_64 ,
V_67 = V_63 * V_68 ,
V_4 = V_2 -> V_3 . V_4 - V_67 ;
char V_21 = ' ' ;
F_14 (chain, &node->val, list) {
char V_77 [ V_78 / 4 + 1 ] , * V_88 ;
int V_81 ;
V_21 = F_8 ( V_20 ) ;
if ( * V_52 != 0 ) {
-- * V_52 ;
continue;
}
V_81 = V_85 ;
if ( F_46 ( & V_2 -> V_3 , V_64 ) ) {
V_2 -> V_29 = & V_20 -> V_11 ;
V_81 = V_86 ;
* V_65 = true ;
}
V_88 = F_42 ( V_20 , V_77 , sizeof( V_77 ) ) ;
F_48 ( & V_2 -> V_3 , V_64 , 0 ) ;
F_47 ( & V_2 -> V_3 , V_81 ) ;
F_49 ( L_11 , V_67 ) ;
F_50 ( L_12 , V_21 ) ;
F_49 ( V_88 , V_4 - 2 ) ;
if ( ++ V_64 == V_2 -> V_3 . V_49 )
goto V_54;
}
if ( V_21 == '-' )
V_64 += F_43 ( V_2 , V_22 ,
V_2 -> V_5 -> V_42 . V_89 ,
V_63 + 1 , V_64 ,
V_52 ,
V_65 ) ;
V_54:
return V_64 - V_66 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_18 * V_20 ,
int V_63 , unsigned short V_64 ,
T_3 * V_52 ,
bool * V_65 )
{
struct V_16 * V_17 ;
int V_66 = V_64 ;
for ( V_17 = F_11 ( V_20 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_14 * V_22 = F_13 ( V_17 , struct V_14 , V_16 ) ;
V_64 += F_51 ( V_2 , V_22 , V_63 ,
V_64 , V_52 ,
V_65 ) ;
if ( V_64 == V_2 -> V_3 . V_49 )
break;
}
return V_64 - V_66 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_10 * V_90 ,
unsigned short V_64 )
{
char V_88 [ 256 ] ;
double V_84 ;
int V_91 = 0 ;
int V_4 = V_2 -> V_3 . V_4 - 6 ;
char V_21 = ' ' ;
bool V_92 = F_46 ( & V_2 -> V_3 , V_64 ) ;
T_3 V_52 = V_90 -> V_52 ;
if ( V_92 ) {
V_2 -> V_31 = V_90 ;
V_2 -> V_29 = & V_90 -> V_11 ;
}
if ( V_93 . V_94 ) {
F_22 ( V_90 ) ;
V_21 = F_7 ( V_90 ) ;
}
if ( V_52 == 0 ) {
F_54 ( V_90 , V_88 , sizeof( V_88 ) , V_2 -> V_5 ) ;
V_84 = ( V_90 -> V_95 * 100.0 ) / V_2 -> V_5 -> V_42 . V_89 ;
F_55 ( & V_2 -> V_3 , V_84 , V_92 ) ;
F_48 ( & V_2 -> V_3 , V_64 , 0 ) ;
if ( V_93 . V_94 ) {
F_50 ( L_12 , V_21 ) ;
V_4 -= 2 ;
}
F_50 ( L_13 , V_84 ) ;
if ( ! V_2 -> V_3 . V_96 )
V_4 += 1 ;
if ( ! V_92 || ! V_2 -> V_3 . V_96 )
F_47 ( & V_2 -> V_3 , V_85 ) ;
if ( V_93 . V_97 ) {
F_50 ( L_14 , V_90 -> V_44 ) ;
V_4 -= 12 ;
}
if ( V_93 . V_98 ) {
F_50 ( L_15 V_99 , V_90 -> V_95 ) ;
V_4 -= 13 ;
}
F_49 ( V_88 , V_4 ) ;
++ V_64 ;
++ V_91 ;
} else
-- V_52 ;
if ( V_21 == '-' && V_64 != V_2 -> V_3 . V_49 ) {
V_91 += F_52 ( V_2 , & V_90 -> V_28 ,
1 , V_64 , & V_52 ,
& V_92 ) ;
if ( V_92 )
V_2 -> V_31 = V_90 ;
}
return V_91 ;
}
static void F_56 ( struct V_34 * V_35 )
{
if ( V_35 -> V_48 == NULL ) {
struct V_1 * V_100 ;
V_100 = F_57 ( V_35 , struct V_1 , V_3 ) ;
V_35 -> V_48 = F_11 ( & V_100 -> V_5 -> V_33 ) ;
}
}
static unsigned int F_58 ( struct V_34 * V_2 )
{
unsigned V_64 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_100 = F_57 ( V_2 , struct V_1 , V_3 ) ;
F_56 ( V_2 ) ;
for ( V_17 = V_2 -> V_48 ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_10 * V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_47 -> V_101 )
continue;
V_64 += F_53 ( V_100 , V_47 , V_64 ) ;
if ( V_64 == V_2 -> V_49 )
break;
}
return V_64 ;
}
static struct V_16 * F_59 ( struct V_16 * V_17 )
{
while ( V_17 != NULL ) {
struct V_10 * V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( ! V_47 -> V_101 )
return V_17 ;
V_17 = F_12 ( V_17 ) ;
}
return NULL ;
}
static struct V_16 * F_60 ( struct V_16 * V_17 )
{
while ( V_17 != NULL ) {
struct V_10 * V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( ! V_47 -> V_101 )
return V_17 ;
V_17 = F_61 ( V_17 ) ;
}
return NULL ;
}
static void F_62 ( struct V_34 * V_2 ,
T_3 V_67 , int V_102 )
{
struct V_10 * V_47 ;
struct V_16 * V_17 ;
bool V_23 = true ;
if ( V_2 -> V_6 == 0 )
return;
F_56 ( V_2 ) ;
switch ( V_102 ) {
case V_103 :
V_17 = F_59 ( F_11 ( V_2 -> V_33 ) ) ;
break;
case V_104 :
V_17 = V_2 -> V_48 ;
goto V_105;
case V_106 :
V_17 = F_60 ( F_63 ( V_2 -> V_33 ) ) ;
V_23 = false ;
break;
default:
return;
}
V_47 = F_13 ( V_2 -> V_48 , struct V_10 , V_16 ) ;
V_47 -> V_52 = 0 ;
V_105:
if ( V_67 > 0 ) {
do {
V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_47 -> V_11 . V_7 ) {
T_4 V_70 = V_47 -> V_32 - V_47 -> V_52 ;
if ( V_67 > V_70 ) {
V_67 -= V_70 ;
V_47 -> V_52 = 0 ;
} else {
V_47 -> V_52 += V_67 ;
V_67 = 0 ;
V_2 -> V_48 = V_17 ;
break;
}
}
V_17 = F_59 ( F_12 ( V_17 ) ) ;
if ( V_17 == NULL )
break;
-- V_67 ;
V_2 -> V_48 = V_17 ;
} while ( V_67 != 0 );
} else if ( V_67 < 0 ) {
while ( 1 ) {
V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_47 -> V_11 . V_7 ) {
if ( V_23 ) {
if ( - V_67 > V_47 -> V_52 ) {
V_67 += V_47 -> V_52 ;
V_47 -> V_52 = 0 ;
} else {
V_47 -> V_52 += V_67 ;
V_67 = 0 ;
V_2 -> V_48 = V_17 ;
break;
}
} else {
if ( - V_67 > V_47 -> V_32 ) {
V_67 += V_47 -> V_32 ;
V_47 -> V_52 = 0 ;
} else {
V_47 -> V_52 = V_47 -> V_32 + V_67 ;
V_67 = 0 ;
V_2 -> V_48 = V_17 ;
break;
}
}
}
V_17 = F_60 ( F_61 ( V_17 ) ) ;
if ( V_17 == NULL )
break;
++ V_67 ;
V_2 -> V_48 = V_17 ;
if ( V_67 == 0 ) {
V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
if ( V_47 -> V_11 . V_7 )
V_47 -> V_52 = V_47 -> V_32 ;
break;
}
V_23 = false ;
}
} else {
V_2 -> V_48 = V_17 ;
V_47 = F_13 ( V_17 , struct V_10 , V_16 ) ;
V_47 -> V_52 = 0 ;
}
}
static struct V_1 * F_64 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_65 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_107 = F_58 ;
V_2 -> V_3 . V_108 = F_62 ;
V_2 -> V_3 . V_109 = true ,
V_2 -> V_110 = V_111 . V_24 . V_25 != NULL ;
}
return V_2 ;
}
static void F_66 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_10 * F_67 ( struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static struct V_112 * F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_31 -> V_112 ;
}
static int F_34 ( struct V_5 * V_2 , char * V_55 , T_1 V_113 ,
const char * V_36 )
{
char V_114 ;
int V_91 ;
const struct V_115 * V_115 = V_2 -> V_116 ;
const struct V_112 * V_112 = V_2 -> V_117 ;
unsigned long V_44 = V_2 -> V_42 . V_44 [ V_118 ] ;
V_44 = F_69 ( V_44 , & V_114 ) ;
V_91 = snprintf ( V_55 , V_113 , L_16 , V_44 , V_114 , V_36 ) ;
if ( V_112 )
V_91 += snprintf ( V_55 + V_91 , V_113 - V_91 ,
L_17 ,
( V_112 -> V_119 ? V_112 -> V_120 : L_18 ) ,
V_112 -> V_121 ) ;
if ( V_115 )
V_91 += snprintf ( V_55 + V_91 , V_113 - V_91 ,
L_19 , V_115 -> V_122 ) ;
return V_91 ;
}
static int F_70 ( struct V_123 * V_124 , int V_44 ,
const char * V_125 , const char * V_36 ,
bool V_126 ,
void (* F_33)( void * V_37 ) , void * V_37 ,
int V_38 )
{
struct V_5 * V_2 = & V_124 -> V_5 ;
struct V_1 * V_35 = F_64 ( V_2 ) ;
struct V_127 * V_128 ;
int V_39 = - 1 ;
if ( V_35 == NULL )
return - 1 ;
V_128 = F_71 ( 2 ) ;
if ( V_128 == NULL )
goto V_54;
F_72 ( V_125 ) ;
while ( 1 ) {
const struct V_112 * V_112 = NULL ;
const struct V_115 * V_115 = NULL ;
char * V_129 [ 16 ] ;
int V_130 = 0 , V_131 = 0 , V_132 ,
V_133 = - 2 , V_134 = - 2 , V_135 = - 2 ,
V_136 = - 2 ;
V_39 = F_32 ( V_35 , V_36 , F_33 , V_37 , V_38 ) ;
if ( V_35 -> V_31 != NULL ) {
V_112 = F_68 ( V_35 ) ;
V_115 = V_35 -> V_29 -> V_137 ? V_35 -> V_29 -> V_137 -> V_115 : NULL ;
}
switch ( V_39 ) {
case V_138 :
case V_139 :
if ( V_44 == 1 )
continue;
goto V_140;
case 'a' :
if ( ! V_35 -> V_110 ) {
F_31 ( & V_35 -> V_3 , V_38 * 2 ,
L_20
L_21 ) ;
continue;
}
if ( V_35 -> V_29 == NULL ||
V_35 -> V_29 -> V_57 == NULL ||
V_35 -> V_29 -> V_137 -> V_115 -> V_141 )
continue;
goto V_142;
case 'd' :
goto V_134;
case 't' :
goto V_135;
case V_143 :
case 'h' :
case '?' :
F_73 ( & V_35 -> V_3 ,
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35 ) ;
continue;
case V_53 :
case V_144 :
break;
case V_145 : {
const void * V_48 ;
if ( F_74 ( V_128 ) ) {
if ( V_126 )
goto V_140;
continue;
}
V_48 = F_75 ( V_128 ) ;
if ( V_48 == & V_35 -> V_5 -> V_116 )
goto V_146;
if ( V_48 == & V_35 -> V_5 -> V_117 )
goto V_147;
continue;
}
case V_148 :
if ( ! V_126 &&
! F_76 ( & V_35 -> V_3 ,
L_36 ) )
continue;
case 'q' :
case F_77 ( 'c' ) :
goto V_140;
default:
continue;
}
if ( ! V_35 -> V_110 )
goto V_149;
if ( V_35 -> V_29 != NULL &&
V_35 -> V_29 -> V_57 != NULL &&
! V_35 -> V_29 -> V_137 -> V_115 -> V_141 &&
F_45 ( & V_129 [ V_130 ] , L_37 ,
V_35 -> V_29 -> V_57 -> V_58 ) > 0 )
V_133 = V_130 ++ ;
if ( V_112 != NULL &&
F_45 ( & V_129 [ V_130 ] , L_38 ,
( V_35 -> V_5 -> V_117 ? L_39 : L_40 ) ,
( V_112 -> V_119 ? V_112 -> V_120 : L_18 ) ,
V_112 -> V_121 ) > 0 )
V_135 = V_130 ++ ;
if ( V_115 != NULL &&
F_45 ( & V_129 [ V_130 ] , L_41 ,
( V_35 -> V_5 -> V_116 ? L_39 : L_40 ) ,
( V_115 -> V_150 ? L_42 : V_115 -> V_122 ) ) > 0 )
V_134 = V_130 ++ ;
if ( V_35 -> V_29 != NULL &&
V_35 -> V_29 -> V_137 != NULL &&
F_45 ( & V_129 [ V_130 ] , L_43 ) > 0 )
V_136 = V_130 ++ ;
V_149:
V_129 [ V_130 ++ ] = ( char * ) L_44 ;
V_131 = F_78 ( V_130 , V_129 ) ;
for ( V_132 = 0 ; V_132 < V_130 - 1 ; ++ V_132 )
free ( V_129 [ V_132 ] ) ;
if ( V_131 == V_130 - 1 )
break;
if ( V_131 == - 1 )
continue;
if ( V_131 == V_133 ) {
struct V_10 * V_30 ;
int V_151 ;
V_142:
V_30 = F_67 ( V_35 ) ;
if ( V_30 == NULL )
continue;
V_30 -> V_152 = true ;
V_151 = F_79 ( V_30 , V_124 -> V_153 , V_44 ,
F_33 , V_37 , V_38 ) ;
V_30 -> V_152 = false ;
F_37 ( & V_35 -> V_3 , V_35 -> V_5 -> V_6 ) ;
if ( V_151 )
F_80 ( & V_35 -> V_3 ) ;
} else if ( V_131 == V_136 )
F_81 ( V_35 -> V_29 -> V_137 ) ;
else if ( V_131 == V_134 ) {
V_134:
if ( V_35 -> V_5 -> V_116 ) {
F_82 ( V_128 , & V_35 -> V_5 -> V_116 ) ;
V_146:
F_39 () ;
V_35 -> V_5 -> V_116 = NULL ;
V_154 . V_155 = false ;
} else {
if ( V_115 == NULL )
continue;
F_40 ( L_45 ,
V_115 -> V_150 ? L_42 : V_115 -> V_122 ) ;
V_35 -> V_5 -> V_116 = V_115 ;
V_154 . V_155 = true ;
F_83 ( V_128 , & V_35 -> V_5 -> V_116 ) ;
}
F_84 ( V_2 ) ;
F_3 ( V_35 ) ;
} else if ( V_131 == V_135 ) {
V_135:
if ( V_35 -> V_5 -> V_117 ) {
F_82 ( V_128 , & V_35 -> V_5 -> V_117 ) ;
V_147:
F_39 () ;
V_35 -> V_5 -> V_117 = NULL ;
V_156 . V_155 = false ;
} else {
F_40 ( L_46 ,
V_112 -> V_119 ? V_112 -> V_120 : L_18 ,
V_112 -> V_121 ) ;
V_35 -> V_5 -> V_117 = V_112 ;
V_156 . V_155 = true ;
F_83 ( V_128 , & V_35 -> V_5 -> V_117 ) ;
}
F_85 ( V_2 ) ;
F_3 ( V_35 ) ;
}
}
V_140:
F_86 ( V_128 ) ;
V_54:
F_66 ( V_35 ) ;
return V_39 ;
}
static void F_87 ( struct V_34 * V_35 ,
void * V_90 , int V_64 )
{
struct V_157 * V_158 = F_57 ( V_35 ,
struct V_157 , V_3 ) ;
struct V_123 * V_124 = F_88 ( V_90 , struct V_123 , V_22 ) ;
bool V_92 = F_46 ( V_35 , V_64 ) ;
unsigned long V_44 = V_124 -> V_5 . V_42 . V_44 [ V_118 ] ;
const char * V_36 = F_89 ( V_124 ) ;
char V_55 [ 256 ] , V_114 ;
const char * V_159 = L_11 ;
T_1 V_91 ;
F_47 ( V_35 , V_92 ? V_86 :
V_85 ) ;
V_44 = F_69 ( V_44 , & V_114 ) ;
V_91 = snprintf ( V_55 , sizeof( V_55 ) , L_47 , V_44 ,
V_114 , V_114 == ' ' ? L_18 : L_11 , V_36 ) ;
F_50 ( L_48 , V_55 ) ;
V_44 = V_124 -> V_5 . V_42 . V_44 [ V_45 ] ;
if ( V_44 != 0 ) {
V_158 -> V_160 = true ;
if ( ! V_92 )
F_47 ( V_35 , V_161 ) ;
V_44 = F_69 ( V_44 , & V_114 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_49 , V_44 ,
V_114 , V_114 == ' ' ? L_18 : L_11 ) ;
V_159 = V_55 ;
}
F_49 ( V_159 , V_35 -> V_4 - V_91 ) ;
if ( V_92 )
V_158 -> V_29 = V_124 ;
}
static int F_90 ( struct V_157 * V_158 ,
int V_44 , const char * V_162 ,
void (* F_33)( void * V_37 ) , void * V_37 , int V_38 )
{
struct V_163 * V_164 = V_158 -> V_3 . V_165 ;
struct V_123 * V_166 ;
const char * V_36 , * V_40 = L_50 ;
int V_39 ;
if ( F_35 ( & V_158 -> V_3 , V_40 ,
L_51 ) < 0 )
return - 1 ;
while ( 1 ) {
V_39 = F_36 ( & V_158 -> V_3 , V_38 ) ;
switch ( V_39 ) {
case V_41 :
F_33 ( V_37 ) ;
if ( ! V_158 -> V_167 && V_158 -> V_160 ) {
F_30 ( & V_158 -> V_3 ) ;
V_158 -> V_167 = true ;
}
continue;
case V_144 :
case V_53 :
if ( ! V_158 -> V_29 )
continue;
V_166 = V_158 -> V_29 ;
V_168:
F_91 ( V_164 , V_166 ) ;
if ( F_33 )
F_33 ( V_37 ) ;
V_36 = F_89 ( V_166 ) ;
V_39 = F_70 ( V_166 , V_44 , V_162 ,
V_36 , true , F_33 ,
V_37 , V_38 ) ;
F_38 ( & V_158 -> V_3 , V_40 ) ;
switch ( V_39 ) {
case V_138 :
if ( V_166 -> V_22 . V_25 == & V_164 -> V_33 )
V_166 = F_88 ( V_164 -> V_33 . V_25 , struct V_123 , V_22 ) ;
else
V_166 = F_88 ( V_166 -> V_22 . V_25 , struct V_123 , V_22 ) ;
goto V_168;
case V_139 :
if ( V_166 -> V_22 . V_169 == & V_164 -> V_33 )
V_166 = F_88 ( V_164 -> V_33 . V_169 , struct V_123 , V_22 ) ;
else
V_166 = F_88 ( V_166 -> V_22 . V_169 , struct V_123 , V_22 ) ;
goto V_168;
case V_148 :
if ( ! F_76 ( & V_158 -> V_3 ,
L_36 ) )
continue;
case 'q' :
case F_77 ( 'c' ) :
goto V_54;
default:
continue;
}
case V_145 :
continue;
case V_148 :
if ( ! F_76 ( & V_158 -> V_3 ,
L_36 ) )
continue;
case 'q' :
case F_77 ( 'c' ) :
goto V_54;
default:
continue;
}
}
V_54:
F_41 ( & V_158 -> V_3 ) ;
return V_39 ;
}
static int F_92 ( struct V_163 * V_164 ,
const char * V_162 ,
void (* F_33)( void * V_37 ) , void * V_37 ,
int V_38 )
{
struct V_123 * V_166 ;
struct V_157 V_158 = {
. V_3 = {
. V_33 = & V_164 -> V_33 ,
. V_107 = V_170 ,
. V_108 = V_171 ,
. V_172 = F_87 ,
. V_6 = V_164 -> V_6 ,
. V_165 = V_164 ,
} ,
} ;
F_72 ( L_52 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_36 = F_89 ( V_166 ) ;
T_1 V_173 = strlen ( V_36 ) + 7 ;
if ( V_158 . V_3 . V_4 < V_173 )
V_158 . V_3 . V_4 = V_173 ;
if ( V_166 -> V_58 == NULL )
V_166 -> V_58 = F_93 ( V_36 ) ;
}
return F_90 ( & V_158 , V_164 -> V_6 , V_162 , F_33 ,
V_37 , V_38 ) ;
}
int F_94 ( struct V_163 * V_164 , const char * V_162 ,
void (* F_33)( void * V_37 ) , void * V_37 ,
int V_38 )
{
if ( V_164 -> V_6 == 1 ) {
struct V_123 * V_23 = F_88 ( V_164 -> V_33 . V_25 ,
struct V_123 , V_22 ) ;
const char * V_36 = F_89 ( V_23 ) ;
return F_70 ( V_23 , V_164 -> V_6 , V_162 ,
V_36 , false , F_33 , V_37 ,
V_38 ) ;
}
return F_92 ( V_164 , V_162 ,
F_33 , V_37 , V_38 ) ;
}
