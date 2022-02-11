static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , T_1 V_5 )
{
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( F_5 ( V_4 -> V_8 ) , V_6 ) ;
if ( V_4 -> V_9 )
V_7 = 0 ;
else
V_7 = V_4 -> V_10 & V_5 ;
F_6 ( F_5 ( V_4 -> V_8 ) , V_6 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_4 ,
struct V_11 * V_12 , T_1 V_13 )
{
int V_7 ;
unsigned long V_6 ;
int V_5 = V_13 & V_14 ;
do {
F_4 ( F_5 ( V_4 -> V_8 ) , V_6 ) ;
V_7 = F_8 ( V_4 -> V_8 , V_12 , V_13 , 0 , 0 ) ;
if ( ! V_7 ) {
if ( ! V_4 -> V_10 )
V_4 -> V_9 = 0 ;
V_4 -> V_10 |= V_5 ;
}
F_6 ( F_5 ( V_4 -> V_8 ) , V_6 ) ;
F_9 () ;
} while ( V_7 == - V_15 );
F_10 ( V_4 -> V_16 , F_3 ( V_4 , V_5 ) == 0 ) ;
return V_7 ? V_7 : V_4 -> V_9 ;
}
static inline long F_11 ( struct V_17 V_18 ,
unsigned long V_19 ,
long V_20 )
{
register unsigned long T_2 V_21 ( L_1 ) = V_22 ;
register struct V_17 T_3 V_21 ( L_2 ) = V_18 ;
register unsigned long T_4 V_21 ( L_3 ) = V_19 ;
register long T_5 V_21 ( L_2 ) ;
register long T_6 V_21 ( L_4 ) = V_20 ;
asm volatile ("diag 2,4,0x500\n"
: "=d" (__rc) : "d" (__nr), "d" (__schid), "d" (__index),
"d"(__cookie)
: "memory", "cc");
return T_5 ;
}
static bool F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_4 ;
struct V_17 V_18 ;
V_4 = F_1 ( V_26 -> V_24 -> V_3 ) ;
F_13 ( V_4 -> V_8 , & V_18 ) ;
V_26 -> V_20 = F_11 ( V_18 , V_24 -> V_28 , V_26 -> V_20 ) ;
if ( V_26 -> V_20 < 0 )
return false ;
return true ;
}
static int F_14 ( struct V_1 * V_4 ,
struct V_11 * V_12 , int V_28 )
{
V_4 -> V_29 -> V_28 = V_28 ;
V_12 -> V_30 = V_31 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( struct V_33 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) ( V_4 -> V_29 ) ;
F_7 ( V_4 , V_12 , V_35 ) ;
return V_4 -> V_29 -> V_36 ;
}
static void F_15 ( struct V_23 * V_24 , struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_24 -> V_3 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
unsigned long V_6 ;
unsigned long V_37 ;
int V_7 ;
unsigned int V_28 = V_24 -> V_28 ;
F_4 ( & V_4 -> V_38 , V_6 ) ;
F_16 ( & V_26 -> V_39 ) ;
F_6 ( & V_4 -> V_38 , V_6 ) ;
V_26 -> V_40 -> V_41 = 0 ;
V_26 -> V_40 -> V_42 = 0 ;
V_26 -> V_40 -> V_28 = V_28 ;
V_26 -> V_40 -> V_36 = 0 ;
V_12 -> V_30 = V_43 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( * V_26 -> V_40 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) ( V_26 -> V_40 ) ;
V_7 = F_7 ( V_4 , V_12 ,
V_44 | V_28 ) ;
if ( V_7 && ( V_7 != - V_45 ) )
F_17 ( & V_24 -> V_3 -> V_46 , L_5 ,
V_7 , V_28 ) ;
F_18 ( V_24 ) ;
V_37 = F_19 ( F_20 ( V_26 -> V_36 , V_47 ) ) ;
F_21 ( V_26 -> V_41 , V_37 ) ;
F_22 ( V_26 -> V_40 ) ;
F_22 ( V_26 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_23 * V_24 , * V_48 ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
F_25 (vq, n, &vdev->vqs, list)
F_15 ( V_24 , V_12 ) ;
F_22 ( V_12 ) ;
}
static struct V_23 * F_26 ( struct V_2 * V_3 ,
int V_51 , T_7 * V_52 ,
const char * V_53 ,
struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 ;
unsigned long V_37 = 0 ;
unsigned long V_6 ;
V_26 = F_24 ( sizeof( struct V_25 ) , V_50 ) ;
if ( ! V_26 ) {
F_17 ( & V_4 -> V_8 -> V_46 , L_6 ) ;
V_9 = - V_54 ;
goto V_55;
}
V_26 -> V_40 = F_24 ( sizeof( * V_26 -> V_40 ) ,
V_49 | V_50 ) ;
if ( ! V_26 -> V_40 ) {
F_17 ( & V_4 -> V_8 -> V_46 , L_7 ) ;
V_9 = - V_54 ;
goto V_55;
}
V_26 -> V_36 = F_14 ( V_4 , V_12 , V_51 ) ;
V_37 = F_19 ( F_20 ( V_26 -> V_36 , V_47 ) ) ;
V_26 -> V_41 = F_27 ( V_37 , V_50 | V_56 ) ;
if ( V_26 -> V_41 == NULL ) {
F_17 ( & V_4 -> V_8 -> V_46 , L_8 ) ;
V_9 = - V_54 ;
goto V_55;
}
V_24 = F_28 ( V_51 , V_26 -> V_36 , V_47 , V_3 ,
true , V_26 -> V_41 , F_12 ,
V_52 , V_53 ) ;
if ( ! V_24 ) {
F_17 ( & V_4 -> V_8 -> V_46 , L_9 ) ;
V_9 = - V_54 ;
goto V_55;
}
V_26 -> V_40 -> V_41 = ( V_57 ) V_26 -> V_41 ;
V_26 -> V_40 -> V_42 = V_47 ;
V_26 -> V_40 -> V_28 = V_51 ;
V_26 -> V_40 -> V_36 = V_26 -> V_36 ;
V_12 -> V_30 = V_43 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( * V_26 -> V_40 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) ( V_26 -> V_40 ) ;
V_9 = F_7 ( V_4 , V_12 , V_44 | V_51 ) ;
if ( V_9 ) {
F_17 ( & V_4 -> V_8 -> V_46 , L_10 ) ;
goto V_55;
}
V_26 -> V_24 = V_24 ;
V_24 -> V_27 = V_26 ;
F_4 ( & V_4 -> V_38 , V_6 ) ;
F_29 ( & V_26 -> V_39 , & V_4 -> V_58 ) ;
F_6 ( & V_4 -> V_38 , V_6 ) ;
return V_24 ;
V_55:
if ( V_24 )
F_18 ( V_24 ) ;
if ( V_26 ) {
if ( V_26 -> V_41 )
F_21 ( V_26 -> V_41 , V_37 ) ;
F_22 ( V_26 -> V_40 ) ;
}
F_22 ( V_26 ) ;
return F_30 ( V_9 ) ;
}
static int F_31 ( struct V_2 * V_3 , unsigned V_59 ,
struct V_23 * V_60 [] ,
T_7 * V_61 [] ,
const char * V_62 [] )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long * V_63 = NULL ;
int V_7 , V_51 ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return - V_54 ;
for ( V_51 = 0 ; V_51 < V_59 ; ++ V_51 ) {
V_60 [ V_51 ] = F_26 ( V_3 , V_51 , V_61 [ V_51 ] , V_62 [ V_51 ] ,
V_12 ) ;
if ( F_32 ( V_60 [ V_51 ] ) ) {
V_7 = F_33 ( V_60 [ V_51 ] ) ;
V_60 [ V_51 ] = NULL ;
goto V_64;
}
}
V_7 = - V_54 ;
V_63 = F_34 ( sizeof( & V_4 -> V_65 ) , V_49 | V_50 ) ;
if ( ! V_63 )
goto V_64;
* V_63 = ( unsigned long ) & V_4 -> V_65 ;
V_4 -> V_65 = 0 ;
V_12 -> V_30 = V_66 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( V_4 -> V_65 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_63 ;
V_7 = F_7 ( V_4 , V_12 , V_67 ) ;
if ( V_7 )
goto V_64;
* V_63 = ( unsigned long ) & V_4 -> V_68 ;
V_4 -> V_68 = 0 ;
V_12 -> V_30 = V_69 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( V_4 -> V_68 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_63 ;
V_7 = F_7 ( V_4 , V_12 , V_70 ) ;
if ( V_7 )
goto V_64;
F_22 ( V_63 ) ;
F_22 ( V_12 ) ;
return 0 ;
V_64:
F_22 ( V_63 ) ;
F_22 ( V_12 ) ;
F_23 ( V_3 ) ;
return V_7 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
* V_4 -> V_71 = 0 ;
V_12 -> V_30 = V_72 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = 0 ;
V_12 -> V_34 = 0 ;
F_7 ( V_4 , V_12 , V_73 ) ;
F_22 ( V_12 ) ;
}
static T_8 F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_74 * V_75 ;
int V_7 , V_76 ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return 0 ;
V_75 = F_24 ( sizeof( * V_75 ) , V_49 | V_50 ) ;
if ( ! V_75 ) {
V_76 = 0 ;
goto V_77;
}
V_75 -> V_28 = 0 ;
V_12 -> V_30 = V_78 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( * V_75 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_75 ;
V_7 = F_7 ( V_4 , V_12 , V_79 ) ;
if ( V_7 ) {
V_76 = 0 ;
goto V_77;
}
V_76 = F_37 ( V_75 -> V_75 ) ;
V_77:
F_22 ( V_75 ) ;
F_22 ( V_12 ) ;
return V_76 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_74 * V_75 ;
int V_51 ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
V_75 = F_24 ( sizeof( * V_75 ) , V_49 | V_50 ) ;
if ( ! V_75 )
goto V_77;
F_39 ( V_3 ) ;
for ( V_51 = 0 ; V_51 < sizeof( * V_3 -> V_75 ) / sizeof( V_75 -> V_75 ) ;
V_51 ++ ) {
int V_80 = V_51 % 2 ? 32 : 0 ;
V_75 -> V_28 = V_51 ;
V_75 -> V_75 = F_40 ( V_3 -> V_75 [ V_51 / 2 ]
>> V_80 ) ;
V_12 -> V_30 = V_81 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( * V_75 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_75 ;
F_7 ( V_4 , V_12 , V_82 ) ;
}
V_77:
F_22 ( V_75 ) ;
F_22 ( V_12 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
unsigned int V_83 , void * V_84 , unsigned V_85 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
struct V_11 * V_12 ;
void * V_86 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
V_86 = F_24 ( V_87 , V_49 | V_50 ) ;
if ( ! V_86 )
goto V_77;
V_12 -> V_30 = V_88 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = V_83 + V_85 ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_86 ;
V_7 = F_7 ( V_4 , V_12 , V_89 ) ;
if ( V_7 )
goto V_77;
memcpy ( V_4 -> V_90 , V_86 , sizeof( V_4 -> V_90 ) ) ;
memcpy ( V_84 , & V_4 -> V_90 [ V_83 ] , V_85 ) ;
V_77:
F_22 ( V_86 ) ;
F_22 ( V_12 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
unsigned int V_83 , const void * V_84 ,
unsigned V_85 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
void * V_86 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
V_86 = F_24 ( V_87 , V_49 | V_50 ) ;
if ( ! V_86 )
goto V_77;
memcpy ( & V_4 -> V_90 [ V_83 ] , V_84 , V_85 ) ;
memcpy ( V_86 , V_4 -> V_90 , sizeof( V_4 -> V_90 ) ) ;
V_12 -> V_30 = V_91 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = V_83 + V_85 ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_86 ;
F_7 ( V_4 , V_12 , V_92 ) ;
V_77:
F_22 ( V_86 ) ;
F_22 ( V_12 ) ;
}
static T_9 F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return * V_4 -> V_71 ;
}
static void F_44 ( struct V_2 * V_3 , T_9 V_71 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
V_12 = F_24 ( sizeof( * V_12 ) , V_49 | V_50 ) ;
if ( ! V_12 )
return;
* V_4 -> V_71 = V_71 ;
V_12 -> V_30 = V_93 ;
V_12 -> V_6 = 0 ;
V_12 -> V_32 = sizeof( V_71 ) ;
V_12 -> V_34 = ( T_1 ) ( unsigned long ) V_4 -> V_71 ;
F_7 ( V_4 , V_12 , V_94 ) ;
F_22 ( V_12 ) ;
}
static void F_45 ( struct V_95 * V_96 )
{
struct V_2 * V_46 = F_2 ( V_96 , struct V_2 ,
V_46 ) ;
struct V_1 * V_4 = F_1 ( V_46 ) ;
F_22 ( V_4 -> V_71 ) ;
F_22 ( V_4 -> V_29 ) ;
F_22 ( V_4 ) ;
}
static int F_46 ( struct V_97 * V_97 )
{
if ( F_47 ( & V_97 -> V_98 ) != 0 )
return 1 ;
if ( F_48 ( & V_97 -> V_98 ) & ~ ( V_99 | V_100 ) )
return 1 ;
if ( F_49 ( & V_97 -> V_98 ) != 0 )
return 1 ;
return 0 ;
}
static struct V_23 * F_50 ( struct V_1 * V_4 ,
int V_28 )
{
struct V_25 * V_26 ;
unsigned long V_6 ;
struct V_23 * V_24 ;
V_24 = NULL ;
F_4 ( & V_4 -> V_38 , V_6 ) ;
F_51 (info, &vcdev->virtqueues, node) {
if ( V_26 -> V_24 -> V_28 == V_28 ) {
V_24 = V_26 -> V_24 ;
break;
}
}
F_6 ( & V_4 -> V_38 , V_6 ) ;
return V_24 ;
}
static void F_52 ( struct V_101 * V_8 ,
unsigned long V_13 ,
struct V_97 * V_97 )
{
T_1 V_102 = V_13 & V_14 ;
struct V_1 * V_4 = F_53 ( & V_8 -> V_46 ) ;
int V_51 ;
struct V_23 * V_24 ;
struct V_103 * V_104 ;
if ( ( V_13 == 0 ) &&
( F_54 ( & V_97 -> V_98 ) ==
( V_105 | V_106 ) ) ) {
}
if ( F_46 ( V_97 ) ) {
if ( ( F_48 ( & V_97 -> V_98 ) & V_107 ) &&
( V_97 -> V_108 [ 0 ] & V_109 ) )
V_4 -> V_9 = - V_110 ;
else
V_4 -> V_9 = - V_111 ;
}
if ( V_4 -> V_10 & V_102 ) {
switch ( V_102 ) {
case V_79 :
case V_82 :
case V_89 :
case V_92 :
case V_94 :
case V_44 :
case V_67 :
case V_70 :
case V_73 :
case V_35 :
V_4 -> V_10 &= ~ V_102 ;
F_55 ( & V_4 -> V_16 ) ;
break;
default:
F_17 ( & V_8 -> V_46 , L_11 ,
V_102 ) ;
F_56 ( 1 ) ;
break;
}
}
F_57 (i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
F_58 ( V_51 , & V_4 -> V_65 ) ;
F_59 () ;
V_24 = F_50 ( V_4 , V_51 ) ;
F_60 ( 0 , V_24 ) ;
}
if ( F_61 ( 0 , & V_4 -> V_68 ) ) {
V_104 = F_2 ( V_4 -> V_3 . V_46 . V_112 ,
struct V_103 , V_112 ) ;
if ( V_104 && V_104 -> V_113 )
V_104 -> V_113 ( & V_4 -> V_3 ) ;
F_58 ( 0 , & V_4 -> V_68 ) ;
}
}
static int F_62 ( struct V_101 * V_8 )
{
struct V_114 V_115 ;
F_63 ( V_8 , & V_115 ) ;
if ( F_61 ( V_115 . V_116 , V_117 [ V_115 . V_118 ] ) )
return 0 ;
return 1 ;
}
static void F_64 ( void * V_119 , T_10 V_20 )
{
struct V_101 * V_8 = V_119 ;
int V_7 ;
V_7 = F_65 ( V_8 ) ;
if ( V_7 )
F_17 ( & V_8 -> V_46 , L_12 , V_7 ) ;
}
static int F_66 ( struct V_101 * V_8 )
{
V_8 -> V_120 = F_52 ;
if ( F_62 ( V_8 ) )
F_67 ( F_64 , V_8 ) ;
return 0 ;
}
static void F_68 ( struct V_101 * V_8 )
{
struct V_1 * V_4 = F_53 ( & V_8 -> V_46 ) ;
if ( V_8 -> V_121 ) {
F_69 ( & V_4 -> V_3 ) ;
F_70 ( & V_8 -> V_46 , NULL ) ;
}
V_8 -> V_120 = NULL ;
}
static int F_71 ( struct V_101 * V_8 )
{
struct V_1 * V_4 = F_53 ( & V_8 -> V_46 ) ;
F_69 ( & V_4 -> V_3 ) ;
F_70 ( & V_8 -> V_46 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_101 * V_8 )
{
int V_7 ;
struct V_1 * V_4 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 ) {
F_17 ( & V_8 -> V_46 , L_13 ) ;
V_7 = - V_54 ;
goto V_77;
}
V_4 -> V_29 = F_24 ( sizeof( * V_4 -> V_29 ) ,
V_49 | V_50 ) ;
if ( ! V_4 -> V_29 ) {
V_7 = - V_54 ;
goto V_77;
}
V_4 -> V_71 = F_24 ( sizeof( * V_4 -> V_71 ) , V_49 | V_50 ) ;
if ( ! V_4 -> V_71 ) {
V_7 = - V_54 ;
goto V_77;
}
V_4 -> V_3 . V_46 . V_122 = & V_8 -> V_46 ;
V_4 -> V_3 . V_46 . V_123 = F_45 ;
V_4 -> V_3 . V_90 = & V_124 ;
V_4 -> V_8 = V_8 ;
F_73 ( & V_4 -> V_16 ) ;
F_74 ( & V_4 -> V_58 ) ;
F_75 ( & V_4 -> V_38 ) ;
F_70 ( & V_8 -> V_46 , V_4 ) ;
V_4 -> V_3 . V_115 . V_125 = V_8 -> V_115 . V_126 ;
V_4 -> V_3 . V_115 . V_95 = V_8 -> V_115 . V_127 ;
V_7 = F_76 ( & V_4 -> V_3 ) ;
if ( V_7 ) {
F_17 ( & V_8 -> V_46 , L_14 ,
V_7 ) ;
goto V_128;
}
return 0 ;
V_128:
F_70 ( & V_8 -> V_46 , NULL ) ;
F_77 ( & V_4 -> V_3 . V_46 ) ;
return V_7 ;
V_77:
if ( V_4 ) {
F_22 ( V_4 -> V_71 ) ;
F_22 ( V_4 -> V_29 ) ;
}
F_22 ( V_4 ) ;
return V_7 ;
}
static int F_78 ( struct V_101 * V_8 , int V_129 )
{
return 0 ;
}
static int T_11 F_79 ( char * * V_130 , unsigned int * V_131 , int V_132 ,
int V_133 , int V_134 )
{
int V_135 ;
V_135 = 0 ;
* V_131 = 0 ;
while ( V_135 <= V_133 ) {
int V_136 = F_80 ( * * V_130 ) ;
if ( V_136 < 0 )
break;
* V_131 = * V_131 * 16 + V_136 ;
( * V_130 ) ++ ;
V_135 ++ ;
}
if ( ( V_135 < V_132 ) || ( V_135 > V_133 ) || ( * V_131 > V_134 ) )
return 1 ;
return 0 ;
}
static int T_11 F_81 ( char * V_137 , unsigned int * V_138 ,
unsigned int * V_118 , unsigned int * V_116 )
{
char * V_139 ;
int V_76 , V_7 ;
V_76 = 1 ;
if ( * V_137 == '\0' )
goto V_64;
V_139 = V_137 ;
V_7 = F_79 ( & V_139 , V_138 , 1 , 2 , V_140 ) ;
if ( V_7 || ( V_139 [ 0 ] != '.' ) )
goto V_64;
V_139 ++ ;
V_7 = F_79 ( & V_139 , V_118 , 1 , 1 , V_141 ) ;
if ( V_7 || ( V_139 [ 0 ] != '.' ) )
goto V_64;
V_139 ++ ;
V_7 = F_79 ( & V_139 , V_116 , 4 , 4 , V_142 ) ;
if ( V_7 || ( V_139 [ 0 ] != '\0' ) )
goto V_64;
V_76 = 0 ;
V_64:
return V_76 ;
}
static void T_11 F_82 ( void )
{
unsigned int V_143 , V_144 , V_145 , V_146 , V_147 , V_148 ;
char * V_149 , * V_137 ;
int V_76 ;
V_137 = V_150 ;
while ( ( V_149 = F_83 ( & V_137 , L_15 ) ) ) {
V_76 = F_81 ( F_83 ( & V_149 , L_16 ) , & V_143 ,
& V_145 , & V_147 ) ;
if ( V_76 )
continue;
if ( V_149 != NULL ) {
V_76 = F_81 ( V_149 , & V_144 ,
& V_146 , & V_148 ) ;
if ( ( V_145 > V_146 ) ||
( ( V_145 == V_146 ) && ( V_147 > V_148 ) ) )
V_76 = - V_151 ;
} else {
V_144 = V_143 ;
V_146 = V_145 ;
V_148 = V_147 ;
}
if ( V_76 )
continue;
while ( ( V_145 < V_146 ) ||
( ( V_145 == V_146 ) && ( V_147 <= V_148 ) ) ) {
F_84 ( V_147 , V_117 [ V_145 ] ) ;
V_147 ++ ;
if ( V_147 > V_142 ) {
V_145 ++ ;
V_147 = 0 ;
}
}
}
}
static int T_11 F_85 ( void )
{
F_82 () ;
return F_86 ( & V_152 ) ;
}
static void T_12 F_87 ( void )
{
F_88 ( & V_152 ) ;
}
