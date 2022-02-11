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
if ( ! ( V_2 -> V_42 & ( V_43 | V_44 ) ) )
return 0 ;
if ( ! ( V_2 -> V_45 & ( V_46 | V_44 ) ) )
return 0 ;
return 1 ;
}
bool T_1 F_13 ( void )
{
struct V_24 * V_2 = & V_25 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_42 & V_47 )
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
void T_1 F_16 ( struct V_48 * V_49 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_49 -> V_50 = 1 ;
if ( V_2 -> V_51 & 0x2 )
V_49 -> V_52 = 1 ;
memcpy ( & V_49 -> V_53 , & V_2 -> V_53 , V_54 ) ;
}
static void F_17 ( struct V_55 * V_56 , void * V_57 )
{
struct V_58 * V_58 = V_57 ;
F_18 ( V_58 ) ;
}
int F_19 ( T_2 V_1 , void * V_2 )
{
struct V_58 V_58 ;
struct V_55 * V_59 ;
int V_3 ;
V_59 = F_20 ( sizeof( * V_59 ) , V_60 ) ;
if ( ! V_59 )
return - V_61 ;
V_59 -> V_62 = V_1 ;
V_59 -> V_2 = V_2 ;
V_59 -> V_63 = V_64 ;
V_59 -> V_65 = F_17 ;
V_59 -> V_66 = & V_58 ;
F_21 ( & V_58 ) ;
V_3 = F_22 ( V_59 ) ;
if ( V_3 )
goto V_4;
F_23 ( & V_58 ) ;
if ( V_59 -> V_63 != V_67 ) {
F_24 ( L_1
L_2 , V_1 , V_59 -> V_63 ) ;
V_3 = - V_68 ;
}
V_4:
F_25 ( V_59 ) ;
return V_3 ;
}
static void F_26 ( struct V_69 * V_49 ,
struct V_70 * V_2 )
{
char * V_71 = ( char * ) V_2 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_72 = V_2 -> V_73 ;
V_49 -> V_74 = V_2 -> V_75 ;
V_49 -> V_76 = V_2 -> V_73 + V_2 -> V_75 ;
V_49 -> V_77 = V_31 & 0x1 ;
memcpy ( & V_49 -> V_78 , V_71 + V_2 -> V_79 ,
V_49 -> V_76 * sizeof( struct V_80 ) ) ;
}
int F_27 ( struct V_69 * V_49 )
{
int V_3 ;
struct V_70 * V_2 ;
if ( ! V_81 )
return - V_82 ;
V_2 = ( void * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_84 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_24 ( L_3 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_68 ;
goto V_4;
}
F_26 ( V_49 , V_2 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_30 ( T_2 V_1 )
{
struct V_85 * V_2 ;
int V_3 ;
if ( ! V_86 )
return - V_82 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
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
V_3 = - V_68 ;
break;
}
V_4:
F_25 ( V_2 ) ;
return V_3 ;
}
int F_31 ( T_3 V_78 )
{
return F_30 ( V_87 | V_78 << 8 ) ;
}
int F_32 ( T_3 V_78 )
{
return F_30 ( V_88 | V_78 << 8 ) ;
}
int F_33 ( unsigned long V_89 )
{
if ( ! V_39 )
return 0 ;
return F_34 ( V_89 ) >> F_35 ( V_39 ) ;
}
static unsigned long long F_36 ( T_4 V_90 )
{
return ( unsigned long long ) ( V_90 - 1 ) * V_39 ;
}
static int F_37 ( T_2 V_1 , T_4 V_90 )
{
struct V_91 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_17 . V_18 = V_92 ;
V_2 -> V_90 = V_90 ;
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
V_2 -> V_17 . V_22 , V_90 ) ;
V_3 = - V_68 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_38 ( T_4 V_90 )
{
unsigned long long V_93 ;
int V_3 ;
V_3 = F_37 ( 0x000d0001 , V_90 ) ;
if ( V_3 )
return V_3 ;
V_93 = F_36 ( V_90 ) ;
F_39 ( V_93 , V_93 + V_39 ) ;
return 0 ;
}
static int F_40 ( T_4 V_90 )
{
return F_37 ( 0x000c0001 , V_90 ) ;
}
static int F_41 ( T_3 V_94 )
{
struct V_95 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_17 . V_18 = V_92 ;
V_3 = F_19 ( 0x00080001 | V_94 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_42 ( V_94 , V_96 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_97 ; V_11 ++ ) {
if ( V_2 -> V_98 [ V_11 ] )
F_40 ( V_2 -> V_98 [ V_11 ] >> 16 ) ;
}
break;
default:
V_3 = - V_68 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_43 ( unsigned long V_93 , unsigned long V_99 ,
int V_100 )
{
struct V_101 * V_102 ;
unsigned long long V_103 ;
int V_3 = 0 ;
F_44 (incr, &sclp_mem_list, list) {
V_103 = F_36 ( V_102 -> V_90 ) ;
if ( V_93 + V_99 - 1 < V_103 )
break;
if ( V_93 > V_103 + V_39 - 1 )
continue;
if ( V_100 )
V_3 |= F_38 ( V_102 -> V_90 ) ;
else
F_40 ( V_102 -> V_90 ) ;
}
return V_3 ? - V_68 : 0 ;
}
static int F_45 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_57 )
{
unsigned long V_93 , V_99 ;
struct V_107 * V_108 ;
unsigned char V_94 ;
int V_3 = 0 ;
V_108 = V_57 ;
V_93 = V_108 -> V_89 << V_109 ;
V_99 = V_108 -> V_110 << V_109 ;
F_46 ( & V_111 ) ;
F_47 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_41 ( V_94 ) ;
switch ( V_106 ) {
case V_112 :
case V_113 :
case V_114 :
break;
case V_115 :
V_3 = F_43 ( V_93 , V_99 , 1 ) ;
break;
case V_116 :
F_43 ( V_93 , V_99 , 0 ) ;
break;
case V_117 :
F_43 ( V_93 , V_99 , 0 ) ;
break;
default:
V_3 = - V_118 ;
break;
}
if ( ! V_3 )
V_119 = 1 ;
F_48 ( & V_111 ) ;
return V_3 ? V_120 : V_121 ;
}
static void T_1 F_49 ( T_4 V_90 )
{
static T_4 V_122 , V_123 ;
unsigned long long V_93 , V_99 ;
if ( V_90 && V_122 && ( V_122 + V_123 == V_90 ) ) {
V_123 ++ ;
return;
}
if ( ! V_122 )
goto V_124;
V_93 = F_36 ( V_122 ) ;
V_99 = ( unsigned long long ) V_123 * V_39 ;
if ( V_93 >= V_125 )
goto V_124;
if ( V_93 + V_99 > V_125 )
V_99 = V_125 - V_93 ;
if ( V_126 && ( V_93 >= V_127 ) )
goto V_124;
if ( V_126 && ( V_93 + V_99 > V_127 ) )
V_99 = V_127 - V_93 ;
F_50 ( 0 , V_93 , V_99 ) ;
V_124:
V_122 = V_90 ;
V_123 = 1 ;
}
static void T_1 F_51 ( void )
{
struct V_101 * V_102 ;
F_44 (incr, &sclp_mem_list, list)
if ( V_102 -> V_74 )
F_49 ( V_102 -> V_90 ) ;
F_49 ( 0 ) ;
}
static void T_1 F_52 ( T_4 V_90 , int V_74 , int V_97 )
{
struct V_101 * V_102 , * V_128 ;
struct V_129 * V_130 ;
T_4 V_131 ;
V_128 = F_20 ( sizeof( * V_128 ) , V_60 ) ;
if ( ! V_128 )
return;
V_128 -> V_90 = V_90 ;
V_128 -> V_74 = V_74 ;
V_131 = 0 ;
V_130 = & V_132 ;
F_44 (incr, &sclp_mem_list, list) {
if ( V_97 && V_102 -> V_90 > V_90 )
break;
if ( ! V_97 && V_102 -> V_90 - V_131 > 1 )
break;
V_131 = V_102 -> V_90 ;
V_130 = & V_102 -> V_133 ;
}
if ( ! V_97 )
V_128 -> V_90 = V_131 + 1 ;
if ( V_128 -> V_90 > V_37 ) {
F_25 ( V_128 ) ;
return;
}
F_53 ( & V_128 -> V_133 , V_130 ) ;
}
static int F_54 ( struct V_134 * V_135 )
{
if ( ! V_119 )
return 0 ;
F_55 ( L_8 ) ;
return - V_136 ;
}
static int T_1 F_56 ( void )
{
struct V_137 * V_138 ;
struct V_139 * V_2 ;
int V_11 , V_94 , V_97 , V_3 ;
if ( V_140 )
return 0 ;
if ( ! V_23 )
return 0 ;
if ( ( V_29 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_61 ;
V_2 = ( void * ) F_57 ( V_60 | V_83 ) ;
if ( ! V_2 )
goto V_4;
V_97 = 0 ;
for ( V_94 = 0 ; V_94 <= V_141 ; V_94 ++ ) {
memset ( V_2 , 0 , V_92 ) ;
V_2 -> V_17 . V_18 = V_92 ;
V_3 = F_19 ( 0x00040001 | V_94 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_42 ( V_94 , V_96 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_97 ; V_11 ++ ) {
if ( ! V_2 -> V_98 [ V_11 ] )
continue;
V_97 ++ ;
F_52 ( V_2 -> V_98 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_97 ; V_11 ++ ) {
if ( ! V_2 -> V_98 [ V_11 ] )
continue;
V_97 ++ ;
F_52 ( V_2 -> V_98 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_68 ;
break;
}
if ( ! V_3 )
V_141 = V_2 -> V_142 ;
}
if ( V_3 || F_58 ( & V_132 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_37 - V_97 ; V_11 ++ )
F_52 ( 0 , 1 , 0 ) ;
V_3 = F_59 ( & V_143 ) ;
if ( V_3 )
goto V_4;
V_3 = F_60 ( & V_144 ) ;
if ( V_3 )
goto V_4;
V_138 = F_61 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_62 ( V_138 ) ;
if ( V_3 )
goto V_145;
F_51 () ;
goto V_4;
V_145:
F_63 ( & V_144 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_64 ( T_2 V_1 , T_5 V_146 )
{
struct V_147 * V_2 ;
int V_3 ;
if ( ! V_148 )
return - V_82 ;
V_2 = (struct V_147 * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_17 . V_18 = V_92 ;
V_2 -> V_149 = V_150 ;
V_2 -> V_151 = V_146 ;
V_3 = F_19 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_65 ( L_10 ,
V_1 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_68 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_66 ( T_5 V_146 )
{
return F_64 ( V_152 , V_146 ) ;
}
int F_67 ( T_5 V_146 )
{
return F_64 ( V_153 , V_146 ) ;
}
static int F_68 ( T_2 V_1 )
{
struct V_154 * V_2 ;
int V_3 ;
if ( ! V_155 )
return - V_82 ;
V_2 = (struct V_154 * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
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
V_3 = - V_68 ;
break;
}
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_69 ( struct V_156 V_157 )
{
return F_68 ( V_158 | V_157 . V_94 << 8 ) ;
}
int F_70 ( struct V_156 V_157 )
{
return F_68 ( V_159 | V_157 . V_94 << 8 ) ;
}
int F_71 ( struct V_160 * V_49 )
{
struct V_161 * V_2 ;
int V_3 ;
if ( ! V_162 )
return - V_82 ;
V_2 = (struct V_161 * ) F_28 ( V_60 | V_83 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_19 ( V_163 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_24 ( L_13
L_14 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_68 ;
goto V_4;
}
memcpy ( V_49 -> V_164 , V_2 -> V_164 , V_165 ) ;
memcpy ( V_49 -> V_74 , V_2 -> V_74 , V_165 ) ;
memcpy ( V_49 -> V_72 , V_2 -> V_72 , V_165 ) ;
V_4:
F_29 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
