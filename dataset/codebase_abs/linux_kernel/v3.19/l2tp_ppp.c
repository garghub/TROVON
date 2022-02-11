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
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_32 = F_19 ( V_3 ) ;
F_20 ( & V_32 -> V_35 , V_10 ) ;
} else {
F_15 ( V_4 , V_33 ,
L_2 ,
V_4 -> V_34 , V_27 ) ;
if ( F_21 ( V_3 , V_10 ) < 0 ) {
F_22 ( & V_4 -> V_36 . V_37 ) ;
F_12 ( V_10 ) ;
}
}
return;
V_30:
F_23 ( V_4 , V_33 , L_3 , V_4 -> V_34 ) ;
F_12 ( V_10 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 )
F_2 ( V_29 -> V_2 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 -> V_2 )
F_3 ( V_29 -> V_2 ) ;
}
static int F_26 ( struct V_12 * V_13 , struct V_14 * V_2 , struct V_15 * V_38 ,
T_1 V_39 )
{
static const unsigned char V_40 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
struct V_28 * V_29 ;
int V_43 ;
error = - V_44 ;
if ( F_27 ( V_3 , V_45 ) || ! ( V_3 -> V_21 & V_46 ) )
goto error;
error = - V_47 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_29 = F_14 ( V_4 ) ;
V_42 = F_28 ( V_29 -> V_48 ) ;
if ( V_42 == NULL )
goto V_49;
V_43 = ( V_42 -> V_50 == V_51 ) ? sizeof( struct V_52 ) : 0 ;
error = - V_53 ;
V_10 = F_29 ( V_3 , V_54 + sizeof( struct V_55 ) +
V_43 + V_4 -> V_56 +
sizeof( V_40 ) + V_39 ,
0 , V_57 ) ;
if ( ! V_10 )
goto V_58;
F_30 ( V_10 , V_54 ) ;
F_31 ( V_10 ) ;
F_30 ( V_10 , sizeof( struct V_55 ) ) ;
F_32 ( V_10 ) ;
F_30 ( V_10 , V_43 ) ;
V_10 -> V_11 [ 0 ] = V_40 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_40 [ 1 ] ;
F_33 ( V_10 , 2 ) ;
error = F_34 ( F_33 ( V_10 , V_39 ) , V_38 , V_39 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_58;
}
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_56 ) ;
F_37 () ;
F_3 ( V_29 -> V_48 ) ;
F_3 ( V_3 ) ;
return V_39 ;
V_58:
F_3 ( V_29 -> V_48 ) ;
V_49:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_38 ( struct V_59 * V_35 , struct V_9 * V_10 )
{
static const T_2 V_40 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_35 -> V_60 ;
struct V_2 * V_61 ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
struct V_28 * V_29 ;
int V_43 , V_62 ;
if ( F_27 ( V_3 , V_45 ) || ! ( V_3 -> V_21 & V_46 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_29 = F_14 ( V_4 ) ;
V_61 = V_29 -> V_48 ;
if ( V_61 == NULL )
goto V_63;
V_42 = F_28 ( V_61 ) ;
if ( V_42 == NULL )
goto V_63;
V_43 = ( V_42 -> V_50 == V_51 ) ? sizeof( struct V_52 ) : 0 ;
V_62 = V_54 +
sizeof( struct V_55 ) +
V_43 +
V_4 -> V_56 +
sizeof( V_40 ) ;
if ( F_39 ( V_10 , V_62 ) )
goto V_64;
F_40 ( V_10 , sizeof( V_40 ) ) ;
V_10 -> V_11 [ 0 ] = V_40 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_40 [ 1 ] ;
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_56 ) ;
F_37 () ;
F_3 ( V_61 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_64:
F_3 ( V_61 ) ;
V_63:
F_3 ( V_3 ) ;
abort:
F_12 ( V_10 ) ;
return 1 ;
}
static void F_41 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_29 -> V_2 ;
struct V_14 * V_2 = V_3 -> V_65 ;
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
error = - V_47 ;
F_47 ( V_3 ) ;
if ( F_27 ( V_3 , V_45 ) != 0 )
goto error;
F_48 ( V_3 ) ;
V_3 -> V_21 = V_66 ;
F_49 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_50 ( V_4 ) ;
F_51 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_52 ( & V_3 -> V_67 ) ;
F_52 ( & V_3 -> V_68 ) ;
F_53 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_53 ( V_3 ) ;
return error ;
}
static int F_54 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_69 ;
V_69 = F_55 ( V_3 , V_10 ) ;
if ( V_69 )
F_12 ( V_10 ) ;
return V_70 ;
}
static int F_56 ( struct V_71 * V_71 , struct V_14 * V_2 )
{
int error = - V_53 ;
struct V_2 * V_3 ;
V_3 = F_57 ( V_71 , V_72 , V_57 , & V_73 ) ;
if ( ! V_3 )
goto V_6;
F_58 ( V_2 , V_3 ) ;
V_2 -> V_74 = V_75 ;
V_2 -> V_76 = & V_77 ;
V_3 -> V_78 = F_54 ;
V_3 -> V_79 = V_80 ;
V_3 -> V_81 = V_72 ;
V_3 -> V_21 = V_82 ;
V_3 -> V_83 = V_84 ;
V_3 -> V_85 = F_44 ;
error = 0 ;
V_6:
return error ;
}
static void F_59 ( struct V_86 * V_38 , void * V_87 )
{
struct V_1 * V_4 = V_87 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
if ( V_29 ) {
struct V_31 * V_32 = F_19 ( V_29 -> V_2 ) ;
if ( V_32 )
F_60 ( V_38 , L_4 , F_61 ( & V_32 -> V_35 ) ) ;
}
}
static int F_62 ( struct V_14 * V_2 , struct V_88 * V_89 ,
int V_90 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_31 * V_32 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_41 * V_42 ;
struct V_28 * V_29 ;
struct V_93 * V_94 ;
struct V_95 V_96 = { 0 , } ;
int error = 0 ;
T_3 V_97 , V_98 ;
T_3 V_99 , V_100 ;
int V_101 = 2 ;
int V_102 ;
F_47 ( V_3 ) ;
error = - V_103 ;
if ( V_92 -> V_104 != V_80 )
goto V_23;
error = - V_105 ;
if ( V_3 -> V_21 & V_46 )
goto V_23;
error = - V_106 ;
if ( V_3 -> V_5 )
goto V_23;
V_98 = 0 ;
if ( V_90 == sizeof( struct V_91 ) ) {
V_102 = V_92 -> V_107 . V_102 ;
V_97 = V_92 -> V_107 . V_108 ;
V_98 = V_92 -> V_107 . V_109 ;
V_99 = V_92 -> V_107 . V_110 ;
V_100 = V_92 -> V_107 . V_111 ;
} else if ( V_90 == sizeof( struct V_112 ) ) {
struct V_112 * V_113 =
(struct V_112 * ) V_92 ;
V_101 = 3 ;
V_102 = V_113 -> V_107 . V_102 ;
V_97 = V_113 -> V_107 . V_108 ;
V_98 = V_113 -> V_107 . V_109 ;
V_99 = V_113 -> V_107 . V_110 ;
V_100 = V_113 -> V_107 . V_111 ;
} else if ( V_90 == sizeof( struct V_114 ) ) {
struct V_114 * V_115 =
(struct V_114 * ) V_92 ;
V_102 = V_115 -> V_107 . V_102 ;
V_97 = V_115 -> V_107 . V_108 ;
V_98 = V_115 -> V_107 . V_109 ;
V_99 = V_115 -> V_107 . V_110 ;
V_100 = V_115 -> V_107 . V_111 ;
} else if ( V_90 == sizeof( struct V_116 ) ) {
struct V_116 * V_115 =
(struct V_116 * ) V_92 ;
V_101 = 3 ;
V_102 = V_115 -> V_107 . V_102 ;
V_97 = V_115 -> V_107 . V_108 ;
V_98 = V_115 -> V_107 . V_109 ;
V_99 = V_115 -> V_107 . V_110 ;
V_100 = V_115 -> V_107 . V_111 ;
} else {
error = - V_103 ;
goto V_23;
}
error = - V_103 ;
if ( V_97 == 0 )
goto V_23;
V_42 = F_63 ( F_64 ( V_3 ) , V_97 ) ;
if ( ( V_99 == 0 ) && ( V_100 == 0 ) ) {
if ( V_42 == NULL ) {
struct V_117 V_118 = {
. V_50 = V_51 ,
. V_119 = 0 ,
} ;
error = F_65 ( F_64 ( V_3 ) , V_102 , V_101 , V_97 , V_98 , & V_118 , & V_42 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_120 ;
if ( V_42 == NULL )
goto V_23;
if ( V_42 -> V_2 == NULL )
goto V_23;
}
if ( V_42 -> V_121 == NULL )
V_42 -> V_121 = F_5 ;
if ( V_42 -> V_98 == 0 )
V_42 -> V_98 = V_98 ;
V_4 = F_66 ( F_64 ( V_3 ) , V_42 , V_99 ) ;
if ( V_4 == NULL ) {
V_96 . V_122 = V_96 . V_123 = 1500 - V_124 ;
V_4 = F_67 ( sizeof( struct V_28 ) ,
V_42 , V_99 ,
V_100 , & V_96 ) ;
if ( V_4 == NULL ) {
error = - V_53 ;
goto V_23;
}
} else {
V_29 = F_14 ( V_4 ) ;
error = - V_125 ;
if ( V_29 -> V_2 != NULL )
goto V_23;
if ( V_29 -> V_48 != V_42 -> V_2 )
goto V_23;
}
V_29 = F_14 ( V_4 ) ;
V_29 -> V_126 = V_127 -> V_128 ;
V_29 -> V_2 = V_3 ;
V_29 -> V_48 = V_42 -> V_2 ;
V_4 -> V_129 = F_13 ;
V_4 -> V_130 = F_41 ;
#if F_68 ( V_131 ) || F_68 ( V_132 )
V_4 -> V_133 = F_59 ;
#endif
V_4 -> V_134 = F_24 ;
V_4 -> V_135 = F_25 ;
V_94 = F_69 ( V_42 -> V_2 ) ;
if ( V_94 != NULL ) {
T_3 V_136 = F_70 ( V_94 ) ;
if ( V_136 != 0 )
V_4 -> V_122 = V_4 -> V_123 = V_136 -
V_124 ;
F_71 ( V_94 ) ;
}
if ( ( V_4 -> V_99 == 0 ) &&
( V_4 -> V_100 == 0 ) ) {
error = 0 ;
goto V_137;
}
V_32 -> V_35 . V_138 = V_139 ;
V_32 -> V_35 . V_60 = V_3 ;
V_32 -> V_35 . V_76 = & V_140 ;
V_32 -> V_35 . V_122 = V_4 -> V_122 ;
error = F_72 ( F_64 ( V_3 ) , & V_32 -> V_35 ) ;
if ( error )
goto V_23;
V_137:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_46 ;
F_23 ( V_4 , V_141 , L_5 ,
V_4 -> V_34 ) ;
V_23:
F_53 ( V_3 ) ;
return error ;
}
static int F_73 ( struct V_71 * V_71 , T_3 V_97 , T_3 V_99 , T_3 V_100 , struct V_95 * V_96 )
{
int error ;
struct V_41 * V_42 ;
struct V_1 * V_4 ;
struct V_28 * V_29 ;
V_42 = F_63 ( V_71 , V_97 ) ;
error = - V_120 ;
if ( V_42 == NULL )
goto V_6;
if ( V_42 -> V_2 == NULL )
goto V_6;
error = - V_125 ;
V_4 = F_66 ( V_71 , V_42 , V_99 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_96 -> V_122 == 0 )
V_96 -> V_122 = 1500 - V_124 ;
if ( V_96 -> V_123 == 0 )
V_96 -> V_123 = V_96 -> V_122 ;
error = - V_53 ;
V_4 = F_67 ( sizeof( struct V_28 ) ,
V_42 , V_99 ,
V_100 , V_96 ) ;
if ( V_4 == NULL )
goto V_6;
V_29 = F_14 ( V_4 ) ;
V_29 -> V_48 = V_42 -> V_2 ;
F_23 ( V_4 , V_141 , L_5 ,
V_4 -> V_34 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_74 ( struct V_14 * V_2 , struct V_88 * V_142 ,
int * V_143 , int V_144 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_145 * V_146 ;
struct V_28 * V_147 ;
error = - V_44 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_46 )
goto V_23;
error = - V_47 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_147 = F_14 ( V_4 ) ;
V_42 = F_28 ( V_147 -> V_48 ) ;
if ( V_42 == NULL ) {
error = - V_47 ;
goto V_148;
}
V_146 = F_75 ( V_42 -> V_2 ) ;
if ( ( V_42 -> V_149 == 2 ) && ( V_42 -> V_2 -> V_81 == V_150 ) ) {
struct V_91 V_92 ;
V_17 = sizeof( V_92 ) ;
memset ( & V_92 , 0 , V_17 ) ;
V_92 . V_151 = V_152 ;
V_92 . V_104 = V_80 ;
V_92 . V_107 . V_102 = V_42 -> V_102 ;
V_92 . V_107 . V_128 = V_147 -> V_126 ;
V_92 . V_107 . V_108 = V_42 -> V_97 ;
V_92 . V_107 . V_109 = V_42 -> V_98 ;
V_92 . V_107 . V_110 = V_4 -> V_99 ;
V_92 . V_107 . V_111 = V_4 -> V_100 ;
V_92 . V_107 . V_153 . V_154 = V_150 ;
V_92 . V_107 . V_153 . V_155 = V_146 -> V_156 ;
V_92 . V_107 . V_153 . V_157 . V_158 = V_146 -> V_159 ;
memcpy ( V_142 , & V_92 , V_17 ) ;
#if F_76 ( V_160 )
} else if ( ( V_42 -> V_149 == 2 ) &&
( V_42 -> V_2 -> V_81 == V_161 ) ) {
struct V_114 V_92 ;
V_17 = sizeof( V_92 ) ;
memset ( & V_92 , 0 , V_17 ) ;
V_92 . V_151 = V_152 ;
V_92 . V_104 = V_80 ;
V_92 . V_107 . V_102 = V_42 -> V_102 ;
V_92 . V_107 . V_128 = V_147 -> V_126 ;
V_92 . V_107 . V_108 = V_42 -> V_97 ;
V_92 . V_107 . V_109 = V_42 -> V_98 ;
V_92 . V_107 . V_110 = V_4 -> V_99 ;
V_92 . V_107 . V_111 = V_4 -> V_100 ;
V_92 . V_107 . V_153 . V_162 = V_161 ;
V_92 . V_107 . V_153 . V_163 = V_146 -> V_156 ;
memcpy ( & V_92 . V_107 . V_153 . V_164 , & V_42 -> V_2 -> V_165 ,
sizeof( V_42 -> V_2 -> V_165 ) ) ;
memcpy ( V_142 , & V_92 , V_17 ) ;
} else if ( ( V_42 -> V_149 == 3 ) &&
( V_42 -> V_2 -> V_81 == V_161 ) ) {
struct V_116 V_92 ;
V_17 = sizeof( V_92 ) ;
memset ( & V_92 , 0 , V_17 ) ;
V_92 . V_151 = V_152 ;
V_92 . V_104 = V_80 ;
V_92 . V_107 . V_102 = V_42 -> V_102 ;
V_92 . V_107 . V_128 = V_147 -> V_126 ;
V_92 . V_107 . V_108 = V_42 -> V_97 ;
V_92 . V_107 . V_109 = V_42 -> V_98 ;
V_92 . V_107 . V_110 = V_4 -> V_99 ;
V_92 . V_107 . V_111 = V_4 -> V_100 ;
V_92 . V_107 . V_153 . V_162 = V_161 ;
V_92 . V_107 . V_153 . V_163 = V_146 -> V_156 ;
memcpy ( & V_92 . V_107 . V_153 . V_164 , & V_42 -> V_2 -> V_165 ,
sizeof( V_42 -> V_2 -> V_165 ) ) ;
memcpy ( V_142 , & V_92 , V_17 ) ;
#endif
} else if ( V_42 -> V_149 == 3 ) {
struct V_112 V_92 ;
V_17 = sizeof( V_92 ) ;
memset ( & V_92 , 0 , V_17 ) ;
V_92 . V_151 = V_152 ;
V_92 . V_104 = V_80 ;
V_92 . V_107 . V_102 = V_42 -> V_102 ;
V_92 . V_107 . V_128 = V_147 -> V_126 ;
V_92 . V_107 . V_108 = V_42 -> V_97 ;
V_92 . V_107 . V_109 = V_42 -> V_98 ;
V_92 . V_107 . V_110 = V_4 -> V_99 ;
V_92 . V_107 . V_111 = V_4 -> V_100 ;
V_92 . V_107 . V_153 . V_154 = V_150 ;
V_92 . V_107 . V_153 . V_155 = V_146 -> V_156 ;
V_92 . V_107 . V_153 . V_157 . V_158 = V_146 -> V_159 ;
memcpy ( V_142 , & V_92 , V_17 ) ;
}
* V_143 = V_17 ;
F_3 ( V_147 -> V_48 ) ;
V_148:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_77 ( struct V_166 * V_167 ,
struct V_168 * V_36 )
{
V_167 -> V_169 = F_78 ( & V_36 -> V_169 ) ;
V_167 -> V_170 = F_78 ( & V_36 -> V_170 ) ;
V_167 -> V_171 = F_78 ( & V_36 -> V_171 ) ;
V_167 -> V_172 = F_78 ( & V_36 -> V_172 ) ;
V_167 -> V_173 = F_78 ( & V_36 -> V_173 ) ;
V_167 -> V_174 = F_78 ( & V_36 -> V_174 ) ;
V_167 -> V_175 = F_78 ( & V_36 -> V_175 ) ;
V_167 -> V_37 = F_78 ( & V_36 -> V_37 ) ;
}
static int F_79 ( struct V_1 * V_4 ,
unsigned int V_176 , unsigned long V_87 )
{
struct V_177 V_178 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_179 = ( int ) V_87 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_166 V_36 ;
F_15 ( V_4 , V_141 ,
L_6 ,
V_4 -> V_34 , V_176 , V_87 ) ;
V_3 = V_29 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_176 ) {
case V_180 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
V_19 = - V_182 ;
if ( F_80 ( & V_178 , ( void V_183 * ) V_87 , sizeof( struct V_177 ) ) )
break;
V_178 . V_184 = V_4 -> V_122 ;
if ( F_81 ( ( void V_183 * ) V_87 , & V_178 , sizeof( struct V_177 ) ) )
break;
F_23 ( V_4 , V_141 , L_7 ,
V_4 -> V_34 , V_4 -> V_122 ) ;
V_19 = 0 ;
break;
case V_185 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
V_19 = - V_182 ;
if ( F_80 ( & V_178 , ( void V_183 * ) V_87 , sizeof( struct V_177 ) ) )
break;
V_4 -> V_122 = V_178 . V_184 ;
F_23 ( V_4 , V_141 , L_8 ,
V_4 -> V_34 , V_4 -> V_122 ) ;
V_19 = 0 ;
break;
case V_186 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
V_19 = - V_182 ;
if ( F_82 ( V_4 -> V_123 , ( int V_183 * ) V_87 ) )
break;
F_23 ( V_4 , V_141 , L_9 ,
V_4 -> V_34 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_187 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
V_19 = - V_182 ;
if ( F_83 ( V_179 , ( int V_183 * ) V_87 ) )
break;
V_4 -> V_123 = V_179 ;
F_23 ( V_4 , V_141 , L_10 ,
V_4 -> V_34 , V_4 -> V_123 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_182 ;
if ( F_82 ( V_29 -> V_18 , ( int V_183 * ) V_87 ) )
break;
F_23 ( V_4 , V_141 , L_11 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_182 ;
if ( F_83 ( V_179 , ( int V_183 * ) V_87 ) )
break;
V_29 -> V_18 = V_179 ;
F_23 ( V_4 , V_141 , L_12 ,
V_4 -> V_34 , V_29 -> V_18 ) ;
V_19 = 0 ;
break;
case V_190 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_97 = V_42 -> V_97 ;
V_36 . V_99 = V_4 -> V_99 ;
F_77 ( & V_36 , & V_4 -> V_36 ) ;
if ( F_81 ( ( void V_183 * ) V_87 , & V_36 ,
sizeof( V_36 ) ) )
break;
F_23 ( V_4 , V_141 , L_13 ,
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
static int F_84 ( struct V_41 * V_42 ,
unsigned int V_176 , unsigned long V_87 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_166 V_36 ;
F_15 ( V_42 , V_141 ,
L_14 ,
V_42 -> V_34 , V_176 , V_87 ) ;
V_3 = V_42 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_176 ) {
case V_190 :
V_19 = - V_181 ;
if ( ! ( V_3 -> V_21 & V_46 ) )
break;
if ( F_80 ( & V_36 , ( void V_183 * ) V_87 ,
sizeof( V_36 ) ) ) {
V_19 = - V_182 ;
break;
}
if ( V_36 . V_99 != 0 ) {
struct V_1 * V_4 =
F_66 ( F_64 ( V_3 ) , V_42 , V_36 . V_99 ) ;
if ( V_4 != NULL )
V_19 = F_79 ( V_4 , V_176 , V_87 ) ;
else
V_19 = - V_192 ;
break;
}
#ifdef F_85
V_36 . V_193 = ( V_3 -> V_194 [ 0 ] || V_3 -> V_194 [ 1 ] ) ? 1 : 0 ;
#endif
F_77 ( & V_36 , & V_42 -> V_36 ) ;
if ( F_81 ( ( void V_183 * ) V_87 , & V_36 , sizeof( V_36 ) ) ) {
V_19 = - V_182 ;
break;
}
F_23 ( V_42 , V_141 , L_13 ,
V_42 -> V_34 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_191 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_86 ( struct V_14 * V_2 , unsigned int V_176 ,
unsigned long V_87 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
struct V_28 * V_29 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_47 ;
if ( F_27 ( V_3 , V_45 ) != 0 )
goto V_23;
V_19 = - V_44 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_21 & ( V_46 | V_22 ) ) ) )
goto V_23;
V_19 = - V_47 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_99 == 0 ) &&
( V_4 -> V_100 == 0 ) ) {
V_19 = - V_47 ;
V_42 = F_28 ( V_29 -> V_48 ) ;
if ( V_42 == NULL )
goto V_148;
V_19 = F_84 ( V_42 , V_176 , V_87 ) ;
F_3 ( V_29 -> V_48 ) ;
goto V_148;
}
V_19 = F_79 ( V_4 , V_176 , V_87 ) ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
int V_195 , int V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_196 :
V_42 -> V_119 = V_179 ;
F_23 ( V_42 , V_141 , L_15 ,
V_42 -> V_34 , V_42 -> V_119 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_195 , int V_179 )
{
int V_19 = 0 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
switch ( V_195 ) {
case V_198 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_103 ;
break;
}
V_4 -> V_199 = V_179 ? - 1 : 0 ;
F_23 ( V_4 , V_141 ,
L_16 ,
V_4 -> V_34 , V_4 -> V_199 ) ;
break;
case V_200 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_103 ;
break;
}
V_4 -> V_201 = V_179 ? - 1 : 0 ;
{
struct V_2 * V_202 = V_29 -> V_2 ;
struct V_31 * V_32 = F_19 ( V_202 ) ;
V_32 -> V_35 . V_138 = V_179 ? V_203 :
V_139 ;
}
F_89 ( V_4 , V_4 -> V_42 -> V_149 ) ;
F_23 ( V_4 , V_141 ,
L_17 ,
V_4 -> V_34 , V_4 -> V_201 ) ;
break;
case V_204 :
if ( ( V_179 != 0 ) && ( V_179 != 1 ) ) {
V_19 = - V_103 ;
break;
}
V_4 -> V_205 = V_179 ? - 1 : 0 ;
F_23 ( V_4 , V_141 ,
L_18 ,
V_4 -> V_34 , V_4 -> V_205 ) ;
break;
case V_196 :
V_4 -> V_119 = V_179 ;
F_23 ( V_4 , V_141 , L_15 ,
V_4 -> V_34 , V_4 -> V_119 ) ;
break;
case V_206 :
V_4 -> V_207 = F_90 ( V_179 ) ;
F_23 ( V_4 , V_141 ,
L_19 ,
V_4 -> V_34 , V_4 -> V_207 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_91 ( struct V_14 * V_2 , int V_208 , int V_195 ,
char V_183 * V_209 , unsigned int V_210 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
struct V_28 * V_29 ;
int V_179 ;
int V_19 ;
if ( V_208 != V_211 )
return - V_103 ;
if ( V_210 < sizeof( int ) )
return - V_103 ;
if ( F_83 ( V_179 , ( int V_183 * ) V_209 ) )
return - V_182 ;
V_19 = - V_44 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_47 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_99 == 0 ) &&
( V_4 -> V_100 == 0 ) ) {
V_19 = - V_47 ;
V_42 = F_28 ( V_29 -> V_48 ) ;
if ( V_42 == NULL )
goto V_148;
V_19 = F_87 ( V_3 , V_42 , V_195 , V_179 ) ;
F_3 ( V_29 -> V_48 ) ;
} else
V_19 = F_88 ( V_3 , V_4 , V_195 , V_179 ) ;
V_19 = 0 ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
int V_195 , int * V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_196 :
* V_179 = V_42 -> V_119 ;
F_23 ( V_42 , V_141 , L_20 ,
V_42 -> V_34 , V_42 -> V_119 ) ;
break;
default:
V_19 = - V_197 ;
break;
}
return V_19 ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_195 , int * V_179 )
{
int V_19 = 0 ;
switch ( V_195 ) {
case V_198 :
* V_179 = V_4 -> V_199 ;
F_23 ( V_4 , V_141 ,
L_21 , V_4 -> V_34 , * V_179 ) ;
break;
case V_200 :
* V_179 = V_4 -> V_201 ;
F_23 ( V_4 , V_141 ,
L_22 , V_4 -> V_34 , * V_179 ) ;
break;
case V_204 :
* V_179 = V_4 -> V_205 ;
F_23 ( V_4 , V_141 ,
L_23 , V_4 -> V_34 , * V_179 ) ;
break;
case V_196 :
* V_179 = V_4 -> V_119 ;
F_23 ( V_4 , V_141 , L_24 ,
V_4 -> V_34 , * V_179 ) ;
break;
case V_206 :
* V_179 = ( int ) F_94 ( V_4 -> V_207 ) ;
F_23 ( V_4 , V_141 ,
L_25 , V_4 -> V_34 , * V_179 ) ;
break;
default:
V_19 = - V_197 ;
}
return V_19 ;
}
static int F_95 ( struct V_14 * V_2 , int V_208 , int V_195 ,
char V_183 * V_209 , int V_183 * V_210 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_41 * V_42 ;
int V_179 , V_17 ;
int V_19 ;
struct V_28 * V_29 ;
if ( V_208 != V_211 )
return - V_103 ;
if ( F_83 ( V_17 , V_210 ) )
return - V_182 ;
V_17 = F_96 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_103 ;
V_19 = - V_44 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_47 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_29 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_99 == 0 ) &&
( V_4 -> V_100 == 0 ) ) {
V_19 = - V_47 ;
V_42 = F_28 ( V_29 -> V_48 ) ;
if ( V_42 == NULL )
goto V_148;
V_19 = F_92 ( V_3 , V_42 , V_195 , & V_179 ) ;
F_3 ( V_29 -> V_48 ) ;
} else
V_19 = F_93 ( V_3 , V_4 , V_195 , & V_179 ) ;
V_19 = - V_182 ;
if ( F_82 ( V_17 , V_210 ) )
goto V_148;
if ( F_81 ( ( void V_183 * ) V_209 , & V_179 , V_17 ) )
goto V_148;
V_19 = 0 ;
V_148:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_97 ( struct V_71 * V_71 , struct V_212 * V_213 )
{
for (; ; ) {
V_213 -> V_42 = F_98 ( V_71 , V_213 -> V_214 ) ;
V_213 -> V_214 ++ ;
if ( V_213 -> V_42 == NULL )
break;
if ( V_213 -> V_42 -> V_149 < 3 )
break;
}
}
static void F_99 ( struct V_71 * V_71 , struct V_212 * V_213 )
{
V_213 -> V_4 = F_100 ( V_213 -> V_42 , V_213 -> V_215 ) ;
V_213 -> V_215 ++ ;
if ( V_213 -> V_4 == NULL ) {
V_213 -> V_215 = 0 ;
F_97 ( V_71 , V_213 ) ;
}
}
static void * F_101 ( struct V_86 * V_38 , T_4 * V_216 )
{
struct V_212 * V_213 = V_217 ;
T_4 V_218 = * V_216 ;
struct V_71 * V_71 ;
if ( ! V_218 )
goto V_6;
F_4 ( V_38 -> V_60 == NULL ) ;
V_213 = V_38 -> V_60 ;
V_71 = F_102 ( V_38 ) ;
if ( V_213 -> V_42 == NULL )
F_97 ( V_71 , V_213 ) ;
else
F_99 ( V_71 , V_213 ) ;
if ( ( V_213 -> V_42 == NULL ) && ( V_213 -> V_4 == NULL ) )
V_213 = NULL ;
V_6:
return V_213 ;
}
static void * F_103 ( struct V_86 * V_38 , void * V_219 , T_4 * V_218 )
{
( * V_218 ) ++ ;
return NULL ;
}
static void F_104 ( struct V_86 * V_220 , void * V_219 )
{
}
static void F_105 ( struct V_86 * V_38 , void * V_219 )
{
struct V_41 * V_42 = V_219 ;
F_60 ( V_38 , L_26 ,
V_42 -> V_34 ,
( V_42 == V_42 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_106 ( & V_42 -> V_221 ) - 1 ) ;
F_60 ( V_38 , L_27 ,
V_42 -> V_119 ,
F_78 ( & V_42 -> V_36 . V_169 ) ,
F_78 ( & V_42 -> V_36 . V_170 ) ,
F_78 ( & V_42 -> V_36 . V_171 ) ,
F_78 ( & V_42 -> V_36 . V_172 ) ,
F_78 ( & V_42 -> V_36 . V_173 ) ,
F_78 ( & V_42 -> V_36 . V_37 ) ) ;
}
static void F_107 ( struct V_86 * V_38 , void * V_219 )
{
struct V_1 * V_4 = V_219 ;
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_28 * V_29 = F_14 ( V_4 ) ;
struct V_31 * V_32 = F_19 ( V_29 -> V_2 ) ;
T_3 V_222 = 0 ;
T_5 V_223 = 0 ;
if ( V_42 -> V_2 ) {
struct V_145 * V_146 = F_75 ( V_42 -> V_2 ) ;
V_222 = F_108 ( V_146 -> V_224 ) ;
V_223 = F_109 ( V_146 -> V_225 ) ;
}
F_60 ( V_38 , L_28
L_29 ,
V_4 -> V_34 , V_222 , V_223 ,
V_42 -> V_97 ,
V_4 -> V_99 ,
V_42 -> V_98 ,
V_4 -> V_100 ,
V_29 -> V_2 -> V_21 ,
( V_4 == V_29 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_60 ( V_38 , L_30 ,
V_4 -> V_122 , V_4 -> V_123 ,
V_4 -> V_199 ? 'R' : '-' ,
V_4 -> V_201 ? 'S' : '-' ,
V_4 -> V_205 ? L_31 : L_32 ,
V_4 -> V_119 ,
F_94 ( V_4 -> V_207 ) ) ;
F_60 ( V_38 , L_33 ,
V_4 -> V_226 , V_4 -> V_227 ,
F_78 ( & V_4 -> V_36 . V_169 ) ,
F_78 ( & V_4 -> V_36 . V_170 ) ,
F_78 ( & V_4 -> V_36 . V_171 ) ,
F_78 ( & V_4 -> V_36 . V_172 ) ,
F_78 ( & V_4 -> V_36 . V_173 ) ,
F_78 ( & V_4 -> V_36 . V_37 ) ) ;
if ( V_32 )
F_60 ( V_38 , L_4 , F_61 ( & V_32 -> V_35 ) ) ;
}
static int F_110 ( struct V_86 * V_38 , void * V_219 )
{
struct V_212 * V_213 = V_219 ;
if ( V_219 == V_217 ) {
F_111 ( V_38 , L_34 V_228 L_35 ) ;
F_111 ( V_38 , L_36 ) ;
F_111 ( V_38 , L_37 ) ;
F_111 ( V_38 , L_38
L_39 ) ;
F_111 ( V_38 , L_40 ) ;
F_111 ( V_38 , L_41 ) ;
goto V_6;
}
if ( V_213 -> V_4 == NULL )
F_105 ( V_38 , V_213 -> V_42 ) ;
else
F_107 ( V_38 , V_213 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_112 ( struct V_229 * V_229 , struct V_230 * V_230 )
{
return F_113 ( V_229 , V_230 , & V_231 ,
sizeof( struct V_212 ) ) ;
}
static T_6 int F_114 ( struct V_71 * V_71 )
{
struct V_232 * V_233 ;
int V_19 = 0 ;
V_233 = F_115 ( L_42 , V_234 , V_71 -> V_235 ,
& V_236 ) ;
if ( ! V_233 ) {
V_19 = - V_53 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_116 ( struct V_71 * V_71 )
{
F_117 ( L_42 , V_71 -> V_235 ) ;
}
static int T_8 F_118 ( void )
{
int V_19 ;
V_19 = F_119 ( & V_237 ) ;
if ( V_19 )
goto V_6;
V_19 = F_120 ( & V_73 , 0 ) ;
if ( V_19 )
goto V_238;
V_19 = F_121 ( V_80 , & V_239 ) ;
if ( V_19 )
goto V_240;
#ifdef F_122
V_19 = F_123 ( V_241 , & V_242 ) ;
if ( V_19 )
goto V_243;
#endif
F_124 ( L_43 , V_228 ) ;
V_6:
return V_19 ;
#ifdef F_122
V_243:
F_125 ( V_80 ) ;
#endif
V_240:
F_126 ( & V_73 ) ;
V_238:
F_127 ( & V_237 ) ;
goto V_6;
}
static void T_9 F_128 ( void )
{
#ifdef F_122
F_129 ( V_241 ) ;
#endif
F_125 ( V_80 ) ;
F_126 ( & V_73 ) ;
F_127 ( & V_237 ) ;
}
