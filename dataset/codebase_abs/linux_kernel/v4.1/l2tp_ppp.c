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
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_30 = F_19 ( V_3 ) ;
F_20 ( & V_30 -> V_33 , V_10 ) ;
} else {
F_15 ( V_4 , V_31 ,
L_2 ,
V_4 -> V_32 , V_25 ) ;
if ( F_21 ( V_3 , V_10 ) < 0 ) {
F_22 ( & V_4 -> V_34 . V_35 ) ;
F_12 ( V_10 ) ;
}
}
return;
V_28:
F_23 ( V_4 , V_31 , L_3 , V_4 -> V_32 ) ;
F_12 ( V_10 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 -> V_2 )
F_2 ( V_27 -> V_2 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 -> V_2 )
F_3 ( V_27 -> V_2 ) ;
}
static int F_26 ( struct V_12 * V_2 , struct V_13 * V_36 ,
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
if ( F_27 ( V_3 , V_43 ) || ! ( V_3 -> V_19 & V_44 ) )
goto error;
error = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_27 = F_14 ( V_4 ) ;
V_40 = F_28 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_47;
V_41 = ( V_40 -> V_48 == V_49 ) ? sizeof( struct V_50 ) : 0 ;
error = - V_51 ;
V_10 = F_29 ( V_3 , V_52 + sizeof( struct V_53 ) +
V_41 + V_4 -> V_54 +
sizeof( V_38 ) + V_37 ,
0 , V_55 ) ;
if ( ! V_10 )
goto V_56;
F_30 ( V_10 , V_52 ) ;
F_31 ( V_10 ) ;
F_30 ( V_10 , sizeof( struct V_53 ) ) ;
F_32 ( V_10 ) ;
F_30 ( V_10 , V_41 ) ;
V_10 -> V_11 [ 0 ] = V_38 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_38 [ 1 ] ;
F_33 ( V_10 , 2 ) ;
error = F_34 ( F_33 ( V_10 , V_37 ) , V_36 , V_37 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_56;
}
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_54 ) ;
F_37 () ;
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
static int F_38 ( struct V_57 * V_33 , struct V_9 * V_10 )
{
static const T_2 V_38 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_33 -> V_58 ;
struct V_2 * V_59 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_41 , V_60 ;
if ( F_27 ( V_3 , V_43 ) || ! ( V_3 -> V_19 & V_44 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_27 = F_14 ( V_4 ) ;
V_59 = V_27 -> V_46 ;
if ( V_59 == NULL )
goto V_61;
V_40 = F_28 ( V_59 ) ;
if ( V_40 == NULL )
goto V_61;
V_41 = ( V_40 -> V_48 == V_49 ) ? sizeof( struct V_50 ) : 0 ;
V_60 = V_52 +
sizeof( struct V_53 ) +
V_41 +
V_4 -> V_54 +
sizeof( V_38 ) ;
if ( F_39 ( V_10 , V_60 ) )
goto V_62;
F_40 ( V_10 , sizeof( V_38 ) ) ;
V_10 -> V_11 [ 0 ] = V_38 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_38 [ 1 ] ;
F_35 () ;
F_36 ( V_4 , V_10 , V_4 -> V_54 ) ;
F_37 () ;
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
static void F_41 ( struct V_1 * V_4 )
{
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_2 * V_3 = V_27 -> V_2 ;
struct V_12 * V_2 = V_3 -> V_63 ;
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
static int F_46 ( struct V_12 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
int error ;
if ( ! V_3 )
return 0 ;
error = - V_45 ;
F_47 ( V_3 ) ;
if ( F_27 ( V_3 , V_43 ) != 0 )
goto error;
F_48 ( V_3 ) ;
V_3 -> V_19 = V_64 ;
F_49 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != NULL ) {
F_50 ( V_4 ) ;
F_51 ( V_4 ) ;
F_3 ( V_3 ) ;
}
F_52 ( & V_3 -> V_65 ) ;
F_52 ( & V_3 -> V_66 ) ;
F_53 ( V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
error:
F_53 ( V_3 ) ;
return error ;
}
static int F_54 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
int V_67 ;
V_67 = F_55 ( V_3 , V_10 ) ;
if ( V_67 )
F_12 ( V_10 ) ;
return V_68 ;
}
static int F_56 ( struct V_69 * V_69 , struct V_12 * V_2 )
{
int error = - V_51 ;
struct V_2 * V_3 ;
V_3 = F_57 ( V_69 , V_70 , V_55 , & V_71 ) ;
if ( ! V_3 )
goto V_6;
F_58 ( V_2 , V_3 ) ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = & V_75 ;
V_3 -> V_76 = F_54 ;
V_3 -> V_77 = V_78 ;
V_3 -> V_79 = V_70 ;
V_3 -> V_19 = V_80 ;
V_3 -> V_81 = V_82 ;
V_3 -> V_83 = F_44 ;
error = 0 ;
V_6:
return error ;
}
static void F_59 ( struct V_84 * V_36 , void * V_85 )
{
struct V_1 * V_4 = V_85 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
if ( V_27 ) {
struct V_29 * V_30 = F_19 ( V_27 -> V_2 ) ;
if ( V_30 )
F_60 ( V_36 , L_4 , F_61 ( & V_30 -> V_33 ) ) ;
}
}
static int F_62 ( struct V_12 * V_2 , struct V_86 * V_87 ,
int V_88 , int V_16 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_89 * V_90 = (struct V_89 * ) V_87 ;
struct V_29 * V_30 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
struct V_91 * V_92 ;
struct V_93 V_94 = { 0 , } ;
int error = 0 ;
T_3 V_95 , V_96 ;
T_3 V_97 , V_98 ;
int V_99 = 2 ;
int V_100 ;
F_47 ( V_3 ) ;
error = - V_101 ;
if ( V_90 -> V_102 != V_78 )
goto V_21;
error = - V_103 ;
if ( V_3 -> V_19 & V_44 )
goto V_21;
error = - V_104 ;
if ( V_3 -> V_5 )
goto V_21;
V_96 = 0 ;
if ( V_88 == sizeof( struct V_89 ) ) {
V_100 = V_90 -> V_105 . V_100 ;
V_95 = V_90 -> V_105 . V_106 ;
V_96 = V_90 -> V_105 . V_107 ;
V_97 = V_90 -> V_105 . V_108 ;
V_98 = V_90 -> V_105 . V_109 ;
} else if ( V_88 == sizeof( struct V_110 ) ) {
struct V_110 * V_111 =
(struct V_110 * ) V_90 ;
V_99 = 3 ;
V_100 = V_111 -> V_105 . V_100 ;
V_95 = V_111 -> V_105 . V_106 ;
V_96 = V_111 -> V_105 . V_107 ;
V_97 = V_111 -> V_105 . V_108 ;
V_98 = V_111 -> V_105 . V_109 ;
} else if ( V_88 == sizeof( struct V_112 ) ) {
struct V_112 * V_113 =
(struct V_112 * ) V_90 ;
V_100 = V_113 -> V_105 . V_100 ;
V_95 = V_113 -> V_105 . V_106 ;
V_96 = V_113 -> V_105 . V_107 ;
V_97 = V_113 -> V_105 . V_108 ;
V_98 = V_113 -> V_105 . V_109 ;
} else if ( V_88 == sizeof( struct V_114 ) ) {
struct V_114 * V_113 =
(struct V_114 * ) V_90 ;
V_99 = 3 ;
V_100 = V_113 -> V_105 . V_100 ;
V_95 = V_113 -> V_105 . V_106 ;
V_96 = V_113 -> V_105 . V_107 ;
V_97 = V_113 -> V_105 . V_108 ;
V_98 = V_113 -> V_105 . V_109 ;
} else {
error = - V_101 ;
goto V_21;
}
error = - V_101 ;
if ( V_95 == 0 )
goto V_21;
V_40 = F_63 ( F_64 ( V_3 ) , V_95 ) ;
if ( ( V_97 == 0 ) && ( V_98 == 0 ) ) {
if ( V_40 == NULL ) {
struct V_115 V_116 = {
. V_48 = V_49 ,
. V_117 = 0 ,
} ;
error = F_65 ( F_64 ( V_3 ) , V_100 , V_99 , V_95 , V_96 , & V_116 , & V_40 ) ;
if ( error < 0 )
goto V_21;
}
} else {
error = - V_118 ;
if ( V_40 == NULL )
goto V_21;
if ( V_40 -> V_2 == NULL )
goto V_21;
}
if ( V_40 -> V_119 == NULL )
V_40 -> V_119 = F_5 ;
if ( V_40 -> V_96 == 0 )
V_40 -> V_96 = V_96 ;
V_4 = F_66 ( F_64 ( V_3 ) , V_40 , V_97 ) ;
if ( V_4 == NULL ) {
V_94 . V_120 = V_94 . V_121 = 1500 - V_122 ;
V_4 = F_67 ( sizeof( struct V_26 ) ,
V_40 , V_97 ,
V_98 , & V_94 ) ;
if ( V_4 == NULL ) {
error = - V_51 ;
goto V_21;
}
} else {
V_27 = F_14 ( V_4 ) ;
error = - V_123 ;
if ( V_27 -> V_2 != NULL )
goto V_21;
if ( V_27 -> V_46 != V_40 -> V_2 )
goto V_21;
}
V_27 = F_14 ( V_4 ) ;
V_27 -> V_124 = V_125 -> V_126 ;
V_27 -> V_2 = V_3 ;
V_27 -> V_46 = V_40 -> V_2 ;
V_4 -> V_127 = F_13 ;
V_4 -> V_128 = F_41 ;
#if F_68 ( V_129 ) || F_68 ( V_130 )
V_4 -> V_131 = F_59 ;
#endif
V_4 -> V_132 = F_24 ;
V_4 -> V_133 = F_25 ;
V_92 = F_69 ( V_40 -> V_2 ) ;
if ( V_92 != NULL ) {
T_3 V_134 = F_70 ( V_92 ) ;
if ( V_134 != 0 )
V_4 -> V_120 = V_4 -> V_121 = V_134 -
V_122 ;
F_71 ( V_92 ) ;
}
if ( ( V_4 -> V_97 == 0 ) &&
( V_4 -> V_98 == 0 ) ) {
error = 0 ;
goto V_135;
}
V_30 -> V_33 . V_136 = V_137 ;
V_30 -> V_33 . V_58 = V_3 ;
V_30 -> V_33 . V_74 = & V_138 ;
V_30 -> V_33 . V_120 = V_4 -> V_120 ;
error = F_72 ( F_64 ( V_3 ) , & V_30 -> V_33 ) ;
if ( error )
goto V_21;
V_135:
V_3 -> V_5 = V_4 ;
V_3 -> V_19 = V_44 ;
F_23 ( V_4 , V_139 , L_5 ,
V_4 -> V_32 ) ;
V_21:
F_53 ( V_3 ) ;
return error ;
}
static int F_73 ( struct V_69 * V_69 , T_3 V_95 , T_3 V_97 , T_3 V_98 , struct V_93 * V_94 )
{
int error ;
struct V_39 * V_40 ;
struct V_1 * V_4 ;
struct V_26 * V_27 ;
V_40 = F_63 ( V_69 , V_95 ) ;
error = - V_118 ;
if ( V_40 == NULL )
goto V_6;
if ( V_40 -> V_2 == NULL )
goto V_6;
error = - V_123 ;
V_4 = F_66 ( V_69 , V_40 , V_97 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_94 -> V_120 == 0 )
V_94 -> V_120 = 1500 - V_122 ;
if ( V_94 -> V_121 == 0 )
V_94 -> V_121 = V_94 -> V_120 ;
error = - V_51 ;
V_4 = F_67 ( sizeof( struct V_26 ) ,
V_40 , V_97 ,
V_98 , V_94 ) ;
if ( V_4 == NULL )
goto V_6;
V_27 = F_14 ( V_4 ) ;
V_27 -> V_46 = V_40 -> V_2 ;
F_23 ( V_4 , V_139 , L_5 ,
V_4 -> V_32 ) ;
error = 0 ;
V_6:
return error ;
}
static int F_74 ( struct V_12 * V_2 , struct V_86 * V_140 ,
int * V_141 , int V_142 )
{
int V_15 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_143 * V_144 ;
struct V_26 * V_145 ;
error = - V_42 ;
if ( V_3 == NULL )
goto V_21;
if ( V_3 -> V_19 != V_44 )
goto V_21;
error = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_145 = F_14 ( V_4 ) ;
V_40 = F_28 ( V_145 -> V_46 ) ;
if ( V_40 == NULL ) {
error = - V_45 ;
goto V_146;
}
V_144 = F_75 ( V_40 -> V_2 ) ;
if ( ( V_40 -> V_147 == 2 ) && ( V_40 -> V_2 -> V_79 == V_148 ) ) {
struct V_89 V_90 ;
V_15 = sizeof( V_90 ) ;
memset ( & V_90 , 0 , V_15 ) ;
V_90 . V_149 = V_150 ;
V_90 . V_102 = V_78 ;
V_90 . V_105 . V_100 = V_40 -> V_100 ;
V_90 . V_105 . V_126 = V_145 -> V_124 ;
V_90 . V_105 . V_106 = V_40 -> V_95 ;
V_90 . V_105 . V_107 = V_40 -> V_96 ;
V_90 . V_105 . V_108 = V_4 -> V_97 ;
V_90 . V_105 . V_109 = V_4 -> V_98 ;
V_90 . V_105 . V_151 . V_152 = V_148 ;
V_90 . V_105 . V_151 . V_153 = V_144 -> V_154 ;
V_90 . V_105 . V_151 . V_155 . V_156 = V_144 -> V_157 ;
memcpy ( V_140 , & V_90 , V_15 ) ;
#if F_76 ( V_158 )
} else if ( ( V_40 -> V_147 == 2 ) &&
( V_40 -> V_2 -> V_79 == V_159 ) ) {
struct V_112 V_90 ;
V_15 = sizeof( V_90 ) ;
memset ( & V_90 , 0 , V_15 ) ;
V_90 . V_149 = V_150 ;
V_90 . V_102 = V_78 ;
V_90 . V_105 . V_100 = V_40 -> V_100 ;
V_90 . V_105 . V_126 = V_145 -> V_124 ;
V_90 . V_105 . V_106 = V_40 -> V_95 ;
V_90 . V_105 . V_107 = V_40 -> V_96 ;
V_90 . V_105 . V_108 = V_4 -> V_97 ;
V_90 . V_105 . V_109 = V_4 -> V_98 ;
V_90 . V_105 . V_151 . V_160 = V_159 ;
V_90 . V_105 . V_151 . V_161 = V_144 -> V_154 ;
memcpy ( & V_90 . V_105 . V_151 . V_162 , & V_40 -> V_2 -> V_163 ,
sizeof( V_40 -> V_2 -> V_163 ) ) ;
memcpy ( V_140 , & V_90 , V_15 ) ;
} else if ( ( V_40 -> V_147 == 3 ) &&
( V_40 -> V_2 -> V_79 == V_159 ) ) {
struct V_114 V_90 ;
V_15 = sizeof( V_90 ) ;
memset ( & V_90 , 0 , V_15 ) ;
V_90 . V_149 = V_150 ;
V_90 . V_102 = V_78 ;
V_90 . V_105 . V_100 = V_40 -> V_100 ;
V_90 . V_105 . V_126 = V_145 -> V_124 ;
V_90 . V_105 . V_106 = V_40 -> V_95 ;
V_90 . V_105 . V_107 = V_40 -> V_96 ;
V_90 . V_105 . V_108 = V_4 -> V_97 ;
V_90 . V_105 . V_109 = V_4 -> V_98 ;
V_90 . V_105 . V_151 . V_160 = V_159 ;
V_90 . V_105 . V_151 . V_161 = V_144 -> V_154 ;
memcpy ( & V_90 . V_105 . V_151 . V_162 , & V_40 -> V_2 -> V_163 ,
sizeof( V_40 -> V_2 -> V_163 ) ) ;
memcpy ( V_140 , & V_90 , V_15 ) ;
#endif
} else if ( V_40 -> V_147 == 3 ) {
struct V_110 V_90 ;
V_15 = sizeof( V_90 ) ;
memset ( & V_90 , 0 , V_15 ) ;
V_90 . V_149 = V_150 ;
V_90 . V_102 = V_78 ;
V_90 . V_105 . V_100 = V_40 -> V_100 ;
V_90 . V_105 . V_126 = V_145 -> V_124 ;
V_90 . V_105 . V_106 = V_40 -> V_95 ;
V_90 . V_105 . V_107 = V_40 -> V_96 ;
V_90 . V_105 . V_108 = V_4 -> V_97 ;
V_90 . V_105 . V_109 = V_4 -> V_98 ;
V_90 . V_105 . V_151 . V_152 = V_148 ;
V_90 . V_105 . V_151 . V_153 = V_144 -> V_154 ;
V_90 . V_105 . V_151 . V_155 . V_156 = V_144 -> V_157 ;
memcpy ( V_140 , & V_90 , V_15 ) ;
}
* V_141 = V_15 ;
F_3 ( V_145 -> V_46 ) ;
V_146:
F_3 ( V_3 ) ;
error = 0 ;
V_21:
return error ;
}
static void F_77 ( struct V_164 * V_165 ,
struct V_166 * V_34 )
{
V_165 -> V_167 = F_78 ( & V_34 -> V_167 ) ;
V_165 -> V_168 = F_78 ( & V_34 -> V_168 ) ;
V_165 -> V_169 = F_78 ( & V_34 -> V_169 ) ;
V_165 -> V_170 = F_78 ( & V_34 -> V_170 ) ;
V_165 -> V_171 = F_78 ( & V_34 -> V_171 ) ;
V_165 -> V_172 = F_78 ( & V_34 -> V_172 ) ;
V_165 -> V_173 = F_78 ( & V_34 -> V_173 ) ;
V_165 -> V_35 = F_78 ( & V_34 -> V_35 ) ;
}
static int F_79 ( struct V_1 * V_4 ,
unsigned int V_174 , unsigned long V_85 )
{
struct V_175 V_176 ;
int V_17 = 0 ;
struct V_2 * V_3 ;
int V_177 = ( int ) V_85 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_39 * V_40 = V_4 -> V_40 ;
struct V_164 V_34 ;
F_15 ( V_4 , V_139 ,
L_6 ,
V_4 -> V_32 , V_174 , V_85 ) ;
V_3 = V_27 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_174 ) {
case V_178 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_180 ;
if ( F_80 ( & V_176 , ( void V_181 * ) V_85 , sizeof( struct V_175 ) ) )
break;
V_176 . V_182 = V_4 -> V_120 ;
if ( F_81 ( ( void V_181 * ) V_85 , & V_176 , sizeof( struct V_175 ) ) )
break;
F_23 ( V_4 , V_139 , L_7 ,
V_4 -> V_32 , V_4 -> V_120 ) ;
V_17 = 0 ;
break;
case V_183 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_180 ;
if ( F_80 ( & V_176 , ( void V_181 * ) V_85 , sizeof( struct V_175 ) ) )
break;
V_4 -> V_120 = V_176 . V_182 ;
F_23 ( V_4 , V_139 , L_8 ,
V_4 -> V_32 , V_4 -> V_120 ) ;
V_17 = 0 ;
break;
case V_184 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_180 ;
if ( F_82 ( V_4 -> V_121 , ( int V_181 * ) V_85 ) )
break;
F_23 ( V_4 , V_139 , L_9 ,
V_4 -> V_32 , V_4 -> V_121 ) ;
V_17 = 0 ;
break;
case V_185 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
V_17 = - V_180 ;
if ( F_83 ( V_177 , ( int V_181 * ) V_85 ) )
break;
V_4 -> V_121 = V_177 ;
F_23 ( V_4 , V_139 , L_10 ,
V_4 -> V_32 , V_4 -> V_121 ) ;
V_17 = 0 ;
break;
case V_186 :
V_17 = - V_180 ;
if ( F_82 ( V_27 -> V_16 , ( int V_181 * ) V_85 ) )
break;
F_23 ( V_4 , V_139 , L_11 ,
V_4 -> V_32 , V_27 -> V_16 ) ;
V_17 = 0 ;
break;
case V_187 :
V_17 = - V_180 ;
if ( F_83 ( V_177 , ( int V_181 * ) V_85 ) )
break;
V_27 -> V_16 = V_177 ;
F_23 ( V_4 , V_139 , L_12 ,
V_4 -> V_32 , V_27 -> V_16 ) ;
V_17 = 0 ;
break;
case V_188 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_95 = V_40 -> V_95 ;
V_34 . V_97 = V_4 -> V_97 ;
F_77 ( & V_34 , & V_4 -> V_34 ) ;
if ( F_81 ( ( void V_181 * ) V_85 , & V_34 ,
sizeof( V_34 ) ) )
break;
F_23 ( V_4 , V_139 , L_13 ,
V_4 -> V_32 ) ;
V_17 = 0 ;
break;
default:
V_17 = - V_189 ;
break;
}
F_3 ( V_3 ) ;
return V_17 ;
}
static int F_84 ( struct V_39 * V_40 ,
unsigned int V_174 , unsigned long V_85 )
{
int V_17 = 0 ;
struct V_2 * V_3 ;
struct V_164 V_34 ;
F_15 ( V_40 , V_139 ,
L_14 ,
V_40 -> V_32 , V_174 , V_85 ) ;
V_3 = V_40 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_174 ) {
case V_188 :
V_17 = - V_179 ;
if ( ! ( V_3 -> V_19 & V_44 ) )
break;
if ( F_80 ( & V_34 , ( void V_181 * ) V_85 ,
sizeof( V_34 ) ) ) {
V_17 = - V_180 ;
break;
}
if ( V_34 . V_97 != 0 ) {
struct V_1 * V_4 =
F_66 ( F_64 ( V_3 ) , V_40 , V_34 . V_97 ) ;
if ( V_4 != NULL )
V_17 = F_79 ( V_4 , V_174 , V_85 ) ;
else
V_17 = - V_190 ;
break;
}
#ifdef F_85
V_34 . V_191 = ( V_3 -> V_192 [ 0 ] || V_3 -> V_192 [ 1 ] ) ? 1 : 0 ;
#endif
F_77 ( & V_34 , & V_40 -> V_34 ) ;
if ( F_81 ( ( void V_181 * ) V_85 , & V_34 , sizeof( V_34 ) ) ) {
V_17 = - V_180 ;
break;
}
F_23 ( V_40 , V_139 , L_13 ,
V_40 -> V_32 ) ;
V_17 = 0 ;
break;
default:
V_17 = - V_189 ;
break;
}
F_3 ( V_3 ) ;
return V_17 ;
}
static int F_86 ( struct V_12 * V_2 , unsigned int V_174 ,
unsigned long V_85 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_17 ;
if ( ! V_3 )
return 0 ;
V_17 = - V_45 ;
if ( F_27 ( V_3 , V_43 ) != 0 )
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
if ( ( V_4 -> V_97 == 0 ) &&
( V_4 -> V_98 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_28 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_146;
V_17 = F_84 ( V_40 , V_174 , V_85 ) ;
F_3 ( V_27 -> V_46 ) ;
goto V_146;
}
V_17 = F_79 ( V_4 , V_174 , V_85 ) ;
V_146:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int V_193 , int V_177 )
{
int V_17 = 0 ;
switch ( V_193 ) {
case V_194 :
V_40 -> V_117 = V_177 ;
F_23 ( V_40 , V_139 , L_15 ,
V_40 -> V_32 , V_40 -> V_117 ) ;
break;
default:
V_17 = - V_195 ;
break;
}
return V_17 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_193 , int V_177 )
{
int V_17 = 0 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
switch ( V_193 ) {
case V_196 :
if ( ( V_177 != 0 ) && ( V_177 != 1 ) ) {
V_17 = - V_101 ;
break;
}
V_4 -> V_197 = V_177 ? - 1 : 0 ;
F_23 ( V_4 , V_139 ,
L_16 ,
V_4 -> V_32 , V_4 -> V_197 ) ;
break;
case V_198 :
if ( ( V_177 != 0 ) && ( V_177 != 1 ) ) {
V_17 = - V_101 ;
break;
}
V_4 -> V_199 = V_177 ? - 1 : 0 ;
{
struct V_2 * V_200 = V_27 -> V_2 ;
struct V_29 * V_30 = F_19 ( V_200 ) ;
V_30 -> V_33 . V_136 = V_177 ? V_201 :
V_137 ;
}
F_89 ( V_4 , V_4 -> V_40 -> V_147 ) ;
F_23 ( V_4 , V_139 ,
L_17 ,
V_4 -> V_32 , V_4 -> V_199 ) ;
break;
case V_202 :
if ( ( V_177 != 0 ) && ( V_177 != 1 ) ) {
V_17 = - V_101 ;
break;
}
V_4 -> V_203 = V_177 ? - 1 : 0 ;
F_23 ( V_4 , V_139 ,
L_18 ,
V_4 -> V_32 , V_4 -> V_203 ) ;
break;
case V_194 :
V_4 -> V_117 = V_177 ;
F_23 ( V_4 , V_139 , L_15 ,
V_4 -> V_32 , V_4 -> V_117 ) ;
break;
case V_204 :
V_4 -> V_205 = F_90 ( V_177 ) ;
F_23 ( V_4 , V_139 ,
L_19 ,
V_4 -> V_32 , V_4 -> V_205 ) ;
break;
default:
V_17 = - V_195 ;
break;
}
return V_17 ;
}
static int F_91 ( struct V_12 * V_2 , int V_206 , int V_193 ,
char V_181 * V_207 , unsigned int V_208 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
int V_177 ;
int V_17 ;
if ( V_206 != V_209 )
return - V_101 ;
if ( V_208 < sizeof( int ) )
return - V_101 ;
if ( F_83 ( V_177 , ( int V_181 * ) V_207 ) )
return - V_180 ;
V_17 = - V_42 ;
if ( V_3 -> V_5 == NULL )
goto V_21;
V_17 = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_27 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_97 == 0 ) &&
( V_4 -> V_98 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_28 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_146;
V_17 = F_87 ( V_3 , V_40 , V_193 , V_177 ) ;
F_3 ( V_27 -> V_46 ) ;
} else
V_17 = F_88 ( V_3 , V_4 , V_193 , V_177 ) ;
V_17 = 0 ;
V_146:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int V_193 , int * V_177 )
{
int V_17 = 0 ;
switch ( V_193 ) {
case V_194 :
* V_177 = V_40 -> V_117 ;
F_23 ( V_40 , V_139 , L_20 ,
V_40 -> V_32 , V_40 -> V_117 ) ;
break;
default:
V_17 = - V_195 ;
break;
}
return V_17 ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_193 , int * V_177 )
{
int V_17 = 0 ;
switch ( V_193 ) {
case V_196 :
* V_177 = V_4 -> V_197 ;
F_23 ( V_4 , V_139 ,
L_21 , V_4 -> V_32 , * V_177 ) ;
break;
case V_198 :
* V_177 = V_4 -> V_199 ;
F_23 ( V_4 , V_139 ,
L_22 , V_4 -> V_32 , * V_177 ) ;
break;
case V_202 :
* V_177 = V_4 -> V_203 ;
F_23 ( V_4 , V_139 ,
L_23 , V_4 -> V_32 , * V_177 ) ;
break;
case V_194 :
* V_177 = V_4 -> V_117 ;
F_23 ( V_4 , V_139 , L_24 ,
V_4 -> V_32 , * V_177 ) ;
break;
case V_204 :
* V_177 = ( int ) F_94 ( V_4 -> V_205 ) ;
F_23 ( V_4 , V_139 ,
L_25 , V_4 -> V_32 , * V_177 ) ;
break;
default:
V_17 = - V_195 ;
}
return V_17 ;
}
static int F_95 ( struct V_12 * V_2 , int V_206 , int V_193 ,
char V_181 * V_207 , int V_181 * V_208 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
int V_177 , V_15 ;
int V_17 ;
struct V_26 * V_27 ;
if ( V_206 != V_209 )
return - V_101 ;
if ( F_83 ( V_15 , V_208 ) )
return - V_180 ;
V_15 = F_96 (unsigned int, len, sizeof(int)) ;
if ( V_15 < 0 )
return - V_101 ;
V_17 = - V_42 ;
if ( V_3 -> V_5 == NULL )
goto V_21;
V_17 = - V_45 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_21;
V_27 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_97 == 0 ) &&
( V_4 -> V_98 == 0 ) ) {
V_17 = - V_45 ;
V_40 = F_28 ( V_27 -> V_46 ) ;
if ( V_40 == NULL )
goto V_146;
V_17 = F_92 ( V_3 , V_40 , V_193 , & V_177 ) ;
F_3 ( V_27 -> V_46 ) ;
} else
V_17 = F_93 ( V_3 , V_4 , V_193 , & V_177 ) ;
V_17 = - V_180 ;
if ( F_82 ( V_15 , V_208 ) )
goto V_146;
if ( F_81 ( ( void V_181 * ) V_207 , & V_177 , V_15 ) )
goto V_146;
V_17 = 0 ;
V_146:
F_3 ( V_3 ) ;
V_21:
return V_17 ;
}
static void F_97 ( struct V_69 * V_69 , struct V_210 * V_211 )
{
for (; ; ) {
V_211 -> V_40 = F_98 ( V_69 , V_211 -> V_212 ) ;
V_211 -> V_212 ++ ;
if ( V_211 -> V_40 == NULL )
break;
if ( V_211 -> V_40 -> V_147 < 3 )
break;
}
}
static void F_99 ( struct V_69 * V_69 , struct V_210 * V_211 )
{
V_211 -> V_4 = F_100 ( V_211 -> V_40 , V_211 -> V_213 ) ;
V_211 -> V_213 ++ ;
if ( V_211 -> V_4 == NULL ) {
V_211 -> V_213 = 0 ;
F_97 ( V_69 , V_211 ) ;
}
}
static void * F_101 ( struct V_84 * V_36 , T_4 * V_214 )
{
struct V_210 * V_211 = V_215 ;
T_4 V_216 = * V_214 ;
struct V_69 * V_69 ;
if ( ! V_216 )
goto V_6;
F_4 ( V_36 -> V_58 == NULL ) ;
V_211 = V_36 -> V_58 ;
V_69 = F_102 ( V_36 ) ;
if ( V_211 -> V_40 == NULL )
F_97 ( V_69 , V_211 ) ;
else
F_99 ( V_69 , V_211 ) ;
if ( ( V_211 -> V_40 == NULL ) && ( V_211 -> V_4 == NULL ) )
V_211 = NULL ;
V_6:
return V_211 ;
}
static void * F_103 ( struct V_84 * V_36 , void * V_217 , T_4 * V_216 )
{
( * V_216 ) ++ ;
return NULL ;
}
static void F_104 ( struct V_84 * V_218 , void * V_217 )
{
}
static void F_105 ( struct V_84 * V_36 , void * V_217 )
{
struct V_39 * V_40 = V_217 ;
F_60 ( V_36 , L_26 ,
V_40 -> V_32 ,
( V_40 == V_40 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_106 ( & V_40 -> V_219 ) - 1 ) ;
F_60 ( V_36 , L_27 ,
V_40 -> V_117 ,
F_78 ( & V_40 -> V_34 . V_167 ) ,
F_78 ( & V_40 -> V_34 . V_168 ) ,
F_78 ( & V_40 -> V_34 . V_169 ) ,
F_78 ( & V_40 -> V_34 . V_170 ) ,
F_78 ( & V_40 -> V_34 . V_171 ) ,
F_78 ( & V_40 -> V_34 . V_35 ) ) ;
}
static void F_107 ( struct V_84 * V_36 , void * V_217 )
{
struct V_1 * V_4 = V_217 ;
struct V_39 * V_40 = V_4 -> V_40 ;
struct V_26 * V_27 = F_14 ( V_4 ) ;
struct V_29 * V_30 = F_19 ( V_27 -> V_2 ) ;
T_3 V_220 = 0 ;
T_5 V_221 = 0 ;
if ( V_40 -> V_2 ) {
struct V_143 * V_144 = F_75 ( V_40 -> V_2 ) ;
V_220 = F_108 ( V_144 -> V_222 ) ;
V_221 = F_109 ( V_144 -> V_223 ) ;
}
F_60 ( V_36 , L_28
L_29 ,
V_4 -> V_32 , V_220 , V_221 ,
V_40 -> V_95 ,
V_4 -> V_97 ,
V_40 -> V_96 ,
V_4 -> V_98 ,
V_27 -> V_2 -> V_19 ,
( V_4 == V_27 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_60 ( V_36 , L_30 ,
V_4 -> V_120 , V_4 -> V_121 ,
V_4 -> V_197 ? 'R' : '-' ,
V_4 -> V_199 ? 'S' : '-' ,
V_4 -> V_203 ? L_31 : L_32 ,
V_4 -> V_117 ,
F_94 ( V_4 -> V_205 ) ) ;
F_60 ( V_36 , L_33 ,
V_4 -> V_224 , V_4 -> V_225 ,
F_78 ( & V_4 -> V_34 . V_167 ) ,
F_78 ( & V_4 -> V_34 . V_168 ) ,
F_78 ( & V_4 -> V_34 . V_169 ) ,
F_78 ( & V_4 -> V_34 . V_170 ) ,
F_78 ( & V_4 -> V_34 . V_171 ) ,
F_78 ( & V_4 -> V_34 . V_35 ) ) ;
if ( V_30 )
F_60 ( V_36 , L_4 , F_61 ( & V_30 -> V_33 ) ) ;
}
static int F_110 ( struct V_84 * V_36 , void * V_217 )
{
struct V_210 * V_211 = V_217 ;
if ( V_217 == V_215 ) {
F_111 ( V_36 , L_34 V_226 L_35 ) ;
F_111 ( V_36 , L_36 ) ;
F_111 ( V_36 , L_37 ) ;
F_111 ( V_36 , L_38
L_39 ) ;
F_111 ( V_36 , L_40 ) ;
F_111 ( V_36 , L_41 ) ;
goto V_6;
}
if ( V_211 -> V_4 == NULL )
F_105 ( V_36 , V_211 -> V_40 ) ;
else
F_107 ( V_36 , V_211 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_112 ( struct V_227 * V_227 , struct V_228 * V_228 )
{
return F_113 ( V_227 , V_228 , & V_229 ,
sizeof( struct V_210 ) ) ;
}
static T_6 int F_114 ( struct V_69 * V_69 )
{
struct V_230 * V_231 ;
int V_17 = 0 ;
V_231 = F_115 ( L_42 , V_232 , V_69 -> V_233 ,
& V_234 ) ;
if ( ! V_231 ) {
V_17 = - V_51 ;
goto V_6;
}
V_6:
return V_17 ;
}
static T_7 void F_116 ( struct V_69 * V_69 )
{
F_117 ( L_42 , V_69 -> V_233 ) ;
}
static int T_8 F_118 ( void )
{
int V_17 ;
V_17 = F_119 ( & V_235 ) ;
if ( V_17 )
goto V_6;
V_17 = F_120 ( & V_71 , 0 ) ;
if ( V_17 )
goto V_236;
V_17 = F_121 ( V_78 , & V_237 ) ;
if ( V_17 )
goto V_238;
#ifdef F_122
V_17 = F_123 ( V_239 , & V_240 ) ;
if ( V_17 )
goto V_241;
#endif
F_124 ( L_43 , V_226 ) ;
V_6:
return V_17 ;
#ifdef F_122
V_241:
F_125 ( V_78 ) ;
#endif
V_238:
F_126 ( & V_71 ) ;
V_236:
F_127 ( & V_235 ) ;
goto V_6;
}
static void T_9 F_128 ( void )
{
#ifdef F_122
F_129 ( V_239 ) ;
#endif
F_125 ( V_78 ) ;
F_126 ( & V_71 ) ;
F_127 ( & V_235 ) ;
}
