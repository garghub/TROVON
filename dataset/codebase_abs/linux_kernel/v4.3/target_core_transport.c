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
F_32 ( & V_55 -> V_68 ) ;
V_55 -> V_69 = V_37 ;
F_33 ( & V_37 -> V_40 ,
& V_55 -> V_70 ) ;
F_34 ( & V_55 -> V_68 ) ;
}
F_33 ( & V_37 -> V_39 , & V_53 -> V_71 ) ;
F_35 ( L_33 ,
V_53 -> V_59 -> V_72 () , V_37 -> V_56 ) ;
}
void F_36 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_2 * V_37 ,
void * V_56 )
{
unsigned long V_73 ;
F_37 ( & V_53 -> V_74 , V_73 ) ;
F_29 ( V_53 , V_55 , V_37 , V_56 ) ;
F_38 ( & V_53 -> V_74 , V_73 ) ;
}
static void F_39 ( struct V_75 * V_75 )
{
struct V_2 * V_37 = F_40 ( V_75 ,
struct V_2 , V_44 ) ;
struct V_52 * V_53 = V_37 -> V_53 ;
V_53 -> V_59 -> V_76 ( V_37 ) ;
}
void F_41 ( struct V_2 * V_37 )
{
F_31 ( & V_37 -> V_44 ) ;
}
void F_42 ( struct V_2 * V_37 )
{
F_43 ( & V_37 -> V_44 , F_39 ) ;
}
T_3 F_44 ( struct V_52 * V_53 , char * V_77 )
{
struct V_2 * V_37 ;
T_3 V_78 = 0 ;
F_45 ( & V_53 -> V_74 ) ;
F_46 (se_sess, &se_tpg->tpg_sess_list, sess_list) {
if ( ! V_37 -> V_54 )
continue;
if ( ! V_37 -> V_54 -> V_79 )
continue;
if ( strlen ( V_37 -> V_54 -> V_80 ) + 1 + V_78 > V_81 )
break;
V_78 += snprintf ( V_77 + V_78 , V_81 - V_78 , L_34 ,
V_37 -> V_54 -> V_80 ) ;
V_78 += 1 ;
}
F_47 ( & V_53 -> V_74 ) ;
return V_78 ;
}
static void F_48 ( struct V_75 * V_75 )
{
struct V_54 * V_82 = F_40 ( V_75 ,
struct V_54 , V_67 ) ;
F_49 ( & V_82 -> V_83 ) ;
}
void F_50 ( struct V_54 * V_82 )
{
F_43 ( & V_82 -> V_67 , F_48 ) ;
}
void F_51 ( struct V_2 * V_37 )
{
struct V_54 * V_55 ;
unsigned long V_73 ;
V_55 = V_37 -> V_54 ;
if ( V_55 ) {
F_37 ( & V_55 -> V_68 , V_73 ) ;
if ( V_55 -> V_84 == 0 )
F_52 ( & V_37 -> V_40 ) ;
if ( F_53 ( & V_55 -> V_70 ) )
V_55 -> V_69 = NULL ;
else {
V_55 -> V_69 = F_40 (
V_55 -> V_70 . V_85 ,
struct V_2 , V_40 ) ;
}
F_38 ( & V_55 -> V_68 , V_73 ) ;
}
}
void F_28 ( struct V_2 * V_37 )
{
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
unsigned long V_73 ;
bool V_87 = true , V_88 = false ;
if ( ! V_53 ) {
F_28 ( V_37 ) ;
return;
}
V_86 = V_53 -> V_59 ;
F_37 ( & V_53 -> V_74 , V_73 ) ;
F_52 ( & V_37 -> V_39 ) ;
V_37 -> V_53 = NULL ;
V_37 -> V_56 = NULL ;
F_38 ( & V_53 -> V_74 , V_73 ) ;
V_55 = V_37 -> V_54 ;
F_57 ( & V_53 -> V_89 ) ;
if ( V_55 && V_55 -> V_79 ) {
if ( ! V_86 -> V_90 ( V_53 ) ) {
F_52 ( & V_55 -> V_91 ) ;
V_53 -> V_92 -- ;
V_88 = true ;
}
}
F_58 ( & V_53 -> V_89 ) ;
if ( V_88 ) {
F_59 ( V_55 ) ;
F_60 ( V_55 , V_53 ) ;
F_61 ( V_55 ) ;
V_87 = false ;
}
F_35 ( L_35 ,
V_53 -> V_59 -> V_72 () ) ;
if ( V_55 && V_87 )
F_50 ( V_55 ) ;
F_28 ( V_37 ) ;
}
static void F_62 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
unsigned long V_73 ;
if ( ! V_96 )
return;
if ( V_94 -> V_98 & V_99 )
return;
F_37 ( & V_96 -> V_100 , V_73 ) ;
if ( V_94 -> V_101 ) {
F_52 ( & V_94 -> V_102 ) ;
V_94 -> V_101 = false ;
}
F_38 ( & V_96 -> V_100 , V_73 ) ;
}
static int F_63 ( struct V_93 * V_94 , bool V_103 ,
bool V_104 )
{
unsigned long V_73 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
if ( V_104 )
V_94 -> V_106 = V_107 ;
if ( V_103 ) {
F_62 ( V_94 ) ;
V_94 -> V_108 = NULL ;
}
if ( V_94 -> V_98 & V_109 ) {
F_35 ( L_36 ,
V_110 , __LINE__ , V_94 -> V_111 ) ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_64 ( & V_94 -> V_112 ) ;
return 1 ;
}
V_94 -> V_98 &= ~ V_113 ;
if ( V_103 ) {
if ( V_94 -> V_86 -> V_114 != NULL ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return V_94 -> V_86 -> V_114 ( V_94 ) ;
}
}
F_38 ( & V_94 -> V_105 , V_73 ) ;
return 0 ;
}
static int F_65 ( struct V_93 * V_94 )
{
return F_63 ( V_94 , true , false ) ;
}
static void F_66 ( struct V_93 * V_94 )
{
struct V_108 * V_115 = V_94 -> V_108 ;
if ( ! V_115 )
return;
if ( F_67 ( & V_94 -> V_116 , true , false ) )
F_68 ( & V_115 -> V_117 ) ;
}
void F_69 ( struct V_93 * V_94 , int remove )
{
if ( V_94 -> V_118 & V_119 )
F_66 ( V_94 ) ;
if ( remove )
V_94 -> V_86 -> V_120 ( V_94 ) ;
if ( F_65 ( V_94 ) )
return;
if ( remove )
F_70 ( V_94 ) ;
}
static void F_71 ( struct V_121 * V_122 )
{
struct V_93 * V_94 = F_40 ( V_122 , struct V_93 , V_122 ) ;
F_72 ( V_94 ,
V_123 ) ;
}
static unsigned char * F_73 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
F_74 ( ! V_94 -> V_108 ) ;
if ( ! V_96 )
return NULL ;
if ( V_94 -> V_118 & V_124 )
return NULL ;
V_94 -> V_125 = V_126 ;
F_35 ( L_37 ,
V_96 -> V_127 -> V_128 , V_96 -> V_129 -> V_130 , V_94 -> V_131 ) ;
return V_94 -> V_132 ;
}
void F_75 ( struct V_93 * V_94 , T_4 V_131 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
int V_133 = V_131 == V_134 ;
unsigned long V_73 ;
V_94 -> V_131 = V_131 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
V_94 -> V_98 &= ~ V_99 ;
if ( V_96 && V_96 -> V_129 -> V_135 ) {
V_96 -> V_129 -> V_135 ( V_94 ,
V_94 -> V_136 ,
F_73 ( V_94 ) ) ;
if ( V_94 -> V_118 & V_137 )
V_133 = 1 ;
}
if ( V_94 -> V_98 & V_138 ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_49 ( & V_94 -> V_139 ) ;
return;
}
if ( V_94 -> V_98 & V_140 &&
V_94 -> V_98 & V_109 ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_64 ( & V_94 -> V_112 ) ;
return;
} else if ( ! V_133 ) {
F_76 ( & V_94 -> V_122 , F_71 ) ;
} else {
F_76 ( & V_94 -> V_122 , V_141 ) ;
}
V_94 -> V_106 = V_142 ;
V_94 -> V_98 |= ( V_143 | V_113 ) ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_77 ( V_25 , & V_94 -> V_122 ) ;
}
void F_78 ( struct V_93 * V_94 , T_4 V_131 , int V_144 )
{
if ( V_131 == V_145 && V_144 < V_94 -> V_146 ) {
if ( V_94 -> V_118 & V_147 ) {
V_94 -> V_148 += V_94 -> V_146 - V_144 ;
} else {
V_94 -> V_118 |= V_147 ;
V_94 -> V_148 = V_94 -> V_146 - V_144 ;
}
V_94 -> V_146 = V_144 ;
}
F_75 ( V_94 , V_131 ) ;
}
static void F_79 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
unsigned long V_73 ;
F_37 ( & V_96 -> V_100 , V_73 ) ;
if ( ! V_94 -> V_101 ) {
F_33 ( & V_94 -> V_102 , & V_96 -> V_102 ) ;
V_94 -> V_101 = true ;
}
F_38 ( & V_96 -> V_100 , V_73 ) ;
}
void F_80 ( struct V_121 * V_122 )
{
struct V_95 * V_96 = F_40 ( V_122 , struct V_95 ,
V_149 ) ;
F_81 ( V_150 ) ;
struct V_93 * V_94 , * V_151 ;
F_32 ( & V_96 -> V_152 ) ;
F_82 ( & V_96 -> V_150 , & V_150 ) ;
F_34 ( & V_96 -> V_152 ) ;
F_83 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_52 ( & V_94 -> V_153 ) ;
F_84 ( & V_96 -> V_154 ) ;
F_35 ( L_38
L_39 , V_94 -> V_86 -> V_72 () , V_94 ,
( V_94 -> V_106 == V_155 ) ? L_40 :
( V_94 -> V_106 == V_156 ) ? L_41
: L_42 ) ;
if ( V_94 -> V_106 == V_156 )
F_85 ( V_94 ) ;
else if ( V_94 -> V_106 == V_155 )
F_86 ( V_94 ) ;
}
}
unsigned char * F_87 ( struct V_93 * V_94 )
{
switch ( V_94 -> V_157 ) {
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
void F_88 (
struct V_95 * V_96 ,
char * V_162 ,
int * V_163 )
{
* V_163 += sprintf ( V_162 + * V_163 , L_47 ) ;
if ( V_96 -> V_164 )
* V_163 += sprintf ( V_162 + * V_163 , L_48 ) ;
else
* V_163 += sprintf ( V_162 + * V_163 , L_49 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_50 , V_96 -> V_165 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_51 ,
V_96 -> V_166 . V_167 ,
V_96 -> V_166 . V_168 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_52 ) ;
}
void F_89 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_78 ;
memset ( V_60 , 0 , V_173 ) ;
V_78 = sprintf ( V_60 , L_53 ) ;
switch ( V_170 -> V_174 ) {
case 0x00 :
sprintf ( V_60 + V_78 , L_54 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_78 , L_55 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_78 , L_56 ) ;
break;
case 0x30 :
sprintf ( V_60 + V_78 , L_57 ) ;
break;
case 0x40 :
sprintf ( V_60 + V_78 , L_58
L_59 ) ;
break;
case 0x50 :
sprintf ( V_60 + V_78 , L_60 ) ;
break;
case 0x60 :
sprintf ( V_60 + V_78 , L_61 ) ;
break;
case 0x70 :
sprintf ( V_60 + V_78 , L_62
L_59 ) ;
break;
case 0x80 :
sprintf ( V_60 + V_78 , L_63 ) ;
break;
default:
sprintf ( V_60 + V_78 , L_64 ,
V_170 -> V_174 ) ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_35 ( L_65 , V_60 ) ;
}
void
F_90 ( struct V_169 * V_170 , unsigned char * V_175 )
{
if ( V_175 [ 1 ] & 0x80 ) {
V_170 -> V_174 = ( V_175 [ 0 ] & 0xf0 ) ;
V_170 -> V_176 = 1 ;
F_89 ( V_170 , NULL , 0 ) ;
}
}
int F_91 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_78 ;
memset ( V_60 , 0 , V_173 ) ;
V_78 = sprintf ( V_60 , L_66 ) ;
switch ( V_170 -> V_177 ) {
case 0x00 :
sprintf ( V_60 + V_78 , L_67 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_78 , L_68 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_78 , L_69 ) ;
break;
default:
sprintf ( V_60 + V_78 , L_64 , V_170 -> V_177 ) ;
V_33 = - V_178 ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_35 ( L_65 , V_60 ) ;
return V_33 ;
}
int F_92 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_177 = ( V_175 [ 1 ] & 0x30 ) ;
return F_91 ( V_170 , NULL , 0 ) ;
}
int F_93 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_78 ;
memset ( V_60 , 0 , V_173 ) ;
V_78 = sprintf ( V_60 , L_70 ) ;
switch ( V_170 -> V_179 ) {
case 0x00 :
sprintf ( V_60 + V_78 , L_71 ) ;
break;
case 0x01 :
sprintf ( V_60 + V_78 , L_72 ) ;
break;
case 0x02 :
sprintf ( V_60 + V_78 , L_73 ) ;
break;
case 0x03 :
sprintf ( V_60 + V_78 , L_74 ) ;
break;
case 0x04 :
sprintf ( V_60 + V_78 , L_75 ) ;
break;
case 0x08 :
sprintf ( V_60 + V_78 , L_76 ) ;
break;
default:
sprintf ( V_60 + V_78 , L_77 ,
V_170 -> V_179 ) ;
V_33 = - V_178 ;
break;
}
if ( V_171 ) {
if ( V_172 < strlen ( V_60 ) + 1 )
return - V_178 ;
strncpy ( V_171 , V_60 , V_172 ) ;
} else {
F_35 ( L_65 , V_60 ) ;
}
return V_33 ;
}
int F_94 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_179 = ( V_175 [ 1 ] & 0x0f ) ;
return F_93 ( V_170 , NULL , 0 ) ;
}
int F_95 (
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
F_35 ( L_65 , V_60 ) ;
return V_33 ;
}
int
F_96 ( struct V_169 * V_170 , unsigned char * V_175 )
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
return F_95 ( V_170 , NULL , 0 ) ;
}
static T_5
F_97 ( struct V_93 * V_94 , struct V_95 * V_96 ,
unsigned int V_185 )
{
T_1 V_186 ;
if ( ! V_94 -> V_86 -> V_187 )
return V_188 ;
V_186 = ( V_94 -> V_86 -> V_187 * V_81 ) ;
if ( V_94 -> V_146 > V_186 ) {
if ( V_94 -> V_118 & V_189 ) {
V_94 -> V_148 = ( V_185 - V_186 ) ;
} else if ( V_94 -> V_118 & V_147 ) {
T_1 V_190 = V_185 + V_94 -> V_148 ;
V_94 -> V_148 = ( V_190 - V_186 ) ;
} else {
V_94 -> V_118 |= V_147 ;
V_94 -> V_148 = ( V_94 -> V_146 - V_186 ) ;
}
V_94 -> V_146 = V_186 ;
if ( V_94 -> V_191 ) {
T_1 V_192 = ( V_186 / V_96 -> V_166 . V_167 ) ;
V_94 -> V_191 = V_96 -> V_191 * V_192 ;
}
}
return V_188 ;
}
T_5
F_98 ( struct V_93 * V_94 , unsigned int V_185 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
if ( V_94 -> V_193 ) {
V_94 -> V_146 = V_185 ;
} else if ( V_185 != V_94 -> V_146 ) {
F_99 ( L_84
L_85
L_86 , V_94 -> V_86 -> V_72 () ,
V_94 -> V_146 , V_185 , V_94 -> V_194 [ 0 ] ) ;
if ( V_94 -> V_157 == V_160 &&
V_94 -> V_118 & V_195 ) {
F_4 ( L_87 ) ;
return V_196 ;
}
if ( V_96 -> V_166 . V_167 != 512 ) {
F_4 ( L_88
L_89
L_90 , V_96 -> V_129 -> V_130 ) ;
return V_196 ;
}
if ( V_185 > V_94 -> V_146 ) {
V_94 -> V_118 |= V_189 ;
V_94 -> V_148 = ( V_185 - V_94 -> V_146 ) ;
} else {
V_94 -> V_118 |= V_147 ;
V_94 -> V_148 = ( V_94 -> V_146 - V_185 ) ;
V_94 -> V_146 = V_185 ;
}
}
return F_97 ( V_94 , V_96 , V_185 ) ;
}
void F_100 (
struct V_93 * V_94 ,
const struct V_57 * V_58 ,
struct V_2 * V_37 ,
T_1 V_146 ,
int V_157 ,
int V_197 ,
unsigned char * V_132 )
{
F_18 ( & V_94 -> V_198 ) ;
F_18 ( & V_94 -> V_153 ) ;
F_18 ( & V_94 -> V_199 ) ;
F_18 ( & V_94 -> V_102 ) ;
F_101 ( & V_94 -> V_112 ) ;
F_101 ( & V_94 -> V_200 ) ;
F_101 ( & V_94 -> V_139 ) ;
F_19 ( & V_94 -> V_105 ) ;
F_20 ( & V_94 -> V_201 ) ;
V_94 -> V_98 = V_202 ;
V_94 -> V_86 = V_58 ;
V_94 -> V_37 = V_37 ;
V_94 -> V_146 = V_146 ;
V_94 -> V_157 = V_157 ;
V_94 -> V_203 = V_197 ;
V_94 -> V_132 = V_132 ;
V_94 -> V_101 = false ;
}
static T_5
F_102 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
if ( V_96 -> V_129 -> V_204 & V_205 )
return 0 ;
if ( V_94 -> V_203 == V_206 ) {
F_35 ( L_91
L_92 ) ;
return V_196 ;
}
return 0 ;
}
T_5
F_103 ( struct V_93 * V_94 , unsigned char * V_207 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
T_5 V_33 ;
if ( F_104 ( V_207 ) > V_208 ) {
F_4 ( L_93
L_94 ,
F_104 ( V_207 ) , V_208 ) ;
return V_196 ;
}
if ( F_104 ( V_207 ) > sizeof( V_94 -> V_209 ) ) {
V_94 -> V_194 = F_22 ( F_104 ( V_207 ) ,
V_38 ) ;
if ( ! V_94 -> V_194 ) {
F_4 ( L_95
L_96 ,
F_104 ( V_207 ) ,
( unsigned long ) sizeof( V_94 -> V_209 ) ) ;
return V_210 ;
}
} else
V_94 -> V_194 = & V_94 -> V_209 [ 0 ] ;
memcpy ( V_94 -> V_194 , V_207 , F_104 ( V_207 ) ) ;
F_105 ( V_94 ) ;
V_33 = F_106 ( V_94 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_107 ( V_94 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_108 ( V_94 ) ;
if ( V_33 ) {
V_94 -> V_131 = V_211 ;
return V_33 ;
}
V_33 = V_96 -> V_129 -> V_212 ( V_94 ) ;
if ( V_33 == V_213 )
F_109 ( L_97 ,
V_94 -> V_86 -> V_72 () ,
V_94 -> V_37 -> V_54 -> V_80 ,
V_94 -> V_194 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_102 ( V_94 ) ;
if ( V_33 )
return V_33 ;
V_94 -> V_118 |= V_214 ;
F_110 ( & V_94 -> V_108 -> V_215 . V_216 ) ;
return 0 ;
}
int F_111 (
struct V_93 * V_94 )
{
T_5 V_33 ;
if ( ! V_94 -> V_108 ) {
F_112 () ;
F_4 ( L_98 ) ;
return - V_178 ;
}
if ( F_113 () ) {
F_112 () ;
F_4 ( L_99
L_100 ) ;
return - V_178 ;
}
V_94 -> V_106 = V_217 ;
V_94 -> V_98 |= V_113 ;
V_33 = F_114 ( V_94 ) ;
if ( V_33 )
F_72 ( V_94 , V_33 ) ;
return 0 ;
}
T_5
F_115 ( struct V_93 * V_94 , struct V_218 * V_219 ,
T_1 V_220 , struct V_218 * V_221 , T_1 V_222 )
{
if ( ! V_219 || ! V_220 )
return 0 ;
if ( V_94 -> V_118 & V_189 ) {
F_99 ( L_101
L_102 ) ;
return V_196 ;
}
V_94 -> V_136 = V_219 ;
V_94 -> V_223 = V_220 ;
V_94 -> V_224 = V_221 ;
V_94 -> V_225 = V_222 ;
V_94 -> V_118 |= V_226 ;
return 0 ;
}
int F_116 ( struct V_93 * V_93 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_227 , T_6 V_228 ,
T_1 V_146 , int V_197 , int V_229 , int V_73 ,
struct V_218 * V_219 , T_1 V_220 ,
struct V_218 * V_221 , T_1 V_222 ,
struct V_218 * V_230 , T_1 V_231 )
{
struct V_52 * V_53 ;
T_5 V_47 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_10 ( V_93 -> V_86 || V_93 -> V_37 ) ;
F_10 ( F_113 () ) ;
F_100 ( V_93 , V_53 -> V_59 , V_37 ,
V_146 , V_229 , V_197 , V_227 ) ;
if ( V_73 & V_232 )
V_93 -> V_193 = 1 ;
V_33 = F_117 ( V_93 , V_73 & V_233 ) ;
if ( V_33 )
return V_33 ;
if ( V_73 & V_234 )
V_93 -> V_118 |= V_235 ;
V_47 = F_118 ( V_93 , V_228 ) ;
if ( V_47 ) {
F_119 ( V_93 , V_47 , 0 ) ;
F_120 ( V_93 ) ;
return 0 ;
}
V_47 = F_103 ( V_93 , V_207 ) ;
if ( V_47 != 0 ) {
F_72 ( V_93 , V_47 ) ;
return 0 ;
}
if ( V_231 ) {
V_93 -> V_236 = V_230 ;
V_93 -> V_237 = V_231 ;
V_93 -> V_118 |= V_238 ;
}
if ( V_220 != 0 ) {
F_10 ( ! V_219 ) ;
if ( ! ( V_93 -> V_118 & V_195 ) &&
V_93 -> V_157 == V_159 ) {
unsigned char * V_60 = NULL ;
if ( V_219 )
V_60 = F_121 ( F_122 ( V_219 ) ) + V_219 -> V_239 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_219 -> V_144 ) ;
F_123 ( F_122 ( V_219 ) ) ;
}
}
V_47 = F_115 ( V_93 , V_219 , V_220 ,
V_221 , V_222 ) ;
if ( V_47 != 0 ) {
F_72 ( V_93 , V_47 ) ;
return 0 ;
}
}
F_124 ( V_93 ) ;
F_111 ( V_93 ) ;
return 0 ;
}
int F_125 ( struct V_93 * V_93 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_227 , T_6 V_228 ,
T_1 V_146 , int V_197 , int V_229 , int V_73 )
{
return F_116 ( V_93 , V_37 , V_207 , V_227 ,
V_228 , V_146 , V_197 , V_229 ,
V_73 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_126 ( struct V_121 * V_122 )
{
struct V_93 * V_93 = F_40 ( V_122 , struct V_93 , V_122 ) ;
V_93 -> V_240 -> V_241 = V_242 ;
V_93 -> V_86 -> V_243 ( V_93 ) ;
F_65 ( V_93 ) ;
}
int F_127 ( struct V_93 * V_93 , struct V_2 * V_37 ,
unsigned char * V_227 , T_6 V_228 ,
void * V_244 , unsigned char V_245 ,
T_7 V_246 , unsigned int V_111 , int V_73 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_100 ( V_93 , V_53 -> V_59 , V_37 ,
0 , V_158 , V_247 , V_227 ) ;
V_33 = F_128 ( V_93 , V_244 , V_245 , V_246 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_245 == V_248 )
V_93 -> V_240 -> V_249 = V_111 ;
V_33 = F_117 ( V_93 , V_73 & V_233 ) ;
if ( V_33 ) {
F_129 ( V_93 -> V_240 ) ;
return V_33 ;
}
V_33 = F_130 ( V_93 , V_228 ) ;
if ( V_33 ) {
F_76 ( & V_93 -> V_122 , F_126 ) ;
F_131 ( & V_93 -> V_122 ) ;
return 0 ;
}
F_132 ( V_93 ) ;
return 0 ;
}
bool F_133 ( struct V_93 * V_94 , unsigned long * V_73 )
__releases( &cmd->t_state_lock
void F_72 ( struct V_93 * V_94 ,
T_5 V_250 )
{
int V_33 = 0 ;
F_35 ( L_103
L_104 , V_94 , V_94 -> V_111 , V_94 -> V_194 [ 0 ] ) ;
F_35 ( L_105 ,
V_94 -> V_86 -> V_251 ( V_94 ) ,
V_94 -> V_106 , V_250 ) ;
F_35 ( L_106 ,
( V_94 -> V_98 & V_113 ) != 0 ,
( V_94 -> V_98 & V_109 ) != 0 ,
( V_94 -> V_98 & V_252 ) != 0 ) ;
F_134 ( V_94 ) ;
if ( ( V_94 -> V_118 & V_253 ) &&
V_94 -> V_254 )
V_94 -> V_254 ( V_94 , false ) ;
switch ( V_250 ) {
case V_255 :
case V_213 :
case V_196 :
case V_256 :
case V_257 :
case V_123 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
break;
case V_210 :
V_250 = V_123 ;
break;
case V_267 :
V_94 -> V_131 = V_211 ;
if ( V_94 -> V_37 &&
V_94 -> V_97 -> V_166 . V_268 == 2 ) {
F_135 ( V_94 -> V_37 -> V_54 ,
V_94 -> V_269 , 0x2C ,
V_270 ) ;
}
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_271 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
goto V_274;
default:
F_4 ( L_107 ,
V_94 -> V_194 [ 0 ] , V_250 ) ;
V_250 = V_213 ;
break;
}
V_33 = F_119 ( V_94 , V_250 , 0 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
V_274:
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
return;
V_273:
V_94 -> V_106 = V_155 ;
F_137 ( V_94 , V_94 -> V_97 ) ;
}
void F_138 ( struct V_93 * V_94 )
{
T_5 V_33 ;
if ( V_94 -> V_275 ) {
V_33 = V_94 -> V_275 ( V_94 ) ;
if ( V_33 ) {
F_32 ( & V_94 -> V_105 ) ;
V_94 -> V_98 &= ~ ( V_99 | V_252 ) ;
F_34 ( & V_94 -> V_105 ) ;
F_72 ( V_94 , V_33 ) ;
}
}
}
static int F_139 ( struct V_93 * V_94 )
{
T_1 V_192 ;
switch ( V_94 -> V_276 ) {
case V_277 :
if ( ! ( V_94 -> V_37 -> V_36 & V_277 ) )
F_140 ( V_94 ) ;
break;
case V_278 :
if ( V_94 -> V_37 -> V_36 & V_278 )
break;
V_192 = V_94 -> V_146 >> F_141 ( V_94 -> V_97 -> V_166 . V_167 ) ;
V_94 -> V_279 = F_142 ( V_94 , V_94 -> V_280 ,
V_192 , 0 , V_94 -> V_236 , 0 ) ;
if ( F_143 ( V_94 -> V_279 ) ) {
F_32 ( & V_94 -> V_105 ) ;
V_94 -> V_98 &= ~ ( V_99 | V_252 ) ;
F_34 ( & V_94 -> V_105 ) ;
F_72 ( V_94 , V_94 -> V_279 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_144 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
if ( V_96 -> V_129 -> V_204 & V_205 )
return false ;
switch ( V_94 -> V_203 ) {
case V_281 :
F_35 ( L_108 ,
V_94 -> V_194 [ 0 ] ) ;
return false ;
case V_282 :
F_145 ( & V_96 -> V_283 ) ;
F_35 ( L_109 ,
V_94 -> V_194 [ 0 ] ) ;
if ( ! F_146 ( & V_96 -> V_284 ) )
return false ;
break;
default:
F_145 ( & V_96 -> V_284 ) ;
break;
}
if ( F_146 ( & V_96 -> V_283 ) == 0 )
return false ;
F_11 ( & V_96 -> V_285 ) ;
F_33 ( & V_94 -> V_198 , & V_96 -> V_286 ) ;
F_12 ( & V_96 -> V_285 ) ;
F_35 ( L_110 ,
V_94 -> V_194 [ 0 ] , V_94 -> V_203 ) ;
return true ;
}
void F_147 ( struct V_93 * V_94 )
{
if ( F_148 ( V_94 , 1 ) )
return;
F_32 ( & V_94 -> V_105 ) ;
if ( V_94 -> V_98 & V_109 ) {
F_35 ( L_36 ,
V_110 , __LINE__ , V_94 -> V_111 ) ;
F_34 ( & V_94 -> V_105 ) ;
F_64 ( & V_94 -> V_112 ) ;
return;
}
V_94 -> V_106 = V_287 ;
V_94 -> V_98 |= V_113 | V_99 | V_252 ;
F_34 ( & V_94 -> V_105 ) ;
if ( F_139 ( V_94 ) )
return;
if ( F_144 ( V_94 ) ) {
F_32 ( & V_94 -> V_105 ) ;
V_94 -> V_98 &= ~ ( V_99 | V_252 ) ;
F_34 ( & V_94 -> V_105 ) ;
return;
}
F_138 ( V_94 ) ;
}
static void F_149 ( struct V_95 * V_96 )
{
for (; ; ) {
struct V_93 * V_94 ;
F_11 ( & V_96 -> V_285 ) ;
if ( F_53 ( & V_96 -> V_286 ) ) {
F_12 ( & V_96 -> V_285 ) ;
break;
}
V_94 = F_150 ( V_96 -> V_286 . V_288 ,
struct V_93 , V_198 ) ;
F_52 ( & V_94 -> V_198 ) ;
F_12 ( & V_96 -> V_285 ) ;
F_138 ( V_94 ) ;
if ( V_94 -> V_203 == V_282 )
break;
}
}
static void F_134 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
if ( V_96 -> V_129 -> V_204 & V_205 )
return;
if ( V_94 -> V_203 == V_247 ) {
F_84 ( & V_96 -> V_284 ) ;
V_96 -> V_289 ++ ;
F_35 ( L_111 ,
V_96 -> V_289 ) ;
} else if ( V_94 -> V_203 == V_281 ) {
V_96 -> V_289 ++ ;
F_35 ( L_112 ,
V_96 -> V_289 ) ;
} else if ( V_94 -> V_203 == V_282 ) {
F_84 ( & V_96 -> V_283 ) ;
V_96 -> V_289 ++ ;
F_35 ( L_113 ,
V_96 -> V_289 ) ;
}
F_149 ( V_96 ) ;
}
static void F_86 ( struct V_93 * V_94 )
{
int V_33 = 0 ;
F_134 ( V_94 ) ;
if ( V_94 -> V_118 & V_137 ) {
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_271 ( V_94 ) ;
goto V_3;
}
switch ( V_94 -> V_157 ) {
case V_159 :
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_290 ( V_94 ) ;
break;
case V_160 :
if ( V_94 -> V_118 & V_235 ) {
V_33 = V_94 -> V_86 -> V_290 ( V_94 ) ;
break;
}
case V_158 :
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_271 ( V_94 ) ;
break;
default:
break;
}
V_3:
if ( V_33 < 0 ) {
F_137 ( V_94 , V_94 -> V_97 ) ;
return;
}
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
}
static void F_137 (
struct V_93 * V_94 ,
struct V_95 * V_96 )
{
F_32 ( & V_96 -> V_152 ) ;
F_33 ( & V_94 -> V_153 , & V_94 -> V_97 -> V_150 ) ;
F_145 ( & V_96 -> V_154 ) ;
F_34 ( & V_94 -> V_97 -> V_152 ) ;
F_131 ( & V_94 -> V_97 -> V_149 ) ;
}
static bool F_151 ( struct V_93 * V_94 )
{
switch ( V_94 -> V_276 ) {
case V_291 :
if ( ! ( V_94 -> V_37 -> V_36 & V_291 ) ) {
T_1 V_192 = V_94 -> V_146 >>
F_141 ( V_94 -> V_97 -> V_166 . V_167 ) ;
V_94 -> V_279 = F_142 ( V_94 , V_94 -> V_280 ,
V_192 , 0 , V_94 -> V_236 ,
0 ) ;
if ( V_94 -> V_279 )
return true ;
}
break;
case V_292 :
if ( V_94 -> V_37 -> V_36 & V_292 )
break;
F_140 ( V_94 ) ;
break;
default:
break;
}
return false ;
}
static void V_141 ( struct V_121 * V_122 )
{
struct V_93 * V_94 = F_40 ( V_122 , struct V_93 , V_122 ) ;
int V_33 ;
F_134 ( V_94 ) ;
if ( F_146 ( & V_94 -> V_97 -> V_154 ) != 0 )
F_131 ( & V_94 -> V_97 -> V_149 ) ;
if ( V_94 -> V_118 & V_137 ) {
F_74 ( ! V_94 -> V_131 ) ;
V_33 = F_119 (
V_94 , 0 , 1 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
return;
}
if ( V_94 -> V_254 ) {
T_5 V_47 ;
V_47 = V_94 -> V_254 ( V_94 , true ) ;
if ( ! V_47 && ! ( V_94 -> V_118 & V_293 ) ) {
if ( ( V_94 -> V_118 & V_253 ) &&
! V_94 -> V_146 )
goto V_294;
return;
} else if ( V_47 ) {
V_33 = F_119 ( V_94 ,
V_47 , 0 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
return;
}
}
V_294:
switch ( V_94 -> V_157 ) {
case V_159 :
F_152 ( V_94 -> V_146 ,
& V_94 -> V_108 -> V_215 . V_295 ) ;
if ( F_151 ( V_94 ) ) {
V_33 = F_119 ( V_94 ,
V_94 -> V_279 , 0 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
return;
}
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_290 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
break;
case V_160 :
F_152 ( V_94 -> V_146 ,
& V_94 -> V_108 -> V_215 . V_296 ) ;
if ( V_94 -> V_118 & V_235 ) {
F_152 ( V_94 -> V_146 ,
& V_94 -> V_108 -> V_215 . V_295 ) ;
V_33 = V_94 -> V_86 -> V_290 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
break;
}
case V_158 :
F_136 ( V_94 ) ;
V_33 = V_94 -> V_86 -> V_271 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
break;
default:
break;
}
F_66 ( V_94 ) ;
F_65 ( V_94 ) ;
return;
V_273:
F_35 ( L_114
L_115 , V_94 , V_94 -> V_157 ) ;
V_94 -> V_106 = V_155 ;
F_137 ( V_94 , V_94 -> V_97 ) ;
}
static inline void F_153 ( struct V_218 * V_219 , int V_297 )
{
struct V_218 * V_298 ;
int V_299 ;
F_154 (sgl, sg, nents, count)
F_155 ( F_122 ( V_298 ) ) ;
F_61 ( V_219 ) ;
}
static inline void F_156 ( struct V_93 * V_94 )
{
if ( ! V_94 -> V_300 )
return;
F_61 ( V_94 -> V_136 ) ;
V_94 -> V_136 = V_94 -> V_300 ;
V_94 -> V_300 = NULL ;
V_94 -> V_223 = V_94 -> V_301 ;
V_94 -> V_301 = 0 ;
}
static inline void F_157 ( struct V_93 * V_94 )
{
if ( ! ( V_94 -> V_118 & V_238 ) ) {
F_153 ( V_94 -> V_236 , V_94 -> V_237 ) ;
V_94 -> V_236 = NULL ;
V_94 -> V_237 = 0 ;
}
if ( V_94 -> V_118 & V_226 ) {
if ( V_94 -> V_118 & V_253 ) {
F_153 ( V_94 -> V_224 ,
V_94 -> V_225 ) ;
V_94 -> V_224 = NULL ;
V_94 -> V_225 = 0 ;
}
F_156 ( V_94 ) ;
return;
}
F_156 ( V_94 ) ;
F_153 ( V_94 -> V_136 , V_94 -> V_223 ) ;
V_94 -> V_136 = NULL ;
V_94 -> V_223 = 0 ;
F_153 ( V_94 -> V_224 , V_94 -> V_225 ) ;
V_94 -> V_224 = NULL ;
V_94 -> V_225 = 0 ;
}
static int F_158 ( struct V_93 * V_94 )
{
F_10 ( ! V_94 -> V_86 ) ;
if ( V_94 -> V_118 & V_302 )
F_129 ( V_94 -> V_240 ) ;
if ( V_94 -> V_194 != V_94 -> V_209 )
F_61 ( V_94 -> V_194 ) ;
return F_120 ( V_94 ) ;
}
static int F_70 ( struct V_93 * V_94 )
{
F_157 ( V_94 ) ;
return F_158 ( V_94 ) ;
}
void * F_159 ( struct V_93 * V_94 )
{
struct V_218 * V_298 = V_94 -> V_136 ;
struct V_77 * * V_303 ;
int V_184 ;
if ( ! V_94 -> V_223 )
return NULL ;
F_10 ( ! V_298 ) ;
if ( V_94 -> V_223 == 1 )
return F_121 ( F_122 ( V_298 ) ) + V_298 -> V_239 ;
V_303 = F_160 ( sizeof( * V_303 ) * V_94 -> V_223 , V_38 ) ;
if ( ! V_303 )
return NULL ;
F_154 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_303 [ V_184 ] = F_122 ( V_298 ) ;
}
V_94 -> V_304 = F_161 ( V_303 , V_94 -> V_223 , V_305 , V_306 ) ;
F_61 ( V_303 ) ;
if ( ! V_94 -> V_304 )
return NULL ;
return V_94 -> V_304 + V_94 -> V_136 [ 0 ] . V_239 ;
}
void F_162 ( struct V_93 * V_94 )
{
if ( ! V_94 -> V_223 ) {
return;
} else if ( V_94 -> V_223 == 1 ) {
F_123 ( F_122 ( V_94 -> V_136 ) ) ;
return;
}
F_163 ( V_94 -> V_304 ) ;
V_94 -> V_304 = NULL ;
}
int
F_164 ( struct V_218 * * V_219 , unsigned int * V_297 , T_1 V_144 ,
bool V_307 )
{
struct V_218 * V_298 ;
struct V_77 * V_77 ;
T_7 V_308 = ( V_307 ) ? V_309 : 0 ;
unsigned int V_310 ;
int V_184 = 0 ;
V_310 = F_165 ( V_144 , V_81 ) ;
V_298 = F_160 ( sizeof( struct V_218 ) * V_310 , V_38 ) ;
if ( ! V_298 )
return - V_28 ;
F_166 ( V_298 , V_310 ) ;
while ( V_144 ) {
T_1 V_311 = F_167 ( T_1 , V_144 , V_81 ) ;
V_77 = F_168 ( V_38 | V_308 ) ;
if ( ! V_77 )
goto V_3;
F_169 ( & V_298 [ V_184 ] , V_77 , V_311 , 0 ) ;
V_144 -= V_311 ;
V_184 ++ ;
}
* V_219 = V_298 ;
* V_297 = V_310 ;
return 0 ;
V_3:
while ( V_184 > 0 ) {
V_184 -- ;
F_155 ( F_122 ( & V_298 [ V_184 ] ) ) ;
}
F_61 ( V_298 ) ;
return - V_28 ;
}
T_5
F_114 ( struct V_93 * V_94 )
{
int V_33 = 0 ;
bool V_308 = ! ( V_94 -> V_118 & V_195 ) ;
if ( V_94 -> V_276 != V_312 &&
! ( V_94 -> V_118 & V_238 ) ) {
V_33 = F_164 ( & V_94 -> V_236 , & V_94 -> V_237 ,
V_94 -> V_191 , true ) ;
if ( V_33 < 0 )
return V_123 ;
}
if ( ! ( V_94 -> V_118 & V_226 ) &&
V_94 -> V_146 ) {
if ( ( V_94 -> V_118 & V_235 ) ||
( V_94 -> V_118 & V_253 ) ) {
T_1 V_313 ;
if ( V_94 -> V_118 & V_253 )
V_313 = V_94 -> V_314 *
V_94 -> V_97 -> V_166 . V_167 ;
else
V_313 = V_94 -> V_146 ;
V_33 = F_164 ( & V_94 -> V_224 ,
& V_94 -> V_225 ,
V_313 , V_308 ) ;
if ( V_33 < 0 )
return V_123 ;
}
V_33 = F_164 ( & V_94 -> V_136 , & V_94 -> V_223 ,
V_94 -> V_146 , V_308 ) ;
if ( V_33 < 0 )
return V_123 ;
} else if ( ( V_94 -> V_118 & V_253 ) &&
V_94 -> V_146 ) {
T_1 V_315 = V_94 -> V_314 *
V_94 -> V_97 -> V_166 . V_167 ;
V_33 = F_164 ( & V_94 -> V_224 ,
& V_94 -> V_225 ,
V_315 , V_308 ) ;
if ( V_33 < 0 )
return V_123 ;
}
F_79 ( V_94 ) ;
if ( V_94 -> V_157 != V_160 || V_94 -> V_146 == 0 ) {
F_147 ( V_94 ) ;
return 0 ;
}
F_63 ( V_94 , false , true ) ;
V_33 = V_94 -> V_86 -> V_104 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 )
goto V_273;
F_74 ( V_33 ) ;
return ( ! V_33 ) ? 0 : V_123 ;
V_273:
F_35 ( L_116 , V_94 ) ;
V_94 -> V_106 = V_156 ;
F_137 ( V_94 , V_94 -> V_97 ) ;
return 0 ;
}
static void F_85 ( struct V_93 * V_94 )
{
int V_33 ;
V_33 = V_94 -> V_86 -> V_104 ( V_94 ) ;
if ( V_33 == - V_272 || V_33 == - V_28 ) {
F_35 ( L_116 ,
V_94 ) ;
F_137 ( V_94 , V_94 -> V_97 ) ;
}
}
int F_170 ( struct V_93 * V_94 , int V_316 )
{
unsigned long V_73 ;
int V_33 = 0 ;
if ( ! ( V_94 -> V_118 & V_119 ) ) {
if ( V_316 && ( V_94 -> V_118 & V_302 ) )
F_171 ( V_94 ) ;
V_33 = F_158 ( V_94 ) ;
} else {
if ( V_316 )
F_171 ( V_94 ) ;
if ( V_94 -> V_101 ) {
F_37 ( & V_94 -> V_105 , V_73 ) ;
F_62 ( V_94 ) ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
}
if ( V_94 -> V_108 )
F_66 ( V_94 ) ;
V_33 = F_70 ( V_94 ) ;
}
return V_33 ;
}
int F_117 ( struct V_93 * V_93 , bool V_317 )
{
struct V_2 * V_37 = V_93 -> V_37 ;
unsigned long V_73 ;
int V_33 = 0 ;
if ( V_317 )
F_31 ( & V_93 -> V_201 ) ;
F_37 ( & V_37 -> V_43 , V_73 ) ;
if ( V_37 -> V_318 ) {
V_33 = - V_319 ;
goto V_3;
}
F_33 ( & V_93 -> V_199 , & V_37 -> V_41 ) ;
V_3:
F_38 ( & V_37 -> V_43 , V_73 ) ;
if ( V_33 && V_317 )
F_120 ( V_93 ) ;
return V_33 ;
}
static void F_172 ( struct V_75 * V_75 )
__releases( &se_cmd->se_sess->sess_cmd_lock
int F_120 ( struct V_93 * V_93 )
{
struct V_2 * V_37 = V_93 -> V_37 ;
if ( ! V_37 ) {
V_93 -> V_86 -> V_320 ( V_93 ) ;
return 1 ;
}
return F_173 ( & V_93 -> V_201 , F_172 ,
& V_37 -> V_43 ) ;
}
void F_174 ( struct V_2 * V_37 )
{
struct V_93 * V_93 ;
unsigned long V_73 ;
F_37 ( & V_37 -> V_43 , V_73 ) ;
if ( V_37 -> V_318 ) {
F_38 ( & V_37 -> V_43 , V_73 ) ;
return;
}
V_37 -> V_318 = 1 ;
F_82 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_46 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_93 -> V_321 = 1 ;
F_38 ( & V_37 -> V_43 , V_73 ) ;
}
void F_175 ( struct V_2 * V_37 )
{
struct V_93 * V_93 , * V_322 ;
unsigned long V_73 ;
F_83 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_52 ( & V_93 -> V_199 ) ;
F_35 ( L_117
L_118 , V_93 , V_93 -> V_106 ,
V_93 -> V_86 -> V_251 ( V_93 ) ) ;
F_176 ( & V_93 -> V_200 ) ;
F_35 ( L_119
L_120 , V_93 , V_93 -> V_106 ,
V_93 -> V_86 -> V_251 ( V_93 ) ) ;
V_93 -> V_86 -> V_320 ( V_93 ) ;
}
F_37 ( & V_37 -> V_43 , V_73 ) ;
F_74 ( ! F_53 ( & V_37 -> V_41 ) ) ;
F_38 ( & V_37 -> V_43 , V_73 ) ;
}
void F_177 ( struct V_108 * V_115 )
{
F_178 ( & V_115 -> V_117 ) ;
F_176 ( & V_115 -> V_323 ) ;
}
bool F_171 ( struct V_93 * V_94 )
{
unsigned long V_73 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
if ( ! ( V_94 -> V_118 & V_119 ) &&
! ( V_94 -> V_118 & V_302 ) ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return false ;
}
if ( ! ( V_94 -> V_118 & V_214 ) &&
! ( V_94 -> V_118 & V_302 ) ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return false ;
}
if ( ! ( V_94 -> V_98 & V_113 ) ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return false ;
}
V_94 -> V_98 |= V_109 ;
F_35 ( L_121 ,
V_94 , V_94 -> V_111 , V_94 -> V_86 -> V_251 ( V_94 ) , V_94 -> V_106 ) ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_176 ( & V_94 -> V_112 ) ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
V_94 -> V_98 &= ~ ( V_113 | V_109 ) ;
F_35 ( L_122 ,
V_94 -> V_111 ) ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
return true ;
}
static int F_179 ( struct V_93 * V_94 , T_5 V_324 )
{
const struct V_325 * V_326 ;
T_4 * V_327 = V_94 -> V_132 ;
int V_328 = ( V_329 int ) V_324 ;
T_4 V_330 , V_331 ;
bool V_332 = F_180 ( V_94 -> V_97 ) ;
if ( V_328 < F_181 ( V_333 ) && V_333 [ V_328 ] . V_334 )
V_326 = & V_333 [ V_328 ] ;
else
V_326 = & V_333 [ ( V_329 int )
V_123 ] ;
if ( V_324 == V_262 ) {
F_182 ( V_94 , & V_330 , & V_331 ) ;
F_183 ( V_330 == 0 ) ;
} else if ( V_326 -> V_330 == 0 ) {
F_183 ( V_94 -> V_335 == 0 ) ;
V_330 = V_94 -> V_335 ;
V_331 = V_94 -> V_336 ;
} else {
V_330 = V_326 -> V_330 ;
V_331 = V_326 -> V_331 ;
}
F_184 ( V_332 , V_327 , V_326 -> V_334 , V_330 , V_331 ) ;
if ( V_326 -> V_337 )
return F_185 ( V_327 ,
V_94 -> V_125 ,
V_94 -> V_338 ) ;
return 0 ;
}
int
F_119 ( struct V_93 * V_94 ,
T_5 V_324 , int V_339 )
{
unsigned long V_73 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
if ( V_94 -> V_118 & V_124 ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return 0 ;
}
V_94 -> V_118 |= V_124 ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
if ( ! V_339 ) {
int V_47 ;
V_94 -> V_118 |= V_340 ;
V_94 -> V_131 = V_341 ;
V_94 -> V_125 = V_126 ;
V_47 = F_179 ( V_94 , V_324 ) ;
if ( V_47 )
return V_47 ;
}
F_136 ( V_94 ) ;
return V_94 -> V_86 -> V_271 ( V_94 ) ;
}
int F_148 ( struct V_93 * V_94 , int V_342 )
{
if ( ! ( V_94 -> V_98 & V_140 ) )
return 0 ;
if ( ! V_342 || ! ( V_94 -> V_118 & V_343 ) )
return 1 ;
F_35 ( L_123 ,
V_94 -> V_194 [ 0 ] , V_94 -> V_111 ) ;
V_94 -> V_118 &= ~ V_343 ;
V_94 -> V_131 = V_344 ;
F_136 ( V_94 ) ;
V_94 -> V_86 -> V_271 ( V_94 ) ;
return 1 ;
}
void F_186 ( struct V_93 * V_94 )
{
unsigned long V_73 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
if ( V_94 -> V_118 & ( V_124 ) ) {
F_38 ( & V_94 -> V_105 , V_73 ) ;
return;
}
F_38 ( & V_94 -> V_105 , V_73 ) ;
if ( V_94 -> V_157 == V_160 ) {
if ( V_94 -> V_86 -> V_345 ( V_94 ) != 0 ) {
V_94 -> V_98 |= V_140 ;
V_94 -> V_118 |= V_343 ;
return;
}
}
V_94 -> V_131 = V_344 ;
F_66 ( V_94 ) ;
F_35 ( L_124 ,
V_94 -> V_194 [ 0 ] , V_94 -> V_111 ) ;
F_136 ( V_94 ) ;
V_94 -> V_86 -> V_271 ( V_94 ) ;
}
static void F_187 ( struct V_121 * V_122 )
{
struct V_93 * V_94 = F_40 ( V_122 , struct V_93 , V_122 ) ;
struct V_95 * V_96 = V_94 -> V_97 ;
struct V_240 * V_346 = V_94 -> V_240 ;
int V_33 ;
switch ( V_346 -> V_347 ) {
case V_248 :
F_188 ( V_96 , V_346 , V_94 -> V_37 ) ;
break;
case V_348 :
case V_349 :
case V_350 :
V_346 -> V_241 = V_351 ;
break;
case V_352 :
V_33 = F_189 ( V_96 , V_346 , NULL , NULL ) ;
V_346 -> V_241 = ( ! V_33 ) ? V_353 :
V_354 ;
if ( V_346 -> V_241 == V_353 ) {
F_135 ( V_94 -> V_37 -> V_54 ,
V_94 -> V_269 , 0x29 ,
V_355 ) ;
}
break;
case V_356 :
V_346 -> V_241 = V_354 ;
break;
case V_357 :
V_346 -> V_241 = V_354 ;
break;
default:
F_4 ( L_125 ,
V_346 -> V_347 ) ;
V_346 -> V_241 = V_354 ;
break;
}
V_94 -> V_106 = V_358 ;
V_94 -> V_86 -> V_243 ( V_94 ) ;
F_65 ( V_94 ) ;
}
int F_132 (
struct V_93 * V_94 )
{
unsigned long V_73 ;
F_37 ( & V_94 -> V_105 , V_73 ) ;
V_94 -> V_98 |= V_113 ;
F_38 ( & V_94 -> V_105 , V_73 ) ;
F_76 ( & V_94 -> V_122 , F_187 ) ;
F_77 ( V_94 -> V_97 -> V_359 , & V_94 -> V_122 ) ;
return 0 ;
}
bool
F_190 ( struct V_95 * V_96 )
{
bool V_360 = false ;
if ( V_96 -> V_129 -> V_361 )
V_360 = V_96 -> V_129 -> V_361 ( V_96 ) ;
else if ( V_96 -> V_166 . V_362 > 0 )
V_360 = true ;
return V_360 ;
}
bool
F_191 ( struct V_95 * V_96 )
{
return F_190 ( V_96 ) && V_96 -> V_166 . V_363 > 0 ;
}
