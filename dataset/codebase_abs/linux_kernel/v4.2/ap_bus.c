static inline int F_1 ( void )
{
return V_1 ;
}
static inline int F_2 ( void )
{
register unsigned long T_1 V_2 ( L_1 ) = F_3 ( 0 , 0 ) ;
register unsigned long T_2 V_2 ( L_2 ) = - V_3 ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(
" .long 0xb2af0000\n"
"0: la %1,0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (reg0), "+d" (reg1), "+d" (reg2) : : "cc" );
return T_2 ;
}
static int F_4 ( void )
{
return F_5 ( 65 ) ;
}
static int F_6 ( void )
{
return F_5 ( 12 ) ;
}
static inline struct V_4
F_7 ( T_4 V_5 , int * V_6 , int * V_7 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
* V_7 = ( int ) ( T_3 >> 24 ) ;
* V_6 = ( int ) ( T_3 & 0xff ) ;
return T_2 ;
}
static inline unsigned long F_8 ( T_4 V_5 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x00800000UL ;
register unsigned long T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
return T_3 ;
}
static inline struct V_4 F_9 ( T_4 V_5 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x01000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
return T_2 ;
}
static inline struct V_4
F_10 ( T_4 V_5 , void * V_8 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x03000000UL ;
register unsigned long T_5 V_2 ( L_2 ) = 0x0000800000000000UL | V_9 ;
register struct V_4 T_6 V_2 ( L_2 ) ;
register void * T_3 V_2 ( L_3 ) = V_8 ;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "+d" (reg1_in), "=d" (reg1_out), "+d" (reg2)
:
: "cc" );
return T_6 ;
}
static inline struct V_4
F_11 ( T_4 V_5 , unsigned int * V_10 )
{
register unsigned long T_1 V_2 ( L_1 ) = 0UL | V_5 | ( 1UL << 23 ) ;
register struct V_4 T_2 V_2 ( L_2 ) = V_11 ;
register unsigned long T_3 V_2 ( L_3 ) ;
asm volatile(
".long 0xb2af0000\n"
"0:\n"
EX_TABLE(0b, 0b)
: "+d" (reg0), "+d" (reg1), "=d" (reg2)
:
: "cc");
* V_10 = ( unsigned int ) ( T_3 >> 32 ) ;
return T_2 ;
}
static inline int F_12 ( struct V_12 * V_13 )
{
register unsigned long T_1 V_2 ( L_1 ) = 0x04000000UL ;
register unsigned long T_2 V_2 ( L_2 ) = - V_14 ;
register unsigned char * T_3 V_2 ( L_3 ) = ( unsigned char * ) V_13 ;
asm volatile(
".long 0xb2af0000\n"
"0: la %1,0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (reg0), "+d" (reg1), "+d" (reg2)
:
: "cc");
return T_2 ;
}
static int F_13 ( T_4 V_5 , unsigned int * V_10 )
{
struct V_4 V_15 ;
V_15 = F_11 ( V_5 , V_10 ) ;
if ( F_14 ( & V_15 ) )
return - V_3 ;
switch ( V_15 . V_16 ) {
case V_17 :
return 0 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return - V_3 ;
case V_22 :
case V_23 :
case V_24 :
default:
return - V_25 ;
}
}
static int F_15 ( struct V_26 * V_27 , void * V_8 )
{
struct V_4 V_15 ;
V_15 = F_10 ( V_27 -> V_5 , V_8 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
case V_24 :
return 0 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return - V_3 ;
case V_22 :
case V_23 :
default:
return - V_25 ;
}
}
static inline struct V_4
F_16 ( T_4 V_5 , unsigned long long V_28 , void * V_29 , T_7 V_30 ,
unsigned int V_31 )
{
typedef struct { char _ [ V_30 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_29 ;
register unsigned long T_9 V_2 ( L_4 ) = ( unsigned long ) V_30 ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned int ) ( V_28 >> 32 ) ;
register unsigned long T_11 V_2 ( L_6 ) = V_28 & 0xffffffff ;
if ( V_31 == 1 )
T_1 |= 0x400000UL ;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc" );
return T_2 ;
}
int F_17 ( T_4 V_5 , unsigned long long V_28 , void * V_29 , T_7 V_30 )
{
struct V_4 V_15 ;
V_15 = F_16 ( V_5 , V_28 , V_29 , V_30 , 0 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
return 0 ;
case V_32 :
case V_22 :
return - V_25 ;
case V_33 :
return - V_14 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_18 ( T_4 V_5 , unsigned long long * V_28 , void * V_29 , T_7 V_30 )
{
typedef struct { char _ [ V_30 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned long ) V_29 ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned long ) V_30 ;
register unsigned long T_12 V_2 ( L_7 ) = 0UL ;
register unsigned long T_13 V_2 ( L_8 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_28 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_19 ( T_4 V_5 , unsigned long long * V_28 , void * V_29 , T_7 V_30 )
{
struct V_4 V_15 ;
V_15 = F_18 ( V_5 , V_28 , V_29 , V_30 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
return 0 ;
case V_34 :
if ( V_15 . V_35 )
return - V_36 ;
return - V_25 ;
case V_22 :
return - V_25 ;
default:
return - V_3 ;
}
}
static inline void F_20 ( void )
{
T_14 V_37 ;
F_21 ( & V_38 ) ;
if ( ! F_22 ( & V_39 ) && ! V_40 ) {
V_37 = F_23 ( 0 , V_41 ) ;
F_24 ( & V_39 , V_37 ) ;
F_25 ( & V_39 ) ;
}
F_26 ( & V_38 ) ;
}
static inline void F_27 ( void )
{
if ( F_1 () )
return;
F_20 () ;
}
static int F_28 ( T_4 V_5 , int * V_6 , int * V_7 )
{
struct V_4 V_15 ;
int V_42 , V_43 ;
V_15 = F_7 ( V_5 , & V_42 , & V_43 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
* V_6 = V_42 + 1 ;
* V_7 = V_43 ;
return 0 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return - V_3 ;
case V_22 :
case V_24 :
case V_23 :
return - V_25 ;
default:
F_29 () ;
}
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_4 V_15 ;
V_15 = F_9 ( V_27 -> V_5 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
V_27 -> V_44 = V_45 ;
V_27 -> V_46 = V_47 ;
return 0 ;
case V_22 :
case V_23 :
return - V_25 ;
case V_18 :
case V_19 :
case V_20 :
default:
return - V_3 ;
}
}
static void F_31 ( struct V_26 * V_27 )
{
int V_48 = V_27 -> V_49 -> V_50 ;
V_27 -> V_51 ++ ;
if ( V_27 -> V_51 == 1 ) {
F_32 ( & V_27 -> V_48 , V_52 + V_48 ) ;
V_27 -> V_46 = V_53 ;
}
}
static void F_33 ( struct V_26 * V_27 )
{
int V_48 = V_27 -> V_49 -> V_50 ;
V_27 -> V_51 -- ;
if ( V_27 -> V_51 > 0 )
F_32 ( & V_27 -> V_48 , V_52 + V_48 ) ;
else
V_27 -> V_46 = V_54 ;
}
static T_15 F_34 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_9 , V_27 -> V_7 ) ;
}
static T_15 F_36 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_9 , V_27 -> V_61 ) ;
}
static T_15 F_37 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_9 , V_27 -> V_6 ) ;
}
static T_15 F_38 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 ;
F_21 ( & V_27 -> V_63 ) ;
V_62 = snprintf ( V_59 , V_60 , L_9 , V_27 -> V_64 ) ;
F_26 ( & V_27 -> V_63 ) ;
return V_62 ;
}
static T_15 F_39 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 ;
F_21 ( & V_27 -> V_63 ) ;
V_62 = snprintf ( V_59 , V_60 , L_9 , V_27 -> V_65 ) ;
F_26 ( & V_27 -> V_63 ) ;
return V_62 ;
}
static T_15 F_40 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 ;
F_21 ( & V_27 -> V_63 ) ;
V_62 = snprintf ( V_59 , V_60 , L_9 , V_27 -> V_66 ) ;
F_26 ( & V_27 -> V_63 ) ;
return V_62 ;
}
static T_15 F_41 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 = 0 ;
F_21 ( & V_27 -> V_63 ) ;
switch ( V_27 -> V_46 ) {
case V_54 :
V_62 = snprintf ( V_59 , V_60 , L_10 ) ;
break;
case V_53 :
V_62 = snprintf ( V_59 , V_60 , L_11 ) ;
break;
case V_67 :
V_62 = snprintf ( V_59 , V_60 , L_12 ) ;
break;
case V_47 :
V_62 = snprintf ( V_59 , V_60 , L_13 ) ;
break;
default:
break;
}
F_26 ( & V_27 -> V_63 ) ;
return V_62 ;
}
static T_15 F_42 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 = 0 ;
F_21 ( & V_27 -> V_63 ) ;
switch ( V_27 -> V_44 ) {
case V_45 :
V_62 = snprintf ( V_59 , V_60 , L_14 ) ;
break;
case V_68 :
V_62 = snprintf ( V_59 , V_60 , L_15 ) ;
break;
case V_69 :
V_62 = snprintf ( V_59 , V_60 , L_16 ) ;
break;
}
F_26 ( & V_27 -> V_63 ) ;
return V_62 ;
}
static T_15 F_43 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
return sprintf ( V_59 , L_17 , F_35 ( V_56 ) -> V_7 ) ;
}
static T_15 F_44 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_18 , V_27 -> V_10 ) ;
}
static int F_45 ( struct V_55 * V_56 , struct V_70 * V_49 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
struct V_71 * V_72 = F_46 ( V_49 ) ;
struct V_73 * V_74 ;
for ( V_74 = V_72 -> V_75 ; V_74 -> V_76 ; V_74 ++ ) {
if ( ( V_74 -> V_76 & V_77 ) &&
( V_74 -> V_78 != V_27 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_47 ( struct V_55 * V_56 , struct V_79 * V_80 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_81 = 0 ;
if ( ! V_27 )
return - V_3 ;
V_81 = F_48 ( V_80 , L_19 , V_27 -> V_7 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_48 ( V_80 , L_20 , V_27 -> V_7 ) ;
return V_81 ;
}
static int F_49 ( struct V_55 * V_56 , T_16 V_82 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
unsigned long V_83 ;
if ( ! V_40 ) {
V_40 = 1 ;
F_50 ( & V_84 ) ;
if ( V_85 != NULL ) {
F_51 ( V_85 ) ;
V_85 = NULL ;
}
F_52 ( & V_86 ) ;
}
do {
V_83 = 0 ;
F_21 ( & V_27 -> V_63 ) ;
F_53 ( V_27 , & V_83 ) ;
F_26 ( & V_27 -> V_63 ) ;
} while ( ( V_83 & 1 ) || ( V_83 & 2 ) );
F_21 ( & V_27 -> V_63 ) ;
V_27 -> V_87 = 1 ;
F_26 ( & V_27 -> V_63 ) ;
return 0 ;
}
static int F_54 ( struct V_55 * V_56 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
int V_62 ;
if ( V_40 ) {
V_40 = 0 ;
if ( F_4 () ) {
if ( ! F_1 () ) {
V_62 = F_55 ( & V_88 ) ;
V_1 = ( V_62 == 0 ) ;
}
} else {
if ( F_1 () ) {
F_56 ( & V_88 ) ;
V_1 = 0 ;
}
}
F_57 () ;
if ( ! V_89 ) {
V_90 = - 1 ;
F_58 () ;
}
F_59 ( & V_84 ) ;
V_84 . V_91 = V_92 ;
V_84 . V_93 = 0 ;
V_84 . V_94 = V_52 + V_95 * V_96 ;
F_60 ( & V_84 ) ;
V_85 = F_61 ( L_21 ) ;
if ( ! V_85 )
return - V_97 ;
F_62 ( & V_86 ) ;
if ( ! F_1 () )
F_27 () ;
else
F_63 ( & V_86 ) ;
if ( V_98 )
V_62 = F_64 () ;
else
V_62 = 0 ;
} else
V_62 = 0 ;
if ( F_65 ( V_27 -> V_5 ) != V_90 ) {
F_21 ( & V_27 -> V_63 ) ;
V_27 -> V_5 = F_3 ( F_66 ( V_27 -> V_5 ) ,
V_90 ) ;
F_26 ( & V_27 -> V_63 ) ;
}
F_67 ( V_85 , & V_99 ) ;
return V_62 ;
}
static int F_68 ( struct V_55 * V_56 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
struct V_71 * V_72 = F_46 ( V_56 -> V_100 ) ;
int V_62 ;
V_27 -> V_49 = V_72 ;
F_21 ( & V_101 ) ;
F_69 ( & V_27 -> V_102 , & V_103 ) ;
F_26 ( & V_101 ) ;
V_62 = V_72 -> V_104 ? V_72 -> V_104 ( V_27 ) : - V_3 ;
if ( V_62 ) {
F_21 ( & V_101 ) ;
F_70 ( & V_27 -> V_102 ) ;
F_26 ( & V_101 ) ;
} else {
if ( V_27 -> V_46 == V_47 ||
V_27 -> V_44 == V_69 )
F_20 () ;
}
return V_62 ;
}
static void F_71 ( struct V_26 * V_27 )
{
struct V_105 * V_106 , * V_107 ;
F_72 (ap_msg, next, &ap_dev->pendingq, list) {
F_70 ( & V_106 -> V_102 ) ;
V_27 -> V_66 -- ;
V_106 -> V_108 ( V_27 , V_106 , F_73 ( - V_3 ) ) ;
}
F_72 (ap_msg, next, &ap_dev->requestq, list) {
F_70 ( & V_106 -> V_102 ) ;
V_27 -> V_65 -- ;
V_106 -> V_108 ( V_27 , V_106 , F_73 ( - V_3 ) ) ;
}
}
void F_74 ( struct V_26 * V_27 )
{
F_21 ( & V_27 -> V_63 ) ;
F_71 ( V_27 ) ;
F_26 ( & V_27 -> V_63 ) ;
}
static int F_75 ( struct V_55 * V_56 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
struct V_71 * V_72 = V_27 -> V_49 ;
F_74 ( V_27 ) ;
F_50 ( & V_27 -> V_48 ) ;
F_21 ( & V_101 ) ;
F_70 ( & V_27 -> V_102 ) ;
F_26 ( & V_101 ) ;
if ( V_72 -> remove )
V_72 -> remove ( V_27 ) ;
F_21 ( & V_27 -> V_63 ) ;
F_76 ( V_27 -> V_51 , & V_109 ) ;
F_26 ( & V_27 -> V_63 ) ;
return 0 ;
}
int F_77 ( struct V_71 * V_72 , struct V_110 * V_111 ,
char * V_112 )
{
struct V_70 * V_49 = & V_72 -> V_100 ;
V_49 -> V_113 = & V_114 ;
V_49 -> V_104 = F_68 ;
V_49 -> remove = F_75 ;
V_49 -> V_111 = V_111 ;
V_49 -> V_112 = V_112 ;
return F_78 ( V_49 ) ;
}
void F_79 ( struct V_71 * V_72 )
{
F_80 ( & V_72 -> V_100 ) ;
}
void F_81 ( void )
{
F_32 ( & V_84 , V_52 + V_95 * V_96 ) ;
F_67 ( V_85 , & V_99 ) ;
F_82 ( & V_99 ) ;
}
static inline int F_83 ( unsigned int * V_115 , unsigned int V_116 )
{
if ( V_116 > 0xFFu )
return 0 ;
return F_84 ( ( V_115 + ( V_116 >> 5 ) ) , ( V_116 & 0x1f ) ) ;
}
static inline int F_85 ( unsigned int V_74 )
{
if ( ! V_117 )
return 1 ;
return F_83 ( V_117 -> V_118 , V_74 ) ;
}
static inline int F_86 ( unsigned int V_119 )
{
if ( ! V_117 )
if ( V_119 < 16 )
return 1 ;
else
return 0 ;
else
return F_83 ( V_117 -> V_120 , V_119 ) ;
}
static T_15 F_87 ( struct V_121 * V_113 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_9 , V_90 ) ;
}
static T_15 F_88 ( struct V_121 * V_113 , char * V_59 )
{
if ( V_117 != NULL ) {
if ( F_5 ( 76 ) ) {
return snprintf ( V_59 , V_60 ,
L_22 ,
V_117 -> V_122 [ 0 ] , V_117 -> V_122 [ 1 ] ,
V_117 -> V_122 [ 2 ] , V_117 -> V_122 [ 3 ] ,
V_117 -> V_122 [ 4 ] , V_117 -> V_122 [ 5 ] ,
V_117 -> V_122 [ 6 ] , V_117 -> V_122 [ 7 ] ) ;
} else {
return snprintf ( V_59 , V_60 , L_23 ,
V_117 -> V_122 [ 0 ] , V_117 -> V_122 [ 1 ] ) ;
}
} else {
return snprintf ( V_59 , V_60 , L_24 ) ;
}
}
static T_15 F_89 ( struct V_121 * V_113 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_9 , V_95 ) ;
}
static T_15 F_90 ( struct V_121 * V_113 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_9 ,
F_1 () ? 1 : 0 ) ;
}
static T_15 F_91 ( struct V_121 * V_113 ,
const char * V_59 , T_7 V_123 )
{
int time ;
if ( sscanf ( V_59 , L_9 , & time ) != 1 || time < 5 || time > 120 )
return - V_14 ;
V_95 = time ;
if ( ! F_92 ( & V_84 ) ||
! F_32 ( & V_84 , V_52 + V_95 * V_96 ) ) {
V_84 . V_94 = V_52 + V_95 * V_96 ;
F_60 ( & V_84 ) ;
}
return V_123 ;
}
static T_15 F_93 ( struct V_121 * V_113 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_9 , V_124 ? 1 : 0 ) ;
}
static T_15 F_94 ( struct V_121 * V_113 ,
const char * V_59 , T_7 V_123 )
{
int V_125 , V_62 ;
if ( sscanf ( V_59 , L_9 , & V_125 ) != 1 )
return - V_14 ;
if ( V_125 ) {
V_62 = F_64 () ;
if ( V_62 )
return V_62 ;
}
else
F_95 () ;
return V_123 ;
}
static T_15 F_96 ( struct V_121 * V_113 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_25 , V_41 ) ;
}
static T_15 F_97 ( struct V_121 * V_113 , const char * V_59 ,
T_7 V_123 )
{
unsigned long long time ;
T_14 V_37 ;
if ( sscanf ( V_59 , L_25 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_14 ;
V_41 = time ;
V_37 = F_23 ( 0 , V_41 ) ;
F_21 ( & V_38 ) ;
F_98 ( & V_39 ) ;
F_99 ( & V_39 , V_37 ) ;
F_100 ( & V_39 , V_126 ) ;
F_26 ( & V_38 ) ;
return V_123 ;
}
static T_15 F_101 ( struct V_121 * V_113 , char * V_59 )
{
T_4 V_5 ;
int V_127 , V_128 , V_129 = - 1 ;
unsigned long V_130 ;
if ( V_117 ) {
if ( V_90 >= 0 && V_90 < V_131 ) {
for ( V_127 = 0 ; V_127 < V_132 ; V_127 ++ ) {
if ( ! F_85 ( V_127 ) )
continue;
V_5 = F_3 ( V_127 , V_90 ) ;
V_130 = F_8 ( V_5 ) ;
if ( V_130 & ( 1UL << 57 ) ) {
V_128 = ( int ) ( ( V_130 & 0x00FF0000UL ) >> 16 ) ;
if ( V_128 > 0 )
V_129 = V_128 ;
else
V_129 = 15 ;
} else {
V_129 = 15 ;
}
break;
}
}
} else {
V_129 = 15 ;
}
return snprintf ( V_59 , V_60 , L_9 , V_129 ) ;
}
static void F_57 ( void )
{
if ( F_6 () ) {
if ( ! V_117 )
V_117 =
F_102 ( sizeof( struct V_12 ) ,
V_133 ) ;
if ( V_117 )
F_12 ( V_117 ) ;
} else
V_117 = NULL ;
}
static int F_58 ( void )
{
int V_6 , V_7 , V_123 , V_134 , V_135 ;
T_4 V_5 ;
int V_62 , V_127 , V_136 ;
if ( ! V_117 -> V_137 && ( V_90 > 15 ) )
return - V_14 ;
if ( V_90 >= 0 && V_90 < V_131 )
return 0 ;
V_135 = - 1 ;
V_134 = 0 ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
if ( ! F_86 ( V_127 ) )
continue;
V_123 = 0 ;
for ( V_136 = 0 ; V_136 < V_132 ; V_136 ++ ) {
if ( ! F_85 ( V_136 ) )
continue;
V_5 = F_3 ( V_136 , V_127 ) ;
V_62 = F_28 ( V_5 , & V_6 , & V_7 ) ;
if ( V_62 )
continue;
V_123 ++ ;
}
if ( V_123 > V_134 ) {
V_134 = V_123 ;
V_135 = V_127 ;
}
}
if ( V_135 >= 0 ) {
V_90 = V_135 ;
return 0 ;
}
return - V_3 ;
}
static int F_103 ( struct V_26 * V_27 )
{
static unsigned char V_29 [] = {
0x00 , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x58 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x01 , 0x00 , 0x43 , 0x43 , 0x41 , 0x2d , 0x41 , 0x50 ,
0x50 , 0x4c , 0x20 , 0x20 , 0x20 , 0x01 , 0x01 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x50 , 0x4b , 0x00 , 0x00 ,
0x00 , 0x00 , 0x01 , 0x1c , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x05 , 0xb8 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x70 , 0x00 , 0x41 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x54 , 0x32 , 0x01 , 0x00 , 0xa0 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0xb8 , 0x05 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x0a , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x08 , 0x00 ,
0x49 , 0x43 , 0x53 , 0x46 , 0x20 , 0x20 , 0x20 , 0x20 ,
0x50 , 0x4b , 0x0a , 0x00 , 0x50 , 0x4b , 0x43 , 0x53 ,
0x2d , 0x31 , 0x2e , 0x32 , 0x37 , 0x00 , 0x11 , 0x22 ,
0x33 , 0x44 , 0x55 , 0x66 , 0x77 , 0x88 , 0x99 , 0x00 ,
0x11 , 0x22 , 0x33 , 0x44 , 0x55 , 0x66 , 0x77 , 0x88 ,
0x99 , 0x00 , 0x11 , 0x22 , 0x33 , 0x44 , 0x55 , 0x66 ,
0x77 , 0x88 , 0x99 , 0x00 , 0x11 , 0x22 , 0x33 , 0x44 ,
0x55 , 0x66 , 0x77 , 0x88 , 0x99 , 0x00 , 0x11 , 0x22 ,
0x33 , 0x44 , 0x55 , 0x66 , 0x77 , 0x88 , 0x99 , 0x00 ,
0x11 , 0x22 , 0x33 , 0x5d , 0x00 , 0x5b , 0x00 , 0x77 ,
0x88 , 0x1e , 0x00 , 0x00 , 0x57 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x04 , 0x00 , 0x00 , 0x4f , 0x00 , 0x00 , 0x00 ,
0x03 , 0x02 , 0x00 , 0x00 , 0x40 , 0x01 , 0x00 , 0x01 ,
0xce , 0x02 , 0x68 , 0x2d , 0x5f , 0xa9 , 0xde , 0x0c ,
0xf6 , 0xd2 , 0x7b , 0x58 , 0x4b , 0xf9 , 0x28 , 0x68 ,
0x3d , 0xb4 , 0xf4 , 0xef , 0x78 , 0xd5 , 0xbe , 0x66 ,
0x63 , 0x42 , 0xef , 0xf8 , 0xfd , 0xa4 , 0xf8 , 0xb0 ,
0x8e , 0x29 , 0xc2 , 0xc9 , 0x2e , 0xd8 , 0x45 , 0xb8 ,
0x53 , 0x8c , 0x6f , 0x4e , 0x72 , 0x8f , 0x6c , 0x04 ,
0x9c , 0x88 , 0xfc , 0x1e , 0xc5 , 0x83 , 0x55 , 0x57 ,
0xf7 , 0xdd , 0xfd , 0x4f , 0x11 , 0x36 , 0x95 , 0x5d ,
} ;
struct V_4 V_15 ;
unsigned long long V_28 ;
char * V_138 ;
int V_62 , V_127 ;
V_138 = ( void * ) F_104 ( V_133 ) ;
if ( ! V_138 ) {
V_62 = - V_97 ;
goto V_139;
}
V_15 = F_16 ( V_27 -> V_5 , 0x0102030405060708ULL ,
V_29 , sizeof( V_29 ) , 0 ) ;
if ( V_15 . V_16 != V_17 ) {
V_62 = - V_3 ;
goto V_140;
}
for ( V_127 = 0 ; V_127 < 6 ; V_127 ++ ) {
F_105 ( 300 ) ;
V_15 = F_18 ( V_27 -> V_5 , & V_28 , V_138 , 4096 ) ;
if ( V_15 . V_16 == V_17 &&
V_28 == 0x0102030405060708ULL )
break;
}
if ( V_127 < 6 ) {
if ( V_138 [ 0 ] == 0x00 && V_138 [ 1 ] == 0x86 )
V_27 -> V_7 = V_141 ;
else
V_27 -> V_7 = V_142 ;
V_62 = 0 ;
} else
V_62 = - V_3 ;
V_140:
F_106 ( ( unsigned long ) V_138 ) ;
V_139:
return V_62 ;
}
static void F_107 ( struct V_143 * V_144 )
{
F_108 ( V_145 ) ;
F_63 ( & V_86 ) ;
}
static int F_109 ( struct V_55 * V_56 , void * V_93 )
{
return F_35 ( V_56 ) -> V_5 == ( T_4 ) ( unsigned long ) V_93 ;
}
static void F_110 ( struct V_55 * V_56 )
{
struct V_26 * V_27 = F_35 ( V_56 ) ;
F_111 ( V_27 ) ;
}
static void F_112 ( struct V_146 * V_147 )
{
struct V_26 * V_27 ;
struct V_55 * V_56 ;
T_4 V_5 ;
int V_6 = 0 , V_7 = 0 ;
unsigned int V_148 ;
int V_62 , V_127 ;
F_57 () ;
if ( F_58 () != 0 ) {
return;
}
for ( V_127 = 0 ; V_127 < V_132 ; V_127 ++ ) {
V_5 = F_3 ( V_127 , V_90 ) ;
V_56 = F_113 ( & V_114 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_109 ) ;
if ( F_85 ( V_127 ) )
V_62 = F_28 ( V_5 , & V_6 , & V_7 ) ;
else
V_62 = - V_3 ;
if ( V_56 ) {
V_27 = F_35 ( V_56 ) ;
F_21 ( & V_27 -> V_63 ) ;
if ( V_62 == - V_3 || V_27 -> V_87 ) {
F_26 ( & V_27 -> V_63 ) ;
if ( V_27 -> V_87 )
V_127 -- ;
F_114 ( V_56 ) ;
F_115 ( V_56 ) ;
continue;
}
F_26 ( & V_27 -> V_63 ) ;
F_115 ( V_56 ) ;
continue;
}
if ( V_62 )
continue;
V_27 = F_102 ( sizeof( * V_27 ) , V_133 ) ;
if ( ! V_27 )
break;
V_27 -> V_5 = V_5 ;
V_62 = F_30 ( V_27 ) ;
if ( ( V_62 != 0 ) && ( V_62 != - V_25 ) ) {
F_111 ( V_27 ) ;
continue;
}
V_27 -> V_6 = V_6 ;
V_27 -> V_87 = 1 ;
F_116 ( & V_27 -> V_63 ) ;
F_117 ( & V_27 -> V_149 ) ;
F_117 ( & V_27 -> V_150 ) ;
F_117 ( & V_27 -> V_102 ) ;
F_118 ( & V_27 -> V_48 , V_151 ,
( unsigned long ) V_27 ) ;
switch ( V_7 ) {
case 0 :
if ( F_103 ( V_27 ) ) {
F_111 ( V_27 ) ;
continue;
}
break;
default:
V_27 -> V_7 = V_7 ;
}
V_27 -> V_61 = V_7 ;
V_62 = F_13 ( V_5 , & V_148 ) ;
if ( ! V_62 )
V_27 -> V_10 = V_148 ;
else
V_27 -> V_10 = 0u ;
V_27 -> V_55 . V_113 = & V_114 ;
V_27 -> V_55 . V_152 = V_153 ;
if ( F_119 ( & V_27 -> V_55 , L_26 ,
F_66 ( V_27 -> V_5 ) ) ) {
F_111 ( V_27 ) ;
continue;
}
V_27 -> V_55 . V_154 = F_110 ;
V_62 = F_120 ( & V_27 -> V_55 ) ;
if ( V_62 ) {
F_115 ( & V_27 -> V_55 ) ;
continue;
}
V_62 = F_121 ( & V_27 -> V_55 . V_155 ,
& V_156 ) ;
if ( ! V_62 ) {
F_21 ( & V_27 -> V_63 ) ;
V_27 -> V_87 = 0 ;
F_26 ( & V_27 -> V_63 ) ;
}
else
F_114 ( & V_27 -> V_55 ) ;
}
}
static void
V_92 ( unsigned long V_157 )
{
F_67 ( V_85 , & V_99 ) ;
V_84 . V_94 = V_52 + V_95 * V_96 ;
F_60 ( & V_84 ) ;
}
static int F_122 ( struct V_26 * V_27 , unsigned long * V_83 )
{
struct V_4 V_15 ;
struct V_105 * V_106 ;
if ( V_27 -> V_51 <= 0 )
return 0 ;
V_15 = F_18 ( V_27 -> V_5 , & V_27 -> V_138 -> V_28 ,
V_27 -> V_138 -> V_158 , V_27 -> V_138 -> V_30 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
V_27 -> V_44 = V_15 . V_159 ;
F_123 ( & V_109 ) ;
F_33 ( V_27 ) ;
F_124 (ap_msg, &ap_dev->pendingq, list) {
if ( V_106 -> V_28 != V_27 -> V_138 -> V_28 )
continue;
F_70 ( & V_106 -> V_102 ) ;
V_27 -> V_66 -- ;
V_106 -> V_108 ( V_27 , V_106 , V_27 -> V_138 ) ;
break;
}
if ( V_27 -> V_51 > 0 )
* V_83 |= 1 ;
break;
case V_34 :
V_27 -> V_44 = V_15 . V_159 ;
if ( V_15 . V_35 ) {
F_76 ( V_27 -> V_51 , & V_109 ) ;
V_27 -> V_51 = 0 ;
F_125 ( & V_27 -> V_149 , & V_27 -> V_150 ) ;
V_27 -> V_65 += V_27 -> V_66 ;
V_27 -> V_66 = 0 ;
} else
* V_83 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_126 ( struct V_26 * V_27 , unsigned long * V_83 )
{
struct V_4 V_15 ;
struct V_105 * V_106 ;
if ( V_27 -> V_65 <= 0 ||
( V_27 -> V_51 >= V_27 -> V_6 ) ||
( V_27 -> V_46 == V_47 ) )
return 0 ;
V_106 = F_127 ( V_27 -> V_150 . V_107 , struct V_105 , V_102 ) ;
V_15 = F_16 ( V_27 -> V_5 , V_106 -> V_28 ,
V_106 -> V_158 , V_106 -> V_30 , V_106 -> V_31 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
F_128 ( & V_109 ) ;
F_31 ( V_27 ) ;
F_129 ( & V_106 -> V_102 , & V_27 -> V_149 ) ;
V_27 -> V_65 -- ;
V_27 -> V_66 ++ ;
if ( V_27 -> V_51 < V_27 -> V_6 &&
V_27 -> V_65 > 0 )
* V_83 |= 1 ;
* V_83 |= 2 ;
break;
case V_22 :
F_20 () ;
case V_32 :
* V_83 |= 2 ;
break;
case V_160 :
case V_33 :
return - V_14 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_130 ( struct V_26 * V_27 , unsigned long * V_83 )
{
int V_62 , V_161 , type ;
struct V_4 V_15 ;
if ( V_27 -> V_46 == V_47 ) {
V_15 = F_7 ( V_27 -> V_5 , & V_161 , & type ) ;
switch ( V_15 . V_16 ) {
case V_17 :
V_27 -> V_46 = V_54 ;
if ( F_1 () ) {
V_62 = F_15 (
V_27 , V_88 . V_162 ) ;
if ( ! V_62 )
V_27 -> V_44 = V_69 ;
else if ( V_62 == - V_3 ) {
F_131 ( L_27
L_28 , F_66 ( V_27 -> V_5 ) ) ;
return V_62 ;
}
}
case V_23 :
case V_22 :
* V_83 |= V_163 ;
break;
case V_18 :
case V_19 :
case V_20 :
return - V_3 ;
default:
break;
}
}
if ( ( V_27 -> V_46 != V_47 ) &&
( V_27 -> V_44 == V_69 ) ) {
V_15 = F_7 ( V_27 -> V_5 , & V_161 , & type ) ;
if ( F_1 () ) {
if ( V_15 . V_159 == 1 )
V_27 -> V_44 = V_68 ;
else
* V_83 |= V_163 ;
} else
V_27 -> V_44 = V_45 ;
}
V_62 = F_122 ( V_27 , V_83 ) ;
if ( V_62 )
return V_62 ;
return F_126 ( V_27 , V_83 ) ;
}
static int F_132 ( struct V_26 * V_27 , struct V_105 * V_106 )
{
struct V_4 V_15 ;
if ( F_133 ( & V_27 -> V_150 ) &&
( V_27 -> V_51 < V_27 -> V_6 ) &&
( V_27 -> V_46 != V_47 ) ) {
V_15 = F_16 ( V_27 -> V_5 , V_106 -> V_28 ,
V_106 -> V_158 , V_106 -> V_30 ,
V_106 -> V_31 ) ;
switch ( V_15 . V_16 ) {
case V_17 :
F_134 ( & V_106 -> V_102 , & V_27 -> V_149 ) ;
F_128 ( & V_109 ) ;
V_27 -> V_66 ++ ;
F_31 ( V_27 ) ;
V_27 -> V_64 ++ ;
break;
case V_32 :
case V_22 :
F_134 ( & V_106 -> V_102 , & V_27 -> V_150 ) ;
V_27 -> V_65 ++ ;
V_27 -> V_64 ++ ;
return - V_25 ;
case V_33 :
case V_160 :
V_106 -> V_108 ( V_27 , V_106 , F_73 ( - V_14 ) ) ;
return - V_14 ;
default:
V_106 -> V_108 ( V_27 , V_106 , F_73 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_134 ( & V_106 -> V_102 , & V_27 -> V_150 ) ;
V_27 -> V_65 ++ ;
V_27 -> V_64 ++ ;
return - V_25 ;
}
F_27 () ;
return 0 ;
}
void F_135 ( struct V_26 * V_27 , struct V_105 * V_106 )
{
unsigned long V_83 ;
int V_62 ;
F_136 ( ! V_106 -> V_108 ) ;
F_21 ( & V_27 -> V_63 ) ;
if ( ! V_27 -> V_87 ) {
V_62 = F_130 ( V_27 , & V_83 ) ;
if ( ! V_62 )
V_62 = F_132 ( V_27 , V_106 ) ;
if ( ! V_62 )
F_137 ( & V_164 ) ;
if ( V_62 == - V_3 )
V_27 -> V_87 = 1 ;
} else {
V_106 -> V_108 ( V_27 , V_106 , F_73 ( - V_3 ) ) ;
V_62 = - V_3 ;
}
F_26 ( & V_27 -> V_63 ) ;
if ( V_62 == - V_3 )
F_114 ( & V_27 -> V_55 ) ;
}
void F_138 ( struct V_26 * V_27 , struct V_105 * V_106 )
{
struct V_105 * V_165 ;
F_21 ( & V_27 -> V_63 ) ;
if ( ! F_133 ( & V_106 -> V_102 ) ) {
F_124 (tmp, &ap_dev->pendingq, list)
if ( V_165 -> V_28 == V_106 -> V_28 ) {
V_27 -> V_66 -- ;
goto V_166;
}
V_27 -> V_65 -- ;
V_166:
F_70 ( & V_106 -> V_102 ) ;
}
F_26 ( & V_27 -> V_63 ) ;
}
static enum F_25 F_139 ( struct V_167 * V_147 )
{
F_63 ( & V_86 ) ;
return V_168 ;
}
static void F_140 ( struct V_26 * V_27 , unsigned long * V_83 )
{
int V_62 ;
F_76 ( V_27 -> V_51 , & V_109 ) ;
V_27 -> V_51 = 0 ;
F_125 ( & V_27 -> V_149 , & V_27 -> V_150 ) ;
V_27 -> V_65 += V_27 -> V_66 ;
V_27 -> V_66 = 0 ;
V_62 = F_30 ( V_27 ) ;
if ( V_62 == - V_3 )
V_27 -> V_87 = 1 ;
else
* V_83 |= V_163 ;
}
static int F_53 ( struct V_26 * V_27 , unsigned long * V_83 )
{
if ( ! V_27 -> V_87 ) {
if ( F_130 ( V_27 , V_83 ) )
V_27 -> V_87 = 1 ;
if ( V_27 -> V_46 == V_67 )
F_140 ( V_27 , V_83 ) ;
}
return 0 ;
}
static void F_141 ( unsigned long V_169 )
{
unsigned long V_83 ;
struct V_26 * V_27 ;
if ( F_1 () )
F_142 ( V_88 . V_162 , 0 ) ;
do {
V_83 = 0 ;
F_143 ( & V_101 ) ;
F_124 (ap_dev, &ap_device_list, list) {
F_143 ( & V_27 -> V_63 ) ;
F_53 ( V_27 , & V_83 ) ;
F_144 ( & V_27 -> V_63 ) ;
}
F_144 ( & V_101 ) ;
} while ( V_83 & V_170 );
if ( V_83 & V_163 )
F_20 () ;
}
static int F_145 ( void * V_93 )
{
F_146 ( V_171 , V_172 ) ;
unsigned long V_83 ;
int V_173 ;
struct V_26 * V_27 ;
F_147 ( V_172 , V_174 ) ;
while ( 1 ) {
if ( V_40 )
return 0 ;
if ( F_148 () ) {
F_149 () ;
continue;
}
F_150 ( & V_164 , & V_171 ) ;
F_151 ( V_175 ) ;
if ( F_152 () )
break;
V_173 = F_153 ( & V_109 ) ;
if ( V_173 <= 0 )
F_149 () ;
F_151 ( V_176 ) ;
F_154 ( & V_164 , & V_171 ) ;
V_83 = 0 ;
F_21 ( & V_101 ) ;
F_124 (ap_dev, &ap_device_list, list) {
F_143 ( & V_27 -> V_63 ) ;
F_53 ( V_27 , & V_83 ) ;
F_144 ( & V_27 -> V_63 ) ;
}
F_26 ( & V_101 ) ;
}
F_151 ( V_176 ) ;
F_154 ( & V_164 , & V_171 ) ;
return 0 ;
}
static int F_64 ( void )
{
int V_62 ;
if ( F_1 () || V_40 )
return 0 ;
F_155 ( & V_177 ) ;
if ( ! V_124 ) {
V_124 = F_156 ( F_145 , NULL , L_29 ) ;
V_62 = F_157 ( V_124 ) ;
if ( V_62 )
V_124 = NULL ;
}
else
V_62 = 0 ;
F_158 ( & V_177 ) ;
return V_62 ;
}
static void F_95 ( void )
{
F_155 ( & V_177 ) ;
if ( V_124 ) {
F_159 ( V_124 ) ;
V_124 = NULL ;
}
F_158 ( & V_177 ) ;
}
static void V_151 ( unsigned long V_93 )
{
struct V_26 * V_27 = (struct V_26 * ) V_93 ;
if ( V_27 -> V_46 == V_53 ) {
V_27 -> V_46 = V_67 ;
if ( F_1 () )
F_63 ( & V_86 ) ;
}
}
static void F_160 ( void )
{
int V_127 ;
if ( ( V_90 != - 1 ) && ( F_86 ( V_90 ) ) )
for ( V_127 = 0 ; V_127 < V_132 ; V_127 ++ )
F_9 ( F_3 ( V_127 , V_90 ) ) ;
}
static void F_161 ( void )
{
int V_127 , V_136 ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
if ( ! F_86 ( V_127 ) )
continue;
for ( V_136 = 0 ; V_136 < V_132 ; V_136 ++ ) {
if ( ! F_85 ( V_136 ) )
continue;
F_9 ( F_3 ( V_136 , V_127 ) ) ;
}
}
}
int T_17 F_162 ( void )
{
int V_62 , V_127 ;
if ( V_90 < - 1 || V_90 >= V_131 ) {
F_163 ( L_30 ,
V_90 ) ;
return - V_14 ;
}
if ( V_90 >= 0 )
V_89 = 1 ;
if ( F_2 () != 0 ) {
F_163 ( L_31
L_32 ) ;
return - V_3 ;
}
if ( F_4 () ) {
V_62 = F_55 ( & V_88 ) ;
V_1 = ( V_62 == 0 ) ;
}
F_164 ( & V_178 ) ;
V_62 = F_165 ( & V_114 ) ;
if ( V_62 )
goto V_139;
for ( V_127 = 0 ; V_179 [ V_127 ] ; V_127 ++ ) {
V_62 = F_166 ( & V_114 , V_179 [ V_127 ] ) ;
if ( V_62 )
goto V_180;
}
V_153 = F_167 ( L_33 ) ;
V_62 = F_157 ( V_153 ) ;
if ( V_62 )
goto V_180;
V_85 = F_61 ( L_21 ) ;
if ( ! V_85 ) {
V_62 = - V_97 ;
goto V_181;
}
F_57 () ;
if ( F_58 () == 0 )
F_112 ( NULL ) ;
F_59 ( & V_84 ) ;
V_84 . V_91 = V_92 ;
V_84 . V_93 = 0 ;
V_84 . V_94 = V_52 + V_95 * V_96 ;
F_60 ( & V_84 ) ;
if ( V_182 )
V_41 = 1500000 ;
F_116 ( & V_38 ) ;
F_168 ( & V_39 , V_183 , V_126 ) ;
V_39 . V_91 = F_139 ;
if ( V_98 ) {
V_62 = F_64 () ;
if ( V_62 )
goto V_184;
}
return 0 ;
V_184:
F_50 ( & V_84 ) ;
F_98 ( & V_39 ) ;
F_51 ( V_85 ) ;
V_181:
F_169 ( V_153 ) ;
V_180:
while ( V_127 -- )
F_170 ( & V_114 , V_179 [ V_127 ] ) ;
F_171 ( & V_114 ) ;
V_139:
F_172 ( & V_178 ) ;
if ( F_1 () )
F_56 ( & V_88 ) ;
return V_62 ;
}
static int F_173 ( struct V_55 * V_56 , void * V_93 )
{
return 1 ;
}
void F_174 ( void )
{
int V_127 ;
struct V_55 * V_56 ;
F_160 () ;
F_95 () ;
F_50 ( & V_84 ) ;
F_98 ( & V_39 ) ;
F_51 ( V_85 ) ;
F_175 ( & V_86 ) ;
while ( ( V_56 = F_113 ( & V_114 , NULL , NULL ,
F_173 ) ) )
{
F_114 ( V_56 ) ;
F_115 ( V_56 ) ;
}
for ( V_127 = 0 ; V_179 [ V_127 ] ; V_127 ++ )
F_170 ( & V_114 , V_179 [ V_127 ] ) ;
F_169 ( V_153 ) ;
F_171 ( & V_114 ) ;
F_172 ( & V_178 ) ;
if ( F_1 () )
F_56 ( & V_88 ) ;
}
