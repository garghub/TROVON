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
int F_21 ( struct V_2 * V_32 ,
unsigned int V_40 , unsigned int V_41 )
{
int V_42 ;
V_32 -> V_43 = F_22 ( V_40 * V_41 ,
V_33 | V_44 | V_45 ) ;
if ( ! V_32 -> V_43 ) {
V_32 -> V_43 = F_23 ( V_40 * V_41 ) ;
if ( ! V_32 -> V_43 ) {
F_4 ( L_26 ) ;
return - V_25 ;
}
}
V_42 = F_24 ( & V_32 -> V_46 , V_40 ) ;
if ( V_42 < 0 ) {
F_4 ( L_27
L_28 , V_40 ) ;
if ( F_25 ( V_32 -> V_43 ) )
F_26 ( V_32 -> V_43 ) ;
else
F_27 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
return - V_25 ;
}
return 0 ;
}
struct V_2 * F_28 ( unsigned int V_40 ,
unsigned int V_41 )
{
struct V_2 * V_32 ;
int V_42 ;
V_32 = F_15 () ;
if ( F_29 ( V_32 ) )
return V_32 ;
V_42 = F_21 ( V_32 , V_40 , V_41 ) ;
if ( V_42 < 0 ) {
F_30 ( V_32 ) ;
return F_17 ( - V_25 ) ;
}
return V_32 ;
}
void F_31 (
struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_2 * V_32 ,
void * V_51 )
{
unsigned char V_52 [ V_53 ] ;
V_32 -> V_48 = V_48 ;
V_32 -> V_51 = V_51 ;
if ( V_50 ) {
if ( V_48 -> V_54 -> V_55 != NULL ) {
memset ( & V_52 [ 0 ] , 0 , V_53 ) ;
V_48 -> V_54 -> V_55 ( V_32 ,
& V_52 [ 0 ] , V_53 ) ;
V_32 -> V_56 = F_32 ( & V_52 [ 0 ] ) ;
}
F_33 ( & V_50 -> V_57 ) ;
F_34 ( & V_50 -> V_58 ) ;
V_50 -> V_59 = V_32 ;
F_35 ( & V_32 -> V_35 ,
& V_50 -> V_60 ) ;
F_36 ( & V_50 -> V_58 ) ;
}
F_35 ( & V_32 -> V_34 , & V_48 -> V_61 ) ;
F_37 ( L_29 ,
V_48 -> V_54 -> V_62 () , V_32 -> V_51 ) ;
}
void F_38 (
struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_2 * V_32 ,
void * V_51 )
{
unsigned long V_63 ;
F_39 ( & V_48 -> V_64 , V_63 ) ;
F_31 ( V_48 , V_50 , V_32 , V_51 ) ;
F_40 ( & V_48 -> V_64 , V_63 ) ;
}
static void F_41 ( struct V_65 * V_65 )
{
struct V_2 * V_32 = F_42 ( V_65 ,
struct V_2 , V_39 ) ;
struct V_47 * V_48 = V_32 -> V_48 ;
V_48 -> V_54 -> V_66 ( V_32 ) ;
}
void F_43 ( struct V_2 * V_32 )
{
F_33 ( & V_32 -> V_39 ) ;
}
void F_44 ( struct V_2 * V_32 )
{
struct V_47 * V_67 = V_32 -> V_48 ;
if ( V_67 -> V_54 -> V_68 != NULL ) {
V_67 -> V_54 -> V_68 ( V_32 ) ;
return;
}
F_45 ( & V_32 -> V_39 , F_41 ) ;
}
static void F_46 ( struct V_65 * V_65 )
{
struct V_49 * V_69 = F_42 ( V_65 ,
struct V_49 , V_57 ) ;
F_47 ( & V_69 -> V_70 ) ;
}
void F_48 ( struct V_49 * V_69 )
{
F_45 ( & V_69 -> V_57 , F_46 ) ;
}
void F_49 ( struct V_2 * V_32 )
{
struct V_49 * V_50 ;
unsigned long V_63 ;
V_50 = V_32 -> V_49 ;
if ( V_50 ) {
F_39 ( & V_50 -> V_58 , V_63 ) ;
if ( V_50 -> V_71 == 0 )
F_50 ( & V_32 -> V_35 ) ;
if ( F_51 ( & V_50 -> V_60 ) )
V_50 -> V_59 = NULL ;
else {
V_50 -> V_59 = F_42 (
V_50 -> V_60 . V_72 ,
struct V_2 , V_35 ) ;
}
F_40 ( & V_50 -> V_58 , V_63 ) ;
}
}
void F_30 ( struct V_2 * V_32 )
{
if ( V_32 -> V_43 ) {
F_52 ( & V_32 -> V_46 ) ;
if ( F_25 ( V_32 -> V_43 ) )
F_26 ( V_32 -> V_43 ) ;
else
F_27 ( V_32 -> V_43 ) ;
}
F_53 ( V_1 , V_32 ) ;
}
void F_54 ( struct V_2 * V_32 )
{
struct V_47 * V_48 = V_32 -> V_48 ;
struct V_73 * V_74 ;
struct V_49 * V_50 ;
unsigned long V_63 ;
bool V_75 = true ;
if ( ! V_48 ) {
F_30 ( V_32 ) ;
return;
}
V_74 = V_48 -> V_54 ;
F_39 ( & V_48 -> V_64 , V_63 ) ;
F_50 ( & V_32 -> V_34 ) ;
V_32 -> V_48 = NULL ;
V_32 -> V_51 = NULL ;
F_40 ( & V_48 -> V_64 , V_63 ) ;
V_50 = V_32 -> V_49 ;
F_39 ( & V_48 -> V_76 , V_63 ) ;
if ( V_50 && V_50 -> V_77 ) {
if ( ! V_74 -> V_78 ( V_48 ) ) {
F_50 ( & V_50 -> V_79 ) ;
V_48 -> V_80 -- ;
F_40 ( & V_48 -> V_76 , V_63 ) ;
F_55 ( V_50 ) ;
F_56 ( V_50 , V_48 ) ;
V_74 -> V_81 ( V_48 , V_50 ) ;
V_75 = false ;
F_39 ( & V_48 -> V_76 , V_63 ) ;
}
}
F_40 ( & V_48 -> V_76 , V_63 ) ;
F_37 ( L_30 ,
V_48 -> V_54 -> V_62 () ) ;
if ( V_50 && V_75 == true )
F_48 ( V_50 ) ;
F_30 ( V_32 ) ;
}
static void F_57 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
unsigned long V_63 ;
if ( ! V_85 )
return;
if ( V_83 -> V_87 & V_88 )
return;
F_39 ( & V_85 -> V_89 , V_63 ) ;
if ( V_83 -> V_90 ) {
F_50 ( & V_83 -> V_91 ) ;
V_83 -> V_90 = false ;
}
F_40 ( & V_85 -> V_89 , V_63 ) ;
}
static int F_58 ( struct V_82 * V_83 , bool V_92 ,
bool V_93 )
{
unsigned long V_63 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_93 )
V_83 -> V_95 = V_96 ;
if ( V_83 -> V_87 & V_97 ) {
F_37 ( L_31 ,
V_98 , __LINE__ , V_83 -> V_74 -> V_99 ( V_83 ) ) ;
V_83 -> V_87 &= ~ V_100 ;
if ( V_92 )
F_57 ( V_83 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_101 ) ;
return 1 ;
}
if ( V_92 ) {
F_57 ( V_83 ) ;
V_83 -> V_102 = NULL ;
}
if ( V_83 -> V_87 & V_103 ) {
F_37 ( L_32 ,
V_98 , __LINE__ ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_104 ) ;
return 1 ;
}
V_83 -> V_87 &= ~ V_100 ;
if ( V_92 ) {
if ( V_83 -> V_74 -> V_105 != NULL ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return V_83 -> V_74 -> V_105 ( V_83 ) ;
}
}
F_40 ( & V_83 -> V_94 , V_63 ) ;
return 0 ;
}
static int F_59 ( struct V_82 * V_83 )
{
return F_58 ( V_83 , true , false ) ;
}
static void F_60 ( struct V_82 * V_83 )
{
struct V_102 * V_106 = V_83 -> V_102 ;
unsigned long V_63 ;
if ( ! V_106 )
return;
F_39 ( & V_106 -> V_107 , V_63 ) ;
if ( ! F_51 ( & V_83 -> V_108 ) )
F_61 ( & V_83 -> V_108 ) ;
F_40 ( & V_106 -> V_107 , V_63 ) ;
}
void F_62 ( struct V_82 * V_83 , int remove )
{
if ( F_59 ( V_83 ) )
return;
if ( remove )
F_63 ( V_83 ) ;
}
static void F_64 ( struct V_109 * V_110 )
{
struct V_82 * V_83 = F_42 ( V_110 , struct V_82 , V_110 ) ;
F_65 ( V_83 ,
V_111 ) ;
}
static unsigned char * F_66 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
F_67 ( ! V_83 -> V_102 ) ;
if ( ! V_85 )
return NULL ;
if ( V_83 -> V_112 & V_113 )
return NULL ;
V_83 -> V_114 = V_115 ;
F_37 ( L_33 ,
V_85 -> V_116 -> V_117 , V_85 -> V_118 -> V_119 , V_83 -> V_120 ) ;
return V_83 -> V_121 ;
}
void F_68 ( struct V_82 * V_83 , T_3 V_120 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
int V_122 = V_120 == V_123 ;
unsigned long V_63 ;
V_83 -> V_120 = V_120 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
V_83 -> V_87 &= ~ V_88 ;
if ( V_85 && V_85 -> V_118 -> V_124 ) {
V_85 -> V_118 -> V_124 ( V_83 ,
V_83 -> V_125 ,
F_66 ( V_83 ) ) ;
if ( V_83 -> V_112 & V_126 )
V_122 = 1 ;
}
if ( V_83 -> V_87 & V_127 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_128 ) ;
return;
}
if ( ! V_122 )
V_83 -> V_87 |= V_129 ;
if ( V_83 -> V_87 & V_130 &&
V_83 -> V_87 & V_103 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_104 ) ;
return;
} else if ( V_83 -> V_87 & V_129 ) {
F_69 ( & V_83 -> V_110 , F_64 ) ;
} else {
F_69 ( & V_83 -> V_110 , V_131 ) ;
}
V_83 -> V_95 = V_132 ;
V_83 -> V_87 |= ( V_133 | V_100 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_70 ( V_22 , & V_83 -> V_110 ) ;
}
static void F_71 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
unsigned long V_63 ;
F_39 ( & V_85 -> V_89 , V_63 ) ;
if ( ! V_83 -> V_90 ) {
F_35 ( & V_83 -> V_91 , & V_85 -> V_91 ) ;
V_83 -> V_90 = true ;
}
F_40 ( & V_85 -> V_89 , V_63 ) ;
}
void F_72 ( struct V_109 * V_110 )
{
struct V_84 * V_85 = F_42 ( V_110 , struct V_84 ,
V_134 ) ;
F_73 ( V_135 ) ;
struct V_82 * V_83 , * V_136 ;
F_34 ( & V_85 -> V_137 ) ;
F_74 ( & V_85 -> V_135 , & V_135 ) ;
F_36 ( & V_85 -> V_137 ) ;
F_75 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_50 ( & V_83 -> V_138 ) ;
F_76 ( & V_85 -> V_139 ) ;
F_77 () ;
F_37 ( L_34
L_35 , V_83 -> V_74 -> V_62 () , V_83 ,
( V_83 -> V_95 == V_140 ) ? L_36 :
( V_83 -> V_95 == V_141 ) ? L_37
: L_38 ) ;
if ( V_83 -> V_95 == V_141 )
F_78 ( V_83 ) ;
else if ( V_83 -> V_95 == V_140 )
F_79 ( V_83 ) ;
}
}
unsigned char * F_80 ( struct V_82 * V_83 )
{
switch ( V_83 -> V_142 ) {
case V_143 :
return L_39 ;
case V_144 :
return L_40 ;
case V_145 :
return L_41 ;
case V_146 :
return L_42 ;
default:
break;
}
return L_38 ;
}
void F_81 (
struct V_84 * V_85 ,
char * V_147 ,
int * V_148 )
{
* V_148 += sprintf ( V_147 + * V_148 , L_43 ) ;
if ( V_85 -> V_149 )
* V_148 += sprintf ( V_147 + * V_148 , L_44 ) ;
else
* V_148 += sprintf ( V_147 + * V_148 , L_45 ) ;
* V_148 += sprintf ( V_147 + * V_148 , L_46 , V_85 -> V_150 ) ;
* V_148 += sprintf ( V_147 + * V_148 , L_47 ,
V_85 -> V_151 . V_152 ,
V_85 -> V_151 . V_153 ) ;
* V_148 += sprintf ( V_147 + * V_148 , L_48 ) ;
}
void F_82 (
struct V_154 * V_155 ,
unsigned char * V_156 ,
int V_157 )
{
unsigned char V_52 [ V_158 ] ;
int V_159 ;
memset ( V_52 , 0 , V_158 ) ;
V_159 = sprintf ( V_52 , L_49 ) ;
switch ( V_155 -> V_160 ) {
case 0x00 :
sprintf ( V_52 + V_159 , L_50 ) ;
break;
case 0x10 :
sprintf ( V_52 + V_159 , L_51 ) ;
break;
case 0x20 :
sprintf ( V_52 + V_159 , L_52 ) ;
break;
case 0x30 :
sprintf ( V_52 + V_159 , L_53 ) ;
break;
case 0x40 :
sprintf ( V_52 + V_159 , L_54
L_55 ) ;
break;
case 0x50 :
sprintf ( V_52 + V_159 , L_56 ) ;
break;
case 0x60 :
sprintf ( V_52 + V_159 , L_57 ) ;
break;
case 0x70 :
sprintf ( V_52 + V_159 , L_58
L_55 ) ;
break;
case 0x80 :
sprintf ( V_52 + V_159 , L_59 ) ;
break;
default:
sprintf ( V_52 + V_159 , L_60 ,
V_155 -> V_160 ) ;
break;
}
if ( V_156 )
strncpy ( V_156 , V_52 , V_157 ) ;
else
F_37 ( L_61 , V_52 ) ;
}
void
F_83 ( struct V_154 * V_155 , unsigned char * V_161 )
{
if ( V_161 [ 1 ] & 0x80 ) {
V_155 -> V_160 = ( V_161 [ 0 ] & 0xf0 ) ;
V_155 -> V_162 = 1 ;
F_82 ( V_155 , NULL , 0 ) ;
}
}
int F_84 (
struct V_154 * V_155 ,
unsigned char * V_156 ,
int V_157 )
{
unsigned char V_52 [ V_158 ] ;
int V_30 = 0 ;
int V_159 ;
memset ( V_52 , 0 , V_158 ) ;
V_159 = sprintf ( V_52 , L_62 ) ;
switch ( V_155 -> V_163 ) {
case 0x00 :
sprintf ( V_52 + V_159 , L_63 ) ;
break;
case 0x10 :
sprintf ( V_52 + V_159 , L_64 ) ;
break;
case 0x20 :
sprintf ( V_52 + V_159 , L_65 ) ;
break;
default:
sprintf ( V_52 + V_159 , L_60 , V_155 -> V_163 ) ;
V_30 = - V_164 ;
break;
}
if ( V_156 )
strncpy ( V_156 , V_52 , V_157 ) ;
else
F_37 ( L_61 , V_52 ) ;
return V_30 ;
}
int F_85 ( struct V_154 * V_155 , unsigned char * V_161 )
{
V_155 -> V_163 = ( V_161 [ 1 ] & 0x30 ) ;
return F_84 ( V_155 , NULL , 0 ) ;
}
int F_86 (
struct V_154 * V_155 ,
unsigned char * V_156 ,
int V_157 )
{
unsigned char V_52 [ V_158 ] ;
int V_30 = 0 ;
int V_159 ;
memset ( V_52 , 0 , V_158 ) ;
V_159 = sprintf ( V_52 , L_66 ) ;
switch ( V_155 -> V_165 ) {
case 0x00 :
sprintf ( V_52 + V_159 , L_67 ) ;
break;
case 0x01 :
sprintf ( V_52 + V_159 , L_68 ) ;
break;
case 0x02 :
sprintf ( V_52 + V_159 , L_69 ) ;
break;
case 0x03 :
sprintf ( V_52 + V_159 , L_70 ) ;
break;
case 0x04 :
sprintf ( V_52 + V_159 , L_71 ) ;
break;
case 0x08 :
sprintf ( V_52 + V_159 , L_72 ) ;
break;
default:
sprintf ( V_52 + V_159 , L_73 ,
V_155 -> V_165 ) ;
V_30 = - V_164 ;
break;
}
if ( V_156 ) {
if ( V_157 < strlen ( V_52 ) + 1 )
return - V_164 ;
strncpy ( V_156 , V_52 , V_157 ) ;
} else {
F_37 ( L_61 , V_52 ) ;
}
return V_30 ;
}
int F_87 ( struct V_154 * V_155 , unsigned char * V_161 )
{
V_155 -> V_165 = ( V_161 [ 1 ] & 0x0f ) ;
return F_86 ( V_155 , NULL , 0 ) ;
}
int F_88 (
struct V_154 * V_155 ,
unsigned char * V_156 ,
int V_157 )
{
unsigned char V_52 [ V_158 ] ;
int V_30 = 0 ;
memset ( V_52 , 0 , V_158 ) ;
switch ( V_155 -> V_166 ) {
case 0x01 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_74 ,
& V_155 -> V_167 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_75 ,
& V_155 -> V_167 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_76 ,
& V_155 -> V_167 [ 0 ] ) ;
break;
default:
sprintf ( V_52 , L_77
L_78 , V_155 -> V_166 ) ;
V_30 = - V_164 ;
break;
}
if ( V_156 )
strncpy ( V_156 , V_52 , V_157 ) ;
else
F_37 ( L_61 , V_52 ) ;
return V_30 ;
}
int
F_89 ( struct V_154 * V_155 , unsigned char * V_161 )
{
static const char V_168 [] = L_79 ;
int V_169 = 0 , V_170 = 4 ;
V_155 -> V_166 = ( V_161 [ 0 ] & 0x0f ) ;
switch ( V_155 -> V_166 ) {
case 0x01 :
V_155 -> V_167 [ V_169 ++ ] =
V_168 [ V_155 -> V_165 ] ;
while ( V_170 < ( 4 + V_161 [ 3 ] ) ) {
V_155 -> V_167 [ V_169 ++ ] =
V_168 [ ( V_161 [ V_170 ] & 0xf0 ) >> 4 ] ;
V_155 -> V_167 [ V_169 ++ ] =
V_168 [ V_161 [ V_170 ] & 0x0f ] ;
V_170 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_170 < ( 4 + V_161 [ 3 ] ) )
V_155 -> V_167 [ V_169 ++ ] = V_161 [ V_170 ++ ] ;
break;
default:
break;
}
return F_88 ( V_155 , NULL , 0 ) ;
}
T_4
F_90 ( struct V_82 * V_83 , unsigned int V_171 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_83 -> V_172 ) {
V_83 -> V_173 = V_171 ;
} else if ( V_171 != V_83 -> V_173 ) {
F_91 ( L_80
L_81
L_82 , V_83 -> V_74 -> V_62 () ,
V_83 -> V_173 , V_171 , V_83 -> V_174 [ 0 ] ) ;
if ( V_83 -> V_142 == V_145 ) {
F_4 ( L_83
L_84 ) ;
return V_175 ;
}
if ( V_85 -> V_151 . V_152 != 512 ) {
F_4 ( L_85
L_86
L_87 , V_85 -> V_118 -> V_119 ) ;
return V_175 ;
}
if ( V_171 > V_83 -> V_173 ) {
V_83 -> V_112 |= V_176 ;
V_83 -> V_177 = ( V_171 - V_83 -> V_173 ) ;
} else {
V_83 -> V_112 |= V_178 ;
V_83 -> V_177 = ( V_83 -> V_173 - V_171 ) ;
V_83 -> V_173 = V_171 ;
}
}
return 0 ;
}
void F_92 (
struct V_82 * V_83 ,
struct V_73 * V_179 ,
struct V_2 * V_32 ,
T_1 V_173 ,
int V_142 ,
int V_180 ,
unsigned char * V_121 )
{
F_18 ( & V_83 -> V_108 ) ;
F_18 ( & V_83 -> V_181 ) ;
F_18 ( & V_83 -> V_138 ) ;
F_18 ( & V_83 -> V_182 ) ;
F_18 ( & V_83 -> V_91 ) ;
F_93 ( & V_83 -> V_183 ) ;
F_93 ( & V_83 -> V_101 ) ;
F_93 ( & V_83 -> V_104 ) ;
F_93 ( & V_83 -> V_184 ) ;
F_93 ( & V_83 -> V_128 ) ;
F_19 ( & V_83 -> V_94 ) ;
V_83 -> V_87 = V_185 ;
V_83 -> V_74 = V_179 ;
V_83 -> V_32 = V_32 ;
V_83 -> V_173 = V_173 ;
V_83 -> V_142 = V_142 ;
V_83 -> V_186 = V_180 ;
V_83 -> V_121 = V_121 ;
V_83 -> V_90 = false ;
}
static T_4
F_94 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_118 -> V_187 == V_188 )
return 0 ;
if ( V_83 -> V_186 == V_189 ) {
F_37 ( L_88
L_89 ) ;
return V_175 ;
}
V_83 -> V_190 = F_95 ( & V_85 -> V_191 ) ;
F_96 () ;
F_37 ( L_90 ,
V_83 -> V_190 , V_83 -> V_186 ,
V_85 -> V_118 -> V_119 ) ;
return 0 ;
}
T_4
F_97 ( struct V_82 * V_83 , unsigned char * V_192 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
T_4 V_30 ;
if ( F_98 ( V_192 ) > V_193 ) {
F_4 ( L_91
L_92 ,
F_98 ( V_192 ) , V_193 ) ;
return V_175 ;
}
if ( F_98 ( V_192 ) > sizeof( V_83 -> V_194 ) ) {
V_83 -> V_174 = F_22 ( F_98 ( V_192 ) ,
V_33 ) ;
if ( ! V_83 -> V_174 ) {
F_4 ( L_93
L_94 ,
F_98 ( V_192 ) ,
( unsigned long ) sizeof( V_83 -> V_194 ) ) ;
return V_195 ;
}
} else
V_83 -> V_174 = & V_83 -> V_194 [ 0 ] ;
memcpy ( V_83 -> V_174 , V_192 , F_98 ( V_192 ) ) ;
F_99 ( V_83 ) ;
V_30 = F_100 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_101 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_102 ( V_83 ) ;
if ( V_30 ) {
V_83 -> V_120 = V_196 ;
return V_30 ;
}
V_30 = V_85 -> V_118 -> V_197 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_94 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_83 -> V_112 |= V_198 ;
F_11 ( & V_83 -> V_102 -> V_199 ) ;
if ( V_83 -> V_102 -> V_200 )
V_83 -> V_102 -> V_200 -> V_201 . V_202 ++ ;
F_12 ( & V_83 -> V_102 -> V_199 ) ;
return 0 ;
}
int F_103 (
struct V_82 * V_83 )
{
T_4 V_30 ;
if ( ! V_83 -> V_102 ) {
F_104 () ;
F_4 ( L_95 ) ;
return - V_164 ;
}
if ( F_105 () ) {
F_104 () ;
F_4 ( L_96
L_97 ) ;
return - V_164 ;
}
V_83 -> V_95 = V_203 ;
V_83 -> V_87 |= V_100 ;
V_30 = F_106 ( V_83 ) ;
if ( V_30 )
F_65 ( V_83 , V_30 ) ;
return 0 ;
}
T_4
F_107 ( struct V_82 * V_83 , struct V_204 * V_205 ,
T_1 V_206 , struct V_204 * V_207 , T_1 V_208 )
{
if ( ! V_205 || ! V_206 )
return 0 ;
if ( V_83 -> V_112 & V_176 ) {
F_91 ( L_98
L_99 ) ;
return V_175 ;
}
V_83 -> V_125 = V_205 ;
V_83 -> V_209 = V_206 ;
if ( V_207 && V_208 ) {
V_83 -> V_210 = V_207 ;
V_83 -> V_211 = V_208 ;
}
V_83 -> V_112 |= V_212 ;
return 0 ;
}
int F_108 ( struct V_82 * V_82 , struct V_2 * V_32 ,
unsigned char * V_192 , unsigned char * V_213 , T_1 V_214 ,
T_1 V_173 , int V_180 , int V_215 , int V_63 ,
struct V_204 * V_205 , T_1 V_206 ,
struct V_204 * V_207 , T_1 V_208 )
{
struct V_47 * V_48 ;
T_4 V_42 ;
int V_30 ;
V_48 = V_32 -> V_48 ;
F_10 ( ! V_48 ) ;
F_10 ( V_82 -> V_74 || V_82 -> V_32 ) ;
F_10 ( F_105 () ) ;
F_92 ( V_82 , V_48 -> V_54 , V_32 ,
V_173 , V_215 , V_180 , V_213 ) ;
if ( V_63 & V_216 )
V_82 -> V_172 = 1 ;
V_30 = F_109 ( V_32 , V_82 , ( V_63 & V_217 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_63 & V_218 )
V_82 -> V_112 |= V_219 ;
V_42 = F_110 ( V_82 , V_214 ) ;
if ( V_42 ) {
F_111 ( V_82 , V_42 , 0 ) ;
F_112 ( V_32 , V_82 ) ;
return 0 ;
}
V_42 = F_97 ( V_82 , V_192 ) ;
if ( V_42 != 0 ) {
F_65 ( V_82 , V_42 ) ;
return 0 ;
}
if ( V_206 != 0 ) {
F_10 ( ! V_205 ) ;
if ( ! ( V_82 -> V_112 & V_220 ) &&
V_82 -> V_142 == V_144 ) {
unsigned char * V_52 = NULL ;
if ( V_205 )
V_52 = F_113 ( F_114 ( V_205 ) ) + V_205 -> V_221 ;
if ( V_52 ) {
memset ( V_52 , 0 , V_205 -> V_222 ) ;
F_115 ( F_114 ( V_205 ) ) ;
}
}
V_42 = F_107 ( V_82 , V_205 , V_206 ,
V_207 , V_208 ) ;
if ( V_42 != 0 ) {
F_65 ( V_82 , V_42 ) ;
return 0 ;
}
}
F_116 ( V_82 ) ;
F_103 ( V_82 ) ;
return 0 ;
}
int F_117 ( struct V_82 * V_82 , struct V_2 * V_32 ,
unsigned char * V_192 , unsigned char * V_213 , T_1 V_214 ,
T_1 V_173 , int V_180 , int V_215 , int V_63 )
{
return F_108 ( V_82 , V_32 , V_192 , V_213 ,
V_214 , V_173 , V_180 , V_215 ,
V_63 , NULL , 0 , NULL , 0 ) ;
}
static void F_118 ( struct V_109 * V_110 )
{
struct V_82 * V_82 = F_42 ( V_110 , struct V_82 , V_110 ) ;
V_82 -> V_223 -> V_224 = V_225 ;
V_82 -> V_74 -> V_226 ( V_82 ) ;
F_59 ( V_82 ) ;
}
int F_119 ( struct V_82 * V_82 , struct V_2 * V_32 ,
unsigned char * V_213 , T_1 V_214 ,
void * V_227 , unsigned char V_228 ,
T_5 V_229 , unsigned int V_230 , int V_63 )
{
struct V_47 * V_48 ;
int V_30 ;
V_48 = V_32 -> V_48 ;
F_10 ( ! V_48 ) ;
F_92 ( V_82 , V_48 -> V_54 , V_32 ,
0 , V_143 , V_231 , V_213 ) ;
V_30 = F_120 ( V_82 , V_227 , V_228 , V_229 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_228 == V_232 )
V_82 -> V_223 -> V_233 = V_230 ;
V_30 = F_109 ( V_32 , V_82 , ( V_63 & V_217 ) ) ;
if ( V_30 ) {
F_121 ( V_82 -> V_223 ) ;
return V_30 ;
}
V_30 = F_122 ( V_82 , V_214 ) ;
if ( V_30 ) {
F_69 ( & V_82 -> V_110 , F_118 ) ;
F_123 ( & V_82 -> V_110 ) ;
return 0 ;
}
F_124 ( V_82 ) ;
return 0 ;
}
bool F_125 ( struct V_82 * V_83 , unsigned long * V_63 )
{
bool V_234 = false ;
if ( V_83 -> V_87 & V_88 ) {
V_83 -> V_87 |= V_127 ;
F_40 ( & V_83 -> V_94 , * V_63 ) ;
F_37 ( L_100 , V_83 ) ;
F_126 ( & V_83 -> V_128 ) ;
F_37 ( L_101 , V_83 ) ;
F_39 ( & V_83 -> V_94 , * V_63 ) ;
V_83 -> V_87 &= ~ V_127 ;
V_83 -> V_87 &= ~ V_88 ;
V_234 = true ;
}
return V_234 ;
}
void F_65 ( struct V_82 * V_83 ,
T_4 V_235 )
{
int V_30 = 0 ;
F_37 ( L_102
L_103 , V_83 , V_83 -> V_74 -> V_99 ( V_83 ) ,
V_83 -> V_174 [ 0 ] ) ;
F_37 ( L_104 ,
V_83 -> V_74 -> V_236 ( V_83 ) ,
V_83 -> V_95 , V_235 ) ;
F_37 ( L_105 ,
( V_83 -> V_87 & V_100 ) != 0 ,
( V_83 -> V_87 & V_103 ) != 0 ,
( V_83 -> V_87 & V_237 ) != 0 ) ;
F_127 ( V_83 ) ;
if ( ( V_83 -> V_112 & V_238 ) &&
V_83 -> V_239 )
V_83 -> V_239 ( V_83 ) ;
switch ( V_235 ) {
case V_240 :
case V_241 :
case V_175 :
case V_242 :
case V_243 :
case V_111 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
break;
case V_195 :
V_235 = V_111 ;
break;
case V_250 :
V_83 -> V_120 = V_196 ;
if ( V_83 -> V_32 &&
V_83 -> V_86 -> V_151 . V_251 == 2 )
F_128 ( V_83 -> V_32 -> V_49 ,
V_83 -> V_252 , 0x2C ,
V_253 ) ;
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_254 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
goto V_257;
default:
F_4 ( L_106 ,
V_83 -> V_174 [ 0 ] , V_235 ) ;
V_235 = V_241 ;
break;
}
V_30 = F_111 ( V_83 , V_235 , 0 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
V_257:
F_60 ( V_83 ) ;
if ( ! F_59 ( V_83 ) )
;
return;
V_256:
V_83 -> V_95 = V_140 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
void F_131 ( struct V_82 * V_83 )
{
T_4 V_30 ;
if ( V_83 -> V_258 ) {
V_30 = V_83 -> V_258 ( V_83 ) ;
if ( V_30 ) {
F_34 ( & V_83 -> V_94 ) ;
V_83 -> V_87 &= ~ ( V_88 | V_237 ) ;
F_36 ( & V_83 -> V_94 ) ;
F_65 ( V_83 , V_30 ) ;
}
}
}
static bool F_132 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_118 -> V_187 == V_188 )
return false ;
switch ( V_83 -> V_186 ) {
case V_259 :
F_37 ( L_107
L_108 ,
V_83 -> V_174 [ 0 ] , V_83 -> V_190 ) ;
return false ;
case V_260 :
F_133 ( & V_85 -> V_261 ) ;
F_96 () ;
F_37 ( L_109
L_110 ,
V_83 -> V_174 [ 0 ] , V_83 -> V_190 ) ;
if ( ! F_134 ( & V_85 -> V_262 ) )
return false ;
break;
default:
F_133 ( & V_85 -> V_262 ) ;
F_96 () ;
break;
}
if ( F_134 ( & V_85 -> V_261 ) == 0 )
return false ;
F_11 ( & V_85 -> V_263 ) ;
F_35 ( & V_83 -> V_181 , & V_85 -> V_264 ) ;
F_12 ( & V_85 -> V_263 ) ;
F_37 ( L_111
L_112 ,
V_83 -> V_174 [ 0 ] , V_83 -> V_186 ,
V_83 -> V_190 ) ;
return true ;
}
void F_135 ( struct V_82 * V_83 )
{
if ( F_136 ( V_83 , 1 ) ) {
F_47 ( & V_83 -> V_101 ) ;
return;
}
F_34 ( & V_83 -> V_94 ) ;
if ( V_83 -> V_87 & V_97 ) {
F_37 ( L_31 ,
V_98 , __LINE__ , V_83 -> V_74 -> V_99 ( V_83 ) ) ;
V_83 -> V_87 &= ~ V_100 ;
F_36 ( & V_83 -> V_94 ) ;
F_47 ( & V_83 -> V_101 ) ;
return;
}
if ( V_83 -> V_87 & V_103 ) {
F_37 ( L_32 ,
V_98 , __LINE__ ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_36 ( & V_83 -> V_94 ) ;
F_47 ( & V_83 -> V_104 ) ;
return;
}
V_83 -> V_95 = V_265 ;
V_83 -> V_87 |= V_100 | V_88 | V_237 ;
F_36 ( & V_83 -> V_94 ) ;
if ( F_132 ( V_83 ) ) {
F_34 ( & V_83 -> V_94 ) ;
V_83 -> V_87 &= ~ V_88 | V_237 ;
F_36 ( & V_83 -> V_94 ) ;
return;
}
F_131 ( V_83 ) ;
}
static void F_137 ( struct V_84 * V_85 )
{
for (; ; ) {
struct V_82 * V_83 ;
F_11 ( & V_85 -> V_263 ) ;
if ( F_51 ( & V_85 -> V_264 ) ) {
F_12 ( & V_85 -> V_263 ) ;
break;
}
V_83 = F_138 ( V_85 -> V_264 . V_266 ,
struct V_82 , V_181 ) ;
F_50 ( & V_83 -> V_181 ) ;
F_12 ( & V_85 -> V_263 ) ;
F_131 ( V_83 ) ;
if ( V_83 -> V_186 == V_260 )
break;
}
}
static void F_127 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_118 -> V_187 == V_188 )
return;
if ( V_83 -> V_186 == V_231 ) {
F_76 ( & V_85 -> V_262 ) ;
F_77 () ;
V_85 -> V_267 ++ ;
F_37 ( L_113
L_114 , V_85 -> V_267 ,
V_83 -> V_190 ) ;
} else if ( V_83 -> V_186 == V_259 ) {
V_85 -> V_267 ++ ;
F_37 ( L_115
L_116 , V_85 -> V_267 ,
V_83 -> V_190 ) ;
} else if ( V_83 -> V_186 == V_260 ) {
F_76 ( & V_85 -> V_261 ) ;
F_77 () ;
V_85 -> V_267 ++ ;
F_37 ( L_117
L_118 , V_85 -> V_267 , V_83 -> V_190 ) ;
}
F_137 ( V_85 ) ;
}
static void F_79 ( struct V_82 * V_83 )
{
int V_30 = 0 ;
F_127 ( V_83 ) ;
if ( V_83 -> V_112 & V_126 ) {
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_254 ( V_83 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_83 -> V_142 ) {
case V_144 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_268 ( V_83 ) ;
break;
case V_145 :
if ( V_83 -> V_112 & V_219 ) {
V_30 = V_83 -> V_74 -> V_268 ( V_83 ) ;
if ( V_30 < 0 )
break;
}
case V_143 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_254 ( V_83 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_130 ( V_83 , V_83 -> V_86 ) ;
return;
}
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
}
static void F_130 (
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
F_34 ( & V_85 -> V_137 ) ;
F_35 ( & V_83 -> V_138 , & V_83 -> V_86 -> V_135 ) ;
F_133 ( & V_85 -> V_139 ) ;
F_96 () ;
F_36 ( & V_83 -> V_86 -> V_137 ) ;
F_123 ( & V_83 -> V_86 -> V_134 ) ;
}
static void V_131 ( struct V_109 * V_110 )
{
struct V_82 * V_83 = F_42 ( V_110 , struct V_82 , V_110 ) ;
int V_30 ;
F_127 ( V_83 ) ;
if ( F_134 ( & V_83 -> V_86 -> V_139 ) != 0 )
F_123 ( & V_83 -> V_86 -> V_134 ) ;
if ( V_83 -> V_112 & V_126 ) {
F_67 ( ! V_83 -> V_120 ) ;
V_30 = F_111 (
V_83 , 0 , 1 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
}
if ( V_83 -> V_239 ) {
T_4 V_42 ;
V_42 = V_83 -> V_239 ( V_83 ) ;
if ( ! V_42 && ! ( V_83 -> V_112 & V_269 ) ) {
return;
} else if ( V_42 ) {
V_30 = F_111 ( V_83 ,
V_42 , 0 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
}
}
switch ( V_83 -> V_142 ) {
case V_144 :
F_11 ( & V_83 -> V_102 -> V_199 ) ;
if ( V_83 -> V_102 -> V_200 ) {
V_83 -> V_102 -> V_200 -> V_201 . V_270 +=
V_83 -> V_173 ;
}
F_12 ( & V_83 -> V_102 -> V_199 ) ;
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_268 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
break;
case V_145 :
F_11 ( & V_83 -> V_102 -> V_199 ) ;
if ( V_83 -> V_102 -> V_200 ) {
V_83 -> V_102 -> V_200 -> V_201 . V_271 +=
V_83 -> V_173 ;
}
F_12 ( & V_83 -> V_102 -> V_199 ) ;
if ( V_83 -> V_112 & V_219 ) {
F_11 ( & V_83 -> V_102 -> V_199 ) ;
if ( V_83 -> V_102 -> V_200 ) {
V_83 -> V_102 -> V_200 -> V_201 . V_270 +=
V_83 -> V_173 ;
}
F_12 ( & V_83 -> V_102 -> V_199 ) ;
V_30 = V_83 -> V_74 -> V_268 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
break;
}
case V_143 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_254 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
break;
default:
break;
}
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
V_256:
F_37 ( L_119
L_120 , V_83 , V_83 -> V_142 ) ;
V_83 -> V_95 = V_140 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
static inline void F_139 ( struct V_204 * V_205 , int V_272 )
{
struct V_204 * V_273 ;
int V_274 ;
F_140 (sgl, sg, nents, count)
F_141 ( F_114 ( V_273 ) ) ;
F_27 ( V_205 ) ;
}
static inline void F_142 ( struct V_82 * V_83 )
{
if ( ! V_83 -> V_275 )
return;
F_27 ( V_83 -> V_125 ) ;
V_83 -> V_125 = V_83 -> V_275 ;
V_83 -> V_275 = NULL ;
V_83 -> V_209 = V_83 -> V_276 ;
V_83 -> V_276 = 0 ;
}
static inline void F_143 ( struct V_82 * V_83 )
{
if ( V_83 -> V_112 & V_212 ) {
F_142 ( V_83 ) ;
return;
}
F_142 ( V_83 ) ;
F_139 ( V_83 -> V_125 , V_83 -> V_209 ) ;
V_83 -> V_125 = NULL ;
V_83 -> V_209 = 0 ;
F_139 ( V_83 -> V_210 , V_83 -> V_211 ) ;
V_83 -> V_210 = NULL ;
V_83 -> V_211 = 0 ;
}
static int F_144 ( struct V_82 * V_83 )
{
F_10 ( ! V_83 -> V_74 ) ;
if ( V_83 -> V_112 & V_277 )
F_121 ( V_83 -> V_223 ) ;
if ( V_83 -> V_174 != V_83 -> V_194 )
F_27 ( V_83 -> V_174 ) ;
return F_112 ( V_83 -> V_32 , V_83 ) ;
}
static int F_63 ( struct V_82 * V_83 )
{
F_143 ( V_83 ) ;
return F_144 ( V_83 ) ;
}
void * F_145 ( struct V_82 * V_83 )
{
struct V_204 * V_273 = V_83 -> V_125 ;
struct V_278 * * V_279 ;
int V_170 ;
if ( ! V_83 -> V_209 )
return NULL ;
F_10 ( ! V_273 ) ;
if ( V_83 -> V_209 == 1 )
return F_113 ( F_114 ( V_273 ) ) + V_273 -> V_221 ;
V_279 = F_146 ( sizeof( * V_279 ) * V_83 -> V_209 , V_33 ) ;
if ( ! V_279 )
return NULL ;
F_140 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_279 [ V_170 ] = F_114 ( V_273 ) ;
}
V_83 -> V_280 = F_147 ( V_279 , V_83 -> V_209 , V_281 , V_282 ) ;
F_27 ( V_279 ) ;
if ( ! V_83 -> V_280 )
return NULL ;
return V_83 -> V_280 + V_83 -> V_125 [ 0 ] . V_221 ;
}
void F_148 ( struct V_82 * V_83 )
{
if ( ! V_83 -> V_209 ) {
return;
} else if ( V_83 -> V_209 == 1 ) {
F_115 ( F_114 ( V_83 -> V_125 ) ) ;
return;
}
F_149 ( V_83 -> V_280 ) ;
V_83 -> V_280 = NULL ;
}
int
F_150 ( struct V_204 * * V_205 , unsigned int * V_272 , T_1 V_222 ,
bool V_283 )
{
struct V_204 * V_273 ;
struct V_278 * V_278 ;
T_5 V_284 = ( V_283 ) ? V_285 : 0 ;
unsigned int V_286 ;
int V_170 = 0 ;
V_286 = F_151 ( V_222 , V_287 ) ;
V_273 = F_146 ( sizeof( struct V_204 ) * V_286 , V_33 ) ;
if ( ! V_273 )
return - V_25 ;
F_152 ( V_273 , V_286 ) ;
while ( V_222 ) {
T_1 V_288 = F_153 ( T_1 , V_222 , V_287 ) ;
V_278 = F_154 ( V_33 | V_284 ) ;
if ( ! V_278 )
goto V_3;
F_155 ( & V_273 [ V_170 ] , V_278 , V_288 , 0 ) ;
V_222 -= V_288 ;
V_170 ++ ;
}
* V_205 = V_273 ;
* V_272 = V_286 ;
return 0 ;
V_3:
while ( V_170 > 0 ) {
V_170 -- ;
F_141 ( F_114 ( & V_273 [ V_170 ] ) ) ;
}
F_27 ( V_273 ) ;
return - V_25 ;
}
T_4
F_106 ( struct V_82 * V_83 )
{
int V_30 = 0 ;
if ( ! ( V_83 -> V_112 & V_212 ) &&
V_83 -> V_173 ) {
bool V_284 = ! ( V_83 -> V_112 & V_220 ) ;
if ( ( V_83 -> V_112 & V_219 ) ||
( V_83 -> V_112 & V_238 ) ) {
T_1 V_289 ;
if ( V_83 -> V_112 & V_238 )
V_289 = V_83 -> V_290 *
V_83 -> V_86 -> V_151 . V_152 ;
else
V_289 = V_83 -> V_173 ;
V_30 = F_150 ( & V_83 -> V_210 ,
& V_83 -> V_211 ,
V_289 , V_284 ) ;
if ( V_30 < 0 )
return V_111 ;
}
V_30 = F_150 ( & V_83 -> V_125 , & V_83 -> V_209 ,
V_83 -> V_173 , V_284 ) ;
if ( V_30 < 0 )
return V_111 ;
}
F_71 ( V_83 ) ;
if ( V_83 -> V_142 != V_145 ) {
F_135 ( V_83 ) ;
return 0 ;
}
F_58 ( V_83 , false , true ) ;
V_30 = V_83 -> V_74 -> V_93 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 )
goto V_256;
F_67 ( V_30 ) ;
return ( ! V_30 ) ? 0 : V_111 ;
V_256:
F_37 ( L_121 , V_83 ) ;
V_83 -> V_95 = V_141 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
return 0 ;
}
static void F_78 ( struct V_82 * V_83 )
{
int V_30 ;
V_30 = V_83 -> V_74 -> V_93 ( V_83 ) ;
if ( V_30 == - V_255 || V_30 == - V_25 ) {
F_37 ( L_121 ,
V_83 ) ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
}
int F_156 ( struct V_82 * V_83 , int V_291 )
{
unsigned long V_63 ;
int V_30 = 0 ;
if ( ! ( V_83 -> V_112 & V_292 ) ) {
if ( V_291 && ( V_83 -> V_112 & V_277 ) )
F_157 ( V_83 ) ;
V_30 = F_144 ( V_83 ) ;
} else {
if ( V_291 )
F_157 ( V_83 ) ;
if ( V_83 -> V_90 ) {
F_39 ( & V_83 -> V_94 , V_63 ) ;
F_57 ( V_83 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
}
if ( V_83 -> V_102 )
F_60 ( V_83 ) ;
V_30 = F_63 ( V_83 ) ;
}
return V_30 ;
}
int F_109 ( struct V_2 * V_32 , struct V_82 * V_82 ,
bool V_293 )
{
unsigned long V_63 ;
int V_30 = 0 ;
F_20 ( & V_82 -> V_294 ) ;
if ( V_293 == true ) {
F_33 ( & V_82 -> V_294 ) ;
V_82 -> V_112 |= V_295 ;
}
F_39 ( & V_32 -> V_38 , V_63 ) ;
if ( V_32 -> V_296 ) {
V_30 = - V_297 ;
goto V_3;
}
F_35 ( & V_82 -> V_182 , & V_32 -> V_36 ) ;
V_3:
F_40 ( & V_32 -> V_38 , V_63 ) ;
return V_30 ;
}
static void F_158 ( struct V_65 * V_65 )
{
struct V_82 * V_82 = F_42 ( V_65 , struct V_82 , V_294 ) ;
struct V_2 * V_32 = V_82 -> V_32 ;
if ( F_51 ( & V_82 -> V_182 ) ) {
F_12 ( & V_32 -> V_38 ) ;
V_82 -> V_74 -> V_298 ( V_82 ) ;
return;
}
if ( V_32 -> V_296 && V_82 -> V_299 ) {
F_12 ( & V_32 -> V_38 ) ;
F_47 ( & V_82 -> V_184 ) ;
return;
}
F_50 ( & V_82 -> V_182 ) ;
F_12 ( & V_32 -> V_38 ) ;
V_82 -> V_74 -> V_298 ( V_82 ) ;
}
int F_112 ( struct V_2 * V_32 , struct V_82 * V_82 )
{
return F_159 ( & V_82 -> V_294 , F_158 ,
& V_32 -> V_38 ) ;
}
void F_160 ( struct V_2 * V_32 )
{
struct V_82 * V_82 ;
unsigned long V_63 ;
F_39 ( & V_32 -> V_38 , V_63 ) ;
if ( V_32 -> V_296 ) {
F_40 ( & V_32 -> V_38 , V_63 ) ;
return;
}
V_32 -> V_296 = 1 ;
F_74 ( & V_32 -> V_36 , & V_32 -> V_37 ) ;
F_161 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_82 -> V_299 = 1 ;
F_40 ( & V_32 -> V_38 , V_63 ) ;
}
void F_162 ( struct V_2 * V_32 )
{
struct V_82 * V_82 , * V_300 ;
unsigned long V_63 ;
F_75 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_50 ( & V_82 -> V_182 ) ;
F_37 ( L_122
L_123 , V_82 , V_82 -> V_95 ,
V_82 -> V_74 -> V_236 ( V_82 ) ) ;
F_126 ( & V_82 -> V_184 ) ;
F_37 ( L_124
L_125 , V_82 , V_82 -> V_95 ,
V_82 -> V_74 -> V_236 ( V_82 ) ) ;
V_82 -> V_74 -> V_298 ( V_82 ) ;
}
F_39 ( & V_32 -> V_38 , V_63 ) ;
F_67 ( ! F_51 ( & V_32 -> V_36 ) ) ;
F_40 ( & V_32 -> V_38 , V_63 ) ;
}
static int F_163 ( struct V_82 * V_83 , struct V_102 * V_106 )
{
unsigned long V_63 ;
int V_30 = 0 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_87 & V_103 ) {
V_83 -> V_87 &= ~ V_97 ;
F_37 ( L_126 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_58 ( V_83 , false , false ) ;
return - V_301 ;
}
V_83 -> V_87 |= V_302 ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( ( V_83 -> V_87 & V_88 ) &&
( V_83 -> V_87 & V_237 ) ) {
if ( ! F_125 ( V_83 , & V_63 ) )
V_30 ++ ;
}
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_37 ( L_127
L_123 , V_83 , V_30 ) ;
if ( ! V_30 ) {
F_37 ( L_128 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_126 ( & V_83 -> V_101 ) ;
F_37 ( L_129 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
}
return 0 ;
}
static void F_164 ( struct V_102 * V_106 )
{
struct V_82 * V_83 = NULL ;
unsigned long V_303 , V_304 ;
F_39 ( & V_106 -> V_107 , V_303 ) ;
while ( ! F_51 ( & V_106 -> V_305 ) ) {
V_83 = F_165 ( & V_106 -> V_305 ,
struct V_82 , V_108 ) ;
F_61 ( & V_83 -> V_108 ) ;
F_11 ( & V_83 -> V_94 ) ;
F_37 ( L_130
L_131 ,
V_83 -> V_102 -> V_214 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
V_83 -> V_87 |= V_97 ;
F_12 ( & V_83 -> V_94 ) ;
F_40 ( & V_106 -> V_107 , V_303 ) ;
if ( ! V_83 -> V_102 ) {
F_4 ( L_132 ,
V_83 -> V_74 -> V_99 ( V_83 ) ,
V_83 -> V_74 -> V_236 ( V_83 ) , V_83 -> V_95 ) ;
F_166 () ;
}
F_37 ( L_133
L_134 , V_83 -> V_102 -> V_214 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
if ( F_163 ( V_83 , V_83 -> V_102 ) < 0 ) {
F_39 ( & V_106 -> V_107 , V_303 ) ;
continue;
}
F_37 ( L_135
L_136 ,
V_83 -> V_102 -> V_214 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_39 ( & V_83 -> V_94 , V_304 ) ;
if ( ! ( V_83 -> V_87 & V_185 ) ) {
F_40 ( & V_83 -> V_94 , V_304 ) ;
goto V_306;
}
V_83 -> V_87 &= ~ V_185 ;
F_57 ( V_83 ) ;
F_40 ( & V_83 -> V_94 , V_304 ) ;
V_306:
F_111 ( V_83 ,
V_240 , 0 ) ;
F_39 ( & V_83 -> V_94 , V_304 ) ;
if ( V_83 -> V_87 & V_302 ) {
F_37 ( L_137
L_138 ,
V_106 -> V_214 ,
V_83 , V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 ,
V_304 ) ;
F_58 ( V_83 , false , false ) ;
F_47 ( & V_83 -> V_183 ) ;
F_39 ( & V_106 -> V_107 , V_303 ) ;
continue;
}
F_37 ( L_139 ,
V_106 -> V_214 , V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_304 ) ;
F_39 ( & V_106 -> V_107 , V_303 ) ;
}
F_40 ( & V_106 -> V_107 , V_303 ) ;
}
static int F_167 ( void * V_307 )
{
struct V_102 * V_106 = V_307 ;
F_164 ( V_106 ) ;
F_47 ( & V_106 -> V_308 ) ;
return 0 ;
}
int F_168 ( struct V_102 * V_106 )
{
struct V_309 * V_310 ;
V_310 = F_169 ( F_167 , V_106 ,
L_140 , V_106 -> V_214 ) ;
if ( F_29 ( V_310 ) ) {
F_4 ( L_141 ) ;
return F_170 ( V_310 ) ;
}
F_126 ( & V_106 -> V_308 ) ;
return 0 ;
}
bool F_157 ( struct V_82 * V_83 )
{
unsigned long V_63 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( ! ( V_83 -> V_112 & V_292 ) &&
! ( V_83 -> V_112 & V_277 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
if ( ! ( V_83 -> V_112 & V_198 ) &&
! ( V_83 -> V_112 & V_277 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
if ( V_83 -> V_87 & V_97 ) {
F_37 ( L_142
L_143
L_144 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_101 ) ;
F_126 ( & V_83 -> V_183 ) ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
F_57 ( V_83 ) ;
F_37 ( L_145
L_146
L_147 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
V_83 -> V_87 &= ~ V_97 ;
}
if ( ! ( V_83 -> V_87 & V_100 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
V_83 -> V_87 |= V_103 ;
F_37 ( L_148
L_149 ,
V_83 , V_83 -> V_74 -> V_99 ( V_83 ) ,
V_83 -> V_74 -> V_236 ( V_83 ) , V_83 -> V_95 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_126 ( & V_83 -> V_104 ) ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
V_83 -> V_87 &= ~ ( V_100 | V_103 ) ;
F_37 ( L_150
L_151 ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
return true ;
}
static int F_171 (
struct V_82 * V_83 ,
T_3 * V_311 ,
T_3 * V_312 )
{
* V_311 = V_83 -> V_313 ;
* V_312 = V_83 -> V_314 ;
return 0 ;
}
int
F_111 ( struct V_82 * V_83 ,
T_4 V_315 , int V_316 )
{
unsigned char * V_317 = V_83 -> V_121 ;
unsigned long V_63 ;
T_3 V_311 = 0 , V_312 = 0 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_112 & V_113 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return 0 ;
}
V_83 -> V_112 |= V_113 ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
if ( ! V_315 && V_316 )
goto V_318;
if ( ! V_316 )
V_83 -> V_112 |= V_319 ;
switch ( V_315 ) {
case V_320 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_323 ;
V_317 [ V_324 ] = 0 ;
V_317 [ V_325 ] = 0 ;
break;
case V_240 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x25 ;
break;
case V_241 :
case V_327 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x20 ;
break;
case V_244 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x24 ;
break;
case V_247 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_328 ;
V_317 [ V_324 ] = 0x29 ;
V_317 [ V_325 ] = 0x03 ;
break;
case V_329 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_328 ;
V_317 [ V_324 ] = 0x0c ;
V_317 [ V_325 ] = 0x0d ;
break;
case V_175 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x24 ;
break;
case V_242 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x26 ;
break;
case V_243 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x1a ;
break;
case V_330 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_328 ;
V_317 [ V_324 ] = 0x0c ;
V_317 [ V_325 ] = 0x0c ;
break;
case V_331 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_328 ;
V_317 [ V_324 ] = 0x47 ;
V_317 [ V_325 ] = 0x05 ;
break;
case V_332 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_328 ;
V_317 [ V_324 ] = 0x11 ;
V_317 [ V_325 ] = 0x13 ;
break;
case V_245 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_333 ;
V_317 [ V_324 ] = 0x27 ;
break;
case V_246 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_326 ;
V_317 [ V_324 ] = 0x21 ;
break;
case V_248 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_334 ;
F_172 ( V_83 , & V_311 , & V_312 ) ;
V_317 [ V_324 ] = V_311 ;
V_317 [ V_325 ] = V_312 ;
break;
case V_249 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_323 ;
F_171 ( V_83 , & V_311 , & V_312 ) ;
V_317 [ V_324 ] = V_311 ;
V_317 [ V_325 ] = V_312 ;
break;
case V_335 :
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_336 ;
V_317 [ V_324 ] = 0x1d ;
V_317 [ V_325 ] = 0x00 ;
break;
case V_111 :
default:
V_317 [ 0 ] = 0x70 ;
V_317 [ V_321 ] = 10 ;
V_317 [ V_322 ] = V_323 ;
V_317 [ V_324 ] = 0x08 ;
break;
}
V_83 -> V_120 = V_337 ;
V_83 -> V_114 = V_115 ;
V_318:
F_129 ( V_83 ) ;
return V_83 -> V_74 -> V_254 ( V_83 ) ;
}
int F_136 ( struct V_82 * V_83 , int V_338 )
{
if ( ! ( V_83 -> V_87 & V_130 ) )
return 0 ;
if ( ! V_338 || ( V_83 -> V_112 & V_339 ) )
return 1 ;
F_37 ( L_152 ,
V_83 -> V_174 [ 0 ] , V_83 -> V_74 -> V_99 ( V_83 ) ) ;
V_83 -> V_112 |= V_339 ;
F_129 ( V_83 ) ;
V_83 -> V_74 -> V_254 ( V_83 ) ;
return 1 ;
}
void F_173 ( struct V_82 * V_83 )
{
unsigned long V_63 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_112 & ( V_113 | V_339 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return;
}
F_40 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_142 == V_145 ) {
if ( V_83 -> V_74 -> V_340 ( V_83 ) != 0 ) {
V_83 -> V_87 |= V_130 ;
F_96 () ;
}
}
V_83 -> V_120 = V_341 ;
F_60 ( V_83 ) ;
F_37 ( L_153
L_154 , V_83 -> V_174 [ 0 ] ,
V_83 -> V_74 -> V_99 ( V_83 ) ) ;
F_129 ( V_83 ) ;
V_83 -> V_74 -> V_254 ( V_83 ) ;
}
static void F_174 ( struct V_109 * V_110 )
{
struct V_82 * V_83 = F_42 ( V_110 , struct V_82 , V_110 ) ;
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_223 * V_342 = V_83 -> V_223 ;
int V_30 ;
switch ( V_342 -> V_343 ) {
case V_232 :
F_175 ( V_85 , V_342 , V_83 -> V_32 ) ;
break;
case V_344 :
case V_345 :
case V_346 :
V_342 -> V_224 = V_347 ;
break;
case V_348 :
V_30 = F_176 ( V_85 , V_342 , NULL , NULL ) ;
V_342 -> V_224 = ( ! V_30 ) ? V_349 :
V_350 ;
break;
case V_351 :
V_342 -> V_224 = V_350 ;
break;
case V_352 :
V_342 -> V_224 = V_350 ;
break;
default:
F_4 ( L_155 ,
V_342 -> V_343 ) ;
V_342 -> V_224 = V_350 ;
break;
}
V_83 -> V_95 = V_353 ;
V_83 -> V_74 -> V_226 ( V_83 ) ;
F_59 ( V_83 ) ;
}
int F_124 (
struct V_82 * V_83 )
{
F_69 ( & V_83 -> V_110 , F_174 ) ;
F_70 ( V_83 -> V_86 -> V_354 , & V_83 -> V_110 ) ;
return 0 ;
}
