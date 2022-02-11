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
if ( V_9 -> V_14 != V_15 )
return 0 ;
V_11 = F_3 ( V_9 ,
F_4 ( V_5 , V_6 ) ) ;
if ( V_11 == NULL )
return 0 ;
F_5 (ilist, &node->val, list) {
if ( ( V_13 -> V_16 != NULL ) || ( V_13 -> V_17 != NULL ) ) {
V_4 += F_1 ( V_1 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_8 & ( 1 << V_3 ) )
V_4 += fprintf ( V_1 , L_3 ) ;
else
V_4 += fprintf ( V_1 , L_2 ) ;
V_4 += fprintf ( V_1 , L_4 ) ;
}
if ( V_18 . V_19 == V_20 ||
V_18 . V_19 == V_21 ) {
if ( V_13 -> V_16 != NULL )
V_4 += fprintf ( V_1 , L_5 ,
V_13 -> V_16 ,
V_13 -> V_22 ) ;
else
V_4 += fprintf ( V_1 , L_6 ) ;
} else if ( V_13 -> V_17 != NULL )
V_4 += fprintf ( V_1 , L_7 ,
V_13 -> V_17 ) ;
else if ( V_13 -> V_16 != NULL )
V_4 += fprintf ( V_1 , L_5 ,
V_13 -> V_16 ,
V_13 -> V_22 ) ;
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
static T_1 F_8 ( T_2 * V_1 , struct V_23 * V_11 ,
struct V_24 * V_25 ,
int V_7 , int V_8 , int V_26 ,
T_3 V_27 , int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
char V_28 [ 1024 ] , * V_29 = NULL ;
char V_30 [ 64 ] ;
const char * V_31 ;
V_4 += F_1 ( V_1 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_8 & ( 1 << V_3 ) )
V_4 += fprintf ( V_1 , L_3 ) ;
else
V_4 += fprintf ( V_1 , L_2 ) ;
if ( ! V_26 && V_3 == V_7 - 1 ) {
V_4 += fprintf ( V_1 , L_11 ) ;
V_4 += F_9 ( V_11 , V_1 , V_27 ) ;
V_4 += fprintf ( V_1 , L_11 ) ;
} else
V_4 += fprintf ( V_1 , L_12 , L_4 ) ;
}
V_31 = F_10 ( V_25 , V_28 , sizeof( V_28 ) , false ) ;
if ( V_32 . V_33 ) {
if ( ! V_26 )
F_11 ( V_11 , V_25 , NULL ,
V_30 , sizeof( V_30 ) ) ;
else
F_11 ( NULL , V_25 , NULL ,
V_30 , sizeof( V_30 ) ) ;
if ( F_12 ( & V_29 , L_13 , V_31 , V_30 ) < 0 )
V_31 = L_14 ;
else
V_31 = V_29 ;
}
fputs ( V_31 , V_1 ) ;
fputc ( '\n' , V_1 ) ;
free ( V_29 ) ;
if ( V_32 . V_34 )
V_4 += F_2 ( V_25 -> V_35 . V_5 , V_25 -> V_6 ,
V_2 , V_7 , V_8 , V_1 ) ;
return V_4 ;
}
static void F_13 ( void )
{
V_36 = malloc ( sizeof( * V_36 ) + 6 ) ;
if ( ! V_36 ) {
fprintf ( V_37 , L_15 ) ;
return;
}
strcpy ( V_36 -> V_38 , L_16 ) ;
V_39 . V_35 . V_40 = V_36 ;
}
static T_1 F_14 ( T_2 * V_1 , struct V_41 * V_42 ,
T_3 V_27 , int V_7 ,
int V_8 , int V_2 )
{
struct V_43 * V_11 , * V_44 ;
struct V_23 * V_45 = NULL ;
struct V_24 * V_25 ;
int V_46 = V_8 ;
T_3 V_47 ;
T_1 V_4 = 0 ;
int V_3 ;
T_4 V_48 = 0 ;
int V_49 = 0 ;
V_47 = V_27 ;
V_11 = F_15 ( V_42 ) ;
while ( V_11 ) {
T_3 V_50 ;
T_3 V_51 ;
V_45 = F_16 ( V_11 , struct V_23 , V_43 ) ;
V_51 = F_17 ( V_45 ) ;
V_47 -= V_51 ;
V_49 += F_18 ( V_45 ) ;
V_44 = F_19 ( V_11 ) ;
if ( ! V_44 && ( V_18 . V_52 != V_53 || ! V_47 ) )
V_46 &= ~ ( 1 << ( V_7 - 1 ) ) ;
V_4 += F_7 ( V_1 , V_7 , V_8 ,
V_2 ) ;
V_3 = 0 ;
F_5 (chain, &child->val, list) {
V_4 += F_8 ( V_1 , V_45 , V_25 , V_7 ,
V_46 , V_3 ++ ,
V_27 ,
V_2 ) ;
}
if ( V_18 . V_52 == V_53 )
V_50 = V_45 -> V_54 ;
else
V_50 = V_27 ;
V_4 += F_14 ( V_1 , & V_45 -> V_41 , V_50 ,
V_7 + 1 ,
V_46 | ( 1 << V_7 ) ,
V_2 ) ;
V_11 = V_44 ;
if ( ++ V_48 == V_18 . V_55 )
break;
}
if ( V_18 . V_52 == V_53 &&
V_47 && V_47 != V_27 ) {
struct V_23 V_56 = {
. V_57 = V_47 ,
} ;
if ( ! V_36 )
return V_4 ;
if ( V_18 . V_58 == V_59 && V_45 && V_45 -> V_60 ) {
V_56 . V_61 = V_45 -> V_60 -> V_62 - V_49 ;
if ( V_56 . V_61 <= 0 )
return V_4 ;
}
V_46 &= ~ ( 1 << ( V_7 - 1 ) ) ;
V_4 += F_8 ( V_1 , & V_56 , & V_39 , V_7 ,
V_46 , 0 , V_27 ,
V_2 ) ;
}
return V_4 ;
}
static bool F_20 ( struct V_43 * V_11 , T_3 V_63 )
{
struct V_23 * V_64 ;
if ( F_19 ( V_11 ) )
return true ;
V_64 = F_16 ( V_11 , struct V_23 , V_43 ) ;
return F_17 ( V_64 ) != V_63 ;
}
static T_1 F_21 ( T_2 * V_1 , struct V_41 * V_42 ,
T_3 V_27 , T_3 V_63 ,
int V_2 )
{
struct V_23 * V_64 ;
struct V_24 * V_25 ;
T_5 V_48 = 0 ;
bool V_65 = false ;
struct V_43 * V_11 ;
int V_3 = 0 ;
int V_4 = 0 ;
char V_28 [ 1024 ] ;
V_11 = F_15 ( V_42 ) ;
if ( V_11 && ! F_20 ( V_11 , V_63 ) ) {
V_64 = F_16 ( V_11 , struct V_23 , V_43 ) ;
F_5 (chain, &cnode->val, list) {
if ( ! V_3 ++ && V_66 == NULL &&
V_67 && ! F_22 ( V_67 , L_17 ) )
continue;
if ( ! V_65 ) {
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_18 ) ;
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_19 ) ;
V_2 += 3 ;
V_65 = true ;
} else
V_4 += F_1 ( V_1 , V_2 ) ;
V_4 += fprintf ( V_1 , L_12 ,
F_10 ( V_25 , V_28 ,
sizeof( V_28 ) ,
false ) ) ;
if ( V_32 . V_33 )
V_4 += F_11 (
NULL , V_25 , V_1 , NULL , 0 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_48 == V_18 . V_55 )
break;
if ( V_32 . V_34 )
V_4 += F_2 ( V_25 -> V_35 . V_5 ,
V_25 -> V_6 ,
V_2 ,
0 , 0 ,
V_1 ) ;
}
V_42 = & V_64 -> V_41 ;
}
if ( V_18 . V_52 == V_53 )
V_27 = V_63 ;
V_4 += F_14 ( V_1 , V_42 , V_27 ,
1 , 1 , V_2 ) ;
if ( V_4 ) {
V_4 += fprintf ( V_1 , L_8 ) ;
}
return V_4 ;
}
static T_1 F_23 ( T_2 * V_1 , struct V_23 * V_11 ,
T_3 V_27 )
{
struct V_24 * V_25 ;
T_1 V_4 = 0 ;
char V_28 [ 1024 ] ;
if ( ! V_11 )
return 0 ;
V_4 += F_23 ( V_1 , V_11 -> V_60 , V_27 ) ;
F_5 (chain, &node->val, list) {
if ( V_25 -> V_6 >= V_68 )
continue;
V_4 += fprintf ( V_1 , L_20 , F_10 ( V_25 ,
V_28 , sizeof( V_28 ) , false ) ) ;
}
return V_4 ;
}
static T_1 F_24 ( T_2 * V_1 , struct V_41 * V_69 ,
T_3 V_27 )
{
T_1 V_4 = 0 ;
T_5 V_48 = 0 ;
struct V_23 * V_25 ;
struct V_43 * V_43 = F_15 ( V_69 ) ;
while ( V_43 ) {
V_25 = F_16 ( V_43 , struct V_23 , V_43 ) ;
V_4 += fprintf ( V_1 , L_10 ) ;
V_4 += F_9 ( V_25 , V_1 , V_27 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
V_4 += F_23 ( V_1 , V_25 , V_27 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_48 == V_18 . V_55 )
break;
V_43 = F_19 ( V_43 ) ;
}
return V_4 ;
}
static T_1 F_25 ( T_2 * V_1 , struct V_23 * V_11 )
{
const char * V_70 = V_32 . V_71 ? : L_21 ;
struct V_24 * V_25 ;
T_1 V_4 = 0 ;
char V_28 [ 1024 ] ;
bool V_72 ;
if ( ! V_11 )
return 0 ;
V_4 += F_25 ( V_1 , V_11 -> V_60 ) ;
V_72 = ( V_4 == 0 ) ;
F_5 (chain, &node->val, list) {
if ( V_25 -> V_6 >= V_68 )
continue;
V_4 += fprintf ( V_1 , L_13 , V_72 ? L_22 : V_70 ,
F_10 ( V_25 ,
V_28 , sizeof( V_28 ) , false ) ) ;
V_72 = false ;
}
return V_4 ;
}
static T_1 F_26 ( T_2 * V_1 , struct V_41 * V_69 ,
T_3 V_27 )
{
T_1 V_4 = 0 ;
T_5 V_48 = 0 ;
struct V_23 * V_25 ;
struct V_43 * V_43 = F_15 ( V_69 ) ;
while ( V_43 ) {
V_25 = F_16 ( V_43 , struct V_23 , V_43 ) ;
V_4 += F_9 ( V_25 , V_1 , V_27 ) ;
V_4 += fprintf ( V_1 , L_2 ) ;
V_4 += F_25 ( V_1 , V_25 ) ;
V_4 += fprintf ( V_1 , L_8 ) ;
if ( ++ V_48 == V_18 . V_55 )
break;
V_43 = F_19 ( V_43 ) ;
}
return V_4 ;
}
static T_1 F_27 ( struct V_73 * V_74 ,
T_3 V_27 , int V_2 ,
T_2 * V_1 )
{
T_3 V_63 = V_74 -> V_75 . V_26 ;
if ( V_32 . V_76 )
V_63 = V_74 -> V_77 -> V_26 ;
switch ( V_18 . V_52 ) {
case V_53 :
return F_21 ( V_1 , & V_74 -> V_78 , V_27 ,
V_63 , V_2 ) ;
break;
case V_79 :
return F_21 ( V_1 , & V_74 -> V_78 , V_27 ,
V_63 , V_2 ) ;
break;
case V_80 :
return F_24 ( V_1 , & V_74 -> V_78 , V_27 ) ;
break;
case V_81 :
return F_26 ( V_1 , & V_74 -> V_78 , V_27 ) ;
break;
case V_82 :
break;
default:
F_28 ( L_23 ) ;
}
return 0 ;
}
int F_29 ( struct V_73 * V_74 , struct V_83 * V_84 ,
struct V_85 * V_86 )
{
const char * V_70 = V_32 . V_71 ;
struct V_87 * V_88 ;
char * V_89 = V_84 -> V_30 ;
int V_4 ;
bool V_72 = true ;
if ( V_32 . V_90 && ! V_74 -> V_60 )
return 0 ;
F_30 (hpp_list, fmt) {
if ( F_31 ( V_88 , V_74 -> V_91 ) )
continue;
if ( ! V_70 || ! V_72 ) {
V_4 = F_32 ( V_84 -> V_30 , V_84 -> V_92 , L_12 , V_70 ? : L_24 ) ;
F_33 ( V_84 , V_4 ) ;
} else
V_72 = false ;
if ( F_34 () && V_88 -> V_93 )
V_4 = V_88 -> V_93 ( V_88 , V_84 , V_74 ) ;
else
V_4 = V_88 -> V_94 ( V_88 , V_84 , V_74 ) ;
V_4 = F_35 ( V_74 , V_84 , V_88 , V_4 ) ;
F_33 ( V_84 , V_4 ) ;
}
return V_84 -> V_30 - V_89 ;
}
static int F_36 ( struct V_73 * V_74 , struct V_83 * V_84 )
{
return F_29 ( V_74 , V_84 , V_74 -> V_91 -> V_86 ) ;
}
static int F_37 ( struct V_73 * V_74 ,
struct V_83 * V_84 ,
struct V_91 * V_91 ,
T_2 * V_1 )
{
const char * V_70 = V_32 . V_71 ;
struct V_87 * V_88 ;
struct V_95 * V_96 ;
char * V_30 = V_84 -> V_30 ;
T_1 V_92 = V_84 -> V_92 ;
int V_4 , V_65 = 0 ;
bool V_72 = true ;
if ( V_32 . V_90 && ! V_74 -> V_60 )
return 0 ;
V_4 = F_32 ( V_84 -> V_30 , V_84 -> V_92 , L_25 , V_74 -> V_7 * V_97 , L_22 ) ;
F_33 ( V_84 , V_4 ) ;
V_96 = F_38 ( & V_91 -> V_98 ,
struct V_95 , V_99 ) ;
F_30 (&fmt_node->hpp, fmt) {
if ( ! V_70 || ! V_72 ) {
V_4 = F_32 ( V_84 -> V_30 , V_84 -> V_92 , L_12 , V_70 ? : L_24 ) ;
F_33 ( V_84 , V_4 ) ;
} else
V_72 = false ;
if ( F_34 () && V_88 -> V_93 )
V_4 = V_88 -> V_93 ( V_88 , V_84 , V_74 ) ;
else
V_4 = V_88 -> V_94 ( V_88 , V_84 , V_74 ) ;
V_4 = F_35 ( V_74 , V_84 , V_88 , V_4 ) ;
F_33 ( V_84 , V_4 ) ;
}
if ( ! V_70 )
V_4 = F_32 ( V_84 -> V_30 , V_84 -> V_92 , L_25 ,
( V_91 -> V_100 - 2 ) * V_97 , L_22 ) ;
F_33 ( V_84 , V_4 ) ;
V_65 += fprintf ( V_1 , L_12 , V_30 ) ;
F_30 (he->hpp_list, fmt) {
V_84 -> V_30 = V_30 ;
V_84 -> V_92 = V_92 ;
if ( F_34 () && V_88 -> V_93 )
V_88 -> V_93 ( V_88 , V_84 , V_74 ) ;
else
V_88 -> V_94 ( V_88 , V_84 , V_74 ) ;
V_65 += fprintf ( V_1 , L_13 , V_70 ? : L_24 , F_39 ( V_30 ) ) ;
}
V_65 += putc ( '\n' , V_1 ) ;
if ( V_32 . V_101 && V_74 -> V_102 ) {
T_3 V_103 = F_40 ( V_91 ) ;
V_65 += F_27 ( V_74 , V_103 , 0 , V_1 ) ;
goto V_104;
}
V_104:
return V_65 ;
}
static int F_41 ( struct V_73 * V_74 , T_1 V_92 ,
char * V_28 , T_1 V_105 , T_2 * V_1 ,
bool V_101 )
{
int V_4 ;
int V_106 = 0 ;
int V_107 = 0 ;
struct V_83 V_84 = {
. V_30 = V_28 ,
. V_92 = V_92 ,
} ;
struct V_91 * V_91 = V_74 -> V_91 ;
T_3 V_108 = V_91 -> V_109 . V_108 ;
if ( V_92 == 0 || V_92 > V_105 )
V_92 = V_84 . V_92 = V_105 ;
if ( V_32 . V_110 )
return F_37 ( V_74 , & V_84 , V_91 , V_1 ) ;
F_36 ( V_74 , & V_84 ) ;
V_4 = fprintf ( V_1 , L_26 , V_28 ) ;
if ( V_101 )
V_106 = F_27 ( V_74 , V_108 ,
0 , V_1 ) ;
if ( V_106 == 0 && V_32 . V_34 ) {
V_107 = F_2 ( V_74 -> V_35 . V_5 , V_74 -> V_6 , 0 , 0 , 0 , V_1 ) ;
V_4 += V_107 ;
if ( V_107 > 0 )
V_4 += fprintf ( V_1 , L_8 ) ;
} else
V_4 += V_106 ;
return V_4 ;
}
static int F_42 ( const char * V_70 , int V_111 ,
const char * line , T_2 * V_1 )
{
if ( V_70 != NULL || V_111 < 2 )
return 0 ;
return fprintf ( V_1 , L_27 , ( V_111 - 2 ) * V_97 , line ) ;
}
static int F_43 ( struct V_91 * V_91 ,
struct V_83 * V_84 , T_2 * V_1 )
{
bool V_112 , V_113 ;
int V_111 ;
int V_7 ;
unsigned V_114 = 0 ;
unsigned V_115 = 0 ;
struct V_87 * V_88 ;
struct V_95 * V_96 ;
const char * V_70 = V_32 . V_71 ;
V_111 = V_91 -> V_100 ;
F_42 ( V_70 , V_111 , V_116 , V_1 ) ;
V_96 = F_38 ( & V_91 -> V_98 ,
struct V_95 , V_99 ) ;
F_30 (&fmt_node->hpp, fmt) {
V_88 -> V_117 ( V_88 , V_84 , V_91 , 0 , NULL ) ;
fprintf ( V_1 , L_13 , V_84 -> V_30 , V_70 ? : L_24 ) ;
}
V_112 = true ;
F_44 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_112 )
V_115 += fprintf ( V_1 , L_28 ) ;
V_112 = false ;
V_113 = true ;
F_30 (&fmt_node->hpp, fmt) {
if ( F_31 ( V_88 , V_91 ) )
continue;
if ( ! V_113 )
V_115 += fprintf ( V_1 , L_29 ) ;
V_113 = false ;
V_88 -> V_117 ( V_88 , V_84 , V_91 , 0 , NULL ) ;
V_115 += fprintf ( V_1 , L_12 , F_45 ( V_84 -> V_30 ) ) ;
}
}
fprintf ( V_1 , L_30 ) ;
F_42 ( V_70 , V_111 , V_118 , V_1 ) ;
V_96 = F_38 ( & V_91 -> V_98 ,
struct V_95 , V_99 ) ;
V_113 = true ;
F_30 (&fmt_node->hpp, fmt) {
if ( ! V_113 )
fprintf ( V_1 , L_12 , V_70 ? : L_31 ) ;
V_113 = false ;
V_114 = V_88 -> V_114 ( V_88 , V_84 , V_91 ) ;
fprintf ( V_1 , L_32 , V_114 , V_118 ) ;
}
V_7 = 0 ;
F_44 (fmt_node, &hists->hpp_formats, list) {
V_113 = true ;
V_114 = V_7 * V_97 ;
F_30 (&fmt_node->hpp, fmt) {
if ( F_31 ( V_88 , V_91 ) )
continue;
if ( ! V_113 )
V_114 ++ ;
V_113 = false ;
V_114 += V_88 -> V_114 ( V_88 , V_84 , V_91 ) ;
}
if ( V_114 > V_115 )
V_115 = V_114 ;
V_7 ++ ;
}
fprintf ( V_1 , L_33 , V_70 ? : L_24 , V_115 , V_118 ) ;
fprintf ( V_1 , L_34 ) ;
return 2 ;
}
static void F_46 ( struct V_91 * V_91 , struct V_83 * V_84 ,
int line , T_2 * V_1 )
{
struct V_87 * V_88 ;
const char * V_70 = V_32 . V_71 ;
bool V_72 = true ;
int V_119 = 0 ;
F_47 (hists, fmt) {
if ( F_31 ( V_88 , V_91 ) )
continue;
if ( ! V_72 && ! V_119 )
fprintf ( V_1 , L_12 , V_70 ? : L_24 ) ;
else
V_72 = false ;
V_88 -> V_117 ( V_88 , V_84 , V_91 , line , & V_119 ) ;
if ( ! V_119 )
fprintf ( V_1 , L_12 , V_84 -> V_30 ) ;
}
}
static int
F_48 ( struct V_91 * V_91 ,
struct V_83 * V_84 ,
T_2 * V_1 )
{
struct V_85 * V_86 = V_91 -> V_86 ;
struct V_87 * V_88 ;
unsigned int V_114 ;
const char * V_70 = V_32 . V_71 ;
bool V_72 = true ;
int line ;
for ( line = 0 ; line < V_86 -> V_120 ; line ++ ) {
if ( line )
fprintf ( V_1 , L_35 ) ;
F_46 ( V_91 , V_84 , line , V_1 ) ;
fprintf ( V_1 , L_8 ) ;
}
if ( V_70 )
return V_86 -> V_120 ;
V_72 = true ;
fprintf ( V_1 , L_35 ) ;
F_47 (hists, fmt) {
unsigned int V_3 ;
if ( F_31 ( V_88 , V_91 ) )
continue;
if ( ! V_72 )
fprintf ( V_1 , L_12 , V_70 ? : L_24 ) ;
else
V_72 = false ;
V_114 = V_88 -> V_114 ( V_88 , V_84 , V_91 ) ;
for ( V_3 = 0 ; V_3 < V_114 ; V_3 ++ )
fprintf ( V_1 , L_36 ) ;
}
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_37 ) ;
return V_86 -> V_120 + 2 ;
}
int F_49 ( struct V_91 * V_91 , T_2 * V_1 )
{
char V_28 [ 1024 ] ;
struct V_83 V_121 = {
. V_30 = V_28 ,
. V_92 = sizeof( V_28 ) ,
} ;
fprintf ( V_1 , L_35 ) ;
if ( V_32 . V_110 )
return F_43 ( V_91 , & V_121 , V_1 ) ;
else
return F_48 ( V_91 , & V_121 , V_1 ) ;
}
T_1 F_50 ( struct V_91 * V_91 , bool V_122 , int V_123 ,
int V_124 , float V_125 , T_2 * V_1 ,
bool V_101 )
{
struct V_43 * V_126 ;
T_1 V_4 = 0 ;
const char * V_70 = V_32 . V_71 ;
int V_127 = 0 ;
T_1 V_128 ;
char * line = NULL ;
unsigned V_111 ;
F_13 () ;
F_51 ( V_91 ) ;
if ( V_32 . V_129 )
F_52 ( V_32 . V_129 ) ;
if ( V_122 )
V_127 += F_49 ( V_91 , V_1 ) ;
if ( V_123 && V_127 >= V_123 )
goto V_104;
V_128 = F_53 ( V_91 ) + 3 + 1 ;
V_128 += F_54 () ;
line = malloc ( V_128 ) ;
if ( line == NULL ) {
V_4 = - 1 ;
goto V_104;
}
V_111 = F_55 ( V_91 ) + 4 ;
for ( V_126 = F_15 ( & V_91 -> V_130 ) ; V_126 ; V_126 = F_56 ( V_126 , V_131 ) ) {
struct V_73 * V_132 = F_16 ( V_126 , struct V_73 , V_43 ) ;
float V_133 ;
if ( V_132 -> V_134 )
continue;
V_133 = F_57 ( V_132 ) ;
if ( V_133 < V_125 )
continue;
V_4 += F_41 ( V_132 , V_124 , line , V_128 , V_1 , V_101 ) ;
if ( V_123 && ++ V_127 >= V_123 )
break;
if ( ! V_132 -> V_102 && ! F_58 ( V_132 , V_125 ) ) {
int V_7 = V_91 -> V_100 + V_132 -> V_7 + 1 ;
F_42 ( V_70 , V_7 , V_116 , V_1 ) ;
fprintf ( V_1 , L_38 , V_111 , L_22 , V_125 ) ;
if ( V_123 && ++ V_127 >= V_123 )
break;
}
if ( V_132 -> V_35 . V_5 == NULL && V_135 > 1 ) {
F_59 ( V_132 -> V_136 -> V_137 ,
V_138 , V_1 ) ;
fprintf ( V_1 , L_39 , V_139 ) ;
}
}
free ( line ) ;
V_104:
F_60 ( & V_36 ) ;
return V_4 ;
}
T_1 F_61 ( struct V_140 * V_109 , T_2 * V_1 )
{
int V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_141 ; ++ V_3 ) {
const char * V_38 ;
if ( V_109 -> V_142 [ V_3 ] == 0 )
continue;
V_38 = F_62 ( V_3 ) ;
if ( ! strcmp ( V_38 , L_40 ) )
continue;
V_4 += fprintf ( V_1 , L_41 , V_38 ,
V_109 -> V_142 [ V_3 ] ) ;
}
return V_4 ;
}
