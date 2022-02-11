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
if ( V_45 != 0 && ! V_46 ) {
F_4 ( L_33
L_34 , V_45 ) ;
return F_17 ( - V_52 ) ;
}
if ( ! V_45 && V_46 ) {
F_4 ( L_35
L_36 , V_46 ) ;
return F_17 ( - V_52 ) ;
}
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
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_2 * V_37 ,
void * V_57 )
{
const struct V_58 * V_59 = V_54 -> V_60 ;
unsigned char V_61 [ V_62 ] ;
V_37 -> V_54 = V_54 ;
V_37 -> V_57 = V_57 ;
if ( V_56 ) {
if ( V_56 -> V_63 )
V_37 -> V_64 = V_56 -> V_63 ;
else if ( V_59 -> V_65 )
V_37 -> V_64 = V_56 -> V_63 =
V_59 -> V_65 ( V_54 ) ;
if ( V_54 -> V_60 -> V_66 != NULL ) {
memset ( & V_61 [ 0 ] , 0 , V_62 ) ;
V_54 -> V_60 -> V_66 ( V_37 ,
& V_61 [ 0 ] , V_62 ) ;
V_37 -> V_67 = F_30 ( & V_61 [ 0 ] ) ;
}
F_31 ( & V_56 -> V_68 ) ;
V_56 -> V_69 = V_37 ;
F_32 ( & V_37 -> V_40 ,
& V_56 -> V_70 ) ;
F_33 ( & V_56 -> V_68 ) ;
}
F_32 ( & V_37 -> V_39 , & V_54 -> V_71 ) ;
F_34 ( L_37 ,
V_54 -> V_60 -> V_72 () , V_37 -> V_57 ) ;
}
void F_35 (
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_2 * V_37 ,
void * V_57 )
{
unsigned long V_73 ;
F_36 ( & V_54 -> V_74 , V_73 ) ;
F_29 ( V_54 , V_56 , V_37 , V_57 ) ;
F_37 ( & V_54 -> V_74 , V_73 ) ;
}
struct V_2 *
F_38 ( struct V_53 * V_75 ,
unsigned int V_45 , unsigned int V_46 ,
enum V_35 V_76 ,
const char * V_77 , void * V_78 ,
int (* F_39)( struct V_53 * ,
struct V_2 * , void * ) )
{
struct V_2 * V_79 ;
if ( V_45 != 0 )
V_79 = F_26 ( V_45 , V_46 , V_76 ) ;
else
V_79 = F_15 ( V_76 ) ;
if ( F_27 ( V_79 ) )
return V_79 ;
V_79 -> V_55 = F_40 ( V_75 ,
( unsigned char * ) V_77 ) ;
if ( ! V_79 -> V_55 ) {
F_28 ( V_79 ) ;
return F_17 ( - V_80 ) ;
}
if ( F_39 != NULL ) {
int V_47 = F_39 ( V_75 , V_79 , V_78 ) ;
if ( V_47 ) {
F_28 ( V_79 ) ;
return F_17 ( V_47 ) ;
}
}
F_35 ( V_75 , V_79 -> V_55 , V_79 , V_78 ) ;
return V_79 ;
}
static void F_41 ( struct V_81 * V_81 )
{
struct V_2 * V_37 = F_42 ( V_81 ,
struct V_2 , V_44 ) ;
struct V_53 * V_54 = V_37 -> V_54 ;
V_54 -> V_60 -> V_82 ( V_37 ) ;
}
int F_43 ( struct V_2 * V_37 )
{
return F_44 ( & V_37 -> V_44 ) ;
}
void F_45 ( struct V_2 * V_37 )
{
F_46 ( & V_37 -> V_44 , F_41 ) ;
}
T_3 F_47 ( struct V_53 * V_54 , char * V_83 )
{
struct V_2 * V_37 ;
T_3 V_84 = 0 ;
F_48 ( & V_54 -> V_74 ) ;
F_49 (se_sess, &se_tpg->tpg_sess_list, sess_list) {
if ( ! V_37 -> V_55 )
continue;
if ( ! V_37 -> V_55 -> V_85 )
continue;
if ( strlen ( V_37 -> V_55 -> V_77 ) + 1 + V_84 > V_86 )
break;
V_84 += snprintf ( V_83 + V_84 , V_86 - V_84 , L_38 ,
V_37 -> V_55 -> V_77 ) ;
V_84 += 1 ;
}
F_50 ( & V_54 -> V_74 ) ;
return V_84 ;
}
static void F_51 ( struct V_81 * V_81 )
{
struct V_55 * V_87 = F_42 ( V_81 ,
struct V_55 , V_88 ) ;
F_52 ( & V_87 -> V_89 ) ;
}
void F_53 ( struct V_55 * V_87 )
{
F_46 ( & V_87 -> V_88 , F_51 ) ;
}
void F_54 ( struct V_2 * V_37 )
{
struct V_55 * V_56 ;
unsigned long V_73 ;
V_56 = V_37 -> V_55 ;
if ( V_56 ) {
F_36 ( & V_56 -> V_68 , V_73 ) ;
if ( V_56 -> V_90 == 0 )
F_55 ( & V_37 -> V_40 ) ;
if ( F_56 ( & V_56 -> V_70 ) )
V_56 -> V_69 = NULL ;
else {
V_56 -> V_69 = F_42 (
V_56 -> V_70 . V_91 ,
struct V_2 , V_40 ) ;
}
F_37 ( & V_56 -> V_68 , V_73 ) ;
}
}
void F_28 ( struct V_2 * V_37 )
{
struct V_55 * V_56 = V_37 -> V_55 ;
if ( V_56 ) {
V_37 -> V_55 = NULL ;
F_53 ( V_56 ) ;
}
if ( V_37 -> V_48 ) {
F_57 ( & V_37 -> V_51 ) ;
F_25 ( V_37 -> V_48 ) ;
}
F_58 ( V_1 , V_37 ) ;
}
void F_59 ( struct V_2 * V_37 )
{
struct V_53 * V_54 = V_37 -> V_54 ;
const struct V_58 * V_92 ;
struct V_55 * V_56 ;
unsigned long V_73 ;
bool V_93 = false ;
if ( ! V_54 ) {
F_28 ( V_37 ) ;
return;
}
V_92 = V_54 -> V_60 ;
F_36 ( & V_54 -> V_74 , V_73 ) ;
F_55 ( & V_37 -> V_39 ) ;
V_37 -> V_54 = NULL ;
V_37 -> V_57 = NULL ;
F_37 ( & V_54 -> V_74 , V_73 ) ;
V_56 = V_37 -> V_55 ;
F_60 ( & V_54 -> V_94 ) ;
if ( V_56 && V_56 -> V_85 ) {
if ( ! V_92 -> V_95 ( V_54 ) ) {
F_55 ( & V_56 -> V_96 ) ;
V_93 = true ;
}
}
F_61 ( & V_54 -> V_94 ) ;
if ( V_93 ) {
F_62 ( V_56 ) ;
F_63 ( V_56 , V_54 ) ;
V_37 -> V_55 = NULL ;
F_64 ( V_56 ) ;
}
F_34 ( L_39 ,
V_54 -> V_60 -> V_72 () ) ;
F_28 ( V_37 ) ;
}
static void F_65 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
unsigned long V_73 ;
if ( ! V_100 )
return;
if ( V_98 -> V_102 & V_103 )
return;
F_36 ( & V_100 -> V_104 , V_73 ) ;
if ( V_98 -> V_105 ) {
F_55 ( & V_98 -> V_106 ) ;
V_98 -> V_105 = false ;
}
F_37 ( & V_100 -> V_104 , V_73 ) ;
}
static int F_66 ( struct V_97 * V_98 , bool V_107 ,
bool V_108 )
{
unsigned long V_73 ;
if ( V_107 ) {
F_65 ( V_98 ) ;
V_98 -> V_109 = NULL ;
}
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_108 )
V_98 -> V_111 = V_112 ;
if ( V_98 -> V_102 & V_113 ) {
F_34 ( L_40 ,
V_114 , __LINE__ , V_98 -> V_115 ) ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
F_67 ( & V_98 -> V_116 ) ;
return 1 ;
}
V_98 -> V_102 &= ~ V_117 ;
if ( V_107 ) {
if ( V_98 -> V_92 -> V_118 != NULL ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
return V_98 -> V_92 -> V_118 ( V_98 ) ;
}
}
F_37 ( & V_98 -> V_110 , V_73 ) ;
return 0 ;
}
static int F_68 ( struct V_97 * V_98 )
{
return F_66 ( V_98 , true , false ) ;
}
static void F_69 ( struct V_97 * V_98 )
{
struct V_109 * V_119 = V_98 -> V_109 ;
if ( ! V_119 )
return;
if ( F_70 ( & V_98 -> V_120 , true , false ) )
F_71 ( & V_119 -> V_121 ) ;
}
void F_72 ( struct V_97 * V_98 , int remove )
{
bool V_122 = ( V_98 -> V_123 & V_124 ) ;
if ( V_98 -> V_123 & V_125 )
F_69 ( V_98 ) ;
if ( remove )
V_98 -> V_92 -> V_126 ( V_98 ) ;
if ( F_68 ( V_98 ) )
return;
if ( remove && V_122 )
F_73 ( V_98 ) ;
}
static void F_74 ( struct V_127 * V_128 )
{
struct V_97 * V_98 = F_42 ( V_128 , struct V_97 , V_128 ) ;
F_75 ( V_98 ,
V_129 ) ;
}
static unsigned char * F_76 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
F_77 ( ! V_98 -> V_109 ) ;
if ( ! V_100 )
return NULL ;
if ( V_98 -> V_123 & V_130 )
return NULL ;
V_98 -> V_131 = V_132 ;
F_34 ( L_41 ,
V_100 -> V_133 -> V_134 , V_100 -> V_135 -> V_136 , V_98 -> V_137 ) ;
return V_98 -> V_138 ;
}
void F_78 ( struct V_97 * V_98 , T_4 V_137 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_139 = V_137 == V_140 ;
unsigned long V_73 ;
V_98 -> V_137 = V_137 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
V_98 -> V_102 &= ~ V_103 ;
if ( V_100 && V_100 -> V_135 -> V_141 ) {
V_100 -> V_135 -> V_141 ( V_98 ,
V_98 -> V_142 ,
F_76 ( V_98 ) ) ;
if ( V_98 -> V_123 & V_143 )
V_139 = 1 ;
}
if ( V_98 -> V_102 & V_144 ||
V_98 -> V_102 & V_113 ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
F_67 ( & V_98 -> V_116 ) ;
return;
} else if ( ! V_139 ) {
F_79 ( & V_98 -> V_128 , F_74 ) ;
} else {
F_79 ( & V_98 -> V_128 , V_145 ) ;
}
V_98 -> V_111 = V_146 ;
V_98 -> V_102 |= ( V_147 | V_117 ) ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_123 & V_148 )
F_80 ( V_98 -> V_149 , V_25 , & V_98 -> V_128 ) ;
else
F_81 ( V_25 , & V_98 -> V_128 ) ;
}
void F_82 ( struct V_97 * V_98 , T_4 V_137 , int V_150 )
{
if ( V_137 == V_151 && V_150 < V_98 -> V_152 ) {
if ( V_98 -> V_123 & V_153 ) {
V_98 -> V_154 += V_98 -> V_152 - V_150 ;
} else {
V_98 -> V_123 |= V_153 ;
V_98 -> V_154 = V_98 -> V_152 - V_150 ;
}
V_98 -> V_152 = V_150 ;
}
F_78 ( V_98 , V_137 ) ;
}
static void F_83 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
unsigned long V_73 ;
F_36 ( & V_100 -> V_104 , V_73 ) ;
if ( ! V_98 -> V_105 ) {
F_32 ( & V_98 -> V_106 , & V_100 -> V_106 ) ;
V_98 -> V_105 = true ;
}
F_37 ( & V_100 -> V_104 , V_73 ) ;
}
void F_84 ( struct V_127 * V_128 )
{
struct V_99 * V_100 = F_42 ( V_128 , struct V_99 ,
V_155 ) ;
F_85 ( V_156 ) ;
struct V_97 * V_98 , * V_157 ;
F_31 ( & V_100 -> V_158 ) ;
F_86 ( & V_100 -> V_156 , & V_156 ) ;
F_33 ( & V_100 -> V_158 ) ;
F_87 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_55 ( & V_98 -> V_159 ) ;
F_88 ( & V_100 -> V_160 ) ;
F_34 ( L_42
L_43 , V_98 -> V_92 -> V_72 () , V_98 ,
( V_98 -> V_111 == V_161 ) ? L_44 :
( V_98 -> V_111 == V_162 ) ? L_45
: L_46 ) ;
if ( V_98 -> V_111 == V_162 )
F_89 ( V_98 ) ;
else if ( V_98 -> V_111 == V_161 )
F_90 ( V_98 ) ;
}
}
unsigned char * F_91 ( struct V_97 * V_98 )
{
switch ( V_98 -> V_163 ) {
case V_164 :
return L_47 ;
case V_165 :
return L_48 ;
case V_166 :
return L_49 ;
case V_167 :
return L_50 ;
default:
break;
}
return L_46 ;
}
void F_92 (
struct V_99 * V_100 ,
char * V_168 ,
int * V_169 )
{
* V_169 += sprintf ( V_168 + * V_169 , L_51 ) ;
if ( V_100 -> V_170 )
* V_169 += sprintf ( V_168 + * V_169 , L_52 ) ;
else
* V_169 += sprintf ( V_168 + * V_169 , L_53 ) ;
* V_169 += sprintf ( V_168 + * V_169 , L_54 , V_100 -> V_171 ) ;
* V_169 += sprintf ( V_168 + * V_169 , L_55 ,
V_100 -> V_172 . V_173 ,
V_100 -> V_172 . V_174 ) ;
* V_169 += sprintf ( V_168 + * V_169 , L_56 ) ;
}
void F_93 (
struct V_175 * V_176 ,
unsigned char * V_177 ,
int V_178 )
{
unsigned char V_61 [ V_179 ] ;
int V_84 ;
memset ( V_61 , 0 , V_179 ) ;
V_84 = sprintf ( V_61 , L_57 ) ;
switch ( V_176 -> V_180 ) {
case 0x00 :
sprintf ( V_61 + V_84 , L_58 ) ;
break;
case 0x10 :
sprintf ( V_61 + V_84 , L_59 ) ;
break;
case 0x20 :
sprintf ( V_61 + V_84 , L_60 ) ;
break;
case 0x30 :
sprintf ( V_61 + V_84 , L_61 ) ;
break;
case 0x40 :
sprintf ( V_61 + V_84 , L_62
L_63 ) ;
break;
case 0x50 :
sprintf ( V_61 + V_84 , L_64 ) ;
break;
case 0x60 :
sprintf ( V_61 + V_84 , L_65 ) ;
break;
case 0x70 :
sprintf ( V_61 + V_84 , L_66
L_63 ) ;
break;
case 0x80 :
sprintf ( V_61 + V_84 , L_67 ) ;
break;
default:
sprintf ( V_61 + V_84 , L_68 ,
V_176 -> V_180 ) ;
break;
}
if ( V_177 )
strncpy ( V_177 , V_61 , V_178 ) ;
else
F_34 ( L_69 , V_61 ) ;
}
void
F_94 ( struct V_175 * V_176 , unsigned char * V_181 )
{
if ( V_181 [ 1 ] & 0x80 ) {
V_176 -> V_180 = ( V_181 [ 0 ] & 0xf0 ) ;
V_176 -> V_182 = 1 ;
F_93 ( V_176 , NULL , 0 ) ;
}
}
int F_95 (
struct V_175 * V_176 ,
unsigned char * V_177 ,
int V_178 )
{
unsigned char V_61 [ V_179 ] ;
int V_33 = 0 ;
int V_84 ;
memset ( V_61 , 0 , V_179 ) ;
V_84 = sprintf ( V_61 , L_70 ) ;
switch ( V_176 -> V_183 ) {
case 0x00 :
sprintf ( V_61 + V_84 , L_71 ) ;
break;
case 0x10 :
sprintf ( V_61 + V_84 , L_72 ) ;
break;
case 0x20 :
sprintf ( V_61 + V_84 , L_73 ) ;
break;
default:
sprintf ( V_61 + V_84 , L_68 , V_176 -> V_183 ) ;
V_33 = - V_52 ;
break;
}
if ( V_177 )
strncpy ( V_177 , V_61 , V_178 ) ;
else
F_34 ( L_69 , V_61 ) ;
return V_33 ;
}
int F_96 ( struct V_175 * V_176 , unsigned char * V_181 )
{
V_176 -> V_183 = ( V_181 [ 1 ] & 0x30 ) ;
return F_95 ( V_176 , NULL , 0 ) ;
}
int F_97 (
struct V_175 * V_176 ,
unsigned char * V_177 ,
int V_178 )
{
unsigned char V_61 [ V_179 ] ;
int V_33 = 0 ;
int V_84 ;
memset ( V_61 , 0 , V_179 ) ;
V_84 = sprintf ( V_61 , L_74 ) ;
switch ( V_176 -> V_184 ) {
case 0x00 :
sprintf ( V_61 + V_84 , L_75 ) ;
break;
case 0x01 :
sprintf ( V_61 + V_84 , L_76 ) ;
break;
case 0x02 :
sprintf ( V_61 + V_84 , L_77 ) ;
break;
case 0x03 :
sprintf ( V_61 + V_84 , L_78 ) ;
break;
case 0x04 :
sprintf ( V_61 + V_84 , L_79 ) ;
break;
case 0x08 :
sprintf ( V_61 + V_84 , L_80 ) ;
break;
default:
sprintf ( V_61 + V_84 , L_81 ,
V_176 -> V_184 ) ;
V_33 = - V_52 ;
break;
}
if ( V_177 ) {
if ( V_178 < strlen ( V_61 ) + 1 )
return - V_52 ;
strncpy ( V_177 , V_61 , V_178 ) ;
} else {
F_34 ( L_69 , V_61 ) ;
}
return V_33 ;
}
int F_98 ( struct V_175 * V_176 , unsigned char * V_181 )
{
V_176 -> V_184 = ( V_181 [ 1 ] & 0x0f ) ;
return F_97 ( V_176 , NULL , 0 ) ;
}
int F_99 (
struct V_175 * V_176 ,
unsigned char * V_177 ,
int V_178 )
{
unsigned char V_61 [ V_179 ] ;
int V_33 = 0 ;
memset ( V_61 , 0 , V_179 ) ;
switch ( V_176 -> V_185 ) {
case 0x01 :
snprintf ( V_61 , sizeof( V_61 ) ,
L_82 ,
& V_176 -> V_186 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_61 , sizeof( V_61 ) ,
L_83 ,
& V_176 -> V_186 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_61 , sizeof( V_61 ) ,
L_84 ,
& V_176 -> V_186 [ 0 ] ) ;
break;
default:
sprintf ( V_61 , L_85
L_86 , V_176 -> V_185 ) ;
V_33 = - V_52 ;
break;
}
if ( V_177 )
strncpy ( V_177 , V_61 , V_178 ) ;
else
F_34 ( L_69 , V_61 ) ;
return V_33 ;
}
int
F_100 ( struct V_175 * V_176 , unsigned char * V_181 )
{
static const char V_187 [] = L_87 ;
int V_188 = 0 , V_189 = 4 ;
V_176 -> V_185 = ( V_181 [ 0 ] & 0x0f ) ;
switch ( V_176 -> V_185 ) {
case 0x01 :
V_176 -> V_186 [ V_188 ++ ] =
V_187 [ V_176 -> V_184 ] ;
while ( V_189 < ( 4 + V_181 [ 3 ] ) ) {
V_176 -> V_186 [ V_188 ++ ] =
V_187 [ ( V_181 [ V_189 ] & 0xf0 ) >> 4 ] ;
V_176 -> V_186 [ V_188 ++ ] =
V_187 [ V_181 [ V_189 ] & 0x0f ] ;
V_189 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_189 < ( 4 + V_181 [ 3 ] ) )
V_176 -> V_186 [ V_188 ++ ] = V_181 [ V_189 ++ ] ;
break;
default:
break;
}
return F_99 ( V_176 , NULL , 0 ) ;
}
static T_5
F_101 ( struct V_97 * V_98 , struct V_99 * V_100 ,
unsigned int V_190 )
{
T_1 V_191 ;
if ( ! V_98 -> V_92 -> V_192 )
return V_193 ;
V_191 = ( V_98 -> V_92 -> V_192 * V_86 ) ;
if ( V_98 -> V_152 > V_191 ) {
if ( V_98 -> V_123 & V_194 ) {
V_98 -> V_154 = ( V_190 - V_191 ) ;
} else if ( V_98 -> V_123 & V_153 ) {
T_1 V_195 = V_190 + V_98 -> V_154 ;
V_98 -> V_154 = ( V_195 - V_191 ) ;
} else {
V_98 -> V_123 |= V_153 ;
V_98 -> V_154 = ( V_98 -> V_152 - V_191 ) ;
}
V_98 -> V_152 = V_191 ;
if ( V_98 -> V_196 ) {
T_1 V_197 = ( V_191 / V_100 -> V_172 . V_173 ) ;
V_98 -> V_196 = V_100 -> V_196 * V_197 ;
}
}
return V_193 ;
}
T_5
F_102 ( struct V_97 * V_98 , unsigned int V_190 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
if ( V_98 -> V_198 ) {
V_98 -> V_152 = V_190 ;
} else if ( V_190 != V_98 -> V_152 ) {
F_103 ( L_88
L_89
L_90 , V_98 -> V_92 -> V_72 () ,
V_98 -> V_152 , V_190 , V_98 -> V_199 [ 0 ] ) ;
if ( V_98 -> V_163 == V_166 &&
V_98 -> V_123 & V_200 ) {
F_4 ( L_91 ) ;
return V_201 ;
}
if ( V_100 -> V_172 . V_173 != 512 ) {
F_4 ( L_92
L_93
L_94 , V_100 -> V_135 -> V_136 ) ;
return V_201 ;
}
if ( V_190 > V_98 -> V_152 ) {
V_98 -> V_123 |= V_194 ;
V_98 -> V_154 = ( V_190 - V_98 -> V_152 ) ;
} else {
V_98 -> V_123 |= V_153 ;
V_98 -> V_154 = ( V_98 -> V_152 - V_190 ) ;
V_98 -> V_152 = V_190 ;
}
}
return F_101 ( V_98 , V_100 , V_190 ) ;
}
void F_104 (
struct V_97 * V_98 ,
const struct V_58 * V_59 ,
struct V_2 * V_37 ,
T_1 V_152 ,
int V_163 ,
int V_202 ,
unsigned char * V_138 )
{
F_18 ( & V_98 -> V_203 ) ;
F_18 ( & V_98 -> V_159 ) ;
F_18 ( & V_98 -> V_204 ) ;
F_18 ( & V_98 -> V_106 ) ;
F_105 ( & V_98 -> V_116 ) ;
F_105 ( & V_98 -> V_205 ) ;
F_19 ( & V_98 -> V_110 ) ;
F_20 ( & V_98 -> V_206 ) ;
V_98 -> V_102 = V_207 ;
V_98 -> V_92 = V_59 ;
V_98 -> V_37 = V_37 ;
V_98 -> V_152 = V_152 ;
V_98 -> V_163 = V_163 ;
V_98 -> V_208 = V_202 ;
V_98 -> V_138 = V_138 ;
V_98 -> V_105 = false ;
}
static T_5
F_106 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
if ( V_100 -> V_135 -> V_209 & V_210 )
return 0 ;
if ( V_98 -> V_208 == V_211 ) {
F_34 ( L_95
L_96 ) ;
return V_201 ;
}
return 0 ;
}
T_5
F_107 ( struct V_97 * V_98 , unsigned char * V_212 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
T_5 V_33 ;
if ( F_108 ( V_212 ) > V_213 ) {
F_4 ( L_97
L_98 ,
F_108 ( V_212 ) , V_213 ) ;
return V_201 ;
}
if ( F_108 ( V_212 ) > sizeof( V_98 -> V_214 ) ) {
V_98 -> V_199 = F_22 ( F_108 ( V_212 ) ,
V_38 ) ;
if ( ! V_98 -> V_199 ) {
F_4 ( L_99
L_100 ,
F_108 ( V_212 ) ,
( unsigned long ) sizeof( V_98 -> V_214 ) ) ;
return V_215 ;
}
} else
V_98 -> V_199 = & V_98 -> V_214 [ 0 ] ;
memcpy ( V_98 -> V_199 , V_212 , F_108 ( V_212 ) ) ;
F_109 ( V_98 ) ;
V_33 = F_110 ( V_98 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_111 ( V_98 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_112 ( V_98 ) ;
if ( V_33 ) {
V_98 -> V_137 = V_216 ;
return V_33 ;
}
V_33 = V_100 -> V_135 -> V_217 ( V_98 ) ;
if ( V_33 == V_218 )
F_113 ( L_101 ,
V_98 -> V_92 -> V_72 () ,
V_98 -> V_37 -> V_55 -> V_77 ,
V_98 -> V_199 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_106 ( V_98 ) ;
if ( V_33 )
return V_33 ;
V_98 -> V_123 |= V_219 ;
F_114 ( & V_98 -> V_109 -> V_220 . V_221 ) ;
return 0 ;
}
int F_115 (
struct V_97 * V_98 )
{
T_5 V_33 ;
if ( ! V_98 -> V_109 ) {
F_116 () ;
F_4 ( L_102 ) ;
return - V_52 ;
}
if ( F_117 () ) {
F_116 () ;
F_4 ( L_103
L_104 ) ;
return - V_52 ;
}
V_98 -> V_111 = V_222 ;
V_98 -> V_102 |= V_117 ;
V_33 = F_118 ( V_98 ) ;
if ( V_33 )
F_75 ( V_98 , V_33 ) ;
return 0 ;
}
T_5
F_119 ( struct V_97 * V_98 , struct V_223 * V_224 ,
T_1 V_225 , struct V_223 * V_226 , T_1 V_227 )
{
if ( ! V_224 || ! V_225 )
return 0 ;
if ( V_98 -> V_123 & V_194 ) {
F_103 ( L_105
L_106 ) ;
return V_201 ;
}
V_98 -> V_142 = V_224 ;
V_98 -> V_228 = V_225 ;
V_98 -> V_229 = V_226 ;
V_98 -> V_230 = V_227 ;
V_98 -> V_123 |= V_231 ;
return 0 ;
}
int F_120 ( struct V_97 * V_97 , struct V_2 * V_37 ,
unsigned char * V_212 , unsigned char * V_232 , T_6 V_233 ,
T_1 V_152 , int V_202 , int V_234 , int V_73 ,
struct V_223 * V_224 , T_1 V_225 ,
struct V_223 * V_226 , T_1 V_227 ,
struct V_223 * V_235 , T_1 V_236 )
{
struct V_53 * V_54 ;
T_5 V_47 ;
int V_33 ;
V_54 = V_37 -> V_54 ;
F_10 ( ! V_54 ) ;
F_10 ( V_97 -> V_92 || V_97 -> V_37 ) ;
F_10 ( F_117 () ) ;
F_104 ( V_97 , V_54 -> V_60 , V_37 ,
V_152 , V_234 , V_202 , V_232 ) ;
if ( V_73 & V_237 )
V_97 -> V_123 |= V_148 ;
else
V_97 -> V_149 = V_238 ;
if ( V_73 & V_239 )
V_97 -> V_198 = 1 ;
V_33 = F_121 ( V_97 , V_73 & V_240 ) ;
if ( V_33 )
return V_33 ;
if ( V_73 & V_241 )
V_97 -> V_123 |= V_242 ;
V_47 = F_122 ( V_97 , V_233 ) ;
if ( V_47 ) {
F_123 ( V_97 , V_47 , 0 ) ;
F_124 ( V_97 ) ;
return 0 ;
}
V_47 = F_107 ( V_97 , V_212 ) ;
if ( V_47 != 0 ) {
F_75 ( V_97 , V_47 ) ;
return 0 ;
}
if ( V_236 ) {
V_97 -> V_243 = V_235 ;
V_97 -> V_244 = V_236 ;
V_97 -> V_123 |= V_245 ;
}
if ( V_225 != 0 ) {
F_10 ( ! V_224 ) ;
if ( ! ( V_97 -> V_123 & V_200 ) &&
V_97 -> V_163 == V_165 ) {
unsigned char * V_61 = NULL ;
if ( V_224 )
V_61 = F_125 ( F_126 ( V_224 ) ) + V_224 -> V_246 ;
if ( V_61 ) {
memset ( V_61 , 0 , V_224 -> V_150 ) ;
F_127 ( F_126 ( V_224 ) ) ;
}
}
V_47 = F_119 ( V_97 , V_224 , V_225 ,
V_226 , V_227 ) ;
if ( V_47 != 0 ) {
F_75 ( V_97 , V_47 ) ;
return 0 ;
}
}
F_128 ( V_97 ) ;
F_115 ( V_97 ) ;
return 0 ;
}
int F_129 ( struct V_97 * V_97 , struct V_2 * V_37 ,
unsigned char * V_212 , unsigned char * V_232 , T_6 V_233 ,
T_1 V_152 , int V_202 , int V_234 , int V_73 )
{
return F_120 ( V_97 , V_37 , V_212 , V_232 ,
V_233 , V_152 , V_202 , V_234 ,
V_73 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_130 ( struct V_127 * V_128 )
{
struct V_97 * V_97 = F_42 ( V_128 , struct V_97 , V_128 ) ;
V_97 -> V_247 -> V_248 = V_249 ;
V_97 -> V_92 -> V_250 ( V_97 ) ;
F_68 ( V_97 ) ;
}
int F_131 ( struct V_97 * V_97 , struct V_2 * V_37 ,
unsigned char * V_232 , T_6 V_233 ,
void * V_251 , unsigned char V_252 ,
T_7 V_253 , T_6 V_115 , int V_73 )
{
struct V_53 * V_54 ;
int V_33 ;
V_54 = V_37 -> V_54 ;
F_10 ( ! V_54 ) ;
F_104 ( V_97 , V_54 -> V_60 , V_37 ,
0 , V_164 , V_254 , V_232 ) ;
V_33 = F_132 ( V_97 , V_251 , V_252 , V_253 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_252 == V_255 )
V_97 -> V_247 -> V_256 = V_115 ;
V_33 = F_121 ( V_97 , V_73 & V_240 ) ;
if ( V_33 ) {
F_133 ( V_97 -> V_247 ) ;
return V_33 ;
}
V_33 = F_134 ( V_97 , V_233 ) ;
if ( V_33 ) {
F_79 ( & V_97 -> V_128 , F_130 ) ;
F_135 ( & V_97 -> V_128 ) ;
return 0 ;
}
F_136 ( V_97 ) ;
return 0 ;
}
void F_75 ( struct V_97 * V_98 ,
T_5 V_257 )
{
int V_33 = 0 , V_258 = 0 ;
F_34 ( L_107
L_108 , V_98 , V_98 -> V_115 , V_98 -> V_199 [ 0 ] ) ;
F_34 ( L_109 ,
V_98 -> V_92 -> V_259 ( V_98 ) ,
V_98 -> V_111 , V_257 ) ;
F_34 ( L_110 ,
( V_98 -> V_102 & V_117 ) != 0 ,
( V_98 -> V_102 & V_113 ) != 0 ,
( V_98 -> V_102 & V_260 ) != 0 ) ;
F_137 ( V_98 ) ;
if ( ( V_98 -> V_123 & V_261 ) &&
V_98 -> V_262 )
V_98 -> V_262 ( V_98 , false , & V_258 ) ;
switch ( V_257 ) {
case V_263 :
case V_218 :
case V_201 :
case V_264 :
case V_265 :
case V_129 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
break;
case V_215 :
V_257 = V_129 ;
break;
case V_275 :
V_98 -> V_137 = V_216 ;
if ( V_98 -> V_37 &&
V_98 -> V_101 -> V_172 . V_276 == 2 ) {
F_138 ( V_98 -> V_37 -> V_55 ,
V_98 -> V_277 , 0x2C ,
V_278 ) ;
}
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_279 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
goto V_282;
default:
F_4 ( L_111 ,
V_98 -> V_199 [ 0 ] , V_257 ) ;
V_257 = V_218 ;
break;
}
V_33 = F_123 ( V_98 , V_257 , 0 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
V_282:
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
return;
V_281:
V_98 -> V_111 = V_161 ;
F_140 ( V_98 , V_98 -> V_101 ) ;
}
void F_141 ( struct V_97 * V_98 )
{
T_5 V_33 ;
if ( V_98 -> V_283 ) {
V_33 = V_98 -> V_283 ( V_98 ) ;
if ( V_33 ) {
F_31 ( & V_98 -> V_110 ) ;
V_98 -> V_102 &= ~ ( V_103 | V_260 ) ;
F_33 ( & V_98 -> V_110 ) ;
F_75 ( V_98 , V_33 ) ;
}
}
}
static int F_142 ( struct V_97 * V_98 )
{
T_1 V_197 ;
switch ( V_98 -> V_76 ) {
case V_284 :
if ( ! ( V_98 -> V_37 -> V_36 & V_284 ) )
F_143 ( V_98 ) ;
break;
case V_285 :
if ( V_98 -> V_37 -> V_36 & V_285 )
break;
V_197 = V_98 -> V_152 >> F_144 ( V_98 -> V_101 -> V_172 . V_173 ) ;
V_98 -> V_286 = F_145 ( V_98 , V_98 -> V_287 ,
V_197 , 0 , V_98 -> V_243 , 0 ) ;
if ( F_146 ( V_98 -> V_286 ) ) {
F_31 ( & V_98 -> V_110 ) ;
V_98 -> V_102 &= ~ ( V_103 | V_260 ) ;
F_33 ( & V_98 -> V_110 ) ;
F_75 ( V_98 , V_98 -> V_286 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_147 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
if ( V_100 -> V_135 -> V_209 & V_210 )
return false ;
switch ( V_98 -> V_208 ) {
case V_288 :
F_34 ( L_112 ,
V_98 -> V_199 [ 0 ] ) ;
return false ;
case V_289 :
F_148 ( & V_100 -> V_290 ) ;
F_34 ( L_113 ,
V_98 -> V_199 [ 0 ] ) ;
if ( ! F_149 ( & V_100 -> V_291 ) )
return false ;
break;
default:
F_148 ( & V_100 -> V_291 ) ;
break;
}
if ( F_149 ( & V_100 -> V_290 ) == 0 )
return false ;
F_11 ( & V_100 -> V_292 ) ;
F_32 ( & V_98 -> V_203 , & V_100 -> V_293 ) ;
F_12 ( & V_100 -> V_292 ) ;
F_34 ( L_114 ,
V_98 -> V_199 [ 0 ] , V_98 -> V_208 ) ;
return true ;
}
void F_150 ( struct V_97 * V_98 )
{
F_31 ( & V_98 -> V_110 ) ;
if ( F_151 ( V_98 , 1 ) ) {
F_33 ( & V_98 -> V_110 ) ;
return;
}
if ( V_98 -> V_102 & V_113 ) {
F_34 ( L_40 ,
V_114 , __LINE__ , V_98 -> V_115 ) ;
F_33 ( & V_98 -> V_110 ) ;
F_67 ( & V_98 -> V_116 ) ;
return;
}
V_98 -> V_111 = V_294 ;
V_98 -> V_102 |= V_117 | V_103 | V_260 ;
F_33 ( & V_98 -> V_110 ) ;
if ( F_142 ( V_98 ) )
return;
if ( F_147 ( V_98 ) ) {
F_31 ( & V_98 -> V_110 ) ;
V_98 -> V_102 &= ~ ( V_103 | V_260 ) ;
F_33 ( & V_98 -> V_110 ) ;
return;
}
F_141 ( V_98 ) ;
}
static void F_152 ( struct V_99 * V_100 )
{
for (; ; ) {
struct V_97 * V_98 ;
F_11 ( & V_100 -> V_292 ) ;
if ( F_56 ( & V_100 -> V_293 ) ) {
F_12 ( & V_100 -> V_292 ) ;
break;
}
V_98 = F_153 ( V_100 -> V_293 . V_295 ,
struct V_97 , V_203 ) ;
F_55 ( & V_98 -> V_203 ) ;
F_12 ( & V_100 -> V_292 ) ;
F_141 ( V_98 ) ;
if ( V_98 -> V_208 == V_289 )
break;
}
}
static void F_137 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
if ( V_100 -> V_135 -> V_209 & V_210 )
return;
if ( V_98 -> V_208 == V_254 ) {
F_88 ( & V_100 -> V_291 ) ;
V_100 -> V_296 ++ ;
F_34 ( L_115 ,
V_100 -> V_296 ) ;
} else if ( V_98 -> V_208 == V_288 ) {
V_100 -> V_296 ++ ;
F_34 ( L_116 ,
V_100 -> V_296 ) ;
} else if ( V_98 -> V_208 == V_289 ) {
F_88 ( & V_100 -> V_290 ) ;
V_100 -> V_296 ++ ;
F_34 ( L_117 ,
V_100 -> V_296 ) ;
}
F_152 ( V_100 ) ;
}
static void F_90 ( struct V_97 * V_98 )
{
int V_33 = 0 ;
F_137 ( V_98 ) ;
if ( V_98 -> V_123 & V_143 ) {
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_279 ( V_98 ) ;
goto V_3;
}
switch ( V_98 -> V_163 ) {
case V_165 :
if ( V_98 -> V_137 )
goto V_279;
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_297 ( V_98 ) ;
break;
case V_166 :
if ( V_98 -> V_123 & V_242 ) {
V_33 = V_98 -> V_92 -> V_297 ( V_98 ) ;
break;
}
case V_164 :
V_279:
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_279 ( V_98 ) ;
break;
default:
break;
}
V_3:
if ( V_33 < 0 ) {
F_140 ( V_98 , V_98 -> V_101 ) ;
return;
}
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
}
static void F_140 (
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
F_31 ( & V_100 -> V_158 ) ;
F_32 ( & V_98 -> V_159 , & V_98 -> V_101 -> V_156 ) ;
F_148 ( & V_100 -> V_160 ) ;
F_33 ( & V_98 -> V_101 -> V_158 ) ;
F_135 ( & V_98 -> V_101 -> V_155 ) ;
}
static bool F_154 ( struct V_97 * V_98 )
{
switch ( V_98 -> V_76 ) {
case V_298 :
if ( ! ( V_98 -> V_37 -> V_36 & V_298 ) ) {
T_1 V_197 = V_98 -> V_152 >>
F_144 ( V_98 -> V_101 -> V_172 . V_173 ) ;
V_98 -> V_286 = F_145 ( V_98 , V_98 -> V_287 ,
V_197 , 0 , V_98 -> V_243 ,
0 ) ;
if ( V_98 -> V_286 )
return true ;
}
break;
case V_299 :
if ( V_98 -> V_37 -> V_36 & V_299 )
break;
F_143 ( V_98 ) ;
break;
default:
break;
}
return false ;
}
static void V_145 ( struct V_127 * V_128 )
{
struct V_97 * V_98 = F_42 ( V_128 , struct V_97 , V_128 ) ;
int V_33 ;
F_137 ( V_98 ) ;
if ( F_149 ( & V_98 -> V_101 -> V_160 ) != 0 )
F_135 ( & V_98 -> V_101 -> V_155 ) ;
if ( V_98 -> V_123 & V_143 ) {
F_77 ( ! V_98 -> V_137 ) ;
V_33 = F_123 (
V_98 , 0 , 1 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
return;
}
if ( V_98 -> V_262 ) {
T_5 V_47 ;
bool V_300 = ( V_98 -> V_123 & V_261 ) ;
bool V_301 = ! ( V_98 -> V_152 ) ;
int V_258 = 0 ;
V_47 = V_98 -> V_262 ( V_98 , true , & V_258 ) ;
if ( ! V_47 && ! V_258 ) {
if ( V_300 && V_301 )
goto V_302;
return;
} else if ( V_47 ) {
V_33 = F_123 ( V_98 ,
V_47 , 0 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
return;
}
}
V_302:
switch ( V_98 -> V_163 ) {
case V_165 :
if ( V_98 -> V_137 )
goto V_279;
F_155 ( V_98 -> V_152 ,
& V_98 -> V_109 -> V_220 . V_303 ) ;
if ( F_154 ( V_98 ) ) {
V_33 = F_123 ( V_98 ,
V_98 -> V_286 , 0 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
return;
}
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_297 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
break;
case V_166 :
F_155 ( V_98 -> V_152 ,
& V_98 -> V_109 -> V_220 . V_304 ) ;
if ( V_98 -> V_123 & V_242 ) {
F_155 ( V_98 -> V_152 ,
& V_98 -> V_109 -> V_220 . V_303 ) ;
V_33 = V_98 -> V_92 -> V_297 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
break;
}
case V_164 :
V_279:
F_139 ( V_98 ) ;
V_33 = V_98 -> V_92 -> V_279 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
break;
default:
break;
}
F_69 ( V_98 ) ;
F_68 ( V_98 ) ;
return;
V_281:
F_34 ( L_118
L_119 , V_98 , V_98 -> V_163 ) ;
V_98 -> V_111 = V_161 ;
F_140 ( V_98 , V_98 -> V_101 ) ;
}
static inline void F_156 ( struct V_223 * V_224 , int V_305 )
{
struct V_223 * V_306 ;
int V_307 ;
F_157 (sgl, sg, nents, count)
F_158 ( F_126 ( V_306 ) ) ;
F_64 ( V_224 ) ;
}
static inline void F_159 ( struct V_97 * V_98 )
{
if ( ! V_98 -> V_308 )
return;
F_64 ( V_98 -> V_142 ) ;
V_98 -> V_142 = V_98 -> V_308 ;
V_98 -> V_308 = NULL ;
V_98 -> V_228 = V_98 -> V_309 ;
V_98 -> V_309 = 0 ;
}
static inline void F_160 ( struct V_97 * V_98 )
{
if ( ! ( V_98 -> V_123 & V_245 ) ) {
F_156 ( V_98 -> V_243 , V_98 -> V_244 ) ;
V_98 -> V_243 = NULL ;
V_98 -> V_244 = 0 ;
}
if ( V_98 -> V_123 & V_231 ) {
if ( V_98 -> V_123 & V_261 ) {
F_156 ( V_98 -> V_229 ,
V_98 -> V_230 ) ;
V_98 -> V_229 = NULL ;
V_98 -> V_230 = 0 ;
}
F_159 ( V_98 ) ;
return;
}
F_159 ( V_98 ) ;
F_156 ( V_98 -> V_142 , V_98 -> V_228 ) ;
V_98 -> V_142 = NULL ;
V_98 -> V_228 = 0 ;
F_156 ( V_98 -> V_229 , V_98 -> V_230 ) ;
V_98 -> V_229 = NULL ;
V_98 -> V_230 = 0 ;
}
static int F_73 ( struct V_97 * V_98 )
{
F_10 ( ! V_98 -> V_92 ) ;
return F_124 ( V_98 ) ;
}
void * F_161 ( struct V_97 * V_98 )
{
struct V_223 * V_306 = V_98 -> V_142 ;
struct V_83 * * V_310 ;
int V_189 ;
if ( ! V_98 -> V_228 )
return NULL ;
F_10 ( ! V_306 ) ;
if ( V_98 -> V_228 == 1 )
return F_125 ( F_126 ( V_306 ) ) + V_306 -> V_246 ;
V_310 = F_162 ( sizeof( * V_310 ) * V_98 -> V_228 , V_38 ) ;
if ( ! V_310 )
return NULL ;
F_157 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_310 [ V_189 ] = F_126 ( V_306 ) ;
}
V_98 -> V_311 = F_163 ( V_310 , V_98 -> V_228 , V_312 , V_313 ) ;
F_64 ( V_310 ) ;
if ( ! V_98 -> V_311 )
return NULL ;
return V_98 -> V_311 + V_98 -> V_142 [ 0 ] . V_246 ;
}
void F_164 ( struct V_97 * V_98 )
{
if ( ! V_98 -> V_228 ) {
return;
} else if ( V_98 -> V_228 == 1 ) {
F_127 ( F_126 ( V_98 -> V_142 ) ) ;
return;
}
F_165 ( V_98 -> V_311 ) ;
V_98 -> V_311 = NULL ;
}
int
F_166 ( struct V_223 * * V_224 , unsigned int * V_305 , T_1 V_150 ,
bool V_314 )
{
struct V_223 * V_306 ;
struct V_83 * V_83 ;
T_7 V_315 = ( V_314 ) ? V_316 : 0 ;
unsigned int V_317 ;
int V_189 = 0 ;
V_317 = F_167 ( V_150 , V_86 ) ;
V_306 = F_162 ( sizeof( struct V_223 ) * V_317 , V_38 ) ;
if ( ! V_306 )
return - V_28 ;
F_168 ( V_306 , V_317 ) ;
while ( V_150 ) {
T_1 V_318 = F_169 ( T_1 , V_150 , V_86 ) ;
V_83 = F_170 ( V_38 | V_315 ) ;
if ( ! V_83 )
goto V_3;
F_171 ( & V_306 [ V_189 ] , V_83 , V_318 , 0 ) ;
V_150 -= V_318 ;
V_189 ++ ;
}
* V_224 = V_306 ;
* V_305 = V_317 ;
return 0 ;
V_3:
while ( V_189 > 0 ) {
V_189 -- ;
F_158 ( F_126 ( & V_306 [ V_189 ] ) ) ;
}
F_64 ( V_306 ) ;
return - V_28 ;
}
T_5
F_118 ( struct V_97 * V_98 )
{
int V_33 = 0 ;
bool V_315 = ! ( V_98 -> V_123 & V_200 ) ;
if ( V_98 -> V_76 != V_319 &&
! ( V_98 -> V_123 & V_245 ) ) {
V_33 = F_166 ( & V_98 -> V_243 , & V_98 -> V_244 ,
V_98 -> V_196 , true ) ;
if ( V_33 < 0 )
return V_129 ;
}
if ( ! ( V_98 -> V_123 & V_231 ) &&
V_98 -> V_152 ) {
if ( ( V_98 -> V_123 & V_242 ) ||
( V_98 -> V_123 & V_261 ) ) {
T_1 V_320 ;
if ( V_98 -> V_123 & V_261 )
V_320 = V_98 -> V_321 *
V_98 -> V_101 -> V_172 . V_173 ;
else
V_320 = V_98 -> V_152 ;
V_33 = F_166 ( & V_98 -> V_229 ,
& V_98 -> V_230 ,
V_320 , V_315 ) ;
if ( V_33 < 0 )
return V_129 ;
}
V_33 = F_166 ( & V_98 -> V_142 , & V_98 -> V_228 ,
V_98 -> V_152 , V_315 ) ;
if ( V_33 < 0 )
return V_129 ;
} else if ( ( V_98 -> V_123 & V_261 ) &&
V_98 -> V_152 ) {
T_1 V_322 = V_98 -> V_321 *
V_98 -> V_101 -> V_172 . V_173 ;
V_33 = F_166 ( & V_98 -> V_229 ,
& V_98 -> V_230 ,
V_322 , V_315 ) ;
if ( V_33 < 0 )
return V_129 ;
}
F_83 ( V_98 ) ;
if ( V_98 -> V_163 != V_166 || V_98 -> V_152 == 0 ) {
F_150 ( V_98 ) ;
return 0 ;
}
F_66 ( V_98 , false , true ) ;
V_33 = V_98 -> V_92 -> V_108 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 )
goto V_281;
F_77 ( V_33 ) ;
return ( ! V_33 ) ? 0 : V_129 ;
V_281:
F_34 ( L_120 , V_98 ) ;
V_98 -> V_111 = V_162 ;
F_140 ( V_98 , V_98 -> V_101 ) ;
return 0 ;
}
static void F_89 ( struct V_97 * V_98 )
{
int V_33 ;
V_33 = V_98 -> V_92 -> V_108 ( V_98 ) ;
if ( V_33 == - V_280 || V_33 == - V_28 ) {
F_34 ( L_120 ,
V_98 ) ;
F_140 ( V_98 , V_98 -> V_101 ) ;
}
}
static void F_172 ( struct V_97 * V_98 , bool * V_323 , bool * V_324 )
{
unsigned long V_73 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
F_173 ( V_98 , true , V_323 , V_324 , & V_73 ) ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
}
int F_174 ( struct V_97 * V_98 , int V_325 )
{
int V_33 = 0 ;
bool V_323 = false , V_324 = false ;
if ( ! ( V_98 -> V_123 & V_125 ) ) {
if ( V_325 && ( V_98 -> V_123 & V_326 ) )
F_172 ( V_98 , & V_323 , & V_324 ) ;
if ( ! V_323 || V_324 )
V_33 = F_73 ( V_98 ) ;
} else {
if ( V_325 )
F_172 ( V_98 , & V_323 , & V_324 ) ;
if ( V_98 -> V_105 )
F_65 ( V_98 ) ;
if ( V_98 -> V_109 )
F_69 ( V_98 ) ;
if ( ! V_323 || V_324 )
V_33 = F_73 ( V_98 ) ;
}
if ( V_323 ) {
F_34 ( L_121 , V_98 -> V_115 ) ;
F_175 ( & V_98 -> V_205 ) ;
V_98 -> V_92 -> V_327 ( V_98 ) ;
V_33 = 1 ;
}
return V_33 ;
}
int F_121 ( struct V_97 * V_97 , bool V_122 )
{
struct V_2 * V_37 = V_97 -> V_37 ;
unsigned long V_73 ;
int V_33 = 0 ;
if ( V_122 )
F_176 ( & V_97 -> V_206 ) ;
F_36 ( & V_37 -> V_43 , V_73 ) ;
if ( V_37 -> V_328 ) {
V_33 = - V_329 ;
goto V_3;
}
F_32 ( & V_97 -> V_204 , & V_37 -> V_41 ) ;
V_3:
F_37 ( & V_37 -> V_43 , V_73 ) ;
if ( V_33 && V_122 )
F_124 ( V_97 ) ;
return V_33 ;
}
static void F_177 ( struct V_97 * V_98 )
{
F_160 ( V_98 ) ;
if ( V_98 -> V_123 & V_326 )
F_133 ( V_98 -> V_247 ) ;
if ( V_98 -> V_199 != V_98 -> V_214 )
F_64 ( V_98 -> V_199 ) ;
}
static void F_178 ( struct V_81 * V_81 )
{
struct V_97 * V_97 = F_42 ( V_81 , struct V_97 , V_206 ) ;
struct V_2 * V_37 = V_97 -> V_37 ;
unsigned long V_73 ;
bool V_330 ;
F_36 ( & V_37 -> V_43 , V_73 ) ;
if ( F_56 ( & V_97 -> V_204 ) ) {
F_37 ( & V_37 -> V_43 , V_73 ) ;
F_177 ( V_97 ) ;
V_97 -> V_92 -> V_327 ( V_97 ) ;
return;
}
F_11 ( & V_97 -> V_110 ) ;
V_330 = ( V_97 -> V_102 & V_331 ) ;
F_12 ( & V_97 -> V_110 ) ;
if ( V_97 -> V_332 || V_330 ) {
F_179 ( & V_97 -> V_204 ) ;
F_37 ( & V_37 -> V_43 , V_73 ) ;
F_177 ( V_97 ) ;
F_52 ( & V_97 -> V_205 ) ;
return;
}
F_179 ( & V_97 -> V_204 ) ;
F_37 ( & V_37 -> V_43 , V_73 ) ;
F_177 ( V_97 ) ;
V_97 -> V_92 -> V_327 ( V_97 ) ;
}
int F_124 ( struct V_97 * V_97 )
{
struct V_2 * V_37 = V_97 -> V_37 ;
if ( ! V_37 ) {
F_177 ( V_97 ) ;
V_97 -> V_92 -> V_327 ( V_97 ) ;
return 1 ;
}
return F_46 ( & V_97 -> V_206 , F_178 ) ;
}
void F_180 ( struct V_2 * V_37 )
{
struct V_97 * V_97 ;
unsigned long V_73 ;
int V_47 ;
F_36 ( & V_37 -> V_43 , V_73 ) ;
if ( V_37 -> V_328 ) {
F_37 ( & V_37 -> V_43 , V_73 ) ;
return;
}
V_37 -> V_328 = 1 ;
F_86 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_49 (se_cmd, &se_sess->sess_wait_list, se_cmd_list) {
V_47 = F_44 ( & V_97 -> V_206 ) ;
if ( V_47 ) {
V_97 -> V_332 = 1 ;
F_11 ( & V_97 -> V_110 ) ;
V_97 -> V_102 |= V_331 ;
F_12 ( & V_97 -> V_110 ) ;
}
}
F_37 ( & V_37 -> V_43 , V_73 ) ;
}
void F_181 ( struct V_2 * V_37 )
{
struct V_97 * V_97 , * V_333 ;
unsigned long V_73 ;
bool V_324 ;
F_87 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_34 ( L_122
L_123 , V_97 , V_97 -> V_111 ,
V_97 -> V_92 -> V_259 ( V_97 ) ) ;
F_36 ( & V_97 -> V_110 , V_73 ) ;
V_324 = ( V_97 -> V_102 & V_334 ) ;
F_37 ( & V_97 -> V_110 , V_73 ) ;
if ( ! F_124 ( V_97 ) ) {
if ( V_324 )
F_124 ( V_97 ) ;
}
F_175 ( & V_97 -> V_205 ) ;
F_34 ( L_124
L_125 , V_97 , V_97 -> V_111 ,
V_97 -> V_92 -> V_259 ( V_97 ) ) ;
V_97 -> V_92 -> V_327 ( V_97 ) ;
}
F_36 ( & V_37 -> V_43 , V_73 ) ;
F_77 ( ! F_56 ( & V_37 -> V_41 ) ) ;
F_37 ( & V_37 -> V_43 , V_73 ) ;
}
void F_182 ( struct V_109 * V_119 )
{
F_183 ( & V_119 -> V_121 ) ;
F_175 ( & V_119 -> V_335 ) ;
}
static bool
F_173 ( struct V_97 * V_98 , bool V_330 ,
bool * V_323 , bool * V_324 , unsigned long * V_73 )
__releases( &cmd->t_state_lock
bool F_184 ( struct V_97 * V_98 )
{
unsigned long V_73 ;
bool V_33 , V_323 = false , V_324 = false ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
V_33 = F_173 ( V_98 , false , & V_323 , & V_324 , & V_73 ) ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
return V_33 ;
}
static int F_185 ( struct V_97 * V_98 , T_5 V_336 )
{
const struct V_337 * V_338 ;
T_4 * V_339 = V_98 -> V_138 ;
int V_340 = ( V_341 int ) V_336 ;
T_4 V_342 , V_343 ;
bool V_344 = F_186 ( V_98 -> V_101 ) ;
if ( V_340 < F_187 ( V_345 ) && V_345 [ V_340 ] . V_346 )
V_338 = & V_345 [ V_340 ] ;
else
V_338 = & V_345 [ ( V_341 int )
V_129 ] ;
if ( V_336 == V_270 ) {
F_188 ( V_98 , & V_342 , & V_343 ) ;
F_189 ( V_342 == 0 ) ;
} else if ( V_338 -> V_342 == 0 ) {
F_189 ( V_98 -> V_347 == 0 ) ;
V_342 = V_98 -> V_347 ;
V_343 = V_98 -> V_348 ;
} else {
V_342 = V_338 -> V_342 ;
V_343 = V_338 -> V_343 ;
}
F_190 ( V_344 , V_339 , V_338 -> V_346 , V_342 , V_343 ) ;
if ( V_338 -> V_349 )
return F_191 ( V_339 ,
V_98 -> V_131 ,
V_98 -> V_350 ) ;
return 0 ;
}
int
F_123 ( struct V_97 * V_98 ,
T_5 V_336 , int V_351 )
{
unsigned long V_73 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_123 & V_130 ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
return 0 ;
}
V_98 -> V_123 |= V_130 ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
if ( ! V_351 ) {
int V_47 ;
V_98 -> V_123 |= V_352 ;
V_98 -> V_137 = V_353 ;
V_98 -> V_131 = V_132 ;
V_47 = F_185 ( V_98 , V_336 ) ;
if ( V_47 )
return V_47 ;
}
F_139 ( V_98 ) ;
return V_98 -> V_92 -> V_279 ( V_98 ) ;
}
static int F_151 ( struct V_97 * V_98 , int V_354 )
__releases( &cmd->t_state_lock
int F_192 ( struct V_97 * V_98 , int V_354 )
{
int V_33 ;
F_31 ( & V_98 -> V_110 ) ;
V_33 = F_151 ( V_98 , V_354 ) ;
F_33 ( & V_98 -> V_110 ) ;
return V_33 ;
}
void F_193 ( struct V_97 * V_98 )
{
unsigned long V_73 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_123 & ( V_130 ) ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
return;
}
F_37 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_163 == V_166 ) {
if ( V_98 -> V_92 -> V_355 ( V_98 ) != 0 ) {
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_123 & V_356 ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
goto V_357;
}
V_98 -> V_123 |= V_356 ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
return;
}
}
V_357:
V_98 -> V_137 = V_358 ;
F_69 ( V_98 ) ;
F_34 ( L_126 ,
V_98 -> V_199 [ 0 ] , V_98 -> V_115 ) ;
F_139 ( V_98 ) ;
V_98 -> V_92 -> V_279 ( V_98 ) ;
}
static void F_194 ( struct V_127 * V_128 )
{
struct V_97 * V_98 = F_42 ( V_128 , struct V_97 , V_128 ) ;
struct V_99 * V_100 = V_98 -> V_101 ;
struct V_247 * V_359 = V_98 -> V_247 ;
unsigned long V_73 ;
int V_33 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_102 & V_144 ) {
V_359 -> V_248 = V_360 ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
goto V_282;
}
F_37 ( & V_98 -> V_110 , V_73 ) ;
switch ( V_359 -> V_361 ) {
case V_255 :
F_195 ( V_100 , V_359 , V_98 -> V_37 ) ;
break;
case V_362 :
case V_363 :
case V_364 :
V_359 -> V_248 = V_365 ;
break;
case V_366 :
V_33 = F_196 ( V_100 , V_359 , NULL , NULL ) ;
V_359 -> V_248 = ( ! V_33 ) ? V_367 :
V_360 ;
if ( V_359 -> V_248 == V_367 ) {
F_138 ( V_98 -> V_37 -> V_55 ,
V_98 -> V_277 , 0x29 ,
V_368 ) ;
}
break;
case V_369 :
V_359 -> V_248 = V_360 ;
break;
case V_370 :
V_359 -> V_248 = V_360 ;
break;
default:
F_4 ( L_127 ,
V_359 -> V_361 ) ;
V_359 -> V_248 = V_360 ;
break;
}
F_36 ( & V_98 -> V_110 , V_73 ) ;
if ( V_98 -> V_102 & V_144 ) {
F_37 ( & V_98 -> V_110 , V_73 ) ;
goto V_282;
}
V_98 -> V_111 = V_371 ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
V_98 -> V_92 -> V_250 ( V_98 ) ;
V_282:
F_68 ( V_98 ) ;
}
int F_136 (
struct V_97 * V_98 )
{
unsigned long V_73 ;
F_36 ( & V_98 -> V_110 , V_73 ) ;
V_98 -> V_102 |= V_117 ;
F_37 ( & V_98 -> V_110 , V_73 ) ;
F_79 ( & V_98 -> V_128 , F_194 ) ;
F_81 ( V_98 -> V_101 -> V_372 , & V_98 -> V_128 ) ;
return 0 ;
}
bool
F_197 ( struct V_99 * V_100 )
{
bool V_373 = false ;
if ( V_100 -> V_135 -> V_374 )
V_373 = V_100 -> V_135 -> V_374 ( V_100 ) ;
else if ( V_100 -> V_172 . V_375 > 0 )
V_373 = true ;
return V_373 ;
}
bool
F_198 ( struct V_99 * V_100 )
{
return F_197 ( V_100 ) && V_100 -> V_172 . V_376 > 0 ;
}
