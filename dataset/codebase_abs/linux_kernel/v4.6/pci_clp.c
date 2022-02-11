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
memcpy ( V_15 -> V_61 , V_17 -> V_61 , sizeof( V_15 -> V_61 ) ) ;
if ( V_17 -> V_62 ) {
memcpy ( V_15 -> V_63 , V_17 -> V_63 ,
sizeof( V_15 -> V_63 ) ) ;
}
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , T_4 V_64 )
{
struct V_65 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_66 ;
V_34 -> V_17 . V_38 . V_39 = sizeof( V_34 -> V_17 ) ;
V_34 -> V_37 . V_64 = V_64 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( ! V_2 && V_34 -> V_17 . V_38 . V_1 == V_43 ) {
V_2 = F_13 ( V_15 , & V_34 -> V_17 ) ;
if ( V_2 )
goto V_67;
V_2 = F_11 ( V_15 , V_34 -> V_17 . V_32 ) ;
} else {
F_12 ( L_2 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
}
V_67:
F_8 ( V_34 ) ;
return V_2 ;
}
int F_16 ( T_4 V_68 , T_4 V_64 , int V_69 )
{
struct V_14 * V_15 ;
int V_2 ;
F_17 ( 3 , L_3 , V_68 , V_64 , V_69 ) ;
V_15 = F_18 ( sizeof( * V_15 ) , V_35 ) ;
if ( ! V_15 )
return - V_36 ;
V_15 -> V_64 = V_64 ;
V_15 -> V_68 = V_68 ;
V_2 = F_15 ( V_15 , V_64 ) ;
if ( V_2 )
goto error;
if ( V_69 )
V_15 -> V_70 = V_71 ;
else
V_15 -> V_70 = V_72 ;
V_2 = F_19 ( V_15 ) ;
if ( V_2 )
goto error;
return 0 ;
error:
F_20 ( V_15 ) ;
return V_2 ;
}
static int F_21 ( T_4 * V_64 , T_1 V_73 , T_1 V_74 )
{
struct V_75 * V_34 ;
int V_2 , V_76 = 100 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
do {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_77 ;
V_34 -> V_17 . V_38 . V_39 = sizeof( V_34 -> V_17 ) ;
V_34 -> V_37 . V_64 = * V_64 ;
V_34 -> V_37 . V_78 = V_74 ;
V_34 -> V_37 . V_79 = V_73 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( V_34 -> V_17 . V_38 . V_1 == V_80 ) {
V_76 -- ;
if ( V_76 < 0 )
break;
F_22 ( 20 ) ;
}
} while ( V_34 -> V_17 . V_38 . V_1 == V_80 );
if ( ! V_2 && V_34 -> V_17 . V_38 . V_1 == V_43 )
* V_64 = V_34 -> V_17 . V_64 ;
else {
F_12 ( L_4 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
}
F_8 ( V_34 ) ;
return V_2 ;
}
int F_23 ( struct V_14 * V_15 , T_1 V_73 )
{
T_4 V_64 = V_15 -> V_64 ;
int V_2 ;
V_2 = F_21 ( & V_64 , V_73 , V_81 ) ;
if ( ! V_2 )
V_15 -> V_64 = V_64 ;
F_17 ( 3 , L_5 , V_15 -> V_68 , V_15 -> V_64 , V_2 ) ;
return V_2 ;
}
int F_24 ( struct V_14 * V_15 )
{
T_4 V_64 = V_15 -> V_64 ;
int V_2 ;
if ( ! F_25 ( V_15 ) )
return 0 ;
V_2 = F_21 ( & V_64 , 0 , V_82 ) ;
if ( ! V_2 )
V_15 -> V_64 = V_64 ;
F_17 ( 3 , L_6 , V_15 -> V_68 , V_15 -> V_64 , V_2 ) ;
return V_2 ;
}
static int F_26 ( struct V_83 * V_34 ,
void (* F_27)( struct V_84 * V_85 ) )
{
T_2 V_86 = 0 ;
int V_87 , V_46 , V_2 ;
do {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_37 . V_38 . V_39 = sizeof( V_34 -> V_37 ) ;
V_34 -> V_37 . V_38 . V_40 = V_88 ;
V_34 -> V_17 . V_38 . V_39 = V_9 - V_89 ;
V_34 -> V_37 . V_86 = V_86 ;
V_2 = F_4 ( V_34 , V_42 ) ;
if ( V_2 || V_34 -> V_17 . V_38 . V_1 != V_43 ) {
F_12 ( L_7 ) ;
F_1 ( V_34 -> V_17 . V_38 . V_1 , V_2 ) ;
V_2 = - V_44 ;
goto V_67;
}
F_28 ( V_34 -> V_17 . V_90 !=
sizeof( struct V_84 ) ) ;
V_87 = ( V_34 -> V_17 . V_38 . V_39 - V_89 ) /
V_34 -> V_17 . V_90 ;
V_86 = V_34 -> V_17 . V_86 ;
for ( V_46 = 0 ; V_46 < V_87 ; V_46 ++ )
F_27 ( & V_34 -> V_17 . V_91 [ V_46 ] ) ;
} while ( V_86 );
V_67:
return V_2 ;
}
static void F_29 ( struct V_84 * V_85 )
{
if ( ! V_85 -> V_92 )
return;
F_16 ( V_85 -> V_68 , V_85 -> V_64 , V_85 -> V_93 ) ;
}
static void F_30 ( struct V_84 * V_85 )
{
struct V_14 * V_15 ;
if ( ! V_85 -> V_92 )
return;
V_15 = F_31 ( V_85 -> V_68 ) ;
if ( ! V_15 ) {
F_16 ( V_85 -> V_68 , V_85 -> V_64 , V_85 -> V_93 ) ;
return;
}
if ( ! V_85 -> V_93 ) {
F_32 ( V_15 ) ;
}
}
static void F_33 ( struct V_84 * V_85 )
{
struct V_14 * V_15 ;
if ( ! V_85 -> V_92 )
return;
V_15 = F_31 ( V_85 -> V_68 ) ;
if ( ! V_15 )
return;
V_15 -> V_64 = V_85 -> V_64 ;
}
int F_34 ( void )
{
struct V_83 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , F_29 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
int F_35 ( void )
{
struct V_83 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , F_30 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
int F_36 ( void )
{
struct V_83 * V_34 ;
int V_2 ;
V_34 = F_5 ( V_94 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_26 ( V_34 , F_33 ) ;
F_8 ( V_34 ) ;
return V_2 ;
}
static int F_37 ( struct F_4 * V_10 , struct V_95 * V_96 )
{
unsigned long V_97 = V_98 - sizeof( V_96 -> V_37 ) ;
if ( V_96 -> V_37 . V_38 . V_39 != sizeof( V_96 -> V_37 ) ||
V_96 -> V_17 . V_38 . V_39 > V_97 )
return - V_99 ;
return F_4 ( V_96 , V_100 ) ? - V_101 : 0 ;
}
static int F_38 ( struct F_4 * V_10 , struct V_102 * V_96 )
{
switch ( V_96 -> V_40 ) {
case 0x0001 :
return F_37 ( V_10 , ( void * ) V_96 ) ;
default:
return - V_99 ;
}
}
static int F_39 ( struct F_4 * V_10 , struct V_95 * V_96 )
{
unsigned long V_97 = V_98 - sizeof( V_96 -> V_37 ) ;
if ( V_96 -> V_37 . V_38 . V_39 != sizeof( V_96 -> V_37 ) ||
V_96 -> V_17 . V_38 . V_39 > V_97 )
return - V_99 ;
return F_4 ( V_96 , V_42 ) ? - V_101 : 0 ;
}
static int F_40 ( struct F_4 * V_10 , struct V_83 * V_96 )
{
unsigned long V_97 = V_98 - sizeof( V_96 -> V_37 ) ;
if ( V_96 -> V_37 . V_38 . V_39 != sizeof( V_96 -> V_37 ) ||
V_96 -> V_17 . V_38 . V_39 > V_97 )
return - V_99 ;
if ( V_96 -> V_37 . V_103 != 0 )
return - V_99 ;
return F_4 ( V_96 , V_42 ) ? - V_101 : 0 ;
}
static int F_41 ( struct F_4 * V_10 ,
struct V_65 * V_96 )
{
unsigned long V_97 = V_98 - sizeof( V_96 -> V_37 ) ;
if ( V_96 -> V_37 . V_38 . V_39 != sizeof( V_96 -> V_37 ) ||
V_96 -> V_17 . V_38 . V_39 > V_97 )
return - V_99 ;
if ( V_96 -> V_37 . V_103 != 0 || V_96 -> V_37 . V_104 != 0 )
return - V_99 ;
return F_4 ( V_96 , V_42 ) ? - V_101 : 0 ;
}
static int F_42 ( struct F_4 * V_10 ,
struct V_33 * V_96 )
{
unsigned long V_97 = V_98 - sizeof( V_96 -> V_37 ) ;
if ( V_96 -> V_37 . V_38 . V_39 != sizeof( V_96 -> V_37 ) ||
V_96 -> V_17 . V_38 . V_39 > V_97 )
return - V_99 ;
if ( V_96 -> V_37 . V_103 != 0 || V_96 -> V_37 . V_104 != 0 ||
V_96 -> V_37 . V_105 != 0 )
return - V_99 ;
return F_4 ( V_96 , V_42 ) ? - V_101 : 0 ;
}
static int F_43 ( struct F_4 * V_10 , struct V_102 * V_96 )
{
switch ( V_96 -> V_40 ) {
case 0x0001 :
return F_39 ( V_10 , ( void * ) V_96 ) ;
case 0x0002 :
return F_40 ( V_10 , ( void * ) V_96 ) ;
case 0x0003 :
return F_41 ( V_10 , ( void * ) V_96 ) ;
case 0x0004 :
return F_42 ( V_10 , ( void * ) V_96 ) ;
default:
return - V_99 ;
}
}
static int F_44 ( struct F_4 * V_10 )
{
struct V_102 * V_96 ;
void T_5 * V_106 ;
int V_2 ;
V_2 = - V_99 ;
if ( V_10 -> V_8 != 0 && V_10 -> V_8 != 2 )
goto V_67;
V_2 = - V_36 ;
V_96 = F_5 ( V_35 ) ;
if ( ! V_96 )
goto V_67;
V_2 = - V_107 ;
V_106 = ( void V_108 T_5 * ) ( unsigned long ) V_10 -> V_109 ;
if ( F_45 ( V_96 , V_106 , V_98 ) != 0 )
goto V_110;
V_2 = - V_99 ;
if ( V_96 -> V_111 != 0 || V_96 -> V_112 != 0 || V_96 -> V_103 != 0 )
goto V_110;
switch ( V_10 -> V_8 ) {
case 0 :
V_2 = F_38 ( V_10 , V_96 ) ;
break;
case 2 :
V_2 = F_43 ( V_10 , V_96 ) ;
break;
}
if ( V_2 )
goto V_110;
V_2 = - V_107 ;
if ( F_46 ( V_106 , V_96 , V_98 ) != 0 )
goto V_110;
V_2 = 0 ;
V_110:
F_8 ( V_96 ) ;
V_67:
return V_2 ;
}
static int F_47 ( struct F_4 * V_10 )
{
void T_5 * V_106 ;
unsigned long V_5 ;
int V_113 ;
if ( V_10 -> V_40 > 1 || F_3 ( & V_5 ) != 0 )
return - V_99 ;
V_106 = ( void V_108 T_5 * ) ( unsigned long ) V_10 -> V_109 ;
if ( V_10 -> V_40 == 0 ) {
V_113 = F_48 ( V_10 -> V_8 , & V_5 ) ;
return F_49 ( V_113 , ( int T_5 * ) V_106 ) ;
}
return F_49 ( V_5 , ( unsigned long T_5 * ) V_106 ) ;
}
static long F_50 ( struct V_114 * V_115 , unsigned int V_40 ,
unsigned long V_116 )
{
struct F_4 V_10 ;
void T_5 * V_117 ;
if ( V_40 != V_118 )
return - V_99 ;
V_117 = F_51 () ? F_52 ( V_116 ) : ( void T_5 * ) V_116 ;
if ( F_45 ( & V_10 , V_117 , sizeof( V_10 ) ) )
return - V_107 ;
if ( V_10 . V_119 != 0 )
return - V_99 ;
return V_10 . V_120 ? F_47 ( & V_10 ) : F_44 ( & V_10 ) ;
}
static int F_53 ( struct V_121 * V_121 , struct V_114 * V_115 )
{
return 0 ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_122 ) ;
}
