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
V_36 = F_14 ( L_28 ) ;
if ( V_36 != 0 )
F_4 ( L_29 ) ;
V_37 = 1 ;
}
struct V_2 * F_15 ( enum V_38 V_39 )
{
struct V_2 * V_40 ;
V_40 = F_16 ( V_1 , V_41 ) ;
if ( ! V_40 ) {
F_4 ( L_30
L_31 ) ;
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
F_4 ( L_32 ) ;
return - V_31 ;
}
}
V_50 = F_24 ( & V_40 -> V_54 , V_48 ) ;
if ( V_50 < 0 ) {
F_4 ( L_33
L_34 , V_48 ) ;
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
F_37 ( L_35 ,
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
F_37 ( L_36 ,
V_56 -> V_62 -> V_70 () ) ;
if ( V_58 && V_83 )
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
F_37 ( L_37 ,
V_107 , __LINE__ ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_59 ( & V_91 -> V_109 ) ;
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
static int F_60 ( struct V_90 * V_91 )
{
return F_58 ( V_91 , true , false ) ;
}
static void F_61 ( struct V_90 * V_91 )
{
struct V_105 * V_112 = V_91 -> V_105 ;
if ( ! V_112 )
return;
if ( F_62 ( & V_91 -> V_113 , true , false ) )
F_63 ( & V_112 -> V_114 ) ;
}
void F_64 ( struct V_90 * V_91 , int remove )
{
if ( V_91 -> V_115 & V_116 )
F_61 ( V_91 ) ;
if ( remove )
V_91 -> V_82 -> V_117 ( V_91 ) ;
if ( F_60 ( V_91 ) )
return;
if ( remove )
F_65 ( V_91 ) ;
}
static void F_66 ( struct V_118 * V_119 )
{
struct V_90 * V_91 = F_42 ( V_119 , struct V_90 , V_119 ) ;
F_67 ( V_91 ,
V_120 ) ;
}
static unsigned char * F_68 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
F_69 ( ! V_91 -> V_105 ) ;
if ( ! V_93 )
return NULL ;
if ( V_91 -> V_115 & V_121 )
return NULL ;
V_91 -> V_122 = V_123 ;
F_37 ( L_38 ,
V_93 -> V_124 -> V_125 , V_93 -> V_126 -> V_127 , V_91 -> V_128 ) ;
return V_91 -> V_129 ;
}
void F_70 ( struct V_90 * V_91 , T_3 V_128 )
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
F_68 ( V_91 ) ) ;
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
F_59 ( & V_91 -> V_109 ) ;
return;
} else if ( ! V_130 ) {
F_71 ( & V_91 -> V_119 , F_66 ) ;
} else {
F_71 ( & V_91 -> V_119 , V_138 ) ;
}
V_91 -> V_103 = V_139 ;
V_91 -> V_95 |= ( V_140 | V_110 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_72 ( V_28 , & V_91 -> V_119 ) ;
}
void F_73 ( struct V_90 * V_91 , T_3 V_128 , int V_141 )
{
if ( V_128 == V_142 && V_141 < V_91 -> V_143 ) {
if ( V_91 -> V_115 & V_144 ) {
V_91 -> V_145 += V_91 -> V_143 - V_141 ;
} else {
V_91 -> V_115 |= V_144 ;
V_91 -> V_145 = V_91 -> V_143 - V_141 ;
}
V_91 -> V_143 = V_141 ;
}
F_70 ( V_91 , V_128 ) ;
}
static void F_74 ( struct V_90 * V_91 )
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
void F_75 ( struct V_118 * V_119 )
{
struct V_92 * V_93 = F_42 ( V_119 , struct V_92 ,
V_146 ) ;
F_76 ( V_147 ) ;
struct V_90 * V_91 , * V_148 ;
F_34 ( & V_93 -> V_149 ) ;
F_77 ( & V_93 -> V_147 , & V_147 ) ;
F_36 ( & V_93 -> V_149 ) ;
F_78 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_50 ( & V_91 -> V_150 ) ;
F_79 ( & V_93 -> V_151 ) ;
F_37 ( L_39
L_40 , V_91 -> V_82 -> V_70 () , V_91 ,
( V_91 -> V_103 == V_152 ) ? L_41 :
( V_91 -> V_103 == V_153 ) ? L_42
: L_43 ) ;
if ( V_91 -> V_103 == V_153 )
F_80 ( V_91 ) ;
else if ( V_91 -> V_103 == V_152 )
F_81 ( V_91 ) ;
}
}
unsigned char * F_82 ( struct V_90 * V_91 )
{
switch ( V_91 -> V_154 ) {
case V_155 :
return L_44 ;
case V_156 :
return L_45 ;
case V_157 :
return L_46 ;
case V_158 :
return L_47 ;
default:
break;
}
return L_43 ;
}
void F_83 (
struct V_92 * V_93 ,
char * V_159 ,
int * V_160 )
{
* V_160 += sprintf ( V_159 + * V_160 , L_48 ) ;
if ( V_93 -> V_161 )
* V_160 += sprintf ( V_159 + * V_160 , L_49 ) ;
else
* V_160 += sprintf ( V_159 + * V_160 , L_50 ) ;
* V_160 += sprintf ( V_159 + * V_160 , L_51 , V_93 -> V_162 ) ;
* V_160 += sprintf ( V_159 + * V_160 , L_52 ,
V_93 -> V_163 . V_164 ,
V_93 -> V_163 . V_165 ) ;
* V_160 += sprintf ( V_159 + * V_160 , L_53 ) ;
}
void F_84 (
struct V_166 * V_167 ,
unsigned char * V_168 ,
int V_169 )
{
unsigned char V_60 [ V_170 ] ;
int V_171 ;
memset ( V_60 , 0 , V_170 ) ;
V_171 = sprintf ( V_60 , L_54 ) ;
switch ( V_167 -> V_172 ) {
case 0x00 :
sprintf ( V_60 + V_171 , L_55 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_171 , L_56 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_171 , L_57 ) ;
break;
case 0x30 :
sprintf ( V_60 + V_171 , L_58 ) ;
break;
case 0x40 :
sprintf ( V_60 + V_171 , L_59
L_60 ) ;
break;
case 0x50 :
sprintf ( V_60 + V_171 , L_61 ) ;
break;
case 0x60 :
sprintf ( V_60 + V_171 , L_62 ) ;
break;
case 0x70 :
sprintf ( V_60 + V_171 , L_63
L_60 ) ;
break;
case 0x80 :
sprintf ( V_60 + V_171 , L_64 ) ;
break;
default:
sprintf ( V_60 + V_171 , L_65 ,
V_167 -> V_172 ) ;
break;
}
if ( V_168 )
strncpy ( V_168 , V_60 , V_169 ) ;
else
F_37 ( L_66 , V_60 ) ;
}
void
F_85 ( struct V_166 * V_167 , unsigned char * V_173 )
{
if ( V_173 [ 1 ] & 0x80 ) {
V_167 -> V_172 = ( V_173 [ 0 ] & 0xf0 ) ;
V_167 -> V_174 = 1 ;
F_84 ( V_167 , NULL , 0 ) ;
}
}
int F_86 (
struct V_166 * V_167 ,
unsigned char * V_168 ,
int V_169 )
{
unsigned char V_60 [ V_170 ] ;
int V_36 = 0 ;
int V_171 ;
memset ( V_60 , 0 , V_170 ) ;
V_171 = sprintf ( V_60 , L_67 ) ;
switch ( V_167 -> V_175 ) {
case 0x00 :
sprintf ( V_60 + V_171 , L_68 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_171 , L_69 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_171 , L_70 ) ;
break;
default:
sprintf ( V_60 + V_171 , L_65 , V_167 -> V_175 ) ;
V_36 = - V_176 ;
break;
}
if ( V_168 )
strncpy ( V_168 , V_60 , V_169 ) ;
else
F_37 ( L_66 , V_60 ) ;
return V_36 ;
}
int F_87 ( struct V_166 * V_167 , unsigned char * V_173 )
{
V_167 -> V_175 = ( V_173 [ 1 ] & 0x30 ) ;
return F_86 ( V_167 , NULL , 0 ) ;
}
int F_88 (
struct V_166 * V_167 ,
unsigned char * V_168 ,
int V_169 )
{
unsigned char V_60 [ V_170 ] ;
int V_36 = 0 ;
int V_171 ;
memset ( V_60 , 0 , V_170 ) ;
V_171 = sprintf ( V_60 , L_71 ) ;
switch ( V_167 -> V_177 ) {
case 0x00 :
sprintf ( V_60 + V_171 , L_72 ) ;
break;
case 0x01 :
sprintf ( V_60 + V_171 , L_73 ) ;
break;
case 0x02 :
sprintf ( V_60 + V_171 , L_74 ) ;
break;
case 0x03 :
sprintf ( V_60 + V_171 , L_75 ) ;
break;
case 0x04 :
sprintf ( V_60 + V_171 , L_76 ) ;
break;
case 0x08 :
sprintf ( V_60 + V_171 , L_77 ) ;
break;
default:
sprintf ( V_60 + V_171 , L_78 ,
V_167 -> V_177 ) ;
V_36 = - V_176 ;
break;
}
if ( V_168 ) {
if ( V_169 < strlen ( V_60 ) + 1 )
return - V_176 ;
strncpy ( V_168 , V_60 , V_169 ) ;
} else {
F_37 ( L_66 , V_60 ) ;
}
return V_36 ;
}
int F_89 ( struct V_166 * V_167 , unsigned char * V_173 )
{
V_167 -> V_177 = ( V_173 [ 1 ] & 0x0f ) ;
return F_88 ( V_167 , NULL , 0 ) ;
}
int F_90 (
struct V_166 * V_167 ,
unsigned char * V_168 ,
int V_169 )
{
unsigned char V_60 [ V_170 ] ;
int V_36 = 0 ;
memset ( V_60 , 0 , V_170 ) ;
switch ( V_167 -> V_178 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_79 ,
& V_167 -> V_179 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_80 ,
& V_167 -> V_179 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_81 ,
& V_167 -> V_179 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_82
L_83 , V_167 -> V_178 ) ;
V_36 = - V_176 ;
break;
}
if ( V_168 )
strncpy ( V_168 , V_60 , V_169 ) ;
else
F_37 ( L_66 , V_60 ) ;
return V_36 ;
}
int
F_91 ( struct V_166 * V_167 , unsigned char * V_173 )
{
static const char V_180 [] = L_84 ;
int V_181 = 0 , V_182 = 4 ;
V_167 -> V_178 = ( V_173 [ 0 ] & 0x0f ) ;
switch ( V_167 -> V_178 ) {
case 0x01 :
V_167 -> V_179 [ V_181 ++ ] =
V_180 [ V_167 -> V_177 ] ;
while ( V_182 < ( 4 + V_173 [ 3 ] ) ) {
V_167 -> V_179 [ V_181 ++ ] =
V_180 [ ( V_173 [ V_182 ] & 0xf0 ) >> 4 ] ;
V_167 -> V_179 [ V_181 ++ ] =
V_180 [ V_173 [ V_182 ] & 0x0f ] ;
V_182 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_182 < ( 4 + V_173 [ 3 ] ) )
V_167 -> V_179 [ V_181 ++ ] = V_173 [ V_182 ++ ] ;
break;
default:
break;
}
return F_90 ( V_167 , NULL , 0 ) ;
}
T_4
F_92 ( struct V_90 * V_91 , unsigned int V_183 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_91 -> V_184 ) {
V_91 -> V_143 = V_183 ;
} else if ( V_183 != V_91 -> V_143 ) {
F_93 ( L_85
L_86
L_87 , V_91 -> V_82 -> V_70 () ,
V_91 -> V_143 , V_183 , V_91 -> V_185 [ 0 ] ) ;
if ( V_91 -> V_154 == V_157 ) {
F_4 ( L_88
L_89 ) ;
return V_186 ;
}
if ( V_93 -> V_163 . V_164 != 512 ) {
F_4 ( L_90
L_91
L_92 , V_93 -> V_126 -> V_127 ) ;
return V_186 ;
}
if ( V_183 > V_91 -> V_143 ) {
V_91 -> V_115 |= V_187 ;
V_91 -> V_145 = ( V_183 - V_91 -> V_143 ) ;
} else {
V_91 -> V_115 |= V_144 ;
V_91 -> V_145 = ( V_91 -> V_143 - V_183 ) ;
V_91 -> V_143 = V_183 ;
}
}
return 0 ;
}
void F_94 (
struct V_90 * V_91 ,
struct V_81 * V_188 ,
struct V_2 * V_40 ,
T_1 V_143 ,
int V_154 ,
int V_189 ,
unsigned char * V_129 )
{
F_18 ( & V_91 -> V_190 ) ;
F_18 ( & V_91 -> V_150 ) ;
F_18 ( & V_91 -> V_191 ) ;
F_18 ( & V_91 -> V_99 ) ;
F_95 ( & V_91 -> V_109 ) ;
F_95 ( & V_91 -> V_192 ) ;
F_95 ( & V_91 -> V_136 ) ;
F_19 ( & V_91 -> V_102 ) ;
F_20 ( & V_91 -> V_193 ) ;
V_91 -> V_95 = V_194 ;
V_91 -> V_82 = V_188 ;
V_91 -> V_40 = V_40 ;
V_91 -> V_143 = V_143 ;
V_91 -> V_154 = V_154 ;
V_91 -> V_195 = V_189 ;
V_91 -> V_129 = V_129 ;
V_91 -> V_98 = false ;
}
static T_4
F_96 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_196 == V_197 )
return 0 ;
if ( V_91 -> V_195 == V_198 ) {
F_37 ( L_93
L_94 ) ;
return V_186 ;
}
V_91 -> V_199 = F_97 ( & V_93 -> V_200 ) ;
F_37 ( L_95 ,
V_91 -> V_199 , V_91 -> V_195 ,
V_93 -> V_126 -> V_127 ) ;
return 0 ;
}
T_4
F_98 ( struct V_90 * V_91 , unsigned char * V_201 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
T_4 V_36 ;
if ( F_99 ( V_201 ) > V_202 ) {
F_4 ( L_96
L_97 ,
F_99 ( V_201 ) , V_202 ) ;
return V_186 ;
}
if ( F_99 ( V_201 ) > sizeof( V_91 -> V_203 ) ) {
V_91 -> V_185 = F_22 ( F_99 ( V_201 ) ,
V_41 ) ;
if ( ! V_91 -> V_185 ) {
F_4 ( L_98
L_99 ,
F_99 ( V_201 ) ,
( unsigned long ) sizeof( V_91 -> V_203 ) ) ;
return V_204 ;
}
} else
V_91 -> V_185 = & V_91 -> V_203 [ 0 ] ;
memcpy ( V_91 -> V_185 , V_201 , F_99 ( V_201 ) ) ;
F_100 ( V_91 ) ;
V_36 = F_101 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_102 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_103 ( V_91 ) ;
if ( V_36 ) {
V_91 -> V_128 = V_205 ;
return V_36 ;
}
V_36 = V_93 -> V_126 -> V_206 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_96 ( V_91 ) ;
if ( V_36 )
return V_36 ;
V_91 -> V_115 |= V_207 ;
F_11 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_105 -> V_209 )
V_91 -> V_105 -> V_209 -> V_210 . V_211 ++ ;
F_12 ( & V_91 -> V_105 -> V_208 ) ;
return 0 ;
}
int F_104 (
struct V_90 * V_91 )
{
T_4 V_36 ;
if ( ! V_91 -> V_105 ) {
F_105 () ;
F_4 ( L_100 ) ;
return - V_176 ;
}
if ( F_106 () ) {
F_105 () ;
F_4 ( L_101
L_102 ) ;
return - V_176 ;
}
V_91 -> V_103 = V_212 ;
V_91 -> V_95 |= V_110 ;
V_36 = F_107 ( V_91 ) ;
if ( V_36 )
F_67 ( V_91 , V_36 ) ;
return 0 ;
}
T_4
F_108 ( struct V_90 * V_91 , struct V_213 * V_214 ,
T_1 V_215 , struct V_213 * V_216 , T_1 V_217 )
{
if ( ! V_214 || ! V_215 )
return 0 ;
if ( V_91 -> V_115 & V_187 ) {
F_93 ( L_103
L_104 ) ;
return V_186 ;
}
V_91 -> V_133 = V_214 ;
V_91 -> V_218 = V_215 ;
if ( V_216 && V_217 ) {
V_91 -> V_219 = V_216 ;
V_91 -> V_220 = V_217 ;
}
V_91 -> V_115 |= V_221 ;
return 0 ;
}
int F_109 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_201 , unsigned char * V_222 , T_1 V_223 ,
T_1 V_143 , int V_189 , int V_224 , int V_71 ,
struct V_213 * V_214 , T_1 V_215 ,
struct V_213 * V_216 , T_1 V_217 ,
struct V_213 * V_225 , T_1 V_226 )
{
struct V_55 * V_56 ;
T_4 V_50 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_10 ( V_90 -> V_82 || V_90 -> V_40 ) ;
F_10 ( F_106 () ) ;
F_94 ( V_90 , V_56 -> V_62 , V_40 ,
V_143 , V_224 , V_189 , V_222 ) ;
if ( V_71 & V_227 )
V_90 -> V_184 = 1 ;
V_36 = F_110 ( V_40 , V_90 , ( V_71 & V_228 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_71 & V_229 )
V_90 -> V_115 |= V_230 ;
V_50 = F_111 ( V_90 , V_223 ) ;
if ( V_50 ) {
F_112 ( V_90 , V_50 , 0 ) ;
F_113 ( V_40 , V_90 ) ;
return 0 ;
}
V_50 = F_98 ( V_90 , V_201 ) ;
if ( V_50 != 0 ) {
F_67 ( V_90 , V_50 ) ;
return 0 ;
}
if ( V_226 ) {
V_90 -> V_231 = V_225 ;
V_90 -> V_232 = V_226 ;
}
if ( V_215 != 0 ) {
F_10 ( ! V_214 ) ;
if ( ! ( V_90 -> V_115 & V_233 ) &&
V_90 -> V_154 == V_156 ) {
unsigned char * V_60 = NULL ;
if ( V_214 )
V_60 = F_114 ( F_115 ( V_214 ) ) + V_214 -> V_234 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_214 -> V_141 ) ;
F_116 ( F_115 ( V_214 ) ) ;
}
}
V_50 = F_108 ( V_90 , V_214 , V_215 ,
V_216 , V_217 ) ;
if ( V_50 != 0 ) {
F_67 ( V_90 , V_50 ) ;
return 0 ;
}
}
F_117 ( V_90 ) ;
F_104 ( V_90 ) ;
return 0 ;
}
int F_118 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_201 , unsigned char * V_222 , T_1 V_223 ,
T_1 V_143 , int V_189 , int V_224 , int V_71 )
{
return F_109 ( V_90 , V_40 , V_201 , V_222 ,
V_223 , V_143 , V_189 , V_224 ,
V_71 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_119 ( struct V_118 * V_119 )
{
struct V_90 * V_90 = F_42 ( V_119 , struct V_90 , V_119 ) ;
V_90 -> V_235 -> V_236 = V_237 ;
V_90 -> V_82 -> V_238 ( V_90 ) ;
F_60 ( V_90 ) ;
}
int F_120 ( struct V_90 * V_90 , struct V_2 * V_40 ,
unsigned char * V_222 , T_1 V_223 ,
void * V_239 , unsigned char V_240 ,
T_5 V_241 , unsigned int V_242 , int V_71 )
{
struct V_55 * V_56 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_94 ( V_90 , V_56 -> V_62 , V_40 ,
0 , V_155 , V_243 , V_222 ) ;
V_36 = F_121 ( V_90 , V_239 , V_240 , V_241 ) ;
if ( V_36 < 0 )
return - V_31 ;
if ( V_240 == V_244 )
V_90 -> V_235 -> V_245 = V_242 ;
V_36 = F_110 ( V_40 , V_90 , ( V_71 & V_228 ) ) ;
if ( V_36 ) {
F_122 ( V_90 -> V_235 ) ;
return V_36 ;
}
V_36 = F_123 ( V_90 , V_223 ) ;
if ( V_36 ) {
F_71 ( & V_90 -> V_119 , F_119 ) ;
F_124 ( & V_90 -> V_119 ) ;
return 0 ;
}
F_125 ( V_90 ) ;
return 0 ;
}
bool F_126 ( struct V_90 * V_91 , unsigned long * V_71 )
{
bool V_246 = false ;
if ( V_91 -> V_95 & V_96 ) {
V_91 -> V_95 |= V_135 ;
F_40 ( & V_91 -> V_102 , * V_71 ) ;
F_37 ( L_105 , V_91 ) ;
F_127 ( & V_91 -> V_136 ) ;
F_37 ( L_106 , V_91 ) ;
F_39 ( & V_91 -> V_102 , * V_71 ) ;
V_91 -> V_95 &= ~ V_135 ;
V_91 -> V_95 &= ~ V_96 ;
V_246 = true ;
}
return V_246 ;
}
void F_67 ( struct V_90 * V_91 ,
T_4 V_247 )
{
int V_36 = 0 ;
F_37 ( L_107
L_108 , V_91 , V_91 -> V_82 -> V_108 ( V_91 ) ,
V_91 -> V_185 [ 0 ] ) ;
F_37 ( L_109 ,
V_91 -> V_82 -> V_248 ( V_91 ) ,
V_91 -> V_103 , V_247 ) ;
F_37 ( L_110 ,
( V_91 -> V_95 & V_110 ) != 0 ,
( V_91 -> V_95 & V_106 ) != 0 ,
( V_91 -> V_95 & V_249 ) != 0 ) ;
F_128 ( V_91 ) ;
if ( ( V_91 -> V_115 & V_250 ) &&
V_91 -> V_251 )
V_91 -> V_251 ( V_91 ) ;
switch ( V_247 ) {
case V_252 :
case V_253 :
case V_186 :
case V_254 :
case V_255 :
case V_120 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
break;
case V_204 :
V_247 = V_120 ;
break;
case V_265 :
V_91 -> V_128 = V_205 ;
if ( V_91 -> V_40 &&
V_91 -> V_94 -> V_163 . V_266 == 2 )
F_129 ( V_91 -> V_40 -> V_57 ,
V_91 -> V_267 , 0x2C ,
V_268 ) ;
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_269 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
goto V_272;
default:
F_4 ( L_111 ,
V_91 -> V_185 [ 0 ] , V_247 ) ;
V_247 = V_253 ;
break;
}
V_36 = F_112 ( V_91 , V_247 , 0 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
V_272:
F_61 ( V_91 ) ;
if ( ! F_60 ( V_91 ) )
;
return;
V_271:
V_91 -> V_103 = V_152 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
void F_132 ( struct V_90 * V_91 )
{
T_4 V_36 ;
if ( V_91 -> V_273 ) {
V_36 = V_91 -> V_273 ( V_91 ) ;
if ( V_36 ) {
F_34 ( & V_91 -> V_102 ) ;
V_91 -> V_95 &= ~ ( V_96 | V_249 ) ;
F_36 ( & V_91 -> V_102 ) ;
F_67 ( V_91 , V_36 ) ;
}
}
}
static bool F_133 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_196 == V_197 )
return false ;
switch ( V_91 -> V_195 ) {
case V_274 :
F_37 ( L_112
L_113 ,
V_91 -> V_185 [ 0 ] , V_91 -> V_199 ) ;
return false ;
case V_275 :
F_134 ( & V_93 -> V_276 ) ;
F_37 ( L_114
L_115 ,
V_91 -> V_185 [ 0 ] , V_91 -> V_199 ) ;
if ( ! F_135 ( & V_93 -> V_277 ) )
return false ;
break;
default:
F_134 ( & V_93 -> V_277 ) ;
break;
}
if ( F_135 ( & V_93 -> V_276 ) == 0 )
return false ;
F_11 ( & V_93 -> V_278 ) ;
F_35 ( & V_91 -> V_190 , & V_93 -> V_279 ) ;
F_12 ( & V_93 -> V_278 ) ;
F_37 ( L_116
L_117 ,
V_91 -> V_185 [ 0 ] , V_91 -> V_195 ,
V_91 -> V_199 ) ;
return true ;
}
void F_136 ( struct V_90 * V_91 )
{
if ( F_137 ( V_91 , 1 ) )
return;
F_34 ( & V_91 -> V_102 ) ;
if ( V_91 -> V_95 & V_106 ) {
F_37 ( L_37 ,
V_107 , __LINE__ ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_36 ( & V_91 -> V_102 ) ;
F_59 ( & V_91 -> V_109 ) ;
return;
}
V_91 -> V_103 = V_280 ;
V_91 -> V_95 |= V_110 | V_96 | V_249 ;
F_36 ( & V_91 -> V_102 ) ;
if ( V_91 -> V_281 == V_282 ) {
if ( ! ( V_91 -> V_40 -> V_39 & V_282 ) )
F_138 ( V_91 ) ;
}
if ( F_133 ( V_91 ) ) {
F_34 ( & V_91 -> V_102 ) ;
V_91 -> V_95 &= ~ V_96 | V_249 ;
F_36 ( & V_91 -> V_102 ) ;
return;
}
F_132 ( V_91 ) ;
}
static void F_139 ( struct V_92 * V_93 )
{
for (; ; ) {
struct V_90 * V_91 ;
F_11 ( & V_93 -> V_278 ) ;
if ( F_51 ( & V_93 -> V_279 ) ) {
F_12 ( & V_93 -> V_278 ) ;
break;
}
V_91 = F_140 ( V_93 -> V_279 . V_283 ,
struct V_90 , V_190 ) ;
F_50 ( & V_91 -> V_190 ) ;
F_12 ( & V_93 -> V_278 ) ;
F_132 ( V_91 ) ;
if ( V_91 -> V_195 == V_275 )
break;
}
}
static void F_128 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_126 -> V_196 == V_197 )
return;
if ( V_91 -> V_195 == V_243 ) {
F_79 ( & V_93 -> V_277 ) ;
V_93 -> V_284 ++ ;
F_37 ( L_118
L_119 , V_93 -> V_284 ,
V_91 -> V_199 ) ;
} else if ( V_91 -> V_195 == V_274 ) {
V_93 -> V_284 ++ ;
F_37 ( L_120
L_121 , V_93 -> V_284 ,
V_91 -> V_199 ) ;
} else if ( V_91 -> V_195 == V_275 ) {
F_79 ( & V_93 -> V_276 ) ;
V_93 -> V_284 ++ ;
F_37 ( L_122
L_123 , V_93 -> V_284 , V_91 -> V_199 ) ;
}
F_139 ( V_93 ) ;
}
static void F_81 ( struct V_90 * V_91 )
{
int V_36 = 0 ;
F_128 ( V_91 ) ;
if ( V_91 -> V_115 & V_134 ) {
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_269 ( V_91 ) ;
goto V_3;
}
switch ( V_91 -> V_154 ) {
case V_156 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_285 ( V_91 ) ;
break;
case V_157 :
if ( V_91 -> V_115 & V_230 ) {
V_36 = V_91 -> V_82 -> V_285 ( V_91 ) ;
if ( V_36 < 0 )
break;
}
case V_155 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_269 ( V_91 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_131 ( V_91 , V_91 -> V_94 ) ;
return;
}
F_61 ( V_91 ) ;
F_60 ( V_91 ) ;
}
static void F_131 (
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
F_34 ( & V_93 -> V_149 ) ;
F_35 ( & V_91 -> V_150 , & V_91 -> V_94 -> V_147 ) ;
F_134 ( & V_93 -> V_151 ) ;
F_36 ( & V_91 -> V_94 -> V_149 ) ;
F_124 ( & V_91 -> V_94 -> V_146 ) ;
}
static bool F_141 ( struct V_90 * V_91 )
{
T_4 V_50 ;
if ( ! ( V_91 -> V_40 -> V_39 & V_286 ) ) {
V_50 = F_142 ( V_91 ) ;
if ( V_50 ) {
V_91 -> V_287 = V_50 ;
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
if ( F_135 ( & V_91 -> V_94 -> V_151 ) != 0 )
F_124 ( & V_91 -> V_94 -> V_146 ) ;
if ( V_91 -> V_115 & V_134 ) {
F_69 ( ! V_91 -> V_128 ) ;
V_36 = F_112 (
V_91 , 0 , 1 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
F_61 ( V_91 ) ;
F_60 ( V_91 ) ;
return;
}
if ( V_91 -> V_251 ) {
T_4 V_50 ;
V_50 = V_91 -> V_251 ( V_91 ) ;
if ( ! V_50 && ! ( V_91 -> V_115 & V_288 ) ) {
return;
} else if ( V_50 ) {
V_36 = F_112 ( V_91 ,
V_50 , 0 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
F_61 ( V_91 ) ;
F_60 ( V_91 ) ;
return;
}
}
switch ( V_91 -> V_154 ) {
case V_156 :
F_11 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_105 -> V_209 ) {
V_91 -> V_105 -> V_209 -> V_210 . V_289 +=
V_91 -> V_143 ;
}
F_12 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_281 == V_286 &&
F_141 ( V_91 ) ) {
V_36 = F_112 ( V_91 ,
V_91 -> V_287 , 0 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
F_61 ( V_91 ) ;
F_60 ( V_91 ) ;
return;
}
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_285 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
break;
case V_157 :
F_11 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_105 -> V_209 ) {
V_91 -> V_105 -> V_209 -> V_210 . V_290 +=
V_91 -> V_143 ;
}
F_12 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_115 & V_230 ) {
F_11 ( & V_91 -> V_105 -> V_208 ) ;
if ( V_91 -> V_105 -> V_209 ) {
V_91 -> V_105 -> V_209 -> V_210 . V_289 +=
V_91 -> V_143 ;
}
F_12 ( & V_91 -> V_105 -> V_208 ) ;
V_36 = V_91 -> V_82 -> V_285 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
break;
}
case V_155 :
F_130 ( V_91 ) ;
V_36 = V_91 -> V_82 -> V_269 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
break;
default:
break;
}
F_61 ( V_91 ) ;
F_60 ( V_91 ) ;
return;
V_271:
F_37 ( L_124
L_125 , V_91 , V_91 -> V_154 ) ;
V_91 -> V_103 = V_152 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
static inline void F_143 ( struct V_213 * V_214 , int V_291 )
{
struct V_213 * V_292 ;
int V_293 ;
F_144 (sgl, sg, nents, count)
F_145 ( F_115 ( V_292 ) ) ;
F_27 ( V_214 ) ;
}
static inline void F_146 ( struct V_90 * V_91 )
{
if ( ! V_91 -> V_294 )
return;
F_27 ( V_91 -> V_133 ) ;
V_91 -> V_133 = V_91 -> V_294 ;
V_91 -> V_294 = NULL ;
V_91 -> V_218 = V_91 -> V_295 ;
V_91 -> V_295 = 0 ;
}
static inline void F_147 ( struct V_90 * V_91 )
{
if ( V_91 -> V_115 & V_221 ) {
F_146 ( V_91 ) ;
return;
}
F_146 ( V_91 ) ;
F_143 ( V_91 -> V_133 , V_91 -> V_218 ) ;
V_91 -> V_133 = NULL ;
V_91 -> V_218 = 0 ;
F_143 ( V_91 -> V_219 , V_91 -> V_220 ) ;
V_91 -> V_219 = NULL ;
V_91 -> V_220 = 0 ;
F_143 ( V_91 -> V_231 , V_91 -> V_232 ) ;
V_91 -> V_231 = NULL ;
V_91 -> V_232 = 0 ;
}
static int F_148 ( struct V_90 * V_91 )
{
F_10 ( ! V_91 -> V_82 ) ;
if ( V_91 -> V_115 & V_296 )
F_122 ( V_91 -> V_235 ) ;
if ( V_91 -> V_185 != V_91 -> V_203 )
F_27 ( V_91 -> V_185 ) ;
return F_113 ( V_91 -> V_40 , V_91 ) ;
}
static int F_65 ( struct V_90 * V_91 )
{
F_147 ( V_91 ) ;
return F_148 ( V_91 ) ;
}
void * F_149 ( struct V_90 * V_91 )
{
struct V_213 * V_292 = V_91 -> V_133 ;
struct V_297 * * V_298 ;
int V_182 ;
if ( ! V_91 -> V_218 )
return NULL ;
F_10 ( ! V_292 ) ;
if ( V_91 -> V_218 == 1 )
return F_114 ( F_115 ( V_292 ) ) + V_292 -> V_234 ;
V_298 = F_150 ( sizeof( * V_298 ) * V_91 -> V_218 , V_41 ) ;
if ( ! V_298 )
return NULL ;
F_144 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_298 [ V_182 ] = F_115 ( V_292 ) ;
}
V_91 -> V_299 = F_151 ( V_298 , V_91 -> V_218 , V_300 , V_301 ) ;
F_27 ( V_298 ) ;
if ( ! V_91 -> V_299 )
return NULL ;
return V_91 -> V_299 + V_91 -> V_133 [ 0 ] . V_234 ;
}
void F_152 ( struct V_90 * V_91 )
{
if ( ! V_91 -> V_218 ) {
return;
} else if ( V_91 -> V_218 == 1 ) {
F_116 ( F_115 ( V_91 -> V_133 ) ) ;
return;
}
F_153 ( V_91 -> V_299 ) ;
V_91 -> V_299 = NULL ;
}
int
F_154 ( struct V_213 * * V_214 , unsigned int * V_291 , T_1 V_141 ,
bool V_302 )
{
struct V_213 * V_292 ;
struct V_297 * V_297 ;
T_5 V_303 = ( V_302 ) ? V_304 : 0 ;
unsigned int V_305 ;
int V_182 = 0 ;
V_305 = F_155 ( V_141 , V_306 ) ;
V_292 = F_150 ( sizeof( struct V_213 ) * V_305 , V_41 ) ;
if ( ! V_292 )
return - V_31 ;
F_156 ( V_292 , V_305 ) ;
while ( V_141 ) {
T_1 V_307 = F_157 ( T_1 , V_141 , V_306 ) ;
V_297 = F_158 ( V_41 | V_303 ) ;
if ( ! V_297 )
goto V_3;
F_159 ( & V_292 [ V_182 ] , V_297 , V_307 , 0 ) ;
V_141 -= V_307 ;
V_182 ++ ;
}
* V_214 = V_292 ;
* V_291 = V_305 ;
return 0 ;
V_3:
while ( V_182 > 0 ) {
V_182 -- ;
F_145 ( F_115 ( & V_292 [ V_182 ] ) ) ;
}
F_27 ( V_292 ) ;
return - V_31 ;
}
T_4
F_107 ( struct V_90 * V_91 )
{
int V_36 = 0 ;
if ( ! ( V_91 -> V_115 & V_221 ) &&
V_91 -> V_143 ) {
bool V_303 = ! ( V_91 -> V_115 & V_233 ) ;
if ( ( V_91 -> V_115 & V_230 ) ||
( V_91 -> V_115 & V_250 ) ) {
T_1 V_308 ;
if ( V_91 -> V_115 & V_250 )
V_308 = V_91 -> V_309 *
V_91 -> V_94 -> V_163 . V_164 ;
else
V_308 = V_91 -> V_143 ;
V_36 = F_154 ( & V_91 -> V_219 ,
& V_91 -> V_220 ,
V_308 , V_303 ) ;
if ( V_36 < 0 )
return V_120 ;
}
if ( V_91 -> V_281 != V_310 ) {
V_36 = F_154 ( & V_91 -> V_231 ,
& V_91 -> V_232 ,
V_91 -> V_311 , true ) ;
if ( V_36 < 0 )
return V_120 ;
}
V_36 = F_154 ( & V_91 -> V_133 , & V_91 -> V_218 ,
V_91 -> V_143 , V_303 ) ;
if ( V_36 < 0 )
return V_120 ;
}
F_74 ( V_91 ) ;
if ( V_91 -> V_154 != V_157 || V_91 -> V_143 == 0 ) {
F_136 ( V_91 ) ;
return 0 ;
}
F_58 ( V_91 , false , true ) ;
V_36 = V_91 -> V_82 -> V_101 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 )
goto V_271;
F_69 ( V_36 ) ;
return ( ! V_36 ) ? 0 : V_120 ;
V_271:
F_37 ( L_126 , V_91 ) ;
V_91 -> V_103 = V_153 ;
F_131 ( V_91 , V_91 -> V_94 ) ;
return 0 ;
}
static void F_80 ( struct V_90 * V_91 )
{
int V_36 ;
V_36 = V_91 -> V_82 -> V_101 ( V_91 ) ;
if ( V_36 == - V_270 || V_36 == - V_31 ) {
F_37 ( L_126 ,
V_91 ) ;
F_131 ( V_91 , V_91 -> V_94 ) ;
}
}
int F_160 ( struct V_90 * V_91 , int V_312 )
{
unsigned long V_71 ;
int V_36 = 0 ;
if ( ! ( V_91 -> V_115 & V_116 ) ) {
if ( V_312 && ( V_91 -> V_115 & V_296 ) )
F_161 ( V_91 ) ;
V_36 = F_148 ( V_91 ) ;
} else {
if ( V_312 )
F_161 ( V_91 ) ;
if ( V_91 -> V_98 ) {
F_39 ( & V_91 -> V_102 , V_71 ) ;
F_57 ( V_91 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
}
if ( V_91 -> V_105 )
F_61 ( V_91 ) ;
V_36 = F_65 ( V_91 ) ;
}
return V_36 ;
}
int F_110 ( struct V_2 * V_40 , struct V_90 * V_90 ,
bool V_313 )
{
unsigned long V_71 ;
int V_36 = 0 ;
if ( V_313 ) {
F_33 ( & V_90 -> V_193 ) ;
V_90 -> V_115 |= V_314 ;
}
F_39 ( & V_40 -> V_46 , V_71 ) ;
if ( V_40 -> V_315 ) {
V_36 = - V_316 ;
goto V_3;
}
F_35 ( & V_90 -> V_191 , & V_40 -> V_44 ) ;
V_3:
F_40 ( & V_40 -> V_46 , V_71 ) ;
if ( V_36 && V_313 )
F_113 ( V_40 , V_90 ) ;
return V_36 ;
}
static void F_162 ( struct V_73 * V_73 )
{
struct V_90 * V_90 = F_42 ( V_73 , struct V_90 , V_193 ) ;
struct V_2 * V_40 = V_90 -> V_40 ;
if ( F_51 ( & V_90 -> V_191 ) ) {
F_12 ( & V_40 -> V_46 ) ;
V_90 -> V_82 -> V_317 ( V_90 ) ;
return;
}
if ( V_40 -> V_315 && V_90 -> V_318 ) {
F_12 ( & V_40 -> V_46 ) ;
F_47 ( & V_90 -> V_192 ) ;
return;
}
F_50 ( & V_90 -> V_191 ) ;
F_12 ( & V_40 -> V_46 ) ;
V_90 -> V_82 -> V_317 ( V_90 ) ;
}
int F_113 ( struct V_2 * V_40 , struct V_90 * V_90 )
{
if ( ! V_40 ) {
V_90 -> V_82 -> V_317 ( V_90 ) ;
return 1 ;
}
return F_163 ( & V_90 -> V_193 , F_162 ,
& V_40 -> V_46 ) ;
}
void F_164 ( struct V_2 * V_40 )
{
struct V_90 * V_90 ;
unsigned long V_71 ;
F_39 ( & V_40 -> V_46 , V_71 ) ;
if ( V_40 -> V_315 ) {
F_40 ( & V_40 -> V_46 , V_71 ) ;
return;
}
V_40 -> V_315 = 1 ;
F_77 ( & V_40 -> V_44 , & V_40 -> V_45 ) ;
F_165 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_90 -> V_318 = 1 ;
F_40 ( & V_40 -> V_46 , V_71 ) ;
}
void F_166 ( struct V_2 * V_40 )
{
struct V_90 * V_90 , * V_319 ;
unsigned long V_71 ;
F_78 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_50 ( & V_90 -> V_191 ) ;
F_37 ( L_127
L_128 , V_90 , V_90 -> V_103 ,
V_90 -> V_82 -> V_248 ( V_90 ) ) ;
F_127 ( & V_90 -> V_192 ) ;
F_37 ( L_129
L_130 , V_90 , V_90 -> V_103 ,
V_90 -> V_82 -> V_248 ( V_90 ) ) ;
V_90 -> V_82 -> V_317 ( V_90 ) ;
}
F_39 ( & V_40 -> V_46 , V_71 ) ;
F_69 ( ! F_51 ( & V_40 -> V_44 ) ) ;
F_40 ( & V_40 -> V_46 , V_71 ) ;
}
static int F_167 ( void * V_320 )
{
struct V_105 * V_112 = V_320 ;
F_168 ( & V_112 -> V_114 ) ;
F_127 ( & V_112 -> V_321 ) ;
F_47 ( & V_112 -> V_322 ) ;
return 0 ;
}
int F_169 ( struct V_105 * V_112 )
{
struct V_323 * V_324 ;
V_324 = F_170 ( F_167 , V_112 ,
L_131 , V_112 -> V_223 ) ;
if ( F_29 ( V_324 ) ) {
F_4 ( L_132 ) ;
return F_171 ( V_324 ) ;
}
F_127 ( & V_112 -> V_322 ) ;
return 0 ;
}
bool F_161 ( struct V_90 * V_91 )
{
unsigned long V_71 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( ! ( V_91 -> V_115 & V_116 ) &&
! ( V_91 -> V_115 & V_296 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
if ( ! ( V_91 -> V_115 & V_207 ) &&
! ( V_91 -> V_115 & V_296 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
if ( ! ( V_91 -> V_95 & V_110 ) ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return false ;
}
V_91 -> V_95 |= V_106 ;
F_37 ( L_133
L_134 ,
V_91 , V_91 -> V_82 -> V_108 ( V_91 ) ,
V_91 -> V_82 -> V_248 ( V_91 ) , V_91 -> V_103 ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_127 ( & V_91 -> V_109 ) ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
V_91 -> V_95 &= ~ ( V_110 | V_106 ) ;
F_37 ( L_135
L_136 ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
return true ;
}
static int F_172 (
struct V_90 * V_91 ,
T_3 * V_325 ,
T_3 * V_326 )
{
* V_325 = V_91 -> V_327 ;
* V_326 = V_91 -> V_328 ;
return 0 ;
}
static
void F_173 ( unsigned char * V_329 , T_6 V_330 )
{
V_329 [ V_331 ] = 0xc ;
V_329 [ V_332 ] = 0 ;
V_329 [ V_333 ] = 0xa ;
V_329 [ V_334 ] = 0x80 ;
F_174 ( V_330 , & V_329 [ 12 ] ) ;
}
int
F_112 ( struct V_90 * V_91 ,
T_4 V_335 , int V_336 )
{
unsigned char * V_329 = V_91 -> V_129 ;
unsigned long V_71 ;
T_3 V_325 = 0 , V_326 = 0 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
if ( V_91 -> V_115 & V_121 ) {
F_40 ( & V_91 -> V_102 , V_71 ) ;
return 0 ;
}
V_91 -> V_115 |= V_121 ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
if ( ! V_335 && V_336 )
goto V_337;
if ( ! V_336 )
V_91 -> V_115 |= V_338 ;
switch ( V_335 ) {
case V_339 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_341 ;
V_329 [ V_342 ] = 0 ;
V_329 [ V_343 ] = 0 ;
break;
case V_252 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x25 ;
break;
case V_253 :
case V_345 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x20 ;
break;
case V_256 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x24 ;
break;
case V_259 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_346 ;
V_329 [ V_342 ] = 0x29 ;
V_329 [ V_343 ] = 0x03 ;
break;
case V_347 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_346 ;
V_329 [ V_342 ] = 0x0c ;
V_329 [ V_343 ] = 0x0d ;
break;
case V_186 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x24 ;
break;
case V_254 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x26 ;
break;
case V_255 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x1a ;
break;
case V_348 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_346 ;
V_329 [ V_342 ] = 0x0c ;
V_329 [ V_343 ] = 0x0c ;
break;
case V_349 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_346 ;
V_329 [ V_342 ] = 0x47 ;
V_329 [ V_343 ] = 0x05 ;
break;
case V_350 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_346 ;
V_329 [ V_342 ] = 0x11 ;
V_329 [ V_343 ] = 0x13 ;
break;
case V_257 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_351 ;
V_329 [ V_342 ] = 0x27 ;
break;
case V_258 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x21 ;
break;
case V_260 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_352 ;
F_175 ( V_91 , & V_325 , & V_326 ) ;
V_329 [ V_342 ] = V_325 ;
V_329 [ V_343 ] = V_326 ;
break;
case V_261 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_341 ;
F_172 ( V_91 , & V_325 , & V_326 ) ;
V_329 [ V_342 ] = V_325 ;
V_329 [ V_343 ] = V_326 ;
break;
case V_353 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_354 ;
V_329 [ V_342 ] = 0x1d ;
V_329 [ V_343 ] = 0x00 ;
break;
case V_262 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x10 ;
V_329 [ V_343 ] = 0x01 ;
F_173 ( V_329 , V_91 -> V_330 ) ;
break;
case V_263 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x10 ;
V_329 [ V_343 ] = 0x02 ;
F_173 ( V_329 , V_91 -> V_330 ) ;
break;
case V_264 :
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_344 ;
V_329 [ V_342 ] = 0x10 ;
V_329 [ V_343 ] = 0x03 ;
F_173 ( V_329 , V_91 -> V_330 ) ;
break;
case V_120 :
default:
V_329 [ 0 ] = 0x70 ;
V_329 [ V_331 ] = 10 ;
V_329 [ V_340 ] = V_341 ;
V_329 [ V_342 ] = 0x08 ;
break;
}
V_91 -> V_128 = V_355 ;
V_91 -> V_122 = V_123 ;
V_337:
F_130 ( V_91 ) ;
return V_91 -> V_82 -> V_269 ( V_91 ) ;
}
int F_137 ( struct V_90 * V_91 , int V_356 )
{
if ( ! ( V_91 -> V_95 & V_137 ) )
return 0 ;
if ( ! V_356 || ! ( V_91 -> V_115 & V_357 ) )
return 1 ;
F_37 ( L_137 ,
V_91 -> V_185 [ 0 ] , V_91 -> V_82 -> V_108 ( V_91 ) ) ;
V_91 -> V_115 &= ~ V_357 ;
V_91 -> V_128 = V_358 ;
F_130 ( V_91 ) ;
V_91 -> V_82 -> V_269 ( V_91 ) ;
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
if ( V_91 -> V_154 == V_157 ) {
if ( V_91 -> V_82 -> V_359 ( V_91 ) != 0 ) {
V_91 -> V_95 |= V_137 ;
V_91 -> V_115 |= V_357 ;
return;
}
}
V_91 -> V_128 = V_358 ;
F_61 ( V_91 ) ;
F_37 ( L_138
L_139 , V_91 -> V_185 [ 0 ] ,
V_91 -> V_82 -> V_108 ( V_91 ) ) ;
F_130 ( V_91 ) ;
V_91 -> V_82 -> V_269 ( V_91 ) ;
}
static void F_177 ( struct V_118 * V_119 )
{
struct V_90 * V_91 = F_42 ( V_119 , struct V_90 , V_119 ) ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_235 * V_360 = V_91 -> V_235 ;
int V_36 ;
switch ( V_360 -> V_361 ) {
case V_244 :
F_178 ( V_93 , V_360 , V_91 -> V_40 ) ;
break;
case V_362 :
case V_363 :
case V_364 :
V_360 -> V_236 = V_365 ;
break;
case V_366 :
V_36 = F_179 ( V_93 , V_360 , NULL , NULL ) ;
V_360 -> V_236 = ( ! V_36 ) ? V_367 :
V_368 ;
break;
case V_369 :
V_360 -> V_236 = V_368 ;
break;
case V_370 :
V_360 -> V_236 = V_368 ;
break;
default:
F_4 ( L_140 ,
V_360 -> V_361 ) ;
V_360 -> V_236 = V_368 ;
break;
}
V_91 -> V_103 = V_371 ;
V_91 -> V_82 -> V_238 ( V_91 ) ;
F_60 ( V_91 ) ;
}
int F_125 (
struct V_90 * V_91 )
{
unsigned long V_71 ;
F_39 ( & V_91 -> V_102 , V_71 ) ;
V_91 -> V_95 |= V_110 ;
F_40 ( & V_91 -> V_102 , V_71 ) ;
F_71 ( & V_91 -> V_119 , F_177 ) ;
F_72 ( V_91 -> V_94 -> V_372 , & V_91 -> V_119 ) ;
return 0 ;
}
