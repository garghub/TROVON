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
struct V_76 * V_77 = V_75 -> V_78 ;
F_57 ( ! V_75 -> V_91 ) ;
if ( ! V_77 )
return NULL ;
if ( V_75 -> V_99 & V_103 )
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
if ( V_75 -> V_99 & V_116 )
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
V_75 -> V_121 = V_122 ;
F_59 ( & V_75 -> V_102 , F_54 ) ;
} else {
F_59 ( & V_75 -> V_102 , V_123 ) ;
}
V_75 -> V_124 = V_125 ;
V_75 -> V_79 |= ( V_126 | V_89 ) ;
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
V_127 ) ;
F_63 ( V_128 ) ;
struct V_74 * V_75 , * V_129 ;
F_24 ( & V_77 -> V_130 ) ;
F_64 ( & V_77 -> V_128 , & V_128 ) ;
F_26 ( & V_77 -> V_130 ) ;
F_65 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_40 ( & V_75 -> V_131 ) ;
F_66 ( & V_77 -> V_132 ) ;
F_67 () ;
F_27 ( L_31
L_32 , V_75 -> V_66 -> V_54 () , V_75 ,
( V_75 -> V_124 == V_133 ) ? L_33 :
( V_75 -> V_124 == V_134 ) ? L_34
: L_35 ) ;
if ( V_75 -> V_124 == V_134 )
F_68 ( V_75 ) ;
else if ( V_75 -> V_124 == V_133 )
F_69 ( V_75 ) ;
}
}
unsigned char * F_70 ( struct V_74 * V_75 )
{
switch ( V_75 -> V_135 ) {
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
struct V_76 * V_77 ,
char * V_140 ,
int * V_141 )
{
* V_141 += sprintf ( V_140 + * V_141 , L_40 ) ;
switch ( V_77 -> V_142 ) {
case V_143 :
* V_141 += sprintf ( V_140 + * V_141 , L_41 ) ;
break;
case V_144 :
* V_141 += sprintf ( V_140 + * V_141 , L_42 ) ;
break;
case V_145 :
* V_141 += sprintf ( V_140 + * V_141 , L_43 ) ;
break;
case V_146 :
case V_147 :
* V_141 += sprintf ( V_140 + * V_141 , L_44 ) ;
break;
default:
* V_141 += sprintf ( V_140 + * V_141 , L_45 , V_77 -> V_142 ) ;
break;
}
* V_141 += sprintf ( V_140 + * V_141 , L_46 , V_77 -> V_148 ) ;
* V_141 += sprintf ( V_140 + * V_141 , L_47 ,
V_77 -> V_149 -> V_150 . V_151 ,
V_77 -> V_149 -> V_150 . V_152 ) ;
* V_141 += sprintf ( V_140 + * V_141 , L_48 ) ;
}
void F_72 (
struct V_153 * V_154 ,
unsigned char * V_155 ,
int V_156 )
{
unsigned char V_44 [ V_157 ] ;
int V_158 ;
memset ( V_44 , 0 , V_157 ) ;
V_158 = sprintf ( V_44 , L_49 ) ;
switch ( V_154 -> V_159 ) {
case 0x00 :
sprintf ( V_44 + V_158 , L_50 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_158 , L_51 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_158 , L_52 ) ;
break;
case 0x30 :
sprintf ( V_44 + V_158 , L_53 ) ;
break;
case 0x40 :
sprintf ( V_44 + V_158 , L_54
L_55 ) ;
break;
case 0x50 :
sprintf ( V_44 + V_158 , L_56 ) ;
break;
case 0x60 :
sprintf ( V_44 + V_158 , L_57 ) ;
break;
case 0x70 :
sprintf ( V_44 + V_158 , L_58
L_55 ) ;
break;
case 0x80 :
sprintf ( V_44 + V_158 , L_59 ) ;
break;
default:
sprintf ( V_44 + V_158 , L_60 ,
V_154 -> V_159 ) ;
break;
}
if ( V_155 )
strncpy ( V_155 , V_44 , V_156 ) ;
else
F_27 ( L_61 , V_44 ) ;
}
void
F_73 ( struct V_153 * V_154 , unsigned char * V_160 )
{
if ( V_160 [ 1 ] & 0x80 ) {
V_154 -> V_159 = ( V_160 [ 0 ] & 0xf0 ) ;
V_154 -> V_161 = 1 ;
F_72 ( V_154 , NULL , 0 ) ;
}
}
int F_74 (
struct V_153 * V_154 ,
unsigned char * V_155 ,
int V_156 )
{
unsigned char V_44 [ V_157 ] ;
int V_30 = 0 ;
int V_158 ;
memset ( V_44 , 0 , V_157 ) ;
V_158 = sprintf ( V_44 , L_62 ) ;
switch ( V_154 -> V_162 ) {
case 0x00 :
sprintf ( V_44 + V_158 , L_63 ) ;
break;
case 0x10 :
sprintf ( V_44 + V_158 , L_64 ) ;
break;
case 0x20 :
sprintf ( V_44 + V_158 , L_65 ) ;
break;
default:
sprintf ( V_44 + V_158 , L_60 , V_154 -> V_162 ) ;
V_30 = - V_163 ;
break;
}
if ( V_155 )
strncpy ( V_155 , V_44 , V_156 ) ;
else
F_27 ( L_61 , V_44 ) ;
return V_30 ;
}
int F_75 ( struct V_153 * V_154 , unsigned char * V_160 )
{
V_154 -> V_162 = ( V_160 [ 1 ] & 0x30 ) ;
return F_74 ( V_154 , NULL , 0 ) ;
}
int F_76 (
struct V_153 * V_154 ,
unsigned char * V_155 ,
int V_156 )
{
unsigned char V_44 [ V_157 ] ;
int V_30 = 0 ;
int V_158 ;
memset ( V_44 , 0 , V_157 ) ;
V_158 = sprintf ( V_44 , L_66 ) ;
switch ( V_154 -> V_164 ) {
case 0x00 :
sprintf ( V_44 + V_158 , L_67 ) ;
break;
case 0x01 :
sprintf ( V_44 + V_158 , L_68 ) ;
break;
case 0x02 :
sprintf ( V_44 + V_158 , L_69 ) ;
break;
case 0x03 :
sprintf ( V_44 + V_158 , L_70 ) ;
break;
case 0x04 :
sprintf ( V_44 + V_158 , L_71 ) ;
break;
case 0x08 :
sprintf ( V_44 + V_158 , L_72 ) ;
break;
default:
sprintf ( V_44 + V_158 , L_73 ,
V_154 -> V_164 ) ;
V_30 = - V_163 ;
break;
}
if ( V_155 ) {
if ( V_156 < strlen ( V_44 ) + 1 )
return - V_163 ;
strncpy ( V_155 , V_44 , V_156 ) ;
} else {
F_27 ( L_61 , V_44 ) ;
}
return V_30 ;
}
int F_77 ( struct V_153 * V_154 , unsigned char * V_160 )
{
V_154 -> V_164 = ( V_160 [ 1 ] & 0x0f ) ;
return F_76 ( V_154 , NULL , 0 ) ;
}
int F_78 (
struct V_153 * V_154 ,
unsigned char * V_155 ,
int V_156 )
{
unsigned char V_44 [ V_157 ] ;
int V_30 = 0 ;
memset ( V_44 , 0 , V_157 ) ;
switch ( V_154 -> V_165 ) {
case 0x01 :
sprintf ( V_44 , L_74 ,
& V_154 -> V_166 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_44 , L_75 ,
& V_154 -> V_166 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_44 , L_76 ,
& V_154 -> V_166 [ 0 ] ) ;
break;
default:
sprintf ( V_44 , L_77
L_78 , V_154 -> V_165 ) ;
V_30 = - V_163 ;
break;
}
if ( V_155 )
strncpy ( V_155 , V_44 , V_156 ) ;
else
F_27 ( L_61 , V_44 ) ;
return V_30 ;
}
int
F_79 ( struct V_153 * V_154 , unsigned char * V_160 )
{
static const char V_167 [] = L_79 ;
int V_168 = 0 , V_169 = 4 ;
V_154 -> V_165 = ( V_160 [ 0 ] & 0x0f ) ;
switch ( V_154 -> V_165 ) {
case 0x01 :
V_154 -> V_166 [ V_168 ++ ] =
V_167 [ V_154 -> V_164 ] ;
while ( V_169 < ( 4 + V_160 [ 3 ] ) ) {
V_154 -> V_166 [ V_168 ++ ] =
V_167 [ ( V_160 [ V_169 ] & 0xf0 ) >> 4 ] ;
V_154 -> V_166 [ V_168 ++ ] =
V_167 [ V_160 [ V_169 ] & 0x0f ] ;
V_169 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_169 < ( 4 + V_160 [ 3 ] ) )
V_154 -> V_166 [ V_168 ++ ] = V_160 [ V_169 ++ ] ;
break;
default:
break;
}
return F_78 ( V_154 , NULL , 0 ) ;
}
static void F_80 ( struct V_76 * V_77 )
{
if ( V_77 -> V_108 -> V_170 == V_171 ) {
V_77 -> V_172 = V_173 ;
return;
}
V_77 -> V_172 = V_174 ;
F_27 ( L_80
L_81 , V_77 -> V_108 -> V_109 ,
V_77 -> V_108 -> V_175 ( V_77 ) ) ;
}
static void F_81 ( struct V_76 * V_77 )
{
struct V_176 * V_177 = & V_77 -> V_149 -> V_176 ;
char V_44 [ 17 ] ;
int V_169 , V_178 ;
for ( V_169 = 0 ; V_169 < 8 ; V_169 ++ )
if ( V_177 -> V_179 [ V_169 ] >= 0x20 )
V_44 [ V_169 ] = V_177 -> V_179 [ V_169 ] ;
else
V_44 [ V_169 ] = ' ' ;
V_44 [ V_169 ] = '\0' ;
F_27 ( L_82 , V_44 ) ;
for ( V_169 = 0 ; V_169 < 16 ; V_169 ++ )
if ( V_177 -> V_180 [ V_169 ] >= 0x20 )
V_44 [ V_169 ] = V_177 -> V_180 [ V_169 ] ;
else
V_44 [ V_169 ] = ' ' ;
V_44 [ V_169 ] = '\0' ;
F_27 ( L_83 , V_44 ) ;
for ( V_169 = 0 ; V_169 < 4 ; V_169 ++ )
if ( V_177 -> V_181 [ V_169 ] >= 0x20 )
V_44 [ V_169 ] = V_177 -> V_181 [ V_169 ] ;
else
V_44 [ V_169 ] = ' ' ;
V_44 [ V_169 ] = '\0' ;
F_27 ( L_84 , V_44 ) ;
V_178 = V_77 -> V_108 -> V_182 ( V_77 ) ;
F_27 ( L_85 , F_82 ( V_178 ) ) ;
F_27 ( L_86 ,
V_77 -> V_108 -> V_175 ( V_77 ) ) ;
}
struct V_76 * F_83 (
struct V_106 * V_183 ,
struct V_184 * V_108 ,
struct V_185 * V_78 ,
T_1 V_186 ,
void * V_187 ,
struct V_188 * V_189 ,
const char * V_190 ,
const char * V_191 )
{
int V_192 ;
struct V_76 * V_77 ;
V_77 = F_84 ( sizeof( struct V_76 ) , V_33 ) ;
if ( ! V_77 ) {
F_4 ( L_87 ) ;
return NULL ;
}
V_77 -> V_193 = V_186 ;
V_77 -> V_142 |= V_144 ;
V_77 -> V_194 = V_187 ;
V_77 -> V_106 = V_183 ;
V_77 -> V_149 = V_78 ;
V_77 -> V_108 = V_108 ;
F_18 ( & V_77 -> V_195 ) ;
F_18 ( & V_77 -> V_196 ) ;
F_18 ( & V_77 -> V_197 ) ;
F_18 ( & V_77 -> V_198 ) ;
F_18 ( & V_77 -> V_83 ) ;
F_18 ( & V_77 -> V_128 ) ;
F_19 ( & V_77 -> V_81 ) ;
F_19 ( & V_77 -> V_199 ) ;
F_19 ( & V_77 -> V_200 ) ;
F_19 ( & V_77 -> V_201 ) ;
F_19 ( & V_77 -> V_202 ) ;
F_19 ( & V_77 -> V_203 ) ;
F_19 ( & V_77 -> V_130 ) ;
F_85 ( & V_77 -> V_204 , 0 ) ;
F_86 ( V_77 , V_189 ) ;
V_77 -> V_205 = F_9 ( V_206 ) ;
V_77 -> V_207 = F_87 () ;
F_19 ( & V_77 -> V_208 ) ;
F_11 ( & V_183 -> V_209 ) ;
F_25 ( & V_77 -> V_195 , & V_183 -> V_210 ) ;
V_183 -> V_211 ++ ;
F_12 ( & V_183 -> V_209 ) ;
F_80 ( V_77 ) ;
V_192 = ( V_183 -> V_212 & V_213 ) ;
F_88 ( V_77 , V_192 ) ;
if ( F_89 ( V_77 , V_192 ) < 0 )
goto V_214;
V_77 -> V_215 = F_5 ( L_88 , V_23 | V_216 , 1 ,
V_77 -> V_108 -> V_109 ) ;
if ( ! V_77 -> V_215 ) {
F_4 ( L_89 ,
V_77 -> V_108 -> V_109 ) ;
goto V_214;
}
F_59 ( & V_77 -> V_127 , F_62 ) ;
if ( V_77 -> V_108 -> V_170 != V_171 ) {
if ( ! V_190 || ! V_191 ) {
F_4 ( L_90
L_91 ) ;
goto V_217;
}
strncpy ( & V_77 -> V_149 -> V_176 . V_179 [ 0 ] , L_92 , 8 ) ;
strncpy ( & V_77 -> V_149 -> V_176 . V_180 [ 0 ] , V_190 , 16 ) ;
strncpy ( & V_77 -> V_149 -> V_176 . V_181 [ 0 ] , V_191 , 4 ) ;
}
F_81 ( V_77 ) ;
return V_77 ;
V_217:
F_8 ( V_77 -> V_215 ) ;
V_214:
F_11 ( & V_183 -> V_209 ) ;
F_40 ( & V_77 -> V_195 ) ;
V_183 -> V_211 -- ;
F_12 ( & V_183 -> V_209 ) ;
F_90 ( V_77 ) ;
F_91 ( V_77 ) ;
return NULL ;
}
int F_92 ( struct V_74 * V_75 , unsigned int V_218 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_75 -> V_219 ) {
V_75 -> V_220 = V_218 ;
} else if ( V_218 != V_75 -> V_220 ) {
F_93 ( L_93
L_94
L_95 , V_75 -> V_66 -> V_54 () ,
V_75 -> V_220 , V_218 , V_75 -> V_221 [ 0 ] ) ;
if ( V_75 -> V_135 == V_138 ) {
F_4 ( L_96
L_97 ) ;
goto V_222;
}
if ( V_77 -> V_149 -> V_150 . V_151 != 512 ) {
F_4 ( L_98
L_99
L_100 , V_77 -> V_108 -> V_109 ) ;
goto V_222;
}
if ( V_218 > V_75 -> V_220 ) {
V_75 -> V_99 |= V_223 ;
V_75 -> V_224 = ( V_218 - V_75 -> V_220 ) ;
} else {
V_75 -> V_99 |= V_225 ;
V_75 -> V_224 = ( V_75 -> V_220 - V_218 ) ;
V_75 -> V_220 = V_218 ;
}
}
return 0 ;
V_222:
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_227 ;
return - V_163 ;
}
void F_94 (
struct V_74 * V_75 ,
struct V_65 * V_228 ,
struct V_2 * V_32 ,
T_1 V_220 ,
int V_135 ,
int V_229 ,
unsigned char * V_111 )
{
F_18 ( & V_75 -> V_98 ) ;
F_18 ( & V_75 -> V_230 ) ;
F_18 ( & V_75 -> V_131 ) ;
F_18 ( & V_75 -> V_231 ) ;
F_18 ( & V_75 -> V_83 ) ;
F_95 ( & V_75 -> V_232 ) ;
F_95 ( & V_75 -> V_90 ) ;
F_95 ( & V_75 -> V_93 ) ;
F_95 ( & V_75 -> V_233 ) ;
F_95 ( & V_75 -> V_118 ) ;
F_19 ( & V_75 -> V_85 ) ;
V_75 -> V_79 = V_96 ;
V_75 -> V_66 = V_228 ;
V_75 -> V_32 = V_32 ;
V_75 -> V_220 = V_220 ;
V_75 -> V_135 = V_135 ;
V_75 -> V_234 = V_229 ;
V_75 -> V_111 = V_111 ;
V_75 -> V_82 = false ;
}
static int F_96 ( struct V_74 * V_75 )
{
if ( V_75 -> V_78 -> V_172 != V_174 )
return 0 ;
if ( V_75 -> V_234 == V_235 ) {
F_27 ( L_101
L_102 ) ;
return - V_163 ;
}
V_75 -> V_236 = F_97 ( & V_75 -> V_78 -> V_204 ) ;
F_98 () ;
F_27 ( L_103 ,
V_75 -> V_236 , V_75 -> V_234 ,
V_75 -> V_78 -> V_108 -> V_109 ) ;
return 0 ;
}
int F_99 (
struct V_74 * V_75 ,
unsigned char * V_237 )
{
struct V_185 * V_238 = V_75 -> V_78 -> V_149 ;
T_1 V_239 = 0 ;
T_3 V_240 = 0 ;
unsigned long V_55 ;
int V_30 ;
if ( F_100 ( V_237 ) > V_241 ) {
F_4 ( L_104
L_105 ,
F_100 ( V_237 ) , V_241 ) ;
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_227 ;
return - V_163 ;
}
if ( F_100 ( V_237 ) > sizeof( V_75 -> V_242 ) ) {
V_75 -> V_221 = F_84 ( F_100 ( V_237 ) ,
V_33 ) ;
if ( ! V_75 -> V_221 ) {
F_4 ( L_106
L_107 ,
F_100 ( V_237 ) ,
( unsigned long ) sizeof( V_75 -> V_242 ) ) ;
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 =
V_122 ;
return - V_25 ;
}
} else
V_75 -> V_221 = & V_75 -> V_242 [ 0 ] ;
memcpy ( V_75 -> V_221 , V_237 , F_100 ( V_237 ) ) ;
if ( F_101 ( V_75 , V_237 ) < 0 ) {
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_243 ;
return - V_163 ;
}
V_30 = V_238 -> V_244 . V_245 ( V_75 , V_237 , & V_240 ) ;
if ( V_30 != 0 ) {
if ( V_30 > 0 ) {
F_27 ( L_108
L_109
L_110 ,
V_75 -> V_66 -> V_54 () , V_240 ) ;
F_102 ( V_75 , 0x04 , V_240 ) ;
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_246 ;
return - V_163 ;
}
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_227 ;
return - V_163 ;
}
if ( V_238 -> V_247 . V_248 . V_249 ( V_75 , & V_239 ) ) {
if ( V_238 -> V_247 . V_248 . V_250 (
V_75 , V_237 , V_239 ) != 0 ) {
V_75 -> V_99 |= V_226 ;
V_75 -> V_99 |= V_251 ;
V_75 -> V_110 = V_252 ;
V_75 -> V_121 = V_253 ;
return - V_254 ;
}
}
V_30 = V_75 -> V_78 -> V_108 -> V_255 ( V_75 ) ;
if ( V_30 < 0 )
return V_30 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_99 |= V_256 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( F_96 ( V_75 ) < 0 ) {
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_227 ;
return - V_163 ;
}
F_11 ( & V_75 -> V_91 -> V_257 ) ;
if ( V_75 -> V_91 -> V_258 )
V_75 -> V_91 -> V_258 -> V_259 . V_260 ++ ;
F_12 ( & V_75 -> V_91 -> V_257 ) ;
return 0 ;
}
int F_103 (
struct V_74 * V_75 )
{
int V_30 ;
if ( ! V_75 -> V_91 ) {
F_104 () ;
F_4 ( L_111 ) ;
return - V_163 ;
}
if ( F_105 () ) {
F_104 () ;
F_4 ( L_112
L_113 ) ;
return - V_163 ;
}
V_75 -> V_124 = V_261 ;
V_75 -> V_79 |= V_89 ;
V_30 = F_106 ( V_75 ) ;
if ( V_30 < 0 )
F_55 ( V_75 ) ;
return 0 ;
}
int F_107 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_237 , unsigned char * V_262 , T_1 V_263 ,
T_1 V_220 , int V_229 , int V_264 , int V_55 ,
struct V_265 * V_266 , T_1 V_267 ,
struct V_265 * V_268 , T_1 V_269 )
{
struct V_39 * V_40 ;
int V_270 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_10 ( V_74 -> V_66 || V_74 -> V_32 ) ;
F_10 ( F_105 () ) ;
F_94 ( V_74 , V_40 -> V_46 , V_32 ,
V_220 , V_264 , V_229 , V_262 ) ;
if ( V_55 & V_271 )
V_74 -> V_219 = 1 ;
V_270 = F_108 ( V_32 , V_74 , ( V_55 & V_272 ) ) ;
if ( V_270 )
return V_270 ;
if ( V_55 & V_273 )
V_74 -> V_99 |= V_274 ;
if ( F_109 ( V_74 , V_263 ) < 0 ) {
F_110 ( V_74 ,
V_74 -> V_121 , 0 ) ;
F_111 ( V_32 , V_74 ) ;
return 0 ;
}
V_270 = F_99 ( V_74 , V_237 ) ;
if ( V_270 != 0 ) {
F_55 ( V_74 ) ;
return 0 ;
}
if ( V_267 != 0 ) {
F_10 ( ! V_266 ) ;
if ( ! ( V_74 -> V_99 & V_275 ) &&
V_74 -> V_135 == V_137 ) {
unsigned char * V_44 = NULL ;
if ( V_266 )
V_44 = F_112 ( F_113 ( V_266 ) ) + V_266 -> V_276 ;
if ( V_44 ) {
memset ( V_44 , 0 , V_266 -> V_277 ) ;
F_114 ( F_113 ( V_266 ) ) ;
}
}
V_270 = F_115 ( V_74 , V_266 , V_267 ,
V_268 , V_269 ) ;
if ( V_270 != 0 ) {
F_55 ( V_74 ) ;
return 0 ;
}
}
F_116 ( V_74 ) ;
F_103 ( V_74 ) ;
return 0 ;
}
int F_117 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_237 , unsigned char * V_262 , T_1 V_263 ,
T_1 V_220 , int V_229 , int V_264 , int V_55 )
{
return F_107 ( V_74 , V_32 , V_237 , V_262 ,
V_263 , V_220 , V_229 , V_264 ,
V_55 , NULL , 0 , NULL , 0 ) ;
}
static void F_118 ( struct V_101 * V_102 )
{
struct V_74 * V_74 = F_32 ( V_102 , struct V_74 , V_102 ) ;
V_74 -> V_278 -> V_279 = V_280 ;
V_74 -> V_66 -> V_281 ( V_74 ) ;
}
int F_119 ( struct V_74 * V_74 , struct V_2 * V_32 ,
unsigned char * V_262 , T_1 V_263 ,
void * V_282 , unsigned char V_283 ,
T_4 V_284 , unsigned int V_285 , int V_55 )
{
struct V_39 * V_40 ;
int V_30 ;
V_40 = V_32 -> V_40 ;
F_10 ( ! V_40 ) ;
F_94 ( V_74 , V_40 -> V_46 , V_32 ,
0 , V_136 , V_286 , V_262 ) ;
V_30 = F_120 ( V_74 , V_282 , V_283 , V_284 ) ;
if ( V_30 < 0 )
return - V_25 ;
if ( V_283 == V_287 )
V_74 -> V_278 -> V_288 = V_285 ;
V_30 = F_108 ( V_32 , V_74 , ( V_55 & V_272 ) ) ;
if ( V_30 ) {
F_121 ( V_74 -> V_278 ) ;
return V_30 ;
}
V_30 = F_122 ( V_74 , V_263 ) ;
if ( V_30 ) {
F_59 ( & V_74 -> V_102 , F_118 ) ;
F_123 ( & V_74 -> V_102 ) ;
return 0 ;
}
F_124 ( V_74 ) ;
return 0 ;
}
bool F_125 ( struct V_74 * V_75 , unsigned long * V_55 )
{
bool V_289 = false ;
if ( V_75 -> V_79 & V_80 ) {
V_75 -> V_79 |= V_117 ;
F_30 ( & V_75 -> V_85 , * V_55 ) ;
F_27 ( L_114 , V_75 ) ;
F_126 ( & V_75 -> V_118 ) ;
F_27 ( L_115 , V_75 ) ;
F_29 ( & V_75 -> V_85 , * V_55 ) ;
V_75 -> V_79 &= ~ V_117 ;
V_75 -> V_79 &= ~ V_80 ;
V_289 = true ;
}
return V_289 ;
}
void F_55 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
F_27 ( L_116
L_117 , V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_221 [ 0 ] ) ;
F_27 ( L_118 ,
V_75 -> V_66 -> V_290 ( V_75 ) ,
V_75 -> V_124 , V_75 -> V_121 ) ;
F_27 ( L_119 ,
( V_75 -> V_79 & V_89 ) != 0 ,
( V_75 -> V_79 & V_92 ) != 0 ,
( V_75 -> V_79 & V_291 ) != 0 ) ;
if ( V_75 -> V_78 -> V_172 == V_174 )
F_127 ( V_75 ) ;
switch ( V_75 -> V_121 ) {
case V_292 :
case V_293 :
case V_227 :
case V_294 :
case V_122 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_243 :
case V_246 :
break;
case V_253 :
V_75 -> V_110 = V_252 ;
if ( V_75 -> V_32 &&
V_75 -> V_78 -> V_149 -> V_150 . V_299 == 2 )
F_128 ( V_75 -> V_32 -> V_41 ,
V_75 -> V_300 , 0x2C ,
V_301 ) ;
V_30 = V_75 -> V_66 -> V_302 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
goto V_305;
default:
F_4 ( L_120 ,
V_75 -> V_221 [ 0 ] , V_75 -> V_121 ) ;
V_75 -> V_121 = V_293 ;
break;
}
V_30 = F_110 ( V_75 ,
V_75 -> V_121 , 0 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
V_305:
F_50 ( V_75 ) ;
if ( ! F_49 ( V_75 ) )
;
return;
V_304:
V_75 -> V_124 = V_133 ;
F_129 ( V_75 , V_75 -> V_78 ) ;
}
static void F_130 ( struct V_74 * V_75 )
{
int error = 0 ;
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 |= ( V_80 | V_291 ) ;
F_26 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_306 )
error = V_75 -> V_306 ( V_75 ) ;
if ( error ) {
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_79 &= ~ ( V_80 | V_291 ) ;
F_26 ( & V_75 -> V_85 ) ;
F_55 ( V_75 ) ;
}
}
void F_131 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( F_132 ( V_75 , 1 ) ) {
F_37 ( & V_75 -> V_93 ) ;
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
V_75 -> V_124 = V_307 ;
F_26 ( & V_75 -> V_85 ) ;
if ( V_77 -> V_172 != V_174 )
goto V_308;
switch ( V_75 -> V_234 ) {
case V_309 :
F_27 ( L_121
L_122 ,
V_75 -> V_221 [ 0 ] , V_75 -> V_236 ) ;
goto V_308;
case V_310 :
F_133 ( & V_77 -> V_311 ) ;
F_98 () ;
F_27 ( L_123
L_124 ,
V_75 -> V_221 [ 0 ] , V_75 -> V_236 ) ;
if ( ! F_134 ( & V_77 -> V_312 ) )
goto V_308;
break;
default:
F_133 ( & V_77 -> V_312 ) ;
F_98 () ;
break;
}
if ( F_134 ( & V_77 -> V_311 ) != 0 ) {
F_11 ( & V_77 -> V_199 ) ;
F_25 ( & V_75 -> V_230 , & V_77 -> V_198 ) ;
F_12 ( & V_77 -> V_199 ) ;
F_27 ( L_125
L_126 ,
V_75 -> V_221 [ 0 ] , V_75 -> V_234 ,
V_75 -> V_236 ) ;
return;
}
V_308:
F_130 ( V_75 ) ;
}
static void F_135 ( struct V_76 * V_77 )
{
for (; ; ) {
struct V_74 * V_75 ;
F_11 ( & V_77 -> V_199 ) ;
if ( F_41 ( & V_77 -> V_198 ) ) {
F_12 ( & V_77 -> V_199 ) ;
break;
}
V_75 = F_136 ( V_77 -> V_198 . V_313 ,
struct V_74 , V_230 ) ;
F_40 ( & V_75 -> V_230 ) ;
F_12 ( & V_77 -> V_199 ) ;
F_130 ( V_75 ) ;
if ( V_75 -> V_234 == V_310 )
break;
}
}
static void F_127 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_78 ;
if ( V_75 -> V_234 == V_286 ) {
F_66 ( & V_77 -> V_312 ) ;
F_67 () ;
V_77 -> V_314 ++ ;
F_27 ( L_127
L_128 , V_77 -> V_314 ,
V_75 -> V_236 ) ;
} else if ( V_75 -> V_234 == V_309 ) {
V_77 -> V_314 ++ ;
F_27 ( L_129
L_130 , V_77 -> V_314 ,
V_75 -> V_236 ) ;
} else if ( V_75 -> V_234 == V_310 ) {
F_66 ( & V_77 -> V_311 ) ;
F_67 () ;
V_77 -> V_314 ++ ;
F_27 ( L_131
L_132 , V_77 -> V_314 , V_75 -> V_236 ) ;
}
F_135 ( V_77 ) ;
}
static void F_69 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
if ( V_75 -> V_78 -> V_172 == V_174 )
F_127 ( V_75 ) ;
if ( V_75 -> V_99 & V_116 ) {
V_30 = V_75 -> V_66 -> V_302 ( V_75 ) ;
if ( V_30 )
goto V_3;
}
switch ( V_75 -> V_135 ) {
case V_137 :
V_30 = V_75 -> V_66 -> V_315 ( V_75 ) ;
break;
case V_138 :
if ( V_75 -> V_316 ) {
V_30 = V_75 -> V_66 -> V_315 ( V_75 ) ;
if ( V_30 < 0 )
break;
}
case V_136 :
V_30 = V_75 -> V_66 -> V_302 ( V_75 ) ;
break;
default:
break;
}
V_3:
if ( V_30 < 0 ) {
F_129 ( V_75 , V_75 -> V_78 ) ;
return;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
}
static void F_129 (
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_24 ( & V_77 -> V_130 ) ;
F_25 ( & V_75 -> V_131 , & V_75 -> V_78 -> V_128 ) ;
F_133 ( & V_77 -> V_132 ) ;
F_98 () ;
F_26 ( & V_75 -> V_78 -> V_130 ) ;
F_123 ( & V_75 -> V_78 -> V_127 ) ;
}
static void V_123 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_32 ( V_102 , struct V_74 , V_102 ) ;
int V_30 ;
if ( V_75 -> V_78 -> V_172 == V_174 )
F_127 ( V_75 ) ;
if ( F_134 ( & V_75 -> V_78 -> V_132 ) != 0 )
F_123 ( & V_75 -> V_78 -> V_127 ) ;
if ( V_75 -> V_99 & V_116 ) {
F_57 ( ! V_75 -> V_110 ) ;
V_30 = F_110 (
V_75 , 0 , 1 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
}
if ( V_75 -> V_317 )
V_75 -> V_317 ( V_75 ) ;
switch ( V_75 -> V_135 ) {
case V_137 :
F_11 ( & V_75 -> V_91 -> V_257 ) ;
if ( V_75 -> V_91 -> V_258 ) {
V_75 -> V_91 -> V_258 -> V_259 . V_318 +=
V_75 -> V_220 ;
}
F_12 ( & V_75 -> V_91 -> V_257 ) ;
V_30 = V_75 -> V_66 -> V_315 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
break;
case V_138 :
F_11 ( & V_75 -> V_91 -> V_257 ) ;
if ( V_75 -> V_91 -> V_258 ) {
V_75 -> V_91 -> V_258 -> V_259 . V_319 +=
V_75 -> V_220 ;
}
F_12 ( & V_75 -> V_91 -> V_257 ) ;
if ( V_75 -> V_316 ) {
F_11 ( & V_75 -> V_91 -> V_257 ) ;
if ( V_75 -> V_91 -> V_258 ) {
V_75 -> V_91 -> V_258 -> V_259 . V_318 +=
V_75 -> V_220 ;
}
F_12 ( & V_75 -> V_91 -> V_257 ) ;
V_30 = V_75 -> V_66 -> V_315 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
break;
}
case V_136 :
V_30 = V_75 -> V_66 -> V_302 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
break;
default:
break;
}
F_50 ( V_75 ) ;
F_49 ( V_75 ) ;
return;
V_304:
F_27 ( L_133
L_134 , V_75 , V_75 -> V_135 ) ;
V_75 -> V_124 = V_133 ;
F_129 ( V_75 , V_75 -> V_78 ) ;
}
static inline void F_137 ( struct V_265 * V_266 , int V_320 )
{
struct V_265 * V_321 ;
int V_322 ;
F_138 (sgl, sg, nents, count)
F_139 ( F_113 ( V_321 ) ) ;
F_91 ( V_266 ) ;
}
static inline void F_140 ( struct V_74 * V_75 )
{
if ( V_75 -> V_99 & V_323 )
return;
F_137 ( V_75 -> V_115 , V_75 -> V_324 ) ;
V_75 -> V_115 = NULL ;
V_75 -> V_324 = 0 ;
F_137 ( V_75 -> V_316 , V_75 -> V_325 ) ;
V_75 -> V_316 = NULL ;
V_75 -> V_325 = 0 ;
}
static void F_141 ( struct V_74 * V_75 )
{
F_10 ( ! V_75 -> V_66 ) ;
if ( V_75 -> V_99 & V_100 )
F_121 ( V_75 -> V_278 ) ;
if ( V_75 -> V_221 != V_75 -> V_242 )
F_91 ( V_75 -> V_221 ) ;
if ( V_75 -> V_326 != 0 ) {
F_111 ( V_75 -> V_32 , V_75 ) ;
return;
}
V_75 -> V_66 -> V_327 ( V_75 ) ;
}
static void F_53 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( F_134 ( & V_75 -> V_328 ) ) {
if ( ! F_142 ( & V_75 -> V_328 ) )
goto V_329;
}
if ( V_75 -> V_79 & V_96 ) {
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_140 ( V_75 ) ;
F_141 ( V_75 ) ;
return;
V_329:
F_30 ( & V_75 -> V_85 , V_55 ) ;
}
int F_115 (
struct V_74 * V_75 ,
struct V_265 * V_266 ,
T_1 V_267 ,
struct V_265 * V_268 ,
T_1 V_269 )
{
if ( ! V_266 || ! V_267 )
return 0 ;
if ( V_75 -> V_99 & V_223 ) {
F_93 ( L_135
L_136 ) ;
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_227 ;
return - V_163 ;
}
V_75 -> V_115 = V_266 ;
V_75 -> V_324 = V_267 ;
if ( V_268 && V_269 ) {
V_75 -> V_316 = V_268 ;
V_75 -> V_325 = V_269 ;
}
V_75 -> V_99 |= V_323 ;
return 0 ;
}
void * F_143 ( struct V_74 * V_75 )
{
struct V_265 * V_321 = V_75 -> V_115 ;
struct V_330 * * V_331 ;
int V_169 ;
if ( ! V_75 -> V_324 )
return NULL ;
F_10 ( ! V_321 ) ;
if ( V_75 -> V_324 == 1 )
return F_112 ( F_113 ( V_321 ) ) + V_321 -> V_276 ;
V_331 = F_144 ( sizeof( * V_331 ) * V_75 -> V_324 , V_33 ) ;
if ( ! V_331 ) {
V_75 -> V_121 = V_122 ;
return NULL ;
}
F_138 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_331 [ V_169 ] = F_113 ( V_321 ) ;
}
V_75 -> V_332 = F_145 ( V_331 , V_75 -> V_324 , V_333 , V_334 ) ;
F_91 ( V_331 ) ;
if ( ! V_75 -> V_332 ) {
V_75 -> V_121 = V_122 ;
return NULL ;
}
return V_75 -> V_332 + V_75 -> V_115 [ 0 ] . V_276 ;
}
void F_146 ( struct V_74 * V_75 )
{
if ( ! V_75 -> V_324 ) {
return;
} else if ( V_75 -> V_324 == 1 ) {
F_114 ( F_113 ( V_75 -> V_115 ) ) ;
return;
}
F_147 ( V_75 -> V_332 ) ;
V_75 -> V_332 = NULL ;
}
static int
F_148 ( struct V_74 * V_75 )
{
T_1 V_277 = V_75 -> V_220 ;
unsigned int V_320 ;
struct V_330 * V_330 ;
T_4 V_335 ;
int V_169 = 0 ;
V_320 = F_149 ( V_277 , V_336 ) ;
V_75 -> V_115 = F_144 ( sizeof( struct V_265 ) * V_320 , V_33 ) ;
if ( ! V_75 -> V_115 )
return - V_25 ;
V_75 -> V_324 = V_320 ;
F_150 ( V_75 -> V_115 , V_320 ) ;
V_335 = V_75 -> V_99 & V_275 ? 0 : V_337 ;
while ( V_277 ) {
T_1 V_338 = F_151 ( T_1 , V_277 , V_336 ) ;
V_330 = F_152 ( V_33 | V_335 ) ;
if ( ! V_330 )
goto V_3;
F_153 ( & V_75 -> V_115 [ V_169 ] , V_330 , V_338 , 0 ) ;
V_277 -= V_338 ;
V_169 ++ ;
}
return 0 ;
V_3:
while ( V_169 > 0 ) {
V_169 -- ;
F_139 ( F_113 ( & V_75 -> V_115 [ V_169 ] ) ) ;
}
F_91 ( V_75 -> V_115 ) ;
V_75 -> V_115 = NULL ;
return - V_25 ;
}
int F_106 ( struct V_74 * V_75 )
{
int V_30 = 0 ;
if ( ! ( V_75 -> V_99 & V_323 ) &&
V_75 -> V_220 ) {
V_30 = F_148 ( V_75 ) ;
if ( V_30 < 0 )
goto V_339;
}
F_133 ( & V_75 -> V_328 ) ;
F_61 ( V_75 ) ;
if ( V_75 -> V_135 != V_138 ) {
F_131 ( V_75 ) ;
return 0 ;
}
F_24 ( & V_75 -> V_85 ) ;
V_75 -> V_124 = V_340 ;
F_26 ( & V_75 -> V_85 ) ;
F_48 ( V_75 , false ) ;
V_30 = V_75 -> V_66 -> V_341 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 )
goto V_304;
if ( V_30 < 0 )
return V_30 ;
return 1 ;
V_339:
V_75 -> V_99 |= V_226 ;
V_75 -> V_121 = V_122 ;
return - V_163 ;
V_304:
F_27 ( L_137 , V_75 ) ;
V_75 -> V_124 = V_134 ;
F_129 ( V_75 , V_75 -> V_78 ) ;
return 0 ;
}
static void F_68 ( struct V_74 * V_75 )
{
int V_30 ;
V_30 = V_75 -> V_66 -> V_341 ( V_75 ) ;
if ( V_30 == - V_303 || V_30 == - V_25 ) {
F_27 ( L_137 ,
V_75 ) ;
F_129 ( V_75 , V_75 -> V_78 ) ;
}
}
void F_154 ( struct V_74 * V_75 , int V_342 )
{
if ( ! ( V_75 -> V_99 & V_343 ) ) {
if ( V_342 && ( V_75 -> V_99 & V_100 ) )
F_155 ( V_75 ) ;
F_141 ( V_75 ) ;
} else {
if ( V_342 )
F_155 ( V_75 ) ;
F_156 ( V_75 -> V_32 -> V_41 , V_75 ) ;
if ( V_75 -> V_91 )
F_50 ( V_75 ) ;
F_53 ( V_75 ) ;
}
}
static int F_108 ( struct V_2 * V_32 , struct V_74 * V_74 ,
bool V_344 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_20 ( & V_74 -> V_345 ) ;
if ( V_344 == true ) {
F_23 ( & V_74 -> V_345 ) ;
V_74 -> V_99 |= V_346 ;
}
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( V_32 -> V_347 ) {
V_30 = - V_348 ;
goto V_3;
}
F_25 ( & V_74 -> V_231 , & V_32 -> V_36 ) ;
V_74 -> V_326 = 1 ;
V_3:
F_30 ( & V_32 -> V_37 , V_55 ) ;
return V_30 ;
}
static void F_157 ( struct V_57 * V_57 )
{
struct V_74 * V_74 = F_32 ( V_57 , struct V_74 , V_345 ) ;
struct V_2 * V_32 = V_74 -> V_32 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
if ( F_41 ( & V_74 -> V_231 ) ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_327 ( V_74 ) ;
return;
}
if ( V_32 -> V_347 && V_74 -> V_349 ) {
F_30 ( & V_32 -> V_37 , V_55 ) ;
F_37 ( & V_74 -> V_233 ) ;
return;
}
F_40 ( & V_74 -> V_231 ) ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
V_74 -> V_66 -> V_327 ( V_74 ) ;
}
int F_111 ( struct V_2 * V_32 , struct V_74 * V_74 )
{
return F_35 ( & V_74 -> V_345 , F_157 ) ;
}
void F_158 ( struct V_2 * V_32 )
{
struct V_74 * V_74 ;
unsigned long V_55 ;
F_29 ( & V_32 -> V_37 , V_55 ) ;
F_57 ( V_32 -> V_347 ) ;
V_32 -> V_347 = 1 ;
F_159 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list)
V_74 -> V_349 = 1 ;
F_30 ( & V_32 -> V_37 , V_55 ) ;
}
void F_160 (
struct V_2 * V_32 ,
int V_342 )
{
struct V_74 * V_74 , * V_350 ;
bool V_270 = false ;
F_65 (se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
F_40 ( & V_74 -> V_231 ) ;
F_27 ( L_138
L_139 , V_74 , V_74 -> V_124 ,
V_74 -> V_66 -> V_290 ( V_74 ) ) ;
if ( V_342 ) {
F_27 ( L_140
L_141 , V_74 , V_74 -> V_124 ,
V_74 -> V_66 -> V_290 ( V_74 ) ) ;
V_270 = F_155 ( V_74 ) ;
F_27 ( L_142
L_141 , V_74 , V_74 -> V_124 ,
V_74 -> V_66 -> V_290 ( V_74 ) ) ;
}
if ( ! V_270 ) {
F_126 ( & V_74 -> V_233 ) ;
F_27 ( L_143
L_141 , V_74 , V_74 -> V_124 ,
V_74 -> V_66 -> V_290 ( V_74 ) ) ;
}
V_74 -> V_66 -> V_327 ( V_74 ) ;
}
}
static int F_161 ( struct V_74 * V_75 , struct V_91 * V_95 )
{
unsigned long V_55 ;
int V_30 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_79 & V_92 ) {
V_75 -> V_79 &= ~ V_86 ;
F_27 ( L_144 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_48 ( V_75 , false ) ;
return - V_351 ;
}
V_75 -> V_79 |= V_352 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ( V_75 -> V_79 & V_80 ) &&
( V_75 -> V_79 & V_291 ) ) {
if ( ! F_125 ( V_75 , & V_55 ) )
V_30 ++ ;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_27 ( L_145
L_139 , V_75 , V_30 ) ;
if ( ! V_30 ) {
F_27 ( L_146 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_126 ( & V_75 -> V_90 ) ;
F_27 ( L_147 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
}
return 0 ;
}
static void F_162 ( struct V_91 * V_95 )
{
struct V_74 * V_75 = NULL ;
unsigned long V_353 , V_354 ;
F_29 ( & V_95 -> V_97 , V_353 ) ;
while ( ! F_41 ( & V_95 -> V_355 ) ) {
V_75 = F_163 ( & V_95 -> V_355 ,
struct V_74 , V_98 ) ;
F_51 ( & V_75 -> V_98 ) ;
F_11 ( & V_75 -> V_85 ) ;
F_27 ( L_148
L_149 ,
V_75 -> V_91 -> V_263 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 |= V_86 ;
F_12 ( & V_75 -> V_85 ) ;
F_30 ( & V_95 -> V_97 , V_353 ) ;
if ( ! V_75 -> V_91 ) {
F_4 ( L_150 ,
V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_290 ( V_75 ) , V_75 -> V_124 ) ;
F_164 () ;
}
F_27 ( L_151
L_152 , V_75 -> V_91 -> V_263 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
if ( F_161 ( V_75 , V_75 -> V_91 ) < 0 ) {
F_29 ( & V_95 -> V_97 , V_353 ) ;
continue;
}
F_27 ( L_153
L_154 ,
V_75 -> V_91 -> V_263 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_29 ( & V_75 -> V_85 , V_354 ) ;
if ( ! ( V_75 -> V_79 & V_96 ) ) {
F_30 ( & V_75 -> V_85 , V_354 ) ;
goto V_356;
}
V_75 -> V_79 &= ~ V_96 ;
F_47 ( V_75 ) ;
F_30 ( & V_75 -> V_85 , V_354 ) ;
V_356:
F_110 ( V_75 ,
V_292 , 0 ) ;
F_29 ( & V_75 -> V_85 , V_354 ) ;
if ( V_75 -> V_79 & V_352 ) {
F_27 ( L_155
L_156 ,
V_95 -> V_263 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 ,
V_354 ) ;
F_48 ( V_75 , false ) ;
F_37 ( & V_75 -> V_232 ) ;
F_29 ( & V_95 -> V_97 , V_353 ) ;
continue;
}
F_27 ( L_157 ,
V_95 -> V_263 , V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_354 ) ;
F_29 ( & V_95 -> V_97 , V_353 ) ;
}
F_30 ( & V_95 -> V_97 , V_353 ) ;
}
static int F_165 ( void * V_357 )
{
struct V_91 * V_95 = V_357 ;
F_162 ( V_95 ) ;
F_37 ( & V_95 -> V_358 ) ;
return 0 ;
}
int F_166 ( struct V_91 * V_95 )
{
struct V_359 * V_360 ;
V_360 = F_167 ( F_165 , V_95 ,
L_158 , V_95 -> V_263 ) ;
if ( F_168 ( V_360 ) ) {
F_4 ( L_159 ) ;
return F_169 ( V_360 ) ;
}
F_126 ( & V_95 -> V_358 ) ;
return 0 ;
}
bool F_155 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( ! ( V_75 -> V_99 & V_343 ) &&
! ( V_75 -> V_99 & V_100 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( ! ( V_75 -> V_99 & V_256 ) &&
! ( V_75 -> V_99 & V_100 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
if ( V_75 -> V_79 & V_86 ) {
F_27 ( L_160
L_161
L_162 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_37 ( & V_75 -> V_90 ) ;
F_126 ( & V_75 -> V_232 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
F_47 ( V_75 ) ;
F_27 ( L_163
L_164
L_165 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_79 &= ~ V_86 ;
}
if ( ! ( V_75 -> V_79 & V_89 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return false ;
}
V_75 -> V_79 |= V_92 ;
F_27 ( L_166
L_167 ,
V_75 , V_75 -> V_66 -> V_88 ( V_75 ) ,
V_75 -> V_66 -> V_290 ( V_75 ) , V_75 -> V_124 ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
F_126 ( & V_75 -> V_93 ) ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
V_75 -> V_79 &= ~ ( V_89 | V_92 ) ;
F_27 ( L_168
L_169 ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
return true ;
}
static int F_170 (
struct V_74 * V_75 ,
T_3 * V_361 ,
T_3 * V_362 )
{
* V_361 = V_75 -> V_363 ;
* V_362 = V_75 -> V_364 ;
return 0 ;
}
static int F_102 (
struct V_74 * V_75 ,
T_3 V_361 ,
T_3 V_362 )
{
V_75 -> V_363 = V_361 ;
V_75 -> V_364 = V_362 ;
return 0 ;
}
int F_110 (
struct V_74 * V_75 ,
T_3 V_365 ,
int V_366 )
{
unsigned char * V_367 = V_75 -> V_111 ;
unsigned long V_55 ;
T_3 V_361 = 0 , V_362 = 0 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_99 & V_103 ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return 0 ;
}
V_75 -> V_99 |= V_103 ;
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( ! V_365 && V_366 )
goto V_368;
if ( ! V_366 )
V_75 -> V_99 |= V_369 ;
switch ( V_365 ) {
case V_292 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x25 ;
break;
case V_293 :
case V_374 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x20 ;
break;
case V_295 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x24 ;
break;
case V_298 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_375 ;
V_367 [ V_373 ] = 0x29 ;
V_367 [ V_376 ] = 0x03 ;
break;
case V_377 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_375 ;
V_367 [ V_373 ] = 0x0c ;
V_367 [ V_376 ] = 0x0d ;
break;
case V_227 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x24 ;
break;
case V_294 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x26 ;
break;
case V_378 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_375 ;
V_367 [ V_373 ] = 0x0c ;
V_367 [ V_376 ] = 0x0c ;
break;
case V_379 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_375 ;
V_367 [ V_373 ] = 0x47 ;
V_367 [ V_376 ] = 0x05 ;
break;
case V_380 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_375 ;
V_367 [ V_373 ] = 0x11 ;
V_367 [ V_376 ] = 0x13 ;
break;
case V_296 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_381 ;
V_367 [ V_373 ] = 0x27 ;
break;
case V_297 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x21 ;
break;
case V_243 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_382 ;
F_171 ( V_75 , & V_361 , & V_362 ) ;
V_367 [ V_373 ] = V_361 ;
V_367 [ V_376 ] = V_362 ;
break;
case V_246 :
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_383 ;
F_170 ( V_75 , & V_361 , & V_362 ) ;
V_367 [ V_373 ] = V_361 ;
V_367 [ V_376 ] = V_362 ;
break;
case V_122 :
default:
V_367 [ 0 ] = 0x70 ;
V_367 [ V_370 ] = 10 ;
V_367 [ V_371 ] = V_372 ;
V_367 [ V_373 ] = 0x80 ;
break;
}
V_75 -> V_110 = V_384 ;
V_75 -> V_104 = V_105 ;
V_368:
return V_75 -> V_66 -> V_302 ( V_75 ) ;
}
int F_132 ( struct V_74 * V_75 , int V_385 )
{
int V_30 = 0 ;
if ( V_75 -> V_79 & V_120 ) {
if ( ! V_385 ||
( V_75 -> V_99 & V_386 ) )
return 1 ;
F_27 ( L_170
L_171 ,
V_75 -> V_221 [ 0 ] ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_99 |= V_386 ;
V_75 -> V_66 -> V_302 ( V_75 ) ;
V_30 = 1 ;
}
return V_30 ;
}
void F_172 ( struct V_74 * V_75 )
{
unsigned long V_55 ;
F_29 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_99 & ( V_103 | V_386 ) ) {
F_30 ( & V_75 -> V_85 , V_55 ) ;
return;
}
F_30 ( & V_75 -> V_85 , V_55 ) ;
if ( V_75 -> V_135 == V_138 ) {
if ( V_75 -> V_66 -> V_387 ( V_75 ) != 0 ) {
V_75 -> V_79 |= V_120 ;
F_98 () ;
}
}
V_75 -> V_110 = V_388 ;
F_27 ( L_172
L_173 , V_75 -> V_221 [ 0 ] ,
V_75 -> V_66 -> V_88 ( V_75 ) ) ;
V_75 -> V_66 -> V_302 ( V_75 ) ;
}
static void F_173 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_32 ( V_102 , struct V_74 , V_102 ) ;
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_278 * V_389 = V_75 -> V_278 ;
int V_30 ;
switch ( V_389 -> V_390 ) {
case V_287 :
F_174 ( V_77 , V_389 , V_75 -> V_32 ) ;
break;
case V_391 :
case V_392 :
case V_393 :
V_389 -> V_279 = V_394 ;
break;
case V_395 :
V_30 = F_175 ( V_77 , V_389 , NULL , NULL ) ;
V_389 -> V_279 = ( ! V_30 ) ? V_396 :
V_397 ;
break;
case V_398 :
V_389 -> V_279 = V_397 ;
break;
case V_399 :
V_389 -> V_279 = V_397 ;
break;
default:
F_4 ( L_174 ,
V_389 -> V_390 ) ;
V_389 -> V_279 = V_397 ;
break;
}
V_75 -> V_124 = V_400 ;
V_75 -> V_66 -> V_281 ( V_75 ) ;
F_49 ( V_75 ) ;
}
int F_124 (
struct V_74 * V_75 )
{
F_59 ( & V_75 -> V_102 , F_173 ) ;
F_60 ( V_75 -> V_78 -> V_215 , & V_75 -> V_102 ) ;
return 0 ;
}
