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
if ( V_2 [ V_18 ] &&
F_39 ( V_58 , F_2 ( V_2 [ V_18 ] ) ) )
goto error;
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
memcpy ( & V_24 -> V_162 , & V_58 -> V_162 , sizeof( V_24 -> V_162 ) ) ;
memcpy ( & V_24 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_24 -> V_96 ) ) ;
V_24 -> V_46 = V_58 -> V_64 . V_46 ;
V_24 -> V_37 = V_58 -> V_64 . V_37 ;
V_24 -> V_95 = V_58 -> V_64 . V_95 ;
V_24 -> V_39 = V_58 -> V_64 . V_39 ;
V_24 -> V_28 = V_58 -> V_64 . V_28 ;
V_24 -> V_133 = V_58 -> V_132 . V_133 ;
}
static int F_61 ( struct V_91 * V_163 , struct V_141 * V_142 )
{
struct V_19 * V_20 ;
struct V_1 * V_164 ;
int V_165 = sizeof( * V_20 ) + V_163 -> V_22 ;
V_164 = F_62 ( V_142 , V_18 , V_165 ) ;
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
static int F_63 ( struct V_14 * V_78 , struct V_141 * V_142 )
{
struct V_5 * V_62 ;
struct V_1 * V_171 ;
V_171 = F_62 ( V_142 , V_8 ,
sizeof( * V_62 ) + ( V_78 -> V_76 + 7 ) / 8 ) ;
if ( ! V_171 )
return - V_166 ;
V_62 = F_2 ( V_171 ) ;
strncpy ( V_62 -> V_11 , V_78 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_80 , V_78 -> V_80 , ( V_78 -> V_76 + 7 ) / 8 ) ;
V_62 -> V_76 = V_78 -> V_76 ;
return 0 ;
}
static int F_64 ( struct V_57 * V_58 ,
struct V_23 * V_24 ,
struct V_141 * V_142 )
{
int V_172 = 0 ;
F_60 ( V_58 , V_24 ) ;
if ( V_58 -> V_64 . V_122 ) {
V_172 = F_65 ( V_142 , V_121 ,
V_58 -> V_64 . V_122 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_130 ) {
V_172 = F_66 ( V_142 , V_53 , sizeof( * V_58 -> V_130 ) , V_58 -> V_130 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_173 ) {
V_172 = F_67 ( V_142 , V_174 , V_58 -> V_173 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_83 ) {
V_172 = F_66 ( V_142 , V_15 , F_8 ( V_58 -> V_83 ) , V_58 -> V_83 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_123 ) {
V_172 = F_63 ( V_58 -> V_123 , V_142 ) ;
if ( ! V_172 )
V_172 = F_66 ( V_142 , V_13 ,
F_6 ( V_58 -> V_123 ) , V_58 -> V_123 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_71 ) {
V_172 = F_66 ( V_142 , V_9 , F_4 ( V_58 -> V_71 ) , V_58 -> V_71 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_125 ) {
V_172 = F_66 ( V_142 , V_10 , sizeof( * ( V_58 -> V_125 ) ) , V_58 -> V_125 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_128 ) {
V_172 = F_66 ( V_142 , V_52 , sizeof( * V_58 -> V_128 ) , V_58 -> V_128 ) ;
if ( V_172 )
goto V_44;
}
if ( V_58 -> V_129 ) {
V_172 = F_65 ( V_142 , V_45 , V_58 -> V_129 ) ;
if ( V_172 )
goto V_44;
}
V_172 = F_68 ( V_142 , & V_58 -> V_131 ) ;
if ( V_172 )
goto V_44;
if ( V_58 -> V_84 )
V_172 = F_66 ( V_142 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
else
V_172 = F_66 ( V_142 , V_99 , sizeof( V_58 -> V_107 ) ,
& V_58 -> V_107 ) ;
if ( V_172 )
goto V_44;
if ( V_58 -> V_175 )
V_172 = F_61 ( V_58 -> V_175 , V_142 ) ;
V_44:
return V_172 ;
}
static int F_69 ( struct V_57 * V_58 , int V_176 , void * V_177 )
{
struct V_178 * V_179 = V_177 ;
struct V_141 * V_180 = V_179 -> V_180 ;
struct V_141 * V_142 = V_179 -> V_181 ;
struct V_23 * V_24 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , F_71 ( V_180 ) . V_151 , V_179 -> V_150 ,
V_149 , sizeof( * V_24 ) , V_179 -> V_182 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_24 = F_44 ( V_144 ) ;
V_38 = F_64 ( V_58 , V_24 , V_142 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_74 ( struct V_183 * V_184 )
{
struct V_185 * V_186 = (struct V_185 * ) & V_184 -> args [ 1 ] ;
struct V_187 * V_145 = V_184 -> V_142 -> V_145 ;
struct V_118 * V_118 = F_43 ( V_145 ) ;
F_75 ( V_186 , V_118 ) ;
return 0 ;
}
static int F_76 ( struct V_141 * V_142 , struct V_183 * V_184 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_185 * V_186 = (struct V_185 * ) & V_184 -> args [ 1 ] ;
struct V_178 V_188 ;
F_77 ( sizeof( struct V_185 ) >
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
V_38 = F_78 ( V_184 -> V_144 , 0 , V_2 , V_190 ,
V_193 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_194 ] ) {
V_192 = F_21 ( sizeof( * V_192 ) , V_68 ) ;
if ( V_192 == NULL )
return - V_69 ;
memcpy ( V_192 , F_2 ( V_2 [ V_194 ] ) ,
sizeof( * V_192 ) ) ;
}
if ( V_2 [ V_195 ] )
V_34 = F_79 ( V_2 [ V_195 ] ) ;
F_80 ( V_186 , V_34 , V_192 ) ;
}
( void ) V_185 ( V_118 , V_186 , F_69 , & V_188 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_81 ( struct V_141 * V_180 ,
struct V_57 * V_58 , T_3 V_133 )
{
struct V_178 V_188 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_82 ( V_196 , V_197 ) ;
if ( ! V_142 )
return F_83 ( - V_69 ) ;
V_188 . V_180 = V_180 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_133 ;
V_188 . V_182 = 0 ;
V_38 = F_69 ( V_58 , 0 , & V_188 ) ;
if ( V_38 ) {
F_84 ( V_142 ) ;
return F_83 ( V_38 ) ;
}
return V_142 ;
}
static inline int F_85 ( struct V_118 * V_118 , struct V_141 * V_142 ,
T_3 V_198 , unsigned int V_199 )
{
struct V_187 * V_200 = F_86 ( V_118 -> V_134 . V_200 ) ;
if ( V_200 )
return F_87 ( V_200 , V_142 , V_198 , V_199 , V_197 ) ;
else
return - 1 ;
}
static inline T_4 F_88 ( void )
{
return F_89 ( 4 )
+ F_90 ( sizeof( struct V_201 ) )
+ F_90 ( sizeof( struct V_202 ) )
+ F_90 ( sizeof( struct V_203 ) )
+ F_90 ( sizeof( struct V_203 ) ) ;
}
static int F_91 ( struct V_141 * V_142 , struct V_118 * V_118 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_204 V_205 ;
struct V_201 V_206 ;
struct V_202 V_207 ;
struct V_203 V_208 , V_209 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_210 ;
unsigned V_211 ;
V_144 = F_70 ( V_142 , V_151 , V_133 , V_212 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_210 = F_44 ( V_144 ) ;
* V_210 = V_28 ;
F_92 ( V_118 , & V_205 ) ;
V_206 . V_213 = V_205 . V_213 ;
V_206 . V_214 = V_205 . V_214 ;
V_206 . V_215 = V_205 . V_215 ;
V_206 . V_216 = V_205 . V_216 ;
V_206 . V_217 = V_205 . V_217 ;
V_206 . V_218 = V_205 . V_218 ;
V_207 . V_219 = V_205 . V_219 ;
V_207 . V_220 = V_205 . V_220 ;
do {
V_211 = F_93 ( & V_118 -> V_134 . V_221 . V_222 ) ;
V_208 . V_223 = V_118 -> V_134 . V_221 . V_224 ;
V_208 . V_225 = V_118 -> V_134 . V_221 . V_226 ;
V_209 . V_223 = V_118 -> V_134 . V_221 . V_227 ;
V_209 . V_225 = V_118 -> V_134 . V_221 . V_228 ;
} while ( F_94 ( & V_118 -> V_134 . V_221 . V_222 , V_211 ) );
V_38 = F_66 ( V_142 , V_229 , sizeof( V_206 ) , & V_206 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , V_230 , sizeof( V_207 ) , & V_207 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , V_231 , sizeof( V_208 ) , & V_208 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , V_232 , sizeof( V_209 ) , & V_209 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_95 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_203 * V_233 = NULL ;
struct V_203 * V_234 = NULL ;
if ( V_2 [ V_231 ] ) {
struct V_1 * V_59 = V_2 [ V_231 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_233 ) )
return - V_7 ;
V_233 = F_2 ( V_59 ) ;
if ( V_233 -> V_223 > 32 || V_233 -> V_225 > 32 )
return - V_7 ;
}
if ( V_2 [ V_232 ] ) {
struct V_1 * V_59 = V_2 [ V_232 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_234 ) )
return - V_7 ;
V_234 = F_2 ( V_59 ) ;
if ( V_234 -> V_223 > 128 || V_234 -> V_225 > 128 )
return - V_7 ;
}
if ( V_233 || V_234 ) {
F_96 ( & V_118 -> V_134 . V_221 . V_222 ) ;
if ( V_233 ) {
V_118 -> V_134 . V_221 . V_224 = V_233 -> V_223 ;
V_118 -> V_134 . V_221 . V_226 = V_233 -> V_225 ;
}
if ( V_234 ) {
V_118 -> V_134 . V_221 . V_227 = V_234 -> V_223 ;
V_118 -> V_134 . V_221 . V_228 = V_234 -> V_225 ;
}
F_97 ( & V_118 -> V_134 . V_221 . V_222 ) ;
F_98 ( V_118 ) ;
}
return 0 ;
}
static int F_99 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_141 * V_235 ;
T_3 * V_28 = F_44 ( V_144 ) ;
T_3 V_236 = F_71 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_235 = F_82 ( F_88 () , V_197 ) ;
if ( V_235 == NULL )
return - V_69 ;
if ( F_91 ( V_235 , V_118 , V_236 , V_133 , * V_28 ) < 0 )
F_100 () ;
return F_101 ( V_118 -> V_134 . V_200 , V_235 , V_236 ) ;
}
static inline T_4 F_102 ( void )
{
return F_89 ( 4 )
+ F_90 ( sizeof( struct V_237 ) )
+ F_90 ( 4 ) ;
}
static int F_103 ( struct V_141 * V_142 , struct V_118 * V_118 ,
T_3 V_151 , T_3 V_133 , T_3 V_28 )
{
struct V_238 V_205 ;
struct V_237 V_239 ;
struct V_143 * V_144 ;
int V_38 ;
T_3 * V_210 ;
V_144 = F_70 ( V_142 , V_151 , V_133 , V_240 , sizeof( T_3 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_210 = F_44 ( V_144 ) ;
* V_210 = V_28 ;
F_104 ( V_118 , & V_205 ) ;
V_239 . V_241 = V_205 . V_241 ;
V_239 . V_242 = V_205 . V_242 ;
V_38 = F_65 ( V_142 , V_243 , V_205 . V_244 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_142 , V_245 , sizeof( V_239 ) , & V_239 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_105 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_141 * V_235 ;
T_3 * V_28 = F_44 ( V_144 ) ;
T_3 V_236 = F_71 ( V_142 ) . V_151 ;
T_3 V_133 = V_144 -> V_150 ;
V_235 = F_82 ( F_102 () , V_197 ) ;
if ( V_235 == NULL )
return - V_69 ;
if ( F_103 ( V_235 , V_118 , V_236 , V_133 , * V_28 ) < 0 )
F_100 () ;
return F_101 ( V_118 -> V_134 . V_200 , V_235 , V_236 ) ;
}
static int F_106 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_154 * V_24 = F_44 ( V_144 ) ;
struct V_57 * V_58 ;
struct V_141 * V_246 ;
int V_38 = - V_158 ;
V_58 = F_51 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( V_58 == NULL )
goto V_247;
V_246 = F_81 ( V_142 , V_58 , V_144 -> V_150 ) ;
if ( F_107 ( V_246 ) ) {
V_38 = F_108 ( V_246 ) ;
} else {
V_38 = F_101 ( V_118 -> V_134 . V_200 , V_246 , F_71 ( V_142 ) . V_151 ) ;
}
F_41 ( V_58 ) ;
V_247:
return V_38 ;
}
static int F_109 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_248 * V_24 ;
struct V_141 * V_246 ;
T_1 * V_159 ;
int V_39 ;
int V_38 ;
T_3 V_131 ;
struct V_155 V_156 ;
V_24 = F_44 ( V_144 ) ;
V_38 = F_110 ( V_24 -> V_188 . V_33 . V_34 , V_24 -> V_249 , V_24 -> V_250 ) ;
if ( V_38 )
goto V_247;
V_39 = V_24 -> V_188 . V_39 ;
V_159 = & V_24 -> V_188 . V_33 . V_159 ;
V_58 = NULL ;
V_131 = F_37 ( V_2 , & V_156 ) ;
if ( V_24 -> V_188 . V_133 ) {
V_58 = F_111 ( V_118 , V_131 , V_24 -> V_188 . V_133 ) ;
if ( V_58 && ! F_112 ( & V_58 -> V_33 . V_159 , V_159 , V_39 ) ) {
F_41 ( V_58 ) ;
V_58 = NULL ;
}
}
if ( ! V_58 )
V_58 = F_113 ( V_118 , & V_156 , V_24 -> V_188 . V_46 , V_24 -> V_188 . V_95 ,
V_24 -> V_188 . V_33 . V_34 , V_159 ,
& V_24 -> V_188 . V_96 , 1 ,
V_39 ) ;
V_38 = - V_251 ;
if ( V_58 == NULL )
goto V_247;
V_38 = F_114 ( V_58 , V_24 -> V_249 , V_24 -> V_250 ) ;
if ( V_38 )
goto V_44;
V_246 = F_81 ( V_142 , V_58 , V_144 -> V_150 ) ;
if ( F_107 ( V_246 ) ) {
V_38 = F_108 ( V_246 ) ;
goto V_44;
}
V_38 = F_101 ( V_118 -> V_134 . V_200 , V_246 , F_71 ( V_142 ) . V_151 ) ;
V_44:
F_41 ( V_58 ) ;
V_247:
return V_38 ;
}
static int F_115 ( T_2 V_252 )
{
switch ( V_252 ) {
case V_253 :
case V_254 :
case V_255 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_116 ( T_2 type )
{
switch ( type ) {
case V_256 :
#ifdef F_117
case V_257 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_118 ( struct V_258 * V_24 )
{
int V_172 ;
switch ( V_24 -> V_259 ) {
case V_260 :
case V_261 :
case V_262 :
case V_263 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_264 ) {
case V_265 :
case V_266 :
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
V_172 = F_115 ( V_24 -> V_252 ) ;
if ( V_172 )
return V_172 ;
if ( V_24 -> V_267 && ( ( V_24 -> V_267 & V_268 ) != V_24 -> V_252 ) )
return - V_7 ;
return 0 ;
}
static int F_119 ( struct V_269 * V_270 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_120 ( & V_270 -> V_175 , V_20 , V_68 ) ;
}
static void F_121 ( struct V_269 * V_271 , struct V_272 * V_273 ,
int V_274 )
{
int V_275 ;
V_271 -> V_276 = V_274 ;
for ( V_275 = 0 ; V_275 < V_274 ; V_275 ++ , V_273 ++ ) {
struct V_277 * V_278 = & V_271 -> V_279 [ V_275 ] ;
memcpy ( & V_278 -> V_33 , & V_273 -> V_33 , sizeof( struct V_280 ) ) ;
memcpy ( & V_278 -> V_96 , & V_273 -> V_96 ,
sizeof( T_1 ) ) ;
V_278 -> V_95 = V_273 -> V_95 ;
V_278 -> V_46 = V_273 -> V_46 ;
V_278 -> V_259 = V_273 -> V_259 ;
V_278 -> V_281 = V_273 -> V_281 ;
V_278 -> V_282 = V_273 -> V_282 ;
V_278 -> V_283 = V_273 -> V_283 ;
V_278 -> V_284 = V_273 -> V_284 ;
V_278 -> V_285 = ! ~ ( V_278 -> V_282 & V_278 -> V_283 & V_278 -> V_284 ) ;
V_278 -> V_286 = V_273 -> V_39 ;
}
}
static int F_122 ( int V_274 , struct V_272 * V_273 , T_5 V_39 )
{
int V_275 ;
if ( V_274 > V_287 )
return - V_7 ;
for ( V_275 = 0 ; V_275 < V_274 ; V_275 ++ ) {
if ( ! V_273 [ V_275 ] . V_39 )
V_273 [ V_275 ] . V_39 = V_39 ;
switch ( V_273 [ V_275 ] . V_39 ) {
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
static int F_123 ( struct V_269 * V_270 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_288 ] ;
if ( ! V_4 ) {
V_270 -> V_276 = 0 ;
} else {
struct V_272 * V_289 = F_2 ( V_4 ) ;
int V_274 = F_3 ( V_4 ) / sizeof( * V_289 ) ;
int V_38 ;
V_38 = F_122 ( V_274 , V_289 , V_270 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_121 ( V_270 , V_289 , V_274 ) ;
}
return 0 ;
}
static int F_124 ( T_2 * V_290 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_291 ] ;
struct V_292 * V_293 ;
T_2 type = V_256 ;
int V_38 ;
if ( V_4 ) {
V_293 = F_2 ( V_4 ) ;
type = V_293 -> type ;
}
V_38 = F_116 ( type ) ;
if ( V_38 )
return V_38 ;
* V_290 = type ;
return 0 ;
}
static void F_125 ( struct V_269 * V_271 , struct V_258 * V_24 )
{
V_271 -> V_294 = V_24 -> V_294 ;
V_271 -> V_267 = V_24 -> V_267 ;
memcpy ( & V_271 -> V_295 , & V_24 -> V_93 , sizeof( V_271 -> V_295 ) ) ;
memcpy ( & V_271 -> V_94 , & V_24 -> V_94 , sizeof( V_271 -> V_94 ) ) ;
V_271 -> V_264 = V_24 -> V_264 ;
V_271 -> V_28 = V_24 -> V_28 ;
V_271 -> V_39 = V_24 -> V_93 . V_39 ;
}
static void F_126 ( struct V_269 * V_271 , struct V_258 * V_24 , int V_252 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_93 , & V_271 -> V_295 , sizeof( V_24 -> V_93 ) ) ;
memcpy ( & V_24 -> V_94 , & V_271 -> V_94 , sizeof( V_24 -> V_94 ) ) ;
memcpy ( & V_24 -> V_111 , & V_271 -> V_111 , sizeof( V_24 -> V_111 ) ) ;
V_24 -> V_294 = V_271 -> V_294 ;
V_24 -> V_267 = V_271 -> V_267 ;
V_24 -> V_93 . V_39 = V_271 -> V_39 ;
V_24 -> V_252 = V_252 ;
V_24 -> V_264 = V_271 -> V_264 ;
V_24 -> V_28 = V_271 -> V_28 ;
V_24 -> V_259 = V_260 ;
}
static struct V_269 * F_127 ( struct V_118 * V_118 , struct V_258 * V_24 , struct V_1 * * V_2 , int * V_119 )
{
struct V_269 * V_271 = F_128 ( V_118 , V_68 ) ;
int V_38 ;
if ( ! V_271 ) {
* V_119 = - V_69 ;
return NULL ;
}
F_125 ( V_271 , V_24 ) ;
V_38 = F_124 ( & V_271 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_123 ( V_271 , V_2 ) ) )
V_38 = F_119 ( V_271 , V_2 ) ;
if ( V_38 )
goto error;
F_37 ( V_2 , & V_271 -> V_131 ) ;
return V_271 ;
error:
* V_119 = V_38 ;
V_271 -> V_186 . V_296 = 1 ;
F_129 ( V_271 ) ;
return NULL ;
}
static int F_130 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_258 * V_24 = F_44 ( V_144 ) ;
struct V_269 * V_271 ;
struct V_146 V_147 ;
int V_38 ;
int V_297 ;
V_38 = F_118 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_271 = F_127 ( V_118 , V_24 , V_2 , & V_38 ) ;
if ( ! V_271 )
return V_38 ;
V_297 = V_144 -> V_148 == V_298 ;
V_38 = F_131 ( V_24 -> V_252 , V_271 , V_297 ) ;
F_132 ( V_271 , V_38 ? 0 : 1 , true ) ;
if ( V_38 ) {
F_133 ( V_271 -> V_175 ) ;
F_28 ( V_271 ) ;
return V_38 ;
}
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_134 ( V_271 , V_24 -> V_252 , & V_147 ) ;
F_135 ( V_271 ) ;
return 0 ;
}
static int F_136 ( struct V_269 * V_271 , struct V_141 * V_142 )
{
struct V_272 V_299 [ V_287 ] ;
int V_275 ;
if ( V_271 -> V_276 == 0 )
return 0 ;
for ( V_275 = 0 ; V_275 < V_271 -> V_276 ; V_275 ++ ) {
struct V_272 * V_86 = & V_299 [ V_275 ] ;
struct V_277 * V_300 = & V_271 -> V_279 [ V_275 ] ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
memcpy ( & V_86 -> V_33 , & V_300 -> V_33 , sizeof( V_86 -> V_33 ) ) ;
V_86 -> V_39 = V_300 -> V_286 ;
memcpy ( & V_86 -> V_96 , & V_300 -> V_96 , sizeof( V_86 -> V_96 ) ) ;
V_86 -> V_95 = V_300 -> V_95 ;
V_86 -> V_46 = V_300 -> V_46 ;
V_86 -> V_259 = V_300 -> V_259 ;
V_86 -> V_281 = V_300 -> V_281 ;
V_86 -> V_282 = V_300 -> V_282 ;
V_86 -> V_283 = V_300 -> V_283 ;
V_86 -> V_284 = V_300 -> V_284 ;
}
return F_66 ( V_142 , V_288 ,
sizeof( struct V_272 ) * V_271 -> V_276 , V_299 ) ;
}
static inline int F_137 ( struct V_57 * V_58 , struct V_141 * V_142 )
{
if ( V_58 -> V_175 ) {
return F_61 ( V_58 -> V_175 , V_142 ) ;
}
return 0 ;
}
static inline int F_138 ( struct V_269 * V_271 , struct V_141 * V_142 )
{
if ( V_271 -> V_175 )
return F_61 ( V_271 -> V_175 , V_142 ) ;
return 0 ;
}
static inline T_4 F_139 ( void )
{
#ifdef F_117
return F_90 ( sizeof( struct V_292 ) ) ;
#else
return 0 ;
#endif
}
static int F_140 ( T_2 type , struct V_141 * V_142 )
{
struct V_292 V_293 = {
. type = type ,
} ;
return F_66 ( V_142 , V_291 , sizeof( V_293 ) , & V_293 ) ;
}
static inline int F_140 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_141 ( struct V_269 * V_271 , int V_252 , int V_176 , void * V_177 )
{
struct V_178 * V_179 = V_177 ;
struct V_258 * V_24 ;
struct V_141 * V_180 = V_179 -> V_180 ;
struct V_141 * V_142 = V_179 -> V_181 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , F_71 ( V_180 ) . V_151 , V_179 -> V_150 ,
V_298 , sizeof( * V_24 ) , V_179 -> V_182 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_24 = F_44 ( V_144 ) ;
F_126 ( V_271 , V_24 , V_252 ) ;
V_38 = F_136 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_140 ( V_271 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_68 ( V_142 , & V_271 -> V_131 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_142 ( struct V_183 * V_184 )
{
struct V_301 * V_186 = (struct V_301 * ) & V_184 -> args [ 1 ] ;
struct V_118 * V_118 = F_43 ( V_184 -> V_142 -> V_145 ) ;
F_143 ( V_186 , V_118 ) ;
return 0 ;
}
static int F_144 ( struct V_141 * V_142 , struct V_183 * V_184 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_301 * V_186 = (struct V_301 * ) & V_184 -> args [ 1 ] ;
struct V_178 V_188 ;
F_77 ( sizeof( struct V_301 ) >
sizeof( V_184 -> args ) - sizeof( V_184 -> args [ 0 ] ) ) ;
V_188 . V_180 = V_184 -> V_142 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_184 -> V_144 -> V_150 ;
V_188 . V_182 = V_189 ;
if ( ! V_184 -> args [ 0 ] ) {
V_184 -> args [ 0 ] = 1 ;
F_145 ( V_186 , V_302 ) ;
}
( void ) V_301 ( V_118 , V_186 , F_141 , & V_188 ) ;
return V_142 -> V_21 ;
}
static struct V_141 * F_146 ( struct V_141 * V_180 ,
struct V_269 * V_271 ,
int V_252 , T_3 V_133 )
{
struct V_178 V_188 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_82 ( V_196 , V_68 ) ;
if ( ! V_142 )
return F_83 ( - V_69 ) ;
V_188 . V_180 = V_180 ;
V_188 . V_181 = V_142 ;
V_188 . V_150 = V_133 ;
V_188 . V_182 = 0 ;
V_38 = F_141 ( V_271 , V_252 , 0 , & V_188 ) ;
if ( V_38 ) {
F_84 ( V_142 ) ;
return F_83 ( V_38 ) ;
}
return V_142 ;
}
static int F_147 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_269 * V_271 ;
struct V_303 * V_24 ;
T_2 type = V_256 ;
int V_38 ;
struct V_146 V_147 ;
int V_304 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_24 = F_44 ( V_144 ) ;
V_304 = V_144 -> V_148 == V_305 ;
V_38 = F_124 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_115 ( V_24 -> V_252 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_267 )
V_271 = F_148 ( V_118 , V_131 , type , V_24 -> V_252 , V_24 -> V_267 , V_304 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_91 * V_306 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_306 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_120 ( & V_306 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_271 = F_149 ( V_118 , V_131 , type , V_24 -> V_252 , & V_24 -> V_93 ,
V_306 , V_304 , & V_38 ) ;
F_133 ( V_306 ) ;
}
if ( V_271 == NULL )
return - V_251 ;
if ( ! V_304 ) {
struct V_141 * V_246 ;
V_246 = F_146 ( V_142 , V_271 , V_24 -> V_252 , V_144 -> V_150 ) ;
if ( F_107 ( V_246 ) ) {
V_38 = F_108 ( V_246 ) ;
} else {
V_38 = F_101 ( V_118 -> V_134 . V_200 , V_246 ,
F_71 ( V_142 ) . V_151 ) ;
}
} else {
F_150 ( V_271 , V_38 ? 0 : 1 , true ) ;
if ( V_38 != 0 )
goto V_44;
V_147 . V_307 . V_308 = V_24 -> V_267 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
F_134 ( V_271 , V_24 -> V_252 , & V_147 ) ;
}
V_44:
F_135 ( V_271 ) ;
if ( V_304 && V_38 == 0 )
F_151 ( V_118 ) ;
return V_38 ;
}
static int F_152 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_309 * V_24 = F_44 ( V_144 ) ;
int V_38 ;
V_38 = F_153 ( V_118 , V_24 -> V_34 , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_307 . V_34 = V_24 -> V_34 ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_118 = V_118 ;
F_50 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_4 F_154 ( struct V_57 * V_58 )
{
T_4 V_310 = V_58 -> V_84 ?
F_12 ( V_58 -> V_84 ) :
sizeof( struct V_106 ) ;
return F_89 ( sizeof( struct V_311 ) )
+ F_90 ( V_310 )
+ F_90 ( sizeof( struct V_109 ) )
+ F_90 ( sizeof( struct V_155 ) )
+ F_90 ( 4 )
+ F_90 ( 4 ) ;
}
static int F_155 ( struct V_141 * V_142 , struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_311 * V_33 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_312 , sizeof( * V_33 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_33 = F_44 ( V_144 ) ;
memcpy ( & V_33 -> V_313 . V_159 , & V_58 -> V_33 . V_159 , sizeof( V_58 -> V_33 . V_159 ) ) ;
V_33 -> V_313 . V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_313 . V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_313 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_58 -> V_64 . V_96 ) ) ;
V_33 -> V_95 = V_58 -> V_64 . V_95 ;
V_33 -> V_28 = V_147 -> V_307 . V_314 ;
if ( V_58 -> V_84 ) {
V_38 = F_66 ( V_142 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
} else {
V_38 = F_66 ( V_142 , V_99 , sizeof( V_58 -> V_107 ) ,
& V_58 -> V_107 ) ;
}
if ( V_38 )
goto V_315;
V_38 = F_66 ( V_142 , V_102 , sizeof( V_58 -> V_111 ) , & V_58 -> V_111 ) ;
if ( V_38 )
goto V_315;
if ( V_33 -> V_28 & V_316 ) {
V_38 = F_65 ( V_142 , V_105 , V_58 -> V_117 ) ;
if ( V_38 )
goto V_315;
}
if ( V_33 -> V_28 & V_317 ) {
V_38 = F_65 ( V_142 , V_104 ,
V_58 -> V_116 * 10 / V_137 ) ;
if ( V_38 )
goto V_315;
}
V_38 = F_68 ( V_142 , & V_58 -> V_131 ) ;
if ( V_38 )
goto V_315;
F_73 ( V_142 , V_144 ) ;
return 0 ;
V_315:
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_156 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_141 * V_235 ;
int V_38 ;
struct V_146 V_147 ;
T_3 V_131 ;
struct V_155 V_156 ;
struct V_311 * V_24 = F_44 ( V_144 ) ;
struct V_154 * V_33 = & V_24 -> V_313 ;
V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_33 -> V_159 , V_33 -> V_49 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_58 == NULL )
return - V_158 ;
V_235 = F_82 ( F_154 ( V_58 ) , V_197 ) ;
if ( V_235 == NULL ) {
F_41 ( V_58 ) ;
return - V_69 ;
}
F_157 ( & V_58 -> V_222 ) ;
V_147 . V_307 . V_314 = V_24 -> V_28 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
if ( F_155 ( V_235 , V_58 , & V_147 ) < 0 )
F_100 () ;
V_38 = F_101 ( V_118 -> V_134 . V_200 , V_235 , F_71 ( V_142 ) . V_151 ) ;
F_158 ( & V_58 -> V_222 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_159 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
struct V_146 V_147 ;
int V_38 = - V_7 ;
T_3 V_131 = 0 ;
struct V_155 V_156 ;
struct V_311 * V_24 = F_44 ( V_144 ) ;
struct V_1 * V_85 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_2 [ V_25 ] ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
if ( ! V_101 && ! V_85 && ! V_100 )
return V_38 ;
if ( ! ( V_144 -> V_182 & V_318 ) )
return V_38 ;
V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_24 -> V_313 . V_159 , V_24 -> V_313 . V_49 , V_24 -> V_313 . V_34 , V_24 -> V_313 . V_39 ) ;
if ( V_58 == NULL )
return - V_158 ;
if ( V_58 -> V_132 . V_139 != V_319 )
goto V_44;
V_38 = F_25 ( V_58 -> V_84 , V_100 ) ;
if ( V_38 )
goto V_44;
F_157 ( & V_58 -> V_222 ) ;
F_32 ( V_58 , V_2 , 1 ) ;
F_158 ( & V_58 -> V_222 ) ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_307 . V_314 = V_320 ;
F_50 ( V_58 , & V_147 ) ;
V_38 = 0 ;
V_44:
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_160 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
T_2 type = V_256 ;
int V_38 ;
V_38 = F_124 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_161 ( V_118 , type , true ) ;
if ( V_38 ) {
if ( V_38 == - V_158 )
return 0 ;
return V_38 ;
}
V_147 . V_307 . type = type ;
V_147 . V_153 = V_144 -> V_148 ;
V_147 . V_133 = V_144 -> V_150 ;
V_147 . V_151 = V_144 -> V_152 ;
V_147 . V_118 = V_118 ;
F_134 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_162 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_269 * V_271 ;
struct V_321 * V_86 = F_44 ( V_144 ) ;
struct V_258 * V_24 = & V_86 -> V_270 ;
T_2 type = V_256 ;
int V_38 = - V_251 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_38 = F_124 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_115 ( V_24 -> V_252 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_267 )
V_271 = F_148 ( V_118 , V_131 , type , V_24 -> V_252 , V_24 -> V_267 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_91 * V_306 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_306 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_120 ( & V_306 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_271 = F_149 ( V_118 , V_131 , type , V_24 -> V_252 ,
& V_24 -> V_93 , V_306 , 0 , & V_38 ) ;
F_133 ( V_306 ) ;
}
if ( V_271 == NULL )
return - V_251 ;
if ( F_163 ( V_271 -> V_186 . V_296 ) )
goto V_44;
V_38 = 0 ;
if ( V_86 -> V_322 ) {
F_164 ( V_271 , V_24 -> V_252 ) ;
F_150 ( V_271 , 1 , true ) ;
} else {
F_165 ( 1 , L_1 ) ;
}
F_166 ( V_271 , V_24 -> V_252 , V_86 -> V_322 , V_144 -> V_152 ) ;
V_44:
F_135 ( V_271 ) ;
return V_38 ;
}
static int F_167 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_57 * V_58 ;
int V_38 ;
struct V_323 * V_324 = F_44 ( V_144 ) ;
struct V_23 * V_24 = & V_324 -> V_139 ;
struct V_155 V_156 ;
T_3 V_131 = F_37 ( V_2 , & V_156 ) ;
V_58 = F_53 ( V_118 , V_131 , & V_24 -> V_33 . V_159 , V_24 -> V_33 . V_49 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_251 ;
if ( V_58 == NULL )
return V_38 ;
F_157 ( & V_58 -> V_222 ) ;
V_38 = - V_7 ;
if ( V_58 -> V_132 . V_139 != V_319 )
goto V_44;
F_168 ( V_58 , V_324 -> V_322 , V_144 -> V_152 ) ;
if ( V_324 -> V_322 ) {
F_169 ( V_58 ) ;
F_59 ( V_58 , 1 , true ) ;
}
V_38 = 0 ;
V_44:
F_158 ( & V_58 -> V_222 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_170 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_269 * V_271 ;
struct V_272 * V_273 ;
int V_275 ;
struct V_1 * V_4 = V_2 [ V_288 ] ;
struct V_155 V_131 ;
struct V_325 * V_326 = F_44 ( V_144 ) ;
struct V_57 * V_58 = F_35 ( V_118 ) ;
int V_38 = - V_69 ;
if ( ! V_58 )
goto V_327;
F_37 ( V_2 , & V_131 ) ;
V_38 = F_118 ( & V_326 -> V_328 ) ;
if ( V_38 )
goto V_329;
V_271 = F_127 ( V_118 , & V_326 -> V_328 , V_2 , & V_38 ) ;
if ( ! V_271 )
goto V_330;
memcpy ( & V_58 -> V_33 , & V_326 -> V_33 , sizeof( V_326 -> V_33 ) ) ;
memcpy ( & V_58 -> V_64 . V_96 , & V_326 -> V_96 , sizeof( V_326 -> V_96 ) ) ;
memcpy ( & V_58 -> V_93 , & V_326 -> V_93 , sizeof( V_326 -> V_93 ) ) ;
V_271 -> V_131 . V_156 = V_58 -> V_131 . V_156 = V_131 . V_156 ;
V_271 -> V_131 . V_331 = V_58 -> V_131 . V_331 = V_131 . V_331 ;
V_273 = F_2 ( V_4 ) ;
for ( V_275 = 0 ; V_275 < V_271 -> V_276 ; V_275 ++ , V_273 ++ ) {
struct V_277 * V_278 = & V_271 -> V_279 [ V_275 ] ;
memcpy ( & V_58 -> V_33 , & V_278 -> V_33 , sizeof( V_58 -> V_33 ) ) ;
V_58 -> V_64 . V_46 = V_278 -> V_46 ;
V_58 -> V_64 . V_95 = V_278 -> V_95 ;
V_58 -> V_64 . V_39 = V_273 -> V_39 ;
V_278 -> V_282 = V_326 -> V_282 ;
V_278 -> V_283 = V_326 -> V_283 ;
V_278 -> V_284 = V_326 -> V_284 ;
V_38 = F_171 ( V_58 , V_278 , V_271 ) ;
}
F_28 ( V_58 ) ;
F_28 ( V_271 ) ;
return 0 ;
V_329:
F_165 ( 1 , L_2 ) ;
V_330:
F_28 ( V_58 ) ;
V_327:
return V_38 ;
}
static int F_172 ( struct V_332 * V_333 ,
struct V_334 * V_335 ,
struct V_1 * * V_2 , int * V_336 )
{
struct V_1 * V_4 = V_2 [ V_337 ] ;
struct V_338 * V_339 ;
int V_275 , V_340 ;
if ( V_335 != NULL ) {
struct V_341 * V_342 ;
V_342 = F_2 ( V_2 [ V_343 ] ) ;
memcpy ( & V_335 -> V_344 , & V_342 -> V_344 , sizeof( V_335 -> V_344 ) ) ;
memcpy ( & V_335 -> V_345 , & V_342 -> V_345 , sizeof( V_335 -> V_345 ) ) ;
V_335 -> V_39 = V_342 -> V_39 ;
V_335 -> V_346 = V_342 -> V_346 ;
}
V_339 = F_2 ( V_4 ) ;
V_340 = F_3 ( V_4 ) / sizeof( * V_339 ) ;
if ( V_340 <= 0 || V_340 > V_287 )
return - V_7 ;
for ( V_275 = 0 ; V_275 < V_340 ; V_275 ++ , V_339 ++ , V_333 ++ ) {
memcpy ( & V_333 -> V_347 , & V_339 -> V_347 , sizeof( V_333 -> V_347 ) ) ;
memcpy ( & V_333 -> V_348 , & V_339 -> V_348 , sizeof( V_333 -> V_348 ) ) ;
memcpy ( & V_333 -> V_349 , & V_339 -> V_349 , sizeof( V_333 -> V_349 ) ) ;
memcpy ( & V_333 -> V_350 , & V_339 -> V_350 , sizeof( V_333 -> V_350 ) ) ;
V_333 -> V_34 = V_339 -> V_34 ;
V_333 -> V_46 = V_339 -> V_46 ;
V_333 -> V_95 = V_339 -> V_95 ;
V_333 -> V_351 = V_339 -> V_351 ;
V_333 -> V_352 = V_339 -> V_352 ;
}
* V_336 = V_275 ;
return 0 ;
}
static int F_173 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
struct V_303 * V_353 = F_44 ( V_144 ) ;
struct V_332 V_156 [ V_287 ] ;
struct V_334 V_132 , * V_354 ;
T_2 type ;
int V_38 ;
int V_355 = 0 ;
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
if ( V_2 [ V_337 ] == NULL )
return - V_7 ;
V_354 = V_2 [ V_343 ] ? & V_132 : NULL ;
V_38 = F_124 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_172 ( (struct V_332 * ) V_156 , V_354 , V_2 , & V_355 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_355 )
return 0 ;
V_332 ( & V_353 -> V_93 , V_353 -> V_252 , type , V_156 , V_355 , V_354 , V_118 ) ;
return 0 ;
}
static int F_173 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_1 * * V_2 )
{
return - V_356 ;
}
static int F_174 ( const struct V_332 * V_156 , struct V_141 * V_142 )
{
struct V_338 V_339 ;
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
V_339 . V_34 = V_156 -> V_34 ;
V_339 . V_46 = V_156 -> V_46 ;
V_339 . V_95 = V_156 -> V_95 ;
V_339 . V_351 = V_156 -> V_351 ;
memcpy ( & V_339 . V_347 , & V_156 -> V_347 , sizeof( V_339 . V_347 ) ) ;
memcpy ( & V_339 . V_348 , & V_156 -> V_348 , sizeof( V_339 . V_348 ) ) ;
V_339 . V_352 = V_156 -> V_352 ;
memcpy ( & V_339 . V_349 , & V_156 -> V_349 , sizeof( V_339 . V_349 ) ) ;
memcpy ( & V_339 . V_350 , & V_156 -> V_350 , sizeof( V_339 . V_350 ) ) ;
return F_66 ( V_142 , V_337 , sizeof( V_339 ) , & V_339 ) ;
}
static int F_175 ( const struct V_334 * V_335 , struct V_141 * V_142 )
{
struct V_341 V_342 ;
memset ( & V_342 , 0 , sizeof( V_342 ) ) ;
V_342 . V_39 = V_335 -> V_39 ;
V_342 . V_346 = V_335 -> V_346 ;
memcpy ( & V_342 . V_344 , & V_335 -> V_344 , sizeof( V_342 . V_344 ) ) ;
memcpy ( & V_342 . V_345 , & V_335 -> V_345 , sizeof( V_342 . V_345 ) ) ;
return F_66 ( V_142 , V_343 , sizeof( V_342 ) , & V_342 ) ;
}
static inline T_4 F_176 ( int V_340 , int V_357 )
{
return F_89 ( sizeof( struct V_303 ) )
+ ( V_357 ? F_90 ( sizeof( struct V_334 ) ) : 0 )
+ F_90 ( sizeof( struct V_338 ) * V_340 )
+ F_139 () ;
}
static int F_177 ( struct V_141 * V_142 , const struct V_332 * V_156 ,
int V_340 , const struct V_334 * V_335 ,
const struct V_358 * V_93 , T_2 V_252 , T_2 type )
{
const struct V_332 * V_359 ;
struct V_303 * V_360 ;
struct V_143 * V_144 ;
int V_275 , V_38 ;
V_144 = F_70 ( V_142 , 0 , 0 , V_361 , sizeof( * V_360 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_360 = F_44 ( V_144 ) ;
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
memcpy ( & V_360 -> V_93 , V_93 , sizeof( V_360 -> V_93 ) ) ;
V_360 -> V_252 = V_252 ;
if ( V_335 != NULL ) {
V_38 = F_175 ( V_335 , V_142 ) ;
if ( V_38 )
goto V_315;
}
V_38 = F_140 ( type , V_142 ) ;
if ( V_38 )
goto V_315;
for ( V_275 = 0 , V_359 = V_156 ; V_275 < V_340 ; V_275 ++ , V_359 ++ ) {
V_38 = F_174 ( V_359 , V_142 ) ;
if ( V_38 )
goto V_315;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
V_315:
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
static int F_178 ( const struct V_358 * V_93 , T_2 V_252 , T_2 type ,
const struct V_332 * V_156 , int V_340 ,
const struct V_334 * V_335 )
{
struct V_118 * V_118 = & V_362 ;
struct V_141 * V_142 ;
V_142 = F_82 ( F_176 ( V_340 , ! ! V_335 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_177 ( V_142 , V_156 , V_340 , V_335 , V_93 , V_252 , type ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_363 ) ;
}
static int F_178 ( const struct V_358 * V_93 , T_2 V_252 , T_2 type ,
const struct V_332 * V_156 , int V_340 ,
const struct V_334 * V_335 )
{
return - V_356 ;
}
static int F_179 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
struct V_1 * V_2 [ V_190 + 1 ] ;
const struct V_364 * V_365 ;
int type , V_38 ;
#ifdef F_180
if ( F_181 () )
return - V_366 ;
#endif
type = V_144 -> V_148 ;
if ( type > V_367 )
return - V_7 ;
type -= V_368 ;
V_365 = & V_369 [ type ] ;
if ( ! F_182 ( V_142 , V_370 ) )
return - V_161 ;
if ( ( type == ( V_371 - V_368 ) ||
type == ( V_372 - V_368 ) ) &&
( V_144 -> V_182 & V_373 ) ) {
if ( V_365 -> V_374 == NULL )
return - V_7 ;
{
struct V_375 V_147 = {
. V_374 = V_365 -> V_374 ,
. V_376 = V_365 -> V_376 ,
} ;
return F_183 ( V_118 -> V_134 . V_200 , V_142 , V_144 , & V_147 ) ;
}
}
V_38 = F_78 ( V_144 , V_377 [ type ] , V_2 ,
V_365 -> V_378 ? : V_190 ,
V_365 -> V_379 ? : V_193 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_365 -> V_380 == NULL )
return - V_7 ;
return V_365 -> V_380 ( V_142 , V_144 , V_2 ) ;
}
static void F_184 ( struct V_141 * V_142 )
{
struct V_118 * V_118 = F_43 ( V_142 -> V_145 ) ;
F_185 ( & V_118 -> V_134 . V_381 ) ;
F_186 ( V_142 , & F_179 ) ;
F_187 ( & V_118 -> V_134 . V_381 ) ;
}
static inline T_4 F_188 ( void )
{
return F_89 ( sizeof( struct V_323 ) )
+ F_90 ( sizeof( struct V_155 ) ) ;
}
static int F_189 ( struct V_141 * V_142 , struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_323 * V_324 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , 0 , V_382 , sizeof( * V_324 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_324 = F_44 ( V_144 ) ;
F_60 ( V_58 , & V_324 -> V_139 ) ;
V_324 -> V_322 = ( V_147 -> V_307 . V_322 != 0 ) ? 1 : 0 ;
V_38 = F_68 ( V_142 , & V_58 -> V_131 ) ;
if ( V_38 )
return V_38 ;
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_190 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_191 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_82 ( F_188 () , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_189 ( V_142 , V_58 , V_147 ) < 0 ) {
F_84 ( V_142 ) ;
return - V_166 ;
}
return F_85 ( V_118 , V_142 , 0 , V_383 ) ;
}
static int F_192 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_191 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_82 ( F_154 ( V_58 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_155 ( V_142 , V_58 , V_147 ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_384 ) ;
}
static int F_193 ( const struct V_146 * V_147 )
{
struct V_118 * V_118 = V_147 -> V_118 ;
struct V_309 * V_24 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_89 ( sizeof( struct V_309 ) ) ;
V_142 = F_82 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_385 , sizeof( * V_24 ) , 0 ) ;
if ( V_144 == NULL ) {
F_84 ( V_142 ) ;
return - V_166 ;
}
V_24 = F_44 ( V_144 ) ;
V_24 -> V_34 = V_147 -> V_307 . V_34 ;
F_73 ( V_142 , V_144 ) ;
return F_85 ( V_118 , V_142 , 0 , V_386 ) ;
}
static inline T_4 F_194 ( struct V_57 * V_58 )
{
T_4 V_387 = 0 ;
if ( V_58 -> V_83 )
V_387 += F_90 ( F_8 ( V_58 -> V_83 ) ) ;
if ( V_58 -> V_123 ) {
V_387 += F_90 ( sizeof( struct V_5 ) +
( V_58 -> V_123 -> V_76 + 7 ) / 8 ) ;
V_387 += F_90 ( F_6 ( V_58 -> V_123 ) ) ;
}
if ( V_58 -> V_71 )
V_387 += F_90 ( F_4 ( V_58 -> V_71 ) ) ;
if ( V_58 -> V_125 )
V_387 += F_90 ( sizeof( * V_58 -> V_125 ) ) ;
if ( V_58 -> V_128 )
V_387 += F_90 ( sizeof( * V_58 -> V_128 ) ) ;
if ( V_58 -> V_129 )
V_387 += F_90 ( sizeof( V_58 -> V_129 ) ) ;
if ( V_58 -> V_84 )
V_387 += F_90 ( F_12 ( V_58 -> V_84 ) ) ;
else
V_387 += F_90 ( sizeof( struct V_106 ) ) ;
if ( V_58 -> V_175 )
V_387 += F_90 ( sizeof( struct V_19 ) +
V_58 -> V_175 -> V_22 ) ;
if ( V_58 -> V_130 )
V_387 += F_90 ( sizeof( * V_58 -> V_130 ) ) ;
if ( V_58 -> V_64 . V_122 )
V_387 += F_90 ( sizeof( V_58 -> V_64 . V_122 ) ) ;
V_387 += F_90 ( sizeof( V_388 ) ) ;
return V_387 ;
}
static int F_195 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_191 ( V_58 ) ;
struct V_23 * V_24 ;
struct V_154 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_21 = F_194 ( V_58 ) ;
int V_389 , V_38 ;
V_389 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_390 ) {
V_21 += F_90 ( V_389 ) ;
V_389 = sizeof( * V_33 ) ;
V_21 += F_90 ( sizeof( struct V_155 ) ) ;
}
V_21 += F_89 ( V_389 ) ;
V_142 = F_82 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_389 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_391;
V_24 = F_44 ( V_144 ) ;
if ( V_147 -> V_153 == V_390 ) {
struct V_1 * V_164 ;
V_33 = F_44 ( V_144 ) ;
memcpy ( & V_33 -> V_159 , & V_58 -> V_33 . V_159 , sizeof( V_33 -> V_159 ) ) ;
V_33 -> V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_34 = V_58 -> V_33 . V_34 ;
V_164 = F_62 ( V_142 , V_392 , sizeof( * V_24 ) ) ;
V_38 = - V_166 ;
if ( V_164 == NULL )
goto V_391;
V_24 = F_2 ( V_164 ) ;
}
V_38 = F_64 ( V_58 , V_24 , V_142 ) ;
if ( V_38 )
goto V_391;
F_73 ( V_142 , V_144 ) ;
return F_85 ( V_118 , V_142 , 0 , V_386 ) ;
V_391:
F_84 ( V_142 ) ;
return V_38 ;
}
static int F_196 ( struct V_57 * V_58 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_382 :
return F_190 ( V_58 , V_147 ) ;
case V_312 :
return F_192 ( V_58 , V_147 ) ;
case V_390 :
case V_393 :
case V_149 :
return F_195 ( V_58 , V_147 ) ;
case V_385 :
return F_193 ( V_147 ) ;
default:
F_197 ( V_394 L_3 ,
V_147 -> V_153 ) ;
break;
}
return 0 ;
}
static inline T_4 F_198 ( struct V_57 * V_58 ,
struct V_269 * V_271 )
{
return F_89 ( sizeof( struct V_325 ) )
+ F_90 ( sizeof( struct V_272 ) * V_271 -> V_276 )
+ F_90 ( sizeof( struct V_155 ) )
+ F_90 ( F_29 ( V_58 -> V_175 ) )
+ F_139 () ;
}
static int F_199 ( struct V_141 * V_142 , struct V_57 * V_58 ,
struct V_277 * V_395 , struct V_269 * V_271 )
{
T_6 V_133 = F_200 () ;
struct V_325 * V_326 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , 0 , 0 , V_396 , sizeof( * V_326 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_326 = F_44 ( V_144 ) ;
memcpy ( & V_326 -> V_33 , & V_58 -> V_33 , sizeof( V_326 -> V_33 ) ) ;
memcpy ( & V_326 -> V_96 , & V_58 -> V_64 . V_96 , sizeof( V_326 -> V_96 ) ) ;
memcpy ( & V_326 -> V_93 , & V_58 -> V_93 , sizeof( V_326 -> V_93 ) ) ;
F_126 ( V_271 , & V_326 -> V_328 , V_254 ) ;
V_326 -> V_282 = V_395 -> V_282 ;
V_326 -> V_283 = V_395 -> V_283 ;
V_326 -> V_284 = V_395 -> V_284 ;
V_326 -> V_133 = V_58 -> V_132 . V_133 = V_133 ;
V_38 = F_136 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_137 ( V_58 , V_142 ) ;
if ( ! V_38 )
V_38 = F_140 ( V_271 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_68 ( V_142 , & V_271 -> V_131 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_201 ( struct V_57 * V_58 , struct V_277 * V_395 ,
struct V_269 * V_271 )
{
struct V_118 * V_118 = F_191 ( V_58 ) ;
struct V_141 * V_142 ;
V_142 = F_82 ( F_198 ( V_58 , V_271 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_199 ( V_142 , V_58 , V_395 , V_271 ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_397 ) ;
}
static struct V_269 * F_202 ( struct V_187 * V_145 , int V_398 ,
T_2 * V_307 , int V_21 , int * V_252 )
{
struct V_118 * V_118 = F_43 ( V_145 ) ;
struct V_258 * V_24 = (struct V_258 * ) V_307 ;
struct V_272 * V_273 = (struct V_272 * ) ( V_24 + 1 ) ;
struct V_269 * V_271 ;
int V_274 ;
switch ( V_145 -> V_399 ) {
case V_40 :
if ( V_398 != V_400 ) {
* V_252 = - V_401 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_398 != V_402 ) {
* V_252 = - V_401 ;
return NULL ;
}
break;
#endif
default:
* V_252 = - V_7 ;
return NULL ;
}
* V_252 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_118 ( V_24 ) )
return NULL ;
V_274 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_273 ) ) ;
if ( F_122 ( V_274 , V_273 , V_24 -> V_93 . V_39 ) )
return NULL ;
if ( V_24 -> V_252 > V_254 )
return NULL ;
V_271 = F_128 ( V_118 , V_197 ) ;
if ( V_271 == NULL ) {
* V_252 = - V_403 ;
return NULL ;
}
F_125 ( V_271 , V_24 ) ;
V_271 -> type = V_256 ;
F_121 ( V_271 , V_273 , V_274 ) ;
* V_252 = V_24 -> V_252 ;
return V_271 ;
}
static inline T_4 F_203 ( struct V_269 * V_271 )
{
return F_89 ( sizeof( struct V_321 ) )
+ F_90 ( sizeof( struct V_272 ) * V_271 -> V_276 )
+ F_90 ( F_29 ( V_271 -> V_175 ) )
+ F_90 ( sizeof( struct V_155 ) )
+ F_139 () ;
}
static int F_204 ( struct V_141 * V_142 , struct V_269 * V_271 ,
int V_252 , const struct V_146 * V_147 )
{
struct V_321 * V_404 ;
int V_322 = V_147 -> V_307 . V_322 ;
struct V_143 * V_144 ;
int V_38 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , 0 , V_405 , sizeof( * V_404 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_404 = F_44 ( V_144 ) ;
F_126 ( V_271 , & V_404 -> V_270 , V_252 ) ;
V_38 = F_136 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_140 ( V_271 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_68 ( V_142 , & V_271 -> V_131 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
V_404 -> V_322 = ! ! V_322 ;
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_205 ( struct V_269 * V_271 , int V_252 , const struct V_146 * V_147 )
{
struct V_118 * V_118 = F_206 ( V_271 ) ;
struct V_141 * V_142 ;
V_142 = F_82 ( F_203 ( V_271 ) , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_204 ( V_142 , V_271 , V_252 , V_147 ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_383 ) ;
}
static int F_207 ( struct V_269 * V_271 , int V_252 , const struct V_146 * V_147 )
{
int V_21 = F_90 ( sizeof( struct V_272 ) * V_271 -> V_276 ) ;
struct V_118 * V_118 = F_206 ( V_271 ) ;
struct V_258 * V_24 ;
struct V_303 * V_33 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_389 , V_38 ;
V_389 = sizeof( * V_24 ) ;
if ( V_147 -> V_153 == V_305 ) {
V_21 += F_90 ( V_389 ) ;
V_389 = sizeof( * V_33 ) ;
}
V_21 += F_139 () ;
V_21 += F_90 ( sizeof( struct V_155 ) ) ;
V_21 += F_89 ( V_389 ) ;
V_142 = F_82 ( V_21 , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_147 -> V_153 , V_389 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_391;
V_24 = F_44 ( V_144 ) ;
if ( V_147 -> V_153 == V_305 ) {
struct V_1 * V_164 ;
V_33 = F_44 ( V_144 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_252 = V_252 ;
if ( V_147 -> V_307 . V_308 )
V_33 -> V_267 = V_271 -> V_267 ;
else
memcpy ( & V_33 -> V_93 , & V_271 -> V_295 , sizeof( V_33 -> V_93 ) ) ;
V_164 = F_62 ( V_142 , V_406 , sizeof( * V_24 ) ) ;
V_38 = - V_166 ;
if ( V_164 == NULL )
goto V_391;
V_24 = F_2 ( V_164 ) ;
}
F_126 ( V_271 , V_24 , V_252 ) ;
V_38 = F_136 ( V_271 , V_142 ) ;
if ( ! V_38 )
V_38 = F_140 ( V_271 -> type , V_142 ) ;
if ( ! V_38 )
V_38 = F_68 ( V_142 , & V_271 -> V_131 ) ;
if ( V_38 )
goto V_391;
F_73 ( V_142 , V_144 ) ;
return F_85 ( V_118 , V_142 , 0 , V_407 ) ;
V_391:
F_84 ( V_142 ) ;
return V_38 ;
}
static int F_208 ( const struct V_146 * V_147 )
{
struct V_118 * V_118 = V_147 -> V_118 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_38 ;
V_142 = F_82 ( F_139 () , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
V_144 = F_70 ( V_142 , V_147 -> V_151 , V_147 -> V_133 , V_408 , 0 , 0 ) ;
V_38 = - V_166 ;
if ( V_144 == NULL )
goto V_391;
V_38 = F_140 ( V_147 -> V_307 . type , V_142 ) ;
if ( V_38 )
goto V_391;
F_73 ( V_142 , V_144 ) ;
return F_85 ( V_118 , V_142 , 0 , V_407 ) ;
V_391:
F_84 ( V_142 ) ;
return V_38 ;
}
static int F_209 ( struct V_269 * V_271 , int V_252 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_153 ) {
case V_298 :
case V_409 :
case V_305 :
return F_207 ( V_271 , V_252 , V_147 ) ;
case V_408 :
return F_208 ( V_147 ) ;
case V_405 :
return F_205 ( V_271 , V_252 , V_147 ) ;
default:
F_197 ( V_394 L_4 ,
V_147 -> V_153 ) ;
}
return 0 ;
}
static inline T_4 F_210 ( void )
{
return F_89 ( sizeof( struct V_410 ) ) ;
}
static int F_211 ( struct V_141 * V_142 , T_2 V_34 ,
struct V_358 * V_93 , T_1 * V_411 )
{
struct V_410 * V_412 ;
struct V_143 * V_144 ;
V_144 = F_70 ( V_142 , 0 , 0 , V_413 , sizeof( * V_412 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_412 = F_44 ( V_144 ) ;
V_412 -> V_34 = V_34 ;
memcpy ( & V_412 -> V_93 , V_93 , sizeof( V_412 -> V_93 ) ) ;
if ( V_411 ) {
int V_38 = F_66 ( V_142 , V_53 , sizeof( * V_411 ) , V_411 ) ;
if ( V_38 ) {
F_72 ( V_142 , V_144 ) ;
return V_38 ;
}
}
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_212 ( struct V_118 * V_118 , T_2 V_34 ,
struct V_358 * V_93 , T_1 * V_411 )
{
struct V_141 * V_142 ;
V_142 = F_82 ( F_210 () , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_211 ( V_142 , V_34 , V_93 , V_411 ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_414 ) ;
}
static inline T_4 F_213 ( void )
{
return F_89 ( sizeof( struct V_415 ) ) ;
}
static int F_214 ( struct V_141 * V_142 , struct V_57 * V_58 ,
T_1 * V_350 , T_7 V_416 )
{
struct V_415 * V_339 ;
struct V_143 * V_144 ;
V_144 = F_70 ( V_142 , 0 , 0 , V_417 , sizeof( * V_339 ) , 0 ) ;
if ( V_144 == NULL )
return - V_166 ;
V_339 = F_44 ( V_144 ) ;
memcpy ( & V_339 -> V_33 . V_159 , & V_58 -> V_33 . V_159 , sizeof( V_339 -> V_33 . V_159 ) ) ;
V_339 -> V_33 . V_49 = V_58 -> V_33 . V_49 ;
V_339 -> V_33 . V_39 = V_58 -> V_64 . V_39 ;
V_339 -> V_33 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_339 -> V_350 , V_350 , sizeof( V_339 -> V_350 ) ) ;
memcpy ( & V_339 -> V_348 , & V_58 -> V_64 . V_96 , sizeof( V_339 -> V_348 ) ) ;
V_339 -> V_416 = V_416 ;
V_339 -> V_418 = V_58 -> V_128 -> V_419 ;
V_339 -> V_95 = V_58 -> V_64 . V_95 ;
F_73 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_215 ( struct V_57 * V_58 , T_1 * V_420 ,
T_7 V_421 )
{
struct V_118 * V_118 = F_191 ( V_58 ) ;
struct V_141 * V_142 ;
if ( V_58 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_58 -> V_128 )
return - V_7 ;
V_142 = F_82 ( F_213 () , V_197 ) ;
if ( V_142 == NULL )
return - V_69 ;
if ( F_214 ( V_142 , V_58 , V_420 , V_421 ) < 0 )
F_100 () ;
return F_85 ( V_118 , V_142 , 0 , V_422 ) ;
}
static bool F_216 ( const struct V_146 * V_147 )
{
return ( bool ) F_217 ( V_147 -> V_118 ) ;
}
static int T_8 F_218 ( struct V_118 * V_118 )
{
struct V_187 * V_200 ;
struct V_423 V_424 = {
. V_425 = V_426 ,
. V_427 = F_184 ,
} ;
V_200 = F_219 ( V_118 , V_428 , & V_424 ) ;
if ( V_200 == NULL )
return - V_69 ;
V_118 -> V_134 . V_429 = V_200 ;
F_220 ( V_118 -> V_134 . V_200 , V_200 ) ;
return 0 ;
}
static void T_9 F_221 ( struct V_430 * V_431 )
{
struct V_118 * V_118 ;
F_222 (net, net_exit_list, exit_list)
F_223 ( V_118 -> V_134 . V_200 , NULL ) ;
F_224 () ;
F_222 (net, net_exit_list, exit_list)
F_225 ( V_118 -> V_134 . V_429 ) ;
}
static int T_10 F_226 ( void )
{
int V_432 ;
F_197 ( V_433 L_5 ) ;
V_432 = F_227 ( & V_434 ) ;
if ( V_432 < 0 )
return V_432 ;
V_432 = F_228 ( & V_435 ) ;
if ( V_432 < 0 )
F_229 ( & V_434 ) ;
return V_432 ;
}
static void T_11 F_230 ( void )
{
F_231 ( & V_435 ) ;
F_229 ( & V_434 ) ;
}
