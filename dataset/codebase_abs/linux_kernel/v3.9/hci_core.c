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
F_107 ( V_2 -> V_237 , & V_2 -> V_179 ,
V_238 ) ;
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
T_8 V_56 = V_239 ;
V_2 = F_106 ( V_235 , struct V_1 , V_182 . V_235 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_67 ( V_2 ) ;
F_26 ( V_2 , V_57 , sizeof( V_56 ) , & V_56 ) ;
V_2 -> V_181 = 0 ;
F_70 ( V_2 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_240 * V_241 , * V_242 ;
F_49 (uuid, tmp, &hdev->uuids, list) {
F_50 ( & V_241 -> V_91 ) ;
F_51 ( V_241 ) ;
}
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_89 * V_79 , * V_80 ;
F_113 (p, n, &hdev->link_keys) {
struct V_243 * V_244 ;
V_244 = F_114 ( V_79 , struct V_243 , V_91 ) ;
F_50 ( V_79 ) ;
F_51 ( V_244 ) ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_245 * V_246 , * V_242 ;
F_49 (k, tmp, &hdev->long_term_keys, list) {
F_50 ( & V_246 -> V_91 ) ;
F_51 ( V_246 ) ;
}
return 0 ;
}
struct V_243 * F_116 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_243 * V_246 ;
F_42 (k, &hdev->link_keys, list)
if ( F_54 ( V_84 , & V_246 -> V_84 ) == 0 )
return V_246 ;
return NULL ;
}
static bool F_117 ( struct V_1 * V_2 , struct V_247 * V_248 ,
T_8 V_249 , T_8 V_250 )
{
if ( V_249 < 0x03 )
return true ;
if ( V_249 == V_251 )
return false ;
if ( V_249 == V_252 && V_250 == 0xff )
return false ;
if ( ! V_248 )
return true ;
if ( V_248 -> V_253 > 0x01 && V_248 -> V_254 > 0x01 )
return true ;
if ( V_248 -> V_253 == 0x02 || V_248 -> V_253 == 0x03 )
return true ;
if ( V_248 -> V_254 == 0x02 || V_248 -> V_254 == 0x03 )
return true ;
return false ;
}
struct V_245 * F_118 ( struct V_1 * V_2 , T_5 V_255 , T_8 rand [ 8 ] )
{
struct V_245 * V_246 ;
F_42 (k, &hdev->long_term_keys, list) {
if ( V_246 -> V_255 != V_255 ||
memcmp ( rand , V_246 -> rand , sizeof( V_246 -> rand ) ) )
continue;
return V_246 ;
}
return NULL ;
}
struct V_245 * F_119 ( struct V_1 * V_2 , T_6 * V_84 ,
T_8 V_256 )
{
struct V_245 * V_246 ;
F_42 (k, &hdev->long_term_keys, list)
if ( V_256 == V_246 -> V_257 &&
F_54 ( V_84 , & V_246 -> V_84 ) == 0 )
return V_246 ;
return NULL ;
}
int F_120 ( struct V_1 * V_2 , struct V_247 * V_248 , int V_258 ,
T_6 * V_84 , T_8 * V_259 , T_8 type , T_8 V_260 )
{
struct V_243 * V_244 , * V_261 ;
T_8 V_250 ;
bool V_262 ;
V_261 = F_116 ( V_2 , V_84 ) ;
if ( V_261 ) {
V_250 = V_261 -> type ;
V_244 = V_261 ;
} else {
V_250 = V_248 ? V_248 -> V_249 : 0xff ;
V_244 = F_61 ( sizeof( * V_244 ) , V_18 ) ;
if ( ! V_244 )
return - V_135 ;
F_58 ( & V_244 -> V_91 , & V_2 -> V_263 ) ;
}
F_4 ( L_18 , V_2 -> V_6 , V_84 , type ) ;
if ( type == V_252 &&
( ! V_248 || V_248 -> V_254 == 0xff ) && V_250 == 0xff ) {
type = V_264 ;
if ( V_248 )
V_248 -> V_249 = type ;
}
F_63 ( & V_244 -> V_84 , V_84 ) ;
memcpy ( V_244 -> V_259 , V_259 , V_265 ) ;
V_244 -> V_260 = V_260 ;
if ( type == V_252 )
V_244 -> type = V_250 ;
else
V_244 -> type = type ;
if ( ! V_258 )
return 0 ;
V_262 = F_117 ( V_2 , V_248 , type , V_250 ) ;
F_121 ( V_2 , V_244 , V_262 ) ;
if ( V_248 )
V_248 -> V_266 = ! V_262 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_6 * V_84 , T_8 V_256 , T_8 type ,
int V_258 , T_8 V_267 , T_8 V_268 [ 16 ] , T_8 V_269 , T_5
V_255 , T_8 rand [ 8 ] )
{
struct V_245 * V_244 , * V_261 ;
if ( ! ( type & V_270 ) && ! ( type & V_271 ) )
return 0 ;
V_261 = F_119 ( V_2 , V_84 , V_256 ) ;
if ( V_261 )
V_244 = V_261 ;
else {
V_244 = F_61 ( sizeof( * V_244 ) , V_18 ) ;
if ( ! V_244 )
return - V_135 ;
F_58 ( & V_244 -> V_91 , & V_2 -> V_272 ) ;
}
F_63 ( & V_244 -> V_84 , V_84 ) ;
V_244 -> V_257 = V_256 ;
memcpy ( V_244 -> V_259 , V_268 , sizeof( V_244 -> V_259 ) ) ;
V_244 -> V_267 = V_267 ;
V_244 -> V_255 = V_255 ;
V_244 -> V_269 = V_269 ;
V_244 -> type = type ;
memcpy ( V_244 -> rand , rand , sizeof( V_244 -> rand ) ) ;
if ( ! V_258 )
return 0 ;
if ( type & V_271 )
F_123 ( V_2 , V_244 , 1 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_243 * V_244 ;
V_244 = F_116 ( V_2 , V_84 ) ;
if ( ! V_244 )
return - V_273 ;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_244 -> V_91 ) ;
F_51 ( V_244 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_245 * V_246 , * V_242 ;
F_49 (k, tmp, &hdev->long_term_keys, list) {
if ( F_54 ( V_84 , & V_246 -> V_84 ) )
continue;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_246 -> V_91 ) ;
F_51 ( V_246 ) ;
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
struct V_274 * F_127 ( struct V_1 * V_2 ,
T_6 * V_84 )
{
struct V_274 * V_13 ;
F_42 (data, &hdev->remote_oob_data, list)
if ( F_54 ( V_84 , & V_13 -> V_84 ) == 0 )
return V_13 ;
return NULL ;
}
int F_60 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_274 * V_13 ;
V_13 = F_127 ( V_2 , V_84 ) ;
if ( ! V_13 )
return - V_273 ;
F_4 ( L_19 , V_2 -> V_6 , V_84 ) ;
F_50 ( & V_13 -> V_91 ) ;
F_51 ( V_13 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_274 * V_13 , * V_80 ;
F_49 (data, n, &hdev->remote_oob_data, list) {
F_50 ( & V_13 -> V_91 ) ;
F_51 ( V_13 ) ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , T_6 * V_84 , T_8 * V_275 ,
T_8 * V_276 )
{
struct V_274 * V_13 ;
V_13 = F_127 ( V_2 , V_84 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_135 ;
F_63 ( & V_13 -> V_84 , V_84 ) ;
F_58 ( & V_13 -> V_91 , & V_2 -> V_277 ) ;
}
memcpy ( V_13 -> V_275 , V_275 , sizeof( V_13 -> V_275 ) ) ;
memcpy ( V_13 -> V_276 , V_276 , sizeof( V_13 -> V_276 ) ) ;
F_4 ( L_22 , V_2 -> V_6 , V_84 ) ;
return 0 ;
}
struct V_278 * F_130 ( struct V_1 * V_2 , T_6 * V_84 )
{
struct V_278 * V_279 ;
F_42 (b, &hdev->blacklist, list)
if ( F_54 ( V_84 , & V_279 -> V_84 ) == 0 )
return V_279 ;
return NULL ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_89 * V_79 , * V_80 ;
F_113 (p, n, &hdev->blacklist) {
struct V_278 * V_279 ;
V_279 = F_114 ( V_79 , struct V_278 , V_91 ) ;
F_50 ( V_79 ) ;
F_51 ( V_279 ) ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_6 * V_84 , T_8 type )
{
struct V_278 * V_280 ;
if ( F_54 ( V_84 , V_86 ) == 0 )
return - V_281 ;
if ( F_130 ( V_2 , V_84 ) )
return - V_282 ;
V_280 = F_61 ( sizeof( struct V_278 ) , V_134 ) ;
if ( ! V_280 )
return - V_135 ;
F_63 ( & V_280 -> V_84 , V_84 ) ;
F_58 ( & V_280 -> V_91 , & V_2 -> V_283 ) ;
return F_133 ( V_2 , V_84 , type ) ;
}
int F_134 ( struct V_1 * V_2 , T_6 * V_84 , T_8 type )
{
struct V_278 * V_280 ;
if ( F_54 ( V_84 , V_86 ) == 0 )
return F_131 ( V_2 ) ;
V_280 = F_130 ( V_2 , V_84 ) ;
if ( ! V_280 )
return - V_273 ;
F_50 ( & V_280 -> V_91 ) ;
F_51 ( V_280 ) ;
return F_135 ( V_2 , V_84 , type ) ;
}
static void F_136 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_284 * V_285 = (struct V_284 * ) V_29 ;
struct V_286 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . type = V_285 -> type ;
V_117 . V_287 = F_39 ( V_285 -> V_287 ) ;
V_117 . V_288 = F_39 ( V_285 -> V_288 ) ;
F_26 ( V_2 , V_289 , sizeof( V_117 ) , & V_117 ) ;
}
static void F_137 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_290 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_291 = 1 ;
V_117 . V_292 = 1 ;
F_26 ( V_2 , V_293 , sizeof( V_117 ) , & V_117 ) ;
}
static int F_138 ( struct V_1 * V_2 , T_8 type , T_2 V_287 ,
T_2 V_288 , int V_30 )
{
long V_127 = F_71 ( 3000 ) ;
struct V_284 V_285 ;
int V_27 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_294 , & V_2 -> V_139 ) )
return - V_295 ;
V_285 . type = type ;
V_285 . V_287 = V_287 ;
V_285 . V_288 = V_288 ;
F_22 ( V_2 ) ;
V_27 = F_12 ( V_2 , F_136 , ( unsigned long ) & V_285 ,
V_127 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_2 , F_137 , 0 , V_127 ) ;
F_23 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_107 ( V_2 -> V_20 , & V_2 -> V_186 ,
F_71 ( V_30 ) ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_294 , & V_2 -> V_139 ) )
return - V_163 ;
if ( F_91 ( & V_2 -> V_186 ) ) {
struct V_290 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_26 ( V_2 , V_293 , sizeof( V_117 ) , & V_117 ) ;
}
return 0 ;
}
static void F_140 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 ,
V_186 . V_235 ) ;
struct V_290 V_117 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_26 ( V_2 , V_293 , sizeof( V_117 ) , & V_117 ) ;
}
static void F_141 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_178 ) ;
struct V_284 * V_285 = & V_2 -> V_284 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_138 ( V_2 , V_285 -> type , V_285 -> V_287 , V_285 -> V_288 ,
V_285 -> V_30 ) ;
}
int F_142 ( struct V_1 * V_2 , T_8 type , T_2 V_287 , T_2 V_288 ,
int V_30 )
{
struct V_284 * V_285 = & V_2 -> V_284 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_138 , & V_2 -> V_139 ) )
return - V_296 ;
if ( F_143 ( & V_2 -> V_178 ) )
return - V_295 ;
V_285 -> type = type ;
V_285 -> V_287 = V_287 ;
V_285 -> V_288 = V_288 ;
V_285 -> V_30 = V_30 ;
F_9 ( V_297 , & V_2 -> V_178 ) ;
return 0 ;
}
struct V_1 * F_144 ( void )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( struct V_1 ) , V_134 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_48 = ( V_298 | V_299 | V_300 ) ;
V_2 -> V_301 = ( V_302 ) ;
V_2 -> V_208 = ( V_210 ) ;
V_2 -> V_303 = 0x03 ;
V_2 -> V_304 = V_146 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_305 = 800 ;
V_2 -> V_306 = 80 ;
F_145 ( & V_2 -> V_307 ) ;
F_145 ( & V_2 -> V_308 ) ;
F_52 ( & V_2 -> V_309 ) ;
F_52 ( & V_2 -> V_283 ) ;
F_52 ( & V_2 -> V_310 ) ;
F_52 ( & V_2 -> V_263 ) ;
F_52 ( & V_2 -> V_272 ) ;
F_52 ( & V_2 -> V_277 ) ;
F_52 ( & V_2 -> V_311 . V_91 ) ;
F_146 ( & V_2 -> V_174 , V_312 ) ;
F_146 ( & V_2 -> V_21 , V_313 ) ;
F_146 ( & V_2 -> V_173 , V_314 ) ;
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
V_67 = F_156 ( & V_315 , 0 , 0 , V_134 ) ;
break;
case V_55 :
V_67 = F_156 ( & V_315 , 1 , 0 , V_134 ) ;
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
F_58 ( & V_2 -> V_91 , & V_316 ) ;
F_158 ( & V_66 ) ;
V_2 -> V_20 = F_159 ( V_2 -> V_6 , V_317 | V_318 |
V_319 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_135 ;
goto V_27;
}
V_2 -> V_237 = F_159 ( V_2 -> V_6 ,
V_317 | V_318 |
V_319 , 1 ) ;
if ( ! V_2 -> V_237 ) {
F_160 ( V_2 -> V_20 ) ;
error = - V_135 ;
goto V_27;
}
error = F_161 ( V_2 ) ;
if ( error < 0 )
goto V_320;
V_2 -> V_161 = F_162 ( V_2 -> V_6 , & V_2 -> V_50 ,
V_321 , & V_322 ,
V_2 ) ;
if ( V_2 -> V_161 ) {
if ( F_163 ( V_2 -> V_161 ) < 0 ) {
F_164 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
}
}
F_25 ( V_172 , & V_2 -> V_139 ) ;
if ( V_2 -> V_53 != V_55 )
F_25 ( V_190 , & V_2 -> V_139 ) ;
F_1 ( V_2 , V_323 ) ;
F_43 ( V_2 ) ;
F_9 ( V_2 -> V_237 , & V_2 -> V_236 ) ;
return V_67 ;
V_320:
F_160 ( V_2 -> V_20 ) ;
F_160 ( V_2 -> V_237 ) ;
V_27:
F_165 ( & V_315 , V_2 -> V_67 ) ;
F_157 ( & V_66 ) ;
F_50 ( & V_2 -> V_91 ) ;
F_158 ( & V_66 ) ;
return error ;
}
void F_166 ( struct V_1 * V_2 )
{
int V_324 , V_67 ;
F_4 ( L_24 , V_2 , V_2 -> V_6 , V_2 -> V_228 ) ;
F_25 ( V_160 , & V_2 -> V_139 ) ;
V_67 = V_2 -> V_67 ;
F_157 ( & V_66 ) ;
F_50 ( & V_2 -> V_91 ) ;
F_158 ( & V_66 ) ;
F_89 ( V_2 ) ;
for ( V_324 = 0 ; V_324 < V_325 ; V_324 ++ )
F_88 ( V_2 -> V_326 [ V_324 ] ) ;
F_90 ( & V_2 -> V_236 ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_172 , & V_2 -> V_139 ) ) {
F_67 ( V_2 ) ;
F_167 ( V_2 ) ;
F_70 ( V_2 ) ;
}
F_168 ( ! F_169 ( & V_2 -> V_309 ) ) ;
F_1 ( V_2 , V_327 ) ;
if ( V_2 -> V_161 ) {
F_170 ( V_2 -> V_161 ) ;
F_164 ( V_2 -> V_161 ) ;
}
F_171 ( V_2 ) ;
F_160 ( V_2 -> V_20 ) ;
F_160 ( V_2 -> V_237 ) ;
F_67 ( V_2 ) ;
F_131 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_115 ( V_2 ) ;
F_128 ( V_2 ) ;
F_70 ( V_2 ) ;
F_74 ( V_2 ) ;
F_165 ( & V_315 , V_67 ) ;
}
int F_172 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_328 ) ;
return 0 ;
}
int F_173 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_329 ) ;
return 0 ;
}
int F_174 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_50 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_88 ( V_16 ) ;
return - V_330 ;
}
F_31 ( V_16 ) -> V_331 = 1 ;
F_175 ( V_16 ) ;
F_32 ( & V_2 -> V_175 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_174 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_332 , T_4 V_64 )
{
int V_154 = 0 ;
int V_333 = 0 ;
int V_334 = V_332 ;
struct V_15 * V_16 ;
struct V_335 * V_336 ;
if ( ( type < V_337 || type > V_338 ) ||
V_64 >= V_325 )
return - V_339 ;
V_16 = V_2 -> V_326 [ V_64 ] ;
if ( ! V_16 ) {
switch ( type ) {
case V_337 :
V_154 = V_340 ;
V_333 = V_341 ;
break;
case V_338 :
V_154 = V_342 ;
V_333 = V_343 ;
break;
case V_344 :
V_154 = V_345 ;
V_333 = V_346 ;
break;
}
V_16 = F_177 ( V_154 , V_18 ) ;
if ( ! V_16 )
return - V_135 ;
V_336 = ( void * ) V_16 -> V_347 ;
V_336 -> V_348 = V_333 ;
V_336 -> V_48 = type ;
V_16 -> V_50 = ( void * ) V_2 ;
V_2 -> V_326 [ V_64 ] = V_16 ;
}
while ( V_332 ) {
V_336 = ( void * ) V_16 -> V_347 ;
V_154 = F_178 ( V_349 , V_336 -> V_348 , V_332 ) ;
memcpy ( F_179 ( V_16 , V_154 ) , V_13 , V_154 ) ;
V_332 -= V_154 ;
V_13 += V_154 ;
V_336 -> V_348 -= V_154 ;
V_334 = V_332 ;
switch ( type ) {
case V_338 :
if ( V_16 -> V_154 == V_343 ) {
struct V_350 * V_351 = V_350 ( V_16 ) ;
V_336 -> V_348 = V_351 -> V_352 ;
if ( F_180 ( V_16 ) < V_336 -> V_348 ) {
F_88 ( V_16 ) ;
V_2 -> V_326 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
case V_337 :
if ( V_16 -> V_154 == V_341 ) {
struct V_353 * V_351 = V_353 ( V_16 ) ;
V_336 -> V_348 = F_6 ( V_351 -> V_354 ) ;
if ( F_180 ( V_16 ) < V_336 -> V_348 ) {
F_88 ( V_16 ) ;
V_2 -> V_326 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
case V_344 :
if ( V_16 -> V_154 == V_346 ) {
struct V_355 * V_351 = V_355 ( V_16 ) ;
V_336 -> V_348 = V_351 -> V_354 ;
if ( F_180 ( V_16 ) < V_336 -> V_348 ) {
F_88 ( V_16 ) ;
V_2 -> V_326 [ V_64 ] = NULL ;
return - V_135 ;
}
}
break;
}
if ( V_336 -> V_348 == 0 ) {
F_31 ( V_16 ) -> V_48 = type ;
F_174 ( V_16 ) ;
V_2 -> V_326 [ V_64 ] = NULL ;
return V_334 ;
}
}
return V_334 ;
}
int F_181 ( struct V_1 * V_2 , int type , void * V_13 , int V_332 )
{
int V_356 = 0 ;
if ( type < V_337 || type > V_338 )
return - V_339 ;
while ( V_332 ) {
V_356 = F_176 ( V_2 , type , V_13 , V_332 , type - 1 ) ;
if ( V_356 < 0 )
return V_356 ;
V_13 += ( V_332 - V_356 ) ;
V_332 = V_356 ;
}
return V_356 ;
}
int F_182 ( struct V_1 * V_2 , void * V_13 , int V_332 )
{
int type ;
int V_356 = 0 ;
while ( V_332 ) {
struct V_15 * V_16 = V_2 -> V_326 [ V_357 ] ;
if ( ! V_16 ) {
struct { char type ; } * V_358 ;
V_358 = V_13 ;
type = V_358 -> type ;
V_13 ++ ;
V_332 -- ;
} else
type = F_31 ( V_16 ) -> V_48 ;
V_356 = F_176 ( V_2 , type , V_13 , V_332 ,
V_357 ) ;
if ( V_356 < 0 )
return V_356 ;
V_13 += ( V_332 - V_356 ) ;
V_332 = V_356 ;
}
return V_356 ;
}
int F_183 ( struct V_359 * V_347 )
{
F_4 ( L_25 , V_347 , V_347 -> V_6 ) ;
F_157 ( & V_360 ) ;
F_58 ( & V_347 -> V_91 , & V_361 ) ;
F_158 ( & V_360 ) ;
return 0 ;
}
int F_184 ( struct V_359 * V_347 )
{
F_4 ( L_25 , V_347 , V_347 -> V_6 ) ;
F_157 ( & V_360 ) ;
F_50 ( & V_347 -> V_91 ) ;
F_158 ( & V_360 ) ;
return 0 ;
}
static int F_185 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_50 ;
if ( ! V_2 ) {
F_88 ( V_16 ) ;
return - V_130 ;
}
F_4 ( L_26 , V_2 -> V_6 , F_31 ( V_16 ) -> V_48 , V_16 -> V_154 ) ;
F_175 ( V_16 ) ;
F_186 ( V_2 , V_16 ) ;
if ( F_187 ( & V_2 -> V_362 ) ) {
F_188 ( V_2 , V_16 ) ;
}
F_189 ( V_16 ) ;
return V_2 -> V_363 ( V_16 ) ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_352 , void * V_285 )
{
int V_154 = V_364 + V_352 ;
struct V_10 * V_365 ;
struct V_15 * V_16 ;
F_4 ( L_27 , V_2 -> V_6 , V_14 , V_352 ) ;
V_16 = F_177 ( V_154 , V_18 ) ;
if ( ! V_16 ) {
F_34 ( L_28 , V_2 -> V_6 ) ;
return - V_135 ;
}
V_365 = (struct V_10 * ) F_179 ( V_16 , V_364 ) ;
V_365 -> V_14 = F_39 ( V_14 ) ;
V_365 -> V_352 = V_352 ;
if ( V_352 )
memcpy ( F_179 ( V_16 , V_352 ) , V_285 , V_352 ) ;
F_4 ( L_29 , V_16 -> V_154 ) ;
F_31 ( V_16 ) -> V_48 = V_49 ;
V_16 -> V_50 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_14 ;
F_32 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_190 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_365 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_365 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_365 -> V_14 != F_39 ( V_14 ) )
return NULL ;
F_4 ( L_30 , V_2 -> V_6 , V_14 ) ;
return V_2 -> V_12 -> V_13 + V_364 ;
}
static void F_191 ( struct V_15 * V_16 , T_1 V_366 , T_1 V_8 )
{
struct V_353 * V_365 ;
int V_154 = V_16 -> V_154 ;
F_192 ( V_16 , V_341 ) ;
F_193 ( V_16 ) ;
V_365 = (struct V_353 * ) F_194 ( V_16 ) ;
V_365 -> V_366 = F_39 ( F_195 ( V_366 , V_8 ) ) ;
V_365 -> V_354 = F_39 ( V_154 ) ;
}
static void F_196 ( struct V_367 * V_368 , struct V_369 * V_370 ,
struct V_15 * V_16 , T_1 V_8 )
{
struct V_247 * V_248 = V_368 -> V_248 ;
struct V_1 * V_2 = V_248 -> V_2 ;
struct V_15 * V_91 ;
V_16 -> V_154 = F_197 ( V_16 ) ;
V_16 -> V_371 = 0 ;
F_31 ( V_16 ) -> V_48 = V_337 ;
switch ( V_2 -> V_53 ) {
case V_54 :
F_191 ( V_16 , V_248 -> V_366 , V_8 ) ;
break;
case V_55 :
F_191 ( V_16 , V_368 -> V_366 , V_8 ) ;
break;
default:
F_34 ( L_31 , V_2 -> V_6 , V_2 -> V_53 ) ;
return;
}
V_91 = F_198 ( V_16 ) -> V_372 ;
if ( ! V_91 ) {
F_4 ( L_32 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_32 ( V_370 , V_16 ) ;
} else {
F_4 ( L_33 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_198 ( V_16 ) -> V_372 = NULL ;
F_199 ( & V_370 -> V_307 ) ;
F_200 ( V_370 , V_16 ) ;
V_8 &= ~ V_373 ;
V_8 |= V_374 ;
do {
V_16 = V_91 ; V_91 = V_91 -> V_375 ;
V_16 -> V_50 = ( void * ) V_2 ;
F_31 ( V_16 ) -> V_48 = V_337 ;
F_191 ( V_16 , V_248 -> V_366 , V_8 ) ;
F_4 ( L_33 , V_2 -> V_6 , V_16 , V_16 -> V_154 ) ;
F_200 ( V_370 , V_16 ) ;
} while ( V_91 );
F_201 ( & V_370 -> V_307 ) ;
}
}
void F_202 ( struct V_367 * V_368 , struct V_15 * V_16 , T_1 V_8 )
{
struct V_1 * V_2 = V_368 -> V_248 -> V_2 ;
F_4 ( L_34 , V_2 -> V_6 , V_368 , V_8 ) ;
V_16 -> V_50 = ( void * ) V_2 ;
F_196 ( V_368 , & V_368 -> V_376 , V_16 , V_8 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_173 ) ;
}
void F_203 ( struct V_247 * V_248 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_248 -> V_2 ;
struct V_355 V_365 ;
F_4 ( L_35 , V_2 -> V_6 , V_16 -> V_154 ) ;
V_365 . V_366 = F_39 ( V_248 -> V_366 ) ;
V_365 . V_354 = V_16 -> V_154 ;
F_192 ( V_16 , V_346 ) ;
F_193 ( V_16 ) ;
memcpy ( F_194 ( V_16 ) , & V_365 , V_346 ) ;
V_16 -> V_50 = ( void * ) V_2 ;
F_31 ( V_16 ) -> V_48 = V_344 ;
F_32 ( & V_248 -> V_376 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_173 ) ;
}
static struct V_247 * F_204 ( struct V_1 * V_2 , T_4 type ,
int * V_377 )
{
struct V_378 * V_351 = & V_2 -> V_311 ;
struct V_247 * V_248 = NULL , * V_379 ;
unsigned int V_104 = 0 , V_380 = ~ 0 ;
F_205 () ;
F_206 (c, &h->list, list) {
if ( V_379 -> type != type || F_207 ( & V_379 -> V_376 ) )
continue;
if ( V_379 -> V_71 != V_381 && V_379 -> V_71 != V_382 )
continue;
V_104 ++ ;
if ( V_379 -> V_11 < V_380 ) {
V_380 = V_379 -> V_11 ;
V_248 = V_379 ;
}
if ( F_208 ( V_2 , type ) == V_104 )
break;
}
F_209 () ;
if ( V_248 ) {
int V_383 , V_384 ;
switch ( V_248 -> type ) {
case V_385 :
V_383 = V_2 -> V_193 ;
break;
case V_386 :
case V_387 :
V_383 = V_2 -> V_194 ;
break;
case V_388 :
V_383 = V_2 -> V_229 ? V_2 -> V_195 : V_2 -> V_193 ;
break;
default:
V_383 = 0 ;
F_34 ( L_36 ) ;
}
V_384 = V_383 / V_104 ;
* V_377 = V_384 ? V_384 : 1 ;
} else
* V_377 = 0 ;
F_4 ( L_37 , V_248 , * V_377 ) ;
return V_248 ;
}
static void F_210 ( struct V_1 * V_2 , T_4 type )
{
struct V_378 * V_351 = & V_2 -> V_311 ;
struct V_247 * V_379 ;
F_34 ( L_38 , V_2 -> V_6 ) ;
F_205 () ;
F_206 (c, &h->list, list) {
if ( V_379 -> type == type && V_379 -> V_11 ) {
F_34 ( L_39 ,
V_2 -> V_6 , & V_379 -> V_389 ) ;
F_211 ( V_379 , V_390 ) ;
}
}
F_209 () ;
}
static struct V_367 * F_212 ( struct V_1 * V_2 , T_4 type ,
int * V_377 )
{
struct V_378 * V_351 = & V_2 -> V_311 ;
struct V_367 * V_368 = NULL ;
unsigned int V_104 = 0 , V_380 = ~ 0 , V_391 = 0 ;
struct V_247 * V_248 ;
int V_383 , V_384 , V_392 = 0 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_205 () ;
F_206 (conn, &h->list, list) {
struct V_367 * V_242 ;
if ( V_248 -> type != type )
continue;
if ( V_248 -> V_71 != V_381 && V_248 -> V_71 != V_382 )
continue;
V_392 ++ ;
F_206 (tmp, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( F_207 ( & V_242 -> V_376 ) )
continue;
V_16 = F_213 ( & V_242 -> V_376 ) ;
if ( V_16 -> V_393 < V_391 )
continue;
if ( V_16 -> V_393 > V_391 ) {
V_104 = 0 ;
V_380 = ~ 0 ;
V_391 = V_16 -> V_393 ;
}
V_104 ++ ;
if ( V_248 -> V_11 < V_380 ) {
V_380 = V_248 -> V_11 ;
V_368 = V_242 ;
}
}
if ( F_208 ( V_2 , type ) == V_392 )
break;
}
F_209 () ;
if ( ! V_368 )
return NULL ;
switch ( V_368 -> V_248 -> type ) {
case V_385 :
V_383 = V_2 -> V_193 ;
break;
case V_394 :
V_383 = V_2 -> V_395 ;
break;
case V_386 :
case V_387 :
V_383 = V_2 -> V_194 ;
break;
case V_388 :
V_383 = V_2 -> V_229 ? V_2 -> V_195 : V_2 -> V_193 ;
break;
default:
V_383 = 0 ;
F_34 ( L_36 ) ;
}
V_384 = V_383 / V_104 ;
* V_377 = V_384 ? V_384 : 1 ;
F_4 ( L_40 , V_368 , * V_377 ) ;
return V_368 ;
}
static void F_214 ( struct V_1 * V_2 , T_4 type )
{
struct V_378 * V_351 = & V_2 -> V_311 ;
struct V_247 * V_248 ;
int V_104 = 0 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
F_205 () ;
F_206 (conn, &h->list, list) {
struct V_367 * V_368 ;
if ( V_248 -> type != type )
continue;
if ( V_248 -> V_71 != V_381 && V_248 -> V_71 != V_382 )
continue;
V_104 ++ ;
F_206 (chan, &conn->chan_list, list) {
struct V_15 * V_16 ;
if ( V_368 -> V_11 ) {
V_368 -> V_11 = 0 ;
continue;
}
if ( F_207 ( & V_368 -> V_376 ) )
continue;
V_16 = F_213 ( & V_368 -> V_376 ) ;
if ( V_16 -> V_393 >= V_396 - 1 )
continue;
V_16 -> V_393 = V_396 - 1 ;
F_4 ( L_41 , V_368 , V_16 ,
V_16 -> V_393 ) ;
}
if ( F_208 ( V_2 , type ) == V_104 )
break;
}
F_209 () ;
}
static inline int F_215 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return F_216 ( V_16 -> V_154 - V_341 , V_2 -> V_397 ) ;
}
static void F_217 ( struct V_1 * V_2 , unsigned int V_383 )
{
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) ) {
if ( ! V_383 && F_218 ( V_103 , V_2 -> V_398 +
V_399 ) )
F_210 ( V_2 , V_385 ) ;
}
}
static void F_219 ( struct V_1 * V_2 )
{
unsigned int V_383 = V_2 -> V_193 ;
struct V_367 * V_368 ;
struct V_15 * V_16 ;
int V_377 ;
F_217 ( V_2 , V_383 ) ;
while ( V_2 -> V_193 &&
( V_368 = F_212 ( V_2 , V_385 , & V_377 ) ) ) {
T_10 V_393 = ( F_213 ( & V_368 -> V_376 ) ) -> V_393 ;
while ( V_377 -- && ( V_16 = F_213 ( & V_368 -> V_376 ) ) ) {
F_4 ( L_42 , V_368 , V_16 ,
V_16 -> V_154 , V_16 -> V_393 ) ;
if ( V_16 -> V_393 < V_393 )
break;
V_16 = F_30 ( & V_368 -> V_376 ) ;
F_220 ( V_368 -> V_248 ,
F_31 ( V_16 ) -> V_400 ) ;
F_185 ( V_16 ) ;
V_2 -> V_398 = V_103 ;
V_2 -> V_193 -- ;
V_368 -> V_11 ++ ;
V_368 -> V_248 -> V_11 ++ ;
}
}
if ( V_383 != V_2 -> V_193 )
F_214 ( V_2 , V_385 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
unsigned int V_383 = V_2 -> V_395 ;
struct V_367 * V_368 ;
struct V_15 * V_16 ;
int V_377 ;
T_8 type ;
F_217 ( V_2 , V_383 ) ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( V_2 -> V_53 == V_55 )
type = V_394 ;
else
type = V_385 ;
while ( V_2 -> V_395 > 0 &&
( V_368 = F_212 ( V_2 , type , & V_377 ) ) ) {
T_10 V_393 = ( F_213 ( & V_368 -> V_376 ) ) -> V_393 ;
while ( V_377 > 0 && ( V_16 = F_213 ( & V_368 -> V_376 ) ) ) {
int V_401 ;
F_4 ( L_42 , V_368 , V_16 ,
V_16 -> V_154 , V_16 -> V_393 ) ;
if ( V_16 -> V_393 < V_393 )
break;
V_16 = F_30 ( & V_368 -> V_376 ) ;
V_401 = F_215 ( V_2 , V_16 ) ;
if ( V_401 > V_2 -> V_395 )
return;
F_220 ( V_368 -> V_248 ,
F_31 ( V_16 ) -> V_400 ) ;
F_185 ( V_16 ) ;
V_2 -> V_398 = V_103 ;
V_2 -> V_395 -= V_401 ;
V_377 -= V_401 ;
V_368 -> V_11 += V_401 ;
V_368 -> V_248 -> V_11 += V_401 ;
}
}
if ( V_383 != V_2 -> V_395 )
F_214 ( V_2 , type ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_208 ( V_2 , V_385 ) && V_2 -> V_53 == V_54 )
return;
if ( ! F_208 ( V_2 , V_394 ) && V_2 -> V_53 == V_55 )
return;
switch ( V_2 -> V_40 ) {
case V_41 :
F_219 ( V_2 ) ;
break;
case V_44 :
F_221 ( V_2 ) ;
break;
}
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_247 * V_248 ;
struct V_15 * V_16 ;
int V_377 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_208 ( V_2 , V_386 ) )
return;
while ( V_2 -> V_194 && ( V_248 = F_204 ( V_2 , V_386 , & V_377 ) ) ) {
while ( V_377 -- && ( V_16 = F_30 ( & V_248 -> V_376 ) ) ) {
F_4 ( L_43 , V_16 , V_16 -> V_154 ) ;
F_185 ( V_16 ) ;
V_248 -> V_11 ++ ;
if ( V_248 -> V_11 == ~ 0 )
V_248 -> V_11 = 0 ;
}
}
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_247 * V_248 ;
struct V_15 * V_16 ;
int V_377 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_208 ( V_2 , V_387 ) )
return;
while ( V_2 -> V_194 && ( V_248 = F_204 ( V_2 , V_387 ,
& V_377 ) ) ) {
while ( V_377 -- && ( V_16 = F_30 ( & V_248 -> V_376 ) ) ) {
F_4 ( L_43 , V_16 , V_16 -> V_154 ) ;
F_185 ( V_16 ) ;
V_248 -> V_11 ++ ;
if ( V_248 -> V_11 == ~ 0 )
V_248 -> V_11 = 0 ;
}
}
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_367 * V_368 ;
struct V_15 * V_16 ;
int V_377 , V_383 , V_242 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_208 ( V_2 , V_388 ) )
return;
if ( ! F_5 ( V_165 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_195 && V_2 -> V_230 &&
F_218 ( V_103 , V_2 -> V_402 + V_403 * 45 ) )
F_210 ( V_2 , V_388 ) ;
}
V_383 = V_2 -> V_230 ? V_2 -> V_195 : V_2 -> V_193 ;
V_242 = V_383 ;
while ( V_383 && ( V_368 = F_212 ( V_2 , V_388 , & V_377 ) ) ) {
T_10 V_393 = ( F_213 ( & V_368 -> V_376 ) ) -> V_393 ;
while ( V_377 -- && ( V_16 = F_213 ( & V_368 -> V_376 ) ) ) {
F_4 ( L_42 , V_368 , V_16 ,
V_16 -> V_154 , V_16 -> V_393 ) ;
if ( V_16 -> V_393 < V_393 )
break;
V_16 = F_30 ( & V_368 -> V_376 ) ;
F_185 ( V_16 ) ;
V_2 -> V_402 = V_103 ;
V_383 -- ;
V_368 -> V_11 ++ ;
V_368 -> V_248 -> V_11 ++ ;
}
}
if ( V_2 -> V_230 )
V_2 -> V_195 = V_383 ;
else
V_2 -> V_193 = V_383 ;
if ( V_383 != V_242 )
F_214 ( V_2 , V_388 ) ;
}
static void V_314 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_173 ) ;
struct V_15 * V_16 ;
F_4 ( L_44 , V_2 -> V_6 , V_2 -> V_193 ,
V_2 -> V_194 , V_2 -> V_195 ) ;
F_222 ( V_2 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
while ( ( V_16 = F_30 ( & V_2 -> V_189 ) ) )
F_185 ( V_16 ) ;
}
static void F_226 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_353 * V_365 = ( void * ) V_16 -> V_13 ;
struct V_247 * V_248 ;
T_1 V_366 , V_8 ;
F_227 ( V_16 , V_341 ) ;
V_366 = F_6 ( V_365 -> V_366 ) ;
V_8 = F_228 ( V_366 ) ;
V_366 = F_229 ( V_366 ) ;
F_4 ( L_45 , V_2 -> V_6 , V_16 -> V_154 ,
V_366 , V_8 ) ;
V_2 -> V_196 . V_404 ++ ;
F_67 ( V_2 ) ;
V_248 = F_230 ( V_2 , V_366 ) ;
F_70 ( V_2 ) ;
if ( V_248 ) {
F_220 ( V_248 , V_405 ) ;
F_231 ( V_248 , V_16 , V_8 ) ;
return;
} else {
F_34 ( L_46 ,
V_2 -> V_6 , V_366 ) ;
}
F_88 ( V_16 ) ;
}
static void F_232 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_355 * V_365 = ( void * ) V_16 -> V_13 ;
struct V_247 * V_248 ;
T_1 V_366 ;
F_227 ( V_16 , V_346 ) ;
V_366 = F_6 ( V_365 -> V_366 ) ;
F_4 ( L_47 , V_2 -> V_6 , V_16 -> V_154 , V_366 ) ;
V_2 -> V_196 . V_406 ++ ;
F_67 ( V_2 ) ;
V_248 = F_230 ( V_2 , V_366 ) ;
F_70 ( V_2 ) ;
if ( V_248 ) {
F_233 ( V_248 , V_16 ) ;
return;
} else {
F_34 ( L_48 ,
V_2 -> V_6 , V_366 ) ;
}
F_88 ( V_16 ) ;
}
static void V_312 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_174 ) ;
struct V_15 * V_16 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
while ( ( V_16 = F_30 ( & V_2 -> V_175 ) ) ) {
F_186 ( V_2 , V_16 ) ;
if ( F_187 ( & V_2 -> V_362 ) ) {
F_188 ( V_2 , V_16 ) ;
}
if ( F_5 ( V_165 , & V_2 -> V_8 ) ) {
F_88 ( V_16 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_31 ( V_16 ) -> V_48 ) {
case V_337 :
case V_344 :
F_88 ( V_16 ) ;
continue;
}
}
switch ( F_31 ( V_16 ) -> V_48 ) {
case V_338 :
F_4 ( L_49 , V_2 -> V_6 ) ;
F_234 ( V_2 , V_16 ) ;
break;
case V_337 :
F_4 ( L_50 , V_2 -> V_6 ) ;
F_226 ( V_2 , V_16 ) ;
break;
case V_344 :
F_4 ( L_51 , V_2 -> V_6 ) ;
F_232 ( V_2 , V_16 ) ;
break;
default:
F_88 ( V_16 ) ;
break;
}
}
}
static void V_313 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_106 ( V_235 , struct V_1 , V_21 ) ;
struct V_15 * V_16 ;
F_4 ( L_52 , V_2 -> V_6 ,
F_187 ( & V_2 -> V_169 ) , F_235 ( & V_2 -> V_19 ) ) ;
if ( F_187 ( & V_2 -> V_169 ) ) {
V_16 = F_30 ( & V_2 -> V_19 ) ;
if ( ! V_16 )
return;
F_88 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_7 ( V_16 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_236 ( & V_2 -> V_169 ) ;
F_185 ( V_16 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_237 ( & V_2 -> V_180 ) ;
else
F_238 ( & V_2 -> V_180 ,
V_103 + V_188 ) ;
} else {
F_8 ( & V_2 -> V_19 , V_16 ) ;
F_9 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_239 ( struct V_1 * V_2 , T_8 V_120 )
{
T_8 V_119 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_116 V_117 ;
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( F_5 ( V_118 , & V_2 -> V_8 ) )
return - V_295 ;
F_48 ( V_2 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
memcpy ( & V_117 . V_119 , V_119 , sizeof( V_117 . V_119 ) ) ;
V_117 . V_120 = V_120 ;
return F_26 ( V_2 , V_122 , sizeof( V_117 ) , & V_117 ) ;
}
int F_240 ( struct V_1 * V_2 )
{
F_4 ( L_13 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_118 , & V_2 -> V_8 ) )
return - V_163 ;
return F_26 ( V_2 , V_407 , 0 , NULL ) ;
}
T_8 F_241 ( T_8 V_257 )
{
switch ( V_257 ) {
case V_408 :
return V_409 ;
default:
return V_410 ;
}
}
