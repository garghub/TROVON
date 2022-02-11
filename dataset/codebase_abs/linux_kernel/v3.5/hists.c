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
char * V_56 , T_1 V_57 )
{
if ( V_14 -> V_9 . V_58 )
return V_14 -> V_9 . V_58 -> V_59 ;
snprintf ( V_56 , V_57 , L_8 V_60 , V_14 -> V_61 ) ;
return V_56 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_62 ,
T_2 V_63 , int V_64 ,
unsigned short V_65 ,
T_3 * V_53 ,
bool * V_66 )
{
struct V_19 * V_17 ;
int V_67 = V_65 , V_4 , V_68 = V_64 * V_69 ;
T_2 V_70 , V_71 ;
if ( V_72 . V_73 == V_74 )
V_70 = V_62 -> V_75 ;
else
V_70 = V_63 ;
V_71 = V_70 ;
V_17 = F_11 ( & V_62 -> V_21 ) ;
while ( V_17 ) {
struct V_16 * V_22 = F_13 ( V_17 , struct V_16 , V_19 ) ;
struct V_19 * V_27 = F_12 ( V_17 ) ;
T_2 V_76 = F_44 ( V_22 ) ;
struct V_13 * V_23 ;
char V_24 = ' ' ;
int V_25 = true ;
int V_77 = 0 ;
V_71 -= V_76 ;
F_14 (chain, &child->val, list) {
char V_78 [ V_79 / 4 + 1 ] , * V_80 ;
const char * V_81 ;
int V_82 ;
bool V_83 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_77 = V_69 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_53 != 0 ) {
-- * V_53 ;
goto V_84;
}
V_80 = NULL ;
V_81 = F_42 ( V_23 , V_78 , sizeof( V_78 ) ) ;
if ( V_83 ) {
double V_85 = V_76 * 100.0 / V_70 ;
if ( F_45 ( & V_80 , L_9 , V_85 , V_81 ) < 0 )
V_81 = L_10 ;
else
V_81 = V_80 ;
}
V_82 = V_86 ;
V_4 = V_2 -> V_3 . V_4 - ( V_68 + V_77 + 2 ) ;
if ( F_46 ( & V_2 -> V_3 , V_65 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_82 = V_87 ;
* V_66 = true ;
}
F_47 ( & V_2 -> V_3 , V_82 ) ;
F_48 ( & V_2 -> V_3 , V_65 , 0 ) ;
F_49 ( L_11 , V_68 + V_77 ) ;
F_50 ( L_12 , V_24 ) ;
F_49 ( V_81 , V_4 ) ;
free ( V_80 ) ;
if ( ++ V_65 == V_2 -> V_3 . V_50 )
goto V_55;
V_84:
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_88 = V_64 + ( V_77 ? 2 : 1 ) ;
V_65 += F_43 ( V_2 , V_22 , V_70 ,
V_88 , V_65 , V_53 ,
V_66 ) ;
}
if ( V_65 == V_2 -> V_3 . V_50 )
goto V_55;
V_17 = V_27 ;
}
V_55:
return V_65 - V_67 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_64 , unsigned short V_65 ,
T_3 * V_53 ,
bool * V_66 )
{
struct V_13 * V_23 ;
int V_67 = V_65 ,
V_68 = V_64 * V_69 ,
V_4 = V_2 -> V_3 . V_4 - V_68 ;
char V_24 = ' ' ;
F_14 (chain, &node->val, list) {
char V_78 [ V_79 / 4 + 1 ] , * V_89 ;
int V_82 ;
V_24 = F_8 ( V_23 ) ;
if ( * V_53 != 0 ) {
-- * V_53 ;
continue;
}
V_82 = V_86 ;
if ( F_46 ( & V_2 -> V_3 , V_65 ) ) {
V_2 -> V_32 = & V_23 -> V_9 ;
V_82 = V_87 ;
* V_66 = true ;
}
V_89 = F_42 ( V_23 , V_78 , sizeof( V_78 ) ) ;
F_48 ( & V_2 -> V_3 , V_65 , 0 ) ;
F_47 ( & V_2 -> V_3 , V_82 ) ;
F_49 ( L_11 , V_68 ) ;
F_50 ( L_12 , V_24 ) ;
F_49 ( V_89 , V_4 - 2 ) ;
if ( ++ V_65 == V_2 -> V_3 . V_50 )
goto V_55;
}
if ( V_24 == '-' )
V_65 += F_43 ( V_2 , V_17 ,
V_2 -> V_5 -> V_43 . V_90 ,
V_64 + 1 , V_65 ,
V_53 ,
V_66 ) ;
V_55:
return V_65 - V_67 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
int V_64 , unsigned short V_65 ,
T_3 * V_53 ,
bool * V_66 )
{
struct V_19 * V_20 ;
int V_67 = V_65 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_65 += F_51 ( V_2 , V_17 , V_64 ,
V_65 , V_53 ,
V_66 ) ;
if ( V_65 == V_2 -> V_3 . V_50 )
break;
}
return V_65 - V_67 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_11 * V_91 ,
unsigned short V_65 )
{
char V_89 [ 256 ] ;
double V_85 ;
int V_92 = 0 ;
int V_4 = V_2 -> V_3 . V_4 - 6 ;
char V_24 = ' ' ;
bool V_93 = F_46 ( & V_2 -> V_3 , V_65 ) ;
T_3 V_53 = V_91 -> V_53 ;
if ( V_93 ) {
V_2 -> V_33 = V_91 ;
V_2 -> V_32 = & V_91 -> V_9 ;
}
if ( V_94 . V_95 ) {
F_22 ( V_91 ) ;
V_24 = F_7 ( V_91 ) ;
}
if ( V_53 == 0 ) {
F_54 ( V_91 , V_89 , sizeof( V_89 ) , V_2 -> V_5 ) ;
V_85 = ( V_91 -> V_96 * 100.0 ) / V_2 -> V_5 -> V_43 . V_90 ;
F_55 ( & V_2 -> V_3 , V_85 , V_93 ) ;
F_48 ( & V_2 -> V_3 , V_65 , 0 ) ;
if ( V_94 . V_95 ) {
F_50 ( L_12 , V_24 ) ;
V_4 -= 2 ;
}
F_50 ( L_13 , V_85 ) ;
if ( ! V_2 -> V_3 . V_97 )
V_4 += 1 ;
if ( ! V_93 || ! V_2 -> V_3 . V_97 )
F_47 ( & V_2 -> V_3 , V_86 ) ;
if ( V_94 . V_98 ) {
F_50 ( L_14 , V_91 -> V_45 ) ;
V_4 -= 12 ;
}
if ( V_94 . V_99 ) {
F_50 ( L_15 V_100 , V_91 -> V_96 ) ;
V_4 -= 13 ;
}
F_49 ( V_89 , V_4 ) ;
++ V_65 ;
++ V_92 ;
} else
-- V_53 ;
if ( V_24 == '-' && V_65 != V_2 -> V_3 . V_50 ) {
V_92 += F_52 ( V_2 , & V_91 -> V_31 ,
1 , V_65 , & V_53 ,
& V_93 ) ;
if ( V_93 )
V_2 -> V_33 = V_91 ;
}
return V_92 ;
}
static void F_56 ( struct V_36 * V_2 )
{
if ( V_2 -> V_49 == NULL ) {
struct V_1 * V_101 ;
V_101 = F_57 ( V_2 , struct V_1 , V_3 ) ;
V_2 -> V_49 = F_11 ( & V_101 -> V_5 -> V_35 ) ;
}
}
static unsigned int F_58 ( struct V_36 * V_2 )
{
unsigned V_65 = 0 ;
struct V_19 * V_20 ;
struct V_1 * V_101 = F_57 ( V_2 , struct V_1 , V_3 ) ;
F_56 ( V_2 ) ;
for ( V_20 = V_2 -> V_49 ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_102 )
continue;
V_65 += F_53 ( V_101 , V_48 , V_65 ) ;
if ( V_65 == V_2 -> V_50 )
break;
}
return V_65 ;
}
static struct V_19 * F_59 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_48 -> V_102 )
return V_20 ;
V_20 = F_12 ( V_20 ) ;
}
return NULL ;
}
static struct V_19 * F_60 ( struct V_19 * V_20 )
{
while ( V_20 != NULL ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( ! V_48 -> V_102 )
return V_20 ;
V_20 = F_61 ( V_20 ) ;
}
return NULL ;
}
static void F_62 ( struct V_36 * V_2 ,
T_3 V_68 , int V_103 )
{
struct V_11 * V_48 ;
struct V_19 * V_20 ;
bool V_25 = true ;
if ( V_2 -> V_6 == 0 )
return;
F_56 ( V_2 ) ;
switch ( V_103 ) {
case V_104 :
V_20 = F_59 ( F_11 ( V_2 -> V_35 ) ) ;
break;
case V_105 :
V_20 = V_2 -> V_49 ;
goto V_106;
case V_107 :
V_20 = F_60 ( F_63 ( V_2 -> V_35 ) ) ;
V_25 = false ;
break;
default:
return;
}
V_48 = F_13 ( V_2 -> V_49 , struct V_11 , V_19 ) ;
V_48 -> V_53 = 0 ;
V_106:
if ( V_68 > 0 ) {
do {
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_9 . V_7 ) {
T_4 V_71 = V_48 -> V_34 - V_48 -> V_53 ;
if ( V_68 > V_71 ) {
V_68 -= V_71 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 += V_68 ;
V_68 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
}
V_20 = F_59 ( F_12 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
-- V_68 ;
V_2 -> V_49 = V_20 ;
} while ( V_68 != 0 );
} else if ( V_68 < 0 ) {
while ( 1 ) {
V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
if ( V_48 -> V_9 . V_7 ) {
if ( V_25 ) {
if ( - V_68 > V_48 -> V_53 ) {
V_68 += V_48 -> V_53 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 += V_68 ;
V_68 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
} else {
if ( - V_68 > V_48 -> V_34 ) {
V_68 += V_48 -> V_34 ;
V_48 -> V_53 = 0 ;
} else {
V_48 -> V_53 = V_48 -> V_34 + V_68 ;
V_68 = 0 ;
V_2 -> V_49 = V_20 ;
break;
}
}
}
V_20 = F_60 ( F_61 ( V_20 ) ) ;
if ( V_20 == NULL )
break;
++ V_68 ;
V_2 -> V_49 = V_20 ;
if ( V_68 == 0 ) {
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
static struct V_1 * F_64 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_65 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_108 = F_58 ;
V_2 -> V_3 . V_109 = F_62 ;
V_2 -> V_3 . V_110 = true ;
if ( V_111 == 1 )
V_2 -> V_112 = V_113 . V_26 . V_27 != NULL ;
else
V_2 -> V_112 = V_114 . V_26 . V_27 != NULL ;
}
return V_2 ;
}
static void F_66 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_67 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_115 * F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_115 ;
}
static int F_34 ( struct V_5 * V_5 , char * V_56 , T_1 V_116 ,
const char * V_37 )
{
char V_117 ;
int V_92 ;
const struct V_118 * V_118 = V_5 -> V_119 ;
const struct V_115 * V_115 = V_5 -> V_120 ;
unsigned long V_121 = V_5 -> V_43 . V_45 [ V_122 ] ;
T_2 V_45 = V_5 -> V_43 . V_90 ;
V_121 = F_69 ( V_121 , & V_117 ) ;
V_92 = F_70 ( V_56 , V_116 ,
L_16 ,
V_121 , V_117 , V_37 , V_45 ) ;
if ( V_5 -> V_123 )
V_92 += snprintf ( V_56 + V_92 , V_116 - V_92 ,
L_17 , V_5 -> V_123 ) ;
if ( V_115 )
V_92 += F_70 ( V_56 + V_92 , V_116 - V_92 ,
L_18 ,
( V_115 -> V_124 ? V_115 -> V_125 : L_19 ) ,
V_115 -> V_126 ) ;
if ( V_118 )
V_92 += F_70 ( V_56 + V_92 , V_116 - V_92 ,
L_20 , V_118 -> V_127 ) ;
return V_92 ;
}
static inline void F_71 ( char * * V_128 , int V_18 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_18 ; ++ V_129 ) {
free ( V_128 [ V_129 ] ) ;
V_128 [ V_129 ] = NULL ;
}
}
static int F_72 ( struct V_130 * V_131 , int V_45 ,
const char * V_132 , const char * V_37 ,
bool V_133 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_5 * V_5 = & V_131 -> V_5 ;
struct V_1 * V_2 = F_64 ( V_5 ) ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
char * V_128 [ 16 ] ;
int V_138 = 0 ;
int V_40 = - 1 ;
char V_139 [ 64 ] ;
if ( V_2 == NULL )
return - 1 ;
V_137 = F_73 ( 2 ) ;
if ( V_137 == NULL )
goto V_55;
F_74 ( V_132 ) ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
while ( 1 ) {
const struct V_115 * V_115 = NULL ;
const struct V_118 * V_118 = NULL ;
int V_140 = 0 ,
V_141 = - 2 , V_142 = - 2 , V_143 = - 2 ,
V_144 = - 2 , V_145 = - 2 , V_146 = - 2 ;
V_138 = 0 ;
V_40 = F_32 ( V_2 , V_37 , F_33 , V_38 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_115 = F_68 ( V_2 ) ;
V_118 = V_2 -> V_32 -> V_147 ? V_2 -> V_32 -> V_147 -> V_118 : NULL ;
}
switch ( V_40 ) {
case V_148 :
case V_149 :
if ( V_45 == 1 )
continue;
goto V_150;
case 'a' :
if ( ! V_2 -> V_112 ) {
F_31 ( & V_2 -> V_3 , V_39 * 2 ,
L_21
L_22 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_58 == NULL ||
V_2 -> V_32 -> V_147 -> V_118 -> V_151 )
continue;
goto V_152;
case 'd' :
goto V_142;
case 't' :
goto V_143;
case '/' :
if ( F_75 ( L_23 ,
L_24 ,
V_139 , L_25 ,
V_39 * 2 ) == V_54 ) {
V_5 -> V_153 = * V_139 ? V_139 : NULL ;
F_76 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case V_154 :
case 'h' :
case '?' :
F_77 ( & V_2 -> V_3 ,
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40 ) ;
continue;
case V_54 :
case V_155 :
break;
case V_156 : {
const void * V_49 ;
if ( F_78 ( V_137 ) ) {
if ( V_133 )
goto V_150;
continue;
}
V_49 = F_79 ( V_137 ) ;
if ( V_49 == & V_2 -> V_5 -> V_119 )
goto V_157;
if ( V_49 == & V_2 -> V_5 -> V_120 )
goto V_158;
continue;
}
case V_159 :
if ( ! V_133 &&
! F_80 ( & V_2 -> V_3 ,
L_41 ) )
continue;
case 'q' :
case F_81 ( 'c' ) :
goto V_150;
default:
continue;
}
if ( ! V_2 -> V_112 )
goto V_160;
if ( V_111 == 1 ) {
V_135 = V_2 -> V_33 -> V_134 ;
if ( V_2 -> V_32 != NULL &&
V_135 &&
V_135 -> V_161 . V_58 != NULL &&
! V_135 -> V_161 . V_147 -> V_118 -> V_151 &&
F_45 ( & V_128 [ V_138 ] , L_42 ,
V_135 -> V_161 . V_58 -> V_59 ) > 0 )
V_144 = V_138 ++ ;
if ( V_2 -> V_32 != NULL &&
V_135 &&
V_135 -> V_162 . V_58 != NULL &&
! V_135 -> V_162 . V_147 -> V_118 -> V_151 &&
( V_135 -> V_162 . V_58 != V_135 -> V_161 . V_58 ||
V_135 -> V_162 . V_147 -> V_118 != V_135 -> V_161 . V_147 -> V_118 ) &&
F_45 ( & V_128 [ V_138 ] , L_42 ,
V_135 -> V_162 . V_58 -> V_59 ) > 0 )
V_145 = V_138 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_58 != NULL &&
! V_2 -> V_32 -> V_147 -> V_118 -> V_151 &&
F_45 ( & V_128 [ V_138 ] , L_42 ,
V_2 -> V_32 -> V_58 -> V_59 ) > 0 )
V_141 = V_138 ++ ;
}
if ( V_115 != NULL &&
F_45 ( & V_128 [ V_138 ] , L_43 ,
( V_2 -> V_5 -> V_120 ? L_44 : L_45 ) ,
( V_115 -> V_124 ? V_115 -> V_125 : L_19 ) ,
V_115 -> V_126 ) > 0 )
V_143 = V_138 ++ ;
if ( V_118 != NULL &&
F_45 ( & V_128 [ V_138 ] , L_46 ,
( V_2 -> V_5 -> V_119 ? L_44 : L_45 ) ,
( V_118 -> V_163 ? L_47 : V_118 -> V_127 ) ) > 0 )
V_142 = V_138 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_147 != NULL &&
F_45 ( & V_128 [ V_138 ] , L_48 ) > 0 )
V_146 = V_138 ++ ;
V_160:
V_128 [ V_138 ++ ] = ( char * ) L_49 ;
V_164:
V_140 = F_82 ( V_138 , V_128 ) ;
if ( V_140 == V_138 - 1 )
break;
if ( V_140 == - 1 ) {
F_71 ( V_128 , V_138 - 1 ) ;
continue;
}
if ( V_140 == V_141 || V_140 == V_145 || V_140 == V_144 ) {
struct V_11 * V_12 ;
int V_165 ;
V_152:
V_12 = F_67 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_140 == V_144 ) {
V_12 -> V_9 . V_58 = V_12 -> V_134 -> V_161 . V_58 ;
V_12 -> V_9 . V_147 = V_12 -> V_134 -> V_161 . V_147 ;
} else if ( V_140 == V_145 ) {
V_12 -> V_9 . V_58 = V_12 -> V_134 -> V_162 . V_58 ;
V_12 -> V_9 . V_147 = V_12 -> V_134 -> V_162 . V_147 ;
}
V_12 -> V_166 = true ;
V_165 = F_83 ( V_12 , V_131 -> V_167 ,
F_33 , V_38 , V_39 ) ;
V_12 -> V_166 = false ;
if ( ( V_165 == 'q' || V_165 == F_81 ( 'c' ) )
&& V_145 != - 2 && V_144 != - 2 )
goto V_164;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_165 )
F_84 ( & V_2 -> V_3 ) ;
} else if ( V_140 == V_146 )
F_85 ( V_2 -> V_32 -> V_147 ) ;
else if ( V_140 == V_142 ) {
V_142:
if ( V_2 -> V_5 -> V_119 ) {
F_86 ( V_137 , & V_2 -> V_5 -> V_119 ) ;
V_157:
F_39 () ;
V_2 -> V_5 -> V_119 = NULL ;
V_168 . V_169 = false ;
} else {
if ( V_118 == NULL )
continue;
F_40 ( L_50 ,
V_118 -> V_163 ? L_47 : V_118 -> V_127 ) ;
V_2 -> V_5 -> V_119 = V_118 ;
V_168 . V_169 = true ;
F_87 ( V_137 , & V_2 -> V_5 -> V_119 ) ;
}
F_88 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_140 == V_143 ) {
V_143:
if ( V_2 -> V_5 -> V_120 ) {
F_86 ( V_137 , & V_2 -> V_5 -> V_120 ) ;
V_158:
F_39 () ;
V_2 -> V_5 -> V_120 = NULL ;
V_170 . V_169 = false ;
} else {
F_40 ( L_51 ,
V_115 -> V_124 ? V_115 -> V_125 : L_19 ,
V_115 -> V_126 ) ;
V_2 -> V_5 -> V_120 = V_115 ;
V_170 . V_169 = true ;
F_87 ( V_137 , & V_2 -> V_5 -> V_120 ) ;
}
F_89 ( V_5 ) ;
F_3 ( V_2 ) ;
}
}
V_150:
F_90 ( V_137 ) ;
V_55:
F_66 ( V_2 ) ;
F_71 ( V_128 , V_138 - 1 ) ;
return V_40 ;
}
static void F_91 ( struct V_36 * V_2 ,
void * V_91 , int V_65 )
{
struct V_171 * V_172 = F_57 ( V_2 ,
struct V_171 , V_3 ) ;
struct V_130 * V_131 = F_92 ( V_91 , struct V_130 , V_17 ) ;
bool V_93 = F_46 ( V_2 , V_65 ) ;
unsigned long V_45 = V_131 -> V_5 . V_43 . V_45 [ V_122 ] ;
const char * V_37 = F_93 ( V_131 ) ;
char V_56 [ 256 ] , V_117 ;
const char * V_173 = L_11 ;
T_1 V_92 ;
F_47 ( V_2 , V_93 ? V_87 :
V_86 ) ;
V_45 = F_69 ( V_45 , & V_117 ) ;
V_92 = F_70 ( V_56 , sizeof( V_56 ) , L_52 , V_45 ,
V_117 , V_117 == ' ' ? L_19 : L_11 , V_37 ) ;
F_50 ( L_53 , V_56 ) ;
V_45 = V_131 -> V_5 . V_43 . V_45 [ V_46 ] ;
if ( V_45 != 0 ) {
V_172 -> V_174 = true ;
if ( ! V_93 )
F_47 ( V_2 , V_175 ) ;
V_45 = F_69 ( V_45 , & V_117 ) ;
V_92 += F_70 ( V_56 , sizeof( V_56 ) , L_54 ,
V_45 , V_117 , V_117 == ' ' ? L_19 : L_11 ) ;
V_173 = V_56 ;
}
F_49 ( V_173 , V_2 -> V_4 - V_92 ) ;
if ( V_93 )
V_172 -> V_32 = V_131 ;
}
static int F_94 ( struct V_171 * V_172 ,
int V_45 , const char * V_176 ,
void (* F_33)( void * V_38 ) , void * V_38 , int V_39 )
{
struct V_177 * V_178 = V_172 -> V_3 . V_179 ;
struct V_130 * V_180 ;
const char * V_37 , * V_41 = L_55 ;
int V_40 ;
if ( F_35 ( & V_172 -> V_3 , V_41 ,
L_56 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_36 ( & V_172 -> V_3 , V_39 ) ;
switch ( V_40 ) {
case V_42 :
F_33 ( V_38 ) ;
if ( ! V_172 -> V_181 && V_172 -> V_174 ) {
F_30 ( & V_172 -> V_3 ) ;
V_172 -> V_181 = true ;
}
continue;
case V_155 :
case V_54 :
if ( ! V_172 -> V_32 )
continue;
V_180 = V_172 -> V_32 ;
V_182:
F_95 ( V_178 , V_180 ) ;
if ( F_33 )
F_33 ( V_38 ) ;
V_37 = F_93 ( V_180 ) ;
V_40 = F_72 ( V_180 , V_45 , V_176 ,
V_37 , true , F_33 ,
V_38 , V_39 ) ;
F_38 ( & V_172 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_148 :
if ( V_180 -> V_17 . V_27 == & V_178 -> V_35 )
V_180 = F_92 ( V_178 -> V_35 . V_27 , struct V_130 , V_17 ) ;
else
V_180 = F_92 ( V_180 -> V_17 . V_27 , struct V_130 , V_17 ) ;
goto V_182;
case V_149 :
if ( V_180 -> V_17 . V_183 == & V_178 -> V_35 )
V_180 = F_92 ( V_178 -> V_35 . V_183 , struct V_130 , V_17 ) ;
else
V_180 = F_92 ( V_180 -> V_17 . V_183 , struct V_130 , V_17 ) ;
goto V_182;
case V_159 :
if ( ! F_80 ( & V_172 -> V_3 ,
L_41 ) )
continue;
case 'q' :
case F_81 ( 'c' ) :
goto V_55;
default:
continue;
}
case V_156 :
continue;
case V_159 :
if ( ! F_80 ( & V_172 -> V_3 ,
L_41 ) )
continue;
case 'q' :
case F_81 ( 'c' ) :
goto V_55;
default:
continue;
}
}
V_55:
F_41 ( & V_172 -> V_3 ) ;
return V_40 ;
}
static int F_96 ( struct V_177 * V_178 ,
const char * V_176 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_130 * V_180 ;
struct V_171 V_172 = {
. V_3 = {
. V_35 = & V_178 -> V_35 ,
. V_108 = V_184 ,
. V_109 = V_185 ,
. V_186 = F_91 ,
. V_6 = V_178 -> V_6 ,
. V_179 = V_178 ,
} ,
} ;
F_74 ( L_57 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_93 ( V_180 ) ;
T_1 V_187 = strlen ( V_37 ) + 7 ;
if ( V_172 . V_3 . V_4 < V_187 )
V_172 . V_3 . V_4 = V_187 ;
if ( V_180 -> V_59 == NULL )
V_180 -> V_59 = F_97 ( V_37 ) ;
}
return F_94 ( & V_172 , V_178 -> V_6 , V_176 , F_33 ,
V_38 , V_39 ) ;
}
int F_98 ( struct V_177 * V_178 , const char * V_176 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
if ( V_178 -> V_6 == 1 ) {
struct V_130 * V_25 = F_92 ( V_178 -> V_35 . V_27 ,
struct V_130 , V_17 ) ;
const char * V_37 = F_93 ( V_25 ) ;
return F_72 ( V_25 , V_178 -> V_6 , V_176 ,
V_37 , false , F_33 , V_38 ,
V_39 ) ;
}
return F_96 ( V_178 , V_176 ,
F_33 , V_38 , V_39 ) ;
}
