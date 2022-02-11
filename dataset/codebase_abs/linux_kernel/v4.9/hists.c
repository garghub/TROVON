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
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
T_2 V_26 , V_27 ;
V_26 = V_2 -> V_28 ? V_25 -> V_29 : 0 ;
V_7 -> V_30 = V_7 -> V_31 - V_26 ;
V_27 = V_7 -> V_32 - V_7 -> V_33 ;
if ( V_27 >= V_7 -> V_30 )
V_7 -> V_32 -= V_27 - V_7 -> V_30 + 1 ;
}
static void F_10 ( struct V_22 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
V_7 -> V_34 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_7 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_7 , int V_35 , int V_36 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
T_2 V_26 ;
V_26 = V_7 -> V_28 ? V_25 -> V_29 : 0 ;
F_15 ( & V_7 -> V_23 , V_35 + V_26 , V_36 ) ;
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
return V_13 -> V_37 ? F_19 ( V_13 -> V_15 ) : ' ' ;
}
static char F_21 ( const struct V_38 * V_39 )
{
return V_39 -> V_37 ? F_19 ( V_39 -> V_15 ) : ' ' ;
}
static void F_22 ( struct V_38 * V_39 , bool V_40 )
{
V_39 -> V_15 = V_40 ? V_39 -> V_37 : false ;
}
static int F_23 ( struct V_41 * V_42 )
{
int V_43 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_42 -> V_44 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_45 = F_7 ( V_9 , struct V_41 , V_8 ) ;
struct V_38 * V_46 ;
char V_47 = ' ' ;
F_25 (chain, &child->val, list) {
++ V_43 ;
V_47 = F_21 ( V_46 ) ;
if ( V_47 == '+' )
break;
}
if ( V_47 == '-' )
V_43 += F_23 ( V_45 ) ;
}
return V_43 ;
}
static int F_26 ( struct V_41 * V_42 )
{
struct V_38 * V_46 ;
char V_47 = 0 ;
int V_43 = 0 ;
F_25 (chain, &node->parent_val, list) {
if ( ! V_47 ) {
V_47 = F_21 ( V_46 ) ;
if ( V_47 == '+' )
return 1 ;
}
V_43 ++ ;
}
F_25 (chain, &node->val, list) {
if ( ! V_47 ) {
V_47 = F_21 ( V_46 ) ;
if ( V_47 == '+' )
return 1 ;
}
V_43 ++ ;
}
return V_43 ;
}
static int F_27 ( struct V_41 * V_42 V_48 )
{
return 1 ;
}
static int F_28 ( struct V_41 * V_42 )
{
struct V_38 * V_46 ;
bool V_15 = false ;
int V_43 = 0 ;
if ( V_49 . V_50 == V_51 )
return F_26 ( V_42 ) ;
else if ( V_49 . V_50 == V_52 )
return F_27 ( V_42 ) ;
F_25 (chain, &node->val, list) {
++ V_43 ;
V_15 = V_46 -> V_15 ;
}
if ( V_15 )
V_43 += F_23 ( V_42 ) ;
return V_43 ;
}
static int F_29 ( struct V_44 * V_46 )
{
struct V_8 * V_9 ;
int V_43 = 0 ;
for ( V_9 = F_4 ( V_46 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_42 = F_7 ( V_9 , struct V_41 , V_8 ) ;
V_43 += F_28 ( V_42 ) ;
}
return V_43 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_53 )
{
int V_54 = 0 ;
struct V_8 * V_42 ;
struct V_12 * V_45 ;
if ( V_13 -> V_14 )
return F_29 ( & V_13 -> V_55 ) ;
if ( V_13 -> V_56 )
return 1 ;
V_42 = F_4 ( & V_13 -> V_57 ) ;
while ( V_42 ) {
float V_58 ;
V_45 = F_7 ( V_42 , struct V_12 , V_8 ) ;
V_58 = F_31 ( V_45 ) ;
if ( ! V_45 -> V_59 && V_58 >= V_2 -> V_4 ) {
V_54 ++ ;
if ( V_53 && V_45 -> V_15 )
V_54 += F_30 ( V_2 , V_45 , true ) ;
}
V_42 = F_24 ( V_42 ) ;
}
return V_54 ;
}
static bool F_32 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return false ;
if ( ! V_13 -> V_37 )
return false ;
V_13 -> V_15 = ! V_13 -> V_15 ;
return true ;
}
static bool F_33 ( struct V_38 * V_39 )
{
if ( ! V_39 )
return false ;
if ( ! V_39 -> V_37 )
return false ;
V_39 -> V_15 = ! V_39 -> V_15 ;
return true ;
}
static void F_34 ( struct V_41 * V_42 )
{
struct V_8 * V_9 = F_4 ( & V_42 -> V_44 ) ;
for ( V_9 = F_4 ( & V_42 -> V_44 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_45 = F_7 ( V_9 , struct V_41 , V_8 ) ;
struct V_38 * V_46 ;
bool V_60 = true ;
F_25 (chain, &child->val, list) {
if ( V_60 ) {
V_60 = false ;
V_46 -> V_37 = V_46 -> V_61 . V_62 != & V_45 -> V_63 ||
! F_35 ( & V_45 -> V_44 ) ;
} else
V_46 -> V_37 = V_46 -> V_61 . V_62 == & V_45 -> V_63 &&
! F_35 ( & V_45 -> V_44 ) ;
}
F_34 ( V_45 ) ;
}
}
static void F_36 ( struct V_41 * V_42 ,
bool V_64 )
{
struct V_38 * V_46 ;
V_46 = F_37 ( V_42 -> V_63 . V_62 , struct V_38 , V_61 ) ;
V_46 -> V_37 = V_64 ;
if ( ! F_38 ( & V_42 -> V_63 ) ) {
V_46 = F_37 ( V_42 -> V_63 . V_65 , struct V_38 , V_61 ) ;
V_46 -> V_37 = ! F_35 ( & V_42 -> V_44 ) ;
}
F_34 ( V_42 ) ;
}
static void F_39 ( struct V_44 * V_66 )
{
struct V_8 * V_9 = F_4 ( V_66 ) ;
bool V_64 = V_9 && F_24 ( V_9 ) ;
for ( V_9 = F_4 ( V_66 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_42 = F_7 ( V_9 , struct V_41 , V_8 ) ;
F_36 ( V_42 , V_64 ) ;
if ( V_49 . V_50 == V_51 ||
V_49 . V_50 == V_52 )
F_40 ( V_42 ) ;
}
}
static void F_41 ( struct V_12 * V_13 )
{
if ( V_13 -> V_67 )
return;
if ( V_13 -> V_14 ) {
V_13 -> V_37 = ! F_35 ( & V_13 -> V_55 ) ;
F_39 ( & V_13 -> V_55 ) ;
} else {
V_13 -> V_37 = ! F_35 ( & V_13 -> V_57 ) ;
}
V_13 -> V_67 = true ;
}
static bool F_42 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_68 ;
struct V_69 * V_70 = V_7 -> V_71 ;
struct V_38 * V_39 = F_11 ( V_70 , struct V_38 , V_70 ) ;
bool V_37 ;
if ( ! V_13 || ! V_70 )
return false ;
if ( V_70 == & V_13 -> V_70 )
V_37 = F_32 ( V_13 ) ;
else
V_37 = F_33 ( V_39 ) ;
if ( V_37 ) {
int V_72 = 0 ;
F_41 ( V_13 ) ;
V_7 -> V_23 . V_17 -= V_13 -> V_16 ;
if ( V_13 -> V_14 )
V_7 -> V_21 -= V_13 -> V_16 ;
else
V_7 -> V_19 -= V_13 -> V_16 ;
if ( V_5 . V_18 )
V_72 = F_30 ( V_7 , V_13 , true ) ;
if ( V_13 -> V_15 ) {
if ( V_13 -> V_14 )
V_13 -> V_16 = F_29 ( & V_13 -> V_55 ) ;
else
V_13 -> V_16 = F_30 ( V_7 , V_13 , false ) ;
if ( V_5 . V_18 )
V_7 -> V_23 . V_17 += V_72 - V_13 -> V_16 ;
if ( ! V_13 -> V_14 && V_13 -> V_16 == 0 ) {
V_13 -> V_56 = true ;
V_13 -> V_16 = 1 ;
}
} else {
if ( V_5 . V_18 )
V_7 -> V_23 . V_17 -= V_72 - V_13 -> V_16 ;
if ( V_13 -> V_56 )
V_13 -> V_56 = false ;
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
static int F_43 ( struct V_41 * V_42 , bool V_40 )
{
int V_43 = 0 ;
struct V_8 * V_9 ;
for ( V_9 = F_4 ( & V_42 -> V_44 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_45 = F_7 ( V_9 , struct V_41 , V_8 ) ;
struct V_38 * V_46 ;
bool V_37 = false ;
F_25 (chain, &child->val, list) {
++ V_43 ;
F_22 ( V_46 , V_40 ) ;
V_37 = V_46 -> V_37 ;
}
if ( V_37 )
V_43 += F_43 ( V_45 , V_40 ) ;
}
return V_43 ;
}
static int F_44 ( struct V_41 * V_42 , bool V_40 )
{
struct V_38 * V_46 ;
bool V_37 = false ;
int V_43 = 0 ;
F_25 (chain, &node->val, list) {
++ V_43 ;
F_22 ( V_46 , V_40 ) ;
V_37 = V_46 -> V_37 ;
}
if ( V_37 )
V_43 += F_43 ( V_42 , V_40 ) ;
return V_43 ;
}
static int F_45 ( struct V_44 * V_46 , bool V_40 )
{
struct V_8 * V_9 ;
int V_43 = 0 ;
for ( V_9 = F_4 ( V_46 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
struct V_41 * V_42 = F_7 ( V_9 , struct V_41 , V_8 ) ;
V_43 += F_44 ( V_42 , V_40 ) ;
}
return V_43 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_12 * V_13 ,
bool V_40 V_48 )
{
float V_58 ;
struct V_8 * V_9 ;
struct V_12 * V_45 ;
int V_43 = 0 ;
for ( V_9 = F_4 ( & V_13 -> V_57 ) ; V_9 ; V_9 = F_24 ( V_9 ) ) {
V_45 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_58 = F_31 ( V_45 ) ;
if ( ! V_45 -> V_59 && V_58 >= V_2 -> V_4 )
V_43 ++ ;
}
return V_43 ;
}
static void F_47 ( struct V_12 * V_13 ,
struct V_1 * V_2 , bool V_40 )
{
F_41 ( V_13 ) ;
V_13 -> V_15 = V_40 ? V_13 -> V_37 : false ;
if ( V_13 -> V_37 ) {
int V_43 ;
if ( V_13 -> V_14 )
V_43 = F_45 ( & V_13 -> V_55 , V_40 ) ;
else
V_43 = F_46 ( V_2 , V_13 , V_40 ) ;
V_13 -> V_16 = V_40 ? V_43 : 0 ;
} else
V_13 -> V_16 = 0 ;
}
static void
F_48 ( struct V_1 * V_7 , bool V_40 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
double V_58 ;
V_9 = F_4 ( & V_7 -> V_3 -> V_11 ) ;
while ( V_9 ) {
V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_9 = F_49 ( V_9 , V_73 ) ;
F_47 ( V_13 , V_7 , V_40 ) ;
V_58 = F_31 ( V_13 ) ;
if ( V_13 -> V_59 || V_58 < V_7 -> V_4 )
continue;
if ( ! V_13 -> V_74 || V_40 )
V_7 -> V_19 ++ ;
if ( V_13 -> V_14 )
V_7 -> V_21 += V_13 -> V_16 ;
else if ( V_40 && ! F_50 ( V_13 , V_7 -> V_4 ) ) {
V_7 -> V_19 ++ ;
V_13 -> V_56 = true ;
V_13 -> V_16 = 1 ;
} else
V_13 -> V_56 = false ;
}
}
static void F_51 ( struct V_1 * V_7 , bool V_40 )
{
V_7 -> V_19 = 0 ;
V_7 -> V_21 = 0 ;
F_48 ( V_7 , V_40 ) ;
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
static int F_54 ( struct V_1 * V_7 , char * V_75 , T_3 V_76 )
{
return V_7 -> V_77 ? V_7 -> V_77 ( V_7 , V_75 , V_76 ) : 0 ;
}
int F_55 ( struct V_1 * V_7 , const char * V_78 )
{
int V_79 ;
char V_77 [ 160 ] ;
struct V_80 * V_81 = V_7 -> V_81 ;
int V_82 = V_81 ? V_81 -> V_83 : 0 ;
V_7 -> V_23 . V_11 = & V_7 -> V_3 -> V_11 ;
V_7 -> V_23 . V_17 = F_8 ( V_7 ) ;
F_54 ( V_7 , V_77 , sizeof( V_77 ) ) ;
if ( F_56 ( & V_7 -> V_23 , V_77 , L_6 , V_78 ) < 0 )
return - 1 ;
while ( 1 ) {
V_79 = F_57 ( & V_7 -> V_23 , V_82 ) ;
switch ( V_79 ) {
case V_84 : {
T_4 V_17 ;
V_81 -> V_85 ( V_81 -> V_86 ) ;
if ( F_1 ( V_7 ) ||
V_5 . V_18 )
F_17 ( V_7 ) ;
V_17 = F_8 ( V_7 ) ;
F_58 ( & V_7 -> V_23 , V_17 ) ;
if ( V_7 -> V_3 -> V_87 . V_88 !=
V_7 -> V_3 -> V_87 . V_89 [ V_90 ] ) {
V_7 -> V_3 -> V_87 . V_88 =
V_7 -> V_3 -> V_87 . V_89 [ V_90 ] ;
F_52 ( & V_7 -> V_23 ) ;
}
F_54 ( V_7 , V_77 , sizeof( V_77 ) ) ;
F_59 ( & V_7 -> V_23 , V_77 ) ;
continue;
}
case 'D' : {
static int V_91 ;
struct V_12 * V_92 = F_7 ( V_7 -> V_23 . V_93 ,
struct V_12 , V_8 ) ;
F_60 () ;
F_61 ( L_7 ,
V_91 ++ , V_7 -> V_23 . V_17 ,
V_7 -> V_3 -> V_17 ,
V_7 -> V_23 . V_30 ,
V_7 -> V_23 . V_32 ,
V_7 -> V_23 . V_33 ,
V_92 -> V_94 , V_92 -> V_16 ) ;
}
break;
case 'C' :
F_51 ( V_7 , false ) ;
break;
case 'E' :
F_51 ( V_7 , true ) ;
break;
case 'H' :
V_7 -> V_28 = ! V_7 -> V_28 ;
F_9 ( V_7 ) ;
break;
case V_95 :
if ( F_42 ( V_7 ) )
break;
default:
goto V_96;
}
}
V_96:
F_62 ( & V_7 -> V_23 ) ;
return V_79 ;
}
static void F_63 ( struct V_1 * V_7 ,
struct V_38 * V_46 ,
const char * V_97 , int V_98 ,
unsigned short V_35 ,
struct V_99 * V_86 )
{
int V_100 , V_34 ;
char V_47 = F_21 ( V_46 ) ;
bool V_101 = V_7 -> V_102 && V_46 -> V_70 . V_103 && F_64 ( V_46 -> V_70 . V_103 ) -> V_104 ;
V_100 = V_105 ;
V_34 = V_7 -> V_23 . V_34 - ( V_98 + 2 ) ;
if ( F_65 ( & V_7 -> V_23 , V_35 ) ) {
V_7 -> V_71 = & V_46 -> V_70 ;
V_100 = V_106 ;
V_86 -> V_107 = true ;
}
F_66 ( & V_7 -> V_23 , V_100 ) ;
F_14 ( V_7 , V_35 , 0 ) ;
F_67 ( & V_7 -> V_23 , L_8 , V_98 ) ;
F_68 ( & V_7 -> V_23 , L_9 , V_47 ) ;
F_69 ( & V_7 -> V_23 , V_101 ? V_108 : ' ' ) ;
F_67 ( & V_7 -> V_23 , V_97 , V_34 ) ;
}
static void F_70 ( struct V_1 * V_23 V_48 ,
struct V_38 * V_46 ,
const char * V_97 , int V_98 ,
unsigned short V_35 V_48 ,
struct V_99 * V_86 )
{
char V_47 = F_21 ( V_46 ) ;
V_86 -> V_109 += fprintf ( V_86 -> V_110 , L_10 , V_98 , L_8 ,
V_47 , V_97 ) ;
}
static bool F_71 ( struct V_1 * V_7 ,
unsigned short V_35 )
{
return V_7 -> V_23 . V_30 == V_35 ;
}
static bool F_72 ( struct V_1 * V_7 V_48 ,
unsigned short V_35 V_48 )
{
return false ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_41 * V_42 ,
struct V_38 * V_46 ,
unsigned short V_35 , T_4 V_111 ,
bool V_112 , int V_98 ,
T_5 V_113 ,
struct V_99 * V_86 )
{
char V_75 [ 1024 ] , * V_114 ;
const char * V_97 ;
if ( V_86 -> V_94 != 0 ) {
V_86 -> V_94 -- ;
return 0 ;
}
V_114 = NULL ;
V_97 = F_74 ( V_46 , V_75 , sizeof( V_75 ) ,
V_7 -> V_102 ) ;
if ( V_112 ) {
char V_115 [ 64 ] ;
F_75 ( V_42 , V_115 , sizeof( V_115 ) ,
V_111 ) ;
if ( F_76 ( & V_114 , L_11 , V_115 , V_97 ) < 0 )
V_97 = L_12 ;
else
V_97 = V_114 ;
}
V_113 ( V_7 , V_46 , V_97 , V_98 , V_35 , V_86 ) ;
free ( V_114 ) ;
return 1 ;
}
static bool F_77 ( struct V_8 * V_42 , T_4 V_116 )
{
struct V_41 * V_45 ;
if ( V_42 == NULL )
return false ;
if ( F_24 ( V_42 ) )
return true ;
V_45 = F_7 ( V_42 , struct V_41 , V_8 ) ;
return F_78 ( V_45 ) != V_116 ;
}
static int F_79 ( struct V_1 * V_7 ,
struct V_44 * V_66 ,
unsigned short V_35 , T_4 V_111 ,
T_4 V_116 ,
T_5 V_113 ,
struct V_99 * V_86 ,
T_6 V_117 )
{
struct V_8 * V_42 ;
int V_118 = V_35 , V_98 = V_119 ;
bool V_112 ;
V_42 = F_4 ( V_66 ) ;
V_112 = F_77 ( V_42 , V_116 ) ;
while ( V_42 ) {
struct V_41 * V_45 = F_7 ( V_42 , struct V_41 , V_8 ) ;
struct V_8 * V_62 = F_24 ( V_42 ) ;
struct V_38 * V_46 ;
char V_47 = ' ' ;
int V_60 = true ;
int V_120 = 0 ;
F_25 (chain, &child->parent_val, list) {
bool V_121 = V_60 ;
if ( V_60 )
V_60 = false ;
else if ( V_112 )
V_120 = V_119 ;
V_47 = F_21 ( V_46 ) ;
V_35 += F_73 ( V_7 , V_45 ,
V_46 , V_35 , V_111 ,
V_121 && V_112 ,
V_98 + V_120 ,
V_113 , V_86 ) ;
if ( V_117 ( V_7 , V_35 ) )
goto V_96;
if ( V_47 == '+' )
goto V_62;
}
F_25 (chain, &child->val, list) {
bool V_121 = V_60 ;
if ( V_60 )
V_60 = false ;
else if ( V_112 )
V_120 = V_119 ;
V_47 = F_21 ( V_46 ) ;
V_35 += F_73 ( V_7 , V_45 ,
V_46 , V_35 , V_111 ,
V_121 && V_112 ,
V_98 + V_120 ,
V_113 , V_86 ) ;
if ( V_117 ( V_7 , V_35 ) )
goto V_96;
if ( V_47 == '+' )
break;
}
V_62:
if ( V_117 ( V_7 , V_35 ) )
break;
V_42 = V_62 ;
}
V_96:
return V_35 - V_118 ;
}
static char * F_80 ( struct V_1 * V_7 ,
struct V_38 * V_46 ,
char * V_122 , char * V_123 )
{
char V_75 [ 1024 ] ;
const char * V_97 ;
char * V_124 ;
V_97 = F_74 ( V_46 , V_75 , sizeof( V_75 ) ,
V_7 -> V_102 ) ;
if ( V_123 ) {
if ( F_76 ( & V_124 , L_13 , V_123 ,
V_5 . V_125 ? : L_14 , V_97 ) < 0 )
V_124 = NULL ;
} else {
if ( V_122 ) {
if ( F_76 ( & V_124 , L_11 , V_122 , V_97 ) < 0 )
V_124 = NULL ;
} else {
if ( F_76 ( & V_124 , L_6 , V_97 ) < 0 )
V_124 = NULL ;
}
}
return V_124 ;
}
static int F_81 ( struct V_1 * V_7 ,
struct V_44 * V_66 ,
unsigned short V_35 , T_4 V_111 ,
T_4 V_116 ,
T_5 V_113 ,
struct V_99 * V_86 ,
T_6 V_117 )
{
struct V_8 * V_42 ;
int V_118 = V_35 , V_98 = V_119 ;
bool V_112 ;
V_42 = F_4 ( V_66 ) ;
V_112 = F_77 ( V_42 , V_116 ) ;
while ( V_42 ) {
struct V_41 * V_45 = F_7 ( V_42 , struct V_41 , V_8 ) ;
struct V_8 * V_62 = F_24 ( V_42 ) ;
struct V_38 * V_46 , * V_126 = NULL ;
int V_60 = true ;
char * V_122 = NULL , * V_127 = NULL ;
char * V_128 = NULL , * V_129 = NULL ;
if ( V_86 -> V_94 != 0 ) {
V_86 -> V_94 -- ;
goto V_62;
}
if ( V_112 ) {
char V_115 [ 64 ] ;
F_75 ( V_45 , V_115 , sizeof( V_115 ) , V_111 ) ;
if ( F_76 ( & V_122 , L_6 , V_115 ) < 0 ) {
V_122 = ( char * ) L_15 ;
goto V_130;
}
V_127 = V_122 ;
}
F_25 (chain, &child->parent_val, list) {
V_128 = F_80 ( V_7 ,
V_46 , V_122 , V_128 ) ;
if ( V_60 ) {
V_60 = false ;
V_126 = V_46 ;
}
if ( V_128 == NULL ) {
V_128 = ( char * ) L_12 ;
goto V_130;
}
V_129 = V_128 ;
}
F_25 (chain, &child->val, list) {
V_128 = F_80 ( V_7 ,
V_46 , V_122 , V_128 ) ;
if ( V_60 ) {
V_60 = false ;
V_126 = V_46 ;
}
if ( V_128 == NULL ) {
V_128 = ( char * ) L_12 ;
goto V_130;
}
V_129 = V_128 ;
}
V_130:
V_113 ( V_7 , V_126 , V_128 , V_98 , V_35 ++ , V_86 ) ;
free ( V_127 ) ;
free ( V_129 ) ;
V_62:
if ( V_117 ( V_7 , V_35 ) )
break;
V_42 = V_62 ;
}
return V_35 - V_118 ;
}
static int F_82 ( struct V_1 * V_7 ,
struct V_44 * V_66 , int V_131 ,
unsigned short V_35 , T_4 V_111 ,
T_4 V_116 ,
T_5 V_113 ,
struct V_99 * V_86 ,
T_6 V_117 )
{
struct V_8 * V_42 ;
int V_118 = V_35 , V_98 = V_131 * V_119 ;
bool V_112 ;
T_4 V_132 = V_111 ;
if ( V_49 . V_50 == V_133 )
V_132 = V_116 ;
V_42 = F_4 ( V_66 ) ;
V_112 = F_77 ( V_42 , V_116 ) ;
while ( V_42 ) {
struct V_41 * V_45 = F_7 ( V_42 , struct V_41 , V_8 ) ;
struct V_8 * V_62 = F_24 ( V_42 ) ;
struct V_38 * V_46 ;
char V_47 = ' ' ;
int V_60 = true ;
int V_120 = 0 ;
F_25 (chain, &child->val, list) {
bool V_121 = V_60 ;
if ( V_60 )
V_60 = false ;
else if ( V_112 )
V_120 = V_119 ;
V_47 = F_21 ( V_46 ) ;
V_35 += F_73 ( V_7 , V_45 ,
V_46 , V_35 , V_132 ,
V_121 && V_112 ,
V_98 + V_120 ,
V_113 , V_86 ) ;
if ( V_117 ( V_7 , V_35 ) )
goto V_96;
if ( V_47 == '+' )
break;
}
if ( V_47 == '-' ) {
const int V_134 = V_131 + ( V_120 ? 2 : 1 ) ;
V_35 += F_82 ( V_7 , & V_45 -> V_44 ,
V_134 , V_35 , V_111 ,
V_45 -> V_135 ,
V_113 , V_86 , V_117 ) ;
}
if ( V_117 ( V_7 , V_35 ) )
break;
V_42 = V_62 ;
}
V_96:
return V_35 - V_118 ;
}
static int F_83 ( struct V_1 * V_7 ,
struct V_12 * V_136 , int V_131 ,
unsigned short V_35 ,
T_5 V_113 ,
struct V_99 * V_86 ,
T_6 V_117 )
{
T_4 V_111 = F_84 ( V_136 -> V_3 ) ;
T_4 V_116 ;
int V_109 ;
if ( V_5 . V_137 )
V_116 = V_136 -> V_138 -> V_139 ;
else
V_116 = V_136 -> V_140 . V_139 ;
if ( V_49 . V_50 == V_51 ) {
V_109 = F_79 ( V_7 ,
& V_136 -> V_55 , V_35 ,
V_111 , V_116 , V_113 , V_86 ,
V_117 ) ;
} else if ( V_49 . V_50 == V_52 ) {
V_109 = F_81 ( V_7 ,
& V_136 -> V_55 , V_35 ,
V_111 , V_116 , V_113 , V_86 ,
V_117 ) ;
} else {
V_109 = F_82 ( V_7 ,
& V_136 -> V_55 , V_131 , V_35 ,
V_111 , V_116 , V_113 , V_86 ,
V_117 ) ;
}
if ( V_86 -> V_107 )
V_7 -> V_68 = V_136 ;
return V_109 ;
}
int F_85 ( struct V_141 * V_142 , const char * V_143 , ... )
{
struct V_144 * V_86 = V_142 -> V_145 ;
int V_146 , V_147 ;
T_7 args ;
double V_58 ;
va_start ( args , V_143 ) ;
V_147 = va_arg ( args , int ) ;
V_58 = va_arg ( args , double ) ;
va_end ( args ) ;
F_86 ( V_86 -> V_23 , V_58 , V_86 -> V_148 ) ;
V_146 = F_87 ( V_142 -> V_115 , V_142 -> V_76 , V_143 , V_147 , V_58 ) ;
F_68 ( V_86 -> V_23 , L_6 , V_142 -> V_115 ) ;
return V_146 ;
}
void F_88 ( void )
{
V_149 [ V_150 ] . V_100 =
V_151 ;
V_149 [ V_152 ] . V_100 =
V_153 ;
V_149 [ V_154 ] . V_100 =
V_155 ;
V_149 [ V_156 ] . V_100 =
V_157 ;
V_149 [ V_158 ] . V_100 =
V_159 ;
V_149 [ V_160 ] . V_100 =
V_161 ;
}
static int F_89 ( struct V_1 * V_7 ,
struct V_12 * V_136 ,
unsigned short V_35 )
{
int V_109 = 0 ;
int V_34 = V_7 -> V_23 . V_34 ;
char V_47 = ' ' ;
bool V_148 = F_65 ( & V_7 -> V_23 , V_35 ) ;
T_8 V_94 = V_136 -> V_94 ;
bool V_60 = true ;
struct V_162 * V_143 ;
if ( V_148 ) {
V_7 -> V_68 = V_136 ;
V_7 -> V_71 = & V_136 -> V_70 ;
}
if ( V_5 . V_163 ) {
F_41 ( V_136 ) ;
V_47 = F_20 ( V_136 ) ;
}
if ( V_94 == 0 ) {
struct V_144 V_86 = {
. V_23 = & V_7 -> V_23 ,
. V_47 = V_47 ,
. V_148 = V_148 ,
} ;
int V_36 = 0 ;
F_14 ( V_7 , V_35 , 0 ) ;
F_90 (browser->hists, fmt) {
char V_164 [ 2048 ] ;
struct V_141 V_142 = {
. V_115 = V_164 ,
. V_76 = sizeof( V_164 ) ,
. V_145 = & V_86 ,
} ;
if ( F_91 ( V_143 , V_136 -> V_3 ) ||
V_36 ++ < V_7 -> V_23 . V_165 )
continue;
if ( V_148 && V_7 -> V_23 . V_166 ) {
F_66 ( & V_7 -> V_23 ,
V_106 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_105 ) ;
}
if ( V_60 ) {
if ( V_5 . V_163 ) {
F_68 ( & V_7 -> V_23 , L_16 , V_47 ) ;
V_34 -= 2 ;
}
V_60 = false ;
} else {
F_68 ( & V_7 -> V_23 , L_17 ) ;
V_34 -= 2 ;
}
if ( V_143 -> V_100 ) {
int V_146 = V_143 -> V_100 ( V_143 , & V_142 , V_136 ) ;
F_92 ( V_136 , & V_142 , V_143 , V_146 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_164 + V_146 ) ;
} else {
F_92 ( V_136 , & V_142 , V_143 , V_143 -> V_136 ( V_143 , & V_142 , V_136 ) ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_164 ) ;
}
V_34 -= V_142 . V_115 - V_164 ;
}
if ( ! V_7 -> V_23 . V_166 )
V_34 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_34 ) ;
++ V_35 ;
++ V_109 ;
} else
-- V_94 ;
if ( V_47 == '-' && V_35 != V_7 -> V_23 . V_30 ) {
struct V_99 V_86 = {
. V_94 = V_94 ,
. V_107 = V_148 ,
} ;
V_109 += F_83 ( V_7 , V_136 , 1 , V_35 ,
F_63 , & V_86 ,
F_71 ) ;
}
return V_109 ;
}
static int F_93 ( struct V_1 * V_7 ,
struct V_12 * V_136 ,
unsigned short V_35 ,
int V_131 )
{
int V_109 = 0 ;
int V_34 = V_7 -> V_23 . V_34 ;
char V_47 = ' ' ;
bool V_148 = F_65 ( & V_7 -> V_23 , V_35 ) ;
T_8 V_94 = V_136 -> V_94 ;
bool V_60 = true ;
struct V_162 * V_143 ;
struct V_167 * V_168 ;
struct V_144 V_86 = {
. V_23 = & V_7 -> V_23 ,
. V_148 = V_148 ,
} ;
int V_36 = 0 ;
int V_169 = ( V_136 -> V_3 -> V_170 - 2 ) * V_171 ;
if ( V_148 ) {
V_7 -> V_68 = V_136 ;
V_7 -> V_71 = & V_136 -> V_70 ;
}
F_41 ( V_136 ) ;
V_47 = F_20 ( V_136 ) ;
V_86 . V_47 = V_47 ;
if ( V_136 -> V_14 && V_94 ) {
V_94 -- ;
goto V_172;
}
F_14 ( V_7 , V_35 , 0 ) ;
if ( V_148 && V_7 -> V_23 . V_166 )
F_66 ( & V_7 -> V_23 , V_106 ) ;
else
F_66 ( & V_7 -> V_23 , V_105 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_131 * V_171 ) ;
V_34 -= V_131 * V_171 ;
V_168 = F_94 ( & V_136 -> V_3 -> V_173 ,
struct V_167 , V_61 ) ;
F_95 (&fmt_node->hpp, fmt) {
char V_164 [ 2048 ] ;
struct V_141 V_142 = {
. V_115 = V_164 ,
. V_76 = sizeof( V_164 ) ,
. V_145 = & V_86 ,
} ;
if ( F_91 ( V_143 , V_136 -> V_3 ) ||
V_36 ++ < V_7 -> V_23 . V_165 )
continue;
if ( V_148 && V_7 -> V_23 . V_166 ) {
F_66 ( & V_7 -> V_23 ,
V_106 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_105 ) ;
}
if ( V_60 ) {
F_68 ( & V_7 -> V_23 , L_16 , V_47 ) ;
V_34 -= 2 ;
V_60 = false ;
} else {
F_68 ( & V_7 -> V_23 , L_17 ) ;
V_34 -= 2 ;
}
if ( V_143 -> V_100 ) {
int V_146 = V_143 -> V_100 ( V_143 , & V_142 , V_136 ) ;
F_92 ( V_136 , & V_142 , V_143 , V_146 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_164 + V_146 ) ;
} else {
int V_146 = V_143 -> V_136 ( V_143 , & V_142 , V_136 ) ;
F_92 ( V_136 , & V_142 , V_143 , V_146 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_164 ) ;
}
V_34 -= V_142 . V_115 - V_164 ;
}
if ( ! V_60 ) {
F_67 ( & V_7 -> V_23 , L_18 , V_169 ) ;
V_34 -= V_169 ;
}
if ( V_36 >= V_7 -> V_23 . V_165 ) {
char V_164 [ 2048 ] ;
struct V_141 V_142 = {
. V_115 = V_164 ,
. V_76 = sizeof( V_164 ) ,
. V_145 = & V_86 ,
} ;
if ( V_148 && V_7 -> V_23 . V_166 ) {
F_66 ( & V_7 -> V_23 ,
V_106 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_105 ) ;
}
F_95 (entry->hpp_list, fmt) {
if ( V_60 ) {
F_68 ( & V_7 -> V_23 , L_16 , V_47 ) ;
V_60 = false ;
} else {
F_67 ( & V_7 -> V_23 , L_18 , 2 ) ;
}
V_34 -= 2 ;
if ( V_143 -> V_100 ) {
V_34 -= V_143 -> V_100 ( V_143 , & V_142 , V_136 ) ;
} else {
int V_174 = 0 ;
V_34 -= V_143 -> V_136 ( V_143 , & V_142 , V_136 ) ;
F_68 ( & V_7 -> V_23 , L_6 , F_96 ( V_164 ) ) ;
while ( isspace ( V_164 [ V_174 ++ ] ) )
V_34 ++ ;
}
}
}
if ( ! V_7 -> V_23 . V_166 )
V_34 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_34 ) ;
++ V_35 ;
++ V_109 ;
V_172:
if ( V_136 -> V_14 && V_47 == '-' && V_35 != V_7 -> V_23 . V_30 ) {
struct V_99 V_175 = {
. V_94 = V_94 ,
} ;
V_109 += F_83 ( V_7 , V_136 ,
V_131 + 1 , V_35 ,
F_63 , & V_175 ,
F_71 ) ;
}
return V_109 ;
}
static int F_97 ( struct V_1 * V_7 ,
unsigned short V_35 , int V_131 )
{
int V_34 = V_7 -> V_23 . V_34 ;
bool V_148 = F_65 ( & V_7 -> V_23 , V_35 ) ;
bool V_60 = true ;
int V_36 = 0 ;
int V_146 ;
struct V_162 * V_143 ;
struct V_167 * V_168 ;
int V_176 = V_7 -> V_3 -> V_170 - 2 ;
if ( V_148 ) {
V_7 -> V_68 = NULL ;
V_7 -> V_71 = NULL ;
}
F_14 ( V_7 , V_35 , 0 ) ;
if ( V_148 && V_7 -> V_23 . V_166 )
F_66 ( & V_7 -> V_23 , V_106 ) ;
else
F_66 ( & V_7 -> V_23 , V_105 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_131 * V_171 ) ;
V_34 -= V_131 * V_171 ;
V_168 = F_94 ( & V_7 -> V_3 -> V_173 ,
struct V_167 , V_61 ) ;
F_95 (&fmt_node->hpp, fmt) {
if ( F_91 ( V_143 , V_7 -> V_3 ) ||
V_36 ++ < V_7 -> V_23 . V_165 )
continue;
V_146 = V_143 -> V_34 ( V_143 , NULL , V_7 -> V_3 ) ;
if ( V_60 ) {
V_60 = false ;
V_146 ++ ;
} else {
V_146 += 2 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_146 ) ;
V_34 -= V_146 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_176 * V_171 ) ;
V_34 -= V_176 * V_171 ;
if ( V_36 >= V_7 -> V_23 . V_165 ) {
char V_115 [ 32 ] ;
V_146 = snprintf ( V_115 , sizeof( V_115 ) , L_19 , V_7 -> V_4 ) ;
F_68 ( & V_7 -> V_23 , L_20 , V_115 ) ;
V_34 -= V_146 + 2 ;
}
if ( ! V_7 -> V_23 . V_166 )
V_34 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_34 ) ;
return 1 ;
}
static int F_98 ( struct V_141 * V_142 , int V_177 )
{
F_99 ( V_142 , V_177 ) ;
return V_142 -> V_76 <= 0 ;
}
static int
F_100 ( struct V_1 * V_7 , char * V_115 ,
T_3 V_76 , int line )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_141 V_178 = {
. V_115 = V_115 ,
. V_76 = V_76 ,
} ;
struct V_162 * V_143 ;
T_3 V_146 = 0 ;
int V_36 = 0 ;
int V_179 = 0 ;
if ( V_5 . V_163 ) {
V_146 = F_87 ( V_115 , V_76 , L_17 ) ;
if ( F_98 ( & V_178 , V_146 ) )
return V_146 ;
}
F_90 (browser->hists, fmt) {
if ( F_91 ( V_143 , V_3 ) || V_36 ++ < V_7 -> V_23 . V_165 )
continue;
V_146 = V_143 -> V_180 ( V_143 , & V_178 , V_3 , line , & V_179 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
if ( V_179 )
continue;
V_146 = F_87 ( V_178 . V_115 , V_178 . V_76 , L_17 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
}
return V_146 ;
}
static int F_101 ( struct V_1 * V_7 , char * V_115 , T_3 V_76 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_141 V_178 = {
. V_115 = V_115 ,
. V_76 = V_76 ,
} ;
struct V_162 * V_143 ;
struct V_167 * V_168 ;
T_3 V_146 = 0 ;
int V_36 = 0 ;
int V_176 = V_3 -> V_170 - 2 ;
bool V_181 , V_182 ;
V_146 = F_87 ( V_115 , V_76 , L_17 ) ;
if ( F_98 ( & V_178 , V_146 ) )
return V_146 ;
V_181 = true ;
V_168 = F_94 ( & V_3 -> V_173 ,
struct V_167 , V_61 ) ;
F_95 (&fmt_node->hpp, fmt) {
if ( V_36 ++ < V_7 -> V_23 . V_165 )
continue;
V_146 = V_143 -> V_180 ( V_143 , & V_178 , V_3 , 0 , NULL ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
V_146 = F_87 ( V_178 . V_115 , V_178 . V_76 , L_17 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
V_181 = false ;
}
if ( ! V_181 ) {
V_146 = F_87 ( V_178 . V_115 , V_178 . V_76 , L_21 ,
V_176 * V_171 , L_18 ) ;
if ( F_98 ( & V_178 , V_146 ) )
return V_146 ;
}
V_181 = true ;
F_102 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_181 ) {
V_146 = F_87 ( V_178 . V_115 , V_178 . V_76 , L_22 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
}
V_181 = false ;
V_182 = true ;
F_95 (&fmt_node->hpp, fmt) {
char * V_183 ;
if ( F_91 ( V_143 , V_3 ) )
continue;
if ( ! V_182 ) {
V_146 = F_87 ( V_178 . V_115 , V_178 . V_76 , L_23 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
}
V_182 = false ;
V_146 = V_143 -> V_180 ( V_143 , & V_178 , V_3 , 0 , NULL ) ;
V_178 . V_115 [ V_146 ] = '\0' ;
V_183 = F_103 ( V_178 . V_115 ) ;
V_146 = strlen ( V_183 ) ;
if ( V_183 != V_178 . V_115 )
memmove ( V_178 . V_115 , V_183 , V_146 + 1 ) ;
if ( F_98 ( & V_178 , V_146 ) )
break;
}
}
return V_146 ;
}
static void F_104 ( struct V_1 * V_7 )
{
char V_184 [ 1024 ] ;
F_101 ( V_7 , V_184 ,
sizeof( V_184 ) ) ;
F_15 ( & V_7 -> V_23 , 0 , 0 ) ;
F_66 ( & V_7 -> V_23 , V_185 ) ;
F_67 ( & V_7 -> V_23 , V_184 , V_7 -> V_23 . V_34 + 1 ) ;
}
static void F_105 ( struct V_1 * V_7 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
int line ;
for ( line = 0 ; line < V_25 -> V_29 ; line ++ ) {
char V_184 [ 1024 ] ;
F_100 ( V_7 , V_184 ,
sizeof( V_184 ) , line ) ;
F_15 ( & V_7 -> V_23 , line , 0 ) ;
F_66 ( & V_7 -> V_23 , V_185 ) ;
F_67 ( & V_7 -> V_23 , V_184 , V_7 -> V_23 . V_34 + 1 ) ;
}
}
static void F_106 ( struct V_1 * V_7 )
{
if ( V_5 . V_18 )
F_104 ( V_7 ) ;
else
F_105 ( V_7 ) ;
}
static void F_107 ( struct V_22 * V_7 )
{
if ( V_7 -> V_93 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
V_7 -> V_93 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
}
}
static unsigned int F_108 ( struct V_22 * V_7 )
{
unsigned V_35 = 0 ;
T_2 V_26 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_28 ) {
struct V_24 * V_25 = V_3 -> V_25 ;
F_106 ( V_2 ) ;
V_26 = V_25 -> V_29 ;
}
F_107 ( V_7 ) ;
V_2 -> V_68 = NULL ;
V_2 -> V_71 = NULL ;
for ( V_9 = V_7 -> V_93 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_58 ;
if ( V_92 -> V_59 ) {
V_92 -> V_15 = false ;
continue;
}
V_58 = F_31 ( V_92 ) ;
if ( V_58 < V_2 -> V_4 )
continue;
if ( V_5 . V_18 ) {
V_35 += F_93 ( V_2 , V_92 , V_35 ,
V_92 -> V_74 ) ;
if ( V_35 == V_7 -> V_30 )
break;
if ( V_92 -> V_56 ) {
F_97 ( V_2 , V_35 , V_92 -> V_74 + 1 ) ;
V_35 ++ ;
}
} else {
V_35 += F_89 ( V_2 , V_92 , V_35 ) ;
}
if ( V_35 == V_7 -> V_30 )
break;
}
return V_35 + V_26 ;
}
static struct V_8 * F_5 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_58 = F_31 ( V_92 ) ;
if ( ! V_92 -> V_59 && V_58 >= V_4 )
return V_9 ;
if ( F_24 ( V_9 ) )
V_9 = F_24 ( V_9 ) ;
else
V_9 = F_6 ( V_9 ) ;
}
return NULL ;
}
static struct V_8 * F_109 ( struct V_8 * V_9 ,
float V_4 )
{
while ( V_9 != NULL ) {
struct V_12 * V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_58 = F_31 ( V_92 ) ;
if ( ! V_92 -> V_59 && V_58 >= V_4 )
return V_9 ;
V_9 = F_110 ( V_9 ) ;
}
return NULL ;
}
static void F_111 ( struct V_22 * V_7 ,
T_8 V_98 , int V_186 )
{
struct V_12 * V_92 ;
struct V_8 * V_9 ;
bool V_60 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
if ( V_7 -> V_17 == 0 )
return;
F_107 ( V_7 ) ;
switch ( V_186 ) {
case V_187 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_188 :
V_9 = V_7 -> V_93 ;
goto V_189;
case V_190 :
V_9 = F_112 ( F_113 ( V_7 -> V_11 ) ) ;
V_9 = F_109 ( V_9 , V_2 -> V_4 ) ;
V_60 = false ;
break;
default:
return;
}
V_92 = F_7 ( V_7 -> V_93 , struct V_12 , V_8 ) ;
V_92 -> V_94 = 0 ;
V_189:
if ( ! V_9 )
return;
if ( V_98 > 0 ) {
do {
V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_92 -> V_15 && V_92 -> V_14 ) {
T_2 V_191 = V_92 -> V_16 - V_92 -> V_94 ;
if ( V_98 > V_191 ) {
V_98 -= V_191 ;
V_92 -> V_94 = 0 ;
} else {
V_92 -> V_94 += V_98 ;
V_98 = 0 ;
V_7 -> V_93 = V_9 ;
break;
}
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
-- V_98 ;
V_7 -> V_93 = V_9 ;
} while ( V_98 != 0 );
} else if ( V_98 < 0 ) {
while ( 1 ) {
V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_92 -> V_15 && V_92 -> V_14 ) {
if ( V_60 ) {
if ( - V_98 > V_92 -> V_94 ) {
V_98 += V_92 -> V_94 ;
V_92 -> V_94 = 0 ;
} else {
V_92 -> V_94 += V_98 ;
V_98 = 0 ;
V_7 -> V_93 = V_9 ;
break;
}
} else {
if ( - V_98 > V_92 -> V_16 ) {
V_98 += V_92 -> V_16 ;
V_92 -> V_94 = 0 ;
} else {
V_92 -> V_94 = V_92 -> V_16 + V_98 ;
V_98 = 0 ;
V_7 -> V_93 = V_9 ;
break;
}
}
}
V_9 = F_109 ( F_110 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
++ V_98 ;
V_7 -> V_93 = V_9 ;
if ( V_98 == 0 ) {
V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_92 -> V_15 && V_92 -> V_14 )
V_92 -> V_94 = V_92 -> V_16 ;
break;
}
V_60 = false ;
}
} else {
V_7 -> V_93 = V_9 ;
V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_92 -> V_94 = 0 ;
}
}
static int F_114 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_110 ,
int V_131 )
{
struct V_99 V_86 = {
. V_110 = V_110 ,
} ;
F_83 ( V_7 , V_13 , V_131 , 0 ,
F_70 , & V_86 ,
F_72 ) ;
return V_86 . V_109 ;
}
static int F_115 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_110 )
{
char V_164 [ 8192 ] ;
int V_109 = 0 ;
char V_47 = ' ' ;
struct V_141 V_142 = {
. V_115 = V_164 ,
. V_76 = sizeof( V_164 ) ,
} ;
struct V_162 * V_143 ;
bool V_60 = true ;
int V_146 ;
if ( V_5 . V_163 ) {
V_47 = F_20 ( V_13 ) ;
V_109 += fprintf ( V_110 , L_16 , V_47 ) ;
}
F_90 (browser->hists, fmt) {
if ( F_91 ( V_143 , V_13 -> V_3 ) )
continue;
if ( ! V_60 ) {
V_146 = F_87 ( V_142 . V_115 , V_142 . V_76 , L_17 ) ;
F_99 ( & V_142 , V_146 ) ;
} else
V_60 = false ;
V_146 = V_143 -> V_136 ( V_143 , & V_142 , V_13 ) ;
V_146 = F_92 ( V_13 , & V_142 , V_143 , V_146 ) ;
F_99 ( & V_142 , V_146 ) ;
}
V_109 += fprintf ( V_110 , L_24 , V_164 ) ;
if ( V_47 == '-' )
V_109 += F_114 ( V_7 , V_13 , V_110 , 1 ) ;
return V_109 ;
}
static int F_116 ( struct V_1 * V_7 ,
struct V_12 * V_13 ,
T_9 * V_110 , int V_131 )
{
char V_164 [ 8192 ] ;
int V_109 = 0 ;
char V_47 = ' ' ;
struct V_141 V_142 = {
. V_115 = V_164 ,
. V_76 = sizeof( V_164 ) ,
} ;
struct V_162 * V_143 ;
struct V_167 * V_168 ;
bool V_60 = true ;
int V_146 ;
int V_169 = ( V_13 -> V_3 -> V_170 - 2 ) * V_171 ;
V_109 = fprintf ( V_110 , L_21 , V_131 * V_171 , L_18 ) ;
V_47 = F_20 ( V_13 ) ;
V_109 += fprintf ( V_110 , L_9 , V_47 ) ;
V_168 = F_94 ( & V_13 -> V_3 -> V_173 ,
struct V_167 , V_61 ) ;
F_95 (&fmt_node->hpp, fmt) {
if ( ! V_60 ) {
V_146 = F_87 ( V_142 . V_115 , V_142 . V_76 , L_17 ) ;
F_99 ( & V_142 , V_146 ) ;
} else
V_60 = false ;
V_146 = V_143 -> V_136 ( V_143 , & V_142 , V_13 ) ;
F_99 ( & V_142 , V_146 ) ;
}
V_146 = F_87 ( V_142 . V_115 , V_142 . V_76 , L_21 , V_169 , L_18 ) ;
F_99 ( & V_142 , V_146 ) ;
F_95 (he->hpp_list, fmt) {
V_146 = F_87 ( V_142 . V_115 , V_142 . V_76 , L_17 ) ;
F_99 ( & V_142 , V_146 ) ;
V_146 = V_143 -> V_136 ( V_143 , & V_142 , V_13 ) ;
F_99 ( & V_142 , V_146 ) ;
}
V_109 += fprintf ( V_110 , L_24 , F_117 ( V_164 ) ) ;
if ( V_13 -> V_14 && V_47 == '-' ) {
V_109 += F_114 ( V_7 , V_13 , V_110 ,
V_13 -> V_74 + 1 ) ;
}
return V_109 ;
}
static int F_118 ( struct V_1 * V_7 , T_9 * V_110 )
{
struct V_8 * V_9 = F_5 ( F_4 ( V_7 -> V_23 . V_11 ) ,
V_7 -> V_4 ) ;
int V_109 = 0 ;
while ( V_9 ) {
struct V_12 * V_92 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_5 . V_18 ) {
V_109 += F_116 ( V_7 ,
V_92 , V_110 ,
V_92 -> V_74 ) ;
} else {
V_109 += F_115 ( V_7 , V_92 , V_110 ) ;
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_7 -> V_4 ) ;
}
return V_109 ;
}
static int F_119 ( struct V_1 * V_7 )
{
char V_192 [ 64 ] ;
T_9 * V_110 ;
while ( 1 ) {
F_87 ( V_192 , sizeof( V_192 ) , L_25 , V_7 -> V_193 ) ;
if ( F_120 ( V_192 , V_194 ) )
break;
if ( ++ V_7 -> V_193 == 8192 ) {
F_61 ( L_26 ) ;
return - 1 ;
}
}
V_110 = fopen ( V_192 , L_27 ) ;
if ( V_110 == NULL ) {
char V_75 [ 64 ] ;
const char * V_195 = F_121 ( V_196 , V_75 , sizeof( V_75 ) ) ;
F_61 ( L_28 , V_192 , V_195 ) ;
return - 1 ;
}
++ V_7 -> V_193 ;
F_118 ( V_7 , V_110 ) ;
fclose ( V_110 ) ;
F_61 ( L_29 , V_192 ) ;
return 0 ;
}
void F_122 ( struct V_1 * V_7 ,
struct V_3 * V_3 )
{
struct V_162 * V_143 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_23 . V_83 = F_108 ;
V_7 -> V_23 . V_197 = F_10 ;
V_7 -> V_23 . V_198 = F_111 ;
V_7 -> V_23 . V_199 = true ;
V_7 -> V_28 = V_5 . V_200 ;
if ( V_5 . V_18 ) {
struct V_167 * V_168 ;
V_168 = F_94 ( & V_3 -> V_173 ,
struct V_167 , V_61 ) ;
F_95 ( & V_168 -> V_142 , V_143 )
++ V_7 -> V_23 . V_201 ;
++ V_7 -> V_23 . V_201 ;
} else {
F_90 ( V_3 , V_143 )
++ V_7 -> V_23 . V_201 ;
}
F_123 ( V_3 ) ;
}
struct V_1 * F_124 ( struct V_3 * V_3 )
{
struct V_1 * V_7 = F_125 ( sizeof( * V_7 ) ) ;
if ( V_7 )
F_122 ( V_7 , V_3 ) ;
return V_7 ;
}
static struct V_1 *
F_126 ( struct V_202 * V_203 ,
struct V_80 * V_81 ,
struct V_204 * V_205 )
{
struct V_1 * V_7 = F_124 ( F_127 ( V_203 ) ) ;
if ( V_7 ) {
V_7 -> V_81 = V_81 ;
V_7 -> V_205 = V_205 ;
V_7 -> V_77 = V_206 ;
}
return V_7 ;
}
void F_128 ( struct V_1 * V_7 )
{
free ( V_7 ) ;
}
static struct V_12 * F_129 ( struct V_1 * V_7 )
{
return V_7 -> V_68 ;
}
static struct V_207 * F_130 ( struct V_1 * V_7 )
{
return V_7 -> V_68 -> V_207 ;
}
static inline bool F_131 ( void * V_85 )
{
return V_85 == NULL ;
}
static int V_206 ( struct V_1 * V_7 ,
char * V_75 , T_3 V_76 )
{
struct V_80 * V_81 = V_7 -> V_81 ;
struct V_3 * V_3 = V_7 -> V_3 ;
char V_208 ;
int V_109 ;
const struct V_209 * V_209 = V_3 -> V_210 ;
const struct V_207 * V_207 = V_3 -> V_211 ;
int V_212 = V_3 -> V_213 ;
unsigned long V_214 = V_3 -> V_87 . V_89 [ V_215 ] ;
T_4 V_89 = V_3 -> V_87 . V_216 ;
struct V_202 * V_203 = F_132 ( V_3 ) ;
const char * V_217 = F_133 ( V_203 ) ;
char V_115 [ 512 ] ;
T_3 V_218 = sizeof( V_115 ) ;
char V_219 [ 30 ] = L_30 ;
bool V_220 = false ;
if ( V_5 . V_221 ) {
V_214 = V_3 -> V_87 . V_222 ;
V_89 = V_3 -> V_87 . V_223 ;
}
if ( F_134 ( V_203 ) ) {
struct V_202 * V_224 ;
F_135 ( V_203 , V_115 , V_218 ) ;
V_217 = V_115 ;
F_136 (pos, evsel) {
struct V_3 * V_225 = F_127 ( V_224 ) ;
if ( V_5 . V_221 ) {
V_214 += V_225 -> V_87 . V_222 ;
V_89 += V_225 -> V_87 . V_223 ;
} else {
V_214 += V_225 -> V_87 . V_89 [ V_215 ] ;
V_89 += V_225 -> V_87 . V_216 ;
}
}
}
if ( V_5 . V_226 &&
strstr ( V_217 , L_31 ) )
V_220 = true ;
V_214 = F_137 ( V_214 , & V_208 ) ;
V_109 = F_87 ( V_75 , V_76 ,
L_32 V_227 ,
V_214 , V_208 , V_217 , V_220 ? V_219 : L_8 , V_89 ) ;
if ( V_3 -> V_228 )
V_109 += snprintf ( V_75 + V_109 , V_76 - V_109 ,
L_33 , V_3 -> V_228 ) ;
if ( V_207 ) {
if ( F_138 ( V_3 , V_207 ) ) {
V_109 += F_87 ( V_75 + V_109 , V_76 - V_109 ,
L_34 ,
( V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ) ,
V_207 -> V_230 ) ;
} else {
V_109 += F_87 ( V_75 + V_109 , V_76 - V_109 ,
L_35 ,
( V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ) ) ;
}
}
if ( V_209 )
V_109 += F_87 ( V_75 + V_109 , V_76 - V_109 ,
L_36 , V_209 -> V_231 ) ;
if ( V_212 > - 1 )
V_109 += F_87 ( V_75 + V_109 , V_76 - V_109 ,
L_37 , V_212 ) ;
if ( ! F_131 ( V_81 ) ) {
struct V_232 * V_93 = V_81 -> V_86 ;
if ( V_93 -> V_233 )
V_109 += F_87 ( V_75 + V_109 , V_76 - V_109 , L_38 ) ;
}
return V_109 ;
}
static inline void F_140 ( char * * V_234 , int V_43 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_43 ; ++ V_174 )
F_141 ( & V_234 [ V_174 ] ) ;
}
static int F_142 ( void )
{
char * V_235 , * V_234 [ 32 ] , * V_236 [ 32 ] , * V_237 ;
T_10 * V_238 ;
int V_239 = 0 , V_240 = - 1 , V_146 = - 1 ;
struct V_241 * V_242 ;
V_235 = getenv ( L_39 ) ;
if ( ! V_235 )
return V_146 ;
V_238 = F_143 ( V_235 ) ;
if ( ! V_238 )
return V_146 ;
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
memset ( V_234 , 0 , sizeof( V_236 ) ) ;
while ( ( V_242 = F_144 ( V_238 ) ) ) {
char V_243 [ V_244 ] ;
T_4 V_245 ;
char * V_246 = V_242 -> V_247 ;
T_9 * V_248 ;
if ( ! ( V_242 -> V_249 == V_250 ) )
continue;
snprintf ( V_243 , sizeof( V_243 ) , L_40 , V_235 , V_246 ) ;
V_248 = fopen ( V_243 , L_41 ) ;
if ( ! V_248 )
continue;
if ( fread ( & V_245 , 1 , 8 , V_248 ) < 8 )
goto V_251;
if ( F_145 ( V_245 ) ) {
V_234 [ V_239 ] = F_146 ( V_246 ) ;
if ( ! V_234 [ V_239 ] )
goto V_251;
V_236 [ V_239 ] = F_146 ( V_243 ) ;
if ( ! V_236 [ V_239 ] ) {
F_141 ( & V_234 [ V_239 ] ) ;
F_147 ( L_42 ) ;
fclose ( V_248 ) ;
break;
}
V_239 ++ ;
}
V_251:
fclose ( V_248 ) ;
if ( V_239 >= 32 ) {
F_147 ( L_43
L_44 ) ;
break;
}
}
F_148 ( V_238 ) ;
if ( V_239 ) {
V_240 = F_149 ( V_239 , V_234 ) ;
if ( V_240 < V_239 && V_240 >= 0 ) {
V_237 = F_146 ( V_236 [ V_240 ] ) ;
if ( V_237 ) {
if ( V_252 )
free ( ( void * ) V_253 ) ;
V_253 = V_237 ;
V_252 = true ;
V_146 = 0 ;
} else
F_147 ( L_45 ) ;
}
}
F_140 ( V_234 , V_239 ) ;
F_140 ( V_236 , V_239 ) ;
return V_146 ;
}
static int
F_150 ( struct V_1 * V_7 , struct V_254 * V_255 )
{
struct V_202 * V_203 ;
struct V_256 * V_257 ;
struct V_12 * V_13 ;
int V_195 ;
if ( ! V_258 && F_151 ( V_7 -> V_205 ) )
return 0 ;
V_257 = F_64 ( V_255 -> V_70 . V_103 ) ;
if ( ! V_257 -> V_104 )
return 0 ;
V_203 = F_132 ( V_7 -> V_3 ) ;
V_195 = F_152 ( & V_255 -> V_70 , V_203 , V_7 -> V_81 ) ;
V_13 = F_129 ( V_7 ) ;
if ( ( V_195 == 'q' || V_195 == F_153 ( 'c' ) ) && V_13 -> V_259 )
return 1 ;
F_58 ( & V_7 -> V_23 , V_7 -> V_3 -> V_17 ) ;
if ( V_195 )
F_154 ( & V_7 -> V_23 ) ;
return 0 ;
}
static int
F_155 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 , char * * V_260 ,
struct V_261 * V_261 , struct V_262 * V_103 )
{
if ( V_103 == NULL || V_261 -> V_209 -> V_263 )
return 0 ;
if ( F_76 ( V_260 , L_46 , V_103 -> V_246 ) < 0 )
return 0 ;
V_255 -> V_70 . V_261 = V_261 ;
V_255 -> V_70 . V_103 = V_103 ;
V_255 -> V_264 = F_150 ;
return 1 ;
}
static int
F_156 ( struct V_1 * V_7 , struct V_254 * V_255 )
{
struct V_207 * V_207 = V_255 -> V_207 ;
if ( ( ! F_138 ( V_7 -> V_3 , V_207 ) &&
! F_138 ( V_7 -> V_3 , V_265 ) ) || V_207 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_211 ) {
F_157 ( V_7 -> V_266 , & V_7 -> V_3 -> V_211 ) ;
F_158 ( V_267 , false ) ;
F_159 ( V_7 -> V_3 -> V_211 ) ;
F_60 () ;
} else {
if ( F_138 ( V_7 -> V_3 , V_207 ) ) {
F_61 ( L_47 ,
V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ,
V_207 -> V_230 ) ;
} else {
F_61 ( L_48 ,
V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ) ;
}
V_7 -> V_3 -> V_211 = F_160 ( V_207 ) ;
F_158 ( V_267 , false ) ;
F_161 ( V_7 -> V_266 , & V_7 -> V_3 -> V_211 ) ;
}
F_162 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_163 ( struct V_1 * V_7 , struct V_254 * V_255 ,
char * * V_260 , struct V_207 * V_207 )
{
int V_146 ;
if ( ( ! F_138 ( V_7 -> V_3 , V_207 ) &&
! F_138 ( V_7 -> V_3 , V_265 ) ) || V_207 == NULL )
return 0 ;
if ( F_138 ( V_7 -> V_3 , V_207 ) ) {
V_146 = F_76 ( V_260 , L_49 ,
V_7 -> V_3 -> V_211 ? L_50 : L_51 ,
V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ,
V_207 -> V_230 ) ;
} else {
V_146 = F_76 ( V_260 , L_52 ,
V_7 -> V_3 -> V_211 ? L_50 : L_51 ,
V_207 -> V_229 ? F_139 ( V_207 ) : L_18 ) ;
}
if ( V_146 < 0 )
return 0 ;
V_255 -> V_207 = V_207 ;
V_255 -> V_264 = F_156 ;
return 1 ;
}
static int
F_164 ( struct V_1 * V_7 , struct V_254 * V_255 )
{
struct V_261 * V_261 = V_255 -> V_70 . V_261 ;
if ( ! F_138 ( V_7 -> V_3 , V_209 ) || V_261 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_210 ) {
F_157 ( V_7 -> V_266 , & V_7 -> V_3 -> V_210 ) ;
F_158 ( V_268 , false ) ;
V_7 -> V_3 -> V_210 = NULL ;
F_60 () ;
} else {
F_61 ( L_53 ,
F_165 ( V_261 ) ? L_54 : V_261 -> V_209 -> V_231 ) ;
V_7 -> V_3 -> V_210 = V_261 -> V_209 ;
F_158 ( V_268 , true ) ;
F_161 ( V_7 -> V_266 , & V_7 -> V_3 -> V_210 ) ;
}
F_166 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_167 ( struct V_1 * V_7 , struct V_254 * V_255 ,
char * * V_260 , struct V_261 * V_261 )
{
if ( ! F_138 ( V_7 -> V_3 , V_209 ) || V_261 == NULL )
return 0 ;
if ( F_76 ( V_260 , L_55 ,
V_7 -> V_3 -> V_210 ? L_50 : L_51 ,
F_165 ( V_261 ) ? L_54 : V_261 -> V_209 -> V_231 ) < 0 )
return 0 ;
V_255 -> V_70 . V_261 = V_261 ;
V_255 -> V_264 = F_164 ;
return 1 ;
}
static int
F_168 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 )
{
F_169 ( V_255 -> V_70 . V_261 ) ;
return 0 ;
}
static int
F_170 ( struct V_1 * V_7 ,
struct V_254 * V_255 , char * * V_260 , struct V_261 * V_261 )
{
if ( ! F_138 ( V_7 -> V_3 , V_209 ) || V_261 == NULL )
return 0 ;
if ( F_76 ( V_260 , L_56 ) < 0 )
return 0 ;
V_255 -> V_70 . V_261 = V_261 ;
V_255 -> V_264 = F_168 ;
return 1 ;
}
static int
F_171 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 )
{
char V_269 [ 64 ] ;
memset ( V_269 , 0 , sizeof( V_269 ) ) ;
if ( V_255 -> V_207 ) {
F_87 ( V_269 , sizeof( V_269 ) , L_57 ,
F_139 ( V_255 -> V_207 ) ) ;
} else if ( V_255 -> V_70 . V_103 ) {
F_87 ( V_269 , sizeof( V_269 ) , L_58 ,
V_255 -> V_70 . V_103 -> V_246 ) ;
}
F_172 ( V_269 ) ;
return 0 ;
}
static int
F_173 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 , char * * V_260 ,
struct V_207 * V_207 , struct V_262 * V_103 )
{
if ( V_207 ) {
if ( F_76 ( V_260 , L_59 ,
F_139 ( V_207 ) ) < 0 )
return 0 ;
} else if ( V_103 ) {
if ( F_76 ( V_260 , L_60 ,
V_103 -> V_246 ) < 0 )
return 0 ;
} else {
if ( F_76 ( V_260 , L_61 ) < 0 )
return 0 ;
}
V_255 -> V_207 = V_207 ;
V_255 -> V_70 . V_103 = V_103 ;
V_255 -> V_264 = F_171 ;
return 1 ;
}
static int
F_174 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 V_48 )
{
if ( F_142 () ) {
F_147 ( L_62
L_63 ) ;
return 0 ;
}
return V_270 ;
}
static int
F_175 ( struct V_1 * V_7 ,
struct V_254 * V_255 , char * * V_260 )
{
if ( ! F_131 ( V_7 -> V_81 ) )
return 0 ;
if ( F_76 ( V_260 , L_64 ) < 0 )
return 0 ;
V_255 -> V_264 = F_174 ;
return 1 ;
}
static int
F_176 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 V_48 )
{
return 0 ;
}
static int
F_177 ( struct V_1 * V_7 V_48 ,
struct V_254 * V_255 , char * * V_260 )
{
if ( F_76 ( V_260 , L_65 ) < 0 )
return 0 ;
V_255 -> V_264 = F_176 ;
return 1 ;
}
static int
F_178 ( struct V_1 * V_7 , struct V_254 * V_255 )
{
if ( ! F_138 ( V_7 -> V_3 , V_271 ) || V_255 -> V_271 < 0 )
return 0 ;
if ( V_7 -> V_3 -> V_213 > - 1 ) {
F_157 ( V_7 -> V_266 , & V_7 -> V_3 -> V_213 ) ;
V_7 -> V_3 -> V_213 = - 1 ;
F_158 ( V_272 , false ) ;
} else {
V_7 -> V_3 -> V_213 = V_255 -> V_271 ;
F_158 ( V_272 , true ) ;
F_161 ( V_7 -> V_266 , & V_7 -> V_3 -> V_213 ) ;
}
F_179 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_180 ( struct V_1 * V_7 , struct V_254 * V_255 ,
char * * V_260 , int V_212 )
{
if ( ! F_138 ( V_7 -> V_3 , V_271 ) || V_212 < 0 )
return 0 ;
if ( F_76 ( V_260 , L_66 ,
( V_7 -> V_3 -> V_213 > - 1 ) ? L_50 : L_51 ,
V_212 ) < 0 )
return 0 ;
V_255 -> V_271 = V_212 ;
V_255 -> V_264 = F_178 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_4 V_17 = 0 ;
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
static void F_181 ( struct V_1 * V_2 ,
double V_58 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
T_4 V_111 = F_84 ( V_2 -> V_3 ) ;
T_4 V_273 = V_111 * ( V_58 / 100 ) ;
V_2 -> V_4 = V_49 . V_274 = V_58 ;
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_13 -> V_56 ) {
V_13 -> V_56 = false ;
V_13 -> V_16 = 0 ;
}
if ( ! V_13 -> V_14 || ! V_5 . V_163 )
goto V_62;
if ( V_49 . V_50 == V_133 ) {
V_111 = V_13 -> V_140 . V_139 ;
if ( V_5 . V_137 )
V_111 = V_13 -> V_138 -> V_139 ;
V_273 = V_111 * ( V_58 / 100 ) ;
}
V_49 . V_275 ( & V_13 -> V_55 , V_13 -> V_276 ,
V_273 , & V_49 ) ;
V_62:
V_9 = F_49 ( V_9 , V_73 ) ;
V_13 -> V_67 = false ;
F_47 ( V_13 , V_2 , false ) ;
}
}
static int F_182 ( struct V_202 * V_203 , int V_89 ,
const char * V_277 ,
bool V_278 ,
struct V_80 * V_81 ,
float V_4 ,
struct V_204 * V_205 )
{
struct V_3 * V_3 = F_127 ( V_203 ) ;
struct V_1 * V_7 = F_126 ( V_203 , V_81 , V_205 ) ;
struct V_259 * V_279 ;
#define F_183 16
char * V_234 [ F_183 ] ;
struct V_254 V_280 [ F_183 ] ;
int V_239 = 0 ;
int V_79 = - 1 ;
char V_115 [ 64 ] ;
int V_82 = V_81 ? V_81 -> V_83 : 0 ;
#define F_184 \
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
const char V_281 [] = F_184
L_67
L_68
L_69
L_70
L_71
L_72
L_73 ;
const char V_282 [] = F_184
L_68
L_71
L_72
L_74
L_75
L_73 ;
if ( V_7 == NULL )
return - 1 ;
F_185 () ;
F_186 ( 0 , 0 , 0 ) ;
if ( V_4 )
V_7 -> V_4 = V_4 ;
F_17 ( V_7 ) ;
V_7 -> V_266 = F_187 ( 3 ) ;
if ( V_7 -> V_266 == NULL )
goto V_96;
F_188 ( V_277 ) ;
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
memset ( V_280 , 0 , sizeof( V_280 ) ) ;
if ( V_5 . V_283 )
F_189 ( V_5 . V_283 ) ;
while ( 1 ) {
struct V_207 * V_207 = NULL ;
struct V_261 * V_261 = NULL ;
int V_240 = 0 ;
int V_284 = - 1 ;
V_239 = 0 ;
V_79 = F_55 ( V_7 , V_277 ) ;
if ( V_7 -> V_68 != NULL ) {
V_207 = F_130 ( V_7 ) ;
V_261 = V_7 -> V_71 -> V_261 ;
V_284 = V_7 -> V_68 -> V_271 ;
}
switch ( V_79 ) {
case V_285 :
case V_286 :
if ( V_89 == 1 )
continue;
goto V_287;
case 'a' :
if ( ! F_138 ( V_3 , V_103 ) ) {
F_53 ( & V_7 -> V_23 , V_82 * 2 ,
L_76
L_77 ) ;
continue;
}
if ( V_7 -> V_71 == NULL ||
V_7 -> V_71 -> V_103 == NULL ||
V_7 -> V_71 -> V_261 -> V_209 -> V_263 )
continue;
V_280 -> V_70 . V_261 = V_7 -> V_71 -> V_261 ;
V_280 -> V_70 . V_103 = V_7 -> V_71 -> V_103 ;
F_150 ( V_7 , V_280 ) ;
continue;
case 'P' :
F_119 ( V_7 ) ;
continue;
case 'd' :
V_280 -> V_70 . V_261 = V_261 ;
F_164 ( V_7 , V_280 ) ;
continue;
case 'V' :
V_7 -> V_102 = ! V_7 -> V_102 ;
continue;
case 't' :
V_280 -> V_207 = V_207 ;
F_156 ( V_7 , V_280 ) ;
continue;
case 'S' :
V_280 -> V_271 = V_284 ;
F_178 ( V_7 , V_280 ) ;
continue;
case '/' :
if ( F_190 ( L_78 ,
L_79
L_80 ,
V_115 , L_81 ,
V_82 * 2 ) == V_95 ) {
V_3 -> V_288 = * V_115 ? V_115 : NULL ;
F_191 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_131 ( V_81 ) ) {
V_280 -> V_207 = NULL ;
V_280 -> V_70 . V_103 = NULL ;
F_171 ( V_7 , V_280 ) ;
}
continue;
case 's' :
if ( F_131 ( V_81 ) ) {
V_79 = F_174 ( V_7 , V_280 ) ;
if ( V_79 == V_270 )
goto V_287;
}
continue;
case 'i' :
if ( V_205 -> V_289 )
F_192 ( V_205 ) ;
continue;
case 'F' :
V_5 . V_221 ^= 1 ;
continue;
case 'z' :
if ( ! F_131 ( V_81 ) ) {
struct V_232 * V_93 = V_81 -> V_86 ;
V_93 -> V_233 = ! V_93 -> V_233 ;
}
continue;
case 'L' :
if ( F_190 ( L_82 ,
L_83 ,
V_115 , L_81 ,
V_82 * 2 ) == V_95 ) {
char * V_290 ;
double V_291 = strtod ( V_115 , & V_290 ) ;
if ( V_291 < 0 || V_291 > 100 ) {
F_53 ( & V_7 -> V_23 , V_82 * 2 ,
L_84 , V_291 ) ;
continue;
}
F_181 ( V_7 , V_291 ) ;
F_16 ( V_7 ) ;
}
continue;
case V_292 :
case 'h' :
case '?' :
F_193 ( & V_7 -> V_23 ,
F_131 ( V_81 ) ? V_281 : V_282 ) ;
continue;
case V_95 :
case V_293 :
case 'm' :
break;
case V_294 :
case V_295 : {
const void * V_93 ;
if ( F_194 ( V_7 -> V_266 ) ) {
if ( V_278 )
goto V_287;
if ( V_79 == V_294 &&
F_195 ( & V_7 -> V_23 ,
L_85 ) )
goto V_287;
continue;
}
V_93 = F_196 ( V_7 -> V_266 ) ;
if ( V_93 == & V_7 -> V_3 -> V_210 ) {
F_164 ( V_7 , V_280 ) ;
} else if ( V_93 == & V_7 -> V_3 -> V_211 ) {
F_156 ( V_7 , V_280 ) ;
} else if ( V_93 == & V_7 -> V_3 -> V_213 ) {
F_178 ( V_7 , V_280 ) ;
}
continue;
}
case 'q' :
case F_153 ( 'c' ) :
goto V_287;
case 'f' :
if ( ! F_131 ( V_81 ) ) {
struct V_232 * V_93 = V_81 -> V_86 ;
F_197 ( V_93 -> V_296 ) ;
if ( V_93 -> V_296 -> V_297 ) {
V_277 = L_86 ;
V_81 -> V_83 = V_82 ;
} else {
V_277 = L_87 ;
V_81 -> V_83 = 0 ;
}
continue;
}
default:
V_277 = L_88 ;
continue;
}
if ( ! F_138 ( V_3 , V_103 ) || V_7 -> V_71 == NULL )
goto V_298;
if ( V_299 == V_300 ) {
V_279 = V_7 -> V_68 -> V_259 ;
if ( V_279 == NULL )
goto V_298;
V_239 += F_155 ( V_7 ,
& V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_279 -> V_301 . V_261 ,
V_279 -> V_301 . V_103 ) ;
if ( V_279 -> V_302 . V_103 != V_279 -> V_301 . V_103 )
V_239 += F_155 ( V_7 ,
& V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_279 -> V_302 . V_261 ,
V_279 -> V_302 . V_103 ) ;
} else {
V_239 += F_155 ( V_7 ,
& V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_7 -> V_71 -> V_261 ,
V_7 -> V_71 -> V_103 ) ;
}
V_298:
V_239 += F_163 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] , V_207 ) ;
V_239 += F_167 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] , V_261 ) ;
V_239 += F_170 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_7 -> V_71 ?
V_7 -> V_71 -> V_261 : NULL ) ;
V_239 += F_180 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_284 ) ;
if ( ! F_131 ( V_81 ) )
goto V_303;
if ( V_7 -> V_68 ) {
if ( F_138 ( V_3 , V_207 ) && V_207 ) {
V_239 += F_173 ( V_7 ,
& V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
V_207 , NULL ) ;
}
if ( F_138 ( V_3 , V_103 ) && V_7 -> V_71 -> V_103 ) {
V_239 += F_173 ( V_7 ,
& V_280 [ V_239 ] ,
& V_234 [ V_239 ] ,
NULL , V_7 -> V_71 -> V_103 ) ;
}
}
V_239 += F_173 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] , NULL , NULL ) ;
V_239 += F_175 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] ) ;
V_303:
V_239 += F_177 ( V_7 , & V_280 [ V_239 ] ,
& V_234 [ V_239 ] ) ;
do {
struct V_254 * V_255 ;
V_240 = F_149 ( V_239 , V_234 ) ;
if ( V_240 == - 1 || V_240 >= V_239 )
break;
V_255 = & V_280 [ V_240 ] ;
V_79 = V_255 -> V_264 ( V_7 , V_255 ) ;
} while ( V_79 == 1 );
if ( V_79 == V_270 )
break;
}
V_287:
F_198 ( V_7 -> V_266 ) ;
V_96:
F_128 ( V_7 ) ;
F_140 ( V_234 , F_183 ) ;
return V_79 ;
}
static void F_199 ( struct V_22 * V_7 ,
void * V_136 , int V_35 )
{
struct V_304 * V_305 = F_11 ( V_7 ,
struct V_304 , V_23 ) ;
struct V_202 * V_203 = F_37 ( V_136 , struct V_202 , V_42 ) ;
struct V_3 * V_3 = F_127 ( V_203 ) ;
bool V_148 = F_65 ( V_7 , V_35 ) ;
unsigned long V_89 = V_3 -> V_87 . V_89 [ V_215 ] ;
const char * V_217 = F_133 ( V_203 ) ;
char V_75 [ 256 ] , V_208 ;
const char * V_306 = L_8 ;
T_3 V_109 ;
F_66 ( V_7 , V_148 ? V_106 :
V_105 ) ;
if ( F_134 ( V_203 ) ) {
struct V_202 * V_224 ;
V_217 = F_200 ( V_203 ) ;
F_136 (pos, evsel) {
struct V_3 * V_225 = F_127 ( V_224 ) ;
V_89 += V_225 -> V_87 . V_89 [ V_215 ] ;
}
}
V_89 = F_137 ( V_89 , & V_208 ) ;
V_109 = F_87 ( V_75 , sizeof( V_75 ) , L_89 , V_89 ,
V_208 , V_208 == ' ' ? L_18 : L_8 , V_217 ) ;
F_68 ( V_7 , L_6 , V_75 ) ;
V_89 = V_3 -> V_87 . V_89 [ V_90 ] ;
if ( V_89 != 0 ) {
V_305 -> V_307 = true ;
if ( ! V_148 )
F_66 ( V_7 , V_308 ) ;
V_89 = F_137 ( V_89 , & V_208 ) ;
V_109 += F_87 ( V_75 , sizeof( V_75 ) , L_90 ,
V_89 , V_208 , V_208 == ' ' ? L_18 : L_8 ) ;
V_306 = V_75 ;
}
F_67 ( V_7 , V_306 , V_7 -> V_34 - V_109 ) ;
if ( V_148 )
V_305 -> V_71 = V_203 ;
}
static int F_201 ( struct V_304 * V_305 ,
int V_89 , const char * V_78 ,
struct V_80 * V_81 )
{
struct V_309 * V_296 = V_305 -> V_23 . V_310 ;
struct V_202 * V_224 ;
const char * V_77 = L_91 ;
int V_82 = V_81 ? V_81 -> V_83 : 0 ;
int V_79 ;
if ( F_56 ( & V_305 -> V_23 , V_77 ,
L_92 ) < 0 )
return - 1 ;
while ( 1 ) {
V_79 = F_57 ( & V_305 -> V_23 , V_82 ) ;
switch ( V_79 ) {
case V_84 :
V_81 -> V_85 ( V_81 -> V_86 ) ;
if ( ! V_305 -> V_311 && V_305 -> V_307 ) {
F_52 ( & V_305 -> V_23 ) ;
V_305 -> V_311 = true ;
}
continue;
case V_293 :
case V_95 :
if ( ! V_305 -> V_71 )
continue;
V_224 = V_305 -> V_71 ;
V_312:
F_202 ( V_296 , V_224 ) ;
if ( V_81 )
V_81 -> V_85 ( V_81 -> V_86 ) ;
V_79 = F_182 ( V_224 , V_89 , V_78 ,
true , V_81 ,
V_305 -> V_4 ,
V_305 -> V_205 ) ;
F_59 ( & V_305 -> V_23 , V_77 ) ;
switch ( V_79 ) {
case V_285 :
if ( V_224 -> V_42 . V_62 == & V_296 -> V_11 )
V_224 = F_203 ( V_296 ) ;
else
V_224 = F_204 ( V_224 ) ;
goto V_312;
case V_286 :
if ( V_224 -> V_42 . V_65 == & V_296 -> V_11 )
V_224 = F_205 ( V_296 ) ;
else
V_224 = F_206 ( V_224 ) ;
goto V_312;
case V_270 :
case 'q' :
case F_153 ( 'c' ) :
goto V_96;
case V_294 :
default:
continue;
}
case V_295 :
continue;
case V_294 :
if ( ! F_195 ( & V_305 -> V_23 ,
L_85 ) )
continue;
case 'q' :
case F_153 ( 'c' ) :
goto V_96;
default:
continue;
}
}
V_96:
F_62 ( & V_305 -> V_23 ) ;
return V_79 ;
}
static bool F_207 ( struct V_22 * V_7 V_48 ,
void * V_136 )
{
struct V_202 * V_203 = F_37 ( V_136 , struct V_202 , V_42 ) ;
if ( V_5 . V_313 && ! F_208 ( V_203 ) )
return true ;
return false ;
}
static int F_209 ( struct V_309 * V_296 ,
int V_17 , const char * V_78 ,
struct V_80 * V_81 ,
float V_4 ,
struct V_204 * V_205 )
{
struct V_202 * V_224 ;
struct V_304 V_305 = {
. V_23 = {
. V_11 = & V_296 -> V_11 ,
. V_83 = V_314 ,
. V_198 = V_315 ,
. V_316 = F_199 ,
. V_317 = F_207 ,
. V_17 = V_17 ,
. V_310 = V_296 ,
} ,
. V_4 = V_4 ,
. V_205 = V_205 ,
} ;
F_188 ( L_93 ) ;
F_210 (evlist, pos) {
const char * V_217 = F_133 ( V_224 ) ;
T_3 V_318 = strlen ( V_217 ) + 7 ;
if ( V_305 . V_23 . V_34 < V_318 )
V_305 . V_23 . V_34 = V_318 ;
}
return F_201 ( & V_305 , V_17 , V_78 , V_81 ) ;
}
int F_211 ( struct V_309 * V_296 , const char * V_78 ,
struct V_80 * V_81 ,
float V_4 ,
struct V_204 * V_205 )
{
int V_17 = V_296 -> V_17 ;
V_319:
if ( V_17 == 1 ) {
struct V_202 * V_60 = F_203 ( V_296 ) ;
return F_182 ( V_60 , V_17 , V_78 ,
false , V_81 , V_4 ,
V_205 ) ;
}
if ( V_5 . V_313 ) {
struct V_202 * V_224 ;
V_17 = 0 ;
F_210 (evlist, pos) {
if ( F_208 ( V_224 ) )
V_17 ++ ;
}
if ( V_17 == 1 )
goto V_319;
}
return F_209 ( V_296 , V_17 , V_78 ,
V_81 , V_4 , V_205 ) ;
}
