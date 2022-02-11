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
if ( V_2 )
F_39 ( V_2 , V_65 ) ;
F_40 ( V_4 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
F_42 ( & V_3 -> V_66 ) ;
F_42 ( & V_3 -> V_67 ) ;
if ( V_4 ) {
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_43 ( V_4 ) ;
}
}
static int F_44 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_46 ;
F_45 ( V_3 ) ;
if ( F_24 ( V_3 , V_44 ) != 0 )
goto error;
F_46 ( V_3 ) ;
V_3 -> V_21 = V_68 ;
F_47 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_48 ( V_4 ) ;
F_49 ( V_4 ) ;
F_3 ( V_3 ) ;
}
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
bool V_102 = false ;
bool V_103 = false ;
int V_104 = 2 ;
int V_105 ;
F_45 ( V_3 ) ;
error = - V_106 ;
if ( V_93 -> V_107 != V_81 )
goto V_23;
error = - V_108 ;
if ( V_3 -> V_21 & V_45 )
goto V_23;
error = - V_109 ;
if ( V_3 -> V_5 )
goto V_23;
V_99 = 0 ;
if ( V_91 == sizeof( struct V_92 ) ) {
V_105 = V_93 -> V_110 . V_105 ;
V_98 = V_93 -> V_110 . V_111 ;
V_99 = V_93 -> V_110 . V_112 ;
V_100 = V_93 -> V_110 . V_113 ;
V_101 = V_93 -> V_110 . V_114 ;
} else if ( V_91 == sizeof( struct V_115 ) ) {
struct V_115 * V_116 =
(struct V_115 * ) V_93 ;
V_104 = 3 ;
V_105 = V_116 -> V_110 . V_105 ;
V_98 = V_116 -> V_110 . V_111 ;
V_99 = V_116 -> V_110 . V_112 ;
V_100 = V_116 -> V_110 . V_113 ;
V_101 = V_116 -> V_110 . V_114 ;
} else if ( V_91 == sizeof( struct V_117 ) ) {
struct V_117 * V_118 =
(struct V_117 * ) V_93 ;
V_105 = V_118 -> V_110 . V_105 ;
V_98 = V_118 -> V_110 . V_111 ;
V_99 = V_118 -> V_110 . V_112 ;
V_100 = V_118 -> V_110 . V_113 ;
V_101 = V_118 -> V_110 . V_114 ;
} else if ( V_91 == sizeof( struct V_119 ) ) {
struct V_119 * V_118 =
(struct V_119 * ) V_93 ;
V_104 = 3 ;
V_105 = V_118 -> V_110 . V_105 ;
V_98 = V_118 -> V_110 . V_111 ;
V_99 = V_118 -> V_110 . V_112 ;
V_100 = V_118 -> V_110 . V_113 ;
V_101 = V_118 -> V_110 . V_114 ;
} else {
error = - V_106 ;
goto V_23;
}
error = - V_106 ;
if ( V_98 == 0 )
goto V_23;
V_41 = F_60 ( F_61 ( V_3 ) , V_98 ) ;
if ( V_41 )
V_103 = true ;
if ( ( V_100 == 0 ) && ( V_101 == 0 ) ) {
if ( V_41 == NULL ) {
struct V_120 V_121 = {
. V_49 = V_50 ,
. V_122 = 0 ,
} ;
error = F_62 ( F_61 ( V_3 ) , V_105 , V_104 , V_98 , V_99 , & V_121 , & V_41 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_123 ;
if ( V_41 == NULL )
goto V_23;
if ( V_41 -> V_2 == NULL )
goto V_23;
}
if ( V_41 -> V_124 == NULL )
V_41 -> V_124 = F_5 ;
if ( V_41 -> V_99 == 0 )
V_41 -> V_99 = V_99 ;
V_4 = F_63 ( F_61 ( V_3 ) , V_41 , V_100 , false ) ;
if ( V_4 ) {
V_102 = true ;
V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 ) {
error = - V_125 ;
goto V_23;
}
if ( V_29 -> V_47 != V_41 -> V_2 ) {
error = - V_125 ;
goto V_23;
}
} else {
V_97 . V_126 = 1500 - V_127 ;
V_97 . V_128 = V_97 . V_126 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , & V_97 ) ;
if ( F_65 ( V_4 ) ) {
error = F_66 ( V_4 ) ;
goto V_23;
}
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_129 = V_130 -> V_131 ;
V_29 -> V_2 = V_3 ;
V_29 -> V_47 = V_41 -> V_2 ;
V_4 -> V_132 = F_13 ;
V_4 -> V_133 = F_38 ;
#if F_67 ( V_134 )
V_4 -> V_135 = F_56 ;
#endif
V_4 -> V_136 = F_21 ;
V_4 -> V_137 = F_22 ;
V_95 = F_68 ( V_41 -> V_2 ) ;
if ( V_95 != NULL ) {
T_2 V_138 = F_69 ( V_95 ) ;
if ( V_138 != 0 )
V_4 -> V_126 = V_4 -> V_128 = V_138 -
V_127 ;
F_70 ( V_95 ) ;
}
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
error = 0 ;
goto V_139;
}
V_32 -> V_35 . V_140 = V_141 ;
V_32 -> V_35 . V_59 = V_3 ;
V_32 -> V_35 . V_77 = & V_142 ;
V_32 -> V_35 . V_126 = V_4 -> V_126 ;
error = F_71 ( F_61 ( V_3 ) , & V_32 -> V_35 ) ;
if ( error )
goto V_23;
V_139:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_45 ;
F_20 ( V_4 , V_143 , L_5 ,
V_4 -> V_34 ) ;
V_23:
if ( V_102 )
F_43 ( V_4 ) ;
if ( V_103 )
F_72 ( V_41 ) ;
F_50 ( V_3 ) ;
return error ;
}
static int F_73 ( struct V_71 * V_71 , struct V_40 * V_41 ,
T_2 V_100 , T_2 V_101 ,
struct V_96 * V_97 )
{
int error ;
struct V_1 * V_4 ;
struct V_28 * V_29 ;
if ( ! V_41 -> V_2 ) {
error = - V_123 ;
goto V_6;
}
if ( V_97 -> V_126 == 0 )
V_97 -> V_126 = 1500 - V_127 ;
if ( V_97 -> V_128 == 0 )
V_97 -> V_128 = V_97 -> V_126 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , V_97 ) ;
if ( F_65 ( V_4 ) ) {
error = F_66 ( V_4 ) ;
goto V_6;
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_47 = V_41 -> V_2 ;
F_20 ( V_4 , V_143 , L_5 ,
V_4 -> V_34 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_74 ( struct V_14 * V_2 , struct V_89 * V_144 ,
int * V_145 , int V_146 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_147 * V_148 ;
struct V_28 * V_149 ;
error = - V_43 ;
if ( V_3 == NULL )
goto V_23;
if ( ! ( V_3 -> V_21 & V_45 ) )
goto V_23;
error = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_149 = F_14 ( V_4 ) ;
V_41 = F_25 ( V_149 -> V_47 ) ;
if ( V_41 == NULL )
goto V_150;
V_148 = F_75 ( V_41 -> V_2 ) ;
if ( ( V_41 -> V_151 == 2 ) && ( V_41 -> V_2 -> V_82 == V_152 ) ) {
struct V_92 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_153 = V_154 ;
V_93 . V_107 = V_81 ;
V_93 . V_110 . V_105 = V_41 -> V_105 ;
V_93 . V_110 . V_131 = V_149 -> V_129 ;
V_93 . V_110 . V_111 = V_41 -> V_98 ;
V_93 . V_110 . V_112 = V_41 -> V_99 ;
V_93 . V_110 . V_113 = V_4 -> V_100 ;
V_93 . V_110 . V_114 = V_4 -> V_101 ;
V_93 . V_110 . V_155 . V_156 = V_152 ;
V_93 . V_110 . V_155 . V_157 = V_148 -> V_158 ;
V_93 . V_110 . V_155 . V_159 . V_160 = V_148 -> V_161 ;
memcpy ( V_144 , & V_93 , V_17 ) ;
#if F_67 ( V_162 )
} else if ( ( V_41 -> V_151 == 2 ) &&
( V_41 -> V_2 -> V_82 == V_163 ) ) {
struct V_117 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_153 = V_154 ;
V_93 . V_107 = V_81 ;
V_93 . V_110 . V_105 = V_41 -> V_105 ;
V_93 . V_110 . V_131 = V_149 -> V_129 ;
V_93 . V_110 . V_111 = V_41 -> V_98 ;
V_93 . V_110 . V_112 = V_41 -> V_99 ;
V_93 . V_110 . V_113 = V_4 -> V_100 ;
V_93 . V_110 . V_114 = V_4 -> V_101 ;
V_93 . V_110 . V_155 . V_164 = V_163 ;
V_93 . V_110 . V_155 . V_165 = V_148 -> V_158 ;
memcpy ( & V_93 . V_110 . V_155 . V_166 , & V_41 -> V_2 -> V_167 ,
sizeof( V_41 -> V_2 -> V_167 ) ) ;
memcpy ( V_144 , & V_93 , V_17 ) ;
} else if ( ( V_41 -> V_151 == 3 ) &&
( V_41 -> V_2 -> V_82 == V_163 ) ) {
struct V_119 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_153 = V_154 ;
V_93 . V_107 = V_81 ;
V_93 . V_110 . V_105 = V_41 -> V_105 ;
V_93 . V_110 . V_131 = V_149 -> V_129 ;
V_93 . V_110 . V_111 = V_41 -> V_98 ;
V_93 . V_110 . V_112 = V_41 -> V_99 ;
V_93 . V_110 . V_113 = V_4 -> V_100 ;
V_93 . V_110 . V_114 = V_4 -> V_101 ;
V_93 . V_110 . V_155 . V_164 = V_163 ;
V_93 . V_110 . V_155 . V_165 = V_148 -> V_158 ;
memcpy ( & V_93 . V_110 . V_155 . V_166 , & V_41 -> V_2 -> V_167 ,
sizeof( V_41 -> V_2 -> V_167 ) ) ;
memcpy ( V_144 , & V_93 , V_17 ) ;
#endif
} else if ( V_41 -> V_151 == 3 ) {
struct V_115 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_153 = V_154 ;
V_93 . V_107 = V_81 ;
V_93 . V_110 . V_105 = V_41 -> V_105 ;
V_93 . V_110 . V_131 = V_149 -> V_129 ;
V_93 . V_110 . V_111 = V_41 -> V_98 ;
V_93 . V_110 . V_112 = V_41 -> V_99 ;
V_93 . V_110 . V_113 = V_4 -> V_100 ;
V_93 . V_110 . V_114 = V_4 -> V_101 ;
V_93 . V_110 . V_155 . V_156 = V_152 ;
V_93 . V_110 . V_155 . V_157 = V_148 -> V_158 ;
V_93 . V_110 . V_155 . V_159 . V_160 = V_148 -> V_161 ;
memcpy ( V_144 , & V_93 , V_17 ) ;
}
* V_145 = V_17 ;
error = 0 ;
F_3 ( V_149 -> V_47 ) ;
V_150:
F_3 ( V_3 ) ;
V_23:
return error ;
}
static void F_76 ( struct V_168 * V_169 ,
struct V_170 * V_36 )
{
V_169 -> V_171 = F_77 ( & V_36 -> V_171 ) ;
V_169 -> V_172 = F_77 ( & V_36 -> V_172 ) ;
V_169 -> V_173 = F_77 ( & V_36 -> V_173 ) ;
V_169 -> V_174 = F_77 ( & V_36 -> V_174 ) ;
V_169 -> V_175 = F_77 ( & V_36 -> V_175 ) ;
V_169 -> V_176 = F_77 ( & V_36 -> V_176 ) ;
V_169 -> V_177 = F_77 ( & V_36 -> V_177 ) ;
V_169 -> V_37 = F_77 ( & V_36 -> V_37 ) ;
}
static int F_78 ( struct V_1 * V_4 ,
unsigned int V_178 , unsigned long V_88 )
{
struct V_179 V_180 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_181 = ( int ) V_88 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_168 V_36 ;
F_15 ( V_4 , V_143 ,
L_6 ,
V_4 -> V_34 , V_178 , V_88 ) ;
V_3 = V_29 -> V_2 ;
if ( ! V_3 )
return - V_182 ;
F_2 ( V_3 ) ;
switch ( V_178 ) {
case V_183 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_185 ;
if ( F_79 ( & V_180 , ( void V_186 * ) V_88 , sizeof( struct V_179 ) ) )
break;
V_180 . V_187 = V_4 -> V_126 ;
if ( F_80 ( ( void V_186 * ) V_88 , & V_180 , sizeof( struct V_179 ) ) )
break;
F_20 ( V_4 , V_143 , L_7 ,
V_4 -> V_34 , V_4 -> V_126 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_185 ;
if ( F_79 ( & V_180 , ( void V_186 * ) V_88 , sizeof( struct V_179 ) ) )
break;
V_4 -> V_126 = V_180 . V_187 ;
F_20 ( V_4 , V_143 , L_8 ,
V_4 -> V_34 , V_4 -> V_126 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_185 ;
if ( F_81 ( V_4 -> V_128 , ( int V_186 * ) V_88 ) )
break;
F_20 ( V_4 , V_143 , L_9 ,
V_4 -> V_34 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_185 ;
if ( F_82 ( V_181 , ( int V_186 * ) V_88 ) )
break;
V_4 -> V_128 = V_181 ;
F_20 ( V_4 , V_143 , L_10 ,
V_4 -> V_34 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_191 :
V_19 = - V_185 ;
if ( F_81 ( V_29 -> V_18 , ( int V_186 * ) V_88 ) )
break;
F_20 ( V_4 , V_143 , L_11 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_192 :
V_19 = - V_185 ;
if ( F_82 ( V_181 , ( int V_186 * ) V_88 ) )
break;
V_29 -> V_18 = V_181 ;
F_20 ( V_4 , V_143 , L_12 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_193 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_98 = V_41 -> V_98 ;
V_36 . V_100 = V_4 -> V_100 ;
F_76 ( & V_36 , & V_4 -> V_36 ) ;
if ( F_80 ( ( void V_186 * ) V_88 , & V_36 ,
sizeof( V_36 ) ) )
break;
F_20 ( V_4 , V_143 , L_13 ,
V_4 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_194 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_83 ( struct V_40 * V_41 ,
unsigned int V_178 , unsigned long V_88 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_168 V_36 ;
F_15 ( V_41 , V_143 ,
L_14 ,
V_41 -> V_34 , V_178 , V_88 ) ;
V_3 = V_41 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_178 ) {
case V_193 :
V_19 = - V_184 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
if ( F_79 ( & V_36 , ( void V_186 * ) V_88 ,
sizeof( V_36 ) ) ) {
V_19 = - V_185 ;
break;
}
if ( V_36 . V_100 != 0 ) {
struct V_1 * V_4 =
F_63 ( F_61 ( V_3 ) , V_41 ,
V_36 . V_100 , true ) ;
if ( V_4 ) {
V_19 = F_78 ( V_4 , V_178 ,
V_88 ) ;
if ( V_4 -> V_137 )
V_4 -> V_137 ( V_4 ) ;
F_43 ( V_4 ) ;
} else {
V_19 = - V_182 ;
}
break;
}
#ifdef F_84
V_36 . V_195 = ( V_3 -> V_196 [ 0 ] || V_3 -> V_196 [ 1 ] ) ? 1 : 0 ;
#endif
F_76 ( & V_36 , & V_41 -> V_36 ) ;
if ( F_80 ( ( void V_186 * ) V_88 , & V_36 , sizeof( V_36 ) ) ) {
V_19 = - V_185 ;
break;
}
F_20 ( V_41 , V_143 , L_13 ,
V_41 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_194 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_85 ( struct V_14 * V_2 , unsigned int V_178 ,
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
goto V_150;
V_19 = F_83 ( V_41 , V_178 , V_88 ) ;
F_3 ( V_29 -> V_47 ) ;
goto V_150;
}
V_19 = F_78 ( V_4 , V_178 , V_88 ) ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_197 , int V_181 )
{
int V_19 = 0 ;
switch ( V_197 ) {
case V_198 :
V_41 -> V_122 = V_181 ;
F_20 ( V_41 , V_143 , L_15 ,
V_41 -> V_34 , V_41 -> V_122 ) ;
break;
default:
V_19 = - V_199 ;
break;
}
return V_19 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_197 , int V_181 )
{
int V_19 = 0 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
switch ( V_197 ) {
case V_200 :
if ( ( V_181 != 0 ) && ( V_181 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_201 = ! ! V_181 ;
F_20 ( V_4 , V_143 ,
L_16 ,
V_4 -> V_34 , V_4 -> V_201 ) ;
break;
case V_202 :
if ( ( V_181 != 0 ) && ( V_181 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_203 = ! ! V_181 ;
{
struct V_2 * V_204 = V_29 -> V_2 ;
struct V_31 * V_32 = F_16 ( V_204 ) ;
V_32 -> V_35 . V_140 = V_181 ? V_205 :
V_141 ;
}
F_88 ( V_4 , V_4 -> V_41 -> V_151 ) ;
F_20 ( V_4 , V_143 ,
L_17 ,
V_4 -> V_34 , V_4 -> V_203 ) ;
break;
case V_206 :
if ( ( V_181 != 0 ) && ( V_181 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_207 = ! ! V_181 ;
F_20 ( V_4 , V_143 ,
L_18 ,
V_4 -> V_34 , V_4 -> V_207 ) ;
break;
case V_198 :
V_4 -> V_122 = V_181 ;
F_20 ( V_4 , V_143 , L_15 ,
V_4 -> V_34 , V_4 -> V_122 ) ;
break;
case V_208 :
V_4 -> V_209 = F_89 ( V_181 ) ;
F_20 ( V_4 , V_143 ,
L_19 ,
V_4 -> V_34 , V_4 -> V_209 ) ;
break;
default:
V_19 = - V_199 ;
break;
}
return V_19 ;
}
static int F_90 ( struct V_14 * V_2 , int V_210 , int V_197 ,
char V_186 * V_211 , unsigned int V_212 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_181 ;
int V_19 ;
if ( V_210 != V_213 )
return - V_106 ;
if ( V_212 < sizeof( int ) )
return - V_106 ;
if ( F_82 ( V_181 , ( int V_186 * ) V_211 ) )
return - V_185 ;
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
goto V_150;
V_19 = F_86 ( V_3 , V_41 , V_197 , V_181 ) ;
F_3 ( V_29 -> V_47 ) ;
} else
V_19 = F_87 ( V_3 , V_4 , V_197 , V_181 ) ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_197 , int * V_181 )
{
int V_19 = 0 ;
switch ( V_197 ) {
case V_198 :
* V_181 = V_41 -> V_122 ;
F_20 ( V_41 , V_143 , L_20 ,
V_41 -> V_34 , V_41 -> V_122 ) ;
break;
default:
V_19 = - V_199 ;
break;
}
return V_19 ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_197 , int * V_181 )
{
int V_19 = 0 ;
switch ( V_197 ) {
case V_200 :
* V_181 = V_4 -> V_201 ;
F_20 ( V_4 , V_143 ,
L_21 , V_4 -> V_34 , * V_181 ) ;
break;
case V_202 :
* V_181 = V_4 -> V_203 ;
F_20 ( V_4 , V_143 ,
L_22 , V_4 -> V_34 , * V_181 ) ;
break;
case V_206 :
* V_181 = V_4 -> V_207 ;
F_20 ( V_4 , V_143 ,
L_23 , V_4 -> V_34 , * V_181 ) ;
break;
case V_198 :
* V_181 = V_4 -> V_122 ;
F_20 ( V_4 , V_143 , L_24 ,
V_4 -> V_34 , * V_181 ) ;
break;
case V_208 :
* V_181 = ( int ) F_93 ( V_4 -> V_209 ) ;
F_20 ( V_4 , V_143 ,
L_25 , V_4 -> V_34 , * V_181 ) ;
break;
default:
V_19 = - V_199 ;
}
return V_19 ;
}
static int F_94 ( struct V_14 * V_2 , int V_210 , int V_197 ,
char V_186 * V_211 , int V_186 * V_212 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
int V_181 , V_17 ;
int V_19 ;
struct V_28 * V_29 ;
if ( V_210 != V_213 )
return - V_106 ;
if ( F_82 ( V_17 , V_212 ) )
return - V_185 ;
V_17 = F_95 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_106 ;
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
goto V_150;
V_19 = F_91 ( V_3 , V_41 , V_197 , & V_181 ) ;
F_3 ( V_29 -> V_47 ) ;
if ( V_19 )
goto V_150;
} else {
V_19 = F_92 ( V_3 , V_4 , V_197 , & V_181 ) ;
if ( V_19 )
goto V_150;
}
V_19 = - V_185 ;
if ( F_81 ( V_17 , V_212 ) )
goto V_150;
if ( F_80 ( ( void V_186 * ) V_211 , & V_181 , V_17 ) )
goto V_150;
V_19 = 0 ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_96 ( struct V_71 * V_71 , struct V_214 * V_215 )
{
for (; ; ) {
V_215 -> V_41 = F_97 ( V_71 , V_215 -> V_216 ) ;
V_215 -> V_216 ++ ;
if ( V_215 -> V_41 == NULL )
break;
if ( V_215 -> V_41 -> V_151 < 3 )
break;
}
}
static void F_98 ( struct V_71 * V_71 , struct V_214 * V_215 )
{
V_215 -> V_4 = F_99 ( V_215 -> V_41 , V_215 -> V_217 , true ) ;
V_215 -> V_217 ++ ;
if ( V_215 -> V_4 == NULL ) {
V_215 -> V_217 = 0 ;
F_96 ( V_71 , V_215 ) ;
}
}
static void * F_100 ( struct V_87 * V_38 , T_3 * V_218 )
{
struct V_214 * V_215 = V_219 ;
T_3 V_220 = * V_218 ;
struct V_71 * V_71 ;
if ( ! V_220 )
goto V_6;
F_4 ( V_38 -> V_59 == NULL ) ;
V_215 = V_38 -> V_59 ;
V_71 = F_101 ( V_38 ) ;
if ( V_215 -> V_41 == NULL )
F_96 ( V_71 , V_215 ) ;
else
F_98 ( V_71 , V_215 ) ;
if ( ( V_215 -> V_41 == NULL ) && ( V_215 -> V_4 == NULL ) )
V_215 = NULL ;
V_6:
return V_215 ;
}
static void * F_102 ( struct V_87 * V_38 , void * V_221 , T_3 * V_220 )
{
( * V_220 ) ++ ;
return NULL ;
}
static void F_103 ( struct V_87 * V_222 , void * V_221 )
{
}
static void F_104 ( struct V_87 * V_38 , void * V_221 )
{
struct V_40 * V_41 = V_221 ;
F_57 ( V_38 , L_26 ,
V_41 -> V_34 ,
( V_41 == V_41 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_105 ( & V_41 -> V_223 ) - 1 ) ;
F_57 ( V_38 , L_27 ,
V_41 -> V_122 ,
F_77 ( & V_41 -> V_36 . V_171 ) ,
F_77 ( & V_41 -> V_36 . V_172 ) ,
F_77 ( & V_41 -> V_36 . V_173 ) ,
F_77 ( & V_41 -> V_36 . V_174 ) ,
F_77 ( & V_41 -> V_36 . V_175 ) ,
F_77 ( & V_41 -> V_36 . V_37 ) ) ;
}
static void F_106 ( struct V_87 * V_38 , void * V_221 )
{
struct V_1 * V_4 = V_221 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_31 * V_32 = F_16 ( V_29 -> V_2 ) ;
T_2 V_224 = 0 ;
T_4 V_225 = 0 ;
if ( V_41 -> V_2 ) {
struct V_147 * V_148 = F_75 ( V_41 -> V_2 ) ;
V_224 = F_107 ( V_148 -> V_226 ) ;
V_225 = F_108 ( V_148 -> V_227 ) ;
}
F_57 ( V_38 , L_28
L_29 ,
V_4 -> V_34 , V_224 , V_225 ,
V_41 -> V_98 ,
V_4 -> V_100 ,
V_41 -> V_99 ,
V_4 -> V_101 ,
V_29 -> V_2 -> V_21 ,
( V_4 == V_29 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_57 ( V_38 , L_30 ,
V_4 -> V_126 , V_4 -> V_128 ,
V_4 -> V_201 ? 'R' : '-' ,
V_4 -> V_203 ? 'S' : '-' ,
V_4 -> V_207 ? L_31 : L_32 ,
V_4 -> V_122 ,
F_93 ( V_4 -> V_209 ) ) ;
F_57 ( V_38 , L_33 ,
V_4 -> V_228 , V_4 -> V_229 ,
F_77 ( & V_4 -> V_36 . V_171 ) ,
F_77 ( & V_4 -> V_36 . V_172 ) ,
F_77 ( & V_4 -> V_36 . V_173 ) ,
F_77 ( & V_4 -> V_36 . V_174 ) ,
F_77 ( & V_4 -> V_36 . V_175 ) ,
F_77 ( & V_4 -> V_36 . V_37 ) ) ;
if ( V_32 )
F_57 ( V_38 , L_4 , F_58 ( & V_32 -> V_35 ) ) ;
}
static int F_109 ( struct V_87 * V_38 , void * V_221 )
{
struct V_214 * V_215 = V_221 ;
if ( V_221 == V_219 ) {
F_110 ( V_38 , L_34 V_230 L_35 ) ;
F_110 ( V_38 , L_36 ) ;
F_110 ( V_38 , L_37 ) ;
F_110 ( V_38 , L_38
L_39 ) ;
F_110 ( V_38 , L_40 ) ;
F_110 ( V_38 , L_41 ) ;
goto V_6;
}
if ( ! V_215 -> V_4 ) {
F_104 ( V_38 , V_215 -> V_41 ) ;
} else {
F_106 ( V_38 , V_215 -> V_4 ) ;
if ( V_215 -> V_4 -> V_137 )
V_215 -> V_4 -> V_137 ( V_215 -> V_4 ) ;
F_43 ( V_215 -> V_4 ) ;
}
V_6:
return 0 ;
}
static int F_111 ( struct V_231 * V_231 , struct V_232 * V_232 )
{
return F_112 ( V_231 , V_232 , & V_233 ,
sizeof( struct V_214 ) ) ;
}
static T_5 int F_113 ( struct V_71 * V_71 )
{
struct V_234 * V_235 ;
int V_19 = 0 ;
V_235 = F_114 ( L_42 , V_236 , V_71 -> V_237 ,
& V_238 ) ;
if ( ! V_235 ) {
V_19 = - V_52 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_6 void F_115 ( struct V_71 * V_71 )
{
F_116 ( L_42 , V_71 -> V_237 ) ;
}
static int T_7 F_117 ( void )
{
int V_19 ;
V_19 = F_118 ( & V_239 ) ;
if ( V_19 )
goto V_6;
V_19 = F_119 ( & V_74 , 0 ) ;
if ( V_19 )
goto V_240;
V_19 = F_120 ( V_81 , & V_241 ) ;
if ( V_19 )
goto V_242;
#ifdef F_121
V_19 = F_122 ( V_243 , & V_244 ) ;
if ( V_19 )
goto V_245;
#endif
F_123 ( L_43 , V_230 ) ;
V_6:
return V_19 ;
#ifdef F_121
V_245:
F_124 ( V_81 ) ;
#endif
V_242:
F_125 ( & V_74 ) ;
V_240:
F_126 ( & V_239 ) ;
goto V_6;
}
static void T_8 F_127 ( void )
{
#ifdef F_121
F_128 ( V_243 ) ;
#endif
F_124 ( V_81 ) ;
F_125 ( & V_74 ) ;
F_126 ( & V_239 ) ;
}
