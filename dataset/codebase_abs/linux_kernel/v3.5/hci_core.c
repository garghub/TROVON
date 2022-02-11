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
static int F_12 ( struct V_1 * V_2 , void (* F_13)( struct V_1 * V_2 , unsigned long V_29 ) ,
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
static inline int F_21 ( struct V_1 * V_2 , void (* F_13)( struct V_1 * V_2 , unsigned long V_29 ) ,
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
if ( ! F_5 ( V_46 , & V_2 -> V_47 ) ) {
F_25 ( V_39 , & V_2 -> V_8 ) ;
F_26 ( V_2 , V_17 , 0 , NULL ) ;
}
F_26 ( V_2 , V_48 , 0 , NULL ) ;
F_26 ( V_2 , V_49 , 0 , NULL ) ;
F_26 ( V_2 , V_50 , 0 , NULL ) ;
F_26 ( V_2 , V_51 , 0 , NULL ) ;
F_26 ( V_2 , V_52 , 0 , NULL ) ;
F_26 ( V_2 , V_53 , 0 , NULL ) ;
F_26 ( V_2 , V_54 , 0 , NULL ) ;
V_43 = V_55 ;
F_26 ( V_2 , V_56 , 1 , & V_43 ) ;
V_42 = F_28 ( 0x7d00 ) ;
F_26 ( V_2 , V_57 , 2 , & V_42 ) ;
F_29 ( & V_41 . V_58 , V_59 ) ;
V_41 . V_60 = 1 ;
F_26 ( V_2 , V_61 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_44 = V_62 ;
F_26 ( V_2 , V_17 , 0 , NULL ) ;
F_26 ( V_2 , V_49 , 0 , NULL ) ;
F_26 ( V_2 , V_63 , 0 , NULL ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_15 * V_16 ;
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_64 ) ) ) {
F_33 ( V_16 ) -> V_65 = V_66 ;
V_16 -> V_67 = ( void * ) V_2 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
F_35 ( & V_2 -> V_64 ) ;
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
T_4 V_78 = F_28 ( V_29 ) ;
F_4 ( L_8 , V_2 -> V_6 , V_78 ) ;
F_26 ( V_2 , V_79 , 2 , & V_78 ) ;
}
struct V_1 * F_42 ( int V_80 )
{
struct V_1 * V_2 = NULL , * V_81 ;
F_4 ( L_9 , V_80 ) ;
if ( V_80 < 0 )
return NULL ;
F_43 ( & V_82 ) ;
F_44 (d, &hci_dev_list, list) {
if ( V_81 -> V_83 == V_80 ) {
V_2 = F_45 ( V_81 ) ;
break;
}
}
F_46 ( & V_82 ) ;
return V_2 ;
}
bool F_47 ( struct V_1 * V_2 )
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
void F_48 ( struct V_1 * V_2 , int V_87 )
{
F_4 ( L_10 , V_2 -> V_6 , V_2 -> V_86 . V_87 , V_87 ) ;
if ( V_2 -> V_86 . V_87 == V_87 )
return;
switch ( V_87 ) {
case V_90 :
if ( V_2 -> V_86 . V_87 != V_91 )
F_49 ( V_2 , 0 ) ;
break;
case V_91 :
break;
case V_88 :
F_49 ( V_2 , 1 ) ;
break;
case V_89 :
break;
case V_92 :
break;
}
V_2 -> V_86 . V_87 = V_87 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_95 , * V_96 ;
F_51 (p, n, &cache->all, all) {
F_52 ( & V_95 -> V_97 ) ;
F_53 ( V_95 ) ;
}
F_54 ( & V_93 -> V_98 ) ;
F_54 ( & V_93 -> V_99 ) ;
}
struct V_94 * F_55 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_11 , V_93 , F_56 ( V_58 ) ) ;
F_44 (e, &cache->all, all) {
if ( ! F_57 ( & V_100 -> V_13 . V_58 , V_58 ) )
return V_100 ;
}
return NULL ;
}
struct V_94 * F_58 ( struct V_1 * V_2 ,
T_6 * V_58 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_11 , V_93 , F_56 ( V_58 ) ) ;
F_44 (e, &cache->unknown, list) {
if ( ! F_57 ( & V_100 -> V_13 . V_58 , V_58 ) )
return V_100 ;
}
return NULL ;
}
struct V_94 * F_59 ( struct V_1 * V_2 ,
T_6 * V_58 ,
int V_87 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_100 ;
F_4 ( L_12 , V_93 , F_56 ( V_58 ) , V_87 ) ;
F_44 (e, &cache->resolve, list) {
if ( ! F_57 ( V_58 , V_59 ) && V_100 -> V_101 == V_87 )
return V_100 ;
if ( ! F_57 ( & V_100 -> V_13 . V_58 , V_58 ) )
return V_100 ;
}
return NULL ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_94 * V_102 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_103 * V_104 = & V_93 -> V_99 ;
struct V_94 * V_95 ;
F_52 ( & V_102 -> V_105 ) ;
F_44 (p, &cache->resolve, list) {
if ( V_95 -> V_101 != V_106 &&
abs ( V_95 -> V_13 . V_107 ) >= abs ( V_102 -> V_13 . V_107 ) )
break;
V_104 = & V_95 -> V_105 ;
}
F_61 ( & V_102 -> V_105 , V_104 ) ;
}
bool F_62 ( struct V_1 * V_2 , struct V_108 * V_13 ,
bool V_109 , bool * V_110 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_94 * V_102 ;
F_4 ( L_11 , V_93 , F_56 ( & V_13 -> V_58 ) ) ;
if ( V_110 )
* V_110 = V_13 -> V_111 ;
V_102 = F_55 ( V_2 , & V_13 -> V_58 ) ;
if ( V_102 ) {
if ( V_102 -> V_13 . V_111 && V_110 )
* V_110 = true ;
if ( V_102 -> V_101 == V_112 &&
V_13 -> V_107 != V_102 -> V_13 . V_107 ) {
V_102 -> V_13 . V_107 = V_13 -> V_107 ;
F_60 ( V_2 , V_102 ) ;
}
goto V_113;
}
V_102 = F_63 ( sizeof( struct V_94 ) , V_18 ) ;
if ( ! V_102 )
return false ;
F_61 ( & V_102 -> V_97 , & V_93 -> V_97 ) ;
if ( V_109 ) {
V_102 -> V_101 = V_114 ;
} else {
V_102 -> V_101 = V_115 ;
F_61 ( & V_102 -> V_105 , & V_93 -> V_98 ) ;
}
V_113:
if ( V_109 && V_102 -> V_101 != V_114 &&
V_102 -> V_101 != V_106 ) {
V_102 -> V_101 = V_114 ;
F_52 ( & V_102 -> V_105 ) ;
}
memcpy ( & V_102 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_102 -> V_116 = V_117 ;
V_93 -> V_116 = V_117 ;
if ( V_102 -> V_101 == V_115 )
return false ;
return true ;
}
static int F_64 ( struct V_1 * V_2 , int V_118 , T_5 * V_119 )
{
struct V_84 * V_93 = & V_2 -> V_86 ;
struct V_120 * V_121 = (struct V_120 * ) V_119 ;
struct V_94 * V_100 ;
int V_122 = 0 ;
F_44 (e, &cache->all, all) {
struct V_108 * V_13 = & V_100 -> V_13 ;
if ( V_122 >= V_118 )
break;
F_29 ( & V_121 -> V_58 , & V_13 -> V_58 ) ;
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
static void F_65 ( struct V_1 * V_2 , unsigned long V_29 )
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
int F_66 ( void T_7 * V_136 )
{
T_5 T_7 * V_137 = V_136 ;
struct V_128 V_129 ;
struct V_1 * V_2 ;
int V_27 = 0 , V_138 = 0 , V_139 ;
long V_140 ;
T_5 * V_119 ;
if ( F_67 ( & V_129 , V_137 , sizeof( V_129 ) ) )
return - V_141 ;
V_2 = F_42 ( V_129 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
F_68 ( V_2 ) ;
if ( F_69 ( V_2 ) > V_144 ||
F_70 ( V_2 ) ||
V_129 . V_8 & V_145 ) {
F_50 ( V_2 ) ;
V_138 = 1 ;
}
F_71 ( V_2 ) ;
V_140 = V_129 . V_133 * F_72 ( 2000 ) ;
if ( V_138 ) {
V_27 = F_21 ( V_2 , F_65 , ( unsigned long ) & V_129 , V_140 ) ;
if ( V_27 < 0 )
goto V_146;
}
V_139 = ( V_129 . V_134 == 0 ) ? 255 : V_129 . V_134 ;
V_119 = F_73 ( sizeof( struct V_120 ) * V_139 , V_147 ) ;
if ( ! V_119 ) {
V_27 = - V_148 ;
goto V_146;
}
F_68 ( V_2 ) ;
V_129 . V_134 = F_64 ( V_2 , V_139 , V_119 ) ;
F_71 ( V_2 ) ;
F_4 ( L_14 , V_129 . V_134 ) ;
if ( ! F_74 ( V_137 , & V_129 , sizeof( V_129 ) ) ) {
V_137 += sizeof( V_129 ) ;
if ( F_74 ( V_137 , V_119 , sizeof( struct V_120 ) *
V_129 . V_134 ) )
V_27 = - V_141 ;
} else
V_27 = - V_141 ;
F_53 ( V_119 ) ;
V_146:
F_75 ( V_2 ) ;
return V_27 ;
}
int F_76 ( T_1 V_67 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_42 ( V_67 ) ;
if ( ! V_2 )
return - V_143 ;
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_22 ( V_2 ) ;
if ( F_5 ( V_149 , & V_2 -> V_150 ) ) {
V_36 = - V_143 ;
goto V_146;
}
if ( V_2 -> V_151 && F_77 ( V_2 -> V_151 ) ) {
V_36 = - V_152 ;
goto V_146;
}
if ( F_5 ( V_37 , & V_2 -> V_8 ) ) {
V_36 = - V_153 ;
goto V_146;
}
if ( F_5 ( V_154 , & V_2 -> V_47 ) )
F_25 ( V_155 , & V_2 -> V_8 ) ;
if ( V_2 -> V_68 != V_69 && ! V_156 )
F_25 ( V_155 , & V_2 -> V_8 ) ;
if ( V_2 -> V_157 ( V_2 ) ) {
V_36 = - V_158 ;
goto V_146;
}
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
F_78 ( & V_2 -> V_159 , 1 ) ;
F_25 ( V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_36 = F_12 ( V_2 , F_31 , 0 ,
F_72 ( V_160 ) ) ;
if ( F_79 ( V_2 ) )
V_36 = F_12 ( V_2 , F_37 , 0 ,
F_72 ( V_160 ) ) ;
F_80 ( V_7 , & V_2 -> V_8 ) ;
}
if ( ! V_36 ) {
F_45 ( V_2 ) ;
F_25 ( V_37 , & V_2 -> V_8 ) ;
F_1 ( V_2 , V_161 ) ;
if ( ! F_5 ( V_162 , & V_2 -> V_150 ) ) {
F_68 ( V_2 ) ;
F_81 ( V_2 , 1 ) ;
F_71 ( V_2 ) ;
}
} else {
F_82 ( & V_2 -> V_163 ) ;
F_82 ( & V_2 -> V_21 ) ;
F_82 ( & V_2 -> V_164 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_165 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
if ( V_2 -> V_12 ) {
F_83 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_167 ( V_2 ) ;
V_2 -> V_8 = 0 ;
}
V_146:
F_23 ( V_2 ) ;
F_75 ( V_2 ) ;
return V_36 ;
}
static int F_84 ( struct V_1 * V_2 )
{
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_85 ( & V_2 -> V_168 ) ;
F_11 ( V_2 , V_143 ) ;
F_22 ( V_2 ) ;
if ( ! F_86 ( V_37 , & V_2 -> V_8 ) ) {
F_87 ( & V_2 -> V_169 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
F_82 ( & V_2 -> V_163 ) ;
F_82 ( & V_2 -> V_164 ) ;
if ( V_2 -> V_170 > 0 ) {
F_88 ( & V_2 -> V_171 ) ;
V_2 -> V_170 = 0 ;
F_80 ( V_172 , & V_2 -> V_150 ) ;
}
if ( F_86 ( V_173 , & V_2 -> V_150 ) )
F_88 ( & V_2 -> V_174 ) ;
F_89 ( & V_2 -> V_175 ) ;
F_68 ( V_2 ) ;
F_50 ( V_2 ) ;
F_90 ( V_2 ) ;
F_71 ( V_2 ) ;
F_1 ( V_2 , V_176 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_78 ( & V_2 -> V_159 , 1 ) ;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) &&
F_5 ( V_46 , & V_2 -> V_47 ) ) {
F_25 ( V_7 , & V_2 -> V_8 ) ;
F_12 ( V_2 , F_24 , 0 ,
F_72 ( 250 ) ) ;
F_80 ( V_7 , & V_2 -> V_8 ) ;
}
F_82 ( & V_2 -> V_21 ) ;
F_35 ( & V_2 -> V_165 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_35 ( & V_2 -> V_177 ) ;
if ( V_2 -> V_12 ) {
F_87 ( & V_2 -> V_169 ) ;
F_83 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_167 ( V_2 ) ;
if ( ! F_86 ( V_178 , & V_2 -> V_150 ) ) {
F_68 ( V_2 ) ;
F_81 ( V_2 , 0 ) ;
F_71 ( V_2 ) ;
}
V_2 -> V_8 = 0 ;
memset ( V_2 -> V_179 , 0 , sizeof( V_2 -> V_179 ) ) ;
memset ( V_2 -> V_126 , 0 , sizeof( V_2 -> V_126 ) ) ;
F_23 ( V_2 ) ;
F_75 ( V_2 ) ;
return 0 ;
}
int F_91 ( T_1 V_67 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_42 ( V_67 ) ;
if ( ! V_2 )
return - V_143 ;
if ( F_86 ( V_178 , & V_2 -> V_150 ) )
F_88 ( & V_2 -> V_180 ) ;
V_27 = F_84 ( V_2 ) ;
F_75 ( V_2 ) ;
return V_27 ;
}
int F_92 ( T_1 V_67 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_42 ( V_67 ) ;
if ( ! V_2 )
return - V_143 ;
F_22 ( V_2 ) ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
goto V_146;
F_35 ( & V_2 -> V_165 ) ;
F_35 ( & V_2 -> V_19 ) ;
F_68 ( V_2 ) ;
F_50 ( V_2 ) ;
F_90 ( V_2 ) ;
F_71 ( V_2 ) ;
if ( V_2 -> V_166 )
V_2 -> V_166 ( V_2 ) ;
F_78 ( & V_2 -> V_159 , 1 ) ;
V_2 -> V_181 = 0 ; V_2 -> V_182 = 0 ; V_2 -> V_183 = 0 ;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) )
V_36 = F_12 ( V_2 , F_24 , 0 ,
F_72 ( V_160 ) ) ;
V_146:
F_23 ( V_2 ) ;
F_75 ( V_2 ) ;
return V_36 ;
}
int F_93 ( T_1 V_67 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_42 ( V_67 ) ;
if ( ! V_2 )
return - V_143 ;
memset ( & V_2 -> V_184 , 0 , sizeof( struct V_185 ) ) ;
F_75 ( V_2 ) ;
return V_36 ;
}
int F_94 ( unsigned int V_4 , void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_186 V_187 ;
int V_27 = 0 ;
if ( F_67 ( & V_187 , V_136 , sizeof( V_187 ) ) )
return - V_141 ;
V_2 = F_42 ( V_187 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
switch ( V_4 ) {
case V_188 :
V_27 = F_21 ( V_2 , F_39 , V_187 . V_189 ,
F_72 ( V_160 ) ) ;
break;
case V_190 :
if ( ! F_95 ( V_2 ) ) {
V_27 = - V_191 ;
break;
}
if ( ! F_5 ( V_192 , & V_2 -> V_8 ) ) {
V_27 = F_21 ( V_2 , F_39 , V_187 . V_189 ,
F_72 ( V_160 ) ) ;
if ( V_27 )
break;
}
V_27 = F_21 ( V_2 , F_40 , V_187 . V_189 ,
F_72 ( V_160 ) ) ;
break;
case V_193 :
V_27 = F_21 ( V_2 , F_38 , V_187 . V_189 ,
F_72 ( V_160 ) ) ;
break;
case V_194 :
V_27 = F_21 ( V_2 , F_41 , V_187 . V_189 ,
F_72 ( V_160 ) ) ;
break;
case V_195 :
V_2 -> V_196 = ( ( T_1 ) V_187 . V_189 ) &
( V_197 | V_198 ) ;
break;
case V_199 :
V_2 -> V_65 = ( T_1 ) V_187 . V_189 ;
break;
case V_200 :
V_2 -> V_201 = * ( ( T_1 * ) & V_187 . V_189 + 1 ) ;
V_2 -> V_202 = * ( ( T_1 * ) & V_187 . V_189 + 0 ) ;
break;
case V_203 :
V_2 -> V_204 = * ( ( T_1 * ) & V_187 . V_189 + 1 ) ;
V_2 -> V_205 = * ( ( T_1 * ) & V_187 . V_189 + 0 ) ;
break;
default:
V_27 = - V_206 ;
break;
}
F_75 ( V_2 ) ;
return V_27 ;
}
int F_96 ( void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_207 * V_208 ;
struct V_186 * V_187 ;
int V_96 = 0 , V_209 , V_27 ;
T_1 V_210 ;
if ( F_97 ( V_210 , ( T_1 T_7 * ) V_136 ) )
return - V_141 ;
if ( ! V_210 || V_210 > ( V_211 * 2 ) / sizeof( * V_187 ) )
return - V_206 ;
V_209 = sizeof( * V_208 ) + V_210 * sizeof( * V_187 ) ;
V_208 = F_63 ( V_209 , V_147 ) ;
if ( ! V_208 )
return - V_148 ;
V_187 = V_208 -> V_212 ;
F_43 ( & V_82 ) ;
F_44 (hdev, &hci_dev_list, list) {
if ( F_86 ( V_178 , & V_2 -> V_150 ) )
F_88 ( & V_2 -> V_180 ) ;
if ( ! F_5 ( V_213 , & V_2 -> V_150 ) )
F_25 ( V_214 , & V_2 -> V_150 ) ;
( V_187 + V_96 ) -> V_142 = V_2 -> V_83 ;
( V_187 + V_96 ) -> V_189 = V_2 -> V_8 ;
if ( ++ V_96 >= V_210 )
break;
}
F_46 ( & V_82 ) ;
V_208 -> V_210 = V_96 ;
V_209 = sizeof( * V_208 ) + V_96 * sizeof( * V_187 ) ;
V_27 = F_74 ( V_136 , V_208 , V_209 ) ;
F_53 ( V_208 ) ;
return V_27 ? - V_141 : 0 ;
}
int F_98 ( void T_7 * V_136 )
{
struct V_1 * V_2 ;
struct V_215 V_216 ;
int V_27 = 0 ;
if ( F_67 ( & V_216 , V_136 , sizeof( V_216 ) ) )
return - V_141 ;
V_2 = F_42 ( V_216 . V_142 ) ;
if ( ! V_2 )
return - V_143 ;
if ( F_86 ( V_178 , & V_2 -> V_150 ) )
F_89 ( & V_2 -> V_180 ) ;
if ( ! F_5 ( V_213 , & V_2 -> V_150 ) )
F_25 ( V_214 , & V_2 -> V_150 ) ;
strcpy ( V_216 . V_6 , V_2 -> V_6 ) ;
V_216 . V_58 = V_2 -> V_58 ;
V_216 . type = ( V_2 -> V_217 & 0x0f ) | ( V_2 -> V_68 << 4 ) ;
V_216 . V_8 = V_2 -> V_8 ;
V_216 . V_65 = V_2 -> V_65 ;
V_216 . V_201 = V_2 -> V_201 ;
V_216 . V_202 = V_2 -> V_202 ;
V_216 . V_204 = V_2 -> V_204 ;
V_216 . V_205 = V_2 -> V_205 ;
V_216 . V_218 = V_2 -> V_218 ;
V_216 . V_196 = V_2 -> V_196 ;
memcpy ( & V_216 . V_184 , & V_2 -> V_184 , sizeof( V_216 . V_184 ) ) ;
memcpy ( & V_216 . V_219 , & V_2 -> V_219 , sizeof( V_216 . V_219 ) ) ;
if ( F_74 ( V_136 , & V_216 , sizeof( V_216 ) ) )
V_27 = - V_141 ;
F_75 ( V_2 ) ;
return V_27 ;
}
static int F_99 ( void * V_13 , bool V_220 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( L_16 , V_2 , V_2 -> V_6 , V_220 ) ;
if ( ! V_220 )
return 0 ;
F_84 ( V_2 ) ;
return 0 ;
}
static void F_100 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 , V_223 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_76 ( V_2 -> V_83 ) < 0 )
return;
if ( F_5 ( V_178 , & V_2 -> V_150 ) )
F_102 ( & V_2 -> V_180 ,
F_72 ( V_224 ) ) ;
if ( F_86 ( V_162 , & V_2 -> V_150 ) )
F_103 ( V_2 ) ;
}
static void F_104 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 ,
V_180 . V_222 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_84 ( V_2 ) ;
}
static void F_105 ( struct V_221 * V_222 )
{
struct V_1 * V_2 ;
T_8 V_72 = V_225 ;
V_2 = F_101 ( V_222 , struct V_1 , V_171 . V_222 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_68 ( V_2 ) ;
F_26 ( V_2 , V_73 , sizeof( V_72 ) , & V_72 ) ;
V_2 -> V_170 = 0 ;
F_71 ( V_2 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_107 (p, n, &hdev->uuids) {
struct V_226 * V_227 ;
V_227 = F_108 ( V_95 , struct V_226 , V_105 ) ;
F_52 ( V_95 ) ;
F_53 ( V_227 ) ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_107 (p, n, &hdev->link_keys) {
struct V_228 * V_229 ;
V_229 = F_108 ( V_95 , struct V_228 , V_105 ) ;
F_52 ( V_95 ) ;
F_53 ( V_229 ) ;
}
return 0 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_230 * V_231 , * V_232 ;
F_51 (k, tmp, &hdev->long_term_keys, list) {
F_52 ( & V_231 -> V_105 ) ;
F_53 ( V_231 ) ;
}
return 0 ;
}
struct V_228 * F_111 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_228 * V_231 ;
F_44 (k, &hdev->link_keys, list)
if ( F_57 ( V_58 , & V_231 -> V_58 ) == 0 )
return V_231 ;
return NULL ;
}
static bool F_112 ( struct V_1 * V_2 , struct V_233 * V_234 ,
T_8 V_235 , T_8 V_236 )
{
if ( V_235 < 0x03 )
return true ;
if ( V_235 == V_237 )
return false ;
if ( V_235 == V_238 && V_236 == 0xff )
return false ;
if ( ! V_234 )
return true ;
if ( V_234 -> V_239 > 0x01 && V_234 -> V_240 > 0x01 )
return true ;
if ( V_234 -> V_239 == 0x02 || V_234 -> V_239 == 0x03 )
return true ;
if ( V_234 -> V_240 == 0x02 || V_234 -> V_240 == 0x03 )
return true ;
return false ;
}
struct V_230 * F_113 ( struct V_1 * V_2 , T_4 V_241 , T_8 rand [ 8 ] )
{
struct V_230 * V_231 ;
F_44 (k, &hdev->long_term_keys, list) {
if ( V_231 -> V_241 != V_241 ||
memcmp ( rand , V_231 -> rand , sizeof( V_231 -> rand ) ) )
continue;
return V_231 ;
}
return NULL ;
}
struct V_230 * F_114 ( struct V_1 * V_2 , T_6 * V_58 ,
T_8 V_242 )
{
struct V_230 * V_231 ;
F_44 (k, &hdev->long_term_keys, list)
if ( V_242 == V_231 -> V_243 &&
F_57 ( V_58 , & V_231 -> V_58 ) == 0 )
return V_231 ;
return NULL ;
}
int F_115 ( struct V_1 * V_2 , struct V_233 * V_234 , int V_244 ,
T_6 * V_58 , T_8 * V_245 , T_8 type , T_8 V_246 )
{
struct V_228 * V_229 , * V_247 ;
T_8 V_236 ;
bool V_248 ;
V_247 = F_111 ( V_2 , V_58 ) ;
if ( V_247 ) {
V_236 = V_247 -> type ;
V_229 = V_247 ;
} else {
V_236 = V_234 ? V_234 -> V_235 : 0xff ;
V_229 = F_63 ( sizeof( * V_229 ) , V_18 ) ;
if ( ! V_229 )
return - V_148 ;
F_61 ( & V_229 -> V_105 , & V_2 -> V_249 ) ;
}
F_4 ( L_17 , V_2 -> V_6 , F_56 ( V_58 ) , type ) ;
if ( type == V_238 &&
( ! V_234 || V_234 -> V_240 == 0xff ) &&
V_236 == 0xff ) {
type = V_250 ;
if ( V_234 )
V_234 -> V_235 = type ;
}
F_29 ( & V_229 -> V_58 , V_58 ) ;
memcpy ( V_229 -> V_245 , V_245 , 16 ) ;
V_229 -> V_246 = V_246 ;
if ( type == V_238 )
V_229 -> type = V_236 ;
else
V_229 -> type = type ;
if ( ! V_244 )
return 0 ;
V_248 = F_112 ( V_2 , V_234 , type , V_236 ) ;
F_116 ( V_2 , V_229 , V_248 ) ;
if ( V_234 )
V_234 -> V_251 = ! V_248 ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , T_6 * V_58 , T_8 V_242 , T_8 type ,
int V_244 , T_8 V_252 , T_8 V_253 [ 16 ] , T_8 V_254 , T_4
V_241 , T_8 rand [ 8 ] )
{
struct V_230 * V_229 , * V_247 ;
if ( ! ( type & V_255 ) && ! ( type & V_256 ) )
return 0 ;
V_247 = F_114 ( V_2 , V_58 , V_242 ) ;
if ( V_247 )
V_229 = V_247 ;
else {
V_229 = F_63 ( sizeof( * V_229 ) , V_18 ) ;
if ( ! V_229 )
return - V_148 ;
F_61 ( & V_229 -> V_105 , & V_2 -> V_257 ) ;
}
F_29 ( & V_229 -> V_58 , V_58 ) ;
V_229 -> V_243 = V_242 ;
memcpy ( V_229 -> V_245 , V_253 , sizeof( V_229 -> V_245 ) ) ;
V_229 -> V_252 = V_252 ;
V_229 -> V_241 = V_241 ;
V_229 -> V_254 = V_254 ;
V_229 -> type = type ;
memcpy ( V_229 -> rand , rand , sizeof( V_229 -> rand ) ) ;
if ( ! V_244 )
return 0 ;
if ( type & V_256 )
F_118 ( V_2 , V_229 , 1 ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_228 * V_229 ;
V_229 = F_111 ( V_2 , V_58 ) ;
if ( ! V_229 )
return - V_258 ;
F_4 ( L_18 , V_2 -> V_6 , F_56 ( V_58 ) ) ;
F_52 ( & V_229 -> V_105 ) ;
F_53 ( V_229 ) ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_230 * V_231 , * V_232 ;
F_51 (k, tmp, &hdev->long_term_keys, list) {
if ( F_57 ( V_58 , & V_231 -> V_58 ) )
continue;
F_4 ( L_18 , V_2 -> V_6 , F_56 ( V_58 ) ) ;
F_52 ( & V_231 -> V_105 ) ;
F_53 ( V_231 ) ;
}
return 0 ;
}
static void F_121 ( unsigned long V_136 )
{
struct V_1 * V_2 = ( void * ) V_136 ;
F_36 ( L_19 , V_2 -> V_6 ) ;
F_78 ( & V_2 -> V_159 , 1 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
struct V_259 * F_122 ( struct V_1 * V_2 ,
T_6 * V_58 )
{
struct V_259 * V_13 ;
F_44 (data, &hdev->remote_oob_data, list)
if ( F_57 ( V_58 , & V_13 -> V_58 ) == 0 )
return V_13 ;
return NULL ;
}
int F_123 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_259 * V_13 ;
V_13 = F_122 ( V_2 , V_58 ) ;
if ( ! V_13 )
return - V_258 ;
F_4 ( L_18 , V_2 -> V_6 , F_56 ( V_58 ) ) ;
F_52 ( & V_13 -> V_105 ) ;
F_53 ( V_13 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_259 * V_13 , * V_96 ;
F_51 (data, n, &hdev->remote_oob_data, list) {
F_52 ( & V_13 -> V_105 ) ;
F_53 ( V_13 ) ;
}
return 0 ;
}
int F_125 ( struct V_1 * V_2 , T_6 * V_58 , T_8 * V_260 ,
T_8 * V_261 )
{
struct V_259 * V_13 ;
V_13 = F_122 ( V_2 , V_58 ) ;
if ( ! V_13 ) {
V_13 = F_73 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_148 ;
F_29 ( & V_13 -> V_58 , V_58 ) ;
F_61 ( & V_13 -> V_105 , & V_2 -> V_262 ) ;
}
memcpy ( V_13 -> V_260 , V_260 , sizeof( V_13 -> V_260 ) ) ;
memcpy ( V_13 -> V_261 , V_261 , sizeof( V_13 -> V_261 ) ) ;
F_4 ( L_20 , V_2 -> V_6 , F_56 ( V_58 ) ) ;
return 0 ;
}
struct V_263 * F_126 ( struct V_1 * V_2 , T_6 * V_58 )
{
struct V_263 * V_264 ;
F_44 (b, &hdev->blacklist, list)
if ( F_57 ( V_58 , & V_264 -> V_58 ) == 0 )
return V_264 ;
return NULL ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_103 * V_95 , * V_96 ;
F_107 (p, n, &hdev->blacklist) {
struct V_263 * V_264 ;
V_264 = F_108 ( V_95 , struct V_263 , V_105 ) ;
F_52 ( V_95 ) ;
F_53 ( V_264 ) ;
}
return 0 ;
}
int F_128 ( struct V_1 * V_2 , T_6 * V_58 , T_8 type )
{
struct V_263 * V_265 ;
if ( F_57 ( V_58 , V_59 ) == 0 )
return - V_266 ;
if ( F_126 ( V_2 , V_58 ) )
return - V_267 ;
V_265 = F_63 ( sizeof( struct V_263 ) , V_147 ) ;
if ( ! V_265 )
return - V_148 ;
F_29 ( & V_265 -> V_58 , V_58 ) ;
F_61 ( & V_265 -> V_105 , & V_2 -> V_268 ) ;
return F_129 ( V_2 , V_58 , type ) ;
}
int F_130 ( struct V_1 * V_2 , T_6 * V_58 , T_8 type )
{
struct V_263 * V_265 ;
if ( F_57 ( V_58 , V_59 ) == 0 )
return F_127 ( V_2 ) ;
V_265 = F_126 ( V_2 , V_58 ) ;
if ( ! V_265 )
return - V_258 ;
F_52 ( & V_265 -> V_105 ) ;
F_53 ( V_265 ) ;
return F_131 ( V_2 , V_58 , type ) ;
}
static void F_132 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_269 * V_42 = (struct V_269 * ) V_29 ;
struct V_270 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . type = V_42 -> type ;
V_41 . V_271 = F_28 ( V_42 -> V_271 ) ;
V_41 . V_272 = F_28 ( V_42 -> V_272 ) ;
F_26 ( V_2 , V_273 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_133 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_274 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_275 = 1 ;
F_26 ( V_2 , V_276 , sizeof( V_41 ) , & V_41 ) ;
}
static int F_134 ( struct V_1 * V_2 , T_8 type , T_2 V_271 ,
T_2 V_272 , int V_30 )
{
long V_140 = F_72 ( 3000 ) ;
struct V_269 V_42 ;
int V_27 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_277 , & V_2 -> V_150 ) )
return - V_278 ;
V_42 . type = type ;
V_42 . V_271 = V_271 ;
V_42 . V_272 = V_272 ;
F_22 ( V_2 ) ;
V_27 = F_12 ( V_2 , F_132 , ( unsigned long ) & V_42 ,
V_140 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_2 , F_133 , 0 , V_140 ) ;
F_23 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_102 ( & V_2 -> V_175 ,
F_72 ( V_30 ) ) ;
return 0 ;
}
int F_135 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_277 , & V_2 -> V_150 ) )
return - V_153 ;
if ( F_88 ( & V_2 -> V_175 ) ) {
struct V_274 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_276 , sizeof( V_41 ) , & V_41 ) ;
}
return 0 ;
}
static void F_136 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 ,
V_175 . V_222 ) ;
struct V_274 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_26 ( V_2 , V_276 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_137 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 , V_168 ) ;
struct V_269 * V_42 = & V_2 -> V_269 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_134 ( V_2 , V_42 -> type , V_42 -> V_271 , V_42 -> V_272 ,
V_42 -> V_30 ) ;
}
int F_138 ( struct V_1 * V_2 , T_8 type , T_2 V_271 , T_2 V_272 ,
int V_30 )
{
struct V_269 * V_42 = & V_2 -> V_269 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_139 ( & V_2 -> V_168 ) )
return - V_278 ;
V_42 -> type = type ;
V_42 -> V_271 = V_271 ;
V_42 -> V_272 = V_272 ;
V_42 -> V_30 = V_30 ;
F_9 ( V_279 , & V_2 -> V_168 ) ;
return 0 ;
}
struct V_1 * F_140 ( void )
{
struct V_1 * V_2 ;
V_2 = F_63 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_65 = ( V_280 | V_281 | V_282 ) ;
V_2 -> V_283 = ( V_284 ) ;
V_2 -> V_196 = ( V_198 ) ;
V_2 -> V_285 = 0x03 ;
V_2 -> V_286 = 800 ;
V_2 -> V_287 = 80 ;
F_141 ( & V_2 -> V_288 ) ;
F_141 ( & V_2 -> V_289 ) ;
F_54 ( & V_2 -> V_290 ) ;
F_54 ( & V_2 -> V_268 ) ;
F_54 ( & V_2 -> V_291 ) ;
F_54 ( & V_2 -> V_249 ) ;
F_54 ( & V_2 -> V_257 ) ;
F_54 ( & V_2 -> V_262 ) ;
F_142 ( & V_2 -> V_164 , V_292 ) ;
F_142 ( & V_2 -> V_21 , V_293 ) ;
F_142 ( & V_2 -> V_163 , V_294 ) ;
F_142 ( & V_2 -> V_223 , F_100 ) ;
F_142 ( & V_2 -> V_168 , F_137 ) ;
F_143 ( & V_2 -> V_180 , F_104 ) ;
F_143 ( & V_2 -> V_171 , F_105 ) ;
F_143 ( & V_2 -> V_175 , F_136 ) ;
F_144 ( & V_2 -> V_64 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_144 ( & V_2 -> V_19 ) ;
F_144 ( & V_2 -> V_177 ) ;
F_145 ( & V_2 -> V_26 ) ;
F_146 ( & V_2 -> V_169 , F_121 , ( unsigned long ) V_2 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
return V_2 ;
}
void F_150 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_64 ) ;
F_151 ( & V_2 -> V_67 ) ;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_103 * V_295 , * V_95 ;
int V_83 , error ;
if ( ! V_2 -> V_157 || ! V_2 -> V_167 )
return - V_206 ;
F_153 ( & V_82 ) ;
V_83 = ( V_2 -> V_68 == V_69 ) ? 0 : 1 ;
V_295 = & V_296 ;
F_154 (p, &hci_dev_list) {
int V_297 = F_108 ( V_95 , struct V_1 , V_105 ) -> V_83 ;
if ( V_297 > V_83 )
break;
if ( V_297 == V_83 )
V_83 ++ ;
V_295 = V_95 ;
}
sprintf ( V_2 -> V_6 , L_21 , V_83 ) ;
V_2 -> V_83 = V_83 ;
F_4 ( L_22 , V_2 , V_2 -> V_6 , V_2 -> V_217 ) ;
F_61 ( & V_2 -> V_105 , V_295 ) ;
F_155 ( & V_82 ) ;
V_2 -> V_20 = F_156 ( V_2 -> V_6 , V_298 | V_299 |
V_300 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_148 ;
goto V_27;
}
error = F_157 ( V_2 ) ;
if ( error < 0 )
goto V_301;
V_2 -> V_151 = F_158 ( V_2 -> V_6 , & V_2 -> V_67 ,
V_302 , & V_303 , V_2 ) ;
if ( V_2 -> V_151 ) {
if ( F_159 ( V_2 -> V_151 ) < 0 ) {
F_160 ( V_2 -> V_151 ) ;
V_2 -> V_151 = NULL ;
}
}
F_25 ( V_178 , & V_2 -> V_150 ) ;
F_25 ( V_162 , & V_2 -> V_150 ) ;
F_161 ( & V_2 -> V_223 ) ;
F_1 ( V_2 , V_304 ) ;
F_45 ( V_2 ) ;
return V_83 ;
V_301:
F_162 ( V_2 -> V_20 ) ;
V_27:
F_153 ( & V_82 ) ;
F_52 ( & V_2 -> V_105 ) ;
F_155 ( & V_82 ) ;
return error ;
}
void F_163 ( struct V_1 * V_2 )
{
int V_305 ;
F_4 ( L_22 , V_2 , V_2 -> V_6 , V_2 -> V_217 ) ;
F_25 ( V_149 , & V_2 -> V_150 ) ;
F_153 ( & V_82 ) ;
F_52 ( & V_2 -> V_105 ) ;
F_155 ( & V_82 ) ;
F_84 ( V_2 ) ;
for ( V_305 = 0 ; V_305 < V_306 ; V_305 ++ )
F_83 ( V_2 -> V_307 [ V_305 ] ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_162 , & V_2 -> V_150 ) ) {
F_68 ( V_2 ) ;
F_164 ( V_2 ) ;
F_71 ( V_2 ) ;
}
F_165 ( ! F_166 ( & V_2 -> V_290 ) ) ;
F_1 ( V_2 , V_308 ) ;
if ( V_2 -> V_151 ) {
F_167 ( V_2 -> V_151 ) ;
F_160 ( V_2 -> V_151 ) ;
}
F_168 ( V_2 ) ;
F_162 ( V_2 -> V_20 ) ;
F_68 ( V_2 ) ;
F_127 ( V_2 ) ;
F_106 ( V_2 ) ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
F_124 ( V_2 ) ;
F_71 ( V_2 ) ;
F_75 ( V_2 ) ;
}
int F_169 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_309 ) ;
return 0 ;
}
int F_170 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_310 ) ;
return 0 ;
}
int F_171 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_67 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_83 ( V_16 ) ;
return - V_311 ;
}
F_33 ( V_16 ) -> V_312 = 1 ;
F_172 ( V_16 ) ;
F_34 ( & V_2 -> V_165 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_164 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_313 , T_5 V_80 )
{
int V_314 = 0 ;
int V_315 = 0 ;
int V_316 = V_313 ;
struct V_15 * V_16 ;
struct V_317 * V_318 ;
if ( ( type < V_319 || type > V_320 ) ||
V_80 >= V_306 )
return - V_321 ;
V_16 = V_2 -> V_307 [ V_80 ] ;
if ( ! V_16 ) {
switch ( type ) {
case V_319 :
V_314 = V_322 ;
V_315 = V_323 ;
break;
case V_320 :
V_314 = V_324 ;
V_315 = V_325 ;
break;
case V_326 :
V_314 = V_327 ;
V_315 = V_328 ;
break;
}
V_16 = F_174 ( V_314 , V_18 ) ;
if ( ! V_16 )
return - V_148 ;
V_318 = ( void * ) V_16 -> V_329 ;
V_318 -> V_330 = V_315 ;
V_318 -> V_65 = type ;
V_16 -> V_67 = ( void * ) V_2 ;
V_2 -> V_307 [ V_80 ] = V_16 ;
}
while ( V_313 ) {
V_318 = ( void * ) V_16 -> V_329 ;
V_314 = F_175 ( V_331 , V_318 -> V_330 , V_313 ) ;
memcpy ( F_176 ( V_16 , V_314 ) , V_13 , V_314 ) ;
V_313 -= V_314 ;
V_13 += V_314 ;
V_318 -> V_330 -= V_314 ;
V_316 = V_313 ;
switch ( type ) {
case V_320 :
if ( V_16 -> V_314 == V_325 ) {
struct V_332 * V_333 = V_332 ( V_16 ) ;
V_318 -> V_330 = V_333 -> V_334 ;
if ( F_177 ( V_16 ) < V_318 -> V_330 ) {
F_83 ( V_16 ) ;
V_2 -> V_307 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
case V_319 :
if ( V_16 -> V_314 == V_323 ) {
struct V_335 * V_333 = V_335 ( V_16 ) ;
V_318 -> V_330 = F_6 ( V_333 -> V_336 ) ;
if ( F_177 ( V_16 ) < V_318 -> V_330 ) {
F_83 ( V_16 ) ;
V_2 -> V_307 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
case V_326 :
if ( V_16 -> V_314 == V_328 ) {
struct V_337 * V_333 = V_337 ( V_16 ) ;
V_318 -> V_330 = V_333 -> V_336 ;
if ( F_177 ( V_16 ) < V_318 -> V_330 ) {
F_83 ( V_16 ) ;
V_2 -> V_307 [ V_80 ] = NULL ;
return - V_148 ;
}
}
break;
}
if ( V_318 -> V_330 == 0 ) {
F_33 ( V_16 ) -> V_65 = type ;
F_171 ( V_16 ) ;
V_2 -> V_307 [ V_80 ] = NULL ;
return V_316 ;
}
}
return V_316 ;
}
int F_178 ( struct V_1 * V_2 , int type , void * V_13 , int V_313 )
{
int V_338 = 0 ;
if ( type < V_319 || type > V_320 )
return - V_321 ;
while ( V_313 ) {
V_338 = F_173 ( V_2 , type , V_13 , V_313 , type - 1 ) ;
if ( V_338 < 0 )
return V_338 ;
V_13 += ( V_313 - V_338 ) ;
V_313 = V_338 ;
}
return V_338 ;
}
int F_179 ( struct V_1 * V_2 , void * V_13 , int V_313 )
{
int type ;
int V_338 = 0 ;
while ( V_313 ) {
struct V_15 * V_16 = V_2 -> V_307 [ V_339 ] ;
if ( ! V_16 ) {
struct { char type ; } * V_340 ;
V_340 = V_13 ;
type = V_340 -> type ;
V_13 ++ ;
V_313 -- ;
} else
type = F_33 ( V_16 ) -> V_65 ;
V_338 = F_173 ( V_2 , type , V_13 , V_313 ,
V_339 ) ;
if ( V_338 < 0 )
return V_338 ;
V_13 += ( V_313 - V_338 ) ;
V_313 = V_338 ;
}
return V_338 ;
}
int F_180 ( struct V_341 * V_329 )
{
F_4 ( L_23 , V_329 , V_329 -> V_6 ) ;
F_153 ( & V_342 ) ;
F_61 ( & V_329 -> V_105 , & V_343 ) ;
F_155 ( & V_342 ) ;
return 0 ;
}
int F_181 ( struct V_341 * V_329 )
{
F_4 ( L_23 , V_329 , V_329 -> V_6 ) ;
F_153 ( & V_342 ) ;
F_52 ( & V_329 -> V_105 ) ;
F_155 ( & V_342 ) ;
return 0 ;
}
static int F_182 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_67 ;
if ( ! V_2 ) {
F_83 ( V_16 ) ;
return - V_143 ;
}
F_4 ( L_24 , V_2 -> V_6 , F_33 ( V_16 ) -> V_65 , V_16 -> V_314 ) ;
F_172 ( V_16 ) ;
F_183 ( V_2 , V_16 ) ;
if ( F_184 ( & V_2 -> V_344 ) ) {
F_185 ( V_2 , V_16 ) ;
}
F_186 ( V_16 ) ;
return V_2 -> V_345 ( V_16 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_334 , void * V_42 )
{
int V_314 = V_346 + V_334 ;
struct V_10 * V_347 ;
struct V_15 * V_16 ;
F_4 ( L_25 , V_2 -> V_6 , V_14 , V_334 ) ;
V_16 = F_174 ( V_314 , V_18 ) ;
if ( ! V_16 ) {
F_36 ( L_26 , V_2 -> V_6 ) ;
return - V_148 ;
}
V_347 = (struct V_10 * ) F_176 ( V_16 , V_346 ) ;
V_347 -> V_14 = F_28 ( V_14 ) ;
V_347 -> V_334 = V_334 ;
if ( V_334 )
memcpy ( F_176 ( V_16 , V_334 ) , V_42 , V_334 ) ;
F_4 ( L_27 , V_16 -> V_314 ) ;
F_33 ( V_16 ) -> V_65 = V_66 ;
V_16 -> V_67 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_14 ;
F_34 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_187 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_347 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_347 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_347 -> V_14 != F_28 ( V_14 ) )
return NULL ;
F_4 ( L_28 , V_2 -> V_6 , V_14 ) ;
return V_2 -> V_12 -> V_13 + V_346 ;
}
static void F_188 ( struct V_15 * V_16 , T_1 V_348 , T_1 V_8 )
{
struct V_335 * V_347 ;
int V_314 = V_16 -> V_314 ;
F_189 ( V_16 , V_323 ) ;
F_190 ( V_16 ) ;
V_347 = (struct V_335 * ) F_191 ( V_16 ) ;
V_347 -> V_348 = F_28 ( F_192 ( V_348 , V_8 ) ) ;
V_347 -> V_336 = F_28 ( V_314 ) ;
}
static void F_193 ( struct V_233 * V_234 , struct V_349 * V_350 ,
struct V_15 * V_16 , T_1 V_8 )
{
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_15 * V_105 ;
V_16 -> V_314 = F_194 ( V_16 ) ;
V_16 -> V_351 = 0 ;
F_33 ( V_16 ) -> V_65 = V_319 ;
F_188 ( V_16 , V_234 -> V_348 , V_8 ) ;
V_105 = F_195 ( V_16 ) -> V_352 ;
if ( ! V_105 ) {
F_4 ( L_29 , V_2 -> V_6 , V_16 , V_16 -> V_314 ) ;
F_34 ( V_350 , V_16 ) ;
} else {
F_4 ( L_30 , V_2 -> V_6 , V_16 , V_16 -> V_314 ) ;
F_195 ( V_16 ) -> V_352 = NULL ;
F_196 ( & V_350 -> V_288 ) ;
F_197 ( V_350 , V_16 ) ;
V_8 &= ~ V_353 ;
V_8 |= V_354 ;
do {
V_16 = V_105 ; V_105 = V_105 -> V_355 ;
V_16 -> V_67 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_65 = V_319 ;
F_188 ( V_16 , V_234 -> V_348 , V_8 ) ;
F_4 ( L_30 , V_2 -> V_6 , V_16 , V_16 -> V_314 ) ;
F_197 ( V_350 , V_16 ) ;
} while ( V_105 );
F_198 ( & V_350 -> V_288 ) ;
}
}
void F_199 ( struct V_356 * V_357 , struct V_15 * V_16 , T_1 V_8 )
{
struct V_233 * V_234 = V_357 -> V_234 ;
struct V_1 * V_2 = V_234 -> V_2 ;
F_4 ( L_31 , V_2 -> V_6 , V_357 , V_8 ) ;
V_16 -> V_67 = ( void * ) V_2 ;
F_193 ( V_234 , & V_357 -> V_358 , V_16 , V_8 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_163 ) ;
}
void F_200 ( struct V_233 * V_234 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_337 V_347 ;
F_4 ( L_32 , V_2 -> V_6 , V_16 -> V_314 ) ;
V_347 . V_348 = F_28 ( V_234 -> V_348 ) ;
V_347 . V_336 = V_16 -> V_314 ;
F_189 ( V_16 , V_328 ) ;
F_190 ( V_16 ) ;
memcpy ( F_191 ( V_16 ) , & V_347 , V_328 ) ;
V_16 -> V_67 = ( void * ) V_2 ;
F_33 ( V_16 ) -> V_65 = V_326 ;
F_34 ( & V_234 -> V_358 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_163 ) ;
}
static inline struct V_233 * F_201 ( struct V_1 * V_2 , T_5 type , int * V_359 )
{
struct V_360 * V_333 = & V_2 -> V_361 ;
struct V_233 * V_234 = NULL , * V_362 ;
unsigned int V_118 = 0 , V_363 = ~ 0 ;
F_202 () ;
F_203 (c, &h->list, list) {
if ( V_362 -> type != type || F_204 ( & V_362 -> V_358 ) )
continue;
if ( V_362 -> V_87 != V_364 && V_362 -> V_87 != V_365 )
continue;
V_118 ++ ;
if ( V_362 -> V_11 < V_363 ) {
V_363 = V_362 -> V_11 ;
V_234 = V_362 ;
}
if ( F_205 ( V_2 , type ) == V_118 )
break;
}
F_206 () ;
if ( V_234 ) {
int V_366 , V_367 ;
switch ( V_234 -> type ) {
case V_368 :
V_366 = V_2 -> V_181 ;
break;
case V_369 :
case V_370 :
V_366 = V_2 -> V_182 ;
break;
case V_371 :
V_366 = V_2 -> V_372 ? V_2 -> V_183 : V_2 -> V_181 ;
break;
default:
V_366 = 0 ;
F_36 ( L_33 ) ;
}
V_367 = V_366 / V_118 ;
* V_359 = V_367 ? V_367 : 1 ;
} else
* V_359 = 0 ;
F_4 ( L_34 , V_234 , * V_359 ) ;
return V_234 ;
}
static inline void F_207 ( struct V_1 * V_2 , T_5 type )
{
struct V_360 * V_333 = & V_2 -> V_361 ;
struct V_233 * V_362 ;
F_36 ( L_35 , V_2 -> V_6 ) ;
F_202 () ;
F_203 (c, &h->list, list) {
if ( V_362 -> type == type && V_362 -> V_11 ) {
F_36 ( L_36 ,
V_2 -> V_6 , F_56 ( & V_362 -> V_373 ) ) ;
F_208 ( V_362 , 0x13 ) ;
}
}
F_206 () ;
}
static inline struct V_356 * F_209 ( struct V_1 * V_2 , T_5 type ,
int * V_359 )
{
struct V_360 * V_333 = & V_2 -> V_361 ;
struct V_356 * V_357 = NULL ;
unsigned int V_118 = 0 , V_363 = ~ 0 , V_374 = 0 ;
struct V_233 * V_234 ;
int V_366 , V_367 , V_375 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_202 () ;
F_203 (conn, &h->list, list) {
struct V_356 * V_232 ;
if ( V_234 -> type != type )
continue;
if ( V_234 -> V_87 != V_364 && V_234 -> V_87 != V_365 )
continue;
V_375 ++ ;
F_203 (tmp, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( F_204 ( & V_232 -> V_358 ) )
continue;
V_16 = F_210 ( & V_232 -> V_358 ) ;
if ( V_16 -> V_376 < V_374 )
continue;
if ( V_16 -> V_376 > V_374 ) {
V_118 = 0 ;
V_363 = ~ 0 ;
V_374 = V_16 -> V_376 ;
}
V_118 ++ ;
if ( V_234 -> V_11 < V_363 ) {
V_363 = V_234 -> V_11 ;
V_357 = V_232 ;
}
}
if ( F_205 ( V_2 , type ) == V_375 )
break;
}
F_206 () ;
if ( ! V_357 )
return NULL ;
switch ( V_357 -> V_234 -> type ) {
case V_368 :
V_366 = V_2 -> V_181 ;
break;
case V_369 :
case V_370 :
V_366 = V_2 -> V_182 ;
break;
case V_371 :
V_366 = V_2 -> V_372 ? V_2 -> V_183 : V_2 -> V_181 ;
break;
default:
V_366 = 0 ;
F_36 ( L_33 ) ;
}
V_367 = V_366 / V_118 ;
* V_359 = V_367 ? V_367 : 1 ;
F_4 ( L_37 , V_357 , * V_359 ) ;
return V_357 ;
}
static void F_211 ( struct V_1 * V_2 , T_5 type )
{
struct V_360 * V_333 = & V_2 -> V_361 ;
struct V_233 * V_234 ;
int V_118 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_202 () ;
F_203 (conn, &h->list, list) {
struct V_356 * V_357 ;
if ( V_234 -> type != type )
continue;
if ( V_234 -> V_87 != V_364 && V_234 -> V_87 != V_365 )
continue;
V_118 ++ ;
F_203 (chan, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( V_357 -> V_11 ) {
V_357 -> V_11 = 0 ;
continue;
}
if ( F_204 ( & V_357 -> V_358 ) )
continue;
V_16 = F_210 ( & V_357 -> V_358 ) ;
if ( V_16 -> V_376 >= V_377 - 1 )
continue;
V_16 -> V_376 = V_377 - 1 ;
F_4 ( L_38 , V_357 , V_16 ,
V_16 -> V_376 ) ;
}
if ( F_205 ( V_2 , type ) == V_118 )
break;
}
F_206 () ;
}
static inline int F_212 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_213 ( V_16 -> V_314 - V_323 , V_2 -> V_378 ) ;
}
static inline void F_214 ( struct V_1 * V_2 , unsigned int V_366 )
{
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
if ( ! V_366 && F_215 ( V_117 , V_2 -> V_379 +
F_72 ( V_380 ) ) )
F_207 ( V_2 , V_368 ) ;
}
}
static inline void F_216 ( struct V_1 * V_2 )
{
unsigned int V_366 = V_2 -> V_181 ;
struct V_356 * V_357 ;
struct V_15 * V_16 ;
int V_359 ;
F_214 ( V_2 , V_366 ) ;
while ( V_2 -> V_181 &&
( V_357 = F_209 ( V_2 , V_368 , & V_359 ) ) ) {
T_9 V_376 = ( F_210 ( & V_357 -> V_358 ) ) -> V_376 ;
while ( V_359 -- && ( V_16 = F_210 ( & V_357 -> V_358 ) ) ) {
F_4 ( L_39 , V_357 , V_16 ,
V_16 -> V_314 , V_16 -> V_376 ) ;
if ( V_16 -> V_376 < V_376 )
break;
V_16 = F_32 ( & V_357 -> V_358 ) ;
F_217 ( V_357 -> V_234 ,
F_33 ( V_16 ) -> V_381 ) ;
F_182 ( V_16 ) ;
V_2 -> V_379 = V_117 ;
V_2 -> V_181 -- ;
V_357 -> V_11 ++ ;
V_357 -> V_234 -> V_11 ++ ;
}
}
if ( V_366 != V_2 -> V_181 )
F_211 ( V_2 , V_368 ) ;
}
static inline void F_218 ( struct V_1 * V_2 )
{
unsigned int V_366 = V_2 -> V_382 ;
struct V_356 * V_357 ;
struct V_15 * V_16 ;
int V_359 ;
F_214 ( V_2 , V_366 ) ;
while ( V_2 -> V_382 > 0 &&
( V_357 = F_209 ( V_2 , V_368 , & V_359 ) ) ) {
T_9 V_376 = ( F_210 ( & V_357 -> V_358 ) ) -> V_376 ;
while ( V_359 > 0 && ( V_16 = F_210 ( & V_357 -> V_358 ) ) ) {
int V_383 ;
F_4 ( L_39 , V_357 , V_16 ,
V_16 -> V_314 , V_16 -> V_376 ) ;
if ( V_16 -> V_376 < V_376 )
break;
V_16 = F_32 ( & V_357 -> V_358 ) ;
V_383 = F_212 ( V_2 , V_16 ) ;
if ( V_383 > V_2 -> V_382 )
return;
F_217 ( V_357 -> V_234 ,
F_33 ( V_16 ) -> V_381 ) ;
F_182 ( V_16 ) ;
V_2 -> V_379 = V_117 ;
V_2 -> V_382 -= V_383 ;
V_359 -= V_383 ;
V_357 -> V_11 += V_383 ;
V_357 -> V_234 -> V_11 += V_383 ;
}
}
if ( V_366 != V_2 -> V_382 )
F_211 ( V_2 , V_368 ) ;
}
static inline void F_219 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_205 ( V_2 , V_368 ) )
return;
switch ( V_2 -> V_44 ) {
case V_45 :
F_216 ( V_2 ) ;
break;
case V_62 :
F_218 ( V_2 ) ;
break;
}
}
static inline void F_220 ( struct V_1 * V_2 )
{
struct V_233 * V_234 ;
struct V_15 * V_16 ;
int V_359 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_205 ( V_2 , V_369 ) )
return;
while ( V_2 -> V_182 && ( V_234 = F_201 ( V_2 , V_369 , & V_359 ) ) ) {
while ( V_359 -- && ( V_16 = F_32 ( & V_234 -> V_358 ) ) ) {
F_4 ( L_40 , V_16 , V_16 -> V_314 ) ;
F_182 ( V_16 ) ;
V_234 -> V_11 ++ ;
if ( V_234 -> V_11 == ~ 0 )
V_234 -> V_11 = 0 ;
}
}
}
static inline void F_221 ( struct V_1 * V_2 )
{
struct V_233 * V_234 ;
struct V_15 * V_16 ;
int V_359 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_205 ( V_2 , V_370 ) )
return;
while ( V_2 -> V_182 && ( V_234 = F_201 ( V_2 , V_370 , & V_359 ) ) ) {
while ( V_359 -- && ( V_16 = F_32 ( & V_234 -> V_358 ) ) ) {
F_4 ( L_40 , V_16 , V_16 -> V_314 ) ;
F_182 ( V_16 ) ;
V_234 -> V_11 ++ ;
if ( V_234 -> V_11 == ~ 0 )
V_234 -> V_11 = 0 ;
}
}
}
static inline void F_222 ( struct V_1 * V_2 )
{
struct V_356 * V_357 ;
struct V_15 * V_16 ;
int V_359 , V_366 , V_232 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_205 ( V_2 , V_371 ) )
return;
if ( ! F_5 ( V_155 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_183 && V_2 -> V_384 &&
F_215 ( V_117 , V_2 -> V_385 + V_386 * 45 ) )
F_207 ( V_2 , V_371 ) ;
}
V_366 = V_2 -> V_384 ? V_2 -> V_183 : V_2 -> V_181 ;
V_232 = V_366 ;
while ( V_366 && ( V_357 = F_209 ( V_2 , V_371 , & V_359 ) ) ) {
T_9 V_376 = ( F_210 ( & V_357 -> V_358 ) ) -> V_376 ;
while ( V_359 -- && ( V_16 = F_210 ( & V_357 -> V_358 ) ) ) {
F_4 ( L_39 , V_357 , V_16 ,
V_16 -> V_314 , V_16 -> V_376 ) ;
if ( V_16 -> V_376 < V_376 )
break;
V_16 = F_32 ( & V_357 -> V_358 ) ;
F_182 ( V_16 ) ;
V_2 -> V_385 = V_117 ;
V_366 -- ;
V_357 -> V_11 ++ ;
V_357 -> V_234 -> V_11 ++ ;
}
}
if ( V_2 -> V_384 )
V_2 -> V_183 = V_366 ;
else
V_2 -> V_181 = V_366 ;
if ( V_366 != V_232 )
F_211 ( V_2 , V_371 ) ;
}
static void V_294 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 , V_163 ) ;
struct V_15 * V_16 ;
F_4 ( L_41 , V_2 -> V_6 , V_2 -> V_181 ,
V_2 -> V_182 , V_2 -> V_183 ) ;
F_219 ( V_2 ) ;
F_220 ( V_2 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_177 ) ) )
F_182 ( V_16 ) ;
}
static inline void F_223 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_335 * V_347 = ( void * ) V_16 -> V_13 ;
struct V_233 * V_234 ;
T_1 V_348 , V_8 ;
F_224 ( V_16 , V_323 ) ;
V_348 = F_6 ( V_347 -> V_348 ) ;
V_8 = F_225 ( V_348 ) ;
V_348 = F_226 ( V_348 ) ;
F_4 ( L_42 , V_2 -> V_6 , V_16 -> V_314 , V_348 , V_8 ) ;
V_2 -> V_184 . V_387 ++ ;
F_68 ( V_2 ) ;
V_234 = F_227 ( V_2 , V_348 ) ;
F_71 ( V_2 ) ;
if ( V_234 ) {
F_217 ( V_234 , V_388 ) ;
F_68 ( V_2 ) ;
if ( F_5 ( V_213 , & V_2 -> V_150 ) &&
! F_228 ( V_389 , & V_234 -> V_8 ) )
F_229 ( V_2 , & V_234 -> V_373 , V_234 -> type ,
V_234 -> V_390 , 0 , NULL , 0 ,
V_234 -> V_126 ) ;
F_71 ( V_2 ) ;
F_230 ( V_234 , V_16 , V_8 ) ;
return;
} else {
F_36 ( L_43 ,
V_2 -> V_6 , V_348 ) ;
}
F_83 ( V_16 ) ;
}
static inline void F_231 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_337 * V_347 = ( void * ) V_16 -> V_13 ;
struct V_233 * V_234 ;
T_1 V_348 ;
F_224 ( V_16 , V_328 ) ;
V_348 = F_6 ( V_347 -> V_348 ) ;
F_4 ( L_44 , V_2 -> V_6 , V_16 -> V_314 , V_348 ) ;
V_2 -> V_184 . V_391 ++ ;
F_68 ( V_2 ) ;
V_234 = F_227 ( V_2 , V_348 ) ;
F_71 ( V_2 ) ;
if ( V_234 ) {
F_232 ( V_234 , V_16 ) ;
return;
} else {
F_36 ( L_45 ,
V_2 -> V_6 , V_348 ) ;
}
F_83 ( V_16 ) ;
}
static void V_292 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 , V_164 ) ;
struct V_15 * V_16 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
while ( ( V_16 = F_32 ( & V_2 -> V_165 ) ) ) {
F_183 ( V_2 , V_16 ) ;
if ( F_184 ( & V_2 -> V_344 ) ) {
F_185 ( V_2 , V_16 ) ;
}
if ( F_5 ( V_155 , & V_2 -> V_8 ) ) {
F_83 ( V_16 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_33 ( V_16 ) -> V_65 ) {
case V_319 :
case V_326 :
F_83 ( V_16 ) ;
continue;
}
}
switch ( F_33 ( V_16 ) -> V_65 ) {
case V_320 :
F_4 ( L_46 , V_2 -> V_6 ) ;
F_233 ( V_2 , V_16 ) ;
break;
case V_319 :
F_4 ( L_47 , V_2 -> V_6 ) ;
F_223 ( V_2 , V_16 ) ;
break;
case V_326 :
F_4 ( L_48 , V_2 -> V_6 ) ;
F_231 ( V_2 , V_16 ) ;
break;
default:
F_83 ( V_16 ) ;
break;
}
}
}
static void V_293 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 , V_21 ) ;
struct V_15 * V_16 ;
F_4 ( L_49 , V_2 -> V_6 , F_184 ( & V_2 -> V_159 ) ) ;
if ( F_184 ( & V_2 -> V_159 ) ) {
V_16 = F_32 ( & V_2 -> V_19 ) ;
if ( ! V_16 )
return;
F_83 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_7 ( V_16 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_234 ( & V_2 -> V_159 ) ;
F_182 ( V_16 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_235 ( & V_2 -> V_169 ) ;
else
F_236 ( & V_2 -> V_169 ,
V_117 + F_72 ( V_392 ) ) ;
} else {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_237 ( struct V_1 * V_2 , T_8 V_133 )
{
T_8 V_132 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_130 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_131 , & V_2 -> V_8 ) )
return - V_278 ;
F_50 ( V_2 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( & V_41 . V_132 , V_132 , sizeof( V_41 . V_132 ) ) ;
V_41 . V_133 = V_133 ;
return F_26 ( V_2 , V_135 , sizeof( V_41 ) , & V_41 ) ;
}
int F_238 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_131 , & V_2 -> V_8 ) )
return - V_153 ;
return F_26 ( V_2 , V_393 , 0 , NULL ) ;
}
T_8 F_239 ( T_8 V_243 )
{
switch ( V_243 ) {
case V_394 :
return V_395 ;
default:
return V_396 ;
}
}
