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
static inline long F_42 ( struct V_64 V_65 ,
unsigned long V_66 ,
long V_67 )
{
F_43 ( V_70 ) ;
return F_41 ( V_65 , V_66 , V_67 ) ;
}
static bool F_44 ( struct V_4 * V_5 )
{
struct V_37 * V_7 = V_5 -> V_71 ;
struct V_1 * V_36 ;
struct V_64 V_65 ;
V_36 = F_1 ( V_7 -> V_5 -> V_3 ) ;
F_45 ( V_36 -> V_40 , & V_65 ) ;
V_7 -> V_67 = F_42 ( V_65 , V_5 -> V_72 , V_7 -> V_67 ) ;
if ( V_7 -> V_67 < 0 )
return false ;
return true ;
}
static int F_46 ( struct V_1 * V_36 ,
struct V_43 * V_44 , int V_72 )
{
int V_39 ;
V_36 -> V_73 -> V_72 = V_72 ;
V_44 -> V_54 = V_74 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( struct V_75 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_36 -> V_73 ) ;
V_39 = F_34 ( V_36 , V_44 , V_76 ) ;
if ( V_39 )
return V_39 ;
return V_36 -> V_73 -> V_77 ;
}
static void F_47 ( struct V_4 * V_5 , struct V_43 * V_44 )
{
struct V_1 * V_36 = F_1 ( V_5 -> V_3 ) ;
struct V_37 * V_7 = V_5 -> V_71 ;
unsigned long V_9 ;
unsigned long V_78 ;
int V_39 ;
unsigned int V_72 = V_5 -> V_72 ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_48 ( & V_7 -> V_79 ) ;
F_33 ( & V_36 -> V_10 , V_9 ) ;
if ( V_36 -> V_80 == 0 ) {
V_7 -> V_81 -> V_82 . V_83 = 0 ;
V_7 -> V_81 -> V_82 . V_84 = 0 ;
V_7 -> V_81 -> V_82 . V_72 = V_72 ;
V_7 -> V_81 -> V_82 . V_77 = 0 ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_82 ) ;
} else {
V_7 -> V_81 -> V_85 . V_86 = 0 ;
V_7 -> V_81 -> V_85 . V_72 = V_72 ;
V_7 -> V_81 -> V_85 . V_77 = 0 ;
V_7 -> V_81 -> V_85 . V_87 = 0 ;
V_7 -> V_81 -> V_85 . V_88 = 0 ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_85 ) ;
}
V_44 -> V_54 = V_89 ;
V_44 -> V_9 = 0 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_7 -> V_81 ) ;
V_39 = F_34 ( V_36 , V_44 ,
V_90 | V_72 ) ;
if ( V_39 && ( V_39 != - V_62 ) )
F_49 ( & V_5 -> V_3 -> V_63 , L_6 ,
V_39 , V_72 ) ;
F_50 ( V_5 ) ;
V_78 = F_51 ( F_52 ( V_7 -> V_77 , V_91 ) ) ;
F_53 ( V_7 -> V_83 , V_78 ) ;
F_21 ( V_7 -> V_81 ) ;
F_21 ( V_7 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_92 ;
struct V_43 * V_44 ;
struct V_1 * V_36 = F_1 ( V_3 ) ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
F_38 ( V_36 , V_44 ) ;
F_55 (vq, n, &vdev->vqs, list)
F_47 ( V_5 , V_44 ) ;
F_21 ( V_44 ) ;
}
static struct V_4 * F_56 ( struct V_2 * V_3 ,
int V_8 , T_8 * V_93 ,
const char * V_94 ,
struct V_43 * V_44 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
int V_41 ;
struct V_4 * V_5 = NULL ;
struct V_37 * V_7 ;
unsigned long V_78 = 0 ;
unsigned long V_9 ;
V_7 = F_18 ( sizeof( struct V_37 ) , V_18 ) ;
if ( ! V_7 ) {
F_49 ( & V_36 -> V_40 -> V_63 , L_7 ) ;
V_41 = - V_95 ;
goto V_96;
}
V_7 -> V_81 = F_18 ( sizeof( * V_7 -> V_81 ) ,
V_53 | V_18 ) ;
if ( ! V_7 -> V_81 ) {
F_49 ( & V_36 -> V_40 -> V_63 , L_8 ) ;
V_41 = - V_95 ;
goto V_96;
}
V_7 -> V_77 = F_46 ( V_36 , V_44 , V_8 ) ;
if ( V_7 -> V_77 < 0 ) {
V_41 = V_7 -> V_77 ;
goto V_96;
}
V_78 = F_51 ( F_52 ( V_7 -> V_77 , V_91 ) ) ;
V_7 -> V_83 = F_57 ( V_78 , V_18 | V_97 ) ;
if ( V_7 -> V_83 == NULL ) {
F_49 ( & V_36 -> V_40 -> V_63 , L_9 ) ;
V_41 = - V_95 ;
goto V_96;
}
V_5 = F_58 ( V_8 , V_7 -> V_77 , V_91 , V_3 ,
true , V_7 -> V_83 , F_44 ,
V_93 , V_94 ) ;
if ( ! V_5 ) {
F_49 ( & V_36 -> V_40 -> V_63 , L_10 ) ;
V_41 = - V_95 ;
goto V_96;
}
if ( V_36 -> V_80 == 0 ) {
V_7 -> V_81 -> V_82 . V_83 = ( V_98 ) V_7 -> V_83 ;
V_7 -> V_81 -> V_82 . V_84 = V_91 ;
V_7 -> V_81 -> V_82 . V_72 = V_8 ;
V_7 -> V_81 -> V_82 . V_77 = V_7 -> V_77 ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_82 ) ;
} else {
V_7 -> V_81 -> V_85 . V_86 = ( V_98 ) V_7 -> V_83 ;
V_7 -> V_81 -> V_85 . V_72 = V_8 ;
V_7 -> V_81 -> V_85 . V_77 = V_7 -> V_77 ;
V_7 -> V_81 -> V_85 . V_87 = ( V_98 ) F_59 ( V_5 ) ;
V_7 -> V_81 -> V_85 . V_88 = ( V_98 ) F_60 ( V_5 ) ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_85 ) ;
}
V_44 -> V_54 = V_89 ;
V_44 -> V_9 = 0 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_7 -> V_81 ) ;
V_41 = F_34 ( V_36 , V_44 , V_90 | V_8 ) ;
if ( V_41 ) {
F_49 ( & V_36 -> V_40 -> V_63 , L_11 ) ;
goto V_96;
}
V_7 -> V_5 = V_5 ;
V_5 -> V_71 = V_7 ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_61 ( & V_7 -> V_79 , & V_36 -> V_99 ) ;
F_33 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
V_96:
if ( V_5 )
F_50 ( V_5 ) ;
if ( V_7 ) {
if ( V_7 -> V_83 )
F_53 ( V_7 -> V_83 , V_78 ) ;
F_21 ( V_7 -> V_81 ) ;
}
F_21 ( V_7 ) ;
return F_62 ( V_41 ) ;
}
static int F_63 ( struct V_1 * V_36 ,
struct V_4 * V_27 [] , int V_28 ,
struct V_43 * V_44 )
{
int V_39 ;
struct V_50 * V_51 = NULL ;
struct V_6 * V_7 ;
V_51 = F_18 ( sizeof( * V_51 ) , V_53 | V_18 ) ;
if ( ! V_51 ) {
V_39 = - V_95 ;
goto V_100;
}
V_51 -> V_101 = F_26 ( V_27 , V_28 ,
& V_51 -> V_102 ,
& V_36 -> V_6 ) ;
if ( ! V_51 -> V_101 ) {
V_39 = - V_103 ;
goto V_100;
}
V_7 = V_36 -> V_6 ;
V_51 -> V_16 =
( unsigned long ) & V_7 -> V_16 ;
V_51 -> V_25 = V_26 ;
V_44 -> V_54 = V_55 ;
V_44 -> V_9 = V_104 ;
V_44 -> V_56 = sizeof( * V_51 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_51 ;
V_39 = F_34 ( V_36 , V_44 , V_60 ) ;
if ( V_39 ) {
if ( V_39 == - V_105 ) {
V_106 = 0 ;
F_64 ( L_12 ) ;
} else
F_49 ( & V_36 -> V_40 -> V_63 ,
L_13 , V_39 ) ;
F_28 ( V_36 ) ;
}
V_100:
F_21 ( V_51 ) ;
return V_39 ;
}
static int F_65 ( struct V_2 * V_3 , unsigned V_28 ,
struct V_4 * V_27 [] ,
T_8 * V_107 [] ,
const char * const V_108 [] )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
unsigned long * V_49 = NULL ;
int V_39 , V_8 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_95 ;
for ( V_8 = 0 ; V_8 < V_28 ; ++ V_8 ) {
V_27 [ V_8 ] = F_56 ( V_3 , V_8 , V_107 [ V_8 ] , V_108 [ V_8 ] ,
V_44 ) ;
if ( F_66 ( V_27 [ V_8 ] ) ) {
V_39 = F_67 ( V_27 [ V_8 ] ) ;
V_27 [ V_8 ] = NULL ;
goto V_100;
}
}
V_39 = - V_95 ;
V_49 = F_39 ( sizeof( & V_36 -> V_58 ) , V_53 | V_18 ) ;
if ( ! V_49 )
goto V_100;
* V_49 = ( unsigned long ) & V_36 -> V_58 ;
if ( V_36 -> V_52 ) {
V_39 = F_63 ( V_36 , V_27 , V_28 , V_44 ) ;
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
goto V_100;
}
* V_49 = ( unsigned long ) & V_36 -> V_109 ;
V_36 -> V_109 = 0 ;
V_44 -> V_54 = V_110 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_36 -> V_109 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
V_39 = F_34 ( V_36 , V_44 , V_111 ) ;
if ( V_39 )
goto V_100;
F_21 ( V_49 ) ;
F_21 ( V_44 ) ;
return 0 ;
V_100:
F_21 ( V_49 ) ;
F_21 ( V_44 ) ;
F_54 ( V_3 ) ;
return V_39 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
* V_36 -> V_112 = 0 ;
V_44 -> V_54 = V_113 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = 0 ;
V_44 -> V_57 = 0 ;
F_34 ( V_36 , V_44 , V_114 ) ;
F_21 ( V_44 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_115 * V_116 ;
int V_39 ;
T_1 V_17 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return 0 ;
V_116 = F_18 ( sizeof( * V_116 ) , V_53 | V_18 ) ;
if ( ! V_116 ) {
V_17 = 0 ;
goto V_117;
}
V_116 -> V_72 = 0 ;
V_44 -> V_54 = V_118 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_116 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_116 ;
V_39 = F_34 ( V_36 , V_44 , V_119 ) ;
if ( V_39 ) {
V_17 = 0 ;
goto V_117;
}
V_17 = F_70 ( V_116 -> V_116 ) ;
if ( V_36 -> V_80 == 0 )
goto V_117;
V_116 -> V_72 = 1 ;
V_44 -> V_54 = V_118 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_116 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_116 ;
V_39 = F_34 ( V_36 , V_44 , V_119 ) ;
if ( V_39 == 0 )
V_17 |= ( T_1 ) F_70 ( V_116 -> V_116 ) << 32 ;
V_117:
F_21 ( V_116 ) ;
F_21 ( V_44 ) ;
return V_17 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_115 * V_116 ;
struct V_43 * V_44 ;
int V_39 ;
if ( V_36 -> V_80 >= 1 &&
! F_72 ( V_3 , V_120 ) ) {
F_73 ( & V_3 -> V_63 , L_14
L_15 ) ;
return - V_121 ;
}
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_95 ;
V_116 = F_18 ( sizeof( * V_116 ) , V_53 | V_18 ) ;
if ( ! V_116 ) {
V_39 = - V_95 ;
goto V_117;
}
F_74 ( V_3 ) ;
V_116 -> V_72 = 0 ;
V_116 -> V_116 = F_75 ( ( V_122 ) V_3 -> V_116 ) ;
V_44 -> V_54 = V_123 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_116 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_116 ;
V_39 = F_34 ( V_36 , V_44 , V_124 ) ;
if ( V_39 )
goto V_117;
if ( V_36 -> V_80 == 0 )
goto V_117;
V_116 -> V_72 = 1 ;
V_116 -> V_116 = F_75 ( V_3 -> V_116 >> 32 ) ;
V_44 -> V_54 = V_123 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_116 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_116 ;
V_39 = F_34 ( V_36 , V_44 , V_124 ) ;
V_117:
F_21 ( V_116 ) ;
F_21 ( V_44 ) ;
return V_39 ;
}
static void F_76 ( struct V_2 * V_3 ,
unsigned int V_125 , void * V_126 , unsigned V_127 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
int V_39 ;
struct V_43 * V_44 ;
void * V_128 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_128 = F_18 ( V_129 , V_53 | V_18 ) ;
if ( ! V_128 )
goto V_117;
V_44 -> V_54 = V_130 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_125 + V_127 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_128 ;
V_39 = F_34 ( V_36 , V_44 , V_131 ) ;
if ( V_39 )
goto V_117;
memcpy ( V_36 -> V_132 , V_128 , V_125 + V_127 ) ;
if ( V_126 )
memcpy ( V_126 , & V_36 -> V_132 [ V_125 ] , V_127 ) ;
if ( V_36 -> V_133 < V_125 + V_127 )
V_36 -> V_133 = V_125 + V_127 ;
V_117:
F_21 ( V_128 ) ;
F_21 ( V_44 ) ;
}
static void F_77 ( struct V_2 * V_3 ,
unsigned int V_125 , const void * V_126 ,
unsigned V_127 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_43 * V_44 ;
void * V_128 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_128 = F_18 ( V_129 , V_53 | V_18 ) ;
if ( ! V_128 )
goto V_117;
if ( V_36 -> V_133 < V_125 )
F_76 ( V_3 , 0 , NULL , V_125 ) ;
memcpy ( & V_36 -> V_132 [ V_125 ] , V_126 , V_127 ) ;
memcpy ( V_128 , V_36 -> V_132 , sizeof( V_36 -> V_132 ) ) ;
V_44 -> V_54 = V_134 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_125 + V_127 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_128 ;
F_34 ( V_36 , V_44 , V_135 ) ;
V_117:
F_21 ( V_128 ) ;
F_21 ( V_44 ) ;
}
static T_9 F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
return * V_36 -> V_112 ;
}
static void F_79 ( struct V_2 * V_3 , T_9 V_112 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
T_9 V_136 = * V_36 -> V_112 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
* V_36 -> V_112 = V_112 ;
V_44 -> V_54 = V_137 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_112 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_36 -> V_112 ;
V_39 = F_34 ( V_36 , V_44 , V_138 ) ;
if ( V_39 )
* V_36 -> V_112 = V_136 ;
F_21 ( V_44 ) ;
}
static void F_80 ( struct V_139 * V_140 )
{
struct V_2 * V_63 = F_2 ( V_140 , struct V_2 ,
V_63 ) ;
struct V_1 * V_36 = F_1 ( V_63 ) ;
F_21 ( V_36 -> V_112 ) ;
F_21 ( V_36 -> V_73 ) ;
F_21 ( V_36 ) ;
}
static int F_81 ( struct V_141 * V_141 )
{
if ( F_82 ( & V_141 -> V_142 ) != 0 )
return 1 ;
if ( F_83 ( & V_141 -> V_142 ) & ~ ( V_143 | V_144 ) )
return 1 ;
if ( F_84 ( & V_141 -> V_142 ) != 0 )
return 1 ;
return 0 ;
}
static struct V_4 * F_85 ( struct V_1 * V_36 ,
int V_72 )
{
struct V_37 * V_7 ;
unsigned long V_9 ;
struct V_4 * V_5 ;
V_5 = NULL ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
F_29 (info, &vcdev->virtqueues, node) {
if ( V_7 -> V_5 -> V_72 == V_72 ) {
V_5 = V_7 -> V_5 ;
break;
}
}
F_33 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
}
static void F_86 ( struct V_1 * V_36 ,
T_2 V_145 )
{
if ( V_36 -> V_42 & V_145 ) {
switch ( V_145 ) {
case V_119 :
case V_124 :
case V_131 :
case V_135 :
case V_138 :
case V_90 :
case V_61 :
case V_111 :
case V_114 :
case V_76 :
case V_60 :
case V_146 :
V_36 -> V_42 &= ~ V_145 ;
F_87 ( & V_36 -> V_48 ) ;
break;
default:
F_49 ( & V_36 -> V_40 -> V_63 ,
L_16 , V_145 ) ;
F_88 ( 1 ) ;
break;
}
}
}
static void F_89 ( struct V_147 * V_40 ,
unsigned long V_45 ,
struct V_141 * V_141 )
{
T_2 V_145 = V_45 & V_46 ;
struct V_1 * V_36 = F_90 ( & V_40 -> V_63 ) ;
int V_8 ;
struct V_4 * V_5 ;
if ( ! V_36 )
return;
if ( F_66 ( V_141 ) ) {
V_36 -> V_41 = F_67 ( V_141 ) ;
F_86 ( V_36 , V_145 ) ;
return;
}
if ( ( V_45 == 0 ) &&
( F_91 ( & V_141 -> V_142 ) ==
( V_148 | V_149 ) ) ) {
}
if ( F_81 ( V_141 ) ) {
if ( ( F_83 ( & V_141 -> V_142 ) & V_150 ) &&
( V_141 -> V_151 [ 0 ] & V_152 ) )
V_36 -> V_41 = - V_105 ;
else
V_36 -> V_41 = - V_153 ;
}
F_86 ( V_36 , V_145 ) ;
F_92 (i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
F_93 ( V_8 , & V_36 -> V_58 ) ;
F_94 () ;
V_5 = F_85 ( V_36 , V_8 ) ;
F_14 ( 0 , V_5 ) ;
}
if ( F_95 ( 0 , & V_36 -> V_109 ) ) {
F_96 ( & V_36 -> V_3 ) ;
F_93 ( 0 , & V_36 -> V_109 ) ;
}
}
static int F_97 ( struct V_147 * V_40 )
{
struct V_154 V_155 ;
F_98 ( V_40 , & V_155 ) ;
if ( F_95 ( V_155 . V_156 , V_157 [ V_155 . V_158 ] ) )
return 0 ;
return 1 ;
}
static void F_99 ( void * V_159 , T_10 V_67 )
{
struct V_147 * V_40 = V_159 ;
int V_39 ;
V_39 = F_100 ( V_40 ) ;
if ( V_39 )
F_49 ( & V_40 -> V_63 , L_17 , V_39 ) ;
}
static int F_101 ( struct V_147 * V_40 )
{
V_40 -> V_22 = F_89 ;
if ( F_97 ( V_40 ) )
F_102 ( F_99 , V_40 ) ;
return 0 ;
}
static struct V_1 * F_103 ( struct V_147 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
V_36 = F_90 ( & V_40 -> V_63 ) ;
if ( ! V_36 || V_36 -> V_160 ) {
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return NULL ;
}
V_36 -> V_160 = true ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return V_36 ;
}
static void F_104 ( struct V_147 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_103 ( V_40 ) ;
if ( V_36 && V_40 -> V_161 ) {
if ( V_36 -> V_162 )
F_105 ( & V_36 -> V_3 ) ;
F_106 ( & V_36 -> V_3 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_107 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
}
V_40 -> V_22 = NULL ;
}
static int F_108 ( struct V_147 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_103 ( V_40 ) ;
if ( ! V_36 )
return 0 ;
if ( V_36 -> V_162 )
F_105 ( & V_36 -> V_3 ) ;
F_106 ( & V_36 -> V_3 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_107 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_36 )
{
struct V_163 * V_164 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_95 ;
V_164 = F_18 ( sizeof( * V_164 ) , V_53 | V_18 ) ;
if ( ! V_164 ) {
F_21 ( V_44 ) ;
return - V_95 ;
}
V_44 -> V_54 = V_165 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_164 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_164 ;
V_36 -> V_80 = V_166 ;
do {
V_164 -> V_80 = V_36 -> V_80 ;
V_164 -> V_167 = 0 ;
V_39 = F_34 ( V_36 , V_44 ,
V_146 ) ;
if ( V_39 == - V_105 ) {
if ( V_36 -> V_80 == 0 )
V_39 = 0 ;
else
V_36 -> V_80 -- ;
}
} while ( V_39 == - V_105 );
F_21 ( V_44 ) ;
F_21 ( V_164 ) ;
return V_39 ;
}
static int F_110 ( struct V_147 * V_40 )
{
int V_39 ;
struct V_1 * V_36 ;
unsigned long V_9 ;
V_36 = F_18 ( sizeof( * V_36 ) , V_18 ) ;
if ( ! V_36 ) {
F_49 ( & V_40 -> V_63 , L_18 ) ;
V_39 = - V_95 ;
goto V_117;
}
V_36 -> V_73 = F_18 ( sizeof( * V_36 -> V_73 ) ,
V_53 | V_18 ) ;
if ( ! V_36 -> V_73 ) {
V_39 = - V_95 ;
goto V_117;
}
V_36 -> V_112 = F_18 ( sizeof( * V_36 -> V_112 ) , V_53 | V_18 ) ;
if ( ! V_36 -> V_112 ) {
V_39 = - V_95 ;
goto V_117;
}
V_36 -> V_52 = V_106 ;
V_36 -> V_3 . V_63 . V_168 = & V_40 -> V_63 ;
V_36 -> V_3 . V_63 . V_169 = F_80 ;
V_36 -> V_3 . V_132 = & V_170 ;
V_36 -> V_40 = V_40 ;
F_111 ( & V_36 -> V_48 ) ;
F_112 ( & V_36 -> V_99 ) ;
F_113 ( & V_36 -> V_10 ) ;
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_107 ( & V_40 -> V_63 , V_36 ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
V_36 -> V_3 . V_155 . V_171 = V_40 -> V_155 . V_172 ;
V_36 -> V_3 . V_155 . V_139 = V_40 -> V_155 . V_173 ;
V_39 = F_109 ( V_36 ) ;
if ( V_39 )
goto V_117;
V_39 = F_114 ( & V_36 -> V_3 ) ;
if ( V_39 ) {
F_49 ( & V_40 -> V_63 , L_19 ,
V_39 ) ;
goto V_174;
}
return 0 ;
V_174:
F_31 ( F_32 ( V_40 ) , V_9 ) ;
F_107 ( & V_40 -> V_63 , NULL ) ;
F_33 ( F_32 ( V_40 ) , V_9 ) ;
F_115 ( & V_36 -> V_3 . V_63 ) ;
return V_39 ;
V_117:
if ( V_36 ) {
F_21 ( V_36 -> V_112 ) ;
F_21 ( V_36 -> V_73 ) ;
}
F_21 ( V_36 ) ;
return V_39 ;
}
static int F_116 ( struct V_147 * V_40 , int V_175 )
{
int V_17 ;
struct V_1 * V_36 = F_90 ( & V_40 -> V_63 ) ;
if ( ! V_36 )
return V_176 ;
switch ( V_175 ) {
case V_177 :
V_36 -> V_162 = true ;
V_17 = V_176 ;
break;
default:
V_17 = V_176 ;
break;
}
return V_17 ;
}
static int T_11 F_117 ( char * * V_178 , unsigned int * V_179 , int V_180 ,
int V_181 , int V_182 )
{
int V_183 ;
V_183 = 0 ;
* V_179 = 0 ;
while ( V_183 <= V_181 ) {
int V_184 = F_118 ( * * V_178 ) ;
if ( V_184 < 0 )
break;
* V_179 = * V_179 * 16 + V_184 ;
( * V_178 ) ++ ;
V_183 ++ ;
}
if ( ( V_183 < V_180 ) || ( V_183 > V_181 ) || ( * V_179 > V_182 ) )
return 1 ;
return 0 ;
}
static int T_11 F_119 ( char * V_185 , unsigned int * V_186 ,
unsigned int * V_158 , unsigned int * V_156 )
{
char * V_187 ;
int V_17 , V_39 ;
V_17 = 1 ;
if ( * V_185 == '\0' )
goto V_100;
V_187 = V_185 ;
V_39 = F_117 ( & V_187 , V_186 , 1 , 2 , V_188 ) ;
if ( V_39 || ( V_187 [ 0 ] != '.' ) )
goto V_100;
V_187 ++ ;
V_39 = F_117 ( & V_187 , V_158 , 1 , 1 , V_189 ) ;
if ( V_39 || ( V_187 [ 0 ] != '.' ) )
goto V_100;
V_187 ++ ;
V_39 = F_117 ( & V_187 , V_156 , 4 , 4 , V_190 ) ;
if ( V_39 || ( V_187 [ 0 ] != '\0' ) )
goto V_100;
V_17 = 0 ;
V_100:
return V_17 ;
}
static void T_11 F_120 ( void )
{
unsigned int V_191 , V_192 , V_193 , V_194 , V_195 , V_196 ;
char * V_197 , * V_185 ;
int V_17 ;
V_185 = V_198 ;
while ( ( V_197 = F_121 ( & V_185 , L_20 ) ) ) {
V_17 = F_119 ( F_121 ( & V_197 , L_21 ) , & V_191 ,
& V_193 , & V_195 ) ;
if ( V_17 )
continue;
if ( V_197 != NULL ) {
V_17 = F_119 ( V_197 , & V_192 ,
& V_194 , & V_196 ) ;
if ( ( V_193 > V_194 ) ||
( ( V_193 == V_194 ) && ( V_195 > V_196 ) ) )
V_17 = - V_121 ;
} else {
V_192 = V_191 ;
V_194 = V_193 ;
V_196 = V_195 ;
}
if ( V_17 )
continue;
while ( ( V_193 < V_194 ) ||
( ( V_193 == V_194 ) && ( V_195 <= V_196 ) ) ) {
F_122 ( V_195 , V_157 [ V_193 ] ) ;
V_195 ++ ;
if ( V_195 > V_190 ) {
V_193 ++ ;
V_195 = 0 ;
}
}
}
}
static int T_11 F_123 ( void )
{
F_120 () ;
return F_124 ( & V_199 ) ;
}
static void T_12 F_125 ( void )
{
int V_8 ;
F_126 ( & V_199 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
F_24 ( V_34 [ V_8 ] ) ;
}
