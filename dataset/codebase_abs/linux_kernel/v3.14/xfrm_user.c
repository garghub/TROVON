static int F_1 ( struct V_1 * * V_2 , enum V_3 type )
{
struct V_1 * V_4 = V_2 [ type ] ;
struct V_5 * V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) < F_4 ( V_6 ) )
return - V_7 ;
switch ( type ) {
case V_8 :
case V_9 :
case V_10 :
break;
default:
return - V_7 ;
}
V_6 -> V_11 [ V_12 - 1 ] = '\0' ;
return 0 ;
}
static int F_5 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_13 ] ;
struct V_14 * V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) < F_6 ( V_6 ) )
return - V_7 ;
V_6 -> V_11 [ V_12 - 1 ] = '\0' ;
return 0 ;
}
static int F_7 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_15 ] ;
struct V_16 * V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) < F_8 ( V_6 ) )
return - V_7 ;
V_6 -> V_11 [ V_12 - 1 ] = '\0' ;
return 0 ;
}
static void F_9 ( struct V_1 * * V_2 , enum V_3 type ,
T_1 * * V_17 )
{
struct V_1 * V_4 = V_2 [ type ] ;
if ( V_4 && V_17 )
* V_17 = F_2 ( V_4 ) ;
}
static inline int F_10 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
if ( V_20 -> V_21 != ( sizeof( struct V_19 ) + V_20 -> V_22 ) )
return - V_7 ;
return 0 ;
}
static inline int F_11 ( struct V_23 * V_24 ,
struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_25 ] ;
struct V_26 * V_27 ;
if ( V_24 -> V_28 & V_29 ) {
if ( ! V_4 )
return - V_7 ;
V_27 = F_2 ( V_4 ) ;
if ( V_27 -> V_30 > V_31 / sizeof( V_27 -> V_32 [ 0 ] ) / 8 )
return - V_7 ;
if ( F_3 ( V_4 ) < F_12 ( V_27 ) &&
F_3 ( V_4 ) != sizeof( * V_27 ) )
return - V_7 ;
}
if ( ! V_4 )
return 0 ;
if ( V_24 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( V_24 -> V_36 != 0 )
return - V_7 ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_1 * * V_2 )
{
int V_37 ;
V_37 = - V_7 ;
switch ( V_24 -> V_38 ) {
case V_39 :
break;
case V_40 :
#if F_14 ( V_41 )
break;
#else
V_37 = - V_42 ;
goto V_43;
#endif
default:
goto V_43;
}
V_37 = - V_7 ;
switch ( V_24 -> V_33 . V_34 ) {
case V_44 :
if ( ( ! V_2 [ V_8 ] &&
! V_2 [ V_13 ] ) ||
V_2 [ V_15 ] ||
V_2 [ V_9 ] ||
V_2 [ V_10 ] ||
V_2 [ V_45 ] ||
( F_15 ( V_24 -> V_33 . V_46 ) >= 0x10000 ) )
goto V_43;
break;
case V_35 :
if ( V_2 [ V_10 ] )
goto V_43;
if ( ! V_2 [ V_8 ] &&
! V_2 [ V_13 ] &&
! V_2 [ V_9 ] &&
! V_2 [ V_15 ] )
goto V_43;
if ( ( V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_9 ] ) &&
V_2 [ V_15 ] )
goto V_43;
if ( V_2 [ V_45 ] &&
V_24 -> V_47 != V_48 )
goto V_43;
break;
case V_49 :
if ( ! V_2 [ V_10 ] ||
V_2 [ V_15 ] ||
V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_9 ] ||
V_2 [ V_45 ] )
goto V_43;
break;
#if F_14 ( V_41 )
case V_50 :
case V_51 :
if ( V_2 [ V_10 ] ||
V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_15 ] ||
V_2 [ V_9 ] ||
V_2 [ V_52 ] ||
V_2 [ V_18 ] ||
V_2 [ V_45 ] ||
! V_2 [ V_53 ] )
goto V_43;
break;
#endif
default:
goto V_43;
}
if ( ( V_37 = F_7 ( V_2 ) ) )
goto V_43;
if ( ( V_37 = F_5 ( V_2 ) ) )
goto V_43;
if ( ( V_37 = F_1 ( V_2 , V_8 ) ) )
goto V_43;
if ( ( V_37 = F_1 ( V_2 , V_9 ) ) )
goto V_43;
if ( ( V_37 = F_1 ( V_2 , V_10 ) ) )
goto V_43;
if ( ( V_37 = F_10 ( V_2 ) ) )
goto V_43;
if ( ( V_37 = F_11 ( V_24 , V_2 ) ) )
goto V_43;
V_37 = - V_7 ;
switch ( V_24 -> V_47 ) {
case V_54 :
case V_48 :
case V_55 :
case V_56 :
break;
default:
goto V_43;
}
V_37 = 0 ;
V_43:
return V_37 ;
}
static int F_16 ( struct V_14 * * V_57 , T_2 * V_58 ,
struct V_1 * V_59 )
{
struct V_5 * V_60 ;
struct V_14 * V_24 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_17 ( V_60 -> V_11 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
* V_58 = V_62 -> V_64 . V_65 ;
V_24 = F_18 ( sizeof( * V_24 ) + ( V_60 -> V_66 + 7 ) / 8 , V_67 ) ;
if ( ! V_24 )
return - V_68 ;
strcpy ( V_24 -> V_11 , V_62 -> V_69 ) ;
V_24 -> V_66 = V_60 -> V_66 ;
V_24 -> V_70 = V_62 -> V_71 . V_72 . V_73 ;
memcpy ( V_24 -> V_74 , V_60 -> V_74 , ( V_60 -> V_66 + 7 ) / 8 ) ;
* V_57 = V_24 ;
return 0 ;
}
static int F_19 ( struct V_14 * * V_57 , T_2 * V_58 ,
struct V_1 * V_59 )
{
struct V_14 * V_24 , * V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_17 ( V_60 -> V_11 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
if ( ( V_60 -> V_70 / 8 ) > V_75 ||
V_60 -> V_70 > V_62 -> V_71 . V_72 . V_76 )
return - V_7 ;
* V_58 = V_62 -> V_64 . V_65 ;
V_24 = F_20 ( V_60 , F_6 ( V_60 ) , V_67 ) ;
if ( ! V_24 )
return - V_68 ;
strcpy ( V_24 -> V_11 , V_62 -> V_69 ) ;
if ( ! V_24 -> V_70 )
V_24 -> V_70 = V_62 -> V_71 . V_72 . V_73 ;
* V_57 = V_24 ;
return 0 ;
}
static int F_21 ( struct V_16 * * V_57 , T_2 * V_58 ,
struct V_1 * V_59 )
{
struct V_16 * V_24 , * V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_22 ( V_60 -> V_11 , V_60 -> V_77 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
* V_58 = V_62 -> V_64 . V_65 ;
V_24 = F_20 ( V_60 , F_8 ( V_60 ) , V_67 ) ;
if ( ! V_24 )
return - V_68 ;
strcpy ( V_24 -> V_11 , V_62 -> V_69 ) ;
* V_57 = V_24 ;
return 0 ;
}
static inline int F_23 ( struct V_26 * V_78 ,
struct V_1 * V_79 )
{
struct V_26 * V_80 ;
int V_81 ;
if ( ! V_78 || ! V_79 )
return 0 ;
V_80 = F_2 ( V_79 ) ;
V_81 = F_12 ( V_80 ) ;
if ( F_3 ( V_79 ) < V_81 || F_12 ( V_78 ) != V_81 )
return - V_7 ;
return 0 ;
}
static int F_24 ( struct V_26 * * V_78 ,
struct V_26 * * V_82 ,
struct V_1 * V_59 )
{
struct V_26 * V_24 , * V_83 , * V_80 ;
int V_84 , V_81 ;
if ( ! V_59 )
return 0 ;
V_80 = F_2 ( V_59 ) ;
V_84 = F_12 ( V_80 ) ;
V_81 = F_3 ( V_59 ) >= V_84 ? V_84 : sizeof( * V_80 ) ;
V_24 = F_25 ( V_84 , V_67 ) ;
if ( ! V_24 )
return - V_68 ;
V_83 = F_25 ( V_84 , V_67 ) ;
if ( ! V_83 ) {
F_26 ( V_24 ) ;
return - V_68 ;
}
memcpy ( V_24 , V_80 , V_81 ) ;
memcpy ( V_83 , V_80 , V_81 ) ;
* V_78 = V_24 ;
* V_82 = V_83 ;
return 0 ;
}
static inline int F_27 ( struct V_85 * V_86 )
{
int V_21 = 0 ;
if ( V_86 ) {
V_21 += sizeof( struct V_19 ) ;
V_21 += V_86 -> V_22 ;
}
return V_21 ;
}
static void F_28 ( struct V_87 * V_88 , struct V_23 * V_24 )
{
memcpy ( & V_88 -> V_33 , & V_24 -> V_33 , sizeof( V_88 -> V_33 ) ) ;
memcpy ( & V_88 -> V_89 , & V_24 -> V_89 , sizeof( V_88 -> V_89 ) ) ;
memcpy ( & V_88 -> V_90 , & V_24 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
V_88 -> V_58 . V_47 = V_24 -> V_47 ;
V_88 -> V_58 . V_36 = F_29 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_88 -> V_58 . V_91 = V_24 -> V_91 ;
V_88 -> V_58 . V_38 = V_24 -> V_38 ;
memcpy ( & V_88 -> V_58 . V_92 , & V_24 -> V_92 , sizeof( V_88 -> V_58 . V_92 ) ) ;
V_88 -> V_58 . V_28 = V_24 -> V_28 ;
if ( ! V_88 -> V_89 . V_38 && ! ( V_24 -> V_28 & V_93 ) )
V_88 -> V_89 . V_38 = V_24 -> V_38 ;
}
static void F_30 ( struct V_87 * V_88 , struct V_1 * * V_2 ,
int V_94 )
{
struct V_1 * V_79 = V_2 [ V_95 ] ;
struct V_1 * V_96 = V_94 ? V_2 [ V_25 ] : NULL ;
struct V_1 * V_97 = V_2 [ V_98 ] ;
struct V_1 * V_99 = V_2 [ V_100 ] ;
struct V_1 * V_4 = V_2 [ V_101 ] ;
if ( V_96 ) {
struct V_26 * V_78 ;
V_78 = F_2 ( V_96 ) ;
memcpy ( V_88 -> V_78 , V_78 ,
F_12 ( V_78 ) ) ;
memcpy ( V_88 -> V_82 , V_78 ,
F_12 ( V_78 ) ) ;
}
if ( V_79 ) {
struct V_102 * V_103 ;
V_103 = F_2 ( V_79 ) ;
memcpy ( & V_88 -> V_103 , V_103 , sizeof( * V_103 ) ) ;
memcpy ( & V_88 -> V_104 , V_103 , sizeof( * V_103 ) ) ;
}
if ( V_97 ) {
struct V_105 * V_106 ;
V_106 = F_2 ( V_97 ) ;
V_88 -> V_107 . V_108 = V_106 -> V_108 ;
V_88 -> V_107 . V_109 = V_106 -> V_109 ;
V_88 -> V_107 . V_110 = V_106 -> V_110 ;
V_88 -> V_107 . V_111 = V_106 -> V_111 ;
}
if ( V_99 )
V_88 -> V_112 = F_31 ( V_99 ) ;
if ( V_4 )
V_88 -> V_113 = F_31 ( V_4 ) ;
}
static struct V_87 * F_32 ( struct V_114 * V_114 ,
struct V_23 * V_24 ,
struct V_1 * * V_2 ,
int * V_115 )
{
struct V_87 * V_88 = F_33 ( V_114 ) ;
int V_37 = - V_68 ;
if ( ! V_88 )
goto V_116;
F_28 ( V_88 , V_24 ) ;
if ( V_2 [ V_117 ] )
V_88 -> V_58 . V_118 = F_31 ( V_2 [ V_117 ] ) ;
if ( ( V_37 = F_21 ( & V_88 -> V_119 , & V_88 -> V_58 . V_120 ,
V_2 [ V_15 ] ) ) )
goto error;
if ( ( V_37 = F_19 ( & V_88 -> V_121 , & V_88 -> V_58 . V_122 ,
V_2 [ V_13 ] ) ) )
goto error;
if ( ! V_88 -> V_58 . V_122 ) {
if ( ( V_37 = F_16 ( & V_88 -> V_121 , & V_88 -> V_58 . V_122 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_37 = F_34 ( & V_88 -> V_123 , & V_88 -> V_58 . V_120 ,
V_124 ,
V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_37 = F_34 ( & V_88 -> V_125 , & V_88 -> V_58 . V_126 ,
V_127 ,
V_2 [ V_10 ] ) ) )
goto error;
if ( V_2 [ V_52 ] ) {
V_88 -> V_128 = F_20 ( F_2 ( V_2 [ V_52 ] ) ,
sizeof( * V_88 -> V_128 ) , V_67 ) ;
if ( V_88 -> V_128 == NULL )
goto error;
}
if ( V_2 [ V_45 ] )
V_88 -> V_129 = F_31 ( V_2 [ V_45 ] ) ;
if ( V_2 [ V_53 ] ) {
V_88 -> V_130 = F_20 ( F_2 ( V_2 [ V_53 ] ) ,
sizeof( * V_88 -> V_130 ) , V_67 ) ;
if ( V_88 -> V_130 == NULL )
goto error;
}
F_35 ( V_2 , & V_88 -> V_131 ) ;
V_37 = F_36 ( V_88 , false ) ;
if ( V_37 )
goto error;
if ( V_2 [ V_18 ] &&
F_37 ( V_88 , F_2 ( V_2 [ V_18 ] ) ) )
goto error;
if ( ( V_37 = F_24 ( & V_88 -> V_78 , & V_88 -> V_82 ,
V_2 [ V_25 ] ) ) )
goto error;
V_88 -> V_132 . V_133 = V_24 -> V_133 ;
V_88 -> V_113 = V_114 -> V_134 . V_135 ;
V_88 -> V_112 = ( V_114 -> V_134 . V_136 * V_137 ) / V_138 ;
if ( ( V_37 = F_38 ( V_88 ) ) )
goto error;
F_30 ( V_88 , V_2 , 0 ) ;
return V_88 ;
error:
V_88 -> V_132 . V_139 = V_140 ;
F_39 ( V_88 ) ;
V_116:
* V_115 = V_37 ;
return NULL ;
}
static int F_40 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_23 * V_24 = F_42 ( V_144 ) ;
struct V_87 * V_88 ;
int V_37 ;
struct V_146 V_147 ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_37 = F_13 ( V_24 , V_2 ) ;
if ( V_37 )
return V_37 ;
V_88 = F_32 ( V_114 , V_24 , V_2 , & V_37 ) ;
if ( ! V_88 )
return V_37 ;
F_45 ( V_88 ) ;
if ( V_144 -> V_152 == V_153 )
V_37 = F_46 ( V_88 ) ;
else
V_37 = F_47 ( V_88 ) ;
F_48 ( V_149 , & V_151 ) ;
F_49 ( V_88 , V_37 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_37 < 0 ) {
V_88 -> V_132 . V_139 = V_140 ;
F_50 ( V_88 ) ;
goto V_43;
}
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_51 ( V_88 , & V_147 ) ;
V_43:
F_39 ( V_88 ) ;
return V_37 ;
}
static struct V_87 * F_52 ( struct V_114 * V_114 ,
struct V_158 * V_24 ,
struct V_1 * * V_2 ,
int * V_115 )
{
struct V_87 * V_88 = NULL ;
struct V_159 V_160 ;
int V_37 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
if ( F_53 ( V_24 -> V_34 , V_161 ) ) {
V_37 = - V_162 ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_163 , V_24 -> V_46 , V_24 -> V_34 , V_24 -> V_38 ) ;
} else {
T_1 * V_92 = NULL ;
F_9 ( V_2 , V_164 , & V_92 ) ;
if ( ! V_92 ) {
V_37 = - V_7 ;
goto V_43;
}
V_37 = - V_162 ;
V_88 = F_55 ( V_114 , V_131 ,
& V_24 -> V_163 , V_92 ,
V_24 -> V_34 , V_24 -> V_38 ) ;
}
V_43:
if ( ! V_88 && V_115 )
* V_115 = V_37 ;
return V_88 ;
}
static int F_56 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_37 = - V_162 ;
struct V_146 V_147 ;
struct V_158 * V_24 = F_42 ( V_144 ) ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_88 = F_52 ( V_114 , V_24 , V_2 , & V_37 ) ;
if ( V_88 == NULL )
return V_37 ;
if ( ( V_37 = F_57 ( V_88 ) ) != 0 )
goto V_43;
if ( F_58 ( V_88 ) ) {
V_37 = - V_165 ;
goto V_43;
}
V_37 = F_59 ( V_88 ) ;
if ( V_37 < 0 )
goto V_43;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_51 ( V_88 , & V_147 ) ;
V_43:
F_48 ( V_149 , & V_151 ) ;
F_60 ( V_88 , V_37 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
F_39 ( V_88 ) ;
return V_37 ;
}
static void F_61 ( struct V_87 * V_88 , struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_33 , & V_88 -> V_33 , sizeof( V_24 -> V_33 ) ) ;
memcpy ( & V_24 -> V_89 , & V_88 -> V_89 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_90 , & V_88 -> V_90 , sizeof( V_24 -> V_90 ) ) ;
memcpy ( & V_24 -> V_107 , & V_88 -> V_107 , sizeof( V_24 -> V_107 ) ) ;
memcpy ( & V_24 -> V_166 , & V_88 -> V_166 , sizeof( V_24 -> V_166 ) ) ;
memcpy ( & V_24 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_24 -> V_92 ) ) ;
V_24 -> V_47 = V_88 -> V_58 . V_47 ;
V_24 -> V_36 = V_88 -> V_58 . V_36 ;
V_24 -> V_91 = V_88 -> V_58 . V_91 ;
V_24 -> V_38 = V_88 -> V_58 . V_38 ;
V_24 -> V_28 = V_88 -> V_58 . V_28 ;
V_24 -> V_133 = V_88 -> V_132 . V_133 ;
}
static int F_62 ( struct V_85 * V_167 , struct V_141 * V_142 )
{
struct V_19 * V_20 ;
struct V_1 * V_168 ;
int V_169 = sizeof( * V_20 ) + V_167 -> V_22 ;
V_168 = F_63 ( V_142 , V_18 , V_169 ) ;
if ( V_168 == NULL )
return - V_170 ;
V_20 = F_2 ( V_168 ) ;
V_20 -> V_171 = V_18 ;
V_20 -> V_21 = V_169 ;
V_20 -> V_172 = V_167 -> V_172 ;
V_20 -> V_173 = V_167 -> V_173 ;
V_20 -> V_22 = V_167 -> V_22 ;
memcpy ( V_20 + 1 , V_167 -> V_174 , V_167 -> V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_14 * V_72 , struct V_141 * V_142 )
{
struct V_5 * V_62 ;
struct V_1 * V_175 ;
V_175 = F_63 ( V_142 , V_8 ,
sizeof( * V_62 ) + ( V_72 -> V_66 + 7 ) / 8 ) ;
if ( ! V_175 )
return - V_170 ;
V_62 = F_2 ( V_175 ) ;
strncpy ( V_62 -> V_11 , V_72 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_74 , V_72 -> V_74 , ( V_72 -> V_66 + 7 ) / 8 ) ;
V_62 -> V_66 = V_72 -> V_66 ;
return 0 ;
}
static int F_65 ( struct V_87 * V_88 ,
struct V_23 * V_24 ,
struct V_141 * V_142 )
{
int V_176 = 0 ;
F_61 ( V_88 , V_24 ) ;
if ( V_88 -> V_58 . V_118 ) {
V_176 = F_66 ( V_142 , V_117 ,
V_88 -> V_58 . V_118 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_130 ) {
V_176 = F_67 ( V_142 , V_53 , sizeof( * V_88 -> V_130 ) , V_88 -> V_130 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_177 ) {
V_176 = F_68 ( V_142 , V_178 , V_88 -> V_177 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_119 ) {
V_176 = F_67 ( V_142 , V_15 , F_8 ( V_88 -> V_119 ) , V_88 -> V_119 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_121 ) {
V_176 = F_64 ( V_88 -> V_121 , V_142 ) ;
if ( ! V_176 )
V_176 = F_67 ( V_142 , V_13 ,
F_6 ( V_88 -> V_121 ) , V_88 -> V_121 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_123 ) {
V_176 = F_67 ( V_142 , V_9 , F_4 ( V_88 -> V_123 ) , V_88 -> V_123 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_125 ) {
V_176 = F_67 ( V_142 , V_10 , sizeof( * ( V_88 -> V_125 ) ) , V_88 -> V_125 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_128 ) {
V_176 = F_67 ( V_142 , V_52 , sizeof( * V_88 -> V_128 ) , V_88 -> V_128 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_129 ) {
V_176 = F_66 ( V_142 , V_45 , V_88 -> V_129 ) ;
if ( V_176 )
goto V_43;
}
V_176 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_176 )
goto V_43;
if ( V_88 -> V_78 ) {
V_176 = F_67 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
if ( V_176 )
goto V_43;
}
if ( V_88 -> V_179 )
V_176 = F_62 ( V_88 -> V_179 , V_142 ) ;
V_43:
return V_176 ;
}
static int F_70 ( struct V_87 * V_88 , int V_180 , void * V_181 )
{
struct V_182 * V_183 = V_181 ;
struct V_141 * V_184 = V_183 -> V_184 ;
struct V_141 * V_142 = V_183 -> V_185 ;
struct V_23 * V_24 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , F_72 ( V_184 ) . V_155 , V_183 -> V_154 ,
V_153 , sizeof( * V_24 ) , V_183 -> V_186 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_24 = F_42 ( V_144 ) ;
V_37 = F_65 ( V_88 , V_24 , V_142 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_75 ( struct V_187 * V_188 )
{
struct V_189 * V_190 = (struct V_189 * ) & V_188 -> args [ 1 ] ;
struct V_191 * V_145 = V_188 -> V_142 -> V_145 ;
struct V_114 * V_114 = F_41 ( V_145 ) ;
F_76 ( V_190 , V_114 ) ;
return 0 ;
}
static int F_77 ( struct V_141 * V_142 , struct V_187 * V_188 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_189 * V_190 = (struct V_189 * ) & V_188 -> args [ 1 ] ;
struct V_182 V_192 ;
F_78 ( sizeof( struct V_189 ) >
sizeof( V_188 -> args ) - sizeof( V_188 -> args [ 0 ] ) ) ;
V_192 . V_184 = V_188 -> V_142 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_188 -> V_144 -> V_154 ;
V_192 . V_186 = V_193 ;
if ( ! V_188 -> args [ 0 ] ) {
V_188 -> args [ 0 ] = 1 ;
F_79 ( V_190 , 0 ) ;
}
( void ) V_189 ( V_114 , V_190 , F_70 , & V_192 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_80 ( struct V_141 * V_184 ,
struct V_87 * V_88 , T_4 V_133 )
{
struct V_182 V_192 ;
struct V_141 * V_142 ;
int V_37 ;
V_142 = F_81 ( V_194 , V_195 ) ;
if ( ! V_142 )
return F_82 ( - V_68 ) ;
V_192 . V_184 = V_184 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_186 = 0 ;
V_37 = F_70 ( V_88 , 0 , & V_192 ) ;
if ( V_37 ) {
F_83 ( V_142 ) ;
return F_82 ( V_37 ) ;
}
return V_142 ;
}
static inline T_5 F_84 ( void )
{
return F_85 ( 4 )
+ F_86 ( sizeof( struct V_196 ) )
+ F_86 ( sizeof( struct V_197 ) ) ;
}
static int F_87 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_28 )
{
struct V_198 V_199 ;
struct V_196 V_200 ;
struct V_197 V_201 ;
struct V_143 * V_144 ;
int V_37 ;
T_4 * V_202 ;
V_144 = F_71 ( V_142 , V_155 , V_133 , V_203 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_202 = F_42 ( V_144 ) ;
* V_202 = V_28 ;
F_88 ( V_114 , & V_199 ) ;
V_200 . V_204 = V_199 . V_204 ;
V_200 . V_205 = V_199 . V_205 ;
V_200 . V_206 = V_199 . V_206 ;
V_200 . V_207 = V_199 . V_207 ;
V_200 . V_208 = V_199 . V_208 ;
V_200 . V_209 = V_199 . V_209 ;
V_201 . V_210 = V_199 . V_210 ;
V_201 . V_211 = V_199 . V_211 ;
V_37 = F_67 ( V_142 , V_212 , sizeof( V_200 ) , & V_200 ) ;
if ( ! V_37 )
V_37 = F_67 ( V_142 , V_213 , sizeof( V_201 ) , & V_201 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_89 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_214 ;
T_4 * V_28 = F_42 ( V_144 ) ;
T_4 V_215 = F_72 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_214 = F_81 ( F_84 () , V_195 ) ;
if ( V_214 == NULL )
return - V_68 ;
if ( F_87 ( V_214 , V_114 , V_215 , V_133 , * V_28 ) < 0 )
F_90 () ;
return F_91 ( V_114 -> V_134 . V_216 , V_214 , V_215 ) ;
}
static inline T_5 F_92 ( void )
{
return F_85 ( 4 )
+ F_86 ( sizeof( struct V_217 ) )
+ F_86 ( 4 ) ;
}
static int F_93 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_28 )
{
struct V_218 V_199 ;
struct V_217 V_219 ;
struct V_143 * V_144 ;
int V_37 ;
T_4 * V_202 ;
V_144 = F_71 ( V_142 , V_155 , V_133 , V_220 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_202 = F_42 ( V_144 ) ;
* V_202 = V_28 ;
F_94 ( V_114 , & V_199 ) ;
V_219 . V_221 = V_199 . V_221 ;
V_219 . V_222 = V_199 . V_222 ;
V_37 = F_66 ( V_142 , V_223 , V_199 . V_224 ) ;
if ( ! V_37 )
V_37 = F_67 ( V_142 , V_225 , sizeof( V_219 ) , & V_219 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_95 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_214 ;
T_4 * V_28 = F_42 ( V_144 ) ;
T_4 V_215 = F_72 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_214 = F_81 ( F_92 () , V_195 ) ;
if ( V_214 == NULL )
return - V_68 ;
if ( F_93 ( V_214 , V_114 , V_215 , V_133 , * V_28 ) < 0 )
F_90 () ;
return F_91 ( V_114 -> V_134 . V_216 , V_214 , V_215 ) ;
}
static int F_96 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_158 * V_24 = F_42 ( V_144 ) ;
struct V_87 * V_88 ;
struct V_141 * V_226 ;
int V_37 = - V_162 ;
V_88 = F_52 ( V_114 , V_24 , V_2 , & V_37 ) ;
if ( V_88 == NULL )
goto V_227;
V_226 = F_80 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_97 ( V_226 ) ) {
V_37 = F_98 ( V_226 ) ;
} else {
V_37 = F_91 ( V_114 -> V_134 . V_216 , V_226 , F_72 ( V_142 ) . V_155 ) ;
}
F_39 ( V_88 ) ;
V_227:
return V_37 ;
}
static int F_99 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_228 * V_24 ;
struct V_141 * V_226 ;
T_1 * V_163 ;
int V_38 ;
int V_37 ;
T_4 V_131 ;
struct V_159 V_160 ;
V_24 = F_42 ( V_144 ) ;
V_37 = F_100 ( V_24 -> V_192 . V_33 . V_34 , V_24 -> V_229 , V_24 -> V_230 ) ;
if ( V_37 )
goto V_227;
V_38 = V_24 -> V_192 . V_38 ;
V_163 = & V_24 -> V_192 . V_33 . V_163 ;
V_88 = NULL ;
V_131 = F_35 ( V_2 , & V_160 ) ;
if ( V_24 -> V_192 . V_133 ) {
V_88 = F_101 ( V_114 , V_131 , V_24 -> V_192 . V_133 ) ;
if ( V_88 && ! F_102 ( & V_88 -> V_33 . V_163 , V_163 , V_38 ) ) {
F_39 ( V_88 ) ;
V_88 = NULL ;
}
}
if ( ! V_88 )
V_88 = F_103 ( V_114 , & V_160 , V_24 -> V_192 . V_47 , V_24 -> V_192 . V_91 ,
V_24 -> V_192 . V_33 . V_34 , V_163 ,
& V_24 -> V_192 . V_92 , 1 ,
V_38 ) ;
V_37 = - V_231 ;
if ( V_88 == NULL )
goto V_227;
V_37 = F_104 ( V_88 , V_24 -> V_229 , V_24 -> V_230 ) ;
if ( V_37 )
goto V_43;
V_226 = F_80 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_97 ( V_226 ) ) {
V_37 = F_98 ( V_226 ) ;
goto V_43;
}
V_37 = F_91 ( V_114 -> V_134 . V_216 , V_226 , F_72 ( V_142 ) . V_155 ) ;
V_43:
F_39 ( V_88 ) ;
V_227:
return V_37 ;
}
static int F_105 ( T_2 V_232 )
{
switch ( V_232 ) {
case V_233 :
case V_234 :
case V_235 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_106 ( T_2 type )
{
switch ( type ) {
case V_236 :
#ifdef F_107
case V_237 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_108 ( struct V_238 * V_24 )
{
int V_176 ;
switch ( V_24 -> V_239 ) {
case V_240 :
case V_241 :
case V_242 :
case V_243 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_244 ) {
case V_245 :
case V_246 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_89 . V_38 ) {
case V_39 :
break;
case V_40 :
#if F_14 ( V_41 )
break;
#else
return - V_42 ;
#endif
default:
return - V_7 ;
}
V_176 = F_105 ( V_24 -> V_232 ) ;
if ( V_176 )
return V_176 ;
if ( V_24 -> V_247 && ( ( V_24 -> V_247 & V_248 ) != V_24 -> V_232 ) )
return - V_7 ;
return 0 ;
}
static int F_109 ( struct V_249 * V_250 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_110 ( & V_250 -> V_179 , V_20 , V_67 ) ;
}
static void F_111 ( struct V_249 * V_251 , struct V_252 * V_253 ,
int V_254 )
{
int V_255 ;
V_251 -> V_256 = V_254 ;
for ( V_255 = 0 ; V_255 < V_254 ; V_255 ++ , V_253 ++ ) {
struct V_257 * V_258 = & V_251 -> V_259 [ V_255 ] ;
memcpy ( & V_258 -> V_33 , & V_253 -> V_33 , sizeof( struct V_260 ) ) ;
memcpy ( & V_258 -> V_92 , & V_253 -> V_92 ,
sizeof( T_1 ) ) ;
V_258 -> V_91 = V_253 -> V_91 ;
V_258 -> V_47 = V_253 -> V_47 ;
V_258 -> V_239 = V_253 -> V_239 ;
V_258 -> V_261 = V_253 -> V_261 ;
V_258 -> V_262 = V_253 -> V_262 ;
V_258 -> V_263 = V_253 -> V_263 ;
V_258 -> V_264 = V_253 -> V_264 ;
V_258 -> V_265 = ! ~ ( V_258 -> V_262 & V_258 -> V_263 & V_258 -> V_264 ) ;
V_258 -> V_266 = V_253 -> V_38 ;
}
}
static int F_112 ( int V_254 , struct V_252 * V_253 , T_6 V_38 )
{
int V_255 ;
if ( V_254 > V_267 )
return - V_7 ;
for ( V_255 = 0 ; V_255 < V_254 ; V_255 ++ ) {
if ( ! V_253 [ V_255 ] . V_38 )
V_253 [ V_255 ] . V_38 = V_38 ;
switch ( V_253 [ V_255 ] . V_38 ) {
case V_39 :
break;
#if F_14 ( V_41 )
case V_40 :
break;
#endif
default:
return - V_7 ;
}
}
return 0 ;
}
static int F_113 ( struct V_249 * V_250 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_268 ] ;
if ( ! V_4 ) {
V_250 -> V_256 = 0 ;
} else {
struct V_252 * V_269 = F_2 ( V_4 ) ;
int V_254 = F_3 ( V_4 ) / sizeof( * V_269 ) ;
int V_37 ;
V_37 = F_112 ( V_254 , V_269 , V_250 -> V_38 ) ;
if ( V_37 )
return V_37 ;
F_111 ( V_250 , V_269 , V_254 ) ;
}
return 0 ;
}
static int F_114 ( T_2 * V_270 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_271 ] ;
struct V_272 * V_273 ;
T_2 type = V_236 ;
int V_37 ;
if ( V_4 ) {
V_273 = F_2 ( V_4 ) ;
type = V_273 -> type ;
}
V_37 = F_106 ( type ) ;
if ( V_37 )
return V_37 ;
* V_270 = type ;
return 0 ;
}
static void F_115 ( struct V_249 * V_251 , struct V_238 * V_24 )
{
V_251 -> V_274 = V_24 -> V_274 ;
V_251 -> V_247 = V_24 -> V_247 ;
memcpy ( & V_251 -> V_275 , & V_24 -> V_89 , sizeof( V_251 -> V_275 ) ) ;
memcpy ( & V_251 -> V_90 , & V_24 -> V_90 , sizeof( V_251 -> V_90 ) ) ;
V_251 -> V_244 = V_24 -> V_244 ;
V_251 -> V_28 = V_24 -> V_28 ;
V_251 -> V_38 = V_24 -> V_89 . V_38 ;
}
static void F_116 ( struct V_249 * V_251 , struct V_238 * V_24 , int V_232 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_89 , & V_251 -> V_275 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_90 , & V_251 -> V_90 , sizeof( V_24 -> V_90 ) ) ;
memcpy ( & V_24 -> V_107 , & V_251 -> V_107 , sizeof( V_24 -> V_107 ) ) ;
V_24 -> V_274 = V_251 -> V_274 ;
V_24 -> V_247 = V_251 -> V_247 ;
V_24 -> V_89 . V_38 = V_251 -> V_38 ;
V_24 -> V_232 = V_232 ;
V_24 -> V_244 = V_251 -> V_244 ;
V_24 -> V_28 = V_251 -> V_28 ;
V_24 -> V_239 = V_240 ;
}
static struct V_249 * F_117 ( struct V_114 * V_114 , struct V_238 * V_24 , struct V_1 * * V_2 , int * V_115 )
{
struct V_249 * V_251 = F_118 ( V_114 , V_67 ) ;
int V_37 ;
if ( ! V_251 ) {
* V_115 = - V_68 ;
return NULL ;
}
F_115 ( V_251 , V_24 ) ;
V_37 = F_114 ( & V_251 -> type , V_2 ) ;
if ( V_37 )
goto error;
if ( ! ( V_37 = F_113 ( V_251 , V_2 ) ) )
V_37 = F_109 ( V_251 , V_2 ) ;
if ( V_37 )
goto error;
F_35 ( V_2 , & V_251 -> V_131 ) ;
return V_251 ;
error:
* V_115 = V_37 ;
V_251 -> V_190 . V_276 = 1 ;
F_119 ( V_251 ) ;
return NULL ;
}
static int F_120 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_238 * V_24 = F_42 ( V_144 ) ;
struct V_249 * V_251 ;
struct V_146 V_147 ;
int V_37 ;
int V_277 ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_37 = F_108 ( V_24 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_251 = F_117 ( V_114 , V_24 , V_2 , & V_37 ) ;
if ( ! V_251 )
return V_37 ;
V_277 = V_144 -> V_152 == V_278 ;
V_37 = F_121 ( V_24 -> V_232 , V_251 , V_277 ) ;
F_48 ( V_149 , & V_151 ) ;
F_122 ( V_251 , V_37 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_37 ) {
F_123 ( V_251 -> V_179 ) ;
F_26 ( V_251 ) ;
return V_37 ;
}
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_124 ( V_251 , V_24 -> V_232 , & V_147 ) ;
F_125 ( V_251 ) ;
return 0 ;
}
static int F_126 ( struct V_249 * V_251 , struct V_141 * V_142 )
{
struct V_252 V_279 [ V_267 ] ;
int V_255 ;
if ( V_251 -> V_256 == 0 )
return 0 ;
for ( V_255 = 0 ; V_255 < V_251 -> V_256 ; V_255 ++ ) {
struct V_252 * V_80 = & V_279 [ V_255 ] ;
struct V_257 * V_280 = & V_251 -> V_259 [ V_255 ] ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( & V_80 -> V_33 , & V_280 -> V_33 , sizeof( V_80 -> V_33 ) ) ;
V_80 -> V_38 = V_280 -> V_266 ;
memcpy ( & V_80 -> V_92 , & V_280 -> V_92 , sizeof( V_80 -> V_92 ) ) ;
V_80 -> V_91 = V_280 -> V_91 ;
V_80 -> V_47 = V_280 -> V_47 ;
V_80 -> V_239 = V_280 -> V_239 ;
V_80 -> V_261 = V_280 -> V_261 ;
V_80 -> V_262 = V_280 -> V_262 ;
V_80 -> V_263 = V_280 -> V_263 ;
V_80 -> V_264 = V_280 -> V_264 ;
}
return F_67 ( V_142 , V_268 ,
sizeof( struct V_252 ) * V_251 -> V_256 , V_279 ) ;
}
static inline int F_127 ( struct V_87 * V_88 , struct V_141 * V_142 )
{
if ( V_88 -> V_179 ) {
return F_62 ( V_88 -> V_179 , V_142 ) ;
}
return 0 ;
}
static inline int F_128 ( struct V_249 * V_251 , struct V_141 * V_142 )
{
if ( V_251 -> V_179 )
return F_62 ( V_251 -> V_179 , V_142 ) ;
return 0 ;
}
static inline T_5 F_129 ( void )
{
#ifdef F_107
return F_86 ( sizeof( struct V_272 ) ) ;
#else
return 0 ;
#endif
}
static int F_130 ( T_2 type , struct V_141 * V_142 )
{
struct V_272 V_273 = {
. type = type ,
} ;
return F_67 ( V_142 , V_271 , sizeof( V_273 ) , & V_273 ) ;
}
static inline int F_130 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_131 ( struct V_249 * V_251 , int V_232 , int V_180 , void * V_181 )
{
struct V_182 * V_183 = V_181 ;
struct V_238 * V_24 ;
struct V_141 * V_184 = V_183 -> V_184 ;
struct V_141 * V_142 = V_183 -> V_185 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , F_72 ( V_184 ) . V_155 , V_183 -> V_154 ,
V_278 , sizeof( * V_24 ) , V_183 -> V_186 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_24 = F_42 ( V_144 ) ;
F_116 ( V_251 , V_24 , V_232 ) ;
V_37 = F_126 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_128 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_130 ( V_251 -> type , V_142 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_142 , & V_251 -> V_131 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_132 ( struct V_187 * V_188 )
{
struct V_281 * V_190 = (struct V_281 * ) & V_188 -> args [ 1 ] ;
struct V_114 * V_114 = F_41 ( V_188 -> V_142 -> V_145 ) ;
F_133 ( V_190 , V_114 ) ;
return 0 ;
}
static int F_134 ( struct V_141 * V_142 , struct V_187 * V_188 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_281 * V_190 = (struct V_281 * ) & V_188 -> args [ 1 ] ;
struct V_182 V_192 ;
F_78 ( sizeof( struct V_281 ) >
sizeof( V_188 -> args ) - sizeof( V_188 -> args [ 0 ] ) ) ;
V_192 . V_184 = V_188 -> V_142 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_188 -> V_144 -> V_154 ;
V_192 . V_186 = V_193 ;
if ( ! V_188 -> args [ 0 ] ) {
V_188 -> args [ 0 ] = 1 ;
F_135 ( V_190 , V_282 ) ;
}
( void ) V_281 ( V_114 , V_190 , F_131 , & V_192 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_136 ( struct V_141 * V_184 ,
struct V_249 * V_251 ,
int V_232 , T_4 V_133 )
{
struct V_182 V_192 ;
struct V_141 * V_142 ;
int V_37 ;
V_142 = F_81 ( V_194 , V_67 ) ;
if ( ! V_142 )
return F_82 ( - V_68 ) ;
V_192 . V_184 = V_184 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_186 = 0 ;
V_37 = F_131 ( V_251 , V_232 , 0 , & V_192 ) ;
if ( V_37 ) {
F_83 ( V_142 ) ;
return F_82 ( V_37 ) ;
}
return V_142 ;
}
static int F_137 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_249 * V_251 ;
struct V_283 * V_24 ;
T_2 type = V_236 ;
int V_37 ;
struct V_146 V_147 ;
int V_284 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_24 = F_42 ( V_144 ) ;
V_284 = V_144 -> V_152 == V_285 ;
V_37 = F_114 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_105 ( V_24 -> V_232 ) ;
if ( V_37 )
return V_37 ;
if ( V_24 -> V_247 )
V_251 = F_138 ( V_114 , V_131 , type , V_24 -> V_232 , V_24 -> V_247 , V_284 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_286 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_286 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_37 = F_110 ( & V_286 , V_20 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_251 = F_139 ( V_114 , V_131 , type , V_24 -> V_232 , & V_24 -> V_89 ,
V_286 , V_284 , & V_37 ) ;
F_123 ( V_286 ) ;
}
if ( V_251 == NULL )
return - V_231 ;
if ( ! V_284 ) {
struct V_141 * V_226 ;
V_226 = F_136 ( V_142 , V_251 , V_24 -> V_232 , V_144 -> V_154 ) ;
if ( F_97 ( V_226 ) ) {
V_37 = F_98 ( V_226 ) ;
} else {
V_37 = F_91 ( V_114 -> V_134 . V_216 , V_226 ,
F_72 ( V_142 ) . V_155 ) ;
}
} else {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_140 ( V_251 , V_37 ? 0 : 1 , V_148 , V_150 ,
V_151 ) ;
if ( V_37 != 0 )
goto V_43;
V_147 . V_287 . V_288 = V_24 -> V_247 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_124 ( V_251 , V_24 -> V_232 , & V_147 ) ;
}
V_43:
F_125 ( V_251 ) ;
if ( V_284 && V_37 == 0 )
F_141 ( V_114 ) ;
return V_37 ;
}
static int F_142 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_289 * V_24 = F_42 ( V_144 ) ;
struct V_290 V_291 ;
int V_37 ;
V_291 . V_148 = F_43 ( V_149 ) ;
V_291 . V_150 = F_44 ( V_149 ) ;
F_48 ( V_149 , & V_291 . V_292 ) ;
V_37 = F_143 ( V_114 , V_24 -> V_34 , & V_291 ) ;
if ( V_37 ) {
if ( V_37 == - V_162 )
return 0 ;
return V_37 ;
}
V_147 . V_287 . V_34 = V_24 -> V_34 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_51 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_5 F_144 ( struct V_87 * V_88 )
{
T_5 V_293 = V_88 -> V_78 ?
F_12 ( V_88 -> V_78 ) :
sizeof( struct V_102 ) ;
return F_85 ( sizeof( struct V_294 ) )
+ F_86 ( V_293 )
+ F_86 ( sizeof( struct V_105 ) )
+ F_86 ( sizeof( struct V_159 ) )
+ F_86 ( 4 )
+ F_86 ( 4 ) ;
}
static int F_145 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_294 * V_33 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_295 , sizeof( * V_33 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_296 . V_163 , & V_88 -> V_33 . V_163 , sizeof( V_88 -> V_33 . V_163 ) ) ;
V_33 -> V_296 . V_46 = V_88 -> V_33 . V_46 ;
V_33 -> V_296 . V_38 = V_88 -> V_58 . V_38 ;
V_33 -> V_296 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_88 -> V_58 . V_92 ) ) ;
V_33 -> V_91 = V_88 -> V_58 . V_91 ;
V_33 -> V_28 = V_147 -> V_287 . V_297 ;
if ( V_88 -> V_78 ) {
V_37 = F_67 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
} else {
V_37 = F_67 ( V_142 , V_95 , sizeof( V_88 -> V_103 ) ,
& V_88 -> V_103 ) ;
}
if ( V_37 )
goto V_298;
V_37 = F_67 ( V_142 , V_98 , sizeof( V_88 -> V_107 ) , & V_88 -> V_107 ) ;
if ( V_37 )
goto V_298;
if ( V_33 -> V_28 & V_299 ) {
V_37 = F_66 ( V_142 , V_101 , V_88 -> V_113 ) ;
if ( V_37 )
goto V_298;
}
if ( V_33 -> V_28 & V_300 ) {
V_37 = F_66 ( V_142 , V_100 ,
V_88 -> V_112 * 10 / V_137 ) ;
if ( V_37 )
goto V_298;
}
V_37 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_37 )
goto V_298;
return F_74 ( V_142 , V_144 ) ;
V_298:
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
static int F_146 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_141 * V_214 ;
int V_37 ;
struct V_146 V_147 ;
T_4 V_131 ;
struct V_159 V_160 ;
struct V_294 * V_24 = F_42 ( V_144 ) ;
struct V_158 * V_33 = & V_24 -> V_296 ;
V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_33 -> V_163 , V_33 -> V_46 , V_33 -> V_34 , V_33 -> V_38 ) ;
if ( V_88 == NULL )
return - V_162 ;
V_214 = F_81 ( F_144 ( V_88 ) , V_195 ) ;
if ( V_214 == NULL ) {
F_39 ( V_88 ) ;
return - V_68 ;
}
F_147 ( & V_88 -> V_301 ) ;
V_147 . V_287 . V_297 = V_24 -> V_28 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
if ( F_145 ( V_214 , V_88 , & V_147 ) < 0 )
F_90 () ;
V_37 = F_91 ( V_114 -> V_134 . V_216 , V_214 , F_72 ( V_142 ) . V_155 ) ;
F_148 ( & V_88 -> V_301 ) ;
F_39 ( V_88 ) ;
return V_37 ;
}
static int F_149 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_146 V_147 ;
int V_37 = - V_7 ;
T_4 V_131 = 0 ;
struct V_159 V_160 ;
struct V_294 * V_24 = F_42 ( V_144 ) ;
struct V_1 * V_79 = V_2 [ V_95 ] ;
struct V_1 * V_96 = V_2 [ V_25 ] ;
struct V_1 * V_97 = V_2 [ V_98 ] ;
if ( ! V_97 && ! V_79 && ! V_96 )
return V_37 ;
if ( ! ( V_144 -> V_186 & V_302 ) )
return V_37 ;
V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_296 . V_163 , V_24 -> V_296 . V_46 , V_24 -> V_296 . V_34 , V_24 -> V_296 . V_38 ) ;
if ( V_88 == NULL )
return - V_162 ;
if ( V_88 -> V_132 . V_139 != V_303 )
goto V_43;
V_37 = F_23 ( V_88 -> V_78 , V_96 ) ;
if ( V_37 )
goto V_43;
F_147 ( & V_88 -> V_301 ) ;
F_30 ( V_88 , V_2 , 1 ) ;
F_148 ( & V_88 -> V_301 ) ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_287 . V_297 = V_304 ;
F_51 ( V_88 , & V_147 ) ;
V_37 = 0 ;
V_43:
F_39 ( V_88 ) ;
return V_37 ;
}
static int F_150 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
T_2 type = V_236 ;
int V_37 ;
struct V_290 V_291 ;
V_37 = F_114 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_291 . V_148 = F_43 ( V_149 ) ;
V_291 . V_150 = F_44 ( V_149 ) ;
F_48 ( V_149 , & V_291 . V_292 ) ;
V_37 = F_151 ( V_114 , type , & V_291 ) ;
if ( V_37 ) {
if ( V_37 == - V_162 )
return 0 ;
return V_37 ;
}
V_147 . V_287 . type = type ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_124 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_152 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_249 * V_251 ;
struct V_305 * V_80 = F_42 ( V_144 ) ;
struct V_238 * V_24 = & V_80 -> V_250 ;
T_2 type = V_236 ;
int V_37 = - V_231 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_37 = F_114 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_105 ( V_24 -> V_232 ) ;
if ( V_37 )
return V_37 ;
if ( V_24 -> V_247 )
V_251 = F_138 ( V_114 , V_131 , type , V_24 -> V_232 , V_24 -> V_247 , 0 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_286 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_286 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_37 = F_110 ( & V_286 , V_20 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_251 = F_139 ( V_114 , V_131 , type , V_24 -> V_232 ,
& V_24 -> V_89 , V_286 , 0 , & V_37 ) ;
F_123 ( V_286 ) ;
}
if ( V_251 == NULL )
return - V_231 ;
if ( F_153 ( V_251 -> V_190 . V_276 ) )
goto V_43;
V_37 = 0 ;
if ( V_80 -> V_306 ) {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_154 ( V_251 , V_24 -> V_232 ) ;
F_140 ( V_251 , 1 , V_148 , V_150 , V_151 ) ;
} else {
F_155 ( 1 , L_1 ) ;
}
F_156 ( V_251 , V_24 -> V_232 , V_80 -> V_306 , V_144 -> V_156 ) ;
V_43:
F_125 ( V_251 ) ;
return V_37 ;
}
static int F_157 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_37 ;
struct V_307 * V_308 = F_42 ( V_144 ) ;
struct V_23 * V_24 = & V_308 -> V_139 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_33 . V_163 , V_24 -> V_33 . V_46 , V_24 -> V_33 . V_34 , V_24 -> V_38 ) ;
V_37 = - V_231 ;
if ( V_88 == NULL )
return V_37 ;
F_147 ( & V_88 -> V_301 ) ;
V_37 = - V_7 ;
if ( V_88 -> V_132 . V_139 != V_303 )
goto V_43;
F_158 ( V_88 , V_308 -> V_306 , V_144 -> V_156 ) ;
if ( V_308 -> V_306 ) {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_159 ( V_88 ) ;
F_60 ( V_88 , 1 , V_148 , V_150 , V_151 ) ;
}
V_37 = 0 ;
V_43:
F_148 ( & V_88 -> V_301 ) ;
F_39 ( V_88 ) ;
return V_37 ;
}
static int F_160 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_249 * V_251 ;
struct V_252 * V_253 ;
int V_255 ;
struct V_1 * V_4 = V_2 [ V_268 ] ;
struct V_159 V_131 ;
struct V_309 * V_310 = F_42 ( V_144 ) ;
struct V_87 * V_88 = F_33 ( V_114 ) ;
int V_37 = - V_68 ;
if ( ! V_88 )
goto V_311;
F_35 ( V_2 , & V_131 ) ;
V_37 = F_108 ( & V_310 -> V_312 ) ;
if ( V_37 )
goto V_313;
V_251 = F_117 ( V_114 , & V_310 -> V_312 , V_2 , & V_37 ) ;
if ( ! V_251 )
goto V_314;
memcpy ( & V_88 -> V_33 , & V_310 -> V_33 , sizeof( V_310 -> V_33 ) ) ;
memcpy ( & V_88 -> V_58 . V_92 , & V_310 -> V_92 , sizeof( V_310 -> V_92 ) ) ;
memcpy ( & V_88 -> V_89 , & V_310 -> V_89 , sizeof( V_310 -> V_89 ) ) ;
V_251 -> V_131 . V_160 = V_88 -> V_131 . V_160 = V_131 . V_160 ;
V_251 -> V_131 . V_315 = V_88 -> V_131 . V_315 = V_131 . V_315 ;
V_253 = F_2 ( V_4 ) ;
for ( V_255 = 0 ; V_255 < V_251 -> V_256 ; V_255 ++ , V_253 ++ ) {
struct V_257 * V_258 = & V_251 -> V_259 [ V_255 ] ;
memcpy ( & V_88 -> V_33 , & V_258 -> V_33 , sizeof( V_88 -> V_33 ) ) ;
V_88 -> V_58 . V_47 = V_258 -> V_47 ;
V_88 -> V_58 . V_91 = V_258 -> V_91 ;
V_88 -> V_58 . V_38 = V_253 -> V_38 ;
V_258 -> V_262 = V_310 -> V_262 ;
V_258 -> V_263 = V_310 -> V_263 ;
V_258 -> V_264 = V_310 -> V_264 ;
V_37 = F_161 ( V_88 , V_258 , V_251 ) ;
}
F_26 ( V_88 ) ;
F_26 ( V_251 ) ;
return 0 ;
V_313:
F_155 ( 1 , L_2 ) ;
V_314:
F_26 ( V_88 ) ;
V_311:
return V_37 ;
}
static int F_162 ( struct V_316 * V_317 ,
struct V_318 * V_319 ,
struct V_1 * * V_2 , int * V_320 )
{
struct V_1 * V_4 = V_2 [ V_321 ] ;
struct V_322 * V_323 ;
int V_255 , V_324 ;
if ( V_319 != NULL ) {
struct V_325 * V_326 ;
V_326 = F_2 ( V_2 [ V_327 ] ) ;
memcpy ( & V_319 -> V_328 , & V_326 -> V_328 , sizeof( V_319 -> V_328 ) ) ;
memcpy ( & V_319 -> V_329 , & V_326 -> V_329 , sizeof( V_319 -> V_329 ) ) ;
V_319 -> V_38 = V_326 -> V_38 ;
V_319 -> V_330 = V_326 -> V_330 ;
}
V_323 = F_2 ( V_4 ) ;
V_324 = F_3 ( V_4 ) / sizeof( * V_323 ) ;
if ( V_324 <= 0 || V_324 > V_267 )
return - V_7 ;
for ( V_255 = 0 ; V_255 < V_324 ; V_255 ++ , V_323 ++ , V_317 ++ ) {
memcpy ( & V_317 -> V_331 , & V_323 -> V_331 , sizeof( V_317 -> V_331 ) ) ;
memcpy ( & V_317 -> V_332 , & V_323 -> V_332 , sizeof( V_317 -> V_332 ) ) ;
memcpy ( & V_317 -> V_333 , & V_323 -> V_333 , sizeof( V_317 -> V_333 ) ) ;
memcpy ( & V_317 -> V_334 , & V_323 -> V_334 , sizeof( V_317 -> V_334 ) ) ;
V_317 -> V_34 = V_323 -> V_34 ;
V_317 -> V_47 = V_323 -> V_47 ;
V_317 -> V_91 = V_323 -> V_91 ;
V_317 -> V_335 = V_323 -> V_335 ;
V_317 -> V_336 = V_323 -> V_336 ;
}
* V_320 = V_255 ;
return 0 ;
}
static int F_163 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_283 * V_337 = F_42 ( V_144 ) ;
struct V_316 V_160 [ V_267 ] ;
struct V_318 V_132 , * V_338 ;
T_2 type ;
int V_37 ;
int V_339 = 0 ;
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
if ( V_2 [ V_321 ] == NULL )
return - V_7 ;
V_338 = V_2 [ V_327 ] ? & V_132 : NULL ;
V_37 = F_114 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_162 ( (struct V_316 * ) V_160 , V_338 , V_2 , & V_339 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_339 )
return 0 ;
V_316 ( & V_337 -> V_89 , V_337 -> V_232 , type , V_160 , V_339 , V_338 , V_114 ) ;
return 0 ;
}
static int F_163 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
return - V_340 ;
}
static int F_164 ( const struct V_316 * V_160 , struct V_141 * V_142 )
{
struct V_322 V_323 ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
V_323 . V_34 = V_160 -> V_34 ;
V_323 . V_47 = V_160 -> V_47 ;
V_323 . V_91 = V_160 -> V_91 ;
V_323 . V_335 = V_160 -> V_335 ;
memcpy ( & V_323 . V_331 , & V_160 -> V_331 , sizeof( V_323 . V_331 ) ) ;
memcpy ( & V_323 . V_332 , & V_160 -> V_332 , sizeof( V_323 . V_332 ) ) ;
V_323 . V_336 = V_160 -> V_336 ;
memcpy ( & V_323 . V_333 , & V_160 -> V_333 , sizeof( V_323 . V_333 ) ) ;
memcpy ( & V_323 . V_334 , & V_160 -> V_334 , sizeof( V_323 . V_334 ) ) ;
return F_67 ( V_142 , V_321 , sizeof( V_323 ) , & V_323 ) ;
}
static int F_165 ( const struct V_318 * V_319 , struct V_141 * V_142 )
{
struct V_325 V_326 ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
V_326 . V_38 = V_319 -> V_38 ;
V_326 . V_330 = V_319 -> V_330 ;
memcpy ( & V_326 . V_328 , & V_319 -> V_328 , sizeof( V_326 . V_328 ) ) ;
memcpy ( & V_326 . V_329 , & V_319 -> V_329 , sizeof( V_326 . V_329 ) ) ;
return F_67 ( V_142 , V_327 , sizeof( V_326 ) , & V_326 ) ;
}
static inline T_5 F_166 ( int V_324 , int V_341 )
{
return F_85 ( sizeof( struct V_283 ) )
+ ( V_341 ? F_86 ( sizeof( struct V_318 ) ) : 0 )
+ F_86 ( sizeof( struct V_322 ) * V_324 )
+ F_129 () ;
}
static int F_167 ( struct V_141 * V_142 , const struct V_316 * V_160 ,
int V_324 , const struct V_318 * V_319 ,
const struct V_342 * V_89 , T_2 V_232 , T_2 type )
{
const struct V_316 * V_343 ;
struct V_283 * V_344 ;
struct V_143 * V_144 ;
int V_255 , V_37 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_345 , sizeof( * V_344 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_344 = F_42 ( V_144 ) ;
memset ( V_344 , 0 , sizeof( * V_344 ) ) ;
memcpy ( & V_344 -> V_89 , V_89 , sizeof( V_344 -> V_89 ) ) ;
V_344 -> V_232 = V_232 ;
if ( V_319 != NULL ) {
V_37 = F_165 ( V_319 , V_142 ) ;
if ( V_37 )
goto V_298;
}
V_37 = F_130 ( type , V_142 ) ;
if ( V_37 )
goto V_298;
for ( V_255 = 0 , V_343 = V_160 ; V_255 < V_324 ; V_255 ++ , V_343 ++ ) {
V_37 = F_164 ( V_343 , V_142 ) ;
if ( V_37 )
goto V_298;
}
return F_74 ( V_142 , V_144 ) ;
V_298:
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
static int F_168 ( const struct V_342 * V_89 , T_2 V_232 , T_2 type ,
const struct V_316 * V_160 , int V_324 ,
const struct V_318 * V_319 )
{
struct V_114 * V_114 = & V_346 ;
struct V_141 * V_142 ;
V_142 = F_81 ( F_166 ( V_324 , ! ! V_319 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_167 ( V_142 , V_160 , V_324 , V_319 , V_89 , V_232 , type ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_347 , V_195 ) ;
}
static int F_168 ( const struct V_342 * V_89 , T_2 V_232 , T_2 type ,
const struct V_316 * V_160 , int V_324 ,
const struct V_318 * V_319 )
{
return - V_340 ;
}
static int F_170 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_1 * V_2 [ V_348 + 1 ] ;
const struct V_349 * V_350 ;
int type , V_37 ;
type = V_144 -> V_152 ;
if ( type > V_351 )
return - V_7 ;
type -= V_352 ;
V_350 = & V_353 [ type ] ;
if ( ! F_171 ( V_114 -> V_354 , V_355 ) )
return - V_165 ;
if ( ( type == ( V_356 - V_352 ) ||
type == ( V_357 - V_352 ) ) &&
( V_144 -> V_186 & V_358 ) ) {
if ( V_350 -> V_359 == NULL )
return - V_7 ;
{
struct V_360 V_147 = {
. V_359 = V_350 -> V_359 ,
. V_361 = V_350 -> V_361 ,
} ;
return F_172 ( V_114 -> V_134 . V_216 , V_142 , V_144 , & V_147 ) ;
}
}
V_37 = F_173 ( V_144 , V_362 [ type ] , V_2 , V_348 ,
V_363 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_350 -> V_364 == NULL )
return - V_7 ;
return V_350 -> V_364 ( V_142 , V_144 , V_2 ) ;
}
static void F_174 ( struct V_141 * V_142 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
F_175 ( & V_114 -> V_134 . V_365 ) ;
F_176 ( V_142 , & F_170 ) ;
F_177 ( & V_114 -> V_134 . V_365 ) ;
}
static inline T_5 F_178 ( void )
{
return F_85 ( sizeof( struct V_307 ) )
+ F_86 ( sizeof( struct V_159 ) ) ;
}
static int F_179 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_307 * V_308 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , 0 , V_366 , sizeof( * V_308 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_308 = F_42 ( V_144 ) ;
F_61 ( V_88 , & V_308 -> V_139 ) ;
V_308 -> V_306 = ( V_147 -> V_287 . V_306 != 0 ) ? 1 : 0 ;
V_37 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_37 )
return V_37 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_180 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_81 ( F_178 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_179 ( V_142 , V_88 , V_147 ) < 0 ) {
F_83 ( V_142 ) ;
return - V_170 ;
}
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_367 , V_195 ) ;
}
static int F_182 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_81 ( F_144 ( V_88 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_145 ( V_142 , V_88 , V_147 ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_368 , V_195 ) ;
}
static int F_183 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_289 * V_24 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_85 ( sizeof( struct V_289 ) ) ;
V_142 = F_81 ( V_21 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_369 , sizeof( * V_24 ) , 0 ) ;
if ( V_144 == NULL ) {
F_83 ( V_142 ) ;
return - V_170 ;
}
V_24 = F_42 ( V_144 ) ;
V_24 -> V_34 = V_147 -> V_287 . V_34 ;
F_74 ( V_142 , V_144 ) ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_370 , V_195 ) ;
}
static inline T_5 F_184 ( struct V_87 * V_88 )
{
T_5 V_371 = 0 ;
if ( V_88 -> V_119 )
V_371 += F_86 ( F_8 ( V_88 -> V_119 ) ) ;
if ( V_88 -> V_121 ) {
V_371 += F_86 ( sizeof( struct V_5 ) +
( V_88 -> V_121 -> V_66 + 7 ) / 8 ) ;
V_371 += F_86 ( F_6 ( V_88 -> V_121 ) ) ;
}
if ( V_88 -> V_123 )
V_371 += F_86 ( F_4 ( V_88 -> V_123 ) ) ;
if ( V_88 -> V_125 )
V_371 += F_86 ( sizeof( * V_88 -> V_125 ) ) ;
if ( V_88 -> V_128 )
V_371 += F_86 ( sizeof( * V_88 -> V_128 ) ) ;
if ( V_88 -> V_129 )
V_371 += F_86 ( sizeof( V_88 -> V_129 ) ) ;
if ( V_88 -> V_78 )
V_371 += F_86 ( F_12 ( V_88 -> V_78 ) ) ;
if ( V_88 -> V_179 )
V_371 += F_86 ( sizeof( struct V_19 ) +
V_88 -> V_179 -> V_22 ) ;
if ( V_88 -> V_130 )
V_371 += F_86 ( sizeof( * V_88 -> V_130 ) ) ;
if ( V_88 -> V_58 . V_118 )
V_371 += F_86 ( sizeof( V_88 -> V_58 . V_118 ) ) ;
V_371 += F_86 ( sizeof( V_372 ) ) ;
return V_371 ;
}
static int F_185 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_23 * V_24 ;
struct V_158 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_184 ( V_88 ) ;
int V_373 , V_37 ;
V_373 = sizeof( * V_24 ) ;
if ( V_147 -> V_157 == V_374 ) {
V_21 += F_86 ( V_373 ) ;
V_373 = sizeof( * V_33 ) ;
V_21 += F_86 ( sizeof( struct V_159 ) ) ;
}
V_21 += F_85 ( V_373 ) ;
V_142 = F_81 ( V_21 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_373 , 0 ) ;
V_37 = - V_170 ;
if ( V_144 == NULL )
goto V_375;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_157 == V_374 ) {
struct V_1 * V_168 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_163 , & V_88 -> V_33 . V_163 , sizeof( V_33 -> V_163 ) ) ;
V_33 -> V_46 = V_88 -> V_33 . V_46 ;
V_33 -> V_38 = V_88 -> V_58 . V_38 ;
V_33 -> V_34 = V_88 -> V_33 . V_34 ;
V_168 = F_63 ( V_142 , V_376 , sizeof( * V_24 ) ) ;
V_37 = - V_170 ;
if ( V_168 == NULL )
goto V_375;
V_24 = F_2 ( V_168 ) ;
}
V_37 = F_65 ( V_88 , V_24 , V_142 ) ;
if ( V_37 )
goto V_375;
F_74 ( V_142 , V_144 ) ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_370 , V_195 ) ;
V_375:
F_83 ( V_142 ) ;
return V_37 ;
}
static int F_186 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_366 :
return F_180 ( V_88 , V_147 ) ;
case V_295 :
return F_182 ( V_88 , V_147 ) ;
case V_374 :
case V_377 :
case V_153 :
return F_185 ( V_88 , V_147 ) ;
case V_369 :
return F_183 ( V_147 ) ;
default:
F_187 ( V_378 L_3 ,
V_147 -> V_157 ) ;
break;
}
return 0 ;
}
static inline T_5 F_188 ( struct V_87 * V_88 ,
struct V_249 * V_251 )
{
return F_85 ( sizeof( struct V_309 ) )
+ F_86 ( sizeof( struct V_252 ) * V_251 -> V_256 )
+ F_86 ( sizeof( struct V_159 ) )
+ F_86 ( F_27 ( V_88 -> V_179 ) )
+ F_129 () ;
}
static int F_189 ( struct V_141 * V_142 , struct V_87 * V_88 ,
struct V_257 * V_379 , struct V_249 * V_251 )
{
T_7 V_133 = F_190 () ;
struct V_309 * V_310 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_380 , sizeof( * V_310 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_310 = F_42 ( V_144 ) ;
memcpy ( & V_310 -> V_33 , & V_88 -> V_33 , sizeof( V_310 -> V_33 ) ) ;
memcpy ( & V_310 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_310 -> V_92 ) ) ;
memcpy ( & V_310 -> V_89 , & V_88 -> V_89 , sizeof( V_310 -> V_89 ) ) ;
F_116 ( V_251 , & V_310 -> V_312 , V_234 ) ;
V_310 -> V_262 = V_379 -> V_262 ;
V_310 -> V_263 = V_379 -> V_263 ;
V_310 -> V_264 = V_379 -> V_264 ;
V_310 -> V_133 = V_88 -> V_132 . V_133 = V_133 ;
V_37 = F_126 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_127 ( V_88 , V_142 ) ;
if ( ! V_37 )
V_37 = F_130 ( V_251 -> type , V_142 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_142 , & V_251 -> V_131 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_191 ( struct V_87 * V_88 , struct V_257 * V_379 ,
struct V_249 * V_251 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_81 ( F_188 ( V_88 , V_251 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_189 ( V_142 , V_88 , V_379 , V_251 ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_381 , V_195 ) ;
}
static struct V_249 * F_192 ( struct V_191 * V_145 , int V_382 ,
T_2 * V_287 , int V_21 , int * V_232 )
{
struct V_114 * V_114 = F_41 ( V_145 ) ;
struct V_238 * V_24 = (struct V_238 * ) V_287 ;
struct V_252 * V_253 = (struct V_252 * ) ( V_24 + 1 ) ;
struct V_249 * V_251 ;
int V_254 ;
switch ( V_145 -> V_383 ) {
case V_39 :
if ( V_382 != V_384 ) {
* V_232 = - V_385 ;
return NULL ;
}
break;
#if F_14 ( V_41 )
case V_40 :
if ( V_382 != V_386 ) {
* V_232 = - V_385 ;
return NULL ;
}
break;
#endif
default:
* V_232 = - V_7 ;
return NULL ;
}
* V_232 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_108 ( V_24 ) )
return NULL ;
V_254 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_253 ) ) ;
if ( F_112 ( V_254 , V_253 , V_24 -> V_89 . V_38 ) )
return NULL ;
if ( V_24 -> V_232 > V_234 )
return NULL ;
V_251 = F_118 ( V_114 , V_195 ) ;
if ( V_251 == NULL ) {
* V_232 = - V_387 ;
return NULL ;
}
F_115 ( V_251 , V_24 ) ;
V_251 -> type = V_236 ;
F_111 ( V_251 , V_253 , V_254 ) ;
* V_232 = V_24 -> V_232 ;
return V_251 ;
}
static inline T_5 F_193 ( struct V_249 * V_251 )
{
return F_85 ( sizeof( struct V_305 ) )
+ F_86 ( sizeof( struct V_252 ) * V_251 -> V_256 )
+ F_86 ( F_27 ( V_251 -> V_179 ) )
+ F_86 ( sizeof( struct V_159 ) )
+ F_129 () ;
}
static int F_194 ( struct V_141 * V_142 , struct V_249 * V_251 ,
int V_232 , const struct V_146 * V_147 )
{
struct V_305 * V_388 ;
int V_306 = V_147 -> V_287 . V_306 ;
struct V_143 * V_144 ;
int V_37 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , 0 , V_389 , sizeof( * V_388 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_388 = F_42 ( V_144 ) ;
F_116 ( V_251 , & V_388 -> V_250 , V_232 ) ;
V_37 = F_126 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_128 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_130 ( V_251 -> type , V_142 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_142 , & V_251 -> V_131 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
V_388 -> V_306 = ! ! V_306 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_195 ( struct V_249 * V_251 , int V_232 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_196 ( V_251 ) ;
struct V_141 * V_142 ;
V_142 = F_81 ( F_193 ( V_251 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_194 ( V_142 , V_251 , V_232 , V_147 ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_367 , V_195 ) ;
}
static int F_197 ( struct V_249 * V_251 , int V_232 , const struct V_146 * V_147 )
{
int V_21 = F_86 ( sizeof( struct V_252 ) * V_251 -> V_256 ) ;
struct V_114 * V_114 = F_196 ( V_251 ) ;
struct V_238 * V_24 ;
struct V_283 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_373 , V_37 ;
V_373 = sizeof( * V_24 ) ;
if ( V_147 -> V_157 == V_285 ) {
V_21 += F_86 ( V_373 ) ;
V_373 = sizeof( * V_33 ) ;
}
V_21 += F_129 () ;
V_21 += F_86 ( sizeof( struct V_159 ) ) ;
V_21 += F_85 ( V_373 ) ;
V_142 = F_81 ( V_21 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_373 , 0 ) ;
V_37 = - V_170 ;
if ( V_144 == NULL )
goto V_375;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_157 == V_285 ) {
struct V_1 * V_168 ;
V_33 = F_42 ( V_144 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_232 = V_232 ;
if ( V_147 -> V_287 . V_288 )
V_33 -> V_247 = V_251 -> V_247 ;
else
memcpy ( & V_33 -> V_89 , & V_251 -> V_275 , sizeof( V_33 -> V_89 ) ) ;
V_168 = F_63 ( V_142 , V_390 , sizeof( * V_24 ) ) ;
V_37 = - V_170 ;
if ( V_168 == NULL )
goto V_375;
V_24 = F_2 ( V_168 ) ;
}
F_116 ( V_251 , V_24 , V_232 ) ;
V_37 = F_126 ( V_251 , V_142 ) ;
if ( ! V_37 )
V_37 = F_130 ( V_251 -> type , V_142 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_142 , & V_251 -> V_131 ) ;
if ( V_37 )
goto V_375;
F_74 ( V_142 , V_144 ) ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_391 , V_195 ) ;
V_375:
F_83 ( V_142 ) ;
return V_37 ;
}
static int F_198 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_37 ;
V_142 = F_81 ( F_129 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_392 , 0 , 0 ) ;
V_37 = - V_170 ;
if ( V_144 == NULL )
goto V_375;
V_37 = F_130 ( V_147 -> V_287 . type , V_142 ) ;
if ( V_37 )
goto V_375;
F_74 ( V_142 , V_144 ) ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_391 , V_195 ) ;
V_375:
F_83 ( V_142 ) ;
return V_37 ;
}
static int F_199 ( struct V_249 * V_251 , int V_232 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_278 :
case V_393 :
case V_285 :
return F_197 ( V_251 , V_232 , V_147 ) ;
case V_392 :
return F_198 ( V_147 ) ;
case V_389 :
return F_195 ( V_251 , V_232 , V_147 ) ;
default:
F_187 ( V_378 L_4 ,
V_147 -> V_157 ) ;
}
return 0 ;
}
static inline T_5 F_200 ( void )
{
return F_85 ( sizeof( struct V_394 ) ) ;
}
static int F_201 ( struct V_141 * V_142 , T_2 V_34 ,
struct V_342 * V_89 , T_1 * V_395 )
{
struct V_394 * V_396 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_397 , sizeof( * V_396 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_396 = F_42 ( V_144 ) ;
V_396 -> V_34 = V_34 ;
memcpy ( & V_396 -> V_89 , V_89 , sizeof( V_396 -> V_89 ) ) ;
if ( V_395 ) {
int V_37 = F_67 ( V_142 , V_53 , sizeof( * V_395 ) , V_395 ) ;
if ( V_37 ) {
F_73 ( V_142 , V_144 ) ;
return V_37 ;
}
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_202 ( struct V_114 * V_114 , T_2 V_34 ,
struct V_342 * V_89 , T_1 * V_395 )
{
struct V_141 * V_142 ;
V_142 = F_81 ( F_200 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_201 ( V_142 , V_34 , V_89 , V_395 ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_398 , V_195 ) ;
}
static inline T_5 F_203 ( void )
{
return F_85 ( sizeof( struct V_399 ) ) ;
}
static int F_204 ( struct V_141 * V_142 , struct V_87 * V_88 ,
T_1 * V_334 , T_8 V_400 )
{
struct V_399 * V_323 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_401 , sizeof( * V_323 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_323 = F_42 ( V_144 ) ;
memcpy ( & V_323 -> V_33 . V_163 , & V_88 -> V_33 . V_163 , sizeof( V_323 -> V_33 . V_163 ) ) ;
V_323 -> V_33 . V_46 = V_88 -> V_33 . V_46 ;
V_323 -> V_33 . V_38 = V_88 -> V_58 . V_38 ;
V_323 -> V_33 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_323 -> V_334 , V_334 , sizeof( V_323 -> V_334 ) ) ;
memcpy ( & V_323 -> V_332 , & V_88 -> V_58 . V_92 , sizeof( V_323 -> V_332 ) ) ;
V_323 -> V_400 = V_400 ;
V_323 -> V_402 = V_88 -> V_128 -> V_403 ;
V_323 -> V_91 = V_88 -> V_58 . V_91 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_205 ( struct V_87 * V_88 , T_1 * V_404 ,
T_8 V_405 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
if ( V_88 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_88 -> V_128 )
return - V_7 ;
V_142 = F_81 ( F_203 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_204 ( V_142 , V_88 , V_404 , V_405 ) < 0 )
F_90 () ;
return F_169 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_406 , V_195 ) ;
}
static int T_9 F_206 ( struct V_114 * V_114 )
{
struct V_191 * V_216 ;
struct V_407 V_408 = {
. V_409 = V_410 ,
. V_411 = F_174 ,
} ;
V_216 = F_207 ( V_114 , V_412 , & V_408 ) ;
if ( V_216 == NULL )
return - V_68 ;
V_114 -> V_134 . V_413 = V_216 ;
F_208 ( V_114 -> V_134 . V_216 , V_216 ) ;
return 0 ;
}
static void T_10 F_209 ( struct V_414 * V_415 )
{
struct V_114 * V_114 ;
F_210 (net, net_exit_list, exit_list)
F_211 ( V_114 -> V_134 . V_216 , NULL ) ;
F_212 () ;
F_210 (net, net_exit_list, exit_list)
F_213 ( V_114 -> V_134 . V_413 ) ;
}
static int T_11 F_214 ( void )
{
int V_416 ;
F_187 ( V_417 L_5 ) ;
V_416 = F_215 ( & V_418 ) ;
if ( V_416 < 0 )
return V_416 ;
V_416 = F_216 ( & V_419 ) ;
if ( V_416 < 0 )
F_217 ( & V_418 ) ;
return V_416 ;
}
static void T_12 F_218 ( void )
{
F_219 ( & V_419 ) ;
F_217 ( & V_418 ) ;
}
