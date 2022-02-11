static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( & V_4 ) ;
}
static int T_1 F_3 ( char * V_5 )
{
int V_6 , V_7 ;
V_7 = F_4 ( V_5 , 0 , & V_6 ) ;
if ( ! V_7 && V_6 >= V_8 )
V_9 = V_6 ;
return 1 ;
}
static int T_1 F_5 ( char * V_5 )
{
int V_10 , V_7 ;
V_7 = F_4 ( V_5 , 0 , & V_10 ) ;
if ( ! V_7 && V_10 )
V_11 = 1 ;
return 1 ;
}
int
F_6 ( T_2 V_12 , void * V_13 )
{
int V_14 = 4 ;
asm volatile(
"0: .insn rre,0xb2200000,%1,%2\n"
"1: ipm %0\n"
" srl %0,28\n"
"2:\n"
EX_TABLE(0b, 2b)
EX_TABLE(1b, 2b)
: "+&d" (cc) : "d" (command), "a" (__pa(sccb))
: "cc", "memory");
if ( V_14 == 4 )
return - V_15 ;
if ( V_14 == 3 )
return - V_16 ;
if ( V_14 == 2 )
return - V_17 ;
return 0 ;
}
static void
F_7 ( void )
{
if ( V_18 == V_19 ) {
V_18 = V_20 ;
F_8 () ;
F_9 ( & V_21 . V_22 , & V_23 ) ;
}
}
static inline void
F_10 ( unsigned long time , void (* F_11)( unsigned long ) ,
unsigned long V_3 )
{
F_12 ( & V_24 ) ;
V_24 . F_11 = F_11 ;
V_24 . V_3 = V_3 ;
V_24 . V_25 = V_26 + time ;
F_13 ( & V_24 ) ;
}
static void
F_14 ( unsigned long V_3 )
{
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_3 ) {
if ( V_29 == V_30 ) {
F_7 () ;
V_29 = V_31 ;
}
} else {
F_10 ( V_32 * V_33 ,
F_14 , 0 ) ;
}
F_16 ( & V_28 , V_27 ) ;
F_17 () ;
}
static unsigned long F_18 ( void )
{
unsigned long V_34 = 0 ;
struct V_1 * V_2 ;
F_19 (req, &sclp_req_queue, list) {
if ( ! V_2 -> V_35 )
continue;
if ( ! V_34 ||
( F_20 ( V_2 -> V_35 , V_34 ) ) )
V_34 = V_2 -> V_35 ;
}
return V_34 ;
}
static struct V_1 * F_21 ( void )
{
unsigned long V_27 , V_36 ;
struct V_1 * V_2 ;
F_15 ( & V_28 , V_27 ) ;
V_36 = V_26 ;
F_19 (req, &sclp_req_queue, list) {
if ( ! V_2 -> V_35 )
continue;
if ( F_22 ( V_2 -> V_35 , V_36 ) ) {
if ( V_2 -> V_37 == V_38 ) {
V_2 -> V_37 = V_39 ;
F_23 ( & V_2 -> V_22 ) ;
goto V_40;
}
}
}
V_2 = NULL ;
V_40:
F_16 ( & V_28 , V_27 ) ;
return V_2 ;
}
static void F_24 ( unsigned long V_3 )
{
unsigned long V_27 , V_34 ;
struct V_1 * V_2 ;
do {
V_2 = F_21 () ;
if ( V_2 && V_2 -> V_41 )
V_2 -> V_41 ( V_2 , V_2 -> V_42 ) ;
} while ( V_2 );
F_15 ( & V_28 , V_27 ) ;
V_34 = F_18 () ;
if ( V_34 )
F_25 ( & V_43 , V_34 ) ;
F_16 ( & V_28 , V_27 ) ;
}
static int
F_26 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_29 != V_31 )
return 0 ;
F_12 ( & V_24 ) ;
V_7 = F_6 ( V_2 -> V_12 , V_2 -> V_13 ) ;
V_2 -> V_44 ++ ;
if ( V_7 == 0 ) {
V_2 -> V_37 = V_45 ;
V_29 = V_30 ;
F_10 ( V_46 * V_33 ,
F_14 , 1 ) ;
return 0 ;
} else if ( V_7 == - V_17 ) {
F_10 ( V_32 * V_33 ,
F_14 , 0 ) ;
return 0 ;
}
V_2 -> V_37 = V_47 ;
return V_7 ;
}
static void
F_17 ( void )
{
struct V_1 * V_2 ;
int V_7 ;
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_29 != V_31 ) {
F_16 ( & V_28 , V_27 ) ;
return;
}
F_12 ( & V_24 ) ;
while ( ! F_27 ( & V_23 ) ) {
V_2 = F_28 ( V_23 . V_48 , struct V_1 , V_22 ) ;
if ( ! V_2 -> V_13 )
goto V_49;
V_7 = F_26 ( V_2 ) ;
if ( V_7 == 0 )
break;
if ( V_2 -> V_44 > 1 ) {
F_10 ( V_32 * V_33 ,
F_14 , 0 ) ;
break;
}
V_49:
F_23 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_41 ) {
F_16 ( & V_28 , V_27 ) ;
V_2 -> V_41 ( V_2 , V_2 -> V_42 ) ;
F_15 ( & V_28 , V_27 ) ;
}
}
F_16 ( & V_28 , V_27 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
if ( V_2 == & V_50 || V_2 == & V_51 )
return 1 ;
if ( V_52 != V_53 )
return 0 ;
if ( V_54 != V_55 )
return 0 ;
if ( V_56 != V_57 )
return 0 ;
return 1 ;
}
int
F_30 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( ! F_29 ( V_2 ) ) {
F_16 ( & V_28 , V_27 ) ;
return - V_16 ;
}
V_2 -> V_37 = V_38 ;
V_2 -> V_44 = 0 ;
F_31 ( & V_2 -> V_22 , & V_23 ) ;
V_7 = 0 ;
if ( V_2 -> V_58 ) {
V_2 -> V_35 = V_26 + V_2 -> V_58 * V_33 ;
if ( ! F_32 ( & V_43 ) ||
F_33 ( V_43 . V_25 , V_2 -> V_35 ) )
F_25 ( & V_43 , V_2 -> V_35 ) ;
} else
V_2 -> V_35 = 0 ;
if ( V_29 == V_31 &&
V_2 -> V_22 . V_59 == & V_23 ) {
if ( ! V_2 -> V_13 ) {
F_23 ( & V_2 -> V_22 ) ;
V_7 = - V_60 ;
goto V_40;
}
V_7 = F_26 ( V_2 ) ;
if ( V_7 )
F_23 ( & V_2 -> V_22 ) ;
}
V_40:
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int
F_34 ( struct V_61 * V_13 )
{
unsigned long V_27 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int V_68 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_7 = 0 ;
for ( V_68 = sizeof( struct V_61 ) ; V_68 < V_13 -> V_69 ;
V_68 += V_63 -> V_69 ) {
V_63 = (struct V_62 * ) ( ( V_70 ) V_13 + V_68 ) ;
if ( V_63 -> V_69 == 0 )
break;
V_67 = NULL ;
F_35 (l, &sclp_reg_list) {
V_67 = F_28 ( V_65 , struct V_66 , V_22 ) ;
if ( V_67 -> V_71 & ( 1 << ( 32 - V_63 -> type ) ) )
break;
else
V_67 = NULL ;
}
if ( V_67 && V_67 -> V_72 ) {
F_16 ( & V_28 , V_27 ) ;
V_67 -> V_72 ( V_63 ) ;
F_15 ( & V_28 , V_27 ) ;
} else if ( V_67 == NULL )
V_7 = - V_73 ;
}
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static void
F_36 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_27 ;
struct V_61 * V_13 ;
V_13 = (struct V_61 * ) V_2 -> V_13 ;
if ( V_2 -> V_37 == V_74 && ( V_13 -> V_75 == 0x20 ||
V_13 -> V_75 == 0x220 ) )
F_34 ( V_13 ) ;
F_15 ( & V_28 , V_27 ) ;
V_18 = V_19 ;
F_16 ( & V_28 , V_27 ) ;
}
static void F_8 ( void )
{
struct V_61 * V_13 ;
V_13 = (struct V_61 * ) V_76 ;
F_37 ( V_13 ) ;
memset ( & V_21 , 0 , sizeof( struct V_1 ) ) ;
V_21 . V_12 = V_77 ;
V_21 . V_37 = V_38 ;
V_21 . V_44 = 0 ;
V_21 . V_41 = F_36 ;
V_21 . V_13 = V_13 ;
V_13 -> V_69 = V_78 ;
V_13 -> V_79 = 0 ;
V_13 -> V_80 [ 2 ] = 0x80 ;
}
static inline struct V_1 *
F_38 ( T_3 V_13 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
F_35 (l, &sclp_req_queue) {
V_2 = F_28 ( V_65 , struct V_1 , V_22 ) ;
if ( V_13 == ( T_3 ) ( V_70 ) V_2 -> V_13 )
return V_2 ;
}
return NULL ;
}
static void F_39 ( struct V_81 V_81 ,
unsigned int V_82 , unsigned long V_83 )
{
struct V_1 * V_2 ;
T_3 V_84 ;
T_3 V_85 ;
F_40 ( V_86 ) ;
F_41 ( & V_28 ) ;
V_84 = V_82 & 0xfffffff8 ;
V_85 = V_82 & 0x3 ;
if ( V_84 ) {
F_12 ( & V_24 ) ;
V_29 = V_87 ;
V_2 = F_38 ( V_84 ) ;
if ( V_2 ) {
F_23 ( & V_2 -> V_22 ) ;
V_2 -> V_37 = V_74 ;
if ( V_2 -> V_41 ) {
F_42 ( & V_28 ) ;
V_2 -> V_41 ( V_2 , V_2 -> V_42 ) ;
F_41 ( & V_28 ) ;
}
}
V_29 = V_31 ;
}
if ( V_85 &&
V_56 == V_57 )
F_7 () ;
F_42 ( & V_28 ) ;
F_17 () ;
}
static inline T_4
F_43 ( unsigned long V_26 )
{
return ( T_4 ) ( V_26 / V_33 ) << 32 ;
}
void
F_44 ( void )
{
unsigned long long V_88 ;
unsigned long V_27 ;
unsigned long V_89 , V_90 ;
T_4 V_91 ;
int V_92 ;
V_91 = 0 ;
if ( F_32 ( & V_24 ) ) {
V_91 = F_45 () +
F_43 ( V_24 . V_25 -
V_26 ) ;
}
F_46 ( V_27 ) ;
V_92 = F_47 () ;
if ( ! V_92 )
F_48 () ;
V_88 = F_49 () ;
F_50 () ;
F_51 ( V_89 , 0 , 0 ) ;
V_90 = V_89 ;
V_90 &= 0xffff00a0 ;
V_90 |= 0x00000200 ;
F_52 ( V_90 , 0 , 0 ) ;
F_53 ( 0x01 ) ;
while ( V_29 != V_31 ) {
if ( F_32 ( & V_24 ) &&
F_45 () > V_91 &&
F_12 ( & V_24 ) )
V_24 . F_11 ( V_24 . V_3 ) ;
F_54 () ;
}
F_55 () ;
F_52 ( V_89 , 0 , 0 ) ;
if ( ! V_92 )
F_56 () ;
F_57 ( V_88 ) ;
F_58 ( V_27 ) ;
}
static void
F_59 ( void )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
unsigned long V_27 ;
T_5 V_71 ;
T_5 V_93 ;
do {
F_15 ( & V_28 , V_27 ) ;
V_67 = NULL ;
F_35 (l, &sclp_reg_list) {
V_67 = F_28 ( V_65 , struct V_66 , V_22 ) ;
V_71 = V_67 -> V_93 & V_94 ;
V_93 = V_67 -> V_71 & V_95 ;
if ( V_67 -> V_94 != V_71 ||
V_67 -> V_95 != V_93 ) {
V_67 -> V_94 = V_71 ;
V_67 -> V_95 = V_93 ;
break;
} else
V_67 = NULL ;
}
F_16 ( & V_28 , V_27 ) ;
if ( V_67 && V_67 -> V_96 )
V_67 -> V_96 ( V_67 ) ;
} while ( V_67 );
}
static void
F_60 ( struct V_62 * V_63 )
{
unsigned long V_27 ;
struct V_97 * V_98 ;
V_98 = (struct V_97 * ) V_63 ;
if ( V_98 -> V_99 != sizeof( T_5 ) )
return;
F_15 ( & V_28 , V_27 ) ;
if ( V_98 -> V_100 )
V_94 = V_98 -> V_94 ;
if ( V_98 -> V_101 )
V_95 = V_98 -> V_95 ;
F_16 ( & V_28 , V_27 ) ;
if ( V_98 -> V_102 )
V_103 . V_104 = V_98 -> V_105 ;
F_59 () ;
}
static inline void
F_61 ( T_5 * V_71 , T_5 * V_93 )
{
struct V_64 * V_65 ;
struct V_66 * V_106 ;
* V_71 = 0 ;
* V_93 = 0 ;
F_35 (l, &sclp_reg_list) {
V_106 = F_28 ( V_65 , struct V_66 , V_22 ) ;
* V_71 |= V_106 -> V_71 ;
* V_93 |= V_106 -> V_93 ;
}
}
int
V_66 ( struct V_66 * V_67 )
{
unsigned long V_27 ;
T_5 V_71 ;
T_5 V_93 ;
int V_7 ;
V_7 = F_62 () ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 , V_27 ) ;
F_61 ( & V_71 , & V_93 ) ;
if ( V_67 -> V_71 & V_71 || V_67 -> V_93 & V_93 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_17 ;
}
V_67 -> V_94 = 0 ;
V_67 -> V_95 = 0 ;
V_67 -> V_107 = 0 ;
F_9 ( & V_67 -> V_22 , & V_108 ) ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_63 ( 1 ) ;
if ( V_7 ) {
F_15 ( & V_28 , V_27 ) ;
F_23 ( & V_67 -> V_22 ) ;
F_16 ( & V_28 , V_27 ) ;
}
return V_7 ;
}
void
F_64 ( struct V_66 * V_67 )
{
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
F_23 ( & V_67 -> V_22 ) ;
F_16 ( & V_28 , V_27 ) ;
F_63 ( 1 ) ;
}
int
F_65 ( struct V_61 * V_13 )
{
struct V_62 * V_63 ;
int V_109 ;
T_6 V_110 ;
V_63 = (struct V_62 * ) ( V_13 + 1 ) ;
V_109 = 0 ;
V_110 = V_13 -> V_69 - sizeof( struct V_61 ) ;
while ( V_110 > 0 ) {
V_110 -= V_63 -> V_69 ;
if ( V_63 -> V_27 & 0x80 ) {
V_13 -> V_69 -= V_63 -> V_69 ;
memcpy ( V_63 , ( void * ) ( ( V_70 ) V_63 + V_63 -> V_69 ) ,
V_110 ) ;
} else {
V_109 ++ ;
V_63 = (struct V_62 * )
( ( V_70 ) V_63 + V_63 -> V_69 ) ;
}
}
return V_109 ;
}
static inline void
F_66 ( T_3 V_71 , T_3 V_93 )
{
struct V_111 * V_13 ;
V_13 = (struct V_111 * ) V_112 ;
F_37 ( V_13 ) ;
memset ( & V_51 , 0 , sizeof( struct V_1 ) ) ;
V_51 . V_12 = V_113 ;
V_51 . V_37 = V_114 ;
V_51 . V_44 = 0 ;
V_51 . V_41 = NULL ;
V_51 . V_42 = NULL ;
V_51 . V_13 = V_13 ;
V_13 -> V_115 . V_69 = sizeof( struct V_111 ) ;
V_13 -> V_99 = sizeof( T_5 ) ;
V_13 -> V_71 = V_71 ;
V_13 -> V_93 = V_93 ;
V_13 -> V_94 = 0 ;
V_13 -> V_95 = 0 ;
}
static int
F_63 ( int V_116 )
{
unsigned long V_27 ;
struct V_111 * V_13 = (struct V_111 * ) V_112 ;
T_5 V_71 ;
T_5 V_93 ;
int V_117 ;
int V_7 ;
unsigned long V_118 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_119 != V_120 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_17 ;
}
if ( V_56 == V_121 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_119 = V_122 ;
if ( V_116 )
F_61 ( & V_71 , & V_93 ) ;
else {
V_71 = 0 ;
V_93 = 0 ;
}
V_7 = - V_16 ;
for ( V_117 = 0 ; V_117 <= V_123 ; V_117 ++ ) {
F_66 ( V_71 , V_93 ) ;
F_16 ( & V_28 , V_27 ) ;
if ( F_30 ( & V_51 ) ) {
V_118 = V_26 + V_32 * V_33 ;
while ( F_20 ( V_26 , V_118 ) )
F_44 () ;
F_15 ( & V_28 , V_27 ) ;
continue;
}
while ( V_51 . V_37 != V_74 &&
V_51 . V_37 != V_47 )
F_44 () ;
F_15 ( & V_28 , V_27 ) ;
if ( V_51 . V_37 == V_74 &&
V_13 -> V_115 . V_75 == 0x20 ) {
if ( V_116 ) {
V_94 = V_13 -> V_94 ;
V_95 = V_13 -> V_95 ;
} else {
V_94 = 0 ;
V_95 = 0 ;
}
F_16 ( & V_28 , V_27 ) ;
F_59 () ;
F_15 ( & V_28 , V_27 ) ;
V_7 = 0 ;
break;
}
}
V_119 = V_120 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
int
F_67 ( void )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_56 != V_57 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_56 = V_124 ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_63 ( 0 ) ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 == 0 )
V_56 = V_121 ;
else
V_56 = V_57 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
int
F_68 ( void )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_56 != V_121 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_56 = V_125 ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_63 ( 1 ) ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 == 0 )
V_56 = V_57 ;
else
V_56 = V_121 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static void F_69 ( struct V_81 V_81 ,
unsigned int V_82 , unsigned long V_83 )
{
T_3 V_84 ;
F_40 ( V_86 ) ;
V_84 = V_82 & 0xfffffff8 ;
if ( V_84 == 0 )
return;
if ( V_84 != ( T_3 ) ( V_70 ) V_112 )
F_70 ( L_1 ,
V_84 ) ;
F_41 ( & V_28 ) ;
if ( V_29 == V_30 ) {
V_51 . V_37 = V_74 ;
V_29 = V_31 ;
}
F_42 ( & V_28 ) ;
}
static void
F_71 ( unsigned long V_3 )
{
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_29 == V_30 ) {
V_51 . V_37 = V_47 ;
V_29 = V_31 ;
}
F_16 ( & V_28 , V_27 ) ;
}
static int
F_72 ( void )
{
struct V_111 * V_13 ;
unsigned long V_27 ;
int V_117 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_7 = F_73 ( V_126 , F_69 ) ;
if ( V_7 ) {
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
for ( V_117 = 0 ; V_117 <= V_127 ; V_117 ++ ) {
F_66 ( 0 , 0 ) ;
V_13 = (struct V_111 * ) V_51 . V_13 ;
V_7 = F_6 ( V_51 . V_12 , V_13 ) ;
if ( V_7 == - V_16 )
break;
V_51 . V_37 = V_45 ;
V_29 = V_30 ;
F_10 ( V_46 * V_33 ,
F_71 , 0 ) ;
F_16 ( & V_28 , V_27 ) ;
F_74 ( V_128 ) ;
F_44 () ;
F_75 ( V_128 ) ;
F_15 ( & V_28 , V_27 ) ;
F_12 ( & V_24 ) ;
if ( V_51 . V_37 == V_74 &&
V_13 -> V_115 . V_75 == 0x20 ) {
V_7 = 0 ;
break;
} else
V_7 = - V_17 ;
}
F_76 ( V_126 , F_69 ) ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int
F_77 ( struct V_129 * V_130 , unsigned long V_131 , void * V_132 )
{
F_67 () ;
return V_133 ;
}
static void F_78 ( enum F_78 F_78 , int V_134 )
{
struct V_66 * V_67 ;
unsigned long V_27 ;
if ( ! V_134 ) {
F_15 ( & V_28 , V_27 ) ;
F_19 (reg, &sclp_reg_list, list)
V_67 -> V_107 = 0 ;
F_16 ( & V_28 , V_27 ) ;
}
do {
F_15 ( & V_28 , V_27 ) ;
F_19 (reg, &sclp_reg_list, list) {
if ( V_134 && V_67 -> V_107 )
goto V_135;
if ( ! V_134 && ! V_67 -> V_107 )
goto V_135;
}
F_16 ( & V_28 , V_27 ) ;
return;
V_135:
F_16 ( & V_28 , V_27 ) ;
if ( V_67 -> V_136 )
V_67 -> V_136 ( V_67 , F_78 ) ;
V_67 -> V_107 = V_134 ? 0 : 1 ;
} while ( 1 );
}
static int F_79 ( struct V_137 * V_138 )
{
unsigned long V_27 ;
int V_7 ;
F_78 ( V_139 , 0 ) ;
F_15 ( & V_28 , V_27 ) ;
V_52 = V_140 ;
F_16 ( & V_28 , V_27 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_41 = F_1 ;
V_50 . V_37 = V_114 ;
F_80 ( & V_4 ) ;
V_7 = F_30 ( & V_50 ) ;
if ( V_7 == 0 )
F_81 ( & V_4 ) ;
else if ( V_7 != - V_60 )
goto V_141;
V_7 = F_67 () ;
if ( V_7 )
goto V_141;
return 0 ;
V_141:
F_15 ( & V_28 , V_27 ) ;
V_52 = V_53 ;
F_16 ( & V_28 , V_27 ) ;
F_78 ( V_142 , 1 ) ;
return V_7 ;
}
static int F_82 ( enum F_78 V_131 )
{
unsigned long V_27 ;
int V_7 ;
V_7 = F_68 () ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_52 = V_53 ;
F_16 ( & V_28 , V_27 ) ;
F_78 ( V_131 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_137 * V_138 )
{
return F_82 ( V_142 ) ;
}
static int F_84 ( struct V_137 * V_138 )
{
return F_82 ( V_143 ) ;
}
static T_7 F_85 ( struct V_144 * V_138 , char * V_145 )
{
return sprintf ( V_145 , L_2 , V_9 ) ;
}
static T_7 F_86 ( struct V_144 * V_138 , char * V_145 )
{
return sprintf ( V_145 , L_2 , V_11 ) ;
}
static T_7 F_87 ( struct V_144 * V_138 , char * V_145 )
{
return sprintf ( V_145 , L_3 , V_146 ) ;
}
static int
F_62 ( void )
{
unsigned long V_27 ;
int V_7 = 0 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_54 != V_147 )
goto V_148;
V_54 = V_149 ;
F_88 ( & V_23 ) ;
F_88 ( & V_108 ) ;
F_9 ( & V_150 . V_22 , & V_108 ) ;
F_89 ( & V_24 ) ;
F_89 ( & V_43 ) ;
V_43 . F_11 = F_24 ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_72 () ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 )
goto V_151;
V_7 = F_90 ( & V_152 ) ;
if ( V_7 )
goto V_151;
V_7 = F_73 ( V_126 , F_39 ) ;
if ( V_7 )
goto V_153;
V_54 = V_55 ;
F_16 ( & V_28 , V_27 ) ;
F_74 ( V_128 ) ;
F_63 ( 1 ) ;
return 0 ;
V_153:
F_91 ( & V_152 ) ;
V_151:
V_54 = V_147 ;
V_148:
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int F_92 ( struct V_129 * V_154 ,
unsigned long V_131 , void * V_3 )
{
if ( V_52 == V_140 )
F_82 ( V_142 ) ;
return V_155 ;
}
static T_1 int F_93 ( void )
{
int V_7 ;
V_7 = F_94 ( & V_156 ) ;
if ( V_7 )
return V_7 ;
V_157 = F_95 ( L_4 , - 1 , NULL , 0 ) ;
V_7 = F_96 ( V_157 ) ;
if ( V_7 )
goto V_158;
V_7 = F_97 ( & V_159 ,
& V_160 ) ;
if ( V_7 )
goto V_161;
return F_62 () ;
V_161:
F_98 ( V_157 ) ;
V_158:
F_99 ( & V_156 ) ;
return V_7 ;
}
