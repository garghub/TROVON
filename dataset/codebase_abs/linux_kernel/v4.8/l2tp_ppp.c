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
static int F_8 ( struct V_12 * V_2 , struct V_13 * V_14 ,
T_1 V_15 , int V_16 )
{
int V_17 ;
struct V_9 * V_10 ;
struct V_2 * V_3 = V_2 -> V_3 ;
V_17 = - V_18 ;
if ( V_3 -> V_19 & V_20 )
goto V_21;
V_17 = 0 ;
V_10 = F_9 ( V_3 , V_16 & ~ V_22 ,
V_16 & V_22 , & V_17 ) ;
if ( ! V_10 )
goto V_21;
if ( V_15 > V_10 -> V_15 )
V_15 = V_10 -> V_15 ;
else if ( V_15 < V_10 -> V_15 )
V_14 -> V_23 |= V_24 ;
V_17 = F_10 ( V_10 , 0 , V_14 , V_15 ) ;
if ( F_11 ( V_17 == 0 ) )
V_17 = V_15 ;
F_12 ( V_10 ) ;
V_21:
return V_17 ;
}
static void F_13 ( struct V_1 * V_4 , struct V_9 * V_10 , int V_25 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_2 * V_3 = NULL ;
V_3 = V_27 -> V_2 ;
if ( V_3 == NULL )
goto V_28;
if ( V_3 -> V_19 & V_20 ) {
struct V_29 * V_30 ;
F_15 ( V_4 , V_31 ,
L_1 ,
V_4 -> V_32 , V_25 ) ;
V_30 = F_16 ( V_3 ) ;
F_17 ( & V_30 -> V_33 , V_10 ) ;
} else {
F_15 ( V_4 , V_31 ,
L_2 ,
V_4 -> V_32 , V_25 ) ;
if ( F_18 ( V_3 , V_10 ) < 0 ) {
F_19 ( & V_4 -> V_34 . V_35 ) ;
F_12 ( V_10 ) ;
}
}
return;
V_28:
F_20 ( V_4 , V_31 , L_3 , V_4 -> V_32 ) ;
F_12 ( V_10 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 -> V_2 )
F_2 ( V_27 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 -> V_2 )
F_3 ( V_27 -> V_2 ) ;
}
static int F_23 ( struct V_12 * V_2 , struct V_13 * V_36 ,
T_1 V_37 )
{
static const unsigned char V_38 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_41 ;
error = - V_42 ;
if ( F_24 ( V_3 , V_43 ) || ! ( V_3 -> V_19 & V_44 ) )
goto error;
error = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_27 = F_14 ( V_4 ) ;
V_40 = F_25 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_47;
V_41 = ( V_40 -> V_48 == V_49 ) ? sizeof( struct V_50 ) : 0 ;
error = - V_51 ;
V_10 = F_26 ( V_3 , V_52 + sizeof( struct V_53 ) +
V_41 + V_4 -> V_54 +
sizeof( V_38 ) + V_37 ,
0 , V_55 ) ;
if ( ! V_10 )
goto V_56;
F_27 ( V_10 , V_52 ) ;
F_28 ( V_10 ) ;
F_27 ( V_10 , sizeof( struct V_53 ) ) ;
F_29 ( V_10 ) ;
F_27 ( V_10 , V_41 ) ;
V_10 -> V_11 [ 0 ] = V_38 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_38 [ 1 ] ;
F_30 ( V_10 , 2 ) ;
error = F_31 ( F_30 ( V_10 , V_37 ) , V_36 , V_37 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_56;
}
F_32 () ;
F_33 ( V_4 , V_10 , V_4 -> V_54 ) ;
F_34 () ;
F_3 ( V_27 -> V_46 ) ;
F_3 ( V_3 ) ;
return V_37 ;
V_56:
F_3 ( V_27 -> V_46 ) ;
V_47:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_35 ( struct V_57 * V_33 , struct V_9 * V_10 )
{
static const T_2 V_38 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_33 -> V_58 ;
struct V_2 * V_59 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_41 , V_60 ;
if ( F_24 ( V_3 , V_43 ) || ! ( V_3 -> V_19 & V_44 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_27 = F_14 ( V_4 ) ;
V_59 = V_27 -> V_46 ;
if ( V_59 == NULL )
goto V_61;
V_40 = F_25 ( V_59 ) ;
if ( V_40 == NULL )
goto V_61;
V_41 = ( V_40 -> V_48 == V_49 ) ? sizeof( struct V_50 ) : 0 ;
V_60 = V_52 +
sizeof( struct V_53 ) +
V_41 +
V_4 -> V_54 +
sizeof( V_38 ) ;
if ( F_36 ( V_10 , V_60 ) )
goto V_62;
F_37 ( V_10 , sizeof( V_38 ) ) ;
V_10 -> V_11 [ 0 ] = V_38 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_38 [ 1 ] ;
F_32 () ;
F_33 ( V_4 , V_10 , V_4 -> V_54 ) ;
F_34 () ;
F_3 ( V_59 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_62:
F_3 ( V_59 ) ;
V_61:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_38 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_27 -> V_2 ;
struct V_12 * V_2 = V_3 -> V_63 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_2 ) {
F_39 ( V_2 , 2 ) ;
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
static int F_43 ( struct V_12 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_45 ;
F_44 ( V_3 ) ;
if ( F_24 ( V_3 , V_43 ) != 0 )
goto error;
F_45 ( V_3 ) ;
V_3 -> V_19 = V_64 ;
F_46 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_49 ( & V_3 -> V_65 ) ;
F_49 ( & V_3 -> V_66 ) ;
F_50 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_50 ( V_3 ) ;
return error ;
}
static int F_51 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_67 ;
V_67 = F_52 ( V_3 , V_10 ) ;
if ( V_67 )
F_12 ( V_10 ) ;
return V_68 ;
}
static int F_53 ( struct V_69 * V_69 , struct V_12 * V_2 , int V_70 )
{
int error = - V_51 ;
struct V_2 * V_3 ;
V_3 = F_54 ( V_69 , V_71 , V_55 , & V_72 , V_70 ) ;
if ( ! V_3 )
goto V_6;
F_55 ( V_2 , V_3 ) ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = & V_76 ;
V_3 -> V_77 = F_51 ;
V_3 -> V_78 = V_79 ;
V_3 -> V_80 = V_71 ;
V_3 -> V_19 = V_81 ;
V_3 -> V_82 = V_83 ;
V_3 -> V_84 = F_41 ;
error = 0 ;
V_6:
return error ;
}
static void F_56 ( struct V_85 * V_36 , void * V_86 )
{
struct V_1 * V_4 = V_86 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 ) {
struct V_29 * V_30 = F_16 ( V_27 -> V_2 ) ;
if ( V_30 )
F_57 ( V_36 , L_4 , F_58 ( & V_30 -> V_33 ) ) ;
}
}
static int F_59 ( struct V_12 * V_2 , struct V_87 * V_88 ,
int V_89 , int V_16 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_90 * V_91 = (struct V_90 * ) V_88 ;
struct V_29 * V_30 = F_16 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
struct V_92 * V_93 ;
struct V_94 V_95 = { 0 , } ;
int error = 0 ;
T_3 V_96 , V_97 ;
T_3 V_98 , V_99 ;
int V_100 = 2 ;
int V_101 ;
F_44 ( V_3 ) ;
error = - V_102 ;
if ( V_91 -> V_103 != V_79 )
goto V_21;
error = - V_104 ;
if ( V_3 -> V_19 & V_44 )
goto V_21;
error = - V_105 ;
if ( V_3 -> V_5 )
goto V_21;
V_97 = 0 ;
if ( V_89 == sizeof( struct V_90 ) ) {
V_101 = V_91 -> V_106 . V_101 ;
V_96 = V_91 -> V_106 . V_107 ;
V_97 = V_91 -> V_106 . V_108 ;
V_98 = V_91 -> V_106 . V_109 ;
V_99 = V_91 -> V_106 . V_110 ;
} else if ( V_89 == sizeof( struct V_111 ) ) {
struct V_111 * V_112 =
(struct V_111 * ) V_91 ;
V_100 = 3 ;
V_101 = V_112 -> V_106 . V_101 ;
V_96 = V_112 -> V_106 . V_107 ;
V_97 = V_112 -> V_106 . V_108 ;
V_98 = V_112 -> V_106 . V_109 ;
V_99 = V_112 -> V_106 . V_110 ;
} else if ( V_89 == sizeof( struct V_113 ) ) {
struct V_113 * V_114 =
(struct V_113 * ) V_91 ;
V_101 = V_114 -> V_106 . V_101 ;
V_96 = V_114 -> V_106 . V_107 ;
V_97 = V_114 -> V_106 . V_108 ;
V_98 = V_114 -> V_106 . V_109 ;
V_99 = V_114 -> V_106 . V_110 ;
} else if ( V_89 == sizeof( struct V_115 ) ) {
struct V_115 * V_114 =
(struct V_115 * ) V_91 ;
V_100 = 3 ;
V_101 = V_114 -> V_106 . V_101 ;
V_96 = V_114 -> V_106 . V_107 ;
V_97 = V_114 -> V_106 . V_108 ;
V_98 = V_114 -> V_106 . V_109 ;
V_99 = V_114 -> V_106 . V_110 ;
} else {
error = - V_102 ;
goto V_21;
}
error = - V_102 ;
if ( V_96 == 0 )
goto V_21;
V_40 = F_60 ( F_61 ( V_3 ) , V_96 ) ;
if ( ( V_98 == 0 ) && ( V_99 == 0 ) ) {
if ( V_40 == NULL ) {
struct V_116 V_117 = {
. V_48 = V_49 ,
. V_118 = 0 ,
} ;
error = F_62 ( F_61 ( V_3 ) , V_101 , V_100 , V_96 , V_97 , & V_117 , & V_40 ) ;
if ( error < 0 )
goto V_21;
}
} else {
error = - V_119 ;
if ( V_40 == NULL )
goto V_21;
if ( V_40 -> V_2 == NULL )
goto V_21;
}
if ( V_40 -> V_120 == NULL )
V_40 -> V_120 = F_5 ;
if ( V_40 -> V_97 == 0 )
V_40 -> V_97 = V_97 ;
V_4 = F_63 ( F_61 ( V_3 ) , V_40 , V_98 ) ;
if ( V_4 == NULL ) {
V_95 . V_121 = V_95 . V_122 = 1500 - V_123 ;
V_4 = F_64 ( sizeof( struct V_26 ) ,
V_40 , V_98 ,
V_99 , & V_95 ) ;
if ( V_4 == NULL ) {
error = - V_51 ;
goto V_21;
}
} else {
V_27 = F_14 ( V_4 ) ;
error = - V_124 ;
if ( V_27 -> V_2 != NULL )
goto V_21;
if ( V_27 -> V_46 != V_40 -> V_2 )
goto V_21;
}
V_27 = F_14 ( V_4 ) ;
V_27 -> V_125 = V_126 -> V_127 ;
V_27 -> V_2 = V_3 ;
V_27 -> V_46 = V_40 -> V_2 ;
V_4 -> V_128 = F_13 ;
V_4 -> V_129 = F_38 ;
#if F_65 ( V_130 ) || F_65 ( V_131 )
V_4 -> V_132 = F_56 ;
#endif
V_4 -> V_133 = F_21 ;
V_4 -> V_134 = F_22 ;
V_93 = F_66 ( V_40 -> V_2 ) ;
if ( V_93 != NULL ) {
T_3 V_135 = F_67 ( V_93 ) ;
if ( V_135 != 0 )
V_4 -> V_121 = V_4 -> V_122 = V_135 -
V_123 ;
F_68 ( V_93 ) ;
}
if ( ( V_4 -> V_98 == 0 ) &&
( V_4 -> V_99 == 0 ) ) {
error = 0 ;
goto V_136;
}
V_30 -> V_33 . V_137 = V_138 ;
V_30 -> V_33 . V_58 = V_3 ;
V_30 -> V_33 . V_75 = & V_139 ;
V_30 -> V_33 . V_121 = V_4 -> V_121 ;
error = F_69 ( F_61 ( V_3 ) , & V_30 -> V_33 ) ;
if ( error )
goto V_21;
V_136:
V_3 -> V_5 = V_4 ;
V_3 -> V_19 = V_44 ;
F_20 ( V_4 , V_140 , L_5 ,
V_4 -> V_32 ) ;
V_21:
F_50 ( V_3 ) ;
return error ;
}
static int F_70 ( struct V_69 * V_69 , T_3 V_96 , T_3 V_98 , T_3 V_99 , struct V_94 * V_95 )
{
int error ;
struct V_39 * V_40 ;
struct V_1 * V_4 ;
struct V_26 * V_27 ;
V_40 = F_60 ( V_69 , V_96 ) ;
error = - V_119 ;
if ( V_40 == NULL )
goto V_6;
if ( V_40 -> V_2 == NULL )
goto V_6;
error = - V_124 ;
V_4 = F_63 ( V_69 , V_40 , V_98 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_95 -> V_121 == 0 )
V_95 -> V_121 = 1500 - V_123 ;
if ( V_95 -> V_122 == 0 )
V_95 -> V_122 = V_95 -> V_121 ;
error = - V_51 ;
V_4 = F_64 ( sizeof( struct V_26 ) ,
V_40 , V_98 ,
V_99 , V_95 ) ;
if ( V_4 == NULL )
goto V_6;
V_27 = F_14 ( V_4 ) ;
V_27 -> V_46 = V_40 -> V_2 ;
F_20 ( V_4 , V_140 , L_5 ,
V_4 -> V_32 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_71 ( struct V_12 * V_2 , struct V_87 * V_141 ,
int * V_142 , int V_143 )
{
int V_15 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_144 * V_145 ;
struct V_26 * V_146 ;
error = - V_42 ;
if ( V_3 == NULL )
goto V_21;
if ( ! ( V_3 -> V_19 & V_44 ) )
goto V_21;
error = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_146 = F_14 ( V_4 ) ;
V_40 = F_25 ( V_146 -> V_46 ) ;
if ( V_40 == NULL )
goto V_147;
V_145 = F_72 ( V_40 -> V_2 ) ;
if ( ( V_40 -> V_148 == 2 ) && ( V_40 -> V_2 -> V_80 == V_149 ) ) {
struct V_90 V_91 ;
V_15 = sizeof( V_91 ) ;
memset ( & V_91 , 0 , V_15 ) ;
V_91 . V_150 = V_151 ;
V_91 . V_103 = V_79 ;
V_91 . V_106 . V_101 = V_40 -> V_101 ;
V_91 . V_106 . V_127 = V_146 -> V_125 ;
V_91 . V_106 . V_107 = V_40 -> V_96 ;
V_91 . V_106 . V_108 = V_40 -> V_97 ;
V_91 . V_106 . V_109 = V_4 -> V_98 ;
V_91 . V_106 . V_110 = V_4 -> V_99 ;
V_91 . V_106 . V_152 . V_153 = V_149 ;
V_91 . V_106 . V_152 . V_154 = V_145 -> V_155 ;
V_91 . V_106 . V_152 . V_156 . V_157 = V_145 -> V_158 ;
memcpy ( V_141 , & V_91 , V_15 ) ;
#if F_73 ( V_159 )
} else if ( ( V_40 -> V_148 == 2 ) &&
( V_40 -> V_2 -> V_80 == V_160 ) ) {
struct V_113 V_91 ;
V_15 = sizeof( V_91 ) ;
memset ( & V_91 , 0 , V_15 ) ;
V_91 . V_150 = V_151 ;
V_91 . V_103 = V_79 ;
V_91 . V_106 . V_101 = V_40 -> V_101 ;
V_91 . V_106 . V_127 = V_146 -> V_125 ;
V_91 . V_106 . V_107 = V_40 -> V_96 ;
V_91 . V_106 . V_108 = V_40 -> V_97 ;
V_91 . V_106 . V_109 = V_4 -> V_98 ;
V_91 . V_106 . V_110 = V_4 -> V_99 ;
V_91 . V_106 . V_152 . V_161 = V_160 ;
V_91 . V_106 . V_152 . V_162 = V_145 -> V_155 ;
memcpy ( & V_91 . V_106 . V_152 . V_163 , & V_40 -> V_2 -> V_164 ,
sizeof( V_40 -> V_2 -> V_164 ) ) ;
memcpy ( V_141 , & V_91 , V_15 ) ;
} else if ( ( V_40 -> V_148 == 3 ) &&
( V_40 -> V_2 -> V_80 == V_160 ) ) {
struct V_115 V_91 ;
V_15 = sizeof( V_91 ) ;
memset ( & V_91 , 0 , V_15 ) ;
V_91 . V_150 = V_151 ;
V_91 . V_103 = V_79 ;
V_91 . V_106 . V_101 = V_40 -> V_101 ;
V_91 . V_106 . V_127 = V_146 -> V_125 ;
V_91 . V_106 . V_107 = V_40 -> V_96 ;
V_91 . V_106 . V_108 = V_40 -> V_97 ;
V_91 . V_106 . V_109 = V_4 -> V_98 ;
V_91 . V_106 . V_110 = V_4 -> V_99 ;
V_91 . V_106 . V_152 . V_161 = V_160 ;
V_91 . V_106 . V_152 . V_162 = V_145 -> V_155 ;
memcpy ( & V_91 . V_106 . V_152 . V_163 , & V_40 -> V_2 -> V_164 ,
sizeof( V_40 -> V_2 -> V_164 ) ) ;
memcpy ( V_141 , & V_91 , V_15 ) ;
#endif
} else if ( V_40 -> V_148 == 3 ) {
struct V_111 V_91 ;
V_15 = sizeof( V_91 ) ;
memset ( & V_91 , 0 , V_15 ) ;
V_91 . V_150 = V_151 ;
V_91 . V_103 = V_79 ;
V_91 . V_106 . V_101 = V_40 -> V_101 ;
V_91 . V_106 . V_127 = V_146 -> V_125 ;
V_91 . V_106 . V_107 = V_40 -> V_96 ;
V_91 . V_106 . V_108 = V_40 -> V_97 ;
V_91 . V_106 . V_109 = V_4 -> V_98 ;
V_91 . V_106 . V_110 = V_4 -> V_99 ;
V_91 . V_106 . V_152 . V_153 = V_149 ;
V_91 . V_106 . V_152 . V_154 = V_145 -> V_155 ;
V_91 . V_106 . V_152 . V_156 . V_157 = V_145 -> V_158 ;
memcpy ( V_141 , & V_91 , V_15 ) ;
}
* V_142 = V_15 ;
error = 0 ;
F_3 ( V_146 -> V_46 ) ;
V_147:
F_3 ( V_3 ) ;
V_21:
return error ;
}
static void F_74 ( struct V_165 * V_166 ,
struct V_167 * V_34 )
{
V_166 -> V_168 = F_75 ( & V_34 -> V_168 ) ;
V_166 -> V_169 = F_75 ( & V_34 -> V_169 ) ;
V_166 -> V_170 = F_75 ( & V_34 -> V_170 ) ;
V_166 -> V_171 = F_75 ( & V_34 -> V_171 ) ;
V_166 -> V_172 = F_75 ( & V_34 -> V_172 ) ;
V_166 -> V_173 = F_75 ( & V_34 -> V_173 ) ;
V_166 -> V_174 = F_75 ( & V_34 -> V_174 ) ;
V_166 -> V_35 = F_75 ( & V_34 -> V_35 ) ;
}
static int F_76 ( struct V_1 * V_4 ,
unsigned int V_175 , unsigned long V_86 )
{
struct V_176 V_177 ;
int V_17 = 0 ;
struct V_2 * V_3 ;
int V_178 = ( int ) V_86 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_39 * V_40 = V_4 -> V_40 ;
struct V_165 V_34 ;
F_15 ( V_4 , V_140 ,
L_6 ,
V_4 -> V_32 , V_175 , V_86 ) ;
V_3 = V_27 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_175 ) {
case V_179 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_181 ;
if ( F_77 ( & V_177 , ( void V_182 * ) V_86 , sizeof( struct V_176 ) ) )
break;
V_177 . V_183 = V_4 -> V_121 ;
if ( F_78 ( ( void V_182 * ) V_86 , & V_177 , sizeof( struct V_176 ) ) )
break;
F_20 ( V_4 , V_140 , L_7 ,
V_4 -> V_32 , V_4 -> V_121 ) ;
V_17 = 0 ;
break;
case V_184 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_181 ;
if ( F_77 ( & V_177 , ( void V_182 * ) V_86 , sizeof( struct V_176 ) ) )
break;
V_4 -> V_121 = V_177 . V_183 ;
F_20 ( V_4 , V_140 , L_8 ,
V_4 -> V_32 , V_4 -> V_121 ) ;
V_17 = 0 ;
break;
case V_185 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_181 ;
if ( F_79 ( V_4 -> V_122 , ( int V_182 * ) V_86 ) )
break;
F_20 ( V_4 , V_140 , L_9 ,
V_4 -> V_32 , V_4 -> V_122 ) ;
V_17 = 0 ;
break;
case V_186 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_181 ;
if ( F_80 ( V_178 , ( int V_182 * ) V_86 ) )
break;
V_4 -> V_122 = V_178 ;
F_20 ( V_4 , V_140 , L_10 ,
V_4 -> V_32 , V_4 -> V_122 ) ;
V_17 = 0 ;
break;
case V_187 :
V_17 = - V_181 ;
if ( F_79 ( V_27 -> V_16 , ( int V_182 * ) V_86 ) )
break;
F_20 ( V_4 , V_140 , L_11 ,
V_4 -> V_32 , V_27 -> V_16 ) ;
V_17 = 0 ;
break;
case V_188 :
V_17 = - V_181 ;
if ( F_80 ( V_178 , ( int V_182 * ) V_86 ) )
break;
V_27 -> V_16 = V_178 ;
F_20 ( V_4 , V_140 , L_12 ,
V_4 -> V_32 , V_27 -> V_16 ) ;
V_17 = 0 ;
break;
case V_189 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_96 = V_40 -> V_96 ;
V_34 . V_98 = V_4 -> V_98 ;
F_74 ( & V_34 , & V_4 -> V_34 ) ;
if ( F_78 ( ( void V_182 * ) V_86 , & V_34 ,
sizeof( V_34 ) ) )
break;
F_20 ( V_4 , V_140 , L_13 ,
V_4 -> V_32 ) ;
V_17 = 0 ;
break;
default:
V_17 = - V_190 ;
break;
}
F_3 ( V_3 ) ;
return V_17 ;
}
static int F_81 ( struct V_39 * V_40 ,
unsigned int V_175 , unsigned long V_86 )
{
int V_17 = 0 ;
struct V_2 * V_3 ;
struct V_165 V_34 ;
F_15 ( V_40 , V_140 ,
L_14 ,
V_40 -> V_32 , V_175 , V_86 ) ;
V_3 = V_40 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_175 ) {
case V_189 :
V_17 = - V_180 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
if ( F_77 ( & V_34 , ( void V_182 * ) V_86 ,
sizeof( V_34 ) ) ) {
V_17 = - V_181 ;
break;
}
if ( V_34 . V_98 != 0 ) {
struct V_1 * V_4 =
F_63 ( F_61 ( V_3 ) , V_40 , V_34 . V_98 ) ;
if ( V_4 != NULL )
V_17 = F_76 ( V_4 , V_175 , V_86 ) ;
else
V_17 = - V_191 ;
break;
}
#ifdef F_82
V_34 . V_192 = ( V_3 -> V_193 [ 0 ] || V_3 -> V_193 [ 1 ] ) ? 1 : 0 ;
#endif
F_74 ( & V_34 , & V_40 -> V_34 ) ;
if ( F_78 ( ( void V_182 * ) V_86 , & V_34 , sizeof( V_34 ) ) ) {
V_17 = - V_181 ;
break;
}
F_20 ( V_40 , V_140 , L_13 ,
V_40 -> V_32 ) ;
V_17 = 0 ;
break;
default:
V_17 = - V_190 ;
break;
}
F_3 ( V_3 ) ;
return V_17 ;
}
static int F_83 ( struct V_12 * V_2 , unsigned int V_175 ,
unsigned long V_86 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_17 ;
if ( ! V_3 )
return 0 ;
V_17 = - V_45 ;
if ( F_24 ( V_3 , V_43 ) != 0 )
goto V_21;
V_17 = - V_42 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_19 & ( V_44 | V_20 ) ) ) )
goto V_21;
V_17 = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_27 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_98 == 0 ) &&
( V_4 -> V_99 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_25 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_147;
V_17 = F_81 ( V_40 , V_175 , V_86 ) ;
F_3 ( V_27 -> V_46 ) ;
goto V_147;
}
V_17 = F_76 ( V_4 , V_175 , V_86 ) ;
V_147:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int V_194 , int V_178 )
{
int V_17 = 0 ;
switch ( V_194 ) {
case V_195 :
V_40 -> V_118 = V_178 ;
F_20 ( V_40 , V_140 , L_15 ,
V_40 -> V_32 , V_40 -> V_118 ) ;
break;
default:
V_17 = - V_196 ;
break;
}
return V_17 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_194 , int V_178 )
{
int V_17 = 0 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
switch ( V_194 ) {
case V_197 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_17 = - V_102 ;
break;
}
V_4 -> V_198 = V_178 ? - 1 : 0 ;
F_20 ( V_4 , V_140 ,
L_16 ,
V_4 -> V_32 , V_4 -> V_198 ) ;
break;
case V_199 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_17 = - V_102 ;
break;
}
V_4 -> V_200 = V_178 ? - 1 : 0 ;
{
struct V_2 * V_201 = V_27 -> V_2 ;
struct V_29 * V_30 = F_16 ( V_201 ) ;
V_30 -> V_33 . V_137 = V_178 ? V_202 :
V_138 ;
}
F_86 ( V_4 , V_4 -> V_40 -> V_148 ) ;
F_20 ( V_4 , V_140 ,
L_17 ,
V_4 -> V_32 , V_4 -> V_200 ) ;
break;
case V_203 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_17 = - V_102 ;
break;
}
V_4 -> V_204 = V_178 ? - 1 : 0 ;
F_20 ( V_4 , V_140 ,
L_18 ,
V_4 -> V_32 , V_4 -> V_204 ) ;
break;
case V_195 :
V_4 -> V_118 = V_178 ;
F_20 ( V_4 , V_140 , L_15 ,
V_4 -> V_32 , V_4 -> V_118 ) ;
break;
case V_205 :
V_4 -> V_206 = F_87 ( V_178 ) ;
F_20 ( V_4 , V_140 ,
L_19 ,
V_4 -> V_32 , V_4 -> V_206 ) ;
break;
default:
V_17 = - V_196 ;
break;
}
return V_17 ;
}
static int F_88 ( struct V_12 * V_2 , int V_207 , int V_194 ,
char V_182 * V_208 , unsigned int V_209 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_178 ;
int V_17 ;
if ( V_207 != V_210 )
return - V_102 ;
if ( V_209 < sizeof( int ) )
return - V_102 ;
if ( F_80 ( V_178 , ( int V_182 * ) V_208 ) )
return - V_181 ;
V_17 = - V_42 ;
if ( V_3 -> V_5 == NULL )
goto V_21;
V_17 = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_27 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_98 == 0 ) &&
( V_4 -> V_99 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_25 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_147;
V_17 = F_84 ( V_3 , V_40 , V_194 , V_178 ) ;
F_3 ( V_27 -> V_46 ) ;
} else
V_17 = F_85 ( V_3 , V_4 , V_194 , V_178 ) ;
V_17 = 0 ;
V_147:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int V_194 , int * V_178 )
{
int V_17 = 0 ;
switch ( V_194 ) {
case V_195 :
* V_178 = V_40 -> V_118 ;
F_20 ( V_40 , V_140 , L_20 ,
V_40 -> V_32 , V_40 -> V_118 ) ;
break;
default:
V_17 = - V_196 ;
break;
}
return V_17 ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_194 , int * V_178 )
{
int V_17 = 0 ;
switch ( V_194 ) {
case V_197 :
* V_178 = V_4 -> V_198 ;
F_20 ( V_4 , V_140 ,
L_21 , V_4 -> V_32 , * V_178 ) ;
break;
case V_199 :
* V_178 = V_4 -> V_200 ;
F_20 ( V_4 , V_140 ,
L_22 , V_4 -> V_32 , * V_178 ) ;
break;
case V_203 :
* V_178 = V_4 -> V_204 ;
F_20 ( V_4 , V_140 ,
L_23 , V_4 -> V_32 , * V_178 ) ;
break;
case V_195 :
* V_178 = V_4 -> V_118 ;
F_20 ( V_4 , V_140 , L_24 ,
V_4 -> V_32 , * V_178 ) ;
break;
case V_205 :
* V_178 = ( int ) F_91 ( V_4 -> V_206 ) ;
F_20 ( V_4 , V_140 ,
L_25 , V_4 -> V_32 , * V_178 ) ;
break;
default:
V_17 = - V_196 ;
}
return V_17 ;
}
static int F_92 ( struct V_12 * V_2 , int V_207 , int V_194 ,
char V_182 * V_208 , int V_182 * V_209 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
int V_178 , V_15 ;
int V_17 ;
struct V_26 * V_27 ;
if ( V_207 != V_210 )
return - V_102 ;
if ( F_80 ( V_15 , V_209 ) )
return - V_181 ;
V_15 = F_93 (unsigned int, len, sizeof(int)) ;
if ( V_15 < 0 )
return - V_102 ;
V_17 = - V_42 ;
if ( V_3 -> V_5 == NULL )
goto V_21;
V_17 = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_27 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_98 == 0 ) &&
( V_4 -> V_99 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_25 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_147;
V_17 = F_89 ( V_3 , V_40 , V_194 , & V_178 ) ;
F_3 ( V_27 -> V_46 ) ;
} else
V_17 = F_90 ( V_3 , V_4 , V_194 , & V_178 ) ;
V_17 = - V_181 ;
if ( F_79 ( V_15 , V_209 ) )
goto V_147;
if ( F_78 ( ( void V_182 * ) V_208 , & V_178 , V_15 ) )
goto V_147;
V_17 = 0 ;
V_147:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static void F_94 ( struct V_69 * V_69 , struct V_211 * V_212 )
{
for (; ; ) {
V_212 -> V_40 = F_95 ( V_69 , V_212 -> V_213 ) ;
V_212 -> V_213 ++ ;
if ( V_212 -> V_40 == NULL )
break;
if ( V_212 -> V_40 -> V_148 < 3 )
break;
}
}
static void F_96 ( struct V_69 * V_69 , struct V_211 * V_212 )
{
V_212 -> V_4 = F_97 ( V_212 -> V_40 , V_212 -> V_214 ) ;
V_212 -> V_214 ++ ;
if ( V_212 -> V_4 == NULL ) {
V_212 -> V_214 = 0 ;
F_94 ( V_69 , V_212 ) ;
}
}
static void * F_98 ( struct V_85 * V_36 , T_4 * V_215 )
{
struct V_211 * V_212 = V_216 ;
T_4 V_217 = * V_215 ;
struct V_69 * V_69 ;
if ( ! V_217 )
goto V_6;
F_4 ( V_36 -> V_58 == NULL ) ;
V_212 = V_36 -> V_58 ;
V_69 = F_99 ( V_36 ) ;
if ( V_212 -> V_40 == NULL )
F_94 ( V_69 , V_212 ) ;
else
F_96 ( V_69 , V_212 ) ;
if ( ( V_212 -> V_40 == NULL ) && ( V_212 -> V_4 == NULL ) )
V_212 = NULL ;
V_6:
return V_212 ;
}
static void * F_100 ( struct V_85 * V_36 , void * V_218 , T_4 * V_217 )
{
( * V_217 ) ++ ;
return NULL ;
}
static void F_101 ( struct V_85 * V_219 , void * V_218 )
{
}
static void F_102 ( struct V_85 * V_36 , void * V_218 )
{
struct V_39 * V_40 = V_218 ;
F_57 ( V_36 , L_26 ,
V_40 -> V_32 ,
( V_40 == V_40 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_103 ( & V_40 -> V_220 ) - 1 ) ;
F_57 ( V_36 , L_27 ,
V_40 -> V_118 ,
F_75 ( & V_40 -> V_34 . V_168 ) ,
F_75 ( & V_40 -> V_34 . V_169 ) ,
F_75 ( & V_40 -> V_34 . V_170 ) ,
F_75 ( & V_40 -> V_34 . V_171 ) ,
F_75 ( & V_40 -> V_34 . V_172 ) ,
F_75 ( & V_40 -> V_34 . V_35 ) ) ;
}
static void F_104 ( struct V_85 * V_36 , void * V_218 )
{
struct V_1 * V_4 = V_218 ;
struct V_39 * V_40 = V_4 -> V_40 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_29 * V_30 = F_16 ( V_27 -> V_2 ) ;
T_3 V_221 = 0 ;
T_5 V_222 = 0 ;
if ( V_40 -> V_2 ) {
struct V_144 * V_145 = F_72 ( V_40 -> V_2 ) ;
V_221 = F_105 ( V_145 -> V_223 ) ;
V_222 = F_106 ( V_145 -> V_224 ) ;
}
F_57 ( V_36 , L_28
L_29 ,
V_4 -> V_32 , V_221 , V_222 ,
V_40 -> V_96 ,
V_4 -> V_98 ,
V_40 -> V_97 ,
V_4 -> V_99 ,
V_27 -> V_2 -> V_19 ,
( V_4 == V_27 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_57 ( V_36 , L_30 ,
V_4 -> V_121 , V_4 -> V_122 ,
V_4 -> V_198 ? 'R' : '-' ,
V_4 -> V_200 ? 'S' : '-' ,
V_4 -> V_204 ? L_31 : L_32 ,
V_4 -> V_118 ,
F_91 ( V_4 -> V_206 ) ) ;
F_57 ( V_36 , L_33 ,
V_4 -> V_225 , V_4 -> V_226 ,
F_75 ( & V_4 -> V_34 . V_168 ) ,
F_75 ( & V_4 -> V_34 . V_169 ) ,
F_75 ( & V_4 -> V_34 . V_170 ) ,
F_75 ( & V_4 -> V_34 . V_171 ) ,
F_75 ( & V_4 -> V_34 . V_172 ) ,
F_75 ( & V_4 -> V_34 . V_35 ) ) ;
if ( V_30 )
F_57 ( V_36 , L_4 , F_58 ( & V_30 -> V_33 ) ) ;
}
static int F_107 ( struct V_85 * V_36 , void * V_218 )
{
struct V_211 * V_212 = V_218 ;
if ( V_218 == V_216 ) {
F_108 ( V_36 , L_34 V_227 L_35 ) ;
F_108 ( V_36 , L_36 ) ;
F_108 ( V_36 , L_37 ) ;
F_108 ( V_36 , L_38
L_39 ) ;
F_108 ( V_36 , L_40 ) ;
F_108 ( V_36 , L_41 ) ;
goto V_6;
}
if ( V_212 -> V_4 == NULL )
F_102 ( V_36 , V_212 -> V_40 ) ;
else
F_104 ( V_36 , V_212 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_109 ( struct V_228 * V_228 , struct V_229 * V_229 )
{
return F_110 ( V_228 , V_229 , & V_230 ,
sizeof( struct V_211 ) ) ;
}
static T_6 int F_111 ( struct V_69 * V_69 )
{
struct V_231 * V_232 ;
int V_17 = 0 ;
V_232 = F_112 ( L_42 , V_233 , V_69 -> V_234 ,
& V_235 ) ;
if ( ! V_232 ) {
V_17 = - V_51 ;
goto V_6;
}
V_6:
return V_17 ;
}
static T_7 void F_113 ( struct V_69 * V_69 )
{
F_114 ( L_42 , V_69 -> V_234 ) ;
}
static int T_8 F_115 ( void )
{
int V_17 ;
V_17 = F_116 ( & V_236 ) ;
if ( V_17 )
goto V_6;
V_17 = F_117 ( & V_72 , 0 ) ;
if ( V_17 )
goto V_237;
V_17 = F_118 ( V_79 , & V_238 ) ;
if ( V_17 )
goto V_239;
#ifdef F_119
V_17 = F_120 ( V_240 , & V_241 ) ;
if ( V_17 )
goto V_242;
#endif
F_121 ( L_43 , V_227 ) ;
V_6:
return V_17 ;
#ifdef F_119
V_242:
F_122 ( V_79 ) ;
#endif
V_239:
F_123 ( & V_72 ) ;
V_237:
F_124 ( & V_236 ) ;
goto V_6;
}
static void T_9 F_125 ( void )
{
#ifdef F_119
F_126 ( V_240 ) ;
#endif
F_122 ( V_79 ) ;
F_123 ( & V_72 ) ;
F_124 ( & V_236 ) ;
}
