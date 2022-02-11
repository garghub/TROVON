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
F_24 ( V_42 ) ;
V_15 = F_7 ( V_5 , & V_41 , & V_41 ) ;
}
}
if ( V_30 == 0 && F_1 () ) {
V_30 = F_16 ( V_5 , V_43 . V_44 ) ;
if ( V_30 )
F_25 ( L_9
L_10 , F_26 ( V_5 ) ) ;
}
return V_30 ;
}
static void F_27 ( struct V_45 * V_46 )
{
int V_47 = V_46 -> V_48 -> V_49 ;
V_46 -> V_50 ++ ;
if ( V_46 -> V_50 == 1 ) {
F_28 ( & V_46 -> V_47 , V_51 + V_47 ) ;
V_46 -> V_52 = V_53 ;
}
}
static void F_29 ( struct V_45 * V_46 )
{
int V_47 = V_46 -> V_48 -> V_49 ;
V_46 -> V_50 -- ;
if ( V_46 -> V_50 > 0 )
F_28 ( & V_46 -> V_47 , V_51 + V_47 ) ;
else
V_46 -> V_52 = V_54 ;
}
static T_14 F_30 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_11 , V_46 -> V_7 ) ;
}
static T_14 F_32 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_11 , V_46 -> V_61 ) ;
}
static T_14 F_33 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_11 , V_46 -> V_6 ) ;
}
static T_14 F_34 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
int V_30 ;
F_35 ( & V_46 -> V_62 ) ;
V_30 = snprintf ( V_59 , V_60 , L_11 , V_46 -> V_63 ) ;
F_36 ( & V_46 -> V_62 ) ;
return V_30 ;
}
static T_14 F_37 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
int V_30 ;
F_35 ( & V_46 -> V_62 ) ;
V_30 = snprintf ( V_59 , V_60 , L_11 , V_46 -> V_64 ) ;
F_36 ( & V_46 -> V_62 ) ;
return V_30 ;
}
static T_14 F_38 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
int V_30 ;
F_35 ( & V_46 -> V_62 ) ;
V_30 = snprintf ( V_59 , V_60 , L_11 , V_46 -> V_65 ) ;
F_36 ( & V_46 -> V_62 ) ;
return V_30 ;
}
static T_14 F_39 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
return sprintf ( V_59 , L_12 , F_31 ( V_56 ) -> V_7 ) ;
}
static T_14 F_40 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
return snprintf ( V_59 , V_60 , L_13 , V_46 -> V_10 ) ;
}
static int F_41 ( struct V_55 * V_56 , struct V_66 * V_48 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
struct V_67 * V_68 = F_42 ( V_48 ) ;
struct V_69 * V_70 ;
for ( V_70 = V_68 -> V_71 ; V_70 -> V_72 ; V_70 ++ ) {
if ( ( V_70 -> V_72 & V_73 ) &&
( V_70 -> V_74 != V_46 -> V_7 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_55 * V_56 , struct V_75 * V_76 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
int V_77 = 0 ;
if ( ! V_46 )
return - V_3 ;
V_77 = F_44 ( V_76 , L_14 , V_46 -> V_7 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_44 ( V_76 , L_15 , V_46 -> V_7 ) ;
return V_77 ;
}
static int F_45 ( struct V_55 * V_56 , T_15 V_78 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
unsigned long V_79 ;
if ( ! V_80 ) {
V_80 = 1 ;
F_46 ( & V_81 ) ;
if ( V_82 != NULL ) {
F_47 ( V_82 ) ;
V_82 = NULL ;
}
F_48 ( & V_83 ) ;
}
do {
V_79 = 0 ;
F_35 ( & V_46 -> V_62 ) ;
F_49 ( V_46 , & V_79 ) ;
F_36 ( & V_46 -> V_62 ) ;
} while ( ( V_79 & 1 ) || ( V_79 & 2 ) );
F_35 ( & V_46 -> V_62 ) ;
V_46 -> V_84 = 1 ;
F_36 ( & V_46 -> V_62 ) ;
return 0 ;
}
static int F_50 ( struct V_55 * V_56 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
int V_30 ;
if ( V_80 ) {
V_80 = 0 ;
if ( F_4 () ) {
if ( ! F_1 () ) {
V_30 = F_51 ( & V_43 ) ;
V_1 = ( V_30 == 0 ) ;
}
} else {
if ( F_1 () ) {
F_52 ( & V_43 ) ;
V_1 = 0 ;
}
}
F_53 () ;
if ( ! V_85 ) {
V_86 = - 1 ;
F_54 () ;
}
F_55 ( & V_81 ) ;
V_81 . V_87 = V_88 ;
V_81 . V_89 = 0 ;
V_81 . V_90 = V_51 + V_91 * V_92 ;
F_56 ( & V_81 ) ;
V_82 = F_57 ( L_16 ) ;
if ( ! V_82 )
return - V_93 ;
F_58 ( & V_83 ) ;
if ( ! F_1 () )
F_59 () ;
else
F_60 ( & V_83 ) ;
if ( V_94 )
V_30 = F_61 () ;
else
V_30 = 0 ;
} else
V_30 = 0 ;
if ( F_62 ( V_46 -> V_5 ) != V_86 ) {
F_35 ( & V_46 -> V_62 ) ;
V_46 -> V_5 = F_3 ( F_26 ( V_46 -> V_5 ) ,
V_86 ) ;
F_36 ( & V_46 -> V_62 ) ;
}
F_63 ( V_82 , & V_95 ) ;
return V_30 ;
}
static int F_64 ( struct V_55 * V_56 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
struct V_67 * V_68 = F_42 ( V_56 -> V_96 ) ;
int V_30 ;
V_46 -> V_48 = V_68 ;
F_35 ( & V_97 ) ;
F_65 ( & V_46 -> V_98 , & V_99 ) ;
F_36 ( & V_97 ) ;
V_30 = V_68 -> V_100 ? V_68 -> V_100 ( V_46 ) : - V_3 ;
if ( V_30 ) {
F_35 ( & V_97 ) ;
F_66 ( & V_46 -> V_98 ) ;
F_36 ( & V_97 ) ;
}
return V_30 ;
}
static void F_67 ( struct V_45 * V_46 )
{
struct V_101 * V_102 , * V_103 ;
F_68 (ap_msg, next, &ap_dev->pendingq, list) {
F_66 ( & V_102 -> V_98 ) ;
V_46 -> V_65 -- ;
V_102 -> V_104 ( V_46 , V_102 , F_69 ( - V_3 ) ) ;
}
F_68 (ap_msg, next, &ap_dev->requestq, list) {
F_66 ( & V_102 -> V_98 ) ;
V_46 -> V_64 -- ;
V_102 -> V_104 ( V_46 , V_102 , F_69 ( - V_3 ) ) ;
}
}
void F_70 ( struct V_45 * V_46 )
{
F_35 ( & V_46 -> V_62 ) ;
F_67 ( V_46 ) ;
F_36 ( & V_46 -> V_62 ) ;
}
static int F_71 ( struct V_55 * V_56 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
struct V_67 * V_68 = V_46 -> V_48 ;
F_70 ( V_46 ) ;
F_46 ( & V_46 -> V_47 ) ;
F_35 ( & V_97 ) ;
F_66 ( & V_46 -> V_98 ) ;
F_36 ( & V_97 ) ;
if ( V_68 -> remove )
V_68 -> remove ( V_46 ) ;
F_35 ( & V_46 -> V_62 ) ;
F_72 ( V_46 -> V_50 , & V_105 ) ;
F_36 ( & V_46 -> V_62 ) ;
return 0 ;
}
int F_73 ( struct V_67 * V_68 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_66 * V_48 = & V_68 -> V_96 ;
V_48 -> V_109 = & V_110 ;
V_48 -> V_100 = F_64 ;
V_48 -> remove = F_71 ;
V_48 -> V_107 = V_107 ;
V_48 -> V_108 = V_108 ;
return F_74 ( V_48 ) ;
}
void F_75 ( struct V_67 * V_68 )
{
F_76 ( & V_68 -> V_96 ) ;
}
void F_77 ( void )
{
F_28 ( & V_81 , V_51 + V_91 * V_92 ) ;
F_63 ( V_82 , & V_95 ) ;
F_78 ( & V_95 ) ;
}
static T_14 F_79 ( struct V_111 * V_109 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_11 , V_86 ) ;
}
static T_14 F_80 ( struct V_111 * V_109 , char * V_59 )
{
if ( V_112 != NULL ) {
if ( F_5 ( 76 ) ) {
return snprintf ( V_59 , V_60 ,
L_17 ,
V_112 -> V_113 [ 0 ] , V_112 -> V_113 [ 1 ] ,
V_112 -> V_113 [ 2 ] , V_112 -> V_113 [ 3 ] ,
V_112 -> V_113 [ 4 ] , V_112 -> V_113 [ 5 ] ,
V_112 -> V_113 [ 6 ] , V_112 -> V_113 [ 7 ] ) ;
} else {
return snprintf ( V_59 , V_60 , L_18 ,
V_112 -> V_113 [ 0 ] , V_112 -> V_113 [ 1 ] ) ;
}
} else {
return snprintf ( V_59 , V_60 , L_19 ) ;
}
}
static T_14 F_81 ( struct V_111 * V_109 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_11 , V_91 ) ;
}
static T_14 F_82 ( struct V_111 * V_109 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_14 F_83 ( struct V_111 * V_109 ,
const char * V_59 , T_7 V_114 )
{
int time ;
if ( sscanf ( V_59 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_14 ;
V_91 = time ;
if ( ! F_84 ( & V_81 ) ||
! F_28 ( & V_81 , V_51 + V_91 * V_92 ) ) {
V_81 . V_90 = V_51 + V_91 * V_92 ;
F_56 ( & V_81 ) ;
}
return V_114 ;
}
static T_14 F_85 ( struct V_111 * V_109 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_11 , V_115 ? 1 : 0 ) ;
}
static T_14 F_86 ( struct V_111 * V_109 ,
const char * V_59 , T_7 V_114 )
{
int V_116 , V_30 ;
if ( sscanf ( V_59 , L_11 , & V_116 ) != 1 )
return - V_14 ;
if ( V_116 ) {
V_30 = F_61 () ;
if ( V_30 )
return V_30 ;
}
else
F_87 () ;
return V_114 ;
}
static T_14 F_88 ( struct V_111 * V_109 , char * V_59 )
{
return snprintf ( V_59 , V_60 , L_20 , V_117 ) ;
}
static T_14 F_89 ( struct V_111 * V_109 , const char * V_59 ,
T_7 V_114 )
{
unsigned long long time ;
T_16 V_118 ;
if ( sscanf ( V_59 , L_20 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_14 ;
V_117 = time ;
V_118 = F_90 ( 0 , V_117 ) ;
if ( ! F_91 ( & V_119 ) ||
! F_92 ( & V_119 , F_93 ( & V_119 ) , V_118 ) ) {
F_94 ( & V_119 , V_118 ) ;
F_95 ( & V_119 , V_120 ) ;
}
return V_114 ;
}
static inline int F_96 ( unsigned int * V_121 , unsigned int V_122 )
{
if ( V_122 > 0xFFu )
return 0 ;
return F_97 ( ( V_121 + ( V_122 >> 5 ) ) , ( V_122 & 0x1f ) ) ;
}
static inline int F_98 ( unsigned int V_70 )
{
if ( ! V_112 )
return 1 ;
return F_96 ( V_112 -> V_123 , V_70 ) ;
}
static inline int F_99 ( unsigned int V_124 )
{
if ( ! V_112 )
if ( V_124 < 16 )
return 1 ;
else
return 0 ;
else
return F_96 ( V_112 -> V_125 , V_124 ) ;
}
static void F_53 ( void )
{
#ifdef F_13
if ( F_6 () ) {
if ( ! V_112 )
V_112 =
F_100 ( sizeof( struct V_12 ) ,
V_126 ) ;
if ( V_112 )
F_11 ( V_112 ) ;
} else
V_112 = NULL ;
#else
V_112 = NULL ;
#endif
}
static int F_54 ( void )
{
int V_6 , V_7 , V_114 , V_127 , V_128 ;
T_4 V_5 ;
int V_30 , V_16 , V_129 ;
if ( ! V_112 -> V_130 && ( V_86 > 15 ) )
return - V_14 ;
if ( V_86 >= 0 && V_86 < V_131 )
return 0 ;
V_128 = - 1 ;
V_127 = 0 ;
for ( V_16 = 0 ; V_16 < V_131 ; V_16 ++ ) {
if ( ! F_99 ( V_16 ) )
continue;
V_114 = 0 ;
for ( V_129 = 0 ; V_129 < V_132 ; V_129 ++ ) {
if ( ! F_98 ( V_129 ) )
continue;
V_5 = F_3 ( V_129 , V_16 ) ;
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
if ( V_30 )
continue;
V_114 ++ ;
}
if ( V_114 > V_127 ) {
V_127 = V_114 ;
V_128 = V_16 ;
}
}
if ( V_128 >= 0 ) {
V_86 = V_128 ;
return 0 ;
}
return - V_3 ;
}
static int F_101 ( struct V_45 * V_46 )
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
char * V_133 ;
int V_30 , V_16 ;
V_133 = ( void * ) F_102 ( V_126 ) ;
if ( ! V_133 ) {
V_30 = - V_93 ;
goto V_134;
}
V_15 = F_17 ( V_46 -> V_5 , 0x0102030405060708ULL ,
V_33 , sizeof( V_33 ) , 0 ) ;
if ( V_15 . V_18 != V_19 ) {
V_30 = - V_3 ;
goto V_135;
}
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
F_103 ( 300 ) ;
V_15 = F_19 ( V_46 -> V_5 , & V_32 , V_133 , 4096 ) ;
if ( V_15 . V_18 == V_19 &&
V_32 == 0x0102030405060708ULL )
break;
}
if ( V_16 < 6 ) {
if ( V_133 [ 0 ] == 0x00 && V_133 [ 1 ] == 0x86 )
V_46 -> V_7 = V_136 ;
else
V_46 -> V_7 = V_137 ;
V_30 = 0 ;
} else
V_30 = - V_3 ;
V_135:
F_104 ( ( unsigned long ) V_133 ) ;
V_134:
return V_30 ;
}
static void F_105 ( struct V_138 * V_139 )
{
F_106 ( V_140 ) ;
F_60 ( & V_83 ) ;
}
static int F_107 ( struct V_55 * V_56 , void * V_89 )
{
return F_31 ( V_56 ) -> V_5 == ( T_4 ) ( unsigned long ) V_89 ;
}
static void F_108 ( struct V_55 * V_56 )
{
struct V_45 * V_46 = F_31 ( V_56 ) ;
F_109 ( V_46 ) ;
}
static void F_110 ( struct V_141 * V_142 )
{
struct V_45 * V_46 ;
struct V_55 * V_56 ;
T_4 V_5 ;
int V_6 , V_7 ;
unsigned int V_143 ;
int V_30 , V_16 ;
F_53 () ;
if ( F_54 () != 0 ) {
return;
}
for ( V_16 = 0 ; V_16 < V_132 ; V_16 ++ ) {
V_5 = F_3 ( V_16 , V_86 ) ;
V_56 = F_111 ( & V_110 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_107 ) ;
if ( F_98 ( V_16 ) )
V_30 = F_21 ( V_5 , & V_6 , & V_7 ) ;
else
V_30 = - V_3 ;
if ( V_56 ) {
if ( V_30 == - V_27 ) {
F_112 ( V_144 ) ;
F_24 ( V_42 ) ;
V_30 = F_21 ( V_5 , & V_6 ,
& V_7 ) ;
}
V_46 = F_31 ( V_56 ) ;
F_35 ( & V_46 -> V_62 ) ;
if ( V_30 || V_46 -> V_84 ) {
F_36 ( & V_46 -> V_62 ) ;
if ( V_46 -> V_84 )
V_16 -- ;
F_113 ( V_56 ) ;
F_114 ( V_56 ) ;
continue;
}
F_36 ( & V_46 -> V_62 ) ;
F_114 ( V_56 ) ;
continue;
}
if ( V_30 )
continue;
V_30 = F_23 ( V_5 ) ;
if ( V_30 )
continue;
V_46 = F_100 ( sizeof( * V_46 ) , V_126 ) ;
if ( ! V_46 )
break;
V_46 -> V_5 = V_5 ;
V_46 -> V_6 = V_6 ;
V_46 -> V_84 = 1 ;
F_115 ( & V_46 -> V_62 ) ;
F_116 ( & V_46 -> V_145 ) ;
F_116 ( & V_46 -> V_146 ) ;
F_116 ( & V_46 -> V_98 ) ;
F_117 ( & V_46 -> V_47 , V_147 ,
( unsigned long ) V_46 ) ;
switch ( V_7 ) {
case 0 :
if ( F_101 ( V_46 ) ) {
F_109 ( V_46 ) ;
continue;
}
break;
case 11 :
V_46 -> V_7 = 10 ;
break;
default:
V_46 -> V_7 = V_7 ;
}
V_46 -> V_61 = V_7 ;
V_30 = F_12 ( V_5 , & V_143 ) ;
if ( ! V_30 )
V_46 -> V_10 = V_143 ;
else
V_46 -> V_10 = 0u ;
V_46 -> V_55 . V_109 = & V_110 ;
V_46 -> V_55 . V_148 = V_149 ;
if ( F_118 ( & V_46 -> V_55 , L_21 ,
F_26 ( V_46 -> V_5 ) ) ) {
F_109 ( V_46 ) ;
continue;
}
V_46 -> V_55 . V_150 = F_108 ;
V_30 = F_119 ( & V_46 -> V_55 ) ;
if ( V_30 ) {
F_114 ( & V_46 -> V_55 ) ;
continue;
}
V_30 = F_120 ( & V_46 -> V_55 . V_151 ,
& V_152 ) ;
if ( ! V_30 ) {
F_35 ( & V_46 -> V_62 ) ;
V_46 -> V_84 = 0 ;
F_36 ( & V_46 -> V_62 ) ;
}
else
F_113 ( & V_46 -> V_55 ) ;
}
}
static void
V_88 ( unsigned long V_153 )
{
F_63 ( V_82 , & V_95 ) ;
V_81 . V_90 = V_51 + V_91 * V_92 ;
F_56 ( & V_81 ) ;
}
static inline void F_121 ( void )
{
T_16 V_118 ;
F_35 ( & V_154 ) ;
if ( F_91 ( & V_119 ) || V_80 )
goto V_134;
if ( F_122 ( F_123 ( & V_119 ) ) <= 0 ) {
V_118 = F_90 ( 0 , V_117 ) ;
F_124 ( & V_119 , V_118 ) ;
F_125 ( & V_119 ) ;
}
V_134:
F_36 ( & V_154 ) ;
}
static inline void F_59 ( void )
{
if ( F_1 () )
return;
F_121 () ;
}
static int F_126 ( struct V_45 * V_46 , unsigned long * V_79 )
{
struct V_4 V_15 ;
struct V_101 * V_102 ;
if ( V_46 -> V_50 <= 0 )
return 0 ;
V_15 = F_19 ( V_46 -> V_5 , & V_46 -> V_133 -> V_32 ,
V_46 -> V_133 -> V_155 , V_46 -> V_133 -> V_34 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_127 ( & V_105 ) ;
F_29 ( V_46 ) ;
F_128 (ap_msg, &ap_dev->pendingq, list) {
if ( V_102 -> V_32 != V_46 -> V_133 -> V_32 )
continue;
F_66 ( & V_102 -> V_98 ) ;
V_46 -> V_65 -- ;
V_102 -> V_104 ( V_46 , V_102 , V_46 -> V_133 ) ;
break;
}
if ( V_46 -> V_50 > 0 )
* V_79 |= 1 ;
break;
case V_38 :
if ( V_15 . V_39 ) {
F_72 ( V_46 -> V_50 , & V_105 ) ;
V_46 -> V_50 = 0 ;
F_129 ( & V_46 -> V_145 , & V_46 -> V_146 ) ;
V_46 -> V_64 += V_46 -> V_65 ;
V_46 -> V_65 = 0 ;
} else
* V_79 |= 2 ;
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_130 ( struct V_45 * V_46 , unsigned long * V_79 )
{
struct V_4 V_15 ;
struct V_101 * V_102 ;
if ( V_46 -> V_64 <= 0 ||
V_46 -> V_50 >= V_46 -> V_6 )
return 0 ;
V_102 = F_131 ( V_46 -> V_146 . V_103 , struct V_101 , V_98 ) ;
V_15 = F_17 ( V_46 -> V_5 , V_102 -> V_32 ,
V_102 -> V_155 , V_102 -> V_34 , V_102 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_132 ( & V_105 ) ;
F_27 ( V_46 ) ;
F_133 ( & V_102 -> V_98 , & V_46 -> V_145 ) ;
V_46 -> V_64 -- ;
V_46 -> V_65 ++ ;
if ( V_46 -> V_50 < V_46 -> V_6 &&
V_46 -> V_64 > 0 )
* V_79 |= 1 ;
* V_79 |= 2 ;
break;
case V_20 :
F_121 () ;
case V_36 :
* V_79 |= 2 ;
break;
case V_156 :
case V_37 :
return - V_14 ;
default:
return - V_3 ;
}
return 0 ;
}
static inline int F_134 ( struct V_45 * V_46 , unsigned long * V_79 )
{
int V_30 ;
V_30 = F_126 ( V_46 , V_79 ) ;
if ( V_30 )
return V_30 ;
return F_130 ( V_46 , V_79 ) ;
}
static int F_135 ( struct V_45 * V_46 , struct V_101 * V_102 )
{
struct V_4 V_15 ;
if ( F_136 ( & V_46 -> V_146 ) &&
V_46 -> V_50 < V_46 -> V_6 ) {
V_15 = F_17 ( V_46 -> V_5 , V_102 -> V_32 ,
V_102 -> V_155 , V_102 -> V_34 ,
V_102 -> V_35 ) ;
switch ( V_15 . V_18 ) {
case V_19 :
F_137 ( & V_102 -> V_98 , & V_46 -> V_145 ) ;
F_132 ( & V_105 ) ;
V_46 -> V_65 ++ ;
F_27 ( V_46 ) ;
V_46 -> V_63 ++ ;
break;
case V_36 :
case V_20 :
F_137 ( & V_102 -> V_98 , & V_46 -> V_146 ) ;
V_46 -> V_64 ++ ;
V_46 -> V_63 ++ ;
return - V_27 ;
case V_37 :
case V_156 :
V_102 -> V_104 ( V_46 , V_102 , F_69 ( - V_14 ) ) ;
return - V_14 ;
default:
V_102 -> V_104 ( V_46 , V_102 , F_69 ( - V_3 ) ) ;
return - V_3 ;
}
} else {
F_137 ( & V_102 -> V_98 , & V_46 -> V_146 ) ;
V_46 -> V_64 ++ ;
V_46 -> V_63 ++ ;
return - V_27 ;
}
F_59 () ;
return 0 ;
}
void F_138 ( struct V_45 * V_46 , struct V_101 * V_102 )
{
unsigned long V_79 ;
int V_30 ;
F_139 ( ! V_102 -> V_104 ) ;
F_35 ( & V_46 -> V_62 ) ;
if ( ! V_46 -> V_84 ) {
V_30 = F_134 ( V_46 , & V_79 ) ;
if ( ! V_30 )
V_30 = F_135 ( V_46 , V_102 ) ;
if ( ! V_30 )
F_140 ( & V_157 ) ;
if ( V_30 == - V_3 )
V_46 -> V_84 = 1 ;
} else {
V_102 -> V_104 ( V_46 , V_102 , F_69 ( - V_3 ) ) ;
V_30 = - V_3 ;
}
F_36 ( & V_46 -> V_62 ) ;
if ( V_30 == - V_3 )
F_113 ( & V_46 -> V_55 ) ;
}
void F_141 ( struct V_45 * V_46 , struct V_101 * V_102 )
{
struct V_101 * V_158 ;
F_35 ( & V_46 -> V_62 ) ;
if ( ! F_136 ( & V_102 -> V_98 ) ) {
F_128 (tmp, &ap_dev->pendingq, list)
if ( V_158 -> V_32 == V_102 -> V_32 ) {
V_46 -> V_65 -- ;
goto V_159;
}
V_46 -> V_64 -- ;
V_159:
F_66 ( & V_102 -> V_98 ) ;
}
F_36 ( & V_46 -> V_62 ) ;
}
static enum F_125 F_142 ( struct V_160 * V_142 )
{
F_60 ( & V_83 ) ;
return V_161 ;
}
static void F_143 ( struct V_45 * V_46 )
{
int V_30 ;
V_46 -> V_52 = V_54 ;
F_72 ( V_46 -> V_50 , & V_105 ) ;
V_46 -> V_50 = 0 ;
F_129 ( & V_46 -> V_145 , & V_46 -> V_146 ) ;
V_46 -> V_64 += V_46 -> V_65 ;
V_46 -> V_65 = 0 ;
V_30 = F_23 ( V_46 -> V_5 ) ;
if ( V_30 == - V_3 )
V_46 -> V_84 = 1 ;
else
F_121 () ;
}
static int F_49 ( struct V_45 * V_46 , unsigned long * V_79 )
{
if ( ! V_46 -> V_84 ) {
if ( F_134 ( V_46 , V_79 ) )
V_46 -> V_84 = 1 ;
if ( V_46 -> V_52 == V_162 )
F_143 ( V_46 ) ;
}
return 0 ;
}
static void F_144 ( unsigned long V_41 )
{
unsigned long V_79 ;
struct V_45 * V_46 ;
if ( F_1 () )
F_145 ( V_43 . V_44 , 0 ) ;
do {
V_79 = 0 ;
F_146 ( & V_97 ) ;
F_128 (ap_dev, &ap_device_list, list) {
F_146 ( & V_46 -> V_62 ) ;
F_49 ( V_46 , & V_79 ) ;
F_147 ( & V_46 -> V_62 ) ;
}
F_147 ( & V_97 ) ;
} while ( V_79 & 1 );
if ( V_79 & 2 )
F_59 () ;
}
static int F_148 ( void * V_89 )
{
F_149 ( V_163 , V_164 ) ;
unsigned long V_79 ;
int V_165 ;
struct V_45 * V_46 ;
F_150 ( V_164 , V_166 ) ;
while ( 1 ) {
if ( V_80 )
return 0 ;
if ( F_151 () ) {
F_152 () ;
continue;
}
F_153 ( & V_157 , & V_163 ) ;
F_112 ( V_167 ) ;
if ( F_154 () )
break;
V_165 = F_155 ( & V_105 ) ;
if ( V_165 <= 0 )
F_152 () ;
F_112 ( V_168 ) ;
F_156 ( & V_157 , & V_163 ) ;
V_79 = 0 ;
F_35 ( & V_97 ) ;
F_128 (ap_dev, &ap_device_list, list) {
F_146 ( & V_46 -> V_62 ) ;
F_49 ( V_46 , & V_79 ) ;
F_147 ( & V_46 -> V_62 ) ;
}
F_36 ( & V_97 ) ;
}
F_112 ( V_168 ) ;
F_156 ( & V_157 , & V_163 ) ;
return 0 ;
}
static int F_61 ( void )
{
int V_30 ;
if ( F_1 () || V_80 )
return 0 ;
F_157 ( & V_169 ) ;
if ( ! V_115 ) {
V_115 = F_158 ( F_148 , NULL , L_22 ) ;
V_30 = F_159 ( V_115 ) ;
if ( V_30 )
V_115 = NULL ;
}
else
V_30 = 0 ;
F_160 ( & V_169 ) ;
return V_30 ;
}
static void F_87 ( void )
{
F_157 ( & V_169 ) ;
if ( V_115 ) {
F_161 ( V_115 ) ;
V_115 = NULL ;
}
F_160 ( & V_169 ) ;
}
static void V_147 ( unsigned long V_89 )
{
struct V_45 * V_46 = (struct V_45 * ) V_89 ;
if ( V_46 -> V_52 == V_53 ) {
V_46 -> V_52 = V_162 ;
if ( F_1 () )
F_60 ( & V_83 ) ;
}
}
static void F_162 ( void )
{
int V_16 ;
if ( V_86 != - 1 )
for ( V_16 = 0 ; V_16 < V_132 ; V_16 ++ )
F_8 ( F_3 ( V_16 , V_86 ) ) ;
}
static void F_163 ( void )
{
int V_16 , V_129 ;
for ( V_16 = 0 ; V_16 < V_131 ; V_16 ++ ) {
if ( ! F_99 ( V_16 ) )
continue;
for ( V_129 = 0 ; V_129 < V_132 ; V_129 ++ ) {
if ( ! F_98 ( V_129 ) )
continue;
F_8 ( F_3 ( V_129 , V_16 ) ) ;
}
}
}
int T_17 F_164 ( void )
{
int V_30 , V_16 ;
if ( V_86 < - 1 || V_86 >= V_131 ) {
F_165 ( L_23 ,
V_86 ) ;
return - V_14 ;
}
if ( V_86 >= 0 )
V_85 = 1 ;
if ( F_2 () != 0 ) {
F_165 ( L_24
L_25 ) ;
return - V_3 ;
}
if ( F_4 () ) {
V_30 = F_51 ( & V_43 ) ;
V_1 = ( V_30 == 0 ) ;
}
F_166 ( & V_170 ) ;
V_30 = F_167 ( & V_110 ) ;
if ( V_30 )
goto V_134;
for ( V_16 = 0 ; V_171 [ V_16 ] ; V_16 ++ ) {
V_30 = F_168 ( & V_110 , V_171 [ V_16 ] ) ;
if ( V_30 )
goto V_172;
}
V_149 = F_169 ( L_26 ) ;
V_30 = F_159 ( V_149 ) ;
if ( V_30 )
goto V_172;
V_82 = F_57 ( L_16 ) ;
if ( ! V_82 ) {
V_30 = - V_93 ;
goto V_173;
}
F_53 () ;
if ( F_54 () == 0 )
F_110 ( NULL ) ;
F_55 ( & V_81 ) ;
V_81 . V_87 = V_88 ;
V_81 . V_89 = 0 ;
V_81 . V_90 = V_51 + V_91 * V_92 ;
F_56 ( & V_81 ) ;
if ( V_174 )
V_117 = 1500000 ;
F_115 ( & V_154 ) ;
F_170 ( & V_119 , V_175 , V_120 ) ;
V_119 . V_87 = F_142 ;
if ( V_94 ) {
V_30 = F_61 () ;
if ( V_30 )
goto V_176;
}
return 0 ;
V_176:
F_46 ( & V_81 ) ;
F_171 ( & V_119 ) ;
F_47 ( V_82 ) ;
V_173:
F_172 ( V_149 ) ;
V_172:
while ( V_16 -- )
F_173 ( & V_110 , V_171 [ V_16 ] ) ;
F_174 ( & V_110 ) ;
V_134:
F_175 ( & V_170 ) ;
if ( F_1 () )
F_52 ( & V_43 ) ;
return V_30 ;
}
static int F_176 ( struct V_55 * V_56 , void * V_89 )
{
return 1 ;
}
void F_177 ( void )
{
int V_16 ;
struct V_55 * V_56 ;
F_162 () ;
F_87 () ;
F_46 ( & V_81 ) ;
F_171 ( & V_119 ) ;
F_47 ( V_82 ) ;
F_178 ( & V_83 ) ;
F_172 ( V_149 ) ;
while ( ( V_56 = F_111 ( & V_110 , NULL , NULL ,
F_176 ) ) )
{
F_113 ( V_56 ) ;
F_114 ( V_56 ) ;
}
for ( V_16 = 0 ; V_171 [ V_16 ] ; V_16 ++ )
F_173 ( & V_110 , V_171 [ V_16 ] ) ;
F_174 ( & V_110 ) ;
F_175 ( & V_170 ) ;
if ( F_1 () )
F_52 ( & V_43 ) ;
}
