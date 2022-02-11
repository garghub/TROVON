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
if ( ( V_24 -> V_33 . V_34 != V_35 ) && ( V_24 -> V_33 . V_34 != V_36 ) )
return - V_7 ;
if ( V_24 -> V_37 != 0 )
return - V_7 ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_1 * * V_2 )
{
int V_38 ;
V_38 = - V_7 ;
switch ( V_24 -> V_39 ) {
case V_40 :
break;
case V_41 :
#if F_14 ( V_42 )
break;
#else
V_38 = - V_43 ;
goto V_44;
#endif
default:
goto V_44;
}
V_38 = - V_7 ;
switch ( V_24 -> V_33 . V_34 ) {
case V_36 :
if ( ( ! V_2 [ V_8 ] &&
! V_2 [ V_13 ] ) ||
V_2 [ V_15 ] ||
V_2 [ V_9 ] ||
V_2 [ V_10 ] ||
V_2 [ V_45 ] ||
( F_15 ( V_24 -> V_33 . V_46 ) >= 0x10000 ) )
goto V_44;
break;
case V_35 :
if ( V_2 [ V_10 ] )
goto V_44;
if ( ! V_2 [ V_8 ] &&
! V_2 [ V_13 ] &&
! V_2 [ V_9 ] &&
! V_2 [ V_15 ] )
goto V_44;
if ( ( V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_9 ] ) &&
V_2 [ V_15 ] )
goto V_44;
if ( V_2 [ V_45 ] &&
V_24 -> V_47 != V_48 )
goto V_44;
break;
case V_49 :
if ( ! V_2 [ V_10 ] ||
V_2 [ V_15 ] ||
V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_9 ] ||
V_2 [ V_45 ] )
goto V_44;
break;
#if F_14 ( V_42 )
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
goto V_44;
break;
#endif
default:
goto V_44;
}
if ( ( V_38 = F_7 ( V_2 ) ) )
goto V_44;
if ( ( V_38 = F_5 ( V_2 ) ) )
goto V_44;
if ( ( V_38 = F_1 ( V_2 , V_8 ) ) )
goto V_44;
if ( ( V_38 = F_1 ( V_2 , V_9 ) ) )
goto V_44;
if ( ( V_38 = F_1 ( V_2 , V_10 ) ) )
goto V_44;
if ( ( V_38 = F_10 ( V_2 ) ) )
goto V_44;
if ( ( V_38 = F_11 ( V_24 , V_2 ) ) )
goto V_44;
V_38 = - V_7 ;
switch ( V_24 -> V_47 ) {
case V_54 :
case V_48 :
case V_55 :
case V_56 :
break;
default:
goto V_44;
}
V_38 = 0 ;
V_44:
return V_38 ;
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
V_88 -> V_58 . V_37 = F_29 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_88 -> V_58 . V_91 = V_24 -> V_91 ;
V_88 -> V_58 . V_39 = V_24 -> V_39 ;
memcpy ( & V_88 -> V_58 . V_92 , & V_24 -> V_92 , sizeof( V_88 -> V_58 . V_92 ) ) ;
V_88 -> V_58 . V_28 = V_24 -> V_28 ;
if ( ! V_88 -> V_89 . V_39 && ! ( V_24 -> V_28 & V_93 ) )
V_88 -> V_89 . V_39 = V_24 -> V_39 ;
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
int V_38 = - V_68 ;
if ( ! V_88 )
goto V_116;
F_28 ( V_88 , V_24 ) ;
if ( V_2 [ V_117 ] )
V_88 -> V_58 . V_118 = F_31 ( V_2 [ V_117 ] ) ;
if ( ( V_38 = F_21 ( & V_88 -> V_119 , & V_88 -> V_58 . V_120 ,
V_2 [ V_15 ] ) ) )
goto error;
if ( ( V_38 = F_19 ( & V_88 -> V_121 , & V_88 -> V_58 . V_122 ,
V_2 [ V_13 ] ) ) )
goto error;
if ( ! V_88 -> V_58 . V_122 ) {
if ( ( V_38 = F_16 ( & V_88 -> V_121 , & V_88 -> V_58 . V_122 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_38 = F_34 ( & V_88 -> V_123 , & V_88 -> V_58 . V_120 ,
V_124 ,
V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_38 = F_34 ( & V_88 -> V_125 , & V_88 -> V_58 . V_126 ,
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
V_38 = F_36 ( V_88 , false ) ;
if ( V_38 )
goto error;
if ( V_2 [ V_18 ] &&
F_37 ( V_88 , F_2 ( V_2 [ V_18 ] ) ) )
goto error;
if ( ( V_38 = F_24 ( & V_88 -> V_78 , & V_88 -> V_82 ,
V_2 [ V_25 ] ) ) )
goto error;
V_88 -> V_132 . V_133 = V_24 -> V_133 ;
V_88 -> V_113 = V_114 -> V_134 . V_135 ;
V_88 -> V_112 = ( V_114 -> V_134 . V_136 * V_137 ) / V_138 ;
if ( ( V_38 = F_38 ( V_88 ) ) )
goto error;
F_30 ( V_88 , V_2 , 0 ) ;
return V_88 ;
error:
V_88 -> V_132 . V_139 = V_140 ;
F_39 ( V_88 ) ;
V_116:
* V_115 = V_38 ;
return NULL ;
}
static int F_40 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_23 * V_24 = F_42 ( V_144 ) ;
struct V_87 * V_88 ;
int V_38 ;
struct V_146 V_147 ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_38 = F_13 ( V_24 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_88 = F_32 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( ! V_88 )
return V_38 ;
F_45 ( V_88 ) ;
if ( V_144 -> V_152 == V_153 )
V_38 = F_46 ( V_88 ) ;
else
V_38 = F_47 ( V_88 ) ;
F_48 ( V_149 , & V_151 ) ;
F_49 ( V_88 , V_38 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_38 < 0 ) {
V_88 -> V_132 . V_139 = V_140 ;
F_50 ( V_88 ) ;
goto V_44;
}
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_51 ( V_88 , & V_147 ) ;
V_44:
F_39 ( V_88 ) ;
return V_38 ;
}
static struct V_87 * F_52 ( struct V_114 * V_114 ,
struct V_158 * V_24 ,
struct V_1 * * V_2 ,
int * V_115 )
{
struct V_87 * V_88 = NULL ;
struct V_159 V_160 ;
int V_38 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
if ( F_53 ( V_24 -> V_34 , V_161 ) ) {
V_38 = - V_162 ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_163 , V_24 -> V_46 , V_24 -> V_34 , V_24 -> V_39 ) ;
} else {
T_1 * V_92 = NULL ;
F_9 ( V_2 , V_164 , & V_92 ) ;
if ( ! V_92 ) {
V_38 = - V_7 ;
goto V_44;
}
V_38 = - V_162 ;
V_88 = F_55 ( V_114 , V_131 ,
& V_24 -> V_163 , V_92 ,
V_24 -> V_34 , V_24 -> V_39 ) ;
}
V_44:
if ( ! V_88 && V_115 )
* V_115 = V_38 ;
return V_88 ;
}
static int F_56 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_38 = - V_162 ;
struct V_146 V_147 ;
struct V_158 * V_24 = F_42 ( V_144 ) ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_88 = F_52 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( V_88 == NULL )
return V_38 ;
if ( ( V_38 = F_57 ( V_88 ) ) != 0 )
goto V_44;
if ( F_58 ( V_88 ) ) {
V_38 = - V_165 ;
goto V_44;
}
V_38 = F_59 ( V_88 ) ;
if ( V_38 < 0 )
goto V_44;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_51 ( V_88 , & V_147 ) ;
V_44:
F_48 ( V_149 , & V_151 ) ;
F_60 ( V_88 , V_38 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
F_39 ( V_88 ) ;
return V_38 ;
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
V_24 -> V_37 = V_88 -> V_58 . V_37 ;
V_24 -> V_91 = V_88 -> V_58 . V_91 ;
V_24 -> V_39 = V_88 -> V_58 . V_39 ;
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
goto V_44;
}
if ( V_88 -> V_130 ) {
V_176 = F_67 ( V_142 , V_53 , sizeof( * V_88 -> V_130 ) , V_88 -> V_130 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_177 ) {
V_176 = F_68 ( V_142 , V_178 , V_88 -> V_177 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_119 ) {
V_176 = F_67 ( V_142 , V_15 , F_8 ( V_88 -> V_119 ) , V_88 -> V_119 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_121 ) {
V_176 = F_64 ( V_88 -> V_121 , V_142 ) ;
if ( ! V_176 )
V_176 = F_67 ( V_142 , V_13 ,
F_6 ( V_88 -> V_121 ) , V_88 -> V_121 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_123 ) {
V_176 = F_67 ( V_142 , V_9 , F_4 ( V_88 -> V_123 ) , V_88 -> V_123 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_125 ) {
V_176 = F_67 ( V_142 , V_10 , sizeof( * ( V_88 -> V_125 ) ) , V_88 -> V_125 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_128 ) {
V_176 = F_67 ( V_142 , V_52 , sizeof( * V_88 -> V_128 ) , V_88 -> V_128 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_129 ) {
V_176 = F_66 ( V_142 , V_45 , V_88 -> V_129 ) ;
if ( V_176 )
goto V_44;
}
V_176 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_176 )
goto V_44;
if ( V_88 -> V_78 ) {
V_176 = F_67 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
if ( V_176 )
goto V_44;
}
if ( V_88 -> V_179 )
V_176 = F_62 ( V_88 -> V_179 , V_142 ) ;
V_44:
return V_176 ;
}
static int F_70 ( struct V_87 * V_88 , int V_180 , void * V_181 )
{
struct V_182 * V_183 = V_181 ;
struct V_141 * V_184 = V_183 -> V_184 ;
struct V_141 * V_142 = V_183 -> V_185 ;
struct V_23 * V_24 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , F_72 ( V_184 ) . V_155 , V_183 -> V_154 ,
V_153 , sizeof( * V_24 ) , V_183 -> V_186 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_24 = F_42 ( V_144 ) ;
V_38 = F_65 ( V_88 , V_24 , V_142 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
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
struct V_1 * V_2 [ V_194 + 1 ] ;
struct V_195 * V_196 = NULL ;
T_2 V_34 = 0 ;
int V_38 ;
V_188 -> args [ 0 ] = 1 ;
V_38 = F_79 ( V_188 -> V_144 , 0 , V_2 , V_194 ,
V_197 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_198 ] ) {
V_196 = F_18 ( sizeof( * V_196 ) , V_67 ) ;
if ( V_196 == NULL )
return - V_68 ;
memcpy ( V_196 , F_2 ( V_2 [ V_198 ] ) ,
sizeof( * V_196 ) ) ;
}
if ( V_2 [ V_199 ] )
V_34 = F_80 ( V_2 [ V_199 ] ) ;
F_81 ( V_190 , V_34 , V_196 ) ;
}
( void ) V_189 ( V_114 , V_190 , F_70 , & V_192 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_82 ( struct V_141 * V_184 ,
struct V_87 * V_88 , T_4 V_133 )
{
struct V_182 V_192 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( V_200 , V_201 ) ;
if ( ! V_142 )
return F_84 ( - V_68 ) ;
V_192 . V_184 = V_184 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_186 = 0 ;
V_38 = F_70 ( V_88 , 0 , & V_192 ) ;
if ( V_38 ) {
F_85 ( V_142 ) ;
return F_84 ( V_38 ) ;
}
return V_142 ;
}
static inline T_5 F_86 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_202 ) )
+ F_88 ( sizeof( struct V_203 ) ) ;
}
static int F_89 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_28 )
{
struct V_204 V_205 ;
struct V_202 V_206 ;
struct V_203 V_207 ;
struct V_143 * V_144 ;
int V_38 ;
T_4 * V_208 ;
V_144 = F_71 ( V_142 , V_155 , V_133 , V_209 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_208 = F_42 ( V_144 ) ;
* V_208 = V_28 ;
F_90 ( V_114 , & V_205 ) ;
V_206 . V_210 = V_205 . V_210 ;
V_206 . V_211 = V_205 . V_211 ;
V_206 . V_212 = V_205 . V_212 ;
V_206 . V_213 = V_205 . V_213 ;
V_206 . V_214 = V_205 . V_214 ;
V_206 . V_215 = V_205 . V_215 ;
V_207 . V_216 = V_205 . V_216 ;
V_207 . V_217 = V_205 . V_217 ;
V_38 = F_67 ( V_142 , V_218 , sizeof( V_206 ) , & V_206 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_219 , sizeof( V_207 ) , & V_207 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_91 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_220 ;
T_4 * V_28 = F_42 ( V_144 ) ;
T_4 V_221 = F_72 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_220 = F_83 ( F_86 () , V_201 ) ;
if ( V_220 == NULL )
return - V_68 ;
if ( F_89 ( V_220 , V_114 , V_221 , V_133 , * V_28 ) < 0 )
F_92 () ;
return F_93 ( V_114 -> V_134 . V_222 , V_220 , V_221 ) ;
}
static inline T_5 F_94 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_223 ) )
+ F_88 ( 4 ) ;
}
static int F_95 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_28 )
{
struct V_224 V_205 ;
struct V_223 V_225 ;
struct V_143 * V_144 ;
int V_38 ;
T_4 * V_208 ;
V_144 = F_71 ( V_142 , V_155 , V_133 , V_226 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_208 = F_42 ( V_144 ) ;
* V_208 = V_28 ;
F_96 ( V_114 , & V_205 ) ;
V_225 . V_227 = V_205 . V_227 ;
V_225 . V_228 = V_205 . V_228 ;
V_38 = F_66 ( V_142 , V_229 , V_205 . V_230 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_231 , sizeof( V_225 ) , & V_225 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_97 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_220 ;
T_4 * V_28 = F_42 ( V_144 ) ;
T_4 V_221 = F_72 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_220 = F_83 ( F_94 () , V_201 ) ;
if ( V_220 == NULL )
return - V_68 ;
if ( F_95 ( V_220 , V_114 , V_221 , V_133 , * V_28 ) < 0 )
F_92 () ;
return F_93 ( V_114 -> V_134 . V_222 , V_220 , V_221 ) ;
}
static int F_98 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_158 * V_24 = F_42 ( V_144 ) ;
struct V_87 * V_88 ;
struct V_141 * V_232 ;
int V_38 = - V_162 ;
V_88 = F_52 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( V_88 == NULL )
goto V_233;
V_232 = F_82 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_99 ( V_232 ) ) {
V_38 = F_100 ( V_232 ) ;
} else {
V_38 = F_93 ( V_114 -> V_134 . V_222 , V_232 , F_72 ( V_142 ) . V_155 ) ;
}
F_39 ( V_88 ) ;
V_233:
return V_38 ;
}
static int F_101 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_234 * V_24 ;
struct V_141 * V_232 ;
T_1 * V_163 ;
int V_39 ;
int V_38 ;
T_4 V_131 ;
struct V_159 V_160 ;
V_24 = F_42 ( V_144 ) ;
V_38 = F_102 ( V_24 -> V_192 . V_33 . V_34 , V_24 -> V_235 , V_24 -> V_236 ) ;
if ( V_38 )
goto V_233;
V_39 = V_24 -> V_192 . V_39 ;
V_163 = & V_24 -> V_192 . V_33 . V_163 ;
V_88 = NULL ;
V_131 = F_35 ( V_2 , & V_160 ) ;
if ( V_24 -> V_192 . V_133 ) {
V_88 = F_103 ( V_114 , V_131 , V_24 -> V_192 . V_133 ) ;
if ( V_88 && ! F_104 ( & V_88 -> V_33 . V_163 , V_163 , V_39 ) ) {
F_39 ( V_88 ) ;
V_88 = NULL ;
}
}
if ( ! V_88 )
V_88 = F_105 ( V_114 , & V_160 , V_24 -> V_192 . V_47 , V_24 -> V_192 . V_91 ,
V_24 -> V_192 . V_33 . V_34 , V_163 ,
& V_24 -> V_192 . V_92 , 1 ,
V_39 ) ;
V_38 = - V_237 ;
if ( V_88 == NULL )
goto V_233;
V_38 = F_106 ( V_88 , V_24 -> V_235 , V_24 -> V_236 ) ;
if ( V_38 )
goto V_44;
V_232 = F_82 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_99 ( V_232 ) ) {
V_38 = F_100 ( V_232 ) ;
goto V_44;
}
V_38 = F_93 ( V_114 -> V_134 . V_222 , V_232 , F_72 ( V_142 ) . V_155 ) ;
V_44:
F_39 ( V_88 ) ;
V_233:
return V_38 ;
}
static int F_107 ( T_2 V_238 )
{
switch ( V_238 ) {
case V_239 :
case V_240 :
case V_241 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_108 ( T_2 type )
{
switch ( type ) {
case V_242 :
#ifdef F_109
case V_243 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_110 ( struct V_244 * V_24 )
{
int V_176 ;
switch ( V_24 -> V_245 ) {
case V_246 :
case V_247 :
case V_248 :
case V_249 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_250 ) {
case V_251 :
case V_252 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_89 . V_39 ) {
case V_40 :
break;
case V_41 :
#if F_14 ( V_42 )
break;
#else
return - V_43 ;
#endif
default:
return - V_7 ;
}
V_176 = F_107 ( V_24 -> V_238 ) ;
if ( V_176 )
return V_176 ;
if ( V_24 -> V_253 && ( ( V_24 -> V_253 & V_254 ) != V_24 -> V_238 ) )
return - V_7 ;
return 0 ;
}
static int F_111 ( struct V_255 * V_256 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_112 ( & V_256 -> V_179 , V_20 , V_67 ) ;
}
static void F_113 ( struct V_255 * V_257 , struct V_258 * V_259 ,
int V_260 )
{
int V_261 ;
V_257 -> V_262 = V_260 ;
for ( V_261 = 0 ; V_261 < V_260 ; V_261 ++ , V_259 ++ ) {
struct V_263 * V_264 = & V_257 -> V_265 [ V_261 ] ;
memcpy ( & V_264 -> V_33 , & V_259 -> V_33 , sizeof( struct V_266 ) ) ;
memcpy ( & V_264 -> V_92 , & V_259 -> V_92 ,
sizeof( T_1 ) ) ;
V_264 -> V_91 = V_259 -> V_91 ;
V_264 -> V_47 = V_259 -> V_47 ;
V_264 -> V_245 = V_259 -> V_245 ;
V_264 -> V_267 = V_259 -> V_267 ;
V_264 -> V_268 = V_259 -> V_268 ;
V_264 -> V_269 = V_259 -> V_269 ;
V_264 -> V_270 = V_259 -> V_270 ;
V_264 -> V_271 = ! ~ ( V_264 -> V_268 & V_264 -> V_269 & V_264 -> V_270 ) ;
V_264 -> V_272 = V_259 -> V_39 ;
}
}
static int F_114 ( int V_260 , struct V_258 * V_259 , T_6 V_39 )
{
int V_261 ;
if ( V_260 > V_273 )
return - V_7 ;
for ( V_261 = 0 ; V_261 < V_260 ; V_261 ++ ) {
if ( ! V_259 [ V_261 ] . V_39 )
V_259 [ V_261 ] . V_39 = V_39 ;
switch ( V_259 [ V_261 ] . V_39 ) {
case V_40 :
break;
#if F_14 ( V_42 )
case V_41 :
break;
#endif
default:
return - V_7 ;
}
}
return 0 ;
}
static int F_115 ( struct V_255 * V_256 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_274 ] ;
if ( ! V_4 ) {
V_256 -> V_262 = 0 ;
} else {
struct V_258 * V_275 = F_2 ( V_4 ) ;
int V_260 = F_3 ( V_4 ) / sizeof( * V_275 ) ;
int V_38 ;
V_38 = F_114 ( V_260 , V_275 , V_256 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_113 ( V_256 , V_275 , V_260 ) ;
}
return 0 ;
}
static int F_116 ( T_2 * V_276 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_277 ] ;
struct V_278 * V_279 ;
T_2 type = V_242 ;
int V_38 ;
if ( V_4 ) {
V_279 = F_2 ( V_4 ) ;
type = V_279 -> type ;
}
V_38 = F_108 ( type ) ;
if ( V_38 )
return V_38 ;
* V_276 = type ;
return 0 ;
}
static void F_117 ( struct V_255 * V_257 , struct V_244 * V_24 )
{
V_257 -> V_280 = V_24 -> V_280 ;
V_257 -> V_253 = V_24 -> V_253 ;
memcpy ( & V_257 -> V_281 , & V_24 -> V_89 , sizeof( V_257 -> V_281 ) ) ;
memcpy ( & V_257 -> V_90 , & V_24 -> V_90 , sizeof( V_257 -> V_90 ) ) ;
V_257 -> V_250 = V_24 -> V_250 ;
V_257 -> V_28 = V_24 -> V_28 ;
V_257 -> V_39 = V_24 -> V_89 . V_39 ;
}
static void F_118 ( struct V_255 * V_257 , struct V_244 * V_24 , int V_238 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_89 , & V_257 -> V_281 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_90 , & V_257 -> V_90 , sizeof( V_24 -> V_90 ) ) ;
memcpy ( & V_24 -> V_107 , & V_257 -> V_107 , sizeof( V_24 -> V_107 ) ) ;
V_24 -> V_280 = V_257 -> V_280 ;
V_24 -> V_253 = V_257 -> V_253 ;
V_24 -> V_89 . V_39 = V_257 -> V_39 ;
V_24 -> V_238 = V_238 ;
V_24 -> V_250 = V_257 -> V_250 ;
V_24 -> V_28 = V_257 -> V_28 ;
V_24 -> V_245 = V_246 ;
}
static struct V_255 * F_119 ( struct V_114 * V_114 , struct V_244 * V_24 , struct V_1 * * V_2 , int * V_115 )
{
struct V_255 * V_257 = F_120 ( V_114 , V_67 ) ;
int V_38 ;
if ( ! V_257 ) {
* V_115 = - V_68 ;
return NULL ;
}
F_117 ( V_257 , V_24 ) ;
V_38 = F_116 ( & V_257 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_115 ( V_257 , V_2 ) ) )
V_38 = F_111 ( V_257 , V_2 ) ;
if ( V_38 )
goto error;
F_35 ( V_2 , & V_257 -> V_131 ) ;
return V_257 ;
error:
* V_115 = V_38 ;
V_257 -> V_190 . V_282 = 1 ;
F_121 ( V_257 ) ;
return NULL ;
}
static int F_122 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_244 * V_24 = F_42 ( V_144 ) ;
struct V_255 * V_257 ;
struct V_146 V_147 ;
int V_38 ;
int V_283 ;
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
V_38 = F_110 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_257 = F_119 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( ! V_257 )
return V_38 ;
V_283 = V_144 -> V_152 == V_284 ;
V_38 = F_123 ( V_24 -> V_238 , V_257 , V_283 ) ;
F_48 ( V_149 , & V_151 ) ;
F_124 ( V_257 , V_38 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_38 ) {
F_125 ( V_257 -> V_179 ) ;
F_26 ( V_257 ) ;
return V_38 ;
}
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_126 ( V_257 , V_24 -> V_238 , & V_147 ) ;
F_127 ( V_257 ) ;
return 0 ;
}
static int F_128 ( struct V_255 * V_257 , struct V_141 * V_142 )
{
struct V_258 V_285 [ V_273 ] ;
int V_261 ;
if ( V_257 -> V_262 == 0 )
return 0 ;
for ( V_261 = 0 ; V_261 < V_257 -> V_262 ; V_261 ++ ) {
struct V_258 * V_80 = & V_285 [ V_261 ] ;
struct V_263 * V_286 = & V_257 -> V_265 [ V_261 ] ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( & V_80 -> V_33 , & V_286 -> V_33 , sizeof( V_80 -> V_33 ) ) ;
V_80 -> V_39 = V_286 -> V_272 ;
memcpy ( & V_80 -> V_92 , & V_286 -> V_92 , sizeof( V_80 -> V_92 ) ) ;
V_80 -> V_91 = V_286 -> V_91 ;
V_80 -> V_47 = V_286 -> V_47 ;
V_80 -> V_245 = V_286 -> V_245 ;
V_80 -> V_267 = V_286 -> V_267 ;
V_80 -> V_268 = V_286 -> V_268 ;
V_80 -> V_269 = V_286 -> V_269 ;
V_80 -> V_270 = V_286 -> V_270 ;
}
return F_67 ( V_142 , V_274 ,
sizeof( struct V_258 ) * V_257 -> V_262 , V_285 ) ;
}
static inline int F_129 ( struct V_87 * V_88 , struct V_141 * V_142 )
{
if ( V_88 -> V_179 ) {
return F_62 ( V_88 -> V_179 , V_142 ) ;
}
return 0 ;
}
static inline int F_130 ( struct V_255 * V_257 , struct V_141 * V_142 )
{
if ( V_257 -> V_179 )
return F_62 ( V_257 -> V_179 , V_142 ) ;
return 0 ;
}
static inline T_5 F_131 ( void )
{
#ifdef F_109
return F_88 ( sizeof( struct V_278 ) ) ;
#else
return 0 ;
#endif
}
static int F_132 ( T_2 type , struct V_141 * V_142 )
{
struct V_278 V_279 = {
. type = type ,
} ;
return F_67 ( V_142 , V_277 , sizeof( V_279 ) , & V_279 ) ;
}
static inline int F_132 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_133 ( struct V_255 * V_257 , int V_238 , int V_180 , void * V_181 )
{
struct V_182 * V_183 = V_181 ;
struct V_244 * V_24 ;
struct V_141 * V_184 = V_183 -> V_184 ;
struct V_141 * V_142 = V_183 -> V_185 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , F_72 ( V_184 ) . V_155 , V_183 -> V_154 ,
V_284 , sizeof( * V_24 ) , V_183 -> V_186 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_24 = F_42 ( V_144 ) ;
F_118 ( V_257 , V_24 , V_238 ) ;
V_38 = F_128 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_130 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_257 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_257 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_134 ( struct V_187 * V_188 )
{
struct V_287 * V_190 = (struct V_287 * ) & V_188 -> args [ 1 ] ;
struct V_114 * V_114 = F_41 ( V_188 -> V_142 -> V_145 ) ;
F_135 ( V_190 , V_114 ) ;
return 0 ;
}
static int F_136 ( struct V_141 * V_142 , struct V_187 * V_188 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_287 * V_190 = (struct V_287 * ) & V_188 -> args [ 1 ] ;
struct V_182 V_192 ;
F_78 ( sizeof( struct V_287 ) >
sizeof( V_188 -> args ) - sizeof( V_188 -> args [ 0 ] ) ) ;
V_192 . V_184 = V_188 -> V_142 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_188 -> V_144 -> V_154 ;
V_192 . V_186 = V_193 ;
if ( ! V_188 -> args [ 0 ] ) {
V_188 -> args [ 0 ] = 1 ;
F_137 ( V_190 , V_288 ) ;
}
( void ) V_287 ( V_114 , V_190 , F_133 , & V_192 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_138 ( struct V_141 * V_184 ,
struct V_255 * V_257 ,
int V_238 , T_4 V_133 )
{
struct V_182 V_192 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( V_200 , V_67 ) ;
if ( ! V_142 )
return F_84 ( - V_68 ) ;
V_192 . V_184 = V_184 ;
V_192 . V_185 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_186 = 0 ;
V_38 = F_133 ( V_257 , V_238 , 0 , & V_192 ) ;
if ( V_38 ) {
F_85 ( V_142 ) ;
return F_84 ( V_38 ) ;
}
return V_142 ;
}
static int F_139 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_255 * V_257 ;
struct V_289 * V_24 ;
T_2 type = V_242 ;
int V_38 ;
struct V_146 V_147 ;
int V_290 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_24 = F_42 ( V_144 ) ;
V_290 = V_144 -> V_152 == V_291 ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_107 ( V_24 -> V_238 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_253 )
V_257 = F_140 ( V_114 , V_131 , type , V_24 -> V_238 , V_24 -> V_253 , V_290 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_292 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_292 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_112 ( & V_292 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_257 = F_141 ( V_114 , V_131 , type , V_24 -> V_238 , & V_24 -> V_89 ,
V_292 , V_290 , & V_38 ) ;
F_125 ( V_292 ) ;
}
if ( V_257 == NULL )
return - V_237 ;
if ( ! V_290 ) {
struct V_141 * V_232 ;
V_232 = F_138 ( V_142 , V_257 , V_24 -> V_238 , V_144 -> V_154 ) ;
if ( F_99 ( V_232 ) ) {
V_38 = F_100 ( V_232 ) ;
} else {
V_38 = F_93 ( V_114 -> V_134 . V_222 , V_232 ,
F_72 ( V_142 ) . V_155 ) ;
}
} else {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_142 ( V_257 , V_38 ? 0 : 1 , V_148 , V_150 ,
V_151 ) ;
if ( V_38 != 0 )
goto V_44;
V_147 . V_293 . V_294 = V_24 -> V_253 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_126 ( V_257 , V_24 -> V_238 , & V_147 ) ;
}
V_44:
F_127 ( V_257 ) ;
if ( V_290 && V_38 == 0 )
F_143 ( V_114 ) ;
return V_38 ;
}
static int F_144 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_295 * V_24 = F_42 ( V_144 ) ;
struct V_296 V_297 ;
int V_38 ;
V_297 . V_148 = F_43 ( V_149 ) ;
V_297 . V_150 = F_44 ( V_149 ) ;
F_48 ( V_149 , & V_297 . V_298 ) ;
V_38 = F_145 ( V_114 , V_24 -> V_34 , & V_297 ) ;
if ( V_38 ) {
if ( V_38 == - V_162 )
return 0 ;
return V_38 ;
}
V_147 . V_293 . V_34 = V_24 -> V_34 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_51 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_5 F_146 ( struct V_87 * V_88 )
{
T_5 V_299 = V_88 -> V_78 ?
F_12 ( V_88 -> V_78 ) :
sizeof( struct V_102 ) ;
return F_87 ( sizeof( struct V_300 ) )
+ F_88 ( V_299 )
+ F_88 ( sizeof( struct V_105 ) )
+ F_88 ( sizeof( struct V_159 ) )
+ F_88 ( 4 )
+ F_88 ( 4 ) ;
}
static int F_147 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_300 * V_33 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_301 , sizeof( * V_33 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_302 . V_163 , & V_88 -> V_33 . V_163 , sizeof( V_88 -> V_33 . V_163 ) ) ;
V_33 -> V_302 . V_46 = V_88 -> V_33 . V_46 ;
V_33 -> V_302 . V_39 = V_88 -> V_58 . V_39 ;
V_33 -> V_302 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_88 -> V_58 . V_92 ) ) ;
V_33 -> V_91 = V_88 -> V_58 . V_91 ;
V_33 -> V_28 = V_147 -> V_293 . V_303 ;
if ( V_88 -> V_78 ) {
V_38 = F_67 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
} else {
V_38 = F_67 ( V_142 , V_95 , sizeof( V_88 -> V_103 ) ,
& V_88 -> V_103 ) ;
}
if ( V_38 )
goto V_304;
V_38 = F_67 ( V_142 , V_98 , sizeof( V_88 -> V_107 ) , & V_88 -> V_107 ) ;
if ( V_38 )
goto V_304;
if ( V_33 -> V_28 & V_305 ) {
V_38 = F_66 ( V_142 , V_101 , V_88 -> V_113 ) ;
if ( V_38 )
goto V_304;
}
if ( V_33 -> V_28 & V_306 ) {
V_38 = F_66 ( V_142 , V_100 ,
V_88 -> V_112 * 10 / V_137 ) ;
if ( V_38 )
goto V_304;
}
V_38 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_38 )
goto V_304;
return F_74 ( V_142 , V_144 ) ;
V_304:
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_148 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_141 * V_220 ;
int V_38 ;
struct V_146 V_147 ;
T_4 V_131 ;
struct V_159 V_160 ;
struct V_300 * V_24 = F_42 ( V_144 ) ;
struct V_158 * V_33 = & V_24 -> V_302 ;
V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_33 -> V_163 , V_33 -> V_46 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_88 == NULL )
return - V_162 ;
V_220 = F_83 ( F_146 ( V_88 ) , V_201 ) ;
if ( V_220 == NULL ) {
F_39 ( V_88 ) ;
return - V_68 ;
}
F_149 ( & V_88 -> V_307 ) ;
V_147 . V_293 . V_303 = V_24 -> V_28 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
if ( F_147 ( V_220 , V_88 , & V_147 ) < 0 )
F_92 () ;
V_38 = F_93 ( V_114 -> V_134 . V_222 , V_220 , F_72 ( V_142 ) . V_155 ) ;
F_150 ( & V_88 -> V_307 ) ;
F_39 ( V_88 ) ;
return V_38 ;
}
static int F_151 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_146 V_147 ;
int V_38 = - V_7 ;
T_4 V_131 = 0 ;
struct V_159 V_160 ;
struct V_300 * V_24 = F_42 ( V_144 ) ;
struct V_1 * V_79 = V_2 [ V_95 ] ;
struct V_1 * V_96 = V_2 [ V_25 ] ;
struct V_1 * V_97 = V_2 [ V_98 ] ;
if ( ! V_97 && ! V_79 && ! V_96 )
return V_38 ;
if ( ! ( V_144 -> V_186 & V_308 ) )
return V_38 ;
V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_302 . V_163 , V_24 -> V_302 . V_46 , V_24 -> V_302 . V_34 , V_24 -> V_302 . V_39 ) ;
if ( V_88 == NULL )
return - V_162 ;
if ( V_88 -> V_132 . V_139 != V_309 )
goto V_44;
V_38 = F_23 ( V_88 -> V_78 , V_96 ) ;
if ( V_38 )
goto V_44;
F_149 ( & V_88 -> V_307 ) ;
F_30 ( V_88 , V_2 , 1 ) ;
F_150 ( & V_88 -> V_307 ) ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_293 . V_303 = V_310 ;
F_51 ( V_88 , & V_147 ) ;
V_38 = 0 ;
V_44:
F_39 ( V_88 ) ;
return V_38 ;
}
static int F_152 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
T_2 type = V_242 ;
int V_38 ;
struct V_296 V_297 ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_297 . V_148 = F_43 ( V_149 ) ;
V_297 . V_150 = F_44 ( V_149 ) ;
F_48 ( V_149 , & V_297 . V_298 ) ;
V_38 = F_153 ( V_114 , type , & V_297 ) ;
if ( V_38 ) {
if ( V_38 == - V_162 )
return 0 ;
return V_38 ;
}
V_147 . V_293 . type = type ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_126 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_154 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_255 * V_257 ;
struct V_311 * V_80 = F_42 ( V_144 ) ;
struct V_244 * V_24 = & V_80 -> V_256 ;
T_2 type = V_242 ;
int V_38 = - V_237 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_107 ( V_24 -> V_238 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_253 )
V_257 = F_140 ( V_114 , V_131 , type , V_24 -> V_238 , V_24 -> V_253 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_292 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_292 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_112 ( & V_292 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_257 = F_141 ( V_114 , V_131 , type , V_24 -> V_238 ,
& V_24 -> V_89 , V_292 , 0 , & V_38 ) ;
F_125 ( V_292 ) ;
}
if ( V_257 == NULL )
return - V_237 ;
if ( F_155 ( V_257 -> V_190 . V_282 ) )
goto V_44;
V_38 = 0 ;
if ( V_80 -> V_312 ) {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_156 ( V_257 , V_24 -> V_238 ) ;
F_142 ( V_257 , 1 , V_148 , V_150 , V_151 ) ;
} else {
F_157 ( 1 , L_1 ) ;
}
F_158 ( V_257 , V_24 -> V_238 , V_80 -> V_312 , V_144 -> V_156 ) ;
V_44:
F_127 ( V_257 ) ;
return V_38 ;
}
static int F_159 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_38 ;
struct V_313 * V_314 = F_42 ( V_144 ) ;
struct V_23 * V_24 = & V_314 -> V_139 ;
struct V_159 V_160 ;
T_4 V_131 = F_35 ( V_2 , & V_160 ) ;
V_88 = F_54 ( V_114 , V_131 , & V_24 -> V_33 . V_163 , V_24 -> V_33 . V_46 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_237 ;
if ( V_88 == NULL )
return V_38 ;
F_149 ( & V_88 -> V_307 ) ;
V_38 = - V_7 ;
if ( V_88 -> V_132 . V_139 != V_309 )
goto V_44;
F_160 ( V_88 , V_314 -> V_312 , V_144 -> V_156 ) ;
if ( V_314 -> V_312 ) {
T_3 V_148 = F_43 ( V_149 ) ;
unsigned int V_150 = F_44 ( V_149 ) ;
T_4 V_151 ;
F_48 ( V_149 , & V_151 ) ;
F_161 ( V_88 ) ;
F_60 ( V_88 , 1 , V_148 , V_150 , V_151 ) ;
}
V_38 = 0 ;
V_44:
F_150 ( & V_88 -> V_307 ) ;
F_39 ( V_88 ) ;
return V_38 ;
}
static int F_162 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_255 * V_257 ;
struct V_258 * V_259 ;
int V_261 ;
struct V_1 * V_4 = V_2 [ V_274 ] ;
struct V_159 V_131 ;
struct V_315 * V_316 = F_42 ( V_144 ) ;
struct V_87 * V_88 = F_33 ( V_114 ) ;
int V_38 = - V_68 ;
if ( ! V_88 )
goto V_317;
F_35 ( V_2 , & V_131 ) ;
V_38 = F_110 ( & V_316 -> V_318 ) ;
if ( V_38 )
goto V_319;
V_257 = F_119 ( V_114 , & V_316 -> V_318 , V_2 , & V_38 ) ;
if ( ! V_257 )
goto V_320;
memcpy ( & V_88 -> V_33 , & V_316 -> V_33 , sizeof( V_316 -> V_33 ) ) ;
memcpy ( & V_88 -> V_58 . V_92 , & V_316 -> V_92 , sizeof( V_316 -> V_92 ) ) ;
memcpy ( & V_88 -> V_89 , & V_316 -> V_89 , sizeof( V_316 -> V_89 ) ) ;
V_257 -> V_131 . V_160 = V_88 -> V_131 . V_160 = V_131 . V_160 ;
V_257 -> V_131 . V_321 = V_88 -> V_131 . V_321 = V_131 . V_321 ;
V_259 = F_2 ( V_4 ) ;
for ( V_261 = 0 ; V_261 < V_257 -> V_262 ; V_261 ++ , V_259 ++ ) {
struct V_263 * V_264 = & V_257 -> V_265 [ V_261 ] ;
memcpy ( & V_88 -> V_33 , & V_264 -> V_33 , sizeof( V_88 -> V_33 ) ) ;
V_88 -> V_58 . V_47 = V_264 -> V_47 ;
V_88 -> V_58 . V_91 = V_264 -> V_91 ;
V_88 -> V_58 . V_39 = V_259 -> V_39 ;
V_264 -> V_268 = V_316 -> V_268 ;
V_264 -> V_269 = V_316 -> V_269 ;
V_264 -> V_270 = V_316 -> V_270 ;
V_38 = F_163 ( V_88 , V_264 , V_257 ) ;
}
F_26 ( V_88 ) ;
F_26 ( V_257 ) ;
return 0 ;
V_319:
F_157 ( 1 , L_2 ) ;
V_320:
F_26 ( V_88 ) ;
V_317:
return V_38 ;
}
static int F_164 ( struct V_322 * V_323 ,
struct V_324 * V_325 ,
struct V_1 * * V_2 , int * V_326 )
{
struct V_1 * V_4 = V_2 [ V_327 ] ;
struct V_328 * V_329 ;
int V_261 , V_330 ;
if ( V_325 != NULL ) {
struct V_331 * V_332 ;
V_332 = F_2 ( V_2 [ V_333 ] ) ;
memcpy ( & V_325 -> V_334 , & V_332 -> V_334 , sizeof( V_325 -> V_334 ) ) ;
memcpy ( & V_325 -> V_335 , & V_332 -> V_335 , sizeof( V_325 -> V_335 ) ) ;
V_325 -> V_39 = V_332 -> V_39 ;
V_325 -> V_336 = V_332 -> V_336 ;
}
V_329 = F_2 ( V_4 ) ;
V_330 = F_3 ( V_4 ) / sizeof( * V_329 ) ;
if ( V_330 <= 0 || V_330 > V_273 )
return - V_7 ;
for ( V_261 = 0 ; V_261 < V_330 ; V_261 ++ , V_329 ++ , V_323 ++ ) {
memcpy ( & V_323 -> V_337 , & V_329 -> V_337 , sizeof( V_323 -> V_337 ) ) ;
memcpy ( & V_323 -> V_338 , & V_329 -> V_338 , sizeof( V_323 -> V_338 ) ) ;
memcpy ( & V_323 -> V_339 , & V_329 -> V_339 , sizeof( V_323 -> V_339 ) ) ;
memcpy ( & V_323 -> V_340 , & V_329 -> V_340 , sizeof( V_323 -> V_340 ) ) ;
V_323 -> V_34 = V_329 -> V_34 ;
V_323 -> V_47 = V_329 -> V_47 ;
V_323 -> V_91 = V_329 -> V_91 ;
V_323 -> V_341 = V_329 -> V_341 ;
V_323 -> V_342 = V_329 -> V_342 ;
}
* V_326 = V_261 ;
return 0 ;
}
static int F_165 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_289 * V_343 = F_42 ( V_144 ) ;
struct V_322 V_160 [ V_273 ] ;
struct V_324 V_132 , * V_344 ;
T_2 type ;
int V_38 ;
int V_345 = 0 ;
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
if ( V_2 [ V_327 ] == NULL )
return - V_7 ;
V_344 = V_2 [ V_333 ] ? & V_132 : NULL ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_164 ( (struct V_322 * ) V_160 , V_344 , V_2 , & V_345 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_345 )
return 0 ;
V_322 ( & V_343 -> V_89 , V_343 -> V_238 , type , V_160 , V_345 , V_344 , V_114 ) ;
return 0 ;
}
static int F_165 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
return - V_346 ;
}
static int F_166 ( const struct V_322 * V_160 , struct V_141 * V_142 )
{
struct V_328 V_329 ;
memset ( & V_329 , 0 , sizeof( V_329 ) ) ;
V_329 . V_34 = V_160 -> V_34 ;
V_329 . V_47 = V_160 -> V_47 ;
V_329 . V_91 = V_160 -> V_91 ;
V_329 . V_341 = V_160 -> V_341 ;
memcpy ( & V_329 . V_337 , & V_160 -> V_337 , sizeof( V_329 . V_337 ) ) ;
memcpy ( & V_329 . V_338 , & V_160 -> V_338 , sizeof( V_329 . V_338 ) ) ;
V_329 . V_342 = V_160 -> V_342 ;
memcpy ( & V_329 . V_339 , & V_160 -> V_339 , sizeof( V_329 . V_339 ) ) ;
memcpy ( & V_329 . V_340 , & V_160 -> V_340 , sizeof( V_329 . V_340 ) ) ;
return F_67 ( V_142 , V_327 , sizeof( V_329 ) , & V_329 ) ;
}
static int F_167 ( const struct V_324 * V_325 , struct V_141 * V_142 )
{
struct V_331 V_332 ;
memset ( & V_332 , 0 , sizeof( V_332 ) ) ;
V_332 . V_39 = V_325 -> V_39 ;
V_332 . V_336 = V_325 -> V_336 ;
memcpy ( & V_332 . V_334 , & V_325 -> V_334 , sizeof( V_332 . V_334 ) ) ;
memcpy ( & V_332 . V_335 , & V_325 -> V_335 , sizeof( V_332 . V_335 ) ) ;
return F_67 ( V_142 , V_333 , sizeof( V_332 ) , & V_332 ) ;
}
static inline T_5 F_168 ( int V_330 , int V_347 )
{
return F_87 ( sizeof( struct V_289 ) )
+ ( V_347 ? F_88 ( sizeof( struct V_324 ) ) : 0 )
+ F_88 ( sizeof( struct V_328 ) * V_330 )
+ F_131 () ;
}
static int F_169 ( struct V_141 * V_142 , const struct V_322 * V_160 ,
int V_330 , const struct V_324 * V_325 ,
const struct V_348 * V_89 , T_2 V_238 , T_2 type )
{
const struct V_322 * V_349 ;
struct V_289 * V_350 ;
struct V_143 * V_144 ;
int V_261 , V_38 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_351 , sizeof( * V_350 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_350 = F_42 ( V_144 ) ;
memset ( V_350 , 0 , sizeof( * V_350 ) ) ;
memcpy ( & V_350 -> V_89 , V_89 , sizeof( V_350 -> V_89 ) ) ;
V_350 -> V_238 = V_238 ;
if ( V_325 != NULL ) {
V_38 = F_167 ( V_325 , V_142 ) ;
if ( V_38 )
goto V_304;
}
V_38 = F_132 ( type , V_142 ) ;
if ( V_38 )
goto V_304;
for ( V_261 = 0 , V_349 = V_160 ; V_261 < V_330 ; V_261 ++ , V_349 ++ ) {
V_38 = F_166 ( V_349 , V_142 ) ;
if ( V_38 )
goto V_304;
}
return F_74 ( V_142 , V_144 ) ;
V_304:
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_170 ( const struct V_348 * V_89 , T_2 V_238 , T_2 type ,
const struct V_322 * V_160 , int V_330 ,
const struct V_324 * V_325 )
{
struct V_114 * V_114 = & V_352 ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_168 ( V_330 , ! ! V_325 ) , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_169 ( V_142 , V_160 , V_330 , V_325 , V_89 , V_238 , type ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_353 , V_201 ) ;
}
static int F_170 ( const struct V_348 * V_89 , T_2 V_238 , T_2 type ,
const struct V_322 * V_160 , int V_330 ,
const struct V_324 * V_325 )
{
return - V_346 ;
}
static int F_172 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_1 * V_2 [ V_194 + 1 ] ;
const struct V_354 * V_355 ;
int type , V_38 ;
type = V_144 -> V_152 ;
if ( type > V_356 )
return - V_7 ;
type -= V_357 ;
V_355 = & V_358 [ type ] ;
if ( ! F_173 ( V_142 , V_359 ) )
return - V_165 ;
if ( ( type == ( V_360 - V_357 ) ||
type == ( V_361 - V_357 ) ) &&
( V_144 -> V_186 & V_362 ) ) {
if ( V_355 -> V_363 == NULL )
return - V_7 ;
{
struct V_364 V_147 = {
. V_363 = V_355 -> V_363 ,
. V_365 = V_355 -> V_365 ,
} ;
return F_174 ( V_114 -> V_134 . V_222 , V_142 , V_144 , & V_147 ) ;
}
}
V_38 = F_79 ( V_144 , V_366 [ type ] , V_2 , V_194 ,
V_197 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_355 -> V_367 == NULL )
return - V_7 ;
return V_355 -> V_367 ( V_142 , V_144 , V_2 ) ;
}
static void F_175 ( struct V_141 * V_142 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
F_176 ( & V_114 -> V_134 . V_368 ) ;
F_177 ( V_142 , & F_172 ) ;
F_178 ( & V_114 -> V_134 . V_368 ) ;
}
static inline T_5 F_179 ( void )
{
return F_87 ( sizeof( struct V_313 ) )
+ F_88 ( sizeof( struct V_159 ) ) ;
}
static int F_180 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_313 * V_314 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , 0 , V_369 , sizeof( * V_314 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_314 = F_42 ( V_144 ) ;
F_61 ( V_88 , & V_314 -> V_139 ) ;
V_314 -> V_312 = ( V_147 -> V_293 . V_312 != 0 ) ? 1 : 0 ;
V_38 = F_69 ( V_142 , & V_88 -> V_131 ) ;
if ( V_38 )
return V_38 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_181 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_182 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_179 () , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_180 ( V_142 , V_88 , V_147 ) < 0 ) {
F_85 ( V_142 ) ;
return - V_170 ;
}
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_370 , V_201 ) ;
}
static int F_183 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_182 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_146 ( V_88 ) , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_147 ( V_142 , V_88 , V_147 ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_371 , V_201 ) ;
}
static int F_184 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_295 * V_24 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_87 ( sizeof( struct V_295 ) ) ;
V_142 = F_83 ( V_21 , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_372 , sizeof( * V_24 ) , 0 ) ;
if ( V_144 == NULL ) {
F_85 ( V_142 ) ;
return - V_170 ;
}
V_24 = F_42 ( V_144 ) ;
V_24 -> V_34 = V_147 -> V_293 . V_34 ;
F_74 ( V_142 , V_144 ) ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_373 , V_201 ) ;
}
static inline T_5 F_185 ( struct V_87 * V_88 )
{
T_5 V_374 = 0 ;
if ( V_88 -> V_119 )
V_374 += F_88 ( F_8 ( V_88 -> V_119 ) ) ;
if ( V_88 -> V_121 ) {
V_374 += F_88 ( sizeof( struct V_5 ) +
( V_88 -> V_121 -> V_66 + 7 ) / 8 ) ;
V_374 += F_88 ( F_6 ( V_88 -> V_121 ) ) ;
}
if ( V_88 -> V_123 )
V_374 += F_88 ( F_4 ( V_88 -> V_123 ) ) ;
if ( V_88 -> V_125 )
V_374 += F_88 ( sizeof( * V_88 -> V_125 ) ) ;
if ( V_88 -> V_128 )
V_374 += F_88 ( sizeof( * V_88 -> V_128 ) ) ;
if ( V_88 -> V_129 )
V_374 += F_88 ( sizeof( V_88 -> V_129 ) ) ;
if ( V_88 -> V_78 )
V_374 += F_88 ( F_12 ( V_88 -> V_78 ) ) ;
if ( V_88 -> V_179 )
V_374 += F_88 ( sizeof( struct V_19 ) +
V_88 -> V_179 -> V_22 ) ;
if ( V_88 -> V_130 )
V_374 += F_88 ( sizeof( * V_88 -> V_130 ) ) ;
if ( V_88 -> V_58 . V_118 )
V_374 += F_88 ( sizeof( V_88 -> V_58 . V_118 ) ) ;
V_374 += F_88 ( sizeof( V_375 ) ) ;
return V_374 ;
}
static int F_186 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_182 ( V_88 ) ;
struct V_23 * V_24 ;
struct V_158 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_185 ( V_88 ) ;
int V_376 , V_38 ;
V_376 = sizeof( * V_24 ) ;
if ( V_147 -> V_157 == V_377 ) {
V_21 += F_88 ( V_376 ) ;
V_376 = sizeof( * V_33 ) ;
V_21 += F_88 ( sizeof( struct V_159 ) ) ;
}
V_21 += F_87 ( V_376 ) ;
V_142 = F_83 ( V_21 , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_376 , 0 ) ;
V_38 = - V_170 ;
if ( V_144 == NULL )
goto V_378;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_157 == V_377 ) {
struct V_1 * V_168 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_163 , & V_88 -> V_33 . V_163 , sizeof( V_33 -> V_163 ) ) ;
V_33 -> V_46 = V_88 -> V_33 . V_46 ;
V_33 -> V_39 = V_88 -> V_58 . V_39 ;
V_33 -> V_34 = V_88 -> V_33 . V_34 ;
V_168 = F_63 ( V_142 , V_379 , sizeof( * V_24 ) ) ;
V_38 = - V_170 ;
if ( V_168 == NULL )
goto V_378;
V_24 = F_2 ( V_168 ) ;
}
V_38 = F_65 ( V_88 , V_24 , V_142 ) ;
if ( V_38 )
goto V_378;
F_74 ( V_142 , V_144 ) ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_373 , V_201 ) ;
V_378:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_187 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_369 :
return F_181 ( V_88 , V_147 ) ;
case V_301 :
return F_183 ( V_88 , V_147 ) ;
case V_377 :
case V_380 :
case V_153 :
return F_186 ( V_88 , V_147 ) ;
case V_372 :
return F_184 ( V_147 ) ;
default:
F_188 ( V_381 L_3 ,
V_147 -> V_157 ) ;
break;
}
return 0 ;
}
static inline T_5 F_189 ( struct V_87 * V_88 ,
struct V_255 * V_257 )
{
return F_87 ( sizeof( struct V_315 ) )
+ F_88 ( sizeof( struct V_258 ) * V_257 -> V_262 )
+ F_88 ( sizeof( struct V_159 ) )
+ F_88 ( F_27 ( V_88 -> V_179 ) )
+ F_131 () ;
}
static int F_190 ( struct V_141 * V_142 , struct V_87 * V_88 ,
struct V_263 * V_382 , struct V_255 * V_257 )
{
T_7 V_133 = F_191 () ;
struct V_315 * V_316 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_383 , sizeof( * V_316 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_316 = F_42 ( V_144 ) ;
memcpy ( & V_316 -> V_33 , & V_88 -> V_33 , sizeof( V_316 -> V_33 ) ) ;
memcpy ( & V_316 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_316 -> V_92 ) ) ;
memcpy ( & V_316 -> V_89 , & V_88 -> V_89 , sizeof( V_316 -> V_89 ) ) ;
F_118 ( V_257 , & V_316 -> V_318 , V_240 ) ;
V_316 -> V_268 = V_382 -> V_268 ;
V_316 -> V_269 = V_382 -> V_269 ;
V_316 -> V_270 = V_382 -> V_270 ;
V_316 -> V_133 = V_88 -> V_132 . V_133 = V_133 ;
V_38 = F_128 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_129 ( V_88 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_257 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_257 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_192 ( struct V_87 * V_88 , struct V_263 * V_382 ,
struct V_255 * V_257 )
{
struct V_114 * V_114 = F_182 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_189 ( V_88 , V_257 ) , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_190 ( V_142 , V_88 , V_382 , V_257 ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_384 , V_201 ) ;
}
static struct V_255 * F_193 ( struct V_191 * V_145 , int V_385 ,
T_2 * V_293 , int V_21 , int * V_238 )
{
struct V_114 * V_114 = F_41 ( V_145 ) ;
struct V_244 * V_24 = (struct V_244 * ) V_293 ;
struct V_258 * V_259 = (struct V_258 * ) ( V_24 + 1 ) ;
struct V_255 * V_257 ;
int V_260 ;
switch ( V_145 -> V_386 ) {
case V_40 :
if ( V_385 != V_387 ) {
* V_238 = - V_388 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_385 != V_389 ) {
* V_238 = - V_388 ;
return NULL ;
}
break;
#endif
default:
* V_238 = - V_7 ;
return NULL ;
}
* V_238 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_110 ( V_24 ) )
return NULL ;
V_260 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_259 ) ) ;
if ( F_114 ( V_260 , V_259 , V_24 -> V_89 . V_39 ) )
return NULL ;
if ( V_24 -> V_238 > V_240 )
return NULL ;
V_257 = F_120 ( V_114 , V_201 ) ;
if ( V_257 == NULL ) {
* V_238 = - V_390 ;
return NULL ;
}
F_117 ( V_257 , V_24 ) ;
V_257 -> type = V_242 ;
F_113 ( V_257 , V_259 , V_260 ) ;
* V_238 = V_24 -> V_238 ;
return V_257 ;
}
static inline T_5 F_194 ( struct V_255 * V_257 )
{
return F_87 ( sizeof( struct V_311 ) )
+ F_88 ( sizeof( struct V_258 ) * V_257 -> V_262 )
+ F_88 ( F_27 ( V_257 -> V_179 ) )
+ F_88 ( sizeof( struct V_159 ) )
+ F_131 () ;
}
static int F_195 ( struct V_141 * V_142 , struct V_255 * V_257 ,
int V_238 , const struct V_146 * V_147 )
{
struct V_311 * V_391 ;
int V_312 = V_147 -> V_293 . V_312 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , 0 , V_392 , sizeof( * V_391 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_391 = F_42 ( V_144 ) ;
F_118 ( V_257 , & V_391 -> V_256 , V_238 ) ;
V_38 = F_128 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_130 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_257 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_257 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
V_391 -> V_312 = ! ! V_312 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_196 ( struct V_255 * V_257 , int V_238 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_197 ( V_257 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_194 ( V_257 ) , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_195 ( V_142 , V_257 , V_238 , V_147 ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_370 , V_201 ) ;
}
static int F_198 ( struct V_255 * V_257 , int V_238 , const struct V_146 * V_147 )
{
int V_21 = F_88 ( sizeof( struct V_258 ) * V_257 -> V_262 ) ;
struct V_114 * V_114 = F_197 ( V_257 ) ;
struct V_244 * V_24 ;
struct V_289 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_376 , V_38 ;
V_376 = sizeof( * V_24 ) ;
if ( V_147 -> V_157 == V_291 ) {
V_21 += F_88 ( V_376 ) ;
V_376 = sizeof( * V_33 ) ;
}
V_21 += F_131 () ;
V_21 += F_88 ( sizeof( struct V_159 ) ) ;
V_21 += F_87 ( V_376 ) ;
V_142 = F_83 ( V_21 , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_376 , 0 ) ;
V_38 = - V_170 ;
if ( V_144 == NULL )
goto V_378;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_157 == V_291 ) {
struct V_1 * V_168 ;
V_33 = F_42 ( V_144 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_238 = V_238 ;
if ( V_147 -> V_293 . V_294 )
V_33 -> V_253 = V_257 -> V_253 ;
else
memcpy ( & V_33 -> V_89 , & V_257 -> V_281 , sizeof( V_33 -> V_89 ) ) ;
V_168 = F_63 ( V_142 , V_393 , sizeof( * V_24 ) ) ;
V_38 = - V_170 ;
if ( V_168 == NULL )
goto V_378;
V_24 = F_2 ( V_168 ) ;
}
F_118 ( V_257 , V_24 , V_238 ) ;
V_38 = F_128 ( V_257 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_257 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_257 -> V_131 ) ;
if ( V_38 )
goto V_378;
F_74 ( V_142 , V_144 ) ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_394 , V_201 ) ;
V_378:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_199 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( F_131 () , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_71 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_395 , 0 , 0 ) ;
V_38 = - V_170 ;
if ( V_144 == NULL )
goto V_378;
V_38 = F_132 ( V_147 -> V_293 . type , V_142 ) ;
if ( V_38 )
goto V_378;
F_74 ( V_142 , V_144 ) ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_394 , V_201 ) ;
V_378:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_200 ( struct V_255 * V_257 , int V_238 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_284 :
case V_396 :
case V_291 :
return F_198 ( V_257 , V_238 , V_147 ) ;
case V_395 :
return F_199 ( V_147 ) ;
case V_392 :
return F_196 ( V_257 , V_238 , V_147 ) ;
default:
F_188 ( V_381 L_4 ,
V_147 -> V_157 ) ;
}
return 0 ;
}
static inline T_5 F_201 ( void )
{
return F_87 ( sizeof( struct V_397 ) ) ;
}
static int F_202 ( struct V_141 * V_142 , T_2 V_34 ,
struct V_348 * V_89 , T_1 * V_398 )
{
struct V_397 * V_399 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_400 , sizeof( * V_399 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_399 = F_42 ( V_144 ) ;
V_399 -> V_34 = V_34 ;
memcpy ( & V_399 -> V_89 , V_89 , sizeof( V_399 -> V_89 ) ) ;
if ( V_398 ) {
int V_38 = F_67 ( V_142 , V_53 , sizeof( * V_398 ) , V_398 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
}
return F_74 ( V_142 , V_144 ) ;
}
static int F_203 ( struct V_114 * V_114 , T_2 V_34 ,
struct V_348 * V_89 , T_1 * V_398 )
{
struct V_141 * V_142 ;
V_142 = F_83 ( F_201 () , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_202 ( V_142 , V_34 , V_89 , V_398 ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_401 , V_201 ) ;
}
static inline T_5 F_204 ( void )
{
return F_87 ( sizeof( struct V_402 ) ) ;
}
static int F_205 ( struct V_141 * V_142 , struct V_87 * V_88 ,
T_1 * V_340 , T_8 V_403 )
{
struct V_402 * V_329 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_404 , sizeof( * V_329 ) , 0 ) ;
if ( V_144 == NULL )
return - V_170 ;
V_329 = F_42 ( V_144 ) ;
memcpy ( & V_329 -> V_33 . V_163 , & V_88 -> V_33 . V_163 , sizeof( V_329 -> V_33 . V_163 ) ) ;
V_329 -> V_33 . V_46 = V_88 -> V_33 . V_46 ;
V_329 -> V_33 . V_39 = V_88 -> V_58 . V_39 ;
V_329 -> V_33 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_329 -> V_340 , V_340 , sizeof( V_329 -> V_340 ) ) ;
memcpy ( & V_329 -> V_338 , & V_88 -> V_58 . V_92 , sizeof( V_329 -> V_338 ) ) ;
V_329 -> V_403 = V_403 ;
V_329 -> V_405 = V_88 -> V_128 -> V_406 ;
V_329 -> V_91 = V_88 -> V_58 . V_91 ;
return F_74 ( V_142 , V_144 ) ;
}
static int F_206 ( struct V_87 * V_88 , T_1 * V_407 ,
T_8 V_408 )
{
struct V_114 * V_114 = F_182 ( V_88 ) ;
struct V_141 * V_142 ;
if ( V_88 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_88 -> V_128 )
return - V_7 ;
V_142 = F_83 ( F_204 () , V_201 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_205 ( V_142 , V_88 , V_407 , V_408 ) < 0 )
F_92 () ;
return F_171 ( V_114 -> V_134 . V_222 , V_142 , 0 , V_409 , V_201 ) ;
}
static bool F_207 ( const struct V_146 * V_147 )
{
return ( bool ) F_208 ( V_147 -> V_114 ) ;
}
static int T_9 F_209 ( struct V_114 * V_114 )
{
struct V_191 * V_222 ;
struct V_410 V_411 = {
. V_412 = V_413 ,
. V_414 = F_175 ,
} ;
V_222 = F_210 ( V_114 , V_415 , & V_411 ) ;
if ( V_222 == NULL )
return - V_68 ;
V_114 -> V_134 . V_416 = V_222 ;
F_211 ( V_114 -> V_134 . V_222 , V_222 ) ;
return 0 ;
}
static void T_10 F_212 ( struct V_417 * V_418 )
{
struct V_114 * V_114 ;
F_213 (net, net_exit_list, exit_list)
F_214 ( V_114 -> V_134 . V_222 , NULL ) ;
F_215 () ;
F_213 (net, net_exit_list, exit_list)
F_216 ( V_114 -> V_134 . V_416 ) ;
}
static int T_11 F_217 ( void )
{
int V_419 ;
F_188 ( V_420 L_5 ) ;
V_419 = F_218 ( & V_421 ) ;
if ( V_419 < 0 )
return V_419 ;
V_419 = F_219 ( & V_422 ) ;
if ( V_419 < 0 )
F_220 ( & V_421 ) ;
return V_419 ;
}
static void T_12 F_221 ( void )
{
F_222 ( & V_422 ) ;
F_220 ( & V_421 ) ;
}
