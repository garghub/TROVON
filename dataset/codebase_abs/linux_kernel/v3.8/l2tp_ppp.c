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
V_4 -> V_38 . V_39 ++ ;
F_12 ( V_10 ) ;
}
return;
V_32:
F_21 ( V_4 , V_35 , L_3 , V_4 -> V_36 ) ;
F_12 ( V_10 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_2 ( V_31 -> V_2 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_3 ( V_31 -> V_2 ) ;
}
static int F_24 ( struct V_12 * V_13 , struct V_14 * V_2 , struct V_15 * V_40 ,
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
if ( F_25 ( V_3 , V_47 ) || ! ( V_3 -> V_21 & V_48 ) )
goto error;
error = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_31 = F_14 ( V_4 ) ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_51;
V_45 = ( V_44 -> V_52 == V_53 ) ? sizeof( struct V_54 ) : 0 ;
error = - V_55 ;
V_10 = F_27 ( V_3 , V_56 + sizeof( struct V_57 ) +
V_45 + V_4 -> V_58 +
sizeof( V_42 ) + V_41 ,
0 , V_59 ) ;
if ( ! V_10 )
goto V_60;
F_28 ( V_10 , V_56 ) ;
F_29 ( V_10 ) ;
F_28 ( V_10 , sizeof( struct V_57 ) ) ;
F_30 ( V_10 ) ;
F_28 ( V_10 , V_45 ) ;
V_10 -> V_11 [ 0 ] = V_42 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_42 [ 1 ] ;
F_31 ( V_10 , 2 ) ;
error = F_32 ( V_10 -> V_11 , V_40 -> V_28 , V_41 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_60;
}
F_31 ( V_10 , V_41 ) ;
F_33 ( V_4 , V_10 , V_4 -> V_58 ) ;
F_3 ( V_31 -> V_50 ) ;
return error ;
V_60:
F_3 ( V_31 -> V_50 ) ;
V_51:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_34 ( struct V_61 * V_37 , struct V_9 * V_10 )
{
static const T_2 V_42 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_37 -> V_62 ;
struct V_2 * V_63 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_45 , V_64 ;
if ( F_25 ( V_3 , V_47 ) || ! ( V_3 -> V_21 & V_48 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_31 = F_14 ( V_4 ) ;
V_63 = V_31 -> V_50 ;
if ( V_63 == NULL )
goto V_65;
V_44 = F_26 ( V_63 ) ;
if ( V_44 == NULL )
goto V_65;
V_45 = ( V_44 -> V_52 == V_53 ) ? sizeof( struct V_54 ) : 0 ;
V_64 = V_56 +
sizeof( struct V_57 ) +
V_45 +
V_4 -> V_58 +
sizeof( V_42 ) ;
if ( F_35 ( V_10 , V_64 ) )
goto V_66;
F_36 ( V_10 , sizeof( V_42 ) ) ;
V_10 -> V_11 [ 0 ] = V_42 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_42 [ 1 ] ;
F_33 ( V_4 , V_10 , V_4 -> V_58 ) ;
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
static void F_37 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_31 -> V_2 ;
struct V_9 * V_10 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_4 -> V_67 == 0 )
goto V_6;
if ( V_3 != NULL ) {
F_38 ( V_3 ) ;
if ( V_3 -> V_21 & ( V_48 | V_22 ) ) {
F_39 ( V_3 ) ;
V_3 -> V_21 = V_68 ;
V_3 -> V_69 ( V_3 ) ;
}
F_40 ( & V_3 -> V_70 ) ;
F_40 ( & V_3 -> V_71 ) ;
while ( ( V_10 = F_41 ( & V_4 -> V_72 ) ) ) {
F_12 ( V_10 ) ;
F_3 ( V_3 ) ;
}
F_42 ( V_3 ) ;
}
V_6:
return;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_5 != NULL ) {
V_4 = V_3 -> V_5 ;
if ( V_4 == NULL )
goto V_6;
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_44 ( V_4 ) ;
}
V_6:
return;
}
static int F_45 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_49 ;
F_38 ( V_3 ) ;
if ( F_25 ( V_3 , V_47 ) != 0 )
goto error;
F_39 ( V_3 ) ;
V_3 -> V_21 = V_68 ;
F_46 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
F_40 ( & V_3 -> V_70 ) ;
F_40 ( & V_3 -> V_71 ) ;
if ( V_4 != NULL ) {
struct V_9 * V_10 ;
while ( ( V_10 = F_41 ( & V_4 -> V_72 ) ) ) {
F_12 ( V_10 ) ;
F_3 ( V_3 ) ;
}
F_3 ( V_3 ) ;
}
F_42 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_42 ( V_3 ) ;
return error ;
}
static int F_47 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_73 ;
V_73 = F_48 ( V_3 , V_10 ) ;
if ( V_73 )
F_12 ( V_10 ) ;
return V_74 ;
}
static int F_49 ( struct V_75 * V_75 , struct V_14 * V_2 )
{
int error = - V_55 ;
struct V_2 * V_3 ;
V_3 = F_50 ( V_75 , V_76 , V_59 , & V_77 ) ;
if ( ! V_3 )
goto V_6;
F_51 ( V_2 , V_3 ) ;
V_2 -> V_78 = V_79 ;
V_2 -> V_80 = & V_81 ;
V_3 -> V_82 = F_47 ;
V_3 -> V_83 = V_84 ;
V_3 -> V_85 = V_76 ;
V_3 -> V_21 = V_86 ;
V_3 -> V_87 = V_88 ;
V_3 -> V_89 = F_43 ;
error = 0 ;
V_6:
return error ;
}
static void F_52 ( struct V_90 * V_40 , void * V_91 )
{
struct V_1 * V_4 = V_91 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 ) {
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
if ( V_34 )
F_53 ( V_40 , L_4 , F_54 ( & V_34 -> V_37 ) ) ;
}
}
static int F_55 ( struct V_14 * V_2 , struct V_92 * V_93 ,
int V_94 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_95 * V_96 = (struct V_95 * ) V_93 ;
struct V_33 * V_34 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
struct V_97 * V_98 ;
struct V_99 V_100 = { 0 , } ;
int error = 0 ;
T_3 V_101 , V_102 ;
T_3 V_67 , V_103 ;
int V_104 = 2 ;
int V_105 ;
F_38 ( V_3 ) ;
error = - V_106 ;
if ( V_96 -> V_107 != V_84 )
goto V_23;
error = - V_108 ;
if ( V_3 -> V_21 & V_48 )
goto V_23;
error = - V_109 ;
if ( V_3 -> V_5 )
goto V_23;
V_102 = 0 ;
if ( V_94 == sizeof( struct V_95 ) ) {
V_105 = V_96 -> V_110 . V_105 ;
V_101 = V_96 -> V_110 . V_111 ;
V_102 = V_96 -> V_110 . V_112 ;
V_67 = V_96 -> V_110 . V_113 ;
V_103 = V_96 -> V_110 . V_114 ;
} else if ( V_94 == sizeof( struct V_115 ) ) {
struct V_115 * V_116 =
(struct V_115 * ) V_96 ;
V_104 = 3 ;
V_105 = V_116 -> V_110 . V_105 ;
V_101 = V_116 -> V_110 . V_111 ;
V_102 = V_116 -> V_110 . V_112 ;
V_67 = V_116 -> V_110 . V_113 ;
V_103 = V_116 -> V_110 . V_114 ;
} else if ( V_94 == sizeof( struct V_117 ) ) {
struct V_117 * V_118 =
(struct V_117 * ) V_96 ;
V_105 = V_118 -> V_110 . V_105 ;
V_101 = V_118 -> V_110 . V_111 ;
V_102 = V_118 -> V_110 . V_112 ;
V_67 = V_118 -> V_110 . V_113 ;
V_103 = V_118 -> V_110 . V_114 ;
} else if ( V_94 == sizeof( struct V_119 ) ) {
struct V_119 * V_118 =
(struct V_119 * ) V_96 ;
V_104 = 3 ;
V_105 = V_118 -> V_110 . V_105 ;
V_101 = V_118 -> V_110 . V_111 ;
V_102 = V_118 -> V_110 . V_112 ;
V_67 = V_118 -> V_110 . V_113 ;
V_103 = V_118 -> V_110 . V_114 ;
} else {
error = - V_106 ;
goto V_23;
}
error = - V_106 ;
if ( V_101 == 0 )
goto V_23;
V_44 = F_56 ( F_57 ( V_3 ) , V_101 ) ;
if ( ( V_67 == 0 ) && ( V_103 == 0 ) ) {
if ( V_44 == NULL ) {
struct V_120 V_121 = {
. V_52 = V_53 ,
. V_122 = 0 ,
} ;
error = F_58 ( F_57 ( V_3 ) , V_105 , V_104 , V_101 , V_102 , & V_121 , & V_44 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_123 ;
if ( V_44 == NULL )
goto V_23;
if ( V_44 -> V_2 == NULL )
goto V_23;
}
if ( V_44 -> V_124 == NULL )
V_44 -> V_124 = F_5 ;
if ( V_44 -> V_102 == 0 )
V_44 -> V_102 = V_102 ;
V_4 = F_59 ( F_57 ( V_3 ) , V_44 , V_67 ) ;
if ( V_4 == NULL ) {
V_100 . V_125 = V_100 . V_126 = 1500 - V_127 ;
V_4 = F_60 ( sizeof( struct V_30 ) ,
V_44 , V_67 ,
V_103 , & V_100 ) ;
if ( V_4 == NULL ) {
error = - V_55 ;
goto V_23;
}
} else {
V_31 = F_14 ( V_4 ) ;
error = - V_128 ;
if ( V_31 -> V_2 != NULL )
goto V_23;
if ( V_31 -> V_50 != V_44 -> V_2 )
goto V_23;
}
V_31 = F_14 ( V_4 ) ;
V_31 -> V_129 = V_130 -> V_131 ;
V_31 -> V_2 = V_3 ;
V_31 -> V_50 = V_44 -> V_2 ;
V_4 -> V_132 = F_13 ;
V_4 -> V_133 = F_37 ;
#if F_61 ( V_134 ) || F_61 ( V_135 )
V_4 -> V_136 = F_52 ;
#endif
V_4 -> V_137 = F_22 ;
V_4 -> V_138 = F_23 ;
V_98 = F_62 ( V_3 ) ;
if ( V_98 != NULL ) {
T_3 V_139 = F_63 ( F_64 ( V_3 ) ) ;
if ( V_139 != 0 )
V_4 -> V_125 = V_4 -> V_126 = V_139 -
V_127 ;
F_65 ( V_98 ) ;
}
if ( ( V_4 -> V_67 == 0 ) &&
( V_4 -> V_103 == 0 ) ) {
error = 0 ;
goto V_140;
}
V_34 -> V_37 . V_141 = V_142 ;
V_34 -> V_37 . V_62 = V_3 ;
V_34 -> V_37 . V_80 = & V_143 ;
V_34 -> V_37 . V_125 = V_4 -> V_125 ;
error = F_66 ( F_57 ( V_3 ) , & V_34 -> V_37 ) ;
if ( error )
goto V_23;
V_140:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_48 ;
F_21 ( V_4 , V_144 , L_5 ,
V_4 -> V_36 ) ;
V_23:
F_42 ( V_3 ) ;
return error ;
}
static int F_67 ( struct V_75 * V_75 , T_3 V_101 , T_3 V_67 , T_3 V_103 , struct V_99 * V_100 )
{
int error ;
struct V_43 * V_44 ;
struct V_1 * V_4 ;
struct V_30 * V_31 ;
V_44 = F_56 ( V_75 , V_101 ) ;
error = - V_123 ;
if ( V_44 == NULL )
goto V_6;
if ( V_44 -> V_2 == NULL )
goto V_6;
error = - V_128 ;
V_4 = F_59 ( V_75 , V_44 , V_67 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_100 -> V_125 == 0 )
V_100 -> V_125 = 1500 - V_127 ;
if ( V_100 -> V_126 == 0 )
V_100 -> V_126 = V_100 -> V_125 ;
error = - V_55 ;
V_4 = F_60 ( sizeof( struct V_30 ) ,
V_44 , V_67 ,
V_103 , V_100 ) ;
if ( V_4 == NULL )
goto V_6;
V_31 = F_14 ( V_4 ) ;
V_31 -> V_50 = V_44 -> V_2 ;
F_21 ( V_4 , V_144 , L_5 ,
V_4 -> V_36 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_68 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 == NULL )
F_44 ( V_4 ) ;
return 0 ;
}
static int F_69 ( struct V_14 * V_2 , struct V_92 * V_145 ,
int * V_146 , int V_147 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_148 * V_149 ;
struct V_30 * V_150 ;
error = - V_46 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_48 )
goto V_23;
error = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_150 = F_14 ( V_4 ) ;
V_44 = F_26 ( V_150 -> V_50 ) ;
if ( V_44 == NULL ) {
error = - V_49 ;
goto V_151;
}
V_149 = F_70 ( V_44 -> V_2 ) ;
if ( ( V_44 -> V_152 == 2 ) && ( V_44 -> V_2 -> V_85 == V_153 ) ) {
struct V_95 V_96 ;
V_17 = sizeof( V_96 ) ;
memset ( & V_96 , 0 , V_17 ) ;
V_96 . V_154 = V_155 ;
V_96 . V_107 = V_84 ;
V_96 . V_110 . V_105 = V_44 -> V_105 ;
V_96 . V_110 . V_131 = V_150 -> V_129 ;
V_96 . V_110 . V_111 = V_44 -> V_101 ;
V_96 . V_110 . V_112 = V_44 -> V_102 ;
V_96 . V_110 . V_113 = V_4 -> V_67 ;
V_96 . V_110 . V_114 = V_4 -> V_103 ;
V_96 . V_110 . V_156 . V_157 = V_153 ;
V_96 . V_110 . V_156 . V_158 = V_149 -> V_159 ;
V_96 . V_110 . V_156 . V_160 . V_161 = V_149 -> V_162 ;
memcpy ( V_145 , & V_96 , V_17 ) ;
#if F_71 ( V_163 )
} else if ( ( V_44 -> V_152 == 2 ) &&
( V_44 -> V_2 -> V_85 == V_164 ) ) {
struct V_165 * V_166 = F_72 ( V_44 -> V_2 ) ;
struct V_117 V_96 ;
V_17 = sizeof( V_96 ) ;
memset ( & V_96 , 0 , V_17 ) ;
V_96 . V_154 = V_155 ;
V_96 . V_107 = V_84 ;
V_96 . V_110 . V_105 = V_44 -> V_105 ;
V_96 . V_110 . V_131 = V_150 -> V_129 ;
V_96 . V_110 . V_111 = V_44 -> V_101 ;
V_96 . V_110 . V_112 = V_44 -> V_102 ;
V_96 . V_110 . V_113 = V_4 -> V_67 ;
V_96 . V_110 . V_114 = V_4 -> V_103 ;
V_96 . V_110 . V_156 . V_167 = V_164 ;
V_96 . V_110 . V_156 . V_168 = V_149 -> V_159 ;
memcpy ( & V_96 . V_110 . V_156 . V_169 , & V_166 -> V_170 ,
sizeof( V_166 -> V_170 ) ) ;
memcpy ( V_145 , & V_96 , V_17 ) ;
} else if ( ( V_44 -> V_152 == 3 ) &&
( V_44 -> V_2 -> V_85 == V_164 ) ) {
struct V_165 * V_166 = F_72 ( V_44 -> V_2 ) ;
struct V_119 V_96 ;
V_17 = sizeof( V_96 ) ;
memset ( & V_96 , 0 , V_17 ) ;
V_96 . V_154 = V_155 ;
V_96 . V_107 = V_84 ;
V_96 . V_110 . V_105 = V_44 -> V_105 ;
V_96 . V_110 . V_131 = V_150 -> V_129 ;
V_96 . V_110 . V_111 = V_44 -> V_101 ;
V_96 . V_110 . V_112 = V_44 -> V_102 ;
V_96 . V_110 . V_113 = V_4 -> V_67 ;
V_96 . V_110 . V_114 = V_4 -> V_103 ;
V_96 . V_110 . V_156 . V_167 = V_164 ;
V_96 . V_110 . V_156 . V_168 = V_149 -> V_159 ;
memcpy ( & V_96 . V_110 . V_156 . V_169 , & V_166 -> V_170 ,
sizeof( V_166 -> V_170 ) ) ;
memcpy ( V_145 , & V_96 , V_17 ) ;
#endif
} else if ( V_44 -> V_152 == 3 ) {
struct V_115 V_96 ;
V_17 = sizeof( V_96 ) ;
memset ( & V_96 , 0 , V_17 ) ;
V_96 . V_154 = V_155 ;
V_96 . V_107 = V_84 ;
V_96 . V_110 . V_105 = V_44 -> V_105 ;
V_96 . V_110 . V_131 = V_150 -> V_129 ;
V_96 . V_110 . V_111 = V_44 -> V_101 ;
V_96 . V_110 . V_112 = V_44 -> V_102 ;
V_96 . V_110 . V_113 = V_4 -> V_67 ;
V_96 . V_110 . V_114 = V_4 -> V_103 ;
V_96 . V_110 . V_156 . V_157 = V_153 ;
V_96 . V_110 . V_156 . V_158 = V_149 -> V_159 ;
V_96 . V_110 . V_156 . V_160 . V_161 = V_149 -> V_162 ;
memcpy ( V_145 , & V_96 , V_17 ) ;
}
* V_146 = V_17 ;
F_3 ( V_150 -> V_50 ) ;
V_151:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_73 ( struct V_171 * V_172 ,
struct V_173 * V_38 )
{
V_172 -> V_174 = V_38 -> V_174 ;
V_172 -> V_175 = V_38 -> V_175 ;
V_172 -> V_176 = V_38 -> V_176 ;
V_172 -> V_177 = V_38 -> V_177 ;
V_172 -> V_178 = V_38 -> V_178 ;
V_172 -> V_179 = V_38 -> V_179 ;
V_172 -> V_180 = V_38 -> V_180 ;
V_172 -> V_39 = V_38 -> V_39 ;
}
static int F_74 ( struct V_1 * V_4 ,
unsigned int V_181 , unsigned long V_91 )
{
struct V_182 V_183 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_184 = ( int ) V_91 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_171 V_38 ;
F_15 ( V_4 , V_144 ,
L_6 ,
V_4 -> V_36 , V_181 , V_91 ) ;
V_3 = V_31 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_181 ) {
case V_185 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_187 ;
if ( F_75 ( & V_183 , ( void V_188 * ) V_91 , sizeof( struct V_182 ) ) )
break;
V_183 . V_189 = V_4 -> V_125 ;
if ( F_76 ( ( void V_188 * ) V_91 , & V_183 , sizeof( struct V_182 ) ) )
break;
F_21 ( V_4 , V_144 , L_7 ,
V_4 -> V_36 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_187 ;
if ( F_75 ( & V_183 , ( void V_188 * ) V_91 , sizeof( struct V_182 ) ) )
break;
V_4 -> V_125 = V_183 . V_189 ;
F_21 ( V_4 , V_144 , L_8 ,
V_4 -> V_36 , V_4 -> V_125 ) ;
V_19 = 0 ;
break;
case V_191 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_187 ;
if ( F_77 ( V_4 -> V_126 , ( int V_188 * ) V_91 ) )
break;
F_21 ( V_4 , V_144 , L_9 ,
V_4 -> V_36 , V_4 -> V_126 ) ;
V_19 = 0 ;
break;
case V_192 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_187 ;
if ( F_78 ( V_184 , ( int V_188 * ) V_91 ) )
break;
V_4 -> V_126 = V_184 ;
F_21 ( V_4 , V_144 , L_10 ,
V_4 -> V_36 , V_4 -> V_126 ) ;
V_19 = 0 ;
break;
case V_193 :
V_19 = - V_187 ;
if ( F_77 ( V_31 -> V_18 , ( int V_188 * ) V_91 ) )
break;
F_21 ( V_4 , V_144 , L_11 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_194 :
V_19 = - V_187 ;
if ( F_78 ( V_184 , ( int V_188 * ) V_91 ) )
break;
V_31 -> V_18 = V_184 ;
F_21 ( V_4 , V_144 , L_12 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_195 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_101 = V_44 -> V_101 ;
V_38 . V_67 = V_4 -> V_67 ;
F_73 ( & V_38 , & V_4 -> V_38 ) ;
if ( F_76 ( ( void V_188 * ) V_91 , & V_38 ,
sizeof( V_38 ) ) )
break;
F_21 ( V_4 , V_144 , L_13 ,
V_4 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_196 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_79 ( struct V_43 * V_44 ,
unsigned int V_181 , unsigned long V_91 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_171 V_38 ;
F_15 ( V_44 , V_144 ,
L_14 ,
V_44 -> V_36 , V_181 , V_91 ) ;
V_3 = V_44 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_181 ) {
case V_195 :
V_19 = - V_186 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
if ( F_75 ( & V_38 , ( void V_188 * ) V_91 ,
sizeof( V_38 ) ) ) {
V_19 = - V_187 ;
break;
}
if ( V_38 . V_67 != 0 ) {
struct V_1 * V_4 =
F_59 ( F_57 ( V_3 ) , V_44 , V_38 . V_67 ) ;
if ( V_4 != NULL )
V_19 = F_74 ( V_4 , V_181 , V_91 ) ;
else
V_19 = - V_197 ;
break;
}
#ifdef F_80
V_38 . V_198 = ( V_3 -> V_199 [ 0 ] || V_3 -> V_199 [ 1 ] ) ? 1 : 0 ;
#endif
F_73 ( & V_38 , & V_44 -> V_38 ) ;
if ( F_76 ( ( void V_188 * ) V_91 , & V_38 , sizeof( V_38 ) ) ) {
V_19 = - V_187 ;
break;
}
F_21 ( V_44 , V_144 , L_13 ,
V_44 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_196 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_81 ( struct V_14 * V_2 , unsigned int V_181 ,
unsigned long V_91 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_49 ;
if ( F_25 ( V_3 , V_47 ) != 0 )
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
if ( ( V_4 -> V_67 == 0 ) &&
( V_4 -> V_103 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_151;
V_19 = F_79 ( V_44 , V_181 , V_91 ) ;
F_3 ( V_31 -> V_50 ) ;
goto V_151;
}
V_19 = F_74 ( V_4 , V_181 , V_91 ) ;
V_151:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_200 , int V_184 )
{
int V_19 = 0 ;
switch ( V_200 ) {
case V_201 :
V_44 -> V_122 = V_184 ;
F_21 ( V_44 , V_144 , L_15 ,
V_44 -> V_36 , V_44 -> V_122 ) ;
break;
default:
V_19 = - V_202 ;
break;
}
return V_19 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_200 , int V_184 )
{
int V_19 = 0 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
switch ( V_200 ) {
case V_203 :
if ( ( V_184 != 0 ) && ( V_184 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_204 = V_184 ? - 1 : 0 ;
F_21 ( V_4 , V_144 ,
L_16 ,
V_4 -> V_36 , V_4 -> V_204 ) ;
break;
case V_205 :
if ( ( V_184 != 0 ) && ( V_184 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_206 = V_184 ? - 1 : 0 ;
{
struct V_2 * V_207 = V_31 -> V_2 ;
struct V_33 * V_34 = F_19 ( V_207 ) ;
V_34 -> V_37 . V_141 = V_184 ? V_208 :
V_142 ;
}
F_21 ( V_4 , V_144 ,
L_17 ,
V_4 -> V_36 , V_4 -> V_206 ) ;
break;
case V_209 :
if ( ( V_184 != 0 ) && ( V_184 != 1 ) ) {
V_19 = - V_106 ;
break;
}
V_4 -> V_210 = V_184 ? - 1 : 0 ;
F_21 ( V_4 , V_144 ,
L_18 ,
V_4 -> V_36 , V_4 -> V_210 ) ;
break;
case V_201 :
V_4 -> V_122 = V_184 ;
F_21 ( V_4 , V_144 , L_15 ,
V_4 -> V_36 , V_4 -> V_122 ) ;
break;
case V_211 :
V_4 -> V_212 = F_84 ( V_184 ) ;
F_21 ( V_4 , V_144 ,
L_19 ,
V_4 -> V_36 , V_4 -> V_212 ) ;
break;
default:
V_19 = - V_202 ;
break;
}
return V_19 ;
}
static int F_85 ( struct V_14 * V_2 , int V_213 , int V_200 ,
char V_188 * V_214 , unsigned int V_215 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_184 ;
int V_19 ;
if ( V_213 != V_216 )
return V_217 . V_218 ( V_3 , V_213 , V_200 , V_214 , V_215 ) ;
if ( V_215 < sizeof( int ) )
return - V_106 ;
if ( F_78 ( V_184 , ( int V_188 * ) V_214 ) )
return - V_187 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_67 == 0 ) &&
( V_4 -> V_103 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_151;
V_19 = F_82 ( V_3 , V_44 , V_200 , V_184 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_83 ( V_3 , V_4 , V_200 , V_184 ) ;
V_19 = 0 ;
V_151:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_200 , int * V_184 )
{
int V_19 = 0 ;
switch ( V_200 ) {
case V_201 :
* V_184 = V_44 -> V_122 ;
F_21 ( V_44 , V_144 , L_20 ,
V_44 -> V_36 , V_44 -> V_122 ) ;
break;
default:
V_19 = - V_202 ;
break;
}
return V_19 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_200 , int * V_184 )
{
int V_19 = 0 ;
switch ( V_200 ) {
case V_203 :
* V_184 = V_4 -> V_204 ;
F_21 ( V_4 , V_144 ,
L_21 , V_4 -> V_36 , * V_184 ) ;
break;
case V_205 :
* V_184 = V_4 -> V_206 ;
F_21 ( V_4 , V_144 ,
L_22 , V_4 -> V_36 , * V_184 ) ;
break;
case V_209 :
* V_184 = V_4 -> V_210 ;
F_21 ( V_4 , V_144 ,
L_23 , V_4 -> V_36 , * V_184 ) ;
break;
case V_201 :
* V_184 = V_4 -> V_122 ;
F_21 ( V_4 , V_144 , L_24 ,
V_4 -> V_36 , * V_184 ) ;
break;
case V_211 :
* V_184 = ( int ) F_88 ( V_4 -> V_212 ) ;
F_21 ( V_4 , V_144 ,
L_25 , V_4 -> V_36 , * V_184 ) ;
break;
default:
V_19 = - V_202 ;
}
return V_19 ;
}
static int F_89 ( struct V_14 * V_2 , int V_213 , int V_200 ,
char V_188 * V_214 , int V_188 * V_215 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
int V_184 , V_17 ;
int V_19 ;
struct V_30 * V_31 ;
if ( V_213 != V_216 )
return V_217 . V_219 ( V_3 , V_213 , V_200 , V_214 , V_215 ) ;
if ( F_78 ( V_17 , V_215 ) )
return - V_187 ;
V_17 = F_90 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_106 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_67 == 0 ) &&
( V_4 -> V_103 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_151;
V_19 = F_86 ( V_3 , V_44 , V_200 , & V_184 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_87 ( V_3 , V_4 , V_200 , & V_184 ) ;
V_19 = - V_187 ;
if ( F_77 ( V_17 , V_215 ) )
goto V_151;
if ( F_76 ( ( void V_188 * ) V_214 , & V_184 , V_17 ) )
goto V_151;
V_19 = 0 ;
V_151:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_91 ( struct V_75 * V_75 , struct V_220 * V_221 )
{
for (; ; ) {
V_221 -> V_44 = F_92 ( V_75 , V_221 -> V_222 ) ;
V_221 -> V_222 ++ ;
if ( V_221 -> V_44 == NULL )
break;
if ( V_221 -> V_44 -> V_152 < 3 )
break;
}
}
static void F_93 ( struct V_75 * V_75 , struct V_220 * V_221 )
{
V_221 -> V_4 = F_94 ( V_221 -> V_44 , V_221 -> V_223 ) ;
V_221 -> V_223 ++ ;
if ( V_221 -> V_4 == NULL ) {
V_221 -> V_223 = 0 ;
F_91 ( V_75 , V_221 ) ;
}
}
static void * F_95 ( struct V_90 * V_40 , T_4 * V_224 )
{
struct V_220 * V_221 = V_225 ;
T_4 V_226 = * V_224 ;
struct V_75 * V_75 ;
if ( ! V_226 )
goto V_6;
F_4 ( V_40 -> V_62 == NULL ) ;
V_221 = V_40 -> V_62 ;
V_75 = F_96 ( V_40 ) ;
if ( V_221 -> V_44 == NULL )
F_91 ( V_75 , V_221 ) ;
else
F_93 ( V_75 , V_221 ) ;
if ( ( V_221 -> V_44 == NULL ) && ( V_221 -> V_4 == NULL ) )
V_221 = NULL ;
V_6:
return V_221 ;
}
static void * F_97 ( struct V_90 * V_40 , void * V_227 , T_4 * V_226 )
{
( * V_226 ) ++ ;
return NULL ;
}
static void F_98 ( struct V_90 * V_228 , void * V_227 )
{
}
static void F_99 ( struct V_90 * V_40 , void * V_227 )
{
struct V_43 * V_44 = V_227 ;
F_53 ( V_40 , L_26 ,
V_44 -> V_36 ,
( V_44 == V_44 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_100 ( & V_44 -> V_229 ) - 1 ) ;
F_53 ( V_40 , L_27 ,
V_44 -> V_122 ,
( unsigned long long ) V_44 -> V_38 . V_174 ,
( unsigned long long ) V_44 -> V_38 . V_175 ,
( unsigned long long ) V_44 -> V_38 . V_176 ,
( unsigned long long ) V_44 -> V_38 . V_177 ,
( unsigned long long ) V_44 -> V_38 . V_178 ,
( unsigned long long ) V_44 -> V_38 . V_39 ) ;
}
static void F_101 ( struct V_90 * V_40 , void * V_227 )
{
struct V_1 * V_4 = V_227 ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
T_3 V_230 = 0 ;
T_5 V_231 = 0 ;
if ( V_44 -> V_2 ) {
struct V_148 * V_149 = F_70 ( V_44 -> V_2 ) ;
V_230 = F_102 ( V_149 -> V_232 ) ;
V_231 = F_103 ( V_149 -> V_233 ) ;
}
F_53 ( V_40 , L_28
L_29 ,
V_4 -> V_36 , V_230 , V_231 ,
V_44 -> V_101 ,
V_4 -> V_67 ,
V_44 -> V_102 ,
V_4 -> V_103 ,
V_31 -> V_2 -> V_21 ,
( V_4 == V_31 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_53 ( V_40 , L_30 ,
V_4 -> V_125 , V_4 -> V_126 ,
V_4 -> V_204 ? 'R' : '-' ,
V_4 -> V_206 ? 'S' : '-' ,
V_4 -> V_210 ? L_31 : L_32 ,
V_4 -> V_122 ,
F_88 ( V_4 -> V_212 ) ) ;
F_53 ( V_40 , L_33 ,
V_4 -> V_234 , V_4 -> V_235 ,
( unsigned long long ) V_4 -> V_38 . V_174 ,
( unsigned long long ) V_4 -> V_38 . V_175 ,
( unsigned long long ) V_4 -> V_38 . V_176 ,
( unsigned long long ) V_4 -> V_38 . V_177 ,
( unsigned long long ) V_4 -> V_38 . V_178 ,
( unsigned long long ) V_4 -> V_38 . V_39 ) ;
if ( V_34 )
F_53 ( V_40 , L_4 , F_54 ( & V_34 -> V_37 ) ) ;
}
static int F_104 ( struct V_90 * V_40 , void * V_227 )
{
struct V_220 * V_221 = V_227 ;
if ( V_227 == V_225 ) {
F_105 ( V_40 , L_34 V_236 L_35 ) ;
F_105 ( V_40 , L_36 ) ;
F_105 ( V_40 , L_37 ) ;
F_105 ( V_40 , L_38
L_39 ) ;
F_105 ( V_40 , L_40 ) ;
F_105 ( V_40 , L_41 ) ;
goto V_6;
}
if ( V_221 -> V_4 == NULL )
F_99 ( V_40 , V_221 -> V_44 ) ;
else
F_101 ( V_40 , V_221 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_106 ( struct V_237 * V_237 , struct V_238 * V_238 )
{
return F_107 ( V_237 , V_238 , & V_239 ,
sizeof( struct V_220 ) ) ;
}
static T_6 int F_108 ( struct V_75 * V_75 )
{
struct V_240 * V_241 ;
int V_19 = 0 ;
V_241 = F_109 ( V_75 , L_42 , V_242 , & V_243 ) ;
if ( ! V_241 ) {
V_19 = - V_55 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_110 ( struct V_75 * V_75 )
{
F_111 ( V_75 , L_42 ) ;
}
static int T_8 F_112 ( void )
{
int V_19 ;
V_19 = F_113 ( & V_244 ) ;
if ( V_19 )
goto V_6;
V_19 = F_114 ( & V_77 , 0 ) ;
if ( V_19 )
goto V_245;
V_19 = F_115 ( V_84 , & V_246 ) ;
if ( V_19 )
goto V_247;
#ifdef F_116
V_19 = F_117 ( V_248 , & V_249 ) ;
if ( V_19 )
goto V_250;
#endif
F_118 ( L_43 , V_236 ) ;
V_6:
return V_19 ;
#ifdef F_116
V_250:
F_119 ( V_84 ) ;
#endif
V_247:
F_120 ( & V_77 ) ;
V_245:
F_121 ( & V_244 ) ;
goto V_6;
}
static void T_9 F_122 ( void )
{
#ifdef F_116
F_123 ( V_248 ) ;
#endif
F_119 ( V_84 ) ;
F_120 ( & V_77 ) ;
F_121 ( & V_244 ) ;
}
