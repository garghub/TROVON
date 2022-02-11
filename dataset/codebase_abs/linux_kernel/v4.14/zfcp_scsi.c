static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
return;
F_3 ( V_2 , L_1 ) ;
F_4 ( & V_4 -> V_5 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_7 )
{
if ( V_7 -> V_8 )
F_6 ( V_7 , V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_10 * V_11 , int V_12 )
{
F_8 ( V_11 , V_12 ) ;
F_9 ( V_11 ) ;
V_11 -> V_13 ( V_11 ) ;
}
static
int F_10 ( struct V_14 * V_15 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_17 * V_18 = F_11 ( F_12 ( V_11 -> V_16 ) ) ;
int V_19 , V_20 , V_21 ;
V_11 -> V_12 = 0 ;
V_11 -> V_22 = NULL ;
V_20 = F_13 ( V_18 ) ;
if ( F_14 ( V_20 ) ) {
V_11 -> V_12 = V_20 ;
F_9 ( V_11 ) ;
V_11 -> V_13 ( V_11 ) ;
return 0 ;
}
V_19 = F_15 ( & V_4 -> V_19 ) ;
if ( F_14 ( V_19 & V_23 ) &&
! ( F_15 ( & V_4 -> V_5 -> V_19 ) &
V_23 ) ) {
F_7 ( V_11 , V_24 ) ;
return 0 ;
}
if ( F_14 ( ! ( V_19 & V_25 ) ) ) {
F_7 ( V_11 , V_26 ) ;
return 0 ;
}
V_21 = F_16 ( V_11 ) ;
if ( F_14 ( V_21 == - V_27 ) )
return V_28 ;
else if ( F_14 ( V_21 < 0 ) )
return V_29 ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( F_12 ( V_2 ) ) ;
struct V_30 * V_31 =
(struct V_30 * ) V_2 -> V_32 -> V_33 [ 0 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_5 ;
struct V_35 * V_36 ;
int V_37 = V_31 -> V_38 & V_39 ;
V_4 -> V_40 . V_31 = V_31 ;
V_4 -> V_40 . V_2 = V_2 ;
V_5 = F_18 ( V_31 , V_18 -> V_41 ) ;
if ( ! V_5 )
return - V_42 ;
V_4 -> V_40 . V_5 = V_5 ;
V_36 = F_19 ( V_5 , F_20 ( V_2 ) ) ;
if ( V_36 )
F_4 ( & V_36 -> V_6 ) ;
if ( ! V_36 && ! ( V_43 && V_37 ) ) {
F_4 ( & V_5 -> V_6 ) ;
return - V_42 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_44 . V_45 . V_46 . V_47 = 0xFFFFFFFF ;
V_4 -> V_44 . V_45 . V_48 . V_47 = 0xFFFFFFFF ;
V_4 -> V_44 . V_49 . V_46 . V_47 = 0xFFFFFFFF ;
V_4 -> V_44 . V_49 . V_48 . V_47 = 0xFFFFFFFF ;
V_4 -> V_44 . V_50 . V_46 . V_47 = 0xFFFFFFFF ;
V_4 -> V_44 . V_50 . V_48 . V_47 = 0xFFFFFFFF ;
F_21 ( & V_4 -> V_44 . V_51 ) ;
F_22 ( V_2 , V_52 ) ;
F_23 ( V_2 , 0 , L_2 ) ;
F_24 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_14 * V_53 = V_11 -> V_16 -> V_32 ;
struct V_30 * V_31 =
(struct V_30 * ) V_53 -> V_33 [ 0 ] ;
struct V_54 * V_55 , * V_56 ;
unsigned long V_57 ;
unsigned long V_58 = ( unsigned long ) V_11 -> V_22 ;
int V_59 = V_60 , V_21 ;
int V_61 = 3 ;
char * V_62 ;
F_26 ( & V_31 -> V_63 , V_57 ) ;
V_55 = F_27 ( V_31 -> V_64 , V_58 ) ;
if ( ! V_55 ) {
F_28 ( & V_31 -> V_63 , V_57 ) ;
F_29 ( L_3 , V_11 , NULL ) ;
return V_65 ;
}
V_55 -> V_66 = NULL ;
F_28 ( & V_31 -> V_63 , V_57 ) ;
while ( V_61 -- ) {
V_56 = F_30 ( V_11 ) ;
if ( V_56 )
break;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 ) {
F_29 ( L_4 , V_11 , NULL ) ;
return V_21 ;
}
if ( ! ( F_15 ( & V_31 -> V_19 ) &
V_52 ) ) {
F_29 ( L_5 , V_11 , NULL ) ;
return V_60 ;
}
}
if ( ! V_56 ) {
F_29 ( L_6 , V_11 , NULL ) ;
return V_65 ;
}
F_32 ( & V_56 -> V_67 ) ;
if ( V_56 -> V_19 & V_68 )
V_62 = L_7 ;
else if ( V_56 -> V_19 & V_69 )
V_62 = L_8 ;
else {
V_62 = L_9 ;
V_59 = V_65 ;
}
F_29 ( V_62 , V_11 , V_56 ) ;
F_33 ( V_56 ) ;
return V_59 ;
}
static void F_34 ( struct V_54 * V_55 , void * V_66 )
{
struct V_70 * V_71 =
(struct V_70 * ) V_66 ;
if ( V_55 -> V_66 == NULL || V_55 -> V_72 != V_73 )
return;
if ( V_55 -> V_74 -> V_75 . V_76 != V_71 -> V_76 )
return;
if ( V_71 -> V_77 == V_78 &&
V_55 -> V_74 -> V_75 . V_79 != V_71 -> V_79 )
return;
F_35 ( (struct V_10 * ) V_55 -> V_66 , V_55 ) ;
V_55 -> V_66 = NULL ;
}
static void F_36 ( struct V_3 * V_80 , T_1 V_81 )
{
struct V_30 * V_31 = V_80 -> V_5 -> V_31 ;
struct V_70 V_71 = {
. V_77 = V_82 ,
. V_76 = V_80 -> V_5 -> V_83 ,
} ;
unsigned long V_57 ;
if ( V_81 == V_78 ) {
V_71 . V_77 = V_78 ;
V_71 . V_79 = V_80 -> V_79 ;
}
F_26 ( & V_31 -> V_63 , V_57 ) ;
F_37 ( V_31 -> V_64 , F_34 ,
& V_71 ) ;
F_28 ( & V_31 -> V_63 , V_57 ) ;
}
static int F_38 ( struct V_10 * V_11 , T_1 V_81 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
struct V_54 * V_84 = NULL ;
int V_59 = V_60 , V_21 ;
int V_61 = 3 ;
while ( V_61 -- ) {
V_84 = F_39 ( V_11 , V_81 ) ;
if ( V_84 )
break;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 ) {
F_40 ( L_10 , V_11 , V_81 , NULL ) ;
return V_21 ;
}
if ( ! ( F_15 ( & V_31 -> V_19 ) &
V_52 ) ) {
F_40 ( L_11 , V_11 , V_81 , NULL ) ;
return V_60 ;
}
}
if ( ! V_84 ) {
F_40 ( L_12 , V_11 , V_81 , NULL ) ;
return V_65 ;
}
F_32 ( & V_84 -> V_67 ) ;
if ( V_84 -> V_19 & V_85 ) {
F_40 ( L_13 , V_11 , V_81 , V_84 ) ;
V_59 = V_65 ;
} else {
F_40 ( L_14 , V_11 , V_81 , V_84 ) ;
F_36 ( V_4 , V_81 ) ;
}
F_33 ( V_84 ) ;
return V_59 ;
}
static int F_41 ( struct V_10 * V_11 )
{
return F_38 ( V_11 , V_78 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
return F_38 ( V_11 , V_82 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
int V_21 ;
F_44 ( V_31 , 0 , L_15 ) ;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 )
return V_21 ;
return V_60 ;
}
int F_45 ( struct V_30 * V_31 )
{
struct V_86 V_87 ;
if ( V_31 -> V_53 )
return 0 ;
F_46 ( V_31 -> V_88 , & V_87 ) ;
V_31 -> V_53 = F_47 ( & V_89 ,
sizeof ( struct V_30 * ) ) ;
if ( ! V_31 -> V_53 ) {
F_48 ( & V_31 -> V_88 -> V_6 ,
L_16
L_17 ) ;
return - V_90 ;
}
V_31 -> V_53 -> V_91 = 511 ;
V_31 -> V_53 -> V_92 = 0xFFFFFFFF ;
V_31 -> V_53 -> V_93 = 0 ;
V_31 -> V_53 -> V_94 = V_87 . V_95 ;
V_31 -> V_53 -> V_96 = 16 ;
V_31 -> V_53 -> V_97 = V_98 ;
V_31 -> V_53 -> V_33 [ 0 ] = ( unsigned long ) V_31 ;
if ( F_49 ( V_31 -> V_53 , & V_31 -> V_88 -> V_6 ) ) {
F_50 ( V_31 -> V_53 ) ;
return - V_90 ;
}
return 0 ;
}
void F_51 ( struct V_30 * V_31 )
{
struct V_14 * V_15 ;
struct V_34 * V_5 ;
V_15 = V_31 -> V_53 ;
if ( ! V_15 )
return;
F_52 ( & V_31 -> V_99 ) ;
F_53 (port, &adapter->port_list, list)
V_5 -> V_18 = NULL ;
F_54 ( & V_31 -> V_99 ) ;
F_55 ( V_15 ) ;
F_56 ( V_15 ) ;
F_50 ( V_15 ) ;
V_31 -> V_53 = NULL ;
}
static struct V_100 *
F_57 ( struct V_30 * V_31 )
{
struct V_100 * V_101 ;
if ( ! V_31 -> V_101 ) {
V_101 = F_58 ( sizeof( * V_101 ) , V_102 ) ;
if ( ! V_101 )
return NULL ;
V_31 -> V_101 = V_101 ;
}
memset ( V_31 -> V_101 , 0 , sizeof( * V_31 -> V_101 ) ) ;
return V_31 -> V_101 ;
}
static void F_59 ( struct V_100 * V_101 ,
struct V_103 * V_66 ,
struct V_103 * V_104 )
{
V_101 -> V_105 =
V_66 -> V_105 - V_104 -> V_105 ;
V_101 -> V_106 = V_66 -> V_106 - V_104 -> V_106 ;
V_101 -> V_107 = V_66 -> V_107 - V_104 -> V_107 ;
V_101 -> V_108 = V_66 -> V_108 - V_104 -> V_108 ;
V_101 -> V_109 = V_66 -> V_109 - V_104 -> V_109 ;
V_101 -> V_110 = V_66 -> V_111 - V_104 -> V_111 ;
V_101 -> V_112 = V_66 -> V_113 - V_104 -> V_113 ;
V_101 -> V_114 = V_66 -> V_114 - V_104 -> V_114 ;
V_101 -> V_115 = V_66 -> V_115 - V_104 -> V_115 ;
V_101 -> V_116 = V_66 -> V_117 - V_104 -> V_117 ;
V_101 -> V_118 = V_66 -> V_119 - V_104 -> V_119 ;
V_101 -> V_120 =
V_66 -> V_121 - V_104 -> V_121 ;
V_101 -> V_122 =
V_66 -> V_123 - V_104 -> V_123 ;
V_101 -> V_124 =
V_66 -> V_125 - V_104 -> V_125 ;
V_101 -> V_126 = V_66 -> V_127 - V_104 -> V_127 ;
V_101 -> V_128 =
V_66 -> V_129 - V_104 -> V_129 ;
V_101 -> V_130 =
V_66 -> V_131 - V_104 -> V_131 ;
V_101 -> V_132 =
V_66 -> V_133 - V_104 -> V_133 ;
V_101 -> V_134 = V_66 -> V_135 - V_104 -> V_135 ;
V_101 -> V_136 = V_66 -> V_137 - V_104 -> V_137 ;
}
static void F_60 ( struct V_100 * V_101 ,
struct V_103 * V_66 )
{
V_101 -> V_105 = V_66 -> V_105 ;
V_101 -> V_106 = V_66 -> V_106 ;
V_101 -> V_107 = V_66 -> V_107 ;
V_101 -> V_108 = V_66 -> V_108 ;
V_101 -> V_109 = V_66 -> V_109 ;
V_101 -> V_110 = V_66 -> V_111 ;
V_101 -> V_112 = V_66 -> V_113 ;
V_101 -> V_114 = V_66 -> V_114 ;
V_101 -> V_115 = V_66 -> V_115 ;
V_101 -> V_116 = V_66 -> V_117 ;
V_101 -> V_118 = V_66 -> V_119 ;
V_101 -> V_120 = V_66 -> V_121 ;
V_101 -> V_122 = V_66 -> V_123 ;
V_101 -> V_124 = V_66 -> V_125 ;
V_101 -> V_126 = V_66 -> V_127 ;
V_101 -> V_128 = V_66 -> V_129 ;
V_101 -> V_130 = V_66 -> V_131 ;
V_101 -> V_132 = V_66 -> V_133 ;
V_101 -> V_134 = V_66 -> V_135 ;
V_101 -> V_136 = V_66 -> V_137 ;
}
static struct V_100 * F_61 ( struct V_14 * V_32 )
{
struct V_30 * V_31 ;
struct V_100 * V_101 ;
struct V_103 * V_66 ;
int V_21 ;
V_31 = (struct V_30 * ) V_32 -> V_33 [ 0 ] ;
V_101 = F_57 ( V_31 ) ;
if ( ! V_101 )
return NULL ;
V_66 = F_62 ( sizeof( * V_66 ) , V_102 ) ;
if ( ! V_66 )
return NULL ;
V_21 = F_63 ( V_31 -> V_138 , V_66 ) ;
if ( V_21 ) {
F_64 ( V_66 ) ;
return NULL ;
}
if ( V_31 -> V_139 &&
( ( V_140 / V_141 - V_31 -> V_139 ) <
V_66 -> V_105 ) )
F_59 ( V_101 , V_66 ,
V_31 -> V_142 ) ;
else
F_60 ( V_101 , V_66 ) ;
F_64 ( V_66 ) ;
return V_101 ;
}
static void F_65 ( struct V_14 * V_15 )
{
struct V_30 * V_31 ;
struct V_103 * V_66 ;
int V_21 ;
V_31 = (struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_66 = F_62 ( sizeof( * V_66 ) , V_102 ) ;
if ( ! V_66 )
return;
V_21 = F_63 ( V_31 -> V_138 , V_66 ) ;
if ( V_21 )
F_64 ( V_66 ) ;
else {
V_31 -> V_139 = V_140 / V_141 ;
F_64 ( V_31 -> V_142 ) ;
V_31 -> V_142 = V_66 ;
}
}
static void F_66 ( struct V_14 * V_15 )
{
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
int V_19 = F_15 ( & V_31 -> V_19 ) ;
if ( ( V_19 & V_52 ) &&
! ( V_19 & V_143 ) )
F_67 ( V_15 ) = V_144 ;
else if ( V_19 & V_143 )
F_67 ( V_15 ) = V_145 ;
else if ( V_19 & V_23 )
F_67 ( V_15 ) = V_146 ;
else
F_67 ( V_15 ) = V_147 ;
}
static void F_68 ( struct V_17 * V_18 , T_2 V_148 )
{
V_18 -> V_149 = V_148 ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_34 * V_5 ;
struct V_14 * V_15 = F_70 ( V_18 ) ;
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_5 = F_18 ( V_31 , V_18 -> V_41 ) ;
if ( V_5 ) {
F_71 ( V_5 , 0 , L_18 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_72 ( struct V_34 * V_5 )
{
struct V_150 V_151 ;
struct V_17 * V_18 ;
if ( V_5 -> V_18 )
return;
V_151 . V_152 = V_5 -> V_153 ;
V_151 . V_41 = V_5 -> V_154 ;
V_151 . V_155 = V_5 -> V_156 ;
V_151 . V_157 = V_158 ;
F_73 ( L_19 , V_5 -> V_31 , V_5 , NULL ,
V_159 ,
V_159 ) ;
V_18 = F_74 ( V_5 -> V_31 -> V_53 , 0 , & V_151 ) ;
if ( ! V_18 ) {
F_48 ( & V_5 -> V_31 -> V_88 -> V_6 ,
L_20 ,
( unsigned long long ) V_5 -> V_154 ) ;
return;
}
V_18 -> V_160 = V_5 -> V_160 ;
V_18 -> V_161 = V_5 -> V_161 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_162 = V_18 -> V_163 ;
F_75 ( V_5 ) ;
}
static void F_76 ( struct V_34 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_18 ;
if ( V_18 ) {
F_73 ( L_21 , V_5 -> V_31 , V_5 , NULL ,
V_164 ,
V_164 ) ;
F_77 ( V_18 ) ;
V_5 -> V_18 = NULL ;
}
}
void F_78 ( struct V_34 * V_5 )
{
F_79 ( & V_5 -> V_6 ) ;
V_5 -> V_165 = V_166 ;
if ( ! F_80 ( V_5 -> V_31 -> V_167 , & V_5 -> V_168 ) )
F_4 ( & V_5 -> V_6 ) ;
}
void F_81 ( struct V_34 * V_5 )
{
F_79 ( & V_5 -> V_6 ) ;
V_5 -> V_165 = V_169 ;
if ( V_5 -> V_18 && F_80 ( V_5 -> V_31 -> V_167 ,
& V_5 -> V_168 ) )
return;
F_4 ( & V_5 -> V_6 ) ;
}
void F_82 ( struct V_30 * V_31 )
{
unsigned long V_57 ;
struct V_34 * V_5 ;
F_83 ( & V_31 -> V_99 , V_57 ) ;
F_53 (port, &adapter->port_list, list)
F_81 ( V_5 ) ;
F_84 ( & V_31 -> V_99 , V_57 ) ;
}
void F_85 ( struct V_170 * V_171 )
{
struct V_34 * V_5 = F_86 ( V_171 , struct V_34 ,
V_168 ) ;
while ( V_5 -> V_165 ) {
if ( V_5 -> V_165 == V_166 ) {
V_5 -> V_165 = V_172 ;
F_72 ( V_5 ) ;
} else {
V_5 -> V_165 = V_172 ;
F_76 ( V_5 ) ;
}
}
F_4 ( & V_5 -> V_6 ) ;
}
void F_87 ( struct V_30 * V_31 )
{
unsigned int V_173 = 0 ;
unsigned int V_174 ;
struct V_14 * V_15 = V_31 -> V_53 ;
V_174 = F_15 ( & V_31 -> V_19 ) &
V_175 ;
if ( V_176 &&
V_31 -> V_177 & V_178 )
V_173 |= V_179 ;
if ( V_176 && V_174 &&
V_31 -> V_177 & V_180 ) {
V_173 |= V_181 ;
F_88 ( V_15 , V_182 ) ;
V_15 -> V_183 = V_31 -> V_138 -> V_184 / 2 ;
V_15 -> V_185 = V_31 -> V_138 -> V_184 / 2 ;
V_15 -> V_186 = V_15 -> V_185 * 8 ;
}
F_89 ( V_15 , V_173 ) ;
}
void F_90 ( struct V_10 * V_187 , int V_188 )
{
F_91 ( 1 , V_187 -> V_189 ,
V_190 , 0x10 , V_188 ) ;
F_92 ( V_187 , V_191 ) ;
V_187 -> V_12 |= V_192 ;
F_8 ( V_187 , V_193 ) ;
}
