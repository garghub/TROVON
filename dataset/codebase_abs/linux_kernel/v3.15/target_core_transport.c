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
struct V_2 * F_15 ( enum V_38 V_39 )
{
struct V_2 * V_40 ;
V_40 = F_16 ( V_1 , V_41 ) ;
if ( ! V_40 ) {
F_4 ( L_28
L_29 ) ;
return F_17 ( - V_31 ) ;
}
F_18 ( & V_40 -> V_42 ) ;
F_18 ( & V_40 -> V_43 ) ;
F_18 ( & V_40 -> V_44 ) ;
F_18 ( & V_40 -> V_45 ) ;
F_19 ( & V_40 -> V_46 ) ;
F_20 ( & V_40 -> V_47 ) ;
V_40 -> V_39 = V_39 ;
return V_40 ;
}
int F_21 ( struct V_2 * V_40 ,
unsigned int V_48 , unsigned int V_49 )
{
int V_50 ;
V_40 -> V_51 = F_22 ( V_48 * V_49 ,
V_41 | V_52 | V_53 ) ;
if ( ! V_40 -> V_51 ) {
V_40 -> V_51 = F_23 ( V_48 * V_49 ) ;
if ( ! V_40 -> V_51 ) {
F_4 ( L_30 ) ;
return - V_31 ;
}
}
V_50 = F_24 ( & V_40 -> V_54 , V_48 ) ;
if ( V_50 < 0 ) {
F_4 ( L_31
L_32 , V_48 ) ;
if ( F_25 ( V_40 -> V_51 ) )
F_26 ( V_40 -> V_51 ) ;
else
F_27 ( V_40 -> V_51 ) ;
V_40 -> V_51 = NULL ;
return - V_31 ;
}
return 0 ;
}
struct V_2 * F_28 ( unsigned int V_48 ,
unsigned int V_49 ,
enum V_38 V_39 )
{
struct V_2 * V_40 ;
int V_50 ;
V_40 = F_15 ( V_39 ) ;
if ( F_29 ( V_40 ) )
return V_40 ;
V_50 = F_21 ( V_40 , V_48 , V_49 ) ;
if ( V_50 < 0 ) {
F_30 ( V_40 ) ;
return F_17 ( - V_31 ) ;
}
return V_40 ;
}
void F_31 (
struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_2 * V_40 ,
void * V_59 )
{
unsigned char V_60 [ V_61 ] ;
V_40 -> V_56 = V_56 ;
V_40 -> V_59 = V_59 ;
if ( V_58 ) {
if ( V_56 -> V_62 -> V_63 != NULL ) {
memset ( & V_60 [ 0 ] , 0 , V_61 ) ;
V_56 -> V_62 -> V_63 ( V_40 ,
& V_60 [ 0 ] , V_61 ) ;
V_40 -> V_64 = F_32 ( & V_60 [ 0 ] ) ;
}
F_33 ( & V_58 -> V_65 ) ;
F_34 ( & V_58 -> V_66 ) ;
V_58 -> V_67 = V_40 ;
F_35 ( & V_40 -> V_43 ,
& V_58 -> V_68 ) ;
F_36 ( & V_58 -> V_66 ) ;
}
F_35 ( & V_40 -> V_42 , & V_56 -> V_69 ) ;
F_37 ( L_33 ,
V_56 -> V_62 -> V_70 () , V_40 -> V_59 ) ;
}
void F_38 (
struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_2 * V_40 ,
void * V_59 )
{
unsigned long V_71 ;
F_39 ( & V_56 -> V_72 , V_71 ) ;
F_31 ( V_56 , V_58 , V_40 , V_59 ) ;
F_40 ( & V_56 -> V_72 , V_71 ) ;
}
static void F_41 ( struct V_73 * V_73 )
{
struct V_2 * V_40 = F_42 ( V_73 ,
struct V_2 , V_47 ) ;
struct V_55 * V_56 = V_40 -> V_56 ;
V_56 -> V_62 -> V_74 ( V_40 ) ;
}
void F_43 ( struct V_2 * V_40 )
{
F_33 ( & V_40 -> V_47 ) ;
}
void F_44 ( struct V_2 * V_40 )
{
struct V_55 * V_75 = V_40 -> V_56 ;
if ( V_75 -> V_62 -> V_76 != NULL ) {
V_75 -> V_62 -> V_76 ( V_40 ) ;
return;
}
F_45 ( & V_40 -> V_47 , F_41 ) ;
}
static void F_46 ( struct V_73 * V_73 )
{
struct V_57 * V_77 = F_42 ( V_73 ,
struct V_57 , V_65 ) ;
F_47 ( & V_77 -> V_78 ) ;
}
void F_48 ( struct V_57 * V_77 )
{
F_45 ( & V_77 -> V_65 , F_46 ) ;
}
void F_49 ( struct V_2 * V_40 )
{
struct V_57 * V_58 ;
unsigned long V_71 ;
V_58 = V_40 -> V_57 ;
if ( V_58 ) {
F_39 ( & V_58 -> V_66 , V_71 ) ;
if ( V_58 -> V_79 == 0 )
F_50 ( & V_40 -> V_43 ) ;
if ( F_51 ( & V_58 -> V_68 ) )
V_58 -> V_67 = NULL ;
else {
V_58 -> V_67 = F_42 (
V_58 -> V_68 . V_80 ,
struct V_2 , V_43 ) ;
}
F_40 ( & V_58 -> V_66 , V_71 ) ;
}
}
void F_30 ( struct V_2 * V_40 )
{
if ( V_40 -> V_51 ) {
F_52 ( & V_40 -> V_54 ) ;
if ( F_25 ( V_40 -> V_51 ) )
F_26 ( V_40 -> V_51 ) ;
else
F_27 ( V_40 -> V_51 ) ;
}
F_53 ( V_1 , V_40 ) ;
}
void F_54 ( struct V_2 * V_40 )
{
struct V_55 * V_56 = V_40 -> V_56 ;
struct V_81 * V_82 ;
struct V_57 * V_58 ;
unsigned long V_71 ;
bool V_83 = true ;
if ( ! V_56 ) {
F_30 ( V_40 ) ;
return;
}
V_82 = V_56 -> V_62 ;
F_39 ( & V_56 -> V_72 , V_71 ) ;
F_50 ( & V_40 -> V_42 ) ;
V_40 -> V_56 = NULL ;
V_40 -> V_59 = NULL ;
F_40 ( & V_56 -> V_72 , V_71 ) ;
V_58 = V_40 -> V_57 ;
F_39 ( & V_56 -> V_84 , V_71 ) ;
if ( V_58 && V_58 -> V_85 ) {
if ( ! V_82 -> V_86 ( V_56 ) ) {
F_50 ( & V_58 -> V_87 ) ;
V_56 -> V_88 -- ;
F_40 ( & V_56 -> V_84 , V_71 ) ;
F_55 ( V_58 ) ;
F_56 ( V_58 , V_56 ) ;
V_82 -> V_89 ( V_56 , V_58 ) ;
V_83 = false ;
F_39 ( & V_56 -> V_84 , V_71 ) ;
}
}
F_40 ( & V_56 -> V_84 , V_71 ) ;
F_37 ( L_34 ,
V_56 -> V_62 -> V_70 () ) ;
if ( V_58 && V_83 == true )
F_48 ( V_58 ) ;
F_30 ( V_40 ) ;
}
static void F_57 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
unsigned long V_71 ;
if ( ! V_93 )
return;
if ( V_91 -> V_95 & V_96 )
return;
F_39 ( & V_93 -> V_97 , V_71 ) ;
if ( V_91 -> V_98 ) {
F_50 ( & V_91 -> V_99 ) ;
V_91 -> V_98 = false ;
}
F_40 ( & V_93 -> V_97 , V_71 ) ;
}
static int F_58 ( struct V_90 * V_91 , bool V_100 ,
bool V_101 )
{
unsigned long V_71 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( V_101 )
V_91 -> V_103 = V_104 ;
if ( V_100 ) {
F_57 ( V_91 ) ;
V_91 -> V_105 = NULL ;
}
if ( V_91 -> V_95 & V_106 ) {
F_37 ( L_35 ,
V_107 , __LINE__ ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_47 ( & V_91 -> V_109 ) ;
return 1 ;
}
V_91 -> V_95 &= ~ V_110 ;
if ( V_100 ) {
if ( V_91 -> V_82 -> V_111 != NULL ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return V_91 -> V_82 -> V_111 ( V_91 ) ;
}
}
F_40 ( & V_91 -> V_102 , V_71 ) ;
return 0 ;
}
static int F_59 ( struct V_90 * V_91 )
{
return F_58 ( V_91 , true , false ) ;
}
static void F_60 ( struct V_90 * V_91 )
{
struct V_105 * V_112 = V_91 -> V_105 ;
if ( ! V_112 )
return;
if ( F_61 ( & V_91 -> V_113 , true , false ) )
F_62 ( & V_112 -> V_114 ) ;
}
void F_63 ( struct V_90 * V_91 , int remove )
{
if ( V_91 -> V_115 & V_116 )
F_60 ( V_91 ) ;
if ( remove )
V_91 -> V_82 -> V_117 ( V_91 ) ;
if ( F_59 ( V_91 ) )
return;
if ( remove )
F_64 ( V_91 ) ;
}
static void F_65 ( struct V_118 * V_119 )
{
struct V_90 * V_91 = F_42 ( V_119 , struct V_90 , V_119 ) ;
F_66 ( V_91 ,
V_120 ) ;
}
static unsigned char * F_67 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
F_68 ( ! V_91 -> V_105 ) ;
if ( ! V_93 )
return NULL ;
if ( V_91 -> V_115 & V_121 )
return NULL ;
V_91 -> V_122 = V_123 ;
F_37 ( L_36 ,
V_93 -> V_124 -> V_125 , V_93 -> V_126 -> V_127 , V_91 -> V_128 ) ;
return V_91 -> V_129 ;
}
void F_69 ( struct V_90 * V_91 , T_3 V_128 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
int V_130 = V_128 == V_131 ;
unsigned long V_71 ;
V_91 -> V_128 = V_128 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
V_91 -> V_95 &= ~ V_96 ;
if ( V_93 && V_93 -> V_126 -> V_132 ) {
V_93 -> V_126 -> V_132 ( V_91 ,
V_91 -> V_133 ,
F_67 ( V_91 ) ) ;
if ( V_91 -> V_115 & V_134 )
V_130 = 1 ;
}
if ( V_91 -> V_95 & V_135 ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_47 ( & V_91 -> V_136 ) ;
return;
}
if ( V_91 -> V_95 & V_137 &&
V_91 -> V_95 & V_106 ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_47 ( & V_91 -> V_109 ) ;
return;
} else if ( ! V_130 ) {
F_70 ( & V_91 -> V_119 , F_65 ) ;
} else {
F_70 ( & V_91 -> V_119 , V_138 ) ;
}
V_91 -> V_103 = V_139 ;
V_91 -> V_95 |= ( V_140 | V_110 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_71 ( V_28 , & V_91 -> V_119 ) ;
}
static void F_72 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
unsigned long V_71 ;
F_39 ( & V_93 -> V_97 , V_71 ) ;
if ( ! V_91 -> V_98 ) {
F_35 ( & V_91 -> V_99 , & V_93 -> V_99 ) ;
V_91 -> V_98 = true ;
}
F_40 ( & V_93 -> V_97 , V_71 ) ;
}
void F_73 ( struct V_118 * V_119 )
{
struct V_92 * V_93 = F_42 ( V_119 , struct V_92 ,
V_141 ) ;
F_74 ( V_142 ) ;
struct V_90 * V_91 , * V_143 ;
F_34 ( & V_93 -> V_144 ) ;
F_75 ( & V_93 -> V_142 , & V_142 ) ;
F_36 ( & V_93 -> V_144 ) ;
F_76 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_50 ( & V_91 -> V_145 ) ;
F_77 ( & V_93 -> V_146 ) ;
F_78 () ;
F_37 ( L_37
L_38 , V_91 -> V_82 -> V_70 () , V_91 ,
( V_91 -> V_103 == V_147 ) ? L_39 :
( V_91 -> V_103 == V_148 ) ? L_40
: L_41 ) ;
if ( V_91 -> V_103 == V_148 )
F_79 ( V_91 ) ;
else if ( V_91 -> V_103 == V_147 )
F_80 ( V_91 ) ;
}
}
unsigned char * F_81 ( struct V_90 * V_91 )
{
switch ( V_91 -> V_149 ) {
case V_150 :
return L_42 ;
case V_151 :
return L_43 ;
case V_152 :
return L_44 ;
case V_153 :
return L_45 ;
default:
break;
}
return L_41 ;
}
void F_82 (
struct V_92 * V_93 ,
char * V_154 ,
int * V_155 )
{
* V_155 += sprintf ( V_154 + * V_155 , L_46 ) ;
if ( V_93 -> V_156 )
* V_155 += sprintf ( V_154 + * V_155 , L_47 ) ;
else
* V_155 += sprintf ( V_154 + * V_155 , L_48 ) ;
* V_155 += sprintf ( V_154 + * V_155 , L_49 , V_93 -> V_157 ) ;
* V_155 += sprintf ( V_154 + * V_155 , L_50 ,
V_93 -> V_158 . V_159 ,
V_93 -> V_158 . V_160 ) ;
* V_155 += sprintf ( V_154 + * V_155 , L_51 ) ;
}
void F_83 (
struct V_161 * V_162 ,
unsigned char * V_163 ,
int V_164 )
{
unsigned char V_60 [ V_165 ] ;
int V_166 ;
memset ( V_60 , 0 , V_165 ) ;
V_166 = sprintf ( V_60 , L_52 ) ;
switch ( V_162 -> V_167 ) {
case 0x00 :
sprintf ( V_60 + V_166 , L_53 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_166 , L_54 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_166 , L_55 ) ;
break;
case 0x30 :
sprintf ( V_60 + V_166 , L_56 ) ;
break;
case 0x40 :
sprintf ( V_60 + V_166 , L_57
L_58 ) ;
break;
case 0x50 :
sprintf ( V_60 + V_166 , L_59 ) ;
break;
case 0x60 :
sprintf ( V_60 + V_166 , L_60 ) ;
break;
case 0x70 :
sprintf ( V_60 + V_166 , L_61
L_58 ) ;
break;
case 0x80 :
sprintf ( V_60 + V_166 , L_62 ) ;
break;
default:
sprintf ( V_60 + V_166 , L_63 ,
V_162 -> V_167 ) ;
break;
}
if ( V_163 )
strncpy ( V_163 , V_60 , V_164 ) ;
else
F_37 ( L_64 , V_60 ) ;
}
void
F_84 ( struct V_161 * V_162 , unsigned char * V_168 )
{
if ( V_168 [ 1 ] & 0x80 ) {
V_162 -> V_167 = ( V_168 [ 0 ] & 0xf0 ) ;
V_162 -> V_169 = 1 ;
F_83 ( V_162 , NULL , 0 ) ;
}
}
int F_85 (
struct V_161 * V_162 ,
unsigned char * V_163 ,
int V_164 )
{
unsigned char V_60 [ V_165 ] ;
int V_36 = 0 ;
int V_166 ;
memset ( V_60 , 0 , V_165 ) ;
V_166 = sprintf ( V_60 , L_65 ) ;
switch ( V_162 -> V_170 ) {
case 0x00 :
sprintf ( V_60 + V_166 , L_66 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_166 , L_67 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_166 , L_68 ) ;
break;
default:
sprintf ( V_60 + V_166 , L_63 , V_162 -> V_170 ) ;
V_36 = - V_171 ;
break;
}
if ( V_163 )
strncpy ( V_163 , V_60 , V_164 ) ;
else
F_37 ( L_64 , V_60 ) ;
return V_36 ;
}
int F_86 ( struct V_161 * V_162 , unsigned char * V_168 )
{
V_162 -> V_170 = ( V_168 [ 1 ] & 0x30 ) ;
return F_85 ( V_162 , NULL , 0 ) ;
}
int F_87 (
struct V_161 * V_162 ,
unsigned char * V_163 ,
int V_164 )
{
unsigned char V_60 [ V_165 ] ;
int V_36 = 0 ;
int V_166 ;
memset ( V_60 , 0 , V_165 ) ;
V_166 = sprintf ( V_60 , L_69 ) ;
switch ( V_162 -> V_172 ) {
case 0x00 :
sprintf ( V_60 + V_166 , L_70 ) ;
break;
case 0x01 :
sprintf ( V_60 + V_166 , L_71 ) ;
break;
case 0x02 :
sprintf ( V_60 + V_166 , L_72 ) ;
break;
case 0x03 :
sprintf ( V_60 + V_166 , L_73 ) ;
break;
case 0x04 :
sprintf ( V_60 + V_166 , L_74 ) ;
break;
case 0x08 :
sprintf ( V_60 + V_166 , L_75 ) ;
break;
default:
sprintf ( V_60 + V_166 , L_76 ,
V_162 -> V_172 ) ;
V_36 = - V_171 ;
break;
}
if ( V_163 ) {
if ( V_164 < strlen ( V_60 ) + 1 )
return - V_171 ;
strncpy ( V_163 , V_60 , V_164 ) ;
} else {
F_37 ( L_64 , V_60 ) ;
}
return V_36 ;
}
int F_88 ( struct V_161 * V_162 , unsigned char * V_168 )
{
V_162 -> V_172 = ( V_168 [ 1 ] & 0x0f ) ;
return F_87 ( V_162 , NULL , 0 ) ;
}
int F_89 (
struct V_161 * V_162 ,
unsigned char * V_163 ,
int V_164 )
{
unsigned char V_60 [ V_165 ] ;
int V_36 = 0 ;
memset ( V_60 , 0 , V_165 ) ;
switch ( V_162 -> V_173 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_77 ,
& V_162 -> V_174 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_78 ,
& V_162 -> V_174 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_79 ,
& V_162 -> V_174 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_80
L_81 , V_162 -> V_173 ) ;
V_36 = - V_171 ;
break;
}
if ( V_163 )
strncpy ( V_163 , V_60 , V_164 ) ;
else
F_37 ( L_64 , V_60 ) ;
return V_36 ;
}
int
F_90 ( struct V_161 * V_162 , unsigned char * V_168 )
{
static const char V_175 [] = L_82 ;
int V_176 = 0 , V_177 = 4 ;
V_162 -> V_173 = ( V_168 [ 0 ] & 0x0f ) ;
switch ( V_162 -> V_173 ) {
case 0x01 :
V_162 -> V_174 [ V_176 ++ ] =
V_175 [ V_162 -> V_172 ] ;
while ( V_177 < ( 4 + V_168 [ 3 ] ) ) {
V_162 -> V_174 [ V_176 ++ ] =
V_175 [ ( V_168 [ V_177 ] & 0xf0 ) >> 4 ] ;
V_162 -> V_174 [ V_176 ++ ] =
V_175 [ V_168 [ V_177 ] & 0x0f ] ;
V_177 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_177 < ( 4 + V_168 [ 3 ] ) )
V_162 -> V_174 [ V_176 ++ ] = V_168 [ V_177 ++ ] ;
break;
default:
break;
}
return F_89 ( V_162 , NULL , 0 ) ;
}
T_4
F_91 ( struct V_90 * V_91 , unsigned int V_178 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_91 -> V_179 ) {
V_91 -> V_180 = V_178 ;
} else if ( V_178 != V_91 -> V_180 ) {
F_92 ( L_83
L_84
L_85 , V_91 -> V_82 -> V_70 () ,
V_91 -> V_180 , V_178 , V_91 -> V_181 [ 0 ] ) ;
if ( V_91 -> V_149 == V_152 ) {
F_4 ( L_86
L_87 ) ;
return V_182 ;
}
if ( V_93 -> V_158 . V_159 != 512 ) {
F_4 ( L_88
L_89
L_90 , V_93 -> V_126 -> V_127 ) ;
return V_182 ;
}
if ( V_178 > V_91 -> V_180 ) {
V_91 -> V_115 |= V_183 ;
V_91 -> V_184 = ( V_178 - V_91 -> V_180 ) ;
} else {
V_91 -> V_115 |= V_185 ;
V_91 -> V_184 = ( V_91 -> V_180 - V_178 ) ;
V_91 -> V_180 = V_178 ;
}
}
return 0 ;
}
void F_93 (
struct V_90 * V_91 ,
struct V_81 * V_186 ,
struct V_2 * V_40 ,
T_1 V_180 ,
int V_149 ,
int V_187 ,
unsigned char * V_129 )
{
F_18 ( & V_91 -> V_188 ) ;
F_18 ( & V_91 -> V_145 ) ;
F_18 ( & V_91 -> V_189 ) ;
F_18 ( & V_91 -> V_99 ) ;
F_94 ( & V_91 -> V_109 ) ;
F_94 ( & V_91 -> V_190 ) ;
F_94 ( & V_91 -> V_136 ) ;
F_19 ( & V_91 -> V_102 ) ;
F_20 ( & V_91 -> V_191 ) ;
V_91 -> V_95 = V_192 ;
V_91 -> V_82 = V_186 ;
V_91 -> V_40 = V_40 ;
V_91 -> V_180 = V_180 ;
V_91 -> V_149 = V_149 ;
V_91 -> V_193 = V_187 ;
V_91 -> V_129 = V_129 ;
V_91 -> V_98 = false ;
}
static T_4
F_95 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_194 == V_195 )
return 0 ;
if ( V_91 -> V_193 == V_196 ) {
F_37 ( L_91
L_92 ) ;
return V_182 ;
}
V_91 -> V_197 = F_96 ( & V_93 -> V_198 ) ;
F_97 () ;
F_37 ( L_93 ,
V_91 -> V_197 , V_91 -> V_193 ,
V_93 -> V_126 -> V_127 ) ;
return 0 ;
}
T_4
F_98 ( struct V_90 * V_91 , unsigned char * V_199 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
T_4 V_36 ;
if ( F_99 ( V_199 ) > V_200 ) {
F_4 ( L_94
L_95 ,
F_99 ( V_199 ) , V_200 ) ;
return V_182 ;
}
if ( F_99 ( V_199 ) > sizeof( V_91 -> V_201 ) ) {
V_91 -> V_181 = F_22 ( F_99 ( V_199 ) ,
V_41 ) ;
if ( ! V_91 -> V_181 ) {
F_4 ( L_96
L_97 ,
F_99 ( V_199 ) ,
( unsigned long ) sizeof( V_91 -> V_201 ) ) ;
return V_202 ;
}
} else
V_91 -> V_181 = & V_91 -> V_201 [ 0 ] ;
memcpy ( V_91 -> V_181 , V_199 , F_99 ( V_199 ) ) ;
F_100 ( V_91 ) ;
V_36 = F_101 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_102 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_103 ( V_91 ) ;
if ( V_36 ) {
V_91 -> V_128 = V_203 ;
return V_36 ;
}
V_36 = V_93 -> V_126 -> V_204 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_95 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_91 -> V_115 |= V_205 ;
F_11 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_105 -> V_207 )
V_91 -> V_105 -> V_207 -> V_208 . V_209 ++ ;
F_12 ( & V_91 -> V_105 -> V_206 ) ;
return 0 ;
}
int F_104 (
struct V_90 * V_91 )
{
T_4 V_36 ;
if ( ! V_91 -> V_105 ) {
F_105 () ;
F_4 ( L_98 ) ;
return - V_171 ;
}
if ( F_106 () ) {
F_105 () ;
F_4 ( L_99
L_100 ) ;
return - V_171 ;
}
V_91 -> V_103 = V_210 ;
V_91 -> V_95 |= V_110 ;
V_36 = F_107 ( V_91 ) ;
if ( V_36 )
F_66 ( V_91 , V_36 ) ;
return 0 ;
}
T_4
F_108 ( struct V_90 * V_91 , struct V_211 * V_212 ,
T_1 V_213 , struct V_211 * V_214 , T_1 V_215 )
{
if ( ! V_212 || ! V_213 )
return 0 ;
if ( V_91 -> V_115 & V_183 ) {
F_92 ( L_101
L_102 ) ;
return V_182 ;
}
V_91 -> V_133 = V_212 ;
V_91 -> V_216 = V_213 ;
if ( V_214 && V_215 ) {
V_91 -> V_217 = V_214 ;
V_91 -> V_218 = V_215 ;
}
V_91 -> V_115 |= V_219 ;
return 0 ;
}
int F_109 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_199 , unsigned char * V_220 , T_1 V_221 ,
T_1 V_180 , int V_187 , int V_222 , int V_71 ,
struct V_211 * V_212 , T_1 V_213 ,
struct V_211 * V_214 , T_1 V_215 ,
struct V_211 * V_223 , T_1 V_224 )
{
struct V_55 * V_56 ;
T_4 V_50 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_10 ( V_90 -> V_82 || V_90 -> V_40 ) ;
F_10 ( F_106 () ) ;
F_93 ( V_90 , V_56 -> V_62 , V_40 ,
V_180 , V_222 , V_187 , V_220 ) ;
if ( V_71 & V_225 )
V_90 -> V_179 = 1 ;
V_36 = F_110 ( V_40 , V_90 , ( V_71 & V_226 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_71 & V_227 )
V_90 -> V_115 |= V_228 ;
V_50 = F_111 ( V_90 , V_221 ) ;
if ( V_50 ) {
F_112 ( V_90 , V_50 , 0 ) ;
F_113 ( V_40 , V_90 ) ;
return 0 ;
}
V_50 = F_98 ( V_90 , V_199 ) ;
if ( V_50 != 0 ) {
F_66 ( V_90 , V_50 ) ;
return 0 ;
}
if ( V_224 ) {
V_90 -> V_229 = V_223 ;
V_90 -> V_230 = V_224 ;
}
if ( V_213 != 0 ) {
F_10 ( ! V_212 ) ;
if ( ! ( V_90 -> V_115 & V_231 ) &&
V_90 -> V_149 == V_151 ) {
unsigned char * V_60 = NULL ;
if ( V_212 )
V_60 = F_114 ( F_115 ( V_212 ) ) + V_212 -> V_232 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_212 -> V_233 ) ;
F_116 ( F_115 ( V_212 ) ) ;
}
}
V_50 = F_108 ( V_90 , V_212 , V_213 ,
V_214 , V_215 ) ;
if ( V_50 != 0 ) {
F_66 ( V_90 , V_50 ) ;
return 0 ;
}
}
F_117 ( V_90 ) ;
F_104 ( V_90 ) ;
return 0 ;
}
int F_118 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_199 , unsigned char * V_220 , T_1 V_221 ,
T_1 V_180 , int V_187 , int V_222 , int V_71 )
{
return F_109 ( V_90 , V_40 , V_199 , V_220 ,
V_221 , V_180 , V_187 , V_222 ,
V_71 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_119 ( struct V_118 * V_119 )
{
struct V_90 * V_90 = F_42 ( V_119 , struct V_90 , V_119 ) ;
V_90 -> V_234 -> V_235 = V_236 ;
V_90 -> V_82 -> V_237 ( V_90 ) ;
F_59 ( V_90 ) ;
}
int F_120 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_220 , T_1 V_221 ,
void * V_238 , unsigned char V_239 ,
T_5 V_240 , unsigned int V_241 , int V_71 )
{
struct V_55 * V_56 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_93 ( V_90 , V_56 -> V_62 , V_40 ,
0 , V_150 , V_242 , V_220 ) ;
V_36 = F_121 ( V_90 , V_238 , V_239 , V_240 ) ;
if ( V_36 < 0 )
return - V_31 ;
if ( V_239 == V_243 )
V_90 -> V_234 -> V_244 = V_241 ;
V_36 = F_110 ( V_40 , V_90 , ( V_71 & V_226 ) ) ;
if ( V_36 ) {
F_122 ( V_90 -> V_234 ) ;
return V_36 ;
}
V_36 = F_123 ( V_90 , V_221 ) ;
if ( V_36 ) {
F_70 ( & V_90 -> V_119 , F_119 ) ;
F_124 ( & V_90 -> V_119 ) ;
return 0 ;
}
F_125 ( V_90 ) ;
return 0 ;
}
bool F_126 ( struct V_90 * V_91 , unsigned long * V_71 )
{
bool V_245 = false ;
if ( V_91 -> V_95 & V_96 ) {
V_91 -> V_95 |= V_135 ;
F_40 ( & V_91 -> V_102 , * V_71 ) ;
F_37 ( L_103 , V_91 ) ;
F_127 ( & V_91 -> V_136 ) ;
F_37 ( L_104 , V_91 ) ;
F_39 ( & V_91 -> V_102 , * V_71 ) ;
V_91 -> V_95 &= ~ V_135 ;
V_91 -> V_95 &= ~ V_96 ;
V_245 = true ;
}
return V_245 ;
}
void F_66 ( struct V_90 * V_91 ,
T_4 V_246 )
{
int V_36 = 0 ;
F_37 ( L_105
L_106 , V_91 , V_91 -> V_82 -> V_108 ( V_91 ) ,
V_91 -> V_181 [ 0 ] ) ;
F_37 ( L_107 ,
V_91 -> V_82 -> V_247 ( V_91 ) ,
V_91 -> V_103 , V_246 ) ;
F_37 ( L_108 ,
( V_91 -> V_95 & V_110 ) != 0 ,
( V_91 -> V_95 & V_106 ) != 0 ,
( V_91 -> V_95 & V_248 ) != 0 ) ;
F_128 ( V_91 ) ;
if ( ( V_91 -> V_115 & V_249 ) &&
V_91 -> V_250 )
V_91 -> V_250 ( V_91 ) ;
switch ( V_246 ) {
case V_251 :
case V_252 :
case V_182 :
case V_253 :
case V_254 :
case V_120 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
break;
case V_202 :
V_246 = V_120 ;
break;
case V_264 :
V_91 -> V_128 = V_203 ;
if ( V_91 -> V_40 &&
V_91 -> V_94 -> V_158 . V_265 == 2 )
F_129 ( V_91 -> V_40 -> V_57 ,
V_91 -> V_266 , 0x2C ,
V_267 ) ;
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_268 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
goto V_271;
default:
F_4 ( L_109 ,
V_91 -> V_181 [ 0 ] , V_246 ) ;
V_246 = V_252 ;
break;
}
V_36 = F_112 ( V_91 , V_246 , 0 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
V_271:
F_60 ( V_91 ) ;
if ( ! F_59 ( V_91 ) )
;
return;
V_270:
V_91 -> V_103 = V_147 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
void F_132 ( struct V_90 * V_91 )
{
T_4 V_36 ;
if ( V_91 -> V_272 ) {
V_36 = V_91 -> V_272 ( V_91 ) ;
if ( V_36 ) {
F_34 ( & V_91 -> V_102 ) ;
V_91 -> V_95 &= ~ ( V_96 | V_248 ) ;
F_36 ( & V_91 -> V_102 ) ;
F_66 ( V_91 , V_36 ) ;
}
}
}
static bool F_133 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_194 == V_195 )
return false ;
switch ( V_91 -> V_193 ) {
case V_273 :
F_37 ( L_110
L_111 ,
V_91 -> V_181 [ 0 ] , V_91 -> V_197 ) ;
return false ;
case V_274 :
F_134 ( & V_93 -> V_275 ) ;
F_97 () ;
F_37 ( L_112
L_113 ,
V_91 -> V_181 [ 0 ] , V_91 -> V_197 ) ;
if ( ! F_135 ( & V_93 -> V_276 ) )
return false ;
break;
default:
F_134 ( & V_93 -> V_276 ) ;
F_97 () ;
break;
}
if ( F_135 ( & V_93 -> V_275 ) == 0 )
return false ;
F_11 ( & V_93 -> V_277 ) ;
F_35 ( & V_91 -> V_188 , & V_93 -> V_278 ) ;
F_12 ( & V_93 -> V_277 ) ;
F_37 ( L_114
L_115 ,
V_91 -> V_181 [ 0 ] , V_91 -> V_193 ,
V_91 -> V_197 ) ;
return true ;
}
void F_136 ( struct V_90 * V_91 )
{
if ( F_137 ( V_91 , 1 ) )
return;
F_34 ( & V_91 -> V_102 ) ;
if ( V_91 -> V_95 & V_106 ) {
F_37 ( L_35 ,
V_107 , __LINE__ ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_36 ( & V_91 -> V_102 ) ;
F_47 ( & V_91 -> V_109 ) ;
return;
}
V_91 -> V_103 = V_279 ;
V_91 -> V_95 |= V_110 | V_96 | V_248 ;
F_36 ( & V_91 -> V_102 ) ;
if ( V_91 -> V_280 == V_281 ) {
if ( ! ( V_91 -> V_40 -> V_39 & V_281 ) )
F_138 ( V_91 ) ;
}
if ( F_133 ( V_91 ) ) {
F_34 ( & V_91 -> V_102 ) ;
V_91 -> V_95 &= ~ V_96 | V_248 ;
F_36 ( & V_91 -> V_102 ) ;
return;
}
F_132 ( V_91 ) ;
}
static void F_139 ( struct V_92 * V_93 )
{
for (; ; ) {
struct V_90 * V_91 ;
F_11 ( & V_93 -> V_277 ) ;
if ( F_51 ( & V_93 -> V_278 ) ) {
F_12 ( & V_93 -> V_277 ) ;
break;
}
V_91 = F_140 ( V_93 -> V_278 . V_282 ,
struct V_90 , V_188 ) ;
F_50 ( & V_91 -> V_188 ) ;
F_12 ( & V_93 -> V_277 ) ;
F_132 ( V_91 ) ;
if ( V_91 -> V_193 == V_274 )
break;
}
}
static void F_128 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_194 == V_195 )
return;
if ( V_91 -> V_193 == V_242 ) {
F_77 ( & V_93 -> V_276 ) ;
F_78 () ;
V_93 -> V_283 ++ ;
F_37 ( L_116
L_117 , V_93 -> V_283 ,
V_91 -> V_197 ) ;
} else if ( V_91 -> V_193 == V_273 ) {
V_93 -> V_283 ++ ;
F_37 ( L_118
L_119 , V_93 -> V_283 ,
V_91 -> V_197 ) ;
} else if ( V_91 -> V_193 == V_274 ) {
F_77 ( & V_93 -> V_275 ) ;
F_78 () ;
V_93 -> V_283 ++ ;
F_37 ( L_120
L_121 , V_93 -> V_283 , V_91 -> V_197 ) ;
}
F_139 ( V_93 ) ;
}
static void F_80 ( struct V_90 * V_91 )
{
int V_36 = 0 ;
F_128 ( V_91 ) ;
if ( V_91 -> V_115 & V_134 ) {
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_268 ( V_91 ) ;
if ( V_36 )
goto V_3;
}
switch ( V_91 -> V_149 ) {
case V_151 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_284 ( V_91 ) ;
break;
case V_152 :
if ( V_91 -> V_115 & V_228 ) {
V_36 = V_91 -> V_82 -> V_284 ( V_91 ) ;
if ( V_36 < 0 )
break;
}
case V_150 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_268 ( V_91 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_131 ( V_91 , V_91 -> V_94 ) ;
return;
}
F_60 ( V_91 ) ;
F_59 ( V_91 ) ;
}
static void F_131 (
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
F_34 ( & V_93 -> V_144 ) ;
F_35 ( & V_91 -> V_145 , & V_91 -> V_94 -> V_142 ) ;
F_134 ( & V_93 -> V_146 ) ;
F_97 () ;
F_36 ( & V_91 -> V_94 -> V_144 ) ;
F_124 ( & V_91 -> V_94 -> V_141 ) ;
}
static bool F_141 ( struct V_90 * V_91 )
{
T_4 V_50 ;
if ( ! ( V_91 -> V_40 -> V_39 & V_285 ) ) {
V_50 = F_142 ( V_91 ) ;
if ( V_50 ) {
V_91 -> V_286 = V_50 ;
return true ;
}
}
return false ;
}
static void V_138 ( struct V_118 * V_119 )
{
struct V_90 * V_91 = F_42 ( V_119 , struct V_90 , V_119 ) ;
int V_36 ;
F_128 ( V_91 ) ;
if ( F_135 ( & V_91 -> V_94 -> V_146 ) != 0 )
F_124 ( & V_91 -> V_94 -> V_141 ) ;
if ( V_91 -> V_115 & V_134 ) {
F_68 ( ! V_91 -> V_128 ) ;
V_36 = F_112 (
V_91 , 0 , 1 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
F_60 ( V_91 ) ;
F_59 ( V_91 ) ;
return;
}
if ( V_91 -> V_250 ) {
T_4 V_50 ;
V_50 = V_91 -> V_250 ( V_91 ) ;
if ( ! V_50 && ! ( V_91 -> V_115 & V_287 ) ) {
return;
} else if ( V_50 ) {
V_36 = F_112 ( V_91 ,
V_50 , 0 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
F_60 ( V_91 ) ;
F_59 ( V_91 ) ;
return;
}
}
switch ( V_91 -> V_149 ) {
case V_151 :
F_11 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_105 -> V_207 ) {
V_91 -> V_105 -> V_207 -> V_208 . V_288 +=
V_91 -> V_180 ;
}
F_12 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_280 == V_285 &&
F_141 ( V_91 ) ) {
V_36 = F_112 ( V_91 ,
V_91 -> V_286 , 0 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
F_60 ( V_91 ) ;
F_59 ( V_91 ) ;
return;
}
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_284 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
break;
case V_152 :
F_11 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_105 -> V_207 ) {
V_91 -> V_105 -> V_207 -> V_208 . V_289 +=
V_91 -> V_180 ;
}
F_12 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_115 & V_228 ) {
F_11 ( & V_91 -> V_105 -> V_206 ) ;
if ( V_91 -> V_105 -> V_207 ) {
V_91 -> V_105 -> V_207 -> V_208 . V_288 +=
V_91 -> V_180 ;
}
F_12 ( & V_91 -> V_105 -> V_206 ) ;
V_36 = V_91 -> V_82 -> V_284 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
break;
}
case V_150 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_268 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
break;
default:
break;
}
F_60 ( V_91 ) ;
F_59 ( V_91 ) ;
return;
V_270:
F_37 ( L_122
L_123 , V_91 , V_91 -> V_149 ) ;
V_91 -> V_103 = V_147 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
static inline void F_143 ( struct V_211 * V_212 , int V_290 )
{
struct V_211 * V_291 ;
int V_292 ;
F_144 (sgl, sg, nents, count)
F_145 ( F_115 ( V_291 ) ) ;
F_27 ( V_212 ) ;
}
static inline void F_146 ( struct V_90 * V_91 )
{
if ( ! V_91 -> V_293 )
return;
F_27 ( V_91 -> V_133 ) ;
V_91 -> V_133 = V_91 -> V_293 ;
V_91 -> V_293 = NULL ;
V_91 -> V_216 = V_91 -> V_294 ;
V_91 -> V_294 = 0 ;
}
static inline void F_147 ( struct V_90 * V_91 )
{
if ( V_91 -> V_115 & V_219 ) {
F_146 ( V_91 ) ;
return;
}
F_146 ( V_91 ) ;
F_143 ( V_91 -> V_133 , V_91 -> V_216 ) ;
V_91 -> V_133 = NULL ;
V_91 -> V_216 = 0 ;
F_143 ( V_91 -> V_217 , V_91 -> V_218 ) ;
V_91 -> V_217 = NULL ;
V_91 -> V_218 = 0 ;
F_143 ( V_91 -> V_229 , V_91 -> V_230 ) ;
V_91 -> V_229 = NULL ;
V_91 -> V_230 = 0 ;
}
static int F_148 ( struct V_90 * V_91 )
{
F_10 ( ! V_91 -> V_82 ) ;
if ( V_91 -> V_115 & V_295 )
F_122 ( V_91 -> V_234 ) ;
if ( V_91 -> V_181 != V_91 -> V_201 )
F_27 ( V_91 -> V_181 ) ;
return F_113 ( V_91 -> V_40 , V_91 ) ;
}
static int F_64 ( struct V_90 * V_91 )
{
F_147 ( V_91 ) ;
return F_148 ( V_91 ) ;
}
void * F_149 ( struct V_90 * V_91 )
{
struct V_211 * V_291 = V_91 -> V_133 ;
struct V_296 * * V_297 ;
int V_177 ;
if ( ! V_91 -> V_216 )
return NULL ;
F_10 ( ! V_291 ) ;
if ( V_91 -> V_216 == 1 )
return F_114 ( F_115 ( V_291 ) ) + V_291 -> V_232 ;
V_297 = F_150 ( sizeof( * V_297 ) * V_91 -> V_216 , V_41 ) ;
if ( ! V_297 )
return NULL ;
F_144 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_297 [ V_177 ] = F_115 ( V_291 ) ;
}
V_91 -> V_298 = F_151 ( V_297 , V_91 -> V_216 , V_299 , V_300 ) ;
F_27 ( V_297 ) ;
if ( ! V_91 -> V_298 )
return NULL ;
return V_91 -> V_298 + V_91 -> V_133 [ 0 ] . V_232 ;
}
void F_152 ( struct V_90 * V_91 )
{
if ( ! V_91 -> V_216 ) {
return;
} else if ( V_91 -> V_216 == 1 ) {
F_116 ( F_115 ( V_91 -> V_133 ) ) ;
return;
}
F_153 ( V_91 -> V_298 ) ;
V_91 -> V_298 = NULL ;
}
int
F_154 ( struct V_211 * * V_212 , unsigned int * V_290 , T_1 V_233 ,
bool V_301 )
{
struct V_211 * V_291 ;
struct V_296 * V_296 ;
T_5 V_302 = ( V_301 ) ? V_303 : 0 ;
unsigned int V_304 ;
int V_177 = 0 ;
V_304 = F_155 ( V_233 , V_305 ) ;
V_291 = F_150 ( sizeof( struct V_211 ) * V_304 , V_41 ) ;
if ( ! V_291 )
return - V_31 ;
F_156 ( V_291 , V_304 ) ;
while ( V_233 ) {
T_1 V_306 = F_157 ( T_1 , V_233 , V_305 ) ;
V_296 = F_158 ( V_41 | V_302 ) ;
if ( ! V_296 )
goto V_3;
F_159 ( & V_291 [ V_177 ] , V_296 , V_306 , 0 ) ;
V_233 -= V_306 ;
V_177 ++ ;
}
* V_212 = V_291 ;
* V_290 = V_304 ;
return 0 ;
V_3:
while ( V_177 > 0 ) {
V_177 -- ;
F_145 ( F_115 ( & V_291 [ V_177 ] ) ) ;
}
F_27 ( V_291 ) ;
return - V_31 ;
}
T_4
F_107 ( struct V_90 * V_91 )
{
int V_36 = 0 ;
if ( ! ( V_91 -> V_115 & V_219 ) &&
V_91 -> V_180 ) {
bool V_302 = ! ( V_91 -> V_115 & V_231 ) ;
if ( ( V_91 -> V_115 & V_228 ) ||
( V_91 -> V_115 & V_249 ) ) {
T_1 V_307 ;
if ( V_91 -> V_115 & V_249 )
V_307 = V_91 -> V_308 *
V_91 -> V_94 -> V_158 . V_159 ;
else
V_307 = V_91 -> V_180 ;
V_36 = F_154 ( & V_91 -> V_217 ,
& V_91 -> V_218 ,
V_307 , V_302 ) ;
if ( V_36 < 0 )
return V_120 ;
}
if ( V_91 -> V_280 != V_309 ) {
V_36 = F_154 ( & V_91 -> V_229 ,
& V_91 -> V_230 ,
V_91 -> V_310 , true ) ;
if ( V_36 < 0 )
return V_120 ;
}
V_36 = F_154 ( & V_91 -> V_133 , & V_91 -> V_216 ,
V_91 -> V_180 , V_302 ) ;
if ( V_36 < 0 )
return V_120 ;
}
F_72 ( V_91 ) ;
if ( V_91 -> V_149 != V_152 ) {
F_136 ( V_91 ) ;
return 0 ;
}
F_58 ( V_91 , false , true ) ;
V_36 = V_91 -> V_82 -> V_101 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 )
goto V_270;
F_68 ( V_36 ) ;
return ( ! V_36 ) ? 0 : V_120 ;
V_270:
F_37 ( L_124 , V_91 ) ;
V_91 -> V_103 = V_148 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
return 0 ;
}
static void F_79 ( struct V_90 * V_91 )
{
int V_36 ;
V_36 = V_91 -> V_82 -> V_101 ( V_91 ) ;
if ( V_36 == - V_269 || V_36 == - V_31 ) {
F_37 ( L_124 ,
V_91 ) ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
}
int F_160 ( struct V_90 * V_91 , int V_311 )
{
unsigned long V_71 ;
int V_36 = 0 ;
if ( ! ( V_91 -> V_115 & V_116 ) ) {
if ( V_311 && ( V_91 -> V_115 & V_295 ) )
F_161 ( V_91 ) ;
V_36 = F_148 ( V_91 ) ;
} else {
if ( V_311 )
F_161 ( V_91 ) ;
if ( V_91 -> V_98 ) {
F_39 ( & V_91 -> V_102 , V_71 ) ;
F_57 ( V_91 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
}
if ( V_91 -> V_105 )
F_60 ( V_91 ) ;
V_36 = F_64 ( V_91 ) ;
}
return V_36 ;
}
int F_110 ( struct V_2 * V_40 , struct V_90 * V_90 ,
bool V_312 )
{
unsigned long V_71 ;
int V_36 = 0 ;
if ( V_312 == true ) {
F_33 ( & V_90 -> V_191 ) ;
V_90 -> V_115 |= V_313 ;
}
F_39 ( & V_40 -> V_46 , V_71 ) ;
if ( V_40 -> V_314 ) {
V_36 = - V_315 ;
goto V_3;
}
F_35 ( & V_90 -> V_189 , & V_40 -> V_44 ) ;
V_3:
F_40 ( & V_40 -> V_46 , V_71 ) ;
return V_36 ;
}
static void F_162 ( struct V_73 * V_73 )
{
struct V_90 * V_90 = F_42 ( V_73 , struct V_90 , V_191 ) ;
struct V_2 * V_40 = V_90 -> V_40 ;
if ( F_51 ( & V_90 -> V_189 ) ) {
F_12 ( & V_40 -> V_46 ) ;
V_90 -> V_82 -> V_316 ( V_90 ) ;
return;
}
if ( V_40 -> V_314 && V_90 -> V_317 ) {
F_12 ( & V_40 -> V_46 ) ;
F_47 ( & V_90 -> V_190 ) ;
return;
}
F_50 ( & V_90 -> V_189 ) ;
F_12 ( & V_40 -> V_46 ) ;
V_90 -> V_82 -> V_316 ( V_90 ) ;
}
int F_113 ( struct V_2 * V_40 , struct V_90 * V_90 )
{
return F_163 ( & V_90 -> V_191 , F_162 ,
& V_40 -> V_46 ) ;
}
void F_164 ( struct V_2 * V_40 )
{
struct V_90 * V_90 ;
unsigned long V_71 ;
F_39 ( & V_40 -> V_46 , V_71 ) ;
if ( V_40 -> V_314 ) {
F_40 ( & V_40 -> V_46 , V_71 ) ;
return;
}
V_40 -> V_314 = 1 ;
F_75 ( & V_40 -> V_44 , & V_40 -> V_45 ) ;
F_165 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_90 -> V_317 = 1 ;
F_40 ( & V_40 -> V_46 , V_71 ) ;
}
void F_166 ( struct V_2 * V_40 )
{
struct V_90 * V_90 , * V_318 ;
unsigned long V_71 ;
F_76 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_50 ( & V_90 -> V_189 ) ;
F_37 ( L_125
L_126 , V_90 , V_90 -> V_103 ,
V_90 -> V_82 -> V_247 ( V_90 ) ) ;
F_127 ( & V_90 -> V_190 ) ;
F_37 ( L_127
L_128 , V_90 , V_90 -> V_103 ,
V_90 -> V_82 -> V_247 ( V_90 ) ) ;
V_90 -> V_82 -> V_316 ( V_90 ) ;
}
F_39 ( & V_40 -> V_46 , V_71 ) ;
F_68 ( ! F_51 ( & V_40 -> V_44 ) ) ;
F_40 ( & V_40 -> V_46 , V_71 ) ;
}
static int F_167 ( void * V_319 )
{
struct V_105 * V_112 = V_319 ;
F_168 ( & V_112 -> V_114 ) ;
F_127 ( & V_112 -> V_320 ) ;
F_47 ( & V_112 -> V_321 ) ;
return 0 ;
}
int F_169 ( struct V_105 * V_112 )
{
struct V_322 * V_323 ;
V_323 = F_170 ( F_167 , V_112 ,
L_129 , V_112 -> V_221 ) ;
if ( F_29 ( V_323 ) ) {
F_4 ( L_130 ) ;
return F_171 ( V_323 ) ;
}
F_127 ( & V_112 -> V_321 ) ;
return 0 ;
}
bool F_161 ( struct V_90 * V_91 )
{
unsigned long V_71 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( ! ( V_91 -> V_115 & V_116 ) &&
! ( V_91 -> V_115 & V_295 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
if ( ! ( V_91 -> V_115 & V_205 ) &&
! ( V_91 -> V_115 & V_295 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
if ( ! ( V_91 -> V_95 & V_110 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
V_91 -> V_95 |= V_106 ;
F_37 ( L_131
L_132 ,
V_91 , V_91 -> V_82 -> V_108 ( V_91 ) ,
V_91 -> V_82 -> V_247 ( V_91 ) , V_91 -> V_103 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_127 ( & V_91 -> V_109 ) ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
V_91 -> V_95 &= ~ ( V_110 | V_106 ) ;
F_37 ( L_133
L_134 ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
return true ;
}
static int F_172 (
struct V_90 * V_91 ,
T_3 * V_324 ,
T_3 * V_325 )
{
* V_324 = V_91 -> V_326 ;
* V_325 = V_91 -> V_327 ;
return 0 ;
}
static
void F_173 ( unsigned char * V_328 , T_6 V_329 )
{
V_328 [ V_330 ] = 0xc ;
V_328 [ V_331 ] = 0 ;
V_328 [ V_332 ] = 0xa ;
V_328 [ V_333 ] = 0x80 ;
F_174 ( V_329 , & V_328 [ 12 ] ) ;
}
int
F_112 ( struct V_90 * V_91 ,
T_4 V_334 , int V_335 )
{
unsigned char * V_328 = V_91 -> V_129 ;
unsigned long V_71 ;
T_3 V_324 = 0 , V_325 = 0 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( V_91 -> V_115 & V_121 ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return 0 ;
}
V_91 -> V_115 |= V_121 ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
if ( ! V_334 && V_335 )
goto V_336;
if ( ! V_335 )
V_91 -> V_115 |= V_337 ;
switch ( V_334 ) {
case V_338 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_340 ;
V_328 [ V_341 ] = 0 ;
V_328 [ V_342 ] = 0 ;
break;
case V_251 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x25 ;
break;
case V_252 :
case V_344 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x20 ;
break;
case V_255 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x24 ;
break;
case V_258 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_345 ;
V_328 [ V_341 ] = 0x29 ;
V_328 [ V_342 ] = 0x03 ;
break;
case V_346 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_345 ;
V_328 [ V_341 ] = 0x0c ;
V_328 [ V_342 ] = 0x0d ;
break;
case V_182 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x24 ;
break;
case V_253 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x26 ;
break;
case V_254 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x1a ;
break;
case V_347 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_345 ;
V_328 [ V_341 ] = 0x0c ;
V_328 [ V_342 ] = 0x0c ;
break;
case V_348 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_345 ;
V_328 [ V_341 ] = 0x47 ;
V_328 [ V_342 ] = 0x05 ;
break;
case V_349 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_345 ;
V_328 [ V_341 ] = 0x11 ;
V_328 [ V_342 ] = 0x13 ;
break;
case V_256 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_350 ;
V_328 [ V_341 ] = 0x27 ;
break;
case V_257 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x21 ;
break;
case V_259 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_351 ;
F_175 ( V_91 , & V_324 , & V_325 ) ;
V_328 [ V_341 ] = V_324 ;
V_328 [ V_342 ] = V_325 ;
break;
case V_260 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_340 ;
F_172 ( V_91 , & V_324 , & V_325 ) ;
V_328 [ V_341 ] = V_324 ;
V_328 [ V_342 ] = V_325 ;
break;
case V_352 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_353 ;
V_328 [ V_341 ] = 0x1d ;
V_328 [ V_342 ] = 0x00 ;
break;
case V_261 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x10 ;
V_328 [ V_342 ] = 0x01 ;
F_173 ( V_328 , V_91 -> V_329 ) ;
break;
case V_262 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x10 ;
V_328 [ V_342 ] = 0x02 ;
F_173 ( V_328 , V_91 -> V_329 ) ;
break;
case V_263 :
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_343 ;
V_328 [ V_341 ] = 0x10 ;
V_328 [ V_342 ] = 0x03 ;
F_173 ( V_328 , V_91 -> V_329 ) ;
break;
case V_120 :
default:
V_328 [ 0 ] = 0x70 ;
V_328 [ V_330 ] = 10 ;
V_328 [ V_339 ] = V_340 ;
V_328 [ V_341 ] = 0x08 ;
break;
}
V_91 -> V_128 = V_354 ;
V_91 -> V_122 = V_123 ;
V_336:
F_130 ( V_91 ) ;
return V_91 -> V_82 -> V_268 ( V_91 ) ;
}
int F_137 ( struct V_90 * V_91 , int V_355 )
{
if ( ! ( V_91 -> V_95 & V_137 ) )
return 0 ;
if ( ! V_355 || ! ( V_91 -> V_115 & V_356 ) )
return 1 ;
F_37 ( L_135 ,
V_91 -> V_181 [ 0 ] , V_91 -> V_82 -> V_108 ( V_91 ) ) ;
V_91 -> V_115 &= ~ V_356 ;
V_91 -> V_128 = V_357 ;
F_130 ( V_91 ) ;
V_91 -> V_82 -> V_268 ( V_91 ) ;
return 1 ;
}
void F_176 ( struct V_90 * V_91 )
{
unsigned long V_71 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( V_91 -> V_115 & ( V_121 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return;
}
F_40 ( & V_91 -> V_102 , V_71 ) ;
if ( V_91 -> V_149 == V_152 ) {
if ( V_91 -> V_82 -> V_358 ( V_91 ) != 0 ) {
V_91 -> V_95 |= V_137 ;
V_91 -> V_115 |= V_356 ;
F_97 () ;
return;
}
}
V_91 -> V_128 = V_357 ;
F_60 ( V_91 ) ;
F_37 ( L_136
L_137 , V_91 -> V_181 [ 0 ] ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_130 ( V_91 ) ;
V_91 -> V_82 -> V_268 ( V_91 ) ;
}
static void F_177 ( struct V_118 * V_119 )
{
struct V_90 * V_91 = F_42 ( V_119 , struct V_90 , V_119 ) ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_234 * V_359 = V_91 -> V_234 ;
int V_36 ;
switch ( V_359 -> V_360 ) {
case V_243 :
F_178 ( V_93 , V_359 , V_91 -> V_40 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
V_359 -> V_235 = V_364 ;
break;
case V_365 :
V_36 = F_179 ( V_93 , V_359 , NULL , NULL ) ;
V_359 -> V_235 = ( ! V_36 ) ? V_366 :
V_367 ;
break;
case V_368 :
V_359 -> V_235 = V_367 ;
break;
case V_369 :
V_359 -> V_235 = V_367 ;
break;
default:
F_4 ( L_138 ,
V_359 -> V_360 ) ;
V_359 -> V_235 = V_367 ;
break;
}
V_91 -> V_103 = V_370 ;
V_91 -> V_82 -> V_237 ( V_91 ) ;
F_59 ( V_91 ) ;
}
int F_125 (
struct V_90 * V_91 )
{
F_70 ( & V_91 -> V_119 , F_177 ) ;
F_71 ( V_91 -> V_94 -> V_371 , & V_91 -> V_119 ) ;
return 0 ;
}
