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
if ( ! V_7 )
V_4 -> V_10 |= V_5 ;
F_6 ( F_5 ( V_4 -> V_8 ) , V_6 ) ;
F_9 () ;
} while ( V_7 == - V_15 );
F_10 ( V_4 -> V_16 , F_3 ( V_4 , V_5 ) == 0 ) ;
return V_7 ? V_7 : V_4 -> V_9 ;
}
static inline long F_11 ( struct V_17 V_18 ,
unsigned long V_19 )
{
register unsigned long T_2 V_20 ( L_1 ) = V_21 ;
register struct V_17 T_3 V_20 ( L_2 ) = V_18 ;
register unsigned long T_4 V_20 ( L_3 ) = V_19 ;
register long T_5 V_20 ( L_2 ) ;
asm volatile ("diag 2,4,0x500\n"
: "=d" (__rc) : "d" (__nr), "d" (__schid), "d" (__index)
: "memory", "cc");
return T_5 ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
struct V_1 * V_4 ;
struct V_17 V_18 ;
V_4 = F_1 ( V_25 -> V_23 -> V_3 ) ;
F_13 ( V_4 -> V_8 , & V_18 ) ;
F_11 ( V_18 , F_14 ( V_23 ) ) ;
}
static int F_15 ( struct V_1 * V_4 ,
struct V_11 * V_12 , int V_27 )
{
V_4 -> V_28 -> V_27 = V_27 ;
V_12 -> V_29 = V_30 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( struct V_32 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) ( V_4 -> V_28 ) ;
F_7 ( V_4 , V_12 , V_34 ) ;
return V_4 -> V_28 -> V_35 ;
}
static void F_16 ( struct V_22 * V_23 , struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_23 -> V_3 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_6 ;
unsigned long V_36 ;
int V_7 ;
unsigned int V_27 = F_14 ( V_23 ) ;
F_4 ( & V_4 -> V_37 , V_6 ) ;
F_17 ( & V_25 -> V_38 ) ;
F_6 ( & V_4 -> V_37 , V_6 ) ;
V_25 -> V_39 -> V_40 = 0 ;
V_25 -> V_39 -> V_41 = 0 ;
V_25 -> V_39 -> V_27 = V_27 ;
V_25 -> V_39 -> V_35 = 0 ;
V_12 -> V_29 = V_42 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( * V_25 -> V_39 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) ( V_25 -> V_39 ) ;
V_7 = F_7 ( V_4 , V_12 ,
V_43 | V_27 ) ;
if ( V_7 && ( V_7 != - V_44 ) )
F_18 ( & V_23 -> V_3 -> V_45 , L_4 ,
V_7 , V_27 ) ;
F_19 ( V_23 ) ;
V_36 = F_20 ( F_21 ( V_25 -> V_35 , V_46 ) ) ;
F_22 ( V_25 -> V_40 , V_36 ) ;
F_23 ( V_25 -> V_39 ) ;
F_23 ( V_25 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_22 * V_23 , * V_47 ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
F_26 (vq, n, &vdev->vqs, list)
F_16 ( V_23 , V_12 ) ;
F_23 ( V_12 ) ;
}
static struct V_22 * F_27 ( struct V_2 * V_3 ,
int V_50 , T_6 * V_51 ,
const char * V_52 ,
struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 ;
unsigned long V_36 = 0 ;
unsigned long V_6 ;
V_25 = F_25 ( sizeof( struct V_24 ) , V_49 ) ;
if ( ! V_25 ) {
F_18 ( & V_4 -> V_8 -> V_45 , L_5 ) ;
V_9 = - V_53 ;
goto V_54;
}
V_25 -> V_39 = F_25 ( sizeof( * V_25 -> V_39 ) ,
V_48 | V_49 ) ;
if ( ! V_25 -> V_39 ) {
F_18 ( & V_4 -> V_8 -> V_45 , L_6 ) ;
V_9 = - V_53 ;
goto V_54;
}
V_25 -> V_35 = F_15 ( V_4 , V_12 , V_50 ) ;
V_36 = F_20 ( F_21 ( V_25 -> V_35 , V_46 ) ) ;
V_25 -> V_40 = F_28 ( V_36 , V_49 | V_55 ) ;
if ( V_25 -> V_40 == NULL ) {
F_18 ( & V_4 -> V_8 -> V_45 , L_7 ) ;
V_9 = - V_53 ;
goto V_54;
}
V_23 = F_29 ( V_50 , V_25 -> V_35 , V_46 , V_3 ,
true , V_25 -> V_40 , F_12 ,
V_51 , V_52 ) ;
if ( ! V_23 ) {
F_18 ( & V_4 -> V_8 -> V_45 , L_8 ) ;
V_9 = - V_53 ;
goto V_54;
}
V_25 -> V_39 -> V_40 = ( V_56 ) V_25 -> V_40 ;
V_25 -> V_39 -> V_41 = V_46 ;
V_25 -> V_39 -> V_27 = V_50 ;
V_25 -> V_39 -> V_35 = V_25 -> V_35 ;
V_12 -> V_29 = V_42 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( * V_25 -> V_39 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) ( V_25 -> V_39 ) ;
V_9 = F_7 ( V_4 , V_12 , V_43 | V_50 ) ;
if ( V_9 ) {
F_18 ( & V_4 -> V_8 -> V_45 , L_9 ) ;
goto V_54;
}
V_25 -> V_23 = V_23 ;
V_23 -> V_26 = V_25 ;
F_4 ( & V_4 -> V_37 , V_6 ) ;
F_30 ( & V_25 -> V_38 , & V_4 -> V_57 ) ;
F_6 ( & V_4 -> V_37 , V_6 ) ;
return V_23 ;
V_54:
if ( V_23 )
F_19 ( V_23 ) ;
if ( V_25 ) {
if ( V_25 -> V_40 )
F_22 ( V_25 -> V_40 , V_36 ) ;
F_23 ( V_25 -> V_39 ) ;
}
F_23 ( V_25 ) ;
return F_31 ( V_9 ) ;
}
static int F_32 ( struct V_2 * V_3 , unsigned V_58 ,
struct V_22 * V_59 [] ,
T_6 * V_60 [] ,
const char * V_61 [] )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long * V_62 = NULL ;
int V_7 , V_50 ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return - V_53 ;
for ( V_50 = 0 ; V_50 < V_58 ; ++ V_50 ) {
V_59 [ V_50 ] = F_27 ( V_3 , V_50 , V_60 [ V_50 ] , V_61 [ V_50 ] ,
V_12 ) ;
if ( F_33 ( V_59 [ V_50 ] ) ) {
V_7 = F_34 ( V_59 [ V_50 ] ) ;
V_59 [ V_50 ] = NULL ;
goto V_63;
}
}
V_7 = - V_53 ;
V_62 = F_35 ( sizeof( & V_4 -> V_64 ) , V_48 | V_49 ) ;
if ( ! V_62 )
goto V_63;
* V_62 = ( unsigned long ) & V_4 -> V_64 ;
V_4 -> V_64 = 0 ;
V_12 -> V_29 = V_65 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( V_4 -> V_64 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_62 ;
V_7 = F_7 ( V_4 , V_12 , V_66 ) ;
if ( V_7 )
goto V_63;
* V_62 = ( unsigned long ) & V_4 -> V_67 ;
V_4 -> V_67 = 0 ;
V_12 -> V_29 = V_68 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( V_4 -> V_67 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_62 ;
V_7 = F_7 ( V_4 , V_12 , V_69 ) ;
if ( V_7 )
goto V_63;
F_23 ( V_62 ) ;
F_23 ( V_12 ) ;
return 0 ;
V_63:
F_23 ( V_62 ) ;
F_23 ( V_12 ) ;
F_24 ( V_3 ) ;
return V_7 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
* V_4 -> V_70 = 0 ;
V_12 -> V_29 = V_71 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = 0 ;
V_12 -> V_33 = 0 ;
F_7 ( V_4 , V_12 , V_72 ) ;
F_23 ( V_12 ) ;
}
static T_7 F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_73 * V_74 ;
int V_7 , V_75 ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return 0 ;
V_74 = F_25 ( sizeof( * V_74 ) , V_48 | V_49 ) ;
if ( ! V_74 ) {
V_75 = 0 ;
goto V_76;
}
V_74 -> V_27 = 0 ;
V_12 -> V_29 = V_77 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( * V_74 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_74 ;
V_7 = F_7 ( V_4 , V_12 , V_78 ) ;
if ( V_7 ) {
V_75 = 0 ;
goto V_76;
}
V_75 = F_38 ( V_74 -> V_74 ) ;
V_76:
F_23 ( V_74 ) ;
F_23 ( V_12 ) ;
return V_75 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_73 * V_74 ;
int V_50 ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
V_74 = F_25 ( sizeof( * V_74 ) , V_48 | V_49 ) ;
if ( ! V_74 )
goto V_76;
F_40 ( V_3 ) ;
for ( V_50 = 0 ; V_50 < sizeof( * V_3 -> V_74 ) / sizeof( V_74 -> V_74 ) ;
V_50 ++ ) {
int V_79 = V_50 % 2 ? 32 : 0 ;
V_74 -> V_27 = V_50 ;
V_74 -> V_74 = F_41 ( V_3 -> V_74 [ V_50 / 2 ]
>> V_79 ) ;
V_12 -> V_29 = V_80 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( * V_74 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_74 ;
F_7 ( V_4 , V_12 , V_81 ) ;
}
V_76:
F_23 ( V_74 ) ;
F_23 ( V_12 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
unsigned int V_82 , void * V_83 , unsigned V_84 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
struct V_11 * V_12 ;
void * V_85 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
V_85 = F_25 ( V_86 , V_48 | V_49 ) ;
if ( ! V_85 )
goto V_76;
V_12 -> V_29 = V_87 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = V_82 + V_84 ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_85 ;
V_7 = F_7 ( V_4 , V_12 , V_88 ) ;
if ( V_7 )
goto V_76;
memcpy ( V_4 -> V_89 , V_85 , sizeof( V_4 -> V_89 ) ) ;
memcpy ( V_83 , & V_4 -> V_89 [ V_82 ] , V_84 ) ;
V_76:
F_23 ( V_85 ) ;
F_23 ( V_12 ) ;
}
static void F_43 ( struct V_2 * V_3 ,
unsigned int V_82 , const void * V_83 ,
unsigned V_84 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
void * V_85 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
V_85 = F_25 ( V_86 , V_48 | V_49 ) ;
if ( ! V_85 )
goto V_76;
memcpy ( & V_4 -> V_89 [ V_82 ] , V_83 , V_84 ) ;
memcpy ( V_85 , V_4 -> V_89 , sizeof( V_4 -> V_89 ) ) ;
V_12 -> V_29 = V_90 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = V_82 + V_84 ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_85 ;
F_7 ( V_4 , V_12 , V_91 ) ;
V_76:
F_23 ( V_85 ) ;
F_23 ( V_12 ) ;
}
static T_8 F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return * V_4 -> V_70 ;
}
static void F_45 ( struct V_2 * V_3 , T_8 V_70 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_48 | V_49 ) ;
if ( ! V_12 )
return;
* V_4 -> V_70 = V_70 ;
V_12 -> V_29 = V_92 ;
V_12 -> V_6 = 0 ;
V_12 -> V_31 = sizeof( V_70 ) ;
V_12 -> V_33 = ( T_1 ) ( unsigned long ) V_4 -> V_70 ;
F_7 ( V_4 , V_12 , V_93 ) ;
F_23 ( V_12 ) ;
}
static void F_46 ( struct V_94 * V_95 )
{
struct V_2 * V_45 = F_2 ( V_95 , struct V_2 ,
V_45 ) ;
struct V_1 * V_4 = F_1 ( V_45 ) ;
F_23 ( V_4 -> V_70 ) ;
F_23 ( V_4 -> V_28 ) ;
F_23 ( V_4 ) ;
}
static int F_47 ( struct V_96 * V_96 )
{
if ( F_48 ( & V_96 -> V_97 ) != 0 )
return 1 ;
if ( F_49 ( & V_96 -> V_97 ) & ~ ( V_98 | V_99 ) )
return 1 ;
if ( F_50 ( & V_96 -> V_97 ) != 0 )
return 1 ;
return 0 ;
}
static struct V_22 * F_51 ( struct V_1 * V_4 ,
int V_27 )
{
struct V_24 * V_25 ;
unsigned long V_6 ;
struct V_22 * V_23 ;
V_23 = NULL ;
F_4 ( & V_4 -> V_37 , V_6 ) ;
F_52 (info, &vcdev->virtqueues, node) {
if ( F_14 ( V_25 -> V_23 ) == V_27 ) {
V_23 = V_25 -> V_23 ;
break;
}
}
F_6 ( & V_4 -> V_37 , V_6 ) ;
return V_23 ;
}
static void F_53 ( struct V_100 * V_8 ,
unsigned long V_13 ,
struct V_96 * V_96 )
{
T_1 V_101 = V_13 & V_14 ;
struct V_1 * V_4 = F_54 ( & V_8 -> V_45 ) ;
int V_50 ;
struct V_22 * V_23 ;
struct V_102 * V_103 ;
if ( ( V_13 == 0 ) &&
( F_55 ( & V_96 -> V_97 ) ==
( V_104 | V_105 ) ) ) {
}
if ( F_47 ( V_96 ) )
V_4 -> V_9 = - V_106 ;
if ( V_4 -> V_10 & V_101 ) {
switch ( V_101 ) {
case V_78 :
case V_81 :
case V_88 :
case V_91 :
case V_93 :
case V_43 :
case V_66 :
case V_69 :
case V_72 :
case V_34 :
V_4 -> V_10 &= ~ V_101 ;
F_56 ( & V_4 -> V_16 ) ;
break;
default:
F_18 ( & V_8 -> V_45 , L_10 ,
V_101 ) ;
F_57 ( 1 ) ;
break;
}
}
F_58 (i, &vcdev->indicators,
sizeof(vcdev->indicators) * BITS_PER_BYTE) {
F_59 ( V_50 , & V_4 -> V_64 ) ;
F_60 () ;
V_23 = F_51 ( V_4 , V_50 ) ;
F_61 ( 0 , V_23 ) ;
}
if ( F_62 ( 0 , & V_4 -> V_67 ) ) {
V_103 = F_2 ( V_4 -> V_3 . V_45 . V_107 ,
struct V_102 , V_107 ) ;
if ( V_103 && V_103 -> V_108 )
V_103 -> V_108 ( & V_4 -> V_3 ) ;
F_59 ( 0 , & V_4 -> V_67 ) ;
}
}
static int F_63 ( struct V_100 * V_8 )
{
struct V_109 V_110 ;
F_64 ( V_8 , & V_110 ) ;
if ( F_62 ( V_110 . V_111 , V_112 [ V_110 . V_113 ] ) )
return 0 ;
return 1 ;
}
static void F_65 ( void * V_114 , T_9 V_115 )
{
struct V_100 * V_8 = V_114 ;
int V_7 ;
V_7 = F_66 ( V_8 ) ;
if ( V_7 )
F_18 ( & V_8 -> V_45 , L_11 , V_7 ) ;
}
static int F_67 ( struct V_100 * V_8 )
{
V_8 -> V_116 = F_53 ;
if ( F_63 ( V_8 ) )
F_68 ( F_65 , V_8 ) ;
return 0 ;
}
static void F_69 ( struct V_100 * V_8 )
{
struct V_1 * V_4 = F_54 ( & V_8 -> V_45 ) ;
if ( V_8 -> V_117 ) {
F_70 ( & V_4 -> V_3 ) ;
F_71 ( & V_8 -> V_45 , NULL ) ;
}
V_8 -> V_116 = NULL ;
}
static int F_72 ( struct V_100 * V_8 )
{
struct V_1 * V_4 = F_54 ( & V_8 -> V_45 ) ;
F_70 ( & V_4 -> V_3 ) ;
F_71 ( & V_8 -> V_45 , NULL ) ;
return 0 ;
}
static int F_73 ( struct V_100 * V_8 )
{
int V_7 ;
struct V_1 * V_4 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 ) {
F_18 ( & V_8 -> V_45 , L_12 ) ;
V_7 = - V_53 ;
goto V_76;
}
V_4 -> V_28 = F_25 ( sizeof( * V_4 -> V_28 ) ,
V_48 | V_49 ) ;
if ( ! V_4 -> V_28 ) {
V_7 = - V_53 ;
goto V_76;
}
V_4 -> V_70 = F_25 ( sizeof( * V_4 -> V_70 ) , V_48 | V_49 ) ;
if ( ! V_4 -> V_70 ) {
V_7 = - V_53 ;
goto V_76;
}
V_4 -> V_3 . V_45 . V_118 = & V_8 -> V_45 ;
V_4 -> V_3 . V_45 . V_119 = F_46 ;
V_4 -> V_3 . V_89 = & V_120 ;
V_4 -> V_8 = V_8 ;
F_74 ( & V_4 -> V_16 ) ;
F_75 ( & V_4 -> V_57 ) ;
F_76 ( & V_4 -> V_37 ) ;
F_71 ( & V_8 -> V_45 , V_4 ) ;
V_4 -> V_3 . V_110 . V_121 = V_8 -> V_110 . V_122 ;
V_4 -> V_3 . V_110 . V_94 = V_8 -> V_110 . V_123 ;
V_7 = F_77 ( & V_4 -> V_3 ) ;
if ( V_7 ) {
F_18 ( & V_8 -> V_45 , L_13 ,
V_7 ) ;
goto V_124;
}
return 0 ;
V_124:
F_71 ( & V_8 -> V_45 , NULL ) ;
F_78 ( & V_4 -> V_3 . V_45 ) ;
return V_7 ;
V_76:
if ( V_4 ) {
F_23 ( V_4 -> V_70 ) ;
F_23 ( V_4 -> V_28 ) ;
}
F_23 ( V_4 ) ;
return V_7 ;
}
static int F_79 ( struct V_100 * V_8 , int V_125 )
{
return 0 ;
}
static int T_10 F_80 ( char * * V_126 , unsigned int * V_127 , int V_128 ,
int V_129 , int V_130 )
{
int V_131 ;
V_131 = 0 ;
* V_127 = 0 ;
while ( V_131 <= V_129 ) {
int V_132 = F_81 ( * * V_126 ) ;
if ( V_132 < 0 )
break;
* V_127 = * V_127 * 16 + V_132 ;
( * V_126 ) ++ ;
V_131 ++ ;
}
if ( ( V_131 < V_128 ) || ( V_131 > V_129 ) || ( * V_127 > V_130 ) )
return 1 ;
return 0 ;
}
static int T_10 F_82 ( char * V_133 , unsigned int * V_134 ,
unsigned int * V_113 , unsigned int * V_111 )
{
char * V_135 ;
int V_75 , V_7 ;
V_75 = 1 ;
if ( * V_133 == '\0' )
goto V_63;
V_135 = V_133 ;
V_7 = F_80 ( & V_135 , V_134 , 1 , 2 , V_136 ) ;
if ( V_7 || ( V_135 [ 0 ] != '.' ) )
goto V_63;
V_135 ++ ;
V_7 = F_80 ( & V_135 , V_113 , 1 , 1 , V_137 ) ;
if ( V_7 || ( V_135 [ 0 ] != '.' ) )
goto V_63;
V_135 ++ ;
V_7 = F_80 ( & V_135 , V_111 , 4 , 4 , V_138 ) ;
if ( V_7 || ( V_135 [ 0 ] != '\0' ) )
goto V_63;
V_75 = 0 ;
V_63:
return V_75 ;
}
static void T_10 F_83 ( void )
{
unsigned int V_139 , V_140 , V_141 , V_142 , V_143 , V_144 ;
char * V_145 , * V_133 ;
int V_75 ;
V_133 = V_146 ;
while ( ( V_145 = F_84 ( & V_133 , L_14 ) ) ) {
V_75 = F_82 ( F_84 ( & V_145 , L_15 ) , & V_139 ,
& V_141 , & V_143 ) ;
if ( V_75 )
continue;
if ( V_145 != NULL ) {
V_75 = F_82 ( V_145 , & V_140 ,
& V_142 , & V_144 ) ;
if ( ( V_141 > V_142 ) ||
( ( V_141 == V_142 ) && ( V_143 > V_144 ) ) )
V_75 = - V_147 ;
} else {
V_140 = V_139 ;
V_142 = V_141 ;
V_144 = V_143 ;
}
if ( V_75 )
continue;
while ( ( V_141 < V_142 ) ||
( ( V_141 == V_142 ) && ( V_143 <= V_144 ) ) ) {
F_85 ( V_143 , V_112 [ V_141 ] ) ;
V_143 ++ ;
if ( V_143 > V_138 ) {
V_141 ++ ;
V_143 = 0 ;
}
}
}
}
static int T_10 F_86 ( void )
{
F_83 () ;
return F_87 ( & V_148 ) ;
}
static void T_11 F_88 ( void )
{
F_89 ( & V_148 ) ;
}
