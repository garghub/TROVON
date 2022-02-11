static int F_1 ( struct V_1 * V_2 , const char * V_3 , ... )
{
int V_4 = 0 ;
int V_5 ;
T_1 args ;
double V_6 ;
const char * V_7 ;
char * V_8 = V_2 -> V_8 ;
T_2 V_9 = V_2 -> V_9 ;
va_start ( args , V_3 ) ;
V_5 = va_arg ( args , int ) ;
V_6 = va_arg ( args , double ) ;
va_end ( args ) ;
V_7 = F_2 ( V_6 ) ;
if ( V_7 )
V_4 += F_3 ( V_8 , V_9 , V_7 ) ;
V_4 += F_3 ( V_8 + V_4 , V_9 - V_4 , V_3 , V_5 , V_6 ) ;
if ( V_7 )
V_4 += F_3 ( V_8 + V_4 , V_9 - V_4 , L_1 ) ;
return V_4 ;
}
void F_4 ( void )
{
V_10 [ V_11 ] . V_12 =
V_13 ;
V_10 [ V_14 ] . V_12 =
V_15 ;
V_10 [ V_16 ] . V_12 =
V_17 ;
V_10 [ V_18 ] . V_12 =
V_19 ;
V_10 [ V_20 ] . V_12 =
V_21 ;
V_10 [ V_22 ] . V_12 =
V_23 ;
}
static void F_5 ( struct V_24 * V_25 , T_3 * V_26 ,
T_4 * V_27 , int V_28 , T_5 V_29 )
{
struct V_30 * V_31 ;
bool V_32 = ( F_6 ( V_25 ) == F_7 ( V_25 ) ) ;
for ( V_31 = F_6 ( V_25 ) ; V_31 ; V_31 = F_8 ( V_31 ) ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 V_37 , V_38 ;
bool V_39 ;
V_34 = F_9 ( V_31 , struct V_33 , V_30 ) ;
V_38 = * V_27 ;
V_39 = ! V_32 ;
F_10 ( V_34 ) ;
F_11 (chain, &node->parent_val, list) {
char V_8 [ 128 ] ;
F_12 ( V_26 , & V_37 , & V_38 ) ;
F_13 ( V_34 , V_8 , sizeof( V_8 ) , V_29 ) ;
F_14 ( V_26 , & V_37 , 0 , V_8 , - 1 ) ;
F_15 ( V_36 , V_8 , sizeof( V_8 ) , false ) ;
F_14 ( V_26 , & V_37 , V_28 , V_8 , - 1 ) ;
if ( V_39 ) {
V_38 = V_37 ;
V_39 = false ;
}
}
F_11 (chain, &node->val, list) {
char V_8 [ 128 ] ;
F_12 ( V_26 , & V_37 , & V_38 ) ;
F_13 ( V_34 , V_8 , sizeof( V_8 ) , V_29 ) ;
F_14 ( V_26 , & V_37 , 0 , V_8 , - 1 ) ;
F_15 ( V_36 , V_8 , sizeof( V_8 ) , false ) ;
F_14 ( V_26 , & V_37 , V_28 , V_8 , - 1 ) ;
if ( V_39 ) {
V_38 = V_37 ;
V_39 = false ;
}
}
}
}
static void F_16 ( struct V_24 * V_25 , T_3 * V_26 ,
T_4 * V_27 , int V_28 , T_5 V_29 )
{
struct V_30 * V_31 ;
for ( V_31 = F_6 ( V_25 ) ; V_31 ; V_31 = F_8 ( V_31 ) ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 V_37 ;
char V_8 [ 64 ] ;
char * V_40 , * V_41 = NULL ;
bool V_42 = true ;
V_34 = F_9 ( V_31 , struct V_33 , V_30 ) ;
F_10 ( V_34 ) ;
F_11 (chain, &node->parent_val, list) {
char V_43 [ 1024 ] ;
F_15 ( V_36 , V_43 , sizeof( V_43 ) , false ) ;
if ( F_17 ( & V_40 , L_2 ,
V_42 ? L_3 : V_41 ,
V_42 ? L_3 : V_44 . V_45 ? : L_4 ,
V_43 ) < 0 )
return;
V_42 = false ;
free ( V_41 ) ;
V_41 = V_40 ;
}
F_11 (chain, &node->val, list) {
char V_43 [ 1024 ] ;
F_15 ( V_36 , V_43 , sizeof( V_43 ) , false ) ;
if ( F_17 ( & V_40 , L_2 ,
V_42 ? L_3 : V_41 ,
V_42 ? L_3 : V_44 . V_45 ? : L_4 ,
V_43 ) < 0 )
return;
V_42 = false ;
free ( V_41 ) ;
V_41 = V_40 ;
}
F_12 ( V_26 , & V_37 , V_27 ) ;
F_13 ( V_34 , V_8 , sizeof( V_8 ) , V_29 ) ;
F_14 ( V_26 , & V_37 , 0 , V_8 , - 1 ) ;
F_14 ( V_26 , & V_37 , V_28 , V_40 , - 1 ) ;
free ( V_41 ) ;
}
}
static void F_18 ( struct V_24 * V_25 , T_3 * V_26 ,
T_4 * V_27 , int V_28 , T_5 V_29 )
{
struct V_30 * V_31 ;
bool V_32 = ( F_6 ( V_25 ) == F_7 ( V_25 ) ) ;
for ( V_31 = F_6 ( V_25 ) ; V_31 ; V_31 = F_8 ( V_31 ) ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 V_37 , V_38 ;
bool V_39 ;
T_5 V_46 ;
V_34 = F_9 ( V_31 , struct V_33 , V_30 ) ;
V_38 = * V_27 ;
V_39 = ! V_32 && ( V_34 -> V_47 > 1 ) ;
F_11 (chain, &node->val, list) {
char V_8 [ 128 ] ;
F_12 ( V_26 , & V_37 , & V_38 ) ;
F_13 ( V_34 , V_8 , sizeof( V_8 ) , V_29 ) ;
F_14 ( V_26 , & V_37 , 0 , V_8 , - 1 ) ;
F_15 ( V_36 , V_8 , sizeof( V_8 ) , false ) ;
F_14 ( V_26 , & V_37 , V_28 , V_8 , - 1 ) ;
if ( V_39 ) {
V_38 = V_37 ;
V_39 = false ;
}
}
if ( V_48 . V_49 == V_50 )
V_46 = V_34 -> V_51 ;
else
V_46 = V_29 ;
F_18 ( & V_34 -> V_24 , V_26 , & V_37 , V_28 ,
V_46 ) ;
}
}
static void F_19 ( struct V_24 * V_25 , T_3 * V_26 ,
T_4 * V_27 , int V_28 , T_5 V_29 )
{
if ( V_48 . V_49 == V_52 )
F_5 ( V_25 , V_26 , V_27 , V_28 , V_29 ) ;
else if ( V_48 . V_49 == V_53 )
F_16 ( V_25 , V_26 , V_27 , V_28 , V_29 ) ;
else
F_18 ( V_25 , V_26 , V_27 , V_28 , V_29 ) ;
}
static void F_20 ( T_6 * V_54 , T_7 * V_55 ,
T_8 * V_28 V_56 ,
T_9 T_10 V_56 )
{
bool V_57 = F_21 ( V_54 , V_55 ) ;
if ( V_57 )
F_22 ( V_54 , V_55 ) ;
else
F_23 ( V_54 , V_55 , FALSE ) ;
}
static void F_24 ( T_11 * V_58 , struct V_59 * V_59 ,
float V_60 )
{
struct V_61 * V_3 ;
T_12 V_62 [ V_63 ] ;
T_13 * V_64 ;
T_3 * V_26 ;
struct V_30 * V_31 ;
T_11 * V_54 ;
int V_65 ;
int V_66 = - 1 ;
int V_67 ;
char V_68 [ 512 ] ;
struct V_1 V_2 = {
. V_8 = V_68 ,
. V_9 = sizeof( V_68 ) ,
} ;
V_67 = 0 ;
F_25 (hists, fmt)
V_62 [ V_67 ++ ] = V_69 ;
V_26 = F_26 ( V_67 , V_62 ) ;
V_54 = F_27 () ;
V_64 = F_28 () ;
V_65 = 0 ;
F_25 (hists, fmt) {
if ( F_29 ( V_3 , V_59 ) )
continue;
if ( F_30 ( V_3 ) )
V_66 = V_65 ;
F_31 ( F_32 ( V_54 ) ,
- 1 , V_3 -> V_43 ,
V_64 , L_5 ,
V_65 ++ , NULL ) ;
}
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
T_8 * V_70 ;
V_70 = F_33 ( F_32 ( V_54 ) , V_65 ) ;
F_34 ( V_70 , TRUE ) ;
if ( V_65 == V_66 ) {
F_35 ( F_32 ( V_54 ) ,
V_70 ) ;
}
}
F_36 ( F_32 ( V_54 ) , F_37 ( V_26 ) ) ;
F_38 ( F_37 ( V_26 ) ) ;
for ( V_31 = F_6 ( & V_59 -> V_71 ) ; V_31 ; V_31 = F_8 ( V_31 ) ) {
struct V_72 * V_73 = F_9 ( V_31 , struct V_72 , V_30 ) ;
T_4 V_37 ;
T_5 V_29 = F_39 ( V_73 -> V_59 ) ;
float V_6 ;
if ( V_73 -> V_74 )
continue;
V_6 = F_40 ( V_73 ) ;
if ( V_6 < V_60 )
continue;
F_12 ( V_26 , & V_37 , NULL ) ;
V_65 = 0 ;
F_25 (hists, fmt) {
if ( F_29 ( V_3 , V_73 -> V_59 ) )
continue;
if ( V_3 -> V_12 )
V_3 -> V_12 ( V_3 , & V_2 , V_73 ) ;
else
V_3 -> V_75 ( V_3 , & V_2 , V_73 ) ;
F_14 ( V_26 , & V_37 , V_65 ++ , V_68 , - 1 ) ;
}
if ( V_44 . V_76 && F_41 ( V_59 , V_77 ) ) {
if ( V_48 . V_49 == V_50 )
V_29 = V_44 . V_78 ?
V_73 -> V_79 -> V_80 : V_73 -> V_81 . V_80 ;
F_19 ( & V_73 -> V_82 , V_26 , & V_37 ,
V_66 , V_29 ) ;
}
}
F_42 ( F_32 ( V_54 ) , TRUE ) ;
F_43 ( V_54 , L_6 ,
F_44 ( F_20 ) , NULL ) ;
F_45 ( F_46 ( V_58 ) , V_54 ) ;
}
static void F_47 ( struct V_59 * V_59 ,
struct V_24 * V_25 ,
T_3 * V_26 ,
T_4 * V_27 ,
struct V_1 * V_2 ,
float V_60 )
{
int V_65 = 0 ;
struct V_30 * V_34 ;
struct V_72 * V_83 ;
struct V_61 * V_3 ;
struct V_84 * V_85 ;
T_5 V_29 = F_39 ( V_59 ) ;
int V_9 ;
for ( V_34 = F_6 ( V_25 ) ; V_34 ; V_34 = F_8 ( V_34 ) ) {
T_4 V_37 ;
float V_6 ;
char * V_86 ;
V_83 = F_9 ( V_34 , struct V_72 , V_30 ) ;
if ( V_83 -> V_74 )
continue;
V_6 = F_40 ( V_83 ) ;
if ( V_6 < V_60 )
continue;
F_12 ( V_26 , & V_37 , V_27 ) ;
V_65 = 0 ;
V_85 = F_48 ( & V_59 -> V_87 ,
struct V_84 , V_88 ) ;
F_49 (&fmt_node->hpp, fmt) {
if ( V_3 -> V_12 )
V_3 -> V_12 ( V_3 , V_2 , V_83 ) ;
else
V_3 -> V_75 ( V_3 , V_2 , V_83 ) ;
F_14 ( V_26 , & V_37 , V_65 ++ , V_2 -> V_8 , - 1 ) ;
}
V_86 = V_2 -> V_8 ;
V_9 = V_2 -> V_9 ;
F_49 (he->hpp_list, fmt) {
int V_4 ;
if ( V_3 -> V_12 )
V_4 = V_3 -> V_12 ( V_3 , V_2 , V_83 ) ;
else
V_4 = V_3 -> V_75 ( V_3 , V_2 , V_83 ) ;
snprintf ( V_2 -> V_8 + V_4 , V_2 -> V_9 - V_4 , L_7 ) ;
F_50 ( V_2 , V_4 + 2 ) ;
}
F_14 ( V_26 , & V_37 , V_65 , F_51 ( F_52 ( V_86 ) ) , - 1 ) ;
if ( ! V_83 -> V_89 ) {
V_2 -> V_8 = V_86 ;
V_2 -> V_9 = V_9 ;
F_47 ( V_59 , & V_83 -> V_90 ,
V_26 , & V_37 , V_2 ,
V_60 ) ;
if ( ! F_53 ( V_83 , V_60 ) ) {
char V_8 [ 32 ] ;
T_4 V_91 ;
snprintf ( V_8 , sizeof( V_8 ) , L_8 ,
V_60 ) ;
F_12 ( V_26 , & V_91 , & V_37 ) ;
F_14 ( V_26 , & V_91 , V_65 , V_8 , - 1 ) ;
}
}
if ( V_44 . V_76 && V_83 -> V_89 ) {
if ( V_48 . V_49 == V_50 )
V_29 = V_44 . V_78 ?
V_83 -> V_79 -> V_80 : V_83 -> V_81 . V_80 ;
F_19 ( & V_83 -> V_82 , V_26 , & V_37 ,
V_65 , V_29 ) ;
}
}
}
static void F_54 ( T_11 * V_58 , struct V_59 * V_59 ,
float V_60 )
{
struct V_61 * V_3 ;
struct V_84 * V_85 ;
T_12 V_62 [ V_63 ] ;
T_13 * V_64 ;
T_3 * V_26 ;
T_11 * V_54 ;
int V_65 ;
int V_67 = 0 ;
char V_68 [ 512 ] ;
char V_8 [ 512 ] ;
bool V_92 , V_93 ;
struct V_1 V_2 = {
. V_8 = V_68 ,
. V_9 = sizeof( V_68 ) ,
} ;
F_25 (hists, fmt) {
if ( F_30 ( V_3 ) ||
F_55 ( V_3 ) )
break;
V_62 [ V_67 ++ ] = V_69 ;
}
V_62 [ V_67 ++ ] = V_69 ;
V_26 = F_26 ( V_67 , V_62 ) ;
V_54 = F_27 () ;
V_64 = F_28 () ;
V_65 = 0 ;
V_85 = F_48 ( & V_59 -> V_87 ,
struct V_84 , V_88 ) ;
F_49 (&fmt_node->hpp, fmt) {
F_31 ( F_32 ( V_54 ) ,
- 1 , V_3 -> V_43 ,
V_64 , L_5 ,
V_65 ++ , NULL ) ;
}
V_8 [ 0 ] = '\0' ;
V_92 = true ;
F_56 (fmt_node, &hists->hpp_formats, list) {
if ( ! V_92 )
strcat ( V_8 , L_9 ) ;
V_92 = false ;
V_93 = true ;
F_49 (&fmt_node->hpp ,fmt) {
if ( F_29 ( V_3 , V_59 ) )
continue;
if ( ! V_93 )
strcat ( V_8 , L_10 ) ;
V_93 = false ;
V_3 -> V_94 ( V_3 , & V_2 , V_59 , 0 , NULL ) ;
strcat ( V_8 , F_51 ( F_52 ( V_2 . V_8 ) ) ) ;
}
}
F_31 ( F_32 ( V_54 ) ,
- 1 , V_8 ,
V_64 , L_5 ,
V_65 ++ , NULL ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
T_8 * V_70 ;
V_70 = F_33 ( F_32 ( V_54 ) , V_65 ) ;
F_34 ( V_70 , TRUE ) ;
if ( V_65 == 0 ) {
F_35 ( F_32 ( V_54 ) ,
V_70 ) ;
}
}
F_36 ( F_32 ( V_54 ) , F_37 ( V_26 ) ) ;
F_38 ( F_37 ( V_26 ) ) ;
F_47 ( V_59 , & V_59 -> V_71 , V_26 ,
NULL , & V_2 , V_60 ) ;
F_42 ( F_32 ( V_54 ) , TRUE ) ;
F_43 ( V_54 , L_6 ,
F_44 ( F_20 ) , NULL ) ;
F_45 ( F_46 ( V_58 ) , V_54 ) ;
}
int F_57 ( struct V_95 * V_96 ,
const char * V_97 ,
struct V_98 * T_14 V_56 ,
float V_60 )
{
struct V_99 * V_100 ;
T_11 * V_101 ;
T_11 * V_102 ;
T_11 * V_103 ;
T_11 * V_104 ;
T_11 * V_58 ;
signal ( V_105 , V_106 ) ;
signal ( V_107 , V_106 ) ;
signal ( V_108 , V_106 ) ;
signal ( V_109 , V_106 ) ;
signal ( V_110 , V_106 ) ;
V_58 = F_58 ( V_111 ) ;
F_59 ( F_60 ( V_58 ) , L_11 ) ;
F_43 ( V_58 , L_12 , V_112 , NULL ) ;
V_113 = F_61 ( V_58 ) ;
if ( ! V_113 )
return - 1 ;
V_101 = F_62 ( FALSE , 0 ) ;
V_102 = F_63 () ;
F_64 ( F_65 ( V_101 ) , V_102 , TRUE , TRUE , 0 ) ;
V_103 = F_66 () ;
if ( V_103 )
F_64 ( F_65 ( V_101 ) , V_103 , FALSE , FALSE , 0 ) ;
V_104 = F_67 () ;
F_64 ( F_65 ( V_101 ) , V_104 , FALSE , FALSE , 0 ) ;
F_45 ( F_46 ( V_58 ) , V_101 ) ;
F_68 (evlist, pos) {
struct V_59 * V_59 = F_69 ( V_100 ) ;
const char * V_114 = F_70 ( V_100 ) ;
T_11 * V_115 ;
T_11 * V_116 ;
char V_8 [ 512 ] ;
T_2 V_9 = sizeof( V_8 ) ;
if ( V_44 . V_117 ) {
if ( ! F_71 ( V_100 ) )
continue;
if ( V_100 -> V_118 > 1 ) {
F_72 ( V_100 , V_8 , V_9 ) ;
V_114 = V_8 ;
}
}
V_115 = F_73 ( NULL , NULL ) ;
F_74 ( F_75 ( V_115 ) ,
V_119 ,
V_119 ) ;
if ( V_44 . V_120 )
F_54 ( V_115 , V_59 , V_60 ) ;
else
F_24 ( V_115 , V_59 , V_60 ) ;
V_116 = F_76 ( V_114 ) ;
F_77 ( F_78 ( V_102 ) , V_115 , V_116 ) ;
}
F_79 ( V_58 ) ;
F_80 ( V_58 ) ;
F_81 ( F_60 ( V_58 ) , V_121 ) ;
F_82 ( V_97 ) ;
F_83 () ;
F_84 ( & V_113 ) ;
return 0 ;
}
