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
if ( ( V_10 -> V_11 [ 0 ] == 0xff ) && ( V_10 -> V_11 [ 1 ] == 0x03 ) )
F_7 ( V_10 , 2 ) ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 , struct V_14 * V_2 ,
struct V_15 * V_16 , T_1 V_17 ,
int V_18 )
{
int V_19 ;
struct V_9 * V_10 ;
struct V_2 * V_3 = V_2 -> V_3 ;
V_19 = - V_20 ;
if ( V_3 -> V_21 & V_22 )
goto V_23;
V_16 -> V_24 = 0 ;
V_19 = 0 ;
V_10 = F_9 ( V_3 , V_18 & ~ V_25 ,
V_18 & V_25 , & V_19 ) ;
if ( ! V_10 )
goto V_23;
if ( V_17 > V_10 -> V_17 )
V_17 = V_10 -> V_17 ;
else if ( V_17 < V_10 -> V_17 )
V_16 -> V_26 |= V_27 ;
V_19 = F_10 ( V_10 , 0 , V_16 -> V_28 , V_17 ) ;
if ( F_11 ( V_19 == 0 ) )
V_19 = V_17 ;
F_12 ( V_10 ) ;
V_23:
return V_19 ;
}
static void F_13 ( struct V_1 * V_4 , struct V_9 * V_10 , int V_29 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_2 * V_3 = NULL ;
V_3 = V_31 -> V_2 ;
if ( V_3 == NULL )
goto V_32;
if ( V_3 -> V_21 & V_22 ) {
struct V_33 * V_34 ;
F_15 ( V_4 , V_35 ,
L_1 ,
V_4 -> V_36 , V_29 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_34 = F_19 ( V_3 ) ;
F_20 ( & V_34 -> V_37 , V_10 ) ;
} else {
F_21 ( V_4 , V_35 , L_2 ,
V_4 -> V_36 ) ;
F_22 ( & V_4 -> V_38 . V_39 ) ;
F_12 ( V_10 ) ;
}
return;
V_32:
F_21 ( V_4 , V_35 , L_3 , V_4 -> V_36 ) ;
F_12 ( V_10 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_2 ( V_31 -> V_2 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_3 ( V_31 -> V_2 ) ;
}
static int F_25 ( struct V_12 * V_13 , struct V_14 * V_2 , struct V_15 * V_40 ,
T_1 V_41 )
{
static const unsigned char V_42 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_45 ;
error = - V_46 ;
if ( F_26 ( V_3 , V_47 ) || ! ( V_3 -> V_21 & V_48 ) )
goto error;
error = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_31 = F_14 ( V_4 ) ;
V_44 = F_27 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_51;
V_45 = ( V_44 -> V_52 == V_53 ) ? sizeof( struct V_54 ) : 0 ;
error = - V_55 ;
V_10 = F_28 ( V_3 , V_56 + sizeof( struct V_57 ) +
V_45 + V_4 -> V_58 +
sizeof( V_42 ) + V_41 ,
0 , V_59 ) ;
if ( ! V_10 )
goto V_60;
F_29 ( V_10 , V_56 ) ;
F_30 ( V_10 ) ;
F_29 ( V_10 , sizeof( struct V_57 ) ) ;
F_31 ( V_10 ) ;
F_29 ( V_10 , V_45 ) ;
V_10 -> V_11 [ 0 ] = V_42 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_42 [ 1 ] ;
F_32 ( V_10 , 2 ) ;
error = F_33 ( F_32 ( V_10 , V_41 ) , V_40 -> V_28 ,
V_41 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_60;
}
F_34 ( V_4 , V_10 , V_4 -> V_58 ) ;
F_3 ( V_31 -> V_50 ) ;
F_3 ( V_3 ) ;
return V_41 ;
V_60:
F_3 ( V_31 -> V_50 ) ;
V_51:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_35 ( struct V_61 * V_37 , struct V_9 * V_10 )
{
static const T_2 V_42 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_37 -> V_62 ;
struct V_2 * V_63 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_45 , V_64 ;
if ( F_26 ( V_3 , V_47 ) || ! ( V_3 -> V_21 & V_48 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_31 = F_14 ( V_4 ) ;
V_63 = V_31 -> V_50 ;
if ( V_63 == NULL )
goto V_65;
V_44 = F_27 ( V_63 ) ;
if ( V_44 == NULL )
goto V_65;
V_45 = ( V_44 -> V_52 == V_53 ) ? sizeof( struct V_54 ) : 0 ;
V_64 = V_56 +
sizeof( struct V_57 ) +
V_45 +
V_4 -> V_58 +
sizeof( V_42 ) ;
if ( F_36 ( V_10 , V_64 ) )
goto V_66;
F_37 ( V_10 , sizeof( V_42 ) ) ;
V_10 -> V_11 [ 0 ] = V_42 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_42 [ 1 ] ;
F_34 ( V_4 , V_10 , V_4 -> V_58 ) ;
F_3 ( V_63 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_66:
F_3 ( V_63 ) ;
V_65:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_38 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_31 -> V_2 ;
struct V_14 * V_2 = V_3 -> V_67 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_2 ) {
F_39 ( V_2 , 2 ) ;
F_40 ( V_4 ) ;
}
return;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
if ( V_4 ) {
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_42 ( V_4 ) ;
}
return;
}
static int F_43 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_49 ;
F_44 ( V_3 ) ;
if ( F_26 ( V_3 , V_47 ) != 0 )
goto error;
F_45 ( V_3 ) ;
V_3 -> V_21 = V_68 ;
F_46 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_49 ( & V_3 -> V_69 ) ;
F_49 ( & V_3 -> V_70 ) ;
F_50 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_50 ( V_3 ) ;
return error ;
}
static int F_51 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_71 ;
V_71 = F_52 ( V_3 , V_10 ) ;
if ( V_71 )
F_12 ( V_10 ) ;
return V_72 ;
}
static int F_53 ( struct V_73 * V_73 , struct V_14 * V_2 )
{
int error = - V_55 ;
struct V_2 * V_3 ;
V_3 = F_54 ( V_73 , V_74 , V_59 , & V_75 ) ;
if ( ! V_3 )
goto V_6;
F_55 ( V_2 , V_3 ) ;
V_2 -> V_76 = V_77 ;
V_2 -> V_78 = & V_79 ;
V_3 -> V_80 = F_51 ;
V_3 -> V_81 = V_82 ;
V_3 -> V_83 = V_74 ;
V_3 -> V_21 = V_84 ;
V_3 -> V_85 = V_86 ;
V_3 -> V_87 = F_41 ;
error = 0 ;
V_6:
return error ;
}
static void F_56 ( struct V_88 * V_40 , void * V_89 )
{
struct V_1 * V_4 = V_89 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 ) {
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
if ( V_34 )
F_57 ( V_40 , L_4 , F_58 ( & V_34 -> V_37 ) ) ;
}
}
static int F_59 ( struct V_14 * V_2 , struct V_90 * V_91 ,
int V_92 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_33 * V_34 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
struct V_95 * V_96 ;
struct V_97 V_98 = { 0 , } ;
int error = 0 ;
T_3 V_99 , V_100 ;
T_3 V_101 , V_102 ;
int V_103 = 2 ;
int V_104 ;
F_44 ( V_3 ) ;
error = - V_105 ;
if ( V_94 -> V_106 != V_82 )
goto V_23;
error = - V_107 ;
if ( V_3 -> V_21 & V_48 )
goto V_23;
error = - V_108 ;
if ( V_3 -> V_5 )
goto V_23;
V_100 = 0 ;
if ( V_92 == sizeof( struct V_93 ) ) {
V_104 = V_94 -> V_109 . V_104 ;
V_99 = V_94 -> V_109 . V_110 ;
V_100 = V_94 -> V_109 . V_111 ;
V_101 = V_94 -> V_109 . V_112 ;
V_102 = V_94 -> V_109 . V_113 ;
} else if ( V_92 == sizeof( struct V_114 ) ) {
struct V_114 * V_115 =
(struct V_114 * ) V_94 ;
V_103 = 3 ;
V_104 = V_115 -> V_109 . V_104 ;
V_99 = V_115 -> V_109 . V_110 ;
V_100 = V_115 -> V_109 . V_111 ;
V_101 = V_115 -> V_109 . V_112 ;
V_102 = V_115 -> V_109 . V_113 ;
} else if ( V_92 == sizeof( struct V_116 ) ) {
struct V_116 * V_117 =
(struct V_116 * ) V_94 ;
V_104 = V_117 -> V_109 . V_104 ;
V_99 = V_117 -> V_109 . V_110 ;
V_100 = V_117 -> V_109 . V_111 ;
V_101 = V_117 -> V_109 . V_112 ;
V_102 = V_117 -> V_109 . V_113 ;
} else if ( V_92 == sizeof( struct V_118 ) ) {
struct V_118 * V_117 =
(struct V_118 * ) V_94 ;
V_103 = 3 ;
V_104 = V_117 -> V_109 . V_104 ;
V_99 = V_117 -> V_109 . V_110 ;
V_100 = V_117 -> V_109 . V_111 ;
V_101 = V_117 -> V_109 . V_112 ;
V_102 = V_117 -> V_109 . V_113 ;
} else {
error = - V_105 ;
goto V_23;
}
error = - V_105 ;
if ( V_99 == 0 )
goto V_23;
V_44 = F_60 ( F_61 ( V_3 ) , V_99 ) ;
if ( ( V_101 == 0 ) && ( V_102 == 0 ) ) {
if ( V_44 == NULL ) {
struct V_119 V_120 = {
. V_52 = V_53 ,
. V_121 = 0 ,
} ;
error = F_62 ( F_61 ( V_3 ) , V_104 , V_103 , V_99 , V_100 , & V_120 , & V_44 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_122 ;
if ( V_44 == NULL )
goto V_23;
if ( V_44 -> V_2 == NULL )
goto V_23;
}
if ( V_44 -> V_123 == NULL )
V_44 -> V_123 = F_5 ;
if ( V_44 -> V_100 == 0 )
V_44 -> V_100 = V_100 ;
V_4 = F_63 ( F_61 ( V_3 ) , V_44 , V_101 ) ;
if ( V_4 == NULL ) {
V_98 . V_124 = V_98 . V_125 = 1500 - V_126 ;
V_4 = F_64 ( sizeof( struct V_30 ) ,
V_44 , V_101 ,
V_102 , & V_98 ) ;
if ( V_4 == NULL ) {
error = - V_55 ;
goto V_23;
}
} else {
V_31 = F_14 ( V_4 ) ;
error = - V_127 ;
if ( V_31 -> V_2 != NULL )
goto V_23;
if ( V_31 -> V_50 != V_44 -> V_2 )
goto V_23;
}
V_31 = F_14 ( V_4 ) ;
V_31 -> V_128 = V_129 -> V_130 ;
V_31 -> V_2 = V_3 ;
V_31 -> V_50 = V_44 -> V_2 ;
V_4 -> V_131 = F_13 ;
V_4 -> V_132 = F_38 ;
#if F_65 ( V_133 ) || F_65 ( V_134 )
V_4 -> V_135 = F_56 ;
#endif
V_4 -> V_136 = F_23 ;
V_4 -> V_137 = F_24 ;
V_96 = F_66 ( V_3 ) ;
if ( V_96 != NULL ) {
T_3 V_138 = F_67 ( F_68 ( V_3 ) ) ;
if ( V_138 != 0 )
V_4 -> V_124 = V_4 -> V_125 = V_138 -
V_126 ;
F_69 ( V_96 ) ;
}
if ( ( V_4 -> V_101 == 0 ) &&
( V_4 -> V_102 == 0 ) ) {
error = 0 ;
goto V_139;
}
V_34 -> V_37 . V_140 = V_141 ;
V_34 -> V_37 . V_62 = V_3 ;
V_34 -> V_37 . V_78 = & V_142 ;
V_34 -> V_37 . V_124 = V_4 -> V_124 ;
error = F_70 ( F_61 ( V_3 ) , & V_34 -> V_37 ) ;
if ( error )
goto V_23;
V_139:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_48 ;
F_21 ( V_4 , V_143 , L_5 ,
V_4 -> V_36 ) ;
V_23:
F_50 ( V_3 ) ;
return error ;
}
static int F_71 ( struct V_73 * V_73 , T_3 V_99 , T_3 V_101 , T_3 V_102 , struct V_97 * V_98 )
{
int error ;
struct V_43 * V_44 ;
struct V_1 * V_4 ;
struct V_30 * V_31 ;
V_44 = F_60 ( V_73 , V_99 ) ;
error = - V_122 ;
if ( V_44 == NULL )
goto V_6;
if ( V_44 -> V_2 == NULL )
goto V_6;
error = - V_127 ;
V_4 = F_63 ( V_73 , V_44 , V_101 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_98 -> V_124 == 0 )
V_98 -> V_124 = 1500 - V_126 ;
if ( V_98 -> V_125 == 0 )
V_98 -> V_125 = V_98 -> V_124 ;
error = - V_55 ;
V_4 = F_64 ( sizeof( struct V_30 ) ,
V_44 , V_101 ,
V_102 , V_98 ) ;
if ( V_4 == NULL )
goto V_6;
V_31 = F_14 ( V_4 ) ;
V_31 -> V_50 = V_44 -> V_2 ;
F_21 ( V_4 , V_143 , L_5 ,
V_4 -> V_36 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_72 ( struct V_14 * V_2 , struct V_90 * V_144 ,
int * V_145 , int V_146 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_147 * V_148 ;
struct V_30 * V_149 ;
error = - V_46 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_48 )
goto V_23;
error = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_149 = F_14 ( V_4 ) ;
V_44 = F_27 ( V_149 -> V_50 ) ;
if ( V_44 == NULL ) {
error = - V_49 ;
goto V_150;
}
V_148 = F_73 ( V_44 -> V_2 ) ;
if ( ( V_44 -> V_151 == 2 ) && ( V_44 -> V_2 -> V_83 == V_152 ) ) {
struct V_93 V_94 ;
V_17 = sizeof( V_94 ) ;
memset ( & V_94 , 0 , V_17 ) ;
V_94 . V_153 = V_154 ;
V_94 . V_106 = V_82 ;
V_94 . V_109 . V_104 = V_44 -> V_104 ;
V_94 . V_109 . V_130 = V_149 -> V_128 ;
V_94 . V_109 . V_110 = V_44 -> V_99 ;
V_94 . V_109 . V_111 = V_44 -> V_100 ;
V_94 . V_109 . V_112 = V_4 -> V_101 ;
V_94 . V_109 . V_113 = V_4 -> V_102 ;
V_94 . V_109 . V_155 . V_156 = V_152 ;
V_94 . V_109 . V_155 . V_157 = V_148 -> V_158 ;
V_94 . V_109 . V_155 . V_159 . V_160 = V_148 -> V_161 ;
memcpy ( V_144 , & V_94 , V_17 ) ;
#if F_74 ( V_162 )
} else if ( ( V_44 -> V_151 == 2 ) &&
( V_44 -> V_2 -> V_83 == V_163 ) ) {
struct V_164 * V_165 = F_75 ( V_44 -> V_2 ) ;
struct V_116 V_94 ;
V_17 = sizeof( V_94 ) ;
memset ( & V_94 , 0 , V_17 ) ;
V_94 . V_153 = V_154 ;
V_94 . V_106 = V_82 ;
V_94 . V_109 . V_104 = V_44 -> V_104 ;
V_94 . V_109 . V_130 = V_149 -> V_128 ;
V_94 . V_109 . V_110 = V_44 -> V_99 ;
V_94 . V_109 . V_111 = V_44 -> V_100 ;
V_94 . V_109 . V_112 = V_4 -> V_101 ;
V_94 . V_109 . V_113 = V_4 -> V_102 ;
V_94 . V_109 . V_155 . V_166 = V_163 ;
V_94 . V_109 . V_155 . V_167 = V_148 -> V_158 ;
memcpy ( & V_94 . V_109 . V_155 . V_168 , & V_165 -> V_169 ,
sizeof( V_165 -> V_169 ) ) ;
memcpy ( V_144 , & V_94 , V_17 ) ;
} else if ( ( V_44 -> V_151 == 3 ) &&
( V_44 -> V_2 -> V_83 == V_163 ) ) {
struct V_164 * V_165 = F_75 ( V_44 -> V_2 ) ;
struct V_118 V_94 ;
V_17 = sizeof( V_94 ) ;
memset ( & V_94 , 0 , V_17 ) ;
V_94 . V_153 = V_154 ;
V_94 . V_106 = V_82 ;
V_94 . V_109 . V_104 = V_44 -> V_104 ;
V_94 . V_109 . V_130 = V_149 -> V_128 ;
V_94 . V_109 . V_110 = V_44 -> V_99 ;
V_94 . V_109 . V_111 = V_44 -> V_100 ;
V_94 . V_109 . V_112 = V_4 -> V_101 ;
V_94 . V_109 . V_113 = V_4 -> V_102 ;
V_94 . V_109 . V_155 . V_166 = V_163 ;
V_94 . V_109 . V_155 . V_167 = V_148 -> V_158 ;
memcpy ( & V_94 . V_109 . V_155 . V_168 , & V_165 -> V_169 ,
sizeof( V_165 -> V_169 ) ) ;
memcpy ( V_144 , & V_94 , V_17 ) ;
#endif
} else if ( V_44 -> V_151 == 3 ) {
struct V_114 V_94 ;
V_17 = sizeof( V_94 ) ;
memset ( & V_94 , 0 , V_17 ) ;
V_94 . V_153 = V_154 ;
V_94 . V_106 = V_82 ;
V_94 . V_109 . V_104 = V_44 -> V_104 ;
V_94 . V_109 . V_130 = V_149 -> V_128 ;
V_94 . V_109 . V_110 = V_44 -> V_99 ;
V_94 . V_109 . V_111 = V_44 -> V_100 ;
V_94 . V_109 . V_112 = V_4 -> V_101 ;
V_94 . V_109 . V_113 = V_4 -> V_102 ;
V_94 . V_109 . V_155 . V_156 = V_152 ;
V_94 . V_109 . V_155 . V_157 = V_148 -> V_158 ;
V_94 . V_109 . V_155 . V_159 . V_160 = V_148 -> V_161 ;
memcpy ( V_144 , & V_94 , V_17 ) ;
}
* V_145 = V_17 ;
F_3 ( V_149 -> V_50 ) ;
V_150:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_76 ( struct V_170 * V_171 ,
struct V_172 * V_38 )
{
V_171 -> V_173 = F_77 ( & V_38 -> V_173 ) ;
V_171 -> V_174 = F_77 ( & V_38 -> V_174 ) ;
V_171 -> V_175 = F_77 ( & V_38 -> V_175 ) ;
V_171 -> V_176 = F_77 ( & V_38 -> V_176 ) ;
V_171 -> V_177 = F_77 ( & V_38 -> V_177 ) ;
V_171 -> V_178 = F_77 ( & V_38 -> V_178 ) ;
V_171 -> V_179 = F_77 ( & V_38 -> V_179 ) ;
V_171 -> V_39 = F_77 ( & V_38 -> V_39 ) ;
}
static int F_78 ( struct V_1 * V_4 ,
unsigned int V_180 , unsigned long V_89 )
{
struct V_181 V_182 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_183 = ( int ) V_89 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_170 V_38 ;
F_15 ( V_4 , V_143 ,
L_6 ,
V_4 -> V_36 , V_180 , V_89 ) ;
V_3 = V_31 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_180 ) {
case V_184 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_186 ;
if ( F_79 ( & V_182 , ( void V_187 * ) V_89 , sizeof( struct V_181 ) ) )
break;
V_182 . V_188 = V_4 -> V_124 ;
if ( F_80 ( ( void V_187 * ) V_89 , & V_182 , sizeof( struct V_181 ) ) )
break;
F_21 ( V_4 , V_143 , L_7 ,
V_4 -> V_36 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_186 ;
if ( F_79 ( & V_182 , ( void V_187 * ) V_89 , sizeof( struct V_181 ) ) )
break;
V_4 -> V_124 = V_182 . V_188 ;
F_21 ( V_4 , V_143 , L_8 ,
V_4 -> V_36 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_186 ;
if ( F_81 ( V_4 -> V_125 , ( int V_187 * ) V_89 ) )
break;
F_21 ( V_4 , V_143 , L_9 ,
V_4 -> V_36 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_191 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_186 ;
if ( F_82 ( V_183 , ( int V_187 * ) V_89 ) )
break;
V_4 -> V_125 = V_183 ;
F_21 ( V_4 , V_143 , L_10 ,
V_4 -> V_36 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_192 :
V_19 = - V_186 ;
if ( F_81 ( V_31 -> V_18 , ( int V_187 * ) V_89 ) )
break;
F_21 ( V_4 , V_143 , L_11 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_193 :
V_19 = - V_186 ;
if ( F_82 ( V_183 , ( int V_187 * ) V_89 ) )
break;
V_31 -> V_18 = V_183 ;
F_21 ( V_4 , V_143 , L_12 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_194 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_99 = V_44 -> V_99 ;
V_38 . V_101 = V_4 -> V_101 ;
F_76 ( & V_38 , & V_4 -> V_38 ) ;
if ( F_80 ( ( void V_187 * ) V_89 , & V_38 ,
sizeof( V_38 ) ) )
break;
F_21 ( V_4 , V_143 , L_13 ,
V_4 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_195 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_83 ( struct V_43 * V_44 ,
unsigned int V_180 , unsigned long V_89 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_170 V_38 ;
F_15 ( V_44 , V_143 ,
L_14 ,
V_44 -> V_36 , V_180 , V_89 ) ;
V_3 = V_44 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_180 ) {
case V_194 :
V_19 = - V_185 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
if ( F_79 ( & V_38 , ( void V_187 * ) V_89 ,
sizeof( V_38 ) ) ) {
V_19 = - V_186 ;
break;
}
if ( V_38 . V_101 != 0 ) {
struct V_1 * V_4 =
F_63 ( F_61 ( V_3 ) , V_44 , V_38 . V_101 ) ;
if ( V_4 != NULL )
V_19 = F_78 ( V_4 , V_180 , V_89 ) ;
else
V_19 = - V_196 ;
break;
}
#ifdef F_84
V_38 . V_197 = ( V_3 -> V_198 [ 0 ] || V_3 -> V_198 [ 1 ] ) ? 1 : 0 ;
#endif
F_76 ( & V_38 , & V_44 -> V_38 ) ;
if ( F_80 ( ( void V_187 * ) V_89 , & V_38 , sizeof( V_38 ) ) ) {
V_19 = - V_186 ;
break;
}
F_21 ( V_44 , V_143 , L_13 ,
V_44 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_195 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_85 ( struct V_14 * V_2 , unsigned int V_180 ,
unsigned long V_89 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_49 ;
if ( F_26 ( V_3 , V_47 ) != 0 )
goto V_23;
V_19 = - V_46 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_21 & ( V_48 | V_22 ) ) ) )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_101 == 0 ) &&
( V_4 -> V_102 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_27 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_150;
V_19 = F_83 ( V_44 , V_180 , V_89 ) ;
F_3 ( V_31 -> V_50 ) ;
goto V_150;
}
V_19 = F_78 ( V_4 , V_180 , V_89 ) ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_199 , int V_183 )
{
int V_19 = 0 ;
switch ( V_199 ) {
case V_200 :
V_44 -> V_121 = V_183 ;
F_21 ( V_44 , V_143 , L_15 ,
V_44 -> V_36 , V_44 -> V_121 ) ;
break;
default:
V_19 = - V_201 ;
break;
}
return V_19 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_199 , int V_183 )
{
int V_19 = 0 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
switch ( V_199 ) {
case V_202 :
if ( ( V_183 != 0 ) && ( V_183 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_203 = V_183 ? - 1 : 0 ;
F_21 ( V_4 , V_143 ,
L_16 ,
V_4 -> V_36 , V_4 -> V_203 ) ;
break;
case V_204 :
if ( ( V_183 != 0 ) && ( V_183 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_205 = V_183 ? - 1 : 0 ;
{
struct V_2 * V_206 = V_31 -> V_2 ;
struct V_33 * V_34 = F_19 ( V_206 ) ;
V_34 -> V_37 . V_140 = V_183 ? V_207 :
V_141 ;
}
F_21 ( V_4 , V_143 ,
L_17 ,
V_4 -> V_36 , V_4 -> V_205 ) ;
break;
case V_208 :
if ( ( V_183 != 0 ) && ( V_183 != 1 ) ) {
V_19 = - V_105 ;
break;
}
V_4 -> V_209 = V_183 ? - 1 : 0 ;
F_21 ( V_4 , V_143 ,
L_18 ,
V_4 -> V_36 , V_4 -> V_209 ) ;
break;
case V_200 :
V_4 -> V_121 = V_183 ;
F_21 ( V_4 , V_143 , L_15 ,
V_4 -> V_36 , V_4 -> V_121 ) ;
break;
case V_210 :
V_4 -> V_211 = F_88 ( V_183 ) ;
F_21 ( V_4 , V_143 ,
L_19 ,
V_4 -> V_36 , V_4 -> V_211 ) ;
break;
default:
V_19 = - V_201 ;
break;
}
return V_19 ;
}
static int F_89 ( struct V_14 * V_2 , int V_212 , int V_199 ,
char V_187 * V_213 , unsigned int V_214 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_183 ;
int V_19 ;
if ( V_212 != V_215 )
return V_216 . V_217 ( V_3 , V_212 , V_199 , V_213 , V_214 ) ;
if ( V_214 < sizeof( int ) )
return - V_105 ;
if ( F_82 ( V_183 , ( int V_187 * ) V_213 ) )
return - V_186 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_101 == 0 ) &&
( V_4 -> V_102 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_27 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_150;
V_19 = F_86 ( V_3 , V_44 , V_199 , V_183 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_87 ( V_3 , V_4 , V_199 , V_183 ) ;
V_19 = 0 ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_199 , int * V_183 )
{
int V_19 = 0 ;
switch ( V_199 ) {
case V_200 :
* V_183 = V_44 -> V_121 ;
F_21 ( V_44 , V_143 , L_20 ,
V_44 -> V_36 , V_44 -> V_121 ) ;
break;
default:
V_19 = - V_201 ;
break;
}
return V_19 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_199 , int * V_183 )
{
int V_19 = 0 ;
switch ( V_199 ) {
case V_202 :
* V_183 = V_4 -> V_203 ;
F_21 ( V_4 , V_143 ,
L_21 , V_4 -> V_36 , * V_183 ) ;
break;
case V_204 :
* V_183 = V_4 -> V_205 ;
F_21 ( V_4 , V_143 ,
L_22 , V_4 -> V_36 , * V_183 ) ;
break;
case V_208 :
* V_183 = V_4 -> V_209 ;
F_21 ( V_4 , V_143 ,
L_23 , V_4 -> V_36 , * V_183 ) ;
break;
case V_200 :
* V_183 = V_4 -> V_121 ;
F_21 ( V_4 , V_143 , L_24 ,
V_4 -> V_36 , * V_183 ) ;
break;
case V_210 :
* V_183 = ( int ) F_92 ( V_4 -> V_211 ) ;
F_21 ( V_4 , V_143 ,
L_25 , V_4 -> V_36 , * V_183 ) ;
break;
default:
V_19 = - V_201 ;
}
return V_19 ;
}
static int F_93 ( struct V_14 * V_2 , int V_212 , int V_199 ,
char V_187 * V_213 , int V_187 * V_214 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
int V_183 , V_17 ;
int V_19 ;
struct V_30 * V_31 ;
if ( V_212 != V_215 )
return V_216 . V_218 ( V_3 , V_212 , V_199 , V_213 , V_214 ) ;
if ( F_82 ( V_17 , V_214 ) )
return - V_186 ;
V_17 = F_94 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_105 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_101 == 0 ) &&
( V_4 -> V_102 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_27 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_150;
V_19 = F_90 ( V_3 , V_44 , V_199 , & V_183 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_91 ( V_3 , V_4 , V_199 , & V_183 ) ;
V_19 = - V_186 ;
if ( F_81 ( V_17 , V_214 ) )
goto V_150;
if ( F_80 ( ( void V_187 * ) V_213 , & V_183 , V_17 ) )
goto V_150;
V_19 = 0 ;
V_150:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_95 ( struct V_73 * V_73 , struct V_219 * V_220 )
{
for (; ; ) {
V_220 -> V_44 = F_96 ( V_73 , V_220 -> V_221 ) ;
V_220 -> V_221 ++ ;
if ( V_220 -> V_44 == NULL )
break;
if ( V_220 -> V_44 -> V_151 < 3 )
break;
}
}
static void F_97 ( struct V_73 * V_73 , struct V_219 * V_220 )
{
V_220 -> V_4 = F_98 ( V_220 -> V_44 , V_220 -> V_222 ) ;
V_220 -> V_222 ++ ;
if ( V_220 -> V_4 == NULL ) {
V_220 -> V_222 = 0 ;
F_95 ( V_73 , V_220 ) ;
}
}
static void * F_99 ( struct V_88 * V_40 , T_4 * V_223 )
{
struct V_219 * V_220 = V_224 ;
T_4 V_225 = * V_223 ;
struct V_73 * V_73 ;
if ( ! V_225 )
goto V_6;
F_4 ( V_40 -> V_62 == NULL ) ;
V_220 = V_40 -> V_62 ;
V_73 = F_100 ( V_40 ) ;
if ( V_220 -> V_44 == NULL )
F_95 ( V_73 , V_220 ) ;
else
F_97 ( V_73 , V_220 ) ;
if ( ( V_220 -> V_44 == NULL ) && ( V_220 -> V_4 == NULL ) )
V_220 = NULL ;
V_6:
return V_220 ;
}
static void * F_101 ( struct V_88 * V_40 , void * V_226 , T_4 * V_225 )
{
( * V_225 ) ++ ;
return NULL ;
}
static void F_102 ( struct V_88 * V_227 , void * V_226 )
{
}
static void F_103 ( struct V_88 * V_40 , void * V_226 )
{
struct V_43 * V_44 = V_226 ;
F_57 ( V_40 , L_26 ,
V_44 -> V_36 ,
( V_44 == V_44 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_104 ( & V_44 -> V_228 ) - 1 ) ;
F_57 ( V_40 , L_27 ,
V_44 -> V_121 ,
F_77 ( & V_44 -> V_38 . V_173 ) ,
F_77 ( & V_44 -> V_38 . V_174 ) ,
F_77 ( & V_44 -> V_38 . V_175 ) ,
F_77 ( & V_44 -> V_38 . V_176 ) ,
F_77 ( & V_44 -> V_38 . V_177 ) ,
F_77 ( & V_44 -> V_38 . V_39 ) ) ;
}
static void F_105 ( struct V_88 * V_40 , void * V_226 )
{
struct V_1 * V_4 = V_226 ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
T_3 V_229 = 0 ;
T_5 V_230 = 0 ;
if ( V_44 -> V_2 ) {
struct V_147 * V_148 = F_73 ( V_44 -> V_2 ) ;
V_229 = F_106 ( V_148 -> V_231 ) ;
V_230 = F_107 ( V_148 -> V_232 ) ;
}
F_57 ( V_40 , L_28
L_29 ,
V_4 -> V_36 , V_229 , V_230 ,
V_44 -> V_99 ,
V_4 -> V_101 ,
V_44 -> V_100 ,
V_4 -> V_102 ,
V_31 -> V_2 -> V_21 ,
( V_4 == V_31 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_57 ( V_40 , L_30 ,
V_4 -> V_124 , V_4 -> V_125 ,
V_4 -> V_203 ? 'R' : '-' ,
V_4 -> V_205 ? 'S' : '-' ,
V_4 -> V_209 ? L_31 : L_32 ,
V_4 -> V_121 ,
F_92 ( V_4 -> V_211 ) ) ;
F_57 ( V_40 , L_33 ,
V_4 -> V_233 , V_4 -> V_234 ,
F_77 ( & V_4 -> V_38 . V_173 ) ,
F_77 ( & V_4 -> V_38 . V_174 ) ,
F_77 ( & V_4 -> V_38 . V_175 ) ,
F_77 ( & V_4 -> V_38 . V_176 ) ,
F_77 ( & V_4 -> V_38 . V_177 ) ,
F_77 ( & V_4 -> V_38 . V_39 ) ) ;
if ( V_34 )
F_57 ( V_40 , L_4 , F_58 ( & V_34 -> V_37 ) ) ;
}
static int F_108 ( struct V_88 * V_40 , void * V_226 )
{
struct V_219 * V_220 = V_226 ;
if ( V_226 == V_224 ) {
F_109 ( V_40 , L_34 V_235 L_35 ) ;
F_109 ( V_40 , L_36 ) ;
F_109 ( V_40 , L_37 ) ;
F_109 ( V_40 , L_38
L_39 ) ;
F_109 ( V_40 , L_40 ) ;
F_109 ( V_40 , L_41 ) ;
goto V_6;
}
if ( V_220 -> V_4 == NULL )
F_103 ( V_40 , V_220 -> V_44 ) ;
else
F_105 ( V_40 , V_220 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_110 ( struct V_236 * V_236 , struct V_237 * V_237 )
{
return F_111 ( V_236 , V_237 , & V_238 ,
sizeof( struct V_219 ) ) ;
}
static T_6 int F_112 ( struct V_73 * V_73 )
{
struct V_239 * V_240 ;
int V_19 = 0 ;
V_240 = F_113 ( L_42 , V_241 , V_73 -> V_242 ,
& V_243 ) ;
if ( ! V_240 ) {
V_19 = - V_55 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_114 ( struct V_73 * V_73 )
{
F_115 ( L_42 , V_73 -> V_242 ) ;
}
static int T_8 F_116 ( void )
{
int V_19 ;
V_19 = F_117 ( & V_244 ) ;
if ( V_19 )
goto V_6;
V_19 = F_118 ( & V_75 , 0 ) ;
if ( V_19 )
goto V_245;
V_19 = F_119 ( V_82 , & V_246 ) ;
if ( V_19 )
goto V_247;
#ifdef F_120
V_19 = F_121 ( V_248 , & V_249 ) ;
if ( V_19 )
goto V_250;
#endif
F_122 ( L_43 , V_235 ) ;
V_6:
return V_19 ;
#ifdef F_120
V_250:
F_123 ( V_82 ) ;
#endif
V_247:
F_124 ( & V_75 ) ;
V_245:
F_125 ( & V_244 ) ;
goto V_6;
}
static void T_9 F_126 ( void )
{
#ifdef F_120
F_127 ( V_248 ) ;
#endif
F_123 ( V_82 ) ;
F_124 ( & V_75 ) ;
F_125 ( & V_244 ) ;
}
