static inline void F_1 ( unsigned int V_1 , int V_2 )
{
struct {
unsigned int V_1 ;
int V_2 ;
} V_3 V_4 = { V_1 , V_2 } ;
F_2 ( & V_4 , sizeof( V_4 ) ) ;
}
static inline int F_3 ( unsigned long * V_5 )
{
unsigned long V_6 ;
int V_7 = 3 ;
asm volatile (
" .insn rrf,0xb9a00000,%[mask],%[cmd],8,0\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [mask] "=d" (mask) : [cmd] "a" (1)
: "cc");
* V_5 = V_6 ;
return V_7 ;
}
static inline int F_4 ( void * V_4 , unsigned int V_8 )
{
struct { T_1 _ [ V_9 ] ; } * V_10 = V_4 ;
T_2 V_11 ;
int V_7 = 3 ;
asm volatile (
" .insn rrf,0xb9a00000,%[ign],%[req],0,%[lps]\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [ign] "=d" (ignored), "+m" (*req)
: [req] "a" (req), [lps] "i" (lps)
: "cc");
return V_7 ;
}
static void * F_5 ( T_3 V_12 )
{
return ( void * ) F_6 ( V_12 , F_7 ( V_9 ) ) ;
}
static void F_8 ( void * V_13 )
{
F_9 ( ( unsigned long ) V_13 , F_7 ( V_9 ) ) ;
}
static void F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_18 = V_17 -> V_19 ;
V_15 -> V_20 = V_17 -> V_21 ;
V_15 -> V_22 = V_17 -> V_23 ;
V_15 -> V_24 = V_17 -> V_25 ;
V_15 -> V_26 = V_17 -> V_27 ;
switch ( V_17 -> V_28 ) {
case 1 :
V_15 -> V_29 = V_30 ;
break;
default:
V_15 -> V_29 = V_31 ;
break;
}
}
static int F_11 ( struct V_14 * V_15 , T_1 V_32 )
{
struct V_33 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_41 ;
V_34 -> V_17 . V_38 . V_39 = sizeof( V_34 -> V_17 ) ;
V_34 -> V_37 . V_32 = V_32 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( ! V_2 && V_34 -> V_17 . V_38 . V_1 == V_43 )
F_10 ( V_15 , & V_34 -> V_17 ) ;
else {
F_12 ( L_1 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
}
F_8 ( V_34 ) ;
return V_2 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_45 * V_17 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
V_15 -> V_48 [ V_46 ] . V_49 = F_14 ( V_17 -> V_50 [ V_46 ] ) ;
V_15 -> V_48 [ V_46 ] . V_51 = V_17 -> V_52 [ V_46 ] ;
}
V_15 -> V_53 = V_17 -> V_54 ;
V_15 -> V_55 = V_17 -> V_56 ;
V_15 -> V_57 = V_17 -> V_57 ;
V_15 -> V_32 = V_17 -> V_32 ;
V_15 -> V_58 = V_17 -> V_58 ;
V_15 -> V_59 = V_17 -> V_59 ;
V_15 -> V_60 = V_17 -> V_60 ;
V_15 -> V_61 = sizeof( V_62 ) * V_17 -> V_63 ;
memcpy ( V_15 -> V_64 , V_17 -> V_64 , sizeof( V_15 -> V_64 ) ) ;
if ( V_17 -> V_65 ) {
memcpy ( V_15 -> V_66 , V_17 -> V_66 ,
sizeof( V_15 -> V_66 ) ) ;
}
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , V_62 V_67 )
{
struct V_68 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_69 ;
V_34 -> V_17 . V_38 . V_39 = sizeof( V_34 -> V_17 ) ;
V_34 -> V_37 . V_67 = V_67 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( ! V_2 && V_34 -> V_17 . V_38 . V_1 == V_43 ) {
V_2 = F_13 ( V_15 , & V_34 -> V_17 ) ;
if ( V_2 )
goto V_70;
V_2 = F_11 ( V_15 , V_34 -> V_17 . V_32 ) ;
} else {
F_12 ( L_2 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
}
V_70:
F_8 ( V_34 ) ;
return V_2 ;
}
int F_16 ( V_62 V_71 , V_62 V_67 , int V_72 )
{
struct V_14 * V_15 ;
int V_2 = - V_36 ;
F_17 ( 3 , L_3 , V_71 , V_67 , V_72 ) ;
V_15 = F_18 ( sizeof( * V_15 ) , V_35 ) ;
if ( ! V_15 )
goto error;
V_15 -> V_67 = V_67 ;
V_15 -> V_71 = V_71 ;
V_2 = F_15 ( V_15 , V_67 ) ;
if ( V_2 )
goto error;
if ( V_72 )
V_15 -> V_73 = V_74 ;
else
V_15 -> V_73 = V_75 ;
V_2 = F_19 ( V_15 ) ;
if ( V_2 )
goto error;
return 0 ;
error:
F_17 ( 0 , L_4 , V_71 , V_2 ) ;
F_20 ( V_15 ) ;
return V_2 ;
}
static int F_21 ( V_62 * V_67 , T_1 V_76 , T_1 V_77 )
{
struct V_78 * V_34 ;
int V_2 , V_79 = 100 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
do {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_80 ;
V_34 -> V_17 . V_38 . V_39 = sizeof( V_34 -> V_17 ) ;
V_34 -> V_37 . V_67 = * V_67 ;
V_34 -> V_37 . V_81 = V_77 ;
V_34 -> V_37 . V_82 = V_76 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( V_34 -> V_17 . V_38 . V_1 == V_83 ) {
V_79 -- ;
if ( V_79 < 0 )
break;
F_22 ( 20 ) ;
}
} while ( V_34 -> V_17 . V_38 . V_1 == V_83 );
if ( ! V_2 && V_34 -> V_17 . V_38 . V_1 == V_43 )
* V_67 = V_34 -> V_17 . V_67 ;
else {
F_12 ( L_5 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
}
F_8 ( V_34 ) ;
return V_2 ;
}
int F_23 ( struct V_14 * V_15 , T_1 V_76 )
{
V_62 V_67 = V_15 -> V_67 ;
int V_2 ;
V_2 = F_21 ( & V_67 , V_76 , V_84 ) ;
if ( ! V_2 )
V_15 -> V_67 = V_67 ;
F_17 ( 3 , L_6 , V_15 -> V_71 , V_15 -> V_67 , V_2 ) ;
return V_2 ;
}
int F_24 ( struct V_14 * V_15 )
{
V_62 V_67 = V_15 -> V_67 ;
int V_2 ;
if ( ! F_25 ( V_15 ) )
return 0 ;
V_2 = F_21 ( & V_67 , 0 , V_85 ) ;
if ( ! V_2 )
V_15 -> V_67 = V_67 ;
F_17 ( 3 , L_7 , V_15 -> V_71 , V_15 -> V_67 , V_2 ) ;
return V_2 ;
}
static int F_26 ( struct V_86 * V_34 , void * V_4 ,
void (* F_27)( struct V_87 * , void * ) )
{
T_2 V_88 = 0 ;
int V_89 , V_46 , V_2 ;
do {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_90 ;
V_34 -> V_17 . V_38 . V_39 = V_9 - V_91 ;
V_34 -> V_37 . V_88 = V_88 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( V_2 || V_34 -> V_17 . V_38 . V_1 != V_43 ) {
F_12 ( L_8 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
goto V_70;
}
V_92 = V_34 -> V_17 . V_93 ;
F_28 ( V_34 -> V_17 . V_94 !=
sizeof( struct V_87 ) ) ;
V_89 = ( V_34 -> V_17 . V_38 . V_39 - V_91 ) /
V_34 -> V_17 . V_94 ;
V_88 = V_34 -> V_17 . V_88 ;
for ( V_46 = 0 ; V_46 < V_89 ; V_46 ++ )
F_27 ( & V_34 -> V_17 . V_95 [ V_46 ] , V_4 ) ;
} while ( V_88 );
V_70:
return V_2 ;
}
static void F_29 ( struct V_87 * V_96 , void * V_4 )
{
struct V_14 * V_15 ;
if ( ! V_96 -> V_97 )
return;
V_15 = F_30 ( V_96 -> V_71 ) ;
if ( ! V_15 )
F_16 ( V_96 -> V_71 , V_96 -> V_67 , V_96 -> V_98 ) ;
}
static void F_31 ( struct V_87 * V_96 , void * V_4 )
{
struct V_14 * V_15 ;
if ( ! V_96 -> V_97 )
return;
V_15 = F_30 ( V_96 -> V_71 ) ;
if ( ! V_15 )
return;
V_15 -> V_67 = V_96 -> V_67 ;
}
int F_32 ( void )
{
struct V_86 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , NULL , F_29 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
int F_33 ( void )
{
struct V_86 * V_34 ;
int V_2 ;
F_34 () ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , NULL , F_29 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
int F_35 ( void )
{
struct V_86 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_99 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , NULL , F_31 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
static void F_36 ( struct V_87 * V_96 , void * V_4 )
{
struct V_100 * V_101 = V_4 ;
if ( V_96 -> V_71 != V_101 -> V_71 )
return;
V_101 -> V_73 = V_96 -> V_98 ;
}
int F_37 ( V_62 V_71 , enum V_102 * V_73 )
{
struct V_86 * V_34 ;
struct V_100 V_101 = { V_71 , V_103 } ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , & V_101 , F_36 ) ;
if ( ! V_2 )
* V_73 = V_101 . V_73 ;
F_8 ( V_34 ) ;
return V_2 ;
}
static int F_38 ( struct F_4 * V_10 , struct V_104 * V_105 )
{
unsigned long V_106 = V_107 - sizeof( V_105 -> V_37 ) ;
if ( V_105 -> V_37 . V_38 . V_39 != sizeof( V_105 -> V_37 ) ||
V_105 -> V_17 . V_38 . V_39 > V_106 )
return - V_108 ;
return F_4 ( V_105 , V_109 ) ? - V_110 : 0 ;
}
static int F_39 ( struct F_4 * V_10 , struct V_111 * V_105 )
{
switch ( V_105 -> V_40 ) {
case 0x0001 :
return F_38 ( V_10 , ( void * ) V_105 ) ;
default:
return - V_108 ;
}
}
static int F_40 ( struct F_4 * V_10 , struct V_104 * V_105 )
{
unsigned long V_106 = V_107 - sizeof( V_105 -> V_37 ) ;
if ( V_105 -> V_37 . V_38 . V_39 != sizeof( V_105 -> V_37 ) ||
V_105 -> V_17 . V_38 . V_39 > V_106 )
return - V_108 ;
return F_4 ( V_105 , V_42 ) ? - V_110 : 0 ;
}
static int F_41 ( struct F_4 * V_10 , struct V_86 * V_105 )
{
unsigned long V_106 = V_107 - sizeof( V_105 -> V_37 ) ;
if ( V_105 -> V_37 . V_38 . V_39 != sizeof( V_105 -> V_37 ) ||
V_105 -> V_17 . V_38 . V_39 > V_106 )
return - V_108 ;
if ( V_105 -> V_37 . V_112 != 0 )
return - V_108 ;
return F_4 ( V_105 , V_42 ) ? - V_110 : 0 ;
}
static int F_42 ( struct F_4 * V_10 ,
struct V_68 * V_105 )
{
unsigned long V_106 = V_107 - sizeof( V_105 -> V_37 ) ;
if ( V_105 -> V_37 . V_38 . V_39 != sizeof( V_105 -> V_37 ) ||
V_105 -> V_17 . V_38 . V_39 > V_106 )
return - V_108 ;
if ( V_105 -> V_37 . V_112 != 0 || V_105 -> V_37 . V_113 != 0 )
return - V_108 ;
return F_4 ( V_105 , V_42 ) ? - V_110 : 0 ;
}
static int F_43 ( struct F_4 * V_10 ,
struct V_33 * V_105 )
{
unsigned long V_106 = V_107 - sizeof( V_105 -> V_37 ) ;
if ( V_105 -> V_37 . V_38 . V_39 != sizeof( V_105 -> V_37 ) ||
V_105 -> V_17 . V_38 . V_39 > V_106 )
return - V_108 ;
if ( V_105 -> V_37 . V_112 != 0 || V_105 -> V_37 . V_113 != 0 ||
V_105 -> V_37 . V_114 != 0 )
return - V_108 ;
return F_4 ( V_105 , V_42 ) ? - V_110 : 0 ;
}
static int F_44 ( struct F_4 * V_10 , struct V_111 * V_105 )
{
switch ( V_105 -> V_40 ) {
case 0x0001 :
return F_40 ( V_10 , ( void * ) V_105 ) ;
case 0x0002 :
return F_41 ( V_10 , ( void * ) V_105 ) ;
case 0x0003 :
return F_42 ( V_10 , ( void * ) V_105 ) ;
case 0x0004 :
return F_43 ( V_10 , ( void * ) V_105 ) ;
default:
return - V_108 ;
}
}
static int F_45 ( struct F_4 * V_10 )
{
struct V_111 * V_105 ;
void T_4 * V_115 ;
int V_2 ;
V_2 = - V_108 ;
if ( V_10 -> V_8 != 0 && V_10 -> V_8 != 2 )
goto V_70;
V_2 = - V_36 ;
V_105 = F_5 ( V_35 ) ;
if ( ! V_105 )
goto V_70;
V_2 = - V_116 ;
V_115 = ( void V_117 T_4 * ) ( unsigned long ) V_10 -> V_118 ;
if ( F_46 ( V_105 , V_115 , V_107 ) != 0 )
goto V_119;
V_2 = - V_108 ;
if ( V_105 -> V_120 != 0 || V_105 -> V_121 != 0 || V_105 -> V_112 != 0 )
goto V_119;
switch ( V_10 -> V_8 ) {
case 0 :
V_2 = F_39 ( V_10 , V_105 ) ;
break;
case 2 :
V_2 = F_44 ( V_10 , V_105 ) ;
break;
}
if ( V_2 )
goto V_119;
V_2 = - V_116 ;
if ( F_47 ( V_115 , V_105 , V_107 ) != 0 )
goto V_119;
V_2 = 0 ;
V_119:
F_8 ( V_105 ) ;
V_70:
return V_2 ;
}
static int F_48 ( struct F_4 * V_10 )
{
void T_4 * V_115 ;
unsigned long V_5 ;
int V_122 ;
if ( V_10 -> V_40 > 1 || F_3 ( & V_5 ) != 0 )
return - V_108 ;
V_115 = ( void V_117 T_4 * ) ( unsigned long ) V_10 -> V_118 ;
if ( V_10 -> V_40 == 0 ) {
V_122 = F_49 ( V_10 -> V_8 , & V_5 ) ;
return F_50 ( V_122 , ( int T_4 * ) V_115 ) ;
}
return F_50 ( V_5 , ( unsigned long T_4 * ) V_115 ) ;
}
static long F_51 ( struct V_123 * V_124 , unsigned int V_40 ,
unsigned long V_125 )
{
struct F_4 V_10 ;
void T_4 * V_126 ;
if ( V_40 != V_127 )
return - V_108 ;
V_126 = F_52 () ? F_53 ( V_125 ) : ( void T_4 * ) V_125 ;
if ( F_46 ( & V_10 , V_126 , sizeof( V_10 ) ) )
return - V_116 ;
if ( V_10 . V_128 != 0 )
return - V_108 ;
return V_10 . V_129 ? F_48 ( & V_10 ) : F_45 ( & V_10 ) ;
}
static int F_54 ( struct V_130 * V_130 , struct V_123 * V_124 )
{
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_131 ) ;
}
