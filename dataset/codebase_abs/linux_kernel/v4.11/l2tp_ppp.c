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
int V_103 = 2 ;
int V_104 ;
F_45 ( V_3 ) ;
error = - V_105 ;
if ( V_93 -> V_106 != V_81 )
goto V_23;
error = - V_107 ;
if ( V_3 -> V_21 & V_45 )
goto V_23;
error = - V_108 ;
if ( V_3 -> V_5 )
goto V_23;
V_99 = 0 ;
if ( V_91 == sizeof( struct V_92 ) ) {
V_104 = V_93 -> V_109 . V_104 ;
V_98 = V_93 -> V_109 . V_110 ;
V_99 = V_93 -> V_109 . V_111 ;
V_100 = V_93 -> V_109 . V_112 ;
V_101 = V_93 -> V_109 . V_113 ;
} else if ( V_91 == sizeof( struct V_114 ) ) {
struct V_114 * V_115 =
(struct V_114 * ) V_93 ;
V_103 = 3 ;
V_104 = V_115 -> V_109 . V_104 ;
V_98 = V_115 -> V_109 . V_110 ;
V_99 = V_115 -> V_109 . V_111 ;
V_100 = V_115 -> V_109 . V_112 ;
V_101 = V_115 -> V_109 . V_113 ;
} else if ( V_91 == sizeof( struct V_116 ) ) {
struct V_116 * V_117 =
(struct V_116 * ) V_93 ;
V_104 = V_117 -> V_109 . V_104 ;
V_98 = V_117 -> V_109 . V_110 ;
V_99 = V_117 -> V_109 . V_111 ;
V_100 = V_117 -> V_109 . V_112 ;
V_101 = V_117 -> V_109 . V_113 ;
} else if ( V_91 == sizeof( struct V_118 ) ) {
struct V_118 * V_117 =
(struct V_118 * ) V_93 ;
V_103 = 3 ;
V_104 = V_117 -> V_109 . V_104 ;
V_98 = V_117 -> V_109 . V_110 ;
V_99 = V_117 -> V_109 . V_111 ;
V_100 = V_117 -> V_109 . V_112 ;
V_101 = V_117 -> V_109 . V_113 ;
} else {
error = - V_105 ;
goto V_23;
}
error = - V_105 ;
if ( V_98 == 0 )
goto V_23;
V_41 = F_60 ( F_61 ( V_3 ) , V_98 ) ;
if ( ( V_100 == 0 ) && ( V_101 == 0 ) ) {
if ( V_41 == NULL ) {
struct V_119 V_120 = {
. V_49 = V_50 ,
. V_121 = 0 ,
} ;
error = F_62 ( F_61 ( V_3 ) , V_104 , V_103 , V_98 , V_99 , & V_120 , & V_41 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_122 ;
if ( V_41 == NULL )
goto V_23;
if ( V_41 -> V_2 == NULL )
goto V_23;
}
if ( V_41 -> V_123 == NULL )
V_41 -> V_123 = F_5 ;
if ( V_41 -> V_99 == 0 )
V_41 -> V_99 = V_99 ;
V_4 = F_63 ( F_61 ( V_3 ) , V_41 , V_100 , false ) ;
if ( V_4 ) {
V_102 = true ;
V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 ) {
error = - V_124 ;
goto V_23;
}
if ( V_29 -> V_47 != V_41 -> V_2 ) {
error = - V_124 ;
goto V_23;
}
} else {
V_97 . V_125 = 1500 - V_126 ;
V_97 . V_127 = V_97 . V_125 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , & V_97 ) ;
if ( F_65 ( V_4 ) ) {
error = F_66 ( V_4 ) ;
goto V_23;
}
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_128 = V_129 -> V_130 ;
V_29 -> V_2 = V_3 ;
V_29 -> V_47 = V_41 -> V_2 ;
V_4 -> V_131 = F_13 ;
V_4 -> V_132 = F_38 ;
#if F_67 ( V_133 )
V_4 -> V_134 = F_56 ;
#endif
V_4 -> V_135 = F_21 ;
V_4 -> V_136 = F_22 ;
V_95 = F_68 ( V_41 -> V_2 ) ;
if ( V_95 != NULL ) {
T_2 V_137 = F_69 ( V_95 ) ;
if ( V_137 != 0 )
V_4 -> V_125 = V_4 -> V_127 = V_137 -
V_126 ;
F_70 ( V_95 ) ;
}
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
error = 0 ;
goto V_138;
}
V_32 -> V_35 . V_139 = V_140 ;
V_32 -> V_35 . V_59 = V_3 ;
V_32 -> V_35 . V_77 = & V_141 ;
V_32 -> V_35 . V_125 = V_4 -> V_125 ;
error = F_71 ( F_61 ( V_3 ) , & V_32 -> V_35 ) ;
if ( error )
goto V_23;
V_138:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_45 ;
F_20 ( V_4 , V_142 , L_5 ,
V_4 -> V_34 ) ;
V_23:
if ( V_102 )
F_43 ( V_4 ) ;
F_50 ( V_3 ) ;
return error ;
}
static int F_72 ( struct V_71 * V_71 , T_2 V_98 , T_2 V_100 , T_2 V_101 , struct V_96 * V_97 )
{
int error ;
struct V_40 * V_41 ;
struct V_1 * V_4 ;
struct V_28 * V_29 ;
V_41 = F_60 ( V_71 , V_98 ) ;
error = - V_122 ;
if ( V_41 == NULL )
goto V_6;
if ( V_41 -> V_2 == NULL )
goto V_6;
if ( V_97 -> V_125 == 0 )
V_97 -> V_125 = 1500 - V_126 ;
if ( V_97 -> V_127 == 0 )
V_97 -> V_127 = V_97 -> V_125 ;
V_4 = F_64 ( sizeof( struct V_28 ) ,
V_41 , V_100 ,
V_101 , V_97 ) ;
if ( F_65 ( V_4 ) ) {
error = F_66 ( V_4 ) ;
goto V_6;
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_47 = V_41 -> V_2 ;
F_20 ( V_4 , V_142 , L_5 ,
V_4 -> V_34 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_73 ( struct V_14 * V_2 , struct V_89 * V_143 ,
int * V_144 , int V_145 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_146 * V_147 ;
struct V_28 * V_148 ;
error = - V_43 ;
if ( V_3 == NULL )
goto V_23;
if ( ! ( V_3 -> V_21 & V_45 ) )
goto V_23;
error = - V_46 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_148 = F_14 ( V_4 ) ;
V_41 = F_25 ( V_148 -> V_47 ) ;
if ( V_41 == NULL )
goto V_149;
V_147 = F_74 ( V_41 -> V_2 ) ;
if ( ( V_41 -> V_150 == 2 ) && ( V_41 -> V_2 -> V_82 == V_151 ) ) {
struct V_92 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_106 = V_81 ;
V_93 . V_109 . V_104 = V_41 -> V_104 ;
V_93 . V_109 . V_130 = V_148 -> V_128 ;
V_93 . V_109 . V_110 = V_41 -> V_98 ;
V_93 . V_109 . V_111 = V_41 -> V_99 ;
V_93 . V_109 . V_112 = V_4 -> V_100 ;
V_93 . V_109 . V_113 = V_4 -> V_101 ;
V_93 . V_109 . V_154 . V_155 = V_151 ;
V_93 . V_109 . V_154 . V_156 = V_147 -> V_157 ;
V_93 . V_109 . V_154 . V_158 . V_159 = V_147 -> V_160 ;
memcpy ( V_143 , & V_93 , V_17 ) ;
#if F_67 ( V_161 )
} else if ( ( V_41 -> V_150 == 2 ) &&
( V_41 -> V_2 -> V_82 == V_162 ) ) {
struct V_116 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_106 = V_81 ;
V_93 . V_109 . V_104 = V_41 -> V_104 ;
V_93 . V_109 . V_130 = V_148 -> V_128 ;
V_93 . V_109 . V_110 = V_41 -> V_98 ;
V_93 . V_109 . V_111 = V_41 -> V_99 ;
V_93 . V_109 . V_112 = V_4 -> V_100 ;
V_93 . V_109 . V_113 = V_4 -> V_101 ;
V_93 . V_109 . V_154 . V_163 = V_162 ;
V_93 . V_109 . V_154 . V_164 = V_147 -> V_157 ;
memcpy ( & V_93 . V_109 . V_154 . V_165 , & V_41 -> V_2 -> V_166 ,
sizeof( V_41 -> V_2 -> V_166 ) ) ;
memcpy ( V_143 , & V_93 , V_17 ) ;
} else if ( ( V_41 -> V_150 == 3 ) &&
( V_41 -> V_2 -> V_82 == V_162 ) ) {
struct V_118 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_106 = V_81 ;
V_93 . V_109 . V_104 = V_41 -> V_104 ;
V_93 . V_109 . V_130 = V_148 -> V_128 ;
V_93 . V_109 . V_110 = V_41 -> V_98 ;
V_93 . V_109 . V_111 = V_41 -> V_99 ;
V_93 . V_109 . V_112 = V_4 -> V_100 ;
V_93 . V_109 . V_113 = V_4 -> V_101 ;
V_93 . V_109 . V_154 . V_163 = V_162 ;
V_93 . V_109 . V_154 . V_164 = V_147 -> V_157 ;
memcpy ( & V_93 . V_109 . V_154 . V_165 , & V_41 -> V_2 -> V_166 ,
sizeof( V_41 -> V_2 -> V_166 ) ) ;
memcpy ( V_143 , & V_93 , V_17 ) ;
#endif
} else if ( V_41 -> V_150 == 3 ) {
struct V_114 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_106 = V_81 ;
V_93 . V_109 . V_104 = V_41 -> V_104 ;
V_93 . V_109 . V_130 = V_148 -> V_128 ;
V_93 . V_109 . V_110 = V_41 -> V_98 ;
V_93 . V_109 . V_111 = V_41 -> V_99 ;
V_93 . V_109 . V_112 = V_4 -> V_100 ;
V_93 . V_109 . V_113 = V_4 -> V_101 ;
V_93 . V_109 . V_154 . V_155 = V_151 ;
V_93 . V_109 . V_154 . V_156 = V_147 -> V_157 ;
V_93 . V_109 . V_154 . V_158 . V_159 = V_147 -> V_160 ;
memcpy ( V_143 , & V_93 , V_17 ) ;
}
* V_144 = V_17 ;
error = 0 ;
F_3 ( V_148 -> V_47 ) ;
V_149:
F_3 ( V_3 ) ;
V_23:
return error ;
}
static void F_75 ( struct V_167 * V_168 ,
struct V_169 * V_36 )
{
V_168 -> V_170 = F_76 ( & V_36 -> V_170 ) ;
V_168 -> V_171 = F_76 ( & V_36 -> V_171 ) ;
V_168 -> V_172 = F_76 ( & V_36 -> V_172 ) ;
V_168 -> V_173 = F_76 ( & V_36 -> V_173 ) ;
V_168 -> V_174 = F_76 ( & V_36 -> V_174 ) ;
V_168 -> V_175 = F_76 ( & V_36 -> V_175 ) ;
V_168 -> V_176 = F_76 ( & V_36 -> V_176 ) ;
V_168 -> V_37 = F_76 ( & V_36 -> V_37 ) ;
}
static int F_77 ( struct V_1 * V_4 ,
unsigned int V_177 , unsigned long V_88 )
{
struct V_178 V_179 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_180 = ( int ) V_88 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_167 V_36 ;
F_15 ( V_4 , V_142 ,
L_6 ,
V_4 -> V_34 , V_177 , V_88 ) ;
V_3 = V_29 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_177 ) {
case V_181 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_183 ;
if ( F_78 ( & V_179 , ( void V_184 * ) V_88 , sizeof( struct V_178 ) ) )
break;
V_179 . V_185 = V_4 -> V_125 ;
if ( F_79 ( ( void V_184 * ) V_88 , & V_179 , sizeof( struct V_178 ) ) )
break;
F_20 ( V_4 , V_142 , L_7 ,
V_4 -> V_34 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_186 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_183 ;
if ( F_78 ( & V_179 , ( void V_184 * ) V_88 , sizeof( struct V_178 ) ) )
break;
V_4 -> V_125 = V_179 . V_185 ;
F_20 ( V_4 , V_142 , L_8 ,
V_4 -> V_34 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_187 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_183 ;
if ( F_80 ( V_4 -> V_127 , ( int V_184 * ) V_88 ) )
break;
F_20 ( V_4 , V_142 , L_9 ,
V_4 -> V_34 , V_4 -> V_127 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
V_19 = - V_183 ;
if ( F_81 ( V_180 , ( int V_184 * ) V_88 ) )
break;
V_4 -> V_127 = V_180 ;
F_20 ( V_4 , V_142 , L_10 ,
V_4 -> V_34 , V_4 -> V_127 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_183 ;
if ( F_80 ( V_29 -> V_18 , ( int V_184 * ) V_88 ) )
break;
F_20 ( V_4 , V_142 , L_11 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_183 ;
if ( F_81 ( V_180 , ( int V_184 * ) V_88 ) )
break;
V_29 -> V_18 = V_180 ;
F_20 ( V_4 , V_142 , L_12 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_191 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_98 = V_41 -> V_98 ;
V_36 . V_100 = V_4 -> V_100 ;
F_75 ( & V_36 , & V_4 -> V_36 ) ;
if ( F_79 ( ( void V_184 * ) V_88 , & V_36 ,
sizeof( V_36 ) ) )
break;
F_20 ( V_4 , V_142 , L_13 ,
V_4 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_192 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_82 ( struct V_40 * V_41 ,
unsigned int V_177 , unsigned long V_88 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_167 V_36 ;
F_15 ( V_41 , V_142 ,
L_14 ,
V_41 -> V_34 , V_177 , V_88 ) ;
V_3 = V_41 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_177 ) {
case V_191 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_45 ) )
break;
if ( F_78 ( & V_36 , ( void V_184 * ) V_88 ,
sizeof( V_36 ) ) ) {
V_19 = - V_183 ;
break;
}
if ( V_36 . V_100 != 0 ) {
struct V_1 * V_4 =
F_63 ( F_61 ( V_3 ) , V_41 ,
V_36 . V_100 , true ) ;
if ( V_4 ) {
V_19 = F_77 ( V_4 , V_177 ,
V_88 ) ;
if ( V_4 -> V_136 )
V_4 -> V_136 ( V_4 ) ;
F_43 ( V_4 ) ;
} else {
V_19 = - V_193 ;
}
break;
}
#ifdef F_83
V_36 . V_194 = ( V_3 -> V_195 [ 0 ] || V_3 -> V_195 [ 1 ] ) ? 1 : 0 ;
#endif
F_75 ( & V_36 , & V_41 -> V_36 ) ;
if ( F_79 ( ( void V_184 * ) V_88 , & V_36 , sizeof( V_36 ) ) ) {
V_19 = - V_183 ;
break;
}
F_20 ( V_41 , V_142 , L_13 ,
V_41 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_192 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_84 ( struct V_14 * V_2 , unsigned int V_177 ,
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
goto V_149;
V_19 = F_82 ( V_41 , V_177 , V_88 ) ;
F_3 ( V_29 -> V_47 ) ;
goto V_149;
}
V_19 = F_77 ( V_4 , V_177 , V_88 ) ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_196 , int V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_197 :
V_41 -> V_121 = V_180 ;
F_20 ( V_41 , V_142 , L_15 ,
V_41 -> V_34 , V_41 -> V_121 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_196 , int V_180 )
{
int V_19 = 0 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
switch ( V_196 ) {
case V_199 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_200 = ! ! V_180 ;
F_20 ( V_4 , V_142 ,
L_16 ,
V_4 -> V_34 , V_4 -> V_200 ) ;
break;
case V_201 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_202 = ! ! V_180 ;
{
struct V_2 * V_203 = V_29 -> V_2 ;
struct V_31 * V_32 = F_16 ( V_203 ) ;
V_32 -> V_35 . V_139 = V_180 ? V_204 :
V_140 ;
}
F_87 ( V_4 , V_4 -> V_41 -> V_150 ) ;
F_20 ( V_4 , V_142 ,
L_17 ,
V_4 -> V_34 , V_4 -> V_202 ) ;
break;
case V_205 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_206 = ! ! V_180 ;
F_20 ( V_4 , V_142 ,
L_18 ,
V_4 -> V_34 , V_4 -> V_206 ) ;
break;
case V_197 :
V_4 -> V_121 = V_180 ;
F_20 ( V_4 , V_142 , L_15 ,
V_4 -> V_34 , V_4 -> V_121 ) ;
break;
case V_207 :
V_4 -> V_208 = F_88 ( V_180 ) ;
F_20 ( V_4 , V_142 ,
L_19 ,
V_4 -> V_34 , V_4 -> V_208 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_89 ( struct V_14 * V_2 , int V_209 , int V_196 ,
char V_184 * V_210 , unsigned int V_211 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
int V_180 ;
int V_19 ;
if ( V_209 != V_212 )
return - V_105 ;
if ( V_211 < sizeof( int ) )
return - V_105 ;
if ( F_81 ( V_180 , ( int V_184 * ) V_210 ) )
return - V_183 ;
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
goto V_149;
V_19 = F_85 ( V_3 , V_41 , V_196 , V_180 ) ;
F_3 ( V_29 -> V_47 ) ;
} else
V_19 = F_86 ( V_3 , V_4 , V_196 , V_180 ) ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
int V_196 , int * V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_197 :
* V_180 = V_41 -> V_121 ;
F_20 ( V_41 , V_142 , L_20 ,
V_41 -> V_34 , V_41 -> V_121 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_196 , int * V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_199 :
* V_180 = V_4 -> V_200 ;
F_20 ( V_4 , V_142 ,
L_21 , V_4 -> V_34 , * V_180 ) ;
break;
case V_201 :
* V_180 = V_4 -> V_202 ;
F_20 ( V_4 , V_142 ,
L_22 , V_4 -> V_34 , * V_180 ) ;
break;
case V_205 :
* V_180 = V_4 -> V_206 ;
F_20 ( V_4 , V_142 ,
L_23 , V_4 -> V_34 , * V_180 ) ;
break;
case V_197 :
* V_180 = V_4 -> V_121 ;
F_20 ( V_4 , V_142 , L_24 ,
V_4 -> V_34 , * V_180 ) ;
break;
case V_207 :
* V_180 = ( int ) F_92 ( V_4 -> V_208 ) ;
F_20 ( V_4 , V_142 ,
L_25 , V_4 -> V_34 , * V_180 ) ;
break;
default:
V_19 = - V_198 ;
}
return V_19 ;
}
static int F_93 ( struct V_14 * V_2 , int V_209 , int V_196 ,
char V_184 * V_210 , int V_184 * V_211 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_40 * V_41 ;
int V_180 , V_17 ;
int V_19 ;
struct V_28 * V_29 ;
if ( V_209 != V_212 )
return - V_105 ;
if ( F_81 ( V_17 , V_211 ) )
return - V_183 ;
V_17 = F_94 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_105 ;
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
goto V_149;
V_19 = F_90 ( V_3 , V_41 , V_196 , & V_180 ) ;
F_3 ( V_29 -> V_47 ) ;
if ( V_19 )
goto V_149;
} else {
V_19 = F_91 ( V_3 , V_4 , V_196 , & V_180 ) ;
if ( V_19 )
goto V_149;
}
V_19 = - V_183 ;
if ( F_80 ( V_17 , V_211 ) )
goto V_149;
if ( F_79 ( ( void V_184 * ) V_210 , & V_180 , V_17 ) )
goto V_149;
V_19 = 0 ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_95 ( struct V_71 * V_71 , struct V_213 * V_214 )
{
for (; ; ) {
V_214 -> V_41 = F_96 ( V_71 , V_214 -> V_215 ) ;
V_214 -> V_215 ++ ;
if ( V_214 -> V_41 == NULL )
break;
if ( V_214 -> V_41 -> V_150 < 3 )
break;
}
}
static void F_97 ( struct V_71 * V_71 , struct V_213 * V_214 )
{
V_214 -> V_4 = F_98 ( V_214 -> V_41 , V_214 -> V_216 , true ) ;
V_214 -> V_216 ++ ;
if ( V_214 -> V_4 == NULL ) {
V_214 -> V_216 = 0 ;
F_95 ( V_71 , V_214 ) ;
}
}
static void * F_99 ( struct V_87 * V_38 , T_3 * V_217 )
{
struct V_213 * V_214 = V_218 ;
T_3 V_219 = * V_217 ;
struct V_71 * V_71 ;
if ( ! V_219 )
goto V_6;
F_4 ( V_38 -> V_59 == NULL ) ;
V_214 = V_38 -> V_59 ;
V_71 = F_100 ( V_38 ) ;
if ( V_214 -> V_41 == NULL )
F_95 ( V_71 , V_214 ) ;
else
F_97 ( V_71 , V_214 ) ;
if ( ( V_214 -> V_41 == NULL ) && ( V_214 -> V_4 == NULL ) )
V_214 = NULL ;
V_6:
return V_214 ;
}
static void * F_101 ( struct V_87 * V_38 , void * V_220 , T_3 * V_219 )
{
( * V_219 ) ++ ;
return NULL ;
}
static void F_102 ( struct V_87 * V_221 , void * V_220 )
{
}
static void F_103 ( struct V_87 * V_38 , void * V_220 )
{
struct V_40 * V_41 = V_220 ;
F_57 ( V_38 , L_26 ,
V_41 -> V_34 ,
( V_41 == V_41 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_104 ( & V_41 -> V_222 ) - 1 ) ;
F_57 ( V_38 , L_27 ,
V_41 -> V_121 ,
F_76 ( & V_41 -> V_36 . V_170 ) ,
F_76 ( & V_41 -> V_36 . V_171 ) ,
F_76 ( & V_41 -> V_36 . V_172 ) ,
F_76 ( & V_41 -> V_36 . V_173 ) ,
F_76 ( & V_41 -> V_36 . V_174 ) ,
F_76 ( & V_41 -> V_36 . V_37 ) ) ;
}
static void F_105 ( struct V_87 * V_38 , void * V_220 )
{
struct V_1 * V_4 = V_220 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_31 * V_32 = F_16 ( V_29 -> V_2 ) ;
T_2 V_223 = 0 ;
T_4 V_224 = 0 ;
if ( V_41 -> V_2 ) {
struct V_146 * V_147 = F_74 ( V_41 -> V_2 ) ;
V_223 = F_106 ( V_147 -> V_225 ) ;
V_224 = F_107 ( V_147 -> V_226 ) ;
}
F_57 ( V_38 , L_28
L_29 ,
V_4 -> V_34 , V_223 , V_224 ,
V_41 -> V_98 ,
V_4 -> V_100 ,
V_41 -> V_99 ,
V_4 -> V_101 ,
V_29 -> V_2 -> V_21 ,
( V_4 == V_29 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_57 ( V_38 , L_30 ,
V_4 -> V_125 , V_4 -> V_127 ,
V_4 -> V_200 ? 'R' : '-' ,
V_4 -> V_202 ? 'S' : '-' ,
V_4 -> V_206 ? L_31 : L_32 ,
V_4 -> V_121 ,
F_92 ( V_4 -> V_208 ) ) ;
F_57 ( V_38 , L_33 ,
V_4 -> V_227 , V_4 -> V_228 ,
F_76 ( & V_4 -> V_36 . V_170 ) ,
F_76 ( & V_4 -> V_36 . V_171 ) ,
F_76 ( & V_4 -> V_36 . V_172 ) ,
F_76 ( & V_4 -> V_36 . V_173 ) ,
F_76 ( & V_4 -> V_36 . V_174 ) ,
F_76 ( & V_4 -> V_36 . V_37 ) ) ;
if ( V_32 )
F_57 ( V_38 , L_4 , F_58 ( & V_32 -> V_35 ) ) ;
}
static int F_108 ( struct V_87 * V_38 , void * V_220 )
{
struct V_213 * V_214 = V_220 ;
if ( V_220 == V_218 ) {
F_109 ( V_38 , L_34 V_229 L_35 ) ;
F_109 ( V_38 , L_36 ) ;
F_109 ( V_38 , L_37 ) ;
F_109 ( V_38 , L_38
L_39 ) ;
F_109 ( V_38 , L_40 ) ;
F_109 ( V_38 , L_41 ) ;
goto V_6;
}
if ( ! V_214 -> V_4 ) {
F_103 ( V_38 , V_214 -> V_41 ) ;
} else {
F_105 ( V_38 , V_214 -> V_4 ) ;
if ( V_214 -> V_4 -> V_136 )
V_214 -> V_4 -> V_136 ( V_214 -> V_4 ) ;
F_43 ( V_214 -> V_4 ) ;
}
V_6:
return 0 ;
}
static int F_110 ( struct V_230 * V_230 , struct V_231 * V_231 )
{
return F_111 ( V_230 , V_231 , & V_232 ,
sizeof( struct V_213 ) ) ;
}
static T_5 int F_112 ( struct V_71 * V_71 )
{
struct V_233 * V_234 ;
int V_19 = 0 ;
V_234 = F_113 ( L_42 , V_235 , V_71 -> V_236 ,
& V_237 ) ;
if ( ! V_234 ) {
V_19 = - V_52 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_6 void F_114 ( struct V_71 * V_71 )
{
F_115 ( L_42 , V_71 -> V_236 ) ;
}
static int T_7 F_116 ( void )
{
int V_19 ;
V_19 = F_117 ( & V_238 ) ;
if ( V_19 )
goto V_6;
V_19 = F_118 ( & V_74 , 0 ) ;
if ( V_19 )
goto V_239;
V_19 = F_119 ( V_81 , & V_240 ) ;
if ( V_19 )
goto V_241;
#ifdef F_120
V_19 = F_121 ( V_242 , & V_243 ) ;
if ( V_19 )
goto V_244;
#endif
F_122 ( L_43 , V_229 ) ;
V_6:
return V_19 ;
#ifdef F_120
V_244:
F_123 ( V_81 ) ;
#endif
V_241:
F_124 ( & V_74 ) ;
V_239:
F_125 ( & V_238 ) ;
goto V_6;
}
static void T_8 F_126 ( void )
{
#ifdef F_120
F_127 ( V_242 ) ;
#endif
F_123 ( V_81 ) ;
F_124 ( & V_74 ) ;
F_125 ( & V_238 ) ;
}
