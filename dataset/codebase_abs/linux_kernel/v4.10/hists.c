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
static int F_23 ( struct V_42 * V_43 )
{
int V_44 = 0 ;
struct V_9 * V_10 ;
for ( V_10 = F_4 ( & V_43 -> V_45 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_46 = F_7 ( V_10 , struct V_42 , V_9 ) ;
struct V_39 * V_47 ;
char V_48 = ' ' ;
F_25 (chain, &child->val, list) {
++ V_44 ;
V_48 = F_21 ( V_47 ) ;
if ( V_48 == '+' )
break;
}
if ( V_48 == '-' )
V_44 += F_23 ( V_46 ) ;
}
return V_44 ;
}
static int F_26 ( struct V_42 * V_43 )
{
struct V_39 * V_47 ;
char V_48 = 0 ;
int V_44 = 0 ;
F_25 (chain, &node->parent_val, list) {
if ( ! V_48 ) {
V_48 = F_21 ( V_47 ) ;
if ( V_48 == '+' )
return 1 ;
}
V_44 ++ ;
}
F_25 (chain, &node->val, list) {
if ( ! V_48 ) {
V_48 = F_21 ( V_47 ) ;
if ( V_48 == '+' )
return 1 ;
}
V_44 ++ ;
}
return V_44 ;
}
static int F_27 ( struct V_42 * V_43 V_49 )
{
return 1 ;
}
static int F_28 ( struct V_42 * V_43 )
{
struct V_39 * V_47 ;
bool V_16 = false ;
int V_44 = 0 ;
if ( V_50 . V_51 == V_52 )
return F_26 ( V_43 ) ;
else if ( V_50 . V_51 == V_53 )
return F_27 ( V_43 ) ;
F_25 (chain, &node->val, list) {
++ V_44 ;
V_16 = V_47 -> V_16 ;
}
if ( V_16 )
V_44 += F_23 ( V_43 ) ;
return V_44 ;
}
static int F_29 ( struct V_45 * V_47 )
{
struct V_9 * V_10 ;
int V_44 = 0 ;
for ( V_10 = F_4 ( V_47 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_43 = F_7 ( V_10 , struct V_42 , V_9 ) ;
V_44 += F_28 ( V_43 ) ;
}
return V_44 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_13 * V_14 ,
bool V_54 )
{
int V_55 = 0 ;
struct V_9 * V_43 ;
struct V_13 * V_46 ;
if ( V_14 -> V_15 )
return F_29 ( & V_14 -> V_56 ) ;
if ( V_14 -> V_57 )
return 1 ;
V_43 = F_4 ( & V_14 -> V_58 ) ;
while ( V_43 ) {
float V_59 ;
V_46 = F_7 ( V_43 , struct V_13 , V_9 ) ;
V_59 = F_31 ( V_46 ) ;
if ( ! V_46 -> V_60 && V_59 >= V_2 -> V_4 ) {
V_55 ++ ;
if ( V_54 && V_46 -> V_16 )
V_55 += F_30 ( V_2 , V_46 , true ) ;
}
V_43 = F_24 ( V_43 ) ;
}
return V_55 ;
}
static bool F_32 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return false ;
if ( ! V_14 -> V_38 )
return false ;
V_14 -> V_16 = ! V_14 -> V_16 ;
return true ;
}
static bool F_33 ( struct V_39 * V_40 )
{
if ( ! V_40 )
return false ;
if ( ! V_40 -> V_38 )
return false ;
V_40 -> V_16 = ! V_40 -> V_16 ;
return true ;
}
static void F_34 ( struct V_42 * V_43 )
{
struct V_9 * V_10 = F_4 ( & V_43 -> V_45 ) ;
for ( V_10 = F_4 ( & V_43 -> V_45 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_46 = F_7 ( V_10 , struct V_42 , V_9 ) ;
struct V_39 * V_47 ;
bool V_61 = true ;
F_25 (chain, &child->val, list) {
if ( V_61 ) {
V_61 = false ;
V_47 -> V_38 = V_47 -> V_62 . V_63 != & V_46 -> V_64 ||
! F_35 ( & V_46 -> V_45 ) ;
} else
V_47 -> V_38 = V_47 -> V_62 . V_63 == & V_46 -> V_64 &&
! F_35 ( & V_46 -> V_45 ) ;
}
F_34 ( V_46 ) ;
}
}
static void F_36 ( struct V_42 * V_43 ,
bool V_65 )
{
struct V_39 * V_47 ;
V_47 = F_37 ( V_43 -> V_64 . V_63 , struct V_39 , V_62 ) ;
V_47 -> V_38 = V_65 ;
if ( ! F_38 ( & V_43 -> V_64 ) ) {
V_47 = F_37 ( V_43 -> V_64 . V_66 , struct V_39 , V_62 ) ;
V_47 -> V_38 = ! F_35 ( & V_43 -> V_45 ) ;
}
F_34 ( V_43 ) ;
}
static void F_39 ( struct V_45 * V_67 )
{
struct V_9 * V_10 = F_4 ( V_67 ) ;
bool V_65 = V_10 && F_24 ( V_10 ) ;
for ( V_10 = F_4 ( V_67 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_43 = F_7 ( V_10 , struct V_42 , V_9 ) ;
F_36 ( V_43 , V_65 ) ;
if ( V_50 . V_51 == V_52 ||
V_50 . V_51 == V_53 )
F_40 ( V_43 ) ;
}
}
static void F_41 ( struct V_13 * V_14 )
{
if ( V_14 -> V_68 )
return;
if ( V_14 -> V_15 ) {
V_14 -> V_38 = ! F_35 ( & V_14 -> V_56 ) ;
F_39 ( & V_14 -> V_56 ) ;
} else {
V_14 -> V_38 = ! F_35 ( & V_14 -> V_58 ) ;
}
V_14 -> V_68 = true ;
}
static bool F_42 ( struct V_1 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_69 ;
struct V_70 * V_71 = V_8 -> V_72 ;
struct V_39 * V_40 = F_11 ( V_71 , struct V_39 , V_71 ) ;
bool V_38 ;
if ( ! V_14 || ! V_71 )
return false ;
if ( V_71 == & V_14 -> V_71 )
V_38 = F_32 ( V_14 ) ;
else
V_38 = F_33 ( V_40 ) ;
if ( V_38 ) {
int V_73 = 0 ;
F_41 ( V_14 ) ;
V_8 -> V_24 . V_18 -= V_14 -> V_17 ;
if ( V_14 -> V_15 )
V_8 -> V_22 -= V_14 -> V_17 ;
else
V_8 -> V_20 -= V_14 -> V_17 ;
if ( V_5 . V_19 )
V_73 = F_30 ( V_8 , V_14 , true ) ;
if ( V_14 -> V_16 ) {
if ( V_14 -> V_15 )
V_14 -> V_17 = F_29 ( & V_14 -> V_56 ) ;
else
V_14 -> V_17 = F_30 ( V_8 , V_14 , false ) ;
if ( V_5 . V_19 )
V_8 -> V_24 . V_18 += V_73 - V_14 -> V_17 ;
if ( ! V_14 -> V_15 && V_14 -> V_17 == 0 ) {
V_14 -> V_57 = true ;
V_14 -> V_17 = 1 ;
}
} else {
if ( V_5 . V_19 )
V_8 -> V_24 . V_18 -= V_73 - V_14 -> V_17 ;
if ( V_14 -> V_57 )
V_14 -> V_57 = false ;
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
static int F_43 ( struct V_42 * V_43 , bool V_41 )
{
int V_44 = 0 ;
struct V_9 * V_10 ;
for ( V_10 = F_4 ( & V_43 -> V_45 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_46 = F_7 ( V_10 , struct V_42 , V_9 ) ;
struct V_39 * V_47 ;
bool V_38 = false ;
F_25 (chain, &child->val, list) {
++ V_44 ;
F_22 ( V_47 , V_41 ) ;
V_38 = V_47 -> V_38 ;
}
if ( V_38 )
V_44 += F_43 ( V_46 , V_41 ) ;
}
return V_44 ;
}
static int F_44 ( struct V_42 * V_43 , bool V_41 )
{
struct V_39 * V_47 ;
bool V_38 = false ;
int V_44 = 0 ;
F_25 (chain, &node->val, list) {
++ V_44 ;
F_22 ( V_47 , V_41 ) ;
V_38 = V_47 -> V_38 ;
}
if ( V_38 )
V_44 += F_43 ( V_43 , V_41 ) ;
return V_44 ;
}
static int F_45 ( struct V_45 * V_47 , bool V_41 )
{
struct V_9 * V_10 ;
int V_44 = 0 ;
for ( V_10 = F_4 ( V_47 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
struct V_42 * V_43 = F_7 ( V_10 , struct V_42 , V_9 ) ;
V_44 += F_44 ( V_43 , V_41 ) ;
}
return V_44 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_13 * V_14 ,
bool V_41 V_49 )
{
float V_59 ;
struct V_9 * V_10 ;
struct V_13 * V_46 ;
int V_44 = 0 ;
for ( V_10 = F_4 ( & V_14 -> V_58 ) ; V_10 ; V_10 = F_24 ( V_10 ) ) {
V_46 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_59 = F_31 ( V_46 ) ;
if ( ! V_46 -> V_60 && V_59 >= V_2 -> V_4 )
V_44 ++ ;
}
return V_44 ;
}
static void F_47 ( struct V_13 * V_14 ,
struct V_1 * V_2 , bool V_41 )
{
F_41 ( V_14 ) ;
V_14 -> V_16 = V_41 ? V_14 -> V_38 : false ;
if ( V_14 -> V_38 ) {
int V_44 ;
if ( V_14 -> V_15 )
V_44 = F_45 ( & V_14 -> V_56 , V_41 ) ;
else
V_44 = F_46 ( V_2 , V_14 , V_41 ) ;
V_14 -> V_17 = V_41 ? V_44 : 0 ;
} else
V_14 -> V_17 = 0 ;
}
static void
F_48 ( struct V_1 * V_8 , bool V_41 )
{
struct V_9 * V_10 ;
struct V_13 * V_14 ;
double V_59 ;
V_10 = F_4 ( & V_8 -> V_3 -> V_12 ) ;
while ( V_10 ) {
V_14 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_10 = F_49 ( V_10 , V_74 ) ;
F_47 ( V_14 , V_8 , V_41 ) ;
V_59 = F_31 ( V_14 ) ;
if ( V_14 -> V_60 || V_59 < V_8 -> V_4 )
continue;
if ( ! V_14 -> V_75 || V_41 )
V_8 -> V_20 ++ ;
if ( V_14 -> V_15 )
V_8 -> V_22 += V_14 -> V_17 ;
else if ( V_41 && ! F_50 ( V_14 , V_8 -> V_4 ) ) {
V_8 -> V_20 ++ ;
V_14 -> V_57 = true ;
V_14 -> V_17 = 1 ;
} else
V_14 -> V_57 = false ;
}
}
static void F_51 ( struct V_1 * V_8 , bool V_41 )
{
V_8 -> V_20 = 0 ;
V_8 -> V_22 = 0 ;
F_48 ( V_8 , V_41 ) ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
F_18 ( & V_8 -> V_24 ) ;
}
static void F_52 ( struct V_23 * V_8 )
{
F_53 ( V_8 , 4 ,
L_2
L_3
L_4
L_5 ) ;
}
static int F_54 ( struct V_1 * V_8 , char * V_76 , T_3 V_77 )
{
return V_8 -> V_78 ? V_8 -> V_78 ( V_8 , V_76 , V_77 ) : 0 ;
}
int F_55 ( struct V_1 * V_8 , const char * V_79 )
{
int V_80 ;
char V_78 [ 160 ] ;
struct V_81 * V_82 = V_8 -> V_82 ;
int V_83 = V_82 ? V_82 -> V_84 : 0 ;
V_8 -> V_24 . V_12 = & V_8 -> V_3 -> V_12 ;
V_8 -> V_24 . V_18 = F_8 ( V_8 ) ;
F_54 ( V_8 , V_78 , sizeof( V_78 ) ) ;
if ( F_56 ( & V_8 -> V_24 , V_78 , L_6 , V_79 ) < 0 )
return - 1 ;
while ( 1 ) {
V_80 = F_57 ( & V_8 -> V_24 , V_83 ) ;
switch ( V_80 ) {
case V_85 : {
T_4 V_18 ;
V_82 -> V_86 ( V_82 -> V_87 ) ;
if ( F_1 ( V_8 ) ||
V_5 . V_19 )
F_17 ( V_8 ) ;
V_18 = F_8 ( V_8 ) ;
F_58 ( & V_8 -> V_24 , V_18 ) ;
if ( V_8 -> V_3 -> V_88 . V_89 !=
V_8 -> V_3 -> V_88 . V_90 [ V_91 ] ) {
V_8 -> V_3 -> V_88 . V_89 =
V_8 -> V_3 -> V_88 . V_90 [ V_91 ] ;
F_52 ( & V_8 -> V_24 ) ;
}
F_54 ( V_8 , V_78 , sizeof( V_78 ) ) ;
F_59 ( & V_8 -> V_24 , V_78 ) ;
continue;
}
case 'D' : {
static int V_92 ;
struct V_13 * V_93 = F_7 ( V_8 -> V_24 . V_94 ,
struct V_13 , V_9 ) ;
F_60 () ;
F_61 ( L_7 ,
V_92 ++ , V_8 -> V_24 . V_18 ,
V_8 -> V_3 -> V_18 ,
V_8 -> V_24 . V_31 ,
V_8 -> V_24 . V_33 ,
V_8 -> V_24 . V_34 ,
V_93 -> V_95 , V_93 -> V_17 ) ;
}
break;
case 'C' :
F_51 ( V_8 , false ) ;
break;
case 'E' :
F_51 ( V_8 , true ) ;
break;
case 'H' :
V_8 -> V_29 = ! V_8 -> V_29 ;
F_9 ( V_8 ) ;
break;
case V_96 :
if ( F_42 ( V_8 ) )
break;
default:
goto V_97;
}
}
V_97:
F_62 ( & V_8 -> V_24 ) ;
return V_80 ;
}
static void F_63 ( struct V_1 * V_8 ,
struct V_39 * V_47 ,
const char * V_98 , int V_99 ,
unsigned short V_36 ,
struct V_100 * V_87 )
{
int V_101 , V_35 ;
char V_48 = F_21 ( V_47 ) ;
bool V_102 = V_8 -> V_103 && V_47 -> V_71 . V_104 && F_64 ( V_47 -> V_71 . V_104 ) -> V_105 ;
V_101 = V_106 ;
V_35 = V_8 -> V_24 . V_35 - ( V_99 + 2 ) ;
if ( F_65 ( & V_8 -> V_24 , V_36 ) ) {
V_8 -> V_72 = & V_47 -> V_71 ;
V_101 = V_107 ;
V_87 -> V_108 = true ;
}
F_66 ( & V_8 -> V_24 , V_101 ) ;
F_14 ( V_8 , V_36 , 0 ) ;
F_67 ( & V_8 -> V_24 , L_8 , V_99 ) ;
F_68 ( & V_8 -> V_24 , L_9 , V_48 ) ;
F_69 ( & V_8 -> V_24 , V_102 ? V_109 : ' ' ) ;
F_67 ( & V_8 -> V_24 , V_98 , V_35 ) ;
}
static void F_70 ( struct V_1 * V_24 V_49 ,
struct V_39 * V_47 ,
const char * V_98 , int V_99 ,
unsigned short V_36 V_49 ,
struct V_100 * V_87 )
{
char V_48 = F_21 ( V_47 ) ;
V_87 -> V_110 += fprintf ( V_87 -> V_111 , L_10 , V_99 , L_8 ,
V_48 , V_98 ) ;
}
static bool F_71 ( struct V_1 * V_8 ,
unsigned short V_36 )
{
return V_8 -> V_24 . V_31 == V_36 ;
}
static bool F_72 ( struct V_1 * V_8 V_49 ,
unsigned short V_36 V_49 )
{
return false ;
}
static int F_73 ( struct V_1 * V_8 ,
struct V_42 * V_43 ,
struct V_39 * V_47 ,
unsigned short V_36 , T_4 V_112 ,
bool V_113 , int V_99 ,
T_5 V_114 ,
struct V_100 * V_87 )
{
char V_76 [ 1024 ] , * V_115 ;
char V_116 [ 64 ] , * V_117 ;
const char * V_98 ;
if ( V_87 -> V_95 != 0 ) {
V_87 -> V_95 -- ;
return 0 ;
}
V_115 = NULL ;
V_117 = NULL ;
V_98 = F_74 ( V_47 , V_76 , sizeof( V_76 ) ,
V_8 -> V_103 ) ;
if ( V_5 . V_118 ) {
if ( V_113 )
F_75 ( V_43 , V_47 , NULL ,
V_116 , sizeof( V_116 ) ) ;
else
F_75 ( NULL , V_47 , NULL ,
V_116 , sizeof( V_116 ) ) ;
if ( F_76 ( & V_117 , L_11 , V_98 , V_116 ) < 0 )
V_98 = L_12 ;
else
V_98 = V_117 ;
}
if ( V_113 ) {
F_77 ( V_43 , V_116 , sizeof( V_116 ) ,
V_112 ) ;
if ( F_76 ( & V_115 , L_13 , V_116 , V_98 ) < 0 )
V_98 = L_12 ;
else
V_98 = V_115 ;
}
V_114 ( V_8 , V_47 , V_98 , V_99 , V_36 , V_87 ) ;
free ( V_115 ) ;
free ( V_117 ) ;
return 1 ;
}
static bool F_78 ( struct V_9 * V_43 , T_4 V_119 )
{
struct V_42 * V_46 ;
if ( V_43 == NULL )
return false ;
if ( F_24 ( V_43 ) )
return true ;
V_46 = F_7 ( V_43 , struct V_42 , V_9 ) ;
return F_79 ( V_46 ) != V_119 ;
}
static int F_80 ( struct V_1 * V_8 ,
struct V_45 * V_67 ,
unsigned short V_36 , T_4 V_112 ,
T_4 V_119 ,
T_5 V_114 ,
struct V_100 * V_87 ,
T_6 V_120 )
{
struct V_9 * V_43 ;
int V_121 = V_36 , V_99 = V_122 ;
bool V_113 ;
V_43 = F_4 ( V_67 ) ;
V_113 = F_78 ( V_43 , V_119 ) ;
while ( V_43 ) {
struct V_42 * V_46 = F_7 ( V_43 , struct V_42 , V_9 ) ;
struct V_9 * V_63 = F_24 ( V_43 ) ;
struct V_39 * V_47 ;
char V_48 = ' ' ;
int V_61 = true ;
int V_123 = 0 ;
F_25 (chain, &child->parent_val, list) {
bool V_124 = V_61 ;
if ( V_61 )
V_61 = false ;
else if ( V_113 )
V_123 = V_122 ;
V_48 = F_21 ( V_47 ) ;
V_36 += F_73 ( V_8 , V_46 ,
V_47 , V_36 , V_112 ,
V_124 && V_113 ,
V_99 + V_123 ,
V_114 , V_87 ) ;
if ( V_120 ( V_8 , V_36 ) )
goto V_97;
if ( V_48 == '+' )
goto V_63;
}
F_25 (chain, &child->val, list) {
bool V_124 = V_61 ;
if ( V_61 )
V_61 = false ;
else if ( V_113 )
V_123 = V_122 ;
V_48 = F_21 ( V_47 ) ;
V_36 += F_73 ( V_8 , V_46 ,
V_47 , V_36 , V_112 ,
V_124 && V_113 ,
V_99 + V_123 ,
V_114 , V_87 ) ;
if ( V_120 ( V_8 , V_36 ) )
goto V_97;
if ( V_48 == '+' )
break;
}
V_63:
if ( V_120 ( V_8 , V_36 ) )
break;
V_43 = V_63 ;
}
V_97:
return V_36 - V_121 ;
}
static char * F_81 ( struct V_1 * V_8 ,
struct V_39 * V_47 ,
char * V_125 , char * V_126 )
{
char V_76 [ 1024 ] ;
const char * V_98 ;
char * V_127 ;
V_98 = F_74 ( V_47 , V_76 , sizeof( V_76 ) ,
V_8 -> V_103 ) ;
if ( V_126 ) {
if ( F_76 ( & V_127 , L_14 , V_126 ,
V_5 . V_128 ? : L_15 , V_98 ) < 0 )
V_127 = NULL ;
} else {
if ( V_125 ) {
if ( F_76 ( & V_127 , L_13 , V_125 , V_98 ) < 0 )
V_127 = NULL ;
} else {
if ( F_76 ( & V_127 , L_6 , V_98 ) < 0 )
V_127 = NULL ;
}
}
return V_127 ;
}
static int F_82 ( struct V_1 * V_8 ,
struct V_45 * V_67 ,
unsigned short V_36 , T_4 V_112 ,
T_4 V_119 ,
T_5 V_114 ,
struct V_100 * V_87 ,
T_6 V_120 )
{
struct V_9 * V_43 ;
int V_121 = V_36 , V_99 = V_122 ;
bool V_113 ;
V_43 = F_4 ( V_67 ) ;
V_113 = F_78 ( V_43 , V_119 ) ;
while ( V_43 ) {
struct V_42 * V_46 = F_7 ( V_43 , struct V_42 , V_9 ) ;
struct V_9 * V_63 = F_24 ( V_43 ) ;
struct V_39 * V_47 , * V_129 = NULL ;
int V_61 = true ;
char * V_125 = NULL , * V_130 = NULL ;
char * V_131 = NULL , * V_132 = NULL ;
if ( V_87 -> V_95 != 0 ) {
V_87 -> V_95 -- ;
goto V_63;
}
if ( V_113 ) {
char V_116 [ 64 ] ;
F_77 ( V_46 , V_116 , sizeof( V_116 ) , V_112 ) ;
if ( F_76 ( & V_125 , L_6 , V_116 ) < 0 ) {
V_125 = ( char * ) L_16 ;
goto V_133;
}
V_130 = V_125 ;
}
F_25 (chain, &child->parent_val, list) {
V_131 = F_81 ( V_8 ,
V_47 , V_125 , V_131 ) ;
if ( V_61 ) {
V_61 = false ;
V_129 = V_47 ;
}
if ( V_131 == NULL ) {
V_131 = ( char * ) L_12 ;
goto V_133;
}
V_132 = V_131 ;
}
F_25 (chain, &child->val, list) {
V_131 = F_81 ( V_8 ,
V_47 , V_125 , V_131 ) ;
if ( V_61 ) {
V_61 = false ;
V_129 = V_47 ;
}
if ( V_131 == NULL ) {
V_131 = ( char * ) L_12 ;
goto V_133;
}
V_132 = V_131 ;
}
V_133:
V_114 ( V_8 , V_129 , V_131 , V_99 , V_36 ++ , V_87 ) ;
free ( V_130 ) ;
free ( V_132 ) ;
V_63:
if ( V_120 ( V_8 , V_36 ) )
break;
V_43 = V_63 ;
}
return V_36 - V_121 ;
}
static int F_83 ( struct V_1 * V_8 ,
struct V_45 * V_67 , int V_134 ,
unsigned short V_36 , T_4 V_112 ,
T_4 V_119 ,
T_5 V_114 ,
struct V_100 * V_87 ,
T_6 V_120 )
{
struct V_9 * V_43 ;
int V_121 = V_36 , V_99 = V_134 * V_122 ;
bool V_113 ;
T_4 V_135 = V_112 ;
if ( V_50 . V_51 == V_136 )
V_135 = V_119 ;
V_43 = F_4 ( V_67 ) ;
V_113 = F_78 ( V_43 , V_119 ) ;
while ( V_43 ) {
struct V_42 * V_46 = F_7 ( V_43 , struct V_42 , V_9 ) ;
struct V_9 * V_63 = F_24 ( V_43 ) ;
struct V_39 * V_47 ;
char V_48 = ' ' ;
int V_61 = true ;
int V_123 = 0 ;
F_25 (chain, &child->val, list) {
bool V_124 = V_61 ;
if ( V_61 )
V_61 = false ;
else if ( V_113 )
V_123 = V_122 ;
V_48 = F_21 ( V_47 ) ;
V_36 += F_73 ( V_8 , V_46 ,
V_47 , V_36 , V_135 ,
V_124 && V_113 ,
V_99 + V_123 ,
V_114 , V_87 ) ;
if ( V_120 ( V_8 , V_36 ) )
goto V_97;
if ( V_48 == '+' )
break;
}
if ( V_48 == '-' ) {
const int V_137 = V_134 + ( V_123 ? 2 : 1 ) ;
V_36 += F_83 ( V_8 , & V_46 -> V_45 ,
V_137 , V_36 , V_112 ,
V_46 -> V_138 ,
V_114 , V_87 , V_120 ) ;
}
if ( V_120 ( V_8 , V_36 ) )
break;
V_43 = V_63 ;
}
V_97:
return V_36 - V_121 ;
}
static int F_84 ( struct V_1 * V_8 ,
struct V_13 * V_139 , int V_134 ,
unsigned short V_36 ,
T_5 V_114 ,
struct V_100 * V_87 ,
T_6 V_120 )
{
T_4 V_112 = F_85 ( V_139 -> V_3 ) ;
T_4 V_119 ;
int V_110 ;
if ( V_5 . V_140 )
V_119 = V_139 -> V_141 -> V_142 ;
else
V_119 = V_139 -> V_143 . V_142 ;
if ( V_50 . V_51 == V_52 ) {
V_110 = F_80 ( V_8 ,
& V_139 -> V_56 , V_36 ,
V_112 , V_119 , V_114 , V_87 ,
V_120 ) ;
} else if ( V_50 . V_51 == V_53 ) {
V_110 = F_82 ( V_8 ,
& V_139 -> V_56 , V_36 ,
V_112 , V_119 , V_114 , V_87 ,
V_120 ) ;
} else {
V_110 = F_83 ( V_8 ,
& V_139 -> V_56 , V_134 , V_36 ,
V_112 , V_119 , V_114 , V_87 ,
V_120 ) ;
}
if ( V_87 -> V_108 )
V_8 -> V_69 = V_139 ;
return V_110 ;
}
int F_86 ( struct V_144 * V_145 , const char * V_146 , ... )
{
struct V_147 * V_87 = V_145 -> V_148 ;
int V_149 , V_150 ;
T_7 args ;
double V_59 ;
va_start ( args , V_146 ) ;
V_150 = va_arg ( args , int ) ;
V_59 = va_arg ( args , double ) ;
va_end ( args ) ;
F_87 ( V_87 -> V_24 , V_59 , V_87 -> V_151 ) ;
V_149 = F_88 ( V_145 -> V_116 , V_145 -> V_77 , V_146 , V_150 , V_59 ) ;
F_68 ( V_87 -> V_24 , L_6 , V_145 -> V_116 ) ;
return V_149 ;
}
void F_89 ( void )
{
V_152 [ V_153 ] . V_101 =
V_154 ;
V_152 [ V_155 ] . V_101 =
V_156 ;
V_152 [ V_157 ] . V_101 =
V_158 ;
V_152 [ V_159 ] . V_101 =
V_160 ;
V_152 [ V_161 ] . V_101 =
V_162 ;
V_152 [ V_163 ] . V_101 =
V_164 ;
}
static int F_90 ( struct V_1 * V_8 ,
struct V_13 * V_139 ,
unsigned short V_36 )
{
int V_110 = 0 ;
int V_35 = V_8 -> V_24 . V_35 ;
char V_48 = ' ' ;
bool V_151 = F_65 ( & V_8 -> V_24 , V_36 ) ;
T_8 V_95 = V_139 -> V_95 ;
bool V_61 = true ;
struct V_165 * V_146 ;
if ( V_151 ) {
V_8 -> V_69 = V_139 ;
V_8 -> V_72 = & V_139 -> V_71 ;
}
if ( V_5 . V_166 ) {
F_41 ( V_139 ) ;
V_48 = F_20 ( V_139 ) ;
}
if ( V_95 == 0 ) {
struct V_147 V_87 = {
. V_24 = & V_8 -> V_24 ,
. V_48 = V_48 ,
. V_151 = V_151 ,
} ;
int V_37 = 0 ;
F_14 ( V_8 , V_36 , 0 ) ;
F_91 (browser->hists, fmt) {
char V_167 [ 2048 ] ;
struct V_144 V_145 = {
. V_116 = V_167 ,
. V_77 = sizeof( V_167 ) ,
. V_148 = & V_87 ,
} ;
if ( F_92 ( V_146 , V_139 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_168 )
continue;
if ( V_151 && V_8 -> V_24 . V_169 ) {
F_66 ( & V_8 -> V_24 ,
V_107 ) ;
} else {
F_66 ( & V_8 -> V_24 ,
V_106 ) ;
}
if ( V_61 ) {
if ( V_5 . V_166 ) {
F_68 ( & V_8 -> V_24 , L_17 , V_48 ) ;
V_35 -= 2 ;
}
V_61 = false ;
} else {
F_68 ( & V_8 -> V_24 , L_18 ) ;
V_35 -= 2 ;
}
if ( V_146 -> V_101 ) {
int V_149 = V_146 -> V_101 ( V_146 , & V_145 , V_139 ) ;
F_93 ( V_139 , & V_145 , V_146 , V_149 ) ;
F_68 ( & V_8 -> V_24 , L_6 , V_167 + V_149 ) ;
} else {
F_93 ( V_139 , & V_145 , V_146 , V_146 -> V_139 ( V_146 , & V_145 , V_139 ) ) ;
F_68 ( & V_8 -> V_24 , L_6 , V_167 ) ;
}
V_35 -= V_145 . V_116 - V_167 ;
}
if ( ! V_8 -> V_24 . V_169 )
V_35 += 1 ;
F_67 ( & V_8 -> V_24 , L_19 , V_35 ) ;
++ V_36 ;
++ V_110 ;
} else
-- V_95 ;
if ( V_48 == '-' && V_36 != V_8 -> V_24 . V_31 ) {
struct V_100 V_87 = {
. V_95 = V_95 ,
. V_108 = V_151 ,
} ;
V_110 += F_84 ( V_8 , V_139 , 1 , V_36 ,
F_63 , & V_87 ,
F_71 ) ;
}
return V_110 ;
}
static int F_94 ( struct V_1 * V_8 ,
struct V_13 * V_139 ,
unsigned short V_36 ,
int V_134 )
{
int V_110 = 0 ;
int V_35 = V_8 -> V_24 . V_35 ;
char V_48 = ' ' ;
bool V_151 = F_65 ( & V_8 -> V_24 , V_36 ) ;
T_8 V_95 = V_139 -> V_95 ;
bool V_61 = true ;
struct V_165 * V_146 ;
struct V_170 * V_171 ;
struct V_147 V_87 = {
. V_24 = & V_8 -> V_24 ,
. V_151 = V_151 ,
} ;
int V_37 = 0 ;
int V_172 = ( V_139 -> V_3 -> V_173 - 2 ) * V_174 ;
if ( V_151 ) {
V_8 -> V_69 = V_139 ;
V_8 -> V_72 = & V_139 -> V_71 ;
}
F_41 ( V_139 ) ;
V_48 = F_20 ( V_139 ) ;
V_87 . V_48 = V_48 ;
if ( V_139 -> V_15 && V_95 ) {
V_95 -- ;
goto V_175;
}
F_14 ( V_8 , V_36 , 0 ) ;
if ( V_151 && V_8 -> V_24 . V_169 )
F_66 ( & V_8 -> V_24 , V_107 ) ;
else
F_66 ( & V_8 -> V_24 , V_106 ) ;
F_67 ( & V_8 -> V_24 , L_19 , V_134 * V_174 ) ;
V_35 -= V_134 * V_174 ;
V_171 = F_95 ( & V_139 -> V_3 -> V_176 ,
struct V_170 , V_62 ) ;
F_96 (&fmt_node->hpp, fmt) {
char V_167 [ 2048 ] ;
struct V_144 V_145 = {
. V_116 = V_167 ,
. V_77 = sizeof( V_167 ) ,
. V_148 = & V_87 ,
} ;
if ( F_92 ( V_146 , V_139 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_168 )
continue;
if ( V_151 && V_8 -> V_24 . V_169 ) {
F_66 ( & V_8 -> V_24 ,
V_107 ) ;
} else {
F_66 ( & V_8 -> V_24 ,
V_106 ) ;
}
if ( V_61 ) {
F_68 ( & V_8 -> V_24 , L_17 , V_48 ) ;
V_35 -= 2 ;
V_61 = false ;
} else {
F_68 ( & V_8 -> V_24 , L_18 ) ;
V_35 -= 2 ;
}
if ( V_146 -> V_101 ) {
int V_149 = V_146 -> V_101 ( V_146 , & V_145 , V_139 ) ;
F_93 ( V_139 , & V_145 , V_146 , V_149 ) ;
F_68 ( & V_8 -> V_24 , L_6 , V_167 + V_149 ) ;
} else {
int V_149 = V_146 -> V_139 ( V_146 , & V_145 , V_139 ) ;
F_93 ( V_139 , & V_145 , V_146 , V_149 ) ;
F_68 ( & V_8 -> V_24 , L_6 , V_167 ) ;
}
V_35 -= V_145 . V_116 - V_167 ;
}
if ( ! V_61 ) {
F_67 ( & V_8 -> V_24 , L_19 , V_172 ) ;
V_35 -= V_172 ;
}
if ( V_37 >= V_8 -> V_24 . V_168 ) {
char V_167 [ 2048 ] ;
struct V_144 V_145 = {
. V_116 = V_167 ,
. V_77 = sizeof( V_167 ) ,
. V_148 = & V_87 ,
} ;
if ( V_151 && V_8 -> V_24 . V_169 ) {
F_66 ( & V_8 -> V_24 ,
V_107 ) ;
} else {
F_66 ( & V_8 -> V_24 ,
V_106 ) ;
}
F_96 (entry->hpp_list, fmt) {
if ( V_61 ) {
F_68 ( & V_8 -> V_24 , L_17 , V_48 ) ;
V_61 = false ;
} else {
F_67 ( & V_8 -> V_24 , L_19 , 2 ) ;
}
V_35 -= 2 ;
if ( V_146 -> V_101 ) {
V_35 -= V_146 -> V_101 ( V_146 , & V_145 , V_139 ) ;
} else {
int V_177 = 0 ;
V_35 -= V_146 -> V_139 ( V_146 , & V_145 , V_139 ) ;
F_68 ( & V_8 -> V_24 , L_6 , F_97 ( V_167 ) ) ;
while ( isspace ( V_167 [ V_177 ++ ] ) )
V_35 ++ ;
}
}
}
if ( ! V_8 -> V_24 . V_169 )
V_35 += 1 ;
F_67 ( & V_8 -> V_24 , L_19 , V_35 ) ;
++ V_36 ;
++ V_110 ;
V_175:
if ( V_139 -> V_15 && V_48 == '-' && V_36 != V_8 -> V_24 . V_31 ) {
struct V_100 V_178 = {
. V_95 = V_95 ,
} ;
V_110 += F_84 ( V_8 , V_139 ,
V_134 + 1 , V_36 ,
F_63 , & V_178 ,
F_71 ) ;
}
return V_110 ;
}
static int F_98 ( struct V_1 * V_8 ,
unsigned short V_36 , int V_134 )
{
int V_35 = V_8 -> V_24 . V_35 ;
bool V_151 = F_65 ( & V_8 -> V_24 , V_36 ) ;
bool V_61 = true ;
int V_37 = 0 ;
int V_149 ;
struct V_165 * V_146 ;
struct V_170 * V_171 ;
int V_179 = V_8 -> V_3 -> V_173 - 2 ;
if ( V_151 ) {
V_8 -> V_69 = NULL ;
V_8 -> V_72 = NULL ;
}
F_14 ( V_8 , V_36 , 0 ) ;
if ( V_151 && V_8 -> V_24 . V_169 )
F_66 ( & V_8 -> V_24 , V_107 ) ;
else
F_66 ( & V_8 -> V_24 , V_106 ) ;
F_67 ( & V_8 -> V_24 , L_19 , V_134 * V_174 ) ;
V_35 -= V_134 * V_174 ;
V_171 = F_95 ( & V_8 -> V_3 -> V_176 ,
struct V_170 , V_62 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( F_92 ( V_146 , V_8 -> V_3 ) ||
V_37 ++ < V_8 -> V_24 . V_168 )
continue;
V_149 = V_146 -> V_35 ( V_146 , NULL , V_8 -> V_3 ) ;
if ( V_61 ) {
V_61 = false ;
V_149 ++ ;
} else {
V_149 += 2 ;
}
F_67 ( & V_8 -> V_24 , L_19 , V_149 ) ;
V_35 -= V_149 ;
}
F_67 ( & V_8 -> V_24 , L_19 , V_179 * V_174 ) ;
V_35 -= V_179 * V_174 ;
if ( V_37 >= V_8 -> V_24 . V_168 ) {
char V_116 [ 32 ] ;
V_149 = snprintf ( V_116 , sizeof( V_116 ) , L_20 , V_8 -> V_4 ) ;
F_68 ( & V_8 -> V_24 , L_21 , V_116 ) ;
V_35 -= V_149 + 2 ;
}
if ( ! V_8 -> V_24 . V_169 )
V_35 += 1 ;
F_67 ( & V_8 -> V_24 , L_19 , V_35 ) ;
return 1 ;
}
static int F_99 ( struct V_144 * V_145 , int V_180 )
{
F_100 ( V_145 , V_180 ) ;
return V_145 -> V_77 <= 0 ;
}
static int
F_101 ( struct V_1 * V_8 , char * V_116 ,
T_3 V_77 , int line )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_144 V_181 = {
. V_116 = V_116 ,
. V_77 = V_77 ,
} ;
struct V_165 * V_146 ;
T_3 V_149 = 0 ;
int V_37 = 0 ;
int V_182 = 0 ;
if ( V_5 . V_166 ) {
V_149 = F_88 ( V_116 , V_77 , L_18 ) ;
if ( F_99 ( & V_181 , V_149 ) )
return V_149 ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_146 , V_3 ) || V_37 ++ < V_8 -> V_24 . V_168 )
continue;
V_149 = V_146 -> V_183 ( V_146 , & V_181 , V_3 , line , & V_182 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
if ( V_182 )
continue;
V_149 = F_88 ( V_181 . V_116 , V_181 . V_77 , L_18 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
}
return V_149 ;
}
static int F_102 ( struct V_1 * V_8 , char * V_116 , T_3 V_77 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_144 V_181 = {
. V_116 = V_116 ,
. V_77 = V_77 ,
} ;
struct V_165 * V_146 ;
struct V_170 * V_171 ;
T_3 V_149 = 0 ;
int V_37 = 0 ;
int V_179 = V_3 -> V_173 - 2 ;
bool V_184 , V_185 ;
V_149 = F_88 ( V_116 , V_77 , L_18 ) ;
if ( F_99 ( & V_181 , V_149 ) )
return V_149 ;
V_184 = true ;
V_171 = F_95 ( & V_3 -> V_176 ,
struct V_170 , V_62 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( V_37 ++ < V_8 -> V_24 . V_168 )
continue;
V_149 = V_146 -> V_183 ( V_146 , & V_181 , V_3 , 0 , NULL ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
V_149 = F_88 ( V_181 . V_116 , V_181 . V_77 , L_18 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
V_184 = false ;
}
if ( ! V_184 ) {
V_149 = F_88 ( V_181 . V_116 , V_181 . V_77 , L_22 ,
V_179 * V_174 , L_19 ) ;
if ( F_99 ( & V_181 , V_149 ) )
return V_149 ;
}
V_184 = true ;
F_103 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_184 ) {
V_149 = F_88 ( V_181 . V_116 , V_181 . V_77 , L_23 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
}
V_184 = false ;
V_185 = true ;
F_96 (&fmt_node->hpp, fmt) {
char * V_186 ;
if ( F_92 ( V_146 , V_3 ) )
continue;
if ( ! V_185 ) {
V_149 = F_88 ( V_181 . V_116 , V_181 . V_77 , L_24 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
}
V_185 = false ;
V_149 = V_146 -> V_183 ( V_146 , & V_181 , V_3 , 0 , NULL ) ;
V_181 . V_116 [ V_149 ] = '\0' ;
V_186 = F_104 ( V_181 . V_116 ) ;
V_149 = strlen ( V_186 ) ;
if ( V_186 != V_181 . V_116 )
memmove ( V_181 . V_116 , V_186 , V_149 + 1 ) ;
if ( F_99 ( & V_181 , V_149 ) )
break;
}
}
return V_149 ;
}
static void F_105 ( struct V_1 * V_8 )
{
char V_187 [ 1024 ] ;
F_102 ( V_8 , V_187 ,
sizeof( V_187 ) ) ;
F_15 ( & V_8 -> V_24 , 0 , 0 ) ;
F_66 ( & V_8 -> V_24 , V_188 ) ;
F_67 ( & V_8 -> V_24 , V_187 , V_8 -> V_24 . V_35 + 1 ) ;
}
static void F_106 ( struct V_1 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_25 * V_26 = V_3 -> V_26 ;
int line ;
for ( line = 0 ; line < V_26 -> V_30 ; line ++ ) {
char V_187 [ 1024 ] ;
F_101 ( V_8 , V_187 ,
sizeof( V_187 ) , line ) ;
F_15 ( & V_8 -> V_24 , line , 0 ) ;
F_66 ( & V_8 -> V_24 , V_188 ) ;
F_67 ( & V_8 -> V_24 , V_187 , V_8 -> V_24 . V_35 + 1 ) ;
}
}
static void F_107 ( struct V_1 * V_8 )
{
if ( V_5 . V_19 )
F_105 ( V_8 ) ;
else
F_106 ( V_8 ) ;
}
static void F_108 ( struct V_23 * V_8 )
{
if ( V_8 -> V_94 == NULL ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
V_8 -> V_94 = F_4 ( & V_2 -> V_3 -> V_12 ) ;
}
}
static unsigned int F_109 ( struct V_23 * V_8 )
{
unsigned V_36 = 0 ;
T_2 V_27 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_29 ) {
struct V_25 * V_26 = V_3 -> V_26 ;
F_107 ( V_2 ) ;
V_27 = V_26 -> V_30 ;
}
F_108 ( V_8 ) ;
V_2 -> V_69 = NULL ;
V_2 -> V_72 = NULL ;
for ( V_10 = V_8 -> V_94 ; V_10 ; V_10 = F_6 ( V_10 ) ) {
struct V_13 * V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_59 ;
if ( V_93 -> V_60 ) {
V_93 -> V_16 = false ;
continue;
}
V_59 = F_31 ( V_93 ) ;
if ( V_59 < V_2 -> V_4 )
continue;
if ( V_5 . V_19 ) {
V_36 += F_94 ( V_2 , V_93 , V_36 ,
V_93 -> V_75 ) ;
if ( V_36 == V_8 -> V_31 )
break;
if ( V_93 -> V_57 ) {
F_98 ( V_2 , V_36 , V_93 -> V_75 + 1 ) ;
V_36 ++ ;
}
} else {
V_36 += F_90 ( V_2 , V_93 , V_36 ) ;
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
struct V_13 * V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_59 = F_31 ( V_93 ) ;
if ( ! V_93 -> V_60 && V_59 >= V_4 )
return V_10 ;
if ( F_24 ( V_10 ) )
V_10 = F_24 ( V_10 ) ;
else
V_10 = F_6 ( V_10 ) ;
}
return NULL ;
}
static struct V_9 * F_110 ( struct V_9 * V_10 ,
float V_4 )
{
while ( V_10 != NULL ) {
struct V_13 * V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
float V_59 = F_31 ( V_93 ) ;
if ( ! V_93 -> V_60 && V_59 >= V_4 )
return V_10 ;
V_10 = F_111 ( V_10 ) ;
}
return NULL ;
}
static void F_112 ( struct V_23 * V_8 ,
T_8 V_99 , int V_189 )
{
struct V_13 * V_93 ;
struct V_9 * V_10 ;
bool V_61 = true ;
struct V_1 * V_2 ;
V_2 = F_11 ( V_8 , struct V_1 , V_24 ) ;
if ( V_8 -> V_18 == 0 )
return;
F_108 ( V_8 ) ;
switch ( V_189 ) {
case V_190 :
V_10 = F_5 ( F_4 ( V_8 -> V_12 ) ,
V_2 -> V_4 ) ;
break;
case V_191 :
V_10 = V_8 -> V_94 ;
goto V_192;
case V_193 :
V_10 = F_113 ( F_114 ( V_8 -> V_12 ) ) ;
V_10 = F_110 ( V_10 , V_2 -> V_4 ) ;
V_61 = false ;
break;
default:
return;
}
V_93 = F_7 ( V_8 -> V_94 , struct V_13 , V_9 ) ;
V_93 -> V_95 = 0 ;
V_192:
if ( ! V_10 )
return;
if ( V_99 > 0 ) {
do {
V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_93 -> V_16 && V_93 -> V_15 ) {
T_2 V_194 = V_93 -> V_17 - V_93 -> V_95 ;
if ( V_99 > V_194 ) {
V_99 -= V_194 ;
V_93 -> V_95 = 0 ;
} else {
V_93 -> V_95 += V_99 ;
V_99 = 0 ;
V_8 -> V_94 = V_10 ;
break;
}
}
V_10 = F_5 ( F_6 ( V_10 ) ,
V_2 -> V_4 ) ;
if ( V_10 == NULL )
break;
-- V_99 ;
V_8 -> V_94 = V_10 ;
} while ( V_99 != 0 );
} else if ( V_99 < 0 ) {
while ( 1 ) {
V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_93 -> V_16 && V_93 -> V_15 ) {
if ( V_61 ) {
if ( - V_99 > V_93 -> V_95 ) {
V_99 += V_93 -> V_95 ;
V_93 -> V_95 = 0 ;
} else {
V_93 -> V_95 += V_99 ;
V_99 = 0 ;
V_8 -> V_94 = V_10 ;
break;
}
} else {
if ( - V_99 > V_93 -> V_17 ) {
V_99 += V_93 -> V_17 ;
V_93 -> V_95 = 0 ;
} else {
V_93 -> V_95 = V_93 -> V_17 + V_99 ;
V_99 = 0 ;
V_8 -> V_94 = V_10 ;
break;
}
}
}
V_10 = F_110 ( F_111 ( V_10 ) ,
V_2 -> V_4 ) ;
if ( V_10 == NULL )
break;
++ V_99 ;
V_8 -> V_94 = V_10 ;
if ( V_99 == 0 ) {
V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_93 -> V_16 && V_93 -> V_15 )
V_93 -> V_95 = V_93 -> V_17 ;
break;
}
V_61 = false ;
}
} else {
V_8 -> V_94 = V_10 ;
V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
V_93 -> V_95 = 0 ;
}
}
static int F_115 ( struct V_1 * V_8 ,
struct V_13 * V_14 , T_9 * V_111 ,
int V_134 )
{
struct V_100 V_87 = {
. V_111 = V_111 ,
} ;
F_84 ( V_8 , V_14 , V_134 , 0 ,
F_70 , & V_87 ,
F_72 ) ;
return V_87 . V_110 ;
}
static int F_116 ( struct V_1 * V_8 ,
struct V_13 * V_14 , T_9 * V_111 )
{
char V_167 [ 8192 ] ;
int V_110 = 0 ;
char V_48 = ' ' ;
struct V_144 V_145 = {
. V_116 = V_167 ,
. V_77 = sizeof( V_167 ) ,
} ;
struct V_165 * V_146 ;
bool V_61 = true ;
int V_149 ;
if ( V_5 . V_166 ) {
V_48 = F_20 ( V_14 ) ;
V_110 += fprintf ( V_111 , L_17 , V_48 ) ;
}
F_91 (browser->hists, fmt) {
if ( F_92 ( V_146 , V_14 -> V_3 ) )
continue;
if ( ! V_61 ) {
V_149 = F_88 ( V_145 . V_116 , V_145 . V_77 , L_18 ) ;
F_100 ( & V_145 , V_149 ) ;
} else
V_61 = false ;
V_149 = V_146 -> V_139 ( V_146 , & V_145 , V_14 ) ;
V_149 = F_93 ( V_14 , & V_145 , V_146 , V_149 ) ;
F_100 ( & V_145 , V_149 ) ;
}
V_110 += fprintf ( V_111 , L_25 , V_167 ) ;
if ( V_48 == '-' )
V_110 += F_115 ( V_8 , V_14 , V_111 , 1 ) ;
return V_110 ;
}
static int F_117 ( struct V_1 * V_8 ,
struct V_13 * V_14 ,
T_9 * V_111 , int V_134 )
{
char V_167 [ 8192 ] ;
int V_110 = 0 ;
char V_48 = ' ' ;
struct V_144 V_145 = {
. V_116 = V_167 ,
. V_77 = sizeof( V_167 ) ,
} ;
struct V_165 * V_146 ;
struct V_170 * V_171 ;
bool V_61 = true ;
int V_149 ;
int V_172 = ( V_14 -> V_3 -> V_173 - 2 ) * V_174 ;
V_110 = fprintf ( V_111 , L_22 , V_134 * V_174 , L_19 ) ;
V_48 = F_20 ( V_14 ) ;
V_110 += fprintf ( V_111 , L_9 , V_48 ) ;
V_171 = F_95 ( & V_14 -> V_3 -> V_176 ,
struct V_170 , V_62 ) ;
F_96 (&fmt_node->hpp, fmt) {
if ( ! V_61 ) {
V_149 = F_88 ( V_145 . V_116 , V_145 . V_77 , L_18 ) ;
F_100 ( & V_145 , V_149 ) ;
} else
V_61 = false ;
V_149 = V_146 -> V_139 ( V_146 , & V_145 , V_14 ) ;
F_100 ( & V_145 , V_149 ) ;
}
V_149 = F_88 ( V_145 . V_116 , V_145 . V_77 , L_22 , V_172 , L_19 ) ;
F_100 ( & V_145 , V_149 ) ;
F_96 (he->hpp_list, fmt) {
V_149 = F_88 ( V_145 . V_116 , V_145 . V_77 , L_18 ) ;
F_100 ( & V_145 , V_149 ) ;
V_149 = V_146 -> V_139 ( V_146 , & V_145 , V_14 ) ;
F_100 ( & V_145 , V_149 ) ;
}
V_110 += fprintf ( V_111 , L_25 , F_118 ( V_167 ) ) ;
if ( V_14 -> V_15 && V_48 == '-' ) {
V_110 += F_115 ( V_8 , V_14 , V_111 ,
V_14 -> V_75 + 1 ) ;
}
return V_110 ;
}
static int F_119 ( struct V_1 * V_8 , T_9 * V_111 )
{
struct V_9 * V_10 = F_5 ( F_4 ( V_8 -> V_24 . V_12 ) ,
V_8 -> V_4 ) ;
int V_110 = 0 ;
while ( V_10 ) {
struct V_13 * V_93 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_5 . V_19 ) {
V_110 += F_117 ( V_8 ,
V_93 , V_111 ,
V_93 -> V_75 ) ;
} else {
V_110 += F_116 ( V_8 , V_93 , V_111 ) ;
}
V_10 = F_5 ( F_6 ( V_10 ) ,
V_8 -> V_4 ) ;
}
return V_110 ;
}
static int F_120 ( struct V_1 * V_8 )
{
char V_195 [ 64 ] ;
T_9 * V_111 ;
while ( 1 ) {
F_88 ( V_195 , sizeof( V_195 ) , L_26 , V_8 -> V_196 ) ;
if ( F_121 ( V_195 , V_197 ) )
break;
if ( ++ V_8 -> V_196 == 8192 ) {
F_61 ( L_27 ) ;
return - 1 ;
}
}
V_111 = fopen ( V_195 , L_28 ) ;
if ( V_111 == NULL ) {
char V_76 [ 64 ] ;
const char * V_198 = F_122 ( V_199 , V_76 , sizeof( V_76 ) ) ;
F_61 ( L_29 , V_195 , V_198 ) ;
return - 1 ;
}
++ V_8 -> V_196 ;
F_119 ( V_8 , V_111 ) ;
fclose ( V_111 ) ;
F_61 ( L_30 , V_195 ) ;
return 0 ;
}
void F_123 ( struct V_1 * V_8 ,
struct V_3 * V_3 )
{
struct V_165 * V_146 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_24 . V_84 = F_109 ;
V_8 -> V_24 . V_200 = F_10 ;
V_8 -> V_24 . V_201 = F_112 ;
V_8 -> V_24 . V_202 = true ;
V_8 -> V_29 = V_5 . V_203 ;
if ( V_5 . V_19 ) {
struct V_170 * V_171 ;
V_171 = F_95 ( & V_3 -> V_176 ,
struct V_170 , V_62 ) ;
F_96 ( & V_171 -> V_145 , V_146 )
++ V_8 -> V_24 . V_204 ;
++ V_8 -> V_24 . V_204 ;
} else {
F_91 ( V_3 , V_146 )
++ V_8 -> V_24 . V_204 ;
}
F_124 ( V_3 ) ;
}
struct V_1 * F_125 ( struct V_3 * V_3 )
{
struct V_1 * V_8 = F_126 ( sizeof( * V_8 ) ) ;
if ( V_8 )
F_123 ( V_8 , V_3 ) ;
return V_8 ;
}
static struct V_1 *
F_127 ( struct V_205 * V_206 ,
struct V_81 * V_82 ,
struct V_207 * V_208 )
{
struct V_1 * V_8 = F_125 ( F_128 ( V_206 ) ) ;
if ( V_8 ) {
V_8 -> V_82 = V_82 ;
V_8 -> V_208 = V_208 ;
V_8 -> V_78 = V_209 ;
}
return V_8 ;
}
void F_129 ( struct V_1 * V_8 )
{
free ( V_8 ) ;
}
static struct V_13 * F_130 ( struct V_1 * V_8 )
{
return V_8 -> V_69 ;
}
static struct V_210 * F_131 ( struct V_1 * V_8 )
{
return V_8 -> V_69 -> V_210 ;
}
static inline bool F_132 ( void * V_86 )
{
return V_86 == NULL ;
}
static int V_209 ( struct V_1 * V_8 ,
char * V_76 , T_3 V_77 )
{
struct V_81 * V_82 = V_8 -> V_82 ;
struct V_3 * V_3 = V_8 -> V_3 ;
char V_211 ;
int V_110 ;
const struct V_212 * V_212 = V_3 -> V_213 ;
const struct V_210 * V_210 = V_3 -> V_214 ;
int V_215 = V_3 -> V_216 ;
unsigned long V_217 = V_3 -> V_88 . V_90 [ V_218 ] ;
T_4 V_90 = V_3 -> V_88 . V_219 ;
struct V_205 * V_206 = F_133 ( V_3 ) ;
const char * V_220 = F_134 ( V_206 ) ;
char V_116 [ 512 ] ;
T_3 V_221 = sizeof( V_116 ) ;
char V_222 [ 30 ] = L_31 ;
bool V_223 = false ;
if ( V_5 . V_224 ) {
V_217 = V_3 -> V_88 . V_225 ;
V_90 = V_3 -> V_88 . V_226 ;
}
if ( F_135 ( V_206 ) ) {
struct V_205 * V_227 ;
F_136 ( V_206 , V_116 , V_221 ) ;
V_220 = V_116 ;
F_137 (pos, evsel) {
struct V_3 * V_228 = F_128 ( V_227 ) ;
if ( V_5 . V_224 ) {
V_217 += V_228 -> V_88 . V_225 ;
V_90 += V_228 -> V_88 . V_226 ;
} else {
V_217 += V_228 -> V_88 . V_90 [ V_218 ] ;
V_90 += V_228 -> V_88 . V_219 ;
}
}
}
if ( V_5 . V_229 &&
strstr ( V_220 , L_32 ) )
V_223 = true ;
V_217 = F_138 ( V_217 , & V_211 ) ;
V_110 = F_88 ( V_76 , V_77 ,
L_33 V_230 ,
V_217 , V_211 , V_220 , V_223 ? V_222 : L_8 , V_90 ) ;
if ( V_3 -> V_231 )
V_110 += snprintf ( V_76 + V_110 , V_77 - V_110 ,
L_34 , V_3 -> V_231 ) ;
if ( V_210 ) {
if ( F_139 ( V_3 , V_210 ) ) {
V_110 += F_88 ( V_76 + V_110 , V_77 - V_110 ,
L_35 ,
( V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ) ,
V_210 -> V_233 ) ;
} else {
V_110 += F_88 ( V_76 + V_110 , V_77 - V_110 ,
L_36 ,
( V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ) ) ;
}
}
if ( V_212 )
V_110 += F_88 ( V_76 + V_110 , V_77 - V_110 ,
L_37 , V_212 -> V_234 ) ;
if ( V_215 > - 1 )
V_110 += F_88 ( V_76 + V_110 , V_77 - V_110 ,
L_38 , V_215 ) ;
if ( ! F_132 ( V_82 ) ) {
struct V_235 * V_94 = V_82 -> V_87 ;
if ( V_94 -> V_236 )
V_110 += F_88 ( V_76 + V_110 , V_77 - V_110 , L_39 ) ;
}
return V_110 ;
}
static inline void F_141 ( char * * V_237 , int V_44 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < V_44 ; ++ V_177 )
F_142 ( & V_237 [ V_177 ] ) ;
}
static int F_143 ( void )
{
char * V_238 , * V_237 [ 32 ] , * V_239 [ 32 ] , * V_240 ;
T_10 * V_241 ;
int V_242 = 0 , V_243 = - 1 , V_149 = - 1 ;
struct V_244 * V_245 ;
V_238 = getenv ( L_40 ) ;
if ( ! V_238 )
return V_149 ;
V_241 = F_144 ( V_238 ) ;
if ( ! V_241 )
return V_149 ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
memset ( V_237 , 0 , sizeof( V_239 ) ) ;
while ( ( V_245 = F_145 ( V_241 ) ) ) {
char V_246 [ V_247 ] ;
T_4 V_248 ;
char * V_249 = V_245 -> V_250 ;
T_9 * V_251 ;
if ( ! ( V_245 -> V_252 == V_253 ) )
continue;
snprintf ( V_246 , sizeof( V_246 ) , L_41 , V_238 , V_249 ) ;
V_251 = fopen ( V_246 , L_42 ) ;
if ( ! V_251 )
continue;
if ( fread ( & V_248 , 1 , 8 , V_251 ) < 8 )
goto V_254;
if ( F_146 ( V_248 ) ) {
V_237 [ V_242 ] = F_147 ( V_249 ) ;
if ( ! V_237 [ V_242 ] )
goto V_254;
V_239 [ V_242 ] = F_147 ( V_246 ) ;
if ( ! V_239 [ V_242 ] ) {
F_142 ( & V_237 [ V_242 ] ) ;
F_148 ( L_43 ) ;
fclose ( V_251 ) ;
break;
}
V_242 ++ ;
}
V_254:
fclose ( V_251 ) ;
if ( V_242 >= 32 ) {
F_148 ( L_44
L_45 ) ;
break;
}
}
F_149 ( V_241 ) ;
if ( V_242 ) {
V_243 = F_150 ( V_242 , V_237 ) ;
if ( V_243 < V_242 && V_243 >= 0 ) {
V_240 = F_147 ( V_239 [ V_243 ] ) ;
if ( V_240 ) {
if ( V_255 )
free ( ( void * ) V_256 ) ;
V_256 = V_240 ;
V_255 = true ;
V_149 = 0 ;
} else
F_148 ( L_46 ) ;
}
}
F_141 ( V_237 , V_242 ) ;
F_141 ( V_239 , V_242 ) ;
return V_149 ;
}
static int
F_151 ( struct V_1 * V_8 , struct V_257 * V_258 )
{
struct V_205 * V_206 ;
struct V_259 * V_260 ;
struct V_13 * V_14 ;
int V_198 ;
if ( ! V_261 && F_152 ( V_8 -> V_208 ) )
return 0 ;
V_260 = F_64 ( V_258 -> V_71 . V_104 ) ;
if ( ! V_260 -> V_105 )
return 0 ;
V_206 = F_133 ( V_8 -> V_3 ) ;
V_198 = F_153 ( & V_258 -> V_71 , V_206 , V_8 -> V_82 ) ;
V_14 = F_130 ( V_8 ) ;
if ( ( V_198 == 'q' || V_198 == F_154 ( 'c' ) ) && V_14 -> V_262 )
return 1 ;
F_58 ( & V_8 -> V_24 , V_8 -> V_3 -> V_18 ) ;
if ( V_198 )
F_155 ( & V_8 -> V_24 ) ;
return 0 ;
}
static int
F_156 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 , char * * V_263 ,
struct V_264 * V_264 , struct V_265 * V_104 )
{
if ( V_104 == NULL || V_264 -> V_212 -> V_266 )
return 0 ;
if ( F_76 ( V_263 , L_47 , V_104 -> V_249 ) < 0 )
return 0 ;
V_258 -> V_71 . V_264 = V_264 ;
V_258 -> V_71 . V_104 = V_104 ;
V_258 -> V_267 = F_151 ;
return 1 ;
}
static int
F_157 ( struct V_1 * V_8 , struct V_257 * V_258 )
{
struct V_210 * V_210 = V_258 -> V_210 ;
if ( ( ! F_139 ( V_8 -> V_3 , V_210 ) &&
! F_139 ( V_8 -> V_3 , V_268 ) ) || V_210 == NULL )
return 0 ;
if ( V_8 -> V_3 -> V_214 ) {
F_158 ( V_8 -> V_269 , & V_8 -> V_3 -> V_214 ) ;
F_159 ( V_270 , false ) ;
F_160 ( V_8 -> V_3 -> V_214 ) ;
F_60 () ;
} else {
if ( F_139 ( V_8 -> V_3 , V_210 ) ) {
F_61 ( L_48 ,
V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ,
V_210 -> V_233 ) ;
} else {
F_61 ( L_49 ,
V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ) ;
}
V_8 -> V_3 -> V_214 = F_161 ( V_210 ) ;
F_159 ( V_270 , false ) ;
F_162 ( V_8 -> V_269 , & V_8 -> V_3 -> V_214 ) ;
}
F_163 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_164 ( struct V_1 * V_8 , struct V_257 * V_258 ,
char * * V_263 , struct V_210 * V_210 )
{
int V_149 ;
if ( ( ! F_139 ( V_8 -> V_3 , V_210 ) &&
! F_139 ( V_8 -> V_3 , V_268 ) ) || V_210 == NULL )
return 0 ;
if ( F_139 ( V_8 -> V_3 , V_210 ) ) {
V_149 = F_76 ( V_263 , L_50 ,
V_8 -> V_3 -> V_214 ? L_51 : L_52 ,
V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ,
V_210 -> V_233 ) ;
} else {
V_149 = F_76 ( V_263 , L_53 ,
V_8 -> V_3 -> V_214 ? L_51 : L_52 ,
V_210 -> V_232 ? F_140 ( V_210 ) : L_19 ) ;
}
if ( V_149 < 0 )
return 0 ;
V_258 -> V_210 = V_210 ;
V_258 -> V_267 = F_157 ;
return 1 ;
}
static int
F_165 ( struct V_1 * V_8 , struct V_257 * V_258 )
{
struct V_264 * V_264 = V_258 -> V_71 . V_264 ;
if ( ! F_139 ( V_8 -> V_3 , V_212 ) || V_264 == NULL )
return 0 ;
if ( V_8 -> V_3 -> V_213 ) {
F_158 ( V_8 -> V_269 , & V_8 -> V_3 -> V_213 ) ;
F_159 ( V_271 , false ) ;
V_8 -> V_3 -> V_213 = NULL ;
F_60 () ;
} else {
F_61 ( L_54 ,
F_166 ( V_264 ) ? L_55 : V_264 -> V_212 -> V_234 ) ;
V_8 -> V_3 -> V_213 = V_264 -> V_212 ;
F_159 ( V_271 , true ) ;
F_162 ( V_8 -> V_269 , & V_8 -> V_3 -> V_213 ) ;
}
F_167 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_168 ( struct V_1 * V_8 , struct V_257 * V_258 ,
char * * V_263 , struct V_264 * V_264 )
{
if ( ! F_139 ( V_8 -> V_3 , V_212 ) || V_264 == NULL )
return 0 ;
if ( F_76 ( V_263 , L_56 ,
V_8 -> V_3 -> V_213 ? L_51 : L_52 ,
F_166 ( V_264 ) ? L_55 : V_264 -> V_212 -> V_234 ) < 0 )
return 0 ;
V_258 -> V_71 . V_264 = V_264 ;
V_258 -> V_267 = F_165 ;
return 1 ;
}
static int
F_169 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 )
{
F_170 ( V_258 -> V_71 . V_264 ) ;
return 0 ;
}
static int
F_171 ( struct V_1 * V_8 ,
struct V_257 * V_258 , char * * V_263 , struct V_264 * V_264 )
{
if ( ! F_139 ( V_8 -> V_3 , V_212 ) || V_264 == NULL )
return 0 ;
if ( F_76 ( V_263 , L_57 ) < 0 )
return 0 ;
V_258 -> V_71 . V_264 = V_264 ;
V_258 -> V_267 = F_169 ;
return 1 ;
}
static int
F_172 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 )
{
char V_272 [ 64 ] ;
memset ( V_272 , 0 , sizeof( V_272 ) ) ;
if ( V_258 -> V_210 ) {
F_88 ( V_272 , sizeof( V_272 ) , L_58 ,
F_140 ( V_258 -> V_210 ) ) ;
} else if ( V_258 -> V_71 . V_104 ) {
F_88 ( V_272 , sizeof( V_272 ) , L_59 ,
V_258 -> V_71 . V_104 -> V_249 ) ;
}
F_173 ( V_272 ) ;
return 0 ;
}
static int
F_174 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 , char * * V_263 ,
struct V_210 * V_210 , struct V_265 * V_104 )
{
if ( V_210 ) {
if ( F_76 ( V_263 , L_60 ,
F_140 ( V_210 ) ) < 0 )
return 0 ;
} else if ( V_104 ) {
if ( F_76 ( V_263 , L_61 ,
V_104 -> V_249 ) < 0 )
return 0 ;
} else {
if ( F_76 ( V_263 , L_62 ) < 0 )
return 0 ;
}
V_258 -> V_210 = V_210 ;
V_258 -> V_71 . V_104 = V_104 ;
V_258 -> V_267 = F_172 ;
return 1 ;
}
static int
F_175 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 V_49 )
{
if ( F_143 () ) {
F_148 ( L_63
L_64 ) ;
return 0 ;
}
return V_273 ;
}
static int
F_176 ( struct V_1 * V_8 ,
struct V_257 * V_258 , char * * V_263 )
{
if ( ! F_132 ( V_8 -> V_82 ) )
return 0 ;
if ( F_76 ( V_263 , L_65 ) < 0 )
return 0 ;
V_258 -> V_267 = F_175 ;
return 1 ;
}
static int
F_177 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 V_49 )
{
return 0 ;
}
static int
F_178 ( struct V_1 * V_8 V_49 ,
struct V_257 * V_258 , char * * V_263 )
{
if ( F_76 ( V_263 , L_66 ) < 0 )
return 0 ;
V_258 -> V_267 = F_177 ;
return 1 ;
}
static int
F_179 ( struct V_1 * V_8 , struct V_257 * V_258 )
{
if ( ! F_139 ( V_8 -> V_3 , V_274 ) || V_258 -> V_274 < 0 )
return 0 ;
if ( V_8 -> V_3 -> V_216 > - 1 ) {
F_158 ( V_8 -> V_269 , & V_8 -> V_3 -> V_216 ) ;
V_8 -> V_3 -> V_216 = - 1 ;
F_159 ( V_275 , false ) ;
} else {
V_8 -> V_3 -> V_216 = V_258 -> V_274 ;
F_159 ( V_275 , true ) ;
F_162 ( V_8 -> V_269 , & V_8 -> V_3 -> V_216 ) ;
}
F_180 ( V_8 -> V_3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int
F_181 ( struct V_1 * V_8 , struct V_257 * V_258 ,
char * * V_263 , int V_215 )
{
if ( ! F_139 ( V_8 -> V_3 , V_274 ) || V_215 < 0 )
return 0 ;
if ( F_76 ( V_263 , L_67 ,
( V_8 -> V_3 -> V_216 > - 1 ) ? L_51 : L_52 ,
V_215 ) < 0 )
return 0 ;
V_258 -> V_274 = V_215 ;
V_258 -> V_267 = F_179 ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_4 V_18 = 0 ;
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
static void F_182 ( struct V_1 * V_2 ,
double V_59 )
{
struct V_13 * V_14 ;
struct V_9 * V_10 = F_4 ( & V_2 -> V_3 -> V_12 ) ;
T_4 V_112 = F_85 ( V_2 -> V_3 ) ;
T_4 V_276 = V_112 * ( V_59 / 100 ) ;
V_2 -> V_4 = V_50 . V_277 = V_59 ;
while ( ( V_10 = F_5 ( V_10 , V_2 -> V_4 ) ) != NULL ) {
V_14 = F_7 ( V_10 , struct V_13 , V_9 ) ;
if ( V_14 -> V_57 ) {
V_14 -> V_57 = false ;
V_14 -> V_17 = 0 ;
}
if ( ! V_14 -> V_15 || ! V_5 . V_166 )
goto V_63;
if ( V_50 . V_51 == V_136 ) {
V_112 = V_14 -> V_143 . V_142 ;
if ( V_5 . V_140 )
V_112 = V_14 -> V_141 -> V_142 ;
V_276 = V_112 * ( V_59 / 100 ) ;
}
V_50 . V_278 ( & V_14 -> V_56 , V_14 -> V_279 ,
V_276 , & V_50 ) ;
V_63:
V_10 = F_49 ( V_10 , V_74 ) ;
V_14 -> V_68 = false ;
F_47 ( V_14 , V_2 , false ) ;
}
}
static int F_183 ( struct V_205 * V_206 , int V_90 ,
const char * V_280 ,
bool V_281 ,
struct V_81 * V_82 ,
float V_4 ,
struct V_207 * V_208 )
{
struct V_3 * V_3 = F_128 ( V_206 ) ;
struct V_1 * V_8 = F_127 ( V_206 , V_82 , V_208 ) ;
struct V_262 * V_282 ;
#define F_184 16
char * V_237 [ F_184 ] ;
struct V_257 V_283 [ F_184 ] ;
int V_242 = 0 ;
int V_80 = - 1 ;
char V_116 [ 64 ] ;
int V_83 = V_82 ? V_82 -> V_84 : 0 ;
#define F_185 \
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
const char V_284 [] = F_185
L_68
L_69
L_70
L_71
L_72
L_73
L_74 ;
const char V_285 [] = F_185
L_69
L_72
L_73
L_75
L_76
L_74 ;
if ( V_8 == NULL )
return - 1 ;
F_186 () ;
F_187 ( 0 , 0 , 0 ) ;
if ( V_4 )
V_8 -> V_4 = V_4 ;
F_17 ( V_8 ) ;
V_8 -> V_269 = F_188 ( 3 ) ;
if ( V_8 -> V_269 == NULL )
goto V_97;
F_189 ( V_280 ) ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
memset ( V_283 , 0 , sizeof( V_283 ) ) ;
if ( V_5 . V_286 )
F_190 ( V_5 . V_286 ) ;
while ( 1 ) {
struct V_210 * V_210 = NULL ;
struct V_264 * V_264 = NULL ;
int V_243 = 0 ;
int V_287 = - 1 ;
V_242 = 0 ;
V_80 = F_55 ( V_8 , V_280 ) ;
if ( V_8 -> V_69 != NULL ) {
V_210 = F_131 ( V_8 ) ;
V_264 = V_8 -> V_72 -> V_264 ;
V_287 = V_8 -> V_69 -> V_274 ;
}
switch ( V_80 ) {
case V_288 :
case V_289 :
if ( V_90 == 1 )
continue;
goto V_290;
case 'a' :
if ( ! F_139 ( V_3 , V_104 ) ) {
F_53 ( & V_8 -> V_24 , V_83 * 2 ,
L_77
L_78 ) ;
continue;
}
if ( V_8 -> V_72 == NULL ||
V_8 -> V_72 -> V_104 == NULL ||
V_8 -> V_72 -> V_264 -> V_212 -> V_266 )
continue;
V_283 -> V_71 . V_264 = V_8 -> V_72 -> V_264 ;
V_283 -> V_71 . V_104 = V_8 -> V_72 -> V_104 ;
F_151 ( V_8 , V_283 ) ;
continue;
case 'P' :
F_120 ( V_8 ) ;
continue;
case 'd' :
V_283 -> V_71 . V_264 = V_264 ;
F_165 ( V_8 , V_283 ) ;
continue;
case 'V' :
V_291 = ( V_291 + 1 ) % 4 ;
V_8 -> V_103 = V_291 > 0 ;
F_61 ( L_79 ,
V_291 ) ;
continue;
case 't' :
V_283 -> V_210 = V_210 ;
F_157 ( V_8 , V_283 ) ;
continue;
case 'S' :
V_283 -> V_274 = V_287 ;
F_179 ( V_8 , V_283 ) ;
continue;
case '/' :
if ( F_191 ( L_80 ,
L_81
L_82 ,
V_116 , L_83 ,
V_83 * 2 ) == V_96 ) {
V_3 -> V_292 = * V_116 ? V_116 : NULL ;
F_192 ( V_3 ) ;
F_16 ( V_8 ) ;
}
continue;
case 'r' :
if ( F_132 ( V_82 ) ) {
V_283 -> V_210 = NULL ;
V_283 -> V_71 . V_104 = NULL ;
F_172 ( V_8 , V_283 ) ;
}
continue;
case 's' :
if ( F_132 ( V_82 ) ) {
V_80 = F_175 ( V_8 , V_283 ) ;
if ( V_80 == V_273 )
goto V_290;
}
continue;
case 'i' :
if ( V_208 -> V_293 )
F_193 ( V_208 ) ;
continue;
case 'F' :
V_5 . V_224 ^= 1 ;
continue;
case 'z' :
if ( ! F_132 ( V_82 ) ) {
struct V_235 * V_94 = V_82 -> V_87 ;
V_94 -> V_236 = ! V_94 -> V_236 ;
}
continue;
case 'L' :
if ( F_191 ( L_84 ,
L_85 ,
V_116 , L_83 ,
V_83 * 2 ) == V_96 ) {
char * V_294 ;
double V_295 = strtod ( V_116 , & V_294 ) ;
if ( V_295 < 0 || V_295 > 100 ) {
F_53 ( & V_8 -> V_24 , V_83 * 2 ,
L_86 , V_295 ) ;
continue;
}
F_182 ( V_8 , V_295 ) ;
F_16 ( V_8 ) ;
}
continue;
case V_296 :
case 'h' :
case '?' :
F_194 ( & V_8 -> V_24 ,
F_132 ( V_82 ) ? V_284 : V_285 ) ;
continue;
case V_96 :
case V_297 :
case 'm' :
break;
case V_298 :
case V_299 : {
const void * V_94 ;
if ( F_195 ( V_8 -> V_269 ) ) {
if ( V_281 )
goto V_290;
if ( V_80 == V_298 &&
F_196 ( & V_8 -> V_24 ,
L_87 ) )
goto V_290;
continue;
}
V_94 = F_197 ( V_8 -> V_269 ) ;
if ( V_94 == & V_8 -> V_3 -> V_213 ) {
F_165 ( V_8 , V_283 ) ;
} else if ( V_94 == & V_8 -> V_3 -> V_214 ) {
F_157 ( V_8 , V_283 ) ;
} else if ( V_94 == & V_8 -> V_3 -> V_216 ) {
F_179 ( V_8 , V_283 ) ;
}
continue;
}
case 'q' :
case F_154 ( 'c' ) :
goto V_290;
case 'f' :
if ( ! F_132 ( V_82 ) ) {
struct V_235 * V_94 = V_82 -> V_87 ;
F_198 ( V_94 -> V_300 ) ;
if ( V_94 -> V_300 -> V_301 ) {
V_280 = L_88 ;
V_82 -> V_84 = V_83 ;
} else {
V_280 = L_89 ;
V_82 -> V_84 = 0 ;
}
continue;
}
default:
V_280 = L_90 ;
continue;
}
if ( ! F_139 ( V_3 , V_104 ) || V_8 -> V_72 == NULL )
goto V_302;
if ( V_303 == V_304 ) {
V_282 = V_8 -> V_69 -> V_262 ;
if ( V_282 == NULL )
goto V_302;
V_242 += F_156 ( V_8 ,
& V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_282 -> V_305 . V_264 ,
V_282 -> V_305 . V_104 ) ;
if ( V_282 -> V_306 . V_104 != V_282 -> V_305 . V_104 )
V_242 += F_156 ( V_8 ,
& V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_282 -> V_306 . V_264 ,
V_282 -> V_306 . V_104 ) ;
} else {
V_242 += F_156 ( V_8 ,
& V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_8 -> V_72 -> V_264 ,
V_8 -> V_72 -> V_104 ) ;
}
V_302:
V_242 += F_164 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] , V_210 ) ;
V_242 += F_168 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] , V_264 ) ;
V_242 += F_171 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_8 -> V_72 ?
V_8 -> V_72 -> V_264 : NULL ) ;
V_242 += F_181 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_287 ) ;
if ( ! F_132 ( V_82 ) )
goto V_307;
if ( V_8 -> V_69 ) {
if ( F_139 ( V_3 , V_210 ) && V_210 ) {
V_242 += F_174 ( V_8 ,
& V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
V_210 , NULL ) ;
}
if ( F_139 ( V_3 , V_104 ) && V_8 -> V_72 -> V_104 ) {
V_242 += F_174 ( V_8 ,
& V_283 [ V_242 ] ,
& V_237 [ V_242 ] ,
NULL , V_8 -> V_72 -> V_104 ) ;
}
}
V_242 += F_174 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] , NULL , NULL ) ;
V_242 += F_176 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] ) ;
V_307:
V_242 += F_178 ( V_8 , & V_283 [ V_242 ] ,
& V_237 [ V_242 ] ) ;
do {
struct V_257 * V_258 ;
V_243 = F_150 ( V_242 , V_237 ) ;
if ( V_243 == - 1 || V_243 >= V_242 )
break;
V_258 = & V_283 [ V_243 ] ;
V_80 = V_258 -> V_267 ( V_8 , V_258 ) ;
} while ( V_80 == 1 );
if ( V_80 == V_273 )
break;
}
V_290:
F_199 ( V_8 -> V_269 ) ;
V_97:
F_129 ( V_8 ) ;
F_141 ( V_237 , F_184 ) ;
return V_80 ;
}
static void F_200 ( struct V_23 * V_8 ,
void * V_139 , int V_36 )
{
struct V_308 * V_309 = F_11 ( V_8 ,
struct V_308 , V_24 ) ;
struct V_205 * V_206 = F_37 ( V_139 , struct V_205 , V_43 ) ;
struct V_3 * V_3 = F_128 ( V_206 ) ;
bool V_151 = F_65 ( V_8 , V_36 ) ;
unsigned long V_90 = V_3 -> V_88 . V_90 [ V_218 ] ;
const char * V_220 = F_134 ( V_206 ) ;
char V_76 [ 256 ] , V_211 ;
const char * V_310 = L_8 ;
T_3 V_110 ;
F_66 ( V_8 , V_151 ? V_107 :
V_106 ) ;
if ( F_135 ( V_206 ) ) {
struct V_205 * V_227 ;
V_220 = F_201 ( V_206 ) ;
F_137 (pos, evsel) {
struct V_3 * V_228 = F_128 ( V_227 ) ;
V_90 += V_228 -> V_88 . V_90 [ V_218 ] ;
}
}
V_90 = F_138 ( V_90 , & V_211 ) ;
V_110 = F_88 ( V_76 , sizeof( V_76 ) , L_91 , V_90 ,
V_211 , V_211 == ' ' ? L_19 : L_8 , V_220 ) ;
F_68 ( V_8 , L_6 , V_76 ) ;
V_90 = V_3 -> V_88 . V_90 [ V_91 ] ;
if ( V_90 != 0 ) {
V_309 -> V_311 = true ;
if ( ! V_151 )
F_66 ( V_8 , V_312 ) ;
V_90 = F_138 ( V_90 , & V_211 ) ;
V_110 += F_88 ( V_76 , sizeof( V_76 ) , L_92 ,
V_90 , V_211 , V_211 == ' ' ? L_19 : L_8 ) ;
V_310 = V_76 ;
}
F_67 ( V_8 , V_310 , V_8 -> V_35 - V_110 ) ;
if ( V_151 )
V_309 -> V_72 = V_206 ;
}
static int F_202 ( struct V_308 * V_309 ,
int V_90 , const char * V_79 ,
struct V_81 * V_82 )
{
struct V_313 * V_300 = V_309 -> V_24 . V_314 ;
struct V_205 * V_227 ;
const char * V_78 = L_93 ;
int V_83 = V_82 ? V_82 -> V_84 : 0 ;
int V_80 ;
if ( F_56 ( & V_309 -> V_24 , V_78 ,
L_94 ) < 0 )
return - 1 ;
while ( 1 ) {
V_80 = F_57 ( & V_309 -> V_24 , V_83 ) ;
switch ( V_80 ) {
case V_85 :
V_82 -> V_86 ( V_82 -> V_87 ) ;
if ( ! V_309 -> V_315 && V_309 -> V_311 ) {
F_52 ( & V_309 -> V_24 ) ;
V_309 -> V_315 = true ;
}
continue;
case V_297 :
case V_96 :
if ( ! V_309 -> V_72 )
continue;
V_227 = V_309 -> V_72 ;
V_316:
F_203 ( V_300 , V_227 ) ;
if ( V_82 )
V_82 -> V_86 ( V_82 -> V_87 ) ;
V_80 = F_183 ( V_227 , V_90 , V_79 ,
true , V_82 ,
V_309 -> V_4 ,
V_309 -> V_208 ) ;
F_59 ( & V_309 -> V_24 , V_78 ) ;
switch ( V_80 ) {
case V_288 :
if ( V_227 -> V_43 . V_63 == & V_300 -> V_12 )
V_227 = F_204 ( V_300 ) ;
else
V_227 = F_205 ( V_227 ) ;
goto V_316;
case V_289 :
if ( V_227 -> V_43 . V_66 == & V_300 -> V_12 )
V_227 = F_206 ( V_300 ) ;
else
V_227 = F_207 ( V_227 ) ;
goto V_316;
case V_273 :
case 'q' :
case F_154 ( 'c' ) :
goto V_97;
case V_298 :
default:
continue;
}
case V_299 :
continue;
case V_298 :
if ( ! F_196 ( & V_309 -> V_24 ,
L_87 ) )
continue;
case 'q' :
case F_154 ( 'c' ) :
goto V_97;
default:
continue;
}
}
V_97:
F_62 ( & V_309 -> V_24 ) ;
return V_80 ;
}
static bool F_208 ( struct V_23 * V_8 V_49 ,
void * V_139 )
{
struct V_205 * V_206 = F_37 ( V_139 , struct V_205 , V_43 ) ;
if ( V_5 . V_317 && ! F_209 ( V_206 ) )
return true ;
return false ;
}
static int F_210 ( struct V_313 * V_300 ,
int V_18 , const char * V_79 ,
struct V_81 * V_82 ,
float V_4 ,
struct V_207 * V_208 )
{
struct V_205 * V_227 ;
struct V_308 V_309 = {
. V_24 = {
. V_12 = & V_300 -> V_12 ,
. V_84 = V_318 ,
. V_201 = V_319 ,
. V_320 = F_200 ,
. V_321 = F_208 ,
. V_18 = V_18 ,
. V_314 = V_300 ,
} ,
. V_4 = V_4 ,
. V_208 = V_208 ,
} ;
F_189 ( L_95 ) ;
F_211 (evlist, pos) {
const char * V_220 = F_134 ( V_227 ) ;
T_3 V_322 = strlen ( V_220 ) + 7 ;
if ( V_309 . V_24 . V_35 < V_322 )
V_309 . V_24 . V_35 = V_322 ;
}
return F_202 ( & V_309 , V_18 , V_79 , V_82 ) ;
}
int F_212 ( struct V_313 * V_300 , const char * V_79 ,
struct V_81 * V_82 ,
float V_4 ,
struct V_207 * V_208 )
{
int V_18 = V_300 -> V_18 ;
V_323:
if ( V_18 == 1 ) {
struct V_205 * V_61 = F_204 ( V_300 ) ;
return F_183 ( V_61 , V_18 , V_79 ,
false , V_82 , V_4 ,
V_208 ) ;
}
if ( V_5 . V_317 ) {
struct V_205 * V_227 ;
V_18 = 0 ;
F_211 (evlist, pos) {
if ( F_209 ( V_227 ) )
V_18 ++ ;
}
if ( V_18 == 1 )
goto V_323;
}
return F_210 ( V_300 , V_18 , V_79 ,
V_82 , V_4 , V_208 ) ;
}
