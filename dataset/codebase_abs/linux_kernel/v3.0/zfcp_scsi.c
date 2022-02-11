static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
switch ( V_4 ) {
case V_5 :
F_2 ( V_2 , F_3 ( V_2 ) , V_3 ) ;
break;
case V_6 :
F_4 ( V_2 , V_3 ) ;
break;
case V_7 :
F_2 ( V_2 , F_3 ( V_2 ) , V_3 ) ;
break;
default:
return - V_8 ;
}
return V_2 -> V_9 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
F_7 ( V_2 , L_1 ) ;
F_8 ( & V_11 -> V_12 -> V_13 ) ;
}
static int F_9 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 )
F_2 ( V_14 , V_16 , V_17 ) ;
else
F_2 ( V_14 , 0 , 1 ) ;
return 0 ;
}
static void F_10 ( struct V_18 * V_19 , int V_20 )
{
F_11 ( V_19 , V_20 ) ;
F_12 ( V_19 ) ;
V_19 -> V_21 ( V_19 ) ;
}
static
int F_13 ( struct V_22 * V_23 , struct V_18 * V_19 )
{
struct V_10 * V_11 = F_6 ( V_19 -> V_24 ) ;
struct V_25 * V_26 = F_14 ( F_15 ( V_19 -> V_24 ) ) ;
int V_27 , V_28 , V_29 ;
V_19 -> V_20 = 0 ;
V_19 -> V_30 = NULL ;
V_28 = F_16 ( V_26 ) ;
if ( F_17 ( V_28 ) ) {
V_19 -> V_20 = V_28 ;
F_12 ( V_19 ) ;
V_19 -> V_21 ( V_19 ) ;
return 0 ;
}
V_27 = F_18 ( & V_11 -> V_27 ) ;
if ( F_17 ( V_27 & V_31 ) &&
! ( F_18 ( & V_11 -> V_12 -> V_27 ) &
V_31 ) ) {
F_10 ( V_19 , V_32 ) ;
return 0 ;
}
if ( F_17 ( ! ( V_27 & V_33 ) ) ) {
F_10 ( V_19 , V_34 ) ;
return 0 ;
}
V_29 = F_19 ( V_19 ) ;
if ( F_17 ( V_29 == - V_35 ) )
return V_36 ;
else if ( F_17 ( V_29 < 0 ) )
return V_37 ;
return V_29 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_14 ( F_15 ( V_2 ) ) ;
struct V_38 * V_39 =
(struct V_38 * ) V_2 -> V_40 -> V_41 [ 0 ] ;
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_42 * V_12 ;
struct V_43 * V_44 ;
int V_45 = V_39 -> V_46 & V_47 ;
V_12 = F_21 ( V_39 , V_26 -> V_48 ) ;
if ( ! V_12 )
return - V_49 ;
V_44 = F_22 ( V_12 , F_23 ( V_2 ) ) ;
if ( V_44 )
F_8 ( & V_44 -> V_13 ) ;
if ( ! V_44 && ! ( V_50 && V_45 ) ) {
F_8 ( & V_12 -> V_13 ) ;
return - V_49 ;
}
V_11 -> V_12 = V_12 ;
V_11 -> V_51 . V_52 . V_53 . V_54 = 0xFFFFFFFF ;
V_11 -> V_51 . V_52 . V_55 . V_54 = 0xFFFFFFFF ;
V_11 -> V_51 . V_56 . V_53 . V_54 = 0xFFFFFFFF ;
V_11 -> V_51 . V_56 . V_55 . V_54 = 0xFFFFFFFF ;
V_11 -> V_51 . V_57 . V_53 . V_54 = 0xFFFFFFFF ;
V_11 -> V_51 . V_57 . V_55 . V_54 = 0xFFFFFFFF ;
F_24 ( & V_11 -> V_51 . V_58 ) ;
F_25 ( V_2 , V_59 ) ;
F_26 ( V_2 , 0 , L_2 ) ;
F_27 ( V_12 -> V_39 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_22 * V_60 = V_19 -> V_24 -> V_40 ;
struct V_38 * V_39 =
(struct V_38 * ) V_60 -> V_41 [ 0 ] ;
struct V_61 * V_62 , * V_63 ;
unsigned long V_64 ;
unsigned long V_65 = ( unsigned long ) V_19 -> V_30 ;
int V_66 = V_67 , V_29 ;
int V_68 = 3 ;
char * V_69 ;
F_29 ( & V_39 -> V_70 , V_64 ) ;
V_62 = F_30 ( V_39 -> V_71 , V_65 ) ;
if ( ! V_62 ) {
F_31 ( & V_39 -> V_70 , V_64 ) ;
F_32 ( L_3 , V_19 , NULL ) ;
return V_72 ;
}
V_62 -> V_73 = NULL ;
F_31 ( & V_39 -> V_70 , V_64 ) ;
while ( V_68 -- ) {
V_63 = F_33 ( V_19 ) ;
if ( V_63 )
break;
F_27 ( V_39 ) ;
V_29 = F_34 ( V_19 ) ;
if ( V_29 ) {
F_32 ( L_4 , V_19 , NULL ) ;
return V_29 ;
}
if ( ! ( F_18 ( & V_39 -> V_27 ) &
V_59 ) ) {
F_32 ( L_5 , V_19 , NULL ) ;
return V_67 ;
}
}
if ( ! V_63 ) {
F_32 ( L_6 , V_19 , NULL ) ;
return V_72 ;
}
F_35 ( & V_63 -> V_74 ) ;
if ( V_63 -> V_27 & V_75 )
V_69 = L_7 ;
else if ( V_63 -> V_27 & V_76 )
V_69 = L_8 ;
else {
V_69 = L_9 ;
V_66 = V_72 ;
}
F_32 ( V_69 , V_19 , V_63 ) ;
F_36 ( V_63 ) ;
return V_66 ;
}
static int F_37 ( struct V_18 * V_19 , T_1 V_77 )
{
struct V_10 * V_11 = F_6 ( V_19 -> V_24 ) ;
struct V_38 * V_39 = V_11 -> V_12 -> V_39 ;
struct V_61 * V_78 = NULL ;
int V_66 = V_67 , V_29 ;
int V_68 = 3 ;
while ( V_68 -- ) {
V_78 = F_38 ( V_19 , V_77 ) ;
if ( V_78 )
break;
F_27 ( V_39 ) ;
V_29 = F_34 ( V_19 ) ;
if ( V_29 )
return V_29 ;
if ( ! ( F_18 ( & V_39 -> V_27 ) &
V_59 ) ) {
F_39 ( L_10 , V_19 , V_77 ) ;
return V_67 ;
}
}
if ( ! V_78 )
return V_72 ;
F_35 ( & V_78 -> V_74 ) ;
if ( V_78 -> V_27 & V_79 ) {
F_39 ( L_11 , V_19 , V_77 ) ;
V_66 = V_72 ;
} else
F_39 ( L_12 , V_19 , V_77 ) ;
F_36 ( V_78 ) ;
return V_66 ;
}
static int F_40 ( struct V_18 * V_19 )
{
return F_37 ( V_19 , V_80 ) ;
}
static int F_41 ( struct V_18 * V_19 )
{
return F_37 ( V_19 , V_81 ) ;
}
static int F_42 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = F_6 ( V_19 -> V_24 ) ;
struct V_38 * V_39 = V_11 -> V_12 -> V_39 ;
int V_29 ;
F_43 ( V_39 , 0 , L_13 ) ;
F_27 ( V_39 ) ;
V_29 = F_34 ( V_19 ) ;
if ( V_29 )
return V_29 ;
return V_67 ;
}
int F_44 ( struct V_38 * V_39 )
{
struct V_82 V_83 ;
if ( V_39 -> V_60 )
return 0 ;
F_45 ( V_39 -> V_84 , & V_83 ) ;
V_39 -> V_60 = F_46 ( & V_85 ,
sizeof ( struct V_38 * ) ) ;
if ( ! V_39 -> V_60 ) {
F_47 ( & V_39 -> V_84 -> V_13 ,
L_14
L_15 ) ;
return - V_86 ;
}
V_39 -> V_60 -> V_87 = 511 ;
V_39 -> V_60 -> V_88 = 0xFFFFFFFF ;
V_39 -> V_60 -> V_89 = 0 ;
V_39 -> V_60 -> V_90 = V_83 . V_91 ;
V_39 -> V_60 -> V_92 = 16 ;
V_39 -> V_60 -> V_93 = V_94 ;
V_39 -> V_60 -> V_41 [ 0 ] = ( unsigned long ) V_39 ;
if ( F_48 ( V_39 -> V_60 , & V_39 -> V_84 -> V_13 ) ) {
F_49 ( V_39 -> V_60 ) ;
return - V_86 ;
}
return 0 ;
}
void F_50 ( struct V_38 * V_39 )
{
struct V_22 * V_23 ;
struct V_42 * V_12 ;
V_23 = V_39 -> V_60 ;
if ( ! V_23 )
return;
F_51 ( & V_39 -> V_95 ) ;
F_52 (port, &adapter->port_list, list)
V_12 -> V_26 = NULL ;
F_53 ( & V_39 -> V_95 ) ;
F_54 ( V_23 ) ;
F_55 ( V_23 ) ;
F_49 ( V_23 ) ;
V_39 -> V_60 = NULL ;
}
static struct V_96 *
F_56 ( struct V_38 * V_39 )
{
struct V_96 * V_97 ;
if ( ! V_39 -> V_97 ) {
V_97 = F_57 ( sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 )
return NULL ;
V_39 -> V_97 = V_97 ;
}
memset ( V_39 -> V_97 , 0 , sizeof( * V_39 -> V_97 ) ) ;
return V_39 -> V_97 ;
}
static void F_58 ( struct V_96 * V_97 ,
struct V_99 * V_73 ,
struct V_99 * V_100 )
{
V_97 -> V_101 =
V_73 -> V_101 - V_100 -> V_101 ;
V_97 -> V_102 = V_73 -> V_102 - V_100 -> V_102 ;
V_97 -> V_103 = V_73 -> V_103 - V_100 -> V_103 ;
V_97 -> V_104 = V_73 -> V_104 - V_100 -> V_104 ;
V_97 -> V_105 = V_73 -> V_105 - V_100 -> V_105 ;
V_97 -> V_106 = V_73 -> V_107 - V_100 -> V_107 ;
V_97 -> V_108 = V_73 -> V_109 - V_100 -> V_109 ;
V_97 -> V_110 = V_73 -> V_110 - V_100 -> V_110 ;
V_97 -> V_111 = V_73 -> V_111 - V_100 -> V_111 ;
V_97 -> V_112 = V_73 -> V_113 - V_100 -> V_113 ;
V_97 -> V_114 = V_73 -> V_115 - V_100 -> V_115 ;
V_97 -> V_116 =
V_73 -> V_117 - V_100 -> V_117 ;
V_97 -> V_118 =
V_73 -> V_119 - V_100 -> V_119 ;
V_97 -> V_120 =
V_73 -> V_121 - V_100 -> V_121 ;
V_97 -> V_122 = V_73 -> V_123 - V_100 -> V_123 ;
V_97 -> V_124 =
V_73 -> V_125 - V_100 -> V_125 ;
V_97 -> V_126 =
V_73 -> V_127 - V_100 -> V_127 ;
V_97 -> V_128 =
V_73 -> V_129 - V_100 -> V_129 ;
V_97 -> V_130 = V_73 -> V_131 - V_100 -> V_131 ;
V_97 -> V_132 = V_73 -> V_133 - V_100 -> V_133 ;
}
static void F_59 ( struct V_96 * V_97 ,
struct V_99 * V_73 )
{
V_97 -> V_101 = V_73 -> V_101 ;
V_97 -> V_102 = V_73 -> V_102 ;
V_97 -> V_103 = V_73 -> V_103 ;
V_97 -> V_104 = V_73 -> V_104 ;
V_97 -> V_105 = V_73 -> V_105 ;
V_97 -> V_106 = V_73 -> V_107 ;
V_97 -> V_108 = V_73 -> V_109 ;
V_97 -> V_110 = V_73 -> V_110 ;
V_97 -> V_111 = V_73 -> V_111 ;
V_97 -> V_112 = V_73 -> V_113 ;
V_97 -> V_114 = V_73 -> V_115 ;
V_97 -> V_116 = V_73 -> V_117 ;
V_97 -> V_118 = V_73 -> V_119 ;
V_97 -> V_120 = V_73 -> V_121 ;
V_97 -> V_122 = V_73 -> V_123 ;
V_97 -> V_124 = V_73 -> V_125 ;
V_97 -> V_126 = V_73 -> V_127 ;
V_97 -> V_128 = V_73 -> V_129 ;
V_97 -> V_130 = V_73 -> V_131 ;
V_97 -> V_132 = V_73 -> V_133 ;
}
static struct V_96 * F_60 ( struct V_22 * V_40 )
{
struct V_38 * V_39 ;
struct V_96 * V_97 ;
struct V_99 * V_73 ;
int V_29 ;
V_39 = (struct V_38 * ) V_40 -> V_41 [ 0 ] ;
V_97 = F_56 ( V_39 ) ;
if ( ! V_97 )
return NULL ;
V_73 = F_61 ( sizeof( * V_73 ) , V_98 ) ;
if ( ! V_73 )
return NULL ;
V_29 = F_62 ( V_39 -> V_134 , V_73 ) ;
if ( V_29 ) {
F_63 ( V_73 ) ;
return NULL ;
}
if ( V_39 -> V_135 &&
( ( V_136 / V_137 - V_39 -> V_135 ) <
V_73 -> V_101 ) )
F_58 ( V_97 , V_73 ,
V_39 -> V_138 ) ;
else
F_59 ( V_97 , V_73 ) ;
F_63 ( V_73 ) ;
return V_97 ;
}
static void F_64 ( struct V_22 * V_23 )
{
struct V_38 * V_39 ;
struct V_99 * V_73 ;
int V_29 ;
V_39 = (struct V_38 * ) V_23 -> V_41 [ 0 ] ;
V_73 = F_61 ( sizeof( * V_73 ) , V_98 ) ;
if ( ! V_73 )
return;
V_29 = F_62 ( V_39 -> V_134 , V_73 ) ;
if ( V_29 )
F_63 ( V_73 ) ;
else {
V_39 -> V_135 = V_136 / V_137 ;
F_63 ( V_39 -> V_138 ) ;
V_39 -> V_138 = V_73 ;
}
}
static void F_65 ( struct V_22 * V_23 )
{
struct V_38 * V_39 =
(struct V_38 * ) V_23 -> V_41 [ 0 ] ;
int V_27 = F_18 ( & V_39 -> V_27 ) ;
if ( ( V_27 & V_59 ) &&
! ( V_27 & V_139 ) )
F_66 ( V_23 ) = V_140 ;
else if ( V_27 & V_139 )
F_66 ( V_23 ) = V_141 ;
else if ( V_27 & V_31 )
F_66 ( V_23 ) = V_142 ;
else
F_66 ( V_23 ) = V_143 ;
}
static void F_67 ( struct V_25 * V_26 , T_2 V_144 )
{
V_26 -> V_145 = V_144 ;
}
static void F_68 ( struct V_25 * V_26 )
{
struct V_42 * V_12 ;
struct V_22 * V_23 = F_69 ( V_26 ) ;
struct V_38 * V_39 =
(struct V_38 * ) V_23 -> V_41 [ 0 ] ;
V_12 = F_21 ( V_39 , V_26 -> V_48 ) ;
if ( V_12 ) {
F_70 ( V_12 , 0 , L_16 ) ;
F_8 ( & V_12 -> V_13 ) ;
}
}
static void F_71 ( struct V_42 * V_12 )
{
struct V_146 V_147 ;
struct V_25 * V_26 ;
if ( V_12 -> V_26 )
return;
V_147 . V_148 = V_12 -> V_149 ;
V_147 . V_48 = V_12 -> V_150 ;
V_147 . V_151 = V_12 -> V_152 ;
V_147 . V_153 = V_154 ;
V_26 = F_72 ( V_12 -> V_39 -> V_60 , 0 , & V_147 ) ;
if ( ! V_26 ) {
F_47 ( & V_12 -> V_39 -> V_84 -> V_13 ,
L_17 ,
( unsigned long long ) V_12 -> V_150 ) ;
return;
}
V_26 -> V_155 = V_12 -> V_155 ;
V_26 -> V_156 = V_12 -> V_156 ;
V_12 -> V_26 = V_26 ;
V_12 -> V_157 = V_26 -> V_158 ;
F_73 ( V_12 ) ;
}
static void F_74 ( struct V_42 * V_12 )
{
struct V_25 * V_26 = V_12 -> V_26 ;
if ( V_26 ) {
F_75 ( V_26 ) ;
V_12 -> V_26 = NULL ;
}
}
void F_76 ( struct V_42 * V_12 )
{
F_77 ( & V_12 -> V_13 ) ;
V_12 -> V_159 = V_160 ;
if ( ! F_78 ( V_12 -> V_39 -> V_161 , & V_12 -> V_162 ) )
F_8 ( & V_12 -> V_13 ) ;
}
void F_79 ( struct V_42 * V_12 )
{
F_77 ( & V_12 -> V_13 ) ;
V_12 -> V_159 = V_163 ;
if ( V_12 -> V_26 && F_78 ( V_12 -> V_39 -> V_161 ,
& V_12 -> V_162 ) )
return;
F_8 ( & V_12 -> V_13 ) ;
}
void F_80 ( struct V_38 * V_39 )
{
unsigned long V_64 ;
struct V_42 * V_12 ;
F_81 ( & V_39 -> V_95 , V_64 ) ;
F_52 (port, &adapter->port_list, list)
F_79 ( V_12 ) ;
F_82 ( & V_39 -> V_95 , V_64 ) ;
}
void F_83 ( struct V_164 * V_165 )
{
struct V_42 * V_12 = F_84 ( V_165 , struct V_42 ,
V_162 ) ;
while ( V_12 -> V_159 ) {
if ( V_12 -> V_159 == V_160 ) {
V_12 -> V_159 = V_166 ;
F_71 ( V_12 ) ;
} else {
V_12 -> V_159 = V_166 ;
F_74 ( V_12 ) ;
}
}
F_8 ( & V_12 -> V_13 ) ;
}
void F_85 ( struct V_38 * V_39 )
{
unsigned int V_167 = 0 ;
unsigned int V_168 ;
struct V_22 * V_23 = V_39 -> V_60 ;
V_168 = F_18 ( & V_39 -> V_27 ) &
V_169 ;
if ( V_170 &&
V_39 -> V_171 & V_172 )
V_167 |= V_173 ;
if ( V_170 && V_168 &&
V_39 -> V_171 & V_174 ) {
V_167 |= V_175 ;
F_86 ( V_23 , V_176 ) ;
V_23 -> V_177 = V_178 / 2 ;
V_23 -> V_179 = V_178 / 2 ;
V_23 -> V_180 = V_178 * 8 / 2 ;
}
F_87 ( V_23 , V_167 ) ;
}
void F_88 ( struct V_18 * V_181 , int V_182 )
{
F_89 ( 1 , V_181 -> V_183 ,
V_184 , 0x10 , V_182 ) ;
F_90 ( V_181 , V_185 ) ;
V_181 -> V_20 |= V_186 ;
F_11 ( V_181 , V_187 ) ;
}
