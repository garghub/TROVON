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
F_15 ( V_4 -> V_35 , V_36 , V_37 ,
L_1 ,
V_4 -> V_38 , V_29 ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_34 = F_19 ( V_3 ) ;
F_20 ( & V_34 -> V_39 , V_10 ) ;
} else {
F_15 ( V_4 -> V_35 , V_36 , V_40 ,
L_2 , V_4 -> V_38 ) ;
V_4 -> V_41 . V_42 ++ ;
F_12 ( V_10 ) ;
}
return;
V_32:
F_15 ( V_4 -> V_35 , V_36 , V_40 ,
L_3 , V_4 -> V_38 ) ;
F_12 ( V_10 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_2 ( V_31 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 -> V_2 )
F_3 ( V_31 -> V_2 ) ;
}
static int F_23 ( struct V_12 * V_13 , struct V_14 * V_2 , struct V_15 * V_43 ,
T_1 V_44 )
{
static const unsigned char V_45 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 ;
int error ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
int V_48 ;
error = - V_49 ;
if ( F_24 ( V_3 , V_50 ) || ! ( V_3 -> V_21 & V_51 ) )
goto error;
error = - V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto error;
V_31 = F_14 ( V_4 ) ;
V_47 = F_25 ( V_31 -> V_53 ) ;
if ( V_47 == NULL )
goto V_54;
V_48 = ( V_47 -> V_55 == V_56 ) ? sizeof( struct V_57 ) : 0 ;
error = - V_58 ;
V_10 = F_26 ( V_3 , V_59 + sizeof( struct V_60 ) +
V_48 + V_4 -> V_61 +
sizeof( V_45 ) + V_44 ,
0 , V_62 ) ;
if ( ! V_10 )
goto V_63;
F_27 ( V_10 , V_59 ) ;
F_28 ( V_10 ) ;
F_27 ( V_10 , sizeof( struct V_60 ) ) ;
F_29 ( V_10 ) ;
F_27 ( V_10 , V_48 ) ;
V_10 -> V_11 [ 0 ] = V_45 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_45 [ 1 ] ;
F_30 ( V_10 , 2 ) ;
error = F_31 ( V_10 -> V_11 , V_43 -> V_28 , V_44 ) ;
if ( error < 0 ) {
F_12 ( V_10 ) ;
goto V_63;
}
F_30 ( V_10 , V_44 ) ;
F_32 ( V_4 , V_10 , V_4 -> V_61 ) ;
F_3 ( V_31 -> V_53 ) ;
return error ;
V_63:
F_3 ( V_31 -> V_53 ) ;
V_54:
F_3 ( V_3 ) ;
error:
return error ;
}
static int F_33 ( struct V_64 * V_39 , struct V_9 * V_10 )
{
static const T_2 V_45 [ 2 ] = { 0xff , 0x03 } ;
struct V_2 * V_3 = (struct V_2 * ) V_39 -> V_65 ;
struct V_2 * V_66 ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
int V_67 ;
int V_68 ;
int V_48 , V_69 ;
if ( F_24 ( V_3 , V_50 ) || ! ( V_3 -> V_21 & V_51 ) )
goto abort;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto abort;
V_31 = F_14 ( V_4 ) ;
V_66 = V_31 -> V_53 ;
if ( V_66 == NULL )
goto V_70;
V_47 = F_25 ( V_66 ) ;
if ( V_47 == NULL )
goto V_70;
V_67 = F_34 ( V_10 ) ;
V_48 = ( V_47 -> V_55 == V_56 ) ? sizeof( struct V_57 ) : 0 ;
V_69 = V_59 +
sizeof( struct V_60 ) +
V_48 +
V_4 -> V_61 +
sizeof( V_45 ) ;
if ( F_35 ( V_10 , V_69 ) )
goto V_71;
V_68 = F_34 ( V_10 ) ;
V_10 -> V_72 += V_68 - V_67 ;
F_36 ( V_10 , sizeof( V_45 ) ) ;
V_10 -> V_11 [ 0 ] = V_45 [ 0 ] ;
V_10 -> V_11 [ 1 ] = V_45 [ 1 ] ;
F_32 ( V_4 , V_10 , V_4 -> V_61 ) ;
F_3 ( V_66 ) ;
F_3 ( V_3 ) ;
return 1 ;
V_71:
F_3 ( V_66 ) ;
V_70:
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
if ( V_4 -> V_73 == 0 )
goto V_6;
if ( V_3 != NULL ) {
F_38 ( V_3 ) ;
if ( V_3 -> V_21 & ( V_51 | V_22 ) ) {
F_39 ( V_3 ) ;
V_3 -> V_21 = V_74 ;
V_3 -> V_75 ( V_3 ) ;
}
F_40 ( & V_3 -> V_76 ) ;
F_40 ( & V_3 -> V_77 ) ;
while ( ( V_10 = F_41 ( & V_4 -> V_78 ) ) ) {
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
error = - V_52 ;
F_38 ( V_3 ) ;
if ( F_24 ( V_3 , V_50 ) != 0 )
goto error;
F_39 ( V_3 ) ;
V_3 -> V_21 = V_74 ;
F_46 ( V_3 ) ;
V_2 -> V_3 = NULL ;
V_4 = F_1 ( V_3 ) ;
F_40 ( & V_3 -> V_76 ) ;
F_40 ( & V_3 -> V_77 ) ;
if ( V_4 != NULL ) {
struct V_9 * V_10 ;
while ( ( V_10 = F_41 ( & V_4 -> V_78 ) ) ) {
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
int V_79 ;
V_79 = F_48 ( V_3 , V_10 ) ;
if ( V_79 )
F_12 ( V_10 ) ;
return V_80 ;
}
static int F_49 ( struct V_81 * V_81 , struct V_14 * V_2 )
{
int error = - V_58 ;
struct V_2 * V_3 ;
V_3 = F_50 ( V_81 , V_82 , V_62 , & V_83 ) ;
if ( ! V_3 )
goto V_6;
F_51 ( V_2 , V_3 ) ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = & V_87 ;
V_3 -> V_88 = F_47 ;
V_3 -> V_89 = V_90 ;
V_3 -> V_91 = V_82 ;
V_3 -> V_21 = V_92 ;
V_3 -> V_93 = V_94 ;
V_3 -> V_95 = F_43 ;
error = 0 ;
V_6:
return error ;
}
static void F_52 ( struct V_96 * V_43 , void * V_97 )
{
struct V_1 * V_4 = V_97 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
if ( V_31 ) {
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
if ( V_34 )
F_53 ( V_43 , L_4 , F_54 ( & V_34 -> V_39 ) ) ;
}
}
static int F_55 ( struct V_14 * V_2 , struct V_98 * V_99 ,
int V_100 , int V_18 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 ;
struct V_103 * V_104 = (struct V_103 * ) V_99 ;
struct V_33 * V_34 = F_19 ( V_3 ) ;
struct V_1 * V_4 = NULL ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
struct V_105 * V_106 ;
struct V_107 V_108 = { 0 , } ;
int error = 0 ;
T_3 V_109 , V_110 ;
T_3 V_73 , V_111 ;
int V_112 = 2 ;
int V_113 ;
F_38 ( V_3 ) ;
error = - V_114 ;
if ( V_102 -> V_115 != V_90 )
goto V_23;
error = - V_116 ;
if ( V_3 -> V_21 & V_51 )
goto V_23;
error = - V_117 ;
if ( V_3 -> V_5 )
goto V_23;
if ( V_100 == sizeof( struct V_101 ) ) {
V_113 = V_102 -> V_118 . V_113 ;
V_109 = V_102 -> V_118 . V_119 ;
V_110 = V_102 -> V_118 . V_120 ;
V_73 = V_102 -> V_118 . V_121 ;
V_111 = V_102 -> V_118 . V_122 ;
} else if ( V_100 == sizeof( struct V_103 ) ) {
V_112 = 3 ;
V_113 = V_104 -> V_118 . V_113 ;
V_109 = V_104 -> V_118 . V_119 ;
V_110 = V_104 -> V_118 . V_120 ;
V_73 = V_104 -> V_118 . V_121 ;
V_111 = V_104 -> V_118 . V_122 ;
} else {
error = - V_114 ;
goto V_23;
}
error = - V_114 ;
if ( V_109 == 0 )
goto V_23;
V_47 = F_56 ( F_57 ( V_3 ) , V_109 ) ;
if ( ( V_73 == 0 ) && ( V_111 == 0 ) ) {
if ( V_47 == NULL ) {
struct V_123 V_124 = {
. V_55 = V_56 ,
. V_35 = 0 ,
} ;
error = F_58 ( F_57 ( V_3 ) , V_113 , V_112 , V_109 , V_110 , & V_124 , & V_47 ) ;
if ( error < 0 )
goto V_23;
}
} else {
error = - V_125 ;
if ( V_47 == NULL )
goto V_23;
if ( V_47 -> V_2 == NULL )
goto V_23;
}
if ( V_47 -> V_126 == NULL )
V_47 -> V_126 = F_5 ;
if ( V_47 -> V_110 == 0 ) {
if ( V_112 == 2 )
V_47 -> V_110 = V_102 -> V_118 . V_120 ;
else
V_47 -> V_110 = V_104 -> V_118 . V_120 ;
}
V_4 = F_59 ( F_57 ( V_3 ) , V_47 , V_73 ) ;
if ( V_4 == NULL ) {
V_108 . V_127 = V_108 . V_128 = 1500 - V_129 ;
V_4 = F_60 ( sizeof( struct V_30 ) ,
V_47 , V_73 ,
V_111 , & V_108 ) ;
if ( V_4 == NULL ) {
error = - V_58 ;
goto V_23;
}
} else {
V_31 = F_14 ( V_4 ) ;
error = - V_130 ;
if ( V_31 -> V_2 != NULL )
goto V_23;
if ( V_31 -> V_53 != V_47 -> V_2 )
goto V_23;
}
V_31 = F_14 ( V_4 ) ;
V_31 -> V_131 = V_132 -> V_133 ;
V_31 -> V_2 = V_3 ;
V_31 -> V_53 = V_47 -> V_2 ;
V_4 -> V_134 = F_13 ;
V_4 -> V_135 = F_37 ;
#if F_61 ( V_136 ) || F_61 ( V_137 )
V_4 -> V_138 = F_52 ;
#endif
V_4 -> V_139 = F_21 ;
V_4 -> V_140 = F_22 ;
V_106 = F_62 ( V_3 ) ;
if ( V_106 != NULL ) {
T_3 V_141 = F_63 ( F_64 ( V_3 ) ) ;
if ( V_141 != 0 )
V_4 -> V_127 = V_4 -> V_128 = V_141 -
V_129 ;
F_65 ( V_106 ) ;
}
if ( ( V_4 -> V_73 == 0 ) &&
( V_4 -> V_111 == 0 ) ) {
error = 0 ;
goto V_142;
}
V_34 -> V_39 . V_143 = V_144 ;
V_34 -> V_39 . V_65 = V_3 ;
V_34 -> V_39 . V_86 = & V_145 ;
V_34 -> V_39 . V_127 = V_4 -> V_127 ;
error = F_66 ( F_57 ( V_3 ) , & V_34 -> V_39 ) ;
if ( error )
goto V_23;
V_142:
V_3 -> V_5 = V_4 ;
V_3 -> V_21 = V_51 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_5 , V_4 -> V_38 ) ;
V_23:
F_42 ( V_3 ) ;
return error ;
}
static int F_67 ( struct V_81 * V_81 , T_3 V_109 , T_3 V_73 , T_3 V_111 , struct V_107 * V_108 )
{
int error ;
struct V_46 * V_47 ;
struct V_1 * V_4 ;
struct V_30 * V_31 ;
V_47 = F_56 ( V_81 , V_109 ) ;
error = - V_125 ;
if ( V_47 == NULL )
goto V_6;
if ( V_47 -> V_2 == NULL )
goto V_6;
error = - V_130 ;
V_4 = F_59 ( V_81 , V_47 , V_73 ) ;
if ( V_4 != NULL )
goto V_6;
if ( V_108 -> V_127 == 0 )
V_108 -> V_127 = 1500 - V_129 ;
if ( V_108 -> V_128 == 0 )
V_108 -> V_128 = V_108 -> V_127 ;
error = - V_58 ;
V_4 = F_60 ( sizeof( struct V_30 ) ,
V_47 , V_73 ,
V_111 , V_108 ) ;
if ( V_4 == NULL )
goto V_6;
V_31 = F_14 ( V_4 ) ;
V_31 -> V_53 = V_47 -> V_2 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_5 , V_4 -> V_38 ) ;
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
static int F_69 ( struct V_14 * V_2 , struct V_98 * V_147 ,
int * V_148 , int V_149 )
{
int V_17 = 0 ;
int error = 0 ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_150 * V_151 ;
struct V_30 * V_152 ;
error = - V_49 ;
if ( V_3 == NULL )
goto V_23;
if ( V_3 -> V_21 != V_51 )
goto V_23;
error = - V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_152 = F_14 ( V_4 ) ;
V_47 = F_25 ( V_152 -> V_53 ) ;
if ( V_47 == NULL ) {
error = - V_52 ;
goto V_153;
}
V_151 = F_70 ( V_47 -> V_2 ) ;
if ( V_47 -> V_154 == 2 ) {
struct V_101 V_102 ;
V_17 = sizeof( V_102 ) ;
memset ( & V_102 , 0 , V_17 ) ;
V_102 . V_155 = V_156 ;
V_102 . V_115 = V_90 ;
V_102 . V_118 . V_113 = V_47 -> V_113 ;
V_102 . V_118 . V_133 = V_152 -> V_131 ;
V_102 . V_118 . V_119 = V_47 -> V_109 ;
V_102 . V_118 . V_120 = V_47 -> V_110 ;
V_102 . V_118 . V_121 = V_4 -> V_73 ;
V_102 . V_118 . V_122 = V_4 -> V_111 ;
V_102 . V_118 . V_157 . V_158 = V_159 ;
V_102 . V_118 . V_157 . V_160 = V_151 -> V_161 ;
V_102 . V_118 . V_157 . V_162 . V_163 = V_151 -> V_164 ;
memcpy ( V_147 , & V_102 , V_17 ) ;
} else if ( V_47 -> V_154 == 3 ) {
struct V_103 V_102 ;
V_17 = sizeof( V_102 ) ;
memset ( & V_102 , 0 , V_17 ) ;
V_102 . V_155 = V_156 ;
V_102 . V_115 = V_90 ;
V_102 . V_118 . V_113 = V_47 -> V_113 ;
V_102 . V_118 . V_133 = V_152 -> V_131 ;
V_102 . V_118 . V_119 = V_47 -> V_109 ;
V_102 . V_118 . V_120 = V_47 -> V_110 ;
V_102 . V_118 . V_121 = V_4 -> V_73 ;
V_102 . V_118 . V_122 = V_4 -> V_111 ;
V_102 . V_118 . V_157 . V_158 = V_159 ;
V_102 . V_118 . V_157 . V_160 = V_151 -> V_161 ;
V_102 . V_118 . V_157 . V_162 . V_163 = V_151 -> V_164 ;
memcpy ( V_147 , & V_102 , V_17 ) ;
}
* V_148 = V_17 ;
F_3 ( V_152 -> V_53 ) ;
V_153:
F_3 ( V_3 ) ;
error = 0 ;
V_23:
return error ;
}
static void F_71 ( struct V_165 * V_166 ,
struct V_167 * V_41 )
{
V_166 -> V_168 = V_41 -> V_168 ;
V_166 -> V_169 = V_41 -> V_169 ;
V_166 -> V_170 = V_41 -> V_170 ;
V_166 -> V_171 = V_41 -> V_171 ;
V_166 -> V_172 = V_41 -> V_172 ;
V_166 -> V_173 = V_41 -> V_173 ;
V_166 -> V_174 = V_41 -> V_174 ;
V_166 -> V_42 = V_41 -> V_42 ;
}
static int F_72 ( struct V_1 * V_4 ,
unsigned int V_175 , unsigned long V_97 )
{
struct V_176 V_177 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_178 = ( int ) V_97 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_46 * V_47 = V_4 -> V_47 ;
struct V_165 V_41 ;
F_15 ( V_4 -> V_35 , V_146 , V_37 ,
L_6 ,
V_4 -> V_38 , V_175 , V_97 ) ;
V_3 = V_31 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_175 ) {
case V_179 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
V_19 = - V_181 ;
if ( F_73 ( & V_177 , ( void V_182 * ) V_97 , sizeof( struct V_176 ) ) )
break;
V_177 . V_183 = V_4 -> V_127 ;
if ( F_74 ( ( void V_182 * ) V_97 , & V_177 , sizeof( struct V_176 ) ) )
break;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_7 , V_4 -> V_38 , V_4 -> V_127 ) ;
V_19 = 0 ;
break;
case V_184 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
V_19 = - V_181 ;
if ( F_73 ( & V_177 , ( void V_182 * ) V_97 , sizeof( struct V_176 ) ) )
break;
V_4 -> V_127 = V_177 . V_183 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_8 , V_4 -> V_38 , V_4 -> V_127 ) ;
V_19 = 0 ;
break;
case V_185 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
V_19 = - V_181 ;
if ( F_75 ( V_4 -> V_128 , ( int V_182 * ) V_97 ) )
break;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_9 , V_4 -> V_38 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_186 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
V_19 = - V_181 ;
if ( F_76 ( V_178 , ( int V_182 * ) V_97 ) )
break;
V_4 -> V_128 = V_178 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_10 , V_4 -> V_38 , V_4 -> V_128 ) ;
V_19 = 0 ;
break;
case V_187 :
V_19 = - V_181 ;
if ( F_75 ( V_31 -> V_18 , ( int V_182 * ) V_97 ) )
break;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_11 , V_4 -> V_38 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_188 :
V_19 = - V_181 ;
if ( F_76 ( V_178 , ( int V_182 * ) V_97 ) )
break;
V_31 -> V_18 = V_178 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_12 , V_4 -> V_38 , V_31 -> V_18 ) ;
V_19 = 0 ;
break;
case V_189 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_109 = V_47 -> V_109 ;
V_41 . V_73 = V_4 -> V_73 ;
F_71 ( & V_41 , & V_4 -> V_41 ) ;
if ( F_74 ( ( void V_182 * ) V_97 , & V_41 ,
sizeof( V_41 ) ) )
break;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_13 , V_4 -> V_38 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_190 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_77 ( struct V_46 * V_47 ,
unsigned int V_175 , unsigned long V_97 )
{
int V_19 = 0 ;
struct V_2 * V_3 ;
struct V_165 V_41 ;
F_15 ( V_47 -> V_35 , V_146 , V_37 ,
L_14 ,
V_47 -> V_38 , V_175 , V_97 ) ;
V_3 = V_47 -> V_2 ;
F_2 ( V_3 ) ;
switch ( V_175 ) {
case V_189 :
V_19 = - V_180 ;
if ( ! ( V_3 -> V_21 & V_51 ) )
break;
if ( F_73 ( & V_41 , ( void V_182 * ) V_97 ,
sizeof( V_41 ) ) ) {
V_19 = - V_181 ;
break;
}
if ( V_41 . V_73 != 0 ) {
struct V_1 * V_4 =
F_59 ( F_57 ( V_3 ) , V_47 , V_41 . V_73 ) ;
if ( V_4 != NULL )
V_19 = F_72 ( V_4 , V_175 , V_97 ) ;
else
V_19 = - V_191 ;
break;
}
#ifdef F_78
V_41 . V_192 = ( V_3 -> V_193 [ 0 ] || V_3 -> V_193 [ 1 ] ) ? 1 : 0 ;
#endif
F_71 ( & V_41 , & V_47 -> V_41 ) ;
if ( F_74 ( ( void V_182 * ) V_97 , & V_41 , sizeof( V_41 ) ) ) {
V_19 = - V_181 ;
break;
}
F_15 ( V_47 -> V_35 , V_146 , V_40 ,
L_13 , V_47 -> V_38 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_190 ;
break;
}
F_3 ( V_3 ) ;
return V_19 ;
}
static int F_79 ( struct V_14 * V_2 , unsigned int V_175 ,
unsigned long V_97 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_19 = - V_52 ;
if ( F_24 ( V_3 , V_50 ) != 0 )
goto V_23;
V_19 = - V_49 ;
if ( ( V_3 -> V_5 == NULL ) ||
( ! ( V_3 -> V_21 & ( V_51 | V_22 ) ) ) )
goto V_23;
V_19 = - V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_73 == 0 ) &&
( V_4 -> V_111 == 0 ) ) {
V_19 = - V_52 ;
V_47 = F_25 ( V_31 -> V_53 ) ;
if ( V_47 == NULL )
goto V_153;
V_19 = F_77 ( V_47 , V_175 , V_97 ) ;
F_3 ( V_31 -> V_53 ) ;
goto V_153;
}
V_19 = F_72 ( V_4 , V_175 , V_97 ) ;
V_153:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_46 * V_47 ,
int V_194 , int V_178 )
{
int V_19 = 0 ;
switch ( V_194 ) {
case V_195 :
V_47 -> V_35 = V_178 ;
F_15 ( V_47 -> V_35 , V_146 , V_40 ,
L_15 , V_47 -> V_38 , V_47 -> V_35 ) ;
break;
default:
V_19 = - V_196 ;
break;
}
return V_19 ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_194 , int V_178 )
{
int V_19 = 0 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
switch ( V_194 ) {
case V_197 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_19 = - V_114 ;
break;
}
V_4 -> V_198 = V_178 ? - 1 : 0 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_16 , V_4 -> V_38 , V_4 -> V_198 ) ;
break;
case V_199 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_19 = - V_114 ;
break;
}
V_4 -> V_200 = V_178 ? - 1 : 0 ;
{
struct V_2 * V_201 = V_31 -> V_2 ;
struct V_33 * V_34 = F_19 ( V_201 ) ;
V_34 -> V_39 . V_143 = V_178 ? V_202 :
V_144 ;
}
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_17 , V_4 -> V_38 , V_4 -> V_200 ) ;
break;
case V_203 :
if ( ( V_178 != 0 ) && ( V_178 != 1 ) ) {
V_19 = - V_114 ;
break;
}
V_4 -> V_204 = V_178 ? - 1 : 0 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_18 , V_4 -> V_38 , V_4 -> V_204 ) ;
break;
case V_195 :
V_4 -> V_35 = V_178 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_15 , V_4 -> V_38 , V_4 -> V_35 ) ;
break;
case V_205 :
V_4 -> V_206 = F_82 ( V_178 ) ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_19 , V_4 -> V_38 , V_4 -> V_206 ) ;
break;
default:
V_19 = - V_196 ;
break;
}
return V_19 ;
}
static int F_83 ( struct V_14 * V_2 , int V_207 , int V_194 ,
char V_182 * V_208 , unsigned int V_209 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
int V_178 ;
int V_19 ;
if ( V_207 != V_210 )
return V_211 . V_212 ( V_3 , V_207 , V_194 , V_208 , V_209 ) ;
if ( V_209 < sizeof( int ) )
return - V_114 ;
if ( F_76 ( V_178 , ( int V_182 * ) V_208 ) )
return - V_181 ;
V_19 = - V_49 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_73 == 0 ) &&
( V_4 -> V_111 == 0 ) ) {
V_19 = - V_52 ;
V_47 = F_25 ( V_31 -> V_53 ) ;
if ( V_47 == NULL )
goto V_153;
V_19 = F_80 ( V_3 , V_47 , V_194 , V_178 ) ;
F_3 ( V_31 -> V_53 ) ;
} else
V_19 = F_81 ( V_3 , V_4 , V_194 , V_178 ) ;
V_19 = 0 ;
V_153:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_46 * V_47 ,
int V_194 , int * V_178 )
{
int V_19 = 0 ;
switch ( V_194 ) {
case V_195 :
* V_178 = V_47 -> V_35 ;
F_15 ( V_47 -> V_35 , V_146 , V_40 ,
L_20 , V_47 -> V_38 , V_47 -> V_35 ) ;
break;
default:
V_19 = - V_196 ;
break;
}
return V_19 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
int V_194 , int * V_178 )
{
int V_19 = 0 ;
switch ( V_194 ) {
case V_197 :
* V_178 = V_4 -> V_198 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_21 , V_4 -> V_38 , * V_178 ) ;
break;
case V_199 :
* V_178 = V_4 -> V_200 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_22 , V_4 -> V_38 , * V_178 ) ;
break;
case V_203 :
* V_178 = V_4 -> V_204 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_23 , V_4 -> V_38 , * V_178 ) ;
break;
case V_195 :
* V_178 = V_4 -> V_35 ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_24 , V_4 -> V_38 , * V_178 ) ;
break;
case V_205 :
* V_178 = ( int ) F_86 ( V_4 -> V_206 ) ;
F_15 ( V_4 -> V_35 , V_146 , V_40 ,
L_25 , V_4 -> V_38 , * V_178 ) ;
break;
default:
V_19 = - V_196 ;
}
return V_19 ;
}
static int F_87 ( struct V_14 * V_2 , int V_207 ,
int V_194 , char V_182 * V_208 , int V_182 * V_209 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_46 * V_47 ;
int V_178 , V_17 ;
int V_19 ;
struct V_30 * V_31 ;
if ( V_207 != V_210 )
return V_211 . V_213 ( V_3 , V_207 , V_194 , V_208 , V_209 ) ;
if ( F_76 ( V_17 , ( int V_182 * ) V_209 ) )
return - V_181 ;
V_17 = F_88 (unsigned int, len, sizeof(int)) ;
if ( V_17 < 0 )
return - V_114 ;
V_19 = - V_49 ;
if ( V_3 -> V_5 == NULL )
goto V_23;
V_19 = - V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_23;
V_31 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_73 == 0 ) &&
( V_4 -> V_111 == 0 ) ) {
V_19 = - V_52 ;
V_47 = F_25 ( V_31 -> V_53 ) ;
if ( V_47 == NULL )
goto V_153;
V_19 = F_84 ( V_3 , V_47 , V_194 , & V_178 ) ;
F_3 ( V_31 -> V_53 ) ;
} else
V_19 = F_85 ( V_3 , V_4 , V_194 , & V_178 ) ;
V_19 = - V_181 ;
if ( F_75 ( V_17 , ( int V_182 * ) V_209 ) )
goto V_153;
if ( F_74 ( ( void V_182 * ) V_208 , & V_178 , V_17 ) )
goto V_153;
V_19 = 0 ;
V_153:
F_3 ( V_3 ) ;
V_23:
return V_19 ;
}
static void F_89 ( struct V_81 * V_81 , struct V_214 * V_215 )
{
for (; ; ) {
V_215 -> V_47 = F_90 ( V_81 , V_215 -> V_216 ) ;
V_215 -> V_216 ++ ;
if ( V_215 -> V_47 == NULL )
break;
if ( V_215 -> V_47 -> V_154 < 3 )
break;
}
}
static void F_91 ( struct V_81 * V_81 , struct V_214 * V_215 )
{
V_215 -> V_4 = F_92 ( V_215 -> V_47 , V_215 -> V_217 ) ;
V_215 -> V_217 ++ ;
if ( V_215 -> V_4 == NULL ) {
V_215 -> V_217 = 0 ;
F_89 ( V_81 , V_215 ) ;
}
}
static void * F_93 ( struct V_96 * V_43 , T_4 * V_218 )
{
struct V_214 * V_215 = V_219 ;
T_4 V_220 = * V_218 ;
struct V_81 * V_81 ;
if ( ! V_220 )
goto V_6;
F_4 ( V_43 -> V_65 == NULL ) ;
V_215 = V_43 -> V_65 ;
V_81 = F_94 ( V_43 ) ;
if ( V_215 -> V_47 == NULL )
F_89 ( V_81 , V_215 ) ;
else
F_91 ( V_81 , V_215 ) ;
if ( ( V_215 -> V_47 == NULL ) && ( V_215 -> V_4 == NULL ) )
V_215 = NULL ;
V_6:
return V_215 ;
}
static void * F_95 ( struct V_96 * V_43 , void * V_221 , T_4 * V_220 )
{
( * V_220 ) ++ ;
return NULL ;
}
static void F_96 ( struct V_96 * V_222 , void * V_221 )
{
}
static void F_97 ( struct V_96 * V_43 , void * V_221 )
{
struct V_46 * V_47 = V_221 ;
F_53 ( V_43 , L_26 ,
V_47 -> V_38 ,
( V_47 == V_47 -> V_2 -> V_5 ) ? 'Y' : 'N' ,
F_98 ( & V_47 -> V_223 ) - 1 ) ;
F_53 ( V_43 , L_27 ,
V_47 -> V_35 ,
( unsigned long long ) V_47 -> V_41 . V_168 ,
( unsigned long long ) V_47 -> V_41 . V_169 ,
( unsigned long long ) V_47 -> V_41 . V_170 ,
( unsigned long long ) V_47 -> V_41 . V_171 ,
( unsigned long long ) V_47 -> V_41 . V_172 ,
( unsigned long long ) V_47 -> V_41 . V_42 ) ;
}
static void F_99 ( struct V_96 * V_43 , void * V_221 )
{
struct V_1 * V_4 = V_221 ;
struct V_46 * V_47 = V_4 -> V_47 ;
struct V_30 * V_31 = F_14 ( V_4 ) ;
struct V_33 * V_34 = F_19 ( V_31 -> V_2 ) ;
T_3 V_224 = 0 ;
T_5 V_225 = 0 ;
if ( V_47 -> V_2 ) {
struct V_150 * V_151 = F_70 ( V_47 -> V_2 ) ;
V_224 = F_100 ( V_151 -> V_226 ) ;
V_225 = F_101 ( V_151 -> V_227 ) ;
}
F_53 ( V_43 , L_28
L_29 ,
V_4 -> V_38 , V_224 , V_225 ,
V_47 -> V_109 ,
V_4 -> V_73 ,
V_47 -> V_110 ,
V_4 -> V_111 ,
V_31 -> V_2 -> V_21 ,
( V_4 == V_31 -> V_2 -> V_5 ) ?
'Y' : 'N' ) ;
F_53 ( V_43 , L_30 ,
V_4 -> V_127 , V_4 -> V_128 ,
V_4 -> V_198 ? 'R' : '-' ,
V_4 -> V_200 ? 'S' : '-' ,
V_4 -> V_204 ? L_31 : L_32 ,
V_4 -> V_35 ,
F_86 ( V_4 -> V_206 ) ) ;
F_53 ( V_43 , L_33 ,
V_4 -> V_228 , V_4 -> V_229 ,
( unsigned long long ) V_4 -> V_41 . V_168 ,
( unsigned long long ) V_4 -> V_41 . V_169 ,
( unsigned long long ) V_4 -> V_41 . V_170 ,
( unsigned long long ) V_4 -> V_41 . V_171 ,
( unsigned long long ) V_4 -> V_41 . V_172 ,
( unsigned long long ) V_4 -> V_41 . V_42 ) ;
if ( V_34 )
F_53 ( V_43 , L_4 , F_54 ( & V_34 -> V_39 ) ) ;
}
static int F_102 ( struct V_96 * V_43 , void * V_221 )
{
struct V_214 * V_215 = V_221 ;
if ( V_221 == V_219 ) {
F_103 ( V_43 , L_34 V_230 L_35 ) ;
F_103 ( V_43 , L_36 ) ;
F_103 ( V_43 , L_37 ) ;
F_103 ( V_43 , L_38
L_39 ) ;
F_103 ( V_43 , L_40 ) ;
F_103 ( V_43 , L_41 ) ;
goto V_6;
}
if ( V_215 -> V_4 == NULL )
F_97 ( V_43 , V_215 -> V_47 ) ;
else
F_99 ( V_43 , V_215 -> V_4 ) ;
V_6:
return 0 ;
}
static int F_104 ( struct V_231 * V_231 , struct V_232 * V_232 )
{
return F_105 ( V_231 , V_232 , & V_233 ,
sizeof( struct V_214 ) ) ;
}
static T_6 int F_106 ( struct V_81 * V_81 )
{
struct V_234 * V_235 ;
int V_19 = 0 ;
V_235 = F_107 ( V_81 , L_42 , V_236 , & V_237 ) ;
if ( ! V_235 ) {
V_19 = - V_58 ;
goto V_6;
}
V_6:
return V_19 ;
}
static T_7 void F_108 ( struct V_81 * V_81 )
{
F_109 ( V_81 , L_42 ) ;
}
static int T_8 F_110 ( void )
{
int V_19 ;
V_19 = F_111 ( & V_238 ) ;
if ( V_19 )
goto V_6;
V_19 = F_112 ( & V_83 , 0 ) ;
if ( V_19 )
goto V_239;
V_19 = F_113 ( V_90 , & V_240 ) ;
if ( V_19 )
goto V_241;
#ifdef F_114
V_19 = F_115 ( V_242 , & V_243 ) ;
if ( V_19 )
goto V_244;
#endif
F_116 ( V_40 L_43 ,
V_230 ) ;
V_6:
return V_19 ;
#ifdef F_114
V_244:
F_117 ( V_90 ) ;
#endif
V_241:
F_118 ( & V_83 ) ;
V_239:
F_119 ( & V_238 ) ;
goto V_6;
}
static void T_9 F_120 ( void )
{
#ifdef F_114
F_121 ( V_242 ) ;
#endif
F_117 ( V_90 ) ;
F_118 ( & V_83 ) ;
F_119 ( & V_238 ) ;
}
