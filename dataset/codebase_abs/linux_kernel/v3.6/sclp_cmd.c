static int T_1 F_1 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
F_2 ( 0 , 9 ) ;
V_3 = F_3 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
F_4 ( V_5 | V_6 | V_7 |
V_8 | V_9 | V_10 ) ;
F_5 () ;
V_4:
F_6 () ;
F_7 ( 0 , 9 ) ;
return V_3 ;
}
static void T_1 F_8 ( void )
{
int V_3 ;
int V_11 ;
struct V_12 * V_2 ;
T_2 V_13 [] = { V_14 ,
V_15 } ;
V_2 = & V_16 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_13 ) ; V_11 ++ ) {
do {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_17 . V_19 = 0x80 ;
V_2 -> V_17 . V_20 [ 2 ] = 0x80 ;
V_3 = F_1 ( V_13 [ V_11 ] , V_2 ) ;
} while ( V_3 == - V_21 );
if ( V_3 )
break;
if ( V_2 -> V_17 . V_22 == 0x10 ) {
V_23 = 1 ;
break;
}
if ( V_2 -> V_17 . V_22 != 0x1f0 )
break;
}
}
static void T_1 F_10 ( void )
{
struct V_24 * V_2 = & V_25 ;
int V_3 ;
do {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_26 = sizeof( V_27 ) ;
V_3 = F_1 ( V_28 , V_2 ) ;
} while ( V_3 == - V_21 );
}
void T_1 F_11 ( void )
{
struct V_12 * V_2 ;
F_8 () ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_29 = V_2 -> V_30 ;
V_31 = V_2 -> V_32 ;
V_33 = V_2 -> V_34 ;
V_35 = V_2 -> V_35 ? V_2 -> V_35 : V_2 -> V_36 ;
V_37 = V_2 -> V_38 ? V_2 -> V_38 : V_2 -> V_39 ;
V_37 <<= 20 ;
F_10 () ;
}
bool T_1 F_12 ( void )
{
struct V_24 * V_2 = & V_25 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_40 & ( V_41 | V_42 ) )
return 1 ;
return 0 ;
}
bool T_1 F_13 ( void )
{
struct V_24 * V_2 = & V_25 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_40 & V_43 )
return 1 ;
return 0 ;
}
unsigned long long F_14 ( void )
{
return V_35 ;
}
unsigned long long F_15 ( void )
{
return V_37 ;
}
T_3 F_16 ( void )
{
return V_33 ;
}
void T_1 F_17 ( struct V_44 * V_45 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_45 -> V_46 = 1 ;
if ( V_2 -> V_47 & 0x2 )
V_45 -> V_48 = 1 ;
memcpy ( & V_45 -> V_49 , & V_2 -> V_49 , V_50 ) ;
}
static void F_18 ( struct V_51 * V_52 , void * V_53 )
{
struct V_54 * V_54 = V_53 ;
F_19 ( V_54 ) ;
}
static int F_20 ( T_2 V_1 , void * V_2 )
{
struct V_54 V_54 ;
struct V_51 * V_55 ;
int V_3 ;
V_55 = F_21 ( sizeof( * V_55 ) , V_56 ) ;
if ( ! V_55 )
return - V_57 ;
V_55 -> V_58 = V_1 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_59 = V_60 ;
V_55 -> V_61 = F_18 ;
V_55 -> V_62 = & V_54 ;
F_22 ( & V_54 ) ;
V_3 = F_23 ( V_55 ) ;
if ( V_3 )
goto V_4;
F_24 ( & V_54 ) ;
if ( V_55 -> V_59 != V_63 ) {
F_25 ( L_1
L_2 , V_1 , V_55 -> V_59 ) ;
V_3 = - V_64 ;
}
V_4:
F_26 ( V_55 ) ;
return V_3 ;
}
static void F_27 ( struct V_65 * V_45 ,
struct V_66 * V_2 )
{
char * V_67 = ( char * ) V_2 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_68 = V_2 -> V_69 ;
V_45 -> V_70 = V_2 -> V_71 ;
V_45 -> V_72 = V_2 -> V_69 + V_2 -> V_71 ;
V_45 -> V_73 = V_31 & 0x1 ;
memcpy ( & V_45 -> V_74 , V_67 + V_2 -> V_75 ,
V_45 -> V_72 * sizeof( struct V_76 ) ) ;
}
int F_28 ( struct V_65 * V_45 )
{
int V_3 ;
struct V_66 * V_2 ;
if ( ! V_77 )
return - V_78 ;
V_2 = ( void * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_20 ( V_80 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_25 ( L_3 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
goto V_4;
}
F_27 ( V_45 , V_2 ) ;
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_31 ( T_2 V_1 )
{
struct V_81 * V_2 ;
int V_3 ;
if ( ! V_82 )
return - V_78 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_20 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_25 ( L_4
L_5 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
break;
}
V_4:
F_26 ( V_2 ) ;
return V_3 ;
}
int F_32 ( T_3 V_74 )
{
return F_31 ( V_83 | V_74 << 8 ) ;
}
int F_33 ( T_3 V_74 )
{
return F_31 ( V_84 | V_74 << 8 ) ;
}
int F_34 ( unsigned long V_85 )
{
if ( ! V_37 )
return 0 ;
return F_35 ( V_85 ) >> F_36 ( V_37 ) ;
}
static unsigned long long F_37 ( T_4 V_86 )
{
return ( unsigned long long ) ( V_86 - 1 ) * V_37 ;
}
static int F_38 ( T_2 V_1 , T_4 V_86 )
{
struct V_87 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = V_88 ;
V_2 -> V_86 = V_86 ;
V_3 = F_20 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_25 ( L_6
L_7 , V_1 ,
V_2 -> V_17 . V_22 , V_86 ) ;
V_3 = - V_64 ;
break;
}
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_39 ( T_4 V_86 )
{
unsigned long long V_89 , V_90 ;
int V_3 ;
V_3 = F_38 ( 0x000d0001 , V_86 ) ;
if ( V_3 )
goto V_4;
V_89 = V_90 = F_37 ( V_86 ) ;
for (; V_90 < V_89 + V_37 ; V_90 += V_88 )
F_40 ( V_90 , V_91 , 0 ) ;
V_4:
return V_3 ;
}
static int F_41 ( T_4 V_86 )
{
return F_38 ( 0x000c0001 , V_86 ) ;
}
static int F_42 ( T_3 V_92 )
{
struct V_93 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = V_88 ;
V_3 = F_20 ( 0x00080001 | V_92 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_43 ( V_92 , V_94 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( V_2 -> V_96 [ V_11 ] )
F_41 ( V_2 -> V_96 [ V_11 ] >> 16 ) ;
}
break;
default:
V_3 = - V_64 ;
break;
}
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_44 ( unsigned long V_89 , unsigned long V_97 ,
int V_98 )
{
struct V_99 * V_100 ;
unsigned long long V_101 ;
int V_3 = 0 ;
F_45 (incr, &sclp_mem_list, list) {
V_101 = F_37 ( V_100 -> V_86 ) ;
if ( V_89 + V_97 - 1 < V_101 )
break;
if ( V_89 > V_101 + V_37 - 1 )
continue;
if ( V_98 ) {
if ( V_100 -> V_102 ++ )
continue;
V_3 |= F_39 ( V_100 -> V_86 ) ;
} else {
if ( -- V_100 -> V_102 )
continue;
F_41 ( V_100 -> V_86 ) ;
}
}
return V_3 ? - V_64 : 0 ;
}
static int F_46 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_53 )
{
unsigned long V_89 , V_97 ;
struct V_106 * V_107 ;
unsigned char V_92 ;
int V_3 = 0 ;
V_107 = V_53 ;
V_89 = V_107 -> V_85 << V_108 ;
V_97 = V_107 -> V_109 << V_108 ;
F_47 ( & V_110 ) ;
F_48 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_42 ( V_92 ) ;
switch ( V_105 ) {
case V_111 :
case V_112 :
case V_113 :
break;
case V_114 :
V_3 = F_44 ( V_89 , V_97 , 1 ) ;
break;
case V_115 :
F_44 ( V_89 , V_97 , 0 ) ;
break;
case V_116 :
F_44 ( V_89 , V_97 , 0 ) ;
break;
default:
V_3 = - V_117 ;
break;
}
if ( ! V_3 )
V_118 = 1 ;
F_49 ( & V_110 ) ;
return V_3 ? V_119 : V_120 ;
}
static void T_1 F_50 ( T_4 V_86 )
{
static T_4 V_121 , V_122 ;
unsigned long long V_89 , V_97 ;
if ( V_86 && V_121 && ( V_121 + V_122 == V_86 ) ) {
V_122 ++ ;
return;
}
if ( ! V_121 )
goto V_123;
V_89 = F_37 ( V_121 ) ;
V_97 = ( unsigned long long ) V_122 * V_37 ;
if ( V_89 >= V_124 )
goto V_123;
if ( V_89 + V_97 > V_124 )
V_97 = V_124 - V_89 ;
if ( V_125 && ( V_89 >= V_126 ) )
goto V_123;
if ( V_125 && ( V_89 + V_97 > V_126 ) )
V_97 = V_126 - V_89 ;
F_51 ( 0 , V_89 , V_97 ) ;
V_123:
V_121 = V_86 ;
V_122 = 1 ;
}
static void T_1 F_52 ( void )
{
struct V_99 * V_100 ;
F_45 (incr, &sclp_mem_list, list)
if ( V_100 -> V_70 )
F_50 ( V_100 -> V_86 ) ;
F_50 ( 0 ) ;
}
static void T_1 F_53 ( T_4 V_86 , int V_70 , int V_95 )
{
struct V_99 * V_100 , * V_127 ;
struct V_128 * V_129 ;
T_4 V_130 ;
V_127 = F_21 ( sizeof( * V_127 ) , V_56 ) ;
if ( ! V_127 )
return;
V_127 -> V_86 = V_86 ;
V_127 -> V_70 = V_70 ;
if ( ! V_70 )
V_127 -> V_102 = 1 ;
V_130 = 0 ;
V_129 = & V_131 ;
F_45 (incr, &sclp_mem_list, list) {
if ( V_95 && V_100 -> V_86 > V_86 )
break;
if ( ! V_95 && V_100 -> V_86 - V_130 > 1 )
break;
V_130 = V_100 -> V_86 ;
V_129 = & V_100 -> V_132 ;
}
if ( ! V_95 )
V_127 -> V_86 = V_130 + 1 ;
if ( V_127 -> V_86 > V_35 ) {
F_26 ( V_127 ) ;
return;
}
F_54 ( & V_127 -> V_132 , V_129 ) ;
}
static int F_55 ( struct V_133 * V_134 )
{
if ( ! V_118 )
return 0 ;
F_56 ( L_8 ) ;
return - V_135 ;
}
static int T_1 F_57 ( void )
{
struct V_136 * V_137 ;
struct V_138 * V_2 ;
int V_11 , V_92 , V_95 , V_3 ;
if ( ! V_23 )
return 0 ;
if ( ( V_29 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_57 ;
V_2 = ( void * ) F_58 ( V_56 | V_79 ) ;
if ( ! V_2 )
goto V_4;
V_95 = 0 ;
for ( V_92 = 0 ; V_92 <= V_139 ; V_92 ++ ) {
memset ( V_2 , 0 , V_88 ) ;
V_2 -> V_17 . V_18 = V_88 ;
V_3 = F_20 ( 0x00040001 | V_92 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_43 ( V_92 , V_94 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( ! V_2 -> V_96 [ V_11 ] )
continue;
V_95 ++ ;
F_53 ( V_2 -> V_96 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( ! V_2 -> V_96 [ V_11 ] )
continue;
V_95 ++ ;
F_53 ( V_2 -> V_96 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_64 ;
break;
}
if ( ! V_3 )
V_139 = V_2 -> V_140 ;
}
if ( V_3 || F_59 ( & V_131 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_35 - V_95 ; V_11 ++ )
F_53 ( 0 , 1 , 0 ) ;
V_3 = F_60 ( & V_141 ) ;
if ( V_3 )
goto V_4;
V_3 = F_61 ( & V_142 ) ;
if ( V_3 )
goto V_4;
V_137 = F_62 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_63 ( V_137 ) ? F_64 ( V_137 ) : 0 ;
if ( V_3 )
goto V_143;
F_52 () ;
goto V_4;
V_143:
F_65 ( & V_142 ) ;
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_66 ( T_2 V_1 )
{
struct V_144 * V_2 ;
int V_3 ;
if ( ! V_145 )
return - V_78 ;
V_2 = (struct V_144 * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_20 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_25 ( L_10
L_11 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
break;
}
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_67 ( struct V_146 V_147 )
{
return F_66 ( V_148 | V_147 . V_92 << 8 ) ;
}
int F_68 ( struct V_146 V_147 )
{
return F_66 ( V_149 | V_147 . V_92 << 8 ) ;
}
int F_69 ( struct V_150 * V_45 )
{
struct V_151 * V_2 ;
int V_3 ;
if ( ! V_152 )
return - V_78 ;
V_2 = (struct V_151 * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_20 ( V_153 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_25 ( L_12
L_13 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
goto V_4;
}
memcpy ( V_45 -> V_154 , V_2 -> V_154 , V_155 ) ;
memcpy ( V_45 -> V_70 , V_2 -> V_70 , V_155 ) ;
memcpy ( V_45 -> V_68 , V_2 -> V_68 , V_155 ) ;
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
