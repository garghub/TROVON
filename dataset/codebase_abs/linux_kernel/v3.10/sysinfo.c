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
static int V_31 ;
int V_11 , V_6 ;
F_5 ( V_8 , '\n' ) ;
if ( ! V_32 )
return;
if ( F_1 ( V_10 , 15 , 1 , V_33 ) )
return;
F_4 ( V_8 , L_19 ) ;
for ( V_11 = 0 ; V_11 < V_34 ; V_11 ++ )
F_4 ( V_8 , L_20 , V_10 -> V_35 [ V_11 ] ) ;
F_5 ( V_8 , '\n' ) ;
#ifdef F_8
F_9 ( V_10 ) ;
F_4 ( V_8 , L_21 ) ;
for ( V_11 = 0 ; V_11 < V_34 ; V_11 ++ )
F_4 ( V_8 , L_20 , V_10 -> V_35 [ V_11 ] ) ;
F_5 ( V_8 , '\n' ) ;
#endif
}
static void F_10 ( struct V_7 * V_8 , struct V_36 * V_10 )
{
struct V_37 * V_38 ;
int V_11 ;
if ( F_1 ( V_10 , 1 , 2 , 2 ) )
return;
V_38 = (struct V_37 * )
( ( unsigned long ) V_10 + V_10 -> V_39 ) ;
F_4 ( V_8 , L_22 , V_10 -> V_40 ) ;
F_4 ( V_8 , L_23 , V_10 -> V_41 ) ;
F_4 ( V_8 , L_24 , V_10 -> V_42 ) ;
F_4 ( V_8 , L_25 , V_10 -> V_43 ) ;
F_4 ( V_8 , L_26 , V_10 -> V_44 ) ;
if ( V_10 -> V_45 == 1 )
F_4 ( V_8 , L_27 , V_38 -> V_46 ) ;
F_5 ( V_8 , '\n' ) ;
if ( V_10 -> V_47 )
F_4 ( V_8 , L_28 , V_10 -> V_47 ) ;
if ( V_10 -> V_48 )
F_4 ( V_8 , L_29 , V_10 -> V_48 ) ;
for ( V_11 = 2 ; V_11 <= V_10 -> V_40 ; V_11 ++ ) {
F_4 ( V_8 , L_30 ,
V_11 , V_10 -> V_49 [ V_11 - 2 ] ) ;
if ( V_10 -> V_45 == 1 )
F_4 ( V_8 , L_27 , V_38 -> V_50 [ V_11 - 2 ] ) ;
F_5 ( V_8 , '\n' ) ;
}
}
static void F_11 ( struct V_7 * V_8 , struct V_51 * V_10 )
{
if ( F_1 ( V_10 , 2 , 2 , 2 ) )
return;
F_3 ( V_10 -> V_52 , sizeof( V_10 -> V_52 ) ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_31 , V_10 -> V_53 ) ;
F_4 ( V_8 , L_32 ) ;
if ( V_10 -> V_54 & V_55 )
F_4 ( V_8 , L_33 ) ;
if ( V_10 -> V_54 & V_56 )
F_4 ( V_8 , L_34 ) ;
if ( V_10 -> V_54 & V_57 )
F_4 ( V_8 , L_35 ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_36 , V_10 -> V_52 ) ;
F_4 ( V_8 , L_37 , V_10 -> V_58 ) ;
F_4 ( V_8 , L_38 , V_10 -> V_40 ) ;
F_4 ( V_8 , L_39 , V_10 -> V_41 ) ;
F_4 ( V_8 , L_40 , V_10 -> V_42 ) ;
F_4 ( V_8 , L_41 , V_10 -> V_43 ) ;
F_4 ( V_8 , L_42 , V_10 -> V_59 ) ;
F_4 ( V_8 , L_43 , V_10 -> V_60 ) ;
}
static void F_12 ( struct V_7 * V_8 , struct V_61 * V_10 )
{
int V_11 ;
if ( F_1 ( V_10 , 3 , 2 , 2 ) )
return;
for ( V_11 = 0 ; V_11 < V_10 -> V_62 ; V_11 ++ ) {
F_3 ( V_10 -> V_63 [ V_11 ] . V_52 , sizeof( V_10 -> V_63 [ V_11 ] . V_52 ) ) ;
F_3 ( V_10 -> V_63 [ V_11 ] . V_64 , sizeof( V_10 -> V_63 [ V_11 ] . V_64 ) ) ;
F_5 ( V_8 , '\n' ) ;
F_4 ( V_8 , L_44 , V_11 , V_10 -> V_63 [ V_11 ] . V_52 ) ;
F_4 ( V_8 , L_45 , V_11 , V_10 -> V_63 [ V_11 ] . V_64 ) ;
F_4 ( V_8 , L_46 , V_11 , V_10 -> V_63 [ V_11 ] . V_58 ) ;
F_4 ( V_8 , L_47 , V_11 , V_10 -> V_63 [ V_11 ] . V_40 ) ;
F_4 ( V_8 , L_48 , V_11 , V_10 -> V_63 [ V_11 ] . V_41 ) ;
F_4 ( V_8 , L_49 , V_11 , V_10 -> V_63 [ V_11 ] . V_42 ) ;
F_4 ( V_8 , L_50 , V_11 , V_10 -> V_63 [ V_11 ] . V_43 ) ;
}
}
static int F_13 ( struct V_7 * V_8 , void * V_65 )
{
void * V_10 = ( void * ) F_14 ( V_66 ) ;
int V_67 ;
if ( ! V_10 )
return 0 ;
V_67 = F_1 ( NULL , 0 , 0 , 0 ) ;
if ( V_67 >= 1 )
F_2 ( V_8 , V_10 ) ;
if ( V_67 >= 1 )
F_7 ( V_8 , V_10 ) ;
if ( V_67 >= 1 )
F_10 ( V_8 , V_10 ) ;
if ( V_67 >= 2 )
F_11 ( V_8 , V_10 ) ;
if ( V_67 >= 3 )
F_12 ( V_8 , V_10 ) ;
F_15 ( ( unsigned long ) V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_17 ( V_69 , F_13 , NULL ) ;
}
static int T_3 F_18 ( void )
{
F_19 ( L_51 , 0444 , NULL , & V_70 ) ;
return 0 ;
}
int F_20 ( struct V_71 * V_72 )
{
struct V_71 * V_73 ;
F_21 ( & V_74 ) ;
F_22 (ptr, &service_level_list, list)
if ( V_73 == V_72 ) {
F_23 ( & V_74 ) ;
return - V_75 ;
}
F_24 ( & V_72 -> V_76 , & V_77 ) ;
F_23 ( & V_74 ) ;
return 0 ;
}
int F_25 ( struct V_71 * V_72 )
{
struct V_71 * V_73 , * V_78 ;
int V_6 = - V_79 ;
F_21 ( & V_74 ) ;
F_26 (ptr, next, &service_level_list, list) {
if ( V_73 != V_72 )
continue;
F_27 ( & V_73 -> V_76 ) ;
V_6 = 0 ;
break;
}
F_23 ( & V_74 ) ;
return V_6 ;
}
static void * F_28 ( struct V_7 * V_8 , T_4 * V_80 )
{
F_29 ( & V_74 ) ;
return F_30 ( & V_77 , * V_80 ) ;
}
static void * F_31 ( struct V_7 * V_8 , void * V_28 , T_4 * V_80 )
{
return F_32 ( V_28 , & V_77 , V_80 ) ;
}
static void F_33 ( struct V_7 * V_8 , void * V_28 )
{
F_34 ( & V_74 ) ;
}
static int F_35 ( struct V_7 * V_8 , void * V_28 )
{
struct V_71 * V_72 ;
V_72 = F_36 ( V_28 , struct V_71 , V_76 ) ;
V_72 -> V_81 ( V_8 , V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_38 ( V_69 , & V_82 ) ;
}
static void F_39 ( struct V_7 * V_8 ,
struct V_71 * V_72 )
{
char * V_83 , * V_84 ;
V_83 = F_40 ( 1024 , V_66 | V_85 ) ;
if ( ! V_83 )
return;
F_41 ( L_52 , V_83 , 1024 , NULL ) ;
V_84 = strchr ( V_83 , '\n' ) ;
if ( V_84 )
* V_84 = 0 ;
F_4 ( V_8 , L_53 , V_83 ) ;
F_42 ( V_83 ) ;
}
static T_3 int F_43 ( void )
{
F_19 ( L_54 , 0 , NULL , & V_86 ) ;
if ( V_87 )
F_20 ( & V_88 ) ;
return 0 ;
}
void F_44 ( void )
{
struct V_36 * V_10 ;
const unsigned int V_89 = 0x4b189680 ;
F_45 ( V_90 ) ; F_45 ( V_91 ) ; F_45 ( V_92 ) ;
V_93 ;
unsigned int V_44 ;
V_10 = ( void * ) F_14 ( V_66 ) ;
if ( ! V_10 )
return;
if ( F_1 ( V_10 , 1 , 2 , 2 ) == 0 ) {
F_46 ( V_90 , & V_89 ) ;
if ( ( V_10 -> V_44 >> 23 ) == 0 )
F_47 ( V_91 , ( long ) V_10 -> V_44 , 64 , long ) ;
else
F_46 ( V_91 , & V_10 -> V_44 ) ;
F_48 ( V_92 , V_90 , V_91 ) ;
F_49 ( V_44 , V_92 , 32 , 0 ) ;
} else
V_44 = 42 ;
V_94 = V_44 * ( 500000 / V_95 ) ;
F_15 ( ( unsigned long ) V_10 ) ;
}
void T_5 F_50 ( void )
{
F_44 () ;
F_51 ( V_96 L_55
L_56 , V_94 / ( 500000 / V_95 ) ,
( V_94 / ( 5000 / V_95 ) ) % 100 ) ;
}
