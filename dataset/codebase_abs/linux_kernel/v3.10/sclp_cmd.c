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
if ( V_2 -> V_33 & 0x02 )
V_34 . V_35 |= V_36 ;
V_37 = V_2 -> V_37 ? V_2 -> V_37 : V_2 -> V_38 ;
V_39 = V_2 -> V_40 ? V_2 -> V_40 : V_2 -> V_41 ;
V_39 <<= 20 ;
F_10 () ;
}
bool T_1 F_12 ( void )
{
struct V_24 * V_2 = & V_25 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_42 & ( V_43 | V_44 ) )
return 1 ;
return 0 ;
}
bool T_1 F_13 ( void )
{
struct V_24 * V_2 = & V_25 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_42 & V_45 )
return 1 ;
return 0 ;
}
unsigned long long F_14 ( void )
{
return V_37 ;
}
unsigned long long F_15 ( void )
{
return V_39 ;
}
void T_1 F_16 ( struct V_46 * V_47 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_47 -> V_48 = 1 ;
if ( V_2 -> V_49 & 0x2 )
V_47 -> V_50 = 1 ;
memcpy ( & V_47 -> V_51 , & V_2 -> V_51 , V_52 ) ;
}
static void F_17 ( struct V_53 * V_54 , void * V_55 )
{
struct V_56 * V_56 = V_55 ;
F_18 ( V_56 ) ;
}
static int F_19 ( T_2 V_1 , void * V_2 )
{
struct V_56 V_56 ;
struct V_53 * V_57 ;
int V_3 ;
V_57 = F_20 ( sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
V_57 -> V_60 = V_1 ;
V_57 -> V_2 = V_2 ;
V_57 -> V_61 = V_62 ;
V_57 -> V_63 = F_17 ;
V_57 -> V_64 = & V_56 ;
F_21 ( & V_56 ) ;
V_3 = F_22 ( V_57 ) ;
if ( V_3 )
goto V_4;
F_23 ( & V_56 ) ;
if ( V_57 -> V_61 != V_65 ) {
F_24 ( L_1
L_2 , V_1 , V_57 -> V_61 ) ;
V_3 = - V_66 ;
}
V_4:
F_25 ( V_57 ) ;
return V_3 ;
}
static void F_26 ( struct V_67 * V_47 ,
struct V_68 * V_2 )
{
char * V_69 = ( char * ) V_2 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_70 = V_2 -> V_71 ;
V_47 -> V_72 = V_2 -> V_73 ;
V_47 -> V_74 = V_2 -> V_71 + V_2 -> V_73 ;
V_47 -> V_75 = V_31 & 0x1 ;
memcpy ( & V_47 -> V_76 , V_69 + V_2 -> V_77 ,
V_47 -> V_74 * sizeof( struct V_78 ) ) ;
}
int F_27 ( struct V_67 * V_47 )
{
int V_3 ;
struct V_68 * V_2 ;
if ( ! V_79 )
return - V_80 ;
V_2 = ( void * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_82 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_24 ( L_3 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_66 ;
goto V_4;
}
F_26 ( V_47 , V_2 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_30 ( T_2 V_1 )
{
struct V_83 * V_2 ;
int V_3 ;
if ( ! V_84 )
return - V_80 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_24 ( L_4
L_5 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_66 ;
break;
}
V_4:
F_25 ( V_2 ) ;
return V_3 ;
}
int F_31 ( T_3 V_76 )
{
return F_30 ( V_85 | V_76 << 8 ) ;
}
int F_32 ( T_3 V_76 )
{
return F_30 ( V_86 | V_76 << 8 ) ;
}
int F_33 ( unsigned long V_87 )
{
if ( ! V_39 )
return 0 ;
return F_34 ( V_87 ) >> F_35 ( V_39 ) ;
}
static unsigned long long F_36 ( T_4 V_88 )
{
return ( unsigned long long ) ( V_88 - 1 ) * V_39 ;
}
static int F_37 ( T_2 V_1 , T_4 V_88 )
{
struct V_89 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = V_90 ;
V_2 -> V_88 = V_88 ;
V_3 = F_19 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_24 ( L_6
L_7 , V_1 ,
V_2 -> V_17 . V_22 , V_88 ) ;
V_3 = - V_66 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_38 ( T_4 V_88 )
{
unsigned long long V_91 ;
int V_3 ;
V_3 = F_37 ( 0x000d0001 , V_88 ) ;
if ( V_3 )
return V_3 ;
V_91 = F_36 ( V_88 ) ;
F_39 ( V_91 , V_91 + V_39 ) ;
return 0 ;
}
static int F_40 ( T_4 V_88 )
{
return F_37 ( 0x000c0001 , V_88 ) ;
}
static int F_41 ( T_3 V_92 )
{
struct V_93 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = V_90 ;
V_3 = F_19 ( 0x00080001 | V_92 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_42 ( V_92 , V_94 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( V_2 -> V_96 [ V_11 ] )
F_40 ( V_2 -> V_96 [ V_11 ] >> 16 ) ;
}
break;
default:
V_3 = - V_66 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_43 ( unsigned long V_91 , unsigned long V_97 ,
int V_98 )
{
struct V_99 * V_100 ;
unsigned long long V_101 ;
int V_3 = 0 ;
F_44 (incr, &sclp_mem_list, list) {
V_101 = F_36 ( V_100 -> V_88 ) ;
if ( V_91 + V_97 - 1 < V_101 )
break;
if ( V_91 > V_101 + V_39 - 1 )
continue;
if ( V_98 )
V_3 |= F_38 ( V_100 -> V_88 ) ;
else
F_40 ( V_100 -> V_88 ) ;
}
return V_3 ? - V_66 : 0 ;
}
static int F_45 ( struct V_102 * V_103 ,
unsigned long V_104 , void * V_55 )
{
unsigned long V_91 , V_97 ;
struct V_105 * V_106 ;
unsigned char V_92 ;
int V_3 = 0 ;
V_106 = V_55 ;
V_91 = V_106 -> V_87 << V_107 ;
V_97 = V_106 -> V_108 << V_107 ;
F_46 ( & V_109 ) ;
F_47 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_41 ( V_92 ) ;
switch ( V_104 ) {
case V_110 :
case V_111 :
case V_112 :
break;
case V_113 :
V_3 = F_43 ( V_91 , V_97 , 1 ) ;
break;
case V_114 :
F_43 ( V_91 , V_97 , 0 ) ;
break;
case V_115 :
F_43 ( V_91 , V_97 , 0 ) ;
break;
default:
V_3 = - V_116 ;
break;
}
if ( ! V_3 )
V_117 = 1 ;
F_48 ( & V_109 ) ;
return V_3 ? V_118 : V_119 ;
}
static void T_1 F_49 ( T_4 V_88 )
{
static T_4 V_120 , V_121 ;
unsigned long long V_91 , V_97 ;
if ( V_88 && V_120 && ( V_120 + V_121 == V_88 ) ) {
V_121 ++ ;
return;
}
if ( ! V_120 )
goto V_122;
V_91 = F_36 ( V_120 ) ;
V_97 = ( unsigned long long ) V_121 * V_39 ;
if ( V_91 >= V_123 )
goto V_122;
if ( V_91 + V_97 > V_123 )
V_97 = V_123 - V_91 ;
if ( V_124 && ( V_91 >= V_125 ) )
goto V_122;
if ( V_124 && ( V_91 + V_97 > V_125 ) )
V_97 = V_125 - V_91 ;
F_50 ( 0 , V_91 , V_97 ) ;
V_122:
V_120 = V_88 ;
V_121 = 1 ;
}
static void T_1 F_51 ( void )
{
struct V_99 * V_100 ;
F_44 (incr, &sclp_mem_list, list)
if ( V_100 -> V_72 )
F_49 ( V_100 -> V_88 ) ;
F_49 ( 0 ) ;
}
static void T_1 F_52 ( T_4 V_88 , int V_72 , int V_95 )
{
struct V_99 * V_100 , * V_126 ;
struct V_127 * V_128 ;
T_4 V_129 ;
V_126 = F_20 ( sizeof( * V_126 ) , V_58 ) ;
if ( ! V_126 )
return;
V_126 -> V_88 = V_88 ;
V_126 -> V_72 = V_72 ;
V_129 = 0 ;
V_128 = & V_130 ;
F_44 (incr, &sclp_mem_list, list) {
if ( V_95 && V_100 -> V_88 > V_88 )
break;
if ( ! V_95 && V_100 -> V_88 - V_129 > 1 )
break;
V_129 = V_100 -> V_88 ;
V_128 = & V_100 -> V_131 ;
}
if ( ! V_95 )
V_126 -> V_88 = V_129 + 1 ;
if ( V_126 -> V_88 > V_37 ) {
F_25 ( V_126 ) ;
return;
}
F_53 ( & V_126 -> V_131 , V_128 ) ;
}
static int F_54 ( struct V_132 * V_133 )
{
if ( ! V_117 )
return 0 ;
F_55 ( L_8 ) ;
return - V_134 ;
}
static int T_1 F_56 ( void )
{
struct V_135 * V_136 ;
struct V_137 * V_2 ;
int V_11 , V_92 , V_95 , V_3 ;
if ( V_138 )
return 0 ;
if ( ! V_23 )
return 0 ;
if ( ( V_29 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_59 ;
V_2 = ( void * ) F_57 ( V_58 | V_81 ) ;
if ( ! V_2 )
goto V_4;
V_95 = 0 ;
for ( V_92 = 0 ; V_92 <= V_139 ; V_92 ++ ) {
memset ( V_2 , 0 , V_90 ) ;
V_2 -> V_17 . V_18 = V_90 ;
V_3 = F_19 ( 0x00040001 | V_92 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_42 ( V_92 , V_94 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( ! V_2 -> V_96 [ V_11 ] )
continue;
V_95 ++ ;
F_52 ( V_2 -> V_96 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_95 ; V_11 ++ ) {
if ( ! V_2 -> V_96 [ V_11 ] )
continue;
V_95 ++ ;
F_52 ( V_2 -> V_96 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_66 ;
break;
}
if ( ! V_3 )
V_139 = V_2 -> V_140 ;
}
if ( V_3 || F_58 ( & V_130 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_37 - V_95 ; V_11 ++ )
F_52 ( 0 , 1 , 0 ) ;
V_3 = F_59 ( & V_141 ) ;
if ( V_3 )
goto V_4;
V_3 = F_60 ( & V_142 ) ;
if ( V_3 )
goto V_4;
V_136 = F_61 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_62 ( V_136 ) ? F_63 ( V_136 ) : 0 ;
if ( V_3 )
goto V_143;
F_51 () ;
goto V_4;
V_143:
F_64 ( & V_142 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_65 ( T_2 V_1 , T_5 V_144 )
{
struct V_145 * V_2 ;
int V_3 ;
if ( ! V_146 )
return - V_80 ;
V_2 = (struct V_145 * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = V_90 ;
V_2 -> V_147 = V_148 ;
V_2 -> V_149 = V_144 ;
V_3 = F_19 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_66 ( L_10 ,
V_1 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_66 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_67 ( T_5 V_144 )
{
return F_65 ( V_150 , V_144 ) ;
}
int F_68 ( T_5 V_144 )
{
return F_65 ( V_151 , V_144 ) ;
}
static int F_69 ( T_2 V_1 )
{
struct V_152 * V_2 ;
int V_3 ;
if ( ! V_153 )
return - V_80 ;
V_2 = (struct V_152 * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_24 ( L_11
L_12 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_66 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_70 ( struct V_154 V_155 )
{
return F_69 ( V_156 | V_155 . V_92 << 8 ) ;
}
int F_71 ( struct V_154 V_155 )
{
return F_69 ( V_157 | V_155 . V_92 << 8 ) ;
}
int F_72 ( struct V_158 * V_47 )
{
struct V_159 * V_2 ;
int V_3 ;
if ( ! V_160 )
return - V_80 ;
V_2 = (struct V_159 * ) F_28 ( V_58 | V_81 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_161 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_24 ( L_13
L_14 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_66 ;
goto V_4;
}
memcpy ( V_47 -> V_162 , V_2 -> V_162 , V_163 ) ;
memcpy ( V_47 -> V_72 , V_2 -> V_72 , V_163 ) ;
memcpy ( V_47 -> V_70 , V_2 -> V_70 , V_163 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
