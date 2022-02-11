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
V_37 -> V_36 = V_36 ;
return V_37 ;
}
int F_20 ( struct V_2 * V_37 ,
unsigned int V_44 , unsigned int V_45 )
{
int V_46 ;
V_37 -> V_47 = F_21 ( V_44 * V_45 ,
V_38 | V_48 | V_49 ) ;
if ( ! V_37 -> V_47 ) {
V_37 -> V_47 = F_22 ( V_44 * V_45 ) ;
if ( ! V_37 -> V_47 ) {
F_4 ( L_30 ) ;
return - V_28 ;
}
}
V_46 = F_23 ( & V_37 -> V_50 , V_44 ) ;
if ( V_46 < 0 ) {
F_4 ( L_31
L_32 , V_44 ) ;
F_24 ( V_37 -> V_47 ) ;
V_37 -> V_47 = NULL ;
return - V_28 ;
}
return 0 ;
}
struct V_2 * F_25 ( unsigned int V_44 ,
unsigned int V_45 ,
enum V_35 V_36 )
{
struct V_2 * V_37 ;
int V_46 ;
if ( V_44 != 0 && ! V_45 ) {
F_4 ( L_33
L_34 , V_44 ) ;
return F_17 ( - V_51 ) ;
}
if ( ! V_44 && V_45 ) {
F_4 ( L_35
L_36 , V_45 ) ;
return F_17 ( - V_51 ) ;
}
V_37 = F_15 ( V_36 ) ;
if ( F_26 ( V_37 ) )
return V_37 ;
V_46 = F_20 ( V_37 , V_44 , V_45 ) ;
if ( V_46 < 0 ) {
F_27 ( V_37 ) ;
return F_17 ( - V_28 ) ;
}
return V_37 ;
}
void F_28 (
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
V_37 -> V_66 = F_29 ( & V_60 [ 0 ] ) ;
}
F_30 ( & V_55 -> V_67 ) ;
V_55 -> V_68 = V_37 ;
F_31 ( & V_37 -> V_40 ,
& V_55 -> V_69 ) ;
F_32 ( & V_55 -> V_67 ) ;
}
F_31 ( & V_37 -> V_39 , & V_53 -> V_70 ) ;
F_33 ( L_37 ,
V_53 -> V_59 -> V_71 () , V_37 -> V_56 ) ;
}
void F_34 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_2 * V_37 ,
void * V_56 )
{
unsigned long V_72 ;
F_35 ( & V_53 -> V_73 , V_72 ) ;
F_28 ( V_53 , V_55 , V_37 , V_56 ) ;
F_36 ( & V_53 -> V_73 , V_72 ) ;
}
struct V_2 *
F_37 ( struct V_52 * V_74 ,
unsigned int V_44 , unsigned int V_45 ,
enum V_35 V_75 ,
const char * V_76 , void * V_77 ,
int (* F_38)( struct V_52 * ,
struct V_2 * , void * ) )
{
struct V_2 * V_78 ;
if ( V_44 != 0 )
V_78 = F_25 ( V_44 , V_45 , V_75 ) ;
else
V_78 = F_15 ( V_75 ) ;
if ( F_26 ( V_78 ) )
return V_78 ;
V_78 -> V_54 = F_39 ( V_74 ,
( unsigned char * ) V_76 ) ;
if ( ! V_78 -> V_54 ) {
F_27 ( V_78 ) ;
return F_17 ( - V_79 ) ;
}
if ( F_38 != NULL ) {
int V_46 = F_38 ( V_74 , V_78 , V_77 ) ;
if ( V_46 ) {
F_27 ( V_78 ) ;
return F_17 ( V_46 ) ;
}
}
F_34 ( V_74 , V_78 -> V_54 , V_78 , V_77 ) ;
return V_78 ;
}
T_3 F_40 ( struct V_52 * V_53 , char * V_80 )
{
struct V_2 * V_37 ;
T_3 V_81 = 0 ;
F_41 ( & V_53 -> V_73 ) ;
F_42 (se_sess, &se_tpg->tpg_sess_list, sess_list) {
if ( ! V_37 -> V_54 )
continue;
if ( ! V_37 -> V_54 -> V_82 )
continue;
if ( strlen ( V_37 -> V_54 -> V_76 ) + 1 + V_81 > V_83 )
break;
V_81 += snprintf ( V_80 + V_81 , V_83 - V_81 , L_38 ,
V_37 -> V_54 -> V_76 ) ;
V_81 += 1 ;
}
F_43 ( & V_53 -> V_73 ) ;
return V_81 ;
}
static void F_44 ( struct V_84 * V_84 )
{
struct V_54 * V_85 = F_45 ( V_84 ,
struct V_54 , V_86 ) ;
struct V_52 * V_53 = V_85 -> V_53 ;
if ( ! V_85 -> V_87 ) {
F_46 ( & V_85 -> V_88 ) ;
return;
}
F_47 ( & V_53 -> V_89 ) ;
F_48 ( & V_85 -> V_90 ) ;
F_49 ( & V_53 -> V_89 ) ;
F_50 ( V_85 ) ;
F_51 ( V_85 , V_53 ) ;
F_52 ( V_85 ) ;
}
void F_53 ( struct V_54 * V_85 )
{
F_54 ( & V_85 -> V_86 , F_44 ) ;
}
void F_55 ( struct V_2 * V_37 )
{
struct V_54 * V_55 ;
unsigned long V_72 ;
V_55 = V_37 -> V_54 ;
if ( V_55 ) {
F_35 ( & V_55 -> V_67 , V_72 ) ;
if ( ! F_56 ( & V_37 -> V_40 ) )
F_57 ( & V_37 -> V_40 ) ;
if ( F_56 ( & V_55 -> V_69 ) )
V_55 -> V_68 = NULL ;
else {
V_55 -> V_68 = F_45 (
V_55 -> V_69 . V_91 ,
struct V_2 , V_40 ) ;
}
F_36 ( & V_55 -> V_67 , V_72 ) ;
}
}
void F_27 ( struct V_2 * V_37 )
{
struct V_54 * V_55 = V_37 -> V_54 ;
if ( V_55 ) {
struct V_52 * V_53 = V_55 -> V_53 ;
const struct V_57 * V_92 = V_53 -> V_59 ;
unsigned long V_72 ;
V_37 -> V_54 = NULL ;
F_47 ( & V_53 -> V_89 ) ;
if ( V_55 -> V_82 &&
! V_92 -> V_93 ( V_53 ) ) {
F_35 ( & V_55 -> V_67 , V_72 ) ;
if ( F_56 ( & V_55 -> V_69 ) )
V_55 -> V_87 = true ;
F_36 ( & V_55 -> V_67 , V_72 ) ;
if ( V_55 -> V_87 )
F_48 ( & V_55 -> V_90 ) ;
}
F_49 ( & V_53 -> V_89 ) ;
if ( V_55 -> V_87 )
F_53 ( V_55 ) ;
F_53 ( V_55 ) ;
}
if ( V_37 -> V_47 ) {
F_58 ( & V_37 -> V_50 ) ;
F_24 ( V_37 -> V_47 ) ;
}
F_59 ( V_1 , V_37 ) ;
}
void F_60 ( struct V_2 * V_37 )
{
struct V_52 * V_53 = V_37 -> V_53 ;
unsigned long V_72 ;
if ( ! V_53 ) {
F_27 ( V_37 ) ;
return;
}
F_35 ( & V_53 -> V_73 , V_72 ) ;
F_48 ( & V_37 -> V_39 ) ;
V_37 -> V_53 = NULL ;
V_37 -> V_56 = NULL ;
F_36 ( & V_53 -> V_73 , V_72 ) ;
F_33 ( L_39 ,
V_53 -> V_59 -> V_71 () ) ;
F_27 ( V_37 ) ;
}
static void F_61 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
unsigned long V_72 ;
if ( ! V_97 )
return;
if ( V_95 -> V_99 & V_100 )
return;
F_35 ( & V_97 -> V_101 , V_72 ) ;
if ( V_95 -> V_102 ) {
F_48 ( & V_95 -> V_103 ) ;
V_95 -> V_102 = false ;
}
F_36 ( & V_97 -> V_101 , V_72 ) ;
}
static int F_62 ( struct V_94 * V_95 , bool V_104 ,
bool V_105 )
{
unsigned long V_72 ;
if ( V_104 ) {
F_61 ( V_95 ) ;
V_95 -> V_106 = NULL ;
}
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_105 )
V_95 -> V_108 = V_109 ;
if ( V_95 -> V_99 & V_110 ) {
F_33 ( L_40 ,
V_111 , __LINE__ , V_95 -> V_112 ) ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
F_63 ( & V_95 -> V_113 ) ;
return 1 ;
}
V_95 -> V_99 &= ~ V_114 ;
if ( V_104 ) {
if ( V_95 -> V_92 -> V_115 != NULL ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
return V_95 -> V_92 -> V_115 ( V_95 ) ;
}
}
F_36 ( & V_95 -> V_107 , V_72 ) ;
return 0 ;
}
static int F_64 ( struct V_94 * V_95 )
{
return F_62 ( V_95 , true , false ) ;
}
static void F_65 ( struct V_94 * V_95 )
{
struct V_106 * V_116 = V_95 -> V_106 ;
if ( ! V_116 )
return;
if ( F_66 ( & V_95 -> V_117 , true , false ) )
F_67 ( & V_116 -> V_118 ) ;
}
void F_68 ( struct V_94 * V_95 , int remove )
{
bool V_119 = ( V_95 -> V_120 & V_121 ) ;
if ( V_95 -> V_120 & V_122 )
F_65 ( V_95 ) ;
if ( remove )
V_95 -> V_92 -> V_123 ( V_95 ) ;
if ( F_64 ( V_95 ) )
return;
if ( remove && V_119 )
F_69 ( V_95 ) ;
}
static void F_70 ( struct V_124 * V_125 )
{
struct V_94 * V_95 = F_45 ( V_125 , struct V_94 , V_125 ) ;
F_71 ( V_95 ,
V_126 ) ;
}
static unsigned char * F_72 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
F_73 ( ! V_95 -> V_106 ) ;
if ( ! V_97 )
return NULL ;
if ( V_95 -> V_120 & V_127 )
return NULL ;
V_95 -> V_128 = V_129 ;
F_33 ( L_41 ,
V_97 -> V_130 -> V_131 , V_97 -> V_132 -> V_133 , V_95 -> V_134 ) ;
return V_95 -> V_135 ;
}
void F_74 ( struct V_94 * V_95 , T_4 V_134 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_136 = V_134 == V_137 ;
unsigned long V_72 ;
V_95 -> V_134 = V_134 ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
V_95 -> V_99 &= ~ V_100 ;
if ( V_97 && V_97 -> V_132 -> V_138 ) {
V_97 -> V_132 -> V_138 ( V_95 ,
V_95 -> V_139 ,
F_72 ( V_95 ) ) ;
if ( V_95 -> V_120 & V_140 )
V_136 = 1 ;
}
if ( V_95 -> V_99 & V_141 ||
V_95 -> V_99 & V_110 ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
F_63 ( & V_95 -> V_113 ) ;
return;
} else if ( ! V_136 ) {
F_75 ( & V_95 -> V_125 , F_70 ) ;
} else {
F_75 ( & V_95 -> V_125 , V_142 ) ;
}
V_95 -> V_108 = V_143 ;
V_95 -> V_99 |= ( V_144 | V_114 ) ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_120 & V_145 )
F_76 ( V_95 -> V_146 , V_25 , & V_95 -> V_125 ) ;
else
F_77 ( V_25 , & V_95 -> V_125 ) ;
}
void F_78 ( struct V_94 * V_95 , T_4 V_134 , int V_147 )
{
if ( V_134 == V_148 && V_147 < V_95 -> V_149 ) {
if ( V_95 -> V_120 & V_150 ) {
V_95 -> V_151 += V_95 -> V_149 - V_147 ;
} else {
V_95 -> V_120 |= V_150 ;
V_95 -> V_151 = V_95 -> V_149 - V_147 ;
}
V_95 -> V_149 = V_147 ;
}
F_74 ( V_95 , V_134 ) ;
}
static void F_79 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
unsigned long V_72 ;
F_35 ( & V_97 -> V_101 , V_72 ) ;
if ( ! V_95 -> V_102 ) {
F_31 ( & V_95 -> V_103 , & V_97 -> V_103 ) ;
V_95 -> V_102 = true ;
}
F_36 ( & V_97 -> V_101 , V_72 ) ;
}
void F_80 ( struct V_124 * V_125 )
{
struct V_96 * V_97 = F_45 ( V_125 , struct V_96 ,
V_152 ) ;
F_81 ( V_153 ) ;
struct V_94 * V_95 , * V_154 ;
F_30 ( & V_97 -> V_155 ) ;
F_82 ( & V_97 -> V_153 , & V_153 ) ;
F_32 ( & V_97 -> V_155 ) ;
F_83 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_48 ( & V_95 -> V_156 ) ;
F_84 ( & V_97 -> V_157 ) ;
F_33 ( L_42
L_43 , V_95 -> V_92 -> V_71 () , V_95 ,
( V_95 -> V_108 == V_158 ) ? L_44 :
( V_95 -> V_108 == V_159 ) ? L_45
: L_46 ) ;
if ( V_95 -> V_108 == V_159 )
F_85 ( V_95 ) ;
else if ( V_95 -> V_108 == V_158 )
F_86 ( V_95 ) ;
}
}
unsigned char * F_87 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_160 ) {
case V_161 :
return L_47 ;
case V_162 :
return L_48 ;
case V_163 :
return L_49 ;
case V_164 :
return L_50 ;
default:
break;
}
return L_46 ;
}
void F_88 (
struct V_96 * V_97 ,
char * V_165 ,
int * V_166 )
{
* V_166 += sprintf ( V_165 + * V_166 , L_51 ) ;
if ( V_97 -> V_167 )
* V_166 += sprintf ( V_165 + * V_166 , L_52 ) ;
else
* V_166 += sprintf ( V_165 + * V_166 , L_53 ) ;
* V_166 += sprintf ( V_165 + * V_166 , L_54 , V_97 -> V_168 ) ;
* V_166 += sprintf ( V_165 + * V_166 , L_55 ,
V_97 -> V_169 . V_170 ,
V_97 -> V_169 . V_171 ) ;
* V_166 += sprintf ( V_165 + * V_166 , L_56 ) ;
}
void F_89 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_60 [ V_176 ] ;
int V_81 ;
memset ( V_60 , 0 , V_176 ) ;
V_81 = sprintf ( V_60 , L_57 ) ;
switch ( V_173 -> V_177 ) {
case 0x00 :
sprintf ( V_60 + V_81 , L_58 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_81 , L_59 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_81 , L_60 ) ;
break;
case 0x30 :
sprintf ( V_60 + V_81 , L_61 ) ;
break;
case 0x40 :
sprintf ( V_60 + V_81 , L_62
L_63 ) ;
break;
case 0x50 :
sprintf ( V_60 + V_81 , L_64 ) ;
break;
case 0x60 :
sprintf ( V_60 + V_81 , L_65 ) ;
break;
case 0x70 :
sprintf ( V_60 + V_81 , L_66
L_63 ) ;
break;
case 0x80 :
sprintf ( V_60 + V_81 , L_67 ) ;
break;
default:
sprintf ( V_60 + V_81 , L_68 ,
V_173 -> V_177 ) ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_60 , V_175 ) ;
else
F_33 ( L_69 , V_60 ) ;
}
void
F_90 ( struct V_172 * V_173 , unsigned char * V_178 )
{
if ( V_178 [ 1 ] & 0x80 ) {
V_173 -> V_177 = ( V_178 [ 0 ] & 0xf0 ) ;
V_173 -> V_179 = 1 ;
F_89 ( V_173 , NULL , 0 ) ;
}
}
int F_91 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_60 [ V_176 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_176 ) ;
V_81 = sprintf ( V_60 , L_70 ) ;
switch ( V_173 -> V_180 ) {
case 0x00 :
sprintf ( V_60 + V_81 , L_71 ) ;
break;
case 0x10 :
sprintf ( V_60 + V_81 , L_72 ) ;
break;
case 0x20 :
sprintf ( V_60 + V_81 , L_73 ) ;
break;
default:
sprintf ( V_60 + V_81 , L_68 , V_173 -> V_180 ) ;
V_33 = - V_51 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_60 , V_175 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int F_92 ( struct V_172 * V_173 , unsigned char * V_178 )
{
V_173 -> V_180 = ( V_178 [ 1 ] & 0x30 ) ;
return F_91 ( V_173 , NULL , 0 ) ;
}
int F_93 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_60 [ V_176 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_176 ) ;
V_81 = sprintf ( V_60 , L_74 ) ;
switch ( V_173 -> V_181 ) {
case 0x00 :
sprintf ( V_60 + V_81 , L_75 ) ;
break;
case 0x01 :
sprintf ( V_60 + V_81 , L_76 ) ;
break;
case 0x02 :
sprintf ( V_60 + V_81 , L_77 ) ;
break;
case 0x03 :
sprintf ( V_60 + V_81 , L_78 ) ;
break;
case 0x04 :
sprintf ( V_60 + V_81 , L_79 ) ;
break;
case 0x08 :
sprintf ( V_60 + V_81 , L_80 ) ;
break;
default:
sprintf ( V_60 + V_81 , L_81 ,
V_173 -> V_181 ) ;
V_33 = - V_51 ;
break;
}
if ( V_174 ) {
if ( V_175 < strlen ( V_60 ) + 1 )
return - V_51 ;
strncpy ( V_174 , V_60 , V_175 ) ;
} else {
F_33 ( L_69 , V_60 ) ;
}
return V_33 ;
}
int F_94 ( struct V_172 * V_173 , unsigned char * V_178 )
{
V_173 -> V_181 = ( V_178 [ 1 ] & 0x0f ) ;
return F_93 ( V_173 , NULL , 0 ) ;
}
int F_95 (
struct V_172 * V_173 ,
unsigned char * V_174 ,
int V_175 )
{
unsigned char V_60 [ V_176 ] ;
int V_33 = 0 ;
memset ( V_60 , 0 , V_176 ) ;
switch ( V_173 -> V_182 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_82 ,
& V_173 -> V_183 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_83 ,
& V_173 -> V_183 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_84 ,
& V_173 -> V_183 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_85
L_86 , V_173 -> V_182 ) ;
V_33 = - V_51 ;
break;
}
if ( V_174 )
strncpy ( V_174 , V_60 , V_175 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int
F_96 ( struct V_172 * V_173 , unsigned char * V_178 )
{
static const char V_184 [] = L_87 ;
int V_185 = 0 , V_186 = 4 ;
V_173 -> V_182 = ( V_178 [ 0 ] & 0x0f ) ;
switch ( V_173 -> V_182 ) {
case 0x01 :
V_173 -> V_183 [ V_185 ++ ] =
V_184 [ V_173 -> V_181 ] ;
while ( V_186 < ( 4 + V_178 [ 3 ] ) ) {
V_173 -> V_183 [ V_185 ++ ] =
V_184 [ ( V_178 [ V_186 ] & 0xf0 ) >> 4 ] ;
V_173 -> V_183 [ V_185 ++ ] =
V_184 [ V_178 [ V_186 ] & 0x0f ] ;
V_186 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_186 < ( 4 + V_178 [ 3 ] ) )
V_173 -> V_183 [ V_185 ++ ] = V_178 [ V_186 ++ ] ;
break;
default:
break;
}
return F_95 ( V_173 , NULL , 0 ) ;
}
static T_5
F_97 ( struct V_94 * V_95 , struct V_96 * V_97 ,
unsigned int V_187 )
{
T_1 V_188 ;
if ( ! V_95 -> V_92 -> V_189 )
return V_190 ;
V_188 = ( V_95 -> V_92 -> V_189 * V_83 ) ;
if ( V_95 -> V_149 > V_188 ) {
if ( V_95 -> V_120 & V_191 ) {
V_95 -> V_151 = ( V_187 - V_188 ) ;
} else if ( V_95 -> V_120 & V_150 ) {
T_1 V_192 = V_187 + V_95 -> V_151 ;
V_95 -> V_151 = ( V_192 - V_188 ) ;
} else {
V_95 -> V_120 |= V_150 ;
V_95 -> V_151 = ( V_95 -> V_149 - V_188 ) ;
}
V_95 -> V_149 = V_188 ;
if ( V_95 -> V_193 ) {
T_1 V_194 = ( V_188 / V_97 -> V_169 . V_170 ) ;
V_95 -> V_193 = V_97 -> V_193 * V_194 ;
}
}
return V_190 ;
}
T_5
F_98 ( struct V_94 * V_95 , unsigned int V_187 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_95 -> V_195 ) {
V_95 -> V_149 = V_187 ;
} else if ( V_187 != V_95 -> V_149 ) {
F_99 ( L_88
L_89
L_90 , V_95 -> V_92 -> V_71 () ,
V_95 -> V_149 , V_187 , V_95 -> V_196 [ 0 ] ) ;
if ( V_95 -> V_160 == V_163 &&
V_95 -> V_120 & V_197 ) {
F_4 ( L_91 ) ;
return V_198 ;
}
if ( V_97 -> V_169 . V_170 != 512 ) {
F_4 ( L_92
L_93
L_94 , V_97 -> V_132 -> V_133 ) ;
return V_198 ;
}
if ( V_187 > V_95 -> V_149 ) {
V_95 -> V_120 |= V_191 ;
V_95 -> V_151 = ( V_187 - V_95 -> V_149 ) ;
} else {
V_95 -> V_120 |= V_150 ;
V_95 -> V_151 = ( V_95 -> V_149 - V_187 ) ;
V_95 -> V_149 = V_187 ;
}
}
return F_97 ( V_95 , V_97 , V_187 ) ;
}
void F_100 (
struct V_94 * V_95 ,
const struct V_57 * V_58 ,
struct V_2 * V_37 ,
T_1 V_149 ,
int V_160 ,
int V_199 ,
unsigned char * V_135 )
{
F_18 ( & V_95 -> V_200 ) ;
F_18 ( & V_95 -> V_156 ) ;
F_18 ( & V_95 -> V_201 ) ;
F_18 ( & V_95 -> V_103 ) ;
F_101 ( & V_95 -> V_113 ) ;
F_101 ( & V_95 -> V_202 ) ;
F_19 ( & V_95 -> V_107 ) ;
F_102 ( & V_95 -> V_203 ) ;
V_95 -> V_99 = V_204 ;
V_95 -> V_92 = V_58 ;
V_95 -> V_37 = V_37 ;
V_95 -> V_149 = V_149 ;
V_95 -> V_160 = V_160 ;
V_95 -> V_205 = V_199 ;
V_95 -> V_135 = V_135 ;
V_95 -> V_102 = false ;
}
static T_5
F_103 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_132 -> V_206 & V_207 )
return 0 ;
if ( V_95 -> V_205 == V_208 ) {
F_33 ( L_95
L_96 ) ;
return V_198 ;
}
return 0 ;
}
T_5
F_104 ( struct V_94 * V_95 , unsigned char * V_209 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
T_5 V_33 ;
if ( F_105 ( V_209 ) > V_210 ) {
F_4 ( L_97
L_98 ,
F_105 ( V_209 ) , V_210 ) ;
return V_198 ;
}
if ( F_105 ( V_209 ) > sizeof( V_95 -> V_211 ) ) {
V_95 -> V_196 = F_21 ( F_105 ( V_209 ) ,
V_38 ) ;
if ( ! V_95 -> V_196 ) {
F_4 ( L_99
L_100 ,
F_105 ( V_209 ) ,
( unsigned long ) sizeof( V_95 -> V_211 ) ) ;
return V_212 ;
}
} else
V_95 -> V_196 = & V_95 -> V_211 [ 0 ] ;
memcpy ( V_95 -> V_196 , V_209 , F_105 ( V_209 ) ) ;
F_106 ( V_95 ) ;
V_33 = V_97 -> V_132 -> V_213 ( V_95 ) ;
if ( V_33 == V_214 )
F_107 ( L_101 ,
V_95 -> V_92 -> V_71 () ,
V_95 -> V_37 -> V_54 -> V_76 ,
V_95 -> V_196 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_103 ( V_95 ) ;
if ( V_33 )
return V_33 ;
V_95 -> V_120 |= V_215 ;
F_108 ( & V_95 -> V_106 -> V_216 . V_217 ) ;
return 0 ;
}
int F_109 (
struct V_94 * V_95 )
{
T_5 V_33 ;
if ( ! V_95 -> V_106 ) {
F_110 () ;
F_4 ( L_102 ) ;
return - V_51 ;
}
if ( F_111 () ) {
F_110 () ;
F_4 ( L_103
L_104 ) ;
return - V_51 ;
}
V_95 -> V_108 = V_218 ;
V_95 -> V_99 |= V_114 ;
V_33 = F_112 ( V_95 ) ;
if ( V_33 )
F_71 ( V_95 , V_33 ) ;
return 0 ;
}
T_5
F_113 ( struct V_94 * V_95 , struct V_219 * V_220 ,
T_1 V_221 , struct V_219 * V_222 , T_1 V_223 )
{
if ( ! V_220 || ! V_221 )
return 0 ;
if ( V_95 -> V_120 & V_191 ) {
F_99 ( L_105
L_106 ) ;
return V_198 ;
}
V_95 -> V_139 = V_220 ;
V_95 -> V_224 = V_221 ;
V_95 -> V_225 = V_222 ;
V_95 -> V_226 = V_223 ;
V_95 -> V_120 |= V_227 ;
return 0 ;
}
int F_114 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_209 , unsigned char * V_228 , T_6 V_229 ,
T_1 V_149 , int V_199 , int V_230 , int V_72 ,
struct V_219 * V_220 , T_1 V_221 ,
struct V_219 * V_222 , T_1 V_223 ,
struct V_219 * V_231 , T_1 V_232 )
{
struct V_52 * V_53 ;
T_5 V_46 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_10 ( V_94 -> V_92 || V_94 -> V_37 ) ;
F_10 ( F_111 () ) ;
F_100 ( V_94 , V_53 -> V_59 , V_37 ,
V_149 , V_230 , V_199 , V_228 ) ;
if ( V_72 & V_233 )
V_94 -> V_120 |= V_145 ;
else
V_94 -> V_146 = V_234 ;
if ( V_72 & V_235 )
V_94 -> V_195 = 1 ;
V_33 = F_115 ( V_94 , V_72 & V_236 ) ;
if ( V_33 )
return V_33 ;
if ( V_72 & V_237 )
V_94 -> V_120 |= V_238 ;
V_46 = F_116 ( V_94 , V_229 ) ;
if ( V_46 ) {
F_117 ( V_94 , V_46 , 0 ) ;
F_118 ( V_94 ) ;
return 0 ;
}
V_46 = F_104 ( V_94 , V_209 ) ;
if ( V_46 != 0 ) {
F_71 ( V_94 , V_46 ) ;
return 0 ;
}
if ( V_232 ) {
V_94 -> V_239 = V_231 ;
V_94 -> V_240 = V_232 ;
V_94 -> V_120 |= V_241 ;
}
if ( V_221 != 0 ) {
F_10 ( ! V_220 ) ;
if ( ! ( V_94 -> V_120 & V_197 ) &&
V_94 -> V_160 == V_162 ) {
unsigned char * V_60 = NULL ;
if ( V_220 )
V_60 = F_119 ( F_120 ( V_220 ) ) + V_220 -> V_242 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_220 -> V_147 ) ;
F_121 ( F_120 ( V_220 ) ) ;
}
}
V_46 = F_113 ( V_94 , V_220 , V_221 ,
V_222 , V_223 ) ;
if ( V_46 != 0 ) {
F_71 ( V_94 , V_46 ) ;
return 0 ;
}
}
F_122 ( V_94 ) ;
F_109 ( V_94 ) ;
return 0 ;
}
int F_123 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_209 , unsigned char * V_228 , T_6 V_229 ,
T_1 V_149 , int V_199 , int V_230 , int V_72 )
{
return F_114 ( V_94 , V_37 , V_209 , V_228 ,
V_229 , V_149 , V_199 , V_230 ,
V_72 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_124 ( struct V_124 * V_125 )
{
struct V_94 * V_94 = F_45 ( V_125 , struct V_94 , V_125 ) ;
V_94 -> V_243 -> V_244 = V_245 ;
V_94 -> V_92 -> V_246 ( V_94 ) ;
F_64 ( V_94 ) ;
}
int F_125 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_228 , T_6 V_229 ,
void * V_247 , unsigned char V_248 ,
T_7 V_249 , T_6 V_112 , int V_72 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_100 ( V_94 , V_53 -> V_59 , V_37 ,
0 , V_161 , V_250 , V_228 ) ;
V_33 = F_126 ( V_94 , V_247 , V_248 , V_249 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_248 == V_251 )
V_94 -> V_243 -> V_252 = V_112 ;
V_33 = F_115 ( V_94 , V_72 & V_236 ) ;
if ( V_33 ) {
F_127 ( V_94 -> V_243 ) ;
return V_33 ;
}
V_33 = F_128 ( V_94 , V_229 ) ;
if ( V_33 ) {
F_75 ( & V_94 -> V_125 , F_124 ) ;
F_129 ( & V_94 -> V_125 ) ;
return 0 ;
}
F_130 ( V_94 ) ;
return 0 ;
}
void F_71 ( struct V_94 * V_95 ,
T_5 V_253 )
{
int V_33 = 0 , V_254 = 0 ;
F_33 ( L_107
L_108 , V_95 , V_95 -> V_112 , V_95 -> V_196 [ 0 ] ) ;
F_33 ( L_109 ,
V_95 -> V_92 -> V_255 ( V_95 ) ,
V_95 -> V_108 , V_253 ) ;
F_33 ( L_110 ,
( V_95 -> V_99 & V_114 ) != 0 ,
( V_95 -> V_99 & V_110 ) != 0 ,
( V_95 -> V_99 & V_256 ) != 0 ) ;
F_131 ( V_95 ) ;
if ( ( V_95 -> V_120 & V_257 ) &&
V_95 -> V_258 )
V_95 -> V_258 ( V_95 , false , & V_254 ) ;
switch ( V_253 ) {
case V_259 :
case V_214 :
case V_198 :
case V_260 :
case V_261 :
case V_126 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
break;
case V_212 :
V_253 = V_126 ;
break;
case V_276 :
V_95 -> V_134 = V_277 ;
if ( V_95 -> V_37 &&
V_95 -> V_98 -> V_169 . V_278 == 2 ) {
F_132 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_279 , 0x2C ,
V_280 ) ;
}
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_281 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
goto V_284;
default:
F_4 ( L_111 ,
V_95 -> V_196 [ 0 ] , V_253 ) ;
V_253 = V_214 ;
break;
}
V_33 = F_117 ( V_95 , V_253 , 0 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
V_284:
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
return;
V_283:
V_95 -> V_108 = V_158 ;
F_134 ( V_95 , V_95 -> V_98 ) ;
}
void F_135 ( struct V_94 * V_95 , bool V_285 )
{
T_5 V_33 ;
if ( ! V_95 -> V_286 ) {
V_33 = V_126 ;
goto V_287;
}
if ( V_285 ) {
V_33 = F_136 ( V_95 ) ;
if ( V_33 )
goto V_287;
V_33 = F_137 ( V_95 ) ;
if ( V_33 )
goto V_287;
V_33 = F_138 ( V_95 ) ;
if ( V_33 ) {
V_95 -> V_134 = V_277 ;
goto V_287;
}
}
V_33 = V_95 -> V_286 ( V_95 ) ;
if ( ! V_33 )
return;
V_287:
F_30 ( & V_95 -> V_107 ) ;
V_95 -> V_99 &= ~ ( V_100 | V_256 ) ;
F_32 ( & V_95 -> V_107 ) ;
F_71 ( V_95 , V_33 ) ;
}
static int F_139 ( struct V_94 * V_95 )
{
T_1 V_194 ;
switch ( V_95 -> V_75 ) {
case V_288 :
if ( ! ( V_95 -> V_37 -> V_36 & V_288 ) )
F_140 ( V_95 ) ;
break;
case V_289 :
if ( V_95 -> V_37 -> V_36 & V_289 )
break;
V_194 = V_95 -> V_149 >> F_141 ( V_95 -> V_98 -> V_169 . V_170 ) ;
V_95 -> V_290 = F_142 ( V_95 , V_95 -> V_291 ,
V_194 , 0 , V_95 -> V_239 , 0 ) ;
if ( F_143 ( V_95 -> V_290 ) ) {
F_30 ( & V_95 -> V_107 ) ;
V_95 -> V_99 &= ~ ( V_100 | V_256 ) ;
F_32 ( & V_95 -> V_107 ) ;
F_71 ( V_95 , V_95 -> V_290 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_144 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_132 -> V_206 & V_207 )
return false ;
V_95 -> V_120 |= V_292 ;
switch ( V_95 -> V_205 ) {
case V_293 :
F_33 ( L_112 ,
V_95 -> V_196 [ 0 ] ) ;
return false ;
case V_294 :
F_145 ( & V_97 -> V_295 ) ;
F_33 ( L_113 ,
V_95 -> V_196 [ 0 ] ) ;
if ( ! F_146 ( & V_97 -> V_296 ) )
return false ;
break;
default:
F_145 ( & V_97 -> V_296 ) ;
break;
}
if ( F_146 ( & V_97 -> V_295 ) == 0 )
return false ;
F_11 ( & V_97 -> V_297 ) ;
F_31 ( & V_95 -> V_200 , & V_97 -> V_298 ) ;
F_12 ( & V_97 -> V_297 ) ;
F_33 ( L_114 ,
V_95 -> V_196 [ 0 ] , V_95 -> V_205 ) ;
return true ;
}
void F_147 ( struct V_94 * V_95 )
{
F_30 ( & V_95 -> V_107 ) ;
if ( F_148 ( V_95 , 1 ) ) {
F_32 ( & V_95 -> V_107 ) ;
return;
}
if ( V_95 -> V_99 & V_110 ) {
F_33 ( L_40 ,
V_111 , __LINE__ , V_95 -> V_112 ) ;
F_32 ( & V_95 -> V_107 ) ;
F_63 ( & V_95 -> V_113 ) ;
return;
}
V_95 -> V_108 = V_299 ;
V_95 -> V_99 |= V_114 | V_100 | V_256 ;
F_32 ( & V_95 -> V_107 ) ;
if ( F_139 ( V_95 ) )
return;
if ( F_144 ( V_95 ) ) {
F_30 ( & V_95 -> V_107 ) ;
V_95 -> V_99 &= ~ ( V_100 | V_256 ) ;
F_32 ( & V_95 -> V_107 ) ;
return;
}
F_135 ( V_95 , true ) ;
}
static void F_149 ( struct V_96 * V_97 )
{
for (; ; ) {
struct V_94 * V_95 ;
F_11 ( & V_97 -> V_297 ) ;
if ( F_56 ( & V_97 -> V_298 ) ) {
F_12 ( & V_97 -> V_297 ) ;
break;
}
V_95 = F_150 ( V_97 -> V_298 . V_300 ,
struct V_94 , V_200 ) ;
F_48 ( & V_95 -> V_200 ) ;
F_12 ( & V_97 -> V_297 ) ;
F_135 ( V_95 , true ) ;
if ( V_95 -> V_205 == V_294 )
break;
}
}
static void F_131 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_132 -> V_206 & V_207 )
return;
if ( ! ( V_95 -> V_120 & V_292 ) )
goto V_301;
if ( V_95 -> V_205 == V_250 ) {
F_84 ( & V_97 -> V_296 ) ;
V_97 -> V_302 ++ ;
F_33 ( L_115 ,
V_97 -> V_302 ) ;
} else if ( V_95 -> V_205 == V_293 ) {
V_97 -> V_302 ++ ;
F_33 ( L_116 ,
V_97 -> V_302 ) ;
} else if ( V_95 -> V_205 == V_294 ) {
F_84 ( & V_97 -> V_295 ) ;
V_97 -> V_302 ++ ;
F_33 ( L_117 ,
V_97 -> V_302 ) ;
}
V_301:
F_149 ( V_97 ) ;
}
static void F_86 ( struct V_94 * V_95 )
{
int V_33 = 0 ;
F_131 ( V_95 ) ;
if ( V_95 -> V_120 & V_140 ) {
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_281 ( V_95 ) ;
goto V_3;
}
switch ( V_95 -> V_160 ) {
case V_162 :
if ( V_95 -> V_134 )
goto V_281;
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
break;
case V_163 :
if ( V_95 -> V_120 & V_238 ) {
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
break;
}
case V_161 :
V_281:
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_281 ( V_95 ) ;
break;
default:
break;
}
V_3:
if ( V_33 < 0 ) {
F_134 ( V_95 , V_95 -> V_98 ) ;
return;
}
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
}
static void F_134 (
struct V_94 * V_95 ,
struct V_96 * V_97 )
{
F_30 ( & V_97 -> V_155 ) ;
F_31 ( & V_95 -> V_156 , & V_95 -> V_98 -> V_153 ) ;
F_145 ( & V_97 -> V_157 ) ;
F_32 ( & V_95 -> V_98 -> V_155 ) ;
F_129 ( & V_95 -> V_98 -> V_152 ) ;
}
static bool F_151 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_75 ) {
case V_304 :
if ( ! ( V_95 -> V_37 -> V_36 & V_304 ) ) {
T_1 V_194 = V_95 -> V_149 >>
F_141 ( V_95 -> V_98 -> V_169 . V_170 ) ;
V_95 -> V_290 = F_142 ( V_95 , V_95 -> V_291 ,
V_194 , 0 , V_95 -> V_239 ,
0 ) ;
if ( V_95 -> V_290 )
return true ;
}
break;
case V_305 :
if ( V_95 -> V_37 -> V_36 & V_305 )
break;
F_140 ( V_95 ) ;
break;
default:
break;
}
return false ;
}
static void V_142 ( struct V_124 * V_125 )
{
struct V_94 * V_95 = F_45 ( V_125 , struct V_94 , V_125 ) ;
int V_33 ;
F_131 ( V_95 ) ;
if ( F_146 ( & V_95 -> V_98 -> V_157 ) != 0 )
F_129 ( & V_95 -> V_98 -> V_152 ) ;
if ( V_95 -> V_120 & V_140 ) {
F_73 ( ! V_95 -> V_134 ) ;
V_33 = F_117 (
V_95 , 0 , 1 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
return;
}
if ( V_95 -> V_258 ) {
T_5 V_46 ;
bool V_306 = ( V_95 -> V_120 & V_257 ) ;
bool V_307 = ! ( V_95 -> V_149 ) ;
int V_254 = 0 ;
V_46 = V_95 -> V_258 ( V_95 , true , & V_254 ) ;
if ( ! V_46 && ! V_254 ) {
if ( V_306 && V_307 )
goto V_308;
return;
} else if ( V_46 ) {
V_33 = F_117 ( V_95 ,
V_46 , 0 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
return;
}
}
V_308:
switch ( V_95 -> V_160 ) {
case V_162 :
if ( V_95 -> V_134 )
goto V_281;
F_152 ( V_95 -> V_149 ,
& V_95 -> V_106 -> V_216 . V_309 ) ;
if ( F_151 ( V_95 ) ) {
V_33 = F_117 ( V_95 ,
V_95 -> V_290 , 0 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
return;
}
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
break;
case V_163 :
F_152 ( V_95 -> V_149 ,
& V_95 -> V_106 -> V_216 . V_310 ) ;
if ( V_95 -> V_120 & V_238 ) {
F_152 ( V_95 -> V_149 ,
& V_95 -> V_106 -> V_216 . V_309 ) ;
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
break;
}
case V_161 :
V_281:
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_281 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
break;
default:
break;
}
F_65 ( V_95 ) ;
F_64 ( V_95 ) ;
return;
V_283:
F_33 ( L_118
L_119 , V_95 , V_95 -> V_160 ) ;
V_95 -> V_108 = V_158 ;
F_134 ( V_95 , V_95 -> V_98 ) ;
}
void F_153 ( struct V_219 * V_220 , int V_311 )
{
struct V_219 * V_312 ;
int V_313 ;
F_154 (sgl, sg, nents, count)
F_155 ( F_120 ( V_312 ) ) ;
F_52 ( V_220 ) ;
}
static inline void F_156 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_314 )
return;
F_52 ( V_95 -> V_139 ) ;
V_95 -> V_139 = V_95 -> V_314 ;
V_95 -> V_314 = NULL ;
V_95 -> V_224 = V_95 -> V_315 ;
V_95 -> V_315 = 0 ;
}
static inline void F_157 ( struct V_94 * V_95 )
{
if ( ! ( V_95 -> V_120 & V_241 ) ) {
F_153 ( V_95 -> V_239 , V_95 -> V_240 ) ;
V_95 -> V_239 = NULL ;
V_95 -> V_240 = 0 ;
}
if ( V_95 -> V_120 & V_227 ) {
if ( V_95 -> V_120 & V_257 ) {
F_153 ( V_95 -> V_225 ,
V_95 -> V_226 ) ;
V_95 -> V_225 = NULL ;
V_95 -> V_226 = 0 ;
}
F_156 ( V_95 ) ;
return;
}
F_156 ( V_95 ) ;
F_153 ( V_95 -> V_139 , V_95 -> V_224 ) ;
V_95 -> V_139 = NULL ;
V_95 -> V_224 = 0 ;
F_153 ( V_95 -> V_225 , V_95 -> V_226 ) ;
V_95 -> V_225 = NULL ;
V_95 -> V_226 = 0 ;
}
static int F_69 ( struct V_94 * V_95 )
{
F_10 ( ! V_95 -> V_92 ) ;
return F_118 ( V_95 ) ;
}
void * F_158 ( struct V_94 * V_95 )
{
struct V_219 * V_312 = V_95 -> V_139 ;
struct V_80 * * V_316 ;
int V_186 ;
if ( ! V_95 -> V_224 )
return NULL ;
F_10 ( ! V_312 ) ;
if ( V_95 -> V_224 == 1 )
return F_119 ( F_120 ( V_312 ) ) + V_312 -> V_242 ;
V_316 = F_159 ( sizeof( * V_316 ) * V_95 -> V_224 , V_38 ) ;
if ( ! V_316 )
return NULL ;
F_154 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_316 [ V_186 ] = F_120 ( V_312 ) ;
}
V_95 -> V_317 = F_160 ( V_316 , V_95 -> V_224 , V_318 , V_319 ) ;
F_52 ( V_316 ) ;
if ( ! V_95 -> V_317 )
return NULL ;
return V_95 -> V_317 + V_95 -> V_139 [ 0 ] . V_242 ;
}
void F_161 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_224 ) {
return;
} else if ( V_95 -> V_224 == 1 ) {
F_121 ( F_120 ( V_95 -> V_139 ) ) ;
return;
}
F_162 ( V_95 -> V_317 ) ;
V_95 -> V_317 = NULL ;
}
int
F_163 ( struct V_219 * * V_220 , unsigned int * V_311 , T_1 V_147 ,
bool V_320 , bool V_321 )
{
struct V_219 * V_312 ;
struct V_80 * V_80 ;
T_7 V_322 = ( V_320 ) ? V_323 : 0 ;
unsigned int V_324 , V_325 ;
int V_186 = 0 ;
V_324 = V_325 = F_164 ( V_147 , V_83 ) ;
if ( V_321 )
V_324 ++ ;
V_312 = F_165 ( V_324 , sizeof( struct V_219 ) , V_38 ) ;
if ( ! V_312 )
return - V_28 ;
F_166 ( V_312 , V_324 ) ;
while ( V_147 ) {
T_1 V_326 = F_167 ( T_1 , V_147 , V_83 ) ;
V_80 = F_168 ( V_38 | V_322 ) ;
if ( ! V_80 )
goto V_3;
F_169 ( & V_312 [ V_186 ] , V_80 , V_326 , 0 ) ;
V_147 -= V_326 ;
V_186 ++ ;
}
* V_220 = V_312 ;
* V_311 = V_325 ;
return 0 ;
V_3:
while ( V_186 > 0 ) {
V_186 -- ;
F_155 ( F_120 ( & V_312 [ V_186 ] ) ) ;
}
F_52 ( V_312 ) ;
return - V_28 ;
}
T_5
F_112 ( struct V_94 * V_95 )
{
int V_33 = 0 ;
bool V_322 = ! ( V_95 -> V_120 & V_197 ) ;
if ( V_95 -> V_75 != V_327 &&
! ( V_95 -> V_120 & V_241 ) ) {
V_33 = F_163 ( & V_95 -> V_239 , & V_95 -> V_240 ,
V_95 -> V_193 , true , false ) ;
if ( V_33 < 0 )
return V_126 ;
}
if ( ! ( V_95 -> V_120 & V_227 ) &&
V_95 -> V_149 ) {
if ( ( V_95 -> V_120 & V_238 ) ||
( V_95 -> V_120 & V_257 ) ) {
T_1 V_328 ;
if ( V_95 -> V_120 & V_257 )
V_328 = V_95 -> V_329 *
V_95 -> V_98 -> V_169 . V_170 ;
else
V_328 = V_95 -> V_149 ;
V_33 = F_163 ( & V_95 -> V_225 ,
& V_95 -> V_226 ,
V_328 , V_322 , false ) ;
if ( V_33 < 0 )
return V_126 ;
}
V_33 = F_163 ( & V_95 -> V_139 , & V_95 -> V_224 ,
V_95 -> V_149 , V_322 , false ) ;
if ( V_33 < 0 )
return V_126 ;
} else if ( ( V_95 -> V_120 & V_257 ) &&
V_95 -> V_149 ) {
T_1 V_330 = V_95 -> V_329 *
V_95 -> V_98 -> V_169 . V_170 ;
V_33 = F_163 ( & V_95 -> V_225 ,
& V_95 -> V_226 ,
V_330 , V_322 , false ) ;
if ( V_33 < 0 )
return V_126 ;
}
F_79 ( V_95 ) ;
if ( V_95 -> V_160 != V_163 || V_95 -> V_149 == 0 ) {
F_147 ( V_95 ) ;
return 0 ;
}
F_62 ( V_95 , false , true ) ;
V_33 = V_95 -> V_92 -> V_105 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 )
goto V_283;
F_73 ( V_33 ) ;
return ( ! V_33 ) ? 0 : V_126 ;
V_283:
F_33 ( L_120 , V_95 ) ;
V_95 -> V_108 = V_159 ;
F_134 ( V_95 , V_95 -> V_98 ) ;
return 0 ;
}
static void F_85 ( struct V_94 * V_95 )
{
int V_33 ;
V_33 = V_95 -> V_92 -> V_105 ( V_95 ) ;
if ( V_33 == - V_282 || V_33 == - V_28 ) {
F_33 ( L_120 ,
V_95 ) ;
F_134 ( V_95 , V_95 -> V_98 ) ;
}
}
static void F_170 ( struct V_94 * V_95 , bool * V_331 , bool * V_332 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
F_171 ( V_95 , true , V_331 , V_332 , & V_72 ) ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
}
int F_172 ( struct V_94 * V_95 , int V_333 )
{
int V_33 = 0 ;
bool V_331 = false , V_332 = false ;
if ( ! ( V_95 -> V_120 & V_122 ) ) {
if ( V_333 && ( V_95 -> V_120 & V_334 ) )
F_170 ( V_95 , & V_331 , & V_332 ) ;
if ( ! V_331 || V_332 )
V_33 = F_69 ( V_95 ) ;
} else {
if ( V_333 )
F_170 ( V_95 , & V_331 , & V_332 ) ;
if ( V_95 -> V_102 )
F_61 ( V_95 ) ;
if ( V_95 -> V_106 )
F_65 ( V_95 ) ;
if ( ! V_331 || V_332 )
V_33 = F_69 ( V_95 ) ;
}
if ( V_331 ) {
F_33 ( L_121 , V_95 -> V_112 ) ;
F_173 ( & V_95 -> V_202 ) ;
V_95 -> V_92 -> V_335 ( V_95 ) ;
V_33 = 1 ;
}
return V_33 ;
}
int F_115 ( struct V_94 * V_94 , bool V_119 )
{
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
int V_33 = 0 ;
if ( V_119 ) {
if ( ! F_174 ( & V_94 -> V_203 ) )
return - V_51 ;
V_94 -> V_120 |= V_121 ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_336 ) {
V_33 = - V_337 ;
goto V_3;
}
F_31 ( & V_94 -> V_201 , & V_37 -> V_41 ) ;
V_3:
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( V_33 && V_119 )
F_118 ( V_94 ) ;
return V_33 ;
}
static void F_175 ( struct V_94 * V_95 )
{
F_157 ( V_95 ) ;
if ( V_95 -> V_120 & V_334 )
F_127 ( V_95 -> V_243 ) ;
if ( V_95 -> V_196 != V_95 -> V_211 )
F_52 ( V_95 -> V_196 ) ;
}
static void F_176 ( struct V_84 * V_84 )
{
struct V_94 * V_94 = F_45 ( V_84 , struct V_94 , V_203 ) ;
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
bool V_338 ;
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_11 ( & V_94 -> V_107 ) ;
V_338 = ( V_94 -> V_99 & V_339 ) &&
( V_94 -> V_99 & V_141 ) ;
F_12 ( & V_94 -> V_107 ) ;
if ( V_94 -> V_340 || V_338 ) {
F_57 ( & V_94 -> V_201 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
F_175 ( V_94 ) ;
F_46 ( & V_94 -> V_202 ) ;
return;
}
F_57 ( & V_94 -> V_201 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
F_175 ( V_94 ) ;
V_94 -> V_92 -> V_335 ( V_94 ) ;
}
int F_118 ( struct V_94 * V_94 )
{
struct V_2 * V_37 = V_94 -> V_37 ;
if ( ! V_37 ) {
F_175 ( V_94 ) ;
V_94 -> V_92 -> V_335 ( V_94 ) ;
return 1 ;
}
return F_54 ( & V_94 -> V_203 , F_176 ) ;
}
void F_177 ( struct V_2 * V_37 )
{
struct V_94 * V_94 , * V_341 ;
unsigned long V_72 ;
int V_46 ;
F_35 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_336 ) {
F_36 ( & V_37 -> V_43 , V_72 ) ;
return;
}
V_37 -> V_336 = 1 ;
F_82 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_83 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
V_46 = F_174 ( & V_94 -> V_203 ) ;
if ( V_46 ) {
V_94 -> V_340 = 1 ;
F_11 ( & V_94 -> V_107 ) ;
V_94 -> V_99 |= V_339 ;
F_12 ( & V_94 -> V_107 ) ;
} else
F_57 ( & V_94 -> V_201 ) ;
}
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
void F_178 ( struct V_2 * V_37 )
{
struct V_94 * V_94 , * V_341 ;
unsigned long V_72 ;
bool V_332 ;
F_83 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_33 ( L_122
L_123 , V_94 , V_94 -> V_108 ,
V_94 -> V_92 -> V_255 ( V_94 ) ) ;
F_35 ( & V_94 -> V_107 , V_72 ) ;
V_332 = ( V_94 -> V_99 & V_342 ) ;
F_36 ( & V_94 -> V_107 , V_72 ) ;
if ( ! F_118 ( V_94 ) ) {
if ( V_332 )
F_118 ( V_94 ) ;
}
F_173 ( & V_94 -> V_202 ) ;
F_33 ( L_124
L_125 , V_94 , V_94 -> V_108 ,
V_94 -> V_92 -> V_255 ( V_94 ) ) ;
V_94 -> V_92 -> V_335 ( V_94 ) ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_73 ( ! F_56 ( & V_37 -> V_41 ) ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
void F_179 ( struct V_106 * V_116 )
{
F_180 ( & V_116 -> V_118 ) ;
F_173 ( & V_116 -> V_343 ) ;
}
static bool
F_171 ( struct V_94 * V_95 , bool V_338 ,
bool * V_331 , bool * V_332 , unsigned long * V_72 )
__releases( &cmd->t_state_lock
bool F_181 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_33 , V_331 = false , V_332 = false ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
V_33 = F_171 ( V_95 , false , & V_331 , & V_332 , & V_72 ) ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
return V_33 ;
}
static int F_182 ( struct V_94 * V_95 , T_5 V_344 )
{
const struct V_345 * V_346 ;
T_4 * V_347 = V_95 -> V_135 ;
int V_348 = ( V_349 int ) V_344 ;
T_4 V_350 , V_351 ;
bool V_352 = F_183 ( V_95 -> V_98 ) ;
if ( V_348 < F_184 ( V_353 ) && V_353 [ V_348 ] . V_354 )
V_346 = & V_353 [ V_348 ] ;
else
V_346 = & V_353 [ ( V_349 int )
V_126 ] ;
if ( V_344 == V_266 ) {
F_185 ( V_95 , & V_350 , & V_351 ) ;
F_186 ( V_350 == 0 ) ;
} else if ( V_346 -> V_350 == 0 ) {
F_186 ( V_95 -> V_355 == 0 ) ;
V_350 = V_95 -> V_355 ;
V_351 = V_95 -> V_356 ;
} else {
V_350 = V_346 -> V_350 ;
V_351 = V_346 -> V_351 ;
}
F_187 ( V_352 , V_347 , V_346 -> V_354 , V_350 , V_351 ) ;
if ( V_346 -> V_357 )
return F_188 ( V_347 ,
V_95 -> V_128 ,
V_95 -> V_358 ) ;
return 0 ;
}
int
F_117 ( struct V_94 * V_95 ,
T_5 V_344 , int V_359 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_120 & V_127 ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
return 0 ;
}
V_95 -> V_120 |= V_127 ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
if ( ! V_359 ) {
int V_46 ;
V_95 -> V_120 |= V_360 ;
V_95 -> V_134 = V_361 ;
V_95 -> V_128 = V_129 ;
V_46 = F_182 ( V_95 , V_344 ) ;
if ( V_46 )
return V_46 ;
}
F_133 ( V_95 ) ;
return V_95 -> V_92 -> V_281 ( V_95 ) ;
}
static int F_148 ( struct V_94 * V_95 , int V_362 )
__releases( &cmd->t_state_lock
int F_189 ( struct V_94 * V_95 , int V_362 )
{
int V_33 ;
F_30 ( & V_95 -> V_107 ) ;
V_33 = F_148 ( V_95 , V_362 ) ;
F_32 ( & V_95 -> V_107 ) ;
return V_33 ;
}
void F_190 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_120 & ( V_127 ) ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
return;
}
F_36 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_160 == V_163 ) {
if ( V_95 -> V_92 -> V_363 ( V_95 ) != 0 ) {
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_120 & V_364 ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
goto V_365;
}
V_95 -> V_120 |= V_364 ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
return;
}
}
V_365:
V_95 -> V_134 = V_366 ;
F_65 ( V_95 ) ;
F_33 ( L_126 ,
V_95 -> V_196 [ 0 ] , V_95 -> V_112 ) ;
F_133 ( V_95 ) ;
V_95 -> V_92 -> V_281 ( V_95 ) ;
}
static void F_191 ( struct V_124 * V_125 )
{
struct V_94 * V_95 = F_45 ( V_125 , struct V_94 , V_125 ) ;
struct V_96 * V_97 = V_95 -> V_98 ;
struct V_243 * V_367 = V_95 -> V_243 ;
unsigned long V_72 ;
int V_33 ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_99 & V_141 ) {
V_367 -> V_244 = V_368 ;
F_36 ( & V_95 -> V_107 , V_72 ) ;
goto V_284;
}
F_36 ( & V_95 -> V_107 , V_72 ) ;
switch ( V_367 -> V_369 ) {
case V_251 :
F_192 ( V_97 , V_367 , V_95 -> V_37 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
V_367 -> V_244 = V_373 ;
break;
case V_374 :
V_33 = F_193 ( V_97 , V_367 , NULL , NULL ) ;
V_367 -> V_244 = ( ! V_33 ) ? V_375 :
V_368 ;
if ( V_367 -> V_244 == V_375 ) {
F_132 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_279 , 0x29 ,
V_376 ) ;
}
break;
case V_377 :
V_367 -> V_244 = V_368 ;
break;
case V_378 :
V_367 -> V_244 = V_368 ;
break;
default:
F_4 ( L_127 ,
V_367 -> V_369 ) ;
V_367 -> V_244 = V_368 ;
break;
}
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_99 & V_141 ) {
F_36 ( & V_95 -> V_107 , V_72 ) ;
goto V_284;
}
F_36 ( & V_95 -> V_107 , V_72 ) ;
V_95 -> V_92 -> V_246 ( V_95 ) ;
V_284:
F_64 ( V_95 ) ;
}
int F_130 (
struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_331 = false ;
F_35 ( & V_95 -> V_107 , V_72 ) ;
if ( V_95 -> V_99 & V_141 ) {
V_331 = true ;
} else {
V_95 -> V_108 = V_379 ;
V_95 -> V_99 |= V_114 ;
}
F_36 ( & V_95 -> V_107 , V_72 ) ;
if ( V_331 ) {
F_107 ( L_128
L_129 , V_95 -> V_243 -> V_369 ,
V_95 -> V_243 -> V_252 , V_95 -> V_112 ) ;
F_64 ( V_95 ) ;
return 0 ;
}
F_75 ( & V_95 -> V_125 , F_191 ) ;
F_77 ( V_95 -> V_98 -> V_380 , & V_95 -> V_125 ) ;
return 0 ;
}
bool
F_194 ( struct V_96 * V_97 )
{
bool V_381 = false ;
if ( V_97 -> V_132 -> V_382 )
V_381 = V_97 -> V_132 -> V_382 ( V_97 ) ;
else if ( V_97 -> V_169 . V_383 > 0 )
V_381 = true ;
return V_381 ;
}
bool
F_195 ( struct V_96 * V_97 )
{
return F_194 ( V_97 ) && V_97 -> V_169 . V_384 > 0 ;
}
