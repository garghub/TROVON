static inline void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = 1 ;
}
static inline void F_2 ( struct V_4 * V_5 )
{
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_3 = 1 ;
}
static inline void F_3 ( struct V_6 * V_7 )
{
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
}
static inline void F_4 ( void * V_8 ,
T_1 V_9 ,
T_1 V_10 ,
T_1 V_11 ,
T_1 V_12 ,
T_1 V_13 ,
T_1 V_14 ,
T_1 V_15 ,
T_1 V_16 ,
T_1 V_17 , T_1 V_18 ,
T_1 V_19 )
{
union V_20 V_21 ;
union V_22 V_23 ;
union V_24 V_24 ;
union V_25 V_26 ;
union V_27 V_28 ;
V_21 . V_29 = 0 ;
V_23 . V_30 = 0 ;
V_24 . V_31 = 0 ;
V_26 . V_32 = 0 ;
V_28 . V_33 = 0 ;
V_28 . V_34 = V_9 ;
F_5 ( V_8 , V_35 , V_28 . V_33 ) ;
V_26 . V_36 = V_10 ;
V_26 . V_37 = V_11 ;
F_5 ( V_8 , V_38 , V_26 . V_32 ) ;
V_21 . V_39 = V_12 ;
V_21 . V_40 = V_13 ;
V_21 . V_41 = V_14 ;
V_21 . V_42 = V_15 ;
F_5 ( V_8 , V_43 , V_21 . V_29 ) ;
V_23 . V_44 = V_16 ;
V_23 . V_45 = V_17 ;
F_5 ( V_8 , V_46 , V_23 . V_30 ) ;
V_24 . V_47 = V_18 ;
V_24 . V_48 = V_19 ;
F_5 ( V_8 , V_49 , V_24 . V_31 ) ;
}
static inline void F_6 ( void * V_8 ,
T_1 V_9 ,
T_1 V_10 ,
T_1 V_11 ,
T_1 V_12 ,
T_1 V_13 ,
T_1 V_14 ,
T_1 V_15 ,
T_1 V_16 ,
T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
union V_20 V_50 ;
union V_22 V_23 ;
union V_24 V_24 ;
union V_25 V_26 ;
union V_27 V_28 ;
V_50 . V_29 = 0 ;
V_23 . V_30 = 0 ;
V_24 . V_31 = 0 ;
V_26 . V_32 = 0 ;
V_28 . V_33 = 0 ;
V_28 . V_34 = V_9 ;
F_5 ( V_8 , V_51 , V_28 . V_33 ) ;
V_26 . V_36 = V_10 ;
V_26 . V_37 = V_11 ;
F_5 ( V_8 , V_52 , V_26 . V_32 ) ;
V_50 . V_39 = V_12 ;
V_50 . V_40 = V_13 ;
V_50 . V_41 = V_14 ;
V_50 . V_42 = V_15 ;
F_5 ( V_8 , V_53 , V_50 . V_29 ) ;
V_23 . V_44 = V_16 ;
V_23 . V_45 = V_17 ;
F_5 ( V_8 , V_54 , V_23 . V_30 ) ;
V_24 . V_47 = V_18 ;
V_24 . V_48 = V_19 ;
F_5 ( V_8 , V_55 , V_24 . V_31 ) ;
}
static inline void F_7 ( void * V_8 ,
T_1 V_16 ,
T_1 V_17 ,
T_1 V_18 ,
T_1 V_19 , T_1 V_56 )
{
union V_22 V_23 ;
union V_24 V_24 ;
union V_57 V_58 ;
V_58 . V_59 = 0 ;
V_24 . V_31 = 0 ;
V_23 . V_30 = 0 ;
V_23 . V_44 = V_16 ;
V_23 . V_45 = V_17 ;
F_5 ( V_8 , V_60 , V_23 . V_30 ) ;
V_24 . V_47 = V_18 ;
V_24 . V_48 = V_19 ;
F_5 ( V_8 , V_61 , V_24 . V_31 ) ;
V_58 . V_62 = V_56 ;
F_5 ( V_8 , V_63 , V_58 . V_59 ) ;
}
static inline int F_8 ( struct V_64 * V_65 )
{
void * V_66 ;
struct V_1 * V_2 ;
T_1 V_12 ;
union V_67 V_67 ;
V_66 = V_65 -> V_66 ;
V_2 = & V_65 -> V_1 ;
if ( ! V_2 -> V_9 )
return - 1 ;
V_12 =
( V_2 -> V_68 + ( V_69 - 1 ) ) / V_69 ;
F_4 ( V_66 , F_9 ( V_2 -> V_9 ) ,
V_2 -> V_10 ,
( V_2 -> V_10 < V_70 ) ? 0 :
( V_2 -> V_10 < V_71 ) ? 1 :
( V_2 -> V_10 < V_72 ) ? 2 : 3 ,
V_12 ,
V_2 -> V_73 ,
V_2 -> V_3 ,
V_2 -> V_15 ,
V_2 -> V_16 ,
V_2 -> V_17 ,
V_2 -> V_18 , V_2 -> V_19 ) ;
V_67 . V_74 = F_10 ( V_66 , V_75 ) ;
V_67 . V_76 = 1 ;
F_5 ( V_66 , V_75 , V_67 . V_74 ) ;
return 0 ;
}
static inline int F_11 ( struct V_64 * V_65 )
{
void * V_66 ;
struct V_4 * V_5 ;
T_1 V_12 ;
union V_67 V_67 ;
V_66 = V_65 -> V_66 ;
V_5 = & V_65 -> V_4 ;
if ( ! V_5 -> V_9 )
return - 1 ;
V_12 =
( V_5 -> V_68 + ( V_69 - 1 ) ) / V_69 ;
F_6 ( V_66 , F_9 ( V_5 -> V_9 ) ,
V_5 -> V_10 ,
( V_5 -> V_10 < V_70 ) ? 0 :
( V_5 -> V_10 < V_71 ) ? 1 :
( V_5 -> V_10 < V_72 ) ? 2 : 3 ,
V_12 ,
V_5 -> V_73 ,
V_5 -> V_3 ,
V_5 -> V_15 ,
V_5 -> V_16 ,
V_5 -> V_17 ,
V_5 -> V_18 , V_5 -> V_19 ) ;
V_67 . V_74 = F_10 ( V_66 , V_75 ) ;
V_67 . V_77 = 1 ;
F_5 ( V_66 , V_75 , V_67 . V_74 ) ;
return 0 ;
}
static inline int F_12 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = & V_65 -> V_78 ;
void * V_66 = V_65 -> V_66 ;
union V_67 V_67 ;
if ( F_13 ( & V_65 -> V_79 ) )
return - V_80 ;
F_14 ( & V_65 -> V_81 , 0 ) ;
F_7 ( V_66 ,
V_7 -> V_16 ,
V_7 -> V_17 ,
V_7 -> V_18 ,
V_7 -> V_19 , V_7 -> V_56 ) ;
V_67 . V_74 = F_10 ( V_66 , V_75 ) ;
V_67 . V_82 = 1 ;
V_67 . V_83 = 1 ;
F_5 ( V_66 , V_75 , V_67 . V_74 ) ;
F_15 ( & V_65 -> V_79 ) ;
return 0 ;
}
static inline T_2
F_16 ( struct V_64 * V_65 , T_1 V_9 ,
T_3 V_84 , T_4 * V_85 )
{
int V_86 = 0 ;
if ( F_13 ( & V_65 -> V_87 ) )
return - V_80 ;
F_14 ( & V_65 -> V_88 , 0 ) ;
V_65 -> V_4 . V_9 = V_9 ;
V_65 -> V_4 . V_10 = * V_85 ;
V_65 -> V_4 . V_68 = V_84 ;
if ( F_11 ( V_65 ) < 0 ) {
F_17 ( V_89 L_1
L_2 ) ;
V_86 = - V_90 ;
goto V_91;
}
if ( F_18 ( V_65 -> V_92 ,
F_19 ( & V_65 -> V_88 ) ) ) {
V_86 = - V_80 ;
goto V_91;
}
V_86 = V_84 ;
* V_85 += V_84 ;
V_91:
F_15 ( & V_65 -> V_87 ) ;
return V_86 ;
}
static inline T_2
F_20 ( struct V_64 * V_65 , T_1 V_9 ,
T_3 V_84 , T_4 * V_85 )
{
int V_86 = 0 ;
if ( F_13 ( & V_65 -> V_93 ) )
return - V_80 ;
F_14 ( & V_65 -> V_88 , 0 ) ;
V_65 -> V_1 . V_9 = V_9 ;
V_65 -> V_1 . V_10 = * V_85 ;
V_65 -> V_1 . V_68 = V_84 ;
if ( F_8 ( V_65 ) < 0 ) {
F_17 ( V_89 L_3 ) ;
V_86 = - V_90 ;
goto V_94;
}
if ( F_18 ( V_65 -> V_95 ,
F_19 ( & V_65 -> V_96 ) ) ) {
V_86 = - V_80 ;
goto V_94;
}
V_86 = V_84 ;
* V_85 += V_84 ;
V_94:
F_15 ( & V_65 -> V_93 ) ;
return V_86 ;
}
static int F_21 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
struct V_64 * V_65 ;
int V_101 ;
F_22 ( & V_102 ) ;
V_101 = F_23 ( V_98 ) ;
F_24 (soft, &soft_list, list) {
if ( V_65 -> V_103 == V_101 ) {
V_100 -> V_104 = V_65 -> V_105 ;
F_15 ( & V_102 ) ;
return 0 ;
}
}
F_15 ( & V_102 ) ;
return - V_106 ;
}
static T_2 F_25 ( struct V_99 * V_100 , char T_5 * V_107 , T_3 V_84 , T_4 * V_85 )
{
struct V_108 * V_108 = V_100 -> V_104 ;
struct V_64 * V_65 = V_108 -> V_65 ;
T_1 V_9 ;
int V_86 = 0 ;
V_9 = F_26 ( V_109 , F_27 ( V_84 ) ) ;
if ( V_9 == 0 )
return - V_110 ;
V_86 = F_16 ( V_65 , V_9 , V_84 , V_85 ) ;
if ( V_86 < 0 )
goto exit;
if ( F_28 ( V_107 , ( void * ) V_9 , V_84 ) )
V_86 = - V_111 ;
exit:
F_29 ( V_9 , F_27 ( V_84 ) ) ;
return V_86 ;
}
static T_2
F_30 ( struct V_99 * V_100 , const char T_5 * V_107 , T_3 V_84 , T_4 * V_85 )
{
struct V_108 * V_108 = V_100 -> V_104 ;
struct V_64 * V_65 = V_108 -> V_65 ;
T_1 V_9 ;
int V_86 = 0 ;
V_9 = F_26 ( V_109 , F_27 ( V_84 ) ) ;
if ( V_9 == 0 )
return - V_110 ;
if ( F_31 ( ( void * ) V_9 , V_107 , V_84 ) ) {
V_86 = - V_111 ;
goto exit;
}
V_86 = F_20 ( V_65 , V_9 , V_84 , V_85 ) ;
exit:
F_29 ( V_9 , F_27 ( V_84 ) ) ;
return V_86 ;
}
static T_4 F_32 ( struct V_99 * V_112 , T_4 V_85 , int V_113 )
{
T_4 V_114 ;
switch ( V_113 ) {
case V_115 :
V_114 = V_85 ;
break;
case V_116 :
V_114 = V_112 -> V_117 + V_85 ;
break;
case V_118 :
V_114 = V_119 + V_85 ;
break;
default:
return - V_120 ;
}
if ( V_114 < 0 )
return - V_120 ;
V_112 -> V_117 = V_114 ;
return V_114 ;
}
static T_1 F_33 ( struct V_64 * V_65 , T_1 V_121 )
{
T_1 V_66 ;
V_66 = ( T_1 ) ( V_65 -> V_66 + V_121 ) ;
return V_66 ;
}
static void F_34 ( struct V_64 * V_65 )
{
V_65 -> V_122 = F_33 ( V_65 , V_123 ) ;
}
static void F_35 ( struct V_64 * V_65 )
{
V_65 -> V_124 = F_33 ( V_65 , V_125 ) ;
}
static int F_36 ( struct V_99 * V_100 , struct V_126 * V_127 )
{
struct V_108 * V_108 = V_100 -> V_104 ;
struct V_64 * V_65 = V_108 -> V_65 ;
if ( V_127 -> V_128 != 0 )
return - V_120 ;
V_127 -> V_129 = F_37 ( V_127 -> V_129 ) ;
if ( F_38 ( V_127 ,
V_127 -> V_130 ,
F_39 ( V_65 -> V_124 ) >> V_131 ,
V_132 ,
V_127 -> V_129 ) )
return - V_90 ;
return 0 ;
}
static T_6
F_40 ( int V_133 , void * V_134 )
{
struct V_64 * V_65 = (struct V_64 * ) V_134 ;
void * V_66 ;
union V_135 V_135 ;
union V_67 V_67 ;
V_66 = V_65 -> V_66 ;
V_135 . V_136 = F_10 ( V_66 , V_137 ) ;
if ( V_135 . V_138 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_139 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_96 , 1 ) ;
F_41 ( & V_65 -> V_95 ) ;
}
if ( V_135 . V_140 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_141 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_88 , 1 ) ;
F_41 ( & V_65 -> V_92 ) ;
}
if ( V_135 . V_142 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_143 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_81 , 1 ) ;
F_41 ( & V_65 -> V_144 ) ;
}
return V_145 ;
}
static int F_42 ( struct V_108 * V_146 )
{
struct V_147 * V_148 ;
struct V_64 * V_65 ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
struct V_6 * V_78 ;
V_65 = V_146 -> V_65 ;
V_1 = & V_65 -> V_1 ;
V_4 = & V_65 -> V_4 ;
V_78 = & V_65 -> V_78 ;
V_65 -> V_149 = NULL ;
V_65 -> V_150 = NULL ;
V_65 -> V_151 = NULL ;
V_148 = F_43 ( V_146 -> V_152 . V_103 , V_153 , - 1 , - 1 , - 1 ) ;
if ( V_148 == NULL )
return - V_90 ;
V_65 -> V_149 = V_148 ;
V_1 -> V_18 = V_148 -> V_154 ;
V_1 -> V_19 = V_148 -> V_155 ;
if ( F_44 ( V_148 -> V_155 ,
( void * ) F_40 , V_156 ,
L_4 , ( void * ) V_65 ) ) {
F_45 ( V_65 -> V_149 ) ;
return - V_90 ;
}
V_148 = F_43 ( V_146 -> V_152 . V_103 , V_153 , - 1 , - 1 , - 1 ) ;
if ( V_148 == NULL ) {
F_46 ( V_65 -> V_149 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_149 ) ;
return - V_90 ;
}
V_65 -> V_150 = V_148 ;
V_4 -> V_18 = V_148 -> V_154 ;
V_4 -> V_19 = V_148 -> V_155 ;
if ( F_44 ( V_148 -> V_155 ,
( void * ) F_40 , V_156 ,
L_5 , ( void * ) V_65 ) ) {
F_45 ( V_65 -> V_150 ) ;
F_46 ( V_65 -> V_149 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_149 ) ;
return - V_90 ;
}
V_148 = F_43 ( V_146 -> V_152 . V_103 , V_153 , - 1 , - 1 , - 1 ) ;
if ( V_148 == NULL ) {
F_46 ( V_65 -> V_150 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_150 ) ;
F_46 ( V_65 -> V_149 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_149 ) ;
return - V_90 ;
}
V_65 -> V_151 = V_148 ;
V_78 -> V_18 = V_148 -> V_154 ;
V_78 -> V_19 = V_148 -> V_155 ;
if ( F_44 ( V_148 -> V_155 ,
( void * ) F_40 , V_156 ,
L_6 , ( void * ) V_65 ) ) {
F_45 ( V_65 -> V_151 ) ;
F_46 ( V_65 -> V_150 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_150 ) ;
F_46 ( V_65 -> V_149 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_149 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_47 ( struct V_108 * V_146 )
{
struct V_64 * V_65 ;
V_65 = V_146 -> V_65 ;
F_46 ( V_65 -> V_149 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_149 ) ;
F_46 ( V_65 -> V_150 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_150 ) ;
F_46 ( V_65 -> V_151 -> V_155 , V_65 ) ;
F_45 ( V_65 -> V_151 ) ;
}
static inline int F_48 ( struct V_64 * V_65 )
{
void * V_66 = V_65 -> V_66 ;
union V_67 V_67 ;
union V_157 V_157 ;
T_1 V_158 ;
V_157 . V_159 =
F_10 ( V_66 , V_160 ) ;
V_157 . V_161 = V_162 ;
F_5 ( V_66 , V_160 ,
V_157 . V_159 ) ;
F_35 ( V_65 ) ;
F_34 ( V_65 ) ;
V_158 = F_10 ( V_66 , V_163 ) ;
F_5 ( V_66 , V_164 , V_158 ) ;
F_49 ( V_66 , V_165 ) ;
F_5 ( V_66 , V_166 , 0x3ffffff7e00ffUL ) ;
V_67 . V_74 = F_10 ( V_66 , V_75 ) ;
V_67 . V_167 = 1 ;
V_67 . V_168 = 1 ;
V_67 . V_141 = 1 ;
V_67 . V_139 = 1 ;
F_5 ( V_66 , V_75 , V_67 . V_74 ) ;
return 0 ;
}
static T_2 F_50 ( struct V_169 * V_146 , struct V_170 * V_171 , char * V_107 )
{
struct V_108 * V_108 = F_51 ( V_146 ) ;
struct V_64 * V_65 = V_108 -> V_65 ;
T_1 V_172 ;
V_172 = * ( T_1 * ) V_65 -> V_122 ;
return sprintf ( V_107 , L_7 ,
F_52 ( V_172 ) , F_53 ( V_172 ) ) ;
}
static T_2 F_54 ( struct V_169 * V_146 , struct V_170 * V_171 , const char * V_107 , T_3 V_173 )
{
int V_174 ;
struct V_108 * V_108 = F_51 ( V_146 ) ;
struct V_64 * V_65 = V_108 -> V_65 ;
if ( V_173 <= 0 )
return 0 ;
V_174 = F_55 ( V_107 , NULL , 0 ) ;
if ( V_174 == 1 ) {
F_12 ( V_65 ) ;
if ( F_18 ( V_65 -> V_144 ,
F_19 ( & V_65 -> V_81 ) ) )
return - V_80 ;
}
return V_173 ;
}
static int F_56 ( struct V_108 * V_146 , const struct V_175 * V_176 )
{
struct V_64 * V_65 ;
V_146 -> V_65 = NULL ;
V_65 = F_57 ( sizeof( struct V_64 ) , V_109 ) ;
if ( V_65 == NULL )
return - V_110 ;
V_65 -> V_103 = V_146 -> V_152 . V_103 ;
F_58 ( & V_65 -> V_177 , & V_178 ) ;
V_65 -> V_66 = ( void * ) F_59 ( V_146 -> V_152 . V_103 ) ;
V_146 -> V_65 = V_65 ;
V_65 -> V_105 = V_146 ;
F_60 ( & V_65 -> V_92 ) ;
F_60 ( & V_65 -> V_95 ) ;
F_60 ( & V_65 -> V_144 ) ;
F_61 ( & V_65 -> V_87 ) ;
F_61 ( & V_65 -> V_93 ) ;
F_61 ( & V_65 -> V_79 ) ;
F_1 ( & V_65 -> V_1 ) ;
F_2 ( & V_65 -> V_4 ) ;
F_3 ( & V_65 -> V_78 ) ;
F_48 ( V_65 ) ;
F_42 ( V_146 ) ;
F_62 ( & V_146 -> V_146 , & V_179 ) ;
return 0 ;
}
static int F_63 ( struct V_108 * V_146 )
{
if ( V_146 -> V_65 ) {
F_47 ( V_146 ) ;
F_64 ( V_146 -> V_65 ) ;
}
F_65 ( & V_146 -> V_146 , & V_179 ) ;
return 0 ;
}
static void T_7 F_66 ( void )
{
F_67 ( V_180 , V_181 ) ;
F_68 ( & V_182 ) ;
}
static int T_8 F_69 ( void )
{
int V_86 ;
if ( ! F_70 ( L_8 ) )
return - V_106 ;
V_86 = F_71 ( V_180 , V_181 , & V_183 ) ;
if ( V_86 < 0 ) {
F_17 ( V_89 L_9 , V_86 ) ;
return V_86 ;
}
V_180 = V_86 ;
return F_72 ( & V_182 ) ;
}
