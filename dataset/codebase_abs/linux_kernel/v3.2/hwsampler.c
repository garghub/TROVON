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
static void F_14 ( void )
{
int V_8 ;
struct V_9 * V_10 ;
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
}
}
static int F_16 ( unsigned long * V_25 )
{
return * V_25 & 0x1ul ? 1 : 0 ;
}
static unsigned long * F_17 ( unsigned long * V_25 )
{
return ( unsigned long * ) ( * V_25 & ~ 0x1ul ) ;
}
static int F_18 ( void )
{
int V_8 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_19 ( & V_10 -> V_26 , 0 ) ;
V_10 -> V_27 = 0 ;
V_10 -> V_28 = 0 ;
V_10 -> V_29 = 0 ;
V_10 -> V_30 = 0 ;
V_10 -> V_31 = 0 ;
V_10 -> V_32 = 0 ;
V_10 -> V_33 = 0 ;
V_10 -> V_34 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_36 = 0 ;
}
return V_7 ;
}
static int F_20 ( int V_8 )
{
int V_37 , V_38 , V_7 ;
unsigned long * V_39 ;
unsigned long V_40 ;
unsigned long * V_41 ;
unsigned long * V_42 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_19 )
return - V_3 ;
V_39 = NULL ;
V_41 = V_39 ;
for ( V_37 = 0 ; V_37 < V_43 ; V_37 ++ ) {
V_39 = ( unsigned long * ) F_21 ( V_44 ) ;
F_22 ( & V_45 ) ;
F_23 () ;
if ( V_46 || ! V_39 ) {
if ( V_39 )
F_24 ( ( unsigned long ) V_39 ) ;
goto V_47;
}
if ( V_10 -> V_19 == 0 )
V_10 -> V_19 = ( unsigned long ) V_39 ;
if ( V_41 )
* V_41 = ( unsigned long ) ( void * ) V_39 + 1 ;
F_25 ( & V_45 ) ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ ) {
V_40 = F_21 ( V_44 ) ;
F_22 ( & V_45 ) ;
F_23 () ;
if ( V_46 || ! V_40 ) {
if ( V_40 )
F_24 ( V_40 ) ;
goto V_47;
}
* V_39 = V_40 ;
V_42 = F_13 ( * V_39 ) ;
* V_42 = V_49 ;
V_39 ++ ;
F_25 ( & V_45 ) ;
}
V_41 = V_39 ;
}
F_22 ( & V_45 ) ;
if ( V_46 )
goto V_47;
V_7 = 0 ;
if ( V_41 )
* V_41 = ( unsigned long )
( ( void * ) V_10 -> V_19 ) + 1 ;
V_50:
F_25 ( & V_45 ) ;
return V_7 ;
V_47:
V_7 = - V_51 ;
goto V_50;
}
static int F_26 ( void )
{
int V_8 ;
int V_52 ;
V_52 = 0 ;
F_15 (cpu) {
unsigned long V_53 ;
unsigned long V_39 ;
unsigned long * V_54 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_19 )
continue;
V_39 = V_10 -> V_19 ;
V_54 = ( unsigned long * ) V_39 ;
V_53 = V_39 ;
while ( 1 ) {
if ( ! * V_54 || ! V_39 )
break;
if ( F_16 ( V_54 ) ) {
V_54 = F_17 ( V_54 ) ;
if ( V_39 )
F_24 ( V_39 ) ;
if ( ( unsigned long ) V_54 == V_53 )
break;
else
V_39 = ( unsigned long ) V_54 ;
} else {
if ( * V_54 ) {
F_24 ( * V_54 ) ;
V_54 ++ ;
}
}
V_52 ++ ;
}
V_10 -> V_19 = 0 ;
}
return V_52 ;
}
static int F_27 ( int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_55 L_5 , V_8 ) ;
goto V_56;
}
V_7 = - V_3 ;
if ( ! V_10 -> F_2 . V_12 ) {
F_8 ( V_55 L_6 , V_8 ) ;
goto V_56;
}
if ( ! V_10 -> F_2 . V_13 ) {
F_8 ( V_55 L_7 , V_8 ) ;
goto V_56;
}
F_8 ( V_55
L_8 ,
V_8 , V_16 ) ;
V_7 = 0 ;
V_56:
return V_7 ;
}
static int F_28 ( int V_8 )
{
unsigned long V_21 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_7 && ! V_10 -> F_2 . V_12 )
F_8 ( V_55 L_9 , V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_55 L_10 ,
V_8 , V_7 ) ;
goto V_57;
}
F_8 ( V_55 L_11 , V_8 ) ;
V_57:
V_21 = V_10 -> V_29 ;
if ( V_21 )
F_8 ( V_14 L_12
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_32 ;
if ( V_21 )
F_8 ( V_14 L_14
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_31 ;
if ( V_21 )
F_8 ( V_14 L_15
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_30 ;
if ( V_21 )
F_8 ( V_14
L_16
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_33 ;
if ( V_21 )
F_8 ( V_14
L_17
L_13 , V_8 , V_21 ) ;
return V_7 ;
}
static int F_30 ( void )
{
if ( ! F_31 ( 68 ) )
return - V_58 ;
return 0 ;
}
static int F_32 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
unsigned long * V_63 ;
int V_8 ;
struct V_9 * V_10 ;
V_63 = V_62 ;
F_22 ( & V_45 ) ;
if ( V_64 == V_65 ) {
if ( V_46 == 0 ) {
V_46 = 1 ;
* V_63 += F_26 () ;
}
} else {
int V_66 ;
V_8 = F_33 () ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_35 ) {
F_15 (i) {
F_10 ( V_66 ) ;
V_10 -> V_35 = 1 ;
}
V_10 -> V_34 = 1 ;
F_8 ( V_55
L_18 ,
V_8 ) ;
}
}
F_25 ( & V_45 ) ;
return V_67 ;
}
static int F_34 ( struct V_59 * V_60 ,
unsigned long V_68 , void * V_69 )
{
return ( V_64 <= V_65 ) ? V_67 : V_70 ;
}
int F_35 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_22 ( & V_71 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_64 == V_72 ) {
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( V_10 -> F_2 . V_13 ) {
V_7 = F_10 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_55
L_19 , V_8 ) ;
V_10 -> V_34 = 1 ;
V_64 = V_73 ;
} else {
V_74 = 1 ;
F_36 ( V_8 , V_75 , & V_10 -> V_76 ) ;
}
}
}
F_25 ( & V_71 ) ;
if ( V_75 )
F_37 ( V_75 ) ;
return V_7 ;
}
int F_38 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_22 ( & V_71 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_64 == V_72 ) {
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_13 ) {
V_74 = 0 ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_14
L_20 ,
V_8 ) ;
}
}
}
F_25 ( & V_71 ) ;
return V_7 ;
}
static void F_39 ( unsigned int V_77 ,
unsigned int V_78 , unsigned long V_79 )
{
struct V_9 * V_10 ;
F_40 ( F_41 () ) . V_80 [ V_81 ] ++ ;
V_10 = & F_42 ( V_11 ) ;
F_43 ( & V_10 -> V_26 , F_44 ( & V_10 -> V_26 ) | V_78 ) ;
if ( V_75 )
F_45 ( V_75 , & V_10 -> V_76 ) ;
}
static int F_46 ( void )
{
int V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( V_7 )
return - V_58 ;
if ( ! V_10 -> F_2 . V_82 ) {
F_8 ( V_55 L_21 ) ;
return - V_3 ;
}
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_83 L_22 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
return - V_3 ;
F_8 ( V_55
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
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_82 )
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
V_10 -> V_27 = V_10 -> V_19 ;
}
static int F_49 ( unsigned int V_8 , int V_26 )
{
int V_7 ;
unsigned long * V_39 ;
struct V_9 * V_10 ;
V_7 = 0 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_39 = ( unsigned long * ) V_10 -> V_27 ;
if ( ! V_39 || ! * V_39 )
return - V_3 ;
if ( V_26 & V_84 )
V_10 -> V_29 ++ ;
if ( V_26 & V_85 )
V_10 -> V_32 ++ ;
if ( V_26 & V_86 ) {
V_10 -> V_31 ++ ;
V_7 = - V_3 ;
}
if ( V_26 & V_87 ) {
V_10 -> V_30 ++ ;
V_7 = - V_3 ;
}
if ( V_26 & V_88 ) {
V_10 -> V_33 ++ ;
V_7 = - V_3 ;
}
return V_7 ;
}
static void F_50 ( unsigned int V_8 )
{
int V_7 , V_66 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_34 ) {
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_55
L_24 ,
V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
F_8 ( V_55
L_19 ,
V_8 ) ;
F_15 (i) {
if ( V_66 == V_8 )
continue;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = 1 ;
F_36 ( V_66 , V_75 ,
& V_10 -> V_76 ) ;
}
}
}
}
}
static void F_51 ( unsigned int V_8 )
{
unsigned long * V_39 ;
unsigned char V_89 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_39 = ( unsigned long * ) V_10 -> V_27 ;
V_89 = 0 ;
while ( ! V_89 && ! V_10 -> V_36 ) {
unsigned long * V_42 ;
struct V_24 * V_90 ;
unsigned long * V_20 = 0 ;
V_42 = F_13 ( * V_39 ) ;
if ( ! ( * V_42 & V_91 ) ) {
V_89 = 1 ;
if ( ! V_74 )
continue;
}
V_90 = (struct V_24 * ) V_42 ;
V_10 -> V_28 += V_90 -> V_92 ;
F_52 ( V_8 , V_39 , V_20 ) ;
F_53 ( ( unsigned char * ) V_90 , 0x40 ) ;
V_39 ++ ;
if ( F_16 ( V_39 ) )
V_39 = F_17 ( V_39 ) ;
V_10 -> V_27 = ( unsigned long ) V_39 ;
}
}
static void F_52 ( unsigned int V_8 , unsigned long * V_39 ,
unsigned long * V_20 )
{
struct V_93 * V_94 ;
unsigned long * V_42 ;
V_42 = F_13 ( * V_39 ) ;
if ( V_20 ) {
if ( V_20 > V_42 )
return;
V_42 = V_20 ;
}
V_94 = (struct V_93 * ) ( * V_39 ) ;
while ( ( unsigned long * ) V_94 < V_42 ) {
struct V_95 * V_96 = NULL ;
struct V_97 * V_98 = NULL ;
if ( V_94 -> V_99 != 1 ) {
break;
} else {
V_94 -> V_99 = 0 ;
}
if ( V_94 -> V_100 == 1 ) {
unsigned int V_101 = V_94 -> V_102 ;
F_54 () ;
V_98 = F_55 ( F_56 ( V_101 ) , V_103 ) ;
if ( V_98 )
V_96 = F_57 ( V_98 ) ;
F_58 () ;
} else {
V_96 = F_57 ( V_104 ) ;
}
F_22 ( & V_71 ) ;
F_59 ( V_94 -> V_105 , V_96 , 0 ,
! V_94 -> V_100 , V_98 ) ;
F_25 ( & V_71 ) ;
V_94 ++ ;
}
}
static void V_76 ( struct V_106 * V_107 )
{
unsigned int V_8 ;
int V_26 ;
struct V_9 * V_10 ;
V_10 = F_60 ( V_107 , struct V_9 , V_76 ) ;
V_8 = F_41 () ;
V_26 = F_43 ( & V_10 -> V_26 , 0 ) ;
if ( ! V_10 -> V_27 )
F_48 ( V_8 ) ;
if ( F_49 ( V_8 , V_26 ) )
return;
if ( ! V_10 -> V_34 )
F_51 ( V_8 ) ;
if ( V_10 -> V_34 )
F_50 ( V_8 ) ;
}
int F_61 ( unsigned long V_39 , unsigned long V_40 )
{
int V_8 , V_7 ;
F_22 ( & V_71 ) ;
V_7 = - V_3 ;
if ( V_64 != V_65 )
goto V_108;
if ( V_39 < 1 )
goto V_108;
if ( V_40 > V_109 || V_40 < V_110 )
goto V_108;
V_43 = V_39 ;
V_48 = V_40 ;
V_46 = 0 ;
F_62 ( & V_111 ) ;
F_15 (cpu) {
if ( F_20 ( V_8 ) ) {
F_63 ( & V_111 ) ;
goto V_112;
}
}
F_63 ( & V_111 ) ;
if ( V_46 )
goto V_112;
V_64 = V_113 ;
V_7 = 0 ;
V_108:
F_25 ( & V_71 ) ;
return V_7 ;
V_112:
V_7 = - V_51 ;
F_8 ( V_14 L_25 ) ;
goto V_108;
}
int F_64 ( void )
{
int V_7 ;
F_22 ( & V_71 ) ;
V_7 = - V_3 ;
if ( V_64 != V_113 )
goto V_114;
F_65 ( 0 , 5 ) ;
F_26 () ;
V_64 = V_65 ;
V_7 = 0 ;
V_114:
F_25 ( & V_71 ) ;
return V_7 ;
}
unsigned long F_66 ( void )
{
return V_115 ;
}
unsigned long F_67 ( void )
{
return V_116 ;
}
unsigned long F_68 ( unsigned int V_8 )
{
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
return V_10 -> V_28 ;
}
int F_69 ( void )
{
int V_7 ;
int V_8 ;
struct V_9 * V_10 ;
F_22 ( & V_71 ) ;
V_7 = - V_3 ;
if ( V_64 )
goto V_117;
V_64 = V_118 ;
F_14 () ;
V_7 = F_30 () ;
if ( V_7 )
goto V_117;
V_7 = F_46 () ;
if ( V_7 )
goto V_117;
V_7 = - V_3 ;
V_75 = F_70 ( L_26 ) ;
if ( ! V_75 )
goto V_117;
F_71 ( & V_119 ) ;
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_72 ( & V_10 -> V_76 , V_76 ) ;
V_7 = F_12 ( V_8 ) ;
F_29 ( V_7 ) ;
if ( V_115 != V_10 -> F_2 . V_120 ) {
if ( V_115 ) {
F_8 ( V_83
L_27 ) ;
if ( V_115 < V_10 -> F_2 . V_120 )
V_115 =
V_10 -> F_2 . V_120 ;
} else
V_115 = V_10 -> F_2 . V_120 ;
}
if ( V_116 != V_10 -> F_2 . V_121 ) {
if ( V_116 ) {
F_8 ( V_83
L_28 ) ;
if ( V_116 > V_10 -> F_2 . V_121 )
V_116 =
V_10 -> F_2 . V_121 ;
} else
V_116 = V_10 -> F_2 . V_121 ;
}
}
F_73 ( 0x1407 , F_39 ) ;
V_64 = V_65 ;
V_7 = 0 ;
V_117:
F_25 ( & V_71 ) ;
return V_7 ;
}
int F_74 ( void )
{
int V_7 ;
F_22 ( & V_71 ) ;
V_7 = - V_3 ;
if ( V_64 == V_65 || V_64 == V_113 ) {
F_25 ( & V_71 ) ;
if ( V_75 )
F_37 ( V_75 ) ;
F_22 ( & V_71 ) ;
if ( V_64 == V_113 ) {
F_65 ( 0 , 5 ) ;
F_26 () ;
}
if ( V_75 ) {
F_75 ( V_75 ) ;
V_75 = NULL ;
}
F_76 ( 0x1407 , F_39 ) ;
V_64 = V_118 ;
V_7 = 0 ;
}
F_25 ( & V_71 ) ;
F_77 ( & V_119 ) ;
return V_7 ;
}
int F_78 ( unsigned long V_122 )
{
int V_7 , V_8 ;
F_22 ( & V_71 ) ;
V_123 = 0 ;
V_7 = - V_3 ;
if ( V_64 != V_113 )
goto V_124;
V_16 = V_122 ;
if ( V_16 < V_115 || V_16 > V_116 )
goto V_124;
V_7 = F_47 () ;
if ( V_7 )
goto V_124;
V_7 = F_18 () ;
if ( V_7 )
goto V_124;
F_15 (cpu) {
V_7 = F_27 ( V_8 ) ;
if ( V_7 )
break;
}
if ( V_7 ) {
F_15 (cpu) {
F_28 ( V_8 ) ;
}
goto V_124;
}
V_64 = V_72 ;
V_7 = 0 ;
V_124:
F_25 ( & V_71 ) ;
if ( V_7 )
return V_7 ;
F_62 ( & V_111 ) ;
V_123 = 1 ;
V_74 = 0 ;
F_79 ( 0 , 5 ) ;
return 0 ;
}
int F_80 ( void )
{
int V_125 , V_7 , V_8 ;
struct V_9 * V_10 ;
F_22 ( & V_71 ) ;
V_7 = 0 ;
if ( V_64 == V_118 ) {
F_25 ( & V_71 ) ;
return V_7 ;
}
V_64 = V_73 ;
F_25 ( & V_71 ) ;
F_15 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> V_36 = 1 ;
V_125 = F_28 ( V_8 ) ;
if ( V_125 )
V_7 = V_125 ;
}
if ( V_75 )
F_37 ( V_75 ) ;
F_22 ( & V_71 ) ;
if ( V_123 ) {
F_63 ( & V_111 ) ;
V_123 = 0 ;
}
V_64 = V_113 ;
F_25 ( & V_71 ) ;
return V_7 ;
}
