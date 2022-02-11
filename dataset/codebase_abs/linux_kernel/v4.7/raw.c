int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
struct V_7 * V_8 ;
V_8 = & V_4 -> V_9 [ F_2 ( V_2 ) -> V_10 & ( V_11 - 1 ) ] ;
F_3 ( & V_4 -> V_12 ) ;
F_4 ( V_2 , V_8 ) ;
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
F_3 ( & V_4 -> V_12 ) ;
if ( F_9 ( V_2 ) )
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , - 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
static struct V_1 * F_10 ( struct V_13 * V_13 , struct V_1 * V_2 ,
unsigned short V_14 , T_1 V_15 , T_1 V_16 , int V_17 )
{
F_11 (sk) {
struct V_18 * V_19 = F_2 ( V_2 ) ;
if ( F_12 ( F_6 ( V_2 ) , V_13 ) && V_19 -> V_10 == V_14 &&
! ( V_19 -> V_20 && V_19 -> V_20 != V_15 ) &&
! ( V_19 -> V_21 && V_19 -> V_21 != V_16 ) &&
! ( V_2 -> V_22 && V_2 -> V_22 != V_17 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static int F_13 ( const struct V_1 * V_2 , const struct V_24 * V_25 )
{
struct V_26 V_27 ;
const struct V_26 * V_28 ;
V_28 = F_14 ( V_25 , F_15 ( V_25 ) ,
sizeof( V_27 ) , & V_27 ) ;
if ( ! V_28 )
return 1 ;
if ( V_28 -> type < 32 ) {
T_2 V_29 = F_16 ( V_2 ) -> V_30 . V_29 ;
return ( ( 1U << V_28 -> type ) & V_29 ) != 0 ;
}
return 0 ;
}
static int F_17 ( struct V_24 * V_25 , const struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_34 = 0 ;
struct V_13 * V_13 ;
F_18 ( & V_35 . V_12 ) ;
V_8 = & V_35 . V_9 [ V_33 ] ;
if ( F_19 ( V_8 ) )
goto V_36;
V_13 = F_20 ( V_25 -> V_37 ) ;
V_2 = F_10 ( V_13 , F_21 ( V_8 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_25 -> V_37 -> V_41 ) ;
while ( V_2 ) {
V_34 = 1 ;
if ( ( V_32 -> V_38 != V_42 || ! F_13 ( V_2 , V_25 ) ) &&
F_22 ( V_2 , V_32 -> V_40 , V_32 -> V_39 ,
V_25 -> V_37 -> V_41 ) ) {
struct V_24 * V_43 = F_23 ( V_25 , V_44 ) ;
if ( V_43 )
F_24 ( V_2 , V_43 ) ;
}
V_2 = F_10 ( V_13 , F_25 ( V_2 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_25 -> V_37 -> V_41 ) ;
}
V_36:
F_26 ( & V_35 . V_12 ) ;
return V_34 ;
}
int F_27 ( struct V_24 * V_25 , int V_38 )
{
int V_33 ;
struct V_1 * F_16 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_16 = F_28 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 && ! F_17 ( V_25 , F_29 ( V_25 ) , V_33 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_30 ( struct V_1 * V_2 , struct V_24 * V_25 , T_3 V_45 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
const int type = F_31 ( V_25 ) -> type ;
const int V_46 = F_31 ( V_25 ) -> V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( type == V_49 && V_46 == V_50 )
F_32 ( V_25 , V_2 , V_45 ) ;
else if ( type == V_51 ) {
F_33 ( V_25 , V_2 ) ;
return;
}
if ( ! V_19 -> V_52 && V_2 -> V_53 != V_54 )
return;
switch ( type ) {
default:
case V_55 :
V_47 = V_56 ;
break;
case V_57 :
return;
case V_58 :
V_47 = V_59 ;
V_48 = 1 ;
break;
case V_49 :
V_47 = V_56 ;
if ( V_46 > V_60 )
break;
V_47 = V_61 [ V_46 ] . V_62 ;
V_48 = V_61 [ V_46 ] . V_63 ;
if ( V_46 == V_50 ) {
V_48 = V_19 -> V_64 != V_65 ;
V_47 = V_66 ;
}
}
if ( V_19 -> V_52 ) {
const struct V_31 * V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
T_4 * V_67 = V_25 -> V_29 + ( V_32 -> V_68 << 2 ) ;
if ( V_19 -> V_69 )
V_67 = V_25 -> V_29 ;
F_34 ( V_2 , V_25 , V_47 , 0 , V_45 , V_67 ) ;
}
if ( V_19 -> V_52 || V_48 ) {
V_2 -> V_70 = V_47 ;
V_2 -> V_71 ( V_2 ) ;
}
}
void F_35 ( struct V_24 * V_25 , int V_38 , T_3 V_45 )
{
int V_33 ;
struct V_1 * F_16 ;
const struct V_31 * V_32 ;
struct V_13 * V_13 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_18 ( & V_35 . V_12 ) ;
F_16 = F_28 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 ) {
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
V_13 = F_20 ( V_25 -> V_37 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_38 ,
V_32 -> V_40 , V_32 -> V_39 ,
V_25 -> V_37 -> V_41 ) ) != NULL ) {
F_30 ( F_16 , V_25 , V_45 ) ;
F_16 = F_25 ( F_16 ) ;
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
}
}
F_26 ( & V_35 . V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_37 ( V_2 , V_25 ) ;
if ( F_38 ( V_2 , V_25 ) < 0 ) {
F_39 ( V_25 ) ;
return V_72 ;
}
return V_73 ;
}
int F_24 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( ! F_40 ( V_2 , V_74 , V_25 ) ) {
F_41 ( & V_2 -> V_75 ) ;
F_39 ( V_25 ) ;
return V_72 ;
}
F_42 ( V_25 ) ;
F_43 ( V_25 , V_25 -> V_29 - F_44 ( V_25 ) ) ;
F_36 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_76 * V_77 ,
struct V_78 * V_79 , T_5 V_80 ,
struct V_81 * * V_82 , unsigned int V_83 ,
const struct V_84 * V_85 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_24 * V_25 ;
unsigned int V_86 ;
int V_47 ;
struct V_81 * V_87 = * V_82 ;
int V_88 , V_89 ;
if ( V_80 > V_87 -> V_90 . V_37 -> V_91 ) {
F_46 ( V_2 , V_66 , V_77 -> V_40 , V_19 -> V_92 ,
V_87 -> V_90 . V_37 -> V_91 ) ;
return - V_66 ;
}
if ( V_83 & V_93 )
goto V_36;
V_88 = F_47 ( V_87 -> V_90 . V_37 ) ;
V_89 = V_87 -> V_90 . V_37 -> V_94 ;
V_25 = F_48 ( V_2 ,
V_80 + V_88 + V_89 + 15 ,
V_83 & V_95 , & V_47 ) ;
if ( ! V_25 )
goto error;
F_49 ( V_25 , V_88 ) ;
V_25 -> V_96 = V_2 -> V_97 ;
V_25 -> V_98 = V_2 -> V_99 ;
F_50 ( V_25 , & V_87 -> V_90 ) ;
* V_82 = NULL ;
F_51 ( V_25 ) ;
V_32 = F_29 ( V_25 ) ;
F_52 ( V_25 , V_80 ) ;
V_25 -> V_100 = V_101 ;
F_53 ( V_2 , V_85 -> V_102 , & F_54 ( V_25 ) -> V_103 ) ;
V_25 -> V_104 = V_25 -> V_105 ;
V_47 = - V_106 ;
if ( F_55 ( V_32 , V_79 , V_80 ) )
goto V_107;
V_86 = V_32 -> V_68 * 4 ;
V_47 = - V_108 ;
if ( V_86 > V_80 )
goto V_107;
if ( V_86 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_77 -> V_39 ;
V_32 -> V_109 = 0 ;
V_32 -> V_110 = F_56 ( V_80 ) ;
if ( ! V_32 -> V_111 )
F_57 ( V_13 , V_25 , NULL ) ;
V_32 -> V_109 = F_58 ( ( unsigned char * ) V_32 , V_32 -> V_68 ) ;
V_25 -> V_104 += V_86 ;
if ( V_32 -> V_38 == V_42 &&
V_80 >= V_86 + sizeof( struct V_26 ) )
F_59 ( V_13 , ( (struct V_26 * )
F_60 ( V_25 ) ) -> type ) ;
}
V_47 = F_61 ( V_112 , V_113 ,
V_13 , V_2 , V_25 , NULL , V_87 -> V_90 . V_37 ,
V_114 ) ;
if ( V_47 > 0 )
V_47 = F_62 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_107:
F_39 ( V_25 ) ;
error:
F_63 ( V_13 , V_115 ) ;
if ( V_47 == - V_116 && ! V_19 -> V_52 )
V_47 = 0 ;
return V_47 ;
}
static int F_64 ( struct V_117 * V_118 , struct V_76 * V_77 )
{
int V_47 ;
if ( V_77 -> V_119 != V_42 )
return 0 ;
V_118 -> V_88 = 2 ;
V_47 = F_55 ( V_118 -> V_28 . V_120 , V_118 -> V_79 , V_118 -> V_88 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_121 = V_118 -> V_28 . V_122 . type ;
V_77 -> V_123 = V_118 -> V_28 . V_122 . V_46 ;
return 0 ;
}
static int F_65 ( void * V_124 , char * V_125 , int V_126 , int V_127 , int V_128 ,
struct V_24 * V_25 )
{
struct V_117 * V_118 = V_124 ;
if ( V_126 < V_118 -> V_88 ) {
int V_129 = F_66 ( V_118 -> V_88 - V_126 , V_127 ) ;
if ( V_25 -> V_100 == V_130 )
memcpy ( V_125 , V_118 -> V_28 . V_120 + V_126 , V_129 ) ;
else
V_25 -> V_131 = F_67 (
V_25 -> V_131 ,
F_68 ( V_118 -> V_28 . V_120 + V_126 ,
V_125 , V_129 , 0 ) ,
V_128 ) ;
V_128 = 0 ;
V_126 += V_129 ;
V_125 += V_129 ;
V_127 -= V_129 ;
if ( ! V_127 )
return 0 ;
}
V_126 -= V_118 -> V_88 ;
return F_69 ( V_118 -> V_79 , V_125 , V_126 , V_127 , V_128 , V_25 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_78 * V_79 , T_5 V_127 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_132 V_133 ;
struct V_81 * V_87 = NULL ;
struct V_76 V_77 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_4 V_134 ;
int V_47 ;
struct V_135 V_136 ;
struct V_117 V_118 ;
V_47 = - V_66 ;
if ( V_127 > 0xFFFF )
goto V_36;
V_47 = - V_137 ;
if ( V_79 -> V_138 & V_139 )
goto V_36;
if ( V_79 -> V_140 ) {
F_71 ( struct V_141 * , V_142 , V_79 -> V_143 ) ;
V_47 = - V_108 ;
if ( V_79 -> V_140 < sizeof( * V_142 ) )
goto V_36;
if ( V_142 -> V_144 != V_145 ) {
F_72 ( L_1 ,
V_146 , V_147 -> V_148 ) ;
V_47 = - V_149 ;
if ( V_142 -> V_144 )
goto V_36;
}
V_40 = V_142 -> V_150 . V_151 ;
} else {
V_47 = - V_152 ;
if ( V_2 -> V_53 != V_54 )
goto V_36;
V_40 = V_19 -> V_20 ;
}
V_133 . V_85 . V_102 = V_2 -> V_153 ;
V_133 . V_154 = V_19 -> V_155 ;
V_133 . V_156 = NULL ;
V_133 . V_103 = 0 ;
V_133 . V_157 = 0 ;
V_133 . V_134 = - 1 ;
V_133 . V_158 = V_2 -> V_22 ;
if ( V_79 -> V_159 ) {
V_47 = F_73 ( V_2 , V_79 , & V_133 , false ) ;
if ( F_74 ( V_47 ) ) {
F_75 ( V_133 . V_156 ) ;
goto V_36;
}
if ( V_133 . V_156 )
free = 1 ;
}
V_39 = V_133 . V_154 ;
V_133 . V_154 = V_40 ;
if ( ! V_133 . V_156 ) {
struct V_160 * V_161 ;
F_76 () ;
V_161 = F_77 ( V_19 -> V_161 ) ;
if ( V_161 ) {
memcpy ( & V_136 , V_161 ,
sizeof( * V_161 ) + V_161 -> V_156 . V_162 ) ;
V_133 . V_156 = & V_136 . V_156 ;
}
F_78 () ;
}
if ( V_133 . V_156 ) {
V_47 = - V_108 ;
if ( V_19 -> V_69 )
goto V_163;
if ( V_133 . V_156 -> V_156 . V_164 ) {
if ( ! V_40 )
goto V_163;
V_40 = V_133 . V_156 -> V_156 . V_165 ;
}
}
V_134 = F_79 ( & V_133 , V_2 ) ;
if ( V_79 -> V_138 & V_166 )
V_134 |= V_167 ;
if ( F_80 ( V_40 ) ) {
if ( ! V_133 . V_158 )
V_133 . V_158 = V_19 -> V_168 ;
if ( ! V_39 )
V_39 = V_19 -> V_169 ;
} else if ( ! V_133 . V_158 )
V_133 . V_158 = V_19 -> V_170 ;
F_81 ( & V_77 , V_133 . V_158 , V_2 -> V_99 , V_134 ,
V_171 ,
V_19 -> V_69 ? V_172 : V_2 -> V_173 ,
F_82 ( V_2 ) |
( V_19 -> V_69 ? V_174 : 0 ) ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_39 && V_133 . V_158 ) {
V_47 = F_83 ( V_13 , V_133 . V_158 , & V_77 ) ;
if ( V_47 < 0 )
goto V_163;
}
if ( ! V_19 -> V_69 ) {
V_118 . V_79 = V_79 ;
V_118 . V_88 = 0 ;
V_47 = F_64 ( & V_118 , & V_77 ) ;
if ( V_47 )
goto V_163;
}
F_84 ( V_2 , F_85 ( & V_77 ) ) ;
V_87 = F_86 ( V_13 , & V_77 , V_2 ) ;
if ( F_87 ( V_87 ) ) {
V_47 = F_88 ( V_87 ) ;
V_87 = NULL ;
goto V_163;
}
V_47 = - V_175 ;
if ( V_87 -> V_176 & V_177 && ! F_89 ( V_2 , V_178 ) )
goto V_163;
if ( V_79 -> V_138 & V_179 )
goto V_180;
V_181:
if ( V_19 -> V_69 )
V_47 = F_45 ( V_2 , & V_77 , V_79 , V_127 ,
& V_87 , V_79 -> V_138 , & V_133 . V_85 ) ;
else {
F_53 ( V_2 , V_133 . V_85 . V_102 , & V_133 . V_103 ) ;
if ( ! V_133 . V_154 )
V_133 . V_154 = V_77 . V_40 ;
F_90 ( V_2 ) ;
V_47 = F_91 ( V_2 , & V_77 , F_65 ,
& V_118 , V_127 , 0 ,
& V_133 , & V_87 , V_79 -> V_138 ) ;
if ( V_47 )
F_92 ( V_2 ) ;
else if ( ! ( V_79 -> V_138 & V_182 ) ) {
V_47 = F_93 ( V_2 , & V_77 ) ;
if ( V_47 == - V_116 && ! V_19 -> V_52 )
V_47 = 0 ;
}
F_94 ( V_2 ) ;
}
V_163:
if ( free )
F_75 ( V_133 . V_156 ) ;
F_95 ( V_87 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_127 ;
V_180:
F_96 ( & V_87 -> V_90 ) ;
if ( ! ( V_79 -> V_138 & V_93 ) || V_127 )
goto V_181;
V_47 = 0 ;
goto V_163;
}
static void F_97 ( struct V_1 * V_2 , long V_183 )
{
F_98 ( V_2 , 0 , NULL ) ;
F_99 ( V_2 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_90 ( V_2 ) ;
F_92 ( V_2 ) ;
F_94 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 , struct V_184 * V_185 , int V_186 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_141 * V_154 = (struct V_141 * ) V_185 ;
int V_187 = - V_108 ;
int V_188 ;
if ( V_2 -> V_53 != V_189 || V_186 < sizeof( struct V_141 ) )
goto V_36;
V_188 = F_102 ( F_6 ( V_2 ) , V_154 -> V_150 . V_151 ) ;
V_187 = - V_190 ;
if ( V_154 -> V_150 . V_151 && V_188 != V_191 &&
V_188 != V_192 && V_188 != V_193 )
goto V_36;
V_19 -> V_21 = V_19 -> V_155 = V_154 -> V_150 . V_151 ;
if ( V_188 == V_192 || V_188 == V_193 )
V_19 -> V_155 = 0 ;
F_103 ( V_2 ) ;
V_187 = 0 ;
V_36: return V_187 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_78 * V_79 , T_5 V_127 ,
int V_194 , int V_83 , int * V_186 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_5 V_195 = 0 ;
int V_47 = - V_137 ;
F_71 ( struct V_141 * , sin , V_79 -> V_143 ) ;
struct V_24 * V_25 ;
if ( V_83 & V_139 )
goto V_36;
if ( V_83 & V_196 ) {
V_47 = F_105 ( V_2 , V_79 , V_127 , V_186 ) ;
goto V_36;
}
V_25 = F_106 ( V_2 , V_83 , V_194 , & V_47 ) ;
if ( ! V_25 )
goto V_36;
V_195 = V_25 -> V_127 ;
if ( V_127 < V_195 ) {
V_79 -> V_138 |= V_197 ;
V_195 = V_127 ;
}
V_47 = F_107 ( V_25 , 0 , V_79 , V_195 ) ;
if ( V_47 )
goto V_163;
F_108 ( V_79 , V_2 , V_25 ) ;
if ( sin ) {
sin -> V_144 = V_145 ;
sin -> V_150 . V_151 = F_29 ( V_25 ) -> V_39 ;
sin -> V_198 = 0 ;
memset ( & sin -> V_199 , 0 , sizeof( sin -> V_199 ) ) ;
* V_186 = sizeof( * sin ) ;
}
if ( V_19 -> V_200 )
F_109 ( V_79 , V_25 ) ;
if ( V_83 & V_197 )
V_195 = V_25 -> V_127 ;
V_163:
F_110 ( V_2 , V_25 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_195 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_201 * V_202 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_202 -> V_30 , 0 , sizeof( V_202 -> V_30 ) ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , char T_6 * V_203 , int V_162 )
{
if ( V_162 > sizeof( struct F_13 ) )
V_162 = sizeof( struct F_13 ) ;
if ( F_113 ( & F_16 ( V_2 ) -> V_30 , V_203 , V_162 ) )
return - V_106 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , char T_6 * V_203 , int T_6 * V_162 )
{
int V_127 , V_187 = - V_106 ;
if ( F_115 ( V_127 , V_162 ) )
goto V_36;
V_187 = - V_108 ;
if ( V_127 < 0 )
goto V_36;
if ( V_127 > sizeof( struct F_13 ) )
V_127 = sizeof( struct F_13 ) ;
V_187 = - V_106 ;
if ( F_116 ( V_127 , V_162 ) ||
F_117 ( V_203 , & F_16 ( V_2 ) -> V_30 , V_127 ) )
goto V_36;
V_187 = 0 ;
V_36: return V_187 ;
}
static int F_118 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , unsigned int V_162 )
{
if ( V_205 == V_206 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_137 ;
else
return F_112 ( V_2 , V_203 , V_162 ) ;
}
return - V_207 ;
}
static int F_119 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , unsigned int V_162 )
{
if ( V_204 != V_208 )
return F_120 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
return F_118 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
}
static int F_121 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , unsigned int V_162 )
{
if ( V_204 != V_208 )
return F_122 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
return F_118 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
}
static int F_123 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , int T_6 * V_162 )
{
if ( V_205 == V_206 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_137 ;
else
return F_114 ( V_2 , V_203 , V_162 ) ;
}
return - V_207 ;
}
static int F_124 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , int T_6 * V_162 )
{
if ( V_204 != V_208 )
return F_125 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
return F_123 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
}
static int F_126 ( struct V_1 * V_2 , int V_204 , int V_205 ,
char T_6 * V_203 , int T_6 * V_162 )
{
if ( V_204 != V_208 )
return F_127 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
return F_123 ( V_2 , V_204 , V_205 , V_203 , V_162 ) ;
}
static int F_128 ( struct V_1 * V_2 , int V_209 , unsigned long V_210 )
{
switch ( V_209 ) {
case V_211 : {
int V_212 = F_129 ( V_2 ) ;
return F_116 ( V_212 , ( int T_6 * ) V_210 ) ;
}
case V_213 : {
struct V_24 * V_25 ;
int V_212 = 0 ;
F_130 ( & V_2 -> V_214 . V_12 ) ;
V_25 = F_131 ( & V_2 -> V_214 ) ;
if ( V_25 )
V_212 = V_25 -> V_127 ;
F_132 ( & V_2 -> V_214 . V_12 ) ;
return F_116 ( V_212 , ( int T_6 * ) V_210 ) ;
}
default:
#ifdef F_133
return F_134 ( V_2 , V_209 , ( void T_6 * ) V_210 ) ;
#else
return - V_215 ;
#endif
}
}
static int F_135 ( struct V_1 * V_2 , unsigned int V_209 , unsigned long V_210 )
{
switch ( V_209 ) {
case V_211 :
case V_213 :
return - V_215 ;
default:
#ifdef F_133
return F_136 ( V_2 , V_209 , F_137 ( V_210 ) ) ;
#else
return - V_215 ;
#endif
}
}
static struct V_1 * F_138 ( struct V_216 * V_217 )
{
struct V_1 * V_2 ;
struct V_218 * V_219 = F_139 ( V_217 ) ;
for ( V_219 -> V_220 = 0 ; V_219 -> V_220 < V_11 ;
++ V_219 -> V_220 ) {
F_140 (sk, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_141 ( V_217 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static struct V_1 * F_142 ( struct V_216 * V_217 , struct V_1 * V_2 )
{
struct V_218 * V_219 = F_139 ( V_217 ) ;
do {
V_2 = F_25 ( V_2 ) ;
V_221:
;
} while ( V_2 && F_6 ( V_2 ) != F_141 ( V_217 ) );
if ( ! V_2 && ++ V_219 -> V_220 < V_11 ) {
V_2 = F_28 ( & V_219 -> V_4 -> V_9 [ V_219 -> V_220 ] ) ;
goto V_221;
}
return V_2 ;
}
static struct V_1 * F_143 ( struct V_216 * V_217 , T_7 V_222 )
{
struct V_1 * V_2 = F_138 ( V_217 ) ;
if ( V_2 )
while ( V_222 && ( V_2 = F_142 ( V_217 , V_2 ) ) != NULL )
-- V_222 ;
return V_222 ? NULL : V_2 ;
}
void * F_144 ( struct V_216 * V_217 , T_7 * V_222 )
{
struct V_218 * V_219 = F_139 ( V_217 ) ;
F_18 ( & V_219 -> V_4 -> V_12 ) ;
return * V_222 ? F_143 ( V_217 , * V_222 - 1 ) : V_223 ;
}
void * F_145 ( struct V_216 * V_217 , void * V_224 , T_7 * V_222 )
{
struct V_1 * V_2 ;
if ( V_224 == V_223 )
V_2 = F_138 ( V_217 ) ;
else
V_2 = F_142 ( V_217 , V_224 ) ;
++ * V_222 ;
return V_2 ;
}
void F_146 ( struct V_216 * V_217 , void * V_224 )
{
struct V_218 * V_219 = F_139 ( V_217 ) ;
F_26 ( & V_219 -> V_4 -> V_12 ) ;
}
static void F_147 ( struct V_216 * V_217 , struct V_1 * V_225 , int V_226 )
{
struct V_18 * V_19 = F_2 ( V_225 ) ;
T_1 V_227 = V_19 -> V_20 ,
V_228 = V_19 -> V_21 ;
T_8 V_229 = 0 ,
V_230 = V_19 -> V_10 ;
F_148 ( V_217 , L_2
L_3 ,
V_226 , V_228 , V_230 , V_227 , V_229 , V_225 -> V_53 ,
F_129 ( V_225 ) ,
F_149 ( V_225 ) ,
0 , 0L , 0 ,
F_150 ( F_151 ( V_217 ) , F_152 ( V_225 ) ) ,
0 , F_153 ( V_225 ) ,
F_154 ( & V_225 -> V_231 ) , V_225 , F_154 ( & V_225 -> V_75 ) ) ;
}
static int F_155 ( struct V_216 * V_217 , void * V_224 )
{
if ( V_224 == V_223 )
F_148 ( V_217 , L_4
L_5
L_6 ) ;
else
F_147 ( V_217 , V_224 , F_139 ( V_217 ) -> V_220 ) ;
return 0 ;
}
int F_156 ( struct V_232 * V_233 , struct V_234 * V_234 ,
struct V_3 * V_4 , const struct V_235 * V_236 )
{
int V_47 ;
struct V_218 * V_226 ;
V_47 = F_157 ( V_233 , V_234 , V_236 , sizeof( struct V_218 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_226 = F_139 ( (struct V_216 * ) V_234 -> V_237 ) ;
V_226 -> V_4 = V_4 ;
return 0 ;
}
static int F_158 ( struct V_232 * V_232 , struct V_234 * V_234 )
{
return F_156 ( V_232 , V_234 , & V_35 , & V_238 ) ;
}
static T_9 int F_159 ( struct V_13 * V_13 )
{
if ( ! F_160 ( L_7 , V_239 , V_13 -> V_240 , & V_241 ) )
return - V_242 ;
return 0 ;
}
static T_10 void F_161 ( struct V_13 * V_13 )
{
F_162 ( L_7 , V_13 -> V_240 ) ;
}
int T_11 F_163 ( void )
{
return F_164 ( & V_243 ) ;
}
void T_11 F_165 ( void )
{
F_166 ( & V_243 ) ;
}
