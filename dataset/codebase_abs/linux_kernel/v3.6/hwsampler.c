static int F_1 ( void * V_1 )
{
int V_2 ;
V_2 = 1 ;
asm volatile(
"0: .insn s,0xB2870000,0(%1)\n"
"1: ipm %0\n"
" srl %0,28\n"
"2:\n"
EX_TABLE(0b, 2b) EX_TABLE(1b, 2b)
: "+d" (cc), "+a" (buffer)
: "m" (*((struct hws_ssctl_request_block *)buffer))
: "cc", "memory");
return V_2 ? - V_3 : 0 ;
}
static int F_2 ( void * V_1 )
{
int V_2 ;
V_2 = 1 ;
asm volatile(
"0: .insn s,0xB2860000,0(%1)\n"
"1: lhi %0,0\n"
"2:\n"
EX_TABLE(0b, 2b) EX_TABLE(1b, 2b)
: "=d" (cc), "+a" (buffer)
: "m" (*((struct hws_qsi_info_block *)buffer))
: "cc", "memory");
return V_2 ? - V_3 : 0 ;
}
static void F_3 ( void * V_4 )
{
struct V_5 * V_6 = V_4 ;
V_6 -> V_7 = F_2 ( V_6 -> V_1 ) ;
}
static void F_4 ( void * V_4 )
{
struct V_5 * V_6 = V_4 ;
V_6 -> V_7 = F_1 ( V_6 -> V_1 ) ;
}
static int F_5 ( int V_8 )
{
int V_7 ;
struct V_5 V_6 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> F_1 . V_12 = 0 ;
V_10 -> F_1 . V_13 = 0 ;
V_6 . V_1 = & V_10 -> F_1 ;
F_7 ( V_8 , F_4 , & V_6 , 1 ) ;
V_7 = V_6 . V_7 ;
if ( V_7 ) {
F_8 ( V_14 L_1 , V_8 ) ;
F_9 () ;
}
V_6 . V_1 = & V_10 -> F_2 ;
F_7 ( V_8 , F_3 , & V_6 , 1 ) ;
if ( V_10 -> F_2 . V_12 || V_10 -> F_2 . V_13 ) {
F_8 ( V_15 L_2 ) ;
F_9 () ;
}
return V_7 ;
}
static int F_10 ( int V_8 )
{
int V_7 ;
struct V_5 V_6 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> F_1 . V_12 = 1 ;
V_10 -> F_1 . V_13 = 0 ;
V_6 . V_1 = & V_10 -> F_1 ;
F_7 ( V_8 , F_4 , & V_6 , 1 ) ;
V_7 = V_6 . V_7 ;
if ( V_7 )
F_8 ( V_14 L_1 , V_8 ) ;
V_6 . V_1 = & V_10 -> F_2 ;
F_7 ( V_8 , F_3 , & V_6 , 1 ) ;
if ( V_10 -> F_2 . V_13 )
F_8 ( V_15 L_3 ) ;
return V_7 ;
}
static int F_11 ( int V_8 , unsigned long V_16 )
{
int V_7 ;
struct V_5 V_6 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> F_1 . V_17 = 1 ;
V_10 -> F_1 . V_18 = V_10 -> V_19 ;
V_10 -> F_1 . V_20 = * ( unsigned long * ) V_10 -> V_19 ;
V_10 -> F_1 . V_16 = V_16 ;
V_10 -> F_1 . V_12 = 1 ;
V_10 -> F_1 . V_13 = 1 ;
V_6 . V_1 = & V_10 -> F_1 ;
F_7 ( V_8 , F_4 , & V_6 , 1 ) ;
V_7 = V_6 . V_7 ;
if ( V_7 )
F_8 ( V_14 L_1 , V_8 ) ;
V_6 . V_1 = & V_10 -> F_2 ;
F_7 ( V_8 , F_3 , & V_6 , 1 ) ;
if ( V_6 . V_7 )
F_8 ( V_14 L_4 , V_8 ) ;
return V_7 ;
}
static int F_12 ( int V_8 )
{
struct V_5 V_6 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_6 . V_1 = & V_10 -> F_2 ;
F_7 ( V_8 , F_3 , & V_6 , 1 ) ;
return V_6 . V_7 ;
}
static inline unsigned long * F_13 ( unsigned long V_21 )
{
void * V_22 ;
V_22 = ( void * ) V_21 ;
V_22 += V_23 ;
V_22 -= sizeof( struct V_24 ) ;
return ( unsigned long * ) V_22 ;
}
static void F_14 ( struct V_25 V_25 ,
unsigned int V_26 , unsigned long V_27 )
{
struct V_9 * V_10 = & F_15 ( V_11 ) ;
if ( ! ( V_26 & V_28 ) )
return;
F_16 ( F_17 () ) . V_29 [ V_30 ] ++ ;
F_18 ( & V_10 -> V_31 , F_19 ( & V_10 -> V_31 ) | V_26 ) ;
if ( V_32 )
F_20 ( V_32 , & V_10 -> V_33 ) ;
}
static void F_21 ( void )
{
int V_8 ;
struct V_9 * V_10 ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
}
}
static int F_23 ( unsigned long * V_34 )
{
return * V_34 & 0x1ul ? 1 : 0 ;
}
static unsigned long * F_24 ( unsigned long * V_34 )
{
return ( unsigned long * ) ( * V_34 & ~ 0x1ul ) ;
}
static int F_25 ( void )
{
int V_8 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_26 ( & V_10 -> V_31 , 0 ) ;
V_10 -> V_35 = 0 ;
V_10 -> V_36 = 0 ;
V_10 -> V_37 = 0 ;
V_10 -> V_38 = 0 ;
V_10 -> V_39 = 0 ;
V_10 -> V_40 = 0 ;
V_10 -> V_41 = 0 ;
V_10 -> V_42 = 0 ;
V_10 -> V_43 = 0 ;
V_10 -> V_44 = 0 ;
}
return V_7 ;
}
static int F_27 ( int V_8 )
{
int V_45 , V_46 , V_7 ;
unsigned long * V_47 ;
unsigned long V_48 ;
unsigned long * V_49 ;
unsigned long * V_50 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_19 )
return - V_3 ;
V_47 = NULL ;
V_49 = V_47 ;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ ) {
V_47 = ( unsigned long * ) F_28 ( V_52 ) ;
F_29 ( & V_53 ) ;
F_30 () ;
if ( V_54 || ! V_47 ) {
if ( V_47 )
F_31 ( ( unsigned long ) V_47 ) ;
goto V_55;
}
if ( V_10 -> V_19 == 0 )
V_10 -> V_19 = ( unsigned long ) V_47 ;
if ( V_49 )
* V_49 = ( unsigned long ) ( void * ) V_47 + 1 ;
F_32 ( & V_53 ) ;
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ ) {
V_48 = F_28 ( V_52 ) ;
F_29 ( & V_53 ) ;
F_30 () ;
if ( V_54 || ! V_48 ) {
if ( V_48 )
F_31 ( V_48 ) ;
goto V_55;
}
* V_47 = V_48 ;
V_50 = F_13 ( * V_47 ) ;
* V_50 = V_57 ;
V_47 ++ ;
F_32 ( & V_53 ) ;
}
V_49 = V_47 ;
}
F_29 ( & V_53 ) ;
if ( V_54 )
goto V_55;
V_7 = 0 ;
if ( V_49 )
* V_49 = ( unsigned long )
( ( void * ) V_10 -> V_19 ) + 1 ;
V_58:
F_32 ( & V_53 ) ;
return V_7 ;
V_55:
V_7 = - V_59 ;
goto V_58;
}
static int F_33 ( void )
{
int V_8 ;
int V_60 ;
V_60 = 0 ;
F_22 (cpu) {
unsigned long V_61 ;
unsigned long V_47 ;
unsigned long * V_62 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_19 )
continue;
V_47 = V_10 -> V_19 ;
V_62 = ( unsigned long * ) V_47 ;
V_61 = V_47 ;
while ( 1 ) {
if ( ! * V_62 || ! V_47 )
break;
if ( F_23 ( V_62 ) ) {
V_62 = F_24 ( V_62 ) ;
if ( V_47 )
F_31 ( V_47 ) ;
if ( ( unsigned long ) V_62 == V_61 )
break;
else
V_47 = ( unsigned long ) V_62 ;
} else {
if ( * V_62 ) {
F_31 ( * V_62 ) ;
V_62 ++ ;
}
}
V_60 ++ ;
}
V_10 -> V_19 = 0 ;
}
return V_60 ;
}
static int F_34 ( int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_63 L_5 , V_8 ) ;
goto V_64;
}
V_7 = - V_3 ;
if ( ! V_10 -> F_2 . V_12 ) {
F_8 ( V_63 L_6 , V_8 ) ;
goto V_64;
}
if ( ! V_10 -> F_2 . V_13 ) {
F_8 ( V_63 L_7 , V_8 ) ;
goto V_64;
}
F_8 ( V_63
L_8 ,
V_8 , V_16 ) ;
V_7 = 0 ;
V_64:
return V_7 ;
}
static int F_35 ( int V_8 )
{
unsigned long V_21 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_7 && ! V_10 -> F_2 . V_12 )
F_8 ( V_63 L_9 , V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_63 L_10 ,
V_8 , V_7 ) ;
goto V_65;
}
F_8 ( V_63 L_11 , V_8 ) ;
V_65:
V_21 = V_10 -> V_37 ;
if ( V_21 )
F_8 ( V_14 L_12
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_40 ;
if ( V_21 )
F_8 ( V_14 L_14
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_39 ;
if ( V_21 )
F_8 ( V_14 L_15
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_38 ;
if ( V_21 )
F_8 ( V_14
L_16
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_41 ;
if ( V_21 )
F_8 ( V_14
L_17
L_13 , V_8 , V_21 ) ;
return V_7 ;
}
static int F_37 ( void )
{
if ( ! F_38 ( 68 ) )
return - V_66 ;
return 0 ;
}
static int F_39 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
unsigned long * V_71 ;
int V_8 ;
struct V_9 * V_10 ;
V_71 = V_70 ;
F_29 ( & V_53 ) ;
if ( V_72 == V_73 ) {
if ( V_54 == 0 ) {
V_54 = 1 ;
* V_71 += F_33 () ;
}
} else {
int V_74 ;
V_8 = F_40 () ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_43 ) {
F_22 (i) {
F_10 ( V_74 ) ;
V_10 -> V_43 = 1 ;
}
V_10 -> V_42 = 1 ;
F_8 ( V_63
L_18 ,
V_8 ) ;
}
}
F_32 ( & V_53 ) ;
return V_75 ;
}
static int F_41 ( struct V_67 * V_68 ,
unsigned long V_76 , void * V_77 )
{
return ( V_72 <= V_73 ) ? V_75 : V_78 ;
}
int F_42 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_29 ( & V_79 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_72 == V_80 ) {
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( V_10 -> F_2 . V_13 ) {
V_7 = F_10 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_63
L_19 , V_8 ) ;
V_10 -> V_42 = 1 ;
V_72 = V_81 ;
} else {
V_82 = 1 ;
F_43 ( V_8 , V_32 , & V_10 -> V_33 ) ;
}
}
}
F_32 ( & V_79 ) ;
if ( V_32 )
F_44 ( V_32 ) ;
return V_7 ;
}
int F_45 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_29 ( & V_79 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_72 == V_80 ) {
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_13 ) {
V_82 = 0 ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_14
L_20 ,
V_8 ) ;
}
}
}
F_32 ( & V_79 ) ;
return V_7 ;
}
static int F_46 ( void )
{
int V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( V_7 )
return - V_66 ;
if ( ! V_10 -> F_2 . V_83 ) {
F_8 ( V_63 L_21 ) ;
return - V_3 ;
}
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_84 L_22 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
return - V_3 ;
F_8 ( V_63
L_23 , V_8 ) ;
}
}
return 0 ;
}
static int F_47 ( void )
{
unsigned int V_8 ;
int V_7 ;
struct V_9 * V_10 ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_83 )
return - V_3 ;
if ( V_10 -> F_2 . V_12 )
return - V_3 ;
if ( V_10 -> F_2 . V_13 )
return - V_3 ;
}
return 0 ;
}
static void F_48 ( unsigned int V_8 )
{
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> V_35 = V_10 -> V_19 ;
}
static int F_49 ( unsigned int V_8 , int V_31 )
{
int V_7 ;
unsigned long * V_47 ;
struct V_9 * V_10 ;
V_7 = 0 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_47 = ( unsigned long * ) V_10 -> V_35 ;
if ( ! V_47 || ! * V_47 )
return - V_3 ;
if ( V_31 & V_85 )
V_10 -> V_37 ++ ;
if ( V_31 & V_86 )
V_10 -> V_40 ++ ;
if ( V_31 & V_87 ) {
V_10 -> V_39 ++ ;
V_7 = - V_3 ;
}
if ( V_31 & V_88 ) {
V_10 -> V_38 ++ ;
V_7 = - V_3 ;
}
if ( V_31 & V_89 ) {
V_10 -> V_41 ++ ;
V_7 = - V_3 ;
}
return V_7 ;
}
static void F_50 ( unsigned int V_8 )
{
int V_7 , V_74 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_42 ) {
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_63
L_24 ,
V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
F_8 ( V_63
L_19 ,
V_8 ) ;
F_22 (i) {
if ( V_74 == V_8 )
continue;
if ( ! V_10 -> V_42 ) {
V_10 -> V_42 = 1 ;
F_43 ( V_74 , V_32 ,
& V_10 -> V_33 ) ;
}
}
}
}
}
static void F_51 ( unsigned int V_8 )
{
unsigned long * V_47 ;
unsigned char V_90 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_47 = ( unsigned long * ) V_10 -> V_35 ;
V_90 = 0 ;
while ( ! V_90 && ! V_10 -> V_44 ) {
unsigned long * V_50 ;
struct V_24 * V_91 ;
unsigned long * V_20 = 0 ;
V_50 = F_13 ( * V_47 ) ;
if ( ! ( * V_50 & V_92 ) ) {
V_90 = 1 ;
if ( ! V_82 )
continue;
}
V_91 = (struct V_24 * ) V_50 ;
V_10 -> V_36 += V_91 -> V_93 ;
F_52 ( V_8 , V_47 , V_20 ) ;
F_53 ( ( unsigned char * ) V_91 , 0x40 ) ;
V_47 ++ ;
if ( F_23 ( V_47 ) )
V_47 = F_24 ( V_47 ) ;
V_10 -> V_35 = ( unsigned long ) V_47 ;
}
}
static void F_52 ( unsigned int V_8 , unsigned long * V_47 ,
unsigned long * V_20 )
{
struct V_94 * V_95 ;
unsigned long * V_50 ;
V_50 = F_13 ( * V_47 ) ;
if ( V_20 ) {
if ( V_20 > V_50 )
return;
V_50 = V_20 ;
}
V_95 = (struct V_94 * ) ( * V_47 ) ;
while ( ( unsigned long * ) V_95 < V_50 ) {
struct V_96 * V_97 = NULL ;
struct V_98 * V_99 = NULL ;
if ( V_95 -> V_100 != 1 ) {
break;
} else {
V_95 -> V_100 = 0 ;
}
if ( V_95 -> V_101 == 1 ) {
unsigned int V_102 = V_95 -> V_103 ;
if ( ! V_104 . V_105 )
goto V_106;
F_54 () ;
V_99 = F_55 ( F_56 ( V_102 ) , V_107 ) ;
if ( V_99 )
V_97 = F_57 ( V_99 ) ;
F_58 () ;
} else {
if ( ! V_104 . V_108 )
goto V_106;
V_97 = F_57 ( V_109 ) ;
}
F_29 ( & V_79 ) ;
F_59 ( V_95 -> V_110 , V_97 , 0 ,
! V_95 -> V_101 , V_99 ) ;
F_32 ( & V_79 ) ;
V_106:
V_95 ++ ;
}
}
static void V_33 ( struct V_111 * V_112 )
{
unsigned int V_8 ;
int V_31 ;
struct V_9 * V_10 ;
V_10 = F_60 ( V_112 , struct V_9 , V_33 ) ;
V_8 = F_17 () ;
V_31 = F_18 ( & V_10 -> V_31 , 0 ) ;
if ( ! V_10 -> V_35 )
F_48 ( V_8 ) ;
if ( F_49 ( V_8 , V_31 ) )
return;
if ( ! V_10 -> V_42 )
F_51 ( V_8 ) ;
if ( V_10 -> V_42 )
F_50 ( V_8 ) ;
}
int F_61 ( unsigned long V_47 , unsigned long V_48 )
{
int V_8 , V_7 ;
F_29 ( & V_79 ) ;
V_7 = - V_3 ;
if ( V_72 != V_73 )
goto V_113;
if ( V_47 < 1 )
goto V_113;
if ( V_48 > V_114 || V_48 < V_115 )
goto V_113;
V_51 = V_47 ;
V_56 = V_48 ;
V_54 = 0 ;
F_62 ( & V_116 ) ;
F_22 (cpu) {
if ( F_27 ( V_8 ) ) {
F_63 ( & V_116 ) ;
goto V_117;
}
}
F_63 ( & V_116 ) ;
if ( V_54 )
goto V_117;
V_72 = V_118 ;
V_7 = 0 ;
V_113:
F_32 ( & V_79 ) ;
return V_7 ;
V_117:
V_7 = - V_59 ;
F_8 ( V_14 L_25 ) ;
goto V_113;
}
int F_64 ( void )
{
int V_7 ;
F_29 ( & V_79 ) ;
V_7 = - V_3 ;
if ( V_72 != V_118 )
goto V_119;
F_65 () ;
F_33 () ;
V_72 = V_73 ;
V_7 = 0 ;
V_119:
F_32 ( & V_79 ) ;
return V_7 ;
}
unsigned long F_66 ( void )
{
return V_120 ;
}
unsigned long F_67 ( void )
{
return V_121 ;
}
unsigned long F_68 ( unsigned int V_8 )
{
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
return V_10 -> V_36 ;
}
int F_69 ( void )
{
int V_7 ;
int V_8 ;
struct V_9 * V_10 ;
F_29 ( & V_79 ) ;
V_7 = - V_3 ;
if ( V_72 )
goto V_122;
V_72 = V_123 ;
F_21 () ;
V_7 = F_37 () ;
if ( V_7 )
goto V_122;
V_7 = F_46 () ;
if ( V_7 )
goto V_122;
V_7 = - V_3 ;
V_32 = F_70 ( L_26 ) ;
if ( ! V_32 )
goto V_122;
F_71 ( & V_124 ) ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_72 ( & V_10 -> V_33 , V_33 ) ;
V_7 = F_12 ( V_8 ) ;
F_36 ( V_7 ) ;
if ( V_120 != V_10 -> F_2 . V_125 ) {
if ( V_120 ) {
F_8 ( V_84
L_27 ) ;
if ( V_120 < V_10 -> F_2 . V_125 )
V_120 =
V_10 -> F_2 . V_125 ;
} else
V_120 = V_10 -> F_2 . V_125 ;
}
if ( V_121 != V_10 -> F_2 . V_126 ) {
if ( V_121 ) {
F_8 ( V_84
L_28 ) ;
if ( V_121 > V_10 -> F_2 . V_126 )
V_121 =
V_10 -> F_2 . V_126 ;
} else
V_121 = V_10 -> F_2 . V_126 ;
}
}
F_73 ( 0x1407 , F_14 ) ;
V_72 = V_73 ;
V_7 = 0 ;
V_122:
F_32 ( & V_79 ) ;
return V_7 ;
}
int F_74 ( void )
{
int V_7 ;
F_29 ( & V_79 ) ;
V_7 = - V_3 ;
if ( V_72 == V_73 || V_72 == V_118 ) {
F_32 ( & V_79 ) ;
if ( V_32 )
F_44 ( V_32 ) ;
F_29 ( & V_79 ) ;
if ( V_72 == V_118 ) {
F_65 () ;
F_33 () ;
}
if ( V_32 ) {
F_75 ( V_32 ) ;
V_32 = NULL ;
}
F_76 ( 0x1407 , F_14 ) ;
V_72 = V_123 ;
V_7 = 0 ;
}
F_32 ( & V_79 ) ;
F_77 ( & V_124 ) ;
return V_7 ;
}
int F_78 ( unsigned long V_127 )
{
int V_7 , V_8 ;
F_29 ( & V_79 ) ;
V_128 = 0 ;
V_7 = - V_3 ;
if ( V_72 != V_118 )
goto V_129;
V_16 = V_127 ;
if ( V_16 < V_120 || V_16 > V_121 )
goto V_129;
V_7 = F_47 () ;
if ( V_7 )
goto V_129;
V_7 = F_25 () ;
if ( V_7 )
goto V_129;
F_22 (cpu) {
V_7 = F_34 ( V_8 ) ;
if ( V_7 )
break;
}
if ( V_7 ) {
F_22 (cpu) {
F_35 ( V_8 ) ;
}
goto V_129;
}
V_72 = V_80 ;
V_7 = 0 ;
V_129:
F_32 ( & V_79 ) ;
if ( V_7 )
return V_7 ;
F_62 ( & V_116 ) ;
V_128 = 1 ;
V_82 = 0 ;
F_79 () ;
return 0 ;
}
int F_80 ( void )
{
int V_130 , V_7 , V_8 ;
struct V_9 * V_10 ;
F_29 ( & V_79 ) ;
V_7 = 0 ;
if ( V_72 == V_123 ) {
F_32 ( & V_79 ) ;
return V_7 ;
}
V_72 = V_81 ;
F_32 ( & V_79 ) ;
F_22 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> V_44 = 1 ;
V_130 = F_35 ( V_8 ) ;
if ( V_130 )
V_7 = V_130 ;
}
if ( V_32 )
F_44 ( V_32 ) ;
F_29 ( & V_79 ) ;
if ( V_128 ) {
F_63 ( & V_116 ) ;
V_128 = 0 ;
}
V_72 = V_118 ;
F_32 ( & V_79 ) ;
return V_7 ;
}
