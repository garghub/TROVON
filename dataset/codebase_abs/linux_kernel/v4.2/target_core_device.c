T_1
F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_3 = NULL ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_6 ;
struct V_8 * V_9 ;
F_2 () ;
V_9 = F_3 ( V_7 , V_2 ) ;
if ( V_9 ) {
F_4 ( & V_9 -> V_10 ) ;
if ( ( V_1 -> V_11 == V_12 ) &&
( V_9 -> V_13 & V_14 ) ) {
F_5 ( L_1
L_2 ,
V_1 -> V_15 -> V_16 () ,
V_2 ) ;
F_6 () ;
return V_17 ;
}
if ( V_1 -> V_11 == V_12 )
F_7 ( V_1 -> V_18 ,
& V_9 -> V_19 ) ;
else if ( V_1 -> V_11 == V_20 )
F_7 ( V_1 -> V_18 ,
& V_9 -> V_21 ) ;
V_3 = F_8 ( V_9 -> V_3 ) ;
V_1 -> V_3 = F_8 ( V_9 -> V_3 ) ;
V_1 -> V_22 = V_9 -> V_22 ;
V_1 -> V_23 = V_2 ;
V_1 -> V_24 |= V_25 ;
F_9 ( & V_3 -> V_26 ) ;
V_1 -> V_27 = true ;
}
F_6 () ;
if ( ! V_3 ) {
if ( V_2 != 0 ) {
F_5 ( L_3
L_2 ,
V_1 -> V_15 -> V_16 () ,
V_2 ) ;
return V_28 ;
}
if ( ( V_1 -> V_11 != V_20 ) &&
( V_1 -> V_11 != V_29 ) )
return V_17 ;
V_3 = V_5 -> V_30 -> V_31 ;
V_1 -> V_3 = V_5 -> V_30 -> V_31 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 |= V_25 ;
F_9 ( & V_3 -> V_26 ) ;
V_1 -> V_27 = true ;
}
V_1 -> V_32 = F_10 ( V_3 -> V_33 ) ;
F_4 ( & V_1 -> V_32 -> V_34 ) ;
if ( V_1 -> V_11 == V_12 )
F_7 ( V_1 -> V_18 ,
& V_1 -> V_32 -> V_19 ) ;
else if ( V_1 -> V_11 == V_20 )
F_7 ( V_1 -> V_18 ,
& V_1 -> V_32 -> V_21 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 , T_2 V_2 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 = NULL ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_6 ;
struct V_35 * V_36 = V_1 -> V_35 ;
unsigned long V_37 ;
F_2 () ;
V_9 = F_3 ( V_7 , V_2 ) ;
if ( V_9 ) {
V_36 -> V_38 = F_8 ( V_9 -> V_3 ) ;
V_1 -> V_3 = F_8 ( V_9 -> V_3 ) ;
V_3 = F_8 ( V_9 -> V_3 ) ;
V_1 -> V_22 = V_9 -> V_22 ;
V_1 -> V_23 = V_2 ;
}
F_6 () ;
if ( ! V_3 ) {
F_12 ( L_3
L_2 ,
V_1 -> V_15 -> V_16 () ,
V_2 ) ;
return - V_39 ;
}
V_1 -> V_32 = F_10 ( V_3 -> V_33 ) ;
V_36 -> V_40 = F_10 ( V_3 -> V_33 ) ;
F_13 ( & V_36 -> V_40 -> V_41 , V_37 ) ;
F_14 ( & V_36 -> V_42 , & V_36 -> V_40 -> V_43 ) ;
F_15 ( & V_36 -> V_40 -> V_41 , V_37 ) ;
return 0 ;
}
bool F_16 ( struct V_1 * V_44 )
{
struct V_4 * V_5 = V_44 -> V_5 ;
struct V_8 * V_9 ;
bool V_45 ;
F_2 () ;
V_9 = F_3 ( V_5 -> V_6 , V_44 -> V_23 ) ;
V_45 = ( V_9 && V_9 -> V_13 & V_14 ) ;
F_6 () ;
return V_45 ;
}
struct V_8 * F_17 (
struct V_6 * V_7 ,
T_3 V_46 )
{
struct V_8 * V_9 ;
struct V_3 * V_47 ;
struct V_48 * V_49 = V_7 -> V_30 ;
F_2 () ;
F_18 (deve, &nacl->lun_entry_hlist, link) {
V_47 = F_8 ( V_9 -> V_3 ) ;
if ( ! V_47 ) {
F_5 ( L_4
L_5 ,
V_49 -> V_50 -> V_16 () ) ;
continue;
}
if ( V_47 -> V_51 != V_46 )
continue;
F_19 ( & V_9 -> V_52 ) ;
F_6 () ;
return V_9 ;
}
F_6 () ;
return NULL ;
}
void F_20 (
struct V_6 * V_7 ,
struct V_48 * V_49 )
{
struct V_8 * V_9 ;
F_21 ( & V_7 -> V_53 ) ;
F_18 (deve, &nacl->lun_entry_hlist, link) {
struct V_3 * V_47 = F_22 ( V_9 -> V_3 ,
F_23 ( & V_7 -> V_53 ) ) ;
F_24 ( V_47 , V_9 , V_7 , V_49 ) ;
}
F_25 ( & V_7 -> V_53 ) ;
}
void F_26 (
T_2 V_54 ,
T_4 V_55 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_21 ( & V_7 -> V_53 ) ;
V_9 = F_3 ( V_7 , V_54 ) ;
if ( V_9 ) {
if ( V_55 & V_56 ) {
V_9 -> V_13 &= ~ V_14 ;
V_9 -> V_13 |= V_56 ;
} else {
V_9 -> V_13 &= ~ V_56 ;
V_9 -> V_13 |= V_14 ;
}
}
F_25 ( & V_7 -> V_53 ) ;
}
struct V_8 * F_3 ( struct V_6 * V_7 , T_2 V_54 )
{
struct V_8 * V_9 ;
F_18 (deve, &nacl->lun_entry_hlist, link)
if ( V_9 -> V_54 == V_54 )
return V_9 ;
return NULL ;
}
void F_27 ( struct V_57 * V_57 )
{
struct V_8 * V_9 = F_28 ( V_57 , struct V_8 ,
V_52 ) ;
F_29 ( & V_9 -> V_58 ) ;
}
static void
F_30 ( struct V_6 * V_7 , struct V_8 * V_59 ,
bool V_60 )
{
struct V_8 * V_61 ;
F_2 () ;
F_18 (tmp, &nacl->lun_entry_hlist, link) {
if ( V_60 && V_61 == V_59 )
continue;
F_31 ( V_61 , 0x3F ,
V_62 ) ;
}
F_6 () ;
}
int F_32 (
struct V_3 * V_47 ,
struct V_63 * V_64 ,
T_2 V_54 ,
T_4 V_55 ,
struct V_6 * V_7 ,
struct V_48 * V_49 )
{
struct V_8 * V_65 , * V_59 ;
V_59 = F_33 ( sizeof( * V_59 ) , V_66 ) ;
if ( ! V_59 ) {
F_5 ( L_6 ) ;
return - V_67 ;
}
F_34 ( & V_59 -> V_68 , 0 ) ;
F_35 ( & V_59 -> V_69 ) ;
F_36 ( & V_59 -> V_70 ) ;
F_36 ( & V_59 -> V_71 ) ;
V_59 -> V_54 = V_54 ;
F_37 ( & V_59 -> V_52 ) ;
F_38 ( & V_59 -> V_58 ) ;
if ( V_55 & V_56 )
V_59 -> V_13 |= V_56 ;
else
V_59 -> V_13 |= V_14 ;
V_59 -> V_72 = F_39 () ;
V_59 -> V_73 ++ ;
F_21 ( & V_7 -> V_53 ) ;
V_65 = F_3 ( V_7 , V_54 ) ;
if ( V_65 && V_65 -> V_3 ) {
struct V_3 * V_74 = F_22 ( V_65 -> V_3 ,
F_23 ( & V_7 -> V_53 ) ) ;
if ( V_74 != V_47 ) {
F_5 ( L_7
L_8
L_9 , V_7 -> V_75 ) ;
F_25 ( & V_7 -> V_53 ) ;
F_40 ( V_59 ) ;
return - V_76 ;
}
F_41 ( V_65 -> V_63 != NULL ) ;
F_42 ( V_59 -> V_3 , V_47 ) ;
F_42 ( V_59 -> V_63 , V_64 ) ;
F_43 ( & V_65 -> V_77 ) ;
F_44 ( & V_59 -> V_77 , & V_7 -> V_78 ) ;
F_25 ( & V_7 -> V_53 ) ;
F_45 ( & V_47 -> V_79 ) ;
F_46 ( & V_65 -> V_71 ) ;
F_14 ( & V_59 -> V_71 , & V_47 -> V_80 ) ;
F_47 ( & V_47 -> V_79 ) ;
F_48 ( & V_65 -> V_52 , F_27 ) ;
F_49 ( & V_65 -> V_58 ) ;
F_30 ( V_7 , V_59 , true ) ;
F_50 ( V_65 , V_81 ) ;
return 0 ;
}
F_42 ( V_59 -> V_3 , V_47 ) ;
F_42 ( V_59 -> V_63 , V_64 ) ;
F_44 ( & V_59 -> V_77 , & V_7 -> V_78 ) ;
F_25 ( & V_7 -> V_53 ) ;
F_45 ( & V_47 -> V_79 ) ;
F_14 ( & V_59 -> V_71 , & V_47 -> V_80 ) ;
F_47 ( & V_47 -> V_79 ) ;
F_30 ( V_7 , V_59 , true ) ;
return 0 ;
}
void F_24 (
struct V_3 * V_47 ,
struct V_8 * V_65 ,
struct V_6 * V_7 ,
struct V_48 * V_49 )
{
struct V_82 * V_83 = F_10 ( V_47 -> V_33 ) ;
F_45 ( & V_47 -> V_79 ) ;
F_46 ( & V_65 -> V_71 ) ;
F_47 ( & V_47 -> V_79 ) ;
F_51 ( V_65 ) ;
F_43 ( & V_65 -> V_77 ) ;
F_52 ( V_84 , & V_65 -> V_85 ) ;
F_42 ( V_65 -> V_3 , NULL ) ;
F_42 ( V_65 -> V_63 , NULL ) ;
V_65 -> V_13 = 0 ;
V_65 -> V_72 = 0 ;
V_65 -> V_73 -- ;
F_48 ( & V_65 -> V_52 , F_27 ) ;
F_49 ( & V_65 -> V_58 ) ;
F_50 ( V_65 , V_81 ) ;
F_53 ( V_83 , V_7 ) ;
F_30 ( V_7 , NULL , false ) ;
}
void F_54 ( struct V_3 * V_47 , struct V_48 * V_49 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_21 ( & V_49 -> V_86 ) ;
F_55 (nacl, &tpg->acl_node_list, acl_list) {
F_21 ( & V_7 -> V_53 ) ;
F_18 (deve, &nacl->lun_entry_hlist, link) {
struct V_3 * V_87 = F_22 ( V_9 -> V_3 ,
F_23 ( & V_7 -> V_53 ) ) ;
if ( V_47 != V_87 )
continue;
F_24 ( V_47 , V_9 , V_7 , V_49 ) ;
}
F_25 ( & V_7 -> V_53 ) ;
}
F_25 ( & V_49 -> V_86 ) ;
}
int F_56 ( struct V_3 * V_47 , struct V_82 * V_83 )
{
struct V_3 * V_61 ;
F_45 ( & V_83 -> V_88 ) ;
if ( V_83 -> V_89 == 0x0000ffff ) {
F_57 ( L_10
L_11 ) ;
F_47 ( & V_83 -> V_88 ) ;
return - V_90 ;
}
V_91:
V_47 -> V_51 = V_83 -> V_92 ++ ;
if ( ! V_47 -> V_51 )
goto V_91;
F_55 (tmp, &dev->dev_sep_list, lun_dev_link) {
if ( V_47 -> V_51 == V_61 -> V_51 )
goto V_91;
}
F_47 ( & V_83 -> V_88 ) ;
return 0 ;
}
static void F_58 ( struct V_82 * V_83 )
{
struct V_93 * V_94 , * V_95 ;
F_45 ( & V_83 -> V_96 . V_97 ) ;
F_59 (vpd, vpd_tmp,
&dev->t10_wwn.t10_vpd_list, vpd_list) {
F_46 ( & V_94 -> V_98 ) ;
F_40 ( V_94 ) ;
}
F_47 ( & V_83 -> V_96 . V_97 ) ;
}
static T_4 F_60 ( T_4 V_99 , T_4 V_100 )
{
T_4 V_101 ;
T_4 V_102 ;
V_102 = F_61 ( 1ul , V_103 / V_100 ) ;
V_101 = F_62 ( V_99 , V_102 ) ;
if ( V_99 != V_101 )
F_63 ( L_12 ,
V_99 , V_101 ) ;
return V_101 ;
}
int F_64 (
struct V_48 * V_49 ,
struct V_82 * V_83 ,
struct V_3 * V_47 )
{
int V_104 ;
V_104 = F_65 ( V_49 , V_47 ,
V_56 , V_83 ) ;
if ( V_104 < 0 )
return V_104 ;
F_12 ( L_13
L_14 , V_49 -> V_50 -> V_16 () ,
V_49 -> V_50 -> V_105 ( V_49 ) , V_47 -> V_2 ,
V_49 -> V_50 -> V_16 () , V_83 -> V_106 -> V_107 ) ;
if ( V_49 -> V_50 -> V_108 ( V_49 ) ) {
struct V_6 * V_109 ;
F_21 ( & V_49 -> V_86 ) ;
F_55 (acl, &tpg->acl_node_list, acl_list) {
if ( V_109 -> V_110 &&
( ! V_49 -> V_50 -> V_111 ||
! V_49 -> V_50 -> V_111 ( V_49 ) ) ) {
F_66 ( V_109 , V_49 , V_47 ) ;
}
}
F_25 ( & V_49 -> V_86 ) ;
}
return 0 ;
}
void F_67 (
struct V_48 * V_49 ,
struct V_3 * V_47 )
{
F_12 ( L_15
L_16 , V_49 -> V_50 -> V_16 () ,
V_49 -> V_50 -> V_105 ( V_49 ) , V_47 -> V_2 ,
V_49 -> V_50 -> V_16 () ) ;
F_68 ( V_49 , V_47 ) ;
}
struct V_63 * F_69 (
struct V_48 * V_49 ,
struct V_6 * V_7 ,
T_2 V_54 ,
int * V_45 )
{
struct V_63 * V_112 ;
if ( strlen ( V_7 -> V_75 ) >= V_113 ) {
F_5 ( L_17 ,
V_49 -> V_50 -> V_16 () ) ;
* V_45 = - V_114 ;
return NULL ;
}
V_112 = F_33 ( sizeof( struct V_63 ) , V_66 ) ;
if ( ! V_112 ) {
F_5 ( L_18 ) ;
* V_45 = - V_67 ;
return NULL ;
}
V_112 -> V_54 = V_54 ;
V_112 -> V_115 = V_7 ;
snprintf ( V_112 -> V_75 , V_113 , L_19 ,
V_7 -> V_75 ) ;
return V_112 ;
}
int F_70 (
struct V_48 * V_49 ,
struct V_63 * V_112 ,
struct V_3 * V_47 ,
T_4 V_55 )
{
struct V_6 * V_7 = V_112 -> V_115 ;
struct V_82 * V_83 = F_10 ( V_47 -> V_33 ) ;
if ( ! V_7 )
return - V_76 ;
if ( ( V_47 -> V_55 & V_14 ) &&
( V_55 & V_56 ) )
V_55 = V_14 ;
V_112 -> V_3 = V_47 ;
if ( F_32 ( V_47 , V_112 , V_112 -> V_54 ,
V_55 , V_7 , V_49 ) < 0 )
return - V_76 ;
F_12 ( L_20
L_21 , V_49 -> V_50 -> V_16 () ,
V_49 -> V_50 -> V_105 ( V_49 ) , V_47 -> V_2 , V_112 -> V_54 ,
( V_55 & V_56 ) ? L_22 : L_23 ,
V_112 -> V_75 ) ;
F_71 ( V_83 , V_49 , V_47 , V_7 ,
V_112 -> V_54 ) ;
return 0 ;
}
int F_72 (
struct V_3 * V_47 ,
struct V_63 * V_112 )
{
struct V_48 * V_49 = V_47 -> V_116 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = V_112 -> V_115 ;
if ( ! V_7 )
return - V_76 ;
F_21 ( & V_7 -> V_53 ) ;
V_9 = F_3 ( V_7 , V_112 -> V_54 ) ;
if ( V_9 )
F_24 ( V_47 , V_9 , V_7 , V_49 ) ;
F_25 ( & V_7 -> V_53 ) ;
F_12 ( L_24
L_25 ,
V_49 -> V_50 -> V_16 () ,
V_49 -> V_50 -> V_105 ( V_49 ) , V_47 -> V_2 ,
V_112 -> V_75 , V_112 -> V_54 ) ;
return 0 ;
}
void F_73 (
struct V_48 * V_49 ,
struct V_63 * V_112 )
{
F_12 ( L_26
L_27 , V_49 -> V_50 -> V_16 () ,
V_49 -> V_50 -> V_105 ( V_49 ) ,
V_49 -> V_50 -> V_16 () ,
V_112 -> V_75 , V_112 -> V_54 ) ;
F_40 ( V_112 ) ;
}
static void F_74 ( struct V_82 * V_83 )
{
struct V_96 * V_117 = & V_83 -> V_96 ;
char V_118 [ 17 ] ;
int V_119 , V_120 ;
for ( V_119 = 0 ; V_119 < 8 ; V_119 ++ )
if ( V_117 -> V_121 [ V_119 ] >= 0x20 )
V_118 [ V_119 ] = V_117 -> V_121 [ V_119 ] ;
else
V_118 [ V_119 ] = ' ' ;
V_118 [ V_119 ] = '\0' ;
F_12 ( L_28 , V_118 ) ;
for ( V_119 = 0 ; V_119 < 16 ; V_119 ++ )
if ( V_117 -> V_122 [ V_119 ] >= 0x20 )
V_118 [ V_119 ] = V_117 -> V_122 [ V_119 ] ;
else
V_118 [ V_119 ] = ' ' ;
V_118 [ V_119 ] = '\0' ;
F_12 ( L_29 , V_118 ) ;
for ( V_119 = 0 ; V_119 < 4 ; V_119 ++ )
if ( V_117 -> V_123 [ V_119 ] >= 0x20 )
V_118 [ V_119 ] = V_117 -> V_123 [ V_119 ] ;
else
V_118 [ V_119 ] = ' ' ;
V_118 [ V_119 ] = '\0' ;
F_12 ( L_30 , V_118 ) ;
V_120 = V_83 -> V_124 -> V_125 ( V_83 ) ;
F_12 ( L_31 , F_75 ( V_120 ) ) ;
}
struct V_82 * F_76 ( struct V_106 * V_126 , const char * V_127 )
{
struct V_82 * V_83 ;
struct V_3 * V_128 ;
V_83 = V_126 -> V_129 -> V_130 -> V_131 ( V_126 , V_127 ) ;
if ( ! V_83 )
return NULL ;
V_83 -> V_132 = V_133 ;
V_83 -> V_106 = V_126 ;
V_83 -> V_124 = V_126 -> V_129 -> V_130 ;
V_83 -> V_134 = sizeof( struct V_135 ) ;
V_83 -> V_136 = V_126 -> V_136 ;
F_36 ( & V_83 -> V_137 ) ;
F_36 ( & V_83 -> V_138 ) ;
F_36 ( & V_83 -> V_43 ) ;
F_36 ( & V_83 -> V_139 ) ;
F_36 ( & V_83 -> V_140 ) ;
F_36 ( & V_83 -> V_141 ) ;
F_36 ( & V_83 -> V_142 ) ;
F_35 ( & V_83 -> V_143 ) ;
F_35 ( & V_83 -> V_144 ) ;
F_35 ( & V_83 -> V_145 ) ;
F_35 ( & V_83 -> V_88 ) ;
F_35 ( & V_83 -> V_41 ) ;
F_35 ( & V_83 -> V_146 ) ;
F_77 ( & V_83 -> V_147 , 1 ) ;
F_34 ( & V_83 -> V_148 , 0 ) ;
F_36 ( & V_83 -> V_96 . V_149 ) ;
F_35 ( & V_83 -> V_96 . V_97 ) ;
F_36 ( & V_83 -> V_150 . V_151 ) ;
F_36 ( & V_83 -> V_150 . V_152 ) ;
F_35 ( & V_83 -> V_150 . V_153 ) ;
F_35 ( & V_83 -> V_150 . V_154 ) ;
F_36 ( & V_83 -> V_155 . V_156 ) ;
F_35 ( & V_83 -> V_155 . V_157 ) ;
F_36 ( & V_83 -> V_155 . V_158 ) ;
F_35 ( & V_83 -> V_155 . V_159 ) ;
V_83 -> V_96 . V_160 = V_83 ;
V_83 -> V_155 . V_160 = V_83 ;
V_83 -> V_161 . V_162 = V_83 ;
V_83 -> V_161 . V_163 = V_164 ;
V_83 -> V_161 . V_165 = 1 ;
V_83 -> V_161 . V_166 = 1 ;
V_83 -> V_161 . V_167 = 1 ;
V_83 -> V_161 . V_168 = V_169 ;
V_83 -> V_161 . V_170 = V_171 ;
V_83 -> V_161 . V_172 = V_173 ;
V_83 -> V_161 . V_174 = V_175 ;
V_83 -> V_161 . V_176 = V_177 ;
V_83 -> V_161 . V_178 = V_179 ;
V_83 -> V_161 . V_180 = V_181 ;
V_83 -> V_161 . V_182 = V_183 ;
V_83 -> V_161 . V_184 = V_185 ;
V_83 -> V_161 . V_186 = V_187 ;
V_83 -> V_161 . V_188 = V_189 ;
V_83 -> V_161 . V_190 = V_191 ;
V_83 -> V_161 . V_192 = V_193 ;
V_83 -> V_161 . V_194 =
V_195 ;
V_83 -> V_161 . V_196 = V_197 ;
V_83 -> V_161 . V_198 =
V_199 ;
V_83 -> V_161 . V_200 = V_201 ;
V_128 = & V_83 -> V_128 ;
F_42 ( V_128 -> V_33 , V_83 ) ;
F_38 ( & V_128 -> V_202 ) ;
F_36 ( & V_128 -> V_80 ) ;
F_36 ( & V_128 -> V_203 ) ;
F_78 ( & V_128 -> V_204 ) ;
V_128 -> V_116 = & V_205 ;
return V_83 ;
}
int F_79 ( struct V_82 * V_83 )
{
struct V_106 * V_126 = V_83 -> V_106 ;
int V_45 ;
if ( V_83 -> V_206 & V_207 ) {
F_5 ( L_32
L_33 ) ;
return - V_208 ;
}
V_45 = V_83 -> V_124 -> V_209 ( V_83 ) ;
if ( V_45 )
goto V_210;
V_83 -> V_161 . V_100 = V_83 -> V_161 . V_211 ;
V_83 -> V_161 . V_212 = V_83 -> V_161 . V_213 ;
V_83 -> V_161 . V_214 =
F_60 ( V_83 -> V_161 . V_214 ,
V_83 -> V_161 . V_211 ) ;
V_83 -> V_161 . V_215 = V_83 -> V_161 . V_214 ;
V_83 -> V_216 = F_80 ( V_217 ) ;
V_83 -> V_72 = F_39 () ;
V_45 = F_81 ( V_83 ) ;
if ( V_45 )
goto V_210;
V_83 -> V_218 = F_82 ( L_34 , V_219 | V_220 , 1 ,
V_83 -> V_124 -> V_127 ) ;
if ( ! V_83 -> V_218 ) {
F_5 ( L_35 ,
V_83 -> V_124 -> V_127 ) ;
V_45 = - V_67 ;
goto V_221;
}
F_83 ( & V_83 -> V_222 , V_223 ) ;
if ( ! ( V_83 -> V_124 -> V_224 & V_225 ) ) {
strncpy ( & V_83 -> V_96 . V_121 [ 0 ] , L_36 , 8 ) ;
strncpy ( & V_83 -> V_96 . V_122 [ 0 ] ,
V_83 -> V_124 -> V_226 , 16 ) ;
strncpy ( & V_83 -> V_96 . V_123 [ 0 ] ,
V_83 -> V_124 -> V_227 , 4 ) ;
}
F_74 ( V_83 ) ;
F_45 ( & V_126 -> V_228 ) ;
V_126 -> V_229 ++ ;
F_47 ( & V_126 -> V_228 ) ;
F_21 ( & V_230 ) ;
F_14 ( & V_83 -> V_142 , & V_231 ) ;
F_25 ( & V_230 ) ;
V_83 -> V_206 |= V_207 ;
return 0 ;
V_221:
F_84 ( V_83 ) ;
V_210:
F_58 ( V_83 ) ;
return V_45 ;
}
void F_85 ( struct V_82 * V_83 )
{
struct V_106 * V_126 = V_83 -> V_106 ;
F_86 ( ! F_87 ( & V_83 -> V_138 ) ) ;
if ( V_83 -> V_206 & V_207 ) {
F_88 ( V_83 -> V_218 ) ;
F_21 ( & V_230 ) ;
F_46 ( & V_83 -> V_142 ) ;
F_25 ( & V_230 ) ;
F_45 ( & V_126 -> V_228 ) ;
V_126 -> V_229 -- ;
F_47 ( & V_126 -> V_228 ) ;
}
F_84 ( V_83 ) ;
F_89 ( V_83 , NULL , 0 , 0 ) ;
F_90 ( V_83 ) ;
F_58 ( V_83 ) ;
if ( V_83 -> V_124 -> V_232 )
V_83 -> V_124 -> V_232 ( V_83 ) ;
V_83 -> V_124 -> V_233 ( V_83 ) ;
}
int F_91 ( void )
{
struct V_106 * V_126 ;
struct V_82 * V_83 ;
char V_118 [] = L_37 ;
int V_45 ;
V_126 = F_92 ( L_38 , 0 , V_234 ) ;
if ( F_93 ( V_126 ) )
return F_94 ( V_126 ) ;
V_83 = F_76 ( V_126 , L_39 ) ;
if ( ! V_83 ) {
V_45 = - V_67 ;
goto V_235;
}
V_126 -> V_129 -> V_130 -> V_236 ( V_83 , V_118 , sizeof( V_118 ) ) ;
V_45 = F_79 ( V_83 ) ;
if ( V_45 )
goto V_237;
V_238 = V_126 ;
V_239 = V_83 ;
return 0 ;
V_237:
F_85 ( V_83 ) ;
V_235:
F_95 ( V_126 ) ;
return V_45 ;
}
void F_96 ( void )
{
struct V_106 * V_126 = V_238 ;
if ( ! V_126 )
return;
if ( V_239 )
F_85 ( V_239 ) ;
F_95 ( V_126 ) ;
}
T_1
F_97 ( struct V_1 * V_44 ,
T_1 (* F_98)( struct V_1 * V_44 ) )
{
unsigned char * V_240 = V_44 -> V_241 ;
switch ( V_240 [ 0 ] ) {
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
break;
default:
V_240 [ 1 ] &= 0x1f ;
break;
}
if ( V_240 [ 0 ] == V_251 ) {
V_44 -> V_252 = V_253 ;
return V_254 ;
}
switch ( V_240 [ 0 ] ) {
case V_255 :
case V_242 :
case V_243 :
case V_244 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_248 :
case V_249 :
case 0x8e :
case V_260 :
case V_261 :
V_44 -> V_24 |= V_262 ;
break;
case V_263 :
switch ( F_99 ( & V_240 [ 8 ] ) ) {
case V_264 :
case V_265 :
case 0x0c :
case V_266 :
V_44 -> V_24 |= V_262 ;
break;
}
}
V_44 -> V_252 = F_98 ;
return V_254 ;
}
