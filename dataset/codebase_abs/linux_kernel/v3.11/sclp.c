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
static int
F_18 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_29 != V_31 )
return 0 ;
F_12 ( & V_24 ) ;
V_7 = F_6 ( V_2 -> V_12 , V_2 -> V_13 ) ;
V_2 -> V_34 ++ ;
if ( V_7 == 0 ) {
V_2 -> V_35 = V_36 ;
V_29 = V_30 ;
F_10 ( V_37 * V_33 ,
F_14 , 1 ) ;
return 0 ;
} else if ( V_7 == - V_17 ) {
F_10 ( V_32 * V_33 ,
F_14 , 0 ) ;
return 0 ;
}
V_2 -> V_35 = V_38 ;
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
while ( ! F_19 ( & V_23 ) ) {
V_2 = F_20 ( V_23 . V_39 , struct V_1 , V_22 ) ;
if ( ! V_2 -> V_13 )
goto V_40;
V_7 = F_18 ( V_2 ) ;
if ( V_7 == 0 )
break;
if ( V_2 -> V_34 > 1 ) {
F_10 ( V_32 * V_33 ,
F_14 , 0 ) ;
break;
}
V_40:
F_21 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_41 ) {
F_16 ( & V_28 , V_27 ) ;
V_2 -> V_41 ( V_2 , V_2 -> V_42 ) ;
F_15 ( & V_28 , V_27 ) ;
}
}
F_16 ( & V_28 , V_27 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_2 == & V_43 || V_2 == & V_44 )
return 1 ;
if ( V_45 != V_46 )
return 0 ;
if ( V_47 != V_48 )
return 0 ;
if ( V_49 != V_50 )
return 0 ;
return 1 ;
}
int
F_23 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( ! F_22 ( V_2 ) ) {
F_16 ( & V_28 , V_27 ) ;
return - V_16 ;
}
V_2 -> V_35 = V_51 ;
V_2 -> V_34 = 0 ;
F_24 ( & V_2 -> V_22 , & V_23 ) ;
V_7 = 0 ;
if ( V_29 == V_31 &&
V_2 -> V_22 . V_52 == & V_23 ) {
if ( ! V_2 -> V_13 ) {
F_21 ( & V_2 -> V_22 ) ;
V_7 = - V_53 ;
goto V_54;
}
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
F_21 ( & V_2 -> V_22 ) ;
}
V_54:
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int
F_25 ( struct V_55 * V_13 )
{
unsigned long V_27 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_62 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_7 = 0 ;
for ( V_62 = sizeof( struct V_55 ) ; V_62 < V_13 -> V_63 ;
V_62 += V_57 -> V_63 ) {
V_57 = (struct V_56 * ) ( ( V_64 ) V_13 + V_62 ) ;
if ( V_57 -> V_63 == 0 )
break;
V_61 = NULL ;
F_26 (l, &sclp_reg_list) {
V_61 = F_20 ( V_59 , struct V_60 , V_22 ) ;
if ( V_61 -> V_65 & ( 1 << ( 32 - V_57 -> type ) ) )
break;
else
V_61 = NULL ;
}
if ( V_61 && V_61 -> V_66 ) {
F_16 ( & V_28 , V_27 ) ;
V_61 -> V_66 ( V_57 ) ;
F_15 ( & V_28 , V_27 ) ;
} else if ( V_61 == NULL )
V_7 = - V_67 ;
}
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static void
F_27 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_27 ;
struct V_55 * V_13 ;
V_13 = (struct V_55 * ) V_2 -> V_13 ;
if ( V_2 -> V_35 == V_68 && ( V_13 -> V_69 == 0x20 ||
V_13 -> V_69 == 0x220 ) )
F_25 ( V_13 ) ;
F_15 ( & V_28 , V_27 ) ;
V_18 = V_19 ;
F_16 ( & V_28 , V_27 ) ;
}
static void F_8 ( void )
{
struct V_55 * V_13 ;
V_13 = (struct V_55 * ) V_70 ;
F_28 ( V_13 ) ;
memset ( & V_21 , 0 , sizeof( struct V_1 ) ) ;
V_21 . V_12 = V_71 ;
V_21 . V_35 = V_51 ;
V_21 . V_34 = 0 ;
V_21 . V_41 = F_27 ;
V_21 . V_13 = V_13 ;
V_13 -> V_63 = V_72 ;
V_13 -> V_73 = 0 ;
V_13 -> V_74 [ 2 ] = 0x80 ;
}
static inline struct V_1 *
F_29 ( T_3 V_13 )
{
struct V_58 * V_59 ;
struct V_1 * V_2 ;
F_26 (l, &sclp_req_queue) {
V_2 = F_20 ( V_59 , struct V_1 , V_22 ) ;
if ( V_13 == ( T_3 ) ( V_64 ) V_2 -> V_13 )
return V_2 ;
}
return NULL ;
}
static void F_30 ( struct V_75 V_75 ,
unsigned int V_76 , unsigned long V_77 )
{
struct V_1 * V_2 ;
T_3 V_78 ;
T_3 V_79 ;
F_31 ( V_80 ) ;
F_32 ( & V_28 ) ;
V_78 = V_76 & 0xfffffff8 ;
V_79 = V_76 & 0x3 ;
if ( V_78 ) {
F_12 ( & V_24 ) ;
V_29 = V_81 ;
V_2 = F_29 ( V_78 ) ;
if ( V_2 ) {
F_21 ( & V_2 -> V_22 ) ;
V_2 -> V_35 = V_68 ;
if ( V_2 -> V_41 ) {
F_33 ( & V_28 ) ;
V_2 -> V_41 ( V_2 , V_2 -> V_42 ) ;
F_32 ( & V_28 ) ;
}
}
V_29 = V_31 ;
}
if ( V_79 &&
V_49 == V_50 )
F_7 () ;
F_33 ( & V_28 ) ;
F_17 () ;
}
static inline T_4
F_34 ( unsigned long V_26 )
{
return ( T_4 ) ( V_26 / V_33 ) << 32 ;
}
void
F_35 ( void )
{
unsigned long long V_82 ;
unsigned long V_27 ;
unsigned long V_83 , V_84 ;
T_4 V_85 ;
int V_86 ;
V_85 = 0 ;
if ( F_36 ( & V_24 ) ) {
V_85 = F_37 () +
F_34 ( V_24 . V_25 -
V_26 ) ;
}
F_38 ( V_27 ) ;
V_86 = F_39 () ;
if ( ! V_86 )
F_40 () ;
V_82 = F_41 () ;
F_42 () ;
F_43 ( V_83 , 0 , 0 ) ;
V_84 = V_83 ;
V_84 &= 0xffff00a0 ;
V_84 |= 0x00000200 ;
F_44 ( V_84 , 0 , 0 ) ;
F_45 ( 0x01 ) ;
while ( V_29 != V_31 ) {
if ( F_36 ( & V_24 ) &&
F_37 () > V_85 &&
F_12 ( & V_24 ) )
V_24 . F_11 ( V_24 . V_3 ) ;
F_46 () ;
}
F_47 () ;
F_44 ( V_83 , 0 , 0 ) ;
if ( ! V_86 )
F_48 () ;
F_49 ( V_82 ) ;
F_50 ( V_27 ) ;
}
static void
F_51 ( void )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_27 ;
T_5 V_65 ;
T_5 V_87 ;
do {
F_15 ( & V_28 , V_27 ) ;
V_61 = NULL ;
F_26 (l, &sclp_reg_list) {
V_61 = F_20 ( V_59 , struct V_60 , V_22 ) ;
V_65 = V_61 -> V_87 & V_88 ;
V_87 = V_61 -> V_65 & V_89 ;
if ( V_61 -> V_88 != V_65 ||
V_61 -> V_89 != V_87 ) {
V_61 -> V_88 = V_65 ;
V_61 -> V_89 = V_87 ;
break;
} else
V_61 = NULL ;
}
F_16 ( & V_28 , V_27 ) ;
if ( V_61 && V_61 -> V_90 )
V_61 -> V_90 ( V_61 ) ;
} while ( V_61 );
}
static void
F_52 ( struct V_56 * V_57 )
{
unsigned long V_27 ;
struct V_91 * V_92 ;
V_92 = (struct V_91 * ) V_57 ;
if ( V_92 -> V_93 != sizeof( T_5 ) )
return;
F_15 ( & V_28 , V_27 ) ;
if ( V_92 -> V_94 )
V_88 = V_92 -> V_88 ;
if ( V_92 -> V_95 )
V_89 = V_92 -> V_89 ;
F_16 ( & V_28 , V_27 ) ;
if ( V_92 -> V_96 )
V_97 = V_92 -> V_98 ;
F_51 () ;
}
static inline void
F_53 ( T_5 * V_65 , T_5 * V_87 )
{
struct V_58 * V_59 ;
struct V_60 * V_99 ;
* V_65 = 0 ;
* V_87 = 0 ;
F_26 (l, &sclp_reg_list) {
V_99 = F_20 ( V_59 , struct V_60 , V_22 ) ;
* V_65 |= V_99 -> V_65 ;
* V_87 |= V_99 -> V_87 ;
}
}
int
V_60 ( struct V_60 * V_61 )
{
unsigned long V_27 ;
T_5 V_65 ;
T_5 V_87 ;
int V_7 ;
V_7 = F_54 () ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 , V_27 ) ;
F_53 ( & V_65 , & V_87 ) ;
if ( V_61 -> V_65 & V_65 || V_61 -> V_87 & V_87 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_17 ;
}
V_61 -> V_88 = 0 ;
V_61 -> V_89 = 0 ;
V_61 -> V_100 = 0 ;
F_9 ( & V_61 -> V_22 , & V_101 ) ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_55 ( 1 ) ;
if ( V_7 ) {
F_15 ( & V_28 , V_27 ) ;
F_21 ( & V_61 -> V_22 ) ;
F_16 ( & V_28 , V_27 ) ;
}
return V_7 ;
}
void
F_56 ( struct V_60 * V_61 )
{
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
F_21 ( & V_61 -> V_22 ) ;
F_16 ( & V_28 , V_27 ) ;
F_55 ( 1 ) ;
}
int
F_57 ( struct V_55 * V_13 )
{
struct V_56 * V_57 ;
int V_102 ;
T_6 V_103 ;
V_57 = (struct V_56 * ) ( V_13 + 1 ) ;
V_102 = 0 ;
V_103 = V_13 -> V_63 - sizeof( struct V_55 ) ;
while ( V_103 > 0 ) {
V_103 -= V_57 -> V_63 ;
if ( V_57 -> V_27 & 0x80 ) {
V_13 -> V_63 -= V_57 -> V_63 ;
memcpy ( V_57 , ( void * ) ( ( V_64 ) V_57 + V_57 -> V_63 ) ,
V_103 ) ;
} else {
V_102 ++ ;
V_57 = (struct V_56 * )
( ( V_64 ) V_57 + V_57 -> V_63 ) ;
}
}
return V_102 ;
}
static inline void
F_58 ( T_3 V_65 , T_3 V_87 )
{
struct V_104 * V_13 ;
V_13 = (struct V_104 * ) V_105 ;
F_28 ( V_13 ) ;
memset ( & V_44 , 0 , sizeof( struct V_1 ) ) ;
V_44 . V_12 = V_106 ;
V_44 . V_35 = V_107 ;
V_44 . V_34 = 0 ;
V_44 . V_41 = NULL ;
V_44 . V_42 = NULL ;
V_44 . V_13 = V_13 ;
V_13 -> V_108 . V_63 = sizeof( struct V_104 ) ;
V_13 -> V_93 = sizeof( T_5 ) ;
V_13 -> V_65 = V_65 ;
V_13 -> V_87 = V_87 ;
V_13 -> V_88 = 0 ;
V_13 -> V_89 = 0 ;
}
static int
F_55 ( int V_109 )
{
unsigned long V_27 ;
struct V_104 * V_13 = (struct V_104 * ) V_105 ;
T_5 V_65 ;
T_5 V_87 ;
int V_110 ;
int V_7 ;
unsigned long V_111 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_112 != V_113 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_17 ;
}
if ( V_49 == V_114 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_112 = V_115 ;
if ( V_109 )
F_53 ( & V_65 , & V_87 ) ;
else {
V_65 = 0 ;
V_87 = 0 ;
}
V_7 = - V_16 ;
for ( V_110 = 0 ; V_110 <= V_116 ; V_110 ++ ) {
F_58 ( V_65 , V_87 ) ;
F_16 ( & V_28 , V_27 ) ;
if ( F_23 ( & V_44 ) ) {
V_111 = V_26 + V_32 * V_33 ;
while ( F_59 ( V_26 , V_111 ) )
F_35 () ;
F_15 ( & V_28 , V_27 ) ;
continue;
}
while ( V_44 . V_35 != V_68 &&
V_44 . V_35 != V_38 )
F_35 () ;
F_15 ( & V_28 , V_27 ) ;
if ( V_44 . V_35 == V_68 &&
V_13 -> V_108 . V_69 == 0x20 ) {
if ( V_109 ) {
V_88 = V_13 -> V_88 ;
V_89 = V_13 -> V_89 ;
} else {
V_88 = 0 ;
V_89 = 0 ;
}
F_16 ( & V_28 , V_27 ) ;
F_51 () ;
F_15 ( & V_28 , V_27 ) ;
V_7 = 0 ;
break;
}
}
V_112 = V_113 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
int
F_60 ( void )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_49 != V_50 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_49 = V_117 ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_55 ( 0 ) ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 == 0 )
V_49 = V_114 ;
else
V_49 = V_50 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
int
F_61 ( void )
{
unsigned long V_27 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_49 != V_114 ) {
F_16 ( & V_28 , V_27 ) ;
return - V_15 ;
}
V_49 = V_118 ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_55 ( 1 ) ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 == 0 )
V_49 = V_50 ;
else
V_49 = V_114 ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static void F_62 ( struct V_75 V_75 ,
unsigned int V_76 , unsigned long V_77 )
{
T_3 V_78 ;
F_31 ( V_80 ) ;
V_78 = V_76 & 0xfffffff8 ;
if ( V_78 == 0 )
return;
if ( V_78 != ( T_3 ) ( V_64 ) V_105 )
F_63 ( L_1 ,
V_78 ) ;
F_32 ( & V_28 ) ;
if ( V_29 == V_30 ) {
V_44 . V_35 = V_68 ;
V_29 = V_31 ;
}
F_33 ( & V_28 ) ;
}
static void
F_64 ( unsigned long V_3 )
{
unsigned long V_27 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_29 == V_30 ) {
V_44 . V_35 = V_38 ;
V_29 = V_31 ;
}
F_16 ( & V_28 , V_27 ) ;
}
static int
F_65 ( void )
{
struct V_104 * V_13 ;
unsigned long V_27 ;
int V_110 ;
int V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_7 = F_66 ( 0x2401 , F_62 ) ;
if ( V_7 ) {
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
for ( V_110 = 0 ; V_110 <= V_119 ; V_110 ++ ) {
F_58 ( 0 , 0 ) ;
V_13 = (struct V_104 * ) V_44 . V_13 ;
V_7 = F_6 ( V_44 . V_12 , V_13 ) ;
if ( V_7 == - V_16 )
break;
V_44 . V_35 = V_36 ;
V_29 = V_30 ;
F_10 ( V_37 * V_33 ,
F_64 , 0 ) ;
F_16 ( & V_28 , V_27 ) ;
F_67 () ;
F_35 () ;
F_68 () ;
F_15 ( & V_28 , V_27 ) ;
F_12 ( & V_24 ) ;
if ( V_44 . V_35 == V_68 &&
V_13 -> V_108 . V_69 == 0x20 ) {
V_7 = 0 ;
break;
} else
V_7 = - V_17 ;
}
F_69 ( 0x2401 , F_62 ) ;
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int
F_70 ( struct V_120 * V_121 , unsigned long V_122 , void * V_123 )
{
F_60 () ;
return V_124 ;
}
static void F_71 ( enum F_71 F_71 , int V_125 )
{
struct V_60 * V_61 ;
unsigned long V_27 ;
if ( ! V_125 ) {
F_15 ( & V_28 , V_27 ) ;
F_72 (reg, &sclp_reg_list, list)
V_61 -> V_100 = 0 ;
F_16 ( & V_28 , V_27 ) ;
}
do {
F_15 ( & V_28 , V_27 ) ;
F_72 (reg, &sclp_reg_list, list) {
if ( V_125 && V_61 -> V_100 )
goto V_126;
if ( ! V_125 && ! V_61 -> V_100 )
goto V_126;
}
F_16 ( & V_28 , V_27 ) ;
return;
V_126:
F_16 ( & V_28 , V_27 ) ;
if ( V_61 -> V_127 )
V_61 -> V_127 ( V_61 , F_71 ) ;
V_61 -> V_100 = V_125 ? 0 : 1 ;
} while ( 1 );
}
static int F_73 ( struct V_128 * V_129 )
{
unsigned long V_27 ;
int V_7 ;
F_71 ( V_130 , 0 ) ;
F_15 ( & V_28 , V_27 ) ;
V_45 = V_131 ;
F_16 ( & V_28 , V_27 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_41 = F_1 ;
V_43 . V_35 = V_107 ;
F_74 ( & V_4 ) ;
V_7 = F_23 ( & V_43 ) ;
if ( V_7 == 0 )
F_75 ( & V_4 ) ;
else if ( V_7 != - V_53 )
goto V_132;
V_7 = F_60 () ;
if ( V_7 )
goto V_132;
return 0 ;
V_132:
F_15 ( & V_28 , V_27 ) ;
V_45 = V_46 ;
F_16 ( & V_28 , V_27 ) ;
F_71 ( V_133 , 1 ) ;
return V_7 ;
}
static int F_76 ( enum F_71 V_122 )
{
unsigned long V_27 ;
int V_7 ;
V_7 = F_61 () ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 , V_27 ) ;
V_45 = V_46 ;
F_16 ( & V_28 , V_27 ) ;
F_71 ( V_122 , 0 ) ;
return 0 ;
}
static int F_77 ( struct V_128 * V_129 )
{
return F_76 ( V_133 ) ;
}
static int F_78 ( struct V_128 * V_129 )
{
return F_76 ( V_134 ) ;
}
static T_7 F_79 ( struct V_135 * V_129 , char * V_136 )
{
return sprintf ( V_136 , L_2 , V_9 ) ;
}
static T_7 F_80 ( struct V_135 * V_129 , char * V_136 )
{
return sprintf ( V_136 , L_2 , V_11 ) ;
}
static T_7 F_81 ( struct V_135 * V_129 , char * V_136 )
{
return sprintf ( V_136 , L_3 , V_137 ) ;
}
static int
F_54 ( void )
{
unsigned long V_27 ;
int V_7 = 0 ;
F_15 ( & V_28 , V_27 ) ;
if ( V_47 != V_138 )
goto V_139;
V_47 = V_140 ;
F_82 ( & V_23 ) ;
F_82 ( & V_101 ) ;
F_9 ( & V_141 . V_22 , & V_101 ) ;
F_83 ( & V_24 ) ;
F_16 ( & V_28 , V_27 ) ;
V_7 = F_65 () ;
F_15 ( & V_28 , V_27 ) ;
if ( V_7 )
goto V_142;
V_7 = F_84 ( & V_143 ) ;
if ( V_7 )
goto V_142;
V_7 = F_66 ( 0x2401 , F_30 ) ;
if ( V_7 )
goto V_144;
V_47 = V_48 ;
F_16 ( & V_28 , V_27 ) ;
F_67 () ;
F_55 ( 1 ) ;
return 0 ;
V_144:
F_85 ( & V_143 ) ;
V_142:
V_47 = V_138 ;
V_139:
F_16 ( & V_28 , V_27 ) ;
return V_7 ;
}
static int F_86 ( struct V_120 * V_145 ,
unsigned long V_122 , void * V_3 )
{
if ( V_45 == V_131 )
F_76 ( V_133 ) ;
return V_146 ;
}
static T_1 int F_87 ( void )
{
int V_7 ;
V_7 = F_88 ( & V_147 ) ;
if ( V_7 )
return V_7 ;
V_148 = F_89 ( L_4 , - 1 , NULL , 0 ) ;
V_7 = F_90 ( V_148 ) ;
if ( V_7 )
goto V_149;
V_7 = F_91 ( & V_150 ,
& V_151 ) ;
if ( V_7 )
goto V_152;
return F_54 () ;
V_152:
F_92 ( V_148 ) ;
V_149:
F_93 ( & V_147 ) ;
return V_7 ;
}
