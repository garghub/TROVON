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
void T_1 F_10 ( void )
{
struct V_12 * V_2 ;
F_8 () ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_24 = V_2 -> V_25 ;
V_26 = V_2 -> V_27 ;
V_28 = V_2 -> V_29 ;
V_30 = V_2 -> V_30 ? V_2 -> V_30 : V_2 -> V_31 ;
V_32 = V_2 -> V_33 ? V_2 -> V_33 : V_2 -> V_34 ;
V_32 <<= 20 ;
}
unsigned long long F_11 ( void )
{
return V_30 ;
}
unsigned long long F_12 ( void )
{
return V_32 ;
}
T_3 F_13 ( void )
{
return V_28 ;
}
void T_1 F_14 ( struct V_35 * V_36 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_36 -> V_37 = 1 ;
if ( V_2 -> V_38 & 0x2 )
V_36 -> V_39 = 1 ;
memcpy ( & V_36 -> V_40 , & V_2 -> V_40 , V_41 ) ;
}
static void F_15 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * V_45 = V_44 ;
F_16 ( V_45 ) ;
}
static int F_17 ( T_2 V_1 , void * V_2 )
{
struct V_45 V_45 ;
struct V_42 * V_46 ;
int V_3 ;
V_46 = F_18 ( sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_46 -> V_49 = V_1 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_50 = V_51 ;
V_46 -> V_52 = F_15 ;
V_46 -> V_53 = & V_45 ;
F_19 ( & V_45 ) ;
V_3 = F_20 ( V_46 ) ;
if ( V_3 )
goto V_4;
F_21 ( & V_45 ) ;
if ( V_46 -> V_50 != V_54 ) {
F_22 ( L_1
L_2 , V_1 , V_46 -> V_50 ) ;
V_3 = - V_55 ;
}
V_4:
F_23 ( V_46 ) ;
return V_3 ;
}
static void F_24 ( struct V_56 * V_36 ,
struct V_57 * V_2 )
{
char * V_58 = ( char * ) V_2 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_59 = V_2 -> V_60 ;
V_36 -> V_61 = V_2 -> V_62 ;
V_36 -> V_63 = V_2 -> V_60 + V_2 -> V_62 ;
V_36 -> V_64 = V_26 & 0x1 ;
memcpy ( & V_36 -> V_65 , V_58 + V_2 -> V_66 ,
V_36 -> V_63 * sizeof( struct V_67 ) ) ;
}
int F_25 ( struct V_56 * V_36 )
{
int V_3 ;
struct V_57 * V_2 ;
if ( ! V_68 )
return - V_69 ;
V_2 = ( void * ) F_26 ( V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_17 ( V_71 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_22 ( L_3 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_55 ;
goto V_4;
}
F_24 ( V_36 , V_2 ) ;
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_28 ( T_2 V_1 )
{
struct V_72 * V_2 ;
int V_3 ;
if ( ! V_73 )
return - V_69 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_17 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_22 ( L_4
L_5 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_55 ;
break;
}
V_4:
F_23 ( V_2 ) ;
return V_3 ;
}
int F_29 ( T_3 V_65 )
{
return F_28 ( V_74 | V_65 << 8 ) ;
}
int F_30 ( T_3 V_65 )
{
return F_28 ( V_75 | V_65 << 8 ) ;
}
int F_31 ( unsigned long V_76 )
{
if ( ! V_32 )
return 0 ;
return F_32 ( V_76 ) >> F_33 ( V_32 ) ;
}
static unsigned long long F_34 ( T_4 V_77 )
{
return ( unsigned long long ) ( V_77 - 1 ) * V_32 ;
}
static int F_35 ( T_2 V_1 , T_4 V_77 )
{
struct V_78 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_26 ( V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = V_79 ;
V_2 -> V_77 = V_77 ;
V_3 = F_17 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_22 ( L_6
L_7 , V_1 ,
V_2 -> V_17 . V_22 , V_77 ) ;
V_3 = - V_55 ;
break;
}
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_36 ( T_4 V_77 )
{
unsigned long long V_80 , V_81 ;
int V_3 ;
V_3 = F_35 ( 0x000d0001 , V_77 ) ;
if ( V_3 )
goto V_4;
V_80 = V_81 = F_34 ( V_77 ) ;
for (; V_81 < V_80 + V_32 ; V_81 += V_79 )
F_37 ( V_81 , V_82 , 0 ) ;
V_4:
return V_3 ;
}
static int F_38 ( T_4 V_77 )
{
return F_35 ( 0x000c0001 , V_77 ) ;
}
static int F_39 ( T_3 V_83 )
{
struct V_84 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_26 ( V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = V_79 ;
V_3 = F_17 ( 0x00080001 | V_83 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_40 ( V_83 , V_85 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_86 ; V_11 ++ ) {
if ( V_2 -> V_87 [ V_11 ] )
F_38 ( V_2 -> V_87 [ V_11 ] >> 16 ) ;
}
break;
default:
V_3 = - V_55 ;
break;
}
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_41 ( unsigned long V_80 , unsigned long V_88 ,
int V_89 )
{
struct V_90 * V_91 ;
unsigned long long V_92 ;
int V_3 = 0 ;
F_42 (incr, &sclp_mem_list, list) {
V_92 = F_34 ( V_91 -> V_77 ) ;
if ( V_80 + V_88 - 1 < V_92 )
break;
if ( V_80 > V_92 + V_32 - 1 )
continue;
if ( V_89 ) {
if ( V_91 -> V_93 ++ )
continue;
V_3 |= F_36 ( V_91 -> V_77 ) ;
} else {
if ( -- V_91 -> V_93 )
continue;
F_38 ( V_91 -> V_77 ) ;
}
}
return V_3 ? - V_55 : 0 ;
}
static int F_43 ( struct V_94 * V_95 ,
unsigned long V_96 , void * V_44 )
{
unsigned long V_80 , V_88 ;
struct V_97 * V_98 ;
unsigned char V_83 ;
int V_3 = 0 ;
V_98 = V_44 ;
V_80 = V_98 -> V_76 << V_99 ;
V_88 = V_98 -> V_100 << V_99 ;
F_44 ( & V_101 ) ;
F_45 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_39 ( V_83 ) ;
switch ( V_96 ) {
case V_102 :
case V_103 :
case V_104 :
break;
case V_105 :
V_3 = F_41 ( V_80 , V_88 , 1 ) ;
break;
case V_106 :
F_41 ( V_80 , V_88 , 0 ) ;
break;
case V_107 :
F_41 ( V_80 , V_88 , 0 ) ;
break;
default:
V_3 = - V_108 ;
break;
}
if ( ! V_3 )
V_109 = 1 ;
F_46 ( & V_101 ) ;
return V_3 ? V_110 : V_111 ;
}
static void T_1 F_47 ( T_4 V_77 )
{
static T_4 V_112 , V_113 ;
unsigned long long V_80 , V_88 ;
if ( V_77 && V_112 && ( V_112 + V_113 == V_77 ) ) {
V_113 ++ ;
return;
}
if ( ! V_112 )
goto V_114;
V_80 = F_34 ( V_112 ) ;
V_88 = ( unsigned long long ) V_113 * V_32 ;
if ( V_80 >= V_115 )
goto V_114;
if ( V_80 + V_88 > V_115 )
V_88 = V_115 - V_80 ;
if ( V_116 && ( V_80 >= V_117 ) )
goto V_114;
if ( V_116 && ( V_80 + V_88 > V_117 ) )
V_88 = V_117 - V_80 ;
F_48 ( 0 , V_80 , V_88 ) ;
V_114:
V_112 = V_77 ;
V_113 = 1 ;
}
static void T_1 F_49 ( void )
{
struct V_90 * V_91 ;
F_42 (incr, &sclp_mem_list, list)
if ( V_91 -> V_61 )
F_47 ( V_91 -> V_77 ) ;
F_47 ( 0 ) ;
}
static void T_1 F_50 ( T_4 V_77 , int V_61 , int V_86 )
{
struct V_90 * V_91 , * V_118 ;
struct V_119 * V_120 ;
T_4 V_121 ;
V_118 = F_18 ( sizeof( * V_118 ) , V_47 ) ;
if ( ! V_118 )
return;
V_118 -> V_77 = V_77 ;
V_118 -> V_61 = V_61 ;
if ( ! V_61 )
V_118 -> V_93 = 1 ;
V_121 = 0 ;
V_120 = & V_122 ;
F_42 (incr, &sclp_mem_list, list) {
if ( V_86 && V_91 -> V_77 > V_77 )
break;
if ( ! V_86 && V_91 -> V_77 - V_121 > 1 )
break;
V_121 = V_91 -> V_77 ;
V_120 = & V_91 -> V_123 ;
}
if ( ! V_86 )
V_118 -> V_77 = V_121 + 1 ;
if ( V_118 -> V_77 > V_30 ) {
F_23 ( V_118 ) ;
return;
}
F_51 ( & V_118 -> V_123 , V_120 ) ;
}
static int F_52 ( struct V_124 * V_125 )
{
if ( ! V_109 )
return 0 ;
F_53 ( L_8 ) ;
return - V_126 ;
}
static int T_1 F_54 ( void )
{
struct V_127 * V_128 ;
struct V_129 * V_2 ;
int V_11 , V_83 , V_86 , V_3 ;
if ( ! V_23 )
return 0 ;
if ( ( V_24 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_48 ;
V_2 = ( void * ) F_55 ( V_47 | V_70 ) ;
if ( ! V_2 )
goto V_4;
V_86 = 0 ;
for ( V_83 = 0 ; V_83 <= V_130 ; V_83 ++ ) {
memset ( V_2 , 0 , V_79 ) ;
V_2 -> V_17 . V_18 = V_79 ;
V_3 = F_17 ( 0x00040001 | V_83 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_40 ( V_83 , V_85 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_86 ; V_11 ++ ) {
if ( ! V_2 -> V_87 [ V_11 ] )
continue;
V_86 ++ ;
F_50 ( V_2 -> V_87 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_86 ; V_11 ++ ) {
if ( ! V_2 -> V_87 [ V_11 ] )
continue;
V_86 ++ ;
F_50 ( V_2 -> V_87 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_55 ;
break;
}
if ( ! V_3 )
V_130 = V_2 -> V_131 ;
}
if ( V_3 || F_56 ( & V_122 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_30 - V_86 ; V_11 ++ )
F_50 ( 0 , 1 , 0 ) ;
V_3 = F_57 ( & V_132 ) ;
if ( V_3 )
goto V_4;
V_3 = F_58 ( & V_133 ) ;
if ( V_3 )
goto V_4;
V_128 = F_59 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_60 ( V_128 ) ? F_61 ( V_128 ) : 0 ;
if ( V_3 )
goto V_134;
F_49 () ;
goto V_4;
V_134:
F_62 ( & V_133 ) ;
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_63 ( T_2 V_1 )
{
struct V_135 * V_2 ;
int V_3 ;
if ( ! V_136 )
return - V_69 ;
V_2 = (struct V_135 * ) F_26 ( V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_17 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_22 ( L_10
L_11 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_55 ;
break;
}
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_64 ( struct V_137 V_138 )
{
return F_63 ( V_139 | V_138 . V_83 << 8 ) ;
}
int F_65 ( struct V_137 V_138 )
{
return F_63 ( V_140 | V_138 . V_83 << 8 ) ;
}
int F_66 ( struct V_141 * V_36 )
{
struct V_142 * V_2 ;
int V_3 ;
if ( ! V_143 )
return - V_69 ;
V_2 = (struct V_142 * ) F_26 ( V_47 | V_70 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_17 ( V_144 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_22 ( L_12
L_13 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_55 ;
goto V_4;
}
memcpy ( V_36 -> V_145 , V_2 -> V_145 , V_146 ) ;
memcpy ( V_36 -> V_61 , V_2 -> V_61 , V_146 ) ;
memcpy ( V_36 -> V_59 , V_2 -> V_59 , V_146 ) ;
V_4:
F_27 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
