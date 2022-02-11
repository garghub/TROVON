int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
register int T_1 V_5 ( L_1 ) = ( V_2 << 28 ) | V_3 ;
register int T_2 V_5 ( L_2 ) = V_4 ;
int V_6 = 0 ;
asm volatile(
" stsi 0(%3)\n"
"0: jz 2f\n"
"1: lhi %1,%4\n"
"2:\n"
EX_TABLE(0b, 1b)
: "+d" (r0), "+d" (rc)
: "d" (r1), "a" (sysinfo), "K" (-EOPNOTSUPP)
: "cc", "memory");
if ( V_6 )
return V_6 ;
return V_2 ? 0 : ( ( unsigned int ) T_1 ) >> 28 ;
}
static void F_2 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_11 ;
if ( F_1 ( V_10 , 1 , 1 , 1 ) )
return;
F_3 ( V_10 -> V_12 , sizeof( V_10 -> V_12 ) ) ;
F_3 ( V_10 -> type , sizeof( V_10 -> type ) ) ;
F_3 ( V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
F_3 ( V_10 -> V_14 , sizeof( V_10 -> V_14 ) ) ;
F_3 ( V_10 -> V_15 , sizeof( V_10 -> V_15 ) ) ;
F_3 ( V_10 -> V_16 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( V_10 -> V_17 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( V_10 -> V_18 , sizeof( V_10 -> V_18 ) ) ;
F_4 ( V_8 , L_3 , V_10 -> V_12 ) ;
F_4 ( V_8 , L_4 , V_10 -> type ) ;
F_4 ( V_8 , L_5 , V_10 -> V_16 ) ;
if ( V_10 -> V_13 [ 0 ] != '\0' )
F_4 ( V_8 , L_6 , V_10 -> V_13 ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_7 , V_10 -> V_14 ) ;
F_4 ( V_8 , L_8 , V_10 -> V_15 ) ;
F_4 ( V_8 , L_9 ,
V_10 -> V_16 , V_10 -> V_19 ) ;
if ( V_10 -> V_20 )
F_4 ( V_8 , L_10 ,
V_10 -> V_17 ,
V_10 -> V_20 ) ;
if ( V_10 -> V_21 )
F_4 ( V_8 , L_11 ,
V_10 -> V_18 ,
V_10 -> V_21 ) ;
if ( V_10 -> V_22 )
F_4 ( V_8 , L_12 , V_10 -> V_22 ) ;
if ( V_10 -> V_23 )
F_4 ( V_8 , L_13 , V_10 -> V_23 ) ;
if ( V_10 -> V_24 )
F_4 ( V_8 , L_14 , V_10 -> V_24 ) ;
if ( V_10 -> V_25 ) {
F_4 ( V_8 , L_15 , V_10 -> V_25 ) ;
F_4 ( V_8 , L_16 , V_10 -> V_26 ) ;
F_4 ( V_8 , L_17 , V_10 -> V_27 ) ;
}
if ( V_10 -> V_28 ) {
for ( V_11 = 1 ; V_11 <= F_6 ( V_10 -> V_29 ) ; V_11 ++ ) {
F_4 ( V_8 , L_18 ,
V_11 , V_10 -> V_29 [ V_11 - 1 ] ) ;
}
}
}
static void F_7 ( struct V_7 * V_8 , struct V_30 * V_10 )
{
int V_11 ;
F_5 ( V_8 , '\n' ) ;
if ( ! V_31 )
return;
if ( F_1 ( V_10 , 15 , 1 , V_32 ) )
return;
F_4 ( V_8 , L_19 ) ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ )
F_4 ( V_8 , L_20 , V_10 -> V_34 [ V_11 ] ) ;
F_5 ( V_8 , '\n' ) ;
#ifdef F_8
F_9 ( V_10 ) ;
F_4 ( V_8 , L_21 ) ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ )
F_4 ( V_8 , L_20 , V_10 -> V_34 [ V_11 ] ) ;
F_5 ( V_8 , '\n' ) ;
#endif
}
static void F_10 ( struct V_7 * V_8 , struct V_35 * V_10 )
{
struct V_36 * V_37 ;
int V_11 ;
if ( F_1 ( V_10 , 1 , 2 , 2 ) )
return;
V_37 = (struct V_36 * )
( ( unsigned long ) V_10 + V_10 -> V_38 ) ;
F_4 ( V_8 , L_22 , V_10 -> V_39 ) ;
F_4 ( V_8 , L_23 , V_10 -> V_40 ) ;
F_4 ( V_8 , L_24 , V_10 -> V_41 ) ;
F_4 ( V_8 , L_25 , V_10 -> V_42 ) ;
if ( V_10 -> V_43 ) {
F_4 ( V_8 , L_26 , V_10 -> V_44 ) ;
F_4 ( V_8 , L_27 , V_10 -> V_45 ) ;
}
F_4 ( V_8 , L_28 , V_10 -> V_46 ) ;
if ( V_10 -> V_47 == 1 )
F_4 ( V_8 , L_29 , V_37 -> V_48 ) ;
F_5 ( V_8 , '\n' ) ;
if ( V_10 -> V_49 )
F_4 ( V_8 , L_30 , V_10 -> V_49 ) ;
if ( V_10 -> V_50 )
F_4 ( V_8 , L_31 , V_10 -> V_50 ) ;
for ( V_11 = 2 ; V_11 <= V_10 -> V_39 ; V_11 ++ ) {
F_4 ( V_8 , L_32 ,
V_11 , V_10 -> V_51 [ V_11 - 2 ] ) ;
if ( V_10 -> V_47 == 1 )
F_4 ( V_8 , L_29 , V_37 -> V_52 [ V_11 - 2 ] ) ;
F_5 ( V_8 , '\n' ) ;
}
}
static void F_11 ( struct V_7 * V_8 , struct V_53 * V_10 )
{
if ( F_1 ( V_10 , 2 , 2 , 2 ) )
return;
F_3 ( V_10 -> V_54 , sizeof( V_10 -> V_54 ) ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_33 , V_10 -> V_55 ) ;
F_4 ( V_8 , L_34 ) ;
if ( V_10 -> V_56 & V_57 )
F_4 ( V_8 , L_35 ) ;
if ( V_10 -> V_56 & V_58 )
F_4 ( V_8 , L_36 ) ;
if ( V_10 -> V_56 & V_59 )
F_4 ( V_8 , L_37 ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_38 , V_10 -> V_54 ) ;
F_4 ( V_8 , L_39 , V_10 -> V_60 ) ;
F_4 ( V_8 , L_40 , V_10 -> V_39 ) ;
F_4 ( V_8 , L_41 , V_10 -> V_40 ) ;
F_4 ( V_8 , L_42 , V_10 -> V_41 ) ;
F_4 ( V_8 , L_43 , V_10 -> V_42 ) ;
F_4 ( V_8 , L_44 , V_10 -> V_61 ) ;
F_4 ( V_8 , L_45 , V_10 -> V_62 ) ;
if ( V_10 -> V_43 ) {
F_4 ( V_8 , L_46 , V_10 -> V_44 ) ;
F_4 ( V_8 , L_47 , V_10 -> V_45 ) ;
F_4 ( V_8 , L_48 , V_10 -> V_63 ) ;
}
}
static void F_12 ( struct V_7 * V_8 , int V_64 ,
struct V_65 * V_10 )
{
if ( V_10 -> V_66 [ V_64 ] . V_67 == 0 )
return;
if ( V_10 -> V_68 [ V_64 ] [ 0 ] == 0 )
return;
switch ( V_10 -> V_66 [ V_64 ] . V_67 ) {
case 1 :
F_3 ( V_10 -> V_68 [ V_64 ] , sizeof( V_10 -> V_68 [ V_64 ] ) ) ;
break;
case 2 :
break;
default:
return;
}
F_4 ( V_8 , L_49 , V_64 ,
V_10 -> V_68 [ V_64 ] ) ;
}
static void F_13 ( struct V_7 * V_8 , int V_11 , struct V_65 * V_10 )
{
if ( ! memcmp ( & V_10 -> V_66 [ V_11 ] . V_69 , & V_70 , sizeof( V_71 ) ) )
return;
F_4 ( V_8 , L_50 , V_11 , & V_10 -> V_66 [ V_11 ] . V_69 ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_65 * V_10 )
{
int V_11 ;
if ( F_1 ( V_10 , 3 , 2 , 2 ) )
return;
for ( V_11 = 0 ; V_11 < V_10 -> V_72 ; V_11 ++ ) {
F_3 ( V_10 -> V_66 [ V_11 ] . V_54 , sizeof( V_10 -> V_66 [ V_11 ] . V_54 ) ) ;
F_3 ( V_10 -> V_66 [ V_11 ] . V_73 , sizeof( V_10 -> V_66 [ V_11 ] . V_73 ) ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_51 , V_11 , V_10 -> V_66 [ V_11 ] . V_54 ) ;
F_4 ( V_8 , L_52 , V_11 , V_10 -> V_66 [ V_11 ] . V_73 ) ;
F_4 ( V_8 , L_53 , V_11 , V_10 -> V_66 [ V_11 ] . V_60 ) ;
F_4 ( V_8 , L_54 , V_11 , V_10 -> V_66 [ V_11 ] . V_39 ) ;
F_4 ( V_8 , L_55 , V_11 , V_10 -> V_66 [ V_11 ] . V_40 ) ;
F_4 ( V_8 , L_56 , V_11 , V_10 -> V_66 [ V_11 ] . V_41 ) ;
F_4 ( V_8 , L_57 , V_11 , V_10 -> V_66 [ V_11 ] . V_42 ) ;
F_12 ( V_8 , V_11 , V_10 ) ;
F_13 ( V_8 , V_11 , V_10 ) ;
}
}
static int F_15 ( struct V_7 * V_8 , void * V_74 )
{
void * V_10 = ( void * ) F_16 ( V_75 ) ;
int V_76 ;
if ( ! V_10 )
return 0 ;
V_76 = F_1 ( NULL , 0 , 0 , 0 ) ;
if ( V_76 >= 1 )
F_2 ( V_8 , V_10 ) ;
if ( V_76 >= 1 )
F_7 ( V_8 , V_10 ) ;
if ( V_76 >= 1 )
F_10 ( V_8 , V_10 ) ;
if ( V_76 >= 2 )
F_11 ( V_8 , V_10 ) ;
if ( V_76 >= 3 )
F_14 ( V_8 , V_10 ) ;
F_17 ( ( unsigned long ) V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_19 ( V_78 , F_15 , NULL ) ;
}
static int T_3 F_20 ( void )
{
F_21 ( L_58 , 0444 , NULL , & V_79 ) ;
return 0 ;
}
int F_22 ( struct V_80 * V_81 )
{
struct V_80 * V_82 ;
F_23 ( & V_83 ) ;
F_24 (ptr, &service_level_list, list)
if ( V_82 == V_81 ) {
F_25 ( & V_83 ) ;
return - V_84 ;
}
F_26 ( & V_81 -> V_85 , & V_86 ) ;
F_25 ( & V_83 ) ;
return 0 ;
}
int F_27 ( struct V_80 * V_81 )
{
struct V_80 * V_82 , * V_87 ;
int V_6 = - V_88 ;
F_23 ( & V_83 ) ;
F_28 (ptr, next, &service_level_list, list) {
if ( V_82 != V_81 )
continue;
F_29 ( & V_82 -> V_85 ) ;
V_6 = 0 ;
break;
}
F_25 ( & V_83 ) ;
return V_6 ;
}
static void * F_30 ( struct V_7 * V_8 , T_4 * V_89 )
{
F_31 ( & V_83 ) ;
return F_32 ( & V_86 , * V_89 ) ;
}
static void * F_33 ( struct V_7 * V_8 , void * V_28 , T_4 * V_89 )
{
return F_34 ( V_28 , & V_86 , V_89 ) ;
}
static void F_35 ( struct V_7 * V_8 , void * V_28 )
{
F_36 ( & V_83 ) ;
}
static int F_37 ( struct V_7 * V_8 , void * V_28 )
{
struct V_80 * V_81 ;
V_81 = F_38 ( V_28 , struct V_80 , V_85 ) ;
V_81 -> V_90 ( V_8 , V_81 ) ;
return 0 ;
}
static int F_39 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_40 ( V_78 , & V_91 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_80 * V_81 )
{
char * V_92 , * V_93 ;
V_92 = F_42 ( 1024 , V_75 | V_94 ) ;
if ( ! V_92 )
return;
F_43 ( L_59 , V_92 , 1024 , NULL ) ;
V_93 = strchr ( V_92 , '\n' ) ;
if ( V_93 )
* V_93 = 0 ;
F_4 ( V_8 , L_60 , V_92 ) ;
F_44 ( V_92 ) ;
}
static T_3 int F_45 ( void )
{
F_21 ( L_61 , 0 , NULL , & V_95 ) ;
if ( V_96 )
F_22 ( & V_97 ) ;
return 0 ;
}
void F_46 ( void )
{
struct V_35 * V_10 ;
const unsigned int V_98 = 0x4b189680 ;
F_47 ( V_99 ) ; F_47 ( V_100 ) ; F_47 ( V_101 ) ;
V_102 ;
unsigned int V_46 ;
V_10 = ( void * ) F_16 ( V_75 ) ;
if ( ! V_10 )
return;
if ( F_1 ( V_10 , 1 , 2 , 2 ) == 0 ) {
F_48 ( V_99 , & V_98 ) ;
if ( ( V_10 -> V_46 >> 23 ) == 0 )
F_49 ( V_100 , ( long ) V_10 -> V_46 , 64 , long ) ;
else
F_48 ( V_100 , & V_10 -> V_46 ) ;
F_50 ( V_101 , V_99 , V_100 ) ;
F_51 ( V_46 , V_101 , 32 , 0 ) ;
} else
V_46 = 42 ;
V_103 = V_46 * ( 500000 / V_104 ) ;
F_17 ( ( unsigned long ) V_10 ) ;
}
void F_52 ( void )
{
F_46 () ;
F_53 ( V_105 L_62
L_63 , V_103 / ( 500000 / V_104 ) ,
( V_103 / ( 5000 / V_104 ) ) % 100 ) ;
}
