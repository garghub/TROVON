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
F_7 ( T_4 V_5 , unsigned long * V_6 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
asm volatile(".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
* V_6 = T_3 ;
return T_2 ;
}
static inline struct V_4
F_8 ( T_4 V_5 , unsigned long * V_6 )
{
struct V_4 V_7 ;
unsigned long V_8 ;
if ( F_5 ( 15 ) )
V_5 |= 1UL << 23 ;
V_7 = F_7 ( V_5 , & V_8 ) ;
if ( V_6 )
* V_6 = V_8 ;
return V_7 ;
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
F_10 ( T_4 V_5 , void * V_9 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x03000000UL ;
register unsigned long T_5 V_2 ( L_2 ) = 0x0000800000000000UL | V_10 ;
register struct V_4 T_6 V_2 ( L_2 ) ;
register void * T_3 V_2 ( L_3 ) = V_9 ;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "+d" (reg1_in), "=d" (reg1_out), "+d" (reg2)
:
: "cc" );
return T_6 ;
}
static inline int F_11 ( void )
{
register unsigned long T_1 V_2 ( L_1 ) = 0x04000000UL ;
register unsigned long T_2 V_2 ( L_2 ) = - V_11 ;
register void * T_3 V_2 ( L_3 ) = ( void * ) V_12 ;
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
static inline int F_12 ( void )
{
if ( ! V_12 )
return - V_13 ;
return F_11 () ;
}
static void F_13 ( void )
{
if ( ! F_6 () )
return;
V_12 = F_14 ( sizeof( * V_12 ) , V_14 ) ;
if ( ! V_12 )
return;
if ( F_12 () != 0 ) {
F_15 ( V_12 ) ;
V_12 = NULL ;
return;
}
}
static inline int F_16 ( unsigned int * V_15 , unsigned int V_16 )
{
return F_17 ( ( V_15 + ( V_16 >> 5 ) ) , ( V_16 & 0x1f ) ) ;
}
static inline int F_18 ( unsigned int V_17 )
{
if ( ! V_12 )
return 1 ;
return F_16 ( V_12 -> V_18 , V_17 ) ;
}
static inline int F_19 ( unsigned int V_19 )
{
if ( ! V_12 )
return V_19 < 16 ;
return F_16 ( V_12 -> V_20 , V_19 ) ;
}
static int F_20 ( struct V_21 * V_22 , void * V_9 )
{
struct V_4 V_23 ;
V_23 = F_10 ( V_22 -> V_5 , V_9 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
case V_26 :
return 0 ;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
F_21 ( L_4 ,
F_22 ( V_22 -> V_5 ) ) ;
return - V_13 ;
case V_31 :
case V_32 :
default:
return - V_33 ;
}
}
static inline struct V_4
F_23 ( T_4 V_5 , unsigned long long V_34 , void * V_35 , T_7 V_36 )
{
typedef struct { char _ [ V_36 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_35 ;
register unsigned long T_9 V_2 ( L_5 ) = ( unsigned long ) V_36 ;
register unsigned long T_10 V_2 ( L_6 ) = ( unsigned int ) ( V_34 >> 32 ) ;
register unsigned long T_11 V_2 ( L_7 ) = V_34 & 0xffffffff ;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc");
return T_2 ;
}
static inline struct V_4
F_24 ( T_4 V_5 , unsigned long long V_34 , void * V_35 , T_7 V_36 ,
unsigned int V_37 )
{
if ( V_37 == 1 )
V_5 |= 0x400000UL ;
return F_23 ( V_5 , V_34 , V_35 , V_36 ) ;
}
int F_25 ( T_4 V_5 , unsigned long long V_34 , void * V_35 , T_7 V_36 )
{
struct V_4 V_23 ;
V_23 = F_24 ( V_5 , V_34 , V_35 , V_36 , 0 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
return 0 ;
case V_38 :
case V_31 :
return - V_33 ;
case V_39 :
return - V_11 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_26 ( T_4 V_5 , unsigned long long * V_34 , void * V_35 , T_7 V_36 )
{
typedef struct { char _ [ V_36 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_6 ) = ( unsigned long ) V_35 ;
register unsigned long T_11 V_2 ( L_7 ) = ( unsigned long ) V_36 ;
register unsigned long T_12 V_2 ( L_8 ) = 0UL ;
register unsigned long T_13 V_2 ( L_9 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_34 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_27 ( T_4 V_5 , unsigned long long * V_34 , void * V_35 , T_7 V_36 )
{
struct V_4 V_23 ;
if ( V_35 == NULL )
return - V_11 ;
V_23 = F_26 ( V_5 , V_34 , V_35 , V_36 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
return 0 ;
case V_40 :
if ( V_23 . V_41 )
return - V_42 ;
return - V_33 ;
case V_31 :
return - V_33 ;
default:
return - V_3 ;
}
}
static int F_28 ( T_4 V_5 , int * V_43 , int * V_44 ,
unsigned int * V_45 )
{
struct V_4 V_23 ;
unsigned long V_6 ;
int V_46 ;
if ( ! F_18 ( F_22 ( V_5 ) ) )
return - V_3 ;
V_23 = F_8 ( V_5 , & V_6 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
* V_43 = ( int ) ( V_6 & 0xff ) ;
* V_44 = ( int ) ( ( V_6 >> 24 ) & 0xff ) ;
* V_45 = ( unsigned int ) ( V_6 >> 32 ) ;
V_46 = ( V_6 >> 16 ) & 0xff ;
if ( ( V_6 & ( 1UL << 57 ) ) && V_46 > 0 )
V_47 = V_46 ;
return 0 ;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return - V_3 ;
case V_31 :
case V_26 :
case V_32 :
return - V_33 ;
default:
F_29 () ;
}
}
static void F_30 ( enum V_48 V_49 )
{
T_14 V_50 ;
switch ( V_49 ) {
case V_51 :
case V_52 :
if ( F_1 () )
break;
if ( V_53 ) {
F_31 ( & V_54 ) ;
break;
}
case V_55 :
F_32 ( & V_56 ) ;
if ( ! F_33 ( & V_57 ) ) {
V_50 = F_34 ( 0 , V_58 ) ;
F_35 ( & V_57 , V_50 ) ;
F_36 ( & V_57 ) ;
}
F_37 ( & V_56 ) ;
break;
case V_59 :
default:
break;
}
}
static enum V_48 F_38 ( struct V_21 * V_22 )
{
return V_59 ;
}
static struct V_4 F_39 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
struct V_60 * V_61 ;
V_23 = F_26 ( V_22 -> V_5 , & V_22 -> V_62 -> V_34 ,
V_22 -> V_62 -> V_63 , V_22 -> V_62 -> V_36 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
F_40 ( & V_64 ) ;
V_22 -> V_65 -- ;
if ( V_22 -> V_65 > 0 )
F_41 ( & V_22 -> V_66 ,
V_67 + V_22 -> V_68 -> V_69 ) ;
F_42 (ap_msg, &ap_dev->pendingq, list) {
if ( V_61 -> V_34 != V_22 -> V_62 -> V_34 )
continue;
F_43 ( & V_61 -> V_70 ) ;
V_22 -> V_71 -- ;
V_61 -> V_72 ( V_22 , V_61 , V_22 -> V_62 ) ;
break;
}
case V_40 :
if ( ! V_23 . V_41 || V_22 -> V_65 <= 0 )
break;
F_44 ( V_22 -> V_65 , & V_64 ) ;
V_22 -> V_65 = 0 ;
F_45 ( & V_22 -> V_73 , & V_22 -> V_74 ) ;
V_22 -> V_75 += V_22 -> V_71 ;
V_22 -> V_71 = 0 ;
break;
default:
break;
}
return V_23 ;
}
static enum V_48 F_46 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
if ( ! V_22 -> V_62 )
return V_59 ;
V_23 = F_39 ( V_22 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
if ( V_22 -> V_65 > 0 ) {
V_22 -> V_76 = V_77 ;
return V_51 ;
}
V_22 -> V_76 = V_78 ;
return V_59 ;
case V_40 :
if ( V_22 -> V_65 > 0 )
return V_52 ;
V_22 -> V_76 = V_78 ;
return V_59 ;
default:
V_22 -> V_76 = V_79 ;
return V_59 ;
}
}
static enum V_48 F_47 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
if ( ! V_22 -> V_62 )
return V_59 ;
V_23 = F_39 ( V_22 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
if ( V_22 -> V_65 > 0 )
return V_51 ;
default:
return V_59 ;
}
}
static enum V_48 F_48 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
struct V_60 * V_61 ;
if ( V_22 -> V_75 <= 0 )
return V_59 ;
V_61 = F_49 ( V_22 -> V_74 . V_80 , struct V_60 , V_70 ) ;
V_23 = F_24 ( V_22 -> V_5 , V_61 -> V_34 ,
V_61 -> V_63 , V_61 -> V_36 , V_61 -> V_37 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
F_50 ( & V_64 ) ;
V_22 -> V_65 ++ ;
if ( V_22 -> V_65 == 1 )
F_41 ( & V_22 -> V_66 ,
V_67 + V_22 -> V_68 -> V_69 ) ;
F_51 ( & V_61 -> V_70 , & V_22 -> V_73 ) ;
V_22 -> V_75 -- ;
V_22 -> V_71 ++ ;
if ( V_22 -> V_65 < V_22 -> V_43 ) {
V_22 -> V_76 = V_77 ;
return V_51 ;
}
case V_38 :
V_22 -> V_76 = V_81 ;
return V_52 ;
case V_31 :
V_22 -> V_76 = V_82 ;
return V_55 ;
case V_83 :
case V_39 :
F_43 ( & V_61 -> V_70 ) ;
V_22 -> V_75 -- ;
V_61 -> V_84 = - V_11 ;
V_61 -> V_72 ( V_22 , V_61 , NULL ) ;
return V_51 ;
default:
V_22 -> V_76 = V_79 ;
return V_59 ;
}
}
static enum V_48 F_52 ( struct V_21 * V_22 )
{
return F_53 ( F_46 ( V_22 ) , F_48 ( V_22 ) ) ;
}
static enum V_48 F_54 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
V_23 = F_9 ( V_22 -> V_5 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
case V_31 :
V_22 -> V_76 = V_82 ;
V_22 -> V_85 = V_86 ;
return V_55 ;
case V_32 :
return V_55 ;
case V_27 :
case V_28 :
case V_29 :
default:
V_22 -> V_76 = V_79 ;
return V_59 ;
}
}
static enum V_48 F_55 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
unsigned long V_6 ;
if ( V_22 -> V_65 > 0 && V_22 -> V_62 )
V_23 = F_39 ( V_22 ) ;
else
V_23 = F_8 ( V_22 -> V_5 , & V_6 ) ;
switch ( V_23 . V_24 ) {
case V_25 :
if ( F_1 () &&
F_20 ( V_22 ,
V_87 . V_88 ) == 0 )
V_22 -> V_76 = V_89 ;
else
V_22 -> V_76 = ( V_22 -> V_65 > 0 ) ?
V_77 : V_78 ;
return V_51 ;
case V_32 :
case V_31 :
return V_55 ;
case V_27 :
case V_28 :
case V_29 :
default:
V_22 -> V_76 = V_79 ;
return V_59 ;
}
}
static enum V_48 F_56 ( struct V_21 * V_22 )
{
struct V_4 V_23 ;
unsigned long V_6 ;
if ( V_22 -> V_65 > 0 && V_22 -> V_62 )
V_23 = F_39 ( V_22 ) ;
else
V_23 = F_8 ( V_22 -> V_5 , & V_6 ) ;
if ( V_23 . V_90 == 1 ) {
V_22 -> V_85 = V_91 ;
V_22 -> V_76 = ( V_22 -> V_65 > 0 ) ?
V_77 : V_78 ;
}
switch ( V_23 . V_24 ) {
case V_25 :
if ( V_22 -> V_65 > 0 )
return V_51 ;
case V_40 :
return V_55 ;
default:
V_22 -> V_76 = V_79 ;
return V_59 ;
}
}
static inline enum V_48 F_57 ( struct V_21 * V_22 ,
enum V_92 V_93 )
{
return V_94 [ V_22 -> V_76 ] [ V_93 ] ( V_22 ) ;
}
static inline enum V_48 F_58 ( struct V_21 * V_22 ,
enum V_92 V_93 )
{
enum V_48 V_49 ;
while ( ( V_49 = F_57 ( V_22 , V_93 ) ) == V_51 )
;
return V_49 ;
}
static void F_59 ( unsigned long V_95 )
{
struct V_21 * V_22 = (struct V_21 * ) V_95 ;
if ( V_96 )
return;
F_32 ( & V_22 -> V_97 ) ;
F_30 ( F_57 ( V_22 , V_98 ) ) ;
F_37 ( & V_22 -> V_97 ) ;
}
static enum F_36 F_60 ( struct V_99 * V_100 )
{
if ( ! V_96 )
F_61 ( & V_101 ) ;
return V_102 ;
}
static void F_62 ( struct V_103 * V_104 )
{
F_63 ( V_105 ) ;
if ( ! V_96 )
F_61 ( & V_101 ) ;
}
static void F_64 ( unsigned long V_106 )
{
struct V_21 * V_22 ;
enum V_48 V_49 = V_59 ;
if ( F_1 () )
F_65 ( V_87 . V_88 , 0 ) ;
F_66 ( & V_107 ) ;
F_42 (ap_dev, &ap_device_list, list) {
F_32 ( & V_22 -> V_97 ) ;
V_49 = F_53 ( V_49 , F_58 ( V_22 , V_108 ) ) ;
F_37 ( & V_22 -> V_97 ) ;
}
F_67 ( & V_107 ) ;
F_30 ( V_49 ) ;
}
static int F_68 ( void * V_95 )
{
F_69 ( V_49 , V_109 ) ;
F_70 ( V_109 , V_110 ) ;
F_71 () ;
while ( ! F_72 () ) {
F_73 ( & V_54 , & V_49 ) ;
F_74 ( V_111 ) ;
if ( V_96 ||
F_75 ( & V_64 ) <= 0 ) {
F_76 () ;
F_77 () ;
}
F_74 ( V_112 ) ;
F_78 ( & V_54 , & V_49 ) ;
if ( F_79 () ) {
F_76 () ;
F_77 () ;
continue;
}
F_64 ( 0 ) ;
} while ( ! F_72 () ) ;
return 0 ;
}
static int F_80 ( void )
{
int V_84 ;
if ( F_1 () || V_53 )
return 0 ;
F_81 ( & V_113 ) ;
V_53 = F_82 ( F_68 , NULL , L_10 ) ;
V_84 = F_83 ( V_53 ) ;
if ( V_84 )
V_53 = NULL ;
F_84 ( & V_113 ) ;
return V_84 ;
}
static void F_85 ( void )
{
if ( ! V_53 )
return;
F_81 ( & V_113 ) ;
F_86 ( V_53 ) ;
V_53 = NULL ;
F_84 ( & V_113 ) ;
}
void F_87 ( struct V_21 * V_22 , struct V_60 * V_61 )
{
F_88 ( ! V_61 -> V_72 ) ;
F_32 ( & V_22 -> V_97 ) ;
F_89 ( & V_61 -> V_70 , & V_22 -> V_74 ) ;
V_22 -> V_75 ++ ;
V_22 -> V_114 ++ ;
F_30 ( F_58 ( V_22 , V_108 ) ) ;
F_37 ( & V_22 -> V_97 ) ;
}
void F_90 ( struct V_21 * V_22 , struct V_60 * V_61 )
{
struct V_60 * V_115 ;
F_32 ( & V_22 -> V_97 ) ;
if ( ! F_91 ( & V_61 -> V_70 ) ) {
F_42 (tmp, &ap_dev->pendingq, list)
if ( V_115 -> V_34 == V_61 -> V_34 ) {
V_22 -> V_71 -- ;
goto V_116;
}
V_22 -> V_75 -- ;
V_116:
F_43 ( & V_61 -> V_70 ) ;
}
F_37 ( & V_22 -> V_97 ) ;
}
static T_15 F_92 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
return snprintf ( V_121 , V_122 , L_11 , V_22 -> V_44 ) ;
}
static T_15 F_94 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
return snprintf ( V_121 , V_122 , L_11 , V_22 -> V_123 ) ;
}
static T_15 F_95 ( struct V_117 * V_118 , struct V_119 * V_120 ,
char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
return snprintf ( V_121 , V_122 , L_11 , V_22 -> V_43 ) ;
}
static T_15 F_96 ( struct V_117 * V_118 ,
struct V_119 * V_120 ,
char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_84 ;
F_32 ( & V_22 -> V_97 ) ;
V_84 = snprintf ( V_121 , V_122 , L_11 , V_22 -> V_114 ) ;
F_37 ( & V_22 -> V_97 ) ;
return V_84 ;
}
static T_15 F_97 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_84 ;
F_32 ( & V_22 -> V_97 ) ;
V_84 = snprintf ( V_121 , V_122 , L_11 , V_22 -> V_75 ) ;
F_37 ( & V_22 -> V_97 ) ;
return V_84 ;
}
static T_15 F_98 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_84 ;
F_32 ( & V_22 -> V_97 ) ;
V_84 = snprintf ( V_121 , V_122 , L_11 , V_22 -> V_71 ) ;
F_37 ( & V_22 -> V_97 ) ;
return V_84 ;
}
static T_15 F_99 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_84 = 0 ;
F_32 ( & V_22 -> V_97 ) ;
switch ( V_22 -> V_76 ) {
case V_124 :
case V_82 :
V_84 = snprintf ( V_121 , V_122 , L_12 ) ;
break;
case V_77 :
case V_81 :
V_84 = snprintf ( V_121 , V_122 , L_13 ) ;
break;
default:
V_84 = snprintf ( V_121 , V_122 , L_14 ) ;
}
F_37 ( & V_22 -> V_97 ) ;
return V_84 ;
}
static T_15 F_100 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_84 = 0 ;
F_32 ( & V_22 -> V_97 ) ;
if ( V_22 -> V_76 == V_89 )
V_84 = snprintf ( V_121 , V_122 , L_15 ) ;
else if ( V_22 -> V_85 == V_91 )
V_84 = snprintf ( V_121 , V_122 , L_16 ) ;
else
V_84 = snprintf ( V_121 , V_122 , L_17 ) ;
F_37 ( & V_22 -> V_97 ) ;
return V_84 ;
}
static T_15 F_101 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
return sprintf ( V_121 , L_18 , F_93 ( V_118 ) -> V_44 ) ;
}
static T_15 F_102 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
return snprintf ( V_121 , V_122 , L_19 , V_22 -> V_125 ) ;
}
static int F_103 ( struct V_117 * V_118 , struct V_126 * V_68 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
struct V_127 * V_128 = F_104 ( V_68 ) ;
struct V_129 * V_17 ;
for ( V_17 = V_128 -> V_130 ; V_17 -> V_131 ; V_17 ++ ) {
if ( ( V_17 -> V_131 & V_132 ) &&
( V_17 -> V_133 != V_22 -> V_44 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_105 ( struct V_117 * V_118 , struct V_134 * V_135 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
int V_136 = 0 ;
if ( ! V_22 )
return - V_3 ;
V_136 = F_106 ( V_135 , L_20 , V_22 -> V_44 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_106 ( V_135 , L_21 , V_22 -> V_44 ) ;
return V_136 ;
}
static int F_107 ( struct V_117 * V_118 , T_16 V_76 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
F_32 ( & V_22 -> V_97 ) ;
V_22 -> V_76 = V_137 ;
while ( F_57 ( V_22 , V_108 ) != V_59 )
;
V_22 -> V_76 = V_79 ;
F_37 ( & V_22 -> V_97 ) ;
return 0 ;
}
static int F_108 ( struct V_117 * V_118 )
{
return 0 ;
}
static void F_109 ( void )
{
V_96 = 1 ;
F_110 ( & V_138 ) ;
F_111 ( & V_101 ) ;
}
static int F_112 ( struct V_117 * V_118 , void * V_106 )
{
F_113 ( V_118 ) ;
return 0 ;
}
static void F_114 ( void )
{
int V_84 ;
F_115 ( & V_139 , NULL , NULL , F_112 ) ;
if ( F_4 () && ! F_1 () ) {
V_84 = F_116 ( & V_87 ) ;
V_1 = ( V_84 == 0 ) ;
}
if ( ! F_4 () && F_1 () ) {
F_117 ( & V_87 ) ;
V_1 = 0 ;
}
if ( ! V_140 )
V_141 = - 1 ;
V_96 = 0 ;
if ( V_1 )
F_65 ( V_87 . V_88 , 0 ) ;
F_118 ( & V_101 ) ;
F_119 ( V_142 , & V_138 ) ;
}
static int F_120 ( struct V_143 * V_144 , unsigned long V_93 ,
void * V_145 )
{
switch ( V_93 ) {
case V_146 :
case V_147 :
F_109 () ;
break;
case V_148 :
case V_149 :
F_114 () ;
break;
default:
break;
}
return V_150 ;
}
void F_121 ( struct V_21 * V_22 ,
struct V_60 * V_62 )
{
V_22 -> V_62 = V_62 ;
F_32 ( & V_22 -> V_97 ) ;
F_30 ( F_57 ( V_22 , V_108 ) ) ;
F_37 ( & V_22 -> V_97 ) ;
}
static int F_122 ( struct V_117 * V_118 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
struct V_127 * V_128 = F_104 ( V_118 -> V_151 ) ;
int V_84 ;
V_22 -> V_68 = V_128 ;
V_84 = V_128 -> V_152 ? V_128 -> V_152 ( V_22 ) : - V_3 ;
if ( V_84 )
V_22 -> V_68 = NULL ;
return V_84 ;
}
static void F_123 ( struct V_21 * V_22 )
{
struct V_60 * V_61 , * V_80 ;
F_124 (ap_msg, next, &ap_dev->pendingq, list) {
F_43 ( & V_61 -> V_70 ) ;
V_22 -> V_71 -- ;
V_61 -> V_84 = - V_153 ;
V_61 -> V_72 ( V_22 , V_61 , NULL ) ;
}
F_124 (ap_msg, next, &ap_dev->requestq, list) {
F_43 ( & V_61 -> V_70 ) ;
V_22 -> V_75 -- ;
V_61 -> V_84 = - V_153 ;
V_61 -> V_72 ( V_22 , V_61 , NULL ) ;
}
}
void F_125 ( struct V_21 * V_22 )
{
F_32 ( & V_22 -> V_97 ) ;
F_123 ( V_22 ) ;
F_37 ( & V_22 -> V_97 ) ;
}
static int F_126 ( struct V_117 * V_118 )
{
struct V_21 * V_22 = F_93 ( V_118 ) ;
struct V_127 * V_128 = V_22 -> V_68 ;
F_125 ( V_22 ) ;
F_127 ( & V_22 -> V_66 ) ;
F_32 ( & V_107 ) ;
F_43 ( & V_22 -> V_70 ) ;
F_37 ( & V_107 ) ;
if ( V_128 -> remove )
V_128 -> remove ( V_22 ) ;
F_32 ( & V_22 -> V_97 ) ;
F_44 ( V_22 -> V_65 , & V_64 ) ;
F_37 ( & V_22 -> V_97 ) ;
return 0 ;
}
static void F_128 ( struct V_117 * V_118 )
{
F_15 ( F_93 ( V_118 ) ) ;
}
int F_129 ( struct V_127 * V_128 , struct V_154 * V_155 ,
char * V_156 )
{
struct V_126 * V_68 = & V_128 -> V_151 ;
if ( ! V_157 )
return - V_3 ;
V_68 -> V_158 = & V_139 ;
V_68 -> V_152 = F_122 ;
V_68 -> remove = F_126 ;
V_68 -> V_155 = V_155 ;
V_68 -> V_156 = V_156 ;
return F_130 ( V_68 ) ;
}
void F_131 ( struct V_127 * V_128 )
{
F_132 ( & V_128 -> V_151 ) ;
}
void F_133 ( void )
{
if ( V_96 )
return;
F_134 ( & V_159 ) ;
F_119 ( V_142 , & V_138 ) ;
F_110 ( & V_138 ) ;
}
static T_15 F_135 ( struct V_160 * V_158 , char * V_121 )
{
return snprintf ( V_121 , V_122 , L_11 , V_141 ) ;
}
static T_15 F_136 ( struct V_160 * V_158 , char * V_121 )
{
if ( ! V_12 )
return snprintf ( V_121 , V_122 , L_22 ) ;
if ( ! F_5 ( 76 ) )
return snprintf ( V_121 , V_122 , L_23 ,
V_12 -> V_161 [ 0 ] ,
V_12 -> V_161 [ 1 ] ) ;
return snprintf ( V_121 , V_122 ,
L_24 ,
V_12 -> V_161 [ 0 ] , V_12 -> V_161 [ 1 ] ,
V_12 -> V_161 [ 2 ] , V_12 -> V_161 [ 3 ] ,
V_12 -> V_161 [ 4 ] , V_12 -> V_161 [ 5 ] ,
V_12 -> V_161 [ 6 ] , V_12 -> V_161 [ 7 ] ) ;
}
static T_15 F_137 ( struct V_160 * V_158 , char * V_121 )
{
return snprintf ( V_121 , V_122 , L_11 , V_162 ) ;
}
static T_15 F_138 ( struct V_160 * V_158 , char * V_121 )
{
return snprintf ( V_121 , V_122 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_15 F_139 ( struct V_160 * V_158 ,
const char * V_121 , T_7 V_163 )
{
int time ;
if ( sscanf ( V_121 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_11 ;
V_162 = time ;
F_41 ( & V_159 , V_67 + V_162 * V_164 ) ;
return V_163 ;
}
static T_15 F_140 ( struct V_160 * V_158 , char * V_121 )
{
return snprintf ( V_121 , V_122 , L_11 , V_53 ? 1 : 0 ) ;
}
static T_15 F_141 ( struct V_160 * V_158 ,
const char * V_121 , T_7 V_163 )
{
int V_165 , V_84 ;
if ( sscanf ( V_121 , L_11 , & V_165 ) != 1 )
return - V_11 ;
if ( V_165 ) {
V_84 = F_80 () ;
if ( V_84 )
V_163 = V_84 ;
} else
F_85 () ;
return V_163 ;
}
static T_15 F_142 ( struct V_160 * V_158 , char * V_121 )
{
return snprintf ( V_121 , V_122 , L_25 , V_58 ) ;
}
static T_15 F_143 ( struct V_160 * V_158 , const char * V_121 ,
T_7 V_163 )
{
unsigned long long time ;
T_14 V_50 ;
if ( sscanf ( V_121 , L_25 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_11 ;
V_58 = time ;
V_50 = F_34 ( 0 , V_58 ) ;
F_32 ( & V_56 ) ;
F_144 ( & V_57 ) ;
F_145 ( & V_57 , V_50 ) ;
F_146 ( & V_57 , V_166 ) ;
F_37 ( & V_56 ) ;
return V_163 ;
}
static T_15 F_147 ( struct V_160 * V_158 , char * V_121 )
{
int V_167 ;
if ( V_12 )
V_167 = V_47 ? : - 1 ;
else
V_167 = 15 ;
return snprintf ( V_121 , V_122 , L_11 , V_167 ) ;
}
static int F_148 ( void )
{
int V_163 , V_168 , V_169 ;
struct V_4 V_23 ;
int V_170 , V_171 ;
if ( V_141 >= 0 )
return 0 ;
V_169 = - 1 ;
V_168 = 0 ;
for ( V_170 = 0 ; V_170 < V_172 ; V_170 ++ ) {
if ( ! F_19 ( V_170 ) )
continue;
V_163 = 0 ;
for ( V_171 = 0 ; V_171 < V_173 ; V_171 ++ ) {
if ( ! F_18 ( V_171 ) )
continue;
V_23 = F_8 ( F_3 ( V_171 , V_170 ) , NULL ) ;
if ( V_23 . V_24 != V_25 )
continue;
V_163 ++ ;
}
if ( V_163 > V_168 ) {
V_168 = V_163 ;
V_169 = V_170 ;
}
}
if ( V_169 >= 0 ) {
V_141 = V_169 ;
return 0 ;
}
return - V_3 ;
}
static int F_149 ( struct V_117 * V_118 , void * V_95 )
{
return F_93 ( V_118 ) -> V_5 == ( T_4 ) ( unsigned long ) V_95 ;
}
static void F_150 ( struct V_174 * V_100 )
{
struct V_21 * V_22 ;
struct V_117 * V_118 ;
T_4 V_5 ;
int V_43 = 0 , V_44 = 0 ;
unsigned int V_175 = 0 ;
int V_84 , V_170 , V_176 ;
F_12 () ;
if ( F_148 () != 0 )
goto V_177;
for ( V_170 = 0 ; V_170 < V_173 ; V_170 ++ ) {
V_5 = F_3 ( V_170 , V_141 ) ;
V_118 = F_151 ( & V_139 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_149 ) ;
V_84 = F_28 ( V_5 , & V_43 , & V_44 ,
& V_175 ) ;
if ( V_118 ) {
V_22 = F_93 ( V_118 ) ;
F_32 ( & V_22 -> V_97 ) ;
if ( V_84 == - V_3 )
V_22 -> V_76 = V_79 ;
V_176 = V_22 -> V_76 == V_79 ;
F_37 ( & V_22 -> V_97 ) ;
if ( V_176 )
F_113 ( V_118 ) ;
F_152 ( V_118 ) ;
if ( ! V_176 )
continue;
}
if ( V_84 )
continue;
V_22 = F_14 ( sizeof( * V_22 ) , V_14 ) ;
if ( ! V_22 )
break;
V_22 -> V_5 = V_5 ;
V_22 -> V_76 = V_124 ;
V_22 -> V_85 = V_86 ;
V_22 -> V_43 = V_43 ;
V_22 -> V_123 = V_44 ;
V_22 -> V_44 = V_44 ;
V_22 -> V_125 = V_175 ;
F_153 ( & V_22 -> V_97 ) ;
F_154 ( & V_22 -> V_73 ) ;
F_154 ( & V_22 -> V_74 ) ;
F_154 ( & V_22 -> V_70 ) ;
F_155 ( & V_22 -> V_66 , F_59 ,
( unsigned long ) V_22 ) ;
V_22 -> V_117 . V_158 = & V_139 ;
V_22 -> V_117 . V_178 = V_179 ;
V_84 = F_156 ( & V_22 -> V_117 , L_26 ,
F_22 ( V_22 -> V_5 ) ) ;
if ( V_84 ) {
F_15 ( V_22 ) ;
continue;
}
F_32 ( & V_107 ) ;
F_157 ( & V_22 -> V_70 , & V_180 ) ;
F_37 ( & V_107 ) ;
F_32 ( & V_22 -> V_97 ) ;
F_30 ( F_57 ( V_22 , V_108 ) ) ;
F_37 ( & V_22 -> V_97 ) ;
V_22 -> V_117 . V_181 = F_128 ;
V_84 = F_158 ( & V_22 -> V_117 ) ;
if ( V_84 ) {
F_32 ( & V_22 -> V_97 ) ;
F_43 ( & V_22 -> V_70 ) ;
F_37 ( & V_22 -> V_97 ) ;
F_152 ( & V_22 -> V_117 ) ;
continue;
}
V_84 = F_159 ( & V_22 -> V_117 . V_182 ,
& V_183 ) ;
if ( V_84 ) {
F_113 ( & V_22 -> V_117 ) ;
continue;
}
}
V_177:
F_41 ( & V_159 , V_67 + V_162 * V_164 ) ;
}
static void F_160 ( unsigned long V_145 )
{
if ( V_96 )
return;
F_119 ( V_142 , & V_138 ) ;
}
static void F_161 ( void )
{
int V_170 ;
if ( V_141 == - 1 || ! F_19 ( V_141 ) )
return;
for ( V_170 = 0 ; V_170 < V_173 ; V_170 ++ )
F_9 ( F_3 ( V_170 , V_141 ) ) ;
}
static void F_162 ( void )
{
int V_170 , V_171 ;
for ( V_170 = 0 ; V_170 < V_172 ; V_170 ++ ) {
if ( ! F_19 ( V_170 ) )
continue;
for ( V_171 = 0 ; V_171 < V_173 ; V_171 ++ ) {
if ( ! F_18 ( V_171 ) )
continue;
F_9 ( F_3 ( V_171 , V_170 ) ) ;
}
}
}
int T_17 F_163 ( void )
{
int V_167 ;
int V_84 , V_170 ;
if ( F_2 () != 0 ) {
F_164 ( L_27 ) ;
return - V_3 ;
}
F_13 () ;
if ( V_12 )
V_167 = V_47 ? : ( V_172 - 1 ) ;
else
V_167 = 15 ;
if ( V_141 < - 1 || V_141 > V_167 ) {
F_164 ( L_28 ,
V_141 ) ;
V_84 = - V_11 ;
goto V_184;
}
if ( V_141 >= 0 )
V_140 = 1 ;
if ( F_4 () ) {
V_84 = F_116 ( & V_87 ) ;
V_1 = ( V_84 == 0 ) ;
}
F_165 ( & V_185 ) ;
V_84 = F_166 ( & V_139 ) ;
if ( V_84 )
goto V_177;
for ( V_170 = 0 ; V_186 [ V_170 ] ; V_170 ++ ) {
V_84 = F_167 ( & V_139 , V_186 [ V_170 ] ) ;
if ( V_84 )
goto V_187;
}
V_179 = F_168 ( L_29 ) ;
V_84 = F_83 ( V_179 ) ;
if ( V_84 )
goto V_187;
F_155 ( & V_159 , F_160 , 0 ) ;
if ( V_188 )
V_58 = 1500000 ;
F_153 ( & V_56 ) ;
F_169 ( & V_57 , V_189 , V_166 ) ;
V_57 . V_190 = F_60 ;
if ( V_191 ) {
V_84 = F_80 () ;
if ( V_84 )
goto V_192;
}
V_84 = F_170 ( & V_193 ) ;
if ( V_84 )
goto V_194;
F_119 ( V_142 , & V_138 ) ;
V_157 = true ;
return 0 ;
V_194:
F_85 () ;
V_192:
F_144 ( & V_57 ) ;
F_171 ( V_179 ) ;
V_187:
while ( V_170 -- )
F_172 ( & V_139 , V_186 [ V_170 ] ) ;
F_173 ( & V_139 ) ;
V_177:
F_174 ( & V_185 ) ;
if ( F_1 () )
F_117 ( & V_87 ) ;
V_184:
F_15 ( V_12 ) ;
return V_84 ;
}
void F_175 ( void )
{
int V_170 ;
V_157 = false ;
F_161 () ;
F_85 () ;
F_127 ( & V_159 ) ;
F_144 ( & V_57 ) ;
F_176 ( & V_101 ) ;
F_115 ( & V_139 , NULL , NULL , F_112 ) ;
for ( V_170 = 0 ; V_186 [ V_170 ] ; V_170 ++ )
F_172 ( & V_139 , V_186 [ V_170 ] ) ;
F_177 ( & V_193 ) ;
F_171 ( V_179 ) ;
F_173 ( & V_139 ) ;
F_15 ( V_12 ) ;
F_174 ( & V_185 ) ;
if ( F_1 () )
F_117 ( & V_87 ) ;
}
