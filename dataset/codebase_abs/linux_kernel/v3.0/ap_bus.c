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
static inline struct V_4 F_9 ( T_4 V_5 ,
int * V_10 )
{
register unsigned long T_1 V_2 ( L_1 ) = 0UL | V_5 | ( 1UL << 23 ) ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(
".long 0xb2af0000\n"
"0: la %1,0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (reg0), "=d" (reg1), "=d" (reg2)
:
: "cc");
if ( T_3 & 0x6000000000000000ULL )
* V_10 = 1 ;
else
* V_10 = 0 ;
return T_2 ;
}
int F_10 ( T_4 V_5 )
{
struct V_4 V_11 ;
int V_12 , V_10 = 0 ;
V_11 = F_9 ( V_5 , & V_10 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
switch ( V_11 . V_14 ) {
case V_15 :
return V_10 ;
case V_16 :
case V_17 :
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return 0 ;
case V_22 :
break;
default:
break;
}
if ( V_12 < V_13 - 1 ) {
F_11 ( 5 ) ;
V_11 = F_9 ( V_5 , & V_10 ) ;
}
}
return V_10 ;
}
static int F_12 ( T_4 V_5 , void * V_8 )
{
#ifdef F_13
struct V_4 V_11 ;
int V_23 , V_24 , V_25 , V_12 ;
V_25 = - V_26 ;
V_11 = F_8 ( V_5 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
switch ( V_11 . V_14 ) {
case V_15 :
if ( V_11 . V_27 )
return 0 ;
break;
case V_16 :
case V_17 :
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return - V_3 ;
case V_22 :
if ( V_11 . V_27 )
return 0 ;
break;
default:
break;
}
if ( V_12 < V_13 - 1 ) {
F_11 ( 5 ) ;
V_11 = F_6 ( V_5 , & V_23 , & V_24 ) ;
}
}
return V_25 ;
#else
return - V_28 ;
#endif
}
static inline struct V_4
F_14 ( T_4 V_5 , unsigned long long V_29 , void * V_30 , T_7 V_31 ,
unsigned int V_32 )
{
typedef struct { char _ [ V_31 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_30 ;
register unsigned long T_9 V_2 ( L_4 ) = ( unsigned long ) V_31 ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned int ) ( V_29 >> 32 ) ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned int ) V_29 ;
if ( V_32 == 1 )
T_1 |= 0x400000UL ;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc" );
return T_2 ;
}
int F_15 ( T_4 V_5 , unsigned long long V_29 , void * V_30 , T_7 V_31 )
{
struct V_4 V_11 ;
V_11 = F_14 ( V_5 , V_29 , V_30 , V_31 , 0 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
return 0 ;
case V_33 :
case V_16 :
return - V_26 ;
case V_34 :
return - V_28 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_16 ( T_4 V_5 , unsigned long long * V_29 , void * V_30 , T_7 V_31 )
{
typedef struct { char _ [ V_31 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned long ) V_30 ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned long ) V_31 ;
register unsigned long T_12 V_2 ( L_7 ) = 0UL ;
register unsigned long T_13 V_2 ( L_8 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_29 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_17 ( T_4 V_5 , unsigned long long * V_29 , void * V_30 , T_7 V_31 )
{
struct V_4 V_11 ;
V_11 = F_16 ( V_5 , V_29 , V_30 , V_31 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
return 0 ;
case V_35 :
if ( V_11 . V_36 )
return - V_37 ;
return - V_26 ;
case V_16 :
return - V_26 ;
default:
return - V_3 ;
}
}
static int F_18 ( T_4 V_5 , int * V_6 , int * V_7 )
{
struct V_4 V_11 ;
int V_23 , V_24 , V_25 , V_12 ;
V_25 = - V_26 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_6 ( V_5 , & V_23 , & V_24 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
* V_6 = V_23 + 1 ;
* V_7 = V_24 ;
V_25 = 0 ;
break;
case V_18 :
V_25 = - V_3 ;
break;
case V_16 :
break;
case V_19 :
V_25 = - V_3 ;
break;
case V_20 :
V_25 = - V_3 ;
break;
case V_21 :
V_25 = - V_3 ;
break;
case V_22 :
break;
case V_17 :
break;
default:
F_19 () ;
}
if ( V_25 != - V_26 )
break;
if ( V_12 < V_13 - 1 )
F_11 ( 5 ) ;
}
return V_25 ;
}
static int F_20 ( T_4 V_5 )
{
struct V_4 V_11 ;
int V_25 , V_38 , V_12 ;
V_25 = - V_3 ;
V_11 = F_7 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
switch ( V_11 . V_14 ) {
case V_15 :
if ( V_11 . V_36 )
V_25 = 0 ;
break;
case V_18 :
case V_19 :
case V_20 :
V_12 = V_13 ;
break;
case V_16 :
V_25 = - V_26 ;
case V_17 :
default:
break;
}
if ( V_25 != - V_3 && V_25 != - V_26 )
break;
if ( V_12 < V_13 - 1 ) {
F_11 ( 5 ) ;
V_11 = F_6 ( V_5 , & V_38 , & V_38 ) ;
}
}
if ( V_25 == 0 && F_1 () ) {
V_25 = F_12 ( V_5 , V_1 ) ;
if ( V_25 )
F_21 ( L_9
L_10 , F_22 ( V_5 ) ) ;
}
return V_25 ;
}
static void F_23 ( struct V_39 * V_40 )
{
int V_41 = V_40 -> V_42 -> V_43 ;
V_40 -> V_44 ++ ;
if ( V_40 -> V_44 == 1 ) {
F_24 ( & V_40 -> V_41 , V_45 + V_41 ) ;
V_40 -> V_46 = V_47 ;
}
}
static void F_25 ( struct V_39 * V_40 )
{
int V_41 = V_40 -> V_42 -> V_43 ;
V_40 -> V_44 -- ;
if ( V_40 -> V_44 > 0 )
F_24 ( & V_40 -> V_41 , V_45 + V_41 ) ;
else
V_40 -> V_46 = V_48 ;
}
static T_14 F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
return snprintf ( V_53 , V_54 , L_11 , V_40 -> V_7 ) ;
}
static T_14 F_28 ( struct V_49 * V_50 , struct V_51 * V_52 ,
char * V_53 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
return snprintf ( V_53 , V_54 , L_11 , V_40 -> V_6 ) ;
}
static T_14 F_29 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
int V_25 ;
F_30 ( & V_40 -> V_55 ) ;
V_25 = snprintf ( V_53 , V_54 , L_11 , V_40 -> V_56 ) ;
F_31 ( & V_40 -> V_55 ) ;
return V_25 ;
}
static T_14 F_32 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
return sprintf ( V_53 , L_12 , F_27 ( V_50 ) -> V_7 ) ;
}
static int F_33 ( struct V_49 * V_50 , struct V_57 * V_42 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
struct V_58 * V_59 = F_34 ( V_42 ) ;
struct V_60 * V_61 ;
for ( V_61 = V_59 -> V_62 ; V_61 -> V_63 ; V_61 ++ ) {
if ( ( V_61 -> V_63 & V_64 ) &&
( V_61 -> V_65 != V_40 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_49 * V_50 , struct V_66 * V_67 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
int V_68 = 0 ;
if ( ! V_40 )
return - V_3 ;
V_68 = F_36 ( V_67 , L_13 , V_40 -> V_7 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_36 ( V_67 , L_14 , V_40 -> V_7 ) ;
return V_68 ;
}
static int F_37 ( struct V_49 * V_50 , T_15 V_69 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
unsigned long V_70 ;
if ( ! V_71 ) {
V_71 = 1 ;
F_38 ( & V_72 ) ;
if ( V_73 != NULL ) {
F_39 ( V_73 ) ;
V_73 = NULL ;
}
F_40 ( & V_74 ) ;
}
do {
V_70 = 0 ;
F_30 ( & V_40 -> V_55 ) ;
F_41 ( V_40 , & V_70 ) ;
F_31 ( & V_40 -> V_55 ) ;
} while ( ( V_70 & 1 ) || ( V_70 & 2 ) );
F_30 ( & V_40 -> V_55 ) ;
V_40 -> V_75 = 1 ;
F_31 ( & V_40 -> V_55 ) ;
return 0 ;
}
static int F_42 ( struct V_49 * V_50 )
{
int V_25 = 0 ;
struct V_39 * V_40 = F_27 ( V_50 ) ;
if ( V_71 ) {
V_71 = 0 ;
if ( ! F_4 () )
V_1 = NULL ;
if ( ! V_76 ) {
V_77 = - 1 ;
F_43 () ;
}
F_44 ( & V_72 ) ;
V_72 . V_78 = V_79 ;
V_72 . V_80 = 0 ;
V_72 . V_81 = V_45 + V_82 * V_83 ;
F_45 ( & V_72 ) ;
V_73 = F_46 ( L_15 ) ;
if ( ! V_73 )
return - V_84 ;
F_47 ( & V_74 ) ;
if ( ! F_1 () )
F_48 () ;
else
F_49 ( & V_74 ) ;
if ( V_85 )
V_25 = F_50 () ;
}
if ( F_51 ( V_40 -> V_5 ) != V_77 ) {
F_30 ( & V_40 -> V_55 ) ;
V_40 -> V_5 = F_3 ( F_22 ( V_40 -> V_5 ) ,
V_77 ) ;
F_31 ( & V_40 -> V_55 ) ;
}
F_52 ( V_73 , & V_86 ) ;
return V_25 ;
}
static int F_53 ( struct V_49 * V_50 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
struct V_58 * V_59 = F_34 ( V_50 -> V_87 ) ;
int V_25 ;
V_40 -> V_42 = V_59 ;
V_25 = V_59 -> V_88 ? V_59 -> V_88 ( V_40 ) : - V_3 ;
if ( ! V_25 ) {
F_30 ( & V_89 ) ;
F_54 ( & V_40 -> V_90 , & V_91 ) ;
F_31 ( & V_89 ) ;
}
return V_25 ;
}
static void F_55 ( struct V_39 * V_40 )
{
struct V_92 * V_93 , * V_94 ;
F_56 (ap_msg, next, &ap_dev->pendingq, list) {
F_57 ( & V_93 -> V_90 ) ;
V_40 -> V_95 -- ;
V_40 -> V_42 -> V_96 ( V_40 , V_93 , F_58 ( - V_3 ) ) ;
}
F_56 (ap_msg, next, &ap_dev->requestq, list) {
F_57 ( & V_93 -> V_90 ) ;
V_40 -> V_97 -- ;
V_40 -> V_42 -> V_96 ( V_40 , V_93 , F_58 ( - V_3 ) ) ;
}
}
void F_59 ( struct V_39 * V_40 )
{
F_30 ( & V_40 -> V_55 ) ;
F_55 ( V_40 ) ;
F_31 ( & V_40 -> V_55 ) ;
}
static int F_60 ( struct V_49 * V_50 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
struct V_58 * V_59 = V_40 -> V_42 ;
F_59 ( V_40 ) ;
F_38 ( & V_40 -> V_41 ) ;
F_30 ( & V_89 ) ;
F_57 ( & V_40 -> V_90 ) ;
F_31 ( & V_89 ) ;
if ( V_59 -> remove )
V_59 -> remove ( V_40 ) ;
F_30 ( & V_40 -> V_55 ) ;
F_61 ( V_40 -> V_44 , & V_98 ) ;
F_31 ( & V_40 -> V_55 ) ;
return 0 ;
}
int F_62 ( struct V_58 * V_59 , struct V_99 * V_100 ,
char * V_101 )
{
struct V_57 * V_42 = & V_59 -> V_87 ;
V_42 -> V_102 = & V_103 ;
V_42 -> V_88 = F_53 ;
V_42 -> remove = F_60 ;
V_42 -> V_100 = V_100 ;
V_42 -> V_101 = V_101 ;
return F_63 ( V_42 ) ;
}
void F_64 ( struct V_58 * V_59 )
{
F_65 ( & V_59 -> V_87 ) ;
}
static T_14 F_66 ( struct V_104 * V_102 , char * V_53 )
{
return snprintf ( V_53 , V_54 , L_11 , V_77 ) ;
}
static T_14 F_67 ( struct V_104 * V_102 , char * V_53 )
{
return snprintf ( V_53 , V_54 , L_11 , V_82 ) ;
}
static T_14 F_68 ( struct V_104 * V_102 , char * V_53 )
{
return snprintf ( V_53 , V_54 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_14 F_69 ( struct V_104 * V_102 ,
const char * V_53 , T_7 V_105 )
{
int time ;
if ( sscanf ( V_53 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_28 ;
V_82 = time ;
if ( ! F_70 ( & V_72 ) ||
! F_24 ( & V_72 , V_45 + V_82 * V_83 ) ) {
V_72 . V_81 = V_45 + V_82 * V_83 ;
F_45 ( & V_72 ) ;
}
return V_105 ;
}
static T_14 F_71 ( struct V_104 * V_102 , char * V_53 )
{
return snprintf ( V_53 , V_54 , L_11 , V_106 ? 1 : 0 ) ;
}
static T_14 F_72 ( struct V_104 * V_102 ,
const char * V_53 , T_7 V_105 )
{
int V_107 , V_25 ;
if ( sscanf ( V_53 , L_11 , & V_107 ) != 1 )
return - V_28 ;
if ( V_107 ) {
V_25 = F_50 () ;
if ( V_25 )
return V_25 ;
}
else
F_73 () ;
return V_105 ;
}
static T_14 F_74 ( struct V_104 * V_102 , char * V_53 )
{
return snprintf ( V_53 , V_54 , L_16 , V_108 ) ;
}
static T_14 F_75 ( struct V_104 * V_102 , const char * V_53 ,
T_7 V_105 )
{
unsigned long long time ;
T_16 V_109 ;
if ( sscanf ( V_53 , L_16 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_28 ;
V_108 = time ;
V_109 = F_76 ( 0 , V_108 ) ;
if ( ! F_77 ( & V_110 ) ||
! F_78 ( & V_110 , F_79 ( & V_110 ) , V_109 ) ) {
F_80 ( & V_110 , V_109 ) ;
F_81 ( & V_110 , V_111 ) ;
}
return V_105 ;
}
static int F_43 ( void )
{
int V_6 , V_7 , V_105 , V_112 , V_113 ;
int V_25 , V_12 , V_114 ;
if ( V_77 >= 0 && V_77 < V_115 )
return 0 ;
V_113 = - 1 ;
V_112 = 0 ;
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ ) {
V_105 = 0 ;
for ( V_114 = 0 ; V_114 < V_116 ; V_114 ++ ) {
T_4 V_5 = F_3 ( V_114 , V_12 ) ;
V_25 = F_18 ( V_5 , & V_6 , & V_7 ) ;
if ( V_25 )
continue;
V_105 ++ ;
}
if ( V_105 > V_112 ) {
V_112 = V_105 ;
V_113 = V_12 ;
}
}
if ( V_113 >= 0 ) {
V_77 = V_113 ;
return 0 ;
}
return - V_3 ;
}
static int F_82 ( struct V_39 * V_40 )
{
static unsigned char V_30 [] = {
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
struct V_4 V_11 ;
unsigned long long V_29 ;
char * V_117 ;
int V_25 , V_12 ;
V_117 = ( void * ) F_83 ( V_118 ) ;
if ( ! V_117 ) {
V_25 = - V_84 ;
goto V_119;
}
V_11 = F_14 ( V_40 -> V_5 , 0x0102030405060708ULL ,
V_30 , sizeof( V_30 ) , 0 ) ;
if ( V_11 . V_14 != V_15 ) {
V_25 = - V_3 ;
goto V_120;
}
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_84 ( 300 ) ;
V_11 = F_16 ( V_40 -> V_5 , & V_29 , V_117 , 4096 ) ;
if ( V_11 . V_14 == V_15 &&
V_29 == 0x0102030405060708ULL )
break;
}
if ( V_12 < 6 ) {
if ( V_117 [ 0 ] == 0x00 && V_117 [ 1 ] == 0x86 )
V_40 -> V_7 = V_121 ;
else
V_40 -> V_7 = V_122 ;
V_25 = 0 ;
} else
V_25 = - V_3 ;
V_120:
F_85 ( ( unsigned long ) V_117 ) ;
V_119:
return V_25 ;
}
static void F_86 ( void * V_123 , void * V_124 )
{
F_87 ( F_88 () ) . V_125 [ V_126 ] ++ ;
F_49 ( & V_74 ) ;
}
static int F_89 ( struct V_49 * V_50 , void * V_80 )
{
return F_27 ( V_50 ) -> V_5 == ( T_4 ) ( unsigned long ) V_80 ;
}
static void F_90 ( struct V_49 * V_50 )
{
struct V_39 * V_40 = F_27 ( V_50 ) ;
F_91 ( V_40 ) ;
}
static void F_92 ( struct V_127 * V_128 )
{
struct V_39 * V_40 ;
struct V_49 * V_50 ;
T_4 V_5 ;
int V_6 , V_7 ;
int V_25 , V_12 ;
if ( F_43 () != 0 )
return;
for ( V_12 = 0 ; V_12 < V_116 ; V_12 ++ ) {
V_5 = F_3 ( V_12 , V_77 ) ;
V_50 = F_93 ( & V_103 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_89 ) ;
V_25 = F_18 ( V_5 , & V_6 , & V_7 ) ;
if ( V_50 ) {
if ( V_25 == - V_26 ) {
F_94 ( V_129 ) ;
F_95 ( V_130 ) ;
V_25 = F_18 ( V_5 , & V_6 ,
& V_7 ) ;
}
V_40 = F_27 ( V_50 ) ;
F_30 ( & V_40 -> V_55 ) ;
if ( V_25 || V_40 -> V_75 ) {
F_31 ( & V_40 -> V_55 ) ;
if ( V_40 -> V_75 )
V_12 -- ;
F_96 ( V_50 ) ;
F_97 ( V_50 ) ;
continue;
}
F_31 ( & V_40 -> V_55 ) ;
F_97 ( V_50 ) ;
continue;
}
if ( V_25 )
continue;
V_25 = F_20 ( V_5 ) ;
if ( V_25 )
continue;
V_40 = F_98 ( sizeof( * V_40 ) , V_118 ) ;
if ( ! V_40 )
break;
V_40 -> V_5 = V_5 ;
V_40 -> V_6 = V_6 ;
V_40 -> V_75 = 1 ;
F_99 ( & V_40 -> V_55 ) ;
F_100 ( & V_40 -> V_131 ) ;
F_100 ( & V_40 -> V_132 ) ;
F_100 ( & V_40 -> V_90 ) ;
F_101 ( & V_40 -> V_41 , V_133 ,
( unsigned long ) V_40 ) ;
if ( V_7 == 0 ) {
if ( F_82 ( V_40 ) ) {
F_91 ( V_40 ) ;
continue;
}
}
else
V_40 -> V_7 = V_7 ;
V_40 -> V_49 . V_102 = & V_103 ;
V_40 -> V_49 . V_134 = V_135 ;
if ( F_102 ( & V_40 -> V_49 , L_17 ,
F_22 ( V_40 -> V_5 ) ) ) {
F_91 ( V_40 ) ;
continue;
}
V_40 -> V_49 . V_136 = F_90 ;
V_25 = F_103 ( & V_40 -> V_49 ) ;
if ( V_25 ) {
F_97 ( & V_40 -> V_49 ) ;
continue;
}
V_25 = F_104 ( & V_40 -> V_49 . V_137 ,
& V_138 ) ;
if ( ! V_25 ) {
F_30 ( & V_40 -> V_55 ) ;
V_40 -> V_75 = 0 ;
F_31 ( & V_40 -> V_55 ) ;
}
else
F_96 ( & V_40 -> V_49 ) ;
}
}
static void
V_79 ( unsigned long V_139 )
{
F_52 ( V_73 , & V_86 ) ;
V_72 . V_81 = V_45 + V_82 * V_83 ;
F_45 ( & V_72 ) ;
}
static inline void F_48 ( void )
{
T_16 V_109 ;
F_30 ( & V_140 ) ;
if ( F_1 () || V_71 )
goto V_119;
if ( F_77 ( & V_110 ) )
goto V_119;
if ( F_105 ( F_106 ( & V_110 ) ) <= 0 ) {
V_109 = F_76 ( 0 , V_108 ) ;
F_107 ( & V_110 , V_109 ) ;
F_108 ( & V_110 ) ;
}
V_119:
F_31 ( & V_140 ) ;
}
static int F_109 ( struct V_39 * V_40 , unsigned long * V_70 )
{
struct V_4 V_11 ;
struct V_92 * V_93 ;
if ( V_40 -> V_44 <= 0 )
return 0 ;
V_11 = F_16 ( V_40 -> V_5 , & V_40 -> V_117 -> V_29 ,
V_40 -> V_117 -> V_141 , V_40 -> V_117 -> V_31 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
F_110 ( & V_98 ) ;
F_25 ( V_40 ) ;
F_111 (ap_msg, &ap_dev->pendingq, list) {
if ( V_93 -> V_29 != V_40 -> V_117 -> V_29 )
continue;
F_57 ( & V_93 -> V_90 ) ;
V_40 -> V_95 -- ;
V_40 -> V_42 -> V_96 ( V_40 , V_93 , V_40 -> V_117 ) ;
break;
}
if ( V_40 -> V_44 > 0 )
* V_70 |= 1 ;
break;
case V_35 :
if ( V_11 . V_36 ) {
F_61 ( V_40 -> V_44 , & V_98 ) ;
V_40 -> V_44 = 0 ;
F_112 ( & V_40 -> V_131 , & V_40 -> V_132 ) ;
V_40 -> V_97 += V_40 -> V_95 ;
V_40 -> V_95 = 0 ;
} else
* V_70 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_113 ( struct V_39 * V_40 , unsigned long * V_70 )
{
struct V_4 V_11 ;
struct V_92 * V_93 ;
if ( V_40 -> V_97 <= 0 ||
V_40 -> V_44 >= V_40 -> V_6 )
return 0 ;
V_93 = F_114 ( V_40 -> V_132 . V_94 , struct V_92 , V_90 ) ;
V_11 = F_14 ( V_40 -> V_5 , V_93 -> V_29 ,
V_93 -> V_141 , V_93 -> V_31 , V_93 -> V_32 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
F_115 ( & V_98 ) ;
F_23 ( V_40 ) ;
F_116 ( & V_93 -> V_90 , & V_40 -> V_131 ) ;
V_40 -> V_97 -- ;
V_40 -> V_95 ++ ;
if ( V_40 -> V_44 < V_40 -> V_6 &&
V_40 -> V_97 > 0 )
* V_70 |= 1 ;
* V_70 |= 2 ;
break;
case V_33 :
case V_16 :
* V_70 |= 2 ;
break;
case V_142 :
case V_34 :
return - V_28 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_117 ( struct V_39 * V_40 , unsigned long * V_70 )
{
int V_25 ;
V_25 = F_109 ( V_40 , V_70 ) ;
if ( V_25 )
return V_25 ;
return F_113 ( V_40 , V_70 ) ;
}
static int F_118 ( struct V_39 * V_40 , struct V_92 * V_93 )
{
struct V_4 V_11 ;
if ( F_119 ( & V_40 -> V_132 ) &&
V_40 -> V_44 < V_40 -> V_6 ) {
V_11 = F_14 ( V_40 -> V_5 , V_93 -> V_29 ,
V_93 -> V_141 , V_93 -> V_31 ,
V_93 -> V_32 ) ;
switch ( V_11 . V_14 ) {
case V_15 :
F_120 ( & V_93 -> V_90 , & V_40 -> V_131 ) ;
F_115 ( & V_98 ) ;
V_40 -> V_95 ++ ;
F_23 ( V_40 ) ;
V_40 -> V_56 ++ ;
break;
case V_33 :
case V_16 :
F_120 ( & V_93 -> V_90 , & V_40 -> V_132 ) ;
V_40 -> V_97 ++ ;
V_40 -> V_56 ++ ;
return - V_26 ;
case V_34 :
case V_142 :
V_40 -> V_42 -> V_96 ( V_40 , V_93 , F_58 ( - V_28 ) ) ;
return - V_28 ;
default:
V_40 -> V_42 -> V_96 ( V_40 , V_93 , F_58 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_120 ( & V_93 -> V_90 , & V_40 -> V_132 ) ;
V_40 -> V_97 ++ ;
V_40 -> V_56 ++ ;
return - V_26 ;
}
F_48 () ;
return 0 ;
}
void F_121 ( struct V_39 * V_40 , struct V_92 * V_93 )
{
unsigned long V_70 ;
int V_25 ;
F_30 ( & V_40 -> V_55 ) ;
if ( ! V_40 -> V_75 ) {
V_25 = F_117 ( V_40 , & V_70 ) ;
if ( ! V_25 )
V_25 = F_118 ( V_40 , V_93 ) ;
if ( ! V_25 )
F_122 ( & V_143 ) ;
if ( V_25 == - V_3 )
V_40 -> V_75 = 1 ;
} else {
V_40 -> V_42 -> V_96 ( V_40 , V_93 , F_58 ( - V_3 ) ) ;
V_25 = - V_3 ;
}
F_31 ( & V_40 -> V_55 ) ;
if ( V_25 == - V_3 )
F_96 ( & V_40 -> V_49 ) ;
}
void F_123 ( struct V_39 * V_40 , struct V_92 * V_93 )
{
struct V_92 * V_144 ;
F_30 ( & V_40 -> V_55 ) ;
if ( ! F_119 ( & V_93 -> V_90 ) ) {
F_111 (tmp, &ap_dev->pendingq, list)
if ( V_144 -> V_29 == V_93 -> V_29 ) {
V_40 -> V_95 -- ;
goto V_145;
}
V_40 -> V_97 -- ;
V_145:
F_57 ( & V_93 -> V_90 ) ;
}
F_31 ( & V_40 -> V_55 ) ;
}
static enum F_108 F_124 ( struct V_146 * V_128 )
{
F_49 ( & V_74 ) ;
return V_147 ;
}
static void F_125 ( struct V_39 * V_40 )
{
int V_25 ;
V_40 -> V_46 = V_48 ;
F_61 ( V_40 -> V_44 , & V_98 ) ;
V_40 -> V_44 = 0 ;
F_112 ( & V_40 -> V_131 , & V_40 -> V_132 ) ;
V_40 -> V_97 += V_40 -> V_95 ;
V_40 -> V_95 = 0 ;
V_25 = F_20 ( V_40 -> V_5 ) ;
if ( V_25 == - V_3 )
V_40 -> V_75 = 1 ;
}
static int F_41 ( struct V_39 * V_40 , unsigned long * V_70 )
{
if ( ! V_40 -> V_75 ) {
if ( F_117 ( V_40 , V_70 ) )
V_40 -> V_75 = 1 ;
if ( V_40 -> V_46 == V_148 )
F_125 ( V_40 ) ;
}
return 0 ;
}
static void F_126 ( unsigned long V_38 )
{
unsigned long V_70 ;
struct V_39 * V_40 ;
if ( F_1 () )
F_127 ( ( V_149 * ) V_1 , 0 ) ;
do {
V_70 = 0 ;
F_128 ( & V_89 ) ;
F_111 (ap_dev, &ap_device_list, list) {
F_128 ( & V_40 -> V_55 ) ;
F_41 ( V_40 , & V_70 ) ;
F_129 ( & V_40 -> V_55 ) ;
}
F_129 ( & V_89 ) ;
} while ( V_70 & 1 );
if ( V_70 & 2 )
F_48 () ;
}
static int F_130 ( void * V_80 )
{
F_131 ( V_150 , V_151 ) ;
unsigned long V_70 ;
int V_152 ;
struct V_39 * V_40 ;
F_132 ( V_151 , 19 ) ;
while ( 1 ) {
if ( V_71 )
return 0 ;
if ( F_133 () ) {
F_134 () ;
continue;
}
F_135 ( & V_143 , & V_150 ) ;
F_94 ( V_153 ) ;
if ( F_136 () )
break;
V_152 = F_137 ( & V_98 ) ;
if ( V_152 <= 0 )
F_134 () ;
F_94 ( V_154 ) ;
F_138 ( & V_143 , & V_150 ) ;
V_70 = 0 ;
F_30 ( & V_89 ) ;
F_111 (ap_dev, &ap_device_list, list) {
F_128 ( & V_40 -> V_55 ) ;
F_41 ( V_40 , & V_70 ) ;
F_129 ( & V_40 -> V_55 ) ;
}
F_31 ( & V_89 ) ;
}
F_94 ( V_154 ) ;
F_138 ( & V_143 , & V_150 ) ;
return 0 ;
}
static int F_50 ( void )
{
int V_25 ;
if ( F_1 () || V_71 )
return 0 ;
F_139 ( & V_155 ) ;
if ( ! V_106 ) {
V_106 = F_140 ( F_130 , NULL , L_18 ) ;
V_25 = F_141 ( V_106 ) ? F_142 ( V_106 ) : 0 ;
if ( V_25 )
V_106 = NULL ;
}
else
V_25 = 0 ;
F_143 ( & V_155 ) ;
return V_25 ;
}
static void F_73 ( void )
{
F_139 ( & V_155 ) ;
if ( V_106 ) {
F_144 ( V_106 ) ;
V_106 = NULL ;
}
F_143 ( & V_155 ) ;
}
static void V_133 ( unsigned long V_80 )
{
struct V_39 * V_40 = (struct V_39 * ) V_80 ;
if ( V_40 -> V_46 == V_47 ) {
V_40 -> V_46 = V_148 ;
if ( F_1 () )
F_49 ( & V_74 ) ;
}
}
static void F_145 ( void )
{
int V_12 ;
if ( V_77 != - 1 )
for ( V_12 = 0 ; V_12 < V_116 ; V_12 ++ )
F_7 ( F_3 ( V_12 , V_77 ) ) ;
}
static void F_146 ( void )
{
int V_12 , V_114 ;
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ )
for ( V_114 = 0 ; V_114 < V_116 ; V_114 ++ )
F_7 ( F_3 ( V_114 , V_12 ) ) ;
}
int T_17 F_147 ( void )
{
int V_25 , V_12 ;
if ( V_77 < - 1 || V_77 >= V_115 ) {
F_148 ( L_19 ,
V_77 ) ;
return - V_28 ;
}
if ( V_77 >= 0 )
V_76 = 1 ;
if ( F_2 () != 0 ) {
F_148 ( L_20
L_21 ) ;
return - V_3 ;
}
if ( F_4 () ) {
F_149 ( V_9 ) ;
V_1 = F_150 (
& F_86 , NULL , V_9 ) ;
if ( F_141 ( V_1 ) ) {
V_1 = NULL ;
F_151 ( V_9 ) ;
}
}
F_152 ( & V_156 ) ;
V_25 = F_153 ( & V_103 ) ;
if ( V_25 )
goto V_119;
for ( V_12 = 0 ; V_157 [ V_12 ] ; V_12 ++ ) {
V_25 = F_154 ( & V_103 , V_157 [ V_12 ] ) ;
if ( V_25 )
goto V_158;
}
V_135 = F_155 ( L_22 ) ;
V_25 = F_141 ( V_135 ) ? F_142 ( V_135 ) : 0 ;
if ( V_25 )
goto V_158;
V_73 = F_46 ( L_15 ) ;
if ( ! V_73 ) {
V_25 = - V_84 ;
goto V_159;
}
if ( F_43 () == 0 )
F_92 ( NULL ) ;
F_44 ( & V_72 ) ;
V_72 . V_78 = V_79 ;
V_72 . V_80 = 0 ;
V_72 . V_81 = V_45 + V_82 * V_83 ;
F_45 ( & V_72 ) ;
if ( V_160 )
V_108 = 1500000 ;
F_99 ( & V_140 ) ;
F_156 ( & V_110 , V_161 , V_111 ) ;
V_110 . V_78 = F_124 ;
if ( V_85 ) {
V_25 = F_50 () ;
if ( V_25 )
goto V_162;
}
return 0 ;
V_162:
F_38 ( & V_72 ) ;
F_157 ( & V_110 ) ;
F_39 ( V_73 ) ;
V_159:
F_158 ( V_135 ) ;
V_158:
while ( V_12 -- )
F_159 ( & V_103 , V_157 [ V_12 ] ) ;
F_160 ( & V_103 ) ;
V_119:
F_161 ( & V_156 ) ;
if ( F_1 () ) {
F_162 ( V_1 , V_9 ) ;
F_151 ( V_9 ) ;
}
return V_25 ;
}
static int F_163 ( struct V_49 * V_50 , void * V_80 )
{
return 1 ;
}
void F_164 ( void )
{
int V_12 ;
struct V_49 * V_50 ;
F_145 () ;
F_73 () ;
F_38 ( & V_72 ) ;
F_157 ( & V_110 ) ;
F_39 ( V_73 ) ;
F_165 ( & V_74 ) ;
F_158 ( V_135 ) ;
while ( ( V_50 = F_93 ( & V_103 , NULL , NULL ,
F_163 ) ) )
{
F_96 ( V_50 ) ;
F_97 ( V_50 ) ;
}
for ( V_12 = 0 ; V_157 [ V_12 ] ; V_12 ++ )
F_159 ( & V_103 , V_157 [ V_12 ] ) ;
F_160 ( & V_103 ) ;
F_161 ( & V_156 ) ;
if ( F_1 () ) {
F_162 ( V_1 , V_9 ) ;
F_151 ( V_9 ) ;
}
}
