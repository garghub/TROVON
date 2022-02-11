static void F_1 ( const char * V_1 ,
T_1 * V_2 ,
T_2 * V_3 ,
T_3 * V_4 )
{
int V_5 ;
if ( V_2 )
* V_2 = NULL ;
if ( V_3 )
* V_3 = NULL ;
if ( V_4 )
* V_4 = NULL ;
if ( ! V_1 )
return;
for ( V_5 = 0 ; V_6 [ V_5 ] . V_7 != NULL ; V_5 ++ ) {
if ( strcmp ( V_6 [ V_5 ] . V_7 , V_1 ) == 0 ) {
if ( V_2 )
* V_2 = V_6 [ V_5 ] . V_8 ;
if ( V_3 )
* V_3 = V_6 [ V_5 ] . V_9 ;
if ( V_4 )
* V_4 = V_6 [ V_5 ] . V_10 ;
break;
}
}
}
static void F_2 ( struct V_11 * V_12 ,
unsigned int V_13 ,
void * V_14 )
{
F_3 ( ( ( unsigned long ) & V_12 -> V_15 ) & ( 16UL - 1 ) ) ;
memset ( V_12 , 0 , V_13 ) ;
F_4 ( & V_12 -> V_16 ) ;
V_12 -> V_17 = V_14 ;
F_5 ( & V_12 -> V_18 , 1 ) ;
V_12 -> V_13 = V_13 ;
}
static struct V_11 * T_4 F_6 ( unsigned int V_19 )
{
unsigned int V_13 , V_20 ;
struct V_11 * V_12 ;
unsigned long V_21 ;
V_13 = ( sizeof( struct V_11 ) -
sizeof( struct V_22 ) +
V_19 ) ;
V_20 = F_7 ( V_13 ) ;
V_21 = F_8 ( V_20 , V_23 ) ;
V_12 = NULL ;
if ( V_21 ) {
V_12 = F_9 ( V_21 ) ;
F_2 ( V_12 , V_13 , V_12 ) ;
}
return V_12 ;
}
static void T_4 F_10 ( struct V_11 * V_12 )
{
unsigned int V_20 ;
unsigned long V_24 ;
F_3 ( F_11 ( & V_12 -> V_18 ) != 0 ) ;
F_3 ( ! F_12 ( & V_12 -> V_16 ) ) ;
V_20 = F_7 ( V_12 -> V_13 ) ;
V_24 = F_13 ( V_12 ) ;
F_14 ( V_24 , V_20 ) ;
}
static struct V_11 * F_15 ( unsigned int V_19 )
{
unsigned int V_13 ;
struct V_11 * V_12 ;
unsigned long V_25 ;
void * V_14 ;
V_13 = ( sizeof( struct V_11 ) -
sizeof( struct V_22 ) +
V_19 ) ;
V_14 = F_16 ( V_13 + 15 , V_26 | V_27 ) ;
if ( ! V_14 )
return NULL ;
V_25 = ( unsigned long ) V_14 ;
V_25 = ( V_25 + 15UL ) & ~ 15UL ;
V_12 = (struct V_11 * ) V_25 ;
F_2 ( V_12 , V_13 , V_14 ) ;
return V_12 ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_3 ( F_11 ( & V_12 -> V_18 ) != 0 ) ;
F_3 ( ! F_12 ( & V_12 -> V_16 ) ) ;
F_18 ( V_12 -> V_17 ) ;
}
static struct V_11 * F_19 ( unsigned int V_19 ,
struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_30 ( V_19 ) ;
if ( V_12 )
V_12 -> V_29 = V_29 ;
return V_12 ;
}
static void F_20 ( struct V_11 * V_12 )
{
V_12 -> V_29 -> free ( V_12 ) ;
}
struct V_11 * F_21 ( void )
{
struct V_11 * V_12 ;
unsigned long V_31 ;
F_22 ( & V_32 , V_31 ) ;
V_12 = V_33 ;
if ( V_12 )
F_23 ( & V_12 -> V_18 ) ;
F_24 ( & V_32 , V_31 ) ;
return V_12 ;
}
void F_25 ( struct V_11 * V_12 )
{
unsigned long V_31 ;
F_22 ( & V_32 , V_31 ) ;
if ( F_26 ( & V_12 -> V_18 ) ) {
F_27 ( & V_12 -> V_16 ) ;
V_12 -> V_29 -> free ( V_12 ) ;
}
F_24 ( & V_32 , V_31 ) ;
}
void F_28 ( struct V_34 * V_35 )
{
bool V_36 = false ;
T_5 V_37 ;
int V_5 ;
F_29 ( & V_38 ) ;
for ( V_5 = 0 ; V_6 [ V_5 ] . V_7 != NULL ; V_5 ++ ) {
if ( strcmp ( V_6 [ V_5 ] . V_7 , V_35 -> V_1 ) == 0 ) {
V_36 = true ;
break;
}
}
if ( ! V_36 ) {
F_30 ( L_1 , V_35 -> V_1 ) ;
F_31 ( & V_38 ) ;
return;
}
V_35 -> V_39 = V_40 ;
V_40 = V_35 ;
F_32 (cur_mdesc, node, client->node_name)
V_35 -> V_41 ( V_33 , V_37 , V_35 -> V_1 ) ;
F_31 ( & V_38 ) ;
}
static const T_5 * F_33 ( struct V_11 * V_12 , T_5 V_37 )
{
const T_5 * V_42 ;
T_5 V_43 ;
V_42 = NULL ;
F_34 (a, hp, node, MDESC_ARC_TYPE_BACK) {
T_5 V_44 ;
V_44 = F_35 ( V_12 , V_43 ) ;
V_42 = F_36 ( V_12 , V_44 ,
L_2 , NULL ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_37 ( struct V_11 * V_45 , T_5 V_37 ,
union V_46 * V_47 )
{
const T_5 * V_48 ;
const char * V_7 ;
const T_5 * V_49 ;
V_49 = F_36 ( V_45 , V_37 , L_3 , NULL ) ;
V_7 = F_36 ( V_45 , V_37 , L_4 , NULL ) ;
V_48 = F_33 ( V_45 , V_37 ) ;
if ( ! V_49 || ! V_7 || ! V_48 )
return - 1 ;
V_47 -> V_50 . V_42 = * V_49 ;
V_47 -> V_50 . V_7 = F_38 ( V_7 , V_26 ) ;
V_47 -> V_50 . V_51 = * V_48 ;
return 0 ;
}
static void F_39 ( union V_46 * V_47 )
{
if ( V_47 && V_47 -> V_50 . V_7 ) {
F_40 ( V_47 -> V_50 . V_7 ) ;
V_47 -> V_50 . V_7 = NULL ;
}
}
static bool F_41 ( union V_46 * V_52 ,
union V_46 * V_53 )
{
if ( V_52 -> V_50 . V_42 != V_53 -> V_50 . V_42 )
return false ;
if ( V_52 -> V_50 . V_51 !=
V_53 -> V_50 . V_51 )
return false ;
if ( strncmp ( V_52 -> V_50 . V_7 ,
V_53 -> V_50 . V_7 , V_54 ) != 0 )
return false ;
return true ;
}
static int F_42 ( struct V_11 * V_45 , T_5 V_37 ,
union V_46 * V_47 )
{
const T_5 * V_49 ;
V_49 = F_36 ( V_45 , V_37 , L_3 , NULL ) ;
if ( ! V_49 )
return - 1 ;
V_47 -> V_55 . V_42 = * V_49 ;
return 0 ;
}
static void F_43 ( union V_46 * V_47 )
{
}
static bool F_44 ( union V_46 * V_52 ,
union V_46 * V_53 )
{
if ( V_52 -> V_55 . V_42 != V_53 -> V_55 . V_42 )
return false ;
return true ;
}
static void F_45 ( const char * V_7 ,
struct V_11 * V_43 ,
struct V_11 * V_56 ,
void (* F_46)( struct V_11 * , T_5 ,
const char * V_1 ) )
{
T_1 V_57 ;
T_2 V_58 ;
T_3 V_59 ;
union V_46 V_52 ;
union V_46 V_53 ;
bool V_60 ;
T_5 V_61 ;
T_5 V_62 ;
int V_63 ;
F_1 ( V_7 , & V_57 , & V_58 ,
& V_59 ) ;
if ( ! V_57 || ! V_58 || ! V_59 ) {
F_30 ( L_5 , V_7 ) ;
return;
}
F_32 (a, a_node, name) {
V_60 = false ;
V_63 = V_57 ( V_43 , V_61 , & V_52 ) ;
if ( V_63 != 0 ) {
F_30 ( L_6 ,
V_7 ) ;
continue;
}
F_32 (b, b_node, name) {
V_63 = V_57 ( V_56 , V_62 , & V_53 ) ;
if ( V_63 != 0 )
continue;
if ( V_59 ( & V_52 , & V_53 ) ) {
V_60 = true ;
V_58 ( & V_53 ) ;
break;
}
V_58 ( & V_53 ) ;
}
V_58 ( & V_52 ) ;
if ( ! V_60 )
F_46 ( V_43 , V_61 , V_7 ) ;
}
}
static void F_47 ( struct V_34 * V_64 ,
struct V_11 * V_65 ,
struct V_11 * V_66 )
{
F_45 ( V_64 -> V_1 , V_65 , V_66 , V_64 -> remove ) ;
F_45 ( V_64 -> V_1 , V_66 , V_65 , V_64 -> V_41 ) ;
}
static void F_48 ( struct V_11 * V_65 ,
struct V_11 * V_66 )
{
struct V_34 * V_64 = V_40 ;
while ( V_64 ) {
F_47 ( V_64 , V_65 , V_66 ) ;
V_64 = V_64 -> V_39 ;
}
}
void F_49 ( void )
{
unsigned long V_67 , V_68 , V_69 ;
struct V_11 * V_12 , * V_70 ;
unsigned long V_31 ;
F_29 ( & V_38 ) ;
( void ) F_50 ( 0UL , 0UL , & V_67 ) ;
V_12 = F_19 ( V_67 , & V_71 ) ;
if ( ! V_12 ) {
F_51 ( V_72 L_7 ) ;
goto V_73;
}
V_69 = F_50 ( F_13 ( & V_12 -> V_15 ) , V_67 , & V_68 ) ;
if ( V_69 != V_74 || V_68 > V_67 ) {
F_51 ( V_72 L_8 ,
V_69 ) ;
F_52 ( & V_12 -> V_18 ) ;
F_20 ( V_12 ) ;
goto V_73;
}
F_22 ( & V_32 , V_31 ) ;
V_70 = V_33 ;
V_33 = V_12 ;
F_24 ( & V_32 , V_31 ) ;
F_48 ( V_70 , V_12 ) ;
F_22 ( & V_32 , V_31 ) ;
if ( F_26 ( & V_70 -> V_18 ) )
F_20 ( V_70 ) ;
else
F_53 ( & V_70 -> V_16 , & V_75 ) ;
F_24 ( & V_32 , V_31 ) ;
V_73:
F_31 ( & V_38 ) ;
}
T_5 F_54 ( struct V_11 * V_12 , const char * V_1 ,
union V_46 * V_47 )
{
T_1 V_57 ;
T_2 V_58 ;
T_3 V_59 ;
union V_46 V_76 ;
T_5 V_77 ;
int V_63 ;
if ( V_12 == NULL || V_1 == NULL || V_47 == NULL )
return V_78 ;
F_1 ( V_1 , & V_57 , & V_58 ,
& V_59 ) ;
if ( ! V_57 || ! V_58 || ! V_59 ) {
F_30 ( L_9 , V_1 ) ;
return - V_79 ;
}
F_32 (hp, hp_node, node_name) {
V_63 = V_57 ( V_12 , V_77 , & V_76 ) ;
if ( V_63 != 0 )
continue;
if ( V_59 ( V_47 , & V_76 ) )
break;
V_58 ( & V_76 ) ;
}
V_58 ( & V_76 ) ;
return V_77 ;
}
int F_55 ( struct V_11 * V_12 , T_5 V_37 ,
const char * V_1 , union V_46 * V_47 )
{
T_1 V_57 ;
int V_63 ;
if ( V_12 == NULL || V_37 == V_78 ||
V_1 == NULL || V_47 == NULL )
return - V_79 ;
F_1 ( V_1 , & V_57 , NULL , NULL ) ;
if ( V_57 == NULL ) {
F_30 ( L_9 , V_1 ) ;
return - V_79 ;
}
V_63 = V_57 ( V_12 , V_37 , V_47 ) ;
if ( V_63 != 0 ) {
F_30 ( L_6 ,
V_1 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_80 * F_56 ( struct V_22 * V_15 )
{
return (struct V_80 * ) ( V_15 + 1 ) ;
}
static void * F_57 ( struct V_22 * V_15 )
{
return ( ( void * ) F_56 ( V_15 ) ) + V_15 -> V_81 ;
}
static void * F_58 ( struct V_22 * V_15 )
{
return ( ( void * ) F_57 ( V_15 ) ) + V_15 -> V_82 ;
}
T_5 F_59 ( struct V_11 * V_12 ,
T_5 V_83 , const char * V_7 )
{
struct V_80 * V_84 = F_56 ( & V_12 -> V_15 ) ;
const char * V_85 = F_57 ( & V_12 -> V_15 ) ;
T_5 V_86 = V_12 -> V_15 . V_81 / 16 ;
T_5 V_87 ;
if ( V_83 == V_78 ) {
V_87 = V_83 = 0 ;
} else if ( V_83 >= V_86 ) {
return V_78 ;
} else {
V_87 = V_84 [ V_83 ] . V_88 . V_89 ;
}
while ( V_87 < V_86 ) {
if ( V_84 [ V_87 ] . V_90 != V_91 )
return V_78 ;
if ( ! strcmp ( V_85 + V_84 [ V_87 ] . V_92 , V_7 ) )
break;
V_87 = V_84 [ V_87 ] . V_88 . V_89 ;
}
if ( V_87 >= V_86 )
V_87 = V_78 ;
return V_87 ;
}
const void * F_36 ( struct V_11 * V_12 , T_5 V_37 ,
const char * V_7 , int * V_93 )
{
const char * V_85 = F_57 ( & V_12 -> V_15 ) ;
T_5 V_86 = V_12 -> V_15 . V_81 / 16 ;
void * V_94 = F_58 ( & V_12 -> V_15 ) ;
struct V_80 * V_84 ;
if ( V_37 == V_78 || V_37 >= V_86 )
return NULL ;
V_84 = F_56 ( & V_12 -> V_15 ) + V_37 ;
V_84 ++ ;
for (; V_84 -> V_90 != V_95 ; V_84 ++ ) {
void * V_89 = NULL ;
int V_67 = 0 ;
switch ( V_84 -> V_90 ) {
case V_96 :
V_89 = & V_84 -> V_88 . V_89 ;
V_67 = 8 ;
break;
case V_97 :
case V_98 :
V_89 = V_94 + V_84 -> V_88 . V_94 . V_99 ;
V_67 = V_84 -> V_88 . V_94 . V_100 ;
break;
default:
break;
}
if ( ! V_89 )
continue;
if ( ! strcmp ( V_85 + V_84 -> V_92 , V_7 ) ) {
if ( V_93 )
* V_93 = V_67 ;
return V_89 ;
}
}
return NULL ;
}
T_5 F_60 ( struct V_11 * V_12 , T_5 V_101 , const char * V_102 )
{
struct V_80 * V_84 , * V_14 = F_56 ( & V_12 -> V_15 ) ;
const char * V_85 = F_57 ( & V_12 -> V_15 ) ;
T_5 V_86 = V_12 -> V_15 . V_81 / 16 ;
if ( V_101 == V_78 || V_101 >= V_86 )
return V_78 ;
V_84 = V_14 + V_101 ;
V_84 ++ ;
for (; V_84 -> V_90 != V_95 ; V_84 ++ ) {
if ( V_84 -> V_90 != V_103 )
continue;
if ( strcmp ( V_85 + V_84 -> V_92 , V_102 ) )
continue;
return V_84 - V_14 ;
}
return V_78 ;
}
T_5 F_35 ( struct V_11 * V_12 , T_5 V_104 )
{
struct V_80 * V_84 , * V_14 = F_56 ( & V_12 -> V_15 ) ;
V_84 = V_14 + V_104 ;
return V_84 -> V_88 . V_89 ;
}
const char * F_61 ( struct V_11 * V_12 , T_5 V_37 )
{
struct V_80 * V_84 , * V_14 = F_56 ( & V_12 -> V_15 ) ;
const char * V_85 = F_57 ( & V_12 -> V_15 ) ;
T_5 V_86 = V_12 -> V_15 . V_81 / 16 ;
if ( V_37 == V_78 || V_37 >= V_86 )
return NULL ;
V_84 = V_14 + V_37 ;
if ( V_84 -> V_90 != V_91 )
return NULL ;
return V_85 + V_84 -> V_92 ;
}
static void T_4 F_62 ( void )
{
struct V_11 * V_12 = F_21 () ;
T_5 V_105 = F_59 ( V_12 , V_78 , L_10 ) ;
const char * V_106 ;
const T_5 * V_107 ;
if ( V_105 == V_78 ) {
F_63 ( L_11 ) ;
F_64 () ;
}
V_106 = F_36 ( V_12 , V_105 , L_12 , NULL ) ;
F_51 ( L_13 , V_106 ) ;
V_106 = F_36 ( V_12 , V_105 , L_4 , NULL ) ;
F_51 ( L_14 , V_106 ) ;
V_107 = F_36 ( V_12 , V_105 , L_15 , NULL ) ;
if ( V_107 )
F_51 ( L_16 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_17 , NULL ) ;
if ( V_107 )
F_51 ( L_18 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_19 , NULL ) ;
F_51 ( L_20 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_21 , NULL ) ;
if ( V_107 )
F_51 ( L_22 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_23 , NULL ) ;
if ( V_107 )
F_51 ( L_24 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_25 , NULL ) ;
if ( V_107 )
F_51 ( L_26 , * V_107 ) ;
V_107 = F_36 ( V_12 , V_105 , L_27 , NULL ) ;
if ( V_107 ) {
V_108 = * V_107 ;
F_51 ( L_28 , V_108 ) ;
}
#ifdef F_65
{
int V_109 , V_5 ;
if ( V_107 ) {
V_109 = * V_107 ;
if ( V_109 > V_110 )
V_109 = V_110 ;
} else {
V_109 = V_110 ;
}
for ( V_5 = 0 ; V_5 < V_109 ; V_5 ++ )
F_66 ( V_5 , true ) ;
}
#endif
F_25 ( V_12 ) ;
}
static void F_67 ( T_6 * V_111 , struct V_11 * V_12 , T_5 V_112 )
{
const T_5 * V_113 = F_36 ( V_12 , V_112 , L_29 , NULL ) ;
const T_5 * V_114 = F_36 ( V_12 , V_112 , L_30 , NULL ) ;
const T_5 * V_115 = F_36 ( V_12 , V_112 , L_31 , NULL ) ;
const char * type ;
int V_116 ;
type = F_36 ( V_12 , V_112 , L_32 , & V_116 ) ;
switch ( * V_113 ) {
case 1 :
if ( F_68 ( type , L_33 , V_116 ) ) {
V_111 -> V_117 = * V_114 ;
V_111 -> V_118 = * V_115 ;
} else if ( F_68 ( type , L_34 , V_116 ) ) {
V_111 -> V_119 = * V_114 ;
V_111 -> V_120 = * V_115 ;
}
break;
case 2 :
V_111 -> V_121 = * V_114 ;
V_111 -> V_122 = * V_115 ;
break;
default:
break;
}
if ( * V_113 == 1 ) {
T_5 V_43 ;
F_34 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_5 V_44 = F_35 ( V_12 , V_43 ) ;
const char * V_7 = F_61 ( V_12 , V_44 ) ;
if ( ! strcmp ( V_7 , L_35 ) )
F_67 ( V_111 , V_12 , V_44 ) ;
}
}
}
static void F_69 ( struct V_11 * V_12 , T_5 V_37 ,
char * V_123 ,
void (* F_46)( struct V_11 * , T_5 , int ) ,
T_5 V_89 , int V_124 )
{
T_5 V_104 ;
if ( V_124 == 0 )
return;
F_34 (arc, hp, node, MDESC_ARC_TYPE_BACK) {
T_5 V_125 = F_35 ( V_12 , V_104 ) ;
const char * V_7 = F_61 ( V_12 , V_125 ) ;
if ( ! strcmp ( V_123 , V_7 ) )
(* F_46)( V_12 , V_125 , V_89 ) ;
F_69 ( V_12 , V_125 , V_123 , F_46 , V_89 , V_124 - 1 ) ;
}
}
static void F_70 ( struct V_11 * V_12 , T_5 V_37 ,
int V_126 )
{
const T_5 * V_42 = F_36 ( V_12 , V_37 , L_3 , NULL ) ;
if ( * V_42 < F_71 () )
F_72 ( * V_42 ) . V_126 = V_126 ;
}
static void F_73 ( struct V_11 * V_12 , T_5 V_37 ,
int V_127 )
{
const T_5 * V_42 = F_36 ( V_12 , V_37 , L_3 , NULL ) ;
if ( * V_42 < F_71 () ) {
F_72 ( * V_42 ) . V_127 = V_127 ;
F_72 ( * V_42 ) . V_128 = V_127 ;
}
}
static void F_74 ( struct V_11 * V_12 , T_5 V_112 ,
int V_126 )
{
F_69 ( V_12 , V_112 , L_36 , F_70 , V_126 , 10 ) ;
}
static void F_75 ( struct V_11 * V_12 , T_5 V_112 ,
int V_127 )
{
F_69 ( V_12 , V_112 , L_36 , F_73 ,
V_127 , 10 ) ;
}
static void F_76 ( struct V_11 * V_12 )
{
int V_129 ;
T_5 V_112 ;
V_129 = 1 ;
F_32 (hp, mp, L_35 ) {
const T_5 * V_113 ;
const char * type ;
int V_67 ;
V_113 = F_36 ( V_12 , V_112 , L_29 , NULL ) ;
if ( * V_113 != 1 )
continue;
type = F_36 ( V_12 , V_112 , L_32 , & V_67 ) ;
if ( ! F_68 ( type , L_33 , V_67 ) )
continue;
F_74 ( V_12 , V_112 , V_129 ) ;
V_129 ++ ;
}
}
static int F_77 ( struct V_11 * V_12 , int V_113 )
{
T_5 V_112 ;
int V_129 = 1 ;
int V_130 = 0 ;
F_32 (hp, mp, L_35 ) {
const T_5 * V_131 ;
V_131 = F_36 ( V_12 , V_112 , L_29 , NULL ) ;
if ( * V_131 != V_113 )
continue;
F_75 ( V_12 , V_112 , V_129 ) ;
V_129 ++ ;
V_130 = 1 ;
}
return V_130 ;
}
static void F_78 ( struct V_11 * V_12 , T_5 V_112 )
{
int V_129 = 1 ;
F_32 (hp, mp, L_37 ) {
T_5 V_43 ;
F_34 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_5 V_132 = F_35 ( V_12 , V_43 ) ;
const char * V_7 ;
const T_5 * V_42 ;
V_7 = F_61 ( V_12 , V_132 ) ;
if ( strcmp ( V_7 , L_36 ) )
continue;
V_42 = F_36 ( V_12 , V_132 , L_3 , NULL ) ;
if ( * V_42 < F_71 () )
F_72 ( * V_42 ) . V_128 = V_129 ;
}
V_129 ++ ;
}
}
static void F_79 ( struct V_11 * V_12 )
{
T_5 V_112 ;
if ( ! F_77 ( V_12 , 3 ) )
F_77 ( V_12 , 2 ) ;
V_112 = F_59 ( V_12 , V_78 , L_38 ) ;
if ( V_112 != V_78 )
F_78 ( V_12 , V_112 ) ;
}
static void F_80 ( struct V_11 * V_12 , T_5 V_112 , int V_133 )
{
T_5 V_43 ;
F_34 (a, hp, mp, MDESC_ARC_TYPE_BACK) {
T_5 V_132 = F_35 ( V_12 , V_43 ) ;
const char * V_7 ;
const T_5 * V_42 ;
V_7 = F_61 ( V_12 , V_132 ) ;
if ( strcmp ( V_7 , L_36 ) )
continue;
V_42 = F_36 ( V_12 , V_132 , L_3 , NULL ) ;
if ( * V_42 < V_110 )
F_72 ( * V_42 ) . V_133 = V_133 ;
}
}
static void F_81 ( struct V_11 * V_12 , const char * V_134 )
{
int V_129 ;
T_5 V_112 ;
V_129 = 0 ;
F_32 (hp, mp, exec_unit_name) {
const char * type ;
int V_67 ;
type = F_36 ( V_12 , V_112 , L_32 , & V_67 ) ;
if ( ! F_68 ( type , L_39 , V_67 ) &&
! F_68 ( type , L_40 , V_67 ) )
continue;
F_80 ( V_12 , V_112 , V_129 ) ;
V_129 ++ ;
}
}
static void F_82 ( struct V_11 * V_12 )
{
F_81 ( V_12 , L_41 ) ;
F_81 ( V_12 , L_42 ) ;
}
static void F_83 ( const T_5 * V_64 , unsigned int * V_135 ,
unsigned long V_136 , unsigned long V_137 )
{
T_5 V_89 ;
if ( ! V_64 )
goto V_138;
V_89 = * V_64 ;
if ( ! V_89 || V_89 >= 64 )
goto V_138;
if ( V_89 > V_137 )
V_89 = V_137 ;
* V_135 = ( ( 1U << V_89 ) * 64U ) - 1U ;
return;
V_138:
* V_135 = ( ( 1U << V_136 ) * 64U ) - 1U ;
}
static void F_84 ( struct V_11 * V_12 , T_5 V_112 ,
struct V_139 * V_140 )
{
static int V_141 ;
const T_5 * V_89 ;
V_89 = F_36 ( V_12 , V_112 , L_43 , NULL ) ;
F_83 ( V_89 , & V_140 -> V_142 , 7 , F_85 ( V_108 * 2 ) ) ;
V_89 = F_36 ( V_12 , V_112 , L_44 , NULL ) ;
F_83 ( V_89 , & V_140 -> V_143 , 7 , 8 ) ;
V_89 = F_36 ( V_12 , V_112 , L_45 , NULL ) ;
F_83 ( V_89 , & V_140 -> V_144 , 6 , 7 ) ;
V_89 = F_36 ( V_12 , V_112 , L_46 , NULL ) ;
F_83 ( V_89 , & V_140 -> V_145 , 2 , 2 ) ;
if ( ! V_141 ++ ) {
F_86 ( L_47
L_48 ,
V_140 -> V_142 + 1 ,
V_140 -> V_143 + 1 ,
V_140 -> V_144 + 1 ,
V_140 -> V_145 + 1 ) ;
}
}
static void * F_87 ( void * (* F_46)( struct V_11 * , T_5 , int , void * ) , void * V_146 , T_7 * V_135 )
{
struct V_11 * V_12 = F_21 () ;
void * V_87 = NULL ;
T_5 V_112 ;
F_32 (hp, mp, L_36 ) {
const T_5 * V_42 = F_36 ( V_12 , V_112 , L_3 , NULL ) ;
int V_147 = * V_42 ;
#ifdef F_65
if ( V_147 >= V_110 ) {
F_51 ( V_148 L_49
L_50 ,
V_147 , V_110 ) ;
continue;
}
if ( ! F_88 ( V_147 , V_135 ) )
continue;
#endif
V_87 = F_46 ( V_12 , V_112 , V_147 , V_146 ) ;
if ( V_87 )
goto V_73;
}
V_73:
F_25 ( V_12 ) ;
return V_87 ;
}
static void * F_89 ( struct V_11 * V_12 , T_5 V_112 , int V_147 ,
void * V_146 )
{
V_149 ++ ;
#ifdef F_65
F_90 ( V_147 , true ) ;
#endif
return NULL ;
}
void F_91 ( T_7 * V_135 )
{
if ( V_150 != V_151 )
return;
V_149 = 0 ;
F_87 ( F_89 , NULL , V_135 ) ;
}
static void * T_4 F_92 ( struct V_11 * V_12 , T_5 V_112 , int V_147 , void * V_146 )
{
const T_5 * V_152 = F_36 ( V_12 , V_112 , L_51 , NULL ) ;
unsigned long * V_153 = V_146 ;
T_5 V_89 ;
V_89 = ( V_154 | V_155 |
V_156 | V_157 ) ;
if ( V_152 )
V_89 = * V_152 ;
if ( ! * V_153 )
* V_153 = V_89 ;
else
* V_153 &= V_89 ;
return NULL ;
}
void T_4 F_93 ( T_7 * V_135 , unsigned long * V_153 )
{
* V_153 = 0 ;
F_87 ( F_92 , V_153 , V_135 ) ;
}
static void * F_94 ( struct V_11 * V_12 , T_5 V_112 , int V_147 ,
void * V_146 )
{
const T_5 * V_158 = F_36 ( V_12 , V_112 , L_52 , NULL ) ;
struct V_139 * V_140 ;
T_6 * V_111 ;
T_5 V_43 ;
#ifndef F_65
if ( V_147 != F_95 () )
return NULL ;
V_147 = 0 ;
#endif
V_111 = & F_72 ( V_147 ) ;
V_111 -> V_159 = * V_158 ;
V_140 = & V_160 [ V_147 ] ;
F_84 ( V_12 , V_112 , V_140 ) ;
F_34 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_5 V_161 , V_132 = F_35 ( V_12 , V_43 ) ;
const char * V_162 ;
V_162 = F_61 ( V_12 , V_132 ) ;
if ( ! strcmp ( V_162 , L_35 ) ) {
F_67 ( V_111 , V_12 , V_132 ) ;
continue;
}
F_34 (j, hp, t, MDESC_ARC_TYPE_FWD) {
T_5 V_125 = F_35 ( V_12 , V_161 ) ;
const char * V_163 ;
V_163 = F_61 ( V_12 , V_125 ) ;
if ( ! strcmp ( V_163 , L_35 ) )
F_67 ( V_111 , V_12 , V_125 ) ;
}
}
V_111 -> V_126 = 0 ;
V_111 -> V_133 = - 1 ;
return NULL ;
}
void F_96 ( T_7 * V_135 )
{
struct V_11 * V_12 ;
F_87 ( F_94 , NULL , V_135 ) ;
V_12 = F_21 () ;
F_76 ( V_12 ) ;
F_82 ( V_12 ) ;
F_79 ( V_12 ) ;
F_25 ( V_12 ) ;
F_97 () ;
}
static int F_98 ( struct V_164 * V_164 , struct V_165 * V_165 )
{
struct V_11 * V_12 = F_21 () ;
if ( ! V_12 )
return - V_166 ;
V_165 -> V_167 = V_12 ;
return 0 ;
}
static T_8 F_99 ( struct V_165 * V_165 , char T_9 * V_168 ,
T_10 V_67 , T_11 * V_169 )
{
struct V_11 * V_12 = V_165 -> V_167 ;
unsigned char * V_15 ;
int V_170 , V_171 = V_67 ;
if ( * V_169 >= V_12 -> V_13 )
return 0 ;
V_170 = V_12 -> V_13 - * V_169 ;
if ( V_171 > V_170 )
V_171 = V_170 ;
V_15 = ( unsigned char * ) & V_12 -> V_15 ;
V_15 += * V_169 ;
if ( ! F_100 ( V_168 , V_15 , V_171 ) ) {
* V_169 += V_171 ;
return V_171 ;
} else {
return - V_172 ;
}
}
static T_11 F_101 ( struct V_165 * V_165 , T_11 V_173 , int V_174 )
{
struct V_11 * V_12 = V_165 -> V_167 ;
return F_102 ( V_165 , V_173 , V_174 , V_12 -> V_13 ) ;
}
static int F_103 ( struct V_164 * V_164 , struct V_165 * V_165 )
{
F_25 ( V_165 -> V_167 ) ;
return 0 ;
}
static int T_4 F_104 ( void )
{
return F_105 ( & V_175 ) ;
}
void T_4 F_106 ( void )
{
struct V_11 * V_12 ;
unsigned long V_67 , V_68 , V_69 ;
( void ) F_50 ( 0UL , 0UL , & V_67 ) ;
F_51 ( L_53 , V_67 ) ;
V_12 = F_19 ( V_67 , & V_176 ) ;
if ( V_12 == NULL ) {
F_63 ( L_54 , V_67 ) ;
F_64 () ;
}
V_69 = F_50 ( F_13 ( & V_12 -> V_15 ) , V_67 , & V_68 ) ;
if ( V_69 != V_74 || V_68 > V_67 ) {
F_63 ( L_55
L_56 ,
V_69 , V_67 , V_68 ) ;
F_20 ( V_12 ) ;
F_64 () ;
}
V_33 = V_12 ;
F_62 () ;
}
