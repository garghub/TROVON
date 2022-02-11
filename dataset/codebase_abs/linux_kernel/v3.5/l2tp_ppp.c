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
int V_64 ;
int V_65 ;
int V_45 , V_66 ;
if ( F_25 ( V_3 , V_47 ) || ! ( V_3 -> V_21 & V_48 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_31 = F_14 ( V_4 ) ;
V_63 = V_31 -> V_50 ;
if ( V_63 == NULL )
goto V_67;
V_44 = F_26 ( V_63 ) ;
if ( V_44 == NULL )
goto V_67;
V_64 = F_35 ( V_10 ) ;
V_45 = ( V_44 -> V_52 == V_53 ) ? sizeof( struct V_54 ) : 0 ;
V_66 = V_56 +
sizeof( struct V_57 ) +
V_45 +
V_4 -> V_58 +
sizeof( V_42 ) ;
if ( F_36 ( V_10 , V_66 ) )
goto V_68;
V_65 = F_35 ( V_10 ) ;
V_10 -> V_69 += V_65 - V_64 ;
F_37 ( V_10 , sizeof( V_42 ) ) ;
V_10 -> V_11 [ 0 ] = V_42 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_42 [ 1 ] ;
F_33 ( V_4 , V_10 , V_4 -> V_58 ) ;
F_3 ( V_63 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_68:
F_3 ( V_63 ) ;
V_67:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_38 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_31 -> V_2 ;
struct V_9 * V_10 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_4 -> V_70 == 0 )
goto V_6;
if ( V_3 != NULL ) {
F_39 ( V_3 ) ;
if ( V_3 -> V_21 & ( V_48 | V_22 ) ) {
F_40 ( V_3 ) ;
V_3 -> V_21 = V_71 ;
V_3 -> V_72 ( V_3 ) ;
}
F_41 ( & V_3 -> V_73 ) ;
F_41 ( & V_3 -> V_74 ) ;
while ( ( V_10 = F_42 ( & V_4 -> V_75 ) ) ) {
F_12 ( V_10 ) ;
F_3 ( V_3 ) ;
}
F_43 ( V_3 ) ;
}
V_6:
return;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_5 != NULL ) {
V_4 = V_3 -> V_5 ;
if ( V_4 == NULL )
goto V_6;
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_45 ( V_4 ) ;
}
V_6:
return;
}
static int F_46 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_49 ;
F_39 ( V_3 ) ;
if ( F_25 ( V_3 , V_47 ) != 0 )
goto error;
F_40 ( V_3 ) ;
V_3 -> V_21 = V_71 ;
F_47 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
F_41 ( & V_3 -> V_73 ) ;
F_41 ( & V_3 -> V_74 ) ;
if ( V_4 != NULL ) {
struct V_9 * V_10 ;
while ( ( V_10 = F_42 ( & V_4 -> V_75 ) ) ) {
F_12 ( V_10 ) ;
F_3 ( V_3 ) ;
}
F_3 ( V_3 ) ;
}
F_43 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_43 ( V_3 ) ;
return error ;
}
static int F_48 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_76 ;
V_76 = F_49 ( V_3 , V_10 ) ;
if ( V_76 )
F_12 ( V_10 ) ;
return V_77 ;
}
static int F_50 ( struct V_78 * V_78 , struct V_14 * V_2 )
{
int error = - V_55 ;
struct V_2 * V_3 ;
V_3 = F_51 ( V_78 , V_79 , V_59 , & V_80 ) ;
if ( ! V_3 )
goto V_6;
F_52 ( V_2 , V_3 ) ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = & V_84 ;
V_3 -> V_85 = F_48 ;
V_3 -> V_86 = V_87 ;
V_3 -> V_88 = V_79 ;
V_3 -> V_21 = V_89 ;
V_3 -> V_90 = V_91 ;
V_3 -> V_92 = F_44 ;
error = 0 ;
V_6:
return error ;
}
static void F_53 ( struct V_93 * V_40 , void * V_94 )
{
struct V_1 * V_4 = V_94 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 ) {
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
if ( V_34 )
F_54 ( V_40 , L_4 , F_55 ( & V_34 -> V_37 ) ) ;
}
}
static int F_56 ( struct V_14 * V_2 , struct V_95 * V_96 ,
int V_97 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_98 * V_99 = (struct V_98 * ) V_96 ;
struct V_33 * V_34 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
struct V_100 * V_101 ;
struct V_102 V_103 = { 0 , } ;
int error = 0 ;
T_3 V_104 , V_105 ;
T_3 V_70 , V_106 ;
int V_107 = 2 ;
int V_108 ;
F_39 ( V_3 ) ;
error = - V_109 ;
if ( V_99 -> V_110 != V_87 )
goto V_23;
error = - V_111 ;
if ( V_3 -> V_21 & V_48 )
goto V_23;
error = - V_112 ;
if ( V_3 -> V_5 )
goto V_23;
V_105 = 0 ;
if ( V_97 == sizeof( struct V_98 ) ) {
V_108 = V_99 -> V_113 . V_108 ;
V_104 = V_99 -> V_113 . V_114 ;
V_105 = V_99 -> V_113 . V_115 ;
V_70 = V_99 -> V_113 . V_116 ;
V_106 = V_99 -> V_113 . V_117 ;
} else if ( V_97 == sizeof( struct V_118 ) ) {
struct V_118 * V_119 =
(struct V_118 * ) V_99 ;
V_107 = 3 ;
V_108 = V_119 -> V_113 . V_108 ;
V_104 = V_119 -> V_113 . V_114 ;
V_105 = V_119 -> V_113 . V_115 ;
V_70 = V_119 -> V_113 . V_116 ;
V_106 = V_119 -> V_113 . V_117 ;
} else if ( V_97 == sizeof( struct V_120 ) ) {
struct V_120 * V_121 =
(struct V_120 * ) V_99 ;
V_108 = V_121 -> V_113 . V_108 ;
V_104 = V_121 -> V_113 . V_114 ;
V_105 = V_121 -> V_113 . V_115 ;
V_70 = V_121 -> V_113 . V_116 ;
V_106 = V_121 -> V_113 . V_117 ;
} else if ( V_97 == sizeof( struct V_122 ) ) {
struct V_122 * V_121 =
(struct V_122 * ) V_99 ;
V_107 = 3 ;
V_108 = V_121 -> V_113 . V_108 ;
V_104 = V_121 -> V_113 . V_114 ;
V_105 = V_121 -> V_113 . V_115 ;
V_70 = V_121 -> V_113 . V_116 ;
V_106 = V_121 -> V_113 . V_117 ;
} else {
error = - V_109 ;
goto V_23;
}
error = - V_109 ;
if ( V_104 == 0 )
goto V_23;
V_44 = F_57 ( F_58 ( V_3 ) , V_104 ) ;
if ( ( V_70 == 0 ) && ( V_106 == 0 ) ) {
if ( V_44 == NULL ) {
struct V_123 V_124 = {
. V_52 = V_53 ,
. V_125 = 0 ,
} ;
error = F_59 ( F_58 ( V_3 ) , V_108 , V_107 , V_104 , V_105 , & V_124 , & V_44 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_126 ;
if ( V_44 == NULL )
goto V_23;
if ( V_44 -> V_2 == NULL )
goto V_23;
}
if ( V_44 -> V_127 == NULL )
V_44 -> V_127 = F_5 ;
if ( V_44 -> V_105 == 0 )
V_44 -> V_105 = V_105 ;
V_4 = F_60 ( F_58 ( V_3 ) , V_44 , V_70 ) ;
if ( V_4 == NULL ) {
V_103 . V_128 = V_103 . V_129 = 1500 - V_130 ;
V_4 = F_61 ( sizeof( struct V_30 ) ,
V_44 , V_70 ,
V_106 , & V_103 ) ;
if ( V_4 == NULL ) {
error = - V_55 ;
goto V_23;
}
} else {
V_31 = F_14 ( V_4 ) ;
error = - V_131 ;
if ( V_31 -> V_2 != NULL )
goto V_23;
if ( V_31 -> V_50 != V_44 -> V_2 )
goto V_23;
}
V_31 = F_14 ( V_4 ) ;
V_31 -> V_132 = V_133 -> V_134 ;
V_31 -> V_2 = V_3 ;
V_31 -> V_50 = V_44 -> V_2 ;
V_4 -> V_135 = F_13 ;
V_4 -> V_136 = F_38 ;
#if F_62 ( V_137 ) || F_62 ( V_138 )
V_4 -> V_139 = F_53 ;
#endif
V_4 -> V_140 = F_22 ;
V_4 -> V_141 = F_23 ;
V_101 = F_63 ( V_3 ) ;
if ( V_101 != NULL ) {
T_3 V_142 = F_64 ( F_65 ( V_3 ) ) ;
if ( V_142 != 0 )
V_4 -> V_128 = V_4 -> V_129 = V_142 -
V_130 ;
F_66 ( V_101 ) ;
}
if ( ( V_4 -> V_70 == 0 ) &&
( V_4 -> V_106 == 0 ) ) {
error = 0 ;
goto V_143;
}
V_34 -> V_37 . V_144 = V_145 ;
V_34 -> V_37 . V_62 = V_3 ;
V_34 -> V_37 . V_83 = & V_146 ;
V_34 -> V_37 . V_128 = V_4 -> V_128 ;
error = F_67 ( F_58 ( V_3 ) , & V_34 -> V_37 ) ;
if ( error )
goto V_23;
V_143:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_48 ;
F_21 ( V_4 , V_147 , L_5 ,
V_4 -> V_36 ) ;
V_23:
F_43 ( V_3 ) ;
return error ;
}
static int F_68 ( struct V_78 * V_78 , T_3 V_104 , T_3 V_70 , T_3 V_106 , struct V_102 * V_103 )
{
int error ;
struct V_43 * V_44 ;
struct V_1 * V_4 ;
struct V_30 * V_31 ;
V_44 = F_57 ( V_78 , V_104 ) ;
error = - V_126 ;
if ( V_44 == NULL )
goto V_6;
if ( V_44 -> V_2 == NULL )
goto V_6;
error = - V_131 ;
V_4 = F_60 ( V_78 , V_44 , V_70 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_103 -> V_128 == 0 )
V_103 -> V_128 = 1500 - V_130 ;
if ( V_103 -> V_129 == 0 )
V_103 -> V_129 = V_103 -> V_128 ;
error = - V_55 ;
V_4 = F_61 ( sizeof( struct V_30 ) ,
V_44 , V_70 ,
V_106 , V_103 ) ;
if ( V_4 == NULL )
goto V_6;
V_31 = F_14 ( V_4 ) ;
V_31 -> V_50 = V_44 -> V_2 ;
F_21 ( V_4 , V_147 , L_5 ,
V_4 -> V_36 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_69 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 == NULL )
F_45 ( V_4 ) ;
return 0 ;
}
static int F_70 ( struct V_14 * V_2 , struct V_95 * V_148 ,
int * V_149 , int V_150 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_151 * V_152 ;
struct V_30 * V_153 ;
error = - V_46 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_48 )
goto V_23;
error = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_153 = F_14 ( V_4 ) ;
V_44 = F_26 ( V_153 -> V_50 ) ;
if ( V_44 == NULL ) {
error = - V_49 ;
goto V_154;
}
V_152 = F_71 ( V_44 -> V_2 ) ;
if ( ( V_44 -> V_155 == 2 ) && ( V_44 -> V_2 -> V_88 == V_156 ) ) {
struct V_98 V_99 ;
V_17 = sizeof( V_99 ) ;
memset ( & V_99 , 0 , V_17 ) ;
V_99 . V_157 = V_158 ;
V_99 . V_110 = V_87 ;
V_99 . V_113 . V_108 = V_44 -> V_108 ;
V_99 . V_113 . V_134 = V_153 -> V_132 ;
V_99 . V_113 . V_114 = V_44 -> V_104 ;
V_99 . V_113 . V_115 = V_44 -> V_105 ;
V_99 . V_113 . V_116 = V_4 -> V_70 ;
V_99 . V_113 . V_117 = V_4 -> V_106 ;
V_99 . V_113 . V_159 . V_160 = V_156 ;
V_99 . V_113 . V_159 . V_161 = V_152 -> V_162 ;
V_99 . V_113 . V_159 . V_163 . V_164 = V_152 -> V_165 ;
memcpy ( V_148 , & V_99 , V_17 ) ;
#if F_72 ( V_166 )
} else if ( ( V_44 -> V_155 == 2 ) &&
( V_44 -> V_2 -> V_88 == V_167 ) ) {
struct V_168 * V_169 = F_73 ( V_44 -> V_2 ) ;
struct V_120 V_99 ;
V_17 = sizeof( V_99 ) ;
memset ( & V_99 , 0 , V_17 ) ;
V_99 . V_157 = V_158 ;
V_99 . V_110 = V_87 ;
V_99 . V_113 . V_108 = V_44 -> V_108 ;
V_99 . V_113 . V_134 = V_153 -> V_132 ;
V_99 . V_113 . V_114 = V_44 -> V_104 ;
V_99 . V_113 . V_115 = V_44 -> V_105 ;
V_99 . V_113 . V_116 = V_4 -> V_70 ;
V_99 . V_113 . V_117 = V_4 -> V_106 ;
V_99 . V_113 . V_159 . V_170 = V_167 ;
V_99 . V_113 . V_159 . V_171 = V_152 -> V_162 ;
memcpy ( & V_99 . V_113 . V_159 . V_172 , & V_169 -> V_173 ,
sizeof( V_169 -> V_173 ) ) ;
memcpy ( V_148 , & V_99 , V_17 ) ;
} else if ( ( V_44 -> V_155 == 3 ) &&
( V_44 -> V_2 -> V_88 == V_167 ) ) {
struct V_168 * V_169 = F_73 ( V_44 -> V_2 ) ;
struct V_122 V_99 ;
V_17 = sizeof( V_99 ) ;
memset ( & V_99 , 0 , V_17 ) ;
V_99 . V_157 = V_158 ;
V_99 . V_110 = V_87 ;
V_99 . V_113 . V_108 = V_44 -> V_108 ;
V_99 . V_113 . V_134 = V_153 -> V_132 ;
V_99 . V_113 . V_114 = V_44 -> V_104 ;
V_99 . V_113 . V_115 = V_44 -> V_105 ;
V_99 . V_113 . V_116 = V_4 -> V_70 ;
V_99 . V_113 . V_117 = V_4 -> V_106 ;
V_99 . V_113 . V_159 . V_170 = V_167 ;
V_99 . V_113 . V_159 . V_171 = V_152 -> V_162 ;
memcpy ( & V_99 . V_113 . V_159 . V_172 , & V_169 -> V_173 ,
sizeof( V_169 -> V_173 ) ) ;
memcpy ( V_148 , & V_99 , V_17 ) ;
#endif
} else if ( V_44 -> V_155 == 3 ) {
struct V_118 V_99 ;
V_17 = sizeof( V_99 ) ;
memset ( & V_99 , 0 , V_17 ) ;
V_99 . V_157 = V_158 ;
V_99 . V_110 = V_87 ;
V_99 . V_113 . V_108 = V_44 -> V_108 ;
V_99 . V_113 . V_134 = V_153 -> V_132 ;
V_99 . V_113 . V_114 = V_44 -> V_104 ;
V_99 . V_113 . V_115 = V_44 -> V_105 ;
V_99 . V_113 . V_116 = V_4 -> V_70 ;
V_99 . V_113 . V_117 = V_4 -> V_106 ;
V_99 . V_113 . V_159 . V_160 = V_156 ;
V_99 . V_113 . V_159 . V_161 = V_152 -> V_162 ;
V_99 . V_113 . V_159 . V_163 . V_164 = V_152 -> V_165 ;
memcpy ( V_148 , & V_99 , V_17 ) ;
}
* V_149 = V_17 ;
F_3 ( V_153 -> V_50 ) ;
V_154:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_74 ( struct V_174 * V_175 ,
struct V_176 * V_38 )
{
V_175 -> V_177 = V_38 -> V_177 ;
V_175 -> V_178 = V_38 -> V_178 ;
V_175 -> V_179 = V_38 -> V_179 ;
V_175 -> V_180 = V_38 -> V_180 ;
V_175 -> V_181 = V_38 -> V_181 ;
V_175 -> V_182 = V_38 -> V_182 ;
V_175 -> V_183 = V_38 -> V_183 ;
V_175 -> V_39 = V_38 -> V_39 ;
}
static int F_75 ( struct V_1 * V_4 ,
unsigned int V_184 , unsigned long V_94 )
{
struct V_185 V_186 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_187 = ( int ) V_94 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_174 V_38 ;
F_15 ( V_4 , V_147 ,
L_6 ,
V_4 -> V_36 , V_184 , V_94 ) ;
V_3 = V_31 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_184 ) {
case V_188 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_190 ;
if ( F_76 ( & V_186 , ( void V_191 * ) V_94 , sizeof( struct V_185 ) ) )
break;
V_186 . V_192 = V_4 -> V_128 ;
if ( F_77 ( ( void V_191 * ) V_94 , & V_186 , sizeof( struct V_185 ) ) )
break;
F_21 ( V_4 , V_147 , L_7 ,
V_4 -> V_36 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_193 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_190 ;
if ( F_76 ( & V_186 , ( void V_191 * ) V_94 , sizeof( struct V_185 ) ) )
break;
V_4 -> V_128 = V_186 . V_192 ;
F_21 ( V_4 , V_147 , L_8 ,
V_4 -> V_36 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_194 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_190 ;
if ( F_78 ( V_4 -> V_129 , ( int V_191 * ) V_94 ) )
break;
F_21 ( V_4 , V_147 , L_9 ,
V_4 -> V_36 , V_4 -> V_129 ) ;
V_19 = 0 ;
break;
case V_195 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
V_19 = - V_190 ;
if ( F_79 ( V_187 , ( int V_191 * ) V_94 ) )
break;
V_4 -> V_129 = V_187 ;
F_21 ( V_4 , V_147 , L_10 ,
V_4 -> V_36 , V_4 -> V_129 ) ;
V_19 = 0 ;
break;
case V_196 :
V_19 = - V_190 ;
if ( F_78 ( V_31 -> V_18 , ( int V_191 * ) V_94 ) )
break;
F_21 ( V_4 , V_147 , L_11 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_197 :
V_19 = - V_190 ;
if ( F_79 ( V_187 , ( int V_191 * ) V_94 ) )
break;
V_31 -> V_18 = V_187 ;
F_21 ( V_4 , V_147 , L_12 ,
V_4 -> V_36 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_198 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_104 = V_44 -> V_104 ;
V_38 . V_70 = V_4 -> V_70 ;
F_74 ( & V_38 , & V_4 -> V_38 ) ;
if ( F_77 ( ( void V_191 * ) V_94 , & V_38 ,
sizeof( V_38 ) ) )
break;
F_21 ( V_4 , V_147 , L_13 ,
V_4 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_199 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_80 ( struct V_43 * V_44 ,
unsigned int V_184 , unsigned long V_94 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_174 V_38 ;
F_15 ( V_44 , V_147 ,
L_14 ,
V_44 -> V_36 , V_184 , V_94 ) ;
V_3 = V_44 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_184 ) {
case V_198 :
V_19 = - V_189 ;
if ( ! ( V_3 -> V_21 & V_48 ) )
break;
if ( F_76 ( & V_38 , ( void V_191 * ) V_94 ,
sizeof( V_38 ) ) ) {
V_19 = - V_190 ;
break;
}
if ( V_38 . V_70 != 0 ) {
struct V_1 * V_4 =
F_60 ( F_58 ( V_3 ) , V_44 , V_38 . V_70 ) ;
if ( V_4 != NULL )
V_19 = F_75 ( V_4 , V_184 , V_94 ) ;
else
V_19 = - V_200 ;
break;
}
#ifdef F_81
V_38 . V_201 = ( V_3 -> V_202 [ 0 ] || V_3 -> V_202 [ 1 ] ) ? 1 : 0 ;
#endif
F_74 ( & V_38 , & V_44 -> V_38 ) ;
if ( F_77 ( ( void V_191 * ) V_94 , & V_38 , sizeof( V_38 ) ) ) {
V_19 = - V_190 ;
break;
}
F_21 ( V_44 , V_147 , L_13 ,
V_44 -> V_36 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_199 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_82 ( struct V_14 * V_2 , unsigned int V_184 ,
unsigned long V_94 )
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
if ( ( V_4 -> V_70 == 0 ) &&
( V_4 -> V_106 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_154;
V_19 = F_80 ( V_44 , V_184 , V_94 ) ;
F_3 ( V_31 -> V_50 ) ;
goto V_154;
}
V_19 = F_75 ( V_4 , V_184 , V_94 ) ;
V_154:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_203 , int V_187 )
{
int V_19 = 0 ;
switch ( V_203 ) {
case V_204 :
V_44 -> V_125 = V_187 ;
F_21 ( V_44 , V_147 , L_15 ,
V_44 -> V_36 , V_44 -> V_125 ) ;
break;
default:
V_19 = - V_205 ;
break;
}
return V_19 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_203 , int V_187 )
{
int V_19 = 0 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
switch ( V_203 ) {
case V_206 :
if ( ( V_187 != 0 ) && ( V_187 != 1 ) ) {
V_19 = - V_109 ;
break;
}
V_4 -> V_207 = V_187 ? - 1 : 0 ;
F_21 ( V_4 , V_147 ,
L_16 ,
V_4 -> V_36 , V_4 -> V_207 ) ;
break;
case V_208 :
if ( ( V_187 != 0 ) && ( V_187 != 1 ) ) {
V_19 = - V_109 ;
break;
}
V_4 -> V_209 = V_187 ? - 1 : 0 ;
{
struct V_2 * V_210 = V_31 -> V_2 ;
struct V_33 * V_34 = F_19 ( V_210 ) ;
V_34 -> V_37 . V_144 = V_187 ? V_211 :
V_145 ;
}
F_21 ( V_4 , V_147 ,
L_17 ,
V_4 -> V_36 , V_4 -> V_209 ) ;
break;
case V_212 :
if ( ( V_187 != 0 ) && ( V_187 != 1 ) ) {
V_19 = - V_109 ;
break;
}
V_4 -> V_213 = V_187 ? - 1 : 0 ;
F_21 ( V_4 , V_147 ,
L_18 ,
V_4 -> V_36 , V_4 -> V_213 ) ;
break;
case V_204 :
V_4 -> V_125 = V_187 ;
F_21 ( V_4 , V_147 , L_15 ,
V_4 -> V_36 , V_4 -> V_125 ) ;
break;
case V_214 :
V_4 -> V_215 = F_85 ( V_187 ) ;
F_21 ( V_4 , V_147 ,
L_19 ,
V_4 -> V_36 , V_4 -> V_215 ) ;
break;
default:
V_19 = - V_205 ;
break;
}
return V_19 ;
}
static int F_86 ( struct V_14 * V_2 , int V_216 , int V_203 ,
char V_191 * V_217 , unsigned int V_218 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
struct V_30 * V_31 ;
int V_187 ;
int V_19 ;
if ( V_216 != V_219 )
return V_220 . V_221 ( V_3 , V_216 , V_203 , V_217 , V_218 ) ;
if ( V_218 < sizeof( int ) )
return - V_109 ;
if ( F_79 ( V_187 , ( int V_191 * ) V_217 ) )
return - V_190 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_70 == 0 ) &&
( V_4 -> V_106 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_154;
V_19 = F_83 ( V_3 , V_44 , V_203 , V_187 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_84 ( V_3 , V_4 , V_203 , V_187 ) ;
V_19 = 0 ;
V_154:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
int V_203 , int * V_187 )
{
int V_19 = 0 ;
switch ( V_203 ) {
case V_204 :
* V_187 = V_44 -> V_125 ;
F_21 ( V_44 , V_147 , L_20 ,
V_44 -> V_36 , V_44 -> V_125 ) ;
break;
default:
V_19 = - V_205 ;
break;
}
return V_19 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_203 , int * V_187 )
{
int V_19 = 0 ;
switch ( V_203 ) {
case V_206 :
* V_187 = V_4 -> V_207 ;
F_21 ( V_4 , V_147 ,
L_21 , V_4 -> V_36 , * V_187 ) ;
break;
case V_208 :
* V_187 = V_4 -> V_209 ;
F_21 ( V_4 , V_147 ,
L_22 , V_4 -> V_36 , * V_187 ) ;
break;
case V_212 :
* V_187 = V_4 -> V_213 ;
F_21 ( V_4 , V_147 ,
L_23 , V_4 -> V_36 , * V_187 ) ;
break;
case V_204 :
* V_187 = V_4 -> V_125 ;
F_21 ( V_4 , V_147 , L_24 ,
V_4 -> V_36 , * V_187 ) ;
break;
case V_214 :
* V_187 = ( int ) F_89 ( V_4 -> V_215 ) ;
F_21 ( V_4 , V_147 ,
L_25 , V_4 -> V_36 , * V_187 ) ;
break;
default:
V_19 = - V_205 ;
}
return V_19 ;
}
static int F_90 ( struct V_14 * V_2 , int V_216 ,
int V_203 , char V_191 * V_217 , int V_191 * V_218 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_43 * V_44 ;
int V_187 , V_17 ;
int V_19 ;
struct V_30 * V_31 ;
if ( V_216 != V_219 )
return V_220 . V_222 ( V_3 , V_216 , V_203 , V_217 , V_218 ) ;
if ( F_79 ( V_17 , ( int V_191 * ) V_218 ) )
return - V_190 ;
V_17 = F_91 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_109 ;
V_19 = - V_46 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_49 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_70 == 0 ) &&
( V_4 -> V_106 == 0 ) ) {
V_19 = - V_49 ;
V_44 = F_26 ( V_31 -> V_50 ) ;
if ( V_44 == NULL )
goto V_154;
V_19 = F_87 ( V_3 , V_44 , V_203 , & V_187 ) ;
F_3 ( V_31 -> V_50 ) ;
} else
V_19 = F_88 ( V_3 , V_4 , V_203 , & V_187 ) ;
V_19 = - V_190 ;
if ( F_78 ( V_17 , ( int V_191 * ) V_218 ) )
goto V_154;
if ( F_77 ( ( void V_191 * ) V_217 , & V_187 , V_17 ) )
goto V_154;
V_19 = 0 ;
V_154:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_92 ( struct V_78 * V_78 , struct V_223 * V_224 )
{
for (; ; ) {
V_224 -> V_44 = F_93 ( V_78 , V_224 -> V_225 ) ;
V_224 -> V_225 ++ ;
if ( V_224 -> V_44 == NULL )
break;
if ( V_224 -> V_44 -> V_155 < 3 )
break;
}
}
static void F_94 ( struct V_78 * V_78 , struct V_223 * V_224 )
{
V_224 -> V_4 = F_95 ( V_224 -> V_44 , V_224 -> V_226 ) ;
V_224 -> V_226 ++ ;
if ( V_224 -> V_4 == NULL ) {
V_224 -> V_226 = 0 ;
F_92 ( V_78 , V_224 ) ;
}
}
static void * F_96 ( struct V_93 * V_40 , T_4 * V_227 )
{
struct V_223 * V_224 = V_228 ;
T_4 V_229 = * V_227 ;
struct V_78 * V_78 ;
if ( ! V_229 )
goto V_6;
F_4 ( V_40 -> V_62 == NULL ) ;
V_224 = V_40 -> V_62 ;
V_78 = F_97 ( V_40 ) ;
if ( V_224 -> V_44 == NULL )
F_92 ( V_78 , V_224 ) ;
else
F_94 ( V_78 , V_224 ) ;
if ( ( V_224 -> V_44 == NULL ) && ( V_224 -> V_4 == NULL ) )
V_224 = NULL ;
V_6:
return V_224 ;
}
static void * F_98 ( struct V_93 * V_40 , void * V_230 , T_4 * V_229 )
{
( * V_229 ) ++ ;
return NULL ;
}
static void F_99 ( struct V_93 * V_231 , void * V_230 )
{
}
static void F_100 ( struct V_93 * V_40 , void * V_230 )
{
struct V_43 * V_44 = V_230 ;
F_54 ( V_40 , L_26 ,
V_44 -> V_36 ,
( V_44 == V_44 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_101 ( & V_44 -> V_232 ) - 1 ) ;
F_54 ( V_40 , L_27 ,
V_44 -> V_125 ,
( unsigned long long ) V_44 -> V_38 . V_177 ,
( unsigned long long ) V_44 -> V_38 . V_178 ,
( unsigned long long ) V_44 -> V_38 . V_179 ,
( unsigned long long ) V_44 -> V_38 . V_180 ,
( unsigned long long ) V_44 -> V_38 . V_181 ,
( unsigned long long ) V_44 -> V_38 . V_39 ) ;
}
static void F_102 ( struct V_93 * V_40 , void * V_230 )
{
struct V_1 * V_4 = V_230 ;
struct V_43 * V_44 = V_4 -> V_44 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
T_3 V_233 = 0 ;
T_5 V_234 = 0 ;
if ( V_44 -> V_2 ) {
struct V_151 * V_152 = F_71 ( V_44 -> V_2 ) ;
V_233 = F_103 ( V_152 -> V_235 ) ;
V_234 = F_104 ( V_152 -> V_236 ) ;
}
F_54 ( V_40 , L_28
L_29 ,
V_4 -> V_36 , V_233 , V_234 ,
V_44 -> V_104 ,
V_4 -> V_70 ,
V_44 -> V_105 ,
V_4 -> V_106 ,
V_31 -> V_2 -> V_21 ,
( V_4 == V_31 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_54 ( V_40 , L_30 ,
V_4 -> V_128 , V_4 -> V_129 ,
V_4 -> V_207 ? 'R' : '-' ,
V_4 -> V_209 ? 'S' : '-' ,
V_4 -> V_213 ? L_31 : L_32 ,
V_4 -> V_125 ,
F_89 ( V_4 -> V_215 ) ) ;
F_54 ( V_40 , L_33 ,
V_4 -> V_237 , V_4 -> V_238 ,
( unsigned long long ) V_4 -> V_38 . V_177 ,
( unsigned long long ) V_4 -> V_38 . V_178 ,
( unsigned long long ) V_4 -> V_38 . V_179 ,
( unsigned long long ) V_4 -> V_38 . V_180 ,
( unsigned long long ) V_4 -> V_38 . V_181 ,
( unsigned long long ) V_4 -> V_38 . V_39 ) ;
if ( V_34 )
F_54 ( V_40 , L_4 , F_55 ( & V_34 -> V_37 ) ) ;
}
static int F_105 ( struct V_93 * V_40 , void * V_230 )
{
struct V_223 * V_224 = V_230 ;
if ( V_230 == V_228 ) {
F_106 ( V_40 , L_34 V_239 L_35 ) ;
F_106 ( V_40 , L_36 ) ;
F_106 ( V_40 , L_37 ) ;
F_106 ( V_40 , L_38
L_39 ) ;
F_106 ( V_40 , L_40 ) ;
F_106 ( V_40 , L_41 ) ;
goto V_6;
}
if ( V_224 -> V_4 == NULL )
F_100 ( V_40 , V_224 -> V_44 ) ;
else
F_102 ( V_40 , V_224 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_107 ( struct V_240 * V_240 , struct V_241 * V_241 )
{
return F_108 ( V_240 , V_241 , & V_242 ,
sizeof( struct V_223 ) ) ;
}
static T_6 int F_109 ( struct V_78 * V_78 )
{
struct V_243 * V_244 ;
int V_19 = 0 ;
V_244 = F_110 ( V_78 , L_42 , V_245 , & V_246 ) ;
if ( ! V_244 ) {
V_19 = - V_55 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_111 ( struct V_78 * V_78 )
{
F_112 ( V_78 , L_42 ) ;
}
static int T_8 F_113 ( void )
{
int V_19 ;
V_19 = F_114 ( & V_247 ) ;
if ( V_19 )
goto V_6;
V_19 = F_115 ( & V_80 , 0 ) ;
if ( V_19 )
goto V_248;
V_19 = F_116 ( V_87 , & V_249 ) ;
if ( V_19 )
goto V_250;
#ifdef F_117
V_19 = F_118 ( V_251 , & V_252 ) ;
if ( V_19 )
goto V_253;
#endif
F_119 ( L_43 , V_239 ) ;
V_6:
return V_19 ;
#ifdef F_117
V_253:
F_120 ( V_87 ) ;
#endif
V_250:
F_121 ( & V_80 ) ;
V_248:
F_122 ( & V_247 ) ;
goto V_6;
}
static void T_9 F_123 ( void )
{
#ifdef F_117
F_124 ( V_251 ) ;
#endif
F_120 ( V_87 ) ;
F_121 ( & V_80 ) ;
F_122 ( & V_247 ) ;
}
