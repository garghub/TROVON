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
static unsigned long F_24 ( struct V_4 * V_27 [] , int V_28 ,
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
V_32 = F_25 ( V_7 -> V_11 , V_28 ) ;
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
static void F_26 ( struct V_1 * V_36 )
{
struct V_37 * V_7 ;
F_27 (info, &vcdev->virtqueues, node)
F_3 ( V_7 -> V_5 , V_36 -> V_6 ) ;
}
static int F_28 ( struct V_1 * V_36 , T_2 V_38 )
{
unsigned long V_9 ;
T_2 V_39 ;
F_29 ( F_30 ( V_36 -> V_40 ) , V_9 ) ;
if ( V_36 -> V_41 )
V_39 = 0 ;
else
V_39 = V_36 -> V_42 & V_38 ;
F_31 ( F_30 ( V_36 -> V_40 ) , V_9 ) ;
return V_39 ;
}
static int F_32 ( struct V_1 * V_36 ,
struct V_43 * V_44 , T_2 V_45 )
{
int V_39 ;
unsigned long V_9 ;
int V_38 = V_45 & V_46 ;
do {
F_29 ( F_30 ( V_36 -> V_40 ) , V_9 ) ;
V_39 = F_33 ( V_36 -> V_40 , V_44 , V_45 , 0 , 0 ) ;
if ( ! V_39 ) {
if ( ! V_36 -> V_42 )
V_36 -> V_41 = 0 ;
V_36 -> V_42 |= V_38 ;
}
F_31 ( F_30 ( V_36 -> V_40 ) , V_9 ) ;
F_34 () ;
} while ( V_39 == - V_47 );
F_35 ( V_36 -> V_48 , F_28 ( V_36 , V_38 ) == 0 ) ;
return V_39 ? V_39 : V_36 -> V_41 ;
}
static void F_36 ( struct V_1 * V_36 ,
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
V_49 = F_37 ( sizeof( & V_36 -> V_58 ) ,
V_53 | V_18 ) ;
if ( ! V_49 )
return;
* V_49 = 0 ;
V_44 -> V_54 = V_59 ;
V_44 -> V_56 = sizeof( & V_36 -> V_58 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
}
V_36 -> V_58 = 0 ;
V_44 -> V_9 = 0 ;
V_39 = F_32 ( V_36 , V_44 ,
V_36 -> V_52 ?
V_60 :
V_61 ) ;
if ( V_39 && ( V_39 != - V_62 ) )
F_38 ( & V_36 -> V_40 -> V_63 ,
L_1 , V_39 ) ;
else if ( V_36 -> V_52 )
F_26 ( V_36 ) ;
F_21 ( V_49 ) ;
F_21 ( V_51 ) ;
}
static inline long F_39 ( struct V_64 V_65 ,
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
static inline long F_40 ( struct V_64 V_65 ,
unsigned long V_66 ,
long V_67 )
{
F_41 ( V_70 ) ;
return F_39 ( V_65 , V_66 , V_67 ) ;
}
static bool F_42 ( struct V_4 * V_5 )
{
struct V_37 * V_7 = V_5 -> V_71 ;
struct V_1 * V_36 ;
struct V_64 V_65 ;
V_36 = F_1 ( V_7 -> V_5 -> V_3 ) ;
F_43 ( V_36 -> V_40 , & V_65 ) ;
V_7 -> V_67 = F_40 ( V_65 , V_5 -> V_72 , V_7 -> V_67 ) ;
if ( V_7 -> V_67 < 0 )
return false ;
return true ;
}
static int F_44 ( struct V_1 * V_36 ,
struct V_43 * V_44 , int V_72 )
{
int V_39 ;
V_36 -> V_73 -> V_72 = V_72 ;
V_44 -> V_54 = V_74 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( struct V_75 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_36 -> V_73 ) ;
V_39 = F_32 ( V_36 , V_44 , V_76 ) ;
if ( V_39 )
return V_39 ;
return V_36 -> V_73 -> V_77 ;
}
static void F_45 ( struct V_4 * V_5 , struct V_43 * V_44 )
{
struct V_1 * V_36 = F_1 ( V_5 -> V_3 ) ;
struct V_37 * V_7 = V_5 -> V_71 ;
unsigned long V_9 ;
unsigned long V_78 ;
int V_39 ;
unsigned int V_72 = V_5 -> V_72 ;
F_29 ( & V_36 -> V_10 , V_9 ) ;
F_46 ( & V_7 -> V_79 ) ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
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
V_39 = F_32 ( V_36 , V_44 ,
V_90 | V_72 ) ;
if ( V_39 && ( V_39 != - V_62 ) )
F_47 ( & V_5 -> V_3 -> V_63 , L_6 ,
V_39 , V_72 ) ;
F_48 ( V_5 ) ;
V_78 = F_49 ( F_50 ( V_7 -> V_77 , V_91 ) ) ;
F_51 ( V_7 -> V_83 , V_78 ) ;
F_21 ( V_7 -> V_81 ) ;
F_21 ( V_7 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_92 ;
struct V_43 * V_44 ;
struct V_1 * V_36 = F_1 ( V_3 ) ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
F_36 ( V_36 , V_44 ) ;
F_53 (vq, n, &vdev->vqs, list)
F_45 ( V_5 , V_44 ) ;
F_21 ( V_44 ) ;
}
static struct V_4 * F_54 ( struct V_2 * V_3 ,
int V_8 , T_8 * V_93 ,
const char * V_94 , bool V_95 ,
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
F_47 ( & V_36 -> V_40 -> V_63 , L_7 ) ;
V_41 = - V_96 ;
goto V_97;
}
V_7 -> V_81 = F_18 ( sizeof( * V_7 -> V_81 ) ,
V_53 | V_18 ) ;
if ( ! V_7 -> V_81 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_8 ) ;
V_41 = - V_96 ;
goto V_97;
}
V_7 -> V_77 = F_44 ( V_36 , V_44 , V_8 ) ;
if ( V_7 -> V_77 < 0 ) {
V_41 = V_7 -> V_77 ;
goto V_97;
}
V_78 = F_49 ( F_50 ( V_7 -> V_77 , V_91 ) ) ;
V_7 -> V_83 = F_55 ( V_78 , V_18 | V_98 ) ;
if ( V_7 -> V_83 == NULL ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_9 ) ;
V_41 = - V_96 ;
goto V_97;
}
V_5 = F_56 ( V_8 , V_7 -> V_77 , V_91 , V_3 ,
true , V_95 , V_7 -> V_83 , F_42 ,
V_93 , V_94 ) ;
if ( ! V_5 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_10 ) ;
V_41 = - V_96 ;
goto V_97;
}
if ( V_36 -> V_80 == 0 ) {
V_7 -> V_81 -> V_82 . V_83 = ( V_99 ) V_7 -> V_83 ;
V_7 -> V_81 -> V_82 . V_84 = V_91 ;
V_7 -> V_81 -> V_82 . V_72 = V_8 ;
V_7 -> V_81 -> V_82 . V_77 = V_7 -> V_77 ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_82 ) ;
} else {
V_7 -> V_81 -> V_85 . V_86 = ( V_99 ) V_7 -> V_83 ;
V_7 -> V_81 -> V_85 . V_72 = V_8 ;
V_7 -> V_81 -> V_85 . V_77 = V_7 -> V_77 ;
V_7 -> V_81 -> V_85 . V_87 = ( V_99 ) F_57 ( V_5 ) ;
V_7 -> V_81 -> V_85 . V_88 = ( V_99 ) F_58 ( V_5 ) ;
V_44 -> V_56 = sizeof( V_7 -> V_81 -> V_85 ) ;
}
V_44 -> V_54 = V_89 ;
V_44 -> V_9 = 0 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) ( V_7 -> V_81 ) ;
V_41 = F_32 ( V_36 , V_44 , V_90 | V_8 ) ;
if ( V_41 ) {
F_47 ( & V_36 -> V_40 -> V_63 , L_11 ) ;
goto V_97;
}
V_7 -> V_5 = V_5 ;
V_5 -> V_71 = V_7 ;
F_29 ( & V_36 -> V_10 , V_9 ) ;
F_59 ( & V_7 -> V_79 , & V_36 -> V_100 ) ;
F_31 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
V_97:
if ( V_5 )
F_48 ( V_5 ) ;
if ( V_7 ) {
if ( V_7 -> V_83 )
F_51 ( V_7 -> V_83 , V_78 ) ;
F_21 ( V_7 -> V_81 ) ;
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
V_39 = - V_96 ;
goto V_101;
}
V_51 -> V_102 = F_24 ( V_27 , V_28 ,
& V_51 -> V_103 ,
& V_36 -> V_6 ) ;
if ( ! V_51 -> V_102 ) {
V_39 = - V_104 ;
goto V_101;
}
V_7 = V_36 -> V_6 ;
V_51 -> V_16 =
( unsigned long ) & V_7 -> V_16 ;
V_51 -> V_25 = V_26 ;
V_44 -> V_54 = V_55 ;
V_44 -> V_9 = V_105 ;
V_44 -> V_56 = sizeof( * V_51 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_51 ;
V_39 = F_32 ( V_36 , V_44 , V_60 ) ;
if ( V_39 ) {
if ( V_39 == - V_106 ) {
V_107 = 0 ;
F_62 ( L_12 ) ;
} else
F_47 ( & V_36 -> V_40 -> V_63 ,
L_13 , V_39 ) ;
F_26 ( V_36 ) ;
}
V_101:
F_21 ( V_51 ) ;
return V_39 ;
}
static int F_63 ( struct V_2 * V_3 , unsigned V_28 ,
struct V_4 * V_27 [] ,
T_8 * V_108 [] ,
const char * const V_109 [] ,
const bool * V_95 ,
struct V_110 * V_86 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
unsigned long * V_49 = NULL ;
int V_39 , V_8 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_96 ;
for ( V_8 = 0 ; V_8 < V_28 ; ++ V_8 ) {
V_27 [ V_8 ] = F_54 ( V_3 , V_8 , V_108 [ V_8 ] , V_109 [ V_8 ] ,
V_95 ? V_95 [ V_8 ] : false , V_44 ) ;
if ( F_64 ( V_27 [ V_8 ] ) ) {
V_39 = F_65 ( V_27 [ V_8 ] ) ;
V_27 [ V_8 ] = NULL ;
goto V_101;
}
}
V_39 = - V_96 ;
V_49 = F_37 ( sizeof( & V_36 -> V_58 ) , V_53 | V_18 ) ;
if ( ! V_49 )
goto V_101;
* V_49 = ( unsigned long ) & V_36 -> V_58 ;
if ( V_36 -> V_52 ) {
V_39 = F_61 ( V_36 , V_27 , V_28 , V_44 ) ;
if ( V_39 )
V_36 -> V_52 = false ;
}
if ( ! V_36 -> V_52 ) {
V_36 -> V_58 = 0 ;
V_44 -> V_54 = V_59 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( & V_36 -> V_58 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
V_39 = F_32 ( V_36 , V_44 , V_61 ) ;
if ( V_39 )
goto V_101;
}
* V_49 = ( unsigned long ) & V_36 -> V_111 ;
V_36 -> V_111 = 0 ;
V_44 -> V_54 = V_112 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( & V_36 -> V_111 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_49 ;
V_39 = F_32 ( V_36 , V_44 , V_113 ) ;
if ( V_39 )
goto V_101;
F_21 ( V_49 ) ;
F_21 ( V_44 ) ;
return 0 ;
V_101:
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
* V_36 -> V_114 = 0 ;
V_44 -> V_54 = V_115 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = 0 ;
V_44 -> V_57 = 0 ;
F_32 ( V_36 , V_44 , V_116 ) ;
F_21 ( V_44 ) ;
}
static T_1 F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_117 * V_118 ;
int V_39 ;
T_1 V_17 ;
struct V_43 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return 0 ;
V_118 = F_18 ( sizeof( * V_118 ) , V_53 | V_18 ) ;
if ( ! V_118 ) {
V_17 = 0 ;
goto V_119;
}
V_118 -> V_72 = 0 ;
V_44 -> V_54 = V_120 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_118 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_118 ;
V_39 = F_32 ( V_36 , V_44 , V_121 ) ;
if ( V_39 ) {
V_17 = 0 ;
goto V_119;
}
V_17 = F_68 ( V_118 -> V_118 ) ;
if ( V_36 -> V_80 == 0 )
goto V_119;
V_118 -> V_72 = 1 ;
V_44 -> V_54 = V_120 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_118 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_118 ;
V_39 = F_32 ( V_36 , V_44 , V_121 ) ;
if ( V_39 == 0 )
V_17 |= ( T_1 ) F_68 ( V_118 -> V_118 ) << 32 ;
V_119:
F_21 ( V_118 ) ;
F_21 ( V_44 ) ;
return V_17 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_117 * V_118 ;
struct V_43 * V_44 ;
int V_39 ;
if ( V_36 -> V_80 >= 1 &&
! F_70 ( V_3 , V_122 ) ) {
F_71 ( & V_3 -> V_63 , L_14
L_15 ) ;
return - V_123 ;
}
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_96 ;
V_118 = F_18 ( sizeof( * V_118 ) , V_53 | V_18 ) ;
if ( ! V_118 ) {
V_39 = - V_96 ;
goto V_119;
}
F_72 ( V_3 ) ;
V_118 -> V_72 = 0 ;
V_118 -> V_118 = F_73 ( ( V_124 ) V_3 -> V_118 ) ;
V_44 -> V_54 = V_125 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_118 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_118 ;
V_39 = F_32 ( V_36 , V_44 , V_126 ) ;
if ( V_39 )
goto V_119;
if ( V_36 -> V_80 == 0 )
goto V_119;
V_118 -> V_72 = 1 ;
V_118 -> V_118 = F_73 ( V_3 -> V_118 >> 32 ) ;
V_44 -> V_54 = V_125 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_118 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_118 ;
V_39 = F_32 ( V_36 , V_44 , V_126 ) ;
V_119:
F_21 ( V_118 ) ;
F_21 ( V_44 ) ;
return V_39 ;
}
static void F_74 ( struct V_2 * V_3 ,
unsigned int V_127 , void * V_128 , unsigned V_129 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
int V_39 ;
struct V_43 * V_44 ;
void * V_130 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_130 = F_18 ( V_131 , V_53 | V_18 ) ;
if ( ! V_130 )
goto V_119;
V_44 -> V_54 = V_132 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_127 + V_129 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_130 ;
V_39 = F_32 ( V_36 , V_44 , V_133 ) ;
if ( V_39 )
goto V_119;
memcpy ( V_36 -> V_134 , V_130 , V_127 + V_129 ) ;
if ( V_128 )
memcpy ( V_128 , & V_36 -> V_134 [ V_127 ] , V_129 ) ;
if ( V_36 -> V_135 < V_127 + V_129 )
V_36 -> V_135 = V_127 + V_129 ;
V_119:
F_21 ( V_130 ) ;
F_21 ( V_44 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
unsigned int V_127 , const void * V_128 ,
unsigned V_129 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
struct V_43 * V_44 ;
void * V_130 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
V_130 = F_18 ( V_131 , V_53 | V_18 ) ;
if ( ! V_130 )
goto V_119;
if ( V_36 -> V_135 < V_127 )
F_74 ( V_3 , 0 , NULL , V_127 ) ;
memcpy ( & V_36 -> V_134 [ V_127 ] , V_128 , V_129 ) ;
memcpy ( V_130 , V_36 -> V_134 , sizeof( V_36 -> V_134 ) ) ;
V_44 -> V_54 = V_136 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = V_127 + V_129 ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_130 ;
F_32 ( V_36 , V_44 , V_137 ) ;
V_119:
F_21 ( V_130 ) ;
F_21 ( V_44 ) ;
}
static T_9 F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
T_9 V_138 = * V_36 -> V_114 ;
struct V_43 * V_44 ;
if ( V_36 -> V_80 < 1 )
return * V_36 -> V_114 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return V_138 ;
V_44 -> V_54 = V_139 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_36 -> V_114 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_36 -> V_114 ;
F_32 ( V_36 , V_44 , V_140 ) ;
F_21 ( V_44 ) ;
return * V_36 -> V_114 ;
}
static void F_77 ( struct V_2 * V_3 , T_9 V_114 )
{
struct V_1 * V_36 = F_1 ( V_3 ) ;
T_9 V_138 = * V_36 -> V_114 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return;
* V_36 -> V_114 = V_114 ;
V_44 -> V_54 = V_141 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( V_114 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_36 -> V_114 ;
V_39 = F_32 ( V_36 , V_44 , V_142 ) ;
if ( V_39 )
* V_36 -> V_114 = V_138 ;
F_21 ( V_44 ) ;
}
static void F_78 ( struct V_143 * V_144 )
{
struct V_2 * V_63 = F_79 ( V_144 ) ;
struct V_1 * V_36 = F_1 ( V_63 ) ;
F_21 ( V_36 -> V_114 ) ;
F_21 ( V_36 -> V_73 ) ;
F_21 ( V_36 ) ;
}
static int F_80 ( struct V_145 * V_145 )
{
if ( F_81 ( & V_145 -> V_146 ) != 0 )
return 1 ;
if ( F_82 ( & V_145 -> V_146 ) & ~ ( V_147 | V_148 ) )
return 1 ;
if ( F_83 ( & V_145 -> V_146 ) != 0 )
return 1 ;
return 0 ;
}
static struct V_4 * F_84 ( struct V_1 * V_36 ,
int V_72 )
{
struct V_37 * V_7 ;
unsigned long V_9 ;
struct V_4 * V_5 ;
V_5 = NULL ;
F_29 ( & V_36 -> V_10 , V_9 ) ;
F_27 (info, &vcdev->virtqueues, node) {
if ( V_7 -> V_5 -> V_72 == V_72 ) {
V_5 = V_7 -> V_5 ;
break;
}
}
F_31 ( & V_36 -> V_10 , V_9 ) ;
return V_5 ;
}
static void F_85 ( struct V_1 * V_36 ,
T_2 V_149 )
{
if ( V_36 -> V_42 & V_149 ) {
switch ( V_149 ) {
case V_121 :
case V_126 :
case V_133 :
case V_137 :
case V_142 :
case V_140 :
case V_90 :
case V_61 :
case V_113 :
case V_116 :
case V_76 :
case V_60 :
case V_150 :
V_36 -> V_42 &= ~ V_149 ;
F_86 ( & V_36 -> V_48 ) ;
break;
default:
F_47 ( & V_36 -> V_40 -> V_63 ,
L_16 , V_149 ) ;
F_87 ( 1 ) ;
break;
}
}
}
static void F_88 ( struct V_151 * V_40 ,
unsigned long V_45 ,
struct V_145 * V_145 )
{
T_2 V_149 = V_45 & V_46 ;
struct V_1 * V_36 = F_89 ( & V_40 -> V_63 ) ;
int V_8 ;
struct V_4 * V_5 ;
if ( ! V_36 )
return;
if ( F_64 ( V_145 ) ) {
V_36 -> V_41 = F_65 ( V_145 ) ;
F_85 ( V_36 , V_149 ) ;
return;
}
if ( ( V_45 == 0 ) &&
( F_90 ( & V_145 -> V_146 ) ==
( V_152 | V_153 ) ) ) {
}
if ( F_80 ( V_145 ) ) {
if ( ( F_82 ( & V_145 -> V_146 ) & V_154 ) &&
( V_145 -> V_155 [ 0 ] & V_156 ) )
V_36 -> V_41 = - V_106 ;
else
V_36 -> V_41 = - V_157 ;
}
F_85 ( V_36 , V_149 ) ;
F_91 (i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
F_92 ( V_8 , & V_36 -> V_58 ) ;
F_93 () ;
V_5 = F_84 ( V_36 , V_8 ) ;
F_14 ( 0 , V_5 ) ;
}
if ( F_94 ( 0 , & V_36 -> V_111 ) ) {
F_95 ( & V_36 -> V_3 ) ;
F_92 ( 0 , & V_36 -> V_111 ) ;
}
}
static int F_96 ( struct V_151 * V_40 )
{
struct V_158 V_159 ;
F_97 ( V_40 , & V_159 ) ;
if ( F_94 ( V_159 . V_160 , V_161 [ V_159 . V_162 ] ) )
return 0 ;
return 1 ;
}
static void F_98 ( void * V_163 , T_10 V_67 )
{
struct V_151 * V_40 = V_163 ;
int V_39 ;
V_39 = F_99 ( V_40 ) ;
if ( V_39 )
F_47 ( & V_40 -> V_63 , L_17 , V_39 ) ;
}
static int F_100 ( struct V_151 * V_40 )
{
V_40 -> V_22 = F_88 ;
if ( F_96 ( V_40 ) )
F_101 ( F_98 , V_40 ) ;
return 0 ;
}
static struct V_1 * F_102 ( struct V_151 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 ;
F_29 ( F_30 ( V_40 ) , V_9 ) ;
V_36 = F_89 ( & V_40 -> V_63 ) ;
if ( ! V_36 || V_36 -> V_164 ) {
F_31 ( F_30 ( V_40 ) , V_9 ) ;
return NULL ;
}
V_36 -> V_164 = true ;
F_31 ( F_30 ( V_40 ) , V_9 ) ;
return V_36 ;
}
static void F_103 ( struct V_151 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_102 ( V_40 ) ;
if ( V_36 && V_40 -> V_165 ) {
if ( V_36 -> V_166 )
F_104 ( & V_36 -> V_3 ) ;
F_105 ( & V_36 -> V_3 ) ;
F_29 ( F_30 ( V_40 ) , V_9 ) ;
F_106 ( & V_40 -> V_63 , NULL ) ;
F_31 ( F_30 ( V_40 ) , V_9 ) ;
}
V_40 -> V_22 = NULL ;
}
static int F_107 ( struct V_151 * V_40 )
{
unsigned long V_9 ;
struct V_1 * V_36 = F_102 ( V_40 ) ;
if ( ! V_36 )
return 0 ;
if ( V_36 -> V_166 )
F_104 ( & V_36 -> V_3 ) ;
F_105 ( & V_36 -> V_3 ) ;
F_29 ( F_30 ( V_40 ) , V_9 ) ;
F_106 ( & V_40 -> V_63 , NULL ) ;
F_31 ( F_30 ( V_40 ) , V_9 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_36 )
{
struct V_167 * V_168 ;
struct V_43 * V_44 ;
int V_39 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_53 | V_18 ) ;
if ( ! V_44 )
return - V_96 ;
V_168 = F_18 ( sizeof( * V_168 ) , V_53 | V_18 ) ;
if ( ! V_168 ) {
F_21 ( V_44 ) ;
return - V_96 ;
}
V_44 -> V_54 = V_169 ;
V_44 -> V_9 = 0 ;
V_44 -> V_56 = sizeof( * V_168 ) ;
V_44 -> V_57 = ( T_2 ) ( unsigned long ) V_168 ;
V_36 -> V_80 = V_170 ;
do {
V_168 -> V_80 = V_36 -> V_80 ;
V_168 -> V_171 = 0 ;
V_39 = F_32 ( V_36 , V_44 ,
V_150 ) ;
if ( V_39 == - V_106 ) {
if ( V_36 -> V_80 == 0 )
V_39 = 0 ;
else
V_36 -> V_80 -- ;
}
} while ( V_39 == - V_106 );
F_21 ( V_44 ) ;
F_21 ( V_168 ) ;
return V_39 ;
}
static int F_109 ( struct V_151 * V_40 )
{
int V_39 ;
struct V_1 * V_36 ;
unsigned long V_9 ;
V_36 = F_18 ( sizeof( * V_36 ) , V_18 ) ;
if ( ! V_36 ) {
F_47 ( & V_40 -> V_63 , L_18 ) ;
V_39 = - V_96 ;
goto V_119;
}
V_36 -> V_73 = F_18 ( sizeof( * V_36 -> V_73 ) ,
V_53 | V_18 ) ;
if ( ! V_36 -> V_73 ) {
V_39 = - V_96 ;
goto V_119;
}
V_36 -> V_114 = F_18 ( sizeof( * V_36 -> V_114 ) , V_53 | V_18 ) ;
if ( ! V_36 -> V_114 ) {
V_39 = - V_96 ;
goto V_119;
}
V_36 -> V_52 = V_107 ;
V_36 -> V_3 . V_63 . V_172 = & V_40 -> V_63 ;
V_36 -> V_3 . V_63 . V_173 = F_78 ;
V_36 -> V_3 . V_134 = & V_174 ;
V_36 -> V_40 = V_40 ;
F_110 ( & V_36 -> V_48 ) ;
F_111 ( & V_36 -> V_100 ) ;
F_112 ( & V_36 -> V_10 ) ;
F_29 ( F_30 ( V_40 ) , V_9 ) ;
F_106 ( & V_40 -> V_63 , V_36 ) ;
F_31 ( F_30 ( V_40 ) , V_9 ) ;
V_36 -> V_3 . V_159 . V_175 = V_40 -> V_159 . V_176 ;
V_36 -> V_3 . V_159 . V_143 = V_40 -> V_159 . V_177 ;
V_39 = F_108 ( V_36 ) ;
if ( V_39 )
goto V_119;
V_39 = F_113 ( & V_36 -> V_3 ) ;
if ( V_39 ) {
F_47 ( & V_40 -> V_63 , L_19 ,
V_39 ) ;
goto V_178;
}
return 0 ;
V_178:
F_29 ( F_30 ( V_40 ) , V_9 ) ;
F_106 ( & V_40 -> V_63 , NULL ) ;
F_31 ( F_30 ( V_40 ) , V_9 ) ;
F_114 ( & V_36 -> V_3 . V_63 ) ;
return V_39 ;
V_119:
if ( V_36 ) {
F_21 ( V_36 -> V_114 ) ;
F_21 ( V_36 -> V_73 ) ;
}
F_21 ( V_36 ) ;
return V_39 ;
}
static int F_115 ( struct V_151 * V_40 , int V_179 )
{
int V_17 ;
struct V_1 * V_36 = F_89 ( & V_40 -> V_63 ) ;
if ( ! V_36 )
return V_180 ;
switch ( V_179 ) {
case V_181 :
V_36 -> V_166 = true ;
V_17 = V_180 ;
break;
default:
V_17 = V_180 ;
break;
}
return V_17 ;
}
static int T_11 F_116 ( char * * V_182 , unsigned int * V_183 , int V_184 ,
int V_185 , int V_186 )
{
int V_187 ;
V_187 = 0 ;
* V_183 = 0 ;
while ( V_187 <= V_185 ) {
int V_188 = F_117 ( * * V_182 ) ;
if ( V_188 < 0 )
break;
* V_183 = * V_183 * 16 + V_188 ;
( * V_182 ) ++ ;
V_187 ++ ;
}
if ( ( V_187 < V_184 ) || ( V_187 > V_185 ) || ( * V_183 > V_186 ) )
return 1 ;
return 0 ;
}
static int T_11 F_118 ( char * V_189 , unsigned int * V_190 ,
unsigned int * V_162 , unsigned int * V_160 )
{
char * V_191 ;
int V_17 , V_39 ;
V_17 = 1 ;
if ( * V_189 == '\0' )
goto V_101;
V_191 = V_189 ;
V_39 = F_116 ( & V_191 , V_190 , 1 , 2 , V_192 ) ;
if ( V_39 || ( V_191 [ 0 ] != '.' ) )
goto V_101;
V_191 ++ ;
V_39 = F_116 ( & V_191 , V_162 , 1 , 1 , V_193 ) ;
if ( V_39 || ( V_191 [ 0 ] != '.' ) )
goto V_101;
V_191 ++ ;
V_39 = F_116 ( & V_191 , V_160 , 4 , 4 , V_194 ) ;
if ( V_39 || ( V_191 [ 0 ] != '\0' ) )
goto V_101;
V_17 = 0 ;
V_101:
return V_17 ;
}
static void T_11 F_119 ( void )
{
unsigned int V_195 , V_196 , V_197 , V_198 , V_199 , V_200 ;
char * V_201 , * V_189 ;
int V_17 ;
V_189 = V_202 ;
while ( ( V_201 = F_120 ( & V_189 , L_20 ) ) ) {
V_17 = F_118 ( F_120 ( & V_201 , L_21 ) , & V_195 ,
& V_197 , & V_199 ) ;
if ( V_17 )
continue;
if ( V_201 != NULL ) {
V_17 = F_118 ( V_201 , & V_196 ,
& V_198 , & V_200 ) ;
if ( ( V_197 > V_198 ) ||
( ( V_197 == V_198 ) && ( V_199 > V_200 ) ) )
V_17 = - V_123 ;
} else {
V_196 = V_195 ;
V_198 = V_197 ;
V_200 = V_199 ;
}
if ( V_17 )
continue;
while ( ( V_197 < V_198 ) ||
( ( V_197 == V_198 ) && ( V_199 <= V_200 ) ) ) {
F_121 ( V_199 , V_161 [ V_197 ] ) ;
V_199 ++ ;
if ( V_199 > V_194 ) {
V_197 ++ ;
V_199 = 0 ;
}
}
}
}
static int T_11 F_122 ( void )
{
F_119 () ;
return F_123 ( & V_203 ) ;
}
