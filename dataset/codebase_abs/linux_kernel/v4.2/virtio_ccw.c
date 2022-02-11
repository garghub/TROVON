static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
unsigned long V_8 , V_9 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_7 -> V_11 ) ; V_8 ++ ) {
if ( V_5 == ( void * ) F_6 ( V_7 -> V_11 , V_8 ) ) {
F_7 ( V_7 -> V_11 , V_8 ) ;
F_8 ( V_7 -> V_11 , V_8 , 0 ) ;
break;
}
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_13 , struct V_6 , V_13 ) ;
unsigned long V_14 ;
F_11 ( V_15 ) ;
F_12 ( & V_7 -> V_10 ) ;
for ( V_14 = 0 ; ; ) {
V_14 = F_13 ( V_7 -> V_11 , V_14 , F_5 ( V_7 -> V_11 ) ) ;
if ( V_14 == - 1UL )
break;
F_14 ( 0 , ( void * ) F_6 ( V_7 -> V_11 , V_14 ) ) ;
}
V_7 -> V_16 = 0 ;
F_15 () ;
for ( V_14 = 0 ; ; ) {
V_14 = F_13 ( V_7 -> V_11 , V_14 , F_5 ( V_7 -> V_11 ) ) ;
if ( V_14 == - 1UL )
break;
F_14 ( 0 , ( void * ) F_6 ( V_7 -> V_11 , V_14 ) ) ;
}
F_16 ( & V_7 -> V_10 ) ;
}
static struct V_6 * F_17 ( void )
{
struct V_6 * V_7 ;
int V_17 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return NULL ;
F_19 ( & V_7 -> V_10 ) ;
V_7 -> V_11 = F_20 ( V_19 , V_20 | V_21 ) ;
if ( ! V_7 -> V_11 ) {
F_21 ( V_7 ) ;
return NULL ;
}
V_7 -> V_13 . V_22 = F_10 ;
V_7 -> V_13 . V_23 = & V_7 -> V_16 ;
V_7 -> V_13 . V_24 = 0xff ;
V_7 -> V_13 . V_25 = V_26 ;
V_17 = F_22 ( & V_7 -> V_13 ) ;
if ( V_17 ) {
F_23 ( V_7 -> V_11 ) ;
F_21 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static void F_24 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_25 ( & V_7 -> V_13 ) ;
F_23 ( V_7 -> V_11 ) ;
F_21 ( V_7 ) ;
}
static unsigned long F_26 ( struct V_4 * V_27 [] , int V_28 ,
T_1 * V_29 , void * * V_6 )
{
int V_8 , V_30 ;
struct V_6 * V_7 ;
unsigned long V_31 = 0 ;
unsigned long V_32 , V_9 ;
for ( V_8 = 0 ; V_8 < V_33 && ! V_31 ; V_8 ++ ) {
if ( ! V_34 [ V_8 ] )
V_34 [ V_8 ] = F_17 () ;
V_7 = V_34 [ V_8 ] ;
if ( ! V_7 )
return 0 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
V_32 = F_27 ( V_7 -> V_11 , V_28 ) ;
if ( V_32 == - 1UL ) {
F_9 ( & V_7 -> V_10 , V_9 ) ;
continue;
}
* V_29 = V_32 ;
* V_6 = V_7 ;
V_31 = ( unsigned long ) V_7 -> V_11 -> V_35 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
F_8 ( V_7 -> V_11 , V_32 + V_30 ,
( unsigned long ) V_27 [ V_30 ] ) ;
}
F_9 ( & V_7 -> V_10 , V_9 ) ;
}
return V_31 ;
}
static void F_28 ( struct V_1 * V_36 )
{
struct V_37 * V_7 ;
F_29 (info, &vcdev->virtqueues, node)
F_3 ( V_7 -> V_5 , V_36 -> V_6 ) ;
}
static int F_30 ( struct V_1 * V_36 , T_2 V_38 )
{
unsigned long V_9 ;
T_2 V_39 ;
F_31 ( F_32 ( V_36 -> V_40 ) , V_9 ) ;
if ( V_36 -> V_41 )
V_39 = 0 ;
else
V_39 = V_36 -> V_42 & V_38 ;
F_33 ( F_32 ( V_36 -> V_40 ) , V_9 ) ;
return V_39 ;
}
static int F_34 ( struct V_1 * V_36 ,
struct V_43 * V_44 , T_2 V_45 )
{
int V_39 ;
unsigned long V_9 ;
int V_38 = V_45 & V_46 ;
do {
F_31 ( F_32 ( V_36 -> V_40 ) , V_9 ) ;
V_39 = F_35 ( V_36 -> V_40 , V_44 , V_45 , 0 , 0 ) ;
if ( ! V_39 ) {
if ( ! V_36 -> V_42 )
V_36 -> V_41 = 0 ;
V_36 -> V_42 |= V_38 ;
}
F_33 ( F_32 ( V_36 -> V_40 ) , V_9 ) ;
F_36 () ;
} while ( V_39 == - V_47 );
F_37 ( V_36 -> V_48 , F_30 ( V_36 , V_38 ) == 0 ) ;
return V_39 ? V_39 : V_36 -> V_41 ;
}
static void F_38 ( struct V_1 * V_36 ,
struct V_43 * V_44 )
{
int V_39 ;
unsigned long * V_49 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_6 * V_6 = V_36 -> V_6 ;
if ( V_36 -> V_52 ) {
V_51 = F_18 ( sizeof( * V_51 ) ,
V_53 | V_18 ) ;
if ( ! V_51 )
return;
V_51 -> V_16 =
( unsigned long ) & V_6 -> V_16 ;
V_51 -> V_25 = V_26 ;
V_44 -> V_54 = V_55 ;
V_44 -> V_56 = sizeof( * V_51 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_51 ;
} else {
V_49 = F_39 ( sizeof( & V_36 -> V_58 ) ,
V_53 | V_18 ) ;
if ( ! V_49 )
return;
* V_49 = 0 ;
V_44 -> V_54 = V_59 ;
V_44 -> V_56 = sizeof( V_36 -> V_58 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
}
V_36 -> V_58 = 0 ;
V_44 -> V_9 = 0 ;
V_39 = F_34 ( V_36 , V_44 ,
V_36 -> V_52 ?
V_60 :
V_61 ) ;
if ( V_39 && ( V_39 != - V_62 ) )
F_40 ( & V_36 -> V_40 -> V_63 ,
L_1 , V_39 ) ;
else if ( V_36 -> V_52 )
F_28 ( V_36 ) ;
F_21 ( V_49 ) ;
F_21 ( V_51 ) ;
}
static inline long F_41 ( struct V_64 V_65 ,
unsigned long V_66 ,
long V_67 )
{
register unsigned long T_3 V_68 ( L_2 ) = V_69 ;
register struct V_64 T_4 V_68 ( L_3 ) = V_65 ;
register unsigned long T_5 V_68 ( L_4 ) = V_66 ;
register long T_6 V_68 ( L_3 ) ;
register long T_7 V_68 ( L_5 ) = V_67 ;
asm volatile ("diag 2,4,0x500\n"
: "=d" (__rc) : "d" (__nr), "d" (__schid), "d" (__index),
"d"(__cookie)
: "memory", "cc");
return T_6 ;
}
static bool F_42 ( struct V_4 * V_5 )
{
struct V_37 * V_7 = V_5 -> V_70 ;
struct V_1 * V_36 ;
struct V_64 V_65 ;
V_36 = F_1 ( V_7 -> V_5 -> V_3 ) ;
F_43 ( V_36 -> V_40 , & V_65 ) ;
V_7 -> V_67 = F_41 ( V_65 , V_5 -> V_71 , V_7 -> V_67 ) ;
if ( V_7 -> V_67 < 0 )
return false ;
return true ;
}
static int F_44 ( struct V_1 * V_36 ,
struct V_43 * V_44 , int V_71 )
{
V_36 -> V_72 -> V_71 = V_71 ;
V_44 -> V_54 = V_73 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( struct V_74 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_36 -> V_72 ) ;
F_34 ( V_36 , V_44 , V_75 ) ;
return V_36 -> V_72 -> V_76 ;
}
static void F_45 ( struct V_4 * V_5 , struct V_43 * V_44 )
{
struct V_1 * V_36 = F_1 ( V_5 -> V_3 ) ;
struct V_37 * V_7 = V_5 -> V_70 ;
unsigned long V_9 ;
unsigned long V_77 ;
int V_39 ;
unsigned int V_71 = V_5 -> V_71 ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_46 ( & V_7 -> V_78 ) ;
F_33 ( & V_36 -> V_10 , V_9 ) ;
if ( V_36 -> V_79 == 0 ) {
V_7 -> V_80 -> V_81 . V_82 = 0 ;
V_7 -> V_80 -> V_81 . V_83 = 0 ;
V_7 -> V_80 -> V_81 . V_71 = V_71 ;
V_7 -> V_80 -> V_81 . V_76 = 0 ;
V_44 -> V_56 = sizeof( V_7 -> V_80 -> V_81 ) ;
} else {
V_7 -> V_80 -> V_84 . V_85 = 0 ;
V_7 -> V_80 -> V_84 . V_71 = V_71 ;
V_7 -> V_80 -> V_84 . V_76 = 0 ;
V_7 -> V_80 -> V_84 . V_86 = 0 ;
V_7 -> V_80 -> V_84 . V_87 = 0 ;
V_44 -> V_56 = sizeof( V_7 -> V_80 -> V_84 ) ;
}
V_44 -> V_54 = V_88 ;
V_44 -> V_9 = 0 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_7 -> V_80 ) ;
V_39 = F_34 ( V_36 , V_44 ,
V_89 | V_71 ) ;
if ( V_39 && ( V_39 != - V_62 ) )
F_47 ( & V_5 -> V_3 -> V_63 , L_6 ,
V_39 , V_71 ) ;
F_48 ( V_5 ) ;
V_77 = F_49 ( F_50 ( V_7 -> V_76 , V_90 ) ) ;
F_51 ( V_7 -> V_82 , V_77 ) ;
F_21 ( V_7 -> V_80 ) ;
F_21 ( V_7 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_91 ;
struct V_43 * V_44 ;
struct V_1 * V_36 = F_1 ( V_3 ) ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
F_38 ( V_36 , V_44 ) ;
F_53 (vq, n, &vdev->vqs, list)
F_45 ( V_5 , V_44 ) ;
F_21 ( V_44 ) ;
}
static struct V_4 * F_54 ( struct V_2 * V_3 ,
int V_8 , T_8 * V_92 ,
const char * V_93 ,
struct V_43 * V_44 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
int V_41 ;
struct V_4 * V_5 = NULL ;
struct V_37 * V_7 ;
unsigned long V_77 = 0 ;
unsigned long V_9 ;
V_7 = F_18 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_7 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_7 ) ;
V_41 = - V_94 ;
goto V_95;
}
V_7 -> V_80 = F_18 ( sizeof( * V_7 -> V_80 ) ,
V_53 | V_18 ) ;
if ( ! V_7 -> V_80 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_8 ) ;
V_41 = - V_94 ;
goto V_95;
}
V_7 -> V_76 = F_44 ( V_36 , V_44 , V_8 ) ;
V_77 = F_49 ( F_50 ( V_7 -> V_76 , V_90 ) ) ;
V_7 -> V_82 = F_55 ( V_77 , V_18 | V_96 ) ;
if ( V_7 -> V_82 == NULL ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_9 ) ;
V_41 = - V_94 ;
goto V_95;
}
V_5 = F_56 ( V_8 , V_7 -> V_76 , V_90 , V_3 ,
true , V_7 -> V_82 , F_42 ,
V_92 , V_93 ) ;
if ( ! V_5 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_10 ) ;
V_41 = - V_94 ;
goto V_95;
}
if ( V_36 -> V_79 == 0 ) {
V_7 -> V_80 -> V_81 . V_82 = ( V_97 ) V_7 -> V_82 ;
V_7 -> V_80 -> V_81 . V_83 = V_90 ;
V_7 -> V_80 -> V_81 . V_71 = V_8 ;
V_7 -> V_80 -> V_81 . V_76 = V_7 -> V_76 ;
V_44 -> V_56 = sizeof( V_7 -> V_80 -> V_81 ) ;
} else {
V_7 -> V_80 -> V_84 . V_85 = ( V_97 ) V_7 -> V_82 ;
V_7 -> V_80 -> V_84 . V_71 = V_8 ;
V_7 -> V_80 -> V_84 . V_76 = V_7 -> V_76 ;
V_7 -> V_80 -> V_84 . V_86 = ( V_97 ) F_57 ( V_5 ) ;
V_7 -> V_80 -> V_84 . V_87 = ( V_97 ) F_58 ( V_5 ) ;
V_44 -> V_56 = sizeof( V_7 -> V_80 -> V_84 ) ;
}
V_44 -> V_54 = V_88 ;
V_44 -> V_9 = 0 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_7 -> V_80 ) ;
V_41 = F_34 ( V_36 , V_44 , V_89 | V_8 ) ;
if ( V_41 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_11 ) ;
goto V_95;
}
V_7 -> V_5 = V_5 ;
V_5 -> V_70 = V_7 ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_59 ( & V_7 -> V_78 , & V_36 -> V_98 ) ;
F_33 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
V_95:
if ( V_5 )
F_48 ( V_5 ) ;
if ( V_7 ) {
if ( V_7 -> V_82 )
F_51 ( V_7 -> V_82 , V_77 ) ;
F_21 ( V_7 -> V_80 ) ;
}
F_21 ( V_7 ) ;
return F_60 ( V_41 ) ;
}
static int F_61 ( struct V_1 * V_36 ,
struct V_4 * V_27 [] , int V_28 ,
struct V_43 * V_44 )
{
int V_39 ;
struct V_50 * V_51 = NULL ;
struct V_6 * V_7 ;
V_51 = F_18 ( sizeof( * V_51 ) , V_53 | V_18 ) ;
if ( ! V_51 ) {
V_39 = - V_94 ;
goto V_99;
}
V_51 -> V_100 = F_26 ( V_27 , V_28 ,
& V_51 -> V_101 ,
& V_36 -> V_6 ) ;
if ( ! V_51 -> V_100 ) {
V_39 = - V_102 ;
goto V_99;
}
V_7 = V_36 -> V_6 ;
V_51 -> V_16 =
( unsigned long ) & V_7 -> V_16 ;
V_51 -> V_25 = V_26 ;
V_44 -> V_54 = V_55 ;
V_44 -> V_9 = V_103 ;
V_44 -> V_56 = sizeof( * V_51 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_51 ;
V_39 = F_34 ( V_36 , V_44 , V_60 ) ;
if ( V_39 ) {
if ( V_39 == - V_104 ) {
V_105 = 0 ;
F_62 ( L_12 ) ;
} else
F_47 ( & V_36 -> V_40 -> V_63 ,
L_13 , V_39 ) ;
F_28 ( V_36 ) ;
}
V_99:
F_21 ( V_51 ) ;
return V_39 ;
}
static int F_63 ( struct V_2 * V_3 , unsigned V_28 ,
struct V_4 * V_27 [] ,
T_8 * V_106 [] ,
const char * V_107 [] )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
unsigned long * V_49 = NULL ;
int V_39 , V_8 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_94 ;
for ( V_8 = 0 ; V_8 < V_28 ; ++ V_8 ) {
V_27 [ V_8 ] = F_54 ( V_3 , V_8 , V_106 [ V_8 ] , V_107 [ V_8 ] ,
V_44 ) ;
if ( F_64 ( V_27 [ V_8 ] ) ) {
V_39 = F_65 ( V_27 [ V_8 ] ) ;
V_27 [ V_8 ] = NULL ;
goto V_99;
}
}
V_39 = - V_94 ;
V_49 = F_39 ( sizeof( & V_36 -> V_58 ) , V_53 | V_18 ) ;
if ( ! V_49 )
goto V_99;
* V_49 = ( unsigned long ) & V_36 -> V_58 ;
if ( V_36 -> V_52 ) {
V_39 = F_61 ( V_36 , V_27 , V_28 , V_44 ) ;
if ( V_39 )
V_36 -> V_52 = 0 ;
}
if ( ! V_36 -> V_52 ) {
V_36 -> V_58 = 0 ;
V_44 -> V_54 = V_59 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_36 -> V_58 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
V_39 = F_34 ( V_36 , V_44 , V_61 ) ;
if ( V_39 )
goto V_99;
}
* V_49 = ( unsigned long ) & V_36 -> V_108 ;
V_36 -> V_108 = 0 ;
V_44 -> V_54 = V_109 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_36 -> V_108 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
V_39 = F_34 ( V_36 , V_44 , V_110 ) ;
if ( V_39 )
goto V_99;
F_21 ( V_49 ) ;
F_21 ( V_44 ) ;
return 0 ;
V_99:
F_21 ( V_49 ) ;
F_21 ( V_44 ) ;
F_52 ( V_3 ) ;
return V_39 ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
* V_36 -> V_111 = 0 ;
V_44 -> V_54 = V_112 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = 0 ;
V_44 -> V_57 = 0 ;
F_34 ( V_36 , V_44 , V_113 ) ;
F_21 ( V_44 ) ;
}
static T_1 F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_114 * V_115 ;
int V_39 ;
T_1 V_17 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return 0 ;
V_115 = F_18 ( sizeof( * V_115 ) , V_53 | V_18 ) ;
if ( ! V_115 ) {
V_17 = 0 ;
goto V_116;
}
V_115 -> V_71 = 0 ;
V_44 -> V_54 = V_117 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_115 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_115 ;
V_39 = F_34 ( V_36 , V_44 , V_118 ) ;
if ( V_39 ) {
V_17 = 0 ;
goto V_116;
}
V_17 = F_68 ( V_115 -> V_115 ) ;
if ( V_36 -> V_79 == 0 )
goto V_116;
V_115 -> V_71 = 1 ;
V_44 -> V_54 = V_117 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_115 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_115 ;
V_39 = F_34 ( V_36 , V_44 , V_118 ) ;
if ( V_39 == 0 )
V_17 |= ( T_1 ) F_68 ( V_115 -> V_115 ) << 32 ;
V_116:
F_21 ( V_115 ) ;
F_21 ( V_44 ) ;
return V_17 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_114 * V_115 ;
struct V_43 * V_44 ;
int V_39 ;
if ( V_36 -> V_79 >= 1 &&
! F_70 ( V_3 , V_119 ) ) {
F_71 ( & V_3 -> V_63 , L_14
L_15 ) ;
return - V_120 ;
}
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_94 ;
V_115 = F_18 ( sizeof( * V_115 ) , V_53 | V_18 ) ;
if ( ! V_115 ) {
V_39 = - V_94 ;
goto V_116;
}
F_72 ( V_3 ) ;
V_115 -> V_71 = 0 ;
V_115 -> V_115 = F_73 ( ( V_121 ) V_3 -> V_115 ) ;
V_44 -> V_54 = V_122 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_115 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_115 ;
V_39 = F_34 ( V_36 , V_44 , V_123 ) ;
if ( V_39 )
goto V_116;
if ( V_36 -> V_79 == 0 )
goto V_116;
V_115 -> V_71 = 1 ;
V_115 -> V_115 = F_73 ( V_3 -> V_115 >> 32 ) ;
V_44 -> V_54 = V_122 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_115 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_115 ;
V_39 = F_34 ( V_36 , V_44 , V_123 ) ;
V_116:
F_21 ( V_115 ) ;
F_21 ( V_44 ) ;
return V_39 ;
}
static void F_74 ( struct V_2 * V_3 ,
unsigned int V_124 , void * V_125 , unsigned V_126 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
int V_39 ;
struct V_43 * V_44 ;
void * V_127 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_127 = F_18 ( V_128 , V_53 | V_18 ) ;
if ( ! V_127 )
goto V_116;
V_44 -> V_54 = V_129 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_124 + V_126 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_127 ;
V_39 = F_34 ( V_36 , V_44 , V_130 ) ;
if ( V_39 )
goto V_116;
memcpy ( V_36 -> V_131 , V_127 , V_124 + V_126 ) ;
if ( V_125 )
memcpy ( V_125 , & V_36 -> V_131 [ V_124 ] , V_126 ) ;
if ( V_36 -> V_132 < V_124 + V_126 )
V_36 -> V_132 = V_124 + V_126 ;
V_116:
F_21 ( V_127 ) ;
F_21 ( V_44 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
unsigned int V_124 , const void * V_125 ,
unsigned V_126 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_43 * V_44 ;
void * V_127 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_127 = F_18 ( V_128 , V_53 | V_18 ) ;
if ( ! V_127 )
goto V_116;
if ( V_36 -> V_132 < V_124 )
F_74 ( V_3 , 0 , NULL , V_124 ) ;
memcpy ( & V_36 -> V_131 [ V_124 ] , V_125 , V_126 ) ;
memcpy ( V_127 , V_36 -> V_131 , sizeof( V_36 -> V_131 ) ) ;
V_44 -> V_54 = V_133 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_124 + V_126 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_127 ;
F_34 ( V_36 , V_44 , V_134 ) ;
V_116:
F_21 ( V_127 ) ;
F_21 ( V_44 ) ;
}
static T_9 F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
return * V_36 -> V_111 ;
}
static void F_77 ( struct V_2 * V_3 , T_9 V_111 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
T_9 V_135 = * V_36 -> V_111 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
* V_36 -> V_111 = V_111 ;
V_44 -> V_54 = V_136 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_111 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_36 -> V_111 ;
V_39 = F_34 ( V_36 , V_44 , V_137 ) ;
if ( V_39 )
* V_36 -> V_111 = V_135 ;
F_21 ( V_44 ) ;
}
static void F_78 ( struct V_138 * V_139 )
{
struct V_2 * V_63 = F_2 ( V_139 , struct V_2 ,
V_63 ) ;
struct V_1 * V_36 = F_1 ( V_63 ) ;
F_21 ( V_36 -> V_111 ) ;
F_21 ( V_36 -> V_72 ) ;
F_21 ( V_36 ) ;
}
static int F_79 ( struct V_140 * V_140 )
{
if ( F_80 ( & V_140 -> V_141 ) != 0 )
return 1 ;
if ( F_81 ( & V_140 -> V_141 ) & ~ ( V_142 | V_143 ) )
return 1 ;
if ( F_82 ( & V_140 -> V_141 ) != 0 )
return 1 ;
return 0 ;
}
static struct V_4 * F_83 ( struct V_1 * V_36 ,
int V_71 )
{
struct V_37 * V_7 ;
unsigned long V_9 ;
struct V_4 * V_5 ;
V_5 = NULL ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_29 (info, &vcdev->virtqueues, node) {
if ( V_7 -> V_5 -> V_71 == V_71 ) {
V_5 = V_7 -> V_5 ;
break;
}
}
F_33 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
}
static void F_84 ( struct V_144 * V_40 ,
unsigned long V_45 ,
struct V_140 * V_140 )
{
T_2 V_145 = V_45 & V_46 ;
struct V_1 * V_36 = F_85 ( & V_40 -> V_63 ) ;
int V_8 ;
struct V_4 * V_5 ;
if ( ! V_36 )
return;
if ( ( V_45 == 0 ) &&
( F_86 ( & V_140 -> V_141 ) ==
( V_146 | V_147 ) ) ) {
}
if ( F_79 ( V_140 ) ) {
if ( ( F_81 ( & V_140 -> V_141 ) & V_148 ) &&
( V_140 -> V_149 [ 0 ] & V_150 ) )
V_36 -> V_41 = - V_104 ;
else
V_36 -> V_41 = - V_151 ;
}
if ( V_36 -> V_42 & V_145 ) {
switch ( V_145 ) {
case V_118 :
case V_123 :
case V_130 :
case V_134 :
case V_137 :
case V_89 :
case V_61 :
case V_110 :
case V_113 :
case V_75 :
case V_60 :
case V_152 :
V_36 -> V_42 &= ~ V_145 ;
F_87 ( & V_36 -> V_48 ) ;
break;
default:
F_47 ( & V_40 -> V_63 , L_16 ,
V_145 ) ;
F_88 ( 1 ) ;
break;
}
}
F_89 (i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
F_90 ( V_8 , & V_36 -> V_58 ) ;
F_91 () ;
V_5 = F_83 ( V_36 , V_8 ) ;
F_14 ( 0 , V_5 ) ;
}
if ( F_92 ( 0 , & V_36 -> V_108 ) ) {
F_93 ( & V_36 -> V_3 ) ;
F_90 ( 0 , & V_36 -> V_108 ) ;
}
}
static int F_94 ( struct V_144 * V_40 )
{
struct V_153 V_154 ;
F_95 ( V_40 , & V_154 ) ;
if ( F_92 ( V_154 . V_155 , V_156 [ V_154 . V_157 ] ) )
return 0 ;
return 1 ;
}
static void F_96 ( void * V_158 , T_10 V_67 )
{
struct V_144 * V_40 = V_158 ;
int V_39 ;
V_39 = F_97 ( V_40 ) ;
if ( V_39 )
F_47 ( & V_40 -> V_63 , L_17 , V_39 ) ;
}
static int F_98 ( struct V_144 * V_40 )
{
V_40 -> V_22 = F_84 ;
if ( F_94 ( V_40 ) )
F_99 ( F_96 , V_40 ) ;
return 0 ;
}
static struct V_1 * F_100 ( struct V_144 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
V_36 = F_85 ( & V_40 -> V_63 ) ;
if ( ! V_36 || V_36 -> V_159 ) {
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return NULL ;
}
V_36 -> V_159 = true ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return V_36 ;
}
static void F_101 ( struct V_144 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_100 ( V_40 ) ;
if ( V_36 && V_40 -> V_160 ) {
if ( V_36 -> V_161 )
F_102 ( & V_36 -> V_3 ) ;
F_103 ( & V_36 -> V_3 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_104 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
}
V_40 -> V_22 = NULL ;
}
static int F_105 ( struct V_144 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_100 ( V_40 ) ;
if ( ! V_36 )
return 0 ;
if ( V_36 -> V_161 )
F_102 ( & V_36 -> V_3 ) ;
F_103 ( & V_36 -> V_3 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_104 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_36 )
{
struct V_162 * V_163 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_94 ;
V_163 = F_18 ( sizeof( * V_163 ) , V_53 | V_18 ) ;
if ( ! V_163 ) {
F_21 ( V_44 ) ;
return - V_94 ;
}
V_44 -> V_54 = V_164 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_163 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_163 ;
V_36 -> V_79 = V_165 ;
do {
V_163 -> V_79 = V_36 -> V_79 ;
V_163 -> V_166 = 0 ;
V_39 = F_34 ( V_36 , V_44 ,
V_152 ) ;
if ( V_39 == - V_104 ) {
if ( V_36 -> V_79 == 0 )
V_39 = 0 ;
else
V_36 -> V_79 -- ;
}
} while ( V_39 == - V_104 );
F_21 ( V_44 ) ;
F_21 ( V_163 ) ;
return V_39 ;
}
static int F_107 ( struct V_144 * V_40 )
{
int V_39 ;
struct V_1 * V_36 ;
unsigned long V_9 ;
V_36 = F_18 ( sizeof( * V_36 ) , V_18 ) ;
if ( ! V_36 ) {
F_47 ( & V_40 -> V_63 , L_18 ) ;
V_39 = - V_94 ;
goto V_116;
}
V_36 -> V_72 = F_18 ( sizeof( * V_36 -> V_72 ) ,
V_53 | V_18 ) ;
if ( ! V_36 -> V_72 ) {
V_39 = - V_94 ;
goto V_116;
}
V_36 -> V_111 = F_18 ( sizeof( * V_36 -> V_111 ) , V_53 | V_18 ) ;
if ( ! V_36 -> V_111 ) {
V_39 = - V_94 ;
goto V_116;
}
V_36 -> V_52 = V_105 ;
V_36 -> V_3 . V_63 . V_167 = & V_40 -> V_63 ;
V_36 -> V_3 . V_63 . V_168 = F_78 ;
V_36 -> V_3 . V_131 = & V_169 ;
V_36 -> V_40 = V_40 ;
F_108 ( & V_36 -> V_48 ) ;
F_109 ( & V_36 -> V_98 ) ;
F_110 ( & V_36 -> V_10 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_104 ( & V_40 -> V_63 , V_36 ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
V_36 -> V_3 . V_154 . V_170 = V_40 -> V_154 . V_171 ;
V_36 -> V_3 . V_154 . V_138 = V_40 -> V_154 . V_172 ;
V_39 = F_106 ( V_36 ) ;
if ( V_39 )
goto V_116;
V_39 = F_111 ( & V_36 -> V_3 ) ;
if ( V_39 ) {
F_47 ( & V_40 -> V_63 , L_19 ,
V_39 ) ;
goto V_173;
}
return 0 ;
V_173:
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_104 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
F_112 ( & V_36 -> V_3 . V_63 ) ;
return V_39 ;
V_116:
if ( V_36 ) {
F_21 ( V_36 -> V_111 ) ;
F_21 ( V_36 -> V_72 ) ;
}
F_21 ( V_36 ) ;
return V_39 ;
}
static int F_113 ( struct V_144 * V_40 , int V_174 )
{
int V_17 ;
struct V_1 * V_36 = F_85 ( & V_40 -> V_63 ) ;
if ( ! V_36 )
return V_175 ;
switch ( V_174 ) {
case V_176 :
V_36 -> V_161 = true ;
V_17 = V_175 ;
break;
default:
V_17 = V_175 ;
break;
}
return V_17 ;
}
static int T_11 F_114 ( char * * V_177 , unsigned int * V_178 , int V_179 ,
int V_180 , int V_181 )
{
int V_182 ;
V_182 = 0 ;
* V_178 = 0 ;
while ( V_182 <= V_180 ) {
int V_183 = F_115 ( * * V_177 ) ;
if ( V_183 < 0 )
break;
* V_178 = * V_178 * 16 + V_183 ;
( * V_177 ) ++ ;
V_182 ++ ;
}
if ( ( V_182 < V_179 ) || ( V_182 > V_180 ) || ( * V_178 > V_181 ) )
return 1 ;
return 0 ;
}
static int T_11 F_116 ( char * V_184 , unsigned int * V_185 ,
unsigned int * V_157 , unsigned int * V_155 )
{
char * V_186 ;
int V_17 , V_39 ;
V_17 = 1 ;
if ( * V_184 == '\0' )
goto V_99;
V_186 = V_184 ;
V_39 = F_114 ( & V_186 , V_185 , 1 , 2 , V_187 ) ;
if ( V_39 || ( V_186 [ 0 ] != '.' ) )
goto V_99;
V_186 ++ ;
V_39 = F_114 ( & V_186 , V_157 , 1 , 1 , V_188 ) ;
if ( V_39 || ( V_186 [ 0 ] != '.' ) )
goto V_99;
V_186 ++ ;
V_39 = F_114 ( & V_186 , V_155 , 4 , 4 , V_189 ) ;
if ( V_39 || ( V_186 [ 0 ] != '\0' ) )
goto V_99;
V_17 = 0 ;
V_99:
return V_17 ;
}
static void T_11 F_117 ( void )
{
unsigned int V_190 , V_191 , V_192 , V_193 , V_194 , V_195 ;
char * V_196 , * V_184 ;
int V_17 ;
V_184 = V_197 ;
while ( ( V_196 = F_118 ( & V_184 , L_20 ) ) ) {
V_17 = F_116 ( F_118 ( & V_196 , L_21 ) , & V_190 ,
& V_192 , & V_194 ) ;
if ( V_17 )
continue;
if ( V_196 != NULL ) {
V_17 = F_116 ( V_196 , & V_191 ,
& V_193 , & V_195 ) ;
if ( ( V_192 > V_193 ) ||
( ( V_192 == V_193 ) && ( V_194 > V_195 ) ) )
V_17 = - V_120 ;
} else {
V_191 = V_190 ;
V_193 = V_192 ;
V_195 = V_194 ;
}
if ( V_17 )
continue;
while ( ( V_192 < V_193 ) ||
( ( V_192 == V_193 ) && ( V_194 <= V_195 ) ) ) {
F_119 ( V_194 , V_156 [ V_192 ] ) ;
V_194 ++ ;
if ( V_194 > V_189 ) {
V_192 ++ ;
V_194 = 0 ;
}
}
}
}
static int T_11 F_120 ( void )
{
F_117 () ;
return F_121 ( & V_198 ) ;
}
static void T_12 F_122 ( void )
{
int V_8 ;
F_123 ( & V_198 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
F_24 ( V_34 [ V_8 ] ) ;
}
