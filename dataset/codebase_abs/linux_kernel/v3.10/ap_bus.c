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
static int F_6 ( void )
{
return F_5 ( 2 ) && F_5 ( 12 ) ;
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
static inline struct V_4 F_8 ( T_4 V_5 )
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
F_9 ( T_4 V_5 , void * V_8 )
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
F_10 ( T_4 V_5 , unsigned int * V_10 )
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
static inline int F_11 ( struct V_12 * V_13 )
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
static int F_12 ( T_4 V_5 , unsigned int * V_10 )
{
#ifdef F_13
struct V_4 V_15 ;
int V_16 ;
V_15 = F_10 ( V_5 , V_10 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
if ( F_14 ( & V_15 ) )
return - V_3 ;
switch ( V_15 . V_18 ) {
case V_19 :
return 0 ;
case V_20 :
case V_21 :
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return - V_3 ;
case V_26 :
break;
default:
break;
}
if ( V_16 < V_17 - 1 ) {
F_15 ( 5 ) ;
V_15 = F_10 ( V_5 , V_10 ) ;
}
}
return - V_27 ;
#else
return - V_14 ;
#endif
}
static int F_16 ( T_4 V_5 , void * V_8 )
{
#ifdef F_13
struct V_4 V_15 ;
int V_28 , V_29 , V_30 , V_16 ;
V_30 = - V_27 ;
V_15 = F_9 ( V_5 , V_8 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
switch ( V_15 . V_18 ) {
case V_19 :
if ( V_15 . V_31 )
return 0 ;
break;
case V_20 :
case V_21 :
if ( V_16 < V_17 - 1 ) {
F_15 ( 5 ) ;
V_15 = F_9 ( V_5 ,
V_8 ) ;
continue;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return - V_3 ;
case V_26 :
if ( V_15 . V_31 )
return 0 ;
break;
default:
break;
}
if ( V_16 < V_17 - 1 ) {
F_15 ( 5 ) ;
V_15 = F_7 ( V_5 , & V_28 , & V_29 ) ;
}
}
return V_30 ;
#else
return - V_14 ;
#endif
}
static inline struct V_4
F_17 ( T_4 V_5 , unsigned long long V_32 , void * V_33 , T_7 V_34 ,
unsigned int V_35 )
{
typedef struct { char _ [ V_34 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_33 ;
register unsigned long T_9 V_2 ( L_4 ) = ( unsigned long ) V_34 ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned int ) ( V_32 >> 32 ) ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned int ) V_32 ;
if ( V_35 == 1 )
T_1 |= 0x400000UL ;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc" );
return T_2 ;
}
int F_18 ( T_4 V_5 , unsigned long long V_32 , void * V_33 , T_7 V_34 )
{
struct V_4 V_15 ;
V_15 = F_17 ( V_5 , V_32 , V_33 , V_34 , 0 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
return 0 ;
case V_36 :
case V_20 :
return - V_27 ;
case V_37 :
return - V_14 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_19 ( T_4 V_5 , unsigned long long * V_32 , void * V_33 , T_7 V_34 )
{
typedef struct { char _ [ V_34 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_5 ) = ( unsigned long ) V_33 ;
register unsigned long T_11 V_2 ( L_6 ) = ( unsigned long ) V_34 ;
register unsigned long T_12 V_2 ( L_7 ) = 0UL ;
register unsigned long T_13 V_2 ( L_8 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_32 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_20 ( T_4 V_5 , unsigned long long * V_32 , void * V_33 , T_7 V_34 )
{
struct V_4 V_15 ;
V_15 = F_19 ( V_5 , V_32 , V_33 , V_34 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
return 0 ;
case V_38 :
if ( V_15 . V_39 )
return - V_40 ;
return - V_27 ;
case V_20 :
return - V_27 ;
default:
return - V_3 ;
}
}
static int F_21 ( T_4 V_5 , int * V_6 , int * V_7 )
{
struct V_4 V_15 ;
int V_28 , V_29 , V_30 , V_16 ;
V_30 = - V_27 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_15 = F_7 ( V_5 , & V_28 , & V_29 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
* V_6 = V_28 + 1 ;
* V_7 = V_29 ;
V_30 = 0 ;
break;
case V_22 :
V_30 = - V_3 ;
break;
case V_20 :
break;
case V_23 :
V_30 = - V_3 ;
break;
case V_24 :
V_30 = - V_3 ;
break;
case V_25 :
V_30 = - V_3 ;
break;
case V_26 :
break;
case V_21 :
break;
default:
F_22 () ;
}
if ( V_30 != - V_27 )
break;
if ( V_16 < V_17 - 1 )
F_15 ( 5 ) ;
}
return V_30 ;
}
static int F_23 ( T_4 V_5 )
{
struct V_4 V_15 ;
int V_30 , V_41 , V_16 ;
V_30 = - V_3 ;
V_15 = F_8 ( V_5 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
switch ( V_15 . V_18 ) {
case V_19 :
if ( V_15 . V_39 )
V_30 = 0 ;
break;
case V_22 :
case V_23 :
case V_24 :
V_16 = V_17 ;
break;
case V_20 :
V_30 = - V_27 ;
case V_21 :
default:
break;
}
if ( V_30 != - V_3 && V_30 != - V_27 )
break;
if ( V_16 < V_17 - 1 ) {
F_15 ( 5 ) ;
V_15 = F_7 ( V_5 , & V_41 , & V_41 ) ;
}
}
if ( V_30 == 0 && F_1 () ) {
V_30 = F_16 ( V_5 , V_1 ) ;
if ( V_30 )
F_24 ( L_9
L_10 , F_25 ( V_5 ) ) ;
}
return V_30 ;
}
static void F_26 ( struct V_42 * V_43 )
{
int V_44 = V_43 -> V_45 -> V_46 ;
V_43 -> V_47 ++ ;
if ( V_43 -> V_47 == 1 ) {
F_27 ( & V_43 -> V_44 , V_48 + V_44 ) ;
V_43 -> V_49 = V_50 ;
}
}
static void F_28 ( struct V_42 * V_43 )
{
int V_44 = V_43 -> V_45 -> V_46 ;
V_43 -> V_47 -- ;
if ( V_43 -> V_47 > 0 )
F_27 ( & V_43 -> V_44 , V_48 + V_44 ) ;
else
V_43 -> V_49 = V_51 ;
}
static T_14 F_29 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
return snprintf ( V_56 , V_57 , L_11 , V_43 -> V_7 ) ;
}
static T_14 F_31 ( struct V_52 * V_53 , struct V_54 * V_55 ,
char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
return snprintf ( V_56 , V_57 , L_11 , V_43 -> V_6 ) ;
}
static T_14 F_32 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
int V_30 ;
F_33 ( & V_43 -> V_58 ) ;
V_30 = snprintf ( V_56 , V_57 , L_11 , V_43 -> V_59 ) ;
F_34 ( & V_43 -> V_58 ) ;
return V_30 ;
}
static T_14 F_35 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
int V_30 ;
F_33 ( & V_43 -> V_58 ) ;
V_30 = snprintf ( V_56 , V_57 , L_11 , V_43 -> V_60 ) ;
F_34 ( & V_43 -> V_58 ) ;
return V_30 ;
}
static T_14 F_36 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
int V_30 ;
F_33 ( & V_43 -> V_58 ) ;
V_30 = snprintf ( V_56 , V_57 , L_11 , V_43 -> V_61 ) ;
F_34 ( & V_43 -> V_58 ) ;
return V_30 ;
}
static T_14 F_37 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_56 )
{
return sprintf ( V_56 , L_12 , F_30 ( V_53 ) -> V_7 ) ;
}
static T_14 F_38 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
return snprintf ( V_56 , V_57 , L_13 , V_43 -> V_10 ) ;
}
static int F_39 ( struct V_52 * V_53 , struct V_62 * V_45 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
struct V_63 * V_64 = F_40 ( V_45 ) ;
struct V_65 * V_66 ;
for ( V_66 = V_64 -> V_67 ; V_66 -> V_68 ; V_66 ++ ) {
if ( ( V_66 -> V_68 & V_69 ) &&
( V_66 -> V_70 != V_43 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_52 * V_53 , struct V_71 * V_72 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
int V_73 = 0 ;
if ( ! V_43 )
return - V_3 ;
V_73 = F_42 ( V_72 , L_14 , V_43 -> V_7 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_42 ( V_72 , L_15 , V_43 -> V_7 ) ;
return V_73 ;
}
static int F_43 ( struct V_52 * V_53 , T_15 V_74 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
unsigned long V_75 ;
if ( ! V_76 ) {
V_76 = 1 ;
F_44 ( & V_77 ) ;
if ( V_78 != NULL ) {
F_45 ( V_78 ) ;
V_78 = NULL ;
}
F_46 ( & V_79 ) ;
}
do {
V_75 = 0 ;
F_33 ( & V_43 -> V_58 ) ;
F_47 ( V_43 , & V_75 ) ;
F_34 ( & V_43 -> V_58 ) ;
} while ( ( V_75 & 1 ) || ( V_75 & 2 ) );
F_33 ( & V_43 -> V_58 ) ;
V_43 -> V_80 = 1 ;
F_34 ( & V_43 -> V_58 ) ;
return 0 ;
}
static int F_48 ( struct V_52 * V_53 )
{
int V_30 = 0 ;
struct V_42 * V_43 = F_30 ( V_53 ) ;
if ( V_76 ) {
V_76 = 0 ;
if ( ! F_4 () )
V_1 = NULL ;
F_49 () ;
if ( ! V_81 ) {
V_82 = - 1 ;
F_50 () ;
}
F_51 ( & V_77 ) ;
V_77 . V_83 = V_84 ;
V_77 . V_85 = 0 ;
V_77 . V_86 = V_48 + V_87 * V_88 ;
F_52 ( & V_77 ) ;
V_78 = F_53 ( L_16 ) ;
if ( ! V_78 )
return - V_89 ;
F_54 ( & V_79 ) ;
if ( ! F_1 () )
F_55 () ;
else
F_56 ( & V_79 ) ;
if ( V_90 )
V_30 = F_57 () ;
}
if ( F_58 ( V_43 -> V_5 ) != V_82 ) {
F_33 ( & V_43 -> V_58 ) ;
V_43 -> V_5 = F_3 ( F_25 ( V_43 -> V_5 ) ,
V_82 ) ;
F_34 ( & V_43 -> V_58 ) ;
}
F_59 ( V_78 , & V_91 ) ;
return V_30 ;
}
static int F_60 ( struct V_52 * V_53 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
struct V_63 * V_64 = F_40 ( V_53 -> V_92 ) ;
int V_30 ;
V_43 -> V_45 = V_64 ;
V_30 = V_64 -> V_93 ? V_64 -> V_93 ( V_43 ) : - V_3 ;
if ( ! V_30 ) {
F_33 ( & V_94 ) ;
F_61 ( & V_43 -> V_95 , & V_96 ) ;
F_34 ( & V_94 ) ;
}
return V_30 ;
}
static void F_62 ( struct V_42 * V_43 )
{
struct V_97 * V_98 , * V_99 ;
F_63 (ap_msg, next, &ap_dev->pendingq, list) {
F_64 ( & V_98 -> V_95 ) ;
V_43 -> V_61 -- ;
V_98 -> V_100 ( V_43 , V_98 , F_65 ( - V_3 ) ) ;
}
F_63 (ap_msg, next, &ap_dev->requestq, list) {
F_64 ( & V_98 -> V_95 ) ;
V_43 -> V_60 -- ;
V_98 -> V_100 ( V_43 , V_98 , F_65 ( - V_3 ) ) ;
}
}
void F_66 ( struct V_42 * V_43 )
{
F_33 ( & V_43 -> V_58 ) ;
F_62 ( V_43 ) ;
F_34 ( & V_43 -> V_58 ) ;
}
static int F_67 ( struct V_52 * V_53 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
struct V_63 * V_64 = V_43 -> V_45 ;
F_66 ( V_43 ) ;
F_44 ( & V_43 -> V_44 ) ;
F_33 ( & V_94 ) ;
F_64 ( & V_43 -> V_95 ) ;
F_34 ( & V_94 ) ;
if ( V_64 -> remove )
V_64 -> remove ( V_43 ) ;
F_33 ( & V_43 -> V_58 ) ;
F_68 ( V_43 -> V_47 , & V_101 ) ;
F_34 ( & V_43 -> V_58 ) ;
return 0 ;
}
int F_69 ( struct V_63 * V_64 , struct V_102 * V_103 ,
char * V_104 )
{
struct V_62 * V_45 = & V_64 -> V_92 ;
V_45 -> V_105 = & V_106 ;
V_45 -> V_93 = F_60 ;
V_45 -> remove = F_67 ;
V_45 -> V_103 = V_103 ;
V_45 -> V_104 = V_104 ;
return F_70 ( V_45 ) ;
}
void F_71 ( struct V_63 * V_64 )
{
F_72 ( & V_64 -> V_92 ) ;
}
void F_73 ( void )
{
F_27 ( & V_77 , V_48 + V_87 * V_88 ) ;
F_59 ( V_78 , & V_91 ) ;
F_74 ( & V_91 ) ;
}
static T_14 F_75 ( struct V_107 * V_105 , char * V_56 )
{
return snprintf ( V_56 , V_57 , L_11 , V_82 ) ;
}
static T_14 F_76 ( struct V_107 * V_105 , char * V_56 )
{
return snprintf ( V_56 , V_57 , L_11 , V_87 ) ;
}
static T_14 F_77 ( struct V_107 * V_105 , char * V_56 )
{
return snprintf ( V_56 , V_57 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_14 F_78 ( struct V_107 * V_105 ,
const char * V_56 , T_7 V_108 )
{
int time ;
if ( sscanf ( V_56 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_14 ;
V_87 = time ;
if ( ! F_79 ( & V_77 ) ||
! F_27 ( & V_77 , V_48 + V_87 * V_88 ) ) {
V_77 . V_86 = V_48 + V_87 * V_88 ;
F_52 ( & V_77 ) ;
}
return V_108 ;
}
static T_14 F_80 ( struct V_107 * V_105 , char * V_56 )
{
return snprintf ( V_56 , V_57 , L_11 , V_109 ? 1 : 0 ) ;
}
static T_14 F_81 ( struct V_107 * V_105 ,
const char * V_56 , T_7 V_108 )
{
int V_110 , V_30 ;
if ( sscanf ( V_56 , L_11 , & V_110 ) != 1 )
return - V_14 ;
if ( V_110 ) {
V_30 = F_57 () ;
if ( V_30 )
return V_30 ;
}
else
F_82 () ;
return V_108 ;
}
static T_14 F_83 ( struct V_107 * V_105 , char * V_56 )
{
return snprintf ( V_56 , V_57 , L_17 , V_111 ) ;
}
static T_14 F_84 ( struct V_107 * V_105 , const char * V_56 ,
T_7 V_108 )
{
unsigned long long time ;
T_16 V_112 ;
if ( sscanf ( V_56 , L_17 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_14 ;
V_111 = time ;
V_112 = F_85 ( 0 , V_111 ) ;
if ( ! F_86 ( & V_113 ) ||
! F_87 ( & V_113 , F_88 ( & V_113 ) , V_112 ) ) {
F_89 ( & V_113 , V_112 ) ;
F_90 ( & V_113 , V_114 ) ;
}
return V_108 ;
}
static inline int F_91 ( unsigned int * V_115 , unsigned int V_116 )
{
if ( V_116 > 0xFFu )
return 0 ;
return F_92 ( ( V_115 + ( V_116 >> 5 ) ) , ( V_116 & 0x1f ) ) ;
}
static inline int F_93 ( unsigned int V_66 )
{
if ( ! V_117 )
return 1 ;
return F_91 ( V_117 -> V_118 , V_66 ) ;
}
static inline int F_94 ( unsigned int V_119 )
{
if ( ! V_117 )
return 1 ;
return F_91 ( V_117 -> V_120 , V_119 ) ;
}
static void F_49 ( void )
{
#ifdef F_13
if ( F_6 () ) {
if ( ! V_117 )
V_117 =
F_95 ( sizeof( struct V_12 ) ,
V_121 ) ;
if ( V_117 )
F_11 ( V_117 ) ;
} else
V_117 = NULL ;
#else
V_117 = NULL ;
#endif
}
static int F_50 ( void )
{
int V_6 , V_7 , V_108 , V_122 , V_123 ;
T_4 V_5 ;
int V_30 , V_16 , V_124 ;
if ( V_82 >= 0 && V_82 < V_125 )
return 0 ;
V_123 = - 1 ;
V_122 = 0 ;
for ( V_16 = 0 ; V_16 < V_125 ; V_16 ++ ) {
if ( ! F_94 ( V_16 ) )
continue;
V_108 = 0 ;
for ( V_124 = 0 ; V_124 < V_126 ; V_124 ++ ) {
if ( ! F_93 ( V_124 ) )
continue;
V_5 = F_3 ( V_124 , V_16 ) ;
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
if ( V_30 )
continue;
V_108 ++ ;
}
if ( V_108 > V_122 ) {
V_122 = V_108 ;
V_123 = V_16 ;
}
}
if ( V_123 >= 0 ) {
V_82 = V_123 ;
return 0 ;
}
return - V_3 ;
}
static int F_96 ( struct V_42 * V_43 )
{
static unsigned char V_33 [] = {
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
unsigned long long V_32 ;
char * V_127 ;
int V_30 , V_16 ;
V_127 = ( void * ) F_97 ( V_121 ) ;
if ( ! V_127 ) {
V_30 = - V_89 ;
goto V_128;
}
V_15 = F_17 ( V_43 -> V_5 , 0x0102030405060708ULL ,
V_33 , sizeof( V_33 ) , 0 ) ;
if ( V_15 . V_18 != V_19 ) {
V_30 = - V_3 ;
goto V_129;
}
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
F_98 ( 300 ) ;
V_15 = F_19 ( V_43 -> V_5 , & V_32 , V_127 , 4096 ) ;
if ( V_15 . V_18 == V_19 &&
V_32 == 0x0102030405060708ULL )
break;
}
if ( V_16 < 6 ) {
if ( V_127 [ 0 ] == 0x00 && V_127 [ 1 ] == 0x86 )
V_43 -> V_7 = V_130 ;
else
V_43 -> V_7 = V_131 ;
V_30 = 0 ;
} else
V_30 = - V_3 ;
V_129:
F_99 ( ( unsigned long ) V_127 ) ;
V_128:
return V_30 ;
}
static void F_100 ( void * V_132 , void * V_133 )
{
F_101 ( V_134 ) ;
F_56 ( & V_79 ) ;
}
static int F_102 ( struct V_52 * V_53 , void * V_85 )
{
return F_30 ( V_53 ) -> V_5 == ( T_4 ) ( unsigned long ) V_85 ;
}
static void F_103 ( struct V_52 * V_53 )
{
struct V_42 * V_43 = F_30 ( V_53 ) ;
F_104 ( V_43 ) ;
}
static void F_105 ( struct V_135 * V_136 )
{
struct V_42 * V_43 ;
struct V_52 * V_53 ;
T_4 V_5 ;
int V_6 , V_7 ;
unsigned int V_137 ;
int V_30 , V_16 ;
F_49 () ;
if ( F_50 () != 0 ) {
return;
}
for ( V_16 = 0 ; V_16 < V_126 ; V_16 ++ ) {
V_5 = F_3 ( V_16 , V_82 ) ;
V_53 = F_106 ( & V_106 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_102 ) ;
if ( F_93 ( V_16 ) )
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
else
V_30 = - V_3 ;
if ( V_53 ) {
if ( V_30 == - V_27 ) {
F_107 ( V_138 ) ;
F_108 ( V_139 ) ;
V_30 = F_21 ( V_5 , & V_6 ,
& V_7 ) ;
}
V_43 = F_30 ( V_53 ) ;
F_33 ( & V_43 -> V_58 ) ;
if ( V_30 || V_43 -> V_80 ) {
F_34 ( & V_43 -> V_58 ) ;
if ( V_43 -> V_80 )
V_16 -- ;
F_109 ( V_53 ) ;
F_110 ( V_53 ) ;
continue;
}
F_34 ( & V_43 -> V_58 ) ;
F_110 ( V_53 ) ;
continue;
}
if ( V_30 )
continue;
V_30 = F_23 ( V_5 ) ;
if ( V_30 )
continue;
V_43 = F_95 ( sizeof( * V_43 ) , V_121 ) ;
if ( ! V_43 )
break;
V_43 -> V_5 = V_5 ;
V_43 -> V_6 = V_6 ;
V_43 -> V_80 = 1 ;
F_111 ( & V_43 -> V_58 ) ;
F_112 ( & V_43 -> V_140 ) ;
F_112 ( & V_43 -> V_141 ) ;
F_112 ( & V_43 -> V_95 ) ;
F_113 ( & V_43 -> V_44 , V_142 ,
( unsigned long ) V_43 ) ;
switch ( V_7 ) {
case 0 :
if ( F_96 ( V_43 ) ) {
F_104 ( V_43 ) ;
continue;
}
break;
default:
V_43 -> V_7 = V_7 ;
}
V_30 = F_12 ( V_5 , & V_137 ) ;
if ( ! V_30 )
V_43 -> V_10 = V_137 ;
else
V_43 -> V_10 = 0u ;
V_43 -> V_52 . V_105 = & V_106 ;
V_43 -> V_52 . V_143 = V_144 ;
if ( F_114 ( & V_43 -> V_52 , L_18 ,
F_25 ( V_43 -> V_5 ) ) ) {
F_104 ( V_43 ) ;
continue;
}
V_43 -> V_52 . V_145 = F_103 ;
V_30 = F_115 ( & V_43 -> V_52 ) ;
if ( V_30 ) {
F_110 ( & V_43 -> V_52 ) ;
continue;
}
V_30 = F_116 ( & V_43 -> V_52 . V_146 ,
& V_147 ) ;
if ( ! V_30 ) {
F_33 ( & V_43 -> V_58 ) ;
V_43 -> V_80 = 0 ;
F_34 ( & V_43 -> V_58 ) ;
}
else
F_109 ( & V_43 -> V_52 ) ;
}
}
static void
V_84 ( unsigned long V_148 )
{
F_59 ( V_78 , & V_91 ) ;
V_77 . V_86 = V_48 + V_87 * V_88 ;
F_52 ( & V_77 ) ;
}
static inline void F_117 ( void )
{
T_16 V_112 ;
F_33 ( & V_149 ) ;
if ( F_86 ( & V_113 ) || V_76 )
goto V_128;
if ( F_118 ( F_119 ( & V_113 ) ) <= 0 ) {
V_112 = F_85 ( 0 , V_111 ) ;
F_120 ( & V_113 , V_112 ) ;
F_121 ( & V_113 ) ;
}
V_128:
F_34 ( & V_149 ) ;
}
static inline void F_55 ( void )
{
if ( F_1 () )
return;
F_117 () ;
}
static int F_122 ( struct V_42 * V_43 , unsigned long * V_75 )
{
struct V_4 V_15 ;
struct V_97 * V_98 ;
if ( V_43 -> V_47 <= 0 )
return 0 ;
V_15 = F_19 ( V_43 -> V_5 , & V_43 -> V_127 -> V_32 ,
V_43 -> V_127 -> V_150 , V_43 -> V_127 -> V_34 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_123 ( & V_101 ) ;
F_28 ( V_43 ) ;
F_124 (ap_msg, &ap_dev->pendingq, list) {
if ( V_98 -> V_32 != V_43 -> V_127 -> V_32 )
continue;
F_64 ( & V_98 -> V_95 ) ;
V_43 -> V_61 -- ;
V_98 -> V_100 ( V_43 , V_98 , V_43 -> V_127 ) ;
break;
}
if ( V_43 -> V_47 > 0 )
* V_75 |= 1 ;
break;
case V_38 :
if ( V_15 . V_39 ) {
F_68 ( V_43 -> V_47 , & V_101 ) ;
V_43 -> V_47 = 0 ;
F_125 ( & V_43 -> V_140 , & V_43 -> V_141 ) ;
V_43 -> V_60 += V_43 -> V_61 ;
V_43 -> V_61 = 0 ;
} else
* V_75 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_126 ( struct V_42 * V_43 , unsigned long * V_75 )
{
struct V_4 V_15 ;
struct V_97 * V_98 ;
if ( V_43 -> V_60 <= 0 ||
V_43 -> V_47 >= V_43 -> V_6 )
return 0 ;
V_98 = F_127 ( V_43 -> V_141 . V_99 , struct V_97 , V_95 ) ;
V_15 = F_17 ( V_43 -> V_5 , V_98 -> V_32 ,
V_98 -> V_150 , V_98 -> V_34 , V_98 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_128 ( & V_101 ) ;
F_26 ( V_43 ) ;
F_129 ( & V_98 -> V_95 , & V_43 -> V_140 ) ;
V_43 -> V_60 -- ;
V_43 -> V_61 ++ ;
if ( V_43 -> V_47 < V_43 -> V_6 &&
V_43 -> V_60 > 0 )
* V_75 |= 1 ;
* V_75 |= 2 ;
break;
case V_20 :
F_117 () ;
case V_36 :
* V_75 |= 2 ;
break;
case V_151 :
case V_37 :
return - V_14 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_130 ( struct V_42 * V_43 , unsigned long * V_75 )
{
int V_30 ;
V_30 = F_122 ( V_43 , V_75 ) ;
if ( V_30 )
return V_30 ;
return F_126 ( V_43 , V_75 ) ;
}
static int F_131 ( struct V_42 * V_43 , struct V_97 * V_98 )
{
struct V_4 V_15 ;
if ( F_132 ( & V_43 -> V_141 ) &&
V_43 -> V_47 < V_43 -> V_6 ) {
V_15 = F_17 ( V_43 -> V_5 , V_98 -> V_32 ,
V_98 -> V_150 , V_98 -> V_34 ,
V_98 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_133 ( & V_98 -> V_95 , & V_43 -> V_140 ) ;
F_128 ( & V_101 ) ;
V_43 -> V_61 ++ ;
F_26 ( V_43 ) ;
V_43 -> V_59 ++ ;
break;
case V_36 :
case V_20 :
F_133 ( & V_98 -> V_95 , & V_43 -> V_141 ) ;
V_43 -> V_60 ++ ;
V_43 -> V_59 ++ ;
return - V_27 ;
case V_37 :
case V_151 :
V_98 -> V_100 ( V_43 , V_98 , F_65 ( - V_14 ) ) ;
return - V_14 ;
default:
V_98 -> V_100 ( V_43 , V_98 , F_65 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_133 ( & V_98 -> V_95 , & V_43 -> V_141 ) ;
V_43 -> V_60 ++ ;
V_43 -> V_59 ++ ;
return - V_27 ;
}
F_55 () ;
return 0 ;
}
void F_134 ( struct V_42 * V_43 , struct V_97 * V_98 )
{
unsigned long V_75 ;
int V_30 ;
F_135 ( ! V_98 -> V_100 ) ;
F_33 ( & V_43 -> V_58 ) ;
if ( ! V_43 -> V_80 ) {
V_30 = F_130 ( V_43 , & V_75 ) ;
if ( ! V_30 )
V_30 = F_131 ( V_43 , V_98 ) ;
if ( ! V_30 )
F_136 ( & V_152 ) ;
if ( V_30 == - V_3 )
V_43 -> V_80 = 1 ;
} else {
V_98 -> V_100 ( V_43 , V_98 , F_65 ( - V_3 ) ) ;
V_30 = - V_3 ;
}
F_34 ( & V_43 -> V_58 ) ;
if ( V_30 == - V_3 )
F_109 ( & V_43 -> V_52 ) ;
}
void F_137 ( struct V_42 * V_43 , struct V_97 * V_98 )
{
struct V_97 * V_153 ;
F_33 ( & V_43 -> V_58 ) ;
if ( ! F_132 ( & V_98 -> V_95 ) ) {
F_124 (tmp, &ap_dev->pendingq, list)
if ( V_153 -> V_32 == V_98 -> V_32 ) {
V_43 -> V_61 -- ;
goto V_154;
}
V_43 -> V_60 -- ;
V_154:
F_64 ( & V_98 -> V_95 ) ;
}
F_34 ( & V_43 -> V_58 ) ;
}
static enum F_121 F_138 ( struct V_155 * V_136 )
{
F_56 ( & V_79 ) ;
return V_156 ;
}
static void F_139 ( struct V_42 * V_43 )
{
int V_30 ;
V_43 -> V_49 = V_51 ;
F_68 ( V_43 -> V_47 , & V_101 ) ;
V_43 -> V_47 = 0 ;
F_125 ( & V_43 -> V_140 , & V_43 -> V_141 ) ;
V_43 -> V_60 += V_43 -> V_61 ;
V_43 -> V_61 = 0 ;
V_30 = F_23 ( V_43 -> V_5 ) ;
if ( V_30 == - V_3 )
V_43 -> V_80 = 1 ;
else
F_117 () ;
}
static int F_47 ( struct V_42 * V_43 , unsigned long * V_75 )
{
if ( ! V_43 -> V_80 ) {
if ( F_130 ( V_43 , V_75 ) )
V_43 -> V_80 = 1 ;
if ( V_43 -> V_49 == V_157 )
F_139 ( V_43 ) ;
}
return 0 ;
}
static void F_140 ( unsigned long V_41 )
{
unsigned long V_75 ;
struct V_42 * V_43 ;
if ( F_1 () )
F_141 ( ( V_158 * ) V_1 , 0 ) ;
do {
V_75 = 0 ;
F_142 ( & V_94 ) ;
F_124 (ap_dev, &ap_device_list, list) {
F_142 ( & V_43 -> V_58 ) ;
F_47 ( V_43 , & V_75 ) ;
F_143 ( & V_43 -> V_58 ) ;
}
F_143 ( & V_94 ) ;
} while ( V_75 & 1 );
if ( V_75 & 2 )
F_55 () ;
}
static int F_144 ( void * V_85 )
{
F_145 ( V_159 , V_160 ) ;
unsigned long V_75 ;
int V_161 ;
struct V_42 * V_43 ;
F_146 ( V_160 , 19 ) ;
while ( 1 ) {
if ( V_76 )
return 0 ;
if ( F_147 () ) {
F_148 () ;
continue;
}
F_149 ( & V_152 , & V_159 ) ;
F_107 ( V_162 ) ;
if ( F_150 () )
break;
V_161 = F_151 ( & V_101 ) ;
if ( V_161 <= 0 )
F_148 () ;
F_107 ( V_163 ) ;
F_152 ( & V_152 , & V_159 ) ;
V_75 = 0 ;
F_33 ( & V_94 ) ;
F_124 (ap_dev, &ap_device_list, list) {
F_142 ( & V_43 -> V_58 ) ;
F_47 ( V_43 , & V_75 ) ;
F_143 ( & V_43 -> V_58 ) ;
}
F_34 ( & V_94 ) ;
}
F_107 ( V_163 ) ;
F_152 ( & V_152 , & V_159 ) ;
return 0 ;
}
static int F_57 ( void )
{
int V_30 ;
if ( F_1 () || V_76 )
return 0 ;
F_153 ( & V_164 ) ;
if ( ! V_109 ) {
V_109 = F_154 ( F_144 , NULL , L_19 ) ;
V_30 = F_155 ( V_109 ) ? F_156 ( V_109 ) : 0 ;
if ( V_30 )
V_109 = NULL ;
}
else
V_30 = 0 ;
F_157 ( & V_164 ) ;
return V_30 ;
}
static void F_82 ( void )
{
F_153 ( & V_164 ) ;
if ( V_109 ) {
F_158 ( V_109 ) ;
V_109 = NULL ;
}
F_157 ( & V_164 ) ;
}
static void V_142 ( unsigned long V_85 )
{
struct V_42 * V_43 = (struct V_42 * ) V_85 ;
if ( V_43 -> V_49 == V_50 ) {
V_43 -> V_49 = V_157 ;
if ( F_1 () )
F_56 ( & V_79 ) ;
}
}
static void F_159 ( void )
{
int V_16 ;
if ( V_82 != - 1 )
for ( V_16 = 0 ; V_16 < V_126 ; V_16 ++ )
F_8 ( F_3 ( V_16 , V_82 ) ) ;
}
static void F_160 ( void )
{
int V_16 , V_124 ;
for ( V_16 = 0 ; V_16 < V_125 ; V_16 ++ )
for ( V_124 = 0 ; V_124 < V_126 ; V_124 ++ )
F_8 ( F_3 ( V_124 , V_16 ) ) ;
}
int T_17 F_161 ( void )
{
int V_30 , V_16 ;
if ( V_82 < - 1 || V_82 >= V_125 ) {
F_162 ( L_20 ,
V_82 ) ;
return - V_14 ;
}
if ( V_82 >= 0 )
V_81 = 1 ;
if ( F_2 () != 0 ) {
F_162 ( L_21
L_22 ) ;
return - V_3 ;
}
if ( F_4 () ) {
F_163 ( V_9 ) ;
V_1 = F_164 (
& F_100 , NULL , V_9 ) ;
if ( F_155 ( V_1 ) ) {
V_1 = NULL ;
F_165 ( V_9 ) ;
}
}
F_166 ( & V_165 ) ;
V_30 = F_167 ( & V_106 ) ;
if ( V_30 )
goto V_128;
for ( V_16 = 0 ; V_166 [ V_16 ] ; V_16 ++ ) {
V_30 = F_168 ( & V_106 , V_166 [ V_16 ] ) ;
if ( V_30 )
goto V_167;
}
V_144 = F_169 ( L_23 ) ;
V_30 = F_155 ( V_144 ) ? F_156 ( V_144 ) : 0 ;
if ( V_30 )
goto V_167;
V_78 = F_53 ( L_16 ) ;
if ( ! V_78 ) {
V_30 = - V_89 ;
goto V_168;
}
F_49 () ;
if ( F_50 () == 0 )
F_105 ( NULL ) ;
F_51 ( & V_77 ) ;
V_77 . V_83 = V_84 ;
V_77 . V_85 = 0 ;
V_77 . V_86 = V_48 + V_87 * V_88 ;
F_52 ( & V_77 ) ;
if ( V_169 )
V_111 = 1500000 ;
F_111 ( & V_149 ) ;
F_170 ( & V_113 , V_170 , V_114 ) ;
V_113 . V_83 = F_138 ;
if ( V_90 ) {
V_30 = F_57 () ;
if ( V_30 )
goto V_171;
}
return 0 ;
V_171:
F_44 ( & V_77 ) ;
F_171 ( & V_113 ) ;
F_45 ( V_78 ) ;
V_168:
F_172 ( V_144 ) ;
V_167:
while ( V_16 -- )
F_173 ( & V_106 , V_166 [ V_16 ] ) ;
F_174 ( & V_106 ) ;
V_128:
F_175 ( & V_165 ) ;
if ( F_1 () ) {
F_176 ( V_1 , V_9 ) ;
F_165 ( V_9 ) ;
}
return V_30 ;
}
static int F_177 ( struct V_52 * V_53 , void * V_85 )
{
return 1 ;
}
void F_178 ( void )
{
int V_16 ;
struct V_52 * V_53 ;
F_159 () ;
F_82 () ;
F_44 ( & V_77 ) ;
F_171 ( & V_113 ) ;
F_45 ( V_78 ) ;
F_179 ( & V_79 ) ;
F_172 ( V_144 ) ;
while ( ( V_53 = F_106 ( & V_106 , NULL , NULL ,
F_177 ) ) )
{
F_109 ( V_53 ) ;
F_110 ( V_53 ) ;
}
for ( V_16 = 0 ; V_166 [ V_16 ] ; V_16 ++ )
F_173 ( & V_106 , V_166 [ V_16 ] ) ;
F_174 ( & V_106 ) ;
F_175 ( & V_165 ) ;
if ( F_1 () ) {
F_176 ( V_1 , V_9 ) ;
F_165 ( V_9 ) ;
}
}
