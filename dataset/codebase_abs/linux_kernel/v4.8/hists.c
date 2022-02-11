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
static int F_54 ( struct V_1 * V_7 , char * V_72 , T_3 V_73 )
{
return V_7 -> V_74 ? V_7 -> V_74 ( V_7 , V_72 , V_73 ) : 0 ;
}
int F_55 ( struct V_1 * V_7 , const char * V_75 )
{
int V_76 ;
char V_74 [ 160 ] ;
struct V_77 * V_78 = V_7 -> V_78 ;
int V_79 = V_78 ? V_78 -> V_80 : 0 ;
V_7 -> V_23 . V_11 = & V_7 -> V_3 -> V_11 ;
V_7 -> V_23 . V_17 = F_8 ( V_7 ) ;
F_54 ( V_7 , V_74 , sizeof( V_74 ) ) ;
if ( F_56 ( & V_7 -> V_23 , V_74 , L_6 , V_75 ) < 0 )
return - 1 ;
while ( 1 ) {
V_76 = F_57 ( & V_7 -> V_23 , V_79 ) ;
switch ( V_76 ) {
case V_81 : {
T_4 V_17 ;
V_78 -> V_82 ( V_78 -> V_83 ) ;
if ( F_1 ( V_7 ) )
F_17 ( V_7 ) ;
V_17 = F_8 ( V_7 ) ;
F_58 ( & V_7 -> V_23 , V_17 ) ;
if ( V_7 -> V_3 -> V_84 . V_85 !=
V_7 -> V_3 -> V_84 . V_86 [ V_87 ] ) {
V_7 -> V_3 -> V_84 . V_85 =
V_7 -> V_3 -> V_84 . V_86 [ V_87 ] ;
F_52 ( & V_7 -> V_23 ) ;
}
F_54 ( V_7 , V_74 , sizeof( V_74 ) ) ;
F_59 ( & V_7 -> V_23 , V_74 ) ;
continue;
}
case 'D' : {
static int V_88 ;
struct V_12 * V_89 = F_7 ( V_7 -> V_23 . V_90 ,
struct V_12 , V_8 ) ;
F_60 () ;
F_61 ( L_7 ,
V_88 ++ , V_7 -> V_23 . V_17 ,
V_7 -> V_3 -> V_17 ,
V_7 -> V_23 . V_27 ,
V_7 -> V_23 . V_29 ,
V_7 -> V_23 . V_30 ,
V_89 -> V_91 , V_89 -> V_16 ) ;
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
case V_92 :
if ( F_42 ( V_7 ) )
break;
default:
goto V_93;
}
}
V_93:
F_62 ( & V_7 -> V_23 ) ;
return V_76 ;
}
static void F_63 ( struct V_1 * V_7 ,
struct V_35 * V_43 ,
const char * V_94 , int V_95 ,
unsigned short V_32 ,
struct V_96 * V_83 )
{
int V_97 , V_31 ;
char V_44 = F_21 ( V_43 ) ;
bool V_98 = V_7 -> V_99 && V_43 -> V_67 . V_100 && F_64 ( V_43 -> V_67 . V_100 ) -> V_101 ;
V_97 = V_102 ;
V_31 = V_7 -> V_23 . V_31 - ( V_95 + 2 ) ;
if ( F_65 ( & V_7 -> V_23 , V_32 ) ) {
V_7 -> V_68 = & V_43 -> V_67 ;
V_97 = V_103 ;
V_83 -> V_104 = true ;
}
F_66 ( & V_7 -> V_23 , V_97 ) ;
F_14 ( V_7 , V_32 , 0 ) ;
F_67 ( & V_7 -> V_23 , L_8 , V_95 ) ;
F_68 ( & V_7 -> V_23 , L_9 , V_44 ) ;
F_69 ( & V_7 -> V_23 , V_98 ? V_105 : ' ' ) ;
F_67 ( & V_7 -> V_23 , V_94 , V_31 ) ;
}
static void F_70 ( struct V_1 * V_23 V_45 ,
struct V_35 * V_43 ,
const char * V_94 , int V_95 ,
unsigned short V_32 V_45 ,
struct V_96 * V_83 )
{
char V_44 = F_21 ( V_43 ) ;
V_83 -> V_106 += fprintf ( V_83 -> V_107 , L_10 , V_95 , L_8 ,
V_44 , V_94 ) ;
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
unsigned short V_32 , T_4 V_108 ,
bool V_109 , int V_95 ,
T_5 V_110 ,
struct V_96 * V_83 )
{
char V_72 [ 1024 ] , * V_111 ;
const char * V_94 ;
if ( V_83 -> V_91 != 0 ) {
V_83 -> V_91 -- ;
return 0 ;
}
V_111 = NULL ;
V_94 = F_74 ( V_43 , V_72 , sizeof( V_72 ) ,
V_7 -> V_99 ) ;
if ( V_109 ) {
char V_112 [ 64 ] ;
F_75 ( V_39 , V_112 , sizeof( V_112 ) ,
V_108 ) ;
if ( F_76 ( & V_111 , L_11 , V_112 , V_94 ) < 0 )
V_94 = L_12 ;
else
V_94 = V_111 ;
}
V_110 ( V_7 , V_43 , V_94 , V_95 , V_32 , V_83 ) ;
free ( V_111 ) ;
return 1 ;
}
static bool F_77 ( struct V_8 * V_39 , T_4 V_113 )
{
struct V_38 * V_42 ;
if ( V_39 == NULL )
return false ;
if ( F_24 ( V_39 ) )
return true ;
V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
return F_78 ( V_42 ) != V_113 ;
}
static int F_79 ( struct V_1 * V_7 ,
struct V_41 * V_63 ,
unsigned short V_32 , T_4 V_108 ,
T_4 V_113 ,
T_5 V_110 ,
struct V_96 * V_83 ,
T_6 V_114 )
{
struct V_8 * V_39 ;
int V_115 = V_32 , V_95 = V_116 ;
bool V_109 ;
V_39 = F_4 ( V_63 ) ;
V_109 = F_77 ( V_39 , V_113 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 ;
char V_44 = ' ' ;
int V_57 = true ;
int V_117 = 0 ;
F_25 (chain, &child->parent_val, list) {
bool V_118 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_109 )
V_117 = V_116 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_108 ,
V_118 && V_109 ,
V_95 + V_117 ,
V_110 , V_83 ) ;
if ( V_114 ( V_7 , V_32 ) )
goto V_93;
if ( V_44 == '+' )
goto V_59;
}
F_25 (chain, &child->val, list) {
bool V_118 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_109 )
V_117 = V_116 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_108 ,
V_118 && V_109 ,
V_95 + V_117 ,
V_110 , V_83 ) ;
if ( V_114 ( V_7 , V_32 ) )
goto V_93;
if ( V_44 == '+' )
break;
}
V_59:
if ( V_114 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
V_93:
return V_32 - V_115 ;
}
static char * F_80 ( struct V_1 * V_7 ,
struct V_35 * V_43 ,
char * V_119 , char * V_120 )
{
char V_72 [ 1024 ] ;
const char * V_94 ;
char * V_121 ;
V_94 = F_74 ( V_43 , V_72 , sizeof( V_72 ) ,
V_7 -> V_99 ) ;
if ( V_120 ) {
if ( F_76 ( & V_121 , L_13 , V_120 ,
V_5 . V_122 ? : L_14 , V_94 ) < 0 )
V_121 = NULL ;
} else {
if ( V_119 ) {
if ( F_76 ( & V_121 , L_11 , V_119 , V_94 ) < 0 )
V_121 = NULL ;
} else {
if ( F_76 ( & V_121 , L_6 , V_94 ) < 0 )
V_121 = NULL ;
}
}
return V_121 ;
}
static int F_81 ( struct V_1 * V_7 ,
struct V_41 * V_63 ,
unsigned short V_32 , T_4 V_108 ,
T_4 V_113 ,
T_5 V_110 ,
struct V_96 * V_83 ,
T_6 V_114 )
{
struct V_8 * V_39 ;
int V_115 = V_32 , V_95 = V_116 ;
bool V_109 ;
V_39 = F_4 ( V_63 ) ;
V_109 = F_77 ( V_39 , V_113 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 , * V_123 = NULL ;
int V_57 = true ;
char * V_119 = NULL , * V_124 = NULL ;
char * V_125 = NULL , * V_126 = NULL ;
if ( V_83 -> V_91 != 0 ) {
V_83 -> V_91 -- ;
goto V_59;
}
if ( V_109 ) {
char V_112 [ 64 ] ;
F_75 ( V_42 , V_112 , sizeof( V_112 ) , V_108 ) ;
if ( F_76 ( & V_119 , L_6 , V_112 ) < 0 ) {
V_119 = ( char * ) L_15 ;
goto V_127;
}
V_124 = V_119 ;
}
F_25 (chain, &child->parent_val, list) {
V_125 = F_80 ( V_7 ,
V_43 , V_119 , V_125 ) ;
if ( V_57 ) {
V_57 = false ;
V_123 = V_43 ;
}
if ( V_125 == NULL ) {
V_125 = ( char * ) L_12 ;
goto V_127;
}
V_126 = V_125 ;
}
F_25 (chain, &child->val, list) {
V_125 = F_80 ( V_7 ,
V_43 , V_119 , V_125 ) ;
if ( V_57 ) {
V_57 = false ;
V_123 = V_43 ;
}
if ( V_125 == NULL ) {
V_125 = ( char * ) L_12 ;
goto V_127;
}
V_126 = V_125 ;
}
V_127:
V_110 ( V_7 , V_123 , V_125 , V_95 , V_32 ++ , V_83 ) ;
free ( V_124 ) ;
free ( V_126 ) ;
V_59:
if ( V_114 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
return V_32 - V_115 ;
}
static int F_82 ( struct V_1 * V_7 ,
struct V_41 * V_63 , int V_128 ,
unsigned short V_32 , T_4 V_108 ,
T_4 V_113 ,
T_5 V_110 ,
struct V_96 * V_83 ,
T_6 V_114 )
{
struct V_8 * V_39 ;
int V_115 = V_32 , V_95 = V_128 * V_116 ;
bool V_109 ;
T_4 V_129 = V_108 ;
if ( V_46 . V_47 == V_130 )
V_129 = V_113 ;
V_39 = F_4 ( V_63 ) ;
V_109 = F_77 ( V_39 , V_113 ) ;
while ( V_39 ) {
struct V_38 * V_42 = F_7 ( V_39 , struct V_38 , V_8 ) ;
struct V_8 * V_59 = F_24 ( V_39 ) ;
struct V_35 * V_43 ;
char V_44 = ' ' ;
int V_57 = true ;
int V_117 = 0 ;
F_25 (chain, &child->val, list) {
bool V_118 = V_57 ;
if ( V_57 )
V_57 = false ;
else if ( V_109 )
V_117 = V_116 ;
V_44 = F_21 ( V_43 ) ;
V_32 += F_73 ( V_7 , V_42 ,
V_43 , V_32 , V_129 ,
V_118 && V_109 ,
V_95 + V_117 ,
V_110 , V_83 ) ;
if ( V_114 ( V_7 , V_32 ) )
goto V_93;
if ( V_44 == '+' )
break;
}
if ( V_44 == '-' ) {
const int V_131 = V_128 + ( V_117 ? 2 : 1 ) ;
V_32 += F_82 ( V_7 , & V_42 -> V_41 ,
V_131 , V_32 , V_108 ,
V_42 -> V_132 ,
V_110 , V_83 , V_114 ) ;
}
if ( V_114 ( V_7 , V_32 ) )
break;
V_39 = V_59 ;
}
V_93:
return V_32 - V_115 ;
}
static int F_83 ( struct V_1 * V_7 ,
struct V_12 * V_133 , int V_128 ,
unsigned short V_32 ,
T_5 V_110 ,
struct V_96 * V_83 ,
T_6 V_114 )
{
T_4 V_108 = F_84 ( V_133 -> V_3 ) ;
T_4 V_113 ;
int V_106 ;
if ( V_5 . V_134 )
V_113 = V_133 -> V_135 -> V_136 ;
else
V_113 = V_133 -> V_137 . V_136 ;
if ( V_46 . V_47 == V_48 ) {
V_106 = F_79 ( V_7 ,
& V_133 -> V_52 , V_32 ,
V_108 , V_113 , V_110 , V_83 ,
V_114 ) ;
} else if ( V_46 . V_47 == V_49 ) {
V_106 = F_81 ( V_7 ,
& V_133 -> V_52 , V_32 ,
V_108 , V_113 , V_110 , V_83 ,
V_114 ) ;
} else {
V_106 = F_82 ( V_7 ,
& V_133 -> V_52 , V_128 , V_32 ,
V_108 , V_113 , V_110 , V_83 ,
V_114 ) ;
}
if ( V_83 -> V_104 )
V_7 -> V_65 = V_133 ;
return V_106 ;
}
static int F_85 ( struct V_138 * V_139 , const char * V_140 , ... )
{
struct V_141 * V_83 = V_139 -> V_142 ;
int V_143 , V_144 ;
T_7 args ;
double V_55 ;
va_start ( args , V_140 ) ;
V_144 = va_arg ( args , int ) ;
V_55 = va_arg ( args , double ) ;
va_end ( args ) ;
F_86 ( V_83 -> V_23 , V_55 , V_83 -> V_145 ) ;
V_143 = F_87 ( V_139 -> V_112 , V_139 -> V_73 , V_140 , V_144 , V_55 ) ;
F_68 ( V_83 -> V_23 , L_6 , V_139 -> V_112 ) ;
F_88 ( V_139 , V_143 ) ;
return V_143 ;
}
void F_89 ( void )
{
V_146 [ V_147 ] . V_97 =
V_148 ;
V_146 [ V_149 ] . V_97 =
V_150 ;
V_146 [ V_151 ] . V_97 =
V_152 ;
V_146 [ V_153 ] . V_97 =
V_154 ;
V_146 [ V_155 ] . V_97 =
V_156 ;
V_146 [ V_157 ] . V_97 =
V_158 ;
}
static int F_90 ( struct V_1 * V_7 ,
struct V_12 * V_133 ,
unsigned short V_32 )
{
int V_106 = 0 ;
int V_31 = V_7 -> V_23 . V_31 ;
char V_44 = ' ' ;
bool V_145 = F_65 ( & V_7 -> V_23 , V_32 ) ;
T_8 V_91 = V_133 -> V_91 ;
bool V_57 = true ;
struct V_159 * V_140 ;
if ( V_145 ) {
V_7 -> V_65 = V_133 ;
V_7 -> V_68 = & V_133 -> V_67 ;
}
if ( V_5 . V_160 ) {
F_41 ( V_133 ) ;
V_44 = F_20 ( V_133 ) ;
}
if ( V_91 == 0 ) {
struct V_141 V_83 = {
. V_23 = & V_7 -> V_23 ,
. V_44 = V_44 ,
. V_145 = V_145 ,
} ;
int V_33 = 0 ;
F_14 ( V_7 , V_32 , 0 ) ;
F_91 (browser->hists, fmt) {
char V_161 [ 2048 ] ;
struct V_138 V_139 = {
. V_112 = V_161 ,
. V_73 = sizeof( V_161 ) ,
. V_142 = & V_83 ,
} ;
if ( F_92 ( V_140 , V_133 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
if ( V_145 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_103 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_102 ) ;
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
if ( V_140 -> V_97 ) {
int V_143 = V_140 -> V_97 ( V_140 , & V_139 , V_133 ) ;
F_93 ( V_133 , & V_139 , V_140 , V_143 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 + V_143 ) ;
} else {
F_93 ( V_133 , & V_139 , V_140 , V_140 -> V_133 ( V_140 , & V_139 , V_133 ) ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 ) ;
}
V_31 -= V_139 . V_112 - V_161 ;
}
if ( ! V_7 -> V_23 . V_163 )
V_31 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_31 ) ;
++ V_32 ;
++ V_106 ;
} else
-- V_91 ;
if ( V_44 == '-' && V_32 != V_7 -> V_23 . V_27 ) {
struct V_96 V_83 = {
. V_91 = V_91 ,
. V_104 = V_145 ,
} ;
V_106 += F_83 ( V_7 , V_133 , 1 , V_32 ,
F_63 , & V_83 ,
F_71 ) ;
}
return V_106 ;
}
static int F_94 ( struct V_1 * V_7 ,
struct V_12 * V_133 ,
unsigned short V_32 ,
int V_128 )
{
int V_106 = 0 ;
int V_31 = V_7 -> V_23 . V_31 ;
char V_44 = ' ' ;
bool V_145 = F_65 ( & V_7 -> V_23 , V_32 ) ;
T_8 V_91 = V_133 -> V_91 ;
bool V_57 = true ;
struct V_159 * V_140 ;
struct V_164 * V_165 ;
struct V_141 V_83 = {
. V_23 = & V_7 -> V_23 ,
. V_145 = V_145 ,
} ;
int V_33 = 0 ;
int V_166 = ( V_133 -> V_3 -> V_167 - 2 ) * V_168 ;
if ( V_145 ) {
V_7 -> V_65 = V_133 ;
V_7 -> V_68 = & V_133 -> V_67 ;
}
F_41 ( V_133 ) ;
V_44 = F_20 ( V_133 ) ;
V_83 . V_44 = V_44 ;
if ( V_133 -> V_14 && V_91 ) {
V_91 -- ;
goto V_169;
}
F_14 ( V_7 , V_32 , 0 ) ;
if ( V_145 && V_7 -> V_23 . V_163 )
F_66 ( & V_7 -> V_23 , V_103 ) ;
else
F_66 ( & V_7 -> V_23 , V_102 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_128 * V_168 ) ;
V_31 -= V_128 * V_168 ;
V_165 = F_95 ( & V_133 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
char V_161 [ 2048 ] ;
struct V_138 V_139 = {
. V_112 = V_161 ,
. V_73 = sizeof( V_161 ) ,
. V_142 = & V_83 ,
} ;
if ( F_92 ( V_140 , V_133 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
if ( V_145 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_103 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_102 ) ;
}
if ( V_57 ) {
F_68 ( & V_7 -> V_23 , L_9 , V_44 ) ;
V_31 -- ;
V_57 = false ;
} else {
F_68 ( & V_7 -> V_23 , L_17 ) ;
V_31 -= 2 ;
}
if ( V_140 -> V_97 ) {
int V_143 = V_140 -> V_97 ( V_140 , & V_139 , V_133 ) ;
F_93 ( V_133 , & V_139 , V_140 , V_143 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 + V_143 ) ;
} else {
int V_143 = V_140 -> V_133 ( V_140 , & V_139 , V_133 ) ;
F_93 ( V_133 , & V_139 , V_140 , V_143 ) ;
F_68 ( & V_7 -> V_23 , L_6 , V_161 ) ;
}
V_31 -= V_139 . V_112 - V_161 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_166 ) ;
V_31 -= V_166 ;
if ( V_33 >= V_7 -> V_23 . V_162 ) {
char V_161 [ 2048 ] ;
struct V_138 V_139 = {
. V_112 = V_161 ,
. V_73 = sizeof( V_161 ) ,
. V_142 = & V_83 ,
} ;
if ( V_145 && V_7 -> V_23 . V_163 ) {
F_66 ( & V_7 -> V_23 ,
V_103 ) ;
} else {
F_66 ( & V_7 -> V_23 ,
V_102 ) ;
}
F_96 (entry->hpp_list, fmt) {
F_67 ( & V_7 -> V_23 , L_18 , 2 ) ;
V_31 -= 2 ;
if ( V_140 -> V_97 ) {
V_31 -= V_140 -> V_97 ( V_140 , & V_139 , V_133 ) ;
} else {
int V_171 = 0 ;
V_31 -= V_140 -> V_133 ( V_140 , & V_139 , V_133 ) ;
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
++ V_106 ;
V_169:
if ( V_133 -> V_14 && V_44 == '-' && V_32 != V_7 -> V_23 . V_27 ) {
struct V_96 V_172 = {
. V_91 = V_91 ,
} ;
V_106 += F_83 ( V_7 , V_133 ,
V_128 + 1 , V_32 ,
F_63 , & V_172 ,
F_71 ) ;
}
return V_106 ;
}
static int F_98 ( struct V_1 * V_7 ,
unsigned short V_32 , int V_128 )
{
int V_31 = V_7 -> V_23 . V_31 ;
bool V_145 = F_65 ( & V_7 -> V_23 , V_32 ) ;
bool V_57 = true ;
int V_33 = 0 ;
int V_143 ;
struct V_159 * V_140 ;
struct V_164 * V_165 ;
int V_173 = V_7 -> V_3 -> V_167 - 2 ;
if ( V_145 ) {
V_7 -> V_65 = NULL ;
V_7 -> V_68 = NULL ;
}
F_14 ( V_7 , V_32 , 0 ) ;
if ( V_145 && V_7 -> V_23 . V_163 )
F_66 ( & V_7 -> V_23 , V_103 ) ;
else
F_66 ( & V_7 -> V_23 , V_102 ) ;
F_67 ( & V_7 -> V_23 , L_18 , V_128 * V_168 ) ;
V_31 -= V_128 * V_168 ;
V_165 = F_95 ( & V_7 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( F_92 ( V_140 , V_7 -> V_3 ) ||
V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_143 = V_140 -> V_31 ( V_140 , NULL , V_7 -> V_3 ) ;
if ( V_57 ) {
V_57 = false ;
V_143 ++ ;
} else {
V_143 += 2 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_143 ) ;
V_31 -= V_143 ;
}
F_67 ( & V_7 -> V_23 , L_18 , V_173 * V_168 ) ;
V_31 -= V_173 * V_168 ;
if ( V_33 >= V_7 -> V_23 . V_162 ) {
char V_112 [ 32 ] ;
V_143 = snprintf ( V_112 , sizeof( V_112 ) , L_19 , V_7 -> V_4 ) ;
F_68 ( & V_7 -> V_23 , L_20 , V_112 ) ;
V_31 -= V_143 + 2 ;
}
if ( ! V_7 -> V_23 . V_163 )
V_31 += 1 ;
F_67 ( & V_7 -> V_23 , L_18 , V_31 ) ;
return 1 ;
}
static int F_99 ( struct V_138 * V_139 , int V_174 )
{
F_88 ( V_139 , V_174 ) ;
return V_139 -> V_73 <= 0 ;
}
static int F_100 ( struct V_1 * V_7 , char * V_112 , T_3 V_73 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_138 V_175 = {
. V_112 = V_112 ,
. V_73 = V_73 ,
} ;
struct V_159 * V_140 ;
T_3 V_143 = 0 ;
int V_33 = 0 ;
if ( V_5 . V_160 ) {
V_143 = F_87 ( V_112 , V_73 , L_17 ) ;
if ( F_99 ( & V_175 , V_143 ) )
return V_143 ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_140 , V_3 ) || V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_143 = V_140 -> V_176 ( V_140 , & V_175 , V_3 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
V_143 = F_87 ( V_175 . V_112 , V_175 . V_73 , L_17 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
}
return V_143 ;
}
static int F_101 ( struct V_1 * V_7 , char * V_112 , T_3 V_73 )
{
struct V_3 * V_3 = V_7 -> V_3 ;
struct V_138 V_175 = {
. V_112 = V_112 ,
. V_73 = V_73 ,
} ;
struct V_159 * V_140 ;
struct V_164 * V_165 ;
T_3 V_143 = 0 ;
int V_33 = 0 ;
int V_173 = V_3 -> V_167 - 2 ;
bool V_177 , V_178 ;
V_143 = F_87 ( V_112 , V_73 , L_8 ) ;
if ( F_99 ( & V_175 , V_143 ) )
return V_143 ;
V_165 = F_95 ( & V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( V_33 ++ < V_7 -> V_23 . V_162 )
continue;
V_143 = V_140 -> V_176 ( V_140 , & V_175 , V_3 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
V_143 = F_87 ( V_175 . V_112 , V_175 . V_73 , L_17 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
}
V_143 = F_87 ( V_175 . V_112 , V_175 . V_73 , L_21 ,
V_173 * V_168 , L_18 ) ;
if ( F_99 ( & V_175 , V_143 ) )
return V_143 ;
V_177 = true ;
F_102 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_177 ) {
V_143 = F_87 ( V_175 . V_112 , V_175 . V_73 , L_22 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
}
V_177 = false ;
V_178 = true ;
F_96 (&fmt_node->hpp, fmt) {
char * V_179 ;
if ( F_92 ( V_140 , V_3 ) )
continue;
if ( ! V_178 ) {
V_143 = F_87 ( V_175 . V_112 , V_175 . V_73 , L_23 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
}
V_178 = false ;
V_143 = V_140 -> V_176 ( V_140 , & V_175 , V_3 ) ;
V_175 . V_112 [ V_143 ] = '\0' ;
V_179 = F_103 ( V_175 . V_112 ) ;
V_143 = strlen ( V_179 ) ;
if ( V_179 != V_175 . V_112 )
memmove ( V_175 . V_112 , V_179 , V_143 + 1 ) ;
if ( F_99 ( & V_175 , V_143 ) )
break;
}
}
return V_143 ;
}
static void F_104 ( struct V_1 * V_7 )
{
char V_180 [ 1024 ] ;
F_101 ( V_7 , V_180 ,
sizeof( V_180 ) ) ;
F_15 ( & V_7 -> V_23 , 0 , 0 ) ;
F_66 ( & V_7 -> V_23 , V_181 ) ;
F_67 ( & V_7 -> V_23 , V_180 , V_7 -> V_23 . V_31 + 1 ) ;
}
static void F_105 ( struct V_1 * V_7 )
{
char V_180 [ 1024 ] ;
F_100 ( V_7 , V_180 ,
sizeof( V_180 ) ) ;
F_15 ( & V_7 -> V_23 , 0 , 0 ) ;
F_66 ( & V_7 -> V_23 , V_181 ) ;
F_67 ( & V_7 -> V_23 , V_180 , V_7 -> V_23 . V_31 + 1 ) ;
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
if ( V_7 -> V_90 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
V_7 -> V_90 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
}
}
static unsigned int F_108 ( struct V_22 * V_7 )
{
unsigned V_32 = 0 ;
T_2 V_24 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
if ( V_2 -> V_25 ) {
F_106 ( V_2 ) ;
V_24 = 1 ;
}
F_107 ( V_7 ) ;
V_2 -> V_65 = NULL ;
V_2 -> V_68 = NULL ;
for ( V_9 = V_7 -> V_90 ; V_9 ; V_9 = F_6 ( V_9 ) ) {
struct V_12 * V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 ;
if ( V_89 -> V_56 ) {
V_89 -> V_15 = false ;
continue;
}
V_55 = F_31 ( V_89 ) ;
if ( V_55 < V_2 -> V_4 )
continue;
if ( V_5 . V_18 ) {
V_32 += F_94 ( V_2 , V_89 , V_32 ,
V_89 -> V_71 ) ;
if ( V_32 == V_7 -> V_27 )
break;
if ( V_89 -> V_53 ) {
F_98 ( V_2 , V_32 , V_89 -> V_71 + 1 ) ;
V_32 ++ ;
}
} else {
V_32 += F_90 ( V_2 , V_89 , V_32 ) ;
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
struct V_12 * V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 = F_31 ( V_89 ) ;
if ( ! V_89 -> V_56 && V_55 >= V_4 )
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
struct V_12 * V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
float V_55 = F_31 ( V_89 ) ;
if ( ! V_89 -> V_56 && V_55 >= V_4 )
return V_9 ;
V_9 = F_110 ( V_9 ) ;
}
return NULL ;
}
static void F_111 ( struct V_22 * V_7 ,
T_8 V_95 , int V_182 )
{
struct V_12 * V_89 ;
struct V_8 * V_9 ;
bool V_57 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_23 ) ;
if ( V_7 -> V_17 == 0 )
return;
F_107 ( V_7 ) ;
switch ( V_182 ) {
case V_183 :
V_9 = F_5 ( F_4 ( V_7 -> V_11 ) ,
V_2 -> V_4 ) ;
break;
case V_184 :
V_9 = V_7 -> V_90 ;
goto V_185;
case V_186 :
V_9 = F_112 ( F_113 ( V_7 -> V_11 ) ) ;
V_9 = F_109 ( V_9 , V_2 -> V_4 ) ;
V_57 = false ;
break;
default:
return;
}
V_89 = F_7 ( V_7 -> V_90 , struct V_12 , V_8 ) ;
V_89 -> V_91 = 0 ;
V_185:
if ( ! V_9 )
return;
if ( V_95 > 0 ) {
do {
V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_89 -> V_15 && V_89 -> V_14 ) {
T_2 V_187 = V_89 -> V_16 - V_89 -> V_91 ;
if ( V_95 > V_187 ) {
V_95 -= V_187 ;
V_89 -> V_91 = 0 ;
} else {
V_89 -> V_91 += V_95 ;
V_95 = 0 ;
V_7 -> V_90 = V_9 ;
break;
}
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
-- V_95 ;
V_7 -> V_90 = V_9 ;
} while ( V_95 != 0 );
} else if ( V_95 < 0 ) {
while ( 1 ) {
V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_89 -> V_15 && V_89 -> V_14 ) {
if ( V_57 ) {
if ( - V_95 > V_89 -> V_91 ) {
V_95 += V_89 -> V_91 ;
V_89 -> V_91 = 0 ;
} else {
V_89 -> V_91 += V_95 ;
V_95 = 0 ;
V_7 -> V_90 = V_9 ;
break;
}
} else {
if ( - V_95 > V_89 -> V_16 ) {
V_95 += V_89 -> V_16 ;
V_89 -> V_91 = 0 ;
} else {
V_89 -> V_91 = V_89 -> V_16 + V_95 ;
V_95 = 0 ;
V_7 -> V_90 = V_9 ;
break;
}
}
}
V_9 = F_109 ( F_110 ( V_9 ) ,
V_2 -> V_4 ) ;
if ( V_9 == NULL )
break;
++ V_95 ;
V_7 -> V_90 = V_9 ;
if ( V_95 == 0 ) {
V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_89 -> V_15 && V_89 -> V_14 )
V_89 -> V_91 = V_89 -> V_16 ;
break;
}
V_57 = false ;
}
} else {
V_7 -> V_90 = V_9 ;
V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
V_89 -> V_91 = 0 ;
}
}
static int F_114 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_107 ,
int V_128 )
{
struct V_96 V_83 = {
. V_107 = V_107 ,
} ;
F_83 ( V_7 , V_13 , V_128 , 0 ,
F_70 , & V_83 ,
F_72 ) ;
return V_83 . V_106 ;
}
static int F_115 ( struct V_1 * V_7 ,
struct V_12 * V_13 , T_9 * V_107 )
{
char V_161 [ 8192 ] ;
int V_106 = 0 ;
char V_44 = ' ' ;
struct V_138 V_139 = {
. V_112 = V_161 ,
. V_73 = sizeof( V_161 ) ,
} ;
struct V_159 * V_140 ;
bool V_57 = true ;
int V_143 ;
if ( V_5 . V_160 ) {
V_44 = F_20 ( V_13 ) ;
V_106 += fprintf ( V_107 , L_16 , V_44 ) ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_140 , V_13 -> V_3 ) )
continue;
if ( ! V_57 ) {
V_143 = F_87 ( V_139 . V_112 , V_139 . V_73 , L_17 ) ;
F_88 ( & V_139 , V_143 ) ;
} else
V_57 = false ;
V_143 = V_140 -> V_133 ( V_140 , & V_139 , V_13 ) ;
V_143 = F_93 ( V_13 , & V_139 , V_140 , V_143 ) ;
F_88 ( & V_139 , V_143 ) ;
}
V_106 += fprintf ( V_107 , L_24 , V_161 ) ;
if ( V_44 == '-' )
V_106 += F_114 ( V_7 , V_13 , V_107 , 1 ) ;
return V_106 ;
}
static int F_116 ( struct V_1 * V_7 ,
struct V_12 * V_13 ,
T_9 * V_107 , int V_128 )
{
char V_161 [ 8192 ] ;
int V_106 = 0 ;
char V_44 = ' ' ;
struct V_138 V_139 = {
. V_112 = V_161 ,
. V_73 = sizeof( V_161 ) ,
} ;
struct V_159 * V_140 ;
struct V_164 * V_165 ;
bool V_57 = true ;
int V_143 ;
int V_166 = ( V_13 -> V_3 -> V_167 - 2 ) * V_168 ;
V_106 = fprintf ( V_107 , L_21 , V_128 * V_168 , L_18 ) ;
V_44 = F_20 ( V_13 ) ;
V_106 += fprintf ( V_107 , L_9 , V_44 ) ;
V_165 = F_95 ( & V_13 -> V_3 -> V_170 ,
struct V_164 , V_58 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( ! V_57 ) {
V_143 = F_87 ( V_139 . V_112 , V_139 . V_73 , L_17 ) ;
F_88 ( & V_139 , V_143 ) ;
} else
V_57 = false ;
V_143 = V_140 -> V_133 ( V_140 , & V_139 , V_13 ) ;
F_88 ( & V_139 , V_143 ) ;
}
V_143 = F_87 ( V_139 . V_112 , V_139 . V_73 , L_21 , V_166 , L_18 ) ;
F_88 ( & V_139 , V_143 ) ;
F_96 (he->hpp_list, fmt) {
V_143 = F_87 ( V_139 . V_112 , V_139 . V_73 , L_17 ) ;
F_88 ( & V_139 , V_143 ) ;
V_143 = V_140 -> V_133 ( V_140 , & V_139 , V_13 ) ;
F_88 ( & V_139 , V_143 ) ;
}
V_106 += fprintf ( V_107 , L_24 , F_117 ( V_161 ) ) ;
if ( V_13 -> V_14 && V_44 == '-' ) {
V_106 += F_114 ( V_7 , V_13 , V_107 ,
V_13 -> V_71 + 1 ) ;
}
return V_106 ;
}
static int F_118 ( struct V_1 * V_7 , T_9 * V_107 )
{
struct V_8 * V_9 = F_5 ( F_4 ( V_7 -> V_23 . V_11 ) ,
V_7 -> V_4 ) ;
int V_106 = 0 ;
while ( V_9 ) {
struct V_12 * V_89 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_5 . V_18 ) {
V_106 += F_116 ( V_7 ,
V_89 , V_107 ,
V_89 -> V_71 ) ;
} else {
V_106 += F_115 ( V_7 , V_89 , V_107 ) ;
}
V_9 = F_5 ( F_6 ( V_9 ) ,
V_7 -> V_4 ) ;
}
return V_106 ;
}
static int F_119 ( struct V_1 * V_7 )
{
char V_188 [ 64 ] ;
T_9 * V_107 ;
while ( 1 ) {
F_87 ( V_188 , sizeof( V_188 ) , L_25 , V_7 -> V_189 ) ;
if ( F_120 ( V_188 , V_190 ) )
break;
if ( ++ V_7 -> V_189 == 8192 ) {
F_61 ( L_26 ) ;
return - 1 ;
}
}
V_107 = fopen ( V_188 , L_27 ) ;
if ( V_107 == NULL ) {
char V_72 [ 64 ] ;
const char * V_191 = F_121 ( V_192 , V_72 , sizeof( V_72 ) ) ;
F_61 ( L_28 , V_188 , V_191 ) ;
return - 1 ;
}
++ V_7 -> V_189 ;
F_118 ( V_7 , V_107 ) ;
fclose ( V_107 ) ;
F_61 ( L_29 , V_188 ) ;
return 0 ;
}
void F_122 ( struct V_1 * V_7 ,
struct V_3 * V_3 )
{
struct V_159 * V_140 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_23 . V_80 = F_108 ;
V_7 -> V_23 . V_193 = F_10 ;
V_7 -> V_23 . V_194 = F_111 ;
V_7 -> V_23 . V_195 = true ;
V_7 -> V_25 = V_5 . V_196 ;
F_91 (hists, fmt) {
F_123 ( V_140 , V_3 ) ;
++ V_7 -> V_23 . V_197 ;
}
}
struct V_1 * F_124 ( struct V_3 * V_3 )
{
struct V_1 * V_7 = F_125 ( sizeof( * V_7 ) ) ;
if ( V_7 )
F_122 ( V_7 , V_3 ) ;
return V_7 ;
}
static struct V_1 *
F_126 ( struct V_198 * V_199 ,
struct V_77 * V_78 ,
struct V_200 * V_201 )
{
struct V_1 * V_7 = F_124 ( F_127 ( V_199 ) ) ;
if ( V_7 ) {
V_7 -> V_78 = V_78 ;
V_7 -> V_201 = V_201 ;
V_7 -> V_74 = V_202 ;
}
return V_7 ;
}
void F_128 ( struct V_1 * V_7 )
{
free ( V_7 ) ;
}
static struct V_12 * F_129 ( struct V_1 * V_7 )
{
return V_7 -> V_65 ;
}
static struct V_203 * F_130 ( struct V_1 * V_7 )
{
return V_7 -> V_65 -> V_203 ;
}
static inline bool F_131 ( void * V_82 )
{
return V_82 == NULL ;
}
static int V_202 ( struct V_1 * V_7 ,
char * V_72 , T_3 V_73 )
{
struct V_77 * V_78 = V_7 -> V_78 ;
struct V_3 * V_3 = V_7 -> V_3 ;
char V_204 ;
int V_106 ;
const struct V_205 * V_205 = V_3 -> V_206 ;
const struct V_203 * V_203 = V_3 -> V_207 ;
int V_208 = V_3 -> V_209 ;
unsigned long V_210 = V_3 -> V_84 . V_86 [ V_211 ] ;
T_4 V_86 = V_3 -> V_84 . V_212 ;
struct V_198 * V_199 = F_132 ( V_3 ) ;
const char * V_213 = F_133 ( V_199 ) ;
char V_112 [ 512 ] ;
T_3 V_214 = sizeof( V_112 ) ;
char V_215 [ 30 ] = L_30 ;
bool V_216 = false ;
if ( V_5 . V_217 ) {
V_210 = V_3 -> V_84 . V_218 ;
V_86 = V_3 -> V_84 . V_219 ;
}
if ( F_134 ( V_199 ) ) {
struct V_198 * V_220 ;
F_135 ( V_199 , V_112 , V_214 ) ;
V_213 = V_112 ;
F_136 (pos, evsel) {
struct V_3 * V_221 = F_127 ( V_220 ) ;
if ( V_5 . V_217 ) {
V_210 += V_221 -> V_84 . V_218 ;
V_86 += V_221 -> V_84 . V_219 ;
} else {
V_210 += V_221 -> V_84 . V_86 [ V_211 ] ;
V_86 += V_221 -> V_84 . V_212 ;
}
}
}
if ( V_5 . V_222 &&
strstr ( V_213 , L_31 ) )
V_216 = true ;
V_210 = F_137 ( V_210 , & V_204 ) ;
V_106 = F_87 ( V_72 , V_73 ,
L_32 V_223 ,
V_210 , V_204 , V_213 , V_216 ? V_215 : L_8 , V_86 ) ;
if ( V_3 -> V_224 )
V_106 += snprintf ( V_72 + V_106 , V_73 - V_106 ,
L_33 , V_3 -> V_224 ) ;
if ( V_203 ) {
if ( F_138 ( V_3 , V_203 ) ) {
V_106 += F_87 ( V_72 + V_106 , V_73 - V_106 ,
L_34 ,
( V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ) ,
V_203 -> V_226 ) ;
} else {
V_106 += F_87 ( V_72 + V_106 , V_73 - V_106 ,
L_35 ,
( V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ) ) ;
}
}
if ( V_205 )
V_106 += F_87 ( V_72 + V_106 , V_73 - V_106 ,
L_36 , V_205 -> V_227 ) ;
if ( V_208 > - 1 )
V_106 += F_87 ( V_72 + V_106 , V_73 - V_106 ,
L_37 , V_208 ) ;
if ( ! F_131 ( V_78 ) ) {
struct V_228 * V_90 = V_78 -> V_83 ;
if ( V_90 -> V_229 )
V_106 += F_87 ( V_72 + V_106 , V_73 - V_106 , L_38 ) ;
}
return V_106 ;
}
static inline void F_140 ( char * * V_230 , int V_40 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_40 ; ++ V_171 )
F_141 ( & V_230 [ V_171 ] ) ;
}
static int F_142 ( void )
{
char * V_231 , * V_230 [ 32 ] , * V_232 [ 32 ] , * V_233 ;
T_10 * V_234 ;
int V_235 = 0 , V_236 = - 1 , V_143 = - 1 ;
struct V_237 * V_238 ;
V_231 = getenv ( L_39 ) ;
if ( ! V_231 )
return V_143 ;
V_234 = F_143 ( V_231 ) ;
if ( ! V_234 )
return V_143 ;
memset ( V_230 , 0 , sizeof( V_230 ) ) ;
memset ( V_230 , 0 , sizeof( V_232 ) ) ;
while ( ( V_238 = F_144 ( V_234 ) ) ) {
char V_239 [ V_240 ] ;
T_4 V_241 ;
char * V_242 = V_238 -> V_243 ;
T_9 * V_244 ;
if ( ! ( V_238 -> V_245 == V_246 ) )
continue;
snprintf ( V_239 , sizeof( V_239 ) , L_40 , V_231 , V_242 ) ;
V_244 = fopen ( V_239 , L_41 ) ;
if ( ! V_244 )
continue;
if ( fread ( & V_241 , 1 , 8 , V_244 ) < 8 )
goto V_247;
if ( F_145 ( V_241 ) ) {
V_230 [ V_235 ] = F_146 ( V_242 ) ;
if ( ! V_230 [ V_235 ] )
goto V_247;
V_232 [ V_235 ] = F_146 ( V_239 ) ;
if ( ! V_232 [ V_235 ] ) {
F_141 ( & V_230 [ V_235 ] ) ;
F_147 ( L_42 ) ;
fclose ( V_244 ) ;
break;
}
V_235 ++ ;
}
V_247:
fclose ( V_244 ) ;
if ( V_235 >= 32 ) {
F_147 ( L_43
L_44 ) ;
break;
}
}
F_148 ( V_234 ) ;
if ( V_235 ) {
V_236 = F_149 ( V_235 , V_230 ) ;
if ( V_236 < V_235 && V_236 >= 0 ) {
V_233 = F_146 ( V_232 [ V_236 ] ) ;
if ( V_233 ) {
if ( V_248 )
free ( ( void * ) V_249 ) ;
V_249 = V_233 ;
V_248 = true ;
V_143 = 0 ;
} else
F_147 ( L_45 ) ;
}
}
F_140 ( V_230 , V_235 ) ;
F_140 ( V_232 , V_235 ) ;
return V_143 ;
}
static int
F_150 ( struct V_1 * V_7 , struct V_250 * V_251 )
{
struct V_198 * V_199 ;
struct V_252 * V_253 ;
struct V_12 * V_13 ;
int V_191 ;
if ( ! V_254 && F_151 ( V_7 -> V_201 ) )
return 0 ;
V_253 = F_64 ( V_251 -> V_67 . V_100 ) ;
if ( ! V_253 -> V_101 )
return 0 ;
V_199 = F_132 ( V_7 -> V_3 ) ;
V_191 = F_152 ( & V_251 -> V_67 , V_199 , V_7 -> V_78 ) ;
V_13 = F_129 ( V_7 ) ;
if ( ( V_191 == 'q' || V_191 == F_153 ( 'c' ) ) && V_13 -> V_255 )
return 1 ;
F_58 ( & V_7 -> V_23 , V_7 -> V_3 -> V_17 ) ;
if ( V_191 )
F_154 ( & V_7 -> V_23 ) ;
return 0 ;
}
static int
F_155 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 , char * * V_256 ,
struct V_257 * V_257 , struct V_258 * V_100 )
{
if ( V_100 == NULL || V_257 -> V_205 -> V_259 )
return 0 ;
if ( F_76 ( V_256 , L_46 , V_100 -> V_242 ) < 0 )
return 0 ;
V_251 -> V_67 . V_257 = V_257 ;
V_251 -> V_67 . V_100 = V_100 ;
V_251 -> V_260 = F_150 ;
return 1 ;
}
static int
F_156 ( struct V_1 * V_7 , struct V_250 * V_251 )
{
struct V_203 * V_203 = V_251 -> V_203 ;
if ( ( ! F_138 ( V_7 -> V_3 , V_203 ) &&
! F_138 ( V_7 -> V_3 , V_261 ) ) || V_203 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_207 ) {
F_157 ( V_7 -> V_262 , & V_7 -> V_3 -> V_207 ) ;
F_158 ( V_263 , false ) ;
F_159 ( V_7 -> V_3 -> V_207 ) ;
F_60 () ;
} else {
if ( F_138 ( V_7 -> V_3 , V_203 ) ) {
F_61 ( L_47 ,
V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ,
V_203 -> V_226 ) ;
} else {
F_61 ( L_48 ,
V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ) ;
}
V_7 -> V_3 -> V_207 = F_160 ( V_203 ) ;
F_158 ( V_263 , false ) ;
F_161 ( V_7 -> V_262 , & V_7 -> V_3 -> V_207 ) ;
}
F_162 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_163 ( struct V_1 * V_7 , struct V_250 * V_251 ,
char * * V_256 , struct V_203 * V_203 )
{
int V_143 ;
if ( ( ! F_138 ( V_7 -> V_3 , V_203 ) &&
! F_138 ( V_7 -> V_3 , V_261 ) ) || V_203 == NULL )
return 0 ;
if ( F_138 ( V_7 -> V_3 , V_203 ) ) {
V_143 = F_76 ( V_256 , L_49 ,
V_7 -> V_3 -> V_207 ? L_50 : L_51 ,
V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ,
V_203 -> V_226 ) ;
} else {
V_143 = F_76 ( V_256 , L_52 ,
V_7 -> V_3 -> V_207 ? L_50 : L_51 ,
V_203 -> V_225 ? F_139 ( V_203 ) : L_18 ) ;
}
if ( V_143 < 0 )
return 0 ;
V_251 -> V_203 = V_203 ;
V_251 -> V_260 = F_156 ;
return 1 ;
}
static int
F_164 ( struct V_1 * V_7 , struct V_250 * V_251 )
{
struct V_257 * V_257 = V_251 -> V_67 . V_257 ;
if ( ! F_138 ( V_7 -> V_3 , V_205 ) || V_257 == NULL )
return 0 ;
if ( V_7 -> V_3 -> V_206 ) {
F_157 ( V_7 -> V_262 , & V_7 -> V_3 -> V_206 ) ;
F_158 ( V_264 , false ) ;
V_7 -> V_3 -> V_206 = NULL ;
F_60 () ;
} else {
if ( V_257 == NULL )
return 0 ;
F_61 ( L_53 ,
F_165 ( V_257 ) ? L_54 : V_257 -> V_205 -> V_227 ) ;
V_7 -> V_3 -> V_206 = V_257 -> V_205 ;
F_158 ( V_264 , true ) ;
F_161 ( V_7 -> V_262 , & V_7 -> V_3 -> V_206 ) ;
}
F_166 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_167 ( struct V_1 * V_7 , struct V_250 * V_251 ,
char * * V_256 , struct V_257 * V_257 )
{
if ( ! F_138 ( V_7 -> V_3 , V_205 ) || V_257 == NULL )
return 0 ;
if ( F_76 ( V_256 , L_55 ,
V_7 -> V_3 -> V_206 ? L_50 : L_51 ,
F_165 ( V_257 ) ? L_54 : V_257 -> V_205 -> V_227 ) < 0 )
return 0 ;
V_251 -> V_67 . V_257 = V_257 ;
V_251 -> V_260 = F_164 ;
return 1 ;
}
static int
F_168 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 )
{
F_169 ( V_251 -> V_67 . V_257 ) ;
return 0 ;
}
static int
F_170 ( struct V_1 * V_7 ,
struct V_250 * V_251 , char * * V_256 , struct V_257 * V_257 )
{
if ( ! F_138 ( V_7 -> V_3 , V_205 ) || V_257 == NULL )
return 0 ;
if ( F_76 ( V_256 , L_56 ) < 0 )
return 0 ;
V_251 -> V_67 . V_257 = V_257 ;
V_251 -> V_260 = F_168 ;
return 1 ;
}
static int
F_171 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 )
{
char V_265 [ 64 ] ;
memset ( V_265 , 0 , sizeof( V_265 ) ) ;
if ( V_251 -> V_203 ) {
F_87 ( V_265 , sizeof( V_265 ) , L_57 ,
F_139 ( V_251 -> V_203 ) ) ;
} else if ( V_251 -> V_67 . V_100 ) {
F_87 ( V_265 , sizeof( V_265 ) , L_58 ,
V_251 -> V_67 . V_100 -> V_242 ) ;
}
F_172 ( V_265 ) ;
return 0 ;
}
static int
F_173 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 , char * * V_256 ,
struct V_203 * V_203 , struct V_258 * V_100 )
{
if ( V_203 ) {
if ( F_76 ( V_256 , L_59 ,
F_139 ( V_203 ) ) < 0 )
return 0 ;
} else if ( V_100 ) {
if ( F_76 ( V_256 , L_60 ,
V_100 -> V_242 ) < 0 )
return 0 ;
} else {
if ( F_76 ( V_256 , L_61 ) < 0 )
return 0 ;
}
V_251 -> V_203 = V_203 ;
V_251 -> V_67 . V_100 = V_100 ;
V_251 -> V_260 = F_171 ;
return 1 ;
}
static int
F_174 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 V_45 )
{
if ( F_142 () ) {
F_147 ( L_62
L_63 ) ;
return 0 ;
}
return V_266 ;
}
static int
F_175 ( struct V_1 * V_7 ,
struct V_250 * V_251 , char * * V_256 )
{
if ( ! F_131 ( V_7 -> V_78 ) )
return 0 ;
if ( F_76 ( V_256 , L_64 ) < 0 )
return 0 ;
V_251 -> V_260 = F_174 ;
return 1 ;
}
static int
F_176 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 V_45 )
{
return 0 ;
}
static int
F_177 ( struct V_1 * V_7 V_45 ,
struct V_250 * V_251 , char * * V_256 )
{
if ( F_76 ( V_256 , L_65 ) < 0 )
return 0 ;
V_251 -> V_260 = F_176 ;
return 1 ;
}
static int
F_178 ( struct V_1 * V_7 , struct V_250 * V_251 )
{
if ( ! F_138 ( V_7 -> V_3 , V_267 ) || V_251 -> V_267 < 0 )
return 0 ;
if ( V_7 -> V_3 -> V_209 > - 1 ) {
F_157 ( V_7 -> V_262 , & V_7 -> V_3 -> V_209 ) ;
V_7 -> V_3 -> V_209 = - 1 ;
F_158 ( V_268 , false ) ;
} else {
V_7 -> V_3 -> V_209 = V_251 -> V_267 ;
F_158 ( V_268 , true ) ;
F_161 ( V_7 -> V_262 , & V_7 -> V_3 -> V_209 ) ;
}
F_179 ( V_7 -> V_3 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int
F_180 ( struct V_1 * V_7 , struct V_250 * V_251 ,
char * * V_256 , int V_208 )
{
if ( ! F_138 ( V_7 -> V_3 , V_267 ) || V_208 < 0 )
return 0 ;
if ( F_76 ( V_256 , L_66 ,
( V_7 -> V_3 -> V_209 > - 1 ) ? L_50 : L_51 ,
V_208 ) < 0 )
return 0 ;
V_251 -> V_267 = V_208 ;
V_251 -> V_260 = F_178 ;
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
double V_55 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 = F_4 ( & V_2 -> V_3 -> V_11 ) ;
T_4 V_108 = F_84 ( V_2 -> V_3 ) ;
T_4 V_269 = V_108 * ( V_55 / 100 ) ;
V_2 -> V_4 = V_46 . V_270 = V_55 ;
while ( ( V_9 = F_5 ( V_9 , V_2 -> V_4 ) ) != NULL ) {
V_13 = F_7 ( V_9 , struct V_12 , V_8 ) ;
if ( V_13 -> V_53 ) {
V_13 -> V_53 = false ;
V_13 -> V_16 = 0 ;
}
if ( ! V_13 -> V_14 || ! V_5 . V_160 )
goto V_59;
if ( V_46 . V_47 == V_130 ) {
V_108 = V_13 -> V_137 . V_136 ;
if ( V_5 . V_134 )
V_108 = V_13 -> V_135 -> V_136 ;
V_269 = V_108 * ( V_55 / 100 ) ;
}
V_46 . V_271 ( & V_13 -> V_52 , V_13 -> V_272 ,
V_269 , & V_46 ) ;
V_59:
V_9 = F_49 ( V_9 , V_70 ) ;
V_13 -> V_64 = false ;
F_47 ( V_13 , V_2 , false ) ;
}
}
static int F_182 ( struct V_198 * V_199 , int V_86 ,
const char * V_273 ,
bool V_274 ,
struct V_77 * V_78 ,
float V_4 ,
struct V_200 * V_201 )
{
struct V_3 * V_3 = F_127 ( V_199 ) ;
struct V_1 * V_7 = F_126 ( V_199 , V_78 , V_201 ) ;
struct V_255 * V_275 ;
#define F_183 16
char * V_230 [ F_183 ] ;
struct V_250 V_276 [ F_183 ] ;
int V_235 = 0 ;
int V_76 = - 1 ;
char V_112 [ 64 ] ;
int V_79 = V_78 ? V_78 -> V_80 : 0 ;
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
const char V_277 [] = F_184
L_67
L_68
L_69
L_70
L_71
L_72
L_73 ;
const char V_278 [] = F_184
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
V_7 -> V_262 = F_187 ( 3 ) ;
if ( V_7 -> V_262 == NULL )
goto V_93;
F_188 ( V_273 ) ;
memset ( V_230 , 0 , sizeof( V_230 ) ) ;
memset ( V_276 , 0 , sizeof( V_276 ) ) ;
if ( V_5 . V_279 )
F_189 ( V_5 . V_279 ) ;
while ( 1 ) {
struct V_203 * V_203 = NULL ;
struct V_257 * V_257 = NULL ;
int V_236 = 0 ;
int V_280 = - 1 ;
V_235 = 0 ;
V_76 = F_55 ( V_7 , V_273 ) ;
if ( V_7 -> V_65 != NULL ) {
V_203 = F_130 ( V_7 ) ;
V_257 = V_7 -> V_68 -> V_257 ;
V_280 = V_7 -> V_65 -> V_267 ;
}
switch ( V_76 ) {
case V_281 :
case V_282 :
if ( V_86 == 1 )
continue;
goto V_283;
case 'a' :
if ( ! F_138 ( V_3 , V_100 ) ) {
F_53 ( & V_7 -> V_23 , V_79 * 2 ,
L_76
L_77 ) ;
continue;
}
if ( V_7 -> V_68 == NULL ||
V_7 -> V_68 -> V_100 == NULL ||
V_7 -> V_68 -> V_257 -> V_205 -> V_259 )
continue;
V_276 -> V_67 . V_257 = V_7 -> V_68 -> V_257 ;
V_276 -> V_67 . V_100 = V_7 -> V_68 -> V_100 ;
F_150 ( V_7 , V_276 ) ;
continue;
case 'P' :
F_119 ( V_7 ) ;
continue;
case 'd' :
V_276 -> V_67 . V_257 = V_257 ;
F_164 ( V_7 , V_276 ) ;
continue;
case 'V' :
V_7 -> V_99 = ! V_7 -> V_99 ;
continue;
case 't' :
V_276 -> V_203 = V_203 ;
F_156 ( V_7 , V_276 ) ;
continue;
case 'S' :
V_276 -> V_267 = V_280 ;
F_178 ( V_7 , V_276 ) ;
continue;
case '/' :
if ( F_190 ( L_78 ,
L_79
L_80 ,
V_112 , L_81 ,
V_79 * 2 ) == V_92 ) {
V_3 -> V_284 = * V_112 ? V_112 : NULL ;
F_191 ( V_3 ) ;
F_16 ( V_7 ) ;
}
continue;
case 'r' :
if ( F_131 ( V_78 ) ) {
V_276 -> V_203 = NULL ;
V_276 -> V_67 . V_100 = NULL ;
F_171 ( V_7 , V_276 ) ;
}
continue;
case 's' :
if ( F_131 ( V_78 ) ) {
V_76 = F_174 ( V_7 , V_276 ) ;
if ( V_76 == V_266 )
goto V_283;
}
continue;
case 'i' :
if ( V_201 -> V_285 )
F_192 ( V_201 ) ;
continue;
case 'F' :
V_5 . V_217 ^= 1 ;
continue;
case 'z' :
if ( ! F_131 ( V_78 ) ) {
struct V_228 * V_90 = V_78 -> V_83 ;
V_90 -> V_229 = ! V_90 -> V_229 ;
}
continue;
case 'L' :
if ( F_190 ( L_82 ,
L_83 ,
V_112 , L_81 ,
V_79 * 2 ) == V_92 ) {
char * V_286 ;
double V_287 = strtod ( V_112 , & V_286 ) ;
if ( V_287 < 0 || V_287 > 100 ) {
F_53 ( & V_7 -> V_23 , V_79 * 2 ,
L_84 , V_287 ) ;
continue;
}
F_181 ( V_7 , V_287 ) ;
F_16 ( V_7 ) ;
}
continue;
case V_288 :
case 'h' :
case '?' :
F_193 ( & V_7 -> V_23 ,
F_131 ( V_78 ) ? V_277 : V_278 ) ;
continue;
case V_92 :
case V_289 :
case 'm' :
break;
case V_290 :
case V_291 : {
const void * V_90 ;
if ( F_194 ( V_7 -> V_262 ) ) {
if ( V_274 )
goto V_283;
if ( V_76 == V_290 &&
F_195 ( & V_7 -> V_23 ,
L_85 ) )
goto V_283;
continue;
}
V_90 = F_196 ( V_7 -> V_262 ) ;
if ( V_90 == & V_7 -> V_3 -> V_206 ) {
F_164 ( V_7 , V_276 ) ;
} else if ( V_90 == & V_7 -> V_3 -> V_207 ) {
F_156 ( V_7 , V_276 ) ;
} else if ( V_90 == & V_7 -> V_3 -> V_209 ) {
F_178 ( V_7 , V_276 ) ;
}
continue;
}
case 'q' :
case F_153 ( 'c' ) :
goto V_283;
case 'f' :
if ( ! F_131 ( V_78 ) ) {
struct V_228 * V_90 = V_78 -> V_83 ;
F_197 ( V_90 -> V_292 ) ;
if ( V_90 -> V_292 -> V_293 ) {
V_273 = L_86 ;
V_78 -> V_80 = V_79 ;
} else {
V_273 = L_87 ;
V_78 -> V_80 = 0 ;
}
continue;
}
default:
V_273 = L_88 ;
continue;
}
if ( ! F_138 ( V_3 , V_100 ) || V_7 -> V_68 == NULL )
goto V_294;
if ( V_295 == V_296 ) {
V_275 = V_7 -> V_65 -> V_255 ;
if ( V_275 == NULL )
goto V_294;
V_235 += F_155 ( V_7 ,
& V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_275 -> V_297 . V_257 ,
V_275 -> V_297 . V_100 ) ;
if ( V_275 -> V_298 . V_100 != V_275 -> V_297 . V_100 )
V_235 += F_155 ( V_7 ,
& V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_275 -> V_298 . V_257 ,
V_275 -> V_298 . V_100 ) ;
} else {
V_235 += F_155 ( V_7 ,
& V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_7 -> V_68 -> V_257 ,
V_7 -> V_68 -> V_100 ) ;
}
V_294:
V_235 += F_163 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] , V_203 ) ;
V_235 += F_167 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] , V_257 ) ;
V_235 += F_170 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_7 -> V_68 ?
V_7 -> V_68 -> V_257 : NULL ) ;
V_235 += F_180 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_280 ) ;
if ( ! F_131 ( V_78 ) )
goto V_299;
if ( V_7 -> V_65 ) {
if ( F_138 ( V_3 , V_203 ) && V_203 ) {
V_235 += F_173 ( V_7 ,
& V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
V_203 , NULL ) ;
}
if ( F_138 ( V_3 , V_100 ) && V_7 -> V_68 -> V_100 ) {
V_235 += F_173 ( V_7 ,
& V_276 [ V_235 ] ,
& V_230 [ V_235 ] ,
NULL , V_7 -> V_68 -> V_100 ) ;
}
}
V_235 += F_173 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] , NULL , NULL ) ;
V_235 += F_175 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] ) ;
V_299:
V_235 += F_177 ( V_7 , & V_276 [ V_235 ] ,
& V_230 [ V_235 ] ) ;
do {
struct V_250 * V_251 ;
V_236 = F_149 ( V_235 , V_230 ) ;
if ( V_236 == - 1 || V_236 >= V_235 )
break;
V_251 = & V_276 [ V_236 ] ;
V_76 = V_251 -> V_260 ( V_7 , V_251 ) ;
} while ( V_76 == 1 );
if ( V_76 == V_266 )
break;
}
V_283:
F_198 ( V_7 -> V_262 ) ;
V_93:
F_128 ( V_7 ) ;
F_140 ( V_230 , F_183 ) ;
return V_76 ;
}
static void F_199 ( struct V_22 * V_7 ,
void * V_133 , int V_32 )
{
struct V_300 * V_301 = F_11 ( V_7 ,
struct V_300 , V_23 ) ;
struct V_198 * V_199 = F_37 ( V_133 , struct V_198 , V_39 ) ;
struct V_3 * V_3 = F_127 ( V_199 ) ;
bool V_145 = F_65 ( V_7 , V_32 ) ;
unsigned long V_86 = V_3 -> V_84 . V_86 [ V_211 ] ;
const char * V_213 = F_133 ( V_199 ) ;
char V_72 [ 256 ] , V_204 ;
const char * V_302 = L_8 ;
T_3 V_106 ;
F_66 ( V_7 , V_145 ? V_103 :
V_102 ) ;
if ( F_134 ( V_199 ) ) {
struct V_198 * V_220 ;
V_213 = F_200 ( V_199 ) ;
F_136 (pos, evsel) {
struct V_3 * V_221 = F_127 ( V_220 ) ;
V_86 += V_221 -> V_84 . V_86 [ V_211 ] ;
}
}
V_86 = F_137 ( V_86 , & V_204 ) ;
V_106 = F_87 ( V_72 , sizeof( V_72 ) , L_89 , V_86 ,
V_204 , V_204 == ' ' ? L_18 : L_8 , V_213 ) ;
F_68 ( V_7 , L_6 , V_72 ) ;
V_86 = V_3 -> V_84 . V_86 [ V_87 ] ;
if ( V_86 != 0 ) {
V_301 -> V_303 = true ;
if ( ! V_145 )
F_66 ( V_7 , V_304 ) ;
V_86 = F_137 ( V_86 , & V_204 ) ;
V_106 += F_87 ( V_72 , sizeof( V_72 ) , L_90 ,
V_86 , V_204 , V_204 == ' ' ? L_18 : L_8 ) ;
V_302 = V_72 ;
}
F_67 ( V_7 , V_302 , V_7 -> V_31 - V_106 ) ;
if ( V_145 )
V_301 -> V_68 = V_199 ;
}
static int F_201 ( struct V_300 * V_301 ,
int V_86 , const char * V_75 ,
struct V_77 * V_78 )
{
struct V_305 * V_292 = V_301 -> V_23 . V_306 ;
struct V_198 * V_220 ;
const char * V_74 = L_91 ;
int V_79 = V_78 ? V_78 -> V_80 : 0 ;
int V_76 ;
if ( F_56 ( & V_301 -> V_23 , V_74 ,
L_92 ) < 0 )
return - 1 ;
while ( 1 ) {
V_76 = F_57 ( & V_301 -> V_23 , V_79 ) ;
switch ( V_76 ) {
case V_81 :
V_78 -> V_82 ( V_78 -> V_83 ) ;
if ( ! V_301 -> V_307 && V_301 -> V_303 ) {
F_52 ( & V_301 -> V_23 ) ;
V_301 -> V_307 = true ;
}
continue;
case V_289 :
case V_92 :
if ( ! V_301 -> V_68 )
continue;
V_220 = V_301 -> V_68 ;
V_308:
F_202 ( V_292 , V_220 ) ;
if ( V_78 )
V_78 -> V_82 ( V_78 -> V_83 ) ;
V_76 = F_182 ( V_220 , V_86 , V_75 ,
true , V_78 ,
V_301 -> V_4 ,
V_301 -> V_201 ) ;
F_59 ( & V_301 -> V_23 , V_74 ) ;
switch ( V_76 ) {
case V_281 :
if ( V_220 -> V_39 . V_59 == & V_292 -> V_11 )
V_220 = F_203 ( V_292 ) ;
else
V_220 = F_204 ( V_220 ) ;
goto V_308;
case V_282 :
if ( V_220 -> V_39 . V_62 == & V_292 -> V_11 )
V_220 = F_205 ( V_292 ) ;
else
V_220 = F_206 ( V_220 ) ;
goto V_308;
case V_266 :
case 'q' :
case F_153 ( 'c' ) :
goto V_93;
case V_290 :
default:
continue;
}
case V_291 :
continue;
case V_290 :
if ( ! F_195 ( & V_301 -> V_23 ,
L_85 ) )
continue;
case 'q' :
case F_153 ( 'c' ) :
goto V_93;
default:
continue;
}
}
V_93:
F_62 ( & V_301 -> V_23 ) ;
return V_76 ;
}
static bool F_207 ( struct V_22 * V_7 V_45 ,
void * V_133 )
{
struct V_198 * V_199 = F_37 ( V_133 , struct V_198 , V_39 ) ;
if ( V_5 . V_309 && ! F_208 ( V_199 ) )
return true ;
return false ;
}
static int F_209 ( struct V_305 * V_292 ,
int V_17 , const char * V_75 ,
struct V_77 * V_78 ,
float V_4 ,
struct V_200 * V_201 )
{
struct V_198 * V_220 ;
struct V_300 V_301 = {
. V_23 = {
. V_11 = & V_292 -> V_11 ,
. V_80 = V_310 ,
. V_194 = V_311 ,
. V_312 = F_199 ,
. V_313 = F_207 ,
. V_17 = V_17 ,
. V_306 = V_292 ,
} ,
. V_4 = V_4 ,
. V_201 = V_201 ,
} ;
F_188 ( L_93 ) ;
F_210 (evlist, pos) {
const char * V_213 = F_133 ( V_220 ) ;
T_3 V_314 = strlen ( V_213 ) + 7 ;
if ( V_301 . V_23 . V_31 < V_314 )
V_301 . V_23 . V_31 = V_314 ;
}
return F_201 ( & V_301 , V_17 , V_75 , V_78 ) ;
}
int F_211 ( struct V_305 * V_292 , const char * V_75 ,
struct V_77 * V_78 ,
float V_4 ,
struct V_200 * V_201 )
{
int V_17 = V_292 -> V_17 ;
V_315:
if ( V_17 == 1 ) {
struct V_198 * V_57 = F_203 ( V_292 ) ;
return F_182 ( V_57 , V_17 , V_75 ,
false , V_78 , V_4 ,
V_201 ) ;
}
if ( V_5 . V_309 ) {
struct V_198 * V_220 ;
V_17 = 0 ;
F_210 (evlist, pos) {
if ( F_208 ( V_220 ) )
V_17 ++ ;
}
if ( V_17 == 1 )
goto V_315;
}
return F_209 ( V_292 , V_17 , V_75 ,
V_78 , V_4 , V_201 ) ;
}
