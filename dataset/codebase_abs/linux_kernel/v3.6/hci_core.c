static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_4 , int V_5 )
{
F_4 ( L_1 , V_2 -> V_6 , V_4 , V_5 ) ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) && V_2 -> V_9 != V_4 ) {
struct V_10 * V_11 = ( void * ) V_2 -> V_12 -> V_13 ;
T_2 V_14 = F_6 ( V_11 -> V_14 ) ;
struct V_15 * V_16 ;
if ( V_4 != V_17 || V_14 == V_17 )
return;
V_16 = F_7 ( V_2 -> V_12 , V_18 ) ;
if ( V_16 ) {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
return;
}
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_24 = V_5 ;
V_2 -> V_22 = V_25 ;
F_10 ( & V_2 -> V_26 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_27 )
{
F_4 ( L_2 , V_2 -> V_6 , V_27 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_24 = V_27 ;
V_2 -> V_22 = V_28 ;
F_10 ( & V_2 -> V_26 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
void (* F_13)( struct V_1 * V_2 , unsigned long V_29 ) ,
unsigned long V_29 , T_3 V_30 )
{
F_14 ( V_31 , V_32 ) ;
int V_27 = 0 ;
F_4 ( L_3 , V_2 -> V_6 ) ;
V_2 -> V_22 = V_23 ;
F_15 ( & V_2 -> V_26 , & V_31 ) ;
F_16 ( V_33 ) ;
F_13 ( V_2 , V_29 ) ;
F_17 ( V_30 ) ;
F_18 ( & V_2 -> V_26 , & V_31 ) ;
if ( F_19 ( V_32 ) )
return - V_34 ;
switch ( V_2 -> V_22 ) {
case V_25 :
V_27 = - F_20 ( V_2 -> V_24 ) ;
break;
case V_28 :
V_27 = - V_2 -> V_24 ;
break;
default:
V_27 = - V_35 ;
break;
}
V_2 -> V_22 = V_2 -> V_24 = 0 ;
F_4 ( L_4 , V_2 -> V_6 , V_27 ) ;
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 ,
void (* F_13)( struct V_1 * V_2 , unsigned long V_29 ) ,
unsigned long V_29 , T_3 V_30 )
{
int V_36 ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
return - V_38 ;
F_22 ( V_2 ) ;
V_36 = F_12 ( V_2 , F_13 , V_29 , V_30 ) ;
F_23 ( V_2 ) ;
return V_36 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
F_25 ( V_39 , & V_2 -> V_8 ) ;
F_26 ( V_2 , V_17 , 0 , NULL ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_40 V_41 ;
T_4 V_42 ;
T_5 V_43 ;
V_2 -> V_44 = V_45 ;
F_26 ( V_2 , V_46 , 0 , NULL ) ;
F_26 ( V_2 , V_47 , 0 , NULL ) ;
F_26 ( V_2 , V_48 , 0 , NULL ) ;
F_26 ( V_2 , V_49 , 0 , NULL ) ;
F_26 ( V_2 , V_50 , 0 , NULL ) ;
F_26 ( V_2 , V_51 , 0 , NULL ) ;
F_26 ( V_2 , V_52 , 0 , NULL ) ;
V_43 = V_53 ;
F_26 ( V_2 , V_54 , 1 , & V_43 ) ;
V_42 = F_28 ( 0x7d00 ) ;
F_26 ( V_2 , V_55 , 2 , & V_42 ) ;
F_29 ( & V_41 . V_56 , V_57 ) ;
V_41 . V_58 = 1 ;
F_26 ( V_2 , V_59 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_44 = V_60 ;
F_26 ( V_2 , V_47 , 0 , NULL ) ;
F_26 ( V_2 , V_61 , 0 , NULL ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_15 * V_16 ;
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_62 ) ) ) {
F_33 ( V_16 ) -> V_63 = V_64 ;
V_16 -> V_65 = ( void * ) V_2 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
F_35 ( & V_2 -> V_62 ) ;
if ( ! F_5 ( V_66 , & V_2 -> V_67 ) )
F_24 ( V_2 , 0 ) ;
switch ( V_2 -> V_68 ) {
case V_69 :
F_27 ( V_2 ) ;
break;
case V_70 :
F_30 ( V_2 ) ;
break;
default:
F_36 ( L_6 , V_2 -> V_68 ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
F_26 ( V_2 , V_71 , 0 , NULL ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_72 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_72 ) ;
F_26 ( V_2 , V_73 , 1 , & V_72 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_74 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_74 ) ;
F_26 ( V_2 , V_75 , 1 , & V_74 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_76 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_76 ) ;
F_26 ( V_2 , V_77 , 1 , & V_76 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_78 = F_42 ( V_29 ) ;
F_4 ( L_8 , V_2 -> V_6 , V_78 ) ;
F_26 ( V_2 , V_79 , 2 , & V_78 ) ;
}
struct V_1 * F_43 ( int V_80 )
{
struct V_1 * V_2 = NULL , * V_81 ;
F_4 ( L_9 , V_80 ) ;
if ( V_80 < 0 )
return NULL ;
F_44 ( & V_82 ) ;
F_45 (d, &hci_dev_list, list) {
if ( V_81 -> V_83 == V_80 ) {
V_2 = F_46 ( V_81 ) ;
break;
}
}
F_47 ( & V_82 ) ;
return V_2 ;
}
bool F_48 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = & V_2 -> V_86 ;
switch ( V_85 -> V_87 ) {
case V_88 :
case V_89 :
return true ;
default:
return false ;
}
}
void F_49 ( struct V_1 * V_2 , int V_87 )
{
F_4 ( L_10 , V_2 -> V_6 , V_2 -> V_86 . V_87 , V_87 ) ;
if ( V_2 -> V_86 . V_87 == V_87 )
return;
switch ( V_87 ) {
case V_90 :
if ( V_2 -> V_86 . V_87 != V_91 )
F_50 ( V_2 , 0 ) ;
break;
case V_91 :
break;
case V_88 :
F_50 ( V_2 , 1 ) ;
break;
case V_89 :
break;
case V_92 :
break;
}
V_2 -> V_86 . V_87 = V_87 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_95 , * V_96 ;
F_52 (p, n, &cache->all, all) {
F_53 ( & V_95 -> V_97 ) ;
F_54 ( V_95 ) ;
}
F_55 ( & V_93 -> V_98 ) ;
F_55 ( & V_93 -> V_99 ) ;
}
struct V_94 * F_56 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_11 , V_93 , F_57 ( V_56 ) ) ;
F_45 (e, &cache->all, all) {
if ( ! F_58 ( & V_100 -> V_13 . V_56 , V_56 ) )
return V_100 ;
}
return NULL ;
}
struct V_94 * F_59 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_11 , V_93 , F_57 ( V_56 ) ) ;
F_45 (e, &cache->unknown, list) {
if ( ! F_58 ( & V_100 -> V_13 . V_56 , V_56 ) )
return V_100 ;
}
return NULL ;
}
struct V_94 * F_60 ( struct V_1 * V_2 ,
T_6 * V_56 ,
int V_87 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_12 , V_93 , F_57 ( V_56 ) , V_87 ) ;
F_45 (e, &cache->resolve, list) {
if ( ! F_58 ( V_56 , V_57 ) && V_100 -> V_101 == V_87 )
return V_100 ;
if ( ! F_58 ( & V_100 -> V_13 . V_56 , V_56 ) )
return V_100 ;
}
return NULL ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_94 * V_102 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_103 * V_104 = & V_93 -> V_99 ;
struct V_94 * V_95 ;
F_53 ( & V_102 -> V_105 ) ;
F_45 (p, &cache->resolve, list) {
if ( V_95 -> V_101 != V_106 &&
abs ( V_95 -> V_13 . V_107 ) >= abs ( V_102 -> V_13 . V_107 ) )
break;
V_104 = & V_95 -> V_105 ;
}
F_62 ( & V_102 -> V_105 , V_104 ) ;
}
bool F_63 ( struct V_1 * V_2 , struct V_108 * V_13 ,
bool V_109 , bool * V_110 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_102 ;
F_4 ( L_11 , V_93 , F_57 ( & V_13 -> V_56 ) ) ;
if ( V_110 )
* V_110 = V_13 -> V_111 ;
V_102 = F_56 ( V_2 , & V_13 -> V_56 ) ;
if ( V_102 ) {
if ( V_102 -> V_13 . V_111 && V_110 )
* V_110 = true ;
if ( V_102 -> V_101 == V_112 &&
V_13 -> V_107 != V_102 -> V_13 . V_107 ) {
V_102 -> V_13 . V_107 = V_13 -> V_107 ;
F_61 ( V_2 , V_102 ) ;
}
goto V_113;
}
V_102 = F_64 ( sizeof( struct V_94 ) , V_18 ) ;
if ( ! V_102 )
return false ;
F_62 ( & V_102 -> V_97 , & V_93 -> V_97 ) ;
if ( V_109 ) {
V_102 -> V_101 = V_114 ;
} else {
V_102 -> V_101 = V_115 ;
F_62 ( & V_102 -> V_105 , & V_93 -> V_98 ) ;
}
V_113:
if ( V_109 && V_102 -> V_101 != V_114 &&
V_102 -> V_101 != V_106 ) {
V_102 -> V_101 = V_114 ;
F_53 ( & V_102 -> V_105 ) ;
}
memcpy ( & V_102 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_102 -> V_116 = V_117 ;
V_93 -> V_116 = V_117 ;
if ( V_102 -> V_101 == V_115 )
return false ;
return true ;
}
static int F_65 ( struct V_1 * V_2 , int V_118 , T_5 * V_119 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_120 * V_121 = (struct V_120 * ) V_119 ;
struct V_94 * V_100 ;
int V_122 = 0 ;
F_45 (e, &cache->all, all) {
struct V_108 * V_13 = & V_100 -> V_13 ;
if ( V_122 >= V_118 )
break;
F_29 ( & V_121 -> V_56 , & V_13 -> V_56 ) ;
V_121 -> V_123 = V_13 -> V_123 ;
V_121 -> V_124 = V_13 -> V_124 ;
V_121 -> V_125 = V_13 -> V_125 ;
memcpy ( V_121 -> V_126 , V_13 -> V_126 , 3 ) ;
V_121 -> V_127 = V_13 -> V_127 ;
V_121 ++ ;
V_122 ++ ;
}
F_4 ( L_13 , V_93 , V_122 ) ;
return V_122 ;
}
static void F_66 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_128 * V_129 = (struct V_128 * ) V_29 ;
struct V_130 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_131 , & V_2 -> V_8 ) )
return;
memcpy ( & V_41 . V_132 , & V_129 -> V_132 , 3 ) ;
V_41 . V_133 = V_129 -> V_133 ;
V_41 . V_134 = V_129 -> V_134 ;
F_26 ( V_2 , V_135 , sizeof( V_41 ) , & V_41 ) ;
}
int F_67 ( void T_7 * V_136 )
{
T_5 T_7 * V_137 = V_136 ;
struct V_128 V_129 ;
struct V_1 * V_2 ;
int V_27 = 0 , V_138 = 0 , V_139 ;
long V_140 ;
T_5 * V_119 ;
if ( F_68 ( & V_129 , V_137 , sizeof( V_129 ) ) )
return - V_141 ;
V_2 = F_43 ( V_129 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
F_69 ( V_2 ) ;
if ( F_70 ( V_2 ) > V_144 ||
F_71 ( V_2 ) || V_129 . V_8 & V_145 ) {
F_51 ( V_2 ) ;
V_138 = 1 ;
}
F_72 ( V_2 ) ;
V_140 = V_129 . V_133 * F_73 ( 2000 ) ;
if ( V_138 ) {
V_27 = F_21 ( V_2 , F_66 , ( unsigned long ) & V_129 , V_140 ) ;
if ( V_27 < 0 )
goto V_146;
}
V_139 = ( V_129 . V_134 == 0 ) ? 255 : V_129 . V_134 ;
V_119 = F_74 ( sizeof( struct V_120 ) * V_139 , V_147 ) ;
if ( ! V_119 ) {
V_27 = - V_148 ;
goto V_146;
}
F_69 ( V_2 ) ;
V_129 . V_134 = F_65 ( V_2 , V_139 , V_119 ) ;
F_72 ( V_2 ) ;
F_4 ( L_14 , V_129 . V_134 ) ;
if ( ! F_75 ( V_137 , & V_129 , sizeof( V_129 ) ) ) {
V_137 += sizeof( V_129 ) ;
if ( F_75 ( V_137 , V_119 , sizeof( struct V_120 ) *
V_129 . V_134 ) )
V_27 = - V_141 ;
} else
V_27 = - V_141 ;
F_54 ( V_119 ) ;
V_146:
F_76 ( V_2 ) ;
return V_27 ;
}
int F_77 ( T_1 V_65 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_65 ) ;
if ( ! V_2 )
return - V_143 ;
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_22 ( V_2 ) ;
if ( F_5 ( V_149 , & V_2 -> V_150 ) ) {
V_36 = - V_143 ;
goto V_146;
}
if ( V_2 -> V_151 && F_78 ( V_2 -> V_151 ) ) {
V_36 = - V_152 ;
goto V_146;
}
if ( F_5 ( V_37 , & V_2 -> V_8 ) ) {
V_36 = - V_153 ;
goto V_146;
}
if ( F_5 ( V_154 , & V_2 -> V_67 ) )
F_25 ( V_155 , & V_2 -> V_8 ) ;
if ( V_2 -> V_68 != V_69 && ! V_156 )
F_25 ( V_155 , & V_2 -> V_8 ) ;
if ( V_2 -> V_157 ( V_2 ) ) {
V_36 = - V_158 ;
goto V_146;
}
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
F_79 ( & V_2 -> V_159 , 1 ) ;
F_25 ( V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_36 = F_12 ( V_2 , F_31 , 0 , V_160 ) ;
if ( F_80 ( V_2 ) )
V_36 = F_12 ( V_2 , F_37 , 0 ,
V_160 ) ;
F_81 ( V_7 , & V_2 -> V_8 ) ;
}
if ( ! V_36 ) {
F_46 ( V_2 ) ;
F_25 ( V_37 , & V_2 -> V_8 ) ;
F_1 ( V_2 , V_161 ) ;
if ( ! F_5 ( V_162 , & V_2 -> V_150 ) ) {
F_69 ( V_2 ) ;
F_82 ( V_2 , 1 ) ;
F_72 ( V_2 ) ;
}
} else {
F_83 ( & V_2 -> V_163 ) ;
F_83 ( & V_2 -> V_21 ) ;
F_83 ( & V_2 -> V_164 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_165 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
if ( V_2 -> V_12 ) {
F_84 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_167 ( V_2 ) ;
V_2 -> V_8 = 0 ;
}
V_146:
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
static int F_85 ( struct V_1 * V_2 )
{
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_86 ( & V_2 -> V_168 ) ;
F_87 ( & V_2 -> V_169 ) ;
F_11 ( V_2 , V_143 ) ;
F_22 ( V_2 ) ;
if ( ! F_88 ( V_37 , & V_2 -> V_8 ) ) {
F_89 ( & V_2 -> V_170 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
F_83 ( & V_2 -> V_163 ) ;
F_83 ( & V_2 -> V_164 ) ;
if ( V_2 -> V_171 > 0 ) {
F_87 ( & V_2 -> V_172 ) ;
V_2 -> V_171 = 0 ;
F_81 ( V_173 , & V_2 -> V_150 ) ;
}
if ( F_88 ( V_174 , & V_2 -> V_150 ) )
F_87 ( & V_2 -> V_175 ) ;
F_90 ( & V_2 -> V_176 ) ;
F_69 ( V_2 ) ;
F_51 ( V_2 ) ;
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
F_1 ( V_2 , V_177 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_79 ( & V_2 -> V_159 , 1 ) ;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) &&
F_5 ( V_66 , & V_2 -> V_67 ) ) {
F_25 ( V_7 , & V_2 -> V_8 ) ;
F_12 ( V_2 , F_24 , 0 , V_178 ) ;
F_81 ( V_7 , & V_2 -> V_8 ) ;
}
F_83 ( & V_2 -> V_21 ) ;
F_35 ( & V_2 -> V_165 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_179 ) ;
if ( V_2 -> V_12 ) {
F_89 ( & V_2 -> V_170 ) ;
F_84 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_167 ( V_2 ) ;
if ( ! F_88 ( V_180 , & V_2 -> V_150 ) ) {
F_69 ( V_2 ) ;
F_82 ( V_2 , 0 ) ;
F_72 ( V_2 ) ;
}
V_2 -> V_8 = 0 ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
memset ( V_2 -> V_126 , 0 , sizeof( V_2 -> V_126 ) ) ;
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
int F_92 ( T_1 V_65 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_43 ( V_65 ) ;
if ( ! V_2 )
return - V_143 ;
if ( F_88 ( V_180 , & V_2 -> V_150 ) )
F_87 ( & V_2 -> V_169 ) ;
V_27 = F_85 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_27 ;
}
int F_93 ( T_1 V_65 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_65 ) ;
if ( ! V_2 )
return - V_143 ;
F_22 ( V_2 ) ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
goto V_146;
F_35 ( & V_2 -> V_165 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_69 ( V_2 ) ;
F_51 ( V_2 ) ;
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
F_79 ( & V_2 -> V_159 , 1 ) ;
V_2 -> V_182 = 0 ; V_2 -> V_183 = 0 ; V_2 -> V_184 = 0 ;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) )
V_36 = F_12 ( V_2 , F_24 , 0 , V_160 ) ;
V_146:
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
int F_94 ( T_1 V_65 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_65 ) ;
if ( ! V_2 )
return - V_143 ;
memset ( & V_2 -> V_185 , 0 , sizeof( struct V_186 ) ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
int F_95 ( unsigned int V_4 , void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_187 V_188 ;
int V_27 = 0 ;
if ( F_68 ( & V_188 , V_136 , sizeof( V_188 ) ) )
return - V_141 ;
V_2 = F_43 ( V_188 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
switch ( V_4 ) {
case V_189 :
V_27 = F_21 ( V_2 , F_39 , V_188 . V_190 ,
V_160 ) ;
break;
case V_191 :
if ( ! F_96 ( V_2 ) ) {
V_27 = - V_192 ;
break;
}
if ( ! F_5 ( V_193 , & V_2 -> V_8 ) ) {
V_27 = F_21 ( V_2 , F_39 , V_188 . V_190 ,
V_160 ) ;
if ( V_27 )
break;
}
V_27 = F_21 ( V_2 , F_40 , V_188 . V_190 ,
V_160 ) ;
break;
case V_194 :
V_27 = F_21 ( V_2 , F_38 , V_188 . V_190 ,
V_160 ) ;
break;
case V_195 :
V_27 = F_21 ( V_2 , F_41 , V_188 . V_190 ,
V_160 ) ;
break;
case V_196 :
V_2 -> V_197 = ( ( T_1 ) V_188 . V_190 ) &
( V_198 | V_199 ) ;
break;
case V_200 :
V_2 -> V_63 = ( T_1 ) V_188 . V_190 ;
break;
case V_201 :
V_2 -> V_202 = * ( ( T_1 * ) & V_188 . V_190 + 1 ) ;
V_2 -> V_203 = * ( ( T_1 * ) & V_188 . V_190 + 0 ) ;
break;
case V_204 :
V_2 -> V_205 = * ( ( T_1 * ) & V_188 . V_190 + 1 ) ;
V_2 -> V_206 = * ( ( T_1 * ) & V_188 . V_190 + 0 ) ;
break;
default:
V_27 = - V_207 ;
break;
}
F_76 ( V_2 ) ;
return V_27 ;
}
int F_97 ( void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_208 * V_209 ;
struct V_187 * V_188 ;
int V_96 = 0 , V_210 , V_27 ;
T_1 V_211 ;
if ( F_98 ( V_211 , ( T_1 T_7 * ) V_136 ) )
return - V_141 ;
if ( ! V_211 || V_211 > ( V_212 * 2 ) / sizeof( * V_188 ) )
return - V_207 ;
V_210 = sizeof( * V_209 ) + V_211 * sizeof( * V_188 ) ;
V_209 = F_64 ( V_210 , V_147 ) ;
if ( ! V_209 )
return - V_148 ;
V_188 = V_209 -> V_213 ;
F_44 ( & V_82 ) ;
F_45 (hdev, &hci_dev_list, list) {
if ( F_88 ( V_180 , & V_2 -> V_150 ) )
F_87 ( & V_2 -> V_169 ) ;
if ( ! F_5 ( V_214 , & V_2 -> V_150 ) )
F_25 ( V_215 , & V_2 -> V_150 ) ;
( V_188 + V_96 ) -> V_142 = V_2 -> V_83 ;
( V_188 + V_96 ) -> V_190 = V_2 -> V_8 ;
if ( ++ V_96 >= V_211 )
break;
}
F_47 ( & V_82 ) ;
V_209 -> V_211 = V_96 ;
V_210 = sizeof( * V_209 ) + V_96 * sizeof( * V_188 ) ;
V_27 = F_75 ( V_136 , V_209 , V_210 ) ;
F_54 ( V_209 ) ;
return V_27 ? - V_141 : 0 ;
}
int F_99 ( void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_216 V_217 ;
int V_27 = 0 ;
if ( F_68 ( & V_217 , V_136 , sizeof( V_217 ) ) )
return - V_141 ;
V_2 = F_43 ( V_217 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
if ( F_88 ( V_180 , & V_2 -> V_150 ) )
F_90 ( & V_2 -> V_169 ) ;
if ( ! F_5 ( V_214 , & V_2 -> V_150 ) )
F_25 ( V_215 , & V_2 -> V_150 ) ;
strcpy ( V_217 . V_6 , V_2 -> V_6 ) ;
V_217 . V_56 = V_2 -> V_56 ;
V_217 . type = ( V_2 -> V_218 & 0x0f ) | ( V_2 -> V_68 << 4 ) ;
V_217 . V_8 = V_2 -> V_8 ;
V_217 . V_63 = V_2 -> V_63 ;
V_217 . V_202 = V_2 -> V_202 ;
V_217 . V_203 = V_2 -> V_203 ;
V_217 . V_205 = V_2 -> V_205 ;
V_217 . V_206 = V_2 -> V_206 ;
V_217 . V_219 = V_2 -> V_219 ;
V_217 . V_197 = V_2 -> V_197 ;
memcpy ( & V_217 . V_185 , & V_2 -> V_185 , sizeof( V_217 . V_185 ) ) ;
memcpy ( & V_217 . V_220 , & V_2 -> V_220 , sizeof( V_217 . V_220 ) ) ;
if ( F_75 ( V_136 , & V_217 , sizeof( V_217 ) ) )
V_27 = - V_141 ;
F_76 ( V_2 ) ;
return V_27 ;
}
static int F_100 ( void * V_13 , bool V_221 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( L_16 , V_2 , V_2 -> V_6 , V_221 ) ;
if ( ! V_221 )
return 0 ;
F_85 ( V_2 ) ;
return 0 ;
}
static void F_101 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 , V_224 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_77 ( V_2 -> V_83 ) < 0 )
return;
if ( F_5 ( V_180 , & V_2 -> V_150 ) )
F_103 ( & V_2 -> V_169 , V_225 ) ;
if ( F_88 ( V_162 , & V_2 -> V_150 ) )
F_104 ( V_2 ) ;
}
static void F_105 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 ,
V_169 . V_223 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_85 ( V_2 ) ;
}
static void F_106 ( struct V_222 * V_223 )
{
struct V_1 * V_2 ;
T_8 V_72 = V_226 ;
V_2 = F_102 ( V_223 , struct V_1 , V_172 . V_223 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_69 ( V_2 ) ;
F_26 ( V_2 , V_73 , sizeof( V_72 ) , & V_72 ) ;
V_2 -> V_171 = 0 ;
F_72 ( V_2 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_108 (p, n, &hdev->uuids) {
struct V_227 * V_228 ;
V_228 = F_109 ( V_95 , struct V_227 , V_105 ) ;
F_53 ( V_95 ) ;
F_54 ( V_228 ) ;
}
return 0 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_108 (p, n, &hdev->link_keys) {
struct V_229 * V_230 ;
V_230 = F_109 ( V_95 , struct V_229 , V_105 ) ;
F_53 ( V_95 ) ;
F_54 ( V_230 ) ;
}
return 0 ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_231 * V_232 , * V_233 ;
F_52 (k, tmp, &hdev->long_term_keys, list) {
F_53 ( & V_232 -> V_105 ) ;
F_54 ( V_232 ) ;
}
return 0 ;
}
struct V_229 * F_112 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_229 * V_232 ;
F_45 (k, &hdev->link_keys, list)
if ( F_58 ( V_56 , & V_232 -> V_56 ) == 0 )
return V_232 ;
return NULL ;
}
static bool F_113 ( struct V_1 * V_2 , struct V_234 * V_235 ,
T_8 V_236 , T_8 V_237 )
{
if ( V_236 < 0x03 )
return true ;
if ( V_236 == V_238 )
return false ;
if ( V_236 == V_239 && V_237 == 0xff )
return false ;
if ( ! V_235 )
return true ;
if ( V_235 -> V_240 > 0x01 && V_235 -> V_241 > 0x01 )
return true ;
if ( V_235 -> V_240 == 0x02 || V_235 -> V_240 == 0x03 )
return true ;
if ( V_235 -> V_241 == 0x02 || V_235 -> V_241 == 0x03 )
return true ;
return false ;
}
struct V_231 * F_114 ( struct V_1 * V_2 , T_4 V_242 , T_8 rand [ 8 ] )
{
struct V_231 * V_232 ;
F_45 (k, &hdev->long_term_keys, list) {
if ( V_232 -> V_242 != V_242 ||
memcmp ( rand , V_232 -> rand , sizeof( V_232 -> rand ) ) )
continue;
return V_232 ;
}
return NULL ;
}
struct V_231 * F_115 ( struct V_1 * V_2 , T_6 * V_56 ,
T_8 V_243 )
{
struct V_231 * V_232 ;
F_45 (k, &hdev->long_term_keys, list)
if ( V_243 == V_232 -> V_244 &&
F_58 ( V_56 , & V_232 -> V_56 ) == 0 )
return V_232 ;
return NULL ;
}
int F_116 ( struct V_1 * V_2 , struct V_234 * V_235 , int V_245 ,
T_6 * V_56 , T_8 * V_246 , T_8 type , T_8 V_247 )
{
struct V_229 * V_230 , * V_248 ;
T_8 V_237 ;
bool V_249 ;
V_248 = F_112 ( V_2 , V_56 ) ;
if ( V_248 ) {
V_237 = V_248 -> type ;
V_230 = V_248 ;
} else {
V_237 = V_235 ? V_235 -> V_236 : 0xff ;
V_230 = F_64 ( sizeof( * V_230 ) , V_18 ) ;
if ( ! V_230 )
return - V_148 ;
F_62 ( & V_230 -> V_105 , & V_2 -> V_250 ) ;
}
F_4 ( L_17 , V_2 -> V_6 , F_57 ( V_56 ) , type ) ;
if ( type == V_239 &&
( ! V_235 || V_235 -> V_241 == 0xff ) && V_237 == 0xff ) {
type = V_251 ;
if ( V_235 )
V_235 -> V_236 = type ;
}
F_29 ( & V_230 -> V_56 , V_56 ) ;
memcpy ( V_230 -> V_246 , V_246 , V_252 ) ;
V_230 -> V_247 = V_247 ;
if ( type == V_239 )
V_230 -> type = V_237 ;
else
V_230 -> type = type ;
if ( ! V_245 )
return 0 ;
V_249 = F_113 ( V_2 , V_235 , type , V_237 ) ;
F_117 ( V_2 , V_230 , V_249 ) ;
if ( V_235 )
V_235 -> V_253 = ! V_249 ;
return 0 ;
}
int F_118 ( struct V_1 * V_2 , T_6 * V_56 , T_8 V_243 , T_8 type ,
int V_245 , T_8 V_254 , T_8 V_255 [ 16 ] , T_8 V_256 , T_4
V_242 , T_8 rand [ 8 ] )
{
struct V_231 * V_230 , * V_248 ;
if ( ! ( type & V_257 ) && ! ( type & V_258 ) )
return 0 ;
V_248 = F_115 ( V_2 , V_56 , V_243 ) ;
if ( V_248 )
V_230 = V_248 ;
else {
V_230 = F_64 ( sizeof( * V_230 ) , V_18 ) ;
if ( ! V_230 )
return - V_148 ;
F_62 ( & V_230 -> V_105 , & V_2 -> V_259 ) ;
}
F_29 ( & V_230 -> V_56 , V_56 ) ;
V_230 -> V_244 = V_243 ;
memcpy ( V_230 -> V_246 , V_255 , sizeof( V_230 -> V_246 ) ) ;
V_230 -> V_254 = V_254 ;
V_230 -> V_242 = V_242 ;
V_230 -> V_256 = V_256 ;
V_230 -> type = type ;
memcpy ( V_230 -> rand , rand , sizeof( V_230 -> rand ) ) ;
if ( ! V_245 )
return 0 ;
if ( type & V_258 )
F_119 ( V_2 , V_230 , 1 ) ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_229 * V_230 ;
V_230 = F_112 ( V_2 , V_56 ) ;
if ( ! V_230 )
return - V_260 ;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_230 -> V_105 ) ;
F_54 ( V_230 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_231 * V_232 , * V_233 ;
F_52 (k, tmp, &hdev->long_term_keys, list) {
if ( F_58 ( V_56 , & V_232 -> V_56 ) )
continue;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_232 -> V_105 ) ;
F_54 ( V_232 ) ;
}
return 0 ;
}
static void F_122 ( unsigned long V_136 )
{
struct V_1 * V_2 = ( void * ) V_136 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = ( void * ) V_2 -> V_12 -> V_13 ;
T_2 V_14 = F_6 ( V_11 -> V_14 ) ;
F_36 ( L_19 , V_2 -> V_6 , V_14 ) ;
} else {
F_36 ( L_20 , V_2 -> V_6 ) ;
}
F_79 ( & V_2 -> V_159 , 1 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
struct V_261 * F_123 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_261 * V_13 ;
F_45 (data, &hdev->remote_oob_data, list)
if ( F_58 ( V_56 , & V_13 -> V_56 ) == 0 )
return V_13 ;
return NULL ;
}
int F_124 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_261 * V_13 ;
V_13 = F_123 ( V_2 , V_56 ) ;
if ( ! V_13 )
return - V_260 ;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_13 -> V_105 ) ;
F_54 ( V_13 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 )
{
struct V_261 * V_13 , * V_96 ;
F_52 (data, n, &hdev->remote_oob_data, list) {
F_53 ( & V_13 -> V_105 ) ;
F_54 ( V_13 ) ;
}
return 0 ;
}
int F_126 ( struct V_1 * V_2 , T_6 * V_56 , T_8 * V_262 ,
T_8 * V_263 )
{
struct V_261 * V_13 ;
V_13 = F_123 ( V_2 , V_56 ) ;
if ( ! V_13 ) {
V_13 = F_74 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_148 ;
F_29 ( & V_13 -> V_56 , V_56 ) ;
F_62 ( & V_13 -> V_105 , & V_2 -> V_264 ) ;
}
memcpy ( V_13 -> V_262 , V_262 , sizeof( V_13 -> V_262 ) ) ;
memcpy ( V_13 -> V_263 , V_263 , sizeof( V_13 -> V_263 ) ) ;
F_4 ( L_21 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
return 0 ;
}
struct V_265 * F_127 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_265 * V_266 ;
F_45 (b, &hdev->blacklist, list)
if ( F_58 ( V_56 , & V_266 -> V_56 ) == 0 )
return V_266 ;
return NULL ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_108 (p, n, &hdev->blacklist) {
struct V_265 * V_266 ;
V_266 = F_109 ( V_95 , struct V_265 , V_105 ) ;
F_53 ( V_95 ) ;
F_54 ( V_266 ) ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , T_6 * V_56 , T_8 type )
{
struct V_265 * V_267 ;
if ( F_58 ( V_56 , V_57 ) == 0 )
return - V_268 ;
if ( F_127 ( V_2 , V_56 ) )
return - V_269 ;
V_267 = F_64 ( sizeof( struct V_265 ) , V_147 ) ;
if ( ! V_267 )
return - V_148 ;
F_29 ( & V_267 -> V_56 , V_56 ) ;
F_62 ( & V_267 -> V_105 , & V_2 -> V_270 ) ;
return F_130 ( V_2 , V_56 , type ) ;
}
int F_131 ( struct V_1 * V_2 , T_6 * V_56 , T_8 type )
{
struct V_265 * V_267 ;
if ( F_58 ( V_56 , V_57 ) == 0 )
return F_128 ( V_2 ) ;
V_267 = F_127 ( V_2 , V_56 ) ;
if ( ! V_267 )
return - V_260 ;
F_53 ( & V_267 -> V_105 ) ;
F_54 ( V_267 ) ;
return F_132 ( V_2 , V_56 , type ) ;
}
static void F_133 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_271 * V_42 = (struct V_271 * ) V_29 ;
struct V_272 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . type = V_42 -> type ;
V_41 . V_273 = F_42 ( V_42 -> V_273 ) ;
V_41 . V_274 = F_42 ( V_42 -> V_274 ) ;
F_26 ( V_2 , V_275 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_134 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_276 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_277 = 1 ;
V_41 . V_278 = 1 ;
F_26 ( V_2 , V_279 , sizeof( V_41 ) , & V_41 ) ;
}
static int F_135 ( struct V_1 * V_2 , T_8 type , T_2 V_273 ,
T_2 V_274 , int V_30 )
{
long V_140 = F_73 ( 3000 ) ;
struct V_271 V_42 ;
int V_27 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_280 , & V_2 -> V_150 ) )
return - V_281 ;
V_42 . type = type ;
V_42 . V_273 = V_273 ;
V_42 . V_274 = V_274 ;
F_22 ( V_2 ) ;
V_27 = F_12 ( V_2 , F_133 , ( unsigned long ) & V_42 ,
V_140 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_2 , F_134 , 0 , V_140 ) ;
F_23 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_103 ( & V_2 -> V_176 ,
F_73 ( V_30 ) ) ;
return 0 ;
}
int F_136 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_280 , & V_2 -> V_150 ) )
return - V_153 ;
if ( F_87 ( & V_2 -> V_176 ) ) {
struct V_276 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_279 , sizeof( V_41 ) , & V_41 ) ;
}
return 0 ;
}
static void F_137 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 ,
V_176 . V_223 ) ;
struct V_276 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_279 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_138 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 , V_168 ) ;
struct V_271 * V_42 = & V_2 -> V_271 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_135 ( V_2 , V_42 -> type , V_42 -> V_273 , V_42 -> V_274 ,
V_42 -> V_30 ) ;
}
int F_139 ( struct V_1 * V_2 , T_8 type , T_2 V_273 , T_2 V_274 ,
int V_30 )
{
struct V_271 * V_42 = & V_2 -> V_271 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_140 ( & V_2 -> V_168 ) )
return - V_281 ;
V_42 -> type = type ;
V_42 -> V_273 = V_273 ;
V_42 -> V_274 = V_274 ;
V_42 -> V_30 = V_30 ;
F_9 ( V_282 , & V_2 -> V_168 ) ;
return 0 ;
}
struct V_1 * F_141 ( void )
{
struct V_1 * V_2 ;
V_2 = F_64 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_63 = ( V_283 | V_284 | V_285 ) ;
V_2 -> V_286 = ( V_287 ) ;
V_2 -> V_197 = ( V_199 ) ;
V_2 -> V_288 = 0x03 ;
V_2 -> V_289 = 800 ;
V_2 -> V_290 = 80 ;
F_142 ( & V_2 -> V_291 ) ;
F_142 ( & V_2 -> V_292 ) ;
F_55 ( & V_2 -> V_293 ) ;
F_55 ( & V_2 -> V_270 ) ;
F_55 ( & V_2 -> V_294 ) ;
F_55 ( & V_2 -> V_250 ) ;
F_55 ( & V_2 -> V_259 ) ;
F_55 ( & V_2 -> V_264 ) ;
F_143 ( & V_2 -> V_164 , V_295 ) ;
F_143 ( & V_2 -> V_21 , V_296 ) ;
F_143 ( & V_2 -> V_163 , V_297 ) ;
F_143 ( & V_2 -> V_224 , F_101 ) ;
F_143 ( & V_2 -> V_168 , F_138 ) ;
F_144 ( & V_2 -> V_169 , F_105 ) ;
F_144 ( & V_2 -> V_172 , F_106 ) ;
F_144 ( & V_2 -> V_176 , F_137 ) ;
F_145 ( & V_2 -> V_62 ) ;
F_145 ( & V_2 -> V_165 ) ;
F_145 ( & V_2 -> V_19 ) ;
F_145 ( & V_2 -> V_179 ) ;
F_146 ( & V_2 -> V_26 ) ;
F_147 ( & V_2 -> V_170 , F_122 , ( unsigned long ) V_2 ) ;
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return V_2 ;
}
void F_151 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_62 ) ;
F_152 ( & V_2 -> V_65 ) ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_83 , error ;
if ( ! V_2 -> V_157 || ! V_2 -> V_167 )
return - V_207 ;
switch ( V_2 -> V_68 ) {
case V_69 :
V_83 = F_154 ( & V_298 , 0 , 0 , V_147 ) ;
break;
case V_70 :
V_83 = F_154 ( & V_298 , 1 , 0 , V_147 ) ;
break;
default:
return - V_207 ;
}
if ( V_83 < 0 )
return V_83 ;
sprintf ( V_2 -> V_6 , L_22 , V_83 ) ;
V_2 -> V_83 = V_83 ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_218 ) ;
F_155 ( & V_82 ) ;
F_62 ( & V_2 -> V_105 , & V_299 ) ;
F_156 ( & V_82 ) ;
V_2 -> V_20 = F_157 ( V_2 -> V_6 , V_300 | V_301 |
V_302 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_148 ;
goto V_27;
}
error = F_158 ( V_2 ) ;
if ( error < 0 )
goto V_303;
V_2 -> V_151 = F_159 ( V_2 -> V_6 , & V_2 -> V_65 ,
V_304 , & V_305 ,
V_2 ) ;
if ( V_2 -> V_151 ) {
if ( F_160 ( V_2 -> V_151 ) < 0 ) {
F_161 ( V_2 -> V_151 ) ;
V_2 -> V_151 = NULL ;
}
}
F_25 ( V_162 , & V_2 -> V_150 ) ;
if ( V_2 -> V_68 != V_70 )
F_25 ( V_180 , & V_2 -> V_150 ) ;
F_162 ( & V_2 -> V_224 ) ;
F_1 ( V_2 , V_306 ) ;
F_46 ( V_2 ) ;
return V_83 ;
V_303:
F_163 ( V_2 -> V_20 ) ;
V_27:
F_164 ( & V_298 , V_2 -> V_83 ) ;
F_155 ( & V_82 ) ;
F_53 ( & V_2 -> V_105 ) ;
F_156 ( & V_82 ) ;
return error ;
}
void F_165 ( struct V_1 * V_2 )
{
int V_307 , V_83 ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_218 ) ;
F_25 ( V_149 , & V_2 -> V_150 ) ;
V_83 = V_2 -> V_83 ;
F_155 ( & V_82 ) ;
F_53 ( & V_2 -> V_105 ) ;
F_156 ( & V_82 ) ;
F_85 ( V_2 ) ;
for ( V_307 = 0 ; V_307 < V_308 ; V_307 ++ )
F_84 ( V_2 -> V_309 [ V_307 ] ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_162 , & V_2 -> V_150 ) ) {
F_69 ( V_2 ) ;
F_166 ( V_2 ) ;
F_72 ( V_2 ) ;
}
F_167 ( ! F_168 ( & V_2 -> V_293 ) ) ;
F_1 ( V_2 , V_310 ) ;
if ( V_2 -> V_151 ) {
F_169 ( V_2 -> V_151 ) ;
F_161 ( V_2 -> V_151 ) ;
}
F_170 ( V_2 ) ;
F_163 ( V_2 -> V_20 ) ;
F_69 ( V_2 ) ;
F_128 ( V_2 ) ;
F_107 ( V_2 ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_125 ( V_2 ) ;
F_72 ( V_2 ) ;
F_76 ( V_2 ) ;
F_164 ( & V_298 , V_83 ) ;
}
int F_171 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_311 ) ;
return 0 ;
}
int F_172 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_312 ) ;
return 0 ;
}
int F_173 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_65 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_84 ( V_16 ) ;
return - V_313 ;
}
F_33 ( V_16 ) -> V_314 = 1 ;
F_174 ( V_16 ) ;
F_34 ( & V_2 -> V_165 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_164 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_315 , T_5 V_80 )
{
int V_316 = 0 ;
int V_317 = 0 ;
int V_318 = V_315 ;
struct V_15 * V_16 ;
struct V_319 * V_320 ;
if ( ( type < V_321 || type > V_322 ) ||
V_80 >= V_308 )
return - V_323 ;
V_16 = V_2 -> V_309 [ V_80 ] ;
if ( ! V_16 ) {
switch ( type ) {
case V_321 :
V_316 = V_324 ;
V_317 = V_325 ;
break;
case V_322 :
V_316 = V_326 ;
V_317 = V_327 ;
break;
case V_328 :
V_316 = V_329 ;
V_317 = V_330 ;
break;
}
V_16 = F_176 ( V_316 , V_18 ) ;
if ( ! V_16 )
return - V_148 ;
V_320 = ( void * ) V_16 -> V_331 ;
V_320 -> V_332 = V_317 ;
V_320 -> V_63 = type ;
V_16 -> V_65 = ( void * ) V_2 ;
V_2 -> V_309 [ V_80 ] = V_16 ;
}
while ( V_315 ) {
V_320 = ( void * ) V_16 -> V_331 ;
V_316 = F_177 ( V_333 , V_320 -> V_332 , V_315 ) ;
memcpy ( F_178 ( V_16 , V_316 ) , V_13 , V_316 ) ;
V_315 -= V_316 ;
V_13 += V_316 ;
V_320 -> V_332 -= V_316 ;
V_318 = V_315 ;
switch ( type ) {
case V_322 :
if ( V_16 -> V_316 == V_327 ) {
struct V_334 * V_335 = V_334 ( V_16 ) ;
V_320 -> V_332 = V_335 -> V_336 ;
if ( F_179 ( V_16 ) < V_320 -> V_332 ) {
F_84 ( V_16 ) ;
V_2 -> V_309 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
case V_321 :
if ( V_16 -> V_316 == V_325 ) {
struct V_337 * V_335 = V_337 ( V_16 ) ;
V_320 -> V_332 = F_6 ( V_335 -> V_338 ) ;
if ( F_179 ( V_16 ) < V_320 -> V_332 ) {
F_84 ( V_16 ) ;
V_2 -> V_309 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
case V_328 :
if ( V_16 -> V_316 == V_330 ) {
struct V_339 * V_335 = V_339 ( V_16 ) ;
V_320 -> V_332 = V_335 -> V_338 ;
if ( F_179 ( V_16 ) < V_320 -> V_332 ) {
F_84 ( V_16 ) ;
V_2 -> V_309 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
}
if ( V_320 -> V_332 == 0 ) {
F_33 ( V_16 ) -> V_63 = type ;
F_173 ( V_16 ) ;
V_2 -> V_309 [ V_80 ] = NULL ;
return V_318 ;
}
}
return V_318 ;
}
int F_180 ( struct V_1 * V_2 , int type , void * V_13 , int V_315 )
{
int V_340 = 0 ;
if ( type < V_321 || type > V_322 )
return - V_323 ;
while ( V_315 ) {
V_340 = F_175 ( V_2 , type , V_13 , V_315 , type - 1 ) ;
if ( V_340 < 0 )
return V_340 ;
V_13 += ( V_315 - V_340 ) ;
V_315 = V_340 ;
}
return V_340 ;
}
int F_181 ( struct V_1 * V_2 , void * V_13 , int V_315 )
{
int type ;
int V_340 = 0 ;
while ( V_315 ) {
struct V_15 * V_16 = V_2 -> V_309 [ V_341 ] ;
if ( ! V_16 ) {
struct { char type ; } * V_342 ;
V_342 = V_13 ;
type = V_342 -> type ;
V_13 ++ ;
V_315 -- ;
} else
type = F_33 ( V_16 ) -> V_63 ;
V_340 = F_175 ( V_2 , type , V_13 , V_315 ,
V_341 ) ;
if ( V_340 < 0 )
return V_340 ;
V_13 += ( V_315 - V_340 ) ;
V_315 = V_340 ;
}
return V_340 ;
}
int F_182 ( struct V_343 * V_331 )
{
F_4 ( L_24 , V_331 , V_331 -> V_6 ) ;
F_155 ( & V_344 ) ;
F_62 ( & V_331 -> V_105 , & V_345 ) ;
F_156 ( & V_344 ) ;
return 0 ;
}
int F_183 ( struct V_343 * V_331 )
{
F_4 ( L_24 , V_331 , V_331 -> V_6 ) ;
F_155 ( & V_344 ) ;
F_53 ( & V_331 -> V_105 ) ;
F_156 ( & V_344 ) ;
return 0 ;
}
static int F_184 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_65 ;
if ( ! V_2 ) {
F_84 ( V_16 ) ;
return - V_143 ;
}
F_4 ( L_25 , V_2 -> V_6 , F_33 ( V_16 ) -> V_63 , V_16 -> V_316 ) ;
F_174 ( V_16 ) ;
F_185 ( V_2 , V_16 ) ;
if ( F_186 ( & V_2 -> V_346 ) ) {
F_187 ( V_2 , V_16 ) ;
}
F_188 ( V_16 ) ;
return V_2 -> V_347 ( V_16 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_336 , void * V_42 )
{
int V_316 = V_348 + V_336 ;
struct V_10 * V_349 ;
struct V_15 * V_16 ;
F_4 ( L_26 , V_2 -> V_6 , V_14 , V_336 ) ;
V_16 = F_176 ( V_316 , V_18 ) ;
if ( ! V_16 ) {
F_36 ( L_27 , V_2 -> V_6 ) ;
return - V_148 ;
}
V_349 = (struct V_10 * ) F_178 ( V_16 , V_348 ) ;
V_349 -> V_14 = F_42 ( V_14 ) ;
V_349 -> V_336 = V_336 ;
if ( V_336 )
memcpy ( F_178 ( V_16 , V_336 ) , V_42 , V_336 ) ;
F_4 ( L_28 , V_16 -> V_316 ) ;
F_33 ( V_16 ) -> V_63 = V_64 ;
V_16 -> V_65 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_14 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_189 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_349 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_349 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_349 -> V_14 != F_42 ( V_14 ) )
return NULL ;
F_4 ( L_29 , V_2 -> V_6 , V_14 ) ;
return V_2 -> V_12 -> V_13 + V_348 ;
}
static void F_190 ( struct V_15 * V_16 , T_1 V_350 , T_1 V_8 )
{
struct V_337 * V_349 ;
int V_316 = V_16 -> V_316 ;
F_191 ( V_16 , V_325 ) ;
F_192 ( V_16 ) ;
V_349 = (struct V_337 * ) F_193 ( V_16 ) ;
V_349 -> V_350 = F_42 ( F_194 ( V_350 , V_8 ) ) ;
V_349 -> V_338 = F_42 ( V_316 ) ;
}
static void F_195 ( struct V_234 * V_235 , struct V_351 * V_352 ,
struct V_15 * V_16 , T_1 V_8 )
{
struct V_1 * V_2 = V_235 -> V_2 ;
struct V_15 * V_105 ;
V_16 -> V_316 = F_196 ( V_16 ) ;
V_16 -> V_353 = 0 ;
F_33 ( V_16 ) -> V_63 = V_321 ;
F_190 ( V_16 , V_235 -> V_350 , V_8 ) ;
V_105 = F_197 ( V_16 ) -> V_354 ;
if ( ! V_105 ) {
F_4 ( L_30 , V_2 -> V_6 , V_16 , V_16 -> V_316 ) ;
F_34 ( V_352 , V_16 ) ;
} else {
F_4 ( L_31 , V_2 -> V_6 , V_16 , V_16 -> V_316 ) ;
F_197 ( V_16 ) -> V_354 = NULL ;
F_198 ( & V_352 -> V_291 ) ;
F_199 ( V_352 , V_16 ) ;
V_8 &= ~ V_355 ;
V_8 |= V_356 ;
do {
V_16 = V_105 ; V_105 = V_105 -> V_357 ;
V_16 -> V_65 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_63 = V_321 ;
F_190 ( V_16 , V_235 -> V_350 , V_8 ) ;
F_4 ( L_31 , V_2 -> V_6 , V_16 , V_16 -> V_316 ) ;
F_199 ( V_352 , V_16 ) ;
} while ( V_105 );
F_200 ( & V_352 -> V_291 ) ;
}
}
void F_201 ( struct V_358 * V_359 , struct V_15 * V_16 , T_1 V_8 )
{
struct V_234 * V_235 = V_359 -> V_235 ;
struct V_1 * V_2 = V_235 -> V_2 ;
F_4 ( L_32 , V_2 -> V_6 , V_359 , V_8 ) ;
V_16 -> V_65 = ( void * ) V_2 ;
F_195 ( V_235 , & V_359 -> V_360 , V_16 , V_8 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_163 ) ;
}
void F_202 ( struct V_234 * V_235 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_235 -> V_2 ;
struct V_339 V_349 ;
F_4 ( L_33 , V_2 -> V_6 , V_16 -> V_316 ) ;
V_349 . V_350 = F_42 ( V_235 -> V_350 ) ;
V_349 . V_338 = V_16 -> V_316 ;
F_191 ( V_16 , V_330 ) ;
F_192 ( V_16 ) ;
memcpy ( F_193 ( V_16 ) , & V_349 , V_330 ) ;
V_16 -> V_65 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_63 = V_328 ;
F_34 ( & V_235 -> V_360 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_163 ) ;
}
static struct V_234 * F_203 ( struct V_1 * V_2 , T_5 type ,
int * V_361 )
{
struct V_362 * V_335 = & V_2 -> V_363 ;
struct V_234 * V_235 = NULL , * V_364 ;
unsigned int V_118 = 0 , V_365 = ~ 0 ;
F_204 () ;
F_205 (c, &h->list, list) {
if ( V_364 -> type != type || F_206 ( & V_364 -> V_360 ) )
continue;
if ( V_364 -> V_87 != V_366 && V_364 -> V_87 != V_367 )
continue;
V_118 ++ ;
if ( V_364 -> V_11 < V_365 ) {
V_365 = V_364 -> V_11 ;
V_235 = V_364 ;
}
if ( F_207 ( V_2 , type ) == V_118 )
break;
}
F_208 () ;
if ( V_235 ) {
int V_368 , V_369 ;
switch ( V_235 -> type ) {
case V_370 :
V_368 = V_2 -> V_182 ;
break;
case V_371 :
case V_372 :
V_368 = V_2 -> V_183 ;
break;
case V_373 :
V_368 = V_2 -> V_374 ? V_2 -> V_184 : V_2 -> V_182 ;
break;
default:
V_368 = 0 ;
F_36 ( L_34 ) ;
}
V_369 = V_368 / V_118 ;
* V_361 = V_369 ? V_369 : 1 ;
} else
* V_361 = 0 ;
F_4 ( L_35 , V_235 , * V_361 ) ;
return V_235 ;
}
static void F_209 ( struct V_1 * V_2 , T_5 type )
{
struct V_362 * V_335 = & V_2 -> V_363 ;
struct V_234 * V_364 ;
F_36 ( L_36 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (c, &h->list, list) {
if ( V_364 -> type == type && V_364 -> V_11 ) {
F_36 ( L_37 ,
V_2 -> V_6 , F_57 ( & V_364 -> V_375 ) ) ;
F_210 ( V_364 , V_376 ) ;
}
}
F_208 () ;
}
static struct V_358 * F_211 ( struct V_1 * V_2 , T_5 type ,
int * V_361 )
{
struct V_362 * V_335 = & V_2 -> V_363 ;
struct V_358 * V_359 = NULL ;
unsigned int V_118 = 0 , V_365 = ~ 0 , V_377 = 0 ;
struct V_234 * V_235 ;
int V_368 , V_369 , V_378 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (conn, &h->list, list) {
struct V_358 * V_233 ;
if ( V_235 -> type != type )
continue;
if ( V_235 -> V_87 != V_366 && V_235 -> V_87 != V_367 )
continue;
V_378 ++ ;
F_205 (tmp, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( F_206 ( & V_233 -> V_360 ) )
continue;
V_16 = F_212 ( & V_233 -> V_360 ) ;
if ( V_16 -> V_379 < V_377 )
continue;
if ( V_16 -> V_379 > V_377 ) {
V_118 = 0 ;
V_365 = ~ 0 ;
V_377 = V_16 -> V_379 ;
}
V_118 ++ ;
if ( V_235 -> V_11 < V_365 ) {
V_365 = V_235 -> V_11 ;
V_359 = V_233 ;
}
}
if ( F_207 ( V_2 , type ) == V_378 )
break;
}
F_208 () ;
if ( ! V_359 )
return NULL ;
switch ( V_359 -> V_235 -> type ) {
case V_370 :
V_368 = V_2 -> V_182 ;
break;
case V_371 :
case V_372 :
V_368 = V_2 -> V_183 ;
break;
case V_373 :
V_368 = V_2 -> V_374 ? V_2 -> V_184 : V_2 -> V_182 ;
break;
default:
V_368 = 0 ;
F_36 ( L_34 ) ;
}
V_369 = V_368 / V_118 ;
* V_361 = V_369 ? V_369 : 1 ;
F_4 ( L_38 , V_359 , * V_361 ) ;
return V_359 ;
}
static void F_213 ( struct V_1 * V_2 , T_5 type )
{
struct V_362 * V_335 = & V_2 -> V_363 ;
struct V_234 * V_235 ;
int V_118 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (conn, &h->list, list) {
struct V_358 * V_359 ;
if ( V_235 -> type != type )
continue;
if ( V_235 -> V_87 != V_366 && V_235 -> V_87 != V_367 )
continue;
V_118 ++ ;
F_205 (chan, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( V_359 -> V_11 ) {
V_359 -> V_11 = 0 ;
continue;
}
if ( F_206 ( & V_359 -> V_360 ) )
continue;
V_16 = F_212 ( & V_359 -> V_360 ) ;
if ( V_16 -> V_379 >= V_380 - 1 )
continue;
V_16 -> V_379 = V_380 - 1 ;
F_4 ( L_39 , V_359 , V_16 ,
V_16 -> V_379 ) ;
}
if ( F_207 ( V_2 , type ) == V_118 )
break;
}
F_208 () ;
}
static inline int F_214 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_215 ( V_16 -> V_316 - V_325 , V_2 -> V_381 ) ;
}
static void F_216 ( struct V_1 * V_2 , unsigned int V_368 )
{
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
if ( ! V_368 && F_217 ( V_117 , V_2 -> V_382 +
V_383 ) )
F_209 ( V_2 , V_370 ) ;
}
}
static void F_218 ( struct V_1 * V_2 )
{
unsigned int V_368 = V_2 -> V_182 ;
struct V_358 * V_359 ;
struct V_15 * V_16 ;
int V_361 ;
F_216 ( V_2 , V_368 ) ;
while ( V_2 -> V_182 &&
( V_359 = F_211 ( V_2 , V_370 , & V_361 ) ) ) {
T_9 V_379 = ( F_212 ( & V_359 -> V_360 ) ) -> V_379 ;
while ( V_361 -- && ( V_16 = F_212 ( & V_359 -> V_360 ) ) ) {
F_4 ( L_40 , V_359 , V_16 ,
V_16 -> V_316 , V_16 -> V_379 ) ;
if ( V_16 -> V_379 < V_379 )
break;
V_16 = F_32 ( & V_359 -> V_360 ) ;
F_219 ( V_359 -> V_235 ,
F_33 ( V_16 ) -> V_384 ) ;
F_184 ( V_16 ) ;
V_2 -> V_382 = V_117 ;
V_2 -> V_182 -- ;
V_359 -> V_11 ++ ;
V_359 -> V_235 -> V_11 ++ ;
}
}
if ( V_368 != V_2 -> V_182 )
F_213 ( V_2 , V_370 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
unsigned int V_368 = V_2 -> V_385 ;
struct V_358 * V_359 ;
struct V_15 * V_16 ;
int V_361 ;
F_216 ( V_2 , V_368 ) ;
while ( V_2 -> V_385 > 0 &&
( V_359 = F_211 ( V_2 , V_370 , & V_361 ) ) ) {
T_9 V_379 = ( F_212 ( & V_359 -> V_360 ) ) -> V_379 ;
while ( V_361 > 0 && ( V_16 = F_212 ( & V_359 -> V_360 ) ) ) {
int V_386 ;
F_4 ( L_40 , V_359 , V_16 ,
V_16 -> V_316 , V_16 -> V_379 ) ;
if ( V_16 -> V_379 < V_379 )
break;
V_16 = F_32 ( & V_359 -> V_360 ) ;
V_386 = F_214 ( V_2 , V_16 ) ;
if ( V_386 > V_2 -> V_385 )
return;
F_219 ( V_359 -> V_235 ,
F_33 ( V_16 ) -> V_384 ) ;
F_184 ( V_16 ) ;
V_2 -> V_382 = V_117 ;
V_2 -> V_385 -= V_386 ;
V_361 -= V_386 ;
V_359 -> V_11 += V_386 ;
V_359 -> V_235 -> V_11 += V_386 ;
}
}
if ( V_368 != V_2 -> V_385 )
F_213 ( V_2 , V_370 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_370 ) )
return;
switch ( V_2 -> V_44 ) {
case V_45 :
F_218 ( V_2 ) ;
break;
case V_60 :
F_220 ( V_2 ) ;
break;
}
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_234 * V_235 ;
struct V_15 * V_16 ;
int V_361 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_371 ) )
return;
while ( V_2 -> V_183 && ( V_235 = F_203 ( V_2 , V_371 , & V_361 ) ) ) {
while ( V_361 -- && ( V_16 = F_32 ( & V_235 -> V_360 ) ) ) {
F_4 ( L_41 , V_16 , V_16 -> V_316 ) ;
F_184 ( V_16 ) ;
V_235 -> V_11 ++ ;
if ( V_235 -> V_11 == ~ 0 )
V_235 -> V_11 = 0 ;
}
}
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_234 * V_235 ;
struct V_15 * V_16 ;
int V_361 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_372 ) )
return;
while ( V_2 -> V_183 && ( V_235 = F_203 ( V_2 , V_372 ,
& V_361 ) ) ) {
while ( V_361 -- && ( V_16 = F_32 ( & V_235 -> V_360 ) ) ) {
F_4 ( L_41 , V_16 , V_16 -> V_316 ) ;
F_184 ( V_16 ) ;
V_235 -> V_11 ++ ;
if ( V_235 -> V_11 == ~ 0 )
V_235 -> V_11 = 0 ;
}
}
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_358 * V_359 ;
struct V_15 * V_16 ;
int V_361 , V_368 , V_233 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_373 ) )
return;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_184 && V_2 -> V_387 &&
F_217 ( V_117 , V_2 -> V_388 + V_389 * 45 ) )
F_209 ( V_2 , V_373 ) ;
}
V_368 = V_2 -> V_387 ? V_2 -> V_184 : V_2 -> V_182 ;
V_233 = V_368 ;
while ( V_368 && ( V_359 = F_211 ( V_2 , V_373 , & V_361 ) ) ) {
T_9 V_379 = ( F_212 ( & V_359 -> V_360 ) ) -> V_379 ;
while ( V_361 -- && ( V_16 = F_212 ( & V_359 -> V_360 ) ) ) {
F_4 ( L_40 , V_359 , V_16 ,
V_16 -> V_316 , V_16 -> V_379 ) ;
if ( V_16 -> V_379 < V_379 )
break;
V_16 = F_32 ( & V_359 -> V_360 ) ;
F_184 ( V_16 ) ;
V_2 -> V_388 = V_117 ;
V_368 -- ;
V_359 -> V_11 ++ ;
V_359 -> V_235 -> V_11 ++ ;
}
}
if ( V_2 -> V_387 )
V_2 -> V_184 = V_368 ;
else
V_2 -> V_182 = V_368 ;
if ( V_368 != V_233 )
F_213 ( V_2 , V_373 ) ;
}
static void V_297 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 , V_163 ) ;
struct V_15 * V_16 ;
F_4 ( L_42 , V_2 -> V_6 , V_2 -> V_182 ,
V_2 -> V_183 , V_2 -> V_184 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_179 ) ) )
F_184 ( V_16 ) ;
}
static void F_225 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_337 * V_349 = ( void * ) V_16 -> V_13 ;
struct V_234 * V_235 ;
T_1 V_350 , V_8 ;
F_226 ( V_16 , V_325 ) ;
V_350 = F_6 ( V_349 -> V_350 ) ;
V_8 = F_227 ( V_350 ) ;
V_350 = F_228 ( V_350 ) ;
F_4 ( L_43 , V_2 -> V_6 , V_16 -> V_316 ,
V_350 , V_8 ) ;
V_2 -> V_185 . V_390 ++ ;
F_69 ( V_2 ) ;
V_235 = F_229 ( V_2 , V_350 ) ;
F_72 ( V_2 ) ;
if ( V_235 ) {
F_219 ( V_235 , V_391 ) ;
F_69 ( V_2 ) ;
if ( F_5 ( V_214 , & V_2 -> V_150 ) &&
! F_230 ( V_392 , & V_235 -> V_8 ) )
F_231 ( V_2 , & V_235 -> V_375 , V_235 -> type ,
V_235 -> V_393 , 0 , NULL , 0 ,
V_235 -> V_126 ) ;
F_72 ( V_2 ) ;
F_232 ( V_235 , V_16 , V_8 ) ;
return;
} else {
F_36 ( L_44 ,
V_2 -> V_6 , V_350 ) ;
}
F_84 ( V_16 ) ;
}
static void F_233 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_339 * V_349 = ( void * ) V_16 -> V_13 ;
struct V_234 * V_235 ;
T_1 V_350 ;
F_226 ( V_16 , V_330 ) ;
V_350 = F_6 ( V_349 -> V_350 ) ;
F_4 ( L_45 , V_2 -> V_6 , V_16 -> V_316 , V_350 ) ;
V_2 -> V_185 . V_394 ++ ;
F_69 ( V_2 ) ;
V_235 = F_229 ( V_2 , V_350 ) ;
F_72 ( V_2 ) ;
if ( V_235 ) {
F_234 ( V_235 , V_16 ) ;
return;
} else {
F_36 ( L_46 ,
V_2 -> V_6 , V_350 ) ;
}
F_84 ( V_16 ) ;
}
static void V_295 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 , V_164 ) ;
struct V_15 * V_16 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_165 ) ) ) {
F_185 ( V_2 , V_16 ) ;
if ( F_186 ( & V_2 -> V_346 ) ) {
F_187 ( V_2 , V_16 ) ;
}
if ( F_5 ( V_155 , & V_2 -> V_8 ) ) {
F_84 ( V_16 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_33 ( V_16 ) -> V_63 ) {
case V_321 :
case V_328 :
F_84 ( V_16 ) ;
continue;
}
}
switch ( F_33 ( V_16 ) -> V_63 ) {
case V_322 :
F_4 ( L_47 , V_2 -> V_6 ) ;
F_235 ( V_2 , V_16 ) ;
break;
case V_321 :
F_4 ( L_48 , V_2 -> V_6 ) ;
F_225 ( V_2 , V_16 ) ;
break;
case V_328 :
F_4 ( L_49 , V_2 -> V_6 ) ;
F_233 ( V_2 , V_16 ) ;
break;
default:
F_84 ( V_16 ) ;
break;
}
}
}
static void V_296 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_102 ( V_223 , struct V_1 , V_21 ) ;
struct V_15 * V_16 ;
F_4 ( L_50 , V_2 -> V_6 ,
F_186 ( & V_2 -> V_159 ) , F_236 ( & V_2 -> V_19 ) ) ;
if ( F_186 ( & V_2 -> V_159 ) ) {
V_16 = F_32 ( & V_2 -> V_19 ) ;
if ( ! V_16 )
return;
F_84 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_7 ( V_16 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_237 ( & V_2 -> V_159 ) ;
F_184 ( V_16 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_238 ( & V_2 -> V_170 ) ;
else
F_239 ( & V_2 -> V_170 ,
V_117 + V_178 ) ;
} else {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_240 ( struct V_1 * V_2 , T_8 V_133 )
{
T_8 V_132 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_130 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_131 , & V_2 -> V_8 ) )
return - V_281 ;
F_51 ( V_2 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( & V_41 . V_132 , V_132 , sizeof( V_41 . V_132 ) ) ;
V_41 . V_133 = V_133 ;
return F_26 ( V_2 , V_135 , sizeof( V_41 ) , & V_41 ) ;
}
int F_241 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_131 , & V_2 -> V_8 ) )
return - V_153 ;
return F_26 ( V_2 , V_395 , 0 , NULL ) ;
}
T_8 F_242 ( T_8 V_244 )
{
switch ( V_244 ) {
case V_396 :
return V_397 ;
default:
return V_398 ;
}
}
