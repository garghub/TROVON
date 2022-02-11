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
F_26 ( V_2 , V_62 , 0 , NULL ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_15 * V_16 ;
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_63 ) ) ) {
F_33 ( V_16 ) -> V_64 = V_65 ;
V_16 -> V_66 = ( void * ) V_2 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
F_35 ( & V_2 -> V_63 ) ;
if ( ! F_5 ( V_67 , & V_2 -> V_68 ) )
F_24 ( V_2 , 0 ) ;
switch ( V_2 -> V_69 ) {
case V_70 :
F_27 ( V_2 ) ;
break;
case V_71 :
F_30 ( V_2 ) ;
break;
default:
F_36 ( L_6 , V_2 -> V_69 ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
F_26 ( V_2 , V_72 , 0 , NULL ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_73 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_73 ) ;
F_26 ( V_2 , V_74 , 1 , & V_73 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_75 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_75 ) ;
F_26 ( V_2 , V_76 , 1 , & V_75 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_77 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_77 ) ;
F_26 ( V_2 , V_78 , 1 , & V_77 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_79 = F_42 ( V_29 ) ;
F_4 ( L_8 , V_2 -> V_6 , V_79 ) ;
F_26 ( V_2 , V_80 , 2 , & V_79 ) ;
}
struct V_1 * F_43 ( int V_81 )
{
struct V_1 * V_2 = NULL , * V_82 ;
F_4 ( L_9 , V_81 ) ;
if ( V_81 < 0 )
return NULL ;
F_44 ( & V_83 ) ;
F_45 (d, &hci_dev_list, list) {
if ( V_82 -> V_84 == V_81 ) {
V_2 = F_46 ( V_82 ) ;
break;
}
}
F_47 ( & V_83 ) ;
return V_2 ;
}
bool F_48 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = & V_2 -> V_87 ;
switch ( V_86 -> V_88 ) {
case V_89 :
case V_90 :
return true ;
default:
return false ;
}
}
void F_49 ( struct V_1 * V_2 , int V_88 )
{
F_4 ( L_10 , V_2 -> V_6 , V_2 -> V_87 . V_88 , V_88 ) ;
if ( V_2 -> V_87 . V_88 == V_88 )
return;
switch ( V_88 ) {
case V_91 :
if ( V_2 -> V_87 . V_88 != V_92 )
F_50 ( V_2 , 0 ) ;
break;
case V_92 :
break;
case V_89 :
F_50 ( V_2 , 1 ) ;
break;
case V_90 :
break;
case V_93 :
break;
}
V_2 -> V_87 . V_88 = V_88 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_95 * V_96 , * V_97 ;
F_52 (p, n, &cache->all, all) {
F_53 ( & V_96 -> V_98 ) ;
F_54 ( V_96 ) ;
}
F_55 ( & V_94 -> V_99 ) ;
F_55 ( & V_94 -> V_100 ) ;
}
struct V_95 * F_56 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_95 * V_101 ;
F_4 ( L_11 , V_94 , F_57 ( V_56 ) ) ;
F_45 (e, &cache->all, all) {
if ( ! F_58 ( & V_101 -> V_13 . V_56 , V_56 ) )
return V_101 ;
}
return NULL ;
}
struct V_95 * F_59 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_95 * V_101 ;
F_4 ( L_11 , V_94 , F_57 ( V_56 ) ) ;
F_45 (e, &cache->unknown, list) {
if ( ! F_58 ( & V_101 -> V_13 . V_56 , V_56 ) )
return V_101 ;
}
return NULL ;
}
struct V_95 * F_60 ( struct V_1 * V_2 ,
T_6 * V_56 ,
int V_88 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_95 * V_101 ;
F_4 ( L_12 , V_94 , F_57 ( V_56 ) , V_88 ) ;
F_45 (e, &cache->resolve, list) {
if ( ! F_58 ( V_56 , V_57 ) && V_101 -> V_102 == V_88 )
return V_101 ;
if ( ! F_58 ( & V_101 -> V_13 . V_56 , V_56 ) )
return V_101 ;
}
return NULL ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_95 * V_103 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_104 * V_105 = & V_94 -> V_100 ;
struct V_95 * V_96 ;
F_53 ( & V_103 -> V_106 ) ;
F_45 (p, &cache->resolve, list) {
if ( V_96 -> V_102 != V_107 &&
abs ( V_96 -> V_13 . V_108 ) >= abs ( V_103 -> V_13 . V_108 ) )
break;
V_105 = & V_96 -> V_106 ;
}
F_62 ( & V_103 -> V_106 , V_105 ) ;
}
bool F_63 ( struct V_1 * V_2 , struct V_109 * V_13 ,
bool V_110 , bool * V_111 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_95 * V_103 ;
F_4 ( L_11 , V_94 , F_57 ( & V_13 -> V_56 ) ) ;
if ( V_111 )
* V_111 = V_13 -> V_112 ;
V_103 = F_56 ( V_2 , & V_13 -> V_56 ) ;
if ( V_103 ) {
if ( V_103 -> V_13 . V_112 && V_111 )
* V_111 = true ;
if ( V_103 -> V_102 == V_113 &&
V_13 -> V_108 != V_103 -> V_13 . V_108 ) {
V_103 -> V_13 . V_108 = V_13 -> V_108 ;
F_61 ( V_2 , V_103 ) ;
}
goto V_114;
}
V_103 = F_64 ( sizeof( struct V_95 ) , V_18 ) ;
if ( ! V_103 )
return false ;
F_62 ( & V_103 -> V_98 , & V_94 -> V_98 ) ;
if ( V_110 ) {
V_103 -> V_102 = V_115 ;
} else {
V_103 -> V_102 = V_116 ;
F_62 ( & V_103 -> V_106 , & V_94 -> V_99 ) ;
}
V_114:
if ( V_110 && V_103 -> V_102 != V_115 &&
V_103 -> V_102 != V_107 ) {
V_103 -> V_102 = V_115 ;
F_53 ( & V_103 -> V_106 ) ;
}
memcpy ( & V_103 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_103 -> V_117 = V_118 ;
V_94 -> V_117 = V_118 ;
if ( V_103 -> V_102 == V_116 )
return false ;
return true ;
}
static int F_65 ( struct V_1 * V_2 , int V_119 , T_5 * V_120 )
{
struct V_85 * V_94 = & V_2 -> V_87 ;
struct V_121 * V_122 = (struct V_121 * ) V_120 ;
struct V_95 * V_101 ;
int V_123 = 0 ;
F_45 (e, &cache->all, all) {
struct V_109 * V_13 = & V_101 -> V_13 ;
if ( V_123 >= V_119 )
break;
F_29 ( & V_122 -> V_56 , & V_13 -> V_56 ) ;
V_122 -> V_124 = V_13 -> V_124 ;
V_122 -> V_125 = V_13 -> V_125 ;
V_122 -> V_126 = V_13 -> V_126 ;
memcpy ( V_122 -> V_127 , V_13 -> V_127 , 3 ) ;
V_122 -> V_128 = V_13 -> V_128 ;
V_122 ++ ;
V_123 ++ ;
}
F_4 ( L_13 , V_94 , V_123 ) ;
return V_123 ;
}
static void F_66 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_129 * V_130 = (struct V_129 * ) V_29 ;
struct V_131 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_132 , & V_2 -> V_8 ) )
return;
memcpy ( & V_41 . V_133 , & V_130 -> V_133 , 3 ) ;
V_41 . V_134 = V_130 -> V_134 ;
V_41 . V_135 = V_130 -> V_135 ;
F_26 ( V_2 , V_136 , sizeof( V_41 ) , & V_41 ) ;
}
int F_67 ( void T_7 * V_137 )
{
T_5 T_7 * V_138 = V_137 ;
struct V_129 V_130 ;
struct V_1 * V_2 ;
int V_27 = 0 , V_139 = 0 , V_140 ;
long V_141 ;
T_5 * V_120 ;
if ( F_68 ( & V_130 , V_138 , sizeof( V_130 ) ) )
return - V_142 ;
V_2 = F_43 ( V_130 . V_143 ) ;
if ( ! V_2 )
return - V_144 ;
F_69 ( V_2 ) ;
if ( F_70 ( V_2 ) > V_145 ||
F_71 ( V_2 ) || V_130 . V_8 & V_146 ) {
F_51 ( V_2 ) ;
V_139 = 1 ;
}
F_72 ( V_2 ) ;
V_141 = V_130 . V_134 * F_73 ( 2000 ) ;
if ( V_139 ) {
V_27 = F_21 ( V_2 , F_66 , ( unsigned long ) & V_130 , V_141 ) ;
if ( V_27 < 0 )
goto V_147;
}
V_140 = ( V_130 . V_135 == 0 ) ? 255 : V_130 . V_135 ;
V_120 = F_74 ( sizeof( struct V_121 ) * V_140 , V_148 ) ;
if ( ! V_120 ) {
V_27 = - V_149 ;
goto V_147;
}
F_69 ( V_2 ) ;
V_130 . V_135 = F_65 ( V_2 , V_140 , V_120 ) ;
F_72 ( V_2 ) ;
F_4 ( L_14 , V_130 . V_135 ) ;
if ( ! F_75 ( V_138 , & V_130 , sizeof( V_130 ) ) ) {
V_138 += sizeof( V_130 ) ;
if ( F_75 ( V_138 , V_120 , sizeof( struct V_121 ) *
V_130 . V_135 ) )
V_27 = - V_142 ;
} else
V_27 = - V_142 ;
F_54 ( V_120 ) ;
V_147:
F_76 ( V_2 ) ;
return V_27 ;
}
int F_77 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_66 ) ;
if ( ! V_2 )
return - V_144 ;
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_22 ( V_2 ) ;
if ( F_5 ( V_150 , & V_2 -> V_151 ) ) {
V_36 = - V_144 ;
goto V_147;
}
if ( V_2 -> V_152 && F_78 ( V_2 -> V_152 ) ) {
V_36 = - V_153 ;
goto V_147;
}
if ( F_5 ( V_37 , & V_2 -> V_8 ) ) {
V_36 = - V_154 ;
goto V_147;
}
if ( F_5 ( V_155 , & V_2 -> V_68 ) )
F_25 ( V_156 , & V_2 -> V_8 ) ;
if ( V_2 -> V_69 != V_70 && ! V_157 )
F_25 ( V_156 , & V_2 -> V_8 ) ;
if ( V_2 -> V_158 ( V_2 ) ) {
V_36 = - V_159 ;
goto V_147;
}
if ( ! F_5 ( V_156 , & V_2 -> V_8 ) ) {
F_79 ( & V_2 -> V_160 , 1 ) ;
F_25 ( V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_36 = F_12 ( V_2 , F_31 , 0 , V_161 ) ;
if ( F_80 ( V_2 ) )
V_36 = F_12 ( V_2 , F_37 , 0 ,
V_161 ) ;
F_81 ( V_7 , & V_2 -> V_8 ) ;
}
if ( ! V_36 ) {
F_46 ( V_2 ) ;
F_25 ( V_37 , & V_2 -> V_8 ) ;
F_1 ( V_2 , V_162 ) ;
if ( ! F_5 ( V_163 , & V_2 -> V_151 ) &&
F_82 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_83 ( V_2 , 1 ) ;
F_72 ( V_2 ) ;
}
} else {
F_84 ( & V_2 -> V_164 ) ;
F_84 ( & V_2 -> V_21 ) ;
F_84 ( & V_2 -> V_165 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_167 )
V_2 -> V_167 ( V_2 ) ;
if ( V_2 -> V_12 ) {
F_85 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_168 ( V_2 ) ;
V_2 -> V_8 = 0 ;
}
V_147:
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_87 ( & V_2 -> V_169 ) ;
F_88 ( & V_2 -> V_170 ) ;
F_11 ( V_2 , V_144 ) ;
F_22 ( V_2 ) ;
if ( ! F_89 ( V_37 , & V_2 -> V_8 ) ) {
F_90 ( & V_2 -> V_171 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
F_84 ( & V_2 -> V_164 ) ;
F_84 ( & V_2 -> V_165 ) ;
if ( V_2 -> V_172 > 0 ) {
F_88 ( & V_2 -> V_173 ) ;
V_2 -> V_172 = 0 ;
F_81 ( V_174 , & V_2 -> V_151 ) ;
}
if ( F_89 ( V_175 , & V_2 -> V_151 ) )
F_88 ( & V_2 -> V_176 ) ;
F_91 ( & V_2 -> V_177 ) ;
F_69 ( V_2 ) ;
F_51 ( V_2 ) ;
F_92 ( V_2 ) ;
F_72 ( V_2 ) ;
F_1 ( V_2 , V_178 ) ;
if ( V_2 -> V_167 )
V_2 -> V_167 ( V_2 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_79 ( & V_2 -> V_160 , 1 ) ;
if ( ! F_5 ( V_156 , & V_2 -> V_8 ) &&
F_5 ( V_67 , & V_2 -> V_68 ) ) {
F_25 ( V_7 , & V_2 -> V_8 ) ;
F_12 ( V_2 , F_24 , 0 , V_179 ) ;
F_81 ( V_7 , & V_2 -> V_8 ) ;
}
F_84 ( & V_2 -> V_21 ) ;
F_35 ( & V_2 -> V_166 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_180 ) ;
if ( V_2 -> V_12 ) {
F_90 ( & V_2 -> V_171 ) ;
F_85 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_168 ( V_2 ) ;
if ( ! F_89 ( V_181 , & V_2 -> V_151 ) &&
F_82 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_83 ( V_2 , 0 ) ;
F_72 ( V_2 ) ;
}
V_2 -> V_8 = 0 ;
memset ( V_2 -> V_182 , 0 , sizeof( V_2 -> V_182 ) ) ;
memset ( V_2 -> V_127 , 0 , sizeof( V_2 -> V_127 ) ) ;
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
int F_93 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_43 ( V_66 ) ;
if ( ! V_2 )
return - V_144 ;
if ( F_89 ( V_181 , & V_2 -> V_151 ) )
F_88 ( & V_2 -> V_170 ) ;
V_27 = F_86 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_27 ;
}
int F_94 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_66 ) ;
if ( ! V_2 )
return - V_144 ;
F_22 ( V_2 ) ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
goto V_147;
F_35 ( & V_2 -> V_166 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_69 ( V_2 ) ;
F_51 ( V_2 ) ;
F_92 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_167 )
V_2 -> V_167 ( V_2 ) ;
F_79 ( & V_2 -> V_160 , 1 ) ;
V_2 -> V_183 = 0 ; V_2 -> V_184 = 0 ; V_2 -> V_185 = 0 ;
if ( ! F_5 ( V_156 , & V_2 -> V_8 ) )
V_36 = F_12 ( V_2 , F_24 , 0 , V_161 ) ;
V_147:
F_23 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
int F_95 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_43 ( V_66 ) ;
if ( ! V_2 )
return - V_144 ;
memset ( & V_2 -> V_186 , 0 , sizeof( struct V_187 ) ) ;
F_76 ( V_2 ) ;
return V_36 ;
}
int F_96 ( unsigned int V_4 , void T_7 * V_137 )
{
struct V_1 * V_2 ;
struct V_188 V_189 ;
int V_27 = 0 ;
if ( F_68 ( & V_189 , V_137 , sizeof( V_189 ) ) )
return - V_142 ;
V_2 = F_43 ( V_189 . V_143 ) ;
if ( ! V_2 )
return - V_144 ;
switch ( V_4 ) {
case V_190 :
V_27 = F_21 ( V_2 , F_39 , V_189 . V_191 ,
V_161 ) ;
break;
case V_192 :
if ( ! F_97 ( V_2 ) ) {
V_27 = - V_193 ;
break;
}
if ( ! F_5 ( V_194 , & V_2 -> V_8 ) ) {
V_27 = F_21 ( V_2 , F_39 , V_189 . V_191 ,
V_161 ) ;
if ( V_27 )
break;
}
V_27 = F_21 ( V_2 , F_40 , V_189 . V_191 ,
V_161 ) ;
break;
case V_195 :
V_27 = F_21 ( V_2 , F_38 , V_189 . V_191 ,
V_161 ) ;
break;
case V_196 :
V_27 = F_21 ( V_2 , F_41 , V_189 . V_191 ,
V_161 ) ;
break;
case V_197 :
V_2 -> V_198 = ( ( T_1 ) V_189 . V_191 ) &
( V_199 | V_200 ) ;
break;
case V_201 :
V_2 -> V_64 = ( T_1 ) V_189 . V_191 ;
break;
case V_202 :
V_2 -> V_203 = * ( ( T_1 * ) & V_189 . V_191 + 1 ) ;
V_2 -> V_204 = * ( ( T_1 * ) & V_189 . V_191 + 0 ) ;
break;
case V_205 :
V_2 -> V_206 = * ( ( T_1 * ) & V_189 . V_191 + 1 ) ;
V_2 -> V_207 = * ( ( T_1 * ) & V_189 . V_191 + 0 ) ;
break;
default:
V_27 = - V_208 ;
break;
}
F_76 ( V_2 ) ;
return V_27 ;
}
int F_98 ( void T_7 * V_137 )
{
struct V_1 * V_2 ;
struct V_209 * V_210 ;
struct V_188 * V_189 ;
int V_97 = 0 , V_211 , V_27 ;
T_1 V_212 ;
if ( F_99 ( V_212 , ( T_1 T_7 * ) V_137 ) )
return - V_142 ;
if ( ! V_212 || V_212 > ( V_213 * 2 ) / sizeof( * V_189 ) )
return - V_208 ;
V_211 = sizeof( * V_210 ) + V_212 * sizeof( * V_189 ) ;
V_210 = F_64 ( V_211 , V_148 ) ;
if ( ! V_210 )
return - V_149 ;
V_189 = V_210 -> V_214 ;
F_44 ( & V_83 ) ;
F_45 (hdev, &hci_dev_list, list) {
if ( F_89 ( V_181 , & V_2 -> V_151 ) )
F_88 ( & V_2 -> V_170 ) ;
if ( ! F_5 ( V_215 , & V_2 -> V_151 ) )
F_25 ( V_216 , & V_2 -> V_151 ) ;
( V_189 + V_97 ) -> V_143 = V_2 -> V_84 ;
( V_189 + V_97 ) -> V_191 = V_2 -> V_8 ;
if ( ++ V_97 >= V_212 )
break;
}
F_47 ( & V_83 ) ;
V_210 -> V_212 = V_97 ;
V_211 = sizeof( * V_210 ) + V_97 * sizeof( * V_189 ) ;
V_27 = F_75 ( V_137 , V_210 , V_211 ) ;
F_54 ( V_210 ) ;
return V_27 ? - V_142 : 0 ;
}
int F_100 ( void T_7 * V_137 )
{
struct V_1 * V_2 ;
struct V_217 V_218 ;
int V_27 = 0 ;
if ( F_68 ( & V_218 , V_137 , sizeof( V_218 ) ) )
return - V_142 ;
V_2 = F_43 ( V_218 . V_143 ) ;
if ( ! V_2 )
return - V_144 ;
if ( F_89 ( V_181 , & V_2 -> V_151 ) )
F_91 ( & V_2 -> V_170 ) ;
if ( ! F_5 ( V_215 , & V_2 -> V_151 ) )
F_25 ( V_216 , & V_2 -> V_151 ) ;
strcpy ( V_218 . V_6 , V_2 -> V_6 ) ;
V_218 . V_56 = V_2 -> V_56 ;
V_218 . type = ( V_2 -> V_219 & 0x0f ) | ( V_2 -> V_69 << 4 ) ;
V_218 . V_8 = V_2 -> V_8 ;
V_218 . V_64 = V_2 -> V_64 ;
V_218 . V_203 = V_2 -> V_203 ;
V_218 . V_204 = V_2 -> V_204 ;
V_218 . V_206 = V_2 -> V_206 ;
V_218 . V_207 = V_2 -> V_207 ;
V_218 . V_220 = V_2 -> V_220 ;
V_218 . V_198 = V_2 -> V_198 ;
memcpy ( & V_218 . V_186 , & V_2 -> V_186 , sizeof( V_218 . V_186 ) ) ;
memcpy ( & V_218 . V_221 , & V_2 -> V_221 , sizeof( V_218 . V_221 ) ) ;
if ( F_75 ( V_137 , & V_218 , sizeof( V_218 ) ) )
V_27 = - V_142 ;
F_76 ( V_2 ) ;
return V_27 ;
}
static int F_101 ( void * V_13 , bool V_222 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( L_16 , V_2 , V_2 -> V_6 , V_222 ) ;
if ( ! V_222 )
return 0 ;
F_86 ( V_2 ) ;
return 0 ;
}
static void F_102 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 , V_225 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_77 ( V_2 -> V_84 ) < 0 )
return;
if ( F_5 ( V_181 , & V_2 -> V_151 ) )
F_104 ( & V_2 -> V_170 , V_226 ) ;
if ( F_89 ( V_163 , & V_2 -> V_151 ) )
F_105 ( V_2 ) ;
}
static void F_106 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 ,
V_170 . V_224 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_86 ( V_2 ) ;
}
static void F_107 ( struct V_223 * V_224 )
{
struct V_1 * V_2 ;
T_8 V_73 = V_227 ;
V_2 = F_103 ( V_224 , struct V_1 , V_173 . V_224 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_69 ( V_2 ) ;
F_26 ( V_2 , V_74 , sizeof( V_73 ) , & V_73 ) ;
V_2 -> V_172 = 0 ;
F_72 ( V_2 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_104 * V_96 , * V_97 ;
F_109 (p, n, &hdev->uuids) {
struct V_228 * V_229 ;
V_229 = F_110 ( V_96 , struct V_228 , V_106 ) ;
F_53 ( V_96 ) ;
F_54 ( V_229 ) ;
}
return 0 ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_104 * V_96 , * V_97 ;
F_109 (p, n, &hdev->link_keys) {
struct V_230 * V_231 ;
V_231 = F_110 ( V_96 , struct V_230 , V_106 ) ;
F_53 ( V_96 ) ;
F_54 ( V_231 ) ;
}
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_232 * V_233 , * V_234 ;
F_52 (k, tmp, &hdev->long_term_keys, list) {
F_53 ( & V_233 -> V_106 ) ;
F_54 ( V_233 ) ;
}
return 0 ;
}
struct V_230 * F_113 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_230 * V_233 ;
F_45 (k, &hdev->link_keys, list)
if ( F_58 ( V_56 , & V_233 -> V_56 ) == 0 )
return V_233 ;
return NULL ;
}
static bool F_114 ( struct V_1 * V_2 , struct V_235 * V_236 ,
T_8 V_237 , T_8 V_238 )
{
if ( V_237 < 0x03 )
return true ;
if ( V_237 == V_239 )
return false ;
if ( V_237 == V_240 && V_238 == 0xff )
return false ;
if ( ! V_236 )
return true ;
if ( V_236 -> V_241 > 0x01 && V_236 -> V_242 > 0x01 )
return true ;
if ( V_236 -> V_241 == 0x02 || V_236 -> V_241 == 0x03 )
return true ;
if ( V_236 -> V_242 == 0x02 || V_236 -> V_242 == 0x03 )
return true ;
return false ;
}
struct V_232 * F_115 ( struct V_1 * V_2 , T_4 V_243 , T_8 rand [ 8 ] )
{
struct V_232 * V_233 ;
F_45 (k, &hdev->long_term_keys, list) {
if ( V_233 -> V_243 != V_243 ||
memcmp ( rand , V_233 -> rand , sizeof( V_233 -> rand ) ) )
continue;
return V_233 ;
}
return NULL ;
}
struct V_232 * F_116 ( struct V_1 * V_2 , T_6 * V_56 ,
T_8 V_244 )
{
struct V_232 * V_233 ;
F_45 (k, &hdev->long_term_keys, list)
if ( V_244 == V_233 -> V_245 &&
F_58 ( V_56 , & V_233 -> V_56 ) == 0 )
return V_233 ;
return NULL ;
}
int F_117 ( struct V_1 * V_2 , struct V_235 * V_236 , int V_246 ,
T_6 * V_56 , T_8 * V_247 , T_8 type , T_8 V_248 )
{
struct V_230 * V_231 , * V_249 ;
T_8 V_238 ;
bool V_250 ;
V_249 = F_113 ( V_2 , V_56 ) ;
if ( V_249 ) {
V_238 = V_249 -> type ;
V_231 = V_249 ;
} else {
V_238 = V_236 ? V_236 -> V_237 : 0xff ;
V_231 = F_64 ( sizeof( * V_231 ) , V_18 ) ;
if ( ! V_231 )
return - V_149 ;
F_62 ( & V_231 -> V_106 , & V_2 -> V_251 ) ;
}
F_4 ( L_17 , V_2 -> V_6 , F_57 ( V_56 ) , type ) ;
if ( type == V_240 &&
( ! V_236 || V_236 -> V_242 == 0xff ) && V_238 == 0xff ) {
type = V_252 ;
if ( V_236 )
V_236 -> V_237 = type ;
}
F_29 ( & V_231 -> V_56 , V_56 ) ;
memcpy ( V_231 -> V_247 , V_247 , V_253 ) ;
V_231 -> V_248 = V_248 ;
if ( type == V_240 )
V_231 -> type = V_238 ;
else
V_231 -> type = type ;
if ( ! V_246 )
return 0 ;
V_250 = F_114 ( V_2 , V_236 , type , V_238 ) ;
F_118 ( V_2 , V_231 , V_250 ) ;
if ( V_236 )
V_236 -> V_254 = ! V_250 ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 , T_6 * V_56 , T_8 V_244 , T_8 type ,
int V_246 , T_8 V_255 , T_8 V_256 [ 16 ] , T_8 V_257 , T_4
V_243 , T_8 rand [ 8 ] )
{
struct V_232 * V_231 , * V_249 ;
if ( ! ( type & V_258 ) && ! ( type & V_259 ) )
return 0 ;
V_249 = F_116 ( V_2 , V_56 , V_244 ) ;
if ( V_249 )
V_231 = V_249 ;
else {
V_231 = F_64 ( sizeof( * V_231 ) , V_18 ) ;
if ( ! V_231 )
return - V_149 ;
F_62 ( & V_231 -> V_106 , & V_2 -> V_260 ) ;
}
F_29 ( & V_231 -> V_56 , V_56 ) ;
V_231 -> V_245 = V_244 ;
memcpy ( V_231 -> V_247 , V_256 , sizeof( V_231 -> V_247 ) ) ;
V_231 -> V_255 = V_255 ;
V_231 -> V_243 = V_243 ;
V_231 -> V_257 = V_257 ;
V_231 -> type = type ;
memcpy ( V_231 -> rand , rand , sizeof( V_231 -> rand ) ) ;
if ( ! V_246 )
return 0 ;
if ( type & V_259 )
F_120 ( V_2 , V_231 , 1 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_230 * V_231 ;
V_231 = F_113 ( V_2 , V_56 ) ;
if ( ! V_231 )
return - V_261 ;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_231 -> V_106 ) ;
F_54 ( V_231 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_232 * V_233 , * V_234 ;
F_52 (k, tmp, &hdev->long_term_keys, list) {
if ( F_58 ( V_56 , & V_233 -> V_56 ) )
continue;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_233 -> V_106 ) ;
F_54 ( V_233 ) ;
}
return 0 ;
}
static void F_123 ( unsigned long V_137 )
{
struct V_1 * V_2 = ( void * ) V_137 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = ( void * ) V_2 -> V_12 -> V_13 ;
T_2 V_14 = F_6 ( V_11 -> V_14 ) ;
F_36 ( L_19 , V_2 -> V_6 , V_14 ) ;
} else {
F_36 ( L_20 , V_2 -> V_6 ) ;
}
F_79 ( & V_2 -> V_160 , 1 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
struct V_262 * F_124 ( struct V_1 * V_2 ,
T_6 * V_56 )
{
struct V_262 * V_13 ;
F_45 (data, &hdev->remote_oob_data, list)
if ( F_58 ( V_56 , & V_13 -> V_56 ) == 0 )
return V_13 ;
return NULL ;
}
int F_125 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_262 * V_13 ;
V_13 = F_124 ( V_2 , V_56 ) ;
if ( ! V_13 )
return - V_261 ;
F_4 ( L_18 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
F_53 ( & V_13 -> V_106 ) ;
F_54 ( V_13 ) ;
return 0 ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_262 * V_13 , * V_97 ;
F_52 (data, n, &hdev->remote_oob_data, list) {
F_53 ( & V_13 -> V_106 ) ;
F_54 ( V_13 ) ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 , T_6 * V_56 , T_8 * V_263 ,
T_8 * V_264 )
{
struct V_262 * V_13 ;
V_13 = F_124 ( V_2 , V_56 ) ;
if ( ! V_13 ) {
V_13 = F_74 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_149 ;
F_29 ( & V_13 -> V_56 , V_56 ) ;
F_62 ( & V_13 -> V_106 , & V_2 -> V_265 ) ;
}
memcpy ( V_13 -> V_263 , V_263 , sizeof( V_13 -> V_263 ) ) ;
memcpy ( V_13 -> V_264 , V_264 , sizeof( V_13 -> V_264 ) ) ;
F_4 ( L_21 , V_2 -> V_6 , F_57 ( V_56 ) ) ;
return 0 ;
}
struct V_266 * F_128 ( struct V_1 * V_2 , T_6 * V_56 )
{
struct V_266 * V_267 ;
F_45 (b, &hdev->blacklist, list)
if ( F_58 ( V_56 , & V_267 -> V_56 ) == 0 )
return V_267 ;
return NULL ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_104 * V_96 , * V_97 ;
F_109 (p, n, &hdev->blacklist) {
struct V_266 * V_267 ;
V_267 = F_110 ( V_96 , struct V_266 , V_106 ) ;
F_53 ( V_96 ) ;
F_54 ( V_267 ) ;
}
return 0 ;
}
int F_130 ( struct V_1 * V_2 , T_6 * V_56 , T_8 type )
{
struct V_266 * V_268 ;
if ( F_58 ( V_56 , V_57 ) == 0 )
return - V_269 ;
if ( F_128 ( V_2 , V_56 ) )
return - V_270 ;
V_268 = F_64 ( sizeof( struct V_266 ) , V_148 ) ;
if ( ! V_268 )
return - V_149 ;
F_29 ( & V_268 -> V_56 , V_56 ) ;
F_62 ( & V_268 -> V_106 , & V_2 -> V_271 ) ;
return F_131 ( V_2 , V_56 , type ) ;
}
int F_132 ( struct V_1 * V_2 , T_6 * V_56 , T_8 type )
{
struct V_266 * V_268 ;
if ( F_58 ( V_56 , V_57 ) == 0 )
return F_129 ( V_2 ) ;
V_268 = F_128 ( V_2 , V_56 ) ;
if ( ! V_268 )
return - V_261 ;
F_53 ( & V_268 -> V_106 ) ;
F_54 ( V_268 ) ;
return F_133 ( V_2 , V_56 , type ) ;
}
static void F_134 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_272 * V_42 = (struct V_272 * ) V_29 ;
struct V_273 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . type = V_42 -> type ;
V_41 . V_274 = F_42 ( V_42 -> V_274 ) ;
V_41 . V_275 = F_42 ( V_42 -> V_275 ) ;
F_26 ( V_2 , V_276 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_135 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_277 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_278 = 1 ;
V_41 . V_279 = 1 ;
F_26 ( V_2 , V_280 , sizeof( V_41 ) , & V_41 ) ;
}
static int F_136 ( struct V_1 * V_2 , T_8 type , T_2 V_274 ,
T_2 V_275 , int V_30 )
{
long V_141 = F_73 ( 3000 ) ;
struct V_272 V_42 ;
int V_27 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_281 , & V_2 -> V_151 ) )
return - V_282 ;
V_42 . type = type ;
V_42 . V_274 = V_274 ;
V_42 . V_275 = V_275 ;
F_22 ( V_2 ) ;
V_27 = F_12 ( V_2 , F_134 , ( unsigned long ) & V_42 ,
V_141 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_2 , F_135 , 0 , V_141 ) ;
F_23 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_104 ( & V_2 -> V_177 ,
F_73 ( V_30 ) ) ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_281 , & V_2 -> V_151 ) )
return - V_154 ;
if ( F_88 ( & V_2 -> V_177 ) ) {
struct V_277 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_280 , sizeof( V_41 ) , & V_41 ) ;
}
return 0 ;
}
static void F_138 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 ,
V_177 . V_224 ) ;
struct V_277 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_280 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_139 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 , V_169 ) ;
struct V_272 * V_42 = & V_2 -> V_272 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_136 ( V_2 , V_42 -> type , V_42 -> V_274 , V_42 -> V_275 ,
V_42 -> V_30 ) ;
}
int F_140 ( struct V_1 * V_2 , T_8 type , T_2 V_274 , T_2 V_275 ,
int V_30 )
{
struct V_272 * V_42 = & V_2 -> V_272 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_141 ( & V_2 -> V_169 ) )
return - V_282 ;
V_42 -> type = type ;
V_42 -> V_274 = V_274 ;
V_42 -> V_275 = V_275 ;
V_42 -> V_30 = V_30 ;
F_9 ( V_283 , & V_2 -> V_169 ) ;
return 0 ;
}
struct V_1 * F_142 ( void )
{
struct V_1 * V_2 ;
V_2 = F_64 ( sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_64 = ( V_284 | V_285 | V_286 ) ;
V_2 -> V_287 = ( V_288 ) ;
V_2 -> V_198 = ( V_200 ) ;
V_2 -> V_289 = 0x03 ;
V_2 -> V_290 = 800 ;
V_2 -> V_291 = 80 ;
F_143 ( & V_2 -> V_292 ) ;
F_143 ( & V_2 -> V_293 ) ;
F_55 ( & V_2 -> V_294 ) ;
F_55 ( & V_2 -> V_271 ) ;
F_55 ( & V_2 -> V_295 ) ;
F_55 ( & V_2 -> V_251 ) ;
F_55 ( & V_2 -> V_260 ) ;
F_55 ( & V_2 -> V_265 ) ;
F_55 ( & V_2 -> V_296 . V_106 ) ;
F_144 ( & V_2 -> V_165 , V_297 ) ;
F_144 ( & V_2 -> V_21 , V_298 ) ;
F_144 ( & V_2 -> V_164 , V_299 ) ;
F_144 ( & V_2 -> V_225 , F_102 ) ;
F_144 ( & V_2 -> V_169 , F_139 ) ;
F_145 ( & V_2 -> V_170 , F_106 ) ;
F_145 ( & V_2 -> V_173 , F_107 ) ;
F_145 ( & V_2 -> V_177 , F_138 ) ;
F_146 ( & V_2 -> V_63 ) ;
F_146 ( & V_2 -> V_166 ) ;
F_146 ( & V_2 -> V_19 ) ;
F_146 ( & V_2 -> V_180 ) ;
F_147 ( & V_2 -> V_26 ) ;
F_148 ( & V_2 -> V_171 , F_123 , ( unsigned long ) V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return V_2 ;
}
void F_151 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_63 ) ;
F_152 ( & V_2 -> V_66 ) ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_84 , error ;
if ( ! V_2 -> V_158 || ! V_2 -> V_168 )
return - V_208 ;
switch ( V_2 -> V_69 ) {
case V_70 :
V_84 = F_154 ( & V_300 , 0 , 0 , V_148 ) ;
break;
case V_71 :
V_84 = F_154 ( & V_300 , 1 , 0 , V_148 ) ;
break;
default:
return - V_208 ;
}
if ( V_84 < 0 )
return V_84 ;
sprintf ( V_2 -> V_6 , L_22 , V_84 ) ;
V_2 -> V_84 = V_84 ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_219 ) ;
F_155 ( & V_83 ) ;
F_62 ( & V_2 -> V_106 , & V_301 ) ;
F_156 ( & V_83 ) ;
V_2 -> V_20 = F_157 ( V_2 -> V_6 , V_302 | V_303 |
V_304 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_149 ;
goto V_27;
}
error = F_158 ( V_2 ) ;
if ( error < 0 )
goto V_305;
V_2 -> V_152 = F_159 ( V_2 -> V_6 , & V_2 -> V_66 ,
V_306 , & V_307 ,
V_2 ) ;
if ( V_2 -> V_152 ) {
if ( F_160 ( V_2 -> V_152 ) < 0 ) {
F_161 ( V_2 -> V_152 ) ;
V_2 -> V_152 = NULL ;
}
}
F_25 ( V_163 , & V_2 -> V_151 ) ;
if ( V_2 -> V_69 != V_71 )
F_25 ( V_181 , & V_2 -> V_151 ) ;
F_1 ( V_2 , V_308 ) ;
F_46 ( V_2 ) ;
F_162 ( & V_2 -> V_225 ) ;
return V_84 ;
V_305:
F_163 ( V_2 -> V_20 ) ;
V_27:
F_164 ( & V_300 , V_2 -> V_84 ) ;
F_155 ( & V_83 ) ;
F_53 ( & V_2 -> V_106 ) ;
F_156 ( & V_83 ) ;
return error ;
}
void F_165 ( struct V_1 * V_2 )
{
int V_309 , V_84 ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_219 ) ;
F_25 ( V_150 , & V_2 -> V_151 ) ;
V_84 = V_2 -> V_84 ;
F_155 ( & V_83 ) ;
F_53 ( & V_2 -> V_106 ) ;
F_156 ( & V_83 ) ;
F_86 ( V_2 ) ;
for ( V_309 = 0 ; V_309 < V_310 ; V_309 ++ )
F_85 ( V_2 -> V_311 [ V_309 ] ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_163 , & V_2 -> V_151 ) ) {
F_69 ( V_2 ) ;
F_166 ( V_2 ) ;
F_72 ( V_2 ) ;
}
F_167 ( ! F_168 ( & V_2 -> V_294 ) ) ;
F_1 ( V_2 , V_312 ) ;
if ( V_2 -> V_152 ) {
F_169 ( V_2 -> V_152 ) ;
F_161 ( V_2 -> V_152 ) ;
}
F_170 ( V_2 ) ;
F_163 ( V_2 -> V_20 ) ;
F_69 ( V_2 ) ;
F_129 ( V_2 ) ;
F_108 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_126 ( V_2 ) ;
F_72 ( V_2 ) ;
F_76 ( V_2 ) ;
F_164 ( & V_300 , V_84 ) ;
}
int F_171 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_313 ) ;
return 0 ;
}
int F_172 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_314 ) ;
return 0 ;
}
int F_173 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_66 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_85 ( V_16 ) ;
return - V_315 ;
}
F_33 ( V_16 ) -> V_316 = 1 ;
F_174 ( V_16 ) ;
F_34 ( & V_2 -> V_166 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_165 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_317 , T_5 V_81 )
{
int V_318 = 0 ;
int V_319 = 0 ;
int V_320 = V_317 ;
struct V_15 * V_16 ;
struct V_321 * V_322 ;
if ( ( type < V_323 || type > V_324 ) ||
V_81 >= V_310 )
return - V_325 ;
V_16 = V_2 -> V_311 [ V_81 ] ;
if ( ! V_16 ) {
switch ( type ) {
case V_323 :
V_318 = V_326 ;
V_319 = V_327 ;
break;
case V_324 :
V_318 = V_328 ;
V_319 = V_329 ;
break;
case V_330 :
V_318 = V_331 ;
V_319 = V_332 ;
break;
}
V_16 = F_176 ( V_318 , V_18 ) ;
if ( ! V_16 )
return - V_149 ;
V_322 = ( void * ) V_16 -> V_333 ;
V_322 -> V_334 = V_319 ;
V_322 -> V_64 = type ;
V_16 -> V_66 = ( void * ) V_2 ;
V_2 -> V_311 [ V_81 ] = V_16 ;
}
while ( V_317 ) {
V_322 = ( void * ) V_16 -> V_333 ;
V_318 = F_177 ( V_335 , V_322 -> V_334 , V_317 ) ;
memcpy ( F_178 ( V_16 , V_318 ) , V_13 , V_318 ) ;
V_317 -= V_318 ;
V_13 += V_318 ;
V_322 -> V_334 -= V_318 ;
V_320 = V_317 ;
switch ( type ) {
case V_324 :
if ( V_16 -> V_318 == V_329 ) {
struct V_336 * V_337 = V_336 ( V_16 ) ;
V_322 -> V_334 = V_337 -> V_338 ;
if ( F_179 ( V_16 ) < V_322 -> V_334 ) {
F_85 ( V_16 ) ;
V_2 -> V_311 [ V_81 ] = NULL ;
return - V_149 ;
}
}
break;
case V_323 :
if ( V_16 -> V_318 == V_327 ) {
struct V_339 * V_337 = V_339 ( V_16 ) ;
V_322 -> V_334 = F_6 ( V_337 -> V_340 ) ;
if ( F_179 ( V_16 ) < V_322 -> V_334 ) {
F_85 ( V_16 ) ;
V_2 -> V_311 [ V_81 ] = NULL ;
return - V_149 ;
}
}
break;
case V_330 :
if ( V_16 -> V_318 == V_332 ) {
struct V_341 * V_337 = V_341 ( V_16 ) ;
V_322 -> V_334 = V_337 -> V_340 ;
if ( F_179 ( V_16 ) < V_322 -> V_334 ) {
F_85 ( V_16 ) ;
V_2 -> V_311 [ V_81 ] = NULL ;
return - V_149 ;
}
}
break;
}
if ( V_322 -> V_334 == 0 ) {
F_33 ( V_16 ) -> V_64 = type ;
F_173 ( V_16 ) ;
V_2 -> V_311 [ V_81 ] = NULL ;
return V_320 ;
}
}
return V_320 ;
}
int F_180 ( struct V_1 * V_2 , int type , void * V_13 , int V_317 )
{
int V_342 = 0 ;
if ( type < V_323 || type > V_324 )
return - V_325 ;
while ( V_317 ) {
V_342 = F_175 ( V_2 , type , V_13 , V_317 , type - 1 ) ;
if ( V_342 < 0 )
return V_342 ;
V_13 += ( V_317 - V_342 ) ;
V_317 = V_342 ;
}
return V_342 ;
}
int F_181 ( struct V_1 * V_2 , void * V_13 , int V_317 )
{
int type ;
int V_342 = 0 ;
while ( V_317 ) {
struct V_15 * V_16 = V_2 -> V_311 [ V_343 ] ;
if ( ! V_16 ) {
struct { char type ; } * V_344 ;
V_344 = V_13 ;
type = V_344 -> type ;
V_13 ++ ;
V_317 -- ;
} else
type = F_33 ( V_16 ) -> V_64 ;
V_342 = F_175 ( V_2 , type , V_13 , V_317 ,
V_343 ) ;
if ( V_342 < 0 )
return V_342 ;
V_13 += ( V_317 - V_342 ) ;
V_317 = V_342 ;
}
return V_342 ;
}
int F_182 ( struct V_345 * V_333 )
{
F_4 ( L_24 , V_333 , V_333 -> V_6 ) ;
F_155 ( & V_346 ) ;
F_62 ( & V_333 -> V_106 , & V_347 ) ;
F_156 ( & V_346 ) ;
return 0 ;
}
int F_183 ( struct V_345 * V_333 )
{
F_4 ( L_24 , V_333 , V_333 -> V_6 ) ;
F_155 ( & V_346 ) ;
F_53 ( & V_333 -> V_106 ) ;
F_156 ( & V_346 ) ;
return 0 ;
}
static int F_184 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_66 ;
if ( ! V_2 ) {
F_85 ( V_16 ) ;
return - V_144 ;
}
F_4 ( L_25 , V_2 -> V_6 , F_33 ( V_16 ) -> V_64 , V_16 -> V_318 ) ;
F_174 ( V_16 ) ;
F_185 ( V_2 , V_16 ) ;
if ( F_186 ( & V_2 -> V_348 ) ) {
F_187 ( V_2 , V_16 ) ;
}
F_188 ( V_16 ) ;
return V_2 -> V_349 ( V_16 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_338 , void * V_42 )
{
int V_318 = V_350 + V_338 ;
struct V_10 * V_351 ;
struct V_15 * V_16 ;
F_4 ( L_26 , V_2 -> V_6 , V_14 , V_338 ) ;
V_16 = F_176 ( V_318 , V_18 ) ;
if ( ! V_16 ) {
F_36 ( L_27 , V_2 -> V_6 ) ;
return - V_149 ;
}
V_351 = (struct V_10 * ) F_178 ( V_16 , V_350 ) ;
V_351 -> V_14 = F_42 ( V_14 ) ;
V_351 -> V_338 = V_338 ;
if ( V_338 )
memcpy ( F_178 ( V_16 , V_338 ) , V_42 , V_338 ) ;
F_4 ( L_28 , V_16 -> V_318 ) ;
F_33 ( V_16 ) -> V_64 = V_65 ;
V_16 -> V_66 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_14 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_189 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_351 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_351 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_351 -> V_14 != F_42 ( V_14 ) )
return NULL ;
F_4 ( L_29 , V_2 -> V_6 , V_14 ) ;
return V_2 -> V_12 -> V_13 + V_350 ;
}
static void F_190 ( struct V_15 * V_16 , T_1 V_352 , T_1 V_8 )
{
struct V_339 * V_351 ;
int V_318 = V_16 -> V_318 ;
F_191 ( V_16 , V_327 ) ;
F_192 ( V_16 ) ;
V_351 = (struct V_339 * ) F_193 ( V_16 ) ;
V_351 -> V_352 = F_42 ( F_194 ( V_352 , V_8 ) ) ;
V_351 -> V_340 = F_42 ( V_318 ) ;
}
static void F_195 ( struct V_235 * V_236 , struct V_353 * V_354 ,
struct V_15 * V_16 , T_1 V_8 )
{
struct V_1 * V_2 = V_236 -> V_2 ;
struct V_15 * V_106 ;
V_16 -> V_318 = F_196 ( V_16 ) ;
V_16 -> V_355 = 0 ;
F_33 ( V_16 ) -> V_64 = V_323 ;
F_190 ( V_16 , V_236 -> V_352 , V_8 ) ;
V_106 = F_197 ( V_16 ) -> V_356 ;
if ( ! V_106 ) {
F_4 ( L_30 , V_2 -> V_6 , V_16 , V_16 -> V_318 ) ;
F_34 ( V_354 , V_16 ) ;
} else {
F_4 ( L_31 , V_2 -> V_6 , V_16 , V_16 -> V_318 ) ;
F_197 ( V_16 ) -> V_356 = NULL ;
F_198 ( & V_354 -> V_292 ) ;
F_199 ( V_354 , V_16 ) ;
V_8 &= ~ V_357 ;
V_8 |= V_358 ;
do {
V_16 = V_106 ; V_106 = V_106 -> V_359 ;
V_16 -> V_66 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_64 = V_323 ;
F_190 ( V_16 , V_236 -> V_352 , V_8 ) ;
F_4 ( L_31 , V_2 -> V_6 , V_16 , V_16 -> V_318 ) ;
F_199 ( V_354 , V_16 ) ;
} while ( V_106 );
F_200 ( & V_354 -> V_292 ) ;
}
}
void F_201 ( struct V_360 * V_361 , struct V_15 * V_16 , T_1 V_8 )
{
struct V_235 * V_236 = V_361 -> V_236 ;
struct V_1 * V_2 = V_236 -> V_2 ;
F_4 ( L_32 , V_2 -> V_6 , V_361 , V_8 ) ;
V_16 -> V_66 = ( void * ) V_2 ;
F_195 ( V_236 , & V_361 -> V_362 , V_16 , V_8 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_164 ) ;
}
void F_202 ( struct V_235 * V_236 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_236 -> V_2 ;
struct V_341 V_351 ;
F_4 ( L_33 , V_2 -> V_6 , V_16 -> V_318 ) ;
V_351 . V_352 = F_42 ( V_236 -> V_352 ) ;
V_351 . V_340 = V_16 -> V_318 ;
F_191 ( V_16 , V_332 ) ;
F_192 ( V_16 ) ;
memcpy ( F_193 ( V_16 ) , & V_351 , V_332 ) ;
V_16 -> V_66 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_64 = V_330 ;
F_34 ( & V_236 -> V_362 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_164 ) ;
}
static struct V_235 * F_203 ( struct V_1 * V_2 , T_5 type ,
int * V_363 )
{
struct V_364 * V_337 = & V_2 -> V_296 ;
struct V_235 * V_236 = NULL , * V_365 ;
unsigned int V_119 = 0 , V_366 = ~ 0 ;
F_204 () ;
F_205 (c, &h->list, list) {
if ( V_365 -> type != type || F_206 ( & V_365 -> V_362 ) )
continue;
if ( V_365 -> V_88 != V_367 && V_365 -> V_88 != V_368 )
continue;
V_119 ++ ;
if ( V_365 -> V_11 < V_366 ) {
V_366 = V_365 -> V_11 ;
V_236 = V_365 ;
}
if ( F_207 ( V_2 , type ) == V_119 )
break;
}
F_208 () ;
if ( V_236 ) {
int V_369 , V_370 ;
switch ( V_236 -> type ) {
case V_371 :
V_369 = V_2 -> V_183 ;
break;
case V_372 :
case V_373 :
V_369 = V_2 -> V_184 ;
break;
case V_374 :
V_369 = V_2 -> V_375 ? V_2 -> V_185 : V_2 -> V_183 ;
break;
default:
V_369 = 0 ;
F_36 ( L_34 ) ;
}
V_370 = V_369 / V_119 ;
* V_363 = V_370 ? V_370 : 1 ;
} else
* V_363 = 0 ;
F_4 ( L_35 , V_236 , * V_363 ) ;
return V_236 ;
}
static void F_209 ( struct V_1 * V_2 , T_5 type )
{
struct V_364 * V_337 = & V_2 -> V_296 ;
struct V_235 * V_365 ;
F_36 ( L_36 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (c, &h->list, list) {
if ( V_365 -> type == type && V_365 -> V_11 ) {
F_36 ( L_37 ,
V_2 -> V_6 , F_57 ( & V_365 -> V_376 ) ) ;
F_210 ( V_365 , V_377 ) ;
}
}
F_208 () ;
}
static struct V_360 * F_211 ( struct V_1 * V_2 , T_5 type ,
int * V_363 )
{
struct V_364 * V_337 = & V_2 -> V_296 ;
struct V_360 * V_361 = NULL ;
unsigned int V_119 = 0 , V_366 = ~ 0 , V_378 = 0 ;
struct V_235 * V_236 ;
int V_369 , V_370 , V_379 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (conn, &h->list, list) {
struct V_360 * V_234 ;
if ( V_236 -> type != type )
continue;
if ( V_236 -> V_88 != V_367 && V_236 -> V_88 != V_368 )
continue;
V_379 ++ ;
F_205 (tmp, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( F_206 ( & V_234 -> V_362 ) )
continue;
V_16 = F_212 ( & V_234 -> V_362 ) ;
if ( V_16 -> V_380 < V_378 )
continue;
if ( V_16 -> V_380 > V_378 ) {
V_119 = 0 ;
V_366 = ~ 0 ;
V_378 = V_16 -> V_380 ;
}
V_119 ++ ;
if ( V_236 -> V_11 < V_366 ) {
V_366 = V_236 -> V_11 ;
V_361 = V_234 ;
}
}
if ( F_207 ( V_2 , type ) == V_379 )
break;
}
F_208 () ;
if ( ! V_361 )
return NULL ;
switch ( V_361 -> V_236 -> type ) {
case V_371 :
V_369 = V_2 -> V_183 ;
break;
case V_372 :
case V_373 :
V_369 = V_2 -> V_184 ;
break;
case V_374 :
V_369 = V_2 -> V_375 ? V_2 -> V_185 : V_2 -> V_183 ;
break;
default:
V_369 = 0 ;
F_36 ( L_34 ) ;
}
V_370 = V_369 / V_119 ;
* V_363 = V_370 ? V_370 : 1 ;
F_4 ( L_38 , V_361 , * V_363 ) ;
return V_361 ;
}
static void F_213 ( struct V_1 * V_2 , T_5 type )
{
struct V_364 * V_337 = & V_2 -> V_296 ;
struct V_235 * V_236 ;
int V_119 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_204 () ;
F_205 (conn, &h->list, list) {
struct V_360 * V_361 ;
if ( V_236 -> type != type )
continue;
if ( V_236 -> V_88 != V_367 && V_236 -> V_88 != V_368 )
continue;
V_119 ++ ;
F_205 (chan, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( V_361 -> V_11 ) {
V_361 -> V_11 = 0 ;
continue;
}
if ( F_206 ( & V_361 -> V_362 ) )
continue;
V_16 = F_212 ( & V_361 -> V_362 ) ;
if ( V_16 -> V_380 >= V_381 - 1 )
continue;
V_16 -> V_380 = V_381 - 1 ;
F_4 ( L_39 , V_361 , V_16 ,
V_16 -> V_380 ) ;
}
if ( F_207 ( V_2 , type ) == V_119 )
break;
}
F_208 () ;
}
static inline int F_214 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_215 ( V_16 -> V_318 - V_327 , V_2 -> V_382 ) ;
}
static void F_216 ( struct V_1 * V_2 , unsigned int V_369 )
{
if ( ! F_5 ( V_156 , & V_2 -> V_8 ) ) {
if ( ! V_369 && F_217 ( V_118 , V_2 -> V_383 +
V_384 ) )
F_209 ( V_2 , V_371 ) ;
}
}
static void F_218 ( struct V_1 * V_2 )
{
unsigned int V_369 = V_2 -> V_183 ;
struct V_360 * V_361 ;
struct V_15 * V_16 ;
int V_363 ;
F_216 ( V_2 , V_369 ) ;
while ( V_2 -> V_183 &&
( V_361 = F_211 ( V_2 , V_371 , & V_363 ) ) ) {
T_9 V_380 = ( F_212 ( & V_361 -> V_362 ) ) -> V_380 ;
while ( V_363 -- && ( V_16 = F_212 ( & V_361 -> V_362 ) ) ) {
F_4 ( L_40 , V_361 , V_16 ,
V_16 -> V_318 , V_16 -> V_380 ) ;
if ( V_16 -> V_380 < V_380 )
break;
V_16 = F_32 ( & V_361 -> V_362 ) ;
F_219 ( V_361 -> V_236 ,
F_33 ( V_16 ) -> V_385 ) ;
F_184 ( V_16 ) ;
V_2 -> V_383 = V_118 ;
V_2 -> V_183 -- ;
V_361 -> V_11 ++ ;
V_361 -> V_236 -> V_11 ++ ;
}
}
if ( V_369 != V_2 -> V_183 )
F_213 ( V_2 , V_371 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
unsigned int V_369 = V_2 -> V_386 ;
struct V_360 * V_361 ;
struct V_15 * V_16 ;
int V_363 ;
F_216 ( V_2 , V_369 ) ;
while ( V_2 -> V_386 > 0 &&
( V_361 = F_211 ( V_2 , V_371 , & V_363 ) ) ) {
T_9 V_380 = ( F_212 ( & V_361 -> V_362 ) ) -> V_380 ;
while ( V_363 > 0 && ( V_16 = F_212 ( & V_361 -> V_362 ) ) ) {
int V_387 ;
F_4 ( L_40 , V_361 , V_16 ,
V_16 -> V_318 , V_16 -> V_380 ) ;
if ( V_16 -> V_380 < V_380 )
break;
V_16 = F_32 ( & V_361 -> V_362 ) ;
V_387 = F_214 ( V_2 , V_16 ) ;
if ( V_387 > V_2 -> V_386 )
return;
F_219 ( V_361 -> V_236 ,
F_33 ( V_16 ) -> V_385 ) ;
F_184 ( V_16 ) ;
V_2 -> V_383 = V_118 ;
V_2 -> V_386 -= V_387 ;
V_363 -= V_387 ;
V_361 -> V_11 += V_387 ;
V_361 -> V_236 -> V_11 += V_387 ;
}
}
if ( V_369 != V_2 -> V_386 )
F_213 ( V_2 , V_371 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_371 ) )
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
struct V_235 * V_236 ;
struct V_15 * V_16 ;
int V_363 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_372 ) )
return;
while ( V_2 -> V_184 && ( V_236 = F_203 ( V_2 , V_372 , & V_363 ) ) ) {
while ( V_363 -- && ( V_16 = F_32 ( & V_236 -> V_362 ) ) ) {
F_4 ( L_41 , V_16 , V_16 -> V_318 ) ;
F_184 ( V_16 ) ;
V_236 -> V_11 ++ ;
if ( V_236 -> V_11 == ~ 0 )
V_236 -> V_11 = 0 ;
}
}
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_235 * V_236 ;
struct V_15 * V_16 ;
int V_363 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_373 ) )
return;
while ( V_2 -> V_184 && ( V_236 = F_203 ( V_2 , V_373 ,
& V_363 ) ) ) {
while ( V_363 -- && ( V_16 = F_32 ( & V_236 -> V_362 ) ) ) {
F_4 ( L_41 , V_16 , V_16 -> V_318 ) ;
F_184 ( V_16 ) ;
V_236 -> V_11 ++ ;
if ( V_236 -> V_11 == ~ 0 )
V_236 -> V_11 = 0 ;
}
}
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_360 * V_361 ;
struct V_15 * V_16 ;
int V_363 , V_369 , V_234 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_207 ( V_2 , V_374 ) )
return;
if ( ! F_5 ( V_156 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_185 && V_2 -> V_388 &&
F_217 ( V_118 , V_2 -> V_389 + V_390 * 45 ) )
F_209 ( V_2 , V_374 ) ;
}
V_369 = V_2 -> V_388 ? V_2 -> V_185 : V_2 -> V_183 ;
V_234 = V_369 ;
while ( V_369 && ( V_361 = F_211 ( V_2 , V_374 , & V_363 ) ) ) {
T_9 V_380 = ( F_212 ( & V_361 -> V_362 ) ) -> V_380 ;
while ( V_363 -- && ( V_16 = F_212 ( & V_361 -> V_362 ) ) ) {
F_4 ( L_40 , V_361 , V_16 ,
V_16 -> V_318 , V_16 -> V_380 ) ;
if ( V_16 -> V_380 < V_380 )
break;
V_16 = F_32 ( & V_361 -> V_362 ) ;
F_184 ( V_16 ) ;
V_2 -> V_389 = V_118 ;
V_369 -- ;
V_361 -> V_11 ++ ;
V_361 -> V_236 -> V_11 ++ ;
}
}
if ( V_2 -> V_388 )
V_2 -> V_185 = V_369 ;
else
V_2 -> V_183 = V_369 ;
if ( V_369 != V_234 )
F_213 ( V_2 , V_374 ) ;
}
static void V_299 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 , V_164 ) ;
struct V_15 * V_16 ;
F_4 ( L_42 , V_2 -> V_6 , V_2 -> V_183 ,
V_2 -> V_184 , V_2 -> V_185 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_180 ) ) )
F_184 ( V_16 ) ;
}
static void F_225 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_339 * V_351 = ( void * ) V_16 -> V_13 ;
struct V_235 * V_236 ;
T_1 V_352 , V_8 ;
F_226 ( V_16 , V_327 ) ;
V_352 = F_6 ( V_351 -> V_352 ) ;
V_8 = F_227 ( V_352 ) ;
V_352 = F_228 ( V_352 ) ;
F_4 ( L_43 , V_2 -> V_6 , V_16 -> V_318 ,
V_352 , V_8 ) ;
V_2 -> V_186 . V_391 ++ ;
F_69 ( V_2 ) ;
V_236 = F_229 ( V_2 , V_352 ) ;
F_72 ( V_2 ) ;
if ( V_236 ) {
F_219 ( V_236 , V_392 ) ;
F_69 ( V_2 ) ;
if ( F_5 ( V_215 , & V_2 -> V_151 ) &&
! F_230 ( V_393 , & V_236 -> V_8 ) )
F_231 ( V_2 , & V_236 -> V_376 , V_236 -> type ,
V_236 -> V_394 , 0 , NULL , 0 ,
V_236 -> V_127 ) ;
F_72 ( V_2 ) ;
F_232 ( V_236 , V_16 , V_8 ) ;
return;
} else {
F_36 ( L_44 ,
V_2 -> V_6 , V_352 ) ;
}
F_85 ( V_16 ) ;
}
static void F_233 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_341 * V_351 = ( void * ) V_16 -> V_13 ;
struct V_235 * V_236 ;
T_1 V_352 ;
F_226 ( V_16 , V_332 ) ;
V_352 = F_6 ( V_351 -> V_352 ) ;
F_4 ( L_45 , V_2 -> V_6 , V_16 -> V_318 , V_352 ) ;
V_2 -> V_186 . V_395 ++ ;
F_69 ( V_2 ) ;
V_236 = F_229 ( V_2 , V_352 ) ;
F_72 ( V_2 ) ;
if ( V_236 ) {
F_234 ( V_236 , V_16 ) ;
return;
} else {
F_36 ( L_46 ,
V_2 -> V_6 , V_352 ) ;
}
F_85 ( V_16 ) ;
}
static void V_297 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 , V_165 ) ;
struct V_15 * V_16 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_166 ) ) ) {
F_185 ( V_2 , V_16 ) ;
if ( F_186 ( & V_2 -> V_348 ) ) {
F_187 ( V_2 , V_16 ) ;
}
if ( F_5 ( V_156 , & V_2 -> V_8 ) ) {
F_85 ( V_16 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_33 ( V_16 ) -> V_64 ) {
case V_323 :
case V_330 :
F_85 ( V_16 ) ;
continue;
}
}
switch ( F_33 ( V_16 ) -> V_64 ) {
case V_324 :
F_4 ( L_47 , V_2 -> V_6 ) ;
F_235 ( V_2 , V_16 ) ;
break;
case V_323 :
F_4 ( L_48 , V_2 -> V_6 ) ;
F_225 ( V_2 , V_16 ) ;
break;
case V_330 :
F_4 ( L_49 , V_2 -> V_6 ) ;
F_233 ( V_2 , V_16 ) ;
break;
default:
F_85 ( V_16 ) ;
break;
}
}
}
static void V_298 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_103 ( V_224 , struct V_1 , V_21 ) ;
struct V_15 * V_16 ;
F_4 ( L_50 , V_2 -> V_6 ,
F_186 ( & V_2 -> V_160 ) , F_236 ( & V_2 -> V_19 ) ) ;
if ( F_186 ( & V_2 -> V_160 ) ) {
V_16 = F_32 ( & V_2 -> V_19 ) ;
if ( ! V_16 )
return;
F_85 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_7 ( V_16 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_237 ( & V_2 -> V_160 ) ;
F_184 ( V_16 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_238 ( & V_2 -> V_171 ) ;
else
F_239 ( & V_2 -> V_171 ,
V_118 + V_179 ) ;
} else {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_240 ( struct V_1 * V_2 , T_8 V_134 )
{
T_8 V_133 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_131 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_132 , & V_2 -> V_8 ) )
return - V_282 ;
F_51 ( V_2 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( & V_41 . V_133 , V_133 , sizeof( V_41 . V_133 ) ) ;
V_41 . V_134 = V_134 ;
return F_26 ( V_2 , V_136 , sizeof( V_41 ) , & V_41 ) ;
}
int F_241 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_132 , & V_2 -> V_8 ) )
return - V_154 ;
return F_26 ( V_2 , V_396 , 0 , NULL ) ;
}
T_8 F_242 ( T_8 V_245 )
{
switch ( V_245 ) {
case V_397 :
return V_398 ;
default:
return V_399 ;
}
}
