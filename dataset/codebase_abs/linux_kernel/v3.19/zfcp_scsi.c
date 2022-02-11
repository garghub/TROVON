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
static int F_34 ( struct V_10 * V_11 , T_1 V_69 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
struct V_53 * V_70 = NULL ;
int V_58 = V_59 , V_21 ;
int V_60 = 3 ;
while ( V_60 -- ) {
V_70 = F_35 ( V_11 , V_69 ) ;
if ( V_70 )
break;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 )
return V_21 ;
if ( ! ( F_15 ( & V_31 -> V_19 ) &
V_51 ) ) {
F_36 ( L_10 , V_11 , V_69 ) ;
return V_59 ;
}
}
if ( ! V_70 )
return V_64 ;
F_32 ( & V_70 -> V_66 ) ;
if ( V_70 -> V_19 & V_71 ) {
F_36 ( L_11 , V_11 , V_69 ) ;
V_58 = V_64 ;
} else
F_36 ( L_12 , V_11 , V_69 ) ;
F_33 ( V_70 ) ;
return V_58 ;
}
static int F_37 ( struct V_10 * V_11 )
{
return F_34 ( V_11 , V_72 ) ;
}
static int F_38 ( struct V_10 * V_11 )
{
return F_34 ( V_11 , V_73 ) ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_16 ) ;
struct V_30 * V_31 = V_4 -> V_5 -> V_31 ;
int V_21 ;
F_40 ( V_31 , 0 , L_13 ) ;
F_24 ( V_31 ) ;
V_21 = F_31 ( V_11 ) ;
if ( V_21 )
return V_21 ;
return V_59 ;
}
int F_41 ( struct V_30 * V_31 )
{
struct V_74 V_75 ;
if ( V_31 -> V_52 )
return 0 ;
F_42 ( V_31 -> V_76 , & V_75 ) ;
V_31 -> V_52 = F_43 ( & V_77 ,
sizeof ( struct V_30 * ) ) ;
if ( ! V_31 -> V_52 ) {
F_44 ( & V_31 -> V_76 -> V_6 ,
L_14
L_15 ) ;
return - V_78 ;
}
V_31 -> V_52 -> V_79 = 511 ;
V_31 -> V_52 -> V_80 = 0xFFFFFFFF ;
V_31 -> V_52 -> V_81 = 0 ;
V_31 -> V_52 -> V_82 = V_75 . V_83 ;
V_31 -> V_52 -> V_84 = 16 ;
V_31 -> V_52 -> V_85 = V_86 ;
V_31 -> V_52 -> V_33 [ 0 ] = ( unsigned long ) V_31 ;
if ( F_45 ( V_31 -> V_52 , & V_31 -> V_76 -> V_6 ) ) {
F_46 ( V_31 -> V_52 ) ;
return - V_78 ;
}
return 0 ;
}
void F_47 ( struct V_30 * V_31 )
{
struct V_14 * V_15 ;
struct V_34 * V_5 ;
V_15 = V_31 -> V_52 ;
if ( ! V_15 )
return;
F_48 ( & V_31 -> V_87 ) ;
F_49 (port, &adapter->port_list, list)
V_5 -> V_18 = NULL ;
F_50 ( & V_31 -> V_87 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
F_46 ( V_15 ) ;
V_31 -> V_52 = NULL ;
}
static struct V_88 *
F_53 ( struct V_30 * V_31 )
{
struct V_88 * V_89 ;
if ( ! V_31 -> V_89 ) {
V_89 = F_54 ( sizeof( * V_89 ) , V_90 ) ;
if ( ! V_89 )
return NULL ;
V_31 -> V_89 = V_89 ;
}
memset ( V_31 -> V_89 , 0 , sizeof( * V_31 -> V_89 ) ) ;
return V_31 -> V_89 ;
}
static void F_55 ( struct V_88 * V_89 ,
struct V_91 * V_65 ,
struct V_91 * V_92 )
{
V_89 -> V_93 =
V_65 -> V_93 - V_92 -> V_93 ;
V_89 -> V_94 = V_65 -> V_94 - V_92 -> V_94 ;
V_89 -> V_95 = V_65 -> V_95 - V_92 -> V_95 ;
V_89 -> V_96 = V_65 -> V_96 - V_92 -> V_96 ;
V_89 -> V_97 = V_65 -> V_97 - V_92 -> V_97 ;
V_89 -> V_98 = V_65 -> V_99 - V_92 -> V_99 ;
V_89 -> V_100 = V_65 -> V_101 - V_92 -> V_101 ;
V_89 -> V_102 = V_65 -> V_102 - V_92 -> V_102 ;
V_89 -> V_103 = V_65 -> V_103 - V_92 -> V_103 ;
V_89 -> V_104 = V_65 -> V_105 - V_92 -> V_105 ;
V_89 -> V_106 = V_65 -> V_107 - V_92 -> V_107 ;
V_89 -> V_108 =
V_65 -> V_109 - V_92 -> V_109 ;
V_89 -> V_110 =
V_65 -> V_111 - V_92 -> V_111 ;
V_89 -> V_112 =
V_65 -> V_113 - V_92 -> V_113 ;
V_89 -> V_114 = V_65 -> V_115 - V_92 -> V_115 ;
V_89 -> V_116 =
V_65 -> V_117 - V_92 -> V_117 ;
V_89 -> V_118 =
V_65 -> V_119 - V_92 -> V_119 ;
V_89 -> V_120 =
V_65 -> V_121 - V_92 -> V_121 ;
V_89 -> V_122 = V_65 -> V_123 - V_92 -> V_123 ;
V_89 -> V_124 = V_65 -> V_125 - V_92 -> V_125 ;
}
static void F_56 ( struct V_88 * V_89 ,
struct V_91 * V_65 )
{
V_89 -> V_93 = V_65 -> V_93 ;
V_89 -> V_94 = V_65 -> V_94 ;
V_89 -> V_95 = V_65 -> V_95 ;
V_89 -> V_96 = V_65 -> V_96 ;
V_89 -> V_97 = V_65 -> V_97 ;
V_89 -> V_98 = V_65 -> V_99 ;
V_89 -> V_100 = V_65 -> V_101 ;
V_89 -> V_102 = V_65 -> V_102 ;
V_89 -> V_103 = V_65 -> V_103 ;
V_89 -> V_104 = V_65 -> V_105 ;
V_89 -> V_106 = V_65 -> V_107 ;
V_89 -> V_108 = V_65 -> V_109 ;
V_89 -> V_110 = V_65 -> V_111 ;
V_89 -> V_112 = V_65 -> V_113 ;
V_89 -> V_114 = V_65 -> V_115 ;
V_89 -> V_116 = V_65 -> V_117 ;
V_89 -> V_118 = V_65 -> V_119 ;
V_89 -> V_120 = V_65 -> V_121 ;
V_89 -> V_122 = V_65 -> V_123 ;
V_89 -> V_124 = V_65 -> V_125 ;
}
static struct V_88 * F_57 ( struct V_14 * V_32 )
{
struct V_30 * V_31 ;
struct V_88 * V_89 ;
struct V_91 * V_65 ;
int V_21 ;
V_31 = (struct V_30 * ) V_32 -> V_33 [ 0 ] ;
V_89 = F_53 ( V_31 ) ;
if ( ! V_89 )
return NULL ;
V_65 = F_58 ( sizeof( * V_65 ) , V_90 ) ;
if ( ! V_65 )
return NULL ;
V_21 = F_59 ( V_31 -> V_126 , V_65 ) ;
if ( V_21 ) {
F_60 ( V_65 ) ;
return NULL ;
}
if ( V_31 -> V_127 &&
( ( V_128 / V_129 - V_31 -> V_127 ) <
V_65 -> V_93 ) )
F_55 ( V_89 , V_65 ,
V_31 -> V_130 ) ;
else
F_56 ( V_89 , V_65 ) ;
F_60 ( V_65 ) ;
return V_89 ;
}
static void F_61 ( struct V_14 * V_15 )
{
struct V_30 * V_31 ;
struct V_91 * V_65 ;
int V_21 ;
V_31 = (struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_65 = F_58 ( sizeof( * V_65 ) , V_90 ) ;
if ( ! V_65 )
return;
V_21 = F_59 ( V_31 -> V_126 , V_65 ) ;
if ( V_21 )
F_60 ( V_65 ) ;
else {
V_31 -> V_127 = V_128 / V_129 ;
F_60 ( V_31 -> V_130 ) ;
V_31 -> V_130 = V_65 ;
}
}
static void F_62 ( struct V_14 * V_15 )
{
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
int V_19 = F_15 ( & V_31 -> V_19 ) ;
if ( ( V_19 & V_51 ) &&
! ( V_19 & V_131 ) )
F_63 ( V_15 ) = V_132 ;
else if ( V_19 & V_131 )
F_63 ( V_15 ) = V_133 ;
else if ( V_19 & V_23 )
F_63 ( V_15 ) = V_134 ;
else
F_63 ( V_15 ) = V_135 ;
}
static void F_64 ( struct V_17 * V_18 , T_2 V_136 )
{
V_18 -> V_137 = V_136 ;
}
static void F_65 ( struct V_17 * V_18 )
{
struct V_34 * V_5 ;
struct V_14 * V_15 = F_66 ( V_18 ) ;
struct V_30 * V_31 =
(struct V_30 * ) V_15 -> V_33 [ 0 ] ;
V_5 = F_18 ( V_31 , V_18 -> V_40 ) ;
if ( V_5 ) {
F_67 ( V_5 , 0 , L_16 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_68 ( struct V_34 * V_5 )
{
struct V_138 V_139 ;
struct V_17 * V_18 ;
if ( V_5 -> V_18 )
return;
V_139 . V_140 = V_5 -> V_141 ;
V_139 . V_40 = V_5 -> V_142 ;
V_139 . V_143 = V_5 -> V_144 ;
V_139 . V_145 = V_146 ;
V_18 = F_69 ( V_5 -> V_31 -> V_52 , 0 , & V_139 ) ;
if ( ! V_18 ) {
F_44 ( & V_5 -> V_31 -> V_76 -> V_6 ,
L_17 ,
( unsigned long long ) V_5 -> V_142 ) ;
return;
}
V_18 -> V_147 = V_5 -> V_147 ;
V_18 -> V_148 = V_5 -> V_148 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_149 = V_18 -> V_150 ;
F_70 ( V_5 ) ;
}
static void F_71 ( struct V_34 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_18 ;
if ( V_18 ) {
F_72 ( V_18 ) ;
V_5 -> V_18 = NULL ;
}
}
void F_73 ( struct V_34 * V_5 )
{
F_74 ( & V_5 -> V_6 ) ;
V_5 -> V_151 = V_152 ;
if ( ! F_75 ( V_5 -> V_31 -> V_153 , & V_5 -> V_154 ) )
F_4 ( & V_5 -> V_6 ) ;
}
void F_76 ( struct V_34 * V_5 )
{
F_74 ( & V_5 -> V_6 ) ;
V_5 -> V_151 = V_155 ;
if ( V_5 -> V_18 && F_75 ( V_5 -> V_31 -> V_153 ,
& V_5 -> V_154 ) )
return;
F_4 ( & V_5 -> V_6 ) ;
}
void F_77 ( struct V_30 * V_31 )
{
unsigned long V_56 ;
struct V_34 * V_5 ;
F_78 ( & V_31 -> V_87 , V_56 ) ;
F_49 (port, &adapter->port_list, list)
F_76 ( V_5 ) ;
F_79 ( & V_31 -> V_87 , V_56 ) ;
}
void F_80 ( struct V_156 * V_157 )
{
struct V_34 * V_5 = F_81 ( V_157 , struct V_34 ,
V_154 ) ;
while ( V_5 -> V_151 ) {
if ( V_5 -> V_151 == V_152 ) {
V_5 -> V_151 = V_158 ;
F_68 ( V_5 ) ;
} else {
V_5 -> V_151 = V_158 ;
F_71 ( V_5 ) ;
}
}
F_4 ( & V_5 -> V_6 ) ;
}
void F_82 ( struct V_30 * V_31 )
{
unsigned int V_159 = 0 ;
unsigned int V_160 ;
struct V_14 * V_15 = V_31 -> V_52 ;
V_160 = F_15 ( & V_31 -> V_19 ) &
V_161 ;
if ( V_162 &&
V_31 -> V_163 & V_164 )
V_159 |= V_165 ;
if ( V_162 && V_160 &&
V_31 -> V_163 & V_166 ) {
V_159 |= V_167 ;
F_83 ( V_15 , V_168 ) ;
V_15 -> V_169 = V_31 -> V_126 -> V_170 / 2 ;
V_15 -> V_171 = V_31 -> V_126 -> V_170 / 2 ;
V_15 -> V_172 = V_15 -> V_171 * 8 ;
}
F_84 ( V_15 , V_159 ) ;
}
void F_85 ( struct V_10 * V_173 , int V_174 )
{
F_86 ( 1 , V_173 -> V_175 ,
V_176 , 0x10 , V_174 ) ;
F_87 ( V_173 , V_177 ) ;
V_173 -> V_12 |= V_178 ;
F_8 ( V_173 , V_179 ) ;
}
