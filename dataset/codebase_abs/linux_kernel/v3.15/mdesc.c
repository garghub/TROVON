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
void * V_4 ;
V_3 = ( sizeof( struct V_1 ) -
sizeof( struct V_12 ) +
V_9 ) ;
V_4 = F_15 ( V_3 + 15 , V_15 | V_16 ) ;
if ( V_4 ) {
struct V_1 * V_2 ;
unsigned long V_17 ;
V_17 = ( unsigned long ) V_4 ;
V_17 = ( V_17 + 15UL ) & ~ 15UL ;
V_2 = (struct V_1 * ) V_17 ;
F_1 ( V_2 , V_3 , V_4 ) ;
return V_2 ;
}
return NULL ;
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
static void F_57 ( struct V_1 * V_2 , T_2 V_88 , int V_99 )
{
T_2 V_32 ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_BACK) {
T_2 V_100 = F_33 ( V_2 , V_32 ) ;
const char * V_34 ;
const T_2 * V_31 ;
V_34 = F_49 ( V_2 , V_100 ) ;
if ( ! strcmp ( V_34 , L_36 ) ) {
V_31 = F_34 ( V_2 , V_100 , L_4 , NULL ) ;
if ( * V_31 < V_86 )
F_58 ( * V_31 ) . V_99 = V_99 ;
} else {
T_2 V_101 ;
F_32 (j, hp, t, MDESC_ARC_TYPE_BACK) {
T_2 V_102 = F_33 ( V_2 , V_101 ) ;
const char * V_103 ;
V_103 = F_49 ( V_2 , V_102 ) ;
if ( strcmp ( V_103 , L_36 ) )
continue;
V_31 = F_34 ( V_2 , V_102 , L_4 , NULL ) ;
if ( * V_31 < V_86 )
F_58 ( * V_31 ) . V_99 = V_99 ;
}
}
}
}
static void F_59 ( struct V_1 * V_2 )
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
F_57 ( V_2 , V_88 , V_104 ) ;
V_104 ++ ;
}
}
static void F_60 ( struct V_1 * V_2 , T_2 V_88 , int V_105 )
{
T_2 V_32 ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_BACK) {
T_2 V_100 = F_33 ( V_2 , V_32 ) ;
const char * V_34 ;
const T_2 * V_31 ;
V_34 = F_49 ( V_2 , V_100 ) ;
if ( strcmp ( V_34 , L_36 ) )
continue;
V_31 = F_34 ( V_2 , V_100 , L_4 , NULL ) ;
if ( * V_31 < V_86 )
F_58 ( * V_31 ) . V_105 = V_105 ;
}
}
static void F_61 ( struct V_1 * V_2 , const char * V_106 )
{
int V_104 ;
T_2 V_88 ;
V_104 = 0 ;
F_29 (hp, mp, exec_unit_name) {
const char * type ;
int V_46 ;
type = F_34 ( V_2 , V_88 , L_32 , & V_46 ) ;
if ( ! F_56 ( type , L_37 , V_46 ) &&
! F_56 ( type , L_38 , V_46 ) )
continue;
F_60 ( V_2 , V_88 , V_104 ) ;
V_104 ++ ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
F_61 ( V_2 , L_39 ) ;
F_61 ( V_2 , L_40 ) ;
}
static void F_63 ( const T_2 * V_42 , unsigned int * V_107 ,
unsigned long V_108 , unsigned long V_109 )
{
T_2 V_64 ;
if ( ! V_42 )
goto V_110;
V_64 = * V_42 ;
if ( ! V_64 || V_64 >= 64 )
goto V_110;
if ( V_64 > V_109 )
V_64 = V_109 ;
* V_107 = ( ( 1U << V_64 ) * 64U ) - 1U ;
return;
V_110:
* V_107 = ( ( 1U << V_108 ) * 64U ) - 1U ;
}
static void F_64 ( struct V_1 * V_2 , T_2 V_88 ,
struct V_111 * V_112 )
{
static int V_113 ;
const T_2 * V_64 ;
V_64 = F_34 ( V_2 , V_88 , L_41 , NULL ) ;
F_63 ( V_64 , & V_112 -> V_114 , 7 , F_65 ( V_83 * 2 ) ) ;
V_64 = F_34 ( V_2 , V_88 , L_42 , NULL ) ;
F_63 ( V_64 , & V_112 -> V_115 , 7 , 8 ) ;
V_64 = F_34 ( V_2 , V_88 , L_43 , NULL ) ;
F_63 ( V_64 , & V_112 -> V_116 , 6 , 7 ) ;
V_64 = F_34 ( V_2 , V_88 , L_44 , NULL ) ;
F_63 ( V_64 , & V_112 -> V_117 , 2 , 2 ) ;
if ( ! V_113 ++ ) {
F_66 ( L_45
L_46 ,
V_112 -> V_114 + 1 ,
V_112 -> V_115 + 1 ,
V_112 -> V_116 + 1 ,
V_112 -> V_117 + 1 ) ;
}
}
static void * F_67 ( void * (* F_36)( struct V_1 * , T_2 , int , void * ) , void * V_118 , T_4 * V_107 )
{
struct V_1 * V_2 = F_20 () ;
void * V_61 = NULL ;
T_2 V_88 ;
F_29 (hp, mp, L_36 ) {
const T_2 * V_31 = F_34 ( V_2 , V_88 , L_4 , NULL ) ;
int V_119 = * V_31 ;
#ifdef F_53
if ( V_119 >= V_86 ) {
F_37 ( V_120 L_47
L_48 ,
V_119 , V_86 ) ;
continue;
}
if ( ! F_68 ( V_119 , V_107 ) )
continue;
#endif
V_61 = F_36 ( V_2 , V_88 , V_119 , V_118 ) ;
if ( V_61 )
goto V_51;
}
V_51:
F_24 ( V_2 ) ;
return V_61 ;
}
static void * F_69 ( struct V_1 * V_2 , T_2 V_88 , int V_119 ,
void * V_118 )
{
V_121 ++ ;
#ifdef F_53
F_70 ( V_119 , true ) ;
#endif
return NULL ;
}
void F_71 ( T_4 * V_107 )
{
if ( V_122 != V_123 )
return;
V_121 = 0 ;
F_67 ( F_69 , NULL , V_107 ) ;
}
static void * T_1 F_72 ( struct V_1 * V_2 , T_2 V_88 , int V_119 , void * V_118 )
{
const T_2 * V_124 = F_34 ( V_2 , V_88 , L_49 , NULL ) ;
unsigned long * V_125 = V_118 ;
T_2 V_64 ;
V_64 = ( V_126 | V_127 |
V_128 | V_129 ) ;
if ( V_124 )
V_64 = * V_124 ;
if ( ! * V_125 )
* V_125 = V_64 ;
else
* V_125 &= V_64 ;
return NULL ;
}
void T_1 F_73 ( T_4 * V_107 , unsigned long * V_125 )
{
* V_125 = 0 ;
F_67 ( F_72 , V_125 , V_107 ) ;
}
static void * F_74 ( struct V_1 * V_2 , T_2 V_88 , int V_119 ,
void * V_118 )
{
const T_2 * V_130 = F_34 ( V_2 , V_88 , L_50 , NULL ) ;
struct V_111 * V_112 ;
T_3 * V_87 ;
T_2 V_32 ;
#ifndef F_53
if ( V_119 != F_75 () )
return NULL ;
V_119 = 0 ;
#endif
V_87 = & F_58 ( V_119 ) ;
V_87 -> V_131 = * V_130 ;
V_112 = & V_132 [ V_119 ] ;
F_64 ( V_2 , V_88 , V_112 ) ;
F_32 (a, hp, mp, MDESC_ARC_TYPE_FWD) {
T_2 V_101 , V_100 = F_33 ( V_2 , V_32 ) ;
const char * V_133 ;
V_133 = F_49 ( V_2 , V_100 ) ;
if ( ! strcmp ( V_133 , L_35 ) ) {
F_55 ( V_87 , V_2 , V_100 ) ;
continue;
}
F_32 (j, hp, t, MDESC_ARC_TYPE_FWD) {
T_2 V_102 = F_33 ( V_2 , V_101 ) ;
const char * V_103 ;
V_103 = F_49 ( V_2 , V_102 ) ;
if ( ! strcmp ( V_103 , L_35 ) )
F_55 ( V_87 , V_2 , V_102 ) ;
}
}
V_87 -> V_99 = 0 ;
V_87 -> V_105 = - 1 ;
return NULL ;
}
void F_76 ( T_4 * V_107 )
{
struct V_1 * V_2 ;
F_67 ( F_74 , NULL , V_107 ) ;
V_2 = F_20 () ;
F_59 ( V_2 ) ;
F_62 ( V_2 ) ;
F_24 ( V_2 ) ;
F_77 () ;
}
static T_5 F_78 ( struct V_134 * V_134 , char T_6 * V_135 ,
T_7 V_46 , T_8 * V_136 )
{
struct V_1 * V_2 = F_20 () ;
int V_137 ;
if ( ! V_2 )
return - V_138 ;
V_137 = V_2 -> V_3 ;
if ( V_46 < V_2 -> V_3 )
V_137 = - V_139 ;
else if ( F_79 ( V_135 , & V_2 -> V_5 , V_2 -> V_3 ) )
V_137 = - V_140 ;
F_24 ( V_2 ) ;
return V_137 ;
}
static int T_1 F_80 ( void )
{
return F_81 ( & V_141 ) ;
}
void T_1 F_82 ( void )
{
struct V_1 * V_2 ;
unsigned long V_46 , V_47 , V_48 ;
( void ) F_41 ( 0UL , 0UL , & V_46 ) ;
F_37 ( L_51 , V_46 ) ;
V_2 = F_18 ( V_46 , & V_142 ) ;
if ( V_2 == NULL ) {
F_51 ( L_52 , V_46 ) ;
F_52 () ;
}
V_48 = F_41 ( F_12 ( & V_2 -> V_5 ) , V_46 , & V_47 ) ;
if ( V_48 != V_52 || V_47 > V_46 ) {
F_51 ( L_53
L_54 ,
V_48 , V_46 , V_47 ) ;
F_19 ( V_2 ) ;
F_52 () ;
}
V_23 = V_2 ;
F_50 () ;
}
