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
if ( V_92 ) {
F_57 ( V_83 ) ;
V_83 -> V_97 = NULL ;
}
if ( V_83 -> V_87 & V_98 ) {
F_37 ( L_31 ,
V_99 , __LINE__ ,
V_83 -> V_74 -> V_100 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_101 ) ;
return 1 ;
}
V_83 -> V_87 &= ~ V_102 ;
if ( V_92 ) {
if ( V_83 -> V_74 -> V_103 != NULL ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return V_83 -> V_74 -> V_103 ( V_83 ) ;
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
struct V_97 * V_104 = V_83 -> V_97 ;
if ( ! V_104 || ! V_83 -> V_105 )
return;
F_61 ( & V_104 -> V_106 ) ;
}
void F_62 ( struct V_82 * V_83 , int remove )
{
if ( F_59 ( V_83 ) )
return;
if ( remove )
F_63 ( V_83 ) ;
}
static void F_64 ( struct V_107 * V_108 )
{
struct V_82 * V_83 = F_42 ( V_108 , struct V_82 , V_108 ) ;
F_65 ( V_83 ,
V_109 ) ;
}
static unsigned char * F_66 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
F_67 ( ! V_83 -> V_97 ) ;
if ( ! V_85 )
return NULL ;
if ( V_83 -> V_110 & V_111 )
return NULL ;
V_83 -> V_112 = V_113 ;
F_37 ( L_32 ,
V_85 -> V_114 -> V_115 , V_85 -> V_116 -> V_117 , V_83 -> V_118 ) ;
return V_83 -> V_119 ;
}
void F_68 ( struct V_82 * V_83 , T_3 V_118 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
int V_120 = V_118 == V_121 ;
unsigned long V_63 ;
V_83 -> V_118 = V_118 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
V_83 -> V_87 &= ~ V_88 ;
if ( V_85 && V_85 -> V_116 -> V_122 ) {
V_85 -> V_116 -> V_122 ( V_83 ,
V_83 -> V_123 ,
F_66 ( V_83 ) ) ;
if ( V_83 -> V_110 & V_124 )
V_120 = 1 ;
}
if ( V_83 -> V_87 & V_125 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_126 ) ;
return;
}
if ( ! V_120 )
V_83 -> V_87 |= V_127 ;
if ( V_83 -> V_87 & V_128 &&
V_83 -> V_87 & V_98 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_47 ( & V_83 -> V_101 ) ;
return;
} else if ( V_83 -> V_87 & V_127 ) {
F_69 ( & V_83 -> V_108 , F_64 ) ;
} else {
F_69 ( & V_83 -> V_108 , V_129 ) ;
}
V_83 -> V_95 = V_130 ;
V_83 -> V_87 |= ( V_131 | V_102 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_70 ( V_22 , & V_83 -> V_108 ) ;
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
void F_72 ( struct V_107 * V_108 )
{
struct V_84 * V_85 = F_42 ( V_108 , struct V_84 ,
V_132 ) ;
F_73 ( V_133 ) ;
struct V_82 * V_83 , * V_134 ;
F_34 ( & V_85 -> V_135 ) ;
F_74 ( & V_85 -> V_133 , & V_133 ) ;
F_36 ( & V_85 -> V_135 ) ;
F_75 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_50 ( & V_83 -> V_136 ) ;
F_76 ( & V_85 -> V_137 ) ;
F_77 () ;
F_37 ( L_33
L_34 , V_83 -> V_74 -> V_62 () , V_83 ,
( V_83 -> V_95 == V_138 ) ? L_35 :
( V_83 -> V_95 == V_139 ) ? L_36
: L_37 ) ;
if ( V_83 -> V_95 == V_139 )
F_78 ( V_83 ) ;
else if ( V_83 -> V_95 == V_138 )
F_79 ( V_83 ) ;
}
}
unsigned char * F_80 ( struct V_82 * V_83 )
{
switch ( V_83 -> V_140 ) {
case V_141 :
return L_38 ;
case V_142 :
return L_39 ;
case V_143 :
return L_40 ;
case V_144 :
return L_41 ;
default:
break;
}
return L_37 ;
}
void F_81 (
struct V_84 * V_85 ,
char * V_145 ,
int * V_146 )
{
* V_146 += sprintf ( V_145 + * V_146 , L_42 ) ;
if ( V_85 -> V_147 )
* V_146 += sprintf ( V_145 + * V_146 , L_43 ) ;
else
* V_146 += sprintf ( V_145 + * V_146 , L_44 ) ;
* V_146 += sprintf ( V_145 + * V_146 , L_45 , V_85 -> V_148 ) ;
* V_146 += sprintf ( V_145 + * V_146 , L_46 ,
V_85 -> V_149 . V_150 ,
V_85 -> V_149 . V_151 ) ;
* V_146 += sprintf ( V_145 + * V_146 , L_47 ) ;
}
void F_82 (
struct V_152 * V_153 ,
unsigned char * V_154 ,
int V_155 )
{
unsigned char V_52 [ V_156 ] ;
int V_157 ;
memset ( V_52 , 0 , V_156 ) ;
V_157 = sprintf ( V_52 , L_48 ) ;
switch ( V_153 -> V_158 ) {
case 0x00 :
sprintf ( V_52 + V_157 , L_49 ) ;
break;
case 0x10 :
sprintf ( V_52 + V_157 , L_50 ) ;
break;
case 0x20 :
sprintf ( V_52 + V_157 , L_51 ) ;
break;
case 0x30 :
sprintf ( V_52 + V_157 , L_52 ) ;
break;
case 0x40 :
sprintf ( V_52 + V_157 , L_53
L_54 ) ;
break;
case 0x50 :
sprintf ( V_52 + V_157 , L_55 ) ;
break;
case 0x60 :
sprintf ( V_52 + V_157 , L_56 ) ;
break;
case 0x70 :
sprintf ( V_52 + V_157 , L_57
L_54 ) ;
break;
case 0x80 :
sprintf ( V_52 + V_157 , L_58 ) ;
break;
default:
sprintf ( V_52 + V_157 , L_59 ,
V_153 -> V_158 ) ;
break;
}
if ( V_154 )
strncpy ( V_154 , V_52 , V_155 ) ;
else
F_37 ( L_60 , V_52 ) ;
}
void
F_83 ( struct V_152 * V_153 , unsigned char * V_159 )
{
if ( V_159 [ 1 ] & 0x80 ) {
V_153 -> V_158 = ( V_159 [ 0 ] & 0xf0 ) ;
V_153 -> V_160 = 1 ;
F_82 ( V_153 , NULL , 0 ) ;
}
}
int F_84 (
struct V_152 * V_153 ,
unsigned char * V_154 ,
int V_155 )
{
unsigned char V_52 [ V_156 ] ;
int V_30 = 0 ;
int V_157 ;
memset ( V_52 , 0 , V_156 ) ;
V_157 = sprintf ( V_52 , L_61 ) ;
switch ( V_153 -> V_161 ) {
case 0x00 :
sprintf ( V_52 + V_157 , L_62 ) ;
break;
case 0x10 :
sprintf ( V_52 + V_157 , L_63 ) ;
break;
case 0x20 :
sprintf ( V_52 + V_157 , L_64 ) ;
break;
default:
sprintf ( V_52 + V_157 , L_59 , V_153 -> V_161 ) ;
V_30 = - V_162 ;
break;
}
if ( V_154 )
strncpy ( V_154 , V_52 , V_155 ) ;
else
F_37 ( L_60 , V_52 ) ;
return V_30 ;
}
int F_85 ( struct V_152 * V_153 , unsigned char * V_159 )
{
V_153 -> V_161 = ( V_159 [ 1 ] & 0x30 ) ;
return F_84 ( V_153 , NULL , 0 ) ;
}
int F_86 (
struct V_152 * V_153 ,
unsigned char * V_154 ,
int V_155 )
{
unsigned char V_52 [ V_156 ] ;
int V_30 = 0 ;
int V_157 ;
memset ( V_52 , 0 , V_156 ) ;
V_157 = sprintf ( V_52 , L_65 ) ;
switch ( V_153 -> V_163 ) {
case 0x00 :
sprintf ( V_52 + V_157 , L_66 ) ;
break;
case 0x01 :
sprintf ( V_52 + V_157 , L_67 ) ;
break;
case 0x02 :
sprintf ( V_52 + V_157 , L_68 ) ;
break;
case 0x03 :
sprintf ( V_52 + V_157 , L_69 ) ;
break;
case 0x04 :
sprintf ( V_52 + V_157 , L_70 ) ;
break;
case 0x08 :
sprintf ( V_52 + V_157 , L_71 ) ;
break;
default:
sprintf ( V_52 + V_157 , L_72 ,
V_153 -> V_163 ) ;
V_30 = - V_162 ;
break;
}
if ( V_154 ) {
if ( V_155 < strlen ( V_52 ) + 1 )
return - V_162 ;
strncpy ( V_154 , V_52 , V_155 ) ;
} else {
F_37 ( L_60 , V_52 ) ;
}
return V_30 ;
}
int F_87 ( struct V_152 * V_153 , unsigned char * V_159 )
{
V_153 -> V_163 = ( V_159 [ 1 ] & 0x0f ) ;
return F_86 ( V_153 , NULL , 0 ) ;
}
int F_88 (
struct V_152 * V_153 ,
unsigned char * V_154 ,
int V_155 )
{
unsigned char V_52 [ V_156 ] ;
int V_30 = 0 ;
memset ( V_52 , 0 , V_156 ) ;
switch ( V_153 -> V_164 ) {
case 0x01 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_73 ,
& V_153 -> V_165 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_74 ,
& V_153 -> V_165 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_52 , sizeof( V_52 ) ,
L_75 ,
& V_153 -> V_165 [ 0 ] ) ;
break;
default:
sprintf ( V_52 , L_76
L_77 , V_153 -> V_164 ) ;
V_30 = - V_162 ;
break;
}
if ( V_154 )
strncpy ( V_154 , V_52 , V_155 ) ;
else
F_37 ( L_60 , V_52 ) ;
return V_30 ;
}
int
F_89 ( struct V_152 * V_153 , unsigned char * V_159 )
{
static const char V_166 [] = L_78 ;
int V_167 = 0 , V_168 = 4 ;
V_153 -> V_164 = ( V_159 [ 0 ] & 0x0f ) ;
switch ( V_153 -> V_164 ) {
case 0x01 :
V_153 -> V_165 [ V_167 ++ ] =
V_166 [ V_153 -> V_163 ] ;
while ( V_168 < ( 4 + V_159 [ 3 ] ) ) {
V_153 -> V_165 [ V_167 ++ ] =
V_166 [ ( V_159 [ V_168 ] & 0xf0 ) >> 4 ] ;
V_153 -> V_165 [ V_167 ++ ] =
V_166 [ V_159 [ V_168 ] & 0x0f ] ;
V_168 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_168 < ( 4 + V_159 [ 3 ] ) )
V_153 -> V_165 [ V_167 ++ ] = V_159 [ V_168 ++ ] ;
break;
default:
break;
}
return F_88 ( V_153 , NULL , 0 ) ;
}
T_4
F_90 ( struct V_82 * V_83 , unsigned int V_169 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_83 -> V_170 ) {
V_83 -> V_171 = V_169 ;
} else if ( V_169 != V_83 -> V_171 ) {
F_91 ( L_79
L_80
L_81 , V_83 -> V_74 -> V_62 () ,
V_83 -> V_171 , V_169 , V_83 -> V_172 [ 0 ] ) ;
if ( V_83 -> V_140 == V_143 ) {
F_4 ( L_82
L_83 ) ;
return V_173 ;
}
if ( V_85 -> V_149 . V_150 != 512 ) {
F_4 ( L_84
L_85
L_86 , V_85 -> V_116 -> V_117 ) ;
return V_173 ;
}
if ( V_169 > V_83 -> V_171 ) {
V_83 -> V_110 |= V_174 ;
V_83 -> V_175 = ( V_169 - V_83 -> V_171 ) ;
} else {
V_83 -> V_110 |= V_176 ;
V_83 -> V_175 = ( V_83 -> V_171 - V_169 ) ;
V_83 -> V_171 = V_169 ;
}
}
return 0 ;
}
void F_92 (
struct V_82 * V_83 ,
struct V_73 * V_177 ,
struct V_2 * V_32 ,
T_1 V_171 ,
int V_140 ,
int V_178 ,
unsigned char * V_119 )
{
F_18 ( & V_83 -> V_179 ) ;
F_18 ( & V_83 -> V_136 ) ;
F_18 ( & V_83 -> V_180 ) ;
F_18 ( & V_83 -> V_91 ) ;
F_93 ( & V_83 -> V_101 ) ;
F_93 ( & V_83 -> V_181 ) ;
F_93 ( & V_83 -> V_126 ) ;
F_19 ( & V_83 -> V_94 ) ;
V_83 -> V_87 = V_182 ;
V_83 -> V_74 = V_177 ;
V_83 -> V_32 = V_32 ;
V_83 -> V_171 = V_171 ;
V_83 -> V_140 = V_140 ;
V_83 -> V_183 = V_178 ;
V_83 -> V_119 = V_119 ;
V_83 -> V_90 = false ;
}
static T_4
F_94 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_116 -> V_184 == V_185 )
return 0 ;
if ( V_83 -> V_183 == V_186 ) {
F_37 ( L_87
L_88 ) ;
return V_173 ;
}
V_83 -> V_187 = F_95 ( & V_85 -> V_188 ) ;
F_96 () ;
F_37 ( L_89 ,
V_83 -> V_187 , V_83 -> V_183 ,
V_85 -> V_116 -> V_117 ) ;
return 0 ;
}
T_4
F_97 ( struct V_82 * V_83 , unsigned char * V_189 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
T_4 V_30 ;
if ( F_98 ( V_189 ) > V_190 ) {
F_4 ( L_90
L_91 ,
F_98 ( V_189 ) , V_190 ) ;
return V_173 ;
}
if ( F_98 ( V_189 ) > sizeof( V_83 -> V_191 ) ) {
V_83 -> V_172 = F_22 ( F_98 ( V_189 ) ,
V_33 ) ;
if ( ! V_83 -> V_172 ) {
F_4 ( L_92
L_93 ,
F_98 ( V_189 ) ,
( unsigned long ) sizeof( V_83 -> V_191 ) ) ;
return V_192 ;
}
} else
V_83 -> V_172 = & V_83 -> V_191 [ 0 ] ;
memcpy ( V_83 -> V_172 , V_189 , F_98 ( V_189 ) ) ;
F_99 ( V_83 ) ;
V_30 = F_100 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_101 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_102 ( V_83 ) ;
if ( V_30 ) {
V_83 -> V_118 = V_193 ;
return V_30 ;
}
V_30 = V_85 -> V_116 -> V_194 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_94 ( V_83 ) ;
if ( V_30 )
return V_30 ;
V_83 -> V_110 |= V_195 ;
F_11 ( & V_83 -> V_97 -> V_196 ) ;
if ( V_83 -> V_97 -> V_197 )
V_83 -> V_97 -> V_197 -> V_198 . V_199 ++ ;
F_12 ( & V_83 -> V_97 -> V_196 ) ;
return 0 ;
}
int F_103 (
struct V_82 * V_83 )
{
T_4 V_30 ;
if ( ! V_83 -> V_97 ) {
F_104 () ;
F_4 ( L_94 ) ;
return - V_162 ;
}
if ( F_105 () ) {
F_104 () ;
F_4 ( L_95
L_96 ) ;
return - V_162 ;
}
V_83 -> V_95 = V_200 ;
V_83 -> V_87 |= V_102 ;
V_30 = F_106 ( V_83 ) ;
if ( V_30 )
F_65 ( V_83 , V_30 ) ;
return 0 ;
}
T_4
F_107 ( struct V_82 * V_83 , struct V_201 * V_202 ,
T_1 V_203 , struct V_201 * V_204 , T_1 V_205 )
{
if ( ! V_202 || ! V_203 )
return 0 ;
if ( V_83 -> V_110 & V_174 ) {
F_91 ( L_97
L_98 ) ;
return V_173 ;
}
V_83 -> V_123 = V_202 ;
V_83 -> V_206 = V_203 ;
if ( V_204 && V_205 ) {
V_83 -> V_207 = V_204 ;
V_83 -> V_208 = V_205 ;
}
V_83 -> V_110 |= V_209 ;
return 0 ;
}
int F_108 ( struct V_82 * V_82 , struct V_2 * V_32 ,
unsigned char * V_189 , unsigned char * V_210 , T_1 V_211 ,
T_1 V_171 , int V_178 , int V_212 , int V_63 ,
struct V_201 * V_202 , T_1 V_203 ,
struct V_201 * V_204 , T_1 V_205 )
{
struct V_47 * V_48 ;
T_4 V_42 ;
int V_30 ;
V_48 = V_32 -> V_48 ;
F_10 ( ! V_48 ) ;
F_10 ( V_82 -> V_74 || V_82 -> V_32 ) ;
F_10 ( F_105 () ) ;
F_92 ( V_82 , V_48 -> V_54 , V_32 ,
V_171 , V_212 , V_178 , V_210 ) ;
if ( V_63 & V_213 )
V_82 -> V_170 = 1 ;
V_30 = F_109 ( V_32 , V_82 , ( V_63 & V_214 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_63 & V_215 )
V_82 -> V_110 |= V_216 ;
V_42 = F_110 ( V_82 , V_211 ) ;
if ( V_42 ) {
F_111 ( V_82 , V_42 , 0 ) ;
F_112 ( V_32 , V_82 ) ;
return 0 ;
}
V_42 = F_97 ( V_82 , V_189 ) ;
if ( V_42 != 0 ) {
F_65 ( V_82 , V_42 ) ;
return 0 ;
}
if ( V_203 != 0 ) {
F_10 ( ! V_202 ) ;
if ( ! ( V_82 -> V_110 & V_217 ) &&
V_82 -> V_140 == V_142 ) {
unsigned char * V_52 = NULL ;
if ( V_202 )
V_52 = F_113 ( F_114 ( V_202 ) ) + V_202 -> V_218 ;
if ( V_52 ) {
memset ( V_52 , 0 , V_202 -> V_219 ) ;
F_115 ( F_114 ( V_202 ) ) ;
}
}
V_42 = F_107 ( V_82 , V_202 , V_203 ,
V_204 , V_205 ) ;
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
unsigned char * V_189 , unsigned char * V_210 , T_1 V_211 ,
T_1 V_171 , int V_178 , int V_212 , int V_63 )
{
return F_108 ( V_82 , V_32 , V_189 , V_210 ,
V_211 , V_171 , V_178 , V_212 ,
V_63 , NULL , 0 , NULL , 0 ) ;
}
static void F_118 ( struct V_107 * V_108 )
{
struct V_82 * V_82 = F_42 ( V_108 , struct V_82 , V_108 ) ;
V_82 -> V_220 -> V_221 = V_222 ;
V_82 -> V_74 -> V_223 ( V_82 ) ;
F_59 ( V_82 ) ;
}
int F_119 ( struct V_82 * V_82 , struct V_2 * V_32 ,
unsigned char * V_210 , T_1 V_211 ,
void * V_224 , unsigned char V_225 ,
T_5 V_226 , unsigned int V_227 , int V_63 )
{
struct V_47 * V_48 ;
int V_30 ;
V_48 = V_32 -> V_48 ;
F_10 ( ! V_48 ) ;
F_92 ( V_82 , V_48 -> V_54 , V_32 ,
0 , V_141 , V_228 , V_210 ) ;
V_30 = F_120 ( V_82 , V_224 , V_225 , V_226 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_225 == V_229 )
V_82 -> V_220 -> V_230 = V_227 ;
V_30 = F_109 ( V_32 , V_82 , ( V_63 & V_214 ) ) ;
if ( V_30 ) {
F_121 ( V_82 -> V_220 ) ;
return V_30 ;
}
V_30 = F_122 ( V_82 , V_211 ) ;
if ( V_30 ) {
F_69 ( & V_82 -> V_108 , F_118 ) ;
F_123 ( & V_82 -> V_108 ) ;
return 0 ;
}
F_124 ( V_82 ) ;
return 0 ;
}
bool F_125 ( struct V_82 * V_83 , unsigned long * V_63 )
{
bool V_231 = false ;
if ( V_83 -> V_87 & V_88 ) {
V_83 -> V_87 |= V_125 ;
F_40 ( & V_83 -> V_94 , * V_63 ) ;
F_37 ( L_99 , V_83 ) ;
F_126 ( & V_83 -> V_126 ) ;
F_37 ( L_100 , V_83 ) ;
F_39 ( & V_83 -> V_94 , * V_63 ) ;
V_83 -> V_87 &= ~ V_125 ;
V_83 -> V_87 &= ~ V_88 ;
V_231 = true ;
}
return V_231 ;
}
void F_65 ( struct V_82 * V_83 ,
T_4 V_232 )
{
int V_30 = 0 ;
F_37 ( L_101
L_102 , V_83 , V_83 -> V_74 -> V_100 ( V_83 ) ,
V_83 -> V_172 [ 0 ] ) ;
F_37 ( L_103 ,
V_83 -> V_74 -> V_233 ( V_83 ) ,
V_83 -> V_95 , V_232 ) ;
F_37 ( L_104 ,
( V_83 -> V_87 & V_102 ) != 0 ,
( V_83 -> V_87 & V_98 ) != 0 ,
( V_83 -> V_87 & V_234 ) != 0 ) ;
F_127 ( V_83 ) ;
if ( ( V_83 -> V_110 & V_235 ) &&
V_83 -> V_236 )
V_83 -> V_236 ( V_83 ) ;
switch ( V_232 ) {
case V_237 :
case V_238 :
case V_173 :
case V_239 :
case V_240 :
case V_109 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
break;
case V_192 :
V_232 = V_109 ;
break;
case V_247 :
V_83 -> V_118 = V_193 ;
if ( V_83 -> V_32 &&
V_83 -> V_86 -> V_149 . V_248 == 2 )
F_128 ( V_83 -> V_32 -> V_49 ,
V_83 -> V_249 , 0x2C ,
V_250 ) ;
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_251 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
goto V_254;
default:
F_4 ( L_105 ,
V_83 -> V_172 [ 0 ] , V_232 ) ;
V_232 = V_238 ;
break;
}
V_30 = F_111 ( V_83 , V_232 , 0 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
V_254:
F_60 ( V_83 ) ;
if ( ! F_59 ( V_83 ) )
;
return;
V_253:
V_83 -> V_95 = V_138 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
void F_131 ( struct V_82 * V_83 )
{
T_4 V_30 ;
if ( V_83 -> V_255 ) {
V_30 = V_83 -> V_255 ( V_83 ) ;
if ( V_30 ) {
F_34 ( & V_83 -> V_94 ) ;
V_83 -> V_87 &= ~ ( V_88 | V_234 ) ;
F_36 ( & V_83 -> V_94 ) ;
F_65 ( V_83 , V_30 ) ;
}
}
}
static bool F_132 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_116 -> V_184 == V_185 )
return false ;
switch ( V_83 -> V_183 ) {
case V_256 :
F_37 ( L_106
L_107 ,
V_83 -> V_172 [ 0 ] , V_83 -> V_187 ) ;
return false ;
case V_257 :
F_133 ( & V_85 -> V_258 ) ;
F_96 () ;
F_37 ( L_108
L_109 ,
V_83 -> V_172 [ 0 ] , V_83 -> V_187 ) ;
if ( ! F_134 ( & V_85 -> V_259 ) )
return false ;
break;
default:
F_133 ( & V_85 -> V_259 ) ;
F_96 () ;
break;
}
if ( F_134 ( & V_85 -> V_258 ) == 0 )
return false ;
F_11 ( & V_85 -> V_260 ) ;
F_35 ( & V_83 -> V_179 , & V_85 -> V_261 ) ;
F_12 ( & V_85 -> V_260 ) ;
F_37 ( L_110
L_111 ,
V_83 -> V_172 [ 0 ] , V_83 -> V_183 ,
V_83 -> V_187 ) ;
return true ;
}
void F_135 ( struct V_82 * V_83 )
{
if ( F_136 ( V_83 , 1 ) )
return;
F_34 ( & V_83 -> V_94 ) ;
if ( V_83 -> V_87 & V_98 ) {
F_37 ( L_31 ,
V_99 , __LINE__ ,
V_83 -> V_74 -> V_100 ( V_83 ) ) ;
F_36 ( & V_83 -> V_94 ) ;
F_47 ( & V_83 -> V_101 ) ;
return;
}
V_83 -> V_95 = V_262 ;
V_83 -> V_87 |= V_102 | V_88 | V_234 ;
F_36 ( & V_83 -> V_94 ) ;
if ( F_132 ( V_83 ) ) {
F_34 ( & V_83 -> V_94 ) ;
V_83 -> V_87 &= ~ V_88 | V_234 ;
F_36 ( & V_83 -> V_94 ) ;
return;
}
F_131 ( V_83 ) ;
}
static void F_137 ( struct V_84 * V_85 )
{
for (; ; ) {
struct V_82 * V_83 ;
F_11 ( & V_85 -> V_260 ) ;
if ( F_51 ( & V_85 -> V_261 ) ) {
F_12 ( & V_85 -> V_260 ) ;
break;
}
V_83 = F_138 ( V_85 -> V_261 . V_263 ,
struct V_82 , V_179 ) ;
F_50 ( & V_83 -> V_179 ) ;
F_12 ( & V_85 -> V_260 ) ;
F_131 ( V_83 ) ;
if ( V_83 -> V_183 == V_257 )
break;
}
}
static void F_127 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
if ( V_85 -> V_116 -> V_184 == V_185 )
return;
if ( V_83 -> V_183 == V_228 ) {
F_76 ( & V_85 -> V_259 ) ;
F_77 () ;
V_85 -> V_264 ++ ;
F_37 ( L_112
L_113 , V_85 -> V_264 ,
V_83 -> V_187 ) ;
} else if ( V_83 -> V_183 == V_256 ) {
V_85 -> V_264 ++ ;
F_37 ( L_114
L_115 , V_85 -> V_264 ,
V_83 -> V_187 ) ;
} else if ( V_83 -> V_183 == V_257 ) {
F_76 ( & V_85 -> V_258 ) ;
F_77 () ;
V_85 -> V_264 ++ ;
F_37 ( L_116
L_117 , V_85 -> V_264 , V_83 -> V_187 ) ;
}
F_137 ( V_85 ) ;
}
static void F_79 ( struct V_82 * V_83 )
{
int V_30 = 0 ;
F_127 ( V_83 ) ;
if ( V_83 -> V_110 & V_124 ) {
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_251 ( V_83 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_83 -> V_140 ) {
case V_142 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_265 ( V_83 ) ;
break;
case V_143 :
if ( V_83 -> V_110 & V_216 ) {
V_30 = V_83 -> V_74 -> V_265 ( V_83 ) ;
if ( V_30 < 0 )
break;
}
case V_141 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_251 ( V_83 ) ;
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
F_34 ( & V_85 -> V_135 ) ;
F_35 ( & V_83 -> V_136 , & V_83 -> V_86 -> V_133 ) ;
F_133 ( & V_85 -> V_137 ) ;
F_96 () ;
F_36 ( & V_83 -> V_86 -> V_135 ) ;
F_123 ( & V_83 -> V_86 -> V_132 ) ;
}
static void V_129 ( struct V_107 * V_108 )
{
struct V_82 * V_83 = F_42 ( V_108 , struct V_82 , V_108 ) ;
int V_30 ;
F_127 ( V_83 ) ;
if ( F_134 ( & V_83 -> V_86 -> V_137 ) != 0 )
F_123 ( & V_83 -> V_86 -> V_132 ) ;
if ( V_83 -> V_110 & V_124 ) {
F_67 ( ! V_83 -> V_118 ) ;
V_30 = F_111 (
V_83 , 0 , 1 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
}
if ( V_83 -> V_236 ) {
T_4 V_42 ;
V_42 = V_83 -> V_236 ( V_83 ) ;
if ( ! V_42 && ! ( V_83 -> V_110 & V_266 ) ) {
return;
} else if ( V_42 ) {
V_30 = F_111 ( V_83 ,
V_42 , 0 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
}
}
switch ( V_83 -> V_140 ) {
case V_142 :
F_11 ( & V_83 -> V_97 -> V_196 ) ;
if ( V_83 -> V_97 -> V_197 ) {
V_83 -> V_97 -> V_197 -> V_198 . V_267 +=
V_83 -> V_171 ;
}
F_12 ( & V_83 -> V_97 -> V_196 ) ;
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_265 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
break;
case V_143 :
F_11 ( & V_83 -> V_97 -> V_196 ) ;
if ( V_83 -> V_97 -> V_197 ) {
V_83 -> V_97 -> V_197 -> V_198 . V_268 +=
V_83 -> V_171 ;
}
F_12 ( & V_83 -> V_97 -> V_196 ) ;
if ( V_83 -> V_110 & V_216 ) {
F_11 ( & V_83 -> V_97 -> V_196 ) ;
if ( V_83 -> V_97 -> V_197 ) {
V_83 -> V_97 -> V_197 -> V_198 . V_267 +=
V_83 -> V_171 ;
}
F_12 ( & V_83 -> V_97 -> V_196 ) ;
V_30 = V_83 -> V_74 -> V_265 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
break;
}
case V_141 :
F_129 ( V_83 ) ;
V_30 = V_83 -> V_74 -> V_251 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
break;
default:
break;
}
F_60 ( V_83 ) ;
F_59 ( V_83 ) ;
return;
V_253:
F_37 ( L_118
L_119 , V_83 , V_83 -> V_140 ) ;
V_83 -> V_95 = V_138 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
static inline void F_139 ( struct V_201 * V_202 , int V_269 )
{
struct V_201 * V_270 ;
int V_271 ;
F_140 (sgl, sg, nents, count)
F_141 ( F_114 ( V_270 ) ) ;
F_27 ( V_202 ) ;
}
static inline void F_142 ( struct V_82 * V_83 )
{
if ( ! V_83 -> V_272 )
return;
F_27 ( V_83 -> V_123 ) ;
V_83 -> V_123 = V_83 -> V_272 ;
V_83 -> V_272 = NULL ;
V_83 -> V_206 = V_83 -> V_273 ;
V_83 -> V_273 = 0 ;
}
static inline void F_143 ( struct V_82 * V_83 )
{
if ( V_83 -> V_110 & V_209 ) {
F_142 ( V_83 ) ;
return;
}
F_142 ( V_83 ) ;
F_139 ( V_83 -> V_123 , V_83 -> V_206 ) ;
V_83 -> V_123 = NULL ;
V_83 -> V_206 = 0 ;
F_139 ( V_83 -> V_207 , V_83 -> V_208 ) ;
V_83 -> V_207 = NULL ;
V_83 -> V_208 = 0 ;
}
static int F_144 ( struct V_82 * V_83 )
{
F_10 ( ! V_83 -> V_74 ) ;
if ( V_83 -> V_110 & V_274 )
F_121 ( V_83 -> V_220 ) ;
if ( V_83 -> V_172 != V_83 -> V_191 )
F_27 ( V_83 -> V_172 ) ;
return F_112 ( V_83 -> V_32 , V_83 ) ;
}
static int F_63 ( struct V_82 * V_83 )
{
F_143 ( V_83 ) ;
return F_144 ( V_83 ) ;
}
void * F_145 ( struct V_82 * V_83 )
{
struct V_201 * V_270 = V_83 -> V_123 ;
struct V_275 * * V_276 ;
int V_168 ;
if ( ! V_83 -> V_206 )
return NULL ;
F_10 ( ! V_270 ) ;
if ( V_83 -> V_206 == 1 )
return F_113 ( F_114 ( V_270 ) ) + V_270 -> V_218 ;
V_276 = F_146 ( sizeof( * V_276 ) * V_83 -> V_206 , V_33 ) ;
if ( ! V_276 )
return NULL ;
F_140 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_276 [ V_168 ] = F_114 ( V_270 ) ;
}
V_83 -> V_277 = F_147 ( V_276 , V_83 -> V_206 , V_278 , V_279 ) ;
F_27 ( V_276 ) ;
if ( ! V_83 -> V_277 )
return NULL ;
return V_83 -> V_277 + V_83 -> V_123 [ 0 ] . V_218 ;
}
void F_148 ( struct V_82 * V_83 )
{
if ( ! V_83 -> V_206 ) {
return;
} else if ( V_83 -> V_206 == 1 ) {
F_115 ( F_114 ( V_83 -> V_123 ) ) ;
return;
}
F_149 ( V_83 -> V_277 ) ;
V_83 -> V_277 = NULL ;
}
int
F_150 ( struct V_201 * * V_202 , unsigned int * V_269 , T_1 V_219 ,
bool V_280 )
{
struct V_201 * V_270 ;
struct V_275 * V_275 ;
T_5 V_281 = ( V_280 ) ? V_282 : 0 ;
unsigned int V_283 ;
int V_168 = 0 ;
V_283 = F_151 ( V_219 , V_284 ) ;
V_270 = F_146 ( sizeof( struct V_201 ) * V_283 , V_33 ) ;
if ( ! V_270 )
return - V_25 ;
F_152 ( V_270 , V_283 ) ;
while ( V_219 ) {
T_1 V_285 = F_153 ( T_1 , V_219 , V_284 ) ;
V_275 = F_154 ( V_33 | V_281 ) ;
if ( ! V_275 )
goto V_3;
F_155 ( & V_270 [ V_168 ] , V_275 , V_285 , 0 ) ;
V_219 -= V_285 ;
V_168 ++ ;
}
* V_202 = V_270 ;
* V_269 = V_283 ;
return 0 ;
V_3:
while ( V_168 > 0 ) {
V_168 -- ;
F_141 ( F_114 ( & V_270 [ V_168 ] ) ) ;
}
F_27 ( V_270 ) ;
return - V_25 ;
}
T_4
F_106 ( struct V_82 * V_83 )
{
int V_30 = 0 ;
if ( ! ( V_83 -> V_110 & V_209 ) &&
V_83 -> V_171 ) {
bool V_281 = ! ( V_83 -> V_110 & V_217 ) ;
if ( ( V_83 -> V_110 & V_216 ) ||
( V_83 -> V_110 & V_235 ) ) {
T_1 V_286 ;
if ( V_83 -> V_110 & V_235 )
V_286 = V_83 -> V_287 *
V_83 -> V_86 -> V_149 . V_150 ;
else
V_286 = V_83 -> V_171 ;
V_30 = F_150 ( & V_83 -> V_207 ,
& V_83 -> V_208 ,
V_286 , V_281 ) ;
if ( V_30 < 0 )
return V_109 ;
}
V_30 = F_150 ( & V_83 -> V_123 , & V_83 -> V_206 ,
V_83 -> V_171 , V_281 ) ;
if ( V_30 < 0 )
return V_109 ;
}
F_71 ( V_83 ) ;
if ( V_83 -> V_140 != V_143 ) {
F_135 ( V_83 ) ;
return 0 ;
}
F_58 ( V_83 , false , true ) ;
V_30 = V_83 -> V_74 -> V_93 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 )
goto V_253;
F_67 ( V_30 ) ;
return ( ! V_30 ) ? 0 : V_109 ;
V_253:
F_37 ( L_120 , V_83 ) ;
V_83 -> V_95 = V_139 ;
F_130 ( V_83 , V_83 -> V_86 ) ;
return 0 ;
}
static void F_78 ( struct V_82 * V_83 )
{
int V_30 ;
V_30 = V_83 -> V_74 -> V_93 ( V_83 ) ;
if ( V_30 == - V_252 || V_30 == - V_25 ) {
F_37 ( L_120 ,
V_83 ) ;
F_130 ( V_83 , V_83 -> V_86 ) ;
}
}
int F_156 ( struct V_82 * V_83 , int V_288 )
{
unsigned long V_63 ;
int V_30 = 0 ;
if ( ! ( V_83 -> V_110 & V_289 ) ) {
if ( V_288 && ( V_83 -> V_110 & V_274 ) )
F_157 ( V_83 ) ;
V_30 = F_144 ( V_83 ) ;
} else {
if ( V_288 )
F_157 ( V_83 ) ;
if ( V_83 -> V_90 ) {
F_39 ( & V_83 -> V_94 , V_63 ) ;
F_57 ( V_83 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
}
if ( V_83 -> V_97 )
F_60 ( V_83 ) ;
V_30 = F_63 ( V_83 ) ;
}
return V_30 ;
}
int F_109 ( struct V_2 * V_32 , struct V_82 * V_82 ,
bool V_290 )
{
unsigned long V_63 ;
int V_30 = 0 ;
F_20 ( & V_82 -> V_291 ) ;
if ( V_290 == true ) {
F_33 ( & V_82 -> V_291 ) ;
V_82 -> V_110 |= V_292 ;
}
F_39 ( & V_32 -> V_38 , V_63 ) ;
if ( V_32 -> V_293 ) {
V_30 = - V_294 ;
goto V_3;
}
F_35 ( & V_82 -> V_180 , & V_32 -> V_36 ) ;
V_3:
F_40 ( & V_32 -> V_38 , V_63 ) ;
return V_30 ;
}
static void F_158 ( struct V_65 * V_65 )
{
struct V_82 * V_82 = F_42 ( V_65 , struct V_82 , V_291 ) ;
struct V_2 * V_32 = V_82 -> V_32 ;
if ( F_51 ( & V_82 -> V_180 ) ) {
F_12 ( & V_32 -> V_38 ) ;
V_82 -> V_74 -> V_295 ( V_82 ) ;
return;
}
if ( V_32 -> V_293 && V_82 -> V_296 ) {
F_12 ( & V_32 -> V_38 ) ;
F_47 ( & V_82 -> V_181 ) ;
return;
}
F_50 ( & V_82 -> V_180 ) ;
F_12 ( & V_32 -> V_38 ) ;
V_82 -> V_74 -> V_295 ( V_82 ) ;
}
int F_112 ( struct V_2 * V_32 , struct V_82 * V_82 )
{
return F_159 ( & V_82 -> V_291 , F_158 ,
& V_32 -> V_38 ) ;
}
void F_160 ( struct V_2 * V_32 )
{
struct V_82 * V_82 ;
unsigned long V_63 ;
F_39 ( & V_32 -> V_38 , V_63 ) ;
if ( V_32 -> V_293 ) {
F_40 ( & V_32 -> V_38 , V_63 ) ;
return;
}
V_32 -> V_293 = 1 ;
F_74 ( & V_32 -> V_36 , & V_32 -> V_37 ) ;
F_161 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_82 -> V_296 = 1 ;
F_40 ( & V_32 -> V_38 , V_63 ) ;
}
void F_162 ( struct V_2 * V_32 )
{
struct V_82 * V_82 , * V_297 ;
unsigned long V_63 ;
F_75 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_50 ( & V_82 -> V_180 ) ;
F_37 ( L_121
L_122 , V_82 , V_82 -> V_95 ,
V_82 -> V_74 -> V_233 ( V_82 ) ) ;
F_126 ( & V_82 -> V_181 ) ;
F_37 ( L_123
L_124 , V_82 , V_82 -> V_95 ,
V_82 -> V_74 -> V_233 ( V_82 ) ) ;
V_82 -> V_74 -> V_295 ( V_82 ) ;
}
F_39 ( & V_32 -> V_38 , V_63 ) ;
F_67 ( ! F_51 ( & V_32 -> V_36 ) ) ;
F_40 ( & V_32 -> V_38 , V_63 ) ;
}
static int F_163 ( void * V_298 )
{
struct V_97 * V_104 = V_298 ;
F_164 ( & V_104 -> V_106 ) ;
F_126 ( & V_104 -> V_299 ) ;
F_47 ( & V_104 -> V_300 ) ;
return 0 ;
}
int F_165 ( struct V_97 * V_104 )
{
struct V_301 * V_302 ;
V_302 = F_166 ( F_163 , V_104 ,
L_125 , V_104 -> V_211 ) ;
if ( F_29 ( V_302 ) ) {
F_4 ( L_126 ) ;
return F_167 ( V_302 ) ;
}
F_126 ( & V_104 -> V_300 ) ;
return 0 ;
}
bool F_157 ( struct V_82 * V_83 )
{
unsigned long V_63 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( ! ( V_83 -> V_110 & V_289 ) &&
! ( V_83 -> V_110 & V_274 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
if ( ! ( V_83 -> V_110 & V_195 ) &&
! ( V_83 -> V_110 & V_274 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
if ( ! ( V_83 -> V_87 & V_102 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return false ;
}
V_83 -> V_87 |= V_98 ;
F_37 ( L_127
L_128 ,
V_83 , V_83 -> V_74 -> V_100 ( V_83 ) ,
V_83 -> V_74 -> V_233 ( V_83 ) , V_83 -> V_95 ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
F_126 ( & V_83 -> V_101 ) ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
V_83 -> V_87 &= ~ ( V_102 | V_98 ) ;
F_37 ( L_129
L_130 ,
V_83 -> V_74 -> V_100 ( V_83 ) ) ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
return true ;
}
static int F_168 (
struct V_82 * V_83 ,
T_3 * V_303 ,
T_3 * V_304 )
{
* V_303 = V_83 -> V_305 ;
* V_304 = V_83 -> V_306 ;
return 0 ;
}
int
F_111 ( struct V_82 * V_83 ,
T_4 V_307 , int V_308 )
{
unsigned char * V_309 = V_83 -> V_119 ;
unsigned long V_63 ;
T_3 V_303 = 0 , V_304 = 0 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_110 & V_111 ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return 0 ;
}
V_83 -> V_110 |= V_111 ;
F_40 ( & V_83 -> V_94 , V_63 ) ;
if ( ! V_307 && V_308 )
goto V_310;
if ( ! V_308 )
V_83 -> V_110 |= V_311 ;
switch ( V_307 ) {
case V_312 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_315 ;
V_309 [ V_316 ] = 0 ;
V_309 [ V_317 ] = 0 ;
break;
case V_237 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x25 ;
break;
case V_238 :
case V_319 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x20 ;
break;
case V_241 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x24 ;
break;
case V_244 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_320 ;
V_309 [ V_316 ] = 0x29 ;
V_309 [ V_317 ] = 0x03 ;
break;
case V_321 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_320 ;
V_309 [ V_316 ] = 0x0c ;
V_309 [ V_317 ] = 0x0d ;
break;
case V_173 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x24 ;
break;
case V_239 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x26 ;
break;
case V_240 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x1a ;
break;
case V_322 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_320 ;
V_309 [ V_316 ] = 0x0c ;
V_309 [ V_317 ] = 0x0c ;
break;
case V_323 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_320 ;
V_309 [ V_316 ] = 0x47 ;
V_309 [ V_317 ] = 0x05 ;
break;
case V_324 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_320 ;
V_309 [ V_316 ] = 0x11 ;
V_309 [ V_317 ] = 0x13 ;
break;
case V_242 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_325 ;
V_309 [ V_316 ] = 0x27 ;
break;
case V_243 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_318 ;
V_309 [ V_316 ] = 0x21 ;
break;
case V_245 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_326 ;
F_169 ( V_83 , & V_303 , & V_304 ) ;
V_309 [ V_316 ] = V_303 ;
V_309 [ V_317 ] = V_304 ;
break;
case V_246 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_315 ;
F_168 ( V_83 , & V_303 , & V_304 ) ;
V_309 [ V_316 ] = V_303 ;
V_309 [ V_317 ] = V_304 ;
break;
case V_327 :
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_328 ;
V_309 [ V_316 ] = 0x1d ;
V_309 [ V_317 ] = 0x00 ;
break;
case V_109 :
default:
V_309 [ 0 ] = 0x70 ;
V_309 [ V_313 ] = 10 ;
V_309 [ V_314 ] = V_315 ;
V_309 [ V_316 ] = 0x08 ;
break;
}
V_83 -> V_118 = V_329 ;
V_83 -> V_112 = V_113 ;
V_310:
F_129 ( V_83 ) ;
return V_83 -> V_74 -> V_251 ( V_83 ) ;
}
int F_136 ( struct V_82 * V_83 , int V_330 )
{
if ( ! ( V_83 -> V_87 & V_128 ) )
return 0 ;
if ( ! V_330 || ( V_83 -> V_110 & V_331 ) )
return 1 ;
F_37 ( L_131 ,
V_83 -> V_172 [ 0 ] , V_83 -> V_74 -> V_100 ( V_83 ) ) ;
V_83 -> V_110 |= V_331 ;
V_83 -> V_118 = V_332 ;
F_129 ( V_83 ) ;
V_83 -> V_74 -> V_251 ( V_83 ) ;
return 1 ;
}
void F_170 ( struct V_82 * V_83 )
{
unsigned long V_63 ;
F_39 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_110 & ( V_111 | V_331 ) ) {
F_40 ( & V_83 -> V_94 , V_63 ) ;
return;
}
F_40 ( & V_83 -> V_94 , V_63 ) ;
if ( V_83 -> V_140 == V_143 ) {
if ( V_83 -> V_74 -> V_333 ( V_83 ) != 0 ) {
V_83 -> V_87 |= V_128 ;
F_96 () ;
return;
}
}
V_83 -> V_118 = V_332 ;
F_60 ( V_83 ) ;
F_37 ( L_132
L_133 , V_83 -> V_172 [ 0 ] ,
V_83 -> V_74 -> V_100 ( V_83 ) ) ;
F_129 ( V_83 ) ;
V_83 -> V_74 -> V_251 ( V_83 ) ;
}
static void F_171 ( struct V_107 * V_108 )
{
struct V_82 * V_83 = F_42 ( V_108 , struct V_82 , V_108 ) ;
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_220 * V_334 = V_83 -> V_220 ;
int V_30 ;
switch ( V_334 -> V_335 ) {
case V_229 :
F_172 ( V_85 , V_334 , V_83 -> V_32 ) ;
break;
case V_336 :
case V_337 :
case V_338 :
V_334 -> V_221 = V_339 ;
break;
case V_340 :
V_30 = F_173 ( V_85 , V_334 , NULL , NULL ) ;
V_334 -> V_221 = ( ! V_30 ) ? V_341 :
V_342 ;
break;
case V_343 :
V_334 -> V_221 = V_342 ;
break;
case V_344 :
V_334 -> V_221 = V_342 ;
break;
default:
F_4 ( L_134 ,
V_334 -> V_335 ) ;
V_334 -> V_221 = V_342 ;
break;
}
V_83 -> V_95 = V_345 ;
V_83 -> V_74 -> V_223 ( V_83 ) ;
F_59 ( V_83 ) ;
}
int F_124 (
struct V_82 * V_83 )
{
F_69 ( & V_83 -> V_108 , F_171 ) ;
F_70 ( V_83 -> V_86 -> V_346 , & V_83 -> V_108 ) ;
return 0 ;
}
