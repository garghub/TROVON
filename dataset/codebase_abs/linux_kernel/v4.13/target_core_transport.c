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
F_48 ( & V_37 -> V_40 ) ;
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
F_57 ( & V_37 -> V_50 ) ;
F_24 ( V_37 -> V_47 ) ;
}
F_58 ( V_1 , V_37 ) ;
}
void F_59 ( struct V_2 * V_37 )
{
struct V_52 * V_53 = V_37 -> V_53 ;
unsigned long V_72 ;
if ( ! V_53 ) {
F_27 ( V_37 ) ;
return;
}
F_35 ( & V_53 -> V_73 , V_72 ) ;
F_60 ( & V_37 -> V_39 ) ;
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
F_60 ( & V_95 -> V_101 ) ;
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
int F_67 ( struct V_94 * V_95 , int remove )
{
bool V_114 = ( V_95 -> V_115 & V_116 ) ;
int V_33 = 0 ;
if ( V_95 -> V_115 & V_117 )
F_64 ( V_95 ) ;
if ( remove )
V_95 -> V_92 -> V_118 ( V_95 ) ;
if ( F_62 ( V_95 ) )
return 1 ;
if ( remove && V_114 )
V_33 = F_68 ( V_95 ) ;
return V_33 ;
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
void F_73 ( struct V_94 * V_95 , unsigned char * V_131 )
{
unsigned char * V_132 ;
unsigned long V_72 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
V_132 = F_71 ( V_95 ) ;
if ( ! V_132 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
return;
}
V_95 -> V_115 |= V_133 ;
memcpy ( V_132 , V_131 , V_95 -> V_123 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
}
void F_74 ( struct V_94 * V_95 , T_4 V_129 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_134 ;
unsigned long V_72 ;
V_95 -> V_129 = V_129 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
switch ( V_95 -> V_129 ) {
case V_135 :
if ( V_95 -> V_115 & V_133 )
V_134 = 1 ;
else
V_134 = 0 ;
break;
default:
V_134 = 1 ;
break;
}
if ( V_95 -> V_104 & V_136 ||
V_95 -> V_104 & V_105 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_137 ) {
F_75 ( & V_97 -> V_138 ) ;
}
F_63 ( & V_95 -> V_108 ) ;
return;
} else if ( ! V_134 ) {
F_76 ( & V_95 -> V_120 , F_69 ) ;
} else {
F_76 ( & V_95 -> V_120 , V_139 ) ;
}
V_95 -> V_140 = V_141 ;
V_95 -> V_104 |= ( V_142 | V_109 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_143 )
F_77 ( V_95 -> V_144 , V_25 , & V_95 -> V_120 ) ;
else
F_78 ( V_25 , & V_95 -> V_120 ) ;
}
void F_79 ( struct V_94 * V_95 , T_4 V_129 , int V_145 )
{
if ( V_129 == V_146 && V_145 < V_95 -> V_147 ) {
if ( V_95 -> V_115 & V_148 ) {
V_95 -> V_149 += V_95 -> V_147 - V_145 ;
} else {
V_95 -> V_115 |= V_148 ;
V_95 -> V_149 = V_95 -> V_147 - V_145 ;
}
V_95 -> V_147 = V_145 ;
}
F_74 ( V_95 , V_129 ) ;
}
static void F_80 ( struct V_94 * V_95 )
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
void F_81 ( struct V_119 * V_120 )
{
struct V_96 * V_97 = F_45 ( V_120 , struct V_96 ,
V_150 ) ;
F_82 ( V_151 ) ;
struct V_94 * V_95 , * V_152 ;
F_30 ( & V_97 -> V_153 ) ;
F_83 ( & V_97 -> V_151 , & V_151 ) ;
F_32 ( & V_97 -> V_153 ) ;
F_84 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_60 ( & V_95 -> V_154 ) ;
F_85 ( & V_97 -> V_155 ) ;
F_33 ( L_42
L_43 , V_95 -> V_92 -> V_71 () , V_95 ,
( V_95 -> V_140 == V_156 ) ? L_44 :
( V_95 -> V_140 == V_157 ) ? L_45
: L_46 ) ;
if ( V_95 -> V_140 == V_157 )
F_86 ( V_95 ) ;
else if ( V_95 -> V_140 == V_156 ||
V_95 -> V_140 == V_158 )
F_87 ( V_95 ) ;
}
}
unsigned char * F_88 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_159 ) {
case V_160 :
return L_47 ;
case V_161 :
return L_48 ;
case V_162 :
return L_49 ;
case V_163 :
return L_50 ;
default:
break;
}
return L_46 ;
}
void F_89 (
struct V_96 * V_97 ,
char * V_164 ,
int * V_165 )
{
* V_165 += sprintf ( V_164 + * V_165 , L_51 ) ;
if ( V_97 -> V_166 )
* V_165 += sprintf ( V_164 + * V_165 , L_52 ) ;
else
* V_165 += sprintf ( V_164 + * V_165 , L_53 ) ;
* V_165 += sprintf ( V_164 + * V_165 , L_54 , V_97 -> V_167 ) ;
* V_165 += sprintf ( V_164 + * V_165 , L_55 ,
V_97 -> V_168 . V_169 ,
V_97 -> V_168 . V_170 ) ;
* V_165 += sprintf ( V_164 + * V_165 , L_56 ) ;
}
void F_90 (
struct V_171 * V_172 ,
unsigned char * V_173 ,
int V_174 )
{
unsigned char V_60 [ V_175 ] ;
int V_81 ;
memset ( V_60 , 0 , V_175 ) ;
V_81 = sprintf ( V_60 , L_57 ) ;
switch ( V_172 -> V_176 ) {
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
V_172 -> V_176 ) ;
break;
}
if ( V_173 )
strncpy ( V_173 , V_60 , V_174 ) ;
else
F_33 ( L_69 , V_60 ) ;
}
void
F_91 ( struct V_171 * V_172 , unsigned char * V_177 )
{
if ( V_177 [ 1 ] & 0x80 ) {
V_172 -> V_176 = ( V_177 [ 0 ] & 0xf0 ) ;
V_172 -> V_178 = 1 ;
F_90 ( V_172 , NULL , 0 ) ;
}
}
int F_92 (
struct V_171 * V_172 ,
unsigned char * V_173 ,
int V_174 )
{
unsigned char V_60 [ V_175 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_175 ) ;
V_81 = sprintf ( V_60 , L_70 ) ;
switch ( V_172 -> V_179 ) {
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
sprintf ( V_60 + V_81 , L_68 , V_172 -> V_179 ) ;
V_33 = - V_51 ;
break;
}
if ( V_173 )
strncpy ( V_173 , V_60 , V_174 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int F_93 ( struct V_171 * V_172 , unsigned char * V_177 )
{
V_172 -> V_179 = ( V_177 [ 1 ] & 0x30 ) ;
return F_92 ( V_172 , NULL , 0 ) ;
}
int F_94 (
struct V_171 * V_172 ,
unsigned char * V_173 ,
int V_174 )
{
unsigned char V_60 [ V_175 ] ;
int V_33 = 0 ;
int V_81 ;
memset ( V_60 , 0 , V_175 ) ;
V_81 = sprintf ( V_60 , L_74 ) ;
switch ( V_172 -> V_180 ) {
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
V_172 -> V_180 ) ;
V_33 = - V_51 ;
break;
}
if ( V_173 ) {
if ( V_174 < strlen ( V_60 ) + 1 )
return - V_51 ;
strncpy ( V_173 , V_60 , V_174 ) ;
} else {
F_33 ( L_69 , V_60 ) ;
}
return V_33 ;
}
int F_95 ( struct V_171 * V_172 , unsigned char * V_177 )
{
V_172 -> V_180 = ( V_177 [ 1 ] & 0x0f ) ;
return F_94 ( V_172 , NULL , 0 ) ;
}
int F_96 (
struct V_171 * V_172 ,
unsigned char * V_173 ,
int V_174 )
{
unsigned char V_60 [ V_175 ] ;
int V_33 = 0 ;
memset ( V_60 , 0 , V_175 ) ;
switch ( V_172 -> V_181 ) {
case 0x01 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_82 ,
& V_172 -> V_182 [ 0 ] ) ;
break;
case 0x02 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_83 ,
& V_172 -> V_182 [ 0 ] ) ;
break;
case 0x03 :
snprintf ( V_60 , sizeof( V_60 ) ,
L_84 ,
& V_172 -> V_182 [ 0 ] ) ;
break;
default:
sprintf ( V_60 , L_85
L_86 , V_172 -> V_181 ) ;
V_33 = - V_51 ;
break;
}
if ( V_173 )
strncpy ( V_173 , V_60 , V_174 ) ;
else
F_33 ( L_69 , V_60 ) ;
return V_33 ;
}
int
F_97 ( struct V_171 * V_172 , unsigned char * V_177 )
{
static const char V_183 [] = L_87 ;
int V_184 = 0 , V_185 = 4 ;
V_172 -> V_181 = ( V_177 [ 0 ] & 0x0f ) ;
switch ( V_172 -> V_181 ) {
case 0x01 :
V_172 -> V_182 [ V_184 ++ ] =
V_183 [ V_172 -> V_180 ] ;
while ( V_185 < ( 4 + V_177 [ 3 ] ) ) {
V_172 -> V_182 [ V_184 ++ ] =
V_183 [ ( V_177 [ V_185 ] & 0xf0 ) >> 4 ] ;
V_172 -> V_182 [ V_184 ++ ] =
V_183 [ V_177 [ V_185 ] & 0x0f ] ;
V_185 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_185 < ( 4 + V_177 [ 3 ] ) )
V_172 -> V_182 [ V_184 ++ ] = V_177 [ V_185 ++ ] ;
break;
default:
break;
}
return F_96 ( V_172 , NULL , 0 ) ;
}
static T_5
F_98 ( struct V_94 * V_95 , struct V_96 * V_97 ,
unsigned int V_186 )
{
T_1 V_187 ;
if ( ! V_95 -> V_92 -> V_188 )
return V_189 ;
V_187 = ( V_95 -> V_92 -> V_188 * V_83 ) ;
if ( V_95 -> V_147 > V_187 ) {
if ( V_95 -> V_115 & V_190 ) {
V_95 -> V_149 = ( V_186 - V_187 ) ;
} else if ( V_95 -> V_115 & V_148 ) {
T_1 V_191 = V_186 + V_95 -> V_149 ;
V_95 -> V_149 = ( V_191 - V_187 ) ;
} else {
V_95 -> V_115 |= V_148 ;
V_95 -> V_149 = ( V_95 -> V_147 - V_187 ) ;
}
V_95 -> V_147 = V_187 ;
if ( V_95 -> V_192 ) {
T_1 V_193 = ( V_187 / V_97 -> V_168 . V_169 ) ;
V_95 -> V_192 = V_97 -> V_192 * V_193 ;
}
}
return V_189 ;
}
T_5
F_99 ( struct V_94 * V_95 , unsigned int V_186 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_95 -> V_194 ) {
V_95 -> V_147 = V_186 ;
} else if ( V_186 != V_95 -> V_147 ) {
F_100 ( L_88
L_89
L_90 , V_95 -> V_92 -> V_71 () ,
V_95 -> V_147 , V_186 , V_95 -> V_195 [ 0 ] ) ;
if ( V_95 -> V_159 == V_162 ) {
if ( V_95 -> V_115 & V_196 ) {
F_101 ( L_91
L_92 ) ;
return V_197 ;
}
if ( V_186 > V_95 -> V_147 ) {
F_101 ( L_93
L_94 ) ;
return V_197 ;
}
}
if ( V_97 -> V_168 . V_169 != 512 ) {
F_4 ( L_95
L_96
L_97 , V_97 -> V_127 -> V_128 ) ;
return V_197 ;
}
if ( V_186 > V_95 -> V_147 ) {
V_95 -> V_115 |= V_190 ;
V_95 -> V_149 = ( V_186 - V_95 -> V_147 ) ;
} else {
V_95 -> V_115 |= V_148 ;
V_95 -> V_149 = ( V_95 -> V_147 - V_186 ) ;
V_95 -> V_147 = V_186 ;
}
}
return F_98 ( V_95 , V_97 , V_186 ) ;
}
void F_102 (
struct V_94 * V_95 ,
const struct V_57 * V_58 ,
struct V_2 * V_37 ,
T_1 V_147 ,
int V_159 ,
int V_198 ,
unsigned char * V_130 )
{
F_18 ( & V_95 -> V_199 ) ;
F_18 ( & V_95 -> V_154 ) ;
F_18 ( & V_95 -> V_200 ) ;
F_18 ( & V_95 -> V_101 ) ;
F_103 ( & V_95 -> V_108 ) ;
F_103 ( & V_95 -> V_201 ) ;
F_19 ( & V_95 -> V_103 ) ;
F_76 ( & V_95 -> V_120 , NULL ) ;
F_104 ( & V_95 -> V_202 ) ;
V_95 -> V_92 = V_58 ;
V_95 -> V_37 = V_37 ;
V_95 -> V_147 = V_147 ;
V_95 -> V_159 = V_159 ;
V_95 -> V_203 = V_198 ;
V_95 -> V_130 = V_130 ;
V_95 -> V_100 = false ;
}
static T_5
F_105 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_127 -> V_204 & V_205 )
return 0 ;
if ( V_95 -> V_203 == V_206 ) {
F_33 ( L_98
L_99 ) ;
return V_197 ;
}
return 0 ;
}
T_5
F_106 ( struct V_94 * V_95 , unsigned char * V_207 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
T_5 V_33 ;
if ( F_107 ( V_207 ) > V_208 ) {
F_4 ( L_100
L_101 ,
F_107 ( V_207 ) , V_208 ) ;
return V_197 ;
}
if ( F_107 ( V_207 ) > sizeof( V_95 -> V_209 ) ) {
V_95 -> V_195 = F_21 ( F_107 ( V_207 ) ,
V_38 ) ;
if ( ! V_95 -> V_195 ) {
F_4 ( L_102
L_103 ,
F_107 ( V_207 ) ,
( unsigned long ) sizeof( V_95 -> V_209 ) ) ;
return V_210 ;
}
} else
V_95 -> V_195 = & V_95 -> V_209 [ 0 ] ;
memcpy ( V_95 -> V_195 , V_207 , F_107 ( V_207 ) ) ;
F_108 ( V_95 ) ;
V_33 = V_97 -> V_127 -> V_211 ( V_95 ) ;
if ( V_33 == V_212 )
F_100 ( L_104 ,
V_95 -> V_92 -> V_71 () ,
V_95 -> V_37 -> V_54 -> V_76 ,
V_95 -> V_195 [ 0 ] ) ;
if ( V_33 )
return V_33 ;
V_33 = F_105 ( V_95 ) ;
if ( V_33 )
return V_33 ;
V_95 -> V_115 |= V_213 ;
F_109 ( & V_95 -> V_102 -> V_214 . V_215 ) ;
return 0 ;
}
int F_110 (
struct V_94 * V_95 )
{
T_5 V_33 ;
if ( ! V_95 -> V_102 ) {
F_111 () ;
F_4 ( L_105 ) ;
return - V_51 ;
}
if ( F_112 () ) {
F_111 () ;
F_4 ( L_106
L_107 ) ;
return - V_51 ;
}
V_95 -> V_140 = V_216 ;
V_95 -> V_104 |= V_109 ;
V_33 = F_113 ( V_95 ) ;
if ( V_33 )
F_70 ( V_95 , V_33 ) ;
return 0 ;
}
T_5
F_114 ( struct V_94 * V_95 , struct V_217 * V_218 ,
T_1 V_219 , struct V_217 * V_220 , T_1 V_221 )
{
if ( ! V_218 || ! V_219 )
return 0 ;
if ( V_95 -> V_115 & V_190 ) {
F_115 ( L_108
L_109 ) ;
return V_197 ;
}
V_95 -> V_222 = V_218 ;
V_95 -> V_223 = V_219 ;
V_95 -> V_224 = V_220 ;
V_95 -> V_225 = V_221 ;
V_95 -> V_115 |= V_226 ;
return 0 ;
}
int F_116 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_131 , T_6 V_227 ,
T_1 V_147 , int V_198 , int V_228 , int V_72 ,
struct V_217 * V_218 , T_1 V_219 ,
struct V_217 * V_220 , T_1 V_221 ,
struct V_217 * V_229 , T_1 V_230 )
{
struct V_52 * V_53 ;
T_5 V_46 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_10 ( V_94 -> V_92 || V_94 -> V_37 ) ;
F_10 ( F_112 () ) ;
F_102 ( V_94 , V_53 -> V_59 , V_37 ,
V_147 , V_228 , V_198 , V_131 ) ;
if ( V_72 & V_231 )
V_94 -> V_115 |= V_143 ;
else
V_94 -> V_144 = V_232 ;
if ( V_72 & V_233 )
V_94 -> V_194 = 1 ;
V_33 = F_117 ( V_94 , V_72 & V_234 ) ;
if ( V_33 )
return V_33 ;
if ( V_72 & V_235 )
V_94 -> V_115 |= V_236 ;
V_46 = F_118 ( V_94 , V_227 ) ;
if ( V_46 ) {
F_119 ( V_94 , V_46 , 0 ) ;
F_120 ( V_94 ) ;
return 0 ;
}
V_46 = F_106 ( V_94 , V_207 ) ;
if ( V_46 != 0 ) {
F_70 ( V_94 , V_46 ) ;
return 0 ;
}
if ( V_230 ) {
V_94 -> V_237 = V_229 ;
V_94 -> V_238 = V_230 ;
V_94 -> V_115 |= V_239 ;
}
if ( V_219 != 0 ) {
F_10 ( ! V_218 ) ;
if ( ! ( V_94 -> V_115 & V_196 ) &&
V_94 -> V_159 == V_161 ) {
unsigned char * V_60 = NULL ;
if ( V_218 )
V_60 = F_121 ( F_122 ( V_218 ) ) + V_218 -> V_240 ;
if ( V_60 ) {
memset ( V_60 , 0 , V_218 -> V_145 ) ;
F_123 ( F_122 ( V_218 ) ) ;
}
}
V_46 = F_114 ( V_94 , V_218 , V_219 ,
V_220 , V_221 ) ;
if ( V_46 != 0 ) {
F_70 ( V_94 , V_46 ) ;
return 0 ;
}
}
F_124 ( V_94 ) ;
F_110 ( V_94 ) ;
return 0 ;
}
int F_125 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_207 , unsigned char * V_131 , T_6 V_227 ,
T_1 V_147 , int V_198 , int V_228 , int V_72 )
{
return F_116 ( V_94 , V_37 , V_207 , V_131 ,
V_227 , V_147 , V_198 , V_228 ,
V_72 , NULL , 0 , NULL , 0 , NULL , 0 ) ;
}
static void F_126 ( struct V_119 * V_120 )
{
struct V_94 * V_94 = F_45 ( V_120 , struct V_94 , V_120 ) ;
V_94 -> V_241 -> V_242 = V_243 ;
V_94 -> V_92 -> V_244 ( V_94 ) ;
F_64 ( V_94 ) ;
F_62 ( V_94 ) ;
}
static bool F_127 ( struct V_2 * V_37 , T_6 V_107 ,
T_6 * V_227 )
{
struct V_94 * V_94 ;
unsigned long V_72 ;
bool V_33 = false ;
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_42 (se_cmd, &se_sess->sess_cmd_list, se_cmd_list) {
if ( V_94 -> V_115 & V_245 )
continue;
if ( V_94 -> V_107 == V_107 ) {
* V_227 = V_94 -> V_246 ;
V_33 = true ;
break;
}
}
F_36 ( & V_37 -> V_43 , V_72 ) ;
return V_33 ;
}
int F_128 ( struct V_94 * V_94 , struct V_2 * V_37 ,
unsigned char * V_131 , T_6 V_227 ,
void * V_247 , unsigned char V_248 ,
T_7 V_249 , T_6 V_107 , int V_72 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_37 -> V_53 ;
F_10 ( ! V_53 ) ;
F_102 ( V_94 , V_53 -> V_59 , V_37 ,
0 , V_160 , V_250 , V_131 ) ;
V_33 = F_129 ( V_94 , V_247 , V_248 , V_249 ) ;
if ( V_33 < 0 )
return - V_28 ;
if ( V_248 == V_251 )
V_94 -> V_241 -> V_252 = V_107 ;
V_33 = F_117 ( V_94 , V_72 & V_234 ) ;
if ( V_33 ) {
F_130 ( V_94 -> V_241 ) ;
return V_33 ;
}
if ( V_248 == V_251 && ( V_72 & V_253 ) ) {
if ( ! F_127 ( V_37 , V_107 , & V_227 ) )
goto V_254;
}
V_33 = F_131 ( V_94 , V_227 ) ;
if ( V_33 )
goto V_254;
F_132 ( V_94 ) ;
return 0 ;
V_254:
F_76 ( & V_94 -> V_120 , F_126 ) ;
F_133 ( & V_94 -> V_120 ) ;
return 0 ;
}
void F_70 ( struct V_94 * V_95 ,
T_5 V_255 )
{
int V_33 = 0 , V_256 = 0 ;
if ( F_134 ( V_95 , 1 ) )
return;
F_33 ( L_110 ,
V_255 ) ;
F_135 ( L_111 , V_95 ) ;
F_136 ( V_95 ) ;
if ( ( V_95 -> V_115 & V_137 ) &&
V_95 -> V_257 )
V_95 -> V_257 ( V_95 , false , & V_256 ) ;
switch ( V_255 ) {
case V_258 :
case V_212 :
case V_197 :
case V_259 :
case V_260 :
case V_121 :
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
case V_272 :
case V_273 :
case V_274 :
break;
case V_210 :
V_255 = V_121 ;
break;
case V_275 :
V_95 -> V_129 = V_276 ;
if ( V_95 -> V_37 &&
V_95 -> V_98 -> V_168 . V_277 == 2 ) {
F_137 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_246 , 0x2C ,
V_278 ) ;
}
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_279 ( V_95 ) ;
if ( V_33 )
goto V_280;
goto V_281;
default:
F_4 ( L_112 ,
V_95 -> V_195 [ 0 ] , V_255 ) ;
V_255 = V_212 ;
break;
}
V_33 = F_119 ( V_95 , V_255 , 0 ) ;
if ( V_33 )
goto V_280;
V_281:
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
V_280:
F_139 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
void F_140 ( struct V_94 * V_95 , bool V_282 )
{
T_5 V_33 ;
if ( ! V_95 -> V_283 ) {
V_33 = V_121 ;
goto V_284;
}
if ( V_282 ) {
V_33 = F_141 ( V_95 ) ;
if ( V_33 )
goto V_284;
V_33 = F_142 ( V_95 ) ;
if ( V_33 )
goto V_284;
V_33 = F_143 ( V_95 ) ;
if ( V_33 ) {
V_95 -> V_129 = V_276 ;
goto V_284;
}
}
V_33 = V_95 -> V_283 ( V_95 ) ;
if ( ! V_33 )
return;
V_284:
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_285 ;
F_32 ( & V_95 -> V_103 ) ;
F_70 ( V_95 , V_33 ) ;
}
static int F_144 ( struct V_94 * V_95 )
{
T_1 V_193 ;
switch ( V_95 -> V_75 ) {
case V_286 :
if ( ! ( V_95 -> V_37 -> V_36 & V_286 ) )
F_145 ( V_95 ) ;
break;
case V_287 :
if ( V_95 -> V_37 -> V_36 & V_287 )
break;
V_193 = V_95 -> V_147 >> F_146 ( V_95 -> V_98 -> V_168 . V_169 ) ;
V_95 -> V_288 = F_147 ( V_95 , V_95 -> V_289 ,
V_193 , 0 , V_95 -> V_237 , 0 ) ;
if ( F_148 ( V_95 -> V_288 ) ) {
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_285 ;
F_32 ( & V_95 -> V_103 ) ;
F_70 ( V_95 , V_95 -> V_288 ) ;
return - 1 ;
}
break;
default:
break;
}
return 0 ;
}
static bool F_149 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_127 -> V_204 & V_205 )
return false ;
V_95 -> V_115 |= V_290 ;
switch ( V_95 -> V_203 ) {
case V_291 :
F_33 ( L_113 ,
V_95 -> V_195 [ 0 ] ) ;
return false ;
case V_292 :
F_150 ( & V_97 -> V_293 ) ;
F_33 ( L_114 ,
V_95 -> V_195 [ 0 ] ) ;
if ( ! F_151 ( & V_97 -> V_294 ) )
return false ;
break;
default:
F_150 ( & V_97 -> V_294 ) ;
break;
}
if ( F_151 ( & V_97 -> V_293 ) == 0 )
return false ;
F_11 ( & V_97 -> V_295 ) ;
F_31 ( & V_95 -> V_199 , & V_97 -> V_296 ) ;
F_12 ( & V_97 -> V_295 ) ;
F_33 ( L_115 ,
V_95 -> V_195 [ 0 ] , V_95 -> V_203 ) ;
return true ;
}
void F_152 ( struct V_94 * V_95 )
{
F_30 ( & V_95 -> V_103 ) ;
if ( F_153 ( V_95 , 1 ) ) {
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
V_95 -> V_140 = V_297 ;
V_95 -> V_104 |= V_109 | V_285 ;
F_32 ( & V_95 -> V_103 ) ;
if ( F_144 ( V_95 ) )
return;
if ( F_149 ( V_95 ) ) {
F_30 ( & V_95 -> V_103 ) ;
V_95 -> V_104 &= ~ V_285 ;
F_32 ( & V_95 -> V_103 ) ;
return;
}
F_140 ( V_95 , true ) ;
}
static void F_154 ( struct V_96 * V_97 )
{
for (; ; ) {
struct V_94 * V_95 ;
F_11 ( & V_97 -> V_295 ) ;
if ( F_56 ( & V_97 -> V_296 ) ) {
F_12 ( & V_97 -> V_295 ) ;
break;
}
V_95 = F_155 ( V_97 -> V_296 . V_298 ,
struct V_94 , V_199 ) ;
F_60 ( & V_95 -> V_199 ) ;
F_12 ( & V_97 -> V_295 ) ;
F_140 ( V_95 , true ) ;
if ( V_95 -> V_203 == V_292 )
break;
}
}
static void F_136 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( V_97 -> V_127 -> V_204 & V_205 )
return;
if ( ! ( V_95 -> V_115 & V_290 ) )
goto V_299;
if ( V_95 -> V_203 == V_250 ) {
F_85 ( & V_97 -> V_294 ) ;
V_97 -> V_300 ++ ;
} else if ( V_95 -> V_203 == V_291 ) {
V_97 -> V_300 ++ ;
F_33 ( L_116 ,
V_97 -> V_300 ) ;
} else if ( V_95 -> V_203 == V_292 ) {
F_85 ( & V_97 -> V_293 ) ;
V_97 -> V_300 ++ ;
F_33 ( L_117 ,
V_97 -> V_300 ) ;
}
V_299:
F_154 ( V_97 ) ;
}
static void F_87 ( struct V_94 * V_95 )
{
int V_33 = 0 ;
F_136 ( V_95 ) ;
if ( V_95 -> V_140 == V_158 ) {
if ( V_95 -> V_129 )
goto V_279;
V_95 -> V_115 |= V_301 ;
V_95 -> V_129 = V_135 ;
V_95 -> V_123 = V_124 ;
F_156 ( V_95 , V_121 ) ;
goto V_279;
}
if ( V_95 -> V_115 & V_133 )
goto V_279;
switch ( V_95 -> V_159 ) {
case V_161 :
if ( V_95 -> V_129 )
goto V_279;
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_302 ( V_95 ) ;
break;
case V_162 :
if ( V_95 -> V_115 & V_236 ) {
V_33 = V_95 -> V_92 -> V_302 ( V_95 ) ;
break;
}
case V_160 :
V_279:
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_279 ( V_95 ) ;
break;
default:
break;
}
if ( V_33 < 0 ) {
F_139 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
return;
}
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
}
static void F_139 ( struct V_94 * V_95 , struct V_96 * V_97 ,
int V_284 , bool V_303 )
{
if ( V_284 == - V_304 || V_284 == - V_28 ) {
V_95 -> V_140 = ( V_303 ) ? V_157 :
V_156 ;
} else {
F_100 ( L_118 , V_284 ) ;
V_95 -> V_140 = V_158 ;
}
F_30 ( & V_97 -> V_153 ) ;
F_31 ( & V_95 -> V_154 , & V_95 -> V_98 -> V_151 ) ;
F_150 ( & V_97 -> V_155 ) ;
F_32 ( & V_95 -> V_98 -> V_153 ) ;
F_133 ( & V_95 -> V_98 -> V_150 ) ;
}
static bool F_157 ( struct V_94 * V_95 )
{
switch ( V_95 -> V_75 ) {
case V_305 :
if ( ! ( V_95 -> V_37 -> V_36 & V_305 ) ) {
T_1 V_193 = V_95 -> V_147 >>
F_146 ( V_95 -> V_98 -> V_168 . V_169 ) ;
V_95 -> V_288 = F_147 ( V_95 , V_95 -> V_289 ,
V_193 , 0 , V_95 -> V_237 ,
0 ) ;
if ( V_95 -> V_288 )
return true ;
}
break;
case V_306 :
if ( V_95 -> V_37 -> V_36 & V_306 )
break;
F_145 ( V_95 ) ;
break;
default:
break;
}
return false ;
}
static void V_139 ( struct V_119 * V_120 )
{
struct V_94 * V_95 = F_45 ( V_120 , struct V_94 , V_120 ) ;
int V_33 ;
F_136 ( V_95 ) ;
if ( F_151 ( & V_95 -> V_98 -> V_155 ) != 0 )
F_133 ( & V_95 -> V_98 -> V_150 ) ;
if ( V_95 -> V_115 & V_133 ) {
F_72 ( ! V_95 -> V_129 ) ;
V_33 = F_119 (
V_95 , 0 , 1 ) ;
if ( V_33 )
goto V_280;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
if ( V_95 -> V_257 ) {
T_5 V_46 ;
bool V_307 = ( V_95 -> V_115 & V_137 ) ;
bool V_308 = ! ( V_95 -> V_147 ) ;
int V_256 = 0 ;
V_46 = V_95 -> V_257 ( V_95 , true , & V_256 ) ;
if ( ! V_46 && ! V_256 ) {
if ( V_307 && V_308 )
goto V_309;
return;
} else if ( V_46 ) {
V_33 = F_119 ( V_95 ,
V_46 , 0 ) ;
if ( V_33 )
goto V_280;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
}
V_309:
switch ( V_95 -> V_159 ) {
case V_161 :
if ( V_95 -> V_129 )
goto V_279;
F_158 ( V_95 -> V_147 ,
& V_95 -> V_102 -> V_214 . V_310 ) ;
if ( F_157 ( V_95 ) ) {
V_33 = F_119 ( V_95 ,
V_95 -> V_288 , 0 ) ;
if ( V_33 )
goto V_280;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
}
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_302 ( V_95 ) ;
if ( V_33 )
goto V_280;
break;
case V_162 :
F_158 ( V_95 -> V_147 ,
& V_95 -> V_102 -> V_214 . V_311 ) ;
if ( V_95 -> V_115 & V_236 ) {
F_158 ( V_95 -> V_147 ,
& V_95 -> V_102 -> V_214 . V_310 ) ;
V_33 = V_95 -> V_92 -> V_302 ( V_95 ) ;
if ( V_33 )
goto V_280;
break;
}
case V_160 :
V_279:
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_279 ( V_95 ) ;
if ( V_33 )
goto V_280;
break;
default:
break;
}
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return;
V_280:
F_33 ( L_119
L_120 , V_95 , V_95 -> V_159 ) ;
F_139 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
void F_159 ( struct V_217 * V_218 , int V_312 )
{
struct V_217 * V_313 ;
int V_314 ;
F_160 (sgl, sg, nents, count)
F_161 ( F_122 ( V_313 ) ) ;
F_52 ( V_218 ) ;
}
static inline void F_162 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_315 )
return;
F_52 ( V_95 -> V_222 ) ;
V_95 -> V_222 = V_95 -> V_315 ;
V_95 -> V_315 = NULL ;
V_95 -> V_223 = V_95 -> V_316 ;
V_95 -> V_316 = 0 ;
}
static inline void F_163 ( struct V_94 * V_95 )
{
if ( ! ( V_95 -> V_115 & V_239 ) ) {
F_159 ( V_95 -> V_237 , V_95 -> V_238 ) ;
V_95 -> V_237 = NULL ;
V_95 -> V_238 = 0 ;
}
if ( V_95 -> V_115 & V_226 ) {
if ( V_95 -> V_115 & V_137 ) {
F_159 ( V_95 -> V_224 ,
V_95 -> V_225 ) ;
V_95 -> V_224 = NULL ;
V_95 -> V_225 = 0 ;
}
F_162 ( V_95 ) ;
return;
}
F_162 ( V_95 ) ;
F_159 ( V_95 -> V_222 , V_95 -> V_223 ) ;
V_95 -> V_222 = NULL ;
V_95 -> V_223 = 0 ;
F_159 ( V_95 -> V_224 , V_95 -> V_225 ) ;
V_95 -> V_224 = NULL ;
V_95 -> V_225 = 0 ;
}
static int F_68 ( struct V_94 * V_95 )
{
F_10 ( ! V_95 -> V_92 ) ;
return F_120 ( V_95 ) ;
}
void * F_164 ( struct V_94 * V_95 )
{
struct V_217 * V_313 = V_95 -> V_222 ;
struct V_80 * * V_317 ;
int V_185 ;
if ( ! V_95 -> V_223 )
return NULL ;
F_10 ( ! V_313 ) ;
if ( V_95 -> V_223 == 1 )
return F_121 ( F_122 ( V_313 ) ) + V_313 -> V_240 ;
V_317 = F_165 ( V_95 -> V_223 , sizeof( * V_317 ) , V_38 ) ;
if ( ! V_317 )
return NULL ;
F_160 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_317 [ V_185 ] = F_122 ( V_313 ) ;
}
V_95 -> V_318 = F_166 ( V_317 , V_95 -> V_223 , V_319 , V_320 ) ;
F_52 ( V_317 ) ;
if ( ! V_95 -> V_318 )
return NULL ;
return V_95 -> V_318 + V_95 -> V_222 [ 0 ] . V_240 ;
}
void F_167 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_223 ) {
return;
} else if ( V_95 -> V_223 == 1 ) {
F_123 ( F_122 ( V_95 -> V_222 ) ) ;
return;
}
F_168 ( V_95 -> V_318 ) ;
V_95 -> V_318 = NULL ;
}
int
F_169 ( struct V_217 * * V_218 , unsigned int * V_312 , T_1 V_145 ,
bool V_321 , bool V_322 )
{
struct V_217 * V_313 ;
struct V_80 * V_80 ;
T_7 V_323 = ( V_321 ) ? V_324 : 0 ;
unsigned int V_325 , V_326 ;
int V_185 = 0 ;
V_325 = V_326 = F_170 ( V_145 , V_83 ) ;
if ( V_322 )
V_325 ++ ;
V_313 = F_165 ( V_325 , sizeof( struct V_217 ) , V_38 ) ;
if ( ! V_313 )
return - V_28 ;
F_171 ( V_313 , V_325 ) ;
while ( V_145 ) {
T_1 V_327 = F_172 ( T_1 , V_145 , V_83 ) ;
V_80 = F_173 ( V_38 | V_323 ) ;
if ( ! V_80 )
goto V_3;
F_174 ( & V_313 [ V_185 ] , V_80 , V_327 , 0 ) ;
V_145 -= V_327 ;
V_185 ++ ;
}
* V_218 = V_313 ;
* V_312 = V_326 ;
return 0 ;
V_3:
while ( V_185 > 0 ) {
V_185 -- ;
F_161 ( F_122 ( & V_313 [ V_185 ] ) ) ;
}
F_52 ( V_313 ) ;
return - V_28 ;
}
T_5
F_113 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
int V_33 = 0 ;
bool V_323 = ! ( V_95 -> V_115 & V_196 ) ;
if ( V_95 -> V_75 != V_328 &&
! ( V_95 -> V_115 & V_239 ) ) {
V_33 = F_169 ( & V_95 -> V_237 , & V_95 -> V_238 ,
V_95 -> V_192 , true , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
if ( ! ( V_95 -> V_115 & V_226 ) &&
V_95 -> V_147 ) {
if ( ( V_95 -> V_115 & V_236 ) ||
( V_95 -> V_115 & V_137 ) ) {
T_1 V_329 ;
if ( V_95 -> V_115 & V_137 )
V_329 = V_95 -> V_330 *
V_95 -> V_98 -> V_168 . V_169 ;
else
V_329 = V_95 -> V_147 ;
V_33 = F_169 ( & V_95 -> V_224 ,
& V_95 -> V_225 ,
V_329 , V_323 , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
V_33 = F_169 ( & V_95 -> V_222 , & V_95 -> V_223 ,
V_95 -> V_147 , V_323 , false ) ;
if ( V_33 < 0 )
return V_121 ;
} else if ( ( V_95 -> V_115 & V_137 ) &&
V_95 -> V_147 ) {
T_1 V_331 = V_95 -> V_330 *
V_95 -> V_98 -> V_168 . V_169 ;
V_33 = F_169 ( & V_95 -> V_224 ,
& V_95 -> V_225 ,
V_331 , V_323 , false ) ;
if ( V_33 < 0 )
return V_121 ;
}
F_80 ( V_95 ) ;
if ( V_95 -> V_159 != V_162 || V_95 -> V_147 == 0 ) {
F_152 ( V_95 ) ;
return 0 ;
}
F_35 ( & V_95 -> V_103 , V_72 ) ;
V_95 -> V_140 = V_332 ;
if ( V_95 -> V_104 & V_105 ) {
F_33 ( L_40 ,
V_106 , __LINE__ , V_95 -> V_107 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
F_63 ( & V_95 -> V_108 ) ;
return 0 ;
}
V_95 -> V_104 &= ~ V_109 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
if ( V_33 )
goto V_280;
return 0 ;
V_280:
F_33 ( L_121 , V_95 ) ;
F_139 ( V_95 , V_95 -> V_98 , V_33 , true ) ;
return 0 ;
}
static void F_86 ( struct V_94 * V_95 )
{
int V_33 ;
V_33 = V_95 -> V_92 -> V_303 ( V_95 ) ;
if ( V_33 ) {
F_33 ( L_121 ,
V_95 ) ;
F_139 ( V_95 , V_95 -> V_98 , V_33 , true ) ;
}
}
static void F_175 ( struct V_94 * V_95 , bool * V_333 , bool * V_334 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
F_176 ( V_95 , true , V_333 , V_334 , & V_72 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
}
int F_177 ( struct V_94 * V_95 , int V_335 )
{
int V_33 = 0 ;
bool V_333 = false , V_334 = false ;
if ( ! ( V_95 -> V_115 & V_117 ) ) {
if ( V_335 && ( V_95 -> V_115 & V_245 ) )
F_175 ( V_95 , & V_333 , & V_334 ) ;
if ( ! V_333 || V_334 )
V_33 = F_68 ( V_95 ) ;
} else {
if ( V_335 )
F_175 ( V_95 , & V_333 , & V_334 ) ;
if ( V_95 -> V_100 )
F_61 ( V_95 ) ;
if ( V_95 -> V_102 )
F_64 ( V_95 ) ;
if ( ! V_333 || V_334 )
V_33 = F_68 ( V_95 ) ;
}
if ( V_333 ) {
F_33 ( L_122 , V_95 -> V_107 ) ;
F_178 ( & V_95 -> V_201 ) ;
V_95 -> V_92 -> V_336 ( V_95 ) ;
V_33 = 1 ;
}
return V_33 ;
}
int F_117 ( struct V_94 * V_94 , bool V_114 )
{
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
int V_33 = 0 ;
if ( V_114 ) {
if ( ! F_179 ( & V_94 -> V_202 ) )
return - V_51 ;
V_94 -> V_115 |= V_116 ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_337 ) {
V_33 = - V_338 ;
goto V_3;
}
F_31 ( & V_94 -> V_200 , & V_37 -> V_41 ) ;
V_3:
F_36 ( & V_37 -> V_43 , V_72 ) ;
if ( V_33 && V_114 )
F_120 ( V_94 ) ;
return V_33 ;
}
static void F_180 ( struct V_94 * V_95 )
{
F_163 ( V_95 ) ;
if ( V_95 -> V_115 & V_245 )
F_130 ( V_95 -> V_241 ) ;
if ( V_95 -> V_195 != V_95 -> V_209 )
F_52 ( V_95 -> V_195 ) ;
}
static void F_181 ( struct V_84 * V_84 )
{
struct V_94 * V_94 = F_45 ( V_84 , struct V_94 , V_202 ) ;
struct V_2 * V_37 = V_94 -> V_37 ;
unsigned long V_72 ;
bool V_339 ;
if ( V_37 ) {
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_11 ( & V_94 -> V_103 ) ;
V_339 = ( V_94 -> V_104 & V_340 ) &&
( V_94 -> V_104 & V_136 ) ;
F_12 ( & V_94 -> V_103 ) ;
if ( V_94 -> V_341 || V_339 ) {
F_48 ( & V_94 -> V_200 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
F_180 ( V_94 ) ;
F_46 ( & V_94 -> V_201 ) ;
return;
}
F_48 ( & V_94 -> V_200 ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
F_180 ( V_94 ) ;
V_94 -> V_92 -> V_336 ( V_94 ) ;
}
int F_120 ( struct V_94 * V_94 )
{
return F_54 ( & V_94 -> V_202 , F_181 ) ;
}
static const char * F_182 ( enum V_342 V_343 )
{
switch ( V_343 ) {
case V_163 : return L_50 ;
case V_162 : return L_49 ;
case V_161 : return L_48 ;
case V_160 : return L_47 ;
}
return L_123 ;
}
static const char * F_183 ( enum V_344 V_345 )
{
switch ( V_345 ) {
case V_346 : return L_124 ;
case V_216 : return L_125 ;
case V_332 : return L_45 ;
case V_297 : return L_126 ;
case V_141 : return L_127 ;
case V_347 :
return L_128 ;
case V_157 : return L_129 ;
case V_156 : return L_130 ;
case V_158 : return L_131 ;
}
return L_123 ;
}
static void F_184 ( char * * V_348 , const char * V_349 )
{
char * V_91 = * V_348 ;
* V_348 = * V_348 ? F_185 ( V_350 , L_132 , * V_348 , V_349 ) :
F_186 ( V_349 , V_350 ) ;
F_52 ( V_91 ) ;
}
static char * F_187 ( T_1 V_351 )
{
char * V_348 = NULL ;
if ( V_351 & V_136 )
F_184 ( & V_348 , L_133 ) ;
if ( V_351 & V_109 )
F_184 ( & V_348 , L_134 ) ;
if ( V_351 & V_142 )
F_184 ( & V_348 , L_135 ) ;
if ( V_351 & V_285 )
F_184 ( & V_348 , L_136 ) ;
if ( V_351 & V_105 )
F_184 ( & V_348 , L_137 ) ;
if ( V_351 & V_340 )
F_184 ( & V_348 , L_138 ) ;
return V_348 ;
}
static const char * F_188 ( enum V_352 V_353 )
{
switch ( V_353 ) {
case V_251 : return L_139 ;
case V_354 : return L_140 ;
case V_355 : return L_141 ;
case V_356 : return L_142 ;
case V_357 : return L_143 ;
case V_358 : return L_144 ;
case V_359 : return L_145 ;
case V_360 : break;
}
return L_123 ;
}
void F_135 ( const char * V_361 , struct V_94 * V_95 )
{
char * V_362 = F_187 ( V_95 -> V_104 ) ;
const T_4 * V_207 = V_95 -> V_195 ;
struct V_241 * V_353 = V_95 -> V_241 ;
if ( ! ( V_95 -> V_115 & V_245 ) ) {
F_33 ( L_146 ,
V_361 , V_207 [ 0 ] , V_207 [ 1 ] , V_95 -> V_107 ,
F_182 ( V_95 -> V_159 ) ,
V_95 -> V_92 -> V_363 ( V_95 ) ,
F_183 ( V_95 -> V_140 ) , V_95 -> V_147 ,
F_189 ( & V_95 -> V_202 ) , V_362 ) ;
} else {
F_33 ( L_147 ,
V_361 , F_188 ( V_353 -> V_364 ) , V_95 -> V_107 ,
V_353 -> V_252 , V_95 -> V_92 -> V_363 ( V_95 ) ,
F_183 ( V_95 -> V_140 ) ,
F_189 ( & V_95 -> V_202 ) , V_362 ) ;
}
F_52 ( V_362 ) ;
}
void F_190 ( struct V_2 * V_37 )
{
struct V_94 * V_94 , * V_365 ;
unsigned long V_72 ;
int V_46 ;
F_35 ( & V_37 -> V_43 , V_72 ) ;
if ( V_37 -> V_337 ) {
F_36 ( & V_37 -> V_43 , V_72 ) ;
return;
}
V_37 -> V_337 = 1 ;
F_83 ( & V_37 -> V_41 , & V_37 -> V_42 ) ;
F_84 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
V_46 = F_179 ( & V_94 -> V_202 ) ;
if ( V_46 ) {
V_94 -> V_341 = 1 ;
F_11 ( & V_94 -> V_103 ) ;
V_94 -> V_104 |= V_340 ;
F_12 ( & V_94 -> V_103 ) ;
} else
F_48 ( & V_94 -> V_200 ) ;
}
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
void F_191 ( struct V_2 * V_37 )
{
struct V_94 * V_94 , * V_365 ;
unsigned long V_72 ;
bool V_334 ;
F_84 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_33 ( L_148
L_149 , V_94 , V_94 -> V_140 ,
V_94 -> V_92 -> V_363 ( V_94 ) ) ;
F_35 ( & V_94 -> V_103 , V_72 ) ;
V_334 = ( V_94 -> V_104 & V_366 ) ;
F_36 ( & V_94 -> V_103 , V_72 ) ;
if ( ! F_120 ( V_94 ) ) {
if ( V_334 )
F_120 ( V_94 ) ;
}
F_178 ( & V_94 -> V_201 ) ;
F_33 ( L_150
L_151 , V_94 , V_94 -> V_140 ,
V_94 -> V_92 -> V_363 ( V_94 ) ) ;
V_94 -> V_92 -> V_336 ( V_94 ) ;
}
F_35 ( & V_37 -> V_43 , V_72 ) ;
F_72 ( ! F_56 ( & V_37 -> V_41 ) ) ;
F_36 ( & V_37 -> V_43 , V_72 ) ;
}
static void F_192 ( struct V_367 * V_368 )
{
struct V_102 * V_111 = F_45 ( V_368 , struct V_102 , V_113 ) ;
F_46 ( & V_111 -> V_369 ) ;
}
void F_193 ( struct V_102 * V_111 )
{
F_194 ( & V_111 -> V_113 , F_192 ) ;
F_178 ( & V_111 -> V_369 ) ;
F_178 ( & V_111 -> V_370 ) ;
}
static bool
F_176 ( struct V_94 * V_95 , bool V_339 ,
bool * V_333 , bool * V_334 , unsigned long * V_72 )
__releases( &cmd->t_state_lock
bool F_195 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_33 , V_333 = false , V_334 = false ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
V_33 = F_176 ( V_95 , false , & V_333 , & V_334 , & V_72 ) ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
return V_33 ;
}
static int F_156 ( struct V_94 * V_95 , T_5 V_371 )
{
const struct V_372 * V_373 ;
T_4 * V_374 = V_95 -> V_130 ;
int V_375 = ( V_376 int ) V_371 ;
T_4 V_377 , V_378 ;
bool V_379 = F_196 ( V_95 -> V_98 ) ;
if ( V_375 < F_197 ( V_380 ) && V_380 [ V_375 ] . V_381 )
V_373 = & V_380 [ V_375 ] ;
else
V_373 = & V_380 [ ( V_376 int )
V_121 ] ;
if ( V_371 == V_265 ) {
F_198 ( V_95 , & V_377 , & V_378 ) ;
F_199 ( V_377 == 0 ) ;
} else if ( V_373 -> V_377 == 0 ) {
F_199 ( V_95 -> V_382 == 0 ) ;
V_377 = V_95 -> V_382 ;
V_378 = V_95 -> V_383 ;
} else {
V_377 = V_373 -> V_377 ;
V_378 = V_373 -> V_378 ;
}
F_200 ( V_379 , V_374 , V_373 -> V_381 , V_377 , V_378 ) ;
if ( V_373 -> V_384 )
return F_201 ( V_374 ,
V_95 -> V_123 ,
V_95 -> V_385 ) ;
return 0 ;
}
int
F_119 ( struct V_94 * V_95 ,
T_5 V_371 , int V_386 )
{
unsigned long V_72 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_122 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
return 0 ;
}
V_95 -> V_115 |= V_122 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( ! V_386 ) {
int V_46 ;
V_95 -> V_115 |= V_301 ;
V_95 -> V_129 = V_135 ;
V_95 -> V_123 = V_124 ;
V_46 = F_156 ( V_95 , V_371 ) ;
if ( V_46 )
return V_46 ;
}
F_138 ( V_95 ) ;
return V_95 -> V_92 -> V_279 ( V_95 ) ;
}
static int F_153 ( struct V_94 * V_95 , int V_387 )
__releases( &cmd->t_state_lock
int F_134 ( struct V_94 * V_95 , int V_387 )
{
int V_33 ;
F_30 ( & V_95 -> V_103 ) ;
V_33 = F_153 ( V_95 , V_387 ) ;
F_32 ( & V_95 -> V_103 ) ;
return V_33 ;
}
void F_202 ( struct V_94 * V_95 )
{
unsigned long V_72 ;
int V_33 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & ( V_122 ) ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
return;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_159 == V_162 ) {
if ( V_95 -> V_92 -> V_388 ( V_95 ) != 0 ) {
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_115 & V_389 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_390;
}
V_95 -> V_115 |= V_389 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
return;
}
}
V_390:
V_95 -> V_129 = V_391 ;
F_64 ( V_95 ) ;
F_33 ( L_152 ,
V_95 -> V_195 [ 0 ] , V_95 -> V_107 ) ;
F_138 ( V_95 ) ;
V_33 = V_95 -> V_92 -> V_279 ( V_95 ) ;
if ( V_33 )
F_139 ( V_95 , V_95 -> V_98 , V_33 , false ) ;
}
static void F_203 ( struct V_119 * V_120 )
{
struct V_94 * V_95 = F_45 ( V_120 , struct V_94 , V_120 ) ;
struct V_96 * V_97 = V_95 -> V_98 ;
struct V_241 * V_392 = V_95 -> V_241 ;
unsigned long V_72 ;
int V_33 ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
V_392 -> V_242 = V_393 ;
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_281;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
switch ( V_392 -> V_364 ) {
case V_251 :
F_204 ( V_97 , V_392 , V_95 -> V_37 ) ;
break;
case V_354 :
case V_355 :
case V_356 :
V_392 -> V_242 = V_394 ;
break;
case V_357 :
V_33 = F_205 ( V_97 , V_392 , NULL , NULL ) ;
V_392 -> V_242 = ( ! V_33 ) ? V_395 :
V_393 ;
if ( V_392 -> V_242 == V_395 ) {
F_137 ( V_95 -> V_37 -> V_54 ,
V_95 -> V_246 , 0x29 ,
V_396 ) ;
}
break;
case V_358 :
V_392 -> V_242 = V_393 ;
break;
case V_359 :
V_392 -> V_242 = V_393 ;
break;
default:
F_4 ( L_153 ,
V_392 -> V_364 ) ;
V_392 -> V_242 = V_393 ;
break;
}
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
F_36 ( & V_95 -> V_103 , V_72 ) ;
goto V_281;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
V_95 -> V_92 -> V_244 ( V_95 ) ;
V_281:
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
}
int F_132 (
struct V_94 * V_95 )
{
unsigned long V_72 ;
bool V_333 = false ;
F_35 ( & V_95 -> V_103 , V_72 ) ;
if ( V_95 -> V_104 & V_136 ) {
V_333 = true ;
} else {
V_95 -> V_140 = V_347 ;
V_95 -> V_104 |= V_109 ;
}
F_36 ( & V_95 -> V_103 , V_72 ) ;
if ( V_333 ) {
F_100 ( L_154
L_155 , V_95 -> V_241 -> V_364 ,
V_95 -> V_241 -> V_252 , V_95 -> V_107 ) ;
F_64 ( V_95 ) ;
F_62 ( V_95 ) ;
return 0 ;
}
F_76 ( & V_95 -> V_120 , F_203 ) ;
F_78 ( V_95 -> V_98 -> V_397 , & V_95 -> V_120 ) ;
return 0 ;
}
bool
F_206 ( struct V_96 * V_97 )
{
bool V_398 = false ;
if ( V_97 -> V_127 -> V_399 )
V_398 = V_97 -> V_127 -> V_399 ( V_97 ) ;
else if ( V_97 -> V_168 . V_400 > 0 )
V_398 = true ;
return V_398 ;
}
bool
F_207 ( struct V_96 * V_97 )
{
return F_206 ( V_97 ) && V_97 -> V_168 . V_401 > 0 ;
}
