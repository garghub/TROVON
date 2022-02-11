static void F_1 ( bool V_1 )
{
if ( V_2 != V_1 )
F_2 ( 1 , L_1 , V_1 ) ;
V_2 = V_1 ;
}
static inline void F_3 ( unsigned int V_3 , int V_4 )
{
struct {
unsigned int V_3 ;
int V_4 ;
} V_5 V_6 = { V_3 , V_4 } ;
F_4 ( & V_6 , sizeof( V_6 ) ) ;
}
static inline int F_5 ( unsigned long * V_7 )
{
unsigned long V_8 ;
int V_9 = 3 ;
asm volatile (
" .insn rrf,0xb9a00000,%[mask],%[cmd],8,0\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [mask] "=d" (mask) : [cmd] "a" (1)
: "cc");
* V_7 = V_8 ;
return V_9 ;
}
static inline int F_6 ( void * V_6 , unsigned int V_10 )
{
struct { T_1 _ [ V_11 ] ; } * V_12 = V_6 ;
T_2 V_13 ;
int V_9 = 3 ;
asm volatile (
" .insn rrf,0xb9a00000,%[ign],%[req],0,%[lps]\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [ign] "=d" (ignored), "+m" (*req)
: [req] "a" (req), [lps] "i" (lps)
: "cc");
return V_9 ;
}
static void * F_7 ( T_3 V_14 )
{
return ( void * ) F_8 ( V_14 , F_9 ( V_11 ) ) ;
}
static void F_10 ( void * V_15 )
{
F_11 ( ( unsigned long ) V_15 , F_9 ( V_11 ) ) ;
}
static void F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
V_17 -> V_20 = V_19 -> V_21 ;
V_17 -> V_22 = V_19 -> V_23 ;
V_17 -> V_24 = V_19 -> V_25 ;
V_17 -> V_26 = V_19 -> V_27 ;
V_17 -> V_28 = V_19 -> V_29 ;
switch ( V_19 -> V_30 ) {
case 1 :
V_17 -> V_31 = V_32 ;
break;
default:
V_17 -> V_31 = V_33 ;
break;
}
}
static int F_13 ( struct V_16 * V_17 , T_1 V_34 )
{
struct V_35 * V_36 ;
int V_4 ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_39 . V_40 . V_41 = sizeof( V_36 -> V_39 ) ;
V_36 -> V_39 . V_40 . V_42 = V_43 ;
V_36 -> V_19 . V_40 . V_41 = sizeof( V_36 -> V_19 ) ;
V_36 -> V_39 . V_34 = V_34 ;
V_4 = F_6 ( V_36 , V_44 ) ;
if ( ! V_4 && V_36 -> V_19 . V_40 . V_3 == V_45 )
F_12 ( V_17 , & V_36 -> V_19 ) ;
else {
F_14 ( L_2 ) ;
F_3 ( V_36 -> V_19 . V_40 . V_3 , V_4 ) ;
V_4 = - V_46 ;
}
F_10 ( V_36 ) ;
return V_4 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_47 * V_19 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_17 -> V_50 [ V_48 ] . V_51 = F_16 ( V_19 -> V_52 [ V_48 ] ) ;
V_17 -> V_50 [ V_48 ] . V_53 = V_19 -> V_54 [ V_48 ] ;
}
V_17 -> V_55 = V_19 -> V_56 ;
V_17 -> V_57 = V_19 -> V_58 ;
V_17 -> V_59 = V_19 -> V_59 ;
V_17 -> V_34 = V_19 -> V_34 ;
V_17 -> V_60 = V_19 -> V_60 ;
V_17 -> V_61 = V_19 -> V_61 ;
V_17 -> V_62 = V_19 -> V_62 ;
V_17 -> V_63 = sizeof( V_64 ) * V_19 -> V_65 ;
memcpy ( V_17 -> V_66 , V_19 -> V_66 , sizeof( V_17 -> V_66 ) ) ;
if ( V_19 -> V_67 ) {
memcpy ( V_17 -> V_68 , V_19 -> V_68 ,
sizeof( V_17 -> V_68 ) ) ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , V_64 V_69 )
{
struct V_70 * V_36 ;
int V_4 ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_39 . V_40 . V_41 = sizeof( V_36 -> V_39 ) ;
V_36 -> V_39 . V_40 . V_42 = V_71 ;
V_36 -> V_19 . V_40 . V_41 = sizeof( V_36 -> V_19 ) ;
V_36 -> V_39 . V_69 = V_69 ;
V_4 = F_6 ( V_36 , V_44 ) ;
if ( ! V_4 && V_36 -> V_19 . V_40 . V_3 == V_45 ) {
V_4 = F_15 ( V_17 , & V_36 -> V_19 ) ;
if ( V_4 )
goto V_72;
V_4 = F_13 ( V_17 , V_36 -> V_19 . V_34 ) ;
} else {
F_14 ( L_3 ) ;
F_3 ( V_36 -> V_19 . V_40 . V_3 , V_4 ) ;
V_4 = - V_46 ;
}
V_72:
F_10 ( V_36 ) ;
return V_4 ;
}
int F_18 ( V_64 V_73 , V_64 V_69 , int V_74 )
{
struct V_16 * V_17 ;
int V_4 = - V_38 ;
F_2 ( 3 , L_4 , V_73 , V_69 , V_74 ) ;
V_17 = F_19 ( sizeof( * V_17 ) , V_37 ) ;
if ( ! V_17 )
goto error;
V_17 -> V_69 = V_69 ;
V_17 -> V_73 = V_73 ;
V_4 = F_17 ( V_17 , V_69 ) ;
if ( V_4 )
goto error;
if ( V_74 )
V_17 -> V_75 = V_76 ;
else
V_17 -> V_75 = V_77 ;
V_4 = F_20 ( V_17 ) ;
if ( V_4 )
goto error;
return 0 ;
error:
F_2 ( 0 , L_5 , V_73 , V_4 ) ;
F_21 ( V_17 ) ;
return V_4 ;
}
static int F_22 ( V_64 * V_69 , T_1 V_78 , T_1 V_79 )
{
struct V_80 * V_36 ;
int V_4 , V_81 = 100 ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
do {
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_39 . V_40 . V_41 = sizeof( V_36 -> V_39 ) ;
V_36 -> V_39 . V_40 . V_42 = V_82 ;
V_36 -> V_19 . V_40 . V_41 = sizeof( V_36 -> V_19 ) ;
V_36 -> V_39 . V_69 = * V_69 ;
V_36 -> V_39 . V_83 = V_79 ;
V_36 -> V_39 . V_84 = V_78 ;
V_4 = F_6 ( V_36 , V_44 ) ;
if ( V_36 -> V_19 . V_40 . V_3 == V_85 ) {
V_81 -- ;
if ( V_81 < 0 )
break;
F_23 ( 20 ) ;
}
} while ( V_36 -> V_19 . V_40 . V_3 == V_85 );
if ( ! V_4 && V_36 -> V_19 . V_40 . V_3 == V_45 )
* V_69 = V_36 -> V_19 . V_69 ;
else {
F_14 ( L_6 ) ;
F_3 ( V_36 -> V_19 . V_40 . V_3 , V_4 ) ;
V_4 = - V_46 ;
}
F_10 ( V_36 ) ;
return V_4 ;
}
int F_24 ( struct V_16 * V_17 , T_1 V_78 )
{
V_64 V_69 = V_17 -> V_69 ;
int V_4 ;
V_4 = F_22 ( & V_69 , V_78 , V_86 ) ;
if ( ! V_4 )
V_17 -> V_69 = V_69 ;
F_2 ( 3 , L_7 , V_17 -> V_73 , V_17 -> V_69 , V_4 ) ;
return V_4 ;
}
int F_25 ( struct V_16 * V_17 )
{
V_64 V_69 = V_17 -> V_69 ;
int V_4 ;
if ( ! F_26 ( V_17 ) )
return 0 ;
V_4 = F_22 ( & V_69 , 0 , V_87 ) ;
if ( ! V_4 )
V_17 -> V_69 = V_69 ;
F_2 ( 3 , L_8 , V_17 -> V_73 , V_17 -> V_69 , V_4 ) ;
return V_4 ;
}
static int F_27 ( struct V_88 * V_36 , void * V_6 ,
void (* F_28)( struct V_89 * , void * ) )
{
T_2 V_90 = 0 ;
int V_91 , V_48 , V_4 ;
do {
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_39 . V_40 . V_41 = sizeof( V_36 -> V_39 ) ;
V_36 -> V_39 . V_40 . V_42 = V_92 ;
V_36 -> V_19 . V_40 . V_41 = V_11 - V_93 ;
V_36 -> V_39 . V_90 = V_90 ;
V_4 = F_6 ( V_36 , V_44 ) ;
if ( V_4 || V_36 -> V_19 . V_40 . V_3 != V_45 ) {
F_14 ( L_9 ) ;
F_3 ( V_36 -> V_19 . V_40 . V_3 , V_4 ) ;
V_4 = - V_46 ;
goto V_72;
}
F_1 ( V_36 -> V_19 . V_94 ) ;
F_29 ( V_36 -> V_19 . V_95 !=
sizeof( struct V_89 ) ) ;
V_91 = ( V_36 -> V_19 . V_40 . V_41 - V_93 ) /
V_36 -> V_19 . V_95 ;
V_90 = V_36 -> V_19 . V_90 ;
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ )
F_28 ( & V_36 -> V_19 . V_96 [ V_48 ] , V_6 ) ;
} while ( V_90 );
V_72:
return V_4 ;
}
static void F_30 ( struct V_89 * V_97 , void * V_6 )
{
struct V_16 * V_17 ;
if ( ! V_97 -> V_98 )
return;
V_17 = F_31 ( V_97 -> V_73 ) ;
if ( ! V_17 )
F_18 ( V_97 -> V_73 , V_97 -> V_69 , V_97 -> V_99 ) ;
}
static void F_32 ( struct V_89 * V_97 , void * V_6 )
{
struct V_16 * V_17 ;
if ( ! V_97 -> V_98 )
return;
V_17 = F_31 ( V_97 -> V_73 ) ;
if ( ! V_17 )
return;
V_17 -> V_69 = V_97 -> V_69 ;
}
int F_33 ( void )
{
struct V_88 * V_36 ;
int V_4 ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_4 = F_27 ( V_36 , NULL , F_30 ) ;
F_10 ( V_36 ) ;
return V_4 ;
}
int F_34 ( void )
{
struct V_88 * V_36 ;
int V_4 ;
F_35 () ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_4 = F_27 ( V_36 , NULL , F_30 ) ;
F_10 ( V_36 ) ;
return V_4 ;
}
int F_36 ( void )
{
struct V_88 * V_36 ;
int V_4 ;
V_36 = F_7 ( V_100 ) ;
if ( ! V_36 )
return - V_38 ;
V_4 = F_27 ( V_36 , NULL , F_32 ) ;
F_10 ( V_36 ) ;
return V_4 ;
}
static void F_37 ( struct V_89 * V_97 , void * V_6 )
{
struct V_101 * V_102 = V_6 ;
if ( V_97 -> V_73 != V_102 -> V_73 )
return;
V_102 -> V_75 = V_97 -> V_99 ;
}
int F_38 ( V_64 V_73 , enum V_103 * V_75 )
{
struct V_88 * V_36 ;
struct V_101 V_102 = { V_73 , V_104 } ;
int V_4 ;
V_36 = F_7 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_4 = F_27 ( V_36 , & V_102 , F_37 ) ;
if ( ! V_4 )
* V_75 = V_102 . V_75 ;
F_10 ( V_36 ) ;
return V_4 ;
}
static int F_39 ( struct F_6 * V_12 , struct V_105 * V_106 )
{
unsigned long V_107 = V_108 - sizeof( V_106 -> V_39 ) ;
if ( V_106 -> V_39 . V_40 . V_41 != sizeof( V_106 -> V_39 ) ||
V_106 -> V_19 . V_40 . V_41 > V_107 )
return - V_109 ;
return F_6 ( V_106 , V_110 ) ? - V_111 : 0 ;
}
static int F_40 ( struct F_6 * V_12 , struct V_112 * V_106 )
{
switch ( V_106 -> V_42 ) {
case 0x0001 :
return F_39 ( V_12 , ( void * ) V_106 ) ;
default:
return - V_109 ;
}
}
static int F_41 ( struct F_6 * V_12 , struct V_105 * V_106 )
{
unsigned long V_107 = V_108 - sizeof( V_106 -> V_39 ) ;
if ( V_106 -> V_39 . V_40 . V_41 != sizeof( V_106 -> V_39 ) ||
V_106 -> V_19 . V_40 . V_41 > V_107 )
return - V_109 ;
return F_6 ( V_106 , V_44 ) ? - V_111 : 0 ;
}
static int F_42 ( struct F_6 * V_12 , struct V_88 * V_106 )
{
unsigned long V_107 = V_108 - sizeof( V_106 -> V_39 ) ;
if ( V_106 -> V_39 . V_40 . V_41 != sizeof( V_106 -> V_39 ) ||
V_106 -> V_19 . V_40 . V_41 > V_107 )
return - V_109 ;
if ( V_106 -> V_39 . V_113 != 0 )
return - V_109 ;
return F_6 ( V_106 , V_44 ) ? - V_111 : 0 ;
}
static int F_43 ( struct F_6 * V_12 ,
struct V_70 * V_106 )
{
unsigned long V_107 = V_108 - sizeof( V_106 -> V_39 ) ;
if ( V_106 -> V_39 . V_40 . V_41 != sizeof( V_106 -> V_39 ) ||
V_106 -> V_19 . V_40 . V_41 > V_107 )
return - V_109 ;
if ( V_106 -> V_39 . V_113 != 0 || V_106 -> V_39 . V_114 != 0 )
return - V_109 ;
return F_6 ( V_106 , V_44 ) ? - V_111 : 0 ;
}
static int F_44 ( struct F_6 * V_12 ,
struct V_35 * V_106 )
{
unsigned long V_107 = V_108 - sizeof( V_106 -> V_39 ) ;
if ( V_106 -> V_39 . V_40 . V_41 != sizeof( V_106 -> V_39 ) ||
V_106 -> V_19 . V_40 . V_41 > V_107 )
return - V_109 ;
if ( V_106 -> V_39 . V_113 != 0 || V_106 -> V_39 . V_114 != 0 ||
V_106 -> V_39 . V_115 != 0 )
return - V_109 ;
return F_6 ( V_106 , V_44 ) ? - V_111 : 0 ;
}
static int F_45 ( struct F_6 * V_12 , struct V_112 * V_106 )
{
switch ( V_106 -> V_42 ) {
case 0x0001 :
return F_41 ( V_12 , ( void * ) V_106 ) ;
case 0x0002 :
return F_42 ( V_12 , ( void * ) V_106 ) ;
case 0x0003 :
return F_43 ( V_12 , ( void * ) V_106 ) ;
case 0x0004 :
return F_44 ( V_12 , ( void * ) V_106 ) ;
default:
return - V_109 ;
}
}
static int F_46 ( struct F_6 * V_12 )
{
struct V_112 * V_106 ;
void T_4 * V_116 ;
int V_4 ;
V_4 = - V_109 ;
if ( V_12 -> V_10 != 0 && V_12 -> V_10 != 2 )
goto V_72;
V_4 = - V_38 ;
V_106 = F_7 ( V_37 ) ;
if ( ! V_106 )
goto V_72;
V_4 = - V_117 ;
V_116 = ( void V_118 T_4 * ) ( unsigned long ) V_12 -> V_119 ;
if ( F_47 ( V_106 , V_116 , V_108 ) != 0 )
goto V_120;
V_4 = - V_109 ;
if ( V_106 -> V_121 != 0 || V_106 -> V_122 != 0 || V_106 -> V_113 != 0 )
goto V_120;
switch ( V_12 -> V_10 ) {
case 0 :
V_4 = F_40 ( V_12 , V_106 ) ;
break;
case 2 :
V_4 = F_45 ( V_12 , V_106 ) ;
break;
}
if ( V_4 )
goto V_120;
V_4 = - V_117 ;
if ( F_48 ( V_116 , V_106 , V_108 ) != 0 )
goto V_120;
V_4 = 0 ;
V_120:
F_10 ( V_106 ) ;
V_72:
return V_4 ;
}
static int F_49 ( struct F_6 * V_12 )
{
void T_4 * V_116 ;
unsigned long V_7 ;
int V_123 ;
if ( V_12 -> V_42 > 1 || F_5 ( & V_7 ) != 0 )
return - V_109 ;
V_116 = ( void V_118 T_4 * ) ( unsigned long ) V_12 -> V_119 ;
if ( V_12 -> V_42 == 0 ) {
V_123 = F_50 ( V_12 -> V_10 , & V_7 ) ;
return F_51 ( V_123 , ( int T_4 * ) V_116 ) ;
}
return F_51 ( V_7 , ( unsigned long T_4 * ) V_116 ) ;
}
static long F_52 ( struct V_124 * V_125 , unsigned int V_42 ,
unsigned long V_126 )
{
struct F_6 V_12 ;
void T_4 * V_127 ;
if ( V_42 != V_128 )
return - V_109 ;
V_127 = F_53 () ? F_54 ( V_126 ) : ( void T_4 * ) V_126 ;
if ( F_47 ( & V_12 , V_127 , sizeof( V_12 ) ) )
return - V_117 ;
if ( V_12 . V_129 != 0 )
return - V_109 ;
return V_12 . V_130 ? F_49 ( & V_12 ) : F_46 ( & V_12 ) ;
}
static int F_55 ( struct V_131 * V_131 , struct V_124 * V_125 )
{
return 0 ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_132 ) ;
}
