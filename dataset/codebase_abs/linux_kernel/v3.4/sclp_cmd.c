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
V_28 = V_2 -> V_28 ? V_2 -> V_28 : V_2 -> V_29 ;
V_30 = V_2 -> V_31 ? V_2 -> V_31 : V_2 -> V_32 ;
V_30 <<= 20 ;
}
unsigned long long F_11 ( void )
{
return V_28 ;
}
unsigned long long F_12 ( void )
{
return V_30 ;
}
void T_1 F_13 ( struct V_33 * V_34 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_34 -> V_35 = 1 ;
if ( V_2 -> V_36 & 0x2 )
V_34 -> V_37 = 1 ;
memcpy ( & V_34 -> V_38 , & V_2 -> V_38 , V_39 ) ;
}
static void F_14 ( struct V_40 * V_41 , void * V_42 )
{
struct V_43 * V_43 = V_42 ;
F_15 ( V_43 ) ;
}
static int F_16 ( T_2 V_1 , void * V_2 )
{
struct V_43 V_43 ;
struct V_40 * V_44 ;
int V_3 ;
V_44 = F_17 ( sizeof( * V_44 ) , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
V_44 -> V_47 = V_1 ;
V_44 -> V_2 = V_2 ;
V_44 -> V_48 = V_49 ;
V_44 -> V_50 = F_14 ;
V_44 -> V_51 = & V_43 ;
F_18 ( & V_43 ) ;
V_3 = F_19 ( V_44 ) ;
if ( V_3 )
goto V_4;
F_20 ( & V_43 ) ;
if ( V_44 -> V_48 != V_52 ) {
F_21 ( L_1
L_2 , V_1 , V_44 -> V_48 ) ;
V_3 = - V_53 ;
}
V_4:
F_22 ( V_44 ) ;
return V_3 ;
}
static void F_23 ( struct V_54 * V_34 ,
struct V_55 * V_2 )
{
char * V_56 = ( char * ) V_2 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_57 = V_2 -> V_58 ;
V_34 -> V_59 = V_2 -> V_60 ;
V_34 -> V_61 = V_2 -> V_58 + V_2 -> V_60 ;
V_34 -> V_62 = V_26 & 0x1 ;
memcpy ( & V_34 -> V_63 , V_56 + V_2 -> V_64 ,
V_34 -> V_61 * sizeof( struct V_65 ) ) ;
}
int F_24 ( struct V_54 * V_34 )
{
int V_3 ;
struct V_55 * V_2 ;
if ( ! V_66 )
return - V_67 ;
V_2 = ( void * ) F_25 ( V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_69 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_21 ( L_3 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_53 ;
goto V_4;
}
F_23 ( V_34 , V_2 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_27 ( T_2 V_1 )
{
struct V_70 * V_2 ;
int V_3 ;
if ( ! V_71 )
return - V_67 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_21 ( L_4
L_5 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_53 ;
break;
}
V_4:
F_22 ( V_2 ) ;
return V_3 ;
}
int F_28 ( T_3 V_63 )
{
return F_27 ( V_72 | V_63 << 8 ) ;
}
int F_29 ( T_3 V_63 )
{
return F_27 ( V_73 | V_63 << 8 ) ;
}
int F_30 ( unsigned long V_74 )
{
if ( ! V_30 )
return 0 ;
return F_31 ( V_74 ) >> F_32 ( V_30 ) ;
}
static unsigned long long F_33 ( T_4 V_75 )
{
return ( unsigned long long ) ( V_75 - 1 ) * V_30 ;
}
static int F_34 ( T_2 V_1 , T_4 V_75 )
{
struct V_76 * V_2 ;
int V_3 ;
V_2 = ( void * ) F_25 ( V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = V_77 ;
V_2 -> V_75 = V_75 ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_21 ( L_6
L_7 , V_1 ,
V_2 -> V_17 . V_22 , V_75 ) ;
V_3 = - V_53 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_35 ( T_4 V_75 )
{
return F_34 ( 0x000d0001 , V_75 ) ;
}
static int F_36 ( T_4 V_75 )
{
return F_34 ( 0x000c0001 , V_75 ) ;
}
static int F_37 ( T_3 V_78 )
{
struct V_79 * V_2 ;
int V_3 ;
int V_11 ;
V_2 = ( void * ) F_25 ( V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = V_77 ;
V_3 = F_16 ( 0x00080001 | V_78 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
F_38 ( V_78 , V_80 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_81 ; V_11 ++ ) {
if ( V_2 -> V_82 [ V_11 ] )
F_36 ( V_2 -> V_82 [ V_11 ] >> 16 ) ;
}
break;
default:
V_3 = - V_53 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_39 ( unsigned long V_83 , unsigned long V_84 ,
int V_85 )
{
struct V_86 * V_87 ;
unsigned long long V_88 ;
int V_3 = 0 ;
F_40 (incr, &sclp_mem_list, list) {
V_88 = F_33 ( V_87 -> V_75 ) ;
if ( V_83 + V_84 - 1 < V_88 )
break;
if ( V_83 > V_88 + V_30 - 1 )
continue;
if ( V_85 ) {
if ( V_87 -> V_89 ++ )
continue;
V_3 |= F_35 ( V_87 -> V_75 ) ;
} else {
if ( -- V_87 -> V_89 )
continue;
F_36 ( V_87 -> V_75 ) ;
}
}
return V_3 ? - V_53 : 0 ;
}
static int F_41 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_42 )
{
unsigned long V_83 , V_84 ;
struct V_93 * V_94 ;
unsigned char V_78 ;
int V_3 = 0 ;
V_94 = V_42 ;
V_83 = V_94 -> V_74 << V_95 ;
V_84 = V_94 -> V_96 << V_95 ;
F_42 ( & V_97 ) ;
F_43 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_37 ( V_78 ) ;
switch ( V_92 ) {
case V_98 :
case V_99 :
case V_100 :
break;
case V_101 :
V_3 = F_39 ( V_83 , V_84 , 1 ) ;
break;
case V_102 :
F_39 ( V_83 , V_84 , 0 ) ;
break;
case V_103 :
F_39 ( V_83 , V_84 , 0 ) ;
break;
default:
V_3 = - V_104 ;
break;
}
if ( ! V_3 )
V_105 = 1 ;
F_44 ( & V_97 ) ;
return V_3 ? V_106 : V_107 ;
}
static void T_1 F_45 ( T_4 V_75 )
{
static T_4 V_108 , V_109 ;
unsigned long long V_83 , V_84 ;
if ( V_75 && V_108 && ( V_108 + V_109 == V_75 ) ) {
V_109 ++ ;
return;
}
if ( ! V_108 )
goto V_110;
V_83 = F_33 ( V_108 ) ;
V_84 = ( unsigned long long ) V_109 * V_30 ;
if ( V_83 >= V_111 )
goto V_110;
if ( V_83 + V_84 > V_111 )
V_84 = V_111 - V_83 ;
if ( V_112 && ( V_83 >= V_113 ) )
goto V_110;
if ( V_112 && ( V_83 + V_84 > V_113 ) )
V_84 = V_113 - V_83 ;
F_46 ( 0 , V_83 , V_84 ) ;
V_110:
V_108 = V_75 ;
V_109 = 1 ;
}
static void T_1 F_47 ( void )
{
struct V_86 * V_87 ;
F_40 (incr, &sclp_mem_list, list)
if ( V_87 -> V_59 )
F_45 ( V_87 -> V_75 ) ;
F_45 ( 0 ) ;
}
static void T_1 F_48 ( T_4 V_75 , int V_59 , int V_81 )
{
struct V_86 * V_87 , * V_114 ;
struct V_115 * V_116 ;
T_4 V_117 ;
V_114 = F_17 ( sizeof( * V_114 ) , V_45 ) ;
if ( ! V_114 )
return;
V_114 -> V_75 = V_75 ;
V_114 -> V_59 = V_59 ;
if ( ! V_59 )
V_114 -> V_89 = 1 ;
V_117 = 0 ;
V_116 = & V_118 ;
F_40 (incr, &sclp_mem_list, list) {
if ( V_81 && V_87 -> V_75 > V_75 )
break;
if ( ! V_81 && V_87 -> V_75 - V_117 > 1 )
break;
V_117 = V_87 -> V_75 ;
V_116 = & V_87 -> V_119 ;
}
if ( ! V_81 )
V_114 -> V_75 = V_117 + 1 ;
if ( V_114 -> V_75 > V_28 ) {
F_22 ( V_114 ) ;
return;
}
F_49 ( & V_114 -> V_119 , V_116 ) ;
}
static int F_50 ( struct V_120 * V_121 )
{
if ( ! V_105 )
return 0 ;
F_51 ( L_8 ) ;
return - V_122 ;
}
static int T_1 F_52 ( void )
{
struct V_123 * V_124 ;
struct V_125 * V_2 ;
int V_11 , V_78 , V_81 , V_3 ;
if ( ! V_23 )
return 0 ;
if ( ( V_24 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_3 = - V_46 ;
V_2 = ( void * ) F_53 ( V_45 | V_68 ) ;
if ( ! V_2 )
goto V_4;
V_81 = 0 ;
for ( V_78 = 0 ; V_78 <= V_126 ; V_78 ++ ) {
memset ( V_2 , 0 , V_77 ) ;
V_2 -> V_17 . V_18 = V_77 ;
V_3 = F_16 ( 0x00040001 | V_78 << 8 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0010 :
F_38 ( V_78 , V_80 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_81 ; V_11 ++ ) {
if ( ! V_2 -> V_82 [ V_11 ] )
continue;
V_81 ++ ;
F_48 ( V_2 -> V_82 [ V_11 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_11 = 0 ; V_11 < V_2 -> V_81 ; V_11 ++ ) {
if ( ! V_2 -> V_82 [ V_11 ] )
continue;
V_81 ++ ;
F_48 ( V_2 -> V_82 [ V_11 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_3 = - V_53 ;
break;
}
if ( ! V_3 )
V_126 = V_2 -> V_127 ;
}
if ( V_3 || F_54 ( & V_118 ) )
goto V_4;
for ( V_11 = 1 ; V_11 <= V_28 - V_81 ; V_11 ++ )
F_48 ( 0 , 1 , 0 ) ;
V_3 = F_55 ( & V_128 ) ;
if ( V_3 )
goto V_4;
V_3 = F_56 ( & V_129 ) ;
if ( V_3 )
goto V_4;
V_124 = F_57 ( L_9 , - 1 , NULL , 0 ) ;
V_3 = F_58 ( V_124 ) ? F_59 ( V_124 ) : 0 ;
if ( V_3 )
goto V_130;
F_47 () ;
goto V_4;
V_130:
F_60 ( & V_129 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
static int F_61 ( T_2 V_1 )
{
struct V_131 * V_2 ;
int V_3 ;
if ( ! V_132 )
return - V_67 ;
V_2 = (struct V_131 * ) F_25 ( V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
switch ( V_2 -> V_17 . V_22 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_21 ( L_10
L_11 , V_1 ,
V_2 -> V_17 . V_22 ) ;
V_3 = - V_53 ;
break;
}
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
int F_62 ( struct V_133 V_134 )
{
return F_61 ( V_135 | V_134 . V_78 << 8 ) ;
}
int F_63 ( struct V_133 V_134 )
{
return F_61 ( V_136 | V_134 . V_78 << 8 ) ;
}
int F_64 ( struct V_137 * V_34 )
{
struct V_138 * V_2 ;
int V_3 ;
if ( ! V_139 )
return - V_67 ;
V_2 = (struct V_138 * ) F_25 ( V_45 | V_68 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_3 = F_16 ( V_140 , V_2 ) ;
if ( V_3 )
goto V_4;
if ( V_2 -> V_17 . V_22 != 0x0010 ) {
F_21 ( L_12
L_13 , V_2 -> V_17 . V_22 ) ;
V_3 = - V_53 ;
goto V_4;
}
memcpy ( V_34 -> V_141 , V_2 -> V_141 , V_142 ) ;
memcpy ( V_34 -> V_59 , V_2 -> V_59 , V_142 ) ;
memcpy ( V_34 -> V_57 , V_2 -> V_57 , V_142 ) ;
V_4:
F_26 ( ( unsigned long ) V_2 ) ;
return V_3 ;
}
