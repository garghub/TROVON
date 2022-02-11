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
F_19 ( & V_32 -> V_37 ) ;
F_20 ( & V_32 -> V_38 ) ;
return V_32 ;
}
void F_21 (
struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_2 * V_32 ,
void * V_43 )
{
unsigned char V_44 [ V_45 ] ;
V_32 -> V_40 = V_40 ;
V_32 -> V_43 = V_43 ;
if ( V_42 ) {
if ( V_40 -> V_46 -> V_47 != NULL ) {
memset ( & V_44 [ 0 ] , 0 , V_45 ) ;
V_40 -> V_46 -> V_47 ( V_32 ,
& V_44 [ 0 ] , V_45 ) ;
V_32 -> V_48 = F_22 ( & V_44 [ 0 ] ) ;
}
F_23 ( & V_42 -> V_49 ) ;
F_24 ( & V_42 -> V_50 ) ;
V_42 -> V_51 = V_32 ;
F_25 ( & V_32 -> V_35 ,
& V_42 -> V_52 ) ;
F_26 ( & V_42 -> V_50 ) ;
}
F_25 ( & V_32 -> V_34 , & V_40 -> V_53 ) ;
F_27 ( L_26 ,
V_40 -> V_46 -> V_54 () , V_32 -> V_43 ) ;
}
void F_28 (
struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_2 * V_32 ,
void * V_43 )
{
unsigned long V_55 ;
F_29 ( & V_40 -> V_56 , V_55 ) ;
F_21 ( V_40 , V_42 , V_32 , V_43 ) ;
F_30 ( & V_40 -> V_56 , V_55 ) ;
}
static void F_31 ( struct V_57 * V_57 )
{
struct V_2 * V_32 = F_32 ( V_57 ,
struct V_2 , V_38 ) ;
struct V_39 * V_40 = V_32 -> V_40 ;
V_40 -> V_46 -> V_58 ( V_32 ) ;
}
void F_33 ( struct V_2 * V_32 )
{
F_23 ( & V_32 -> V_38 ) ;
}
void F_34 ( struct V_2 * V_32 )
{
struct V_39 * V_59 = V_32 -> V_40 ;
if ( V_59 -> V_46 -> V_60 != NULL ) {
V_59 -> V_46 -> V_60 ( V_32 ) ;
return;
}
F_35 ( & V_32 -> V_38 , F_31 ) ;
}
static void F_36 ( struct V_57 * V_57 )
{
struct V_41 * V_61 = F_32 ( V_57 ,
struct V_41 , V_49 ) ;
F_37 ( & V_61 -> V_62 ) ;
}
void F_38 ( struct V_41 * V_61 )
{
F_35 ( & V_61 -> V_49 , F_36 ) ;
}
void F_39 ( struct V_2 * V_32 )
{
struct V_41 * V_42 ;
unsigned long V_55 ;
V_42 = V_32 -> V_41 ;
if ( V_42 ) {
F_29 ( & V_42 -> V_50 , V_55 ) ;
if ( V_42 -> V_63 == 0 )
F_40 ( & V_32 -> V_35 ) ;
if ( F_41 ( & V_42 -> V_52 ) )
V_42 -> V_51 = NULL ;
else {
V_42 -> V_51 = F_32 (
V_42 -> V_52 . V_64 ,
struct V_2 , V_35 ) ;
}
F_30 ( & V_42 -> V_50 , V_55 ) ;
}
}
void F_42 ( struct V_2 * V_32 )
{
F_43 ( V_1 , V_32 ) ;
}
void F_44 ( struct V_2 * V_32 )
{
struct V_39 * V_40 = V_32 -> V_40 ;
struct V_65 * V_66 ;
struct V_41 * V_42 ;
unsigned long V_55 ;
bool V_67 = true ;
if ( ! V_40 ) {
F_42 ( V_32 ) ;
return;
}
V_66 = V_40 -> V_46 ;
F_29 ( & V_40 -> V_56 , V_55 ) ;
F_40 ( & V_32 -> V_34 ) ;
V_32 -> V_40 = NULL ;
V_32 -> V_43 = NULL ;
F_30 ( & V_40 -> V_56 , V_55 ) ;
V_42 = V_32 -> V_41 ;
F_29 ( & V_40 -> V_68 , V_55 ) ;
if ( V_42 && V_42 -> V_69 ) {
if ( ! V_66 -> V_70 ( V_40 ) ) {
F_40 ( & V_42 -> V_71 ) ;
V_40 -> V_72 -- ;
F_30 ( & V_40 -> V_68 , V_55 ) ;
F_45 ( V_42 ) ;
F_46 ( V_42 , V_40 ) ;
V_66 -> V_73 ( V_40 , V_42 ) ;
V_67 = false ;
F_29 ( & V_40 -> V_68 , V_55 ) ;
}
}
F_30 ( & V_40 -> V_68 , V_55 ) ;
F_27 ( L_27 ,
V_40 -> V_46 -> V_54 () ) ;
if ( V_42 && V_67 == true )
F_38 ( V_42 ) ;
F_42 ( V_32 ) ;
}
static void F_47 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
unsigned long V_55 ;
if ( ! V_77 )
return;
if ( V_75 -> V_79 & V_80 )
return;
F_29 ( & V_77 -> V_81 , V_55 ) ;
if ( V_75 -> V_82 ) {
F_40 ( & V_75 -> V_83 ) ;
V_75 -> V_82 = false ;
}
F_30 ( & V_77 -> V_81 , V_55 ) ;
}
static int F_48 ( struct V_74 * V_75 , bool V_84 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_28 ,
V_87 , __LINE__ , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_89 ;
if ( V_84 )
F_47 ( V_75 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_90 ) ;
return 1 ;
}
if ( V_84 ) {
F_47 ( V_75 ) ;
V_75 -> V_91 = NULL ;
}
if ( V_75 -> V_79 & V_92 ) {
F_27 ( L_29 ,
V_87 , __LINE__ ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_93 ) ;
return 1 ;
}
V_75 -> V_79 &= ~ V_89 ;
if ( V_84 ) {
if ( V_75 -> V_66 -> V_94 != NULL ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return V_75 -> V_66 -> V_94 ( V_75 ) ;
}
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
return 0 ;
}
static int F_49 ( struct V_74 * V_75 )
{
return F_48 ( V_75 , true ) ;
}
static void F_50 ( struct V_74 * V_75 )
{
struct V_91 * V_95 = V_75 -> V_91 ;
unsigned long V_55 ;
if ( ! V_95 )
return;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_79 & V_96 ) {
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_29 ( & V_95 -> V_97 , V_55 ) ;
if ( ! F_41 ( & V_75 -> V_98 ) )
F_51 ( & V_75 -> V_98 ) ;
F_30 ( & V_95 -> V_97 , V_55 ) ;
}
void F_52 ( struct V_74 * V_75 , int remove )
{
if ( F_49 ( V_75 ) )
return;
if ( remove )
F_53 ( V_75 ) ;
}
static void F_54 ( struct V_99 * V_100 )
{
struct V_74 * V_75 = F_32 ( V_100 , struct V_74 , V_100 ) ;
F_55 ( V_75 ,
V_101 ) ;
}
static unsigned char * F_56 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
F_57 ( ! V_75 -> V_91 ) ;
if ( ! V_77 )
return NULL ;
if ( V_75 -> V_102 & V_103 )
return NULL ;
V_75 -> V_104 = V_105 ;
F_27 ( L_30 ,
V_77 -> V_106 -> V_107 , V_77 -> V_108 -> V_109 , V_75 -> V_110 ) ;
return V_75 -> V_111 ;
}
void F_58 ( struct V_74 * V_75 , T_3 V_110 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
int V_112 = V_110 == V_113 ;
unsigned long V_55 ;
V_75 -> V_110 = V_110 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_79 &= ~ V_80 ;
if ( V_77 && V_77 -> V_108 -> V_114 ) {
V_77 -> V_108 -> V_114 ( V_75 ,
V_75 -> V_115 ,
F_56 ( V_75 ) ) ;
if ( V_75 -> V_102 & V_116 )
V_112 = 1 ;
}
if ( V_75 -> V_79 & V_117 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_118 ) ;
return;
}
if ( ! V_112 )
V_75 -> V_79 |= V_119 ;
if ( V_75 -> V_79 & V_120 &&
V_75 -> V_79 & V_92 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_93 ) ;
return;
} else if ( V_75 -> V_79 & V_119 ) {
F_59 ( & V_75 -> V_100 , F_54 ) ;
} else {
F_59 ( & V_75 -> V_100 , V_121 ) ;
}
V_75 -> V_122 = V_123 ;
V_75 -> V_79 |= ( V_124 | V_89 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_60 ( V_22 , & V_75 -> V_100 ) ;
}
static void F_61 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
unsigned long V_55 ;
F_29 ( & V_77 -> V_81 , V_55 ) ;
if ( ! V_75 -> V_82 ) {
F_25 ( & V_75 -> V_83 , & V_77 -> V_83 ) ;
V_75 -> V_82 = true ;
}
F_30 ( & V_77 -> V_81 , V_55 ) ;
}
void F_62 ( struct V_99 * V_100 )
{
struct V_76 * V_77 = F_32 ( V_100 , struct V_76 ,
V_125 ) ;
F_63 ( V_126 ) ;
struct V_74 * V_75 , * V_127 ;
F_24 ( & V_77 -> V_128 ) ;
F_64 ( & V_77 -> V_126 , & V_126 ) ;
F_26 ( & V_77 -> V_128 ) ;
F_65 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_40 ( & V_75 -> V_129 ) ;
F_66 ( & V_77 -> V_130 ) ;
F_67 () ;
F_27 ( L_31
L_32 , V_75 -> V_66 -> V_54 () , V_75 ,
( V_75 -> V_122 == V_131 ) ? L_33 :
( V_75 -> V_122 == V_132 ) ? L_34
: L_35 ) ;
if ( V_75 -> V_122 == V_132 )
F_68 ( V_75 ) ;
else if ( V_75 -> V_122 == V_131 )
F_69 ( V_75 ) ;
}
}
unsigned char * F_70 ( struct V_74 * V_75 )
{
switch ( V_75 -> V_133 ) {
case V_134 :
return L_36 ;
case V_135 :
return L_37 ;
case V_136 :
return L_38 ;
case V_137 :
return L_39 ;
default:
break;
}
return L_35 ;
}
void F_71 (
struct V_76 * V_77 ,
char * V_138 ,
int * V_139 )
{
* V_139 += sprintf ( V_138 + * V_139 , L_40 ) ;
if ( V_77 -> V_140 )
* V_139 += sprintf ( V_138 + * V_139 , L_41 ) ;
else
* V_139 += sprintf ( V_138 + * V_139 , L_42 ) ;
* V_139 += sprintf ( V_138 + * V_139 , L_43 , V_77 -> V_141 ) ;
* V_139 += sprintf ( V_138 + * V_139 , L_44 ,
V_77 -> V_142 . V_143 ,
V_77 -> V_142 . V_144 ) ;
* V_139 += sprintf ( V_138 + * V_139 , L_45 ) ;
}
void F_72 (
struct V_145 * V_146 ,
unsigned char * V_147 ,
int V_148 )
{
unsigned char V_44 [ V_149 ] ;
int V_150 ;
memset ( V_44 , 0 , V_149 ) ;
V_150 = sprintf ( V_44 , L_46 ) ;
switch ( V_146 -> V_151 ) {
case 0x00 :
sprintf ( V_44 + V_150 , L_47 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_150 , L_48 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_150 , L_49 ) ;
break;
case 0x30 :
sprintf ( V_44 + V_150 , L_50 ) ;
break;
case 0x40 :
sprintf ( V_44 + V_150 , L_51
L_52 ) ;
break;
case 0x50 :
sprintf ( V_44 + V_150 , L_53 ) ;
break;
case 0x60 :
sprintf ( V_44 + V_150 , L_54 ) ;
break;
case 0x70 :
sprintf ( V_44 + V_150 , L_55
L_52 ) ;
break;
case 0x80 :
sprintf ( V_44 + V_150 , L_56 ) ;
break;
default:
sprintf ( V_44 + V_150 , L_57 ,
V_146 -> V_151 ) ;
break;
}
if ( V_147 )
strncpy ( V_147 , V_44 , V_148 ) ;
else
F_27 ( L_58 , V_44 ) ;
}
void
F_73 ( struct V_145 * V_146 , unsigned char * V_152 )
{
if ( V_152 [ 1 ] & 0x80 ) {
V_146 -> V_151 = ( V_152 [ 0 ] & 0xf0 ) ;
V_146 -> V_153 = 1 ;
F_72 ( V_146 , NULL , 0 ) ;
}
}
int F_74 (
struct V_145 * V_146 ,
unsigned char * V_147 ,
int V_148 )
{
unsigned char V_44 [ V_149 ] ;
int V_30 = 0 ;
int V_150 ;
memset ( V_44 , 0 , V_149 ) ;
V_150 = sprintf ( V_44 , L_59 ) ;
switch ( V_146 -> V_154 ) {
case 0x00 :
sprintf ( V_44 + V_150 , L_60 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_150 , L_61 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_150 , L_62 ) ;
break;
default:
sprintf ( V_44 + V_150 , L_57 , V_146 -> V_154 ) ;
V_30 = - V_155 ;
break;
}
if ( V_147 )
strncpy ( V_147 , V_44 , V_148 ) ;
else
F_27 ( L_58 , V_44 ) ;
return V_30 ;
}
int F_75 ( struct V_145 * V_146 , unsigned char * V_152 )
{
V_146 -> V_154 = ( V_152 [ 1 ] & 0x30 ) ;
return F_74 ( V_146 , NULL , 0 ) ;
}
int F_76 (
struct V_145 * V_146 ,
unsigned char * V_147 ,
int V_148 )
{
unsigned char V_44 [ V_149 ] ;
int V_30 = 0 ;
int V_150 ;
memset ( V_44 , 0 , V_149 ) ;
V_150 = sprintf ( V_44 , L_63 ) ;
switch ( V_146 -> V_156 ) {
case 0x00 :
sprintf ( V_44 + V_150 , L_64 ) ;
break;
case 0x01 :
sprintf ( V_44 + V_150 , L_65 ) ;
break;
case 0x02 :
sprintf ( V_44 + V_150 , L_66 ) ;
break;
case 0x03 :
sprintf ( V_44 + V_150 , L_67 ) ;
break;
case 0x04 :
sprintf ( V_44 + V_150 , L_68 ) ;
break;
case 0x08 :
sprintf ( V_44 + V_150 , L_69 ) ;
break;
default:
sprintf ( V_44 + V_150 , L_70 ,
V_146 -> V_156 ) ;
V_30 = - V_155 ;
break;
}
if ( V_147 ) {
if ( V_148 < strlen ( V_44 ) + 1 )
return - V_155 ;
strncpy ( V_147 , V_44 , V_148 ) ;
} else {
F_27 ( L_58 , V_44 ) ;
}
return V_30 ;
}
int F_77 ( struct V_145 * V_146 , unsigned char * V_152 )
{
V_146 -> V_156 = ( V_152 [ 1 ] & 0x0f ) ;
return F_76 ( V_146 , NULL , 0 ) ;
}
int F_78 (
struct V_145 * V_146 ,
unsigned char * V_147 ,
int V_148 )
{
unsigned char V_44 [ V_149 ] ;
int V_30 = 0 ;
memset ( V_44 , 0 , V_149 ) ;
switch ( V_146 -> V_157 ) {
case 0x01 :
snprintf ( V_44 , sizeof( V_44 ) ,
L_71 ,
& V_146 -> V_158 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_44 , sizeof( V_44 ) ,
L_72 ,
& V_146 -> V_158 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_44 , sizeof( V_44 ) ,
L_73 ,
& V_146 -> V_158 [ 0 ] ) ;
break;
default:
sprintf ( V_44 , L_74
L_75 , V_146 -> V_157 ) ;
V_30 = - V_155 ;
break;
}
if ( V_147 )
strncpy ( V_147 , V_44 , V_148 ) ;
else
F_27 ( L_58 , V_44 ) ;
return V_30 ;
}
int
F_79 ( struct V_145 * V_146 , unsigned char * V_152 )
{
static const char V_159 [] = L_76 ;
int V_160 = 0 , V_161 = 4 ;
V_146 -> V_157 = ( V_152 [ 0 ] & 0x0f ) ;
switch ( V_146 -> V_157 ) {
case 0x01 :
V_146 -> V_158 [ V_160 ++ ] =
V_159 [ V_146 -> V_156 ] ;
while ( V_161 < ( 4 + V_152 [ 3 ] ) ) {
V_146 -> V_158 [ V_160 ++ ] =
V_159 [ ( V_152 [ V_161 ] & 0xf0 ) >> 4 ] ;
V_146 -> V_158 [ V_160 ++ ] =
V_159 [ V_152 [ V_161 ] & 0x0f ] ;
V_161 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_161 < ( 4 + V_152 [ 3 ] ) )
V_146 -> V_158 [ V_160 ++ ] = V_152 [ V_161 ++ ] ;
break;
default:
break;
}
return F_78 ( V_146 , NULL , 0 ) ;
}
T_4
F_80 ( struct V_74 * V_75 , unsigned int V_162 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_75 -> V_163 ) {
V_75 -> V_164 = V_162 ;
} else if ( V_162 != V_75 -> V_164 ) {
F_81 ( L_77
L_78
L_79 , V_75 -> V_66 -> V_54 () ,
V_75 -> V_164 , V_162 , V_75 -> V_165 [ 0 ] ) ;
if ( V_75 -> V_133 == V_136 ) {
F_4 ( L_80
L_81 ) ;
return V_166 ;
}
if ( V_77 -> V_142 . V_143 != 512 ) {
F_4 ( L_82
L_83
L_84 , V_77 -> V_108 -> V_109 ) ;
return V_166 ;
}
if ( V_162 > V_75 -> V_164 ) {
V_75 -> V_102 |= V_167 ;
V_75 -> V_168 = ( V_162 - V_75 -> V_164 ) ;
} else {
V_75 -> V_102 |= V_169 ;
V_75 -> V_168 = ( V_75 -> V_164 - V_162 ) ;
V_75 -> V_164 = V_162 ;
}
}
return 0 ;
}
void F_82 (
struct V_74 * V_75 ,
struct V_65 * V_170 ,
struct V_2 * V_32 ,
T_1 V_164 ,
int V_133 ,
int V_171 ,
unsigned char * V_111 )
{
F_18 ( & V_75 -> V_98 ) ;
F_18 ( & V_75 -> V_172 ) ;
F_18 ( & V_75 -> V_129 ) ;
F_18 ( & V_75 -> V_173 ) ;
F_18 ( & V_75 -> V_83 ) ;
F_83 ( & V_75 -> V_174 ) ;
F_83 ( & V_75 -> V_90 ) ;
F_83 ( & V_75 -> V_93 ) ;
F_83 ( & V_75 -> V_175 ) ;
F_83 ( & V_75 -> V_118 ) ;
F_19 ( & V_75 -> V_85 ) ;
V_75 -> V_79 = V_96 ;
V_75 -> V_66 = V_170 ;
V_75 -> V_32 = V_32 ;
V_75 -> V_164 = V_164 ;
V_75 -> V_133 = V_133 ;
V_75 -> V_176 = V_171 ;
V_75 -> V_111 = V_111 ;
V_75 -> V_82 = false ;
}
static T_4
F_84 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_77 -> V_108 -> V_177 == V_178 )
return 0 ;
if ( V_75 -> V_176 == V_179 ) {
F_27 ( L_85
L_86 ) ;
return V_166 ;
}
V_75 -> V_180 = F_85 ( & V_77 -> V_181 ) ;
F_86 () ;
F_27 ( L_87 ,
V_75 -> V_180 , V_75 -> V_176 ,
V_77 -> V_108 -> V_109 ) ;
return 0 ;
}
T_4
F_87 ( struct V_74 * V_75 , unsigned char * V_182 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
unsigned long V_55 ;
T_4 V_30 ;
if ( F_88 ( V_182 ) > V_183 ) {
F_4 ( L_88
L_89 ,
F_88 ( V_182 ) , V_183 ) ;
return V_166 ;
}
if ( F_88 ( V_182 ) > sizeof( V_75 -> V_184 ) ) {
V_75 -> V_165 = F_89 ( F_88 ( V_182 ) ,
V_33 ) ;
if ( ! V_75 -> V_165 ) {
F_4 ( L_90
L_91 ,
F_88 ( V_182 ) ,
( unsigned long ) sizeof( V_75 -> V_184 ) ) ;
return V_185 ;
}
} else
V_75 -> V_165 = & V_75 -> V_184 [ 0 ] ;
memcpy ( V_75 -> V_165 , V_182 , F_88 ( V_182 ) ) ;
V_30 = F_90 ( V_75 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_91 ( V_75 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_92 ( V_75 ) ;
if ( V_30 ) {
V_75 -> V_110 = V_186 ;
return V_30 ;
}
V_30 = V_77 -> V_108 -> V_187 ( V_75 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_84 ( V_75 ) ;
if ( V_30 )
return V_30 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_102 |= V_188 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_11 ( & V_75 -> V_91 -> V_189 ) ;
if ( V_75 -> V_91 -> V_190 )
V_75 -> V_91 -> V_190 -> V_191 . V_192 ++ ;
F_12 ( & V_75 -> V_91 -> V_189 ) ;
return 0 ;
}
int F_93 (
struct V_74 * V_75 )
{
T_4 V_30 ;
if ( ! V_75 -> V_91 ) {
F_94 () ;
F_4 ( L_92 ) ;
return - V_155 ;
}
if ( F_95 () ) {
F_94 () ;
F_4 ( L_93
L_94 ) ;
return - V_155 ;
}
V_75 -> V_122 = V_193 ;
V_75 -> V_79 |= V_89 ;
V_30 = F_96 ( V_75 ) ;
if ( V_30 )
F_55 ( V_75 , V_30 ) ;
return 0 ;
}
static T_4
F_97 ( struct V_74 * V_75 , struct V_194 * V_195 ,
T_1 V_196 , struct V_194 * V_197 , T_1 V_198 )
{
if ( ! V_195 || ! V_196 )
return 0 ;
if ( V_75 -> V_102 & V_167 ) {
F_81 ( L_95
L_96 ) ;
return V_166 ;
}
V_75 -> V_115 = V_195 ;
V_75 -> V_199 = V_196 ;
if ( V_197 && V_198 ) {
V_75 -> V_200 = V_197 ;
V_75 -> V_201 = V_198 ;
}
V_75 -> V_102 |= V_202 ;
return 0 ;
}
int F_98 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_182 , unsigned char * V_203 , T_1 V_204 ,
T_1 V_164 , int V_171 , int V_205 , int V_55 ,
struct V_194 * V_195 , T_1 V_196 ,
struct V_194 * V_197 , T_1 V_198 )
{
struct V_39 * V_40 ;
T_4 V_206 ;
int V_30 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_10 ( V_74 -> V_66 || V_74 -> V_32 ) ;
F_10 ( F_95 () ) ;
F_82 ( V_74 , V_40 -> V_46 , V_32 ,
V_164 , V_205 , V_171 , V_203 ) ;
if ( V_55 & V_207 )
V_74 -> V_163 = 1 ;
V_30 = F_99 ( V_32 , V_74 , ( V_55 & V_208 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_55 & V_209 )
V_74 -> V_102 |= V_210 ;
V_206 = F_100 ( V_74 , V_204 ) ;
if ( V_206 ) {
F_101 ( V_74 , V_206 , 0 ) ;
F_102 ( V_32 , V_74 ) ;
return 0 ;
}
V_206 = F_87 ( V_74 , V_182 ) ;
if ( V_206 != 0 ) {
F_55 ( V_74 , V_206 ) ;
return 0 ;
}
if ( V_196 != 0 ) {
F_10 ( ! V_195 ) ;
if ( ! ( V_74 -> V_102 & V_211 ) &&
V_74 -> V_133 == V_135 ) {
unsigned char * V_44 = NULL ;
if ( V_195 )
V_44 = F_103 ( F_104 ( V_195 ) ) + V_195 -> V_212 ;
if ( V_44 ) {
memset ( V_44 , 0 , V_195 -> V_213 ) ;
F_105 ( F_104 ( V_195 ) ) ;
}
}
V_206 = F_97 ( V_74 , V_195 , V_196 ,
V_197 , V_198 ) ;
if ( V_206 != 0 ) {
F_55 ( V_74 , V_206 ) ;
return 0 ;
}
}
F_106 ( V_74 ) ;
F_93 ( V_74 ) ;
return 0 ;
}
int F_107 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_182 , unsigned char * V_203 , T_1 V_204 ,
T_1 V_164 , int V_171 , int V_205 , int V_55 )
{
return F_98 ( V_74 , V_32 , V_182 , V_203 ,
V_204 , V_164 , V_171 , V_205 ,
V_55 , NULL , 0 , NULL , 0 ) ;
}
static void F_108 ( struct V_99 * V_100 )
{
struct V_74 * V_74 = F_32 ( V_100 , struct V_74 , V_100 ) ;
V_74 -> V_214 -> V_215 = V_216 ;
V_74 -> V_66 -> V_217 ( V_74 ) ;
F_49 ( V_74 ) ;
}
int F_109 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_203 , T_1 V_204 ,
void * V_218 , unsigned char V_219 ,
T_5 V_220 , unsigned int V_221 , int V_55 )
{
struct V_39 * V_40 ;
int V_30 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_82 ( V_74 , V_40 -> V_46 , V_32 ,
0 , V_134 , V_222 , V_203 ) ;
V_30 = F_110 ( V_74 , V_218 , V_219 , V_220 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_219 == V_223 )
V_74 -> V_214 -> V_224 = V_221 ;
V_30 = F_99 ( V_32 , V_74 , ( V_55 & V_208 ) ) ;
if ( V_30 ) {
F_111 ( V_74 -> V_214 ) ;
return V_30 ;
}
V_30 = F_112 ( V_74 , V_204 ) ;
if ( V_30 ) {
F_59 ( & V_74 -> V_100 , F_108 ) ;
F_113 ( & V_74 -> V_100 ) ;
return 0 ;
}
F_114 ( V_74 ) ;
return 0 ;
}
bool F_115 ( struct V_74 * V_75 , unsigned long * V_55 )
{
bool V_225 = false ;
if ( V_75 -> V_79 & V_80 ) {
V_75 -> V_79 |= V_117 ;
F_30 ( & V_75 -> V_85 , * V_55 ) ;
F_27 ( L_97 , V_75 ) ;
F_116 ( & V_75 -> V_118 ) ;
F_27 ( L_98 , V_75 ) ;
F_29 ( & V_75 -> V_85 , * V_55 ) ;
V_75 -> V_79 &= ~ V_117 ;
V_75 -> V_79 &= ~ V_80 ;
V_225 = true ;
}
return V_225 ;
}
void F_55 ( struct V_74 * V_75 ,
T_4 V_226 )
{
int V_30 = 0 ;
F_27 ( L_99
L_100 , V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_165 [ 0 ] ) ;
F_27 ( L_101 ,
V_75 -> V_66 -> V_227 ( V_75 ) ,
V_75 -> V_122 , V_226 ) ;
F_27 ( L_102 ,
( V_75 -> V_79 & V_89 ) != 0 ,
( V_75 -> V_79 & V_92 ) != 0 ,
( V_75 -> V_79 & V_228 ) != 0 ) ;
F_117 ( V_75 ) ;
switch ( V_226 ) {
case V_229 :
case V_230 :
case V_166 :
case V_231 :
case V_232 :
case V_101 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
break;
case V_185 :
V_226 = V_101 ;
break;
case V_239 :
V_75 -> V_110 = V_186 ;
if ( V_75 -> V_32 &&
V_75 -> V_78 -> V_142 . V_240 == 2 )
F_118 ( V_75 -> V_32 -> V_41 ,
V_75 -> V_241 , 0x2C ,
V_242 ) ;
V_30 = V_75 -> V_66 -> V_243 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
goto V_246;
default:
F_4 ( L_103 ,
V_75 -> V_165 [ 0 ] , V_226 ) ;
V_226 = V_230 ;
break;
}
V_30 = F_101 ( V_75 , V_226 , 0 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
V_246:
F_50 ( V_75 ) ;
if ( ! F_49 ( V_75 ) )
;
return;
V_245:
V_75 -> V_122 = V_131 ;
F_119 ( V_75 , V_75 -> V_78 ) ;
}
static void F_120 ( struct V_74 * V_75 )
{
T_4 V_30 ;
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 |= ( V_80 | V_228 ) ;
F_26 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_247 ) {
V_30 = V_75 -> V_247 ( V_75 ) ;
if ( V_30 ) {
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 &= ~ ( V_80 | V_228 ) ;
F_26 ( & V_75 -> V_85 ) ;
F_55 ( V_75 , V_30 ) ;
}
}
}
static bool F_121 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_77 -> V_108 -> V_177 == V_178 )
return false ;
switch ( V_75 -> V_176 ) {
case V_248 :
F_27 ( L_104
L_105 ,
V_75 -> V_165 [ 0 ] , V_75 -> V_180 ) ;
return false ;
case V_249 :
F_122 ( & V_77 -> V_250 ) ;
F_86 () ;
F_27 ( L_106
L_107 ,
V_75 -> V_165 [ 0 ] , V_75 -> V_180 ) ;
if ( ! F_123 ( & V_77 -> V_251 ) )
return false ;
break;
default:
F_122 ( & V_77 -> V_251 ) ;
F_86 () ;
break;
}
if ( F_123 ( & V_77 -> V_250 ) == 0 )
return false ;
F_11 ( & V_77 -> V_252 ) ;
F_25 ( & V_75 -> V_172 , & V_77 -> V_253 ) ;
F_12 ( & V_77 -> V_252 ) ;
F_27 ( L_108
L_109 ,
V_75 -> V_165 [ 0 ] , V_75 -> V_176 ,
V_75 -> V_180 ) ;
return true ;
}
void F_124 ( struct V_74 * V_75 )
{
if ( F_125 ( V_75 , 1 ) ) {
F_37 ( & V_75 -> V_90 ) ;
return;
}
F_24 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_28 ,
V_87 , __LINE__ , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_89 ;
F_26 ( & V_75 -> V_85 ) ;
F_37 ( & V_75 -> V_90 ) ;
return;
}
if ( V_75 -> V_79 & V_92 ) {
F_27 ( L_29 ,
V_87 , __LINE__ ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_26 ( & V_75 -> V_85 ) ;
F_37 ( & V_75 -> V_93 ) ;
return;
}
V_75 -> V_122 = V_254 ;
V_75 -> V_79 |= V_89 ;
F_26 ( & V_75 -> V_85 ) ;
if ( ! F_121 ( V_75 ) )
F_120 ( V_75 ) ;
}
static void F_126 ( struct V_76 * V_77 )
{
for (; ; ) {
struct V_74 * V_75 ;
F_11 ( & V_77 -> V_252 ) ;
if ( F_41 ( & V_77 -> V_253 ) ) {
F_12 ( & V_77 -> V_252 ) ;
break;
}
V_75 = F_127 ( V_77 -> V_253 . V_255 ,
struct V_74 , V_172 ) ;
F_40 ( & V_75 -> V_172 ) ;
F_12 ( & V_77 -> V_252 ) ;
F_120 ( V_75 ) ;
if ( V_75 -> V_176 == V_249 )
break;
}
}
static void F_117 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_77 -> V_108 -> V_177 == V_178 )
return;
if ( V_75 -> V_176 == V_222 ) {
F_66 ( & V_77 -> V_251 ) ;
F_67 () ;
V_77 -> V_256 ++ ;
F_27 ( L_110
L_111 , V_77 -> V_256 ,
V_75 -> V_180 ) ;
} else if ( V_75 -> V_176 == V_248 ) {
V_77 -> V_256 ++ ;
F_27 ( L_112
L_113 , V_77 -> V_256 ,
V_75 -> V_180 ) ;
} else if ( V_75 -> V_176 == V_249 ) {
F_66 ( & V_77 -> V_250 ) ;
F_67 () ;
V_77 -> V_256 ++ ;
F_27 ( L_114
L_115 , V_77 -> V_256 , V_75 -> V_180 ) ;
}
F_126 ( V_77 ) ;
}
static void F_69 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
F_117 ( V_75 ) ;
if ( V_75 -> V_102 & V_116 ) {
V_30 = V_75 -> V_66 -> V_243 ( V_75 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_75 -> V_133 ) {
case V_135 :
V_30 = V_75 -> V_66 -> V_257 ( V_75 ) ;
break;
case V_136 :
if ( V_75 -> V_200 ) {
V_30 = V_75 -> V_66 -> V_257 ( V_75 ) ;
if ( V_30 < 0 )
break;
}
case V_134 :
V_30 = V_75 -> V_66 -> V_243 ( V_75 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_119 ( V_75 , V_75 -> V_78 ) ;
return;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
}
static void F_119 (
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_24 ( & V_77 -> V_128 ) ;
F_25 ( & V_75 -> V_129 , & V_75 -> V_78 -> V_126 ) ;
F_122 ( & V_77 -> V_130 ) ;
F_86 () ;
F_26 ( & V_75 -> V_78 -> V_128 ) ;
F_113 ( & V_75 -> V_78 -> V_125 ) ;
}
static void V_121 ( struct V_99 * V_100 )
{
struct V_74 * V_75 = F_32 ( V_100 , struct V_74 , V_100 ) ;
int V_30 ;
F_117 ( V_75 ) ;
if ( F_123 ( & V_75 -> V_78 -> V_130 ) != 0 )
F_113 ( & V_75 -> V_78 -> V_125 ) ;
if ( V_75 -> V_102 & V_116 ) {
F_57 ( ! V_75 -> V_110 ) ;
V_30 = F_101 (
V_75 , 0 , 1 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
}
if ( V_75 -> V_258 )
V_75 -> V_258 ( V_75 ) ;
switch ( V_75 -> V_133 ) {
case V_135 :
F_11 ( & V_75 -> V_91 -> V_189 ) ;
if ( V_75 -> V_91 -> V_190 ) {
V_75 -> V_91 -> V_190 -> V_191 . V_259 +=
V_75 -> V_164 ;
}
F_12 ( & V_75 -> V_91 -> V_189 ) ;
V_30 = V_75 -> V_66 -> V_257 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
break;
case V_136 :
F_11 ( & V_75 -> V_91 -> V_189 ) ;
if ( V_75 -> V_91 -> V_190 ) {
V_75 -> V_91 -> V_190 -> V_191 . V_260 +=
V_75 -> V_164 ;
}
F_12 ( & V_75 -> V_91 -> V_189 ) ;
if ( V_75 -> V_200 ) {
F_11 ( & V_75 -> V_91 -> V_189 ) ;
if ( V_75 -> V_91 -> V_190 ) {
V_75 -> V_91 -> V_190 -> V_191 . V_259 +=
V_75 -> V_164 ;
}
F_12 ( & V_75 -> V_91 -> V_189 ) ;
V_30 = V_75 -> V_66 -> V_257 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
break;
}
case V_134 :
V_30 = V_75 -> V_66 -> V_243 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
break;
default:
break;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
V_245:
F_27 ( L_116
L_117 , V_75 , V_75 -> V_133 ) ;
V_75 -> V_122 = V_131 ;
F_119 ( V_75 , V_75 -> V_78 ) ;
}
static inline void F_128 ( struct V_194 * V_195 , int V_261 )
{
struct V_194 * V_262 ;
int V_263 ;
F_129 (sgl, sg, nents, count)
F_130 ( F_104 ( V_262 ) ) ;
F_131 ( V_195 ) ;
}
static inline void F_132 ( struct V_74 * V_75 )
{
if ( V_75 -> V_102 & V_202 )
return;
F_128 ( V_75 -> V_115 , V_75 -> V_199 ) ;
V_75 -> V_115 = NULL ;
V_75 -> V_199 = 0 ;
F_128 ( V_75 -> V_200 , V_75 -> V_201 ) ;
V_75 -> V_200 = NULL ;
V_75 -> V_201 = 0 ;
}
static void F_133 ( struct V_74 * V_75 )
{
F_10 ( ! V_75 -> V_66 ) ;
if ( V_75 -> V_102 & V_264 )
F_111 ( V_75 -> V_214 ) ;
if ( V_75 -> V_165 != V_75 -> V_184 )
F_131 ( V_75 -> V_165 ) ;
if ( V_75 -> V_265 != 0 ) {
F_102 ( V_75 -> V_32 , V_75 ) ;
return;
}
V_75 -> V_66 -> V_266 ( V_75 ) ;
}
static void F_53 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( F_123 ( & V_75 -> V_267 ) &&
! F_134 ( & V_75 -> V_267 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return;
}
if ( V_75 -> V_79 & V_96 ) {
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_132 ( V_75 ) ;
F_133 ( V_75 ) ;
return;
}
void * F_135 ( struct V_74 * V_75 )
{
struct V_194 * V_262 = V_75 -> V_115 ;
struct V_268 * * V_269 ;
int V_161 ;
if ( ! V_75 -> V_199 )
return NULL ;
F_10 ( ! V_262 ) ;
if ( V_75 -> V_199 == 1 )
return F_103 ( F_104 ( V_262 ) ) + V_262 -> V_212 ;
V_269 = F_136 ( sizeof( * V_269 ) * V_75 -> V_199 , V_33 ) ;
if ( ! V_269 )
return NULL ;
F_129 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_269 [ V_161 ] = F_104 ( V_262 ) ;
}
V_75 -> V_270 = F_137 ( V_269 , V_75 -> V_199 , V_271 , V_272 ) ;
F_131 ( V_269 ) ;
if ( ! V_75 -> V_270 )
return NULL ;
return V_75 -> V_270 + V_75 -> V_115 [ 0 ] . V_212 ;
}
void F_138 ( struct V_74 * V_75 )
{
if ( ! V_75 -> V_199 ) {
return;
} else if ( V_75 -> V_199 == 1 ) {
F_105 ( F_104 ( V_75 -> V_115 ) ) ;
return;
}
F_139 ( V_75 -> V_270 ) ;
V_75 -> V_270 = NULL ;
}
static int
F_140 ( struct V_74 * V_75 )
{
T_1 V_213 = V_75 -> V_164 ;
unsigned int V_261 ;
struct V_268 * V_268 ;
T_5 V_273 ;
int V_161 = 0 ;
V_261 = F_141 ( V_213 , V_274 ) ;
V_75 -> V_115 = F_136 ( sizeof( struct V_194 ) * V_261 , V_33 ) ;
if ( ! V_75 -> V_115 )
return - V_25 ;
V_75 -> V_199 = V_261 ;
F_142 ( V_75 -> V_115 , V_261 ) ;
V_273 = V_75 -> V_102 & V_211 ? 0 : V_275 ;
while ( V_213 ) {
T_1 V_276 = F_143 ( T_1 , V_213 , V_274 ) ;
V_268 = F_144 ( V_33 | V_273 ) ;
if ( ! V_268 )
goto V_3;
F_145 ( & V_75 -> V_115 [ V_161 ] , V_268 , V_276 , 0 ) ;
V_213 -= V_276 ;
V_161 ++ ;
}
return 0 ;
V_3:
while ( V_161 > 0 ) {
V_161 -- ;
F_130 ( F_104 ( & V_75 -> V_115 [ V_161 ] ) ) ;
}
F_131 ( V_75 -> V_115 ) ;
V_75 -> V_115 = NULL ;
return - V_25 ;
}
T_4
F_96 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
if ( ! ( V_75 -> V_102 & V_202 ) &&
V_75 -> V_164 ) {
V_30 = F_140 ( V_75 ) ;
if ( V_30 < 0 )
return V_101 ;
}
F_122 ( & V_75 -> V_267 ) ;
F_61 ( V_75 ) ;
if ( V_75 -> V_133 != V_136 ) {
F_124 ( V_75 ) ;
return 0 ;
}
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_122 = V_277 ;
F_26 ( & V_75 -> V_85 ) ;
F_48 ( V_75 , false ) ;
V_30 = V_75 -> V_66 -> V_278 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 )
goto V_245;
F_57 ( V_30 ) ;
return ( ! V_30 ) ? 0 : V_101 ;
V_245:
F_27 ( L_118 , V_75 ) ;
V_75 -> V_122 = V_132 ;
F_119 ( V_75 , V_75 -> V_78 ) ;
return 0 ;
}
static void F_68 ( struct V_74 * V_75 )
{
int V_30 ;
V_30 = V_75 -> V_66 -> V_278 ( V_75 ) ;
if ( V_30 == - V_244 || V_30 == - V_25 ) {
F_27 ( L_118 ,
V_75 ) ;
F_119 ( V_75 , V_75 -> V_78 ) ;
}
}
void F_146 ( struct V_74 * V_75 , int V_279 )
{
if ( ! ( V_75 -> V_102 & V_280 ) ) {
if ( V_279 && ( V_75 -> V_102 & V_264 ) )
F_147 ( V_75 ) ;
F_133 ( V_75 ) ;
} else {
if ( V_279 )
F_147 ( V_75 ) ;
F_148 ( V_75 -> V_32 -> V_41 , V_75 ) ;
if ( V_75 -> V_91 )
F_50 ( V_75 ) ;
F_53 ( V_75 ) ;
}
}
static int F_99 ( struct V_2 * V_32 , struct V_74 * V_74 ,
bool V_281 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_20 ( & V_74 -> V_282 ) ;
if ( V_281 == true ) {
F_23 ( & V_74 -> V_282 ) ;
V_74 -> V_102 |= V_283 ;
}
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( V_32 -> V_284 ) {
V_30 = - V_285 ;
goto V_3;
}
F_25 ( & V_74 -> V_173 , & V_32 -> V_36 ) ;
V_74 -> V_265 = 1 ;
V_3:
F_30 ( & V_32 -> V_37 , V_55 ) ;
return V_30 ;
}
static void F_149 ( struct V_57 * V_57 )
{
struct V_74 * V_74 = F_32 ( V_57 , struct V_74 , V_282 ) ;
struct V_2 * V_32 = V_74 -> V_32 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( F_41 ( & V_74 -> V_173 ) ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_266 ( V_74 ) ;
return;
}
if ( V_32 -> V_284 && V_74 -> V_286 ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
F_37 ( & V_74 -> V_175 ) ;
return;
}
F_40 ( & V_74 -> V_173 ) ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_266 ( V_74 ) ;
}
int F_102 ( struct V_2 * V_32 , struct V_74 * V_74 )
{
return F_35 ( & V_74 -> V_282 , F_149 ) ;
}
void F_150 ( struct V_2 * V_32 )
{
struct V_74 * V_74 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
F_57 ( V_32 -> V_284 ) ;
V_32 -> V_284 = 1 ;
F_151 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list)
V_74 -> V_286 = 1 ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
}
void F_152 (
struct V_2 * V_32 ,
int V_279 )
{
struct V_74 * V_74 , * V_287 ;
bool V_206 = false ;
F_65 (se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
F_40 ( & V_74 -> V_173 ) ;
F_27 ( L_119
L_120 , V_74 , V_74 -> V_122 ,
V_74 -> V_66 -> V_227 ( V_74 ) ) ;
if ( V_279 ) {
F_27 ( L_121
L_122 , V_74 , V_74 -> V_122 ,
V_74 -> V_66 -> V_227 ( V_74 ) ) ;
V_206 = F_147 ( V_74 ) ;
F_27 ( L_123
L_122 , V_74 , V_74 -> V_122 ,
V_74 -> V_66 -> V_227 ( V_74 ) ) ;
}
if ( ! V_206 ) {
F_116 ( & V_74 -> V_175 ) ;
F_27 ( L_124
L_122 , V_74 , V_74 -> V_122 ,
V_74 -> V_66 -> V_227 ( V_74 ) ) ;
}
V_74 -> V_66 -> V_266 ( V_74 ) ;
}
}
static int F_153 ( struct V_74 * V_75 , struct V_91 * V_95 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_79 & V_92 ) {
V_75 -> V_79 &= ~ V_86 ;
F_27 ( L_125 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_48 ( V_75 , false ) ;
return - V_288 ;
}
V_75 -> V_79 |= V_289 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ( V_75 -> V_79 & V_80 ) &&
( V_75 -> V_79 & V_228 ) ) {
if ( ! F_115 ( V_75 , & V_55 ) )
V_30 ++ ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_27 ( L_126
L_120 , V_75 , V_30 ) ;
if ( ! V_30 ) {
F_27 ( L_127 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_116 ( & V_75 -> V_90 ) ;
F_27 ( L_128 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
}
return 0 ;
}
static void F_154 ( struct V_91 * V_95 )
{
struct V_74 * V_75 = NULL ;
unsigned long V_290 , V_291 ;
F_29 ( & V_95 -> V_97 , V_290 ) ;
while ( ! F_41 ( & V_95 -> V_292 ) ) {
V_75 = F_155 ( & V_95 -> V_292 ,
struct V_74 , V_98 ) ;
F_51 ( & V_75 -> V_98 ) ;
F_11 ( & V_75 -> V_85 ) ;
F_27 ( L_129
L_130 ,
V_75 -> V_91 -> V_204 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 |= V_86 ;
F_12 ( & V_75 -> V_85 ) ;
F_30 ( & V_95 -> V_97 , V_290 ) ;
if ( ! V_75 -> V_91 ) {
F_4 ( L_131 ,
V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_227 ( V_75 ) , V_75 -> V_122 ) ;
F_156 () ;
}
F_27 ( L_132
L_133 , V_75 -> V_91 -> V_204 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
if ( F_153 ( V_75 , V_75 -> V_91 ) < 0 ) {
F_29 ( & V_95 -> V_97 , V_290 ) ;
continue;
}
F_27 ( L_134
L_135 ,
V_75 -> V_91 -> V_204 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_29 ( & V_75 -> V_85 , V_291 ) ;
if ( ! ( V_75 -> V_79 & V_96 ) ) {
F_30 ( & V_75 -> V_85 , V_291 ) ;
goto V_293;
}
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
F_30 ( & V_75 -> V_85 , V_291 ) ;
V_293:
F_101 ( V_75 ,
V_229 , 0 ) ;
F_29 ( & V_75 -> V_85 , V_291 ) ;
if ( V_75 -> V_79 & V_289 ) {
F_27 ( L_136
L_137 ,
V_95 -> V_204 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 ,
V_291 ) ;
F_48 ( V_75 , false ) ;
F_37 ( & V_75 -> V_174 ) ;
F_29 ( & V_95 -> V_97 , V_290 ) ;
continue;
}
F_27 ( L_138 ,
V_95 -> V_204 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_291 ) ;
F_29 ( & V_95 -> V_97 , V_290 ) ;
}
F_30 ( & V_95 -> V_97 , V_290 ) ;
}
static int F_157 ( void * V_294 )
{
struct V_91 * V_95 = V_294 ;
F_154 ( V_95 ) ;
F_37 ( & V_95 -> V_295 ) ;
return 0 ;
}
int F_158 ( struct V_91 * V_95 )
{
struct V_296 * V_297 ;
V_297 = F_159 ( F_157 , V_95 ,
L_139 , V_95 -> V_204 ) ;
if ( F_160 ( V_297 ) ) {
F_4 ( L_140 ) ;
return F_161 ( V_297 ) ;
}
F_116 ( & V_95 -> V_295 ) ;
return 0 ;
}
bool F_147 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ! ( V_75 -> V_102 & V_280 ) &&
! ( V_75 -> V_102 & V_264 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( ! ( V_75 -> V_102 & V_188 ) &&
! ( V_75 -> V_102 & V_264 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_141
L_142
L_143 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_90 ) ;
F_116 ( & V_75 -> V_174 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
F_47 ( V_75 ) ;
F_27 ( L_144
L_145
L_146 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_86 ;
}
if ( ! ( V_75 -> V_79 & V_89 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
V_75 -> V_79 |= V_92 ;
F_27 ( L_147
L_148 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_227 ( V_75 ) , V_75 -> V_122 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_116 ( & V_75 -> V_93 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_79 &= ~ ( V_89 | V_92 ) ;
F_27 ( L_149
L_150 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
return true ;
}
static int F_162 (
struct V_74 * V_75 ,
T_3 * V_298 ,
T_3 * V_299 )
{
* V_298 = V_75 -> V_300 ;
* V_299 = V_75 -> V_301 ;
return 0 ;
}
int
F_101 ( struct V_74 * V_75 ,
T_4 V_302 , int V_303 )
{
unsigned char * V_304 = V_75 -> V_111 ;
unsigned long V_55 ;
T_3 V_298 = 0 , V_299 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_102 & V_103 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return 0 ;
}
V_75 -> V_102 |= V_103 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( ! V_302 && V_303 )
goto V_305;
if ( ! V_303 )
V_75 -> V_102 |= V_306 ;
switch ( V_302 ) {
case V_307 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_310 ;
V_304 [ V_311 ] = 0 ;
V_304 [ V_312 ] = 0 ;
break;
case V_229 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x25 ;
break;
case V_230 :
case V_314 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x20 ;
break;
case V_233 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x24 ;
break;
case V_236 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_315 ;
V_304 [ V_311 ] = 0x29 ;
V_304 [ V_312 ] = 0x03 ;
break;
case V_316 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_315 ;
V_304 [ V_311 ] = 0x0c ;
V_304 [ V_312 ] = 0x0d ;
break;
case V_166 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x24 ;
break;
case V_231 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x26 ;
break;
case V_232 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x1a ;
break;
case V_317 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_315 ;
V_304 [ V_311 ] = 0x0c ;
V_304 [ V_312 ] = 0x0c ;
break;
case V_318 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_315 ;
V_304 [ V_311 ] = 0x47 ;
V_304 [ V_312 ] = 0x05 ;
break;
case V_319 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_315 ;
V_304 [ V_311 ] = 0x11 ;
V_304 [ V_312 ] = 0x13 ;
break;
case V_234 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_320 ;
V_304 [ V_311 ] = 0x27 ;
break;
case V_235 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x21 ;
break;
case V_237 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_321 ;
F_163 ( V_75 , & V_298 , & V_299 ) ;
V_304 [ V_311 ] = V_298 ;
V_304 [ V_312 ] = V_299 ;
break;
case V_238 :
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_310 ;
F_162 ( V_75 , & V_298 , & V_299 ) ;
V_304 [ V_311 ] = V_298 ;
V_304 [ V_312 ] = V_299 ;
break;
case V_101 :
default:
V_304 [ 0 ] = 0x70 ;
V_304 [ V_308 ] = 10 ;
V_304 [ V_309 ] = V_313 ;
V_304 [ V_311 ] = 0x08 ;
break;
}
V_75 -> V_110 = V_322 ;
V_75 -> V_104 = V_105 ;
V_305:
return V_75 -> V_66 -> V_243 ( V_75 ) ;
}
int F_125 ( struct V_74 * V_75 , int V_323 )
{
if ( ! ( V_75 -> V_79 & V_120 ) )
return 0 ;
if ( ! V_323 || ( V_75 -> V_102 & V_324 ) )
return 1 ;
F_27 ( L_151 ,
V_75 -> V_165 [ 0 ] , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_102 |= V_324 ;
V_75 -> V_66 -> V_243 ( V_75 ) ;
return 1 ;
}
void F_164 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_102 & ( V_103 | V_324 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_133 == V_136 ) {
if ( V_75 -> V_66 -> V_325 ( V_75 ) != 0 ) {
V_75 -> V_79 |= V_120 ;
F_86 () ;
}
}
V_75 -> V_110 = V_326 ;
F_50 ( V_75 ) ;
F_27 ( L_152
L_153 , V_75 -> V_165 [ 0 ] ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_66 -> V_243 ( V_75 ) ;
}
static void F_165 ( struct V_99 * V_100 )
{
struct V_74 * V_75 = F_32 ( V_100 , struct V_74 , V_100 ) ;
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_214 * V_327 = V_75 -> V_214 ;
int V_30 ;
switch ( V_327 -> V_328 ) {
case V_223 :
F_166 ( V_77 , V_327 , V_75 -> V_32 ) ;
break;
case V_329 :
case V_330 :
case V_331 :
V_327 -> V_215 = V_332 ;
break;
case V_333 :
V_30 = F_167 ( V_77 , V_327 , NULL , NULL ) ;
V_327 -> V_215 = ( ! V_30 ) ? V_334 :
V_335 ;
break;
case V_336 :
V_327 -> V_215 = V_335 ;
break;
case V_337 :
V_327 -> V_215 = V_335 ;
break;
default:
F_4 ( L_154 ,
V_327 -> V_328 ) ;
V_327 -> V_215 = V_335 ;
break;
}
V_75 -> V_122 = V_338 ;
V_75 -> V_66 -> V_217 ( V_75 ) ;
F_49 ( V_75 ) ;
}
int F_114 (
struct V_74 * V_75 )
{
F_59 ( & V_75 -> V_100 , F_165 ) ;
F_60 ( V_75 -> V_78 -> V_339 , & V_75 -> V_100 ) ;
return 0 ;
}
