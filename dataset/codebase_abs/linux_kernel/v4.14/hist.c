static T_1 F_1 ( T_2 * V_1 , int V_2 )
{
int V_3 ;
int V_4 = fprintf ( V_1 , L_1 ) ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 += fprintf ( V_1 , L_2 ) ;
return V_4 ;
}
static T_1 F_2 ( struct V_5 * V_5 , T_3 V_6 , int V_2 ,
int V_7 , int V_8 , T_2 * V_1 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_4 = 0 , V_3 ;
if ( V_5 == NULL )
return 0 ;
V_9 = V_5 -> V_9 ;
if ( V_9 == NULL )
return 0 ;
V_11 = F_3 ( V_9 ,
F_4 ( V_5 , V_6 ) ) ;
if ( V_11 == NULL )
return 0 ;
F_5 (ilist, &node->val, list) {
if ( ( V_13 -> V_14 != NULL ) || ( V_13 -> V_15 != NULL ) ) {
V_4 += F_1 ( V_1 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_8 & ( 1 << V_3 ) )
V_4 += fprintf ( V_1 , L_3 ) ;
else
V_4 += fprintf ( V_1 , L_2 ) ;
V_4 += fprintf ( V_1 , L_4 ) ;
}
if ( V_16 . V_17 == V_18 ||
V_16 . V_17 == V_19 ) {
if ( V_13 -> V_14 != NULL )
V_4 += fprintf ( V_1 , L_5 ,
V_13 -> V_14 ,
V_13 -> V_20 ) ;
else
V_4 += fprintf ( V_1 , L_6 ) ;
} else if ( V_13 -> V_15 != NULL )
V_4 += fprintf ( V_1 , L_7 ,
V_13 -> V_15 ) ;
else if ( V_13 -> V_14 != NULL )
V_4 += fprintf ( V_1 , L_5 ,
V_13 -> V_14 ,
V_13 -> V_20 ) ;
else
V_4 += fprintf ( V_1 , L_6 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
}
}
F_6 ( V_11 ) ;
return V_4 ;
}
static T_1 F_7 ( T_2 * V_1 , int V_7 , int V_8 ,
int V_2 )
{
int V_3 ;
T_1 V_4 = F_1 ( V_1 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
if ( V_8 & ( 1 << V_3 ) )
V_4 += fprintf ( V_1 , L_9 ) ;
else
V_4 += fprintf ( V_1 , L_10 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
return V_4 ;
}
static T_1 F_8 ( T_2 * V_1 , struct V_21 * V_11 ,
struct V_22 * V_23 ,
int V_7 , int V_8 , int V_24 ,
T_3 V_25 , int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
char V_26 [ 1024 ] , * V_27 = NULL ;
char V_28 [ 64 ] ;
const char * V_29 ;
V_4 += F_1 ( V_1 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_8 & ( 1 << V_3 ) )
V_4 += fprintf ( V_1 , L_3 ) ;
else
V_4 += fprintf ( V_1 , L_2 ) ;
if ( ! V_24 && V_3 == V_7 - 1 ) {
V_4 += fprintf ( V_1 , L_11 ) ;
V_4 += F_9 ( V_11 , V_1 , V_25 ) ;
V_4 += fprintf ( V_1 , L_11 ) ;
} else
V_4 += fprintf ( V_1 , L_12 , L_4 ) ;
}
V_29 = F_10 ( V_23 , V_26 , sizeof( V_26 ) , false ) ;
if ( V_30 . V_31 ) {
F_11 ( V_23 , NULL ,
V_28 , sizeof( V_28 ) ) ;
if ( F_12 ( & V_27 , L_13 , V_29 , V_28 ) < 0 )
V_29 = L_14 ;
else
V_29 = V_27 ;
}
fputs ( V_29 , V_1 ) ;
fputc ( '\n' , V_1 ) ;
free ( V_27 ) ;
if ( V_30 . V_32 )
V_4 += F_2 ( V_23 -> V_33 . V_5 , V_23 -> V_6 ,
V_2 , V_7 , V_8 , V_1 ) ;
return V_4 ;
}
static void F_13 ( void )
{
V_34 = malloc ( sizeof( * V_34 ) + 6 ) ;
if ( ! V_34 ) {
fprintf ( V_35 , L_15 ) ;
return;
}
strcpy ( V_34 -> V_36 , L_16 ) ;
V_37 . V_33 . V_38 = V_34 ;
}
static T_1 F_14 ( T_2 * V_1 , struct V_39 * V_40 ,
T_3 V_25 , int V_7 ,
int V_8 , int V_2 )
{
struct V_41 * V_11 , * V_42 ;
struct V_21 * V_43 = NULL ;
struct V_22 * V_23 ;
int V_44 = V_8 ;
T_3 V_45 ;
T_1 V_4 = 0 ;
int V_3 ;
T_4 V_46 = 0 ;
int V_47 = 0 ;
V_45 = V_25 ;
V_11 = F_15 ( V_40 ) ;
while ( V_11 ) {
T_3 V_48 ;
T_3 V_49 ;
V_43 = F_16 ( V_11 , struct V_21 , V_41 ) ;
V_49 = F_17 ( V_43 ) ;
V_45 -= V_49 ;
V_47 += F_18 ( V_43 ) ;
V_42 = F_19 ( V_11 ) ;
if ( ! V_42 && ( V_16 . V_50 != V_51 || ! V_45 ) )
V_44 &= ~ ( 1 << ( V_7 - 1 ) ) ;
V_4 += F_7 ( V_1 , V_7 , V_8 ,
V_2 ) ;
V_3 = 0 ;
F_5 (chain, &child->val, list) {
V_4 += F_8 ( V_1 , V_43 , V_23 , V_7 ,
V_44 , V_3 ++ ,
V_25 ,
V_2 ) ;
}
if ( V_16 . V_50 == V_51 )
V_48 = V_43 -> V_52 ;
else
V_48 = V_25 ;
V_4 += F_14 ( V_1 , & V_43 -> V_39 , V_48 ,
V_7 + 1 ,
V_44 | ( 1 << V_7 ) ,
V_2 ) ;
V_11 = V_42 ;
if ( ++ V_46 == V_16 . V_53 )
break;
}
if ( V_16 . V_50 == V_51 &&
V_45 && V_45 != V_25 ) {
struct V_21 V_54 = {
. V_55 = V_45 ,
} ;
if ( ! V_34 )
return V_4 ;
if ( V_16 . V_56 == V_57 && V_43 && V_43 -> V_58 ) {
V_54 . V_59 = V_43 -> V_58 -> V_60 - V_47 ;
if ( V_54 . V_59 <= 0 )
return V_4 ;
}
V_44 &= ~ ( 1 << ( V_7 - 1 ) ) ;
V_4 += F_8 ( V_1 , & V_54 , & V_37 , V_7 ,
V_44 , 0 , V_25 ,
V_2 ) ;
}
return V_4 ;
}
static bool F_20 ( struct V_41 * V_11 , T_3 V_61 )
{
struct V_21 * V_62 ;
if ( F_19 ( V_11 ) )
return true ;
V_62 = F_16 ( V_11 , struct V_21 , V_41 ) ;
return F_17 ( V_62 ) != V_61 ;
}
static T_1 F_21 ( T_2 * V_1 , struct V_39 * V_40 ,
T_3 V_25 , T_3 V_61 ,
int V_2 )
{
struct V_21 * V_62 ;
struct V_22 * V_23 ;
T_5 V_46 = 0 ;
bool V_63 = false ;
struct V_41 * V_11 ;
int V_3 = 0 ;
int V_4 = 0 ;
char V_26 [ 1024 ] ;
V_11 = F_15 ( V_40 ) ;
if ( V_11 && ! F_20 ( V_11 , V_61 ) ) {
V_62 = F_16 ( V_11 , struct V_21 , V_41 ) ;
F_5 (chain, &cnode->val, list) {
if ( ! V_3 ++ && V_64 == NULL &&
V_65 && F_22 ( V_65 , L_17 ) )
continue;
if ( ! V_63 ) {
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_18 ) ;
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_19 ) ;
V_2 += 3 ;
V_63 = true ;
} else
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_12 ,
F_10 ( V_23 , V_26 ,
sizeof( V_26 ) ,
false ) ) ;
if ( V_30 . V_31 )
V_4 += F_11 (
V_23 , V_1 , NULL , 0 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_46 == V_16 . V_53 )
break;
if ( V_30 . V_32 )
V_4 += F_2 ( V_23 -> V_33 . V_5 ,
V_23 -> V_6 ,
V_2 ,
0 , 0 ,
V_1 ) ;
}
V_40 = & V_62 -> V_39 ;
}
if ( V_16 . V_50 == V_51 )
V_25 = V_61 ;
V_4 += F_14 ( V_1 , V_40 , V_25 ,
1 , 1 , V_2 ) ;
if ( V_4 ) {
V_4 += fprintf ( V_1 , L_8 ) ;
}
return V_4 ;
}
static T_1 F_23 ( T_2 * V_1 , struct V_21 * V_11 ,
T_3 V_25 )
{
struct V_22 * V_23 ;
T_1 V_4 = 0 ;
char V_26 [ 1024 ] ;
if ( ! V_11 )
return 0 ;
V_4 += F_23 ( V_1 , V_11 -> V_58 , V_25 ) ;
F_5 (chain, &node->val, list) {
if ( V_23 -> V_6 >= V_66 )
continue;
V_4 += fprintf ( V_1 , L_20 , F_10 ( V_23 ,
V_26 , sizeof( V_26 ) , false ) ) ;
}
return V_4 ;
}
static T_1 F_24 ( T_2 * V_1 , struct V_39 * V_67 ,
T_3 V_25 )
{
T_1 V_4 = 0 ;
T_5 V_46 = 0 ;
struct V_21 * V_23 ;
struct V_41 * V_41 = F_15 ( V_67 ) ;
while ( V_41 ) {
V_23 = F_16 ( V_41 , struct V_21 , V_41 ) ;
V_4 += fprintf ( V_1 , L_10 ) ;
V_4 += F_9 ( V_23 , V_1 , V_25 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
V_4 += F_23 ( V_1 , V_23 , V_25 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_46 == V_16 . V_53 )
break;
V_41 = F_19 ( V_41 ) ;
}
return V_4 ;
}
static T_1 F_25 ( T_2 * V_1 , struct V_21 * V_11 )
{
const char * V_68 = V_30 . V_69 ? : L_21 ;
struct V_22 * V_23 ;
T_1 V_4 = 0 ;
char V_26 [ 1024 ] ;
bool V_70 ;
if ( ! V_11 )
return 0 ;
V_4 += F_25 ( V_1 , V_11 -> V_58 ) ;
V_70 = ( V_4 == 0 ) ;
F_5 (chain, &node->val, list) {
if ( V_23 -> V_6 >= V_66 )
continue;
V_4 += fprintf ( V_1 , L_13 , V_70 ? L_22 : V_68 ,
F_10 ( V_23 ,
V_26 , sizeof( V_26 ) , false ) ) ;
V_70 = false ;
}
return V_4 ;
}
static T_1 F_26 ( T_2 * V_1 , struct V_39 * V_67 ,
T_3 V_25 )
{
T_1 V_4 = 0 ;
T_5 V_46 = 0 ;
struct V_21 * V_23 ;
struct V_41 * V_41 = F_15 ( V_67 ) ;
while ( V_41 ) {
V_23 = F_16 ( V_41 , struct V_21 , V_41 ) ;
V_4 += F_9 ( V_23 , V_1 , V_25 ) ;
V_4 += fprintf ( V_1 , L_2 ) ;
V_4 += F_25 ( V_1 , V_23 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_46 == V_16 . V_53 )
break;
V_41 = F_19 ( V_41 ) ;
}
return V_4 ;
}
static T_1 F_27 ( struct V_71 * V_72 ,
T_3 V_25 , int V_2 ,
T_2 * V_1 )
{
T_3 V_61 = V_72 -> V_73 . V_24 ;
if ( V_30 . V_74 )
V_61 = V_72 -> V_75 -> V_24 ;
switch ( V_16 . V_50 ) {
case V_51 :
return F_21 ( V_1 , & V_72 -> V_76 , V_25 ,
V_61 , V_2 ) ;
break;
case V_77 :
return F_21 ( V_1 , & V_72 -> V_76 , V_25 ,
V_61 , V_2 ) ;
break;
case V_78 :
return F_24 ( V_1 , & V_72 -> V_76 , V_25 ) ;
break;
case V_79 :
return F_26 ( V_1 , & V_72 -> V_76 , V_25 ) ;
break;
case V_80 :
break;
default:
F_28 ( L_23 ) ;
}
return 0 ;
}
int F_29 ( struct V_71 * V_72 , struct V_81 * V_82 ,
struct V_83 * V_84 )
{
const char * V_68 = V_30 . V_69 ;
struct V_85 * V_86 ;
char * V_87 = V_82 -> V_28 ;
int V_4 ;
bool V_70 = true ;
if ( V_30 . V_88 && ! V_72 -> V_58 )
return 0 ;
F_30 (hpp_list, fmt) {
if ( F_31 ( V_86 , V_72 -> V_89 ) )
continue;
if ( ! V_68 || ! V_70 ) {
V_4 = F_32 ( V_82 -> V_28 , V_82 -> V_90 , L_12 , V_68 ? : L_24 ) ;
F_33 ( V_82 , V_4 ) ;
} else
V_70 = false ;
if ( F_34 () && V_86 -> V_91 )
V_4 = V_86 -> V_91 ( V_86 , V_82 , V_72 ) ;
else
V_4 = V_86 -> V_92 ( V_86 , V_82 , V_72 ) ;
V_4 = F_35 ( V_72 , V_82 , V_86 , V_4 ) ;
F_33 ( V_82 , V_4 ) ;
}
return V_82 -> V_28 - V_87 ;
}
static int F_36 ( struct V_71 * V_72 , struct V_81 * V_82 )
{
return F_29 ( V_72 , V_82 , V_72 -> V_89 -> V_84 ) ;
}
static int F_37 ( struct V_71 * V_72 ,
struct V_81 * V_82 ,
struct V_89 * V_89 ,
T_2 * V_1 )
{
const char * V_68 = V_30 . V_69 ;
struct V_85 * V_86 ;
struct V_93 * V_94 ;
char * V_28 = V_82 -> V_28 ;
T_1 V_90 = V_82 -> V_90 ;
int V_4 , V_63 = 0 ;
bool V_70 = true ;
if ( V_30 . V_88 && ! V_72 -> V_58 )
return 0 ;
V_4 = F_32 ( V_82 -> V_28 , V_82 -> V_90 , L_25 , V_72 -> V_7 * V_95 , L_22 ) ;
F_33 ( V_82 , V_4 ) ;
V_94 = F_38 ( & V_89 -> V_96 ,
struct V_93 , V_97 ) ;
F_30 (&fmt_node->hpp, fmt) {
if ( ! V_68 || ! V_70 ) {
V_4 = F_32 ( V_82 -> V_28 , V_82 -> V_90 , L_12 , V_68 ? : L_24 ) ;
F_33 ( V_82 , V_4 ) ;
} else
V_70 = false ;
if ( F_34 () && V_86 -> V_91 )
V_4 = V_86 -> V_91 ( V_86 , V_82 , V_72 ) ;
else
V_4 = V_86 -> V_92 ( V_86 , V_82 , V_72 ) ;
V_4 = F_35 ( V_72 , V_82 , V_86 , V_4 ) ;
F_33 ( V_82 , V_4 ) ;
}
if ( ! V_68 )
V_4 = F_32 ( V_82 -> V_28 , V_82 -> V_90 , L_25 ,
( V_89 -> V_98 - 2 ) * V_95 , L_22 ) ;
F_33 ( V_82 , V_4 ) ;
V_63 += fprintf ( V_1 , L_12 , V_28 ) ;
F_30 (he->hpp_list, fmt) {
V_82 -> V_28 = V_28 ;
V_82 -> V_90 = V_90 ;
if ( F_34 () && V_86 -> V_91 )
V_86 -> V_91 ( V_86 , V_82 , V_72 ) ;
else
V_86 -> V_92 ( V_86 , V_82 , V_72 ) ;
V_63 += fprintf ( V_1 , L_13 , V_68 ? : L_24 , F_39 ( V_28 ) ) ;
}
V_63 += putc ( '\n' , V_1 ) ;
if ( V_30 . V_99 && V_72 -> V_100 ) {
T_3 V_101 = F_40 ( V_89 ) ;
V_63 += F_27 ( V_72 , V_101 , 0 , V_1 ) ;
goto V_102;
}
V_102:
return V_63 ;
}
static int F_41 ( struct V_71 * V_72 , T_1 V_90 ,
char * V_26 , T_1 V_103 , T_2 * V_1 ,
bool V_99 )
{
int V_4 ;
int V_104 = 0 ;
int V_105 = 0 ;
struct V_81 V_82 = {
. V_28 = V_26 ,
. V_90 = V_90 ,
} ;
struct V_89 * V_89 = V_72 -> V_89 ;
T_3 V_106 = V_89 -> V_107 . V_106 ;
if ( V_90 == 0 || V_90 > V_103 )
V_90 = V_82 . V_90 = V_103 ;
if ( V_30 . V_108 )
return F_37 ( V_72 , & V_82 , V_89 , V_1 ) ;
F_36 ( V_72 , & V_82 ) ;
V_4 = fprintf ( V_1 , L_26 , V_26 ) ;
if ( V_99 )
V_104 = F_27 ( V_72 , V_106 ,
0 , V_1 ) ;
if ( V_104 == 0 && V_30 . V_32 ) {
V_105 = F_2 ( V_72 -> V_33 . V_5 , V_72 -> V_6 , 0 , 0 , 0 , V_1 ) ;
V_4 += V_105 ;
if ( V_105 > 0 )
V_4 += fprintf ( V_1 , L_8 ) ;
} else
V_4 += V_104 ;
return V_4 ;
}
static int F_42 ( const char * V_68 , int V_109 ,
const char * line , T_2 * V_1 )
{
if ( V_68 != NULL || V_109 < 2 )
return 0 ;
return fprintf ( V_1 , L_27 , ( V_109 - 2 ) * V_95 , line ) ;
}
static int F_43 ( struct V_89 * V_89 ,
struct V_81 * V_82 , T_2 * V_1 )
{
bool V_110 , V_111 ;
int V_109 ;
int V_7 ;
unsigned V_112 = 0 ;
unsigned V_113 = 0 ;
struct V_85 * V_86 ;
struct V_93 * V_94 ;
const char * V_68 = V_30 . V_69 ;
V_109 = V_89 -> V_98 ;
F_42 ( V_68 , V_109 , V_114 , V_1 ) ;
V_94 = F_38 ( & V_89 -> V_96 ,
struct V_93 , V_97 ) ;
F_30 (&fmt_node->hpp, fmt) {
V_86 -> V_115 ( V_86 , V_82 , V_89 , 0 , NULL ) ;
fprintf ( V_1 , L_13 , V_82 -> V_28 , V_68 ? : L_24 ) ;
}
V_110 = true ;
F_44 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_110 )
V_113 += fprintf ( V_1 , L_28 ) ;
V_110 = false ;
V_111 = true ;
F_30 (&fmt_node->hpp, fmt) {
if ( F_31 ( V_86 , V_89 ) )
continue;
if ( ! V_111 )
V_113 += fprintf ( V_1 , L_29 ) ;
V_111 = false ;
V_86 -> V_115 ( V_86 , V_82 , V_89 , 0 , NULL ) ;
V_113 += fprintf ( V_1 , L_12 , F_45 ( V_82 -> V_28 ) ) ;
}
}
fprintf ( V_1 , L_30 ) ;
F_42 ( V_68 , V_109 , V_116 , V_1 ) ;
V_94 = F_38 ( & V_89 -> V_96 ,
struct V_93 , V_97 ) ;
V_111 = true ;
F_30 (&fmt_node->hpp, fmt) {
if ( ! V_111 )
fprintf ( V_1 , L_12 , V_68 ? : L_31 ) ;
V_111 = false ;
V_112 = V_86 -> V_112 ( V_86 , V_82 , V_89 ) ;
fprintf ( V_1 , L_32 , V_112 , V_116 ) ;
}
V_7 = 0 ;
F_44 (fmt_node, &hists->hpp_formats, list) {
V_111 = true ;
V_112 = V_7 * V_95 ;
F_30 (&fmt_node->hpp, fmt) {
if ( F_31 ( V_86 , V_89 ) )
continue;
if ( ! V_111 )
V_112 ++ ;
V_111 = false ;
V_112 += V_86 -> V_112 ( V_86 , V_82 , V_89 ) ;
}
if ( V_112 > V_113 )
V_113 = V_112 ;
V_7 ++ ;
}
fprintf ( V_1 , L_33 , V_68 ? : L_24 , V_113 , V_116 ) ;
fprintf ( V_1 , L_34 ) ;
return 2 ;
}
static void F_46 ( struct V_89 * V_89 , struct V_81 * V_82 ,
int line , T_2 * V_1 )
{
struct V_85 * V_86 ;
const char * V_68 = V_30 . V_69 ;
bool V_70 = true ;
int V_117 = 0 ;
F_47 (hists, fmt) {
if ( F_31 ( V_86 , V_89 ) )
continue;
if ( ! V_70 && ! V_117 )
fprintf ( V_1 , L_12 , V_68 ? : L_24 ) ;
else
V_70 = false ;
V_86 -> V_115 ( V_86 , V_82 , V_89 , line , & V_117 ) ;
if ( ! V_117 )
fprintf ( V_1 , L_12 , V_82 -> V_28 ) ;
}
}
static int
F_48 ( struct V_89 * V_89 ,
struct V_81 * V_82 ,
T_2 * V_1 )
{
struct V_83 * V_84 = V_89 -> V_84 ;
struct V_85 * V_86 ;
unsigned int V_112 ;
const char * V_68 = V_30 . V_69 ;
bool V_70 = true ;
int line ;
for ( line = 0 ; line < V_84 -> V_118 ; line ++ ) {
if ( line )
fprintf ( V_1 , L_35 ) ;
F_46 ( V_89 , V_82 , line , V_1 ) ;
fprintf ( V_1 , L_8 ) ;
}
if ( V_68 )
return V_84 -> V_118 ;
V_70 = true ;
fprintf ( V_1 , L_35 ) ;
F_47 (hists, fmt) {
unsigned int V_3 ;
if ( F_31 ( V_86 , V_89 ) )
continue;
if ( ! V_70 )
fprintf ( V_1 , L_12 , V_68 ? : L_24 ) ;
else
V_70 = false ;
V_112 = V_86 -> V_112 ( V_86 , V_82 , V_89 ) ;
for ( V_3 = 0 ; V_3 < V_112 ; V_3 ++ )
fprintf ( V_1 , L_36 ) ;
}
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_37 ) ;
return V_84 -> V_118 + 2 ;
}
int F_49 ( struct V_89 * V_89 , T_2 * V_1 )
{
char V_26 [ 1024 ] ;
struct V_81 V_119 = {
. V_28 = V_26 ,
. V_90 = sizeof( V_26 ) ,
} ;
fprintf ( V_1 , L_35 ) ;
if ( V_30 . V_108 )
return F_43 ( V_89 , & V_119 , V_1 ) ;
else
return F_48 ( V_89 , & V_119 , V_1 ) ;
}
T_1 F_50 ( struct V_89 * V_89 , bool V_120 , int V_121 ,
int V_122 , float V_123 , T_2 * V_1 ,
bool V_99 )
{
struct V_41 * V_124 ;
T_1 V_4 = 0 ;
const char * V_68 = V_30 . V_69 ;
int V_125 = 0 ;
T_1 V_126 ;
char * line = NULL ;
unsigned V_109 ;
F_13 () ;
F_51 ( V_89 ) ;
if ( V_30 . V_127 )
F_52 ( V_30 . V_127 ) ;
if ( V_120 )
V_125 += F_49 ( V_89 , V_1 ) ;
if ( V_121 && V_125 >= V_121 )
goto V_102;
V_126 = F_53 ( V_89 ) + 3 + 1 ;
V_126 += F_54 () ;
line = malloc ( V_126 ) ;
if ( line == NULL ) {
V_4 = - 1 ;
goto V_102;
}
V_109 = F_55 ( V_89 ) + 4 ;
for ( V_124 = F_15 ( & V_89 -> V_128 ) ; V_124 ; V_124 = F_56 ( V_124 , V_129 ) ) {
struct V_71 * V_130 = F_16 ( V_124 , struct V_71 , V_41 ) ;
float V_131 ;
if ( V_130 -> V_132 )
continue;
V_131 = F_57 ( V_130 ) ;
if ( V_131 < V_123 )
continue;
V_4 += F_41 ( V_130 , V_122 , line , V_126 , V_1 , V_99 ) ;
if ( V_121 && ++ V_125 >= V_121 )
break;
if ( ! V_130 -> V_100 && ! F_58 ( V_130 , V_123 ) ) {
int V_7 = V_89 -> V_98 + V_130 -> V_7 + 1 ;
F_42 ( V_68 , V_7 , V_114 , V_1 ) ;
fprintf ( V_1 , L_38 , V_109 , L_22 , V_123 ) ;
if ( V_121 && ++ V_125 >= V_121 )
break;
}
if ( V_130 -> V_33 . V_5 == NULL && V_133 > 1 ) {
F_59 ( V_130 -> V_134 -> V_135 ,
V_136 , V_1 ) ;
fprintf ( V_1 , L_39 , V_137 ) ;
}
}
free ( line ) ;
V_102:
F_60 ( & V_34 ) ;
return V_4 ;
}
T_1 F_61 ( struct V_138 * V_107 , T_2 * V_1 )
{
int V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_139 ; ++ V_3 ) {
const char * V_36 ;
if ( V_107 -> V_140 [ V_3 ] == 0 )
continue;
V_36 = F_62 ( V_3 ) ;
if ( ! strcmp ( V_36 , L_40 ) )
continue;
V_4 += fprintf ( V_1 , L_41 , V_36 ,
V_107 -> V_140 [ V_3 ] ) ;
}
return V_4 ;
}
