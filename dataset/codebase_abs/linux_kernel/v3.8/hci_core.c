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
V_2 -> V_40 = V_41 ;
F_26 ( V_2 , V_42 , 0 , NULL ) ;
F_26 ( V_2 , V_43 , 0 , NULL ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_40 = V_44 ;
F_26 ( V_2 , V_43 , 0 , NULL ) ;
F_26 ( V_2 , V_45 , 0 , NULL ) ;
F_26 ( V_2 , V_46 , 0 , NULL ) ;
}
static void F_29 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_15 * V_16 ;
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
while ( ( V_16 = F_30 ( & V_2 -> V_47 ) ) ) {
F_31 ( V_16 ) -> V_48 = V_49 ;
V_16 -> V_50 = ( void * ) V_2 ;
F_32 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
F_33 ( & V_2 -> V_47 ) ;
if ( ! F_5 ( V_51 , & V_2 -> V_52 ) )
F_24 ( V_2 , 0 ) ;
switch ( V_2 -> V_53 ) {
case V_54 :
F_27 ( V_2 ) ;
break;
case V_55 :
F_28 ( V_2 ) ;
break;
default:
F_34 ( L_6 , V_2 -> V_53 ) ;
break;
}
}
static void F_35 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_56 = V_29 ;
F_4 ( L_7 , V_2 -> V_6 , V_56 ) ;
F_26 ( V_2 , V_57 , 1 , & V_56 ) ;
}
static void F_36 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_58 = V_29 ;
F_4 ( L_7 , V_2 -> V_6 , V_58 ) ;
F_26 ( V_2 , V_59 , 1 , & V_58 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_60 = V_29 ;
F_4 ( L_7 , V_2 -> V_6 , V_60 ) ;
F_26 ( V_2 , V_61 , 1 , & V_60 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_5 V_62 = F_39 ( V_29 ) ;
F_4 ( L_7 , V_2 -> V_6 , V_62 ) ;
F_26 ( V_2 , V_63 , 2 , & V_62 ) ;
}
struct V_1 * F_40 ( int V_64 )
{
struct V_1 * V_2 = NULL , * V_65 ;
F_4 ( L_8 , V_64 ) ;
if ( V_64 < 0 )
return NULL ;
F_41 ( & V_66 ) ;
F_42 (d, &hci_dev_list, list) {
if ( V_65 -> V_67 == V_64 ) {
V_2 = F_43 ( V_65 ) ;
break;
}
}
F_44 ( & V_66 ) ;
return V_2 ;
}
bool F_45 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = & V_2 -> V_70 ;
switch ( V_69 -> V_71 ) {
case V_72 :
case V_73 :
return true ;
default:
return false ;
}
}
void F_46 ( struct V_1 * V_2 , int V_71 )
{
F_4 ( L_9 , V_2 -> V_6 , V_2 -> V_70 . V_71 , V_71 ) ;
if ( V_2 -> V_70 . V_71 == V_71 )
return;
switch ( V_71 ) {
case V_74 :
if ( V_2 -> V_70 . V_71 != V_75 )
F_47 ( V_2 , 0 ) ;
break;
case V_75 :
break;
case V_72 :
F_47 ( V_2 , 1 ) ;
break;
case V_73 :
break;
case V_76 :
break;
}
V_2 -> V_70 . V_71 = V_71 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_78 * V_79 , * V_80 ;
F_49 (p, n, &cache->all, all) {
F_50 ( & V_79 -> V_81 ) ;
F_51 ( V_79 ) ;
}
F_52 ( & V_77 -> V_82 ) ;
F_52 ( & V_77 -> V_83 ) ;
}
struct V_78 * F_53 ( struct V_1 * V_2 ,
T_6 * V_84 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_78 * V_85 ;
F_4 ( L_10 , V_77 , V_84 ) ;
F_42 (e, &cache->all, all) {
if ( ! F_54 ( & V_85 -> V_13 . V_84 , V_84 ) )
return V_85 ;
}
return NULL ;
}
struct V_78 * F_55 ( struct V_1 * V_2 ,
T_6 * V_84 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_78 * V_85 ;
F_4 ( L_10 , V_77 , V_84 ) ;
F_42 (e, &cache->unknown, list) {
if ( ! F_54 ( & V_85 -> V_13 . V_84 , V_84 ) )
return V_85 ;
}
return NULL ;
}
struct V_78 * F_56 ( struct V_1 * V_2 ,
T_6 * V_84 ,
int V_71 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_78 * V_85 ;
F_4 ( L_11 , V_77 , V_84 , V_71 ) ;
F_42 (e, &cache->resolve, list) {
if ( ! F_54 ( V_84 , V_86 ) && V_85 -> V_87 == V_71 )
return V_85 ;
if ( ! F_54 ( & V_85 -> V_13 . V_84 , V_84 ) )
return V_85 ;
}
return NULL ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_78 * V_88 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_89 * V_90 = & V_77 -> V_83 ;
struct V_78 * V_79 ;
F_50 ( & V_88 -> V_91 ) ;
F_42 (p, &cache->resolve, list) {
if ( V_79 -> V_87 != V_92 &&
abs ( V_79 -> V_13 . V_93 ) >= abs ( V_88 -> V_13 . V_93 ) )
break;
V_90 = & V_79 -> V_91 ;
}
F_58 ( & V_88 -> V_91 , V_90 ) ;
}
bool F_59 ( struct V_1 * V_2 , struct V_94 * V_13 ,
bool V_95 , bool * V_96 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_78 * V_88 ;
F_4 ( L_10 , V_77 , & V_13 -> V_84 ) ;
F_60 ( V_2 , & V_13 -> V_84 ) ;
if ( V_96 )
* V_96 = V_13 -> V_97 ;
V_88 = F_53 ( V_2 , & V_13 -> V_84 ) ;
if ( V_88 ) {
if ( V_88 -> V_13 . V_97 && V_96 )
* V_96 = true ;
if ( V_88 -> V_87 == V_98 &&
V_13 -> V_93 != V_88 -> V_13 . V_93 ) {
V_88 -> V_13 . V_93 = V_13 -> V_93 ;
F_57 ( V_2 , V_88 ) ;
}
goto V_99;
}
V_88 = F_61 ( sizeof( struct V_78 ) , V_18 ) ;
if ( ! V_88 )
return false ;
F_58 ( & V_88 -> V_81 , & V_77 -> V_81 ) ;
if ( V_95 ) {
V_88 -> V_87 = V_100 ;
} else {
V_88 -> V_87 = V_101 ;
F_58 ( & V_88 -> V_91 , & V_77 -> V_82 ) ;
}
V_99:
if ( V_95 && V_88 -> V_87 != V_100 &&
V_88 -> V_87 != V_92 ) {
V_88 -> V_87 = V_100 ;
F_50 ( & V_88 -> V_91 ) ;
}
memcpy ( & V_88 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_88 -> V_102 = V_103 ;
V_77 -> V_102 = V_103 ;
if ( V_88 -> V_87 == V_101 )
return false ;
return true ;
}
static int F_62 ( struct V_1 * V_2 , int V_104 , T_4 * V_105 )
{
struct V_68 * V_77 = & V_2 -> V_70 ;
struct V_106 * V_107 = (struct V_106 * ) V_105 ;
struct V_78 * V_85 ;
int V_108 = 0 ;
F_42 (e, &cache->all, all) {
struct V_94 * V_13 = & V_85 -> V_13 ;
if ( V_108 >= V_104 )
break;
F_63 ( & V_107 -> V_84 , & V_13 -> V_84 ) ;
V_107 -> V_109 = V_13 -> V_109 ;
V_107 -> V_110 = V_13 -> V_110 ;
V_107 -> V_111 = V_13 -> V_111 ;
memcpy ( V_107 -> V_112 , V_13 -> V_112 , 3 ) ;
V_107 -> V_113 = V_13 -> V_113 ;
V_107 ++ ;
V_108 ++ ;
}
F_4 ( L_12 , V_77 , V_108 ) ;
return V_108 ;
}
static void F_64 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_114 * V_115 = (struct V_114 * ) V_29 ;
struct V_116 V_117 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_118 , & V_2 -> V_8 ) )
return;
memcpy ( & V_117 . V_119 , & V_115 -> V_119 , 3 ) ;
V_117 . V_120 = V_115 -> V_120 ;
V_117 . V_121 = V_115 -> V_121 ;
F_26 ( V_2 , V_122 , sizeof( V_117 ) , & V_117 ) ;
}
int F_65 ( void T_7 * V_123 )
{
T_4 T_7 * V_124 = V_123 ;
struct V_114 V_115 ;
struct V_1 * V_2 ;
int V_27 = 0 , V_125 = 0 , V_126 ;
long V_127 ;
T_4 * V_105 ;
if ( F_66 ( & V_115 , V_124 , sizeof( V_115 ) ) )
return - V_128 ;
V_2 = F_40 ( V_115 . V_129 ) ;
if ( ! V_2 )
return - V_130 ;
F_67 ( V_2 ) ;
if ( F_68 ( V_2 ) > V_131 ||
F_69 ( V_2 ) || V_115 . V_8 & V_132 ) {
F_48 ( V_2 ) ;
V_125 = 1 ;
}
F_70 ( V_2 ) ;
V_127 = V_115 . V_120 * F_71 ( 2000 ) ;
if ( V_125 ) {
V_27 = F_21 ( V_2 , F_64 , ( unsigned long ) & V_115 , V_127 ) ;
if ( V_27 < 0 )
goto V_133;
}
V_126 = ( V_115 . V_121 == 0 ) ? 255 : V_115 . V_121 ;
V_105 = F_72 ( sizeof( struct V_106 ) * V_126 , V_134 ) ;
if ( ! V_105 ) {
V_27 = - V_135 ;
goto V_133;
}
F_67 ( V_2 ) ;
V_115 . V_121 = F_62 ( V_2 , V_126 , V_105 ) ;
F_70 ( V_2 ) ;
F_4 ( L_14 , V_115 . V_121 ) ;
if ( ! F_73 ( V_124 , & V_115 , sizeof( V_115 ) ) ) {
V_124 += sizeof( V_115 ) ;
if ( F_73 ( V_124 , V_105 , sizeof( struct V_106 ) *
V_115 . V_121 ) )
V_27 = - V_128 ;
} else
V_27 = - V_128 ;
F_51 ( V_105 ) ;
V_133:
F_74 ( V_2 ) ;
return V_27 ;
}
static T_8 F_75 ( struct V_1 * V_2 , T_8 * V_124 )
{
T_8 V_136 = 0 , V_8 = 0 ;
T_9 V_137 ;
if ( F_5 ( V_138 , & V_2 -> V_139 ) )
V_8 |= V_140 ;
if ( ! F_76 ( V_2 ) )
V_8 |= V_141 ;
if ( F_77 ( V_2 ) )
V_8 |= V_142 ;
if ( F_78 ( V_2 ) )
V_8 |= V_143 ;
if ( V_8 ) {
F_4 ( L_15 , V_8 ) ;
V_124 [ 0 ] = 2 ;
V_124 [ 1 ] = V_144 ;
V_124 [ 2 ] = V_8 ;
V_136 += 3 ;
V_124 += 3 ;
}
if ( V_2 -> V_145 != V_146 ) {
V_124 [ 0 ] = 2 ;
V_124 [ 1 ] = V_147 ;
V_124 [ 2 ] = ( T_8 ) V_2 -> V_145 ;
V_136 += 3 ;
V_124 += 3 ;
}
V_137 = strlen ( V_2 -> V_148 ) ;
if ( V_137 > 0 ) {
T_9 V_149 = V_150 - V_136 - 2 ;
if ( V_137 > V_149 ) {
V_137 = V_149 ;
V_124 [ 1 ] = V_151 ;
} else
V_124 [ 1 ] = V_152 ;
V_124 [ 0 ] = V_137 + 1 ;
memcpy ( V_124 + 2 , V_2 -> V_148 , V_137 ) ;
V_136 += ( V_137 + 2 ) ;
V_124 += ( V_137 + 2 ) ;
}
return V_136 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_153 V_117 ;
T_8 V_154 ;
int V_27 ;
F_67 ( V_2 ) ;
if ( ! F_80 ( V_2 ) ) {
V_27 = - V_155 ;
goto V_156;
}
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_154 = F_75 ( V_2 , V_117 . V_13 ) ;
if ( V_2 -> V_157 == V_154 &&
memcmp ( V_117 . V_13 , V_2 -> V_158 , V_154 ) == 0 ) {
V_27 = 0 ;
goto V_156;
}
memcpy ( V_2 -> V_158 , V_117 . V_13 , sizeof( V_117 . V_13 ) ) ;
V_2 -> V_157 = V_154 ;
V_117 . V_120 = V_154 ;
V_27 = F_26 ( V_2 , V_159 , sizeof( V_117 ) , & V_117 ) ;
V_156:
F_70 ( V_2 ) ;
return V_27 ;
}
int F_81 ( T_1 V_50 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_40 ( V_50 ) ;
if ( ! V_2 )
return - V_130 ;
F_4 ( L_16 , V_2 -> V_6 , V_2 ) ;
F_22 ( V_2 ) ;
if ( F_5 ( V_160 , & V_2 -> V_139 ) ) {
V_36 = - V_130 ;
goto V_133;
}
if ( V_2 -> V_161 && F_82 ( V_2 -> V_161 ) ) {
V_36 = - V_162 ;
goto V_133;
}
if ( F_5 ( V_37 , & V_2 -> V_8 ) ) {
V_36 = - V_163 ;
goto V_133;
}
if ( F_5 ( V_164 , & V_2 -> V_52 ) )
F_25 ( V_165 , & V_2 -> V_8 ) ;
if ( V_2 -> V_53 != V_54 && ! V_166 )
F_25 ( V_165 , & V_2 -> V_8 ) ;
if ( V_2 -> V_167 ( V_2 ) ) {
V_36 = - V_168 ;
goto V_133;
}
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) ) {
F_83 ( & V_2 -> V_169 , 1 ) ;
F_25 ( V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_36 = F_12 ( V_2 , F_29 , 0 , V_170 ) ;
F_84 ( V_7 , & V_2 -> V_8 ) ;
}
if ( ! V_36 ) {
F_43 ( V_2 ) ;
F_25 ( V_37 , & V_2 -> V_8 ) ;
F_1 ( V_2 , V_171 ) ;
F_79 ( V_2 ) ;
if ( ! F_5 ( V_172 , & V_2 -> V_139 ) &&
F_85 ( V_2 ) ) {
F_67 ( V_2 ) ;
F_86 ( V_2 , 1 ) ;
F_70 ( V_2 ) ;
}
} else {
F_87 ( & V_2 -> V_173 ) ;
F_87 ( & V_2 -> V_21 ) ;
F_87 ( & V_2 -> V_174 ) ;
F_33 ( & V_2 -> V_19 ) ;
F_33 ( & V_2 -> V_175 ) ;
if ( V_2 -> V_176 )
V_2 -> V_176 ( V_2 ) ;
if ( V_2 -> V_12 ) {
F_88 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_177 ( V_2 ) ;
V_2 -> V_8 = 0 ;
}
V_133:
F_23 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
static int F_89 ( struct V_1 * V_2 )
{
F_4 ( L_16 , V_2 -> V_6 , V_2 ) ;
F_90 ( & V_2 -> V_178 ) ;
F_91 ( & V_2 -> V_179 ) ;
F_11 ( V_2 , V_130 ) ;
F_22 ( V_2 ) ;
if ( ! F_92 ( V_37 , & V_2 -> V_8 ) ) {
F_93 ( & V_2 -> V_180 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
F_87 ( & V_2 -> V_173 ) ;
F_87 ( & V_2 -> V_174 ) ;
if ( V_2 -> V_181 > 0 ) {
F_91 ( & V_2 -> V_182 ) ;
V_2 -> V_181 = 0 ;
F_84 ( V_183 , & V_2 -> V_139 ) ;
}
if ( F_92 ( V_184 , & V_2 -> V_139 ) )
F_91 ( & V_2 -> V_185 ) ;
F_94 ( & V_2 -> V_186 ) ;
F_67 ( V_2 ) ;
F_48 ( V_2 ) ;
F_95 ( V_2 ) ;
F_70 ( V_2 ) ;
F_1 ( V_2 , V_187 ) ;
if ( V_2 -> V_176 )
V_2 -> V_176 ( V_2 ) ;
F_33 ( & V_2 -> V_19 ) ;
F_83 ( & V_2 -> V_169 , 1 ) ;
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) &&
F_5 ( V_51 , & V_2 -> V_52 ) ) {
F_25 ( V_7 , & V_2 -> V_8 ) ;
F_12 ( V_2 , F_24 , 0 , V_188 ) ;
F_84 ( V_7 , & V_2 -> V_8 ) ;
}
F_87 ( & V_2 -> V_21 ) ;
F_33 ( & V_2 -> V_175 ) ;
F_33 ( & V_2 -> V_19 ) ;
F_33 ( & V_2 -> V_189 ) ;
if ( V_2 -> V_12 ) {
F_93 ( & V_2 -> V_180 ) ;
F_88 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_177 ( V_2 ) ;
if ( ! F_92 ( V_190 , & V_2 -> V_139 ) &&
F_85 ( V_2 ) ) {
F_67 ( V_2 ) ;
F_86 ( V_2 , 0 ) ;
F_70 ( V_2 ) ;
}
V_2 -> V_8 = 0 ;
V_2 -> V_191 = 0 ;
memset ( V_2 -> V_192 , 0 , sizeof( V_2 -> V_192 ) ) ;
memset ( V_2 -> V_112 , 0 , sizeof( V_2 -> V_112 ) ) ;
F_23 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
int F_96 ( T_1 V_50 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_40 ( V_50 ) ;
if ( ! V_2 )
return - V_130 ;
if ( F_92 ( V_190 , & V_2 -> V_139 ) )
F_91 ( & V_2 -> V_179 ) ;
V_27 = F_89 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_27 ;
}
int F_97 ( T_1 V_50 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_40 ( V_50 ) ;
if ( ! V_2 )
return - V_130 ;
F_22 ( V_2 ) ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
goto V_133;
F_33 ( & V_2 -> V_175 ) ;
F_33 ( & V_2 -> V_19 ) ;
F_67 ( V_2 ) ;
F_48 ( V_2 ) ;
F_95 ( V_2 ) ;
F_70 ( V_2 ) ;
if ( V_2 -> V_176 )
V_2 -> V_176 ( V_2 ) ;
F_83 ( & V_2 -> V_169 , 1 ) ;
V_2 -> V_193 = 0 ; V_2 -> V_194 = 0 ; V_2 -> V_195 = 0 ;
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) )
V_36 = F_12 ( V_2 , F_24 , 0 , V_170 ) ;
V_133:
F_23 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
int F_98 ( T_1 V_50 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_40 ( V_50 ) ;
if ( ! V_2 )
return - V_130 ;
memset ( & V_2 -> V_196 , 0 , sizeof( struct V_197 ) ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
int F_99 ( unsigned int V_4 , void T_7 * V_123 )
{
struct V_1 * V_2 ;
struct V_198 V_199 ;
int V_27 = 0 ;
if ( F_66 ( & V_199 , V_123 , sizeof( V_199 ) ) )
return - V_128 ;
V_2 = F_40 ( V_199 . V_129 ) ;
if ( ! V_2 )
return - V_130 ;
switch ( V_4 ) {
case V_200 :
V_27 = F_21 ( V_2 , F_36 , V_199 . V_201 ,
V_170 ) ;
break;
case V_202 :
if ( ! F_100 ( V_2 ) ) {
V_27 = - V_203 ;
break;
}
if ( ! F_5 ( V_204 , & V_2 -> V_8 ) ) {
V_27 = F_21 ( V_2 , F_36 , V_199 . V_201 ,
V_170 ) ;
if ( V_27 )
break;
}
V_27 = F_21 ( V_2 , F_37 , V_199 . V_201 ,
V_170 ) ;
break;
case V_205 :
V_27 = F_21 ( V_2 , F_35 , V_199 . V_201 ,
V_170 ) ;
break;
case V_206 :
V_27 = F_21 ( V_2 , F_38 , V_199 . V_201 ,
V_170 ) ;
break;
case V_207 :
V_2 -> V_208 = ( ( T_1 ) V_199 . V_201 ) &
( V_209 | V_210 ) ;
break;
case V_211 :
V_2 -> V_48 = ( T_1 ) V_199 . V_201 ;
break;
case V_212 :
V_2 -> V_213 = * ( ( T_1 * ) & V_199 . V_201 + 1 ) ;
V_2 -> V_214 = * ( ( T_1 * ) & V_199 . V_201 + 0 ) ;
break;
case V_215 :
V_2 -> V_216 = * ( ( T_1 * ) & V_199 . V_201 + 1 ) ;
V_2 -> V_217 = * ( ( T_1 * ) & V_199 . V_201 + 0 ) ;
break;
default:
V_27 = - V_155 ;
break;
}
F_74 ( V_2 ) ;
return V_27 ;
}
int F_101 ( void T_7 * V_123 )
{
struct V_1 * V_2 ;
struct V_218 * V_219 ;
struct V_198 * V_199 ;
int V_80 = 0 , V_220 , V_27 ;
T_1 V_221 ;
if ( F_102 ( V_221 , ( T_1 T_7 * ) V_123 ) )
return - V_128 ;
if ( ! V_221 || V_221 > ( V_222 * 2 ) / sizeof( * V_199 ) )
return - V_155 ;
V_220 = sizeof( * V_219 ) + V_221 * sizeof( * V_199 ) ;
V_219 = F_61 ( V_220 , V_134 ) ;
if ( ! V_219 )
return - V_135 ;
V_199 = V_219 -> V_223 ;
F_41 ( & V_66 ) ;
F_42 (hdev, &hci_dev_list, list) {
if ( F_92 ( V_190 , & V_2 -> V_139 ) )
F_91 ( & V_2 -> V_179 ) ;
if ( ! F_5 ( V_224 , & V_2 -> V_139 ) )
F_25 ( V_225 , & V_2 -> V_139 ) ;
( V_199 + V_80 ) -> V_129 = V_2 -> V_67 ;
( V_199 + V_80 ) -> V_201 = V_2 -> V_8 ;
if ( ++ V_80 >= V_221 )
break;
}
F_44 ( & V_66 ) ;
V_219 -> V_221 = V_80 ;
V_220 = sizeof( * V_219 ) + V_80 * sizeof( * V_199 ) ;
V_27 = F_73 ( V_123 , V_219 , V_220 ) ;
F_51 ( V_219 ) ;
return V_27 ? - V_128 : 0 ;
}
int F_103 ( void T_7 * V_123 )
{
struct V_1 * V_2 ;
struct V_226 V_227 ;
int V_27 = 0 ;
if ( F_66 ( & V_227 , V_123 , sizeof( V_227 ) ) )
return - V_128 ;
V_2 = F_40 ( V_227 . V_129 ) ;
if ( ! V_2 )
return - V_130 ;
if ( F_92 ( V_190 , & V_2 -> V_139 ) )
F_94 ( & V_2 -> V_179 ) ;
if ( ! F_5 ( V_224 , & V_2 -> V_139 ) )
F_25 ( V_225 , & V_2 -> V_139 ) ;
strcpy ( V_227 . V_6 , V_2 -> V_6 ) ;
V_227 . V_84 = V_2 -> V_84 ;
V_227 . type = ( V_2 -> V_228 & 0x0f ) | ( V_2 -> V_53 << 4 ) ;
V_227 . V_8 = V_2 -> V_8 ;
V_227 . V_48 = V_2 -> V_48 ;
if ( F_76 ( V_2 ) ) {
V_227 . V_213 = V_2 -> V_213 ;
V_227 . V_214 = V_2 -> V_214 ;
V_227 . V_216 = V_2 -> V_216 ;
V_227 . V_217 = V_2 -> V_217 ;
} else {
V_227 . V_213 = V_2 -> V_229 ;
V_227 . V_214 = V_2 -> V_230 ;
V_227 . V_216 = 0 ;
V_227 . V_217 = 0 ;
}
V_227 . V_231 = V_2 -> V_231 ;
V_227 . V_208 = V_2 -> V_208 ;
memcpy ( & V_227 . V_196 , & V_2 -> V_196 , sizeof( V_227 . V_196 ) ) ;
memcpy ( & V_227 . V_232 , & V_2 -> V_232 , sizeof( V_227 . V_232 ) ) ;
if ( F_73 ( V_123 , & V_227 , sizeof( V_227 ) ) )
V_27 = - V_128 ;
F_74 ( V_2 ) ;
return V_27 ;
}
static int F_104 ( void * V_13 , bool V_233 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( L_17 , V_2 , V_2 -> V_6 , V_233 ) ;
if ( ! V_233 )
return 0 ;
F_89 ( V_2 ) ;
return 0 ;
}
static void F_105 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_236 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_81 ( V_2 -> V_67 ) < 0 )
return;
if ( F_5 ( V_190 , & V_2 -> V_139 ) )
F_107 ( & V_2 -> V_179 , V_237 ) ;
if ( F_92 ( V_172 , & V_2 -> V_139 ) )
F_108 ( V_2 ) ;
}
static void F_109 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 ,
V_179 . V_235 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_89 ( V_2 ) ;
}
static void F_110 ( struct V_234 * V_235 )
{
struct V_1 * V_2 ;
T_8 V_56 = V_238 ;
V_2 = F_106 ( V_235 , struct V_1 , V_182 . V_235 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_67 ( V_2 ) ;
F_26 ( V_2 , V_57 , sizeof( V_56 ) , & V_56 ) ;
V_2 -> V_181 = 0 ;
F_70 ( V_2 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_89 * V_79 , * V_80 ;
F_112 (p, n, &hdev->uuids) {
struct V_239 * V_240 ;
V_240 = F_113 ( V_79 , struct V_239 , V_91 ) ;
F_50 ( V_79 ) ;
F_51 ( V_240 ) ;
}
return 0 ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_89 * V_79 , * V_80 ;
F_112 (p, n, &hdev->link_keys) {
struct V_241 * V_242 ;
V_242 = F_113 ( V_79 , struct V_241 , V_91 ) ;
F_50 ( V_79 ) ;
F_51 ( V_242 ) ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_243 * V_244 , * V_245 ;
F_49 (k, tmp, &hdev->long_term_keys, list) {
F_50 ( & V_244 -> V_91 ) ;
F_51 ( V_244 ) ;
}
return 0 ;
}
struct V_241 * F_116 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_241 * V_244 ;
F_42 (k, &hdev->link_keys, list)
if ( F_54 ( V_84 , & V_244 -> V_84 ) == 0 )
return V_244 ;
return NULL ;
}
static bool F_117 ( struct V_1 * V_2 , struct V_246 * V_247 ,
T_8 V_248 , T_8 V_249 )
{
if ( V_248 < 0x03 )
return true ;
if ( V_248 == V_250 )
return false ;
if ( V_248 == V_251 && V_249 == 0xff )
return false ;
if ( ! V_247 )
return true ;
if ( V_247 -> V_252 > 0x01 && V_247 -> V_253 > 0x01 )
return true ;
if ( V_247 -> V_252 == 0x02 || V_247 -> V_252 == 0x03 )
return true ;
if ( V_247 -> V_253 == 0x02 || V_247 -> V_253 == 0x03 )
return true ;
return false ;
}
struct V_243 * F_118 ( struct V_1 * V_2 , T_5 V_254 , T_8 rand [ 8 ] )
{
struct V_243 * V_244 ;
F_42 (k, &hdev->long_term_keys, list) {
if ( V_244 -> V_254 != V_254 ||
memcmp ( rand , V_244 -> rand , sizeof( V_244 -> rand ) ) )
continue;
return V_244 ;
}
return NULL ;
}
struct V_243 * F_119 ( struct V_1 * V_2 , T_6 * V_84 ,
T_8 V_255 )
{
struct V_243 * V_244 ;
F_42 (k, &hdev->long_term_keys, list)
if ( V_255 == V_244 -> V_256 &&
F_54 ( V_84 , & V_244 -> V_84 ) == 0 )
return V_244 ;
return NULL ;
}
int F_120 ( struct V_1 * V_2 , struct V_246 * V_247 , int V_257 ,
T_6 * V_84 , T_8 * V_258 , T_8 type , T_8 V_259 )
{
struct V_241 * V_242 , * V_260 ;
T_8 V_249 ;
bool V_261 ;
V_260 = F_116 ( V_2 , V_84 ) ;
if ( V_260 ) {
V_249 = V_260 -> type ;
V_242 = V_260 ;
} else {
V_249 = V_247 ? V_247 -> V_248 : 0xff ;
V_242 = F_61 ( sizeof( * V_242 ) , V_18 ) ;
if ( ! V_242 )
return - V_135 ;
F_58 ( & V_242 -> V_91 , & V_2 -> V_262 ) ;
}
F_4 ( L_18 , V_2 -> V_6 , V_84 , type ) ;
if ( type == V_251 &&
( ! V_247 || V_247 -> V_253 == 0xff ) && V_249 == 0xff ) {
type = V_263 ;
if ( V_247 )
V_247 -> V_248 = type ;
}
F_63 ( & V_242 -> V_84 , V_84 ) ;
memcpy ( V_242 -> V_258 , V_258 , V_264 ) ;
V_242 -> V_259 = V_259 ;
if ( type == V_251 )
V_242 -> type = V_249 ;
else
V_242 -> type = type ;
if ( ! V_257 )
return 0 ;
V_261 = F_117 ( V_2 , V_247 , type , V_249 ) ;
F_121 ( V_2 , V_242 , V_261 ) ;
if ( V_247 )
V_247 -> V_265 = ! V_261 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_6 * V_84 , T_8 V_255 , T_8 type ,
int V_257 , T_8 V_266 , T_8 V_267 [ 16 ] , T_8 V_268 , T_5
V_254 , T_8 rand [ 8 ] )
{
struct V_243 * V_242 , * V_260 ;
if ( ! ( type & V_269 ) && ! ( type & V_270 ) )
return 0 ;
V_260 = F_119 ( V_2 , V_84 , V_255 ) ;
if ( V_260 )
V_242 = V_260 ;
else {
V_242 = F_61 ( sizeof( * V_242 ) , V_18 ) ;
if ( ! V_242 )
return - V_135 ;
F_58 ( & V_242 -> V_91 , & V_2 -> V_271 ) ;
}
F_63 ( & V_242 -> V_84 , V_84 ) ;
V_242 -> V_256 = V_255 ;
memcpy ( V_242 -> V_258 , V_267 , sizeof( V_242 -> V_258 ) ) ;
V_242 -> V_266 = V_266 ;
V_242 -> V_254 = V_254 ;
V_242 -> V_268 = V_268 ;
V_242 -> type = type ;
memcpy ( V_242 -> rand , rand , sizeof( V_242 -> rand ) ) ;
if ( ! V_257 )
return 0 ;
if ( type & V_270 )
F_123 ( V_2 , V_242 , 1 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_241 * V_242 ;
V_242 = F_116 ( V_2 , V_84 ) ;
if ( ! V_242 )
return - V_272 ;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_242 -> V_91 ) ;
F_51 ( V_242 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_243 * V_244 , * V_245 ;
F_49 (k, tmp, &hdev->long_term_keys, list) {
if ( F_54 ( V_84 , & V_244 -> V_84 ) )
continue;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_244 -> V_91 ) ;
F_51 ( V_244 ) ;
}
return 0 ;
}
static void F_126 ( unsigned long V_123 )
{
struct V_1 * V_2 = ( void * ) V_123 ;
if ( V_2 -> V_12 ) {
struct V_10 * V_11 = ( void * ) V_2 -> V_12 -> V_13 ;
T_2 V_14 = F_6 ( V_11 -> V_14 ) ;
F_34 ( L_20 , V_2 -> V_6 , V_14 ) ;
} else {
F_34 ( L_21 , V_2 -> V_6 ) ;
}
F_83 ( & V_2 -> V_169 , 1 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
struct V_273 * F_127 ( struct V_1 * V_2 ,
T_6 * V_84 )
{
struct V_273 * V_13 ;
F_42 (data, &hdev->remote_oob_data, list)
if ( F_54 ( V_84 , & V_13 -> V_84 ) == 0 )
return V_13 ;
return NULL ;
}
int F_60 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_273 * V_13 ;
V_13 = F_127 ( V_2 , V_84 ) ;
if ( ! V_13 )
return - V_272 ;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_13 -> V_91 ) ;
F_51 ( V_13 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_273 * V_13 , * V_80 ;
F_49 (data, n, &hdev->remote_oob_data, list) {
F_50 ( & V_13 -> V_91 ) ;
F_51 ( V_13 ) ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , T_6 * V_84 , T_8 * V_274 ,
T_8 * V_275 )
{
struct V_273 * V_13 ;
V_13 = F_127 ( V_2 , V_84 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_135 ;
F_63 ( & V_13 -> V_84 , V_84 ) ;
F_58 ( & V_13 -> V_91 , & V_2 -> V_276 ) ;
}
memcpy ( V_13 -> V_274 , V_274 , sizeof( V_13 -> V_274 ) ) ;
memcpy ( V_13 -> V_275 , V_275 , sizeof( V_13 -> V_275 ) ) ;
F_4 ( L_22 , V_2 -> V_6 , V_84 ) ;
return 0 ;
}
struct V_277 * F_130 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_277 * V_278 ;
F_42 (b, &hdev->blacklist, list)
if ( F_54 ( V_84 , & V_278 -> V_84 ) == 0 )
return V_278 ;
return NULL ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_89 * V_79 , * V_80 ;
F_112 (p, n, &hdev->blacklist) {
struct V_277 * V_278 ;
V_278 = F_113 ( V_79 , struct V_277 , V_91 ) ;
F_50 ( V_79 ) ;
F_51 ( V_278 ) ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_6 * V_84 , T_8 type )
{
struct V_277 * V_279 ;
if ( F_54 ( V_84 , V_86 ) == 0 )
return - V_280 ;
if ( F_130 ( V_2 , V_84 ) )
return - V_281 ;
V_279 = F_61 ( sizeof( struct V_277 ) , V_134 ) ;
if ( ! V_279 )
return - V_135 ;
F_63 ( & V_279 -> V_84 , V_84 ) ;
F_58 ( & V_279 -> V_91 , & V_2 -> V_282 ) ;
return F_133 ( V_2 , V_84 , type ) ;
}
int F_134 ( struct V_1 * V_2 , T_6 * V_84 , T_8 type )
{
struct V_277 * V_279 ;
if ( F_54 ( V_84 , V_86 ) == 0 )
return F_131 ( V_2 ) ;
V_279 = F_130 ( V_2 , V_84 ) ;
if ( ! V_279 )
return - V_272 ;
F_50 ( & V_279 -> V_91 ) ;
F_51 ( V_279 ) ;
return F_135 ( V_2 , V_84 , type ) ;
}
static void F_136 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_283 * V_284 = (struct V_283 * ) V_29 ;
struct V_285 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . type = V_284 -> type ;
V_117 . V_286 = F_39 ( V_284 -> V_286 ) ;
V_117 . V_287 = F_39 ( V_284 -> V_287 ) ;
F_26 ( V_2 , V_288 , sizeof( V_117 ) , & V_117 ) ;
}
static void F_137 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_289 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_290 = 1 ;
V_117 . V_291 = 1 ;
F_26 ( V_2 , V_292 , sizeof( V_117 ) , & V_117 ) ;
}
static int F_138 ( struct V_1 * V_2 , T_8 type , T_2 V_286 ,
T_2 V_287 , int V_30 )
{
long V_127 = F_71 ( 3000 ) ;
struct V_283 V_284 ;
int V_27 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_293 , & V_2 -> V_139 ) )
return - V_294 ;
V_284 . type = type ;
V_284 . V_286 = V_286 ;
V_284 . V_287 = V_287 ;
F_22 ( V_2 ) ;
V_27 = F_12 ( V_2 , F_136 , ( unsigned long ) & V_284 ,
V_127 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_2 , F_137 , 0 , V_127 ) ;
F_23 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_107 ( & V_2 -> V_186 ,
F_71 ( V_30 ) ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_293 , & V_2 -> V_139 ) )
return - V_163 ;
if ( F_91 ( & V_2 -> V_186 ) ) {
struct V_289 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_26 ( V_2 , V_292 , sizeof( V_117 ) , & V_117 ) ;
}
return 0 ;
}
static void F_140 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 ,
V_186 . V_235 ) ;
struct V_289 V_117 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_26 ( V_2 , V_292 , sizeof( V_117 ) , & V_117 ) ;
}
static void F_141 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_178 ) ;
struct V_283 * V_284 = & V_2 -> V_283 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_138 ( V_2 , V_284 -> type , V_284 -> V_286 , V_284 -> V_287 ,
V_284 -> V_30 ) ;
}
int F_142 ( struct V_1 * V_2 , T_8 type , T_2 V_286 , T_2 V_287 ,
int V_30 )
{
struct V_283 * V_284 = & V_2 -> V_283 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_138 , & V_2 -> V_139 ) )
return - V_295 ;
if ( F_143 ( & V_2 -> V_178 ) )
return - V_294 ;
V_284 -> type = type ;
V_284 -> V_286 = V_286 ;
V_284 -> V_287 = V_287 ;
V_284 -> V_30 = V_30 ;
F_9 ( V_296 , & V_2 -> V_178 ) ;
return 0 ;
}
struct V_1 * F_144 ( void )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( struct V_1 ) , V_134 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_48 = ( V_297 | V_298 | V_299 ) ;
V_2 -> V_300 = ( V_301 ) ;
V_2 -> V_208 = ( V_210 ) ;
V_2 -> V_302 = 0x03 ;
V_2 -> V_303 = V_146 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_304 = 800 ;
V_2 -> V_305 = 80 ;
F_145 ( & V_2 -> V_306 ) ;
F_145 ( & V_2 -> V_307 ) ;
F_52 ( & V_2 -> V_308 ) ;
F_52 ( & V_2 -> V_282 ) ;
F_52 ( & V_2 -> V_309 ) ;
F_52 ( & V_2 -> V_262 ) ;
F_52 ( & V_2 -> V_271 ) ;
F_52 ( & V_2 -> V_276 ) ;
F_52 ( & V_2 -> V_310 . V_91 ) ;
F_146 ( & V_2 -> V_174 , V_311 ) ;
F_146 ( & V_2 -> V_21 , V_312 ) ;
F_146 ( & V_2 -> V_173 , V_313 ) ;
F_146 ( & V_2 -> V_236 , F_105 ) ;
F_146 ( & V_2 -> V_178 , F_141 ) ;
F_147 ( & V_2 -> V_179 , F_109 ) ;
F_147 ( & V_2 -> V_182 , F_110 ) ;
F_147 ( & V_2 -> V_186 , F_140 ) ;
F_148 ( & V_2 -> V_47 ) ;
F_148 ( & V_2 -> V_175 ) ;
F_148 ( & V_2 -> V_19 ) ;
F_148 ( & V_2 -> V_189 ) ;
F_149 ( & V_2 -> V_26 ) ;
F_150 ( & V_2 -> V_180 , F_126 , ( unsigned long ) V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
return V_2 ;
}
void F_153 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_47 ) ;
F_154 ( & V_2 -> V_50 ) ;
}
int F_155 ( struct V_1 * V_2 )
{
int V_67 , error ;
if ( ! V_2 -> V_167 || ! V_2 -> V_177 )
return - V_155 ;
switch ( V_2 -> V_53 ) {
case V_54 :
V_67 = F_156 ( & V_314 , 0 , 0 , V_134 ) ;
break;
case V_55 :
V_67 = F_156 ( & V_314 , 1 , 0 , V_134 ) ;
break;
default:
return - V_155 ;
}
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_2 -> V_6 , L_23 , V_67 ) ;
V_2 -> V_67 = V_67 ;
F_4 ( L_24 , V_2 , V_2 -> V_6 , V_2 -> V_228 ) ;
F_157 ( & V_66 ) ;
F_58 ( & V_2 -> V_91 , & V_315 ) ;
F_158 ( & V_66 ) ;
V_2 -> V_20 = F_159 ( V_2 -> V_6 , V_316 | V_317 |
V_318 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_135 ;
goto V_27;
}
error = F_160 ( V_2 ) ;
if ( error < 0 )
goto V_319;
V_2 -> V_161 = F_161 ( V_2 -> V_6 , & V_2 -> V_50 ,
V_320 , & V_321 ,
V_2 ) ;
if ( V_2 -> V_161 ) {
if ( F_162 ( V_2 -> V_161 ) < 0 ) {
F_163 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
}
}
F_25 ( V_172 , & V_2 -> V_139 ) ;
if ( V_2 -> V_53 != V_55 )
F_25 ( V_190 , & V_2 -> V_139 ) ;
F_1 ( V_2 , V_322 ) ;
F_43 ( V_2 ) ;
F_164 ( & V_2 -> V_236 ) ;
return V_67 ;
V_319:
F_165 ( V_2 -> V_20 ) ;
V_27:
F_166 ( & V_314 , V_2 -> V_67 ) ;
F_157 ( & V_66 ) ;
F_50 ( & V_2 -> V_91 ) ;
F_158 ( & V_66 ) ;
return error ;
}
void F_167 ( struct V_1 * V_2 )
{
int V_323 , V_67 ;
F_4 ( L_24 , V_2 , V_2 -> V_6 , V_2 -> V_228 ) ;
F_25 ( V_160 , & V_2 -> V_139 ) ;
V_67 = V_2 -> V_67 ;
F_157 ( & V_66 ) ;
F_50 ( & V_2 -> V_91 ) ;
F_158 ( & V_66 ) ;
F_89 ( V_2 ) ;
for ( V_323 = 0 ; V_323 < V_324 ; V_323 ++ )
F_88 ( V_2 -> V_325 [ V_323 ] ) ;
F_90 ( & V_2 -> V_236 ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_172 , & V_2 -> V_139 ) ) {
F_67 ( V_2 ) ;
F_168 ( V_2 ) ;
F_70 ( V_2 ) ;
}
F_169 ( ! F_170 ( & V_2 -> V_308 ) ) ;
F_1 ( V_2 , V_326 ) ;
if ( V_2 -> V_161 ) {
F_171 ( V_2 -> V_161 ) ;
F_163 ( V_2 -> V_161 ) ;
}
F_172 ( V_2 ) ;
F_165 ( V_2 -> V_20 ) ;
F_67 ( V_2 ) ;
F_131 ( V_2 ) ;
F_111 ( V_2 ) ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
F_128 ( V_2 ) ;
F_70 ( V_2 ) ;
F_74 ( V_2 ) ;
F_166 ( & V_314 , V_67 ) ;
}
int F_173 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_327 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_328 ) ;
return 0 ;
}
int F_175 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_50 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_88 ( V_16 ) ;
return - V_329 ;
}
F_31 ( V_16 ) -> V_330 = 1 ;
F_176 ( V_16 ) ;
F_32 ( & V_2 -> V_175 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_174 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_331 , T_4 V_64 )
{
int V_154 = 0 ;
int V_332 = 0 ;
int V_333 = V_331 ;
struct V_15 * V_16 ;
struct V_334 * V_335 ;
if ( ( type < V_336 || type > V_337 ) ||
V_64 >= V_324 )
return - V_338 ;
V_16 = V_2 -> V_325 [ V_64 ] ;
if ( ! V_16 ) {
switch ( type ) {
case V_336 :
V_154 = V_339 ;
V_332 = V_340 ;
break;
case V_337 :
V_154 = V_341 ;
V_332 = V_342 ;
break;
case V_343 :
V_154 = V_344 ;
V_332 = V_345 ;
break;
}
V_16 = F_178 ( V_154 , V_18 ) ;
if ( ! V_16 )
return - V_135 ;
V_335 = ( void * ) V_16 -> V_346 ;
V_335 -> V_347 = V_332 ;
V_335 -> V_48 = type ;
V_16 -> V_50 = ( void * ) V_2 ;
V_2 -> V_325 [ V_64 ] = V_16 ;
}
while ( V_331 ) {
V_335 = ( void * ) V_16 -> V_346 ;
V_154 = F_179 ( V_348 , V_335 -> V_347 , V_331 ) ;
memcpy ( F_180 ( V_16 , V_154 ) , V_13 , V_154 ) ;
V_331 -= V_154 ;
V_13 += V_154 ;
V_335 -> V_347 -= V_154 ;
V_333 = V_331 ;
switch ( type ) {
case V_337 :
if ( V_16 -> V_154 == V_342 ) {
struct V_349 * V_350 = V_349 ( V_16 ) ;
V_335 -> V_347 = V_350 -> V_351 ;
if ( F_181 ( V_16 ) < V_335 -> V_347 ) {
F_88 ( V_16 ) ;
V_2 -> V_325 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
case V_336 :
if ( V_16 -> V_154 == V_340 ) {
struct V_352 * V_350 = V_352 ( V_16 ) ;
V_335 -> V_347 = F_6 ( V_350 -> V_353 ) ;
if ( F_181 ( V_16 ) < V_335 -> V_347 ) {
F_88 ( V_16 ) ;
V_2 -> V_325 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
case V_343 :
if ( V_16 -> V_154 == V_345 ) {
struct V_354 * V_350 = V_354 ( V_16 ) ;
V_335 -> V_347 = V_350 -> V_353 ;
if ( F_181 ( V_16 ) < V_335 -> V_347 ) {
F_88 ( V_16 ) ;
V_2 -> V_325 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
}
if ( V_335 -> V_347 == 0 ) {
F_31 ( V_16 ) -> V_48 = type ;
F_175 ( V_16 ) ;
V_2 -> V_325 [ V_64 ] = NULL ;
return V_333 ;
}
}
return V_333 ;
}
int F_182 ( struct V_1 * V_2 , int type , void * V_13 , int V_331 )
{
int V_355 = 0 ;
if ( type < V_336 || type > V_337 )
return - V_338 ;
while ( V_331 ) {
V_355 = F_177 ( V_2 , type , V_13 , V_331 , type - 1 ) ;
if ( V_355 < 0 )
return V_355 ;
V_13 += ( V_331 - V_355 ) ;
V_331 = V_355 ;
}
return V_355 ;
}
int F_183 ( struct V_1 * V_2 , void * V_13 , int V_331 )
{
int type ;
int V_355 = 0 ;
while ( V_331 ) {
struct V_15 * V_16 = V_2 -> V_325 [ V_356 ] ;
if ( ! V_16 ) {
struct { char type ; } * V_357 ;
V_357 = V_13 ;
type = V_357 -> type ;
V_13 ++ ;
V_331 -- ;
} else
type = F_31 ( V_16 ) -> V_48 ;
V_355 = F_177 ( V_2 , type , V_13 , V_331 ,
V_356 ) ;
if ( V_355 < 0 )
return V_355 ;
V_13 += ( V_331 - V_355 ) ;
V_331 = V_355 ;
}
return V_355 ;
}
int F_184 ( struct V_358 * V_346 )
{
F_4 ( L_25 , V_346 , V_346 -> V_6 ) ;
F_157 ( & V_359 ) ;
F_58 ( & V_346 -> V_91 , & V_360 ) ;
F_158 ( & V_359 ) ;
return 0 ;
}
int F_185 ( struct V_358 * V_346 )
{
F_4 ( L_25 , V_346 , V_346 -> V_6 ) ;
F_157 ( & V_359 ) ;
F_50 ( & V_346 -> V_91 ) ;
F_158 ( & V_359 ) ;
return 0 ;
}
static int F_186 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_50 ;
if ( ! V_2 ) {
F_88 ( V_16 ) ;
return - V_130 ;
}
F_4 ( L_26 , V_2 -> V_6 , F_31 ( V_16 ) -> V_48 , V_16 -> V_154 ) ;
F_176 ( V_16 ) ;
F_187 ( V_2 , V_16 ) ;
if ( F_188 ( & V_2 -> V_361 ) ) {
F_189 ( V_2 , V_16 ) ;
}
F_190 ( V_16 ) ;
return V_2 -> V_362 ( V_16 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_351 , void * V_284 )
{
int V_154 = V_363 + V_351 ;
struct V_10 * V_364 ;
struct V_15 * V_16 ;
F_4 ( L_27 , V_2 -> V_6 , V_14 , V_351 ) ;
V_16 = F_178 ( V_154 , V_18 ) ;
if ( ! V_16 ) {
F_34 ( L_28 , V_2 -> V_6 ) ;
return - V_135 ;
}
V_364 = (struct V_10 * ) F_180 ( V_16 , V_363 ) ;
V_364 -> V_14 = F_39 ( V_14 ) ;
V_364 -> V_351 = V_351 ;
if ( V_351 )
memcpy ( F_180 ( V_16 , V_351 ) , V_284 , V_351 ) ;
F_4 ( L_29 , V_16 -> V_154 ) ;
F_31 ( V_16 ) -> V_48 = V_49 ;
V_16 -> V_50 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_14 ;
F_32 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_191 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_364 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_364 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_364 -> V_14 != F_39 ( V_14 ) )
return NULL ;
F_4 ( L_30 , V_2 -> V_6 , V_14 ) ;
return V_2 -> V_12 -> V_13 + V_363 ;
}
static void F_192 ( struct V_15 * V_16 , T_1 V_365 , T_1 V_8 )
{
struct V_352 * V_364 ;
int V_154 = V_16 -> V_154 ;
F_193 ( V_16 , V_340 ) ;
F_194 ( V_16 ) ;
V_364 = (struct V_352 * ) F_195 ( V_16 ) ;
V_364 -> V_365 = F_39 ( F_196 ( V_365 , V_8 ) ) ;
V_364 -> V_353 = F_39 ( V_154 ) ;
}
static void F_197 ( struct V_366 * V_367 , struct V_368 * V_369 ,
struct V_15 * V_16 , T_1 V_8 )
{
struct V_246 * V_247 = V_367 -> V_247 ;
struct V_1 * V_2 = V_247 -> V_2 ;
struct V_15 * V_91 ;
V_16 -> V_154 = F_198 ( V_16 ) ;
V_16 -> V_370 = 0 ;
F_31 ( V_16 ) -> V_48 = V_336 ;
switch ( V_2 -> V_53 ) {
case V_54 :
F_192 ( V_16 , V_247 -> V_365 , V_8 ) ;
break;
case V_55 :
F_192 ( V_16 , V_367 -> V_365 , V_8 ) ;
break;
default:
F_34 ( L_31 , V_2 -> V_6 , V_2 -> V_53 ) ;
return;
}
V_91 = F_199 ( V_16 ) -> V_371 ;
if ( ! V_91 ) {
F_4 ( L_32 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_32 ( V_369 , V_16 ) ;
} else {
F_4 ( L_33 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_199 ( V_16 ) -> V_371 = NULL ;
F_200 ( & V_369 -> V_306 ) ;
F_201 ( V_369 , V_16 ) ;
V_8 &= ~ V_372 ;
V_8 |= V_373 ;
do {
V_16 = V_91 ; V_91 = V_91 -> V_374 ;
V_16 -> V_50 = ( void * ) V_2 ;
F_31 ( V_16 ) -> V_48 = V_336 ;
F_192 ( V_16 , V_247 -> V_365 , V_8 ) ;
F_4 ( L_33 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_201 ( V_369 , V_16 ) ;
} while ( V_91 );
F_202 ( & V_369 -> V_306 ) ;
}
}
void F_203 ( struct V_366 * V_367 , struct V_15 * V_16 , T_1 V_8 )
{
struct V_1 * V_2 = V_367 -> V_247 -> V_2 ;
F_4 ( L_34 , V_2 -> V_6 , V_367 , V_8 ) ;
V_16 -> V_50 = ( void * ) V_2 ;
F_197 ( V_367 , & V_367 -> V_375 , V_16 , V_8 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_173 ) ;
}
void F_204 ( struct V_246 * V_247 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_247 -> V_2 ;
struct V_354 V_364 ;
F_4 ( L_35 , V_2 -> V_6 , V_16 -> V_154 ) ;
V_364 . V_365 = F_39 ( V_247 -> V_365 ) ;
V_364 . V_353 = V_16 -> V_154 ;
F_193 ( V_16 , V_345 ) ;
F_194 ( V_16 ) ;
memcpy ( F_195 ( V_16 ) , & V_364 , V_345 ) ;
V_16 -> V_50 = ( void * ) V_2 ;
F_31 ( V_16 ) -> V_48 = V_343 ;
F_32 ( & V_247 -> V_375 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_173 ) ;
}
static struct V_246 * F_205 ( struct V_1 * V_2 , T_4 type ,
int * V_376 )
{
struct V_377 * V_350 = & V_2 -> V_310 ;
struct V_246 * V_247 = NULL , * V_378 ;
unsigned int V_104 = 0 , V_379 = ~ 0 ;
F_206 () ;
F_207 (c, &h->list, list) {
if ( V_378 -> type != type || F_208 ( & V_378 -> V_375 ) )
continue;
if ( V_378 -> V_71 != V_380 && V_378 -> V_71 != V_381 )
continue;
V_104 ++ ;
if ( V_378 -> V_11 < V_379 ) {
V_379 = V_378 -> V_11 ;
V_247 = V_378 ;
}
if ( F_209 ( V_2 , type ) == V_104 )
break;
}
F_210 () ;
if ( V_247 ) {
int V_382 , V_383 ;
switch ( V_247 -> type ) {
case V_384 :
V_382 = V_2 -> V_193 ;
break;
case V_385 :
case V_386 :
V_382 = V_2 -> V_194 ;
break;
case V_387 :
V_382 = V_2 -> V_229 ? V_2 -> V_195 : V_2 -> V_193 ;
break;
default:
V_382 = 0 ;
F_34 ( L_36 ) ;
}
V_383 = V_382 / V_104 ;
* V_376 = V_383 ? V_383 : 1 ;
} else
* V_376 = 0 ;
F_4 ( L_37 , V_247 , * V_376 ) ;
return V_247 ;
}
static void F_211 ( struct V_1 * V_2 , T_4 type )
{
struct V_377 * V_350 = & V_2 -> V_310 ;
struct V_246 * V_378 ;
F_34 ( L_38 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (c, &h->list, list) {
if ( V_378 -> type == type && V_378 -> V_11 ) {
F_34 ( L_39 ,
V_2 -> V_6 , & V_378 -> V_388 ) ;
F_212 ( V_378 , V_389 ) ;
}
}
F_210 () ;
}
static struct V_366 * F_213 ( struct V_1 * V_2 , T_4 type ,
int * V_376 )
{
struct V_377 * V_350 = & V_2 -> V_310 ;
struct V_366 * V_367 = NULL ;
unsigned int V_104 = 0 , V_379 = ~ 0 , V_390 = 0 ;
struct V_246 * V_247 ;
int V_382 , V_383 , V_391 = 0 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (conn, &h->list, list) {
struct V_366 * V_245 ;
if ( V_247 -> type != type )
continue;
if ( V_247 -> V_71 != V_380 && V_247 -> V_71 != V_381 )
continue;
V_391 ++ ;
F_207 (tmp, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( F_208 ( & V_245 -> V_375 ) )
continue;
V_16 = F_214 ( & V_245 -> V_375 ) ;
if ( V_16 -> V_392 < V_390 )
continue;
if ( V_16 -> V_392 > V_390 ) {
V_104 = 0 ;
V_379 = ~ 0 ;
V_390 = V_16 -> V_392 ;
}
V_104 ++ ;
if ( V_247 -> V_11 < V_379 ) {
V_379 = V_247 -> V_11 ;
V_367 = V_245 ;
}
}
if ( F_209 ( V_2 , type ) == V_391 )
break;
}
F_210 () ;
if ( ! V_367 )
return NULL ;
switch ( V_367 -> V_247 -> type ) {
case V_384 :
V_382 = V_2 -> V_193 ;
break;
case V_393 :
V_382 = V_2 -> V_394 ;
break;
case V_385 :
case V_386 :
V_382 = V_2 -> V_194 ;
break;
case V_387 :
V_382 = V_2 -> V_229 ? V_2 -> V_195 : V_2 -> V_193 ;
break;
default:
V_382 = 0 ;
F_34 ( L_36 ) ;
}
V_383 = V_382 / V_104 ;
* V_376 = V_383 ? V_383 : 1 ;
F_4 ( L_40 , V_367 , * V_376 ) ;
return V_367 ;
}
static void F_215 ( struct V_1 * V_2 , T_4 type )
{
struct V_377 * V_350 = & V_2 -> V_310 ;
struct V_246 * V_247 ;
int V_104 = 0 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (conn, &h->list, list) {
struct V_366 * V_367 ;
if ( V_247 -> type != type )
continue;
if ( V_247 -> V_71 != V_380 && V_247 -> V_71 != V_381 )
continue;
V_104 ++ ;
F_207 (chan, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( V_367 -> V_11 ) {
V_367 -> V_11 = 0 ;
continue;
}
if ( F_208 ( & V_367 -> V_375 ) )
continue;
V_16 = F_214 ( & V_367 -> V_375 ) ;
if ( V_16 -> V_392 >= V_395 - 1 )
continue;
V_16 -> V_392 = V_395 - 1 ;
F_4 ( L_41 , V_367 , V_16 ,
V_16 -> V_392 ) ;
}
if ( F_209 ( V_2 , type ) == V_104 )
break;
}
F_210 () ;
}
static inline int F_216 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_217 ( V_16 -> V_154 - V_340 , V_2 -> V_396 ) ;
}
static void F_218 ( struct V_1 * V_2 , unsigned int V_382 )
{
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) ) {
if ( ! V_382 && F_219 ( V_103 , V_2 -> V_397 +
V_398 ) )
F_211 ( V_2 , V_384 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
unsigned int V_382 = V_2 -> V_193 ;
struct V_366 * V_367 ;
struct V_15 * V_16 ;
int V_376 ;
F_218 ( V_2 , V_382 ) ;
while ( V_2 -> V_193 &&
( V_367 = F_213 ( V_2 , V_384 , & V_376 ) ) ) {
T_10 V_392 = ( F_214 ( & V_367 -> V_375 ) ) -> V_392 ;
while ( V_376 -- && ( V_16 = F_214 ( & V_367 -> V_375 ) ) ) {
F_4 ( L_42 , V_367 , V_16 ,
V_16 -> V_154 , V_16 -> V_392 ) ;
if ( V_16 -> V_392 < V_392 )
break;
V_16 = F_30 ( & V_367 -> V_375 ) ;
F_221 ( V_367 -> V_247 ,
F_31 ( V_16 ) -> V_399 ) ;
F_186 ( V_16 ) ;
V_2 -> V_397 = V_103 ;
V_2 -> V_193 -- ;
V_367 -> V_11 ++ ;
V_367 -> V_247 -> V_11 ++ ;
}
}
if ( V_382 != V_2 -> V_193 )
F_215 ( V_2 , V_384 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
unsigned int V_382 = V_2 -> V_394 ;
struct V_366 * V_367 ;
struct V_15 * V_16 ;
int V_376 ;
T_8 type ;
F_218 ( V_2 , V_382 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( V_2 -> V_53 == V_55 )
type = V_393 ;
else
type = V_384 ;
while ( V_2 -> V_394 > 0 &&
( V_367 = F_213 ( V_2 , type , & V_376 ) ) ) {
T_10 V_392 = ( F_214 ( & V_367 -> V_375 ) ) -> V_392 ;
while ( V_376 > 0 && ( V_16 = F_214 ( & V_367 -> V_375 ) ) ) {
int V_400 ;
F_4 ( L_42 , V_367 , V_16 ,
V_16 -> V_154 , V_16 -> V_392 ) ;
if ( V_16 -> V_392 < V_392 )
break;
V_16 = F_30 ( & V_367 -> V_375 ) ;
V_400 = F_216 ( V_2 , V_16 ) ;
if ( V_400 > V_2 -> V_394 )
return;
F_221 ( V_367 -> V_247 ,
F_31 ( V_16 ) -> V_399 ) ;
F_186 ( V_16 ) ;
V_2 -> V_397 = V_103 ;
V_2 -> V_394 -= V_400 ;
V_376 -= V_400 ;
V_367 -> V_11 += V_400 ;
V_367 -> V_247 -> V_11 += V_400 ;
}
}
if ( V_382 != V_2 -> V_394 )
F_215 ( V_2 , type ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_384 ) && V_2 -> V_53 == V_54 )
return;
if ( ! F_209 ( V_2 , V_393 ) && V_2 -> V_53 == V_55 )
return;
switch ( V_2 -> V_40 ) {
case V_41 :
F_220 ( V_2 ) ;
break;
case V_44 :
F_222 ( V_2 ) ;
break;
}
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_246 * V_247 ;
struct V_15 * V_16 ;
int V_376 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_385 ) )
return;
while ( V_2 -> V_194 && ( V_247 = F_205 ( V_2 , V_385 , & V_376 ) ) ) {
while ( V_376 -- && ( V_16 = F_30 ( & V_247 -> V_375 ) ) ) {
F_4 ( L_43 , V_16 , V_16 -> V_154 ) ;
F_186 ( V_16 ) ;
V_247 -> V_11 ++ ;
if ( V_247 -> V_11 == ~ 0 )
V_247 -> V_11 = 0 ;
}
}
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_246 * V_247 ;
struct V_15 * V_16 ;
int V_376 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_386 ) )
return;
while ( V_2 -> V_194 && ( V_247 = F_205 ( V_2 , V_386 ,
& V_376 ) ) ) {
while ( V_376 -- && ( V_16 = F_30 ( & V_247 -> V_375 ) ) ) {
F_4 ( L_43 , V_16 , V_16 -> V_154 ) ;
F_186 ( V_16 ) ;
V_247 -> V_11 ++ ;
if ( V_247 -> V_11 == ~ 0 )
V_247 -> V_11 = 0 ;
}
}
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_366 * V_367 ;
struct V_15 * V_16 ;
int V_376 , V_382 , V_245 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_387 ) )
return;
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_195 && V_2 -> V_230 &&
F_219 ( V_103 , V_2 -> V_401 + V_402 * 45 ) )
F_211 ( V_2 , V_387 ) ;
}
V_382 = V_2 -> V_230 ? V_2 -> V_195 : V_2 -> V_193 ;
V_245 = V_382 ;
while ( V_382 && ( V_367 = F_213 ( V_2 , V_387 , & V_376 ) ) ) {
T_10 V_392 = ( F_214 ( & V_367 -> V_375 ) ) -> V_392 ;
while ( V_376 -- && ( V_16 = F_214 ( & V_367 -> V_375 ) ) ) {
F_4 ( L_42 , V_367 , V_16 ,
V_16 -> V_154 , V_16 -> V_392 ) ;
if ( V_16 -> V_392 < V_392 )
break;
V_16 = F_30 ( & V_367 -> V_375 ) ;
F_186 ( V_16 ) ;
V_2 -> V_401 = V_103 ;
V_382 -- ;
V_367 -> V_11 ++ ;
V_367 -> V_247 -> V_11 ++ ;
}
}
if ( V_2 -> V_230 )
V_2 -> V_195 = V_382 ;
else
V_2 -> V_193 = V_382 ;
if ( V_382 != V_245 )
F_215 ( V_2 , V_387 ) ;
}
static void V_313 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_173 ) ;
struct V_15 * V_16 ;
F_4 ( L_44 , V_2 -> V_6 , V_2 -> V_193 ,
V_2 -> V_194 , V_2 -> V_195 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
F_226 ( V_2 ) ;
while ( ( V_16 = F_30 ( & V_2 -> V_189 ) ) )
F_186 ( V_16 ) ;
}
static void F_227 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_352 * V_364 = ( void * ) V_16 -> V_13 ;
struct V_246 * V_247 ;
T_1 V_365 , V_8 ;
F_228 ( V_16 , V_340 ) ;
V_365 = F_6 ( V_364 -> V_365 ) ;
V_8 = F_229 ( V_365 ) ;
V_365 = F_230 ( V_365 ) ;
F_4 ( L_45 , V_2 -> V_6 , V_16 -> V_154 ,
V_365 , V_8 ) ;
V_2 -> V_196 . V_403 ++ ;
F_67 ( V_2 ) ;
V_247 = F_231 ( V_2 , V_365 ) ;
F_70 ( V_2 ) ;
if ( V_247 ) {
F_221 ( V_247 , V_404 ) ;
F_232 ( V_247 , V_16 , V_8 ) ;
return;
} else {
F_34 ( L_46 ,
V_2 -> V_6 , V_365 ) ;
}
F_88 ( V_16 ) ;
}
static void F_233 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_354 * V_364 = ( void * ) V_16 -> V_13 ;
struct V_246 * V_247 ;
T_1 V_365 ;
F_228 ( V_16 , V_345 ) ;
V_365 = F_6 ( V_364 -> V_365 ) ;
F_4 ( L_47 , V_2 -> V_6 , V_16 -> V_154 , V_365 ) ;
V_2 -> V_196 . V_405 ++ ;
F_67 ( V_2 ) ;
V_247 = F_231 ( V_2 , V_365 ) ;
F_70 ( V_2 ) ;
if ( V_247 ) {
F_234 ( V_247 , V_16 ) ;
return;
} else {
F_34 ( L_48 ,
V_2 -> V_6 , V_365 ) ;
}
F_88 ( V_16 ) ;
}
static void V_311 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_174 ) ;
struct V_15 * V_16 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
while ( ( V_16 = F_30 ( & V_2 -> V_175 ) ) ) {
F_187 ( V_2 , V_16 ) ;
if ( F_188 ( & V_2 -> V_361 ) ) {
F_189 ( V_2 , V_16 ) ;
}
if ( F_5 ( V_165 , & V_2 -> V_8 ) ) {
F_88 ( V_16 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_31 ( V_16 ) -> V_48 ) {
case V_336 :
case V_343 :
F_88 ( V_16 ) ;
continue;
}
}
switch ( F_31 ( V_16 ) -> V_48 ) {
case V_337 :
F_4 ( L_49 , V_2 -> V_6 ) ;
F_235 ( V_2 , V_16 ) ;
break;
case V_336 :
F_4 ( L_50 , V_2 -> V_6 ) ;
F_227 ( V_2 , V_16 ) ;
break;
case V_343 :
F_4 ( L_51 , V_2 -> V_6 ) ;
F_233 ( V_2 , V_16 ) ;
break;
default:
F_88 ( V_16 ) ;
break;
}
}
}
static void V_312 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_21 ) ;
struct V_15 * V_16 ;
F_4 ( L_52 , V_2 -> V_6 ,
F_188 ( & V_2 -> V_169 ) , F_236 ( & V_2 -> V_19 ) ) ;
if ( F_188 ( & V_2 -> V_169 ) ) {
V_16 = F_30 ( & V_2 -> V_19 ) ;
if ( ! V_16 )
return;
F_88 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_7 ( V_16 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_237 ( & V_2 -> V_169 ) ;
F_186 ( V_16 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_238 ( & V_2 -> V_180 ) ;
else
F_239 ( & V_2 -> V_180 ,
V_103 + V_188 ) ;
} else {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_240 ( struct V_1 * V_2 , T_8 V_120 )
{
T_8 V_119 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_116 V_117 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_118 , & V_2 -> V_8 ) )
return - V_294 ;
F_48 ( V_2 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
memcpy ( & V_117 . V_119 , V_119 , sizeof( V_117 . V_119 ) ) ;
V_117 . V_120 = V_120 ;
return F_26 ( V_2 , V_122 , sizeof( V_117 ) , & V_117 ) ;
}
int F_241 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_118 , & V_2 -> V_8 ) )
return - V_163 ;
return F_26 ( V_2 , V_406 , 0 , NULL ) ;
}
T_8 F_242 ( T_8 V_256 )
{
switch ( V_256 ) {
case V_407 :
return V_408 ;
default:
return V_409 ;
}
}
