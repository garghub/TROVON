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
V_19 = 0 ;
V_10 = F_9 ( V_3 , V_18 & ~ V_24 ,
V_18 & V_24 , & V_19 ) ;
if ( ! V_10 )
goto V_23;
if ( V_17 > V_10 -> V_17 )
V_17 = V_10 -> V_17 ;
else if ( V_17 < V_10 -> V_17 )
V_16 -> V_25 |= V_26 ;
V_19 = F_10 ( V_10 , 0 , V_16 -> V_27 , V_17 ) ;
if ( F_11 ( V_19 == 0 ) )
V_19 = V_17 ;
F_12 ( V_10 ) ;
V_23:
return V_19 ;
}
static void F_13 ( struct V_1 * V_4 , struct V_9 * V_10 , int V_28 )
{
struct V_29 * V_30 = F_14 ( V_4 ) ;
struct V_2 * V_3 = NULL ;
V_3 = V_30 -> V_2 ;
if ( V_3 == NULL )
goto V_31;
if ( V_3 -> V_21 & V_22 ) {
struct V_32 * V_33 ;
F_15 ( V_4 , V_34 ,
L_1 ,
V_4 -> V_35 , V_28 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_33 = F_19 ( V_3 ) ;
F_20 ( & V_33 -> V_36 , V_10 ) ;
} else {
F_15 ( V_4 , V_34 ,
L_2 ,
V_4 -> V_35 , V_28 ) ;
if ( F_21 ( V_3 , V_10 ) < 0 ) {
F_22 ( & V_4 -> V_37 . V_38 ) ;
F_12 ( V_10 ) ;
}
}
return;
V_31:
F_23 ( V_4 , V_34 , L_3 , V_4 -> V_35 ) ;
F_12 ( V_10 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
struct V_29 * V_30 = F_14 ( V_4 ) ;
if ( V_30 -> V_2 )
F_2 ( V_30 -> V_2 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
struct V_29 * V_30 = F_14 ( V_4 ) ;
if ( V_30 -> V_2 )
F_3 ( V_30 -> V_2 ) ;
}
static int F_26 ( struct V_12 * V_13 , struct V_14 * V_2 , struct V_15 * V_39 ,
T_1 V_40 )
{
static const unsigned char V_41 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
struct V_29 * V_30 ;
int V_44 ;
error = - V_45 ;
if ( F_27 ( V_3 , V_46 ) || ! ( V_3 -> V_21 & V_47 ) )
goto error;
error = - V_48 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_30 = F_14 ( V_4 ) ;
V_43 = F_28 ( V_30 -> V_49 ) ;
if ( V_43 == NULL )
goto V_50;
V_44 = ( V_43 -> V_51 == V_52 ) ? sizeof( struct V_53 ) : 0 ;
error = - V_54 ;
V_10 = F_29 ( V_3 , V_55 + sizeof( struct V_56 ) +
V_44 + V_4 -> V_57 +
sizeof( V_41 ) + V_40 ,
0 , V_58 ) ;
if ( ! V_10 )
goto V_59;
F_30 ( V_10 , V_55 ) ;
F_31 ( V_10 ) ;
F_30 ( V_10 , sizeof( struct V_56 ) ) ;
F_32 ( V_10 ) ;
F_30 ( V_10 , V_44 ) ;
V_10 -> V_11 [ 0 ] = V_41 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_41 [ 1 ] ;
F_33 ( V_10 , 2 ) ;
error = F_34 ( F_33 ( V_10 , V_40 ) , V_39 -> V_27 ,
V_40 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_59;
}
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_57 ) ;
F_37 () ;
F_3 ( V_30 -> V_49 ) ;
F_3 ( V_3 ) ;
return V_40 ;
V_59:
F_3 ( V_30 -> V_49 ) ;
V_50:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_38 ( struct V_60 * V_36 , struct V_9 * V_10 )
{
static const T_2 V_41 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_36 -> V_61 ;
struct V_2 * V_62 ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
struct V_29 * V_30 ;
int V_44 , V_63 ;
if ( F_27 ( V_3 , V_46 ) || ! ( V_3 -> V_21 & V_47 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_30 = F_14 ( V_4 ) ;
V_62 = V_30 -> V_49 ;
if ( V_62 == NULL )
goto V_64;
V_43 = F_28 ( V_62 ) ;
if ( V_43 == NULL )
goto V_64;
V_44 = ( V_43 -> V_51 == V_52 ) ? sizeof( struct V_53 ) : 0 ;
V_63 = V_55 +
sizeof( struct V_56 ) +
V_44 +
V_4 -> V_57 +
sizeof( V_41 ) ;
if ( F_39 ( V_10 , V_63 ) )
goto V_65;
F_40 ( V_10 , sizeof( V_41 ) ) ;
V_10 -> V_11 [ 0 ] = V_41 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_41 [ 1 ] ;
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_57 ) ;
F_37 () ;
F_3 ( V_62 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_65:
F_3 ( V_62 ) ;
V_64:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_41 ( struct V_1 * V_4 )
{
struct V_29 * V_30 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_30 -> V_2 ;
struct V_14 * V_2 = V_3 -> V_66 ;
F_4 ( V_4 -> V_7 != V_8 ) ;
if ( V_2 ) {
F_42 ( V_2 , 2 ) ;
F_43 ( V_4 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
if ( V_4 ) {
V_3 -> V_5 = NULL ;
F_4 ( V_4 -> V_7 != V_8 ) ;
F_45 ( V_4 ) ;
}
}
static int F_46 ( struct V_14 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_48 ;
F_47 ( V_3 ) ;
if ( F_27 ( V_3 , V_46 ) != 0 )
goto error;
F_48 ( V_3 ) ;
V_3 -> V_21 = V_67 ;
F_49 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_50 ( V_4 ) ;
F_51 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_52 ( & V_3 -> V_68 ) ;
F_52 ( & V_3 -> V_69 ) ;
F_53 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_53 ( V_3 ) ;
return error ;
}
static int F_54 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_70 ;
V_70 = F_55 ( V_3 , V_10 ) ;
if ( V_70 )
F_12 ( V_10 ) ;
return V_71 ;
}
static int F_56 ( struct V_72 * V_72 , struct V_14 * V_2 )
{
int error = - V_54 ;
struct V_2 * V_3 ;
V_3 = F_57 ( V_72 , V_73 , V_58 , & V_74 ) ;
if ( ! V_3 )
goto V_6;
F_58 ( V_2 , V_3 ) ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = & V_78 ;
V_3 -> V_79 = F_54 ;
V_3 -> V_80 = V_81 ;
V_3 -> V_82 = V_73 ;
V_3 -> V_21 = V_83 ;
V_3 -> V_84 = V_85 ;
V_3 -> V_86 = F_44 ;
error = 0 ;
V_6:
return error ;
}
static void F_59 ( struct V_87 * V_39 , void * V_88 )
{
struct V_1 * V_4 = V_88 ;
struct V_29 * V_30 = F_14 ( V_4 ) ;
if ( V_30 ) {
struct V_32 * V_33 = F_19 ( V_30 -> V_2 ) ;
if ( V_33 )
F_60 ( V_39 , L_4 , F_61 ( & V_33 -> V_36 ) ) ;
}
}
static int F_62 ( struct V_14 * V_2 , struct V_89 * V_90 ,
int V_91 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_32 * V_33 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_42 * V_43 ;
struct V_29 * V_30 ;
struct V_94 * V_95 ;
struct V_96 V_97 = { 0 , } ;
int error = 0 ;
T_3 V_98 , V_99 ;
T_3 V_100 , V_101 ;
int V_102 = 2 ;
int V_103 ;
F_47 ( V_3 ) ;
error = - V_104 ;
if ( V_93 -> V_105 != V_81 )
goto V_23;
error = - V_106 ;
if ( V_3 -> V_21 & V_47 )
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
V_43 = F_63 ( F_64 ( V_3 ) , V_98 ) ;
if ( ( V_100 == 0 ) && ( V_101 == 0 ) ) {
if ( V_43 == NULL ) {
struct V_118 V_119 = {
. V_51 = V_52 ,
. V_120 = 0 ,
} ;
error = F_65 ( F_64 ( V_3 ) , V_103 , V_102 , V_98 , V_99 , & V_119 , & V_43 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_121 ;
if ( V_43 == NULL )
goto V_23;
if ( V_43 -> V_2 == NULL )
goto V_23;
}
if ( V_43 -> V_122 == NULL )
V_43 -> V_122 = F_5 ;
if ( V_43 -> V_99 == 0 )
V_43 -> V_99 = V_99 ;
V_4 = F_66 ( F_64 ( V_3 ) , V_43 , V_100 ) ;
if ( V_4 == NULL ) {
V_97 . V_123 = V_97 . V_124 = 1500 - V_125 ;
V_4 = F_67 ( sizeof( struct V_29 ) ,
V_43 , V_100 ,
V_101 , & V_97 ) ;
if ( V_4 == NULL ) {
error = - V_54 ;
goto V_23;
}
} else {
V_30 = F_14 ( V_4 ) ;
error = - V_126 ;
if ( V_30 -> V_2 != NULL )
goto V_23;
if ( V_30 -> V_49 != V_43 -> V_2 )
goto V_23;
}
V_30 = F_14 ( V_4 ) ;
V_30 -> V_127 = V_128 -> V_129 ;
V_30 -> V_2 = V_3 ;
V_30 -> V_49 = V_43 -> V_2 ;
V_4 -> V_130 = F_13 ;
V_4 -> V_131 = F_41 ;
#if F_68 ( V_132 ) || F_68 ( V_133 )
V_4 -> V_134 = F_59 ;
#endif
V_4 -> V_135 = F_24 ;
V_4 -> V_136 = F_25 ;
V_95 = F_69 ( V_43 -> V_2 ) ;
if ( V_95 != NULL ) {
T_3 V_137 = F_70 ( F_71 ( V_43 -> V_2 ) ) ;
if ( V_137 != 0 )
V_4 -> V_123 = V_4 -> V_124 = V_137 -
V_125 ;
F_72 ( V_95 ) ;
}
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
error = 0 ;
goto V_138;
}
V_33 -> V_36 . V_139 = V_140 ;
V_33 -> V_36 . V_61 = V_3 ;
V_33 -> V_36 . V_77 = & V_141 ;
V_33 -> V_36 . V_123 = V_4 -> V_123 ;
error = F_73 ( F_64 ( V_3 ) , & V_33 -> V_36 ) ;
if ( error )
goto V_23;
V_138:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_47 ;
F_23 ( V_4 , V_142 , L_5 ,
V_4 -> V_35 ) ;
V_23:
F_53 ( V_3 ) ;
return error ;
}
static int F_74 ( struct V_72 * V_72 , T_3 V_98 , T_3 V_100 , T_3 V_101 , struct V_96 * V_97 )
{
int error ;
struct V_42 * V_43 ;
struct V_1 * V_4 ;
struct V_29 * V_30 ;
V_43 = F_63 ( V_72 , V_98 ) ;
error = - V_121 ;
if ( V_43 == NULL )
goto V_6;
if ( V_43 -> V_2 == NULL )
goto V_6;
error = - V_126 ;
V_4 = F_66 ( V_72 , V_43 , V_100 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_97 -> V_123 == 0 )
V_97 -> V_123 = 1500 - V_125 ;
if ( V_97 -> V_124 == 0 )
V_97 -> V_124 = V_97 -> V_123 ;
error = - V_54 ;
V_4 = F_67 ( sizeof( struct V_29 ) ,
V_43 , V_100 ,
V_101 , V_97 ) ;
if ( V_4 == NULL )
goto V_6;
V_30 = F_14 ( V_4 ) ;
V_30 -> V_49 = V_43 -> V_2 ;
F_23 ( V_4 , V_142 , L_5 ,
V_4 -> V_35 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_75 ( struct V_14 * V_2 , struct V_89 * V_143 ,
int * V_144 , int V_145 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_146 * V_147 ;
struct V_29 * V_148 ;
error = - V_45 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_47 )
goto V_23;
error = - V_48 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_148 = F_14 ( V_4 ) ;
V_43 = F_28 ( V_148 -> V_49 ) ;
if ( V_43 == NULL ) {
error = - V_48 ;
goto V_149;
}
V_147 = F_76 ( V_43 -> V_2 ) ;
if ( ( V_43 -> V_150 == 2 ) && ( V_43 -> V_2 -> V_82 == V_151 ) ) {
struct V_92 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_43 -> V_103 ;
V_93 . V_108 . V_129 = V_148 -> V_127 ;
V_93 . V_108 . V_109 = V_43 -> V_98 ;
V_93 . V_108 . V_110 = V_43 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_154 . V_155 = V_151 ;
V_93 . V_108 . V_154 . V_156 = V_147 -> V_157 ;
V_93 . V_108 . V_154 . V_158 . V_159 = V_147 -> V_160 ;
memcpy ( V_143 , & V_93 , V_17 ) ;
#if F_77 ( V_161 )
} else if ( ( V_43 -> V_150 == 2 ) &&
( V_43 -> V_2 -> V_82 == V_162 ) ) {
struct V_115 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_43 -> V_103 ;
V_93 . V_108 . V_129 = V_148 -> V_127 ;
V_93 . V_108 . V_109 = V_43 -> V_98 ;
V_93 . V_108 . V_110 = V_43 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_154 . V_163 = V_162 ;
V_93 . V_108 . V_154 . V_164 = V_147 -> V_157 ;
memcpy ( & V_93 . V_108 . V_154 . V_165 , & V_43 -> V_2 -> V_166 ,
sizeof( V_43 -> V_2 -> V_166 ) ) ;
memcpy ( V_143 , & V_93 , V_17 ) ;
} else if ( ( V_43 -> V_150 == 3 ) &&
( V_43 -> V_2 -> V_82 == V_162 ) ) {
struct V_117 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_43 -> V_103 ;
V_93 . V_108 . V_129 = V_148 -> V_127 ;
V_93 . V_108 . V_109 = V_43 -> V_98 ;
V_93 . V_108 . V_110 = V_43 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_154 . V_163 = V_162 ;
V_93 . V_108 . V_154 . V_164 = V_147 -> V_157 ;
memcpy ( & V_93 . V_108 . V_154 . V_165 , & V_43 -> V_2 -> V_166 ,
sizeof( V_43 -> V_2 -> V_166 ) ) ;
memcpy ( V_143 , & V_93 , V_17 ) ;
#endif
} else if ( V_43 -> V_150 == 3 ) {
struct V_113 V_93 ;
V_17 = sizeof( V_93 ) ;
memset ( & V_93 , 0 , V_17 ) ;
V_93 . V_152 = V_153 ;
V_93 . V_105 = V_81 ;
V_93 . V_108 . V_103 = V_43 -> V_103 ;
V_93 . V_108 . V_129 = V_148 -> V_127 ;
V_93 . V_108 . V_109 = V_43 -> V_98 ;
V_93 . V_108 . V_110 = V_43 -> V_99 ;
V_93 . V_108 . V_111 = V_4 -> V_100 ;
V_93 . V_108 . V_112 = V_4 -> V_101 ;
V_93 . V_108 . V_154 . V_155 = V_151 ;
V_93 . V_108 . V_154 . V_156 = V_147 -> V_157 ;
V_93 . V_108 . V_154 . V_158 . V_159 = V_147 -> V_160 ;
memcpy ( V_143 , & V_93 , V_17 ) ;
}
* V_144 = V_17 ;
F_3 ( V_148 -> V_49 ) ;
V_149:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_78 ( struct V_167 * V_168 ,
struct V_169 * V_37 )
{
V_168 -> V_170 = F_79 ( & V_37 -> V_170 ) ;
V_168 -> V_171 = F_79 ( & V_37 -> V_171 ) ;
V_168 -> V_172 = F_79 ( & V_37 -> V_172 ) ;
V_168 -> V_173 = F_79 ( & V_37 -> V_173 ) ;
V_168 -> V_174 = F_79 ( & V_37 -> V_174 ) ;
V_168 -> V_175 = F_79 ( & V_37 -> V_175 ) ;
V_168 -> V_176 = F_79 ( & V_37 -> V_176 ) ;
V_168 -> V_38 = F_79 ( & V_37 -> V_38 ) ;
}
static int F_80 ( struct V_1 * V_4 ,
unsigned int V_177 , unsigned long V_88 )
{
struct V_178 V_179 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_180 = ( int ) V_88 ;
struct V_29 * V_30 = F_14 ( V_4 ) ;
struct V_42 * V_43 = V_4 -> V_43 ;
struct V_167 V_37 ;
F_15 ( V_4 , V_142 ,
L_6 ,
V_4 -> V_35 , V_177 , V_88 ) ;
V_3 = V_30 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_177 ) {
case V_181 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
V_19 = - V_183 ;
if ( F_81 ( & V_179 , ( void V_184 * ) V_88 , sizeof( struct V_178 ) ) )
break;
V_179 . V_185 = V_4 -> V_123 ;
if ( F_82 ( ( void V_184 * ) V_88 , & V_179 , sizeof( struct V_178 ) ) )
break;
F_23 ( V_4 , V_142 , L_7 ,
V_4 -> V_35 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_186 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
V_19 = - V_183 ;
if ( F_81 ( & V_179 , ( void V_184 * ) V_88 , sizeof( struct V_178 ) ) )
break;
V_4 -> V_123 = V_179 . V_185 ;
F_23 ( V_4 , V_142 , L_8 ,
V_4 -> V_35 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_187 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
V_19 = - V_183 ;
if ( F_83 ( V_4 -> V_124 , ( int V_184 * ) V_88 ) )
break;
F_23 ( V_4 , V_142 , L_9 ,
V_4 -> V_35 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
V_19 = - V_183 ;
if ( F_84 ( V_180 , ( int V_184 * ) V_88 ) )
break;
V_4 -> V_124 = V_180 ;
F_23 ( V_4 , V_142 , L_10 ,
V_4 -> V_35 , V_4 -> V_124 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_183 ;
if ( F_83 ( V_30 -> V_18 , ( int V_184 * ) V_88 ) )
break;
F_23 ( V_4 , V_142 , L_11 ,
V_4 -> V_35 , V_30 -> V_18 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_183 ;
if ( F_84 ( V_180 , ( int V_184 * ) V_88 ) )
break;
V_30 -> V_18 = V_180 ;
F_23 ( V_4 , V_142 , L_12 ,
V_4 -> V_35 , V_30 -> V_18 ) ;
V_19 = 0 ;
break;
case V_191 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_98 = V_43 -> V_98 ;
V_37 . V_100 = V_4 -> V_100 ;
F_78 ( & V_37 , & V_4 -> V_37 ) ;
if ( F_82 ( ( void V_184 * ) V_88 , & V_37 ,
sizeof( V_37 ) ) )
break;
F_23 ( V_4 , V_142 , L_13 ,
V_4 -> V_35 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_192 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_85 ( struct V_42 * V_43 ,
unsigned int V_177 , unsigned long V_88 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_167 V_37 ;
F_15 ( V_43 , V_142 ,
L_14 ,
V_43 -> V_35 , V_177 , V_88 ) ;
V_3 = V_43 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_177 ) {
case V_191 :
V_19 = - V_182 ;
if ( ! ( V_3 -> V_21 & V_47 ) )
break;
if ( F_81 ( & V_37 , ( void V_184 * ) V_88 ,
sizeof( V_37 ) ) ) {
V_19 = - V_183 ;
break;
}
if ( V_37 . V_100 != 0 ) {
struct V_1 * V_4 =
F_66 ( F_64 ( V_3 ) , V_43 , V_37 . V_100 ) ;
if ( V_4 != NULL )
V_19 = F_80 ( V_4 , V_177 , V_88 ) ;
else
V_19 = - V_193 ;
break;
}
#ifdef F_86
V_37 . V_194 = ( V_3 -> V_195 [ 0 ] || V_3 -> V_195 [ 1 ] ) ? 1 : 0 ;
#endif
F_78 ( & V_37 , & V_43 -> V_37 ) ;
if ( F_82 ( ( void V_184 * ) V_88 , & V_37 , sizeof( V_37 ) ) ) {
V_19 = - V_183 ;
break;
}
F_23 ( V_43 , V_142 , L_13 ,
V_43 -> V_35 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_192 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_87 ( struct V_14 * V_2 , unsigned int V_177 ,
unsigned long V_88 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
struct V_29 * V_30 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_48 ;
if ( F_27 ( V_3 , V_46 ) != 0 )
goto V_23;
V_19 = - V_45 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_21 & ( V_47 | V_22 ) ) ) )
goto V_23;
V_19 = - V_48 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_30 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_48 ;
V_43 = F_28 ( V_30 -> V_49 ) ;
if ( V_43 == NULL )
goto V_149;
V_19 = F_85 ( V_43 , V_177 , V_88 ) ;
F_3 ( V_30 -> V_49 ) ;
goto V_149;
}
V_19 = F_80 ( V_4 , V_177 , V_88 ) ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
int V_196 , int V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_197 :
V_43 -> V_120 = V_180 ;
F_23 ( V_43 , V_142 , L_15 ,
V_43 -> V_35 , V_43 -> V_120 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_196 , int V_180 )
{
int V_19 = 0 ;
struct V_29 * V_30 = F_14 ( V_4 ) ;
switch ( V_196 ) {
case V_199 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_200 = V_180 ? - 1 : 0 ;
F_23 ( V_4 , V_142 ,
L_16 ,
V_4 -> V_35 , V_4 -> V_200 ) ;
break;
case V_201 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_202 = V_180 ? - 1 : 0 ;
{
struct V_2 * V_203 = V_30 -> V_2 ;
struct V_32 * V_33 = F_19 ( V_203 ) ;
V_33 -> V_36 . V_139 = V_180 ? V_204 :
V_140 ;
}
F_90 ( V_4 , V_4 -> V_43 -> V_150 ) ;
F_23 ( V_4 , V_142 ,
L_17 ,
V_4 -> V_35 , V_4 -> V_202 ) ;
break;
case V_205 :
if ( ( V_180 != 0 ) && ( V_180 != 1 ) ) {
V_19 = - V_104 ;
break;
}
V_4 -> V_206 = V_180 ? - 1 : 0 ;
F_23 ( V_4 , V_142 ,
L_18 ,
V_4 -> V_35 , V_4 -> V_206 ) ;
break;
case V_197 :
V_4 -> V_120 = V_180 ;
F_23 ( V_4 , V_142 , L_15 ,
V_4 -> V_35 , V_4 -> V_120 ) ;
break;
case V_207 :
V_4 -> V_208 = F_91 ( V_180 ) ;
F_23 ( V_4 , V_142 ,
L_19 ,
V_4 -> V_35 , V_4 -> V_208 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_92 ( struct V_14 * V_2 , int V_209 , int V_196 ,
char V_184 * V_210 , unsigned int V_211 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
struct V_29 * V_30 ;
int V_180 ;
int V_19 ;
if ( V_209 != V_212 )
return V_213 . V_214 ( V_3 , V_209 , V_196 , V_210 , V_211 ) ;
if ( V_211 < sizeof( int ) )
return - V_104 ;
if ( F_84 ( V_180 , ( int V_184 * ) V_210 ) )
return - V_183 ;
V_19 = - V_45 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_48 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_30 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_48 ;
V_43 = F_28 ( V_30 -> V_49 ) ;
if ( V_43 == NULL )
goto V_149;
V_19 = F_88 ( V_3 , V_43 , V_196 , V_180 ) ;
F_3 ( V_30 -> V_49 ) ;
} else
V_19 = F_89 ( V_3 , V_4 , V_196 , V_180 ) ;
V_19 = 0 ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
int V_196 , int * V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_197 :
* V_180 = V_43 -> V_120 ;
F_23 ( V_43 , V_142 , L_20 ,
V_43 -> V_35 , V_43 -> V_120 ) ;
break;
default:
V_19 = - V_198 ;
break;
}
return V_19 ;
}
static int F_94 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_196 , int * V_180 )
{
int V_19 = 0 ;
switch ( V_196 ) {
case V_199 :
* V_180 = V_4 -> V_200 ;
F_23 ( V_4 , V_142 ,
L_21 , V_4 -> V_35 , * V_180 ) ;
break;
case V_201 :
* V_180 = V_4 -> V_202 ;
F_23 ( V_4 , V_142 ,
L_22 , V_4 -> V_35 , * V_180 ) ;
break;
case V_205 :
* V_180 = V_4 -> V_206 ;
F_23 ( V_4 , V_142 ,
L_23 , V_4 -> V_35 , * V_180 ) ;
break;
case V_197 :
* V_180 = V_4 -> V_120 ;
F_23 ( V_4 , V_142 , L_24 ,
V_4 -> V_35 , * V_180 ) ;
break;
case V_207 :
* V_180 = ( int ) F_95 ( V_4 -> V_208 ) ;
F_23 ( V_4 , V_142 ,
L_25 , V_4 -> V_35 , * V_180 ) ;
break;
default:
V_19 = - V_198 ;
}
return V_19 ;
}
static int F_96 ( struct V_14 * V_2 , int V_209 , int V_196 ,
char V_184 * V_210 , int V_184 * V_211 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_42 * V_43 ;
int V_180 , V_17 ;
int V_19 ;
struct V_29 * V_30 ;
if ( V_209 != V_212 )
return V_213 . V_215 ( V_3 , V_209 , V_196 , V_210 , V_211 ) ;
if ( F_84 ( V_17 , V_211 ) )
return - V_183 ;
V_17 = F_97 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_104 ;
V_19 = - V_45 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_48 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_30 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_100 == 0 ) &&
( V_4 -> V_101 == 0 ) ) {
V_19 = - V_48 ;
V_43 = F_28 ( V_30 -> V_49 ) ;
if ( V_43 == NULL )
goto V_149;
V_19 = F_93 ( V_3 , V_43 , V_196 , & V_180 ) ;
F_3 ( V_30 -> V_49 ) ;
} else
V_19 = F_94 ( V_3 , V_4 , V_196 , & V_180 ) ;
V_19 = - V_183 ;
if ( F_83 ( V_17 , V_211 ) )
goto V_149;
if ( F_82 ( ( void V_184 * ) V_210 , & V_180 , V_17 ) )
goto V_149;
V_19 = 0 ;
V_149:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_98 ( struct V_72 * V_72 , struct V_216 * V_217 )
{
for (; ; ) {
V_217 -> V_43 = F_99 ( V_72 , V_217 -> V_218 ) ;
V_217 -> V_218 ++ ;
if ( V_217 -> V_43 == NULL )
break;
if ( V_217 -> V_43 -> V_150 < 3 )
break;
}
}
static void F_100 ( struct V_72 * V_72 , struct V_216 * V_217 )
{
V_217 -> V_4 = F_101 ( V_217 -> V_43 , V_217 -> V_219 ) ;
V_217 -> V_219 ++ ;
if ( V_217 -> V_4 == NULL ) {
V_217 -> V_219 = 0 ;
F_98 ( V_72 , V_217 ) ;
}
}
static void * F_102 ( struct V_87 * V_39 , T_4 * V_220 )
{
struct V_216 * V_217 = V_221 ;
T_4 V_222 = * V_220 ;
struct V_72 * V_72 ;
if ( ! V_222 )
goto V_6;
F_4 ( V_39 -> V_61 == NULL ) ;
V_217 = V_39 -> V_61 ;
V_72 = F_103 ( V_39 ) ;
if ( V_217 -> V_43 == NULL )
F_98 ( V_72 , V_217 ) ;
else
F_100 ( V_72 , V_217 ) ;
if ( ( V_217 -> V_43 == NULL ) && ( V_217 -> V_4 == NULL ) )
V_217 = NULL ;
V_6:
return V_217 ;
}
static void * F_104 ( struct V_87 * V_39 , void * V_223 , T_4 * V_222 )
{
( * V_222 ) ++ ;
return NULL ;
}
static void F_105 ( struct V_87 * V_224 , void * V_223 )
{
}
static void F_106 ( struct V_87 * V_39 , void * V_223 )
{
struct V_42 * V_43 = V_223 ;
F_60 ( V_39 , L_26 ,
V_43 -> V_35 ,
( V_43 == V_43 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_107 ( & V_43 -> V_225 ) - 1 ) ;
F_60 ( V_39 , L_27 ,
V_43 -> V_120 ,
F_79 ( & V_43 -> V_37 . V_170 ) ,
F_79 ( & V_43 -> V_37 . V_171 ) ,
F_79 ( & V_43 -> V_37 . V_172 ) ,
F_79 ( & V_43 -> V_37 . V_173 ) ,
F_79 ( & V_43 -> V_37 . V_174 ) ,
F_79 ( & V_43 -> V_37 . V_38 ) ) ;
}
static void F_108 ( struct V_87 * V_39 , void * V_223 )
{
struct V_1 * V_4 = V_223 ;
struct V_42 * V_43 = V_4 -> V_43 ;
struct V_29 * V_30 = F_14 ( V_4 ) ;
struct V_32 * V_33 = F_19 ( V_30 -> V_2 ) ;
T_3 V_226 = 0 ;
T_5 V_227 = 0 ;
if ( V_43 -> V_2 ) {
struct V_146 * V_147 = F_76 ( V_43 -> V_2 ) ;
V_226 = F_109 ( V_147 -> V_228 ) ;
V_227 = F_110 ( V_147 -> V_229 ) ;
}
F_60 ( V_39 , L_28
L_29 ,
V_4 -> V_35 , V_226 , V_227 ,
V_43 -> V_98 ,
V_4 -> V_100 ,
V_43 -> V_99 ,
V_4 -> V_101 ,
V_30 -> V_2 -> V_21 ,
( V_4 == V_30 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_60 ( V_39 , L_30 ,
V_4 -> V_123 , V_4 -> V_124 ,
V_4 -> V_200 ? 'R' : '-' ,
V_4 -> V_202 ? 'S' : '-' ,
V_4 -> V_206 ? L_31 : L_32 ,
V_4 -> V_120 ,
F_95 ( V_4 -> V_208 ) ) ;
F_60 ( V_39 , L_33 ,
V_4 -> V_230 , V_4 -> V_231 ,
F_79 ( & V_4 -> V_37 . V_170 ) ,
F_79 ( & V_4 -> V_37 . V_171 ) ,
F_79 ( & V_4 -> V_37 . V_172 ) ,
F_79 ( & V_4 -> V_37 . V_173 ) ,
F_79 ( & V_4 -> V_37 . V_174 ) ,
F_79 ( & V_4 -> V_37 . V_38 ) ) ;
if ( V_33 )
F_60 ( V_39 , L_4 , F_61 ( & V_33 -> V_36 ) ) ;
}
static int F_111 ( struct V_87 * V_39 , void * V_223 )
{
struct V_216 * V_217 = V_223 ;
if ( V_223 == V_221 ) {
F_112 ( V_39 , L_34 V_232 L_35 ) ;
F_112 ( V_39 , L_36 ) ;
F_112 ( V_39 , L_37 ) ;
F_112 ( V_39 , L_38
L_39 ) ;
F_112 ( V_39 , L_40 ) ;
F_112 ( V_39 , L_41 ) ;
goto V_6;
}
if ( V_217 -> V_4 == NULL )
F_106 ( V_39 , V_217 -> V_43 ) ;
else
F_108 ( V_39 , V_217 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_113 ( struct V_233 * V_233 , struct V_234 * V_234 )
{
return F_114 ( V_233 , V_234 , & V_235 ,
sizeof( struct V_216 ) ) ;
}
static T_6 int F_115 ( struct V_72 * V_72 )
{
struct V_236 * V_237 ;
int V_19 = 0 ;
V_237 = F_116 ( L_42 , V_238 , V_72 -> V_239 ,
& V_240 ) ;
if ( ! V_237 ) {
V_19 = - V_54 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_117 ( struct V_72 * V_72 )
{
F_118 ( L_42 , V_72 -> V_239 ) ;
}
static int T_8 F_119 ( void )
{
int V_19 ;
V_19 = F_120 ( & V_241 ) ;
if ( V_19 )
goto V_6;
V_19 = F_121 ( & V_74 , 0 ) ;
if ( V_19 )
goto V_242;
V_19 = F_122 ( V_81 , & V_243 ) ;
if ( V_19 )
goto V_244;
#ifdef F_123
V_19 = F_124 ( V_245 , & V_246 ) ;
if ( V_19 )
goto V_247;
#endif
F_125 ( L_43 , V_232 ) ;
V_6:
return V_19 ;
#ifdef F_123
V_247:
F_126 ( V_81 ) ;
#endif
V_244:
F_127 ( & V_74 ) ;
V_242:
F_128 ( & V_241 ) ;
goto V_6;
}
static void T_9 F_129 ( void )
{
#ifdef F_123
F_130 ( V_245 ) ;
#endif
F_126 ( V_81 ) ;
F_127 ( & V_74 ) ;
F_128 ( & V_241 ) ;
}
