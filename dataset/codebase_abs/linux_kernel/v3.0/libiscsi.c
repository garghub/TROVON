static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_1 != V_2 && ( ( V_1 < V_2 && ( V_2 - V_1 < V_3 ) ) ||
( V_1 > V_2 && ( V_2 - V_1 < V_3 ) ) ) ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
return V_1 == V_2 || ( ( V_1 < V_2 && ( V_2 - V_1 < V_3 ) ) ||
( V_1 > V_2 && ( V_2 - V_1 < V_3 ) ) ) ;
}
inline void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
if ( V_11 -> V_12 )
F_5 ( V_11 -> V_12 , & V_5 -> V_13 ) ;
}
static void F_6 ( struct V_14 * V_8 ,
T_2 V_15 , T_2 V_16 )
{
if ( F_1 ( V_16 , V_15 - 1 ) )
return;
if ( V_15 != V_8 -> V_15 &&
! F_1 ( V_15 , V_8 -> V_15 ) )
V_8 -> V_15 = V_15 ;
if ( V_16 != V_8 -> V_16 &&
! F_1 ( V_16 , V_8 -> V_16 ) ) {
V_8 -> V_16 = V_16 ;
if ( ! F_7 ( & V_8 -> V_17 -> V_18 ) ||
! F_7 ( & V_8 -> V_17 -> V_19 ) )
F_3 ( V_8 -> V_17 ) ;
}
}
void F_8 ( struct V_14 * V_8 , struct V_20 * V_21 )
{
F_6 ( V_8 , F_9 ( V_21 -> V_15 ) ,
F_9 ( V_21 -> V_16 ) ) ;
}
void F_10 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_21 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
unsigned int V_27 = V_25 -> V_28 - V_25 -> V_29 ;
V_23 -> V_30 = sizeof( struct V_26 ) ;
memset ( V_21 , 0 , sizeof( struct V_26 ) ) ;
V_21 -> V_31 = V_25 -> V_31 ;
V_21 -> V_32 = F_11 ( V_25 -> V_32 ) ;
V_25 -> V_32 ++ ;
V_21 -> V_33 = V_34 ;
memcpy ( V_21 -> V_35 , V_23 -> V_35 , sizeof( V_21 -> V_35 ) ) ;
V_21 -> V_36 = V_23 -> V_37 ;
V_21 -> V_38 = V_25 -> V_38 ;
V_21 -> V_39 = F_11 ( V_25 -> V_40 + V_25 -> V_29 ) ;
if ( V_27 > V_5 -> V_41 ) {
F_12 ( V_21 -> V_42 , V_5 -> V_41 ) ;
V_25 -> V_43 = V_5 -> V_41 ;
V_21 -> V_44 = 0 ;
} else {
F_12 ( V_21 -> V_42 , V_27 ) ;
V_25 -> V_43 = V_27 ;
V_21 -> V_44 = V_45 ;
}
V_5 -> V_46 ++ ;
}
static int F_13 ( struct V_22 * V_23 , unsigned V_47 )
{
unsigned V_48 = V_23 -> V_30 + V_47 ;
if ( V_48 > V_23 -> V_49 ) {
F_14 ( 1 ) ;
return - V_50 ;
}
F_14 ( V_47 & ( V_51 - 1 ) ) ;
V_23 -> V_30 = V_48 ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_52 * V_53 = V_23 -> V_54 ;
unsigned V_55 , V_56 ;
unsigned short V_57 ;
struct V_58 * V_59 ;
int V_60 ;
V_59 = F_16 ( V_23 ) ;
V_55 = V_53 -> V_61 - V_62 ;
F_17 ( V_55 > sizeof( V_59 -> V_63 ) ) ;
V_57 = V_55 + sizeof( V_59 -> V_64 ) ;
V_56 = F_18 ( V_55 ) ;
V_60 = F_13 ( V_23 , sizeof( V_59 -> V_57 ) +
sizeof( V_59 -> V_65 ) + V_57 + V_56 ) ;
if ( V_60 )
return V_60 ;
if ( V_56 )
memset ( & V_59 -> V_63 [ V_55 ] , 0 , V_56 ) ;
V_59 -> V_57 = F_19 ( V_57 ) ;
V_59 -> V_65 = V_66 ;
V_59 -> V_64 = 0 ;
memcpy ( V_59 -> V_63 , V_53 -> V_67 + V_62 , V_55 ) ;
F_20 ( V_23 -> V_5 -> V_8 ,
L_1
L_2
L_3 , V_53 -> V_61 , V_55 , V_56 , V_57 ,
V_23 -> V_30 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 )
{
struct V_52 * V_54 = V_23 -> V_54 ;
struct V_68 * V_69 ;
int V_60 ;
V_69 = F_16 ( V_23 ) ;
V_60 = F_13 ( V_23 , sizeof( * V_69 ) ) ;
if ( V_60 )
return V_60 ;
V_69 -> V_57 =
F_19 ( sizeof( V_69 -> V_70 ) +
sizeof( V_69 -> V_64 ) ) ;
V_69 -> V_65 = V_71 ;
V_69 -> V_64 = 0 ;
V_69 -> V_70 = F_11 ( F_22 ( V_54 ) -> V_72 ) ;
F_20 ( V_23 -> V_5 -> V_8 ,
L_4
L_5 ,
F_9 ( V_69 -> V_70 ) ,
F_23 ( V_69 -> V_57 ) ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 , int V_33 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_73 * V_74 = & V_5 -> V_75 ;
unsigned int V_76 ;
if ( V_5 -> V_77 == V_78 )
return 0 ;
if ( ( V_74 -> V_33 & V_79 ) != V_80 )
return 0 ;
switch ( F_25 ( V_74 ) ) {
case V_81 :
V_76 = F_26 ( (struct V_82 * ) V_74 -> V_35 ) ;
if ( V_76 != V_23 -> V_54 -> V_83 -> V_35 )
return 0 ;
case V_84 :
if ( V_33 != V_34 ) {
F_27 ( V_85 , V_5 ,
L_6
L_7
L_8 ,
V_23 -> V_21 -> V_33 , V_33 ,
V_23 -> V_36 , V_23 -> V_37 ) ;
return - V_86 ;
}
if ( V_5 -> V_8 -> V_87 ) {
F_27 ( V_85 , V_5 ,
L_6
L_9 ,
V_23 -> V_21 -> V_33 , V_33 ,
V_23 -> V_36 , V_23 -> V_37 ) ;
return - V_86 ;
}
break;
case V_88 :
if ( V_33 == V_34 &&
V_23 -> V_37 == V_74 -> V_89 ) {
F_20 ( V_5 -> V_8 ,
L_10
L_11
L_12 , V_23 -> V_36 ,
V_23 -> V_37 ) ;
return - V_86 ;
}
break;
}
return 0 ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_52 * V_54 = V_23 -> V_54 ;
struct V_90 * V_21 ;
unsigned V_91 , V_61 ;
T_3 V_36 ;
int V_60 ;
V_60 = F_24 ( V_23 , V_92 ) ;
if ( V_60 )
return V_60 ;
if ( V_5 -> V_8 -> V_93 -> V_94 ) {
V_60 = V_5 -> V_8 -> V_93 -> V_94 ( V_23 , V_92 ) ;
if ( V_60 )
return V_60 ;
}
V_21 = (struct V_90 * ) V_23 -> V_21 ;
V_36 = V_21 -> V_36 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
if ( V_8 -> V_93 -> V_95 )
V_21 -> V_36 = V_23 -> V_37 = V_36 ;
else
V_21 -> V_36 = V_23 -> V_37 = F_29 ( V_23 -> V_36 ,
V_23 -> V_5 -> V_8 -> V_96 ) ;
V_23 -> V_30 = 0 ;
V_60 = F_13 ( V_23 , sizeof( * V_21 ) ) ;
if ( V_60 )
return V_60 ;
V_21 -> V_33 = V_92 ;
V_21 -> V_44 = V_97 ;
F_30 ( V_54 -> V_83 -> V_35 , (struct V_82 * ) V_21 -> V_35 ) ;
memcpy ( V_23 -> V_35 , V_21 -> V_35 , sizeof( V_23 -> V_35 ) ) ;
V_21 -> V_38 = F_11 ( V_5 -> V_38 ) ;
V_61 = V_54 -> V_61 ;
if ( V_61 < V_62 )
memset ( & V_21 -> V_98 [ V_61 ] , 0 , V_62 - V_61 ) ;
else if ( V_61 > V_62 ) {
V_60 = F_15 ( V_23 ) ;
if ( V_60 )
return V_60 ;
V_61 = V_62 ;
}
memcpy ( V_21 -> V_98 , V_54 -> V_67 , V_61 ) ;
V_23 -> V_99 = 0 ;
if ( F_31 ( V_54 ) ) {
V_21 -> V_44 |= V_100 ;
V_60 = F_21 ( V_23 ) ;
if ( V_60 )
return V_60 ;
}
if ( V_54 -> V_101 == V_102 ) {
unsigned V_103 = F_32 ( V_54 ) -> V_72 ;
struct V_24 * V_25 = & V_23 -> V_104 ;
V_21 -> V_28 = F_11 ( V_103 ) ;
V_21 -> V_44 |= V_105 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
if ( V_8 -> V_106 ) {
if ( V_103 >= V_8 -> V_107 )
V_23 -> V_99 = F_33 ( V_8 -> V_107 ,
V_5 -> V_41 ) ;
else
V_23 -> V_99 = F_33 ( V_103 ,
V_5 -> V_41 ) ;
F_12 ( V_21 -> V_42 , V_23 -> V_99 ) ;
} else
F_34 ( V_21 -> V_42 ) ;
if ( ! V_8 -> V_108 ) {
V_25 -> V_28 = F_33 ( V_8 -> V_107 , V_103 ) -
V_23 -> V_99 ;
V_25 -> V_40 = V_23 -> V_99 ;
V_25 -> V_31 = F_11 ( V_109 ) ;
V_25 -> V_38 = F_11 ( V_5 -> V_38 ) ;
}
if ( ! V_23 -> V_104 . V_28 )
V_21 -> V_44 |= V_45 ;
} else {
V_21 -> V_44 |= V_45 ;
F_34 ( V_21 -> V_42 ) ;
V_21 -> V_28 = F_11 ( F_22 ( V_54 ) -> V_72 ) ;
if ( V_54 -> V_101 == V_110 )
V_21 -> V_44 |= V_100 ;
}
V_91 = V_23 -> V_30 - sizeof( * V_21 ) ;
F_14 ( V_91 & ( V_51 - 1 ) ) ;
V_91 /= V_51 ;
F_14 ( V_91 >= 256 ) ;
V_21 -> V_111 = V_91 & 0xFF ;
V_21 -> V_112 = V_23 -> V_112 = F_11 ( V_8 -> V_112 ) ;
if ( V_8 -> V_93 -> V_113 && V_8 -> V_93 -> V_113 ( V_23 ) )
return - V_114 ;
V_23 -> V_115 = V_116 ;
V_8 -> V_112 ++ ;
V_5 -> V_117 ++ ;
F_20 ( V_8 , L_13
L_14 ,
F_31 ( V_54 ) ? L_15 :
V_54 -> V_101 == V_102 ?
L_16 : L_17 , V_5 -> V_118 , V_54 , V_54 -> V_67 [ 0 ] ,
V_23 -> V_36 , F_35 ( V_54 ) ,
F_31 ( V_54 ) ? F_22 ( V_54 ) -> V_72 : 0 ,
V_8 -> V_112 ,
V_8 -> V_16 - V_8 -> V_15 + 1 ) ;
return 0 ;
}
static void F_36 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_52 * V_54 = V_23 -> V_54 ;
int V_119 = V_23 -> V_115 ;
F_20 ( V_8 , L_18 ,
V_23 -> V_36 , V_23 -> V_115 , V_23 -> V_54 ) ;
V_8 -> V_93 -> V_120 ( V_23 ) ;
V_23 -> V_115 = V_121 ;
V_23 -> V_54 = NULL ;
if ( V_5 -> V_122 == V_23 )
return;
F_37 ( & V_8 -> V_123 . V_124 , ( void * ) & V_23 , sizeof( void * ) ) ;
if ( V_54 ) {
V_23 -> V_54 = NULL ;
V_54 -> V_125 . V_126 = NULL ;
if ( V_119 != V_127 )
V_54 -> V_128 ( V_54 ) ;
}
}
void F_38 ( struct V_22 * V_23 )
{
F_39 ( & V_23 -> V_129 ) ;
}
void F_40 ( struct V_22 * V_23 )
{
if ( F_41 ( & V_23 -> V_129 ) )
F_36 ( V_23 ) ;
}
void F_42 ( struct V_22 * V_23 )
{
struct V_14 * V_8 = V_23 -> V_5 -> V_8 ;
F_43 ( & V_8 -> V_130 ) ;
F_40 ( V_23 ) ;
F_44 ( & V_8 -> V_130 ) ;
}
static void F_45 ( struct V_22 * V_23 , int V_115 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
F_20 ( V_5 -> V_8 ,
L_19 ,
V_23 -> V_36 , V_23 -> V_115 , V_23 -> V_54 ) ;
if ( V_23 -> V_115 == V_131 ||
V_23 -> V_115 == V_132 ||
V_23 -> V_115 == V_133 ||
V_23 -> V_115 == V_127 )
return;
F_46 ( V_23 -> V_115 == V_121 ) ;
V_23 -> V_115 = V_115 ;
if ( ! F_7 ( & V_23 -> V_134 ) )
F_47 ( & V_23 -> V_134 ) ;
if ( V_5 -> V_23 == V_23 )
V_5 -> V_23 = NULL ;
if ( V_5 -> V_135 == V_23 )
V_5 -> V_135 = NULL ;
F_40 ( V_23 ) ;
}
void F_48 ( struct V_22 * V_23 ,
T_2 V_15 , T_2 V_16 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
F_20 ( V_5 -> V_8 , L_20 , V_23 -> V_36 ) ;
V_5 -> V_136 = V_137 ;
F_6 ( V_5 -> V_8 , V_15 , V_16 ) ;
F_45 ( V_23 , V_131 ) ;
}
static void F_49 ( struct V_22 * V_23 , int V_138 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
struct V_52 * V_54 ;
int V_115 ;
V_54 = V_23 -> V_54 ;
if ( ! V_54 )
return;
if ( V_23 -> V_115 == V_139 ) {
V_5 -> V_8 -> V_140 -- ;
V_115 = V_131 ;
} else if ( V_138 == V_141 )
V_115 = V_133 ;
else
V_115 = V_132 ;
V_54 -> V_142 = V_138 << 16 ;
if ( ! F_31 ( V_54 ) )
F_50 ( V_54 , F_35 ( V_54 ) ) ;
else {
F_32 ( V_54 ) -> V_143 = F_32 ( V_54 ) -> V_72 ;
F_22 ( V_54 ) -> V_143 = F_22 ( V_54 ) -> V_72 ;
}
F_45 ( V_23 , V_115 ) ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_22 * V_23 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_144 * V_21 = V_23 -> V_21 ;
struct V_145 * V_146 = (struct V_145 * ) V_21 ;
T_4 V_33 = V_21 -> V_33 & V_79 ;
if ( V_5 -> V_8 -> V_115 == V_147 )
return - V_148 ;
if ( V_33 != V_149 && V_33 != V_150 )
V_146 -> V_38 = F_11 ( V_5 -> V_38 ) ;
V_146 -> V_112 = F_11 ( V_8 -> V_112 ) ;
if ( V_21 -> V_36 != V_151 ) {
if ( V_5 -> V_152 == V_153 &&
! ( V_21 -> V_33 & V_154 ) ) {
V_8 -> V_140 ++ ;
V_8 -> V_112 ++ ;
}
}
if ( V_8 -> V_93 -> V_113 && V_8 -> V_93 -> V_113 ( V_23 ) )
return - V_114 ;
if ( ( V_21 -> V_33 & V_79 ) == V_155 )
V_8 -> V_115 = V_147 ;
V_23 -> V_115 = V_116 ;
F_20 ( V_8 , L_21
L_22 , V_21 -> V_33 & V_79 ,
V_21 -> V_36 , V_23 -> V_43 ) ;
return 0 ;
}
static struct V_22 *
F_52 ( struct V_4 * V_5 , struct V_144 * V_21 ,
char * V_156 , T_2 V_157 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_10 * V_11 = F_4 ( V_8 -> V_9 ) ;
T_4 V_33 = V_21 -> V_33 & V_79 ;
struct V_22 * V_23 ;
T_3 V_36 ;
if ( V_8 -> V_115 == V_158 )
return NULL ;
if ( V_33 == V_149 || V_33 == V_150 ) {
if ( V_5 -> V_122 -> V_115 != V_121 ) {
F_27 ( V_159 , V_5 , L_23
L_24 ) ;
return NULL ;
}
V_23 = V_5 -> V_122 ;
} else {
if ( V_8 -> V_115 != V_160 )
return NULL ;
F_17 ( V_5 -> V_152 == V_161 ) ;
F_17 ( V_5 -> V_152 == V_162 ) ;
if ( ! F_53 ( & V_8 -> V_123 . V_124 ,
( void * ) & V_23 , sizeof( void * ) ) )
return NULL ;
}
F_54 ( & V_23 -> V_129 , 1 ) ;
V_23 -> V_5 = V_5 ;
V_23 -> V_54 = NULL ;
F_55 ( & V_23 -> V_134 ) ;
V_23 -> V_115 = V_139 ;
if ( V_157 ) {
memcpy ( V_23 -> V_156 , V_156 , V_157 ) ;
V_23 -> V_43 = V_157 ;
} else
V_23 -> V_43 = 0 ;
if ( V_5 -> V_8 -> V_93 -> V_94 ) {
if ( V_5 -> V_8 -> V_93 -> V_94 ( V_23 , V_21 -> V_33 ) ) {
F_27 ( V_159 , V_5 , L_25
L_26 ) ;
goto V_163;
}
}
V_36 = V_23 -> V_21 -> V_36 ;
V_23 -> V_30 = sizeof( struct V_144 ) ;
memcpy ( V_23 -> V_21 , V_21 , sizeof( struct V_144 ) ) ;
if ( V_21 -> V_36 != V_151 ) {
if ( V_8 -> V_93 -> V_95 )
V_23 -> V_21 -> V_36 = V_36 ;
else
V_23 -> V_21 -> V_36 = F_29 ( V_23 -> V_36 ,
V_23 -> V_5 -> V_8 -> V_96 ) ;
}
if ( ! V_11 -> V_12 ) {
if ( F_51 ( V_5 , V_23 ) )
goto V_163;
if ( V_8 -> V_93 -> V_164 ( V_23 ) )
goto V_163;
} else {
F_56 ( & V_23 -> V_134 , & V_5 -> V_19 ) ;
F_3 ( V_5 ) ;
}
return V_23 ;
V_163:
F_40 ( V_23 ) ;
return NULL ;
}
int F_57 ( struct V_165 * V_166 , struct V_144 * V_21 ,
char * V_156 , T_2 V_157 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
struct V_14 * V_8 = V_5 -> V_8 ;
int V_138 = 0 ;
F_43 ( & V_8 -> V_130 ) ;
if ( ! F_52 ( V_5 , V_21 , V_156 , V_157 ) )
V_138 = - V_168 ;
F_44 ( & V_8 -> V_130 ) ;
return V_138 ;
}
static void F_58 ( struct V_4 * V_5 , struct V_144 * V_21 ,
struct V_22 * V_23 , char * V_156 ,
int V_169 )
{
struct V_170 * V_171 = (struct V_170 * ) V_21 ;
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_52 * V_54 = V_23 -> V_54 ;
F_8 ( V_8 , (struct V_20 * ) V_171 ) ;
V_5 -> V_38 = F_9 ( V_171 -> V_172 ) + 1 ;
V_54 -> V_142 = ( V_173 << 16 ) | V_171 -> V_174 ;
if ( V_171 -> V_175 != V_176 ) {
V_54 -> V_142 = V_177 << 16 ;
goto V_178;
}
if ( V_171 -> V_174 == V_179 ) {
T_5 V_180 ;
if ( V_169 < 2 ) {
V_181:
F_27 ( V_159 , V_5 ,
L_27
L_28 , V_169 ) ;
V_54 -> V_142 = V_182 << 16 ;
goto V_178;
}
V_180 = F_59 ( V_156 ) ;
if ( V_169 < V_180 )
goto V_181;
memcpy ( V_54 -> V_183 , V_156 + 2 ,
F_60 ( T_5 , V_180 , V_184 ) ) ;
F_20 ( V_8 , L_29 ,
F_60 ( T_5 , V_180 ,
V_184 ) ) ;
}
if ( V_171 -> V_44 & ( V_185 |
V_186 ) ) {
int V_187 = F_9 ( V_171 -> V_188 ) ;
if ( F_31 ( V_54 ) && V_187 > 0 &&
( V_171 -> V_44 & V_186 ||
V_187 <= F_22 ( V_54 ) -> V_72 ) )
F_22 ( V_54 ) -> V_143 = V_187 ;
else
V_54 -> V_142 = ( V_182 << 16 ) | V_171 -> V_174 ;
}
if ( V_171 -> V_44 & ( V_189 |
V_190 ) ) {
int V_187 = F_9 ( V_171 -> V_191 ) ;
if ( V_187 > 0 &&
( V_171 -> V_44 & V_190 ||
V_187 <= F_35 ( V_54 ) ) )
F_50 ( V_54 , V_187 ) ;
else
V_54 -> V_142 = ( V_182 << 16 ) | V_171 -> V_174 ;
}
V_178:
F_20 ( V_8 , L_30 ,
V_54 , V_54 -> V_142 , V_23 -> V_36 ) ;
V_5 -> V_192 ++ ;
F_45 ( V_23 , V_131 ) ;
}
static void
F_61 ( struct V_4 * V_5 , struct V_144 * V_21 ,
struct V_22 * V_23 )
{
struct V_193 * V_171 = (struct V_193 * ) V_21 ;
struct V_52 * V_54 = V_23 -> V_54 ;
if ( ! ( V_171 -> V_44 & V_194 ) )
return;
F_8 ( V_5 -> V_8 , (struct V_20 * ) V_21 ) ;
V_54 -> V_142 = ( V_173 << 16 ) | V_171 -> V_174 ;
V_5 -> V_38 = F_9 ( V_171 -> V_172 ) + 1 ;
if ( V_171 -> V_44 & ( V_195 |
V_196 ) ) {
int V_187 = F_9 ( V_171 -> V_191 ) ;
if ( V_187 > 0 &&
( V_171 -> V_44 & V_190 ||
V_187 <= F_22 ( V_54 ) -> V_72 ) )
F_22 ( V_54 ) -> V_143 = V_187 ;
else
V_54 -> V_142 = ( V_182 << 16 ) | V_171 -> V_174 ;
}
F_20 ( V_5 -> V_8 , L_31
L_32 ,
V_54 , V_54 -> V_142 , V_23 -> V_36 ) ;
V_5 -> V_192 ++ ;
F_45 ( V_23 , V_131 ) ;
}
static void F_62 ( struct V_4 * V_5 , struct V_144 * V_21 )
{
struct V_197 * V_74 = (struct V_197 * ) V_21 ;
V_5 -> V_38 = F_9 ( V_21 -> V_172 ) + 1 ;
V_5 -> V_198 ++ ;
if ( V_5 -> V_77 != V_199 )
return;
if ( V_74 -> V_175 == V_200 )
V_5 -> V_77 = V_201 ;
else if ( V_74 -> V_175 == V_202 )
V_5 -> V_77 = V_203 ;
else
V_5 -> V_77 = V_204 ;
F_63 ( & V_5 -> V_205 ) ;
}
static void F_64 ( struct V_4 * V_5 , struct V_20 * V_171 )
{
struct V_145 V_21 ;
struct V_22 * V_23 ;
if ( ! V_171 && V_5 -> V_135 )
return;
memset ( & V_21 , 0 , sizeof( struct V_145 ) ) ;
V_21 . V_33 = V_206 | V_154 ;
V_21 . V_44 = V_45 ;
if ( V_171 ) {
memcpy ( V_21 . V_35 , V_171 -> V_35 , 8 ) ;
V_21 . V_31 = V_171 -> V_31 ;
V_21 . V_36 = V_151 ;
} else
V_21 . V_31 = V_151 ;
V_23 = F_52 ( V_5 , (struct V_144 * ) & V_21 , NULL , 0 ) ;
if ( ! V_23 )
F_27 ( V_159 , V_5 , L_33 ) ;
else if ( ! V_171 ) {
V_5 -> V_135 = V_23 ;
V_5 -> V_207 = V_137 ;
}
}
static int F_65 ( struct V_22 * V_23 ,
struct V_20 * V_146 , char * V_156 , int V_169 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
int V_60 = 0 ;
if ( V_5 -> V_135 != V_23 ) {
if ( F_66 ( V_5 -> V_166 , (struct V_144 * ) V_146 ,
V_156 , V_169 ) )
V_60 = V_208 ;
} else
F_67 ( & V_5 -> V_209 , V_137 + V_5 -> V_210 ) ;
F_45 ( V_23 , V_131 ) ;
return V_60 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_144 * V_21 ,
char * V_156 , int V_169 )
{
struct V_211 * V_212 = (struct V_211 * ) V_21 ;
struct V_144 V_213 ;
int V_33 , V_60 = 0 ;
V_5 -> V_38 = F_9 ( V_212 -> V_172 ) + 1 ;
if ( F_69 ( V_212 -> V_42 ) > V_169 ||
F_69 ( V_212 -> V_42 ) < sizeof( struct V_144 ) ) {
F_27 ( V_159 , V_5 , L_34
L_35
L_36 , F_69 ( V_212 -> V_42 ) ,
V_169 ) ;
return V_214 ;
}
memcpy ( & V_213 , V_156 , sizeof( struct V_144 ) ) ;
V_33 = V_213 . V_33 & V_79 ;
switch ( V_212 -> V_215 ) {
case V_216 :
F_27 ( V_159 , V_5 ,
L_37
L_38 ,
V_213 . V_36 , V_33 ) ;
break;
case V_217 :
F_27 ( V_159 , V_5 ,
L_39
L_40 ,
V_213 . V_36 , V_33 ) ;
if ( V_33 != V_206 )
return 0 ;
if ( V_213 . V_36 == F_11 ( V_109 ) )
F_64 ( V_5 ,
(struct V_20 * ) & V_213 ) ;
else {
struct V_22 * V_23 ;
V_23 = F_70 ( V_5 , V_213 . V_36 ) ;
if ( ! V_23 ) {
F_27 ( V_159 , V_5 ,
L_41
L_42 ) ;
V_60 = V_218 ;
} else
V_60 = F_65 ( V_23 ,
(struct V_20 * ) & V_213 ,
NULL , 0 ) ;
}
break;
default:
F_27 ( V_159 , V_5 ,
L_43
L_44 , V_213 . V_36 ,
V_213 . V_33 , V_212 -> V_215 ) ;
break;
}
return V_60 ;
}
struct V_22 * F_70 ( struct V_4 * V_5 , T_3 V_36 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
int V_219 ;
if ( V_36 == V_151 )
return NULL ;
if ( V_8 -> V_93 -> V_95 )
V_8 -> V_93 -> V_95 ( V_5 , V_36 , & V_219 , NULL ) ;
else
V_219 = F_71 ( V_36 ) ;
if ( V_219 >= V_8 -> V_220 )
return NULL ;
return V_8 -> V_221 [ V_219 ] ;
}
int F_72 ( struct V_4 * V_5 , struct V_144 * V_21 ,
char * V_156 , int V_169 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
int V_33 = V_21 -> V_33 & V_79 , V_60 = 0 ;
struct V_22 * V_23 ;
T_2 V_36 ;
V_5 -> V_136 = V_137 ;
V_60 = F_73 ( V_5 , V_21 -> V_36 ) ;
if ( V_60 )
return V_60 ;
if ( V_21 -> V_36 != V_151 )
V_36 = F_71 ( V_21 -> V_36 ) ;
else
V_36 = ~ 0U ;
F_20 ( V_8 , L_45 ,
V_33 , V_5 -> V_118 , V_36 , V_169 ) ;
if ( V_36 == ~ 0U ) {
F_8 ( V_8 , (struct V_20 * ) V_21 ) ;
switch( V_33 ) {
case V_222 :
if ( V_169 ) {
V_60 = V_214 ;
break;
}
if ( V_21 -> V_31 == F_11 ( V_109 ) )
break;
F_64 ( V_5 , (struct V_20 * ) V_21 ) ;
break;
case V_223 :
V_60 = F_68 ( V_5 , V_21 , V_156 , V_169 ) ;
break;
case V_224 :
V_5 -> V_38 = F_9 ( V_21 -> V_172 ) + 1 ;
if ( F_66 ( V_5 -> V_166 , V_21 , V_156 , V_169 ) )
V_60 = V_208 ;
break;
default:
V_60 = V_225 ;
break;
}
goto V_178;
}
switch( V_33 ) {
case V_226 :
case V_227 :
V_23 = F_74 ( V_5 , V_21 -> V_36 ) ;
if ( ! V_23 )
return V_218 ;
V_23 -> V_228 = V_137 ;
break;
case V_229 :
return 0 ;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_222 :
V_23 = F_70 ( V_5 , V_21 -> V_36 ) ;
if ( ! V_23 )
return V_218 ;
break;
default:
return V_225 ;
}
switch( V_33 ) {
case V_226 :
F_58 ( V_5 , V_21 , V_23 , V_156 , V_169 ) ;
break;
case V_227 :
F_61 ( V_5 , V_21 , V_23 ) ;
break;
case V_230 :
F_8 ( V_8 , (struct V_20 * ) V_21 ) ;
if ( V_169 ) {
V_60 = V_214 ;
break;
}
V_5 -> V_38 = F_9 ( V_21 -> V_172 ) + 1 ;
goto V_234;
case V_231 :
case V_232 :
F_8 ( V_8 , (struct V_20 * ) V_21 ) ;
goto V_234;
case V_233 :
F_8 ( V_8 , (struct V_20 * ) V_21 ) ;
if ( V_169 ) {
V_60 = V_214 ;
break;
}
F_62 ( V_5 , V_21 ) ;
F_45 ( V_23 , V_131 ) ;
break;
case V_222 :
F_8 ( V_8 , (struct V_20 * ) V_21 ) ;
if ( V_21 -> V_31 != F_11 ( V_109 ) || V_169 ) {
V_60 = V_214 ;
break;
}
V_5 -> V_38 = F_9 ( V_21 -> V_172 ) + 1 ;
V_60 = F_65 ( V_23 , (struct V_20 * ) V_21 ,
V_156 , V_169 ) ;
break;
default:
V_60 = V_225 ;
break;
}
V_178:
return V_60 ;
V_234:
if ( F_66 ( V_5 -> V_166 , V_21 , V_156 , V_169 ) )
V_60 = V_208 ;
F_45 ( V_23 , V_131 ) ;
return V_60 ;
}
int F_75 ( struct V_4 * V_5 , struct V_144 * V_21 ,
char * V_156 , int V_169 )
{
int V_60 ;
F_76 ( & V_5 -> V_8 -> V_130 ) ;
V_60 = F_72 ( V_5 , V_21 , V_156 , V_169 ) ;
F_77 ( & V_5 -> V_8 -> V_130 ) ;
return V_60 ;
}
int F_73 ( struct V_4 * V_5 , T_3 V_36 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
int V_96 = 0 , V_219 = 0 ;
if ( V_36 == V_151 )
return 0 ;
if ( V_8 -> V_93 -> V_95 )
V_8 -> V_93 -> V_95 ( V_5 , V_36 , & V_219 , & V_96 ) ;
else {
V_219 = F_71 ( V_36 ) ;
V_96 = ( ( V_235 T_1 ) V_36 >> V_236 ) & V_237 ;
}
if ( V_96 != V_8 -> V_96 ) {
F_27 ( V_159 , V_5 ,
L_46 ,
( V_235 T_1 ) V_36 , V_8 -> V_96 ) ;
return V_218 ;
}
if ( V_219 >= V_8 -> V_220 ) {
F_27 ( V_159 , V_5 ,
L_47
L_48 , V_219 , V_8 -> V_220 ) ;
return V_218 ;
}
return 0 ;
}
struct V_22 * F_74 ( struct V_4 * V_5 , T_3 V_36 )
{
struct V_22 * V_23 ;
if ( F_73 ( V_5 , V_36 ) )
return NULL ;
V_23 = F_70 ( V_5 , V_36 ) ;
if ( ! V_23 || ! V_23 -> V_54 )
return NULL ;
if ( V_23 -> V_54 -> V_125 . V_238 != V_5 -> V_8 -> V_96 ) {
F_78 ( V_159 , V_5 -> V_8 ,
L_49 ,
V_23 -> V_54 -> V_125 . V_238 , V_5 -> V_8 -> V_96 ) ;
return NULL ;
}
return V_23 ;
}
void F_79 ( struct V_14 * V_8 ,
enum V_239 V_138 )
{
struct V_4 * V_5 ;
struct V_83 * V_240 ;
F_43 ( & V_8 -> V_130 ) ;
V_5 = V_8 -> V_17 ;
if ( V_8 -> V_115 == V_158 || ! V_5 ) {
F_44 ( & V_8 -> V_130 ) ;
return;
}
V_240 = F_80 ( & V_5 -> V_166 -> V_240 ) ;
F_44 ( & V_8 -> V_130 ) ;
if ( ! V_240 )
return;
if ( V_138 == V_241 )
F_81 ( V_5 -> V_166 , V_138 ) ;
else
F_82 ( V_5 , V_138 ) ;
F_83 ( V_240 ) ;
}
void F_82 ( struct V_4 * V_5 , enum V_239 V_138 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 == V_242 ) {
F_44 ( & V_8 -> V_130 ) ;
return;
}
if ( V_5 -> V_243 == 0 )
V_8 -> V_115 = V_242 ;
F_44 ( & V_8 -> V_130 ) ;
F_84 ( V_244 , & V_5 -> V_245 ) ;
F_84 ( V_244 , & V_5 -> V_246 ) ;
F_81 ( V_5 -> V_166 , V_138 ) ;
}
static int F_85 ( struct V_4 * V_5 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
if ( ! F_2 ( V_8 -> V_140 , V_8 -> V_16 ) ) {
F_20 ( V_8 , L_50
L_51 ,
V_8 -> V_15 , V_8 -> V_16 ,
V_8 -> V_112 , V_8 -> V_140 ) ;
return - V_247 ;
}
return 0 ;
}
static int F_86 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
int V_60 ;
if ( F_87 ( V_244 , & V_5 -> V_245 ) )
return - V_248 ;
F_38 ( V_23 ) ;
F_44 ( & V_5 -> V_8 -> V_130 ) ;
V_60 = V_5 -> V_8 -> V_93 -> V_164 ( V_23 ) ;
F_43 ( & V_5 -> V_8 -> V_130 ) ;
if ( ! V_60 ) {
V_23 -> V_228 = V_137 ;
V_5 -> V_23 = NULL ;
}
F_40 ( V_23 ) ;
return V_60 ;
}
void F_88 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = V_23 -> V_5 ;
if ( F_7 ( & V_23 -> V_134 ) )
F_56 ( & V_23 -> V_134 , & V_5 -> V_249 ) ;
F_3 ( V_5 ) ;
}
static int F_89 ( struct V_4 * V_5 )
{
struct V_22 * V_23 ;
int V_60 = 0 ;
F_43 ( & V_5 -> V_8 -> V_130 ) ;
if ( F_87 ( V_244 , & V_5 -> V_245 ) ) {
F_20 ( V_5 -> V_8 , L_52 ) ;
F_44 ( & V_5 -> V_8 -> V_130 ) ;
return - V_248 ;
}
if ( V_5 -> V_23 ) {
V_60 = F_86 ( V_5 ) ;
if ( V_60 )
goto V_250;
}
V_251:
while ( ! F_7 ( & V_5 -> V_19 ) ) {
V_5 -> V_23 = F_90 ( V_5 -> V_19 . V_252 ,
struct V_22 , V_134 ) ;
F_47 ( & V_5 -> V_23 -> V_134 ) ;
if ( F_51 ( V_5 , V_5 -> V_23 ) ) {
F_40 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
continue;
}
V_60 = F_86 ( V_5 ) ;
if ( V_60 )
goto V_250;
}
while ( ! F_7 ( & V_5 -> V_18 ) ) {
V_5 -> V_23 = F_90 ( V_5 -> V_18 . V_252 , struct V_22 ,
V_134 ) ;
F_47 ( & V_5 -> V_23 -> V_134 ) ;
if ( V_5 -> V_8 -> V_115 == V_147 ) {
F_49 ( V_5 -> V_23 , V_253 ) ;
continue;
}
V_60 = F_28 ( V_5 -> V_23 ) ;
if ( V_60 ) {
if ( V_60 == - V_254 || V_60 == - V_86 ) {
F_56 ( & V_5 -> V_23 -> V_134 ,
& V_5 -> V_18 ) ;
V_5 -> V_23 = NULL ;
goto V_250;
} else
F_49 ( V_5 -> V_23 , V_255 ) ;
continue;
}
V_60 = F_86 ( V_5 ) ;
if ( V_60 )
goto V_250;
if ( ! F_7 ( & V_5 -> V_19 ) )
goto V_251;
}
while ( ! F_7 ( & V_5 -> V_249 ) ) {
if ( V_5 -> V_8 -> V_115 == V_147 )
break;
V_23 = F_90 ( V_5 -> V_249 . V_252 , struct V_22 ,
V_134 ) ;
if ( F_24 ( V_23 , V_34 ) )
break;
V_5 -> V_23 = V_23 ;
F_47 ( & V_5 -> V_23 -> V_134 ) ;
V_5 -> V_23 -> V_115 = V_116 ;
V_60 = F_86 ( V_5 ) ;
if ( V_60 )
goto V_250;
if ( ! F_7 ( & V_5 -> V_19 ) )
goto V_251;
}
F_44 ( & V_5 -> V_8 -> V_130 ) ;
return - V_248 ;
V_250:
F_44 ( & V_5 -> V_8 -> V_130 ) ;
return V_60 ;
}
static void F_91 ( struct V_256 * V_257 )
{
struct V_4 * V_5 =
F_92 ( V_257 , struct V_4 , V_13 ) ;
int V_60 ;
do {
V_60 = F_89 ( V_5 ) ;
} while ( V_60 >= 0 || V_60 == - V_258 );
}
static inline struct V_22 * F_93 ( struct V_4 * V_5 ,
struct V_52 * V_54 )
{
struct V_22 * V_23 ;
if ( ! F_53 ( & V_5 -> V_8 -> V_123 . V_124 ,
( void * ) & V_23 , sizeof( void * ) ) )
return NULL ;
V_54 -> V_125 . V_238 = V_5 -> V_8 -> V_96 ;
V_54 -> V_125 . V_126 = ( char * ) V_23 ;
F_54 ( & V_23 -> V_129 , 1 ) ;
V_23 -> V_115 = V_139 ;
V_23 -> V_5 = V_5 ;
V_23 -> V_54 = V_54 ;
V_23 -> V_259 = false ;
V_23 -> V_260 = V_137 ;
V_23 -> V_228 = V_137 ;
F_55 ( & V_23 -> V_134 ) ;
return V_23 ;
}
int F_94 ( struct V_6 * V_9 , struct V_52 * V_54 )
{
struct V_261 * V_262 ;
struct V_10 * V_11 ;
int V_215 = 0 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
struct V_22 * V_23 = NULL ;
V_54 -> V_142 = 0 ;
V_54 -> V_125 . V_126 = NULL ;
V_11 = F_4 ( V_9 ) ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
F_43 ( & V_8 -> V_130 ) ;
V_215 = F_97 ( V_262 ) ;
if ( V_215 ) {
V_54 -> V_142 = V_215 ;
goto V_263;
}
if ( V_8 -> V_115 != V_160 ) {
switch ( V_8 -> V_115 ) {
case V_242 :
case V_264 :
V_215 = V_265 ;
V_54 -> V_142 = V_253 << 16 ;
break;
case V_147 :
V_215 = V_266 ;
V_54 -> V_142 = V_253 << 16 ;
break;
case V_267 :
V_215 = V_268 ;
V_54 -> V_142 = V_269 << 16 ;
break;
case V_158 :
V_215 = V_270 ;
V_54 -> V_142 = V_271 << 16 ;
break;
default:
V_215 = V_272 ;
V_54 -> V_142 = V_271 << 16 ;
}
goto V_263;
}
V_5 = V_8 -> V_17 ;
if ( ! V_5 ) {
V_215 = V_272 ;
V_54 -> V_142 = V_271 << 16 ;
goto V_263;
}
if ( F_87 ( V_244 , & V_5 -> V_245 ) ) {
V_215 = V_265 ;
V_54 -> V_142 = V_273 ;
goto V_263;
}
if ( F_85 ( V_5 ) ) {
V_215 = V_274 ;
goto V_212;
}
V_23 = F_93 ( V_5 , V_54 ) ;
if ( ! V_23 ) {
V_215 = V_275 ;
goto V_212;
}
if ( ! V_11 -> V_12 ) {
V_215 = F_28 ( V_23 ) ;
if ( V_215 ) {
if ( V_215 == - V_254 || V_215 == - V_86 ) {
V_215 = V_275 ;
goto V_276;
} else {
V_54 -> V_142 = V_255 << 16 ;
goto V_277;
}
}
if ( V_8 -> V_93 -> V_164 ( V_23 ) ) {
V_8 -> V_112 -- ;
V_215 = V_278 ;
goto V_276;
}
} else {
F_56 ( & V_23 -> V_134 , & V_5 -> V_18 ) ;
F_3 ( V_5 ) ;
}
V_8 -> V_140 ++ ;
F_44 ( & V_8 -> V_130 ) ;
return 0 ;
V_276:
F_45 ( V_23 , V_127 ) ;
V_212:
F_44 ( & V_8 -> V_130 ) ;
F_20 ( V_8 , L_53 ,
V_54 -> V_67 [ 0 ] , V_215 ) ;
return V_279 ;
V_277:
F_45 ( V_23 , V_127 ) ;
V_263:
F_44 ( & V_8 -> V_130 ) ;
F_20 ( V_8 , L_54 ,
V_54 -> V_67 [ 0 ] , V_215 ) ;
if ( ! F_31 ( V_54 ) )
F_50 ( V_54 , F_35 ( V_54 ) ) ;
else {
F_32 ( V_54 ) -> V_143 = F_32 ( V_54 ) -> V_72 ;
F_22 ( V_54 ) -> V_143 = F_22 ( V_54 ) -> V_72 ;
}
V_54 -> V_128 ( V_54 ) ;
return 0 ;
}
int F_98 ( struct V_280 * V_281 , int V_282 , int V_215 )
{
switch ( V_215 ) {
case V_283 :
F_99 ( V_281 , F_100 ( V_281 ) , V_282 ) ;
break;
case V_284 :
F_101 ( V_281 , V_282 ) ;
break;
case V_285 :
F_99 ( V_281 , F_100 ( V_281 ) , V_282 ) ;
break;
default:
return - V_286 ;
}
return V_281 -> V_287 ;
}
int F_102 ( struct F_96 * V_288 )
{
struct V_261 * V_262 = F_95 ( V_288 ) ;
struct V_14 * V_8 = V_262 -> V_167 ;
V_288 -> V_289 = V_8 -> V_290 ;
return 0 ;
}
static void F_103 ( unsigned long V_156 )
{
struct V_4 * V_5 = (struct V_4 * ) V_156 ;
struct V_14 * V_8 = V_5 -> V_8 ;
F_76 ( & V_8 -> V_130 ) ;
if ( V_5 -> V_77 == V_199 ) {
V_5 -> V_77 = V_291 ;
F_104 ( V_8 , L_55 ) ;
F_63 ( & V_5 -> V_205 ) ;
}
F_77 ( & V_8 -> V_130 ) ;
}
static int F_105 ( struct V_4 * V_5 ,
struct V_73 * V_21 , int V_96 ,
int V_292 )
{
struct V_14 * V_8 = V_5 -> V_8 ;
struct V_22 * V_23 ;
V_23 = F_52 ( V_5 , (struct V_144 * ) V_21 ,
NULL , 0 ) ;
if ( ! V_23 ) {
F_44 ( & V_8 -> V_130 ) ;
F_27 ( V_159 , V_5 , L_56 ) ;
F_82 ( V_5 , V_208 ) ;
F_43 ( & V_8 -> V_130 ) ;
return - V_168 ;
}
V_5 -> V_293 ++ ;
V_5 -> V_294 . V_295 = V_292 * V_296 + V_137 ;
V_5 -> V_294 . V_297 = F_103 ;
V_5 -> V_294 . V_156 = ( unsigned long ) V_5 ;
F_106 ( & V_5 -> V_294 ) ;
F_104 ( V_8 , L_57 ) ;
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
F_108 ( V_5 -> V_205 , V_96 != V_8 -> V_96 ||
V_8 -> V_115 != V_160 ||
V_5 -> V_77 != V_199 ) ;
if ( F_109 ( V_299 ) )
F_110 ( V_299 ) ;
F_111 ( & V_5 -> V_294 ) ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_96 != V_8 -> V_96 ||
V_8 -> V_115 != V_160 )
return - V_148 ;
return 0 ;
}
static void F_113 ( struct V_4 * V_5 , unsigned V_35 ,
int error )
{
struct V_22 * V_23 ;
int V_219 ;
for ( V_219 = 0 ; V_219 < V_5 -> V_8 -> V_220 ; V_219 ++ ) {
V_23 = V_5 -> V_8 -> V_221 [ V_219 ] ;
if ( ! V_23 -> V_54 || V_23 -> V_115 == V_121 )
continue;
if ( V_35 != - 1 && V_35 != V_23 -> V_54 -> V_83 -> V_35 )
continue;
F_20 ( V_5 -> V_8 ,
L_58 ,
V_23 -> V_54 , V_23 -> V_36 , V_23 -> V_115 ) ;
F_49 ( V_23 , error ) ;
}
}
void F_114 ( struct V_4 * V_5 )
{
F_43 ( & V_5 -> V_8 -> V_130 ) ;
F_84 ( V_244 , & V_5 -> V_245 ) ;
F_44 ( & V_5 -> V_8 -> V_130 ) ;
}
void F_115 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_84 ( V_244 , & V_5 -> V_245 ) ;
if ( V_11 -> V_12 )
F_116 ( V_11 -> V_12 ) ;
}
static void F_117 ( struct V_4 * V_5 )
{
F_118 ( V_244 , & V_5 -> V_245 ) ;
F_3 ( V_5 ) ;
}
static int F_119 ( struct V_4 * V_5 )
{
if ( V_5 -> V_135 &&
F_120 ( V_5 -> V_136 + ( V_5 -> V_210 * V_296 ) +
( V_5 -> V_300 * V_296 ) , V_137 ) )
return 1 ;
else
return 0 ;
}
static enum V_301 F_121 ( struct V_52 * V_54 )
{
enum V_301 V_60 = V_302 ;
struct V_22 * V_23 = NULL , * V_303 ;
struct V_261 * V_262 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
int V_219 ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
F_104 ( V_8 , L_59 , V_54 ) ;
F_76 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 != V_160 ) {
V_60 = V_304 ;
goto V_250;
}
V_5 = V_8 -> V_17 ;
if ( ! V_5 ) {
V_60 = V_304 ;
goto V_250;
}
V_23 = (struct V_22 * ) V_54 -> V_125 . V_126 ;
if ( ! V_23 ) {
V_60 = V_304 ;
goto V_250;
}
if ( F_122 ( V_23 -> V_228 , V_23 -> V_260 ) ) {
F_104 ( V_8 , L_60
L_61
L_62
L_63 , V_23 -> V_228 , V_23 -> V_260 ) ;
V_23 -> V_259 = false ;
V_60 = V_304 ;
goto V_250;
}
if ( ! V_5 -> V_210 && ! V_5 -> V_300 )
goto V_250;
if ( F_119 ( V_5 ) ) {
V_60 = V_304 ;
goto V_250;
}
for ( V_219 = 0 ; V_219 < V_5 -> V_8 -> V_220 ; V_219 ++ ) {
V_303 = V_5 -> V_8 -> V_221 [ V_219 ] ;
if ( ! V_303 -> V_54 || V_303 == V_23 ||
V_303 -> V_115 != V_116 )
continue;
if ( F_122 ( V_303 -> V_54 -> V_305 ,
V_23 -> V_54 -> V_305 ) )
continue;
if ( F_122 ( V_303 -> V_228 , V_23 -> V_260 ) ) {
F_104 ( V_8 , L_64
L_65
L_66
L_67
L_68 ,
V_23 -> V_228 , V_303 -> V_228 ,
V_23 -> V_260 ) ;
V_60 = V_304 ;
goto V_250;
}
}
if ( V_23 -> V_259 )
goto V_250;
if ( V_5 -> V_135 ) {
V_23 -> V_259 = true ;
V_60 = V_304 ;
goto V_250;
}
F_64 ( V_5 , NULL ) ;
V_23 -> V_259 = true ;
V_60 = V_304 ;
V_250:
if ( V_23 )
V_23 -> V_260 = V_137 ;
F_77 ( & V_8 -> V_130 ) ;
F_104 ( V_8 , L_69 , V_60 == V_304 ?
L_70 : L_71 ) ;
return V_60 ;
}
static void F_123 ( unsigned long V_156 )
{
struct V_4 * V_5 = (struct V_4 * ) V_156 ;
struct V_14 * V_8 = V_5 -> V_8 ;
unsigned long V_210 , V_306 = 0 , V_136 ;
F_76 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 != V_160 )
goto V_250;
V_210 = V_5 -> V_210 ;
if ( ! V_210 )
goto V_250;
V_210 *= V_296 ;
V_136 = V_5 -> V_136 ;
if ( F_119 ( V_5 ) ) {
F_27 ( V_159 , V_5 , L_72
L_73
L_74 ,
V_5 -> V_300 , V_5 -> V_210 ,
V_136 , V_5 -> V_207 , V_137 ) ;
F_77 ( & V_8 -> V_130 ) ;
F_82 ( V_5 , V_208 ) ;
return;
}
if ( F_120 ( V_136 + V_210 , V_137 ) ) {
F_124 ( V_5 , L_75 ) ;
F_64 ( V_5 , NULL ) ;
V_306 = V_5 -> V_207 + ( V_5 -> V_300 * V_296 ) ;
} else
V_306 = V_136 + V_210 ;
F_124 ( V_5 , L_76 , V_306 ) ;
F_67 ( & V_5 -> V_209 , V_306 ) ;
V_250:
F_77 ( & V_8 -> V_130 ) ;
}
static void F_125 ( struct V_22 * V_23 ,
struct V_73 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_33 = V_80 | V_154 ;
V_21 -> V_44 = V_88 & V_307 ;
V_21 -> V_44 |= V_45 ;
memcpy ( V_21 -> V_35 , V_23 -> V_35 , sizeof( V_21 -> V_35 ) ) ;
V_21 -> V_89 = V_23 -> V_37 ;
V_21 -> V_308 = V_23 -> V_112 ;
}
int F_126 ( struct V_52 * V_54 )
{
struct V_261 * V_262 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
struct V_73 * V_21 ;
int V_60 , V_96 ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
F_104 ( V_8 , L_77 , V_54 ) ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( ! V_54 -> V_125 . V_126 ) {
F_104 ( V_8 , L_78
L_79 ) ;
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_309 ;
}
if ( ! V_8 -> V_17 || V_8 -> V_115 != V_160 ||
V_54 -> V_125 . V_238 != V_8 -> V_96 ) {
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
F_104 ( V_8 , L_80
L_81 ) ;
return V_310 ;
}
V_5 = V_8 -> V_17 ;
V_5 -> V_311 ++ ;
V_96 = V_8 -> V_96 ;
V_23 = (struct V_22 * ) V_54 -> V_125 . V_126 ;
F_104 ( V_8 , L_82 ,
V_54 , V_23 -> V_36 ) ;
if ( ! V_23 -> V_54 ) {
F_104 ( V_8 , L_83 ) ;
goto V_312;
}
if ( V_23 -> V_115 == V_139 ) {
F_49 ( V_23 , V_255 ) ;
goto V_312;
}
if ( V_5 -> V_77 != V_78 )
goto V_313;
V_5 -> V_77 = V_199 ;
V_21 = & V_5 -> V_75 ;
F_125 ( V_23 , V_21 ) ;
if ( F_105 ( V_5 , V_21 , V_96 , V_8 -> V_314 ) ) {
V_60 = V_310 ;
goto V_313;
}
switch ( V_5 -> V_77 ) {
case V_201 :
F_44 ( & V_8 -> V_130 ) ;
F_115 ( V_5 ) ;
F_43 ( & V_8 -> V_130 ) ;
F_49 ( V_23 , V_255 ) ;
V_5 -> V_77 = V_78 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
F_44 ( & V_8 -> V_130 ) ;
F_117 ( V_5 ) ;
goto V_315;
case V_291 :
F_44 ( & V_8 -> V_130 ) ;
F_82 ( V_5 , V_316 ) ;
goto V_317;
case V_203 :
if ( ! V_54 -> V_125 . V_126 ) {
V_5 -> V_77 = V_78 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
F_104 ( V_8 , L_84
L_12 ) ;
goto V_312;
}
default:
V_5 -> V_77 = V_78 ;
goto V_313;
}
V_312:
F_44 ( & V_8 -> V_130 ) ;
V_315:
F_104 ( V_8 , L_85 ,
V_54 , V_23 -> V_36 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_309 ;
V_313:
F_44 ( & V_8 -> V_130 ) ;
V_317:
F_104 ( V_8 , L_86 , V_54 ,
V_23 ? V_23 -> V_36 : 0 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_310 ;
}
static void F_127 ( struct V_52 * V_54 , struct V_73 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_33 = V_80 | V_154 ;
V_21 -> V_44 = V_81 & V_307 ;
V_21 -> V_44 |= V_45 ;
F_30 ( V_54 -> V_83 -> V_35 , (struct V_82 * ) V_21 -> V_35 ) ;
V_21 -> V_89 = V_151 ;
}
int F_128 ( struct V_52 * V_54 )
{
struct V_261 * V_262 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
struct V_73 * V_21 ;
int V_60 = V_310 ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
F_104 ( V_8 , L_87 , V_54 , V_54 -> V_83 -> V_35 ) ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( ! V_8 -> V_17 || V_8 -> V_115 != V_160 )
goto V_318;
V_5 = V_8 -> V_17 ;
if ( V_5 -> V_77 != V_78 )
goto V_318;
V_5 -> V_77 = V_199 ;
V_21 = & V_5 -> V_75 ;
F_127 ( V_54 , V_21 ) ;
if ( F_105 ( V_5 , V_21 , V_8 -> V_96 ,
V_8 -> V_319 ) ) {
V_60 = V_310 ;
goto V_318;
}
switch ( V_5 -> V_77 ) {
case V_201 :
break;
case V_291 :
F_44 ( & V_8 -> V_130 ) ;
F_82 ( V_5 , V_316 ) ;
goto V_250;
default:
V_5 -> V_77 = V_78 ;
goto V_318;
}
V_60 = V_309 ;
F_44 ( & V_8 -> V_130 ) ;
F_115 ( V_5 ) ;
F_43 ( & V_8 -> V_130 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
F_113 ( V_5 , V_54 -> V_83 -> V_35 , V_177 ) ;
V_5 -> V_77 = V_78 ;
F_44 ( & V_8 -> V_130 ) ;
F_117 ( V_5 ) ;
goto V_250;
V_318:
F_44 ( & V_8 -> V_130 ) ;
V_250:
F_104 ( V_8 , L_88 ,
V_60 == V_309 ? L_89 : L_90 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_60 ;
}
void F_129 ( struct V_261 * V_262 )
{
struct V_14 * V_8 = V_262 -> V_167 ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 != V_160 ) {
V_8 -> V_115 = V_267 ;
if ( V_8 -> V_17 )
F_63 ( & V_8 -> V_17 -> V_205 ) ;
}
F_44 ( & V_8 -> V_130 ) ;
}
int F_130 ( struct V_52 * V_54 )
{
struct V_261 * V_262 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
V_5 = V_8 -> V_17 ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 == V_158 ) {
V_313:
F_104 ( V_8 ,
L_91
L_92 , V_8 -> V_320 ,
V_5 -> V_321 , V_8 -> V_96 ) ;
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_310 ;
}
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
F_82 ( V_5 , V_316 ) ;
F_104 ( V_8 , L_93 ) ;
F_108 ( V_5 -> V_205 ,
V_8 -> V_115 == V_158 ||
V_8 -> V_115 == V_160 ||
V_8 -> V_115 == V_267 ) ;
if ( F_109 ( V_299 ) )
F_110 ( V_299 ) ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_8 -> V_115 == V_160 ) {
F_104 ( V_8 ,
L_94 ,
V_8 -> V_320 , V_5 -> V_321 ) ;
} else
goto V_313;
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_309 ;
}
static void F_131 ( struct V_52 * V_54 , struct V_73 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_33 = V_80 | V_154 ;
V_21 -> V_44 = V_84 & V_307 ;
V_21 -> V_44 |= V_45 ;
V_21 -> V_89 = V_151 ;
}
int F_132 ( struct V_52 * V_54 )
{
struct V_261 * V_262 ;
struct V_14 * V_8 ;
struct V_4 * V_5 ;
struct V_73 * V_21 ;
int V_60 = V_310 ;
V_262 = F_95 ( F_96 ( V_54 -> V_83 ) ) ;
V_8 = V_262 -> V_167 ;
F_104 ( V_8 , L_95 , V_54 ,
V_8 -> V_320 ) ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( ! V_8 -> V_17 || V_8 -> V_115 != V_160 )
goto V_318;
V_5 = V_8 -> V_17 ;
if ( V_5 -> V_77 != V_78 )
goto V_318;
V_5 -> V_77 = V_199 ;
V_21 = & V_5 -> V_75 ;
F_131 ( V_54 , V_21 ) ;
if ( F_105 ( V_5 , V_21 , V_8 -> V_96 ,
V_8 -> V_322 ) ) {
V_60 = V_310 ;
goto V_318;
}
switch ( V_5 -> V_77 ) {
case V_201 :
break;
case V_291 :
F_44 ( & V_8 -> V_130 ) ;
F_82 ( V_5 , V_316 ) ;
goto V_250;
default:
V_5 -> V_77 = V_78 ;
goto V_318;
}
V_60 = V_309 ;
F_44 ( & V_8 -> V_130 ) ;
F_115 ( V_5 ) ;
F_43 ( & V_8 -> V_130 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
F_113 ( V_5 , - 1 , V_177 ) ;
V_5 -> V_77 = V_78 ;
F_44 ( & V_8 -> V_130 ) ;
F_117 ( V_5 ) ;
goto V_250;
V_318:
F_44 ( & V_8 -> V_130 ) ;
V_250:
F_104 ( V_8 , L_96 , V_8 -> V_320 ,
V_60 == V_309 ? L_89 : L_90 ) ;
F_107 ( & V_8 -> V_298 ) ;
return V_60 ;
}
int F_133 ( struct V_52 * V_54 )
{
int V_60 ;
V_60 = F_132 ( V_54 ) ;
if ( V_60 == V_310 )
V_60 = F_130 ( V_54 ) ;
return V_60 ;
}
int
F_134 ( struct V_323 * V_324 , int V_325 , void * * * V_326 , int V_327 )
{
int V_219 , V_328 = 1 ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
V_324 -> V_325 = V_325 ;
if ( V_326 )
V_328 ++ ;
V_324 -> V_329 = F_135 ( V_328 * V_325 * sizeof( void * ) , V_330 ) ;
if ( V_324 -> V_329 == NULL )
return - V_254 ;
F_136 ( & V_324 -> V_124 , ( void * ) V_324 -> V_329 , V_325 * sizeof( void * ) ) ;
for ( V_219 = 0 ; V_219 < V_325 ; V_219 ++ ) {
V_324 -> V_329 [ V_219 ] = F_135 ( V_327 , V_330 ) ;
if ( V_324 -> V_329 [ V_219 ] == NULL ) {
V_324 -> V_325 = V_219 ;
goto V_331;
}
F_37 ( & V_324 -> V_124 , ( void * ) & V_324 -> V_329 [ V_219 ] , sizeof( void * ) ) ;
}
if ( V_326 ) {
* V_326 = V_324 -> V_329 + V_325 ;
memcpy ( * V_326 , V_324 -> V_329 , V_325 * sizeof( void * ) ) ;
}
return 0 ;
V_331:
F_137 ( V_324 ) ;
return - V_254 ;
}
void F_137 ( struct V_323 * V_324 )
{
int V_219 ;
for ( V_219 = 0 ; V_219 < V_324 -> V_325 ; V_219 ++ )
F_138 ( V_324 -> V_329 [ V_219 ] ) ;
F_138 ( V_324 -> V_329 ) ;
}
int F_139 ( struct V_6 * V_7 , struct V_83 * V_332 )
{
if ( ! V_7 -> V_289 )
V_7 -> V_289 = V_333 ;
if ( ! V_7 -> V_334 )
V_7 -> V_334 = V_335 ;
if ( ! V_7 -> V_336 -> V_337 )
V_7 -> V_336 -> V_337 = F_121 ;
return F_140 ( V_7 , V_332 ) ;
}
struct V_6 * F_141 ( struct V_338 * V_339 ,
int V_340 , bool V_341 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
V_7 = F_142 ( V_339 , sizeof( struct V_10 ) + V_340 ) ;
if ( ! V_7 )
return NULL ;
V_11 = F_4 ( V_7 ) ;
if ( V_341 ) {
snprintf ( V_11 -> V_342 , sizeof( V_11 -> V_342 ) ,
L_97 , V_7 -> V_343 ) ;
V_11 -> V_12 = F_143 ( V_11 -> V_342 ) ;
if ( ! V_11 -> V_12 )
goto V_344;
}
F_144 ( & V_11 -> V_130 ) ;
V_11 -> V_115 = V_345 ;
V_11 -> V_346 = 0 ;
F_145 ( & V_11 -> V_347 ) ;
return V_7 ;
V_344:
F_146 ( V_7 ) ;
return NULL ;
}
static void F_147 ( struct V_261 * V_262 )
{
F_79 ( V_262 -> V_167 , V_241 ) ;
}
void F_148 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_44 ;
F_149 ( & V_11 -> V_130 , V_44 ) ;
V_11 -> V_115 = V_348 ;
F_150 ( & V_11 -> V_130 , V_44 ) ;
F_151 ( V_7 , F_147 ) ;
F_108 ( V_11 -> V_347 ,
V_11 -> V_346 == 0 ) ;
if ( F_109 ( V_299 ) )
F_110 ( V_299 ) ;
F_152 ( V_7 ) ;
if ( V_11 -> V_12 )
F_153 ( V_11 -> V_12 ) ;
}
void F_154 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_138 ( V_11 -> V_349 ) ;
F_138 ( V_11 -> V_350 ) ;
F_138 ( V_11 -> V_351 ) ;
F_146 ( V_7 ) ;
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_44 ;
V_7 = F_156 ( V_7 ) ;
if ( ! V_7 ) {
F_157 ( V_159 L_98
L_99
L_100 ) ;
return;
}
F_149 ( & V_11 -> V_130 , V_44 ) ;
V_11 -> V_346 -- ;
if ( V_11 -> V_346 == 0 )
F_63 ( & V_11 -> V_347 ) ;
F_150 ( & V_11 -> V_130 , V_44 ) ;
F_146 ( V_7 ) ;
}
struct V_261 *
F_158 ( struct V_352 * V_353 , struct V_6 * V_7 ,
T_5 V_220 , int V_354 , int V_355 ,
T_2 V_356 , unsigned int V_118 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_14 * V_8 ;
struct V_261 * V_262 ;
int V_357 , V_358 , V_359 = V_220 ;
unsigned long V_44 ;
F_149 ( & V_11 -> V_130 , V_44 ) ;
if ( V_11 -> V_115 == V_348 ) {
F_150 ( & V_11 -> V_130 , V_44 ) ;
return NULL ;
}
V_11 -> V_346 ++ ;
F_150 ( & V_11 -> V_130 , V_44 ) ;
if ( ! V_359 )
V_359 = V_333 ;
if ( V_359 < V_360 ) {
F_157 ( V_159 L_101
L_102 ,
V_359 , V_360 ) ;
goto V_361;
}
if ( V_359 > V_362 ) {
F_157 ( V_159 L_101
L_103 ,
V_220 , V_362 ) ;
V_359 = V_362 ;
}
if ( ! F_159 ( V_359 ) ) {
F_157 ( V_159 L_101
L_104 , V_359 ) ;
V_359 = F_160 ( V_359 ) ;
if ( V_359 < V_360 )
return NULL ;
F_157 ( V_85 L_105 ,
V_359 ) ;
}
V_358 = V_359 - V_363 ;
V_262 = F_161 ( V_7 , V_353 ,
sizeof( struct V_14 ) +
V_354 ) ;
if ( ! V_262 )
goto V_361;
V_8 = V_262 -> V_167 ;
V_8 -> V_262 = V_262 ;
V_8 -> V_9 = V_7 ;
V_8 -> V_115 = V_364 ;
V_8 -> V_87 = 1 ;
V_8 -> V_322 = 30 ;
V_8 -> V_319 = 15 ;
V_8 -> V_314 = 10 ;
V_8 -> V_290 = V_358 ;
V_8 -> V_220 = V_359 ;
V_8 -> V_140 = V_8 -> V_112 = V_356 ;
V_8 -> V_15 = V_356 + 1 ;
V_8 -> V_16 = V_356 + 1 ;
V_8 -> V_365 = 1 ;
V_8 -> V_93 = V_353 ;
V_8 -> V_167 = V_262 -> V_167 + sizeof( * V_8 ) ;
F_162 ( & V_8 -> V_298 ) ;
F_144 ( & V_8 -> V_130 ) ;
if ( F_134 ( & V_8 -> V_123 , V_8 -> V_220 ,
( void * * * ) & V_8 -> V_221 ,
V_355 + sizeof( struct V_22 ) ) )
goto V_366;
for ( V_357 = 0 ; V_357 < V_8 -> V_220 ; V_357 ++ ) {
struct V_22 * V_23 = V_8 -> V_221 [ V_357 ] ;
if ( V_355 )
V_23 -> V_167 = & V_23 [ 1 ] ;
V_23 -> V_36 = V_357 ;
V_23 -> V_115 = V_121 ;
F_55 ( & V_23 -> V_134 ) ;
}
if ( ! F_163 ( V_353 -> V_367 ) )
goto V_368;
if ( F_164 ( V_262 , V_118 ) )
goto V_369;
return V_262 ;
V_369:
F_165 ( V_353 -> V_367 ) ;
V_368:
F_137 ( & V_8 -> V_123 ) ;
V_366:
F_166 ( V_262 ) ;
V_361:
F_155 ( V_7 ) ;
return NULL ;
}
void F_167 ( struct V_261 * V_262 )
{
struct V_14 * V_8 = V_262 -> V_167 ;
struct V_370 * V_367 = V_262 -> V_371 -> V_367 ;
struct V_6 * V_7 = V_8 -> V_9 ;
F_137 ( & V_8 -> V_123 ) ;
F_138 ( V_8 -> V_372 ) ;
F_138 ( V_8 -> V_373 ) ;
F_138 ( V_8 -> V_374 ) ;
F_138 ( V_8 -> V_375 ) ;
F_138 ( V_8 -> V_320 ) ;
F_138 ( V_8 -> V_351 ) ;
F_138 ( V_8 -> V_376 ) ;
F_168 ( V_262 ) ;
F_155 ( V_7 ) ;
F_165 ( V_367 ) ;
}
struct V_165 *
F_169 ( struct V_261 * V_262 , int V_354 ,
T_2 V_377 )
{
struct V_14 * V_8 = V_262 -> V_167 ;
struct V_4 * V_5 ;
struct V_165 * V_166 ;
char * V_156 ;
V_166 = F_170 ( V_262 , sizeof( * V_5 ) + V_354 ,
V_377 ) ;
if ( ! V_166 )
return NULL ;
V_5 = V_166 -> V_167 ;
memset ( V_5 , 0 , sizeof( * V_5 ) + V_354 ) ;
V_5 -> V_167 = V_166 -> V_167 + sizeof( * V_5 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_166 = V_166 ;
V_5 -> V_152 = V_161 ;
V_5 -> V_118 = V_377 ;
V_5 -> V_38 = 0 ;
V_5 -> V_77 = V_78 ;
F_171 ( & V_5 -> V_209 ) ;
V_5 -> V_209 . V_156 = ( unsigned long ) V_5 ;
V_5 -> V_209 . V_297 = F_123 ;
F_55 ( & V_5 -> V_19 ) ;
F_55 ( & V_5 -> V_18 ) ;
F_55 ( & V_5 -> V_249 ) ;
F_172 ( & V_5 -> V_13 , F_91 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( ! F_53 ( & V_8 -> V_123 . V_124 ,
( void * ) & V_5 -> V_122 ,
sizeof( void * ) ) ) {
F_44 ( & V_8 -> V_130 ) ;
goto V_378;
}
F_44 ( & V_8 -> V_130 ) ;
V_156 = ( char * ) F_173 ( V_330 ,
F_174 ( V_379 ) ) ;
if ( ! V_156 )
goto V_380;
V_5 -> V_122 -> V_156 = V_5 -> V_156 = V_156 ;
F_171 ( & V_5 -> V_294 ) ;
F_145 ( & V_5 -> V_205 ) ;
return V_166 ;
V_380:
F_37 ( & V_8 -> V_123 . V_124 , ( void * ) & V_5 -> V_122 ,
sizeof( void * ) ) ;
V_378:
F_175 ( V_166 ) ;
return NULL ;
}
void F_176 ( struct V_165 * V_166 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
struct V_14 * V_8 = V_5 -> V_8 ;
unsigned long V_44 ;
F_111 ( & V_5 -> V_209 ) ;
F_43 ( & V_8 -> V_130 ) ;
V_5 -> V_152 = V_381 ;
if ( V_8 -> V_17 == V_5 ) {
V_8 -> V_115 = V_158 ;
F_63 ( & V_5 -> V_205 ) ;
}
F_44 ( & V_8 -> V_130 ) ;
for (; ; ) {
F_149 ( V_8 -> V_9 -> V_382 , V_44 ) ;
if ( ! V_8 -> V_9 -> V_383 ) {
F_150 ( V_8 -> V_9 -> V_382 , V_44 ) ;
break;
}
F_150 ( V_8 -> V_9 -> V_382 , V_44 ) ;
F_177 ( 500 ) ;
F_27 ( V_85 , V_5 , L_106
L_107 ,
V_8 -> V_9 -> V_383 ,
V_8 -> V_9 -> V_384 ) ;
F_63 ( & V_5 -> V_205 ) ;
}
F_115 ( V_5 ) ;
F_43 ( & V_8 -> V_130 ) ;
F_178 ( ( unsigned long ) V_5 -> V_156 ,
F_174 ( V_379 ) ) ;
F_138 ( V_5 -> V_321 ) ;
F_37 ( & V_8 -> V_123 . V_124 , ( void * ) & V_5 -> V_122 ,
sizeof( void * ) ) ;
if ( V_8 -> V_17 == V_5 )
V_8 -> V_17 = NULL ;
F_44 ( & V_8 -> V_130 ) ;
F_175 ( V_166 ) ;
}
int F_179 ( struct V_165 * V_166 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
struct V_14 * V_8 = V_5 -> V_8 ;
if ( ! V_8 ) {
F_27 ( V_159 , V_5 ,
L_108 ) ;
return - V_168 ;
}
if ( ( V_8 -> V_106 || ! V_8 -> V_108 ) &&
V_8 -> V_107 > V_8 -> V_385 ) {
F_27 ( V_85 , V_5 , L_109
L_110 ,
V_8 -> V_107 , V_8 -> V_385 ) ;
return - V_50 ;
}
if ( V_5 -> V_300 && ! V_5 -> V_210 ) {
F_27 ( V_159 , V_5 , L_111
L_112 ) ;
V_5 -> V_210 = 5 ;
}
if ( V_5 -> V_210 && ! V_5 -> V_300 ) {
F_27 ( V_159 , V_5 , L_113
L_114 ) ;
V_5 -> V_300 = 5 ;
}
F_43 ( & V_8 -> V_130 ) ;
V_5 -> V_152 = V_153 ;
V_8 -> V_115 = V_160 ;
V_8 -> V_140 = V_8 -> V_112 ;
V_5 -> V_136 = V_137 ;
V_5 -> V_207 = V_137 ;
if ( V_5 -> V_210 && V_5 -> V_300 )
F_67 ( & V_5 -> V_209 ,
V_137 + ( V_5 -> V_210 * V_296 ) ) ;
switch( V_5 -> V_243 ) {
case V_386 :
V_5 -> V_243 = 0 ;
V_5 -> V_77 = V_78 ;
V_8 -> V_96 ++ ;
if ( V_8 -> V_96 == 16 )
V_8 -> V_96 = 0 ;
break;
case V_387 :
V_5 -> V_243 = 0 ;
break;
default:
break;
}
F_44 ( & V_8 -> V_130 ) ;
F_180 ( V_8 -> V_262 ) ;
F_63 ( & V_5 -> V_205 ) ;
return 0 ;
}
static void
F_181 ( struct V_14 * V_8 , struct V_4 * V_5 )
{
struct V_22 * V_23 ;
int V_219 , V_115 ;
for ( V_219 = 0 ; V_219 < V_5 -> V_8 -> V_220 ; V_219 ++ ) {
V_23 = V_5 -> V_8 -> V_221 [ V_219 ] ;
if ( V_23 -> V_54 )
continue;
if ( V_23 -> V_115 == V_121 )
continue;
F_20 ( V_5 -> V_8 ,
L_115 ,
V_23 -> V_36 , V_23 -> V_115 ) ;
V_115 = V_133 ;
if ( V_23 -> V_115 == V_139 )
V_115 = V_131 ;
F_45 ( V_23 , V_115 ) ;
}
}
static void F_182 ( struct V_14 * V_8 ,
struct V_4 * V_5 , int V_388 )
{
int V_389 ;
F_112 ( & V_8 -> V_298 ) ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_5 -> V_243 == V_387 ) {
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
return;
}
if ( V_388 == V_387 )
V_8 -> V_115 = V_158 ;
else if ( V_5 -> V_243 != V_386 )
V_8 -> V_115 = V_264 ;
V_389 = V_5 -> V_243 ;
V_5 -> V_243 = V_388 ;
F_44 ( & V_8 -> V_130 ) ;
F_111 ( & V_5 -> V_209 ) ;
F_115 ( V_5 ) ;
F_43 ( & V_8 -> V_130 ) ;
V_5 -> V_152 = V_162 ;
F_44 ( & V_8 -> V_130 ) ;
if ( V_388 == V_386 ) {
V_5 -> V_390 = 0 ;
V_5 -> V_391 = 0 ;
if ( V_8 -> V_115 == V_264 &&
V_389 != V_386 ) {
F_20 ( V_8 , L_116 ) ;
F_183 ( V_8 -> V_262 ) ;
}
}
F_43 ( & V_8 -> V_130 ) ;
F_113 ( V_5 , - 1 , V_141 ) ;
F_181 ( V_8 , V_5 ) ;
memset ( & V_5 -> V_75 , 0 , sizeof( V_5 -> V_75 ) ) ;
F_44 ( & V_8 -> V_130 ) ;
F_107 ( & V_8 -> V_298 ) ;
}
void F_184 ( struct V_165 * V_166 , int V_388 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
struct V_14 * V_8 = V_5 -> V_8 ;
switch ( V_388 ) {
case V_386 :
case V_387 :
F_182 ( V_8 , V_5 , V_388 ) ;
break;
default:
F_27 ( V_159 , V_5 ,
L_117 , V_388 ) ;
}
}
int F_185 ( struct V_261 * V_262 ,
struct V_165 * V_166 , int V_392 )
{
struct V_14 * V_8 = V_262 -> V_167 ;
struct V_4 * V_5 = V_166 -> V_167 ;
F_43 ( & V_8 -> V_130 ) ;
if ( V_392 )
V_8 -> V_17 = V_5 ;
F_44 ( & V_8 -> V_130 ) ;
F_118 ( V_244 , & V_5 -> V_246 ) ;
F_118 ( V_244 , & V_5 -> V_245 ) ;
return 0 ;
}
static int F_186 ( char * * V_393 , char * V_394 )
{
char * V_395 ;
if ( * V_393 ) {
if ( ! strcmp ( * V_393 , V_394 ) )
return 0 ;
}
V_395 = F_187 ( V_394 , V_396 ) ;
if ( ! V_395 )
return - V_254 ;
F_138 ( * V_393 ) ;
* V_393 = V_395 ;
return 0 ;
}
int F_188 ( struct V_165 * V_166 ,
enum V_397 V_393 , char * V_398 , int V_399 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
struct V_14 * V_8 = V_5 -> V_8 ;
T_2 V_400 ;
switch( V_393 ) {
case V_401 :
sscanf ( V_398 , L_118 , & V_8 -> V_87 ) ;
break;
case V_402 :
sscanf ( V_398 , L_118 , & V_8 -> V_314 ) ;
break;
case V_403 :
sscanf ( V_398 , L_118 , & V_8 -> V_319 ) ;
break;
case V_404 :
sscanf ( V_398 , L_118 , & V_8 -> V_322 ) ;
break;
case V_405 :
sscanf ( V_398 , L_118 , & V_5 -> V_300 ) ;
break;
case V_406 :
sscanf ( V_398 , L_118 , & V_5 -> V_210 ) ;
break;
case V_407 :
sscanf ( V_398 , L_118 , & V_5 -> V_408 ) ;
break;
case V_409 :
sscanf ( V_398 , L_118 , & V_5 -> V_41 ) ;
break;
case V_410 :
sscanf ( V_398 , L_118 , & V_5 -> V_390 ) ;
break;
case V_411 :
sscanf ( V_398 , L_118 , & V_5 -> V_391 ) ;
break;
case V_412 :
sscanf ( V_398 , L_118 , & V_8 -> V_108 ) ;
break;
case V_413 :
sscanf ( V_398 , L_118 , & V_8 -> V_365 ) ;
break;
case V_414 :
sscanf ( V_398 , L_118 , & V_8 -> V_106 ) ;
break;
case V_415 :
sscanf ( V_398 , L_118 , & V_8 -> V_107 ) ;
break;
case V_416 :
sscanf ( V_398 , L_118 , & V_8 -> V_385 ) ;
break;
case V_417 :
sscanf ( V_398 , L_118 , & V_8 -> V_418 ) ;
break;
case V_419 :
sscanf ( V_398 , L_118 , & V_8 -> V_420 ) ;
break;
case V_421 :
sscanf ( V_398 , L_118 , & V_8 -> V_422 ) ;
break;
case V_423 :
sscanf ( V_398 , L_118 , & V_400 ) ;
F_17 ( V_400 ) ;
break;
case V_424 :
sscanf ( V_398 , L_118 , & V_400 ) ;
F_17 ( V_400 ) ;
break;
case V_425 :
sscanf ( V_398 , L_119 , & V_5 -> V_38 ) ;
break;
case V_426 :
return F_186 ( & V_8 -> V_374 , V_398 ) ;
case V_427 :
return F_186 ( & V_8 -> V_375 , V_398 ) ;
case V_428 :
return F_186 ( & V_8 -> V_372 , V_398 ) ;
case V_429 :
return F_186 ( & V_8 -> V_373 , V_398 ) ;
case V_430 :
return F_186 ( & V_8 -> V_320 , V_398 ) ;
case V_431 :
sscanf ( V_398 , L_118 , & V_8 -> V_432 ) ;
break;
case V_433 :
sscanf ( V_398 , L_118 , & V_5 -> V_434 ) ;
break;
case V_435 :
return F_186 ( & V_5 -> V_321 , V_398 ) ;
case V_436 :
return F_186 ( & V_8 -> V_376 , V_398 ) ;
case V_437 :
return F_186 ( & V_8 -> V_351 , V_398 ) ;
default:
return - V_438 ;
}
return 0 ;
}
int F_189 ( struct V_261 * V_262 ,
enum V_397 V_393 , char * V_398 )
{
struct V_14 * V_8 = V_262 -> V_167 ;
int V_47 ;
switch( V_393 ) {
case V_401 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_87 ) ;
break;
case V_402 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_314 ) ;
break;
case V_403 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_319 ) ;
break;
case V_404 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_322 ) ;
break;
case V_412 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_108 ) ;
break;
case V_413 :
V_47 = sprintf ( V_398 , L_121 , V_8 -> V_365 ) ;
break;
case V_414 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_106 ) ;
break;
case V_415 :
V_47 = sprintf ( V_398 , L_3 , V_8 -> V_107 ) ;
break;
case V_416 :
V_47 = sprintf ( V_398 , L_3 , V_8 -> V_385 ) ;
break;
case V_417 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_418 ) ;
break;
case V_419 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_420 ) ;
break;
case V_421 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_422 ) ;
break;
case V_430 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_320 ) ;
break;
case V_431 :
V_47 = sprintf ( V_398 , L_120 , V_8 -> V_432 ) ;
break;
case V_426 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_374 ) ;
break;
case V_427 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_375 ) ;
break;
case V_428 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_372 ) ;
break;
case V_429 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_373 ) ;
break;
case V_436 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_376 ) ;
break;
case V_437 :
V_47 = sprintf ( V_398 , L_122 , V_8 -> V_351 ) ;
break;
default:
return - V_438 ;
}
return V_47 ;
}
int F_190 ( struct V_439 * V_440 ,
enum V_397 V_393 , char * V_398 )
{
struct V_441 * V_442 = NULL ;
struct V_443 * sin = NULL ;
int V_47 ;
switch ( V_440 -> V_444 ) {
case V_445 :
sin = (struct V_443 * ) V_440 ;
break;
case V_446 :
V_442 = (struct V_441 * ) V_440 ;
break;
default:
return - V_50 ;
}
switch ( V_393 ) {
case V_447 :
case V_448 :
if ( sin )
V_47 = sprintf ( V_398 , L_123 , & sin -> V_449 . V_450 ) ;
else
V_47 = sprintf ( V_398 , L_124 , & V_442 -> V_451 ) ;
break;
case V_452 :
if ( sin )
V_47 = sprintf ( V_398 , L_121 , F_23 ( sin -> V_453 ) ) ;
else
V_47 = sprintf ( V_398 , L_121 ,
F_23 ( V_442 -> V_454 ) ) ;
break;
default:
return - V_50 ;
}
return V_47 ;
}
int F_191 ( struct V_165 * V_166 ,
enum V_397 V_393 , char * V_398 )
{
struct V_4 * V_5 = V_166 -> V_167 ;
int V_47 ;
switch( V_393 ) {
case V_405 :
V_47 = sprintf ( V_398 , L_3 , V_5 -> V_300 ) ;
break;
case V_406 :
V_47 = sprintf ( V_398 , L_3 , V_5 -> V_210 ) ;
break;
case V_407 :
V_47 = sprintf ( V_398 , L_3 , V_5 -> V_408 ) ;
break;
case V_409 :
V_47 = sprintf ( V_398 , L_3 , V_5 -> V_41 ) ;
break;
case V_410 :
V_47 = sprintf ( V_398 , L_120 , V_5 -> V_390 ) ;
break;
case V_411 :
V_47 = sprintf ( V_398 , L_120 , V_5 -> V_391 ) ;
break;
case V_423 :
V_47 = sprintf ( V_398 , L_120 , V_5 -> V_455 ) ;
break;
case V_424 :
V_47 = sprintf ( V_398 , L_120 , V_5 -> V_456 ) ;
break;
case V_425 :
V_47 = sprintf ( V_398 , L_3 , V_5 -> V_38 ) ;
break;
case V_433 :
V_47 = sprintf ( V_398 , L_120 , V_5 -> V_434 ) ;
break;
case V_435 :
V_47 = sprintf ( V_398 , L_122 , V_5 -> V_321 ) ;
break;
default:
return - V_438 ;
}
return V_47 ;
}
int F_192 ( struct V_6 * V_7 , enum V_457 V_393 ,
char * V_398 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_47 ;
switch ( V_393 ) {
case V_458 :
V_47 = sprintf ( V_398 , L_122 , V_11 -> V_349 ) ;
break;
case V_459 :
V_47 = sprintf ( V_398 , L_122 , V_11 -> V_350 ) ;
break;
case V_460 :
V_47 = sprintf ( V_398 , L_122 , V_11 -> V_351 ) ;
break;
default:
return - V_438 ;
}
return V_47 ;
}
int F_193 ( struct V_6 * V_7 , enum V_457 V_393 ,
char * V_398 , int V_399 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
switch ( V_393 ) {
case V_458 :
return F_186 ( & V_11 -> V_349 , V_398 ) ;
case V_459 :
return F_186 ( & V_11 -> V_350 , V_398 ) ;
case V_460 :
return F_186 ( & V_11 -> V_351 , V_398 ) ;
default:
return - V_438 ;
}
return 0 ;
}
