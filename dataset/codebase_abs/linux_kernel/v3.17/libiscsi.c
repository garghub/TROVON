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
V_48 -> V_178 [ 7 ] = 0xc ;
V_48 -> V_178 [ 8 ] = 0 ;
V_48 -> V_178 [ 9 ] = 0xa ;
V_48 -> V_178 [ 10 ] = 0x80 ;
F_61 ( V_173 , & V_48 -> V_178 [ 12 ] ) ;
goto V_180;
}
}
if ( V_169 -> V_181 != V_182 ) {
V_48 -> V_137 = V_183 << 16 ;
goto V_180;
}
if ( V_169 -> V_172 == V_177 ) {
T_7 V_184 ;
if ( V_167 < 2 ) {
V_185:
F_25 ( V_154 , V_2 ,
L_29
L_30 , V_167 ) ;
V_48 -> V_137 = V_186 << 16 ;
goto V_180;
}
V_184 = F_62 ( V_151 ) ;
if ( V_167 < V_184 )
goto V_185;
memcpy ( V_48 -> V_178 , V_151 + 2 ,
F_63 ( T_7 , V_184 , V_187 ) ) ;
F_18 ( V_5 , L_31 ,
F_63 ( T_7 , V_184 ,
V_187 ) ) ;
}
if ( V_169 -> V_38 & ( V_188 |
V_189 ) ) {
int V_190 = F_7 ( V_169 -> V_191 ) ;
if ( F_29 ( V_48 ) && V_190 > 0 &&
( V_169 -> V_38 & V_189 ||
V_190 <= F_20 ( V_48 ) -> V_66 ) )
F_20 ( V_48 ) -> V_138 = V_190 ;
else
V_48 -> V_137 = ( V_186 << 16 ) | V_169 -> V_172 ;
}
if ( V_169 -> V_38 & ( V_192 |
V_193 ) ) {
int V_190 = F_7 ( V_169 -> V_194 ) ;
if ( V_190 > 0 &&
( V_169 -> V_38 & V_193 ||
V_190 <= F_50 ( V_48 ) ) )
F_49 ( V_48 , V_190 ) ;
else
V_48 -> V_137 = ( V_186 << 16 ) | V_169 -> V_172 ;
}
V_180:
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
V_48 -> V_137 = ( V_186 << 16 ) | V_169 -> V_172 ;
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
if ( V_68 -> V_181 == V_203 )
V_2 -> V_71 = V_204 ;
else if ( V_68 -> V_181 == V_205 )
V_2 -> V_71 = V_206 ;
else
V_2 -> V_71 = V_207 ;
F_66 ( & V_2 -> V_208 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_14 * V_169 )
{
struct V_140 V_15 ;
struct V_16 * V_17 ;
if ( ! V_169 && V_2 -> V_130 )
return;
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
if ( ! V_17 )
F_25 ( V_154 , V_2 , L_35 ) ;
else if ( ! V_169 ) {
V_2 -> V_130 = V_17 ;
V_2 -> V_210 = V_132 ;
}
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
goto V_180;
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
V_180:
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
int F_102 ( struct V_286 * V_287 , int V_288 , int V_218 )
{
switch ( V_218 ) {
case V_289 :
F_103 ( V_287 , F_104 ( V_287 ) , V_288 ) ;
break;
case V_290 :
F_105 ( V_287 , V_288 ) ;
break;
case V_291 :
F_103 ( V_287 , F_104 ( V_287 ) , V_288 ) ;
break;
default:
return - V_292 ;
}
return V_287 -> V_293 ;
}
int F_106 ( struct F_100 * V_294 )
{
struct V_267 * V_268 = F_99 ( V_294 ) ;
struct V_11 * V_5 = V_268 -> V_164 ;
V_294 -> V_295 = V_5 -> V_296 ;
return 0 ;
}
static void F_107 ( unsigned long V_151 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 ;
struct V_11 * V_5 = V_2 -> V_5 ;
F_74 ( & V_5 -> V_165 ) ;
if ( V_2 -> V_71 == V_202 ) {
V_2 -> V_71 = V_297 ;
F_108 ( V_5 , L_57 ) ;
F_66 ( & V_2 -> V_208 ) ;
}
F_73 ( & V_5 -> V_165 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_67 * V_15 , int V_90 ,
int V_298 )
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
V_2 -> V_299 ++ ;
V_2 -> V_300 . V_301 = V_298 * V_302 + V_132 ;
V_2 -> V_300 . V_303 = F_107 ;
V_2 -> V_300 . V_151 = ( unsigned long ) V_2 ;
F_110 ( & V_2 -> V_300 ) ;
F_108 ( V_5 , L_59 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
F_112 ( V_2 -> V_208 , V_90 != V_5 -> V_90 ||
V_5 -> V_110 != V_156 ||
V_2 -> V_71 != V_202 ) ;
if ( F_113 ( V_305 ) )
F_114 ( V_305 ) ;
F_115 ( & V_2 -> V_300 ) ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_90 != V_5 -> V_90 ||
V_5 -> V_110 != V_156 )
return - V_143 ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , T_2 V_29 , int error )
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
void F_118 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_5 -> V_165 ) ;
F_87 ( V_249 , & V_2 -> V_250 ) ;
F_42 ( & V_2 -> V_5 -> V_165 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_87 ( V_249 , & V_2 -> V_250 ) ;
if ( V_8 -> V_9 )
F_120 ( V_8 -> V_9 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_122 ( V_249 , & V_2 -> V_250 ) ;
F_1 ( V_2 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
if ( V_2 -> V_130 &&
F_124 ( V_2 -> V_131 + ( V_2 -> V_213 * V_302 ) +
( V_2 -> V_306 * V_302 ) , V_132 ) )
return 1 ;
else
return 0 ;
}
static enum V_307 F_125 ( struct V_46 * V_48 )
{
enum V_307 V_54 = V_308 ;
struct V_16 * V_17 = NULL , * V_309 ;
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
int V_222 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_108 ( V_5 , L_61 , V_48 ) ;
F_74 ( & V_5 -> V_165 ) ;
V_17 = (struct V_16 * ) V_48 -> V_120 . V_121 ;
if ( ! V_17 ) {
V_54 = V_310 ;
goto V_255;
}
if ( V_5 -> V_110 != V_156 ) {
V_54 = V_311 ;
goto V_255;
}
V_2 = V_5 -> V_245 ;
if ( ! V_2 ) {
V_54 = V_311 ;
goto V_255;
}
if ( F_126 ( V_17 -> V_231 , V_17 -> V_266 ) ) {
F_108 ( V_5 , L_62
L_63
L_64
L_65 , V_17 -> V_231 , V_17 -> V_266 ) ;
V_17 -> V_265 = false ;
V_54 = V_311 ;
goto V_255;
}
if ( ! V_2 -> V_213 && ! V_2 -> V_306 )
goto V_255;
if ( F_123 ( V_2 ) ) {
V_54 = V_311 ;
goto V_255;
}
for ( V_222 = 0 ; V_222 < V_2 -> V_5 -> V_223 ; V_222 ++ ) {
V_309 = V_2 -> V_5 -> V_224 [ V_222 ] ;
if ( ! V_309 -> V_48 || V_309 == V_17 ||
V_309 -> V_110 != V_111 )
continue;
if ( F_126 ( V_309 -> V_48 -> V_312 ,
V_17 -> V_48 -> V_312 ) )
continue;
if ( F_126 ( V_309 -> V_231 , V_17 -> V_266 ) ) {
F_108 ( V_5 , L_66
L_67
L_68
L_69
L_70 ,
V_17 -> V_231 , V_309 -> V_231 ,
V_17 -> V_266 ) ;
V_54 = V_311 ;
goto V_255;
}
}
if ( V_17 -> V_265 )
goto V_255;
if ( V_2 -> V_130 ) {
V_17 -> V_265 = true ;
V_54 = V_311 ;
goto V_255;
}
F_67 ( V_2 , NULL ) ;
V_17 -> V_265 = true ;
V_54 = V_311 ;
V_255:
if ( V_17 )
V_17 -> V_266 = V_132 ;
F_73 ( & V_5 -> V_165 ) ;
F_108 ( V_5 , L_71 , V_54 == V_311 ?
L_72 : L_73 ) ;
return V_54 ;
}
static void F_127 ( unsigned long V_151 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 ;
struct V_11 * V_5 = V_2 -> V_5 ;
unsigned long V_213 , V_313 = 0 , V_131 ;
F_74 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 != V_156 )
goto V_255;
V_213 = V_2 -> V_213 ;
if ( ! V_213 )
goto V_255;
V_213 *= V_302 ;
V_131 = V_2 -> V_131 ;
if ( F_123 ( V_2 ) ) {
F_25 ( V_154 , V_2 , L_74
L_75
L_76 ,
V_2 -> V_306 , V_2 -> V_213 ,
V_131 , V_2 -> V_210 , V_132 ) ;
F_73 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_314 ) ;
return;
}
if ( F_124 ( V_131 + V_213 , V_132 ) ) {
F_128 ( V_2 , L_77 ) ;
F_67 ( V_2 , NULL ) ;
V_313 = V_2 -> V_210 + ( V_2 -> V_306 * V_302 ) ;
} else
V_313 = V_131 + V_213 ;
F_128 ( V_2 , L_78 , V_313 ) ;
F_70 ( & V_2 -> V_212 , V_313 ) ;
V_255:
F_73 ( & V_5 -> V_165 ) ;
}
static void F_129 ( struct V_16 * V_17 ,
struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_81 & V_315 ;
V_15 -> V_38 |= V_39 ;
V_15 -> V_29 = V_17 -> V_29 ;
V_15 -> V_82 = V_17 -> V_31 ;
V_15 -> V_316 = V_17 -> V_107 ;
}
int F_130 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_67 * V_15 ;
int V_54 , V_90 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_108 ( V_5 , L_79 , V_48 ) ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_48 -> V_120 . V_121 ) {
F_108 ( V_5 , L_80
L_81 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_317 ;
}
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 ||
V_48 -> V_120 . V_242 != V_5 -> V_90 ) {
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
F_108 ( V_5 , L_82
L_83 ) ;
return V_318 ;
}
V_2 = V_5 -> V_245 ;
V_2 -> V_319 ++ ;
V_90 = V_5 -> V_90 ;
V_17 = (struct V_16 * ) V_48 -> V_120 . V_121 ;
F_108 ( V_5 , L_84 ,
V_48 , V_17 -> V_30 ) ;
if ( ! V_17 -> V_48 ) {
F_108 ( V_5 , L_85 ) ;
goto V_320;
}
if ( V_17 -> V_110 == V_134 ) {
F_48 ( V_17 , V_261 ) ;
goto V_320;
}
if ( V_2 -> V_71 != V_72 )
goto V_321;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_129 ( V_17 , V_15 ) ;
if ( F_109 ( V_2 , V_15 , V_90 , V_5 -> V_322 ) ) {
V_54 = V_318 ;
goto V_321;
}
switch ( V_2 -> V_71 ) {
case V_204 :
F_42 ( & V_5 -> V_165 ) ;
F_119 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
F_48 ( V_17 , V_261 ) ;
V_2 -> V_71 = V_72 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_42 ( & V_5 -> V_165 ) ;
F_121 ( V_2 ) ;
goto V_323;
case V_297 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_324 ) ;
goto V_325;
case V_206 :
if ( ! V_48 -> V_120 . V_121 ) {
V_2 -> V_71 = V_72 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_108 ( V_5 , L_86
L_12 ) ;
goto V_320;
}
default:
V_2 -> V_71 = V_72 ;
goto V_321;
}
V_320:
F_42 ( & V_5 -> V_165 ) ;
V_323:
F_108 ( V_5 , L_87 ,
V_48 , V_17 -> V_30 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_317 ;
V_321:
F_42 ( & V_5 -> V_165 ) ;
V_325:
F_108 ( V_5 , L_88 , V_48 ,
V_17 ? V_17 -> V_30 : 0 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_318 ;
}
static void F_131 ( struct V_46 * V_48 , struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_75 & V_315 ;
V_15 -> V_38 |= V_39 ;
F_28 ( V_48 -> V_76 -> V_29 , & V_15 -> V_29 ) ;
V_15 -> V_82 = V_146 ;
}
int F_132 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_67 * V_15 ;
int V_54 = V_318 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_108 ( V_5 , L_89 , V_48 ,
V_48 -> V_76 -> V_29 ) ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 )
goto V_326;
V_2 = V_5 -> V_245 ;
if ( V_2 -> V_71 != V_72 )
goto V_326;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_131 ( V_48 , V_15 ) ;
if ( F_109 ( V_2 , V_15 , V_5 -> V_90 ,
V_5 -> V_327 ) ) {
V_54 = V_318 ;
goto V_326;
}
switch ( V_2 -> V_71 ) {
case V_204 :
break;
case V_297 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_324 ) ;
goto V_255;
default:
V_2 -> V_71 = V_72 ;
goto V_326;
}
V_54 = V_317 ;
F_42 ( & V_5 -> V_165 ) ;
F_119 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_117 ( V_2 , V_48 -> V_76 -> V_29 , V_183 ) ;
V_2 -> V_71 = V_72 ;
F_42 ( & V_5 -> V_165 ) ;
F_121 ( V_2 ) ;
goto V_255;
V_326:
F_42 ( & V_5 -> V_165 ) ;
V_255:
F_108 ( V_5 , L_90 ,
V_54 == V_317 ? L_91 : L_92 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_54 ;
}
void F_133 ( struct V_267 * V_268 )
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
int F_134 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
V_2 = V_5 -> V_245 ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 == V_153 ) {
V_321:
F_108 ( V_5 ,
L_93
L_94 , V_5 -> V_328 ,
V_2 -> V_329 , V_5 -> V_90 ) ;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_318 ;
}
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
F_85 ( V_2 , V_324 ) ;
F_108 ( V_5 , L_95 ) ;
F_112 ( V_2 -> V_208 ,
V_5 -> V_110 == V_153 ||
V_5 -> V_110 == V_156 ||
V_5 -> V_110 == V_273 ) ;
if ( F_113 ( V_305 ) )
F_114 ( V_305 ) ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_5 -> V_110 == V_156 ) {
F_108 ( V_5 ,
L_96 ,
V_5 -> V_328 , V_2 -> V_329 ) ;
} else
goto V_321;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_317 ;
}
static void F_135 ( struct V_46 * V_48 , struct V_67 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_27 = V_74 | V_149 ;
V_15 -> V_38 = V_77 & V_315 ;
V_15 -> V_38 |= V_39 ;
V_15 -> V_82 = V_146 ;
}
int F_136 ( struct V_46 * V_48 )
{
struct V_267 * V_268 ;
struct V_11 * V_5 ;
struct V_1 * V_2 ;
struct V_67 * V_15 ;
int V_54 = V_318 ;
V_268 = F_99 ( F_100 ( V_48 -> V_76 ) ) ;
V_5 = V_268 -> V_164 ;
F_108 ( V_5 , L_97 , V_48 ,
V_5 -> V_328 ) ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! V_5 -> V_245 || V_5 -> V_110 != V_156 )
goto V_326;
V_2 = V_5 -> V_245 ;
if ( V_2 -> V_71 != V_72 )
goto V_326;
V_2 -> V_71 = V_202 ;
V_15 = & V_2 -> V_69 ;
F_135 ( V_48 , V_15 ) ;
if ( F_109 ( V_2 , V_15 , V_5 -> V_90 ,
V_5 -> V_330 ) ) {
V_54 = V_318 ;
goto V_326;
}
switch ( V_2 -> V_71 ) {
case V_204 :
break;
case V_297 :
F_42 ( & V_5 -> V_165 ) ;
F_85 ( V_2 , V_324 ) ;
goto V_255;
default:
V_2 -> V_71 = V_72 ;
goto V_326;
}
V_54 = V_317 ;
F_42 ( & V_5 -> V_165 ) ;
F_119 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
F_117 ( V_2 , - 1 , V_183 ) ;
V_2 -> V_71 = V_72 ;
F_42 ( & V_5 -> V_165 ) ;
F_121 ( V_2 ) ;
goto V_255;
V_326:
F_42 ( & V_5 -> V_165 ) ;
V_255:
F_108 ( V_5 , L_98 , V_5 -> V_328 ,
V_54 == V_317 ? L_91 : L_92 ) ;
F_111 ( & V_5 -> V_304 ) ;
return V_54 ;
}
int F_137 ( struct V_46 * V_48 )
{
int V_54 ;
V_54 = F_136 ( V_48 ) ;
if ( V_54 == V_318 )
V_54 = F_134 ( V_48 ) ;
return V_54 ;
}
int
F_138 ( struct V_331 * V_332 , int V_333 , void * * * V_334 , int V_335 )
{
int V_222 , V_336 = 1 ;
memset ( V_332 , 0 , sizeof( * V_332 ) ) ;
V_332 -> V_333 = V_333 ;
if ( V_334 )
V_336 ++ ;
V_332 -> V_337 = F_139 ( V_336 * V_333 * sizeof( void * ) , V_338 ) ;
if ( V_332 -> V_337 == NULL )
return - V_260 ;
F_140 ( & V_332 -> V_119 , ( void * ) V_332 -> V_337 , V_333 * sizeof( void * ) ) ;
for ( V_222 = 0 ; V_222 < V_333 ; V_222 ++ ) {
V_332 -> V_337 [ V_222 ] = F_139 ( V_335 , V_338 ) ;
if ( V_332 -> V_337 [ V_222 ] == NULL ) {
V_332 -> V_333 = V_222 ;
goto V_339;
}
F_35 ( & V_332 -> V_119 , ( void * ) & V_332 -> V_337 [ V_222 ] , sizeof( void * ) ) ;
}
if ( V_334 ) {
* V_334 = V_332 -> V_337 + V_333 ;
memcpy ( * V_334 , V_332 -> V_337 , V_333 * sizeof( void * ) ) ;
}
return 0 ;
V_339:
F_141 ( V_332 ) ;
return - V_260 ;
}
void F_141 ( struct V_331 * V_332 )
{
int V_222 ;
for ( V_222 = 0 ; V_222 < V_332 -> V_333 ; V_222 ++ )
F_142 ( V_332 -> V_337 [ V_222 ] ) ;
F_142 ( V_332 -> V_337 ) ;
}
int F_143 ( struct V_3 * V_4 , struct V_76 * V_340 )
{
if ( ! V_4 -> V_295 )
V_4 -> V_295 = V_341 ;
if ( ! V_4 -> V_342 )
V_4 -> V_342 = V_343 ;
if ( ! V_4 -> V_344 -> V_345 )
V_4 -> V_344 -> V_345 = F_125 ;
return F_144 ( V_4 , V_340 ) ;
}
struct V_3 * F_145 ( struct V_346 * V_347 ,
int V_348 , bool V_349 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
V_4 = F_146 ( V_347 , sizeof( struct V_7 ) + V_348 ) ;
if ( ! V_4 )
return NULL ;
V_8 = F_2 ( V_4 ) ;
if ( V_349 ) {
snprintf ( V_8 -> V_350 , sizeof( V_8 -> V_350 ) ,
L_99 , V_4 -> V_351 ) ;
V_8 -> V_9 = F_147 ( V_8 -> V_350 ) ;
if ( ! V_8 -> V_9 )
goto V_352;
}
F_148 ( & V_8 -> V_353 ) ;
V_8 -> V_110 = V_354 ;
V_8 -> V_355 = 0 ;
F_149 ( & V_8 -> V_356 ) ;
return V_4 ;
V_352:
F_150 ( V_4 ) ;
return NULL ;
}
static void F_151 ( struct V_267 * V_268 )
{
F_82 ( V_268 -> V_164 , V_246 ) ;
}
void F_152 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned long V_38 ;
F_153 ( & V_8 -> V_353 , V_38 ) ;
V_8 -> V_110 = V_357 ;
F_154 ( & V_8 -> V_353 , V_38 ) ;
F_155 ( V_4 , F_151 ) ;
F_112 ( V_8 -> V_356 ,
V_8 -> V_355 == 0 ) ;
if ( F_113 ( V_305 ) )
F_114 ( V_305 ) ;
F_156 ( V_4 ) ;
if ( V_8 -> V_9 )
F_157 ( V_8 -> V_9 ) ;
}
void F_158 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_142 ( V_8 -> V_358 ) ;
F_142 ( V_8 -> V_359 ) ;
F_142 ( V_8 -> V_360 ) ;
F_150 ( V_4 ) ;
}
static void F_159 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned long V_38 ;
V_4 = F_160 ( V_4 ) ;
if ( ! V_4 ) {
F_161 ( V_154 L_100
L_101
L_102 ) ;
return;
}
F_153 ( & V_8 -> V_353 , V_38 ) ;
V_8 -> V_355 -- ;
if ( V_8 -> V_355 == 0 )
F_66 ( & V_8 -> V_356 ) ;
F_154 ( & V_8 -> V_353 , V_38 ) ;
F_150 ( V_4 ) ;
}
struct V_267 *
F_162 ( struct V_361 * V_362 , struct V_3 * V_4 ,
T_7 V_223 , int V_363 , int V_364 ,
T_1 V_365 , unsigned int V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_11 * V_5 ;
struct V_267 * V_268 ;
int V_366 , V_367 , V_368 = V_223 ;
unsigned long V_38 ;
F_153 ( & V_8 -> V_353 , V_38 ) ;
if ( V_8 -> V_110 == V_357 ) {
F_154 ( & V_8 -> V_353 , V_38 ) ;
return NULL ;
}
V_8 -> V_355 ++ ;
F_154 ( & V_8 -> V_353 , V_38 ) ;
if ( ! V_368 )
V_368 = V_341 ;
if ( V_368 < V_369 ) {
F_161 ( V_154 L_103
L_104 ,
V_368 , V_369 ) ;
goto V_370;
}
if ( V_368 > V_371 ) {
F_161 ( V_154 L_103
L_105 ,
V_223 , V_371 ) ;
V_368 = V_371 ;
}
if ( ! F_163 ( V_368 ) ) {
F_161 ( V_154 L_103
L_106 , V_368 ) ;
V_368 = F_164 ( V_368 ) ;
if ( V_368 < V_369 )
return NULL ;
F_161 ( V_78 L_107 ,
V_368 ) ;
}
V_367 = V_368 - V_372 ;
V_268 = F_165 ( V_4 , V_362 ,
sizeof( struct V_11 ) +
V_363 ) ;
if ( ! V_268 )
goto V_370;
V_5 = V_268 -> V_164 ;
V_5 -> V_268 = V_268 ;
V_5 -> V_6 = V_4 ;
V_5 -> V_110 = V_373 ;
V_5 -> V_80 = 1 ;
V_5 -> V_330 = 30 ;
V_5 -> V_327 = 15 ;
V_5 -> V_322 = 10 ;
V_5 -> V_296 = V_367 ;
V_5 -> V_223 = V_368 ;
V_5 -> V_135 = V_5 -> V_107 = V_365 ;
V_5 -> V_12 = V_365 + 1 ;
V_5 -> V_13 = V_365 + 1 ;
V_5 -> V_374 = 1 ;
V_5 -> V_87 = V_362 ;
V_5 -> V_164 = V_268 -> V_164 + sizeof( * V_5 ) ;
F_166 ( & V_5 -> V_304 ) ;
F_148 ( & V_5 -> V_165 ) ;
F_148 ( & V_5 -> V_125 ) ;
if ( F_138 ( & V_5 -> V_118 , V_5 -> V_223 ,
( void * * * ) & V_5 -> V_224 ,
V_364 + sizeof( struct V_16 ) ) )
goto V_375;
for ( V_366 = 0 ; V_366 < V_5 -> V_223 ; V_366 ++ ) {
struct V_16 * V_17 = V_5 -> V_224 [ V_366 ] ;
if ( V_364 )
V_17 -> V_164 = & V_17 [ 1 ] ;
V_17 -> V_30 = V_366 ;
V_17 -> V_110 = V_116 ;
F_56 ( & V_17 -> V_129 ) ;
}
if ( ! F_167 ( V_362 -> V_376 ) )
goto V_377;
if ( F_168 ( V_268 , V_113 ) )
goto V_378;
return V_268 ;
V_378:
F_169 ( V_362 -> V_376 ) ;
V_377:
F_141 ( & V_5 -> V_118 ) ;
V_375:
F_170 ( V_268 ) ;
V_370:
F_159 ( V_4 ) ;
return NULL ;
}
void F_171 ( struct V_267 * V_268 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_379 * V_376 = V_268 -> V_380 -> V_376 ;
struct V_3 * V_4 = V_5 -> V_6 ;
F_141 ( & V_5 -> V_118 ) ;
F_142 ( V_5 -> V_381 ) ;
F_142 ( V_5 -> V_382 ) ;
F_142 ( V_5 -> V_383 ) ;
F_142 ( V_5 -> V_384 ) ;
F_142 ( V_5 -> V_328 ) ;
F_142 ( V_5 -> V_385 ) ;
F_142 ( V_5 -> V_360 ) ;
F_142 ( V_5 -> V_386 ) ;
F_142 ( V_5 -> V_387 ) ;
F_142 ( V_5 -> V_388 ) ;
F_142 ( V_5 -> V_389 ) ;
F_142 ( V_5 -> V_390 ) ;
F_142 ( V_5 -> V_391 ) ;
F_172 ( V_268 ) ;
F_159 ( V_4 ) ;
F_169 ( V_376 ) ;
}
struct V_162 *
F_173 ( struct V_267 * V_268 , int V_363 ,
T_1 V_392 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
char * V_151 ;
V_163 = F_174 ( V_268 , sizeof( * V_2 ) + V_363 ,
V_392 ) ;
if ( ! V_163 )
return NULL ;
V_2 = V_163 -> V_164 ;
memset ( V_2 , 0 , sizeof( * V_2 ) + V_363 ) ;
V_2 -> V_164 = V_163 -> V_164 + sizeof( * V_2 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_163 = V_163 ;
V_2 -> V_147 = V_157 ;
V_2 -> V_113 = V_392 ;
V_2 -> V_32 = 0 ;
V_2 -> V_71 = V_72 ;
F_175 ( & V_2 -> V_212 ) ;
V_2 -> V_212 . V_151 = ( unsigned long ) V_2 ;
V_2 -> V_212 . V_303 = F_127 ;
F_56 ( & V_2 -> V_161 ) ;
F_56 ( & V_2 -> V_258 ) ;
F_56 ( & V_2 -> V_254 ) ;
F_176 ( & V_2 -> V_10 , F_95 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( ! F_54 ( & V_5 -> V_118 . V_119 ,
( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ) {
F_42 ( & V_5 -> V_165 ) ;
goto V_393;
}
F_42 ( & V_5 -> V_165 ) ;
V_151 = ( char * ) F_177 ( V_338 ,
F_178 ( V_155 ) ) ;
if ( ! V_151 )
goto V_394;
V_2 -> V_117 -> V_151 = V_2 -> V_151 = V_151 ;
F_175 ( & V_2 -> V_300 ) ;
F_149 ( & V_2 -> V_208 ) ;
return V_163 ;
V_394:
F_35 ( & V_5 -> V_118 . V_119 , ( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ;
V_393:
F_179 ( V_163 ) ;
return NULL ;
}
void F_180 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
unsigned long V_38 ;
F_115 ( & V_2 -> V_212 ) ;
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_395 ;
if ( V_5 -> V_245 == V_2 ) {
V_5 -> V_110 = V_153 ;
F_66 ( & V_2 -> V_208 ) ;
}
F_42 ( & V_5 -> V_165 ) ;
for (; ; ) {
F_153 ( V_5 -> V_6 -> V_396 , V_38 ) ;
if ( ! F_181 ( & V_5 -> V_6 -> V_397 ) ) {
F_154 ( V_5 -> V_6 -> V_396 , V_38 ) ;
break;
}
F_154 ( V_5 -> V_6 -> V_396 , V_38 ) ;
F_182 ( 500 ) ;
F_25 ( V_78 , V_2 , L_108
L_109 ,
F_181 ( & V_5 -> V_6 -> V_397 ) ,
V_5 -> V_6 -> V_398 ) ;
F_66 ( & V_2 -> V_208 ) ;
}
F_119 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
F_183 ( ( unsigned long ) V_2 -> V_151 ,
F_178 ( V_155 ) ) ;
F_142 ( V_2 -> V_329 ) ;
F_142 ( V_2 -> V_399 ) ;
F_41 ( & V_5 -> V_125 ) ;
F_35 ( & V_5 -> V_118 . V_119 , ( void * ) & V_2 -> V_117 ,
sizeof( void * ) ) ;
F_42 ( & V_5 -> V_125 ) ;
if ( V_5 -> V_245 == V_2 )
V_5 -> V_245 = NULL ;
F_42 ( & V_5 -> V_165 ) ;
F_179 ( V_163 ) ;
}
int F_184 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
if ( ! V_5 ) {
F_25 ( V_154 , V_2 ,
L_110 ) ;
return - V_166 ;
}
if ( ( V_5 -> V_101 || ! V_5 -> V_103 ) &&
V_5 -> V_102 > V_5 -> V_400 ) {
F_25 ( V_78 , V_2 , L_111
L_112 ,
V_5 -> V_102 , V_5 -> V_400 ) ;
return - V_44 ;
}
if ( V_2 -> V_306 && ! V_2 -> V_213 ) {
F_25 ( V_154 , V_2 , L_113
L_114 ) ;
V_2 -> V_213 = 5 ;
}
if ( V_2 -> V_213 && ! V_2 -> V_306 ) {
F_25 ( V_154 , V_2 , L_115
L_116 ) ;
V_2 -> V_306 = 5 ;
}
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_148 ;
V_5 -> V_110 = V_156 ;
V_5 -> V_135 = V_5 -> V_107 ;
V_2 -> V_131 = V_132 ;
V_2 -> V_210 = V_132 ;
if ( V_2 -> V_213 && V_2 -> V_306 )
F_70 ( & V_2 -> V_212 ,
V_132 + ( V_2 -> V_213 * V_302 ) ) ;
switch( V_2 -> V_248 ) {
case V_401 :
V_2 -> V_248 = 0 ;
V_2 -> V_71 = V_72 ;
V_5 -> V_90 ++ ;
if ( V_5 -> V_90 == 16 )
V_5 -> V_90 = 0 ;
break;
case V_402 :
V_2 -> V_248 = 0 ;
break;
default:
break;
}
F_42 ( & V_5 -> V_165 ) ;
F_185 ( V_5 -> V_268 ) ;
F_66 ( & V_2 -> V_208 ) ;
return 0 ;
}
static void
F_186 ( struct V_11 * V_5 , struct V_1 * V_2 )
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
L_117 ,
V_17 -> V_30 , V_17 -> V_110 ) ;
V_110 = V_128 ;
if ( V_17 -> V_110 == V_134 )
V_110 = V_126 ;
F_43 ( V_17 , V_110 ) ;
}
}
static void F_187 ( struct V_11 * V_5 ,
struct V_1 * V_2 , int V_403 )
{
int V_404 ;
F_116 ( & V_5 -> V_304 ) ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_2 -> V_248 == V_402 ) {
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
return;
}
if ( V_403 == V_402 )
V_5 -> V_110 = V_153 ;
else if ( V_2 -> V_248 != V_401 )
V_5 -> V_110 = V_270 ;
V_404 = V_2 -> V_248 ;
V_2 -> V_248 = V_403 ;
F_42 ( & V_5 -> V_165 ) ;
F_115 ( & V_2 -> V_212 ) ;
F_119 ( V_2 ) ;
F_41 ( & V_5 -> V_165 ) ;
V_2 -> V_147 = V_158 ;
F_42 ( & V_5 -> V_165 ) ;
if ( V_403 == V_401 ) {
V_2 -> V_405 = 0 ;
V_2 -> V_406 = 0 ;
if ( V_5 -> V_110 == V_270 &&
V_404 != V_401 ) {
F_18 ( V_5 , L_118 ) ;
F_188 ( V_5 -> V_268 ) ;
}
}
F_41 ( & V_5 -> V_165 ) ;
F_117 ( V_2 , - 1 , V_136 ) ;
F_186 ( V_5 , V_2 ) ;
memset ( & V_2 -> V_69 , 0 , sizeof( V_2 -> V_69 ) ) ;
F_42 ( & V_5 -> V_165 ) ;
F_111 ( & V_5 -> V_304 ) ;
}
void F_189 ( struct V_162 * V_163 , int V_403 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
switch ( V_403 ) {
case V_401 :
case V_402 :
F_187 ( V_5 , V_2 , V_403 ) ;
break;
default:
F_25 ( V_154 , V_2 ,
L_119 , V_403 ) ;
}
}
int F_190 ( struct V_267 * V_268 ,
struct V_162 * V_163 , int V_407 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
struct V_1 * V_2 = V_163 -> V_164 ;
F_41 ( & V_5 -> V_165 ) ;
if ( V_407 )
V_5 -> V_245 = V_2 ;
F_42 ( & V_5 -> V_165 ) ;
F_122 ( V_249 , & V_2 -> V_251 ) ;
F_122 ( V_249 , & V_2 -> V_250 ) ;
return 0 ;
}
int F_191 ( char * * V_408 , char * V_409 )
{
char * V_410 ;
if ( * V_408 ) {
if ( ! strcmp ( * V_408 , V_409 ) )
return 0 ;
}
V_410 = F_192 ( V_409 , V_411 ) ;
if ( ! V_410 )
return - V_260 ;
F_142 ( * V_408 ) ;
* V_408 = V_410 ;
return 0 ;
}
int F_193 ( struct V_162 * V_163 ,
enum V_412 V_408 , char * V_413 , int V_414 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
struct V_11 * V_5 = V_2 -> V_5 ;
int V_415 ;
switch( V_408 ) {
case V_416 :
sscanf ( V_413 , L_120 , & V_5 -> V_80 ) ;
break;
case V_417 :
sscanf ( V_413 , L_120 , & V_5 -> V_322 ) ;
break;
case V_418 :
sscanf ( V_413 , L_120 , & V_5 -> V_327 ) ;
break;
case V_419 :
sscanf ( V_413 , L_120 , & V_5 -> V_330 ) ;
break;
case V_420 :
sscanf ( V_413 , L_120 , & V_2 -> V_306 ) ;
break;
case V_421 :
sscanf ( V_413 , L_120 , & V_2 -> V_213 ) ;
break;
case V_422 :
sscanf ( V_413 , L_120 , & V_2 -> V_423 ) ;
break;
case V_424 :
sscanf ( V_413 , L_120 , & V_2 -> V_35 ) ;
break;
case V_425 :
sscanf ( V_413 , L_120 , & V_2 -> V_405 ) ;
break;
case V_426 :
sscanf ( V_413 , L_120 , & V_2 -> V_406 ) ;
break;
case V_427 :
sscanf ( V_413 , L_120 , & V_5 -> V_103 ) ;
break;
case V_428 :
sscanf ( V_413 , L_121 , & V_5 -> V_374 ) ;
break;
case V_429 :
sscanf ( V_413 , L_120 , & V_5 -> V_101 ) ;
break;
case V_430 :
sscanf ( V_413 , L_120 , & V_5 -> V_102 ) ;
break;
case V_431 :
sscanf ( V_413 , L_120 , & V_5 -> V_400 ) ;
break;
case V_432 :
sscanf ( V_413 , L_120 , & V_5 -> V_433 ) ;
break;
case V_434 :
sscanf ( V_413 , L_120 , & V_5 -> V_435 ) ;
break;
case V_436 :
sscanf ( V_413 , L_120 , & V_5 -> V_437 ) ;
break;
case V_438 :
sscanf ( V_413 , L_122 , & V_2 -> V_32 ) ;
break;
case V_439 :
return F_191 ( & V_5 -> V_383 , V_413 ) ;
case V_440 :
return F_191 ( & V_5 -> V_384 , V_413 ) ;
case V_441 :
return F_191 ( & V_5 -> V_381 , V_413 ) ;
case V_442 :
return F_191 ( & V_5 -> V_382 , V_413 ) ;
case V_443 :
return F_191 ( & V_5 -> V_328 , V_413 ) ;
case V_444 :
return F_191 ( & V_5 -> V_385 , V_413 ) ;
case V_445 :
sscanf ( V_413 , L_120 , & V_5 -> V_446 ) ;
break;
case V_447 :
sscanf ( V_413 , L_120 , & V_2 -> V_448 ) ;
break;
case V_449 :
return F_191 ( & V_2 -> V_329 , V_413 ) ;
case V_450 :
return F_191 ( & V_5 -> V_389 , V_413 ) ;
case V_451 :
return F_191 ( & V_5 -> V_360 , V_413 ) ;
case V_452 :
return F_191 ( & V_5 -> V_386 , V_413 ) ;
case V_453 :
return F_191 ( & V_5 -> V_387 , V_413 ) ;
case V_454 :
return F_191 ( & V_5 -> V_388 , V_413 ) ;
case V_455 :
return F_191 ( & V_5 -> V_390 , V_413 ) ;
case V_456 :
return F_191 ( & V_5 -> V_391 ,
V_413 ) ;
case V_457 :
sscanf ( V_413 , L_120 , & V_415 ) ;
V_5 -> V_458 = ! ! V_415 ;
break;
case V_459 :
return F_191 ( & V_2 -> V_399 , V_413 ) ;
default:
return - V_460 ;
}
return 0 ;
}
int F_194 ( struct V_267 * V_268 ,
enum V_412 V_408 , char * V_413 )
{
struct V_11 * V_5 = V_268 -> V_164 ;
int V_41 ;
switch( V_408 ) {
case V_416 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_80 ) ;
break;
case V_417 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_322 ) ;
break;
case V_418 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_327 ) ;
break;
case V_419 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_330 ) ;
break;
case V_427 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_103 ) ;
break;
case V_428 :
V_41 = sprintf ( V_413 , L_124 , V_5 -> V_374 ) ;
break;
case V_429 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_101 ) ;
break;
case V_430 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_102 ) ;
break;
case V_431 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_400 ) ;
break;
case V_432 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_433 ) ;
break;
case V_434 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_435 ) ;
break;
case V_461 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_462 ) ;
break;
case V_436 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_437 ) ;
break;
case V_443 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_328 ) ;
break;
case V_444 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_385 ) ;
break;
case V_445 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_446 ) ;
break;
case V_439 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_383 ) ;
break;
case V_440 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_384 ) ;
break;
case V_441 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_381 ) ;
break;
case V_442 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_382 ) ;
break;
case V_450 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_389 ) ;
break;
case V_451 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_360 ) ;
break;
case V_452 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_386 ) ;
break;
case V_453 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_387 ) ;
break;
case V_454 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_388 ) ;
break;
case V_463 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_464 ) ;
break;
case V_457 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_458 ) ;
break;
case V_455 :
V_41 = sprintf ( V_413 , L_125 , V_5 -> V_390 ) ;
break;
case V_465 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_466 ) ;
break;
case V_467 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_468 ) ;
break;
case V_469 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_470 ) ;
break;
case V_471 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_472 ) ;
break;
case V_473 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_474 ) ;
break;
case V_475 :
V_41 = sprintf ( V_413 , L_123 , V_5 -> V_476 ) ;
break;
case V_477 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_478 ) ;
break;
case V_479 :
V_41 = sprintf ( V_413 , L_126 ,
V_5 -> V_480 [ 0 ] , V_5 -> V_480 [ 1 ] ,
V_5 -> V_480 [ 2 ] , V_5 -> V_480 [ 3 ] ,
V_5 -> V_480 [ 4 ] , V_5 -> V_480 [ 5 ] ) ;
break;
case V_481 :
V_41 = sprintf ( V_413 , L_3 , V_5 -> V_482 ) ;
break;
case V_456 :
if ( V_5 -> V_391 )
V_41 = sprintf ( V_413 , L_125 ,
V_5 -> V_391 ) ;
else
V_41 = sprintf ( V_413 , L_127 ) ;
break;
default:
return - V_460 ;
}
return V_41 ;
}
int F_195 ( struct V_483 * V_484 ,
enum V_412 V_408 , char * V_413 )
{
struct V_485 * V_486 = NULL ;
struct V_487 * sin = NULL ;
int V_41 ;
switch ( V_484 -> V_488 ) {
case V_489 :
sin = (struct V_487 * ) V_484 ;
break;
case V_490 :
V_486 = (struct V_485 * ) V_484 ;
break;
default:
return - V_44 ;
}
switch ( V_408 ) {
case V_491 :
case V_492 :
if ( sin )
V_41 = sprintf ( V_413 , L_128 , & sin -> V_493 . V_494 ) ;
else
V_41 = sprintf ( V_413 , L_129 , & V_486 -> V_495 ) ;
break;
case V_496 :
if ( sin )
V_41 = sprintf ( V_413 , L_124 , F_21 ( sin -> V_497 ) ) ;
else
V_41 = sprintf ( V_413 , L_124 ,
F_21 ( V_486 -> V_498 ) ) ;
break;
default:
return - V_44 ;
}
return V_41 ;
}
int F_196 ( struct V_162 * V_163 ,
enum V_412 V_408 , char * V_413 )
{
struct V_1 * V_2 = V_163 -> V_164 ;
int V_41 ;
switch( V_408 ) {
case V_420 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_306 ) ;
break;
case V_421 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_213 ) ;
break;
case V_422 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_423 ) ;
break;
case V_424 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_35 ) ;
break;
case V_425 :
V_41 = sprintf ( V_413 , L_123 , V_2 -> V_405 ) ;
break;
case V_426 :
V_41 = sprintf ( V_413 , L_123 , V_2 -> V_406 ) ;
break;
case V_499 :
V_41 = sprintf ( V_413 , L_123 , V_2 -> V_500 ) ;
break;
case V_501 :
V_41 = sprintf ( V_413 , L_123 , V_2 -> V_502 ) ;
break;
case V_438 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_32 ) ;
break;
case V_447 :
V_41 = sprintf ( V_413 , L_123 , V_2 -> V_448 ) ;
break;
case V_449 :
V_41 = sprintf ( V_413 , L_125 , V_2 -> V_329 ) ;
break;
case V_503 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_170 ) ;
break;
case V_504 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_505 ) ;
break;
case V_506 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_507 ) ;
break;
case V_508 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_509 ) ;
break;
case V_510 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_511 ) ;
break;
case V_512 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_513 ) ;
break;
case V_514 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_515 ) ;
break;
case V_516 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_517 ) ;
break;
case V_518 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_519 ) ;
break;
case V_520 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_521 ) ;
break;
case V_522 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_523 ) ;
break;
case V_524 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_525 ) ;
break;
case V_526 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_527 ) ;
break;
case V_528 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_529 ) ;
break;
case V_530 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_531 ) ;
break;
case V_532 :
V_41 = sprintf ( V_413 , L_3 , V_2 -> V_533 ) ;
break;
case V_459 :
V_41 = sprintf ( V_413 , L_125 , V_2 -> V_399 ) ;
break;
default:
return - V_460 ;
}
return V_41 ;
}
int F_197 ( struct V_3 * V_4 , enum V_534 V_408 ,
char * V_413 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_41 ;
switch ( V_408 ) {
case V_535 :
V_41 = sprintf ( V_413 , L_125 , V_8 -> V_358 ) ;
break;
case V_536 :
V_41 = sprintf ( V_413 , L_125 , V_8 -> V_359 ) ;
break;
case V_537 :
V_41 = sprintf ( V_413 , L_125 , V_8 -> V_360 ) ;
break;
default:
return - V_460 ;
}
return V_41 ;
}
int F_198 ( struct V_3 * V_4 , enum V_534 V_408 ,
char * V_413 , int V_414 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
switch ( V_408 ) {
case V_535 :
return F_191 ( & V_8 -> V_358 , V_413 ) ;
case V_536 :
return F_191 ( & V_8 -> V_359 , V_413 ) ;
case V_537 :
return F_191 ( & V_8 -> V_360 , V_413 ) ;
default:
return - V_460 ;
}
return 0 ;
}
