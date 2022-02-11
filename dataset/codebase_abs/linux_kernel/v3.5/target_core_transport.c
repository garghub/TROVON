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
static void F_13 ( struct V_30 * V_31 )
{
F_14 ( & V_31 -> V_32 , 0 ) ;
F_15 ( & V_31 -> V_33 ) ;
F_16 ( & V_31 -> V_34 ) ;
F_17 ( & V_31 -> V_35 ) ;
}
void F_18 ( void )
{
int V_36 ;
if ( V_37 )
return;
V_36 = F_19 ( L_18 ) ;
if ( V_36 != 0 )
F_4 ( L_19 ) ;
V_36 = F_19 ( L_20 ) ;
if ( V_36 != 0 )
F_4 ( L_21 ) ;
V_36 = F_19 ( L_22 ) ;
if ( V_36 != 0 )
F_4 ( L_23 ) ;
V_36 = F_19 ( L_24 ) ;
if ( V_36 != 0 )
F_4 ( L_25 ) ;
V_37 = 1 ;
return;
}
struct V_2 * F_20 ( void )
{
struct V_2 * V_38 ;
V_38 = F_21 ( V_1 , V_39 ) ;
if ( ! V_38 ) {
F_4 ( L_26
L_27 ) ;
return F_22 ( - V_25 ) ;
}
F_15 ( & V_38 -> V_40 ) ;
F_15 ( & V_38 -> V_41 ) ;
F_15 ( & V_38 -> V_42 ) ;
F_15 ( & V_38 -> V_43 ) ;
F_17 ( & V_38 -> V_44 ) ;
F_23 ( & V_38 -> V_45 ) ;
return V_38 ;
}
void F_24 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_2 * V_38 ,
void * V_50 )
{
unsigned char V_51 [ V_52 ] ;
V_38 -> V_47 = V_47 ;
V_38 -> V_50 = V_50 ;
if ( V_49 ) {
if ( V_47 -> V_53 -> V_54 != NULL ) {
memset ( & V_51 [ 0 ] , 0 , V_52 ) ;
V_47 -> V_53 -> V_54 ( V_38 ,
& V_51 [ 0 ] , V_52 ) ;
V_38 -> V_55 = F_25 ( & V_51 [ 0 ] ) ;
}
F_26 ( & V_49 -> V_56 ) ;
F_27 ( & V_49 -> V_57 ) ;
V_49 -> V_58 = V_38 ;
F_28 ( & V_38 -> V_41 ,
& V_49 -> V_59 ) ;
F_29 ( & V_49 -> V_57 ) ;
}
F_28 ( & V_38 -> V_40 , & V_47 -> V_60 ) ;
F_30 ( L_28 ,
V_47 -> V_53 -> V_61 () , V_38 -> V_50 ) ;
}
void F_31 (
struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_2 * V_38 ,
void * V_50 )
{
unsigned long V_62 ;
F_32 ( & V_47 -> V_63 , V_62 ) ;
F_24 ( V_47 , V_49 , V_38 , V_50 ) ;
F_33 ( & V_47 -> V_63 , V_62 ) ;
}
void F_34 ( struct V_64 * V_64 )
{
struct V_2 * V_38 = F_35 ( V_64 ,
struct V_2 , V_45 ) ;
struct V_46 * V_47 = V_38 -> V_47 ;
V_47 -> V_53 -> V_65 ( V_38 ) ;
}
void F_36 ( struct V_2 * V_38 )
{
F_26 ( & V_38 -> V_45 ) ;
}
void F_37 ( struct V_2 * V_38 )
{
struct V_46 * V_66 = V_38 -> V_47 ;
if ( V_66 -> V_53 -> V_67 != NULL ) {
V_66 -> V_53 -> V_67 ( V_38 ) ;
return;
}
F_38 ( & V_38 -> V_45 , F_34 ) ;
}
static void F_39 ( struct V_64 * V_64 )
{
struct V_48 * V_68 = F_35 ( V_64 ,
struct V_48 , V_56 ) ;
F_40 ( & V_68 -> V_69 ) ;
}
void F_41 ( struct V_48 * V_68 )
{
F_38 ( & V_68 -> V_56 , F_39 ) ;
}
void F_42 ( struct V_2 * V_38 )
{
struct V_48 * V_49 ;
unsigned long V_62 ;
V_49 = V_38 -> V_48 ;
if ( V_49 ) {
F_32 ( & V_49 -> V_57 , V_62 ) ;
if ( V_49 -> V_70 == 0 )
F_43 ( & V_38 -> V_41 ) ;
if ( F_44 ( & V_49 -> V_59 ) )
V_49 -> V_58 = NULL ;
else {
V_49 -> V_58 = F_35 (
V_49 -> V_59 . V_71 ,
struct V_2 , V_41 ) ;
}
F_33 ( & V_49 -> V_57 , V_62 ) ;
}
}
void F_45 ( struct V_2 * V_38 )
{
F_46 ( V_1 , V_38 ) ;
}
void F_47 ( struct V_2 * V_38 )
{
struct V_46 * V_47 = V_38 -> V_47 ;
struct V_72 * V_73 ;
struct V_48 * V_49 ;
unsigned long V_62 ;
bool V_74 = true ;
if ( ! V_47 ) {
F_45 ( V_38 ) ;
return;
}
V_73 = V_47 -> V_53 ;
F_32 ( & V_47 -> V_63 , V_62 ) ;
F_43 ( & V_38 -> V_40 ) ;
V_38 -> V_47 = NULL ;
V_38 -> V_50 = NULL ;
F_33 ( & V_47 -> V_63 , V_62 ) ;
V_49 = V_38 -> V_48 ;
F_32 ( & V_47 -> V_75 , V_62 ) ;
if ( V_49 && V_49 -> V_76 ) {
if ( ! V_73 -> V_77 ( V_47 ) ) {
F_43 ( & V_49 -> V_78 ) ;
V_47 -> V_79 -- ;
F_33 ( & V_47 -> V_75 , V_62 ) ;
F_48 ( V_49 ) ;
F_49 ( V_49 , V_47 ) ;
V_73 -> V_80 ( V_47 , V_49 ) ;
V_74 = false ;
F_32 ( & V_47 -> V_75 , V_62 ) ;
}
}
F_33 ( & V_47 -> V_75 , V_62 ) ;
F_30 ( L_29 ,
V_47 -> V_53 -> V_61 () ) ;
if ( V_49 && V_74 == true )
F_41 ( V_49 ) ;
F_45 ( V_38 ) ;
}
static void F_50 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
unsigned long V_62 ;
if ( ! V_84 )
return;
if ( V_82 -> V_86 & V_87 )
return;
F_32 ( & V_84 -> V_88 , V_62 ) ;
if ( V_82 -> V_89 ) {
F_43 ( & V_82 -> V_90 ) ;
V_82 -> V_89 = false ;
}
F_33 ( & V_84 -> V_88 , V_62 ) ;
}
static int F_51 (
struct V_81 * V_82 ,
int V_91 ,
T_3 V_92 )
{
unsigned long V_62 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_86 & V_94 ) {
F_30 ( L_30 ,
V_95 , __LINE__ , V_82 -> V_73 -> V_96 ( V_82 ) ) ;
V_82 -> V_86 &= ~ V_97 ;
if ( V_91 == 2 )
F_50 ( V_82 ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_40 ( & V_82 -> V_98 ) ;
return 1 ;
}
if ( V_82 -> V_86 & V_99 ) {
F_30 ( L_31 ,
V_95 , __LINE__ ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
if ( V_91 == 2 )
F_50 ( V_82 ) ;
if ( V_91 == 2 )
V_82 -> V_100 = NULL ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_40 ( & V_82 -> V_101 ) ;
return 1 ;
}
if ( V_91 ) {
V_82 -> V_86 &= ~ V_97 ;
if ( V_91 == 2 ) {
F_50 ( V_82 ) ;
V_82 -> V_100 = NULL ;
if ( V_82 -> V_73 -> V_102 != NULL ) {
F_33 (
& V_82 -> V_93 , V_62 ) ;
return V_82 -> V_73 -> V_102 ( V_82 ) ;
}
}
F_33 ( & V_82 -> V_93 , V_62 ) ;
return 0 ;
} else if ( V_92 )
V_82 -> V_92 = V_92 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
return 0 ;
}
static int F_52 ( struct V_81 * V_82 )
{
return F_51 ( V_82 , 2 , 0 ) ;
}
static void F_53 ( struct V_81 * V_82 )
{
struct V_100 * V_103 = V_82 -> V_100 ;
unsigned long V_62 ;
if ( ! V_103 )
return;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_86 & V_104 ) {
V_82 -> V_86 &= ~ V_104 ;
F_50 ( V_82 ) ;
}
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_32 ( & V_103 -> V_105 , V_62 ) ;
if ( ! F_44 ( & V_82 -> V_106 ) )
F_54 ( & V_82 -> V_106 ) ;
F_33 ( & V_103 -> V_105 , V_62 ) ;
}
void F_55 ( struct V_81 * V_82 , int remove )
{
if ( ! ( V_82 -> V_107 & V_108 ) )
F_53 ( V_82 ) ;
if ( F_52 ( V_82 ) )
return;
if ( remove ) {
F_56 ( V_82 ) ;
F_57 ( V_82 ) ;
}
}
static void F_58 ( struct V_81 * V_82 , int V_92 ,
bool V_109 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_30 * V_31 = & V_84 -> V_110 ;
unsigned long V_62 ;
if ( V_92 ) {
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_92 = V_92 ;
V_82 -> V_86 |= V_97 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
}
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( ! F_44 ( & V_82 -> V_111 ) )
F_43 ( & V_82 -> V_111 ) ;
else
F_59 ( & V_31 -> V_32 ) ;
if ( V_109 )
F_60 ( & V_82 -> V_111 , & V_31 -> V_33 ) ;
else
F_28 ( & V_82 -> V_111 , & V_31 -> V_33 ) ;
V_82 -> V_86 |= V_112 ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
F_61 ( & V_31 -> V_34 ) ;
}
static struct V_81 *
F_62 ( struct V_30 * V_31 )
{
struct V_81 * V_82 ;
unsigned long V_62 ;
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( F_44 ( & V_31 -> V_33 ) ) {
F_33 ( & V_31 -> V_35 , V_62 ) ;
return NULL ;
}
V_82 = F_63 ( & V_31 -> V_33 , struct V_81 , V_111 ) ;
V_82 -> V_86 &= ~ V_112 ;
F_54 ( & V_82 -> V_111 ) ;
F_64 ( & V_31 -> V_32 ) ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
return V_82 ;
}
static void F_56 ( struct V_81 * V_82 )
{
struct V_30 * V_31 = & V_82 -> V_85 -> V_110 ;
unsigned long V_62 ;
F_32 ( & V_31 -> V_35 , V_62 ) ;
if ( ! ( V_82 -> V_86 & V_112 ) ) {
F_33 ( & V_31 -> V_35 , V_62 ) ;
return;
}
V_82 -> V_86 &= ~ V_112 ;
F_64 ( & V_31 -> V_32 ) ;
F_54 ( & V_82 -> V_111 ) ;
F_33 ( & V_31 -> V_35 , V_62 ) ;
}
static void F_65 ( struct V_113 * V_114 )
{
struct V_81 * V_82 = F_35 ( V_114 , struct V_81 , V_114 ) ;
F_66 ( V_82 ) ;
}
void F_67 ( struct V_81 * V_82 , T_3 V_115 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
int V_116 = V_115 == V_117 ;
unsigned long V_62 ;
V_82 -> V_115 = V_115 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_86 &= ~ V_87 ;
if ( V_84 && V_84 -> V_118 -> V_119 ) {
if ( V_84 -> V_118 -> V_119 ( V_82 ,
V_82 -> V_120 ) != 0 ) {
V_82 -> V_107 |= V_121 ;
V_116 = 1 ;
}
}
if ( V_82 -> V_86 & V_122 ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_40 ( & V_82 -> V_123 ) ;
return;
}
if ( ! V_116 )
V_82 -> V_86 |= V_124 ;
if ( V_82 -> V_86 & V_125 &&
V_82 -> V_86 & V_99 ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_40 ( & V_82 -> V_101 ) ;
return;
} else if ( V_82 -> V_86 & V_124 ) {
V_82 -> V_126 = V_127 ;
F_68 ( & V_82 -> V_114 , F_65 ) ;
} else {
F_68 ( & V_82 -> V_114 , V_128 ) ;
}
V_82 -> V_92 = V_129 ;
V_82 -> V_86 |= ( V_130 | V_97 ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_69 ( V_22 , & V_82 -> V_114 ) ;
}
static void F_70 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
unsigned long V_62 ;
F_32 ( & V_84 -> V_88 , V_62 ) ;
if ( ! V_82 -> V_89 ) {
F_28 ( & V_82 -> V_90 , & V_84 -> V_90 ) ;
V_82 -> V_89 = true ;
}
F_33 ( & V_84 -> V_88 , V_62 ) ;
}
static void F_71 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
bool V_131 = false ;
if ( ! F_44 ( & V_82 -> V_132 ) )
return;
if ( V_84 -> V_133 == V_134 &&
V_82 -> V_135 == V_136 )
V_131 = true ;
if ( V_131 )
F_60 ( & V_82 -> V_132 , & V_84 -> V_132 ) ;
else
F_28 ( & V_82 -> V_132 , & V_84 -> V_132 ) ;
F_59 ( & V_84 -> V_137 ) ;
if ( V_82 -> V_89 )
return;
if ( V_131 )
F_60 ( & V_82 -> V_90 , & V_84 -> V_90 ) ;
else
F_28 ( & V_82 -> V_90 , & V_84 -> V_90 ) ;
V_82 -> V_89 = true ;
}
static void F_72 ( struct V_81 * V_82 )
{
unsigned long V_62 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_32 ( & V_84 -> V_88 , V_62 ) ;
F_71 ( V_82 ) ;
F_33 ( & V_84 -> V_88 , V_62 ) ;
}
void F_73 ( struct V_81 * V_82 )
{
F_54 ( & V_82 -> V_132 ) ;
F_64 ( & V_82 -> V_85 -> V_137 ) ;
}
static void F_74 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
unsigned long V_62 ;
if ( F_75 ( F_44 ( & V_82 -> V_132 ) ) )
return;
F_32 ( & V_84 -> V_88 , V_62 ) ;
F_73 ( V_82 ) ;
F_33 ( & V_84 -> V_88 , V_62 ) ;
}
static void F_76 ( struct V_113 * V_114 )
{
struct V_83 * V_84 = F_35 ( V_114 , struct V_83 ,
V_138 ) ;
F_77 ( V_139 ) ;
struct V_81 * V_82 , * V_140 ;
F_27 ( & V_84 -> V_141 ) ;
F_78 ( & V_84 -> V_139 , & V_139 ) ;
F_29 ( & V_84 -> V_141 ) ;
F_79 (cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
F_43 ( & V_82 -> V_142 ) ;
F_64 ( & V_84 -> V_143 ) ;
F_80 () ;
F_30 ( L_32
L_33 , V_82 -> V_73 -> V_61 () , V_82 ,
( V_82 -> V_92 == V_144 ) ? L_34 :
( V_82 -> V_92 == V_145 ) ? L_35
: L_36 ) ;
F_58 ( V_82 , V_82 -> V_92 , true ) ;
}
}
unsigned char * F_81 ( struct V_81 * V_82 )
{
switch ( V_82 -> V_146 ) {
case V_147 :
return L_37 ;
case V_148 :
return L_38 ;
case V_149 :
return L_39 ;
case V_150 :
return L_40 ;
default:
break;
}
return L_36 ;
}
void F_82 (
struct V_83 * V_84 ,
char * V_151 ,
int * V_152 )
{
* V_152 += sprintf ( V_151 + * V_152 , L_41 ) ;
switch ( V_84 -> V_153 ) {
case V_154 :
* V_152 += sprintf ( V_151 + * V_152 , L_42 ) ;
break;
case V_155 :
* V_152 += sprintf ( V_151 + * V_152 , L_43 ) ;
break;
case V_156 :
* V_152 += sprintf ( V_151 + * V_152 , L_44 ) ;
break;
case V_157 :
case V_158 :
* V_152 += sprintf ( V_151 + * V_152 , L_45 ) ;
break;
default:
* V_152 += sprintf ( V_151 + * V_152 , L_46 , V_84 -> V_153 ) ;
break;
}
* V_152 += sprintf ( V_151 + * V_152 , L_47 ,
F_83 ( & V_84 -> V_137 ) , V_84 -> V_159 ) ;
* V_152 += sprintf ( V_151 + * V_152 , L_48 ,
V_84 -> V_160 -> V_161 . V_162 ,
V_84 -> V_160 -> V_161 . V_163 ) ;
* V_152 += sprintf ( V_151 + * V_152 , L_49 ) ;
}
void F_84 (
struct V_164 * V_165 ,
unsigned char * V_166 ,
int V_167 )
{
unsigned char V_51 [ V_168 ] ;
int V_169 ;
memset ( V_51 , 0 , V_168 ) ;
V_169 = sprintf ( V_51 , L_50 ) ;
switch ( V_165 -> V_170 ) {
case 0x00 :
sprintf ( V_51 + V_169 , L_51 ) ;
break;
case 0x10 :
sprintf ( V_51 + V_169 , L_52 ) ;
break;
case 0x20 :
sprintf ( V_51 + V_169 , L_53 ) ;
break;
case 0x30 :
sprintf ( V_51 + V_169 , L_54 ) ;
break;
case 0x40 :
sprintf ( V_51 + V_169 , L_55
L_56 ) ;
break;
case 0x50 :
sprintf ( V_51 + V_169 , L_57 ) ;
break;
case 0x60 :
sprintf ( V_51 + V_169 , L_58 ) ;
break;
case 0x70 :
sprintf ( V_51 + V_169 , L_59
L_56 ) ;
break;
case 0x80 :
sprintf ( V_51 + V_169 , L_60 ) ;
break;
default:
sprintf ( V_51 + V_169 , L_61 ,
V_165 -> V_170 ) ;
break;
}
if ( V_166 )
strncpy ( V_166 , V_51 , V_167 ) ;
else
F_30 ( L_62 , V_51 ) ;
}
void
F_85 ( struct V_164 * V_165 , unsigned char * V_171 )
{
if ( V_171 [ 1 ] & 0x80 ) {
V_165 -> V_170 = ( V_171 [ 0 ] & 0xf0 ) ;
V_165 -> V_172 = 1 ;
F_84 ( V_165 , NULL , 0 ) ;
}
}
int F_86 (
struct V_164 * V_165 ,
unsigned char * V_166 ,
int V_167 )
{
unsigned char V_51 [ V_168 ] ;
int V_36 = 0 ;
int V_169 ;
memset ( V_51 , 0 , V_168 ) ;
V_169 = sprintf ( V_51 , L_63 ) ;
switch ( V_165 -> V_173 ) {
case 0x00 :
sprintf ( V_51 + V_169 , L_64 ) ;
break;
case 0x10 :
sprintf ( V_51 + V_169 , L_65 ) ;
break;
case 0x20 :
sprintf ( V_51 + V_169 , L_66 ) ;
break;
default:
sprintf ( V_51 + V_169 , L_61 , V_165 -> V_173 ) ;
V_36 = - V_174 ;
break;
}
if ( V_166 )
strncpy ( V_166 , V_51 , V_167 ) ;
else
F_30 ( L_62 , V_51 ) ;
return V_36 ;
}
int F_87 ( struct V_164 * V_165 , unsigned char * V_171 )
{
V_165 -> V_173 = ( V_171 [ 1 ] & 0x30 ) ;
return F_86 ( V_165 , NULL , 0 ) ;
}
int F_88 (
struct V_164 * V_165 ,
unsigned char * V_166 ,
int V_167 )
{
unsigned char V_51 [ V_168 ] ;
int V_36 = 0 ;
int V_169 ;
memset ( V_51 , 0 , V_168 ) ;
V_169 = sprintf ( V_51 , L_67 ) ;
switch ( V_165 -> V_175 ) {
case 0x00 :
sprintf ( V_51 + V_169 , L_68 ) ;
break;
case 0x01 :
sprintf ( V_51 + V_169 , L_69 ) ;
break;
case 0x02 :
sprintf ( V_51 + V_169 , L_70 ) ;
break;
case 0x03 :
sprintf ( V_51 + V_169 , L_71 ) ;
break;
case 0x04 :
sprintf ( V_51 + V_169 , L_72 ) ;
break;
case 0x08 :
sprintf ( V_51 + V_169 , L_73 ) ;
break;
default:
sprintf ( V_51 + V_169 , L_74 ,
V_165 -> V_175 ) ;
V_36 = - V_174 ;
break;
}
if ( V_166 ) {
if ( V_167 < strlen ( V_51 ) + 1 )
return - V_174 ;
strncpy ( V_166 , V_51 , V_167 ) ;
} else {
F_30 ( L_62 , V_51 ) ;
}
return V_36 ;
}
int F_89 ( struct V_164 * V_165 , unsigned char * V_171 )
{
V_165 -> V_175 = ( V_171 [ 1 ] & 0x0f ) ;
return F_88 ( V_165 , NULL , 0 ) ;
}
int F_90 (
struct V_164 * V_165 ,
unsigned char * V_166 ,
int V_167 )
{
unsigned char V_51 [ V_168 ] ;
int V_36 = 0 ;
memset ( V_51 , 0 , V_168 ) ;
switch ( V_165 -> V_176 ) {
case 0x01 :
sprintf ( V_51 , L_75 ,
& V_165 -> V_177 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_51 , L_76 ,
& V_165 -> V_177 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_51 , L_77 ,
& V_165 -> V_177 [ 0 ] ) ;
break;
default:
sprintf ( V_51 , L_78
L_79 , V_165 -> V_176 ) ;
V_36 = - V_174 ;
break;
}
if ( V_166 )
strncpy ( V_166 , V_51 , V_167 ) ;
else
F_30 ( L_62 , V_51 ) ;
return V_36 ;
}
int
F_91 ( struct V_164 * V_165 , unsigned char * V_171 )
{
static const char V_178 [] = L_80 ;
int V_179 = 0 , V_180 = 4 ;
V_165 -> V_176 = ( V_171 [ 0 ] & 0x0f ) ;
switch ( V_165 -> V_176 ) {
case 0x01 :
V_165 -> V_177 [ V_179 ++ ] =
V_178 [ V_165 -> V_175 ] ;
while ( V_180 < ( 4 + V_171 [ 3 ] ) ) {
V_165 -> V_177 [ V_179 ++ ] =
V_178 [ ( V_171 [ V_180 ] & 0xf0 ) >> 4 ] ;
V_165 -> V_177 [ V_179 ++ ] =
V_178 [ V_171 [ V_180 ] & 0x0f ] ;
V_180 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_180 < ( 4 + V_171 [ 3 ] ) )
V_165 -> V_177 [ V_179 ++ ] = V_171 [ V_180 ++ ] ;
break;
default:
break;
}
return F_90 ( V_165 , NULL , 0 ) ;
}
static void F_92 ( struct V_83 * V_84 )
{
if ( V_84 -> V_118 -> V_181 == V_182 ) {
V_84 -> V_133 = V_183 ;
return;
}
V_84 -> V_133 = V_134 ;
F_30 ( L_81
L_82 , V_84 -> V_118 -> V_184 ,
V_84 -> V_118 -> V_185 ( V_84 ) ) ;
}
static void F_93 ( struct V_83 * V_84 )
{
struct V_186 * V_187 = & V_84 -> V_160 -> V_186 ;
char V_51 [ 17 ] ;
int V_180 , V_188 ;
for ( V_180 = 0 ; V_180 < 8 ; V_180 ++ )
if ( V_187 -> V_189 [ V_180 ] >= 0x20 )
V_51 [ V_180 ] = V_187 -> V_189 [ V_180 ] ;
else
V_51 [ V_180 ] = ' ' ;
V_51 [ V_180 ] = '\0' ;
F_30 ( L_83 , V_51 ) ;
for ( V_180 = 0 ; V_180 < 16 ; V_180 ++ )
if ( V_187 -> V_190 [ V_180 ] >= 0x20 )
V_51 [ V_180 ] = V_187 -> V_190 [ V_180 ] ;
else
V_51 [ V_180 ] = ' ' ;
V_51 [ V_180 ] = '\0' ;
F_30 ( L_84 , V_51 ) ;
for ( V_180 = 0 ; V_180 < 4 ; V_180 ++ )
if ( V_187 -> V_191 [ V_180 ] >= 0x20 )
V_51 [ V_180 ] = V_187 -> V_191 [ V_180 ] ;
else
V_51 [ V_180 ] = ' ' ;
V_51 [ V_180 ] = '\0' ;
F_30 ( L_85 , V_51 ) ;
V_188 = V_84 -> V_118 -> V_192 ( V_84 ) ;
F_30 ( L_86 , F_94 ( V_188 ) ) ;
F_30 ( L_87 ,
V_84 -> V_118 -> V_185 ( V_84 ) ) ;
}
struct V_83 * F_95 (
struct V_193 * V_194 ,
struct V_195 * V_118 ,
struct V_196 * V_85 ,
T_1 V_197 ,
void * V_198 ,
struct V_199 * V_200 ,
const char * V_201 ,
const char * V_202 )
{
int V_203 ;
struct V_83 * V_84 ;
V_84 = F_96 ( sizeof( struct V_83 ) , V_39 ) ;
if ( ! V_84 ) {
F_4 ( L_88 ) ;
return NULL ;
}
F_13 ( & V_84 -> V_110 ) ;
V_84 -> V_204 = V_197 ;
V_84 -> V_153 |= V_155 ;
V_84 -> V_205 = V_198 ;
V_84 -> V_193 = V_194 ;
V_84 -> V_160 = V_85 ;
V_84 -> V_118 = V_118 ;
F_15 ( & V_84 -> V_206 ) ;
F_15 ( & V_84 -> V_207 ) ;
F_15 ( & V_84 -> V_208 ) ;
F_15 ( & V_84 -> V_132 ) ;
F_15 ( & V_84 -> V_209 ) ;
F_15 ( & V_84 -> V_90 ) ;
F_15 ( & V_84 -> V_139 ) ;
F_17 ( & V_84 -> V_88 ) ;
F_17 ( & V_84 -> V_210 ) ;
F_17 ( & V_84 -> V_211 ) ;
F_17 ( & V_84 -> V_212 ) ;
F_17 ( & V_84 -> V_213 ) ;
F_17 ( & V_84 -> V_214 ) ;
F_17 ( & V_84 -> V_141 ) ;
F_14 ( & V_84 -> V_215 , 0 ) ;
F_97 ( V_84 , V_200 ) ;
V_84 -> V_216 = F_9 ( V_217 ) ;
V_84 -> V_218 = F_98 () ;
F_17 ( & V_84 -> V_219 ) ;
F_11 ( & V_194 -> V_220 ) ;
F_28 ( & V_84 -> V_206 , & V_194 -> V_221 ) ;
V_194 -> V_222 ++ ;
F_12 ( & V_194 -> V_220 ) ;
F_92 ( V_84 ) ;
V_203 = ( V_194 -> V_223 & V_224 ) ;
F_99 ( V_84 , V_203 ) ;
if ( F_100 ( V_84 , V_203 ) < 0 )
goto V_3;
V_84 -> V_225 = F_101 ( V_226 , V_84 ,
L_89 , V_84 -> V_118 -> V_184 ) ;
if ( F_102 ( V_84 -> V_225 ) ) {
F_4 ( L_90 ,
V_84 -> V_118 -> V_184 ) ;
goto V_3;
}
F_68 ( & V_84 -> V_138 , F_76 ) ;
if ( V_84 -> V_118 -> V_181 != V_182 ) {
if ( ! V_201 || ! V_202 ) {
F_4 ( L_91
L_92 ) ;
goto V_3;
}
strncpy ( & V_84 -> V_160 -> V_186 . V_189 [ 0 ] , L_93 , 8 ) ;
strncpy ( & V_84 -> V_160 -> V_186 . V_190 [ 0 ] , V_201 , 16 ) ;
strncpy ( & V_84 -> V_160 -> V_186 . V_191 [ 0 ] , V_202 , 4 ) ;
}
F_93 ( V_84 ) ;
return V_84 ;
V_3:
F_103 ( V_84 -> V_225 ) ;
F_11 ( & V_194 -> V_220 ) ;
F_43 ( & V_84 -> V_206 ) ;
V_194 -> V_222 -- ;
F_12 ( & V_194 -> V_220 ) ;
F_104 ( V_84 ) ;
F_105 ( V_84 ) ;
return NULL ;
}
static inline void F_106 (
unsigned char * V_227 )
{
switch ( V_227 [ 0 ] ) {
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
break;
default:
V_227 [ 1 ] &= 0x1f ;
break;
}
}
void F_107 (
struct V_81 * V_82 ,
struct V_72 * V_237 ,
struct V_2 * V_38 ,
T_1 V_238 ,
int V_146 ,
int V_239 ,
unsigned char * V_240 )
{
F_15 ( & V_82 -> V_106 ) ;
F_15 ( & V_82 -> V_241 ) ;
F_15 ( & V_82 -> V_142 ) ;
F_15 ( & V_82 -> V_111 ) ;
F_15 ( & V_82 -> V_242 ) ;
F_15 ( & V_82 -> V_132 ) ;
F_15 ( & V_82 -> V_90 ) ;
F_108 ( & V_82 -> V_243 ) ;
F_108 ( & V_82 -> V_98 ) ;
F_108 ( & V_82 -> V_101 ) ;
F_108 ( & V_82 -> V_244 ) ;
F_108 ( & V_82 -> V_123 ) ;
F_17 ( & V_82 -> V_93 ) ;
V_82 -> V_86 = V_104 ;
V_82 -> V_73 = V_237 ;
V_82 -> V_38 = V_38 ;
V_82 -> V_238 = V_238 ;
V_82 -> V_146 = V_146 ;
V_82 -> V_135 = V_239 ;
V_82 -> V_240 = V_240 ;
V_82 -> V_89 = false ;
}
static int F_109 ( struct V_81 * V_82 )
{
if ( V_82 -> V_85 -> V_133 != V_134 )
return 0 ;
if ( V_82 -> V_135 == V_245 ) {
F_30 ( L_94
L_95 ) ;
return - V_174 ;
}
V_82 -> V_246 = F_110 ( & V_82 -> V_85 -> V_215 ) ;
F_111 () ;
F_30 ( L_96 ,
V_82 -> V_246 , V_82 -> V_135 ,
V_82 -> V_85 -> V_118 -> V_184 ) ;
return 0 ;
}
int F_112 (
struct V_81 * V_82 ,
unsigned char * V_227 )
{
int V_36 ;
F_106 ( V_227 ) ;
if ( F_113 ( V_227 ) > V_247 ) {
F_4 ( L_97
L_98 ,
F_113 ( V_227 ) , V_247 ) ;
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_249 ;
return - V_174 ;
}
if ( F_113 ( V_227 ) > sizeof( V_82 -> V_250 ) ) {
V_82 -> V_251 = F_96 ( F_113 ( V_227 ) ,
V_39 ) ;
if ( ! V_82 -> V_251 ) {
F_4 ( L_99
L_100 ,
F_113 ( V_227 ) ,
( unsigned long ) sizeof( V_82 -> V_250 ) ) ;
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 =
V_127 ;
return - V_25 ;
}
} else
V_82 -> V_251 = & V_82 -> V_250 [ 0 ] ;
memcpy ( V_82 -> V_251 , V_227 , F_113 ( V_227 ) ) ;
V_36 = F_114 ( V_82 , V_227 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( F_109 ( V_82 ) < 0 ) {
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_249 ;
return - V_174 ;
}
F_11 ( & V_82 -> V_100 -> V_252 ) ;
if ( V_82 -> V_100 -> V_253 )
V_82 -> V_100 -> V_253 -> V_254 . V_255 ++ ;
F_12 ( & V_82 -> V_100 -> V_252 ) ;
return 0 ;
}
int F_115 (
struct V_81 * V_82 )
{
int V_36 ;
if ( ! V_82 -> V_100 ) {
F_116 () ;
F_4 ( L_101 ) ;
return - V_174 ;
}
if ( F_117 () ) {
F_116 () ;
F_4 ( L_102
L_103 ) ;
return - V_174 ;
}
V_82 -> V_92 = V_256 ;
V_82 -> V_86 |= V_97 ;
V_36 = F_118 ( V_82 ) ;
if ( V_36 < 0 )
F_66 ( V_82 ) ;
return 0 ;
}
void F_119 ( struct V_81 * V_81 , struct V_2 * V_38 ,
unsigned char * V_227 , unsigned char * V_257 , T_1 V_258 ,
T_1 V_238 , int V_239 , int V_259 , int V_62 )
{
struct V_46 * V_47 ;
int V_260 ;
V_47 = V_38 -> V_47 ;
F_10 ( ! V_47 ) ;
F_10 ( V_81 -> V_73 || V_81 -> V_38 ) ;
F_10 ( F_117 () ) ;
F_107 ( V_81 , V_47 -> V_53 , V_38 ,
V_238 , V_259 , V_239 , V_257 ) ;
if ( V_62 & V_261 )
V_81 -> V_262 = 1 ;
F_120 ( V_38 , V_81 , ( V_62 & V_263 ) ) ;
if ( V_62 & V_264 )
V_81 -> V_107 |= V_265 ;
if ( F_121 ( V_81 , V_258 ) < 0 ) {
F_122 ( V_81 ,
V_81 -> V_126 , 0 ) ;
F_123 ( V_38 , V_81 ) ;
return;
}
V_260 = F_112 ( V_81 , V_227 ) ;
if ( V_260 != 0 ) {
F_66 ( V_81 ) ;
return;
}
F_124 ( V_81 ) ;
F_115 ( V_81 ) ;
return;
}
static void F_125 ( struct V_113 * V_114 )
{
struct V_81 * V_81 = F_35 ( V_114 , struct V_81 , V_114 ) ;
V_81 -> V_266 -> V_267 = V_268 ;
V_81 -> V_73 -> V_269 ( V_81 ) ;
F_126 ( V_81 , 0 ) ;
}
int F_127 ( struct V_81 * V_81 , struct V_2 * V_38 ,
unsigned char * V_257 , T_1 V_258 ,
void * V_270 , unsigned char V_271 ,
T_4 V_272 , unsigned int V_273 , int V_62 )
{
struct V_46 * V_47 ;
int V_36 ;
V_47 = V_38 -> V_47 ;
F_10 ( ! V_47 ) ;
F_107 ( V_81 , V_47 -> V_53 , V_38 ,
0 , V_147 , V_274 , V_257 ) ;
V_36 = F_128 ( V_81 , V_270 , V_271 , V_272 ) ;
if ( V_36 < 0 )
return - V_25 ;
if ( V_271 == V_275 )
V_81 -> V_266 -> V_276 = V_273 ;
F_120 ( V_38 , V_81 , ( V_62 & V_263 ) ) ;
V_36 = F_129 ( V_81 , V_258 ) ;
if ( V_36 ) {
F_68 ( & V_81 -> V_114 , F_125 ) ;
F_130 ( & V_81 -> V_114 ) ;
return 0 ;
}
F_131 ( V_81 ) ;
return 0 ;
}
int F_132 (
struct V_81 * V_82 )
{
if ( ! V_82 -> V_100 ) {
F_116 () ;
F_4 ( L_101 ) ;
return - V_174 ;
}
F_58 ( V_82 , V_277 , false ) ;
return 0 ;
}
int F_133 (
struct V_81 * V_82 )
{
if ( ! F_117 () && F_134 ( V_278 ) )
return - V_279 ;
if ( F_135 ( V_82 , 1 ) != 0 )
return 0 ;
F_58 ( V_82 , V_280 , false ) ;
return 0 ;
}
int F_131 (
struct V_81 * V_82 )
{
F_58 ( V_82 , V_281 , false ) ;
return 0 ;
}
bool F_136 ( struct V_81 * V_82 , unsigned long * V_62 )
{
bool V_282 = false ;
if ( V_82 -> V_86 & V_87 ) {
V_82 -> V_86 |= V_122 ;
F_33 ( & V_82 -> V_93 , * V_62 ) ;
F_30 ( L_104 , V_82 ) ;
F_137 ( & V_82 -> V_123 ) ;
F_30 ( L_105 , V_82 ) ;
F_32 ( & V_82 -> V_93 , * V_62 ) ;
V_82 -> V_86 &= ~ V_122 ;
V_82 -> V_86 &= ~ V_87 ;
V_282 = true ;
}
return V_282 ;
}
void F_66 ( struct V_81 * V_82 )
{
int V_36 = 0 ;
F_30 ( L_106
L_107 , V_82 , V_82 -> V_73 -> V_96 ( V_82 ) ,
V_82 -> V_251 [ 0 ] ) ;
F_30 ( L_108 ,
V_82 -> V_73 -> V_283 ( V_82 ) ,
V_82 -> V_92 , V_82 -> V_126 ) ;
F_30 ( L_109 ,
( V_82 -> V_86 & V_97 ) != 0 ,
( V_82 -> V_86 & V_99 ) != 0 ,
( V_82 -> V_86 & V_284 ) != 0 ) ;
if ( V_82 -> V_85 -> V_133 == V_134 )
F_138 ( V_82 ) ;
switch ( V_82 -> V_126 ) {
case V_285 :
case V_286 :
case V_249 :
case V_287 :
case V_127 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
break;
case V_293 :
V_82 -> V_115 = V_294 ;
if ( V_82 -> V_38 &&
V_82 -> V_85 -> V_160 -> V_161 . V_295 == 2 )
F_139 ( V_82 -> V_38 -> V_48 ,
V_82 -> V_296 , 0x2C ,
V_297 ) ;
V_36 = V_82 -> V_73 -> V_298 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
goto V_301;
default:
F_4 ( L_110 ,
V_82 -> V_251 [ 0 ] , V_82 -> V_126 ) ;
V_82 -> V_126 = V_286 ;
break;
}
V_36 = F_122 ( V_82 ,
V_82 -> V_126 , 0 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
V_301:
F_53 ( V_82 ) ;
if ( ! F_52 ( V_82 ) )
;
return;
V_300:
V_82 -> V_92 = V_144 ;
F_140 ( V_82 , V_82 -> V_85 ) ;
}
static inline T_1 F_141 ( unsigned char * V_227 )
{
return ( ( V_227 [ 1 ] & 0x1f ) << 16 ) | ( V_227 [ 2 ] << 8 ) | V_227 [ 3 ] ;
}
static inline T_1 F_142 ( unsigned char * V_227 )
{
return ( V_227 [ 2 ] << 24 ) | ( V_227 [ 3 ] << 16 ) | ( V_227 [ 4 ] << 8 ) | V_227 [ 5 ] ;
}
static inline unsigned long long F_143 ( unsigned char * V_227 )
{
unsigned int V_302 , V_303 ;
V_302 = ( V_227 [ 2 ] << 24 ) | ( V_227 [ 3 ] << 16 ) | ( V_227 [ 4 ] << 8 ) | V_227 [ 5 ] ;
V_303 = ( V_227 [ 6 ] << 24 ) | ( V_227 [ 7 ] << 16 ) | ( V_227 [ 8 ] << 8 ) | V_227 [ 9 ] ;
return ( ( unsigned long long ) V_303 ) | ( unsigned long long ) V_302 << 32 ;
}
static inline unsigned long long F_144 ( unsigned char * V_227 )
{
unsigned int V_302 , V_303 ;
V_302 = ( V_227 [ 12 ] << 24 ) | ( V_227 [ 13 ] << 16 ) | ( V_227 [ 14 ] << 8 ) | V_227 [ 15 ] ;
V_303 = ( V_227 [ 16 ] << 24 ) | ( V_227 [ 17 ] << 16 ) | ( V_227 [ 18 ] << 8 ) | V_227 [ 19 ] ;
return ( ( unsigned long long ) V_303 ) | ( unsigned long long ) V_302 << 32 ;
}
static void F_145 ( struct V_81 * V_81 )
{
unsigned long V_62 ;
F_32 ( & V_81 -> V_93 , V_62 ) ;
V_81 -> V_107 |= V_304 ;
F_33 ( & V_81 -> V_93 , V_62 ) ;
}
static inline int F_146 ( struct V_81 * V_82 )
{
if ( V_82 -> V_85 -> V_133 != V_134 )
return 1 ;
if ( V_82 -> V_135 == V_136 ) {
F_30 ( L_111
L_112 ,
V_82 -> V_251 [ 0 ] ,
V_82 -> V_246 ) ;
return 1 ;
} else if ( V_82 -> V_135 == V_305 ) {
F_59 ( & V_82 -> V_85 -> V_306 ) ;
F_111 () ;
F_30 ( L_113
L_114 ,
V_82 -> V_251 [ 0 ] ,
V_82 -> V_246 ) ;
if ( ! F_83 ( & V_82 -> V_85 -> V_307 ) )
return 1 ;
} else {
F_59 ( & V_82 -> V_85 -> V_307 ) ;
F_111 () ;
}
if ( F_83 ( & V_82 -> V_85 -> V_306 ) != 0 ) {
F_11 ( & V_82 -> V_85 -> V_210 ) ;
V_82 -> V_107 |= V_308 ;
F_28 ( & V_82 -> V_241 ,
& V_82 -> V_85 -> V_209 ) ;
F_12 ( & V_82 -> V_85 -> V_210 ) ;
F_30 ( L_115
L_116 ,
V_82 -> V_251 [ 0 ] , V_82 -> V_135 ,
V_82 -> V_246 ) ;
return 0 ;
}
return 1 ;
}
static void F_147 ( struct V_81 * V_82 )
{
int V_309 ;
struct V_83 * V_85 = V_82 -> V_85 ;
if ( ! F_51 ( V_82 , 0 , V_310 ) ) {
V_309 = F_146 ( V_82 ) ;
if ( V_309 ) {
F_148 ( V_85 , V_82 ) ;
return;
}
}
F_148 ( V_85 , NULL ) ;
}
static int F_148 ( struct V_83 * V_84 , struct V_81 * V_311 )
{
int error ;
struct V_81 * V_82 = NULL ;
unsigned long V_62 ;
V_312:
F_27 ( & V_84 -> V_88 ) ;
if ( V_311 != NULL )
F_71 ( V_311 ) ;
if ( F_44 ( & V_84 -> V_132 ) ) {
F_29 ( & V_84 -> V_88 ) ;
return 0 ;
}
V_82 = F_63 ( & V_84 -> V_132 , struct V_81 , V_132 ) ;
F_73 ( V_82 ) ;
F_29 ( & V_84 -> V_88 ) ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_86 |= V_87 ;
V_82 -> V_86 |= V_284 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_313 )
error = V_82 -> V_313 ( V_82 ) ;
else {
error = V_84 -> V_118 -> V_313 ( V_82 , V_82 -> V_120 ,
V_82 -> V_314 , V_82 -> V_146 ) ;
}
if ( error != 0 ) {
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_86 &= ~ V_87 ;
V_82 -> V_86 &= ~ V_284 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_66 ( V_82 ) ;
}
V_311 = NULL ;
goto V_312;
return 0 ;
}
static inline T_1 F_149 (
unsigned char * V_227 ,
struct V_81 * V_82 ,
int * V_36 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
if ( ! V_84 )
goto V_315;
if ( V_84 -> V_118 -> V_192 ( V_84 ) == V_316 )
return ( T_1 ) ( V_227 [ 2 ] << 16 ) + ( V_227 [ 3 ] << 8 ) + V_227 [ 4 ] ;
V_315:
return V_227 [ 4 ] ? : 256 ;
}
static inline T_1 F_150 (
unsigned char * V_227 ,
struct V_81 * V_82 ,
int * V_36 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
if ( ! V_84 )
goto V_315;
if ( V_84 -> V_118 -> V_192 ( V_84 ) == V_316 ) {
* V_36 = - V_174 ;
return 0 ;
}
V_315:
return ( T_1 ) ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
}
static inline T_1 F_151 (
unsigned char * V_227 ,
struct V_81 * V_82 ,
int * V_36 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
if ( ! V_84 )
goto V_315;
if ( V_84 -> V_118 -> V_192 ( V_84 ) == V_316 ) {
* V_36 = - V_174 ;
return 0 ;
}
V_315:
return ( T_1 ) ( V_227 [ 6 ] << 24 ) + ( V_227 [ 7 ] << 16 ) + ( V_227 [ 8 ] << 8 ) + V_227 [ 9 ] ;
}
static inline T_1 F_152 (
unsigned char * V_227 ,
struct V_81 * V_82 ,
int * V_36 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
if ( ! V_84 )
goto V_315;
if ( V_84 -> V_118 -> V_192 ( V_84 ) == V_316 )
return ( T_1 ) ( V_227 [ 12 ] << 16 ) + ( V_227 [ 13 ] << 8 ) + V_227 [ 14 ] ;
V_315:
return ( T_1 ) ( V_227 [ 10 ] << 24 ) + ( V_227 [ 11 ] << 16 ) +
( V_227 [ 12 ] << 8 ) + V_227 [ 13 ] ;
}
static inline T_1 F_153 (
unsigned char * V_227 ,
struct V_81 * V_82 ,
int * V_36 )
{
return ( T_1 ) ( V_227 [ 28 ] << 24 ) + ( V_227 [ 29 ] << 16 ) +
( V_227 [ 30 ] << 8 ) + V_227 [ 31 ] ;
}
static inline T_1 F_154 (
T_1 V_317 ,
unsigned char * V_227 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
if ( V_84 -> V_118 -> V_192 ( V_84 ) == V_316 ) {
if ( V_227 [ 1 ] & 1 ) {
return V_84 -> V_160 -> V_161 . V_162 * V_317 ;
} else
return V_317 ;
}
F_30 ( L_117
L_118 , V_84 -> V_160 -> V_161 . V_162 ,
V_317 , V_84 -> V_160 -> V_161 . V_162 * V_317 ,
V_84 -> V_118 -> V_184 ) ;
return V_84 -> V_160 -> V_161 . V_162 * V_317 ;
}
static void F_155 ( struct V_81 * V_82 )
{
unsigned char * V_51 , * V_318 ;
struct V_319 * V_320 ;
unsigned int V_321 ;
int V_180 ;
int V_322 ;
V_51 = F_156 ( V_82 -> V_238 , V_39 ) ;
if ( ! V_51 ) {
F_4 ( L_119 ) ;
return;
}
F_157 ( V_82 -> V_120 ,
V_82 -> V_314 ,
V_51 ,
V_82 -> V_238 ) ;
V_321 = 0 ;
F_158 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_318 = F_159 ( F_160 ( V_320 ) ) ;
if ( ! V_318 )
goto V_3;
for ( V_180 = 0 ; V_180 < V_320 -> V_323 ; V_180 ++ )
* ( V_318 + V_320 -> V_321 + V_180 ) ^= * ( V_51 + V_321 + V_180 ) ;
V_321 += V_320 -> V_323 ;
F_161 ( V_318 ) ;
}
V_3:
F_105 ( V_51 ) ;
}
static int F_162 ( struct V_81 * V_82 )
{
unsigned char * V_324 = V_82 -> V_240 , * V_240 = NULL ;
struct V_83 * V_84 = V_82 -> V_85 ;
unsigned long V_62 ;
T_1 V_321 = 0 ;
F_75 ( ! V_82 -> V_100 ) ;
if ( ! V_84 )
return 0 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_107 & V_325 ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return 0 ;
}
if ( ! ( V_82 -> V_107 & V_121 ) )
goto V_3;
if ( ! V_84 -> V_118 -> V_326 ) {
F_4 ( L_120 ) ;
goto V_3;
}
V_240 = V_84 -> V_118 -> V_326 ( V_82 ) ;
if ( ! V_240 ) {
F_4 ( L_121
L_122 ,
V_82 -> V_73 -> V_96 ( V_82 ) , V_82 ) ;
goto V_3;
}
F_33 ( & V_82 -> V_93 , V_62 ) ;
V_321 = V_82 -> V_73 -> V_327 ( V_82 , V_328 ) ;
memcpy ( & V_324 [ V_321 ] , V_240 , V_328 ) ;
V_82 -> V_329 = V_328 + V_321 ;
F_30 ( L_123 ,
V_84 -> V_193 -> V_330 , V_84 -> V_118 -> V_184 , V_82 -> V_115 ) ;
return 0 ;
V_3:
F_33 ( & V_82 -> V_93 , V_62 ) ;
return - 1 ;
}
static inline long long F_163 ( struct V_83 * V_84 )
{
return V_84 -> V_118 -> V_331 ( V_84 ) + 1 ;
}
static int F_164 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
T_1 V_317 ;
if ( V_84 -> V_118 -> V_192 ( V_84 ) != V_332 )
return 0 ;
V_317 = ( V_82 -> V_238 / V_84 -> V_160 -> V_161 . V_162 ) ;
if ( ( V_82 -> V_333 + V_317 ) > F_163 ( V_84 ) ) {
F_4 ( L_124
L_125 ,
V_82 -> V_333 , V_317 ,
F_163 ( V_84 ) ) ;
return - V_174 ;
}
return 0 ;
}
static int F_165 ( unsigned char * V_62 , struct V_83 * V_84 )
{
int V_334 = ( V_84 -> V_118 -> V_181 ==
V_182 ) ;
if ( ! V_334 ) {
if ( ( V_62 [ 0 ] & 0x04 ) || ( V_62 [ 0 ] & 0x02 ) ) {
F_4 ( L_126
L_127
L_128 ) ;
return - V_335 ;
}
if ( ! ( V_62 [ 0 ] & 0x08 ) ) {
F_4 ( L_129
L_130 ) ;
return - V_335 ;
}
}
return 0 ;
}
static int F_114 (
struct V_81 * V_82 ,
unsigned char * V_227 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_196 * V_336 = V_84 -> V_160 ;
int V_36 = 0 , V_337 = 0 , V_334 ;
T_1 V_317 = 0 , V_338 = 0 , V_339 = 0 ;
T_5 V_340 ;
T_3 V_341 = 0 ;
if ( F_166 ( V_82 , V_227 ) < 0 ) {
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_291 ;
return - V_174 ;
}
V_36 = V_336 -> V_342 . V_343 ( V_82 , V_227 , & V_341 ) ;
if ( V_36 != 0 ) {
if ( V_36 > 0 ) {
F_30 ( L_131
L_132 ,
V_82 -> V_73 -> V_61 () , V_341 ) ;
F_167 ( V_82 , 0x04 , V_341 ) ;
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_292 ;
return - V_174 ;
}
goto V_344;
}
if ( V_336 -> V_345 . V_346 . V_347 ( V_82 , & V_339 ) != 0 ) {
if ( V_336 -> V_345 . V_346 . V_348 (
V_82 , V_227 , V_339 ) != 0 ) {
V_82 -> V_107 |= V_248 ;
V_82 -> V_107 |= V_349 ;
V_82 -> V_115 = V_294 ;
V_82 -> V_126 = V_293 ;
return - V_350 ;
}
}
V_334 =
( V_84 -> V_118 -> V_181 == V_182 ) ;
switch ( V_227 [ 0 ] ) {
case V_351 :
V_317 = F_149 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_141 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
break;
case V_228 :
V_317 = F_150 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
break;
case V_229 :
V_317 = F_151 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
break;
case V_230 :
V_317 = F_152 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_143 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
break;
case V_354 :
V_317 = F_149 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_141 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
break;
case V_355 :
case V_234 :
V_317 = F_150 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
if ( V_227 [ 1 ] & 0x8 )
V_82 -> V_107 |= V_356 ;
V_82 -> V_107 |= V_353 ;
break;
case V_357 :
V_317 = F_151 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
if ( V_227 [ 1 ] & 0x8 )
V_82 -> V_107 |= V_356 ;
V_82 -> V_107 |= V_353 ;
break;
case V_358 :
V_317 = F_152 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_143 ( V_227 ) ;
if ( V_227 [ 1 ] & 0x8 )
V_82 -> V_107 |= V_356 ;
V_82 -> V_107 |= V_353 ;
break;
case V_359 :
if ( ( V_82 -> V_146 != V_149 ) ||
! ( V_82 -> V_107 & V_265 ) )
goto V_344;
V_317 = F_150 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
if ( V_334 )
goto V_352;
V_82 -> V_360 = & F_155 ;
if ( V_227 [ 1 ] & 0x8 )
V_82 -> V_107 |= V_356 ;
break;
case V_361 :
V_340 = F_168 ( & V_227 [ 8 ] ) ;
switch ( V_340 ) {
case V_362 :
V_317 = F_153 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_333 = F_144 ( V_227 ) ;
V_82 -> V_107 |= V_353 ;
if ( V_334 )
goto V_352;
V_82 -> V_360 = & F_155 ;
if ( V_227 [ 1 ] & 0x8 )
V_82 -> V_107 |= V_356 ;
break;
case V_363 :
V_317 = F_153 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
if ( V_317 )
V_338 = F_154 ( 1 , V_227 , V_82 ) ;
else {
F_4 ( L_133
L_134 ) ;
goto V_344;
}
V_82 -> V_333 = F_25 ( & V_227 [ 12 ] ) ;
V_82 -> V_107 |= V_364 ;
if ( F_165 ( & V_227 [ 10 ] , V_84 ) < 0 )
goto V_352;
if ( ! V_334 )
V_82 -> V_313 = V_365 ;
break;
default:
F_4 ( L_135
L_136 , V_340 ) ;
goto V_352;
}
break;
case V_236 :
if ( V_84 -> V_118 -> V_192 ( V_84 ) != V_366 ) {
if ( ( V_227 [ 1 ] & 0x1f ) == V_367 &&
V_336 -> V_342 . V_368 == V_369 ) {
V_82 -> V_313 =
V_370 ;
}
V_338 = ( V_227 [ 6 ] << 24 ) | ( V_227 [ 7 ] << 16 ) |
( V_227 [ 8 ] << 8 ) | V_227 [ 9 ] ;
} else {
V_338 = ( V_227 [ 8 ] << 8 ) + V_227 [ 9 ] ;
}
V_82 -> V_107 |= V_364 ;
break;
case V_371 :
V_338 = V_227 [ 4 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_372 :
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_373 :
V_338 = V_227 [ 4 ] ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_374 ;
break;
case V_375 :
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_374 ;
break;
case V_376 :
case V_377 :
case V_378 :
case V_379 :
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_380 :
V_338 = V_381 ;
V_82 -> V_107 |= V_364 ;
break;
case V_382 :
case V_383 :
case V_384 :
case V_385 :
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_386 :
if ( V_336 -> V_345 . V_387 == V_388 )
V_82 -> V_313 = V_389 ;
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_390 :
if ( V_336 -> V_345 . V_387 == V_388 )
V_82 -> V_313 = V_391 ;
V_338 = ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_392 :
case V_393 :
V_338 = ( V_227 [ 8 ] << 8 ) + V_227 [ 9 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_394 :
V_338 = V_395 ;
V_82 -> V_107 |= V_364 ;
break;
case V_396 :
if ( V_84 -> V_118 -> V_192 ( V_84 ) != V_366 ) {
if ( V_227 [ 1 ] == V_397 &&
V_336 -> V_342 . V_368 == V_369 ) {
V_82 -> V_313 =
V_398 ;
}
V_338 = ( V_227 [ 6 ] << 24 ) | ( V_227 [ 7 ] << 16 ) |
( V_227 [ 8 ] << 8 ) | V_227 [ 9 ] ;
} else {
V_338 = ( V_227 [ 8 ] << 8 ) + V_227 [ 9 ] ;
}
V_82 -> V_107 |= V_364 ;
break;
case V_399 :
V_338 = ( V_227 [ 3 ] << 8 ) + V_227 [ 4 ] ;
if ( V_82 -> V_85 -> V_133 == V_134 )
V_82 -> V_135 = V_136 ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_400 ;
break;
case V_401 :
V_338 = ( V_227 [ 6 ] << 16 ) + ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_402 :
V_338 = V_403 ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_404 ;
break;
case V_405 :
case V_406 :
case V_407 :
V_338 = ( V_227 [ 6 ] << 24 ) | ( V_227 [ 7 ] << 16 ) | ( V_227 [ 8 ] << 8 ) | V_227 [ 9 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_408 :
switch ( V_82 -> V_251 [ 1 ] & 0x1f ) {
case V_409 :
if ( ! V_334 )
V_82 -> V_313 =
V_410 ;
break;
default:
if ( V_334 )
break;
F_4 ( L_137 ,
V_82 -> V_251 [ 1 ] & 0x1f ) ;
goto V_344;
}
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
V_338 = ( V_227 [ 10 ] << 24 ) | ( V_227 [ 11 ] << 16 ) |
( V_227 [ 12 ] << 8 ) | V_227 [ 13 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_417 :
case V_231 :
V_338 = ( V_227 [ 3 ] << 8 ) | V_227 [ 4 ] ;
V_82 -> V_107 |= V_364 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case V_418 :
V_338 = V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_419 :
V_338 = V_227 [ 4 ] ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_420 ;
break;
case V_421 :
V_338 = 65536 * V_227 [ 7 ] + 256 * V_227 [ 8 ] + V_227 [ 9 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_422 :
V_338 = ( V_227 [ 6 ] << 16 ) + ( V_227 [ 7 ] << 8 ) + V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_423 :
case V_424 :
if ( V_227 [ 0 ] == V_424 )
V_338 = ( V_227 [ 7 ] << 8 ) | V_227 [ 8 ] ;
else
V_338 = V_82 -> V_238 ;
if ( V_336 -> V_345 . V_387 != V_425 )
V_82 -> V_313 = V_426 ;
V_82 -> V_107 |= V_427 ;
break;
case V_428 :
case V_429 :
if ( V_227 [ 0 ] == V_429 )
V_338 = ( V_227 [ 7 ] << 8 ) | V_227 [ 8 ] ;
else
V_338 = V_82 -> V_238 ;
if ( V_336 -> V_345 . V_387 != V_425 )
V_82 -> V_313 = V_430 ;
V_82 -> V_107 |= V_427 ;
break;
case V_431 :
case V_432 :
if ( V_227 [ 0 ] == V_431 ) {
V_317 = F_150 ( V_227 , V_82 , & V_337 ) ;
V_82 -> V_333 = F_142 ( V_227 ) ;
} else {
V_317 = F_152 ( V_227 , V_82 , & V_337 ) ;
V_82 -> V_333 = F_143 ( V_227 ) ;
}
if ( V_337 )
goto V_352;
V_338 = F_154 ( V_317 , V_227 , V_82 ) ;
V_82 -> V_107 |= V_427 ;
if ( V_334 )
break;
if ( ( V_82 -> V_333 != 0 ) || ( V_317 != 0 ) ) {
if ( F_164 ( V_82 ) < 0 )
goto V_344;
}
V_82 -> V_313 = V_433 ;
break;
case V_434 :
V_338 = F_168 ( & V_227 [ 7 ] ) ;
V_82 -> V_107 |= V_364 ;
if ( ! V_334 )
V_82 -> V_313 = V_435 ;
break;
case V_436 :
V_317 = F_152 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
if ( V_317 )
V_338 = F_154 ( 1 , V_227 , V_82 ) ;
else {
F_4 ( L_138 ) ;
goto V_344;
}
V_82 -> V_333 = F_25 ( & V_227 [ 2 ] ) ;
V_82 -> V_107 |= V_364 ;
if ( F_165 ( & V_227 [ 1 ] , V_84 ) < 0 )
goto V_352;
if ( ! V_334 )
V_82 -> V_313 = V_365 ;
break;
case V_437 :
V_317 = F_150 ( V_227 , V_82 , & V_337 ) ;
if ( V_337 )
goto V_352;
if ( V_317 )
V_338 = F_154 ( 1 , V_227 , V_82 ) ;
else {
F_4 ( L_138 ) ;
goto V_344;
}
V_82 -> V_333 = F_169 ( & V_227 [ 2 ] ) ;
V_82 -> V_107 |= V_364 ;
if ( F_165 ( & V_227 [ 1 ] , V_84 ) < 0 )
goto V_352;
if ( ! V_334 )
V_82 -> V_313 = V_365 ;
break;
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_232 :
case V_445 :
V_82 -> V_107 |= V_427 ;
if ( ! V_334 )
V_82 -> V_313 = V_446 ;
break;
case V_447 :
case V_448 :
case V_449 :
case V_450 :
case V_451 :
V_82 -> V_107 |= V_427 ;
break;
case V_452 :
V_82 -> V_313 = V_453 ;
V_338 = ( V_227 [ 6 ] << 24 ) | ( V_227 [ 7 ] << 16 ) | ( V_227 [ 8 ] << 8 ) | V_227 [ 9 ] ;
if ( V_82 -> V_85 -> V_133 == V_134 )
V_82 -> V_135 = V_136 ;
V_82 -> V_107 |= V_364 ;
break;
case V_454 :
V_338 = ( V_227 [ 7 ] << 8 ) | V_227 [ 8 ] ;
V_82 -> V_107 |= V_364 ;
break;
case V_455 :
if ( ! V_334 )
goto V_352;
switch ( V_227 [ 2 ] & 0x3 ) {
case 0x0 :
V_317 = 0 ;
break;
case 0x1 :
V_317 = ( ( ( V_227 [ 1 ] & 0x1 ) ? V_227 [ 3 ] : 0 ) << 8 ) | V_227 [ 4 ] ;
break;
case 0x2 :
V_317 = ( ( ( V_227 [ 1 ] & 0x1 ) ? V_227 [ 5 ] : 0 ) << 8 ) | V_227 [ 6 ] ;
break;
case 0x3 :
F_4 ( L_139 ) ;
goto V_344;
}
if ( V_227 [ 2 ] & 0x4 ) {
V_338 = V_317 * ( ( V_227 [ 2 ] & 0x10 ) ?
V_84 -> V_160 -> V_161 . V_162 : 512 ) ;
} else {
V_338 = V_317 ;
}
V_82 -> V_107 |= V_364 ;
break;
default:
F_170 ( L_140
L_141 ,
V_82 -> V_73 -> V_61 () , V_227 [ 0 ] ) ;
goto V_352;
}
if ( V_82 -> V_262 )
V_82 -> V_238 = V_338 ;
if ( V_338 != V_82 -> V_238 ) {
F_170 ( L_142
L_143
L_144 , V_82 -> V_73 -> V_61 () ,
V_82 -> V_238 , V_338 , V_227 [ 0 ] ) ;
V_82 -> V_456 = V_338 ;
if ( V_82 -> V_146 == V_149 ) {
F_4 ( L_145
L_146 ) ;
goto V_344;
}
if ( ! V_36 && ( V_84 -> V_160 -> V_161 . V_162 != 512 ) ) {
F_4 ( L_147
L_148
L_149 , V_84 -> V_118 -> V_184 ) ;
goto V_344;
}
if ( V_338 > V_82 -> V_238 ) {
V_82 -> V_107 |= V_457 ;
V_82 -> V_458 = ( V_338 - V_82 -> V_238 ) ;
} else {
V_82 -> V_107 |= V_459 ;
V_82 -> V_458 = ( V_82 -> V_238 - V_338 ) ;
}
V_82 -> V_238 = V_338 ;
}
if ( V_82 -> V_107 & V_353 ) {
if ( V_317 > V_336 -> V_161 . V_460 ) {
F_171 ( V_461 L_150
L_151
L_152 , V_227 [ 0 ] , V_317 ,
V_336 -> V_161 . V_460 ) ;
goto V_344;
}
if ( V_317 > V_336 -> V_161 . V_163 ) {
F_171 ( V_461 L_150
L_153
L_152 , V_227 [ 0 ] , V_317 ,
V_336 -> V_161 . V_163 ) ;
goto V_344;
}
}
if ( ! ( V_334 || V_82 -> V_313 ||
( V_82 -> V_107 & V_353 ) ) )
goto V_352;
F_145 ( V_82 ) ;
return V_36 ;
V_352:
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_286 ;
return - V_174 ;
V_344:
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_249 ;
return - V_174 ;
}
static void F_138 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_81 * V_462 , * V_140 ;
int V_463 = 0 ;
if ( V_82 -> V_135 == V_274 ) {
F_64 ( & V_84 -> V_307 ) ;
F_80 () ;
V_84 -> V_464 ++ ;
F_30 ( L_154
L_155 , V_84 -> V_464 ,
V_82 -> V_246 ) ;
} else if ( V_82 -> V_135 == V_136 ) {
V_84 -> V_464 ++ ;
F_30 ( L_156
L_157 , V_84 -> V_464 ,
V_82 -> V_246 ) ;
} else if ( V_82 -> V_135 == V_305 ) {
F_64 ( & V_84 -> V_306 ) ;
F_80 () ;
V_84 -> V_464 ++ ;
F_30 ( L_158
L_152 , V_84 -> V_464 , V_82 -> V_246 ) ;
}
F_11 ( & V_84 -> V_210 ) ;
F_79 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
F_43 ( & V_462 -> V_241 ) ;
F_12 ( & V_84 -> V_210 ) ;
F_30 ( L_159
L_160
L_161 ,
V_462 -> V_251 [ 0 ] ,
V_462 -> V_135 , V_462 -> V_246 ) ;
F_72 ( V_462 ) ;
V_463 ++ ;
F_11 ( & V_84 -> V_210 ) ;
if ( V_462 -> V_135 == V_305 )
break;
}
F_12 ( & V_84 -> V_210 ) ;
if ( V_463 != 0 )
F_61 ( & V_84 -> V_110 . V_34 ) ;
}
static void F_172 ( struct V_81 * V_82 )
{
int V_36 = 0 ;
if ( V_82 -> V_85 -> V_133 == V_134 )
F_138 ( V_82 ) ;
if ( V_82 -> V_107 & V_121 ) {
V_36 = V_82 -> V_73 -> V_298 ( V_82 ) ;
if ( V_36 )
goto V_3;
}
switch ( V_82 -> V_146 ) {
case V_148 :
V_36 = V_82 -> V_73 -> V_465 ( V_82 ) ;
break;
case V_149 :
if ( V_82 -> V_466 ) {
V_36 = V_82 -> V_73 -> V_465 ( V_82 ) ;
if ( V_36 < 0 )
break;
}
case V_147 :
V_36 = V_82 -> V_73 -> V_298 ( V_82 ) ;
break;
default:
break;
}
V_3:
if ( V_36 < 0 ) {
F_140 ( V_82 , V_82 -> V_85 ) ;
return;
}
F_53 ( V_82 ) ;
F_52 ( V_82 ) ;
}
static void F_140 (
struct V_81 * V_82 ,
struct V_83 * V_84 )
{
F_27 ( & V_84 -> V_141 ) ;
F_28 ( & V_82 -> V_142 , & V_82 -> V_85 -> V_139 ) ;
F_59 ( & V_84 -> V_143 ) ;
F_111 () ;
F_29 ( & V_82 -> V_85 -> V_141 ) ;
F_130 ( & V_82 -> V_85 -> V_138 ) ;
}
static void V_128 ( struct V_113 * V_114 )
{
struct V_81 * V_82 = F_35 ( V_114 , struct V_81 , V_114 ) ;
int V_467 = 0 , V_36 ;
if ( V_82 -> V_85 -> V_133 == V_134 )
F_138 ( V_82 ) ;
if ( F_83 ( & V_82 -> V_85 -> V_143 ) != 0 )
F_130 ( & V_82 -> V_85 -> V_138 ) ;
if ( V_82 -> V_107 & V_121 ) {
if ( F_162 ( V_82 ) < 0 )
V_467 = V_285 ;
if ( V_82 -> V_115 ) {
V_36 = F_122 (
V_82 , V_467 , 1 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
F_53 ( V_82 ) ;
F_52 ( V_82 ) ;
return;
}
}
if ( V_82 -> V_360 )
V_82 -> V_360 ( V_82 ) ;
switch ( V_82 -> V_146 ) {
case V_148 :
F_11 ( & V_82 -> V_100 -> V_252 ) ;
if ( V_82 -> V_100 -> V_253 ) {
V_82 -> V_100 -> V_253 -> V_254 . V_468 +=
V_82 -> V_238 ;
}
F_12 ( & V_82 -> V_100 -> V_252 ) ;
V_36 = V_82 -> V_73 -> V_465 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
break;
case V_149 :
F_11 ( & V_82 -> V_100 -> V_252 ) ;
if ( V_82 -> V_100 -> V_253 ) {
V_82 -> V_100 -> V_253 -> V_254 . V_469 +=
V_82 -> V_238 ;
}
F_12 ( & V_82 -> V_100 -> V_252 ) ;
if ( V_82 -> V_466 ) {
F_11 ( & V_82 -> V_100 -> V_252 ) ;
if ( V_82 -> V_100 -> V_253 ) {
V_82 -> V_100 -> V_253 -> V_254 . V_468 +=
V_82 -> V_238 ;
}
F_12 ( & V_82 -> V_100 -> V_252 ) ;
V_36 = V_82 -> V_73 -> V_465 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
break;
}
case V_147 :
V_36 = V_82 -> V_73 -> V_298 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
break;
default:
break;
}
F_53 ( V_82 ) ;
F_52 ( V_82 ) ;
return;
V_300:
F_30 ( L_162
L_163 , V_82 , V_82 -> V_146 ) ;
V_82 -> V_92 = V_144 ;
F_140 ( V_82 , V_82 -> V_85 ) ;
}
static inline void F_173 ( struct V_319 * V_470 , int V_471 )
{
struct V_319 * V_320 ;
int V_322 ;
F_158 (sgl, sg, nents, count)
F_174 ( F_160 ( V_320 ) ) ;
F_105 ( V_470 ) ;
}
static inline void F_175 ( struct V_81 * V_82 )
{
if ( V_82 -> V_107 & V_472 )
return;
F_173 ( V_82 -> V_120 , V_82 -> V_314 ) ;
V_82 -> V_120 = NULL ;
V_82 -> V_314 = 0 ;
F_173 ( V_82 -> V_466 , V_82 -> V_473 ) ;
V_82 -> V_466 = NULL ;
V_82 -> V_473 = 0 ;
}
static void F_176 ( struct V_81 * V_82 )
{
F_10 ( ! V_82 -> V_73 ) ;
if ( V_82 -> V_107 & V_108 )
F_177 ( V_82 -> V_266 ) ;
if ( V_82 -> V_251 != V_82 -> V_250 )
F_105 ( V_82 -> V_251 ) ;
if ( V_82 -> V_474 != 0 ) {
F_123 ( V_82 -> V_38 , V_82 ) ;
return;
}
V_82 -> V_73 -> V_475 ( V_82 ) ;
}
static void F_57 ( struct V_81 * V_82 )
{
unsigned long V_62 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( F_83 ( & V_82 -> V_476 ) ) {
if ( ! F_178 ( & V_82 -> V_476 ) )
goto V_477;
}
if ( V_82 -> V_86 & V_104 ) {
V_82 -> V_86 &= ~ V_104 ;
F_50 ( V_82 ) ;
}
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_175 ( V_82 ) ;
F_176 ( V_82 ) ;
return;
V_477:
F_33 ( & V_82 -> V_93 , V_62 ) ;
}
int F_179 (
struct V_81 * V_82 ,
struct V_319 * V_470 ,
T_1 V_478 ,
struct V_319 * V_479 ,
T_1 V_480 )
{
if ( ! V_470 || ! V_478 )
return 0 ;
if ( ( V_82 -> V_107 & V_353 ) ||
( V_82 -> V_107 & V_364 ) ) {
if ( V_82 -> V_107 & V_457 ) {
F_170 ( L_164
L_165 ) ;
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_249 ;
return - V_174 ;
}
V_82 -> V_120 = V_470 ;
V_82 -> V_314 = V_478 ;
if ( V_479 && V_480 ) {
V_82 -> V_466 = V_479 ;
V_82 -> V_473 = V_480 ;
}
V_82 -> V_107 |= V_472 ;
}
return 0 ;
}
void * F_180 ( struct V_81 * V_82 )
{
struct V_319 * V_320 = V_82 -> V_120 ;
struct V_481 * * V_482 ;
int V_180 ;
F_10 ( ! V_320 ) ;
if ( ! V_82 -> V_314 )
return NULL ;
else if ( V_82 -> V_314 == 1 )
return F_181 ( F_160 ( V_320 ) ) + V_320 -> V_321 ;
V_482 = F_156 ( sizeof( * V_482 ) * V_82 -> V_314 , V_39 ) ;
if ( ! V_482 )
return NULL ;
F_158 (cmd->t_data_sg, sg, cmd->t_data_nents, i) {
V_482 [ V_180 ] = F_160 ( V_320 ) ;
}
V_82 -> V_483 = F_182 ( V_482 , V_82 -> V_314 , V_484 , V_485 ) ;
F_105 ( V_482 ) ;
if ( ! V_82 -> V_483 )
return NULL ;
return V_82 -> V_483 + V_82 -> V_120 [ 0 ] . V_321 ;
}
void F_183 ( struct V_81 * V_82 )
{
if ( ! V_82 -> V_314 ) {
return;
} else if ( V_82 -> V_314 == 1 ) {
F_184 ( F_160 ( V_82 -> V_120 ) ) ;
return;
}
F_185 ( V_82 -> V_483 ) ;
V_82 -> V_483 = NULL ;
}
static int
F_186 ( struct V_81 * V_82 )
{
T_1 V_323 = V_82 -> V_238 ;
unsigned int V_471 ;
struct V_481 * V_481 ;
T_4 V_486 ;
int V_180 = 0 ;
V_471 = F_187 ( V_323 , V_487 ) ;
V_82 -> V_120 = F_156 ( sizeof( struct V_319 ) * V_471 , V_39 ) ;
if ( ! V_82 -> V_120 )
return - V_25 ;
V_82 -> V_314 = V_471 ;
F_188 ( V_82 -> V_120 , V_471 ) ;
V_486 = V_82 -> V_107 & V_353 ? 0 : V_488 ;
while ( V_323 ) {
T_1 V_489 = F_189 ( T_1 , V_323 , V_487 ) ;
V_481 = F_190 ( V_39 | V_486 ) ;
if ( ! V_481 )
goto V_3;
F_191 ( & V_82 -> V_120 [ V_180 ] , V_481 , V_489 , 0 ) ;
V_323 -= V_489 ;
V_180 ++ ;
}
return 0 ;
V_3:
while ( V_180 >= 0 ) {
F_174 ( F_160 ( & V_82 -> V_120 [ V_180 ] ) ) ;
V_180 -- ;
}
F_105 ( V_82 -> V_120 ) ;
V_82 -> V_120 = NULL ;
return - V_25 ;
}
int F_118 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
int V_36 = 0 ;
if ( ! ( V_82 -> V_107 & V_472 ) &&
V_82 -> V_238 ) {
V_36 = F_186 ( V_82 ) ;
if ( V_36 < 0 )
goto V_490;
}
if ( ( V_82 -> V_107 & V_364 ) &&
! V_82 -> V_238 ) {
F_27 ( & V_82 -> V_93 ) ;
V_82 -> V_92 = V_129 ;
V_82 -> V_86 |= V_97 ;
F_29 ( & V_82 -> V_93 ) ;
if ( V_82 -> V_251 [ 0 ] == V_419 ) {
T_3 V_491 = 0 , V_492 = 0 ;
F_192 ( V_82 ,
& V_491 , & V_492 ) ;
}
F_68 ( & V_82 -> V_114 , V_128 ) ;
F_69 ( V_22 , & V_82 -> V_114 ) ;
return 0 ;
}
if ( V_82 -> V_107 & V_353 ) {
struct V_161 * V_493 = & V_84 -> V_160 -> V_161 ;
if ( F_164 ( V_82 ) < 0 )
return - V_174 ;
F_10 ( V_82 -> V_238 % V_493 -> V_162 ) ;
F_10 ( F_187 ( V_82 -> V_238 , V_493 -> V_162 ) >
V_493 -> V_163 ) ;
}
F_59 ( & V_82 -> V_476 ) ;
if ( V_82 -> V_146 == V_149 ) {
F_70 ( V_82 ) ;
return F_193 ( V_82 ) ;
}
F_147 ( V_82 ) ;
return 0 ;
V_490:
V_82 -> V_107 |= V_248 ;
V_82 -> V_126 = V_127 ;
return - V_174 ;
}
void F_194 ( struct V_81 * V_82 )
{
F_147 ( V_82 ) ;
}
static void F_195 ( struct V_81 * V_82 )
{
int V_36 ;
V_36 = V_82 -> V_73 -> V_494 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 ) {
F_30 ( L_166 ,
V_82 ) ;
F_140 ( V_82 , V_82 -> V_85 ) ;
}
}
static int F_193 ( struct V_81 * V_82 )
{
unsigned long V_62 ;
int V_36 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_92 = V_495 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_51 ( V_82 , 1 , 0 ) ;
V_36 = V_82 -> V_73 -> V_494 ( V_82 ) ;
if ( V_36 == - V_299 || V_36 == - V_25 )
goto V_300;
else if ( V_36 < 0 )
return V_36 ;
return 1 ;
V_300:
F_30 ( L_166 , V_82 ) ;
V_82 -> V_92 = V_145 ;
F_140 ( V_82 , V_82 -> V_85 ) ;
return 0 ;
}
void F_126 ( struct V_81 * V_82 , int V_496 )
{
if ( ! ( V_82 -> V_107 & V_497 ) ) {
if ( V_496 && ( V_82 -> V_107 & V_108 ) )
F_196 ( V_82 ) ;
F_176 ( V_82 ) ;
} else {
if ( V_496 )
F_196 ( V_82 ) ;
F_197 ( V_82 -> V_38 -> V_48 , V_82 ) ;
if ( V_82 -> V_100 )
F_53 ( V_82 ) ;
F_57 ( V_82 ) ;
}
}
void F_120 ( struct V_2 * V_38 , struct V_81 * V_81 ,
bool V_498 )
{
unsigned long V_62 ;
F_23 ( & V_81 -> V_499 ) ;
if ( V_498 == true ) {
F_26 ( & V_81 -> V_499 ) ;
V_81 -> V_107 |= V_500 ;
}
F_32 ( & V_38 -> V_44 , V_62 ) ;
F_28 ( & V_81 -> V_242 , & V_38 -> V_42 ) ;
V_81 -> V_474 = 1 ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
}
static void F_198 ( struct V_64 * V_64 )
{
struct V_81 * V_81 = F_35 ( V_64 , struct V_81 , V_499 ) ;
struct V_2 * V_38 = V_81 -> V_38 ;
unsigned long V_62 ;
F_32 ( & V_38 -> V_44 , V_62 ) ;
if ( F_44 ( & V_81 -> V_242 ) ) {
F_33 ( & V_38 -> V_44 , V_62 ) ;
V_81 -> V_73 -> V_475 ( V_81 ) ;
return;
}
if ( V_38 -> V_501 && V_81 -> V_502 ) {
F_33 ( & V_38 -> V_44 , V_62 ) ;
F_40 ( & V_81 -> V_244 ) ;
return;
}
F_43 ( & V_81 -> V_242 ) ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
V_81 -> V_73 -> V_475 ( V_81 ) ;
}
int F_123 ( struct V_2 * V_38 , struct V_81 * V_81 )
{
return F_38 ( & V_81 -> V_499 , F_198 ) ;
}
void F_199 ( struct V_2 * V_38 )
{
struct V_81 * V_81 ;
unsigned long V_62 ;
F_75 ( ! F_44 ( & V_38 -> V_43 ) ) ;
F_15 ( & V_38 -> V_43 ) ;
F_32 ( & V_38 -> V_44 , V_62 ) ;
V_38 -> V_501 = 1 ;
F_78 ( & V_38 -> V_42 , & V_38 -> V_43 ) ;
F_200 (se_cmd, &se_sess->sess_wait_list, se_cmd_list)
V_81 -> V_502 = 1 ;
F_33 ( & V_38 -> V_44 , V_62 ) ;
}
void F_201 (
struct V_2 * V_38 ,
int V_496 )
{
struct V_81 * V_81 , * V_503 ;
bool V_260 = false ;
F_79 (se_cmd, tmp_cmd,
&se_sess->sess_wait_list, se_cmd_list) {
F_43 ( & V_81 -> V_242 ) ;
F_30 ( L_167
L_168 , V_81 , V_81 -> V_92 ,
V_81 -> V_73 -> V_283 ( V_81 ) ) ;
if ( V_496 ) {
F_30 ( L_169
L_170 , V_81 , V_81 -> V_92 ,
V_81 -> V_73 -> V_283 ( V_81 ) ) ;
V_260 = F_196 ( V_81 ) ;
F_30 ( L_171
L_170 , V_81 , V_81 -> V_92 ,
V_81 -> V_73 -> V_283 ( V_81 ) ) ;
}
if ( ! V_260 ) {
F_137 ( & V_81 -> V_244 ) ;
F_30 ( L_172
L_170 , V_81 , V_81 -> V_92 ,
V_81 -> V_73 -> V_283 ( V_81 ) ) ;
}
V_81 -> V_73 -> V_475 ( V_81 ) ;
}
}
static int F_202 ( struct V_81 * V_82 , struct V_100 * V_103 )
{
unsigned long V_62 ;
int V_36 = 0 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_86 & V_99 ) {
V_82 -> V_86 &= ~ V_94 ;
F_30 ( L_173 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_51 ( V_82 , 1 , 0 ) ;
return - V_279 ;
}
V_82 -> V_86 |= V_504 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_61 ( & V_82 -> V_85 -> V_110 . V_34 ) ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( ( V_82 -> V_86 & V_87 ) &&
( V_82 -> V_86 & V_284 ) ) {
if ( ! F_136 ( V_82 , & V_62 ) )
V_36 ++ ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
} else {
F_33 ( & V_82 -> V_93 ,
V_62 ) ;
F_74 ( V_82 ) ;
}
F_30 ( L_174
L_168 , V_82 , V_36 ) ;
if ( ! V_36 ) {
F_30 ( L_175 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_137 ( & V_82 -> V_98 ) ;
F_30 ( L_176 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
}
F_56 ( V_82 ) ;
return 0 ;
}
static void F_203 ( struct V_100 * V_103 )
{
struct V_81 * V_82 = NULL ;
unsigned long V_505 , V_506 ;
F_32 ( & V_103 -> V_105 , V_505 ) ;
while ( ! F_44 ( & V_103 -> V_507 ) ) {
V_82 = F_63 ( & V_103 -> V_507 ,
struct V_81 , V_106 ) ;
F_54 ( & V_82 -> V_106 ) ;
F_11 ( & V_82 -> V_93 ) ;
F_30 ( L_177
L_178 ,
V_82 -> V_100 -> V_258 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
V_82 -> V_86 |= V_94 ;
F_12 ( & V_82 -> V_93 ) ;
F_33 ( & V_103 -> V_105 , V_505 ) ;
if ( ! V_82 -> V_100 ) {
F_4 ( L_179 ,
V_82 -> V_73 -> V_96 ( V_82 ) ,
V_82 -> V_73 -> V_283 ( V_82 ) , V_82 -> V_92 ) ;
F_204 () ;
}
F_30 ( L_180
L_181 , V_82 -> V_100 -> V_258 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
if ( F_202 ( V_82 , V_82 -> V_100 ) < 0 ) {
F_32 ( & V_103 -> V_105 , V_505 ) ;
continue;
}
F_30 ( L_182
L_183 ,
V_82 -> V_100 -> V_258 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_32 ( & V_82 -> V_93 , V_506 ) ;
if ( ! ( V_82 -> V_86 & V_104 ) ) {
F_33 ( & V_82 -> V_93 , V_506 ) ;
goto V_508;
}
V_82 -> V_86 &= ~ V_104 ;
F_50 ( V_82 ) ;
F_33 ( & V_82 -> V_93 , V_506 ) ;
V_508:
F_122 ( V_82 ,
V_285 , 0 ) ;
F_32 ( & V_82 -> V_93 , V_506 ) ;
if ( V_82 -> V_86 & V_504 ) {
F_30 ( L_184
L_185 ,
V_103 -> V_258 ,
V_82 , V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_33 ( & V_82 -> V_93 ,
V_506 ) ;
F_51 ( V_82 , 1 , 0 ) ;
F_40 ( & V_82 -> V_243 ) ;
F_32 ( & V_103 -> V_105 , V_505 ) ;
continue;
}
F_30 ( L_186 ,
V_103 -> V_258 , V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_33 ( & V_82 -> V_93 , V_506 ) ;
F_32 ( & V_103 -> V_105 , V_505 ) ;
}
F_33 ( & V_103 -> V_105 , V_505 ) ;
}
static int F_205 ( void * V_509 )
{
struct V_100 * V_103 = V_509 ;
F_203 ( V_103 ) ;
F_40 ( & V_103 -> V_510 ) ;
return 0 ;
}
int F_206 ( struct V_100 * V_103 )
{
struct V_511 * V_512 ;
V_512 = F_101 ( F_205 , V_103 ,
L_187 , V_103 -> V_258 ) ;
if ( F_102 ( V_512 ) ) {
F_4 ( L_188 ) ;
return F_207 ( V_512 ) ;
}
F_137 ( & V_103 -> V_510 ) ;
return 0 ;
}
bool F_196 ( struct V_81 * V_82 )
{
unsigned long V_62 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( ! ( V_82 -> V_107 & V_497 ) &&
! ( V_82 -> V_107 & V_108 ) ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return false ;
}
if ( ! ( V_82 -> V_107 & V_304 ) &&
! ( V_82 -> V_107 & V_108 ) ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return false ;
}
if ( V_82 -> V_86 & V_94 ) {
F_30 ( L_189
L_190
L_191 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_40 ( & V_82 -> V_98 ) ;
F_137 ( & V_82 -> V_243 ) ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
F_50 ( V_82 ) ;
F_30 ( L_192
L_193
L_194 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
V_82 -> V_86 &= ~ V_94 ;
}
if ( ! ( V_82 -> V_86 & V_97 ) ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return false ;
}
V_82 -> V_86 |= V_99 ;
F_30 ( L_195
L_196 ,
V_82 , V_82 -> V_73 -> V_96 ( V_82 ) ,
V_82 -> V_73 -> V_283 ( V_82 ) , V_82 -> V_92 ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
F_61 ( & V_82 -> V_85 -> V_110 . V_34 ) ;
F_137 ( & V_82 -> V_101 ) ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
V_82 -> V_86 &= ~ ( V_97 | V_99 ) ;
F_30 ( L_197
L_198 ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
return true ;
}
static int F_208 (
struct V_81 * V_82 ,
T_3 * V_513 ,
T_3 * V_514 )
{
* V_513 = V_82 -> V_515 ;
* V_514 = V_82 -> V_516 ;
return 0 ;
}
static int F_167 (
struct V_81 * V_82 ,
T_3 V_513 ,
T_3 V_514 )
{
V_82 -> V_515 = V_513 ;
V_82 -> V_516 = V_514 ;
return 0 ;
}
int F_122 (
struct V_81 * V_82 ,
T_3 V_467 ,
int V_517 )
{
unsigned char * V_324 = V_82 -> V_240 ;
unsigned long V_62 ;
int V_321 ;
T_3 V_513 = 0 , V_514 = 0 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_107 & V_325 ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return 0 ;
}
V_82 -> V_107 |= V_325 ;
F_33 ( & V_82 -> V_93 , V_62 ) ;
if ( ! V_467 && V_517 )
goto V_518;
if ( ! V_517 )
V_82 -> V_107 |= V_519 ;
V_321 = V_82 -> V_73 -> V_327 ( V_82 ,
V_328 ) ;
switch ( V_467 ) {
case V_285 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x25 ;
break;
case V_286 :
case V_524 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x20 ;
break;
case V_288 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x24 ;
break;
case V_290 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_525 ;
V_324 [ V_321 + V_523 ] = 0x29 ;
V_324 [ V_321 + V_526 ] = 0x03 ;
break;
case V_527 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_525 ;
V_324 [ V_321 + V_523 ] = 0x0c ;
V_324 [ V_321 + V_526 ] = 0x0d ;
break;
case V_249 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x24 ;
break;
case V_287 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x26 ;
break;
case V_528 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_525 ;
V_324 [ V_321 + V_523 ] = 0x0c ;
V_324 [ V_321 + V_526 ] = 0x0c ;
break;
case V_529 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_525 ;
V_324 [ V_321 + V_523 ] = 0x47 ;
V_324 [ V_321 + V_526 ] = 0x05 ;
break;
case V_530 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_525 ;
V_324 [ V_321 + V_523 ] = 0x11 ;
V_324 [ V_321 + V_526 ] = 0x13 ;
break;
case V_289 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_531 ;
V_324 [ V_321 + V_523 ] = 0x27 ;
break;
case V_291 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_532 ;
F_209 ( V_82 , & V_513 , & V_514 ) ;
V_324 [ V_321 + V_523 ] = V_513 ;
V_324 [ V_321 + V_526 ] = V_514 ;
break;
case V_292 :
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_533 ;
F_208 ( V_82 , & V_513 , & V_514 ) ;
V_324 [ V_321 + V_523 ] = V_513 ;
V_324 [ V_321 + V_526 ] = V_514 ;
break;
case V_127 :
default:
V_324 [ V_321 ] = 0x70 ;
V_324 [ V_321 + V_520 ] = 10 ;
V_324 [ V_321 + V_521 ] = V_522 ;
V_324 [ V_321 + V_523 ] = 0x80 ;
break;
}
V_82 -> V_115 = V_534 ;
V_82 -> V_329 = V_328 + V_321 ;
V_518:
return V_82 -> V_73 -> V_298 ( V_82 ) ;
}
int F_135 ( struct V_81 * V_82 , int V_535 )
{
int V_36 = 0 ;
if ( V_82 -> V_86 & V_125 ) {
if ( ! V_535 ||
( V_82 -> V_107 & V_536 ) )
return 1 ;
F_30 ( L_199
L_200 ,
V_82 -> V_251 [ 0 ] ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
V_82 -> V_107 |= V_536 ;
V_82 -> V_73 -> V_298 ( V_82 ) ;
V_36 = 1 ;
}
return V_36 ;
}
void F_210 ( struct V_81 * V_82 )
{
unsigned long V_62 ;
F_32 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_107 & V_325 ) {
F_33 ( & V_82 -> V_93 , V_62 ) ;
return;
}
F_33 ( & V_82 -> V_93 , V_62 ) ;
if ( V_82 -> V_146 == V_149 ) {
if ( V_82 -> V_73 -> V_537 ( V_82 ) != 0 ) {
V_82 -> V_86 |= V_125 ;
F_111 () ;
}
}
V_82 -> V_115 = V_538 ;
F_30 ( L_201
L_202 , V_82 -> V_251 [ 0 ] ,
V_82 -> V_73 -> V_96 ( V_82 ) ) ;
V_82 -> V_73 -> V_298 ( V_82 ) ;
}
static int F_211 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_266 * V_539 = V_82 -> V_266 ;
int V_36 ;
switch ( V_539 -> V_540 ) {
case V_275 :
F_212 ( V_84 , V_539 , V_82 -> V_38 ) ;
break;
case V_541 :
case V_542 :
case V_543 :
V_539 -> V_267 = V_544 ;
break;
case V_545 :
V_36 = F_213 ( V_84 , V_539 , NULL , NULL ) ;
V_539 -> V_267 = ( ! V_36 ) ? V_546 :
V_547 ;
break;
case V_548 :
V_539 -> V_267 = V_547 ;
break;
case V_549 :
V_539 -> V_267 = V_547 ;
break;
default:
F_4 ( L_203 ,
V_539 -> V_540 ) ;
V_539 -> V_267 = V_547 ;
break;
}
V_82 -> V_92 = V_550 ;
V_82 -> V_73 -> V_269 ( V_82 ) ;
F_52 ( V_82 ) ;
return 0 ;
}
static int V_226 ( void * V_551 )
{
int V_36 ;
struct V_81 * V_82 ;
struct V_83 * V_84 = V_551 ;
while ( ! F_214 () ) {
V_36 = F_215 ( V_84 -> V_110 . V_34 ,
F_83 ( & V_84 -> V_110 . V_32 ) ||
F_214 () ) ;
if ( V_36 < 0 )
goto V_3;
V_552:
V_82 = F_62 ( & V_84 -> V_110 ) ;
if ( ! V_82 )
continue;
switch ( V_82 -> V_92 ) {
case V_256 :
F_204 () ;
break;
case V_277 :
if ( ! V_82 -> V_73 -> V_553 ) {
F_4 ( L_204
L_205 ) ;
F_204 () ;
}
V_36 = V_82 -> V_73 -> V_553 ( V_82 ) ;
if ( V_36 < 0 ) {
F_66 ( V_82 ) ;
break;
}
V_36 = F_118 ( V_82 ) ;
if ( V_36 < 0 ) {
F_66 ( V_82 ) ;
break;
}
break;
case V_280 :
F_194 ( V_82 ) ;
break;
case V_281 :
F_211 ( V_82 ) ;
break;
case V_145 :
F_195 ( V_82 ) ;
break;
case V_144 :
F_172 ( V_82 ) ;
break;
default:
F_4 ( L_206
L_207 ,
V_82 -> V_92 ,
V_82 -> V_73 -> V_96 ( V_82 ) ,
V_82 -> V_73 -> V_283 ( V_82 ) ,
V_82 -> V_100 -> V_258 ) ;
F_204 () ;
}
goto V_552;
}
V_3:
F_75 ( ! F_44 ( & V_84 -> V_90 ) ) ;
F_75 ( ! F_44 ( & V_84 -> V_110 . V_33 ) ) ;
V_84 -> V_225 = NULL ;
return 0 ;
}
