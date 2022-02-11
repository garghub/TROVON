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
if ( V_13 -> V_14 && V_13 -> V_15 )
V_10 += V_13 -> V_16 ;
}
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_17 ;
if ( V_5 . V_18 )
V_17 = V_2 -> V_19 ;
else if ( F_1 ( V_2 ) )
V_17 = V_2 -> V_20 ;
else
V_17 = V_2 -> V_3 -> V_17 ;
V_2 -> V_21 = F_3 ( V_2 ) ;
return V_17 + V_2 -> V_21 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_22 * V_7 = & V_2 -> V_23 ;
T_2 V_24 = V_2 -> V_25 ? 1 : 0 , V_26 ;
V_7 -> V_27 = V_7 -> V_28 - V_24 ;
V_26 = V_7 -> V_29 - V_7 -> V_30 ;
if ( V_26 >= V_7 -> V_27 )
V_7 -> V_29 -= V_26 - V_7 -> V_27 + 1 ;
}
static void F_10 ( struct V_22 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
V_7 -> V_31 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_7 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_7 , int V_32 , int V_33 )
{
T_2 V_24 = V_7 -> V_25 ? 1 : 0 ;
F_15 ( & V_7 -> V_23 , V_32 + V_24 , V_33 ) ;
}
static void F_16 ( struct V_1 * V_7 )
{
V_7 -> V_21 = 0 ;
F_17 ( V_7 ) ;
V_7 -> V_23 . V_17 = F_8 ( V_7 ) ;
F_10 ( & V_7 -> V_23 ) ;
F_18 ( & V_7 -> V_23 ) ;
}
static char F_19 ( bool V_15 )
{
return V_15 ? '-' : '+' ;
}
static char F_20 ( const struct V_12 * V_13 )
{
return V_13 -> V_34 ? F_19 ( V_13 -> V_15 ) : ' ' ;
}
static char F_21 ( const struct V_35 * V_36 )
{
return V_36 -> V_34 ? F_19 ( V_36 -> V_15 ) : ' ' ;
}
static void F_22 ( struct V_35 * V_36 , bool V_37 )
{
V_36 -> V_15 = V_37 ? V_36 -> V_34 : false ;
}
static int F_23 ( struct V_38 * V_39 )
{
int V_40 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_39 -> V_41 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_42 = F_7 ( V_9 , struct V_38 , V_8 ) ;
struct V_35 * V_43 ;
char V_44 = ' ' ;
F_25 (chain, &child->val, list) {
++ V_40 ;
V_44 = F_21 ( V_43 ) ;
if ( V_44 == '+' )
break;
}
if ( V_44 == '-' )
V_40 += F_23 ( V_42 ) ;
}
return V_40 ;
}
static int F_26 ( struct V_38 * V_39 )
{
struct V_35 * V_43 ;
char V_44 = 0 ;
int V_40 = 0 ;
F_25 (chain, &node->parent_val, list) {
if ( ! V_44 ) {
V_44 = F_21 ( V_43 ) ;
if ( V_44 == '+' )
return 1 ;
}
V_40 ++ ;
}
F_25 (chain, &node->val, list) {
if ( ! V_44 ) {
V_44 = F_21 ( V_43 ) ;
if ( V_44 == '+' )
return 1 ;
}
V_40 ++ ;
}
return V_40 ;
}
static int F_27 ( struct V_38 * V_39 V_45 )
{
return 1 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_35 * V_43 ;
bool V_15 = false ;
int V_40 = 0 ;
if ( V_46 . V_47 == V_48 )
return F_26 ( V_39 ) ;
else if ( V_46 . V_47 == V_49 )
return F_27 ( V_39 ) ;
F_25 (chain, &node->val, list) {
++ V_40 ;
V_15 = V_43 -> V_15 ;
}
if ( V_15 )
V_40 += F_23 ( V_39 ) ;
return V_40 ;
}
static int F_29 ( struct V_41 * V_43 )
{
struct V_8 * V_9 ;
int V_40 = 0 ;
for ( V_9 = F_4 ( V_43 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_39 = F_7 ( V_9 , struct V_38 , V_8 ) ;
V_40 += F_28 ( V_39 ) ;
}
return V_40 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_50 )
{
int V_51 = 0 ;
struct V_8 * V_39 ;
struct V_12 * V_42 ;
if ( V_13 -> V_14 )
return F_29 ( & V_13 -> V_52 ) ;
if ( V_13 -> V_53 )
return 1 ;
V_39 = F_4 ( & V_13 -> V_54 ) ;
while ( V_39 ) {
float V_55 ;
V_42 = F_7 ( V_39 , struct V_12 , V_8 ) ;
V_55 = F_31 ( V_42 ) ;
if ( ! V_42 -> V_56 && V_55 >= V_2 -> V_4 ) {
V_51 ++ ;
if ( V_50 && V_42 -> V_15 )
V_51 += F_30 ( V_2 , V_42 , true ) ;
}
V_39 = F_24 ( V_39 ) ;
}
return V_51 ;
}
static bool F_32 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return false ;
if ( ! V_13 -> V_34 )
return false ;
V_13 -> V_15 = ! V_13 -> V_15 ;
return true ;
}
static bool F_33 ( struct V_35 * V_36 )
{
if ( ! V_36 )
return false ;
if ( ! V_36 -> V_34 )
return false ;
V_36 -> V_15 = ! V_36 -> V_15 ;
return true ;
}
static void F_34 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = F_4 ( & V_39 -> V_41 ) ;
for ( V_9 = F_4 ( & V_39 -> V_41 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_42 = F_7 ( V_9 , struct V_38 , V_8 ) ;
struct V_35 * V_43 ;
bool V_57 = true ;
F_25 (chain, &child->val, list) {
if ( V_57 ) {
V_57 = false ;
V_43 -> V_34 = V_43 -> V_58 . V_59 != & V_42 -> V_60 ||
! F_35 ( & V_42 -> V_41 ) ;
} else
V_43 -> V_34 = V_43 -> V_58 . V_59 == & V_42 -> V_60 &&
! F_35 ( & V_42 -> V_41 ) ;
}
F_34 ( V_42 ) ;
}
}
static void F_36 ( struct V_38 * V_39 ,
bool V_61 )
{
struct V_35 * V_43 ;
V_43 = F_37 ( V_39 -> V_60 . V_59 , struct V_35 , V_58 ) ;
V_43 -> V_34 = V_61 ;
if ( ! F_38 ( & V_39 -> V_60 ) ) {
V_43 = F_37 ( V_39 -> V_60 . V_62 , struct V_35 , V_58 ) ;
V_43 -> V_34 = ! F_35 ( & V_39 -> V_41 ) ;
}
F_34 ( V_39 ) ;
}
static void F_39 ( struct V_41 * V_63 )
{
struct V_8 * V_9 = F_4 ( V_63 ) ;
bool V_61 = V_9 && F_24 ( V_9 ) ;
for ( V_9 = F_4 ( V_63 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_39 = F_7 ( V_9 , struct V_38 , V_8 ) ;
F_36 ( V_39 , V_61 ) ;
if ( V_46 . V_47 == V_48 ||
V_46 . V_47 == V_49 )
F_40 ( V_39 ) ;
}
}
static void F_41 ( struct V_12 * V_13 )
{
if ( V_13 -> V_64 )
return;
if ( V_13 -> V_14 ) {
V_13 -> V_34 = ! F_35 ( & V_13 -> V_52 ) ;
F_39 ( & V_13 -> V_52 ) ;
} else {
V_13 -> V_34 = ! F_35 ( & V_13 -> V_54 ) ;
}
V_13 -> V_64 = true ;
}
static bool F_42 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_65 ;
struct V_66 * V_67 = V_7 -> V_68 ;
struct V_35 * V_36 = F_11 ( V_67 , struct V_35 , V_67 ) ;
bool V_34 ;
if ( ! V_13 || ! V_67 )
return false ;
if ( V_67 == & V_13 -> V_67 )
V_34 = F_32 ( V_13 ) ;
else
V_34 = F_33 ( V_36 ) ;
if ( V_34 ) {
int V_69 = 0 ;
F_41 ( V_13 ) ;
V_7 -> V_23 . V_17 -= V_13 -> V_16 ;
if ( V_13 -> V_14 )
V_7 -> V_21 -= V_13 -> V_16 ;
else
V_7 -> V_19 -= V_13 -> V_16 ;
if ( V_5 . V_18 )
V_69 = F_30 ( V_7 , V_13 , true ) ;
if ( V_13 -> V_15 ) {
if ( V_13 -> V_14 )
V_13 -> V_16 = F_29 ( & V_13 -> V_52 ) ;
else
V_13 -> V_16 = F_30 ( V_7 , V_13 , false ) ;
if ( V_5 . V_18 )
V_7 -> V_23 . V_17 += V_69 - V_13 -> V_16 ;
if ( ! V_13 -> V_14 && V_13 -> V_16 == 0 ) {
V_13 -> V_53 = true ;
V_13 -> V_16 = 1 ;
}
} else {
if ( V_5 . V_18 )
V_7 -> V_23 . V_17 -= V_69 - V_13 -> V_16 ;
if ( V_13 -> V_53 )
V_13 -> V_53 = false ;
V_13 -> V_16 = 0 ;
}
V_7 -> V_23 . V_17 += V_13 -> V_16 ;
if ( V_13 -> V_14 )
V_7 -> V_21 += V_13 -> V_16 ;
else
V_7 -> V_19 += V_13 -> V_16 ;
return true ;
}
return false ;
}
static int F_43 ( struct V_38 * V_39 , bool V_37 )
{
int V_40 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_39 -> V_41 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_42 = F_7 ( V_9 , struct V_38 , V_8 ) ;
struct V_35 * V_43 ;
bool V_34 = false ;
F_25 (chain, &child->val, list) {
++ V_40 ;
F_22 ( V_43 , V_37 ) ;
V_34 = V_43 -> V_34 ;
}
if ( V_34 )
V_40 += F_43 ( V_42 , V_37 ) ;
}
return V_40 ;
}
static int F_44 ( struct V_38 * V_39 , bool V_37 )
{
struct V_35 * V_43 ;
bool V_34 = false ;
int V_40 = 0 ;
F_25 (chain, &node->val, list) {
++ V_40 ;
F_22 ( V_43 , V_37 ) ;
V_34 = V_43 -> V_34 ;
}
if ( V_34 )
V_40 += F_43 ( V_39 , V_37 ) ;
return V_40 ;
}
static int F_45 ( struct V_41 * V_43 , bool V_37 )
{
struct V_8 * V_9 ;
int V_40 = 0 ;
for ( V_9 = F_4 ( V_43 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_38 * V_39 = F_7 ( V_9 , struct V_38 , V_8 ) ;
V_40 += F_44 ( V_39 , V_37 ) ;
}
return V_40 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_37 V_45 )
{
float V_55 ;
struct V_8 * V_9 ;
struct V_12 * V_42 ;
int V_40 = 0 ;
for ( V_9 = F_4 ( & V_13 -> V_54 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
V_42 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_55 = F_31 ( V_42 ) ;
if ( ! V_42 -> V_56 && V_55 >= V_2 -> V_4 )
V_40 ++ ;
}
return V_40 ;
}
static void F_47 ( struct V_12 * V_13 ,
struct V_1 * V_2 , bool V_37 )
{
F_41 ( V_13 ) ;
V_13 -> V_15 = V_37 ? V_13 -> V_34 : false ;
if ( V_13 -> V_34 ) {
int V_40 ;
if ( V_13 -> V_14 )
V_40 = F_45 ( & V_13 -> V_52 , V_37 ) ;
else
V_40 = F_46 ( V_2 , V_13 , V_37 ) ;
V_13 -> V_16 = V_37 ? V_40 : 0 ;
} else
V_13 -> V_16 = 0 ;
}
static void
F_48 ( struct V_1 * V_7 , bool V_37 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
double V_55 ;
V_9 = F_4 ( & V_7 -> V_3 -> V_11 ) ;
while ( V_9 ) {
V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_9 = F_49 ( V_9 , V_70 ) ;
F_47 ( V_13 , V_7 , V_37 ) ;
V_55 = F_31 ( V_13 ) ;
if ( V_13 -> V_56 || V_55 < V_7 -> V_4 )
continue;
if ( ! V_13 -> V_71 || V_37 )
V_7 -> V_19 ++ ;
if ( V_13 -> V_14 )
V_7 -> V_21 += V_13 -> V_16 ;
else if ( V_37 && ! F_50 ( V_13 , V_7 -> V_4 ) ) {
V_7 -> V_19 ++ ;
V_13 -> V_53 = true ;
V_13 -> V_16 = 1 ;
} else
V_13 -> V_53 = false ;
}
}
static void F_51 ( struct V_1 * V_7 , bool V_37 )
{
V_7 -> V_19 = 0 ;
V_7 -> V_21 = 0 ;
F_48 ( V_7 , V_37 ) ;
V_7 -> V_23 . V_17 = F_8 ( V_7 ) ;
F_18 ( & V_7 -> V_23 ) ;
}
static void F_52 ( struct V_22 * V_7 )
{
F_53 ( V_7 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_54 ( struct V_1 * V_7 , const char * V_72 )
{
int V_73 ;
char V_74 [ 160 ] ;
struct V_75 * V_76 = V_7 -> V_76 ;
int V_77 = V_76 ? V_76 -> V_78 : 0 ;
V_7 -> V_23 . V_11 = & V_7 -> V_3 -> V_11 ;
V_7 -> V_23 . V_17 = F_8 ( V_7 ) ;
F_55 ( V_7 -> V_3 , V_76 , V_74 , sizeof( V_74 ) ) ;
if ( F_56 ( & V_7 -> V_23 , V_74 , L_6 , V_72 ) < 0 )
return - 1 ;
while ( 1 ) {
V_73 = F_57 ( & V_7 -> V_23 , V_77 ) ;
switch ( V_73 ) {
case V_79 : {
T_3 V_17 ;
V_76 -> V_80 ( V_76 -> V_81 ) ;
if ( F_1 ( V_7 ) )
F_17 ( V_7 ) ;
V_17 = F_8 ( V_7 ) ;
F_58 ( & V_7 -> V_23 , V_17 ) ;
if ( V_7 -> V_3 -> V_82 . V_83 !=
V_7 -> V_3 -> V_82 . V_84 [ V_85 ] ) {
V_7 -> V_3 -> V_82 . V_83 =
V_7 -> V_3 -> V_82 . V_84 [ V_85 ] ;
F_52 ( & V_7 -> V_23 ) ;
}
F_55 ( V_7 -> V_3 ,
V_76 , V_74 , sizeof( V_74 ) ) ;
F_59 ( & V_7 -> V_23 , V_74 ) ;
continue;
}
case 'D' : {
static int V_86 ;
struct V_12 * V_87 = F_7 ( V_7 -> V_23 . V_88 ,
struct V_12 , V_8 ) ;
F_60 () ;
F_61 ( L_7 ,
V_86 ++ , V_7 -> V_23 . V_17 ,
V_7 -> V_3 -> V_17 ,
V_7 -> V_23 . V_27 ,
V_7 -> V_23 . V_29 ,
V_7 -> V_23 . V_30 ,
V_87 -> V_89 , V_87 -> V_16 ) ;
}
break;
case 'C' :
F_51 ( V_7 , false ) ;
break;
case 'E' :
F_51 ( V_7 , true ) ;
break;
case 'H' :
V_7 -> V_25 = ! V_7 -> V_25 ;
F_9 ( V_7 ) ;
break;
case V_90 :
if ( F_42 ( V_7 ) )
break;
default:
goto V_91;
}
}
V_91:
F_62 ( & V_7 -> V_23 ) ;
return V_73 ;
}
static void F_63 ( struct V_1 * V_7 ,
struct V_35 * V_43 ,
const char * V_92 , int V_93 ,
unsigned short V_32 ,
struct V_94 * V_81 )
{
int V_95 , V_31 ;
char V_44 = F_21 ( V_43 ) ;
bool V_96 = V_7 -> V_97 && V_43 -> V_67 . V_98 && F_64 ( V_43 -> V_67 . V_98 ) -> V_99 ;
V_95 = V_100 ;
V_31 = V_7 -> V_23 . V_31 - ( V_93 + 2 ) ;
if ( F_65 ( & V_7 -> V_23 , V_32 ) ) {
V_7 -> V_68 = & V_43 -> V_67 ;
V_95 = V_101 ;
V_81 -> V_102 = true ;
}
F_66 ( & V_7 -> V_23 , V_95 ) ;
F_14 ( V_7 , V_32 , 0 ) ;
F_67 ( & V_7 -> V_23 , L_8 , V_93 ) ;
F_68 ( & V_7 -> V_23 , L_9 , V_44 ) ;
F_69 ( & V_7 -> V_23 , V_96 ? V_103 : ' ' ) ;
F_67 ( & V_7 -> V_23 , V_92 , V_31 ) ;
}
static void F_70 ( struct V_1 * V_23 V_45 ,
struct V_35 * V_43 ,
const char * V_92 , int V_93 ,
unsigned short V_32 V_45 ,
struct V_94 * V_81 )
{
char V_44 = F_21 ( V_43 ) ;
V_81 -> V_104 += fprintf ( V_81 -> V_105 , L_10 , V_93 , L_8 ,
V_44 , V_92 ) ;
}
static bool F_71 ( struct V_1 * V_7 ,
unsigned short V_32 )
{
return V_7 -> V_23 . V_27 == V_32 ;
}
static bool F_72 ( struct V_1 * V_7 V_45 ,
unsigned short V_32 V_45 )
{
return false ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_38 * V_39 ,
struct V_35 * V_43 ,
unsigned short V_32 , T_3 V_106 ,
bool V_107 , int V_93 ,
T_4 V_108 ,
struct V_94 * V_81 )
{
char V_109 [ 1024 ] , * V_110 ;
const char * V_92 ;
if ( V_81 -> V_89 != 0 ) {
V_81 -> V_89 -- ;
return 0 ;
}
V_110 = NULL ;
V_92 = F_74 ( V_43 , V_109 , sizeof( V_109 ) ,
V_7 -> V_97 ) ;
if ( V_107 ) {
char V_111 [ 64 ] ;
F_75 ( V_39 , V_111 , sizeof( V_111 ) ,
V_106 ) ;
if ( F_76 ( & V_110 , L_11 , V_111 , V_92 ) < 0 )
V_92 = L_12 ;
else
V_92 = V_110 ;
}
V_108 ( V_7 , V_43 , V_92 , V_93 , V_32 , V_81 ) ;
free ( V_110 ) ;
return 1 ;
}
static bool F_77 ( struct V_8 * V_39 , T_3 V_112 )
{
struct V_38 * V_42 ;
if ( V_39 == NULL )
return false ;
if ( F_24 ( V_39 ) )
return true ;
V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
return F_78 ( V_42 ) != V_112 ;
}
static int F_79 ( struct V_1 * V_7 ,
struct V_41 * V_63 ,
unsigned short V_32 , T_3 V_106 ,
T_3 V_112 ,
T_4 V_108 ,
struct V_94 * V_81 ,
T_5 V_113 )
{
struct V_8 * V_39 ;
int V_114 = V_32 , V_93 = V_115 ;
bool V_107 ;
V_39 = F_4 ( V_63 ) ;
V_107 = F_77 ( V_39 , V_112 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 ;
char V_44 = ' ' ;
int V_57 = true ;
int V_116 = 0 ;
F_25 (chain, &child->parent_val, list) {
bool V_117 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_107 )
V_116 = V_115 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_106 ,
V_117 && V_107 ,
V_93 + V_116 ,
V_108 , V_81 ) ;
if ( V_113 ( V_7 , V_32 ) )
goto V_91;
if ( V_44 == '+' )
goto V_59;
}
F_25 (chain, &child->val, list) {
bool V_117 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_107 )
V_116 = V_115 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_106 ,
V_117 && V_107 ,
V_93 + V_116 ,
V_108 , V_81 ) ;
if ( V_113 ( V_7 , V_32 ) )
goto V_91;
if ( V_44 == '+' )
break;
}
V_59:
if ( V_113 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
V_91:
return V_32 - V_114 ;
}
static char * F_80 ( struct V_1 * V_7 ,
struct V_35 * V_43 ,
char * V_118 , char * V_119 )
{
char V_109 [ 1024 ] ;
const char * V_92 ;
char * V_120 ;
V_92 = F_74 ( V_43 , V_109 , sizeof( V_109 ) ,
V_7 -> V_97 ) ;
if ( V_119 ) {
if ( F_76 ( & V_120 , L_13 , V_119 ,
V_5 . V_121 ? : L_14 , V_92 ) < 0 )
V_120 = NULL ;
} else {
if ( V_118 ) {
if ( F_76 ( & V_120 , L_11 , V_118 , V_92 ) < 0 )
V_120 = NULL ;
} else {
if ( F_76 ( & V_120 , L_6 , V_92 ) < 0 )
V_120 = NULL ;
}
}
return V_120 ;
}
static int F_81 ( struct V_1 * V_7 ,
struct V_41 * V_63 ,
unsigned short V_32 , T_3 V_106 ,
T_3 V_112 ,
T_4 V_108 ,
struct V_94 * V_81 ,
T_5 V_113 )
{
struct V_8 * V_39 ;
int V_114 = V_32 , V_93 = V_115 ;
bool V_107 ;
V_39 = F_4 ( V_63 ) ;
V_107 = F_77 ( V_39 , V_112 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 , * V_122 = NULL ;
int V_57 = true ;
char * V_118 = NULL , * V_123 = NULL ;
char * V_124 = NULL , * V_125 = NULL ;
if ( V_81 -> V_89 != 0 ) {
V_81 -> V_89 -- ;
goto V_59;
}
if ( V_107 ) {
char V_111 [ 64 ] ;
F_75 ( V_42 , V_111 , sizeof( V_111 ) , V_106 ) ;
if ( F_76 ( & V_118 , L_6 , V_111 ) < 0 ) {
V_118 = ( char * ) L_15 ;
goto V_126;
}
V_123 = V_118 ;
}
F_25 (chain, &child->parent_val, list) {
V_124 = F_80 ( V_7 ,
V_43 , V_118 , V_124 ) ;
if ( V_57 ) {
V_57 = false ;
V_122 = V_43 ;
}
if ( V_124 == NULL ) {
V_124 = ( char * ) L_12 ;
goto V_126;
}
V_125 = V_124 ;
}
F_25 (chain, &child->val, list) {
V_124 = F_80 ( V_7 ,
V_43 , V_118 , V_124 ) ;
if ( V_57 ) {
V_57 = false ;
V_122 = V_43 ;
}
if ( V_124 == NULL ) {
V_124 = ( char * ) L_12 ;
goto V_126;
}
V_125 = V_124 ;
}
V_126:
V_108 ( V_7 , V_122 , V_124 , V_93 , V_32 ++ , V_81 ) ;
free ( V_123 ) ;
free ( V_125 ) ;
V_59:
if ( V_113 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
return V_32 - V_114 ;
}
static int F_82 ( struct V_1 * V_7 ,
struct V_41 * V_63 , int V_127 ,
unsigned short V_32 , T_3 V_106 ,
T_3 V_112 ,
T_4 V_108 ,
struct V_94 * V_81 ,
T_5 V_113 )
{
struct V_8 * V_39 ;
int V_114 = V_32 , V_93 = V_127 * V_115 ;
bool V_107 ;
T_3 V_128 = V_106 ;
if ( V_46 . V_47 == V_129 )
V_128 = V_112 ;
V_39 = F_4 ( V_63 ) ;
V_107 = F_77 ( V_39 , V_112 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 ;
char V_44 = ' ' ;
int V_57 = true ;
int V_116 = 0 ;
F_25 (chain, &child->val, list) {
bool V_117 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_107 )
V_116 = V_115 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_128 ,
V_117 && V_107 ,
V_93 + V_116 ,
V_108 , V_81 ) ;
if ( V_113 ( V_7 , V_32 ) )
goto V_91;
if ( V_44 == '+' )
break;
}
if ( V_44 == '-' ) {
const int V_130 = V_127 + ( V_116 ? 2 : 1 ) ;
V_32 += F_82 ( V_7 , & V_42 -> V_41 ,
V_130 , V_32 , V_106 ,
V_42 -> V_131 ,
V_108 , V_81 , V_113 ) ;
}
if ( V_113 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
V_91:
return V_32 - V_114 ;
}
static int F_83 ( struct V_1 * V_7 ,
struct V_12 * V_132 , int V_127 ,
unsigned short V_32 ,
T_4 V_108 ,
struct V_94 * V_81 ,
T_5 V_113 )
{
T_3 V_106 = F_84 ( V_132 -> V_3 ) ;
T_3 V_112 ;
int V_104 ;
if ( V_5 . V_133 )
V_112 = V_132 -> V_134 -> V_135 ;
else
V_112 = V_132 -> V_136 . V_135 ;
if ( V_46 . V_47 == V_48 ) {
V_104 = F_79 ( V_7 ,
& V_132 -> V_52 , V_32 ,
V_106 , V_112 , V_108 , V_81 ,
V_113 ) ;
} else if ( V_46 . V_47 == V_49 ) {
V_104 = F_81 ( V_7 ,
& V_132 -> V_52 , V_32 ,
V_106 , V_112 , V_108 , V_81 ,
V_113 ) ;
} else {
V_104 = F_82 ( V_7 ,
& V_132 -> V_52 , V_127 , V_32 ,
V_106 , V_112 , V_108 , V_81 ,
V_113 ) ;
}
if ( V_81 -> V_102 )
V_7 -> V_65 = V_132 ;
return V_104 ;
}
static int F_85 ( struct V_137 * V_138 , const char * V_139 , ... )
{
struct V_140 * V_81 = V_138 -> V_141 ;
int V_142 , V_143 ;
T_6 args ;
double V_55 ;
va_start ( args , V_139 ) ;
V_143 = va_arg ( args , int ) ;
V_55 = va_arg ( args , double ) ;
va_end ( args ) ;
F_86 ( V_81 -> V_23 , V_55 , V_81 -> V_144 ) ;
V_142 = F_87 ( V_138 -> V_111 , V_138 -> V_145 , V_139 , V_143 , V_55 ) ;
F_68 ( V_81 -> V_23 , L_6 , V_138 -> V_111 ) ;
F_88 ( V_138 , V_142 ) ;
return V_142 ;
}
void F_89 ( void )
{
V_146 [ V_147 ] . V_95 =
V_148 ;
V_146 [ V_149 ] . V_95 =
V_150 ;
V_146 [ V_151 ] . V_95 =
V_152 ;
V_146 [ V_153 ] . V_95 =
V_154 ;
V_146 [ V_155 ] . V_95 =
V_156 ;
V_146 [ V_157 ] . V_95 =
V_158 ;
}
static int F_90 ( struct V_1 * V_7 ,
struct V_12 * V_132 ,
unsigned short V_32 )
{
int V_104 = 0 ;
int V_31 = V_7 -> V_23 . V_31 ;
char V_44 = ' ' ;
bool V_144 = F_65 ( & V_7 -> V_23 , V_32 ) ;
T_7 V_89 = V_132 -> V_89 ;
bool V_57 = true ;
struct V_159 * V_139 ;
if ( V_144 ) {
V_7 -> V_65 = V_132 ;
V_7 -> V_68 = & V_132 -> V_67 ;
}
if ( V_5 . V_160 ) {
F_41 ( V_132 ) ;
V_44 = F_20 ( V_132 ) ;
}
if ( V_89 == 0 ) {
struct V_140 V_81 = {
. V_23 = & V_7 -> V_23 ,
. V_44 = V_44 ,
. V_144 = V_144 ,
} ;
int V_33 = 0 ;
F_14 ( V_7 , V_32 , 0 ) ;
F_91 (browser->hists, fmt) {
char V_161 [ 2048 ] ;
struct V_137 V_138 = {
. V_111 = V_161 ,
. V_145 = sizeof( V_161 ) ,
. V_141 = & V_81 ,
} ;
if ( F_92 ( V_139 , V_132 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
if ( V_144 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_101 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_100 ) ;
}
if ( V_57 ) {
if ( V_5 . V_160 ) {
F_68 ( & V_7 -> V_23 , L_16 , V_44 ) ;
V_31 -= 2 ;
}
V_57 = false ;
} else {
F_68 ( & V_7 -> V_23 , L_17 ) ;
V_31 -= 2 ;
}
if ( V_139 -> V_95 ) {
int V_142 = V_139 -> V_95 ( V_139 , & V_138 , V_132 ) ;
F_93 ( V_132 , & V_138 , V_139 , V_142 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 + V_142 ) ;
} else {
F_93 ( V_132 , & V_138 , V_139 , V_139 -> V_132 ( V_139 , & V_138 , V_132 ) ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 ) ;
}
V_31 -= V_138 . V_111 - V_161 ;
}
if ( ! V_7 -> V_23 . V_163 )
V_31 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_31 ) ;
++ V_32 ;
++ V_104 ;
} else
-- V_89 ;
if ( V_44 == '-' && V_32 != V_7 -> V_23 . V_27 ) {
struct V_94 V_81 = {
. V_89 = V_89 ,
. V_102 = V_144 ,
} ;
V_104 += F_83 ( V_7 , V_132 , 1 , V_32 ,
F_63 , & V_81 ,
F_71 ) ;
}
return V_104 ;
}
static int F_94 ( struct V_1 * V_7 ,
struct V_12 * V_132 ,
unsigned short V_32 ,
int V_127 )
{
int V_104 = 0 ;
int V_31 = V_7 -> V_23 . V_31 ;
char V_44 = ' ' ;
bool V_144 = F_65 ( & V_7 -> V_23 , V_32 ) ;
T_7 V_89 = V_132 -> V_89 ;
bool V_57 = true ;
struct V_159 * V_139 ;
struct V_164 * V_165 ;
struct V_140 V_81 = {
. V_23 = & V_7 -> V_23 ,
. V_144 = V_144 ,
} ;
int V_33 = 0 ;
int V_166 = ( V_132 -> V_3 -> V_167 - 2 ) * V_168 ;
if ( V_144 ) {
V_7 -> V_65 = V_132 ;
V_7 -> V_68 = & V_132 -> V_67 ;
}
F_41 ( V_132 ) ;
V_44 = F_20 ( V_132 ) ;
V_81 . V_44 = V_44 ;
if ( V_132 -> V_14 && V_89 ) {
V_89 -- ;
goto V_169;
}
F_14 ( V_7 , V_32 , 0 ) ;
if ( V_144 && V_7 -> V_23 . V_163 )
F_66 ( & V_7 -> V_23 , V_101 ) ;
else
F_66 ( & V_7 -> V_23 , V_100 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_127 * V_168 ) ;
V_31 -= V_127 * V_168 ;
V_165 = F_95 ( & V_132 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
char V_161 [ 2048 ] ;
struct V_137 V_138 = {
. V_111 = V_161 ,
. V_145 = sizeof( V_161 ) ,
. V_141 = & V_81 ,
} ;
if ( F_92 ( V_139 , V_132 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
if ( V_144 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_101 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_100 ) ;
}
if ( V_57 ) {
F_68 ( & V_7 -> V_23 , L_9 , V_44 ) ;
V_31 -- ;
V_57 = false ;
} else {
F_68 ( & V_7 -> V_23 , L_17 ) ;
V_31 -= 2 ;
}
if ( V_139 -> V_95 ) {
int V_142 = V_139 -> V_95 ( V_139 , & V_138 , V_132 ) ;
F_93 ( V_132 , & V_138 , V_139 , V_142 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 + V_142 ) ;
} else {
int V_142 = V_139 -> V_132 ( V_139 , & V_138 , V_132 ) ;
F_93 ( V_132 , & V_138 , V_139 , V_142 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 ) ;
}
V_31 -= V_138 . V_111 - V_161 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_166 ) ;
V_31 -= V_166 ;
if ( V_33 >= V_7 -> V_23 . V_162 ) {
char V_161 [ 2048 ] ;
struct V_137 V_138 = {
. V_111 = V_161 ,
. V_145 = sizeof( V_161 ) ,
. V_141 = & V_81 ,
} ;
if ( V_144 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_101 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_100 ) ;
}
F_96 (entry->hpp_list, fmt) {
F_67 ( & V_7 -> V_23 , L_18 , 2 ) ;
V_31 -= 2 ;
if ( V_139 -> V_95 ) {
V_31 -= V_139 -> V_95 ( V_139 , & V_138 , V_132 ) ;
} else {
int V_171 = 0 ;
V_31 -= V_139 -> V_132 ( V_139 , & V_138 , V_132 ) ;
F_68 ( & V_7 -> V_23 , L_6 , F_97 ( V_161 ) ) ;
while ( isspace ( V_161 [ V_171 ++ ] ) )
V_31 ++ ;
}
}
}
if ( ! V_7 -> V_23 . V_163 )
V_31 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_31 ) ;
++ V_32 ;
++ V_104 ;
V_169:
if ( V_132 -> V_14 && V_44 == '-' && V_32 != V_7 -> V_23 . V_27 ) {
struct V_94 V_172 = {
. V_89 = V_89 ,
} ;
V_104 += F_83 ( V_7 , V_132 ,
V_127 + 1 , V_32 ,
F_63 , & V_172 ,
F_71 ) ;
}
return V_104 ;
}
static int F_98 ( struct V_1 * V_7 ,
unsigned short V_32 , int V_127 )
{
int V_31 = V_7 -> V_23 . V_31 ;
bool V_144 = F_65 ( & V_7 -> V_23 , V_32 ) ;
bool V_57 = true ;
int V_33 = 0 ;
int V_142 ;
struct V_159 * V_139 ;
struct V_164 * V_165 ;
int V_173 = V_7 -> V_3 -> V_167 - 2 ;
if ( V_144 ) {
V_7 -> V_65 = NULL ;
V_7 -> V_68 = NULL ;
}
F_14 ( V_7 , V_32 , 0 ) ;
if ( V_144 && V_7 -> V_23 . V_163 )
F_66 ( & V_7 -> V_23 , V_101 ) ;
else
F_66 ( & V_7 -> V_23 , V_100 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_127 * V_168 ) ;
V_31 -= V_127 * V_168 ;
V_165 = F_95 ( & V_7 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( F_92 ( V_139 , V_7 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_142 = V_139 -> V_31 ( V_139 , NULL , F_99 ( V_7 -> V_3 ) ) ;
if ( V_57 ) {
V_57 = false ;
V_142 ++ ;
} else {
V_142 += 2 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_142 ) ;
V_31 -= V_142 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_173 * V_168 ) ;
V_31 -= V_173 * V_168 ;
if ( V_33 >= V_7 -> V_23 . V_162 ) {
char V_111 [ 32 ] ;
V_142 = snprintf ( V_111 , sizeof( V_111 ) , L_19 , V_7 -> V_4 ) ;
F_68 ( & V_7 -> V_23 , L_20 , V_111 ) ;
V_31 -= V_142 + 2 ;
}
if ( ! V_7 -> V_23 . V_163 )
V_31 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_31 ) ;
return 1 ;
}
static int F_100 ( struct V_137 * V_138 , int V_174 )
{
F_88 ( V_138 , V_174 ) ;
return V_138 -> V_145 <= 0 ;
}
static int F_101 ( struct V_1 * V_7 , char * V_111 , T_8 V_145 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_137 V_175 = {
. V_111 = V_111 ,
. V_145 = V_145 ,
} ;
struct V_159 * V_139 ;
T_8 V_142 = 0 ;
int V_33 = 0 ;
if ( V_5 . V_160 ) {
V_142 = F_87 ( V_111 , V_145 , L_17 ) ;
if ( F_100 ( & V_175 , V_142 ) )
return V_142 ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_139 , V_3 ) || V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_142 = V_139 -> V_176 ( V_139 , & V_175 , F_99 ( V_3 ) ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
V_142 = F_87 ( V_175 . V_111 , V_175 . V_145 , L_17 ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
}
return V_142 ;
}
static int F_102 ( struct V_1 * V_7 , char * V_111 , T_8 V_145 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_137 V_175 = {
. V_111 = V_111 ,
. V_145 = V_145 ,
} ;
struct V_159 * V_139 ;
struct V_164 * V_165 ;
T_8 V_142 = 0 ;
int V_33 = 0 ;
int V_173 = V_3 -> V_167 - 2 ;
bool V_177 , V_178 ;
V_142 = F_87 ( V_111 , V_145 , L_8 ) ;
if ( F_100 ( & V_175 , V_142 ) )
return V_142 ;
V_165 = F_95 ( & V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_142 = V_139 -> V_176 ( V_139 , & V_175 , F_99 ( V_3 ) ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
V_142 = F_87 ( V_175 . V_111 , V_175 . V_145 , L_17 ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
}
V_142 = F_87 ( V_175 . V_111 , V_175 . V_145 , L_21 ,
V_173 * V_168 , L_18 ) ;
if ( F_100 ( & V_175 , V_142 ) )
return V_142 ;
V_177 = true ;
F_103 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_177 ) {
V_142 = F_87 ( V_175 . V_111 , V_175 . V_145 , L_22 ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
}
V_177 = false ;
V_178 = true ;
F_96 (&fmt_node->hpp, fmt) {
char * V_179 ;
if ( F_92 ( V_139 , V_3 ) )
continue;
if ( ! V_178 ) {
V_142 = F_87 ( V_175 . V_111 , V_175 . V_145 , L_23 ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
}
V_178 = false ;
V_142 = V_139 -> V_176 ( V_139 , & V_175 , F_99 ( V_3 ) ) ;
V_175 . V_111 [ V_142 ] = '\0' ;
V_179 = F_104 ( V_175 . V_111 ) ;
V_142 = strlen ( V_179 ) ;
if ( V_179 != V_175 . V_111 )
memmove ( V_175 . V_111 , V_179 , V_142 + 1 ) ;
if ( F_100 ( & V_175 , V_142 ) )
break;
}
}
return V_142 ;
}
static void F_105 ( struct V_1 * V_7 )
{
char V_180 [ 1024 ] ;
if ( V_5 . V_18 )
F_102 ( V_7 , V_180 ,
sizeof( V_180 ) ) ;
else
F_101 ( V_7 , V_180 ,
sizeof( V_180 ) ) ;
F_15 ( & V_7 -> V_23 , 0 , 0 ) ;
F_66 ( & V_7 -> V_23 , V_181 ) ;
F_67 ( & V_7 -> V_23 , V_180 , V_7 -> V_23 . V_31 + 1 ) ;
}
static void F_106 ( struct V_22 * V_7 )
{
if ( V_7 -> V_88 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
V_7 -> V_88 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
}
}
static unsigned int F_107 ( struct V_22 * V_7 )
{
unsigned V_32 = 0 ;
T_2 V_24 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
if ( V_2 -> V_25 ) {
F_105 ( V_2 ) ;
V_24 = 1 ;
}
F_106 ( V_7 ) ;
V_2 -> V_65 = NULL ;
V_2 -> V_68 = NULL ;
for ( V_9 = V_7 -> V_88 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 ;
if ( V_87 -> V_56 ) {
V_87 -> V_15 = false ;
continue;
}
V_55 = F_31 ( V_87 ) ;
if ( V_55 < V_2 -> V_4 )
continue;
if ( V_5 . V_18 ) {
V_32 += F_94 ( V_2 , V_87 , V_32 ,
V_87 -> V_71 ) ;
if ( V_32 == V_7 -> V_27 )
break;
if ( V_87 -> V_53 ) {
F_98 ( V_2 , V_32 , V_87 -> V_71 + 1 ) ;
V_32 ++ ;
}
} else {
V_32 += F_90 ( V_2 , V_87 , V_32 ) ;
}
if ( V_32 == V_7 -> V_27 )
break;
}
return V_32 + V_24 ;
}
static struct V_8 * F_5 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 = F_31 ( V_87 ) ;
if ( ! V_87 -> V_56 && V_55 >= V_4 )
return V_9 ;
if ( F_24 ( V_9 ) )
V_9 = F_24 ( V_9 ) ;
else
V_9 = F_6 ( V_9 ) ;
}
return NULL ;
}
static struct V_8 * F_108 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 = F_31 ( V_87 ) ;
if ( ! V_87 -> V_56 && V_55 >= V_4 )
return V_9 ;
V_9 = F_109 ( V_9 ) ;
}
return NULL ;
}
static void F_110 ( struct V_22 * V_7 ,
T_7 V_93 , int V_182 )
{
struct V_12 * V_87 ;
struct V_8 * V_9 ;
bool V_57 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
if ( V_7 -> V_17 == 0 )
return;
F_106 ( V_7 ) ;
switch ( V_182 ) {
case V_183 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_184 :
V_9 = V_7 -> V_88 ;
goto V_185;
case V_186 :
V_9 = F_111 ( F_112 ( V_7 -> V_11 ) ) ;
V_9 = F_108 ( V_9 , V_2 -> V_4 ) ;
V_57 = false ;
break;
default:
return;
}
V_87 = F_7 ( V_7 -> V_88 , struct V_12 , V_8 ) ;
V_87 -> V_89 = 0 ;
V_185:
if ( ! V_9 )
return;
if ( V_93 > 0 ) {
do {
V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_87 -> V_15 && V_87 -> V_14 ) {
T_2 V_187 = V_87 -> V_16 - V_87 -> V_89 ;
if ( V_93 > V_187 ) {
V_93 -= V_187 ;
V_87 -> V_89 = 0 ;
} else {
V_87 -> V_89 += V_93 ;
V_93 = 0 ;
V_7 -> V_88 = V_9 ;
break;
}
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
-- V_93 ;
V_7 -> V_88 = V_9 ;
} while ( V_93 != 0 );
} else if ( V_93 < 0 ) {
while ( 1 ) {
V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_87 -> V_15 && V_87 -> V_14 ) {
if ( V_57 ) {
if ( - V_93 > V_87 -> V_89 ) {
V_93 += V_87 -> V_89 ;
V_87 -> V_89 = 0 ;
} else {
V_87 -> V_89 += V_93 ;
V_93 = 0 ;
V_7 -> V_88 = V_9 ;
break;
}
} else {
if ( - V_93 > V_87 -> V_16 ) {
V_93 += V_87 -> V_16 ;
V_87 -> V_89 = 0 ;
} else {
V_87 -> V_89 = V_87 -> V_16 + V_93 ;
V_93 = 0 ;
V_7 -> V_88 = V_9 ;
break;
}
}
}
V_9 = F_108 ( F_109 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
++ V_93 ;
V_7 -> V_88 = V_9 ;
if ( V_93 == 0 ) {
V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_87 -> V_15 && V_87 -> V_14 )
V_87 -> V_89 = V_87 -> V_16 ;
break;
}
V_57 = false ;
}
} else {
V_7 -> V_88 = V_9 ;
V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_87 -> V_89 = 0 ;
}
}
static int F_113 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_105 ,
int V_127 )
{
struct V_94 V_81 = {
. V_105 = V_105 ,
} ;
F_83 ( V_7 , V_13 , V_127 , 0 ,
F_70 , & V_81 ,
F_72 ) ;
return V_81 . V_104 ;
}
static int F_114 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_105 )
{
char V_161 [ 8192 ] ;
int V_104 = 0 ;
char V_44 = ' ' ;
struct V_137 V_138 = {
. V_111 = V_161 ,
. V_145 = sizeof( V_161 ) ,
} ;
struct V_159 * V_139 ;
bool V_57 = true ;
int V_142 ;
if ( V_5 . V_160 ) {
V_44 = F_20 ( V_13 ) ;
V_104 += fprintf ( V_105 , L_16 , V_44 ) ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_139 , V_13 -> V_3 ) )
continue;
if ( ! V_57 ) {
V_142 = F_87 ( V_138 . V_111 , V_138 . V_145 , L_17 ) ;
F_88 ( & V_138 , V_142 ) ;
} else
V_57 = false ;
V_142 = V_139 -> V_132 ( V_139 , & V_138 , V_13 ) ;
V_142 = F_93 ( V_13 , & V_138 , V_139 , V_142 ) ;
F_88 ( & V_138 , V_142 ) ;
}
V_104 += fprintf ( V_105 , L_24 , V_161 ) ;
if ( V_44 == '-' )
V_104 += F_113 ( V_7 , V_13 , V_105 , 1 ) ;
return V_104 ;
}
static int F_115 ( struct V_1 * V_7 ,
struct V_12 * V_13 ,
T_9 * V_105 , int V_127 )
{
char V_161 [ 8192 ] ;
int V_104 = 0 ;
char V_44 = ' ' ;
struct V_137 V_138 = {
. V_111 = V_161 ,
. V_145 = sizeof( V_161 ) ,
} ;
struct V_159 * V_139 ;
struct V_164 * V_165 ;
bool V_57 = true ;
int V_142 ;
int V_166 = ( V_13 -> V_3 -> V_167 - 2 ) * V_168 ;
V_104 = fprintf ( V_105 , L_21 , V_127 * V_168 , L_18 ) ;
V_44 = F_20 ( V_13 ) ;
V_104 += fprintf ( V_105 , L_9 , V_44 ) ;
V_165 = F_95 ( & V_13 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( ! V_57 ) {
V_142 = F_87 ( V_138 . V_111 , V_138 . V_145 , L_17 ) ;
F_88 ( & V_138 , V_142 ) ;
} else
V_57 = false ;
V_142 = V_139 -> V_132 ( V_139 , & V_138 , V_13 ) ;
F_88 ( & V_138 , V_142 ) ;
}
V_142 = F_87 ( V_138 . V_111 , V_138 . V_145 , L_21 , V_166 , L_18 ) ;
F_88 ( & V_138 , V_142 ) ;
F_96 (he->hpp_list, fmt) {
V_142 = F_87 ( V_138 . V_111 , V_138 . V_145 , L_17 ) ;
F_88 ( & V_138 , V_142 ) ;
V_142 = V_139 -> V_132 ( V_139 , & V_138 , V_13 ) ;
F_88 ( & V_138 , V_142 ) ;
}
V_104 += fprintf ( V_105 , L_24 , F_116 ( V_161 ) ) ;
if ( V_13 -> V_14 && V_44 == '-' ) {
V_104 += F_113 ( V_7 , V_13 , V_105 ,
V_13 -> V_71 + 1 ) ;
}
return V_104 ;
}
static int F_117 ( struct V_1 * V_7 , T_9 * V_105 )
{
struct V_8 * V_9 = F_5 ( F_4 ( V_7 -> V_23 . V_11 ) ,
V_7 -> V_4 ) ;
int V_104 = 0 ;
while ( V_9 ) {
struct V_12 * V_87 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_5 . V_18 ) {
V_104 += F_115 ( V_7 ,
V_87 , V_105 ,
V_87 -> V_71 ) ;
} else {
V_104 += F_114 ( V_7 , V_87 , V_105 ) ;
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_7 -> V_4 ) ;
}
return V_104 ;
}
static int F_118 ( struct V_1 * V_7 )
{
char V_188 [ 64 ] ;
T_9 * V_105 ;
while ( 1 ) {
F_87 ( V_188 , sizeof( V_188 ) , L_25 , V_7 -> V_189 ) ;
if ( F_119 ( V_188 , V_190 ) )
break;
if ( ++ V_7 -> V_189 == 8192 ) {
F_61 ( L_26 ) ;
return - 1 ;
}
}
V_105 = fopen ( V_188 , L_27 ) ;
if ( V_105 == NULL ) {
char V_109 [ 64 ] ;
const char * V_191 = F_120 ( V_192 , V_109 , sizeof( V_109 ) ) ;
F_61 ( L_28 , V_188 , V_191 ) ;
return - 1 ;
}
++ V_7 -> V_189 ;
F_117 ( V_7 , V_105 ) ;
fclose ( V_105 ) ;
F_61 ( L_29 , V_188 ) ;
return 0 ;
}
static struct V_1 * F_121 ( struct V_3 * V_3 ,
struct V_75 * V_76 ,
struct V_193 * V_194 )
{
struct V_1 * V_7 = F_122 ( sizeof( * V_7 ) ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_23 . V_78 = F_107 ;
V_7 -> V_23 . V_195 = F_10 ;
V_7 -> V_23 . V_196 = F_110 ;
V_7 -> V_23 . V_197 = true ;
V_7 -> V_25 = V_5 . V_198 ;
V_7 -> V_76 = V_76 ;
V_7 -> V_194 = V_194 ;
}
return V_7 ;
}
static void F_123 ( struct V_1 * V_7 )
{
free ( V_7 ) ;
}
static struct V_12 * F_124 ( struct V_1 * V_7 )
{
return V_7 -> V_65 ;
}
static struct V_199 * F_125 ( struct V_1 * V_7 )
{
return V_7 -> V_65 -> V_199 ;
}
static inline bool F_126 ( void * V_80 )
{
return V_80 == NULL ;
}
static int F_55 ( struct V_3 * V_3 ,
struct V_75 * V_76 ,
char * V_109 , T_8 V_145 )
{
char V_200 ;
int V_104 ;
const struct V_201 * V_201 = V_3 -> V_202 ;
const struct V_199 * V_199 = V_3 -> V_203 ;
int V_204 = V_3 -> V_205 ;
unsigned long V_206 = V_3 -> V_82 . V_84 [ V_207 ] ;
T_3 V_84 = V_3 -> V_82 . V_208 ;
struct V_209 * V_210 = F_99 ( V_3 ) ;
const char * V_211 = F_127 ( V_210 ) ;
char V_111 [ 512 ] ;
T_8 V_212 = sizeof( V_111 ) ;
char V_213 [ 30 ] = L_30 ;
bool V_214 = false ;
if ( V_5 . V_215 ) {
V_206 = V_3 -> V_82 . V_216 ;
V_84 = V_3 -> V_82 . V_217 ;
}
if ( F_128 ( V_210 ) ) {
struct V_209 * V_218 ;
F_129 ( V_210 , V_111 , V_212 ) ;
V_211 = V_111 ;
F_130 (pos, evsel) {
struct V_3 * V_219 = F_131 ( V_218 ) ;
if ( V_5 . V_215 ) {
V_206 += V_219 -> V_82 . V_216 ;
V_84 += V_219 -> V_82 . V_217 ;
} else {
V_206 += V_219 -> V_82 . V_84 [ V_207 ] ;
V_84 += V_219 -> V_82 . V_208 ;
}
}
}
if ( V_5 . V_220 &&
strstr ( V_211 , L_31 ) )
V_214 = true ;
V_206 = F_132 ( V_206 , & V_200 ) ;
V_104 = F_87 ( V_109 , V_145 ,
L_32 V_221 ,
V_206 , V_200 , V_211 , V_214 ? V_213 : L_8 , V_84 ) ;
if ( V_3 -> V_222 )
V_104 += snprintf ( V_109 + V_104 , V_145 - V_104 ,
L_33 , V_3 -> V_222 ) ;
if ( V_199 ) {
if ( F_133 ( V_3 , V_199 ) ) {
V_104 += F_87 ( V_109 + V_104 , V_145 - V_104 ,
L_34 ,
( V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ) ,
V_199 -> V_224 ) ;
} else {
V_104 += F_87 ( V_109 + V_104 , V_145 - V_104 ,
L_35 ,
( V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ) ) ;
}
}
if ( V_201 )
V_104 += F_87 ( V_109 + V_104 , V_145 - V_104 ,
L_36 , V_201 -> V_225 ) ;
if ( V_204 > - 1 )
V_104 += F_87 ( V_109 + V_104 , V_145 - V_104 ,
L_37 , V_204 ) ;
if ( ! F_126 ( V_76 ) ) {
struct V_226 * V_88 = V_76 -> V_81 ;
if ( V_88 -> V_227 )
V_104 += F_87 ( V_109 + V_104 , V_145 - V_104 , L_38 ) ;
}
return V_104 ;
}
static inline void F_135 ( char * * V_228 , int V_40 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_40 ; ++ V_171 )
F_136 ( & V_228 [ V_171 ] ) ;
}
static int F_137 ( void )
{
char * V_229 , * V_228 [ 32 ] , * V_230 [ 32 ] , * V_231 ;
T_10 * V_232 ;
int V_233 = 0 , V_234 = - 1 , V_142 = - 1 ;
struct V_235 * V_236 ;
V_229 = getenv ( L_39 ) ;
if ( ! V_229 )
return V_142 ;
V_232 = F_138 ( V_229 ) ;
if ( ! V_232 )
return V_142 ;
memset ( V_228 , 0 , sizeof( V_228 ) ) ;
memset ( V_228 , 0 , sizeof( V_230 ) ) ;
while ( ( V_236 = F_139 ( V_232 ) ) ) {
char V_237 [ V_238 ] ;
T_3 V_239 ;
char * V_240 = V_236 -> V_241 ;
T_9 * V_242 ;
if ( ! ( V_236 -> V_243 == V_244 ) )
continue;
snprintf ( V_237 , sizeof( V_237 ) , L_40 , V_229 , V_240 ) ;
V_242 = fopen ( V_237 , L_41 ) ;
if ( ! V_242 )
continue;
if ( fread ( & V_239 , 1 , 8 , V_242 ) < 8 )
goto V_245;
if ( F_140 ( V_239 ) ) {
V_228 [ V_233 ] = F_141 ( V_240 ) ;
if ( ! V_228 [ V_233 ] )
goto V_245;
V_230 [ V_233 ] = F_141 ( V_237 ) ;
if ( ! V_230 [ V_233 ] ) {
F_136 ( & V_228 [ V_233 ] ) ;
F_142 ( L_42 ) ;
fclose ( V_242 ) ;
break;
}
V_233 ++ ;
}
V_245:
fclose ( V_242 ) ;
if ( V_233 >= 32 ) {
F_142 ( L_43
L_44 ) ;
break;
}
}
F_143 ( V_232 ) ;
if ( V_233 ) {
V_234 = F_144 ( V_233 , V_228 ) ;
if ( V_234 < V_233 && V_234 >= 0 ) {
V_231 = F_141 ( V_230 [ V_234 ] ) ;
if ( V_231 ) {
if ( V_246 )
free ( ( void * ) V_247 ) ;
V_247 = V_231 ;
V_246 = true ;
V_142 = 0 ;
} else
F_142 ( L_45 ) ;
}
}
F_135 ( V_228 , V_233 ) ;
F_135 ( V_230 , V_233 ) ;
return V_142 ;
}
static int
F_145 ( struct V_1 * V_7 , struct V_248 * V_249 )
{
struct V_209 * V_210 ;
struct V_250 * V_251 ;
struct V_12 * V_13 ;
int V_191 ;
if ( ! V_252 && F_146 ( V_7 -> V_194 ) )
return 0 ;
V_251 = F_64 ( V_249 -> V_67 . V_98 ) ;
if ( ! V_251 -> V_99 )
return 0 ;
V_210 = F_99 ( V_7 -> V_3 ) ;
V_191 = F_147 ( & V_249 -> V_67 , V_210 , V_7 -> V_76 ) ;
V_13 = F_124 ( V_7 ) ;
if ( ( V_191 == 'q' || V_191 == F_148 ( 'c' ) ) && V_13 -> V_253 )
return 1 ;
F_58 ( & V_7 -> V_23 , V_7 -> V_3 -> V_17 ) ;
if ( V_191 )
F_149 ( & V_7 -> V_23 ) ;
return 0 ;
}
static int
F_150 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 , char * * V_254 ,
struct V_255 * V_255 , struct V_256 * V_98 )
{
if ( V_98 == NULL || V_255 -> V_201 -> V_257 )
return 0 ;
if ( F_76 ( V_254 , L_46 , V_98 -> V_240 ) < 0 )
return 0 ;
V_249 -> V_67 . V_255 = V_255 ;
V_249 -> V_67 . V_98 = V_98 ;
V_249 -> V_258 = F_145 ;
return 1 ;
}
static int
F_151 ( struct V_1 * V_7 , struct V_248 * V_249 )
{
struct V_199 * V_199 = V_249 -> V_199 ;
if ( ( ! F_133 ( V_7 -> V_3 , V_199 ) &&
! F_133 ( V_7 -> V_3 , V_259 ) ) || V_199 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_203 ) {
F_152 ( V_7 -> V_260 , & V_7 -> V_3 -> V_203 ) ;
F_153 ( V_261 , false ) ;
F_154 ( V_7 -> V_3 -> V_203 ) ;
F_60 () ;
} else {
if ( F_133 ( V_7 -> V_3 , V_199 ) ) {
F_61 ( L_47 ,
V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ,
V_199 -> V_224 ) ;
} else {
F_61 ( L_48 ,
V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ) ;
}
V_7 -> V_3 -> V_203 = F_155 ( V_199 ) ;
F_153 ( V_261 , false ) ;
F_156 ( V_7 -> V_260 , & V_7 -> V_3 -> V_203 ) ;
}
F_157 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_158 ( struct V_1 * V_7 , struct V_248 * V_249 ,
char * * V_254 , struct V_199 * V_199 )
{
int V_142 ;
if ( ( ! F_133 ( V_7 -> V_3 , V_199 ) &&
! F_133 ( V_7 -> V_3 , V_259 ) ) || V_199 == NULL )
return 0 ;
if ( F_133 ( V_7 -> V_3 , V_199 ) ) {
V_142 = F_76 ( V_254 , L_49 ,
V_7 -> V_3 -> V_203 ? L_50 : L_51 ,
V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ,
V_199 -> V_224 ) ;
} else {
V_142 = F_76 ( V_254 , L_52 ,
V_7 -> V_3 -> V_203 ? L_50 : L_51 ,
V_199 -> V_223 ? F_134 ( V_199 ) : L_18 ) ;
}
if ( V_142 < 0 )
return 0 ;
V_249 -> V_199 = V_199 ;
V_249 -> V_258 = F_151 ;
return 1 ;
}
static int
F_159 ( struct V_1 * V_7 , struct V_248 * V_249 )
{
struct V_255 * V_255 = V_249 -> V_67 . V_255 ;
if ( ! F_133 ( V_7 -> V_3 , V_201 ) || V_255 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_202 ) {
F_152 ( V_7 -> V_260 , & V_7 -> V_3 -> V_202 ) ;
F_153 ( V_262 , false ) ;
V_7 -> V_3 -> V_202 = NULL ;
F_60 () ;
} else {
if ( V_255 == NULL )
return 0 ;
F_61 ( L_53 ,
F_160 ( V_255 ) ? L_54 : V_255 -> V_201 -> V_225 ) ;
V_7 -> V_3 -> V_202 = V_255 -> V_201 ;
F_153 ( V_262 , true ) ;
F_156 ( V_7 -> V_260 , & V_7 -> V_3 -> V_202 ) ;
}
F_161 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_162 ( struct V_1 * V_7 , struct V_248 * V_249 ,
char * * V_254 , struct V_255 * V_255 )
{
if ( ! F_133 ( V_7 -> V_3 , V_201 ) || V_255 == NULL )
return 0 ;
if ( F_76 ( V_254 , L_55 ,
V_7 -> V_3 -> V_202 ? L_50 : L_51 ,
F_160 ( V_255 ) ? L_54 : V_255 -> V_201 -> V_225 ) < 0 )
return 0 ;
V_249 -> V_67 . V_255 = V_255 ;
V_249 -> V_258 = F_159 ;
return 1 ;
}
static int
F_163 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 )
{
F_164 ( V_249 -> V_67 . V_255 ) ;
return 0 ;
}
static int
F_165 ( struct V_1 * V_7 ,
struct V_248 * V_249 , char * * V_254 , struct V_255 * V_255 )
{
if ( ! F_133 ( V_7 -> V_3 , V_201 ) || V_255 == NULL )
return 0 ;
if ( F_76 ( V_254 , L_56 ) < 0 )
return 0 ;
V_249 -> V_67 . V_255 = V_255 ;
V_249 -> V_258 = F_163 ;
return 1 ;
}
static int
F_166 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 )
{
char V_263 [ 64 ] ;
memset ( V_263 , 0 , sizeof( V_263 ) ) ;
if ( V_249 -> V_199 ) {
F_87 ( V_263 , sizeof( V_263 ) , L_57 ,
F_134 ( V_249 -> V_199 ) ) ;
} else if ( V_249 -> V_67 . V_98 ) {
F_87 ( V_263 , sizeof( V_263 ) , L_58 ,
V_249 -> V_67 . V_98 -> V_240 ) ;
}
F_167 ( V_263 ) ;
return 0 ;
}
static int
F_168 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 , char * * V_254 ,
struct V_199 * V_199 , struct V_256 * V_98 )
{
if ( V_199 ) {
if ( F_76 ( V_254 , L_59 ,
F_134 ( V_199 ) ) < 0 )
return 0 ;
} else if ( V_98 ) {
if ( F_76 ( V_254 , L_60 ,
V_98 -> V_240 ) < 0 )
return 0 ;
} else {
if ( F_76 ( V_254 , L_61 ) < 0 )
return 0 ;
}
V_249 -> V_199 = V_199 ;
V_249 -> V_67 . V_98 = V_98 ;
V_249 -> V_258 = F_166 ;
return 1 ;
}
static int
F_169 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 V_45 )
{
if ( F_137 () ) {
F_142 ( L_62
L_63 ) ;
return 0 ;
}
return V_264 ;
}
static int
F_170 ( struct V_1 * V_7 ,
struct V_248 * V_249 , char * * V_254 )
{
if ( ! F_126 ( V_7 -> V_76 ) )
return 0 ;
if ( F_76 ( V_254 , L_64 ) < 0 )
return 0 ;
V_249 -> V_258 = F_169 ;
return 1 ;
}
static int
F_171 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 V_45 )
{
return 0 ;
}
static int
F_172 ( struct V_1 * V_7 V_45 ,
struct V_248 * V_249 , char * * V_254 )
{
if ( F_76 ( V_254 , L_65 ) < 0 )
return 0 ;
V_249 -> V_258 = F_171 ;
return 1 ;
}
static int
F_173 ( struct V_1 * V_7 , struct V_248 * V_249 )
{
if ( ! F_133 ( V_7 -> V_3 , V_265 ) || V_249 -> V_265 < 0 )
return 0 ;
if ( V_7 -> V_3 -> V_205 > - 1 ) {
F_152 ( V_7 -> V_260 , & V_7 -> V_3 -> V_205 ) ;
V_7 -> V_3 -> V_205 = - 1 ;
F_153 ( V_266 , false ) ;
} else {
V_7 -> V_3 -> V_205 = V_249 -> V_265 ;
F_153 ( V_266 , true ) ;
F_156 ( V_7 -> V_260 , & V_7 -> V_3 -> V_205 ) ;
}
F_174 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_175 ( struct V_1 * V_7 , struct V_248 * V_249 ,
char * * V_254 , int V_204 )
{
if ( ! F_133 ( V_7 -> V_3 , V_265 ) || V_204 < 0 )
return 0 ;
if ( F_76 ( V_254 , L_66 ,
( V_7 -> V_3 -> V_205 > - 1 ) ? L_50 : L_51 ,
V_204 ) < 0 )
return 0 ;
V_249 -> V_265 = V_204 ;
V_249 -> V_258 = F_173 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 V_17 = 0 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
if ( V_2 -> V_4 == 0 && ! V_5 . V_18 ) {
V_2 -> V_20 = V_2 -> V_3 -> V_20 ;
return;
}
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_17 ++ ;
V_9 = F_6 ( V_9 ) ;
}
V_2 -> V_20 = V_17 ;
V_2 -> V_19 = V_17 ;
}
static void F_176 ( struct V_1 * V_2 ,
double V_55 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
T_3 V_106 = F_84 ( V_2 -> V_3 ) ;
T_3 V_267 = V_106 * ( V_55 / 100 ) ;
V_2 -> V_4 = V_46 . V_268 = V_55 ;
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_13 -> V_53 ) {
V_13 -> V_53 = false ;
V_13 -> V_16 = 0 ;
}
if ( ! V_13 -> V_14 || ! V_5 . V_160 )
goto V_59;
if ( V_46 . V_47 == V_129 ) {
V_106 = V_13 -> V_136 . V_135 ;
if ( V_5 . V_133 )
V_106 = V_13 -> V_134 -> V_135 ;
V_267 = V_106 * ( V_55 / 100 ) ;
}
V_46 . V_269 ( & V_13 -> V_52 , V_13 -> V_270 ,
V_267 , & V_46 ) ;
V_59:
V_9 = F_49 ( V_9 , V_70 ) ;
V_13 -> V_64 = false ;
F_47 ( V_13 , V_2 , false ) ;
}
}
static int F_177 ( struct V_209 * V_210 , int V_84 ,
const char * V_271 ,
bool V_272 ,
struct V_75 * V_76 ,
float V_4 ,
struct V_193 * V_194 )
{
struct V_3 * V_3 = F_131 ( V_210 ) ;
struct V_1 * V_7 = F_121 ( V_3 , V_76 , V_194 ) ;
struct V_253 * V_273 ;
#define F_178 16
char * V_228 [ F_178 ] ;
struct V_248 V_274 [ F_178 ] ;
int V_233 = 0 ;
int V_73 = - 1 ;
char V_111 [ 64 ] ;
int V_77 = V_76 ? V_76 -> V_78 : 0 ;
struct V_159 * V_139 ;
#define F_179 \
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
"L Change percent limit\n" \
"m Display context menu\n" \
"S Zoom into current Processor Socket\n" \
const char V_275 [] = F_179
L_67
L_68
L_69
L_70
L_71
L_72
L_73 ;
const char V_276 [] = F_179
L_68
L_71
L_72
L_74
L_75
L_73 ;
if ( V_7 == NULL )
return - 1 ;
F_180 () ;
F_181 ( 0 , 0 , 0 ) ;
if ( V_4 )
V_7 -> V_4 = V_4 ;
F_17 ( V_7 ) ;
V_7 -> V_260 = F_182 ( 3 ) ;
if ( V_7 -> V_260 == NULL )
goto V_91;
F_183 ( V_271 ) ;
memset ( V_228 , 0 , sizeof( V_228 ) ) ;
memset ( V_274 , 0 , sizeof( V_274 ) ) ;
F_91 (browser->hists, fmt) {
F_184 ( V_139 , V_3 ) ;
++ V_7 -> V_23 . V_277 ;
}
if ( V_5 . V_278 )
F_185 ( V_5 . V_278 ) ;
while ( 1 ) {
struct V_199 * V_199 = NULL ;
struct V_255 * V_255 = NULL ;
int V_234 = 0 ;
int V_279 = - 1 ;
V_233 = 0 ;
V_73 = F_54 ( V_7 , V_271 ) ;
if ( V_7 -> V_65 != NULL ) {
V_199 = F_125 ( V_7 ) ;
V_255 = V_7 -> V_68 -> V_255 ;
V_279 = V_7 -> V_65 -> V_265 ;
}
switch ( V_73 ) {
case V_280 :
case V_281 :
if ( V_84 == 1 )
continue;
goto V_282;
case 'a' :
if ( ! F_133 ( V_3 , V_98 ) ) {
F_53 ( & V_7 -> V_23 , V_77 * 2 ,
L_76
L_77 ) ;
continue;
}
if ( V_7 -> V_68 == NULL ||
V_7 -> V_68 -> V_98 == NULL ||
V_7 -> V_68 -> V_255 -> V_201 -> V_257 )
continue;
V_274 -> V_67 . V_255 = V_7 -> V_68 -> V_255 ;
V_274 -> V_67 . V_98 = V_7 -> V_68 -> V_98 ;
F_145 ( V_7 , V_274 ) ;
continue;
case 'P' :
F_118 ( V_7 ) ;
continue;
case 'd' :
V_274 -> V_67 . V_255 = V_255 ;
F_159 ( V_7 , V_274 ) ;
continue;
case 'V' :
V_7 -> V_97 = ! V_7 -> V_97 ;
continue;
case 't' :
V_274 -> V_199 = V_199 ;
F_151 ( V_7 , V_274 ) ;
continue;
case 'S' :
V_274 -> V_265 = V_279 ;
F_173 ( V_7 , V_274 ) ;
continue;
case '/' :
if ( F_186 ( L_78 ,
L_79
L_80 ,
V_111 , L_81 ,
V_77 * 2 ) == V_90 ) {
V_3 -> V_283 = * V_111 ? V_111 : NULL ;
F_187 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_126 ( V_76 ) ) {
V_274 -> V_199 = NULL ;
V_274 -> V_67 . V_98 = NULL ;
F_166 ( V_7 , V_274 ) ;
}
continue;
case 's' :
if ( F_126 ( V_76 ) ) {
V_73 = F_169 ( V_7 , V_274 ) ;
if ( V_73 == V_264 )
goto V_282;
}
continue;
case 'i' :
if ( V_194 -> V_284 )
F_188 ( V_194 ) ;
continue;
case 'F' :
V_5 . V_215 ^= 1 ;
continue;
case 'z' :
if ( ! F_126 ( V_76 ) ) {
struct V_226 * V_88 = V_76 -> V_81 ;
V_88 -> V_227 = ! V_88 -> V_227 ;
}
continue;
case 'L' :
if ( F_186 ( L_82 ,
L_83 ,
V_111 , L_81 ,
V_77 * 2 ) == V_90 ) {
char * V_285 ;
double V_286 = strtod ( V_111 , & V_285 ) ;
if ( V_286 < 0 || V_286 > 100 ) {
F_53 ( & V_7 -> V_23 , V_77 * 2 ,
L_84 , V_286 ) ;
continue;
}
F_176 ( V_7 , V_286 ) ;
F_16 ( V_7 ) ;
}
continue;
case V_287 :
case 'h' :
case '?' :
F_189 ( & V_7 -> V_23 ,
F_126 ( V_76 ) ? V_275 : V_276 ) ;
continue;
case V_90 :
case V_288 :
case 'm' :
break;
case V_289 :
case V_290 : {
const void * V_88 ;
if ( F_190 ( V_7 -> V_260 ) ) {
if ( V_272 )
goto V_282;
if ( V_73 == V_289 &&
F_191 ( & V_7 -> V_23 ,
L_85 ) )
goto V_282;
continue;
}
V_88 = F_192 ( V_7 -> V_260 ) ;
if ( V_88 == & V_7 -> V_3 -> V_202 ) {
F_159 ( V_7 , V_274 ) ;
} else if ( V_88 == & V_7 -> V_3 -> V_203 ) {
F_151 ( V_7 , V_274 ) ;
} else if ( V_88 == & V_7 -> V_3 -> V_205 ) {
F_173 ( V_7 , V_274 ) ;
}
continue;
}
case 'q' :
case F_148 ( 'c' ) :
goto V_282;
case 'f' :
if ( ! F_126 ( V_76 ) ) {
struct V_226 * V_88 = V_76 -> V_81 ;
F_193 ( V_88 -> V_291 ) ;
if ( V_88 -> V_291 -> V_292 ) {
V_271 = L_86 ;
V_76 -> V_78 = V_77 ;
} else {
V_271 = L_87 ;
V_76 -> V_78 = 0 ;
}
continue;
}
default:
V_271 = L_88 ;
continue;
}
if ( ! F_133 ( V_3 , V_98 ) || V_7 -> V_68 == NULL )
goto V_293;
if ( V_294 == V_295 ) {
V_273 = V_7 -> V_65 -> V_253 ;
if ( V_273 == NULL )
goto V_293;
V_233 += F_150 ( V_7 ,
& V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_273 -> V_296 . V_255 ,
V_273 -> V_296 . V_98 ) ;
if ( V_273 -> V_297 . V_98 != V_273 -> V_296 . V_98 )
V_233 += F_150 ( V_7 ,
& V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_273 -> V_297 . V_255 ,
V_273 -> V_297 . V_98 ) ;
} else {
V_233 += F_150 ( V_7 ,
& V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_7 -> V_68 -> V_255 ,
V_7 -> V_68 -> V_98 ) ;
}
V_293:
V_233 += F_158 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] , V_199 ) ;
V_233 += F_162 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] , V_255 ) ;
V_233 += F_165 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_7 -> V_68 ?
V_7 -> V_68 -> V_255 : NULL ) ;
V_233 += F_175 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_279 ) ;
if ( ! F_126 ( V_76 ) )
goto V_298;
if ( V_7 -> V_65 ) {
if ( F_133 ( V_3 , V_199 ) && V_199 ) {
V_233 += F_168 ( V_7 ,
& V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
V_199 , NULL ) ;
}
if ( F_133 ( V_3 , V_98 ) && V_7 -> V_68 -> V_98 ) {
V_233 += F_168 ( V_7 ,
& V_274 [ V_233 ] ,
& V_228 [ V_233 ] ,
NULL , V_7 -> V_68 -> V_98 ) ;
}
}
V_233 += F_168 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] , NULL , NULL ) ;
V_233 += F_170 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] ) ;
V_298:
V_233 += F_172 ( V_7 , & V_274 [ V_233 ] ,
& V_228 [ V_233 ] ) ;
do {
struct V_248 * V_249 ;
V_234 = F_144 ( V_233 , V_228 ) ;
if ( V_234 == - 1 || V_234 >= V_233 )
break;
V_249 = & V_274 [ V_234 ] ;
V_73 = V_249 -> V_258 ( V_7 , V_249 ) ;
} while ( V_73 == 1 );
if ( V_73 == V_264 )
break;
}
V_282:
F_194 ( V_7 -> V_260 ) ;
V_91:
F_123 ( V_7 ) ;
F_135 ( V_228 , F_178 ) ;
return V_73 ;
}
static void F_195 ( struct V_22 * V_7 ,
void * V_132 , int V_32 )
{
struct V_299 * V_300 = F_11 ( V_7 ,
struct V_299 , V_23 ) ;
struct V_209 * V_210 = F_37 ( V_132 , struct V_209 , V_39 ) ;
struct V_3 * V_3 = F_131 ( V_210 ) ;
bool V_144 = F_65 ( V_7 , V_32 ) ;
unsigned long V_84 = V_3 -> V_82 . V_84 [ V_207 ] ;
const char * V_211 = F_127 ( V_210 ) ;
char V_109 [ 256 ] , V_200 ;
const char * V_301 = L_8 ;
T_8 V_104 ;
F_66 ( V_7 , V_144 ? V_101 :
V_100 ) ;
if ( F_128 ( V_210 ) ) {
struct V_209 * V_218 ;
V_211 = F_196 ( V_210 ) ;
F_130 (pos, evsel) {
struct V_3 * V_219 = F_131 ( V_218 ) ;
V_84 += V_219 -> V_82 . V_84 [ V_207 ] ;
}
}
V_84 = F_132 ( V_84 , & V_200 ) ;
V_104 = F_87 ( V_109 , sizeof( V_109 ) , L_89 , V_84 ,
V_200 , V_200 == ' ' ? L_18 : L_8 , V_211 ) ;
F_68 ( V_7 , L_6 , V_109 ) ;
V_84 = V_3 -> V_82 . V_84 [ V_85 ] ;
if ( V_84 != 0 ) {
V_300 -> V_302 = true ;
if ( ! V_144 )
F_66 ( V_7 , V_303 ) ;
V_84 = F_132 ( V_84 , & V_200 ) ;
V_104 += F_87 ( V_109 , sizeof( V_109 ) , L_90 ,
V_84 , V_200 , V_200 == ' ' ? L_18 : L_8 ) ;
V_301 = V_109 ;
}
F_67 ( V_7 , V_301 , V_7 -> V_31 - V_104 ) ;
if ( V_144 )
V_300 -> V_68 = V_210 ;
}
static int F_197 ( struct V_299 * V_300 ,
int V_84 , const char * V_72 ,
struct V_75 * V_76 )
{
struct V_304 * V_291 = V_300 -> V_23 . V_305 ;
struct V_209 * V_218 ;
const char * V_74 = L_91 ;
int V_77 = V_76 ? V_76 -> V_78 : 0 ;
int V_73 ;
if ( F_56 ( & V_300 -> V_23 , V_74 ,
L_92 ) < 0 )
return - 1 ;
while ( 1 ) {
V_73 = F_57 ( & V_300 -> V_23 , V_77 ) ;
switch ( V_73 ) {
case V_79 :
V_76 -> V_80 ( V_76 -> V_81 ) ;
if ( ! V_300 -> V_306 && V_300 -> V_302 ) {
F_52 ( & V_300 -> V_23 ) ;
V_300 -> V_306 = true ;
}
continue;
case V_288 :
case V_90 :
if ( ! V_300 -> V_68 )
continue;
V_218 = V_300 -> V_68 ;
V_307:
F_198 ( V_291 , V_218 ) ;
if ( V_76 )
V_76 -> V_80 ( V_76 -> V_81 ) ;
V_73 = F_177 ( V_218 , V_84 , V_72 ,
true , V_76 ,
V_300 -> V_4 ,
V_300 -> V_194 ) ;
F_59 ( & V_300 -> V_23 , V_74 ) ;
switch ( V_73 ) {
case V_280 :
if ( V_218 -> V_39 . V_59 == & V_291 -> V_11 )
V_218 = F_199 ( V_291 ) ;
else
V_218 = F_200 ( V_218 ) ;
goto V_307;
case V_281 :
if ( V_218 -> V_39 . V_62 == & V_291 -> V_11 )
V_218 = F_201 ( V_291 ) ;
else
V_218 = F_202 ( V_218 ) ;
goto V_307;
case V_264 :
case 'q' :
case F_148 ( 'c' ) :
goto V_91;
case V_289 :
default:
continue;
}
case V_290 :
continue;
case V_289 :
if ( ! F_191 ( & V_300 -> V_23 ,
L_85 ) )
continue;
case 'q' :
case F_148 ( 'c' ) :
goto V_91;
default:
continue;
}
}
V_91:
F_62 ( & V_300 -> V_23 ) ;
return V_73 ;
}
static bool F_203 ( struct V_22 * V_7 V_45 ,
void * V_132 )
{
struct V_209 * V_210 = F_37 ( V_132 , struct V_209 , V_39 ) ;
if ( V_5 . V_308 && ! F_204 ( V_210 ) )
return true ;
return false ;
}
static int F_205 ( struct V_304 * V_291 ,
int V_17 , const char * V_72 ,
struct V_75 * V_76 ,
float V_4 ,
struct V_193 * V_194 )
{
struct V_209 * V_218 ;
struct V_299 V_300 = {
. V_23 = {
. V_11 = & V_291 -> V_11 ,
. V_78 = V_309 ,
. V_196 = V_310 ,
. V_311 = F_195 ,
. V_312 = F_203 ,
. V_17 = V_17 ,
. V_305 = V_291 ,
} ,
. V_4 = V_4 ,
. V_194 = V_194 ,
} ;
F_183 ( L_93 ) ;
F_206 (evlist, pos) {
const char * V_211 = F_127 ( V_218 ) ;
T_8 V_313 = strlen ( V_211 ) + 7 ;
if ( V_300 . V_23 . V_31 < V_313 )
V_300 . V_23 . V_31 = V_313 ;
}
return F_197 ( & V_300 , V_17 , V_72 , V_76 ) ;
}
int F_207 ( struct V_304 * V_291 , const char * V_72 ,
struct V_75 * V_76 ,
float V_4 ,
struct V_193 * V_194 )
{
int V_17 = V_291 -> V_17 ;
V_314:
if ( V_17 == 1 ) {
struct V_209 * V_57 = F_199 ( V_291 ) ;
return F_177 ( V_57 , V_17 , V_72 ,
false , V_76 , V_4 ,
V_194 ) ;
}
if ( V_5 . V_308 ) {
struct V_209 * V_218 ;
V_17 = 0 ;
F_206 (evlist, pos) {
if ( F_204 ( V_218 ) )
V_17 ++ ;
}
if ( V_17 == 1 )
goto V_314;
}
return F_205 ( V_291 , V_17 , V_72 ,
V_76 , V_4 , V_194 ) ;
}
