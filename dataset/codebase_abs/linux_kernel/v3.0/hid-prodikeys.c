static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
F_4 ( L_1 , V_9 -> V_10 -> V_11 ) ;
return sprintf ( V_5 , L_2 , V_9 -> V_10 -> V_11 ,
V_12 , V_13 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
unsigned V_15 = 0 ;
if ( sscanf ( V_5 , L_3 , & V_15 ) > 0 && V_15 <= V_13 ) {
F_4 ( L_4 , V_15 ) ;
V_9 -> V_10 -> V_11 = V_15 ;
return strlen ( V_5 ) ;
}
return - V_16 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
F_4 ( L_5 , V_9 -> V_10 -> V_17 ) ;
return sprintf ( V_5 , L_6 , V_9 -> V_10 -> V_17 ,
V_18 , V_19 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
unsigned V_20 = 0 ;
if ( sscanf ( V_5 , L_3 , & V_20 ) > 0 && V_20 <= V_19 ) {
F_4 ( L_7 , V_20 ) ;
V_9 -> V_10 -> V_17 = V_20 ;
V_9 -> V_10 -> V_21 =
( 0 == V_20 || ! V_9 -> V_10 -> V_22 ) ? 0 : 1 ;
return strlen ( V_5 ) ;
}
return - V_16 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
F_4 ( L_8 , V_9 -> V_10 -> V_23 ) ;
return sprintf ( V_5 , L_9 , V_9 -> V_10 -> V_23 ,
V_24 , V_25 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
int V_26 = 0 ;
if ( sscanf ( V_5 , L_10 , & V_26 ) > 0 &&
V_26 >= V_24 && V_26 <= V_25 ) {
F_4 ( L_11 , V_26 ) ;
V_9 -> V_10 -> V_23 = V_26 ;
return strlen ( V_5 ) ;
}
return - V_16 ;
}
static void F_10 ( struct V_27 * V_10 ,
unsigned char V_28 , unsigned char V_29 , unsigned char V_30 )
{
unsigned long V_31 ;
unsigned char V_32 [ 3 ] ;
V_32 [ 0 ] = V_28 ;
V_32 [ 1 ] = V_29 ;
V_32 [ 2 ] = V_30 ;
F_11 ( & V_10 -> V_33 , V_31 ) ;
if ( ! V_10 -> V_34 )
goto V_35;
if ( ! F_12 ( V_10 -> V_34 -> V_36 , & V_10 -> V_37 ) )
goto V_35;
F_13 ( V_10 -> V_34 , V_32 , 3 ) ;
V_35:
F_14 ( & V_10 -> V_33 , V_31 ) ;
return;
}
void F_15 ( unsigned long V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
F_10 ( V_40 -> V_10 , V_40 -> V_28 , V_40 -> V_29 , V_40 -> V_30 ) ;
V_40 -> V_41 = 0 ;
}
void F_16 ( struct V_27 * V_10 )
{
struct V_39 * V_40 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_40 = & V_10 -> V_44 [ V_42 ] ;
V_40 -> V_41 = 0 ;
V_40 -> V_10 = V_10 ;
F_17 ( & V_40 -> V_45 , F_15 ,
( unsigned long ) V_40 ) ;
}
}
void F_18 ( struct V_27 * V_10 )
{
struct V_39 * V_40 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_40 = & V_10 -> V_44 [ V_42 ] ;
V_40 -> V_41 = 1 ;
F_19 ( & V_40 -> V_45 ) ;
}
}
static int F_20 ( struct V_27 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_9 -> V_7 ;
struct V_46 * V_47 ;
F_21 (report,
&hdev->report_enum[HID_OUTPUT_REPORT].report_list, list) {
if ( ! ( 6 == V_47 -> V_48 ) )
continue;
if ( V_47 -> V_49 < 1 ) {
F_22 ( V_7 , L_12 ) ;
break;
}
if ( V_47 -> V_50 [ 0 ] -> V_51 != 2 ) {
F_22 ( V_7 , L_13 ) ;
break;
}
V_10 -> V_52 = V_47 ;
return 0 ;
}
return - V_53 ;
}
static void F_23 ( struct V_27 * V_10 , int V_54 )
{
struct V_6 * V_7 = V_10 -> V_9 -> V_7 ;
struct V_46 * V_47 = V_10 -> V_52 ;
V_47 -> V_50 [ 0 ] -> V_55 [ 0 ] = 0x01 ;
V_47 -> V_50 [ 0 ] -> V_55 [ 1 ] = V_54 ;
F_24 ( V_7 , V_47 , V_56 ) ;
}
static int F_25 ( struct V_27 * V_10 , T_3 * V_38 )
{
T_4 V_57 ;
V_57 = V_38 [ 1 ] ;
V_57 = ( V_57 << 8 ) | V_38 [ 2 ] ;
V_57 = ( V_57 << 8 ) | V_38 [ 3 ] ;
F_4 ( L_14 , V_10 -> V_22 ) ;
if ( V_10 -> V_22 && V_57 == 0x004000 ) {
V_10 -> V_23 -- ;
if ( V_10 -> V_23 < - 2 )
V_10 -> V_23 = - 2 ;
F_4 ( L_15 ,
V_10 -> V_22 , V_10 -> V_23 ) ;
return 1 ;
}
else if ( V_10 -> V_22 && V_57 == 0x000004 ) {
V_10 -> V_21 ^= 0x1 ;
return 1 ;
}
return 0 ;
}
static int F_26 ( struct V_27 * V_10 , T_3 * V_38 , int V_58 )
{
struct V_39 * V_40 ;
unsigned V_42 , V_59 ;
unsigned char V_28 , V_29 , V_30 ;
unsigned V_60 = ( V_58 - 1 ) / 2 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_29 = V_38 [ V_59 * 2 + 1 ] ;
V_30 = V_38 [ V_59 * 2 + 2 ] ;
if ( V_29 < 0x81 ) {
V_28 = 128 + 16 + V_10 -> V_11 ;
V_29 = V_29 - 0x54 + V_61 +
( V_10 -> V_23 * 12 ) ;
if ( 0 == V_30 )
V_30 = 1 ;
} else {
V_28 = 128 + V_10 -> V_11 ;
V_29 = V_29 - 0x94 + V_61 +
( V_10 -> V_23 * 12 ) ;
if ( V_10 -> V_21 ) {
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_40 = & V_10 -> V_44 [ V_42 ] ;
if ( ! V_40 -> V_41 ) {
V_40 -> V_28 = V_28 ;
V_40 -> V_29 = V_29 ;
V_40 -> V_30 = V_30 ;
V_40 -> V_41 = 1 ;
F_27 ( & V_40 -> V_45 ,
V_62 +
F_28 ( V_10 -> V_17 ) ) ;
return 1 ;
}
}
}
}
F_10 ( V_10 , V_28 , V_29 , V_30 ) ;
}
return 1 ;
}
static int F_29 ( struct V_27 * V_10 , T_3 * V_38 )
{
unsigned V_63 ;
T_4 V_57 ;
T_4 V_64 ;
V_57 = V_38 [ 1 ] ;
V_57 = ( V_57 << 8 ) | V_38 [ 2 ] ;
V_57 = ( V_57 << 8 ) | V_38 [ 3 ] ;
for ( V_64 = 0 ; V_64 < 24 ; V_64 ++ ) {
V_63 = V_10 -> V_65 [ V_64 ] ;
if ( ! ( ( 0x01 << V_64 ) & V_57 ) ) {
F_30 ( V_10 -> V_66 , V_67 ,
V_10 -> V_65 [ V_64 ] , 0 ) ;
V_10 -> V_65 [ V_64 ] = 0 ;
}
}
for ( V_64 = 0 ; V_64 < 24 ; V_64 ++ ) {
V_63 = 0 ;
switch ( ( 0x01 << V_64 ) & V_57 ) {
case 0x000010 :
V_10 -> V_68 ^= 0x000010 ;
if ( V_10 -> V_68 )
F_23 ( V_10 , 0xc5 ) ;
else
F_23 ( V_10 , 0xc6 ) ;
continue;
case 0x020000 :
F_23 ( V_10 , 0xc1 ) ;
V_10 -> V_22 ^= 0x01 ;
F_4 ( L_14 , V_10 -> V_22 ) ;
continue;
case 0x100000 :
F_4 ( L_14 , V_10 -> V_22 ) ;
if ( V_10 -> V_22 ) {
V_10 -> V_23 ++ ;
if ( V_10 -> V_23 > 2 )
V_10 -> V_23 = 2 ;
F_4 ( L_15 ,
V_10 -> V_22 , V_10 -> V_23 ) ;
continue;
} else
V_63 = V_69 ;
break;
case 0x400000 :
V_63 = V_70 ;
break;
case 0x080000 :
V_63 = V_71 ;
break;
case 0x040000 :
V_63 = V_72 ;
break;
case 0x800000 :
V_63 = V_73 ;
break;
case 0x200000 :
V_63 = V_74 ;
break;
case 0x010000 :
V_63 = V_75 ;
break;
case 0x000100 :
V_63 = V_76 ;
break;
case 0x000200 :
V_63 = V_77 ;
break;
case 0x000400 :
V_63 = V_78 ;
break;
case 0x000800 :
V_63 = V_79 ;
break;
case 0x001000 :
V_63 = V_80 ;
break;
case 0x002000 :
V_63 = V_81 ;
break;
case 0x004000 :
V_63 = V_82 ;
break;
case 0x008000 :
V_63 = V_83 ;
break;
case 0x000001 :
V_63 = V_84 ;
break;
case 0x000002 :
V_63 = V_85 ;
break;
case 0x000004 :
V_63 = V_86 ;
break;
case 0x000008 :
V_63 = V_87 ;
break;
}
if ( V_63 ) {
F_30 ( V_10 -> V_66 , V_67 , V_63 , 1 ) ;
V_10 -> V_65 [ V_64 ] = V_63 ;
}
}
return 1 ;
}
int F_31 (
struct V_27 * V_10 , unsigned V_88 , T_3 * V_38 , int V_58 )
{
int V_89 = 0 ;
switch ( V_88 ) {
case 0x01 :
V_89 = F_25 ( V_10 , V_38 ) ;
break;
case 0x03 :
V_89 = F_26 ( V_10 , V_38 , V_58 ) ;
break;
case 0x04 :
V_89 = F_29 ( V_10 , V_38 ) ;
break;
}
return V_89 ;
}
void F_32 ( struct V_27 * V_10 , struct V_90 * V_91 )
{
unsigned int V_92 [] = {
V_93 ,
V_69 , V_70 ,
V_71 , V_72 ,
V_73 ,
V_74 ,
V_75 ,
V_76 , V_77 ,
V_78 , V_79 ,
V_80 , V_81 ,
V_82 , V_83 ,
V_84 , V_85 ,
V_86 , V_87 ,
0
} ;
unsigned int * V_94 = & V_92 [ 0 ] ;
unsigned short V_42 ;
if ( V_10 -> V_95 != 1 )
return;
V_10 -> V_66 = V_91 ;
for ( V_42 = 0 ; V_42 < 24 ; V_42 ++ )
V_10 -> V_65 [ V_42 ] = 0 ;
while ( * V_94 != 0 ) {
F_33 ( * V_94 , V_10 -> V_66 -> V_96 ) ;
++ V_94 ;
}
}
static int F_34 ( struct V_27 * V_10 )
{
if ( V_10 -> V_95 != 1 )
return 0 ;
F_20 ( V_10 ) ;
F_23 ( V_10 , 0xc1 ) ;
return 0 ;
}
static int F_35 ( struct V_97 * V_2 )
{
return 0 ;
}
static int F_36 ( struct V_98 * V_99 )
{
struct V_27 * V_10 = V_99 -> V_100 -> V_101 ;
F_4 ( L_16 ) ;
V_10 -> V_34 = V_99 ;
return 0 ;
}
static int F_37 ( struct V_98 * V_99 )
{
F_4 ( L_17 ) ;
return 0 ;
}
static void F_38 ( struct V_98 * V_99 , int V_102 )
{
struct V_27 * V_10 = V_99 -> V_100 -> V_101 ;
F_4 ( L_18 , V_102 ) ;
V_10 -> V_37 = V_102 ;
}
int F_39 ( struct V_27 * V_10 )
{
static int V_2 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_107 ;
static struct V_108 V_109 = {
. V_110 = F_35 ,
} ;
if ( V_10 -> V_95 != 1 )
return 0 ;
if ( V_2 >= V_111 )
return - V_53 ;
if ( ! V_112 [ V_2 ] ) {
V_2 ++ ;
return - V_113 ;
}
V_107 = F_40 ( V_114 [ V_2 ] , V_48 [ V_2 ] , V_115 , 0 , & V_104 ) ;
if ( V_107 < 0 ) {
F_41 ( L_19 ) ;
V_107 = - V_116 ;
goto V_117;
}
V_10 -> V_104 = V_104 ;
V_107 = F_42 ( V_104 , V_118 , V_10 , & V_109 ) ;
if ( V_107 < 0 ) {
F_41 ( L_20 ,
V_107 ) ;
goto V_117;
}
strncpy ( V_104 -> V_119 , V_120 , sizeof( V_104 -> V_119 ) ) ;
strncpy ( V_104 -> V_120 , V_120 , sizeof( V_104 -> V_120 ) ) ;
strncpy ( V_104 -> V_121 , V_121 , sizeof( V_104 -> V_121 ) ) ;
V_107 = F_43 ( V_104 , V_104 -> V_120 , 0 ,
0 , 1 , & V_106 ) ;
if ( V_107 < 0 ) {
F_41 ( L_21 ,
V_107 ) ;
goto V_117;
}
V_10 -> V_106 = V_106 ;
strncpy ( V_106 -> V_122 , V_104 -> V_120 , sizeof( V_106 -> V_122 ) ) ;
V_106 -> V_123 = V_124 ;
V_106 -> V_101 = V_10 ;
F_44 ( V_106 , V_125 ,
& V_126 ) ;
F_45 ( V_104 , & V_10 -> V_9 -> V_7 -> V_2 ) ;
V_107 = F_46 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_127 ) ;
if ( V_107 < 0 ) {
F_41 ( L_22 ,
V_107 ) ;
goto V_117;
}
V_107 = F_46 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_128 ) ;
if ( V_107 < 0 ) {
F_41 ( L_23 ,
V_107 ) ;
goto V_129;
}
V_107 = F_46 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_130 ) ;
if ( V_107 < 0 ) {
F_41 ( L_24 ,
V_107 ) ;
goto V_131;
}
F_47 ( & V_10 -> V_33 ) ;
F_16 ( V_10 ) ;
F_34 ( V_10 ) ;
V_107 = F_48 ( V_104 ) ;
if ( V_107 < 0 ) {
F_41 ( L_25 ,
V_107 ) ;
goto V_132;
}
F_4 ( L_26 ) ;
return 0 ;
V_132:
F_18 ( V_10 ) ;
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 , V_130 ) ;
V_131:
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 , V_128 ) ;
V_129:
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 , V_127 ) ;
V_117:
if ( V_10 -> V_104 ) {
F_50 ( V_10 -> V_104 ) ;
V_10 -> V_104 = NULL ;
}
return V_107 ;
}
int F_51 ( struct V_27 * V_10 )
{
if ( V_10 -> V_104 ) {
F_18 ( V_10 ) ;
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_127 ) ;
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_128 ) ;
F_49 ( & V_10 -> V_9 -> V_7 -> V_2 ,
V_130 ) ;
F_52 ( V_10 -> V_104 ) ;
F_53 ( V_10 -> V_104 ) ;
}
return 0 ;
}
static T_5 * F_54 ( struct V_6 * V_7 , T_5 * V_133 ,
unsigned int * V_134 )
{
if ( * V_134 == 178 &&
V_133 [ 111 ] == 0x06 && V_133 [ 112 ] == 0x00 &&
V_133 [ 113 ] == 0xff ) {
F_55 ( V_7 ,
L_27 ) ;
V_133 [ 144 ] = 0x18 ;
}
return V_133 ;
}
static int F_56 ( struct V_6 * V_7 , struct V_135 * V_136 ,
struct V_137 * V_50 , struct V_138 * V_139 ,
unsigned long * * V_140 , int * V_141 )
{
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
struct V_27 * V_10 ;
V_10 = V_9 -> V_10 ;
if ( V_142 == ( V_139 -> V_143 & V_144 ) &&
1 == V_10 -> V_95 ) {
F_32 ( V_10 , V_136 -> V_91 ) ;
return 0 ;
}
return 0 ;
}
static int F_57 ( struct V_6 * V_7 , struct V_46 * V_47 ,
T_3 * V_38 , int V_58 )
{
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
int V_89 = 0 ;
if ( 1 == V_9 -> V_10 -> V_95 ) {
if ( V_47 -> V_48 == V_38 [ 0 ] )
switch ( V_47 -> V_48 ) {
case 0x01 :
case 0x03 :
case 0x04 :
V_89 = F_31 ( V_9 -> V_10 ,
V_47 -> V_48 , V_38 , V_58 ) ;
break;
}
}
return V_89 ;
}
static int F_58 ( struct V_6 * V_7 , const struct V_145 * V_48 )
{
int V_89 ;
struct V_146 * V_147 = F_59 ( V_7 -> V_2 . V_148 ) ;
unsigned short V_95 = V_147 -> V_149 -> V_150 . V_151 ;
unsigned long V_152 = V_48 -> V_153 ;
struct V_8 * V_9 ;
struct V_27 * V_10 = NULL ;
V_9 = F_60 ( sizeof( * V_9 ) , V_154 ) ;
if ( V_9 == NULL ) {
F_22 ( V_7 , L_28 ) ;
return - V_116 ;
}
V_9 -> V_7 = V_7 ;
V_10 = F_60 ( sizeof( * V_10 ) , V_154 ) ;
if ( V_10 == NULL ) {
F_22 ( V_7 , L_28 ) ;
V_89 = - V_116 ;
goto V_155;
}
V_10 -> V_9 = V_9 ;
V_9 -> V_10 = V_10 ;
V_10 -> V_95 = V_95 ;
F_61 ( V_7 , V_9 ) ;
V_89 = F_62 ( V_7 ) ;
if ( V_89 ) {
F_22 ( V_7 , L_29 ) ;
goto V_155;
}
if ( V_152 & V_156 ) {
V_7 -> V_152 |= V_157 ;
}
V_89 = F_63 ( V_7 , V_158 ) ;
if ( V_89 ) {
F_22 ( V_7 , L_30 ) ;
goto V_155;
}
V_89 = F_39 ( V_10 ) ;
if ( V_89 < 0 )
goto V_159;
return 0 ;
V_159:
F_64 ( V_7 ) ;
V_155:
if ( V_10 != NULL )
F_65 ( V_10 ) ;
F_65 ( V_9 ) ;
return V_89 ;
}
static void F_66 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) F_3 ( V_7 ) ;
struct V_27 * V_10 ;
V_10 = V_9 -> V_10 ;
if ( V_10 ) {
F_51 ( V_10 ) ;
F_65 ( V_10 ) ;
}
F_64 ( V_7 ) ;
F_65 ( V_9 ) ;
}
static int F_67 ( void )
{
int V_89 ;
V_89 = F_68 ( & V_160 ) ;
if ( V_89 )
F_69 ( L_31 ) ;
return V_89 ;
}
static void F_70 ( void )
{
F_71 ( & V_160 ) ;
}
