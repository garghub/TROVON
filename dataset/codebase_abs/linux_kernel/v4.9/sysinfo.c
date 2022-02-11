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
static void F_3 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
int V_12 ;
if ( F_2 ( V_11 , 1 , 1 , 1 ) )
return;
F_4 ( V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ;
F_4 ( V_11 -> type , sizeof( V_11 -> type ) ) ;
F_4 ( V_11 -> V_14 , sizeof( V_11 -> V_14 ) ) ;
F_4 ( V_11 -> V_15 , sizeof( V_11 -> V_15 ) ) ;
F_4 ( V_11 -> V_16 , sizeof( V_11 -> V_16 ) ) ;
F_4 ( V_11 -> V_17 , sizeof( V_11 -> V_17 ) ) ;
F_4 ( V_11 -> V_18 , sizeof( V_11 -> V_18 ) ) ;
F_4 ( V_11 -> V_19 , sizeof( V_11 -> V_19 ) ) ;
F_5 ( V_9 , L_3 , V_11 -> V_13 ) ;
F_5 ( V_9 , L_4 , V_11 -> type ) ;
F_5 ( V_9 , L_5 , V_11 -> V_17 ) ;
if ( V_11 -> V_14 [ 0 ] != '\0' )
F_5 ( V_9 , L_6 , V_11 -> V_14 ) ;
F_6 ( V_9 , '\n' ) ;
F_5 ( V_9 , L_7 , V_11 -> V_15 ) ;
F_5 ( V_9 , L_8 , V_11 -> V_16 ) ;
F_5 ( V_9 , L_9 ,
V_11 -> V_17 , V_11 -> V_20 ) ;
if ( V_11 -> V_21 )
F_5 ( V_9 , L_10 ,
V_11 -> V_18 ,
V_11 -> V_21 ) ;
if ( V_11 -> V_22 )
F_5 ( V_9 , L_11 ,
V_11 -> V_19 ,
V_11 -> V_22 ) ;
if ( V_11 -> V_23 )
F_5 ( V_9 , L_12 , V_11 -> V_23 ) ;
if ( V_11 -> V_24 )
F_5 ( V_9 , L_13 , V_11 -> V_24 ) ;
if ( V_11 -> V_25 )
F_5 ( V_9 , L_14 , V_11 -> V_25 ) ;
if ( V_11 -> V_26 ) {
F_5 ( V_9 , L_15 , V_11 -> V_26 ) ;
F_5 ( V_9 , L_16 , V_11 -> V_27 ) ;
F_5 ( V_9 , L_17 , V_11 -> V_28 ) ;
}
if ( V_11 -> V_29 ) {
for ( V_12 = 1 ; V_12 <= F_7 ( V_11 -> V_30 ) ; V_12 ++ ) {
F_5 ( V_9 , L_18 ,
V_12 , V_11 -> V_30 [ V_12 - 1 ] ) ;
}
}
}
static void F_8 ( struct V_8 * V_9 , struct V_31 * V_11 )
{
int V_12 ;
F_6 ( V_9 , '\n' ) ;
if ( ! V_32 )
return;
if ( F_2 ( V_11 , 15 , 1 , V_33 ) )
return;
F_5 ( V_9 , L_19 ) ;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
F_5 ( V_9 , L_20 , V_11 -> V_35 [ V_12 ] ) ;
F_6 ( V_9 , '\n' ) ;
#ifdef F_9
F_10 ( V_11 ) ;
F_5 ( V_9 , L_21 ) ;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
F_5 ( V_9 , L_20 , V_11 -> V_35 [ V_12 ] ) ;
F_6 ( V_9 , '\n' ) ;
#endif
}
static void F_11 ( struct V_8 * V_9 , struct V_36 * V_11 )
{
struct V_37 * V_38 ;
int V_12 ;
if ( F_2 ( V_11 , 1 , 2 , 2 ) )
return;
V_38 = (struct V_37 * )
( ( unsigned long ) V_11 + V_11 -> V_39 ) ;
F_5 ( V_9 , L_22 , V_11 -> V_40 ) ;
F_5 ( V_9 , L_23 , V_11 -> V_41 ) ;
F_5 ( V_9 , L_24 , V_11 -> V_42 ) ;
F_5 ( V_9 , L_25 , V_11 -> V_43 ) ;
if ( V_11 -> V_44 ) {
F_5 ( V_9 , L_26 , V_11 -> V_45 ) ;
F_5 ( V_9 , L_27 , V_11 -> V_46 ) ;
}
F_5 ( V_9 , L_28 , V_11 -> V_47 ) ;
if ( V_11 -> V_48 == 1 )
F_5 ( V_9 , L_29 , V_38 -> V_49 ) ;
F_6 ( V_9 , '\n' ) ;
if ( V_11 -> V_50 )
F_5 ( V_9 , L_30 , V_11 -> V_50 ) ;
if ( V_11 -> V_51 )
F_5 ( V_9 , L_31 , V_11 -> V_51 ) ;
for ( V_12 = 2 ; V_12 <= V_11 -> V_40 ; V_12 ++ ) {
F_5 ( V_9 , L_32 ,
V_12 , V_11 -> V_52 [ V_12 - 2 ] ) ;
if ( V_11 -> V_48 == 1 )
F_5 ( V_9 , L_29 , V_38 -> V_53 [ V_12 - 2 ] ) ;
F_6 ( V_9 , '\n' ) ;
}
}
static void F_12 ( struct V_8 * V_9 , struct V_54 * V_11 )
{
if ( F_2 ( V_11 , 2 , 2 , 2 ) )
return;
F_4 ( V_11 -> V_55 , sizeof( V_11 -> V_55 ) ) ;
F_6 ( V_9 , '\n' ) ;
F_5 ( V_9 , L_33 , V_11 -> V_56 ) ;
F_5 ( V_9 , L_34 ) ;
if ( V_11 -> V_57 & V_58 )
F_5 ( V_9 , L_35 ) ;
if ( V_11 -> V_57 & V_59 )
F_5 ( V_9 , L_36 ) ;
if ( V_11 -> V_57 & V_60 )
F_5 ( V_9 , L_37 ) ;
F_6 ( V_9 , '\n' ) ;
F_5 ( V_9 , L_38 , V_11 -> V_55 ) ;
F_5 ( V_9 , L_39 , V_11 -> V_61 ) ;
F_5 ( V_9 , L_40 , V_11 -> V_40 ) ;
F_5 ( V_9 , L_41 , V_11 -> V_41 ) ;
F_5 ( V_9 , L_42 , V_11 -> V_42 ) ;
F_5 ( V_9 , L_43 , V_11 -> V_43 ) ;
F_5 ( V_9 , L_44 , V_11 -> V_62 ) ;
F_5 ( V_9 , L_45 , V_11 -> V_63 ) ;
if ( V_11 -> V_44 ) {
F_5 ( V_9 , L_46 , V_11 -> V_45 ) ;
F_5 ( V_9 , L_47 , V_11 -> V_46 ) ;
F_5 ( V_9 , L_48 , V_11 -> V_64 ) ;
}
}
static void F_13 ( struct V_8 * V_9 , int V_5 ,
struct V_65 * V_11 )
{
if ( V_11 -> V_66 [ V_5 ] . V_67 == 0 )
return;
if ( V_11 -> V_68 [ V_5 ] [ 0 ] == 0 )
return;
switch ( V_11 -> V_66 [ V_5 ] . V_67 ) {
case 1 :
F_4 ( V_11 -> V_68 [ V_5 ] , sizeof( V_11 -> V_68 [ V_5 ] ) ) ;
break;
case 2 :
break;
default:
return;
}
F_5 ( V_9 , L_49 , V_5 ,
V_11 -> V_68 [ V_5 ] ) ;
}
static void F_14 ( struct V_8 * V_9 , int V_12 , struct V_65 * V_11 )
{
if ( ! memcmp ( & V_11 -> V_66 [ V_12 ] . V_69 , & V_70 , sizeof( V_71 ) ) )
return;
F_5 ( V_9 , L_50 , V_12 , & V_11 -> V_66 [ V_12 ] . V_69 ) ;
}
static void F_15 ( struct V_8 * V_9 , struct V_65 * V_11 )
{
int V_12 ;
if ( F_2 ( V_11 , 3 , 2 , 2 ) )
return;
for ( V_12 = 0 ; V_12 < V_11 -> V_72 ; V_12 ++ ) {
F_4 ( V_11 -> V_66 [ V_12 ] . V_55 , sizeof( V_11 -> V_66 [ V_12 ] . V_55 ) ) ;
F_4 ( V_11 -> V_66 [ V_12 ] . V_73 , sizeof( V_11 -> V_66 [ V_12 ] . V_73 ) ) ;
F_6 ( V_9 , '\n' ) ;
F_5 ( V_9 , L_51 , V_12 , V_11 -> V_66 [ V_12 ] . V_55 ) ;
F_5 ( V_9 , L_52 , V_12 , V_11 -> V_66 [ V_12 ] . V_73 ) ;
F_5 ( V_9 , L_53 , V_12 , V_11 -> V_66 [ V_12 ] . V_61 ) ;
F_5 ( V_9 , L_54 , V_12 , V_11 -> V_66 [ V_12 ] . V_40 ) ;
F_5 ( V_9 , L_55 , V_12 , V_11 -> V_66 [ V_12 ] . V_41 ) ;
F_5 ( V_9 , L_56 , V_12 , V_11 -> V_66 [ V_12 ] . V_42 ) ;
F_5 ( V_9 , L_57 , V_12 , V_11 -> V_66 [ V_12 ] . V_43 ) ;
F_13 ( V_9 , V_12 , V_11 ) ;
F_14 ( V_9 , V_12 , V_11 ) ;
}
}
static int F_16 ( struct V_8 * V_9 , void * V_74 )
{
void * V_11 = ( void * ) F_17 ( V_75 ) ;
int V_76 ;
if ( ! V_11 )
return 0 ;
V_76 = F_2 ( NULL , 0 , 0 , 0 ) ;
if ( V_76 >= 1 )
F_3 ( V_9 , V_11 ) ;
if ( V_76 >= 1 )
F_8 ( V_9 , V_11 ) ;
if ( V_76 >= 1 )
F_11 ( V_9 , V_11 ) ;
if ( V_76 >= 2 )
F_12 ( V_9 , V_11 ) ;
if ( V_76 >= 3 )
F_15 ( V_9 , V_11 ) ;
F_18 ( ( unsigned long ) V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_20 ( V_78 , F_16 , NULL ) ;
}
static int T_3 F_21 ( void )
{
F_22 ( L_58 , 0444 , NULL , & V_79 ) ;
return 0 ;
}
int F_23 ( struct V_80 * V_81 )
{
struct V_80 * V_82 ;
F_24 ( & V_83 ) ;
F_25 (ptr, &service_level_list, list)
if ( V_82 == V_81 ) {
F_26 ( & V_83 ) ;
return - V_84 ;
}
F_27 ( & V_81 -> V_85 , & V_86 ) ;
F_26 ( & V_83 ) ;
return 0 ;
}
int F_28 ( struct V_80 * V_81 )
{
struct V_80 * V_82 , * V_87 ;
int V_7 = - V_88 ;
F_24 ( & V_83 ) ;
F_29 (ptr, next, &service_level_list, list) {
if ( V_82 != V_81 )
continue;
F_30 ( & V_82 -> V_85 ) ;
V_7 = 0 ;
break;
}
F_26 ( & V_83 ) ;
return V_7 ;
}
static void * F_31 ( struct V_8 * V_9 , T_4 * V_89 )
{
F_32 ( & V_83 ) ;
return F_33 ( & V_86 , * V_89 ) ;
}
static void * F_34 ( struct V_8 * V_9 , void * V_29 , T_4 * V_89 )
{
return F_35 ( V_29 , & V_86 , V_89 ) ;
}
static void F_36 ( struct V_8 * V_9 , void * V_29 )
{
F_37 ( & V_83 ) ;
}
static int F_38 ( struct V_8 * V_9 , void * V_29 )
{
struct V_80 * V_81 ;
V_81 = F_39 ( V_29 , struct V_80 , V_85 ) ;
V_81 -> V_90 ( V_9 , V_81 ) ;
return 0 ;
}
static int F_40 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_41 ( V_78 , & V_91 ) ;
}
static void F_42 ( struct V_8 * V_9 ,
struct V_80 * V_81 )
{
char * V_92 , * V_93 ;
V_92 = F_43 ( 1024 , V_75 | V_94 ) ;
if ( ! V_92 )
return;
F_44 ( L_59 , V_92 , 1024 , NULL ) ;
V_93 = strchr ( V_92 , '\n' ) ;
if ( V_93 )
* V_93 = 0 ;
F_5 ( V_9 , L_60 , V_92 ) ;
F_45 ( V_92 ) ;
}
static T_3 int F_46 ( void )
{
F_22 ( L_61 , 0 , NULL , & V_95 ) ;
if ( V_96 )
F_23 ( & V_97 ) ;
return 0 ;
}
void F_47 ( void )
{
struct V_36 * V_11 ;
unsigned long V_47 ;
struct V_98 V_99 ;
V_11 = ( void * ) F_17 ( V_75 ) ;
if ( ! V_11 )
return;
if ( F_2 ( V_11 , 1 , 2 , 2 ) == 0 ) {
F_48 ( & V_99 , V_100 ) ;
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
F_49 ( & V_99 , V_100 ) ;
} else
V_47 = 42 ;
V_101 = V_47 * ( 500000 / V_102 ) ;
F_18 ( ( unsigned long ) V_11 ) ;
}
void F_50 ( void )
{
F_47 () ;
F_51 ( V_103 L_62
L_63 , V_101 / ( 500000 / V_102 ) ,
( V_101 / ( 5000 / V_102 ) ) % 100 ) ;
}
