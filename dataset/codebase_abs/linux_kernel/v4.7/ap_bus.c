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
if ( F_5 ( 15 ) )
T_1 |= 1UL << 23 ;
asm volatile(".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
if ( V_6 )
* V_6 = T_3 ;
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
F_9 ( T_4 V_5 , void * V_7 )
{
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x03000000UL ;
register unsigned long T_5 V_2 ( L_2 ) = 0x0000800000000000UL | V_8 ;
register struct V_4 T_6 V_2 ( L_2 ) ;
register void * T_3 V_2 ( L_3 ) = V_7 ;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "+d" (reg1_in), "=d" (reg1_out), "+d" (reg2)
:
: "cc" );
return T_6 ;
}
static inline int F_10 ( void )
{
register unsigned long T_1 V_2 ( L_1 ) = 0x04000000UL ;
register unsigned long T_2 V_2 ( L_2 ) = - V_9 ;
register void * T_3 V_2 ( L_3 ) = ( void * ) V_10 ;
if ( ! V_10 )
return - V_11 ;
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
static void F_11 ( void )
{
if ( ! F_6 () )
return;
V_10 = F_12 ( sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return;
if ( F_10 () != 0 ) {
F_13 ( V_10 ) ;
V_10 = NULL ;
return;
}
}
static inline int F_14 ( unsigned int * V_13 , unsigned int V_14 )
{
return F_15 ( ( V_13 + ( V_14 >> 5 ) ) , ( V_14 & 0x1f ) ) ;
}
static inline int F_16 ( unsigned int V_15 )
{
if ( ! V_10 )
return 1 ;
return F_14 ( V_10 -> V_16 , V_15 ) ;
}
static inline int F_17 ( unsigned int V_17 )
{
if ( ! V_10 )
return V_17 < 16 ;
return F_14 ( V_10 -> V_18 , V_17 ) ;
}
static int F_18 ( struct V_19 * V_20 , void * V_7 )
{
struct V_4 V_21 ;
V_21 = F_9 ( V_20 -> V_5 , V_7 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
case V_24 :
return 0 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
F_19 ( L_4 ,
F_20 ( V_20 -> V_5 ) ) ;
return - V_11 ;
case V_29 :
case V_30 :
default:
return - V_31 ;
}
}
static inline struct V_4
F_21 ( T_4 V_5 , unsigned long long V_32 , void * V_33 , T_7 V_34 ,
unsigned int V_35 )
{
typedef struct { char _ [ V_34 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x40000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = ( unsigned long ) V_33 ;
register unsigned long T_9 V_2 ( L_5 ) = ( unsigned long ) V_34 ;
register unsigned long T_10 V_2 ( L_6 ) = ( unsigned int ) ( V_32 >> 32 ) ;
register unsigned long T_11 V_2 ( L_7 ) = V_32 & 0xffffffff ;
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
int F_22 ( T_4 V_5 , unsigned long long V_32 , void * V_33 , T_7 V_34 )
{
struct V_4 V_21 ;
V_21 = F_21 ( V_5 , V_32 , V_33 , V_34 , 0 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
return 0 ;
case V_36 :
case V_29 :
return - V_31 ;
case V_37 :
return - V_9 ;
default:
return - V_3 ;
}
}
static inline struct V_4
F_23 ( T_4 V_5 , unsigned long long * V_32 , void * V_33 , T_7 V_34 )
{
typedef struct { char _ [ V_34 ] ; } T_8;
register unsigned long T_1 V_2 ( L_1 ) = V_5 | 0x80000000UL ;
register struct V_4 T_2 V_2 ( L_2 ) ;
register unsigned long T_3 V_2 ( L_3 ) = 0UL ;
register unsigned long T_10 V_2 ( L_6 ) = ( unsigned long ) V_33 ;
register unsigned long T_11 V_2 ( L_7 ) = ( unsigned long ) V_34 ;
register unsigned long T_12 V_2 ( L_8 ) = 0UL ;
register unsigned long T_13 V_2 ( L_9 ) = 0UL ;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
* V_32 = ( ( ( unsigned long long ) T_12 ) << 32 ) + T_13 ;
return T_2 ;
}
int F_24 ( T_4 V_5 , unsigned long long * V_32 , void * V_33 , T_7 V_34 )
{
struct V_4 V_21 ;
V_21 = F_23 ( V_5 , V_32 , V_33 , V_34 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
return 0 ;
case V_38 :
if ( V_21 . V_39 )
return - V_40 ;
return - V_31 ;
case V_29 :
return - V_31 ;
default:
return - V_3 ;
}
}
static int F_25 ( T_4 V_5 , int * V_41 , int * V_42 ,
unsigned int * V_43 )
{
struct V_4 V_21 ;
unsigned long V_6 ;
int V_44 ;
if ( ! F_16 ( F_20 ( V_5 ) ) )
return - V_3 ;
V_21 = F_7 ( V_5 , & V_6 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
* V_41 = ( int ) ( V_6 & 0xff ) ;
* V_42 = ( int ) ( ( V_6 >> 24 ) & 0xff ) ;
* V_43 = ( unsigned int ) ( V_6 >> 32 ) ;
V_44 = ( V_6 >> 16 ) & 0xff ;
if ( ( V_6 & ( 1UL << 57 ) ) && V_44 > 0 )
V_45 = V_44 ;
return 0 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return - V_3 ;
case V_29 :
case V_24 :
case V_30 :
return - V_31 ;
default:
F_26 () ;
}
}
static void F_27 ( enum V_46 V_47 )
{
T_14 V_48 ;
switch ( V_47 ) {
case V_49 :
case V_50 :
if ( F_1 () )
break;
if ( V_51 ) {
F_28 ( & V_52 ) ;
break;
}
case V_53 :
F_29 ( & V_54 ) ;
if ( ! F_30 ( & V_55 ) ) {
V_48 = F_31 ( 0 , V_56 ) ;
F_32 ( & V_55 , V_48 ) ;
F_33 ( & V_55 ) ;
}
F_34 ( & V_54 ) ;
break;
case V_57 :
default:
break;
}
}
static enum V_46 F_35 ( struct V_19 * V_20 )
{
return V_57 ;
}
static struct V_4 F_36 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
struct V_58 * V_59 ;
V_21 = F_23 ( V_20 -> V_5 , & V_20 -> V_60 -> V_32 ,
V_20 -> V_60 -> V_61 , V_20 -> V_60 -> V_34 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
F_37 ( & V_62 ) ;
V_20 -> V_63 -- ;
if ( V_20 -> V_63 > 0 )
F_38 ( & V_20 -> V_64 ,
V_65 + V_20 -> V_66 -> V_67 ) ;
F_39 (ap_msg, &ap_dev->pendingq, list) {
if ( V_59 -> V_32 != V_20 -> V_60 -> V_32 )
continue;
F_40 ( & V_59 -> V_68 ) ;
V_20 -> V_69 -- ;
V_59 -> V_70 ( V_20 , V_59 , V_20 -> V_60 ) ;
break;
}
case V_38 :
if ( ! V_21 . V_39 || V_20 -> V_63 <= 0 )
break;
F_41 ( V_20 -> V_63 , & V_62 ) ;
V_20 -> V_63 = 0 ;
F_42 ( & V_20 -> V_71 , & V_20 -> V_72 ) ;
V_20 -> V_73 += V_20 -> V_69 ;
V_20 -> V_69 = 0 ;
break;
default:
break;
}
return V_21 ;
}
static enum V_46 F_43 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
V_21 = F_36 ( V_20 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
if ( V_20 -> V_63 > 0 ) {
V_20 -> V_74 = V_75 ;
return V_49 ;
}
V_20 -> V_74 = V_76 ;
return V_57 ;
case V_38 :
if ( V_20 -> V_63 > 0 )
return V_50 ;
V_20 -> V_74 = V_76 ;
return V_57 ;
default:
V_20 -> V_74 = V_77 ;
return V_57 ;
}
}
static enum V_46 F_44 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
struct V_58 * V_59 ;
if ( V_20 -> V_73 <= 0 )
return V_57 ;
V_59 = F_45 ( V_20 -> V_72 . V_78 , struct V_58 , V_68 ) ;
V_21 = F_21 ( V_20 -> V_5 , V_59 -> V_32 ,
V_59 -> V_61 , V_59 -> V_34 , V_59 -> V_35 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
F_46 ( & V_62 ) ;
V_20 -> V_63 ++ ;
if ( V_20 -> V_63 == 1 )
F_38 ( & V_20 -> V_64 ,
V_65 + V_20 -> V_66 -> V_67 ) ;
F_47 ( & V_59 -> V_68 , & V_20 -> V_71 ) ;
V_20 -> V_73 -- ;
V_20 -> V_69 ++ ;
if ( V_20 -> V_63 < V_20 -> V_41 ) {
V_20 -> V_74 = V_75 ;
return V_49 ;
}
case V_36 :
V_20 -> V_74 = V_79 ;
return V_50 ;
case V_29 :
V_20 -> V_74 = V_80 ;
return V_53 ;
case V_81 :
case V_37 :
F_40 ( & V_59 -> V_68 ) ;
V_20 -> V_73 -- ;
V_59 -> V_82 = - V_9 ;
V_59 -> V_70 ( V_20 , V_59 , NULL ) ;
return V_49 ;
default:
V_20 -> V_74 = V_77 ;
return V_57 ;
}
}
static enum V_46 F_48 ( struct V_19 * V_20 )
{
return F_49 ( F_43 ( V_20 ) , F_44 ( V_20 ) ) ;
}
static enum V_46 F_50 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
V_21 = F_8 ( V_20 -> V_5 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
case V_29 :
V_20 -> V_74 = V_80 ;
V_20 -> V_83 = V_84 ;
return V_53 ;
case V_30 :
return V_53 ;
case V_25 :
case V_26 :
case V_27 :
default:
V_20 -> V_74 = V_77 ;
return V_57 ;
}
}
static enum V_46 F_51 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
unsigned long V_6 ;
if ( V_20 -> V_63 > 0 )
V_21 = F_36 ( V_20 ) ;
else
V_21 = F_7 ( V_20 -> V_5 , & V_6 ) ;
switch ( V_21 . V_22 ) {
case V_23 :
if ( F_1 () &&
F_18 ( V_20 ,
V_85 . V_86 ) == 0 )
V_20 -> V_74 = V_87 ;
else
V_20 -> V_74 = ( V_20 -> V_63 > 0 ) ?
V_75 : V_76 ;
return V_49 ;
case V_30 :
case V_29 :
return V_53 ;
case V_25 :
case V_26 :
case V_27 :
default:
V_20 -> V_74 = V_77 ;
return V_57 ;
}
}
static enum V_46 F_52 ( struct V_19 * V_20 )
{
struct V_4 V_21 ;
unsigned long V_6 ;
if ( V_20 -> V_63 > 0 )
V_21 = F_36 ( V_20 ) ;
else
V_21 = F_7 ( V_20 -> V_5 , & V_6 ) ;
if ( V_21 . V_88 == 1 ) {
V_20 -> V_83 = V_89 ;
V_20 -> V_74 = ( V_20 -> V_63 > 0 ) ?
V_75 : V_76 ;
}
switch ( V_21 . V_22 ) {
case V_23 :
if ( V_20 -> V_63 > 0 )
return V_49 ;
case V_38 :
return V_53 ;
default:
V_20 -> V_74 = V_77 ;
return V_57 ;
}
}
static inline enum V_46 F_53 ( struct V_19 * V_20 ,
enum V_90 V_91 )
{
return V_92 [ V_20 -> V_74 ] [ V_91 ] ( V_20 ) ;
}
static inline enum V_46 F_54 ( struct V_19 * V_20 ,
enum V_90 V_91 )
{
enum V_46 V_47 ;
while ( ( V_47 = F_53 ( V_20 , V_91 ) ) == V_49 )
;
return V_47 ;
}
static void F_55 ( unsigned long V_93 )
{
struct V_19 * V_20 = (struct V_19 * ) V_93 ;
if ( V_94 )
return;
F_29 ( & V_20 -> V_95 ) ;
F_27 ( F_53 ( V_20 , V_96 ) ) ;
F_34 ( & V_20 -> V_95 ) ;
}
static enum F_33 F_56 ( struct V_97 * V_98 )
{
if ( ! V_94 )
F_57 ( & V_99 ) ;
return V_100 ;
}
static void F_58 ( struct V_101 * V_102 )
{
F_59 ( V_103 ) ;
if ( ! V_94 )
F_57 ( & V_99 ) ;
}
static void F_60 ( unsigned long V_104 )
{
struct V_19 * V_20 ;
enum V_46 V_47 = V_57 ;
if ( F_1 () )
F_61 ( V_85 . V_86 , 0 ) ;
F_62 ( & V_105 ) ;
F_39 (ap_dev, &ap_device_list, list) {
F_29 ( & V_20 -> V_95 ) ;
V_47 = F_49 ( V_47 , F_54 ( V_20 , V_106 ) ) ;
F_34 ( & V_20 -> V_95 ) ;
}
F_63 ( & V_105 ) ;
F_27 ( V_47 ) ;
}
static int F_64 ( void * V_93 )
{
F_65 ( V_47 , V_107 ) ;
F_66 ( V_107 , V_108 ) ;
F_67 () ;
while ( ! F_68 () ) {
F_69 ( & V_52 , & V_47 ) ;
F_70 ( V_109 ) ;
if ( V_94 ||
F_71 ( & V_62 ) <= 0 ) {
F_72 () ;
F_73 () ;
}
F_70 ( V_110 ) ;
F_74 ( & V_52 , & V_47 ) ;
if ( F_75 () ) {
F_72 () ;
F_73 () ;
continue;
}
F_60 ( 0 ) ;
} while ( ! F_68 () ) ;
return 0 ;
}
static int F_76 ( void )
{
int V_82 ;
if ( F_1 () || V_51 )
return 0 ;
F_77 ( & V_111 ) ;
V_51 = F_78 ( F_64 , NULL , L_10 ) ;
V_82 = F_79 ( V_51 ) ;
if ( V_82 )
V_51 = NULL ;
F_80 ( & V_111 ) ;
return V_82 ;
}
static void F_81 ( void )
{
if ( ! V_51 )
return;
F_77 ( & V_111 ) ;
F_82 ( V_51 ) ;
V_51 = NULL ;
F_80 ( & V_111 ) ;
}
void F_83 ( struct V_19 * V_20 , struct V_58 * V_59 )
{
F_84 ( ! V_59 -> V_70 ) ;
F_29 ( & V_20 -> V_95 ) ;
F_85 ( & V_59 -> V_68 , & V_20 -> V_72 ) ;
V_20 -> V_73 ++ ;
V_20 -> V_112 ++ ;
F_27 ( F_54 ( V_20 , V_106 ) ) ;
F_34 ( & V_20 -> V_95 ) ;
}
void F_86 ( struct V_19 * V_20 , struct V_58 * V_59 )
{
struct V_58 * V_113 ;
F_29 ( & V_20 -> V_95 ) ;
if ( ! F_87 ( & V_59 -> V_68 ) ) {
F_39 (tmp, &ap_dev->pendingq, list)
if ( V_113 -> V_32 == V_59 -> V_32 ) {
V_20 -> V_69 -- ;
goto V_114;
}
V_20 -> V_73 -- ;
V_114:
F_40 ( & V_59 -> V_68 ) ;
}
F_34 ( & V_20 -> V_95 ) ;
}
static T_15 F_88 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
return snprintf ( V_119 , V_120 , L_11 , V_20 -> V_42 ) ;
}
static T_15 F_90 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
return snprintf ( V_119 , V_120 , L_11 , V_20 -> V_121 ) ;
}
static T_15 F_91 ( struct V_115 * V_116 , struct V_117 * V_118 ,
char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
return snprintf ( V_119 , V_120 , L_11 , V_20 -> V_41 ) ;
}
static T_15 F_92 ( struct V_115 * V_116 ,
struct V_117 * V_118 ,
char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_82 ;
F_29 ( & V_20 -> V_95 ) ;
V_82 = snprintf ( V_119 , V_120 , L_11 , V_20 -> V_112 ) ;
F_34 ( & V_20 -> V_95 ) ;
return V_82 ;
}
static T_15 F_93 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_82 ;
F_29 ( & V_20 -> V_95 ) ;
V_82 = snprintf ( V_119 , V_120 , L_11 , V_20 -> V_73 ) ;
F_34 ( & V_20 -> V_95 ) ;
return V_82 ;
}
static T_15 F_94 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_82 ;
F_29 ( & V_20 -> V_95 ) ;
V_82 = snprintf ( V_119 , V_120 , L_11 , V_20 -> V_69 ) ;
F_34 ( & V_20 -> V_95 ) ;
return V_82 ;
}
static T_15 F_95 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_82 = 0 ;
F_29 ( & V_20 -> V_95 ) ;
switch ( V_20 -> V_74 ) {
case V_122 :
case V_80 :
V_82 = snprintf ( V_119 , V_120 , L_12 ) ;
break;
case V_75 :
case V_79 :
V_82 = snprintf ( V_119 , V_120 , L_13 ) ;
break;
default:
V_82 = snprintf ( V_119 , V_120 , L_14 ) ;
}
F_34 ( & V_20 -> V_95 ) ;
return V_82 ;
}
static T_15 F_96 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_82 = 0 ;
F_29 ( & V_20 -> V_95 ) ;
if ( V_20 -> V_74 == V_87 )
V_82 = snprintf ( V_119 , V_120 , L_15 ) ;
else if ( V_20 -> V_83 == V_89 )
V_82 = snprintf ( V_119 , V_120 , L_16 ) ;
else
V_82 = snprintf ( V_119 , V_120 , L_17 ) ;
F_34 ( & V_20 -> V_95 ) ;
return V_82 ;
}
static T_15 F_97 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
return sprintf ( V_119 , L_18 , F_89 ( V_116 ) -> V_42 ) ;
}
static T_15 F_98 ( struct V_115 * V_116 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
return snprintf ( V_119 , V_120 , L_19 , V_20 -> V_123 ) ;
}
static int F_99 ( struct V_115 * V_116 , struct V_124 * V_66 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
struct V_125 * V_126 = F_100 ( V_66 ) ;
struct V_127 * V_15 ;
for ( V_15 = V_126 -> V_128 ; V_15 -> V_129 ; V_15 ++ ) {
if ( ( V_15 -> V_129 & V_130 ) &&
( V_15 -> V_131 != V_20 -> V_42 ) )
continue;
return 1 ;
}
return 0 ;
}
static int F_101 ( struct V_115 * V_116 , struct V_132 * V_133 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
int V_134 = 0 ;
if ( ! V_20 )
return - V_3 ;
V_134 = F_102 ( V_133 , L_20 , V_20 -> V_42 ) ;
if ( V_134 )
return V_134 ;
V_134 = F_102 ( V_133 , L_21 , V_20 -> V_42 ) ;
return V_134 ;
}
static int F_103 ( struct V_115 * V_116 , T_16 V_74 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
F_29 ( & V_20 -> V_95 ) ;
V_20 -> V_74 = V_135 ;
while ( F_53 ( V_20 , V_106 ) != V_57 )
;
V_20 -> V_74 = V_77 ;
F_34 ( & V_20 -> V_95 ) ;
return 0 ;
}
static int F_104 ( struct V_115 * V_116 )
{
return 0 ;
}
static void F_105 ( void )
{
V_94 = 1 ;
F_106 ( & V_136 ) ;
F_107 ( & V_99 ) ;
}
static int F_108 ( struct V_115 * V_116 , void * V_104 )
{
F_109 ( V_116 ) ;
return 0 ;
}
static void F_110 ( void )
{
int V_82 ;
F_111 ( & V_137 , NULL , NULL , F_108 ) ;
if ( F_4 () && ! F_1 () ) {
V_82 = F_112 ( & V_85 ) ;
V_1 = ( V_82 == 0 ) ;
}
if ( ! F_4 () && F_1 () ) {
F_113 ( & V_85 ) ;
V_1 = 0 ;
}
if ( ! V_138 )
V_139 = - 1 ;
V_94 = 0 ;
if ( V_1 )
F_61 ( V_85 . V_86 , 0 ) ;
F_114 ( & V_99 ) ;
F_115 ( V_140 , & V_136 ) ;
}
static int F_116 ( struct V_141 * V_142 , unsigned long V_91 ,
void * V_143 )
{
switch ( V_91 ) {
case V_144 :
case V_145 :
F_105 () ;
break;
case V_146 :
case V_147 :
F_110 () ;
break;
default:
break;
}
return V_148 ;
}
static int F_117 ( struct V_115 * V_116 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
struct V_125 * V_126 = F_100 ( V_116 -> V_149 ) ;
int V_82 ;
V_20 -> V_66 = V_126 ;
V_82 = V_126 -> V_150 ? V_126 -> V_150 ( V_20 ) : - V_3 ;
if ( V_82 )
V_20 -> V_66 = NULL ;
return V_82 ;
}
static void F_118 ( struct V_19 * V_20 )
{
struct V_58 * V_59 , * V_78 ;
F_119 (ap_msg, next, &ap_dev->pendingq, list) {
F_40 ( & V_59 -> V_68 ) ;
V_20 -> V_69 -- ;
V_59 -> V_82 = - V_151 ;
V_59 -> V_70 ( V_20 , V_59 , NULL ) ;
}
F_119 (ap_msg, next, &ap_dev->requestq, list) {
F_40 ( & V_59 -> V_68 ) ;
V_20 -> V_73 -- ;
V_59 -> V_82 = - V_151 ;
V_59 -> V_70 ( V_20 , V_59 , NULL ) ;
}
}
void F_120 ( struct V_19 * V_20 )
{
F_29 ( & V_20 -> V_95 ) ;
F_118 ( V_20 ) ;
F_34 ( & V_20 -> V_95 ) ;
}
static int F_121 ( struct V_115 * V_116 )
{
struct V_19 * V_20 = F_89 ( V_116 ) ;
struct V_125 * V_126 = V_20 -> V_66 ;
F_120 ( V_20 ) ;
F_122 ( & V_20 -> V_64 ) ;
F_29 ( & V_105 ) ;
F_40 ( & V_20 -> V_68 ) ;
F_34 ( & V_105 ) ;
if ( V_126 -> remove )
V_126 -> remove ( V_20 ) ;
F_29 ( & V_20 -> V_95 ) ;
F_41 ( V_20 -> V_63 , & V_62 ) ;
F_34 ( & V_20 -> V_95 ) ;
return 0 ;
}
static void F_123 ( struct V_115 * V_116 )
{
F_13 ( F_89 ( V_116 ) ) ;
}
int F_124 ( struct V_125 * V_126 , struct V_152 * V_153 ,
char * V_154 )
{
struct V_124 * V_66 = & V_126 -> V_149 ;
if ( ! V_155 )
return - V_3 ;
V_66 -> V_156 = & V_137 ;
V_66 -> V_150 = F_117 ;
V_66 -> remove = F_121 ;
V_66 -> V_153 = V_153 ;
V_66 -> V_154 = V_154 ;
return F_125 ( V_66 ) ;
}
void F_126 ( struct V_125 * V_126 )
{
F_127 ( & V_126 -> V_149 ) ;
}
void F_128 ( void )
{
if ( V_94 )
return;
F_129 ( & V_157 ) ;
F_115 ( V_140 , & V_136 ) ;
F_106 ( & V_136 ) ;
}
static T_15 F_130 ( struct V_158 * V_156 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_11 , V_139 ) ;
}
static T_15 F_131 ( struct V_158 * V_156 , char * V_119 )
{
if ( ! V_10 )
return snprintf ( V_119 , V_120 , L_22 ) ;
if ( ! F_5 ( 76 ) )
return snprintf ( V_119 , V_120 , L_23 ,
V_10 -> V_159 [ 0 ] ,
V_10 -> V_159 [ 1 ] ) ;
return snprintf ( V_119 , V_120 ,
L_24 ,
V_10 -> V_159 [ 0 ] , V_10 -> V_159 [ 1 ] ,
V_10 -> V_159 [ 2 ] , V_10 -> V_159 [ 3 ] ,
V_10 -> V_159 [ 4 ] , V_10 -> V_159 [ 5 ] ,
V_10 -> V_159 [ 6 ] , V_10 -> V_159 [ 7 ] ) ;
}
static T_15 F_132 ( struct V_158 * V_156 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_11 , V_160 ) ;
}
static T_15 F_133 ( struct V_158 * V_156 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_11 ,
F_1 () ? 1 : 0 ) ;
}
static T_15 F_134 ( struct V_158 * V_156 ,
const char * V_119 , T_7 V_161 )
{
int time ;
if ( sscanf ( V_119 , L_11 , & time ) != 1 || time < 5 || time > 120 )
return - V_9 ;
V_160 = time ;
F_38 ( & V_157 , V_65 + V_160 * V_162 ) ;
return V_161 ;
}
static T_15 F_135 ( struct V_158 * V_156 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_11 , V_51 ? 1 : 0 ) ;
}
static T_15 F_136 ( struct V_158 * V_156 ,
const char * V_119 , T_7 V_161 )
{
int V_163 , V_82 ;
if ( sscanf ( V_119 , L_11 , & V_163 ) != 1 )
return - V_9 ;
if ( V_163 ) {
V_82 = F_76 () ;
if ( V_82 )
V_161 = V_82 ;
} else
F_81 () ;
return V_161 ;
}
static T_15 F_137 ( struct V_158 * V_156 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_25 , V_56 ) ;
}
static T_15 F_138 ( struct V_158 * V_156 , const char * V_119 ,
T_7 V_161 )
{
unsigned long long time ;
T_14 V_48 ;
if ( sscanf ( V_119 , L_25 , & time ) != 1 || time < 1 ||
time > 120000000000ULL )
return - V_9 ;
V_56 = time ;
V_48 = F_31 ( 0 , V_56 ) ;
F_29 ( & V_54 ) ;
F_139 ( & V_55 ) ;
F_140 ( & V_55 , V_48 ) ;
F_141 ( & V_55 , V_164 ) ;
F_34 ( & V_54 ) ;
return V_161 ;
}
static T_15 F_142 ( struct V_158 * V_156 , char * V_119 )
{
int V_165 ;
if ( V_10 )
V_165 = V_45 ? : - 1 ;
else
V_165 = 15 ;
return snprintf ( V_119 , V_120 , L_11 , V_165 ) ;
}
static int F_143 ( void )
{
int V_161 , V_166 , V_167 ;
struct V_4 V_21 ;
int V_168 , V_169 ;
if ( V_139 >= 0 )
return 0 ;
V_167 = - 1 ;
V_166 = 0 ;
for ( V_168 = 0 ; V_168 < V_170 ; V_168 ++ ) {
if ( ! F_17 ( V_168 ) )
continue;
V_161 = 0 ;
for ( V_169 = 0 ; V_169 < V_171 ; V_169 ++ ) {
if ( ! F_16 ( V_169 ) )
continue;
V_21 = F_7 ( F_3 ( V_169 , V_168 ) , NULL ) ;
if ( V_21 . V_22 != V_23 )
continue;
V_161 ++ ;
}
if ( V_161 > V_166 ) {
V_166 = V_161 ;
V_167 = V_168 ;
}
}
if ( V_167 >= 0 ) {
V_139 = V_167 ;
return 0 ;
}
return - V_3 ;
}
static int F_144 ( struct V_115 * V_116 , void * V_93 )
{
return F_89 ( V_116 ) -> V_5 == ( T_4 ) ( unsigned long ) V_93 ;
}
static void F_145 ( struct V_172 * V_98 )
{
struct V_19 * V_20 ;
struct V_115 * V_116 ;
T_4 V_5 ;
int V_41 = 0 , V_42 = 0 ;
unsigned int V_173 = 0 ;
int V_82 , V_168 , V_174 ;
F_10 () ;
if ( F_143 () != 0 )
goto V_175;
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ ) {
V_5 = F_3 ( V_168 , V_139 ) ;
V_116 = F_146 ( & V_137 , NULL ,
( void * ) ( unsigned long ) V_5 ,
F_144 ) ;
V_82 = F_25 ( V_5 , & V_41 , & V_42 ,
& V_173 ) ;
if ( V_116 ) {
V_20 = F_89 ( V_116 ) ;
F_29 ( & V_20 -> V_95 ) ;
if ( V_82 == - V_3 )
V_20 -> V_74 = V_77 ;
V_174 = V_20 -> V_74 == V_77 ;
F_34 ( & V_20 -> V_95 ) ;
if ( V_174 )
F_109 ( V_116 ) ;
F_147 ( V_116 ) ;
if ( ! V_174 )
continue;
}
if ( V_82 )
continue;
V_20 = F_12 ( sizeof( * V_20 ) , V_12 ) ;
if ( ! V_20 )
break;
V_20 -> V_5 = V_5 ;
V_20 -> V_74 = V_122 ;
V_20 -> V_83 = V_84 ;
V_20 -> V_41 = V_41 ;
V_20 -> V_121 = V_42 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_123 = V_173 ;
F_148 ( & V_20 -> V_95 ) ;
F_149 ( & V_20 -> V_71 ) ;
F_149 ( & V_20 -> V_72 ) ;
F_149 ( & V_20 -> V_68 ) ;
F_150 ( & V_20 -> V_64 , F_55 ,
( unsigned long ) V_20 ) ;
V_20 -> V_115 . V_156 = & V_137 ;
V_20 -> V_115 . V_176 = V_177 ;
V_82 = F_151 ( & V_20 -> V_115 , L_26 ,
F_20 ( V_20 -> V_5 ) ) ;
if ( V_82 ) {
F_13 ( V_20 ) ;
continue;
}
F_29 ( & V_105 ) ;
F_152 ( & V_20 -> V_68 , & V_178 ) ;
F_34 ( & V_105 ) ;
F_29 ( & V_20 -> V_95 ) ;
F_27 ( F_53 ( V_20 , V_106 ) ) ;
F_34 ( & V_20 -> V_95 ) ;
V_20 -> V_115 . V_179 = F_123 ;
V_82 = F_153 ( & V_20 -> V_115 ) ;
if ( V_82 ) {
F_29 ( & V_20 -> V_95 ) ;
F_40 ( & V_20 -> V_68 ) ;
F_34 ( & V_20 -> V_95 ) ;
F_147 ( & V_20 -> V_115 ) ;
continue;
}
V_82 = F_154 ( & V_20 -> V_115 . V_180 ,
& V_181 ) ;
if ( V_82 ) {
F_109 ( & V_20 -> V_115 ) ;
continue;
}
}
V_175:
F_38 ( & V_157 , V_65 + V_160 * V_162 ) ;
}
static void F_155 ( unsigned long V_143 )
{
if ( V_94 )
return;
F_115 ( V_140 , & V_136 ) ;
}
static void F_156 ( void )
{
int V_168 ;
if ( V_139 == - 1 || ! F_17 ( V_139 ) )
return;
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ )
F_8 ( F_3 ( V_168 , V_139 ) ) ;
}
static void F_157 ( void )
{
int V_168 , V_169 ;
for ( V_168 = 0 ; V_168 < V_170 ; V_168 ++ ) {
if ( ! F_17 ( V_168 ) )
continue;
for ( V_169 = 0 ; V_169 < V_171 ; V_169 ++ ) {
if ( ! F_16 ( V_169 ) )
continue;
F_8 ( F_3 ( V_169 , V_168 ) ) ;
}
}
}
int T_17 F_158 ( void )
{
int V_165 ;
int V_82 , V_168 ;
if ( F_2 () != 0 ) {
F_159 ( L_27 ) ;
return - V_3 ;
}
F_11 () ;
if ( V_10 )
V_165 = V_45 ? : ( V_170 - 1 ) ;
else
V_165 = 15 ;
if ( V_139 < - 1 || V_139 > V_165 ) {
F_159 ( L_28 ,
V_139 ) ;
return - V_9 ;
}
if ( V_139 >= 0 )
V_138 = 1 ;
if ( F_4 () ) {
V_82 = F_112 ( & V_85 ) ;
V_1 = ( V_82 == 0 ) ;
}
F_160 ( & V_182 ) ;
V_82 = F_161 ( & V_137 ) ;
if ( V_82 )
goto V_175;
for ( V_168 = 0 ; V_183 [ V_168 ] ; V_168 ++ ) {
V_82 = F_162 ( & V_137 , V_183 [ V_168 ] ) ;
if ( V_82 )
goto V_184;
}
V_177 = F_163 ( L_29 ) ;
V_82 = F_79 ( V_177 ) ;
if ( V_82 )
goto V_184;
F_150 ( & V_157 , F_155 , 0 ) ;
if ( V_185 )
V_56 = 1500000 ;
F_148 ( & V_54 ) ;
F_164 ( & V_55 , V_186 , V_164 ) ;
V_55 . V_187 = F_56 ;
if ( V_188 ) {
V_82 = F_76 () ;
if ( V_82 )
goto V_189;
}
V_82 = F_165 ( & V_190 ) ;
if ( V_82 )
goto V_191;
F_115 ( V_140 , & V_136 ) ;
V_155 = true ;
return 0 ;
V_191:
F_81 () ;
V_189:
F_139 ( & V_55 ) ;
F_166 ( V_177 ) ;
V_184:
while ( V_168 -- )
F_167 ( & V_137 , V_183 [ V_168 ] ) ;
F_168 ( & V_137 ) ;
V_175:
F_169 ( & V_182 ) ;
if ( F_1 () )
F_113 ( & V_85 ) ;
F_13 ( V_10 ) ;
return V_82 ;
}
void F_170 ( void )
{
int V_168 ;
V_155 = false ;
F_156 () ;
F_81 () ;
F_122 ( & V_157 ) ;
F_139 ( & V_55 ) ;
F_171 ( & V_99 ) ;
F_111 ( & V_137 , NULL , NULL , F_108 ) ;
for ( V_168 = 0 ; V_183 [ V_168 ] ; V_168 ++ )
F_167 ( & V_137 , V_183 [ V_168 ] ) ;
F_172 ( & V_190 ) ;
F_166 ( V_177 ) ;
F_168 ( & V_137 ) ;
F_13 ( V_10 ) ;
F_169 ( & V_182 ) ;
if ( F_1 () )
F_113 ( & V_85 ) ;
}
