int F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , F_3 ( struct V_2 ) ,
0 , NULL ) ;
if ( ! V_1 ) {
F_4 ( L_2
L_3 ) ;
goto V_3;
}
V_4 = F_2 ( L_4 ,
sizeof( struct V_5 ) , F_3 ( struct V_5 ) ,
0 , NULL ) ;
if ( ! V_4 ) {
F_4 ( L_5 ) ;
goto V_6;
}
V_7 = F_2 ( L_6 ,
sizeof( struct V_8 ) ,
F_3 ( struct V_8 ) , 0 , NULL ) ;
if ( ! V_7 ) {
F_4 ( L_7
L_3 ) ;
goto V_9;
}
V_10 = F_2 ( L_8 ,
sizeof( struct V_11 ) , F_3 ( struct V_11 ) ,
0 , NULL ) ;
if ( ! V_10 ) {
F_4 ( L_9
L_3 ) ;
goto V_12;
}
V_13 = F_2 ( L_10 ,
sizeof( struct V_14 ) ,
F_3 ( struct V_14 ) , 0 , NULL ) ;
if ( ! V_13 ) {
F_4 ( L_11
L_12 ) ;
goto V_15;
}
V_16 = F_2 ( L_13 ,
sizeof( struct V_17 ) ,
F_3 ( struct V_17 ) , 0 , NULL ) ;
if ( ! V_16 ) {
F_4 ( L_14
L_12 ) ;
goto V_18;
}
V_19 = F_2 (
L_15 ,
sizeof( struct V_20 ) ,
F_3 ( struct V_20 ) ,
0 , NULL ) ;
if ( ! V_19 ) {
F_4 ( L_14
L_16 ) ;
goto V_21;
}
V_22 = F_5 ( L_17 ,
V_23 , 0 ) ;
if ( ! V_22 )
goto V_24;
return 0 ;
V_24:
F_6 ( V_19 ) ;
V_21:
F_6 ( V_16 ) ;
V_18:
F_6 ( V_13 ) ;
V_15:
F_6 ( V_10 ) ;
V_12:
F_6 ( V_7 ) ;
V_9:
F_6 ( V_4 ) ;
V_6:
F_6 ( V_1 ) ;
V_3:
return - V_25 ;
}
void F_7 ( void )
{
F_8 ( V_22 ) ;
F_6 ( V_1 ) ;
F_6 ( V_4 ) ;
F_6 ( V_7 ) ;
F_6 ( V_10 ) ;
F_6 ( V_13 ) ;
F_6 ( V_16 ) ;
F_6 ( V_19 ) ;
}
T_1 F_9 ( T_2 type )
{
T_1 V_26 ;
F_10 ( ( type < 0 ) || ( type >= V_27 ) ) ;
F_11 ( & V_28 ) ;
V_26 = ++ V_29 [ type ] ;
F_12 ( & V_28 ) ;
return V_26 ;
}
void F_13 ( void )
{
int V_30 ;
static int V_31 ;
if ( V_31 )
return;
V_30 = F_14 ( L_18 ) ;
if ( V_30 != 0 )
F_4 ( L_19 ) ;
V_30 = F_14 ( L_20 ) ;
if ( V_30 != 0 )
F_4 ( L_21 ) ;
V_30 = F_14 ( L_22 ) ;
if ( V_30 != 0 )
F_4 ( L_23 ) ;
V_31 = 1 ;
}
struct V_2 * F_15 ( void )
{
struct V_2 * V_32 ;
V_32 = F_16 ( V_1 , V_33 ) ;
if ( ! V_32 ) {
F_4 ( L_24
L_25 ) ;
return F_17 ( - V_25 ) ;
}
F_18 ( & V_32 -> V_34 ) ;
F_18 ( & V_32 -> V_35 ) ;
F_18 ( & V_32 -> V_36 ) ;
F_18 ( & V_32 -> V_37 ) ;
F_19 ( & V_32 -> V_38 ) ;
F_20 ( & V_32 -> V_39 ) ;
return V_32 ;
}
void F_21 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_2 * V_32 ,
void * V_44 )
{
unsigned char V_45 [ V_46 ] ;
V_32 -> V_41 = V_41 ;
V_32 -> V_44 = V_44 ;
if ( V_43 ) {
if ( V_41 -> V_47 -> V_48 != NULL ) {
memset ( & V_45 [ 0 ] , 0 , V_46 ) ;
V_41 -> V_47 -> V_48 ( V_32 ,
& V_45 [ 0 ] , V_46 ) ;
V_32 -> V_49 = F_22 ( & V_45 [ 0 ] ) ;
}
F_23 ( & V_43 -> V_50 ) ;
F_24 ( & V_43 -> V_51 ) ;
V_43 -> V_52 = V_32 ;
F_25 ( & V_32 -> V_35 ,
& V_43 -> V_53 ) ;
F_26 ( & V_43 -> V_51 ) ;
}
F_25 ( & V_32 -> V_34 , & V_41 -> V_54 ) ;
F_27 ( L_26 ,
V_41 -> V_47 -> V_55 () , V_32 -> V_44 ) ;
}
void F_28 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_2 * V_32 ,
void * V_44 )
{
unsigned long V_56 ;
F_29 ( & V_41 -> V_57 , V_56 ) ;
F_21 ( V_41 , V_43 , V_32 , V_44 ) ;
F_30 ( & V_41 -> V_57 , V_56 ) ;
}
static void F_31 ( struct V_58 * V_58 )
{
struct V_2 * V_32 = F_32 ( V_58 ,
struct V_2 , V_39 ) ;
struct V_40 * V_41 = V_32 -> V_41 ;
V_41 -> V_47 -> V_59 ( V_32 ) ;
}
void F_33 ( struct V_2 * V_32 )
{
F_23 ( & V_32 -> V_39 ) ;
}
void F_34 ( struct V_2 * V_32 )
{
struct V_40 * V_60 = V_32 -> V_41 ;
if ( V_60 -> V_47 -> V_61 != NULL ) {
V_60 -> V_47 -> V_61 ( V_32 ) ;
return;
}
F_35 ( & V_32 -> V_39 , F_31 ) ;
}
static void F_36 ( struct V_58 * V_58 )
{
struct V_42 * V_62 = F_32 ( V_58 ,
struct V_42 , V_50 ) ;
F_37 ( & V_62 -> V_63 ) ;
}
void F_38 ( struct V_42 * V_62 )
{
F_35 ( & V_62 -> V_50 , F_36 ) ;
}
void F_39 ( struct V_2 * V_32 )
{
struct V_42 * V_43 ;
unsigned long V_56 ;
V_43 = V_32 -> V_42 ;
if ( V_43 ) {
F_29 ( & V_43 -> V_51 , V_56 ) ;
if ( V_43 -> V_64 == 0 )
F_40 ( & V_32 -> V_35 ) ;
if ( F_41 ( & V_43 -> V_53 ) )
V_43 -> V_52 = NULL ;
else {
V_43 -> V_52 = F_32 (
V_43 -> V_53 . V_65 ,
struct V_2 , V_35 ) ;
}
F_30 ( & V_43 -> V_51 , V_56 ) ;
}
}
void F_42 ( struct V_2 * V_32 )
{
F_43 ( V_1 , V_32 ) ;
}
void F_44 ( struct V_2 * V_32 )
{
struct V_40 * V_41 = V_32 -> V_41 ;
struct V_66 * V_67 ;
struct V_42 * V_43 ;
unsigned long V_56 ;
bool V_68 = true ;
if ( ! V_41 ) {
F_42 ( V_32 ) ;
return;
}
V_67 = V_41 -> V_47 ;
F_29 ( & V_41 -> V_57 , V_56 ) ;
F_40 ( & V_32 -> V_34 ) ;
V_32 -> V_41 = NULL ;
V_32 -> V_44 = NULL ;
F_30 ( & V_41 -> V_57 , V_56 ) ;
V_43 = V_32 -> V_42 ;
F_29 ( & V_41 -> V_69 , V_56 ) ;
if ( V_43 && V_43 -> V_70 ) {
if ( ! V_67 -> V_71 ( V_41 ) ) {
F_40 ( & V_43 -> V_72 ) ;
V_41 -> V_73 -- ;
F_30 ( & V_41 -> V_69 , V_56 ) ;
F_45 ( V_43 ) ;
F_46 ( V_43 , V_41 ) ;
V_67 -> V_74 ( V_41 , V_43 ) ;
V_68 = false ;
F_29 ( & V_41 -> V_69 , V_56 ) ;
}
}
F_30 ( & V_41 -> V_69 , V_56 ) ;
F_27 ( L_27 ,
V_41 -> V_47 -> V_55 () ) ;
if ( V_43 && V_68 == true )
F_38 ( V_43 ) ;
F_42 ( V_32 ) ;
}
static void F_47 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
unsigned long V_56 ;
if ( ! V_78 )
return;
if ( V_76 -> V_80 & V_81 )
return;
F_29 ( & V_78 -> V_82 , V_56 ) ;
if ( V_76 -> V_83 ) {
F_40 ( & V_76 -> V_84 ) ;
V_76 -> V_83 = false ;
}
F_30 ( & V_78 -> V_82 , V_56 ) ;
}
static int F_48 ( struct V_75 * V_76 , bool V_85 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_80 & V_87 ) {
F_27 ( L_28 ,
V_88 , __LINE__ , V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_90 ;
if ( V_85 )
F_47 ( V_76 ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_37 ( & V_76 -> V_91 ) ;
return 1 ;
}
if ( V_85 ) {
F_47 ( V_76 ) ;
V_76 -> V_92 = NULL ;
}
if ( V_76 -> V_80 & V_93 ) {
F_27 ( L_29 ,
V_88 , __LINE__ ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_37 ( & V_76 -> V_94 ) ;
return 1 ;
}
V_76 -> V_80 &= ~ V_90 ;
if ( V_85 ) {
if ( V_76 -> V_67 -> V_95 != NULL ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return V_76 -> V_67 -> V_95 ( V_76 ) ;
}
}
F_30 ( & V_76 -> V_86 , V_56 ) ;
return 0 ;
}
static int F_49 ( struct V_75 * V_76 )
{
return F_48 ( V_76 , true ) ;
}
static void F_50 ( struct V_75 * V_76 )
{
struct V_92 * V_96 = V_76 -> V_92 ;
unsigned long V_56 ;
if ( ! V_96 )
return;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_80 & V_97 ) {
V_76 -> V_80 &= ~ V_97 ;
F_47 ( V_76 ) ;
}
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_29 ( & V_96 -> V_98 , V_56 ) ;
if ( ! F_41 ( & V_76 -> V_99 ) )
F_51 ( & V_76 -> V_99 ) ;
F_30 ( & V_96 -> V_98 , V_56 ) ;
}
void F_52 ( struct V_75 * V_76 , int remove )
{
if ( F_49 ( V_76 ) )
return;
if ( remove )
F_53 ( V_76 ) ;
}
static void F_54 ( struct V_100 * V_101 )
{
struct V_75 * V_76 = F_32 ( V_101 , struct V_75 , V_101 ) ;
F_55 ( V_76 ,
V_102 ) ;
}
static unsigned char * F_56 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
F_57 ( ! V_76 -> V_92 ) ;
if ( ! V_78 )
return NULL ;
if ( V_76 -> V_103 & V_104 )
return NULL ;
V_76 -> V_105 = V_106 ;
F_27 ( L_30 ,
V_78 -> V_107 -> V_108 , V_78 -> V_109 -> V_110 , V_76 -> V_111 ) ;
return V_76 -> V_112 ;
}
void F_58 ( struct V_75 * V_76 , T_3 V_111 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
int V_113 = V_111 == V_114 ;
unsigned long V_56 ;
V_76 -> V_111 = V_111 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
V_76 -> V_80 &= ~ V_81 ;
if ( V_78 && V_78 -> V_109 -> V_115 ) {
V_78 -> V_109 -> V_115 ( V_76 ,
V_76 -> V_116 ,
F_56 ( V_76 ) ) ;
if ( V_76 -> V_103 & V_117 )
V_113 = 1 ;
}
if ( V_76 -> V_80 & V_118 ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_37 ( & V_76 -> V_119 ) ;
return;
}
if ( ! V_113 )
V_76 -> V_80 |= V_120 ;
if ( V_76 -> V_80 & V_121 &&
V_76 -> V_80 & V_93 ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_37 ( & V_76 -> V_94 ) ;
return;
} else if ( V_76 -> V_80 & V_120 ) {
F_59 ( & V_76 -> V_101 , F_54 ) ;
} else {
F_59 ( & V_76 -> V_101 , V_122 ) ;
}
V_76 -> V_123 = V_124 ;
V_76 -> V_80 |= ( V_125 | V_90 ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_60 ( V_22 , & V_76 -> V_101 ) ;
}
static void F_61 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
unsigned long V_56 ;
F_29 ( & V_78 -> V_82 , V_56 ) ;
if ( ! V_76 -> V_83 ) {
F_25 ( & V_76 -> V_84 , & V_78 -> V_84 ) ;
V_76 -> V_83 = true ;
}
F_30 ( & V_78 -> V_82 , V_56 ) ;
}
void F_62 ( struct V_100 * V_101 )
{
struct V_77 * V_78 = F_32 ( V_101 , struct V_77 ,
V_126 ) ;
F_63 ( V_127 ) ;
struct V_75 * V_76 , * V_128 ;
F_24 ( & V_78 -> V_129 ) ;
F_64 ( & V_78 -> V_127 , & V_127 ) ;
F_26 ( & V_78 -> V_129 ) ;
F_65 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_40 ( & V_76 -> V_130 ) ;
F_66 ( & V_78 -> V_131 ) ;
F_67 () ;
F_27 ( L_31
L_32 , V_76 -> V_67 -> V_55 () , V_76 ,
( V_76 -> V_123 == V_132 ) ? L_33 :
( V_76 -> V_123 == V_133 ) ? L_34
: L_35 ) ;
if ( V_76 -> V_123 == V_133 )
F_68 ( V_76 ) ;
else if ( V_76 -> V_123 == V_132 )
F_69 ( V_76 ) ;
}
}
unsigned char * F_70 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_134 ) {
case V_135 :
return L_36 ;
case V_136 :
return L_37 ;
case V_137 :
return L_38 ;
case V_138 :
return L_39 ;
default:
break;
}
return L_35 ;
}
void F_71 (
struct V_77 * V_78 ,
char * V_139 ,
int * V_140 )
{
* V_140 += sprintf ( V_139 + * V_140 , L_40 ) ;
if ( V_78 -> V_141 )
* V_140 += sprintf ( V_139 + * V_140 , L_41 ) ;
else
* V_140 += sprintf ( V_139 + * V_140 , L_42 ) ;
* V_140 += sprintf ( V_139 + * V_140 , L_43 , V_78 -> V_142 ) ;
* V_140 += sprintf ( V_139 + * V_140 , L_44 ,
V_78 -> V_143 . V_144 ,
V_78 -> V_143 . V_145 ) ;
* V_140 += sprintf ( V_139 + * V_140 , L_45 ) ;
}
void F_72 (
struct V_146 * V_147 ,
unsigned char * V_148 ,
int V_149 )
{
unsigned char V_45 [ V_150 ] ;
int V_151 ;
memset ( V_45 , 0 , V_150 ) ;
V_151 = sprintf ( V_45 , L_46 ) ;
switch ( V_147 -> V_152 ) {
case 0x00 :
sprintf ( V_45 + V_151 , L_47 ) ;
break;
case 0x10 :
sprintf ( V_45 + V_151 , L_48 ) ;
break;
case 0x20 :
sprintf ( V_45 + V_151 , L_49 ) ;
break;
case 0x30 :
sprintf ( V_45 + V_151 , L_50 ) ;
break;
case 0x40 :
sprintf ( V_45 + V_151 , L_51
L_52 ) ;
break;
case 0x50 :
sprintf ( V_45 + V_151 , L_53 ) ;
break;
case 0x60 :
sprintf ( V_45 + V_151 , L_54 ) ;
break;
case 0x70 :
sprintf ( V_45 + V_151 , L_55
L_52 ) ;
break;
case 0x80 :
sprintf ( V_45 + V_151 , L_56 ) ;
break;
default:
sprintf ( V_45 + V_151 , L_57 ,
V_147 -> V_152 ) ;
break;
}
if ( V_148 )
strncpy ( V_148 , V_45 , V_149 ) ;
else
F_27 ( L_58 , V_45 ) ;
}
void
F_73 ( struct V_146 * V_147 , unsigned char * V_153 )
{
if ( V_153 [ 1 ] & 0x80 ) {
V_147 -> V_152 = ( V_153 [ 0 ] & 0xf0 ) ;
V_147 -> V_154 = 1 ;
F_72 ( V_147 , NULL , 0 ) ;
}
}
int F_74 (
struct V_146 * V_147 ,
unsigned char * V_148 ,
int V_149 )
{
unsigned char V_45 [ V_150 ] ;
int V_30 = 0 ;
int V_151 ;
memset ( V_45 , 0 , V_150 ) ;
V_151 = sprintf ( V_45 , L_59 ) ;
switch ( V_147 -> V_155 ) {
case 0x00 :
sprintf ( V_45 + V_151 , L_60 ) ;
break;
case 0x10 :
sprintf ( V_45 + V_151 , L_61 ) ;
break;
case 0x20 :
sprintf ( V_45 + V_151 , L_62 ) ;
break;
default:
sprintf ( V_45 + V_151 , L_57 , V_147 -> V_155 ) ;
V_30 = - V_156 ;
break;
}
if ( V_148 )
strncpy ( V_148 , V_45 , V_149 ) ;
else
F_27 ( L_58 , V_45 ) ;
return V_30 ;
}
int F_75 ( struct V_146 * V_147 , unsigned char * V_153 )
{
V_147 -> V_155 = ( V_153 [ 1 ] & 0x30 ) ;
return F_74 ( V_147 , NULL , 0 ) ;
}
int F_76 (
struct V_146 * V_147 ,
unsigned char * V_148 ,
int V_149 )
{
unsigned char V_45 [ V_150 ] ;
int V_30 = 0 ;
int V_151 ;
memset ( V_45 , 0 , V_150 ) ;
V_151 = sprintf ( V_45 , L_63 ) ;
switch ( V_147 -> V_157 ) {
case 0x00 :
sprintf ( V_45 + V_151 , L_64 ) ;
break;
case 0x01 :
sprintf ( V_45 + V_151 , L_65 ) ;
break;
case 0x02 :
sprintf ( V_45 + V_151 , L_66 ) ;
break;
case 0x03 :
sprintf ( V_45 + V_151 , L_67 ) ;
break;
case 0x04 :
sprintf ( V_45 + V_151 , L_68 ) ;
break;
case 0x08 :
sprintf ( V_45 + V_151 , L_69 ) ;
break;
default:
sprintf ( V_45 + V_151 , L_70 ,
V_147 -> V_157 ) ;
V_30 = - V_156 ;
break;
}
if ( V_148 ) {
if ( V_149 < strlen ( V_45 ) + 1 )
return - V_156 ;
strncpy ( V_148 , V_45 , V_149 ) ;
} else {
F_27 ( L_58 , V_45 ) ;
}
return V_30 ;
}
int F_77 ( struct V_146 * V_147 , unsigned char * V_153 )
{
V_147 -> V_157 = ( V_153 [ 1 ] & 0x0f ) ;
return F_76 ( V_147 , NULL , 0 ) ;
}
int F_78 (
struct V_146 * V_147 ,
unsigned char * V_148 ,
int V_149 )
{
unsigned char V_45 [ V_150 ] ;
int V_30 = 0 ;
memset ( V_45 , 0 , V_150 ) ;
switch ( V_147 -> V_158 ) {
case 0x01 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_71 ,
& V_147 -> V_159 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_72 ,
& V_147 -> V_159 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_73 ,
& V_147 -> V_159 [ 0 ] ) ;
break;
default:
sprintf ( V_45 , L_74
L_75 , V_147 -> V_158 ) ;
V_30 = - V_156 ;
break;
}
if ( V_148 )
strncpy ( V_148 , V_45 , V_149 ) ;
else
F_27 ( L_58 , V_45 ) ;
return V_30 ;
}
int
F_79 ( struct V_146 * V_147 , unsigned char * V_153 )
{
static const char V_160 [] = L_76 ;
int V_161 = 0 , V_162 = 4 ;
V_147 -> V_158 = ( V_153 [ 0 ] & 0x0f ) ;
switch ( V_147 -> V_158 ) {
case 0x01 :
V_147 -> V_159 [ V_161 ++ ] =
V_160 [ V_147 -> V_157 ] ;
while ( V_162 < ( 4 + V_153 [ 3 ] ) ) {
V_147 -> V_159 [ V_161 ++ ] =
V_160 [ ( V_153 [ V_162 ] & 0xf0 ) >> 4 ] ;
V_147 -> V_159 [ V_161 ++ ] =
V_160 [ V_153 [ V_162 ] & 0x0f ] ;
V_162 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_162 < ( 4 + V_153 [ 3 ] ) )
V_147 -> V_159 [ V_161 ++ ] = V_153 [ V_162 ++ ] ;
break;
default:
break;
}
return F_78 ( V_147 , NULL , 0 ) ;
}
T_4
F_80 ( struct V_75 * V_76 , unsigned int V_163 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_76 -> V_164 ) {
V_76 -> V_165 = V_163 ;
} else if ( V_163 != V_76 -> V_165 ) {
F_81 ( L_77
L_78
L_79 , V_76 -> V_67 -> V_55 () ,
V_76 -> V_165 , V_163 , V_76 -> V_166 [ 0 ] ) ;
if ( V_76 -> V_134 == V_137 ) {
F_4 ( L_80
L_81 ) ;
return V_167 ;
}
if ( V_78 -> V_143 . V_144 != 512 ) {
F_4 ( L_82
L_83
L_84 , V_78 -> V_109 -> V_110 ) ;
return V_167 ;
}
if ( V_163 > V_76 -> V_165 ) {
V_76 -> V_103 |= V_168 ;
V_76 -> V_169 = ( V_163 - V_76 -> V_165 ) ;
} else {
V_76 -> V_103 |= V_170 ;
V_76 -> V_169 = ( V_76 -> V_165 - V_163 ) ;
V_76 -> V_165 = V_163 ;
}
}
return 0 ;
}
void F_82 (
struct V_75 * V_76 ,
struct V_66 * V_171 ,
struct V_2 * V_32 ,
T_1 V_165 ,
int V_134 ,
int V_172 ,
unsigned char * V_112 )
{
F_18 ( & V_76 -> V_99 ) ;
F_18 ( & V_76 -> V_173 ) ;
F_18 ( & V_76 -> V_130 ) ;
F_18 ( & V_76 -> V_174 ) ;
F_18 ( & V_76 -> V_84 ) ;
F_83 ( & V_76 -> V_175 ) ;
F_83 ( & V_76 -> V_91 ) ;
F_83 ( & V_76 -> V_94 ) ;
F_83 ( & V_76 -> V_176 ) ;
F_83 ( & V_76 -> V_119 ) ;
F_19 ( & V_76 -> V_86 ) ;
V_76 -> V_80 = V_97 ;
V_76 -> V_67 = V_171 ;
V_76 -> V_32 = V_32 ;
V_76 -> V_165 = V_165 ;
V_76 -> V_134 = V_134 ;
V_76 -> V_177 = V_172 ;
V_76 -> V_112 = V_112 ;
V_76 -> V_83 = false ;
}
static T_4
F_84 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_109 -> V_178 == V_179 )
return 0 ;
if ( V_76 -> V_177 == V_180 ) {
F_27 ( L_85
L_86 ) ;
return V_167 ;
}
V_76 -> V_181 = F_85 ( & V_78 -> V_182 ) ;
F_86 () ;
F_27 ( L_87 ,
V_76 -> V_181 , V_76 -> V_177 ,
V_78 -> V_109 -> V_110 ) ;
return 0 ;
}
T_4
F_87 ( struct V_75 * V_76 , unsigned char * V_183 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
unsigned long V_56 ;
T_4 V_30 ;
if ( F_88 ( V_183 ) > V_184 ) {
F_4 ( L_88
L_89 ,
F_88 ( V_183 ) , V_184 ) ;
return V_167 ;
}
if ( F_88 ( V_183 ) > sizeof( V_76 -> V_185 ) ) {
V_76 -> V_166 = F_89 ( F_88 ( V_183 ) ,
V_33 ) ;
if ( ! V_76 -> V_166 ) {
F_4 ( L_90
L_91 ,
F_88 ( V_183 ) ,
( unsigned long ) sizeof( V_76 -> V_185 ) ) ;
return V_186 ;
}
} else
V_76 -> V_166 = & V_76 -> V_185 [ 0 ] ;
memcpy ( V_76 -> V_166 , V_183 , F_88 ( V_183 ) ) ;
V_30 = F_90 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_91 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_92 ( V_76 ) ;
if ( V_30 ) {
V_76 -> V_111 = V_187 ;
return V_30 ;
}
V_30 = V_78 -> V_109 -> V_188 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_84 ( V_76 ) ;
if ( V_30 )
return V_30 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
V_76 -> V_103 |= V_189 ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_11 ( & V_76 -> V_92 -> V_190 ) ;
if ( V_76 -> V_92 -> V_191 )
V_76 -> V_92 -> V_191 -> V_192 . V_193 ++ ;
F_12 ( & V_76 -> V_92 -> V_190 ) ;
return 0 ;
}
int F_93 (
struct V_75 * V_76 )
{
T_4 V_30 ;
if ( ! V_76 -> V_92 ) {
F_94 () ;
F_4 ( L_92 ) ;
return - V_156 ;
}
if ( F_95 () ) {
F_94 () ;
F_4 ( L_93
L_94 ) ;
return - V_156 ;
}
V_76 -> V_123 = V_194 ;
V_76 -> V_80 |= V_90 ;
V_30 = F_96 ( V_76 ) ;
if ( V_30 )
F_55 ( V_76 , V_30 ) ;
return 0 ;
}
static T_4
F_97 ( struct V_75 * V_76 , struct V_195 * V_196 ,
T_1 V_197 , struct V_195 * V_198 , T_1 V_199 )
{
if ( ! V_196 || ! V_197 )
return 0 ;
if ( V_76 -> V_103 & V_168 ) {
F_81 ( L_95
L_96 ) ;
return V_167 ;
}
V_76 -> V_116 = V_196 ;
V_76 -> V_200 = V_197 ;
if ( V_198 && V_199 ) {
V_76 -> V_201 = V_198 ;
V_76 -> V_202 = V_199 ;
}
V_76 -> V_103 |= V_203 ;
return 0 ;
}
int F_98 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_183 , unsigned char * V_204 , T_1 V_205 ,
T_1 V_165 , int V_172 , int V_206 , int V_56 ,
struct V_195 * V_196 , T_1 V_197 ,
struct V_195 * V_198 , T_1 V_199 )
{
struct V_40 * V_41 ;
T_4 V_207 ;
int V_30 ;
V_41 = V_32 -> V_41 ;
F_10 ( ! V_41 ) ;
F_10 ( V_75 -> V_67 || V_75 -> V_32 ) ;
F_10 ( F_95 () ) ;
F_82 ( V_75 , V_41 -> V_47 , V_32 ,
V_165 , V_206 , V_172 , V_204 ) ;
if ( V_56 & V_208 )
V_75 -> V_164 = 1 ;
V_30 = F_99 ( V_32 , V_75 , ( V_56 & V_209 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_56 & V_210 )
V_75 -> V_103 |= V_211 ;
V_207 = F_100 ( V_75 , V_205 ) ;
if ( V_207 ) {
F_101 ( V_75 , V_207 , 0 ) ;
F_102 ( V_32 , V_75 ) ;
return 0 ;
}
V_207 = F_87 ( V_75 , V_183 ) ;
if ( V_207 != 0 ) {
F_55 ( V_75 , V_207 ) ;
return 0 ;
}
if ( V_197 != 0 ) {
F_10 ( ! V_196 ) ;
if ( ! ( V_75 -> V_103 & V_212 ) &&
V_75 -> V_134 == V_136 ) {
unsigned char * V_45 = NULL ;
if ( V_196 )
V_45 = F_103 ( F_104 ( V_196 ) ) + V_196 -> V_213 ;
if ( V_45 ) {
memset ( V_45 , 0 , V_196 -> V_214 ) ;
F_105 ( F_104 ( V_196 ) ) ;
}
}
V_207 = F_97 ( V_75 , V_196 , V_197 ,
V_198 , V_199 ) ;
if ( V_207 != 0 ) {
F_55 ( V_75 , V_207 ) ;
return 0 ;
}
}
F_106 ( V_75 ) ;
F_93 ( V_75 ) ;
return 0 ;
}
int F_107 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_183 , unsigned char * V_204 , T_1 V_205 ,
T_1 V_165 , int V_172 , int V_206 , int V_56 )
{
return F_98 ( V_75 , V_32 , V_183 , V_204 ,
V_205 , V_165 , V_172 , V_206 ,
V_56 , NULL , 0 , NULL , 0 ) ;
}
static void F_108 ( struct V_100 * V_101 )
{
struct V_75 * V_75 = F_32 ( V_101 , struct V_75 , V_101 ) ;
V_75 -> V_215 -> V_216 = V_217 ;
V_75 -> V_67 -> V_218 ( V_75 ) ;
F_49 ( V_75 ) ;
}
int F_109 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_204 , T_1 V_205 ,
void * V_219 , unsigned char V_220 ,
T_5 V_221 , unsigned int V_222 , int V_56 )
{
struct V_40 * V_41 ;
int V_30 ;
V_41 = V_32 -> V_41 ;
F_10 ( ! V_41 ) ;
F_82 ( V_75 , V_41 -> V_47 , V_32 ,
0 , V_135 , V_223 , V_204 ) ;
V_30 = F_110 ( V_75 , V_219 , V_220 , V_221 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_220 == V_224 )
V_75 -> V_215 -> V_225 = V_222 ;
V_30 = F_99 ( V_32 , V_75 , ( V_56 & V_209 ) ) ;
if ( V_30 ) {
F_111 ( V_75 -> V_215 ) ;
return V_30 ;
}
V_30 = F_112 ( V_75 , V_205 ) ;
if ( V_30 ) {
F_59 ( & V_75 -> V_101 , F_108 ) ;
F_113 ( & V_75 -> V_101 ) ;
return 0 ;
}
F_114 ( V_75 ) ;
return 0 ;
}
bool F_115 ( struct V_75 * V_76 , unsigned long * V_56 )
{
bool V_226 = false ;
if ( V_76 -> V_80 & V_81 ) {
V_76 -> V_80 |= V_118 ;
F_30 ( & V_76 -> V_86 , * V_56 ) ;
F_27 ( L_97 , V_76 ) ;
F_116 ( & V_76 -> V_119 ) ;
F_27 ( L_98 , V_76 ) ;
F_29 ( & V_76 -> V_86 , * V_56 ) ;
V_76 -> V_80 &= ~ V_118 ;
V_76 -> V_80 &= ~ V_81 ;
V_226 = true ;
}
return V_226 ;
}
void F_55 ( struct V_75 * V_76 ,
T_4 V_227 )
{
int V_30 = 0 ;
F_27 ( L_99
L_100 , V_76 , V_76 -> V_67 -> V_89 ( V_76 ) ,
V_76 -> V_166 [ 0 ] ) ;
F_27 ( L_101 ,
V_76 -> V_67 -> V_228 ( V_76 ) ,
V_76 -> V_123 , V_227 ) ;
F_27 ( L_102 ,
( V_76 -> V_80 & V_90 ) != 0 ,
( V_76 -> V_80 & V_93 ) != 0 ,
( V_76 -> V_80 & V_229 ) != 0 ) ;
F_117 ( V_76 ) ;
switch ( V_227 ) {
case V_230 :
case V_231 :
case V_167 :
case V_232 :
case V_233 :
case V_102 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
break;
case V_186 :
V_227 = V_102 ;
break;
case V_240 :
V_76 -> V_111 = V_187 ;
if ( V_76 -> V_32 &&
V_76 -> V_79 -> V_143 . V_241 == 2 )
F_118 ( V_76 -> V_32 -> V_42 ,
V_76 -> V_242 , 0x2C ,
V_243 ) ;
V_30 = V_76 -> V_67 -> V_244 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
goto V_247;
default:
F_4 ( L_103 ,
V_76 -> V_166 [ 0 ] , V_227 ) ;
V_227 = V_231 ;
break;
}
V_30 = F_101 ( V_76 , V_227 , 0 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
V_247:
F_50 ( V_76 ) ;
if ( ! F_49 ( V_76 ) )
;
return;
V_246:
V_76 -> V_123 = V_132 ;
F_119 ( V_76 , V_76 -> V_79 ) ;
}
static void F_120 ( struct V_75 * V_76 )
{
T_4 V_30 ;
F_24 ( & V_76 -> V_86 ) ;
V_76 -> V_80 |= ( V_81 | V_229 ) ;
F_26 ( & V_76 -> V_86 ) ;
if ( V_76 -> V_248 ) {
V_30 = V_76 -> V_248 ( V_76 ) ;
if ( V_30 ) {
F_24 ( & V_76 -> V_86 ) ;
V_76 -> V_80 &= ~ ( V_81 | V_229 ) ;
F_26 ( & V_76 -> V_86 ) ;
F_55 ( V_76 , V_30 ) ;
}
}
}
static bool F_121 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_109 -> V_178 == V_179 )
return false ;
switch ( V_76 -> V_177 ) {
case V_249 :
F_27 ( L_104
L_105 ,
V_76 -> V_166 [ 0 ] , V_76 -> V_181 ) ;
return false ;
case V_250 :
F_122 ( & V_78 -> V_251 ) ;
F_86 () ;
F_27 ( L_106
L_107 ,
V_76 -> V_166 [ 0 ] , V_76 -> V_181 ) ;
if ( ! F_123 ( & V_78 -> V_252 ) )
return false ;
break;
default:
F_122 ( & V_78 -> V_252 ) ;
F_86 () ;
break;
}
if ( F_123 ( & V_78 -> V_251 ) == 0 )
return false ;
F_11 ( & V_78 -> V_253 ) ;
F_25 ( & V_76 -> V_173 , & V_78 -> V_254 ) ;
F_12 ( & V_78 -> V_253 ) ;
F_27 ( L_108
L_109 ,
V_76 -> V_166 [ 0 ] , V_76 -> V_177 ,
V_76 -> V_181 ) ;
return true ;
}
void F_124 ( struct V_75 * V_76 )
{
if ( F_125 ( V_76 , 1 ) ) {
F_37 ( & V_76 -> V_91 ) ;
return;
}
F_24 ( & V_76 -> V_86 ) ;
if ( V_76 -> V_80 & V_87 ) {
F_27 ( L_28 ,
V_88 , __LINE__ , V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_90 ;
F_26 ( & V_76 -> V_86 ) ;
F_37 ( & V_76 -> V_91 ) ;
return;
}
if ( V_76 -> V_80 & V_93 ) {
F_27 ( L_29 ,
V_88 , __LINE__ ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_26 ( & V_76 -> V_86 ) ;
F_37 ( & V_76 -> V_94 ) ;
return;
}
V_76 -> V_123 = V_255 ;
V_76 -> V_80 |= V_90 ;
F_26 ( & V_76 -> V_86 ) ;
if ( ! F_121 ( V_76 ) )
F_120 ( V_76 ) ;
}
static void F_126 ( struct V_77 * V_78 )
{
for (; ; ) {
struct V_75 * V_76 ;
F_11 ( & V_78 -> V_253 ) ;
if ( F_41 ( & V_78 -> V_254 ) ) {
F_12 ( & V_78 -> V_253 ) ;
break;
}
V_76 = F_127 ( V_78 -> V_254 . V_256 ,
struct V_75 , V_173 ) ;
F_40 ( & V_76 -> V_173 ) ;
F_12 ( & V_78 -> V_253 ) ;
F_120 ( V_76 ) ;
if ( V_76 -> V_177 == V_250 )
break;
}
}
static void F_117 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_109 -> V_178 == V_179 )
return;
if ( V_76 -> V_177 == V_223 ) {
F_66 ( & V_78 -> V_252 ) ;
F_67 () ;
V_78 -> V_257 ++ ;
F_27 ( L_110
L_111 , V_78 -> V_257 ,
V_76 -> V_181 ) ;
} else if ( V_76 -> V_177 == V_249 ) {
V_78 -> V_257 ++ ;
F_27 ( L_112
L_113 , V_78 -> V_257 ,
V_76 -> V_181 ) ;
} else if ( V_76 -> V_177 == V_250 ) {
F_66 ( & V_78 -> V_251 ) ;
F_67 () ;
V_78 -> V_257 ++ ;
F_27 ( L_114
L_115 , V_78 -> V_257 , V_76 -> V_181 ) ;
}
F_126 ( V_78 ) ;
}
static void F_69 ( struct V_75 * V_76 )
{
int V_30 = 0 ;
F_117 ( V_76 ) ;
if ( V_76 -> V_103 & V_117 ) {
V_30 = V_76 -> V_67 -> V_244 ( V_76 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_76 -> V_134 ) {
case V_136 :
V_30 = V_76 -> V_67 -> V_258 ( V_76 ) ;
break;
case V_137 :
if ( V_76 -> V_201 ) {
V_30 = V_76 -> V_67 -> V_258 ( V_76 ) ;
if ( V_30 < 0 )
break;
}
case V_135 :
V_30 = V_76 -> V_67 -> V_244 ( V_76 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_119 ( V_76 , V_76 -> V_79 ) ;
return;
}
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
}
static void F_119 (
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
F_24 ( & V_78 -> V_129 ) ;
F_25 ( & V_76 -> V_130 , & V_76 -> V_79 -> V_127 ) ;
F_122 ( & V_78 -> V_131 ) ;
F_86 () ;
F_26 ( & V_76 -> V_79 -> V_129 ) ;
F_113 ( & V_76 -> V_79 -> V_126 ) ;
}
static void V_122 ( struct V_100 * V_101 )
{
struct V_75 * V_76 = F_32 ( V_101 , struct V_75 , V_101 ) ;
int V_30 ;
F_117 ( V_76 ) ;
if ( F_123 ( & V_76 -> V_79 -> V_131 ) != 0 )
F_113 ( & V_76 -> V_79 -> V_126 ) ;
if ( V_76 -> V_103 & V_117 ) {
F_57 ( ! V_76 -> V_111 ) ;
V_30 = F_101 (
V_76 , 0 , 1 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
return;
}
if ( V_76 -> V_259 )
V_76 -> V_259 ( V_76 ) ;
switch ( V_76 -> V_134 ) {
case V_136 :
F_11 ( & V_76 -> V_92 -> V_190 ) ;
if ( V_76 -> V_92 -> V_191 ) {
V_76 -> V_92 -> V_191 -> V_192 . V_260 +=
V_76 -> V_165 ;
}
F_12 ( & V_76 -> V_92 -> V_190 ) ;
V_30 = V_76 -> V_67 -> V_258 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
break;
case V_137 :
F_11 ( & V_76 -> V_92 -> V_190 ) ;
if ( V_76 -> V_92 -> V_191 ) {
V_76 -> V_92 -> V_191 -> V_192 . V_261 +=
V_76 -> V_165 ;
}
F_12 ( & V_76 -> V_92 -> V_190 ) ;
if ( V_76 -> V_201 ) {
F_11 ( & V_76 -> V_92 -> V_190 ) ;
if ( V_76 -> V_92 -> V_191 ) {
V_76 -> V_92 -> V_191 -> V_192 . V_260 +=
V_76 -> V_165 ;
}
F_12 ( & V_76 -> V_92 -> V_190 ) ;
V_30 = V_76 -> V_67 -> V_258 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
break;
}
case V_135 :
V_30 = V_76 -> V_67 -> V_244 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
break;
default:
break;
}
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
return;
V_246:
F_27 ( L_116
L_117 , V_76 , V_76 -> V_134 ) ;
V_76 -> V_123 = V_132 ;
F_119 ( V_76 , V_76 -> V_79 ) ;
}
static inline void F_128 ( struct V_195 * V_196 , int V_262 )
{
struct V_195 * V_263 ;
int V_264 ;
F_129 (sgl, sg, nents, count)
F_130 ( F_104 ( V_263 ) ) ;
F_131 ( V_196 ) ;
}
static inline void F_132 ( struct V_75 * V_76 )
{
if ( V_76 -> V_103 & V_203 )
return;
F_128 ( V_76 -> V_116 , V_76 -> V_200 ) ;
V_76 -> V_116 = NULL ;
V_76 -> V_200 = 0 ;
F_128 ( V_76 -> V_201 , V_76 -> V_202 ) ;
V_76 -> V_201 = NULL ;
V_76 -> V_202 = 0 ;
}
static int F_133 ( struct V_75 * V_76 )
{
F_10 ( ! V_76 -> V_67 ) ;
if ( V_76 -> V_103 & V_265 )
F_111 ( V_76 -> V_215 ) ;
if ( V_76 -> V_166 != V_76 -> V_185 )
F_131 ( V_76 -> V_166 ) ;
if ( V_76 -> V_266 != 0 )
return F_102 ( V_76 -> V_32 , V_76 ) ;
V_76 -> V_67 -> V_267 ( V_76 ) ;
return 1 ;
}
static int F_53 ( struct V_75 * V_76 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( F_123 ( & V_76 -> V_268 ) &&
! F_134 ( & V_76 -> V_268 ) ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return 0 ;
}
if ( V_76 -> V_80 & V_97 ) {
V_76 -> V_80 &= ~ V_97 ;
F_47 ( V_76 ) ;
}
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_132 ( V_76 ) ;
return F_133 ( V_76 ) ;
}
void * F_135 ( struct V_75 * V_76 )
{
struct V_195 * V_263 = V_76 -> V_116 ;
struct V_269 * * V_270 ;
int V_162 ;
if ( ! V_76 -> V_200 )
return NULL ;
F_10 ( ! V_263 ) ;
if ( V_76 -> V_200 == 1 )
return F_103 ( F_104 ( V_263 ) ) + V_263 -> V_213 ;
V_270 = F_136 ( sizeof( * V_270 ) * V_76 -> V_200 , V_33 ) ;
if ( ! V_270 )
return NULL ;
F_129 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_270 [ V_162 ] = F_104 ( V_263 ) ;
}
V_76 -> V_271 = F_137 ( V_270 , V_76 -> V_200 , V_272 , V_273 ) ;
F_131 ( V_270 ) ;
if ( ! V_76 -> V_271 )
return NULL ;
return V_76 -> V_271 + V_76 -> V_116 [ 0 ] . V_213 ;
}
void F_138 ( struct V_75 * V_76 )
{
if ( ! V_76 -> V_200 ) {
return;
} else if ( V_76 -> V_200 == 1 ) {
F_105 ( F_104 ( V_76 -> V_116 ) ) ;
return;
}
F_139 ( V_76 -> V_271 ) ;
V_76 -> V_271 = NULL ;
}
static int
F_140 ( struct V_75 * V_76 )
{
T_1 V_214 = V_76 -> V_165 ;
unsigned int V_262 ;
struct V_269 * V_269 ;
T_5 V_274 ;
int V_162 = 0 ;
V_262 = F_141 ( V_214 , V_275 ) ;
V_76 -> V_116 = F_136 ( sizeof( struct V_195 ) * V_262 , V_33 ) ;
if ( ! V_76 -> V_116 )
return - V_25 ;
V_76 -> V_200 = V_262 ;
F_142 ( V_76 -> V_116 , V_262 ) ;
V_274 = V_76 -> V_103 & V_212 ? 0 : V_276 ;
while ( V_214 ) {
T_1 V_277 = F_143 ( T_1 , V_214 , V_275 ) ;
V_269 = F_144 ( V_33 | V_274 ) ;
if ( ! V_269 )
goto V_3;
F_145 ( & V_76 -> V_116 [ V_162 ] , V_269 , V_277 , 0 ) ;
V_214 -= V_277 ;
V_162 ++ ;
}
return 0 ;
V_3:
while ( V_162 > 0 ) {
V_162 -- ;
F_130 ( F_104 ( & V_76 -> V_116 [ V_162 ] ) ) ;
}
F_131 ( V_76 -> V_116 ) ;
V_76 -> V_116 = NULL ;
return - V_25 ;
}
T_4
F_96 ( struct V_75 * V_76 )
{
int V_30 = 0 ;
if ( ! ( V_76 -> V_103 & V_203 ) &&
V_76 -> V_165 ) {
V_30 = F_140 ( V_76 ) ;
if ( V_30 < 0 )
return V_102 ;
}
F_122 ( & V_76 -> V_268 ) ;
F_61 ( V_76 ) ;
if ( V_76 -> V_134 != V_137 ) {
F_124 ( V_76 ) ;
return 0 ;
}
F_24 ( & V_76 -> V_86 ) ;
V_76 -> V_123 = V_278 ;
F_26 ( & V_76 -> V_86 ) ;
F_48 ( V_76 , false ) ;
V_30 = V_76 -> V_67 -> V_279 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 )
goto V_246;
F_57 ( V_30 ) ;
return ( ! V_30 ) ? 0 : V_102 ;
V_246:
F_27 ( L_118 , V_76 ) ;
V_76 -> V_123 = V_133 ;
F_119 ( V_76 , V_76 -> V_79 ) ;
return 0 ;
}
static void F_68 ( struct V_75 * V_76 )
{
int V_30 ;
V_30 = V_76 -> V_67 -> V_279 ( V_76 ) ;
if ( V_30 == - V_245 || V_30 == - V_25 ) {
F_27 ( L_118 ,
V_76 ) ;
F_119 ( V_76 , V_76 -> V_79 ) ;
}
}
int F_146 ( struct V_75 * V_76 , int V_280 )
{
int V_30 = 0 ;
if ( ! ( V_76 -> V_103 & V_281 ) ) {
if ( V_280 && ( V_76 -> V_103 & V_265 ) )
F_147 ( V_76 ) ;
V_30 = F_133 ( V_76 ) ;
} else {
if ( V_280 )
F_147 ( V_76 ) ;
if ( V_76 -> V_92 )
F_50 ( V_76 ) ;
V_30 = F_53 ( V_76 ) ;
}
return V_30 ;
}
int F_99 ( struct V_2 * V_32 , struct V_75 * V_75 ,
bool V_282 )
{
unsigned long V_56 ;
int V_30 = 0 ;
F_20 ( & V_75 -> V_283 ) ;
if ( V_282 == true ) {
F_23 ( & V_75 -> V_283 ) ;
V_75 -> V_103 |= V_284 ;
}
F_29 ( & V_32 -> V_38 , V_56 ) ;
if ( V_32 -> V_285 ) {
V_30 = - V_286 ;
goto V_3;
}
F_25 ( & V_75 -> V_174 , & V_32 -> V_36 ) ;
V_75 -> V_266 = 1 ;
V_3:
F_30 ( & V_32 -> V_38 , V_56 ) ;
return V_30 ;
}
static void F_148 ( struct V_58 * V_58 )
{
struct V_75 * V_75 = F_32 ( V_58 , struct V_75 , V_283 ) ;
struct V_2 * V_32 = V_75 -> V_32 ;
if ( F_41 ( & V_75 -> V_174 ) ) {
F_12 ( & V_32 -> V_38 ) ;
V_75 -> V_67 -> V_267 ( V_75 ) ;
return;
}
if ( V_32 -> V_285 && V_75 -> V_287 ) {
F_12 ( & V_32 -> V_38 ) ;
F_37 ( & V_75 -> V_176 ) ;
return;
}
F_40 ( & V_75 -> V_174 ) ;
F_12 ( & V_32 -> V_38 ) ;
V_75 -> V_67 -> V_267 ( V_75 ) ;
}
int F_102 ( struct V_2 * V_32 , struct V_75 * V_75 )
{
return F_149 ( & V_75 -> V_283 , F_148 ,
& V_32 -> V_38 ) ;
}
void F_150 ( struct V_2 * V_32 )
{
struct V_75 * V_75 ;
unsigned long V_56 ;
F_29 ( & V_32 -> V_38 , V_56 ) ;
if ( V_32 -> V_285 ) {
F_30 ( & V_32 -> V_38 , V_56 ) ;
return;
}
V_32 -> V_285 = 1 ;
F_64 ( & V_32 -> V_36 , & V_32 -> V_37 ) ;
F_151 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_75 -> V_287 = 1 ;
F_30 ( & V_32 -> V_38 , V_56 ) ;
}
void F_152 ( struct V_2 * V_32 )
{
struct V_75 * V_75 , * V_288 ;
unsigned long V_56 ;
F_65 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_40 ( & V_75 -> V_174 ) ;
F_27 ( L_119
L_120 , V_75 , V_75 -> V_123 ,
V_75 -> V_67 -> V_228 ( V_75 ) ) ;
F_116 ( & V_75 -> V_176 ) ;
F_27 ( L_121
L_122 , V_75 , V_75 -> V_123 ,
V_75 -> V_67 -> V_228 ( V_75 ) ) ;
V_75 -> V_67 -> V_267 ( V_75 ) ;
}
F_29 ( & V_32 -> V_38 , V_56 ) ;
F_57 ( ! F_41 ( & V_32 -> V_36 ) ) ;
F_30 ( & V_32 -> V_38 , V_56 ) ;
}
static int F_153 ( struct V_75 * V_76 , struct V_92 * V_96 )
{
unsigned long V_56 ;
int V_30 = 0 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_80 & V_93 ) {
V_76 -> V_80 &= ~ V_87 ;
F_27 ( L_123 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_48 ( V_76 , false ) ;
return - V_289 ;
}
V_76 -> V_80 |= V_290 ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( ( V_76 -> V_80 & V_81 ) &&
( V_76 -> V_80 & V_229 ) ) {
if ( ! F_115 ( V_76 , & V_56 ) )
V_30 ++ ;
}
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_27 ( L_124
L_120 , V_76 , V_30 ) ;
if ( ! V_30 ) {
F_27 ( L_125 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_116 ( & V_76 -> V_91 ) ;
F_27 ( L_126 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
}
return 0 ;
}
static void F_154 ( struct V_92 * V_96 )
{
struct V_75 * V_76 = NULL ;
unsigned long V_291 , V_292 ;
F_29 ( & V_96 -> V_98 , V_291 ) ;
while ( ! F_41 ( & V_96 -> V_293 ) ) {
V_76 = F_155 ( & V_96 -> V_293 ,
struct V_75 , V_99 ) ;
F_51 ( & V_76 -> V_99 ) ;
F_11 ( & V_76 -> V_86 ) ;
F_27 ( L_127
L_128 ,
V_76 -> V_92 -> V_205 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_80 |= V_87 ;
F_12 ( & V_76 -> V_86 ) ;
F_30 ( & V_96 -> V_98 , V_291 ) ;
if ( ! V_76 -> V_92 ) {
F_4 ( L_129 ,
V_76 -> V_67 -> V_89 ( V_76 ) ,
V_76 -> V_67 -> V_228 ( V_76 ) , V_76 -> V_123 ) ;
F_156 () ;
}
F_27 ( L_130
L_131 , V_76 -> V_92 -> V_205 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
if ( F_153 ( V_76 , V_76 -> V_92 ) < 0 ) {
F_29 ( & V_96 -> V_98 , V_291 ) ;
continue;
}
F_27 ( L_132
L_133 ,
V_76 -> V_92 -> V_205 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_29 ( & V_76 -> V_86 , V_292 ) ;
if ( ! ( V_76 -> V_80 & V_97 ) ) {
F_30 ( & V_76 -> V_86 , V_292 ) ;
goto V_294;
}
V_76 -> V_80 &= ~ V_97 ;
F_47 ( V_76 ) ;
F_30 ( & V_76 -> V_86 , V_292 ) ;
V_294:
F_101 ( V_76 ,
V_230 , 0 ) ;
F_29 ( & V_76 -> V_86 , V_292 ) ;
if ( V_76 -> V_80 & V_290 ) {
F_27 ( L_134
L_135 ,
V_96 -> V_205 ,
V_76 , V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 ,
V_292 ) ;
F_48 ( V_76 , false ) ;
F_37 ( & V_76 -> V_175 ) ;
F_29 ( & V_96 -> V_98 , V_291 ) ;
continue;
}
F_27 ( L_136 ,
V_96 -> V_205 , V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 , V_292 ) ;
F_29 ( & V_96 -> V_98 , V_291 ) ;
}
F_30 ( & V_96 -> V_98 , V_291 ) ;
}
static int F_157 ( void * V_295 )
{
struct V_92 * V_96 = V_295 ;
F_154 ( V_96 ) ;
F_37 ( & V_96 -> V_296 ) ;
return 0 ;
}
int F_158 ( struct V_92 * V_96 )
{
struct V_297 * V_298 ;
V_298 = F_159 ( F_157 , V_96 ,
L_137 , V_96 -> V_205 ) ;
if ( F_160 ( V_298 ) ) {
F_4 ( L_138 ) ;
return F_161 ( V_298 ) ;
}
F_116 ( & V_96 -> V_296 ) ;
return 0 ;
}
bool F_147 ( struct V_75 * V_76 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( ! ( V_76 -> V_103 & V_281 ) &&
! ( V_76 -> V_103 & V_265 ) ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return false ;
}
if ( ! ( V_76 -> V_103 & V_189 ) &&
! ( V_76 -> V_103 & V_265 ) ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return false ;
}
if ( V_76 -> V_80 & V_87 ) {
F_27 ( L_139
L_140
L_141 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_37 ( & V_76 -> V_91 ) ;
F_116 ( & V_76 -> V_175 ) ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
F_47 ( V_76 ) ;
F_27 ( L_142
L_143
L_144 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_87 ;
}
if ( ! ( V_76 -> V_80 & V_90 ) ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return false ;
}
V_76 -> V_80 |= V_93 ;
F_27 ( L_145
L_146 ,
V_76 , V_76 -> V_67 -> V_89 ( V_76 ) ,
V_76 -> V_67 -> V_228 ( V_76 ) , V_76 -> V_123 ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
F_116 ( & V_76 -> V_94 ) ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
V_76 -> V_80 &= ~ ( V_90 | V_93 ) ;
F_27 ( L_147
L_148 ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
return true ;
}
static int F_162 (
struct V_75 * V_76 ,
T_3 * V_299 ,
T_3 * V_300 )
{
* V_299 = V_76 -> V_301 ;
* V_300 = V_76 -> V_302 ;
return 0 ;
}
int
F_101 ( struct V_75 * V_76 ,
T_4 V_303 , int V_304 )
{
unsigned char * V_305 = V_76 -> V_112 ;
unsigned long V_56 ;
T_3 V_299 = 0 , V_300 = 0 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_103 & V_104 ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return 0 ;
}
V_76 -> V_103 |= V_104 ;
F_30 ( & V_76 -> V_86 , V_56 ) ;
if ( ! V_303 && V_304 )
goto V_306;
if ( ! V_304 )
V_76 -> V_103 |= V_307 ;
switch ( V_303 ) {
case V_308 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_311 ;
V_305 [ V_312 ] = 0 ;
V_305 [ V_313 ] = 0 ;
break;
case V_230 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x25 ;
break;
case V_231 :
case V_315 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x20 ;
break;
case V_234 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x24 ;
break;
case V_237 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_316 ;
V_305 [ V_312 ] = 0x29 ;
V_305 [ V_313 ] = 0x03 ;
break;
case V_317 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_316 ;
V_305 [ V_312 ] = 0x0c ;
V_305 [ V_313 ] = 0x0d ;
break;
case V_167 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x24 ;
break;
case V_232 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x26 ;
break;
case V_233 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x1a ;
break;
case V_318 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_316 ;
V_305 [ V_312 ] = 0x0c ;
V_305 [ V_313 ] = 0x0c ;
break;
case V_319 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_316 ;
V_305 [ V_312 ] = 0x47 ;
V_305 [ V_313 ] = 0x05 ;
break;
case V_320 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_316 ;
V_305 [ V_312 ] = 0x11 ;
V_305 [ V_313 ] = 0x13 ;
break;
case V_235 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_321 ;
V_305 [ V_312 ] = 0x27 ;
break;
case V_236 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_314 ;
V_305 [ V_312 ] = 0x21 ;
break;
case V_238 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_322 ;
F_163 ( V_76 , & V_299 , & V_300 ) ;
V_305 [ V_312 ] = V_299 ;
V_305 [ V_313 ] = V_300 ;
break;
case V_239 :
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_311 ;
F_162 ( V_76 , & V_299 , & V_300 ) ;
V_305 [ V_312 ] = V_299 ;
V_305 [ V_313 ] = V_300 ;
break;
case V_102 :
default:
V_305 [ 0 ] = 0x70 ;
V_305 [ V_309 ] = 10 ;
V_305 [ V_310 ] = V_311 ;
V_305 [ V_312 ] = 0x08 ;
break;
}
V_76 -> V_111 = V_323 ;
V_76 -> V_105 = V_106 ;
V_306:
return V_76 -> V_67 -> V_244 ( V_76 ) ;
}
int F_125 ( struct V_75 * V_76 , int V_324 )
{
if ( ! ( V_76 -> V_80 & V_121 ) )
return 0 ;
if ( ! V_324 || ( V_76 -> V_103 & V_325 ) )
return 1 ;
F_27 ( L_149 ,
V_76 -> V_166 [ 0 ] , V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_103 |= V_325 ;
V_76 -> V_67 -> V_244 ( V_76 ) ;
return 1 ;
}
void F_164 ( struct V_75 * V_76 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_103 & ( V_104 | V_325 ) ) {
F_30 ( & V_76 -> V_86 , V_56 ) ;
return;
}
F_30 ( & V_76 -> V_86 , V_56 ) ;
if ( V_76 -> V_134 == V_137 ) {
if ( V_76 -> V_67 -> V_326 ( V_76 ) != 0 ) {
V_76 -> V_80 |= V_121 ;
F_86 () ;
}
}
V_76 -> V_111 = V_327 ;
F_50 ( V_76 ) ;
F_27 ( L_150
L_151 , V_76 -> V_166 [ 0 ] ,
V_76 -> V_67 -> V_89 ( V_76 ) ) ;
V_76 -> V_67 -> V_244 ( V_76 ) ;
}
static void F_165 ( struct V_100 * V_101 )
{
struct V_75 * V_76 = F_32 ( V_101 , struct V_75 , V_101 ) ;
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_215 * V_328 = V_76 -> V_215 ;
int V_30 ;
switch ( V_328 -> V_329 ) {
case V_224 :
F_166 ( V_78 , V_328 , V_76 -> V_32 ) ;
break;
case V_330 :
case V_331 :
case V_332 :
V_328 -> V_216 = V_333 ;
break;
case V_334 :
V_30 = F_167 ( V_78 , V_328 , NULL , NULL ) ;
V_328 -> V_216 = ( ! V_30 ) ? V_335 :
V_336 ;
break;
case V_337 :
V_328 -> V_216 = V_336 ;
break;
case V_338 :
V_328 -> V_216 = V_336 ;
break;
default:
F_4 ( L_152 ,
V_328 -> V_329 ) ;
V_328 -> V_216 = V_336 ;
break;
}
V_76 -> V_123 = V_339 ;
V_76 -> V_67 -> V_218 ( V_76 ) ;
F_49 ( V_76 ) ;
}
int F_114 (
struct V_75 * V_76 )
{
F_59 ( & V_76 -> V_101 , F_165 ) ;
F_60 ( V_76 -> V_79 -> V_340 , & V_76 -> V_101 ) ;
return 0 ;
}
