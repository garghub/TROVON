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
V_5 = F_18 ( V_31 , V_18 -> V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_36 = F_19 ( V_5 , F_20 ( V_2 ) ) ;
if ( V_36 )
F_4 ( & V_36 -> V_6 ) ;
if ( ! V_36 && ! ( V_42 && V_37 ) ) {
F_4 ( & V_5 -> V_6 ) ;
return - V_41 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_43 . V_44 . V_45 . V_46 = 0xFFFFFFFF ;
V_4 -> V_43 . V_44 . V_47 . V_46 = 0xFFFFFFFF ;
V_4 -> V_43 . V_48 . V_45 . V_46 = 0xFFFFFFFF ;
V_4 -> V_43 . V_48 . V_47 . V_46 = 0xFFFFFFFF ;
V_4 -> V_43 . V_49 . V_45 . V_46 = 0xFFFFFFFF ;
V_4 -> V_43 . V_49 . V_47 . V_46 = 0xFFFFFFFF ;
F_21 ( & V_4 -> V_43 . V_50 ) ;
F_22 ( V_2 , V_51 ) ;
F_23 ( V_2 , 0 , L_2 ) ;
F_24 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_14 * V_52 = V_11 -> V_16 -> V_32 ;
struct V_30 * V_31 =
(struct V_30 * ) V_52 -> V_33 [ 0 ] ;
struct V_53 * V_54 , * V_55 ;
unsigned long V_56 ;
unsigned long V_57 = ( unsigned long ) V_11 -> V_22 ;
int V_58 = V_59 , V_21 ;
int V_60 = 3 ;
char * V_61 ;
F_26 ( & V_31 -> V_62 , V_56 ) ;
V_54 = F_27 ( V_31 -> V_63 , V_57 ) ;
if ( ! V_54 ) {
F_28 ( & V_31 -> V_62 , V_56 ) ;
F_29 ( L_3 , V_11 , NULL ) ;
return V_64 ;
}
V_54 -> V_65 = NULL ;
F_28 ( & V_31 -> V_62 , V_56 ) ;
while ( V_60 -- ) {
V_55 = F_30 ( V_11 ) ;
if ( V_55 )
break;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 ) {
F_29 ( L_4 , V_11 , NULL ) ;
return V_21 ;
}
if ( ! ( F_15 ( & V_31 -> V_19 ) &
V_51 ) ) {
F_29 ( L_5 , V_11 , NULL ) ;
return V_59 ;
}
}
if ( ! V_55 ) {
F_29 ( L_6 , V_11 , NULL ) ;
return V_64 ;
}
F_32 ( & V_55 -> V_66 ) ;
if ( V_55 -> V_19 & V_67 )
V_61 = L_7 ;
else if ( V_55 -> V_19 & V_68 )
V_61 = L_8 ;
else {
V_61 = L_9 ;
V_58 = V_64 ;
}
F_29 ( V_61 , V_11 , V_55 ) ;
F_33 ( V_55 ) ;
return V_58 ;
}
static void F_34 ( struct V_53 * V_54 , void * V_65 )
{
struct V_69 * V_70 =
(struct V_69 * ) V_65 ;
if ( V_54 -> V_65 == NULL || V_54 -> V_71 != V_72 )
return;
if ( V_54 -> V_73 -> V_74 . V_75 != V_70 -> V_75 )
return;
if ( V_70 -> V_76 == V_77 &&
V_54 -> V_73 -> V_74 . V_78 != V_70 -> V_78 )
return;
F_35 ( (struct V_10 * ) V_54 -> V_65 , V_54 ) ;
V_54 -> V_65 = NULL ;
}
static void F_36 ( struct V_3 * V_79 , T_1 V_80 )
{
struct V_30 * V_31 = V_79 -> V_5 -> V_31 ;
struct V_69 V_70 = {
. V_76 = V_81 ,
. V_75 = V_79 -> V_5 -> V_82 ,
} ;
unsigned long V_56 ;
if ( V_80 == V_77 ) {
V_70 . V_76 = V_77 ;
V_70 . V_78 = V_79 -> V_78 ;
}
F_26 ( & V_31 -> V_62 , V_56 ) ;
F_37 ( V_31 -> V_63 , F_34 ,
& V_70 ) ;
F_28 ( & V_31 -> V_62 , V_56 ) ;
}
static int F_38 ( struct V_10 * V_11 , T_1 V_80 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
struct V_53 * V_83 = NULL ;
int V_58 = V_59 , V_21 ;
int V_60 = 3 ;
while ( V_60 -- ) {
V_83 = F_39 ( V_11 , V_80 ) ;
if ( V_83 )
break;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 )
return V_21 ;
if ( ! ( F_15 ( & V_31 -> V_19 ) &
V_51 ) ) {
F_40 ( L_10 , V_11 , V_80 ) ;
return V_59 ;
}
}
if ( ! V_83 )
return V_64 ;
F_32 ( & V_83 -> V_66 ) ;
if ( V_83 -> V_19 & V_84 ) {
F_40 ( L_11 , V_11 , V_80 ) ;
V_58 = V_64 ;
} else {
F_40 ( L_12 , V_11 , V_80 ) ;
F_36 ( V_4 , V_80 ) ;
}
F_33 ( V_83 ) ;
return V_58 ;
}
static int F_41 ( struct V_10 * V_11 )
{
return F_38 ( V_11 , V_77 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
return F_38 ( V_11 , V_81 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
int V_21 ;
F_44 ( V_31 , 0 , L_13 ) ;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 )
return V_21 ;
return V_59 ;
}
int F_45 ( struct V_30 * V_31 )
{
struct V_85 V_86 ;
if ( V_31 -> V_52 )
return 0 ;
F_46 ( V_31 -> V_87 , & V_86 ) ;
V_31 -> V_52 = F_47 ( & V_88 ,
sizeof ( struct V_30 * ) ) ;
if ( ! V_31 -> V_52 ) {
F_48 ( & V_31 -> V_87 -> V_6 ,
L_14
L_15 ) ;
return - V_89 ;
}
V_31 -> V_52 -> V_90 = 511 ;
V_31 -> V_52 -> V_91 = 0xFFFFFFFF ;
V_31 -> V_52 -> V_92 = 0 ;
V_31 -> V_52 -> V_93 = V_86 . V_94 ;
V_31 -> V_52 -> V_95 = 16 ;
V_31 -> V_52 -> V_96 = V_97 ;
V_31 -> V_52 -> V_33 [ 0 ] = ( unsigned long ) V_31 ;
if ( F_49 ( V_31 -> V_52 , & V_31 -> V_87 -> V_6 ) ) {
F_50 ( V_31 -> V_52 ) ;
return - V_89 ;
}
return 0 ;
}
void F_51 ( struct V_30 * V_31 )
{
struct V_14 * V_15 ;
struct V_34 * V_5 ;
V_15 = V_31 -> V_52 ;
if ( ! V_15 )
return;
F_52 ( & V_31 -> V_98 ) ;
F_53 (port, &adapter->port_list, list)
V_5 -> V_18 = NULL ;
F_54 ( & V_31 -> V_98 ) ;
F_55 ( V_15 ) ;
F_56 ( V_15 ) ;
F_50 ( V_15 ) ;
V_31 -> V_52 = NULL ;
}
static struct V_99 *
F_57 ( struct V_30 * V_31 )
{
struct V_99 * V_100 ;
if ( ! V_31 -> V_100 ) {
V_100 = F_58 ( sizeof( * V_100 ) , V_101 ) ;
if ( ! V_100 )
return NULL ;
V_31 -> V_100 = V_100 ;
}
memset ( V_31 -> V_100 , 0 , sizeof( * V_31 -> V_100 ) ) ;
return V_31 -> V_100 ;
}
static void F_59 ( struct V_99 * V_100 ,
struct V_102 * V_65 ,
struct V_102 * V_103 )
{
V_100 -> V_104 =
V_65 -> V_104 - V_103 -> V_104 ;
V_100 -> V_105 = V_65 -> V_105 - V_103 -> V_105 ;
V_100 -> V_106 = V_65 -> V_106 - V_103 -> V_106 ;
V_100 -> V_107 = V_65 -> V_107 - V_103 -> V_107 ;
V_100 -> V_108 = V_65 -> V_108 - V_103 -> V_108 ;
V_100 -> V_109 = V_65 -> V_110 - V_103 -> V_110 ;
V_100 -> V_111 = V_65 -> V_112 - V_103 -> V_112 ;
V_100 -> V_113 = V_65 -> V_113 - V_103 -> V_113 ;
V_100 -> V_114 = V_65 -> V_114 - V_103 -> V_114 ;
V_100 -> V_115 = V_65 -> V_116 - V_103 -> V_116 ;
V_100 -> V_117 = V_65 -> V_118 - V_103 -> V_118 ;
V_100 -> V_119 =
V_65 -> V_120 - V_103 -> V_120 ;
V_100 -> V_121 =
V_65 -> V_122 - V_103 -> V_122 ;
V_100 -> V_123 =
V_65 -> V_124 - V_103 -> V_124 ;
V_100 -> V_125 = V_65 -> V_126 - V_103 -> V_126 ;
V_100 -> V_127 =
V_65 -> V_128 - V_103 -> V_128 ;
V_100 -> V_129 =
V_65 -> V_130 - V_103 -> V_130 ;
V_100 -> V_131 =
V_65 -> V_132 - V_103 -> V_132 ;
V_100 -> V_133 = V_65 -> V_134 - V_103 -> V_134 ;
V_100 -> V_135 = V_65 -> V_136 - V_103 -> V_136 ;
}
static void F_60 ( struct V_99 * V_100 ,
struct V_102 * V_65 )
{
V_100 -> V_104 = V_65 -> V_104 ;
V_100 -> V_105 = V_65 -> V_105 ;
V_100 -> V_106 = V_65 -> V_106 ;
V_100 -> V_107 = V_65 -> V_107 ;
V_100 -> V_108 = V_65 -> V_108 ;
V_100 -> V_109 = V_65 -> V_110 ;
V_100 -> V_111 = V_65 -> V_112 ;
V_100 -> V_113 = V_65 -> V_113 ;
V_100 -> V_114 = V_65 -> V_114 ;
V_100 -> V_115 = V_65 -> V_116 ;
V_100 -> V_117 = V_65 -> V_118 ;
V_100 -> V_119 = V_65 -> V_120 ;
V_100 -> V_121 = V_65 -> V_122 ;
V_100 -> V_123 = V_65 -> V_124 ;
V_100 -> V_125 = V_65 -> V_126 ;
V_100 -> V_127 = V_65 -> V_128 ;
V_100 -> V_129 = V_65 -> V_130 ;
V_100 -> V_131 = V_65 -> V_132 ;
V_100 -> V_133 = V_65 -> V_134 ;
V_100 -> V_135 = V_65 -> V_136 ;
}
static struct V_99 * F_61 ( struct V_14 * V_32 )
{
struct V_30 * V_31 ;
struct V_99 * V_100 ;
struct V_102 * V_65 ;
int V_21 ;
V_31 = (struct V_30 * ) V_32 -> V_33 [ 0 ] ;
V_100 = F_57 ( V_31 ) ;
if ( ! V_100 )
return NULL ;
V_65 = F_62 ( sizeof( * V_65 ) , V_101 ) ;
if ( ! V_65 )
return NULL ;
V_21 = F_63 ( V_31 -> V_137 , V_65 ) ;
if ( V_21 ) {
F_64 ( V_65 ) ;
return NULL ;
}
if ( V_31 -> V_138 &&
( ( V_139 / V_140 - V_31 -> V_138 ) <
V_65 -> V_104 ) )
F_59 ( V_100 , V_65 ,
V_31 -> V_141 ) ;
else
F_60 ( V_100 , V_65 ) ;
F_64 ( V_65 ) ;
return V_100 ;
}
static void F_65 ( struct V_14 * V_15 )
{
struct V_30 * V_31 ;
struct V_102 * V_65 ;
int V_21 ;
V_31 = (struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_65 = F_62 ( sizeof( * V_65 ) , V_101 ) ;
if ( ! V_65 )
return;
V_21 = F_63 ( V_31 -> V_137 , V_65 ) ;
if ( V_21 )
F_64 ( V_65 ) ;
else {
V_31 -> V_138 = V_139 / V_140 ;
F_64 ( V_31 -> V_141 ) ;
V_31 -> V_141 = V_65 ;
}
}
static void F_66 ( struct V_14 * V_15 )
{
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
int V_19 = F_15 ( & V_31 -> V_19 ) ;
if ( ( V_19 & V_51 ) &&
! ( V_19 & V_142 ) )
F_67 ( V_15 ) = V_143 ;
else if ( V_19 & V_142 )
F_67 ( V_15 ) = V_144 ;
else if ( V_19 & V_23 )
F_67 ( V_15 ) = V_145 ;
else
F_67 ( V_15 ) = V_146 ;
}
static void F_68 ( struct V_17 * V_18 , T_2 V_147 )
{
V_18 -> V_148 = V_147 ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_34 * V_5 ;
struct V_14 * V_15 = F_70 ( V_18 ) ;
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_5 = F_18 ( V_31 , V_18 -> V_40 ) ;
if ( V_5 ) {
F_71 ( V_5 , 0 , L_16 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_72 ( struct V_34 * V_5 )
{
struct V_149 V_150 ;
struct V_17 * V_18 ;
if ( V_5 -> V_18 )
return;
V_150 . V_151 = V_5 -> V_152 ;
V_150 . V_40 = V_5 -> V_153 ;
V_150 . V_154 = V_5 -> V_155 ;
V_150 . V_156 = V_157 ;
F_73 ( L_17 , V_5 -> V_31 , V_5 , NULL ,
V_158 ,
V_158 ) ;
V_18 = F_74 ( V_5 -> V_31 -> V_52 , 0 , & V_150 ) ;
if ( ! V_18 ) {
F_48 ( & V_5 -> V_31 -> V_87 -> V_6 ,
L_18 ,
( unsigned long long ) V_5 -> V_153 ) ;
return;
}
V_18 -> V_159 = V_5 -> V_159 ;
V_18 -> V_160 = V_5 -> V_160 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_161 = V_18 -> V_162 ;
F_75 ( V_5 ) ;
}
static void F_76 ( struct V_34 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_18 ;
if ( V_18 ) {
F_73 ( L_19 , V_5 -> V_31 , V_5 , NULL ,
V_163 ,
V_163 ) ;
F_77 ( V_18 ) ;
V_5 -> V_18 = NULL ;
}
}
void F_78 ( struct V_34 * V_5 )
{
F_79 ( & V_5 -> V_6 ) ;
V_5 -> V_164 = V_165 ;
if ( ! F_80 ( V_5 -> V_31 -> V_166 , & V_5 -> V_167 ) )
F_4 ( & V_5 -> V_6 ) ;
}
void F_81 ( struct V_34 * V_5 )
{
F_79 ( & V_5 -> V_6 ) ;
V_5 -> V_164 = V_168 ;
if ( V_5 -> V_18 && F_80 ( V_5 -> V_31 -> V_166 ,
& V_5 -> V_167 ) )
return;
F_4 ( & V_5 -> V_6 ) ;
}
void F_82 ( struct V_30 * V_31 )
{
unsigned long V_56 ;
struct V_34 * V_5 ;
F_83 ( & V_31 -> V_98 , V_56 ) ;
F_53 (port, &adapter->port_list, list)
F_81 ( V_5 ) ;
F_84 ( & V_31 -> V_98 , V_56 ) ;
}
void F_85 ( struct V_169 * V_170 )
{
struct V_34 * V_5 = F_86 ( V_170 , struct V_34 ,
V_167 ) ;
while ( V_5 -> V_164 ) {
if ( V_5 -> V_164 == V_165 ) {
V_5 -> V_164 = V_171 ;
F_72 ( V_5 ) ;
} else {
V_5 -> V_164 = V_171 ;
F_76 ( V_5 ) ;
}
}
F_4 ( & V_5 -> V_6 ) ;
}
void F_87 ( struct V_30 * V_31 )
{
unsigned int V_172 = 0 ;
unsigned int V_173 ;
struct V_14 * V_15 = V_31 -> V_52 ;
V_173 = F_15 ( & V_31 -> V_19 ) &
V_174 ;
if ( V_175 &&
V_31 -> V_176 & V_177 )
V_172 |= V_178 ;
if ( V_175 && V_173 &&
V_31 -> V_176 & V_179 ) {
V_172 |= V_180 ;
F_88 ( V_15 , V_181 ) ;
V_15 -> V_182 = V_31 -> V_137 -> V_183 / 2 ;
V_15 -> V_184 = V_31 -> V_137 -> V_183 / 2 ;
V_15 -> V_185 = V_15 -> V_184 * 8 ;
}
F_89 ( V_15 , V_172 ) ;
}
void F_90 ( struct V_10 * V_186 , int V_187 )
{
F_91 ( 1 , V_186 -> V_188 ,
V_189 , 0x10 , V_187 ) ;
F_92 ( V_186 , V_190 ) ;
V_186 -> V_12 |= V_191 ;
F_8 ( V_186 , V_192 ) ;
}
