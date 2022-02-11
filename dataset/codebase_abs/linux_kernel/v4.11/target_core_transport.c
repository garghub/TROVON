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
F_35 ( & V_97 -> V_99 , V_72 ) ;
if ( V_95 -> V_100 ) {
F_48 ( & V_95 -> V_101 ) ;
V_95 -> V_100 = false ;
}
F_36 ( & V_97 -> V_99 , V_72 ) ;
}
static int F_62 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
F_61 ( V_95 ) ;
V_95 -> V_102 = NULL ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_105 ) {
F_33 ( L_40 ,
V_106 , __LINE__ , V_95 -> V_107 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
F_63 ( & V_95 -> V_108 ) ;
return 1 ;
}
V_95 -> V_104 &= ~ V_109 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
return V_95 -> V_92 -> V_110 ( V_95 ) ;
}
static void F_64 ( struct V_94 * V_95 )
{
struct V_102 * V_111 = V_95 -> V_102 ;
if ( ! V_111 )
return;
if ( F_65 ( & V_95 -> V_112 , true , false ) )
F_66 ( & V_111 -> V_113 ) ;
}
void F_67 ( struct V_94 * V_95 , int remove )
{
bool V_114 = ( V_95 -> V_115 & V_116 ) ;
if ( V_95 -> V_115 & V_117 )
F_64 ( V_95 ) ;
if ( remove )
V_95 -> V_92 -> V_118 ( V_95 ) ;
if ( F_62 ( V_95 ) )
return;
if ( remove && V_114 )
F_68 ( V_95 ) ;
}
static void F_69 ( struct V_119 * V_120 )
{
struct V_94 * V_95 = F_45 ( V_120 , struct V_94 , V_120 ) ;
F_70 ( V_95 ,
V_121 ) ;
}
static unsigned char * F_71 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
F_72 ( ! V_95 -> V_102 ) ;
if ( ! V_97 )
return NULL ;
if ( V_95 -> V_115 & V_122 )
return NULL ;
V_95 -> V_123 = V_124 ;
F_33 ( L_41 ,
V_97 -> V_125 -> V_126 , V_97 -> V_127 -> V_128 , V_95 -> V_129 ) ;
return V_95 -> V_130 ;
}
void F_73 ( struct V_94 * V_95 , T_4 V_129 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_131 = V_129 == V_132 ;
unsigned long V_72 ;
V_95 -> V_129 = V_129 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_97 && V_97 -> V_127 -> V_133 ) {
V_97 -> V_127 -> V_133 ( V_95 ,
V_95 -> V_134 ,
F_71 ( V_95 ) ) ;
if ( V_95 -> V_115 & V_135 )
V_131 = 1 ;
}
if ( V_95 -> V_104 & V_136 ||
V_95 -> V_104 & V_105 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
F_63 ( & V_95 -> V_108 ) ;
return;
} else if ( ! V_131 ) {
F_74 ( & V_95 -> V_120 , F_69 ) ;
} else {
F_74 ( & V_95 -> V_120 , V_137 ) ;
}
V_95 -> V_138 = V_139 ;
V_95 -> V_104 |= ( V_140 | V_109 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_141 )
F_75 ( V_95 -> V_142 , V_25 , & V_95 -> V_120 ) ;
else
F_76 ( V_25 , & V_95 -> V_120 ) ;
}
void F_77 ( struct V_94 * V_95 , T_4 V_129 , int V_143 )
{
if ( V_129 == V_144 && V_143 < V_95 -> V_145 ) {
if ( V_95 -> V_115 & V_146 ) {
V_95 -> V_147 += V_95 -> V_145 - V_143 ;
} else {
V_95 -> V_115 |= V_146 ;
V_95 -> V_147 = V_95 -> V_145 - V_143 ;
}
V_95 -> V_145 = V_143 ;
}
F_73 ( V_95 , V_129 ) ;
}
static void F_78 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
unsigned long V_72 ;
F_35 ( & V_97 -> V_99 , V_72 ) ;
if ( ! V_95 -> V_100 ) {
F_31 ( & V_95 -> V_101 , & V_97 -> V_101 ) ;
V_95 -> V_100 = true ;
}
F_36 ( & V_97 -> V_99 , V_72 ) ;
}
void F_79 ( struct V_119 * V_120 )
{
struct V_96 * V_97 = F_45 ( V_120 , struct V_96 ,
V_148 ) ;
F_80 ( V_149 ) ;
struct V_94 * V_95 , * V_150 ;
F_30 ( & V_97 -> V_151 ) ;
F_81 ( & V_97 -> V_149 , & V_149 ) ;
F_32 ( & V_97 -> V_151 ) ;
F_82 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_48 ( & V_95 -> V_152 ) ;
F_83 ( & V_97 -> V_153 ) ;
F_33 ( L_42
L_43 , V_95 -> V_92 -> V_71 () , V_95 ,
( V_95 -> V_138 == V_154 ) ? L_44 :
( V_95 -> V_138 == V_155 ) ? L_45
: L_46 ) ;
if ( V_95 -> V_138 == V_155 )
F_84 ( V_95 ) ;
else if ( V_95 -> V_138 == V_154 ||
V_95 -> V_138 == V_156 )
F_85 ( V_95 ) ;
}
}
unsigned char * F_86 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_157 ) {
case V_158 :
return L_47 ;
case V_159 :
return L_48 ;
case V_160 :
return L_49 ;
case V_161 :
return L_50 ;
default:
break;
}
return L_46 ;
}
void F_87 (
struct V_96 * V_97 ,
char * V_162 ,
int * V_163 )
{
* V_163 += sprintf ( V_162 + * V_163 , L_51 ) ;
if ( V_97 -> V_164 )
* V_163 += sprintf ( V_162 + * V_163 , L_52 ) ;
else
* V_163 += sprintf ( V_162 + * V_163 , L_53 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_54 , V_97 -> V_165 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_55 ,
V_97 -> V_166 . V_167 ,
V_97 -> V_166 . V_168 ) ;
* V_163 += sprintf ( V_162 + * V_163 , L_56 ) ;
}
void F_88 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_81 ;
memset ( V_60 , 0 , V_173 ) ;
V_81 = sprintf ( V_60 , L_57 ) ;
switch ( V_170 -> V_174 ) {
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
V_170 -> V_174 ) ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_33 ( L_69 , V_60 ) ;
}
void
F_89 ( struct V_169 * V_170 , unsigned char * V_175 )
{
if ( V_175 [ 1 ] & 0x80 ) {
V_170 -> V_174 = ( V_175 [ 0 ] & 0xf0 ) ;
V_170 -> V_176 = 1 ;
F_88 ( V_170 , NULL , 0 ) ;
}
}
int F_90 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_173 ) ;
V_81 = sprintf ( V_60 , L_70 ) ;
switch ( V_170 -> V_177 ) {
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
sprintf ( V_60 + V_81 , L_68 , V_170 -> V_177 ) ;
V_33 = - V_51 ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int F_91 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_177 = ( V_175 [ 1 ] & 0x30 ) ;
return F_90 ( V_170 , NULL , 0 ) ;
}
int F_92 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_173 ) ;
V_81 = sprintf ( V_60 , L_74 ) ;
switch ( V_170 -> V_178 ) {
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
V_170 -> V_178 ) ;
V_33 = - V_51 ;
break;
}
if ( V_171 ) {
if ( V_172 < strlen ( V_60 ) + 1 )
return - V_51 ;
strncpy ( V_171 , V_60 , V_172 ) ;
} else {
F_33 ( L_69 , V_60 ) ;
}
return V_33 ;
}
int F_93 ( struct V_169 * V_170 , unsigned char * V_175 )
{
V_170 -> V_178 = ( V_175 [ 1 ] & 0x0f ) ;
return F_92 ( V_170 , NULL , 0 ) ;
}
int F_94 (
struct V_169 * V_170 ,
unsigned char * V_171 ,
int V_172 )
{
unsigned char V_60 [ V_173 ] ;
int V_33 = 0 ;
memset ( V_60 , 0 , V_173 ) ;
switch ( V_170 -> V_179 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_82 ,
& V_170 -> V_180 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_83 ,
& V_170 -> V_180 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_84 ,
& V_170 -> V_180 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_85
L_86 , V_170 -> V_179 ) ;
V_33 = - V_51 ;
break;
}
if ( V_171 )
strncpy ( V_171 , V_60 , V_172 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int
F_95 ( struct V_169 * V_170 , unsigned char * V_175 )
{
static const char V_181 [] = L_87 ;
int V_182 = 0 , V_183 = 4 ;
V_170 -> V_179 = ( V_175 [ 0 ] & 0x0f ) ;
switch ( V_170 -> V_179 ) {
case 0x01 :
V_170 -> V_180 [ V_182 ++ ] =
V_181 [ V_170 -> V_178 ] ;
while ( V_183 < ( 4 + V_175 [ 3 ] ) ) {
V_170 -> V_180 [ V_182 ++ ] =
V_181 [ ( V_175 [ V_183 ] & 0xf0 ) >> 4 ] ;
V_170 -> V_180 [ V_182 ++ ] =
V_181 [ V_175 [ V_183 ] & 0x0f ] ;
V_183 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_183 < ( 4 + V_175 [ 3 ] ) )
V_170 -> V_180 [ V_182 ++ ] = V_175 [ V_183 ++ ] ;
break;
default:
break;
}
return F_94 ( V_170 , NULL , 0 ) ;
}
static T_5
F_96 ( struct V_94 * V_95 , struct V_96 * V_97 ,
unsigned int V_184 )
{
T_1 V_185 ;
if ( ! V_95 -> V_92 -> V_186 )
return V_187 ;
V_185 = ( V_95 -> V_92 -> V_186 * V_83 ) ;
if ( V_95 -> V_145 > V_185 ) {
if ( V_95 -> V_115 & V_188 ) {
V_95 -> V_147 = ( V_184 - V_185 ) ;
} else if ( V_95 -> V_115 & V_146 ) {
T_1 V_189 = V_184 + V_95 -> V_147 ;
V_95 -> V_147 = ( V_189 - V_185 ) ;
} else {
V_95 -> V_115 |= V_146 ;
V_95 -> V_147 = ( V_95 -> V_145 - V_185 ) ;
}
V_95 -> V_145 = V_185 ;
if ( V_95 -> V_190 ) {
T_1 V_191 = ( V_185 / V_97 -> V_166 . V_167 ) ;
V_95 -> V_190 = V_97 -> V_190 * V_191 ;
}
}
return V_187 ;
}
T_5
F_97 ( struct V_94 * V_95 , unsigned int V_184 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_95 -> V_192 ) {
V_95 -> V_145 = V_184 ;
} else if ( V_184 != V_95 -> V_145 ) {
F_98 ( L_88
L_89
L_90 , V_95 -> V_92 -> V_71 () ,
V_95 -> V_145 , V_184 , V_95 -> V_193 [ 0 ] ) ;
if ( V_95 -> V_157 == V_160 &&
V_95 -> V_115 & V_194 ) {
F_4 ( L_91 ) ;
return V_195 ;
}
if ( V_97 -> V_166 . V_167 != 512 ) {
F_4 ( L_92
L_93
L_94 , V_97 -> V_127 -> V_128 ) ;
return V_195 ;
}
if ( V_184 > V_95 -> V_145 ) {
V_95 -> V_115 |= V_188 ;
V_95 -> V_147 = ( V_184 - V_95 -> V_145 ) ;
} else {
V_95 -> V_115 |= V_146 ;
V_95 -> V_147 = ( V_95 -> V_145 - V_184 ) ;
V_95 -> V_145 = V_184 ;
}
}
return F_96 ( V_95 , V_97 , V_184 ) ;
}
void F_99 (
struct V_94 * V_95 ,
const struct V_57 * V_58 ,
struct V_2 * V_37 ,
T_1 V_145 ,
int V_157 ,
int V_196 ,
unsigned char * V_130 )
{
F_18 ( & V_95 -> V_197 ) ;
F_18 ( & V_95 -> V_152 ) ;
F_18 ( & V_95 -> V_198 ) ;
F_18 ( & V_95 -> V_101 ) ;
F_100 ( & V_95 -> V_108 ) ;
F_100 ( & V_95 -> V_199 ) ;
F_19 ( & V_95 -> V_103 ) ;
F_101 ( & V_95 -> V_200 ) ;
V_95 -> V_92 = V_58 ;
V_95 -> V_37 = V_37 ;
V_95 -> V_145 = V_145 ;
V_95 -> V_157 = V_157 ;
V_95 -> V_201 = V_196 ;
V_95 -> V_130 = V_130 ;
V_95 -> V_100 = false ;
}
static T_5
F_102 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_127 -> V_202 & V_203 )
return 0 ;
if ( V_95 -> V_201 == V_204 ) {
F_33 ( L_95
L_96 ) ;
return V_195 ;
}
return 0 ;
}
T_5
F_103 ( struct V_94 * V_95 , unsigned char * V_205 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
T_5 V_33 ;
if ( F_104 ( V_205 ) > V_206 ) {
F_4 ( L_97
L_98 ,
F_104 ( V_205 ) , V_206 ) ;
return V_195 ;
}
if ( F_104 ( V_205 ) > sizeof( V_95 -> V_207 ) ) {
V_95 -> V_193 = F_21 ( F_104 ( V_205 ) ,
V_38 ) ;
if ( ! V_95 -> V_193 ) {
F_4 ( L_99
L_100 ,
F_104 ( V_205 ) ,
( unsigned long ) sizeof( V_95 -> V_207 ) ) ;
return V_208 ;
}
} else
V_95 -> V_193 = & V_95 -> V_207 [ 0 ] ;
memcpy ( V_95 -> V_193 , V_205 , F_104 ( V_205 ) ) ;
F_105 ( V_95 ) ;
V_33 = V_97 -> V_127 -> V_209 ( V_95 ) ;
if ( V_33 == V_210 )
F_106 ( L_101 ,
V_95 -> V_92 -> V_71 () ,
V_95 -> V_37 -> V_54 -> V_76 ,
V_95 -> V_193 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_102 ( V_95 ) ;
if ( V_33 )
return V_33 ;
V_95 -> V_115 |= V_211 ;
F_107 ( & V_95 -> V_102 -> V_212 . V_213 ) ;
return 0 ;
}
int F_108 (
struct V_94 * V_95 )
{
T_5 V_33 ;
if ( ! V_95 -> V_102 ) {
F_109 () ;
F_4 ( L_102 ) ;
return - V_51 ;
}
if ( F_110 () ) {
F_109 () ;
F_4 ( L_103
L_104 ) ;
return - V_51 ;
}
V_95 -> V_138 = V_214 ;
V_95 -> V_104 |= V_109 ;
V_33 = F_111 ( V_95 ) ;
if ( V_33 )
F_70 ( V_95 , V_33 ) ;
return 0 ;
}
T_5
F_112 ( struct V_94 * V_95 , struct V_215 * V_216 ,
T_1 V_217 , struct V_215 * V_218 , T_1 V_219 )
{
if ( ! V_216 || ! V_217 )
return 0 ;
if ( V_95 -> V_115 & V_188 ) {
F_98 ( L_105
L_106 ) ;
return V_195 ;
}
V_95 -> V_134 = V_216 ;
V_95 -> V_220 = V_217 ;
V_95 -> V_221 = V_218 ;
V_95 -> V_222 = V_219 ;
V_95 -> V_115 |= V_223 ;
return 0 ;
}
int F_113 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_205 , unsigned char * V_224 , T_6 V_225 ,
T_1 V_145 , int V_196 , int V_226 , int V_72 ,
struct V_215 * V_216 , T_1 V_217 ,
struct V_215 * V_218 , T_1 V_219 ,
struct V_215 * V_227 , T_1 V_228 )
{
struct V_52 * V_53 ;
T_5 V_46 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_10 ( V_94 -> V_92 || V_94 -> V_37 ) ;
F_10 ( F_110 () ) ;
F_99 ( V_94 , V_53 -> V_59 , V_37 ,
V_145 , V_226 , V_196 , V_224 ) ;
if ( V_72 & V_229 )
V_94 -> V_115 |= V_141 ;
else
V_94 -> V_142 = V_230 ;
if ( V_72 & V_231 )
V_94 -> V_192 = 1 ;
V_33 = F_114 ( V_94 , V_72 & V_232 ) ;
if ( V_33 )
return V_33 ;
if ( V_72 & V_233 )
V_94 -> V_115 |= V_234 ;
V_46 = F_115 ( V_94 , V_225 ) ;
if ( V_46 ) {
F_116 ( V_94 , V_46 , 0 ) ;
F_117 ( V_94 ) ;
return 0 ;
}
V_46 = F_103 ( V_94 , V_205 ) ;
if ( V_46 != 0 ) {
F_70 ( V_94 , V_46 ) ;
return 0 ;
}
if ( V_228 ) {
V_94 -> V_235 = V_227 ;
V_94 -> V_236 = V_228 ;
V_94 -> V_115 |= V_237 ;
}
if ( V_217 != 0 ) {
F_10 ( ! V_216 ) ;
if ( ! ( V_94 -> V_115 & V_194 ) &&
V_94 -> V_157 == V_159 ) {
unsigned char * V_60 = NULL ;
if ( V_216 )
V_60 = F_118 ( F_119 ( V_216 ) ) + V_216 -> V_238 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_216 -> V_143 ) ;
F_120 ( F_119 ( V_216 ) ) ;
}
}
V_46 = F_112 ( V_94 , V_216 , V_217 ,
V_218 , V_219 ) ;
if ( V_46 != 0 ) {
F_70 ( V_94 , V_46 ) ;
return 0 ;
}
}
F_121 ( V_94 ) ;
F_108 ( V_94 ) ;
return 0 ;
}
int F_122 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_205 , unsigned char * V_224 , T_6 V_225 ,
T_1 V_145 , int V_196 , int V_226 , int V_72 )
{
return F_113 ( V_94 , V_37 , V_205 , V_224 ,
V_225 , V_145 , V_196 , V_226 ,
V_72 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_123 ( struct V_119 * V_120 )
{
struct V_94 * V_94 = F_45 ( V_120 , struct V_94 , V_120 ) ;
V_94 -> V_239 -> V_240 = V_241 ;
V_94 -> V_92 -> V_242 ( V_94 ) ;
F_62 ( V_94 ) ;
}
int F_124 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_224 , T_6 V_225 ,
void * V_243 , unsigned char V_244 ,
T_7 V_245 , T_6 V_107 , int V_72 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_99 ( V_94 , V_53 -> V_59 , V_37 ,
0 , V_158 , V_246 , V_224 ) ;
V_33 = F_125 ( V_94 , V_243 , V_244 , V_245 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_244 == V_247 )
V_94 -> V_239 -> V_248 = V_107 ;
V_33 = F_114 ( V_94 , V_72 & V_232 ) ;
if ( V_33 ) {
F_126 ( V_94 -> V_239 ) ;
return V_33 ;
}
V_33 = F_127 ( V_94 , V_225 ) ;
if ( V_33 ) {
F_74 ( & V_94 -> V_120 , F_123 ) ;
F_128 ( & V_94 -> V_120 ) ;
return 0 ;
}
F_129 ( V_94 ) ;
return 0 ;
}
void F_70 ( struct V_94 * V_95 ,
T_5 V_249 )
{
int V_33 = 0 , V_250 = 0 ;
if ( F_130 ( V_95 , 1 ) )
return;
F_33 ( L_107
L_108 , V_95 , V_95 -> V_107 , V_95 -> V_193 [ 0 ] ) ;
F_33 ( L_109 ,
V_95 -> V_92 -> V_251 ( V_95 ) ,
V_95 -> V_138 , V_249 ) ;
F_33 ( L_110 ,
( V_95 -> V_104 & V_109 ) != 0 ,
( V_95 -> V_104 & V_105 ) != 0 ,
( V_95 -> V_104 & V_252 ) != 0 ) ;
F_131 ( V_95 ) ;
if ( ( V_95 -> V_115 & V_253 ) &&
V_95 -> V_254 )
V_95 -> V_254 ( V_95 , false , & V_250 ) ;
switch ( V_249 ) {
case V_255 :
case V_210 :
case V_195 :
case V_256 :
case V_257 :
case V_121 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
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
break;
case V_208 :
V_249 = V_121 ;
break;
case V_272 :
V_95 -> V_129 = V_273 ;
if ( V_95 -> V_37 &&
V_95 -> V_98 -> V_166 . V_274 == 2 ) {
F_132 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_275 , 0x2C ,
V_276 ) ;
}
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_277 ( V_95 ) ;
if ( V_33 )
goto V_278;
goto V_279;
default:
F_4 ( L_111 ,
V_95 -> V_193 [ 0 ] , V_249 ) ;
V_249 = V_210 ;
break;
}
V_33 = F_116 ( V_95 , V_249 , 0 ) ;
if ( V_33 )
goto V_278;
V_279:
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
V_278:
F_134 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
void F_135 ( struct V_94 * V_95 , bool V_280 )
{
T_5 V_33 ;
if ( ! V_95 -> V_281 ) {
V_33 = V_121 ;
goto V_282;
}
if ( V_280 ) {
V_33 = F_136 ( V_95 ) ;
if ( V_33 )
goto V_282;
V_33 = F_137 ( V_95 ) ;
if ( V_33 )
goto V_282;
V_33 = F_138 ( V_95 ) ;
if ( V_33 ) {
V_95 -> V_129 = V_273 ;
goto V_282;
}
}
V_33 = V_95 -> V_281 ( V_95 ) ;
if ( ! V_33 )
return;
V_282:
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_252 ;
F_32 ( & V_95 -> V_103 ) ;
F_70 ( V_95 , V_33 ) ;
}
static int F_139 ( struct V_94 * V_95 )
{
T_1 V_191 ;
switch ( V_95 -> V_75 ) {
case V_283 :
if ( ! ( V_95 -> V_37 -> V_36 & V_283 ) )
F_140 ( V_95 ) ;
break;
case V_284 :
if ( V_95 -> V_37 -> V_36 & V_284 )
break;
V_191 = V_95 -> V_145 >> F_141 ( V_95 -> V_98 -> V_166 . V_167 ) ;
V_95 -> V_285 = F_142 ( V_95 , V_95 -> V_286 ,
V_191 , 0 , V_95 -> V_235 , 0 ) ;
if ( F_143 ( V_95 -> V_285 ) ) {
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_252 ;
F_32 ( & V_95 -> V_103 ) ;
F_70 ( V_95 , V_95 -> V_285 ) ;
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
if ( V_97 -> V_127 -> V_202 & V_203 )
return false ;
V_95 -> V_115 |= V_287 ;
switch ( V_95 -> V_201 ) {
case V_288 :
F_33 ( L_112 ,
V_95 -> V_193 [ 0 ] ) ;
return false ;
case V_289 :
F_145 ( & V_97 -> V_290 ) ;
F_33 ( L_113 ,
V_95 -> V_193 [ 0 ] ) ;
if ( ! F_146 ( & V_97 -> V_291 ) )
return false ;
break;
default:
F_145 ( & V_97 -> V_291 ) ;
break;
}
if ( F_146 ( & V_97 -> V_290 ) == 0 )
return false ;
F_11 ( & V_97 -> V_292 ) ;
F_31 ( & V_95 -> V_197 , & V_97 -> V_293 ) ;
F_12 ( & V_97 -> V_292 ) ;
F_33 ( L_114 ,
V_95 -> V_193 [ 0 ] , V_95 -> V_201 ) ;
return true ;
}
void F_147 ( struct V_94 * V_95 )
{
F_30 ( & V_95 -> V_103 ) ;
if ( F_148 ( V_95 , 1 ) ) {
F_32 ( & V_95 -> V_103 ) ;
return;
}
if ( V_95 -> V_104 & V_105 ) {
F_33 ( L_40 ,
V_106 , __LINE__ , V_95 -> V_107 ) ;
F_32 ( & V_95 -> V_103 ) ;
F_63 ( & V_95 -> V_108 ) ;
return;
}
V_95 -> V_138 = V_294 ;
V_95 -> V_104 |= V_109 | V_252 ;
F_32 ( & V_95 -> V_103 ) ;
if ( F_139 ( V_95 ) )
return;
if ( F_144 ( V_95 ) ) {
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_252 ;
F_32 ( & V_95 -> V_103 ) ;
return;
}
F_135 ( V_95 , true ) ;
}
static void F_149 ( struct V_96 * V_97 )
{
for (; ; ) {
struct V_94 * V_95 ;
F_11 ( & V_97 -> V_292 ) ;
if ( F_56 ( & V_97 -> V_293 ) ) {
F_12 ( & V_97 -> V_292 ) ;
break;
}
V_95 = F_150 ( V_97 -> V_293 . V_295 ,
struct V_94 , V_197 ) ;
F_48 ( & V_95 -> V_197 ) ;
F_12 ( & V_97 -> V_292 ) ;
F_135 ( V_95 , true ) ;
if ( V_95 -> V_201 == V_289 )
break;
}
}
static void F_131 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_127 -> V_202 & V_203 )
return;
if ( ! ( V_95 -> V_115 & V_287 ) )
goto V_296;
if ( V_95 -> V_201 == V_246 ) {
F_83 ( & V_97 -> V_291 ) ;
V_97 -> V_297 ++ ;
} else if ( V_95 -> V_201 == V_288 ) {
V_97 -> V_297 ++ ;
F_33 ( L_115 ,
V_97 -> V_297 ) ;
} else if ( V_95 -> V_201 == V_289 ) {
F_83 ( & V_97 -> V_290 ) ;
V_97 -> V_297 ++ ;
F_33 ( L_116 ,
V_97 -> V_297 ) ;
}
V_296:
F_149 ( V_97 ) ;
}
static void F_85 ( struct V_94 * V_95 )
{
int V_33 = 0 ;
F_131 ( V_95 ) ;
if ( V_95 -> V_138 == V_156 ) {
if ( V_95 -> V_129 )
goto V_277;
V_95 -> V_115 |= V_298 ;
V_95 -> V_129 = V_299 ;
V_95 -> V_123 = V_124 ;
F_151 ( V_95 , V_121 ) ;
goto V_277;
}
if ( V_95 -> V_115 & V_135 )
goto V_277;
switch ( V_95 -> V_157 ) {
case V_159 :
if ( V_95 -> V_129 )
goto V_277;
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_300 ( V_95 ) ;
break;
case V_160 :
if ( V_95 -> V_115 & V_234 ) {
V_33 = V_95 -> V_92 -> V_300 ( V_95 ) ;
break;
}
case V_158 :
V_277:
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_277 ( V_95 ) ;
break;
default:
break;
}
if ( V_33 < 0 ) {
F_134 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
return;
}
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
}
static void F_134 ( struct V_94 * V_95 , struct V_96 * V_97 ,
int V_282 , bool V_301 )
{
if ( V_282 == - V_302 || V_282 == - V_28 ) {
V_95 -> V_138 = ( V_301 ) ? V_155 :
V_154 ;
} else {
F_106 ( L_117 , V_282 ) ;
V_95 -> V_138 = V_156 ;
}
F_30 ( & V_97 -> V_151 ) ;
F_31 ( & V_95 -> V_152 , & V_95 -> V_98 -> V_149 ) ;
F_145 ( & V_97 -> V_153 ) ;
F_32 ( & V_95 -> V_98 -> V_151 ) ;
F_128 ( & V_95 -> V_98 -> V_148 ) ;
}
static bool F_152 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_75 ) {
case V_303 :
if ( ! ( V_95 -> V_37 -> V_36 & V_303 ) ) {
T_1 V_191 = V_95 -> V_145 >>
F_141 ( V_95 -> V_98 -> V_166 . V_167 ) ;
V_95 -> V_285 = F_142 ( V_95 , V_95 -> V_286 ,
V_191 , 0 , V_95 -> V_235 ,
0 ) ;
if ( V_95 -> V_285 )
return true ;
}
break;
case V_304 :
if ( V_95 -> V_37 -> V_36 & V_304 )
break;
F_140 ( V_95 ) ;
break;
default:
break;
}
return false ;
}
static void V_137 ( struct V_119 * V_120 )
{
struct V_94 * V_95 = F_45 ( V_120 , struct V_94 , V_120 ) ;
int V_33 ;
F_131 ( V_95 ) ;
if ( F_146 ( & V_95 -> V_98 -> V_153 ) != 0 )
F_128 ( & V_95 -> V_98 -> V_148 ) ;
if ( V_95 -> V_115 & V_135 ) {
F_72 ( ! V_95 -> V_129 ) ;
V_33 = F_116 (
V_95 , 0 , 1 ) ;
if ( V_33 )
goto V_278;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
if ( V_95 -> V_254 ) {
T_5 V_46 ;
bool V_305 = ( V_95 -> V_115 & V_253 ) ;
bool V_306 = ! ( V_95 -> V_145 ) ;
int V_250 = 0 ;
V_46 = V_95 -> V_254 ( V_95 , true , & V_250 ) ;
if ( ! V_46 && ! V_250 ) {
if ( V_305 && V_306 )
goto V_307;
return;
} else if ( V_46 ) {
V_33 = F_116 ( V_95 ,
V_46 , 0 ) ;
if ( V_33 )
goto V_278;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
}
V_307:
switch ( V_95 -> V_157 ) {
case V_159 :
if ( V_95 -> V_129 )
goto V_277;
F_153 ( V_95 -> V_145 ,
& V_95 -> V_102 -> V_212 . V_308 ) ;
if ( F_152 ( V_95 ) ) {
V_33 = F_116 ( V_95 ,
V_95 -> V_285 , 0 ) ;
if ( V_33 )
goto V_278;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_300 ( V_95 ) ;
if ( V_33 )
goto V_278;
break;
case V_160 :
F_153 ( V_95 -> V_145 ,
& V_95 -> V_102 -> V_212 . V_309 ) ;
if ( V_95 -> V_115 & V_234 ) {
F_153 ( V_95 -> V_145 ,
& V_95 -> V_102 -> V_212 . V_308 ) ;
V_33 = V_95 -> V_92 -> V_300 ( V_95 ) ;
if ( V_33 )
goto V_278;
break;
}
case V_158 :
V_277:
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_277 ( V_95 ) ;
if ( V_33 )
goto V_278;
break;
default:
break;
}
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
V_278:
F_33 ( L_118
L_119 , V_95 , V_95 -> V_157 ) ;
F_134 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
void F_154 ( struct V_215 * V_216 , int V_310 )
{
struct V_215 * V_311 ;
int V_312 ;
F_155 (sgl, sg, nents, count)
F_156 ( F_119 ( V_311 ) ) ;
F_52 ( V_216 ) ;
}
static inline void F_157 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_313 )
return;
F_52 ( V_95 -> V_134 ) ;
V_95 -> V_134 = V_95 -> V_313 ;
V_95 -> V_313 = NULL ;
V_95 -> V_220 = V_95 -> V_314 ;
V_95 -> V_314 = 0 ;
}
static inline void F_158 ( struct V_94 * V_95 )
{
if ( ! ( V_95 -> V_115 & V_237 ) ) {
F_154 ( V_95 -> V_235 , V_95 -> V_236 ) ;
V_95 -> V_235 = NULL ;
V_95 -> V_236 = 0 ;
}
if ( V_95 -> V_115 & V_223 ) {
if ( V_95 -> V_115 & V_253 ) {
F_154 ( V_95 -> V_221 ,
V_95 -> V_222 ) ;
V_95 -> V_221 = NULL ;
V_95 -> V_222 = 0 ;
}
F_157 ( V_95 ) ;
return;
}
F_157 ( V_95 ) ;
F_154 ( V_95 -> V_134 , V_95 -> V_220 ) ;
V_95 -> V_134 = NULL ;
V_95 -> V_220 = 0 ;
F_154 ( V_95 -> V_221 , V_95 -> V_222 ) ;
V_95 -> V_221 = NULL ;
V_95 -> V_222 = 0 ;
}
static int F_68 ( struct V_94 * V_95 )
{
F_10 ( ! V_95 -> V_92 ) ;
return F_117 ( V_95 ) ;
}
void * F_159 ( struct V_94 * V_95 )
{
struct V_215 * V_311 = V_95 -> V_134 ;
struct V_80 * * V_315 ;
int V_183 ;
if ( ! V_95 -> V_220 )
return NULL ;
F_10 ( ! V_311 ) ;
if ( V_95 -> V_220 == 1 )
return F_118 ( F_119 ( V_311 ) ) + V_311 -> V_238 ;
V_315 = F_160 ( sizeof( * V_315 ) * V_95 -> V_220 , V_38 ) ;
if ( ! V_315 )
return NULL ;
F_155 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_315 [ V_183 ] = F_119 ( V_311 ) ;
}
V_95 -> V_316 = F_161 ( V_315 , V_95 -> V_220 , V_317 , V_318 ) ;
F_52 ( V_315 ) ;
if ( ! V_95 -> V_316 )
return NULL ;
return V_95 -> V_316 + V_95 -> V_134 [ 0 ] . V_238 ;
}
void F_162 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_220 ) {
return;
} else if ( V_95 -> V_220 == 1 ) {
F_120 ( F_119 ( V_95 -> V_134 ) ) ;
return;
}
F_163 ( V_95 -> V_316 ) ;
V_95 -> V_316 = NULL ;
}
int
F_164 ( struct V_215 * * V_216 , unsigned int * V_310 , T_1 V_143 ,
bool V_319 , bool V_320 )
{
struct V_215 * V_311 ;
struct V_80 * V_80 ;
T_7 V_321 = ( V_319 ) ? V_322 : 0 ;
unsigned int V_323 , V_324 ;
int V_183 = 0 ;
V_323 = V_324 = F_165 ( V_143 , V_83 ) ;
if ( V_320 )
V_323 ++ ;
V_311 = F_166 ( V_323 , sizeof( struct V_215 ) , V_38 ) ;
if ( ! V_311 )
return - V_28 ;
F_167 ( V_311 , V_323 ) ;
while ( V_143 ) {
T_1 V_325 = F_168 ( T_1 , V_143 , V_83 ) ;
V_80 = F_169 ( V_38 | V_321 ) ;
if ( ! V_80 )
goto V_3;
F_170 ( & V_311 [ V_183 ] , V_80 , V_325 , 0 ) ;
V_143 -= V_325 ;
V_183 ++ ;
}
* V_216 = V_311 ;
* V_310 = V_324 ;
return 0 ;
V_3:
while ( V_183 > 0 ) {
V_183 -- ;
F_156 ( F_119 ( & V_311 [ V_183 ] ) ) ;
}
F_52 ( V_311 ) ;
return - V_28 ;
}
T_5
F_111 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
int V_33 = 0 ;
bool V_321 = ! ( V_95 -> V_115 & V_194 ) ;
if ( V_95 -> V_75 != V_326 &&
! ( V_95 -> V_115 & V_237 ) ) {
V_33 = F_164 ( & V_95 -> V_235 , & V_95 -> V_236 ,
V_95 -> V_190 , true , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
if ( ! ( V_95 -> V_115 & V_223 ) &&
V_95 -> V_145 ) {
if ( ( V_95 -> V_115 & V_234 ) ||
( V_95 -> V_115 & V_253 ) ) {
T_1 V_327 ;
if ( V_95 -> V_115 & V_253 )
V_327 = V_95 -> V_328 *
V_95 -> V_98 -> V_166 . V_167 ;
else
V_327 = V_95 -> V_145 ;
V_33 = F_164 ( & V_95 -> V_221 ,
& V_95 -> V_222 ,
V_327 , V_321 , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
V_33 = F_164 ( & V_95 -> V_134 , & V_95 -> V_220 ,
V_95 -> V_145 , V_321 , false ) ;
if ( V_33 < 0 )
return V_121 ;
} else if ( ( V_95 -> V_115 & V_253 ) &&
V_95 -> V_145 ) {
T_1 V_329 = V_95 -> V_328 *
V_95 -> V_98 -> V_166 . V_167 ;
V_33 = F_164 ( & V_95 -> V_221 ,
& V_95 -> V_222 ,
V_329 , V_321 , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
F_78 ( V_95 ) ;
if ( V_95 -> V_157 != V_160 || V_95 -> V_145 == 0 ) {
F_147 ( V_95 ) ;
return 0 ;
}
F_35 ( & V_95 -> V_103 , V_72 ) ;
V_95 -> V_138 = V_330 ;
if ( V_95 -> V_104 & V_105 ) {
F_33 ( L_40 ,
V_106 , __LINE__ , V_95 -> V_107 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
F_63 ( & V_95 -> V_108 ) ;
return 0 ;
}
V_95 -> V_104 &= ~ V_109 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
V_33 = V_95 -> V_92 -> V_301 ( V_95 ) ;
if ( V_33 )
goto V_278;
return 0 ;
V_278:
F_33 ( L_120 , V_95 ) ;
F_134 ( V_95 , V_95 -> V_98 , V_33 , true ) ;
return 0 ;
}
static void F_84 ( struct V_94 * V_95 )
{
int V_33 ;
V_33 = V_95 -> V_92 -> V_301 ( V_95 ) ;
if ( V_33 ) {
F_33 ( L_120 ,
V_95 ) ;
F_134 ( V_95 , V_95 -> V_98 , V_33 , true ) ;
}
}
static void F_171 ( struct V_94 * V_95 , bool * V_331 , bool * V_332 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
F_172 ( V_95 , true , V_331 , V_332 , & V_72 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
}
int F_173 ( struct V_94 * V_95 , int V_333 )
{
int V_33 = 0 ;
bool V_331 = false , V_332 = false ;
if ( ! ( V_95 -> V_115 & V_117 ) ) {
if ( V_333 && ( V_95 -> V_115 & V_334 ) )
F_171 ( V_95 , & V_331 , & V_332 ) ;
if ( ! V_331 || V_332 )
V_33 = F_68 ( V_95 ) ;
} else {
if ( V_333 )
F_171 ( V_95 , & V_331 , & V_332 ) ;
if ( V_95 -> V_100 )
F_61 ( V_95 ) ;
if ( V_95 -> V_102 )
F_64 ( V_95 ) ;
if ( ! V_331 || V_332 )
V_33 = F_68 ( V_95 ) ;
}
if ( V_331 ) {
F_33 ( L_121 , V_95 -> V_107 ) ;
F_174 ( & V_95 -> V_199 ) ;
V_95 -> V_92 -> V_335 ( V_95 ) ;
V_33 = 1 ;
}
return V_33 ;
}
int F_114 ( struct V_94 * V_94 , bool V_114 )
{
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
int V_33 = 0 ;
if ( V_114 ) {
if ( ! F_175 ( & V_94 -> V_200 ) )
return - V_51 ;
V_94 -> V_115 |= V_116 ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_336 ) {
V_33 = - V_337 ;
goto V_3;
}
F_31 ( & V_94 -> V_198 , & V_37 -> V_41 ) ;
V_3:
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( V_33 && V_114 )
F_117 ( V_94 ) ;
return V_33 ;
}
static void F_176 ( struct V_94 * V_95 )
{
F_158 ( V_95 ) ;
if ( V_95 -> V_115 & V_334 )
F_126 ( V_95 -> V_239 ) ;
if ( V_95 -> V_193 != V_95 -> V_207 )
F_52 ( V_95 -> V_193 ) ;
}
static void F_177 ( struct V_84 * V_84 )
{
struct V_94 * V_94 = F_45 ( V_84 , struct V_94 , V_200 ) ;
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
bool V_338 ;
if ( V_37 ) {
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_11 ( & V_94 -> V_103 ) ;
V_338 = ( V_94 -> V_104 & V_339 ) &&
( V_94 -> V_104 & V_136 ) ;
F_12 ( & V_94 -> V_103 ) ;
if ( V_94 -> V_340 || V_338 ) {
F_57 ( & V_94 -> V_198 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
F_176 ( V_94 ) ;
F_46 ( & V_94 -> V_199 ) ;
return;
}
F_57 ( & V_94 -> V_198 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
F_176 ( V_94 ) ;
V_94 -> V_92 -> V_335 ( V_94 ) ;
}
int F_117 ( struct V_94 * V_94 )
{
return F_54 ( & V_94 -> V_200 , F_177 ) ;
}
void F_178 ( struct V_2 * V_37 )
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
F_81 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_82 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
V_46 = F_175 ( & V_94 -> V_200 ) ;
if ( V_46 ) {
V_94 -> V_340 = 1 ;
F_11 ( & V_94 -> V_103 ) ;
V_94 -> V_104 |= V_339 ;
F_12 ( & V_94 -> V_103 ) ;
} else
F_57 ( & V_94 -> V_198 ) ;
}
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
void F_179 ( struct V_2 * V_37 )
{
struct V_94 * V_94 , * V_341 ;
unsigned long V_72 ;
bool V_332 ;
F_82 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_33 ( L_122
L_123 , V_94 , V_94 -> V_138 ,
V_94 -> V_92 -> V_251 ( V_94 ) ) ;
F_35 ( & V_94 -> V_103 , V_72 ) ;
V_332 = ( V_94 -> V_104 & V_342 ) ;
F_36 ( & V_94 -> V_103 , V_72 ) ;
if ( ! F_117 ( V_94 ) ) {
if ( V_332 )
F_117 ( V_94 ) ;
}
F_174 ( & V_94 -> V_199 ) ;
F_33 ( L_124
L_125 , V_94 , V_94 -> V_138 ,
V_94 -> V_92 -> V_251 ( V_94 ) ) ;
V_94 -> V_92 -> V_335 ( V_94 ) ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_72 ( ! F_56 ( & V_37 -> V_41 ) ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
static void F_180 ( struct V_343 * V_344 )
{
struct V_102 * V_111 = F_45 ( V_344 , struct V_102 , V_113 ) ;
F_46 ( & V_111 -> V_345 ) ;
}
void F_181 ( struct V_102 * V_111 )
{
F_182 ( & V_111 -> V_113 , F_180 ) ;
F_174 ( & V_111 -> V_345 ) ;
F_174 ( & V_111 -> V_346 ) ;
}
static bool
F_172 ( struct V_94 * V_95 , bool V_338 ,
bool * V_331 , bool * V_332 , unsigned long * V_72 )
__releases( &cmd->t_state_lock
bool F_183 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_33 , V_331 = false , V_332 = false ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
V_33 = F_172 ( V_95 , false , & V_331 , & V_332 , & V_72 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
return V_33 ;
}
static int F_151 ( struct V_94 * V_95 , T_5 V_347 )
{
const struct V_348 * V_349 ;
T_4 * V_350 = V_95 -> V_130 ;
int V_351 = ( V_352 int ) V_347 ;
T_4 V_353 , V_354 ;
bool V_355 = F_184 ( V_95 -> V_98 ) ;
if ( V_351 < F_185 ( V_356 ) && V_356 [ V_351 ] . V_357 )
V_349 = & V_356 [ V_351 ] ;
else
V_349 = & V_356 [ ( V_352 int )
V_121 ] ;
if ( V_347 == V_262 ) {
F_186 ( V_95 , & V_353 , & V_354 ) ;
F_187 ( V_353 == 0 ) ;
} else if ( V_349 -> V_353 == 0 ) {
F_187 ( V_95 -> V_358 == 0 ) ;
V_353 = V_95 -> V_358 ;
V_354 = V_95 -> V_359 ;
} else {
V_353 = V_349 -> V_353 ;
V_354 = V_349 -> V_354 ;
}
F_188 ( V_355 , V_350 , V_349 -> V_357 , V_353 , V_354 ) ;
if ( V_349 -> V_360 )
return F_189 ( V_350 ,
V_95 -> V_123 ,
V_95 -> V_361 ) ;
return 0 ;
}
int
F_116 ( struct V_94 * V_95 ,
T_5 V_347 , int V_362 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_122 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
return 0 ;
}
V_95 -> V_115 |= V_122 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( ! V_362 ) {
int V_46 ;
V_95 -> V_115 |= V_298 ;
V_95 -> V_129 = V_299 ;
V_95 -> V_123 = V_124 ;
V_46 = F_151 ( V_95 , V_347 ) ;
if ( V_46 )
return V_46 ;
}
F_133 ( V_95 ) ;
return V_95 -> V_92 -> V_277 ( V_95 ) ;
}
static int F_148 ( struct V_94 * V_95 , int V_363 )
__releases( &cmd->t_state_lock
int F_130 ( struct V_94 * V_95 , int V_363 )
{
int V_33 ;
F_30 ( & V_95 -> V_103 ) ;
V_33 = F_148 ( V_95 , V_363 ) ;
F_32 ( & V_95 -> V_103 ) ;
return V_33 ;
}
void F_190 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
int V_33 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & ( V_122 ) ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
return;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_157 == V_160 ) {
if ( V_95 -> V_92 -> V_364 ( V_95 ) != 0 ) {
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_365 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_366;
}
V_95 -> V_115 |= V_365 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
return;
}
}
V_366:
V_95 -> V_129 = V_367 ;
F_64 ( V_95 ) ;
F_33 ( L_126 ,
V_95 -> V_193 [ 0 ] , V_95 -> V_107 ) ;
F_133 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_277 ( V_95 ) ;
if ( V_33 )
F_134 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
static void F_191 ( struct V_119 * V_120 )
{
struct V_94 * V_95 = F_45 ( V_120 , struct V_94 , V_120 ) ;
struct V_96 * V_97 = V_95 -> V_98 ;
struct V_239 * V_368 = V_95 -> V_239 ;
unsigned long V_72 ;
int V_33 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
V_368 -> V_240 = V_369 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_279;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
switch ( V_368 -> V_370 ) {
case V_247 :
F_192 ( V_97 , V_368 , V_95 -> V_37 ) ;
break;
case V_371 :
case V_372 :
case V_373 :
V_368 -> V_240 = V_374 ;
break;
case V_375 :
V_33 = F_193 ( V_97 , V_368 , NULL , NULL ) ;
V_368 -> V_240 = ( ! V_33 ) ? V_376 :
V_369 ;
if ( V_368 -> V_240 == V_376 ) {
F_132 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_275 , 0x29 ,
V_377 ) ;
}
break;
case V_378 :
V_368 -> V_240 = V_369 ;
break;
case V_379 :
V_368 -> V_240 = V_369 ;
break;
default:
F_4 ( L_127 ,
V_368 -> V_370 ) ;
V_368 -> V_240 = V_369 ;
break;
}
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_279;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
V_95 -> V_92 -> V_242 ( V_95 ) ;
V_279:
F_62 ( V_95 ) ;
}
int F_129 (
struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_331 = false ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
V_331 = true ;
} else {
V_95 -> V_138 = V_380 ;
V_95 -> V_104 |= V_109 ;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_331 ) {
F_106 ( L_128
L_129 , V_95 -> V_239 -> V_370 ,
V_95 -> V_239 -> V_248 , V_95 -> V_107 ) ;
F_62 ( V_95 ) ;
return 0 ;
}
F_74 ( & V_95 -> V_120 , F_191 ) ;
F_76 ( V_95 -> V_98 -> V_381 , & V_95 -> V_120 ) ;
return 0 ;
}
bool
F_194 ( struct V_96 * V_97 )
{
bool V_382 = false ;
if ( V_97 -> V_127 -> V_383 )
V_382 = V_97 -> V_127 -> V_383 ( V_97 ) ;
else if ( V_97 -> V_166 . V_384 > 0 )
V_382 = true ;
return V_382 ;
}
bool
F_195 ( struct V_96 * V_97 )
{
return F_194 ( V_97 ) && V_97 -> V_166 . V_385 > 0 ;
}
