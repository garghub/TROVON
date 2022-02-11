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
V_22 = F_2 (
L_17 ,
sizeof( struct V_23 ) ,
F_3 ( struct V_23 ) , 0 , NULL ) ;
if ( ! V_22 ) {
F_4 ( L_18
L_12 ) ;
goto V_24;
}
V_25 = F_2 (
L_19 ,
sizeof( struct V_26 ) ,
F_3 ( struct V_26 ) , 0 , NULL ) ;
if ( ! V_25 ) {
F_4 ( L_20
L_12 ) ;
goto V_27;
}
V_28 = F_5 ( L_21 ,
V_29 , 0 ) ;
if ( ! V_28 )
goto V_30;
return 0 ;
V_30:
F_6 ( V_25 ) ;
V_27:
F_6 ( V_22 ) ;
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
return - V_31 ;
}
void F_7 ( void )
{
F_8 ( V_28 ) ;
F_6 ( V_1 ) ;
F_6 ( V_4 ) ;
F_6 ( V_7 ) ;
F_6 ( V_10 ) ;
F_6 ( V_13 ) ;
F_6 ( V_16 ) ;
F_6 ( V_19 ) ;
F_6 ( V_22 ) ;
F_6 ( V_25 ) ;
}
T_1 F_9 ( T_2 type )
{
T_1 V_32 ;
F_10 ( ( type < 0 ) || ( type >= V_33 ) ) ;
F_11 ( & V_34 ) ;
V_32 = ++ V_35 [ type ] ;
F_12 ( & V_34 ) ;
return V_32 ;
}
void F_13 ( void )
{
int V_36 ;
static int V_37 ;
if ( V_37 )
return;
V_36 = F_14 ( L_22 ) ;
if ( V_36 != 0 )
F_4 ( L_23 ) ;
V_36 = F_14 ( L_24 ) ;
if ( V_36 != 0 )
F_4 ( L_25 ) ;
V_36 = F_14 ( L_26 ) ;
if ( V_36 != 0 )
F_4 ( L_27 ) ;
V_37 = 1 ;
}
struct V_2 * F_15 ( void )
{
struct V_2 * V_38 ;
V_38 = F_16 ( V_1 , V_39 ) ;
if ( ! V_38 ) {
F_4 ( L_28
L_29 ) ;
return F_17 ( - V_31 ) ;
}
F_18 ( & V_38 -> V_40 ) ;
F_18 ( & V_38 -> V_41 ) ;
F_18 ( & V_38 -> V_42 ) ;
F_18 ( & V_38 -> V_43 ) ;
F_19 ( & V_38 -> V_44 ) ;
F_20 ( & V_38 -> V_45 ) ;
return V_38 ;
}
int F_21 ( struct V_2 * V_38 ,
unsigned int V_46 , unsigned int V_47 )
{
int V_48 ;
V_38 -> V_49 = F_22 ( V_46 * V_47 ,
V_39 | V_50 | V_51 ) ;
if ( ! V_38 -> V_49 ) {
V_38 -> V_49 = F_23 ( V_46 * V_47 ) ;
if ( ! V_38 -> V_49 ) {
F_4 ( L_30 ) ;
return - V_31 ;
}
}
V_48 = F_24 ( & V_38 -> V_52 , V_46 ) ;
if ( V_48 < 0 ) {
F_4 ( L_31
L_32 , V_46 ) ;
if ( F_25 ( V_38 -> V_49 ) )
F_26 ( V_38 -> V_49 ) ;
else
F_27 ( V_38 -> V_49 ) ;
V_38 -> V_49 = NULL ;
return - V_31 ;
}
return 0 ;
}
struct V_2 * F_28 ( unsigned int V_46 ,
unsigned int V_47 )
{
struct V_2 * V_38 ;
int V_48 ;
V_38 = F_15 () ;
if ( F_29 ( V_38 ) )
return V_38 ;
V_48 = F_21 ( V_38 , V_46 , V_47 ) ;
if ( V_48 < 0 ) {
F_30 ( V_38 ) ;
return F_17 ( - V_31 ) ;
}
return V_38 ;
}
void F_31 (
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_2 * V_38 ,
void * V_57 )
{
unsigned char V_58 [ V_59 ] ;
V_38 -> V_54 = V_54 ;
V_38 -> V_57 = V_57 ;
if ( V_56 ) {
if ( V_54 -> V_60 -> V_61 != NULL ) {
memset ( & V_58 [ 0 ] , 0 , V_59 ) ;
V_54 -> V_60 -> V_61 ( V_38 ,
& V_58 [ 0 ] , V_59 ) ;
V_38 -> V_62 = F_32 ( & V_58 [ 0 ] ) ;
}
F_33 ( & V_56 -> V_63 ) ;
F_34 ( & V_56 -> V_64 ) ;
V_56 -> V_65 = V_38 ;
F_35 ( & V_38 -> V_41 ,
& V_56 -> V_66 ) ;
F_36 ( & V_56 -> V_64 ) ;
}
F_35 ( & V_38 -> V_40 , & V_54 -> V_67 ) ;
F_37 ( L_33 ,
V_54 -> V_60 -> V_68 () , V_38 -> V_57 ) ;
}
void F_38 (
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_2 * V_38 ,
void * V_57 )
{
unsigned long V_69 ;
F_39 ( & V_54 -> V_70 , V_69 ) ;
F_31 ( V_54 , V_56 , V_38 , V_57 ) ;
F_40 ( & V_54 -> V_70 , V_69 ) ;
}
static void F_41 ( struct V_71 * V_71 )
{
struct V_2 * V_38 = F_42 ( V_71 ,
struct V_2 , V_45 ) ;
struct V_53 * V_54 = V_38 -> V_54 ;
V_54 -> V_60 -> V_72 ( V_38 ) ;
}
void F_43 ( struct V_2 * V_38 )
{
F_33 ( & V_38 -> V_45 ) ;
}
void F_44 ( struct V_2 * V_38 )
{
struct V_53 * V_73 = V_38 -> V_54 ;
if ( V_73 -> V_60 -> V_74 != NULL ) {
V_73 -> V_60 -> V_74 ( V_38 ) ;
return;
}
F_45 ( & V_38 -> V_45 , F_41 ) ;
}
static void F_46 ( struct V_71 * V_71 )
{
struct V_55 * V_75 = F_42 ( V_71 ,
struct V_55 , V_63 ) ;
F_47 ( & V_75 -> V_76 ) ;
}
void F_48 ( struct V_55 * V_75 )
{
F_45 ( & V_75 -> V_63 , F_46 ) ;
}
void F_49 ( struct V_2 * V_38 )
{
struct V_55 * V_56 ;
unsigned long V_69 ;
V_56 = V_38 -> V_55 ;
if ( V_56 ) {
F_39 ( & V_56 -> V_64 , V_69 ) ;
if ( V_56 -> V_77 == 0 )
F_50 ( & V_38 -> V_41 ) ;
if ( F_51 ( & V_56 -> V_66 ) )
V_56 -> V_65 = NULL ;
else {
V_56 -> V_65 = F_42 (
V_56 -> V_66 . V_78 ,
struct V_2 , V_41 ) ;
}
F_40 ( & V_56 -> V_64 , V_69 ) ;
}
}
void F_30 ( struct V_2 * V_38 )
{
if ( V_38 -> V_49 ) {
F_52 ( & V_38 -> V_52 ) ;
if ( F_25 ( V_38 -> V_49 ) )
F_26 ( V_38 -> V_49 ) ;
else
F_27 ( V_38 -> V_49 ) ;
}
F_53 ( V_1 , V_38 ) ;
}
void F_54 ( struct V_2 * V_38 )
{
struct V_53 * V_54 = V_38 -> V_54 ;
struct V_79 * V_80 ;
struct V_55 * V_56 ;
unsigned long V_69 ;
bool V_81 = true ;
if ( ! V_54 ) {
F_30 ( V_38 ) ;
return;
}
V_80 = V_54 -> V_60 ;
F_39 ( & V_54 -> V_70 , V_69 ) ;
F_50 ( & V_38 -> V_40 ) ;
V_38 -> V_54 = NULL ;
V_38 -> V_57 = NULL ;
F_40 ( & V_54 -> V_70 , V_69 ) ;
V_56 = V_38 -> V_55 ;
F_39 ( & V_54 -> V_82 , V_69 ) ;
if ( V_56 && V_56 -> V_83 ) {
if ( ! V_80 -> V_84 ( V_54 ) ) {
F_50 ( & V_56 -> V_85 ) ;
V_54 -> V_86 -- ;
F_40 ( & V_54 -> V_82 , V_69 ) ;
F_55 ( V_56 ) ;
F_56 ( V_56 , V_54 ) ;
V_80 -> V_87 ( V_54 , V_56 ) ;
V_81 = false ;
F_39 ( & V_54 -> V_82 , V_69 ) ;
}
}
F_40 ( & V_54 -> V_82 , V_69 ) ;
F_37 ( L_34 ,
V_54 -> V_60 -> V_68 () ) ;
if ( V_56 && V_81 == true )
F_48 ( V_56 ) ;
F_30 ( V_38 ) ;
}
static void F_57 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
unsigned long V_69 ;
if ( ! V_91 )
return;
if ( V_89 -> V_93 & V_94 )
return;
F_39 ( & V_91 -> V_95 , V_69 ) ;
if ( V_89 -> V_96 ) {
F_50 ( & V_89 -> V_97 ) ;
V_89 -> V_96 = false ;
}
F_40 ( & V_91 -> V_95 , V_69 ) ;
}
static int F_58 ( struct V_88 * V_89 , bool V_98 ,
bool V_99 )
{
unsigned long V_69 ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
if ( V_99 )
V_89 -> V_101 = V_102 ;
if ( V_98 ) {
F_57 ( V_89 ) ;
V_89 -> V_103 = NULL ;
}
if ( V_89 -> V_93 & V_104 ) {
F_37 ( L_35 ,
V_105 , __LINE__ ,
V_89 -> V_80 -> V_106 ( V_89 ) ) ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
F_47 ( & V_89 -> V_107 ) ;
return 1 ;
}
V_89 -> V_93 &= ~ V_108 ;
if ( V_98 ) {
if ( V_89 -> V_80 -> V_109 != NULL ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return V_89 -> V_80 -> V_109 ( V_89 ) ;
}
}
F_40 ( & V_89 -> V_100 , V_69 ) ;
return 0 ;
}
static int F_59 ( struct V_88 * V_89 )
{
return F_58 ( V_89 , true , false ) ;
}
static void F_60 ( struct V_88 * V_89 )
{
struct V_103 * V_110 = V_89 -> V_103 ;
if ( ! V_110 )
return;
if ( F_61 ( & V_89 -> V_111 , true , false ) )
F_62 ( & V_110 -> V_112 ) ;
}
void F_63 ( struct V_88 * V_89 , int remove )
{
if ( F_59 ( V_89 ) )
return;
if ( remove )
F_64 ( V_89 ) ;
}
static void F_65 ( struct V_113 * V_114 )
{
struct V_88 * V_89 = F_42 ( V_114 , struct V_88 , V_114 ) ;
F_66 ( V_89 ,
V_115 ) ;
}
static unsigned char * F_67 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
F_68 ( ! V_89 -> V_103 ) ;
if ( ! V_91 )
return NULL ;
if ( V_89 -> V_116 & V_117 )
return NULL ;
V_89 -> V_118 = V_119 ;
F_37 ( L_36 ,
V_91 -> V_120 -> V_121 , V_91 -> V_122 -> V_123 , V_89 -> V_124 ) ;
return V_89 -> V_125 ;
}
void F_69 ( struct V_88 * V_89 , T_3 V_124 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
int V_126 = V_124 == V_127 ;
unsigned long V_69 ;
V_89 -> V_124 = V_124 ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
V_89 -> V_93 &= ~ V_94 ;
if ( V_91 && V_91 -> V_122 -> V_128 ) {
V_91 -> V_122 -> V_128 ( V_89 ,
V_89 -> V_129 ,
F_67 ( V_89 ) ) ;
if ( V_89 -> V_116 & V_130 )
V_126 = 1 ;
}
if ( V_89 -> V_93 & V_131 ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
F_47 ( & V_89 -> V_132 ) ;
return;
}
if ( V_89 -> V_93 & V_133 &&
V_89 -> V_93 & V_104 ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
F_47 ( & V_89 -> V_107 ) ;
return;
} else if ( ! V_126 ) {
F_70 ( & V_89 -> V_114 , F_65 ) ;
} else {
F_70 ( & V_89 -> V_114 , V_134 ) ;
}
V_89 -> V_101 = V_135 ;
V_89 -> V_93 |= ( V_136 | V_108 ) ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
F_71 ( V_28 , & V_89 -> V_114 ) ;
}
static void F_72 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
unsigned long V_69 ;
F_39 ( & V_91 -> V_95 , V_69 ) ;
if ( ! V_89 -> V_96 ) {
F_35 ( & V_89 -> V_97 , & V_91 -> V_97 ) ;
V_89 -> V_96 = true ;
}
F_40 ( & V_91 -> V_95 , V_69 ) ;
}
void F_73 ( struct V_113 * V_114 )
{
struct V_90 * V_91 = F_42 ( V_114 , struct V_90 ,
V_137 ) ;
F_74 ( V_138 ) ;
struct V_88 * V_89 , * V_139 ;
F_34 ( & V_91 -> V_140 ) ;
F_75 ( & V_91 -> V_138 , & V_138 ) ;
F_36 ( & V_91 -> V_140 ) ;
F_76 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_50 ( & V_89 -> V_141 ) ;
F_77 ( & V_91 -> V_142 ) ;
F_78 () ;
F_37 ( L_37
L_38 , V_89 -> V_80 -> V_68 () , V_89 ,
( V_89 -> V_101 == V_143 ) ? L_39 :
( V_89 -> V_101 == V_144 ) ? L_40
: L_41 ) ;
if ( V_89 -> V_101 == V_144 )
F_79 ( V_89 ) ;
else if ( V_89 -> V_101 == V_143 )
F_80 ( V_89 ) ;
}
}
unsigned char * F_81 ( struct V_88 * V_89 )
{
switch ( V_89 -> V_145 ) {
case V_146 :
return L_42 ;
case V_147 :
return L_43 ;
case V_148 :
return L_44 ;
case V_149 :
return L_45 ;
default:
break;
}
return L_41 ;
}
void F_82 (
struct V_90 * V_91 ,
char * V_150 ,
int * V_151 )
{
* V_151 += sprintf ( V_150 + * V_151 , L_46 ) ;
if ( V_91 -> V_152 )
* V_151 += sprintf ( V_150 + * V_151 , L_47 ) ;
else
* V_151 += sprintf ( V_150 + * V_151 , L_48 ) ;
* V_151 += sprintf ( V_150 + * V_151 , L_49 , V_91 -> V_153 ) ;
* V_151 += sprintf ( V_150 + * V_151 , L_50 ,
V_91 -> V_154 . V_155 ,
V_91 -> V_154 . V_156 ) ;
* V_151 += sprintf ( V_150 + * V_151 , L_51 ) ;
}
void F_83 (
struct V_157 * V_158 ,
unsigned char * V_159 ,
int V_160 )
{
unsigned char V_58 [ V_161 ] ;
int V_162 ;
memset ( V_58 , 0 , V_161 ) ;
V_162 = sprintf ( V_58 , L_52 ) ;
switch ( V_158 -> V_163 ) {
case 0x00 :
sprintf ( V_58 + V_162 , L_53 ) ;
break;
case 0x10 :
sprintf ( V_58 + V_162 , L_54 ) ;
break;
case 0x20 :
sprintf ( V_58 + V_162 , L_55 ) ;
break;
case 0x30 :
sprintf ( V_58 + V_162 , L_56 ) ;
break;
case 0x40 :
sprintf ( V_58 + V_162 , L_57
L_58 ) ;
break;
case 0x50 :
sprintf ( V_58 + V_162 , L_59 ) ;
break;
case 0x60 :
sprintf ( V_58 + V_162 , L_60 ) ;
break;
case 0x70 :
sprintf ( V_58 + V_162 , L_61
L_58 ) ;
break;
case 0x80 :
sprintf ( V_58 + V_162 , L_62 ) ;
break;
default:
sprintf ( V_58 + V_162 , L_63 ,
V_158 -> V_163 ) ;
break;
}
if ( V_159 )
strncpy ( V_159 , V_58 , V_160 ) ;
else
F_37 ( L_64 , V_58 ) ;
}
void
F_84 ( struct V_157 * V_158 , unsigned char * V_164 )
{
if ( V_164 [ 1 ] & 0x80 ) {
V_158 -> V_163 = ( V_164 [ 0 ] & 0xf0 ) ;
V_158 -> V_165 = 1 ;
F_83 ( V_158 , NULL , 0 ) ;
}
}
int F_85 (
struct V_157 * V_158 ,
unsigned char * V_159 ,
int V_160 )
{
unsigned char V_58 [ V_161 ] ;
int V_36 = 0 ;
int V_162 ;
memset ( V_58 , 0 , V_161 ) ;
V_162 = sprintf ( V_58 , L_65 ) ;
switch ( V_158 -> V_166 ) {
case 0x00 :
sprintf ( V_58 + V_162 , L_66 ) ;
break;
case 0x10 :
sprintf ( V_58 + V_162 , L_67 ) ;
break;
case 0x20 :
sprintf ( V_58 + V_162 , L_68 ) ;
break;
default:
sprintf ( V_58 + V_162 , L_63 , V_158 -> V_166 ) ;
V_36 = - V_167 ;
break;
}
if ( V_159 )
strncpy ( V_159 , V_58 , V_160 ) ;
else
F_37 ( L_64 , V_58 ) ;
return V_36 ;
}
int F_86 ( struct V_157 * V_158 , unsigned char * V_164 )
{
V_158 -> V_166 = ( V_164 [ 1 ] & 0x30 ) ;
return F_85 ( V_158 , NULL , 0 ) ;
}
int F_87 (
struct V_157 * V_158 ,
unsigned char * V_159 ,
int V_160 )
{
unsigned char V_58 [ V_161 ] ;
int V_36 = 0 ;
int V_162 ;
memset ( V_58 , 0 , V_161 ) ;
V_162 = sprintf ( V_58 , L_69 ) ;
switch ( V_158 -> V_168 ) {
case 0x00 :
sprintf ( V_58 + V_162 , L_70 ) ;
break;
case 0x01 :
sprintf ( V_58 + V_162 , L_71 ) ;
break;
case 0x02 :
sprintf ( V_58 + V_162 , L_72 ) ;
break;
case 0x03 :
sprintf ( V_58 + V_162 , L_73 ) ;
break;
case 0x04 :
sprintf ( V_58 + V_162 , L_74 ) ;
break;
case 0x08 :
sprintf ( V_58 + V_162 , L_75 ) ;
break;
default:
sprintf ( V_58 + V_162 , L_76 ,
V_158 -> V_168 ) ;
V_36 = - V_167 ;
break;
}
if ( V_159 ) {
if ( V_160 < strlen ( V_58 ) + 1 )
return - V_167 ;
strncpy ( V_159 , V_58 , V_160 ) ;
} else {
F_37 ( L_64 , V_58 ) ;
}
return V_36 ;
}
int F_88 ( struct V_157 * V_158 , unsigned char * V_164 )
{
V_158 -> V_168 = ( V_164 [ 1 ] & 0x0f ) ;
return F_87 ( V_158 , NULL , 0 ) ;
}
int F_89 (
struct V_157 * V_158 ,
unsigned char * V_159 ,
int V_160 )
{
unsigned char V_58 [ V_161 ] ;
int V_36 = 0 ;
memset ( V_58 , 0 , V_161 ) ;
switch ( V_158 -> V_169 ) {
case 0x01 :
snprintf ( V_58 , sizeof( V_58 ) ,
L_77 ,
& V_158 -> V_170 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_58 , sizeof( V_58 ) ,
L_78 ,
& V_158 -> V_170 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_58 , sizeof( V_58 ) ,
L_79 ,
& V_158 -> V_170 [ 0 ] ) ;
break;
default:
sprintf ( V_58 , L_80
L_81 , V_158 -> V_169 ) ;
V_36 = - V_167 ;
break;
}
if ( V_159 )
strncpy ( V_159 , V_58 , V_160 ) ;
else
F_37 ( L_64 , V_58 ) ;
return V_36 ;
}
int
F_90 ( struct V_157 * V_158 , unsigned char * V_164 )
{
static const char V_171 [] = L_82 ;
int V_172 = 0 , V_173 = 4 ;
V_158 -> V_169 = ( V_164 [ 0 ] & 0x0f ) ;
switch ( V_158 -> V_169 ) {
case 0x01 :
V_158 -> V_170 [ V_172 ++ ] =
V_171 [ V_158 -> V_168 ] ;
while ( V_173 < ( 4 + V_164 [ 3 ] ) ) {
V_158 -> V_170 [ V_172 ++ ] =
V_171 [ ( V_164 [ V_173 ] & 0xf0 ) >> 4 ] ;
V_158 -> V_170 [ V_172 ++ ] =
V_171 [ V_164 [ V_173 ] & 0x0f ] ;
V_173 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_173 < ( 4 + V_164 [ 3 ] ) )
V_158 -> V_170 [ V_172 ++ ] = V_164 [ V_173 ++ ] ;
break;
default:
break;
}
return F_89 ( V_158 , NULL , 0 ) ;
}
T_4
F_91 ( struct V_88 * V_89 , unsigned int V_174 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
if ( V_89 -> V_175 ) {
V_89 -> V_176 = V_174 ;
} else if ( V_174 != V_89 -> V_176 ) {
F_92 ( L_83
L_84
L_85 , V_89 -> V_80 -> V_68 () ,
V_89 -> V_176 , V_174 , V_89 -> V_177 [ 0 ] ) ;
if ( V_89 -> V_145 == V_148 ) {
F_4 ( L_86
L_87 ) ;
return V_178 ;
}
if ( V_91 -> V_154 . V_155 != 512 ) {
F_4 ( L_88
L_89
L_90 , V_91 -> V_122 -> V_123 ) ;
return V_178 ;
}
if ( V_174 > V_89 -> V_176 ) {
V_89 -> V_116 |= V_179 ;
V_89 -> V_180 = ( V_174 - V_89 -> V_176 ) ;
} else {
V_89 -> V_116 |= V_181 ;
V_89 -> V_180 = ( V_89 -> V_176 - V_174 ) ;
V_89 -> V_176 = V_174 ;
}
}
return 0 ;
}
void F_93 (
struct V_88 * V_89 ,
struct V_79 * V_182 ,
struct V_2 * V_38 ,
T_1 V_176 ,
int V_145 ,
int V_183 ,
unsigned char * V_125 )
{
F_18 ( & V_89 -> V_184 ) ;
F_18 ( & V_89 -> V_141 ) ;
F_18 ( & V_89 -> V_185 ) ;
F_18 ( & V_89 -> V_97 ) ;
F_94 ( & V_89 -> V_107 ) ;
F_94 ( & V_89 -> V_186 ) ;
F_94 ( & V_89 -> V_132 ) ;
F_19 ( & V_89 -> V_100 ) ;
V_89 -> V_93 = V_187 ;
V_89 -> V_80 = V_182 ;
V_89 -> V_38 = V_38 ;
V_89 -> V_176 = V_176 ;
V_89 -> V_145 = V_145 ;
V_89 -> V_188 = V_183 ;
V_89 -> V_125 = V_125 ;
V_89 -> V_96 = false ;
}
static T_4
F_95 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
if ( V_91 -> V_122 -> V_189 == V_190 )
return 0 ;
if ( V_89 -> V_188 == V_191 ) {
F_37 ( L_91
L_92 ) ;
return V_178 ;
}
V_89 -> V_192 = F_96 ( & V_91 -> V_193 ) ;
F_97 () ;
F_37 ( L_93 ,
V_89 -> V_192 , V_89 -> V_188 ,
V_91 -> V_122 -> V_123 ) ;
return 0 ;
}
T_4
F_98 ( struct V_88 * V_89 , unsigned char * V_194 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
T_4 V_36 ;
if ( F_99 ( V_194 ) > V_195 ) {
F_4 ( L_94
L_95 ,
F_99 ( V_194 ) , V_195 ) ;
return V_178 ;
}
if ( F_99 ( V_194 ) > sizeof( V_89 -> V_196 ) ) {
V_89 -> V_177 = F_22 ( F_99 ( V_194 ) ,
V_39 ) ;
if ( ! V_89 -> V_177 ) {
F_4 ( L_96
L_97 ,
F_99 ( V_194 ) ,
( unsigned long ) sizeof( V_89 -> V_196 ) ) ;
return V_197 ;
}
} else
V_89 -> V_177 = & V_89 -> V_196 [ 0 ] ;
memcpy ( V_89 -> V_177 , V_194 , F_99 ( V_194 ) ) ;
F_100 ( V_89 ) ;
V_36 = F_101 ( V_89 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_102 ( V_89 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_103 ( V_89 ) ;
if ( V_36 ) {
V_89 -> V_124 = V_198 ;
return V_36 ;
}
V_36 = V_91 -> V_122 -> V_199 ( V_89 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_95 ( V_89 ) ;
if ( V_36 )
return V_36 ;
V_89 -> V_116 |= V_200 ;
F_11 ( & V_89 -> V_103 -> V_201 ) ;
if ( V_89 -> V_103 -> V_202 )
V_89 -> V_103 -> V_202 -> V_203 . V_204 ++ ;
F_12 ( & V_89 -> V_103 -> V_201 ) ;
return 0 ;
}
int F_104 (
struct V_88 * V_89 )
{
T_4 V_36 ;
if ( ! V_89 -> V_103 ) {
F_105 () ;
F_4 ( L_98 ) ;
return - V_167 ;
}
if ( F_106 () ) {
F_105 () ;
F_4 ( L_99
L_100 ) ;
return - V_167 ;
}
V_89 -> V_101 = V_205 ;
V_89 -> V_93 |= V_108 ;
V_36 = F_107 ( V_89 ) ;
if ( V_36 )
F_66 ( V_89 , V_36 ) ;
return 0 ;
}
T_4
F_108 ( struct V_88 * V_89 , struct V_206 * V_207 ,
T_1 V_208 , struct V_206 * V_209 , T_1 V_210 )
{
if ( ! V_207 || ! V_208 )
return 0 ;
if ( V_89 -> V_116 & V_179 ) {
F_92 ( L_101
L_102 ) ;
return V_178 ;
}
V_89 -> V_129 = V_207 ;
V_89 -> V_211 = V_208 ;
if ( V_209 && V_210 ) {
V_89 -> V_212 = V_209 ;
V_89 -> V_213 = V_210 ;
}
V_89 -> V_116 |= V_214 ;
return 0 ;
}
int F_109 ( struct V_88 * V_88 , struct V_2 * V_38 ,
unsigned char * V_194 , unsigned char * V_215 , T_1 V_216 ,
T_1 V_176 , int V_183 , int V_217 , int V_69 ,
struct V_206 * V_207 , T_1 V_208 ,
struct V_206 * V_209 , T_1 V_210 ,
struct V_206 * V_218 , T_1 V_219 )
{
struct V_53 * V_54 ;
T_4 V_48 ;
int V_36 ;
V_54 = V_38 -> V_54 ;
F_10 ( ! V_54 ) ;
F_10 ( V_88 -> V_80 || V_88 -> V_38 ) ;
F_10 ( F_106 () ) ;
F_93 ( V_88 , V_54 -> V_60 , V_38 ,
V_176 , V_217 , V_183 , V_215 ) ;
if ( V_69 & V_220 )
V_88 -> V_175 = 1 ;
V_36 = F_110 ( V_38 , V_88 , ( V_69 & V_221 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_69 & V_222 )
V_88 -> V_116 |= V_223 ;
V_48 = F_111 ( V_88 , V_216 ) ;
if ( V_48 ) {
F_112 ( V_88 , V_48 , 0 ) ;
F_113 ( V_38 , V_88 ) ;
return 0 ;
}
if ( V_219 ) {
V_88 -> V_224 = V_218 ;
V_88 -> V_225 = V_219 ;
}
V_48 = F_98 ( V_88 , V_194 ) ;
if ( V_48 != 0 ) {
F_66 ( V_88 , V_48 ) ;
return 0 ;
}
if ( V_208 != 0 ) {
F_10 ( ! V_207 ) ;
if ( ! ( V_88 -> V_116 & V_226 ) &&
V_88 -> V_145 == V_147 ) {
unsigned char * V_58 = NULL ;
if ( V_207 )
V_58 = F_114 ( F_115 ( V_207 ) ) + V_207 -> V_227 ;
if ( V_58 ) {
memset ( V_58 , 0 , V_207 -> V_228 ) ;
F_116 ( F_115 ( V_207 ) ) ;
}
}
V_48 = F_108 ( V_88 , V_207 , V_208 ,
V_209 , V_210 ) ;
if ( V_48 != 0 ) {
F_66 ( V_88 , V_48 ) ;
return 0 ;
}
}
F_117 ( V_88 ) ;
F_104 ( V_88 ) ;
return 0 ;
}
int F_118 ( struct V_88 * V_88 , struct V_2 * V_38 ,
unsigned char * V_194 , unsigned char * V_215 , T_1 V_216 ,
T_1 V_176 , int V_183 , int V_217 , int V_69 )
{
return F_109 ( V_88 , V_38 , V_194 , V_215 ,
V_216 , V_176 , V_183 , V_217 ,
V_69 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_119 ( struct V_113 * V_114 )
{
struct V_88 * V_88 = F_42 ( V_114 , struct V_88 , V_114 ) ;
V_88 -> V_229 -> V_230 = V_231 ;
V_88 -> V_80 -> V_232 ( V_88 ) ;
F_59 ( V_88 ) ;
}
int F_120 ( struct V_88 * V_88 , struct V_2 * V_38 ,
unsigned char * V_215 , T_1 V_216 ,
void * V_233 , unsigned char V_234 ,
T_5 V_235 , unsigned int V_236 , int V_69 )
{
struct V_53 * V_54 ;
int V_36 ;
V_54 = V_38 -> V_54 ;
F_10 ( ! V_54 ) ;
F_93 ( V_88 , V_54 -> V_60 , V_38 ,
0 , V_146 , V_237 , V_215 ) ;
V_36 = F_121 ( V_88 , V_233 , V_234 , V_235 ) ;
if ( V_36 < 0 )
return - V_31 ;
if ( V_234 == V_238 )
V_88 -> V_229 -> V_239 = V_236 ;
V_36 = F_110 ( V_38 , V_88 , ( V_69 & V_221 ) ) ;
if ( V_36 ) {
F_122 ( V_88 -> V_229 ) ;
return V_36 ;
}
V_36 = F_123 ( V_88 , V_216 ) ;
if ( V_36 ) {
F_70 ( & V_88 -> V_114 , F_119 ) ;
F_124 ( & V_88 -> V_114 ) ;
return 0 ;
}
F_125 ( V_88 ) ;
return 0 ;
}
bool F_126 ( struct V_88 * V_89 , unsigned long * V_69 )
{
bool V_240 = false ;
if ( V_89 -> V_93 & V_94 ) {
V_89 -> V_93 |= V_131 ;
F_40 ( & V_89 -> V_100 , * V_69 ) ;
F_37 ( L_103 , V_89 ) ;
F_127 ( & V_89 -> V_132 ) ;
F_37 ( L_104 , V_89 ) ;
F_39 ( & V_89 -> V_100 , * V_69 ) ;
V_89 -> V_93 &= ~ V_131 ;
V_89 -> V_93 &= ~ V_94 ;
V_240 = true ;
}
return V_240 ;
}
void F_66 ( struct V_88 * V_89 ,
T_4 V_241 )
{
int V_36 = 0 ;
F_37 ( L_105
L_106 , V_89 , V_89 -> V_80 -> V_106 ( V_89 ) ,
V_89 -> V_177 [ 0 ] ) ;
F_37 ( L_107 ,
V_89 -> V_80 -> V_242 ( V_89 ) ,
V_89 -> V_101 , V_241 ) ;
F_37 ( L_108 ,
( V_89 -> V_93 & V_108 ) != 0 ,
( V_89 -> V_93 & V_104 ) != 0 ,
( V_89 -> V_93 & V_243 ) != 0 ) ;
F_128 ( V_89 ) ;
if ( ( V_89 -> V_116 & V_244 ) &&
V_89 -> V_245 )
V_89 -> V_245 ( V_89 ) ;
switch ( V_241 ) {
case V_246 :
case V_247 :
case V_178 :
case V_248 :
case V_249 :
case V_115 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
break;
case V_197 :
V_241 = V_115 ;
break;
case V_259 :
V_89 -> V_124 = V_198 ;
if ( V_89 -> V_38 &&
V_89 -> V_92 -> V_154 . V_260 == 2 )
F_129 ( V_89 -> V_38 -> V_55 ,
V_89 -> V_261 , 0x2C ,
V_262 ) ;
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_263 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
goto V_266;
default:
F_4 ( L_109 ,
V_89 -> V_177 [ 0 ] , V_241 ) ;
V_241 = V_247 ;
break;
}
V_36 = F_112 ( V_89 , V_241 , 0 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
V_266:
F_60 ( V_89 ) ;
if ( ! F_59 ( V_89 ) )
;
return;
V_265:
V_89 -> V_101 = V_143 ;
F_131 ( V_89 , V_89 -> V_92 ) ;
}
void F_132 ( struct V_88 * V_89 )
{
T_4 V_36 ;
if ( V_89 -> V_267 ) {
V_36 = V_89 -> V_267 ( V_89 ) ;
if ( V_36 ) {
F_34 ( & V_89 -> V_100 ) ;
V_89 -> V_93 &= ~ ( V_94 | V_243 ) ;
F_36 ( & V_89 -> V_100 ) ;
F_66 ( V_89 , V_36 ) ;
}
}
}
static bool F_133 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
if ( V_91 -> V_122 -> V_189 == V_190 )
return false ;
switch ( V_89 -> V_188 ) {
case V_268 :
F_37 ( L_110
L_111 ,
V_89 -> V_177 [ 0 ] , V_89 -> V_192 ) ;
return false ;
case V_269 :
F_134 ( & V_91 -> V_270 ) ;
F_97 () ;
F_37 ( L_112
L_113 ,
V_89 -> V_177 [ 0 ] , V_89 -> V_192 ) ;
if ( ! F_135 ( & V_91 -> V_271 ) )
return false ;
break;
default:
F_134 ( & V_91 -> V_271 ) ;
F_97 () ;
break;
}
if ( F_135 ( & V_91 -> V_270 ) == 0 )
return false ;
F_11 ( & V_91 -> V_272 ) ;
F_35 ( & V_89 -> V_184 , & V_91 -> V_273 ) ;
F_12 ( & V_91 -> V_272 ) ;
F_37 ( L_114
L_115 ,
V_89 -> V_177 [ 0 ] , V_89 -> V_188 ,
V_89 -> V_192 ) ;
return true ;
}
void F_136 ( struct V_88 * V_89 )
{
if ( F_137 ( V_89 , 1 ) )
return;
F_34 ( & V_89 -> V_100 ) ;
if ( V_89 -> V_93 & V_104 ) {
F_37 ( L_35 ,
V_105 , __LINE__ ,
V_89 -> V_80 -> V_106 ( V_89 ) ) ;
F_36 ( & V_89 -> V_100 ) ;
F_47 ( & V_89 -> V_107 ) ;
return;
}
V_89 -> V_101 = V_274 ;
V_89 -> V_93 |= V_108 | V_94 | V_243 ;
F_36 ( & V_89 -> V_100 ) ;
if ( F_133 ( V_89 ) ) {
F_34 ( & V_89 -> V_100 ) ;
V_89 -> V_93 &= ~ V_94 | V_243 ;
F_36 ( & V_89 -> V_100 ) ;
return;
}
F_132 ( V_89 ) ;
}
static void F_138 ( struct V_90 * V_91 )
{
for (; ; ) {
struct V_88 * V_89 ;
F_11 ( & V_91 -> V_272 ) ;
if ( F_51 ( & V_91 -> V_273 ) ) {
F_12 ( & V_91 -> V_272 ) ;
break;
}
V_89 = F_139 ( V_91 -> V_273 . V_275 ,
struct V_88 , V_184 ) ;
F_50 ( & V_89 -> V_184 ) ;
F_12 ( & V_91 -> V_272 ) ;
F_132 ( V_89 ) ;
if ( V_89 -> V_188 == V_269 )
break;
}
}
static void F_128 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_92 ;
if ( V_91 -> V_122 -> V_189 == V_190 )
return;
if ( V_89 -> V_188 == V_237 ) {
F_77 ( & V_91 -> V_271 ) ;
F_78 () ;
V_91 -> V_276 ++ ;
F_37 ( L_116
L_117 , V_91 -> V_276 ,
V_89 -> V_192 ) ;
} else if ( V_89 -> V_188 == V_268 ) {
V_91 -> V_276 ++ ;
F_37 ( L_118
L_119 , V_91 -> V_276 ,
V_89 -> V_192 ) ;
} else if ( V_89 -> V_188 == V_269 ) {
F_77 ( & V_91 -> V_270 ) ;
F_78 () ;
V_91 -> V_276 ++ ;
F_37 ( L_120
L_121 , V_91 -> V_276 , V_89 -> V_192 ) ;
}
F_138 ( V_91 ) ;
}
static void F_80 ( struct V_88 * V_89 )
{
int V_36 = 0 ;
F_128 ( V_89 ) ;
if ( V_89 -> V_116 & V_130 ) {
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_263 ( V_89 ) ;
if ( V_36 )
goto V_3;
}
switch ( V_89 -> V_145 ) {
case V_147 :
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_277 ( V_89 ) ;
break;
case V_148 :
if ( V_89 -> V_116 & V_223 ) {
V_36 = V_89 -> V_80 -> V_277 ( V_89 ) ;
if ( V_36 < 0 )
break;
}
case V_146 :
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_263 ( V_89 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_131 ( V_89 , V_89 -> V_92 ) ;
return;
}
F_60 ( V_89 ) ;
F_59 ( V_89 ) ;
}
static void F_131 (
struct V_88 * V_89 ,
struct V_90 * V_91 )
{
F_34 ( & V_91 -> V_140 ) ;
F_35 ( & V_89 -> V_141 , & V_89 -> V_92 -> V_138 ) ;
F_134 ( & V_91 -> V_142 ) ;
F_97 () ;
F_36 ( & V_89 -> V_92 -> V_140 ) ;
F_124 ( & V_89 -> V_92 -> V_137 ) ;
}
static void V_134 ( struct V_113 * V_114 )
{
struct V_88 * V_89 = F_42 ( V_114 , struct V_88 , V_114 ) ;
int V_36 ;
F_128 ( V_89 ) ;
if ( F_135 ( & V_89 -> V_92 -> V_142 ) != 0 )
F_124 ( & V_89 -> V_92 -> V_137 ) ;
if ( V_89 -> V_116 & V_130 ) {
F_68 ( ! V_89 -> V_124 ) ;
V_36 = F_112 (
V_89 , 0 , 1 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
F_60 ( V_89 ) ;
F_59 ( V_89 ) ;
return;
}
if ( V_89 -> V_245 ) {
T_4 V_48 ;
V_48 = V_89 -> V_245 ( V_89 ) ;
if ( ! V_48 && ! ( V_89 -> V_116 & V_278 ) ) {
return;
} else if ( V_48 ) {
V_36 = F_112 ( V_89 ,
V_48 , 0 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
F_60 ( V_89 ) ;
F_59 ( V_89 ) ;
return;
}
}
switch ( V_89 -> V_145 ) {
case V_147 :
F_11 ( & V_89 -> V_103 -> V_201 ) ;
if ( V_89 -> V_103 -> V_202 ) {
V_89 -> V_103 -> V_202 -> V_203 . V_279 +=
V_89 -> V_176 ;
}
F_12 ( & V_89 -> V_103 -> V_201 ) ;
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_277 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
break;
case V_148 :
F_11 ( & V_89 -> V_103 -> V_201 ) ;
if ( V_89 -> V_103 -> V_202 ) {
V_89 -> V_103 -> V_202 -> V_203 . V_280 +=
V_89 -> V_176 ;
}
F_12 ( & V_89 -> V_103 -> V_201 ) ;
if ( V_89 -> V_116 & V_223 ) {
F_11 ( & V_89 -> V_103 -> V_201 ) ;
if ( V_89 -> V_103 -> V_202 ) {
V_89 -> V_103 -> V_202 -> V_203 . V_279 +=
V_89 -> V_176 ;
}
F_12 ( & V_89 -> V_103 -> V_201 ) ;
V_36 = V_89 -> V_80 -> V_277 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
break;
}
case V_146 :
F_130 ( V_89 ) ;
V_36 = V_89 -> V_80 -> V_263 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
break;
default:
break;
}
F_60 ( V_89 ) ;
F_59 ( V_89 ) ;
return;
V_265:
F_37 ( L_122
L_123 , V_89 , V_89 -> V_145 ) ;
V_89 -> V_101 = V_143 ;
F_131 ( V_89 , V_89 -> V_92 ) ;
}
static inline void F_140 ( struct V_206 * V_207 , int V_281 )
{
struct V_206 * V_282 ;
int V_283 ;
F_141 (sgl, sg, nents, count)
F_142 ( F_115 ( V_282 ) ) ;
F_27 ( V_207 ) ;
}
static inline void F_143 ( struct V_88 * V_89 )
{
if ( ! V_89 -> V_284 )
return;
F_27 ( V_89 -> V_129 ) ;
V_89 -> V_129 = V_89 -> V_284 ;
V_89 -> V_284 = NULL ;
V_89 -> V_211 = V_89 -> V_285 ;
V_89 -> V_285 = 0 ;
}
static inline void F_144 ( struct V_88 * V_89 )
{
if ( V_89 -> V_116 & V_214 ) {
F_143 ( V_89 ) ;
return;
}
F_143 ( V_89 ) ;
F_140 ( V_89 -> V_129 , V_89 -> V_211 ) ;
V_89 -> V_129 = NULL ;
V_89 -> V_211 = 0 ;
F_140 ( V_89 -> V_212 , V_89 -> V_213 ) ;
V_89 -> V_212 = NULL ;
V_89 -> V_213 = 0 ;
}
static int F_145 ( struct V_88 * V_89 )
{
F_10 ( ! V_89 -> V_80 ) ;
if ( V_89 -> V_116 & V_286 )
F_122 ( V_89 -> V_229 ) ;
if ( V_89 -> V_177 != V_89 -> V_196 )
F_27 ( V_89 -> V_177 ) ;
return F_113 ( V_89 -> V_38 , V_89 ) ;
}
static int F_64 ( struct V_88 * V_89 )
{
F_144 ( V_89 ) ;
return F_145 ( V_89 ) ;
}
void * F_146 ( struct V_88 * V_89 )
{
struct V_206 * V_282 = V_89 -> V_129 ;
struct V_287 * * V_288 ;
int V_173 ;
if ( ! V_89 -> V_211 )
return NULL ;
F_10 ( ! V_282 ) ;
if ( V_89 -> V_211 == 1 )
return F_114 ( F_115 ( V_282 ) ) + V_282 -> V_227 ;
V_288 = F_147 ( sizeof( * V_288 ) * V_89 -> V_211 , V_39 ) ;
if ( ! V_288 )
return NULL ;
F_141 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_288 [ V_173 ] = F_115 ( V_282 ) ;
}
V_89 -> V_289 = F_148 ( V_288 , V_89 -> V_211 , V_290 , V_291 ) ;
F_27 ( V_288 ) ;
if ( ! V_89 -> V_289 )
return NULL ;
return V_89 -> V_289 + V_89 -> V_129 [ 0 ] . V_227 ;
}
void F_149 ( struct V_88 * V_89 )
{
if ( ! V_89 -> V_211 ) {
return;
} else if ( V_89 -> V_211 == 1 ) {
F_116 ( F_115 ( V_89 -> V_129 ) ) ;
return;
}
F_150 ( V_89 -> V_289 ) ;
V_89 -> V_289 = NULL ;
}
int
F_151 ( struct V_206 * * V_207 , unsigned int * V_281 , T_1 V_228 ,
bool V_292 )
{
struct V_206 * V_282 ;
struct V_287 * V_287 ;
T_5 V_293 = ( V_292 ) ? V_294 : 0 ;
unsigned int V_295 ;
int V_173 = 0 ;
V_295 = F_152 ( V_228 , V_296 ) ;
V_282 = F_147 ( sizeof( struct V_206 ) * V_295 , V_39 ) ;
if ( ! V_282 )
return - V_31 ;
F_153 ( V_282 , V_295 ) ;
while ( V_228 ) {
T_1 V_297 = F_154 ( T_1 , V_228 , V_296 ) ;
V_287 = F_155 ( V_39 | V_293 ) ;
if ( ! V_287 )
goto V_3;
F_156 ( & V_282 [ V_173 ] , V_287 , V_297 , 0 ) ;
V_228 -= V_297 ;
V_173 ++ ;
}
* V_207 = V_282 ;
* V_281 = V_295 ;
return 0 ;
V_3:
while ( V_173 > 0 ) {
V_173 -- ;
F_142 ( F_115 ( & V_282 [ V_173 ] ) ) ;
}
F_27 ( V_282 ) ;
return - V_31 ;
}
T_4
F_107 ( struct V_88 * V_89 )
{
int V_36 = 0 ;
if ( ! ( V_89 -> V_116 & V_214 ) &&
V_89 -> V_176 ) {
bool V_293 = ! ( V_89 -> V_116 & V_226 ) ;
if ( ( V_89 -> V_116 & V_223 ) ||
( V_89 -> V_116 & V_244 ) ) {
T_1 V_298 ;
if ( V_89 -> V_116 & V_244 )
V_298 = V_89 -> V_299 *
V_89 -> V_92 -> V_154 . V_155 ;
else
V_298 = V_89 -> V_176 ;
V_36 = F_151 ( & V_89 -> V_212 ,
& V_89 -> V_213 ,
V_298 , V_293 ) ;
if ( V_36 < 0 )
return V_115 ;
}
V_36 = F_151 ( & V_89 -> V_129 , & V_89 -> V_211 ,
V_89 -> V_176 , V_293 ) ;
if ( V_36 < 0 )
return V_115 ;
}
F_72 ( V_89 ) ;
if ( V_89 -> V_145 != V_148 ) {
F_136 ( V_89 ) ;
return 0 ;
}
F_58 ( V_89 , false , true ) ;
V_36 = V_89 -> V_80 -> V_99 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 )
goto V_265;
F_68 ( V_36 ) ;
return ( ! V_36 ) ? 0 : V_115 ;
V_265:
F_37 ( L_124 , V_89 ) ;
V_89 -> V_101 = V_144 ;
F_131 ( V_89 , V_89 -> V_92 ) ;
return 0 ;
}
static void F_79 ( struct V_88 * V_89 )
{
int V_36 ;
V_36 = V_89 -> V_80 -> V_99 ( V_89 ) ;
if ( V_36 == - V_264 || V_36 == - V_31 ) {
F_37 ( L_124 ,
V_89 ) ;
F_131 ( V_89 , V_89 -> V_92 ) ;
}
}
int F_157 ( struct V_88 * V_89 , int V_300 )
{
unsigned long V_69 ;
int V_36 = 0 ;
if ( ! ( V_89 -> V_116 & V_301 ) ) {
if ( V_300 && ( V_89 -> V_116 & V_286 ) )
F_158 ( V_89 ) ;
V_36 = F_145 ( V_89 ) ;
} else {
if ( V_300 )
F_158 ( V_89 ) ;
if ( V_89 -> V_96 ) {
F_39 ( & V_89 -> V_100 , V_69 ) ;
F_57 ( V_89 ) ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
}
if ( V_89 -> V_103 )
F_60 ( V_89 ) ;
V_36 = F_64 ( V_89 ) ;
}
return V_36 ;
}
int F_110 ( struct V_2 * V_38 , struct V_88 * V_88 ,
bool V_302 )
{
unsigned long V_69 ;
int V_36 = 0 ;
F_20 ( & V_88 -> V_303 ) ;
if ( V_302 == true ) {
F_33 ( & V_88 -> V_303 ) ;
V_88 -> V_116 |= V_304 ;
}
F_39 ( & V_38 -> V_44 , V_69 ) ;
if ( V_38 -> V_305 ) {
V_36 = - V_306 ;
goto V_3;
}
F_35 ( & V_88 -> V_185 , & V_38 -> V_42 ) ;
V_3:
F_40 ( & V_38 -> V_44 , V_69 ) ;
return V_36 ;
}
static void F_159 ( struct V_71 * V_71 )
{
struct V_88 * V_88 = F_42 ( V_71 , struct V_88 , V_303 ) ;
struct V_2 * V_38 = V_88 -> V_38 ;
if ( F_51 ( & V_88 -> V_185 ) ) {
F_12 ( & V_38 -> V_44 ) ;
V_88 -> V_80 -> V_307 ( V_88 ) ;
return;
}
if ( V_38 -> V_305 && V_88 -> V_308 ) {
F_12 ( & V_38 -> V_44 ) ;
F_47 ( & V_88 -> V_186 ) ;
return;
}
F_50 ( & V_88 -> V_185 ) ;
F_12 ( & V_38 -> V_44 ) ;
V_88 -> V_80 -> V_307 ( V_88 ) ;
}
int F_113 ( struct V_2 * V_38 , struct V_88 * V_88 )
{
return F_160 ( & V_88 -> V_303 , F_159 ,
& V_38 -> V_44 ) ;
}
void F_161 ( struct V_2 * V_38 )
{
struct V_88 * V_88 ;
unsigned long V_69 ;
F_39 ( & V_38 -> V_44 , V_69 ) ;
if ( V_38 -> V_305 ) {
F_40 ( & V_38 -> V_44 , V_69 ) ;
return;
}
V_38 -> V_305 = 1 ;
F_75 ( & V_38 -> V_42 , & V_38 -> V_43 ) ;
F_162 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_88 -> V_308 = 1 ;
F_40 ( & V_38 -> V_44 , V_69 ) ;
}
void F_163 ( struct V_2 * V_38 )
{
struct V_88 * V_88 , * V_309 ;
unsigned long V_69 ;
F_76 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_50 ( & V_88 -> V_185 ) ;
F_37 ( L_125
L_126 , V_88 , V_88 -> V_101 ,
V_88 -> V_80 -> V_242 ( V_88 ) ) ;
F_127 ( & V_88 -> V_186 ) ;
F_37 ( L_127
L_128 , V_88 , V_88 -> V_101 ,
V_88 -> V_80 -> V_242 ( V_88 ) ) ;
V_88 -> V_80 -> V_307 ( V_88 ) ;
}
F_39 ( & V_38 -> V_44 , V_69 ) ;
F_68 ( ! F_51 ( & V_38 -> V_42 ) ) ;
F_40 ( & V_38 -> V_44 , V_69 ) ;
}
static int F_164 ( void * V_310 )
{
struct V_103 * V_110 = V_310 ;
F_165 ( & V_110 -> V_112 ) ;
F_127 ( & V_110 -> V_311 ) ;
F_47 ( & V_110 -> V_312 ) ;
return 0 ;
}
int F_166 ( struct V_103 * V_110 )
{
struct V_313 * V_314 ;
V_314 = F_167 ( F_164 , V_110 ,
L_129 , V_110 -> V_216 ) ;
if ( F_29 ( V_314 ) ) {
F_4 ( L_130 ) ;
return F_168 ( V_314 ) ;
}
F_127 ( & V_110 -> V_312 ) ;
return 0 ;
}
bool F_158 ( struct V_88 * V_89 )
{
unsigned long V_69 ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
if ( ! ( V_89 -> V_116 & V_301 ) &&
! ( V_89 -> V_116 & V_286 ) ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return false ;
}
if ( ! ( V_89 -> V_116 & V_200 ) &&
! ( V_89 -> V_116 & V_286 ) ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return false ;
}
if ( ! ( V_89 -> V_93 & V_108 ) ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return false ;
}
V_89 -> V_93 |= V_104 ;
F_37 ( L_131
L_132 ,
V_89 , V_89 -> V_80 -> V_106 ( V_89 ) ,
V_89 -> V_80 -> V_242 ( V_89 ) , V_89 -> V_101 ) ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
F_127 ( & V_89 -> V_107 ) ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
V_89 -> V_93 &= ~ ( V_108 | V_104 ) ;
F_37 ( L_133
L_134 ,
V_89 -> V_80 -> V_106 ( V_89 ) ) ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
return true ;
}
static int F_169 (
struct V_88 * V_89 ,
T_3 * V_315 ,
T_3 * V_316 )
{
* V_315 = V_89 -> V_317 ;
* V_316 = V_89 -> V_318 ;
return 0 ;
}
static
void F_170 ( unsigned char * V_319 , T_6 V_320 )
{
V_319 [ V_321 ] = 0xc ;
V_319 [ V_322 ] = 0 ;
V_319 [ V_323 ] = 0xa ;
V_319 [ V_324 ] = 0x80 ;
F_171 ( V_320 , & V_319 [ 12 ] ) ;
}
int
F_112 ( struct V_88 * V_89 ,
T_4 V_325 , int V_326 )
{
unsigned char * V_319 = V_89 -> V_125 ;
unsigned long V_69 ;
T_3 V_315 = 0 , V_316 = 0 ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
if ( V_89 -> V_116 & V_117 ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return 0 ;
}
V_89 -> V_116 |= V_117 ;
F_40 ( & V_89 -> V_100 , V_69 ) ;
if ( ! V_325 && V_326 )
goto V_327;
if ( ! V_326 )
V_89 -> V_116 |= V_328 ;
switch ( V_325 ) {
case V_329 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_331 ;
V_319 [ V_332 ] = 0 ;
V_319 [ V_333 ] = 0 ;
break;
case V_246 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x25 ;
break;
case V_247 :
case V_335 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x20 ;
break;
case V_250 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x24 ;
break;
case V_253 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_336 ;
V_319 [ V_332 ] = 0x29 ;
V_319 [ V_333 ] = 0x03 ;
break;
case V_337 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_336 ;
V_319 [ V_332 ] = 0x0c ;
V_319 [ V_333 ] = 0x0d ;
break;
case V_178 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x24 ;
break;
case V_248 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x26 ;
break;
case V_249 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x1a ;
break;
case V_338 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_336 ;
V_319 [ V_332 ] = 0x0c ;
V_319 [ V_333 ] = 0x0c ;
break;
case V_339 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_336 ;
V_319 [ V_332 ] = 0x47 ;
V_319 [ V_333 ] = 0x05 ;
break;
case V_340 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_336 ;
V_319 [ V_332 ] = 0x11 ;
V_319 [ V_333 ] = 0x13 ;
break;
case V_251 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_341 ;
V_319 [ V_332 ] = 0x27 ;
break;
case V_252 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x21 ;
break;
case V_254 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_342 ;
F_172 ( V_89 , & V_315 , & V_316 ) ;
V_319 [ V_332 ] = V_315 ;
V_319 [ V_333 ] = V_316 ;
break;
case V_255 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_331 ;
F_169 ( V_89 , & V_315 , & V_316 ) ;
V_319 [ V_332 ] = V_315 ;
V_319 [ V_333 ] = V_316 ;
break;
case V_343 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_344 ;
V_319 [ V_332 ] = 0x1d ;
V_319 [ V_333 ] = 0x00 ;
break;
case V_256 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x10 ;
V_319 [ V_333 ] = 0x01 ;
F_170 ( V_319 , V_89 -> V_320 ) ;
break;
case V_257 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x10 ;
V_319 [ V_333 ] = 0x02 ;
F_170 ( V_319 , V_89 -> V_320 ) ;
break;
case V_258 :
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_334 ;
V_319 [ V_332 ] = 0x10 ;
V_319 [ V_333 ] = 0x03 ;
F_170 ( V_319 , V_89 -> V_320 ) ;
break;
case V_115 :
default:
V_319 [ 0 ] = 0x70 ;
V_319 [ V_321 ] = 10 ;
V_319 [ V_330 ] = V_331 ;
V_319 [ V_332 ] = 0x08 ;
break;
}
V_89 -> V_124 = V_345 ;
V_89 -> V_118 = V_119 ;
V_327:
F_130 ( V_89 ) ;
return V_89 -> V_80 -> V_263 ( V_89 ) ;
}
int F_137 ( struct V_88 * V_89 , int V_346 )
{
if ( ! ( V_89 -> V_93 & V_133 ) )
return 0 ;
if ( ! V_346 || ( V_89 -> V_116 & V_347 ) )
return 1 ;
F_37 ( L_135 ,
V_89 -> V_177 [ 0 ] , V_89 -> V_80 -> V_106 ( V_89 ) ) ;
V_89 -> V_116 |= V_347 ;
V_89 -> V_124 = V_348 ;
F_130 ( V_89 ) ;
V_89 -> V_80 -> V_263 ( V_89 ) ;
return 1 ;
}
void F_173 ( struct V_88 * V_89 )
{
unsigned long V_69 ;
F_39 ( & V_89 -> V_100 , V_69 ) ;
if ( V_89 -> V_116 & ( V_117 | V_347 ) ) {
F_40 ( & V_89 -> V_100 , V_69 ) ;
return;
}
F_40 ( & V_89 -> V_100 , V_69 ) ;
if ( V_89 -> V_145 == V_148 ) {
if ( V_89 -> V_80 -> V_349 ( V_89 ) != 0 ) {
V_89 -> V_93 |= V_133 ;
F_97 () ;
return;
}
}
V_89 -> V_124 = V_348 ;
F_60 ( V_89 ) ;
F_37 ( L_136
L_137 , V_89 -> V_177 [ 0 ] ,
V_89 -> V_80 -> V_106 ( V_89 ) ) ;
F_130 ( V_89 ) ;
V_89 -> V_80 -> V_263 ( V_89 ) ;
}
static void F_174 ( struct V_113 * V_114 )
{
struct V_88 * V_89 = F_42 ( V_114 , struct V_88 , V_114 ) ;
struct V_90 * V_91 = V_89 -> V_92 ;
struct V_229 * V_350 = V_89 -> V_229 ;
int V_36 ;
switch ( V_350 -> V_351 ) {
case V_238 :
F_175 ( V_91 , V_350 , V_89 -> V_38 ) ;
break;
case V_352 :
case V_353 :
case V_354 :
V_350 -> V_230 = V_355 ;
break;
case V_356 :
V_36 = F_176 ( V_91 , V_350 , NULL , NULL ) ;
V_350 -> V_230 = ( ! V_36 ) ? V_357 :
V_358 ;
break;
case V_359 :
V_350 -> V_230 = V_358 ;
break;
case V_360 :
V_350 -> V_230 = V_358 ;
break;
default:
F_4 ( L_138 ,
V_350 -> V_351 ) ;
V_350 -> V_230 = V_358 ;
break;
}
V_89 -> V_101 = V_361 ;
V_89 -> V_80 -> V_232 ( V_89 ) ;
F_59 ( V_89 ) ;
}
int F_125 (
struct V_88 * V_89 )
{
F_70 ( & V_89 -> V_114 , F_174 ) ;
F_71 ( V_89 -> V_92 -> V_362 , & V_89 -> V_114 ) ;
return 0 ;
}
