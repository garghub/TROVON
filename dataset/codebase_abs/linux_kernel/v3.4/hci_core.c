static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_4 , int V_5 )
{
F_4 ( L_1 , V_2 -> V_6 , V_4 , V_5 ) ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) && V_2 -> V_9 != V_4 ) {
struct V_10 * V_11 = ( void * ) V_2 -> V_12 -> V_13 ;
struct V_14 * V_15 ;
if ( V_4 != V_16 || V_11 -> V_17 == V_16 )
return;
V_15 = F_6 ( V_2 -> V_12 , V_18 ) ;
if ( V_15 ) {
F_7 ( & V_2 -> V_19 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
return;
}
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_24 = V_5 ;
V_2 -> V_22 = V_25 ;
F_9 ( & V_2 -> V_26 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_27 )
{
F_4 ( L_2 , V_2 -> V_6 , V_27 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_24 = V_27 ;
V_2 -> V_22 = V_28 ;
F_9 ( & V_2 -> V_26 ) ;
}
}
static int F_11 ( struct V_1 * V_2 , void (* F_12)( struct V_1 * V_2 , unsigned long V_29 ) ,
unsigned long V_29 , T_2 V_30 )
{
F_13 ( V_31 , V_32 ) ;
int V_27 = 0 ;
F_4 ( L_3 , V_2 -> V_6 ) ;
V_2 -> V_22 = V_23 ;
F_14 ( & V_2 -> V_26 , & V_31 ) ;
F_15 ( V_33 ) ;
F_12 ( V_2 , V_29 ) ;
F_16 ( V_30 ) ;
F_17 ( & V_2 -> V_26 , & V_31 ) ;
if ( F_18 ( V_32 ) )
return - V_34 ;
switch ( V_2 -> V_22 ) {
case V_25 :
V_27 = - F_19 ( V_2 -> V_24 ) ;
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
static inline int F_20 ( struct V_1 * V_2 , void (* F_12)( struct V_1 * V_2 , unsigned long V_29 ) ,
unsigned long V_29 , T_2 V_30 )
{
int V_36 ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
return - V_38 ;
F_21 ( V_2 ) ;
V_36 = F_11 ( V_2 , F_12 , V_29 , V_30 ) ;
F_22 ( V_2 ) ;
return V_36 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
F_24 ( V_39 , & V_2 -> V_8 ) ;
F_25 ( V_2 , V_16 , 0 , NULL ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_40 V_41 ;
T_3 V_42 ;
T_4 V_43 ;
V_2 -> V_44 = V_45 ;
if ( ! F_5 ( V_46 , & V_2 -> V_47 ) ) {
F_24 ( V_39 , & V_2 -> V_8 ) ;
F_25 ( V_2 , V_16 , 0 , NULL ) ;
}
F_25 ( V_2 , V_48 , 0 , NULL ) ;
F_25 ( V_2 , V_49 , 0 , NULL ) ;
F_25 ( V_2 , V_50 , 0 , NULL ) ;
F_25 ( V_2 , V_51 , 0 , NULL ) ;
F_25 ( V_2 , V_52 , 0 , NULL ) ;
F_25 ( V_2 , V_53 , 0 , NULL ) ;
F_25 ( V_2 , V_54 , 0 , NULL ) ;
V_43 = V_55 ;
F_25 ( V_2 , V_56 , 1 , & V_43 ) ;
V_42 = F_27 ( 0x7d00 ) ;
F_25 ( V_2 , V_57 , 2 , & V_42 ) ;
F_28 ( & V_41 . V_58 , V_59 ) ;
V_41 . V_60 = 1 ;
F_25 ( V_2 , V_61 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_44 = V_62 ;
F_25 ( V_2 , V_16 , 0 , NULL ) ;
F_25 ( V_2 , V_49 , 0 , NULL ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_14 * V_15 ;
F_4 ( L_5 , V_2 -> V_6 , V_29 ) ;
while ( ( V_15 = F_31 ( & V_2 -> V_63 ) ) ) {
F_32 ( V_15 ) -> V_64 = V_65 ;
V_15 -> V_66 = ( void * ) V_2 ;
F_33 ( & V_2 -> V_19 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
F_34 ( & V_2 -> V_63 ) ;
switch ( V_2 -> V_67 ) {
case V_68 :
F_26 ( V_2 ) ;
break;
case V_69 :
F_29 ( V_2 ) ;
break;
default:
F_35 ( L_6 , V_2 -> V_67 ) ;
break;
}
}
static void F_36 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
F_25 ( V_2 , V_70 , 0 , NULL ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_71 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_71 ) ;
F_25 ( V_2 , V_72 , 1 , & V_71 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_73 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_73 ) ;
F_25 ( V_2 , V_74 , 1 , & V_73 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_4 V_75 = V_29 ;
F_4 ( L_8 , V_2 -> V_6 , V_75 ) ;
F_25 ( V_2 , V_76 , 1 , & V_75 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_29 )
{
T_3 V_77 = F_27 ( V_29 ) ;
F_4 ( L_8 , V_2 -> V_6 , V_77 ) ;
F_25 ( V_2 , V_78 , 2 , & V_77 ) ;
}
struct V_1 * F_41 ( int V_79 )
{
struct V_1 * V_2 = NULL , * V_80 ;
F_4 ( L_9 , V_79 ) ;
if ( V_79 < 0 )
return NULL ;
F_42 ( & V_81 ) ;
F_43 (d, &hci_dev_list, list) {
if ( V_80 -> V_82 == V_79 ) {
V_2 = F_44 ( V_80 ) ;
break;
}
}
F_45 ( & V_81 ) ;
return V_2 ;
}
bool F_46 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_85 ;
switch ( V_84 -> V_86 ) {
case V_87 :
case V_88 :
return true ;
default:
return false ;
}
}
void F_47 ( struct V_1 * V_2 , int V_86 )
{
F_4 ( L_10 , V_2 -> V_6 , V_2 -> V_85 . V_86 , V_86 ) ;
if ( V_2 -> V_85 . V_86 == V_86 )
return;
switch ( V_86 ) {
case V_89 :
if ( V_2 -> V_85 . V_86 != V_90 )
F_48 ( V_2 , 0 ) ;
V_2 -> V_85 . type = 0 ;
break;
case V_90 :
break;
case V_87 :
F_48 ( V_2 , 1 ) ;
break;
case V_88 :
break;
case V_91 :
break;
}
V_2 -> V_85 . V_86 = V_86 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_93 * V_94 , * V_95 ;
F_50 (p, n, &cache->all, all) {
F_51 ( & V_94 -> V_96 ) ;
F_52 ( V_94 ) ;
}
F_53 ( & V_92 -> V_97 ) ;
F_53 ( & V_92 -> V_98 ) ;
}
struct V_93 * F_54 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_93 * V_99 ;
F_4 ( L_11 , V_92 , F_55 ( V_58 ) ) ;
F_43 (e, &cache->all, all) {
if ( ! F_56 ( & V_99 -> V_13 . V_58 , V_58 ) )
return V_99 ;
}
return NULL ;
}
struct V_93 * F_57 ( struct V_1 * V_2 ,
T_5 * V_58 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_93 * V_99 ;
F_4 ( L_11 , V_92 , F_55 ( V_58 ) ) ;
F_43 (e, &cache->unknown, list) {
if ( ! F_56 ( & V_99 -> V_13 . V_58 , V_58 ) )
return V_99 ;
}
return NULL ;
}
struct V_93 * F_58 ( struct V_1 * V_2 ,
T_5 * V_58 ,
int V_86 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_93 * V_99 ;
F_4 ( L_12 , V_92 , F_55 ( V_58 ) , V_86 ) ;
F_43 (e, &cache->resolve, list) {
if ( ! F_56 ( V_58 , V_59 ) && V_99 -> V_100 == V_86 )
return V_99 ;
if ( ! F_56 ( & V_99 -> V_13 . V_58 , V_58 ) )
return V_99 ;
}
return NULL ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_93 * V_101 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_102 * V_103 = & V_92 -> V_98 ;
struct V_93 * V_94 ;
F_51 ( & V_101 -> V_104 ) ;
F_43 (p, &cache->resolve, list) {
if ( V_94 -> V_100 != V_105 &&
abs ( V_94 -> V_13 . V_106 ) >= abs ( V_101 -> V_13 . V_106 ) )
break;
V_103 = & V_94 -> V_104 ;
}
F_60 ( & V_101 -> V_104 , V_103 ) ;
}
bool F_61 ( struct V_1 * V_2 , struct V_107 * V_13 ,
bool V_108 , bool * V_109 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_93 * V_101 ;
F_4 ( L_11 , V_92 , F_55 ( & V_13 -> V_58 ) ) ;
if ( V_109 )
* V_109 = V_13 -> V_110 ;
V_101 = F_54 ( V_2 , & V_13 -> V_58 ) ;
if ( V_101 ) {
if ( V_101 -> V_13 . V_110 && V_109 )
* V_109 = true ;
if ( V_101 -> V_100 == V_111 &&
V_13 -> V_106 != V_101 -> V_13 . V_106 ) {
V_101 -> V_13 . V_106 = V_13 -> V_106 ;
F_59 ( V_2 , V_101 ) ;
}
goto V_112;
}
V_101 = F_62 ( sizeof( struct V_93 ) , V_18 ) ;
if ( ! V_101 )
return false ;
F_60 ( & V_101 -> V_96 , & V_92 -> V_96 ) ;
if ( V_108 ) {
V_101 -> V_100 = V_113 ;
} else {
V_101 -> V_100 = V_114 ;
F_60 ( & V_101 -> V_104 , & V_92 -> V_97 ) ;
}
V_112:
if ( V_108 && V_101 -> V_100 != V_113 &&
V_101 -> V_100 != V_105 ) {
V_101 -> V_100 = V_113 ;
F_51 ( & V_101 -> V_104 ) ;
}
memcpy ( & V_101 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_101 -> V_115 = V_116 ;
V_92 -> V_115 = V_116 ;
if ( V_101 -> V_100 == V_114 )
return false ;
return true ;
}
static int F_63 ( struct V_1 * V_2 , int V_117 , T_4 * V_118 )
{
struct V_83 * V_92 = & V_2 -> V_85 ;
struct V_119 * V_120 = (struct V_119 * ) V_118 ;
struct V_93 * V_99 ;
int V_121 = 0 ;
F_43 (e, &cache->all, all) {
struct V_107 * V_13 = & V_99 -> V_13 ;
if ( V_121 >= V_117 )
break;
F_28 ( & V_120 -> V_58 , & V_13 -> V_58 ) ;
V_120 -> V_122 = V_13 -> V_122 ;
V_120 -> V_123 = V_13 -> V_123 ;
V_120 -> V_124 = V_13 -> V_124 ;
memcpy ( V_120 -> V_125 , V_13 -> V_125 , 3 ) ;
V_120 -> V_126 = V_13 -> V_126 ;
V_120 ++ ;
V_121 ++ ;
}
F_4 ( L_13 , V_92 , V_121 ) ;
return V_121 ;
}
static void F_64 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_127 * V_128 = (struct V_127 * ) V_29 ;
struct V_129 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_130 , & V_2 -> V_8 ) )
return;
memcpy ( & V_41 . V_131 , & V_128 -> V_131 , 3 ) ;
V_41 . V_132 = V_128 -> V_132 ;
V_41 . V_133 = V_128 -> V_133 ;
F_25 ( V_2 , V_134 , sizeof( V_41 ) , & V_41 ) ;
}
int F_65 ( void T_6 * V_135 )
{
T_4 T_6 * V_136 = V_135 ;
struct V_127 V_128 ;
struct V_1 * V_2 ;
int V_27 = 0 , V_137 = 0 , V_138 ;
long V_139 ;
T_4 * V_118 ;
if ( F_66 ( & V_128 , V_136 , sizeof( V_128 ) ) )
return - V_140 ;
V_2 = F_41 ( V_128 . V_141 ) ;
if ( ! V_2 )
return - V_142 ;
F_67 ( V_2 ) ;
if ( F_68 ( V_2 ) > V_143 ||
F_69 ( V_2 ) ||
V_128 . V_8 & V_144 ) {
F_49 ( V_2 ) ;
V_137 = 1 ;
}
F_70 ( V_2 ) ;
V_139 = V_128 . V_132 * F_71 ( 2000 ) ;
if ( V_137 ) {
V_27 = F_20 ( V_2 , F_64 , ( unsigned long ) & V_128 , V_139 ) ;
if ( V_27 < 0 )
goto V_145;
}
V_138 = ( V_128 . V_133 == 0 ) ? 255 : V_128 . V_133 ;
V_118 = F_72 ( sizeof( struct V_119 ) * V_138 , V_146 ) ;
if ( ! V_118 ) {
V_27 = - V_147 ;
goto V_145;
}
F_67 ( V_2 ) ;
V_128 . V_133 = F_63 ( V_2 , V_138 , V_118 ) ;
F_70 ( V_2 ) ;
F_4 ( L_14 , V_128 . V_133 ) ;
if ( ! F_73 ( V_136 , & V_128 , sizeof( V_128 ) ) ) {
V_136 += sizeof( V_128 ) ;
if ( F_73 ( V_136 , V_118 , sizeof( struct V_119 ) *
V_128 . V_133 ) )
V_27 = - V_140 ;
} else
V_27 = - V_140 ;
F_52 ( V_118 ) ;
V_145:
F_74 ( V_2 ) ;
return V_27 ;
}
int F_75 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_41 ( V_66 ) ;
if ( ! V_2 )
return - V_142 ;
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_21 ( V_2 ) ;
if ( F_5 ( V_148 , & V_2 -> V_149 ) ) {
V_36 = - V_142 ;
goto V_145;
}
if ( V_2 -> V_150 && F_76 ( V_2 -> V_150 ) ) {
V_36 = - V_151 ;
goto V_145;
}
if ( F_5 ( V_37 , & V_2 -> V_8 ) ) {
V_36 = - V_152 ;
goto V_145;
}
if ( F_5 ( V_153 , & V_2 -> V_47 ) )
F_24 ( V_154 , & V_2 -> V_8 ) ;
if ( V_2 -> V_67 != V_68 && ! V_155 )
F_24 ( V_154 , & V_2 -> V_8 ) ;
if ( V_2 -> V_156 ( V_2 ) ) {
V_36 = - V_157 ;
goto V_145;
}
if ( ! F_5 ( V_154 , & V_2 -> V_8 ) ) {
F_77 ( & V_2 -> V_158 , 1 ) ;
F_24 ( V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_36 = F_11 ( V_2 , F_30 , 0 ,
F_71 ( V_159 ) ) ;
if ( F_78 ( V_2 ) )
V_36 = F_11 ( V_2 , F_36 , 0 ,
F_71 ( V_159 ) ) ;
F_79 ( V_7 , & V_2 -> V_8 ) ;
}
if ( ! V_36 ) {
F_44 ( V_2 ) ;
F_24 ( V_37 , & V_2 -> V_8 ) ;
F_1 ( V_2 , V_160 ) ;
if ( ! F_5 ( V_161 , & V_2 -> V_149 ) ) {
F_67 ( V_2 ) ;
F_80 ( V_2 , 1 ) ;
F_70 ( V_2 ) ;
}
} else {
F_81 ( & V_2 -> V_162 ) ;
F_81 ( & V_2 -> V_21 ) ;
F_81 ( & V_2 -> V_163 ) ;
F_34 ( & V_2 -> V_19 ) ;
F_34 ( & V_2 -> V_164 ) ;
if ( V_2 -> V_165 )
V_2 -> V_165 ( V_2 ) ;
if ( V_2 -> V_12 ) {
F_82 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_166 ( V_2 ) ;
V_2 -> V_8 = 0 ;
}
V_145:
F_22 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_4 ( L_15 , V_2 -> V_6 , V_2 ) ;
F_84 ( & V_2 -> V_167 ) ;
F_10 ( V_2 , V_142 ) ;
F_21 ( V_2 ) ;
if ( ! F_85 ( V_37 , & V_2 -> V_8 ) ) {
F_86 ( & V_2 -> V_168 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
F_81 ( & V_2 -> V_162 ) ;
F_81 ( & V_2 -> V_163 ) ;
if ( V_2 -> V_169 > 0 ) {
F_87 ( & V_2 -> V_170 ) ;
V_2 -> V_169 = 0 ;
F_79 ( V_171 , & V_2 -> V_149 ) ;
}
if ( F_85 ( V_172 , & V_2 -> V_149 ) )
F_87 ( & V_2 -> V_173 ) ;
F_88 ( & V_2 -> V_174 ) ;
F_67 ( V_2 ) ;
F_49 ( V_2 ) ;
F_89 ( V_2 ) ;
F_70 ( V_2 ) ;
F_1 ( V_2 , V_175 ) ;
if ( V_2 -> V_165 )
V_2 -> V_165 ( V_2 ) ;
F_34 ( & V_2 -> V_19 ) ;
F_77 ( & V_2 -> V_158 , 1 ) ;
if ( ! F_5 ( V_154 , & V_2 -> V_8 ) &&
F_5 ( V_46 , & V_2 -> V_47 ) ) {
F_24 ( V_7 , & V_2 -> V_8 ) ;
F_11 ( V_2 , F_23 , 0 ,
F_71 ( 250 ) ) ;
F_79 ( V_7 , & V_2 -> V_8 ) ;
}
F_81 ( & V_2 -> V_21 ) ;
F_34 ( & V_2 -> V_164 ) ;
F_34 ( & V_2 -> V_19 ) ;
F_34 ( & V_2 -> V_176 ) ;
if ( V_2 -> V_12 ) {
F_86 ( & V_2 -> V_168 ) ;
F_82 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
V_2 -> V_166 ( V_2 ) ;
if ( ! F_85 ( V_177 , & V_2 -> V_149 ) ) {
F_67 ( V_2 ) ;
F_80 ( V_2 , 0 ) ;
F_70 ( V_2 ) ;
}
V_2 -> V_8 = 0 ;
memset ( V_2 -> V_178 , 0 , sizeof( V_2 -> V_178 ) ) ;
memset ( V_2 -> V_125 , 0 , sizeof( V_2 -> V_125 ) ) ;
F_22 ( V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
int F_90 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_41 ( V_66 ) ;
if ( ! V_2 )
return - V_142 ;
if ( F_85 ( V_177 , & V_2 -> V_149 ) )
F_87 ( & V_2 -> V_179 ) ;
V_27 = F_83 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_27 ;
}
int F_91 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_41 ( V_66 ) ;
if ( ! V_2 )
return - V_142 ;
F_21 ( V_2 ) ;
if ( ! F_5 ( V_37 , & V_2 -> V_8 ) )
goto V_145;
F_34 ( & V_2 -> V_164 ) ;
F_34 ( & V_2 -> V_19 ) ;
F_67 ( V_2 ) ;
F_49 ( V_2 ) ;
F_89 ( V_2 ) ;
F_70 ( V_2 ) ;
if ( V_2 -> V_165 )
V_2 -> V_165 ( V_2 ) ;
F_77 ( & V_2 -> V_158 , 1 ) ;
V_2 -> V_180 = 0 ; V_2 -> V_181 = 0 ; V_2 -> V_182 = 0 ;
if ( ! F_5 ( V_154 , & V_2 -> V_8 ) )
V_36 = F_11 ( V_2 , F_23 , 0 ,
F_71 ( V_159 ) ) ;
V_145:
F_22 ( V_2 ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
int F_92 ( T_1 V_66 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
V_2 = F_41 ( V_66 ) ;
if ( ! V_2 )
return - V_142 ;
memset ( & V_2 -> V_183 , 0 , sizeof( struct V_184 ) ) ;
F_74 ( V_2 ) ;
return V_36 ;
}
int F_93 ( unsigned int V_4 , void T_6 * V_135 )
{
struct V_1 * V_2 ;
struct V_185 V_186 ;
int V_27 = 0 ;
if ( F_66 ( & V_186 , V_135 , sizeof( V_186 ) ) )
return - V_140 ;
V_2 = F_41 ( V_186 . V_141 ) ;
if ( ! V_2 )
return - V_142 ;
switch ( V_4 ) {
case V_187 :
V_27 = F_20 ( V_2 , F_38 , V_186 . V_188 ,
F_71 ( V_159 ) ) ;
break;
case V_189 :
if ( ! F_94 ( V_2 ) ) {
V_27 = - V_190 ;
break;
}
if ( ! F_5 ( V_191 , & V_2 -> V_8 ) ) {
V_27 = F_20 ( V_2 , F_38 , V_186 . V_188 ,
F_71 ( V_159 ) ) ;
if ( V_27 )
break;
}
V_27 = F_20 ( V_2 , F_39 , V_186 . V_188 ,
F_71 ( V_159 ) ) ;
break;
case V_192 :
V_27 = F_20 ( V_2 , F_37 , V_186 . V_188 ,
F_71 ( V_159 ) ) ;
break;
case V_193 :
V_27 = F_20 ( V_2 , F_40 , V_186 . V_188 ,
F_71 ( V_159 ) ) ;
break;
case V_194 :
V_2 -> V_195 = ( ( T_1 ) V_186 . V_188 ) &
( V_196 | V_197 ) ;
break;
case V_198 :
V_2 -> V_64 = ( T_1 ) V_186 . V_188 ;
break;
case V_199 :
V_2 -> V_200 = * ( ( T_1 * ) & V_186 . V_188 + 1 ) ;
V_2 -> V_201 = * ( ( T_1 * ) & V_186 . V_188 + 0 ) ;
break;
case V_202 :
V_2 -> V_203 = * ( ( T_1 * ) & V_186 . V_188 + 1 ) ;
V_2 -> V_204 = * ( ( T_1 * ) & V_186 . V_188 + 0 ) ;
break;
default:
V_27 = - V_205 ;
break;
}
F_74 ( V_2 ) ;
return V_27 ;
}
int F_95 ( void T_6 * V_135 )
{
struct V_1 * V_2 ;
struct V_206 * V_207 ;
struct V_185 * V_186 ;
int V_95 = 0 , V_208 , V_27 ;
T_1 V_209 ;
if ( F_96 ( V_209 , ( T_1 T_6 * ) V_135 ) )
return - V_140 ;
if ( ! V_209 || V_209 > ( V_210 * 2 ) / sizeof( * V_186 ) )
return - V_205 ;
V_208 = sizeof( * V_207 ) + V_209 * sizeof( * V_186 ) ;
V_207 = F_62 ( V_208 , V_146 ) ;
if ( ! V_207 )
return - V_147 ;
V_186 = V_207 -> V_211 ;
F_42 ( & V_81 ) ;
F_43 (hdev, &hci_dev_list, list) {
if ( F_85 ( V_177 , & V_2 -> V_149 ) )
F_87 ( & V_2 -> V_179 ) ;
if ( ! F_5 ( V_212 , & V_2 -> V_149 ) )
F_24 ( V_213 , & V_2 -> V_149 ) ;
( V_186 + V_95 ) -> V_141 = V_2 -> V_82 ;
( V_186 + V_95 ) -> V_188 = V_2 -> V_8 ;
if ( ++ V_95 >= V_209 )
break;
}
F_45 ( & V_81 ) ;
V_207 -> V_209 = V_95 ;
V_208 = sizeof( * V_207 ) + V_95 * sizeof( * V_186 ) ;
V_27 = F_73 ( V_135 , V_207 , V_208 ) ;
F_52 ( V_207 ) ;
return V_27 ? - V_140 : 0 ;
}
int F_97 ( void T_6 * V_135 )
{
struct V_1 * V_2 ;
struct V_214 V_215 ;
int V_27 = 0 ;
if ( F_66 ( & V_215 , V_135 , sizeof( V_215 ) ) )
return - V_140 ;
V_2 = F_41 ( V_215 . V_141 ) ;
if ( ! V_2 )
return - V_142 ;
if ( F_85 ( V_177 , & V_2 -> V_149 ) )
F_88 ( & V_2 -> V_179 ) ;
if ( ! F_5 ( V_212 , & V_2 -> V_149 ) )
F_24 ( V_213 , & V_2 -> V_149 ) ;
strcpy ( V_215 . V_6 , V_2 -> V_6 ) ;
V_215 . V_58 = V_2 -> V_58 ;
V_215 . type = ( V_2 -> V_216 & 0x0f ) | ( V_2 -> V_67 << 4 ) ;
V_215 . V_8 = V_2 -> V_8 ;
V_215 . V_64 = V_2 -> V_64 ;
V_215 . V_200 = V_2 -> V_200 ;
V_215 . V_201 = V_2 -> V_201 ;
V_215 . V_203 = V_2 -> V_203 ;
V_215 . V_204 = V_2 -> V_204 ;
V_215 . V_217 = V_2 -> V_217 ;
V_215 . V_195 = V_2 -> V_195 ;
memcpy ( & V_215 . V_183 , & V_2 -> V_183 , sizeof( V_215 . V_183 ) ) ;
memcpy ( & V_215 . V_218 , & V_2 -> V_218 , sizeof( V_215 . V_218 ) ) ;
if ( F_73 ( V_135 , & V_215 , sizeof( V_215 ) ) )
V_27 = - V_140 ;
F_74 ( V_2 ) ;
return V_27 ;
}
static int F_98 ( void * V_13 , bool V_219 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( L_16 , V_2 , V_2 -> V_6 , V_219 ) ;
if ( ! V_219 )
return 0 ;
F_83 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_99 ( void )
{
struct V_1 * V_2 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_2 )
return NULL ;
F_100 ( V_2 ) ;
F_101 ( & V_2 -> V_63 ) ;
return V_2 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_63 ) ;
F_103 ( & V_2 -> V_66 ) ;
}
static void F_104 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 , V_222 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_75 ( V_2 -> V_82 ) < 0 )
return;
if ( F_5 ( V_177 , & V_2 -> V_149 ) )
F_106 ( & V_2 -> V_179 ,
F_71 ( V_223 ) ) ;
if ( F_85 ( V_161 , & V_2 -> V_149 ) )
F_107 ( V_2 ) ;
}
static void F_108 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 ,
V_179 . V_221 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_83 ( V_2 ) ;
}
static void F_109 ( struct V_220 * V_221 )
{
struct V_1 * V_2 ;
T_7 V_71 = V_224 ;
V_2 = F_105 ( V_221 , struct V_1 , V_170 . V_221 ) ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_67 ( V_2 ) ;
F_25 ( V_2 , V_72 , sizeof( V_71 ) , & V_71 ) ;
V_2 -> V_169 = 0 ;
F_70 ( V_2 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_102 * V_94 , * V_95 ;
F_111 (p, n, &hdev->uuids) {
struct V_225 * V_226 ;
V_226 = F_112 ( V_94 , struct V_225 , V_104 ) ;
F_51 ( V_94 ) ;
F_52 ( V_226 ) ;
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_102 * V_94 , * V_95 ;
F_111 (p, n, &hdev->link_keys) {
struct V_227 * V_228 ;
V_228 = F_112 ( V_94 , struct V_227 , V_104 ) ;
F_51 ( V_94 ) ;
F_52 ( V_228 ) ;
}
return 0 ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_229 * V_230 , * V_231 ;
F_50 (k, tmp, &hdev->long_term_keys, list) {
F_51 ( & V_230 -> V_104 ) ;
F_52 ( V_230 ) ;
}
return 0 ;
}
struct V_227 * F_115 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_227 * V_230 ;
F_43 (k, &hdev->link_keys, list)
if ( F_56 ( V_58 , & V_230 -> V_58 ) == 0 )
return V_230 ;
return NULL ;
}
static bool F_116 ( struct V_1 * V_2 , struct V_232 * V_233 ,
T_7 V_234 , T_7 V_235 )
{
if ( V_234 < 0x03 )
return true ;
if ( V_234 == V_236 )
return false ;
if ( V_234 == V_237 && V_235 == 0xff )
return false ;
if ( ! V_233 )
return true ;
if ( V_233 -> V_238 > 0x01 && V_233 -> V_239 > 0x01 )
return true ;
if ( V_233 -> V_238 == 0x02 || V_233 -> V_238 == 0x03 )
return true ;
if ( V_233 -> V_239 == 0x02 || V_233 -> V_239 == 0x03 )
return true ;
return false ;
}
struct V_229 * F_117 ( struct V_1 * V_2 , T_3 V_240 , T_7 rand [ 8 ] )
{
struct V_229 * V_230 ;
F_43 (k, &hdev->long_term_keys, list) {
if ( V_230 -> V_240 != V_240 ||
memcmp ( rand , V_230 -> rand , sizeof( V_230 -> rand ) ) )
continue;
return V_230 ;
}
return NULL ;
}
struct V_229 * F_118 ( struct V_1 * V_2 , T_5 * V_58 ,
T_7 V_241 )
{
struct V_229 * V_230 ;
F_43 (k, &hdev->long_term_keys, list)
if ( V_241 == V_230 -> V_242 &&
F_56 ( V_58 , & V_230 -> V_58 ) == 0 )
return V_230 ;
return NULL ;
}
int F_119 ( struct V_1 * V_2 , struct V_232 * V_233 , int V_243 ,
T_5 * V_58 , T_7 * V_244 , T_7 type , T_7 V_245 )
{
struct V_227 * V_228 , * V_246 ;
T_7 V_235 ;
bool V_247 ;
V_246 = F_115 ( V_2 , V_58 ) ;
if ( V_246 ) {
V_235 = V_246 -> type ;
V_228 = V_246 ;
} else {
V_235 = V_233 ? V_233 -> V_234 : 0xff ;
V_228 = F_62 ( sizeof( * V_228 ) , V_18 ) ;
if ( ! V_228 )
return - V_147 ;
F_60 ( & V_228 -> V_104 , & V_2 -> V_248 ) ;
}
F_4 ( L_17 , V_2 -> V_6 , F_55 ( V_58 ) , type ) ;
if ( type == V_237 &&
( ! V_233 || V_233 -> V_239 == 0xff ) &&
V_235 == 0xff ) {
type = V_249 ;
if ( V_233 )
V_233 -> V_234 = type ;
}
F_28 ( & V_228 -> V_58 , V_58 ) ;
memcpy ( V_228 -> V_244 , V_244 , 16 ) ;
V_228 -> V_245 = V_245 ;
if ( type == V_237 )
V_228 -> type = V_235 ;
else
V_228 -> type = type ;
if ( ! V_243 )
return 0 ;
V_247 = F_116 ( V_2 , V_233 , type , V_235 ) ;
F_120 ( V_2 , V_228 , V_247 ) ;
if ( V_233 )
V_233 -> V_250 = ! V_247 ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_5 * V_58 , T_7 V_241 , T_7 type ,
int V_243 , T_7 V_251 , T_7 V_252 [ 16 ] , T_7 V_253 , T_8
V_240 , T_7 rand [ 8 ] )
{
struct V_229 * V_228 , * V_246 ;
if ( ! ( type & V_254 ) && ! ( type & V_255 ) )
return 0 ;
V_246 = F_118 ( V_2 , V_58 , V_241 ) ;
if ( V_246 )
V_228 = V_246 ;
else {
V_228 = F_62 ( sizeof( * V_228 ) , V_18 ) ;
if ( ! V_228 )
return - V_147 ;
F_60 ( & V_228 -> V_104 , & V_2 -> V_256 ) ;
}
F_28 ( & V_228 -> V_58 , V_58 ) ;
V_228 -> V_242 = V_241 ;
memcpy ( V_228 -> V_244 , V_252 , sizeof( V_228 -> V_244 ) ) ;
V_228 -> V_251 = V_251 ;
V_228 -> V_240 = V_240 ;
V_228 -> V_253 = V_253 ;
V_228 -> type = type ;
memcpy ( V_228 -> rand , rand , sizeof( V_228 -> rand ) ) ;
if ( ! V_243 )
return 0 ;
if ( type & V_255 )
F_122 ( V_2 , V_228 , 1 ) ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_227 * V_228 ;
V_228 = F_115 ( V_2 , V_58 ) ;
if ( ! V_228 )
return - V_257 ;
F_4 ( L_18 , V_2 -> V_6 , F_55 ( V_58 ) ) ;
F_51 ( & V_228 -> V_104 ) ;
F_52 ( V_228 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_229 * V_230 , * V_231 ;
F_50 (k, tmp, &hdev->long_term_keys, list) {
if ( F_56 ( V_58 , & V_230 -> V_58 ) )
continue;
F_4 ( L_18 , V_2 -> V_6 , F_55 ( V_58 ) ) ;
F_51 ( & V_230 -> V_104 ) ;
F_52 ( V_230 ) ;
}
return 0 ;
}
static void F_125 ( unsigned long V_135 )
{
struct V_1 * V_2 = ( void * ) V_135 ;
F_35 ( L_19 , V_2 -> V_6 ) ;
F_77 ( & V_2 -> V_158 , 1 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
struct V_258 * F_126 ( struct V_1 * V_2 ,
T_5 * V_58 )
{
struct V_258 * V_13 ;
F_43 (data, &hdev->remote_oob_data, list)
if ( F_56 ( V_58 , & V_13 -> V_58 ) == 0 )
return V_13 ;
return NULL ;
}
int F_127 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_258 * V_13 ;
V_13 = F_126 ( V_2 , V_58 ) ;
if ( ! V_13 )
return - V_257 ;
F_4 ( L_18 , V_2 -> V_6 , F_55 ( V_58 ) ) ;
F_51 ( & V_13 -> V_104 ) ;
F_52 ( V_13 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_258 * V_13 , * V_95 ;
F_50 (data, n, &hdev->remote_oob_data, list) {
F_51 ( & V_13 -> V_104 ) ;
F_52 ( V_13 ) ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , T_5 * V_58 , T_7 * V_259 ,
T_7 * V_260 )
{
struct V_258 * V_13 ;
V_13 = F_126 ( V_2 , V_58 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
return - V_147 ;
F_28 ( & V_13 -> V_58 , V_58 ) ;
F_60 ( & V_13 -> V_104 , & V_2 -> V_261 ) ;
}
memcpy ( V_13 -> V_259 , V_259 , sizeof( V_13 -> V_259 ) ) ;
memcpy ( V_13 -> V_260 , V_260 , sizeof( V_13 -> V_260 ) ) ;
F_4 ( L_20 , V_2 -> V_6 , F_55 ( V_58 ) ) ;
return 0 ;
}
struct V_262 * F_130 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_262 * V_263 ;
F_43 (b, &hdev->blacklist, list)
if ( F_56 ( V_58 , & V_263 -> V_58 ) == 0 )
return V_263 ;
return NULL ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_102 * V_94 , * V_95 ;
F_111 (p, n, &hdev->blacklist) {
struct V_262 * V_263 ;
V_263 = F_112 ( V_94 , struct V_262 , V_104 ) ;
F_51 ( V_94 ) ;
F_52 ( V_263 ) ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_5 * V_58 , T_7 type )
{
struct V_262 * V_264 ;
if ( F_56 ( V_58 , V_59 ) == 0 )
return - V_265 ;
if ( F_130 ( V_2 , V_58 ) )
return - V_266 ;
V_264 = F_62 ( sizeof( struct V_262 ) , V_146 ) ;
if ( ! V_264 )
return - V_147 ;
F_28 ( & V_264 -> V_58 , V_58 ) ;
F_60 ( & V_264 -> V_104 , & V_2 -> V_267 ) ;
return F_133 ( V_2 , V_58 , type ) ;
}
int F_134 ( struct V_1 * V_2 , T_5 * V_58 , T_7 type )
{
struct V_262 * V_264 ;
if ( F_56 ( V_58 , V_59 ) == 0 )
return F_131 ( V_2 ) ;
V_264 = F_130 ( V_2 , V_58 ) ;
if ( ! V_264 )
return - V_257 ;
F_51 ( & V_264 -> V_104 ) ;
F_52 ( V_264 ) ;
return F_135 ( V_2 , V_58 , type ) ;
}
static void F_136 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 ,
V_268 . V_221 ) ;
F_67 ( V_2 ) ;
F_137 ( V_2 ) ;
F_70 ( V_2 ) ;
}
int F_137 ( struct V_1 * V_2 )
{
struct V_269 * V_264 , * V_231 ;
F_50 (entry, tmp, &hdev->adv_entries, list) {
F_51 ( & V_264 -> V_104 ) ;
F_52 ( V_264 ) ;
}
F_4 ( L_21 , V_2 -> V_6 ) ;
return 0 ;
}
struct V_269 * F_138 ( struct V_1 * V_2 , T_5 * V_58 )
{
struct V_269 * V_264 ;
F_43 (entry, &hdev->adv_entries, list)
if ( F_56 ( V_58 , & V_264 -> V_58 ) == 0 )
return V_264 ;
return NULL ;
}
static inline int F_139 ( T_7 V_270 )
{
if ( V_270 == V_271 || V_270 == V_272 )
return 1 ;
return 0 ;
}
int F_140 ( struct V_1 * V_2 ,
struct V_273 * V_274 ) { struct V_269 * V_264 ; if ( ! F_139 ( V_274 -> V_270 ) )
return - V_205 ;
if ( F_138 ( V_2 , & V_274 -> V_58 ) )
return 0 ;
V_264 = F_62 ( sizeof( * V_264 ) , V_146 ) ;
if ( ! V_264 )
return - V_147 ;
F_28 ( & V_264 -> V_58 , & V_274 -> V_58 ) ;
V_264 -> V_242 = V_274 -> V_242 ;
F_60 ( & V_264 -> V_104 , & V_2 -> V_275 ) ;
F_4 ( L_22 , V_2 -> V_6 ,
F_55 ( & V_264 -> V_58 ) , V_264 -> V_242 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_276 * V_42 = (struct V_276 * ) V_29 ;
struct V_277 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . type = V_42 -> type ;
V_41 . V_278 = F_27 ( V_42 -> V_278 ) ;
V_41 . V_279 = F_27 ( V_42 -> V_279 ) ;
F_25 ( V_2 , V_280 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_142 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_281 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_282 = 1 ;
F_25 ( V_2 , V_283 , sizeof( V_41 ) , & V_41 ) ;
}
static int F_143 ( struct V_1 * V_2 , T_7 type , T_8 V_278 ,
T_8 V_279 , int V_30 )
{
long V_139 = F_71 ( 3000 ) ;
struct V_276 V_42 ;
int V_27 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_284 , & V_2 -> V_149 ) )
return - V_285 ;
V_42 . type = type ;
V_42 . V_278 = V_278 ;
V_42 . V_279 = V_279 ;
F_21 ( V_2 ) ;
V_27 = F_11 ( V_2 , F_141 , ( unsigned long ) & V_42 ,
V_139 ) ;
if ( ! V_27 )
V_27 = F_11 ( V_2 , F_142 , 0 , V_139 ) ;
F_22 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
F_106 ( & V_2 -> V_174 ,
F_71 ( V_30 ) ) ;
return 0 ;
}
static void F_144 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 ,
V_174 . V_221 ) ;
struct V_281 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
F_25 ( V_2 , V_283 , sizeof( V_41 ) , & V_41 ) ;
}
static void F_145 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 , V_167 ) ;
struct V_276 * V_42 = & V_2 -> V_276 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_143 ( V_2 , V_42 -> type , V_42 -> V_278 , V_42 -> V_279 ,
V_42 -> V_30 ) ;
}
int F_146 ( struct V_1 * V_2 , T_7 type , T_8 V_278 , T_8 V_279 ,
int V_30 )
{
struct V_276 * V_42 = & V_2 -> V_276 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_147 ( & V_2 -> V_167 ) )
return - V_285 ;
V_42 -> type = type ;
V_42 -> V_278 = V_278 ;
V_42 -> V_279 = V_279 ;
V_42 -> V_30 = V_30 ;
F_8 ( V_286 , & V_2 -> V_167 ) ;
return 0 ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_102 * V_287 = & V_288 , * V_94 ;
int V_289 , V_82 , error ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_216 ) ;
if ( ! V_2 -> V_156 || ! V_2 -> V_166 )
return - V_205 ;
V_82 = ( V_2 -> V_67 == V_68 ) ? 0 : 1 ;
F_149 ( & V_81 ) ;
F_150 (p, &hci_dev_list) {
if ( F_112 ( V_94 , struct V_1 , V_104 ) -> V_82 != V_82 )
break;
V_287 = V_94 ; V_82 ++ ;
}
sprintf ( V_2 -> V_6 , L_24 , V_82 ) ;
V_2 -> V_82 = V_82 ;
F_151 ( & V_2 -> V_104 , V_287 ) ;
F_152 ( & V_2 -> V_290 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_149 = 0 ;
V_2 -> V_64 = ( V_291 | V_292 | V_293 ) ;
V_2 -> V_294 = ( V_295 ) ;
V_2 -> V_195 = ( V_197 ) ;
V_2 -> V_296 = 0x03 ;
V_2 -> V_297 = 0 ;
V_2 -> V_298 = 800 ;
V_2 -> V_299 = 80 ;
F_153 ( & V_2 -> V_163 , V_300 ) ;
F_153 ( & V_2 -> V_21 , V_301 ) ;
F_153 ( & V_2 -> V_162 , V_302 ) ;
F_101 ( & V_2 -> V_164 ) ;
F_101 ( & V_2 -> V_19 ) ;
F_101 ( & V_2 -> V_176 ) ;
F_154 ( & V_2 -> V_168 , F_125 , ( unsigned long ) V_2 ) ;
for ( V_289 = 0 ; V_289 < V_303 ; V_289 ++ )
V_2 -> V_304 [ V_289 ] = NULL ;
F_155 ( & V_2 -> V_26 ) ;
F_152 ( & V_2 -> V_305 ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
F_53 ( & V_2 -> V_306 ) ;
F_53 ( & V_2 -> V_267 ) ;
F_53 ( & V_2 -> V_307 ) ;
F_53 ( & V_2 -> V_248 ) ;
F_53 ( & V_2 -> V_256 ) ;
F_53 ( & V_2 -> V_261 ) ;
F_53 ( & V_2 -> V_275 ) ;
F_158 ( & V_2 -> V_268 , F_136 ) ;
F_153 ( & V_2 -> V_222 , F_104 ) ;
F_158 ( & V_2 -> V_179 , F_108 ) ;
F_158 ( & V_2 -> V_170 , F_109 ) ;
memset ( & V_2 -> V_183 , 0 , sizeof( struct V_184 ) ) ;
F_77 ( & V_2 -> V_308 , 0 ) ;
F_153 ( & V_2 -> V_167 , F_145 ) ;
F_158 ( & V_2 -> V_174 , F_144 ) ;
F_159 ( & V_81 ) ;
V_2 -> V_20 = F_160 ( V_2 -> V_6 , V_309 | V_310 |
V_311 , 1 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_147 ;
goto V_27;
}
error = F_161 ( V_2 ) ;
if ( error < 0 )
goto V_312;
V_2 -> V_150 = F_162 ( V_2 -> V_6 , & V_2 -> V_66 ,
V_313 , & V_314 , V_2 ) ;
if ( V_2 -> V_150 ) {
if ( F_163 ( V_2 -> V_150 ) < 0 ) {
F_164 ( V_2 -> V_150 ) ;
V_2 -> V_150 = NULL ;
}
}
F_24 ( V_177 , & V_2 -> V_149 ) ;
F_24 ( V_161 , & V_2 -> V_149 ) ;
F_165 ( & V_2 -> V_222 ) ;
F_1 ( V_2 , V_315 ) ;
F_44 ( V_2 ) ;
return V_82 ;
V_312:
F_166 ( V_2 -> V_20 ) ;
V_27:
F_149 ( & V_81 ) ;
F_51 ( & V_2 -> V_104 ) ;
F_159 ( & V_81 ) ;
return error ;
}
void F_167 ( struct V_1 * V_2 )
{
int V_289 ;
F_4 ( L_23 , V_2 , V_2 -> V_6 , V_2 -> V_216 ) ;
F_24 ( V_148 , & V_2 -> V_149 ) ;
F_149 ( & V_81 ) ;
F_51 ( & V_2 -> V_104 ) ;
F_159 ( & V_81 ) ;
F_83 ( V_2 ) ;
for ( V_289 = 0 ; V_289 < V_303 ; V_289 ++ )
F_82 ( V_2 -> V_304 [ V_289 ] ) ;
if ( ! F_5 ( V_7 , & V_2 -> V_8 ) &&
! F_5 ( V_161 , & V_2 -> V_149 ) ) {
F_67 ( V_2 ) ;
F_168 ( V_2 ) ;
F_70 ( V_2 ) ;
}
F_169 ( ! F_170 ( & V_2 -> V_306 ) ) ;
F_1 ( V_2 , V_316 ) ;
if ( V_2 -> V_150 ) {
F_171 ( V_2 -> V_150 ) ;
F_164 ( V_2 -> V_150 ) ;
}
F_172 ( V_2 ) ;
F_88 ( & V_2 -> V_268 ) ;
F_166 ( V_2 -> V_20 ) ;
F_67 ( V_2 ) ;
F_131 ( V_2 ) ;
F_110 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
F_128 ( V_2 ) ;
F_137 ( V_2 ) ;
F_70 ( V_2 ) ;
F_74 ( V_2 ) ;
}
int F_173 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_317 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_318 ) ;
return 0 ;
}
int F_175 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_66 ;
if ( ! V_2 || ( ! F_5 ( V_37 , & V_2 -> V_8 )
&& ! F_5 ( V_7 , & V_2 -> V_8 ) ) ) {
F_82 ( V_15 ) ;
return - V_319 ;
}
F_32 ( V_15 ) -> V_320 = 1 ;
F_176 ( V_15 ) ;
F_33 ( & V_2 -> V_164 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_163 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , int type , void * V_13 ,
int V_321 , T_4 V_79 )
{
int V_322 = 0 ;
int V_323 = 0 ;
int V_324 = V_321 ;
struct V_14 * V_15 ;
struct V_325 * V_326 ;
if ( ( type < V_327 || type > V_328 ) ||
V_79 >= V_303 )
return - V_329 ;
V_15 = V_2 -> V_304 [ V_79 ] ;
if ( ! V_15 ) {
switch ( type ) {
case V_327 :
V_322 = V_330 ;
V_323 = V_331 ;
break;
case V_328 :
V_322 = V_332 ;
V_323 = V_333 ;
break;
case V_334 :
V_322 = V_335 ;
V_323 = V_336 ;
break;
}
V_15 = F_178 ( V_322 , V_18 ) ;
if ( ! V_15 )
return - V_147 ;
V_326 = ( void * ) V_15 -> V_337 ;
V_326 -> V_338 = V_323 ;
V_326 -> V_64 = type ;
V_15 -> V_66 = ( void * ) V_2 ;
V_2 -> V_304 [ V_79 ] = V_15 ;
}
while ( V_321 ) {
V_326 = ( void * ) V_15 -> V_337 ;
V_322 = F_179 ( V_339 , V_326 -> V_338 , V_321 ) ;
memcpy ( F_180 ( V_15 , V_322 ) , V_13 , V_322 ) ;
V_321 -= V_322 ;
V_13 += V_322 ;
V_326 -> V_338 -= V_322 ;
V_324 = V_321 ;
switch ( type ) {
case V_328 :
if ( V_15 -> V_322 == V_333 ) {
struct V_340 * V_341 = V_340 ( V_15 ) ;
V_326 -> V_338 = V_341 -> V_342 ;
if ( F_181 ( V_15 ) < V_326 -> V_338 ) {
F_82 ( V_15 ) ;
V_2 -> V_304 [ V_79 ] = NULL ;
return - V_147 ;
}
}
break;
case V_327 :
if ( V_15 -> V_322 == V_331 ) {
struct V_343 * V_341 = V_343 ( V_15 ) ;
V_326 -> V_338 = F_182 ( V_341 -> V_344 ) ;
if ( F_181 ( V_15 ) < V_326 -> V_338 ) {
F_82 ( V_15 ) ;
V_2 -> V_304 [ V_79 ] = NULL ;
return - V_147 ;
}
}
break;
case V_334 :
if ( V_15 -> V_322 == V_336 ) {
struct V_345 * V_341 = V_345 ( V_15 ) ;
V_326 -> V_338 = V_341 -> V_344 ;
if ( F_181 ( V_15 ) < V_326 -> V_338 ) {
F_82 ( V_15 ) ;
V_2 -> V_304 [ V_79 ] = NULL ;
return - V_147 ;
}
}
break;
}
if ( V_326 -> V_338 == 0 ) {
F_32 ( V_15 ) -> V_64 = type ;
F_175 ( V_15 ) ;
V_2 -> V_304 [ V_79 ] = NULL ;
return V_324 ;
}
}
return V_324 ;
}
int F_183 ( struct V_1 * V_2 , int type , void * V_13 , int V_321 )
{
int V_346 = 0 ;
if ( type < V_327 || type > V_328 )
return - V_329 ;
while ( V_321 ) {
V_346 = F_177 ( V_2 , type , V_13 , V_321 , type - 1 ) ;
if ( V_346 < 0 )
return V_346 ;
V_13 += ( V_321 - V_346 ) ;
V_321 = V_346 ;
}
return V_346 ;
}
int F_184 ( struct V_1 * V_2 , void * V_13 , int V_321 )
{
int type ;
int V_346 = 0 ;
while ( V_321 ) {
struct V_14 * V_15 = V_2 -> V_304 [ V_347 ] ;
if ( ! V_15 ) {
struct { char type ; } * V_348 ;
V_348 = V_13 ;
type = V_348 -> type ;
V_13 ++ ;
V_321 -- ;
} else
type = F_32 ( V_15 ) -> V_64 ;
V_346 = F_177 ( V_2 , type , V_13 , V_321 ,
V_347 ) ;
if ( V_346 < 0 )
return V_346 ;
V_13 += ( V_321 - V_346 ) ;
V_321 = V_346 ;
}
return V_346 ;
}
int F_185 ( struct V_349 * V_337 )
{
F_4 ( L_25 , V_337 , V_337 -> V_6 ) ;
F_149 ( & V_350 ) ;
F_60 ( & V_337 -> V_104 , & V_351 ) ;
F_159 ( & V_350 ) ;
return 0 ;
}
int F_186 ( struct V_349 * V_337 )
{
F_4 ( L_25 , V_337 , V_337 -> V_6 ) ;
F_149 ( & V_350 ) ;
F_51 ( & V_337 -> V_104 ) ;
F_159 ( & V_350 ) ;
return 0 ;
}
static int F_187 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_66 ;
if ( ! V_2 ) {
F_82 ( V_15 ) ;
return - V_142 ;
}
F_4 ( L_26 , V_2 -> V_6 , F_32 ( V_15 ) -> V_64 , V_15 -> V_322 ) ;
F_176 ( V_15 ) ;
F_188 ( V_2 , V_15 ) ;
if ( F_189 ( & V_2 -> V_308 ) ) {
F_190 ( V_2 , V_15 ) ;
}
F_191 ( V_15 ) ;
return V_2 -> V_352 ( V_15 ) ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_342 , void * V_42 )
{
int V_322 = V_353 + V_342 ;
struct V_10 * V_354 ;
struct V_14 * V_15 ;
F_4 ( L_27 , V_2 -> V_6 , V_17 , V_342 ) ;
V_15 = F_178 ( V_322 , V_18 ) ;
if ( ! V_15 ) {
F_35 ( L_28 , V_2 -> V_6 ) ;
return - V_147 ;
}
V_354 = (struct V_10 * ) F_180 ( V_15 , V_353 ) ;
V_354 -> V_17 = F_27 ( V_17 ) ;
V_354 -> V_342 = V_342 ;
if ( V_342 )
memcpy ( F_180 ( V_15 , V_342 ) , V_42 , V_342 ) ;
F_4 ( L_29 , V_15 -> V_322 ) ;
F_32 ( V_15 ) -> V_64 = V_65 ;
V_15 -> V_66 = ( void * ) V_2 ;
if ( F_5 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 = V_17 ;
F_33 ( & V_2 -> V_19 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
void * F_192 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_10 * V_354 ;
if ( ! V_2 -> V_12 )
return NULL ;
V_354 = ( void * ) V_2 -> V_12 -> V_13 ;
if ( V_354 -> V_17 != F_27 ( V_17 ) )
return NULL ;
F_4 ( L_30 , V_2 -> V_6 , V_17 ) ;
return V_2 -> V_12 -> V_13 + V_353 ;
}
static void F_193 ( struct V_14 * V_15 , T_1 V_355 , T_1 V_8 )
{
struct V_343 * V_354 ;
int V_322 = V_15 -> V_322 ;
F_194 ( V_15 , V_331 ) ;
F_195 ( V_15 ) ;
V_354 = (struct V_343 * ) F_196 ( V_15 ) ;
V_354 -> V_355 = F_27 ( F_197 ( V_355 , V_8 ) ) ;
V_354 -> V_344 = F_27 ( V_322 ) ;
}
static void F_198 ( struct V_232 * V_233 , struct V_356 * V_357 ,
struct V_14 * V_15 , T_1 V_8 )
{
struct V_1 * V_2 = V_233 -> V_2 ;
struct V_14 * V_104 ;
V_104 = F_199 ( V_15 ) -> V_358 ;
if ( ! V_104 ) {
F_4 ( L_31 , V_2 -> V_6 , V_15 , V_15 -> V_322 ) ;
F_33 ( V_357 , V_15 ) ;
} else {
F_4 ( L_32 , V_2 -> V_6 , V_15 , V_15 -> V_322 ) ;
F_199 ( V_15 ) -> V_358 = NULL ;
F_200 ( & V_357 -> V_290 ) ;
F_201 ( V_357 , V_15 ) ;
V_8 &= ~ V_359 ;
V_8 |= V_360 ;
do {
V_15 = V_104 ; V_104 = V_104 -> V_361 ;
V_15 -> V_66 = ( void * ) V_2 ;
F_32 ( V_15 ) -> V_64 = V_327 ;
F_193 ( V_15 , V_233 -> V_355 , V_8 ) ;
F_4 ( L_32 , V_2 -> V_6 , V_15 , V_15 -> V_322 ) ;
F_201 ( V_357 , V_15 ) ;
} while ( V_104 );
F_202 ( & V_357 -> V_290 ) ;
}
}
void F_203 ( struct V_362 * V_363 , struct V_14 * V_15 , T_1 V_8 )
{
struct V_232 * V_233 = V_363 -> V_233 ;
struct V_1 * V_2 = V_233 -> V_2 ;
F_4 ( L_33 , V_2 -> V_6 , V_363 , V_8 ) ;
V_15 -> V_66 = ( void * ) V_2 ;
F_32 ( V_15 ) -> V_64 = V_327 ;
F_193 ( V_15 , V_233 -> V_355 , V_8 ) ;
F_198 ( V_233 , & V_363 -> V_364 , V_15 , V_8 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_162 ) ;
}
void F_204 ( struct V_232 * V_233 , struct V_14 * V_15 )
{
struct V_1 * V_2 = V_233 -> V_2 ;
struct V_345 V_354 ;
F_4 ( L_34 , V_2 -> V_6 , V_15 -> V_322 ) ;
V_354 . V_355 = F_27 ( V_233 -> V_355 ) ;
V_354 . V_344 = V_15 -> V_322 ;
F_194 ( V_15 , V_336 ) ;
F_195 ( V_15 ) ;
memcpy ( F_196 ( V_15 ) , & V_354 , V_336 ) ;
V_15 -> V_66 = ( void * ) V_2 ;
F_32 ( V_15 ) -> V_64 = V_334 ;
F_33 ( & V_233 -> V_364 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_162 ) ;
}
static inline struct V_232 * F_205 ( struct V_1 * V_2 , T_4 type , int * V_365 )
{
struct V_366 * V_341 = & V_2 -> V_367 ;
struct V_232 * V_233 = NULL , * V_368 ;
int V_117 = 0 , V_369 = ~ 0 ;
F_206 () ;
F_207 (c, &h->list, list) {
if ( V_368 -> type != type || F_208 ( & V_368 -> V_364 ) )
continue;
if ( V_368 -> V_86 != V_370 && V_368 -> V_86 != V_371 )
continue;
V_117 ++ ;
if ( V_368 -> V_11 < V_369 ) {
V_369 = V_368 -> V_11 ;
V_233 = V_368 ;
}
if ( F_209 ( V_2 , type ) == V_117 )
break;
}
F_210 () ;
if ( V_233 ) {
int V_372 , V_373 ;
switch ( V_233 -> type ) {
case V_374 :
V_372 = V_2 -> V_180 ;
break;
case V_375 :
case V_376 :
V_372 = V_2 -> V_181 ;
break;
case V_377 :
V_372 = V_2 -> V_378 ? V_2 -> V_182 : V_2 -> V_180 ;
break;
default:
V_372 = 0 ;
F_35 ( L_35 ) ;
}
V_373 = V_372 / V_117 ;
* V_365 = V_373 ? V_373 : 1 ;
} else
* V_365 = 0 ;
F_4 ( L_36 , V_233 , * V_365 ) ;
return V_233 ;
}
static inline void F_211 ( struct V_1 * V_2 , T_4 type )
{
struct V_366 * V_341 = & V_2 -> V_367 ;
struct V_232 * V_368 ;
F_35 ( L_37 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (c, &h->list, list) {
if ( V_368 -> type == type && V_368 -> V_11 ) {
F_35 ( L_38 ,
V_2 -> V_6 , F_55 ( & V_368 -> V_379 ) ) ;
F_212 ( V_368 , 0x13 ) ;
}
}
F_210 () ;
}
static inline struct V_362 * F_213 ( struct V_1 * V_2 , T_4 type ,
int * V_365 )
{
struct V_366 * V_341 = & V_2 -> V_367 ;
struct V_362 * V_363 = NULL ;
int V_117 = 0 , V_369 = ~ 0 , V_380 = 0 ;
struct V_232 * V_233 ;
int V_372 , V_373 , V_381 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (conn, &h->list, list) {
struct V_362 * V_231 ;
if ( V_233 -> type != type )
continue;
if ( V_233 -> V_86 != V_370 && V_233 -> V_86 != V_371 )
continue;
V_381 ++ ;
F_207 (tmp, &conn->chan_list, list) {
struct V_14 * V_15 ;
if ( F_208 ( & V_231 -> V_364 ) )
continue;
V_15 = F_214 ( & V_231 -> V_364 ) ;
if ( V_15 -> V_382 < V_380 )
continue;
if ( V_15 -> V_382 > V_380 ) {
V_117 = 0 ;
V_369 = ~ 0 ;
V_380 = V_15 -> V_382 ;
}
V_117 ++ ;
if ( V_233 -> V_11 < V_369 ) {
V_369 = V_233 -> V_11 ;
V_363 = V_231 ;
}
}
if ( F_209 ( V_2 , type ) == V_381 )
break;
}
F_210 () ;
if ( ! V_363 )
return NULL ;
switch ( V_363 -> V_233 -> type ) {
case V_374 :
V_372 = V_2 -> V_180 ;
break;
case V_375 :
case V_376 :
V_372 = V_2 -> V_181 ;
break;
case V_377 :
V_372 = V_2 -> V_378 ? V_2 -> V_182 : V_2 -> V_180 ;
break;
default:
V_372 = 0 ;
F_35 ( L_35 ) ;
}
V_373 = V_372 / V_117 ;
* V_365 = V_373 ? V_373 : 1 ;
F_4 ( L_39 , V_363 , * V_365 ) ;
return V_363 ;
}
static void F_215 ( struct V_1 * V_2 , T_4 type )
{
struct V_366 * V_341 = & V_2 -> V_367 ;
struct V_232 * V_233 ;
int V_117 = 0 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
F_206 () ;
F_207 (conn, &h->list, list) {
struct V_362 * V_363 ;
if ( V_233 -> type != type )
continue;
if ( V_233 -> V_86 != V_370 && V_233 -> V_86 != V_371 )
continue;
V_117 ++ ;
F_207 (chan, &conn->chan_list, list) {
struct V_14 * V_15 ;
if ( V_363 -> V_11 ) {
V_363 -> V_11 = 0 ;
continue;
}
if ( F_208 ( & V_363 -> V_364 ) )
continue;
V_15 = F_214 ( & V_363 -> V_364 ) ;
if ( V_15 -> V_382 >= V_383 - 1 )
continue;
V_15 -> V_382 = V_383 - 1 ;
F_4 ( L_40 , V_363 , V_15 ,
V_15 -> V_382 ) ;
}
if ( F_209 ( V_2 , type ) == V_117 )
break;
}
F_210 () ;
}
static inline int F_216 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return F_217 ( V_15 -> V_322 - V_331 , V_2 -> V_384 ) ;
}
static inline void F_218 ( struct V_1 * V_2 , unsigned int V_372 )
{
if ( ! F_5 ( V_154 , & V_2 -> V_8 ) ) {
if ( ! V_372 && F_219 ( V_116 , V_2 -> V_385 +
F_71 ( V_386 ) ) )
F_211 ( V_2 , V_374 ) ;
}
}
static inline void F_220 ( struct V_1 * V_2 )
{
unsigned int V_372 = V_2 -> V_180 ;
struct V_362 * V_363 ;
struct V_14 * V_15 ;
int V_365 ;
F_218 ( V_2 , V_372 ) ;
while ( V_2 -> V_180 &&
( V_363 = F_213 ( V_2 , V_374 , & V_365 ) ) ) {
T_9 V_382 = ( F_214 ( & V_363 -> V_364 ) ) -> V_382 ;
while ( V_365 -- && ( V_15 = F_214 ( & V_363 -> V_364 ) ) ) {
F_4 ( L_41 , V_363 , V_15 ,
V_15 -> V_322 , V_15 -> V_382 ) ;
if ( V_15 -> V_382 < V_382 )
break;
V_15 = F_31 ( & V_363 -> V_364 ) ;
F_221 ( V_363 -> V_233 ,
F_32 ( V_15 ) -> V_387 ) ;
F_187 ( V_15 ) ;
V_2 -> V_385 = V_116 ;
V_2 -> V_180 -- ;
V_363 -> V_11 ++ ;
V_363 -> V_233 -> V_11 ++ ;
}
}
if ( V_372 != V_2 -> V_180 )
F_215 ( V_2 , V_374 ) ;
}
static inline void F_222 ( struct V_1 * V_2 )
{
unsigned int V_372 = V_2 -> V_388 ;
struct V_362 * V_363 ;
struct V_14 * V_15 ;
int V_365 ;
F_218 ( V_2 , V_372 ) ;
while ( V_2 -> V_388 > 0 &&
( V_363 = F_213 ( V_2 , V_374 , & V_365 ) ) ) {
T_9 V_382 = ( F_214 ( & V_363 -> V_364 ) ) -> V_382 ;
while ( V_365 > 0 && ( V_15 = F_214 ( & V_363 -> V_364 ) ) ) {
int V_389 ;
F_4 ( L_41 , V_363 , V_15 ,
V_15 -> V_322 , V_15 -> V_382 ) ;
if ( V_15 -> V_382 < V_382 )
break;
V_15 = F_31 ( & V_363 -> V_364 ) ;
V_389 = F_216 ( V_2 , V_15 ) ;
if ( V_389 > V_2 -> V_388 )
return;
F_221 ( V_363 -> V_233 ,
F_32 ( V_15 ) -> V_387 ) ;
F_187 ( V_15 ) ;
V_2 -> V_385 = V_116 ;
V_2 -> V_388 -= V_389 ;
V_365 -= V_389 ;
V_363 -> V_11 += V_389 ;
V_363 -> V_233 -> V_11 += V_389 ;
}
}
if ( V_372 != V_2 -> V_388 )
F_215 ( V_2 , V_374 ) ;
}
static inline void F_223 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_374 ) )
return;
switch ( V_2 -> V_44 ) {
case V_45 :
F_220 ( V_2 ) ;
break;
case V_62 :
F_222 ( V_2 ) ;
break;
}
}
static inline void F_224 ( struct V_1 * V_2 )
{
struct V_232 * V_233 ;
struct V_14 * V_15 ;
int V_365 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_375 ) )
return;
while ( V_2 -> V_181 && ( V_233 = F_205 ( V_2 , V_375 , & V_365 ) ) ) {
while ( V_365 -- && ( V_15 = F_31 ( & V_233 -> V_364 ) ) ) {
F_4 ( L_42 , V_15 , V_15 -> V_322 ) ;
F_187 ( V_15 ) ;
V_233 -> V_11 ++ ;
if ( V_233 -> V_11 == ~ 0 )
V_233 -> V_11 = 0 ;
}
}
}
static inline void F_225 ( struct V_1 * V_2 )
{
struct V_232 * V_233 ;
struct V_14 * V_15 ;
int V_365 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_376 ) )
return;
while ( V_2 -> V_181 && ( V_233 = F_205 ( V_2 , V_376 , & V_365 ) ) ) {
while ( V_365 -- && ( V_15 = F_31 ( & V_233 -> V_364 ) ) ) {
F_4 ( L_42 , V_15 , V_15 -> V_322 ) ;
F_187 ( V_15 ) ;
V_233 -> V_11 ++ ;
if ( V_233 -> V_11 == ~ 0 )
V_233 -> V_11 = 0 ;
}
}
}
static inline void F_226 ( struct V_1 * V_2 )
{
struct V_362 * V_363 ;
struct V_14 * V_15 ;
int V_365 , V_372 , V_231 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_209 ( V_2 , V_377 ) )
return;
if ( ! F_5 ( V_154 , & V_2 -> V_8 ) ) {
if ( ! V_2 -> V_182 && V_2 -> V_390 &&
F_219 ( V_116 , V_2 -> V_391 + V_392 * 45 ) )
F_211 ( V_2 , V_377 ) ;
}
V_372 = V_2 -> V_390 ? V_2 -> V_182 : V_2 -> V_180 ;
V_231 = V_372 ;
while ( V_372 && ( V_363 = F_213 ( V_2 , V_377 , & V_365 ) ) ) {
T_9 V_382 = ( F_214 ( & V_363 -> V_364 ) ) -> V_382 ;
while ( V_365 -- && ( V_15 = F_214 ( & V_363 -> V_364 ) ) ) {
F_4 ( L_41 , V_363 , V_15 ,
V_15 -> V_322 , V_15 -> V_382 ) ;
if ( V_15 -> V_382 < V_382 )
break;
V_15 = F_31 ( & V_363 -> V_364 ) ;
F_187 ( V_15 ) ;
V_2 -> V_391 = V_116 ;
V_372 -- ;
V_363 -> V_11 ++ ;
V_363 -> V_233 -> V_11 ++ ;
}
}
if ( V_2 -> V_390 )
V_2 -> V_182 = V_372 ;
else
V_2 -> V_180 = V_372 ;
if ( V_372 != V_231 )
F_215 ( V_2 , V_377 ) ;
}
static void V_302 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 , V_162 ) ;
struct V_14 * V_15 ;
F_4 ( L_43 , V_2 -> V_6 , V_2 -> V_180 ,
V_2 -> V_181 , V_2 -> V_182 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
F_226 ( V_2 ) ;
while ( ( V_15 = F_31 ( & V_2 -> V_176 ) ) )
F_187 ( V_15 ) ;
}
static inline void F_227 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_343 * V_354 = ( void * ) V_15 -> V_13 ;
struct V_232 * V_233 ;
T_1 V_355 , V_8 ;
F_228 ( V_15 , V_331 ) ;
V_355 = F_182 ( V_354 -> V_355 ) ;
V_8 = F_229 ( V_355 ) ;
V_355 = F_230 ( V_355 ) ;
F_4 ( L_44 , V_2 -> V_6 , V_15 -> V_322 , V_355 , V_8 ) ;
V_2 -> V_183 . V_393 ++ ;
F_67 ( V_2 ) ;
V_233 = F_231 ( V_2 , V_355 ) ;
F_70 ( V_2 ) ;
if ( V_233 ) {
F_221 ( V_233 , V_394 ) ;
F_67 ( V_2 ) ;
if ( F_5 ( V_212 , & V_2 -> V_149 ) &&
! F_232 ( V_395 , & V_233 -> V_8 ) )
F_233 ( V_2 , & V_233 -> V_379 , V_233 -> type ,
V_233 -> V_396 , 0 , NULL , 0 ,
V_233 -> V_125 ) ;
F_70 ( V_2 ) ;
F_234 ( V_233 , V_15 , V_8 ) ;
return;
} else {
F_35 ( L_45 ,
V_2 -> V_6 , V_355 ) ;
}
F_82 ( V_15 ) ;
}
static inline void F_235 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_345 * V_354 = ( void * ) V_15 -> V_13 ;
struct V_232 * V_233 ;
T_1 V_355 ;
F_228 ( V_15 , V_336 ) ;
V_355 = F_182 ( V_354 -> V_355 ) ;
F_4 ( L_46 , V_2 -> V_6 , V_15 -> V_322 , V_355 ) ;
V_2 -> V_183 . V_397 ++ ;
F_67 ( V_2 ) ;
V_233 = F_231 ( V_2 , V_355 ) ;
F_70 ( V_2 ) ;
if ( V_233 ) {
F_236 ( V_233 , V_15 ) ;
return;
} else {
F_35 ( L_47 ,
V_2 -> V_6 , V_355 ) ;
}
F_82 ( V_15 ) ;
}
static void V_300 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 , V_163 ) ;
struct V_14 * V_15 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
while ( ( V_15 = F_31 ( & V_2 -> V_164 ) ) ) {
F_188 ( V_2 , V_15 ) ;
if ( F_189 ( & V_2 -> V_308 ) ) {
F_190 ( V_2 , V_15 ) ;
}
if ( F_5 ( V_154 , & V_2 -> V_8 ) ) {
F_82 ( V_15 ) ;
continue;
}
if ( F_5 ( V_7 , & V_2 -> V_8 ) ) {
switch ( F_32 ( V_15 ) -> V_64 ) {
case V_327 :
case V_334 :
F_82 ( V_15 ) ;
continue;
}
}
switch ( F_32 ( V_15 ) -> V_64 ) {
case V_328 :
F_4 ( L_48 , V_2 -> V_6 ) ;
F_237 ( V_2 , V_15 ) ;
break;
case V_327 :
F_4 ( L_49 , V_2 -> V_6 ) ;
F_227 ( V_2 , V_15 ) ;
break;
case V_334 :
F_4 ( L_50 , V_2 -> V_6 ) ;
F_235 ( V_2 , V_15 ) ;
break;
default:
F_82 ( V_15 ) ;
break;
}
}
}
static void V_301 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_105 ( V_221 , struct V_1 , V_21 ) ;
struct V_14 * V_15 ;
F_4 ( L_51 , V_2 -> V_6 , F_189 ( & V_2 -> V_158 ) ) ;
if ( F_189 ( & V_2 -> V_158 ) ) {
V_15 = F_31 ( & V_2 -> V_19 ) ;
if ( ! V_15 )
return;
F_82 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_6 ( V_15 , V_18 ) ;
if ( V_2 -> V_12 ) {
F_238 ( & V_2 -> V_158 ) ;
F_187 ( V_15 ) ;
if ( F_5 ( V_39 , & V_2 -> V_8 ) )
F_239 ( & V_2 -> V_168 ) ;
else
F_240 ( & V_2 -> V_168 ,
V_116 + F_71 ( V_398 ) ) ;
} else {
F_7 ( & V_2 -> V_19 , V_15 ) ;
F_8 ( V_2 -> V_20 , & V_2 -> V_21 ) ;
}
}
}
int F_241 ( struct V_1 * V_2 , T_7 V_132 )
{
T_7 V_131 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_129 V_41 ;
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( F_5 ( V_130 , & V_2 -> V_8 ) )
return - V_285 ;
F_49 ( V_2 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( & V_41 . V_131 , V_131 , sizeof( V_41 . V_131 ) ) ;
V_41 . V_132 = V_132 ;
return F_25 ( V_2 , V_134 , sizeof( V_41 ) , & V_41 ) ;
}
int F_242 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_130 , & V_2 -> V_8 ) )
return - V_399 ;
return F_25 ( V_2 , V_400 , 0 , NULL ) ;
}
