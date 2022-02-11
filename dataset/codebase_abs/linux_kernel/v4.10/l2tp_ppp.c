static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 == NULL )
return NULL ;
F_2 ( V_3 ) ;
V_4 = (struct V_1 * ) ( V_3 -> V_5 ) ;
if ( V_4 == NULL ) {
F_3 ( V_3 ) ;
goto V_6;
}
F_4 ( V_4 -> V_7 != V_8 ) ;
V_6:
return V_4 ;
}
static int F_5 ( struct V_9 * V_10 )
{
if ( ! F_6 ( V_10 , 2 ) )
return 1 ;
if ( ( V_10 -> V_11 [ 0 ] == V_12 ) && ( V_10 -> V_11 [ 1 ] == V_13 ) )
F_7 ( V_10 , 2 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_2 , struct V_15 * V_16 ,
T_1 V_17 , int V_18 )
{
int V_19 ;
struct V_9 * V_10 ;
struct V_2 * V_3 = V_2 -> V_3 ;
V_19 = - V_20 ;
if ( V_3 -> V_21 & V_22 )
goto V_23;
V_19 = 0 ;
V_10 = F_9 ( V_3 , V_18 & ~ V_24 ,
V_18 & V_24 , & V_19 ) ;
if ( ! V_10 )
goto V_23;
if ( V_17 > V_10 -> V_17 )
V_17 = V_10 -> V_17 ;
else if ( V_17 < V_10 -> V_17 )
V_16 -> V_25 |= V_26 ;
V_19 = F_10 ( V_10 , 0 , V_16 , V_17 ) ;
if ( F_11 ( V_19 == 0 ) )
V_19 = V_17 ;
F_12 ( V_10 ) ;
V_23:
return V_19 ;
}
static void F_13 ( struct V_1 * V_4 , struct V_9 * V_10 , int V_27 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_2 * V_3 = NULL ;
V_3 = V_29 -> V_2 ;
if ( V_3 == NULL )
goto V_30;
if ( V_3 -> V_21 & V_22 ) {
struct V_31 * V_32 ;
F_15 ( V_4 , V_33 ,
L_1 ,
V_4 -> V_34 , V_27 ) ;
V_32 = F_16 ( V_3 ) ;
F_17 ( & V_32 -> V_35 , V_10 ) ;
} else {
F_15 ( V_4 , V_33 ,
L_2 ,
V_4 -> V_34 , V_27 ) ;
if ( F_18 ( V_3 , V_10 ) < 0 ) {
F_19 ( & V_4 -> V_36 . V_37 ) ;
F_12 ( V_10 ) ;
}
}
return;
V_30:
F_20 ( V_4 , V_33 , L_3 , V_4 -> V_34 ) ;
F_12 ( V_10 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 )
F_2 ( V_29 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 )
F_3 ( V_29 -> V_2 ) ;
}
static int F_23 ( struct V_14 * V_2 , struct V_15 * V_38 ,
T_1 V_39 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_42 ;
error = - V_43 ;
if ( F_24 ( V_3 , V_44 ) || ! ( V_3 -> V_21 & V_45 ) )
goto error;
error = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_29 = F_14 ( V_4 ) ;
V_41 = F_25 ( V_29 -> V_47 ) ;
if ( V_41 == NULL )
goto V_48;
V_42 = ( V_41 -> V_49 == V_50 ) ? sizeof( struct V_51 ) : 0 ;
error = - V_52 ;
V_10 = F_26 ( V_3 , V_53 + sizeof( struct V_54 ) +
V_42 + V_4 -> V_55 +
2 + V_39 ,
0 , V_56 ) ;
if ( ! V_10 )
goto V_57;
F_27 ( V_10 , V_53 ) ;
F_28 ( V_10 ) ;
F_27 ( V_10 , sizeof( struct V_54 ) ) ;
F_29 ( V_10 ) ;
F_27 ( V_10 , V_42 ) ;
V_10 -> V_11 [ 0 ] = V_12 ;
V_10 -> V_11 [ 1 ] = V_13 ;
F_30 ( V_10 , 2 ) ;
error = F_31 ( F_30 ( V_10 , V_39 ) , V_38 , V_39 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_57;
}
F_32 () ;
F_33 ( V_4 , V_10 , V_4 -> V_55 ) ;
F_34 () ;
F_3 ( V_29 -> V_47 ) ;
F_3 ( V_3 ) ;
return V_39 ;
V_57:
F_3 ( V_29 -> V_47 ) ;
V_48:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_35 ( struct V_58 * V_35 , struct V_9 * V_10 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 -> V_59 ;
struct V_2 * V_60 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_42 , V_61 ;
if ( F_24 ( V_3 , V_44 ) || ! ( V_3 -> V_21 & V_45 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_29 = F_14 ( V_4 ) ;
V_60 = V_29 -> V_47 ;
if ( V_60 == NULL )
goto V_62;
V_41 = F_25 ( V_60 ) ;
if ( V_41 == NULL )
goto V_62;
V_42 = ( V_41 -> V_49 == V_50 ) ? sizeof( struct V_51 ) : 0 ;
V_61 = V_53 +
sizeof( struct V_54 ) +
V_42 +
V_4 -> V_55 +
2 ;
if ( F_36 ( V_10 , V_61 ) )
goto V_63;
F_37 ( V_10 , 2 ) ;
V_10 -> V_11 [ 0 ] = V_12 ;
V_10 -> V_11 [ 1 ] = V_13 ;
F_32 () ;
F_33 ( V_4 , V_10 , V_4 -> V_55 ) ;
F_34 () ;
F_3 ( V_60 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_63:
F_3 ( V_60 ) ;
V_62:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_38 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_29 -> V_2 ;
struct V_14 * V_2 = V_3 -> V_64 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_2 ) {
F_39 ( V_2 , V_65 ) ;
F_40 ( V_4 ) ;
}
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
if ( V_4 ) {
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_42 ( V_4 ) ;
}
}
static int F_43 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_46 ;
F_44 ( V_3 ) ;
if ( F_24 ( V_3 , V_44 ) != 0 )
goto error;
F_45 ( V_3 ) ;
V_3 -> V_21 = V_66 ;
F_46 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_49 ( & V_3 -> V_67 ) ;
F_49 ( & V_3 -> V_68 ) ;
F_50 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_50 ( V_3 ) ;
return error ;
}
static int F_51 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_69 ;
V_69 = F_52 ( V_3 , V_10 ) ;
if ( V_69 )
F_12 ( V_10 ) ;
return V_70 ;
}
static int F_53 ( struct V_71 * V_71 , struct V_14 * V_2 , int V_72 )
{
int error = - V_52 ;
struct V_2 * V_3 ;
V_3 = F_54 ( V_71 , V_73 , V_56 , & V_74 , V_72 ) ;
if ( ! V_3 )
goto V_6;
F_55 ( V_2 , V_3 ) ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = & V_78 ;
V_3 -> V_79 = F_51 ;
V_3 -> V_80 = V_81 ;
V_3 -> V_82 = V_73 ;
V_3 -> V_21 = V_83 ;
V_3 -> V_84 = V_85 ;
V_3 -> V_86 = F_41 ;
error = 0 ;
V_6:
return error ;
}
static void F_56 ( struct V_87 * V_38 , void * V_88 )
{
struct V_1 * V_4 = V_88 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 ) {
struct V_31 * V_32 = F_16 ( V_29 -> V_2 ) ;
if ( V_32 )
F_57 ( V_38 , L_4 , F_58 ( & V_32 -> V_35 ) ) ;
}
}
static int F_59 ( struct V_14 * V_2 , struct V_89 * V_90 ,
int V_91 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_31 * V_32 = F_16 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
struct V_94 * V_95 ;
struct V_96 V_97 = { 0 , } ;
int error = 0 ;
T_2 V_98 , V_99 ;
T_2 V_100 , V_101 ;
int V_102 = 2 ;
int V_103 ;
F_44 ( V_3 ) ;
error = - V_104 ;
if ( V_93 -> V_105 != V_81 )
goto V_23;
error = - V_106 ;
if ( V_3 -> V_21 & V_45 )
goto V_23;
error = - V_107 ;
if ( V_3 -> V_5 )
goto V_23;
V_99 = 0 ;
if ( V_91 == sizeof( struct V_92 ) ) {
V_103 = V_93 -> V_108 . V_103 ;
V_98 = V_93 -> V_108 . V_109 ;
V_99 = V_93 -> V_108 . V_110 ;
V_100 = V_93 -> V_108 . V_111 ;
V_101 = V_93 -> V_108 . V_112 ;
} else if ( V_91 == sizeof( struct V_113 ) ) {
struct V_113 * V_114 =
(struct V_113 * ) V_93 ;
V_102 = 3 ;
V_103 = V_114 -> V_108 . V_103 ;
V_98 = V_114 -> V_108 . V_109 ;
V_99 = V_114 -> V_108 . V_110 ;
V_100 = V_114 -> V_108 . V_111 ;
V_101 = V_114 -> V_108 . V_112 ;
} else if ( V_91 == sizeof( struct V_115 ) ) {
struct V_115 * V_116 =
(struct V_115 * ) V_93 ;
V_103 = V_116 -> V_108 . V_103 ;
V_98 = V_116 -> V_108 . V_109 ;
V_99 = V_116 -> V_108 . V_110 ;
V_100 = V_116 -> V_108 . V_111 ;
V_101 = V_116 -> V_108 . V_112 ;
} else if ( V_91 == sizeof( struct V_117 ) ) {
struct V_117 * V_116 =
(struct V_117 * ) V_93 ;
V_102 = 3 ;
V_103 = V_116 -> V_108 . V_103 ;
V_98 = V_116 -> V_108 . V_109 ;
V_99 = V_116 -> V_108 . V_110 ;
V_100 = V_116 -> V_108 . V_111 ;
V_101 = V_116 -> V_108 . V_112 ;
} else {
error = - V_104 ;
goto V_23;
}
error = - V_104 ;
if ( V_98 == 0 )
goto V_23;
V_41 = F_60 ( F_61 ( V_3 ) , V_98 ) ;
if ( ( V_100 == 0 ) && ( V_101 == 0 ) ) {
if ( V_41 == NULL ) {
struct V_118 V_119 = {
. V_49 = V_50 ,
. V_120 = 0 ,
} ;
error = F_62 ( F_61 ( V_3 ) , V_103 , V_102 , V_98 , V_99 , & V_119 , & V_41 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_121 ;
if ( V_41 == NULL )
goto V_23;
if ( V_41 -> V_2 == NULL )
goto V_23;
}
if ( V_41 -> V_122 == NULL )
V_41 -> V_122 = F_5 ;
if ( V_41 -> V_99 == 0 )
V_41 -> V_99 = V_99 ;
V_4 = F_63 ( F_61 ( V_3 ) , V_41 , V_100 ) ;
if ( V_4 == NULL ) {
V_97 . V_123 = V_97 . V_124 = 1500 - V_125 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , & V_97 ) ;
if ( V_4 == NULL ) {
error = - V_52 ;
goto V_23;
}
} else {
V_29 = F_14 ( V_4 ) ;
error = - V_126 ;
if ( V_29 -> V_2 != NULL )
goto V_23;
if ( V_29 -> V_47 != V_41 -> V_2 )
goto V_23;
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_127 = V_128 -> V_129 ;
V_29 -> V_2 = V_3 ;
V_29 -> V_47 = V_41 -> V_2 ;
V_4 -> V_130 = F_13 ;
V_4 -> V_131 = F_38 ;
#if F_65 ( V_132 )
V_4 -> V_133 = F_56 ;
#endif
V_4 -> V_134 = F_21 ;
V_4 -> V_135 = F_22 ;
V_95 = F_66 ( V_41 -> V_2 ) ;
if ( V_95 != NULL ) {
T_2 V_136 = F_67 ( V_95 ) ;
if ( V_136 != 0 )
V_4 -> V_123 = V_4 -> V_124 = V_136 -
V_125 ;
F_68 ( V_95 ) ;
}
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
error = 0 ;
goto V_137;
}
V_32 -> V_35 . V_138 = V_139 ;
V_32 -> V_35 . V_59 = V_3 ;
V_32 -> V_35 . V_77 = & V_140 ;
V_32 -> V_35 . V_123 = V_4 -> V_123 ;
error = F_69 ( F_61 ( V_3 ) , & V_32 -> V_35 ) ;
if ( error )
goto V_23;
V_137:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_45 ;
F_20 ( V_4 , V_141 , L_5 ,
V_4 -> V_34 ) ;
V_23:
F_50 ( V_3 ) ;
return error ;
}
static int F_70 ( struct V_71 * V_71 , T_2 V_98 , T_2 V_100 , T_2 V_101 , struct V_96 * V_97 )
{
int error ;
struct V_40 * V_41 ;
struct V_1 * V_4 ;
struct V_28 * V_29 ;
V_41 = F_60 ( V_71 , V_98 ) ;
error = - V_121 ;
if ( V_41 == NULL )
goto V_6;
if ( V_41 -> V_2 == NULL )
goto V_6;
error = - V_126 ;
V_4 = F_63 ( V_71 , V_41 , V_100 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_97 -> V_123 == 0 )
V_97 -> V_123 = 1500 - V_125 ;
if ( V_97 -> V_124 == 0 )
V_97 -> V_124 = V_97 -> V_123 ;
error = - V_52 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , V_97 ) ;
if ( V_4 == NULL )
goto V_6;
V_29 = F_14 ( V_4 ) ;
V_29 -> V_47 = V_41 -> V_2 ;
F_20 ( V_4 , V_141 , L_5 ,
V_4 -> V_34 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_71 ( struct V_14 * V_2 , struct V_89 * V_142 ,
int * V_143 , int V_144 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_145 * V_146 ;
struct V_28 * V_147 ;
error = - V_43 ;
if ( V_3 == NULL )
goto V_23;
if ( ! ( V_3 -> V_21 & V_45 ) )
goto V_23;
error = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_147 = F_14 ( V_4 ) ;
V_41 = F_25 ( V_147 -> V_47 ) ;
if ( V_41 == NULL )
goto V_148;
V_146 = F_72 ( V_41 -> V_2 ) ;
if ( ( V_41 -> V_149 == 2 ) && ( V_41 -> V_2 -> V_82 == V_150 ) ) {
struct V_92 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_151 = V_152 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_41 -> V_103 ;
V_93 . V_108 . V_129 = V_147 -> V_127 ;
V_93 . V_108 . V_109 = V_41 -> V_98 ;
V_93 . V_108 . V_110 = V_41 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_153 . V_154 = V_150 ;
V_93 . V_108 . V_153 . V_155 = V_146 -> V_156 ;
V_93 . V_108 . V_153 . V_157 . V_158 = V_146 -> V_159 ;
memcpy ( V_142 , & V_93 , V_17 ) ;
#if F_65 ( V_160 )
} else if ( ( V_41 -> V_149 == 2 ) &&
( V_41 -> V_2 -> V_82 == V_161 ) ) {
struct V_115 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_151 = V_152 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_41 -> V_103 ;
V_93 . V_108 . V_129 = V_147 -> V_127 ;
V_93 . V_108 . V_109 = V_41 -> V_98 ;
V_93 . V_108 . V_110 = V_41 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_153 . V_162 = V_161 ;
V_93 . V_108 . V_153 . V_163 = V_146 -> V_156 ;
memcpy ( & V_93 . V_108 . V_153 . V_164 , & V_41 -> V_2 -> V_165 ,
sizeof( V_41 -> V_2 -> V_165 ) ) ;
memcpy ( V_142 , & V_93 , V_17 ) ;
} else if ( ( V_41 -> V_149 == 3 ) &&
( V_41 -> V_2 -> V_82 == V_161 ) ) {
struct V_117 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_151 = V_152 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_41 -> V_103 ;
V_93 . V_108 . V_129 = V_147 -> V_127 ;
V_93 . V_108 . V_109 = V_41 -> V_98 ;
V_93 . V_108 . V_110 = V_41 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_153 . V_162 = V_161 ;
V_93 . V_108 . V_153 . V_163 = V_146 -> V_156 ;
memcpy ( & V_93 . V_108 . V_153 . V_164 , & V_41 -> V_2 -> V_165 ,
sizeof( V_41 -> V_2 -> V_165 ) ) ;
memcpy ( V_142 , & V_93 , V_17 ) ;
#endif
} else if ( V_41 -> V_149 == 3 ) {
struct V_113 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_151 = V_152 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_41 -> V_103 ;
V_93 . V_108 . V_129 = V_147 -> V_127 ;
V_93 . V_108 . V_109 = V_41 -> V_98 ;
V_93 . V_108 . V_110 = V_41 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_153 . V_154 = V_150 ;
V_93 . V_108 . V_153 . V_155 = V_146 -> V_156 ;
V_93 . V_108 . V_153 . V_157 . V_158 = V_146 -> V_159 ;
memcpy ( V_142 , & V_93 , V_17 ) ;
}
* V_143 = V_17 ;
error = 0 ;
F_3 ( V_147 -> V_47 ) ;
V_148:
F_3 ( V_3 ) ;
V_23:
return error ;
}
static void F_73 ( struct V_166 * V_167 ,
struct V_168 * V_36 )
{
V_167 -> V_169 = F_74 ( & V_36 -> V_169 ) ;
V_167 -> V_170 = F_74 ( & V_36 -> V_170 ) ;
V_167 -> V_171 = F_74 ( & V_36 -> V_171 ) ;
V_167 -> V_172 = F_74 ( & V_36 -> V_172 ) ;
V_167 -> V_173 = F_74 ( & V_36 -> V_173 ) ;
V_167 -> V_174 = F_74 ( & V_36 -> V_174 ) ;
V_167 -> V_175 = F_74 ( & V_36 -> V_175 ) ;
V_167 -> V_37 = F_74 ( & V_36 -> V_37 ) ;
}
static int F_75 ( struct V_1 * V_4 ,
unsigned int V_176 , unsigned long V_88 )
{
struct V_177 V_178 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_179 = ( int ) V_88 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_166 V_36 ;
F_15 ( V_4 , V_141 ,
L_6 ,
V_4 -> V_34 , V_176 , V_88 ) ;
V_3 = V_29 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_176 ) {
case V_180 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_182 ;
if ( F_76 ( & V_178 , ( void V_183 * ) V_88 , sizeof( struct V_177 ) ) )
break;
V_178 . V_184 = V_4 -> V_123 ;
if ( F_77 ( ( void V_183 * ) V_88 , & V_178 , sizeof( struct V_177 ) ) )
break;
F_20 ( V_4 , V_141 , L_7 ,
V_4 -> V_34 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_185 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_182 ;
if ( F_76 ( & V_178 , ( void V_183 * ) V_88 , sizeof( struct V_177 ) ) )
break;
V_4 -> V_123 = V_178 . V_184 ;
F_20 ( V_4 , V_141 , L_8 ,
V_4 -> V_34 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_186 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_182 ;
if ( F_78 ( V_4 -> V_124 , ( int V_183 * ) V_88 ) )
break;
F_20 ( V_4 , V_141 , L_9 ,
V_4 -> V_34 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_187 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_182 ;
if ( F_79 ( V_179 , ( int V_183 * ) V_88 ) )
break;
V_4 -> V_124 = V_179 ;
F_20 ( V_4 , V_141 , L_10 ,
V_4 -> V_34 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_182 ;
if ( F_78 ( V_29 -> V_18 , ( int V_183 * ) V_88 ) )
break;
F_20 ( V_4 , V_141 , L_11 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_182 ;
if ( F_79 ( V_179 , ( int V_183 * ) V_88 ) )
break;
V_29 -> V_18 = V_179 ;
F_20 ( V_4 , V_141 , L_12 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_98 = V_41 -> V_98 ;
V_36 . V_100 = V_4 -> V_100 ;
F_73 ( & V_36 , & V_4 -> V_36 ) ;
if ( F_77 ( ( void V_183 * ) V_88 , & V_36 ,
sizeof( V_36 ) ) )
break;
F_20 ( V_4 , V_141 , L_13 ,
V_4 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_191 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_80 ( struct V_40 * V_41 ,
unsigned int V_176 , unsigned long V_88 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_166 V_36 ;
F_15 ( V_41 , V_141 ,
L_14 ,
V_41 -> V_34 , V_176 , V_88 ) ;
V_3 = V_41 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_176 ) {
case V_190 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
if ( F_76 ( & V_36 , ( void V_183 * ) V_88 ,
sizeof( V_36 ) ) ) {
V_19 = - V_182 ;
break;
}
if ( V_36 . V_100 != 0 ) {
struct V_1 * V_4 =
F_63 ( F_61 ( V_3 ) , V_41 , V_36 . V_100 ) ;
if ( V_4 != NULL )
V_19 = F_75 ( V_4 , V_176 , V_88 ) ;
else
V_19 = - V_192 ;
break;
}
#ifdef F_81
V_36 . V_193 = ( V_3 -> V_194 [ 0 ] || V_3 -> V_194 [ 1 ] ) ? 1 : 0 ;
#endif
F_73 ( & V_36 , & V_41 -> V_36 ) ;
if ( F_77 ( ( void V_183 * ) V_88 , & V_36 , sizeof( V_36 ) ) ) {
V_19 = - V_182 ;
break;
}
F_20 ( V_41 , V_141 , L_13 ,
V_41 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_191 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_82 ( struct V_14 * V_2 , unsigned int V_176 ,
unsigned long V_88 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_46 ;
if ( F_24 ( V_3 , V_44 ) != 0 )
goto V_23;
V_19 = - V_43 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_21 & ( V_45 | V_22 ) ) ) )
goto V_23;
V_19 = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_46 ;
V_41 = F_25 ( V_29 -> V_47 ) ;
if ( V_41 == NULL )
goto V_148;
V_19 = F_80 ( V_41 , V_176 , V_88 ) ;
F_3 ( V_29 -> V_47 ) ;
goto V_148;
}
V_19 = F_75 ( V_4 , V_176 , V_88 ) ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_195 , int V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_196 :
V_41 -> V_120 = V_179 ;
F_20 ( V_41 , V_141 , L_15 ,
V_41 -> V_34 , V_41 -> V_120 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_195 , int V_179 )
{
int V_19 = 0 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
switch ( V_195 ) {
case V_198 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_199 = ! ! V_179 ;
F_20 ( V_4 , V_141 ,
L_16 ,
V_4 -> V_34 , V_4 -> V_199 ) ;
break;
case V_200 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_201 = ! ! V_179 ;
{
struct V_2 * V_202 = V_29 -> V_2 ;
struct V_31 * V_32 = F_16 ( V_202 ) ;
V_32 -> V_35 . V_138 = V_179 ? V_203 :
V_139 ;
}
F_85 ( V_4 , V_4 -> V_41 -> V_149 ) ;
F_20 ( V_4 , V_141 ,
L_17 ,
V_4 -> V_34 , V_4 -> V_201 ) ;
break;
case V_204 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_205 = ! ! V_179 ;
F_20 ( V_4 , V_141 ,
L_18 ,
V_4 -> V_34 , V_4 -> V_205 ) ;
break;
case V_196 :
V_4 -> V_120 = V_179 ;
F_20 ( V_4 , V_141 , L_15 ,
V_4 -> V_34 , V_4 -> V_120 ) ;
break;
case V_206 :
V_4 -> V_207 = F_86 ( V_179 ) ;
F_20 ( V_4 , V_141 ,
L_19 ,
V_4 -> V_34 , V_4 -> V_207 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_87 ( struct V_14 * V_2 , int V_208 , int V_195 ,
char V_183 * V_209 , unsigned int V_210 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_179 ;
int V_19 ;
if ( V_208 != V_211 )
return - V_104 ;
if ( V_210 < sizeof( int ) )
return - V_104 ;
if ( F_79 ( V_179 , ( int V_183 * ) V_209 ) )
return - V_182 ;
V_19 = - V_43 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_46 ;
V_41 = F_25 ( V_29 -> V_47 ) ;
if ( V_41 == NULL )
goto V_148;
V_19 = F_83 ( V_3 , V_41 , V_195 , V_179 ) ;
F_3 ( V_29 -> V_47 ) ;
} else
V_19 = F_84 ( V_3 , V_4 , V_195 , V_179 ) ;
V_19 = 0 ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_195 , int * V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_196 :
* V_179 = V_41 -> V_120 ;
F_20 ( V_41 , V_141 , L_20 ,
V_41 -> V_34 , V_41 -> V_120 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_195 , int * V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_198 :
* V_179 = V_4 -> V_199 ;
F_20 ( V_4 , V_141 ,
L_21 , V_4 -> V_34 , * V_179 ) ;
break;
case V_200 :
* V_179 = V_4 -> V_201 ;
F_20 ( V_4 , V_141 ,
L_22 , V_4 -> V_34 , * V_179 ) ;
break;
case V_204 :
* V_179 = V_4 -> V_205 ;
F_20 ( V_4 , V_141 ,
L_23 , V_4 -> V_34 , * V_179 ) ;
break;
case V_196 :
* V_179 = V_4 -> V_120 ;
F_20 ( V_4 , V_141 , L_24 ,
V_4 -> V_34 , * V_179 ) ;
break;
case V_206 :
* V_179 = ( int ) F_90 ( V_4 -> V_207 ) ;
F_20 ( V_4 , V_141 ,
L_25 , V_4 -> V_34 , * V_179 ) ;
break;
default:
V_19 = - V_197 ;
}
return V_19 ;
}
static int F_91 ( struct V_14 * V_2 , int V_208 , int V_195 ,
char V_183 * V_209 , int V_183 * V_210 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
int V_179 , V_17 ;
int V_19 ;
struct V_28 * V_29 ;
if ( V_208 != V_211 )
return - V_104 ;
if ( F_79 ( V_17 , V_210 ) )
return - V_182 ;
V_17 = F_92 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_104 ;
V_19 = - V_43 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_46 ;
V_41 = F_25 ( V_29 -> V_47 ) ;
if ( V_41 == NULL )
goto V_148;
V_19 = F_88 ( V_3 , V_41 , V_195 , & V_179 ) ;
F_3 ( V_29 -> V_47 ) ;
} else
V_19 = F_89 ( V_3 , V_4 , V_195 , & V_179 ) ;
V_19 = - V_182 ;
if ( F_78 ( V_17 , V_210 ) )
goto V_148;
if ( F_77 ( ( void V_183 * ) V_209 , & V_179 , V_17 ) )
goto V_148;
V_19 = 0 ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_93 ( struct V_71 * V_71 , struct V_212 * V_213 )
{
for (; ; ) {
V_213 -> V_41 = F_94 ( V_71 , V_213 -> V_214 ) ;
V_213 -> V_214 ++ ;
if ( V_213 -> V_41 == NULL )
break;
if ( V_213 -> V_41 -> V_149 < 3 )
break;
}
}
static void F_95 ( struct V_71 * V_71 , struct V_212 * V_213 )
{
V_213 -> V_4 = F_96 ( V_213 -> V_41 , V_213 -> V_215 ) ;
V_213 -> V_215 ++ ;
if ( V_213 -> V_4 == NULL ) {
V_213 -> V_215 = 0 ;
F_93 ( V_71 , V_213 ) ;
}
}
static void * F_97 ( struct V_87 * V_38 , T_3 * V_216 )
{
struct V_212 * V_213 = V_217 ;
T_3 V_218 = * V_216 ;
struct V_71 * V_71 ;
if ( ! V_218 )
goto V_6;
F_4 ( V_38 -> V_59 == NULL ) ;
V_213 = V_38 -> V_59 ;
V_71 = F_98 ( V_38 ) ;
if ( V_213 -> V_41 == NULL )
F_93 ( V_71 , V_213 ) ;
else
F_95 ( V_71 , V_213 ) ;
if ( ( V_213 -> V_41 == NULL ) && ( V_213 -> V_4 == NULL ) )
V_213 = NULL ;
V_6:
return V_213 ;
}
static void * F_99 ( struct V_87 * V_38 , void * V_219 , T_3 * V_218 )
{
( * V_218 ) ++ ;
return NULL ;
}
static void F_100 ( struct V_87 * V_220 , void * V_219 )
{
}
static void F_101 ( struct V_87 * V_38 , void * V_219 )
{
struct V_40 * V_41 = V_219 ;
F_57 ( V_38 , L_26 ,
V_41 -> V_34 ,
( V_41 == V_41 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_102 ( & V_41 -> V_221 ) - 1 ) ;
F_57 ( V_38 , L_27 ,
V_41 -> V_120 ,
F_74 ( & V_41 -> V_36 . V_169 ) ,
F_74 ( & V_41 -> V_36 . V_170 ) ,
F_74 ( & V_41 -> V_36 . V_171 ) ,
F_74 ( & V_41 -> V_36 . V_172 ) ,
F_74 ( & V_41 -> V_36 . V_173 ) ,
F_74 ( & V_41 -> V_36 . V_37 ) ) ;
}
static void F_103 ( struct V_87 * V_38 , void * V_219 )
{
struct V_1 * V_4 = V_219 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_31 * V_32 = F_16 ( V_29 -> V_2 ) ;
T_2 V_222 = 0 ;
T_4 V_223 = 0 ;
if ( V_41 -> V_2 ) {
struct V_145 * V_146 = F_72 ( V_41 -> V_2 ) ;
V_222 = F_104 ( V_146 -> V_224 ) ;
V_223 = F_105 ( V_146 -> V_225 ) ;
}
F_57 ( V_38 , L_28
L_29 ,
V_4 -> V_34 , V_222 , V_223 ,
V_41 -> V_98 ,
V_4 -> V_100 ,
V_41 -> V_99 ,
V_4 -> V_101 ,
V_29 -> V_2 -> V_21 ,
( V_4 == V_29 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_57 ( V_38 , L_30 ,
V_4 -> V_123 , V_4 -> V_124 ,
V_4 -> V_199 ? 'R' : '-' ,
V_4 -> V_201 ? 'S' : '-' ,
V_4 -> V_205 ? L_31 : L_32 ,
V_4 -> V_120 ,
F_90 ( V_4 -> V_207 ) ) ;
F_57 ( V_38 , L_33 ,
V_4 -> V_226 , V_4 -> V_227 ,
F_74 ( & V_4 -> V_36 . V_169 ) ,
F_74 ( & V_4 -> V_36 . V_170 ) ,
F_74 ( & V_4 -> V_36 . V_171 ) ,
F_74 ( & V_4 -> V_36 . V_172 ) ,
F_74 ( & V_4 -> V_36 . V_173 ) ,
F_74 ( & V_4 -> V_36 . V_37 ) ) ;
if ( V_32 )
F_57 ( V_38 , L_4 , F_58 ( & V_32 -> V_35 ) ) ;
}
static int F_106 ( struct V_87 * V_38 , void * V_219 )
{
struct V_212 * V_213 = V_219 ;
if ( V_219 == V_217 ) {
F_107 ( V_38 , L_34 V_228 L_35 ) ;
F_107 ( V_38 , L_36 ) ;
F_107 ( V_38 , L_37 ) ;
F_107 ( V_38 , L_38
L_39 ) ;
F_107 ( V_38 , L_40 ) ;
F_107 ( V_38 , L_41 ) ;
goto V_6;
}
if ( V_213 -> V_4 == NULL )
F_101 ( V_38 , V_213 -> V_41 ) ;
else
F_103 ( V_38 , V_213 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_108 ( struct V_229 * V_229 , struct V_230 * V_230 )
{
return F_109 ( V_229 , V_230 , & V_231 ,
sizeof( struct V_212 ) ) ;
}
static T_5 int F_110 ( struct V_71 * V_71 )
{
struct V_232 * V_233 ;
int V_19 = 0 ;
V_233 = F_111 ( L_42 , V_234 , V_71 -> V_235 ,
& V_236 ) ;
if ( ! V_233 ) {
V_19 = - V_52 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_6 void F_112 ( struct V_71 * V_71 )
{
F_113 ( L_42 , V_71 -> V_235 ) ;
}
static int T_7 F_114 ( void )
{
int V_19 ;
V_19 = F_115 ( & V_237 ) ;
if ( V_19 )
goto V_6;
V_19 = F_116 ( & V_74 , 0 ) ;
if ( V_19 )
goto V_238;
V_19 = F_117 ( V_81 , & V_239 ) ;
if ( V_19 )
goto V_240;
#ifdef F_118
V_19 = F_119 ( V_241 , & V_242 ) ;
if ( V_19 )
goto V_243;
#endif
F_120 ( L_43 , V_228 ) ;
V_6:
return V_19 ;
#ifdef F_118
V_243:
F_121 ( V_81 ) ;
#endif
V_240:
F_122 ( & V_74 ) ;
V_238:
F_123 ( & V_237 ) ;
goto V_6;
}
static void T_8 F_124 ( void )
{
#ifdef F_118
F_125 ( V_241 ) ;
#endif
F_121 ( V_81 ) ;
F_122 ( & V_74 ) ;
F_123 ( & V_237 ) ;
}
