static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) || V_2 -> V_4 || V_5 . V_6 ;
}
static int F_3 ( struct V_1 * V_7 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 = V_7 -> V_3 ;
int V_10 = 0 ;
for ( V_9 = F_4 ( & V_3 -> V_11 ) ;
( V_9 = F_5 ( V_9 , V_7 -> V_4 ) ) != NULL ;
V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_13 =
F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_13 -> V_14 )
V_10 += V_13 -> V_15 ;
}
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_16 ;
if ( F_1 ( V_2 ) )
V_16 = V_2 -> V_17 ;
else
V_16 = V_2 -> V_3 -> V_16 ;
V_2 -> V_18 = F_3 ( V_2 ) ;
return V_16 + V_2 -> V_18 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_19 * V_7 = & V_2 -> V_20 ;
T_2 V_21 = V_2 -> V_22 ? 1 : 0 , V_23 ;
V_7 -> V_24 = V_7 -> V_25 - V_21 ;
V_23 = V_7 -> V_26 - V_7 -> V_27 ;
if ( V_23 >= V_7 -> V_24 )
V_7 -> V_26 -= V_23 - V_7 -> V_24 + 1 ;
}
static void F_10 ( struct V_19 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
V_7 -> V_28 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_7 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_7 , int V_29 , int V_30 )
{
T_2 V_21 = V_7 -> V_22 ? 1 : 0 ;
F_15 ( & V_7 -> V_20 , V_29 + V_21 , V_30 ) ;
}
static void F_16 ( struct V_1 * V_7 )
{
V_7 -> V_18 = 0 ;
F_17 ( V_7 ) ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_10 ( & V_7 -> V_20 ) ;
F_18 ( & V_7 -> V_20 ) ;
}
static char F_19 ( bool V_14 )
{
return V_14 ? '-' : '+' ;
}
static char F_20 ( const struct V_12 * V_13 )
{
return V_13 -> V_31 ? F_19 ( V_13 -> V_14 ) : ' ' ;
}
static char F_21 ( const struct V_32 * V_33 )
{
return V_33 -> V_31 ? F_19 ( V_33 -> V_14 ) : ' ' ;
}
static void F_22 ( struct V_32 * V_33 , bool V_34 )
{
V_33 -> V_14 = V_34 ? V_33 -> V_31 : false ;
}
static int F_23 ( struct V_35 * V_36 )
{
int V_37 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
F_24 (chain, &child->val, list) {
++ V_37 ;
V_41 = F_21 ( V_40 ) ;
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' )
V_37 += F_23 ( V_39 ) ;
}
return V_37 ;
}
static int F_25 ( struct V_35 * V_36 )
{
struct V_32 * V_40 ;
char V_41 = 0 ;
int V_37 = 0 ;
F_24 (chain, &node->parent_val, list) {
if ( ! V_41 ) {
V_41 = F_21 ( V_40 ) ;
if ( V_41 == '+' )
return 1 ;
}
V_37 ++ ;
}
F_24 (chain, &node->val, list) {
if ( ! V_41 ) {
V_41 = F_21 ( V_40 ) ;
if ( V_41 == '+' )
return 1 ;
}
V_37 ++ ;
}
return V_37 ;
}
static int F_26 ( struct V_35 * V_36 V_42 )
{
return 1 ;
}
static int F_27 ( struct V_35 * V_36 )
{
struct V_32 * V_40 ;
bool V_14 = false ;
int V_37 = 0 ;
if ( V_43 . V_44 == V_45 )
return F_25 ( V_36 ) ;
else if ( V_43 . V_44 == V_46 )
return F_26 ( V_36 ) ;
F_24 (chain, &node->val, list) {
++ V_37 ;
V_14 = V_40 -> V_14 ;
}
if ( V_14 )
V_37 += F_23 ( V_36 ) ;
return V_37 ;
}
static int F_28 ( struct V_38 * V_40 )
{
struct V_8 * V_9 ;
int V_37 = 0 ;
for ( V_9 = F_4 ( V_40 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
V_37 += F_27 ( V_36 ) ;
}
return V_37 ;
}
static bool F_29 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return false ;
if ( ! V_13 -> V_31 )
return false ;
V_13 -> V_14 = ! V_13 -> V_14 ;
return true ;
}
static bool F_30 ( struct V_32 * V_33 )
{
if ( ! V_33 )
return false ;
if ( ! V_33 -> V_31 )
return false ;
V_33 -> V_14 = ! V_33 -> V_14 ;
return true ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_4 ( & V_36 -> V_38 ) ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
bool V_47 = true ;
F_24 (chain, &child->val, list) {
if ( V_47 ) {
V_47 = false ;
V_40 -> V_31 = V_40 -> V_48 . V_49 != & V_39 -> V_50 ||
! F_32 ( & V_39 -> V_38 ) ;
} else
V_40 -> V_31 = V_40 -> V_48 . V_49 == & V_39 -> V_50 &&
! F_32 ( & V_39 -> V_38 ) ;
}
F_31 ( V_39 ) ;
}
}
static void F_33 ( struct V_35 * V_36 ,
bool V_51 )
{
struct V_32 * V_40 ;
V_40 = F_34 ( V_36 -> V_50 . V_49 , struct V_32 , V_48 ) ;
V_40 -> V_31 = V_51 ;
if ( V_36 -> V_50 . V_49 != V_36 -> V_50 . V_52 ) {
V_40 = F_34 ( V_36 -> V_50 . V_52 , struct V_32 , V_48 ) ;
V_40 -> V_31 = ! F_32 ( & V_36 -> V_38 ) ;
}
F_31 ( V_36 ) ;
}
static void F_35 ( struct V_38 * V_53 )
{
struct V_8 * V_9 = F_4 ( V_53 ) ;
bool V_51 = V_9 && F_6 ( V_9 ) ;
for ( V_9 = F_4 ( V_53 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
F_33 ( V_36 , V_51 ) ;
if ( V_43 . V_44 == V_45 ||
V_43 . V_44 == V_46 )
F_36 ( V_36 ) ;
}
}
static void F_37 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_54 ) {
V_13 -> V_31 = ! F_32 ( & V_13 -> V_55 ) ;
F_35 ( & V_13 -> V_55 ) ;
V_13 -> V_54 = true ;
}
}
static bool F_38 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_56 ;
struct V_57 * V_58 = V_7 -> V_59 ;
struct V_32 * V_33 = F_11 ( V_58 , struct V_32 , V_58 ) ;
bool V_31 ;
if ( ! V_13 || ! V_58 )
return false ;
if ( V_58 == & V_13 -> V_58 )
V_31 = F_29 ( V_13 ) ;
else
V_31 = F_30 ( V_33 ) ;
if ( V_31 ) {
F_37 ( V_13 ) ;
V_7 -> V_20 . V_16 -= V_13 -> V_15 ;
V_7 -> V_18 -= V_13 -> V_15 ;
if ( V_13 -> V_14 )
V_13 -> V_15 = F_28 ( & V_13 -> V_55 ) ;
else
V_13 -> V_15 = 0 ;
V_7 -> V_20 . V_16 += V_13 -> V_15 ;
V_7 -> V_18 += V_13 -> V_15 ;
return true ;
}
return false ;
}
static int F_39 ( struct V_35 * V_36 , bool V_34 )
{
int V_37 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_36 -> V_38 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_39 = F_7 ( V_9 , struct V_35 , V_8 ) ;
struct V_32 * V_40 ;
bool V_31 = false ;
F_24 (chain, &child->val, list) {
++ V_37 ;
F_22 ( V_40 , V_34 ) ;
V_31 = V_40 -> V_31 ;
}
if ( V_31 )
V_37 += F_39 ( V_39 , V_34 ) ;
}
return V_37 ;
}
static int F_40 ( struct V_35 * V_36 , bool V_34 )
{
struct V_32 * V_40 ;
bool V_31 = false ;
int V_37 = 0 ;
F_24 (chain, &node->val, list) {
++ V_37 ;
F_22 ( V_40 , V_34 ) ;
V_31 = V_40 -> V_31 ;
}
if ( V_31 )
V_37 += F_39 ( V_36 , V_34 ) ;
return V_37 ;
}
static int F_41 ( struct V_38 * V_40 , bool V_34 )
{
struct V_8 * V_9 ;
int V_37 = 0 ;
for ( V_9 = F_4 ( V_40 ) ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_35 * V_36 = F_7 ( V_9 , struct V_35 , V_8 ) ;
V_37 += F_40 ( V_36 , V_34 ) ;
}
return V_37 ;
}
static void F_42 ( struct V_12 * V_13 , bool V_34 )
{
F_37 ( V_13 ) ;
V_13 -> V_14 = V_34 ? V_13 -> V_31 : false ;
if ( V_13 -> V_31 ) {
int V_37 = F_41 ( & V_13 -> V_55 , V_34 ) ;
V_13 -> V_15 = V_34 ? V_37 : 0 ;
} else
V_13 -> V_15 = 0 ;
}
static void
F_43 ( struct V_1 * V_7 , bool V_34 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 = V_7 -> V_3 ;
for ( V_9 = F_4 ( & V_3 -> V_11 ) ;
( V_9 = F_5 ( V_9 , V_7 -> V_4 ) ) != NULL ;
V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
F_42 ( V_13 , V_34 ) ;
V_7 -> V_18 += V_13 -> V_15 ;
}
}
static void F_44 ( struct V_1 * V_7 , bool V_34 )
{
V_7 -> V_18 = 0 ;
F_43 ( V_7 , V_34 ) ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_18 ( & V_7 -> V_20 ) ;
}
static void F_45 ( struct V_19 * V_7 )
{
F_46 ( V_7 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_47 ( struct V_1 * V_7 , const char * V_60 )
{
int V_61 ;
char V_62 [ 160 ] ;
struct V_63 * V_64 = V_7 -> V_64 ;
int V_65 = V_64 ? V_64 -> V_66 : 0 ;
V_7 -> V_20 . V_11 = & V_7 -> V_3 -> V_11 ;
V_7 -> V_20 . V_16 = F_8 ( V_7 ) ;
F_48 ( V_7 -> V_3 , V_64 , V_62 , sizeof( V_62 ) ) ;
if ( F_49 ( & V_7 -> V_20 , V_62 , L_6 , V_60 ) < 0 )
return - 1 ;
while ( 1 ) {
V_61 = F_50 ( & V_7 -> V_20 , V_65 ) ;
switch ( V_61 ) {
case V_67 : {
T_3 V_16 ;
V_64 -> V_68 ( V_64 -> V_69 ) ;
if ( F_1 ( V_7 ) )
F_17 ( V_7 ) ;
V_16 = F_8 ( V_7 ) ;
F_51 ( & V_7 -> V_20 , V_16 ) ;
if ( V_7 -> V_3 -> V_70 . V_71 !=
V_7 -> V_3 -> V_70 . V_72 [ V_73 ] ) {
V_7 -> V_3 -> V_70 . V_71 =
V_7 -> V_3 -> V_70 . V_72 [ V_73 ] ;
F_45 ( & V_7 -> V_20 ) ;
}
F_48 ( V_7 -> V_3 ,
V_64 , V_62 , sizeof( V_62 ) ) ;
F_52 ( & V_7 -> V_20 , V_62 ) ;
continue;
}
case 'D' : {
static int V_74 ;
struct V_12 * V_75 = F_7 ( V_7 -> V_20 . V_76 ,
struct V_12 , V_8 ) ;
F_53 () ;
F_54 ( L_7 ,
V_74 ++ , V_7 -> V_20 . V_16 ,
V_7 -> V_3 -> V_16 ,
V_7 -> V_20 . V_24 ,
V_7 -> V_20 . V_26 ,
V_7 -> V_20 . V_27 ,
V_75 -> V_77 , V_75 -> V_15 ) ;
}
break;
case 'C' :
F_44 ( V_7 , false ) ;
break;
case 'E' :
F_44 ( V_7 , true ) ;
break;
case 'H' :
V_7 -> V_22 = ! V_7 -> V_22 ;
F_9 ( V_7 ) ;
break;
case V_78 :
if ( F_38 ( V_7 ) )
break;
default:
goto V_79;
}
}
V_79:
F_55 ( & V_7 -> V_20 ) ;
return V_61 ;
}
static void F_56 ( struct V_1 * V_7 ,
struct V_32 * V_40 ,
const char * V_80 , int V_81 ,
unsigned short V_29 ,
struct V_82 * V_69 )
{
int V_83 , V_28 ;
char V_41 = F_21 ( V_40 ) ;
bool V_84 = V_7 -> V_85 && V_40 -> V_58 . V_86 && F_57 ( V_40 -> V_58 . V_86 ) -> V_87 ;
V_83 = V_88 ;
V_28 = V_7 -> V_20 . V_28 - ( V_81 + 2 ) ;
if ( F_58 ( & V_7 -> V_20 , V_29 ) ) {
V_7 -> V_59 = & V_40 -> V_58 ;
V_83 = V_89 ;
V_69 -> V_90 = true ;
}
F_59 ( & V_7 -> V_20 , V_83 ) ;
F_14 ( V_7 , V_29 , 0 ) ;
F_60 ( & V_7 -> V_20 , L_8 , V_81 ) ;
F_61 ( & V_7 -> V_20 , L_9 , V_41 ) ;
F_62 ( & V_7 -> V_20 , V_84 ? V_91 : ' ' ) ;
F_60 ( & V_7 -> V_20 , V_80 , V_28 ) ;
}
static void F_63 ( struct V_1 * V_20 V_42 ,
struct V_32 * V_40 ,
const char * V_80 , int V_81 ,
unsigned short V_29 V_42 ,
struct V_82 * V_69 )
{
char V_41 = F_21 ( V_40 ) ;
V_69 -> V_92 += fprintf ( V_69 -> V_93 , L_10 , V_81 , L_8 ,
V_41 , V_80 ) ;
}
static bool F_64 ( struct V_1 * V_7 ,
unsigned short V_29 )
{
return V_7 -> V_20 . V_24 == V_29 ;
}
static bool F_65 ( struct V_1 * V_7 V_42 ,
unsigned short V_29 V_42 )
{
return false ;
}
static int F_66 ( struct V_1 * V_7 ,
struct V_35 * V_36 ,
struct V_32 * V_40 ,
unsigned short V_29 , T_3 V_94 ,
bool V_95 , int V_81 ,
T_4 V_96 ,
struct V_82 * V_69 )
{
char V_97 [ 1024 ] , * V_98 ;
const char * V_80 ;
if ( V_69 -> V_77 != 0 ) {
V_69 -> V_77 -- ;
return 0 ;
}
V_98 = NULL ;
V_80 = F_67 ( V_40 , V_97 , sizeof( V_97 ) ,
V_7 -> V_85 ) ;
if ( V_95 ) {
char V_99 [ 64 ] ;
F_68 ( V_36 , V_99 , sizeof( V_99 ) ,
V_94 ) ;
if ( F_69 ( & V_98 , L_11 , V_99 , V_80 ) < 0 )
V_80 = L_12 ;
else
V_80 = V_98 ;
}
V_96 ( V_7 , V_40 , V_80 , V_81 , V_29 , V_69 ) ;
free ( V_98 ) ;
return 1 ;
}
static int F_70 ( struct V_1 * V_7 ,
struct V_38 * V_53 ,
unsigned short V_29 , T_3 V_94 ,
T_4 V_96 ,
struct V_82 * V_69 ,
T_5 V_100 )
{
struct V_8 * V_36 ;
int V_101 = V_29 , V_81 = V_102 ;
bool V_95 ;
V_36 = F_4 ( V_53 ) ;
V_95 = V_36 && F_6 ( V_36 ) ;
while ( V_36 ) {
struct V_35 * V_39 = F_7 ( V_36 , struct V_35 , V_8 ) ;
struct V_8 * V_49 = F_6 ( V_36 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
int V_47 = true ;
int V_103 = 0 ;
F_24 (chain, &child->parent_val, list) {
bool V_104 = V_47 ;
if ( V_47 )
V_47 = false ;
else if ( V_95 )
V_103 = V_102 ;
V_41 = F_21 ( V_40 ) ;
V_29 += F_66 ( V_7 , V_39 ,
V_40 , V_29 , V_94 ,
V_104 && V_95 ,
V_81 + V_103 ,
V_96 , V_69 ) ;
if ( V_100 ( V_7 , V_29 ) )
goto V_79;
if ( V_41 == '+' )
goto V_49;
}
F_24 (chain, &child->val, list) {
bool V_104 = V_47 ;
if ( V_47 )
V_47 = false ;
else if ( V_95 )
V_103 = V_102 ;
V_41 = F_21 ( V_40 ) ;
V_29 += F_66 ( V_7 , V_39 ,
V_40 , V_29 , V_94 ,
V_104 && V_95 ,
V_81 + V_103 ,
V_96 , V_69 ) ;
if ( V_100 ( V_7 , V_29 ) )
goto V_79;
if ( V_41 == '+' )
break;
}
V_49:
if ( V_100 ( V_7 , V_29 ) )
break;
V_36 = V_49 ;
}
V_79:
return V_29 - V_101 ;
}
static char * F_71 ( struct V_1 * V_7 ,
struct V_32 * V_40 ,
char * V_105 , char * V_106 )
{
char V_97 [ 1024 ] ;
const char * V_80 ;
char * V_107 ;
V_80 = F_67 ( V_40 , V_97 , sizeof( V_97 ) ,
V_7 -> V_85 ) ;
if ( V_106 ) {
if ( F_69 ( & V_107 , L_13 , V_106 ,
V_5 . V_108 ? : L_14 , V_80 ) < 0 )
V_107 = NULL ;
} else {
if ( V_105 ) {
if ( F_69 ( & V_107 , L_11 , V_105 , V_80 ) < 0 )
V_107 = NULL ;
} else {
if ( F_69 ( & V_107 , L_6 , V_80 ) < 0 )
V_107 = NULL ;
}
}
return V_107 ;
}
static int F_72 ( struct V_1 * V_7 ,
struct V_38 * V_53 ,
unsigned short V_29 , T_3 V_94 ,
T_4 V_96 ,
struct V_82 * V_69 ,
T_5 V_100 )
{
struct V_8 * V_36 ;
int V_101 = V_29 , V_81 = V_102 ;
bool V_95 ;
V_36 = F_4 ( V_53 ) ;
V_95 = V_36 && F_6 ( V_36 ) ;
while ( V_36 ) {
struct V_35 * V_39 = F_7 ( V_36 , struct V_35 , V_8 ) ;
struct V_8 * V_49 = F_6 ( V_36 ) ;
struct V_32 * V_40 , * V_109 = NULL ;
int V_47 = true ;
char * V_105 = NULL , * V_110 = NULL ;
char * V_111 = NULL , * V_112 = NULL ;
if ( V_69 -> V_77 != 0 ) {
V_69 -> V_77 -- ;
goto V_49;
}
if ( V_95 ) {
char V_99 [ 64 ] ;
F_68 ( V_39 , V_99 , sizeof( V_99 ) , V_94 ) ;
if ( F_69 ( & V_105 , L_6 , V_99 ) < 0 ) {
V_105 = ( char * ) L_15 ;
goto V_113;
}
V_110 = V_105 ;
}
F_24 (chain, &child->parent_val, list) {
V_111 = F_71 ( V_7 ,
V_40 , V_105 , V_111 ) ;
if ( V_47 ) {
V_47 = false ;
V_109 = V_40 ;
}
if ( V_111 == NULL ) {
V_111 = ( char * ) L_12 ;
goto V_113;
}
V_112 = V_111 ;
}
F_24 (chain, &child->val, list) {
V_111 = F_71 ( V_7 ,
V_40 , V_105 , V_111 ) ;
if ( V_47 ) {
V_47 = false ;
V_109 = V_40 ;
}
if ( V_111 == NULL ) {
V_111 = ( char * ) L_12 ;
goto V_113;
}
V_112 = V_111 ;
}
V_113:
V_96 ( V_7 , V_109 , V_111 , V_81 , V_29 ++ , V_69 ) ;
free ( V_110 ) ;
free ( V_112 ) ;
V_49:
if ( V_100 ( V_7 , V_29 ) )
break;
V_36 = V_49 ;
}
return V_29 - V_101 ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_38 * V_53 , int V_114 ,
unsigned short V_29 , T_3 V_94 ,
T_4 V_96 ,
struct V_82 * V_69 ,
T_5 V_100 )
{
struct V_8 * V_36 ;
int V_101 = V_29 , V_81 = V_114 * V_102 ;
T_3 V_115 ;
bool V_95 ;
V_36 = F_4 ( V_53 ) ;
V_95 = V_36 && F_6 ( V_36 ) ;
while ( V_36 ) {
struct V_35 * V_39 = F_7 ( V_36 , struct V_35 , V_8 ) ;
struct V_8 * V_49 = F_6 ( V_36 ) ;
struct V_32 * V_40 ;
char V_41 = ' ' ;
int V_47 = true ;
int V_103 = 0 ;
F_24 (chain, &child->val, list) {
bool V_104 = V_47 ;
if ( V_47 )
V_47 = false ;
else if ( V_95 )
V_103 = V_102 ;
V_41 = F_21 ( V_40 ) ;
V_29 += F_66 ( V_7 , V_39 ,
V_40 , V_29 , V_94 ,
V_104 && V_95 ,
V_81 + V_103 ,
V_96 , V_69 ) ;
if ( V_100 ( V_7 , V_29 ) )
goto V_79;
if ( V_41 == '+' )
break;
}
if ( V_41 == '-' ) {
const int V_116 = V_114 + ( V_103 ? 2 : 1 ) ;
if ( V_43 . V_44 == V_117 )
V_115 = V_39 -> V_118 ;
else
V_115 = V_94 ;
V_29 += F_73 ( V_7 , & V_39 -> V_38 ,
V_116 , V_29 , V_115 ,
V_96 , V_69 , V_100 ) ;
}
if ( V_100 ( V_7 , V_29 ) )
break;
V_36 = V_49 ;
}
V_79:
return V_29 - V_101 ;
}
static int F_74 ( struct V_119 * V_120 , const char * V_121 , ... )
{
struct V_122 * V_69 = V_120 -> V_123 ;
int V_124 , V_125 ;
T_6 args ;
double V_126 ;
va_start ( args , V_121 ) ;
V_125 = va_arg ( args , int ) ;
V_126 = va_arg ( args , double ) ;
va_end ( args ) ;
F_75 ( V_69 -> V_20 , V_126 , V_69 -> V_127 ) ;
V_124 = F_76 ( V_120 -> V_99 , V_120 -> V_128 , V_121 , V_125 , V_126 ) ;
F_61 ( V_69 -> V_20 , L_6 , V_120 -> V_99 ) ;
F_77 ( V_120 , V_124 ) ;
return V_124 ;
}
void F_78 ( void )
{
V_129 [ V_130 ] . V_83 =
V_131 ;
V_129 [ V_132 ] . V_83 =
V_133 ;
V_129 [ V_134 ] . V_83 =
V_135 ;
V_129 [ V_136 ] . V_83 =
V_137 ;
V_129 [ V_138 ] . V_83 =
V_139 ;
V_129 [ V_140 ] . V_83 =
V_141 ;
}
static int F_79 ( struct V_1 * V_7 ,
struct V_12 * V_142 ,
unsigned short V_29 )
{
char V_143 [ 256 ] ;
int V_92 = 0 ;
int V_28 = V_7 -> V_20 . V_28 ;
char V_41 = ' ' ;
bool V_127 = F_58 ( & V_7 -> V_20 , V_29 ) ;
T_7 V_77 = V_142 -> V_77 ;
bool V_47 = true ;
struct V_144 * V_121 ;
if ( V_127 ) {
V_7 -> V_56 = V_142 ;
V_7 -> V_59 = & V_142 -> V_58 ;
}
if ( V_5 . V_145 ) {
F_37 ( V_142 ) ;
V_41 = F_20 ( V_142 ) ;
}
if ( V_77 == 0 ) {
struct V_122 V_69 = {
. V_20 = & V_7 -> V_20 ,
. V_41 = V_41 ,
. V_127 = V_127 ,
} ;
struct V_119 V_120 = {
. V_99 = V_143 ,
. V_128 = sizeof( V_143 ) ,
. V_123 = & V_69 ,
} ;
int V_30 = 0 ;
F_14 ( V_7 , V_29 , 0 ) ;
F_80 (fmt) {
if ( F_81 ( V_121 , V_142 -> V_3 ) ||
V_30 ++ < V_7 -> V_20 . V_146 )
continue;
if ( V_127 && V_7 -> V_20 . V_147 ) {
F_59 ( & V_7 -> V_20 ,
V_89 ) ;
} else {
F_59 ( & V_7 -> V_20 ,
V_88 ) ;
}
if ( V_47 ) {
if ( V_5 . V_145 ) {
F_61 ( & V_7 -> V_20 , L_16 , V_41 ) ;
V_28 -= 2 ;
}
V_47 = false ;
} else {
F_61 ( & V_7 -> V_20 , L_17 ) ;
V_28 -= 2 ;
}
if ( V_121 -> V_83 ) {
V_28 -= V_121 -> V_83 ( V_121 , & V_120 , V_142 ) ;
} else {
V_28 -= V_121 -> V_142 ( V_121 , & V_120 , V_142 ) ;
F_61 ( & V_7 -> V_20 , L_6 , V_143 ) ;
}
}
if ( ! V_7 -> V_20 . V_147 )
V_28 += 1 ;
F_60 ( & V_7 -> V_20 , L_18 , V_28 ) ;
++ V_29 ;
++ V_92 ;
} else
-- V_77 ;
if ( V_41 == '-' && V_29 != V_7 -> V_20 . V_24 ) {
T_3 V_94 = F_82 ( V_142 -> V_3 ) ;
struct V_82 V_69 = {
. V_77 = V_77 ,
. V_90 = V_127 ,
} ;
if ( V_43 . V_44 == V_117 ) {
if ( V_5 . V_148 )
V_94 = V_142 -> V_149 -> V_150 ;
else
V_94 = V_142 -> V_151 . V_150 ;
}
if ( V_43 . V_44 == V_45 ) {
V_92 += F_70 ( V_7 ,
& V_142 -> V_55 , V_29 , V_94 ,
F_56 , & V_69 ,
F_64 ) ;
} else if ( V_43 . V_44 == V_46 ) {
V_92 += F_72 ( V_7 ,
& V_142 -> V_55 , V_29 , V_94 ,
F_56 , & V_69 ,
F_64 ) ;
} else {
V_92 += F_73 ( V_7 ,
& V_142 -> V_55 , 1 , V_29 , V_94 ,
F_56 , & V_69 ,
F_64 ) ;
}
if ( V_69 . V_90 )
V_7 -> V_56 = V_142 ;
}
return V_92 ;
}
static int F_83 ( struct V_119 * V_120 , int V_152 )
{
F_77 ( V_120 , V_152 ) ;
return V_120 -> V_128 <= 0 ;
}
static int F_84 ( struct V_1 * V_7 , char * V_99 , T_8 V_128 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_119 V_153 = {
. V_99 = V_99 ,
. V_128 = V_128 ,
} ;
struct V_144 * V_121 ;
T_8 V_124 = 0 ;
int V_30 = 0 ;
if ( V_5 . V_145 ) {
V_124 = F_76 ( V_99 , V_128 , L_17 ) ;
if ( F_83 ( & V_153 , V_124 ) )
return V_124 ;
}
F_80 (fmt) {
if ( F_81 ( V_121 , V_3 ) || V_30 ++ < V_7 -> V_20 . V_146 )
continue;
V_124 = V_121 -> V_154 ( V_121 , & V_153 , F_85 ( V_3 ) ) ;
if ( F_83 ( & V_153 , V_124 ) )
break;
V_124 = F_76 ( V_153 . V_99 , V_153 . V_128 , L_17 ) ;
if ( F_83 ( & V_153 , V_124 ) )
break;
}
return V_124 ;
}
static void F_86 ( struct V_1 * V_7 )
{
char V_155 [ 1024 ] ;
F_84 ( V_7 , V_155 , sizeof( V_155 ) ) ;
F_15 ( & V_7 -> V_20 , 0 , 0 ) ;
F_59 ( & V_7 -> V_20 , V_156 ) ;
F_60 ( & V_7 -> V_20 , V_155 , V_7 -> V_20 . V_28 + 1 ) ;
}
static void F_87 ( struct V_19 * V_7 )
{
if ( V_7 -> V_76 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
V_7 -> V_76 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
}
}
static unsigned int F_88 ( struct V_19 * V_7 )
{
unsigned V_29 = 0 ;
T_2 V_21 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
if ( V_2 -> V_22 ) {
F_86 ( V_2 ) ;
V_21 = 1 ;
}
F_87 ( V_7 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_59 = NULL ;
for ( V_9 = V_7 -> V_76 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_126 ;
if ( V_75 -> V_157 )
continue;
V_126 = F_89 ( V_75 ) ;
if ( V_126 < V_2 -> V_4 )
continue;
V_29 += F_79 ( V_2 , V_75 , V_29 ) ;
if ( V_29 == V_7 -> V_24 )
break;
}
return V_29 + V_21 ;
}
static struct V_8 * F_5 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_126 = F_89 ( V_75 ) ;
if ( ! V_75 -> V_157 && V_126 >= V_4 )
return V_9 ;
V_9 = F_6 ( V_9 ) ;
}
return NULL ;
}
static struct V_8 * F_90 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_126 = F_89 ( V_75 ) ;
if ( ! V_75 -> V_157 && V_126 >= V_4 )
return V_9 ;
V_9 = F_91 ( V_9 ) ;
}
return NULL ;
}
static void F_92 ( struct V_19 * V_7 ,
T_7 V_81 , int V_158 )
{
struct V_12 * V_75 ;
struct V_8 * V_9 ;
bool V_47 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_20 ) ;
if ( V_7 -> V_16 == 0 )
return;
F_87 ( V_7 ) ;
switch ( V_158 ) {
case V_159 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_160 :
V_9 = V_7 -> V_76 ;
goto V_161;
case V_162 :
V_9 = F_90 ( F_93 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
V_47 = false ;
break;
default:
return;
}
V_75 = F_7 ( V_7 -> V_76 , struct V_12 , V_8 ) ;
V_75 -> V_77 = 0 ;
V_161:
if ( ! V_9 )
return;
if ( V_81 > 0 ) {
do {
V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_75 -> V_14 ) {
T_2 V_163 = V_75 -> V_15 - V_75 -> V_77 ;
if ( V_81 > V_163 ) {
V_81 -= V_163 ;
V_75 -> V_77 = 0 ;
} else {
V_75 -> V_77 += V_81 ;
V_81 = 0 ;
V_7 -> V_76 = V_9 ;
break;
}
}
V_9 = F_5 ( F_6 ( V_9 ) , V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
-- V_81 ;
V_7 -> V_76 = V_9 ;
} while ( V_81 != 0 );
} else if ( V_81 < 0 ) {
while ( 1 ) {
V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_75 -> V_14 ) {
if ( V_47 ) {
if ( - V_81 > V_75 -> V_77 ) {
V_81 += V_75 -> V_77 ;
V_75 -> V_77 = 0 ;
} else {
V_75 -> V_77 += V_81 ;
V_81 = 0 ;
V_7 -> V_76 = V_9 ;
break;
}
} else {
if ( - V_81 > V_75 -> V_15 ) {
V_81 += V_75 -> V_15 ;
V_75 -> V_77 = 0 ;
} else {
V_75 -> V_77 = V_75 -> V_15 + V_81 ;
V_81 = 0 ;
V_7 -> V_76 = V_9 ;
break;
}
}
}
V_9 = F_90 ( F_91 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
++ V_81 ;
V_7 -> V_76 = V_9 ;
if ( V_81 == 0 ) {
V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_75 -> V_14 )
V_75 -> V_77 = V_75 -> V_15 ;
break;
}
V_47 = false ;
}
} else {
V_7 -> V_76 = V_9 ;
V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_75 -> V_77 = 0 ;
}
}
static int F_94 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_93 )
{
T_3 V_94 = F_82 ( V_13 -> V_3 ) ;
struct V_82 V_69 = {
. V_93 = V_93 ,
} ;
if ( V_5 . V_148 )
V_94 = V_13 -> V_149 -> V_150 ;
F_73 ( V_7 , & V_13 -> V_55 , 1 , 0 , V_94 ,
F_63 , & V_69 ,
F_65 ) ;
return V_69 . V_92 ;
}
static int F_95 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_93 )
{
char V_143 [ 8192 ] ;
int V_92 = 0 ;
char V_41 = ' ' ;
struct V_119 V_120 = {
. V_99 = V_143 ,
. V_128 = sizeof( V_143 ) ,
} ;
struct V_144 * V_121 ;
bool V_47 = true ;
int V_124 ;
if ( V_5 . V_145 )
V_41 = F_20 ( V_13 ) ;
if ( V_5 . V_145 )
V_92 += fprintf ( V_93 , L_16 , V_41 ) ;
F_80 (fmt) {
if ( F_81 ( V_121 , V_13 -> V_3 ) )
continue;
if ( ! V_47 ) {
V_124 = F_76 ( V_120 . V_99 , V_120 . V_128 , L_17 ) ;
F_77 ( & V_120 , V_124 ) ;
} else
V_47 = false ;
V_124 = V_121 -> V_142 ( V_121 , & V_120 , V_13 ) ;
F_77 ( & V_120 , V_124 ) ;
}
V_92 += fprintf ( V_93 , L_19 , F_96 ( V_143 ) ) ;
if ( V_41 == '-' )
V_92 += F_94 ( V_7 , V_13 , V_93 ) ;
return V_92 ;
}
static int F_97 ( struct V_1 * V_7 , T_9 * V_93 )
{
struct V_8 * V_9 = F_5 ( F_4 ( V_7 -> V_20 . V_11 ) ,
V_7 -> V_4 ) ;
int V_92 = 0 ;
while ( V_9 ) {
struct V_12 * V_75 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_92 += F_95 ( V_7 , V_75 , V_93 ) ;
V_9 = F_5 ( F_6 ( V_9 ) , V_7 -> V_4 ) ;
}
return V_92 ;
}
static int F_98 ( struct V_1 * V_7 )
{
char V_164 [ 64 ] ;
T_9 * V_93 ;
while ( 1 ) {
F_76 ( V_164 , sizeof( V_164 ) , L_20 , V_7 -> V_165 ) ;
if ( F_99 ( V_164 , V_166 ) )
break;
if ( ++ V_7 -> V_165 == 8192 ) {
F_54 ( L_21 ) ;
return - 1 ;
}
}
V_93 = fopen ( V_164 , L_22 ) ;
if ( V_93 == NULL ) {
char V_97 [ 64 ] ;
const char * V_167 = F_100 ( V_168 , V_97 , sizeof( V_97 ) ) ;
F_54 ( L_23 , V_164 , V_167 ) ;
return - 1 ;
}
++ V_7 -> V_165 ;
F_97 ( V_7 , V_93 ) ;
fclose ( V_93 ) ;
F_54 ( L_24 , V_164 ) ;
return 0 ;
}
static struct V_1 * F_101 ( struct V_3 * V_3 ,
struct V_63 * V_64 ,
struct V_169 * V_170 )
{
struct V_1 * V_7 = F_102 ( sizeof( * V_7 ) ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_20 . V_66 = F_88 ;
V_7 -> V_20 . V_171 = F_10 ;
V_7 -> V_20 . V_172 = F_92 ;
V_7 -> V_20 . V_173 = true ;
V_7 -> V_22 = V_5 . V_174 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_170 = V_170 ;
}
return V_7 ;
}
static void F_103 ( struct V_1 * V_7 )
{
free ( V_7 ) ;
}
static struct V_12 * F_104 ( struct V_1 * V_7 )
{
return V_7 -> V_56 ;
}
static struct V_175 * F_105 ( struct V_1 * V_7 )
{
return V_7 -> V_56 -> V_175 ;
}
static inline bool F_106 ( void * V_68 )
{
return V_68 == NULL ;
}
static int F_48 ( struct V_3 * V_3 ,
struct V_63 * V_64 ,
char * V_97 , T_8 V_128 )
{
char V_176 ;
int V_92 ;
const struct V_177 * V_177 = V_3 -> V_178 ;
const struct V_175 * V_175 = V_3 -> V_179 ;
int V_180 = V_3 -> V_181 ;
unsigned long V_182 = V_3 -> V_70 . V_72 [ V_183 ] ;
T_3 V_72 = V_3 -> V_70 . V_184 ;
struct V_185 * V_186 = F_85 ( V_3 ) ;
const char * V_187 = F_107 ( V_186 ) ;
char V_99 [ 512 ] ;
T_8 V_188 = sizeof( V_99 ) ;
char V_189 [ 30 ] = L_25 ;
bool V_190 = false ;
if ( V_5 . V_191 ) {
V_182 = V_3 -> V_70 . V_192 ;
V_72 = V_3 -> V_70 . V_193 ;
}
if ( F_108 ( V_186 ) ) {
struct V_185 * V_194 ;
F_109 ( V_186 , V_99 , V_188 ) ;
V_187 = V_99 ;
F_110 (pos, evsel) {
struct V_3 * V_195 = F_111 ( V_194 ) ;
if ( V_5 . V_191 ) {
V_182 += V_195 -> V_70 . V_192 ;
V_72 += V_195 -> V_70 . V_193 ;
} else {
V_182 += V_195 -> V_70 . V_72 [ V_183 ] ;
V_72 += V_195 -> V_70 . V_184 ;
}
}
}
if ( V_5 . V_196 &&
strstr ( V_187 , L_26 ) )
V_190 = true ;
V_182 = F_112 ( V_182 , & V_176 ) ;
V_92 = F_76 ( V_97 , V_128 ,
L_27 V_197 ,
V_182 , V_176 , V_187 , V_190 ? V_189 : L_8 , V_72 ) ;
if ( V_3 -> V_198 )
V_92 += snprintf ( V_97 + V_92 , V_128 - V_92 ,
L_28 , V_3 -> V_198 ) ;
if ( V_175 )
V_92 += F_76 ( V_97 + V_92 , V_128 - V_92 ,
L_29 ,
( V_175 -> V_199 ? F_113 ( V_175 ) : L_18 ) ,
V_175 -> V_200 ) ;
if ( V_177 )
V_92 += F_76 ( V_97 + V_92 , V_128 - V_92 ,
L_30 , V_177 -> V_201 ) ;
if ( V_180 > - 1 )
V_92 += F_76 ( V_97 + V_92 , V_128 - V_92 ,
L_31 , V_180 ) ;
if ( ! F_106 ( V_64 ) ) {
struct V_202 * V_76 = V_64 -> V_69 ;
if ( V_76 -> V_203 )
V_92 += F_76 ( V_97 + V_92 , V_128 - V_92 , L_32 ) ;
}
return V_92 ;
}
static inline void F_114 ( char * * V_204 , int V_37 )
{
int V_205 ;
for ( V_205 = 0 ; V_205 < V_37 ; ++ V_205 )
F_115 ( & V_204 [ V_205 ] ) ;
}
static int F_116 ( void )
{
char * V_206 , * V_204 [ 32 ] , * V_207 [ 32 ] , * V_208 ;
T_10 * V_209 ;
int V_210 = 0 , V_211 = - 1 , V_124 = - 1 ;
struct V_212 * V_213 ;
V_206 = getenv ( L_33 ) ;
if ( ! V_206 )
return V_124 ;
V_209 = F_117 ( V_206 ) ;
if ( ! V_209 )
return V_124 ;
memset ( V_204 , 0 , sizeof( V_204 ) ) ;
memset ( V_204 , 0 , sizeof( V_207 ) ) ;
while ( ( V_213 = F_118 ( V_209 ) ) ) {
char V_214 [ V_215 ] ;
T_3 V_216 ;
char * V_217 = V_213 -> V_218 ;
T_9 * V_219 ;
if ( ! ( V_213 -> V_220 == V_221 ) )
continue;
snprintf ( V_214 , sizeof( V_214 ) , L_34 , V_206 , V_217 ) ;
V_219 = fopen ( V_214 , L_35 ) ;
if ( ! V_219 )
continue;
if ( fread ( & V_216 , 1 , 8 , V_219 ) < 8 )
goto V_222;
if ( F_119 ( V_216 ) ) {
V_204 [ V_210 ] = F_120 ( V_217 ) ;
if ( ! V_204 [ V_210 ] )
goto V_222;
V_207 [ V_210 ] = F_120 ( V_214 ) ;
if ( ! V_207 [ V_210 ] ) {
F_115 ( & V_204 [ V_210 ] ) ;
F_121 ( L_36 ) ;
fclose ( V_219 ) ;
break;
}
V_210 ++ ;
}
V_222:
fclose ( V_219 ) ;
if ( V_210 >= 32 ) {
F_121 ( L_37
L_38 ) ;
break;
}
}
F_122 ( V_209 ) ;
if ( V_210 ) {
V_211 = F_123 ( V_210 , V_204 ) ;
if ( V_211 < V_210 && V_211 >= 0 ) {
V_208 = F_120 ( V_207 [ V_211 ] ) ;
if ( V_208 ) {
if ( V_223 )
free ( ( void * ) V_224 ) ;
V_224 = V_208 ;
V_223 = true ;
V_124 = 0 ;
} else
F_121 ( L_39 ) ;
}
}
F_114 ( V_204 , V_210 ) ;
F_114 ( V_207 , V_210 ) ;
return V_124 ;
}
static int
F_124 ( struct V_1 * V_7 , struct V_225 * V_226 )
{
struct V_185 * V_186 ;
struct V_227 * V_228 ;
struct V_12 * V_13 ;
int V_167 ;
if ( ! V_229 && F_125 ( V_7 -> V_170 ) )
return 0 ;
V_228 = F_57 ( V_226 -> V_58 . V_86 ) ;
if ( ! V_228 -> V_87 )
return 0 ;
V_186 = F_85 ( V_7 -> V_3 ) ;
V_167 = F_126 ( & V_226 -> V_58 , V_186 , V_7 -> V_64 ) ;
V_13 = F_104 ( V_7 ) ;
if ( ( V_167 == 'q' || V_167 == F_127 ( 'c' ) ) && V_13 -> V_230 )
return 1 ;
F_51 ( & V_7 -> V_20 , V_7 -> V_3 -> V_16 ) ;
if ( V_167 )
F_128 ( & V_7 -> V_20 ) ;
return 0 ;
}
static int
F_129 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 , char * * V_231 ,
struct V_232 * V_232 , struct V_233 * V_86 )
{
if ( V_86 == NULL || V_232 -> V_177 -> V_234 )
return 0 ;
if ( F_69 ( V_231 , L_40 , V_86 -> V_217 ) < 0 )
return 0 ;
V_226 -> V_58 . V_232 = V_232 ;
V_226 -> V_58 . V_86 = V_86 ;
V_226 -> V_235 = F_124 ;
return 1 ;
}
static int
F_130 ( struct V_1 * V_7 , struct V_225 * V_226 )
{
struct V_175 * V_175 = V_226 -> V_175 ;
if ( V_7 -> V_3 -> V_179 ) {
F_131 ( V_7 -> V_236 , & V_7 -> V_3 -> V_179 ) ;
F_132 ( V_237 , false ) ;
F_133 ( V_7 -> V_3 -> V_179 ) ;
F_53 () ;
} else {
F_54 ( L_41 ,
V_175 -> V_199 ? F_113 ( V_175 ) : L_18 ,
V_175 -> V_200 ) ;
V_7 -> V_3 -> V_179 = F_134 ( V_175 ) ;
F_132 ( V_237 , false ) ;
F_135 ( V_7 -> V_236 , & V_7 -> V_3 -> V_179 ) ;
}
F_136 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_137 ( struct V_1 * V_7 , struct V_225 * V_226 ,
char * * V_231 , struct V_175 * V_175 )
{
if ( V_175 == NULL )
return 0 ;
if ( F_69 ( V_231 , L_42 ,
V_7 -> V_3 -> V_179 ? L_43 : L_44 ,
V_175 -> V_199 ? F_113 ( V_175 ) : L_18 ,
V_175 -> V_200 ) < 0 )
return 0 ;
V_226 -> V_175 = V_175 ;
V_226 -> V_235 = F_130 ;
return 1 ;
}
static int
F_138 ( struct V_1 * V_7 , struct V_225 * V_226 )
{
struct V_232 * V_232 = V_226 -> V_58 . V_232 ;
if ( V_7 -> V_3 -> V_178 ) {
F_131 ( V_7 -> V_236 , & V_7 -> V_3 -> V_178 ) ;
F_132 ( V_238 , false ) ;
V_7 -> V_3 -> V_178 = NULL ;
F_53 () ;
} else {
if ( V_232 == NULL )
return 0 ;
F_54 ( L_45 ,
F_139 ( V_232 ) ? L_46 : V_232 -> V_177 -> V_201 ) ;
V_7 -> V_3 -> V_178 = V_232 -> V_177 ;
F_132 ( V_238 , true ) ;
F_135 ( V_7 -> V_236 , & V_7 -> V_3 -> V_178 ) ;
}
F_140 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_141 ( struct V_1 * V_7 , struct V_225 * V_226 ,
char * * V_231 , struct V_232 * V_232 )
{
if ( V_232 == NULL )
return 0 ;
if ( F_69 ( V_231 , L_47 ,
V_7 -> V_3 -> V_178 ? L_43 : L_44 ,
F_139 ( V_232 ) ? L_46 : V_232 -> V_177 -> V_201 ) < 0 )
return 0 ;
V_226 -> V_58 . V_232 = V_232 ;
V_226 -> V_235 = F_138 ;
return 1 ;
}
static int
F_142 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 )
{
F_143 ( V_226 -> V_58 . V_232 ) ;
return 0 ;
}
static int
F_144 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 , char * * V_231 , struct V_232 * V_232 )
{
if ( V_232 == NULL )
return 0 ;
if ( F_69 ( V_231 , L_48 ) < 0 )
return 0 ;
V_226 -> V_58 . V_232 = V_232 ;
V_226 -> V_235 = F_142 ;
return 1 ;
}
static int
F_145 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 )
{
char V_239 [ 64 ] ;
memset ( V_239 , 0 , sizeof( V_239 ) ) ;
if ( V_226 -> V_175 ) {
F_76 ( V_239 , sizeof( V_239 ) , L_49 ,
F_113 ( V_226 -> V_175 ) ) ;
} else if ( V_226 -> V_58 . V_86 ) {
F_76 ( V_239 , sizeof( V_239 ) , L_50 ,
V_226 -> V_58 . V_86 -> V_217 ) ;
}
F_146 ( V_239 ) ;
return 0 ;
}
static int
F_147 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 , char * * V_231 ,
struct V_175 * V_175 , struct V_233 * V_86 )
{
if ( V_175 ) {
if ( F_69 ( V_231 , L_51 ,
F_113 ( V_175 ) ) < 0 )
return 0 ;
} else if ( V_86 ) {
if ( F_69 ( V_231 , L_52 ,
V_86 -> V_217 ) < 0 )
return 0 ;
} else {
if ( F_69 ( V_231 , L_53 ) < 0 )
return 0 ;
}
V_226 -> V_175 = V_175 ;
V_226 -> V_58 . V_86 = V_86 ;
V_226 -> V_235 = F_145 ;
return 1 ;
}
static int
F_148 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 V_42 )
{
if ( F_116 () ) {
F_121 ( L_54
L_55 ) ;
return 0 ;
}
return V_240 ;
}
static int
F_149 ( struct V_1 * V_7 ,
struct V_225 * V_226 , char * * V_231 )
{
if ( ! F_106 ( V_7 -> V_64 ) )
return 0 ;
if ( F_69 ( V_231 , L_56 ) < 0 )
return 0 ;
V_226 -> V_235 = F_148 ;
return 1 ;
}
static int
F_150 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 V_42 )
{
return 0 ;
}
static int
F_151 ( struct V_1 * V_7 V_42 ,
struct V_225 * V_226 , char * * V_231 )
{
if ( F_69 ( V_231 , L_57 ) < 0 )
return 0 ;
V_226 -> V_235 = F_150 ;
return 1 ;
}
static int
F_152 ( struct V_1 * V_7 , struct V_225 * V_226 )
{
if ( V_7 -> V_3 -> V_181 > - 1 ) {
F_131 ( V_7 -> V_236 , & V_7 -> V_3 -> V_181 ) ;
V_7 -> V_3 -> V_181 = - 1 ;
F_132 ( V_241 , false ) ;
} else {
V_7 -> V_3 -> V_181 = V_226 -> V_242 ;
F_132 ( V_241 , true ) ;
F_135 ( V_7 -> V_236 , & V_7 -> V_3 -> V_181 ) ;
}
F_153 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_154 ( struct V_1 * V_7 , struct V_225 * V_226 ,
char * * V_231 , int V_180 )
{
if ( V_180 < 0 )
return 0 ;
if ( F_69 ( V_231 , L_58 ,
( V_7 -> V_3 -> V_181 > - 1 ) ? L_43 : L_44 ,
V_180 ) < 0 )
return 0 ;
V_226 -> V_242 = V_180 ;
V_226 -> V_235 = F_152 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 V_16 = 0 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_17 = V_2 -> V_3 -> V_17 ;
return;
}
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_16 ++ ;
V_9 = F_6 ( V_9 ) ;
}
V_2 -> V_17 = V_16 ;
}
static int F_155 ( struct V_185 * V_186 , int V_72 ,
const char * V_243 ,
bool V_244 ,
struct V_63 * V_64 ,
float V_4 ,
struct V_169 * V_170 )
{
struct V_3 * V_3 = F_111 ( V_186 ) ;
struct V_1 * V_7 = F_101 ( V_3 , V_64 , V_170 ) ;
struct V_230 * V_245 ;
#define F_156 16
char * V_204 [ F_156 ] ;
struct V_225 V_246 [ F_156 ] ;
int V_210 = 0 ;
int V_61 = - 1 ;
char V_99 [ 64 ] ;
int V_65 = V_64 ? V_64 -> V_66 : 0 ;
struct V_144 * V_121 ;
#define F_157 \
"h/?/F1 Show this window\n" \
"UP/DOWN/PGUP\n" \
"PGDN/SPACE Navigate\n" \
"q/ESC/CTRL+C Exit browser\n\n" \
"For multiple event sessions:\n\n" \
"TAB/UNTAB Switch events\n\n" \
"For symbolic views (--sort has sym):\n\n" \
"ENTER Zoom into DSO/Threads & Annotate current symbol\n" \
"ESC Zoom out\n" \
"a Annotate current symbol\n" \
"C Collapse all callchains\n" \
"d Zoom into current DSO\n" \
"E Expand all callchains\n" \
"F Toggle percentage of filtered entries\n" \
"H Display column headers\n" \
"m Display context menu\n" \
"S Zoom into current Processor Socket\n" \
const char V_247 [] = F_157
L_59
L_60
L_61
L_62
L_63
L_64
L_65 ;
const char V_248 [] = F_157
L_60
L_63
L_64
L_66
L_67
L_65 ;
if ( V_7 == NULL )
return - 1 ;
F_158 () ;
F_159 ( 0 , 0 , 0 ) ;
if ( V_4 )
V_7 -> V_4 = V_4 ;
F_17 ( V_7 ) ;
V_7 -> V_236 = F_160 ( 3 ) ;
if ( V_7 -> V_236 == NULL )
goto V_79;
F_161 ( V_243 ) ;
memset ( V_204 , 0 , sizeof( V_204 ) ) ;
memset ( V_246 , 0 , sizeof( V_246 ) ) ;
F_80 (fmt) {
F_162 ( V_121 , V_3 ) ;
++ V_7 -> V_20 . V_249 ;
}
if ( V_5 . V_250 )
F_163 ( V_5 . V_250 ) ;
while ( 1 ) {
struct V_175 * V_175 = NULL ;
struct V_232 * V_232 = NULL ;
int V_211 = 0 ;
int V_251 = - 1 ;
V_210 = 0 ;
V_61 = F_47 ( V_7 , V_243 ) ;
if ( V_7 -> V_56 != NULL ) {
V_175 = F_105 ( V_7 ) ;
V_232 = V_7 -> V_59 -> V_232 ;
V_251 = V_7 -> V_56 -> V_242 ;
}
switch ( V_61 ) {
case V_252 :
case V_253 :
if ( V_72 == 1 )
continue;
goto V_254;
case 'a' :
if ( ! V_255 ) {
F_46 ( & V_7 -> V_20 , V_65 * 2 ,
L_68
L_69 ) ;
continue;
}
if ( V_7 -> V_59 == NULL ||
V_7 -> V_59 -> V_86 == NULL ||
V_7 -> V_59 -> V_232 -> V_177 -> V_234 )
continue;
V_246 -> V_58 . V_232 = V_7 -> V_59 -> V_232 ;
V_246 -> V_58 . V_86 = V_7 -> V_59 -> V_86 ;
F_124 ( V_7 , V_246 ) ;
continue;
case 'P' :
F_98 ( V_7 ) ;
continue;
case 'd' :
V_246 -> V_58 . V_232 = V_232 ;
F_138 ( V_7 , V_246 ) ;
continue;
case 'V' :
V_7 -> V_85 = ! V_7 -> V_85 ;
continue;
case 't' :
V_246 -> V_175 = V_175 ;
F_130 ( V_7 , V_246 ) ;
continue;
case 'S' :
V_246 -> V_242 = V_251 ;
F_152 ( V_7 , V_246 ) ;
continue;
case '/' :
if ( F_164 ( L_70 ,
L_71
L_72 ,
V_99 , L_73 ,
V_65 * 2 ) == V_78 ) {
V_3 -> V_256 = * V_99 ? V_99 : NULL ;
F_165 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_106 ( V_64 ) ) {
V_246 -> V_175 = NULL ;
V_246 -> V_58 . V_86 = NULL ;
F_145 ( V_7 , V_246 ) ;
}
continue;
case 's' :
if ( F_106 ( V_64 ) ) {
V_61 = F_148 ( V_7 , V_246 ) ;
if ( V_61 == V_240 )
goto V_254;
}
continue;
case 'i' :
if ( V_170 -> V_257 )
F_166 ( V_170 ) ;
continue;
case 'F' :
V_5 . V_191 ^= 1 ;
continue;
case 'z' :
if ( ! F_106 ( V_64 ) ) {
struct V_202 * V_76 = V_64 -> V_69 ;
V_76 -> V_203 = ! V_76 -> V_203 ;
}
continue;
case V_258 :
case 'h' :
case '?' :
F_167 ( & V_7 -> V_20 ,
F_106 ( V_64 ) ? V_247 : V_248 ) ;
continue;
case V_78 :
case V_259 :
case 'm' :
break;
case V_260 :
case V_261 : {
const void * V_76 ;
if ( F_168 ( V_7 -> V_236 ) ) {
if ( V_244 )
goto V_254;
if ( V_61 == V_260 &&
F_169 ( & V_7 -> V_20 ,
L_74 ) )
goto V_254;
continue;
}
V_76 = F_170 ( V_7 -> V_236 ) ;
if ( V_76 == & V_7 -> V_3 -> V_178 ) {
F_138 ( V_7 , V_246 ) ;
} else if ( V_76 == & V_7 -> V_3 -> V_179 ) {
F_130 ( V_7 , V_246 ) ;
} else if ( V_76 == & V_7 -> V_3 -> V_181 ) {
F_152 ( V_7 , V_246 ) ;
}
continue;
}
case 'q' :
case F_127 ( 'c' ) :
goto V_254;
case 'f' :
if ( ! F_106 ( V_64 ) ) {
struct V_202 * V_76 = V_64 -> V_69 ;
F_171 ( V_76 -> V_262 ) ;
if ( V_76 -> V_262 -> V_263 ) {
V_243 = L_75 ;
V_64 -> V_66 = V_65 ;
} else {
V_243 = L_76 ;
V_64 -> V_66 = 0 ;
}
continue;
}
default:
V_243 = L_77 ;
continue;
}
if ( ! V_255 )
goto V_264;
if ( V_7 -> V_59 == NULL )
goto V_265;
if ( V_266 == V_267 ) {
V_245 = V_7 -> V_56 -> V_230 ;
if ( V_245 == NULL )
goto V_265;
V_210 += F_129 ( V_7 ,
& V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_245 -> V_268 . V_232 ,
V_245 -> V_268 . V_86 ) ;
if ( V_245 -> V_269 . V_86 != V_245 -> V_268 . V_86 )
V_210 += F_129 ( V_7 ,
& V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_245 -> V_269 . V_232 ,
V_245 -> V_269 . V_86 ) ;
} else {
V_210 += F_129 ( V_7 ,
& V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_7 -> V_59 -> V_232 ,
V_7 -> V_59 -> V_86 ) ;
}
V_265:
V_210 += F_137 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] , V_175 ) ;
V_210 += F_141 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] , V_232 ) ;
V_210 += F_144 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_7 -> V_59 ?
V_7 -> V_59 -> V_232 : NULL ) ;
V_210 += F_154 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_251 ) ;
if ( V_7 -> V_56 ) {
V_210 += F_147 ( V_7 ,
& V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
V_175 , NULL ) ;
V_210 += F_147 ( V_7 ,
& V_246 [ V_210 ] ,
& V_204 [ V_210 ] ,
NULL , V_7 -> V_59 -> V_86 ) ;
}
V_210 += F_147 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] , NULL , NULL ) ;
V_210 += F_149 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] ) ;
V_264:
V_210 += F_151 ( V_7 , & V_246 [ V_210 ] ,
& V_204 [ V_210 ] ) ;
do {
struct V_225 * V_226 ;
V_211 = F_123 ( V_210 , V_204 ) ;
if ( V_211 == - 1 || V_211 >= V_210 )
break;
V_226 = & V_246 [ V_211 ] ;
V_61 = V_226 -> V_235 ( V_7 , V_226 ) ;
} while ( V_61 == 1 );
if ( V_61 == V_240 )
break;
}
V_254:
F_172 ( V_7 -> V_236 ) ;
V_79:
F_103 ( V_7 ) ;
F_114 ( V_204 , F_156 ) ;
return V_61 ;
}
static void F_173 ( struct V_19 * V_7 ,
void * V_142 , int V_29 )
{
struct V_270 * V_271 = F_11 ( V_7 ,
struct V_270 , V_20 ) ;
struct V_185 * V_186 = F_34 ( V_142 , struct V_185 , V_36 ) ;
struct V_3 * V_3 = F_111 ( V_186 ) ;
bool V_127 = F_58 ( V_7 , V_29 ) ;
unsigned long V_72 = V_3 -> V_70 . V_72 [ V_183 ] ;
const char * V_187 = F_107 ( V_186 ) ;
char V_97 [ 256 ] , V_176 ;
const char * V_272 = L_8 ;
T_8 V_92 ;
F_59 ( V_7 , V_127 ? V_89 :
V_88 ) ;
if ( F_108 ( V_186 ) ) {
struct V_185 * V_194 ;
V_187 = F_174 ( V_186 ) ;
F_110 (pos, evsel) {
struct V_3 * V_195 = F_111 ( V_194 ) ;
V_72 += V_195 -> V_70 . V_72 [ V_183 ] ;
}
}
V_72 = F_112 ( V_72 , & V_176 ) ;
V_92 = F_76 ( V_97 , sizeof( V_97 ) , L_78 , V_72 ,
V_176 , V_176 == ' ' ? L_18 : L_8 , V_187 ) ;
F_61 ( V_7 , L_6 , V_97 ) ;
V_72 = V_3 -> V_70 . V_72 [ V_73 ] ;
if ( V_72 != 0 ) {
V_271 -> V_273 = true ;
if ( ! V_127 )
F_59 ( V_7 , V_274 ) ;
V_72 = F_112 ( V_72 , & V_176 ) ;
V_92 += F_76 ( V_97 , sizeof( V_97 ) , L_79 ,
V_72 , V_176 , V_176 == ' ' ? L_18 : L_8 ) ;
V_272 = V_97 ;
}
F_60 ( V_7 , V_272 , V_7 -> V_28 - V_92 ) ;
if ( V_127 )
V_271 -> V_59 = V_186 ;
}
static int F_175 ( struct V_270 * V_271 ,
int V_72 , const char * V_60 ,
struct V_63 * V_64 )
{
struct V_275 * V_262 = V_271 -> V_20 . V_276 ;
struct V_185 * V_194 ;
const char * V_62 = L_80 ;
int V_65 = V_64 ? V_64 -> V_66 : 0 ;
int V_61 ;
if ( F_49 ( & V_271 -> V_20 , V_62 ,
L_81 ) < 0 )
return - 1 ;
while ( 1 ) {
V_61 = F_50 ( & V_271 -> V_20 , V_65 ) ;
switch ( V_61 ) {
case V_67 :
V_64 -> V_68 ( V_64 -> V_69 ) ;
if ( ! V_271 -> V_277 && V_271 -> V_273 ) {
F_45 ( & V_271 -> V_20 ) ;
V_271 -> V_277 = true ;
}
continue;
case V_259 :
case V_78 :
if ( ! V_271 -> V_59 )
continue;
V_194 = V_271 -> V_59 ;
V_278:
F_176 ( V_262 , V_194 ) ;
if ( V_64 )
V_64 -> V_68 ( V_64 -> V_69 ) ;
V_61 = F_155 ( V_194 , V_72 , V_60 ,
true , V_64 ,
V_271 -> V_4 ,
V_271 -> V_170 ) ;
F_52 ( & V_271 -> V_20 , V_62 ) ;
switch ( V_61 ) {
case V_252 :
if ( V_194 -> V_36 . V_49 == & V_262 -> V_11 )
V_194 = F_177 ( V_262 ) ;
else
V_194 = F_178 ( V_194 ) ;
goto V_278;
case V_253 :
if ( V_194 -> V_36 . V_52 == & V_262 -> V_11 )
V_194 = F_179 ( V_262 ) ;
else
V_194 = F_180 ( V_194 ) ;
goto V_278;
case V_240 :
case 'q' :
case F_127 ( 'c' ) :
goto V_79;
case V_260 :
default:
continue;
}
case V_261 :
continue;
case V_260 :
if ( ! F_169 ( & V_271 -> V_20 ,
L_74 ) )
continue;
case 'q' :
case F_127 ( 'c' ) :
goto V_79;
default:
continue;
}
}
V_79:
F_55 ( & V_271 -> V_20 ) ;
return V_61 ;
}
static bool F_181 ( struct V_19 * V_7 V_42 ,
void * V_142 )
{
struct V_185 * V_186 = F_34 ( V_142 , struct V_185 , V_36 ) ;
if ( V_5 . V_279 && ! F_182 ( V_186 ) )
return true ;
return false ;
}
static int F_183 ( struct V_275 * V_262 ,
int V_16 , const char * V_60 ,
struct V_63 * V_64 ,
float V_4 ,
struct V_169 * V_170 )
{
struct V_185 * V_194 ;
struct V_270 V_271 = {
. V_20 = {
. V_11 = & V_262 -> V_11 ,
. V_66 = V_280 ,
. V_172 = V_281 ,
. V_282 = F_173 ,
. V_283 = F_181 ,
. V_16 = V_16 ,
. V_276 = V_262 ,
} ,
. V_4 = V_4 ,
. V_170 = V_170 ,
} ;
F_161 ( L_82 ) ;
F_184 (evlist, pos) {
const char * V_187 = F_107 ( V_194 ) ;
T_8 V_284 = strlen ( V_187 ) + 7 ;
if ( V_271 . V_20 . V_28 < V_284 )
V_271 . V_20 . V_28 = V_284 ;
}
return F_175 ( & V_271 , V_16 , V_60 , V_64 ) ;
}
int F_185 ( struct V_275 * V_262 , const char * V_60 ,
struct V_63 * V_64 ,
float V_4 ,
struct V_169 * V_170 )
{
int V_16 = V_262 -> V_16 ;
V_285:
if ( V_16 == 1 ) {
struct V_185 * V_47 = F_177 ( V_262 ) ;
return F_155 ( V_47 , V_16 , V_60 ,
false , V_64 , V_4 ,
V_170 ) ;
}
if ( V_5 . V_279 ) {
struct V_185 * V_194 ;
V_16 = 0 ;
F_184 (evlist, pos) {
if ( F_182 ( V_194 ) )
V_16 ++ ;
}
if ( V_16 == 1 )
goto V_285;
}
return F_183 ( V_262 , V_16 , V_60 ,
V_64 , V_4 , V_170 ) ;
}
