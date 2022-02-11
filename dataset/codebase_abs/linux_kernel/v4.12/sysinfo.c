static inline int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 , int * V_5 )
{
register int T_1 V_6 ( L_1 ) = ( V_2 << 28 ) | V_3 ;
register int T_2 V_6 ( L_2 ) = V_4 ;
int V_7 = 0 ;
asm volatile(
" stsi 0(%3)\n"
"0: jz 2f\n"
"1: lhi %1,%4\n"
"2:\n"
EX_TABLE(0b, 1b)
: "+d" (r0), "+d" (rc)
: "d" (r1), "a" (sysinfo), "K" (-EOPNOTSUPP)
: "cc", "memory");
* V_5 = ( ( unsigned int ) T_1 ) >> 28 ;
return V_7 ;
}
int F_2 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 , V_7 ;
V_7 = F_1 ( V_1 , V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_7 )
return V_7 ;
return V_2 ? 0 : V_5 ;
}
static bool F_3 ( unsigned char V_8 , char * V_9 , T_3 V_10 )
{
switch ( V_8 ) {
case 1 :
F_4 ( V_9 , V_10 ) ;
break;
case 2 :
break;
default:
return false ;
}
return true ;
}
static void F_5 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
int V_15 ;
if ( F_2 ( V_14 , 1 , 1 , 1 ) )
return;
F_4 ( V_14 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
F_4 ( V_14 -> type , sizeof( V_14 -> type ) ) ;
F_4 ( V_14 -> V_17 , sizeof( V_14 -> V_17 ) ) ;
F_4 ( V_14 -> V_18 , sizeof( V_14 -> V_18 ) ) ;
F_4 ( V_14 -> V_19 , sizeof( V_14 -> V_19 ) ) ;
F_4 ( V_14 -> V_20 , sizeof( V_14 -> V_20 ) ) ;
F_4 ( V_14 -> V_21 , sizeof( V_14 -> V_21 ) ) ;
F_4 ( V_14 -> V_22 , sizeof( V_14 -> V_22 ) ) ;
F_6 ( V_12 , L_3 , V_14 -> V_16 ) ;
F_6 ( V_12 , L_4 , V_14 -> type ) ;
F_6 ( V_12 , L_5 , V_14 -> V_20 ) ;
if ( V_14 -> V_17 [ 0 ] != '\0' )
F_6 ( V_12 , L_6 , V_14 -> V_17 ) ;
F_7 ( V_12 , '\n' ) ;
F_6 ( V_12 , L_7 , V_14 -> V_18 ) ;
F_6 ( V_12 , L_8 , V_14 -> V_19 ) ;
F_6 ( V_12 , L_9 ,
V_14 -> V_20 , V_14 -> V_23 ) ;
if ( V_14 -> V_24 )
F_6 ( V_12 , L_10 ,
V_14 -> V_21 ,
V_14 -> V_24 ) ;
if ( V_14 -> V_25 )
F_6 ( V_12 , L_11 ,
V_14 -> V_22 ,
V_14 -> V_25 ) ;
if ( V_14 -> V_26 )
F_6 ( V_12 , L_12 , V_14 -> V_26 ) ;
if ( V_14 -> V_27 )
F_6 ( V_12 , L_13 , V_14 -> V_27 ) ;
if ( V_14 -> V_28 )
F_6 ( V_12 , L_14 , V_14 -> V_28 ) ;
if ( V_14 -> V_29 ) {
F_6 ( V_12 , L_15 , V_14 -> V_29 ) ;
F_6 ( V_12 , L_16 , V_14 -> V_30 ) ;
F_6 ( V_12 , L_17 , V_14 -> V_31 ) ;
}
if ( V_14 -> V_32 ) {
for ( V_15 = 1 ; V_15 <= F_8 ( V_14 -> V_33 ) ; V_15 ++ ) {
F_6 ( V_12 , L_18 ,
V_15 , V_14 -> V_33 [ V_15 - 1 ] ) ;
}
}
}
static void F_9 ( struct V_11 * V_12 , struct V_34 * V_14 )
{
int V_15 ;
F_7 ( V_12 , '\n' ) ;
if ( ! V_35 )
return;
if ( F_2 ( V_14 , 15 , 1 , V_36 ) )
return;
F_6 ( V_12 , L_19 ) ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ )
F_6 ( V_12 , L_20 , V_14 -> V_38 [ V_15 ] ) ;
F_7 ( V_12 , '\n' ) ;
#ifdef F_10
F_11 ( V_14 ) ;
F_6 ( V_12 , L_21 ) ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ )
F_6 ( V_12 , L_20 , V_14 -> V_38 [ V_15 ] ) ;
F_7 ( V_12 , '\n' ) ;
#endif
}
static void F_12 ( struct V_11 * V_12 , struct V_39 * V_14 )
{
struct V_40 * V_41 ;
int V_15 ;
if ( F_2 ( V_14 , 1 , 2 , 2 ) )
return;
V_41 = (struct V_40 * )
( ( unsigned long ) V_14 + V_14 -> V_42 ) ;
F_6 ( V_12 , L_22 , V_14 -> V_43 ) ;
F_6 ( V_12 , L_23 , V_14 -> V_44 ) ;
F_6 ( V_12 , L_24 , V_14 -> V_45 ) ;
F_6 ( V_12 , L_25 , V_14 -> V_46 ) ;
if ( V_14 -> V_47 ) {
F_6 ( V_12 , L_26 , V_14 -> V_48 ) ;
F_6 ( V_12 , L_27 , V_14 -> V_49 ) ;
}
F_6 ( V_12 , L_28 , V_14 -> V_50 ) ;
if ( V_14 -> V_51 == 1 )
F_6 ( V_12 , L_29 , V_41 -> V_52 ) ;
F_7 ( V_12 , '\n' ) ;
if ( V_14 -> V_53 )
F_6 ( V_12 , L_30 , V_14 -> V_53 ) ;
if ( V_14 -> V_54 )
F_6 ( V_12 , L_31 , V_14 -> V_54 ) ;
for ( V_15 = 2 ; V_15 <= V_14 -> V_43 ; V_15 ++ ) {
F_6 ( V_12 , L_32 ,
V_15 , V_14 -> V_55 [ V_15 - 2 ] ) ;
if ( V_14 -> V_51 == 1 )
F_6 ( V_12 , L_29 , V_41 -> V_56 [ V_15 - 2 ] ) ;
F_7 ( V_12 , '\n' ) ;
}
}
static void F_13 ( struct V_11 * V_12 , struct V_57 * V_14 )
{
if ( F_2 ( V_14 , 2 , 2 , 2 ) )
return;
F_4 ( V_14 -> V_9 , sizeof( V_14 -> V_9 ) ) ;
F_7 ( V_12 , '\n' ) ;
F_6 ( V_12 , L_33 , V_14 -> V_58 ) ;
F_6 ( V_12 , L_34 ) ;
if ( V_14 -> V_59 & V_60 )
F_6 ( V_12 , L_35 ) ;
if ( V_14 -> V_59 & V_61 )
F_6 ( V_12 , L_36 ) ;
if ( V_14 -> V_59 & V_62 )
F_6 ( V_12 , L_37 ) ;
F_7 ( V_12 , '\n' ) ;
F_6 ( V_12 , L_38 , V_14 -> V_9 ) ;
F_6 ( V_12 , L_39 , V_14 -> V_63 ) ;
F_6 ( V_12 , L_40 , V_14 -> V_43 ) ;
F_6 ( V_12 , L_41 , V_14 -> V_44 ) ;
F_6 ( V_12 , L_42 , V_14 -> V_45 ) ;
F_6 ( V_12 , L_43 , V_14 -> V_46 ) ;
F_6 ( V_12 , L_44 , V_14 -> V_64 ) ;
F_6 ( V_12 , L_45 , V_14 -> V_65 ) ;
if ( V_14 -> V_47 ) {
F_6 ( V_12 , L_46 , V_14 -> V_48 ) ;
F_6 ( V_12 , L_47 , V_14 -> V_49 ) ;
F_6 ( V_12 , L_48 , V_14 -> V_66 ) ;
}
if ( F_3 ( V_14 -> V_67 , V_14 -> V_68 , sizeof( V_14 -> V_68 ) ) ) {
F_6 ( V_12 , L_49 , V_14 -> V_68 ) ;
F_6 ( V_12 , L_50 , & V_14 -> V_69 ) ;
}
}
static void F_14 ( struct V_11 * V_12 , int V_5 ,
struct V_70 * V_14 )
{
T_3 V_10 = sizeof( V_14 -> V_71 [ V_5 ] ) ;
if ( ! F_3 ( V_14 -> V_72 [ V_5 ] . V_73 , V_14 -> V_71 [ V_5 ] , V_10 ) )
return;
F_6 ( V_12 , L_51 , V_5 ,
V_14 -> V_71 [ V_5 ] ) ;
}
static void F_15 ( struct V_11 * V_12 , int V_15 , struct V_70 * V_14 )
{
if ( ! memcmp ( & V_14 -> V_72 [ V_15 ] . V_69 , & V_74 , sizeof( V_75 ) ) )
return;
F_6 ( V_12 , L_52 , V_15 , & V_14 -> V_72 [ V_15 ] . V_69 ) ;
}
static void F_16 ( struct V_11 * V_12 , struct V_70 * V_14 )
{
int V_15 ;
if ( F_2 ( V_14 , 3 , 2 , 2 ) )
return;
for ( V_15 = 0 ; V_15 < V_14 -> V_76 ; V_15 ++ ) {
F_4 ( V_14 -> V_72 [ V_15 ] . V_9 , sizeof( V_14 -> V_72 [ V_15 ] . V_9 ) ) ;
F_4 ( V_14 -> V_72 [ V_15 ] . V_77 , sizeof( V_14 -> V_72 [ V_15 ] . V_77 ) ) ;
F_7 ( V_12 , '\n' ) ;
F_6 ( V_12 , L_53 , V_15 , V_14 -> V_72 [ V_15 ] . V_9 ) ;
F_6 ( V_12 , L_54 , V_15 , V_14 -> V_72 [ V_15 ] . V_77 ) ;
F_6 ( V_12 , L_55 , V_15 , V_14 -> V_72 [ V_15 ] . V_63 ) ;
F_6 ( V_12 , L_56 , V_15 , V_14 -> V_72 [ V_15 ] . V_43 ) ;
F_6 ( V_12 , L_57 , V_15 , V_14 -> V_72 [ V_15 ] . V_44 ) ;
F_6 ( V_12 , L_58 , V_15 , V_14 -> V_72 [ V_15 ] . V_45 ) ;
F_6 ( V_12 , L_59 , V_15 , V_14 -> V_72 [ V_15 ] . V_46 ) ;
F_14 ( V_12 , V_15 , V_14 ) ;
F_15 ( V_12 , V_15 , V_14 ) ;
}
}
static int F_17 ( struct V_11 * V_12 , void * V_78 )
{
void * V_14 = ( void * ) F_18 ( V_79 ) ;
int V_80 ;
if ( ! V_14 )
return 0 ;
V_80 = F_2 ( NULL , 0 , 0 , 0 ) ;
if ( V_80 >= 1 )
F_5 ( V_12 , V_14 ) ;
if ( V_80 >= 1 )
F_9 ( V_12 , V_14 ) ;
if ( V_80 >= 1 )
F_12 ( V_12 , V_14 ) ;
if ( V_80 >= 2 )
F_13 ( V_12 , V_14 ) ;
if ( V_80 >= 3 )
F_16 ( V_12 , V_14 ) ;
F_19 ( ( unsigned long ) V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_21 ( V_82 , F_17 , NULL ) ;
}
static int T_4 F_22 ( void )
{
F_23 ( L_60 , 0444 , NULL , & V_83 ) ;
return 0 ;
}
int F_24 ( struct V_84 * V_85 )
{
struct V_84 * V_86 ;
F_25 ( & V_87 ) ;
F_26 (ptr, &service_level_list, list)
if ( V_86 == V_85 ) {
F_27 ( & V_87 ) ;
return - V_88 ;
}
F_28 ( & V_85 -> V_89 , & V_90 ) ;
F_27 ( & V_87 ) ;
return 0 ;
}
int F_29 ( struct V_84 * V_85 )
{
struct V_84 * V_86 , * V_91 ;
int V_7 = - V_92 ;
F_25 ( & V_87 ) ;
F_30 (ptr, next, &service_level_list, list) {
if ( V_86 != V_85 )
continue;
F_31 ( & V_86 -> V_89 ) ;
V_7 = 0 ;
break;
}
F_27 ( & V_87 ) ;
return V_7 ;
}
static void * F_32 ( struct V_11 * V_12 , T_5 * V_93 )
{
F_33 ( & V_87 ) ;
return F_34 ( & V_90 , * V_93 ) ;
}
static void * F_35 ( struct V_11 * V_12 , void * V_32 , T_5 * V_93 )
{
return F_36 ( V_32 , & V_90 , V_93 ) ;
}
static void F_37 ( struct V_11 * V_12 , void * V_32 )
{
F_38 ( & V_87 ) ;
}
static int F_39 ( struct V_11 * V_12 , void * V_32 )
{
struct V_84 * V_85 ;
V_85 = F_40 ( V_32 , struct V_84 , V_89 ) ;
V_85 -> V_94 ( V_12 , V_85 ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_42 ( V_82 , & V_95 ) ;
}
static void F_43 ( struct V_11 * V_12 ,
struct V_84 * V_85 )
{
char * V_96 , * V_97 ;
V_96 = F_44 ( 1024 , V_79 | V_98 ) ;
if ( ! V_96 )
return;
F_45 ( L_61 , V_96 , 1024 , NULL ) ;
V_97 = strchr ( V_96 , '\n' ) ;
if ( V_97 )
* V_97 = 0 ;
F_6 ( V_12 , L_62 , V_96 ) ;
F_46 ( V_96 ) ;
}
static T_4 int F_47 ( void )
{
F_23 ( L_63 , 0 , NULL , & V_99 ) ;
if ( V_100 )
F_24 ( & V_101 ) ;
return 0 ;
}
void F_48 ( void )
{
struct V_39 * V_14 ;
unsigned long V_50 ;
struct V_102 V_103 ;
V_14 = ( void * ) F_18 ( V_79 ) ;
if ( ! V_14 )
return;
if ( F_2 ( V_14 , 1 , 2 , 2 ) == 0 ) {
F_49 ( & V_103 , V_104 ) ;
asm volatile(
" sfpc %3\n"
" l %0,%1\n"
" tmlh %0,0xff80\n"
" jnz 0f\n"
" cefbr %%f2,%0\n"
" j 1f\n"
"0: le %%f2,%1\n"
"1: cefbr %%f0,%2\n"
" debr %%f0,%%f2\n"
" cgebr %0,5,%%f0\n"
: "=&d" (capability)
: "Q" (info->capability), "d" (10000000), "d" (0)
: "cc"
);
F_50 ( & V_103 , V_104 ) ;
} else
V_50 = 42 ;
V_105 = V_50 * ( 500000 / V_106 ) ;
F_19 ( ( unsigned long ) V_14 ) ;
}
void F_51 ( void )
{
F_48 () ;
F_52 ( V_107 L_64
L_65 , V_105 / ( 500000 / V_106 ) ,
( V_105 / ( 5000 / V_106 ) ) % 100 ) ;
}
static int F_53 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
F_19 ( ( unsigned long ) V_82 -> V_108 ) ;
return 0 ;
}
static T_6 F_54 ( struct V_82 * V_82 , char T_7 * V_109 , T_3 V_110 , T_5 * V_111 )
{
return F_55 ( V_109 , V_110 , V_111 , V_82 -> V_108 , V_112 ) ;
}
static T_4 int F_56 ( void )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_5 , V_15 ;
V_114 = F_57 ( L_66 , V_117 ) ;
if ( F_58 ( V_114 ) )
return 0 ;
V_5 = F_2 ( NULL , 0 , 0 , 0 ) ;
if ( V_5 > 0 )
V_118 = V_5 ;
F_59 ( L_67 , 0400 , V_114 , & V_118 ) ;
for ( V_15 = 0 ; V_15 < F_8 ( V_115 ) ; V_15 ++ ) {
V_116 = & V_115 [ V_15 ] ;
F_60 ( V_116 -> V_9 , 0400 , V_114 , NULL , V_116 -> V_119 ) ;
}
if ( F_61 ( F_10 ) && V_35 ) {
char V_120 [ 10 ] ;
sprintf ( V_120 , L_68 , F_62 () ) ;
F_63 ( L_69 , V_114 , V_120 ) ;
}
return 0 ;
}
