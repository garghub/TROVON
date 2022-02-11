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
V_2 [ V_45 ] )
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
V_24 -> V_46 != V_47 )
goto V_44;
break;
case V_48 :
if ( ! V_2 [ V_10 ] ||
V_2 [ V_15 ] ||
V_2 [ V_8 ] ||
V_2 [ V_13 ] ||
V_2 [ V_9 ] ||
V_2 [ V_45 ] ||
( F_15 ( V_24 -> V_33 . V_49 ) >= 0x10000 ) )
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
switch ( V_24 -> V_46 ) {
case V_54 :
case V_47 :
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
V_88 -> V_58 . V_46 = V_24 -> V_46 ;
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
V_38 = F_13 ( V_24 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_88 = F_32 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( ! V_88 )
return V_38 ;
F_43 ( V_88 ) ;
if ( V_144 -> V_148 == V_149 )
V_38 = F_44 ( V_88 ) ;
else
V_38 = F_45 ( V_88 ) ;
F_46 ( V_88 , V_38 ? 0 : 1 , true ) ;
if ( V_38 < 0 ) {
V_88 -> V_132 . V_139 = V_140 ;
F_47 ( V_88 ) ;
goto V_44;
}
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_153 = V_144 -> V_148 ;
F_48 ( V_88 , & V_147 ) ;
V_44:
F_39 ( V_88 ) ;
return V_38 ;
}
static struct V_87 * F_49 ( struct V_114 * V_114 ,
struct V_154 * V_24 ,
struct V_1 * * V_2 ,
int * V_115 )
{
struct V_87 * V_88 = NULL ;
struct V_155 V_156 ;
int V_38 ;
T_3 V_131 = F_35 ( V_2 , & V_156 ) ;
if ( F_50 ( V_24 -> V_34 , V_157 ) ) {
V_38 = - V_158 ;
V_88 = F_51 ( V_114 , V_131 , & V_24 -> V_159 , V_24 -> V_49 , V_24 -> V_34 , V_24 -> V_39 ) ;
} else {
T_1 * V_92 = NULL ;
F_9 ( V_2 , V_160 , & V_92 ) ;
if ( ! V_92 ) {
V_38 = - V_7 ;
goto V_44;
}
V_38 = - V_158 ;
V_88 = F_52 ( V_114 , V_131 ,
& V_24 -> V_159 , V_92 ,
V_24 -> V_34 , V_24 -> V_39 ) ;
}
V_44:
if ( ! V_88 && V_115 )
* V_115 = V_38 ;
return V_88 ;
}
static int F_53 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_38 = - V_158 ;
struct V_146 V_147 ;
struct V_154 * V_24 = F_42 ( V_144 ) ;
V_88 = F_49 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( V_88 == NULL )
return V_38 ;
if ( ( V_38 = F_54 ( V_88 ) ) != 0 )
goto V_44;
if ( F_55 ( V_88 ) ) {
V_38 = - V_161 ;
goto V_44;
}
V_38 = F_56 ( V_88 ) ;
if ( V_38 < 0 )
goto V_44;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_153 = V_144 -> V_148 ;
F_48 ( V_88 , & V_147 ) ;
V_44:
F_57 ( V_88 , V_38 ? 0 : 1 , true ) ;
F_39 ( V_88 ) ;
return V_38 ;
}
static void F_58 ( struct V_87 * V_88 , struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_33 , & V_88 -> V_33 , sizeof( V_24 -> V_33 ) ) ;
memcpy ( & V_24 -> V_89 , & V_88 -> V_89 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_90 , & V_88 -> V_90 , sizeof( V_24 -> V_90 ) ) ;
memcpy ( & V_24 -> V_107 , & V_88 -> V_107 , sizeof( V_24 -> V_107 ) ) ;
memcpy ( & V_24 -> V_162 , & V_88 -> V_162 , sizeof( V_24 -> V_162 ) ) ;
memcpy ( & V_24 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_24 -> V_92 ) ) ;
V_24 -> V_46 = V_88 -> V_58 . V_46 ;
V_24 -> V_37 = V_88 -> V_58 . V_37 ;
V_24 -> V_91 = V_88 -> V_58 . V_91 ;
V_24 -> V_39 = V_88 -> V_58 . V_39 ;
V_24 -> V_28 = V_88 -> V_58 . V_28 ;
V_24 -> V_133 = V_88 -> V_132 . V_133 ;
}
static int F_59 ( struct V_85 * V_163 , struct V_141 * V_142 )
{
struct V_19 * V_20 ;
struct V_1 * V_164 ;
int V_165 = sizeof( * V_20 ) + V_163 -> V_22 ;
V_164 = F_60 ( V_142 , V_18 , V_165 ) ;
if ( V_164 == NULL )
return - V_166 ;
V_20 = F_2 ( V_164 ) ;
V_20 -> V_167 = V_18 ;
V_20 -> V_21 = V_165 ;
V_20 -> V_168 = V_163 -> V_168 ;
V_20 -> V_169 = V_163 -> V_169 ;
V_20 -> V_22 = V_163 -> V_22 ;
memcpy ( V_20 + 1 , V_163 -> V_170 , V_163 -> V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_72 , struct V_141 * V_142 )
{
struct V_5 * V_62 ;
struct V_1 * V_171 ;
V_171 = F_60 ( V_142 , V_8 ,
sizeof( * V_62 ) + ( V_72 -> V_66 + 7 ) / 8 ) ;
if ( ! V_171 )
return - V_166 ;
V_62 = F_2 ( V_171 ) ;
strncpy ( V_62 -> V_11 , V_72 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_74 , V_72 -> V_74 , ( V_72 -> V_66 + 7 ) / 8 ) ;
V_62 -> V_66 = V_72 -> V_66 ;
return 0 ;
}
static int F_62 ( struct V_87 * V_88 ,
struct V_23 * V_24 ,
struct V_141 * V_142 )
{
int V_172 = 0 ;
F_58 ( V_88 , V_24 ) ;
if ( V_88 -> V_58 . V_118 ) {
V_172 = F_63 ( V_142 , V_117 ,
V_88 -> V_58 . V_118 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_130 ) {
V_172 = F_64 ( V_142 , V_53 , sizeof( * V_88 -> V_130 ) , V_88 -> V_130 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_173 ) {
V_172 = F_65 ( V_142 , V_174 , V_88 -> V_173 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_119 ) {
V_172 = F_64 ( V_142 , V_15 , F_8 ( V_88 -> V_119 ) , V_88 -> V_119 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_121 ) {
V_172 = F_61 ( V_88 -> V_121 , V_142 ) ;
if ( ! V_172 )
V_172 = F_64 ( V_142 , V_13 ,
F_6 ( V_88 -> V_121 ) , V_88 -> V_121 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_123 ) {
V_172 = F_64 ( V_142 , V_9 , F_4 ( V_88 -> V_123 ) , V_88 -> V_123 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_125 ) {
V_172 = F_64 ( V_142 , V_10 , sizeof( * ( V_88 -> V_125 ) ) , V_88 -> V_125 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_128 ) {
V_172 = F_64 ( V_142 , V_52 , sizeof( * V_88 -> V_128 ) , V_88 -> V_128 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_129 ) {
V_172 = F_63 ( V_142 , V_45 , V_88 -> V_129 ) ;
if ( V_172 )
goto V_44;
}
V_172 = F_66 ( V_142 , & V_88 -> V_131 ) ;
if ( V_172 )
goto V_44;
if ( V_88 -> V_78 ) {
V_172 = F_64 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
if ( V_172 )
goto V_44;
}
if ( V_88 -> V_175 )
V_172 = F_59 ( V_88 -> V_175 , V_142 ) ;
V_44:
return V_172 ;
}
static int F_67 ( struct V_87 * V_88 , int V_176 , void * V_177 )
{
struct V_178 * V_179 = V_177 ;
struct V_141 * V_180 = V_179 -> V_180 ;
struct V_141 * V_142 = V_179 -> V_181 ;
struct V_23 * V_24 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , F_69 ( V_180 ) . V_151 , V_179 -> V_150 ,
V_149 , sizeof( * V_24 ) , V_179 -> V_182 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_24 = F_42 ( V_144 ) ;
V_38 = F_62 ( V_88 , V_24 , V_142 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
F_71 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_72 ( struct V_183 * V_184 )
{
struct V_185 * V_186 = (struct V_185 * ) & V_184 -> args [ 1 ] ;
struct V_187 * V_145 = V_184 -> V_142 -> V_145 ;
struct V_114 * V_114 = F_41 ( V_145 ) ;
F_73 ( V_186 , V_114 ) ;
return 0 ;
}
static int F_74 ( struct V_141 * V_142 , struct V_183 * V_184 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_185 * V_186 = (struct V_185 * ) & V_184 -> args [ 1 ] ;
struct V_178 V_188 ;
F_75 ( sizeof( struct V_185 ) >
sizeof( V_184 -> args ) - sizeof( V_184 -> args [ 0 ] ) ) ;
V_188 . V_180 = V_184 -> V_142 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_184 -> V_144 -> V_150 ;
V_188 . V_182 = V_189 ;
if ( ! V_184 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_190 + 1 ] ;
struct V_191 * V_192 = NULL ;
T_2 V_34 = 0 ;
int V_38 ;
V_184 -> args [ 0 ] = 1 ;
V_38 = F_76 ( V_184 -> V_144 , 0 , V_2 , V_190 ,
V_193 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_194 ] ) {
V_192 = F_18 ( sizeof( * V_192 ) , V_67 ) ;
if ( V_192 == NULL )
return - V_68 ;
memcpy ( V_192 , F_2 ( V_2 [ V_194 ] ) ,
sizeof( * V_192 ) ) ;
}
if ( V_2 [ V_195 ] )
V_34 = F_77 ( V_2 [ V_195 ] ) ;
F_78 ( V_186 , V_34 , V_192 ) ;
}
( void ) V_185 ( V_114 , V_186 , F_67 , & V_188 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_79 ( struct V_141 * V_180 ,
struct V_87 * V_88 , T_3 V_133 )
{
struct V_178 V_188 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_80 ( V_196 , V_197 ) ;
if ( ! V_142 )
return F_81 ( - V_68 ) ;
V_188 . V_180 = V_180 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_133 ;
V_188 . V_182 = 0 ;
V_38 = F_67 ( V_88 , 0 , & V_188 ) ;
if ( V_38 ) {
F_82 ( V_142 ) ;
return F_81 ( V_38 ) ;
}
return V_142 ;
}
static inline int F_83 ( struct V_114 * V_114 , struct V_141 * V_142 ,
T_3 V_198 , unsigned int V_199 )
{
struct V_187 * V_200 = F_84 ( V_114 -> V_134 . V_200 ) ;
if ( V_200 )
return F_85 ( V_200 , V_142 , V_198 , V_199 , V_197 ) ;
else
return - 1 ;
}
static inline T_4 F_86 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_201 ) )
+ F_88 ( sizeof( struct V_202 ) ) ;
}
static int F_89 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_203 V_204 ;
struct V_201 V_205 ;
struct V_202 V_206 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_207 ;
V_144 = F_68 ( V_142 , V_151 , V_133 , V_208 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_207 = F_42 ( V_144 ) ;
* V_207 = V_28 ;
F_90 ( V_114 , & V_204 ) ;
V_205 . V_209 = V_204 . V_209 ;
V_205 . V_210 = V_204 . V_210 ;
V_205 . V_211 = V_204 . V_211 ;
V_205 . V_212 = V_204 . V_212 ;
V_205 . V_213 = V_204 . V_213 ;
V_205 . V_214 = V_204 . V_214 ;
V_206 . V_215 = V_204 . V_215 ;
V_206 . V_216 = V_204 . V_216 ;
V_38 = F_64 ( V_142 , V_217 , sizeof( V_205 ) , & V_205 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_142 , V_218 , sizeof( V_206 ) , & V_206 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_71 ( V_142 , V_144 ) ;
}
static int F_91 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_219 ;
T_3 * V_28 = F_42 ( V_144 ) ;
T_3 V_220 = F_69 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_219 = F_80 ( F_86 () , V_197 ) ;
if ( V_219 == NULL )
return - V_68 ;
if ( F_89 ( V_219 , V_114 , V_220 , V_133 , * V_28 ) < 0 )
F_92 () ;
return F_93 ( V_114 -> V_134 . V_200 , V_219 , V_220 ) ;
}
static inline T_4 F_94 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_221 ) )
+ F_88 ( 4 ) ;
}
static int F_95 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_222 V_204 ;
struct V_221 V_223 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_207 ;
V_144 = F_68 ( V_142 , V_151 , V_133 , V_224 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_207 = F_42 ( V_144 ) ;
* V_207 = V_28 ;
F_96 ( V_114 , & V_204 ) ;
V_223 . V_225 = V_204 . V_225 ;
V_223 . V_226 = V_204 . V_226 ;
V_38 = F_63 ( V_142 , V_227 , V_204 . V_228 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_142 , V_229 , sizeof( V_223 ) , & V_223 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_71 ( V_142 , V_144 ) ;
}
static int F_97 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_141 * V_219 ;
T_3 * V_28 = F_42 ( V_144 ) ;
T_3 V_220 = F_69 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_219 = F_80 ( F_94 () , V_197 ) ;
if ( V_219 == NULL )
return - V_68 ;
if ( F_95 ( V_219 , V_114 , V_220 , V_133 , * V_28 ) < 0 )
F_92 () ;
return F_93 ( V_114 -> V_134 . V_200 , V_219 , V_220 ) ;
}
static int F_98 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_154 * V_24 = F_42 ( V_144 ) ;
struct V_87 * V_88 ;
struct V_141 * V_230 ;
int V_38 = - V_158 ;
V_88 = F_49 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( V_88 == NULL )
goto V_231;
V_230 = F_79 ( V_142 , V_88 , V_144 -> V_150 ) ;
if ( F_99 ( V_230 ) ) {
V_38 = F_100 ( V_230 ) ;
} else {
V_38 = F_93 ( V_114 -> V_134 . V_200 , V_230 , F_69 ( V_142 ) . V_151 ) ;
}
F_39 ( V_88 ) ;
V_231:
return V_38 ;
}
static int F_101 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_232 * V_24 ;
struct V_141 * V_230 ;
T_1 * V_159 ;
int V_39 ;
int V_38 ;
T_3 V_131 ;
struct V_155 V_156 ;
V_24 = F_42 ( V_144 ) ;
V_38 = F_102 ( V_24 -> V_188 . V_33 . V_34 , V_24 -> V_233 , V_24 -> V_234 ) ;
if ( V_38 )
goto V_231;
V_39 = V_24 -> V_188 . V_39 ;
V_159 = & V_24 -> V_188 . V_33 . V_159 ;
V_88 = NULL ;
V_131 = F_35 ( V_2 , & V_156 ) ;
if ( V_24 -> V_188 . V_133 ) {
V_88 = F_103 ( V_114 , V_131 , V_24 -> V_188 . V_133 ) ;
if ( V_88 && ! F_104 ( & V_88 -> V_33 . V_159 , V_159 , V_39 ) ) {
F_39 ( V_88 ) ;
V_88 = NULL ;
}
}
if ( ! V_88 )
V_88 = F_105 ( V_114 , & V_156 , V_24 -> V_188 . V_46 , V_24 -> V_188 . V_91 ,
V_24 -> V_188 . V_33 . V_34 , V_159 ,
& V_24 -> V_188 . V_92 , 1 ,
V_39 ) ;
V_38 = - V_235 ;
if ( V_88 == NULL )
goto V_231;
V_38 = F_106 ( V_88 , V_24 -> V_233 , V_24 -> V_234 ) ;
if ( V_38 )
goto V_44;
V_230 = F_79 ( V_142 , V_88 , V_144 -> V_150 ) ;
if ( F_99 ( V_230 ) ) {
V_38 = F_100 ( V_230 ) ;
goto V_44;
}
V_38 = F_93 ( V_114 -> V_134 . V_200 , V_230 , F_69 ( V_142 ) . V_151 ) ;
V_44:
F_39 ( V_88 ) ;
V_231:
return V_38 ;
}
static int F_107 ( T_2 V_236 )
{
switch ( V_236 ) {
case V_237 :
case V_238 :
case V_239 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_108 ( T_2 type )
{
switch ( type ) {
case V_240 :
#ifdef F_109
case V_241 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_110 ( struct V_242 * V_24 )
{
int V_172 ;
switch ( V_24 -> V_243 ) {
case V_244 :
case V_245 :
case V_246 :
case V_247 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_248 ) {
case V_249 :
case V_250 :
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
V_172 = F_107 ( V_24 -> V_236 ) ;
if ( V_172 )
return V_172 ;
if ( V_24 -> V_251 && ( ( V_24 -> V_251 & V_252 ) != V_24 -> V_236 ) )
return - V_7 ;
return 0 ;
}
static int F_111 ( struct V_253 * V_254 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_112 ( & V_254 -> V_175 , V_20 , V_67 ) ;
}
static void F_113 ( struct V_253 * V_255 , struct V_256 * V_257 ,
int V_258 )
{
int V_259 ;
V_255 -> V_260 = V_258 ;
for ( V_259 = 0 ; V_259 < V_258 ; V_259 ++ , V_257 ++ ) {
struct V_261 * V_262 = & V_255 -> V_263 [ V_259 ] ;
memcpy ( & V_262 -> V_33 , & V_257 -> V_33 , sizeof( struct V_264 ) ) ;
memcpy ( & V_262 -> V_92 , & V_257 -> V_92 ,
sizeof( T_1 ) ) ;
V_262 -> V_91 = V_257 -> V_91 ;
V_262 -> V_46 = V_257 -> V_46 ;
V_262 -> V_243 = V_257 -> V_243 ;
V_262 -> V_265 = V_257 -> V_265 ;
V_262 -> V_266 = V_257 -> V_266 ;
V_262 -> V_267 = V_257 -> V_267 ;
V_262 -> V_268 = V_257 -> V_268 ;
V_262 -> V_269 = ! ~ ( V_262 -> V_266 & V_262 -> V_267 & V_262 -> V_268 ) ;
V_262 -> V_270 = V_257 -> V_39 ;
}
}
static int F_114 ( int V_258 , struct V_256 * V_257 , T_5 V_39 )
{
int V_259 ;
if ( V_258 > V_271 )
return - V_7 ;
for ( V_259 = 0 ; V_259 < V_258 ; V_259 ++ ) {
if ( ! V_257 [ V_259 ] . V_39 )
V_257 [ V_259 ] . V_39 = V_39 ;
switch ( V_257 [ V_259 ] . V_39 ) {
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
static int F_115 ( struct V_253 * V_254 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_272 ] ;
if ( ! V_4 ) {
V_254 -> V_260 = 0 ;
} else {
struct V_256 * V_273 = F_2 ( V_4 ) ;
int V_258 = F_3 ( V_4 ) / sizeof( * V_273 ) ;
int V_38 ;
V_38 = F_114 ( V_258 , V_273 , V_254 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_113 ( V_254 , V_273 , V_258 ) ;
}
return 0 ;
}
static int F_116 ( T_2 * V_274 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_275 ] ;
struct V_276 * V_277 ;
T_2 type = V_240 ;
int V_38 ;
if ( V_4 ) {
V_277 = F_2 ( V_4 ) ;
type = V_277 -> type ;
}
V_38 = F_108 ( type ) ;
if ( V_38 )
return V_38 ;
* V_274 = type ;
return 0 ;
}
static void F_117 ( struct V_253 * V_255 , struct V_242 * V_24 )
{
V_255 -> V_278 = V_24 -> V_278 ;
V_255 -> V_251 = V_24 -> V_251 ;
memcpy ( & V_255 -> V_279 , & V_24 -> V_89 , sizeof( V_255 -> V_279 ) ) ;
memcpy ( & V_255 -> V_90 , & V_24 -> V_90 , sizeof( V_255 -> V_90 ) ) ;
V_255 -> V_248 = V_24 -> V_248 ;
V_255 -> V_28 = V_24 -> V_28 ;
V_255 -> V_39 = V_24 -> V_89 . V_39 ;
}
static void F_118 ( struct V_253 * V_255 , struct V_242 * V_24 , int V_236 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_89 , & V_255 -> V_279 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_90 , & V_255 -> V_90 , sizeof( V_24 -> V_90 ) ) ;
memcpy ( & V_24 -> V_107 , & V_255 -> V_107 , sizeof( V_24 -> V_107 ) ) ;
V_24 -> V_278 = V_255 -> V_278 ;
V_24 -> V_251 = V_255 -> V_251 ;
V_24 -> V_89 . V_39 = V_255 -> V_39 ;
V_24 -> V_236 = V_236 ;
V_24 -> V_248 = V_255 -> V_248 ;
V_24 -> V_28 = V_255 -> V_28 ;
V_24 -> V_243 = V_244 ;
}
static struct V_253 * F_119 ( struct V_114 * V_114 , struct V_242 * V_24 , struct V_1 * * V_2 , int * V_115 )
{
struct V_253 * V_255 = F_120 ( V_114 , V_67 ) ;
int V_38 ;
if ( ! V_255 ) {
* V_115 = - V_68 ;
return NULL ;
}
F_117 ( V_255 , V_24 ) ;
V_38 = F_116 ( & V_255 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_115 ( V_255 , V_2 ) ) )
V_38 = F_111 ( V_255 , V_2 ) ;
if ( V_38 )
goto error;
F_35 ( V_2 , & V_255 -> V_131 ) ;
return V_255 ;
error:
* V_115 = V_38 ;
V_255 -> V_186 . V_280 = 1 ;
F_121 ( V_255 ) ;
return NULL ;
}
static int F_122 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_242 * V_24 = F_42 ( V_144 ) ;
struct V_253 * V_255 ;
struct V_146 V_147 ;
int V_38 ;
int V_281 ;
V_38 = F_110 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_255 = F_119 ( V_114 , V_24 , V_2 , & V_38 ) ;
if ( ! V_255 )
return V_38 ;
V_281 = V_144 -> V_148 == V_282 ;
V_38 = F_123 ( V_24 -> V_236 , V_255 , V_281 ) ;
F_124 ( V_255 , V_38 ? 0 : 1 , true ) ;
if ( V_38 ) {
F_125 ( V_255 -> V_175 ) ;
F_26 ( V_255 ) ;
return V_38 ;
}
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_126 ( V_255 , V_24 -> V_236 , & V_147 ) ;
F_127 ( V_255 ) ;
return 0 ;
}
static int F_128 ( struct V_253 * V_255 , struct V_141 * V_142 )
{
struct V_256 V_283 [ V_271 ] ;
int V_259 ;
if ( V_255 -> V_260 == 0 )
return 0 ;
for ( V_259 = 0 ; V_259 < V_255 -> V_260 ; V_259 ++ ) {
struct V_256 * V_80 = & V_283 [ V_259 ] ;
struct V_261 * V_284 = & V_255 -> V_263 [ V_259 ] ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( & V_80 -> V_33 , & V_284 -> V_33 , sizeof( V_80 -> V_33 ) ) ;
V_80 -> V_39 = V_284 -> V_270 ;
memcpy ( & V_80 -> V_92 , & V_284 -> V_92 , sizeof( V_80 -> V_92 ) ) ;
V_80 -> V_91 = V_284 -> V_91 ;
V_80 -> V_46 = V_284 -> V_46 ;
V_80 -> V_243 = V_284 -> V_243 ;
V_80 -> V_265 = V_284 -> V_265 ;
V_80 -> V_266 = V_284 -> V_266 ;
V_80 -> V_267 = V_284 -> V_267 ;
V_80 -> V_268 = V_284 -> V_268 ;
}
return F_64 ( V_142 , V_272 ,
sizeof( struct V_256 ) * V_255 -> V_260 , V_283 ) ;
}
static inline int F_129 ( struct V_87 * V_88 , struct V_141 * V_142 )
{
if ( V_88 -> V_175 ) {
return F_59 ( V_88 -> V_175 , V_142 ) ;
}
return 0 ;
}
static inline int F_130 ( struct V_253 * V_255 , struct V_141 * V_142 )
{
if ( V_255 -> V_175 )
return F_59 ( V_255 -> V_175 , V_142 ) ;
return 0 ;
}
static inline T_4 F_131 ( void )
{
#ifdef F_109
return F_88 ( sizeof( struct V_276 ) ) ;
#else
return 0 ;
#endif
}
static int F_132 ( T_2 type , struct V_141 * V_142 )
{
struct V_276 V_277 = {
. type = type ,
} ;
return F_64 ( V_142 , V_275 , sizeof( V_277 ) , & V_277 ) ;
}
static inline int F_132 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_133 ( struct V_253 * V_255 , int V_236 , int V_176 , void * V_177 )
{
struct V_178 * V_179 = V_177 ;
struct V_242 * V_24 ;
struct V_141 * V_180 = V_179 -> V_180 ;
struct V_141 * V_142 = V_179 -> V_181 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , F_69 ( V_180 ) . V_151 , V_179 -> V_150 ,
V_282 , sizeof( * V_24 ) , V_179 -> V_182 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_24 = F_42 ( V_144 ) ;
F_118 ( V_255 , V_24 , V_236 ) ;
V_38 = F_128 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_130 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_255 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , & V_255 -> V_131 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
F_71 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_134 ( struct V_183 * V_184 )
{
struct V_285 * V_186 = (struct V_285 * ) & V_184 -> args [ 1 ] ;
struct V_114 * V_114 = F_41 ( V_184 -> V_142 -> V_145 ) ;
F_135 ( V_186 , V_114 ) ;
return 0 ;
}
static int F_136 ( struct V_141 * V_142 , struct V_183 * V_184 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_285 * V_186 = (struct V_285 * ) & V_184 -> args [ 1 ] ;
struct V_178 V_188 ;
F_75 ( sizeof( struct V_285 ) >
sizeof( V_184 -> args ) - sizeof( V_184 -> args [ 0 ] ) ) ;
V_188 . V_180 = V_184 -> V_142 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_184 -> V_144 -> V_150 ;
V_188 . V_182 = V_189 ;
if ( ! V_184 -> args [ 0 ] ) {
V_184 -> args [ 0 ] = 1 ;
F_137 ( V_186 , V_286 ) ;
}
( void ) V_285 ( V_114 , V_186 , F_133 , & V_188 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_138 ( struct V_141 * V_180 ,
struct V_253 * V_255 ,
int V_236 , T_3 V_133 )
{
struct V_178 V_188 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_80 ( V_196 , V_67 ) ;
if ( ! V_142 )
return F_81 ( - V_68 ) ;
V_188 . V_180 = V_180 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_133 ;
V_188 . V_182 = 0 ;
V_38 = F_133 ( V_255 , V_236 , 0 , & V_188 ) ;
if ( V_38 ) {
F_82 ( V_142 ) ;
return F_81 ( V_38 ) ;
}
return V_142 ;
}
static int F_139 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_253 * V_255 ;
struct V_287 * V_24 ;
T_2 type = V_240 ;
int V_38 ;
struct V_146 V_147 ;
int V_288 ;
struct V_155 V_156 ;
T_3 V_131 = F_35 ( V_2 , & V_156 ) ;
V_24 = F_42 ( V_144 ) ;
V_288 = V_144 -> V_148 == V_289 ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_107 ( V_24 -> V_236 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_251 )
V_255 = F_140 ( V_114 , V_131 , type , V_24 -> V_236 , V_24 -> V_251 , V_288 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_290 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_290 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_112 ( & V_290 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_255 = F_141 ( V_114 , V_131 , type , V_24 -> V_236 , & V_24 -> V_89 ,
V_290 , V_288 , & V_38 ) ;
F_125 ( V_290 ) ;
}
if ( V_255 == NULL )
return - V_235 ;
if ( ! V_288 ) {
struct V_141 * V_230 ;
V_230 = F_138 ( V_142 , V_255 , V_24 -> V_236 , V_144 -> V_150 ) ;
if ( F_99 ( V_230 ) ) {
V_38 = F_100 ( V_230 ) ;
} else {
V_38 = F_93 ( V_114 -> V_134 . V_200 , V_230 ,
F_69 ( V_142 ) . V_151 ) ;
}
} else {
F_142 ( V_255 , V_38 ? 0 : 1 , true ) ;
if ( V_38 != 0 )
goto V_44;
V_147 . V_291 . V_292 = V_24 -> V_251 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_126 ( V_255 , V_24 -> V_236 , & V_147 ) ;
}
V_44:
F_127 ( V_255 ) ;
if ( V_288 && V_38 == 0 )
F_143 ( V_114 ) ;
return V_38 ;
}
static int F_144 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_293 * V_24 = F_42 ( V_144 ) ;
int V_38 ;
V_38 = F_145 ( V_114 , V_24 -> V_34 , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_291 . V_34 = V_24 -> V_34 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_114 = V_114 ;
F_48 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_4 F_146 ( struct V_87 * V_88 )
{
T_4 V_294 = V_88 -> V_78 ?
F_12 ( V_88 -> V_78 ) :
sizeof( struct V_102 ) ;
return F_87 ( sizeof( struct V_295 ) )
+ F_88 ( V_294 )
+ F_88 ( sizeof( struct V_105 ) )
+ F_88 ( sizeof( struct V_155 ) )
+ F_88 ( 4 )
+ F_88 ( 4 ) ;
}
static int F_147 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_295 * V_33 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_296 , sizeof( * V_33 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_297 . V_159 , & V_88 -> V_33 . V_159 , sizeof( V_88 -> V_33 . V_159 ) ) ;
V_33 -> V_297 . V_49 = V_88 -> V_33 . V_49 ;
V_33 -> V_297 . V_39 = V_88 -> V_58 . V_39 ;
V_33 -> V_297 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_88 -> V_58 . V_92 ) ) ;
V_33 -> V_91 = V_88 -> V_58 . V_91 ;
V_33 -> V_28 = V_147 -> V_291 . V_298 ;
if ( V_88 -> V_78 ) {
V_38 = F_64 ( V_142 , V_25 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
} else {
V_38 = F_64 ( V_142 , V_95 , sizeof( V_88 -> V_103 ) ,
& V_88 -> V_103 ) ;
}
if ( V_38 )
goto V_299;
V_38 = F_64 ( V_142 , V_98 , sizeof( V_88 -> V_107 ) , & V_88 -> V_107 ) ;
if ( V_38 )
goto V_299;
if ( V_33 -> V_28 & V_300 ) {
V_38 = F_63 ( V_142 , V_101 , V_88 -> V_113 ) ;
if ( V_38 )
goto V_299;
}
if ( V_33 -> V_28 & V_301 ) {
V_38 = F_63 ( V_142 , V_100 ,
V_88 -> V_112 * 10 / V_137 ) ;
if ( V_38 )
goto V_299;
}
V_38 = F_66 ( V_142 , & V_88 -> V_131 ) ;
if ( V_38 )
goto V_299;
return F_71 ( V_142 , V_144 ) ;
V_299:
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_148 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_141 * V_219 ;
int V_38 ;
struct V_146 V_147 ;
T_3 V_131 ;
struct V_155 V_156 ;
struct V_295 * V_24 = F_42 ( V_144 ) ;
struct V_154 * V_33 = & V_24 -> V_297 ;
V_131 = F_35 ( V_2 , & V_156 ) ;
V_88 = F_51 ( V_114 , V_131 , & V_33 -> V_159 , V_33 -> V_49 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_88 == NULL )
return - V_158 ;
V_219 = F_80 ( F_146 ( V_88 ) , V_197 ) ;
if ( V_219 == NULL ) {
F_39 ( V_88 ) ;
return - V_68 ;
}
F_149 ( & V_88 -> V_302 ) ;
V_147 . V_291 . V_298 = V_24 -> V_28 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
if ( F_147 ( V_219 , V_88 , & V_147 ) < 0 )
F_92 () ;
V_38 = F_93 ( V_114 -> V_134 . V_200 , V_219 , F_69 ( V_142 ) . V_151 ) ;
F_150 ( & V_88 -> V_302 ) ;
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
T_3 V_131 = 0 ;
struct V_155 V_156 ;
struct V_295 * V_24 = F_42 ( V_144 ) ;
struct V_1 * V_79 = V_2 [ V_95 ] ;
struct V_1 * V_96 = V_2 [ V_25 ] ;
struct V_1 * V_97 = V_2 [ V_98 ] ;
if ( ! V_97 && ! V_79 && ! V_96 )
return V_38 ;
if ( ! ( V_144 -> V_182 & V_303 ) )
return V_38 ;
V_131 = F_35 ( V_2 , & V_156 ) ;
V_88 = F_51 ( V_114 , V_131 , & V_24 -> V_297 . V_159 , V_24 -> V_297 . V_49 , V_24 -> V_297 . V_34 , V_24 -> V_297 . V_39 ) ;
if ( V_88 == NULL )
return - V_158 ;
if ( V_88 -> V_132 . V_139 != V_304 )
goto V_44;
V_38 = F_23 ( V_88 -> V_78 , V_96 ) ;
if ( V_38 )
goto V_44;
F_149 ( & V_88 -> V_302 ) ;
F_30 ( V_88 , V_2 , 1 ) ;
F_150 ( & V_88 -> V_302 ) ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_291 . V_298 = V_305 ;
F_48 ( V_88 , & V_147 ) ;
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
T_2 type = V_240 ;
int V_38 ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_153 ( V_114 , type , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_291 . type = type ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_114 = V_114 ;
F_126 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_154 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_253 * V_255 ;
struct V_306 * V_80 = F_42 ( V_144 ) ;
struct V_242 * V_24 = & V_80 -> V_254 ;
T_2 type = V_240 ;
int V_38 = - V_235 ;
struct V_155 V_156 ;
T_3 V_131 = F_35 ( V_2 , & V_156 ) ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_107 ( V_24 -> V_236 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_251 )
V_255 = F_140 ( V_114 , V_131 , type , V_24 -> V_236 , V_24 -> V_251 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_85 * V_290 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_290 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_112 ( & V_290 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_255 = F_141 ( V_114 , V_131 , type , V_24 -> V_236 ,
& V_24 -> V_89 , V_290 , 0 , & V_38 ) ;
F_125 ( V_290 ) ;
}
if ( V_255 == NULL )
return - V_235 ;
if ( F_155 ( V_255 -> V_186 . V_280 ) )
goto V_44;
V_38 = 0 ;
if ( V_80 -> V_307 ) {
F_156 ( V_255 , V_24 -> V_236 ) ;
F_142 ( V_255 , 1 , true ) ;
} else {
F_157 ( 1 , L_1 ) ;
}
F_158 ( V_255 , V_24 -> V_236 , V_80 -> V_307 , V_144 -> V_152 ) ;
V_44:
F_127 ( V_255 ) ;
return V_38 ;
}
static int F_159 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_38 ;
struct V_308 * V_309 = F_42 ( V_144 ) ;
struct V_23 * V_24 = & V_309 -> V_139 ;
struct V_155 V_156 ;
T_3 V_131 = F_35 ( V_2 , & V_156 ) ;
V_88 = F_51 ( V_114 , V_131 , & V_24 -> V_33 . V_159 , V_24 -> V_33 . V_49 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_235 ;
if ( V_88 == NULL )
return V_38 ;
F_149 ( & V_88 -> V_302 ) ;
V_38 = - V_7 ;
if ( V_88 -> V_132 . V_139 != V_304 )
goto V_44;
F_160 ( V_88 , V_309 -> V_307 , V_144 -> V_152 ) ;
if ( V_309 -> V_307 ) {
F_161 ( V_88 ) ;
F_57 ( V_88 , 1 , true ) ;
}
V_38 = 0 ;
V_44:
F_150 ( & V_88 -> V_302 ) ;
F_39 ( V_88 ) ;
return V_38 ;
}
static int F_162 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_253 * V_255 ;
struct V_256 * V_257 ;
int V_259 ;
struct V_1 * V_4 = V_2 [ V_272 ] ;
struct V_155 V_131 ;
struct V_310 * V_311 = F_42 ( V_144 ) ;
struct V_87 * V_88 = F_33 ( V_114 ) ;
int V_38 = - V_68 ;
if ( ! V_88 )
goto V_312;
F_35 ( V_2 , & V_131 ) ;
V_38 = F_110 ( & V_311 -> V_313 ) ;
if ( V_38 )
goto V_314;
V_255 = F_119 ( V_114 , & V_311 -> V_313 , V_2 , & V_38 ) ;
if ( ! V_255 )
goto V_315;
memcpy ( & V_88 -> V_33 , & V_311 -> V_33 , sizeof( V_311 -> V_33 ) ) ;
memcpy ( & V_88 -> V_58 . V_92 , & V_311 -> V_92 , sizeof( V_311 -> V_92 ) ) ;
memcpy ( & V_88 -> V_89 , & V_311 -> V_89 , sizeof( V_311 -> V_89 ) ) ;
V_255 -> V_131 . V_156 = V_88 -> V_131 . V_156 = V_131 . V_156 ;
V_255 -> V_131 . V_316 = V_88 -> V_131 . V_316 = V_131 . V_316 ;
V_257 = F_2 ( V_4 ) ;
for ( V_259 = 0 ; V_259 < V_255 -> V_260 ; V_259 ++ , V_257 ++ ) {
struct V_261 * V_262 = & V_255 -> V_263 [ V_259 ] ;
memcpy ( & V_88 -> V_33 , & V_262 -> V_33 , sizeof( V_88 -> V_33 ) ) ;
V_88 -> V_58 . V_46 = V_262 -> V_46 ;
V_88 -> V_58 . V_91 = V_262 -> V_91 ;
V_88 -> V_58 . V_39 = V_257 -> V_39 ;
V_262 -> V_266 = V_311 -> V_266 ;
V_262 -> V_267 = V_311 -> V_267 ;
V_262 -> V_268 = V_311 -> V_268 ;
V_38 = F_163 ( V_88 , V_262 , V_255 ) ;
}
F_26 ( V_88 ) ;
F_26 ( V_255 ) ;
return 0 ;
V_314:
F_157 ( 1 , L_2 ) ;
V_315:
F_26 ( V_88 ) ;
V_312:
return V_38 ;
}
static int F_164 ( struct V_317 * V_318 ,
struct V_319 * V_320 ,
struct V_1 * * V_2 , int * V_321 )
{
struct V_1 * V_4 = V_2 [ V_322 ] ;
struct V_323 * V_324 ;
int V_259 , V_325 ;
if ( V_320 != NULL ) {
struct V_326 * V_327 ;
V_327 = F_2 ( V_2 [ V_328 ] ) ;
memcpy ( & V_320 -> V_329 , & V_327 -> V_329 , sizeof( V_320 -> V_329 ) ) ;
memcpy ( & V_320 -> V_330 , & V_327 -> V_330 , sizeof( V_320 -> V_330 ) ) ;
V_320 -> V_39 = V_327 -> V_39 ;
V_320 -> V_331 = V_327 -> V_331 ;
}
V_324 = F_2 ( V_4 ) ;
V_325 = F_3 ( V_4 ) / sizeof( * V_324 ) ;
if ( V_325 <= 0 || V_325 > V_271 )
return - V_7 ;
for ( V_259 = 0 ; V_259 < V_325 ; V_259 ++ , V_324 ++ , V_318 ++ ) {
memcpy ( & V_318 -> V_332 , & V_324 -> V_332 , sizeof( V_318 -> V_332 ) ) ;
memcpy ( & V_318 -> V_333 , & V_324 -> V_333 , sizeof( V_318 -> V_333 ) ) ;
memcpy ( & V_318 -> V_334 , & V_324 -> V_334 , sizeof( V_318 -> V_334 ) ) ;
memcpy ( & V_318 -> V_335 , & V_324 -> V_335 , sizeof( V_318 -> V_335 ) ) ;
V_318 -> V_34 = V_324 -> V_34 ;
V_318 -> V_46 = V_324 -> V_46 ;
V_318 -> V_91 = V_324 -> V_91 ;
V_318 -> V_336 = V_324 -> V_336 ;
V_318 -> V_337 = V_324 -> V_337 ;
}
* V_321 = V_259 ;
return 0 ;
}
static int F_165 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_287 * V_338 = F_42 ( V_144 ) ;
struct V_317 V_156 [ V_271 ] ;
struct V_319 V_132 , * V_339 ;
T_2 type ;
int V_38 ;
int V_340 = 0 ;
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
if ( V_2 [ V_322 ] == NULL )
return - V_7 ;
V_339 = V_2 [ V_328 ] ? & V_132 : NULL ;
V_38 = F_116 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_164 ( (struct V_317 * ) V_156 , V_339 , V_2 , & V_340 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_340 )
return 0 ;
V_317 ( & V_338 -> V_89 , V_338 -> V_236 , type , V_156 , V_340 , V_339 , V_114 ) ;
return 0 ;
}
static int F_165 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
return - V_341 ;
}
static int F_166 ( const struct V_317 * V_156 , struct V_141 * V_142 )
{
struct V_323 V_324 ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
V_324 . V_34 = V_156 -> V_34 ;
V_324 . V_46 = V_156 -> V_46 ;
V_324 . V_91 = V_156 -> V_91 ;
V_324 . V_336 = V_156 -> V_336 ;
memcpy ( & V_324 . V_332 , & V_156 -> V_332 , sizeof( V_324 . V_332 ) ) ;
memcpy ( & V_324 . V_333 , & V_156 -> V_333 , sizeof( V_324 . V_333 ) ) ;
V_324 . V_337 = V_156 -> V_337 ;
memcpy ( & V_324 . V_334 , & V_156 -> V_334 , sizeof( V_324 . V_334 ) ) ;
memcpy ( & V_324 . V_335 , & V_156 -> V_335 , sizeof( V_324 . V_335 ) ) ;
return F_64 ( V_142 , V_322 , sizeof( V_324 ) , & V_324 ) ;
}
static int F_167 ( const struct V_319 * V_320 , struct V_141 * V_142 )
{
struct V_326 V_327 ;
memset ( & V_327 , 0 , sizeof( V_327 ) ) ;
V_327 . V_39 = V_320 -> V_39 ;
V_327 . V_331 = V_320 -> V_331 ;
memcpy ( & V_327 . V_329 , & V_320 -> V_329 , sizeof( V_327 . V_329 ) ) ;
memcpy ( & V_327 . V_330 , & V_320 -> V_330 , sizeof( V_327 . V_330 ) ) ;
return F_64 ( V_142 , V_328 , sizeof( V_327 ) , & V_327 ) ;
}
static inline T_4 F_168 ( int V_325 , int V_342 )
{
return F_87 ( sizeof( struct V_287 ) )
+ ( V_342 ? F_88 ( sizeof( struct V_319 ) ) : 0 )
+ F_88 ( sizeof( struct V_323 ) * V_325 )
+ F_131 () ;
}
static int F_169 ( struct V_141 * V_142 , const struct V_317 * V_156 ,
int V_325 , const struct V_319 * V_320 ,
const struct V_343 * V_89 , T_2 V_236 , T_2 type )
{
const struct V_317 * V_344 ;
struct V_287 * V_345 ;
struct V_143 * V_144 ;
int V_259 , V_38 ;
V_144 = F_68 ( V_142 , 0 , 0 , V_346 , sizeof( * V_345 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_345 = F_42 ( V_144 ) ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
memcpy ( & V_345 -> V_89 , V_89 , sizeof( V_345 -> V_89 ) ) ;
V_345 -> V_236 = V_236 ;
if ( V_320 != NULL ) {
V_38 = F_167 ( V_320 , V_142 ) ;
if ( V_38 )
goto V_299;
}
V_38 = F_132 ( type , V_142 ) ;
if ( V_38 )
goto V_299;
for ( V_259 = 0 , V_344 = V_156 ; V_259 < V_325 ; V_259 ++ , V_344 ++ ) {
V_38 = F_166 ( V_344 , V_142 ) ;
if ( V_38 )
goto V_299;
}
return F_71 ( V_142 , V_144 ) ;
V_299:
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_170 ( const struct V_343 * V_89 , T_2 V_236 , T_2 type ,
const struct V_317 * V_156 , int V_325 ,
const struct V_319 * V_320 )
{
struct V_114 * V_114 = & V_347 ;
struct V_141 * V_142 ;
V_142 = F_80 ( F_168 ( V_325 , ! ! V_320 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_169 ( V_142 , V_156 , V_325 , V_320 , V_89 , V_236 , type ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_348 ) ;
}
static int F_170 ( const struct V_343 * V_89 , T_2 V_236 , T_2 type ,
const struct V_317 * V_156 , int V_325 ,
const struct V_319 * V_320 )
{
return - V_341 ;
}
static int F_171 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
struct V_1 * V_2 [ V_190 + 1 ] ;
const struct V_349 * V_350 ;
int type , V_38 ;
type = V_144 -> V_148 ;
if ( type > V_351 )
return - V_7 ;
type -= V_352 ;
V_350 = & V_353 [ type ] ;
if ( ! F_172 ( V_142 , V_354 ) )
return - V_161 ;
if ( ( type == ( V_355 - V_352 ) ||
type == ( V_356 - V_352 ) ) &&
( V_144 -> V_182 & V_357 ) ) {
if ( V_350 -> V_358 == NULL )
return - V_7 ;
{
struct V_359 V_147 = {
. V_358 = V_350 -> V_358 ,
. V_360 = V_350 -> V_360 ,
} ;
return F_173 ( V_114 -> V_134 . V_200 , V_142 , V_144 , & V_147 ) ;
}
}
V_38 = F_76 ( V_144 , V_361 [ type ] , V_2 , V_190 ,
V_193 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_350 -> V_362 == NULL )
return - V_7 ;
return V_350 -> V_362 ( V_142 , V_144 , V_2 ) ;
}
static void F_174 ( struct V_141 * V_142 )
{
struct V_114 * V_114 = F_41 ( V_142 -> V_145 ) ;
F_175 ( & V_114 -> V_134 . V_363 ) ;
F_176 ( V_142 , & F_171 ) ;
F_177 ( & V_114 -> V_134 . V_363 ) ;
}
static inline T_4 F_178 ( void )
{
return F_87 ( sizeof( struct V_308 ) )
+ F_88 ( sizeof( struct V_155 ) ) ;
}
static int F_179 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_308 * V_309 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , 0 , V_364 , sizeof( * V_309 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_309 = F_42 ( V_144 ) ;
F_58 ( V_88 , & V_309 -> V_139 ) ;
V_309 -> V_307 = ( V_147 -> V_291 . V_307 != 0 ) ? 1 : 0 ;
V_38 = F_66 ( V_142 , & V_88 -> V_131 ) ;
if ( V_38 )
return V_38 ;
return F_71 ( V_142 , V_144 ) ;
}
static int F_180 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_80 ( F_178 () , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_179 ( V_142 , V_88 , V_147 ) < 0 ) {
F_82 ( V_142 ) ;
return - V_166 ;
}
return F_83 ( V_114 , V_142 , 0 , V_365 ) ;
}
static int F_182 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_80 ( F_146 ( V_88 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_147 ( V_142 , V_88 , V_147 ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_366 ) ;
}
static int F_183 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_293 * V_24 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_87 ( sizeof( struct V_293 ) ) ;
V_142 = F_80 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_367 , sizeof( * V_24 ) , 0 ) ;
if ( V_144 == NULL ) {
F_82 ( V_142 ) ;
return - V_166 ;
}
V_24 = F_42 ( V_144 ) ;
V_24 -> V_34 = V_147 -> V_291 . V_34 ;
F_71 ( V_142 , V_144 ) ;
return F_83 ( V_114 , V_142 , 0 , V_368 ) ;
}
static inline T_4 F_184 ( struct V_87 * V_88 )
{
T_4 V_369 = 0 ;
if ( V_88 -> V_119 )
V_369 += F_88 ( F_8 ( V_88 -> V_119 ) ) ;
if ( V_88 -> V_121 ) {
V_369 += F_88 ( sizeof( struct V_5 ) +
( V_88 -> V_121 -> V_66 + 7 ) / 8 ) ;
V_369 += F_88 ( F_6 ( V_88 -> V_121 ) ) ;
}
if ( V_88 -> V_123 )
V_369 += F_88 ( F_4 ( V_88 -> V_123 ) ) ;
if ( V_88 -> V_125 )
V_369 += F_88 ( sizeof( * V_88 -> V_125 ) ) ;
if ( V_88 -> V_128 )
V_369 += F_88 ( sizeof( * V_88 -> V_128 ) ) ;
if ( V_88 -> V_129 )
V_369 += F_88 ( sizeof( V_88 -> V_129 ) ) ;
if ( V_88 -> V_78 )
V_369 += F_88 ( F_12 ( V_88 -> V_78 ) ) ;
if ( V_88 -> V_175 )
V_369 += F_88 ( sizeof( struct V_19 ) +
V_88 -> V_175 -> V_22 ) ;
if ( V_88 -> V_130 )
V_369 += F_88 ( sizeof( * V_88 -> V_130 ) ) ;
if ( V_88 -> V_58 . V_118 )
V_369 += F_88 ( sizeof( V_88 -> V_58 . V_118 ) ) ;
V_369 += F_88 ( sizeof( V_370 ) ) ;
return V_369 ;
}
static int F_185 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_23 * V_24 ;
struct V_154 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_184 ( V_88 ) ;
int V_371 , V_38 ;
V_371 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_372 ) {
V_21 += F_88 ( V_371 ) ;
V_371 = sizeof( * V_33 ) ;
V_21 += F_88 ( sizeof( struct V_155 ) ) ;
}
V_21 += F_87 ( V_371 ) ;
V_142 = F_80 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_371 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_373;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_153 == V_372 ) {
struct V_1 * V_164 ;
V_33 = F_42 ( V_144 ) ;
memcpy ( & V_33 -> V_159 , & V_88 -> V_33 . V_159 , sizeof( V_33 -> V_159 ) ) ;
V_33 -> V_49 = V_88 -> V_33 . V_49 ;
V_33 -> V_39 = V_88 -> V_58 . V_39 ;
V_33 -> V_34 = V_88 -> V_33 . V_34 ;
V_164 = F_60 ( V_142 , V_374 , sizeof( * V_24 ) ) ;
V_38 = - V_166 ;
if ( V_164 == NULL )
goto V_373;
V_24 = F_2 ( V_164 ) ;
}
V_38 = F_62 ( V_88 , V_24 , V_142 ) ;
if ( V_38 )
goto V_373;
F_71 ( V_142 , V_144 ) ;
return F_83 ( V_114 , V_142 , 0 , V_368 ) ;
V_373:
F_82 ( V_142 ) ;
return V_38 ;
}
static int F_186 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_364 :
return F_180 ( V_88 , V_147 ) ;
case V_296 :
return F_182 ( V_88 , V_147 ) ;
case V_372 :
case V_375 :
case V_149 :
return F_185 ( V_88 , V_147 ) ;
case V_367 :
return F_183 ( V_147 ) ;
default:
F_187 ( V_376 L_3 ,
V_147 -> V_153 ) ;
break;
}
return 0 ;
}
static inline T_4 F_188 ( struct V_87 * V_88 ,
struct V_253 * V_255 )
{
return F_87 ( sizeof( struct V_310 ) )
+ F_88 ( sizeof( struct V_256 ) * V_255 -> V_260 )
+ F_88 ( sizeof( struct V_155 ) )
+ F_88 ( F_27 ( V_88 -> V_175 ) )
+ F_131 () ;
}
static int F_189 ( struct V_141 * V_142 , struct V_87 * V_88 ,
struct V_261 * V_377 , struct V_253 * V_255 )
{
T_6 V_133 = F_190 () ;
struct V_310 * V_311 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , 0 , 0 , V_378 , sizeof( * V_311 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_311 = F_42 ( V_144 ) ;
memcpy ( & V_311 -> V_33 , & V_88 -> V_33 , sizeof( V_311 -> V_33 ) ) ;
memcpy ( & V_311 -> V_92 , & V_88 -> V_58 . V_92 , sizeof( V_311 -> V_92 ) ) ;
memcpy ( & V_311 -> V_89 , & V_88 -> V_89 , sizeof( V_311 -> V_89 ) ) ;
F_118 ( V_255 , & V_311 -> V_313 , V_238 ) ;
V_311 -> V_266 = V_377 -> V_266 ;
V_311 -> V_267 = V_377 -> V_267 ;
V_311 -> V_268 = V_377 -> V_268 ;
V_311 -> V_133 = V_88 -> V_132 . V_133 = V_133 ;
V_38 = F_128 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_129 ( V_88 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_255 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , & V_255 -> V_131 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
return F_71 ( V_142 , V_144 ) ;
}
static int F_191 ( struct V_87 * V_88 , struct V_261 * V_377 ,
struct V_253 * V_255 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_80 ( F_188 ( V_88 , V_255 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_189 ( V_142 , V_88 , V_377 , V_255 ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_379 ) ;
}
static struct V_253 * F_192 ( struct V_187 * V_145 , int V_380 ,
T_2 * V_291 , int V_21 , int * V_236 )
{
struct V_114 * V_114 = F_41 ( V_145 ) ;
struct V_242 * V_24 = (struct V_242 * ) V_291 ;
struct V_256 * V_257 = (struct V_256 * ) ( V_24 + 1 ) ;
struct V_253 * V_255 ;
int V_258 ;
switch ( V_145 -> V_381 ) {
case V_40 :
if ( V_380 != V_382 ) {
* V_236 = - V_383 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_380 != V_384 ) {
* V_236 = - V_383 ;
return NULL ;
}
break;
#endif
default:
* V_236 = - V_7 ;
return NULL ;
}
* V_236 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_110 ( V_24 ) )
return NULL ;
V_258 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_257 ) ) ;
if ( F_114 ( V_258 , V_257 , V_24 -> V_89 . V_39 ) )
return NULL ;
if ( V_24 -> V_236 > V_238 )
return NULL ;
V_255 = F_120 ( V_114 , V_197 ) ;
if ( V_255 == NULL ) {
* V_236 = - V_385 ;
return NULL ;
}
F_117 ( V_255 , V_24 ) ;
V_255 -> type = V_240 ;
F_113 ( V_255 , V_257 , V_258 ) ;
* V_236 = V_24 -> V_236 ;
return V_255 ;
}
static inline T_4 F_193 ( struct V_253 * V_255 )
{
return F_87 ( sizeof( struct V_306 ) )
+ F_88 ( sizeof( struct V_256 ) * V_255 -> V_260 )
+ F_88 ( F_27 ( V_255 -> V_175 ) )
+ F_88 ( sizeof( struct V_155 ) )
+ F_131 () ;
}
static int F_194 ( struct V_141 * V_142 , struct V_253 * V_255 ,
int V_236 , const struct V_146 * V_147 )
{
struct V_306 * V_386 ;
int V_307 = V_147 -> V_291 . V_307 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , 0 , V_387 , sizeof( * V_386 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_386 = F_42 ( V_144 ) ;
F_118 ( V_255 , & V_386 -> V_254 , V_236 ) ;
V_38 = F_128 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_130 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_255 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , & V_255 -> V_131 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
V_386 -> V_307 = ! ! V_307 ;
return F_71 ( V_142 , V_144 ) ;
}
static int F_195 ( struct V_253 * V_255 , int V_236 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_196 ( V_255 ) ;
struct V_141 * V_142 ;
V_142 = F_80 ( F_193 ( V_255 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_194 ( V_142 , V_255 , V_236 , V_147 ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_365 ) ;
}
static int F_197 ( struct V_253 * V_255 , int V_236 , const struct V_146 * V_147 )
{
int V_21 = F_88 ( sizeof( struct V_256 ) * V_255 -> V_260 ) ;
struct V_114 * V_114 = F_196 ( V_255 ) ;
struct V_242 * V_24 ;
struct V_287 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_371 , V_38 ;
V_371 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_289 ) {
V_21 += F_88 ( V_371 ) ;
V_371 = sizeof( * V_33 ) ;
}
V_21 += F_131 () ;
V_21 += F_88 ( sizeof( struct V_155 ) ) ;
V_21 += F_87 ( V_371 ) ;
V_142 = F_80 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_371 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_373;
V_24 = F_42 ( V_144 ) ;
if ( V_147 -> V_153 == V_289 ) {
struct V_1 * V_164 ;
V_33 = F_42 ( V_144 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_236 = V_236 ;
if ( V_147 -> V_291 . V_292 )
V_33 -> V_251 = V_255 -> V_251 ;
else
memcpy ( & V_33 -> V_89 , & V_255 -> V_279 , sizeof( V_33 -> V_89 ) ) ;
V_164 = F_60 ( V_142 , V_388 , sizeof( * V_24 ) ) ;
V_38 = - V_166 ;
if ( V_164 == NULL )
goto V_373;
V_24 = F_2 ( V_164 ) ;
}
F_118 ( V_255 , V_24 , V_236 ) ;
V_38 = F_128 ( V_255 , V_142 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_255 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , & V_255 -> V_131 ) ;
if ( V_38 )
goto V_373;
F_71 ( V_142 , V_144 ) ;
return F_83 ( V_114 , V_142 , 0 , V_389 ) ;
V_373:
F_82 ( V_142 ) ;
return V_38 ;
}
static int F_198 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_80 ( F_131 () , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_68 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_390 , 0 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_373;
V_38 = F_132 ( V_147 -> V_291 . type , V_142 ) ;
if ( V_38 )
goto V_373;
F_71 ( V_142 , V_144 ) ;
return F_83 ( V_114 , V_142 , 0 , V_389 ) ;
V_373:
F_82 ( V_142 ) ;
return V_38 ;
}
static int F_199 ( struct V_253 * V_255 , int V_236 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_282 :
case V_391 :
case V_289 :
return F_197 ( V_255 , V_236 , V_147 ) ;
case V_390 :
return F_198 ( V_147 ) ;
case V_387 :
return F_195 ( V_255 , V_236 , V_147 ) ;
default:
F_187 ( V_376 L_4 ,
V_147 -> V_153 ) ;
}
return 0 ;
}
static inline T_4 F_200 ( void )
{
return F_87 ( sizeof( struct V_392 ) ) ;
}
static int F_201 ( struct V_141 * V_142 , T_2 V_34 ,
struct V_343 * V_89 , T_1 * V_393 )
{
struct V_392 * V_394 ;
struct V_143 * V_144 ;
V_144 = F_68 ( V_142 , 0 , 0 , V_395 , sizeof( * V_394 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_394 = F_42 ( V_144 ) ;
V_394 -> V_34 = V_34 ;
memcpy ( & V_394 -> V_89 , V_89 , sizeof( V_394 -> V_89 ) ) ;
if ( V_393 ) {
int V_38 = F_64 ( V_142 , V_53 , sizeof( * V_393 ) , V_393 ) ;
if ( V_38 ) {
F_70 ( V_142 , V_144 ) ;
return V_38 ;
}
}
return F_71 ( V_142 , V_144 ) ;
}
static int F_202 ( struct V_114 * V_114 , T_2 V_34 ,
struct V_343 * V_89 , T_1 * V_393 )
{
struct V_141 * V_142 ;
V_142 = F_80 ( F_200 () , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_201 ( V_142 , V_34 , V_89 , V_393 ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_396 ) ;
}
static inline T_4 F_203 ( void )
{
return F_87 ( sizeof( struct V_397 ) ) ;
}
static int F_204 ( struct V_141 * V_142 , struct V_87 * V_88 ,
T_1 * V_335 , T_7 V_398 )
{
struct V_397 * V_324 ;
struct V_143 * V_144 ;
V_144 = F_68 ( V_142 , 0 , 0 , V_399 , sizeof( * V_324 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_324 = F_42 ( V_144 ) ;
memcpy ( & V_324 -> V_33 . V_159 , & V_88 -> V_33 . V_159 , sizeof( V_324 -> V_33 . V_159 ) ) ;
V_324 -> V_33 . V_49 = V_88 -> V_33 . V_49 ;
V_324 -> V_33 . V_39 = V_88 -> V_58 . V_39 ;
V_324 -> V_33 . V_34 = V_88 -> V_33 . V_34 ;
memcpy ( & V_324 -> V_335 , V_335 , sizeof( V_324 -> V_335 ) ) ;
memcpy ( & V_324 -> V_333 , & V_88 -> V_58 . V_92 , sizeof( V_324 -> V_333 ) ) ;
V_324 -> V_398 = V_398 ;
V_324 -> V_400 = V_88 -> V_128 -> V_401 ;
V_324 -> V_91 = V_88 -> V_58 . V_91 ;
return F_71 ( V_142 , V_144 ) ;
}
static int F_205 ( struct V_87 * V_88 , T_1 * V_402 ,
T_7 V_403 )
{
struct V_114 * V_114 = F_181 ( V_88 ) ;
struct V_141 * V_142 ;
if ( V_88 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_88 -> V_128 )
return - V_7 ;
V_142 = F_80 ( F_203 () , V_197 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_204 ( V_142 , V_88 , V_402 , V_403 ) < 0 )
F_92 () ;
return F_83 ( V_114 , V_142 , 0 , V_404 ) ;
}
static bool F_206 ( const struct V_146 * V_147 )
{
return ( bool ) F_207 ( V_147 -> V_114 ) ;
}
static int T_8 F_208 ( struct V_114 * V_114 )
{
struct V_187 * V_200 ;
struct V_405 V_406 = {
. V_407 = V_408 ,
. V_409 = F_174 ,
} ;
V_200 = F_209 ( V_114 , V_410 , & V_406 ) ;
if ( V_200 == NULL )
return - V_68 ;
V_114 -> V_134 . V_411 = V_200 ;
F_210 ( V_114 -> V_134 . V_200 , V_200 ) ;
return 0 ;
}
static void T_9 F_211 ( struct V_412 * V_413 )
{
struct V_114 * V_114 ;
F_212 (net, net_exit_list, exit_list)
F_213 ( V_114 -> V_134 . V_200 , NULL ) ;
F_214 () ;
F_212 (net, net_exit_list, exit_list)
F_215 ( V_114 -> V_134 . V_411 ) ;
}
static int T_10 F_216 ( void )
{
int V_414 ;
F_187 ( V_415 L_5 ) ;
V_414 = F_217 ( & V_416 ) ;
if ( V_414 < 0 )
return V_414 ;
V_414 = F_218 ( & V_417 ) ;
if ( V_414 < 0 )
F_219 ( & V_416 ) ;
return V_414 ;
}
static void T_11 F_220 ( void )
{
F_221 ( & V_417 ) ;
F_219 ( & V_416 ) ;
}
