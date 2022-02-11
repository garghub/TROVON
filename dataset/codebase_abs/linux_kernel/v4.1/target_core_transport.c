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
const struct V_60 * V_61 = V_56 -> V_62 ;
unsigned char V_63 [ V_64 ] ;
V_40 -> V_56 = V_56 ;
V_40 -> V_59 = V_59 ;
if ( V_58 ) {
if ( V_58 -> V_65 )
V_40 -> V_66 = V_58 -> V_65 ;
else if ( V_61 -> V_67 )
V_40 -> V_66 = V_58 -> V_65 =
V_61 -> V_67 ( V_56 ) ;
if ( V_56 -> V_62 -> V_68 != NULL ) {
memset ( & V_63 [ 0 ] , 0 , V_64 ) ;
V_56 -> V_62 -> V_68 ( V_40 ,
& V_63 [ 0 ] , V_64 ) ;
V_40 -> V_69 = F_32 ( & V_63 [ 0 ] ) ;
}
F_33 ( & V_58 -> V_70 ) ;
F_34 ( & V_58 -> V_71 ) ;
V_58 -> V_72 = V_40 ;
F_35 ( & V_40 -> V_43 ,
& V_58 -> V_73 ) ;
F_36 ( & V_58 -> V_71 ) ;
}
F_35 ( & V_40 -> V_42 , & V_56 -> V_74 ) ;
F_37 ( L_35 ,
V_56 -> V_62 -> V_75 () , V_40 -> V_59 ) ;
}
void F_38 (
struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_2 * V_40 ,
void * V_59 )
{
unsigned long V_76 ;
F_39 ( & V_56 -> V_77 , V_76 ) ;
F_31 ( V_56 , V_58 , V_40 , V_59 ) ;
F_40 ( & V_56 -> V_77 , V_76 ) ;
}
static void F_41 ( struct V_78 * V_78 )
{
struct V_2 * V_40 = F_42 ( V_78 ,
struct V_2 , V_47 ) ;
struct V_55 * V_56 = V_40 -> V_56 ;
V_56 -> V_62 -> V_79 ( V_40 ) ;
}
void F_43 ( struct V_2 * V_40 )
{
F_33 ( & V_40 -> V_47 ) ;
}
void F_44 ( struct V_2 * V_40 )
{
struct V_55 * V_80 = V_40 -> V_56 ;
if ( V_80 -> V_62 -> V_81 != NULL ) {
V_80 -> V_62 -> V_81 ( V_40 ) ;
return;
}
F_45 ( & V_40 -> V_47 , F_41 ) ;
}
T_3 F_46 ( struct V_55 * V_56 , char * V_82 )
{
struct V_2 * V_40 ;
T_3 V_83 = 0 ;
F_47 ( & V_56 -> V_77 ) ;
F_48 (se_sess, &se_tpg->tpg_sess_list, sess_list) {
if ( ! V_40 -> V_57 )
continue;
if ( ! V_40 -> V_57 -> V_84 )
continue;
if ( strlen ( V_40 -> V_57 -> V_85 ) + 1 + V_83 > V_86 )
break;
V_83 += snprintf ( V_82 + V_83 , V_86 - V_83 , L_36 ,
V_40 -> V_57 -> V_85 ) ;
V_83 += 1 ;
}
F_49 ( & V_56 -> V_77 ) ;
return V_83 ;
}
static void F_50 ( struct V_78 * V_78 )
{
struct V_57 * V_87 = F_42 ( V_78 ,
struct V_57 , V_70 ) ;
F_51 ( & V_87 -> V_88 ) ;
}
void F_52 ( struct V_57 * V_87 )
{
F_45 ( & V_87 -> V_70 , F_50 ) ;
}
void F_53 ( struct V_2 * V_40 )
{
struct V_57 * V_58 ;
unsigned long V_76 ;
V_58 = V_40 -> V_57 ;
if ( V_58 ) {
F_39 ( & V_58 -> V_71 , V_76 ) ;
if ( V_58 -> V_89 == 0 )
F_54 ( & V_40 -> V_43 ) ;
if ( F_55 ( & V_58 -> V_73 ) )
V_58 -> V_72 = NULL ;
else {
V_58 -> V_72 = F_42 (
V_58 -> V_73 . V_90 ,
struct V_2 , V_43 ) ;
}
F_40 ( & V_58 -> V_71 , V_76 ) ;
}
}
void F_30 ( struct V_2 * V_40 )
{
if ( V_40 -> V_51 ) {
F_56 ( & V_40 -> V_54 ) ;
if ( F_25 ( V_40 -> V_51 ) )
F_26 ( V_40 -> V_51 ) ;
else
F_27 ( V_40 -> V_51 ) ;
}
F_57 ( V_1 , V_40 ) ;
}
void F_58 ( struct V_2 * V_40 )
{
struct V_55 * V_56 = V_40 -> V_56 ;
const struct V_60 * V_91 ;
struct V_57 * V_58 ;
unsigned long V_76 ;
bool V_92 = true ;
if ( ! V_56 ) {
F_30 ( V_40 ) ;
return;
}
V_91 = V_56 -> V_62 ;
F_39 ( & V_56 -> V_77 , V_76 ) ;
F_54 ( & V_40 -> V_42 ) ;
V_40 -> V_56 = NULL ;
V_40 -> V_59 = NULL ;
F_40 ( & V_56 -> V_77 , V_76 ) ;
V_58 = V_40 -> V_57 ;
F_39 ( & V_56 -> V_93 , V_76 ) ;
if ( V_58 && V_58 -> V_84 ) {
if ( ! V_91 -> V_94 ( V_56 ) ) {
F_54 ( & V_58 -> V_95 ) ;
V_56 -> V_96 -- ;
F_40 ( & V_56 -> V_93 , V_76 ) ;
F_59 ( V_58 ) ;
F_60 ( V_58 , V_56 ) ;
V_91 -> V_97 ( V_56 , V_58 ) ;
V_92 = false ;
F_39 ( & V_56 -> V_93 , V_76 ) ;
}
}
F_40 ( & V_56 -> V_93 , V_76 ) ;
F_37 ( L_37 ,
V_56 -> V_62 -> V_75 () ) ;
if ( V_58 && V_92 )
F_52 ( V_58 ) ;
F_30 ( V_40 ) ;
}
static void F_61 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
unsigned long V_76 ;
if ( ! V_101 )
return;
if ( V_99 -> V_103 & V_104 )
return;
F_39 ( & V_101 -> V_105 , V_76 ) ;
if ( V_99 -> V_106 ) {
F_54 ( & V_99 -> V_107 ) ;
V_99 -> V_106 = false ;
}
F_40 ( & V_101 -> V_105 , V_76 ) ;
}
static int F_62 ( struct V_98 * V_99 , bool V_108 ,
bool V_109 )
{
unsigned long V_76 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
if ( V_109 )
V_99 -> V_111 = V_112 ;
if ( V_108 ) {
F_61 ( V_99 ) ;
V_99 -> V_113 = NULL ;
}
if ( V_99 -> V_103 & V_114 ) {
F_37 ( L_38 ,
V_115 , __LINE__ ,
V_99 -> V_91 -> V_116 ( V_99 ) ) ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_63 ( & V_99 -> V_117 ) ;
return 1 ;
}
V_99 -> V_103 &= ~ V_118 ;
if ( V_108 ) {
if ( V_99 -> V_91 -> V_119 != NULL ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return V_99 -> V_91 -> V_119 ( V_99 ) ;
}
}
F_40 ( & V_99 -> V_110 , V_76 ) ;
return 0 ;
}
static int F_64 ( struct V_98 * V_99 )
{
return F_62 ( V_99 , true , false ) ;
}
static void F_65 ( struct V_98 * V_99 )
{
struct V_113 * V_120 = V_99 -> V_113 ;
if ( ! V_120 )
return;
if ( F_66 ( & V_99 -> V_121 , true , false ) )
F_67 ( & V_120 -> V_122 ) ;
}
void F_68 ( struct V_98 * V_99 , int remove )
{
if ( V_99 -> V_123 & V_124 )
F_65 ( V_99 ) ;
if ( remove )
V_99 -> V_91 -> V_125 ( V_99 ) ;
if ( F_64 ( V_99 ) )
return;
if ( remove )
F_69 ( V_99 ) ;
}
static void F_70 ( struct V_126 * V_127 )
{
struct V_98 * V_99 = F_42 ( V_127 , struct V_98 , V_127 ) ;
F_71 ( V_99 ,
V_128 ) ;
}
static unsigned char * F_72 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
F_73 ( ! V_99 -> V_113 ) ;
if ( ! V_101 )
return NULL ;
if ( V_99 -> V_123 & V_129 )
return NULL ;
V_99 -> V_130 = V_131 ;
F_37 ( L_39 ,
V_101 -> V_132 -> V_133 , V_101 -> V_134 -> V_135 , V_99 -> V_136 ) ;
return V_99 -> V_137 ;
}
void F_74 ( struct V_98 * V_99 , T_4 V_136 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
int V_138 = V_136 == V_139 ;
unsigned long V_76 ;
V_99 -> V_136 = V_136 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
V_99 -> V_103 &= ~ V_104 ;
if ( V_101 && V_101 -> V_134 -> V_140 ) {
V_101 -> V_134 -> V_140 ( V_99 ,
V_99 -> V_141 ,
F_72 ( V_99 ) ) ;
if ( V_99 -> V_123 & V_142 )
V_138 = 1 ;
}
if ( V_99 -> V_103 & V_143 ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_51 ( & V_99 -> V_144 ) ;
return;
}
if ( V_99 -> V_103 & V_145 &&
V_99 -> V_103 & V_114 ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_63 ( & V_99 -> V_117 ) ;
return;
} else if ( ! V_138 ) {
F_75 ( & V_99 -> V_127 , F_70 ) ;
} else {
F_75 ( & V_99 -> V_127 , V_146 ) ;
}
V_99 -> V_111 = V_147 ;
V_99 -> V_103 |= ( V_148 | V_118 ) ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_76 ( V_28 , & V_99 -> V_127 ) ;
}
void F_77 ( struct V_98 * V_99 , T_4 V_136 , int V_149 )
{
if ( V_136 == V_150 && V_149 < V_99 -> V_151 ) {
if ( V_99 -> V_123 & V_152 ) {
V_99 -> V_153 += V_99 -> V_151 - V_149 ;
} else {
V_99 -> V_123 |= V_152 ;
V_99 -> V_153 = V_99 -> V_151 - V_149 ;
}
V_99 -> V_151 = V_149 ;
}
F_74 ( V_99 , V_136 ) ;
}
static void F_78 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
unsigned long V_76 ;
F_39 ( & V_101 -> V_105 , V_76 ) ;
if ( ! V_99 -> V_106 ) {
F_35 ( & V_99 -> V_107 , & V_101 -> V_107 ) ;
V_99 -> V_106 = true ;
}
F_40 ( & V_101 -> V_105 , V_76 ) ;
}
void F_79 ( struct V_126 * V_127 )
{
struct V_100 * V_101 = F_42 ( V_127 , struct V_100 ,
V_154 ) ;
F_80 ( V_155 ) ;
struct V_98 * V_99 , * V_156 ;
F_34 ( & V_101 -> V_157 ) ;
F_81 ( & V_101 -> V_155 , & V_155 ) ;
F_36 ( & V_101 -> V_157 ) ;
F_82 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_54 ( & V_99 -> V_158 ) ;
F_83 ( & V_101 -> V_159 ) ;
F_37 ( L_40
L_41 , V_99 -> V_91 -> V_75 () , V_99 ,
( V_99 -> V_111 == V_160 ) ? L_42 :
( V_99 -> V_111 == V_161 ) ? L_43
: L_44 ) ;
if ( V_99 -> V_111 == V_161 )
F_84 ( V_99 ) ;
else if ( V_99 -> V_111 == V_160 )
F_85 ( V_99 ) ;
}
}
unsigned char * F_86 ( struct V_98 * V_99 )
{
switch ( V_99 -> V_162 ) {
case V_163 :
return L_45 ;
case V_164 :
return L_46 ;
case V_165 :
return L_47 ;
case V_166 :
return L_48 ;
default:
break;
}
return L_44 ;
}
void F_87 (
struct V_100 * V_101 ,
char * V_167 ,
int * V_168 )
{
* V_168 += sprintf ( V_167 + * V_168 , L_49 ) ;
if ( V_101 -> V_169 )
* V_168 += sprintf ( V_167 + * V_168 , L_50 ) ;
else
* V_168 += sprintf ( V_167 + * V_168 , L_51 ) ;
* V_168 += sprintf ( V_167 + * V_168 , L_52 , V_101 -> V_170 ) ;
* V_168 += sprintf ( V_167 + * V_168 , L_53 ,
V_101 -> V_171 . V_172 ,
V_101 -> V_171 . V_173 ) ;
* V_168 += sprintf ( V_167 + * V_168 , L_54 ) ;
}
void F_88 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_63 [ V_178 ] ;
int V_83 ;
memset ( V_63 , 0 , V_178 ) ;
V_83 = sprintf ( V_63 , L_55 ) ;
switch ( V_175 -> V_179 ) {
case 0x00 :
sprintf ( V_63 + V_83 , L_56 ) ;
break;
case 0x10 :
sprintf ( V_63 + V_83 , L_57 ) ;
break;
case 0x20 :
sprintf ( V_63 + V_83 , L_58 ) ;
break;
case 0x30 :
sprintf ( V_63 + V_83 , L_59 ) ;
break;
case 0x40 :
sprintf ( V_63 + V_83 , L_60
L_61 ) ;
break;
case 0x50 :
sprintf ( V_63 + V_83 , L_62 ) ;
break;
case 0x60 :
sprintf ( V_63 + V_83 , L_63 ) ;
break;
case 0x70 :
sprintf ( V_63 + V_83 , L_64
L_61 ) ;
break;
case 0x80 :
sprintf ( V_63 + V_83 , L_65 ) ;
break;
default:
sprintf ( V_63 + V_83 , L_66 ,
V_175 -> V_179 ) ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_63 , V_177 ) ;
else
F_37 ( L_67 , V_63 ) ;
}
void
F_89 ( struct V_174 * V_175 , unsigned char * V_180 )
{
if ( V_180 [ 1 ] & 0x80 ) {
V_175 -> V_179 = ( V_180 [ 0 ] & 0xf0 ) ;
V_175 -> V_181 = 1 ;
F_88 ( V_175 , NULL , 0 ) ;
}
}
int F_90 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_63 [ V_178 ] ;
int V_36 = 0 ;
int V_83 ;
memset ( V_63 , 0 , V_178 ) ;
V_83 = sprintf ( V_63 , L_68 ) ;
switch ( V_175 -> V_182 ) {
case 0x00 :
sprintf ( V_63 + V_83 , L_69 ) ;
break;
case 0x10 :
sprintf ( V_63 + V_83 , L_70 ) ;
break;
case 0x20 :
sprintf ( V_63 + V_83 , L_71 ) ;
break;
default:
sprintf ( V_63 + V_83 , L_66 , V_175 -> V_182 ) ;
V_36 = - V_183 ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_63 , V_177 ) ;
else
F_37 ( L_67 , V_63 ) ;
return V_36 ;
}
int F_91 ( struct V_174 * V_175 , unsigned char * V_180 )
{
V_175 -> V_182 = ( V_180 [ 1 ] & 0x30 ) ;
return F_90 ( V_175 , NULL , 0 ) ;
}
int F_92 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_63 [ V_178 ] ;
int V_36 = 0 ;
int V_83 ;
memset ( V_63 , 0 , V_178 ) ;
V_83 = sprintf ( V_63 , L_72 ) ;
switch ( V_175 -> V_184 ) {
case 0x00 :
sprintf ( V_63 + V_83 , L_73 ) ;
break;
case 0x01 :
sprintf ( V_63 + V_83 , L_74 ) ;
break;
case 0x02 :
sprintf ( V_63 + V_83 , L_75 ) ;
break;
case 0x03 :
sprintf ( V_63 + V_83 , L_76 ) ;
break;
case 0x04 :
sprintf ( V_63 + V_83 , L_77 ) ;
break;
case 0x08 :
sprintf ( V_63 + V_83 , L_78 ) ;
break;
default:
sprintf ( V_63 + V_83 , L_79 ,
V_175 -> V_184 ) ;
V_36 = - V_183 ;
break;
}
if ( V_176 ) {
if ( V_177 < strlen ( V_63 ) + 1 )
return - V_183 ;
strncpy ( V_176 , V_63 , V_177 ) ;
} else {
F_37 ( L_67 , V_63 ) ;
}
return V_36 ;
}
int F_93 ( struct V_174 * V_175 , unsigned char * V_180 )
{
V_175 -> V_184 = ( V_180 [ 1 ] & 0x0f ) ;
return F_92 ( V_175 , NULL , 0 ) ;
}
int F_94 (
struct V_174 * V_175 ,
unsigned char * V_176 ,
int V_177 )
{
unsigned char V_63 [ V_178 ] ;
int V_36 = 0 ;
memset ( V_63 , 0 , V_178 ) ;
switch ( V_175 -> V_185 ) {
case 0x01 :
snprintf ( V_63 , sizeof( V_63 ) ,
L_80 ,
& V_175 -> V_186 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_63 , sizeof( V_63 ) ,
L_81 ,
& V_175 -> V_186 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_63 , sizeof( V_63 ) ,
L_82 ,
& V_175 -> V_186 [ 0 ] ) ;
break;
default:
sprintf ( V_63 , L_83
L_84 , V_175 -> V_185 ) ;
V_36 = - V_183 ;
break;
}
if ( V_176 )
strncpy ( V_176 , V_63 , V_177 ) ;
else
F_37 ( L_67 , V_63 ) ;
return V_36 ;
}
int
F_95 ( struct V_174 * V_175 , unsigned char * V_180 )
{
static const char V_187 [] = L_85 ;
int V_188 = 0 , V_189 = 4 ;
V_175 -> V_185 = ( V_180 [ 0 ] & 0x0f ) ;
switch ( V_175 -> V_185 ) {
case 0x01 :
V_175 -> V_186 [ V_188 ++ ] =
V_187 [ V_175 -> V_184 ] ;
while ( V_189 < ( 4 + V_180 [ 3 ] ) ) {
V_175 -> V_186 [ V_188 ++ ] =
V_187 [ ( V_180 [ V_189 ] & 0xf0 ) >> 4 ] ;
V_175 -> V_186 [ V_188 ++ ] =
V_187 [ V_180 [ V_189 ] & 0x0f ] ;
V_189 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_189 < ( 4 + V_180 [ 3 ] ) )
V_175 -> V_186 [ V_188 ++ ] = V_180 [ V_189 ++ ] ;
break;
default:
break;
}
return F_94 ( V_175 , NULL , 0 ) ;
}
T_5
F_96 ( struct V_98 * V_99 , unsigned int V_190 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
if ( V_99 -> V_191 ) {
V_99 -> V_151 = V_190 ;
} else if ( V_190 != V_99 -> V_151 ) {
F_97 ( L_86
L_87
L_88 , V_99 -> V_91 -> V_75 () ,
V_99 -> V_151 , V_190 , V_99 -> V_192 [ 0 ] ) ;
if ( V_99 -> V_162 == V_165 ) {
F_4 ( L_89
L_90 ) ;
return V_193 ;
}
if ( V_101 -> V_171 . V_172 != 512 ) {
F_4 ( L_91
L_92
L_93 , V_101 -> V_134 -> V_135 ) ;
return V_193 ;
}
if ( V_190 > V_99 -> V_151 ) {
V_99 -> V_123 |= V_194 ;
V_99 -> V_153 = ( V_190 - V_99 -> V_151 ) ;
} else {
V_99 -> V_123 |= V_152 ;
V_99 -> V_153 = ( V_99 -> V_151 - V_190 ) ;
V_99 -> V_151 = V_190 ;
}
}
return 0 ;
}
void F_98 (
struct V_98 * V_99 ,
const struct V_60 * V_61 ,
struct V_2 * V_40 ,
T_1 V_151 ,
int V_162 ,
int V_195 ,
unsigned char * V_137 )
{
F_18 ( & V_99 -> V_196 ) ;
F_18 ( & V_99 -> V_158 ) ;
F_18 ( & V_99 -> V_197 ) ;
F_18 ( & V_99 -> V_107 ) ;
F_99 ( & V_99 -> V_117 ) ;
F_99 ( & V_99 -> V_198 ) ;
F_99 ( & V_99 -> V_144 ) ;
F_19 ( & V_99 -> V_110 ) ;
F_20 ( & V_99 -> V_199 ) ;
V_99 -> V_103 = V_200 ;
V_99 -> V_91 = V_61 ;
V_99 -> V_40 = V_40 ;
V_99 -> V_151 = V_151 ;
V_99 -> V_162 = V_162 ;
V_99 -> V_201 = V_195 ;
V_99 -> V_137 = V_137 ;
V_99 -> V_106 = false ;
}
static T_5
F_100 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
if ( V_101 -> V_134 -> V_202 & V_203 )
return 0 ;
if ( V_99 -> V_201 == V_204 ) {
F_37 ( L_94
L_95 ) ;
return V_193 ;
}
V_99 -> V_205 = F_101 ( & V_101 -> V_206 ) ;
F_37 ( L_96 ,
V_99 -> V_205 , V_99 -> V_201 ,
V_101 -> V_134 -> V_135 ) ;
return 0 ;
}
T_5
F_102 ( struct V_98 * V_99 , unsigned char * V_207 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
T_5 V_36 ;
if ( F_103 ( V_207 ) > V_208 ) {
F_4 ( L_97
L_98 ,
F_103 ( V_207 ) , V_208 ) ;
return V_193 ;
}
if ( F_103 ( V_207 ) > sizeof( V_99 -> V_209 ) ) {
V_99 -> V_192 = F_22 ( F_103 ( V_207 ) ,
V_41 ) ;
if ( ! V_99 -> V_192 ) {
F_4 ( L_99
L_100 ,
F_103 ( V_207 ) ,
( unsigned long ) sizeof( V_99 -> V_209 ) ) ;
return V_210 ;
}
} else
V_99 -> V_192 = & V_99 -> V_209 [ 0 ] ;
memcpy ( V_99 -> V_192 , V_207 , F_103 ( V_207 ) ) ;
F_104 ( V_99 ) ;
V_36 = F_105 ( V_99 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_106 ( V_99 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_107 ( V_99 ) ;
if ( V_36 ) {
V_99 -> V_136 = V_211 ;
return V_36 ;
}
V_36 = V_101 -> V_134 -> V_212 ( V_99 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_100 ( V_99 ) ;
if ( V_36 )
return V_36 ;
V_99 -> V_123 |= V_213 ;
F_11 ( & V_99 -> V_113 -> V_214 ) ;
if ( V_99 -> V_113 -> V_215 )
V_99 -> V_113 -> V_215 -> V_216 . V_217 ++ ;
F_12 ( & V_99 -> V_113 -> V_214 ) ;
return 0 ;
}
int F_108 (
struct V_98 * V_99 )
{
T_5 V_36 ;
if ( ! V_99 -> V_113 ) {
F_109 () ;
F_4 ( L_101 ) ;
return - V_183 ;
}
if ( F_110 () ) {
F_109 () ;
F_4 ( L_102
L_103 ) ;
return - V_183 ;
}
V_99 -> V_111 = V_218 ;
V_99 -> V_103 |= V_118 ;
V_36 = F_111 ( V_99 ) ;
if ( V_36 )
F_71 ( V_99 , V_36 ) ;
return 0 ;
}
T_5
F_112 ( struct V_98 * V_99 , struct V_219 * V_220 ,
T_1 V_221 , struct V_219 * V_222 , T_1 V_223 )
{
if ( ! V_220 || ! V_221 )
return 0 ;
if ( V_99 -> V_123 & V_194 ) {
F_97 ( L_104
L_105 ) ;
return V_193 ;
}
V_99 -> V_141 = V_220 ;
V_99 -> V_224 = V_221 ;
if ( V_222 && V_223 ) {
V_99 -> V_225 = V_222 ;
V_99 -> V_226 = V_223 ;
}
V_99 -> V_123 |= V_227 ;
return 0 ;
}
int F_113 ( struct V_98 * V_98 , struct V_2 * V_40 ,
unsigned char * V_207 , unsigned char * V_228 , T_1 V_229 ,
T_1 V_151 , int V_195 , int V_230 , int V_76 ,
struct V_219 * V_220 , T_1 V_221 ,
struct V_219 * V_222 , T_1 V_223 ,
struct V_219 * V_231 , T_1 V_232 )
{
struct V_55 * V_56 ;
T_5 V_50 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_10 ( V_98 -> V_91 || V_98 -> V_40 ) ;
F_10 ( F_110 () ) ;
F_98 ( V_98 , V_56 -> V_62 , V_40 ,
V_151 , V_230 , V_195 , V_228 ) ;
if ( V_76 & V_233 )
V_98 -> V_191 = 1 ;
V_36 = F_114 ( V_40 , V_98 , ( V_76 & V_234 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_76 & V_235 )
V_98 -> V_123 |= V_236 ;
V_50 = F_115 ( V_98 , V_229 ) ;
if ( V_50 ) {
F_116 ( V_98 , V_50 , 0 ) ;
F_117 ( V_40 , V_98 ) ;
return 0 ;
}
V_50 = F_102 ( V_98 , V_207 ) ;
if ( V_50 != 0 ) {
F_71 ( V_98 , V_50 ) ;
return 0 ;
}
if ( V_232 ) {
V_98 -> V_237 = V_231 ;
V_98 -> V_238 = V_232 ;
}
if ( V_221 != 0 ) {
F_10 ( ! V_220 ) ;
if ( ! ( V_98 -> V_123 & V_239 ) &&
V_98 -> V_162 == V_164 ) {
unsigned char * V_63 = NULL ;
if ( V_220 )
V_63 = F_118 ( F_119 ( V_220 ) ) + V_220 -> V_240 ;
if ( V_63 ) {
memset ( V_63 , 0 , V_220 -> V_149 ) ;
F_120 ( F_119 ( V_220 ) ) ;
}
}
V_50 = F_112 ( V_98 , V_220 , V_221 ,
V_222 , V_223 ) ;
if ( V_50 != 0 ) {
F_71 ( V_98 , V_50 ) ;
return 0 ;
}
}
F_121 ( V_98 ) ;
F_108 ( V_98 ) ;
return 0 ;
}
int F_122 ( struct V_98 * V_98 , struct V_2 * V_40 ,
unsigned char * V_207 , unsigned char * V_228 , T_1 V_229 ,
T_1 V_151 , int V_195 , int V_230 , int V_76 )
{
return F_113 ( V_98 , V_40 , V_207 , V_228 ,
V_229 , V_151 , V_195 , V_230 ,
V_76 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_123 ( struct V_126 * V_127 )
{
struct V_98 * V_98 = F_42 ( V_127 , struct V_98 , V_127 ) ;
V_98 -> V_241 -> V_242 = V_243 ;
V_98 -> V_91 -> V_244 ( V_98 ) ;
F_64 ( V_98 ) ;
}
int F_124 ( struct V_98 * V_98 , struct V_2 * V_40 ,
unsigned char * V_228 , T_1 V_229 ,
void * V_245 , unsigned char V_246 ,
T_6 V_247 , unsigned int V_248 , int V_76 )
{
struct V_55 * V_56 ;
int V_36 ;
V_56 = V_40 -> V_56 ;
F_10 ( ! V_56 ) ;
F_98 ( V_98 , V_56 -> V_62 , V_40 ,
0 , V_163 , V_249 , V_228 ) ;
V_36 = F_125 ( V_98 , V_245 , V_246 , V_247 ) ;
if ( V_36 < 0 )
return - V_31 ;
if ( V_246 == V_250 )
V_98 -> V_241 -> V_251 = V_248 ;
V_36 = F_114 ( V_40 , V_98 , ( V_76 & V_234 ) ) ;
if ( V_36 ) {
F_126 ( V_98 -> V_241 ) ;
return V_36 ;
}
V_36 = F_127 ( V_98 , V_229 ) ;
if ( V_36 ) {
F_75 ( & V_98 -> V_127 , F_123 ) ;
F_128 ( & V_98 -> V_127 ) ;
return 0 ;
}
F_129 ( V_98 ) ;
return 0 ;
}
bool F_130 ( struct V_98 * V_99 , unsigned long * V_76 )
__releases( &cmd->t_state_lock
void F_71 ( struct V_98 * V_99 ,
T_5 V_252 )
{
int V_36 = 0 ;
F_37 ( L_106
L_107 , V_99 , V_99 -> V_91 -> V_116 ( V_99 ) ,
V_99 -> V_192 [ 0 ] ) ;
F_37 ( L_108 ,
V_99 -> V_91 -> V_253 ( V_99 ) ,
V_99 -> V_111 , V_252 ) ;
F_37 ( L_109 ,
( V_99 -> V_103 & V_118 ) != 0 ,
( V_99 -> V_103 & V_114 ) != 0 ,
( V_99 -> V_103 & V_254 ) != 0 ) ;
F_131 ( V_99 ) ;
if ( ( V_99 -> V_123 & V_255 ) &&
V_99 -> V_256 )
V_99 -> V_256 ( V_99 , false ) ;
switch ( V_252 ) {
case V_257 :
case V_258 :
case V_193 :
case V_259 :
case V_260 :
case V_128 :
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
V_252 = V_128 ;
break;
case V_270 :
V_99 -> V_136 = V_211 ;
if ( V_99 -> V_40 &&
V_99 -> V_102 -> V_171 . V_271 == 2 )
F_132 ( V_99 -> V_40 -> V_57 ,
V_99 -> V_272 , 0x2C ,
V_273 ) ;
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_274 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
goto V_277;
default:
F_4 ( L_110 ,
V_99 -> V_192 [ 0 ] , V_252 ) ;
V_252 = V_258 ;
break;
}
V_36 = F_116 ( V_99 , V_252 , 0 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
V_277:
F_65 ( V_99 ) ;
if ( ! F_64 ( V_99 ) )
;
return;
V_276:
V_99 -> V_111 = V_160 ;
F_134 ( V_99 , V_99 -> V_102 ) ;
}
void F_135 ( struct V_98 * V_99 )
{
T_5 V_36 ;
if ( V_99 -> V_278 ) {
V_36 = V_99 -> V_278 ( V_99 ) ;
if ( V_36 ) {
F_34 ( & V_99 -> V_110 ) ;
V_99 -> V_103 &= ~ ( V_104 | V_254 ) ;
F_36 ( & V_99 -> V_110 ) ;
F_71 ( V_99 , V_36 ) ;
}
}
}
static int F_136 ( struct V_98 * V_99 )
{
T_1 V_279 ;
switch ( V_99 -> V_280 ) {
case V_281 :
if ( ! ( V_99 -> V_40 -> V_39 & V_281 ) )
F_137 ( V_99 ) ;
break;
case V_282 :
if ( V_99 -> V_40 -> V_39 & V_282 )
break;
V_279 = V_99 -> V_151 >> F_138 ( V_99 -> V_102 -> V_171 . V_172 ) ;
V_99 -> V_283 = F_139 ( V_99 , V_99 -> V_284 ,
V_279 , 0 , NULL , 0 ) ;
if ( F_140 ( V_99 -> V_283 ) ) {
F_34 ( & V_99 -> V_110 ) ;
V_99 -> V_103 &= ~ ( V_104 | V_254 ) ;
F_36 ( & V_99 -> V_110 ) ;
F_71 ( V_99 , V_99 -> V_283 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_141 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
if ( V_101 -> V_134 -> V_202 & V_203 )
return false ;
switch ( V_99 -> V_201 ) {
case V_285 :
F_37 ( L_111
L_112 ,
V_99 -> V_192 [ 0 ] , V_99 -> V_205 ) ;
return false ;
case V_286 :
F_142 ( & V_101 -> V_287 ) ;
F_37 ( L_113
L_114 ,
V_99 -> V_192 [ 0 ] , V_99 -> V_205 ) ;
if ( ! F_143 ( & V_101 -> V_288 ) )
return false ;
break;
default:
F_142 ( & V_101 -> V_288 ) ;
break;
}
if ( F_143 ( & V_101 -> V_287 ) == 0 )
return false ;
F_11 ( & V_101 -> V_289 ) ;
F_35 ( & V_99 -> V_196 , & V_101 -> V_290 ) ;
F_12 ( & V_101 -> V_289 ) ;
F_37 ( L_115
L_116 ,
V_99 -> V_192 [ 0 ] , V_99 -> V_201 ,
V_99 -> V_205 ) ;
return true ;
}
void F_144 ( struct V_98 * V_99 )
{
if ( F_145 ( V_99 , 1 ) )
return;
F_34 ( & V_99 -> V_110 ) ;
if ( V_99 -> V_103 & V_114 ) {
F_37 ( L_38 ,
V_115 , __LINE__ ,
V_99 -> V_91 -> V_116 ( V_99 ) ) ;
F_36 ( & V_99 -> V_110 ) ;
F_63 ( & V_99 -> V_117 ) ;
return;
}
V_99 -> V_111 = V_291 ;
V_99 -> V_103 |= V_118 | V_104 | V_254 ;
F_36 ( & V_99 -> V_110 ) ;
if ( F_136 ( V_99 ) )
return;
if ( F_141 ( V_99 ) ) {
F_34 ( & V_99 -> V_110 ) ;
V_99 -> V_103 &= ~ ( V_104 | V_254 ) ;
F_36 ( & V_99 -> V_110 ) ;
return;
}
F_135 ( V_99 ) ;
}
static void F_146 ( struct V_100 * V_101 )
{
for (; ; ) {
struct V_98 * V_99 ;
F_11 ( & V_101 -> V_289 ) ;
if ( F_55 ( & V_101 -> V_290 ) ) {
F_12 ( & V_101 -> V_289 ) ;
break;
}
V_99 = F_147 ( V_101 -> V_290 . V_292 ,
struct V_98 , V_196 ) ;
F_54 ( & V_99 -> V_196 ) ;
F_12 ( & V_101 -> V_289 ) ;
F_135 ( V_99 ) ;
if ( V_99 -> V_201 == V_286 )
break;
}
}
static void F_131 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
if ( V_101 -> V_134 -> V_202 & V_203 )
return;
if ( V_99 -> V_201 == V_249 ) {
F_83 ( & V_101 -> V_288 ) ;
V_101 -> V_293 ++ ;
F_37 ( L_117
L_118 , V_101 -> V_293 ,
V_99 -> V_205 ) ;
} else if ( V_99 -> V_201 == V_285 ) {
V_101 -> V_293 ++ ;
F_37 ( L_119
L_120 , V_101 -> V_293 ,
V_99 -> V_205 ) ;
} else if ( V_99 -> V_201 == V_286 ) {
F_83 ( & V_101 -> V_287 ) ;
V_101 -> V_293 ++ ;
F_37 ( L_121
L_122 , V_101 -> V_293 , V_99 -> V_205 ) ;
}
F_146 ( V_101 ) ;
}
static void F_85 ( struct V_98 * V_99 )
{
int V_36 = 0 ;
F_131 ( V_99 ) ;
if ( V_99 -> V_123 & V_142 ) {
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_274 ( V_99 ) ;
goto V_3;
}
switch ( V_99 -> V_162 ) {
case V_164 :
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_294 ( V_99 ) ;
break;
case V_165 :
if ( V_99 -> V_123 & V_236 ) {
V_36 = V_99 -> V_91 -> V_294 ( V_99 ) ;
break;
}
case V_163 :
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_274 ( V_99 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_134 ( V_99 , V_99 -> V_102 ) ;
return;
}
F_65 ( V_99 ) ;
F_64 ( V_99 ) ;
}
static void F_134 (
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
F_34 ( & V_101 -> V_157 ) ;
F_35 ( & V_99 -> V_158 , & V_99 -> V_102 -> V_155 ) ;
F_142 ( & V_101 -> V_159 ) ;
F_36 ( & V_99 -> V_102 -> V_157 ) ;
F_128 ( & V_99 -> V_102 -> V_154 ) ;
}
static bool F_148 ( struct V_98 * V_99 )
{
T_5 V_50 ;
switch ( V_99 -> V_280 ) {
case V_295 :
if ( ! ( V_99 -> V_40 -> V_39 & V_295 ) ) {
V_50 = F_149 ( V_99 ) ;
if ( V_50 ) {
V_99 -> V_283 = V_50 ;
return true ;
}
}
break;
case V_296 :
if ( V_99 -> V_40 -> V_39 & V_296 )
break;
F_137 ( V_99 ) ;
break;
default:
break;
}
return false ;
}
static void V_146 ( struct V_126 * V_127 )
{
struct V_98 * V_99 = F_42 ( V_127 , struct V_98 , V_127 ) ;
int V_36 ;
F_131 ( V_99 ) ;
if ( F_143 ( & V_99 -> V_102 -> V_159 ) != 0 )
F_128 ( & V_99 -> V_102 -> V_154 ) ;
if ( V_99 -> V_123 & V_142 ) {
F_73 ( ! V_99 -> V_136 ) ;
V_36 = F_116 (
V_99 , 0 , 1 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
F_65 ( V_99 ) ;
F_64 ( V_99 ) ;
return;
}
if ( V_99 -> V_256 ) {
T_5 V_50 ;
V_50 = V_99 -> V_256 ( V_99 , true ) ;
if ( ! V_50 && ! ( V_99 -> V_123 & V_297 ) ) {
if ( ( V_99 -> V_123 & V_255 ) &&
! V_99 -> V_151 )
goto V_298;
return;
} else if ( V_50 ) {
V_36 = F_116 ( V_99 ,
V_50 , 0 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
F_65 ( V_99 ) ;
F_64 ( V_99 ) ;
return;
}
}
V_298:
switch ( V_99 -> V_162 ) {
case V_164 :
F_11 ( & V_99 -> V_113 -> V_214 ) ;
if ( V_99 -> V_113 -> V_215 ) {
V_99 -> V_113 -> V_215 -> V_216 . V_299 +=
V_99 -> V_151 ;
}
F_12 ( & V_99 -> V_113 -> V_214 ) ;
if ( F_148 ( V_99 ) ) {
V_36 = F_116 ( V_99 ,
V_99 -> V_283 , 0 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
F_65 ( V_99 ) ;
F_64 ( V_99 ) ;
return;
}
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_294 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
break;
case V_165 :
F_11 ( & V_99 -> V_113 -> V_214 ) ;
if ( V_99 -> V_113 -> V_215 ) {
V_99 -> V_113 -> V_215 -> V_216 . V_300 +=
V_99 -> V_151 ;
}
F_12 ( & V_99 -> V_113 -> V_214 ) ;
if ( V_99 -> V_123 & V_236 ) {
F_11 ( & V_99 -> V_113 -> V_214 ) ;
if ( V_99 -> V_113 -> V_215 ) {
V_99 -> V_113 -> V_215 -> V_216 . V_299 +=
V_99 -> V_151 ;
}
F_12 ( & V_99 -> V_113 -> V_214 ) ;
V_36 = V_99 -> V_91 -> V_294 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
break;
}
case V_163 :
F_133 ( V_99 ) ;
V_36 = V_99 -> V_91 -> V_274 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
break;
default:
break;
}
F_65 ( V_99 ) ;
F_64 ( V_99 ) ;
return;
V_276:
F_37 ( L_123
L_124 , V_99 , V_99 -> V_162 ) ;
V_99 -> V_111 = V_160 ;
F_134 ( V_99 , V_99 -> V_102 ) ;
}
static inline void F_150 ( struct V_219 * V_220 , int V_301 )
{
struct V_219 * V_302 ;
int V_303 ;
F_151 (sgl, sg, nents, count)
F_152 ( F_119 ( V_302 ) ) ;
F_27 ( V_220 ) ;
}
static inline void F_153 ( struct V_98 * V_99 )
{
if ( ! V_99 -> V_304 )
return;
F_27 ( V_99 -> V_141 ) ;
V_99 -> V_141 = V_99 -> V_304 ;
V_99 -> V_304 = NULL ;
V_99 -> V_224 = V_99 -> V_305 ;
V_99 -> V_305 = 0 ;
}
static inline void F_154 ( struct V_98 * V_99 )
{
if ( V_99 -> V_123 & V_227 ) {
if ( V_99 -> V_123 & V_255 ) {
F_150 ( V_99 -> V_225 ,
V_99 -> V_226 ) ;
V_99 -> V_225 = NULL ;
V_99 -> V_226 = 0 ;
}
F_153 ( V_99 ) ;
return;
}
F_153 ( V_99 ) ;
F_150 ( V_99 -> V_141 , V_99 -> V_224 ) ;
V_99 -> V_141 = NULL ;
V_99 -> V_224 = 0 ;
F_150 ( V_99 -> V_225 , V_99 -> V_226 ) ;
V_99 -> V_225 = NULL ;
V_99 -> V_226 = 0 ;
F_150 ( V_99 -> V_237 , V_99 -> V_238 ) ;
V_99 -> V_237 = NULL ;
V_99 -> V_238 = 0 ;
}
static int F_155 ( struct V_98 * V_99 )
{
F_10 ( ! V_99 -> V_91 ) ;
if ( V_99 -> V_123 & V_306 )
F_126 ( V_99 -> V_241 ) ;
if ( V_99 -> V_192 != V_99 -> V_209 )
F_27 ( V_99 -> V_192 ) ;
return F_117 ( V_99 -> V_40 , V_99 ) ;
}
static int F_69 ( struct V_98 * V_99 )
{
F_154 ( V_99 ) ;
return F_155 ( V_99 ) ;
}
void * F_156 ( struct V_98 * V_99 )
{
struct V_219 * V_302 = V_99 -> V_141 ;
struct V_82 * * V_307 ;
int V_189 ;
if ( ! V_99 -> V_224 )
return NULL ;
F_10 ( ! V_302 ) ;
if ( V_99 -> V_224 == 1 )
return F_118 ( F_119 ( V_302 ) ) + V_302 -> V_240 ;
V_307 = F_157 ( sizeof( * V_307 ) * V_99 -> V_224 , V_41 ) ;
if ( ! V_307 )
return NULL ;
F_151 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_307 [ V_189 ] = F_119 ( V_302 ) ;
}
V_99 -> V_308 = F_158 ( V_307 , V_99 -> V_224 , V_309 , V_310 ) ;
F_27 ( V_307 ) ;
if ( ! V_99 -> V_308 )
return NULL ;
return V_99 -> V_308 + V_99 -> V_141 [ 0 ] . V_240 ;
}
void F_159 ( struct V_98 * V_99 )
{
if ( ! V_99 -> V_224 ) {
return;
} else if ( V_99 -> V_224 == 1 ) {
F_120 ( F_119 ( V_99 -> V_141 ) ) ;
return;
}
F_160 ( V_99 -> V_308 ) ;
V_99 -> V_308 = NULL ;
}
int
F_161 ( struct V_219 * * V_220 , unsigned int * V_301 , T_1 V_149 ,
bool V_311 )
{
struct V_219 * V_302 ;
struct V_82 * V_82 ;
T_6 V_312 = ( V_311 ) ? V_313 : 0 ;
unsigned int V_314 ;
int V_189 = 0 ;
V_314 = F_162 ( V_149 , V_86 ) ;
V_302 = F_157 ( sizeof( struct V_219 ) * V_314 , V_41 ) ;
if ( ! V_302 )
return - V_31 ;
F_163 ( V_302 , V_314 ) ;
while ( V_149 ) {
T_1 V_315 = F_164 ( T_1 , V_149 , V_86 ) ;
V_82 = F_165 ( V_41 | V_312 ) ;
if ( ! V_82 )
goto V_3;
F_166 ( & V_302 [ V_189 ] , V_82 , V_315 , 0 ) ;
V_149 -= V_315 ;
V_189 ++ ;
}
* V_220 = V_302 ;
* V_301 = V_314 ;
return 0 ;
V_3:
while ( V_189 > 0 ) {
V_189 -- ;
F_152 ( F_119 ( & V_302 [ V_189 ] ) ) ;
}
F_27 ( V_302 ) ;
return - V_31 ;
}
T_5
F_111 ( struct V_98 * V_99 )
{
int V_36 = 0 ;
bool V_312 = ! ( V_99 -> V_123 & V_239 ) ;
if ( ! ( V_99 -> V_123 & V_227 ) &&
V_99 -> V_151 ) {
if ( ( V_99 -> V_123 & V_236 ) ||
( V_99 -> V_123 & V_255 ) ) {
T_1 V_316 ;
if ( V_99 -> V_123 & V_255 )
V_316 = V_99 -> V_317 *
V_99 -> V_102 -> V_171 . V_172 ;
else
V_316 = V_99 -> V_151 ;
V_36 = F_161 ( & V_99 -> V_225 ,
& V_99 -> V_226 ,
V_316 , V_312 ) ;
if ( V_36 < 0 )
return V_128 ;
}
if ( V_99 -> V_280 != V_318 ) {
V_36 = F_161 ( & V_99 -> V_237 ,
& V_99 -> V_238 ,
V_99 -> V_319 , true ) ;
if ( V_36 < 0 )
return V_128 ;
}
V_36 = F_161 ( & V_99 -> V_141 , & V_99 -> V_224 ,
V_99 -> V_151 , V_312 ) ;
if ( V_36 < 0 )
return V_128 ;
} else if ( ( V_99 -> V_123 & V_255 ) &&
V_99 -> V_151 ) {
T_1 V_320 = V_99 -> V_317 *
V_99 -> V_102 -> V_171 . V_172 ;
V_36 = F_161 ( & V_99 -> V_225 ,
& V_99 -> V_226 ,
V_320 , V_312 ) ;
if ( V_36 < 0 )
return V_128 ;
}
F_78 ( V_99 ) ;
if ( V_99 -> V_162 != V_165 || V_99 -> V_151 == 0 ) {
F_144 ( V_99 ) ;
return 0 ;
}
F_62 ( V_99 , false , true ) ;
V_36 = V_99 -> V_91 -> V_109 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 )
goto V_276;
F_73 ( V_36 ) ;
return ( ! V_36 ) ? 0 : V_128 ;
V_276:
F_37 ( L_125 , V_99 ) ;
V_99 -> V_111 = V_161 ;
F_134 ( V_99 , V_99 -> V_102 ) ;
return 0 ;
}
static void F_84 ( struct V_98 * V_99 )
{
int V_36 ;
V_36 = V_99 -> V_91 -> V_109 ( V_99 ) ;
if ( V_36 == - V_275 || V_36 == - V_31 ) {
F_37 ( L_125 ,
V_99 ) ;
F_134 ( V_99 , V_99 -> V_102 ) ;
}
}
int F_167 ( struct V_98 * V_99 , int V_321 )
{
unsigned long V_76 ;
int V_36 = 0 ;
if ( ! ( V_99 -> V_123 & V_124 ) ) {
if ( V_321 && ( V_99 -> V_123 & V_306 ) )
F_168 ( V_99 ) ;
V_36 = F_155 ( V_99 ) ;
} else {
if ( V_321 )
F_168 ( V_99 ) ;
if ( V_99 -> V_106 ) {
F_39 ( & V_99 -> V_110 , V_76 ) ;
F_61 ( V_99 ) ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
}
if ( V_99 -> V_113 )
F_65 ( V_99 ) ;
V_36 = F_69 ( V_99 ) ;
}
return V_36 ;
}
int F_114 ( struct V_2 * V_40 , struct V_98 * V_98 ,
bool V_322 )
{
unsigned long V_76 ;
int V_36 = 0 ;
if ( V_322 )
F_33 ( & V_98 -> V_199 ) ;
F_39 ( & V_40 -> V_46 , V_76 ) ;
if ( V_40 -> V_323 ) {
V_36 = - V_324 ;
goto V_3;
}
F_35 ( & V_98 -> V_197 , & V_40 -> V_44 ) ;
V_3:
F_40 ( & V_40 -> V_46 , V_76 ) ;
if ( V_36 && V_322 )
F_117 ( V_40 , V_98 ) ;
return V_36 ;
}
static void F_169 ( struct V_78 * V_78 )
__releases( &se_cmd->se_sess->sess_cmd_lock
int F_117 ( struct V_2 * V_40 , struct V_98 * V_98 )
{
if ( ! V_40 ) {
V_98 -> V_91 -> V_325 ( V_98 ) ;
return 1 ;
}
return F_170 ( & V_98 -> V_199 , F_169 ,
& V_40 -> V_46 ) ;
}
void F_171 ( struct V_2 * V_40 )
{
struct V_98 * V_98 ;
unsigned long V_76 ;
F_39 ( & V_40 -> V_46 , V_76 ) ;
if ( V_40 -> V_323 ) {
F_40 ( & V_40 -> V_46 , V_76 ) ;
return;
}
V_40 -> V_323 = 1 ;
F_81 ( & V_40 -> V_44 , & V_40 -> V_45 ) ;
F_48 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_98 -> V_326 = 1 ;
F_40 ( & V_40 -> V_46 , V_76 ) ;
}
void F_172 ( struct V_2 * V_40 )
{
struct V_98 * V_98 , * V_327 ;
unsigned long V_76 ;
F_82 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_54 ( & V_98 -> V_197 ) ;
F_37 ( L_126
L_127 , V_98 , V_98 -> V_111 ,
V_98 -> V_91 -> V_253 ( V_98 ) ) ;
F_173 ( & V_98 -> V_198 ) ;
F_37 ( L_128
L_129 , V_98 , V_98 -> V_111 ,
V_98 -> V_91 -> V_253 ( V_98 ) ) ;
V_98 -> V_91 -> V_325 ( V_98 ) ;
}
F_39 ( & V_40 -> V_46 , V_76 ) ;
F_73 ( ! F_55 ( & V_40 -> V_44 ) ) ;
F_40 ( & V_40 -> V_46 , V_76 ) ;
}
static int F_174 ( void * V_328 )
{
struct V_113 * V_120 = V_328 ;
F_175 ( & V_120 -> V_122 ) ;
F_173 ( & V_120 -> V_329 ) ;
F_51 ( & V_120 -> V_330 ) ;
return 0 ;
}
int F_176 ( struct V_113 * V_120 )
{
struct V_331 * V_332 ;
V_332 = F_177 ( F_174 , V_120 ,
L_130 , V_120 -> V_229 ) ;
if ( F_29 ( V_332 ) ) {
F_4 ( L_131 ) ;
return F_178 ( V_332 ) ;
}
F_173 ( & V_120 -> V_330 ) ;
return 0 ;
}
bool F_168 ( struct V_98 * V_99 )
{
unsigned long V_76 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
if ( ! ( V_99 -> V_123 & V_124 ) &&
! ( V_99 -> V_123 & V_306 ) ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return false ;
}
if ( ! ( V_99 -> V_123 & V_213 ) &&
! ( V_99 -> V_123 & V_306 ) ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return false ;
}
if ( ! ( V_99 -> V_103 & V_118 ) ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return false ;
}
V_99 -> V_103 |= V_114 ;
F_37 ( L_132
L_133 ,
V_99 , V_99 -> V_91 -> V_116 ( V_99 ) ,
V_99 -> V_91 -> V_253 ( V_99 ) , V_99 -> V_111 ) ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_173 ( & V_99 -> V_117 ) ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
V_99 -> V_103 &= ~ ( V_118 | V_114 ) ;
F_37 ( L_134
L_135 ,
V_99 -> V_91 -> V_116 ( V_99 ) ) ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
return true ;
}
static int F_179 (
struct V_98 * V_99 ,
T_4 * V_333 ,
T_4 * V_334 )
{
* V_333 = V_99 -> V_335 ;
* V_334 = V_99 -> V_336 ;
return 0 ;
}
static
void F_180 ( unsigned char * V_337 , T_7 V_338 )
{
V_337 [ V_339 ] = 0xc ;
V_337 [ V_340 ] = 0 ;
V_337 [ V_341 ] = 0xa ;
V_337 [ V_342 ] = 0x80 ;
F_181 ( V_338 , & V_337 [ 12 ] ) ;
}
int
F_116 ( struct V_98 * V_99 ,
T_5 V_343 , int V_344 )
{
unsigned char * V_337 = V_99 -> V_137 ;
unsigned long V_76 ;
T_4 V_333 = 0 , V_334 = 0 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
if ( V_99 -> V_123 & V_129 ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return 0 ;
}
V_99 -> V_123 |= V_129 ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
if ( ! V_343 && V_344 )
goto V_345;
if ( ! V_344 )
V_99 -> V_123 |= V_346 ;
switch ( V_343 ) {
case V_347 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_349 ;
V_337 [ V_350 ] = 0 ;
V_337 [ V_351 ] = 0 ;
break;
case V_257 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x25 ;
break;
case V_258 :
case V_353 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x20 ;
break;
case V_261 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x24 ;
break;
case V_264 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_354 ;
V_337 [ V_350 ] = 0x29 ;
V_337 [ V_351 ] = 0x03 ;
break;
case V_355 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_354 ;
V_337 [ V_350 ] = 0x0c ;
V_337 [ V_351 ] = 0x0d ;
break;
case V_193 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x24 ;
break;
case V_259 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x26 ;
break;
case V_260 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x1a ;
break;
case V_356 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_354 ;
V_337 [ V_350 ] = 0x0c ;
V_337 [ V_351 ] = 0x0c ;
break;
case V_357 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_354 ;
V_337 [ V_350 ] = 0x47 ;
V_337 [ V_351 ] = 0x05 ;
break;
case V_358 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_354 ;
V_337 [ V_350 ] = 0x11 ;
V_337 [ V_351 ] = 0x13 ;
break;
case V_262 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_359 ;
V_337 [ V_350 ] = 0x27 ;
break;
case V_263 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x21 ;
break;
case V_265 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_360 ;
F_182 ( V_99 , & V_333 , & V_334 ) ;
V_337 [ V_350 ] = V_333 ;
V_337 [ V_351 ] = V_334 ;
break;
case V_266 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_349 ;
F_179 ( V_99 , & V_333 , & V_334 ) ;
V_337 [ V_350 ] = V_333 ;
V_337 [ V_351 ] = V_334 ;
break;
case V_361 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_362 ;
V_337 [ V_350 ] = 0x1d ;
V_337 [ V_351 ] = 0x00 ;
break;
case V_267 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x10 ;
V_337 [ V_351 ] = 0x01 ;
F_180 ( V_337 , V_99 -> V_338 ) ;
break;
case V_268 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x10 ;
V_337 [ V_351 ] = 0x02 ;
F_180 ( V_337 , V_99 -> V_338 ) ;
break;
case V_269 :
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_352 ;
V_337 [ V_350 ] = 0x10 ;
V_337 [ V_351 ] = 0x03 ;
F_180 ( V_337 , V_99 -> V_338 ) ;
break;
case V_128 :
default:
V_337 [ 0 ] = 0x70 ;
V_337 [ V_339 ] = 10 ;
V_337 [ V_348 ] = V_349 ;
V_337 [ V_350 ] = 0x08 ;
break;
}
V_99 -> V_136 = V_363 ;
V_99 -> V_130 = V_131 ;
V_345:
F_133 ( V_99 ) ;
return V_99 -> V_91 -> V_274 ( V_99 ) ;
}
int F_145 ( struct V_98 * V_99 , int V_364 )
{
if ( ! ( V_99 -> V_103 & V_145 ) )
return 0 ;
if ( ! V_364 || ! ( V_99 -> V_123 & V_365 ) )
return 1 ;
F_37 ( L_136 ,
V_99 -> V_192 [ 0 ] , V_99 -> V_91 -> V_116 ( V_99 ) ) ;
V_99 -> V_123 &= ~ V_365 ;
V_99 -> V_136 = V_366 ;
F_133 ( V_99 ) ;
V_99 -> V_91 -> V_274 ( V_99 ) ;
return 1 ;
}
void F_183 ( struct V_98 * V_99 )
{
unsigned long V_76 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
if ( V_99 -> V_123 & ( V_129 ) ) {
F_40 ( & V_99 -> V_110 , V_76 ) ;
return;
}
F_40 ( & V_99 -> V_110 , V_76 ) ;
if ( V_99 -> V_162 == V_165 ) {
if ( V_99 -> V_91 -> V_367 ( V_99 ) != 0 ) {
V_99 -> V_103 |= V_145 ;
V_99 -> V_123 |= V_365 ;
return;
}
}
V_99 -> V_136 = V_366 ;
F_65 ( V_99 ) ;
F_37 ( L_137
L_138 , V_99 -> V_192 [ 0 ] ,
V_99 -> V_91 -> V_116 ( V_99 ) ) ;
F_133 ( V_99 ) ;
V_99 -> V_91 -> V_274 ( V_99 ) ;
}
static void F_184 ( struct V_126 * V_127 )
{
struct V_98 * V_99 = F_42 ( V_127 , struct V_98 , V_127 ) ;
struct V_100 * V_101 = V_99 -> V_102 ;
struct V_241 * V_368 = V_99 -> V_241 ;
int V_36 ;
switch ( V_368 -> V_369 ) {
case V_250 :
F_185 ( V_101 , V_368 , V_99 -> V_40 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
V_368 -> V_242 = V_373 ;
break;
case V_374 :
V_36 = F_186 ( V_101 , V_368 , NULL , NULL ) ;
V_368 -> V_242 = ( ! V_36 ) ? V_375 :
V_376 ;
break;
case V_377 :
V_368 -> V_242 = V_376 ;
break;
case V_378 :
V_368 -> V_242 = V_376 ;
break;
default:
F_4 ( L_139 ,
V_368 -> V_369 ) ;
V_368 -> V_242 = V_376 ;
break;
}
V_99 -> V_111 = V_379 ;
V_99 -> V_91 -> V_244 ( V_99 ) ;
F_64 ( V_99 ) ;
}
int F_129 (
struct V_98 * V_99 )
{
unsigned long V_76 ;
F_39 ( & V_99 -> V_110 , V_76 ) ;
V_99 -> V_103 |= V_118 ;
F_40 ( & V_99 -> V_110 , V_76 ) ;
F_75 ( & V_99 -> V_127 , F_184 ) ;
F_76 ( V_99 -> V_102 -> V_380 , & V_99 -> V_127 ) ;
return 0 ;
}
