static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
void * V_4 )
{
F_2 ( ( ( unsigned long ) & V_2 -> V_5 ) & ( 16UL - 1 ) ) ;
memset ( V_2 , 0 , V_3 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_4 ;
F_4 ( & V_2 -> V_8 , 1 ) ;
V_2 -> V_3 = V_3 ;
}
static struct V_1 * T_1 F_5 ( unsigned int V_9 )
{
unsigned int V_3 , V_10 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
V_3 = ( sizeof( struct V_1 ) -
sizeof( struct V_12 ) +
V_9 ) ;
V_10 = F_6 ( V_3 ) ;
V_11 = F_7 ( V_10 , V_13 ) ;
V_2 = NULL ;
if ( V_11 ) {
V_2 = F_8 ( V_11 ) ;
F_1 ( V_2 , V_3 , V_2 ) ;
}
return V_2 ;
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
unsigned long V_14 ;
F_2 ( F_10 ( & V_2 -> V_8 ) != 0 ) ;
F_2 ( ! F_11 ( & V_2 -> V_6 ) ) ;
V_10 = F_6 ( V_2 -> V_3 ) ;
V_14 = F_12 ( V_2 ) ;
F_13 ( V_14 , V_10 ) ;
}
static struct V_1 * F_14 ( unsigned int V_9 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
unsigned long V_15 ;
void * V_4 ;
V_3 = ( sizeof( struct V_1 ) -
sizeof( struct V_12 ) +
V_9 ) ;
V_4 = F_15 ( V_3 + 15 , V_16 | V_17 ) ;
V_15 = ( unsigned long ) V_4 ;
V_15 = ( V_15 + 15UL ) & ~ 15UL ;
V_2 = (struct V_1 * ) V_15 ;
F_1 ( V_2 , V_3 , V_4 ) ;
return V_2 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_2 ( F_10 ( & V_2 -> V_8 ) != 0 ) ;
F_2 ( ! F_11 ( & V_2 -> V_6 ) ) ;
F_17 ( V_2 -> V_7 ) ;
}
static struct V_1 * F_18 ( unsigned int V_9 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ( V_9 ) ;
if ( V_2 )
V_2 -> V_19 = V_19 ;
return V_2 ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_19 -> free ( V_2 ) ;
}
struct V_1 * F_20 ( void )
{
struct V_1 * V_2 ;
unsigned long V_21 ;
F_21 ( & V_22 , V_21 ) ;
V_2 = V_23 ;
if ( V_2 )
F_22 ( & V_2 -> V_8 ) ;
F_23 ( & V_22 , V_21 ) ;
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
F_21 ( & V_22 , V_21 ) ;
if ( F_25 ( & V_2 -> V_8 ) ) {
F_26 ( & V_2 -> V_6 ) ;
V_2 -> V_19 -> free ( V_2 ) ;
}
F_23 ( & V_22 , V_21 ) ;
}
void F_27 ( struct V_24 * V_25 )
{
T_2 V_26 ;
F_28 ( & V_27 ) ;
V_25 -> V_28 = V_29 ;
V_29 = V_25 ;
F_29 (cur_mdesc, node, client->node_name)
V_25 -> V_30 ( V_23 , V_26 ) ;
F_30 ( & V_27 ) ;
}
static const T_2 * F_31 ( struct V_1 * V_2 , T_2 V_26 )
{
const T_2 * V_31 ;
T_2 V_32 ;
V_31 = NULL ;
F_32 (a, hp, node, MDESC_ARC_TYPE_BACK) {
T_2 V_33 ;
V_33 = F_33 ( V_2 , V_32 ) ;
V_31 = F_34 ( V_2 , V_33 ,
L_1 , NULL ) ;
if ( V_31 )
break;
}
return V_31 ;
}
static void F_35 ( const char * V_34 ,
struct V_1 * V_32 ,
struct V_1 * V_35 ,
void (* F_36)( struct V_1 * , T_2 ) )
{
T_2 V_26 ;
F_29 (a, node, name) {
int V_36 = 0 , V_37 = 0 ;
const char * V_38 ;
const T_2 * V_31 ;
T_2 V_39 ;
V_38 = F_34 ( V_32 , V_26 , L_2 , NULL ) ;
if ( V_38 && ! strcmp ( V_38 , L_3 ) ) {
V_37 = 1 ;
V_31 = F_31 ( V_32 , V_26 ) ;
} else
V_31 = F_34 ( V_32 , V_26 , L_4 , NULL ) ;
if ( ! V_31 ) {
F_37 ( V_40 L_5 ,
( V_38 ? V_38 : V_34 ) ) ;
continue;
}
F_29 (b, fnode, name) {
const T_2 * V_41 ;
if ( V_37 ) {
V_38 = F_34 ( V_35 , V_39 ,
L_2 , NULL ) ;
if ( ! V_38 ||
strcmp ( V_38 , L_3 ) )
continue;
V_41 = F_31 ( V_35 , V_39 ) ;
if ( ! V_41 ) {
F_37 ( V_40 L_6
L_7 ) ;
continue;
}
} else
V_41 = F_34 ( V_35 , V_39 ,
L_4 , NULL ) ;
if ( * V_31 == * V_41 ) {
V_36 = 1 ;
break;
}
}
if ( ! V_36 )
F_36 ( V_32 , V_26 ) ;
}
}
static void F_38 ( struct V_24 * V_42 ,
struct V_1 * V_43 ,
struct V_1 * V_44 )
{
F_35 ( V_42 -> V_45 , V_43 , V_44 , V_42 -> remove ) ;
F_35 ( V_42 -> V_45 , V_44 , V_43 , V_42 -> V_30 ) ;
}
static void F_39 ( struct V_1 * V_43 ,
struct V_1 * V_44 )
{
struct V_24 * V_42 = V_29 ;
while ( V_42 ) {
F_38 ( V_42 , V_43 , V_44 ) ;
V_42 = V_42 -> V_28 ;
}
}
void F_40 ( void )
{
unsigned long V_46 , V_47 , V_48 ;
struct V_1 * V_2 , * V_49 ;
unsigned long V_21 ;
F_28 ( & V_27 ) ;
( void ) F_41 ( 0UL , 0UL , & V_46 ) ;
V_2 = F_18 ( V_46 , & V_50 ) ;
if ( ! V_2 ) {
F_37 ( V_40 L_8 ) ;
goto V_51;
}
V_48 = F_41 ( F_12 ( & V_2 -> V_5 ) , V_46 , & V_47 ) ;
if ( V_48 != V_52 || V_47 > V_46 ) {
F_37 ( V_40 L_9 ,
V_48 ) ;
F_42 ( & V_2 -> V_8 ) ;
F_19 ( V_2 ) ;
goto V_51;
}
F_21 ( & V_22 , V_21 ) ;
V_49 = V_23 ;
V_23 = V_2 ;
F_23 ( & V_22 , V_21 ) ;
F_39 ( V_49 , V_2 ) ;
F_21 ( & V_22 , V_21 ) ;
if ( F_25 ( & V_49 -> V_8 ) )
F_19 ( V_49 ) ;
else
F_43 ( & V_49 -> V_6 , & V_53 ) ;
F_23 ( & V_22 , V_21 ) ;
V_51:
F_30 ( & V_27 ) ;
}
static struct V_54 * F_44 ( struct V_12 * V_5 )
{
return (struct V_54 * ) ( V_5 + 1 ) ;
}
static void * F_45 ( struct V_12 * V_5 )
{
return ( ( void * ) F_44 ( V_5 ) ) + V_5 -> V_55 ;
}
static void * F_46 ( struct V_12 * V_5 )
{
return ( ( void * ) F_45 ( V_5 ) ) + V_5 -> V_56 ;
}
T_2 F_47 ( struct V_1 * V_2 ,
T_2 V_57 , const char * V_34 )
{
struct V_54 * V_58 = F_44 ( & V_2 -> V_5 ) ;
const char * V_59 = F_45 ( & V_2 -> V_5 ) ;
T_2 V_60 = V_2 -> V_5 . V_55 / 16 ;
T_2 V_61 ;
if ( V_57 == V_62 ) {
V_61 = V_57 = 0 ;
} else if ( V_57 >= V_60 ) {
return V_62 ;
} else {
V_61 = V_58 [ V_57 ] . V_63 . V_64 ;
}
while ( V_61 < V_60 ) {
if ( V_58 [ V_61 ] . V_65 != V_66 )
return V_62 ;
if ( ! strcmp ( V_59 + V_58 [ V_61 ] . V_67 , V_34 ) )
break;
V_61 = V_58 [ V_61 ] . V_63 . V_64 ;
}
if ( V_61 >= V_60 )
V_61 = V_62 ;
return V_61 ;
}
const void * F_34 ( struct V_1 * V_2 , T_2 V_26 ,
const char * V_34 , int * V_68 )
{
const char * V_59 = F_45 ( & V_2 -> V_5 ) ;
T_2 V_60 = V_2 -> V_5 . V_55 / 16 ;
void * V_69 = F_46 ( & V_2 -> V_5 ) ;
struct V_54 * V_58 ;
if ( V_26 == V_62 || V_26 >= V_60 )
return NULL ;
V_58 = F_44 ( & V_2 -> V_5 ) + V_26 ;
V_58 ++ ;
for (; V_58 -> V_65 != V_70 ; V_58 ++ ) {
void * V_64 = NULL ;
int V_46 = 0 ;
switch ( V_58 -> V_65 ) {
case V_71 :
V_64 = & V_58 -> V_63 . V_64 ;
V_46 = 8 ;
break;
case V_72 :
case V_73 :
V_64 = V_69 + V_58 -> V_63 . V_69 . V_74 ;
V_46 = V_58 -> V_63 . V_69 . V_75 ;
break;
default:
break;
}
if ( ! V_64 )
continue;
if ( ! strcmp ( V_59 + V_58 -> V_67 , V_34 ) ) {
if ( V_68 )
* V_68 = V_46 ;
return V_64 ;
}
}
return NULL ;
}
T_2 F_48 ( struct V_1 * V_2 , T_2 V_76 , const char * V_77 )
{
struct V_54 * V_58 , * V_4 = F_44 ( & V_2 -> V_5 ) ;
const char * V_59 = F_45 ( & V_2 -> V_5 ) ;
T_2 V_60 = V_2 -> V_5 . V_55 / 16 ;
if ( V_76 == V_62 || V_76 >= V_60 )
return V_62 ;
V_58 = V_4 + V_76 ;
V_58 ++ ;
for (; V_58 -> V_65 != V_70 ; V_58 ++ ) {
if ( V_58 -> V_65 != V_78 )
continue;
if ( strcmp ( V_59 + V_58 -> V_67 , V_77 ) )
continue;
return V_58 - V_4 ;
}
return V_62 ;
}
T_2 F_33 ( struct V_1 * V_2 , T_2 V_79 )
{
struct V_54 * V_58 , * V_4 = F_44 ( & V_2 -> V_5 ) ;
V_58 = V_4 + V_79 ;
return V_58 -> V_63 . V_64 ;
}
const char * F_49 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_54 * V_58 , * V_4 = F_44 ( & V_2 -> V_5 ) ;
const char * V_59 = F_45 ( & V_2 -> V_5 ) ;
T_2 V_60 = V_2 -> V_5 . V_55 / 16 ;
if ( V_26 == V_62 || V_26 >= V_60 )
return NULL ;
V_58 = V_4 + V_26 ;
if ( V_58 -> V_65 != V_66 )
return NULL ;
return V_59 + V_58 -> V_67 ;
}
static void T_1 F_50 ( void )
{
struct V_1 * V_2 = F_20 () ;
T_2 V_80 = F_47 ( V_2 , V_62 , L_10 ) ;
const char * V_81 ;
const T_2 * V_82 ;
if ( V_80 == V_62 ) {
F_51 ( L_11 ) ;
F_52 () ;
}
V_81 = F_34 ( V_2 , V_80 , L_12 , NULL ) ;
F_37 ( L_13 , V_81 ) ;
V_81 = F_34 ( V_2 , V_80 , L_2 , NULL ) ;
F_37 ( L_14 , V_81 ) ;
V_82 = F_34 ( V_2 , V_80 , L_15 , NULL ) ;
if ( V_82 )
F_37 ( L_16 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_17 , NULL ) ;
if ( V_82 )
F_37 ( L_18 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_19 , NULL ) ;
F_37 ( L_20 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_21 , NULL ) ;
if ( V_82 )
F_37 ( L_22 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_23 , NULL ) ;
if ( V_82 )
F_37 ( L_24 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_25 , NULL ) ;
if ( V_82 )
F_37 ( L_26 , * V_82 ) ;
V_82 = F_34 ( V_2 , V_80 , L_27 , NULL ) ;
if ( V_82 ) {
V_83 = * V_82 ;
F_37 ( L_28 , V_83 ) ;
}
#ifdef F_53
{
int V_84 , V_85 ;
if ( V_82 ) {
V_84 = * V_82 ;
if ( V_84 > V_86 )
V_84 = V_86 ;
} else {
V_84 = V_86 ;
}
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ )
F_54 ( V_85 , true ) ;
}
#endif
F_24 ( V_2 ) ;
}
static void F_55 ( T_3 * V_87 , struct V_1 * V_2 , T_2 V_88 )
{
const T_2 * V_89 = F_34 ( V_2 , V_88 , L_29 , NULL ) ;
const T_2 * V_90 = F_34 ( V_2 , V_88 , L_30 , NULL ) ;
const T_2 * V_91 = F_34 ( V_2 , V_88 , L_31 , NULL ) ;
const char * type ;
int V_92 ;
type = F_34 ( V_2 , V_88 , L_32 , & V_92 ) ;
switch ( * V_89 ) {
case 1 :
if ( F_56 ( type , L_33 , V_92 ) ) {
V_87 -> V_93 = * V_90 ;
V_87 -> V_94 = * V_91 ;
} else if ( F_56 ( type , L_34 , V_92 ) ) {
V_87 -> V_95 = * V_90 ;
V_87 -> V_96 = * V_91 ;
}
break;
case 2 :
V_87 -> V_97 = * V_90 ;
V_87 -> V_98 = * V_91 ;
break;
default:
break;
}
if ( * V_89 == 1 ) {
T_2 V_32 ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_2 V_33 = F_33 ( V_2 , V_32 ) ;
const char * V_34 = F_49 ( V_2 , V_33 ) ;
if ( ! strcmp ( V_34 , L_35 ) )
F_55 ( V_87 , V_2 , V_33 ) ;
}
}
}
static void F_57 ( struct V_1 * V_2 , T_2 V_26 ,
char * V_99 ,
void (* F_36)( struct V_1 * , T_2 , int ) ,
T_2 V_64 , int V_100 )
{
T_2 V_79 ;
if ( V_100 == 0 )
return;
F_32 (arc, hp, node, MDESC_ARC_TYPE_BACK) {
T_2 V_101 = F_33 ( V_2 , V_79 ) ;
const char * V_34 = F_49 ( V_2 , V_101 ) ;
if ( ! strcmp ( V_99 , V_34 ) )
(* F_36)( V_2 , V_101 , V_64 ) ;
F_57 ( V_2 , V_101 , V_99 , F_36 , V_64 , V_100 - 1 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , T_2 V_26 ,
int V_102 )
{
const T_2 * V_31 = F_34 ( V_2 , V_26 , L_4 , NULL ) ;
if ( * V_31 < F_59 () )
F_60 ( * V_31 ) . V_102 = V_102 ;
}
static void F_61 ( struct V_1 * V_2 , T_2 V_26 ,
int V_103 )
{
const T_2 * V_31 = F_34 ( V_2 , V_26 , L_4 , NULL ) ;
if ( * V_31 < F_59 () )
F_60 ( * V_31 ) . V_103 = V_103 ;
}
static void F_62 ( struct V_1 * V_2 , T_2 V_88 ,
int V_102 )
{
F_57 ( V_2 , V_88 , L_36 , F_58 , V_102 , 10 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 V_88 ,
int V_103 )
{
F_57 ( V_2 , V_88 , L_36 , F_61 , V_103 , 10 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_104 ;
T_2 V_88 ;
V_104 = 1 ;
F_29 (hp, mp, L_35 ) {
const T_2 * V_89 ;
const char * type ;
int V_46 ;
V_89 = F_34 ( V_2 , V_88 , L_29 , NULL ) ;
if ( * V_89 != 1 )
continue;
type = F_34 ( V_2 , V_88 , L_32 , & V_46 ) ;
if ( ! F_56 ( type , L_33 , V_46 ) )
continue;
F_62 ( V_2 , V_88 , V_104 ) ;
V_104 ++ ;
}
}
static int F_65 ( struct V_1 * V_2 , int V_89 )
{
T_2 V_88 ;
int V_104 = 1 ;
int V_105 = 0 ;
F_29 (hp, mp, L_35 ) {
const T_2 * V_106 ;
V_106 = F_34 ( V_2 , V_88 , L_29 , NULL ) ;
if ( * V_106 != V_89 )
continue;
F_63 ( V_2 , V_88 , V_104 ) ;
V_104 ++ ;
V_105 = 1 ;
}
return V_105 ;
}
static void F_66 ( struct V_1 * V_2 , T_2 V_88 )
{
int V_104 = 1 ;
F_29 (hp, mp, L_37 ) {
T_2 V_32 ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_2 V_107 = F_33 ( V_2 , V_32 ) ;
const char * V_34 ;
const T_2 * V_31 ;
V_34 = F_49 ( V_2 , V_107 ) ;
if ( strcmp ( V_34 , L_36 ) )
continue;
V_31 = F_34 ( V_2 , V_107 , L_4 , NULL ) ;
if ( * V_31 < F_59 () )
F_60 ( * V_31 ) . V_103 = V_104 ;
}
V_104 ++ ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
T_2 V_88 ;
V_88 = F_47 ( V_2 , V_62 , L_38 ) ;
if ( V_88 != V_62 )
return F_66 ( V_2 , V_88 ) ;
if ( ! F_65 ( V_2 , 3 ) )
F_65 ( V_2 , 2 ) ;
}
static void F_68 ( struct V_1 * V_2 , T_2 V_88 , int V_108 )
{
T_2 V_32 ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_BACK) {
T_2 V_107 = F_33 ( V_2 , V_32 ) ;
const char * V_34 ;
const T_2 * V_31 ;
V_34 = F_49 ( V_2 , V_107 ) ;
if ( strcmp ( V_34 , L_36 ) )
continue;
V_31 = F_34 ( V_2 , V_107 , L_4 , NULL ) ;
if ( * V_31 < V_86 )
F_60 ( * V_31 ) . V_108 = V_108 ;
}
}
static void F_69 ( struct V_1 * V_2 , const char * V_109 )
{
int V_104 ;
T_2 V_88 ;
V_104 = 0 ;
F_29 (hp, mp, exec_unit_name) {
const char * type ;
int V_46 ;
type = F_34 ( V_2 , V_88 , L_32 , & V_46 ) ;
if ( ! F_56 ( type , L_39 , V_46 ) &&
! F_56 ( type , L_40 , V_46 ) )
continue;
F_68 ( V_2 , V_88 , V_104 ) ;
V_104 ++ ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
F_69 ( V_2 , L_41 ) ;
F_69 ( V_2 , L_42 ) ;
}
static void F_71 ( const T_2 * V_42 , unsigned int * V_110 ,
unsigned long V_111 , unsigned long V_112 )
{
T_2 V_64 ;
if ( ! V_42 )
goto V_113;
V_64 = * V_42 ;
if ( ! V_64 || V_64 >= 64 )
goto V_113;
if ( V_64 > V_112 )
V_64 = V_112 ;
* V_110 = ( ( 1U << V_64 ) * 64U ) - 1U ;
return;
V_113:
* V_110 = ( ( 1U << V_111 ) * 64U ) - 1U ;
}
static void F_72 ( struct V_1 * V_2 , T_2 V_88 ,
struct V_114 * V_115 )
{
static int V_116 ;
const T_2 * V_64 ;
V_64 = F_34 ( V_2 , V_88 , L_43 , NULL ) ;
F_71 ( V_64 , & V_115 -> V_117 , 7 , F_73 ( V_83 * 2 ) ) ;
V_64 = F_34 ( V_2 , V_88 , L_44 , NULL ) ;
F_71 ( V_64 , & V_115 -> V_118 , 7 , 8 ) ;
V_64 = F_34 ( V_2 , V_88 , L_45 , NULL ) ;
F_71 ( V_64 , & V_115 -> V_119 , 6 , 7 ) ;
V_64 = F_34 ( V_2 , V_88 , L_46 , NULL ) ;
F_71 ( V_64 , & V_115 -> V_120 , 2 , 2 ) ;
if ( ! V_116 ++ ) {
F_74 ( L_47
L_48 ,
V_115 -> V_117 + 1 ,
V_115 -> V_118 + 1 ,
V_115 -> V_119 + 1 ,
V_115 -> V_120 + 1 ) ;
}
}
static void * F_75 ( void * (* F_36)( struct V_1 * , T_2 , int , void * ) , void * V_121 , T_4 * V_110 )
{
struct V_1 * V_2 = F_20 () ;
void * V_61 = NULL ;
T_2 V_88 ;
F_29 (hp, mp, L_36 ) {
const T_2 * V_31 = F_34 ( V_2 , V_88 , L_4 , NULL ) ;
int V_122 = * V_31 ;
#ifdef F_53
if ( V_122 >= V_86 ) {
F_37 ( V_123 L_49
L_50 ,
V_122 , V_86 ) ;
continue;
}
if ( ! F_76 ( V_122 , V_110 ) )
continue;
#endif
V_61 = F_36 ( V_2 , V_88 , V_122 , V_121 ) ;
if ( V_61 )
goto V_51;
}
V_51:
F_24 ( V_2 ) ;
return V_61 ;
}
static void * F_77 ( struct V_1 * V_2 , T_2 V_88 , int V_122 ,
void * V_121 )
{
V_124 ++ ;
#ifdef F_53
F_78 ( V_122 , true ) ;
#endif
return NULL ;
}
void F_79 ( T_4 * V_110 )
{
if ( V_125 != V_126 )
return;
V_124 = 0 ;
F_75 ( F_77 , NULL , V_110 ) ;
}
static void * T_1 F_80 ( struct V_1 * V_2 , T_2 V_88 , int V_122 , void * V_121 )
{
const T_2 * V_127 = F_34 ( V_2 , V_88 , L_51 , NULL ) ;
unsigned long * V_128 = V_121 ;
T_2 V_64 ;
V_64 = ( V_129 | V_130 |
V_131 | V_132 ) ;
if ( V_127 )
V_64 = * V_127 ;
if ( ! * V_128 )
* V_128 = V_64 ;
else
* V_128 &= V_64 ;
return NULL ;
}
void T_1 F_81 ( T_4 * V_110 , unsigned long * V_128 )
{
* V_128 = 0 ;
F_75 ( F_80 , V_128 , V_110 ) ;
}
static void * F_82 ( struct V_1 * V_2 , T_2 V_88 , int V_122 ,
void * V_121 )
{
const T_2 * V_133 = F_34 ( V_2 , V_88 , L_52 , NULL ) ;
struct V_114 * V_115 ;
T_3 * V_87 ;
T_2 V_32 ;
#ifndef F_53
if ( V_122 != F_83 () )
return NULL ;
V_122 = 0 ;
#endif
V_87 = & F_60 ( V_122 ) ;
V_87 -> V_134 = * V_133 ;
V_115 = & V_135 [ V_122 ] ;
F_72 ( V_2 , V_88 , V_115 ) ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_2 V_136 , V_107 = F_33 ( V_2 , V_32 ) ;
const char * V_137 ;
V_137 = F_49 ( V_2 , V_107 ) ;
if ( ! strcmp ( V_137 , L_35 ) ) {
F_55 ( V_87 , V_2 , V_107 ) ;
continue;
}
F_32 (j, hp, t, MDESC_ARC_TYPE_FWD) {
T_2 V_101 = F_33 ( V_2 , V_136 ) ;
const char * V_138 ;
V_138 = F_49 ( V_2 , V_101 ) ;
if ( ! strcmp ( V_138 , L_35 ) )
F_55 ( V_87 , V_2 , V_101 ) ;
}
}
V_87 -> V_102 = 0 ;
V_87 -> V_108 = - 1 ;
return NULL ;
}
void F_84 ( T_4 * V_110 )
{
struct V_1 * V_2 ;
F_75 ( F_82 , NULL , V_110 ) ;
V_2 = F_20 () ;
F_64 ( V_2 ) ;
F_70 ( V_2 ) ;
F_67 ( V_2 ) ;
F_24 ( V_2 ) ;
F_85 () ;
}
static int F_86 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
struct V_1 * V_2 = F_20 () ;
if ( ! V_2 )
return - V_141 ;
V_140 -> V_142 = V_2 ;
return 0 ;
}
static T_5 F_87 ( struct V_140 * V_140 , char T_6 * V_143 ,
T_7 V_46 , T_8 * V_144 )
{
struct V_1 * V_2 = V_140 -> V_142 ;
unsigned char * V_5 ;
int V_145 , V_146 = V_46 ;
if ( * V_144 >= V_2 -> V_3 )
return 0 ;
V_145 = V_2 -> V_3 - * V_144 ;
if ( V_146 > V_145 )
V_146 = V_145 ;
V_5 = ( unsigned char * ) & V_2 -> V_5 ;
V_5 += * V_144 ;
if ( ! F_88 ( V_143 , V_5 , V_146 ) ) {
* V_144 += V_146 ;
return V_146 ;
} else {
return - V_147 ;
}
}
static T_8 F_89 ( struct V_140 * V_140 , T_8 V_148 , int V_149 )
{
struct V_1 * V_2 = V_140 -> V_142 ;
return F_90 ( V_140 , V_148 , V_149 , V_2 -> V_3 ) ;
}
static int F_91 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
F_24 ( V_140 -> V_142 ) ;
return 0 ;
}
static int T_1 F_92 ( void )
{
return F_93 ( & V_150 ) ;
}
void T_1 F_94 ( void )
{
struct V_1 * V_2 ;
unsigned long V_46 , V_47 , V_48 ;
( void ) F_41 ( 0UL , 0UL , & V_46 ) ;
F_37 ( L_53 , V_46 ) ;
V_2 = F_18 ( V_46 , & V_151 ) ;
if ( V_2 == NULL ) {
F_51 ( L_54 , V_46 ) ;
F_52 () ;
}
V_48 = F_41 ( F_12 ( & V_2 -> V_5 ) , V_46 , & V_47 ) ;
if ( V_48 != V_52 || V_47 > V_46 ) {
F_51 ( L_55
L_56 ,
V_48 , V_46 , V_47 ) ;
F_19 ( V_2 ) ;
F_52 () ;
}
V_23 = V_2 ;
F_50 () ;
}
