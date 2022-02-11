static int T_1 F_1 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
F_2 ( 0 , 9 ) ;
V_3 = F_3 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
F_4 ( V_5 | V_6 |
V_7 | V_8 ) ;
F_5 () ;
V_4:
F_6 () ;
F_7 ( 0 , 9 ) ;
return V_3 ;
}
static void T_1 F_8 ( void )
{
int V_3 ;
int V_9 ;
struct V_10 * V_2 ;
T_2 V_11 [] = { V_12 ,
V_13 } ;
V_2 = & V_14 ;
for ( V_9 = 0 ; V_9 < F_9 ( V_11 ) ; V_9 ++ ) {
do {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_15 . V_16 = sizeof( * V_2 ) ;
V_2 -> V_15 . V_17 = 0x80 ;
V_2 -> V_15 . V_18 [ 2 ] = 0x80 ;
V_3 = F_1 ( V_11 [ V_9 ] , V_2 ) ;
} while ( V_3 == - V_19 );
if ( V_3 )
break;
if ( V_2 -> V_15 . V_20 == 0x10 ) {
V_21 = 1 ;
break;
}
if ( V_2 -> V_15 . V_20 != 0x1f0 )
break;
}
}
void T_1 F_10 ( void )
{
struct V_10 * V_2 ;
F_8 () ;
if ( ! V_21 )
return;
V_2 = & V_14 ;
V_22 = V_2 -> V_23 ;
V_24 = V_2 -> V_25 ;
V_26 = V_2 -> V_26 ? V_2 -> V_26 : V_2 -> V_27 ;
V_28 = V_2 -> V_29 ? V_2 -> V_29 : V_2 -> V_30 ;
V_28 <<= 20 ;
}
unsigned long long F_11 ( void )
{
return V_26 ;
}
unsigned long long F_12 ( void )
{
return V_28 ;
}
void T_1 F_13 ( struct V_31 * V_32 )
{
struct V_10 * V_2 ;
if ( ! V_21 )
return;
V_2 = & V_14 ;
V_32 -> V_33 = 1 ;
if ( V_2 -> V_34 & 0x2 )
V_32 -> V_35 = 1 ;
memcpy ( & V_32 -> V_36 , & V_2 -> V_36 , V_37 ) ;
}
static void F_14 ( struct V_38 * V_39 , void * V_40 )
{
struct V_41 * V_41 = V_40 ;
F_15 ( V_41 ) ;
}
static int F_16 ( T_2 V_1 , void * V_2 )
{
struct V_41 V_41 ;
struct V_38 * V_42 ;
int V_3 ;
V_42 = F_17 ( sizeof( * V_42 ) , V_43 ) ;
if ( ! V_42 )
return - V_44 ;
V_42 -> V_45 = V_1 ;
V_42 -> V_2 = V_2 ;
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = F_14 ;
V_42 -> V_49 = & V_41 ;
F_18 ( & V_41 ) ;
V_3 = F_19 ( V_42 ) ;
if ( V_3 )
goto V_4;
F_20 ( & V_41 ) ;
if ( V_42 -> V_46 != V_50 ) {
F_21 ( L_1
L_2 , V_1 , V_42 -> V_46 ) ;
V_3 = - V_51 ;
}
V_4:
F_22 ( V_42 ) ;
return V_3 ;
}
static void F_23 ( struct V_52 * V_32 ,
struct V_53 * V_2 )
{
char * V_54 = ( char * ) V_2 ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_55 = V_2 -> V_56 ;
V_32 -> V_57 = V_2 -> V_58 ;
V_32 -> V_59 = V_2 -> V_56 + V_2 -> V_58 ;
V_32 -> V_60 = V_24 & 0x1 ;
memcpy ( & V_32 -> V_61 , V_54 + V_2 -> V_62 ,
V_32 -> V_59 * sizeof( struct V_63 ) ) ;
}
int F_24 ( struct V_52 * V_32 )
{
int V_3 ;
struct V_53 * V_2 ;
if ( ! V_64 )
return - V_65 ;
V_2 = ( void * ) F_25 ( V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_67 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_15 . V_20 != 0x0010 ) {
F_21 ( L_3 ,
V_2 -> V_15 . V_20 ) ;
V_3 = - V_51 ;
goto V_4;
}
F_23 ( V_32 , V_2 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_27 ( T_2 V_1 )
{
struct V_68 * V_2 ;
int V_3 ;
if ( ! V_69 )
return - V_65 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_15 . V_20 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_21 ( L_4
L_5 , V_1 ,
V_2 -> V_15 . V_20 ) ;
V_3 = - V_51 ;
break;
}
V_4:
F_22 ( V_2 ) ;
return V_3 ;
}
int F_28 ( T_3 V_61 )
{
return F_27 ( V_70 | V_61 << 8 ) ;
}
int F_29 ( T_3 V_61 )
{
return F_27 ( V_71 | V_61 << 8 ) ;
}
int F_30 ( unsigned long V_72 )
{
if ( ! V_28 )
return 0 ;
return F_31 ( V_72 ) >> F_32 ( V_28 ) ;
}
static unsigned long long F_33 ( T_4 V_73 )
{
return ( unsigned long long ) ( V_73 - 1 ) * V_28 ;
}
static int F_34 ( T_2 V_1 , T_4 V_73 )
{
struct V_74 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_25 ( V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = V_75 ;
V_2 -> V_73 = V_73 ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_15 . V_20 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_21 ( L_6
L_7 , V_1 ,
V_2 -> V_15 . V_20 , V_73 ) ;
V_3 = - V_51 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_35 ( T_4 V_73 )
{
return F_34 ( 0x000d0001 , V_73 ) ;
}
static int F_36 ( T_4 V_73 )
{
return F_34 ( 0x000c0001 , V_73 ) ;
}
static int F_37 ( T_3 V_76 )
{
struct V_77 * V_2 ;
int V_3 ;
int V_9 ;
V_2 = ( void * ) F_25 ( V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = V_75 ;
V_3 = F_16 ( 0x00080001 | V_76 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_15 . V_20 ) {
case 0x0020 :
F_38 ( V_76 , V_78 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_79 ; V_9 ++ ) {
if ( V_2 -> V_80 [ V_9 ] )
F_36 ( V_2 -> V_80 [ V_9 ] >> 16 ) ;
}
break;
default:
V_3 = - V_51 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_39 ( unsigned long V_81 , unsigned long V_82 ,
int V_83 )
{
struct V_84 * V_85 ;
unsigned long long V_86 ;
int V_3 = 0 ;
F_40 (incr, &sclp_mem_list, list) {
V_86 = F_33 ( V_85 -> V_73 ) ;
if ( V_81 + V_82 - 1 < V_86 )
break;
if ( V_81 > V_86 + V_28 - 1 )
continue;
if ( V_83 ) {
if ( V_85 -> V_87 ++ )
continue;
V_3 |= F_35 ( V_85 -> V_73 ) ;
} else {
if ( -- V_85 -> V_87 )
continue;
F_36 ( V_85 -> V_73 ) ;
}
}
return V_3 ? - V_51 : 0 ;
}
static int F_41 ( struct V_88 * V_89 ,
unsigned long V_90 , void * V_40 )
{
unsigned long V_81 , V_82 ;
struct V_91 * V_92 ;
unsigned char V_76 ;
int V_3 = 0 ;
V_92 = V_40 ;
V_81 = V_92 -> V_72 << V_93 ;
V_82 = V_92 -> V_94 << V_93 ;
F_42 ( & V_95 ) ;
for ( V_76 = 0 ; V_76 <= V_96 ; V_76 ++ )
if ( ! F_43 ( V_76 , V_78 ) )
F_37 ( V_76 ) ;
switch ( V_90 ) {
case V_97 :
case V_98 :
case V_99 :
break;
case V_100 :
V_3 = F_39 ( V_81 , V_82 , 1 ) ;
break;
case V_101 :
F_39 ( V_81 , V_82 , 0 ) ;
break;
case V_102 :
F_39 ( V_81 , V_82 , 0 ) ;
break;
default:
V_3 = - V_103 ;
break;
}
if ( ! V_3 )
V_104 = 1 ;
F_44 ( & V_95 ) ;
return V_3 ? V_105 : V_106 ;
}
static void T_1 F_45 ( T_4 V_73 )
{
static T_4 V_107 , V_108 ;
unsigned long long V_81 , V_82 ;
if ( V_73 && V_107 && ( V_107 + V_108 == V_73 ) ) {
V_108 ++ ;
return;
}
if ( ! V_107 )
goto V_109;
V_81 = F_33 ( V_107 ) ;
V_82 = ( unsigned long long ) V_108 * V_28 ;
if ( V_81 >= V_110 )
goto V_109;
if ( V_81 + V_82 > V_110 )
V_82 = V_110 - V_81 ;
if ( V_111 && ( V_81 >= V_112 ) )
goto V_109;
if ( V_111 && ( V_81 + V_82 > V_112 ) )
V_82 = V_112 - V_81 ;
F_46 ( 0 , V_81 , V_82 ) ;
V_109:
V_107 = V_73 ;
V_108 = 1 ;
}
static void T_1 F_47 ( void )
{
struct V_84 * V_85 ;
F_40 (incr, &sclp_mem_list, list)
if ( V_85 -> V_57 )
F_45 ( V_85 -> V_73 ) ;
F_45 ( 0 ) ;
}
static void T_1 F_48 ( T_4 V_73 , int V_57 , int V_79 )
{
struct V_84 * V_85 , * V_113 ;
struct V_114 * V_115 ;
T_4 V_116 ;
V_113 = F_17 ( sizeof( * V_113 ) , V_43 ) ;
if ( ! V_113 )
return;
V_113 -> V_73 = V_73 ;
V_113 -> V_57 = V_57 ;
if ( ! V_57 )
V_113 -> V_87 = 1 ;
V_116 = 0 ;
V_115 = & V_117 ;
F_40 (incr, &sclp_mem_list, list) {
if ( V_79 && V_85 -> V_73 > V_73 )
break;
if ( ! V_79 && V_85 -> V_73 - V_116 > 1 )
break;
V_116 = V_85 -> V_73 ;
V_115 = & V_85 -> V_118 ;
}
if ( ! V_79 )
V_113 -> V_73 = V_116 + 1 ;
if ( V_113 -> V_73 > V_26 ) {
F_22 ( V_113 ) ;
return;
}
F_49 ( & V_113 -> V_118 , V_115 ) ;
}
static int F_50 ( struct V_119 * V_120 )
{
if ( ! V_104 )
return 0 ;
F_51 ( L_8 ) ;
return - V_121 ;
}
static int T_1 F_52 ( void )
{
struct V_122 * V_123 ;
struct V_124 * V_2 ;
int V_9 , V_76 , V_79 , V_3 ;
if ( ! V_21 )
return 0 ;
if ( ( V_22 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_44 ;
V_2 = ( void * ) F_53 ( V_43 | V_66 ) ;
if ( ! V_2 )
goto V_4;
V_79 = 0 ;
for ( V_76 = 0 ; V_76 <= V_96 ; V_76 ++ ) {
memset ( V_2 , 0 , V_75 ) ;
V_2 -> V_15 . V_16 = V_75 ;
V_3 = F_16 ( 0x00040001 | V_76 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_15 . V_20 ) {
case 0x0010 :
F_38 ( V_76 , V_78 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_79 ; V_9 ++ ) {
if ( ! V_2 -> V_80 [ V_9 ] )
continue;
V_79 ++ ;
F_48 ( V_2 -> V_80 [ V_9 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_9 = 0 ; V_9 < V_2 -> V_79 ; V_9 ++ ) {
if ( ! V_2 -> V_80 [ V_9 ] )
continue;
V_79 ++ ;
F_48 ( V_2 -> V_80 [ V_9 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_51 ;
break;
}
if ( ! V_3 )
V_96 = V_2 -> V_125 ;
}
if ( V_3 || F_54 ( & V_117 ) )
goto V_4;
for ( V_9 = 1 ; V_9 <= V_26 - V_79 ; V_9 ++ )
F_48 ( 0 , 1 , 0 ) ;
V_3 = F_55 ( & V_126 ) ;
if ( V_3 )
goto V_4;
V_3 = F_56 ( & V_127 ) ;
if ( V_3 )
goto V_4;
V_123 = F_57 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_58 ( V_123 ) ? F_59 ( V_123 ) : 0 ;
if ( V_3 )
goto V_128;
F_47 () ;
goto V_4;
V_128:
F_60 ( & V_127 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_61 ( T_2 V_1 )
{
struct V_129 * V_2 ;
int V_3 ;
if ( ! V_130 )
return - V_65 ;
V_2 = (struct V_129 * ) F_25 ( V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_15 . V_20 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_21 ( L_10
L_11 , V_1 ,
V_2 -> V_15 . V_20 ) ;
V_3 = - V_51 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_62 ( struct V_131 V_132 )
{
return F_61 ( V_133 | V_132 . V_76 << 8 ) ;
}
int F_63 ( struct V_131 V_132 )
{
return F_61 ( V_134 | V_132 . V_76 << 8 ) ;
}
int F_64 ( struct V_135 * V_32 )
{
struct V_136 * V_2 ;
int V_3 ;
if ( ! V_137 )
return - V_65 ;
V_2 = (struct V_136 * ) F_25 ( V_43 | V_66 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_15 . V_16 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_138 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_15 . V_20 != 0x0010 ) {
F_21 ( L_12
L_13 , V_2 -> V_15 . V_20 ) ;
V_3 = - V_51 ;
goto V_4;
}
memcpy ( V_32 -> V_139 , V_2 -> V_139 , V_140 ) ;
memcpy ( V_32 -> V_57 , V_2 -> V_57 , V_140 ) ;
memcpy ( V_32 -> V_55 , V_2 -> V_55 , V_140 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
