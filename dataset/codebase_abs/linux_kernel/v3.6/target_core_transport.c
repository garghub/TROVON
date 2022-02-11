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
V_30 = F_14 ( L_24 ) ;
if ( V_30 != 0 )
F_4 ( L_25 ) ;
V_31 = 1 ;
return;
}
struct V_2 * F_15 ( void )
{
struct V_2 * V_32 ;
V_32 = F_16 ( V_1 , V_33 ) ;
if ( ! V_32 ) {
F_4 ( L_26
L_27 ) ;
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
F_27 ( L_28 ,
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
void F_31 ( struct V_57 * V_57 )
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
F_27 ( L_29 ,
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
F_27 ( L_30 ,
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
F_27 ( L_31 ,
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
if ( ! ( V_75 -> V_99 & V_100 ) )
F_50 ( V_75 ) ;
if ( F_49 ( V_75 ) )
return;
if ( remove )
F_53 ( V_75 ) ;
}
static void F_54 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_32 ( V_102 , struct V_74 , V_102 ) ;
F_55 ( V_75 ) ;
}
static unsigned char * F_56 ( struct V_74 * V_75 )
{
unsigned char * V_103 = V_75 -> V_104 ;
struct V_76 * V_77 = V_75 -> V_78 ;
T_1 V_105 = 0 ;
F_57 ( ! V_75 -> V_91 ) ;
if ( ! V_77 )
return NULL ;
if ( V_75 -> V_99 & V_106 )
return NULL ;
V_105 = V_75 -> V_66 -> V_107 ( V_75 , V_108 ) ;
V_75 -> V_109 = V_108 + V_105 ;
F_27 ( L_32 ,
V_77 -> V_110 -> V_111 , V_77 -> V_112 -> V_113 , V_75 -> V_114 ) ;
return & V_103 [ V_105 ] ;
}
void F_58 ( struct V_74 * V_75 , T_3 V_114 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
int V_115 = V_114 == V_116 ;
unsigned long V_55 ;
V_75 -> V_114 = V_114 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_79 &= ~ V_80 ;
if ( V_77 && V_77 -> V_112 -> V_117 ) {
V_77 -> V_112 -> V_117 ( V_75 ,
V_75 -> V_118 ,
F_56 ( V_75 ) ) ;
if ( V_75 -> V_99 & V_119 )
V_115 = 1 ;
}
if ( V_75 -> V_79 & V_120 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_121 ) ;
return;
}
if ( ! V_115 )
V_75 -> V_79 |= V_122 ;
if ( V_75 -> V_79 & V_123 &&
V_75 -> V_79 & V_92 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_93 ) ;
return;
} else if ( V_75 -> V_79 & V_122 ) {
V_75 -> V_124 = V_125 ;
F_59 ( & V_75 -> V_102 , F_54 ) ;
} else {
F_59 ( & V_75 -> V_102 , V_126 ) ;
}
V_75 -> V_127 = V_128 ;
V_75 -> V_79 |= ( V_129 | V_89 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_60 ( V_22 , & V_75 -> V_102 ) ;
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
static void F_62 ( struct V_101 * V_102 )
{
struct V_76 * V_77 = F_32 ( V_102 , struct V_76 ,
V_130 ) ;
F_63 ( V_131 ) ;
struct V_74 * V_75 , * V_132 ;
F_24 ( & V_77 -> V_133 ) ;
F_64 ( & V_77 -> V_131 , & V_131 ) ;
F_26 ( & V_77 -> V_133 ) ;
F_65 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_40 ( & V_75 -> V_134 ) ;
F_66 ( & V_77 -> V_135 ) ;
F_67 () ;
F_27 ( L_33
L_34 , V_75 -> V_66 -> V_54 () , V_75 ,
( V_75 -> V_127 == V_136 ) ? L_35 :
( V_75 -> V_127 == V_137 ) ? L_36
: L_37 ) ;
if ( V_75 -> V_127 == V_137 )
F_68 ( V_75 ) ;
else if ( V_75 -> V_127 == V_136 )
F_69 ( V_75 ) ;
}
}
unsigned char * F_70 ( struct V_74 * V_75 )
{
switch ( V_75 -> V_138 ) {
case V_139 :
return L_38 ;
case V_140 :
return L_39 ;
case V_141 :
return L_40 ;
case V_142 :
return L_41 ;
default:
break;
}
return L_37 ;
}
void F_71 (
struct V_76 * V_77 ,
char * V_143 ,
int * V_144 )
{
* V_144 += sprintf ( V_143 + * V_144 , L_42 ) ;
switch ( V_77 -> V_145 ) {
case V_146 :
* V_144 += sprintf ( V_143 + * V_144 , L_43 ) ;
break;
case V_147 :
* V_144 += sprintf ( V_143 + * V_144 , L_44 ) ;
break;
case V_148 :
* V_144 += sprintf ( V_143 + * V_144 , L_45 ) ;
break;
case V_149 :
case V_150 :
* V_144 += sprintf ( V_143 + * V_144 , L_46 ) ;
break;
default:
* V_144 += sprintf ( V_143 + * V_144 , L_47 , V_77 -> V_145 ) ;
break;
}
* V_144 += sprintf ( V_143 + * V_144 , L_48 , V_77 -> V_151 ) ;
* V_144 += sprintf ( V_143 + * V_144 , L_49 ,
V_77 -> V_152 -> V_153 . V_154 ,
V_77 -> V_152 -> V_153 . V_155 ) ;
* V_144 += sprintf ( V_143 + * V_144 , L_50 ) ;
}
void F_72 (
struct V_156 * V_157 ,
unsigned char * V_158 ,
int V_159 )
{
unsigned char V_44 [ V_160 ] ;
int V_161 ;
memset ( V_44 , 0 , V_160 ) ;
V_161 = sprintf ( V_44 , L_51 ) ;
switch ( V_157 -> V_162 ) {
case 0x00 :
sprintf ( V_44 + V_161 , L_52 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_161 , L_53 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_161 , L_54 ) ;
break;
case 0x30 :
sprintf ( V_44 + V_161 , L_55 ) ;
break;
case 0x40 :
sprintf ( V_44 + V_161 , L_56
L_57 ) ;
break;
case 0x50 :
sprintf ( V_44 + V_161 , L_58 ) ;
break;
case 0x60 :
sprintf ( V_44 + V_161 , L_59 ) ;
break;
case 0x70 :
sprintf ( V_44 + V_161 , L_60
L_57 ) ;
break;
case 0x80 :
sprintf ( V_44 + V_161 , L_61 ) ;
break;
default:
sprintf ( V_44 + V_161 , L_62 ,
V_157 -> V_162 ) ;
break;
}
if ( V_158 )
strncpy ( V_158 , V_44 , V_159 ) ;
else
F_27 ( L_63 , V_44 ) ;
}
void
F_73 ( struct V_156 * V_157 , unsigned char * V_163 )
{
if ( V_163 [ 1 ] & 0x80 ) {
V_157 -> V_162 = ( V_163 [ 0 ] & 0xf0 ) ;
V_157 -> V_164 = 1 ;
F_72 ( V_157 , NULL , 0 ) ;
}
}
int F_74 (
struct V_156 * V_157 ,
unsigned char * V_158 ,
int V_159 )
{
unsigned char V_44 [ V_160 ] ;
int V_30 = 0 ;
int V_161 ;
memset ( V_44 , 0 , V_160 ) ;
V_161 = sprintf ( V_44 , L_64 ) ;
switch ( V_157 -> V_165 ) {
case 0x00 :
sprintf ( V_44 + V_161 , L_65 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_161 , L_66 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_161 , L_67 ) ;
break;
default:
sprintf ( V_44 + V_161 , L_62 , V_157 -> V_165 ) ;
V_30 = - V_166 ;
break;
}
if ( V_158 )
strncpy ( V_158 , V_44 , V_159 ) ;
else
F_27 ( L_63 , V_44 ) ;
return V_30 ;
}
int F_75 ( struct V_156 * V_157 , unsigned char * V_163 )
{
V_157 -> V_165 = ( V_163 [ 1 ] & 0x30 ) ;
return F_74 ( V_157 , NULL , 0 ) ;
}
int F_76 (
struct V_156 * V_157 ,
unsigned char * V_158 ,
int V_159 )
{
unsigned char V_44 [ V_160 ] ;
int V_30 = 0 ;
int V_161 ;
memset ( V_44 , 0 , V_160 ) ;
V_161 = sprintf ( V_44 , L_68 ) ;
switch ( V_157 -> V_167 ) {
case 0x00 :
sprintf ( V_44 + V_161 , L_69 ) ;
break;
case 0x01 :
sprintf ( V_44 + V_161 , L_70 ) ;
break;
case 0x02 :
sprintf ( V_44 + V_161 , L_71 ) ;
break;
case 0x03 :
sprintf ( V_44 + V_161 , L_72 ) ;
break;
case 0x04 :
sprintf ( V_44 + V_161 , L_73 ) ;
break;
case 0x08 :
sprintf ( V_44 + V_161 , L_74 ) ;
break;
default:
sprintf ( V_44 + V_161 , L_75 ,
V_157 -> V_167 ) ;
V_30 = - V_166 ;
break;
}
if ( V_158 ) {
if ( V_159 < strlen ( V_44 ) + 1 )
return - V_166 ;
strncpy ( V_158 , V_44 , V_159 ) ;
} else {
F_27 ( L_63 , V_44 ) ;
}
return V_30 ;
}
int F_77 ( struct V_156 * V_157 , unsigned char * V_163 )
{
V_157 -> V_167 = ( V_163 [ 1 ] & 0x0f ) ;
return F_76 ( V_157 , NULL , 0 ) ;
}
int F_78 (
struct V_156 * V_157 ,
unsigned char * V_158 ,
int V_159 )
{
unsigned char V_44 [ V_160 ] ;
int V_30 = 0 ;
memset ( V_44 , 0 , V_160 ) ;
switch ( V_157 -> V_168 ) {
case 0x01 :
sprintf ( V_44 , L_76 ,
& V_157 -> V_169 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_44 , L_77 ,
& V_157 -> V_169 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_44 , L_78 ,
& V_157 -> V_169 [ 0 ] ) ;
break;
default:
sprintf ( V_44 , L_79
L_80 , V_157 -> V_168 ) ;
V_30 = - V_166 ;
break;
}
if ( V_158 )
strncpy ( V_158 , V_44 , V_159 ) ;
else
F_27 ( L_63 , V_44 ) ;
return V_30 ;
}
int
F_79 ( struct V_156 * V_157 , unsigned char * V_163 )
{
static const char V_170 [] = L_81 ;
int V_171 = 0 , V_172 = 4 ;
V_157 -> V_168 = ( V_163 [ 0 ] & 0x0f ) ;
switch ( V_157 -> V_168 ) {
case 0x01 :
V_157 -> V_169 [ V_171 ++ ] =
V_170 [ V_157 -> V_167 ] ;
while ( V_172 < ( 4 + V_163 [ 3 ] ) ) {
V_157 -> V_169 [ V_171 ++ ] =
V_170 [ ( V_163 [ V_172 ] & 0xf0 ) >> 4 ] ;
V_157 -> V_169 [ V_171 ++ ] =
V_170 [ V_163 [ V_172 ] & 0x0f ] ;
V_172 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_172 < ( 4 + V_163 [ 3 ] ) )
V_157 -> V_169 [ V_171 ++ ] = V_163 [ V_172 ++ ] ;
break;
default:
break;
}
return F_78 ( V_157 , NULL , 0 ) ;
}
static void F_80 ( struct V_76 * V_77 )
{
if ( V_77 -> V_112 -> V_173 == V_174 ) {
V_77 -> V_175 = V_176 ;
return;
}
V_77 -> V_175 = V_177 ;
F_27 ( L_82
L_83 , V_77 -> V_112 -> V_113 ,
V_77 -> V_112 -> V_178 ( V_77 ) ) ;
}
static void F_81 ( struct V_76 * V_77 )
{
struct V_179 * V_180 = & V_77 -> V_152 -> V_179 ;
char V_44 [ 17 ] ;
int V_172 , V_181 ;
for ( V_172 = 0 ; V_172 < 8 ; V_172 ++ )
if ( V_180 -> V_182 [ V_172 ] >= 0x20 )
V_44 [ V_172 ] = V_180 -> V_182 [ V_172 ] ;
else
V_44 [ V_172 ] = ' ' ;
V_44 [ V_172 ] = '\0' ;
F_27 ( L_84 , V_44 ) ;
for ( V_172 = 0 ; V_172 < 16 ; V_172 ++ )
if ( V_180 -> V_183 [ V_172 ] >= 0x20 )
V_44 [ V_172 ] = V_180 -> V_183 [ V_172 ] ;
else
V_44 [ V_172 ] = ' ' ;
V_44 [ V_172 ] = '\0' ;
F_27 ( L_85 , V_44 ) ;
for ( V_172 = 0 ; V_172 < 4 ; V_172 ++ )
if ( V_180 -> V_184 [ V_172 ] >= 0x20 )
V_44 [ V_172 ] = V_180 -> V_184 [ V_172 ] ;
else
V_44 [ V_172 ] = ' ' ;
V_44 [ V_172 ] = '\0' ;
F_27 ( L_86 , V_44 ) ;
V_181 = V_77 -> V_112 -> V_185 ( V_77 ) ;
F_27 ( L_87 , F_82 ( V_181 ) ) ;
F_27 ( L_88 ,
V_77 -> V_112 -> V_178 ( V_77 ) ) ;
}
struct V_76 * F_83 (
struct V_110 * V_186 ,
struct V_187 * V_112 ,
struct V_188 * V_78 ,
T_1 V_189 ,
void * V_190 ,
struct V_191 * V_192 ,
const char * V_193 ,
const char * V_194 )
{
int V_195 ;
struct V_76 * V_77 ;
V_77 = F_84 ( sizeof( struct V_76 ) , V_33 ) ;
if ( ! V_77 ) {
F_4 ( L_89 ) ;
return NULL ;
}
V_77 -> V_196 = V_189 ;
V_77 -> V_145 |= V_147 ;
V_77 -> V_197 = V_190 ;
V_77 -> V_110 = V_186 ;
V_77 -> V_152 = V_78 ;
V_77 -> V_112 = V_112 ;
F_18 ( & V_77 -> V_198 ) ;
F_18 ( & V_77 -> V_199 ) ;
F_18 ( & V_77 -> V_200 ) ;
F_18 ( & V_77 -> V_201 ) ;
F_18 ( & V_77 -> V_83 ) ;
F_18 ( & V_77 -> V_131 ) ;
F_19 ( & V_77 -> V_81 ) ;
F_19 ( & V_77 -> V_202 ) ;
F_19 ( & V_77 -> V_203 ) ;
F_19 ( & V_77 -> V_204 ) ;
F_19 ( & V_77 -> V_205 ) ;
F_19 ( & V_77 -> V_206 ) ;
F_19 ( & V_77 -> V_133 ) ;
F_85 ( & V_77 -> V_207 , 0 ) ;
F_86 ( V_77 , V_192 ) ;
V_77 -> V_208 = F_9 ( V_209 ) ;
V_77 -> V_210 = F_87 () ;
F_19 ( & V_77 -> V_211 ) ;
F_11 ( & V_186 -> V_212 ) ;
F_25 ( & V_77 -> V_198 , & V_186 -> V_213 ) ;
V_186 -> V_214 ++ ;
F_12 ( & V_186 -> V_212 ) ;
F_80 ( V_77 ) ;
V_195 = ( V_186 -> V_215 & V_216 ) ;
F_88 ( V_77 , V_195 ) ;
if ( F_89 ( V_77 , V_195 ) < 0 )
goto V_217;
V_77 -> V_218 = F_5 ( L_90 , V_23 | V_219 , 1 ,
V_77 -> V_112 -> V_113 ) ;
if ( ! V_77 -> V_218 ) {
F_4 ( L_91 ,
V_77 -> V_112 -> V_113 ) ;
goto V_217;
}
F_59 ( & V_77 -> V_130 , F_62 ) ;
if ( V_77 -> V_112 -> V_173 != V_174 ) {
if ( ! V_193 || ! V_194 ) {
F_4 ( L_92
L_93 ) ;
goto V_220;
}
strncpy ( & V_77 -> V_152 -> V_179 . V_182 [ 0 ] , L_94 , 8 ) ;
strncpy ( & V_77 -> V_152 -> V_179 . V_183 [ 0 ] , V_193 , 16 ) ;
strncpy ( & V_77 -> V_152 -> V_179 . V_184 [ 0 ] , V_194 , 4 ) ;
}
F_81 ( V_77 ) ;
return V_77 ;
V_220:
F_8 ( V_77 -> V_218 ) ;
V_217:
F_11 ( & V_186 -> V_212 ) ;
F_40 ( & V_77 -> V_198 ) ;
V_186 -> V_214 -- ;
F_12 ( & V_186 -> V_212 ) ;
F_90 ( V_77 ) ;
F_91 ( V_77 ) ;
return NULL ;
}
int F_92 ( struct V_74 * V_75 , unsigned int V_221 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_75 -> V_222 ) {
V_75 -> V_223 = V_221 ;
} else if ( V_221 != V_75 -> V_223 ) {
F_93 ( L_95
L_96
L_97 , V_75 -> V_66 -> V_54 () ,
V_75 -> V_223 , V_221 , V_75 -> V_224 [ 0 ] ) ;
if ( V_75 -> V_138 == V_141 ) {
F_4 ( L_98
L_99 ) ;
goto V_225;
}
if ( V_77 -> V_152 -> V_153 . V_154 != 512 ) {
F_4 ( L_100
L_101
L_102 , V_77 -> V_112 -> V_113 ) ;
goto V_225;
}
if ( V_221 > V_75 -> V_223 ) {
V_75 -> V_99 |= V_226 ;
V_75 -> V_227 = ( V_221 - V_75 -> V_223 ) ;
} else {
V_75 -> V_99 |= V_228 ;
V_75 -> V_227 = ( V_75 -> V_223 - V_221 ) ;
V_75 -> V_223 = V_221 ;
}
}
return 0 ;
V_225:
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_230 ;
return - V_166 ;
}
void F_94 (
struct V_74 * V_75 ,
struct V_65 * V_231 ,
struct V_2 * V_32 ,
T_1 V_223 ,
int V_138 ,
int V_232 ,
unsigned char * V_104 )
{
F_18 ( & V_75 -> V_98 ) ;
F_18 ( & V_75 -> V_233 ) ;
F_18 ( & V_75 -> V_134 ) ;
F_18 ( & V_75 -> V_234 ) ;
F_18 ( & V_75 -> V_83 ) ;
F_95 ( & V_75 -> V_235 ) ;
F_95 ( & V_75 -> V_90 ) ;
F_95 ( & V_75 -> V_93 ) ;
F_95 ( & V_75 -> V_236 ) ;
F_95 ( & V_75 -> V_121 ) ;
F_19 ( & V_75 -> V_85 ) ;
V_75 -> V_79 = V_96 ;
V_75 -> V_66 = V_231 ;
V_75 -> V_32 = V_32 ;
V_75 -> V_223 = V_223 ;
V_75 -> V_138 = V_138 ;
V_75 -> V_237 = V_232 ;
V_75 -> V_104 = V_104 ;
V_75 -> V_82 = false ;
}
static int F_96 ( struct V_74 * V_75 )
{
if ( V_75 -> V_78 -> V_175 != V_177 )
return 0 ;
if ( V_75 -> V_237 == V_238 ) {
F_27 ( L_103
L_104 ) ;
return - V_166 ;
}
V_75 -> V_239 = F_97 ( & V_75 -> V_78 -> V_207 ) ;
F_98 () ;
F_27 ( L_105 ,
V_75 -> V_239 , V_75 -> V_237 ,
V_75 -> V_78 -> V_112 -> V_113 ) ;
return 0 ;
}
int F_99 (
struct V_74 * V_75 ,
unsigned char * V_240 )
{
struct V_188 * V_241 = V_75 -> V_78 -> V_152 ;
T_1 V_242 = 0 ;
T_3 V_243 = 0 ;
unsigned long V_55 ;
int V_30 ;
if ( F_100 ( V_240 ) > V_244 ) {
F_4 ( L_106
L_107 ,
F_100 ( V_240 ) , V_244 ) ;
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_230 ;
return - V_166 ;
}
if ( F_100 ( V_240 ) > sizeof( V_75 -> V_245 ) ) {
V_75 -> V_224 = F_84 ( F_100 ( V_240 ) ,
V_33 ) ;
if ( ! V_75 -> V_224 ) {
F_4 ( L_108
L_109 ,
F_100 ( V_240 ) ,
( unsigned long ) sizeof( V_75 -> V_245 ) ) ;
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 =
V_125 ;
return - V_25 ;
}
} else
V_75 -> V_224 = & V_75 -> V_245 [ 0 ] ;
memcpy ( V_75 -> V_224 , V_240 , F_100 ( V_240 ) ) ;
if ( F_101 ( V_75 , V_240 ) < 0 ) {
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_246 ;
return - V_166 ;
}
V_30 = V_241 -> V_247 . V_248 ( V_75 , V_240 , & V_243 ) ;
if ( V_30 != 0 ) {
if ( V_30 > 0 ) {
F_27 ( L_110
L_111
L_112 ,
V_75 -> V_66 -> V_54 () , V_243 ) ;
F_102 ( V_75 , 0x04 , V_243 ) ;
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_249 ;
return - V_166 ;
}
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_230 ;
return - V_166 ;
}
if ( V_241 -> V_250 . V_251 . V_252 ( V_75 , & V_242 ) ) {
if ( V_241 -> V_250 . V_251 . V_253 (
V_75 , V_240 , V_242 ) != 0 ) {
V_75 -> V_99 |= V_229 ;
V_75 -> V_99 |= V_254 ;
V_75 -> V_114 = V_255 ;
V_75 -> V_124 = V_256 ;
return - V_257 ;
}
}
V_30 = V_75 -> V_78 -> V_112 -> V_258 ( V_75 ) ;
if ( V_30 < 0 )
return V_30 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_99 |= V_259 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( F_96 ( V_75 ) < 0 ) {
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_230 ;
return - V_166 ;
}
F_11 ( & V_75 -> V_91 -> V_260 ) ;
if ( V_75 -> V_91 -> V_261 )
V_75 -> V_91 -> V_261 -> V_262 . V_263 ++ ;
F_12 ( & V_75 -> V_91 -> V_260 ) ;
return 0 ;
}
int F_103 (
struct V_74 * V_75 )
{
int V_30 ;
if ( ! V_75 -> V_91 ) {
F_104 () ;
F_4 ( L_113 ) ;
return - V_166 ;
}
if ( F_105 () ) {
F_104 () ;
F_4 ( L_114
L_115 ) ;
return - V_166 ;
}
V_75 -> V_127 = V_264 ;
V_75 -> V_79 |= V_89 ;
V_30 = F_106 ( V_75 ) ;
if ( V_30 < 0 )
F_55 ( V_75 ) ;
return 0 ;
}
int F_107 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_240 , unsigned char * V_265 , T_1 V_266 ,
T_1 V_223 , int V_232 , int V_267 , int V_55 )
{
struct V_39 * V_40 ;
int V_268 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_10 ( V_74 -> V_66 || V_74 -> V_32 ) ;
F_10 ( F_105 () ) ;
F_94 ( V_74 , V_40 -> V_46 , V_32 ,
V_223 , V_267 , V_232 , V_265 ) ;
if ( V_55 & V_269 )
V_74 -> V_222 = 1 ;
V_268 = F_108 ( V_32 , V_74 , ( V_55 & V_270 ) ) ;
if ( V_268 )
return V_268 ;
if ( V_55 & V_271 )
V_74 -> V_99 |= V_272 ;
if ( F_109 ( V_74 , V_266 ) < 0 ) {
F_110 ( V_74 ,
V_74 -> V_124 , 0 ) ;
F_111 ( V_32 , V_74 ) ;
return 0 ;
}
V_268 = F_99 ( V_74 , V_240 ) ;
if ( V_268 != 0 ) {
F_55 ( V_74 ) ;
return 0 ;
}
F_112 ( V_74 ) ;
F_103 ( V_74 ) ;
return 0 ;
}
static void F_113 ( struct V_101 * V_102 )
{
struct V_74 * V_74 = F_32 ( V_102 , struct V_74 , V_102 ) ;
V_74 -> V_273 -> V_274 = V_275 ;
V_74 -> V_66 -> V_276 ( V_74 ) ;
F_114 ( V_74 , 0 ) ;
}
int F_115 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_265 , T_1 V_266 ,
void * V_277 , unsigned char V_278 ,
T_4 V_279 , unsigned int V_280 , int V_55 )
{
struct V_39 * V_40 ;
int V_30 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_94 ( V_74 , V_40 -> V_46 , V_32 ,
0 , V_139 , V_281 , V_265 ) ;
V_30 = F_116 ( V_74 , V_277 , V_278 , V_279 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_278 == V_282 )
V_74 -> V_273 -> V_283 = V_280 ;
V_30 = F_108 ( V_32 , V_74 , ( V_55 & V_270 ) ) ;
if ( V_30 ) {
F_117 ( V_74 -> V_273 ) ;
return V_30 ;
}
V_30 = F_118 ( V_74 , V_266 ) ;
if ( V_30 ) {
F_59 ( & V_74 -> V_102 , F_113 ) ;
F_119 ( & V_74 -> V_102 ) ;
return 0 ;
}
F_120 ( V_74 ) ;
return 0 ;
}
bool F_121 ( struct V_74 * V_75 , unsigned long * V_55 )
{
bool V_284 = false ;
if ( V_75 -> V_79 & V_80 ) {
V_75 -> V_79 |= V_120 ;
F_30 ( & V_75 -> V_85 , * V_55 ) ;
F_27 ( L_116 , V_75 ) ;
F_122 ( & V_75 -> V_121 ) ;
F_27 ( L_117 , V_75 ) ;
F_29 ( & V_75 -> V_85 , * V_55 ) ;
V_75 -> V_79 &= ~ V_120 ;
V_75 -> V_79 &= ~ V_80 ;
V_284 = true ;
}
return V_284 ;
}
void F_55 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
F_27 ( L_118
L_119 , V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_224 [ 0 ] ) ;
F_27 ( L_120 ,
V_75 -> V_66 -> V_285 ( V_75 ) ,
V_75 -> V_127 , V_75 -> V_124 ) ;
F_27 ( L_121 ,
( V_75 -> V_79 & V_89 ) != 0 ,
( V_75 -> V_79 & V_92 ) != 0 ,
( V_75 -> V_79 & V_286 ) != 0 ) ;
if ( V_75 -> V_78 -> V_175 == V_177 )
F_123 ( V_75 ) ;
switch ( V_75 -> V_124 ) {
case V_287 :
case V_288 :
case V_230 :
case V_289 :
case V_125 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_246 :
case V_249 :
break;
case V_256 :
V_75 -> V_114 = V_255 ;
if ( V_75 -> V_32 &&
V_75 -> V_78 -> V_152 -> V_153 . V_294 == 2 )
F_124 ( V_75 -> V_32 -> V_41 ,
V_75 -> V_295 , 0x2C ,
V_296 ) ;
V_30 = V_75 -> V_66 -> V_297 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
goto V_300;
default:
F_4 ( L_122 ,
V_75 -> V_224 [ 0 ] , V_75 -> V_124 ) ;
V_75 -> V_124 = V_288 ;
break;
}
V_30 = F_110 ( V_75 ,
V_75 -> V_124 , 0 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
V_300:
F_50 ( V_75 ) ;
if ( ! F_49 ( V_75 ) )
;
return;
V_299:
V_75 -> V_127 = V_136 ;
F_125 ( V_75 , V_75 -> V_78 ) ;
}
static void F_126 ( struct V_74 * V_75 )
{
int error = 0 ;
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 |= ( V_80 | V_286 ) ;
F_26 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_301 )
error = V_75 -> V_301 ( V_75 ) ;
if ( error ) {
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 &= ~ ( V_80 | V_286 ) ;
F_26 ( & V_75 -> V_85 ) ;
F_55 ( V_75 ) ;
}
}
void F_127 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( F_128 ( V_75 , 1 ) )
return;
F_24 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_30 ,
V_87 , __LINE__ , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_89 ;
F_26 ( & V_75 -> V_85 ) ;
F_37 ( & V_75 -> V_90 ) ;
return;
}
if ( V_75 -> V_79 & V_92 ) {
F_27 ( L_31 ,
V_87 , __LINE__ ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_26 ( & V_75 -> V_85 ) ;
F_37 ( & V_75 -> V_93 ) ;
return;
}
V_75 -> V_127 = V_302 ;
F_26 ( & V_75 -> V_85 ) ;
if ( V_77 -> V_175 != V_177 )
goto V_303;
switch ( V_75 -> V_237 ) {
case V_304 :
F_27 ( L_123
L_124 ,
V_75 -> V_224 [ 0 ] , V_75 -> V_239 ) ;
goto V_303;
case V_305 :
F_129 ( & V_77 -> V_306 ) ;
F_98 () ;
F_27 ( L_125
L_126 ,
V_75 -> V_224 [ 0 ] , V_75 -> V_239 ) ;
if ( ! F_130 ( & V_77 -> V_307 ) )
goto V_303;
break;
default:
F_129 ( & V_77 -> V_307 ) ;
F_98 () ;
break;
}
if ( F_130 ( & V_77 -> V_306 ) != 0 ) {
F_11 ( & V_77 -> V_202 ) ;
F_25 ( & V_75 -> V_233 , & V_77 -> V_201 ) ;
F_12 ( & V_77 -> V_202 ) ;
F_27 ( L_127
L_128 ,
V_75 -> V_224 [ 0 ] , V_75 -> V_237 ,
V_75 -> V_239 ) ;
return;
}
V_303:
F_126 ( V_75 ) ;
}
static void F_131 ( struct V_76 * V_77 )
{
for (; ; ) {
struct V_74 * V_75 ;
F_11 ( & V_77 -> V_202 ) ;
if ( F_41 ( & V_77 -> V_201 ) ) {
F_12 ( & V_77 -> V_202 ) ;
break;
}
V_75 = F_132 ( V_77 -> V_201 . V_308 ,
struct V_74 , V_233 ) ;
F_40 ( & V_75 -> V_233 ) ;
F_12 ( & V_77 -> V_202 ) ;
F_126 ( V_75 ) ;
if ( V_75 -> V_237 == V_305 )
break;
}
}
static void F_123 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_75 -> V_237 == V_281 ) {
F_66 ( & V_77 -> V_307 ) ;
F_67 () ;
V_77 -> V_309 ++ ;
F_27 ( L_129
L_130 , V_77 -> V_309 ,
V_75 -> V_239 ) ;
} else if ( V_75 -> V_237 == V_304 ) {
V_77 -> V_309 ++ ;
F_27 ( L_131
L_132 , V_77 -> V_309 ,
V_75 -> V_239 ) ;
} else if ( V_75 -> V_237 == V_305 ) {
F_66 ( & V_77 -> V_306 ) ;
F_67 () ;
V_77 -> V_309 ++ ;
F_27 ( L_133
L_134 , V_77 -> V_309 , V_75 -> V_239 ) ;
}
F_131 ( V_77 ) ;
}
static void F_69 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
if ( V_75 -> V_78 -> V_175 == V_177 )
F_123 ( V_75 ) ;
if ( V_75 -> V_99 & V_119 ) {
V_30 = V_75 -> V_66 -> V_297 ( V_75 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_75 -> V_138 ) {
case V_140 :
V_30 = V_75 -> V_66 -> V_310 ( V_75 ) ;
break;
case V_141 :
if ( V_75 -> V_311 ) {
V_30 = V_75 -> V_66 -> V_310 ( V_75 ) ;
if ( V_30 < 0 )
break;
}
case V_139 :
V_30 = V_75 -> V_66 -> V_297 ( V_75 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_125 ( V_75 , V_75 -> V_78 ) ;
return;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
}
static void F_125 (
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_24 ( & V_77 -> V_133 ) ;
F_25 ( & V_75 -> V_134 , & V_75 -> V_78 -> V_131 ) ;
F_129 ( & V_77 -> V_135 ) ;
F_98 () ;
F_26 ( & V_75 -> V_78 -> V_133 ) ;
F_119 ( & V_75 -> V_78 -> V_130 ) ;
}
static void V_126 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_32 ( V_102 , struct V_74 , V_102 ) ;
int V_30 ;
if ( V_75 -> V_78 -> V_175 == V_177 )
F_123 ( V_75 ) ;
if ( F_130 ( & V_75 -> V_78 -> V_135 ) != 0 )
F_119 ( & V_75 -> V_78 -> V_130 ) ;
if ( V_75 -> V_99 & V_119 ) {
F_57 ( ! V_75 -> V_114 ) ;
V_30 = F_110 (
V_75 , 0 , 1 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
}
if ( V_75 -> V_312 )
V_75 -> V_312 ( V_75 ) ;
switch ( V_75 -> V_138 ) {
case V_140 :
F_11 ( & V_75 -> V_91 -> V_260 ) ;
if ( V_75 -> V_91 -> V_261 ) {
V_75 -> V_91 -> V_261 -> V_262 . V_313 +=
V_75 -> V_223 ;
}
F_12 ( & V_75 -> V_91 -> V_260 ) ;
V_30 = V_75 -> V_66 -> V_310 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
break;
case V_141 :
F_11 ( & V_75 -> V_91 -> V_260 ) ;
if ( V_75 -> V_91 -> V_261 ) {
V_75 -> V_91 -> V_261 -> V_262 . V_314 +=
V_75 -> V_223 ;
}
F_12 ( & V_75 -> V_91 -> V_260 ) ;
if ( V_75 -> V_311 ) {
F_11 ( & V_75 -> V_91 -> V_260 ) ;
if ( V_75 -> V_91 -> V_261 ) {
V_75 -> V_91 -> V_261 -> V_262 . V_313 +=
V_75 -> V_223 ;
}
F_12 ( & V_75 -> V_91 -> V_260 ) ;
V_30 = V_75 -> V_66 -> V_310 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
break;
}
case V_139 :
V_30 = V_75 -> V_66 -> V_297 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
break;
default:
break;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
V_299:
F_27 ( L_135
L_136 , V_75 , V_75 -> V_138 ) ;
V_75 -> V_127 = V_136 ;
F_125 ( V_75 , V_75 -> V_78 ) ;
}
static inline void F_133 ( struct V_315 * V_316 , int V_317 )
{
struct V_315 * V_318 ;
int V_319 ;
F_134 (sgl, sg, nents, count)
F_135 ( F_136 ( V_318 ) ) ;
F_91 ( V_316 ) ;
}
static inline void F_137 ( struct V_74 * V_75 )
{
if ( V_75 -> V_99 & V_320 )
return;
F_133 ( V_75 -> V_118 , V_75 -> V_321 ) ;
V_75 -> V_118 = NULL ;
V_75 -> V_321 = 0 ;
F_133 ( V_75 -> V_311 , V_75 -> V_322 ) ;
V_75 -> V_311 = NULL ;
V_75 -> V_322 = 0 ;
}
static void F_138 ( struct V_74 * V_75 )
{
F_10 ( ! V_75 -> V_66 ) ;
if ( V_75 -> V_99 & V_100 )
F_117 ( V_75 -> V_273 ) ;
if ( V_75 -> V_224 != V_75 -> V_245 )
F_91 ( V_75 -> V_224 ) ;
if ( V_75 -> V_323 != 0 ) {
F_111 ( V_75 -> V_32 , V_75 ) ;
return;
}
V_75 -> V_66 -> V_324 ( V_75 ) ;
}
static void F_53 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( F_130 ( & V_75 -> V_325 ) ) {
if ( ! F_139 ( & V_75 -> V_325 ) )
goto V_326;
}
if ( V_75 -> V_79 & V_96 ) {
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_137 ( V_75 ) ;
F_138 ( V_75 ) ;
return;
V_326:
F_30 ( & V_75 -> V_85 , V_55 ) ;
}
int F_140 (
struct V_74 * V_75 ,
struct V_315 * V_316 ,
T_1 V_327 ,
struct V_315 * V_328 ,
T_1 V_329 )
{
if ( ! V_316 || ! V_327 )
return 0 ;
if ( V_75 -> V_99 & V_226 ) {
F_93 ( L_137
L_138 ) ;
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_230 ;
return - V_166 ;
}
V_75 -> V_118 = V_316 ;
V_75 -> V_321 = V_327 ;
if ( V_328 && V_329 ) {
V_75 -> V_311 = V_328 ;
V_75 -> V_322 = V_329 ;
}
V_75 -> V_99 |= V_320 ;
return 0 ;
}
void * F_141 ( struct V_74 * V_75 )
{
struct V_315 * V_318 = V_75 -> V_118 ;
struct V_330 * * V_331 ;
int V_172 ;
if ( ! V_75 -> V_321 )
return NULL ;
F_10 ( ! V_318 ) ;
if ( V_75 -> V_321 == 1 )
return F_142 ( F_136 ( V_318 ) ) + V_318 -> V_105 ;
V_331 = F_143 ( sizeof( * V_331 ) * V_75 -> V_321 , V_33 ) ;
if ( ! V_331 ) {
V_75 -> V_124 = V_125 ;
return NULL ;
}
F_134 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_331 [ V_172 ] = F_136 ( V_318 ) ;
}
V_75 -> V_332 = F_144 ( V_331 , V_75 -> V_321 , V_333 , V_334 ) ;
F_91 ( V_331 ) ;
if ( ! V_75 -> V_332 ) {
V_75 -> V_124 = V_125 ;
return NULL ;
}
return V_75 -> V_332 + V_75 -> V_118 [ 0 ] . V_105 ;
}
void F_145 ( struct V_74 * V_75 )
{
if ( ! V_75 -> V_321 ) {
return;
} else if ( V_75 -> V_321 == 1 ) {
F_146 ( F_136 ( V_75 -> V_118 ) ) ;
return;
}
F_147 ( V_75 -> V_332 ) ;
V_75 -> V_332 = NULL ;
}
static int
F_148 ( struct V_74 * V_75 )
{
T_1 V_335 = V_75 -> V_223 ;
unsigned int V_317 ;
struct V_330 * V_330 ;
T_4 V_336 ;
int V_172 = 0 ;
V_317 = F_149 ( V_335 , V_337 ) ;
V_75 -> V_118 = F_143 ( sizeof( struct V_315 ) * V_317 , V_33 ) ;
if ( ! V_75 -> V_118 )
return - V_25 ;
V_75 -> V_321 = V_317 ;
F_150 ( V_75 -> V_118 , V_317 ) ;
V_336 = V_75 -> V_99 & V_338 ? 0 : V_339 ;
while ( V_335 ) {
T_1 V_340 = F_151 ( T_1 , V_335 , V_337 ) ;
V_330 = F_152 ( V_33 | V_336 ) ;
if ( ! V_330 )
goto V_3;
F_153 ( & V_75 -> V_118 [ V_172 ] , V_330 , V_340 , 0 ) ;
V_335 -= V_340 ;
V_172 ++ ;
}
return 0 ;
V_3:
while ( V_172 > 0 ) {
V_172 -- ;
F_135 ( F_136 ( & V_75 -> V_118 [ V_172 ] ) ) ;
}
F_91 ( V_75 -> V_118 ) ;
V_75 -> V_118 = NULL ;
return - V_25 ;
}
int F_106 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
if ( ! ( V_75 -> V_99 & V_320 ) &&
V_75 -> V_223 ) {
V_30 = F_148 ( V_75 ) ;
if ( V_30 < 0 )
goto V_341;
}
if ( ! V_75 -> V_223 &&
V_75 -> V_224 [ 0 ] != V_342 &&
V_75 -> V_78 -> V_112 -> V_173 != V_174 ) {
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_127 = V_128 ;
V_75 -> V_79 |= V_89 ;
F_26 ( & V_75 -> V_85 ) ;
F_59 ( & V_75 -> V_102 , V_126 ) ;
F_60 ( V_22 , & V_75 -> V_102 ) ;
return 0 ;
}
F_129 ( & V_75 -> V_325 ) ;
F_61 ( V_75 ) ;
if ( V_75 -> V_138 != V_141 ) {
F_127 ( V_75 ) ;
return 0 ;
}
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_127 = V_343 ;
F_26 ( & V_75 -> V_85 ) ;
F_48 ( V_75 , false ) ;
V_30 = V_75 -> V_66 -> V_344 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 )
goto V_299;
if ( V_30 < 0 )
return V_30 ;
return 1 ;
V_341:
V_75 -> V_99 |= V_229 ;
V_75 -> V_124 = V_125 ;
return - V_166 ;
V_299:
F_27 ( L_139 , V_75 ) ;
V_75 -> V_127 = V_137 ;
F_125 ( V_75 , V_75 -> V_78 ) ;
return 0 ;
}
static void F_68 ( struct V_74 * V_75 )
{
int V_30 ;
V_30 = V_75 -> V_66 -> V_344 ( V_75 ) ;
if ( V_30 == - V_298 || V_30 == - V_25 ) {
F_27 ( L_139 ,
V_75 ) ;
F_125 ( V_75 , V_75 -> V_78 ) ;
}
}
void F_114 ( struct V_74 * V_75 , int V_345 )
{
if ( ! ( V_75 -> V_99 & V_346 ) ) {
if ( V_345 && ( V_75 -> V_99 & V_100 ) )
F_154 ( V_75 ) ;
F_138 ( V_75 ) ;
} else {
if ( V_345 )
F_154 ( V_75 ) ;
F_155 ( V_75 -> V_32 -> V_41 , V_75 ) ;
if ( V_75 -> V_91 )
F_50 ( V_75 ) ;
F_53 ( V_75 ) ;
}
}
static int F_108 ( struct V_2 * V_32 , struct V_74 * V_74 ,
bool V_347 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_20 ( & V_74 -> V_348 ) ;
if ( V_347 == true ) {
F_23 ( & V_74 -> V_348 ) ;
V_74 -> V_99 |= V_349 ;
}
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( V_32 -> V_350 ) {
V_30 = - V_351 ;
goto V_3;
}
F_25 ( & V_74 -> V_234 , & V_32 -> V_36 ) ;
V_74 -> V_323 = 1 ;
V_3:
F_30 ( & V_32 -> V_37 , V_55 ) ;
return V_30 ;
}
static void F_156 ( struct V_57 * V_57 )
{
struct V_74 * V_74 = F_32 ( V_57 , struct V_74 , V_348 ) ;
struct V_2 * V_32 = V_74 -> V_32 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( F_41 ( & V_74 -> V_234 ) ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_324 ( V_74 ) ;
return;
}
if ( V_32 -> V_350 && V_74 -> V_352 ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
F_37 ( & V_74 -> V_236 ) ;
return;
}
F_40 ( & V_74 -> V_234 ) ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_324 ( V_74 ) ;
}
int F_111 ( struct V_2 * V_32 , struct V_74 * V_74 )
{
return F_35 ( & V_74 -> V_348 , F_156 ) ;
}
void F_157 ( struct V_2 * V_32 )
{
struct V_74 * V_74 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
F_57 ( V_32 -> V_350 ) ;
V_32 -> V_350 = 1 ;
F_158 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list)
V_74 -> V_352 = 1 ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
}
void F_159 (
struct V_2 * V_32 ,
int V_345 )
{
struct V_74 * V_74 , * V_353 ;
bool V_268 = false ;
F_65 (se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
F_40 ( & V_74 -> V_234 ) ;
F_27 ( L_140
L_141 , V_74 , V_74 -> V_127 ,
V_74 -> V_66 -> V_285 ( V_74 ) ) ;
if ( V_345 ) {
F_27 ( L_142
L_143 , V_74 , V_74 -> V_127 ,
V_74 -> V_66 -> V_285 ( V_74 ) ) ;
V_268 = F_154 ( V_74 ) ;
F_27 ( L_144
L_143 , V_74 , V_74 -> V_127 ,
V_74 -> V_66 -> V_285 ( V_74 ) ) ;
}
if ( ! V_268 ) {
F_122 ( & V_74 -> V_236 ) ;
F_27 ( L_145
L_143 , V_74 , V_74 -> V_127 ,
V_74 -> V_66 -> V_285 ( V_74 ) ) ;
}
V_74 -> V_66 -> V_324 ( V_74 ) ;
}
}
static int F_160 ( struct V_74 * V_75 , struct V_91 * V_95 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_79 & V_92 ) {
V_75 -> V_79 &= ~ V_86 ;
F_27 ( L_146 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_48 ( V_75 , false ) ;
return - V_354 ;
}
V_75 -> V_79 |= V_355 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ( V_75 -> V_79 & V_80 ) &&
( V_75 -> V_79 & V_286 ) ) {
if ( ! F_121 ( V_75 , & V_55 ) )
V_30 ++ ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_27 ( L_147
L_141 , V_75 , V_30 ) ;
if ( ! V_30 ) {
F_27 ( L_148 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_122 ( & V_75 -> V_90 ) ;
F_27 ( L_149 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
}
return 0 ;
}
static void F_161 ( struct V_91 * V_95 )
{
struct V_74 * V_75 = NULL ;
unsigned long V_356 , V_357 ;
F_29 ( & V_95 -> V_97 , V_356 ) ;
while ( ! F_41 ( & V_95 -> V_358 ) ) {
V_75 = F_162 ( & V_95 -> V_358 ,
struct V_74 , V_98 ) ;
F_51 ( & V_75 -> V_98 ) ;
F_11 ( & V_75 -> V_85 ) ;
F_27 ( L_150
L_151 ,
V_75 -> V_91 -> V_266 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 |= V_86 ;
F_12 ( & V_75 -> V_85 ) ;
F_30 ( & V_95 -> V_97 , V_356 ) ;
if ( ! V_75 -> V_91 ) {
F_4 ( L_152 ,
V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_285 ( V_75 ) , V_75 -> V_127 ) ;
F_163 () ;
}
F_27 ( L_153
L_154 , V_75 -> V_91 -> V_266 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
if ( F_160 ( V_75 , V_75 -> V_91 ) < 0 ) {
F_29 ( & V_95 -> V_97 , V_356 ) ;
continue;
}
F_27 ( L_155
L_156 ,
V_75 -> V_91 -> V_266 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_29 ( & V_75 -> V_85 , V_357 ) ;
if ( ! ( V_75 -> V_79 & V_96 ) ) {
F_30 ( & V_75 -> V_85 , V_357 ) ;
goto V_359;
}
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
F_30 ( & V_75 -> V_85 , V_357 ) ;
V_359:
F_110 ( V_75 ,
V_287 , 0 ) ;
F_29 ( & V_75 -> V_85 , V_357 ) ;
if ( V_75 -> V_79 & V_355 ) {
F_27 ( L_157
L_158 ,
V_95 -> V_266 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 ,
V_357 ) ;
F_48 ( V_75 , false ) ;
F_37 ( & V_75 -> V_235 ) ;
F_29 ( & V_95 -> V_97 , V_356 ) ;
continue;
}
F_27 ( L_159 ,
V_95 -> V_266 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_357 ) ;
F_29 ( & V_95 -> V_97 , V_356 ) ;
}
F_30 ( & V_95 -> V_97 , V_356 ) ;
}
static int F_164 ( void * V_360 )
{
struct V_91 * V_95 = V_360 ;
F_161 ( V_95 ) ;
F_37 ( & V_95 -> V_361 ) ;
return 0 ;
}
int F_165 ( struct V_91 * V_95 )
{
struct V_362 * V_363 ;
V_363 = F_166 ( F_164 , V_95 ,
L_160 , V_95 -> V_266 ) ;
if ( F_167 ( V_363 ) ) {
F_4 ( L_161 ) ;
return F_168 ( V_363 ) ;
}
F_122 ( & V_95 -> V_361 ) ;
return 0 ;
}
bool F_154 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ! ( V_75 -> V_99 & V_346 ) &&
! ( V_75 -> V_99 & V_100 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( ! ( V_75 -> V_99 & V_259 ) &&
! ( V_75 -> V_99 & V_100 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_162
L_163
L_164 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_90 ) ;
F_122 ( & V_75 -> V_235 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
F_47 ( V_75 ) ;
F_27 ( L_165
L_166
L_167 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_86 ;
}
if ( ! ( V_75 -> V_79 & V_89 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
V_75 -> V_79 |= V_92 ;
F_27 ( L_168
L_169 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_285 ( V_75 ) , V_75 -> V_127 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_122 ( & V_75 -> V_93 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_79 &= ~ ( V_89 | V_92 ) ;
F_27 ( L_170
L_171 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
return true ;
}
static int F_169 (
struct V_74 * V_75 ,
T_3 * V_364 ,
T_3 * V_365 )
{
* V_364 = V_75 -> V_366 ;
* V_365 = V_75 -> V_367 ;
return 0 ;
}
static int F_102 (
struct V_74 * V_75 ,
T_3 V_364 ,
T_3 V_365 )
{
V_75 -> V_366 = V_364 ;
V_75 -> V_367 = V_365 ;
return 0 ;
}
int F_110 (
struct V_74 * V_75 ,
T_3 V_368 ,
int V_369 )
{
unsigned char * V_103 = V_75 -> V_104 ;
unsigned long V_55 ;
int V_105 ;
T_3 V_364 = 0 , V_365 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_99 & V_106 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return 0 ;
}
V_75 -> V_99 |= V_106 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( ! V_368 && V_369 )
goto V_370;
if ( ! V_369 )
V_75 -> V_99 |= V_371 ;
V_105 = V_75 -> V_66 -> V_107 ( V_75 ,
V_108 ) ;
switch ( V_368 ) {
case V_287 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x25 ;
break;
case V_288 :
case V_376 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x20 ;
break;
case V_290 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x24 ;
break;
case V_293 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_377 ;
V_103 [ V_105 + V_375 ] = 0x29 ;
V_103 [ V_105 + V_378 ] = 0x03 ;
break;
case V_379 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_377 ;
V_103 [ V_105 + V_375 ] = 0x0c ;
V_103 [ V_105 + V_378 ] = 0x0d ;
break;
case V_230 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x24 ;
break;
case V_289 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x26 ;
break;
case V_380 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_377 ;
V_103 [ V_105 + V_375 ] = 0x0c ;
V_103 [ V_105 + V_378 ] = 0x0c ;
break;
case V_381 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_377 ;
V_103 [ V_105 + V_375 ] = 0x47 ;
V_103 [ V_105 + V_378 ] = 0x05 ;
break;
case V_382 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_377 ;
V_103 [ V_105 + V_375 ] = 0x11 ;
V_103 [ V_105 + V_378 ] = 0x13 ;
break;
case V_291 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_383 ;
V_103 [ V_105 + V_375 ] = 0x27 ;
break;
case V_292 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x21 ;
break;
case V_246 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_384 ;
F_170 ( V_75 , & V_364 , & V_365 ) ;
V_103 [ V_105 + V_375 ] = V_364 ;
V_103 [ V_105 + V_378 ] = V_365 ;
break;
case V_249 :
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_385 ;
F_169 ( V_75 , & V_364 , & V_365 ) ;
V_103 [ V_105 + V_375 ] = V_364 ;
V_103 [ V_105 + V_378 ] = V_365 ;
break;
case V_125 :
default:
V_103 [ V_105 ] = 0x70 ;
V_103 [ V_105 + V_372 ] = 10 ;
V_103 [ V_105 + V_373 ] = V_374 ;
V_103 [ V_105 + V_375 ] = 0x80 ;
break;
}
V_75 -> V_114 = V_386 ;
V_75 -> V_109 = V_108 + V_105 ;
V_370:
return V_75 -> V_66 -> V_297 ( V_75 ) ;
}
int F_128 ( struct V_74 * V_75 , int V_387 )
{
int V_30 = 0 ;
if ( V_75 -> V_79 & V_123 ) {
if ( ! V_387 ||
( V_75 -> V_99 & V_388 ) )
return 1 ;
F_27 ( L_172
L_173 ,
V_75 -> V_224 [ 0 ] ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_99 |= V_388 ;
V_75 -> V_66 -> V_297 ( V_75 ) ;
V_30 = 1 ;
}
return V_30 ;
}
void F_171 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_99 & V_106 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_138 == V_141 ) {
if ( V_75 -> V_66 -> V_389 ( V_75 ) != 0 ) {
V_75 -> V_79 |= V_123 ;
F_98 () ;
}
}
V_75 -> V_114 = V_390 ;
F_27 ( L_174
L_175 , V_75 -> V_224 [ 0 ] ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_66 -> V_297 ( V_75 ) ;
}
static void F_172 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_32 ( V_102 , struct V_74 , V_102 ) ;
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_273 * V_391 = V_75 -> V_273 ;
int V_30 ;
switch ( V_391 -> V_392 ) {
case V_282 :
F_173 ( V_77 , V_391 , V_75 -> V_32 ) ;
break;
case V_393 :
case V_394 :
case V_395 :
V_391 -> V_274 = V_396 ;
break;
case V_397 :
V_30 = F_174 ( V_77 , V_391 , NULL , NULL ) ;
V_391 -> V_274 = ( ! V_30 ) ? V_398 :
V_399 ;
break;
case V_400 :
V_391 -> V_274 = V_399 ;
break;
case V_401 :
V_391 -> V_274 = V_399 ;
break;
default:
F_4 ( L_176 ,
V_391 -> V_392 ) ;
V_391 -> V_274 = V_399 ;
break;
}
V_75 -> V_127 = V_402 ;
V_75 -> V_66 -> V_276 ( V_75 ) ;
F_49 ( V_75 ) ;
}
int F_120 (
struct V_74 * V_75 )
{
F_59 ( & V_75 -> V_102 , F_172 ) ;
F_60 ( V_75 -> V_78 -> V_218 , & V_75 -> V_102 ) ;
return 0 ;
}
