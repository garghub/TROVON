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
static int F_48 ( struct V_75 * V_76 , bool V_85 ,
bool V_86 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( V_86 )
V_76 -> V_88 = V_89 ;
if ( V_76 -> V_80 & V_90 ) {
F_27 ( L_28 ,
V_91 , __LINE__ , V_76 -> V_67 -> V_92 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_93 ;
if ( V_85 )
F_47 ( V_76 ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_37 ( & V_76 -> V_94 ) ;
return 1 ;
}
if ( V_85 ) {
F_47 ( V_76 ) ;
V_76 -> V_95 = NULL ;
}
if ( V_76 -> V_80 & V_96 ) {
F_27 ( L_29 ,
V_91 , __LINE__ ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_37 ( & V_76 -> V_97 ) ;
return 1 ;
}
V_76 -> V_80 &= ~ V_93 ;
if ( V_85 ) {
if ( V_76 -> V_67 -> V_98 != NULL ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return V_76 -> V_67 -> V_98 ( V_76 ) ;
}
}
F_30 ( & V_76 -> V_87 , V_56 ) ;
return 0 ;
}
static int F_49 ( struct V_75 * V_76 )
{
return F_48 ( V_76 , true , false ) ;
}
static void F_50 ( struct V_75 * V_76 )
{
struct V_95 * V_99 = V_76 -> V_95 ;
unsigned long V_56 ;
if ( ! V_99 )
return;
F_29 ( & V_99 -> V_100 , V_56 ) ;
if ( ! F_41 ( & V_76 -> V_101 ) )
F_51 ( & V_76 -> V_101 ) ;
F_30 ( & V_99 -> V_100 , V_56 ) ;
}
void F_52 ( struct V_75 * V_76 , int remove )
{
if ( F_49 ( V_76 ) )
return;
if ( remove )
F_53 ( V_76 ) ;
}
static void F_54 ( struct V_102 * V_103 )
{
struct V_75 * V_76 = F_32 ( V_103 , struct V_75 , V_103 ) ;
F_55 ( V_76 ,
V_104 ) ;
}
static unsigned char * F_56 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
F_57 ( ! V_76 -> V_95 ) ;
if ( ! V_78 )
return NULL ;
if ( V_76 -> V_105 & V_106 )
return NULL ;
V_76 -> V_107 = V_108 ;
F_27 ( L_30 ,
V_78 -> V_109 -> V_110 , V_78 -> V_111 -> V_112 , V_76 -> V_113 ) ;
return V_76 -> V_114 ;
}
void F_58 ( struct V_75 * V_76 , T_3 V_113 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
int V_115 = V_113 == V_116 ;
unsigned long V_56 ;
V_76 -> V_113 = V_113 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
V_76 -> V_80 &= ~ V_81 ;
if ( V_78 && V_78 -> V_111 -> V_117 ) {
V_78 -> V_111 -> V_117 ( V_76 ,
V_76 -> V_118 ,
F_56 ( V_76 ) ) ;
if ( V_76 -> V_105 & V_119 )
V_115 = 1 ;
}
if ( V_76 -> V_80 & V_120 ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_37 ( & V_76 -> V_121 ) ;
return;
}
if ( ! V_115 )
V_76 -> V_80 |= V_122 ;
if ( V_76 -> V_80 & V_123 &&
V_76 -> V_80 & V_96 ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_37 ( & V_76 -> V_97 ) ;
return;
} else if ( V_76 -> V_80 & V_122 ) {
F_59 ( & V_76 -> V_103 , F_54 ) ;
} else {
F_59 ( & V_76 -> V_103 , V_124 ) ;
}
V_76 -> V_88 = V_125 ;
V_76 -> V_80 |= ( V_126 | V_93 ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_60 ( V_22 , & V_76 -> V_103 ) ;
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
void F_62 ( struct V_102 * V_103 )
{
struct V_77 * V_78 = F_32 ( V_103 , struct V_77 ,
V_127 ) ;
F_63 ( V_128 ) ;
struct V_75 * V_76 , * V_129 ;
F_24 ( & V_78 -> V_130 ) ;
F_64 ( & V_78 -> V_128 , & V_128 ) ;
F_26 ( & V_78 -> V_130 ) ;
F_65 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_40 ( & V_76 -> V_131 ) ;
F_66 ( & V_78 -> V_132 ) ;
F_67 () ;
F_27 ( L_31
L_32 , V_76 -> V_67 -> V_55 () , V_76 ,
( V_76 -> V_88 == V_133 ) ? L_33 :
( V_76 -> V_88 == V_134 ) ? L_34
: L_35 ) ;
if ( V_76 -> V_88 == V_134 )
F_68 ( V_76 ) ;
else if ( V_76 -> V_88 == V_133 )
F_69 ( V_76 ) ;
}
}
unsigned char * F_70 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_135 ) {
case V_136 :
return L_36 ;
case V_137 :
return L_37 ;
case V_138 :
return L_38 ;
case V_139 :
return L_39 ;
default:
break;
}
return L_35 ;
}
void F_71 (
struct V_77 * V_78 ,
char * V_140 ,
int * V_141 )
{
* V_141 += sprintf ( V_140 + * V_141 , L_40 ) ;
if ( V_78 -> V_142 )
* V_141 += sprintf ( V_140 + * V_141 , L_41 ) ;
else
* V_141 += sprintf ( V_140 + * V_141 , L_42 ) ;
* V_141 += sprintf ( V_140 + * V_141 , L_43 , V_78 -> V_143 ) ;
* V_141 += sprintf ( V_140 + * V_141 , L_44 ,
V_78 -> V_144 . V_145 ,
V_78 -> V_144 . V_146 ) ;
* V_141 += sprintf ( V_140 + * V_141 , L_45 ) ;
}
void F_72 (
struct V_147 * V_148 ,
unsigned char * V_149 ,
int V_150 )
{
unsigned char V_45 [ V_151 ] ;
int V_152 ;
memset ( V_45 , 0 , V_151 ) ;
V_152 = sprintf ( V_45 , L_46 ) ;
switch ( V_148 -> V_153 ) {
case 0x00 :
sprintf ( V_45 + V_152 , L_47 ) ;
break;
case 0x10 :
sprintf ( V_45 + V_152 , L_48 ) ;
break;
case 0x20 :
sprintf ( V_45 + V_152 , L_49 ) ;
break;
case 0x30 :
sprintf ( V_45 + V_152 , L_50 ) ;
break;
case 0x40 :
sprintf ( V_45 + V_152 , L_51
L_52 ) ;
break;
case 0x50 :
sprintf ( V_45 + V_152 , L_53 ) ;
break;
case 0x60 :
sprintf ( V_45 + V_152 , L_54 ) ;
break;
case 0x70 :
sprintf ( V_45 + V_152 , L_55
L_52 ) ;
break;
case 0x80 :
sprintf ( V_45 + V_152 , L_56 ) ;
break;
default:
sprintf ( V_45 + V_152 , L_57 ,
V_148 -> V_153 ) ;
break;
}
if ( V_149 )
strncpy ( V_149 , V_45 , V_150 ) ;
else
F_27 ( L_58 , V_45 ) ;
}
void
F_73 ( struct V_147 * V_148 , unsigned char * V_154 )
{
if ( V_154 [ 1 ] & 0x80 ) {
V_148 -> V_153 = ( V_154 [ 0 ] & 0xf0 ) ;
V_148 -> V_155 = 1 ;
F_72 ( V_148 , NULL , 0 ) ;
}
}
int F_74 (
struct V_147 * V_148 ,
unsigned char * V_149 ,
int V_150 )
{
unsigned char V_45 [ V_151 ] ;
int V_30 = 0 ;
int V_152 ;
memset ( V_45 , 0 , V_151 ) ;
V_152 = sprintf ( V_45 , L_59 ) ;
switch ( V_148 -> V_156 ) {
case 0x00 :
sprintf ( V_45 + V_152 , L_60 ) ;
break;
case 0x10 :
sprintf ( V_45 + V_152 , L_61 ) ;
break;
case 0x20 :
sprintf ( V_45 + V_152 , L_62 ) ;
break;
default:
sprintf ( V_45 + V_152 , L_57 , V_148 -> V_156 ) ;
V_30 = - V_157 ;
break;
}
if ( V_149 )
strncpy ( V_149 , V_45 , V_150 ) ;
else
F_27 ( L_58 , V_45 ) ;
return V_30 ;
}
int F_75 ( struct V_147 * V_148 , unsigned char * V_154 )
{
V_148 -> V_156 = ( V_154 [ 1 ] & 0x30 ) ;
return F_74 ( V_148 , NULL , 0 ) ;
}
int F_76 (
struct V_147 * V_148 ,
unsigned char * V_149 ,
int V_150 )
{
unsigned char V_45 [ V_151 ] ;
int V_30 = 0 ;
int V_152 ;
memset ( V_45 , 0 , V_151 ) ;
V_152 = sprintf ( V_45 , L_63 ) ;
switch ( V_148 -> V_158 ) {
case 0x00 :
sprintf ( V_45 + V_152 , L_64 ) ;
break;
case 0x01 :
sprintf ( V_45 + V_152 , L_65 ) ;
break;
case 0x02 :
sprintf ( V_45 + V_152 , L_66 ) ;
break;
case 0x03 :
sprintf ( V_45 + V_152 , L_67 ) ;
break;
case 0x04 :
sprintf ( V_45 + V_152 , L_68 ) ;
break;
case 0x08 :
sprintf ( V_45 + V_152 , L_69 ) ;
break;
default:
sprintf ( V_45 + V_152 , L_70 ,
V_148 -> V_158 ) ;
V_30 = - V_157 ;
break;
}
if ( V_149 ) {
if ( V_150 < strlen ( V_45 ) + 1 )
return - V_157 ;
strncpy ( V_149 , V_45 , V_150 ) ;
} else {
F_27 ( L_58 , V_45 ) ;
}
return V_30 ;
}
int F_77 ( struct V_147 * V_148 , unsigned char * V_154 )
{
V_148 -> V_158 = ( V_154 [ 1 ] & 0x0f ) ;
return F_76 ( V_148 , NULL , 0 ) ;
}
int F_78 (
struct V_147 * V_148 ,
unsigned char * V_149 ,
int V_150 )
{
unsigned char V_45 [ V_151 ] ;
int V_30 = 0 ;
memset ( V_45 , 0 , V_151 ) ;
switch ( V_148 -> V_159 ) {
case 0x01 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_71 ,
& V_148 -> V_160 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_72 ,
& V_148 -> V_160 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_45 , sizeof( V_45 ) ,
L_73 ,
& V_148 -> V_160 [ 0 ] ) ;
break;
default:
sprintf ( V_45 , L_74
L_75 , V_148 -> V_159 ) ;
V_30 = - V_157 ;
break;
}
if ( V_149 )
strncpy ( V_149 , V_45 , V_150 ) ;
else
F_27 ( L_58 , V_45 ) ;
return V_30 ;
}
int
F_79 ( struct V_147 * V_148 , unsigned char * V_154 )
{
static const char V_161 [] = L_76 ;
int V_162 = 0 , V_163 = 4 ;
V_148 -> V_159 = ( V_154 [ 0 ] & 0x0f ) ;
switch ( V_148 -> V_159 ) {
case 0x01 :
V_148 -> V_160 [ V_162 ++ ] =
V_161 [ V_148 -> V_158 ] ;
while ( V_163 < ( 4 + V_154 [ 3 ] ) ) {
V_148 -> V_160 [ V_162 ++ ] =
V_161 [ ( V_154 [ V_163 ] & 0xf0 ) >> 4 ] ;
V_148 -> V_160 [ V_162 ++ ] =
V_161 [ V_154 [ V_163 ] & 0x0f ] ;
V_163 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_163 < ( 4 + V_154 [ 3 ] ) )
V_148 -> V_160 [ V_162 ++ ] = V_154 [ V_163 ++ ] ;
break;
default:
break;
}
return F_78 ( V_148 , NULL , 0 ) ;
}
T_4
F_80 ( struct V_75 * V_76 , unsigned int V_164 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_76 -> V_165 ) {
V_76 -> V_166 = V_164 ;
} else if ( V_164 != V_76 -> V_166 ) {
F_81 ( L_77
L_78
L_79 , V_76 -> V_67 -> V_55 () ,
V_76 -> V_166 , V_164 , V_76 -> V_167 [ 0 ] ) ;
if ( V_76 -> V_135 == V_138 ) {
F_4 ( L_80
L_81 ) ;
return V_168 ;
}
if ( V_78 -> V_144 . V_145 != 512 ) {
F_4 ( L_82
L_83
L_84 , V_78 -> V_111 -> V_112 ) ;
return V_168 ;
}
if ( V_164 > V_76 -> V_166 ) {
V_76 -> V_105 |= V_169 ;
V_76 -> V_170 = ( V_164 - V_76 -> V_166 ) ;
} else {
V_76 -> V_105 |= V_171 ;
V_76 -> V_170 = ( V_76 -> V_166 - V_164 ) ;
V_76 -> V_166 = V_164 ;
}
}
return 0 ;
}
void F_82 (
struct V_75 * V_76 ,
struct V_66 * V_172 ,
struct V_2 * V_32 ,
T_1 V_166 ,
int V_135 ,
int V_173 ,
unsigned char * V_114 )
{
F_18 ( & V_76 -> V_101 ) ;
F_18 ( & V_76 -> V_174 ) ;
F_18 ( & V_76 -> V_131 ) ;
F_18 ( & V_76 -> V_175 ) ;
F_18 ( & V_76 -> V_84 ) ;
F_83 ( & V_76 -> V_176 ) ;
F_83 ( & V_76 -> V_94 ) ;
F_83 ( & V_76 -> V_97 ) ;
F_83 ( & V_76 -> V_177 ) ;
F_83 ( & V_76 -> V_121 ) ;
F_19 ( & V_76 -> V_87 ) ;
V_76 -> V_80 = V_178 ;
V_76 -> V_67 = V_172 ;
V_76 -> V_32 = V_32 ;
V_76 -> V_166 = V_166 ;
V_76 -> V_135 = V_135 ;
V_76 -> V_179 = V_173 ;
V_76 -> V_114 = V_114 ;
V_76 -> V_83 = false ;
}
static T_4
F_84 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_111 -> V_180 == V_181 )
return 0 ;
if ( V_76 -> V_179 == V_182 ) {
F_27 ( L_85
L_86 ) ;
return V_168 ;
}
V_76 -> V_183 = F_85 ( & V_78 -> V_184 ) ;
F_86 () ;
F_27 ( L_87 ,
V_76 -> V_183 , V_76 -> V_179 ,
V_78 -> V_111 -> V_112 ) ;
return 0 ;
}
T_4
F_87 ( struct V_75 * V_76 , unsigned char * V_185 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
T_4 V_30 ;
if ( F_88 ( V_185 ) > V_186 ) {
F_4 ( L_88
L_89 ,
F_88 ( V_185 ) , V_186 ) ;
return V_168 ;
}
if ( F_88 ( V_185 ) > sizeof( V_76 -> V_187 ) ) {
V_76 -> V_167 = F_89 ( F_88 ( V_185 ) ,
V_33 ) ;
if ( ! V_76 -> V_167 ) {
F_4 ( L_90
L_91 ,
F_88 ( V_185 ) ,
( unsigned long ) sizeof( V_76 -> V_187 ) ) ;
return V_188 ;
}
} else
V_76 -> V_167 = & V_76 -> V_187 [ 0 ] ;
memcpy ( V_76 -> V_167 , V_185 , F_88 ( V_185 ) ) ;
F_90 ( V_76 ) ;
V_30 = F_91 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_92 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_93 ( V_76 ) ;
if ( V_30 ) {
V_76 -> V_113 = V_189 ;
return V_30 ;
}
V_30 = V_78 -> V_111 -> V_190 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_84 ( V_76 ) ;
if ( V_30 )
return V_30 ;
V_76 -> V_105 |= V_191 ;
F_11 ( & V_76 -> V_95 -> V_192 ) ;
if ( V_76 -> V_95 -> V_193 )
V_76 -> V_95 -> V_193 -> V_194 . V_195 ++ ;
F_12 ( & V_76 -> V_95 -> V_192 ) ;
return 0 ;
}
int F_94 (
struct V_75 * V_76 )
{
T_4 V_30 ;
if ( ! V_76 -> V_95 ) {
F_95 () ;
F_4 ( L_92 ) ;
return - V_157 ;
}
if ( F_96 () ) {
F_95 () ;
F_4 ( L_93
L_94 ) ;
return - V_157 ;
}
V_76 -> V_88 = V_196 ;
V_76 -> V_80 |= V_93 ;
V_30 = F_97 ( V_76 ) ;
if ( V_30 )
F_55 ( V_76 , V_30 ) ;
return 0 ;
}
static T_4
F_98 ( struct V_75 * V_76 , struct V_197 * V_198 ,
T_1 V_199 , struct V_197 * V_200 , T_1 V_201 )
{
if ( ! V_198 || ! V_199 )
return 0 ;
if ( V_76 -> V_105 & V_169 ) {
F_81 ( L_95
L_96 ) ;
return V_168 ;
}
V_76 -> V_118 = V_198 ;
V_76 -> V_202 = V_199 ;
if ( V_200 && V_201 ) {
V_76 -> V_203 = V_200 ;
V_76 -> V_204 = V_201 ;
}
V_76 -> V_105 |= V_205 ;
return 0 ;
}
int F_99 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_185 , unsigned char * V_206 , T_1 V_207 ,
T_1 V_166 , int V_173 , int V_208 , int V_56 ,
struct V_197 * V_198 , T_1 V_199 ,
struct V_197 * V_200 , T_1 V_201 )
{
struct V_40 * V_41 ;
T_4 V_209 ;
int V_30 ;
V_41 = V_32 -> V_41 ;
F_10 ( ! V_41 ) ;
F_10 ( V_75 -> V_67 || V_75 -> V_32 ) ;
F_10 ( F_96 () ) ;
F_82 ( V_75 , V_41 -> V_47 , V_32 ,
V_166 , V_208 , V_173 , V_206 ) ;
if ( V_56 & V_210 )
V_75 -> V_165 = 1 ;
V_30 = F_100 ( V_32 , V_75 , ( V_56 & V_211 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_56 & V_212 )
V_75 -> V_105 |= V_213 ;
V_209 = F_101 ( V_75 , V_207 ) ;
if ( V_209 ) {
F_102 ( V_75 , V_209 , 0 ) ;
F_103 ( V_32 , V_75 ) ;
return 0 ;
}
V_209 = F_87 ( V_75 , V_185 ) ;
if ( V_209 != 0 ) {
F_55 ( V_75 , V_209 ) ;
return 0 ;
}
if ( V_199 != 0 ) {
F_10 ( ! V_198 ) ;
if ( ! ( V_75 -> V_105 & V_214 ) &&
V_75 -> V_135 == V_137 ) {
unsigned char * V_45 = NULL ;
if ( V_198 )
V_45 = F_104 ( F_105 ( V_198 ) ) + V_198 -> V_215 ;
if ( V_45 ) {
memset ( V_45 , 0 , V_198 -> V_216 ) ;
F_106 ( F_105 ( V_198 ) ) ;
}
}
V_209 = F_98 ( V_75 , V_198 , V_199 ,
V_200 , V_201 ) ;
if ( V_209 != 0 ) {
F_55 ( V_75 , V_209 ) ;
return 0 ;
}
}
F_107 ( V_75 ) ;
F_94 ( V_75 ) ;
return 0 ;
}
int F_108 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_185 , unsigned char * V_206 , T_1 V_207 ,
T_1 V_166 , int V_173 , int V_208 , int V_56 )
{
return F_99 ( V_75 , V_32 , V_185 , V_206 ,
V_207 , V_166 , V_173 , V_208 ,
V_56 , NULL , 0 , NULL , 0 ) ;
}
static void F_109 ( struct V_102 * V_103 )
{
struct V_75 * V_75 = F_32 ( V_103 , struct V_75 , V_103 ) ;
V_75 -> V_217 -> V_218 = V_219 ;
V_75 -> V_67 -> V_220 ( V_75 ) ;
F_49 ( V_75 ) ;
}
int F_110 ( struct V_75 * V_75 , struct V_2 * V_32 ,
unsigned char * V_206 , T_1 V_207 ,
void * V_221 , unsigned char V_222 ,
T_5 V_223 , unsigned int V_224 , int V_56 )
{
struct V_40 * V_41 ;
int V_30 ;
V_41 = V_32 -> V_41 ;
F_10 ( ! V_41 ) ;
F_82 ( V_75 , V_41 -> V_47 , V_32 ,
0 , V_136 , V_225 , V_206 ) ;
V_30 = F_111 ( V_75 , V_221 , V_222 , V_223 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_222 == V_226 )
V_75 -> V_217 -> V_227 = V_224 ;
V_30 = F_100 ( V_32 , V_75 , ( V_56 & V_211 ) ) ;
if ( V_30 ) {
F_112 ( V_75 -> V_217 ) ;
return V_30 ;
}
V_30 = F_113 ( V_75 , V_207 ) ;
if ( V_30 ) {
F_59 ( & V_75 -> V_103 , F_109 ) ;
F_114 ( & V_75 -> V_103 ) ;
return 0 ;
}
F_115 ( V_75 ) ;
return 0 ;
}
bool F_116 ( struct V_75 * V_76 , unsigned long * V_56 )
{
bool V_228 = false ;
if ( V_76 -> V_80 & V_81 ) {
V_76 -> V_80 |= V_120 ;
F_30 ( & V_76 -> V_87 , * V_56 ) ;
F_27 ( L_97 , V_76 ) ;
F_117 ( & V_76 -> V_121 ) ;
F_27 ( L_98 , V_76 ) ;
F_29 ( & V_76 -> V_87 , * V_56 ) ;
V_76 -> V_80 &= ~ V_120 ;
V_76 -> V_80 &= ~ V_81 ;
V_228 = true ;
}
return V_228 ;
}
void F_55 ( struct V_75 * V_76 ,
T_4 V_229 )
{
int V_30 = 0 ;
F_27 ( L_99
L_100 , V_76 , V_76 -> V_67 -> V_92 ( V_76 ) ,
V_76 -> V_167 [ 0 ] ) ;
F_27 ( L_101 ,
V_76 -> V_67 -> V_230 ( V_76 ) ,
V_76 -> V_88 , V_229 ) ;
F_27 ( L_102 ,
( V_76 -> V_80 & V_93 ) != 0 ,
( V_76 -> V_80 & V_96 ) != 0 ,
( V_76 -> V_80 & V_231 ) != 0 ) ;
F_118 ( V_76 ) ;
switch ( V_229 ) {
case V_232 :
case V_233 :
case V_168 :
case V_234 :
case V_235 :
case V_104 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
break;
case V_188 :
V_229 = V_104 ;
break;
case V_242 :
V_76 -> V_113 = V_189 ;
if ( V_76 -> V_32 &&
V_76 -> V_79 -> V_144 . V_243 == 2 )
F_119 ( V_76 -> V_32 -> V_42 ,
V_76 -> V_244 , 0x2C ,
V_245 ) ;
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_246 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
goto V_249;
default:
F_4 ( L_103 ,
V_76 -> V_167 [ 0 ] , V_229 ) ;
V_229 = V_233 ;
break;
}
V_30 = F_102 ( V_76 , V_229 , 0 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
V_249:
F_50 ( V_76 ) ;
if ( ! F_49 ( V_76 ) )
;
return;
V_248:
V_76 -> V_88 = V_133 ;
F_121 ( V_76 , V_76 -> V_79 ) ;
}
static void F_122 ( struct V_75 * V_76 )
{
T_4 V_30 ;
if ( V_76 -> V_250 ) {
V_30 = V_76 -> V_250 ( V_76 ) ;
if ( V_30 ) {
F_24 ( & V_76 -> V_87 ) ;
V_76 -> V_80 &= ~ ( V_81 | V_231 ) ;
F_26 ( & V_76 -> V_87 ) ;
F_55 ( V_76 , V_30 ) ;
}
}
}
static bool F_123 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_111 -> V_180 == V_181 )
return false ;
switch ( V_76 -> V_179 ) {
case V_251 :
F_27 ( L_104
L_105 ,
V_76 -> V_167 [ 0 ] , V_76 -> V_183 ) ;
return false ;
case V_252 :
F_124 ( & V_78 -> V_253 ) ;
F_86 () ;
F_27 ( L_106
L_107 ,
V_76 -> V_167 [ 0 ] , V_76 -> V_183 ) ;
if ( ! F_125 ( & V_78 -> V_254 ) )
return false ;
break;
default:
F_124 ( & V_78 -> V_254 ) ;
F_86 () ;
break;
}
if ( F_125 ( & V_78 -> V_253 ) == 0 )
return false ;
F_11 ( & V_78 -> V_255 ) ;
F_25 ( & V_76 -> V_174 , & V_78 -> V_256 ) ;
F_12 ( & V_78 -> V_255 ) ;
F_27 ( L_108
L_109 ,
V_76 -> V_167 [ 0 ] , V_76 -> V_179 ,
V_76 -> V_183 ) ;
return true ;
}
void F_126 ( struct V_75 * V_76 )
{
if ( F_127 ( V_76 , 1 ) ) {
F_37 ( & V_76 -> V_94 ) ;
return;
}
F_24 ( & V_76 -> V_87 ) ;
if ( V_76 -> V_80 & V_90 ) {
F_27 ( L_28 ,
V_91 , __LINE__ , V_76 -> V_67 -> V_92 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_93 ;
F_26 ( & V_76 -> V_87 ) ;
F_37 ( & V_76 -> V_94 ) ;
return;
}
if ( V_76 -> V_80 & V_96 ) {
F_27 ( L_29 ,
V_91 , __LINE__ ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_26 ( & V_76 -> V_87 ) ;
F_37 ( & V_76 -> V_97 ) ;
return;
}
V_76 -> V_88 = V_257 ;
V_76 -> V_80 |= V_93 | V_81 | V_231 ;
F_26 ( & V_76 -> V_87 ) ;
if ( F_123 ( V_76 ) ) {
F_24 ( & V_76 -> V_87 ) ;
V_76 -> V_80 &= ~ V_81 | V_231 ;
F_26 ( & V_76 -> V_87 ) ;
return;
}
F_122 ( V_76 ) ;
}
static void F_128 ( struct V_77 * V_78 )
{
for (; ; ) {
struct V_75 * V_76 ;
F_11 ( & V_78 -> V_255 ) ;
if ( F_41 ( & V_78 -> V_256 ) ) {
F_12 ( & V_78 -> V_255 ) ;
break;
}
V_76 = F_129 ( V_78 -> V_256 . V_258 ,
struct V_75 , V_174 ) ;
F_40 ( & V_76 -> V_174 ) ;
F_12 ( & V_78 -> V_255 ) ;
F_122 ( V_76 ) ;
if ( V_76 -> V_179 == V_252 )
break;
}
}
static void F_118 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_79 ;
if ( V_78 -> V_111 -> V_180 == V_181 )
return;
if ( V_76 -> V_179 == V_225 ) {
F_66 ( & V_78 -> V_254 ) ;
F_67 () ;
V_78 -> V_259 ++ ;
F_27 ( L_110
L_111 , V_78 -> V_259 ,
V_76 -> V_183 ) ;
} else if ( V_76 -> V_179 == V_251 ) {
V_78 -> V_259 ++ ;
F_27 ( L_112
L_113 , V_78 -> V_259 ,
V_76 -> V_183 ) ;
} else if ( V_76 -> V_179 == V_252 ) {
F_66 ( & V_78 -> V_253 ) ;
F_67 () ;
V_78 -> V_259 ++ ;
F_27 ( L_114
L_115 , V_78 -> V_259 , V_76 -> V_183 ) ;
}
F_128 ( V_78 ) ;
}
static void F_69 ( struct V_75 * V_76 )
{
int V_30 = 0 ;
F_118 ( V_76 ) ;
if ( V_76 -> V_105 & V_119 ) {
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_246 ( V_76 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_76 -> V_135 ) {
case V_137 :
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_260 ( V_76 ) ;
break;
case V_138 :
if ( V_76 -> V_203 ) {
V_30 = V_76 -> V_67 -> V_260 ( V_76 ) ;
if ( V_30 < 0 )
break;
}
case V_136 :
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_246 ( V_76 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_121 ( V_76 , V_76 -> V_79 ) ;
return;
}
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
}
static void F_121 (
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
F_24 ( & V_78 -> V_130 ) ;
F_25 ( & V_76 -> V_131 , & V_76 -> V_79 -> V_128 ) ;
F_124 ( & V_78 -> V_132 ) ;
F_86 () ;
F_26 ( & V_76 -> V_79 -> V_130 ) ;
F_114 ( & V_76 -> V_79 -> V_127 ) ;
}
static void V_124 ( struct V_102 * V_103 )
{
struct V_75 * V_76 = F_32 ( V_103 , struct V_75 , V_103 ) ;
int V_30 ;
F_118 ( V_76 ) ;
if ( F_125 ( & V_76 -> V_79 -> V_132 ) != 0 )
F_114 ( & V_76 -> V_79 -> V_127 ) ;
if ( V_76 -> V_105 & V_119 ) {
F_57 ( ! V_76 -> V_113 ) ;
V_30 = F_102 (
V_76 , 0 , 1 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
return;
}
if ( V_76 -> V_261 )
V_76 -> V_261 ( V_76 ) ;
switch ( V_76 -> V_135 ) {
case V_137 :
F_11 ( & V_76 -> V_95 -> V_192 ) ;
if ( V_76 -> V_95 -> V_193 ) {
V_76 -> V_95 -> V_193 -> V_194 . V_262 +=
V_76 -> V_166 ;
}
F_12 ( & V_76 -> V_95 -> V_192 ) ;
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_260 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
break;
case V_138 :
F_11 ( & V_76 -> V_95 -> V_192 ) ;
if ( V_76 -> V_95 -> V_193 ) {
V_76 -> V_95 -> V_193 -> V_194 . V_263 +=
V_76 -> V_166 ;
}
F_12 ( & V_76 -> V_95 -> V_192 ) ;
if ( V_76 -> V_203 ) {
F_11 ( & V_76 -> V_95 -> V_192 ) ;
if ( V_76 -> V_95 -> V_193 ) {
V_76 -> V_95 -> V_193 -> V_194 . V_262 +=
V_76 -> V_166 ;
}
F_12 ( & V_76 -> V_95 -> V_192 ) ;
V_30 = V_76 -> V_67 -> V_260 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
break;
}
case V_136 :
F_120 ( V_76 ) ;
V_30 = V_76 -> V_67 -> V_246 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
break;
default:
break;
}
F_50 ( V_76 ) ;
F_49 ( V_76 ) ;
return;
V_248:
F_27 ( L_116
L_117 , V_76 , V_76 -> V_135 ) ;
V_76 -> V_88 = V_133 ;
F_121 ( V_76 , V_76 -> V_79 ) ;
}
static inline void F_130 ( struct V_197 * V_198 , int V_264 )
{
struct V_197 * V_265 ;
int V_266 ;
F_131 (sgl, sg, nents, count)
F_132 ( F_105 ( V_265 ) ) ;
F_133 ( V_198 ) ;
}
static inline void F_134 ( struct V_75 * V_76 )
{
if ( V_76 -> V_105 & V_205 )
return;
F_130 ( V_76 -> V_118 , V_76 -> V_202 ) ;
V_76 -> V_118 = NULL ;
V_76 -> V_202 = 0 ;
F_130 ( V_76 -> V_203 , V_76 -> V_204 ) ;
V_76 -> V_203 = NULL ;
V_76 -> V_204 = 0 ;
}
static int F_135 ( struct V_75 * V_76 )
{
F_10 ( ! V_76 -> V_67 ) ;
if ( V_76 -> V_105 & V_267 )
F_112 ( V_76 -> V_217 ) ;
if ( V_76 -> V_167 != V_76 -> V_187 )
F_133 ( V_76 -> V_167 ) ;
return F_103 ( V_76 -> V_32 , V_76 ) ;
}
static int F_53 ( struct V_75 * V_76 )
{
F_134 ( V_76 ) ;
return F_135 ( V_76 ) ;
}
void * F_136 ( struct V_75 * V_76 )
{
struct V_197 * V_265 = V_76 -> V_118 ;
struct V_268 * * V_269 ;
int V_163 ;
if ( ! V_76 -> V_202 )
return NULL ;
F_10 ( ! V_265 ) ;
if ( V_76 -> V_202 == 1 )
return F_104 ( F_105 ( V_265 ) ) + V_265 -> V_215 ;
V_269 = F_137 ( sizeof( * V_269 ) * V_76 -> V_202 , V_33 ) ;
if ( ! V_269 )
return NULL ;
F_131 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_269 [ V_163 ] = F_105 ( V_265 ) ;
}
V_76 -> V_270 = F_138 ( V_269 , V_76 -> V_202 , V_271 , V_272 ) ;
F_133 ( V_269 ) ;
if ( ! V_76 -> V_270 )
return NULL ;
return V_76 -> V_270 + V_76 -> V_118 [ 0 ] . V_215 ;
}
void F_139 ( struct V_75 * V_76 )
{
if ( ! V_76 -> V_202 ) {
return;
} else if ( V_76 -> V_202 == 1 ) {
F_106 ( F_105 ( V_76 -> V_118 ) ) ;
return;
}
F_140 ( V_76 -> V_270 ) ;
V_76 -> V_270 = NULL ;
}
static int
F_141 ( struct V_75 * V_76 )
{
T_1 V_216 = V_76 -> V_166 ;
unsigned int V_264 ;
struct V_268 * V_268 ;
T_5 V_273 ;
int V_163 = 0 ;
V_264 = F_142 ( V_216 , V_274 ) ;
V_76 -> V_118 = F_137 ( sizeof( struct V_197 ) * V_264 , V_33 ) ;
if ( ! V_76 -> V_118 )
return - V_25 ;
V_76 -> V_202 = V_264 ;
F_143 ( V_76 -> V_118 , V_264 ) ;
V_273 = V_76 -> V_105 & V_214 ? 0 : V_275 ;
while ( V_216 ) {
T_1 V_276 = F_144 ( T_1 , V_216 , V_274 ) ;
V_268 = F_145 ( V_33 | V_273 ) ;
if ( ! V_268 )
goto V_3;
F_146 ( & V_76 -> V_118 [ V_163 ] , V_268 , V_276 , 0 ) ;
V_216 -= V_276 ;
V_163 ++ ;
}
return 0 ;
V_3:
while ( V_163 > 0 ) {
V_163 -- ;
F_132 ( F_105 ( & V_76 -> V_118 [ V_163 ] ) ) ;
}
F_133 ( V_76 -> V_118 ) ;
V_76 -> V_118 = NULL ;
return - V_25 ;
}
T_4
F_97 ( struct V_75 * V_76 )
{
int V_30 = 0 ;
if ( ! ( V_76 -> V_105 & V_205 ) &&
V_76 -> V_166 ) {
V_30 = F_141 ( V_76 ) ;
if ( V_30 < 0 )
return V_104 ;
}
F_61 ( V_76 ) ;
if ( V_76 -> V_135 != V_138 ) {
F_126 ( V_76 ) ;
return 0 ;
}
F_48 ( V_76 , false , true ) ;
V_30 = V_76 -> V_67 -> V_86 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 )
goto V_248;
F_57 ( V_30 ) ;
return ( ! V_30 ) ? 0 : V_104 ;
V_248:
F_27 ( L_118 , V_76 ) ;
V_76 -> V_88 = V_134 ;
F_121 ( V_76 , V_76 -> V_79 ) ;
return 0 ;
}
static void F_68 ( struct V_75 * V_76 )
{
int V_30 ;
V_30 = V_76 -> V_67 -> V_86 ( V_76 ) ;
if ( V_30 == - V_247 || V_30 == - V_25 ) {
F_27 ( L_118 ,
V_76 ) ;
F_121 ( V_76 , V_76 -> V_79 ) ;
}
}
int F_147 ( struct V_75 * V_76 , int V_277 )
{
int V_30 = 0 ;
if ( ! ( V_76 -> V_105 & V_278 ) ) {
if ( V_277 && ( V_76 -> V_105 & V_267 ) )
F_148 ( V_76 ) ;
V_30 = F_135 ( V_76 ) ;
} else {
if ( V_277 )
F_148 ( V_76 ) ;
if ( V_76 -> V_95 )
F_50 ( V_76 ) ;
V_30 = F_53 ( V_76 ) ;
}
return V_30 ;
}
int F_100 ( struct V_2 * V_32 , struct V_75 * V_75 ,
bool V_279 )
{
unsigned long V_56 ;
int V_30 = 0 ;
F_20 ( & V_75 -> V_280 ) ;
if ( V_279 == true ) {
F_23 ( & V_75 -> V_280 ) ;
V_75 -> V_105 |= V_281 ;
}
F_29 ( & V_32 -> V_38 , V_56 ) ;
if ( V_32 -> V_282 ) {
V_30 = - V_283 ;
goto V_3;
}
F_25 ( & V_75 -> V_175 , & V_32 -> V_36 ) ;
V_3:
F_30 ( & V_32 -> V_38 , V_56 ) ;
return V_30 ;
}
static void F_149 ( struct V_58 * V_58 )
{
struct V_75 * V_75 = F_32 ( V_58 , struct V_75 , V_280 ) ;
struct V_2 * V_32 = V_75 -> V_32 ;
if ( F_41 ( & V_75 -> V_175 ) ) {
F_12 ( & V_32 -> V_38 ) ;
V_75 -> V_67 -> V_284 ( V_75 ) ;
return;
}
if ( V_32 -> V_282 && V_75 -> V_285 ) {
F_12 ( & V_32 -> V_38 ) ;
F_37 ( & V_75 -> V_177 ) ;
return;
}
F_40 ( & V_75 -> V_175 ) ;
F_12 ( & V_32 -> V_38 ) ;
V_75 -> V_67 -> V_284 ( V_75 ) ;
}
int F_103 ( struct V_2 * V_32 , struct V_75 * V_75 )
{
return F_150 ( & V_75 -> V_280 , F_149 ,
& V_32 -> V_38 ) ;
}
void F_151 ( struct V_2 * V_32 )
{
struct V_75 * V_75 ;
unsigned long V_56 ;
F_29 ( & V_32 -> V_38 , V_56 ) ;
if ( V_32 -> V_282 ) {
F_30 ( & V_32 -> V_38 , V_56 ) ;
return;
}
V_32 -> V_282 = 1 ;
F_64 ( & V_32 -> V_36 , & V_32 -> V_37 ) ;
F_152 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_75 -> V_285 = 1 ;
F_30 ( & V_32 -> V_38 , V_56 ) ;
}
void F_153 ( struct V_2 * V_32 )
{
struct V_75 * V_75 , * V_286 ;
unsigned long V_56 ;
F_65 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_40 ( & V_75 -> V_175 ) ;
F_27 ( L_119
L_120 , V_75 , V_75 -> V_88 ,
V_75 -> V_67 -> V_230 ( V_75 ) ) ;
F_117 ( & V_75 -> V_177 ) ;
F_27 ( L_121
L_122 , V_75 , V_75 -> V_88 ,
V_75 -> V_67 -> V_230 ( V_75 ) ) ;
V_75 -> V_67 -> V_284 ( V_75 ) ;
}
F_29 ( & V_32 -> V_38 , V_56 ) ;
F_57 ( ! F_41 ( & V_32 -> V_36 ) ) ;
F_30 ( & V_32 -> V_38 , V_56 ) ;
}
static int F_154 ( struct V_75 * V_76 , struct V_95 * V_99 )
{
unsigned long V_56 ;
int V_30 = 0 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( V_76 -> V_80 & V_96 ) {
V_76 -> V_80 &= ~ V_90 ;
F_27 ( L_123 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_48 ( V_76 , false , false ) ;
return - V_287 ;
}
V_76 -> V_80 |= V_288 ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( ( V_76 -> V_80 & V_81 ) &&
( V_76 -> V_80 & V_231 ) ) {
if ( ! F_116 ( V_76 , & V_56 ) )
V_30 ++ ;
}
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_27 ( L_124
L_120 , V_76 , V_30 ) ;
if ( ! V_30 ) {
F_27 ( L_125 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_117 ( & V_76 -> V_94 ) ;
F_27 ( L_126 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
}
return 0 ;
}
static void F_155 ( struct V_95 * V_99 )
{
struct V_75 * V_76 = NULL ;
unsigned long V_289 , V_290 ;
F_29 ( & V_99 -> V_100 , V_289 ) ;
while ( ! F_41 ( & V_99 -> V_291 ) ) {
V_76 = F_156 ( & V_99 -> V_291 ,
struct V_75 , V_101 ) ;
F_51 ( & V_76 -> V_101 ) ;
F_11 ( & V_76 -> V_87 ) ;
F_27 ( L_127
L_128 ,
V_76 -> V_95 -> V_207 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
V_76 -> V_80 |= V_90 ;
F_12 ( & V_76 -> V_87 ) ;
F_30 ( & V_99 -> V_100 , V_289 ) ;
if ( ! V_76 -> V_95 ) {
F_4 ( L_129 ,
V_76 -> V_67 -> V_92 ( V_76 ) ,
V_76 -> V_67 -> V_230 ( V_76 ) , V_76 -> V_88 ) ;
F_157 () ;
}
F_27 ( L_130
L_131 , V_76 -> V_95 -> V_207 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
if ( F_154 ( V_76 , V_76 -> V_95 ) < 0 ) {
F_29 ( & V_99 -> V_100 , V_289 ) ;
continue;
}
F_27 ( L_132
L_133 ,
V_76 -> V_95 -> V_207 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_29 ( & V_76 -> V_87 , V_290 ) ;
if ( ! ( V_76 -> V_80 & V_178 ) ) {
F_30 ( & V_76 -> V_87 , V_290 ) ;
goto V_292;
}
V_76 -> V_80 &= ~ V_178 ;
F_47 ( V_76 ) ;
F_30 ( & V_76 -> V_87 , V_290 ) ;
V_292:
F_102 ( V_76 ,
V_232 , 0 ) ;
F_29 ( & V_76 -> V_87 , V_290 ) ;
if ( V_76 -> V_80 & V_288 ) {
F_27 ( L_134
L_135 ,
V_99 -> V_207 ,
V_76 , V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 ,
V_290 ) ;
F_48 ( V_76 , false , false ) ;
F_37 ( & V_76 -> V_176 ) ;
F_29 ( & V_99 -> V_100 , V_289 ) ;
continue;
}
F_27 ( L_136 ,
V_99 -> V_207 , V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 , V_290 ) ;
F_29 ( & V_99 -> V_100 , V_289 ) ;
}
F_30 ( & V_99 -> V_100 , V_289 ) ;
}
static int F_158 ( void * V_293 )
{
struct V_95 * V_99 = V_293 ;
F_155 ( V_99 ) ;
F_37 ( & V_99 -> V_294 ) ;
return 0 ;
}
int F_159 ( struct V_95 * V_99 )
{
struct V_295 * V_296 ;
V_296 = F_160 ( F_158 , V_99 ,
L_137 , V_99 -> V_207 ) ;
if ( F_161 ( V_296 ) ) {
F_4 ( L_138 ) ;
return F_162 ( V_296 ) ;
}
F_117 ( & V_99 -> V_294 ) ;
return 0 ;
}
bool F_148 ( struct V_75 * V_76 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( ! ( V_76 -> V_105 & V_278 ) &&
! ( V_76 -> V_105 & V_267 ) ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return false ;
}
if ( ! ( V_76 -> V_105 & V_191 ) &&
! ( V_76 -> V_105 & V_267 ) ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return false ;
}
if ( V_76 -> V_80 & V_90 ) {
F_27 ( L_139
L_140
L_141 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_37 ( & V_76 -> V_94 ) ;
F_117 ( & V_76 -> V_176 ) ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
F_47 ( V_76 ) ;
F_27 ( L_142
L_143
L_144 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
V_76 -> V_80 &= ~ V_90 ;
}
if ( ! ( V_76 -> V_80 & V_93 ) ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return false ;
}
V_76 -> V_80 |= V_96 ;
F_27 ( L_145
L_146 ,
V_76 , V_76 -> V_67 -> V_92 ( V_76 ) ,
V_76 -> V_67 -> V_230 ( V_76 ) , V_76 -> V_88 ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
F_117 ( & V_76 -> V_97 ) ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
V_76 -> V_80 &= ~ ( V_93 | V_96 ) ;
F_27 ( L_147
L_148 ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
return true ;
}
static int F_163 (
struct V_75 * V_76 ,
T_3 * V_297 ,
T_3 * V_298 )
{
* V_297 = V_76 -> V_299 ;
* V_298 = V_76 -> V_300 ;
return 0 ;
}
int
F_102 ( struct V_75 * V_76 ,
T_4 V_301 , int V_302 )
{
unsigned char * V_303 = V_76 -> V_114 ;
unsigned long V_56 ;
T_3 V_297 = 0 , V_298 = 0 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( V_76 -> V_105 & V_106 ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return 0 ;
}
V_76 -> V_105 |= V_106 ;
F_30 ( & V_76 -> V_87 , V_56 ) ;
if ( ! V_301 && V_302 )
goto V_304;
if ( ! V_302 )
V_76 -> V_105 |= V_305 ;
switch ( V_301 ) {
case V_306 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_309 ;
V_303 [ V_310 ] = 0 ;
V_303 [ V_311 ] = 0 ;
break;
case V_232 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x25 ;
break;
case V_233 :
case V_313 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x20 ;
break;
case V_236 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x24 ;
break;
case V_239 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_314 ;
V_303 [ V_310 ] = 0x29 ;
V_303 [ V_311 ] = 0x03 ;
break;
case V_315 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_314 ;
V_303 [ V_310 ] = 0x0c ;
V_303 [ V_311 ] = 0x0d ;
break;
case V_168 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x24 ;
break;
case V_234 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x26 ;
break;
case V_235 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x1a ;
break;
case V_316 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_314 ;
V_303 [ V_310 ] = 0x0c ;
V_303 [ V_311 ] = 0x0c ;
break;
case V_317 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_314 ;
V_303 [ V_310 ] = 0x47 ;
V_303 [ V_311 ] = 0x05 ;
break;
case V_318 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_314 ;
V_303 [ V_310 ] = 0x11 ;
V_303 [ V_311 ] = 0x13 ;
break;
case V_237 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_319 ;
V_303 [ V_310 ] = 0x27 ;
break;
case V_238 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_312 ;
V_303 [ V_310 ] = 0x21 ;
break;
case V_240 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_320 ;
F_164 ( V_76 , & V_297 , & V_298 ) ;
V_303 [ V_310 ] = V_297 ;
V_303 [ V_311 ] = V_298 ;
break;
case V_241 :
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_309 ;
F_163 ( V_76 , & V_297 , & V_298 ) ;
V_303 [ V_310 ] = V_297 ;
V_303 [ V_311 ] = V_298 ;
break;
case V_104 :
default:
V_303 [ 0 ] = 0x70 ;
V_303 [ V_307 ] = 10 ;
V_303 [ V_308 ] = V_309 ;
V_303 [ V_310 ] = 0x08 ;
break;
}
V_76 -> V_113 = V_321 ;
V_76 -> V_107 = V_108 ;
V_304:
F_120 ( V_76 ) ;
return V_76 -> V_67 -> V_246 ( V_76 ) ;
}
int F_127 ( struct V_75 * V_76 , int V_322 )
{
if ( ! ( V_76 -> V_80 & V_123 ) )
return 0 ;
if ( ! V_322 || ( V_76 -> V_105 & V_323 ) )
return 1 ;
F_27 ( L_149 ,
V_76 -> V_167 [ 0 ] , V_76 -> V_67 -> V_92 ( V_76 ) ) ;
V_76 -> V_105 |= V_323 ;
F_120 ( V_76 ) ;
V_76 -> V_67 -> V_246 ( V_76 ) ;
return 1 ;
}
void F_165 ( struct V_75 * V_76 )
{
unsigned long V_56 ;
F_29 ( & V_76 -> V_87 , V_56 ) ;
if ( V_76 -> V_105 & ( V_106 | V_323 ) ) {
F_30 ( & V_76 -> V_87 , V_56 ) ;
return;
}
F_30 ( & V_76 -> V_87 , V_56 ) ;
if ( V_76 -> V_135 == V_138 ) {
if ( V_76 -> V_67 -> V_324 ( V_76 ) != 0 ) {
V_76 -> V_80 |= V_123 ;
F_86 () ;
}
}
V_76 -> V_113 = V_325 ;
F_50 ( V_76 ) ;
F_27 ( L_150
L_151 , V_76 -> V_167 [ 0 ] ,
V_76 -> V_67 -> V_92 ( V_76 ) ) ;
F_120 ( V_76 ) ;
V_76 -> V_67 -> V_246 ( V_76 ) ;
}
static void F_166 ( struct V_102 * V_103 )
{
struct V_75 * V_76 = F_32 ( V_103 , struct V_75 , V_103 ) ;
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_217 * V_326 = V_76 -> V_217 ;
int V_30 ;
switch ( V_326 -> V_327 ) {
case V_226 :
F_167 ( V_78 , V_326 , V_76 -> V_32 ) ;
break;
case V_328 :
case V_329 :
case V_330 :
V_326 -> V_218 = V_331 ;
break;
case V_332 :
V_30 = F_168 ( V_78 , V_326 , NULL , NULL ) ;
V_326 -> V_218 = ( ! V_30 ) ? V_333 :
V_334 ;
break;
case V_335 :
V_326 -> V_218 = V_334 ;
break;
case V_336 :
V_326 -> V_218 = V_334 ;
break;
default:
F_4 ( L_152 ,
V_326 -> V_327 ) ;
V_326 -> V_218 = V_334 ;
break;
}
V_76 -> V_88 = V_337 ;
V_76 -> V_67 -> V_220 ( V_76 ) ;
F_49 ( V_76 ) ;
}
int F_115 (
struct V_75 * V_76 )
{
F_59 ( & V_76 -> V_103 , F_166 ) ;
F_60 ( V_76 -> V_79 -> V_338 , & V_76 -> V_103 ) ;
return 0 ;
}
