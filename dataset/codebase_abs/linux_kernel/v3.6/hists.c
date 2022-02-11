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
static int F_64 ( struct V_1 * V_2 ,
struct V_16 * V_62 ,
T_2 V_63 , int V_64 ,
T_5 * V_108 )
{
struct V_19 * V_17 ;
int V_68 = V_64 * V_69 ;
T_2 V_70 , V_71 ;
int V_92 = 0 ;
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
bool V_83 = V_25 ;
if ( V_25 )
V_25 = false ;
else
V_77 = V_69 ;
V_24 = F_8 ( V_23 ) ;
V_80 = NULL ;
V_81 = F_42 ( V_23 , V_78 , sizeof( V_78 ) ) ;
if ( V_83 ) {
double V_85 = V_76 * 100.0 / V_70 ;
if ( F_45 ( & V_80 , L_9 , V_85 , V_81 ) < 0 )
V_81 = L_10 ;
else
V_81 = V_80 ;
}
V_92 += fprintf ( V_108 , L_16 , V_68 + V_77 , L_11 , V_24 , V_81 ) ;
free ( V_80 ) ;
if ( V_24 == '+' )
break;
}
if ( V_24 == '-' ) {
const int V_88 = V_64 + ( V_77 ? 2 : 1 ) ;
V_92 += F_64 ( V_2 , V_22 , V_70 ,
V_88 , V_108 ) ;
}
V_17 = V_27 ;
}
return V_92 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
int V_64 , T_5 * V_108 )
{
struct V_13 * V_23 ;
int V_68 = V_64 * V_69 ;
char V_24 = ' ' ;
int V_92 = 0 ;
F_14 (chain, &node->val, list) {
char V_78 [ V_79 / 4 + 1 ] , * V_89 ;
V_24 = F_8 ( V_23 ) ;
V_89 = F_42 ( V_23 , V_78 , sizeof( V_78 ) ) ;
V_92 += fprintf ( V_108 , L_16 , V_68 , L_11 , V_24 , V_89 ) ;
}
if ( V_24 == '-' )
V_92 += F_64 ( V_2 , V_17 ,
V_2 -> V_5 -> V_43 . V_90 ,
V_64 + 1 , V_108 ) ;
return V_92 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_21 * V_23 , int V_64 , T_5 * V_108 )
{
struct V_19 * V_20 ;
int V_92 = 0 ;
for ( V_20 = F_11 ( V_23 ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_17 = F_13 ( V_20 , struct V_16 , V_19 ) ;
V_92 += F_65 ( V_2 , V_17 , V_64 , V_108 ) ;
}
return V_92 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_5 * V_108 )
{
char V_89 [ 8192 ] ;
double V_85 ;
int V_92 = 0 ;
char V_24 = ' ' ;
if ( V_94 . V_95 )
V_24 = F_7 ( V_12 ) ;
F_54 ( V_12 , V_89 , sizeof( V_89 ) , V_2 -> V_5 ) ;
V_85 = ( V_12 -> V_96 * 100.0 ) / V_2 -> V_5 -> V_43 . V_90 ;
if ( V_94 . V_95 )
V_92 += fprintf ( V_108 , L_12 , V_24 ) ;
V_92 += fprintf ( V_108 , L_13 , V_85 ) ;
if ( V_94 . V_98 )
V_92 += fprintf ( V_108 , L_14 , V_12 -> V_45 ) ;
if ( V_94 . V_99 )
V_92 += fprintf ( V_108 , L_15 V_100 , V_12 -> V_96 ) ;
V_92 += fprintf ( V_108 , L_17 , F_68 ( V_89 ) ) ;
if ( V_24 == '-' )
V_92 += F_66 ( V_2 , & V_12 -> V_31 , 1 , V_108 ) ;
return V_92 ;
}
static int F_69 ( struct V_1 * V_2 , T_5 * V_108 )
{
struct V_19 * V_20 = F_59 ( F_11 ( V_2 -> V_3 . V_35 ) ) ;
int V_92 = 0 ;
while ( V_20 ) {
struct V_11 * V_48 = F_13 ( V_20 , struct V_11 , V_19 ) ;
V_92 += F_67 ( V_2 , V_48 , V_108 ) ;
V_20 = F_59 ( F_12 ( V_20 ) ) ;
}
return V_92 ;
}
static int F_70 ( struct V_1 * V_2 )
{
char V_109 [ 64 ] ;
T_5 * V_108 ;
while ( 1 ) {
F_71 ( V_109 , sizeof( V_109 ) , L_18 , V_2 -> V_110 ) ;
if ( F_72 ( V_109 , V_111 ) )
break;
if ( ++ V_2 -> V_110 == 8192 ) {
F_40 ( L_19 ) ;
return - 1 ;
}
}
V_108 = fopen ( V_109 , L_20 ) ;
if ( V_108 == NULL ) {
char V_56 [ 64 ] ;
const char * V_112 = F_73 ( V_113 , V_56 , sizeof( V_56 ) ) ;
F_40 ( L_21 , V_109 , V_112 ) ;
return - 1 ;
}
++ V_2 -> V_110 ;
F_69 ( V_2 , V_108 ) ;
fclose ( V_108 ) ;
F_40 ( L_22 , V_109 ) ;
return 0 ;
}
static struct V_1 * F_74 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_75 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_3 . V_114 = F_58 ;
V_2 -> V_3 . V_115 = F_62 ;
V_2 -> V_3 . V_116 = true ;
if ( V_117 == 1 )
V_2 -> V_118 = V_119 . V_26 . V_27 != NULL ;
else
V_2 -> V_118 = V_120 . V_26 . V_27 != NULL ;
}
return V_2 ;
}
static void F_76 ( struct V_1 * V_2 )
{
free ( V_2 ) ;
}
static struct V_11 * F_77 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static struct V_121 * F_78 ( struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_121 ;
}
static int F_34 ( struct V_5 * V_5 , char * V_56 , T_1 V_122 ,
const char * V_37 )
{
char V_123 ;
int V_92 ;
const struct V_124 * V_124 = V_5 -> V_125 ;
const struct V_121 * V_121 = V_5 -> V_126 ;
unsigned long V_127 = V_5 -> V_43 . V_45 [ V_128 ] ;
T_2 V_45 = V_5 -> V_43 . V_90 ;
V_127 = F_79 ( V_127 , & V_123 ) ;
V_92 = F_71 ( V_56 , V_122 ,
L_23 ,
V_127 , V_123 , V_37 , V_45 ) ;
if ( V_5 -> V_129 )
V_92 += snprintf ( V_56 + V_92 , V_122 - V_92 ,
L_24 , V_5 -> V_129 ) ;
if ( V_121 )
V_92 += F_71 ( V_56 + V_92 , V_122 - V_92 ,
L_25 ,
( V_121 -> V_130 ? V_121 -> V_131 : L_26 ) ,
V_121 -> V_132 ) ;
if ( V_124 )
V_92 += F_71 ( V_56 + V_92 , V_122 - V_92 ,
L_27 , V_124 -> V_133 ) ;
return V_92 ;
}
static inline void F_80 ( char * * V_134 , int V_18 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_18 ; ++ V_135 ) {
free ( V_134 [ V_135 ] ) ;
V_134 [ V_135 ] = NULL ;
}
}
static int F_81 ( struct V_136 * V_137 , int V_45 ,
const char * V_138 , const char * V_37 ,
bool V_139 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_5 * V_5 = & V_137 -> V_5 ;
struct V_1 * V_2 = F_74 ( V_5 ) ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
char * V_134 [ 16 ] ;
int V_144 = 0 ;
int V_40 = - 1 ;
char V_145 [ 64 ] ;
if ( V_2 == NULL )
return - 1 ;
V_143 = F_82 ( 2 ) ;
if ( V_143 == NULL )
goto V_55;
F_83 ( V_138 ) ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
while ( 1 ) {
const struct V_121 * V_121 = NULL ;
const struct V_124 * V_124 = NULL ;
int V_146 = 0 ,
V_147 = - 2 , V_148 = - 2 , V_149 = - 2 ,
V_150 = - 2 , V_151 = - 2 , V_152 = - 2 ;
V_144 = 0 ;
V_40 = F_32 ( V_2 , V_37 , F_33 , V_38 , V_39 ) ;
if ( V_2 -> V_33 != NULL ) {
V_121 = F_78 ( V_2 ) ;
V_124 = V_2 -> V_32 -> V_153 ? V_2 -> V_32 -> V_153 -> V_124 : NULL ;
}
switch ( V_40 ) {
case V_154 :
case V_155 :
if ( V_45 == 1 )
continue;
goto V_156;
case 'a' :
if ( ! V_2 -> V_118 ) {
F_31 ( & V_2 -> V_3 , V_39 * 2 ,
L_28
L_29 ) ;
continue;
}
if ( V_2 -> V_32 == NULL ||
V_2 -> V_32 -> V_58 == NULL ||
V_2 -> V_32 -> V_153 -> V_124 -> V_157 )
continue;
goto V_158;
case 'P' :
F_70 ( V_2 ) ;
continue;
case 'd' :
goto V_148;
case 't' :
goto V_149;
case '/' :
if ( F_84 ( L_30 ,
L_31 ,
V_145 , L_32 ,
V_39 * 2 ) == V_54 ) {
V_5 -> V_159 = * V_145 ? V_145 : NULL ;
F_85 ( V_5 ) ;
F_3 ( V_2 ) ;
}
continue;
case V_160 :
case 'h' :
case '?' :
F_86 ( & V_2 -> V_3 ,
L_33
L_34
L_35
L_36
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
L_48 ) ;
continue;
case V_54 :
case V_161 :
break;
case V_162 : {
const void * V_49 ;
if ( F_87 ( V_143 ) ) {
if ( V_139 )
goto V_156;
continue;
}
V_49 = F_88 ( V_143 ) ;
if ( V_49 == & V_2 -> V_5 -> V_125 )
goto V_163;
if ( V_49 == & V_2 -> V_5 -> V_126 )
goto V_164;
continue;
}
case V_165 :
if ( ! V_139 &&
! F_89 ( & V_2 -> V_3 ,
L_49 ) )
continue;
case 'q' :
case F_90 ( 'c' ) :
goto V_156;
default:
continue;
}
if ( ! V_2 -> V_118 )
goto V_166;
if ( V_117 == 1 ) {
V_141 = V_2 -> V_33 -> V_140 ;
if ( V_2 -> V_32 != NULL &&
V_141 &&
V_141 -> V_167 . V_58 != NULL &&
! V_141 -> V_167 . V_153 -> V_124 -> V_157 &&
F_45 ( & V_134 [ V_144 ] , L_50 ,
V_141 -> V_167 . V_58 -> V_59 ) > 0 )
V_150 = V_144 ++ ;
if ( V_2 -> V_32 != NULL &&
V_141 &&
V_141 -> V_168 . V_58 != NULL &&
! V_141 -> V_168 . V_153 -> V_124 -> V_157 &&
( V_141 -> V_168 . V_58 != V_141 -> V_167 . V_58 ||
V_141 -> V_168 . V_153 -> V_124 != V_141 -> V_167 . V_153 -> V_124 ) &&
F_45 ( & V_134 [ V_144 ] , L_50 ,
V_141 -> V_168 . V_58 -> V_59 ) > 0 )
V_151 = V_144 ++ ;
} else {
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_58 != NULL &&
! V_2 -> V_32 -> V_153 -> V_124 -> V_157 &&
F_45 ( & V_134 [ V_144 ] , L_50 ,
V_2 -> V_32 -> V_58 -> V_59 ) > 0 )
V_147 = V_144 ++ ;
}
if ( V_121 != NULL &&
F_45 ( & V_134 [ V_144 ] , L_51 ,
( V_2 -> V_5 -> V_126 ? L_52 : L_53 ) ,
( V_121 -> V_130 ? V_121 -> V_131 : L_26 ) ,
V_121 -> V_132 ) > 0 )
V_149 = V_144 ++ ;
if ( V_124 != NULL &&
F_45 ( & V_134 [ V_144 ] , L_54 ,
( V_2 -> V_5 -> V_125 ? L_52 : L_53 ) ,
( V_124 -> V_169 ? L_55 : V_124 -> V_133 ) ) > 0 )
V_148 = V_144 ++ ;
if ( V_2 -> V_32 != NULL &&
V_2 -> V_32 -> V_153 != NULL &&
F_45 ( & V_134 [ V_144 ] , L_56 ) > 0 )
V_152 = V_144 ++ ;
V_166:
V_134 [ V_144 ++ ] = ( char * ) L_57 ;
V_170:
V_146 = F_91 ( V_144 , V_134 ) ;
if ( V_146 == V_144 - 1 )
break;
if ( V_146 == - 1 ) {
F_80 ( V_134 , V_144 - 1 ) ;
continue;
}
if ( V_146 == V_147 || V_146 == V_151 || V_146 == V_150 ) {
struct V_11 * V_12 ;
int V_112 ;
V_158:
V_12 = F_77 ( V_2 ) ;
if ( V_12 == NULL )
continue;
if ( V_146 == V_150 ) {
V_12 -> V_9 . V_58 = V_12 -> V_140 -> V_167 . V_58 ;
V_12 -> V_9 . V_153 = V_12 -> V_140 -> V_167 . V_153 ;
} else if ( V_146 == V_151 ) {
V_12 -> V_9 . V_58 = V_12 -> V_140 -> V_168 . V_58 ;
V_12 -> V_9 . V_153 = V_12 -> V_140 -> V_168 . V_153 ;
}
V_12 -> V_171 = true ;
V_112 = F_92 ( V_12 , V_137 -> V_172 ,
F_33 , V_38 , V_39 ) ;
V_12 -> V_171 = false ;
if ( ( V_112 == 'q' || V_112 == F_90 ( 'c' ) )
&& V_151 != - 2 && V_150 != - 2 )
goto V_170;
F_37 ( & V_2 -> V_3 , V_2 -> V_5 -> V_6 ) ;
if ( V_112 )
F_93 ( & V_2 -> V_3 ) ;
} else if ( V_146 == V_152 )
F_94 ( V_2 -> V_32 -> V_153 ) ;
else if ( V_146 == V_148 ) {
V_148:
if ( V_2 -> V_5 -> V_125 ) {
F_95 ( V_143 , & V_2 -> V_5 -> V_125 ) ;
V_163:
F_39 () ;
V_2 -> V_5 -> V_125 = NULL ;
V_173 . V_174 = false ;
} else {
if ( V_124 == NULL )
continue;
F_40 ( L_58 ,
V_124 -> V_169 ? L_55 : V_124 -> V_133 ) ;
V_2 -> V_5 -> V_125 = V_124 ;
V_173 . V_174 = true ;
F_96 ( V_143 , & V_2 -> V_5 -> V_125 ) ;
}
F_97 ( V_5 ) ;
F_3 ( V_2 ) ;
} else if ( V_146 == V_149 ) {
V_149:
if ( V_2 -> V_5 -> V_126 ) {
F_95 ( V_143 , & V_2 -> V_5 -> V_126 ) ;
V_164:
F_39 () ;
V_2 -> V_5 -> V_126 = NULL ;
V_175 . V_174 = false ;
} else {
F_40 ( L_59 ,
V_121 -> V_130 ? V_121 -> V_131 : L_26 ,
V_121 -> V_132 ) ;
V_2 -> V_5 -> V_126 = V_121 ;
V_175 . V_174 = true ;
F_96 ( V_143 , & V_2 -> V_5 -> V_126 ) ;
}
F_98 ( V_5 ) ;
F_3 ( V_2 ) ;
}
}
V_156:
F_99 ( V_143 ) ;
V_55:
F_76 ( V_2 ) ;
F_80 ( V_134 , V_144 - 1 ) ;
return V_40 ;
}
static void F_100 ( struct V_36 * V_2 ,
void * V_91 , int V_65 )
{
struct V_176 * V_177 = F_57 ( V_2 ,
struct V_176 , V_3 ) ;
struct V_136 * V_137 = F_101 ( V_91 , struct V_136 , V_17 ) ;
bool V_93 = F_46 ( V_2 , V_65 ) ;
unsigned long V_45 = V_137 -> V_5 . V_43 . V_45 [ V_128 ] ;
const char * V_37 = F_102 ( V_137 ) ;
char V_56 [ 256 ] , V_123 ;
const char * V_178 = L_11 ;
T_1 V_92 ;
F_47 ( V_2 , V_93 ? V_87 :
V_86 ) ;
V_45 = F_79 ( V_45 , & V_123 ) ;
V_92 = F_71 ( V_56 , sizeof( V_56 ) , L_60 , V_45 ,
V_123 , V_123 == ' ' ? L_26 : L_11 , V_37 ) ;
F_50 ( L_61 , V_56 ) ;
V_45 = V_137 -> V_5 . V_43 . V_45 [ V_46 ] ;
if ( V_45 != 0 ) {
V_177 -> V_179 = true ;
if ( ! V_93 )
F_47 ( V_2 , V_180 ) ;
V_45 = F_79 ( V_45 , & V_123 ) ;
V_92 += F_71 ( V_56 , sizeof( V_56 ) , L_62 ,
V_45 , V_123 , V_123 == ' ' ? L_26 : L_11 ) ;
V_178 = V_56 ;
}
F_49 ( V_178 , V_2 -> V_4 - V_92 ) ;
if ( V_93 )
V_177 -> V_32 = V_137 ;
}
static int F_103 ( struct V_176 * V_177 ,
int V_45 , const char * V_181 ,
void (* F_33)( void * V_38 ) , void * V_38 , int V_39 )
{
struct V_182 * V_183 = V_177 -> V_3 . V_184 ;
struct V_136 * V_185 ;
const char * V_37 , * V_41 = L_63 ;
int V_40 ;
if ( F_35 ( & V_177 -> V_3 , V_41 ,
L_64 ) < 0 )
return - 1 ;
while ( 1 ) {
V_40 = F_36 ( & V_177 -> V_3 , V_39 ) ;
switch ( V_40 ) {
case V_42 :
F_33 ( V_38 ) ;
if ( ! V_177 -> V_186 && V_177 -> V_179 ) {
F_30 ( & V_177 -> V_3 ) ;
V_177 -> V_186 = true ;
}
continue;
case V_161 :
case V_54 :
if ( ! V_177 -> V_32 )
continue;
V_185 = V_177 -> V_32 ;
V_187:
F_104 ( V_183 , V_185 ) ;
if ( F_33 )
F_33 ( V_38 ) ;
V_37 = F_102 ( V_185 ) ;
V_40 = F_81 ( V_185 , V_45 , V_181 ,
V_37 , true , F_33 ,
V_38 , V_39 ) ;
F_38 ( & V_177 -> V_3 , V_41 ) ;
switch ( V_40 ) {
case V_154 :
if ( V_185 -> V_17 . V_27 == & V_183 -> V_35 )
V_185 = F_101 ( V_183 -> V_35 . V_27 , struct V_136 , V_17 ) ;
else
V_185 = F_101 ( V_185 -> V_17 . V_27 , struct V_136 , V_17 ) ;
goto V_187;
case V_155 :
if ( V_185 -> V_17 . V_188 == & V_183 -> V_35 )
V_185 = F_101 ( V_183 -> V_35 . V_188 , struct V_136 , V_17 ) ;
else
V_185 = F_101 ( V_185 -> V_17 . V_188 , struct V_136 , V_17 ) ;
goto V_187;
case V_165 :
if ( ! F_89 ( & V_177 -> V_3 ,
L_49 ) )
continue;
case 'q' :
case F_90 ( 'c' ) :
goto V_55;
default:
continue;
}
case V_162 :
continue;
case V_165 :
if ( ! F_89 ( & V_177 -> V_3 ,
L_49 ) )
continue;
case 'q' :
case F_90 ( 'c' ) :
goto V_55;
default:
continue;
}
}
V_55:
F_41 ( & V_177 -> V_3 ) ;
return V_40 ;
}
static int F_105 ( struct V_182 * V_183 ,
const char * V_181 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
struct V_136 * V_185 ;
struct V_176 V_177 = {
. V_3 = {
. V_35 = & V_183 -> V_35 ,
. V_114 = V_189 ,
. V_115 = V_190 ,
. V_191 = F_100 ,
. V_6 = V_183 -> V_6 ,
. V_184 = V_183 ,
} ,
} ;
F_83 ( L_65 ) ;
F_14 (pos, &evlist->entries, node) {
const char * V_37 = F_102 ( V_185 ) ;
T_1 V_192 = strlen ( V_37 ) + 7 ;
if ( V_177 . V_3 . V_4 < V_192 )
V_177 . V_3 . V_4 = V_192 ;
}
return F_103 ( & V_177 , V_183 -> V_6 , V_181 , F_33 ,
V_38 , V_39 ) ;
}
int F_106 ( struct V_182 * V_183 , const char * V_181 ,
void (* F_33)( void * V_38 ) , void * V_38 ,
int V_39 )
{
if ( V_183 -> V_6 == 1 ) {
struct V_136 * V_25 = F_101 ( V_183 -> V_35 . V_27 ,
struct V_136 , V_17 ) ;
const char * V_37 = F_102 ( V_25 ) ;
return F_81 ( V_25 , V_183 -> V_6 , V_181 ,
V_37 , false , F_33 , V_38 ,
V_39 ) ;
}
return F_105 ( V_183 , V_181 ,
F_33 , V_38 , V_39 ) ;
}
