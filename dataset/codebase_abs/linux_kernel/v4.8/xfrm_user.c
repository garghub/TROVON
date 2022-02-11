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
static int F_16 ( struct V_57 * V_58 , struct V_1 * V_59 )
{
struct V_5 * V_24 , * V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_17 ( V_60 -> V_11 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
V_58 -> V_64 . V_65 = V_62 -> V_66 . V_67 ;
V_24 = F_18 ( V_60 , F_4 ( V_60 ) , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
strcpy ( V_24 -> V_11 , V_62 -> V_70 ) ;
V_58 -> V_71 = V_24 ;
V_58 -> V_72 = V_62 -> V_73 . V_74 . V_72 ;
return 0 ;
}
static int F_19 ( struct V_14 * * V_75 , T_2 * V_64 ,
struct V_1 * V_59 )
{
struct V_5 * V_60 ;
struct V_14 * V_24 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_20 ( V_60 -> V_11 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
* V_64 = V_62 -> V_66 . V_67 ;
V_24 = F_21 ( sizeof( * V_24 ) + ( V_60 -> V_76 + 7 ) / 8 , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
strcpy ( V_24 -> V_11 , V_62 -> V_70 ) ;
V_24 -> V_76 = V_60 -> V_76 ;
V_24 -> V_77 = V_62 -> V_73 . V_78 . V_79 ;
memcpy ( V_24 -> V_80 , V_60 -> V_80 , ( V_60 -> V_76 + 7 ) / 8 ) ;
* V_75 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_14 * * V_75 , T_2 * V_64 ,
struct V_1 * V_59 )
{
struct V_14 * V_24 , * V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_20 ( V_60 -> V_11 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
if ( V_60 -> V_77 > V_62 -> V_73 . V_78 . V_81 )
return - V_7 ;
* V_64 = V_62 -> V_66 . V_67 ;
V_24 = F_18 ( V_60 , F_6 ( V_60 ) , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
strcpy ( V_24 -> V_11 , V_62 -> V_70 ) ;
if ( ! V_24 -> V_77 )
V_24 -> V_77 = V_62 -> V_73 . V_78 . V_79 ;
* V_75 = V_24 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 , struct V_1 * V_59 )
{
struct V_16 * V_24 , * V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return 0 ;
V_60 = F_2 ( V_59 ) ;
V_62 = F_24 ( V_60 -> V_11 , V_60 -> V_82 , 1 ) ;
if ( ! V_62 )
return - V_63 ;
V_58 -> V_64 . V_65 = V_62 -> V_66 . V_67 ;
V_24 = F_18 ( V_60 , F_8 ( V_60 ) , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
strcpy ( V_24 -> V_11 , V_62 -> V_70 ) ;
V_58 -> V_83 = V_24 ;
V_58 -> V_72 = V_62 -> V_73 . V_83 . V_72 ;
return 0 ;
}
static inline int F_25 ( struct V_26 * V_84 ,
struct V_1 * V_85 )
{
struct V_26 * V_86 ;
int V_87 ;
if ( ! V_84 || ! V_85 )
return 0 ;
V_86 = F_2 ( V_85 ) ;
V_87 = F_12 ( V_86 ) ;
if ( F_3 ( V_85 ) < V_87 || F_12 ( V_84 ) != V_87 )
return - V_7 ;
return 0 ;
}
static int F_26 ( struct V_26 * * V_84 ,
struct V_26 * * V_88 ,
struct V_1 * V_59 )
{
struct V_26 * V_24 , * V_89 , * V_86 ;
int V_90 , V_87 ;
if ( ! V_59 )
return 0 ;
V_86 = F_2 ( V_59 ) ;
V_90 = F_12 ( V_86 ) ;
V_87 = F_3 ( V_59 ) >= V_90 ? V_90 : sizeof( * V_86 ) ;
V_24 = F_27 ( V_90 , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
V_89 = F_27 ( V_90 , V_68 ) ;
if ( ! V_89 ) {
F_28 ( V_24 ) ;
return - V_69 ;
}
memcpy ( V_24 , V_86 , V_87 ) ;
memcpy ( V_89 , V_86 , V_87 ) ;
* V_84 = V_24 ;
* V_88 = V_89 ;
return 0 ;
}
static inline int F_29 ( struct V_91 * V_92 )
{
int V_21 = 0 ;
if ( V_92 ) {
V_21 += sizeof( struct V_19 ) ;
V_21 += V_92 -> V_22 ;
}
return V_21 ;
}
static void F_30 ( struct V_57 * V_58 , struct V_23 * V_24 )
{
memcpy ( & V_58 -> V_33 , & V_24 -> V_33 , sizeof( V_58 -> V_33 ) ) ;
memcpy ( & V_58 -> V_93 , & V_24 -> V_93 , sizeof( V_58 -> V_93 ) ) ;
memcpy ( & V_58 -> V_94 , & V_24 -> V_94 , sizeof( V_58 -> V_94 ) ) ;
V_58 -> V_64 . V_46 = V_24 -> V_46 ;
V_58 -> V_64 . V_37 = F_31 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_58 -> V_64 . V_95 = V_24 -> V_95 ;
V_58 -> V_64 . V_39 = V_24 -> V_39 ;
memcpy ( & V_58 -> V_64 . V_96 , & V_24 -> V_96 , sizeof( V_58 -> V_64 . V_96 ) ) ;
V_58 -> V_64 . V_28 = V_24 -> V_28 ;
if ( ! V_58 -> V_93 . V_39 && ! ( V_24 -> V_28 & V_97 ) )
V_58 -> V_93 . V_39 = V_24 -> V_39 ;
}
static void F_32 ( struct V_57 * V_58 , struct V_1 * * V_2 ,
int V_98 )
{
struct V_1 * V_85 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_98 ? V_2 [ V_25 ] : NULL ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
struct V_1 * V_103 = V_2 [ V_104 ] ;
struct V_1 * V_4 = V_2 [ V_105 ] ;
if ( V_100 ) {
struct V_26 * V_84 ;
V_84 = F_2 ( V_100 ) ;
memcpy ( V_58 -> V_84 , V_84 ,
F_12 ( V_84 ) ) ;
memcpy ( V_58 -> V_88 , V_84 ,
F_12 ( V_84 ) ) ;
}
if ( V_85 ) {
struct V_106 * V_107 ;
V_107 = F_2 ( V_85 ) ;
memcpy ( & V_58 -> V_107 , V_107 , sizeof( * V_107 ) ) ;
memcpy ( & V_58 -> V_108 , V_107 , sizeof( * V_107 ) ) ;
}
if ( V_101 ) {
struct V_109 * V_110 ;
V_110 = F_2 ( V_101 ) ;
V_58 -> V_111 . V_112 = V_110 -> V_112 ;
V_58 -> V_111 . V_113 = V_110 -> V_113 ;
V_58 -> V_111 . V_114 = V_110 -> V_114 ;
V_58 -> V_111 . V_115 = V_110 -> V_115 ;
}
if ( V_103 )
V_58 -> V_116 = F_33 ( V_103 ) ;
if ( V_4 )
V_58 -> V_117 = F_33 ( V_4 ) ;
}
static struct V_57 * F_34 ( struct V_118 * V_118 ,
struct V_23 * V_24 ,
struct V_1 * * V_2 ,
int * V_119 )
{
struct V_57 * V_58 = F_35 ( V_118 ) ;
int V_38 = - V_69 ;
if ( ! V_58 )
goto V_120;
F_30 ( V_58 , V_24 ) ;
if ( V_2 [ V_121 ] )
V_58 -> V_64 . V_122 = F_33 ( V_2 [ V_121 ] ) ;
if ( ( V_38 = F_23 ( V_58 , V_2 [ V_15 ] ) ) )
goto error;
if ( ( V_38 = F_22 ( & V_58 -> V_123 , & V_58 -> V_64 . V_124 ,
V_2 [ V_13 ] ) ) )
goto error;
if ( ! V_58 -> V_64 . V_124 ) {
if ( ( V_38 = F_19 ( & V_58 -> V_123 , & V_58 -> V_64 . V_124 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_38 = F_16 ( V_58 , V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_38 = F_36 ( & V_58 -> V_125 , & V_58 -> V_64 . V_126 ,
V_127 ,
V_2 [ V_10 ] ) ) )
goto error;
if ( V_2 [ V_52 ] ) {
V_58 -> V_128 = F_18 ( F_2 ( V_2 [ V_52 ] ) ,
sizeof( * V_58 -> V_128 ) , V_68 ) ;
if ( V_58 -> V_128 == NULL )
goto error;
}
if ( V_2 [ V_45 ] )
V_58 -> V_129 = F_33 ( V_2 [ V_45 ] ) ;
if ( V_2 [ V_53 ] ) {
V_58 -> V_130 = F_18 ( F_2 ( V_2 [ V_53 ] ) ,
sizeof( * V_58 -> V_130 ) , V_68 ) ;
if ( V_58 -> V_130 == NULL )
goto error;
}
F_37 ( V_2 , & V_58 -> V_131 ) ;
V_38 = F_38 ( V_58 , false ) ;
if ( V_38 )
goto error;
if ( V_2 [ V_18 ] ) {
V_38 = F_39 ( V_58 ,
F_2 ( V_2 [ V_18 ] ) ) ;
if ( V_38 )
goto error;
}
if ( ( V_38 = F_26 ( & V_58 -> V_84 , & V_58 -> V_88 ,
V_2 [ V_25 ] ) ) )
goto error;
V_58 -> V_132 . V_133 = V_24 -> V_133 ;
V_58 -> V_117 = V_118 -> V_134 . V_135 ;
V_58 -> V_116 = ( V_118 -> V_134 . V_136 * V_137 ) / V_138 ;
if ( ( V_38 = F_40 ( V_58 ) ) )
goto error;
F_32 ( V_58 , V_2 , 0 ) ;
return V_58 ;
error:
V_58 -> V_132 . V_139 = V_140 ;
F_41 ( V_58 ) ;
V_120:
* V_119 = V_38 ;
return NULL ;
}
static int F_42 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_23 * V_24 = F_44 ( V_144 ) ;
struct V_57 * V_58 ;
int V_38 ;
struct V_146 V_147 ;
V_38 = F_13 ( V_24 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_58 = F_34 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( ! V_58 )
return V_38 ;
F_45 ( V_58 ) ;
if ( V_144 -> V_148 == V_149 )
V_38 = F_46 ( V_58 ) ;
else
V_38 = F_47 ( V_58 ) ;
F_48 ( V_58 , V_38 ? 0 : 1 , true ) ;
if ( V_38 < 0 ) {
V_58 -> V_132 . V_139 = V_140 ;
F_49 ( V_58 ) ;
goto V_44;
}
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_153 = V_144 -> V_148 ;
F_50 ( V_58 , & V_147 ) ;
V_44:
F_41 ( V_58 ) ;
return V_38 ;
}
static struct V_57 * F_51 ( struct V_118 * V_118 ,
struct V_154 * V_24 ,
struct V_1 * * V_2 ,
int * V_119 )
{
struct V_57 * V_58 = NULL ;
struct V_155 V_156 ;
int V_38 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
if ( F_52 ( V_24 -> V_34 , V_157 ) ) {
V_38 = - V_158 ;
V_58 = F_53 ( V_118 , V_131 , & V_24 -> V_159 , V_24 -> V_49 , V_24 -> V_34 , V_24 -> V_39 ) ;
} else {
T_1 * V_96 = NULL ;
F_9 ( V_2 , V_160 , & V_96 ) ;
if ( ! V_96 ) {
V_38 = - V_7 ;
goto V_44;
}
V_38 = - V_158 ;
V_58 = F_54 ( V_118 , V_131 ,
& V_24 -> V_159 , V_96 ,
V_24 -> V_34 , V_24 -> V_39 ) ;
}
V_44:
if ( ! V_58 && V_119 )
* V_119 = V_38 ;
return V_58 ;
}
static int F_55 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
int V_38 = - V_158 ;
struct V_146 V_147 ;
struct V_154 * V_24 = F_44 ( V_144 ) ;
V_58 = F_51 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( V_58 == NULL )
return V_38 ;
if ( ( V_38 = F_56 ( V_58 ) ) != 0 )
goto V_44;
if ( F_57 ( V_58 ) ) {
V_38 = - V_161 ;
goto V_44;
}
V_38 = F_58 ( V_58 ) ;
if ( V_38 < 0 )
goto V_44;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_153 = V_144 -> V_148 ;
F_50 ( V_58 , & V_147 ) ;
V_44:
F_59 ( V_58 , V_38 ? 0 : 1 , true ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static void F_60 ( struct V_57 * V_58 , struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_33 , & V_58 -> V_33 , sizeof( V_24 -> V_33 ) ) ;
memcpy ( & V_24 -> V_93 , & V_58 -> V_93 , sizeof( V_24 -> V_93 ) ) ;
memcpy ( & V_24 -> V_94 , & V_58 -> V_94 , sizeof( V_24 -> V_94 ) ) ;
memcpy ( & V_24 -> V_111 , & V_58 -> V_111 , sizeof( V_24 -> V_111 ) ) ;
F_61 ( V_58 -> V_162 . V_37 , & V_24 -> V_162 . V_37 ) ;
F_61 ( V_58 -> V_162 . V_107 , & V_24 -> V_162 . V_107 ) ;
F_61 ( V_58 -> V_162 . V_163 , & V_24 -> V_162 . V_163 ) ;
memcpy ( & V_24 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_24 -> V_96 ) ) ;
V_24 -> V_46 = V_58 -> V_64 . V_46 ;
V_24 -> V_37 = V_58 -> V_64 . V_37 ;
V_24 -> V_95 = V_58 -> V_64 . V_95 ;
V_24 -> V_39 = V_58 -> V_64 . V_39 ;
V_24 -> V_28 = V_58 -> V_64 . V_28 ;
V_24 -> V_133 = V_58 -> V_132 . V_133 ;
}
static int F_62 ( struct V_91 * V_164 , struct V_141 * V_142 )
{
struct V_19 * V_20 ;
struct V_1 * V_165 ;
int V_166 = sizeof( * V_20 ) + V_164 -> V_22 ;
V_165 = F_63 ( V_142 , V_18 , V_166 ) ;
if ( V_165 == NULL )
return - V_167 ;
V_20 = F_2 ( V_165 ) ;
V_20 -> V_168 = V_18 ;
V_20 -> V_21 = V_166 ;
V_20 -> V_169 = V_164 -> V_169 ;
V_20 -> V_170 = V_164 -> V_170 ;
V_20 -> V_22 = V_164 -> V_22 ;
memcpy ( V_20 + 1 , V_164 -> V_171 , V_164 -> V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_14 * V_78 , struct V_141 * V_142 )
{
struct V_5 * V_62 ;
struct V_1 * V_172 ;
V_172 = F_63 ( V_142 , V_8 ,
sizeof( * V_62 ) + ( V_78 -> V_76 + 7 ) / 8 ) ;
if ( ! V_172 )
return - V_167 ;
V_62 = F_2 ( V_172 ) ;
strncpy ( V_62 -> V_11 , V_78 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_80 , V_78 -> V_80 , ( V_78 -> V_76 + 7 ) / 8 ) ;
V_62 -> V_76 = V_78 -> V_76 ;
return 0 ;
}
static int F_65 ( struct V_57 * V_58 ,
struct V_23 * V_24 ,
struct V_141 * V_142 )
{
int V_173 = 0 ;
F_60 ( V_58 , V_24 ) ;
if ( V_58 -> V_64 . V_122 ) {
V_173 = F_66 ( V_142 , V_121 ,
V_58 -> V_64 . V_122 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_130 ) {
V_173 = F_67 ( V_142 , V_53 , sizeof( * V_58 -> V_130 ) , V_58 -> V_130 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_174 ) {
V_173 = F_68 ( V_142 , V_175 , V_58 -> V_174 ,
V_176 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_83 ) {
V_173 = F_67 ( V_142 , V_15 , F_8 ( V_58 -> V_83 ) , V_58 -> V_83 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_123 ) {
V_173 = F_64 ( V_58 -> V_123 , V_142 ) ;
if ( ! V_173 )
V_173 = F_67 ( V_142 , V_13 ,
F_6 ( V_58 -> V_123 ) , V_58 -> V_123 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_71 ) {
V_173 = F_67 ( V_142 , V_9 , F_4 ( V_58 -> V_71 ) , V_58 -> V_71 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_125 ) {
V_173 = F_67 ( V_142 , V_10 , sizeof( * ( V_58 -> V_125 ) ) , V_58 -> V_125 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_128 ) {
V_173 = F_67 ( V_142 , V_52 , sizeof( * V_58 -> V_128 ) , V_58 -> V_128 ) ;
if ( V_173 )
goto V_44;
}
if ( V_58 -> V_129 ) {
V_173 = F_66 ( V_142 , V_45 , V_58 -> V_129 ) ;
if ( V_173 )
goto V_44;
}
V_173 = F_69 ( V_142 , & V_58 -> V_131 ) ;
if ( V_173 )
goto V_44;
if ( V_58 -> V_84 )
V_173 = F_67 ( V_142 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
else
V_173 = F_67 ( V_142 , V_99 , sizeof( V_58 -> V_107 ) ,
& V_58 -> V_107 ) ;
if ( V_173 )
goto V_44;
if ( V_58 -> V_177 )
V_173 = F_62 ( V_58 -> V_177 , V_142 ) ;
V_44:
return V_173 ;
}
static int F_70 ( struct V_57 * V_58 , int V_178 , void * V_179 )
{
struct V_180 * V_181 = V_179 ;
struct V_141 * V_182 = V_181 -> V_182 ;
struct V_141 * V_142 = V_181 -> V_183 ;
struct V_23 * V_24 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , F_72 ( V_182 ) . V_151 , V_181 -> V_150 ,
V_149 , sizeof( * V_24 ) , V_181 -> V_184 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_24 = F_44 ( V_144 ) ;
V_38 = F_65 ( V_58 , V_24 , V_142 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_75 ( struct V_185 * V_186 )
{
struct V_187 * V_188 = (struct V_187 * ) & V_186 -> args [ 1 ] ;
struct V_189 * V_145 = V_186 -> V_142 -> V_145 ;
struct V_118 * V_118 = F_43 ( V_145 ) ;
if ( V_186 -> args [ 0 ] )
F_76 ( V_188 , V_118 ) ;
return 0 ;
}
static int F_77 ( struct V_141 * V_142 , struct V_185 * V_186 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_187 * V_188 = (struct V_187 * ) & V_186 -> args [ 1 ] ;
struct V_180 V_190 ;
F_78 ( sizeof( struct V_187 ) >
sizeof( V_186 -> args ) - sizeof( V_186 -> args [ 0 ] ) ) ;
V_190 . V_182 = V_186 -> V_142 ;
V_190 . V_183 = V_142 ;
V_190 . V_150 = V_186 -> V_144 -> V_150 ;
V_190 . V_184 = V_191 ;
if ( ! V_186 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_192 + 1 ] ;
struct V_193 * V_194 = NULL ;
T_2 V_34 = 0 ;
int V_38 ;
V_38 = F_79 ( V_186 -> V_144 , 0 , V_2 , V_192 ,
V_195 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_196 ] ) {
V_194 = F_18 ( F_2 ( V_2 [ V_196 ] ) ,
sizeof( * V_194 ) , V_68 ) ;
if ( V_194 == NULL )
return - V_69 ;
}
if ( V_2 [ V_197 ] )
V_34 = F_80 ( V_2 [ V_197 ] ) ;
F_81 ( V_188 , V_34 , V_194 ) ;
V_186 -> args [ 0 ] = 1 ;
}
( void ) V_187 ( V_118 , V_188 , F_70 , & V_190 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_82 ( struct V_141 * V_182 ,
struct V_57 * V_58 , T_3 V_133 )
{
struct V_180 V_190 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( V_198 , V_199 ) ;
if ( ! V_142 )
return F_84 ( - V_69 ) ;
V_190 . V_182 = V_182 ;
V_190 . V_183 = V_142 ;
V_190 . V_150 = V_133 ;
V_190 . V_184 = 0 ;
V_38 = F_70 ( V_58 , 0 , & V_190 ) ;
if ( V_38 ) {
F_85 ( V_142 ) ;
return F_84 ( V_38 ) ;
}
return V_142 ;
}
static inline int F_86 ( struct V_118 * V_118 , struct V_141 * V_142 ,
T_3 V_200 , unsigned int V_201 )
{
struct V_189 * V_202 = F_87 ( V_118 -> V_134 . V_202 ) ;
if ( V_202 )
return F_88 ( V_202 , V_142 , V_200 , V_201 , V_199 ) ;
else
return - 1 ;
}
static inline T_4 F_89 ( void )
{
return F_90 ( 4 )
+ F_91 ( sizeof( struct V_203 ) )
+ F_91 ( sizeof( struct V_204 ) )
+ F_91 ( sizeof( struct V_205 ) )
+ F_91 ( sizeof( struct V_205 ) ) ;
}
static int F_92 ( struct V_141 * V_142 , struct V_118 * V_118 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_206 V_207 ;
struct V_203 V_208 ;
struct V_204 V_209 ;
struct V_205 V_210 , V_211 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_212 ;
unsigned V_213 ;
V_144 = F_71 ( V_142 , V_151 , V_133 , V_214 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_212 = F_44 ( V_144 ) ;
* V_212 = V_28 ;
F_93 ( V_118 , & V_207 ) ;
V_208 . V_215 = V_207 . V_215 ;
V_208 . V_216 = V_207 . V_216 ;
V_208 . V_217 = V_207 . V_217 ;
V_208 . V_218 = V_207 . V_218 ;
V_208 . V_219 = V_207 . V_219 ;
V_208 . V_220 = V_207 . V_220 ;
V_209 . V_221 = V_207 . V_221 ;
V_209 . V_222 = V_207 . V_222 ;
do {
V_213 = F_94 ( & V_118 -> V_134 . V_223 . V_224 ) ;
V_210 . V_225 = V_118 -> V_134 . V_223 . V_226 ;
V_210 . V_227 = V_118 -> V_134 . V_223 . V_228 ;
V_211 . V_225 = V_118 -> V_134 . V_223 . V_229 ;
V_211 . V_227 = V_118 -> V_134 . V_223 . V_230 ;
} while ( F_95 ( & V_118 -> V_134 . V_223 . V_224 , V_213 ) );
V_38 = F_67 ( V_142 , V_231 , sizeof( V_208 ) , & V_208 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_232 , sizeof( V_209 ) , & V_209 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_233 , sizeof( V_210 ) , & V_210 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_234 , sizeof( V_211 ) , & V_211 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_96 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_205 * V_235 = NULL ;
struct V_205 * V_236 = NULL ;
if ( V_2 [ V_233 ] ) {
struct V_1 * V_59 = V_2 [ V_233 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_235 ) )
return - V_7 ;
V_235 = F_2 ( V_59 ) ;
if ( V_235 -> V_225 > 32 || V_235 -> V_227 > 32 )
return - V_7 ;
}
if ( V_2 [ V_234 ] ) {
struct V_1 * V_59 = V_2 [ V_234 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_236 ) )
return - V_7 ;
V_236 = F_2 ( V_59 ) ;
if ( V_236 -> V_225 > 128 || V_236 -> V_227 > 128 )
return - V_7 ;
}
if ( V_235 || V_236 ) {
F_97 ( & V_118 -> V_134 . V_223 . V_224 ) ;
if ( V_235 ) {
V_118 -> V_134 . V_223 . V_226 = V_235 -> V_225 ;
V_118 -> V_134 . V_223 . V_228 = V_235 -> V_227 ;
}
if ( V_236 ) {
V_118 -> V_134 . V_223 . V_229 = V_236 -> V_225 ;
V_118 -> V_134 . V_223 . V_230 = V_236 -> V_227 ;
}
F_98 ( & V_118 -> V_134 . V_223 . V_224 ) ;
F_99 ( V_118 ) ;
}
return 0 ;
}
static int F_100 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_141 * V_237 ;
T_3 * V_28 = F_44 ( V_144 ) ;
T_3 V_238 = F_72 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_237 = F_83 ( F_89 () , V_199 ) ;
if ( V_237 == NULL )
return - V_69 ;
if ( F_92 ( V_237 , V_118 , V_238 , V_133 , * V_28 ) < 0 )
F_101 () ;
return F_102 ( V_118 -> V_134 . V_202 , V_237 , V_238 ) ;
}
static inline T_4 F_103 ( void )
{
return F_90 ( 4 )
+ F_91 ( sizeof( struct V_239 ) )
+ F_91 ( 4 ) ;
}
static int F_104 ( struct V_141 * V_142 , struct V_118 * V_118 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_240 V_207 ;
struct V_239 V_241 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_212 ;
V_144 = F_71 ( V_142 , V_151 , V_133 , V_242 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_212 = F_44 ( V_144 ) ;
* V_212 = V_28 ;
F_105 ( V_118 , & V_207 ) ;
V_241 . V_243 = V_207 . V_243 ;
V_241 . V_244 = V_207 . V_244 ;
V_38 = F_66 ( V_142 , V_245 , V_207 . V_246 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_142 , V_247 , sizeof( V_241 ) , & V_241 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_106 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_141 * V_237 ;
T_3 * V_28 = F_44 ( V_144 ) ;
T_3 V_238 = F_72 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_237 = F_83 ( F_103 () , V_199 ) ;
if ( V_237 == NULL )
return - V_69 ;
if ( F_104 ( V_237 , V_118 , V_238 , V_133 , * V_28 ) < 0 )
F_101 () ;
return F_102 ( V_118 -> V_134 . V_202 , V_237 , V_238 ) ;
}
static int F_107 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_154 * V_24 = F_44 ( V_144 ) ;
struct V_57 * V_58 ;
struct V_141 * V_248 ;
int V_38 = - V_158 ;
V_58 = F_51 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( V_58 == NULL )
goto V_249;
V_248 = F_82 ( V_142 , V_58 , V_144 -> V_150 ) ;
if ( F_108 ( V_248 ) ) {
V_38 = F_109 ( V_248 ) ;
} else {
V_38 = F_102 ( V_118 -> V_134 . V_202 , V_248 , F_72 ( V_142 ) . V_151 ) ;
}
F_41 ( V_58 ) ;
V_249:
return V_38 ;
}
static int F_110 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_250 * V_24 ;
struct V_141 * V_248 ;
T_1 * V_159 ;
int V_39 ;
int V_38 ;
T_3 V_131 ;
struct V_155 V_156 ;
V_24 = F_44 ( V_144 ) ;
V_38 = F_111 ( V_24 -> V_190 . V_33 . V_34 , V_24 -> V_251 , V_24 -> V_252 ) ;
if ( V_38 )
goto V_249;
V_39 = V_24 -> V_190 . V_39 ;
V_159 = & V_24 -> V_190 . V_33 . V_159 ;
V_58 = NULL ;
V_131 = F_37 ( V_2 , & V_156 ) ;
if ( V_24 -> V_190 . V_133 ) {
V_58 = F_112 ( V_118 , V_131 , V_24 -> V_190 . V_133 ) ;
if ( V_58 && ! F_113 ( & V_58 -> V_33 . V_159 , V_159 , V_39 ) ) {
F_41 ( V_58 ) ;
V_58 = NULL ;
}
}
if ( ! V_58 )
V_58 = F_114 ( V_118 , & V_156 , V_24 -> V_190 . V_46 , V_24 -> V_190 . V_95 ,
V_24 -> V_190 . V_33 . V_34 , V_159 ,
& V_24 -> V_190 . V_96 , 1 ,
V_39 ) ;
V_38 = - V_253 ;
if ( V_58 == NULL )
goto V_249;
V_38 = F_115 ( V_58 , V_24 -> V_251 , V_24 -> V_252 ) ;
if ( V_38 )
goto V_44;
V_248 = F_82 ( V_142 , V_58 , V_144 -> V_150 ) ;
if ( F_108 ( V_248 ) ) {
V_38 = F_109 ( V_248 ) ;
goto V_44;
}
V_38 = F_102 ( V_118 -> V_134 . V_202 , V_248 , F_72 ( V_142 ) . V_151 ) ;
V_44:
F_41 ( V_58 ) ;
V_249:
return V_38 ;
}
static int F_116 ( T_2 V_254 )
{
switch ( V_254 ) {
case V_255 :
case V_256 :
case V_257 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_117 ( T_2 type )
{
switch ( type ) {
case V_258 :
#ifdef F_118
case V_259 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_119 ( struct V_260 * V_24 )
{
int V_173 ;
switch ( V_24 -> V_261 ) {
case V_262 :
case V_263 :
case V_264 :
case V_265 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_266 ) {
case V_267 :
case V_268 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_93 . V_39 ) {
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
V_173 = F_116 ( V_24 -> V_254 ) ;
if ( V_173 )
return V_173 ;
if ( V_24 -> V_269 && ( ( V_24 -> V_269 & V_270 ) != V_24 -> V_254 ) )
return - V_7 ;
return 0 ;
}
static int F_120 ( struct V_271 * V_272 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_121 ( & V_272 -> V_177 , V_20 , V_68 ) ;
}
static void F_122 ( struct V_271 * V_273 , struct V_274 * V_275 ,
int V_276 )
{
int V_277 ;
V_273 -> V_278 = V_276 ;
for ( V_277 = 0 ; V_277 < V_276 ; V_277 ++ , V_275 ++ ) {
struct V_279 * V_280 = & V_273 -> V_281 [ V_277 ] ;
memcpy ( & V_280 -> V_33 , & V_275 -> V_33 , sizeof( struct V_282 ) ) ;
memcpy ( & V_280 -> V_96 , & V_275 -> V_96 ,
sizeof( T_1 ) ) ;
V_280 -> V_95 = V_275 -> V_95 ;
V_280 -> V_46 = V_275 -> V_46 ;
V_280 -> V_261 = V_275 -> V_261 ;
V_280 -> V_283 = V_275 -> V_283 ;
V_280 -> V_284 = V_275 -> V_284 ;
V_280 -> V_285 = V_275 -> V_285 ;
V_280 -> V_286 = V_275 -> V_286 ;
V_280 -> V_287 = ! ~ ( V_280 -> V_284 & V_280 -> V_285 & V_280 -> V_286 ) ;
V_280 -> V_288 = V_275 -> V_39 ;
}
}
static int F_123 ( int V_276 , struct V_274 * V_275 , T_5 V_39 )
{
int V_277 ;
if ( V_276 > V_289 )
return - V_7 ;
for ( V_277 = 0 ; V_277 < V_276 ; V_277 ++ ) {
if ( ! V_275 [ V_277 ] . V_39 )
V_275 [ V_277 ] . V_39 = V_39 ;
switch ( V_275 [ V_277 ] . V_39 ) {
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
static int F_124 ( struct V_271 * V_272 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_290 ] ;
if ( ! V_4 ) {
V_272 -> V_278 = 0 ;
} else {
struct V_274 * V_291 = F_2 ( V_4 ) ;
int V_276 = F_3 ( V_4 ) / sizeof( * V_291 ) ;
int V_38 ;
V_38 = F_123 ( V_276 , V_291 , V_272 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_122 ( V_272 , V_291 , V_276 ) ;
}
return 0 ;
}
static int F_125 ( T_2 * V_292 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_293 ] ;
struct V_294 * V_295 ;
T_2 type = V_258 ;
int V_38 ;
if ( V_4 ) {
V_295 = F_2 ( V_4 ) ;
type = V_295 -> type ;
}
V_38 = F_117 ( type ) ;
if ( V_38 )
return V_38 ;
* V_292 = type ;
return 0 ;
}
static void F_126 ( struct V_271 * V_273 , struct V_260 * V_24 )
{
V_273 -> V_296 = V_24 -> V_296 ;
V_273 -> V_269 = V_24 -> V_269 ;
memcpy ( & V_273 -> V_297 , & V_24 -> V_93 , sizeof( V_273 -> V_297 ) ) ;
memcpy ( & V_273 -> V_94 , & V_24 -> V_94 , sizeof( V_273 -> V_94 ) ) ;
V_273 -> V_266 = V_24 -> V_266 ;
V_273 -> V_28 = V_24 -> V_28 ;
V_273 -> V_39 = V_24 -> V_93 . V_39 ;
}
static void F_127 ( struct V_271 * V_273 , struct V_260 * V_24 , int V_254 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_93 , & V_273 -> V_297 , sizeof( V_24 -> V_93 ) ) ;
memcpy ( & V_24 -> V_94 , & V_273 -> V_94 , sizeof( V_24 -> V_94 ) ) ;
memcpy ( & V_24 -> V_111 , & V_273 -> V_111 , sizeof( V_24 -> V_111 ) ) ;
V_24 -> V_296 = V_273 -> V_296 ;
V_24 -> V_269 = V_273 -> V_269 ;
V_24 -> V_93 . V_39 = V_273 -> V_39 ;
V_24 -> V_254 = V_254 ;
V_24 -> V_266 = V_273 -> V_266 ;
V_24 -> V_28 = V_273 -> V_28 ;
V_24 -> V_261 = V_262 ;
}
static struct V_271 * F_128 ( struct V_118 * V_118 , struct V_260 * V_24 , struct V_1 * * V_2 , int * V_119 )
{
struct V_271 * V_273 = F_129 ( V_118 , V_68 ) ;
int V_38 ;
if ( ! V_273 ) {
* V_119 = - V_69 ;
return NULL ;
}
F_126 ( V_273 , V_24 ) ;
V_38 = F_125 ( & V_273 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_124 ( V_273 , V_2 ) ) )
V_38 = F_120 ( V_273 , V_2 ) ;
if ( V_38 )
goto error;
F_37 ( V_2 , & V_273 -> V_131 ) ;
return V_273 ;
error:
* V_119 = V_38 ;
V_273 -> V_188 . V_298 = 1 ;
F_130 ( V_273 ) ;
return NULL ;
}
static int F_131 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_260 * V_24 = F_44 ( V_144 ) ;
struct V_271 * V_273 ;
struct V_146 V_147 ;
int V_38 ;
int V_299 ;
V_38 = F_119 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_273 = F_128 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( ! V_273 )
return V_38 ;
V_299 = V_144 -> V_148 == V_300 ;
V_38 = F_132 ( V_24 -> V_254 , V_273 , V_299 ) ;
F_133 ( V_273 , V_38 ? 0 : 1 , true ) ;
if ( V_38 ) {
F_134 ( V_273 -> V_177 ) ;
F_28 ( V_273 ) ;
return V_38 ;
}
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_135 ( V_273 , V_24 -> V_254 , & V_147 ) ;
F_136 ( V_273 ) ;
return 0 ;
}
static int F_137 ( struct V_271 * V_273 , struct V_141 * V_142 )
{
struct V_274 V_301 [ V_289 ] ;
int V_277 ;
if ( V_273 -> V_278 == 0 )
return 0 ;
for ( V_277 = 0 ; V_277 < V_273 -> V_278 ; V_277 ++ ) {
struct V_274 * V_86 = & V_301 [ V_277 ] ;
struct V_279 * V_302 = & V_273 -> V_281 [ V_277 ] ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
memcpy ( & V_86 -> V_33 , & V_302 -> V_33 , sizeof( V_86 -> V_33 ) ) ;
V_86 -> V_39 = V_302 -> V_288 ;
memcpy ( & V_86 -> V_96 , & V_302 -> V_96 , sizeof( V_86 -> V_96 ) ) ;
V_86 -> V_95 = V_302 -> V_95 ;
V_86 -> V_46 = V_302 -> V_46 ;
V_86 -> V_261 = V_302 -> V_261 ;
V_86 -> V_283 = V_302 -> V_283 ;
V_86 -> V_284 = V_302 -> V_284 ;
V_86 -> V_285 = V_302 -> V_285 ;
V_86 -> V_286 = V_302 -> V_286 ;
}
return F_67 ( V_142 , V_290 ,
sizeof( struct V_274 ) * V_273 -> V_278 , V_301 ) ;
}
static inline int F_138 ( struct V_57 * V_58 , struct V_141 * V_142 )
{
if ( V_58 -> V_177 ) {
return F_62 ( V_58 -> V_177 , V_142 ) ;
}
return 0 ;
}
static inline int F_139 ( struct V_271 * V_273 , struct V_141 * V_142 )
{
if ( V_273 -> V_177 )
return F_62 ( V_273 -> V_177 , V_142 ) ;
return 0 ;
}
static inline T_4 F_140 ( void )
{
#ifdef F_118
return F_91 ( sizeof( struct V_294 ) ) ;
#else
return 0 ;
#endif
}
static int F_141 ( T_2 type , struct V_141 * V_142 )
{
struct V_294 V_295 = {
. type = type ,
} ;
return F_67 ( V_142 , V_293 , sizeof( V_295 ) , & V_295 ) ;
}
static inline int F_141 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_142 ( struct V_271 * V_273 , int V_254 , int V_178 , void * V_179 )
{
struct V_180 * V_181 = V_179 ;
struct V_260 * V_24 ;
struct V_141 * V_182 = V_181 -> V_182 ;
struct V_141 * V_142 = V_181 -> V_183 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , F_72 ( V_182 ) . V_151 , V_181 -> V_150 ,
V_300 , sizeof( * V_24 ) , V_181 -> V_184 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_24 = F_44 ( V_144 ) ;
F_127 ( V_273 , V_24 , V_254 ) ;
V_38 = F_137 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_139 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_273 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_273 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_143 ( struct V_185 * V_186 )
{
struct V_303 * V_188 = (struct V_303 * ) & V_186 -> args [ 1 ] ;
struct V_118 * V_118 = F_43 ( V_186 -> V_142 -> V_145 ) ;
F_144 ( V_188 , V_118 ) ;
return 0 ;
}
static int F_145 ( struct V_141 * V_142 , struct V_185 * V_186 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_303 * V_188 = (struct V_303 * ) & V_186 -> args [ 1 ] ;
struct V_180 V_190 ;
F_78 ( sizeof( struct V_303 ) >
sizeof( V_186 -> args ) - sizeof( V_186 -> args [ 0 ] ) ) ;
V_190 . V_182 = V_186 -> V_142 ;
V_190 . V_183 = V_142 ;
V_190 . V_150 = V_186 -> V_144 -> V_150 ;
V_190 . V_184 = V_191 ;
if ( ! V_186 -> args [ 0 ] ) {
V_186 -> args [ 0 ] = 1 ;
F_146 ( V_188 , V_304 ) ;
}
( void ) V_303 ( V_118 , V_188 , F_142 , & V_190 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_147 ( struct V_141 * V_182 ,
struct V_271 * V_273 ,
int V_254 , T_3 V_133 )
{
struct V_180 V_190 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( V_198 , V_68 ) ;
if ( ! V_142 )
return F_84 ( - V_69 ) ;
V_190 . V_182 = V_182 ;
V_190 . V_183 = V_142 ;
V_190 . V_150 = V_133 ;
V_190 . V_184 = 0 ;
V_38 = F_142 ( V_273 , V_254 , 0 , & V_190 ) ;
if ( V_38 ) {
F_85 ( V_142 ) ;
return F_84 ( V_38 ) ;
}
return V_142 ;
}
static int F_148 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_271 * V_273 ;
struct V_305 * V_24 ;
T_2 type = V_258 ;
int V_38 ;
struct V_146 V_147 ;
int V_306 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_24 = F_44 ( V_144 ) ;
V_306 = V_144 -> V_148 == V_307 ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_116 ( V_24 -> V_254 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_269 )
V_273 = F_149 ( V_118 , V_131 , type , V_24 -> V_254 , V_24 -> V_269 , V_306 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_91 * V_308 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_308 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_121 ( & V_308 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_273 = F_150 ( V_118 , V_131 , type , V_24 -> V_254 , & V_24 -> V_93 ,
V_308 , V_306 , & V_38 ) ;
F_134 ( V_308 ) ;
}
if ( V_273 == NULL )
return - V_253 ;
if ( ! V_306 ) {
struct V_141 * V_248 ;
V_248 = F_147 ( V_142 , V_273 , V_24 -> V_254 , V_144 -> V_150 ) ;
if ( F_108 ( V_248 ) ) {
V_38 = F_109 ( V_248 ) ;
} else {
V_38 = F_102 ( V_118 -> V_134 . V_202 , V_248 ,
F_72 ( V_142 ) . V_151 ) ;
}
} else {
F_151 ( V_273 , V_38 ? 0 : 1 , true ) ;
if ( V_38 != 0 )
goto V_44;
V_147 . V_309 . V_310 = V_24 -> V_269 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_135 ( V_273 , V_24 -> V_254 , & V_147 ) ;
}
V_44:
F_136 ( V_273 ) ;
if ( V_306 && V_38 == 0 )
F_152 ( V_118 ) ;
return V_38 ;
}
static int F_153 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_311 * V_24 = F_44 ( V_144 ) ;
int V_38 ;
V_38 = F_154 ( V_118 , V_24 -> V_34 , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_309 . V_34 = V_24 -> V_34 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_118 = V_118 ;
F_50 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_4 F_155 ( struct V_57 * V_58 )
{
T_4 V_312 = V_58 -> V_84 ?
F_12 ( V_58 -> V_84 ) :
sizeof( struct V_106 ) ;
return F_90 ( sizeof( struct V_313 ) )
+ F_91 ( V_312 )
+ F_156 ( sizeof( struct V_109 ) )
+ F_91 ( sizeof( struct V_155 ) )
+ F_91 ( 4 )
+ F_91 ( 4 ) ;
}
static int F_157 ( struct V_141 * V_142 , struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_313 * V_33 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_314 , sizeof( * V_33 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_33 = F_44 ( V_144 ) ;
memcpy ( & V_33 -> V_315 . V_159 , & V_58 -> V_33 . V_159 , sizeof( V_58 -> V_33 . V_159 ) ) ;
V_33 -> V_315 . V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_315 . V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_315 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_58 -> V_64 . V_96 ) ) ;
V_33 -> V_95 = V_58 -> V_64 . V_95 ;
V_33 -> V_28 = V_147 -> V_309 . V_316 ;
if ( V_58 -> V_84 ) {
V_38 = F_67 ( V_142 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
} else {
V_38 = F_67 ( V_142 , V_99 , sizeof( V_58 -> V_107 ) ,
& V_58 -> V_107 ) ;
}
if ( V_38 )
goto V_317;
V_38 = F_158 ( V_142 , V_102 , sizeof( V_58 -> V_111 ) , & V_58 -> V_111 ,
V_176 ) ;
if ( V_38 )
goto V_317;
if ( V_33 -> V_28 & V_318 ) {
V_38 = F_66 ( V_142 , V_105 , V_58 -> V_117 ) ;
if ( V_38 )
goto V_317;
}
if ( V_33 -> V_28 & V_319 ) {
V_38 = F_66 ( V_142 , V_104 ,
V_58 -> V_116 * 10 / V_137 ) ;
if ( V_38 )
goto V_317;
}
V_38 = F_69 ( V_142 , & V_58 -> V_131 ) ;
if ( V_38 )
goto V_317;
F_74 ( V_142 , V_144 ) ;
return 0 ;
V_317:
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_159 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_141 * V_237 ;
int V_38 ;
struct V_146 V_147 ;
T_3 V_131 ;
struct V_155 V_156 ;
struct V_313 * V_24 = F_44 ( V_144 ) ;
struct V_154 * V_33 = & V_24 -> V_315 ;
V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_33 -> V_159 , V_33 -> V_49 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_58 == NULL )
return - V_158 ;
V_237 = F_83 ( F_155 ( V_58 ) , V_199 ) ;
if ( V_237 == NULL ) {
F_41 ( V_58 ) ;
return - V_69 ;
}
F_160 ( & V_58 -> V_224 ) ;
V_147 . V_309 . V_316 = V_24 -> V_28 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
if ( F_157 ( V_237 , V_58 , & V_147 ) < 0 )
F_101 () ;
V_38 = F_102 ( V_118 -> V_134 . V_202 , V_237 , F_72 ( V_142 ) . V_151 ) ;
F_161 ( & V_58 -> V_224 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_162 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_146 V_147 ;
int V_38 = - V_7 ;
T_3 V_131 = 0 ;
struct V_155 V_156 ;
struct V_313 * V_24 = F_44 ( V_144 ) ;
struct V_1 * V_85 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_2 [ V_25 ] ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
struct V_1 * V_103 = V_2 [ V_104 ] ;
struct V_1 * V_4 = V_2 [ V_105 ] ;
if ( ! V_101 && ! V_85 && ! V_100 && ! V_103 && ! V_4 )
return V_38 ;
if ( ! ( V_144 -> V_184 & V_320 ) )
return V_38 ;
V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_24 -> V_315 . V_159 , V_24 -> V_315 . V_49 , V_24 -> V_315 . V_34 , V_24 -> V_315 . V_39 ) ;
if ( V_58 == NULL )
return - V_158 ;
if ( V_58 -> V_132 . V_139 != V_321 )
goto V_44;
V_38 = F_25 ( V_58 -> V_84 , V_100 ) ;
if ( V_38 )
goto V_44;
F_160 ( & V_58 -> V_224 ) ;
F_32 ( V_58 , V_2 , 1 ) ;
F_161 ( & V_58 -> V_224 ) ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_309 . V_316 = V_322 ;
F_50 ( V_58 , & V_147 ) ;
V_38 = 0 ;
V_44:
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_163 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
T_2 type = V_258 ;
int V_38 ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_164 ( V_118 , type , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_309 . type = type ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_118 = V_118 ;
F_135 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_165 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_271 * V_273 ;
struct V_323 * V_86 = F_44 ( V_144 ) ;
struct V_260 * V_24 = & V_86 -> V_272 ;
T_2 type = V_258 ;
int V_38 = - V_253 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_116 ( V_24 -> V_254 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_269 )
V_273 = F_149 ( V_118 , V_131 , type , V_24 -> V_254 , V_24 -> V_269 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_91 * V_308 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_308 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_121 ( & V_308 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_273 = F_150 ( V_118 , V_131 , type , V_24 -> V_254 ,
& V_24 -> V_93 , V_308 , 0 , & V_38 ) ;
F_134 ( V_308 ) ;
}
if ( V_273 == NULL )
return - V_253 ;
if ( F_166 ( V_273 -> V_188 . V_298 ) )
goto V_44;
V_38 = 0 ;
if ( V_86 -> V_324 ) {
F_167 ( V_273 , V_24 -> V_254 ) ;
F_151 ( V_273 , 1 , true ) ;
}
F_168 ( V_273 , V_24 -> V_254 , V_86 -> V_324 , V_144 -> V_152 ) ;
V_44:
F_136 ( V_273 ) ;
return V_38 ;
}
static int F_169 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
int V_38 ;
struct V_325 * V_326 = F_44 ( V_144 ) ;
struct V_23 * V_24 = & V_326 -> V_139 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_24 -> V_33 . V_159 , V_24 -> V_33 . V_49 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_253 ;
if ( V_58 == NULL )
return V_38 ;
F_160 ( & V_58 -> V_224 ) ;
V_38 = - V_7 ;
if ( V_58 -> V_132 . V_139 != V_321 )
goto V_44;
F_170 ( V_58 , V_326 -> V_324 , V_144 -> V_152 ) ;
if ( V_326 -> V_324 ) {
F_171 ( V_58 ) ;
F_59 ( V_58 , 1 , true ) ;
}
V_38 = 0 ;
V_44:
F_161 ( & V_58 -> V_224 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_172 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_271 * V_273 ;
struct V_274 * V_275 ;
int V_277 ;
struct V_1 * V_4 = V_2 [ V_290 ] ;
struct V_155 V_131 ;
struct V_327 * V_328 = F_44 ( V_144 ) ;
struct V_57 * V_58 = F_35 ( V_118 ) ;
int V_38 = - V_69 ;
if ( ! V_58 )
goto V_329;
F_37 ( V_2 , & V_131 ) ;
V_38 = F_119 ( & V_328 -> V_330 ) ;
if ( V_38 )
goto V_331;
V_273 = F_128 ( V_118 , & V_328 -> V_330 , V_2 , & V_38 ) ;
if ( ! V_273 )
goto V_331;
memcpy ( & V_58 -> V_33 , & V_328 -> V_33 , sizeof( V_328 -> V_33 ) ) ;
memcpy ( & V_58 -> V_64 . V_96 , & V_328 -> V_96 , sizeof( V_328 -> V_96 ) ) ;
memcpy ( & V_58 -> V_93 , & V_328 -> V_93 , sizeof( V_328 -> V_93 ) ) ;
V_273 -> V_131 . V_156 = V_58 -> V_131 . V_156 = V_131 . V_156 ;
V_273 -> V_131 . V_332 = V_58 -> V_131 . V_332 = V_131 . V_332 ;
V_275 = F_2 ( V_4 ) ;
for ( V_277 = 0 ; V_277 < V_273 -> V_278 ; V_277 ++ , V_275 ++ ) {
struct V_279 * V_280 = & V_273 -> V_281 [ V_277 ] ;
memcpy ( & V_58 -> V_33 , & V_280 -> V_33 , sizeof( V_58 -> V_33 ) ) ;
V_58 -> V_64 . V_46 = V_280 -> V_46 ;
V_58 -> V_64 . V_95 = V_280 -> V_95 ;
V_58 -> V_64 . V_39 = V_275 -> V_39 ;
V_280 -> V_284 = V_328 -> V_284 ;
V_280 -> V_285 = V_328 -> V_285 ;
V_280 -> V_286 = V_328 -> V_286 ;
V_38 = F_173 ( V_58 , V_280 , V_273 ) ;
}
F_28 ( V_58 ) ;
F_28 ( V_273 ) ;
return 0 ;
V_331:
F_28 ( V_58 ) ;
V_329:
return V_38 ;
}
static int F_174 ( struct V_333 * V_334 ,
struct V_335 * V_336 ,
struct V_1 * * V_2 , int * V_337 )
{
struct V_1 * V_4 = V_2 [ V_338 ] ;
struct V_339 * V_340 ;
int V_277 , V_341 ;
if ( V_336 != NULL ) {
struct V_342 * V_343 ;
V_343 = F_2 ( V_2 [ V_344 ] ) ;
memcpy ( & V_336 -> V_345 , & V_343 -> V_345 , sizeof( V_336 -> V_345 ) ) ;
memcpy ( & V_336 -> V_346 , & V_343 -> V_346 , sizeof( V_336 -> V_346 ) ) ;
V_336 -> V_39 = V_343 -> V_39 ;
V_336 -> V_347 = V_343 -> V_347 ;
}
V_340 = F_2 ( V_4 ) ;
V_341 = F_3 ( V_4 ) / sizeof( * V_340 ) ;
if ( V_341 <= 0 || V_341 > V_289 )
return - V_7 ;
for ( V_277 = 0 ; V_277 < V_341 ; V_277 ++ , V_340 ++ , V_334 ++ ) {
memcpy ( & V_334 -> V_348 , & V_340 -> V_348 , sizeof( V_334 -> V_348 ) ) ;
memcpy ( & V_334 -> V_349 , & V_340 -> V_349 , sizeof( V_334 -> V_349 ) ) ;
memcpy ( & V_334 -> V_350 , & V_340 -> V_350 , sizeof( V_334 -> V_350 ) ) ;
memcpy ( & V_334 -> V_351 , & V_340 -> V_351 , sizeof( V_334 -> V_351 ) ) ;
V_334 -> V_34 = V_340 -> V_34 ;
V_334 -> V_46 = V_340 -> V_46 ;
V_334 -> V_95 = V_340 -> V_95 ;
V_334 -> V_352 = V_340 -> V_352 ;
V_334 -> V_353 = V_340 -> V_353 ;
}
* V_337 = V_277 ;
return 0 ;
}
static int F_175 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_305 * V_354 = F_44 ( V_144 ) ;
struct V_333 V_156 [ V_289 ] ;
struct V_335 V_132 , * V_355 ;
T_2 type ;
int V_38 ;
int V_356 = 0 ;
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
if ( V_2 [ V_338 ] == NULL )
return - V_7 ;
V_355 = V_2 [ V_344 ] ? & V_132 : NULL ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_174 ( (struct V_333 * ) V_156 , V_355 , V_2 , & V_356 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_356 )
return 0 ;
V_333 ( & V_354 -> V_93 , V_354 -> V_254 , type , V_156 , V_356 , V_355 , V_118 ) ;
return 0 ;
}
static int F_175 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
return - V_357 ;
}
static int F_176 ( const struct V_333 * V_156 , struct V_141 * V_142 )
{
struct V_339 V_340 ;
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . V_34 = V_156 -> V_34 ;
V_340 . V_46 = V_156 -> V_46 ;
V_340 . V_95 = V_156 -> V_95 ;
V_340 . V_352 = V_156 -> V_352 ;
memcpy ( & V_340 . V_348 , & V_156 -> V_348 , sizeof( V_340 . V_348 ) ) ;
memcpy ( & V_340 . V_349 , & V_156 -> V_349 , sizeof( V_340 . V_349 ) ) ;
V_340 . V_353 = V_156 -> V_353 ;
memcpy ( & V_340 . V_350 , & V_156 -> V_350 , sizeof( V_340 . V_350 ) ) ;
memcpy ( & V_340 . V_351 , & V_156 -> V_351 , sizeof( V_340 . V_351 ) ) ;
return F_67 ( V_142 , V_338 , sizeof( V_340 ) , & V_340 ) ;
}
static int F_177 ( const struct V_335 * V_336 , struct V_141 * V_142 )
{
struct V_342 V_343 ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_343 . V_39 = V_336 -> V_39 ;
V_343 . V_347 = V_336 -> V_347 ;
memcpy ( & V_343 . V_345 , & V_336 -> V_345 , sizeof( V_343 . V_345 ) ) ;
memcpy ( & V_343 . V_346 , & V_336 -> V_346 , sizeof( V_343 . V_346 ) ) ;
return F_67 ( V_142 , V_344 , sizeof( V_343 ) , & V_343 ) ;
}
static inline T_4 F_178 ( int V_341 , int V_358 )
{
return F_90 ( sizeof( struct V_305 ) )
+ ( V_358 ? F_91 ( sizeof( struct V_335 ) ) : 0 )
+ F_91 ( sizeof( struct V_339 ) * V_341 )
+ F_140 () ;
}
static int F_179 ( struct V_141 * V_142 , const struct V_333 * V_156 ,
int V_341 , const struct V_335 * V_336 ,
const struct V_359 * V_93 , T_2 V_254 , T_2 type )
{
const struct V_333 * V_360 ;
struct V_305 * V_361 ;
struct V_143 * V_144 ;
int V_277 , V_38 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_362 , sizeof( * V_361 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_361 = F_44 ( V_144 ) ;
memset ( V_361 , 0 , sizeof( * V_361 ) ) ;
memcpy ( & V_361 -> V_93 , V_93 , sizeof( V_361 -> V_93 ) ) ;
V_361 -> V_254 = V_254 ;
if ( V_336 != NULL ) {
V_38 = F_177 ( V_336 , V_142 ) ;
if ( V_38 )
goto V_317;
}
V_38 = F_141 ( type , V_142 ) ;
if ( V_38 )
goto V_317;
for ( V_277 = 0 , V_360 = V_156 ; V_277 < V_341 ; V_277 ++ , V_360 ++ ) {
V_38 = F_176 ( V_360 , V_142 ) ;
if ( V_38 )
goto V_317;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
V_317:
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_180 ( const struct V_359 * V_93 , T_2 V_254 , T_2 type ,
const struct V_333 * V_156 , int V_341 ,
const struct V_335 * V_336 )
{
struct V_118 * V_118 = & V_363 ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_178 ( V_341 , ! ! V_336 ) , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_179 ( V_142 , V_156 , V_341 , V_336 , V_93 , V_254 , type ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_364 ) ;
}
static int F_180 ( const struct V_359 * V_93 , T_2 V_254 , T_2 type ,
const struct V_333 * V_156 , int V_341 ,
const struct V_335 * V_336 )
{
return - V_357 ;
}
static int F_181 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_1 * V_2 [ V_192 + 1 ] ;
const struct V_365 * V_366 ;
int type , V_38 ;
#ifdef F_182
if ( F_183 () )
return - V_367 ;
#endif
type = V_144 -> V_148 ;
if ( type > V_368 )
return - V_7 ;
type -= V_369 ;
V_366 = & V_370 [ type ] ;
if ( ! F_184 ( V_142 , V_371 ) )
return - V_161 ;
if ( ( type == ( V_372 - V_369 ) ||
type == ( V_373 - V_369 ) ) &&
( V_144 -> V_184 & V_374 ) ) {
if ( V_366 -> V_375 == NULL )
return - V_7 ;
{
struct V_376 V_147 = {
. V_375 = V_366 -> V_375 ,
. V_377 = V_366 -> V_377 ,
} ;
return F_185 ( V_118 -> V_134 . V_202 , V_142 , V_144 , & V_147 ) ;
}
}
V_38 = F_79 ( V_144 , V_378 [ type ] , V_2 ,
V_366 -> V_379 ? : V_192 ,
V_366 -> V_380 ? : V_195 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_366 -> V_381 == NULL )
return - V_7 ;
return V_366 -> V_381 ( V_142 , V_144 , V_2 ) ;
}
static void F_186 ( struct V_141 * V_142 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
F_187 ( & V_118 -> V_134 . V_382 ) ;
F_188 ( V_142 , & F_181 ) ;
F_189 ( & V_118 -> V_134 . V_382 ) ;
}
static inline T_4 F_190 ( void )
{
return F_90 ( sizeof( struct V_325 ) )
+ F_91 ( sizeof( struct V_155 ) ) ;
}
static int F_191 ( struct V_141 * V_142 , struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_325 * V_326 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , 0 , V_383 , sizeof( * V_326 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_326 = F_44 ( V_144 ) ;
F_60 ( V_58 , & V_326 -> V_139 ) ;
V_326 -> V_324 = ( V_147 -> V_309 . V_324 != 0 ) ? 1 : 0 ;
V_38 = F_69 ( V_142 , & V_58 -> V_131 ) ;
if ( V_38 )
return V_38 ;
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_192 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_193 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_190 () , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_191 ( V_142 , V_58 , V_147 ) < 0 ) {
F_85 ( V_142 ) ;
return - V_167 ;
}
return F_86 ( V_118 , V_142 , 0 , V_384 ) ;
}
static int F_194 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_193 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_155 ( V_58 ) , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_157 ( V_142 , V_58 , V_147 ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_385 ) ;
}
static int F_195 ( const struct V_146 * V_147 )
{
struct V_118 * V_118 = V_147 -> V_118 ;
struct V_311 * V_24 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_90 ( sizeof( struct V_311 ) ) ;
V_142 = F_83 ( V_21 , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_386 , sizeof( * V_24 ) , 0 ) ;
if ( V_144 == NULL ) {
F_85 ( V_142 ) ;
return - V_167 ;
}
V_24 = F_44 ( V_144 ) ;
V_24 -> V_34 = V_147 -> V_309 . V_34 ;
F_74 ( V_142 , V_144 ) ;
return F_86 ( V_118 , V_142 , 0 , V_387 ) ;
}
static inline T_4 F_196 ( struct V_57 * V_58 )
{
T_4 V_388 = 0 ;
if ( V_58 -> V_83 )
V_388 += F_91 ( F_8 ( V_58 -> V_83 ) ) ;
if ( V_58 -> V_123 ) {
V_388 += F_91 ( sizeof( struct V_5 ) +
( V_58 -> V_123 -> V_76 + 7 ) / 8 ) ;
V_388 += F_91 ( F_6 ( V_58 -> V_123 ) ) ;
}
if ( V_58 -> V_71 )
V_388 += F_91 ( F_4 ( V_58 -> V_71 ) ) ;
if ( V_58 -> V_125 )
V_388 += F_91 ( sizeof( * V_58 -> V_125 ) ) ;
if ( V_58 -> V_128 )
V_388 += F_91 ( sizeof( * V_58 -> V_128 ) ) ;
if ( V_58 -> V_129 )
V_388 += F_91 ( sizeof( V_58 -> V_129 ) ) ;
if ( V_58 -> V_84 )
V_388 += F_91 ( F_12 ( V_58 -> V_84 ) ) ;
else
V_388 += F_91 ( sizeof( struct V_106 ) ) ;
if ( V_58 -> V_177 )
V_388 += F_91 ( sizeof( struct V_19 ) +
V_58 -> V_177 -> V_22 ) ;
if ( V_58 -> V_130 )
V_388 += F_91 ( sizeof( * V_58 -> V_130 ) ) ;
if ( V_58 -> V_64 . V_122 )
V_388 += F_91 ( sizeof( V_58 -> V_64 . V_122 ) ) ;
V_388 += F_156 ( sizeof( V_389 ) ) ;
return V_388 ;
}
static int F_197 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_193 ( V_58 ) ;
struct V_23 * V_24 ;
struct V_154 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_196 ( V_58 ) ;
int V_390 , V_38 ;
V_390 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_391 ) {
V_21 += F_91 ( V_390 ) ;
V_390 = sizeof( * V_33 ) ;
V_21 += F_91 ( sizeof( struct V_155 ) ) ;
}
V_21 += F_90 ( V_390 ) ;
V_142 = F_83 ( V_21 , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_390 , 0 ) ;
V_38 = - V_167 ;
if ( V_144 == NULL )
goto V_392;
V_24 = F_44 ( V_144 ) ;
if ( V_147 -> V_153 == V_391 ) {
struct V_1 * V_165 ;
V_33 = F_44 ( V_144 ) ;
memcpy ( & V_33 -> V_159 , & V_58 -> V_33 . V_159 , sizeof( V_33 -> V_159 ) ) ;
V_33 -> V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_34 = V_58 -> V_33 . V_34 ;
V_165 = F_63 ( V_142 , V_393 , sizeof( * V_24 ) ) ;
V_38 = - V_167 ;
if ( V_165 == NULL )
goto V_392;
V_24 = F_2 ( V_165 ) ;
}
V_38 = F_65 ( V_58 , V_24 , V_142 ) ;
if ( V_38 )
goto V_392;
F_74 ( V_142 , V_144 ) ;
return F_86 ( V_118 , V_142 , 0 , V_387 ) ;
V_392:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_198 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_383 :
return F_192 ( V_58 , V_147 ) ;
case V_314 :
return F_194 ( V_58 , V_147 ) ;
case V_391 :
case V_394 :
case V_149 :
return F_197 ( V_58 , V_147 ) ;
case V_386 :
return F_195 ( V_147 ) ;
default:
F_199 ( V_395 L_1 ,
V_147 -> V_153 ) ;
break;
}
return 0 ;
}
static inline T_4 F_200 ( struct V_57 * V_58 ,
struct V_271 * V_273 )
{
return F_90 ( sizeof( struct V_327 ) )
+ F_91 ( sizeof( struct V_274 ) * V_273 -> V_278 )
+ F_91 ( sizeof( struct V_155 ) )
+ F_91 ( F_29 ( V_58 -> V_177 ) )
+ F_140 () ;
}
static int F_201 ( struct V_141 * V_142 , struct V_57 * V_58 ,
struct V_279 * V_396 , struct V_271 * V_273 )
{
T_6 V_133 = F_202 () ;
struct V_327 * V_328 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_397 , sizeof( * V_328 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_328 = F_44 ( V_144 ) ;
memcpy ( & V_328 -> V_33 , & V_58 -> V_33 , sizeof( V_328 -> V_33 ) ) ;
memcpy ( & V_328 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_328 -> V_96 ) ) ;
memcpy ( & V_328 -> V_93 , & V_58 -> V_93 , sizeof( V_328 -> V_93 ) ) ;
F_127 ( V_273 , & V_328 -> V_330 , V_256 ) ;
V_328 -> V_284 = V_396 -> V_284 ;
V_328 -> V_285 = V_396 -> V_285 ;
V_328 -> V_286 = V_396 -> V_286 ;
V_328 -> V_133 = V_58 -> V_132 . V_133 = V_133 ;
V_38 = F_137 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_58 , V_142 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_273 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_273 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_203 ( struct V_57 * V_58 , struct V_279 * V_396 ,
struct V_271 * V_273 )
{
struct V_118 * V_118 = F_193 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_200 ( V_58 , V_273 ) , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_201 ( V_142 , V_58 , V_396 , V_273 ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_398 ) ;
}
static struct V_271 * F_204 ( struct V_189 * V_145 , int V_399 ,
T_2 * V_309 , int V_21 , int * V_254 )
{
struct V_118 * V_118 = F_43 ( V_145 ) ;
struct V_260 * V_24 = (struct V_260 * ) V_309 ;
struct V_274 * V_275 = (struct V_274 * ) ( V_24 + 1 ) ;
struct V_271 * V_273 ;
int V_276 ;
switch ( V_145 -> V_400 ) {
case V_40 :
if ( V_399 != V_401 ) {
* V_254 = - V_402 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_399 != V_403 ) {
* V_254 = - V_402 ;
return NULL ;
}
break;
#endif
default:
* V_254 = - V_7 ;
return NULL ;
}
* V_254 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_119 ( V_24 ) )
return NULL ;
V_276 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_275 ) ) ;
if ( F_123 ( V_276 , V_275 , V_24 -> V_93 . V_39 ) )
return NULL ;
if ( V_24 -> V_254 > V_256 )
return NULL ;
V_273 = F_129 ( V_118 , V_199 ) ;
if ( V_273 == NULL ) {
* V_254 = - V_404 ;
return NULL ;
}
F_126 ( V_273 , V_24 ) ;
V_273 -> type = V_258 ;
F_122 ( V_273 , V_275 , V_276 ) ;
* V_254 = V_24 -> V_254 ;
return V_273 ;
}
static inline T_4 F_205 ( struct V_271 * V_273 )
{
return F_90 ( sizeof( struct V_323 ) )
+ F_91 ( sizeof( struct V_274 ) * V_273 -> V_278 )
+ F_91 ( F_29 ( V_273 -> V_177 ) )
+ F_91 ( sizeof( struct V_155 ) )
+ F_140 () ;
}
static int F_206 ( struct V_141 * V_142 , struct V_271 * V_273 ,
int V_254 , const struct V_146 * V_147 )
{
struct V_323 * V_405 ;
int V_324 = V_147 -> V_309 . V_324 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , 0 , V_406 , sizeof( * V_405 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_405 = F_44 ( V_144 ) ;
F_127 ( V_273 , & V_405 -> V_272 , V_254 ) ;
V_38 = F_137 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_139 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_273 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_273 -> V_131 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
V_405 -> V_324 = ! ! V_324 ;
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_207 ( struct V_271 * V_273 , int V_254 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_208 ( V_273 ) ;
struct V_141 * V_142 ;
V_142 = F_83 ( F_205 ( V_273 ) , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_206 ( V_142 , V_273 , V_254 , V_147 ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_384 ) ;
}
static int F_209 ( struct V_271 * V_273 , int V_254 , const struct V_146 * V_147 )
{
int V_21 = F_91 ( sizeof( struct V_274 ) * V_273 -> V_278 ) ;
struct V_118 * V_118 = F_208 ( V_273 ) ;
struct V_260 * V_24 ;
struct V_305 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_390 , V_38 ;
V_390 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_307 ) {
V_21 += F_91 ( V_390 ) ;
V_390 = sizeof( * V_33 ) ;
}
V_21 += F_140 () ;
V_21 += F_91 ( sizeof( struct V_155 ) ) ;
V_21 += F_90 ( V_390 ) ;
V_142 = F_83 ( V_21 , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_390 , 0 ) ;
V_38 = - V_167 ;
if ( V_144 == NULL )
goto V_392;
V_24 = F_44 ( V_144 ) ;
if ( V_147 -> V_153 == V_307 ) {
struct V_1 * V_165 ;
V_33 = F_44 ( V_144 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_254 = V_254 ;
if ( V_147 -> V_309 . V_310 )
V_33 -> V_269 = V_273 -> V_269 ;
else
memcpy ( & V_33 -> V_93 , & V_273 -> V_297 , sizeof( V_33 -> V_93 ) ) ;
V_165 = F_63 ( V_142 , V_407 , sizeof( * V_24 ) ) ;
V_38 = - V_167 ;
if ( V_165 == NULL )
goto V_392;
V_24 = F_2 ( V_165 ) ;
}
F_127 ( V_273 , V_24 , V_254 ) ;
V_38 = F_137 ( V_273 , V_142 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_273 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_142 , & V_273 -> V_131 ) ;
if ( V_38 )
goto V_392;
F_74 ( V_142 , V_144 ) ;
return F_86 ( V_118 , V_142 , 0 , V_408 ) ;
V_392:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_210 ( const struct V_146 * V_147 )
{
struct V_118 * V_118 = V_147 -> V_118 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_83 ( F_140 () , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_71 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_409 , 0 , 0 ) ;
V_38 = - V_167 ;
if ( V_144 == NULL )
goto V_392;
V_38 = F_141 ( V_147 -> V_309 . type , V_142 ) ;
if ( V_38 )
goto V_392;
F_74 ( V_142 , V_144 ) ;
return F_86 ( V_118 , V_142 , 0 , V_408 ) ;
V_392:
F_85 ( V_142 ) ;
return V_38 ;
}
static int F_211 ( struct V_271 * V_273 , int V_254 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_300 :
case V_410 :
case V_307 :
return F_209 ( V_273 , V_254 , V_147 ) ;
case V_409 :
return F_210 ( V_147 ) ;
case V_406 :
return F_207 ( V_273 , V_254 , V_147 ) ;
default:
F_199 ( V_395 L_2 ,
V_147 -> V_153 ) ;
}
return 0 ;
}
static inline T_4 F_212 ( void )
{
return F_90 ( sizeof( struct V_411 ) ) ;
}
static int F_213 ( struct V_141 * V_142 , T_2 V_34 ,
struct V_359 * V_93 , T_1 * V_412 )
{
struct V_411 * V_413 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_414 , sizeof( * V_413 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_413 = F_44 ( V_144 ) ;
V_413 -> V_34 = V_34 ;
memcpy ( & V_413 -> V_93 , V_93 , sizeof( V_413 -> V_93 ) ) ;
if ( V_412 ) {
int V_38 = F_67 ( V_142 , V_53 , sizeof( * V_412 ) , V_412 ) ;
if ( V_38 ) {
F_73 ( V_142 , V_144 ) ;
return V_38 ;
}
}
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_214 ( struct V_118 * V_118 , T_2 V_34 ,
struct V_359 * V_93 , T_1 * V_412 )
{
struct V_141 * V_142 ;
V_142 = F_83 ( F_212 () , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_213 ( V_142 , V_34 , V_93 , V_412 ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_415 ) ;
}
static inline T_4 F_215 ( void )
{
return F_90 ( sizeof( struct V_416 ) ) ;
}
static int F_216 ( struct V_141 * V_142 , struct V_57 * V_58 ,
T_1 * V_351 , T_7 V_417 )
{
struct V_416 * V_340 ;
struct V_143 * V_144 ;
V_144 = F_71 ( V_142 , 0 , 0 , V_418 , sizeof( * V_340 ) , 0 ) ;
if ( V_144 == NULL )
return - V_167 ;
V_340 = F_44 ( V_144 ) ;
memcpy ( & V_340 -> V_33 . V_159 , & V_58 -> V_33 . V_159 , sizeof( V_340 -> V_33 . V_159 ) ) ;
V_340 -> V_33 . V_49 = V_58 -> V_33 . V_49 ;
V_340 -> V_33 . V_39 = V_58 -> V_64 . V_39 ;
V_340 -> V_33 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_340 -> V_351 , V_351 , sizeof( V_340 -> V_351 ) ) ;
memcpy ( & V_340 -> V_349 , & V_58 -> V_64 . V_96 , sizeof( V_340 -> V_349 ) ) ;
V_340 -> V_417 = V_417 ;
V_340 -> V_419 = V_58 -> V_128 -> V_420 ;
V_340 -> V_95 = V_58 -> V_64 . V_95 ;
F_74 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_217 ( struct V_57 * V_58 , T_1 * V_421 ,
T_7 V_422 )
{
struct V_118 * V_118 = F_193 ( V_58 ) ;
struct V_141 * V_142 ;
if ( V_58 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_58 -> V_128 )
return - V_7 ;
V_142 = F_83 ( F_215 () , V_199 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_216 ( V_142 , V_58 , V_421 , V_422 ) < 0 )
F_101 () ;
return F_86 ( V_118 , V_142 , 0 , V_423 ) ;
}
static bool F_218 ( const struct V_146 * V_147 )
{
return ( bool ) F_219 ( V_147 -> V_118 ) ;
}
static int T_8 F_220 ( struct V_118 * V_118 )
{
struct V_189 * V_202 ;
struct V_424 V_425 = {
. V_426 = V_427 ,
. V_428 = F_186 ,
} ;
V_202 = F_221 ( V_118 , V_429 , & V_425 ) ;
if ( V_202 == NULL )
return - V_69 ;
V_118 -> V_134 . V_430 = V_202 ;
F_222 ( V_118 -> V_134 . V_202 , V_202 ) ;
return 0 ;
}
static void T_9 F_223 ( struct V_431 * V_432 )
{
struct V_118 * V_118 ;
F_224 (net, net_exit_list, exit_list)
F_225 ( V_118 -> V_134 . V_202 , NULL ) ;
F_226 () ;
F_224 (net, net_exit_list, exit_list)
F_227 ( V_118 -> V_134 . V_430 ) ;
}
static int T_10 F_228 ( void )
{
int V_433 ;
F_199 ( V_434 L_3 ) ;
V_433 = F_229 ( & V_435 ) ;
if ( V_433 < 0 )
return V_433 ;
V_433 = F_230 ( & V_436 ) ;
if ( V_433 < 0 )
F_231 ( & V_435 ) ;
return V_433 ;
}
static void T_11 F_232 ( void )
{
F_233 ( & V_436 ) ;
F_231 ( & V_435 ) ;
}
