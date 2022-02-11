static inline int F_1 ( void )
{
return V_1 != NULL ;
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
return F_5 ( 2 ) && F_5 ( 65 ) ;
}
static inline struct V_4
F_6 ( T_4 V_5 , int * V_6 , int * V_7 )
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
static inline struct V_4 F_7 ( T_4 V_5 )
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
F_8 ( T_4 V_5 , void * V_8 )
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
F_9 ( T_4 V_5 , unsigned int * V_10 )
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
static int F_10 ( T_4 V_5 , unsigned int * V_10 )
{
#ifdef F_11
struct V_4 V_12 ;
int V_13 ;
V_12 = F_9 ( V_5 , V_10 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( F_12 ( & V_12 ) )
return - V_3 ;
switch ( V_12 . V_15 ) {
case V_16 :
return 0 ;
case V_17 :
case V_18 :
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return - V_3 ;
case V_23 :
break;
default:
break;
}
if ( V_13 < V_14 - 1 ) {
F_13 ( 5 ) ;
V_12 = F_9 ( V_5 , V_10 ) ;
}
}
return - V_24 ;
#else
return - V_25 ;
#endif
}
int F_14 ( T_4 V_5 )
{
unsigned int V_10 ;
if ( F_10 ( V_5 , & V_10 ) )
return 0 ;
return F_15 ( V_10 , 1 ) &&
F_15 ( V_10 , 2 ) ;
}
static int F_16 ( T_4 V_5 , void * V_8 )
{
#ifdef F_11
struct V_4 V_12 ;
int V_26 , V_27 , V_28 , V_13 ;
V_28 = - V_24 ;
V_12 = F_8 ( V_5 , V_8 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
switch ( V_12 . V_15 ) {
case V_16 :
if ( V_12 . V_29 )
return 0 ;
break;
case V_17 :
case V_18 :
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return - V_3 ;
case V_23 :
if ( V_12 . V_29 )
return 0 ;
break;
default:
break;
}
if ( V_13 < V_14 - 1 ) {
F_13 ( 5 ) ;
V_12 = F_6 ( V_5 , & V_26 , & V_27 ) ;
}
}
return V_28 ;
#else
return - V_25 ;
#endif
}
static inline struct V_4
F_17 ( T_4 V_5 , unsigned long long V_30 , void * V_31 , T_7 V_32 ,
unsigned int V_33 )
{
typedef struct { char _ [ V_32 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_31 ;
register unsigned long T_9 V_2 ( L_4 ) = ( unsigned long ) V_32 ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned int ) ( V_30 >> 32 ) ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned int ) V_30 ;
if ( V_33 == 1 )
T_1 |= 0x400000UL ;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc" );
return T_2 ;
}
int F_18 ( T_4 V_5 , unsigned long long V_30 , void * V_31 , T_7 V_32 )
{
struct V_4 V_12 ;
V_12 = F_17 ( V_5 , V_30 , V_31 , V_32 , 0 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
return 0 ;
case V_34 :
case V_17 :
return - V_24 ;
case V_35 :
return - V_25 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_19 ( T_4 V_5 , unsigned long long * V_30 , void * V_31 , T_7 V_32 )
{
typedef struct { char _ [ V_32 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned long ) V_31 ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned long ) V_32 ;
register unsigned long T_12 V_2 ( L_7 ) = 0UL ;
register unsigned long T_13 V_2 ( L_8 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_30 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_20 ( T_4 V_5 , unsigned long long * V_30 , void * V_31 , T_7 V_32 )
{
struct V_4 V_12 ;
V_12 = F_19 ( V_5 , V_30 , V_31 , V_32 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
return 0 ;
case V_36 :
if ( V_12 . V_37 )
return - V_38 ;
return - V_24 ;
case V_17 :
return - V_24 ;
default:
return - V_3 ;
}
}
static int F_21 ( T_4 V_5 , int * V_6 , int * V_7 )
{
struct V_4 V_12 ;
int V_26 , V_27 , V_28 , V_13 ;
V_28 = - V_24 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_12 = F_6 ( V_5 , & V_26 , & V_27 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
* V_6 = V_26 + 1 ;
* V_7 = V_27 ;
V_28 = 0 ;
break;
case V_19 :
V_28 = - V_3 ;
break;
case V_17 :
break;
case V_20 :
V_28 = - V_3 ;
break;
case V_21 :
V_28 = - V_3 ;
break;
case V_22 :
V_28 = - V_3 ;
break;
case V_23 :
break;
case V_18 :
break;
default:
F_22 () ;
}
if ( V_28 != - V_24 )
break;
if ( V_13 < V_14 - 1 )
F_13 ( 5 ) ;
}
return V_28 ;
}
static int F_23 ( T_4 V_5 )
{
struct V_4 V_12 ;
int V_28 , V_39 , V_13 ;
V_28 = - V_3 ;
V_12 = F_7 ( V_5 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
switch ( V_12 . V_15 ) {
case V_16 :
if ( V_12 . V_37 )
V_28 = 0 ;
break;
case V_19 :
case V_20 :
case V_21 :
V_13 = V_14 ;
break;
case V_17 :
V_28 = - V_24 ;
case V_18 :
default:
break;
}
if ( V_28 != - V_3 && V_28 != - V_24 )
break;
if ( V_13 < V_14 - 1 ) {
F_13 ( 5 ) ;
V_12 = F_6 ( V_5 , & V_39 , & V_39 ) ;
}
}
if ( V_28 == 0 && F_1 () ) {
V_28 = F_16 ( V_5 , V_1 ) ;
if ( V_28 )
F_24 ( L_9
L_10 , F_25 ( V_5 ) ) ;
}
return V_28 ;
}
static void F_26 ( struct V_40 * V_41 )
{
int V_42 = V_41 -> V_43 -> V_44 ;
V_41 -> V_45 ++ ;
if ( V_41 -> V_45 == 1 ) {
F_27 ( & V_41 -> V_42 , V_46 + V_42 ) ;
V_41 -> V_47 = V_48 ;
}
}
static void F_28 ( struct V_40 * V_41 )
{
int V_42 = V_41 -> V_43 -> V_44 ;
V_41 -> V_45 -- ;
if ( V_41 -> V_45 > 0 )
F_27 ( & V_41 -> V_42 , V_46 + V_42 ) ;
else
V_41 -> V_47 = V_49 ;
}
static T_14 F_29 ( struct V_50 * V_51 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
return snprintf ( V_54 , V_55 , L_11 , V_41 -> V_7 ) ;
}
static T_14 F_31 ( struct V_50 * V_51 , struct V_52 * V_53 ,
char * V_54 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
return snprintf ( V_54 , V_55 , L_11 , V_41 -> V_6 ) ;
}
static T_14 F_32 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
int V_28 ;
F_33 ( & V_41 -> V_56 ) ;
V_28 = snprintf ( V_54 , V_55 , L_11 , V_41 -> V_57 ) ;
F_34 ( & V_41 -> V_56 ) ;
return V_28 ;
}
static T_14 F_35 ( struct V_50 * V_51 ,
struct V_52 * V_53 , char * V_54 )
{
return sprintf ( V_54 , L_12 , F_30 ( V_51 ) -> V_7 ) ;
}
static int F_36 ( struct V_50 * V_51 , struct V_58 * V_43 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
struct V_59 * V_60 = F_37 ( V_43 ) ;
struct V_61 * V_62 ;
for ( V_62 = V_60 -> V_63 ; V_62 -> V_64 ; V_62 ++ ) {
if ( ( V_62 -> V_64 & V_65 ) &&
( V_62 -> V_66 != V_41 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_38 ( struct V_50 * V_51 , struct V_67 * V_68 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
int V_69 = 0 ;
if ( ! V_41 )
return - V_3 ;
V_69 = F_39 ( V_68 , L_13 , V_41 -> V_7 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_39 ( V_68 , L_14 , V_41 -> V_7 ) ;
return V_69 ;
}
static int F_40 ( struct V_50 * V_51 , T_15 V_70 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
unsigned long V_71 ;
if ( ! V_72 ) {
V_72 = 1 ;
F_41 ( & V_73 ) ;
if ( V_74 != NULL ) {
F_42 ( V_74 ) ;
V_74 = NULL ;
}
F_43 ( & V_75 ) ;
}
do {
V_71 = 0 ;
F_33 ( & V_41 -> V_56 ) ;
F_44 ( V_41 , & V_71 ) ;
F_34 ( & V_41 -> V_56 ) ;
} while ( ( V_71 & 1 ) || ( V_71 & 2 ) );
F_33 ( & V_41 -> V_56 ) ;
V_41 -> V_76 = 1 ;
F_34 ( & V_41 -> V_56 ) ;
return 0 ;
}
static int F_45 ( struct V_50 * V_51 )
{
int V_28 = 0 ;
struct V_40 * V_41 = F_30 ( V_51 ) ;
if ( V_72 ) {
V_72 = 0 ;
if ( ! F_4 () )
V_1 = NULL ;
if ( ! V_77 ) {
V_78 = - 1 ;
F_46 () ;
}
F_47 ( & V_73 ) ;
V_73 . V_79 = V_80 ;
V_73 . V_81 = 0 ;
V_73 . V_82 = V_46 + V_83 * V_84 ;
F_48 ( & V_73 ) ;
V_74 = F_49 ( L_15 ) ;
if ( ! V_74 )
return - V_85 ;
F_50 ( & V_75 ) ;
if ( ! F_1 () )
F_51 () ;
else
F_52 ( & V_75 ) ;
if ( V_86 )
V_28 = F_53 () ;
}
if ( F_54 ( V_41 -> V_5 ) != V_78 ) {
F_33 ( & V_41 -> V_56 ) ;
V_41 -> V_5 = F_3 ( F_25 ( V_41 -> V_5 ) ,
V_78 ) ;
F_34 ( & V_41 -> V_56 ) ;
}
F_55 ( V_74 , & V_87 ) ;
return V_28 ;
}
static int F_56 ( struct V_50 * V_51 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
struct V_59 * V_60 = F_37 ( V_51 -> V_88 ) ;
int V_28 ;
V_41 -> V_43 = V_60 ;
V_28 = V_60 -> V_89 ? V_60 -> V_89 ( V_41 ) : - V_3 ;
if ( ! V_28 ) {
F_33 ( & V_90 ) ;
F_57 ( & V_41 -> V_91 , & V_92 ) ;
F_34 ( & V_90 ) ;
}
return V_28 ;
}
static void F_58 ( struct V_40 * V_41 )
{
struct V_93 * V_94 , * V_95 ;
F_59 (ap_msg, next, &ap_dev->pendingq, list) {
F_60 ( & V_94 -> V_91 ) ;
V_41 -> V_96 -- ;
V_94 -> V_97 ( V_41 , V_94 , F_61 ( - V_3 ) ) ;
}
F_59 (ap_msg, next, &ap_dev->requestq, list) {
F_60 ( & V_94 -> V_91 ) ;
V_41 -> V_98 -- ;
V_94 -> V_97 ( V_41 , V_94 , F_61 ( - V_3 ) ) ;
}
}
void F_62 ( struct V_40 * V_41 )
{
F_33 ( & V_41 -> V_56 ) ;
F_58 ( V_41 ) ;
F_34 ( & V_41 -> V_56 ) ;
}
static int F_63 ( struct V_50 * V_51 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
struct V_59 * V_60 = V_41 -> V_43 ;
F_62 ( V_41 ) ;
F_41 ( & V_41 -> V_42 ) ;
F_33 ( & V_90 ) ;
F_60 ( & V_41 -> V_91 ) ;
F_34 ( & V_90 ) ;
if ( V_60 -> remove )
V_60 -> remove ( V_41 ) ;
F_33 ( & V_41 -> V_56 ) ;
F_64 ( V_41 -> V_45 , & V_99 ) ;
F_34 ( & V_41 -> V_56 ) ;
return 0 ;
}
int F_65 ( struct V_59 * V_60 , struct V_100 * V_101 ,
char * V_102 )
{
struct V_58 * V_43 = & V_60 -> V_88 ;
V_43 -> V_103 = & V_104 ;
V_43 -> V_89 = F_56 ;
V_43 -> remove = F_63 ;
V_43 -> V_101 = V_101 ;
V_43 -> V_102 = V_102 ;
return F_66 ( V_43 ) ;
}
void F_67 ( struct V_59 * V_60 )
{
F_68 ( & V_60 -> V_88 ) ;
}
static T_14 F_69 ( struct V_105 * V_103 , char * V_54 )
{
return snprintf ( V_54 , V_55 , L_11 , V_78 ) ;
}
static T_14 F_70 ( struct V_105 * V_103 , char * V_54 )
{
return snprintf ( V_54 , V_55 , L_11 , V_83 ) ;
}
static T_14 F_71 ( struct V_105 * V_103 , char * V_54 )
{
return snprintf ( V_54 , V_55 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_14 F_72 ( struct V_105 * V_103 ,
const char * V_54 , T_7 V_106 )
{
int time ;
if ( sscanf ( V_54 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_25 ;
V_83 = time ;
if ( ! F_73 ( & V_73 ) ||
! F_27 ( & V_73 , V_46 + V_83 * V_84 ) ) {
V_73 . V_82 = V_46 + V_83 * V_84 ;
F_48 ( & V_73 ) ;
}
return V_106 ;
}
static T_14 F_74 ( struct V_105 * V_103 , char * V_54 )
{
return snprintf ( V_54 , V_55 , L_11 , V_107 ? 1 : 0 ) ;
}
static T_14 F_75 ( struct V_105 * V_103 ,
const char * V_54 , T_7 V_106 )
{
int V_108 , V_28 ;
if ( sscanf ( V_54 , L_11 , & V_108 ) != 1 )
return - V_25 ;
if ( V_108 ) {
V_28 = F_53 () ;
if ( V_28 )
return V_28 ;
}
else
F_76 () ;
return V_106 ;
}
static T_14 F_77 ( struct V_105 * V_103 , char * V_54 )
{
return snprintf ( V_54 , V_55 , L_16 , V_109 ) ;
}
static T_14 F_78 ( struct V_105 * V_103 , const char * V_54 ,
T_7 V_106 )
{
unsigned long long time ;
T_16 V_110 ;
if ( sscanf ( V_54 , L_16 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_25 ;
V_109 = time ;
V_110 = F_79 ( 0 , V_109 ) ;
if ( ! F_80 ( & V_111 ) ||
! F_81 ( & V_111 , F_82 ( & V_111 ) , V_110 ) ) {
F_83 ( & V_111 , V_110 ) ;
F_84 ( & V_111 , V_112 ) ;
}
return V_106 ;
}
static int F_46 ( void )
{
int V_6 , V_7 , V_106 , V_113 , V_114 ;
int V_28 , V_13 , V_115 ;
if ( V_78 >= 0 && V_78 < V_116 )
return 0 ;
V_114 = - 1 ;
V_113 = 0 ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
V_106 = 0 ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
T_4 V_5 = F_3 ( V_115 , V_13 ) ;
V_28 = F_21 ( V_5 , & V_6 , & V_7 ) ;
if ( V_28 )
continue;
V_106 ++ ;
}
if ( V_106 > V_113 ) {
V_113 = V_106 ;
V_114 = V_13 ;
}
}
if ( V_114 >= 0 ) {
V_78 = V_114 ;
return 0 ;
}
return - V_3 ;
}
static int F_85 ( struct V_40 * V_41 )
{
static unsigned char V_31 [] = {
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
struct V_4 V_12 ;
unsigned long long V_30 ;
char * V_118 ;
int V_28 , V_13 ;
V_118 = ( void * ) F_86 ( V_119 ) ;
if ( ! V_118 ) {
V_28 = - V_85 ;
goto V_120;
}
V_12 = F_17 ( V_41 -> V_5 , 0x0102030405060708ULL ,
V_31 , sizeof( V_31 ) , 0 ) ;
if ( V_12 . V_15 != V_16 ) {
V_28 = - V_3 ;
goto V_121;
}
for ( V_13 = 0 ; V_13 < 6 ; V_13 ++ ) {
F_87 ( 300 ) ;
V_12 = F_19 ( V_41 -> V_5 , & V_30 , V_118 , 4096 ) ;
if ( V_12 . V_15 == V_16 &&
V_30 == 0x0102030405060708ULL )
break;
}
if ( V_13 < 6 ) {
if ( V_118 [ 0 ] == 0x00 && V_118 [ 1 ] == 0x86 )
V_41 -> V_7 = V_122 ;
else
V_41 -> V_7 = V_123 ;
V_28 = 0 ;
} else
V_28 = - V_3 ;
V_121:
F_88 ( ( unsigned long ) V_118 ) ;
V_120:
return V_28 ;
}
static void F_89 ( void * V_124 , void * V_125 )
{
F_90 ( F_91 () ) . V_126 [ V_127 ] ++ ;
F_52 ( & V_75 ) ;
}
static int F_92 ( struct V_50 * V_51 , void * V_81 )
{
return F_30 ( V_51 ) -> V_5 == ( T_4 ) ( unsigned long ) V_81 ;
}
static void F_93 ( struct V_50 * V_51 )
{
struct V_40 * V_41 = F_30 ( V_51 ) ;
F_94 ( V_41 ) ;
}
static void F_95 ( struct V_128 * V_129 )
{
struct V_40 * V_41 ;
struct V_50 * V_51 ;
T_4 V_5 ;
int V_6 , V_7 ;
unsigned int V_130 ;
int V_28 , V_13 ;
if ( F_46 () != 0 )
return;
for ( V_13 = 0 ; V_13 < V_117 ; V_13 ++ ) {
V_5 = F_3 ( V_13 , V_78 ) ;
V_51 = F_96 ( & V_104 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_92 ) ;
V_28 = F_21 ( V_5 , & V_6 , & V_7 ) ;
if ( V_51 ) {
if ( V_28 == - V_24 ) {
F_97 ( V_131 ) ;
F_98 ( V_132 ) ;
V_28 = F_21 ( V_5 , & V_6 ,
& V_7 ) ;
}
V_41 = F_30 ( V_51 ) ;
F_33 ( & V_41 -> V_56 ) ;
if ( V_28 || V_41 -> V_76 ) {
F_34 ( & V_41 -> V_56 ) ;
if ( V_41 -> V_76 )
V_13 -- ;
F_99 ( V_51 ) ;
F_100 ( V_51 ) ;
continue;
}
F_34 ( & V_41 -> V_56 ) ;
F_100 ( V_51 ) ;
continue;
}
if ( V_28 )
continue;
V_28 = F_23 ( V_5 ) ;
if ( V_28 )
continue;
V_41 = F_101 ( sizeof( * V_41 ) , V_119 ) ;
if ( ! V_41 )
break;
V_41 -> V_5 = V_5 ;
V_41 -> V_6 = V_6 ;
V_41 -> V_76 = 1 ;
F_102 ( & V_41 -> V_56 ) ;
F_103 ( & V_41 -> V_133 ) ;
F_103 ( & V_41 -> V_134 ) ;
F_103 ( & V_41 -> V_91 ) ;
F_104 ( & V_41 -> V_42 , V_135 ,
( unsigned long ) V_41 ) ;
switch ( V_7 ) {
case 0 :
if ( F_85 ( V_41 ) ) {
F_94 ( V_41 ) ;
continue;
}
break;
case 10 :
if ( F_10 ( V_5 , & V_130 ) ) {
F_94 ( V_41 ) ;
continue;
}
if ( F_15 ( V_130 , 3 ) )
V_41 -> V_7 = V_136 ;
else if ( F_15 ( V_130 , 4 ) )
V_41 -> V_7 = V_137 ;
else {
F_94 ( V_41 ) ;
continue;
}
break;
default:
V_41 -> V_7 = V_7 ;
}
V_41 -> V_50 . V_103 = & V_104 ;
V_41 -> V_50 . V_138 = V_139 ;
if ( F_105 ( & V_41 -> V_50 , L_17 ,
F_25 ( V_41 -> V_5 ) ) ) {
F_94 ( V_41 ) ;
continue;
}
V_41 -> V_50 . V_140 = F_93 ;
V_28 = F_106 ( & V_41 -> V_50 ) ;
if ( V_28 ) {
F_100 ( & V_41 -> V_50 ) ;
continue;
}
V_28 = F_107 ( & V_41 -> V_50 . V_141 ,
& V_142 ) ;
if ( ! V_28 ) {
F_33 ( & V_41 -> V_56 ) ;
V_41 -> V_76 = 0 ;
F_34 ( & V_41 -> V_56 ) ;
}
else
F_99 ( & V_41 -> V_50 ) ;
}
}
static void
V_80 ( unsigned long V_143 )
{
F_55 ( V_74 , & V_87 ) ;
V_73 . V_82 = V_46 + V_83 * V_84 ;
F_48 ( & V_73 ) ;
}
static inline void F_108 ( void )
{
T_16 V_110 ;
F_33 ( & V_144 ) ;
if ( F_80 ( & V_111 ) || V_72 )
goto V_120;
if ( F_109 ( F_110 ( & V_111 ) ) <= 0 ) {
V_110 = F_79 ( 0 , V_109 ) ;
F_111 ( & V_111 , V_110 ) ;
F_112 ( & V_111 ) ;
}
V_120:
F_34 ( & V_144 ) ;
}
static inline void F_51 ( void )
{
if ( F_1 () )
return;
F_108 () ;
}
static int F_113 ( struct V_40 * V_41 , unsigned long * V_71 )
{
struct V_4 V_12 ;
struct V_93 * V_94 ;
if ( V_41 -> V_45 <= 0 )
return 0 ;
V_12 = F_19 ( V_41 -> V_5 , & V_41 -> V_118 -> V_30 ,
V_41 -> V_118 -> V_145 , V_41 -> V_118 -> V_32 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
F_114 ( & V_99 ) ;
F_28 ( V_41 ) ;
F_115 (ap_msg, &ap_dev->pendingq, list) {
if ( V_94 -> V_30 != V_41 -> V_118 -> V_30 )
continue;
F_60 ( & V_94 -> V_91 ) ;
V_41 -> V_96 -- ;
V_94 -> V_97 ( V_41 , V_94 , V_41 -> V_118 ) ;
break;
}
if ( V_41 -> V_45 > 0 )
* V_71 |= 1 ;
break;
case V_36 :
if ( V_12 . V_37 ) {
F_64 ( V_41 -> V_45 , & V_99 ) ;
V_41 -> V_45 = 0 ;
F_116 ( & V_41 -> V_133 , & V_41 -> V_134 ) ;
V_41 -> V_98 += V_41 -> V_96 ;
V_41 -> V_96 = 0 ;
} else
* V_71 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_117 ( struct V_40 * V_41 , unsigned long * V_71 )
{
struct V_4 V_12 ;
struct V_93 * V_94 ;
if ( V_41 -> V_98 <= 0 ||
V_41 -> V_45 >= V_41 -> V_6 )
return 0 ;
V_94 = F_118 ( V_41 -> V_134 . V_95 , struct V_93 , V_91 ) ;
V_12 = F_17 ( V_41 -> V_5 , V_94 -> V_30 ,
V_94 -> V_145 , V_94 -> V_32 , V_94 -> V_33 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
F_119 ( & V_99 ) ;
F_26 ( V_41 ) ;
F_120 ( & V_94 -> V_91 , & V_41 -> V_133 ) ;
V_41 -> V_98 -- ;
V_41 -> V_96 ++ ;
if ( V_41 -> V_45 < V_41 -> V_6 &&
V_41 -> V_98 > 0 )
* V_71 |= 1 ;
* V_71 |= 2 ;
break;
case V_17 :
F_108 () ;
case V_34 :
* V_71 |= 2 ;
break;
case V_146 :
case V_35 :
return - V_25 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_121 ( struct V_40 * V_41 , unsigned long * V_71 )
{
int V_28 ;
V_28 = F_113 ( V_41 , V_71 ) ;
if ( V_28 )
return V_28 ;
return F_117 ( V_41 , V_71 ) ;
}
static int F_122 ( struct V_40 * V_41 , struct V_93 * V_94 )
{
struct V_4 V_12 ;
if ( F_123 ( & V_41 -> V_134 ) &&
V_41 -> V_45 < V_41 -> V_6 ) {
V_12 = F_17 ( V_41 -> V_5 , V_94 -> V_30 ,
V_94 -> V_145 , V_94 -> V_32 ,
V_94 -> V_33 ) ;
switch ( V_12 . V_15 ) {
case V_16 :
F_124 ( & V_94 -> V_91 , & V_41 -> V_133 ) ;
F_119 ( & V_99 ) ;
V_41 -> V_96 ++ ;
F_26 ( V_41 ) ;
V_41 -> V_57 ++ ;
break;
case V_34 :
case V_17 :
F_124 ( & V_94 -> V_91 , & V_41 -> V_134 ) ;
V_41 -> V_98 ++ ;
V_41 -> V_57 ++ ;
return - V_24 ;
case V_35 :
case V_146 :
V_94 -> V_97 ( V_41 , V_94 , F_61 ( - V_25 ) ) ;
return - V_25 ;
default:
V_94 -> V_97 ( V_41 , V_94 , F_61 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_124 ( & V_94 -> V_91 , & V_41 -> V_134 ) ;
V_41 -> V_98 ++ ;
V_41 -> V_57 ++ ;
return - V_24 ;
}
F_51 () ;
return 0 ;
}
void F_125 ( struct V_40 * V_41 , struct V_93 * V_94 )
{
unsigned long V_71 ;
int V_28 ;
F_126 ( ! V_94 -> V_97 ) ;
F_33 ( & V_41 -> V_56 ) ;
if ( ! V_41 -> V_76 ) {
V_28 = F_121 ( V_41 , & V_71 ) ;
if ( ! V_28 )
V_28 = F_122 ( V_41 , V_94 ) ;
if ( ! V_28 )
F_127 ( & V_147 ) ;
if ( V_28 == - V_3 )
V_41 -> V_76 = 1 ;
} else {
V_94 -> V_97 ( V_41 , V_94 , F_61 ( - V_3 ) ) ;
V_28 = - V_3 ;
}
F_34 ( & V_41 -> V_56 ) ;
if ( V_28 == - V_3 )
F_99 ( & V_41 -> V_50 ) ;
}
void F_128 ( struct V_40 * V_41 , struct V_93 * V_94 )
{
struct V_93 * V_148 ;
F_33 ( & V_41 -> V_56 ) ;
if ( ! F_123 ( & V_94 -> V_91 ) ) {
F_115 (tmp, &ap_dev->pendingq, list)
if ( V_148 -> V_30 == V_94 -> V_30 ) {
V_41 -> V_96 -- ;
goto V_149;
}
V_41 -> V_98 -- ;
V_149:
F_60 ( & V_94 -> V_91 ) ;
}
F_34 ( & V_41 -> V_56 ) ;
}
static enum F_112 F_129 ( struct V_150 * V_129 )
{
F_52 ( & V_75 ) ;
return V_151 ;
}
static void F_130 ( struct V_40 * V_41 )
{
int V_28 ;
V_41 -> V_47 = V_49 ;
F_64 ( V_41 -> V_45 , & V_99 ) ;
V_41 -> V_45 = 0 ;
F_116 ( & V_41 -> V_133 , & V_41 -> V_134 ) ;
V_41 -> V_98 += V_41 -> V_96 ;
V_41 -> V_96 = 0 ;
V_28 = F_23 ( V_41 -> V_5 ) ;
if ( V_28 == - V_3 )
V_41 -> V_76 = 1 ;
else
F_108 () ;
}
static int F_44 ( struct V_40 * V_41 , unsigned long * V_71 )
{
if ( ! V_41 -> V_76 ) {
if ( F_121 ( V_41 , V_71 ) )
V_41 -> V_76 = 1 ;
if ( V_41 -> V_47 == V_152 )
F_130 ( V_41 ) ;
}
return 0 ;
}
static void F_131 ( unsigned long V_39 )
{
unsigned long V_71 ;
struct V_40 * V_41 ;
if ( F_1 () )
F_132 ( ( V_153 * ) V_1 , 0 ) ;
do {
V_71 = 0 ;
F_133 ( & V_90 ) ;
F_115 (ap_dev, &ap_device_list, list) {
F_133 ( & V_41 -> V_56 ) ;
F_44 ( V_41 , & V_71 ) ;
F_134 ( & V_41 -> V_56 ) ;
}
F_134 ( & V_90 ) ;
} while ( V_71 & 1 );
if ( V_71 & 2 )
F_51 () ;
}
static int F_135 ( void * V_81 )
{
F_136 ( V_154 , V_155 ) ;
unsigned long V_71 ;
int V_156 ;
struct V_40 * V_41 ;
F_137 ( V_155 , 19 ) ;
while ( 1 ) {
if ( V_72 )
return 0 ;
if ( F_138 () ) {
F_139 () ;
continue;
}
F_140 ( & V_147 , & V_154 ) ;
F_97 ( V_157 ) ;
if ( F_141 () )
break;
V_156 = F_142 ( & V_99 ) ;
if ( V_156 <= 0 )
F_139 () ;
F_97 ( V_158 ) ;
F_143 ( & V_147 , & V_154 ) ;
V_71 = 0 ;
F_33 ( & V_90 ) ;
F_115 (ap_dev, &ap_device_list, list) {
F_133 ( & V_41 -> V_56 ) ;
F_44 ( V_41 , & V_71 ) ;
F_134 ( & V_41 -> V_56 ) ;
}
F_34 ( & V_90 ) ;
}
F_97 ( V_158 ) ;
F_143 ( & V_147 , & V_154 ) ;
return 0 ;
}
static int F_53 ( void )
{
int V_28 ;
if ( F_1 () || V_72 )
return 0 ;
F_144 ( & V_159 ) ;
if ( ! V_107 ) {
V_107 = F_145 ( F_135 , NULL , L_18 ) ;
V_28 = F_146 ( V_107 ) ? F_147 ( V_107 ) : 0 ;
if ( V_28 )
V_107 = NULL ;
}
else
V_28 = 0 ;
F_148 ( & V_159 ) ;
return V_28 ;
}
static void F_76 ( void )
{
F_144 ( & V_159 ) ;
if ( V_107 ) {
F_149 ( V_107 ) ;
V_107 = NULL ;
}
F_148 ( & V_159 ) ;
}
static void V_135 ( unsigned long V_81 )
{
struct V_40 * V_41 = (struct V_40 * ) V_81 ;
if ( V_41 -> V_47 == V_48 ) {
V_41 -> V_47 = V_152 ;
if ( F_1 () )
F_52 ( & V_75 ) ;
}
}
static void F_150 ( void )
{
int V_13 ;
if ( V_78 != - 1 )
for ( V_13 = 0 ; V_13 < V_117 ; V_13 ++ )
F_7 ( F_3 ( V_13 , V_78 ) ) ;
}
static void F_151 ( void )
{
int V_13 , V_115 ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ )
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ )
F_7 ( F_3 ( V_115 , V_13 ) ) ;
}
int T_17 F_152 ( void )
{
int V_28 , V_13 ;
if ( V_78 < - 1 || V_78 >= V_116 ) {
F_153 ( L_19 ,
V_78 ) ;
return - V_25 ;
}
if ( V_78 >= 0 )
V_77 = 1 ;
if ( F_2 () != 0 ) {
F_153 ( L_20
L_21 ) ;
return - V_3 ;
}
if ( F_4 () ) {
F_154 ( V_9 ) ;
V_1 = F_155 (
& F_89 , NULL , V_9 ) ;
if ( F_146 ( V_1 ) ) {
V_1 = NULL ;
F_156 ( V_9 ) ;
}
}
F_157 ( & V_160 ) ;
V_28 = F_158 ( & V_104 ) ;
if ( V_28 )
goto V_120;
for ( V_13 = 0 ; V_161 [ V_13 ] ; V_13 ++ ) {
V_28 = F_159 ( & V_104 , V_161 [ V_13 ] ) ;
if ( V_28 )
goto V_162;
}
V_139 = F_160 ( L_22 ) ;
V_28 = F_146 ( V_139 ) ? F_147 ( V_139 ) : 0 ;
if ( V_28 )
goto V_162;
V_74 = F_49 ( L_15 ) ;
if ( ! V_74 ) {
V_28 = - V_85 ;
goto V_163;
}
if ( F_46 () == 0 )
F_95 ( NULL ) ;
F_47 ( & V_73 ) ;
V_73 . V_79 = V_80 ;
V_73 . V_81 = 0 ;
V_73 . V_82 = V_46 + V_83 * V_84 ;
F_48 ( & V_73 ) ;
if ( V_164 )
V_109 = 1500000 ;
F_102 ( & V_144 ) ;
F_161 ( & V_111 , V_165 , V_112 ) ;
V_111 . V_79 = F_129 ;
if ( V_86 ) {
V_28 = F_53 () ;
if ( V_28 )
goto V_166;
}
return 0 ;
V_166:
F_41 ( & V_73 ) ;
F_162 ( & V_111 ) ;
F_42 ( V_74 ) ;
V_163:
F_163 ( V_139 ) ;
V_162:
while ( V_13 -- )
F_164 ( & V_104 , V_161 [ V_13 ] ) ;
F_165 ( & V_104 ) ;
V_120:
F_166 ( & V_160 ) ;
if ( F_1 () ) {
F_167 ( V_1 , V_9 ) ;
F_156 ( V_9 ) ;
}
return V_28 ;
}
static int F_168 ( struct V_50 * V_51 , void * V_81 )
{
return 1 ;
}
void F_169 ( void )
{
int V_13 ;
struct V_50 * V_51 ;
F_150 () ;
F_76 () ;
F_41 ( & V_73 ) ;
F_162 ( & V_111 ) ;
F_42 ( V_74 ) ;
F_170 ( & V_75 ) ;
F_163 ( V_139 ) ;
while ( ( V_51 = F_96 ( & V_104 , NULL , NULL ,
F_168 ) ) )
{
F_99 ( V_51 ) ;
F_100 ( V_51 ) ;
}
for ( V_13 = 0 ; V_161 [ V_13 ] ; V_13 ++ )
F_164 ( & V_104 , V_161 [ V_13 ] ) ;
F_165 ( & V_104 ) ;
F_166 ( & V_160 ) ;
if ( F_1 () ) {
F_167 ( V_1 , V_9 ) ;
F_156 ( V_9 ) ;
}
}
