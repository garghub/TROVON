inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_9 )
F_3 ( V_8 -> V_9 , & V_2 -> V_10 ) ;
}
static void F_4 ( struct V_11 * V_5 ,
T_1 V_12 , T_1 V_13 )
{
if ( F_5 ( V_13 , V_12 - 1 ) )
return;
if ( V_12 != V_5 -> V_12 &&
! F_5 ( V_12 , V_5 -> V_12 ) )
V_5 -> V_12 = V_12 ;
if ( V_13 != V_5 -> V_13 &&
! F_5 ( V_13 , V_5 -> V_13 ) )
V_5 -> V_13 = V_13 ;
}
void F_6 ( struct V_11 * V_5 , struct V_14 * V_15 )
{
F_4 ( V_5 , F_7 ( V_15 -> V_12 ) ,
F_7 ( V_15 -> V_13 ) ) ;
}
void F_8 ( struct V_16 * V_17 , struct V_18 * V_19 ,
struct V_20 * V_15 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned int V_21 = V_19 -> V_22 - V_19 -> V_23 ;
V_17 -> V_24 = sizeof( struct V_20 ) ;
memset ( V_15 , 0 , sizeof( struct V_20 ) ) ;
V_15 -> V_25 = V_19 -> V_25 ;
V_15 -> V_26 = F_9 ( V_19 -> V_26 ) ;
V_19 -> V_26 ++ ;
V_15 -> V_27 = V_28 ;
V_15 -> V_29 = V_17 -> V_29 ;
V_15 -> V_30 = V_17 -> V_31 ;
V_15 -> V_32 = V_19 -> V_32 ;
V_15 -> V_33 = F_9 ( V_19 -> V_34 + V_19 -> V_23 ) ;
if ( V_21 > V_2 -> V_35 ) {
F_10 ( V_15 -> V_36 , V_2 -> V_35 ) ;
V_19 -> V_37 = V_2 -> V_35 ;
V_15 -> V_38 = 0 ;
} else {
F_10 ( V_15 -> V_36 , V_21 ) ;
V_19 -> V_37 = V_21 ;
V_15 -> V_38 = V_39 ;
}
V_2 -> V_40 ++ ;
}
static int F_11 ( struct V_16 * V_17 , unsigned V_41 )
{
unsigned V_42 = V_17 -> V_24 + V_41 ;
if ( V_42 > V_17 -> V_43 ) {
F_12 ( 1 ) ;
return - V_44 ;
}
F_12 ( V_41 & ( V_45 - 1 ) ) ;
V_17 -> V_24 = V_42 ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_46 * V_47 = V_17 -> V_48 ;
unsigned V_49 , V_50 ;
unsigned short V_51 ;
struct V_52 * V_53 ;
int V_54 ;
V_53 = F_14 ( V_17 ) ;
V_49 = V_47 -> V_55 - V_56 ;
F_15 ( V_49 > sizeof( V_53 -> V_57 ) ) ;
V_51 = V_49 + sizeof( V_53 -> V_58 ) ;
V_50 = F_16 ( V_49 ) ;
V_54 = F_11 ( V_17 , sizeof( V_53 -> V_51 ) +
sizeof( V_53 -> V_59 ) + V_51 + V_50 ) ;
if ( V_54 )
return V_54 ;
if ( V_50 )
memset ( & V_53 -> V_57 [ V_49 ] , 0 , V_50 ) ;
V_53 -> V_51 = F_17 ( V_51 ) ;
V_53 -> V_59 = V_60 ;
V_53 -> V_58 = 0 ;
memcpy ( V_53 -> V_57 , V_47 -> V_61 + V_56 , V_49 ) ;
F_18 ( V_17 -> V_2 -> V_5 ,
L_1
L_2
L_3 , V_47 -> V_55 , V_49 , V_50 , V_51 ,
V_17 -> V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_46 * V_48 = V_17 -> V_48 ;
struct V_62 * V_63 ;
int V_54 ;
V_63 = F_14 ( V_17 ) ;
V_54 = F_11 ( V_17 , sizeof( * V_63 ) ) ;
if ( V_54 )
return V_54 ;
V_63 -> V_51 =
F_17 ( sizeof( V_63 -> V_64 ) +
sizeof( V_63 -> V_58 ) ) ;
V_63 -> V_59 = V_65 ;
V_63 -> V_58 = 0 ;
V_63 -> V_64 = F_9 ( F_20 ( V_48 ) -> V_66 ) ;
F_18 ( V_17 -> V_2 -> V_5 ,
L_4
L_5 ,
F_7 ( V_63 -> V_64 ) ,
F_21 ( V_63 -> V_51 ) ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , int V_27 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_67 * V_68 = & V_2 -> V_69 ;
T_2 V_70 ;
if ( V_2 -> V_71 == V_72 )
return 0 ;
if ( ( V_68 -> V_27 & V_73 ) != V_74 )
return 0 ;
switch ( F_23 ( V_68 ) ) {
case V_75 :
V_70 = F_24 ( & V_68 -> V_29 ) ;
if ( V_70 != V_17 -> V_48 -> V_76 -> V_29 )
return 0 ;
case V_77 :
if ( V_27 != V_28 ) {
F_25 ( V_78 , V_2 ,
L_6
L_7
L_8 ,
V_17 -> V_15 -> V_27 , V_27 ,
V_17 -> V_30 , V_17 -> V_31 ) ;
return - V_79 ;
}
if ( V_2 -> V_5 -> V_80 ) {
F_25 ( V_78 , V_2 ,
L_6
L_9 ,
V_17 -> V_15 -> V_27 , V_27 ,
V_17 -> V_30 , V_17 -> V_31 ) ;
return - V_79 ;
}
break;
case V_81 :
if ( V_27 == V_28 &&
V_17 -> V_31 == V_68 -> V_82 ) {
F_18 ( V_2 -> V_5 ,
L_10
L_11
L_12 , V_17 -> V_30 ,
V_17 -> V_31 ) ;
return - V_79 ;
}
break;
}
return 0 ;
}
static int F_26 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_46 * V_48 = V_17 -> V_48 ;
struct V_83 * V_15 ;
unsigned V_84 , V_55 , V_85 ;
T_3 V_30 ;
int V_54 ;
V_54 = F_22 ( V_17 , V_86 ) ;
if ( V_54 )
return V_54 ;
if ( V_2 -> V_5 -> V_87 -> V_88 ) {
V_54 = V_2 -> V_5 -> V_87 -> V_88 ( V_17 , V_86 ) ;
if ( V_54 )
return V_54 ;
}
V_15 = (struct V_83 * ) V_17 -> V_15 ;
V_30 = V_15 -> V_30 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( V_5 -> V_87 -> V_89 )
V_15 -> V_30 = V_17 -> V_31 = V_30 ;
else
V_15 -> V_30 = V_17 -> V_31 = F_27 ( V_17 -> V_30 ,
V_17 -> V_2 -> V_5 -> V_90 ) ;
V_17 -> V_24 = 0 ;
V_54 = F_11 ( V_17 , sizeof( * V_15 ) ) ;
if ( V_54 )
return V_54 ;
V_15 -> V_27 = V_86 ;
V_15 -> V_38 = V_91 ;
F_28 ( V_48 -> V_76 -> V_29 , & V_15 -> V_29 ) ;
V_17 -> V_29 = V_15 -> V_29 ;
V_15 -> V_32 = F_9 ( V_2 -> V_32 ) ;
V_55 = V_48 -> V_55 ;
if ( V_55 < V_56 )
memset ( & V_15 -> V_92 [ V_55 ] , 0 , V_56 - V_55 ) ;
else if ( V_55 > V_56 ) {
V_54 = F_13 ( V_17 ) ;
if ( V_54 )
return V_54 ;
V_55 = V_56 ;
}
memcpy ( V_15 -> V_92 , V_48 -> V_61 , V_55 ) ;
V_17 -> V_93 = 0 ;
if ( F_29 ( V_48 ) ) {
V_15 -> V_38 |= V_94 ;
V_54 = F_19 ( V_17 ) ;
if ( V_54 )
return V_54 ;
}
if ( F_30 ( V_48 ) != V_95 )
V_17 -> V_96 = true ;
V_85 = F_31 ( V_48 ) ;
V_15 -> V_22 = F_9 ( V_85 ) ;
if ( V_48 -> V_97 == V_98 ) {
struct V_18 * V_19 = & V_17 -> V_99 ;
V_15 -> V_38 |= V_100 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
if ( V_5 -> V_101 ) {
if ( V_85 >= V_5 -> V_102 )
V_17 -> V_93 = F_32 ( V_5 -> V_102 ,
V_2 -> V_35 ) ;
else
V_17 -> V_93 = F_32 ( V_85 ,
V_2 -> V_35 ) ;
F_10 ( V_15 -> V_36 , V_17 -> V_93 ) ;
} else
F_33 ( V_15 -> V_36 ) ;
if ( ! V_5 -> V_103 ) {
V_19 -> V_22 = F_32 ( V_5 -> V_102 ,
V_85 ) -
V_17 -> V_93 ;
V_19 -> V_34 = V_17 -> V_93 ;
V_19 -> V_25 = F_9 ( V_104 ) ;
V_19 -> V_32 = F_9 ( V_2 -> V_32 ) ;
}
if ( ! V_17 -> V_99 . V_22 )
V_15 -> V_38 |= V_39 ;
} else {
V_15 -> V_38 |= V_39 ;
F_33 ( V_15 -> V_36 ) ;
if ( V_48 -> V_97 == V_105 )
V_15 -> V_38 |= V_94 ;
}
V_84 = V_17 -> V_24 - sizeof( * V_15 ) ;
F_12 ( V_84 & ( V_45 - 1 ) ) ;
V_84 /= V_45 ;
F_12 ( V_84 >= 256 ) ;
V_15 -> V_106 = V_84 & 0xFF ;
V_15 -> V_107 = V_17 -> V_107 = F_9 ( V_5 -> V_107 ) ;
if ( V_5 -> V_87 -> V_108 && V_5 -> V_87 -> V_108 ( V_17 ) )
return - V_109 ;
V_17 -> V_110 = V_111 ;
V_5 -> V_107 ++ ;
V_2 -> V_112 ++ ;
F_18 ( V_5 , L_13
L_14 ,
F_29 ( V_48 ) ? L_15 :
V_48 -> V_97 == V_98 ?
L_16 : L_17 , V_2 -> V_113 , V_48 , V_48 -> V_61 [ 0 ] ,
V_17 -> V_30 , V_85 ,
F_29 ( V_48 ) ? F_20 ( V_48 ) -> V_66 : 0 ,
V_5 -> V_107 ,
V_5 -> V_13 - V_5 -> V_12 + 1 ) ;
return 0 ;
}
static void F_34 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_46 * V_48 = V_17 -> V_48 ;
int V_114 = V_17 -> V_110 ;
F_18 ( V_5 , L_18 ,
V_17 -> V_30 , V_17 -> V_110 , V_17 -> V_48 ) ;
V_5 -> V_87 -> V_115 ( V_17 ) ;
V_17 -> V_110 = V_116 ;
V_17 -> V_48 = NULL ;
if ( V_2 -> V_117 == V_17 )
return;
F_35 ( & V_5 -> V_118 . V_119 , ( void * ) & V_17 , sizeof( void * ) ) ;
if ( V_48 ) {
V_48 -> V_120 . V_121 = NULL ;
if ( V_114 != V_122 )
V_48 -> V_123 ( V_48 ) ;
}
}
void F_36 ( struct V_16 * V_17 )
{
F_37 ( & V_17 -> V_124 ) ;
}
void F_38 ( struct V_16 * V_17 )
{
if ( F_39 ( & V_17 -> V_124 ) )
F_34 ( V_17 ) ;
}
void F_40 ( struct V_16 * V_17 )
{
struct V_11 * V_5 = V_17 -> V_2 -> V_5 ;
F_41 ( & V_5 -> V_125 ) ;
F_38 ( V_17 ) ;
F_42 ( & V_5 -> V_125 ) ;
}
static void F_43 ( struct V_16 * V_17 , int V_110 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
F_18 ( V_2 -> V_5 ,
L_19 ,
V_17 -> V_30 , V_17 -> V_110 , V_17 -> V_48 ) ;
if ( V_17 -> V_110 == V_126 ||
V_17 -> V_110 == V_127 ||
V_17 -> V_110 == V_128 ||
V_17 -> V_110 == V_122 )
return;
F_44 ( V_17 -> V_110 == V_116 ) ;
V_17 -> V_110 = V_110 ;
if ( ! F_45 ( & V_17 -> V_129 ) )
F_46 ( & V_17 -> V_129 ) ;
if ( V_2 -> V_17 == V_17 )
V_2 -> V_17 = NULL ;
if ( V_2 -> V_130 == V_17 )
V_2 -> V_130 = NULL ;
F_38 ( V_17 ) ;
}
void F_47 ( struct V_16 * V_17 ,
T_1 V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
F_18 ( V_2 -> V_5 , L_20 , V_17 -> V_30 ) ;
V_2 -> V_131 = V_132 ;
F_4 ( V_2 -> V_5 , V_12 , V_13 ) ;
F_43 ( V_17 , V_126 ) ;
}
static void F_48 ( struct V_16 * V_17 , int V_133 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_46 * V_48 ;
int V_110 ;
V_48 = V_17 -> V_48 ;
if ( ! V_48 )
return;
if ( V_17 -> V_110 == V_134 ) {
V_2 -> V_5 -> V_135 -- ;
V_110 = V_126 ;
} else if ( V_133 == V_136 )
V_110 = V_128 ;
else
V_110 = V_127 ;
V_48 -> V_137 = V_133 << 16 ;
if ( ! F_29 ( V_48 ) )
F_49 ( V_48 , F_50 ( V_48 ) ) ;
else {
F_51 ( V_48 ) -> V_138 = F_51 ( V_48 ) -> V_66 ;
F_20 ( V_48 ) -> V_138 = F_20 ( V_48 ) -> V_66 ;
}
F_41 ( & V_2 -> V_5 -> V_125 ) ;
F_43 ( V_17 , V_110 ) ;
F_42 ( & V_2 -> V_5 -> V_125 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_139 * V_15 = V_17 -> V_15 ;
struct V_140 * V_141 = (struct V_140 * ) V_15 ;
T_4 V_27 = V_15 -> V_27 & V_73 ;
if ( V_2 -> V_5 -> V_110 == V_142 )
return - V_143 ;
if ( V_27 != V_144 && V_27 != V_145 )
V_141 -> V_32 = F_9 ( V_2 -> V_32 ) ;
V_141 -> V_107 = F_9 ( V_5 -> V_107 ) ;
if ( V_15 -> V_30 != V_146 ) {
if ( V_2 -> V_147 == V_148 &&
! ( V_15 -> V_27 & V_149 ) ) {
V_5 -> V_135 ++ ;
V_5 -> V_107 ++ ;
}
}
if ( V_5 -> V_87 -> V_108 && V_5 -> V_87 -> V_108 ( V_17 ) )
return - V_109 ;
if ( ( V_15 -> V_27 & V_73 ) == V_150 )
V_5 -> V_110 = V_142 ;
V_17 -> V_110 = V_111 ;
F_18 ( V_5 , L_21
L_22 , V_15 -> V_27 & V_73 ,
V_15 -> V_30 , V_17 -> V_37 ) ;
return 0 ;
}
static struct V_16 *
F_53 ( struct V_1 * V_2 , struct V_139 * V_15 ,
char * V_151 , T_1 V_152 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_7 * V_8 = F_2 ( V_5 -> V_6 ) ;
T_4 V_27 = V_15 -> V_27 & V_73 ;
struct V_16 * V_17 ;
T_3 V_30 ;
if ( V_5 -> V_110 == V_153 )
return NULL ;
if ( V_27 == V_144 || V_27 == V_145 ) {
if ( V_2 -> V_117 -> V_110 != V_116 ) {
F_25 ( V_154 , V_2 , L_23
L_24 ) ;
return NULL ;
}
if ( V_152 > V_155 ) {
F_25 ( V_154 , V_2 , L_25 , V_152 , V_155 ) ;
return NULL ;
}
V_17 = V_2 -> V_117 ;
} else {
if ( V_5 -> V_110 != V_156 )
return NULL ;
if ( V_152 != 0 ) {
F_25 ( V_154 , V_2 , L_26 , V_152 , V_27 ) ;
return NULL ;
}
F_15 ( V_2 -> V_147 == V_157 ) ;
F_15 ( V_2 -> V_147 == V_158 ) ;
if ( ! F_54 ( & V_5 -> V_118 . V_119 ,
( void * ) & V_17 , sizeof( void * ) ) )
return NULL ;
}
F_55 ( & V_17 -> V_124 , 1 ) ;
V_17 -> V_2 = V_2 ;
V_17 -> V_48 = NULL ;
F_56 ( & V_17 -> V_129 ) ;
V_17 -> V_110 = V_134 ;
if ( V_152 ) {
memcpy ( V_17 -> V_151 , V_151 , V_152 ) ;
V_17 -> V_37 = V_152 ;
} else
V_17 -> V_37 = 0 ;
if ( V_2 -> V_5 -> V_87 -> V_88 ) {
if ( V_2 -> V_5 -> V_87 -> V_88 ( V_17 , V_15 -> V_27 ) ) {
F_25 ( V_154 , V_2 , L_27
L_28 ) ;
goto V_159;
}
}
V_30 = V_17 -> V_15 -> V_30 ;
V_17 -> V_24 = sizeof( struct V_139 ) ;
memcpy ( V_17 -> V_15 , V_15 , sizeof( struct V_139 ) ) ;
if ( V_15 -> V_30 != V_146 ) {
if ( V_5 -> V_87 -> V_89 )
V_17 -> V_15 -> V_30 = V_30 ;
else
V_17 -> V_15 -> V_30 = F_27 ( V_17 -> V_30 ,
V_17 -> V_2 -> V_5 -> V_90 ) ;
}
if ( ! V_8 -> V_9 ) {
if ( F_52 ( V_2 , V_17 ) )
goto V_159;
if ( V_5 -> V_87 -> V_160 ( V_17 ) )
goto V_159;
} else {
F_57 ( & V_17 -> V_129 , & V_2 -> V_161 ) ;
F_1 ( V_2 ) ;
}
return V_17 ;
V_159:
F_41 ( & V_5 -> V_125 ) ;
F_38 ( V_17 ) ;
F_42 ( & V_5 -> V_125 ) ;
return NULL ;
}
int F_58 ( struct V_162 * V_163 , struct V_139 * V_15 ,
char * V_151 , T_1 V_152 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
int V_133 = 0 ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! F_53 ( V_2 , V_15 , V_151 , V_152 ) )
V_133 = - V_166 ;
F_42 ( & V_5 -> V_165 ) ;
return V_133 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_139 * V_15 ,
struct V_16 * V_17 , char * V_151 ,
int V_167 )
{
struct V_168 * V_169 = (struct V_168 * ) V_15 ;
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_46 * V_48 = V_17 -> V_48 ;
F_6 ( V_5 , (struct V_14 * ) V_169 ) ;
V_2 -> V_32 = F_7 ( V_169 -> V_170 ) + 1 ;
V_48 -> V_137 = ( V_171 << 16 ) | V_169 -> V_172 ;
if ( V_17 -> V_96 ) {
T_5 V_173 ;
T_6 V_174 ;
F_15 ( ! V_5 -> V_87 -> V_175 ) ;
V_174 = V_5 -> V_87 -> V_175 ( V_17 , & V_173 ) ;
if ( V_174 ) {
V_48 -> V_137 = V_176 << 24 |
V_177 ;
F_60 ( 1 , V_48 -> V_178 ,
V_179 , 0x10 , V_174 ) ;
F_61 ( V_48 -> V_178 ,
V_180 ,
V_173 ) ;
goto V_181;
}
}
if ( V_169 -> V_182 != V_183 ) {
V_48 -> V_137 = V_184 << 16 ;
goto V_181;
}
if ( V_169 -> V_172 == V_177 ) {
T_7 V_185 ;
if ( V_167 < 2 ) {
V_186:
F_25 ( V_154 , V_2 ,
L_29
L_30 , V_167 ) ;
V_48 -> V_137 = V_187 << 16 ;
goto V_181;
}
V_185 = F_62 ( V_151 ) ;
if ( V_167 < V_185 )
goto V_186;
memcpy ( V_48 -> V_178 , V_151 + 2 ,
F_63 ( T_7 , V_185 , V_180 ) ) ;
F_18 ( V_5 , L_31 ,
F_63 ( T_7 , V_185 ,
V_180 ) ) ;
}
if ( V_169 -> V_38 & ( V_188 |
V_189 ) ) {
int V_190 = F_7 ( V_169 -> V_191 ) ;
if ( F_29 ( V_48 ) && V_190 > 0 &&
( V_169 -> V_38 & V_189 ||
V_190 <= F_20 ( V_48 ) -> V_66 ) )
F_20 ( V_48 ) -> V_138 = V_190 ;
else
V_48 -> V_137 = ( V_187 << 16 ) | V_169 -> V_172 ;
}
if ( V_169 -> V_38 & ( V_192 |
V_193 ) ) {
int V_190 = F_7 ( V_169 -> V_194 ) ;
if ( V_190 > 0 &&
( V_169 -> V_38 & V_193 ||
V_190 <= F_50 ( V_48 ) ) )
F_49 ( V_48 , V_190 ) ;
else
V_48 -> V_137 = ( V_187 << 16 ) | V_169 -> V_172 ;
}
V_181:
F_18 ( V_5 , L_32 ,
V_48 , V_48 -> V_137 , V_17 -> V_30 ) ;
V_2 -> V_195 ++ ;
F_43 ( V_17 , V_126 ) ;
}
static void
F_64 ( struct V_1 * V_2 , struct V_139 * V_15 ,
struct V_16 * V_17 )
{
struct V_196 * V_169 = (struct V_196 * ) V_15 ;
struct V_46 * V_48 = V_17 -> V_48 ;
if ( ! ( V_169 -> V_38 & V_197 ) )
return;
F_6 ( V_2 -> V_5 , (struct V_14 * ) V_15 ) ;
V_48 -> V_137 = ( V_171 << 16 ) | V_169 -> V_172 ;
V_2 -> V_32 = F_7 ( V_169 -> V_170 ) + 1 ;
if ( V_169 -> V_38 & ( V_198 |
V_199 ) ) {
int V_190 = F_7 ( V_169 -> V_194 ) ;
if ( V_190 > 0 &&
( V_169 -> V_38 & V_193 ||
V_190 <= F_20 ( V_48 ) -> V_66 ) )
F_20 ( V_48 ) -> V_138 = V_190 ;
else
V_48 -> V_137 = ( V_187 << 16 ) | V_169 -> V_172 ;
}
F_18 ( V_2 -> V_5 , L_33
L_34 ,
V_48 , V_48 -> V_137 , V_17 -> V_30 ) ;
V_2 -> V_195 ++ ;
F_43 ( V_17 , V_126 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_139 * V_15 )
{
struct V_200 * V_68 = (struct V_200 * ) V_15 ;
V_2 -> V_32 = F_7 ( V_15 -> V_170 ) + 1 ;
V_2 -> V_201 ++ ;
if ( V_2 -> V_71 != V_202 )
return;
if ( V_68 -> V_182 == V_203 )
V_2 -> V_71 = V_204 ;
else if ( V_68 -> V_182 == V_205 )
V_2 -> V_71 = V_206 ;
else
V_2 -> V_71 = V_207 ;
F_66 ( & V_2 -> V_208 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_14 * V_169 )
{
struct V_140 V_15 ;
struct V_16 * V_17 ;
if ( ! V_169 && V_2 -> V_130 )
return - V_44 ;
memset ( & V_15 , 0 , sizeof( struct V_140 ) ) ;
V_15 . V_27 = V_209 | V_149 ;
V_15 . V_38 = V_39 ;
if ( V_169 ) {
V_15 . V_29 = V_169 -> V_29 ;
V_15 . V_25 = V_169 -> V_25 ;
V_15 . V_30 = V_146 ;
} else
V_15 . V_25 = V_146 ;
V_17 = F_53 ( V_2 , (struct V_139 * ) & V_15 , NULL , 0 ) ;
if ( ! V_17 ) {
F_25 ( V_154 , V_2 , L_35 ) ;
return - V_109 ;
} else if ( ! V_169 ) {
V_2 -> V_130 = V_17 ;
V_2 -> V_210 = V_132 ;
}
return 0 ;
}
static int F_68 ( struct V_16 * V_17 ,
struct V_14 * V_141 , char * V_151 , int V_167 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
int V_54 = 0 ;
if ( V_2 -> V_130 != V_17 ) {
if ( F_69 ( V_2 -> V_163 , (struct V_139 * ) V_141 ,
V_151 , V_167 ) )
V_54 = V_211 ;
} else
F_70 ( & V_2 -> V_212 , V_132 + V_2 -> V_213 ) ;
F_43 ( V_17 , V_126 ) ;
return V_54 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_139 * V_15 ,
char * V_151 , int V_167 )
{
struct V_214 * V_215 = (struct V_214 * ) V_15 ;
struct V_139 V_216 ;
int V_27 , V_54 = 0 ;
V_2 -> V_32 = F_7 ( V_215 -> V_170 ) + 1 ;
if ( F_72 ( V_215 -> V_36 ) > V_167 ||
F_72 ( V_215 -> V_36 ) < sizeof( struct V_139 ) ) {
F_25 ( V_154 , V_2 , L_36
L_37
L_38 , F_72 ( V_215 -> V_36 ) ,
V_167 ) ;
return V_217 ;
}
memcpy ( & V_216 , V_151 , sizeof( struct V_139 ) ) ;
V_27 = V_216 . V_27 & V_73 ;
switch ( V_215 -> V_218 ) {
case V_219 :
F_25 ( V_154 , V_2 ,
L_39
L_40 ,
V_27 , V_216 . V_30 ) ;
break;
case V_220 :
F_25 ( V_154 , V_2 ,
L_41
L_42 ,
V_27 , V_216 . V_30 ) ;
if ( V_27 != V_209 )
return 0 ;
if ( V_216 . V_30 == F_9 ( V_104 ) ) {
F_73 ( & V_2 -> V_5 -> V_125 ) ;
F_74 ( & V_2 -> V_5 -> V_165 ) ;
F_67 ( V_2 ,
(struct V_14 * ) & V_216 ) ;
F_73 ( & V_2 -> V_5 -> V_165 ) ;
F_74 ( & V_2 -> V_5 -> V_125 ) ;
} else {
struct V_16 * V_17 ;
V_17 = F_75 ( V_2 , V_216 . V_30 ) ;
if ( ! V_17 ) {
F_25 ( V_154 , V_2 ,
L_43
L_44 ) ;
V_54 = V_221 ;
} else
V_54 = F_68 ( V_17 ,
(struct V_14 * ) & V_216 ,
NULL , 0 ) ;
}
break;
default:
F_25 ( V_154 , V_2 ,
L_45
L_46 , V_216 . V_27 ,
V_216 . V_30 , V_215 -> V_218 ) ;
break;
}
return V_54 ;
}
struct V_16 * F_75 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
int V_222 ;
if ( V_30 == V_146 )
return NULL ;
if ( V_5 -> V_87 -> V_89 )
V_5 -> V_87 -> V_89 ( V_2 , V_30 , & V_222 , NULL ) ;
else
V_222 = F_76 ( V_30 ) ;
if ( V_222 >= V_5 -> V_223 )
return NULL ;
return V_5 -> V_224 [ V_222 ] ;
}
int F_77 ( struct V_1 * V_2 , struct V_139 * V_15 ,
char * V_151 , int V_167 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
int V_27 = V_15 -> V_27 & V_73 , V_54 = 0 ;
struct V_16 * V_17 ;
T_1 V_30 ;
V_2 -> V_131 = V_132 ;
V_54 = F_78 ( V_2 , V_15 -> V_30 ) ;
if ( V_54 )
return V_54 ;
if ( V_15 -> V_30 != V_146 )
V_30 = F_76 ( V_15 -> V_30 ) ;
else
V_30 = ~ 0U ;
F_18 ( V_5 , L_47 ,
V_27 , V_2 -> V_113 , V_30 , V_167 ) ;
if ( V_30 == ~ 0U ) {
F_6 ( V_5 , (struct V_14 * ) V_15 ) ;
switch( V_27 ) {
case V_225 :
if ( V_167 ) {
V_54 = V_217 ;
break;
}
if ( V_15 -> V_25 == F_9 ( V_104 ) )
break;
F_73 ( & V_5 -> V_125 ) ;
F_74 ( & V_5 -> V_165 ) ;
F_67 ( V_2 , (struct V_14 * ) V_15 ) ;
F_73 ( & V_5 -> V_165 ) ;
F_74 ( & V_5 -> V_125 ) ;
break;
case V_226 :
V_54 = F_71 ( V_2 , V_15 , V_151 , V_167 ) ;
break;
case V_227 :
V_2 -> V_32 = F_7 ( V_15 -> V_170 ) + 1 ;
if ( F_69 ( V_2 -> V_163 , V_15 , V_151 , V_167 ) )
V_54 = V_211 ;
break;
default:
V_54 = V_228 ;
break;
}
goto V_181;
}
switch( V_27 ) {
case V_229 :
case V_230 :
V_17 = F_79 ( V_2 , V_15 -> V_30 ) ;
if ( ! V_17 )
return V_221 ;
V_17 -> V_231 = V_132 ;
break;
case V_232 :
return 0 ;
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_225 :
V_17 = F_75 ( V_2 , V_15 -> V_30 ) ;
if ( ! V_17 )
return V_221 ;
break;
default:
return V_228 ;
}
switch( V_27 ) {
case V_229 :
F_59 ( V_2 , V_15 , V_17 , V_151 , V_167 ) ;
break;
case V_230 :
F_64 ( V_2 , V_15 , V_17 ) ;
break;
case V_233 :
F_6 ( V_5 , (struct V_14 * ) V_15 ) ;
if ( V_167 ) {
V_54 = V_217 ;
break;
}
V_2 -> V_32 = F_7 ( V_15 -> V_170 ) + 1 ;
goto V_237;
case V_234 :
case V_235 :
F_6 ( V_5 , (struct V_14 * ) V_15 ) ;
goto V_237;
case V_236 :
F_6 ( V_5 , (struct V_14 * ) V_15 ) ;
if ( V_167 ) {
V_54 = V_217 ;
break;
}
F_65 ( V_2 , V_15 ) ;
F_43 ( V_17 , V_126 ) ;
break;
case V_225 :
F_6 ( V_5 , (struct V_14 * ) V_15 ) ;
if ( V_15 -> V_25 != F_9 ( V_104 ) || V_167 ) {
V_54 = V_217 ;
break;
}
V_2 -> V_32 = F_7 ( V_15 -> V_170 ) + 1 ;
V_54 = F_68 ( V_17 , (struct V_14 * ) V_15 ,
V_151 , V_167 ) ;
break;
default:
V_54 = V_228 ;
break;
}
V_181:
return V_54 ;
V_237:
if ( F_69 ( V_2 -> V_163 , V_15 , V_151 , V_167 ) )
V_54 = V_211 ;
F_43 ( V_17 , V_126 ) ;
return V_54 ;
}
int F_80 ( struct V_1 * V_2 , struct V_139 * V_15 ,
char * V_151 , int V_167 )
{
int V_54 ;
F_74 ( & V_2 -> V_5 -> V_125 ) ;
V_54 = F_77 ( V_2 , V_15 , V_151 , V_167 ) ;
F_73 ( & V_2 -> V_5 -> V_125 ) ;
return V_54 ;
}
int F_78 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
int V_90 = 0 , V_222 = 0 ;
if ( V_30 == V_146 )
return 0 ;
if ( V_5 -> V_87 -> V_89 )
V_5 -> V_87 -> V_89 ( V_2 , V_30 , & V_222 , & V_90 ) ;
else {
V_222 = F_76 ( V_30 ) ;
V_90 = ( ( V_238 V_239 ) V_30 >> V_240 ) & V_241 ;
}
if ( V_90 != V_5 -> V_90 ) {
F_25 ( V_154 , V_2 ,
L_48 ,
( V_238 V_239 ) V_30 , V_5 -> V_90 ) ;
return V_221 ;
}
if ( V_222 >= V_5 -> V_223 ) {
F_25 ( V_154 , V_2 ,
L_49
L_50 , V_222 , V_5 -> V_223 ) ;
return V_221 ;
}
return 0 ;
}
struct V_16 * F_79 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_16 * V_17 ;
if ( F_78 ( V_2 , V_30 ) )
return NULL ;
V_17 = F_75 ( V_2 , V_30 ) ;
if ( ! V_17 || ! V_17 -> V_48 )
return NULL ;
if ( V_17 -> V_48 -> V_120 . V_242 != V_2 -> V_5 -> V_90 ) {
F_81 ( V_154 , V_2 -> V_5 ,
L_51 ,
V_17 -> V_48 -> V_120 . V_242 , V_2 -> V_5 -> V_90 ) ;
return NULL ;
}
return V_17 ;
}
void F_82 ( struct V_11 * V_5 ,
enum V_243 V_133 )
{
struct V_1 * V_2 ;
struct V_76 * V_244 ;
F_41 ( & V_5 -> V_165 ) ;
V_2 = V_5 -> V_245 ;
if ( V_5 -> V_110 == V_153 || ! V_2 ) {
F_42 ( & V_5 -> V_165 ) ;
return;
}
V_244 = F_83 ( & V_2 -> V_163 -> V_244 ) ;
F_42 ( & V_5 -> V_165 ) ;
if ( ! V_244 )
return;
if ( V_133 == V_246 )
F_84 ( V_2 -> V_163 , V_133 ) ;
else
F_85 ( V_2 , V_133 ) ;
F_86 ( V_244 ) ;
}
void F_85 ( struct V_1 * V_2 , enum V_243 V_133 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 == V_247 ) {
F_42 ( & V_5 -> V_165 ) ;
return;
}
if ( V_2 -> V_248 == 0 )
V_5 -> V_110 = V_247 ;
F_42 ( & V_5 -> V_165 ) ;
F_87 ( V_249 , & V_2 -> V_250 ) ;
F_87 ( V_249 , & V_2 -> V_251 ) ;
F_84 ( V_2 -> V_163 , V_133 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
if ( ! F_89 ( V_5 -> V_135 , V_5 -> V_13 ) ) {
F_18 ( V_5 , L_52
L_53 ,
V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_107 , V_5 -> V_135 ) ;
return - V_252 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_54 ;
if ( F_91 ( V_249 , & V_2 -> V_250 ) )
return - V_253 ;
F_36 ( V_17 ) ;
F_42 ( & V_2 -> V_5 -> V_165 ) ;
V_54 = V_2 -> V_5 -> V_87 -> V_160 ( V_17 ) ;
F_41 ( & V_2 -> V_5 -> V_165 ) ;
if ( ! V_54 ) {
V_17 -> V_231 = V_132 ;
V_2 -> V_17 = NULL ;
}
F_74 ( & V_2 -> V_5 -> V_125 ) ;
F_38 ( V_17 ) ;
F_73 ( & V_2 -> V_5 -> V_125 ) ;
return V_54 ;
}
void F_92 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
if ( F_45 ( & V_17 -> V_129 ) )
F_57 ( & V_17 -> V_129 , & V_2 -> V_254 ) ;
F_1 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_54 = 0 ;
F_41 ( & V_2 -> V_5 -> V_165 ) ;
if ( F_91 ( V_249 , & V_2 -> V_250 ) ) {
F_18 ( V_2 -> V_5 , L_54 ) ;
F_42 ( & V_2 -> V_5 -> V_165 ) ;
return - V_253 ;
}
if ( V_2 -> V_17 ) {
V_54 = F_90 ( V_2 ) ;
if ( V_54 )
goto V_255;
}
V_256:
while ( ! F_45 ( & V_2 -> V_161 ) ) {
V_2 -> V_17 = F_94 ( V_2 -> V_161 . V_257 ,
struct V_16 , V_129 ) ;
F_46 ( & V_2 -> V_17 -> V_129 ) ;
if ( F_52 ( V_2 , V_2 -> V_17 ) ) {
F_41 ( & V_2 -> V_5 -> V_125 ) ;
F_38 ( V_2 -> V_17 ) ;
F_42 ( & V_2 -> V_5 -> V_125 ) ;
V_2 -> V_17 = NULL ;
continue;
}
V_54 = F_90 ( V_2 ) ;
if ( V_54 )
goto V_255;
}
while ( ! F_45 ( & V_2 -> V_258 ) ) {
V_2 -> V_17 = F_94 ( V_2 -> V_258 . V_257 , struct V_16 ,
V_129 ) ;
F_46 ( & V_2 -> V_17 -> V_129 ) ;
if ( V_2 -> V_5 -> V_110 == V_142 ) {
F_48 ( V_2 -> V_17 , V_259 ) ;
continue;
}
V_54 = F_26 ( V_2 -> V_17 ) ;
if ( V_54 ) {
if ( V_54 == - V_260 || V_54 == - V_79 ) {
F_57 ( & V_2 -> V_17 -> V_129 ,
& V_2 -> V_258 ) ;
V_2 -> V_17 = NULL ;
goto V_255;
} else
F_48 ( V_2 -> V_17 , V_261 ) ;
continue;
}
V_54 = F_90 ( V_2 ) ;
if ( V_54 )
goto V_255;
if ( ! F_45 ( & V_2 -> V_161 ) )
goto V_256;
}
while ( ! F_45 ( & V_2 -> V_254 ) ) {
if ( V_2 -> V_5 -> V_110 == V_142 )
break;
V_17 = F_94 ( V_2 -> V_254 . V_257 , struct V_16 ,
V_129 ) ;
if ( F_22 ( V_17 , V_28 ) )
break;
V_2 -> V_17 = V_17 ;
F_46 ( & V_2 -> V_17 -> V_129 ) ;
V_2 -> V_17 -> V_110 = V_111 ;
V_54 = F_90 ( V_2 ) ;
if ( V_54 )
goto V_255;
if ( ! F_45 ( & V_2 -> V_161 ) )
goto V_256;
}
F_42 ( & V_2 -> V_5 -> V_165 ) ;
return - V_253 ;
V_255:
F_42 ( & V_2 -> V_5 -> V_165 ) ;
return V_54 ;
}
static void F_95 ( struct V_262 * V_263 )
{
struct V_1 * V_2 =
F_96 ( V_263 , struct V_1 , V_10 ) ;
int V_54 ;
do {
V_54 = F_93 ( V_2 ) ;
} while ( V_54 >= 0 || V_54 == - V_264 );
}
static inline struct V_16 * F_97 ( struct V_1 * V_2 ,
struct V_46 * V_48 )
{
struct V_16 * V_17 ;
if ( ! F_54 ( & V_2 -> V_5 -> V_118 . V_119 ,
( void * ) & V_17 , sizeof( void * ) ) )
return NULL ;
V_48 -> V_120 . V_242 = V_2 -> V_5 -> V_90 ;
V_48 -> V_120 . V_121 = ( char * ) V_17 ;
F_55 ( & V_17 -> V_124 , 1 ) ;
V_17 -> V_110 = V_134 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_48 = V_48 ;
V_17 -> V_265 = false ;
V_17 -> V_266 = V_132 ;
V_17 -> V_231 = V_132 ;
V_17 -> V_96 = false ;
F_56 ( & V_17 -> V_129 ) ;
return V_17 ;
}
int F_98 ( struct V_3 * V_6 , struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_7 * V_8 ;
int V_218 = 0 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_16 * V_17 = NULL ;
V_48 -> V_137 = 0 ;
V_48 -> V_120 . V_121 = NULL ;
V_8 = F_2 ( V_6 ) ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_41 ( & V_5 -> V_165 ) ;
V_218 = F_101 ( V_268 ) ;
if ( V_218 ) {
V_48 -> V_137 = V_218 ;
goto V_269;
}
if ( V_5 -> V_110 != V_156 ) {
switch ( V_5 -> V_110 ) {
case V_247 :
case V_270 :
V_218 = V_271 ;
V_48 -> V_137 = V_259 << 16 ;
break;
case V_142 :
V_218 = V_272 ;
V_48 -> V_137 = V_259 << 16 ;
break;
case V_273 :
V_218 = V_274 ;
V_48 -> V_137 = V_275 << 16 ;
break;
case V_153 :
V_218 = V_276 ;
V_48 -> V_137 = V_277 << 16 ;
break;
default:
V_218 = V_278 ;
V_48 -> V_137 = V_277 << 16 ;
}
goto V_269;
}
V_2 = V_5 -> V_245 ;
if ( ! V_2 ) {
V_218 = V_278 ;
V_48 -> V_137 = V_277 << 16 ;
goto V_269;
}
if ( F_91 ( V_249 , & V_2 -> V_250 ) ) {
V_218 = V_271 ;
V_48 -> V_137 = V_279 ;
goto V_269;
}
if ( F_88 ( V_2 ) ) {
V_218 = V_280 ;
goto V_215;
}
V_17 = F_97 ( V_2 , V_48 ) ;
if ( ! V_17 ) {
V_218 = V_281 ;
goto V_215;
}
if ( ! V_8 -> V_9 ) {
V_218 = F_26 ( V_17 ) ;
if ( V_218 ) {
if ( V_218 == - V_260 || V_218 == - V_79 ) {
V_218 = V_281 ;
goto V_282;
} else {
V_48 -> V_137 = V_261 << 16 ;
goto V_283;
}
}
if ( V_5 -> V_87 -> V_160 ( V_17 ) ) {
V_5 -> V_107 -- ;
V_218 = V_284 ;
goto V_282;
}
} else {
F_57 ( & V_17 -> V_129 , & V_2 -> V_258 ) ;
F_1 ( V_2 ) ;
}
V_5 -> V_135 ++ ;
F_42 ( & V_5 -> V_165 ) ;
return 0 ;
V_282:
F_43 ( V_17 , V_122 ) ;
V_215:
F_42 ( & V_5 -> V_165 ) ;
F_18 ( V_5 , L_55 ,
V_48 -> V_61 [ 0 ] , V_218 ) ;
return V_285 ;
V_283:
F_43 ( V_17 , V_122 ) ;
V_269:
F_42 ( & V_5 -> V_165 ) ;
F_18 ( V_5 , L_56 ,
V_48 -> V_61 [ 0 ] , V_218 ) ;
if ( ! F_29 ( V_48 ) )
F_49 ( V_48 , F_50 ( V_48 ) ) ;
else {
F_51 ( V_48 ) -> V_138 = F_51 ( V_48 ) -> V_66 ;
F_20 ( V_48 ) -> V_138 = F_20 ( V_48 ) -> V_66 ;
}
V_48 -> V_123 ( V_48 ) ;
return 0 ;
}
int F_102 ( struct F_100 * V_286 )
{
struct V_267 * V_268 = F_99 ( V_286 ) ;
struct V_11 * V_5 = V_268 -> V_164 ;
V_286 -> V_287 = V_5 -> V_288 ;
return 0 ;
}
static void F_103 ( unsigned long V_151 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 ;
struct V_11 * V_5 = V_2 -> V_5 ;
F_74 ( & V_5 -> V_165 ) ;
if ( V_2 -> V_71 == V_202 ) {
V_2 -> V_71 = V_289 ;
F_104 ( V_5 , L_57 ) ;
F_66 ( & V_2 -> V_208 ) ;
}
F_73 ( & V_5 -> V_165 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_67 * V_15 , int V_90 ,
int V_290 )
{
struct V_11 * V_5 = V_2 -> V_5 ;
struct V_16 * V_17 ;
V_17 = F_53 ( V_2 , (struct V_139 * ) V_15 ,
NULL , 0 ) ;
if ( ! V_17 ) {
F_42 ( & V_5 -> V_165 ) ;
F_25 ( V_154 , V_2 , L_58 ) ;
F_85 ( V_2 , V_211 ) ;
F_41 ( & V_5 -> V_165 ) ;
return - V_166 ;
}
V_2 -> V_291 ++ ;
V_2 -> V_292 . V_293 = V_290 * V_294 + V_132 ;
V_2 -> V_292 . V_295 = F_103 ;
V_2 -> V_292 . V_151 = ( unsigned long ) V_2 ;
F_106 ( & V_2 -> V_292 ) ;
F_104 ( V_5 , L_59 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
F_108 ( V_2 -> V_208 , V_90 != V_5 -> V_90 ||
V_5 -> V_110 != V_156 ||
V_2 -> V_71 != V_202 ) ;
if ( F_109 ( V_297 ) )
F_110 ( V_297 ) ;
F_111 ( & V_2 -> V_292 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_90 != V_5 -> V_90 ||
V_5 -> V_110 != V_156 )
return - V_143 ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , T_2 V_29 , int error )
{
struct V_16 * V_17 ;
int V_222 ;
for ( V_222 = 0 ; V_222 < V_2 -> V_5 -> V_223 ; V_222 ++ ) {
V_17 = V_2 -> V_5 -> V_224 [ V_222 ] ;
if ( ! V_17 -> V_48 || V_17 -> V_110 == V_116 )
continue;
if ( V_29 != - 1 && V_29 != V_17 -> V_48 -> V_76 -> V_29 )
continue;
F_18 ( V_2 -> V_5 ,
L_60 ,
V_17 -> V_48 , V_17 -> V_30 , V_17 -> V_110 ) ;
F_48 ( V_17 , error ) ;
}
}
void F_114 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_5 -> V_165 ) ;
F_87 ( V_249 , & V_2 -> V_250 ) ;
F_42 ( & V_2 -> V_5 -> V_165 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_87 ( V_249 , & V_2 -> V_250 ) ;
if ( V_8 -> V_9 )
F_116 ( V_8 -> V_9 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_118 ( V_249 , & V_2 -> V_250 ) ;
F_1 ( V_2 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( V_2 -> V_130 &&
F_120 ( V_2 -> V_131 + ( V_2 -> V_213 * V_294 ) +
( V_2 -> V_298 * V_294 ) , V_132 ) )
return 1 ;
else
return 0 ;
}
static enum V_299 F_121 ( struct V_46 * V_48 )
{
enum V_299 V_54 = V_300 ;
struct V_16 * V_17 = NULL , * V_301 ;
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
int V_222 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_104 ( V_5 , L_61 , V_48 ) ;
F_74 ( & V_5 -> V_165 ) ;
V_17 = (struct V_16 * ) V_48 -> V_120 . V_121 ;
if ( ! V_17 ) {
V_54 = V_302 ;
goto V_255;
}
if ( V_5 -> V_110 != V_156 ) {
V_54 = V_303 ;
goto V_255;
}
V_2 = V_5 -> V_245 ;
if ( ! V_2 ) {
V_54 = V_303 ;
goto V_255;
}
if ( F_122 ( V_17 -> V_231 , V_17 -> V_266 ) ) {
F_104 ( V_5 , L_62
L_63
L_64
L_65 , V_17 -> V_231 , V_17 -> V_266 ) ;
V_17 -> V_265 = false ;
V_54 = V_303 ;
goto V_255;
}
if ( ! V_2 -> V_213 && ! V_2 -> V_298 )
goto V_255;
if ( F_119 ( V_2 ) ) {
V_54 = V_303 ;
goto V_255;
}
for ( V_222 = 0 ; V_222 < V_2 -> V_5 -> V_223 ; V_222 ++ ) {
V_301 = V_2 -> V_5 -> V_224 [ V_222 ] ;
if ( ! V_301 -> V_48 || V_301 == V_17 ||
V_301 -> V_110 != V_111 )
continue;
if ( F_122 ( V_301 -> V_48 -> V_304 ,
V_17 -> V_48 -> V_304 ) )
continue;
if ( F_122 ( V_301 -> V_231 , V_17 -> V_266 ) ) {
F_104 ( V_5 , L_66
L_67
L_68
L_69
L_70 ,
V_17 -> V_231 , V_301 -> V_231 ,
V_17 -> V_266 ) ;
V_54 = V_303 ;
goto V_255;
}
}
if ( V_17 -> V_265 )
goto V_255;
if ( V_2 -> V_130 ) {
V_17 -> V_265 = true ;
V_54 = V_303 ;
goto V_255;
}
F_67 ( V_2 , NULL ) ;
V_17 -> V_265 = true ;
V_54 = V_303 ;
V_255:
if ( V_17 )
V_17 -> V_266 = V_132 ;
F_73 ( & V_5 -> V_165 ) ;
F_104 ( V_5 , L_71 , V_54 == V_303 ?
L_72 : L_73 ) ;
return V_54 ;
}
static void F_123 ( unsigned long V_151 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 ;
struct V_11 * V_5 = V_2 -> V_5 ;
unsigned long V_213 , V_305 = 0 , V_131 ;
F_74 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 != V_156 )
goto V_255;
V_213 = V_2 -> V_213 ;
if ( ! V_213 )
goto V_255;
V_213 *= V_294 ;
V_131 = V_2 -> V_131 ;
if ( F_119 ( V_2 ) ) {
F_25 ( V_154 , V_2 , L_74
L_75
L_76 ,
V_2 -> V_298 , V_2 -> V_213 ,
V_131 , V_2 -> V_210 , V_132 ) ;
F_73 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_306 ) ;
return;
}
if ( F_120 ( V_131 + V_213 , V_132 ) ) {
F_124 ( V_2 , L_77 ) ;
if ( F_67 ( V_2 , NULL ) )
V_305 = V_132 + ( 1 * V_294 ) ;
else
V_305 = V_2 -> V_210 + ( V_2 -> V_298 * V_294 ) ;
} else
V_305 = V_131 + V_213 ;
F_124 ( V_2 , L_78 , V_305 ) ;
F_70 ( & V_2 -> V_212 , V_305 ) ;
V_255:
F_73 ( & V_5 -> V_165 ) ;
}
static void F_125 ( struct V_16 * V_17 ,
struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_81 & V_307 ;
V_15 -> V_38 |= V_39 ;
V_15 -> V_29 = V_17 -> V_29 ;
V_15 -> V_82 = V_17 -> V_31 ;
V_15 -> V_308 = V_17 -> V_107 ;
}
int F_126 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_67 * V_15 ;
int V_90 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_104 ( V_5 , L_79 , V_48 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_48 -> V_120 . V_121 ) {
F_104 ( V_5 , L_80
L_81 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_309 ;
}
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 ||
V_48 -> V_120 . V_242 != V_5 -> V_90 ) {
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
F_104 ( V_5 , L_82
L_83 ) ;
return V_310 ;
}
V_2 = V_5 -> V_245 ;
V_2 -> V_311 ++ ;
V_90 = V_5 -> V_90 ;
V_17 = (struct V_16 * ) V_48 -> V_120 . V_121 ;
F_104 ( V_5 , L_84 ,
V_48 , V_17 -> V_30 ) ;
if ( ! V_17 -> V_48 ) {
F_104 ( V_5 , L_85 ) ;
goto V_312;
}
if ( V_17 -> V_110 == V_134 ) {
F_48 ( V_17 , V_261 ) ;
goto V_312;
}
if ( V_2 -> V_71 != V_72 )
goto V_313;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_125 ( V_17 , V_15 ) ;
if ( F_105 ( V_2 , V_15 , V_90 , V_5 -> V_314 ) )
goto V_313;
switch ( V_2 -> V_71 ) {
case V_204 :
F_42 ( & V_5 -> V_165 ) ;
F_115 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
F_48 ( V_17 , V_261 ) ;
V_2 -> V_71 = V_72 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_42 ( & V_5 -> V_165 ) ;
F_117 ( V_2 ) ;
goto V_315;
case V_289 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_316 ) ;
goto V_317;
case V_206 :
if ( ! V_48 -> V_120 . V_121 ) {
V_2 -> V_71 = V_72 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_104 ( V_5 , L_86
L_12 ) ;
goto V_312;
}
default:
V_2 -> V_71 = V_72 ;
goto V_313;
}
V_312:
F_42 ( & V_5 -> V_165 ) ;
V_315:
F_104 ( V_5 , L_87 ,
V_48 , V_17 -> V_30 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_309 ;
V_313:
F_42 ( & V_5 -> V_165 ) ;
V_317:
F_104 ( V_5 , L_88 , V_48 ,
V_17 ? V_17 -> V_30 : 0 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_310 ;
}
static void F_127 ( struct V_46 * V_48 , struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_75 & V_307 ;
V_15 -> V_38 |= V_39 ;
F_28 ( V_48 -> V_76 -> V_29 , & V_15 -> V_29 ) ;
V_15 -> V_82 = V_146 ;
}
int F_128 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_67 * V_15 ;
int V_54 = V_310 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_104 ( V_5 , L_89 , V_48 ,
V_48 -> V_76 -> V_29 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 )
goto V_318;
V_2 = V_5 -> V_245 ;
if ( V_2 -> V_71 != V_72 )
goto V_318;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_127 ( V_48 , V_15 ) ;
if ( F_105 ( V_2 , V_15 , V_5 -> V_90 ,
V_5 -> V_319 ) ) {
V_54 = V_310 ;
goto V_318;
}
switch ( V_2 -> V_71 ) {
case V_204 :
break;
case V_289 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_316 ) ;
goto V_255;
default:
V_2 -> V_71 = V_72 ;
goto V_318;
}
V_54 = V_309 ;
F_42 ( & V_5 -> V_165 ) ;
F_115 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_113 ( V_2 , V_48 -> V_76 -> V_29 , V_184 ) ;
V_2 -> V_71 = V_72 ;
F_42 ( & V_5 -> V_165 ) ;
F_117 ( V_2 ) ;
goto V_255;
V_318:
F_42 ( & V_5 -> V_165 ) ;
V_255:
F_104 ( V_5 , L_90 ,
V_54 == V_309 ? L_91 : L_92 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_54 ;
}
void F_129 ( struct V_267 * V_268 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 != V_156 ) {
V_5 -> V_110 = V_273 ;
if ( V_5 -> V_245 )
F_66 ( & V_5 -> V_245 -> V_208 ) ;
}
F_42 ( & V_5 -> V_165 ) ;
}
int F_130 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
V_2 = V_5 -> V_245 ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 == V_153 ) {
V_313:
F_104 ( V_5 ,
L_93
L_94 , V_5 -> V_320 ,
V_2 -> V_321 , V_5 -> V_90 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_310 ;
}
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
F_85 ( V_2 , V_316 ) ;
F_104 ( V_5 , L_95 ) ;
F_108 ( V_2 -> V_208 ,
V_5 -> V_110 == V_153 ||
V_5 -> V_110 == V_156 ||
V_5 -> V_110 == V_273 ) ;
if ( F_109 ( V_297 ) )
F_110 ( V_297 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 == V_156 ) {
F_104 ( V_5 ,
L_96 ,
V_5 -> V_320 , V_2 -> V_321 ) ;
} else
goto V_313;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_309 ;
}
static void F_131 ( struct V_46 * V_48 , struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_77 & V_307 ;
V_15 -> V_38 |= V_39 ;
V_15 -> V_82 = V_146 ;
}
static int F_132 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_67 * V_15 ;
int V_54 = V_310 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_104 ( V_5 , L_97 , V_48 ,
V_5 -> V_320 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 )
goto V_318;
V_2 = V_5 -> V_245 ;
if ( V_2 -> V_71 != V_72 )
goto V_318;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_131 ( V_48 , V_15 ) ;
if ( F_105 ( V_2 , V_15 , V_5 -> V_90 ,
V_5 -> V_322 ) ) {
V_54 = V_310 ;
goto V_318;
}
switch ( V_2 -> V_71 ) {
case V_204 :
break;
case V_289 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_316 ) ;
goto V_255;
default:
V_2 -> V_71 = V_72 ;
goto V_318;
}
V_54 = V_309 ;
F_42 ( & V_5 -> V_165 ) ;
F_115 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_113 ( V_2 , - 1 , V_184 ) ;
V_2 -> V_71 = V_72 ;
F_42 ( & V_5 -> V_165 ) ;
F_117 ( V_2 ) ;
goto V_255;
V_318:
F_42 ( & V_5 -> V_165 ) ;
V_255:
F_104 ( V_5 , L_98 , V_5 -> V_320 ,
V_54 == V_309 ? L_91 : L_92 ) ;
F_107 ( & V_5 -> V_296 ) ;
return V_54 ;
}
int F_133 ( struct V_46 * V_48 )
{
int V_54 ;
V_54 = F_132 ( V_48 ) ;
if ( V_54 == V_310 )
V_54 = F_130 ( V_48 ) ;
return V_54 ;
}
int
F_134 ( struct V_323 * V_324 , int V_325 , void * * * V_326 , int V_327 )
{
int V_222 , V_328 = 1 ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
V_324 -> V_325 = V_325 ;
if ( V_326 )
V_328 ++ ;
V_324 -> V_329 = F_135 ( V_328 * V_325 * sizeof( void * ) , V_330 ) ;
if ( V_324 -> V_329 == NULL )
return - V_260 ;
F_136 ( & V_324 -> V_119 , ( void * ) V_324 -> V_329 , V_325 * sizeof( void * ) ) ;
for ( V_222 = 0 ; V_222 < V_325 ; V_222 ++ ) {
V_324 -> V_329 [ V_222 ] = F_135 ( V_327 , V_330 ) ;
if ( V_324 -> V_329 [ V_222 ] == NULL ) {
V_324 -> V_325 = V_222 ;
goto V_331;
}
F_35 ( & V_324 -> V_119 , ( void * ) & V_324 -> V_329 [ V_222 ] , sizeof( void * ) ) ;
}
if ( V_326 ) {
* V_326 = V_324 -> V_329 + V_325 ;
memcpy ( * V_326 , V_324 -> V_329 , V_325 * sizeof( void * ) ) ;
}
return 0 ;
V_331:
F_137 ( V_324 ) ;
return - V_260 ;
}
void F_137 ( struct V_323 * V_324 )
{
int V_222 ;
for ( V_222 = 0 ; V_222 < V_324 -> V_325 ; V_222 ++ )
F_138 ( V_324 -> V_329 [ V_222 ] ) ;
F_138 ( V_324 -> V_329 ) ;
}
int F_139 ( struct V_3 * V_4 , struct V_76 * V_332 )
{
if ( ! V_4 -> V_287 )
V_4 -> V_287 = V_333 ;
if ( ! V_4 -> V_334 )
V_4 -> V_334 = V_335 ;
if ( ! V_4 -> V_336 -> V_337 )
V_4 -> V_336 -> V_337 = F_121 ;
return F_140 ( V_4 , V_332 ) ;
}
struct V_3 * F_141 ( struct V_338 * V_339 ,
int V_340 , bool V_341 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
V_4 = F_142 ( V_339 , sizeof( struct V_7 ) + V_340 ) ;
if ( ! V_4 )
return NULL ;
V_8 = F_2 ( V_4 ) ;
if ( V_341 ) {
snprintf ( V_8 -> V_342 , sizeof( V_8 -> V_342 ) ,
L_99 , V_4 -> V_343 ) ;
V_8 -> V_9 = F_143 ( V_8 -> V_342 ) ;
if ( ! V_8 -> V_9 )
goto V_344;
}
F_144 ( & V_8 -> V_345 ) ;
V_8 -> V_110 = V_346 ;
V_8 -> V_347 = 0 ;
F_145 ( & V_8 -> V_348 ) ;
return V_4 ;
V_344:
F_146 ( V_4 ) ;
return NULL ;
}
static void F_147 ( struct V_267 * V_268 )
{
F_82 ( V_268 -> V_164 , V_246 ) ;
}
void F_148 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned long V_38 ;
F_149 ( & V_8 -> V_345 , V_38 ) ;
V_8 -> V_110 = V_349 ;
F_150 ( & V_8 -> V_345 , V_38 ) ;
F_151 ( V_4 , F_147 ) ;
F_108 ( V_8 -> V_348 ,
V_8 -> V_347 == 0 ) ;
if ( F_109 ( V_297 ) )
F_110 ( V_297 ) ;
F_152 ( V_4 ) ;
if ( V_8 -> V_9 )
F_153 ( V_8 -> V_9 ) ;
}
void F_154 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_138 ( V_8 -> V_350 ) ;
F_138 ( V_8 -> V_351 ) ;
F_138 ( V_8 -> V_352 ) ;
F_146 ( V_4 ) ;
}
static void F_155 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned long V_38 ;
V_4 = F_156 ( V_4 ) ;
if ( ! V_4 ) {
F_157 ( V_154 L_100
L_101
L_102 ) ;
return;
}
F_149 ( & V_8 -> V_345 , V_38 ) ;
V_8 -> V_347 -- ;
if ( V_8 -> V_347 == 0 )
F_66 ( & V_8 -> V_348 ) ;
F_150 ( & V_8 -> V_345 , V_38 ) ;
F_146 ( V_4 ) ;
}
struct V_267 *
F_158 ( struct V_353 * V_354 , struct V_3 * V_4 ,
T_7 V_223 , int V_355 , int V_356 ,
T_1 V_357 , unsigned int V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_11 * V_5 ;
struct V_267 * V_268 ;
int V_358 , V_359 , V_360 = V_223 ;
unsigned long V_38 ;
F_149 ( & V_8 -> V_345 , V_38 ) ;
if ( V_8 -> V_110 == V_349 ) {
F_150 ( & V_8 -> V_345 , V_38 ) ;
return NULL ;
}
V_8 -> V_347 ++ ;
F_150 ( & V_8 -> V_345 , V_38 ) ;
if ( ! V_360 )
V_360 = V_333 ;
if ( V_360 < V_361 ) {
F_157 ( V_154 L_103
L_104 ,
V_360 , V_361 ) ;
goto V_362;
}
if ( V_360 > V_363 ) {
F_157 ( V_154 L_103
L_105 ,
V_223 , V_363 ) ;
V_360 = V_363 ;
}
if ( ! F_159 ( V_360 ) ) {
F_157 ( V_154 L_103
L_106 , V_360 ) ;
V_360 = F_160 ( V_360 ) ;
if ( V_360 < V_361 )
return NULL ;
F_157 ( V_78 L_107 ,
V_360 ) ;
}
V_359 = V_360 - V_364 ;
V_268 = F_161 ( V_4 , V_354 ,
sizeof( struct V_11 ) +
V_355 ) ;
if ( ! V_268 )
goto V_362;
V_5 = V_268 -> V_164 ;
V_5 -> V_268 = V_268 ;
V_5 -> V_6 = V_4 ;
V_5 -> V_110 = V_365 ;
V_5 -> V_80 = 1 ;
V_5 -> V_322 = 30 ;
V_5 -> V_319 = 15 ;
V_5 -> V_314 = 10 ;
V_5 -> V_288 = V_359 ;
V_5 -> V_223 = V_360 ;
V_5 -> V_135 = V_5 -> V_107 = V_357 ;
V_5 -> V_12 = V_357 + 1 ;
V_5 -> V_13 = V_357 + 1 ;
V_5 -> V_366 = 1 ;
V_5 -> V_87 = V_354 ;
V_5 -> V_164 = V_268 -> V_164 + sizeof( * V_5 ) ;
F_162 ( & V_5 -> V_296 ) ;
F_144 ( & V_5 -> V_165 ) ;
F_144 ( & V_5 -> V_125 ) ;
if ( F_134 ( & V_5 -> V_118 , V_5 -> V_223 ,
( void * * * ) & V_5 -> V_224 ,
V_356 + sizeof( struct V_16 ) ) )
goto V_367;
for ( V_358 = 0 ; V_358 < V_5 -> V_223 ; V_358 ++ ) {
struct V_16 * V_17 = V_5 -> V_224 [ V_358 ] ;
if ( V_356 )
V_17 -> V_164 = & V_17 [ 1 ] ;
V_17 -> V_30 = V_358 ;
V_17 -> V_110 = V_116 ;
F_56 ( & V_17 -> V_129 ) ;
}
if ( ! F_163 ( V_354 -> V_368 ) )
goto V_369;
if ( F_164 ( V_268 , V_113 ) )
goto V_370;
return V_268 ;
V_370:
F_165 ( V_354 -> V_368 ) ;
V_369:
F_137 ( & V_5 -> V_118 ) ;
V_367:
F_166 ( V_268 ) ;
V_362:
F_155 ( V_4 ) ;
return NULL ;
}
void F_167 ( struct V_267 * V_268 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_371 * V_368 = V_268 -> V_372 -> V_368 ;
struct V_3 * V_4 = V_5 -> V_6 ;
F_137 ( & V_5 -> V_118 ) ;
F_138 ( V_5 -> V_373 ) ;
F_138 ( V_5 -> V_374 ) ;
F_138 ( V_5 -> V_375 ) ;
F_138 ( V_5 -> V_376 ) ;
F_138 ( V_5 -> V_320 ) ;
F_138 ( V_5 -> V_377 ) ;
F_138 ( V_5 -> V_352 ) ;
F_138 ( V_5 -> V_378 ) ;
F_138 ( V_5 -> V_379 ) ;
F_138 ( V_5 -> V_380 ) ;
F_138 ( V_5 -> V_381 ) ;
F_138 ( V_5 -> V_382 ) ;
F_138 ( V_5 -> V_383 ) ;
F_168 ( V_268 ) ;
F_155 ( V_4 ) ;
F_165 ( V_368 ) ;
}
struct V_162 *
F_169 ( struct V_267 * V_268 , int V_355 ,
T_1 V_384 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
char * V_151 ;
V_163 = F_170 ( V_268 , sizeof( * V_2 ) + V_355 ,
V_384 ) ;
if ( ! V_163 )
return NULL ;
V_2 = V_163 -> V_164 ;
memset ( V_2 , 0 , sizeof( * V_2 ) + V_355 ) ;
V_2 -> V_164 = V_163 -> V_164 + sizeof( * V_2 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_163 = V_163 ;
V_2 -> V_147 = V_157 ;
V_2 -> V_113 = V_384 ;
V_2 -> V_32 = 0 ;
V_2 -> V_71 = V_72 ;
F_171 ( & V_2 -> V_212 ) ;
V_2 -> V_212 . V_151 = ( unsigned long ) V_2 ;
V_2 -> V_212 . V_295 = F_123 ;
F_56 ( & V_2 -> V_161 ) ;
F_56 ( & V_2 -> V_258 ) ;
F_56 ( & V_2 -> V_254 ) ;
F_172 ( & V_2 -> V_10 , F_95 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! F_54 ( & V_5 -> V_118 . V_119 ,
( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ) {
F_42 ( & V_5 -> V_165 ) ;
goto V_385;
}
F_42 ( & V_5 -> V_165 ) ;
V_151 = ( char * ) F_173 ( V_330 ,
F_174 ( V_155 ) ) ;
if ( ! V_151 )
goto V_386;
V_2 -> V_117 -> V_151 = V_2 -> V_151 = V_151 ;
F_171 ( & V_2 -> V_292 ) ;
F_145 ( & V_2 -> V_208 ) ;
return V_163 ;
V_386:
F_35 ( & V_5 -> V_118 . V_119 , ( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ;
V_385:
F_175 ( V_163 ) ;
return NULL ;
}
void F_176 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
F_111 ( & V_2 -> V_212 ) ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_387 ;
if ( V_5 -> V_245 == V_2 ) {
V_5 -> V_110 = V_153 ;
F_66 ( & V_2 -> V_208 ) ;
}
F_42 ( & V_5 -> V_165 ) ;
F_115 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
F_177 ( ( unsigned long ) V_2 -> V_151 ,
F_174 ( V_155 ) ) ;
F_138 ( V_2 -> V_321 ) ;
F_138 ( V_2 -> V_388 ) ;
F_41 ( & V_5 -> V_125 ) ;
F_35 ( & V_5 -> V_118 . V_119 , ( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ;
F_42 ( & V_5 -> V_125 ) ;
if ( V_5 -> V_245 == V_2 )
V_5 -> V_245 = NULL ;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
F_175 ( V_163 ) ;
}
int F_178 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
if ( ! V_5 ) {
F_25 ( V_154 , V_2 ,
L_108 ) ;
return - V_166 ;
}
if ( ( V_5 -> V_101 || ! V_5 -> V_103 ) &&
V_5 -> V_102 > V_5 -> V_389 ) {
F_25 ( V_78 , V_2 , L_109
L_110 ,
V_5 -> V_102 , V_5 -> V_389 ) ;
return - V_44 ;
}
if ( V_2 -> V_298 && ! V_2 -> V_213 ) {
F_25 ( V_154 , V_2 , L_111
L_112 ) ;
V_2 -> V_213 = 5 ;
}
if ( V_2 -> V_213 && ! V_2 -> V_298 ) {
F_25 ( V_154 , V_2 , L_113
L_114 ) ;
V_2 -> V_298 = 5 ;
}
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_148 ;
V_5 -> V_110 = V_156 ;
V_5 -> V_135 = V_5 -> V_107 ;
V_2 -> V_131 = V_132 ;
V_2 -> V_210 = V_132 ;
if ( V_2 -> V_213 && V_2 -> V_298 )
F_70 ( & V_2 -> V_212 ,
V_132 + ( V_2 -> V_213 * V_294 ) ) ;
switch( V_2 -> V_248 ) {
case V_390 :
V_2 -> V_248 = 0 ;
V_2 -> V_71 = V_72 ;
V_5 -> V_90 ++ ;
if ( V_5 -> V_90 == 16 )
V_5 -> V_90 = 0 ;
break;
case V_391 :
V_2 -> V_248 = 0 ;
break;
default:
break;
}
F_42 ( & V_5 -> V_165 ) ;
F_179 ( V_5 -> V_268 ) ;
F_66 ( & V_2 -> V_208 ) ;
return 0 ;
}
static void
F_180 ( struct V_11 * V_5 , struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_222 , V_110 ;
for ( V_222 = 0 ; V_222 < V_2 -> V_5 -> V_223 ; V_222 ++ ) {
V_17 = V_2 -> V_5 -> V_224 [ V_222 ] ;
if ( V_17 -> V_48 )
continue;
if ( V_17 -> V_110 == V_116 )
continue;
F_18 ( V_2 -> V_5 ,
L_115 ,
V_17 -> V_30 , V_17 -> V_110 ) ;
V_110 = V_128 ;
if ( V_17 -> V_110 == V_134 )
V_110 = V_126 ;
F_43 ( V_17 , V_110 ) ;
}
}
static void F_181 ( struct V_11 * V_5 ,
struct V_1 * V_2 , int V_392 )
{
int V_393 ;
F_112 ( & V_5 -> V_296 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_2 -> V_248 == V_391 ) {
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
return;
}
if ( V_392 == V_391 )
V_5 -> V_110 = V_153 ;
else if ( V_2 -> V_248 != V_390 )
V_5 -> V_110 = V_270 ;
V_393 = V_2 -> V_248 ;
V_2 -> V_248 = V_392 ;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_2 -> V_212 ) ;
F_115 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_158 ;
F_42 ( & V_5 -> V_165 ) ;
if ( V_392 == V_390 ) {
V_2 -> V_394 = 0 ;
V_2 -> V_395 = 0 ;
if ( V_5 -> V_110 == V_270 &&
V_393 != V_390 ) {
F_18 ( V_5 , L_116 ) ;
F_182 ( V_5 -> V_268 ) ;
}
}
F_41 ( & V_5 -> V_165 ) ;
F_113 ( V_2 , - 1 , V_136 ) ;
F_180 ( V_5 , V_2 ) ;
memset ( & V_2 -> V_69 , 0 , sizeof( V_2 -> V_69 ) ) ;
F_42 ( & V_5 -> V_165 ) ;
F_107 ( & V_5 -> V_296 ) ;
}
void F_183 ( struct V_162 * V_163 , int V_392 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
switch ( V_392 ) {
case V_390 :
case V_391 :
F_181 ( V_5 , V_2 , V_392 ) ;
break;
default:
F_25 ( V_154 , V_2 ,
L_117 , V_392 ) ;
}
}
int F_184 ( struct V_267 * V_268 ,
struct V_162 * V_163 , int V_396 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_1 * V_2 = V_163 -> V_164 ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_396 )
V_5 -> V_245 = V_2 ;
F_42 ( & V_5 -> V_165 ) ;
F_118 ( V_249 , & V_2 -> V_251 ) ;
F_118 ( V_249 , & V_2 -> V_250 ) ;
return 0 ;
}
int F_185 ( char * * V_397 , char * V_398 )
{
char * V_399 ;
if ( * V_397 ) {
if ( ! strcmp ( * V_397 , V_398 ) )
return 0 ;
}
V_399 = F_186 ( V_398 , V_400 ) ;
if ( ! V_399 )
return - V_260 ;
F_138 ( * V_397 ) ;
* V_397 = V_399 ;
return 0 ;
}
int F_187 ( struct V_162 * V_163 ,
enum V_401 V_397 , char * V_402 , int V_403 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
int V_404 ;
switch( V_397 ) {
case V_405 :
sscanf ( V_402 , L_118 , & V_5 -> V_80 ) ;
break;
case V_406 :
sscanf ( V_402 , L_118 , & V_5 -> V_314 ) ;
break;
case V_407 :
sscanf ( V_402 , L_118 , & V_5 -> V_319 ) ;
break;
case V_408 :
sscanf ( V_402 , L_118 , & V_5 -> V_322 ) ;
break;
case V_409 :
sscanf ( V_402 , L_118 , & V_2 -> V_298 ) ;
break;
case V_410 :
sscanf ( V_402 , L_118 , & V_2 -> V_213 ) ;
break;
case V_411 :
sscanf ( V_402 , L_118 , & V_2 -> V_412 ) ;
break;
case V_413 :
sscanf ( V_402 , L_118 , & V_2 -> V_35 ) ;
break;
case V_414 :
sscanf ( V_402 , L_118 , & V_2 -> V_394 ) ;
break;
case V_415 :
sscanf ( V_402 , L_118 , & V_2 -> V_395 ) ;
break;
case V_416 :
sscanf ( V_402 , L_118 , & V_5 -> V_103 ) ;
break;
case V_417 :
sscanf ( V_402 , L_119 , & V_5 -> V_366 ) ;
break;
case V_418 :
sscanf ( V_402 , L_118 , & V_5 -> V_101 ) ;
break;
case V_419 :
sscanf ( V_402 , L_118 , & V_5 -> V_102 ) ;
break;
case V_420 :
sscanf ( V_402 , L_118 , & V_5 -> V_389 ) ;
break;
case V_421 :
sscanf ( V_402 , L_118 , & V_5 -> V_422 ) ;
break;
case V_423 :
sscanf ( V_402 , L_118 , & V_5 -> V_424 ) ;
break;
case V_425 :
sscanf ( V_402 , L_118 , & V_5 -> V_426 ) ;
break;
case V_427 :
sscanf ( V_402 , L_120 , & V_2 -> V_32 ) ;
break;
case V_428 :
return F_185 ( & V_5 -> V_375 , V_402 ) ;
case V_429 :
return F_185 ( & V_5 -> V_376 , V_402 ) ;
case V_430 :
return F_185 ( & V_5 -> V_373 , V_402 ) ;
case V_431 :
return F_185 ( & V_5 -> V_374 , V_402 ) ;
case V_432 :
return F_185 ( & V_5 -> V_320 , V_402 ) ;
case V_433 :
return F_185 ( & V_5 -> V_377 , V_402 ) ;
case V_434 :
sscanf ( V_402 , L_118 , & V_5 -> V_435 ) ;
break;
case V_436 :
sscanf ( V_402 , L_118 , & V_2 -> V_437 ) ;
break;
case V_438 :
return F_185 ( & V_2 -> V_321 , V_402 ) ;
case V_439 :
return F_185 ( & V_5 -> V_381 , V_402 ) ;
case V_440 :
return F_185 ( & V_5 -> V_352 , V_402 ) ;
case V_441 :
return F_185 ( & V_5 -> V_378 , V_402 ) ;
case V_442 :
return F_185 ( & V_5 -> V_379 , V_402 ) ;
case V_443 :
return F_185 ( & V_5 -> V_380 , V_402 ) ;
case V_444 :
return F_185 ( & V_5 -> V_382 , V_402 ) ;
case V_445 :
return F_185 ( & V_5 -> V_383 ,
V_402 ) ;
case V_446 :
sscanf ( V_402 , L_118 , & V_404 ) ;
V_5 -> V_447 = ! ! V_404 ;
break;
case V_448 :
return F_185 ( & V_2 -> V_388 , V_402 ) ;
default:
return - V_449 ;
}
return 0 ;
}
int F_188 ( struct V_267 * V_268 ,
enum V_401 V_397 , char * V_402 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
int V_41 ;
switch( V_397 ) {
case V_405 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_80 ) ;
break;
case V_406 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_314 ) ;
break;
case V_407 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_319 ) ;
break;
case V_408 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_322 ) ;
break;
case V_416 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_103 ) ;
break;
case V_417 :
V_41 = sprintf ( V_402 , L_122 , V_5 -> V_366 ) ;
break;
case V_418 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_101 ) ;
break;
case V_419 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_102 ) ;
break;
case V_420 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_389 ) ;
break;
case V_421 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_422 ) ;
break;
case V_423 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_424 ) ;
break;
case V_450 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_451 ) ;
break;
case V_425 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_426 ) ;
break;
case V_432 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_320 ) ;
break;
case V_433 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_377 ) ;
break;
case V_434 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_435 ) ;
break;
case V_428 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_375 ) ;
break;
case V_429 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_376 ) ;
break;
case V_430 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_373 ) ;
break;
case V_431 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_374 ) ;
break;
case V_439 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_381 ) ;
break;
case V_440 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_352 ) ;
break;
case V_441 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_378 ) ;
break;
case V_442 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_379 ) ;
break;
case V_443 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_380 ) ;
break;
case V_452 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_453 ) ;
break;
case V_446 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_447 ) ;
break;
case V_444 :
V_41 = sprintf ( V_402 , L_123 , V_5 -> V_382 ) ;
break;
case V_454 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_455 ) ;
break;
case V_456 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_457 ) ;
break;
case V_458 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_459 ) ;
break;
case V_460 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_461 ) ;
break;
case V_462 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_463 ) ;
break;
case V_464 :
V_41 = sprintf ( V_402 , L_121 , V_5 -> V_465 ) ;
break;
case V_466 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_467 ) ;
break;
case V_468 :
V_41 = sprintf ( V_402 , L_124 ,
V_5 -> V_469 [ 0 ] , V_5 -> V_469 [ 1 ] ,
V_5 -> V_469 [ 2 ] , V_5 -> V_469 [ 3 ] ,
V_5 -> V_469 [ 4 ] , V_5 -> V_469 [ 5 ] ) ;
break;
case V_470 :
V_41 = sprintf ( V_402 , L_3 , V_5 -> V_471 ) ;
break;
case V_445 :
if ( V_5 -> V_383 )
V_41 = sprintf ( V_402 , L_123 ,
V_5 -> V_383 ) ;
else
V_41 = sprintf ( V_402 , L_125 ) ;
break;
default:
return - V_449 ;
}
return V_41 ;
}
int F_189 ( struct V_472 * V_473 ,
enum V_401 V_397 , char * V_402 )
{
struct V_474 * V_475 = NULL ;
struct V_476 * sin = NULL ;
int V_41 ;
switch ( V_473 -> V_477 ) {
case V_478 :
sin = (struct V_476 * ) V_473 ;
break;
case V_479 :
V_475 = (struct V_474 * ) V_473 ;
break;
default:
return - V_44 ;
}
switch ( V_397 ) {
case V_480 :
case V_481 :
if ( sin )
V_41 = sprintf ( V_402 , L_126 , & sin -> V_482 . V_483 ) ;
else
V_41 = sprintf ( V_402 , L_127 , & V_475 -> V_484 ) ;
break;
case V_485 :
case V_486 :
if ( sin )
V_41 = sprintf ( V_402 , L_122 , F_21 ( sin -> V_487 ) ) ;
else
V_41 = sprintf ( V_402 , L_122 ,
F_21 ( V_475 -> V_488 ) ) ;
break;
default:
return - V_44 ;
}
return V_41 ;
}
int F_190 ( struct V_162 * V_163 ,
enum V_401 V_397 , char * V_402 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
int V_41 ;
switch( V_397 ) {
case V_409 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_298 ) ;
break;
case V_410 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_213 ) ;
break;
case V_411 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_412 ) ;
break;
case V_413 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_35 ) ;
break;
case V_414 :
V_41 = sprintf ( V_402 , L_121 , V_2 -> V_394 ) ;
break;
case V_415 :
V_41 = sprintf ( V_402 , L_121 , V_2 -> V_395 ) ;
break;
case V_489 :
V_41 = sprintf ( V_402 , L_121 , V_2 -> V_490 ) ;
break;
case V_491 :
V_41 = sprintf ( V_402 , L_121 , V_2 -> V_492 ) ;
break;
case V_427 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_32 ) ;
break;
case V_436 :
V_41 = sprintf ( V_402 , L_121 , V_2 -> V_437 ) ;
break;
case V_438 :
V_41 = sprintf ( V_402 , L_123 , V_2 -> V_321 ) ;
break;
case V_493 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_170 ) ;
break;
case V_494 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_495 ) ;
break;
case V_496 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_497 ) ;
break;
case V_486 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_498 ) ;
break;
case V_499 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_500 ) ;
break;
case V_501 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_502 ) ;
break;
case V_503 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_504 ) ;
break;
case V_505 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_506 ) ;
break;
case V_507 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_508 ) ;
break;
case V_509 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_510 ) ;
break;
case V_511 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_512 ) ;
break;
case V_513 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_514 ) ;
break;
case V_515 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_516 ) ;
break;
case V_517 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_518 ) ;
break;
case V_519 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_520 ) ;
break;
case V_521 :
V_41 = sprintf ( V_402 , L_3 , V_2 -> V_522 ) ;
break;
case V_448 :
V_41 = sprintf ( V_402 , L_123 , V_2 -> V_388 ) ;
break;
default:
return - V_449 ;
}
return V_41 ;
}
int F_191 ( struct V_3 * V_4 , enum V_523 V_397 ,
char * V_402 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_41 ;
switch ( V_397 ) {
case V_524 :
V_41 = sprintf ( V_402 , L_123 , V_8 -> V_350 ) ;
break;
case V_525 :
V_41 = sprintf ( V_402 , L_123 , V_8 -> V_351 ) ;
break;
case V_526 :
V_41 = sprintf ( V_402 , L_123 , V_8 -> V_352 ) ;
break;
default:
return - V_449 ;
}
return V_41 ;
}
int F_192 ( struct V_3 * V_4 , enum V_523 V_397 ,
char * V_402 , int V_403 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
switch ( V_397 ) {
case V_524 :
return F_185 ( & V_8 -> V_350 , V_402 ) ;
case V_525 :
return F_185 ( & V_8 -> V_351 , V_402 ) ;
case V_526 :
return F_185 ( & V_8 -> V_352 , V_402 ) ;
default:
return - V_449 ;
}
return 0 ;
}
