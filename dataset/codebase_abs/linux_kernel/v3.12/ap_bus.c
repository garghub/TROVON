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
register unsigned long T_11 V_2 ( L_6 ) = V_32 & 0xffffffff ;
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
V_30 = F_16 ( V_5 , V_42 . V_43 ) ;
if ( V_30 )
F_24 ( L_9
L_10 , F_25 ( V_5 ) ) ;
}
return V_30 ;
}
static void F_26 ( struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 -> V_48 ;
V_45 -> V_49 ++ ;
if ( V_45 -> V_49 == 1 ) {
F_27 ( & V_45 -> V_46 , V_50 + V_46 ) ;
V_45 -> V_51 = V_52 ;
}
}
static void F_28 ( struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 -> V_48 ;
V_45 -> V_49 -- ;
if ( V_45 -> V_49 > 0 )
F_27 ( & V_45 -> V_46 , V_50 + V_46 ) ;
else
V_45 -> V_51 = V_53 ;
}
static T_14 F_29 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
return snprintf ( V_58 , V_59 , L_11 , V_45 -> V_7 ) ;
}
static T_14 F_31 ( struct V_54 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
return snprintf ( V_58 , V_59 , L_11 , V_45 -> V_6 ) ;
}
static T_14 F_32 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
int V_30 ;
F_33 ( & V_45 -> V_60 ) ;
V_30 = snprintf ( V_58 , V_59 , L_11 , V_45 -> V_61 ) ;
F_34 ( & V_45 -> V_60 ) ;
return V_30 ;
}
static T_14 F_35 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
int V_30 ;
F_33 ( & V_45 -> V_60 ) ;
V_30 = snprintf ( V_58 , V_59 , L_11 , V_45 -> V_62 ) ;
F_34 ( & V_45 -> V_60 ) ;
return V_30 ;
}
static T_14 F_36 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
int V_30 ;
F_33 ( & V_45 -> V_60 ) ;
V_30 = snprintf ( V_58 , V_59 , L_11 , V_45 -> V_63 ) ;
F_34 ( & V_45 -> V_60 ) ;
return V_30 ;
}
static T_14 F_37 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_12 , F_30 ( V_55 ) -> V_7 ) ;
}
static T_14 F_38 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
return snprintf ( V_58 , V_59 , L_13 , V_45 -> V_10 ) ;
}
static int F_39 ( struct V_54 * V_55 , struct V_64 * V_47 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
struct V_65 * V_66 = F_40 ( V_47 ) ;
struct V_67 * V_68 ;
for ( V_68 = V_66 -> V_69 ; V_68 -> V_70 ; V_68 ++ ) {
if ( ( V_68 -> V_70 & V_71 ) &&
( V_68 -> V_72 != V_45 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_54 * V_55 , struct V_73 * V_74 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
int V_75 = 0 ;
if ( ! V_45 )
return - V_3 ;
V_75 = F_42 ( V_74 , L_14 , V_45 -> V_7 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_42 ( V_74 , L_15 , V_45 -> V_7 ) ;
return V_75 ;
}
static int F_43 ( struct V_54 * V_55 , T_15 V_76 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
unsigned long V_77 ;
if ( ! V_78 ) {
V_78 = 1 ;
F_44 ( & V_79 ) ;
if ( V_80 != NULL ) {
F_45 ( V_80 ) ;
V_80 = NULL ;
}
F_46 ( & V_81 ) ;
}
do {
V_77 = 0 ;
F_33 ( & V_45 -> V_60 ) ;
F_47 ( V_45 , & V_77 ) ;
F_34 ( & V_45 -> V_60 ) ;
} while ( ( V_77 & 1 ) || ( V_77 & 2 ) );
F_33 ( & V_45 -> V_60 ) ;
V_45 -> V_82 = 1 ;
F_34 ( & V_45 -> V_60 ) ;
return 0 ;
}
static int F_48 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
int V_30 ;
if ( V_78 ) {
V_78 = 0 ;
if ( F_4 () ) {
if ( ! F_1 () ) {
V_30 = F_49 ( & V_42 ) ;
V_1 = ( V_30 == 0 ) ;
}
} else {
if ( F_1 () ) {
F_50 ( & V_42 ) ;
V_1 = 0 ;
}
}
F_51 () ;
if ( ! V_83 ) {
V_84 = - 1 ;
F_52 () ;
}
F_53 ( & V_79 ) ;
V_79 . V_85 = V_86 ;
V_79 . V_87 = 0 ;
V_79 . V_88 = V_50 + V_89 * V_90 ;
F_54 ( & V_79 ) ;
V_80 = F_55 ( L_16 ) ;
if ( ! V_80 )
return - V_91 ;
F_56 ( & V_81 ) ;
if ( ! F_1 () )
F_57 () ;
else
F_58 ( & V_81 ) ;
if ( V_92 )
V_30 = F_59 () ;
else
V_30 = 0 ;
} else
V_30 = 0 ;
if ( F_60 ( V_45 -> V_5 ) != V_84 ) {
F_33 ( & V_45 -> V_60 ) ;
V_45 -> V_5 = F_3 ( F_25 ( V_45 -> V_5 ) ,
V_84 ) ;
F_34 ( & V_45 -> V_60 ) ;
}
F_61 ( V_80 , & V_93 ) ;
return V_30 ;
}
static int F_62 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
struct V_65 * V_66 = F_40 ( V_55 -> V_94 ) ;
int V_30 ;
V_45 -> V_47 = V_66 ;
V_30 = V_66 -> V_95 ? V_66 -> V_95 ( V_45 ) : - V_3 ;
if ( ! V_30 ) {
F_33 ( & V_96 ) ;
F_63 ( & V_45 -> V_97 , & V_98 ) ;
F_34 ( & V_96 ) ;
}
return V_30 ;
}
static void F_64 ( struct V_44 * V_45 )
{
struct V_99 * V_100 , * V_101 ;
F_65 (ap_msg, next, &ap_dev->pendingq, list) {
F_66 ( & V_100 -> V_97 ) ;
V_45 -> V_63 -- ;
V_100 -> V_102 ( V_45 , V_100 , F_67 ( - V_3 ) ) ;
}
F_65 (ap_msg, next, &ap_dev->requestq, list) {
F_66 ( & V_100 -> V_97 ) ;
V_45 -> V_62 -- ;
V_100 -> V_102 ( V_45 , V_100 , F_67 ( - V_3 ) ) ;
}
}
void F_68 ( struct V_44 * V_45 )
{
F_33 ( & V_45 -> V_60 ) ;
F_64 ( V_45 ) ;
F_34 ( & V_45 -> V_60 ) ;
}
static int F_69 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
struct V_65 * V_66 = V_45 -> V_47 ;
F_68 ( V_45 ) ;
F_44 ( & V_45 -> V_46 ) ;
F_33 ( & V_96 ) ;
F_66 ( & V_45 -> V_97 ) ;
F_34 ( & V_96 ) ;
if ( V_66 -> remove )
V_66 -> remove ( V_45 ) ;
F_33 ( & V_45 -> V_60 ) ;
F_70 ( V_45 -> V_49 , & V_103 ) ;
F_34 ( & V_45 -> V_60 ) ;
return 0 ;
}
int F_71 ( struct V_65 * V_66 , struct V_104 * V_105 ,
char * V_106 )
{
struct V_64 * V_47 = & V_66 -> V_94 ;
V_47 -> V_107 = & V_108 ;
V_47 -> V_95 = F_62 ;
V_47 -> remove = F_69 ;
V_47 -> V_105 = V_105 ;
V_47 -> V_106 = V_106 ;
return F_72 ( V_47 ) ;
}
void F_73 ( struct V_65 * V_66 )
{
F_74 ( & V_66 -> V_94 ) ;
}
void F_75 ( void )
{
F_27 ( & V_79 , V_50 + V_89 * V_90 ) ;
F_61 ( V_80 , & V_93 ) ;
F_76 ( & V_93 ) ;
}
static T_14 F_77 ( struct V_109 * V_107 , char * V_58 )
{
return snprintf ( V_58 , V_59 , L_11 , V_84 ) ;
}
static T_14 F_78 ( struct V_109 * V_107 , char * V_58 )
{
return snprintf ( V_58 , V_59 , L_11 , V_89 ) ;
}
static T_14 F_79 ( struct V_109 * V_107 , char * V_58 )
{
return snprintf ( V_58 , V_59 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_14 F_80 ( struct V_109 * V_107 ,
const char * V_58 , T_7 V_110 )
{
int time ;
if ( sscanf ( V_58 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_14 ;
V_89 = time ;
if ( ! F_81 ( & V_79 ) ||
! F_27 ( & V_79 , V_50 + V_89 * V_90 ) ) {
V_79 . V_88 = V_50 + V_89 * V_90 ;
F_54 ( & V_79 ) ;
}
return V_110 ;
}
static T_14 F_82 ( struct V_109 * V_107 , char * V_58 )
{
return snprintf ( V_58 , V_59 , L_11 , V_111 ? 1 : 0 ) ;
}
static T_14 F_83 ( struct V_109 * V_107 ,
const char * V_58 , T_7 V_110 )
{
int V_112 , V_30 ;
if ( sscanf ( V_58 , L_11 , & V_112 ) != 1 )
return - V_14 ;
if ( V_112 ) {
V_30 = F_59 () ;
if ( V_30 )
return V_30 ;
}
else
F_84 () ;
return V_110 ;
}
static T_14 F_85 ( struct V_109 * V_107 , char * V_58 )
{
return snprintf ( V_58 , V_59 , L_17 , V_113 ) ;
}
static T_14 F_86 ( struct V_109 * V_107 , const char * V_58 ,
T_7 V_110 )
{
unsigned long long time ;
T_16 V_114 ;
if ( sscanf ( V_58 , L_17 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_14 ;
V_113 = time ;
V_114 = F_87 ( 0 , V_113 ) ;
if ( ! F_88 ( & V_115 ) ||
! F_89 ( & V_115 , F_90 ( & V_115 ) , V_114 ) ) {
F_91 ( & V_115 , V_114 ) ;
F_92 ( & V_115 , V_116 ) ;
}
return V_110 ;
}
static inline int F_93 ( unsigned int * V_117 , unsigned int V_118 )
{
if ( V_118 > 0xFFu )
return 0 ;
return F_94 ( ( V_117 + ( V_118 >> 5 ) ) , ( V_118 & 0x1f ) ) ;
}
static inline int F_95 ( unsigned int V_68 )
{
if ( ! V_119 )
return 1 ;
return F_93 ( V_119 -> V_120 , V_68 ) ;
}
static inline int F_96 ( unsigned int V_121 )
{
if ( ! V_119 )
return 1 ;
return F_93 ( V_119 -> V_122 , V_121 ) ;
}
static void F_51 ( void )
{
#ifdef F_13
if ( F_6 () ) {
if ( ! V_119 )
V_119 =
F_97 ( sizeof( struct V_12 ) ,
V_123 ) ;
if ( V_119 )
F_11 ( V_119 ) ;
} else
V_119 = NULL ;
#else
V_119 = NULL ;
#endif
}
static int F_52 ( void )
{
int V_6 , V_7 , V_110 , V_124 , V_125 ;
T_4 V_5 ;
int V_30 , V_16 , V_126 ;
if ( V_84 >= 0 && V_84 < V_127 )
return 0 ;
V_125 = - 1 ;
V_124 = 0 ;
for ( V_16 = 0 ; V_16 < V_127 ; V_16 ++ ) {
if ( ! F_96 ( V_16 ) )
continue;
V_110 = 0 ;
for ( V_126 = 0 ; V_126 < V_128 ; V_126 ++ ) {
if ( ! F_95 ( V_126 ) )
continue;
V_5 = F_3 ( V_126 , V_16 ) ;
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
if ( V_30 )
continue;
V_110 ++ ;
}
if ( V_110 > V_124 ) {
V_124 = V_110 ;
V_125 = V_16 ;
}
}
if ( V_125 >= 0 ) {
V_84 = V_125 ;
return 0 ;
}
return - V_3 ;
}
static int F_98 ( struct V_44 * V_45 )
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
char * V_129 ;
int V_30 , V_16 ;
V_129 = ( void * ) F_99 ( V_123 ) ;
if ( ! V_129 ) {
V_30 = - V_91 ;
goto V_130;
}
V_15 = F_17 ( V_45 -> V_5 , 0x0102030405060708ULL ,
V_33 , sizeof( V_33 ) , 0 ) ;
if ( V_15 . V_18 != V_19 ) {
V_30 = - V_3 ;
goto V_131;
}
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
F_100 ( 300 ) ;
V_15 = F_19 ( V_45 -> V_5 , & V_32 , V_129 , 4096 ) ;
if ( V_15 . V_18 == V_19 &&
V_32 == 0x0102030405060708ULL )
break;
}
if ( V_16 < 6 ) {
if ( V_129 [ 0 ] == 0x00 && V_129 [ 1 ] == 0x86 )
V_45 -> V_7 = V_132 ;
else
V_45 -> V_7 = V_133 ;
V_30 = 0 ;
} else
V_30 = - V_3 ;
V_131:
F_101 ( ( unsigned long ) V_129 ) ;
V_130:
return V_30 ;
}
static void F_102 ( struct V_134 * V_135 )
{
F_103 ( V_136 ) ;
F_58 ( & V_81 ) ;
}
static int F_104 ( struct V_54 * V_55 , void * V_87 )
{
return F_30 ( V_55 ) -> V_5 == ( T_4 ) ( unsigned long ) V_87 ;
}
static void F_105 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = F_30 ( V_55 ) ;
F_106 ( V_45 ) ;
}
static void F_107 ( struct V_137 * V_138 )
{
struct V_44 * V_45 ;
struct V_54 * V_55 ;
T_4 V_5 ;
int V_6 , V_7 ;
unsigned int V_139 ;
int V_30 , V_16 ;
F_51 () ;
if ( F_52 () != 0 ) {
return;
}
for ( V_16 = 0 ; V_16 < V_128 ; V_16 ++ ) {
V_5 = F_3 ( V_16 , V_84 ) ;
V_55 = F_108 ( & V_108 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_104 ) ;
if ( F_95 ( V_16 ) )
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
else
V_30 = - V_3 ;
if ( V_55 ) {
if ( V_30 == - V_27 ) {
F_109 ( V_140 ) ;
F_110 ( V_141 ) ;
V_30 = F_21 ( V_5 , & V_6 ,
& V_7 ) ;
}
V_45 = F_30 ( V_55 ) ;
F_33 ( & V_45 -> V_60 ) ;
if ( V_30 || V_45 -> V_82 ) {
F_34 ( & V_45 -> V_60 ) ;
if ( V_45 -> V_82 )
V_16 -- ;
F_111 ( V_55 ) ;
F_112 ( V_55 ) ;
continue;
}
F_34 ( & V_45 -> V_60 ) ;
F_112 ( V_55 ) ;
continue;
}
if ( V_30 )
continue;
V_30 = F_23 ( V_5 ) ;
if ( V_30 )
continue;
V_45 = F_97 ( sizeof( * V_45 ) , V_123 ) ;
if ( ! V_45 )
break;
V_45 -> V_5 = V_5 ;
V_45 -> V_6 = V_6 ;
V_45 -> V_82 = 1 ;
F_113 ( & V_45 -> V_60 ) ;
F_114 ( & V_45 -> V_142 ) ;
F_114 ( & V_45 -> V_143 ) ;
F_114 ( & V_45 -> V_97 ) ;
F_115 ( & V_45 -> V_46 , V_144 ,
( unsigned long ) V_45 ) ;
switch ( V_7 ) {
case 0 :
if ( F_98 ( V_45 ) ) {
F_106 ( V_45 ) ;
continue;
}
break;
default:
V_45 -> V_7 = V_7 ;
}
V_30 = F_12 ( V_5 , & V_139 ) ;
if ( ! V_30 )
V_45 -> V_10 = V_139 ;
else
V_45 -> V_10 = 0u ;
V_45 -> V_54 . V_107 = & V_108 ;
V_45 -> V_54 . V_145 = V_146 ;
if ( F_116 ( & V_45 -> V_54 , L_18 ,
F_25 ( V_45 -> V_5 ) ) ) {
F_106 ( V_45 ) ;
continue;
}
V_45 -> V_54 . V_147 = F_105 ;
V_30 = F_117 ( & V_45 -> V_54 ) ;
if ( V_30 ) {
F_112 ( & V_45 -> V_54 ) ;
continue;
}
V_30 = F_118 ( & V_45 -> V_54 . V_148 ,
& V_149 ) ;
if ( ! V_30 ) {
F_33 ( & V_45 -> V_60 ) ;
V_45 -> V_82 = 0 ;
F_34 ( & V_45 -> V_60 ) ;
}
else
F_111 ( & V_45 -> V_54 ) ;
}
}
static void
V_86 ( unsigned long V_150 )
{
F_61 ( V_80 , & V_93 ) ;
V_79 . V_88 = V_50 + V_89 * V_90 ;
F_54 ( & V_79 ) ;
}
static inline void F_119 ( void )
{
T_16 V_114 ;
F_33 ( & V_151 ) ;
if ( F_88 ( & V_115 ) || V_78 )
goto V_130;
if ( F_120 ( F_121 ( & V_115 ) ) <= 0 ) {
V_114 = F_87 ( 0 , V_113 ) ;
F_122 ( & V_115 , V_114 ) ;
F_123 ( & V_115 ) ;
}
V_130:
F_34 ( & V_151 ) ;
}
static inline void F_57 ( void )
{
if ( F_1 () )
return;
F_119 () ;
}
static int F_124 ( struct V_44 * V_45 , unsigned long * V_77 )
{
struct V_4 V_15 ;
struct V_99 * V_100 ;
if ( V_45 -> V_49 <= 0 )
return 0 ;
V_15 = F_19 ( V_45 -> V_5 , & V_45 -> V_129 -> V_32 ,
V_45 -> V_129 -> V_152 , V_45 -> V_129 -> V_34 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_125 ( & V_103 ) ;
F_28 ( V_45 ) ;
F_126 (ap_msg, &ap_dev->pendingq, list) {
if ( V_100 -> V_32 != V_45 -> V_129 -> V_32 )
continue;
F_66 ( & V_100 -> V_97 ) ;
V_45 -> V_63 -- ;
V_100 -> V_102 ( V_45 , V_100 , V_45 -> V_129 ) ;
break;
}
if ( V_45 -> V_49 > 0 )
* V_77 |= 1 ;
break;
case V_38 :
if ( V_15 . V_39 ) {
F_70 ( V_45 -> V_49 , & V_103 ) ;
V_45 -> V_49 = 0 ;
F_127 ( & V_45 -> V_142 , & V_45 -> V_143 ) ;
V_45 -> V_62 += V_45 -> V_63 ;
V_45 -> V_63 = 0 ;
} else
* V_77 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_128 ( struct V_44 * V_45 , unsigned long * V_77 )
{
struct V_4 V_15 ;
struct V_99 * V_100 ;
if ( V_45 -> V_62 <= 0 ||
V_45 -> V_49 >= V_45 -> V_6 )
return 0 ;
V_100 = F_129 ( V_45 -> V_143 . V_101 , struct V_99 , V_97 ) ;
V_15 = F_17 ( V_45 -> V_5 , V_100 -> V_32 ,
V_100 -> V_152 , V_100 -> V_34 , V_100 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_130 ( & V_103 ) ;
F_26 ( V_45 ) ;
F_131 ( & V_100 -> V_97 , & V_45 -> V_142 ) ;
V_45 -> V_62 -- ;
V_45 -> V_63 ++ ;
if ( V_45 -> V_49 < V_45 -> V_6 &&
V_45 -> V_62 > 0 )
* V_77 |= 1 ;
* V_77 |= 2 ;
break;
case V_20 :
F_119 () ;
case V_36 :
* V_77 |= 2 ;
break;
case V_153 :
case V_37 :
return - V_14 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_132 ( struct V_44 * V_45 , unsigned long * V_77 )
{
int V_30 ;
V_30 = F_124 ( V_45 , V_77 ) ;
if ( V_30 )
return V_30 ;
return F_128 ( V_45 , V_77 ) ;
}
static int F_133 ( struct V_44 * V_45 , struct V_99 * V_100 )
{
struct V_4 V_15 ;
if ( F_134 ( & V_45 -> V_143 ) &&
V_45 -> V_49 < V_45 -> V_6 ) {
V_15 = F_17 ( V_45 -> V_5 , V_100 -> V_32 ,
V_100 -> V_152 , V_100 -> V_34 ,
V_100 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_135 ( & V_100 -> V_97 , & V_45 -> V_142 ) ;
F_130 ( & V_103 ) ;
V_45 -> V_63 ++ ;
F_26 ( V_45 ) ;
V_45 -> V_61 ++ ;
break;
case V_36 :
case V_20 :
F_135 ( & V_100 -> V_97 , & V_45 -> V_143 ) ;
V_45 -> V_62 ++ ;
V_45 -> V_61 ++ ;
return - V_27 ;
case V_37 :
case V_153 :
V_100 -> V_102 ( V_45 , V_100 , F_67 ( - V_14 ) ) ;
return - V_14 ;
default:
V_100 -> V_102 ( V_45 , V_100 , F_67 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_135 ( & V_100 -> V_97 , & V_45 -> V_143 ) ;
V_45 -> V_62 ++ ;
V_45 -> V_61 ++ ;
return - V_27 ;
}
F_57 () ;
return 0 ;
}
void F_136 ( struct V_44 * V_45 , struct V_99 * V_100 )
{
unsigned long V_77 ;
int V_30 ;
F_137 ( ! V_100 -> V_102 ) ;
F_33 ( & V_45 -> V_60 ) ;
if ( ! V_45 -> V_82 ) {
V_30 = F_132 ( V_45 , & V_77 ) ;
if ( ! V_30 )
V_30 = F_133 ( V_45 , V_100 ) ;
if ( ! V_30 )
F_138 ( & V_154 ) ;
if ( V_30 == - V_3 )
V_45 -> V_82 = 1 ;
} else {
V_100 -> V_102 ( V_45 , V_100 , F_67 ( - V_3 ) ) ;
V_30 = - V_3 ;
}
F_34 ( & V_45 -> V_60 ) ;
if ( V_30 == - V_3 )
F_111 ( & V_45 -> V_54 ) ;
}
void F_139 ( struct V_44 * V_45 , struct V_99 * V_100 )
{
struct V_99 * V_155 ;
F_33 ( & V_45 -> V_60 ) ;
if ( ! F_134 ( & V_100 -> V_97 ) ) {
F_126 (tmp, &ap_dev->pendingq, list)
if ( V_155 -> V_32 == V_100 -> V_32 ) {
V_45 -> V_63 -- ;
goto V_156;
}
V_45 -> V_62 -- ;
V_156:
F_66 ( & V_100 -> V_97 ) ;
}
F_34 ( & V_45 -> V_60 ) ;
}
static enum F_123 F_140 ( struct V_157 * V_138 )
{
F_58 ( & V_81 ) ;
return V_158 ;
}
static void F_141 ( struct V_44 * V_45 )
{
int V_30 ;
V_45 -> V_51 = V_53 ;
F_70 ( V_45 -> V_49 , & V_103 ) ;
V_45 -> V_49 = 0 ;
F_127 ( & V_45 -> V_142 , & V_45 -> V_143 ) ;
V_45 -> V_62 += V_45 -> V_63 ;
V_45 -> V_63 = 0 ;
V_30 = F_23 ( V_45 -> V_5 ) ;
if ( V_30 == - V_3 )
V_45 -> V_82 = 1 ;
else
F_119 () ;
}
static int F_47 ( struct V_44 * V_45 , unsigned long * V_77 )
{
if ( ! V_45 -> V_82 ) {
if ( F_132 ( V_45 , V_77 ) )
V_45 -> V_82 = 1 ;
if ( V_45 -> V_51 == V_159 )
F_141 ( V_45 ) ;
}
return 0 ;
}
static void F_142 ( unsigned long V_41 )
{
unsigned long V_77 ;
struct V_44 * V_45 ;
if ( F_1 () )
F_143 ( V_42 . V_43 , 0 ) ;
do {
V_77 = 0 ;
F_144 ( & V_96 ) ;
F_126 (ap_dev, &ap_device_list, list) {
F_144 ( & V_45 -> V_60 ) ;
F_47 ( V_45 , & V_77 ) ;
F_145 ( & V_45 -> V_60 ) ;
}
F_145 ( & V_96 ) ;
} while ( V_77 & 1 );
if ( V_77 & 2 )
F_57 () ;
}
static int F_146 ( void * V_87 )
{
F_147 ( V_160 , V_161 ) ;
unsigned long V_77 ;
int V_162 ;
struct V_44 * V_45 ;
F_148 ( V_161 , 19 ) ;
while ( 1 ) {
if ( V_78 )
return 0 ;
if ( F_149 () ) {
F_150 () ;
continue;
}
F_151 ( & V_154 , & V_160 ) ;
F_109 ( V_163 ) ;
if ( F_152 () )
break;
V_162 = F_153 ( & V_103 ) ;
if ( V_162 <= 0 )
F_150 () ;
F_109 ( V_164 ) ;
F_154 ( & V_154 , & V_160 ) ;
V_77 = 0 ;
F_33 ( & V_96 ) ;
F_126 (ap_dev, &ap_device_list, list) {
F_144 ( & V_45 -> V_60 ) ;
F_47 ( V_45 , & V_77 ) ;
F_145 ( & V_45 -> V_60 ) ;
}
F_34 ( & V_96 ) ;
}
F_109 ( V_164 ) ;
F_154 ( & V_154 , & V_160 ) ;
return 0 ;
}
static int F_59 ( void )
{
int V_30 ;
if ( F_1 () || V_78 )
return 0 ;
F_155 ( & V_165 ) ;
if ( ! V_111 ) {
V_111 = F_156 ( F_146 , NULL , L_19 ) ;
V_30 = F_157 ( V_111 ) ;
if ( V_30 )
V_111 = NULL ;
}
else
V_30 = 0 ;
F_158 ( & V_165 ) ;
return V_30 ;
}
static void F_84 ( void )
{
F_155 ( & V_165 ) ;
if ( V_111 ) {
F_159 ( V_111 ) ;
V_111 = NULL ;
}
F_158 ( & V_165 ) ;
}
static void V_144 ( unsigned long V_87 )
{
struct V_44 * V_45 = (struct V_44 * ) V_87 ;
if ( V_45 -> V_51 == V_52 ) {
V_45 -> V_51 = V_159 ;
if ( F_1 () )
F_58 ( & V_81 ) ;
}
}
static void F_160 ( void )
{
int V_16 ;
if ( V_84 != - 1 )
for ( V_16 = 0 ; V_16 < V_128 ; V_16 ++ )
F_8 ( F_3 ( V_16 , V_84 ) ) ;
}
static void F_161 ( void )
{
int V_16 , V_126 ;
for ( V_16 = 0 ; V_16 < V_127 ; V_16 ++ )
for ( V_126 = 0 ; V_126 < V_128 ; V_126 ++ )
F_8 ( F_3 ( V_126 , V_16 ) ) ;
}
int T_17 F_162 ( void )
{
int V_30 , V_16 ;
if ( V_84 < - 1 || V_84 >= V_127 ) {
F_163 ( L_20 ,
V_84 ) ;
return - V_14 ;
}
if ( V_84 >= 0 )
V_83 = 1 ;
if ( F_2 () != 0 ) {
F_163 ( L_21
L_22 ) ;
return - V_3 ;
}
if ( F_4 () ) {
V_30 = F_49 ( & V_42 ) ;
V_1 = ( V_30 == 0 ) ;
}
F_164 ( & V_166 ) ;
V_30 = F_165 ( & V_108 ) ;
if ( V_30 )
goto V_130;
for ( V_16 = 0 ; V_167 [ V_16 ] ; V_16 ++ ) {
V_30 = F_166 ( & V_108 , V_167 [ V_16 ] ) ;
if ( V_30 )
goto V_168;
}
V_146 = F_167 ( L_23 ) ;
V_30 = F_157 ( V_146 ) ;
if ( V_30 )
goto V_168;
V_80 = F_55 ( L_16 ) ;
if ( ! V_80 ) {
V_30 = - V_91 ;
goto V_169;
}
F_51 () ;
if ( F_52 () == 0 )
F_107 ( NULL ) ;
F_53 ( & V_79 ) ;
V_79 . V_85 = V_86 ;
V_79 . V_87 = 0 ;
V_79 . V_88 = V_50 + V_89 * V_90 ;
F_54 ( & V_79 ) ;
if ( V_170 )
V_113 = 1500000 ;
F_113 ( & V_151 ) ;
F_168 ( & V_115 , V_171 , V_116 ) ;
V_115 . V_85 = F_140 ;
if ( V_92 ) {
V_30 = F_59 () ;
if ( V_30 )
goto V_172;
}
return 0 ;
V_172:
F_44 ( & V_79 ) ;
F_169 ( & V_115 ) ;
F_45 ( V_80 ) ;
V_169:
F_170 ( V_146 ) ;
V_168:
while ( V_16 -- )
F_171 ( & V_108 , V_167 [ V_16 ] ) ;
F_172 ( & V_108 ) ;
V_130:
F_173 ( & V_166 ) ;
if ( F_1 () )
F_50 ( & V_42 ) ;
return V_30 ;
}
static int F_174 ( struct V_54 * V_55 , void * V_87 )
{
return 1 ;
}
void F_175 ( void )
{
int V_16 ;
struct V_54 * V_55 ;
F_160 () ;
F_84 () ;
F_44 ( & V_79 ) ;
F_169 ( & V_115 ) ;
F_45 ( V_80 ) ;
F_176 ( & V_81 ) ;
F_170 ( V_146 ) ;
while ( ( V_55 = F_108 ( & V_108 , NULL , NULL ,
F_174 ) ) )
{
F_111 ( V_55 ) ;
F_112 ( V_55 ) ;
}
for ( V_16 = 0 ; V_167 [ V_16 ] ; V_16 ++ )
F_171 ( & V_108 , V_167 [ V_16 ] ) ;
F_172 ( & V_108 ) ;
F_173 ( & V_166 ) ;
if ( F_1 () )
F_50 ( & V_42 ) ;
}
