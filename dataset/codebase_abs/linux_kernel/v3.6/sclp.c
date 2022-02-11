static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( & V_4 ) ;
}
int
F_3 ( T_1 V_5 , void * V_6 )
{
int V_7 ;
asm volatile(
" .insn rre,0xb2200000,%1,%2\n"
" ipm %0\n"
" srl %0,28"
: "=&d" (cc) : "d" (command), "a" (__pa(sccb))
: "cc", "memory");
if ( V_7 == 3 )
return - V_8 ;
if ( V_7 == 2 )
return - V_9 ;
return 0 ;
}
static void
F_4 ( void )
{
if ( V_10 == V_11 ) {
V_10 = V_12 ;
F_5 () ;
F_6 ( & V_13 . V_14 , & V_15 ) ;
}
}
static inline void
F_7 ( unsigned long time , void (* F_8)( unsigned long ) ,
unsigned long V_3 )
{
F_9 ( & V_16 ) ;
V_16 . F_8 = F_8 ;
V_16 . V_3 = V_3 ;
V_16 . V_17 = V_18 + time ;
F_10 ( & V_16 ) ;
}
static void
F_11 ( unsigned long V_3 )
{
unsigned long V_19 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_3 ) {
if ( V_21 == V_22 ) {
F_4 () ;
V_21 = V_23 ;
}
} else {
F_7 ( V_24 * V_25 ,
F_11 , 0 ) ;
}
F_13 ( & V_20 , V_19 ) ;
F_14 () ;
}
static int
F_15 ( struct V_1 * V_2 )
{
int V_26 ;
if ( V_21 != V_23 )
return 0 ;
F_9 ( & V_16 ) ;
V_26 = F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_27 ++ ;
if ( V_26 == 0 ) {
V_2 -> V_28 = V_29 ;
V_21 = V_22 ;
F_7 ( V_30 * V_25 ,
F_11 , 1 ) ;
return 0 ;
} else if ( V_26 == - V_9 ) {
F_7 ( V_24 * V_25 ,
F_11 , 0 ) ;
return 0 ;
}
V_2 -> V_28 = V_31 ;
return V_26 ;
}
static void
F_14 ( void )
{
struct V_1 * V_2 ;
int V_26 ;
unsigned long V_19 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_21 != V_23 ) {
F_13 ( & V_20 , V_19 ) ;
return;
}
F_9 ( & V_16 ) ;
while ( ! F_16 ( & V_15 ) ) {
V_2 = F_17 ( V_15 . V_32 , struct V_1 , V_14 ) ;
if ( ! V_2 -> V_6 )
goto V_33;
V_26 = F_15 ( V_2 ) ;
if ( V_26 == 0 )
break;
if ( V_2 -> V_27 > 1 ) {
F_7 ( V_24 * V_25 ,
F_11 , 0 ) ;
break;
}
V_33:
F_18 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_34 ) {
F_13 ( & V_20 , V_19 ) ;
V_2 -> V_34 ( V_2 , V_2 -> V_35 ) ;
F_12 ( & V_20 , V_19 ) ;
}
}
F_13 ( & V_20 , V_19 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( V_2 == & V_36 || V_2 == & V_37 )
return 1 ;
if ( V_38 != V_39 )
return 0 ;
if ( V_40 != V_41 )
return 0 ;
if ( V_42 != V_43 )
return 0 ;
return 1 ;
}
int
F_20 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
int V_26 ;
F_12 ( & V_20 , V_19 ) ;
if ( ! F_19 ( V_2 ) ) {
F_13 ( & V_20 , V_19 ) ;
return - V_8 ;
}
V_2 -> V_28 = V_44 ;
V_2 -> V_27 = 0 ;
F_21 ( & V_2 -> V_14 , & V_15 ) ;
V_26 = 0 ;
if ( V_21 == V_23 &&
V_2 -> V_14 . V_45 == & V_15 ) {
if ( ! V_2 -> V_6 ) {
F_18 ( & V_2 -> V_14 ) ;
V_26 = - V_46 ;
goto V_47;
}
V_26 = F_15 ( V_2 ) ;
if ( V_26 )
F_18 ( & V_2 -> V_14 ) ;
}
V_47:
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
static int
F_22 ( struct V_48 * V_6 )
{
unsigned long V_19 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_55 ;
int V_26 ;
F_12 ( & V_20 , V_19 ) ;
V_26 = 0 ;
for ( V_55 = sizeof( struct V_48 ) ; V_55 < V_6 -> V_56 ;
V_55 += V_50 -> V_56 ) {
V_50 = (struct V_49 * ) ( ( V_57 ) V_6 + V_55 ) ;
if ( V_50 -> V_56 == 0 )
break;
V_54 = NULL ;
F_23 (l, &sclp_reg_list) {
V_54 = F_17 ( V_52 , struct V_53 , V_14 ) ;
if ( V_54 -> V_58 & ( 1 << ( 32 - V_50 -> type ) ) )
break;
else
V_54 = NULL ;
}
if ( V_54 && V_54 -> V_59 ) {
F_13 ( & V_20 , V_19 ) ;
V_54 -> V_59 ( V_50 ) ;
F_12 ( & V_20 , V_19 ) ;
} else if ( V_54 == NULL )
V_26 = - V_60 ;
}
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
static void
F_24 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_19 ;
struct V_48 * V_6 ;
V_6 = (struct V_48 * ) V_2 -> V_6 ;
if ( V_2 -> V_28 == V_61 && ( V_6 -> V_62 == 0x20 ||
V_6 -> V_62 == 0x220 ) )
F_22 ( V_6 ) ;
F_12 ( & V_20 , V_19 ) ;
V_10 = V_11 ;
F_13 ( & V_20 , V_19 ) ;
}
static void F_5 ( void )
{
struct V_48 * V_6 ;
V_6 = (struct V_48 * ) V_63 ;
F_25 ( V_6 ) ;
memset ( & V_13 , 0 , sizeof( struct V_1 ) ) ;
V_13 . V_5 = V_64 ;
V_13 . V_28 = V_44 ;
V_13 . V_27 = 0 ;
V_13 . V_34 = F_24 ;
V_13 . V_6 = V_6 ;
V_6 -> V_56 = V_65 ;
V_6 -> V_66 = 0 ;
V_6 -> V_67 [ 2 ] = 0x80 ;
}
static inline struct V_1 *
F_26 ( T_2 V_6 )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
F_23 (l, &sclp_req_queue) {
V_2 = F_17 ( V_52 , struct V_1 , V_14 ) ;
if ( V_6 == ( T_2 ) ( V_57 ) V_2 -> V_6 )
return V_2 ;
}
return NULL ;
}
static void F_27 ( struct V_68 V_68 ,
unsigned int V_69 , unsigned long V_70 )
{
struct V_1 * V_2 ;
T_2 V_71 ;
T_2 V_72 ;
F_28 ( F_29 () ) . V_73 [ V_74 ] ++ ;
F_30 ( & V_20 ) ;
V_71 = V_69 & 0xfffffff8 ;
V_72 = V_69 & 0x3 ;
if ( V_71 ) {
F_9 ( & V_16 ) ;
V_21 = V_75 ;
V_2 = F_26 ( V_71 ) ;
if ( V_2 ) {
F_18 ( & V_2 -> V_14 ) ;
V_2 -> V_28 = V_61 ;
if ( V_2 -> V_34 ) {
F_31 ( & V_20 ) ;
V_2 -> V_34 ( V_2 , V_2 -> V_35 ) ;
F_30 ( & V_20 ) ;
}
}
V_21 = V_23 ;
}
if ( V_72 &&
V_42 == V_43 )
F_4 () ;
F_31 ( & V_20 ) ;
F_14 () ;
}
static inline T_3
F_32 ( unsigned long V_18 )
{
return ( T_3 ) ( V_18 / V_25 ) << 32 ;
}
void
F_33 ( void )
{
unsigned long long V_76 ;
unsigned long V_19 ;
unsigned long V_77 , V_78 ;
T_3 V_79 ;
int V_80 ;
V_79 = 0 ;
if ( F_34 ( & V_16 ) ) {
V_79 = F_35 () +
F_32 ( V_16 . V_17 -
V_18 ) ;
}
F_36 ( V_19 ) ;
V_80 = F_37 () ;
if ( ! V_80 )
F_38 () ;
V_76 = F_39 () ;
F_40 () ;
F_41 ( V_77 , 0 , 0 ) ;
V_78 = V_77 ;
V_78 &= 0xffff00a0 ;
V_78 |= 0x00000200 ;
F_42 ( V_78 , 0 , 0 ) ;
F_43 ( 0x01 ) ;
while ( V_21 != V_23 ) {
if ( F_34 ( & V_16 ) &&
F_35 () > V_79 &&
F_9 ( & V_16 ) )
V_16 . F_8 ( V_16 . V_3 ) ;
F_44 () ;
}
F_45 () ;
F_42 ( V_77 , 0 , 0 ) ;
if ( ! V_80 )
F_46 () ;
F_47 ( V_76 ) ;
F_48 ( V_19 ) ;
}
static void
F_49 ( void )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
unsigned long V_19 ;
T_4 V_58 ;
T_4 V_81 ;
do {
F_12 ( & V_20 , V_19 ) ;
V_54 = NULL ;
F_23 (l, &sclp_reg_list) {
V_54 = F_17 ( V_52 , struct V_53 , V_14 ) ;
V_58 = V_54 -> V_81 & V_82 ;
V_81 = V_54 -> V_58 & V_83 ;
if ( V_54 -> V_82 != V_58 ||
V_54 -> V_83 != V_81 ) {
V_54 -> V_82 = V_58 ;
V_54 -> V_83 = V_81 ;
break;
} else
V_54 = NULL ;
}
F_13 ( & V_20 , V_19 ) ;
if ( V_54 && V_54 -> V_84 )
V_54 -> V_84 ( V_54 ) ;
} while ( V_54 );
}
static void
F_50 ( struct V_49 * V_50 )
{
unsigned long V_19 ;
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_50 ;
if ( V_86 -> V_87 != sizeof( T_4 ) )
return;
F_12 ( & V_20 , V_19 ) ;
if ( V_86 -> V_88 )
V_82 = V_86 -> V_82 ;
if ( V_86 -> V_89 )
V_83 = V_86 -> V_83 ;
F_13 ( & V_20 , V_19 ) ;
if ( V_86 -> V_90 )
V_91 = V_86 -> V_92 ;
F_49 () ;
}
static inline void
F_51 ( T_4 * V_58 , T_4 * V_81 )
{
struct V_51 * V_52 ;
struct V_53 * V_93 ;
* V_58 = 0 ;
* V_81 = 0 ;
F_23 (l, &sclp_reg_list) {
V_93 = F_17 ( V_52 , struct V_53 , V_14 ) ;
* V_58 |= V_93 -> V_58 ;
* V_81 |= V_93 -> V_81 ;
}
}
int
V_53 ( struct V_53 * V_54 )
{
unsigned long V_19 ;
T_4 V_58 ;
T_4 V_81 ;
int V_26 ;
V_26 = F_52 () ;
if ( V_26 )
return V_26 ;
F_12 ( & V_20 , V_19 ) ;
F_51 ( & V_58 , & V_81 ) ;
if ( V_54 -> V_58 & V_58 || V_54 -> V_81 & V_81 ) {
F_13 ( & V_20 , V_19 ) ;
return - V_9 ;
}
V_54 -> V_82 = 0 ;
V_54 -> V_83 = 0 ;
V_54 -> V_94 = 0 ;
F_6 ( & V_54 -> V_14 , & V_95 ) ;
F_13 ( & V_20 , V_19 ) ;
V_26 = F_53 ( 1 ) ;
if ( V_26 ) {
F_12 ( & V_20 , V_19 ) ;
F_18 ( & V_54 -> V_14 ) ;
F_13 ( & V_20 , V_19 ) ;
}
return V_26 ;
}
void
F_54 ( struct V_53 * V_54 )
{
unsigned long V_19 ;
F_12 ( & V_20 , V_19 ) ;
F_18 ( & V_54 -> V_14 ) ;
F_13 ( & V_20 , V_19 ) ;
F_53 ( 1 ) ;
}
int
F_55 ( struct V_48 * V_6 )
{
struct V_49 * V_50 ;
int V_96 ;
T_5 V_97 ;
V_50 = (struct V_49 * ) ( V_6 + 1 ) ;
V_96 = 0 ;
V_97 = V_6 -> V_56 - sizeof( struct V_48 ) ;
while ( V_97 > 0 ) {
V_97 -= V_50 -> V_56 ;
if ( V_50 -> V_19 & 0x80 ) {
V_6 -> V_56 -= V_50 -> V_56 ;
memcpy ( V_50 , ( void * ) ( ( V_57 ) V_50 + V_50 -> V_56 ) ,
V_97 ) ;
} else {
V_96 ++ ;
V_50 = (struct V_49 * )
( ( V_57 ) V_50 + V_50 -> V_56 ) ;
}
}
return V_96 ;
}
static inline void
F_56 ( T_2 V_58 , T_2 V_81 )
{
struct V_98 * V_6 ;
V_6 = (struct V_98 * ) V_99 ;
F_25 ( V_6 ) ;
memset ( & V_37 , 0 , sizeof( struct V_1 ) ) ;
V_37 . V_5 = V_100 ;
V_37 . V_28 = V_101 ;
V_37 . V_27 = 0 ;
V_37 . V_34 = NULL ;
V_37 . V_35 = NULL ;
V_37 . V_6 = V_6 ;
V_6 -> V_102 . V_56 = sizeof( struct V_98 ) ;
V_6 -> V_87 = sizeof( T_4 ) ;
V_6 -> V_58 = V_58 ;
V_6 -> V_81 = V_81 ;
V_6 -> V_82 = 0 ;
V_6 -> V_83 = 0 ;
}
static int
F_53 ( int V_103 )
{
unsigned long V_19 ;
struct V_98 * V_6 = (struct V_98 * ) V_99 ;
T_4 V_58 ;
T_4 V_81 ;
int V_104 ;
int V_26 ;
unsigned long V_105 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_106 != V_107 ) {
F_13 ( & V_20 , V_19 ) ;
return - V_9 ;
}
if ( V_42 == V_108 ) {
F_13 ( & V_20 , V_19 ) ;
return - V_109 ;
}
V_106 = V_110 ;
if ( V_103 )
F_51 ( & V_58 , & V_81 ) ;
else {
V_58 = 0 ;
V_81 = 0 ;
}
V_26 = - V_8 ;
for ( V_104 = 0 ; V_104 <= V_111 ; V_104 ++ ) {
F_56 ( V_58 , V_81 ) ;
F_13 ( & V_20 , V_19 ) ;
if ( F_20 ( & V_37 ) ) {
V_105 = V_18 + V_24 * V_25 ;
while ( F_57 ( V_18 , V_105 ) )
F_33 () ;
F_12 ( & V_20 , V_19 ) ;
continue;
}
while ( V_37 . V_28 != V_61 &&
V_37 . V_28 != V_31 )
F_33 () ;
F_12 ( & V_20 , V_19 ) ;
if ( V_37 . V_28 == V_61 &&
V_6 -> V_102 . V_62 == 0x20 ) {
if ( V_103 ) {
V_82 = V_6 -> V_82 ;
V_83 = V_6 -> V_83 ;
} else {
V_82 = 0 ;
V_83 = 0 ;
}
F_13 ( & V_20 , V_19 ) ;
F_49 () ;
F_12 ( & V_20 , V_19 ) ;
V_26 = 0 ;
break;
}
}
V_106 = V_107 ;
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
int
F_58 ( void )
{
unsigned long V_19 ;
int V_26 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_42 != V_43 ) {
F_13 ( & V_20 , V_19 ) ;
return - V_109 ;
}
V_42 = V_112 ;
F_13 ( & V_20 , V_19 ) ;
V_26 = F_53 ( 0 ) ;
F_12 ( & V_20 , V_19 ) ;
if ( V_26 == 0 )
V_42 = V_108 ;
else
V_42 = V_43 ;
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
int
F_59 ( void )
{
unsigned long V_19 ;
int V_26 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_42 != V_108 ) {
F_13 ( & V_20 , V_19 ) ;
return - V_109 ;
}
V_42 = V_113 ;
F_13 ( & V_20 , V_19 ) ;
V_26 = F_53 ( 1 ) ;
F_12 ( & V_20 , V_19 ) ;
if ( V_26 == 0 )
V_42 = V_43 ;
else
V_42 = V_108 ;
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
static void F_60 ( struct V_68 V_68 ,
unsigned int V_69 , unsigned long V_70 )
{
T_2 V_71 ;
F_28 ( F_29 () ) . V_73 [ V_74 ] ++ ;
V_71 = V_69 & 0xfffffff8 ;
if ( V_71 == 0 )
return;
if ( V_71 != ( T_2 ) ( V_57 ) V_99 )
F_61 ( L_1 ,
V_71 ) ;
F_30 ( & V_20 ) ;
if ( V_21 == V_22 ) {
V_37 . V_28 = V_61 ;
V_21 = V_23 ;
}
F_31 ( & V_20 ) ;
}
static void
F_62 ( unsigned long V_3 )
{
unsigned long V_19 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_21 == V_22 ) {
V_37 . V_28 = V_31 ;
V_21 = V_23 ;
}
F_13 ( & V_20 , V_19 ) ;
}
static int
F_63 ( void )
{
struct V_98 * V_6 ;
unsigned long V_19 ;
int V_104 ;
int V_26 ;
F_12 ( & V_20 , V_19 ) ;
V_26 = F_64 ( 0x2401 , F_60 ) ;
if ( V_26 ) {
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
for ( V_104 = 0 ; V_104 <= V_114 ; V_104 ++ ) {
F_56 ( 0 , 0 ) ;
V_6 = (struct V_98 * ) V_37 . V_6 ;
V_26 = F_3 ( V_37 . V_5 , V_6 ) ;
if ( V_26 == - V_8 )
break;
V_37 . V_28 = V_29 ;
V_21 = V_22 ;
F_7 ( V_30 * V_25 ,
F_62 , 0 ) ;
F_13 ( & V_20 , V_19 ) ;
F_65 () ;
F_33 () ;
F_66 () ;
F_12 ( & V_20 , V_19 ) ;
F_9 ( & V_16 ) ;
if ( V_37 . V_28 == V_61 &&
V_6 -> V_102 . V_62 == 0x20 ) {
V_26 = 0 ;
break;
} else
V_26 = - V_9 ;
}
F_67 ( 0x2401 , F_60 ) ;
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
static int
F_68 ( struct V_115 * V_116 , unsigned long V_117 , void * V_118 )
{
F_58 () ;
return V_119 ;
}
static void F_69 ( enum F_69 F_69 , int V_120 )
{
struct V_53 * V_54 ;
unsigned long V_19 ;
if ( ! V_120 ) {
F_12 ( & V_20 , V_19 ) ;
F_70 (reg, &sclp_reg_list, list)
V_54 -> V_94 = 0 ;
F_13 ( & V_20 , V_19 ) ;
}
do {
F_12 ( & V_20 , V_19 ) ;
F_70 (reg, &sclp_reg_list, list) {
if ( V_120 && V_54 -> V_94 )
goto V_121;
if ( ! V_120 && ! V_54 -> V_94 )
goto V_121;
}
F_13 ( & V_20 , V_19 ) ;
return;
V_121:
F_13 ( & V_20 , V_19 ) ;
if ( V_54 -> V_122 )
V_54 -> V_122 ( V_54 , F_69 ) ;
V_54 -> V_94 = V_120 ? 0 : 1 ;
} while ( 1 );
}
static int F_71 ( struct V_123 * V_124 )
{
unsigned long V_19 ;
int V_26 ;
F_69 ( V_125 , 0 ) ;
F_12 ( & V_20 , V_19 ) ;
V_38 = V_126 ;
F_13 ( & V_20 , V_19 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_34 = F_1 ;
V_36 . V_28 = V_101 ;
F_72 ( & V_4 ) ;
V_26 = F_20 ( & V_36 ) ;
if ( V_26 == 0 )
F_73 ( & V_4 ) ;
else if ( V_26 != - V_46 )
goto V_127;
V_26 = F_58 () ;
if ( V_26 )
goto V_127;
return 0 ;
V_127:
F_12 ( & V_20 , V_19 ) ;
V_38 = V_39 ;
F_13 ( & V_20 , V_19 ) ;
F_69 ( V_128 , 1 ) ;
return V_26 ;
}
static int F_74 ( enum F_69 V_117 )
{
unsigned long V_19 ;
int V_26 ;
V_26 = F_59 () ;
if ( V_26 )
return V_26 ;
F_12 ( & V_20 , V_19 ) ;
V_38 = V_39 ;
F_13 ( & V_20 , V_19 ) ;
F_69 ( V_117 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_123 * V_124 )
{
return F_74 ( V_128 ) ;
}
static int F_76 ( struct V_123 * V_124 )
{
return F_74 ( V_129 ) ;
}
static int
F_52 ( void )
{
unsigned long V_19 ;
int V_26 = 0 ;
F_12 ( & V_20 , V_19 ) ;
if ( V_40 != V_130 )
goto V_131;
V_40 = V_132 ;
F_77 ( & V_15 ) ;
F_77 ( & V_95 ) ;
F_6 ( & V_133 . V_14 , & V_95 ) ;
F_78 ( & V_16 ) ;
F_13 ( & V_20 , V_19 ) ;
V_26 = F_63 () ;
F_12 ( & V_20 , V_19 ) ;
if ( V_26 )
goto V_134;
V_26 = F_79 ( & V_135 ) ;
if ( V_26 )
goto V_134;
V_26 = F_64 ( 0x2401 , F_27 ) ;
if ( V_26 )
goto V_136;
V_40 = V_41 ;
F_13 ( & V_20 , V_19 ) ;
F_65 () ;
F_53 ( 1 ) ;
return 0 ;
V_136:
F_80 ( & V_135 ) ;
V_134:
V_40 = V_130 ;
V_131:
F_13 ( & V_20 , V_19 ) ;
return V_26 ;
}
static int F_81 ( struct V_115 * V_137 ,
unsigned long V_117 , void * V_3 )
{
if ( V_38 == V_126 )
F_74 ( V_128 ) ;
return V_138 ;
}
static T_6 int F_82 ( void )
{
int V_26 ;
V_26 = F_83 ( & V_139 ) ;
if ( V_26 )
return V_26 ;
V_140 = F_84 ( L_2 , - 1 , NULL , 0 ) ;
V_26 = F_85 ( V_140 ) ? F_86 ( V_140 ) : 0 ;
if ( V_26 )
goto V_141;
V_26 = F_87 ( & V_142 ,
& V_143 ) ;
if ( V_26 )
goto V_144;
return F_52 () ;
V_144:
F_88 ( V_140 ) ;
V_141:
F_89 ( & V_139 ) ;
return V_26 ;
}
