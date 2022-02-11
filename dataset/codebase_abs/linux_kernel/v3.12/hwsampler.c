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
F_16 ( V_29 ) ;
F_17 ( & V_10 -> V_30 , F_18 ( & V_10 -> V_30 ) | V_26 ) ;
if ( V_31 )
F_19 ( V_31 , & V_10 -> V_32 ) ;
}
static void F_20 ( void )
{
int V_8 ;
struct V_9 * V_10 ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
}
}
static int F_22 ( unsigned long * V_33 )
{
return * V_33 & 0x1ul ? 1 : 0 ;
}
static unsigned long * F_23 ( unsigned long * V_33 )
{
return ( unsigned long * ) ( * V_33 & ~ 0x1ul ) ;
}
static int F_24 ( void )
{
int V_8 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_25 ( & V_10 -> V_30 , 0 ) ;
V_10 -> V_34 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_36 = 0 ;
V_10 -> V_37 = 0 ;
V_10 -> V_38 = 0 ;
V_10 -> V_39 = 0 ;
V_10 -> V_40 = 0 ;
V_10 -> V_41 = 0 ;
V_10 -> V_42 = 0 ;
V_10 -> V_43 = 0 ;
}
return V_7 ;
}
static int F_26 ( int V_8 )
{
int V_44 , V_45 , V_7 ;
unsigned long * V_46 ;
unsigned long V_47 ;
unsigned long * V_48 ;
unsigned long * V_49 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_19 )
return - V_3 ;
V_46 = NULL ;
V_48 = V_46 ;
for ( V_44 = 0 ; V_44 < V_50 ; V_44 ++ ) {
V_46 = ( unsigned long * ) F_27 ( V_51 ) ;
F_28 ( & V_52 ) ;
F_29 () ;
if ( V_53 || ! V_46 ) {
if ( V_46 )
F_30 ( ( unsigned long ) V_46 ) ;
goto V_54;
}
if ( V_10 -> V_19 == 0 )
V_10 -> V_19 = ( unsigned long ) V_46 ;
if ( V_48 )
* V_48 = ( unsigned long ) ( void * ) V_46 + 1 ;
F_31 ( & V_52 ) ;
for ( V_45 = 0 ; V_45 < V_55 ; V_45 ++ ) {
V_47 = F_27 ( V_51 ) ;
F_28 ( & V_52 ) ;
F_29 () ;
if ( V_53 || ! V_47 ) {
if ( V_47 )
F_30 ( V_47 ) ;
goto V_54;
}
* V_46 = V_47 ;
V_49 = F_13 ( * V_46 ) ;
* V_49 = V_56 ;
V_46 ++ ;
F_31 ( & V_52 ) ;
}
V_48 = V_46 ;
}
F_28 ( & V_52 ) ;
if ( V_53 )
goto V_54;
V_7 = 0 ;
if ( V_48 )
* V_48 = ( unsigned long )
( ( void * ) V_10 -> V_19 ) + 1 ;
V_57:
F_31 ( & V_52 ) ;
return V_7 ;
V_54:
V_7 = - V_58 ;
goto V_57;
}
static int F_32 ( void )
{
int V_8 ;
int V_59 ;
V_59 = 0 ;
F_21 (cpu) {
unsigned long V_60 ;
unsigned long V_46 ;
unsigned long * V_61 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_19 )
continue;
V_46 = V_10 -> V_19 ;
V_61 = ( unsigned long * ) V_46 ;
V_60 = V_46 ;
while ( 1 ) {
if ( ! * V_61 || ! V_46 )
break;
if ( F_22 ( V_61 ) ) {
V_61 = F_23 ( V_61 ) ;
if ( V_46 )
F_30 ( V_46 ) ;
if ( ( unsigned long ) V_61 == V_60 )
break;
else
V_46 = ( unsigned long ) V_61 ;
} else {
if ( * V_61 ) {
F_30 ( * V_61 ) ;
V_61 ++ ;
}
}
V_59 ++ ;
}
V_10 -> V_19 = 0 ;
}
return V_59 ;
}
static int F_33 ( int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_62 L_5 , V_8 ) ;
goto V_63;
}
V_7 = - V_3 ;
if ( ! V_10 -> F_2 . V_12 ) {
F_8 ( V_62 L_6 , V_8 ) ;
goto V_63;
}
if ( ! V_10 -> F_2 . V_13 ) {
F_8 ( V_62 L_7 , V_8 ) ;
goto V_63;
}
F_8 ( V_62
L_8 ,
V_8 , V_16 ) ;
V_7 = 0 ;
V_63:
return V_7 ;
}
static int F_34 ( int V_8 )
{
unsigned long V_21 ;
int V_7 ;
struct V_9 * V_10 ;
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_7 && ! V_10 -> F_2 . V_12 )
F_8 ( V_62 L_9 , V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_62 L_10 ,
V_8 , V_7 ) ;
goto V_64;
}
F_8 ( V_62 L_11 , V_8 ) ;
V_64:
V_21 = V_10 -> V_36 ;
if ( V_21 )
F_8 ( V_14 L_12
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_39 ;
if ( V_21 )
F_8 ( V_14 L_14
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_38 ;
if ( V_21 )
F_8 ( V_14 L_15
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_37 ;
if ( V_21 )
F_8 ( V_14
L_16
L_13 , V_8 , V_21 ) ;
V_21 = V_10 -> V_40 ;
if ( V_21 )
F_8 ( V_14
L_17
L_13 , V_8 , V_21 ) ;
return V_7 ;
}
static int F_36 ( void )
{
if ( ! F_37 ( 68 ) )
return - V_65 ;
return 0 ;
}
static int F_38 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_69 )
{
unsigned long * V_70 ;
int V_8 ;
struct V_9 * V_10 ;
V_70 = V_69 ;
F_28 ( & V_52 ) ;
if ( V_71 == V_72 ) {
if ( V_53 == 0 ) {
V_53 = 1 ;
* V_70 += F_32 () ;
}
} else {
int V_73 ;
V_8 = F_39 () ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( ! V_10 -> V_42 ) {
F_21 (i) {
F_10 ( V_73 ) ;
V_10 -> V_42 = 1 ;
}
V_10 -> V_41 = 1 ;
F_8 ( V_62
L_18 ,
V_8 ) ;
}
}
F_31 ( & V_52 ) ;
return V_74 ;
}
static int F_40 ( struct V_66 * V_67 ,
unsigned long V_75 , void * V_76 )
{
return ( V_71 <= V_72 ) ? V_74 : V_77 ;
}
int F_41 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_28 ( & V_78 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_71 == V_79 ) {
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( V_10 -> F_2 . V_13 ) {
V_7 = F_10 ( V_8 ) ;
if ( V_7 ) {
F_8 ( V_62
L_19 , V_8 ) ;
V_10 -> V_41 = 1 ;
V_71 = V_80 ;
} else {
V_81 = 1 ;
F_42 ( V_8 , V_31 , & V_10 -> V_32 ) ;
}
}
}
F_31 ( & V_78 ) ;
if ( V_31 )
F_43 ( V_31 ) ;
return V_7 ;
}
int F_44 ( unsigned int V_8 )
{
int V_7 ;
struct V_9 * V_10 ;
V_7 = 0 ;
F_28 ( & V_78 ) ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_71 == V_79 ) {
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_13 ) {
V_81 = 0 ;
V_7 = F_11 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_8 ( V_14
L_20 ,
V_8 ) ;
}
}
}
F_31 ( & V_78 ) ;
return V_7 ;
}
static int F_45 ( void )
{
int V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( V_7 )
return - V_65 ;
if ( ! V_10 -> F_2 . V_82 ) {
F_8 ( V_62 L_21 ) ;
return - V_3 ;
}
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_83 L_22 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
return - V_3 ;
F_8 ( V_62
L_23 , V_8 ) ;
}
}
return 0 ;
}
static int F_46 ( void )
{
unsigned int V_8 ;
int V_7 ;
struct V_9 * V_10 ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( ! V_10 -> F_2 . V_82 )
return - V_3 ;
if ( V_10 -> F_2 . V_12 )
return - V_3 ;
if ( V_10 -> F_2 . V_13 )
return - V_3 ;
}
return 0 ;
}
static void F_47 ( unsigned int V_8 )
{
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> V_34 = V_10 -> V_19 ;
}
static int F_48 ( unsigned int V_8 , int V_30 )
{
int V_7 ;
unsigned long * V_46 ;
struct V_9 * V_10 ;
V_7 = 0 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_46 = ( unsigned long * ) V_10 -> V_34 ;
if ( ! V_46 || ! * V_46 )
return - V_3 ;
if ( V_30 & V_84 )
V_10 -> V_36 ++ ;
if ( V_30 & V_85 )
V_10 -> V_39 ++ ;
if ( V_30 & V_86 ) {
V_10 -> V_38 ++ ;
V_7 = - V_3 ;
}
if ( V_30 & V_87 ) {
V_10 -> V_37 ++ ;
V_7 = - V_3 ;
}
if ( V_30 & V_88 ) {
V_10 -> V_40 ++ ;
V_7 = - V_3 ;
}
return V_7 ;
}
static void F_49 ( unsigned int V_8 )
{
int V_7 , V_73 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
if ( V_10 -> V_41 ) {
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( V_10 -> F_2 . V_12 ) {
F_8 ( V_62
L_24 ,
V_8 ) ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
F_8 ( V_62
L_19 ,
V_8 ) ;
F_21 (i) {
if ( V_73 == V_8 )
continue;
if ( ! V_10 -> V_41 ) {
V_10 -> V_41 = 1 ;
F_42 ( V_73 , V_31 ,
& V_10 -> V_32 ) ;
}
}
}
}
}
static void F_50 ( unsigned int V_8 )
{
unsigned long * V_46 ;
unsigned char V_89 ;
struct V_9 * V_10 ;
V_10 = & F_6 ( V_11 , V_8 ) ;
V_46 = ( unsigned long * ) V_10 -> V_34 ;
V_89 = 0 ;
while ( ! V_89 && ! V_10 -> V_43 ) {
unsigned long * V_49 ;
struct V_24 * V_90 ;
unsigned long * V_20 = 0 ;
V_49 = F_13 ( * V_46 ) ;
if ( ! ( * V_49 & V_91 ) ) {
V_89 = 1 ;
if ( ! V_81 )
continue;
}
V_90 = (struct V_24 * ) V_49 ;
V_10 -> V_35 += V_90 -> V_92 ;
F_51 ( V_8 , V_46 , V_20 ) ;
F_52 ( ( unsigned char * ) V_90 , 0x40 ) ;
V_46 ++ ;
if ( F_22 ( V_46 ) )
V_46 = F_23 ( V_46 ) ;
V_10 -> V_34 = ( unsigned long ) V_46 ;
}
}
static void F_51 ( unsigned int V_8 , unsigned long * V_46 ,
unsigned long * V_20 )
{
struct V_93 * V_94 ;
unsigned long * V_49 ;
V_49 = F_13 ( * V_46 ) ;
if ( V_20 ) {
if ( V_20 > V_49 )
return;
V_49 = V_20 ;
}
V_94 = (struct V_93 * ) ( * V_46 ) ;
while ( ( unsigned long * ) V_94 < V_49 ) {
struct V_95 * V_96 = NULL ;
struct V_97 * V_98 = NULL ;
if ( V_94 -> V_99 != 1 ) {
break;
} else {
V_94 -> V_99 = 0 ;
}
if ( V_94 -> V_100 == 1 ) {
unsigned int V_101 = V_94 -> V_102 ;
if ( ! V_103 . V_104 )
goto V_105;
F_53 () ;
V_98 = F_54 ( F_55 ( V_101 ) , V_106 ) ;
if ( V_98 )
V_96 = F_56 ( V_98 ) ;
F_57 () ;
} else {
if ( ! V_103 . V_107 )
goto V_105;
V_96 = F_56 ( V_108 ) ;
}
F_28 ( & V_78 ) ;
F_58 ( V_94 -> V_109 , V_96 , 0 ,
! V_94 -> V_100 , V_98 ) ;
F_31 ( & V_78 ) ;
V_105:
V_94 ++ ;
}
}
static void V_32 ( struct V_110 * V_111 )
{
unsigned int V_8 ;
int V_30 ;
struct V_9 * V_10 ;
V_10 = F_59 ( V_111 , struct V_9 , V_32 ) ;
V_8 = F_60 () ;
V_30 = F_17 ( & V_10 -> V_30 , 0 ) ;
if ( ! V_10 -> V_34 )
F_47 ( V_8 ) ;
if ( F_48 ( V_8 , V_30 ) )
return;
if ( ! V_10 -> V_41 )
F_50 ( V_8 ) ;
if ( V_10 -> V_41 )
F_49 ( V_8 ) ;
}
int F_61 ( unsigned long V_46 , unsigned long V_47 )
{
int V_8 , V_7 ;
F_28 ( & V_78 ) ;
V_7 = - V_3 ;
if ( V_71 != V_72 )
goto V_112;
if ( V_46 < 1 )
goto V_112;
if ( V_47 > V_113 || V_47 < V_114 )
goto V_112;
V_50 = V_46 ;
V_55 = V_47 ;
V_53 = 0 ;
F_62 ( & V_115 ) ;
F_21 (cpu) {
if ( F_26 ( V_8 ) ) {
F_63 ( & V_115 ) ;
goto V_116;
}
}
F_63 ( & V_115 ) ;
if ( V_53 )
goto V_116;
V_71 = V_117 ;
V_7 = 0 ;
V_112:
F_31 ( & V_78 ) ;
return V_7 ;
V_116:
V_7 = - V_58 ;
F_8 ( V_14 L_25 ) ;
goto V_112;
}
int F_64 ( void )
{
int V_7 ;
F_28 ( & V_78 ) ;
V_7 = - V_3 ;
if ( V_71 != V_117 )
goto V_118;
F_65 ( V_119 ) ;
F_32 () ;
V_71 = V_72 ;
V_7 = 0 ;
V_118:
F_31 ( & V_78 ) ;
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
return V_10 -> V_35 ;
}
int F_69 ( void )
{
int V_7 ;
int V_8 ;
struct V_9 * V_10 ;
F_28 ( & V_78 ) ;
V_7 = - V_3 ;
if ( V_71 )
goto V_122;
V_71 = V_123 ;
F_20 () ;
V_7 = F_36 () ;
if ( V_7 )
goto V_122;
V_7 = F_45 () ;
if ( V_7 )
goto V_122;
V_7 = - V_3 ;
V_31 = F_70 ( L_26 ) ;
if ( ! V_31 )
goto V_122;
F_71 ( & V_124 ) ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
F_72 ( & V_10 -> V_32 , V_32 ) ;
V_7 = F_12 ( V_8 ) ;
F_35 ( V_7 ) ;
if ( V_120 != V_10 -> F_2 . V_125 ) {
if ( V_120 ) {
F_8 ( V_83
L_27 ) ;
if ( V_120 < V_10 -> F_2 . V_125 )
V_120 =
V_10 -> F_2 . V_125 ;
} else
V_120 = V_10 -> F_2 . V_125 ;
}
if ( V_121 != V_10 -> F_2 . V_126 ) {
if ( V_121 ) {
F_8 ( V_83
L_28 ) ;
if ( V_121 > V_10 -> F_2 . V_126 )
V_121 =
V_10 -> F_2 . V_126 ;
} else
V_121 = V_10 -> F_2 . V_126 ;
}
}
F_73 ( 0x1407 , F_14 ) ;
V_71 = V_72 ;
V_7 = 0 ;
V_122:
F_31 ( & V_78 ) ;
return V_7 ;
}
int F_74 ( void )
{
int V_7 ;
F_28 ( & V_78 ) ;
V_7 = - V_3 ;
if ( V_71 == V_72 || V_71 == V_117 ) {
F_31 ( & V_78 ) ;
if ( V_31 )
F_43 ( V_31 ) ;
F_28 ( & V_78 ) ;
if ( V_71 == V_117 ) {
F_65 ( V_119 ) ;
F_32 () ;
}
if ( V_31 ) {
F_75 ( V_31 ) ;
V_31 = NULL ;
}
F_76 ( 0x1407 , F_14 ) ;
V_71 = V_123 ;
V_7 = 0 ;
}
F_31 ( & V_78 ) ;
F_77 ( & V_124 ) ;
return V_7 ;
}
int F_78 ( unsigned long V_127 )
{
int V_7 , V_8 ;
F_28 ( & V_78 ) ;
V_128 = 0 ;
V_7 = - V_3 ;
if ( V_71 != V_117 )
goto V_129;
V_16 = V_127 ;
if ( V_16 < V_120 || V_16 > V_121 )
goto V_129;
V_7 = F_46 () ;
if ( V_7 )
goto V_129;
V_7 = F_24 () ;
if ( V_7 )
goto V_129;
F_21 (cpu) {
V_7 = F_33 ( V_8 ) ;
if ( V_7 )
break;
}
if ( V_7 ) {
F_21 (cpu) {
F_34 ( V_8 ) ;
}
goto V_129;
}
V_71 = V_79 ;
V_7 = 0 ;
V_129:
F_31 ( & V_78 ) ;
if ( V_7 )
return V_7 ;
F_62 ( & V_115 ) ;
V_128 = 1 ;
V_81 = 0 ;
F_79 ( V_119 ) ;
return 0 ;
}
int F_80 ( void )
{
int V_130 , V_7 , V_8 ;
struct V_9 * V_10 ;
F_28 ( & V_78 ) ;
V_7 = 0 ;
if ( V_71 == V_123 ) {
F_31 ( & V_78 ) ;
return V_7 ;
}
V_71 = V_80 ;
F_31 ( & V_78 ) ;
F_21 (cpu) {
V_10 = & F_6 ( V_11 , V_8 ) ;
V_10 -> V_43 = 1 ;
V_130 = F_34 ( V_8 ) ;
if ( V_130 )
V_7 = V_130 ;
}
if ( V_31 )
F_43 ( V_31 ) ;
F_28 ( & V_78 ) ;
if ( V_128 ) {
F_63 ( & V_115 ) ;
V_128 = 0 ;
}
V_71 = V_117 ;
F_31 ( & V_78 ) ;
return V_7 ;
}
