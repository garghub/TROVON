static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) || V_2 -> V_4 || V_5 . V_6 || V_2 -> V_7 ;
}
static int F_3 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
struct V_3 * V_3 = V_8 -> V_3 ;
int V_11 = 0 ;
for ( V_10 = F_4 ( & V_3 -> V_12 ) ;
( V_10 = F_5 ( V_10 , V_8 -> V_4 ) ) != NULL ;
V_10 = F_6 ( V_10 ) ) {
struct V_13 * V_14 =
F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_14 -> V_15 && V_14 -> V_16 )
V_11 += V_14 -> V_17 ;
}
return V_11 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_18 ;
if ( V_5 . V_19 )
V_18 = V_2 -> V_20 ;
else if ( F_1 ( V_2 ) )
V_18 = V_2 -> V_21 ;
else
V_18 = V_2 -> V_3 -> V_18 ;
V_2 -> V_22 = F_3 ( V_2 ) ;
return V_18 + V_2 -> V_22 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_23 * V_8 = & V_2 -> V_24 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_25 * V_26 = V_3 -> V_26 ;
T_2 V_27 , V_28 ;
V_27 = V_2 -> V_29 ? V_26 -> V_30 : 0 ;
V_8 -> V_31 = V_8 -> V_32 - V_27 ;
V_28 = V_8 -> V_33 - V_8 -> V_34 ;
if ( V_28 >= V_8 -> V_31 )
V_8 -> V_33 -= V_28 - V_8 -> V_31 + 1 ;
}
static void F_10 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
V_8 -> V_35 = 3 + ( F_12 ( V_2 -> V_3 ) + sizeof( L_1 ) ) ;
F_13 ( V_8 ) ;
F_9 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_8 , int V_36 , int V_37 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_25 * V_26 = V_3 -> V_26 ;
T_2 V_27 ;
V_27 = V_8 -> V_29 ? V_26 -> V_30 : 0 ;
F_15 ( & V_8 -> V_24 , V_36 + V_27 , V_37 ) ;
}
static void F_16 ( struct V_1 * V_8 )
{
V_8 -> V_22 = 0 ;
F_17 ( V_8 ) ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
F_10 ( & V_8 -> V_24 ) ;
F_18 ( & V_8 -> V_24 ) ;
}
static char F_19 ( bool V_16 )
{
return V_16 ? '-' : '+' ;
}
static char F_20 ( const struct V_13 * V_14 )
{
return V_14 -> V_38 ? F_19 ( V_14 -> V_16 ) : ' ' ;
}
static char F_21 ( const struct V_39 * V_40 )
{
return V_40 -> V_38 ? F_19 ( V_40 -> V_16 ) : ' ' ;
}
static void F_22 ( struct V_39 * V_40 , bool V_41 )
{
V_40 -> V_16 = V_41 ? V_40 -> V_38 : false ;
}
static struct V_42 * F_23 ( struct V_43 * V_43 , T_3 V_44 )
{
struct V_45 * V_45 ;
struct V_42 * V_46 ;
if ( V_43 == NULL )
return NULL ;
V_45 = V_43 -> V_45 ;
if ( V_45 == NULL )
return NULL ;
if ( V_45 -> V_47 != V_48 )
return NULL ;
V_46 = F_24 ( V_45 ,
F_25 ( V_43 , V_44 ) ) ;
return V_46 ;
}
static int F_26 ( struct V_42 * V_46 )
{
struct V_49 * V_50 ;
int V_51 = 0 ;
if ( V_46 == NULL )
return 0 ;
F_27 (ilist, &node->val, list) {
if ( ( V_50 -> V_52 != NULL ) || ( V_50 -> V_53 != NULL ) )
V_51 ++ ;
}
return V_51 ;
}
static int F_28 ( struct V_39 * V_54 )
{
struct V_42 * V_46 ;
int V_31 ;
V_46 = F_23 ( V_54 -> V_55 . V_43 , V_54 -> V_44 ) ;
if ( V_46 == NULL )
return 0 ;
V_31 = F_26 ( V_46 ) ;
F_29 ( V_46 ) ;
return V_31 ;
}
static int F_30 ( struct V_56 * V_46 )
{
int V_57 = 0 , V_58 ;
struct V_9 * V_10 ;
for ( V_10 = F_4 ( & V_46 -> V_59 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_60 = F_7 ( V_10 , struct V_56 , V_9 ) ;
struct V_39 * V_54 ;
char V_61 = ' ' ;
F_27 (chain, &child->val, list) {
++ V_57 ;
if ( V_5 . V_62 ) {
V_58 =
F_28 ( V_54 ) ;
V_57 += V_58 ;
}
V_61 = F_21 ( V_54 ) ;
if ( V_61 == '+' )
break;
}
if ( V_61 == '-' )
V_57 += F_30 ( V_60 ) ;
}
return V_57 ;
}
static int F_32 ( struct V_56 * V_46 )
{
struct V_39 * V_54 ;
char V_61 = 0 ;
int V_57 = 0 ;
F_27 (chain, &node->parent_val, list) {
if ( ! V_61 ) {
V_61 = F_21 ( V_54 ) ;
if ( V_61 == '+' )
return 1 ;
}
V_57 ++ ;
}
F_27 (chain, &node->val, list) {
if ( ! V_61 ) {
V_61 = F_21 ( V_54 ) ;
if ( V_61 == '+' )
return 1 ;
}
V_57 ++ ;
}
return V_57 ;
}
static int F_33 ( struct V_56 * V_46 V_63 )
{
return 1 ;
}
static int F_34 ( struct V_56 * V_46 )
{
struct V_39 * V_54 ;
bool V_16 = false ;
int V_57 = 0 , V_58 ;
if ( V_64 . V_65 == V_66 )
return F_32 ( V_46 ) ;
else if ( V_64 . V_65 == V_67 )
return F_33 ( V_46 ) ;
F_27 (chain, &node->val, list) {
++ V_57 ;
if ( V_5 . V_62 ) {
V_58 = F_28 ( V_54 ) ;
V_57 += V_58 ;
}
V_16 = V_54 -> V_16 ;
}
if ( V_16 )
V_57 += F_30 ( V_46 ) ;
return V_57 ;
}
static int F_35 ( struct V_59 * V_54 )
{
struct V_9 * V_10 ;
int V_57 = 0 ;
for ( V_10 = F_4 ( V_54 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_46 = F_7 ( V_10 , struct V_56 , V_9 ) ;
V_57 += F_34 ( V_46 ) ;
}
return V_57 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_13 * V_14 ,
bool V_68 )
{
int V_69 = 0 ;
struct V_9 * V_46 ;
struct V_13 * V_60 ;
if ( V_14 -> V_15 )
return F_35 ( & V_14 -> V_70 ) ;
if ( V_14 -> V_71 )
return 1 ;
V_46 = F_4 ( & V_14 -> V_72 ) ;
while ( V_46 ) {
float V_73 ;
V_60 = F_7 ( V_46 , struct V_13 , V_9 ) ;
V_73 = F_37 ( V_60 ) ;
if ( ! V_60 -> V_74 && V_73 >= V_2 -> V_4 ) {
V_69 ++ ;
if ( V_68 && V_60 -> V_16 )
V_69 += F_36 ( V_2 , V_60 , true ) ;
}
V_46 = F_31 ( V_46 ) ;
}
return V_69 ;
}
static bool F_38 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return false ;
if ( ! V_14 -> V_38 )
return false ;
V_14 -> V_16 = ! V_14 -> V_16 ;
return true ;
}
static bool F_39 ( struct V_39 * V_40 )
{
if ( ! V_40 )
return false ;
if ( ! V_40 -> V_38 )
return false ;
V_40 -> V_16 = ! V_40 -> V_16 ;
return true ;
}
static void F_40 ( struct V_56 * V_46 )
{
struct V_9 * V_10 = F_4 ( & V_46 -> V_59 ) ;
for ( V_10 = F_4 ( & V_46 -> V_59 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_60 = F_7 ( V_10 , struct V_56 , V_9 ) ;
struct V_39 * V_54 ;
bool V_75 = true ;
F_27 (chain, &child->val, list) {
if ( V_75 ) {
V_75 = false ;
V_54 -> V_38 = V_54 -> V_76 . V_77 != & V_60 -> V_78 ||
! F_41 ( & V_60 -> V_59 ) ;
} else
V_54 -> V_38 = V_54 -> V_76 . V_77 == & V_60 -> V_78 &&
! F_41 ( & V_60 -> V_59 ) ;
}
F_40 ( V_60 ) ;
}
}
static void F_42 ( struct V_56 * V_46 ,
bool V_79 )
{
struct V_39 * V_54 ;
V_54 = F_43 ( V_46 -> V_78 . V_77 , struct V_39 , V_76 ) ;
V_54 -> V_38 = V_79 ;
if ( ! F_44 ( & V_46 -> V_78 ) ) {
V_54 = F_43 ( V_46 -> V_78 . V_80 , struct V_39 , V_76 ) ;
V_54 -> V_38 = ! F_41 ( & V_46 -> V_59 ) ;
}
F_40 ( V_46 ) ;
}
static void F_45 ( struct V_59 * V_81 )
{
struct V_9 * V_10 = F_4 ( V_81 ) ;
bool V_79 = V_10 && F_31 ( V_10 ) ;
for ( V_10 = F_4 ( V_81 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_46 = F_7 ( V_10 , struct V_56 , V_9 ) ;
F_42 ( V_46 , V_79 ) ;
if ( V_64 . V_65 == V_66 ||
V_64 . V_65 == V_67 )
F_46 ( V_46 ) ;
}
}
static void F_47 ( struct V_13 * V_14 )
{
if ( V_14 -> V_82 )
return;
if ( V_14 -> V_15 ) {
V_14 -> V_38 = ! F_41 ( & V_14 -> V_70 ) ;
F_45 ( & V_14 -> V_70 ) ;
} else {
V_14 -> V_38 = ! F_41 ( & V_14 -> V_72 ) ;
}
V_14 -> V_82 = true ;
}
static void F_48 ( struct V_13 * V_14 )
{
if ( V_14 -> V_42 )
return;
V_14 -> V_42 = F_23 ( V_14 -> V_55 . V_43 , V_14 -> V_44 ) ;
if ( V_14 -> V_42 == NULL )
return;
V_14 -> V_38 = true ;
}
static bool F_49 ( struct V_1 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_83 ;
struct V_84 * V_55 = V_8 -> V_85 ;
struct V_39 * V_40 = F_11 ( V_55 , struct V_39 , V_55 ) ;
bool V_38 ;
if ( ! V_14 || ! V_55 )
return false ;
if ( V_55 == & V_14 -> V_55 )
V_38 = F_38 ( V_14 ) ;
else
V_38 = F_39 ( V_40 ) ;
if ( V_38 ) {
int V_86 = 0 ;
F_47 ( V_14 ) ;
V_8 -> V_24 . V_18 -= V_14 -> V_17 ;
if ( V_14 -> V_15 )
V_8 -> V_22 -= V_14 -> V_17 ;
else
V_8 -> V_20 -= V_14 -> V_17 ;
if ( V_5 . V_19 )
V_86 = F_36 ( V_8 , V_14 , true ) ;
if ( V_14 -> V_16 ) {
if ( V_14 -> V_15 )
if ( V_14 -> V_42 )
V_14 -> V_17 = F_26 (
V_14 -> V_42 ) ;
else
V_14 -> V_17 = F_35 (
& V_14 -> V_70 ) ;
else
V_14 -> V_17 = F_36 ( V_8 , V_14 , false ) ;
if ( V_5 . V_19 )
V_8 -> V_24 . V_18 += V_86 - V_14 -> V_17 ;
if ( ! V_14 -> V_15 && V_14 -> V_17 == 0 ) {
V_14 -> V_71 = true ;
V_14 -> V_17 = 1 ;
}
} else {
if ( V_5 . V_19 )
V_8 -> V_24 . V_18 -= V_86 - V_14 -> V_17 ;
if ( V_14 -> V_71 )
V_14 -> V_71 = false ;
V_14 -> V_17 = 0 ;
}
V_8 -> V_24 . V_18 += V_14 -> V_17 ;
if ( V_14 -> V_15 )
V_8 -> V_22 += V_14 -> V_17 ;
else
V_8 -> V_20 += V_14 -> V_17 ;
return true ;
}
return false ;
}
static int F_50 ( struct V_56 * V_46 , bool V_41 )
{
int V_57 = 0 ;
struct V_9 * V_10 ;
for ( V_10 = F_4 ( & V_46 -> V_59 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_60 = F_7 ( V_10 , struct V_56 , V_9 ) ;
struct V_39 * V_54 ;
bool V_38 = false ;
F_27 (chain, &child->val, list) {
++ V_57 ;
F_22 ( V_54 , V_41 ) ;
V_38 = V_54 -> V_38 ;
}
if ( V_38 )
V_57 += F_50 ( V_60 , V_41 ) ;
}
return V_57 ;
}
static int F_51 ( struct V_56 * V_46 , bool V_41 )
{
struct V_39 * V_54 ;
bool V_38 = false ;
int V_57 = 0 ;
F_27 (chain, &node->val, list) {
++ V_57 ;
F_22 ( V_54 , V_41 ) ;
V_38 = V_54 -> V_38 ;
}
if ( V_38 )
V_57 += F_50 ( V_46 , V_41 ) ;
return V_57 ;
}
static int F_52 ( struct V_59 * V_54 , bool V_41 )
{
struct V_9 * V_10 ;
int V_57 = 0 ;
for ( V_10 = F_4 ( V_54 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
struct V_56 * V_46 = F_7 ( V_10 , struct V_56 , V_9 ) ;
V_57 += F_51 ( V_46 , V_41 ) ;
}
return V_57 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_13 * V_14 ,
bool V_41 V_63 )
{
float V_73 ;
struct V_9 * V_10 ;
struct V_13 * V_60 ;
int V_57 = 0 ;
for ( V_10 = F_4 ( & V_14 -> V_72 ) ; V_10 ; V_10 = F_31 ( V_10 ) ) {
V_60 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_73 = F_37 ( V_60 ) ;
if ( ! V_60 -> V_74 && V_73 >= V_2 -> V_4 )
V_57 ++ ;
}
return V_57 ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_1 * V_2 , bool V_41 )
{
F_47 ( V_14 ) ;
V_14 -> V_16 = V_41 ? V_14 -> V_38 : false ;
if ( V_14 -> V_38 ) {
int V_57 ;
if ( V_14 -> V_15 )
V_57 = F_52 ( & V_14 -> V_70 , V_41 ) ;
else
V_57 = F_53 ( V_2 , V_14 , V_41 ) ;
V_14 -> V_17 = V_41 ? V_57 : 0 ;
} else
V_14 -> V_17 = 0 ;
}
static void F_55 ( struct V_13 * V_14 ,
struct V_1 * V_8 , bool V_41 )
{
double V_73 ;
V_73 = F_37 ( V_14 ) ;
if ( V_14 -> V_74 || V_73 < V_8 -> V_4 )
return;
F_54 ( V_14 , V_8 , V_41 ) ;
if ( ! V_14 -> V_87 || V_41 )
V_8 -> V_20 ++ ;
if ( V_14 -> V_15 )
V_8 -> V_22 += V_14 -> V_17 ;
else if ( V_41 && ! F_56 ( V_14 , V_8 -> V_4 ) ) {
V_8 -> V_20 ++ ;
V_14 -> V_71 = true ;
V_14 -> V_17 = 1 ;
} else
V_14 -> V_71 = false ;
}
static void
F_57 ( struct V_1 * V_8 , bool V_41 )
{
struct V_9 * V_10 ;
struct V_13 * V_14 ;
V_10 = F_4 ( & V_8 -> V_3 -> V_12 ) ;
while ( V_10 ) {
V_14 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_10 = F_58 ( V_10 , V_88 ) ;
F_55 ( V_14 , V_8 , V_41 ) ;
}
}
static void F_59 ( struct V_1 * V_8 , bool V_41 )
{
V_8 -> V_20 = 0 ;
V_8 -> V_22 = 0 ;
F_57 ( V_8 , V_41 ) ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
F_18 ( & V_8 -> V_24 ) ;
}
static void F_60 ( struct V_1 * V_8 , bool V_41 )
{
if ( ! V_8 -> V_83 )
return;
F_55 ( V_8 -> V_83 , V_8 , V_41 ) ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
}
static void F_61 ( struct V_23 * V_8 )
{
F_62 ( V_8 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_63 ( struct V_1 * V_8 , char * V_89 , T_4 V_90 )
{
return V_8 -> V_91 ? V_8 -> V_91 ( V_8 , V_89 , V_90 ) : 0 ;
}
int F_64 ( struct V_1 * V_8 , const char * V_92 )
{
int V_93 ;
char V_91 [ 160 ] ;
struct V_94 * V_95 = V_8 -> V_95 ;
int V_96 = V_95 ? V_95 -> V_97 : 0 ;
V_8 -> V_24 . V_12 = & V_8 -> V_3 -> V_12 ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
F_63 ( V_8 , V_91 , sizeof( V_91 ) ) ;
if ( F_65 ( & V_8 -> V_24 , V_91 , L_6 , V_92 ) < 0 )
return - 1 ;
while ( 1 ) {
V_93 = F_66 ( & V_8 -> V_24 , V_96 ) ;
switch ( V_93 ) {
case V_98 : {
T_3 V_18 ;
V_95 -> V_99 ( V_95 -> V_100 ) ;
if ( F_1 ( V_8 ) ||
V_5 . V_19 )
F_17 ( V_8 ) ;
V_18 = F_8 ( V_8 ) ;
F_67 ( & V_8 -> V_24 , V_18 ) ;
if ( V_8 -> V_3 -> V_101 . V_102 !=
V_8 -> V_3 -> V_101 . V_103 [ V_104 ] ) {
V_8 -> V_3 -> V_101 . V_102 =
V_8 -> V_3 -> V_101 . V_103 [ V_104 ] ;
F_61 ( & V_8 -> V_24 ) ;
}
F_63 ( V_8 , V_91 , sizeof( V_91 ) ) ;
F_68 ( & V_8 -> V_24 , V_91 ) ;
continue;
}
case 'D' : {
static int V_105 ;
struct V_13 * V_106 = F_7 ( V_8 -> V_24 . V_107 ,
struct V_13 , V_9 ) ;
F_69 () ;
F_70 ( L_7 ,
V_105 ++ , V_8 -> V_24 . V_18 ,
V_8 -> V_3 -> V_18 ,
V_8 -> V_24 . V_31 ,
V_8 -> V_24 . V_33 ,
V_8 -> V_24 . V_34 ,
V_106 -> V_108 , V_106 -> V_17 ) ;
}
break;
case 'C' :
F_59 ( V_8 , false ) ;
break;
case 'c' :
F_60 ( V_8 , false ) ;
break;
case 'E' :
F_59 ( V_8 , true ) ;
break;
case 'e' :
F_60 ( V_8 , true ) ;
break;
case 'H' :
V_8 -> V_29 = ! V_8 -> V_29 ;
F_9 ( V_8 ) ;
break;
case V_109 :
if ( F_49 ( V_8 ) )
break;
default:
goto V_110;
}
}
V_110:
F_71 ( & V_8 -> V_24 ) ;
return V_93 ;
}
static void F_72 ( struct V_1 * V_8 ,
struct V_39 * V_54 ,
const char * V_111 , int V_112 ,
unsigned short V_36 ,
struct V_113 * V_100 )
{
int V_114 , V_35 ;
char V_61 = F_21 ( V_54 ) ;
bool V_115 = V_8 -> V_116 && V_54 -> V_55 . V_117 && F_73 ( V_54 -> V_55 . V_117 ) -> V_118 ;
V_114 = V_119 ;
V_35 = V_8 -> V_24 . V_35 - ( V_112 + 2 ) ;
if ( F_74 ( & V_8 -> V_24 , V_36 ) ) {
V_8 -> V_85 = & V_54 -> V_55 ;
V_114 = V_120 ;
V_100 -> V_121 = true ;
}
F_75 ( & V_8 -> V_24 , V_114 ) ;
F_14 ( V_8 , V_36 , 0 ) ;
F_76 ( & V_8 -> V_24 , L_8 , V_112 ) ;
F_77 ( & V_8 -> V_24 , L_9 , V_61 ) ;
F_78 ( & V_8 -> V_24 , V_115 ? V_122 : ' ' ) ;
F_76 ( & V_8 -> V_24 , V_111 , V_35 ) ;
}
static void F_79 ( struct V_1 * V_24 V_63 ,
struct V_39 * V_54 ,
const char * V_111 , int V_112 ,
unsigned short V_36 V_63 ,
struct V_113 * V_100 )
{
char V_61 = F_21 ( V_54 ) ;
V_100 -> V_123 += fprintf ( V_100 -> V_124 , L_10 , V_112 , L_8 ,
V_61 , V_111 ) ;
}
static bool F_80 ( struct V_1 * V_8 ,
unsigned short V_36 )
{
return V_8 -> V_24 . V_31 == V_36 ;
}
static bool F_81 ( struct V_1 * V_8 V_63 ,
unsigned short V_36 V_63 )
{
return false ;
}
static int F_82 ( struct V_1 * V_8 ,
struct V_42 * V_46 ,
unsigned short V_36 ,
int V_112 )
{
struct V_49 * V_50 ;
char V_125 [ 1024 ] ;
int V_114 , V_35 , V_126 ;
V_126 = V_36 ;
V_35 = V_8 -> V_24 . V_35 - ( V_127 + 2 ) ;
F_27 (ilist, &node->val, list) {
if ( ( V_50 -> V_52 != NULL ) || ( V_50 -> V_53 != NULL ) ) {
V_114 = V_119 ;
if ( F_74 ( & V_8 -> V_24 , V_36 ) )
V_114 = V_120 ;
if ( V_64 . V_93 == V_128 ||
V_64 . V_93 == V_129 ) {
if ( V_50 -> V_52 != NULL )
F_83 ( V_125 , sizeof( V_125 ) ,
L_11 ,
V_50 -> V_52 ,
V_50 -> V_130 ) ;
else
F_83 ( V_125 , sizeof( V_125 ) , L_12 ) ;
} else if ( V_50 -> V_53 != NULL )
F_83 ( V_125 , sizeof( V_125 ) , L_13 ,
V_50 -> V_53 ) ;
else if ( V_50 -> V_52 != NULL )
F_83 ( V_125 , sizeof( V_125 ) ,
L_11 ,
V_50 -> V_52 ,
V_50 -> V_130 ) ;
else
F_83 ( V_125 , sizeof( V_125 ) , L_12 ) ;
F_75 ( & V_8 -> V_24 , V_114 ) ;
F_14 ( V_8 , V_36 , 0 ) ;
F_76 ( & V_8 -> V_24 , L_8 ,
V_127 + V_112 ) ;
F_76 ( & V_8 -> V_24 , V_125 , V_35 ) ;
V_36 ++ ;
}
}
return V_36 - V_126 ;
}
static T_4 F_84 ( struct V_1 * V_8 , struct V_43 * V_43 ,
T_3 V_44 , int V_36 , int V_112 )
{
struct V_42 * V_46 ;
int V_131 ;
V_46 = F_23 ( V_43 , V_44 ) ;
if ( V_46 == NULL )
return 0 ;
V_131 = F_82 ( V_8 , V_46 , V_36 , V_112 ) ;
F_29 ( V_46 ) ;
return V_131 ;
}
static int F_85 ( struct V_1 * V_8 ,
struct V_56 * V_46 ,
struct V_39 * V_54 ,
unsigned short V_36 , T_3 V_132 ,
bool V_133 , int V_112 ,
T_5 V_134 ,
struct V_113 * V_100 )
{
char V_89 [ 1024 ] , * V_135 ;
char V_125 [ 64 ] , * V_136 ;
const char * V_111 ;
int V_58 = 0 , V_131 = 1 ;
if ( V_100 -> V_108 != 0 ) {
V_100 -> V_108 -- ;
return 0 ;
}
V_135 = NULL ;
V_136 = NULL ;
V_111 = F_86 ( V_54 , V_89 , sizeof( V_89 ) ,
V_8 -> V_116 ) ;
if ( V_5 . V_137 ) {
if ( V_133 )
F_87 ( V_46 , V_54 , NULL ,
V_125 , sizeof( V_125 ) ) ;
else
F_87 ( NULL , V_54 , NULL ,
V_125 , sizeof( V_125 ) ) ;
if ( F_88 ( & V_136 , L_14 , V_111 , V_125 ) < 0 )
V_111 = L_15 ;
else
V_111 = V_136 ;
}
if ( V_133 ) {
F_89 ( V_46 , V_125 , sizeof( V_125 ) ,
V_132 ) ;
if ( F_88 ( & V_135 , L_16 , V_125 , V_111 ) < 0 )
V_111 = L_15 ;
else
V_111 = V_135 ;
}
V_134 ( V_8 , V_54 , V_111 , V_112 , V_36 , V_100 ) ;
free ( V_135 ) ;
free ( V_136 ) ;
if ( V_5 . V_62 ) {
V_58 = F_84 ( V_8 , V_54 -> V_55 . V_43 ,
V_54 -> V_44 , V_36 + 1 , V_112 ) ;
}
return V_131 + V_58 ;
}
static bool F_90 ( struct V_9 * V_46 , T_3 V_138 )
{
struct V_56 * V_60 ;
if ( V_46 == NULL )
return false ;
if ( F_31 ( V_46 ) )
return true ;
V_60 = F_7 ( V_46 , struct V_56 , V_9 ) ;
return F_91 ( V_60 ) != V_138 ;
}
static int F_92 ( struct V_1 * V_8 ,
struct V_59 * V_81 ,
unsigned short V_36 , T_3 V_132 ,
T_3 V_138 ,
T_5 V_134 ,
struct V_113 * V_100 ,
T_6 V_139 )
{
struct V_9 * V_46 ;
int V_126 = V_36 , V_112 = V_127 ;
bool V_133 ;
V_46 = F_4 ( V_81 ) ;
V_133 = F_90 ( V_46 , V_138 ) ;
while ( V_46 ) {
struct V_56 * V_60 = F_7 ( V_46 , struct V_56 , V_9 ) ;
struct V_9 * V_77 = F_31 ( V_46 ) ;
struct V_39 * V_54 ;
char V_61 = ' ' ;
int V_75 = true ;
int V_140 = 0 ;
F_27 (chain, &child->parent_val, list) {
bool V_141 = V_75 ;
if ( V_75 )
V_75 = false ;
else if ( V_133 )
V_140 = V_127 ;
V_61 = F_21 ( V_54 ) ;
V_36 += F_85 ( V_8 , V_60 ,
V_54 , V_36 , V_132 ,
V_141 && V_133 ,
V_112 + V_140 ,
V_134 , V_100 ) ;
if ( V_139 ( V_8 , V_36 ) )
goto V_110;
if ( V_61 == '+' )
goto V_77;
}
F_27 (chain, &child->val, list) {
bool V_141 = V_75 ;
if ( V_75 )
V_75 = false ;
else if ( V_133 )
V_140 = V_127 ;
V_61 = F_21 ( V_54 ) ;
V_36 += F_85 ( V_8 , V_60 ,
V_54 , V_36 , V_132 ,
V_141 && V_133 ,
V_112 + V_140 ,
V_134 , V_100 ) ;
if ( V_139 ( V_8 , V_36 ) )
goto V_110;
if ( V_61 == '+' )
break;
}
V_77:
if ( V_139 ( V_8 , V_36 ) )
break;
V_46 = V_77 ;
}
V_110:
return V_36 - V_126 ;
}
static char * F_93 ( struct V_1 * V_8 ,
struct V_39 * V_54 ,
char * V_142 , char * V_143 )
{
char V_89 [ 1024 ] ;
const char * V_111 ;
char * V_144 ;
V_111 = F_86 ( V_54 , V_89 , sizeof( V_89 ) ,
V_8 -> V_116 ) ;
if ( V_143 ) {
if ( F_88 ( & V_144 , L_17 , V_143 ,
V_5 . V_145 ? : L_18 , V_111 ) < 0 )
V_144 = NULL ;
} else {
if ( V_142 ) {
if ( F_88 ( & V_144 , L_16 , V_142 , V_111 ) < 0 )
V_144 = NULL ;
} else {
if ( F_88 ( & V_144 , L_6 , V_111 ) < 0 )
V_144 = NULL ;
}
}
return V_144 ;
}
static int F_94 ( struct V_1 * V_8 ,
struct V_59 * V_81 ,
unsigned short V_36 , T_3 V_132 ,
T_3 V_138 ,
T_5 V_134 ,
struct V_113 * V_100 ,
T_6 V_139 )
{
struct V_9 * V_46 ;
int V_126 = V_36 , V_112 = V_127 ;
bool V_133 ;
V_46 = F_4 ( V_81 ) ;
V_133 = F_90 ( V_46 , V_138 ) ;
while ( V_46 ) {
struct V_56 * V_60 = F_7 ( V_46 , struct V_56 , V_9 ) ;
struct V_9 * V_77 = F_31 ( V_46 ) ;
struct V_39 * V_54 , * V_146 = NULL ;
int V_75 = true ;
char * V_142 = NULL , * V_147 = NULL ;
char * V_148 = NULL , * V_149 = NULL ;
if ( V_100 -> V_108 != 0 ) {
V_100 -> V_108 -- ;
goto V_77;
}
if ( V_133 ) {
char V_125 [ 64 ] ;
F_89 ( V_60 , V_125 , sizeof( V_125 ) , V_132 ) ;
if ( F_88 ( & V_142 , L_6 , V_125 ) < 0 ) {
V_142 = ( char * ) L_19 ;
goto V_150;
}
V_147 = V_142 ;
}
F_27 (chain, &child->parent_val, list) {
V_148 = F_93 ( V_8 ,
V_54 , V_142 , V_148 ) ;
if ( V_75 ) {
V_75 = false ;
V_146 = V_54 ;
}
if ( V_148 == NULL ) {
V_148 = ( char * ) L_15 ;
goto V_150;
}
V_149 = V_148 ;
}
F_27 (chain, &child->val, list) {
V_148 = F_93 ( V_8 ,
V_54 , V_142 , V_148 ) ;
if ( V_75 ) {
V_75 = false ;
V_146 = V_54 ;
}
if ( V_148 == NULL ) {
V_148 = ( char * ) L_15 ;
goto V_150;
}
V_149 = V_148 ;
}
V_150:
V_134 ( V_8 , V_146 , V_148 , V_112 , V_36 ++ , V_100 ) ;
free ( V_147 ) ;
free ( V_149 ) ;
V_77:
if ( V_139 ( V_8 , V_36 ) )
break;
V_46 = V_77 ;
}
return V_36 - V_126 ;
}
static int F_95 ( struct V_1 * V_8 ,
struct V_59 * V_81 , int V_151 ,
unsigned short V_36 , T_3 V_132 ,
T_3 V_138 ,
T_5 V_134 ,
struct V_113 * V_100 ,
T_6 V_139 )
{
struct V_9 * V_46 ;
int V_126 = V_36 , V_112 = V_151 * V_127 ;
bool V_133 ;
T_3 V_152 = V_132 ;
if ( V_64 . V_65 == V_153 )
V_152 = V_138 ;
V_46 = F_4 ( V_81 ) ;
V_133 = F_90 ( V_46 , V_138 ) ;
while ( V_46 ) {
struct V_56 * V_60 = F_7 ( V_46 , struct V_56 , V_9 ) ;
struct V_9 * V_77 = F_31 ( V_46 ) ;
struct V_39 * V_54 ;
char V_61 = ' ' ;
int V_75 = true ;
int V_140 = 0 ;
F_27 (chain, &child->val, list) {
bool V_141 = V_75 ;
if ( V_75 )
V_75 = false ;
else if ( V_133 )
V_140 = V_127 ;
V_61 = F_21 ( V_54 ) ;
V_36 += F_85 ( V_8 , V_60 ,
V_54 , V_36 , V_152 ,
V_141 && V_133 ,
V_112 + V_140 ,
V_134 , V_100 ) ;
if ( V_139 ( V_8 , V_36 ) )
goto V_110;
if ( V_61 == '+' )
break;
}
if ( V_61 == '-' ) {
const int V_154 = V_151 + ( V_140 ? 2 : 1 ) ;
V_36 += F_95 ( V_8 , & V_60 -> V_59 ,
V_154 , V_36 , V_132 ,
V_60 -> V_155 ,
V_134 , V_100 , V_139 ) ;
}
if ( V_139 ( V_8 , V_36 ) )
break;
V_46 = V_77 ;
}
V_110:
return V_36 - V_126 ;
}
static int F_96 ( struct V_1 * V_8 ,
struct V_13 * V_156 , int V_151 ,
unsigned short V_36 ,
T_5 V_134 ,
struct V_113 * V_100 ,
T_6 V_139 )
{
T_3 V_132 = F_97 ( V_156 -> V_3 ) ;
T_3 V_138 ;
int V_123 ;
if ( V_5 . V_157 )
V_138 = V_156 -> V_158 -> V_159 ;
else
V_138 = V_156 -> V_160 . V_159 ;
if ( V_64 . V_65 == V_66 ) {
V_123 = F_92 ( V_8 ,
& V_156 -> V_70 , V_36 ,
V_132 , V_138 , V_134 , V_100 ,
V_139 ) ;
} else if ( V_64 . V_65 == V_67 ) {
V_123 = F_94 ( V_8 ,
& V_156 -> V_70 , V_36 ,
V_132 , V_138 , V_134 , V_100 ,
V_139 ) ;
} else {
V_123 = F_95 ( V_8 ,
& V_156 -> V_70 , V_151 , V_36 ,
V_132 , V_138 , V_134 , V_100 ,
V_139 ) ;
}
if ( V_100 -> V_121 )
V_8 -> V_83 = V_156 ;
return V_123 ;
}
int F_98 ( struct V_161 * V_162 , const char * V_163 , ... )
{
struct V_164 * V_100 = V_162 -> V_165 ;
int V_131 , V_166 ;
T_7 args ;
double V_73 ;
va_start ( args , V_163 ) ;
V_166 = va_arg ( args , int ) ;
V_73 = va_arg ( args , double ) ;
va_end ( args ) ;
F_99 ( V_100 -> V_24 , V_73 , V_100 -> V_167 ) ;
V_131 = F_83 ( V_162 -> V_125 , V_162 -> V_90 , V_163 , V_166 , V_73 ) ;
F_77 ( V_100 -> V_24 , L_6 , V_162 -> V_125 ) ;
return V_131 ;
}
void F_100 ( void )
{
V_168 [ V_169 ] . V_114 =
V_170 ;
V_168 [ V_171 ] . V_114 =
V_172 ;
V_168 [ V_173 ] . V_114 =
V_174 ;
V_168 [ V_175 ] . V_114 =
V_176 ;
V_168 [ V_177 ] . V_114 =
V_178 ;
V_168 [ V_179 ] . V_114 =
V_180 ;
}
static int F_101 ( struct V_1 * V_8 ,
struct V_13 * V_156 ,
unsigned short V_36 )
{
int V_123 = 0 ;
int V_35 = V_8 -> V_24 . V_35 ;
char V_61 = ' ' ;
bool V_167 = F_74 ( & V_8 -> V_24 , V_36 ) ;
T_8 V_108 = V_156 -> V_108 ;
bool V_75 = true ;
struct V_181 * V_163 ;
if ( V_167 ) {
V_8 -> V_83 = V_156 ;
V_8 -> V_85 = & V_156 -> V_55 ;
}
if ( V_5 . V_182 ) {
F_47 ( V_156 ) ;
V_61 = F_20 ( V_156 ) ;
}
if ( V_5 . V_62 &&
( ! V_156 -> V_38 ) ) {
F_48 ( V_156 ) ;
V_61 = F_20 ( V_156 ) ;
}
if ( V_108 == 0 ) {
struct V_164 V_100 = {
. V_24 = & V_8 -> V_24 ,
. V_61 = V_61 ,
. V_167 = V_167 ,
} ;
int V_37 = 0 ;
F_14 ( V_8 , V_36 , 0 ) ;
F_102 (browser->hists, fmt) {
char V_183 [ 2048 ] ;
struct V_161 V_162 = {
. V_125 = V_183 ,
. V_90 = sizeof( V_183 ) ,
. V_165 = & V_100 ,
} ;
if ( F_103 ( V_163 , V_156 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_184 )
continue;
if ( V_167 && V_8 -> V_24 . V_185 ) {
F_75 ( & V_8 -> V_24 ,
V_120 ) ;
} else {
F_75 ( & V_8 -> V_24 ,
V_119 ) ;
}
if ( V_75 ) {
if ( V_5 . V_182 ||
V_5 . V_62 ) {
F_77 ( & V_8 -> V_24 , L_20 , V_61 ) ;
V_35 -= 2 ;
}
V_75 = false ;
} else {
F_77 ( & V_8 -> V_24 , L_21 ) ;
V_35 -= 2 ;
}
if ( V_163 -> V_114 ) {
int V_131 = V_163 -> V_114 ( V_163 , & V_162 , V_156 ) ;
F_104 ( V_156 , & V_162 , V_163 , V_131 ) ;
F_77 ( & V_8 -> V_24 , L_6 , V_183 + V_131 ) ;
} else {
F_104 ( V_156 , & V_162 , V_163 , V_163 -> V_156 ( V_163 , & V_162 , V_156 ) ) ;
F_77 ( & V_8 -> V_24 , L_6 , V_183 ) ;
}
V_35 -= V_162 . V_125 - V_183 ;
}
if ( ! V_8 -> V_24 . V_185 )
V_35 += 1 ;
F_76 ( & V_8 -> V_24 , L_22 , V_35 ) ;
++ V_36 ;
++ V_123 ;
} else
-- V_108 ;
if ( V_61 == '-' && V_36 != V_8 -> V_24 . V_31 ) {
struct V_113 V_100 = {
. V_108 = V_108 ,
. V_121 = V_167 ,
} ;
if ( V_156 -> V_42 )
V_123 += F_82 ( V_8 ,
V_156 -> V_42 , V_36 , 0 ) ;
else
V_123 += F_96 ( V_8 ,
V_156 , 1 , V_36 ,
F_72 ,
& V_100 ,
F_80 ) ;
}
return V_123 ;
}
static int F_105 ( struct V_1 * V_8 ,
struct V_13 * V_156 ,
unsigned short V_36 ,
int V_151 )
{
int V_123 = 0 ;
int V_35 = V_8 -> V_24 . V_35 ;
char V_61 = ' ' ;
bool V_167 = F_74 ( & V_8 -> V_24 , V_36 ) ;
T_8 V_108 = V_156 -> V_108 ;
bool V_75 = true ;
struct V_181 * V_163 ;
struct V_186 * V_187 ;
struct V_164 V_100 = {
. V_24 = & V_8 -> V_24 ,
. V_167 = V_167 ,
} ;
int V_37 = 0 ;
int V_188 = ( V_156 -> V_3 -> V_189 - 2 ) * V_190 ;
if ( V_167 ) {
V_8 -> V_83 = V_156 ;
V_8 -> V_85 = & V_156 -> V_55 ;
}
F_47 ( V_156 ) ;
V_61 = F_20 ( V_156 ) ;
V_100 . V_61 = V_61 ;
if ( V_156 -> V_15 && V_108 ) {
V_108 -- ;
goto V_191;
}
F_14 ( V_8 , V_36 , 0 ) ;
if ( V_167 && V_8 -> V_24 . V_185 )
F_75 ( & V_8 -> V_24 , V_120 ) ;
else
F_75 ( & V_8 -> V_24 , V_119 ) ;
F_76 ( & V_8 -> V_24 , L_22 , V_151 * V_190 ) ;
V_35 -= V_151 * V_190 ;
V_187 = F_106 ( & V_156 -> V_3 -> V_192 ,
struct V_186 , V_76 ) ;
F_107 (&fmt_node->hpp, fmt) {
char V_183 [ 2048 ] ;
struct V_161 V_162 = {
. V_125 = V_183 ,
. V_90 = sizeof( V_183 ) ,
. V_165 = & V_100 ,
} ;
if ( F_103 ( V_163 , V_156 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_184 )
continue;
if ( V_167 && V_8 -> V_24 . V_185 ) {
F_75 ( & V_8 -> V_24 ,
V_120 ) ;
} else {
F_75 ( & V_8 -> V_24 ,
V_119 ) ;
}
if ( V_75 ) {
F_77 ( & V_8 -> V_24 , L_20 , V_61 ) ;
V_35 -= 2 ;
V_75 = false ;
} else {
F_77 ( & V_8 -> V_24 , L_21 ) ;
V_35 -= 2 ;
}
if ( V_163 -> V_114 ) {
int V_131 = V_163 -> V_114 ( V_163 , & V_162 , V_156 ) ;
F_104 ( V_156 , & V_162 , V_163 , V_131 ) ;
F_77 ( & V_8 -> V_24 , L_6 , V_183 + V_131 ) ;
} else {
int V_131 = V_163 -> V_156 ( V_163 , & V_162 , V_156 ) ;
F_104 ( V_156 , & V_162 , V_163 , V_131 ) ;
F_77 ( & V_8 -> V_24 , L_6 , V_183 ) ;
}
V_35 -= V_162 . V_125 - V_183 ;
}
if ( ! V_75 ) {
F_76 ( & V_8 -> V_24 , L_22 , V_188 ) ;
V_35 -= V_188 ;
}
if ( V_37 >= V_8 -> V_24 . V_184 ) {
char V_183 [ 2048 ] ;
struct V_161 V_162 = {
. V_125 = V_183 ,
. V_90 = sizeof( V_183 ) ,
. V_165 = & V_100 ,
} ;
if ( V_167 && V_8 -> V_24 . V_185 ) {
F_75 ( & V_8 -> V_24 ,
V_120 ) ;
} else {
F_75 ( & V_8 -> V_24 ,
V_119 ) ;
}
F_107 (entry->hpp_list, fmt) {
if ( V_75 ) {
F_77 ( & V_8 -> V_24 , L_20 , V_61 ) ;
V_75 = false ;
} else {
F_76 ( & V_8 -> V_24 , L_22 , 2 ) ;
}
V_35 -= 2 ;
if ( V_163 -> V_114 ) {
V_35 -= V_163 -> V_114 ( V_163 , & V_162 , V_156 ) ;
} else {
int V_51 = 0 ;
V_35 -= V_163 -> V_156 ( V_163 , & V_162 , V_156 ) ;
F_77 ( & V_8 -> V_24 , L_6 , F_108 ( V_183 ) ) ;
while ( isspace ( V_183 [ V_51 ++ ] ) )
V_35 ++ ;
}
}
}
if ( ! V_8 -> V_24 . V_185 )
V_35 += 1 ;
F_76 ( & V_8 -> V_24 , L_22 , V_35 ) ;
++ V_36 ;
++ V_123 ;
V_191:
if ( V_156 -> V_15 && V_61 == '-' && V_36 != V_8 -> V_24 . V_31 ) {
struct V_113 V_193 = {
. V_108 = V_108 ,
} ;
V_123 += F_96 ( V_8 , V_156 ,
V_151 + 1 , V_36 ,
F_72 , & V_193 ,
F_80 ) ;
}
return V_123 ;
}
static int F_109 ( struct V_1 * V_8 ,
unsigned short V_36 , int V_151 )
{
int V_35 = V_8 -> V_24 . V_35 ;
bool V_167 = F_74 ( & V_8 -> V_24 , V_36 ) ;
bool V_75 = true ;
int V_37 = 0 ;
int V_131 ;
struct V_181 * V_163 ;
struct V_186 * V_187 ;
int V_194 = V_8 -> V_3 -> V_189 - 2 ;
if ( V_167 ) {
V_8 -> V_83 = NULL ;
V_8 -> V_85 = NULL ;
}
F_14 ( V_8 , V_36 , 0 ) ;
if ( V_167 && V_8 -> V_24 . V_185 )
F_75 ( & V_8 -> V_24 , V_120 ) ;
else
F_75 ( & V_8 -> V_24 , V_119 ) ;
F_76 ( & V_8 -> V_24 , L_22 , V_151 * V_190 ) ;
V_35 -= V_151 * V_190 ;
V_187 = F_106 ( & V_8 -> V_3 -> V_192 ,
struct V_186 , V_76 ) ;
F_107 (&fmt_node->hpp, fmt) {
if ( F_103 ( V_163 , V_8 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_184 )
continue;
V_131 = V_163 -> V_35 ( V_163 , NULL , V_8 -> V_3 ) ;
if ( V_75 ) {
V_75 = false ;
V_131 ++ ;
} else {
V_131 += 2 ;
}
F_76 ( & V_8 -> V_24 , L_22 , V_131 ) ;
V_35 -= V_131 ;
}
F_76 ( & V_8 -> V_24 , L_22 , V_194 * V_190 ) ;
V_35 -= V_194 * V_190 ;
if ( V_37 >= V_8 -> V_24 . V_184 ) {
char V_125 [ 32 ] ;
V_131 = snprintf ( V_125 , sizeof( V_125 ) , L_23 , V_8 -> V_4 ) ;
F_77 ( & V_8 -> V_24 , L_24 , V_125 ) ;
V_35 -= V_131 + 2 ;
}
if ( ! V_8 -> V_24 . V_185 )
V_35 += 1 ;
F_76 ( & V_8 -> V_24 , L_22 , V_35 ) ;
return 1 ;
}
static int F_110 ( struct V_161 * V_162 , int V_195 )
{
F_111 ( V_162 , V_195 ) ;
return V_162 -> V_90 <= 0 ;
}
static int
F_112 ( struct V_1 * V_8 , char * V_125 ,
T_4 V_90 , int line )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_161 V_196 = {
. V_125 = V_125 ,
. V_90 = V_90 ,
} ;
struct V_181 * V_163 ;
T_4 V_131 = 0 ;
int V_37 = 0 ;
int V_197 = 0 ;
if ( V_5 . V_182 ) {
V_131 = F_83 ( V_125 , V_90 , L_21 ) ;
if ( F_110 ( & V_196 , V_131 ) )
return V_131 ;
}
F_102 (browser->hists, fmt) {
if ( F_103 ( V_163 , V_3 ) || V_37 ++ < V_8 -> V_24 . V_184 )
continue;
V_131 = V_163 -> V_198 ( V_163 , & V_196 , V_3 , line , & V_197 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
if ( V_197 )
continue;
V_131 = F_83 ( V_196 . V_125 , V_196 . V_90 , L_21 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
}
return V_131 ;
}
static int F_113 ( struct V_1 * V_8 , char * V_125 , T_4 V_90 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_161 V_196 = {
. V_125 = V_125 ,
. V_90 = V_90 ,
} ;
struct V_181 * V_163 ;
struct V_186 * V_187 ;
T_4 V_131 = 0 ;
int V_37 = 0 ;
int V_194 = V_3 -> V_189 - 2 ;
bool V_199 , V_200 ;
V_131 = F_83 ( V_125 , V_90 , L_21 ) ;
if ( F_110 ( & V_196 , V_131 ) )
return V_131 ;
V_199 = true ;
V_187 = F_106 ( & V_3 -> V_192 ,
struct V_186 , V_76 ) ;
F_107 (&fmt_node->hpp, fmt) {
if ( V_37 ++ < V_8 -> V_24 . V_184 )
continue;
V_131 = V_163 -> V_198 ( V_163 , & V_196 , V_3 , 0 , NULL ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
V_131 = F_83 ( V_196 . V_125 , V_196 . V_90 , L_21 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
V_199 = false ;
}
if ( ! V_199 ) {
V_131 = F_83 ( V_196 . V_125 , V_196 . V_90 , L_25 ,
V_194 * V_190 , L_22 ) ;
if ( F_110 ( & V_196 , V_131 ) )
return V_131 ;
}
V_199 = true ;
F_114 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_199 ) {
V_131 = F_83 ( V_196 . V_125 , V_196 . V_90 , L_26 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
}
V_199 = false ;
V_200 = true ;
F_107 (&fmt_node->hpp, fmt) {
char * V_201 ;
if ( F_103 ( V_163 , V_3 ) )
continue;
if ( ! V_200 ) {
V_131 = F_83 ( V_196 . V_125 , V_196 . V_90 , L_27 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
}
V_200 = false ;
V_131 = V_163 -> V_198 ( V_163 , & V_196 , V_3 , 0 , NULL ) ;
V_196 . V_125 [ V_131 ] = '\0' ;
V_201 = F_115 ( V_196 . V_125 ) ;
V_131 = strlen ( V_201 ) ;
if ( V_201 != V_196 . V_125 )
memmove ( V_196 . V_125 , V_201 , V_131 + 1 ) ;
if ( F_110 ( & V_196 , V_131 ) )
break;
}
}
return V_131 ;
}
static void F_116 ( struct V_1 * V_8 )
{
char V_202 [ 1024 ] ;
F_113 ( V_8 , V_202 ,
sizeof( V_202 ) ) ;
F_15 ( & V_8 -> V_24 , 0 , 0 ) ;
F_75 ( & V_8 -> V_24 , V_203 ) ;
F_76 ( & V_8 -> V_24 , V_202 , V_8 -> V_24 . V_35 + 1 ) ;
}
static void F_117 ( struct V_1 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_25 * V_26 = V_3 -> V_26 ;
int line ;
for ( line = 0 ; line < V_26 -> V_30 ; line ++ ) {
char V_202 [ 1024 ] ;
F_112 ( V_8 , V_202 ,
sizeof( V_202 ) , line ) ;
F_15 ( & V_8 -> V_24 , line , 0 ) ;
F_75 ( & V_8 -> V_24 , V_203 ) ;
F_76 ( & V_8 -> V_24 , V_202 , V_8 -> V_24 . V_35 + 1 ) ;
}
}
static void F_118 ( struct V_1 * V_8 )
{
if ( V_5 . V_19 )
F_116 ( V_8 ) ;
else
F_117 ( V_8 ) ;
}
static void F_119 ( struct V_23 * V_8 )
{
if ( V_8 -> V_107 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
V_8 -> V_107 = F_4 ( & V_2 -> V_3 -> V_12 ) ;
}
}
static unsigned int F_120 ( struct V_23 * V_8 )
{
unsigned V_36 = 0 ;
T_2 V_27 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_29 ) {
struct V_25 * V_26 = V_3 -> V_26 ;
F_118 ( V_2 ) ;
V_27 = V_26 -> V_30 ;
}
F_119 ( V_8 ) ;
V_2 -> V_83 = NULL ;
V_2 -> V_85 = NULL ;
for ( V_10 = V_8 -> V_107 ; V_10 ; V_10 = F_6 ( V_10 ) ) {
struct V_13 * V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_73 ;
if ( V_106 -> V_74 ) {
V_106 -> V_16 = false ;
continue;
}
V_73 = F_37 ( V_106 ) ;
if ( V_73 < V_2 -> V_4 )
continue;
if ( V_5 . V_19 ) {
V_36 += F_105 ( V_2 , V_106 , V_36 ,
V_106 -> V_87 ) ;
if ( V_36 == V_8 -> V_31 )
break;
if ( V_106 -> V_71 ) {
F_109 ( V_2 , V_36 , V_106 -> V_87 + 1 ) ;
V_36 ++ ;
}
} else {
V_36 += F_101 ( V_2 , V_106 , V_36 ) ;
}
if ( V_36 == V_8 -> V_31 )
break;
}
return V_36 + V_27 ;
}
static struct V_9 * F_5 ( struct V_9 * V_10 ,
float V_4 )
{
while ( V_10 != NULL ) {
struct V_13 * V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_73 = F_37 ( V_106 ) ;
if ( ! V_106 -> V_74 && V_73 >= V_4 )
return V_10 ;
if ( F_31 ( V_10 ) )
V_10 = F_31 ( V_10 ) ;
else
V_10 = F_6 ( V_10 ) ;
}
return NULL ;
}
static struct V_9 * F_121 ( struct V_9 * V_10 ,
float V_4 )
{
while ( V_10 != NULL ) {
struct V_13 * V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_73 = F_37 ( V_106 ) ;
if ( ! V_106 -> V_74 && V_73 >= V_4 )
return V_10 ;
V_10 = F_122 ( V_10 ) ;
}
return NULL ;
}
static void F_123 ( struct V_23 * V_8 ,
T_8 V_112 , int V_204 )
{
struct V_13 * V_106 ;
struct V_9 * V_10 ;
bool V_75 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
if ( V_8 -> V_18 == 0 )
return;
F_119 ( V_8 ) ;
switch ( V_204 ) {
case V_205 :
V_10 = F_5 ( F_4 ( V_8 -> V_12 ) ,
V_2 -> V_4 ) ;
break;
case V_206 :
V_10 = V_8 -> V_107 ;
goto V_207;
case V_208 :
V_10 = F_124 ( F_125 ( V_8 -> V_12 ) ) ;
V_10 = F_121 ( V_10 , V_2 -> V_4 ) ;
V_75 = false ;
break;
default:
return;
}
V_106 = F_7 ( V_8 -> V_107 , struct V_13 , V_9 ) ;
V_106 -> V_108 = 0 ;
V_207:
if ( ! V_10 )
return;
if ( V_112 > 0 ) {
do {
V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_106 -> V_16 && V_106 -> V_15 ) {
T_2 V_209 = V_106 -> V_17 - V_106 -> V_108 ;
if ( V_112 > V_209 ) {
V_112 -= V_209 ;
V_106 -> V_108 = 0 ;
} else {
V_106 -> V_108 += V_112 ;
V_112 = 0 ;
V_8 -> V_107 = V_10 ;
break;
}
}
V_10 = F_5 ( F_6 ( V_10 ) ,
V_2 -> V_4 ) ;
if ( V_10 == NULL )
break;
-- V_112 ;
V_8 -> V_107 = V_10 ;
} while ( V_112 != 0 );
} else if ( V_112 < 0 ) {
while ( 1 ) {
V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_106 -> V_16 && V_106 -> V_15 ) {
if ( V_75 ) {
if ( - V_112 > V_106 -> V_108 ) {
V_112 += V_106 -> V_108 ;
V_106 -> V_108 = 0 ;
} else {
V_106 -> V_108 += V_112 ;
V_112 = 0 ;
V_8 -> V_107 = V_10 ;
break;
}
} else {
if ( - V_112 > V_106 -> V_17 ) {
V_112 += V_106 -> V_17 ;
V_106 -> V_108 = 0 ;
} else {
V_106 -> V_108 = V_106 -> V_17 + V_112 ;
V_112 = 0 ;
V_8 -> V_107 = V_10 ;
break;
}
}
}
V_10 = F_121 ( F_122 ( V_10 ) ,
V_2 -> V_4 ) ;
if ( V_10 == NULL )
break;
++ V_112 ;
V_8 -> V_107 = V_10 ;
if ( V_112 == 0 ) {
V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_106 -> V_16 && V_106 -> V_15 )
V_106 -> V_108 = V_106 -> V_17 ;
break;
}
V_75 = false ;
}
} else {
V_8 -> V_107 = V_10 ;
V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_106 -> V_108 = 0 ;
}
}
static int F_126 ( struct V_1 * V_8 ,
struct V_13 * V_14 , T_9 * V_124 ,
int V_151 )
{
struct V_113 V_100 = {
. V_124 = V_124 ,
} ;
F_96 ( V_8 , V_14 , V_151 , 0 ,
F_79 , & V_100 ,
F_81 ) ;
return V_100 . V_123 ;
}
static int F_127 ( struct V_1 * V_8 ,
struct V_13 * V_14 , T_9 * V_124 )
{
char V_183 [ 8192 ] ;
int V_123 = 0 ;
char V_61 = ' ' ;
struct V_161 V_162 = {
. V_125 = V_183 ,
. V_90 = sizeof( V_183 ) ,
} ;
struct V_181 * V_163 ;
bool V_75 = true ;
int V_131 ;
if ( V_5 . V_182 ) {
V_61 = F_20 ( V_14 ) ;
V_123 += fprintf ( V_124 , L_20 , V_61 ) ;
}
F_102 (browser->hists, fmt) {
if ( F_103 ( V_163 , V_14 -> V_3 ) )
continue;
if ( ! V_75 ) {
V_131 = F_83 ( V_162 . V_125 , V_162 . V_90 , L_21 ) ;
F_111 ( & V_162 , V_131 ) ;
} else
V_75 = false ;
V_131 = V_163 -> V_156 ( V_163 , & V_162 , V_14 ) ;
V_131 = F_104 ( V_14 , & V_162 , V_163 , V_131 ) ;
F_111 ( & V_162 , V_131 ) ;
}
V_123 += fprintf ( V_124 , L_28 , V_183 ) ;
if ( V_61 == '-' )
V_123 += F_126 ( V_8 , V_14 , V_124 , 1 ) ;
return V_123 ;
}
static int F_128 ( struct V_1 * V_8 ,
struct V_13 * V_14 ,
T_9 * V_124 , int V_151 )
{
char V_183 [ 8192 ] ;
int V_123 = 0 ;
char V_61 = ' ' ;
struct V_161 V_162 = {
. V_125 = V_183 ,
. V_90 = sizeof( V_183 ) ,
} ;
struct V_181 * V_163 ;
struct V_186 * V_187 ;
bool V_75 = true ;
int V_131 ;
int V_188 = ( V_14 -> V_3 -> V_189 - 2 ) * V_190 ;
V_123 = fprintf ( V_124 , L_25 , V_151 * V_190 , L_22 ) ;
V_61 = F_20 ( V_14 ) ;
V_123 += fprintf ( V_124 , L_9 , V_61 ) ;
V_187 = F_106 ( & V_14 -> V_3 -> V_192 ,
struct V_186 , V_76 ) ;
F_107 (&fmt_node->hpp, fmt) {
if ( ! V_75 ) {
V_131 = F_83 ( V_162 . V_125 , V_162 . V_90 , L_21 ) ;
F_111 ( & V_162 , V_131 ) ;
} else
V_75 = false ;
V_131 = V_163 -> V_156 ( V_163 , & V_162 , V_14 ) ;
F_111 ( & V_162 , V_131 ) ;
}
V_131 = F_83 ( V_162 . V_125 , V_162 . V_90 , L_25 , V_188 , L_22 ) ;
F_111 ( & V_162 , V_131 ) ;
F_107 (he->hpp_list, fmt) {
V_131 = F_83 ( V_162 . V_125 , V_162 . V_90 , L_21 ) ;
F_111 ( & V_162 , V_131 ) ;
V_131 = V_163 -> V_156 ( V_163 , & V_162 , V_14 ) ;
F_111 ( & V_162 , V_131 ) ;
}
V_123 += fprintf ( V_124 , L_28 , F_129 ( V_183 ) ) ;
if ( V_14 -> V_15 && V_61 == '-' ) {
V_123 += F_126 ( V_8 , V_14 , V_124 ,
V_14 -> V_87 + 1 ) ;
}
return V_123 ;
}
static int F_130 ( struct V_1 * V_8 , T_9 * V_124 )
{
struct V_9 * V_10 = F_5 ( F_4 ( V_8 -> V_24 . V_12 ) ,
V_8 -> V_4 ) ;
int V_123 = 0 ;
while ( V_10 ) {
struct V_13 * V_106 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_5 . V_19 ) {
V_123 += F_128 ( V_8 ,
V_106 , V_124 ,
V_106 -> V_87 ) ;
} else {
V_123 += F_127 ( V_8 , V_106 , V_124 ) ;
}
V_10 = F_5 ( F_6 ( V_10 ) ,
V_8 -> V_4 ) ;
}
return V_123 ;
}
static int F_131 ( struct V_1 * V_8 )
{
char V_52 [ 64 ] ;
T_9 * V_124 ;
while ( 1 ) {
F_83 ( V_52 , sizeof( V_52 ) , L_29 , V_8 -> V_210 ) ;
if ( F_132 ( V_52 , V_211 ) )
break;
if ( ++ V_8 -> V_210 == 8192 ) {
F_70 ( L_30 ) ;
return - 1 ;
}
}
V_124 = fopen ( V_52 , L_31 ) ;
if ( V_124 == NULL ) {
char V_89 [ 64 ] ;
const char * V_212 = F_133 ( V_213 , V_89 , sizeof( V_89 ) ) ;
F_70 ( L_32 , V_52 , V_212 ) ;
return - 1 ;
}
++ V_8 -> V_210 ;
F_130 ( V_8 , V_124 ) ;
fclose ( V_124 ) ;
F_70 ( L_33 , V_52 ) ;
return 0 ;
}
void F_134 ( struct V_1 * V_8 ,
struct V_3 * V_3 )
{
struct V_181 * V_163 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_24 . V_97 = F_120 ;
V_8 -> V_24 . V_214 = F_10 ;
V_8 -> V_24 . V_215 = F_123 ;
V_8 -> V_24 . V_216 = true ;
V_8 -> V_29 = V_5 . V_217 ;
if ( V_5 . V_19 ) {
struct V_186 * V_187 ;
V_187 = F_106 ( & V_3 -> V_192 ,
struct V_186 , V_76 ) ;
F_107 ( & V_187 -> V_162 , V_163 )
++ V_8 -> V_24 . V_218 ;
++ V_8 -> V_24 . V_218 ;
} else {
F_102 ( V_3 , V_163 )
++ V_8 -> V_24 . V_218 ;
}
F_135 ( V_3 ) ;
}
struct V_1 * F_136 ( struct V_3 * V_3 )
{
struct V_1 * V_8 = F_137 ( sizeof( * V_8 ) ) ;
if ( V_8 )
F_134 ( V_8 , V_3 ) ;
return V_8 ;
}
static struct V_1 *
F_138 ( struct V_219 * V_220 ,
struct V_94 * V_95 ,
struct V_221 * V_222 )
{
struct V_1 * V_8 = F_136 ( F_139 ( V_220 ) ) ;
if ( V_8 ) {
V_8 -> V_95 = V_95 ;
V_8 -> V_222 = V_222 ;
V_8 -> V_91 = V_223 ;
}
return V_8 ;
}
void F_140 ( struct V_1 * V_8 )
{
free ( V_8 ) ;
}
static struct V_13 * F_141 ( struct V_1 * V_8 )
{
return V_8 -> V_83 ;
}
static struct V_224 * F_142 ( struct V_1 * V_8 )
{
return V_8 -> V_83 -> V_224 ;
}
static inline bool F_143 ( void * V_99 )
{
return V_99 == NULL ;
}
static int V_223 ( struct V_1 * V_8 ,
char * V_89 , T_4 V_90 )
{
struct V_94 * V_95 = V_8 -> V_95 ;
struct V_3 * V_3 = V_8 -> V_3 ;
char V_225 ;
int V_123 ;
const struct V_45 * V_45 = V_3 -> V_226 ;
const struct V_224 * V_224 = V_3 -> V_227 ;
int V_228 = V_3 -> V_229 ;
unsigned long V_230 = V_3 -> V_101 . V_103 [ V_231 ] ;
T_3 V_103 = V_3 -> V_101 . V_232 ;
struct V_219 * V_220 = F_144 ( V_3 ) ;
const char * V_233 = F_145 ( V_220 ) ;
char V_125 [ 512 ] ;
T_4 V_234 = sizeof( V_125 ) ;
char V_235 [ 30 ] = L_34 ;
bool V_236 = false ;
if ( V_5 . V_237 ) {
V_230 = V_3 -> V_101 . V_238 ;
V_103 = V_3 -> V_101 . V_239 ;
}
if ( F_146 ( V_220 ) ) {
struct V_219 * V_240 ;
F_147 ( V_220 , V_125 , V_234 ) ;
V_233 = V_125 ;
F_148 (pos, evsel) {
struct V_3 * V_241 = F_139 ( V_240 ) ;
if ( V_5 . V_237 ) {
V_230 += V_241 -> V_101 . V_238 ;
V_103 += V_241 -> V_101 . V_239 ;
} else {
V_230 += V_241 -> V_101 . V_103 [ V_231 ] ;
V_103 += V_241 -> V_101 . V_232 ;
}
}
}
if ( V_5 . V_242 &&
strstr ( V_233 , L_35 ) )
V_236 = true ;
V_230 = F_149 ( V_230 , & V_225 ) ;
V_123 = F_83 ( V_89 , V_90 ,
L_36 V_243 ,
V_230 , V_225 , V_233 , V_236 ? V_235 : L_8 , V_103 ) ;
if ( V_3 -> V_244 )
V_123 += snprintf ( V_89 + V_123 , V_90 - V_123 ,
L_37 , V_3 -> V_244 ) ;
if ( V_224 ) {
if ( F_150 ( V_3 , V_224 ) ) {
V_123 += F_83 ( V_89 + V_123 , V_90 - V_123 ,
L_38 ,
( V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ) ,
V_224 -> V_246 ) ;
} else {
V_123 += F_83 ( V_89 + V_123 , V_90 - V_123 ,
L_39 ,
( V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ) ) ;
}
}
if ( V_45 )
V_123 += F_83 ( V_89 + V_123 , V_90 - V_123 ,
L_40 , V_45 -> V_247 ) ;
if ( V_228 > - 1 )
V_123 += F_83 ( V_89 + V_123 , V_90 - V_123 ,
L_41 , V_228 ) ;
if ( ! F_143 ( V_95 ) ) {
struct V_248 * V_107 = V_95 -> V_100 ;
if ( V_107 -> V_249 )
V_123 += F_83 ( V_89 + V_123 , V_90 - V_123 , L_42 ) ;
}
return V_123 ;
}
static inline void F_152 ( char * * V_250 , int V_57 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_57 ; ++ V_51 )
F_153 ( & V_250 [ V_51 ] ) ;
}
static int F_154 ( void )
{
char * V_251 , * V_250 [ 32 ] , * V_252 [ 32 ] , * V_253 ;
T_10 * V_254 ;
int V_255 = 0 , V_256 = - 1 , V_131 = - 1 ;
struct V_257 * V_258 ;
V_251 = getenv ( L_43 ) ;
if ( ! V_251 )
return V_131 ;
V_254 = F_155 ( V_251 ) ;
if ( ! V_254 )
return V_131 ;
memset ( V_250 , 0 , sizeof( V_250 ) ) ;
memset ( V_252 , 0 , sizeof( V_252 ) ) ;
while ( ( V_258 = F_156 ( V_254 ) ) ) {
char V_259 [ V_260 ] ;
T_3 V_261 ;
char * V_262 = V_258 -> V_263 ;
T_9 * V_264 ;
if ( ! ( V_258 -> V_265 == V_266 ) )
continue;
snprintf ( V_259 , sizeof( V_259 ) , L_44 , V_251 , V_262 ) ;
V_264 = fopen ( V_259 , L_45 ) ;
if ( ! V_264 )
continue;
if ( fread ( & V_261 , 1 , 8 , V_264 ) < 8 )
goto V_267;
if ( F_157 ( V_261 ) ) {
V_250 [ V_255 ] = F_158 ( V_262 ) ;
if ( ! V_250 [ V_255 ] )
goto V_267;
V_252 [ V_255 ] = F_158 ( V_259 ) ;
if ( ! V_252 [ V_255 ] ) {
F_153 ( & V_250 [ V_255 ] ) ;
F_159 ( L_46 ) ;
fclose ( V_264 ) ;
break;
}
V_255 ++ ;
}
V_267:
fclose ( V_264 ) ;
if ( V_255 >= 32 ) {
F_159 ( L_47
L_48 ) ;
break;
}
}
F_160 ( V_254 ) ;
if ( V_255 ) {
V_256 = F_161 ( V_255 , V_250 ) ;
if ( V_256 < V_255 && V_256 >= 0 ) {
V_253 = F_158 ( V_252 [ V_256 ] ) ;
if ( V_253 ) {
if ( V_268 )
free ( ( void * ) V_269 ) ;
V_269 = V_253 ;
V_268 = true ;
V_131 = 0 ;
} else
F_159 ( L_49 ) ;
}
}
F_152 ( V_250 , V_255 ) ;
F_152 ( V_252 , V_255 ) ;
return V_131 ;
}
static int
F_162 ( struct V_1 * V_8 , struct V_270 * V_271 )
{
struct V_219 * V_220 ;
struct V_272 * V_273 ;
struct V_13 * V_14 ;
int V_212 ;
if ( ! V_274 && F_163 ( V_8 -> V_222 ) )
return 0 ;
V_273 = F_73 ( V_271 -> V_55 . V_117 ) ;
if ( ! V_273 -> V_118 )
return 0 ;
V_220 = F_144 ( V_8 -> V_3 ) ;
V_212 = F_164 ( & V_271 -> V_55 , V_220 , V_8 -> V_95 ) ;
V_14 = F_141 ( V_8 ) ;
if ( ( V_212 == 'q' || V_212 == F_165 ( 'c' ) ) && V_14 -> V_275 )
return 1 ;
F_67 ( & V_8 -> V_24 , V_8 -> V_3 -> V_18 ) ;
if ( V_212 )
F_166 ( & V_8 -> V_24 ) ;
return 0 ;
}
static int
F_167 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 , char * * V_276 ,
struct V_43 * V_43 , struct V_277 * V_117 )
{
if ( V_117 == NULL || V_43 -> V_45 -> V_278 )
return 0 ;
if ( F_88 ( V_276 , L_50 , V_117 -> V_262 ) < 0 )
return 0 ;
V_271 -> V_55 . V_43 = V_43 ;
V_271 -> V_55 . V_117 = V_117 ;
V_271 -> V_279 = F_162 ;
return 1 ;
}
static int
F_168 ( struct V_1 * V_8 , struct V_270 * V_271 )
{
struct V_224 * V_224 = V_271 -> V_224 ;
if ( ( ! F_150 ( V_8 -> V_3 , V_224 ) &&
! F_150 ( V_8 -> V_3 , V_280 ) ) || V_224 == NULL )
return 0 ;
if ( V_8 -> V_3 -> V_227 ) {
F_169 ( V_8 -> V_281 , & V_8 -> V_3 -> V_227 ) ;
F_170 ( V_282 , false ) ;
F_171 ( V_8 -> V_3 -> V_227 ) ;
F_69 () ;
} else {
if ( F_150 ( V_8 -> V_3 , V_224 ) ) {
F_70 ( L_51 ,
V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ,
V_224 -> V_246 ) ;
} else {
F_70 ( L_52 ,
V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ) ;
}
V_8 -> V_3 -> V_227 = F_172 ( V_224 ) ;
F_170 ( V_282 , false ) ;
F_173 ( V_8 -> V_281 , & V_8 -> V_3 -> V_227 ) ;
}
F_174 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_175 ( struct V_1 * V_8 , struct V_270 * V_271 ,
char * * V_276 , struct V_224 * V_224 )
{
int V_131 ;
if ( ( ! F_150 ( V_8 -> V_3 , V_224 ) &&
! F_150 ( V_8 -> V_3 , V_280 ) ) || V_224 == NULL )
return 0 ;
if ( F_150 ( V_8 -> V_3 , V_224 ) ) {
V_131 = F_88 ( V_276 , L_53 ,
V_8 -> V_3 -> V_227 ? L_54 : L_55 ,
V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ,
V_224 -> V_246 ) ;
} else {
V_131 = F_88 ( V_276 , L_56 ,
V_8 -> V_3 -> V_227 ? L_54 : L_55 ,
V_224 -> V_245 ? F_151 ( V_224 ) : L_22 ) ;
}
if ( V_131 < 0 )
return 0 ;
V_271 -> V_224 = V_224 ;
V_271 -> V_279 = F_168 ;
return 1 ;
}
static int
F_176 ( struct V_1 * V_8 , struct V_270 * V_271 )
{
struct V_43 * V_43 = V_271 -> V_55 . V_43 ;
if ( ! F_150 ( V_8 -> V_3 , V_45 ) || V_43 == NULL )
return 0 ;
if ( V_8 -> V_3 -> V_226 ) {
F_169 ( V_8 -> V_281 , & V_8 -> V_3 -> V_226 ) ;
F_170 ( V_283 , false ) ;
V_8 -> V_3 -> V_226 = NULL ;
F_69 () ;
} else {
F_70 ( L_57 ,
F_177 ( V_43 ) ? L_58 : V_43 -> V_45 -> V_247 ) ;
V_8 -> V_3 -> V_226 = V_43 -> V_45 ;
F_170 ( V_283 , true ) ;
F_173 ( V_8 -> V_281 , & V_8 -> V_3 -> V_226 ) ;
}
F_178 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_179 ( struct V_1 * V_8 , struct V_270 * V_271 ,
char * * V_276 , struct V_43 * V_43 )
{
if ( ! F_150 ( V_8 -> V_3 , V_45 ) || V_43 == NULL )
return 0 ;
if ( F_88 ( V_276 , L_59 ,
V_8 -> V_3 -> V_226 ? L_54 : L_55 ,
F_177 ( V_43 ) ? L_58 : V_43 -> V_45 -> V_247 ) < 0 )
return 0 ;
V_271 -> V_55 . V_43 = V_43 ;
V_271 -> V_279 = F_176 ;
return 1 ;
}
static int
F_180 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 )
{
F_181 ( V_271 -> V_55 . V_43 ) ;
return 0 ;
}
static int
F_182 ( struct V_1 * V_8 ,
struct V_270 * V_271 , char * * V_276 , struct V_43 * V_43 )
{
if ( ! F_150 ( V_8 -> V_3 , V_45 ) || V_43 == NULL )
return 0 ;
if ( F_88 ( V_276 , L_60 ) < 0 )
return 0 ;
V_271 -> V_55 . V_43 = V_43 ;
V_271 -> V_279 = F_180 ;
return 1 ;
}
static int
F_183 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 )
{
char V_284 [ 64 ] ;
memset ( V_284 , 0 , sizeof( V_284 ) ) ;
if ( V_271 -> V_224 ) {
F_83 ( V_284 , sizeof( V_284 ) , L_61 ,
F_151 ( V_271 -> V_224 ) ) ;
} else if ( V_271 -> V_55 . V_117 ) {
F_83 ( V_284 , sizeof( V_284 ) , L_62 ,
V_271 -> V_55 . V_117 -> V_262 ) ;
}
F_184 ( V_284 ) ;
return 0 ;
}
static int
F_185 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 , char * * V_276 ,
struct V_224 * V_224 , struct V_277 * V_117 )
{
if ( V_224 ) {
if ( F_88 ( V_276 , L_63 ,
F_151 ( V_224 ) ) < 0 )
return 0 ;
} else if ( V_117 ) {
if ( F_88 ( V_276 , L_64 ,
V_117 -> V_262 ) < 0 )
return 0 ;
} else {
if ( F_88 ( V_276 , L_65 ) < 0 )
return 0 ;
}
V_271 -> V_224 = V_224 ;
V_271 -> V_55 . V_117 = V_117 ;
V_271 -> V_279 = F_183 ;
return 1 ;
}
static int
F_186 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 V_63 )
{
if ( F_154 () ) {
F_159 ( L_66
L_67 ) ;
return 0 ;
}
return V_285 ;
}
static int
F_187 ( struct V_1 * V_8 ,
struct V_270 * V_271 , char * * V_276 )
{
if ( ! F_143 ( V_8 -> V_95 ) )
return 0 ;
if ( F_88 ( V_276 , L_68 ) < 0 )
return 0 ;
V_271 -> V_279 = F_186 ;
return 1 ;
}
static int
F_188 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 V_63 )
{
return 0 ;
}
static int
F_189 ( struct V_1 * V_8 V_63 ,
struct V_270 * V_271 , char * * V_276 )
{
if ( F_88 ( V_276 , L_69 ) < 0 )
return 0 ;
V_271 -> V_279 = F_188 ;
return 1 ;
}
static int
F_190 ( struct V_1 * V_8 , struct V_270 * V_271 )
{
if ( ! F_150 ( V_8 -> V_3 , V_286 ) || V_271 -> V_286 < 0 )
return 0 ;
if ( V_8 -> V_3 -> V_229 > - 1 ) {
F_169 ( V_8 -> V_281 , & V_8 -> V_3 -> V_229 ) ;
V_8 -> V_3 -> V_229 = - 1 ;
F_170 ( V_287 , false ) ;
} else {
V_8 -> V_3 -> V_229 = V_271 -> V_286 ;
F_170 ( V_287 , true ) ;
F_173 ( V_8 -> V_281 , & V_8 -> V_3 -> V_229 ) ;
}
F_191 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_192 ( struct V_1 * V_8 , struct V_270 * V_271 ,
char * * V_276 , int V_228 )
{
if ( ! F_150 ( V_8 -> V_3 , V_286 ) || V_228 < 0 )
return 0 ;
if ( F_88 ( V_276 , L_70 ,
( V_8 -> V_3 -> V_229 > - 1 ) ? L_54 : L_55 ,
V_228 ) < 0 )
return 0 ;
V_271 -> V_286 = V_228 ;
V_271 -> V_279 = F_190 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 V_18 = 0 ;
struct V_9 * V_10 = F_4 ( & V_2 -> V_3 -> V_12 ) ;
if ( V_2 -> V_4 == 0 && ! V_5 . V_19 ) {
V_2 -> V_21 = V_2 -> V_3 -> V_21 ;
return;
}
while ( ( V_10 = F_5 ( V_10 , V_2 -> V_4 ) ) != NULL ) {
V_18 ++ ;
V_10 = F_6 ( V_10 ) ;
}
V_2 -> V_21 = V_18 ;
V_2 -> V_20 = V_18 ;
}
static void F_193 ( struct V_1 * V_2 ,
double V_73 )
{
struct V_13 * V_14 ;
struct V_9 * V_10 = F_4 ( & V_2 -> V_3 -> V_12 ) ;
T_3 V_132 = F_97 ( V_2 -> V_3 ) ;
T_3 V_288 = V_132 * ( V_73 / 100 ) ;
V_2 -> V_4 = V_64 . V_289 = V_73 ;
while ( ( V_10 = F_5 ( V_10 , V_2 -> V_4 ) ) != NULL ) {
V_14 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_14 -> V_71 ) {
V_14 -> V_71 = false ;
V_14 -> V_17 = 0 ;
}
if ( ! V_14 -> V_15 || ! V_5 . V_182 )
goto V_77;
if ( V_64 . V_65 == V_153 ) {
V_132 = V_14 -> V_160 . V_159 ;
if ( V_5 . V_157 )
V_132 = V_14 -> V_158 -> V_159 ;
V_288 = V_132 * ( V_73 / 100 ) ;
}
V_64 . V_290 ( & V_14 -> V_70 , V_14 -> V_291 ,
V_288 , & V_64 ) ;
V_77:
V_10 = F_58 ( V_10 , V_88 ) ;
V_14 -> V_82 = false ;
F_55 ( V_14 , V_2 , false ) ;
}
}
static int F_194 ( struct V_219 * V_220 , int V_103 ,
const char * V_292 ,
bool V_293 ,
struct V_94 * V_95 ,
float V_4 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_139 ( V_220 ) ;
struct V_1 * V_8 = F_138 ( V_220 , V_95 , V_222 ) ;
struct V_275 * V_294 ;
#define F_195 16
char * V_250 [ F_195 ] ;
struct V_270 V_295 [ F_195 ] ;
int V_255 = 0 ;
int V_93 = - 1 ;
char V_125 [ 64 ] ;
int V_96 = V_95 ? V_95 -> V_97 : 0 ;
#define F_196 \
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
const char V_296 [] = F_196
L_71
L_72
L_73
L_74
L_75
L_76
L_77 ;
const char V_297 [] = F_196
L_72
L_75
L_76
L_78
L_79
L_77 ;
if ( V_8 == NULL )
return - 1 ;
F_197 () ;
F_198 ( 0 , 0 , 0 ) ;
if ( V_4 )
V_8 -> V_4 = V_4 ;
F_17 ( V_8 ) ;
V_8 -> V_281 = F_199 ( 3 ) ;
if ( V_8 -> V_281 == NULL )
goto V_110;
F_200 ( V_292 ) ;
memset ( V_250 , 0 , sizeof( V_250 ) ) ;
memset ( V_295 , 0 , sizeof( V_295 ) ) ;
if ( V_5 . V_298 )
F_201 ( V_5 . V_298 ) ;
while ( 1 ) {
struct V_224 * V_224 = NULL ;
struct V_43 * V_43 = NULL ;
int V_256 = 0 ;
int V_299 = - 1 ;
V_255 = 0 ;
V_93 = F_64 ( V_8 , V_292 ) ;
if ( V_8 -> V_83 != NULL ) {
V_224 = F_142 ( V_8 ) ;
V_43 = V_8 -> V_85 -> V_43 ;
V_299 = V_8 -> V_83 -> V_286 ;
}
switch ( V_93 ) {
case V_300 :
case V_301 :
if ( V_103 == 1 )
continue;
goto V_302;
case 'a' :
if ( ! F_150 ( V_3 , V_117 ) ) {
F_62 ( & V_8 -> V_24 , V_96 * 2 ,
L_80
L_81 ) ;
continue;
}
if ( V_8 -> V_85 == NULL ||
V_8 -> V_85 -> V_117 == NULL ||
V_8 -> V_85 -> V_43 -> V_45 -> V_278 )
continue;
V_295 -> V_55 . V_43 = V_8 -> V_85 -> V_43 ;
V_295 -> V_55 . V_117 = V_8 -> V_85 -> V_117 ;
F_162 ( V_8 , V_295 ) ;
continue;
case 'P' :
F_131 ( V_8 ) ;
continue;
case 'd' :
V_295 -> V_55 . V_43 = V_43 ;
F_176 ( V_8 , V_295 ) ;
continue;
case 'V' :
V_303 = ( V_303 + 1 ) % 4 ;
V_8 -> V_116 = V_303 > 0 ;
F_70 ( L_82 ,
V_303 ) ;
continue;
case 't' :
V_295 -> V_224 = V_224 ;
F_168 ( V_8 , V_295 ) ;
continue;
case 'S' :
V_295 -> V_286 = V_299 ;
F_190 ( V_8 , V_295 ) ;
continue;
case '/' :
if ( F_202 ( L_83 ,
L_84
L_85 ,
V_125 , L_86 ,
V_96 * 2 ) == V_109 ) {
V_3 -> V_304 = * V_125 ? V_125 : NULL ;
F_203 ( V_3 ) ;
F_16 ( V_8 ) ;
}
continue;
case 'r' :
if ( F_143 ( V_95 ) ) {
V_295 -> V_224 = NULL ;
V_295 -> V_55 . V_117 = NULL ;
F_183 ( V_8 , V_295 ) ;
}
continue;
case 's' :
if ( F_143 ( V_95 ) ) {
V_93 = F_186 ( V_8 , V_295 ) ;
if ( V_93 == V_285 )
goto V_302;
}
continue;
case 'i' :
if ( V_222 -> V_305 )
F_204 ( V_222 ) ;
continue;
case 'F' :
V_5 . V_237 ^= 1 ;
continue;
case 'z' :
if ( ! F_143 ( V_95 ) ) {
struct V_248 * V_107 = V_95 -> V_100 ;
V_107 -> V_249 = ! V_107 -> V_249 ;
}
continue;
case 'L' :
if ( F_202 ( L_87 ,
L_88 ,
V_125 , L_86 ,
V_96 * 2 ) == V_109 ) {
char * V_306 ;
double V_307 = strtod ( V_125 , & V_306 ) ;
if ( V_307 < 0 || V_307 > 100 ) {
F_62 ( & V_8 -> V_24 , V_96 * 2 ,
L_89 , V_307 ) ;
continue;
}
F_193 ( V_8 , V_307 ) ;
F_16 ( V_8 ) ;
}
continue;
case V_308 :
case 'h' :
case '?' :
F_205 ( & V_8 -> V_24 ,
F_143 ( V_95 ) ? V_296 : V_297 ) ;
continue;
case V_109 :
case V_309 :
case 'm' :
break;
case V_310 :
case V_311 : {
const void * V_107 ;
if ( F_206 ( V_8 -> V_281 ) ) {
if ( V_293 )
goto V_302;
if ( V_93 == V_310 &&
F_207 ( & V_8 -> V_24 ,
L_90 ) )
goto V_302;
continue;
}
V_107 = F_208 ( V_8 -> V_281 ) ;
if ( V_107 == & V_8 -> V_3 -> V_226 ) {
F_176 ( V_8 , V_295 ) ;
} else if ( V_107 == & V_8 -> V_3 -> V_227 ) {
F_168 ( V_8 , V_295 ) ;
} else if ( V_107 == & V_8 -> V_3 -> V_229 ) {
F_190 ( V_8 , V_295 ) ;
}
continue;
}
case 'q' :
case F_165 ( 'c' ) :
goto V_302;
case 'f' :
if ( ! F_143 ( V_95 ) ) {
struct V_248 * V_107 = V_95 -> V_100 ;
F_209 ( V_107 -> V_312 ) ;
if ( V_107 -> V_312 -> V_313 ) {
V_292 = L_91 ;
V_95 -> V_97 = V_96 ;
} else {
V_292 = L_92 ;
V_95 -> V_97 = 0 ;
}
continue;
}
default:
V_292 = L_93 ;
continue;
}
if ( ! F_150 ( V_3 , V_117 ) || V_8 -> V_85 == NULL )
goto V_314;
if ( V_315 == V_316 ) {
V_294 = V_8 -> V_83 -> V_275 ;
if ( V_294 == NULL )
goto V_314;
V_255 += F_167 ( V_8 ,
& V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_294 -> V_317 . V_43 ,
V_294 -> V_317 . V_117 ) ;
if ( V_294 -> V_318 . V_117 != V_294 -> V_317 . V_117 )
V_255 += F_167 ( V_8 ,
& V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_294 -> V_318 . V_43 ,
V_294 -> V_318 . V_117 ) ;
} else {
V_255 += F_167 ( V_8 ,
& V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_8 -> V_85 -> V_43 ,
V_8 -> V_85 -> V_117 ) ;
}
V_314:
V_255 += F_175 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] , V_224 ) ;
V_255 += F_179 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] , V_43 ) ;
V_255 += F_182 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_8 -> V_85 ?
V_8 -> V_85 -> V_43 : NULL ) ;
V_255 += F_192 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_299 ) ;
if ( ! F_143 ( V_95 ) )
goto V_319;
if ( V_8 -> V_83 ) {
if ( F_150 ( V_3 , V_224 ) && V_224 ) {
V_255 += F_185 ( V_8 ,
& V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
V_224 , NULL ) ;
}
if ( F_150 ( V_3 , V_117 ) && V_8 -> V_85 -> V_117 ) {
V_255 += F_185 ( V_8 ,
& V_295 [ V_255 ] ,
& V_250 [ V_255 ] ,
NULL , V_8 -> V_85 -> V_117 ) ;
}
}
V_255 += F_185 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] , NULL , NULL ) ;
V_255 += F_187 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] ) ;
V_319:
V_255 += F_189 ( V_8 , & V_295 [ V_255 ] ,
& V_250 [ V_255 ] ) ;
do {
struct V_270 * V_271 ;
V_256 = F_161 ( V_255 , V_250 ) ;
if ( V_256 == - 1 || V_256 >= V_255 )
break;
V_271 = & V_295 [ V_256 ] ;
V_93 = V_271 -> V_279 ( V_8 , V_271 ) ;
} while ( V_93 == 1 );
if ( V_93 == V_285 )
break;
}
V_302:
F_210 ( V_8 -> V_281 ) ;
V_110:
F_140 ( V_8 ) ;
F_152 ( V_250 , F_195 ) ;
return V_93 ;
}
static void F_211 ( struct V_23 * V_8 ,
void * V_156 , int V_36 )
{
struct V_320 * V_321 = F_11 ( V_8 ,
struct V_320 , V_24 ) ;
struct V_219 * V_220 = F_43 ( V_156 , struct V_219 , V_46 ) ;
struct V_3 * V_3 = F_139 ( V_220 ) ;
bool V_167 = F_74 ( V_8 , V_36 ) ;
unsigned long V_103 = V_3 -> V_101 . V_103 [ V_231 ] ;
const char * V_233 = F_145 ( V_220 ) ;
char V_89 [ 256 ] , V_225 ;
const char * V_322 = L_8 ;
T_4 V_123 ;
F_75 ( V_8 , V_167 ? V_120 :
V_119 ) ;
if ( F_146 ( V_220 ) ) {
struct V_219 * V_240 ;
V_233 = F_212 ( V_220 ) ;
F_148 (pos, evsel) {
struct V_3 * V_241 = F_139 ( V_240 ) ;
V_103 += V_241 -> V_101 . V_103 [ V_231 ] ;
}
}
V_103 = F_149 ( V_103 , & V_225 ) ;
V_123 = F_83 ( V_89 , sizeof( V_89 ) , L_94 , V_103 ,
V_225 , V_225 == ' ' ? L_22 : L_8 , V_233 ) ;
F_77 ( V_8 , L_6 , V_89 ) ;
V_103 = V_3 -> V_101 . V_103 [ V_104 ] ;
if ( V_103 != 0 ) {
V_321 -> V_323 = true ;
if ( ! V_167 )
F_75 ( V_8 , V_324 ) ;
V_103 = F_149 ( V_103 , & V_225 ) ;
V_123 += F_83 ( V_89 , sizeof( V_89 ) , L_95 ,
V_103 , V_225 , V_225 == ' ' ? L_22 : L_8 ) ;
V_322 = V_89 ;
}
F_76 ( V_8 , V_322 , V_8 -> V_35 - V_123 ) ;
if ( V_167 )
V_321 -> V_85 = V_220 ;
}
static int F_213 ( struct V_320 * V_321 ,
int V_103 , const char * V_92 ,
struct V_94 * V_95 )
{
struct V_325 * V_312 = V_321 -> V_24 . V_326 ;
struct V_219 * V_240 ;
const char * V_91 = L_96 ;
int V_96 = V_95 ? V_95 -> V_97 : 0 ;
int V_93 ;
if ( F_65 ( & V_321 -> V_24 , V_91 ,
L_97 ) < 0 )
return - 1 ;
while ( 1 ) {
V_93 = F_66 ( & V_321 -> V_24 , V_96 ) ;
switch ( V_93 ) {
case V_98 :
V_95 -> V_99 ( V_95 -> V_100 ) ;
if ( ! V_321 -> V_327 && V_321 -> V_323 ) {
F_61 ( & V_321 -> V_24 ) ;
V_321 -> V_327 = true ;
}
continue;
case V_309 :
case V_109 :
if ( ! V_321 -> V_85 )
continue;
V_240 = V_321 -> V_85 ;
V_328:
F_214 ( V_312 , V_240 ) ;
if ( V_95 )
V_95 -> V_99 ( V_95 -> V_100 ) ;
V_93 = F_194 ( V_240 , V_103 , V_92 ,
true , V_95 ,
V_321 -> V_4 ,
V_321 -> V_222 ) ;
F_68 ( & V_321 -> V_24 , V_91 ) ;
switch ( V_93 ) {
case V_300 :
if ( V_240 -> V_46 . V_77 == & V_312 -> V_12 )
V_240 = F_215 ( V_312 ) ;
else
V_240 = F_216 ( V_240 ) ;
goto V_328;
case V_301 :
if ( V_240 -> V_46 . V_80 == & V_312 -> V_12 )
V_240 = F_217 ( V_312 ) ;
else
V_240 = F_218 ( V_240 ) ;
goto V_328;
case V_285 :
case 'q' :
case F_165 ( 'c' ) :
goto V_110;
case V_310 :
default:
continue;
}
case V_311 :
continue;
case V_310 :
if ( ! F_207 ( & V_321 -> V_24 ,
L_90 ) )
continue;
case 'q' :
case F_165 ( 'c' ) :
goto V_110;
default:
continue;
}
}
V_110:
F_71 ( & V_321 -> V_24 ) ;
return V_93 ;
}
static bool F_219 ( struct V_23 * V_8 V_63 ,
void * V_156 )
{
struct V_219 * V_220 = F_43 ( V_156 , struct V_219 , V_46 ) ;
if ( V_5 . V_329 && ! F_220 ( V_220 ) )
return true ;
return false ;
}
static int F_221 ( struct V_325 * V_312 ,
int V_18 , const char * V_92 ,
struct V_94 * V_95 ,
float V_4 ,
struct V_221 * V_222 )
{
struct V_219 * V_240 ;
struct V_320 V_321 = {
. V_24 = {
. V_12 = & V_312 -> V_12 ,
. V_97 = V_330 ,
. V_215 = V_331 ,
. V_332 = F_211 ,
. V_333 = F_219 ,
. V_18 = V_18 ,
. V_326 = V_312 ,
} ,
. V_4 = V_4 ,
. V_222 = V_222 ,
} ;
F_200 ( L_98 ) ;
F_222 (evlist, pos) {
const char * V_233 = F_145 ( V_240 ) ;
T_4 V_334 = strlen ( V_233 ) + 7 ;
if ( V_321 . V_24 . V_35 < V_334 )
V_321 . V_24 . V_35 = V_334 ;
}
return F_213 ( & V_321 , V_18 , V_92 , V_95 ) ;
}
int F_223 ( struct V_325 * V_312 , const char * V_92 ,
struct V_94 * V_95 ,
float V_4 ,
struct V_221 * V_222 )
{
int V_18 = V_312 -> V_18 ;
V_335:
if ( V_18 == 1 ) {
struct V_219 * V_75 = F_215 ( V_312 ) ;
return F_194 ( V_75 , V_18 , V_92 ,
false , V_95 , V_4 ,
V_222 ) ;
}
if ( V_5 . V_329 ) {
struct V_219 * V_240 ;
V_18 = 0 ;
F_222 (evlist, pos) {
if ( F_220 ( V_240 ) )
V_18 ++ ;
}
if ( V_18 == 1 )
goto V_335;
}
return F_221 ( V_312 , V_18 , V_92 ,
V_95 , V_4 , V_222 ) ;
}
