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
unsigned long long V_89 ;
int V_3 ;
V_3 = F_38 ( 0x000d0001 , V_86 ) ;
if ( V_3 )
return V_3 ;
V_89 = F_37 ( V_86 ) ;
F_40 ( V_89 , V_89 + V_37 ) ;
return 0 ;
}
static int F_41 ( T_4 V_86 )
{
return F_38 ( 0x000c0001 , V_86 ) ;
}
static int F_42 ( T_3 V_90 )
{
struct V_91 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = V_88 ;
V_3 = F_20 ( 0x00080001 | V_90 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_43 ( V_90 , V_92 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_93 ; V_11 ++ ) {
if ( V_2 -> V_94 [ V_11 ] )
F_41 ( V_2 -> V_94 [ V_11 ] >> 16 ) ;
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
static int F_44 ( unsigned long V_89 , unsigned long V_95 ,
int V_96 )
{
struct V_97 * V_98 ;
unsigned long long V_99 ;
int V_3 = 0 ;
F_45 (incr, &sclp_mem_list, list) {
V_99 = F_37 ( V_98 -> V_86 ) ;
if ( V_89 + V_95 - 1 < V_99 )
break;
if ( V_89 > V_99 + V_37 - 1 )
continue;
if ( V_96 ) {
if ( V_98 -> V_100 ++ )
continue;
V_3 |= F_39 ( V_98 -> V_86 ) ;
} else {
if ( -- V_98 -> V_100 )
continue;
F_41 ( V_98 -> V_86 ) ;
}
}
return V_3 ? - V_64 : 0 ;
}
static int F_46 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_53 )
{
unsigned long V_89 , V_95 ;
struct V_104 * V_105 ;
unsigned char V_90 ;
int V_3 = 0 ;
V_105 = V_53 ;
V_89 = V_105 -> V_85 << V_106 ;
V_95 = V_105 -> V_107 << V_106 ;
F_47 ( & V_108 ) ;
F_48 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_42 ( V_90 ) ;
switch ( V_103 ) {
case V_109 :
case V_110 :
case V_111 :
break;
case V_112 :
V_3 = F_44 ( V_89 , V_95 , 1 ) ;
break;
case V_113 :
F_44 ( V_89 , V_95 , 0 ) ;
break;
case V_114 :
F_44 ( V_89 , V_95 , 0 ) ;
break;
default:
V_3 = - V_115 ;
break;
}
if ( ! V_3 )
V_116 = 1 ;
F_49 ( & V_108 ) ;
return V_3 ? V_117 : V_118 ;
}
static void T_1 F_50 ( T_4 V_86 )
{
static T_4 V_119 , V_120 ;
unsigned long long V_89 , V_95 ;
if ( V_86 && V_119 && ( V_119 + V_120 == V_86 ) ) {
V_120 ++ ;
return;
}
if ( ! V_119 )
goto V_121;
V_89 = F_37 ( V_119 ) ;
V_95 = ( unsigned long long ) V_120 * V_37 ;
if ( V_89 >= V_122 )
goto V_121;
if ( V_89 + V_95 > V_122 )
V_95 = V_122 - V_89 ;
if ( V_123 && ( V_89 >= V_124 ) )
goto V_121;
if ( V_123 && ( V_89 + V_95 > V_124 ) )
V_95 = V_124 - V_89 ;
F_51 ( 0 , V_89 , V_95 ) ;
V_121:
V_119 = V_86 ;
V_120 = 1 ;
}
static void T_1 F_52 ( void )
{
struct V_97 * V_98 ;
F_45 (incr, &sclp_mem_list, list)
if ( V_98 -> V_70 )
F_50 ( V_98 -> V_86 ) ;
F_50 ( 0 ) ;
}
static void T_1 F_53 ( T_4 V_86 , int V_70 , int V_93 )
{
struct V_97 * V_98 , * V_125 ;
struct V_126 * V_127 ;
T_4 V_128 ;
V_125 = F_21 ( sizeof( * V_125 ) , V_56 ) ;
if ( ! V_125 )
return;
V_125 -> V_86 = V_86 ;
V_125 -> V_70 = V_70 ;
if ( ! V_70 )
V_125 -> V_100 = 1 ;
V_128 = 0 ;
V_127 = & V_129 ;
F_45 (incr, &sclp_mem_list, list) {
if ( V_93 && V_98 -> V_86 > V_86 )
break;
if ( ! V_93 && V_98 -> V_86 - V_128 > 1 )
break;
V_128 = V_98 -> V_86 ;
V_127 = & V_98 -> V_130 ;
}
if ( ! V_93 )
V_125 -> V_86 = V_128 + 1 ;
if ( V_125 -> V_86 > V_35 ) {
F_26 ( V_125 ) ;
return;
}
F_54 ( & V_125 -> V_130 , V_127 ) ;
}
static int F_55 ( struct V_131 * V_132 )
{
if ( ! V_116 )
return 0 ;
F_56 ( L_8 ) ;
return - V_133 ;
}
static int T_1 F_57 ( void )
{
struct V_134 * V_135 ;
struct V_136 * V_2 ;
int V_11 , V_90 , V_93 , V_3 ;
if ( ! V_23 )
return 0 ;
if ( ( V_29 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_57 ;
V_2 = ( void * ) F_58 ( V_56 | V_79 ) ;
if ( ! V_2 )
goto V_4;
V_93 = 0 ;
for ( V_90 = 0 ; V_90 <= V_137 ; V_90 ++ ) {
memset ( V_2 , 0 , V_88 ) ;
V_2 -> V_17 . V_18 = V_88 ;
V_3 = F_20 ( 0x00040001 | V_90 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_43 ( V_90 , V_92 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_93 ; V_11 ++ ) {
if ( ! V_2 -> V_94 [ V_11 ] )
continue;
V_93 ++ ;
F_53 ( V_2 -> V_94 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_93 ; V_11 ++ ) {
if ( ! V_2 -> V_94 [ V_11 ] )
continue;
V_93 ++ ;
F_53 ( V_2 -> V_94 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_64 ;
break;
}
if ( ! V_3 )
V_137 = V_2 -> V_138 ;
}
if ( V_3 || F_59 ( & V_129 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_35 - V_93 ; V_11 ++ )
F_53 ( 0 , 1 , 0 ) ;
V_3 = F_60 ( & V_139 ) ;
if ( V_3 )
goto V_4;
V_3 = F_61 ( & V_140 ) ;
if ( V_3 )
goto V_4;
V_135 = F_62 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_63 ( V_135 ) ? F_64 ( V_135 ) : 0 ;
if ( V_3 )
goto V_141;
F_52 () ;
goto V_4;
V_141:
F_65 ( & V_140 ) ;
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_66 ( T_2 V_1 , T_5 V_142 )
{
struct V_143 * V_2 ;
int V_3 ;
if ( ! V_144 )
return - V_78 ;
V_2 = (struct V_143 * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = V_88 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_147 = V_142 ;
V_3 = F_20 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_67 ( L_10 ,
V_1 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
break;
}
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_68 ( T_5 V_142 )
{
return F_66 ( V_148 , V_142 ) ;
}
int F_69 ( T_5 V_142 )
{
return F_66 ( V_149 , V_142 ) ;
}
static int F_70 ( T_2 V_1 )
{
struct V_150 * V_2 ;
int V_3 ;
if ( ! V_151 )
return - V_78 ;
V_2 = (struct V_150 * ) F_29 ( V_56 | V_79 ) ;
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
F_25 ( L_11
L_12 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
break;
}
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_71 ( struct V_152 V_153 )
{
return F_70 ( V_154 | V_153 . V_90 << 8 ) ;
}
int F_72 ( struct V_152 V_153 )
{
return F_70 ( V_155 | V_153 . V_90 << 8 ) ;
}
int F_73 ( struct V_156 * V_45 )
{
struct V_157 * V_2 ;
int V_3 ;
if ( ! V_158 )
return - V_78 ;
V_2 = (struct V_157 * ) F_29 ( V_56 | V_79 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_20 ( V_159 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_25 ( L_13
L_14 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_64 ;
goto V_4;
}
memcpy ( V_45 -> V_160 , V_2 -> V_160 , V_161 ) ;
memcpy ( V_45 -> V_70 , V_2 -> V_70 , V_161 ) ;
memcpy ( V_45 -> V_68 , V_2 -> V_68 , V_161 ) ;
V_4:
F_30 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
