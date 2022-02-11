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
return F_33 ( V_112 , V_85 , V_113 , V_114 ,
V_115 ) ;
}
static T_1 F_34 ( struct V_64 * V_65 , T_1 V_116 )
{
T_1 V_66 ;
V_66 = ( T_1 ) ( V_65 -> V_66 + V_116 ) ;
return V_66 ;
}
static void F_35 ( struct V_64 * V_65 )
{
V_65 -> V_117 = F_34 ( V_65 , V_118 ) ;
}
static void F_36 ( struct V_64 * V_65 )
{
V_65 -> V_119 = F_34 ( V_65 , V_120 ) ;
}
static int F_37 ( struct V_99 * V_100 , struct V_121 * V_122 )
{
struct V_108 * V_108 = V_100 -> V_104 ;
struct V_64 * V_65 = V_108 -> V_65 ;
if ( V_122 -> V_123 != 0 )
return - V_124 ;
V_122 -> V_125 = F_38 ( V_122 -> V_125 ) ;
if ( F_39 ( V_122 ,
V_122 -> V_126 ,
F_40 ( V_65 -> V_119 ) >> V_127 ,
V_128 ,
V_122 -> V_125 ) )
return - V_90 ;
return 0 ;
}
static T_6
F_41 ( int V_129 , void * V_130 )
{
struct V_64 * V_65 = (struct V_64 * ) V_130 ;
void * V_66 ;
union V_131 V_131 ;
union V_67 V_67 ;
V_66 = V_65 -> V_66 ;
V_131 . V_132 = F_10 ( V_66 , V_133 ) ;
if ( V_131 . V_134 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_135 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_96 , 1 ) ;
F_42 ( & V_65 -> V_95 ) ;
}
if ( V_131 . V_136 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_137 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_88 , 1 ) ;
F_42 ( & V_65 -> V_92 ) ;
}
if ( V_131 . V_138 ) {
V_67 . V_74 =
F_10 ( V_66 , V_75 ) ;
V_67 . V_139 = 1 ;
F_5 ( V_66 , V_75 ,
V_67 . V_74 ) ;
F_14 ( & V_65 -> V_81 , 1 ) ;
F_42 ( & V_65 -> V_140 ) ;
}
return V_141 ;
}
static int F_43 ( struct V_108 * V_142 )
{
struct V_143 * V_144 ;
struct V_64 * V_65 ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
struct V_6 * V_78 ;
V_65 = V_142 -> V_65 ;
V_1 = & V_65 -> V_1 ;
V_4 = & V_65 -> V_4 ;
V_78 = & V_65 -> V_78 ;
V_65 -> V_145 = NULL ;
V_65 -> V_146 = NULL ;
V_65 -> V_147 = NULL ;
V_144 = F_44 ( V_142 -> V_148 . V_103 , V_149 , - 1 , - 1 , - 1 ) ;
if ( V_144 == NULL )
return - V_90 ;
V_65 -> V_145 = V_144 ;
V_1 -> V_18 = V_144 -> V_150 ;
V_1 -> V_19 = V_144 -> V_151 ;
if ( F_45 ( V_144 -> V_151 ,
( void * ) F_41 , V_152 ,
L_4 , ( void * ) V_65 ) ) {
F_46 ( V_65 -> V_145 ) ;
return - V_90 ;
}
V_144 = F_44 ( V_142 -> V_148 . V_103 , V_149 , - 1 , - 1 , - 1 ) ;
if ( V_144 == NULL ) {
F_47 ( V_65 -> V_145 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_145 ) ;
return - V_90 ;
}
V_65 -> V_146 = V_144 ;
V_4 -> V_18 = V_144 -> V_150 ;
V_4 -> V_19 = V_144 -> V_151 ;
if ( F_45 ( V_144 -> V_151 ,
( void * ) F_41 , V_152 ,
L_5 , ( void * ) V_65 ) ) {
F_46 ( V_65 -> V_146 ) ;
F_47 ( V_65 -> V_145 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_145 ) ;
return - V_90 ;
}
V_144 = F_44 ( V_142 -> V_148 . V_103 , V_149 , - 1 , - 1 , - 1 ) ;
if ( V_144 == NULL ) {
F_47 ( V_65 -> V_146 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_146 ) ;
F_47 ( V_65 -> V_145 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_145 ) ;
return - V_90 ;
}
V_65 -> V_147 = V_144 ;
V_78 -> V_18 = V_144 -> V_150 ;
V_78 -> V_19 = V_144 -> V_151 ;
if ( F_45 ( V_144 -> V_151 ,
( void * ) F_41 , V_152 ,
L_6 , ( void * ) V_65 ) ) {
F_46 ( V_65 -> V_147 ) ;
F_47 ( V_65 -> V_146 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_146 ) ;
F_47 ( V_65 -> V_145 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_145 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_48 ( struct V_108 * V_142 )
{
struct V_64 * V_65 ;
V_65 = V_142 -> V_65 ;
F_47 ( V_65 -> V_145 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_145 ) ;
F_47 ( V_65 -> V_146 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_146 ) ;
F_47 ( V_65 -> V_147 -> V_151 , V_65 ) ;
F_46 ( V_65 -> V_147 ) ;
}
static inline int F_49 ( struct V_64 * V_65 )
{
void * V_66 = V_65 -> V_66 ;
union V_67 V_67 ;
union V_153 V_153 ;
T_1 V_154 ;
V_153 . V_155 =
F_10 ( V_66 , V_156 ) ;
V_153 . V_157 = V_158 ;
F_5 ( V_66 , V_156 ,
V_153 . V_155 ) ;
F_36 ( V_65 ) ;
F_35 ( V_65 ) ;
V_154 = F_10 ( V_66 , V_159 ) ;
F_5 ( V_66 , V_160 , V_154 ) ;
F_50 ( V_66 , V_161 ) ;
F_5 ( V_66 , V_162 , 0x3ffffff7e00ffUL ) ;
V_67 . V_74 = F_10 ( V_66 , V_75 ) ;
V_67 . V_163 = 1 ;
V_67 . V_164 = 1 ;
V_67 . V_137 = 1 ;
V_67 . V_135 = 1 ;
F_5 ( V_66 , V_75 , V_67 . V_74 ) ;
return 0 ;
}
static T_2 F_51 ( struct V_165 * V_142 , struct V_166 * V_167 , char * V_107 )
{
struct V_108 * V_108 = F_52 ( V_142 ) ;
struct V_64 * V_65 = V_108 -> V_65 ;
T_1 V_168 ;
V_168 = * ( T_1 * ) V_65 -> V_117 ;
return sprintf ( V_107 , L_7 ,
F_53 ( V_168 ) , F_54 ( V_168 ) ) ;
}
static T_2 F_55 ( struct V_165 * V_142 , struct V_166 * V_167 , const char * V_107 , T_3 V_169 )
{
int V_170 ;
struct V_108 * V_108 = F_52 ( V_142 ) ;
struct V_64 * V_65 = V_108 -> V_65 ;
if ( V_169 <= 0 )
return 0 ;
V_170 = F_56 ( V_107 , NULL , 0 ) ;
if ( V_170 == 1 ) {
F_12 ( V_65 ) ;
if ( F_18 ( V_65 -> V_140 ,
F_19 ( & V_65 -> V_81 ) ) )
return - V_80 ;
}
return V_169 ;
}
static int F_57 ( struct V_108 * V_142 , const struct V_171 * V_172 )
{
struct V_64 * V_65 ;
V_142 -> V_65 = NULL ;
V_65 = F_58 ( sizeof( struct V_64 ) , V_109 ) ;
if ( V_65 == NULL )
return - V_110 ;
V_65 -> V_103 = V_142 -> V_148 . V_103 ;
F_59 ( & V_65 -> V_173 , & V_174 ) ;
V_65 -> V_66 = ( void * ) F_60 ( V_142 -> V_148 . V_103 ) ;
V_142 -> V_65 = V_65 ;
V_65 -> V_105 = V_142 ;
F_61 ( & V_65 -> V_92 ) ;
F_61 ( & V_65 -> V_95 ) ;
F_61 ( & V_65 -> V_140 ) ;
F_62 ( & V_65 -> V_87 ) ;
F_62 ( & V_65 -> V_93 ) ;
F_62 ( & V_65 -> V_79 ) ;
F_1 ( & V_65 -> V_1 ) ;
F_2 ( & V_65 -> V_4 ) ;
F_3 ( & V_65 -> V_78 ) ;
F_49 ( V_65 ) ;
F_43 ( V_142 ) ;
F_63 ( & V_142 -> V_142 , & V_175 ) ;
return 0 ;
}
static int F_64 ( struct V_108 * V_142 )
{
if ( V_142 -> V_65 ) {
F_48 ( V_142 ) ;
F_65 ( V_142 -> V_65 ) ;
}
F_66 ( & V_142 -> V_142 , & V_175 ) ;
return 0 ;
}
static void T_7 F_67 ( void )
{
F_68 ( V_176 , V_177 ) ;
F_69 ( & V_178 ) ;
}
static int T_8 F_70 ( void )
{
int V_86 ;
if ( ! F_71 ( L_8 ) )
return - V_106 ;
V_86 = F_72 ( V_176 , V_177 , & V_179 ) ;
if ( V_86 < 0 ) {
F_17 ( V_89 L_9 , V_86 ) ;
return V_86 ;
}
V_176 = V_86 ;
return F_73 ( & V_178 ) ;
}
