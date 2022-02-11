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
F_3 ( struct V_20 ) , 0 , NULL ) ;
if ( ! V_19 ) {
F_4 ( L_16
L_12 ) ;
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
V_25 = F_5 ( L_19 ,
V_26 , 0 ) ;
if ( ! V_25 )
goto V_27;
return 0 ;
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
return - V_28 ;
}
void F_7 ( void )
{
F_8 ( V_25 ) ;
F_6 ( V_1 ) ;
F_6 ( V_4 ) ;
F_6 ( V_7 ) ;
F_6 ( V_10 ) ;
F_6 ( V_13 ) ;
F_6 ( V_16 ) ;
F_6 ( V_19 ) ;
F_6 ( V_22 ) ;
}
T_1 F_9 ( T_2 type )
{
T_1 V_29 ;
F_10 ( ( type < 0 ) || ( type >= V_30 ) ) ;
F_11 ( & V_31 ) ;
V_29 = ++ V_32 [ type ] ;
F_12 ( & V_31 ) ;
return V_29 ;
}
void F_13 ( void )
{
int V_33 ;
static int V_34 ;
if ( V_34 )
return;
V_33 = F_14 ( L_20 ) ;
if ( V_33 != 0 )
F_4 ( L_21 ) ;
V_33 = F_14 ( L_22 ) ;
if ( V_33 != 0 )
F_4 ( L_23 ) ;
V_33 = F_14 ( L_24 ) ;
if ( V_33 != 0 )
F_4 ( L_25 ) ;
V_33 = F_14 ( L_26 ) ;
if ( V_33 != 0 )
F_4 ( L_27 ) ;
V_34 = 1 ;
}
struct V_2 * F_15 ( enum V_35 V_36 )
{
struct V_2 * V_37 ;
V_37 = F_16 ( V_1 , V_38 ) ;
if ( ! V_37 ) {
F_4 ( L_28
L_29 ) ;
return F_17 ( - V_28 ) ;
}
F_18 ( & V_37 -> V_39 ) ;
F_18 ( & V_37 -> V_40 ) ;
F_18 ( & V_37 -> V_41 ) ;
F_18 ( & V_37 -> V_42 ) ;
F_19 ( & V_37 -> V_43 ) ;
F_20 ( & V_37 -> V_44 ) ;
V_37 -> V_36 = V_36 ;
return V_37 ;
}
int F_21 ( struct V_2 * V_37 ,
unsigned int V_45 , unsigned int V_46 )
{
int V_47 ;
V_37 -> V_48 = F_22 ( V_45 * V_46 ,
V_38 | V_49 | V_50 ) ;
if ( ! V_37 -> V_48 ) {
V_37 -> V_48 = F_23 ( V_45 * V_46 ) ;
if ( ! V_37 -> V_48 ) {
F_4 ( L_30 ) ;
return - V_28 ;
}
}
V_47 = F_24 ( & V_37 -> V_51 , V_45 ) ;
if ( V_47 < 0 ) {
F_4 ( L_31
L_32 , V_45 ) ;
F_25 ( V_37 -> V_48 ) ;
V_37 -> V_48 = NULL ;
return - V_28 ;
}
return 0 ;
}
struct V_2 * F_26 ( unsigned int V_45 ,
unsigned int V_46 ,
enum V_35 V_36 )
{
struct V_2 * V_37 ;
int V_47 ;
V_37 = F_15 ( V_36 ) ;
if ( F_27 ( V_37 ) )
return V_37 ;
V_47 = F_21 ( V_37 , V_45 , V_46 ) ;
if ( V_47 < 0 ) {
F_28 ( V_37 ) ;
return F_17 ( - V_28 ) ;
}
return V_37 ;
}
void F_29 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_2 * V_37 ,
void * V_56 )
{
const struct V_57 * V_58 = V_53 -> V_59 ;
unsigned char V_60 [ V_61 ] ;
V_37 -> V_53 = V_53 ;
V_37 -> V_56 = V_56 ;
if ( V_55 ) {
if ( V_55 -> V_62 )
V_37 -> V_63 = V_55 -> V_62 ;
else if ( V_58 -> V_64 )
V_37 -> V_63 = V_55 -> V_62 =
V_58 -> V_64 ( V_53 ) ;
if ( V_53 -> V_59 -> V_65 != NULL ) {
memset ( & V_60 [ 0 ] , 0 , V_61 ) ;
V_53 -> V_59 -> V_65 ( V_37 ,
& V_60 [ 0 ] , V_61 ) ;
V_37 -> V_66 = F_30 ( & V_60 [ 0 ] ) ;
}
F_31 ( & V_55 -> V_67 ) ;
V_55 -> V_68 = V_37 ;
F_32 ( & V_37 -> V_40 ,
& V_55 -> V_69 ) ;
F_33 ( & V_55 -> V_67 ) ;
}
F_32 ( & V_37 -> V_39 , & V_53 -> V_70 ) ;
F_34 ( L_33 ,
V_53 -> V_59 -> V_71 () , V_37 -> V_56 ) ;
}
void F_35 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_2 * V_37 ,
void * V_56 )
{
unsigned long V_72 ;
F_36 ( & V_53 -> V_73 , V_72 ) ;
F_29 ( V_53 , V_55 , V_37 , V_56 ) ;
F_37 ( & V_53 -> V_73 , V_72 ) ;
}
static void F_38 ( struct V_74 * V_74 )
{
struct V_2 * V_37 = F_39 ( V_74 ,
struct V_2 , V_44 ) ;
struct V_52 * V_53 = V_37 -> V_53 ;
V_53 -> V_59 -> V_75 ( V_37 ) ;
}
int F_40 ( struct V_2 * V_37 )
{
return F_41 ( & V_37 -> V_44 ) ;
}
void F_42 ( struct V_2 * V_37 )
{
F_43 ( & V_37 -> V_44 , F_38 ) ;
}
T_3 F_44 ( struct V_52 * V_53 , char * V_76 )
{
struct V_2 * V_37 ;
T_3 V_77 = 0 ;
F_45 ( & V_53 -> V_73 ) ;
F_46 (se_sess, &se_tpg->tpg_sess_list, sess_list) {
if ( ! V_37 -> V_54 )
continue;
if ( ! V_37 -> V_54 -> V_78 )
continue;
if ( strlen ( V_37 -> V_54 -> V_79 ) + 1 + V_77 > V_80 )
break;
V_77 += snprintf ( V_76 + V_77 , V_80 - V_77 , L_34 ,
V_37 -> V_54 -> V_79 ) ;
V_77 += 1 ;
}
F_47 ( & V_53 -> V_73 ) ;
return V_77 ;
}
static void F_48 ( struct V_74 * V_74 )
{
struct V_54 * V_81 = F_39 ( V_74 ,
struct V_54 , V_82 ) ;
F_49 ( & V_81 -> V_83 ) ;
}
void F_50 ( struct V_54 * V_81 )
{
F_43 ( & V_81 -> V_82 , F_48 ) ;
}
void F_51 ( struct V_2 * V_37 )
{
struct V_54 * V_55 ;
unsigned long V_72 ;
V_55 = V_37 -> V_54 ;
if ( V_55 ) {
F_36 ( & V_55 -> V_67 , V_72 ) ;
if ( V_55 -> V_84 == 0 )
F_52 ( & V_37 -> V_40 ) ;
if ( F_53 ( & V_55 -> V_69 ) )
V_55 -> V_68 = NULL ;
else {
V_55 -> V_68 = F_39 (
V_55 -> V_69 . V_85 ,
struct V_2 , V_40 ) ;
}
F_37 ( & V_55 -> V_67 , V_72 ) ;
}
}
void F_28 ( struct V_2 * V_37 )
{
struct V_54 * V_55 = V_37 -> V_54 ;
if ( V_55 ) {
V_37 -> V_54 = NULL ;
F_50 ( V_55 ) ;
}
if ( V_37 -> V_48 ) {
F_54 ( & V_37 -> V_51 ) ;
F_25 ( V_37 -> V_48 ) ;
}
F_55 ( V_1 , V_37 ) ;
}
void F_56 ( struct V_2 * V_37 )
{
struct V_52 * V_53 = V_37 -> V_53 ;
const struct V_57 * V_86 ;
struct V_54 * V_55 ;
unsigned long V_72 ;
bool V_87 = false ;
if ( ! V_53 ) {
F_28 ( V_37 ) ;
return;
}
V_86 = V_53 -> V_59 ;
F_36 ( & V_53 -> V_73 , V_72 ) ;
F_52 ( & V_37 -> V_39 ) ;
V_37 -> V_53 = NULL ;
V_37 -> V_56 = NULL ;
F_37 ( & V_53 -> V_73 , V_72 ) ;
V_55 = V_37 -> V_54 ;
F_57 ( & V_53 -> V_88 ) ;
if ( V_55 && V_55 -> V_78 ) {
if ( ! V_86 -> V_89 ( V_53 ) ) {
F_52 ( & V_55 -> V_90 ) ;
V_87 = true ;
}
}
F_58 ( & V_53 -> V_88 ) ;
if ( V_87 ) {
F_59 ( V_55 ) ;
F_60 ( V_55 , V_53 ) ;
V_37 -> V_54 = NULL ;
F_61 ( V_55 ) ;
}
F_34 ( L_35 ,
V_53 -> V_59 -> V_71 () ) ;
F_28 ( V_37 ) ;
}
static void F_62 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
unsigned long V_72 ;
if ( ! V_94 )
return;
if ( V_92 -> V_96 & V_97 )
return;
F_36 ( & V_94 -> V_98 , V_72 ) ;
if ( V_92 -> V_99 ) {
F_52 ( & V_92 -> V_100 ) ;
V_92 -> V_99 = false ;
}
F_37 ( & V_94 -> V_98 , V_72 ) ;
}
static int F_63 ( struct V_91 * V_92 , bool V_101 ,
bool V_102 )
{
unsigned long V_72 ;
if ( V_101 ) {
F_62 ( V_92 ) ;
V_92 -> V_103 = NULL ;
}
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_102 )
V_92 -> V_105 = V_106 ;
if ( V_92 -> V_96 & V_107 ) {
F_34 ( L_36 ,
V_108 , __LINE__ , V_92 -> V_109 ) ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
F_64 ( & V_92 -> V_110 ) ;
return 1 ;
}
V_92 -> V_96 &= ~ V_111 ;
if ( V_101 ) {
if ( V_92 -> V_86 -> V_112 != NULL ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
return V_92 -> V_86 -> V_112 ( V_92 ) ;
}
}
F_37 ( & V_92 -> V_104 , V_72 ) ;
return 0 ;
}
static int F_65 ( struct V_91 * V_92 )
{
return F_63 ( V_92 , true , false ) ;
}
static void F_66 ( struct V_91 * V_92 )
{
struct V_103 * V_113 = V_92 -> V_103 ;
if ( ! V_113 )
return;
if ( F_67 ( & V_92 -> V_114 , true , false ) )
F_68 ( & V_113 -> V_115 ) ;
}
void F_69 ( struct V_91 * V_92 , int remove )
{
bool V_116 = ( V_92 -> V_117 & V_118 ) ;
if ( V_92 -> V_117 & V_119 )
F_66 ( V_92 ) ;
if ( remove )
V_92 -> V_86 -> V_120 ( V_92 ) ;
if ( F_65 ( V_92 ) )
return;
if ( remove && V_116 )
F_70 ( V_92 ) ;
}
static void F_71 ( struct V_121 * V_122 )
{
struct V_91 * V_92 = F_39 ( V_122 , struct V_91 , V_122 ) ;
F_72 ( V_92 ,
V_123 ) ;
}
static unsigned char * F_73 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
F_74 ( ! V_92 -> V_103 ) ;
if ( ! V_94 )
return NULL ;
if ( V_92 -> V_117 & V_124 )
return NULL ;
V_92 -> V_125 = V_126 ;
F_34 ( L_37 ,
V_94 -> V_127 -> V_128 , V_94 -> V_129 -> V_130 , V_92 -> V_131 ) ;
return V_92 -> V_132 ;
}
void F_75 ( struct V_91 * V_92 , T_4 V_131 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
int V_133 = V_131 == V_134 ;
unsigned long V_72 ;
V_92 -> V_131 = V_131 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
V_92 -> V_96 &= ~ V_97 ;
if ( V_94 && V_94 -> V_129 -> V_135 ) {
V_94 -> V_129 -> V_135 ( V_92 ,
V_92 -> V_136 ,
F_73 ( V_92 ) ) ;
if ( V_92 -> V_117 & V_137 )
V_133 = 1 ;
}
if ( V_92 -> V_96 & V_138 ||
V_92 -> V_96 & V_107 ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
F_64 ( & V_92 -> V_110 ) ;
return;
} else if ( ! V_133 ) {
F_76 ( & V_92 -> V_122 , F_71 ) ;
} else {
F_76 ( & V_92 -> V_122 , V_139 ) ;
}
V_92 -> V_105 = V_140 ;
V_92 -> V_96 |= ( V_141 | V_111 ) ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_117 & V_142 )
F_77 ( V_92 -> V_143 , V_25 , & V_92 -> V_122 ) ;
else
F_78 ( V_25 , & V_92 -> V_122 ) ;
}
void F_79 ( struct V_91 * V_92 , T_4 V_131 , int V_144 )
{
if ( V_131 == V_145 && V_144 < V_92 -> V_146 ) {
if ( V_92 -> V_117 & V_147 ) {
V_92 -> V_148 += V_92 -> V_146 - V_144 ;
} else {
V_92 -> V_117 |= V_147 ;
V_92 -> V_148 = V_92 -> V_146 - V_144 ;
}
V_92 -> V_146 = V_144 ;
}
F_75 ( V_92 , V_131 ) ;
}
static void F_80 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
unsigned long V_72 ;
F_36 ( & V_94 -> V_98 , V_72 ) ;
if ( ! V_92 -> V_99 ) {
F_32 ( & V_92 -> V_100 , & V_94 -> V_100 ) ;
V_92 -> V_99 = true ;
}
F_37 ( & V_94 -> V_98 , V_72 ) ;
}
void F_81 ( struct V_121 * V_122 )
{
struct V_93 * V_94 = F_39 ( V_122 , struct V_93 ,
V_149 ) ;
F_82 ( V_150 ) ;
struct V_91 * V_92 , * V_151 ;
F_31 ( & V_94 -> V_152 ) ;
F_83 ( & V_94 -> V_150 , & V_150 ) ;
F_33 ( & V_94 -> V_152 ) ;
F_84 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_52 ( & V_92 -> V_153 ) ;
F_85 ( & V_94 -> V_154 ) ;
F_34 ( L_38
L_39 , V_92 -> V_86 -> V_71 () , V_92 ,
( V_92 -> V_105 == V_155 ) ? L_40 :
( V_92 -> V_105 == V_156 ) ? L_41
: L_42 ) ;
if ( V_92 -> V_105 == V_156 )
F_86 ( V_92 ) ;
else if ( V_92 -> V_105 == V_155 )
F_87 ( V_92 ) ;
}
}
unsigned char * F_88 ( struct V_91 * V_92 )
{
switch ( V_92 -> V_157 ) {
case V_158 :
return L_43 ;
case V_159 :
return L_44 ;
case V_160 :
return L_45 ;
case V_161 :
return L_46 ;
default:
break;
}
return L_42 ;
}
void F_89 (
struct V_93 * V_94 ,
char * V_162 ,
int * V_163 )
{
* V_163 += sprintf ( V_162 + * V_163 , L_47 ) ;
if ( V_94 -> V_164 )
* V_163 += sprintf ( V_162 + * V_163 , L_48 ) ;
else
* V_163 += sprintf ( V_162 + * V_163 , L_49 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_50 , V_94 -> V_165 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_51 ,
V_94 -> V_166 . V_167 ,
V_94 -> V_166 . V_168 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_52 ) ;
}
void F_90 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_77 ;
memset ( V_60 , 0 , V_173 ) ;
V_77 = sprintf ( V_60 , L_53 ) ;
switch ( V_170 -> V_174 ) {
case 0x00 :
sprintf ( V_60 + V_77 , L_54 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_77 , L_55 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_77 , L_56 ) ;
break;
case 0x30 :
sprintf ( V_60 + V_77 , L_57 ) ;
break;
case 0x40 :
sprintf ( V_60 + V_77 , L_58
L_59 ) ;
break;
case 0x50 :
sprintf ( V_60 + V_77 , L_60 ) ;
break;
case 0x60 :
sprintf ( V_60 + V_77 , L_61 ) ;
break;
case 0x70 :
sprintf ( V_60 + V_77 , L_62
L_59 ) ;
break;
case 0x80 :
sprintf ( V_60 + V_77 , L_63 ) ;
break;
default:
sprintf ( V_60 + V_77 , L_64 ,
V_170 -> V_174 ) ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_34 ( L_65 , V_60 ) ;
}
void
F_91 ( struct V_169 * V_170 , unsigned char * V_175 )
{
if ( V_175 [ 1 ] & 0x80 ) {
V_170 -> V_174 = ( V_175 [ 0 ] & 0xf0 ) ;
V_170 -> V_176 = 1 ;
F_90 ( V_170 , NULL , 0 ) ;
}
}
int F_92 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_77 ;
memset ( V_60 , 0 , V_173 ) ;
V_77 = sprintf ( V_60 , L_66 ) ;
switch ( V_170 -> V_177 ) {
case 0x00 :
sprintf ( V_60 + V_77 , L_67 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_77 , L_68 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_77 , L_69 ) ;
break;
default:
sprintf ( V_60 + V_77 , L_64 , V_170 -> V_177 ) ;
V_33 = - V_178 ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_34 ( L_65 , V_60 ) ;
return V_33 ;
}
int F_93 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_177 = ( V_175 [ 1 ] & 0x30 ) ;
return F_92 ( V_170 , NULL , 0 ) ;
}
int F_94 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_77 ;
memset ( V_60 , 0 , V_173 ) ;
V_77 = sprintf ( V_60 , L_70 ) ;
switch ( V_170 -> V_179 ) {
case 0x00 :
sprintf ( V_60 + V_77 , L_71 ) ;
break;
case 0x01 :
sprintf ( V_60 + V_77 , L_72 ) ;
break;
case 0x02 :
sprintf ( V_60 + V_77 , L_73 ) ;
break;
case 0x03 :
sprintf ( V_60 + V_77 , L_74 ) ;
break;
case 0x04 :
sprintf ( V_60 + V_77 , L_75 ) ;
break;
case 0x08 :
sprintf ( V_60 + V_77 , L_76 ) ;
break;
default:
sprintf ( V_60 + V_77 , L_77 ,
V_170 -> V_179 ) ;
V_33 = - V_178 ;
break;
}
if ( V_171 ) {
if ( V_172 < strlen ( V_60 ) + 1 )
return - V_178 ;
strncpy ( V_171 , V_60 , V_172 ) ;
} else {
F_34 ( L_65 , V_60 ) ;
}
return V_33 ;
}
int F_95 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_179 = ( V_175 [ 1 ] & 0x0f ) ;
return F_94 ( V_170 , NULL , 0 ) ;
}
int F_96 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
memset ( V_60 , 0 , V_173 ) ;
switch ( V_170 -> V_180 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_78 ,
& V_170 -> V_181 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_79 ,
& V_170 -> V_181 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_80 ,
& V_170 -> V_181 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_81
L_82 , V_170 -> V_180 ) ;
V_33 = - V_178 ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_34 ( L_65 , V_60 ) ;
return V_33 ;
}
int
F_97 ( struct V_169 * V_170 , unsigned char * V_175 )
{
static const char V_182 [] = L_83 ;
int V_183 = 0 , V_184 = 4 ;
V_170 -> V_180 = ( V_175 [ 0 ] & 0x0f ) ;
switch ( V_170 -> V_180 ) {
case 0x01 :
V_170 -> V_181 [ V_183 ++ ] =
V_182 [ V_170 -> V_179 ] ;
while ( V_184 < ( 4 + V_175 [ 3 ] ) ) {
V_170 -> V_181 [ V_183 ++ ] =
V_182 [ ( V_175 [ V_184 ] & 0xf0 ) >> 4 ] ;
V_170 -> V_181 [ V_183 ++ ] =
V_182 [ V_175 [ V_184 ] & 0x0f ] ;
V_184 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_184 < ( 4 + V_175 [ 3 ] ) )
V_170 -> V_181 [ V_183 ++ ] = V_175 [ V_184 ++ ] ;
break;
default:
break;
}
return F_96 ( V_170 , NULL , 0 ) ;
}
static T_5
F_98 ( struct V_91 * V_92 , struct V_93 * V_94 ,
unsigned int V_185 )
{
T_1 V_186 ;
if ( ! V_92 -> V_86 -> V_187 )
return V_188 ;
V_186 = ( V_92 -> V_86 -> V_187 * V_80 ) ;
if ( V_92 -> V_146 > V_186 ) {
if ( V_92 -> V_117 & V_189 ) {
V_92 -> V_148 = ( V_185 - V_186 ) ;
} else if ( V_92 -> V_117 & V_147 ) {
T_1 V_190 = V_185 + V_92 -> V_148 ;
V_92 -> V_148 = ( V_190 - V_186 ) ;
} else {
V_92 -> V_117 |= V_147 ;
V_92 -> V_148 = ( V_92 -> V_146 - V_186 ) ;
}
V_92 -> V_146 = V_186 ;
if ( V_92 -> V_191 ) {
T_1 V_192 = ( V_186 / V_94 -> V_166 . V_167 ) ;
V_92 -> V_191 = V_94 -> V_191 * V_192 ;
}
}
return V_188 ;
}
T_5
F_99 ( struct V_91 * V_92 , unsigned int V_185 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
if ( V_92 -> V_193 ) {
V_92 -> V_146 = V_185 ;
} else if ( V_185 != V_92 -> V_146 ) {
F_100 ( L_84
L_85
L_86 , V_92 -> V_86 -> V_71 () ,
V_92 -> V_146 , V_185 , V_92 -> V_194 [ 0 ] ) ;
if ( V_92 -> V_157 == V_160 &&
V_92 -> V_117 & V_195 ) {
F_4 ( L_87 ) ;
return V_196 ;
}
if ( V_94 -> V_166 . V_167 != 512 ) {
F_4 ( L_88
L_89
L_90 , V_94 -> V_129 -> V_130 ) ;
return V_196 ;
}
if ( V_185 > V_92 -> V_146 ) {
V_92 -> V_117 |= V_189 ;
V_92 -> V_148 = ( V_185 - V_92 -> V_146 ) ;
} else {
V_92 -> V_117 |= V_147 ;
V_92 -> V_148 = ( V_92 -> V_146 - V_185 ) ;
V_92 -> V_146 = V_185 ;
}
}
return F_98 ( V_92 , V_94 , V_185 ) ;
}
void F_101 (
struct V_91 * V_92 ,
const struct V_57 * V_58 ,
struct V_2 * V_37 ,
T_1 V_146 ,
int V_157 ,
int V_197 ,
unsigned char * V_132 )
{
F_18 ( & V_92 -> V_198 ) ;
F_18 ( & V_92 -> V_153 ) ;
F_18 ( & V_92 -> V_199 ) ;
F_18 ( & V_92 -> V_100 ) ;
F_102 ( & V_92 -> V_110 ) ;
F_102 ( & V_92 -> V_200 ) ;
F_19 ( & V_92 -> V_104 ) ;
F_20 ( & V_92 -> V_201 ) ;
V_92 -> V_96 = V_202 ;
V_92 -> V_86 = V_58 ;
V_92 -> V_37 = V_37 ;
V_92 -> V_146 = V_146 ;
V_92 -> V_157 = V_157 ;
V_92 -> V_203 = V_197 ;
V_92 -> V_132 = V_132 ;
V_92 -> V_99 = false ;
}
static T_5
F_103 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
if ( V_94 -> V_129 -> V_204 & V_205 )
return 0 ;
if ( V_92 -> V_203 == V_206 ) {
F_34 ( L_91
L_92 ) ;
return V_196 ;
}
return 0 ;
}
T_5
F_104 ( struct V_91 * V_92 , unsigned char * V_207 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
T_5 V_33 ;
if ( F_105 ( V_207 ) > V_208 ) {
F_4 ( L_93
L_94 ,
F_105 ( V_207 ) , V_208 ) ;
return V_196 ;
}
if ( F_105 ( V_207 ) > sizeof( V_92 -> V_209 ) ) {
V_92 -> V_194 = F_22 ( F_105 ( V_207 ) ,
V_38 ) ;
if ( ! V_92 -> V_194 ) {
F_4 ( L_95
L_96 ,
F_105 ( V_207 ) ,
( unsigned long ) sizeof( V_92 -> V_209 ) ) ;
return V_210 ;
}
} else
V_92 -> V_194 = & V_92 -> V_209 [ 0 ] ;
memcpy ( V_92 -> V_194 , V_207 , F_105 ( V_207 ) ) ;
F_106 ( V_92 ) ;
V_33 = F_107 ( V_92 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_108 ( V_92 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_109 ( V_92 ) ;
if ( V_33 ) {
V_92 -> V_131 = V_211 ;
return V_33 ;
}
V_33 = V_94 -> V_129 -> V_212 ( V_92 ) ;
if ( V_33 == V_213 )
F_110 ( L_97 ,
V_92 -> V_86 -> V_71 () ,
V_92 -> V_37 -> V_54 -> V_79 ,
V_92 -> V_194 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_103 ( V_92 ) ;
if ( V_33 )
return V_33 ;
V_92 -> V_117 |= V_214 ;
F_111 ( & V_92 -> V_103 -> V_215 . V_216 ) ;
return 0 ;
}
int F_112 (
struct V_91 * V_92 )
{
T_5 V_33 ;
if ( ! V_92 -> V_103 ) {
F_113 () ;
F_4 ( L_98 ) ;
return - V_178 ;
}
if ( F_114 () ) {
F_113 () ;
F_4 ( L_99
L_100 ) ;
return - V_178 ;
}
V_92 -> V_105 = V_217 ;
V_92 -> V_96 |= V_111 ;
V_33 = F_115 ( V_92 ) ;
if ( V_33 )
F_72 ( V_92 , V_33 ) ;
return 0 ;
}
T_5
F_116 ( struct V_91 * V_92 , struct V_218 * V_219 ,
T_1 V_220 , struct V_218 * V_221 , T_1 V_222 )
{
if ( ! V_219 || ! V_220 )
return 0 ;
if ( V_92 -> V_117 & V_189 ) {
F_100 ( L_101
L_102 ) ;
return V_196 ;
}
V_92 -> V_136 = V_219 ;
V_92 -> V_223 = V_220 ;
V_92 -> V_224 = V_221 ;
V_92 -> V_225 = V_222 ;
V_92 -> V_117 |= V_226 ;
return 0 ;
}
int F_117 ( struct V_91 * V_91 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_227 , T_6 V_228 ,
T_1 V_146 , int V_197 , int V_229 , int V_72 ,
struct V_218 * V_219 , T_1 V_220 ,
struct V_218 * V_221 , T_1 V_222 ,
struct V_218 * V_230 , T_1 V_231 )
{
struct V_52 * V_53 ;
T_5 V_47 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_10 ( V_91 -> V_86 || V_91 -> V_37 ) ;
F_10 ( F_114 () ) ;
F_101 ( V_91 , V_53 -> V_59 , V_37 ,
V_146 , V_229 , V_197 , V_227 ) ;
if ( V_72 & V_232 )
V_91 -> V_117 |= V_142 ;
else
V_91 -> V_143 = V_233 ;
if ( V_72 & V_234 )
V_91 -> V_193 = 1 ;
V_33 = F_118 ( V_91 , V_72 & V_235 ) ;
if ( V_33 )
return V_33 ;
if ( V_72 & V_236 )
V_91 -> V_117 |= V_237 ;
V_47 = F_119 ( V_91 , V_228 ) ;
if ( V_47 ) {
F_120 ( V_91 , V_47 , 0 ) ;
F_121 ( V_91 ) ;
return 0 ;
}
V_47 = F_104 ( V_91 , V_207 ) ;
if ( V_47 != 0 ) {
F_72 ( V_91 , V_47 ) ;
return 0 ;
}
if ( V_231 ) {
V_91 -> V_238 = V_230 ;
V_91 -> V_239 = V_231 ;
V_91 -> V_117 |= V_240 ;
}
if ( V_220 != 0 ) {
F_10 ( ! V_219 ) ;
if ( ! ( V_91 -> V_117 & V_195 ) &&
V_91 -> V_157 == V_159 ) {
unsigned char * V_60 = NULL ;
if ( V_219 )
V_60 = F_122 ( F_123 ( V_219 ) ) + V_219 -> V_241 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_219 -> V_144 ) ;
F_124 ( F_123 ( V_219 ) ) ;
}
}
V_47 = F_116 ( V_91 , V_219 , V_220 ,
V_221 , V_222 ) ;
if ( V_47 != 0 ) {
F_72 ( V_91 , V_47 ) ;
return 0 ;
}
}
F_125 ( V_91 ) ;
F_112 ( V_91 ) ;
return 0 ;
}
int F_126 ( struct V_91 * V_91 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_227 , T_6 V_228 ,
T_1 V_146 , int V_197 , int V_229 , int V_72 )
{
return F_117 ( V_91 , V_37 , V_207 , V_227 ,
V_228 , V_146 , V_197 , V_229 ,
V_72 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_127 ( struct V_121 * V_122 )
{
struct V_91 * V_91 = F_39 ( V_122 , struct V_91 , V_122 ) ;
V_91 -> V_242 -> V_243 = V_244 ;
V_91 -> V_86 -> V_245 ( V_91 ) ;
F_65 ( V_91 ) ;
}
int F_128 ( struct V_91 * V_91 , struct V_2 * V_37 ,
unsigned char * V_227 , T_6 V_228 ,
void * V_246 , unsigned char V_247 ,
T_7 V_248 , T_6 V_109 , int V_72 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_101 ( V_91 , V_53 -> V_59 , V_37 ,
0 , V_158 , V_249 , V_227 ) ;
V_33 = F_129 ( V_91 , V_246 , V_247 , V_248 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_247 == V_250 )
V_91 -> V_242 -> V_251 = V_109 ;
V_33 = F_118 ( V_91 , V_72 & V_235 ) ;
if ( V_33 ) {
F_130 ( V_91 -> V_242 ) ;
return V_33 ;
}
V_33 = F_131 ( V_91 , V_228 ) ;
if ( V_33 ) {
F_76 ( & V_91 -> V_122 , F_127 ) ;
F_132 ( & V_91 -> V_122 ) ;
return 0 ;
}
F_133 ( V_91 ) ;
return 0 ;
}
void F_72 ( struct V_91 * V_92 ,
T_5 V_252 )
{
int V_33 = 0 , V_253 = 0 ;
F_34 ( L_103
L_104 , V_92 , V_92 -> V_109 , V_92 -> V_194 [ 0 ] ) ;
F_34 ( L_105 ,
V_92 -> V_86 -> V_254 ( V_92 ) ,
V_92 -> V_105 , V_252 ) ;
F_34 ( L_106 ,
( V_92 -> V_96 & V_111 ) != 0 ,
( V_92 -> V_96 & V_107 ) != 0 ,
( V_92 -> V_96 & V_255 ) != 0 ) ;
F_134 ( V_92 ) ;
if ( ( V_92 -> V_117 & V_256 ) &&
V_92 -> V_257 )
V_92 -> V_257 ( V_92 , false , & V_253 ) ;
switch ( V_252 ) {
case V_258 :
case V_213 :
case V_196 :
case V_259 :
case V_260 :
case V_123 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
break;
case V_210 :
V_252 = V_123 ;
break;
case V_270 :
V_92 -> V_131 = V_211 ;
if ( V_92 -> V_37 &&
V_92 -> V_95 -> V_166 . V_271 == 2 ) {
F_135 ( V_92 -> V_37 -> V_54 ,
V_92 -> V_272 , 0x2C ,
V_273 ) ;
}
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_274 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
goto V_277;
default:
F_4 ( L_107 ,
V_92 -> V_194 [ 0 ] , V_252 ) ;
V_252 = V_213 ;
break;
}
V_33 = F_120 ( V_92 , V_252 , 0 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
V_277:
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
return;
V_276:
V_92 -> V_105 = V_155 ;
F_137 ( V_92 , V_92 -> V_95 ) ;
}
void F_138 ( struct V_91 * V_92 )
{
T_5 V_33 ;
if ( V_92 -> V_278 ) {
V_33 = V_92 -> V_278 ( V_92 ) ;
if ( V_33 ) {
F_31 ( & V_92 -> V_104 ) ;
V_92 -> V_96 &= ~ ( V_97 | V_255 ) ;
F_33 ( & V_92 -> V_104 ) ;
F_72 ( V_92 , V_33 ) ;
}
}
}
static int F_139 ( struct V_91 * V_92 )
{
T_1 V_192 ;
switch ( V_92 -> V_279 ) {
case V_280 :
if ( ! ( V_92 -> V_37 -> V_36 & V_280 ) )
F_140 ( V_92 ) ;
break;
case V_281 :
if ( V_92 -> V_37 -> V_36 & V_281 )
break;
V_192 = V_92 -> V_146 >> F_141 ( V_92 -> V_95 -> V_166 . V_167 ) ;
V_92 -> V_282 = F_142 ( V_92 , V_92 -> V_283 ,
V_192 , 0 , V_92 -> V_238 , 0 ) ;
if ( F_143 ( V_92 -> V_282 ) ) {
F_31 ( & V_92 -> V_104 ) ;
V_92 -> V_96 &= ~ ( V_97 | V_255 ) ;
F_33 ( & V_92 -> V_104 ) ;
F_72 ( V_92 , V_92 -> V_282 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_144 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
if ( V_94 -> V_129 -> V_204 & V_205 )
return false ;
switch ( V_92 -> V_203 ) {
case V_284 :
F_34 ( L_108 ,
V_92 -> V_194 [ 0 ] ) ;
return false ;
case V_285 :
F_145 ( & V_94 -> V_286 ) ;
F_34 ( L_109 ,
V_92 -> V_194 [ 0 ] ) ;
if ( ! F_146 ( & V_94 -> V_287 ) )
return false ;
break;
default:
F_145 ( & V_94 -> V_287 ) ;
break;
}
if ( F_146 ( & V_94 -> V_286 ) == 0 )
return false ;
F_11 ( & V_94 -> V_288 ) ;
F_32 ( & V_92 -> V_198 , & V_94 -> V_289 ) ;
F_12 ( & V_94 -> V_288 ) ;
F_34 ( L_110 ,
V_92 -> V_194 [ 0 ] , V_92 -> V_203 ) ;
return true ;
}
void F_147 ( struct V_91 * V_92 )
{
F_31 ( & V_92 -> V_104 ) ;
if ( F_148 ( V_92 , 1 ) ) {
F_33 ( & V_92 -> V_104 ) ;
return;
}
if ( V_92 -> V_96 & V_107 ) {
F_34 ( L_36 ,
V_108 , __LINE__ , V_92 -> V_109 ) ;
F_33 ( & V_92 -> V_104 ) ;
F_64 ( & V_92 -> V_110 ) ;
return;
}
V_92 -> V_105 = V_290 ;
V_92 -> V_96 |= V_111 | V_97 | V_255 ;
F_33 ( & V_92 -> V_104 ) ;
if ( F_139 ( V_92 ) )
return;
if ( F_144 ( V_92 ) ) {
F_31 ( & V_92 -> V_104 ) ;
V_92 -> V_96 &= ~ ( V_97 | V_255 ) ;
F_33 ( & V_92 -> V_104 ) ;
return;
}
F_138 ( V_92 ) ;
}
static void F_149 ( struct V_93 * V_94 )
{
for (; ; ) {
struct V_91 * V_92 ;
F_11 ( & V_94 -> V_288 ) ;
if ( F_53 ( & V_94 -> V_289 ) ) {
F_12 ( & V_94 -> V_288 ) ;
break;
}
V_92 = F_150 ( V_94 -> V_289 . V_291 ,
struct V_91 , V_198 ) ;
F_52 ( & V_92 -> V_198 ) ;
F_12 ( & V_94 -> V_288 ) ;
F_138 ( V_92 ) ;
if ( V_92 -> V_203 == V_285 )
break;
}
}
static void F_134 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 ;
if ( V_94 -> V_129 -> V_204 & V_205 )
return;
if ( V_92 -> V_203 == V_249 ) {
F_85 ( & V_94 -> V_287 ) ;
V_94 -> V_292 ++ ;
F_34 ( L_111 ,
V_94 -> V_292 ) ;
} else if ( V_92 -> V_203 == V_284 ) {
V_94 -> V_292 ++ ;
F_34 ( L_112 ,
V_94 -> V_292 ) ;
} else if ( V_92 -> V_203 == V_285 ) {
F_85 ( & V_94 -> V_286 ) ;
V_94 -> V_292 ++ ;
F_34 ( L_113 ,
V_94 -> V_292 ) ;
}
F_149 ( V_94 ) ;
}
static void F_87 ( struct V_91 * V_92 )
{
int V_33 = 0 ;
F_134 ( V_92 ) ;
if ( V_92 -> V_117 & V_137 ) {
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_274 ( V_92 ) ;
goto V_3;
}
switch ( V_92 -> V_157 ) {
case V_159 :
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_293 ( V_92 ) ;
break;
case V_160 :
if ( V_92 -> V_117 & V_237 ) {
V_33 = V_92 -> V_86 -> V_293 ( V_92 ) ;
break;
}
case V_158 :
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_274 ( V_92 ) ;
break;
default:
break;
}
V_3:
if ( V_33 < 0 ) {
F_137 ( V_92 , V_92 -> V_95 ) ;
return;
}
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
}
static void F_137 (
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
F_31 ( & V_94 -> V_152 ) ;
F_32 ( & V_92 -> V_153 , & V_92 -> V_95 -> V_150 ) ;
F_145 ( & V_94 -> V_154 ) ;
F_33 ( & V_92 -> V_95 -> V_152 ) ;
F_132 ( & V_92 -> V_95 -> V_149 ) ;
}
static bool F_151 ( struct V_91 * V_92 )
{
switch ( V_92 -> V_279 ) {
case V_294 :
if ( ! ( V_92 -> V_37 -> V_36 & V_294 ) ) {
T_1 V_192 = V_92 -> V_146 >>
F_141 ( V_92 -> V_95 -> V_166 . V_167 ) ;
V_92 -> V_282 = F_142 ( V_92 , V_92 -> V_283 ,
V_192 , 0 , V_92 -> V_238 ,
0 ) ;
if ( V_92 -> V_282 )
return true ;
}
break;
case V_295 :
if ( V_92 -> V_37 -> V_36 & V_295 )
break;
F_140 ( V_92 ) ;
break;
default:
break;
}
return false ;
}
static void V_139 ( struct V_121 * V_122 )
{
struct V_91 * V_92 = F_39 ( V_122 , struct V_91 , V_122 ) ;
int V_33 ;
F_134 ( V_92 ) ;
if ( F_146 ( & V_92 -> V_95 -> V_154 ) != 0 )
F_132 ( & V_92 -> V_95 -> V_149 ) ;
if ( V_92 -> V_117 & V_137 ) {
F_74 ( ! V_92 -> V_131 ) ;
V_33 = F_120 (
V_92 , 0 , 1 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
return;
}
if ( V_92 -> V_257 ) {
T_5 V_47 ;
bool V_296 = ( V_92 -> V_117 & V_256 ) ;
bool V_297 = ! ( V_92 -> V_146 ) ;
int V_253 = 0 ;
V_47 = V_92 -> V_257 ( V_92 , true , & V_253 ) ;
if ( ! V_47 && ! V_253 ) {
if ( V_296 && V_297 )
goto V_298;
return;
} else if ( V_47 ) {
V_33 = F_120 ( V_92 ,
V_47 , 0 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
return;
}
}
V_298:
switch ( V_92 -> V_157 ) {
case V_159 :
F_152 ( V_92 -> V_146 ,
& V_92 -> V_103 -> V_215 . V_299 ) ;
if ( F_151 ( V_92 ) ) {
V_33 = F_120 ( V_92 ,
V_92 -> V_282 , 0 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
return;
}
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_293 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
break;
case V_160 :
F_152 ( V_92 -> V_146 ,
& V_92 -> V_103 -> V_215 . V_300 ) ;
if ( V_92 -> V_117 & V_237 ) {
F_152 ( V_92 -> V_146 ,
& V_92 -> V_103 -> V_215 . V_299 ) ;
V_33 = V_92 -> V_86 -> V_293 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
break;
}
case V_158 :
F_136 ( V_92 ) ;
V_33 = V_92 -> V_86 -> V_274 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
break;
default:
break;
}
F_66 ( V_92 ) ;
F_65 ( V_92 ) ;
return;
V_276:
F_34 ( L_114
L_115 , V_92 , V_92 -> V_157 ) ;
V_92 -> V_105 = V_155 ;
F_137 ( V_92 , V_92 -> V_95 ) ;
}
static inline void F_153 ( struct V_218 * V_219 , int V_301 )
{
struct V_218 * V_302 ;
int V_303 ;
F_154 (sgl, sg, nents, count)
F_155 ( F_123 ( V_302 ) ) ;
F_61 ( V_219 ) ;
}
static inline void F_156 ( struct V_91 * V_92 )
{
if ( ! V_92 -> V_304 )
return;
F_61 ( V_92 -> V_136 ) ;
V_92 -> V_136 = V_92 -> V_304 ;
V_92 -> V_304 = NULL ;
V_92 -> V_223 = V_92 -> V_305 ;
V_92 -> V_305 = 0 ;
}
static inline void F_157 ( struct V_91 * V_92 )
{
if ( ! ( V_92 -> V_117 & V_240 ) ) {
F_153 ( V_92 -> V_238 , V_92 -> V_239 ) ;
V_92 -> V_238 = NULL ;
V_92 -> V_239 = 0 ;
}
if ( V_92 -> V_117 & V_226 ) {
if ( V_92 -> V_117 & V_256 ) {
F_153 ( V_92 -> V_224 ,
V_92 -> V_225 ) ;
V_92 -> V_224 = NULL ;
V_92 -> V_225 = 0 ;
}
F_156 ( V_92 ) ;
return;
}
F_156 ( V_92 ) ;
F_153 ( V_92 -> V_136 , V_92 -> V_223 ) ;
V_92 -> V_136 = NULL ;
V_92 -> V_223 = 0 ;
F_153 ( V_92 -> V_224 , V_92 -> V_225 ) ;
V_92 -> V_224 = NULL ;
V_92 -> V_225 = 0 ;
}
static int F_70 ( struct V_91 * V_92 )
{
F_10 ( ! V_92 -> V_86 ) ;
return F_121 ( V_92 ) ;
}
void * F_158 ( struct V_91 * V_92 )
{
struct V_218 * V_302 = V_92 -> V_136 ;
struct V_76 * * V_306 ;
int V_184 ;
if ( ! V_92 -> V_223 )
return NULL ;
F_10 ( ! V_302 ) ;
if ( V_92 -> V_223 == 1 )
return F_122 ( F_123 ( V_302 ) ) + V_302 -> V_241 ;
V_306 = F_159 ( sizeof( * V_306 ) * V_92 -> V_223 , V_38 ) ;
if ( ! V_306 )
return NULL ;
F_154 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_306 [ V_184 ] = F_123 ( V_302 ) ;
}
V_92 -> V_307 = F_160 ( V_306 , V_92 -> V_223 , V_308 , V_309 ) ;
F_61 ( V_306 ) ;
if ( ! V_92 -> V_307 )
return NULL ;
return V_92 -> V_307 + V_92 -> V_136 [ 0 ] . V_241 ;
}
void F_161 ( struct V_91 * V_92 )
{
if ( ! V_92 -> V_223 ) {
return;
} else if ( V_92 -> V_223 == 1 ) {
F_124 ( F_123 ( V_92 -> V_136 ) ) ;
return;
}
F_162 ( V_92 -> V_307 ) ;
V_92 -> V_307 = NULL ;
}
int
F_163 ( struct V_218 * * V_219 , unsigned int * V_301 , T_1 V_144 ,
bool V_310 )
{
struct V_218 * V_302 ;
struct V_76 * V_76 ;
T_7 V_311 = ( V_310 ) ? V_312 : 0 ;
unsigned int V_313 ;
int V_184 = 0 ;
V_313 = F_164 ( V_144 , V_80 ) ;
V_302 = F_159 ( sizeof( struct V_218 ) * V_313 , V_38 ) ;
if ( ! V_302 )
return - V_28 ;
F_165 ( V_302 , V_313 ) ;
while ( V_144 ) {
T_1 V_314 = F_166 ( T_1 , V_144 , V_80 ) ;
V_76 = F_167 ( V_38 | V_311 ) ;
if ( ! V_76 )
goto V_3;
F_168 ( & V_302 [ V_184 ] , V_76 , V_314 , 0 ) ;
V_144 -= V_314 ;
V_184 ++ ;
}
* V_219 = V_302 ;
* V_301 = V_313 ;
return 0 ;
V_3:
while ( V_184 > 0 ) {
V_184 -- ;
F_155 ( F_123 ( & V_302 [ V_184 ] ) ) ;
}
F_61 ( V_302 ) ;
return - V_28 ;
}
T_5
F_115 ( struct V_91 * V_92 )
{
int V_33 = 0 ;
bool V_311 = ! ( V_92 -> V_117 & V_195 ) ;
if ( V_92 -> V_279 != V_315 &&
! ( V_92 -> V_117 & V_240 ) ) {
V_33 = F_163 ( & V_92 -> V_238 , & V_92 -> V_239 ,
V_92 -> V_191 , true ) ;
if ( V_33 < 0 )
return V_123 ;
}
if ( ! ( V_92 -> V_117 & V_226 ) &&
V_92 -> V_146 ) {
if ( ( V_92 -> V_117 & V_237 ) ||
( V_92 -> V_117 & V_256 ) ) {
T_1 V_316 ;
if ( V_92 -> V_117 & V_256 )
V_316 = V_92 -> V_317 *
V_92 -> V_95 -> V_166 . V_167 ;
else
V_316 = V_92 -> V_146 ;
V_33 = F_163 ( & V_92 -> V_224 ,
& V_92 -> V_225 ,
V_316 , V_311 ) ;
if ( V_33 < 0 )
return V_123 ;
}
V_33 = F_163 ( & V_92 -> V_136 , & V_92 -> V_223 ,
V_92 -> V_146 , V_311 ) ;
if ( V_33 < 0 )
return V_123 ;
} else if ( ( V_92 -> V_117 & V_256 ) &&
V_92 -> V_146 ) {
T_1 V_318 = V_92 -> V_317 *
V_92 -> V_95 -> V_166 . V_167 ;
V_33 = F_163 ( & V_92 -> V_224 ,
& V_92 -> V_225 ,
V_318 , V_311 ) ;
if ( V_33 < 0 )
return V_123 ;
}
F_80 ( V_92 ) ;
if ( V_92 -> V_157 != V_160 || V_92 -> V_146 == 0 ) {
F_147 ( V_92 ) ;
return 0 ;
}
F_63 ( V_92 , false , true ) ;
V_33 = V_92 -> V_86 -> V_102 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 )
goto V_276;
F_74 ( V_33 ) ;
return ( ! V_33 ) ? 0 : V_123 ;
V_276:
F_34 ( L_116 , V_92 ) ;
V_92 -> V_105 = V_156 ;
F_137 ( V_92 , V_92 -> V_95 ) ;
return 0 ;
}
static void F_86 ( struct V_91 * V_92 )
{
int V_33 ;
V_33 = V_92 -> V_86 -> V_102 ( V_92 ) ;
if ( V_33 == - V_275 || V_33 == - V_28 ) {
F_34 ( L_116 ,
V_92 ) ;
F_137 ( V_92 , V_92 -> V_95 ) ;
}
}
static void F_169 ( struct V_91 * V_92 , bool * V_319 , bool * V_320 )
{
unsigned long V_72 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
F_170 ( V_92 , true , V_319 , V_320 , & V_72 ) ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
}
int F_171 ( struct V_91 * V_92 , int V_321 )
{
int V_33 = 0 ;
bool V_319 = false , V_320 = false ;
if ( ! ( V_92 -> V_117 & V_119 ) ) {
if ( V_321 && ( V_92 -> V_117 & V_322 ) )
F_169 ( V_92 , & V_319 , & V_320 ) ;
if ( ! V_319 || V_320 )
V_33 = F_70 ( V_92 ) ;
} else {
if ( V_321 )
F_169 ( V_92 , & V_319 , & V_320 ) ;
if ( V_92 -> V_99 )
F_62 ( V_92 ) ;
if ( V_92 -> V_103 )
F_66 ( V_92 ) ;
if ( ! V_319 || V_320 )
V_33 = F_70 ( V_92 ) ;
}
if ( V_319 ) {
F_34 ( L_117 , V_92 -> V_109 ) ;
F_172 ( & V_92 -> V_200 ) ;
V_92 -> V_86 -> V_323 ( V_92 ) ;
V_33 = 1 ;
}
return V_33 ;
}
int F_118 ( struct V_91 * V_91 , bool V_116 )
{
struct V_2 * V_37 = V_91 -> V_37 ;
unsigned long V_72 ;
int V_33 = 0 ;
if ( V_116 )
F_173 ( & V_91 -> V_201 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_324 ) {
V_33 = - V_325 ;
goto V_3;
}
F_32 ( & V_91 -> V_199 , & V_37 -> V_41 ) ;
V_3:
F_37 ( & V_37 -> V_43 , V_72 ) ;
if ( V_33 && V_116 )
F_121 ( V_91 ) ;
return V_33 ;
}
static void F_174 ( struct V_91 * V_92 )
{
F_157 ( V_92 ) ;
if ( V_92 -> V_117 & V_322 )
F_130 ( V_92 -> V_242 ) ;
if ( V_92 -> V_194 != V_92 -> V_209 )
F_61 ( V_92 -> V_194 ) ;
}
static void F_175 ( struct V_74 * V_74 )
{
struct V_91 * V_91 = F_39 ( V_74 , struct V_91 , V_201 ) ;
struct V_2 * V_37 = V_91 -> V_37 ;
unsigned long V_72 ;
bool V_326 ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( F_53 ( & V_91 -> V_199 ) ) {
F_37 ( & V_37 -> V_43 , V_72 ) ;
F_174 ( V_91 ) ;
V_91 -> V_86 -> V_323 ( V_91 ) ;
return;
}
F_11 ( & V_91 -> V_104 ) ;
V_326 = ( V_91 -> V_96 & V_327 ) ;
F_12 ( & V_91 -> V_104 ) ;
if ( V_91 -> V_328 || V_326 ) {
F_176 ( & V_91 -> V_199 ) ;
F_37 ( & V_37 -> V_43 , V_72 ) ;
F_174 ( V_91 ) ;
F_49 ( & V_91 -> V_200 ) ;
return;
}
F_176 ( & V_91 -> V_199 ) ;
F_37 ( & V_37 -> V_43 , V_72 ) ;
F_174 ( V_91 ) ;
V_91 -> V_86 -> V_323 ( V_91 ) ;
}
int F_121 ( struct V_91 * V_91 )
{
struct V_2 * V_37 = V_91 -> V_37 ;
if ( ! V_37 ) {
F_174 ( V_91 ) ;
V_91 -> V_86 -> V_323 ( V_91 ) ;
return 1 ;
}
return F_43 ( & V_91 -> V_201 , F_175 ) ;
}
void F_177 ( struct V_2 * V_37 )
{
struct V_91 * V_91 ;
unsigned long V_72 ;
int V_47 ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_324 ) {
F_37 ( & V_37 -> V_43 , V_72 ) ;
return;
}
V_37 -> V_324 = 1 ;
F_83 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_46 (se_cmd, &se_sess->sess_wait_list, se_cmd_list) {
V_47 = F_41 ( & V_91 -> V_201 ) ;
if ( V_47 ) {
V_91 -> V_328 = 1 ;
F_11 ( & V_91 -> V_104 ) ;
V_91 -> V_96 |= V_327 ;
F_12 ( & V_91 -> V_104 ) ;
}
}
F_37 ( & V_37 -> V_43 , V_72 ) ;
}
void F_178 ( struct V_2 * V_37 )
{
struct V_91 * V_91 , * V_329 ;
unsigned long V_72 ;
bool V_320 ;
F_84 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_176 ( & V_91 -> V_199 ) ;
F_34 ( L_118
L_119 , V_91 , V_91 -> V_105 ,
V_91 -> V_86 -> V_254 ( V_91 ) ) ;
F_36 ( & V_91 -> V_104 , V_72 ) ;
V_320 = ( V_91 -> V_96 & V_330 ) ;
F_37 ( & V_91 -> V_104 , V_72 ) ;
if ( ! F_121 ( V_91 ) ) {
if ( V_320 )
F_121 ( V_91 ) ;
}
F_172 ( & V_91 -> V_200 ) ;
F_34 ( L_120
L_121 , V_91 , V_91 -> V_105 ,
V_91 -> V_86 -> V_254 ( V_91 ) ) ;
V_91 -> V_86 -> V_323 ( V_91 ) ;
}
F_36 ( & V_37 -> V_43 , V_72 ) ;
F_74 ( ! F_53 ( & V_37 -> V_41 ) ) ;
F_37 ( & V_37 -> V_43 , V_72 ) ;
}
void F_179 ( struct V_103 * V_113 )
{
F_180 ( & V_113 -> V_115 ) ;
F_172 ( & V_113 -> V_331 ) ;
}
static bool
F_170 ( struct V_91 * V_92 , bool V_326 ,
bool * V_319 , bool * V_320 , unsigned long * V_72 )
__releases( &cmd->t_state_lock
bool F_181 ( struct V_91 * V_92 )
{
unsigned long V_72 ;
bool V_33 , V_319 = false , V_320 = false ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
V_33 = F_170 ( V_92 , false , & V_319 , & V_320 , & V_72 ) ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
return V_33 ;
}
static int F_182 ( struct V_91 * V_92 , T_5 V_332 )
{
const struct V_333 * V_334 ;
T_4 * V_335 = V_92 -> V_132 ;
int V_336 = ( V_337 int ) V_332 ;
T_4 V_338 , V_339 ;
bool V_340 = F_183 ( V_92 -> V_95 ) ;
if ( V_336 < F_184 ( V_341 ) && V_341 [ V_336 ] . V_342 )
V_334 = & V_341 [ V_336 ] ;
else
V_334 = & V_341 [ ( V_337 int )
V_123 ] ;
if ( V_332 == V_265 ) {
F_185 ( V_92 , & V_338 , & V_339 ) ;
F_186 ( V_338 == 0 ) ;
} else if ( V_334 -> V_338 == 0 ) {
F_186 ( V_92 -> V_343 == 0 ) ;
V_338 = V_92 -> V_343 ;
V_339 = V_92 -> V_344 ;
} else {
V_338 = V_334 -> V_338 ;
V_339 = V_334 -> V_339 ;
}
F_187 ( V_340 , V_335 , V_334 -> V_342 , V_338 , V_339 ) ;
if ( V_334 -> V_345 )
return F_188 ( V_335 ,
V_92 -> V_125 ,
V_92 -> V_346 ) ;
return 0 ;
}
int
F_120 ( struct V_91 * V_92 ,
T_5 V_332 , int V_347 )
{
unsigned long V_72 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_117 & V_124 ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
return 0 ;
}
V_92 -> V_117 |= V_124 ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
if ( ! V_347 ) {
int V_47 ;
V_92 -> V_117 |= V_348 ;
V_92 -> V_131 = V_349 ;
V_92 -> V_125 = V_126 ;
V_47 = F_182 ( V_92 , V_332 ) ;
if ( V_47 )
return V_47 ;
}
F_136 ( V_92 ) ;
return V_92 -> V_86 -> V_274 ( V_92 ) ;
}
static int F_148 ( struct V_91 * V_92 , int V_350 )
__releases( &cmd->t_state_lock
int F_189 ( struct V_91 * V_92 , int V_350 )
{
int V_33 ;
F_31 ( & V_92 -> V_104 ) ;
V_33 = F_148 ( V_92 , V_350 ) ;
F_33 ( & V_92 -> V_104 ) ;
return V_33 ;
}
void F_190 ( struct V_91 * V_92 )
{
unsigned long V_72 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_117 & ( V_124 ) ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
return;
}
F_37 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_157 == V_160 ) {
if ( V_92 -> V_86 -> V_351 ( V_92 ) != 0 ) {
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_117 & V_352 ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
goto V_353;
}
V_92 -> V_117 |= V_352 ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
return;
}
}
V_353:
V_92 -> V_131 = V_354 ;
F_66 ( V_92 ) ;
F_34 ( L_122 ,
V_92 -> V_194 [ 0 ] , V_92 -> V_109 ) ;
F_136 ( V_92 ) ;
V_92 -> V_86 -> V_274 ( V_92 ) ;
}
static void F_191 ( struct V_121 * V_122 )
{
struct V_91 * V_92 = F_39 ( V_122 , struct V_91 , V_122 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
struct V_242 * V_355 = V_92 -> V_242 ;
unsigned long V_72 ;
int V_33 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_96 & V_138 ) {
V_355 -> V_243 = V_356 ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
goto V_277;
}
F_37 ( & V_92 -> V_104 , V_72 ) ;
switch ( V_355 -> V_357 ) {
case V_250 :
F_192 ( V_94 , V_355 , V_92 -> V_37 ) ;
break;
case V_358 :
case V_359 :
case V_360 :
V_355 -> V_243 = V_361 ;
break;
case V_362 :
V_33 = F_193 ( V_94 , V_355 , NULL , NULL ) ;
V_355 -> V_243 = ( ! V_33 ) ? V_363 :
V_356 ;
if ( V_355 -> V_243 == V_363 ) {
F_135 ( V_92 -> V_37 -> V_54 ,
V_92 -> V_272 , 0x29 ,
V_364 ) ;
}
break;
case V_365 :
V_355 -> V_243 = V_356 ;
break;
case V_366 :
V_355 -> V_243 = V_356 ;
break;
default:
F_4 ( L_123 ,
V_355 -> V_357 ) ;
V_355 -> V_243 = V_356 ;
break;
}
F_36 ( & V_92 -> V_104 , V_72 ) ;
if ( V_92 -> V_96 & V_138 ) {
F_37 ( & V_92 -> V_104 , V_72 ) ;
goto V_277;
}
V_92 -> V_105 = V_367 ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
V_92 -> V_86 -> V_245 ( V_92 ) ;
V_277:
F_65 ( V_92 ) ;
}
int F_133 (
struct V_91 * V_92 )
{
unsigned long V_72 ;
F_36 ( & V_92 -> V_104 , V_72 ) ;
V_92 -> V_96 |= V_111 ;
F_37 ( & V_92 -> V_104 , V_72 ) ;
F_76 ( & V_92 -> V_122 , F_191 ) ;
F_78 ( V_92 -> V_95 -> V_368 , & V_92 -> V_122 ) ;
return 0 ;
}
bool
F_194 ( struct V_93 * V_94 )
{
bool V_369 = false ;
if ( V_94 -> V_129 -> V_370 )
V_369 = V_94 -> V_129 -> V_370 ( V_94 ) ;
else if ( V_94 -> V_166 . V_371 > 0 )
V_369 = true ;
return V_369 ;
}
bool
F_195 ( struct V_93 * V_94 )
{
return F_194 ( V_94 ) && V_94 -> V_166 . V_372 > 0 ;
}
