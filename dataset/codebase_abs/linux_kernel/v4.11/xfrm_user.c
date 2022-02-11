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
if ( F_3 ( V_85 ) < V_87 ||
F_12 ( V_84 ) != V_87 ||
V_84 -> V_30 != V_86 -> V_30 )
return - V_7 ;
if ( V_86 -> V_37 > V_86 -> V_30 * sizeof( V_88 ) * 8 )
return - V_7 ;
return 0 ;
}
static int F_26 ( struct V_26 * * V_84 ,
struct V_26 * * V_89 ,
struct V_1 * V_59 )
{
struct V_26 * V_24 , * V_90 , * V_86 ;
int V_91 , V_87 ;
if ( ! V_59 )
return 0 ;
V_86 = F_2 ( V_59 ) ;
V_91 = F_12 ( V_86 ) ;
V_87 = F_3 ( V_59 ) >= V_91 ? V_91 : sizeof( * V_86 ) ;
V_24 = F_27 ( V_91 , V_68 ) ;
if ( ! V_24 )
return - V_69 ;
V_90 = F_27 ( V_91 , V_68 ) ;
if ( ! V_90 ) {
F_28 ( V_24 ) ;
return - V_69 ;
}
memcpy ( V_24 , V_86 , V_87 ) ;
memcpy ( V_90 , V_86 , V_87 ) ;
* V_84 = V_24 ;
* V_89 = V_90 ;
return 0 ;
}
static inline int F_29 ( struct V_92 * V_93 )
{
int V_21 = 0 ;
if ( V_93 ) {
V_21 += sizeof( struct V_19 ) ;
V_21 += V_93 -> V_22 ;
}
return V_21 ;
}
static void F_30 ( struct V_57 * V_58 , struct V_23 * V_24 )
{
memcpy ( & V_58 -> V_33 , & V_24 -> V_33 , sizeof( V_58 -> V_33 ) ) ;
memcpy ( & V_58 -> V_94 , & V_24 -> V_94 , sizeof( V_58 -> V_94 ) ) ;
memcpy ( & V_58 -> V_95 , & V_24 -> V_95 , sizeof( V_58 -> V_95 ) ) ;
V_58 -> V_64 . V_46 = V_24 -> V_46 ;
V_58 -> V_64 . V_37 = F_31 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_58 -> V_64 . V_96 = V_24 -> V_96 ;
V_58 -> V_64 . V_39 = V_24 -> V_39 ;
memcpy ( & V_58 -> V_64 . V_97 , & V_24 -> V_97 , sizeof( V_58 -> V_64 . V_97 ) ) ;
V_58 -> V_64 . V_28 = V_24 -> V_28 ;
if ( ! V_58 -> V_94 . V_39 && ! ( V_24 -> V_28 & V_98 ) )
V_58 -> V_94 . V_39 = V_24 -> V_39 ;
}
static void F_32 ( struct V_57 * V_58 , struct V_1 * * V_2 ,
int V_99 )
{
struct V_1 * V_85 = V_2 [ V_100 ] ;
struct V_1 * V_101 = V_99 ? V_2 [ V_25 ] : NULL ;
struct V_1 * V_102 = V_2 [ V_103 ] ;
struct V_1 * V_104 = V_2 [ V_105 ] ;
struct V_1 * V_4 = V_2 [ V_106 ] ;
if ( V_101 ) {
struct V_26 * V_84 ;
V_84 = F_2 ( V_101 ) ;
memcpy ( V_58 -> V_84 , V_84 ,
F_12 ( V_84 ) ) ;
memcpy ( V_58 -> V_89 , V_84 ,
F_12 ( V_84 ) ) ;
}
if ( V_85 ) {
struct V_107 * V_108 ;
V_108 = F_2 ( V_85 ) ;
memcpy ( & V_58 -> V_108 , V_108 , sizeof( * V_108 ) ) ;
memcpy ( & V_58 -> V_109 , V_108 , sizeof( * V_108 ) ) ;
}
if ( V_102 ) {
struct V_110 * V_111 ;
V_111 = F_2 ( V_102 ) ;
V_58 -> V_112 . V_113 = V_111 -> V_113 ;
V_58 -> V_112 . V_114 = V_111 -> V_114 ;
V_58 -> V_112 . V_115 = V_111 -> V_115 ;
V_58 -> V_112 . V_116 = V_111 -> V_116 ;
}
if ( V_104 )
V_58 -> V_117 = F_33 ( V_104 ) ;
if ( V_4 )
V_58 -> V_118 = F_33 ( V_4 ) ;
}
static struct V_57 * F_34 ( struct V_119 * V_119 ,
struct V_23 * V_24 ,
struct V_1 * * V_2 ,
int * V_120 )
{
struct V_57 * V_58 = F_35 ( V_119 ) ;
int V_38 = - V_69 ;
if ( ! V_58 )
goto V_121;
F_30 ( V_58 , V_24 ) ;
if ( V_2 [ V_122 ] )
V_58 -> V_64 . V_123 = F_33 ( V_2 [ V_122 ] ) ;
if ( ( V_38 = F_23 ( V_58 , V_2 [ V_15 ] ) ) )
goto error;
if ( ( V_38 = F_22 ( & V_58 -> V_124 , & V_58 -> V_64 . V_125 ,
V_2 [ V_13 ] ) ) )
goto error;
if ( ! V_58 -> V_64 . V_125 ) {
if ( ( V_38 = F_19 ( & V_58 -> V_124 , & V_58 -> V_64 . V_125 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_38 = F_16 ( V_58 , V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_38 = F_36 ( & V_58 -> V_126 , & V_58 -> V_64 . V_127 ,
V_128 ,
V_2 [ V_10 ] ) ) )
goto error;
if ( V_2 [ V_52 ] ) {
V_58 -> V_129 = F_18 ( F_2 ( V_2 [ V_52 ] ) ,
sizeof( * V_58 -> V_129 ) , V_68 ) ;
if ( V_58 -> V_129 == NULL )
goto error;
}
if ( V_2 [ V_45 ] )
V_58 -> V_130 = F_33 ( V_2 [ V_45 ] ) ;
if ( V_2 [ V_53 ] ) {
V_58 -> V_131 = F_18 ( F_2 ( V_2 [ V_53 ] ) ,
sizeof( * V_58 -> V_131 ) , V_68 ) ;
if ( V_58 -> V_131 == NULL )
goto error;
}
F_37 ( V_2 , & V_58 -> V_132 ) ;
V_38 = F_38 ( V_58 , false ) ;
if ( V_38 )
goto error;
if ( V_2 [ V_18 ] ) {
V_38 = F_39 ( V_58 ,
F_2 ( V_2 [ V_18 ] ) ) ;
if ( V_38 )
goto error;
}
if ( ( V_38 = F_26 ( & V_58 -> V_84 , & V_58 -> V_89 ,
V_2 [ V_25 ] ) ) )
goto error;
V_58 -> V_133 . V_134 = V_24 -> V_134 ;
V_58 -> V_118 = V_119 -> V_135 . V_136 ;
V_58 -> V_117 = ( V_119 -> V_135 . V_137 * V_138 ) / V_139 ;
if ( ( V_38 = F_40 ( V_58 ) ) )
goto error;
F_32 ( V_58 , V_2 , 0 ) ;
return V_58 ;
error:
V_58 -> V_133 . V_140 = V_141 ;
F_41 ( V_58 ) ;
V_121:
* V_120 = V_38 ;
return NULL ;
}
static int F_42 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_23 * V_24 = F_44 ( V_145 ) ;
struct V_57 * V_58 ;
int V_38 ;
struct V_147 V_148 ;
V_38 = F_13 ( V_24 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_58 = F_34 ( V_119 , V_24 , V_2 , & V_38 ) ;
if ( ! V_58 )
return V_38 ;
F_45 ( V_58 ) ;
if ( V_145 -> V_149 == V_150 )
V_38 = F_46 ( V_58 ) ;
else
V_38 = F_47 ( V_58 ) ;
F_48 ( V_58 , V_38 ? 0 : 1 , true ) ;
if ( V_38 < 0 ) {
V_58 -> V_133 . V_140 = V_141 ;
F_49 ( V_58 ) ;
goto V_44;
}
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_154 = V_145 -> V_149 ;
F_50 ( V_58 , & V_148 ) ;
V_44:
F_41 ( V_58 ) ;
return V_38 ;
}
static struct V_57 * F_51 ( struct V_119 * V_119 ,
struct V_155 * V_24 ,
struct V_1 * * V_2 ,
int * V_120 )
{
struct V_57 * V_58 = NULL ;
struct V_156 V_157 ;
int V_38 ;
T_3 V_132 = F_37 ( V_2 , & V_157 ) ;
if ( F_52 ( V_24 -> V_34 , V_158 ) ) {
V_38 = - V_159 ;
V_58 = F_53 ( V_119 , V_132 , & V_24 -> V_160 , V_24 -> V_49 , V_24 -> V_34 , V_24 -> V_39 ) ;
} else {
T_1 * V_97 = NULL ;
F_9 ( V_2 , V_161 , & V_97 ) ;
if ( ! V_97 ) {
V_38 = - V_7 ;
goto V_44;
}
V_38 = - V_159 ;
V_58 = F_54 ( V_119 , V_132 ,
& V_24 -> V_160 , V_97 ,
V_24 -> V_34 , V_24 -> V_39 ) ;
}
V_44:
if ( ! V_58 && V_120 )
* V_120 = V_38 ;
return V_58 ;
}
static int F_55 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_57 * V_58 ;
int V_38 = - V_159 ;
struct V_147 V_148 ;
struct V_155 * V_24 = F_44 ( V_145 ) ;
V_58 = F_51 ( V_119 , V_24 , V_2 , & V_38 ) ;
if ( V_58 == NULL )
return V_38 ;
if ( ( V_38 = F_56 ( V_58 ) ) != 0 )
goto V_44;
if ( F_57 ( V_58 ) ) {
V_38 = - V_162 ;
goto V_44;
}
V_38 = F_58 ( V_58 ) ;
if ( V_38 < 0 )
goto V_44;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_154 = V_145 -> V_149 ;
F_50 ( V_58 , & V_148 ) ;
V_44:
F_59 ( V_58 , V_38 ? 0 : 1 , true ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static void F_60 ( struct V_57 * V_58 , struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_33 , & V_58 -> V_33 , sizeof( V_24 -> V_33 ) ) ;
memcpy ( & V_24 -> V_94 , & V_58 -> V_94 , sizeof( V_24 -> V_94 ) ) ;
memcpy ( & V_24 -> V_95 , & V_58 -> V_95 , sizeof( V_24 -> V_95 ) ) ;
memcpy ( & V_24 -> V_112 , & V_58 -> V_112 , sizeof( V_24 -> V_112 ) ) ;
F_61 ( V_58 -> V_163 . V_37 , & V_24 -> V_163 . V_37 ) ;
F_61 ( V_58 -> V_163 . V_108 , & V_24 -> V_163 . V_108 ) ;
F_61 ( V_58 -> V_163 . V_164 , & V_24 -> V_163 . V_164 ) ;
memcpy ( & V_24 -> V_97 , & V_58 -> V_64 . V_97 , sizeof( V_24 -> V_97 ) ) ;
V_24 -> V_46 = V_58 -> V_64 . V_46 ;
V_24 -> V_37 = V_58 -> V_64 . V_37 ;
V_24 -> V_96 = V_58 -> V_64 . V_96 ;
V_24 -> V_39 = V_58 -> V_64 . V_39 ;
V_24 -> V_28 = V_58 -> V_64 . V_28 ;
V_24 -> V_134 = V_58 -> V_133 . V_134 ;
}
static int F_62 ( struct V_92 * V_165 , struct V_142 * V_143 )
{
struct V_19 * V_20 ;
struct V_1 * V_166 ;
int V_167 = sizeof( * V_20 ) + V_165 -> V_22 ;
V_166 = F_63 ( V_143 , V_18 , V_167 ) ;
if ( V_166 == NULL )
return - V_168 ;
V_20 = F_2 ( V_166 ) ;
V_20 -> V_169 = V_18 ;
V_20 -> V_21 = V_167 ;
V_20 -> V_170 = V_165 -> V_170 ;
V_20 -> V_171 = V_165 -> V_171 ;
V_20 -> V_22 = V_165 -> V_22 ;
memcpy ( V_20 + 1 , V_165 -> V_172 , V_165 -> V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_14 * V_78 , struct V_142 * V_143 )
{
struct V_5 * V_62 ;
struct V_1 * V_173 ;
V_173 = F_63 ( V_143 , V_8 ,
sizeof( * V_62 ) + ( V_78 -> V_76 + 7 ) / 8 ) ;
if ( ! V_173 )
return - V_168 ;
V_62 = F_2 ( V_173 ) ;
strncpy ( V_62 -> V_11 , V_78 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_80 , V_78 -> V_80 , ( V_78 -> V_76 + 7 ) / 8 ) ;
V_62 -> V_76 = V_78 -> V_76 ;
return 0 ;
}
static int F_65 ( struct V_57 * V_58 ,
struct V_23 * V_24 ,
struct V_142 * V_143 )
{
int V_174 = 0 ;
F_60 ( V_58 , V_24 ) ;
if ( V_58 -> V_64 . V_123 ) {
V_174 = F_66 ( V_143 , V_122 ,
V_58 -> V_64 . V_123 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_131 ) {
V_174 = F_67 ( V_143 , V_53 , sizeof( * V_58 -> V_131 ) , V_58 -> V_131 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_175 ) {
V_174 = F_68 ( V_143 , V_176 , V_58 -> V_175 ,
V_177 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_83 ) {
V_174 = F_67 ( V_143 , V_15 , F_8 ( V_58 -> V_83 ) , V_58 -> V_83 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_124 ) {
V_174 = F_64 ( V_58 -> V_124 , V_143 ) ;
if ( ! V_174 )
V_174 = F_67 ( V_143 , V_13 ,
F_6 ( V_58 -> V_124 ) , V_58 -> V_124 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_71 ) {
V_174 = F_67 ( V_143 , V_9 , F_4 ( V_58 -> V_71 ) , V_58 -> V_71 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_126 ) {
V_174 = F_67 ( V_143 , V_10 , sizeof( * ( V_58 -> V_126 ) ) , V_58 -> V_126 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_129 ) {
V_174 = F_67 ( V_143 , V_52 , sizeof( * V_58 -> V_129 ) , V_58 -> V_129 ) ;
if ( V_174 )
goto V_44;
}
if ( V_58 -> V_130 ) {
V_174 = F_66 ( V_143 , V_45 , V_58 -> V_130 ) ;
if ( V_174 )
goto V_44;
}
V_174 = F_69 ( V_143 , & V_58 -> V_132 ) ;
if ( V_174 )
goto V_44;
if ( V_58 -> V_84 )
V_174 = F_67 ( V_143 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
else
V_174 = F_67 ( V_143 , V_100 , sizeof( V_58 -> V_108 ) ,
& V_58 -> V_108 ) ;
if ( V_174 )
goto V_44;
if ( V_58 -> V_178 )
V_174 = F_62 ( V_58 -> V_178 , V_143 ) ;
V_44:
return V_174 ;
}
static int F_70 ( struct V_57 * V_58 , int V_179 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_142 * V_183 = V_182 -> V_183 ;
struct V_142 * V_143 = V_182 -> V_184 ;
struct V_23 * V_24 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , F_72 ( V_183 ) . V_152 , V_182 -> V_151 ,
V_150 , sizeof( * V_24 ) , V_182 -> V_185 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_24 = F_44 ( V_145 ) ;
V_38 = F_65 ( V_58 , V_24 , V_143 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_75 ( struct V_186 * V_187 )
{
struct V_188 * V_189 = (struct V_188 * ) & V_187 -> args [ 1 ] ;
struct V_190 * V_146 = V_187 -> V_143 -> V_146 ;
struct V_119 * V_119 = F_43 ( V_146 ) ;
if ( V_187 -> args [ 0 ] )
F_76 ( V_189 , V_119 ) ;
return 0 ;
}
static int F_77 ( struct V_142 * V_143 , struct V_186 * V_187 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_188 * V_189 = (struct V_188 * ) & V_187 -> args [ 1 ] ;
struct V_181 V_191 ;
F_78 ( sizeof( struct V_188 ) >
sizeof( V_187 -> args ) - sizeof( V_187 -> args [ 0 ] ) ) ;
V_191 . V_183 = V_187 -> V_143 ;
V_191 . V_184 = V_143 ;
V_191 . V_151 = V_187 -> V_145 -> V_151 ;
V_191 . V_185 = V_192 ;
if ( ! V_187 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_193 + 1 ] ;
struct V_194 * V_195 = NULL ;
T_2 V_34 = 0 ;
int V_38 ;
V_38 = F_79 ( V_187 -> V_145 , 0 , V_2 , V_193 ,
V_196 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_197 ] ) {
V_195 = F_18 ( F_2 ( V_2 [ V_197 ] ) ,
sizeof( * V_195 ) , V_68 ) ;
if ( V_195 == NULL )
return - V_69 ;
}
if ( V_2 [ V_198 ] )
V_34 = F_80 ( V_2 [ V_198 ] ) ;
F_81 ( V_189 , V_34 , V_195 ) ;
V_187 -> args [ 0 ] = 1 ;
}
( void ) V_188 ( V_119 , V_189 , F_70 , & V_191 ) ;
return V_143 -> V_21 ;
}
static struct V_142 * F_82 ( struct V_142 * V_183 ,
struct V_57 * V_58 , T_3 V_134 )
{
struct V_181 V_191 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_83 ( V_199 , V_200 ) ;
if ( ! V_143 )
return F_84 ( - V_69 ) ;
V_191 . V_183 = V_183 ;
V_191 . V_184 = V_143 ;
V_191 . V_151 = V_134 ;
V_191 . V_185 = 0 ;
V_38 = F_70 ( V_58 , 0 , & V_191 ) ;
if ( V_38 ) {
F_85 ( V_143 ) ;
return F_84 ( V_38 ) ;
}
return V_143 ;
}
static inline int F_86 ( struct V_119 * V_119 , struct V_142 * V_143 ,
T_3 V_201 , unsigned int V_202 )
{
struct V_190 * V_203 = F_87 ( V_119 -> V_135 . V_203 ) ;
if ( V_203 )
return F_88 ( V_203 , V_143 , V_201 , V_202 , V_200 ) ;
else
return - 1 ;
}
static inline T_4 F_89 ( void )
{
return F_90 ( 4 )
+ F_91 ( sizeof( struct V_204 ) )
+ F_91 ( sizeof( struct V_205 ) )
+ F_91 ( sizeof( struct V_206 ) )
+ F_91 ( sizeof( struct V_206 ) ) ;
}
static int F_92 ( struct V_142 * V_143 , struct V_119 * V_119 ,
T_3 V_152 , T_3 V_134 , T_3 V_28 )
{
struct V_207 V_208 ;
struct V_204 V_209 ;
struct V_205 V_210 ;
struct V_206 V_211 , V_212 ;
struct V_144 * V_145 ;
int V_38 ;
T_3 * V_213 ;
unsigned V_214 ;
V_145 = F_71 ( V_143 , V_152 , V_134 , V_215 , sizeof( T_3 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_213 = F_44 ( V_145 ) ;
* V_213 = V_28 ;
F_93 ( V_119 , & V_208 ) ;
V_209 . V_216 = V_208 . V_216 ;
V_209 . V_217 = V_208 . V_217 ;
V_209 . V_218 = V_208 . V_218 ;
V_209 . V_219 = V_208 . V_219 ;
V_209 . V_220 = V_208 . V_220 ;
V_209 . V_221 = V_208 . V_221 ;
V_210 . V_222 = V_208 . V_222 ;
V_210 . V_223 = V_208 . V_223 ;
do {
V_214 = F_94 ( & V_119 -> V_135 . V_224 . V_225 ) ;
V_211 . V_226 = V_119 -> V_135 . V_224 . V_227 ;
V_211 . V_228 = V_119 -> V_135 . V_224 . V_229 ;
V_212 . V_226 = V_119 -> V_135 . V_224 . V_230 ;
V_212 . V_228 = V_119 -> V_135 . V_224 . V_231 ;
} while ( F_95 ( & V_119 -> V_135 . V_224 . V_225 , V_214 ) );
V_38 = F_67 ( V_143 , V_232 , sizeof( V_209 ) , & V_209 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_143 , V_233 , sizeof( V_210 ) , & V_210 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_143 , V_234 , sizeof( V_211 ) , & V_211 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_143 , V_235 , sizeof( V_212 ) , & V_212 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_96 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_206 * V_236 = NULL ;
struct V_206 * V_237 = NULL ;
if ( V_2 [ V_234 ] ) {
struct V_1 * V_59 = V_2 [ V_234 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_236 ) )
return - V_7 ;
V_236 = F_2 ( V_59 ) ;
if ( V_236 -> V_226 > 32 || V_236 -> V_228 > 32 )
return - V_7 ;
}
if ( V_2 [ V_235 ] ) {
struct V_1 * V_59 = V_2 [ V_235 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_237 ) )
return - V_7 ;
V_237 = F_2 ( V_59 ) ;
if ( V_237 -> V_226 > 128 || V_237 -> V_228 > 128 )
return - V_7 ;
}
if ( V_236 || V_237 ) {
F_97 ( & V_119 -> V_135 . V_224 . V_225 ) ;
if ( V_236 ) {
V_119 -> V_135 . V_224 . V_227 = V_236 -> V_226 ;
V_119 -> V_135 . V_224 . V_229 = V_236 -> V_228 ;
}
if ( V_237 ) {
V_119 -> V_135 . V_224 . V_230 = V_237 -> V_226 ;
V_119 -> V_135 . V_224 . V_231 = V_237 -> V_228 ;
}
F_98 ( & V_119 -> V_135 . V_224 . V_225 ) ;
F_99 ( V_119 ) ;
}
return 0 ;
}
static int F_100 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_142 * V_238 ;
T_3 * V_28 = F_44 ( V_145 ) ;
T_3 V_239 = F_72 ( V_143 ) . V_152 ;
T_3 V_134 = V_145 -> V_151 ;
V_238 = F_83 ( F_89 () , V_200 ) ;
if ( V_238 == NULL )
return - V_69 ;
if ( F_92 ( V_238 , V_119 , V_239 , V_134 , * V_28 ) < 0 )
F_101 () ;
return F_102 ( V_119 -> V_135 . V_203 , V_238 , V_239 ) ;
}
static inline T_4 F_103 ( void )
{
return F_90 ( 4 )
+ F_91 ( sizeof( struct V_240 ) )
+ F_91 ( 4 ) ;
}
static int F_104 ( struct V_142 * V_143 , struct V_119 * V_119 ,
T_3 V_152 , T_3 V_134 , T_3 V_28 )
{
struct V_241 V_208 ;
struct V_240 V_242 ;
struct V_144 * V_145 ;
int V_38 ;
T_3 * V_213 ;
V_145 = F_71 ( V_143 , V_152 , V_134 , V_243 , sizeof( T_3 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_213 = F_44 ( V_145 ) ;
* V_213 = V_28 ;
F_105 ( V_119 , & V_208 ) ;
V_242 . V_244 = V_208 . V_244 ;
V_242 . V_245 = V_208 . V_245 ;
V_38 = F_66 ( V_143 , V_246 , V_208 . V_247 ) ;
if ( ! V_38 )
V_38 = F_67 ( V_143 , V_248 , sizeof( V_242 ) , & V_242 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_106 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_142 * V_238 ;
T_3 * V_28 = F_44 ( V_145 ) ;
T_3 V_239 = F_72 ( V_143 ) . V_152 ;
T_3 V_134 = V_145 -> V_151 ;
V_238 = F_83 ( F_103 () , V_200 ) ;
if ( V_238 == NULL )
return - V_69 ;
if ( F_104 ( V_238 , V_119 , V_239 , V_134 , * V_28 ) < 0 )
F_101 () ;
return F_102 ( V_119 -> V_135 . V_203 , V_238 , V_239 ) ;
}
static int F_107 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_155 * V_24 = F_44 ( V_145 ) ;
struct V_57 * V_58 ;
struct V_142 * V_249 ;
int V_38 = - V_159 ;
V_58 = F_51 ( V_119 , V_24 , V_2 , & V_38 ) ;
if ( V_58 == NULL )
goto V_250;
V_249 = F_82 ( V_143 , V_58 , V_145 -> V_151 ) ;
if ( F_108 ( V_249 ) ) {
V_38 = F_109 ( V_249 ) ;
} else {
V_38 = F_102 ( V_119 -> V_135 . V_203 , V_249 , F_72 ( V_143 ) . V_152 ) ;
}
F_41 ( V_58 ) ;
V_250:
return V_38 ;
}
static int F_110 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_57 * V_58 ;
struct V_251 * V_24 ;
struct V_142 * V_249 ;
T_1 * V_160 ;
int V_39 ;
int V_38 ;
T_3 V_132 ;
struct V_156 V_157 ;
V_24 = F_44 ( V_145 ) ;
V_38 = F_111 ( V_24 -> V_191 . V_33 . V_34 , V_24 -> V_252 , V_24 -> V_253 ) ;
if ( V_38 )
goto V_250;
V_39 = V_24 -> V_191 . V_39 ;
V_160 = & V_24 -> V_191 . V_33 . V_160 ;
V_58 = NULL ;
V_132 = F_37 ( V_2 , & V_157 ) ;
if ( V_24 -> V_191 . V_134 ) {
V_58 = F_112 ( V_119 , V_132 , V_24 -> V_191 . V_134 ) ;
if ( V_58 && ! F_113 ( & V_58 -> V_33 . V_160 , V_160 , V_39 ) ) {
F_41 ( V_58 ) ;
V_58 = NULL ;
}
}
if ( ! V_58 )
V_58 = F_114 ( V_119 , & V_157 , V_24 -> V_191 . V_46 , V_24 -> V_191 . V_96 ,
V_24 -> V_191 . V_33 . V_34 , V_160 ,
& V_24 -> V_191 . V_97 , 1 ,
V_39 ) ;
V_38 = - V_254 ;
if ( V_58 == NULL )
goto V_250;
V_38 = F_115 ( V_58 , V_24 -> V_252 , V_24 -> V_253 ) ;
if ( V_38 )
goto V_44;
V_249 = F_82 ( V_143 , V_58 , V_145 -> V_151 ) ;
if ( F_108 ( V_249 ) ) {
V_38 = F_109 ( V_249 ) ;
goto V_44;
}
V_38 = F_102 ( V_119 -> V_135 . V_203 , V_249 , F_72 ( V_143 ) . V_152 ) ;
V_44:
F_41 ( V_58 ) ;
V_250:
return V_38 ;
}
static int F_116 ( T_2 V_255 )
{
switch ( V_255 ) {
case V_256 :
case V_257 :
case V_258 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_117 ( T_2 type )
{
switch ( type ) {
case V_259 :
#ifdef F_118
case V_260 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_119 ( struct V_261 * V_24 )
{
int V_174 ;
switch ( V_24 -> V_262 ) {
case V_263 :
case V_264 :
case V_265 :
case V_266 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_267 ) {
case V_268 :
case V_269 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_94 . V_39 ) {
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
V_174 = F_116 ( V_24 -> V_255 ) ;
if ( V_174 )
return V_174 ;
if ( V_24 -> V_270 && ( ( V_24 -> V_270 & V_271 ) != V_24 -> V_255 ) )
return - V_7 ;
return 0 ;
}
static int F_120 ( struct V_272 * V_273 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_121 ( & V_273 -> V_178 , V_20 , V_68 ) ;
}
static void F_122 ( struct V_272 * V_274 , struct V_275 * V_276 ,
int V_277 )
{
int V_278 ;
V_274 -> V_279 = V_277 ;
for ( V_278 = 0 ; V_278 < V_277 ; V_278 ++ , V_276 ++ ) {
struct V_280 * V_281 = & V_274 -> V_282 [ V_278 ] ;
memcpy ( & V_281 -> V_33 , & V_276 -> V_33 , sizeof( struct V_283 ) ) ;
memcpy ( & V_281 -> V_97 , & V_276 -> V_97 ,
sizeof( T_1 ) ) ;
V_281 -> V_96 = V_276 -> V_96 ;
V_281 -> V_46 = V_276 -> V_46 ;
V_281 -> V_262 = V_276 -> V_262 ;
V_281 -> V_284 = V_276 -> V_284 ;
V_281 -> V_285 = V_276 -> V_285 ;
V_281 -> V_286 = V_276 -> V_286 ;
V_281 -> V_287 = V_276 -> V_287 ;
V_281 -> V_288 = ! ~ ( V_281 -> V_285 & V_281 -> V_286 & V_281 -> V_287 ) ;
V_281 -> V_289 = V_276 -> V_39 ;
}
}
static int F_123 ( int V_277 , struct V_275 * V_276 , T_5 V_39 )
{
int V_278 ;
if ( V_277 > V_290 )
return - V_7 ;
for ( V_278 = 0 ; V_278 < V_277 ; V_278 ++ ) {
if ( ! V_276 [ V_278 ] . V_39 )
V_276 [ V_278 ] . V_39 = V_39 ;
switch ( V_276 [ V_278 ] . V_39 ) {
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
static int F_124 ( struct V_272 * V_273 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_291 ] ;
if ( ! V_4 ) {
V_273 -> V_279 = 0 ;
} else {
struct V_275 * V_292 = F_2 ( V_4 ) ;
int V_277 = F_3 ( V_4 ) / sizeof( * V_292 ) ;
int V_38 ;
V_38 = F_123 ( V_277 , V_292 , V_273 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_122 ( V_273 , V_292 , V_277 ) ;
}
return 0 ;
}
static int F_125 ( T_2 * V_293 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_294 ] ;
struct V_295 * V_296 ;
T_2 type = V_259 ;
int V_38 ;
if ( V_4 ) {
V_296 = F_2 ( V_4 ) ;
type = V_296 -> type ;
}
V_38 = F_117 ( type ) ;
if ( V_38 )
return V_38 ;
* V_293 = type ;
return 0 ;
}
static void F_126 ( struct V_272 * V_274 , struct V_261 * V_24 )
{
V_274 -> V_297 = V_24 -> V_297 ;
V_274 -> V_270 = V_24 -> V_270 ;
memcpy ( & V_274 -> V_298 , & V_24 -> V_94 , sizeof( V_274 -> V_298 ) ) ;
memcpy ( & V_274 -> V_95 , & V_24 -> V_95 , sizeof( V_274 -> V_95 ) ) ;
V_274 -> V_267 = V_24 -> V_267 ;
V_274 -> V_28 = V_24 -> V_28 ;
V_274 -> V_39 = V_24 -> V_94 . V_39 ;
}
static void F_127 ( struct V_272 * V_274 , struct V_261 * V_24 , int V_255 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_94 , & V_274 -> V_298 , sizeof( V_24 -> V_94 ) ) ;
memcpy ( & V_24 -> V_95 , & V_274 -> V_95 , sizeof( V_24 -> V_95 ) ) ;
memcpy ( & V_24 -> V_112 , & V_274 -> V_112 , sizeof( V_24 -> V_112 ) ) ;
V_24 -> V_297 = V_274 -> V_297 ;
V_24 -> V_270 = V_274 -> V_270 ;
V_24 -> V_94 . V_39 = V_274 -> V_39 ;
V_24 -> V_255 = V_255 ;
V_24 -> V_267 = V_274 -> V_267 ;
V_24 -> V_28 = V_274 -> V_28 ;
V_24 -> V_262 = V_263 ;
}
static struct V_272 * F_128 ( struct V_119 * V_119 , struct V_261 * V_24 , struct V_1 * * V_2 , int * V_120 )
{
struct V_272 * V_274 = F_129 ( V_119 , V_68 ) ;
int V_38 ;
if ( ! V_274 ) {
* V_120 = - V_69 ;
return NULL ;
}
F_126 ( V_274 , V_24 ) ;
V_38 = F_125 ( & V_274 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_124 ( V_274 , V_2 ) ) )
V_38 = F_120 ( V_274 , V_2 ) ;
if ( V_38 )
goto error;
F_37 ( V_2 , & V_274 -> V_132 ) ;
return V_274 ;
error:
* V_120 = V_38 ;
V_274 -> V_189 . V_299 = 1 ;
F_130 ( V_274 ) ;
return NULL ;
}
static int F_131 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_261 * V_24 = F_44 ( V_145 ) ;
struct V_272 * V_274 ;
struct V_147 V_148 ;
int V_38 ;
int V_300 ;
V_38 = F_119 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_274 = F_128 ( V_119 , V_24 , V_2 , & V_38 ) ;
if ( ! V_274 )
return V_38 ;
V_300 = V_145 -> V_149 == V_301 ;
V_38 = F_132 ( V_24 -> V_255 , V_274 , V_300 ) ;
F_133 ( V_274 , V_38 ? 0 : 1 , true ) ;
if ( V_38 ) {
F_134 ( V_274 -> V_178 ) ;
F_28 ( V_274 ) ;
return V_38 ;
}
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
F_135 ( V_274 , V_24 -> V_255 , & V_148 ) ;
F_136 ( V_274 ) ;
return 0 ;
}
static int F_137 ( struct V_272 * V_274 , struct V_142 * V_143 )
{
struct V_275 V_302 [ V_290 ] ;
int V_278 ;
if ( V_274 -> V_279 == 0 )
return 0 ;
for ( V_278 = 0 ; V_278 < V_274 -> V_279 ; V_278 ++ ) {
struct V_275 * V_86 = & V_302 [ V_278 ] ;
struct V_280 * V_303 = & V_274 -> V_282 [ V_278 ] ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
memcpy ( & V_86 -> V_33 , & V_303 -> V_33 , sizeof( V_86 -> V_33 ) ) ;
V_86 -> V_39 = V_303 -> V_289 ;
memcpy ( & V_86 -> V_97 , & V_303 -> V_97 , sizeof( V_86 -> V_97 ) ) ;
V_86 -> V_96 = V_303 -> V_96 ;
V_86 -> V_46 = V_303 -> V_46 ;
V_86 -> V_262 = V_303 -> V_262 ;
V_86 -> V_284 = V_303 -> V_284 ;
V_86 -> V_285 = V_303 -> V_285 ;
V_86 -> V_286 = V_303 -> V_286 ;
V_86 -> V_287 = V_303 -> V_287 ;
}
return F_67 ( V_143 , V_291 ,
sizeof( struct V_275 ) * V_274 -> V_279 , V_302 ) ;
}
static inline int F_138 ( struct V_57 * V_58 , struct V_142 * V_143 )
{
if ( V_58 -> V_178 ) {
return F_62 ( V_58 -> V_178 , V_143 ) ;
}
return 0 ;
}
static inline int F_139 ( struct V_272 * V_274 , struct V_142 * V_143 )
{
if ( V_274 -> V_178 )
return F_62 ( V_274 -> V_178 , V_143 ) ;
return 0 ;
}
static inline T_4 F_140 ( void )
{
#ifdef F_118
return F_91 ( sizeof( struct V_295 ) ) ;
#else
return 0 ;
#endif
}
static int F_141 ( T_2 type , struct V_142 * V_143 )
{
struct V_295 V_296 = {
. type = type ,
} ;
return F_67 ( V_143 , V_294 , sizeof( V_296 ) , & V_296 ) ;
}
static inline int F_141 ( T_2 type , struct V_142 * V_143 )
{
return 0 ;
}
static int F_142 ( struct V_272 * V_274 , int V_255 , int V_179 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_261 * V_24 ;
struct V_142 * V_183 = V_182 -> V_183 ;
struct V_142 * V_143 = V_182 -> V_184 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , F_72 ( V_183 ) . V_152 , V_182 -> V_151 ,
V_301 , sizeof( * V_24 ) , V_182 -> V_185 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_24 = F_44 ( V_145 ) ;
F_127 ( V_274 , V_24 , V_255 ) ;
V_38 = F_137 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_139 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_274 -> type , V_143 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_143 , & V_274 -> V_132 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_143 ( struct V_186 * V_187 )
{
struct V_304 * V_189 = (struct V_304 * ) & V_187 -> args [ 1 ] ;
struct V_119 * V_119 = F_43 ( V_187 -> V_143 -> V_146 ) ;
F_144 ( V_189 , V_119 ) ;
return 0 ;
}
static int F_145 ( struct V_142 * V_143 , struct V_186 * V_187 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_304 * V_189 = (struct V_304 * ) & V_187 -> args [ 1 ] ;
struct V_181 V_191 ;
F_78 ( sizeof( struct V_304 ) >
sizeof( V_187 -> args ) - sizeof( V_187 -> args [ 0 ] ) ) ;
V_191 . V_183 = V_187 -> V_143 ;
V_191 . V_184 = V_143 ;
V_191 . V_151 = V_187 -> V_145 -> V_151 ;
V_191 . V_185 = V_192 ;
if ( ! V_187 -> args [ 0 ] ) {
V_187 -> args [ 0 ] = 1 ;
F_146 ( V_189 , V_305 ) ;
}
( void ) V_304 ( V_119 , V_189 , F_142 , & V_191 ) ;
return V_143 -> V_21 ;
}
static struct V_142 * F_147 ( struct V_142 * V_183 ,
struct V_272 * V_274 ,
int V_255 , T_3 V_134 )
{
struct V_181 V_191 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_83 ( V_199 , V_68 ) ;
if ( ! V_143 )
return F_84 ( - V_69 ) ;
V_191 . V_183 = V_183 ;
V_191 . V_184 = V_143 ;
V_191 . V_151 = V_134 ;
V_191 . V_185 = 0 ;
V_38 = F_142 ( V_274 , V_255 , 0 , & V_191 ) ;
if ( V_38 ) {
F_85 ( V_143 ) ;
return F_84 ( V_38 ) ;
}
return V_143 ;
}
static int F_148 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_272 * V_274 ;
struct V_306 * V_24 ;
T_2 type = V_259 ;
int V_38 ;
struct V_147 V_148 ;
int V_307 ;
struct V_156 V_157 ;
T_3 V_132 = F_37 ( V_2 , & V_157 ) ;
V_24 = F_44 ( V_145 ) ;
V_307 = V_145 -> V_149 == V_308 ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_116 ( V_24 -> V_255 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_270 )
V_274 = F_149 ( V_119 , V_132 , type , V_24 -> V_255 , V_24 -> V_270 , V_307 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_92 * V_309 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_309 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_121 ( & V_309 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_274 = F_150 ( V_119 , V_132 , type , V_24 -> V_255 , & V_24 -> V_94 ,
V_309 , V_307 , & V_38 ) ;
F_134 ( V_309 ) ;
}
if ( V_274 == NULL )
return - V_254 ;
if ( ! V_307 ) {
struct V_142 * V_249 ;
V_249 = F_147 ( V_143 , V_274 , V_24 -> V_255 , V_145 -> V_151 ) ;
if ( F_108 ( V_249 ) ) {
V_38 = F_109 ( V_249 ) ;
} else {
V_38 = F_102 ( V_119 -> V_135 . V_203 , V_249 ,
F_72 ( V_143 ) . V_152 ) ;
}
} else {
F_151 ( V_274 , V_38 ? 0 : 1 , true ) ;
if ( V_38 != 0 )
goto V_44;
V_148 . V_310 . V_311 = V_24 -> V_270 ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
F_135 ( V_274 , V_24 -> V_255 , & V_148 ) ;
}
V_44:
F_136 ( V_274 ) ;
if ( V_307 && V_38 == 0 )
F_152 ( V_119 ) ;
return V_38 ;
}
static int F_153 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_147 V_148 ;
struct V_312 * V_24 = F_44 ( V_145 ) ;
int V_38 ;
V_38 = F_154 ( V_119 , V_24 -> V_34 , true ) ;
if ( V_38 ) {
if ( V_38 == - V_159 )
return 0 ;
return V_38 ;
}
V_148 . V_310 . V_34 = V_24 -> V_34 ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_119 = V_119 ;
F_50 ( NULL , & V_148 ) ;
return 0 ;
}
static inline T_4 F_155 ( struct V_57 * V_58 )
{
T_4 V_313 = V_58 -> V_84 ?
F_12 ( V_58 -> V_84 ) :
sizeof( struct V_107 ) ;
return F_90 ( sizeof( struct V_314 ) )
+ F_91 ( V_313 )
+ F_156 ( sizeof( struct V_110 ) )
+ F_91 ( sizeof( struct V_156 ) )
+ F_91 ( 4 )
+ F_91 ( 4 ) ;
}
static int F_157 ( struct V_142 * V_143 , struct V_57 * V_58 , const struct V_147 * V_148 )
{
struct V_314 * V_33 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_315 , sizeof( * V_33 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_33 = F_44 ( V_145 ) ;
memcpy ( & V_33 -> V_316 . V_160 , & V_58 -> V_33 . V_160 , sizeof( V_58 -> V_33 . V_160 ) ) ;
V_33 -> V_316 . V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_316 . V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_316 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_97 , & V_58 -> V_64 . V_97 , sizeof( V_58 -> V_64 . V_97 ) ) ;
V_33 -> V_96 = V_58 -> V_64 . V_96 ;
V_33 -> V_28 = V_148 -> V_310 . V_317 ;
if ( V_58 -> V_84 ) {
V_38 = F_67 ( V_143 , V_25 ,
F_12 ( V_58 -> V_84 ) ,
V_58 -> V_84 ) ;
} else {
V_38 = F_67 ( V_143 , V_100 , sizeof( V_58 -> V_108 ) ,
& V_58 -> V_108 ) ;
}
if ( V_38 )
goto V_318;
V_38 = F_158 ( V_143 , V_103 , sizeof( V_58 -> V_112 ) , & V_58 -> V_112 ,
V_177 ) ;
if ( V_38 )
goto V_318;
if ( V_33 -> V_28 & V_319 ) {
V_38 = F_66 ( V_143 , V_106 , V_58 -> V_118 ) ;
if ( V_38 )
goto V_318;
}
if ( V_33 -> V_28 & V_320 ) {
V_38 = F_66 ( V_143 , V_105 ,
V_58 -> V_117 * 10 / V_138 ) ;
if ( V_38 )
goto V_318;
}
V_38 = F_69 ( V_143 , & V_58 -> V_132 ) ;
if ( V_38 )
goto V_318;
F_74 ( V_143 , V_145 ) ;
return 0 ;
V_318:
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
static int F_159 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_57 * V_58 ;
struct V_142 * V_238 ;
int V_38 ;
struct V_147 V_148 ;
T_3 V_132 ;
struct V_156 V_157 ;
struct V_314 * V_24 = F_44 ( V_145 ) ;
struct V_155 * V_33 = & V_24 -> V_316 ;
V_132 = F_37 ( V_2 , & V_157 ) ;
V_58 = F_53 ( V_119 , V_132 , & V_33 -> V_160 , V_33 -> V_49 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_58 == NULL )
return - V_159 ;
V_238 = F_83 ( F_155 ( V_58 ) , V_200 ) ;
if ( V_238 == NULL ) {
F_41 ( V_58 ) ;
return - V_69 ;
}
F_160 ( & V_58 -> V_225 ) ;
V_148 . V_310 . V_317 = V_24 -> V_28 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
if ( F_157 ( V_238 , V_58 , & V_148 ) < 0 )
F_101 () ;
V_38 = F_102 ( V_119 -> V_135 . V_203 , V_238 , F_72 ( V_143 ) . V_152 ) ;
F_161 ( & V_58 -> V_225 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_162 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_57 * V_58 ;
struct V_147 V_148 ;
int V_38 = - V_7 ;
T_3 V_132 = 0 ;
struct V_156 V_157 ;
struct V_314 * V_24 = F_44 ( V_145 ) ;
struct V_1 * V_85 = V_2 [ V_100 ] ;
struct V_1 * V_101 = V_2 [ V_25 ] ;
struct V_1 * V_102 = V_2 [ V_103 ] ;
struct V_1 * V_104 = V_2 [ V_105 ] ;
struct V_1 * V_4 = V_2 [ V_106 ] ;
if ( ! V_102 && ! V_85 && ! V_101 && ! V_104 && ! V_4 )
return V_38 ;
if ( ! ( V_145 -> V_185 & V_321 ) )
return V_38 ;
V_132 = F_37 ( V_2 , & V_157 ) ;
V_58 = F_53 ( V_119 , V_132 , & V_24 -> V_316 . V_160 , V_24 -> V_316 . V_49 , V_24 -> V_316 . V_34 , V_24 -> V_316 . V_39 ) ;
if ( V_58 == NULL )
return - V_159 ;
if ( V_58 -> V_133 . V_140 != V_322 )
goto V_44;
V_38 = F_25 ( V_58 -> V_84 , V_101 ) ;
if ( V_38 )
goto V_44;
F_160 ( & V_58 -> V_225 ) ;
F_32 ( V_58 , V_2 , 1 ) ;
F_161 ( & V_58 -> V_225 ) ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_310 . V_317 = V_323 ;
F_50 ( V_58 , & V_148 ) ;
V_38 = 0 ;
V_44:
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_163 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_147 V_148 ;
T_2 type = V_259 ;
int V_38 ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_164 ( V_119 , type , true ) ;
if ( V_38 ) {
if ( V_38 == - V_159 )
return 0 ;
return V_38 ;
}
V_148 . V_310 . type = type ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_119 = V_119 ;
F_135 ( NULL , 0 , & V_148 ) ;
return 0 ;
}
static int F_165 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_272 * V_274 ;
struct V_324 * V_86 = F_44 ( V_145 ) ;
struct V_261 * V_24 = & V_86 -> V_273 ;
T_2 type = V_259 ;
int V_38 = - V_254 ;
struct V_156 V_157 ;
T_3 V_132 = F_37 ( V_2 , & V_157 ) ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_116 ( V_24 -> V_255 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_270 )
V_274 = F_149 ( V_119 , V_132 , type , V_24 -> V_255 , V_24 -> V_270 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_92 * V_309 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_309 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_121 ( & V_309 , V_20 , V_68 ) ;
if ( V_38 )
return V_38 ;
}
V_274 = F_150 ( V_119 , V_132 , type , V_24 -> V_255 ,
& V_24 -> V_94 , V_309 , 0 , & V_38 ) ;
F_134 ( V_309 ) ;
}
if ( V_274 == NULL )
return - V_254 ;
if ( F_166 ( V_274 -> V_189 . V_299 ) )
goto V_44;
V_38 = 0 ;
if ( V_86 -> V_325 ) {
F_167 ( V_274 , V_24 -> V_255 ) ;
F_151 ( V_274 , 1 , true ) ;
}
F_168 ( V_274 , V_24 -> V_255 , V_86 -> V_325 , V_145 -> V_153 ) ;
V_44:
F_136 ( V_274 ) ;
return V_38 ;
}
static int F_169 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_57 * V_58 ;
int V_38 ;
struct V_326 * V_327 = F_44 ( V_145 ) ;
struct V_23 * V_24 = & V_327 -> V_140 ;
struct V_156 V_157 ;
T_3 V_132 = F_37 ( V_2 , & V_157 ) ;
V_58 = F_53 ( V_119 , V_132 , & V_24 -> V_33 . V_160 , V_24 -> V_33 . V_49 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_254 ;
if ( V_58 == NULL )
return V_38 ;
F_160 ( & V_58 -> V_225 ) ;
V_38 = - V_7 ;
if ( V_58 -> V_133 . V_140 != V_322 )
goto V_44;
F_170 ( V_58 , V_327 -> V_325 , V_145 -> V_153 ) ;
if ( V_327 -> V_325 ) {
F_171 ( V_58 ) ;
F_59 ( V_58 , 1 , true ) ;
}
V_38 = 0 ;
V_44:
F_161 ( & V_58 -> V_225 ) ;
F_41 ( V_58 ) ;
return V_38 ;
}
static int F_172 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_272 * V_274 ;
struct V_275 * V_276 ;
int V_278 ;
struct V_1 * V_4 = V_2 [ V_291 ] ;
struct V_156 V_132 ;
struct V_328 * V_329 = F_44 ( V_145 ) ;
struct V_57 * V_58 = F_35 ( V_119 ) ;
int V_38 = - V_69 ;
if ( ! V_58 )
goto V_330;
F_37 ( V_2 , & V_132 ) ;
V_38 = F_119 ( & V_329 -> V_331 ) ;
if ( V_38 )
goto V_332;
V_274 = F_128 ( V_119 , & V_329 -> V_331 , V_2 , & V_38 ) ;
if ( ! V_274 )
goto V_332;
memcpy ( & V_58 -> V_33 , & V_329 -> V_33 , sizeof( V_329 -> V_33 ) ) ;
memcpy ( & V_58 -> V_64 . V_97 , & V_329 -> V_97 , sizeof( V_329 -> V_97 ) ) ;
memcpy ( & V_58 -> V_94 , & V_329 -> V_94 , sizeof( V_329 -> V_94 ) ) ;
V_274 -> V_132 . V_157 = V_58 -> V_132 . V_157 = V_132 . V_157 ;
V_274 -> V_132 . V_333 = V_58 -> V_132 . V_333 = V_132 . V_333 ;
V_276 = F_2 ( V_4 ) ;
for ( V_278 = 0 ; V_278 < V_274 -> V_279 ; V_278 ++ , V_276 ++ ) {
struct V_280 * V_281 = & V_274 -> V_282 [ V_278 ] ;
memcpy ( & V_58 -> V_33 , & V_281 -> V_33 , sizeof( V_58 -> V_33 ) ) ;
V_58 -> V_64 . V_46 = V_281 -> V_46 ;
V_58 -> V_64 . V_96 = V_281 -> V_96 ;
V_58 -> V_64 . V_39 = V_276 -> V_39 ;
V_281 -> V_285 = V_329 -> V_285 ;
V_281 -> V_286 = V_329 -> V_286 ;
V_281 -> V_287 = V_329 -> V_287 ;
V_38 = F_173 ( V_58 , V_281 , V_274 ) ;
}
F_28 ( V_58 ) ;
F_28 ( V_274 ) ;
return 0 ;
V_332:
F_28 ( V_58 ) ;
V_330:
return V_38 ;
}
static int F_174 ( struct V_334 * V_335 ,
struct V_336 * V_337 ,
struct V_1 * * V_2 , int * V_338 )
{
struct V_1 * V_4 = V_2 [ V_339 ] ;
struct V_340 * V_341 ;
int V_278 , V_342 ;
if ( V_337 != NULL ) {
struct V_343 * V_344 ;
V_344 = F_2 ( V_2 [ V_345 ] ) ;
memcpy ( & V_337 -> V_346 , & V_344 -> V_346 , sizeof( V_337 -> V_346 ) ) ;
memcpy ( & V_337 -> V_347 , & V_344 -> V_347 , sizeof( V_337 -> V_347 ) ) ;
V_337 -> V_39 = V_344 -> V_39 ;
V_337 -> V_348 = V_344 -> V_348 ;
}
V_341 = F_2 ( V_4 ) ;
V_342 = F_3 ( V_4 ) / sizeof( * V_341 ) ;
if ( V_342 <= 0 || V_342 > V_290 )
return - V_7 ;
for ( V_278 = 0 ; V_278 < V_342 ; V_278 ++ , V_341 ++ , V_335 ++ ) {
memcpy ( & V_335 -> V_349 , & V_341 -> V_349 , sizeof( V_335 -> V_349 ) ) ;
memcpy ( & V_335 -> V_350 , & V_341 -> V_350 , sizeof( V_335 -> V_350 ) ) ;
memcpy ( & V_335 -> V_351 , & V_341 -> V_351 , sizeof( V_335 -> V_351 ) ) ;
memcpy ( & V_335 -> V_352 , & V_341 -> V_352 , sizeof( V_335 -> V_352 ) ) ;
V_335 -> V_34 = V_341 -> V_34 ;
V_335 -> V_46 = V_341 -> V_46 ;
V_335 -> V_96 = V_341 -> V_96 ;
V_335 -> V_353 = V_341 -> V_353 ;
V_335 -> V_354 = V_341 -> V_354 ;
}
* V_338 = V_278 ;
return 0 ;
}
static int F_175 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_306 * V_355 = F_44 ( V_145 ) ;
struct V_334 V_157 [ V_290 ] ;
struct V_336 V_133 , * V_356 ;
T_2 type ;
int V_38 ;
int V_357 = 0 ;
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
if ( V_2 [ V_339 ] == NULL )
return - V_7 ;
V_356 = V_2 [ V_345 ] ? & V_133 : NULL ;
V_38 = F_125 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_174 ( (struct V_334 * ) V_157 , V_356 , V_2 , & V_357 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_357 )
return 0 ;
V_334 ( & V_355 -> V_94 , V_355 -> V_255 , type , V_157 , V_357 , V_356 , V_119 ) ;
return 0 ;
}
static int F_175 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
return - V_358 ;
}
static int F_176 ( const struct V_334 * V_157 , struct V_142 * V_143 )
{
struct V_340 V_341 ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_34 = V_157 -> V_34 ;
V_341 . V_46 = V_157 -> V_46 ;
V_341 . V_96 = V_157 -> V_96 ;
V_341 . V_353 = V_157 -> V_353 ;
memcpy ( & V_341 . V_349 , & V_157 -> V_349 , sizeof( V_341 . V_349 ) ) ;
memcpy ( & V_341 . V_350 , & V_157 -> V_350 , sizeof( V_341 . V_350 ) ) ;
V_341 . V_354 = V_157 -> V_354 ;
memcpy ( & V_341 . V_351 , & V_157 -> V_351 , sizeof( V_341 . V_351 ) ) ;
memcpy ( & V_341 . V_352 , & V_157 -> V_352 , sizeof( V_341 . V_352 ) ) ;
return F_67 ( V_143 , V_339 , sizeof( V_341 ) , & V_341 ) ;
}
static int F_177 ( const struct V_336 * V_337 , struct V_142 * V_143 )
{
struct V_343 V_344 ;
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
V_344 . V_39 = V_337 -> V_39 ;
V_344 . V_348 = V_337 -> V_348 ;
memcpy ( & V_344 . V_346 , & V_337 -> V_346 , sizeof( V_344 . V_346 ) ) ;
memcpy ( & V_344 . V_347 , & V_337 -> V_347 , sizeof( V_344 . V_347 ) ) ;
return F_67 ( V_143 , V_345 , sizeof( V_344 ) , & V_344 ) ;
}
static inline T_4 F_178 ( int V_342 , int V_359 )
{
return F_90 ( sizeof( struct V_306 ) )
+ ( V_359 ? F_91 ( sizeof( struct V_336 ) ) : 0 )
+ F_91 ( sizeof( struct V_340 ) * V_342 )
+ F_140 () ;
}
static int F_179 ( struct V_142 * V_143 , const struct V_334 * V_157 ,
int V_342 , const struct V_336 * V_337 ,
const struct V_360 * V_94 , T_2 V_255 , T_2 type )
{
const struct V_334 * V_361 ;
struct V_306 * V_362 ;
struct V_144 * V_145 ;
int V_278 , V_38 ;
V_145 = F_71 ( V_143 , 0 , 0 , V_363 , sizeof( * V_362 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_362 = F_44 ( V_145 ) ;
memset ( V_362 , 0 , sizeof( * V_362 ) ) ;
memcpy ( & V_362 -> V_94 , V_94 , sizeof( V_362 -> V_94 ) ) ;
V_362 -> V_255 = V_255 ;
if ( V_337 != NULL ) {
V_38 = F_177 ( V_337 , V_143 ) ;
if ( V_38 )
goto V_318;
}
V_38 = F_141 ( type , V_143 ) ;
if ( V_38 )
goto V_318;
for ( V_278 = 0 , V_361 = V_157 ; V_278 < V_342 ; V_278 ++ , V_361 ++ ) {
V_38 = F_176 ( V_361 , V_143 ) ;
if ( V_38 )
goto V_318;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
V_318:
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
static int F_180 ( const struct V_360 * V_94 , T_2 V_255 , T_2 type ,
const struct V_334 * V_157 , int V_342 ,
const struct V_336 * V_337 )
{
struct V_119 * V_119 = & V_364 ;
struct V_142 * V_143 ;
V_143 = F_83 ( F_178 ( V_342 , ! ! V_337 ) , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_179 ( V_143 , V_157 , V_342 , V_337 , V_94 , V_255 , type ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_365 ) ;
}
static int F_180 ( const struct V_360 * V_94 , T_2 V_255 , T_2 type ,
const struct V_334 * V_157 , int V_342 ,
const struct V_336 * V_337 )
{
return - V_358 ;
}
static int F_181 ( struct V_142 * V_143 , struct V_144 * V_145 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
struct V_1 * V_2 [ V_193 + 1 ] ;
const struct V_366 * V_367 ;
int type , V_38 ;
#ifdef F_182
if ( F_183 () )
return - V_368 ;
#endif
type = V_145 -> V_149 ;
if ( type > V_369 )
return - V_7 ;
type -= V_370 ;
V_367 = & V_371 [ type ] ;
if ( ! F_184 ( V_143 , V_372 ) )
return - V_162 ;
if ( ( type == ( V_373 - V_370 ) ||
type == ( V_374 - V_370 ) ) &&
( V_145 -> V_185 & V_375 ) ) {
if ( V_367 -> V_376 == NULL )
return - V_7 ;
{
struct V_377 V_148 = {
. V_376 = V_367 -> V_376 ,
. V_378 = V_367 -> V_378 ,
} ;
return F_185 ( V_119 -> V_135 . V_203 , V_143 , V_145 , & V_148 ) ;
}
}
V_38 = F_79 ( V_145 , V_379 [ type ] , V_2 ,
V_367 -> V_380 ? : V_193 ,
V_367 -> V_381 ? : V_196 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_367 -> V_382 == NULL )
return - V_7 ;
return V_367 -> V_382 ( V_143 , V_145 , V_2 ) ;
}
static void F_186 ( struct V_142 * V_143 )
{
struct V_119 * V_119 = F_43 ( V_143 -> V_146 ) ;
F_187 ( & V_119 -> V_135 . V_383 ) ;
F_188 ( V_143 , & F_181 ) ;
F_189 ( & V_119 -> V_135 . V_383 ) ;
}
static inline T_4 F_190 ( void )
{
return F_90 ( sizeof( struct V_326 ) )
+ F_91 ( sizeof( struct V_156 ) ) ;
}
static int F_191 ( struct V_142 * V_143 , struct V_57 * V_58 , const struct V_147 * V_148 )
{
struct V_326 * V_327 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , 0 , V_384 , sizeof( * V_327 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_327 = F_44 ( V_145 ) ;
F_60 ( V_58 , & V_327 -> V_140 ) ;
V_327 -> V_325 = ( V_148 -> V_310 . V_325 != 0 ) ? 1 : 0 ;
V_38 = F_69 ( V_143 , & V_58 -> V_132 ) ;
if ( V_38 )
return V_38 ;
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_192 ( struct V_57 * V_58 , const struct V_147 * V_148 )
{
struct V_119 * V_119 = F_193 ( V_58 ) ;
struct V_142 * V_143 ;
V_143 = F_83 ( F_190 () , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_191 ( V_143 , V_58 , V_148 ) < 0 ) {
F_85 ( V_143 ) ;
return - V_168 ;
}
return F_86 ( V_119 , V_143 , 0 , V_385 ) ;
}
static int F_194 ( struct V_57 * V_58 , const struct V_147 * V_148 )
{
struct V_119 * V_119 = F_193 ( V_58 ) ;
struct V_142 * V_143 ;
V_143 = F_83 ( F_155 ( V_58 ) , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_157 ( V_143 , V_58 , V_148 ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_386 ) ;
}
static int F_195 ( const struct V_147 * V_148 )
{
struct V_119 * V_119 = V_148 -> V_119 ;
struct V_312 * V_24 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_21 = F_90 ( sizeof( struct V_312 ) ) ;
V_143 = F_83 ( V_21 , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_387 , sizeof( * V_24 ) , 0 ) ;
if ( V_145 == NULL ) {
F_85 ( V_143 ) ;
return - V_168 ;
}
V_24 = F_44 ( V_145 ) ;
V_24 -> V_34 = V_148 -> V_310 . V_34 ;
F_74 ( V_143 , V_145 ) ;
return F_86 ( V_119 , V_143 , 0 , V_388 ) ;
}
static inline T_4 F_196 ( struct V_57 * V_58 )
{
T_4 V_389 = 0 ;
if ( V_58 -> V_83 )
V_389 += F_91 ( F_8 ( V_58 -> V_83 ) ) ;
if ( V_58 -> V_124 ) {
V_389 += F_91 ( sizeof( struct V_5 ) +
( V_58 -> V_124 -> V_76 + 7 ) / 8 ) ;
V_389 += F_91 ( F_6 ( V_58 -> V_124 ) ) ;
}
if ( V_58 -> V_71 )
V_389 += F_91 ( F_4 ( V_58 -> V_71 ) ) ;
if ( V_58 -> V_126 )
V_389 += F_91 ( sizeof( * V_58 -> V_126 ) ) ;
if ( V_58 -> V_129 )
V_389 += F_91 ( sizeof( * V_58 -> V_129 ) ) ;
if ( V_58 -> V_130 )
V_389 += F_91 ( sizeof( V_58 -> V_130 ) ) ;
if ( V_58 -> V_84 )
V_389 += F_91 ( F_12 ( V_58 -> V_84 ) ) ;
else
V_389 += F_91 ( sizeof( struct V_107 ) ) ;
if ( V_58 -> V_178 )
V_389 += F_91 ( sizeof( struct V_19 ) +
V_58 -> V_178 -> V_22 ) ;
if ( V_58 -> V_131 )
V_389 += F_91 ( sizeof( * V_58 -> V_131 ) ) ;
if ( V_58 -> V_64 . V_123 )
V_389 += F_91 ( sizeof( V_58 -> V_64 . V_123 ) ) ;
V_389 += F_156 ( sizeof( V_390 ) ) ;
return V_389 ;
}
static int F_197 ( struct V_57 * V_58 , const struct V_147 * V_148 )
{
struct V_119 * V_119 = F_193 ( V_58 ) ;
struct V_23 * V_24 ;
struct V_155 * V_33 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_21 = F_196 ( V_58 ) ;
int V_391 , V_38 ;
V_391 = sizeof( * V_24 ) ;
if ( V_148 -> V_154 == V_392 ) {
V_21 += F_91 ( V_391 ) ;
V_391 = sizeof( * V_33 ) ;
V_21 += F_91 ( sizeof( struct V_156 ) ) ;
}
V_21 += F_90 ( V_391 ) ;
V_143 = F_83 ( V_21 , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_148 -> V_154 , V_391 , 0 ) ;
V_38 = - V_168 ;
if ( V_145 == NULL )
goto V_393;
V_24 = F_44 ( V_145 ) ;
if ( V_148 -> V_154 == V_392 ) {
struct V_1 * V_166 ;
V_33 = F_44 ( V_145 ) ;
memcpy ( & V_33 -> V_160 , & V_58 -> V_33 . V_160 , sizeof( V_33 -> V_160 ) ) ;
V_33 -> V_49 = V_58 -> V_33 . V_49 ;
V_33 -> V_39 = V_58 -> V_64 . V_39 ;
V_33 -> V_34 = V_58 -> V_33 . V_34 ;
V_166 = F_63 ( V_143 , V_394 , sizeof( * V_24 ) ) ;
V_38 = - V_168 ;
if ( V_166 == NULL )
goto V_393;
V_24 = F_2 ( V_166 ) ;
}
V_38 = F_65 ( V_58 , V_24 , V_143 ) ;
if ( V_38 )
goto V_393;
F_74 ( V_143 , V_145 ) ;
return F_86 ( V_119 , V_143 , 0 , V_388 ) ;
V_393:
F_85 ( V_143 ) ;
return V_38 ;
}
static int F_198 ( struct V_57 * V_58 , const struct V_147 * V_148 )
{
switch ( V_148 -> V_154 ) {
case V_384 :
return F_192 ( V_58 , V_148 ) ;
case V_315 :
return F_194 ( V_58 , V_148 ) ;
case V_392 :
case V_395 :
case V_150 :
return F_197 ( V_58 , V_148 ) ;
case V_387 :
return F_195 ( V_148 ) ;
default:
F_199 ( V_396 L_1 ,
V_148 -> V_154 ) ;
break;
}
return 0 ;
}
static inline T_4 F_200 ( struct V_57 * V_58 ,
struct V_272 * V_274 )
{
return F_90 ( sizeof( struct V_328 ) )
+ F_91 ( sizeof( struct V_275 ) * V_274 -> V_279 )
+ F_91 ( sizeof( struct V_156 ) )
+ F_91 ( F_29 ( V_58 -> V_178 ) )
+ F_140 () ;
}
static int F_201 ( struct V_142 * V_143 , struct V_57 * V_58 ,
struct V_280 * V_397 , struct V_272 * V_274 )
{
V_88 V_134 = F_202 () ;
struct V_328 * V_329 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , 0 , 0 , V_398 , sizeof( * V_329 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_329 = F_44 ( V_145 ) ;
memcpy ( & V_329 -> V_33 , & V_58 -> V_33 , sizeof( V_329 -> V_33 ) ) ;
memcpy ( & V_329 -> V_97 , & V_58 -> V_64 . V_97 , sizeof( V_329 -> V_97 ) ) ;
memcpy ( & V_329 -> V_94 , & V_58 -> V_94 , sizeof( V_329 -> V_94 ) ) ;
F_127 ( V_274 , & V_329 -> V_331 , V_257 ) ;
V_329 -> V_285 = V_397 -> V_285 ;
V_329 -> V_286 = V_397 -> V_286 ;
V_329 -> V_287 = V_397 -> V_287 ;
V_329 -> V_134 = V_58 -> V_133 . V_134 = V_134 ;
V_38 = F_137 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_58 , V_143 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_274 -> type , V_143 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_143 , & V_274 -> V_132 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_203 ( struct V_57 * V_58 , struct V_280 * V_397 ,
struct V_272 * V_274 )
{
struct V_119 * V_119 = F_193 ( V_58 ) ;
struct V_142 * V_143 ;
V_143 = F_83 ( F_200 ( V_58 , V_274 ) , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_201 ( V_143 , V_58 , V_397 , V_274 ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_399 ) ;
}
static struct V_272 * F_204 ( struct V_190 * V_146 , int V_400 ,
T_2 * V_310 , int V_21 , int * V_255 )
{
struct V_119 * V_119 = F_43 ( V_146 ) ;
struct V_261 * V_24 = (struct V_261 * ) V_310 ;
struct V_275 * V_276 = (struct V_275 * ) ( V_24 + 1 ) ;
struct V_272 * V_274 ;
int V_277 ;
switch ( V_146 -> V_401 ) {
case V_40 :
if ( V_400 != V_402 ) {
* V_255 = - V_368 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_400 != V_403 ) {
* V_255 = - V_368 ;
return NULL ;
}
break;
#endif
default:
* V_255 = - V_7 ;
return NULL ;
}
* V_255 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_119 ( V_24 ) )
return NULL ;
V_277 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_276 ) ) ;
if ( F_123 ( V_277 , V_276 , V_24 -> V_94 . V_39 ) )
return NULL ;
if ( V_24 -> V_255 > V_257 )
return NULL ;
V_274 = F_129 ( V_119 , V_200 ) ;
if ( V_274 == NULL ) {
* V_255 = - V_404 ;
return NULL ;
}
F_126 ( V_274 , V_24 ) ;
V_274 -> type = V_259 ;
F_122 ( V_274 , V_276 , V_277 ) ;
* V_255 = V_24 -> V_255 ;
return V_274 ;
}
static inline T_4 F_205 ( struct V_272 * V_274 )
{
return F_90 ( sizeof( struct V_324 ) )
+ F_91 ( sizeof( struct V_275 ) * V_274 -> V_279 )
+ F_91 ( F_29 ( V_274 -> V_178 ) )
+ F_91 ( sizeof( struct V_156 ) )
+ F_140 () ;
}
static int F_206 ( struct V_142 * V_143 , struct V_272 * V_274 ,
int V_255 , const struct V_147 * V_148 )
{
struct V_324 * V_405 ;
int V_325 = V_148 -> V_310 . V_325 ;
struct V_144 * V_145 ;
int V_38 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , 0 , V_406 , sizeof( * V_405 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_405 = F_44 ( V_145 ) ;
F_127 ( V_274 , & V_405 -> V_273 , V_255 ) ;
V_38 = F_137 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_139 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_274 -> type , V_143 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_143 , & V_274 -> V_132 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
V_405 -> V_325 = ! ! V_325 ;
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_207 ( struct V_272 * V_274 , int V_255 , const struct V_147 * V_148 )
{
struct V_119 * V_119 = F_208 ( V_274 ) ;
struct V_142 * V_143 ;
V_143 = F_83 ( F_205 ( V_274 ) , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_206 ( V_143 , V_274 , V_255 , V_148 ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_385 ) ;
}
static int F_209 ( struct V_272 * V_274 , int V_255 , const struct V_147 * V_148 )
{
int V_21 = F_91 ( sizeof( struct V_275 ) * V_274 -> V_279 ) ;
struct V_119 * V_119 = F_208 ( V_274 ) ;
struct V_261 * V_24 ;
struct V_306 * V_33 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_391 , V_38 ;
V_391 = sizeof( * V_24 ) ;
if ( V_148 -> V_154 == V_308 ) {
V_21 += F_91 ( V_391 ) ;
V_391 = sizeof( * V_33 ) ;
}
V_21 += F_140 () ;
V_21 += F_91 ( sizeof( struct V_156 ) ) ;
V_21 += F_90 ( V_391 ) ;
V_143 = F_83 ( V_21 , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_148 -> V_154 , V_391 , 0 ) ;
V_38 = - V_168 ;
if ( V_145 == NULL )
goto V_393;
V_24 = F_44 ( V_145 ) ;
if ( V_148 -> V_154 == V_308 ) {
struct V_1 * V_166 ;
V_33 = F_44 ( V_145 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_255 = V_255 ;
if ( V_148 -> V_310 . V_311 )
V_33 -> V_270 = V_274 -> V_270 ;
else
memcpy ( & V_33 -> V_94 , & V_274 -> V_298 , sizeof( V_33 -> V_94 ) ) ;
V_166 = F_63 ( V_143 , V_407 , sizeof( * V_24 ) ) ;
V_38 = - V_168 ;
if ( V_166 == NULL )
goto V_393;
V_24 = F_2 ( V_166 ) ;
}
F_127 ( V_274 , V_24 , V_255 ) ;
V_38 = F_137 ( V_274 , V_143 ) ;
if ( ! V_38 )
V_38 = F_141 ( V_274 -> type , V_143 ) ;
if ( ! V_38 )
V_38 = F_69 ( V_143 , & V_274 -> V_132 ) ;
if ( V_38 )
goto V_393;
F_74 ( V_143 , V_145 ) ;
return F_86 ( V_119 , V_143 , 0 , V_408 ) ;
V_393:
F_85 ( V_143 ) ;
return V_38 ;
}
static int F_210 ( const struct V_147 * V_148 )
{
struct V_119 * V_119 = V_148 -> V_119 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_83 ( F_140 () , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
V_145 = F_71 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_409 , 0 , 0 ) ;
V_38 = - V_168 ;
if ( V_145 == NULL )
goto V_393;
V_38 = F_141 ( V_148 -> V_310 . type , V_143 ) ;
if ( V_38 )
goto V_393;
F_74 ( V_143 , V_145 ) ;
return F_86 ( V_119 , V_143 , 0 , V_408 ) ;
V_393:
F_85 ( V_143 ) ;
return V_38 ;
}
static int F_211 ( struct V_272 * V_274 , int V_255 , const struct V_147 * V_148 )
{
switch ( V_148 -> V_154 ) {
case V_301 :
case V_410 :
case V_308 :
return F_209 ( V_274 , V_255 , V_148 ) ;
case V_409 :
return F_210 ( V_148 ) ;
case V_406 :
return F_207 ( V_274 , V_255 , V_148 ) ;
default:
F_199 ( V_396 L_2 ,
V_148 -> V_154 ) ;
}
return 0 ;
}
static inline T_4 F_212 ( void )
{
return F_90 ( sizeof( struct V_411 ) ) ;
}
static int F_213 ( struct V_142 * V_143 , T_2 V_34 ,
struct V_360 * V_94 , T_1 * V_412 )
{
struct V_411 * V_413 ;
struct V_144 * V_145 ;
V_145 = F_71 ( V_143 , 0 , 0 , V_414 , sizeof( * V_413 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_413 = F_44 ( V_145 ) ;
V_413 -> V_34 = V_34 ;
memcpy ( & V_413 -> V_94 , V_94 , sizeof( V_413 -> V_94 ) ) ;
if ( V_412 ) {
int V_38 = F_67 ( V_143 , V_53 , sizeof( * V_412 ) , V_412 ) ;
if ( V_38 ) {
F_73 ( V_143 , V_145 ) ;
return V_38 ;
}
}
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_214 ( struct V_119 * V_119 , T_2 V_34 ,
struct V_360 * V_94 , T_1 * V_412 )
{
struct V_142 * V_143 ;
V_143 = F_83 ( F_212 () , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_213 ( V_143 , V_34 , V_94 , V_412 ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_415 ) ;
}
static inline T_4 F_215 ( void )
{
return F_90 ( sizeof( struct V_416 ) ) ;
}
static int F_216 ( struct V_142 * V_143 , struct V_57 * V_58 ,
T_1 * V_352 , T_6 V_417 )
{
struct V_416 * V_341 ;
struct V_144 * V_145 ;
V_145 = F_71 ( V_143 , 0 , 0 , V_418 , sizeof( * V_341 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_341 = F_44 ( V_145 ) ;
memcpy ( & V_341 -> V_33 . V_160 , & V_58 -> V_33 . V_160 , sizeof( V_341 -> V_33 . V_160 ) ) ;
V_341 -> V_33 . V_49 = V_58 -> V_33 . V_49 ;
V_341 -> V_33 . V_39 = V_58 -> V_64 . V_39 ;
V_341 -> V_33 . V_34 = V_58 -> V_33 . V_34 ;
memcpy ( & V_341 -> V_352 , V_352 , sizeof( V_341 -> V_352 ) ) ;
memcpy ( & V_341 -> V_350 , & V_58 -> V_64 . V_97 , sizeof( V_341 -> V_350 ) ) ;
V_341 -> V_417 = V_417 ;
V_341 -> V_419 = V_58 -> V_129 -> V_420 ;
V_341 -> V_96 = V_58 -> V_64 . V_96 ;
F_74 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_217 ( struct V_57 * V_58 , T_1 * V_421 ,
T_6 V_422 )
{
struct V_119 * V_119 = F_193 ( V_58 ) ;
struct V_142 * V_143 ;
if ( V_58 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_58 -> V_129 )
return - V_7 ;
V_143 = F_83 ( F_215 () , V_200 ) ;
if ( V_143 == NULL )
return - V_69 ;
if ( F_216 ( V_143 , V_58 , V_421 , V_422 ) < 0 )
F_101 () ;
return F_86 ( V_119 , V_143 , 0 , V_423 ) ;
}
static bool F_218 ( const struct V_147 * V_148 )
{
return ( bool ) F_219 ( V_148 -> V_119 ) ;
}
static int T_7 F_220 ( struct V_119 * V_119 )
{
struct V_190 * V_203 ;
struct V_424 V_425 = {
. V_426 = V_427 ,
. V_428 = F_186 ,
} ;
V_203 = F_221 ( V_119 , V_429 , & V_425 ) ;
if ( V_203 == NULL )
return - V_69 ;
V_119 -> V_135 . V_430 = V_203 ;
F_222 ( V_119 -> V_135 . V_203 , V_203 ) ;
return 0 ;
}
static void T_8 F_223 ( struct V_431 * V_432 )
{
struct V_119 * V_119 ;
F_224 (net, net_exit_list, exit_list)
F_225 ( V_119 -> V_135 . V_203 , NULL ) ;
F_226 () ;
F_224 (net, net_exit_list, exit_list)
F_227 ( V_119 -> V_135 . V_430 ) ;
}
static int T_9 F_228 ( void )
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
static void T_10 F_232 ( void )
{
F_233 ( & V_436 ) ;
F_231 ( & V_435 ) ;
}
