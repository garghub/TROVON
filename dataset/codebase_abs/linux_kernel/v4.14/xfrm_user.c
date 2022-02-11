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
V_6 -> V_11 [ sizeof( V_6 -> V_11 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_5 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_12 ] ;
struct V_13 * V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) < F_6 ( V_6 ) )
return - V_7 ;
V_6 -> V_11 [ sizeof( V_6 -> V_11 ) - 1 ] = '\0' ;
return 0 ;
}
static int F_7 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_14 ] ;
struct V_15 * V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) < F_8 ( V_6 ) )
return - V_7 ;
V_6 -> V_11 [ sizeof( V_6 -> V_11 ) - 1 ] = '\0' ;
return 0 ;
}
static void F_9 ( struct V_1 * * V_2 , enum V_3 type ,
T_1 * * V_16 )
{
struct V_1 * V_4 = V_2 [ type ] ;
if ( V_4 && V_16 )
* V_16 = F_2 ( V_4 ) ;
}
static inline int F_10 ( struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_18 * V_19 ;
if ( ! V_4 )
return 0 ;
V_19 = F_2 ( V_4 ) ;
if ( V_19 -> V_20 != ( sizeof( struct V_18 ) + V_19 -> V_21 ) )
return - V_7 ;
return 0 ;
}
static inline int F_11 ( struct V_22 * V_23 ,
struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_24 ] ;
struct V_25 * V_26 ;
if ( V_23 -> V_27 & V_28 ) {
if ( ! V_4 )
return - V_7 ;
V_26 = F_2 ( V_4 ) ;
if ( V_26 -> V_29 > V_30 / sizeof( V_26 -> V_31 [ 0 ] ) / 8 )
return - V_7 ;
if ( F_3 ( V_4 ) < F_12 ( V_26 ) &&
F_3 ( V_4 ) != sizeof( * V_26 ) )
return - V_7 ;
}
if ( ! V_4 )
return 0 ;
if ( ( V_23 -> V_32 . V_33 != V_34 ) && ( V_23 -> V_32 . V_33 != V_35 ) )
return - V_7 ;
if ( V_23 -> V_36 != 0 )
return - V_7 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_1 * * V_2 )
{
int V_37 ;
V_37 = - V_7 ;
switch ( V_23 -> V_38 ) {
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
switch ( V_23 -> V_32 . V_33 ) {
case V_35 :
if ( ( ! V_2 [ V_8 ] &&
! V_2 [ V_12 ] ) ||
V_2 [ V_14 ] ||
V_2 [ V_9 ] ||
V_2 [ V_10 ] ||
V_2 [ V_44 ] )
goto V_43;
break;
case V_34 :
if ( V_2 [ V_10 ] )
goto V_43;
if ( ! V_2 [ V_8 ] &&
! V_2 [ V_12 ] &&
! V_2 [ V_9 ] &&
! V_2 [ V_14 ] )
goto V_43;
if ( ( V_2 [ V_8 ] ||
V_2 [ V_12 ] ||
V_2 [ V_9 ] ) &&
V_2 [ V_14 ] )
goto V_43;
if ( V_2 [ V_44 ] &&
V_23 -> V_45 != V_46 )
goto V_43;
break;
case V_47 :
if ( ! V_2 [ V_10 ] ||
V_2 [ V_14 ] ||
V_2 [ V_8 ] ||
V_2 [ V_12 ] ||
V_2 [ V_9 ] ||
V_2 [ V_44 ] ||
( F_15 ( V_23 -> V_32 . V_48 ) >= 0x10000 ) )
goto V_43;
break;
#if F_14 ( V_41 )
case V_49 :
case V_50 :
if ( V_2 [ V_10 ] ||
V_2 [ V_8 ] ||
V_2 [ V_12 ] ||
V_2 [ V_14 ] ||
V_2 [ V_9 ] ||
V_2 [ V_51 ] ||
V_2 [ V_17 ] ||
V_2 [ V_44 ] ||
! V_2 [ V_52 ] )
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
if ( ( V_37 = F_11 ( V_23 , V_2 ) ) )
goto V_43;
V_37 = - V_7 ;
switch ( V_23 -> V_45 ) {
case V_53 :
case V_46 :
case V_54 :
case V_55 :
break;
default:
goto V_43;
}
V_37 = 0 ;
V_43:
return V_37 ;
}
static int F_16 ( struct V_56 * V_57 , struct V_1 * V_58 )
{
struct V_5 * V_23 , * V_59 ;
struct V_60 * V_61 ;
if ( ! V_58 )
return 0 ;
V_59 = F_2 ( V_58 ) ;
V_61 = F_17 ( V_59 -> V_11 , 1 ) ;
if ( ! V_61 )
return - V_62 ;
V_57 -> V_63 . V_64 = V_61 -> V_65 . V_66 ;
V_23 = F_18 ( V_59 , F_4 ( V_59 ) , V_67 ) ;
if ( ! V_23 )
return - V_68 ;
strcpy ( V_23 -> V_11 , V_61 -> V_69 ) ;
V_57 -> V_70 = V_23 ;
V_57 -> V_71 = V_61 -> V_72 . V_73 . V_71 ;
return 0 ;
}
static int F_19 ( struct V_13 * * V_74 , T_2 * V_63 ,
struct V_1 * V_58 )
{
struct V_5 * V_59 ;
struct V_13 * V_23 ;
struct V_60 * V_61 ;
if ( ! V_58 )
return 0 ;
V_59 = F_2 ( V_58 ) ;
V_61 = F_20 ( V_59 -> V_11 , 1 ) ;
if ( ! V_61 )
return - V_62 ;
* V_63 = V_61 -> V_65 . V_66 ;
V_23 = F_21 ( sizeof( * V_23 ) + ( V_59 -> V_75 + 7 ) / 8 , V_67 ) ;
if ( ! V_23 )
return - V_68 ;
strcpy ( V_23 -> V_11 , V_61 -> V_69 ) ;
V_23 -> V_75 = V_59 -> V_75 ;
V_23 -> V_76 = V_61 -> V_72 . V_77 . V_78 ;
memcpy ( V_23 -> V_79 , V_59 -> V_79 , ( V_59 -> V_75 + 7 ) / 8 ) ;
* V_74 = V_23 ;
return 0 ;
}
static int F_22 ( struct V_13 * * V_74 , T_2 * V_63 ,
struct V_1 * V_58 )
{
struct V_13 * V_23 , * V_59 ;
struct V_60 * V_61 ;
if ( ! V_58 )
return 0 ;
V_59 = F_2 ( V_58 ) ;
V_61 = F_20 ( V_59 -> V_11 , 1 ) ;
if ( ! V_61 )
return - V_62 ;
if ( V_59 -> V_76 > V_61 -> V_72 . V_77 . V_80 )
return - V_7 ;
* V_63 = V_61 -> V_65 . V_66 ;
V_23 = F_18 ( V_59 , F_6 ( V_59 ) , V_67 ) ;
if ( ! V_23 )
return - V_68 ;
strcpy ( V_23 -> V_11 , V_61 -> V_69 ) ;
if ( ! V_23 -> V_76 )
V_23 -> V_76 = V_61 -> V_72 . V_77 . V_78 ;
* V_74 = V_23 ;
return 0 ;
}
static int F_23 ( struct V_56 * V_57 , struct V_1 * V_58 )
{
struct V_15 * V_23 , * V_59 ;
struct V_60 * V_61 ;
if ( ! V_58 )
return 0 ;
V_59 = F_2 ( V_58 ) ;
V_61 = F_24 ( V_59 -> V_11 , V_59 -> V_81 , 1 ) ;
if ( ! V_61 )
return - V_62 ;
V_57 -> V_63 . V_64 = V_61 -> V_65 . V_66 ;
V_23 = F_18 ( V_59 , F_8 ( V_59 ) , V_67 ) ;
if ( ! V_23 )
return - V_68 ;
strcpy ( V_23 -> V_11 , V_61 -> V_69 ) ;
V_57 -> V_82 = V_23 ;
V_57 -> V_71 = V_61 -> V_72 . V_82 . V_71 ;
return 0 ;
}
static inline int F_25 ( struct V_25 * V_83 ,
struct V_1 * V_84 )
{
struct V_25 * V_85 ;
int V_86 ;
if ( ! V_83 || ! V_84 )
return 0 ;
V_85 = F_2 ( V_84 ) ;
V_86 = F_12 ( V_85 ) ;
if ( F_3 ( V_84 ) < V_86 ||
F_12 ( V_83 ) != V_86 ||
V_83 -> V_29 != V_85 -> V_29 )
return - V_7 ;
if ( V_85 -> V_36 > V_85 -> V_29 * sizeof( V_87 ) * 8 )
return - V_7 ;
return 0 ;
}
static int F_26 ( struct V_25 * * V_83 ,
struct V_25 * * V_88 ,
struct V_1 * V_58 )
{
struct V_25 * V_23 , * V_89 , * V_85 ;
int V_90 , V_86 ;
if ( ! V_58 )
return 0 ;
V_85 = F_2 ( V_58 ) ;
V_90 = F_12 ( V_85 ) ;
V_86 = F_3 ( V_58 ) >= V_90 ? V_90 : sizeof( * V_85 ) ;
V_23 = F_27 ( V_90 , V_67 ) ;
if ( ! V_23 )
return - V_68 ;
V_89 = F_27 ( V_90 , V_67 ) ;
if ( ! V_89 ) {
F_28 ( V_23 ) ;
return - V_68 ;
}
memcpy ( V_23 , V_85 , V_86 ) ;
memcpy ( V_89 , V_85 , V_86 ) ;
* V_83 = V_23 ;
* V_88 = V_89 ;
return 0 ;
}
static inline int F_29 ( struct V_91 * V_92 )
{
int V_20 = 0 ;
if ( V_92 ) {
V_20 += sizeof( struct V_18 ) ;
V_20 += V_92 -> V_21 ;
}
return V_20 ;
}
static void F_30 ( struct V_56 * V_57 , struct V_22 * V_23 )
{
memcpy ( & V_57 -> V_32 , & V_23 -> V_32 , sizeof( V_57 -> V_32 ) ) ;
memcpy ( & V_57 -> V_93 , & V_23 -> V_93 , sizeof( V_57 -> V_93 ) ) ;
memcpy ( & V_57 -> V_94 , & V_23 -> V_94 , sizeof( V_57 -> V_94 ) ) ;
V_57 -> V_63 . V_45 = V_23 -> V_45 ;
V_57 -> V_63 . V_36 = F_31 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_57 -> V_63 . V_95 = V_23 -> V_95 ;
V_57 -> V_63 . V_38 = V_23 -> V_38 ;
memcpy ( & V_57 -> V_63 . V_96 , & V_23 -> V_96 , sizeof( V_57 -> V_63 . V_96 ) ) ;
V_57 -> V_63 . V_27 = V_23 -> V_27 ;
if ( ! V_57 -> V_93 . V_38 && ! ( V_23 -> V_27 & V_97 ) )
V_57 -> V_93 . V_38 = V_23 -> V_38 ;
}
static void F_32 ( struct V_56 * V_57 , struct V_1 * * V_2 ,
int V_98 )
{
struct V_1 * V_84 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_98 ? V_2 [ V_24 ] : NULL ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
struct V_1 * V_103 = V_2 [ V_104 ] ;
struct V_1 * V_4 = V_2 [ V_105 ] ;
if ( V_100 ) {
struct V_25 * V_83 ;
V_83 = F_2 ( V_100 ) ;
memcpy ( V_57 -> V_83 , V_83 ,
F_12 ( V_83 ) ) ;
memcpy ( V_57 -> V_88 , V_83 ,
F_12 ( V_83 ) ) ;
}
if ( V_84 ) {
struct V_106 * V_107 ;
V_107 = F_2 ( V_84 ) ;
memcpy ( & V_57 -> V_107 , V_107 , sizeof( * V_107 ) ) ;
memcpy ( & V_57 -> V_108 , V_107 , sizeof( * V_107 ) ) ;
}
if ( V_101 ) {
struct V_109 * V_110 ;
V_110 = F_2 ( V_101 ) ;
V_57 -> V_111 . V_112 = V_110 -> V_112 ;
V_57 -> V_111 . V_113 = V_110 -> V_113 ;
V_57 -> V_111 . V_114 = V_110 -> V_114 ;
V_57 -> V_111 . V_115 = V_110 -> V_115 ;
}
if ( V_103 )
V_57 -> V_116 = F_33 ( V_103 ) ;
if ( V_4 )
V_57 -> V_117 = F_33 ( V_4 ) ;
}
static struct V_56 * F_34 ( struct V_118 * V_118 ,
struct V_22 * V_23 ,
struct V_1 * * V_2 ,
int * V_119 )
{
struct V_56 * V_57 = F_35 ( V_118 ) ;
int V_37 = - V_68 ;
if ( ! V_57 )
goto V_120;
F_30 ( V_57 , V_23 ) ;
if ( V_2 [ V_121 ] )
V_57 -> V_63 . V_122 = F_33 ( V_2 [ V_121 ] ) ;
if ( ( V_37 = F_23 ( V_57 , V_2 [ V_14 ] ) ) )
goto error;
if ( ( V_37 = F_22 ( & V_57 -> V_123 , & V_57 -> V_63 . V_124 ,
V_2 [ V_12 ] ) ) )
goto error;
if ( ! V_57 -> V_63 . V_124 ) {
if ( ( V_37 = F_19 ( & V_57 -> V_123 , & V_57 -> V_63 . V_124 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_37 = F_16 ( V_57 , V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_37 = F_36 ( & V_57 -> V_125 , & V_57 -> V_63 . V_126 ,
V_127 ,
V_2 [ V_10 ] ) ) )
goto error;
if ( V_2 [ V_51 ] ) {
V_57 -> V_128 = F_18 ( F_2 ( V_2 [ V_51 ] ) ,
sizeof( * V_57 -> V_128 ) , V_67 ) ;
if ( V_57 -> V_128 == NULL )
goto error;
}
if ( V_2 [ V_44 ] )
V_57 -> V_129 = F_33 ( V_2 [ V_44 ] ) ;
if ( V_2 [ V_52 ] ) {
V_57 -> V_130 = F_18 ( F_2 ( V_2 [ V_52 ] ) ,
sizeof( * V_57 -> V_130 ) , V_67 ) ;
if ( V_57 -> V_130 == NULL )
goto error;
}
F_37 ( V_2 , & V_57 -> V_131 ) ;
if ( V_2 [ V_132 ] )
V_57 -> V_63 . V_133 = F_33 ( V_2 [ V_132 ] ) ;
V_37 = F_38 ( V_57 , false , V_2 [ V_134 ] ) ;
if ( V_37 )
goto error;
if ( V_2 [ V_17 ] ) {
V_37 = F_39 ( V_57 ,
F_2 ( V_2 [ V_17 ] ) ) ;
if ( V_37 )
goto error;
}
if ( V_2 [ V_134 ] ) {
V_37 = F_40 ( V_118 , V_57 ,
F_2 ( V_2 [ V_134 ] ) ) ;
if ( V_37 )
goto error;
}
if ( ( V_37 = F_26 ( & V_57 -> V_83 , & V_57 -> V_88 ,
V_2 [ V_24 ] ) ) )
goto error;
V_57 -> V_135 . V_136 = V_23 -> V_136 ;
V_57 -> V_117 = V_118 -> V_137 . V_138 ;
V_57 -> V_116 = ( V_118 -> V_137 . V_139 * V_140 ) / V_141 ;
if ( ( V_37 = F_41 ( V_57 ) ) )
goto error;
F_32 ( V_57 , V_2 , 0 ) ;
return V_57 ;
error:
V_57 -> V_135 . V_142 = V_143 ;
F_42 ( V_57 ) ;
V_120:
* V_119 = V_37 ;
return NULL ;
}
static int F_43 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_22 * V_23 = F_45 ( V_147 ) ;
struct V_56 * V_57 ;
int V_37 ;
struct V_149 V_150 ;
V_37 = F_13 ( V_23 , V_2 ) ;
if ( V_37 )
return V_37 ;
V_57 = F_34 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( ! V_57 )
return V_37 ;
F_46 ( V_57 ) ;
if ( V_147 -> V_151 == V_152 )
V_37 = F_47 ( V_57 ) ;
else
V_37 = F_48 ( V_57 ) ;
F_49 ( V_57 , V_37 ? 0 : 1 , true ) ;
if ( V_37 < 0 ) {
V_57 -> V_135 . V_142 = V_143 ;
F_50 ( V_57 ) ;
F_51 ( V_57 ) ;
goto V_43;
}
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
V_150 . V_156 = V_147 -> V_151 ;
F_52 ( V_57 , & V_150 ) ;
V_43:
F_42 ( V_57 ) ;
return V_37 ;
}
static struct V_56 * F_53 ( struct V_118 * V_118 ,
struct V_157 * V_23 ,
struct V_1 * * V_2 ,
int * V_119 )
{
struct V_56 * V_57 = NULL ;
struct V_158 V_159 ;
int V_37 ;
T_3 V_131 = F_37 ( V_2 , & V_159 ) ;
if ( F_54 ( V_23 -> V_33 , V_160 ) ) {
V_37 = - V_161 ;
V_57 = F_55 ( V_118 , V_131 , & V_23 -> V_162 , V_23 -> V_48 , V_23 -> V_33 , V_23 -> V_38 ) ;
} else {
T_1 * V_96 = NULL ;
F_9 ( V_2 , V_163 , & V_96 ) ;
if ( ! V_96 ) {
V_37 = - V_7 ;
goto V_43;
}
V_37 = - V_161 ;
V_57 = F_56 ( V_118 , V_131 ,
& V_23 -> V_162 , V_96 ,
V_23 -> V_33 , V_23 -> V_38 ) ;
}
V_43:
if ( ! V_57 && V_119 )
* V_119 = V_37 ;
return V_57 ;
}
static int F_57 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_56 * V_57 ;
int V_37 = - V_161 ;
struct V_149 V_150 ;
struct V_157 * V_23 = F_45 ( V_147 ) ;
V_57 = F_53 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( V_57 == NULL )
return V_37 ;
if ( ( V_37 = F_58 ( V_57 ) ) != 0 )
goto V_43;
if ( F_59 ( V_57 ) ) {
V_37 = - V_164 ;
goto V_43;
}
V_37 = F_60 ( V_57 ) ;
if ( V_37 < 0 )
goto V_43;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
V_150 . V_156 = V_147 -> V_151 ;
F_52 ( V_57 , & V_150 ) ;
V_43:
F_61 ( V_57 , V_37 ? 0 : 1 , true ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static void F_62 ( struct V_56 * V_57 , struct V_22 * V_23 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
memcpy ( & V_23 -> V_32 , & V_57 -> V_32 , sizeof( V_23 -> V_32 ) ) ;
memcpy ( & V_23 -> V_93 , & V_57 -> V_93 , sizeof( V_23 -> V_93 ) ) ;
memcpy ( & V_23 -> V_94 , & V_57 -> V_94 , sizeof( V_23 -> V_94 ) ) ;
memcpy ( & V_23 -> V_111 , & V_57 -> V_111 , sizeof( V_23 -> V_111 ) ) ;
F_63 ( V_57 -> V_165 . V_36 , & V_23 -> V_165 . V_36 ) ;
F_63 ( V_57 -> V_165 . V_107 , & V_23 -> V_165 . V_107 ) ;
F_63 ( V_57 -> V_165 . V_166 , & V_23 -> V_165 . V_166 ) ;
memcpy ( & V_23 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_23 -> V_96 ) ) ;
V_23 -> V_45 = V_57 -> V_63 . V_45 ;
V_23 -> V_36 = V_57 -> V_63 . V_36 ;
V_23 -> V_95 = V_57 -> V_63 . V_95 ;
V_23 -> V_38 = V_57 -> V_63 . V_38 ;
V_23 -> V_27 = V_57 -> V_63 . V_27 ;
V_23 -> V_136 = V_57 -> V_135 . V_136 ;
}
static int F_64 ( struct V_91 * V_167 , struct V_144 * V_145 )
{
struct V_18 * V_19 ;
struct V_1 * V_168 ;
int V_169 = sizeof( * V_19 ) + V_167 -> V_21 ;
V_168 = F_65 ( V_145 , V_17 , V_169 ) ;
if ( V_168 == NULL )
return - V_170 ;
V_19 = F_2 ( V_168 ) ;
V_19 -> V_171 = V_17 ;
V_19 -> V_20 = V_169 ;
V_19 -> V_172 = V_167 -> V_172 ;
V_19 -> V_173 = V_167 -> V_173 ;
V_19 -> V_21 = V_167 -> V_21 ;
memcpy ( V_19 + 1 , V_167 -> V_174 , V_167 -> V_21 ) ;
return 0 ;
}
static int F_66 ( struct V_175 * V_176 , struct V_144 * V_145 )
{
struct V_177 * V_178 ;
struct V_1 * V_168 ;
V_168 = F_65 ( V_145 , V_134 , sizeof( * V_178 ) ) ;
if ( V_168 == NULL )
return - V_170 ;
V_178 = F_2 ( V_168 ) ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_179 = V_176 -> V_180 -> V_179 ;
V_178 -> V_27 = V_176 -> V_27 ;
return 0 ;
}
static int F_67 ( struct V_13 * V_77 , struct V_144 * V_145 )
{
struct V_5 * V_61 ;
struct V_1 * V_181 ;
V_181 = F_65 ( V_145 , V_8 ,
sizeof( * V_61 ) + ( V_77 -> V_75 + 7 ) / 8 ) ;
if ( ! V_181 )
return - V_170 ;
V_61 = F_2 ( V_181 ) ;
strncpy ( V_61 -> V_11 , V_77 -> V_11 , sizeof( V_61 -> V_11 ) ) ;
memcpy ( V_61 -> V_79 , V_77 -> V_79 , ( V_77 -> V_75 + 7 ) / 8 ) ;
V_61 -> V_75 = V_77 -> V_75 ;
return 0 ;
}
static int F_68 ( struct V_56 * V_57 ,
struct V_22 * V_23 ,
struct V_144 * V_145 )
{
int V_182 = 0 ;
F_62 ( V_57 , V_23 ) ;
if ( V_57 -> V_63 . V_122 ) {
V_182 = F_69 ( V_145 , V_121 ,
V_57 -> V_63 . V_122 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_130 ) {
V_182 = F_70 ( V_145 , V_52 , sizeof( * V_57 -> V_130 ) , V_57 -> V_130 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_183 ) {
V_182 = F_71 ( V_145 , V_184 , V_57 -> V_183 ,
V_185 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_82 ) {
V_182 = F_70 ( V_145 , V_14 , F_8 ( V_57 -> V_82 ) , V_57 -> V_82 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_123 ) {
V_182 = F_67 ( V_57 -> V_123 , V_145 ) ;
if ( ! V_182 )
V_182 = F_70 ( V_145 , V_12 ,
F_6 ( V_57 -> V_123 ) , V_57 -> V_123 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_70 ) {
V_182 = F_70 ( V_145 , V_9 , F_4 ( V_57 -> V_70 ) , V_57 -> V_70 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_125 ) {
V_182 = F_70 ( V_145 , V_10 , sizeof( * ( V_57 -> V_125 ) ) , V_57 -> V_125 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_128 ) {
V_182 = F_70 ( V_145 , V_51 , sizeof( * V_57 -> V_128 ) , V_57 -> V_128 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_129 ) {
V_182 = F_69 ( V_145 , V_44 , V_57 -> V_129 ) ;
if ( V_182 )
goto V_43;
}
V_182 = F_72 ( V_145 , & V_57 -> V_131 ) ;
if ( V_182 )
goto V_43;
if ( V_57 -> V_83 )
V_182 = F_70 ( V_145 , V_24 ,
F_12 ( V_57 -> V_83 ) ,
V_57 -> V_83 ) ;
else
V_182 = F_70 ( V_145 , V_99 , sizeof( V_57 -> V_107 ) ,
& V_57 -> V_107 ) ;
if ( V_182 )
goto V_43;
if( V_57 -> V_176 . V_180 )
V_182 = F_66 ( & V_57 -> V_176 , V_145 ) ;
if ( V_182 )
goto V_43;
if ( V_57 -> V_63 . V_133 ) {
V_182 = F_69 ( V_145 , V_132 , V_57 -> V_63 . V_133 ) ;
if ( V_182 )
goto V_43;
}
if ( V_57 -> V_186 )
V_182 = F_64 ( V_57 -> V_186 , V_145 ) ;
V_43:
return V_182 ;
}
static int F_73 ( struct V_56 * V_57 , int V_187 , void * V_188 )
{
struct V_189 * V_190 = V_188 ;
struct V_144 * V_191 = V_190 -> V_191 ;
struct V_144 * V_145 = V_190 -> V_192 ;
struct V_22 * V_23 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , F_75 ( V_191 ) . V_154 , V_190 -> V_153 ,
V_152 , sizeof( * V_23 ) , V_190 -> V_193 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_23 = F_45 ( V_147 ) ;
V_37 = F_68 ( V_57 , V_23 , V_145 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_78 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = (struct V_196 * ) & V_195 -> args [ 1 ] ;
struct V_198 * V_148 = V_195 -> V_145 -> V_148 ;
struct V_118 * V_118 = F_44 ( V_148 ) ;
if ( V_195 -> args [ 0 ] )
F_79 ( V_197 , V_118 ) ;
return 0 ;
}
static int F_80 ( struct V_144 * V_145 , struct V_194 * V_195 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_196 * V_197 = (struct V_196 * ) & V_195 -> args [ 1 ] ;
struct V_189 V_199 ;
F_81 ( sizeof( struct V_196 ) >
sizeof( V_195 -> args ) - sizeof( V_195 -> args [ 0 ] ) ) ;
V_199 . V_191 = V_195 -> V_145 ;
V_199 . V_192 = V_145 ;
V_199 . V_153 = V_195 -> V_147 -> V_153 ;
V_199 . V_193 = V_200 ;
if ( ! V_195 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_201 + 1 ] ;
struct V_202 * V_203 = NULL ;
T_2 V_33 = 0 ;
int V_37 ;
V_37 = F_82 ( V_195 -> V_147 , 0 , V_2 , V_201 , V_204 ,
NULL ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 [ V_205 ] ) {
V_203 = F_18 ( F_2 ( V_2 [ V_205 ] ) ,
sizeof( * V_203 ) , V_67 ) ;
if ( V_203 == NULL )
return - V_68 ;
}
if ( V_2 [ V_206 ] )
V_33 = F_83 ( V_2 [ V_206 ] ) ;
F_84 ( V_197 , V_33 , V_203 ) ;
V_195 -> args [ 0 ] = 1 ;
}
( void ) V_196 ( V_118 , V_197 , F_73 , & V_199 ) ;
return V_145 -> V_20 ;
}
static struct V_144 * F_85 ( struct V_144 * V_191 ,
struct V_56 * V_57 , T_3 V_136 )
{
struct V_189 V_199 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_86 ( V_207 , V_208 ) ;
if ( ! V_145 )
return F_87 ( - V_68 ) ;
V_199 . V_191 = V_191 ;
V_199 . V_192 = V_145 ;
V_199 . V_153 = V_136 ;
V_199 . V_193 = 0 ;
V_37 = F_73 ( V_57 , 0 , & V_199 ) ;
if ( V_37 ) {
F_88 ( V_145 ) ;
return F_87 ( V_37 ) ;
}
return V_145 ;
}
static inline int F_89 ( struct V_118 * V_118 , struct V_144 * V_145 ,
T_3 V_209 , unsigned int V_210 )
{
struct V_198 * V_211 = F_90 ( V_118 -> V_137 . V_211 ) ;
if ( V_211 )
return F_91 ( V_211 , V_145 , V_209 , V_210 , V_208 ) ;
else
return - 1 ;
}
static inline T_4 F_92 ( void )
{
return F_93 ( 4 )
+ F_94 ( sizeof( struct V_212 ) )
+ F_94 ( sizeof( struct V_213 ) )
+ F_94 ( sizeof( struct V_214 ) )
+ F_94 ( sizeof( struct V_214 ) ) ;
}
static int F_95 ( struct V_144 * V_145 , struct V_118 * V_118 ,
T_3 V_154 , T_3 V_136 , T_3 V_27 )
{
struct V_215 V_216 ;
struct V_212 V_217 ;
struct V_213 V_218 ;
struct V_214 V_219 , V_220 ;
struct V_146 * V_147 ;
int V_37 ;
T_3 * V_221 ;
unsigned V_222 ;
V_147 = F_74 ( V_145 , V_154 , V_136 , V_223 , sizeof( T_3 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_221 = F_45 ( V_147 ) ;
* V_221 = V_27 ;
F_96 ( V_118 , & V_216 ) ;
V_217 . V_224 = V_216 . V_224 ;
V_217 . V_225 = V_216 . V_225 ;
V_217 . V_226 = V_216 . V_226 ;
V_217 . V_227 = V_216 . V_227 ;
V_217 . V_228 = V_216 . V_228 ;
V_217 . V_229 = V_216 . V_229 ;
V_218 . V_230 = V_216 . V_230 ;
V_218 . V_231 = V_216 . V_231 ;
do {
V_222 = F_97 ( & V_118 -> V_137 . V_232 . V_233 ) ;
V_219 . V_234 = V_118 -> V_137 . V_232 . V_235 ;
V_219 . V_236 = V_118 -> V_137 . V_232 . V_237 ;
V_220 . V_234 = V_118 -> V_137 . V_232 . V_238 ;
V_220 . V_236 = V_118 -> V_137 . V_232 . V_239 ;
} while ( F_98 ( & V_118 -> V_137 . V_232 . V_233 , V_222 ) );
V_37 = F_70 ( V_145 , V_240 , sizeof( V_217 ) , & V_217 ) ;
if ( ! V_37 )
V_37 = F_70 ( V_145 , V_241 , sizeof( V_218 ) , & V_218 ) ;
if ( ! V_37 )
V_37 = F_70 ( V_145 , V_242 , sizeof( V_219 ) , & V_219 ) ;
if ( ! V_37 )
V_37 = F_70 ( V_145 , V_243 , sizeof( V_220 ) , & V_220 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_99 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_214 * V_244 = NULL ;
struct V_214 * V_245 = NULL ;
if ( V_2 [ V_242 ] ) {
struct V_1 * V_58 = V_2 [ V_242 ] ;
if ( F_3 ( V_58 ) < sizeof( * V_244 ) )
return - V_7 ;
V_244 = F_2 ( V_58 ) ;
if ( V_244 -> V_234 > 32 || V_244 -> V_236 > 32 )
return - V_7 ;
}
if ( V_2 [ V_243 ] ) {
struct V_1 * V_58 = V_2 [ V_243 ] ;
if ( F_3 ( V_58 ) < sizeof( * V_245 ) )
return - V_7 ;
V_245 = F_2 ( V_58 ) ;
if ( V_245 -> V_234 > 128 || V_245 -> V_236 > 128 )
return - V_7 ;
}
if ( V_244 || V_245 ) {
F_100 ( & V_118 -> V_137 . V_232 . V_233 ) ;
if ( V_244 ) {
V_118 -> V_137 . V_232 . V_235 = V_244 -> V_234 ;
V_118 -> V_137 . V_232 . V_237 = V_244 -> V_236 ;
}
if ( V_245 ) {
V_118 -> V_137 . V_232 . V_238 = V_245 -> V_234 ;
V_118 -> V_137 . V_232 . V_239 = V_245 -> V_236 ;
}
F_101 ( & V_118 -> V_137 . V_232 . V_233 ) ;
F_102 ( V_118 ) ;
}
return 0 ;
}
static int F_103 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_144 * V_246 ;
T_3 * V_27 = F_45 ( V_147 ) ;
T_3 V_247 = F_75 ( V_145 ) . V_154 ;
T_3 V_136 = V_147 -> V_153 ;
V_246 = F_86 ( F_92 () , V_208 ) ;
if ( V_246 == NULL )
return - V_68 ;
if ( F_95 ( V_246 , V_118 , V_247 , V_136 , * V_27 ) < 0 )
F_104 () ;
return F_105 ( V_118 -> V_137 . V_211 , V_246 , V_247 ) ;
}
static inline T_4 F_106 ( void )
{
return F_93 ( 4 )
+ F_94 ( sizeof( struct V_248 ) )
+ F_94 ( 4 ) ;
}
static int F_107 ( struct V_144 * V_145 , struct V_118 * V_118 ,
T_3 V_154 , T_3 V_136 , T_3 V_27 )
{
struct V_249 V_216 ;
struct V_248 V_250 ;
struct V_146 * V_147 ;
int V_37 ;
T_3 * V_221 ;
V_147 = F_74 ( V_145 , V_154 , V_136 , V_251 , sizeof( T_3 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_221 = F_45 ( V_147 ) ;
* V_221 = V_27 ;
F_108 ( V_118 , & V_216 ) ;
V_250 . V_252 = V_216 . V_252 ;
V_250 . V_253 = V_216 . V_253 ;
V_37 = F_69 ( V_145 , V_254 , V_216 . V_255 ) ;
if ( ! V_37 )
V_37 = F_70 ( V_145 , V_256 , sizeof( V_250 ) , & V_250 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_109 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_144 * V_246 ;
T_3 * V_27 = F_45 ( V_147 ) ;
T_3 V_247 = F_75 ( V_145 ) . V_154 ;
T_3 V_136 = V_147 -> V_153 ;
V_246 = F_86 ( F_106 () , V_208 ) ;
if ( V_246 == NULL )
return - V_68 ;
if ( F_107 ( V_246 , V_118 , V_247 , V_136 , * V_27 ) < 0 )
F_104 () ;
return F_105 ( V_118 -> V_137 . V_211 , V_246 , V_247 ) ;
}
static int F_110 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_157 * V_23 = F_45 ( V_147 ) ;
struct V_56 * V_57 ;
struct V_144 * V_257 ;
int V_37 = - V_161 ;
V_57 = F_53 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( V_57 == NULL )
goto V_258;
V_257 = F_85 ( V_145 , V_57 , V_147 -> V_153 ) ;
if ( F_111 ( V_257 ) ) {
V_37 = F_112 ( V_257 ) ;
} else {
V_37 = F_105 ( V_118 -> V_137 . V_211 , V_257 , F_75 ( V_145 ) . V_154 ) ;
}
F_42 ( V_57 ) ;
V_258:
return V_37 ;
}
static int F_113 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_56 * V_57 ;
struct V_259 * V_23 ;
struct V_144 * V_257 ;
T_1 * V_162 ;
int V_38 ;
int V_37 ;
T_3 V_131 ;
struct V_158 V_159 ;
V_23 = F_45 ( V_147 ) ;
V_37 = F_114 ( V_23 -> V_199 . V_32 . V_33 , V_23 -> V_260 , V_23 -> V_261 ) ;
if ( V_37 )
goto V_258;
V_38 = V_23 -> V_199 . V_38 ;
V_162 = & V_23 -> V_199 . V_32 . V_162 ;
V_57 = NULL ;
V_131 = F_37 ( V_2 , & V_159 ) ;
if ( V_23 -> V_199 . V_136 ) {
V_57 = F_115 ( V_118 , V_131 , V_23 -> V_199 . V_136 ) ;
if ( V_57 && ! F_116 ( & V_57 -> V_32 . V_162 , V_162 , V_38 ) ) {
F_42 ( V_57 ) ;
V_57 = NULL ;
}
}
if ( ! V_57 )
V_57 = F_117 ( V_118 , & V_159 , V_23 -> V_199 . V_45 , V_23 -> V_199 . V_95 ,
V_23 -> V_199 . V_32 . V_33 , V_162 ,
& V_23 -> V_199 . V_96 , 1 ,
V_38 ) ;
V_37 = - V_262 ;
if ( V_57 == NULL )
goto V_258;
V_37 = F_118 ( V_57 , V_23 -> V_260 , V_23 -> V_261 ) ;
if ( V_37 )
goto V_43;
V_257 = F_85 ( V_145 , V_57 , V_147 -> V_153 ) ;
if ( F_111 ( V_257 ) ) {
V_37 = F_112 ( V_257 ) ;
goto V_43;
}
V_37 = F_105 ( V_118 -> V_137 . V_211 , V_257 , F_75 ( V_145 ) . V_154 ) ;
V_43:
F_42 ( V_57 ) ;
V_258:
return V_37 ;
}
static int F_119 ( T_2 V_263 )
{
switch ( V_263 ) {
case V_264 :
case V_265 :
case V_266 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_120 ( T_2 type )
{
switch ( type ) {
case V_267 :
#ifdef F_121
case V_268 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_122 ( struct V_269 * V_23 )
{
int V_182 ;
switch ( V_23 -> V_270 ) {
case V_271 :
case V_272 :
case V_273 :
case V_274 :
break;
default:
return - V_7 ;
}
switch ( V_23 -> V_275 ) {
case V_276 :
case V_277 :
break;
default:
return - V_7 ;
}
switch ( V_23 -> V_93 . V_38 ) {
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
V_182 = F_119 ( V_23 -> V_263 ) ;
if ( V_182 )
return V_182 ;
if ( V_23 -> V_278 && ( ( V_23 -> V_278 & V_279 ) != V_23 -> V_263 ) )
return - V_7 ;
return 0 ;
}
static int F_123 ( struct V_280 * V_281 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_18 * V_19 ;
if ( ! V_4 )
return 0 ;
V_19 = F_2 ( V_4 ) ;
return F_124 ( & V_281 -> V_186 , V_19 , V_67 ) ;
}
static void F_125 ( struct V_280 * V_282 , struct V_283 * V_284 ,
int V_285 )
{
int V_286 ;
V_282 -> V_287 = V_285 ;
for ( V_286 = 0 ; V_286 < V_285 ; V_286 ++ , V_284 ++ ) {
struct V_288 * V_289 = & V_282 -> V_290 [ V_286 ] ;
memcpy ( & V_289 -> V_32 , & V_284 -> V_32 , sizeof( struct V_291 ) ) ;
memcpy ( & V_289 -> V_96 , & V_284 -> V_96 ,
sizeof( T_1 ) ) ;
V_289 -> V_95 = V_284 -> V_95 ;
V_289 -> V_45 = V_284 -> V_45 ;
V_289 -> V_270 = V_284 -> V_270 ;
V_289 -> V_292 = V_284 -> V_292 ;
V_289 -> V_293 = V_284 -> V_293 ;
V_289 -> V_294 = V_284 -> V_294 ;
V_289 -> V_295 = V_284 -> V_295 ;
V_289 -> V_296 = ! ~ ( V_289 -> V_293 & V_289 -> V_294 & V_289 -> V_295 ) ;
V_289 -> V_297 = V_284 -> V_38 ;
}
}
static int F_126 ( int V_285 , struct V_283 * V_284 , T_5 V_38 )
{
int V_286 ;
if ( V_285 > V_298 )
return - V_7 ;
for ( V_286 = 0 ; V_286 < V_285 ; V_286 ++ ) {
if ( ! V_284 [ V_286 ] . V_38 )
V_284 [ V_286 ] . V_38 = V_38 ;
switch ( V_284 [ V_286 ] . V_38 ) {
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
static int F_127 ( struct V_280 * V_281 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_299 ] ;
if ( ! V_4 ) {
V_281 -> V_287 = 0 ;
} else {
struct V_283 * V_300 = F_2 ( V_4 ) ;
int V_285 = F_3 ( V_4 ) / sizeof( * V_300 ) ;
int V_37 ;
V_37 = F_126 ( V_285 , V_300 , V_281 -> V_38 ) ;
if ( V_37 )
return V_37 ;
F_125 ( V_281 , V_300 , V_285 ) ;
}
return 0 ;
}
static int F_128 ( T_2 * V_301 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_302 ] ;
struct V_303 * V_304 ;
T_2 type = V_267 ;
int V_37 ;
if ( V_4 ) {
V_304 = F_2 ( V_4 ) ;
type = V_304 -> type ;
}
V_37 = F_120 ( type ) ;
if ( V_37 )
return V_37 ;
* V_301 = type ;
return 0 ;
}
static void F_129 ( struct V_280 * V_282 , struct V_269 * V_23 )
{
V_282 -> V_305 = V_23 -> V_305 ;
V_282 -> V_278 = V_23 -> V_278 ;
memcpy ( & V_282 -> V_306 , & V_23 -> V_93 , sizeof( V_282 -> V_306 ) ) ;
memcpy ( & V_282 -> V_94 , & V_23 -> V_94 , sizeof( V_282 -> V_94 ) ) ;
V_282 -> V_275 = V_23 -> V_275 ;
V_282 -> V_27 = V_23 -> V_27 ;
V_282 -> V_38 = V_23 -> V_93 . V_38 ;
}
static void F_130 ( struct V_280 * V_282 , struct V_269 * V_23 , int V_263 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
memcpy ( & V_23 -> V_93 , & V_282 -> V_306 , sizeof( V_23 -> V_93 ) ) ;
memcpy ( & V_23 -> V_94 , & V_282 -> V_94 , sizeof( V_23 -> V_94 ) ) ;
memcpy ( & V_23 -> V_111 , & V_282 -> V_111 , sizeof( V_23 -> V_111 ) ) ;
V_23 -> V_305 = V_282 -> V_305 ;
V_23 -> V_278 = V_282 -> V_278 ;
V_23 -> V_93 . V_38 = V_282 -> V_38 ;
V_23 -> V_263 = V_263 ;
V_23 -> V_275 = V_282 -> V_275 ;
V_23 -> V_27 = V_282 -> V_27 ;
V_23 -> V_270 = V_271 ;
}
static struct V_280 * F_131 ( struct V_118 * V_118 , struct V_269 * V_23 , struct V_1 * * V_2 , int * V_119 )
{
struct V_280 * V_282 = F_132 ( V_118 , V_67 ) ;
int V_37 ;
if ( ! V_282 ) {
* V_119 = - V_68 ;
return NULL ;
}
F_129 ( V_282 , V_23 ) ;
V_37 = F_128 ( & V_282 -> type , V_2 ) ;
if ( V_37 )
goto error;
if ( ! ( V_37 = F_127 ( V_282 , V_2 ) ) )
V_37 = F_123 ( V_282 , V_2 ) ;
if ( V_37 )
goto error;
F_37 ( V_2 , & V_282 -> V_131 ) ;
return V_282 ;
error:
* V_119 = V_37 ;
V_282 -> V_197 . V_307 = 1 ;
F_133 ( V_282 ) ;
return NULL ;
}
static int F_134 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_269 * V_23 = F_45 ( V_147 ) ;
struct V_280 * V_282 ;
struct V_149 V_150 ;
int V_37 ;
int V_308 ;
V_37 = F_122 ( V_23 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_282 = F_131 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( ! V_282 )
return V_37 ;
V_308 = V_147 -> V_151 == V_309 ;
V_37 = F_135 ( V_23 -> V_263 , V_282 , V_308 ) ;
F_136 ( V_282 , V_37 ? 0 : 1 , true ) ;
if ( V_37 ) {
F_137 ( V_282 -> V_186 ) ;
F_28 ( V_282 ) ;
return V_37 ;
}
V_150 . V_156 = V_147 -> V_151 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
F_138 ( V_282 , V_23 -> V_263 , & V_150 ) ;
F_139 ( V_282 ) ;
return 0 ;
}
static int F_140 ( struct V_280 * V_282 , struct V_144 * V_145 )
{
struct V_283 V_310 [ V_298 ] ;
int V_286 ;
if ( V_282 -> V_287 == 0 )
return 0 ;
for ( V_286 = 0 ; V_286 < V_282 -> V_287 ; V_286 ++ ) {
struct V_283 * V_85 = & V_310 [ V_286 ] ;
struct V_288 * V_311 = & V_282 -> V_290 [ V_286 ] ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
memcpy ( & V_85 -> V_32 , & V_311 -> V_32 , sizeof( V_85 -> V_32 ) ) ;
V_85 -> V_38 = V_311 -> V_297 ;
memcpy ( & V_85 -> V_96 , & V_311 -> V_96 , sizeof( V_85 -> V_96 ) ) ;
V_85 -> V_95 = V_311 -> V_95 ;
V_85 -> V_45 = V_311 -> V_45 ;
V_85 -> V_270 = V_311 -> V_270 ;
V_85 -> V_292 = V_311 -> V_292 ;
V_85 -> V_293 = V_311 -> V_293 ;
V_85 -> V_294 = V_311 -> V_294 ;
V_85 -> V_295 = V_311 -> V_295 ;
}
return F_70 ( V_145 , V_299 ,
sizeof( struct V_283 ) * V_282 -> V_287 , V_310 ) ;
}
static inline int F_141 ( struct V_56 * V_57 , struct V_144 * V_145 )
{
if ( V_57 -> V_186 ) {
return F_64 ( V_57 -> V_186 , V_145 ) ;
}
return 0 ;
}
static inline int F_142 ( struct V_280 * V_282 , struct V_144 * V_145 )
{
if ( V_282 -> V_186 )
return F_64 ( V_282 -> V_186 , V_145 ) ;
return 0 ;
}
static inline T_4 F_143 ( void )
{
#ifdef F_121
return F_94 ( sizeof( struct V_303 ) ) ;
#else
return 0 ;
#endif
}
static int F_144 ( T_2 type , struct V_144 * V_145 )
{
struct V_303 V_304 = {
. type = type ,
} ;
return F_70 ( V_145 , V_302 , sizeof( V_304 ) , & V_304 ) ;
}
static inline int F_144 ( T_2 type , struct V_144 * V_145 )
{
return 0 ;
}
static int F_145 ( struct V_280 * V_282 , int V_263 , int V_187 , void * V_188 )
{
struct V_189 * V_190 = V_188 ;
struct V_269 * V_23 ;
struct V_144 * V_191 = V_190 -> V_191 ;
struct V_144 * V_145 = V_190 -> V_192 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , F_75 ( V_191 ) . V_154 , V_190 -> V_153 ,
V_309 , sizeof( * V_23 ) , V_190 -> V_193 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_23 = F_45 ( V_147 ) ;
F_130 ( V_282 , V_23 , V_263 ) ;
V_37 = F_140 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_142 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_144 ( V_282 -> type , V_145 ) ;
if ( ! V_37 )
V_37 = F_72 ( V_145 , & V_282 -> V_131 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_146 ( struct V_194 * V_195 )
{
struct V_312 * V_197 = (struct V_312 * ) V_195 -> args ;
struct V_118 * V_118 = F_44 ( V_195 -> V_145 -> V_148 ) ;
F_147 ( V_197 , V_118 ) ;
return 0 ;
}
static int F_148 ( struct V_194 * V_195 )
{
struct V_312 * V_197 = (struct V_312 * ) V_195 -> args ;
F_81 ( sizeof( * V_197 ) > sizeof( V_195 -> args ) ) ;
F_149 ( V_197 , V_313 ) ;
return 0 ;
}
static int F_150 ( struct V_144 * V_145 , struct V_194 * V_195 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_312 * V_197 = (struct V_312 * ) V_195 -> args ;
struct V_189 V_199 ;
V_199 . V_191 = V_195 -> V_145 ;
V_199 . V_192 = V_145 ;
V_199 . V_153 = V_195 -> V_147 -> V_153 ;
V_199 . V_193 = V_200 ;
( void ) V_312 ( V_118 , V_197 , F_145 , & V_199 ) ;
return V_145 -> V_20 ;
}
static struct V_144 * F_151 ( struct V_144 * V_191 ,
struct V_280 * V_282 ,
int V_263 , T_3 V_136 )
{
struct V_189 V_199 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_86 ( V_207 , V_67 ) ;
if ( ! V_145 )
return F_87 ( - V_68 ) ;
V_199 . V_191 = V_191 ;
V_199 . V_192 = V_145 ;
V_199 . V_153 = V_136 ;
V_199 . V_193 = 0 ;
V_37 = F_145 ( V_282 , V_263 , 0 , & V_199 ) ;
if ( V_37 ) {
F_88 ( V_145 ) ;
return F_87 ( V_37 ) ;
}
return V_145 ;
}
static int F_152 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_280 * V_282 ;
struct V_314 * V_23 ;
T_2 type = V_267 ;
int V_37 ;
struct V_149 V_150 ;
int V_315 ;
struct V_158 V_159 ;
T_3 V_131 = F_37 ( V_2 , & V_159 ) ;
V_23 = F_45 ( V_147 ) ;
V_315 = V_147 -> V_151 == V_316 ;
V_37 = F_128 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_119 ( V_23 -> V_263 ) ;
if ( V_37 )
return V_37 ;
if ( V_23 -> V_278 )
V_282 = F_153 ( V_118 , V_131 , type , V_23 -> V_263 , V_23 -> V_278 , V_315 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_91 * V_317 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_317 = NULL ;
if ( V_4 ) {
struct V_18 * V_19 = F_2 ( V_4 ) ;
V_37 = F_124 ( & V_317 , V_19 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_282 = F_154 ( V_118 , V_131 , type , V_23 -> V_263 , & V_23 -> V_93 ,
V_317 , V_315 , & V_37 ) ;
F_137 ( V_317 ) ;
}
if ( V_282 == NULL )
return - V_262 ;
if ( ! V_315 ) {
struct V_144 * V_257 ;
V_257 = F_151 ( V_145 , V_282 , V_23 -> V_263 , V_147 -> V_153 ) ;
if ( F_111 ( V_257 ) ) {
V_37 = F_112 ( V_257 ) ;
} else {
V_37 = F_105 ( V_118 -> V_137 . V_211 , V_257 ,
F_75 ( V_145 ) . V_154 ) ;
}
} else {
F_155 ( V_282 , V_37 ? 0 : 1 , true ) ;
if ( V_37 != 0 )
goto V_43;
V_150 . V_318 . V_319 = V_23 -> V_278 ;
V_150 . V_156 = V_147 -> V_151 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
F_138 ( V_282 , V_23 -> V_263 , & V_150 ) ;
}
V_43:
F_139 ( V_282 ) ;
return V_37 ;
}
static int F_156 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_149 V_150 ;
struct V_320 * V_23 = F_45 ( V_147 ) ;
int V_37 ;
V_37 = F_157 ( V_118 , V_23 -> V_33 , true ) ;
if ( V_37 ) {
if ( V_37 == - V_161 )
return 0 ;
return V_37 ;
}
V_150 . V_318 . V_33 = V_23 -> V_33 ;
V_150 . V_156 = V_147 -> V_151 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
V_150 . V_118 = V_118 ;
F_52 ( NULL , & V_150 ) ;
return 0 ;
}
static inline T_4 F_158 ( struct V_56 * V_57 )
{
T_4 V_321 = V_57 -> V_83 ?
F_12 ( V_57 -> V_83 ) :
sizeof( struct V_106 ) ;
return F_93 ( sizeof( struct V_322 ) )
+ F_94 ( V_321 )
+ F_159 ( sizeof( struct V_109 ) )
+ F_94 ( sizeof( struct V_158 ) )
+ F_94 ( 4 )
+ F_94 ( 4 ) ;
}
static int F_160 ( struct V_144 * V_145 , struct V_56 * V_57 , const struct V_149 * V_150 )
{
struct V_322 * V_32 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , V_150 -> V_136 , V_323 , sizeof( * V_32 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_32 = F_45 ( V_147 ) ;
memset ( & V_32 -> V_324 , 0 , sizeof( V_32 -> V_324 ) ) ;
memcpy ( & V_32 -> V_324 . V_162 , & V_57 -> V_32 . V_162 , sizeof( V_57 -> V_32 . V_162 ) ) ;
V_32 -> V_324 . V_48 = V_57 -> V_32 . V_48 ;
V_32 -> V_324 . V_38 = V_57 -> V_63 . V_38 ;
V_32 -> V_324 . V_33 = V_57 -> V_32 . V_33 ;
memcpy ( & V_32 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_57 -> V_63 . V_96 ) ) ;
V_32 -> V_95 = V_57 -> V_63 . V_95 ;
V_32 -> V_27 = V_150 -> V_318 . V_325 ;
if ( V_57 -> V_83 ) {
V_37 = F_70 ( V_145 , V_24 ,
F_12 ( V_57 -> V_83 ) ,
V_57 -> V_83 ) ;
} else {
V_37 = F_70 ( V_145 , V_99 , sizeof( V_57 -> V_107 ) ,
& V_57 -> V_107 ) ;
}
if ( V_37 )
goto V_326;
V_37 = F_161 ( V_145 , V_102 , sizeof( V_57 -> V_111 ) , & V_57 -> V_111 ,
V_185 ) ;
if ( V_37 )
goto V_326;
if ( V_32 -> V_27 & V_327 ) {
V_37 = F_69 ( V_145 , V_105 , V_57 -> V_117 ) ;
if ( V_37 )
goto V_326;
}
if ( V_32 -> V_27 & V_328 ) {
V_37 = F_69 ( V_145 , V_104 ,
V_57 -> V_116 * 10 / V_140 ) ;
if ( V_37 )
goto V_326;
}
V_37 = F_72 ( V_145 , & V_57 -> V_131 ) ;
if ( V_37 )
goto V_326;
F_77 ( V_145 , V_147 ) ;
return 0 ;
V_326:
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
static int F_162 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_56 * V_57 ;
struct V_144 * V_246 ;
int V_37 ;
struct V_149 V_150 ;
T_3 V_131 ;
struct V_158 V_159 ;
struct V_322 * V_23 = F_45 ( V_147 ) ;
struct V_157 * V_32 = & V_23 -> V_324 ;
V_131 = F_37 ( V_2 , & V_159 ) ;
V_57 = F_55 ( V_118 , V_131 , & V_32 -> V_162 , V_32 -> V_48 , V_32 -> V_33 , V_32 -> V_38 ) ;
if ( V_57 == NULL )
return - V_161 ;
V_246 = F_86 ( F_158 ( V_57 ) , V_208 ) ;
if ( V_246 == NULL ) {
F_42 ( V_57 ) ;
return - V_68 ;
}
F_163 ( & V_57 -> V_233 ) ;
V_150 . V_318 . V_325 = V_23 -> V_27 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
if ( F_160 ( V_246 , V_57 , & V_150 ) < 0 )
F_104 () ;
V_37 = F_105 ( V_118 -> V_137 . V_211 , V_246 , F_75 ( V_145 ) . V_154 ) ;
F_164 ( & V_57 -> V_233 ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_165 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_56 * V_57 ;
struct V_149 V_150 ;
int V_37 = - V_7 ;
T_3 V_131 = 0 ;
struct V_158 V_159 ;
struct V_322 * V_23 = F_45 ( V_147 ) ;
struct V_1 * V_84 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_2 [ V_24 ] ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
struct V_1 * V_103 = V_2 [ V_104 ] ;
struct V_1 * V_4 = V_2 [ V_105 ] ;
if ( ! V_101 && ! V_84 && ! V_100 && ! V_103 && ! V_4 )
return V_37 ;
if ( ! ( V_147 -> V_193 & V_329 ) )
return V_37 ;
V_131 = F_37 ( V_2 , & V_159 ) ;
V_57 = F_55 ( V_118 , V_131 , & V_23 -> V_324 . V_162 , V_23 -> V_324 . V_48 , V_23 -> V_324 . V_33 , V_23 -> V_324 . V_38 ) ;
if ( V_57 == NULL )
return - V_161 ;
if ( V_57 -> V_135 . V_142 != V_330 )
goto V_43;
V_37 = F_25 ( V_57 -> V_83 , V_100 ) ;
if ( V_37 )
goto V_43;
F_163 ( & V_57 -> V_233 ) ;
F_32 ( V_57 , V_2 , 1 ) ;
F_164 ( & V_57 -> V_233 ) ;
V_150 . V_156 = V_147 -> V_151 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
V_150 . V_318 . V_325 = V_331 ;
F_52 ( V_57 , & V_150 ) ;
V_37 = 0 ;
V_43:
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_166 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_149 V_150 ;
T_2 type = V_267 ;
int V_37 ;
V_37 = F_128 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_167 ( V_118 , type , true ) ;
if ( V_37 ) {
if ( V_37 == - V_161 )
return 0 ;
return V_37 ;
}
V_150 . V_318 . type = type ;
V_150 . V_156 = V_147 -> V_151 ;
V_150 . V_136 = V_147 -> V_153 ;
V_150 . V_154 = V_147 -> V_155 ;
V_150 . V_118 = V_118 ;
F_138 ( NULL , 0 , & V_150 ) ;
return 0 ;
}
static int F_168 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_280 * V_282 ;
struct V_332 * V_85 = F_45 ( V_147 ) ;
struct V_269 * V_23 = & V_85 -> V_281 ;
T_2 type = V_267 ;
int V_37 = - V_262 ;
struct V_158 V_159 ;
T_3 V_131 = F_37 ( V_2 , & V_159 ) ;
V_37 = F_128 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_119 ( V_23 -> V_263 ) ;
if ( V_37 )
return V_37 ;
if ( V_23 -> V_278 )
V_282 = F_153 ( V_118 , V_131 , type , V_23 -> V_263 , V_23 -> V_278 , 0 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_91 * V_317 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_317 = NULL ;
if ( V_4 ) {
struct V_18 * V_19 = F_2 ( V_4 ) ;
V_37 = F_124 ( & V_317 , V_19 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_282 = F_154 ( V_118 , V_131 , type , V_23 -> V_263 ,
& V_23 -> V_93 , V_317 , 0 , & V_37 ) ;
F_137 ( V_317 ) ;
}
if ( V_282 == NULL )
return - V_262 ;
if ( F_169 ( V_282 -> V_197 . V_307 ) )
goto V_43;
V_37 = 0 ;
if ( V_85 -> V_333 ) {
F_170 ( V_282 , V_23 -> V_263 ) ;
F_155 ( V_282 , 1 , true ) ;
}
F_171 ( V_282 , V_23 -> V_263 , V_85 -> V_333 , V_147 -> V_155 ) ;
V_43:
F_139 ( V_282 ) ;
return V_37 ;
}
static int F_172 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_56 * V_57 ;
int V_37 ;
struct V_334 * V_335 = F_45 ( V_147 ) ;
struct V_22 * V_23 = & V_335 -> V_142 ;
struct V_158 V_159 ;
T_3 V_131 = F_37 ( V_2 , & V_159 ) ;
V_57 = F_55 ( V_118 , V_131 , & V_23 -> V_32 . V_162 , V_23 -> V_32 . V_48 , V_23 -> V_32 . V_33 , V_23 -> V_38 ) ;
V_37 = - V_262 ;
if ( V_57 == NULL )
return V_37 ;
F_163 ( & V_57 -> V_233 ) ;
V_37 = - V_7 ;
if ( V_57 -> V_135 . V_142 != V_330 )
goto V_43;
F_173 ( V_57 , V_335 -> V_333 , V_147 -> V_155 ) ;
if ( V_335 -> V_333 ) {
F_174 ( V_57 ) ;
F_61 ( V_57 , 1 , true ) ;
}
V_37 = 0 ;
V_43:
F_164 ( & V_57 -> V_233 ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_175 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_280 * V_282 ;
struct V_283 * V_284 ;
int V_286 ;
struct V_1 * V_4 = V_2 [ V_299 ] ;
struct V_158 V_131 ;
struct V_336 * V_337 = F_45 ( V_147 ) ;
struct V_56 * V_57 = F_35 ( V_118 ) ;
int V_37 = - V_68 ;
if ( ! V_57 )
goto V_338;
F_37 ( V_2 , & V_131 ) ;
V_37 = F_122 ( & V_337 -> V_339 ) ;
if ( V_37 )
goto V_340;
V_282 = F_131 ( V_118 , & V_337 -> V_339 , V_2 , & V_37 ) ;
if ( ! V_282 )
goto V_340;
memcpy ( & V_57 -> V_32 , & V_337 -> V_32 , sizeof( V_337 -> V_32 ) ) ;
memcpy ( & V_57 -> V_63 . V_96 , & V_337 -> V_96 , sizeof( V_337 -> V_96 ) ) ;
memcpy ( & V_57 -> V_93 , & V_337 -> V_93 , sizeof( V_337 -> V_93 ) ) ;
V_282 -> V_131 . V_159 = V_57 -> V_131 . V_159 = V_131 . V_159 ;
V_282 -> V_131 . V_341 = V_57 -> V_131 . V_341 = V_131 . V_341 ;
V_284 = F_2 ( V_4 ) ;
for ( V_286 = 0 ; V_286 < V_282 -> V_287 ; V_286 ++ , V_284 ++ ) {
struct V_288 * V_289 = & V_282 -> V_290 [ V_286 ] ;
memcpy ( & V_57 -> V_32 , & V_289 -> V_32 , sizeof( V_57 -> V_32 ) ) ;
V_57 -> V_63 . V_45 = V_289 -> V_45 ;
V_57 -> V_63 . V_95 = V_289 -> V_95 ;
V_57 -> V_63 . V_38 = V_284 -> V_38 ;
V_289 -> V_293 = V_337 -> V_293 ;
V_289 -> V_294 = V_337 -> V_294 ;
V_289 -> V_295 = V_337 -> V_295 ;
V_37 = F_176 ( V_57 , V_289 , V_282 ) ;
}
F_28 ( V_57 ) ;
F_28 ( V_282 ) ;
return 0 ;
V_340:
F_28 ( V_57 ) ;
V_338:
return V_37 ;
}
static int F_177 ( struct V_342 * V_343 ,
struct V_344 * V_345 ,
struct V_1 * * V_2 , int * V_346 )
{
struct V_1 * V_4 = V_2 [ V_347 ] ;
struct V_348 * V_349 ;
int V_286 , V_350 ;
if ( V_345 != NULL ) {
struct V_351 * V_352 ;
V_352 = F_2 ( V_2 [ V_353 ] ) ;
memcpy ( & V_345 -> V_354 , & V_352 -> V_354 , sizeof( V_345 -> V_354 ) ) ;
memcpy ( & V_345 -> V_355 , & V_352 -> V_355 , sizeof( V_345 -> V_355 ) ) ;
V_345 -> V_38 = V_352 -> V_38 ;
V_345 -> V_356 = V_352 -> V_356 ;
}
V_349 = F_2 ( V_4 ) ;
V_350 = F_3 ( V_4 ) / sizeof( * V_349 ) ;
if ( V_350 <= 0 || V_350 > V_298 )
return - V_7 ;
for ( V_286 = 0 ; V_286 < V_350 ; V_286 ++ , V_349 ++ , V_343 ++ ) {
memcpy ( & V_343 -> V_357 , & V_349 -> V_357 , sizeof( V_343 -> V_357 ) ) ;
memcpy ( & V_343 -> V_358 , & V_349 -> V_358 , sizeof( V_343 -> V_358 ) ) ;
memcpy ( & V_343 -> V_359 , & V_349 -> V_359 , sizeof( V_343 -> V_359 ) ) ;
memcpy ( & V_343 -> V_360 , & V_349 -> V_360 , sizeof( V_343 -> V_360 ) ) ;
V_343 -> V_33 = V_349 -> V_33 ;
V_343 -> V_45 = V_349 -> V_45 ;
V_343 -> V_95 = V_349 -> V_95 ;
V_343 -> V_361 = V_349 -> V_361 ;
V_343 -> V_362 = V_349 -> V_362 ;
}
* V_346 = V_286 ;
return 0 ;
}
static int F_178 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
struct V_314 * V_363 = F_45 ( V_147 ) ;
struct V_342 V_159 [ V_298 ] ;
struct V_344 V_135 , * V_364 ;
T_2 type ;
int V_37 ;
int V_365 = 0 ;
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_366 * V_128 = NULL ;
if ( V_2 [ V_347 ] == NULL )
return - V_7 ;
V_364 = V_2 [ V_353 ] ? & V_135 : NULL ;
V_37 = F_128 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_177 ( (struct V_342 * ) V_159 , V_364 , V_2 , & V_365 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_365 )
return 0 ;
if ( V_2 [ V_51 ] ) {
V_128 = F_18 ( F_2 ( V_2 [ V_51 ] ) ,
sizeof( * V_128 ) , V_67 ) ;
if ( ! V_128 )
return 0 ;
}
V_37 = V_342 ( & V_363 -> V_93 , V_363 -> V_263 , type , V_159 , V_365 , V_364 , V_118 , V_128 ) ;
F_28 ( V_128 ) ;
return V_37 ;
}
static int F_178 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_1 * * V_2 )
{
return - V_367 ;
}
static int F_179 ( const struct V_342 * V_159 , struct V_144 * V_145 )
{
struct V_348 V_349 ;
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_349 . V_33 = V_159 -> V_33 ;
V_349 . V_45 = V_159 -> V_45 ;
V_349 . V_95 = V_159 -> V_95 ;
V_349 . V_361 = V_159 -> V_361 ;
memcpy ( & V_349 . V_357 , & V_159 -> V_357 , sizeof( V_349 . V_357 ) ) ;
memcpy ( & V_349 . V_358 , & V_159 -> V_358 , sizeof( V_349 . V_358 ) ) ;
V_349 . V_362 = V_159 -> V_362 ;
memcpy ( & V_349 . V_359 , & V_159 -> V_359 , sizeof( V_349 . V_359 ) ) ;
memcpy ( & V_349 . V_360 , & V_159 -> V_360 , sizeof( V_349 . V_360 ) ) ;
return F_70 ( V_145 , V_347 , sizeof( V_349 ) , & V_349 ) ;
}
static int F_180 ( const struct V_344 * V_345 , struct V_144 * V_145 )
{
struct V_351 V_352 ;
memset ( & V_352 , 0 , sizeof( V_352 ) ) ;
V_352 . V_38 = V_345 -> V_38 ;
V_352 . V_356 = V_345 -> V_356 ;
memcpy ( & V_352 . V_354 , & V_345 -> V_354 , sizeof( V_352 . V_354 ) ) ;
memcpy ( & V_352 . V_355 , & V_345 -> V_355 , sizeof( V_352 . V_355 ) ) ;
return F_70 ( V_145 , V_353 , sizeof( V_352 ) , & V_352 ) ;
}
static inline T_4 F_181 ( int V_350 , int V_368 ,
int V_369 )
{
return F_93 ( sizeof( struct V_314 ) )
+ ( V_368 ? F_94 ( sizeof( struct V_344 ) ) : 0 )
+ ( V_369 ? F_94 ( sizeof( struct V_366 ) ) : 0 )
+ F_94 ( sizeof( struct V_348 ) * V_350 )
+ F_143 () ;
}
static int F_182 ( struct V_144 * V_145 , const struct V_342 * V_159 ,
int V_350 , const struct V_344 * V_345 ,
const struct V_370 * V_93 ,
const struct V_366 * V_128 , T_2 V_263 , T_2 type )
{
const struct V_342 * V_371 ;
struct V_314 * V_372 ;
struct V_146 * V_147 ;
int V_286 , V_37 ;
V_147 = F_74 ( V_145 , 0 , 0 , V_373 , sizeof( * V_372 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_372 = F_45 ( V_147 ) ;
memset ( V_372 , 0 , sizeof( * V_372 ) ) ;
memcpy ( & V_372 -> V_93 , V_93 , sizeof( V_372 -> V_93 ) ) ;
V_372 -> V_263 = V_263 ;
if ( V_345 != NULL ) {
V_37 = F_180 ( V_345 , V_145 ) ;
if ( V_37 )
goto V_326;
}
if ( V_128 ) {
V_37 = F_70 ( V_145 , V_51 , sizeof( * V_128 ) , V_128 ) ;
if ( V_37 )
goto V_326;
}
V_37 = F_144 ( type , V_145 ) ;
if ( V_37 )
goto V_326;
for ( V_286 = 0 , V_371 = V_159 ; V_286 < V_350 ; V_286 ++ , V_371 ++ ) {
V_37 = F_179 ( V_371 , V_145 ) ;
if ( V_37 )
goto V_326;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
V_326:
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
static int F_183 ( const struct V_370 * V_93 , T_2 V_263 , T_2 type ,
const struct V_342 * V_159 , int V_350 ,
const struct V_344 * V_345 ,
const struct V_366 * V_128 )
{
struct V_118 * V_118 = & V_374 ;
struct V_144 * V_145 ;
V_145 = F_86 ( F_181 ( V_350 , ! ! V_345 , ! ! V_128 ) ,
V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_182 ( V_145 , V_159 , V_350 , V_345 , V_93 , V_128 , V_263 , type ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_375 ) ;
}
static int F_183 ( const struct V_370 * V_93 , T_2 V_263 , T_2 type ,
const struct V_342 * V_159 , int V_350 ,
const struct V_344 * V_345 ,
const struct V_366 * V_128 )
{
return - V_367 ;
}
static int F_184 ( struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_376 * V_377 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
struct V_1 * V_2 [ V_201 + 1 ] ;
const struct V_378 * V_379 ;
int type , V_37 ;
#ifdef F_185
if ( F_186 () )
return - V_380 ;
#endif
type = V_147 -> V_151 ;
if ( type > V_381 )
return - V_7 ;
type -= V_382 ;
V_379 = & V_383 [ type ] ;
if ( ! F_187 ( V_145 , V_384 ) )
return - V_164 ;
if ( ( type == ( V_385 - V_382 ) ||
type == ( V_386 - V_382 ) ) &&
( V_147 -> V_193 & V_387 ) ) {
if ( V_379 -> V_388 == NULL )
return - V_7 ;
{
struct V_389 V_150 = {
. V_390 = V_379 -> V_390 ,
. V_388 = V_379 -> V_388 ,
. V_391 = V_379 -> V_391 ,
} ;
return F_188 ( V_118 -> V_137 . V_211 , V_145 , V_147 , & V_150 ) ;
}
}
V_37 = F_82 ( V_147 , V_392 [ type ] , V_2 ,
V_379 -> V_393 ? : V_201 ,
V_379 -> V_394 ? : V_204 , V_377 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_379 -> V_395 == NULL )
return - V_7 ;
return V_379 -> V_395 ( V_145 , V_147 , V_2 ) ;
}
static void F_189 ( struct V_144 * V_145 )
{
struct V_118 * V_118 = F_44 ( V_145 -> V_148 ) ;
F_190 ( & V_118 -> V_137 . V_396 ) ;
F_191 ( V_145 , & F_184 ) ;
F_192 ( & V_118 -> V_137 . V_396 ) ;
}
static inline T_4 F_193 ( void )
{
return F_93 ( sizeof( struct V_334 ) )
+ F_94 ( sizeof( struct V_158 ) ) ;
}
static int F_194 ( struct V_144 * V_145 , struct V_56 * V_57 , const struct V_149 * V_150 )
{
struct V_334 * V_335 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , 0 , V_397 , sizeof( * V_335 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_335 = F_45 ( V_147 ) ;
F_62 ( V_57 , & V_335 -> V_142 ) ;
V_335 -> V_333 = ( V_150 -> V_318 . V_333 != 0 ) ? 1 : 0 ;
memset ( & V_335 -> V_333 + 1 , 0 , sizeof( * V_335 ) - F_195 ( F_196 ( * V_335 ) , V_333 ) ) ;
V_37 = F_72 ( V_145 , & V_57 -> V_131 ) ;
if ( V_37 )
return V_37 ;
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_197 ( struct V_56 * V_57 , const struct V_149 * V_150 )
{
struct V_118 * V_118 = F_198 ( V_57 ) ;
struct V_144 * V_145 ;
V_145 = F_86 ( F_193 () , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_194 ( V_145 , V_57 , V_150 ) < 0 ) {
F_88 ( V_145 ) ;
return - V_170 ;
}
return F_89 ( V_118 , V_145 , 0 , V_398 ) ;
}
static int F_199 ( struct V_56 * V_57 , const struct V_149 * V_150 )
{
struct V_118 * V_118 = F_198 ( V_57 ) ;
struct V_144 * V_145 ;
V_145 = F_86 ( F_158 ( V_57 ) , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_160 ( V_145 , V_57 , V_150 ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_399 ) ;
}
static int F_200 ( const struct V_149 * V_150 )
{
struct V_118 * V_118 = V_150 -> V_118 ;
struct V_320 * V_23 ;
struct V_146 * V_147 ;
struct V_144 * V_145 ;
int V_20 = F_93 ( sizeof( struct V_320 ) ) ;
V_145 = F_86 ( V_20 , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , V_150 -> V_136 , V_400 , sizeof( * V_23 ) , 0 ) ;
if ( V_147 == NULL ) {
F_88 ( V_145 ) ;
return - V_170 ;
}
V_23 = F_45 ( V_147 ) ;
V_23 -> V_33 = V_150 -> V_318 . V_33 ;
F_77 ( V_145 , V_147 ) ;
return F_89 ( V_118 , V_145 , 0 , V_401 ) ;
}
static inline T_4 F_201 ( struct V_56 * V_57 )
{
T_4 V_402 = 0 ;
if ( V_57 -> V_82 )
V_402 += F_94 ( F_8 ( V_57 -> V_82 ) ) ;
if ( V_57 -> V_123 ) {
V_402 += F_94 ( sizeof( struct V_5 ) +
( V_57 -> V_123 -> V_75 + 7 ) / 8 ) ;
V_402 += F_94 ( F_6 ( V_57 -> V_123 ) ) ;
}
if ( V_57 -> V_70 )
V_402 += F_94 ( F_4 ( V_57 -> V_70 ) ) ;
if ( V_57 -> V_125 )
V_402 += F_94 ( sizeof( * V_57 -> V_125 ) ) ;
if ( V_57 -> V_128 )
V_402 += F_94 ( sizeof( * V_57 -> V_128 ) ) ;
if ( V_57 -> V_129 )
V_402 += F_94 ( sizeof( V_57 -> V_129 ) ) ;
if ( V_57 -> V_83 )
V_402 += F_94 ( F_12 ( V_57 -> V_83 ) ) ;
else
V_402 += F_94 ( sizeof( struct V_106 ) ) ;
if ( V_57 -> V_186 )
V_402 += F_94 ( sizeof( struct V_18 ) +
V_57 -> V_186 -> V_21 ) ;
if ( V_57 -> V_130 )
V_402 += F_94 ( sizeof( * V_57 -> V_130 ) ) ;
if ( V_57 -> V_63 . V_122 )
V_402 += F_94 ( sizeof( V_57 -> V_63 . V_122 ) ) ;
if ( V_57 -> V_176 . V_180 )
V_402 += F_94 ( sizeof( V_57 -> V_176 ) ) ;
if ( V_57 -> V_63 . V_133 )
V_402 += F_94 ( sizeof( V_57 -> V_63 . V_133 ) ) ;
V_402 += F_159 ( sizeof( V_403 ) ) ;
return V_402 ;
}
static int F_202 ( struct V_56 * V_57 , const struct V_149 * V_150 )
{
struct V_118 * V_118 = F_198 ( V_57 ) ;
struct V_22 * V_23 ;
struct V_157 * V_32 ;
struct V_146 * V_147 ;
struct V_144 * V_145 ;
int V_20 = F_201 ( V_57 ) ;
int V_404 , V_37 ;
V_404 = sizeof( * V_23 ) ;
if ( V_150 -> V_156 == V_405 ) {
V_20 += F_94 ( V_404 ) ;
V_404 = sizeof( * V_32 ) ;
V_20 += F_94 ( sizeof( struct V_158 ) ) ;
}
V_20 += F_93 ( V_404 ) ;
V_145 = F_86 ( V_20 , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , V_150 -> V_136 , V_150 -> V_156 , V_404 , 0 ) ;
V_37 = - V_170 ;
if ( V_147 == NULL )
goto V_406;
V_23 = F_45 ( V_147 ) ;
if ( V_150 -> V_156 == V_405 ) {
struct V_1 * V_168 ;
V_32 = F_45 ( V_147 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
memcpy ( & V_32 -> V_162 , & V_57 -> V_32 . V_162 , sizeof( V_32 -> V_162 ) ) ;
V_32 -> V_48 = V_57 -> V_32 . V_48 ;
V_32 -> V_38 = V_57 -> V_63 . V_38 ;
V_32 -> V_33 = V_57 -> V_32 . V_33 ;
V_168 = F_65 ( V_145 , V_407 , sizeof( * V_23 ) ) ;
V_37 = - V_170 ;
if ( V_168 == NULL )
goto V_406;
V_23 = F_2 ( V_168 ) ;
}
V_37 = F_68 ( V_57 , V_23 , V_145 ) ;
if ( V_37 )
goto V_406;
F_77 ( V_145 , V_147 ) ;
return F_89 ( V_118 , V_145 , 0 , V_401 ) ;
V_406:
F_88 ( V_145 ) ;
return V_37 ;
}
static int F_203 ( struct V_56 * V_57 , const struct V_149 * V_150 )
{
switch ( V_150 -> V_156 ) {
case V_397 :
return F_197 ( V_57 , V_150 ) ;
case V_323 :
return F_199 ( V_57 , V_150 ) ;
case V_405 :
case V_408 :
case V_152 :
return F_202 ( V_57 , V_150 ) ;
case V_400 :
return F_200 ( V_150 ) ;
default:
F_204 ( V_409 L_1 ,
V_150 -> V_156 ) ;
break;
}
return 0 ;
}
static inline T_4 F_205 ( struct V_56 * V_57 ,
struct V_280 * V_282 )
{
return F_93 ( sizeof( struct V_336 ) )
+ F_94 ( sizeof( struct V_283 ) * V_282 -> V_287 )
+ F_94 ( sizeof( struct V_158 ) )
+ F_94 ( F_29 ( V_57 -> V_186 ) )
+ F_143 () ;
}
static int F_206 ( struct V_144 * V_145 , struct V_56 * V_57 ,
struct V_288 * V_410 , struct V_280 * V_282 )
{
V_87 V_136 = F_207 () ;
struct V_336 * V_337 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , 0 , 0 , V_411 , sizeof( * V_337 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_337 = F_45 ( V_147 ) ;
memcpy ( & V_337 -> V_32 , & V_57 -> V_32 , sizeof( V_337 -> V_32 ) ) ;
memcpy ( & V_337 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_337 -> V_96 ) ) ;
memcpy ( & V_337 -> V_93 , & V_57 -> V_93 , sizeof( V_337 -> V_93 ) ) ;
F_130 ( V_282 , & V_337 -> V_339 , V_265 ) ;
V_337 -> V_293 = V_410 -> V_293 ;
V_337 -> V_294 = V_410 -> V_294 ;
V_337 -> V_295 = V_410 -> V_295 ;
V_337 -> V_136 = V_57 -> V_135 . V_136 = V_136 ;
V_37 = F_140 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_141 ( V_57 , V_145 ) ;
if ( ! V_37 )
V_37 = F_144 ( V_282 -> type , V_145 ) ;
if ( ! V_37 )
V_37 = F_72 ( V_145 , & V_282 -> V_131 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_208 ( struct V_56 * V_57 , struct V_288 * V_410 ,
struct V_280 * V_282 )
{
struct V_118 * V_118 = F_198 ( V_57 ) ;
struct V_144 * V_145 ;
V_145 = F_86 ( F_205 ( V_57 , V_282 ) , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_206 ( V_145 , V_57 , V_410 , V_282 ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_412 ) ;
}
static struct V_280 * F_209 ( struct V_198 * V_148 , int V_413 ,
T_2 * V_318 , int V_20 , int * V_263 )
{
struct V_118 * V_118 = F_44 ( V_148 ) ;
struct V_269 * V_23 = (struct V_269 * ) V_318 ;
struct V_283 * V_284 = (struct V_283 * ) ( V_23 + 1 ) ;
struct V_280 * V_282 ;
int V_285 ;
switch ( V_148 -> V_414 ) {
case V_39 :
if ( V_413 != V_415 ) {
* V_263 = - V_380 ;
return NULL ;
}
break;
#if F_14 ( V_41 )
case V_40 :
if ( V_413 != V_416 ) {
* V_263 = - V_380 ;
return NULL ;
}
break;
#endif
default:
* V_263 = - V_7 ;
return NULL ;
}
* V_263 = - V_7 ;
if ( V_20 < sizeof( * V_23 ) ||
F_122 ( V_23 ) )
return NULL ;
V_285 = ( ( V_20 - sizeof( * V_23 ) ) / sizeof( * V_284 ) ) ;
if ( F_126 ( V_285 , V_284 , V_23 -> V_93 . V_38 ) )
return NULL ;
if ( V_23 -> V_263 > V_265 )
return NULL ;
V_282 = F_132 ( V_118 , V_208 ) ;
if ( V_282 == NULL ) {
* V_263 = - V_417 ;
return NULL ;
}
F_129 ( V_282 , V_23 ) ;
V_282 -> type = V_267 ;
F_125 ( V_282 , V_284 , V_285 ) ;
* V_263 = V_23 -> V_263 ;
return V_282 ;
}
static inline T_4 F_210 ( struct V_280 * V_282 )
{
return F_93 ( sizeof( struct V_332 ) )
+ F_94 ( sizeof( struct V_283 ) * V_282 -> V_287 )
+ F_94 ( F_29 ( V_282 -> V_186 ) )
+ F_94 ( sizeof( struct V_158 ) )
+ F_143 () ;
}
static int F_211 ( struct V_144 * V_145 , struct V_280 * V_282 ,
int V_263 , const struct V_149 * V_150 )
{
struct V_332 * V_418 ;
int V_333 = V_150 -> V_318 . V_333 ;
struct V_146 * V_147 ;
int V_37 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , 0 , V_419 , sizeof( * V_418 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_418 = F_45 ( V_147 ) ;
F_130 ( V_282 , & V_418 -> V_281 , V_263 ) ;
V_37 = F_140 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_142 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_144 ( V_282 -> type , V_145 ) ;
if ( ! V_37 )
V_37 = F_72 ( V_145 , & V_282 -> V_131 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
V_418 -> V_333 = ! ! V_333 ;
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_212 ( struct V_280 * V_282 , int V_263 , const struct V_149 * V_150 )
{
struct V_118 * V_118 = F_213 ( V_282 ) ;
struct V_144 * V_145 ;
V_145 = F_86 ( F_210 ( V_282 ) , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_211 ( V_145 , V_282 , V_263 , V_150 ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_398 ) ;
}
static int F_214 ( struct V_280 * V_282 , int V_263 , const struct V_149 * V_150 )
{
int V_20 = F_94 ( sizeof( struct V_283 ) * V_282 -> V_287 ) ;
struct V_118 * V_118 = F_213 ( V_282 ) ;
struct V_269 * V_23 ;
struct V_314 * V_32 ;
struct V_146 * V_147 ;
struct V_144 * V_145 ;
int V_404 , V_37 ;
V_404 = sizeof( * V_23 ) ;
if ( V_150 -> V_156 == V_316 ) {
V_20 += F_94 ( V_404 ) ;
V_404 = sizeof( * V_32 ) ;
}
V_20 += F_143 () ;
V_20 += F_94 ( sizeof( struct V_158 ) ) ;
V_20 += F_93 ( V_404 ) ;
V_145 = F_86 ( V_20 , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , V_150 -> V_136 , V_150 -> V_156 , V_404 , 0 ) ;
V_37 = - V_170 ;
if ( V_147 == NULL )
goto V_406;
V_23 = F_45 ( V_147 ) ;
if ( V_150 -> V_156 == V_316 ) {
struct V_1 * V_168 ;
V_32 = F_45 ( V_147 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_263 = V_263 ;
if ( V_150 -> V_318 . V_319 )
V_32 -> V_278 = V_282 -> V_278 ;
else
memcpy ( & V_32 -> V_93 , & V_282 -> V_306 , sizeof( V_32 -> V_93 ) ) ;
V_168 = F_65 ( V_145 , V_420 , sizeof( * V_23 ) ) ;
V_37 = - V_170 ;
if ( V_168 == NULL )
goto V_406;
V_23 = F_2 ( V_168 ) ;
}
F_130 ( V_282 , V_23 , V_263 ) ;
V_37 = F_140 ( V_282 , V_145 ) ;
if ( ! V_37 )
V_37 = F_144 ( V_282 -> type , V_145 ) ;
if ( ! V_37 )
V_37 = F_72 ( V_145 , & V_282 -> V_131 ) ;
if ( V_37 )
goto V_406;
F_77 ( V_145 , V_147 ) ;
return F_89 ( V_118 , V_145 , 0 , V_421 ) ;
V_406:
F_88 ( V_145 ) ;
return V_37 ;
}
static int F_215 ( const struct V_149 * V_150 )
{
struct V_118 * V_118 = V_150 -> V_118 ;
struct V_146 * V_147 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_86 ( F_143 () , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
V_147 = F_74 ( V_145 , V_150 -> V_154 , V_150 -> V_136 , V_422 , 0 , 0 ) ;
V_37 = - V_170 ;
if ( V_147 == NULL )
goto V_406;
V_37 = F_144 ( V_150 -> V_318 . type , V_145 ) ;
if ( V_37 )
goto V_406;
F_77 ( V_145 , V_147 ) ;
return F_89 ( V_118 , V_145 , 0 , V_421 ) ;
V_406:
F_88 ( V_145 ) ;
return V_37 ;
}
static int F_216 ( struct V_280 * V_282 , int V_263 , const struct V_149 * V_150 )
{
switch ( V_150 -> V_156 ) {
case V_309 :
case V_423 :
case V_316 :
return F_214 ( V_282 , V_263 , V_150 ) ;
case V_422 :
return F_215 ( V_150 ) ;
case V_419 :
return F_212 ( V_282 , V_263 , V_150 ) ;
default:
F_204 ( V_409 L_2 ,
V_150 -> V_156 ) ;
}
return 0 ;
}
static inline T_4 F_217 ( void )
{
return F_93 ( sizeof( struct V_424 ) ) ;
}
static int F_218 ( struct V_144 * V_145 , T_2 V_33 ,
struct V_370 * V_93 , T_1 * V_425 )
{
struct V_424 * V_426 ;
struct V_146 * V_147 ;
V_147 = F_74 ( V_145 , 0 , 0 , V_427 , sizeof( * V_426 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_426 = F_45 ( V_147 ) ;
V_426 -> V_33 = V_33 ;
memcpy ( & V_426 -> V_93 , V_93 , sizeof( V_426 -> V_93 ) ) ;
if ( V_425 ) {
int V_37 = F_70 ( V_145 , V_52 , sizeof( * V_425 ) , V_425 ) ;
if ( V_37 ) {
F_76 ( V_145 , V_147 ) ;
return V_37 ;
}
}
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_219 ( struct V_118 * V_118 , T_2 V_33 ,
struct V_370 * V_93 , T_1 * V_425 )
{
struct V_144 * V_145 ;
V_145 = F_86 ( F_217 () , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_218 ( V_145 , V_33 , V_93 , V_425 ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_428 ) ;
}
static inline T_4 F_220 ( void )
{
return F_93 ( sizeof( struct V_429 ) ) ;
}
static int F_221 ( struct V_144 * V_145 , struct V_56 * V_57 ,
T_1 * V_360 , T_6 V_430 )
{
struct V_429 * V_349 ;
struct V_146 * V_147 ;
V_147 = F_74 ( V_145 , 0 , 0 , V_431 , sizeof( * V_349 ) , 0 ) ;
if ( V_147 == NULL )
return - V_170 ;
V_349 = F_45 ( V_147 ) ;
memcpy ( & V_349 -> V_32 . V_162 , & V_57 -> V_32 . V_162 , sizeof( V_349 -> V_32 . V_162 ) ) ;
V_349 -> V_32 . V_48 = V_57 -> V_32 . V_48 ;
V_349 -> V_32 . V_38 = V_57 -> V_63 . V_38 ;
V_349 -> V_32 . V_33 = V_57 -> V_32 . V_33 ;
memcpy ( & V_349 -> V_360 , V_360 , sizeof( V_349 -> V_360 ) ) ;
memcpy ( & V_349 -> V_358 , & V_57 -> V_63 . V_96 , sizeof( V_349 -> V_358 ) ) ;
V_349 -> V_430 = V_430 ;
V_349 -> V_432 = V_57 -> V_128 -> V_433 ;
V_349 -> V_95 = V_57 -> V_63 . V_95 ;
F_77 ( V_145 , V_147 ) ;
return 0 ;
}
static int F_222 ( struct V_56 * V_57 , T_1 * V_434 ,
T_6 V_435 )
{
struct V_118 * V_118 = F_198 ( V_57 ) ;
struct V_144 * V_145 ;
if ( V_57 -> V_32 . V_33 != V_34 )
return - V_7 ;
if ( ! V_57 -> V_128 )
return - V_7 ;
V_145 = F_86 ( F_220 () , V_208 ) ;
if ( V_145 == NULL )
return - V_68 ;
if ( F_221 ( V_145 , V_57 , V_434 , V_435 ) < 0 )
F_104 () ;
return F_89 ( V_118 , V_145 , 0 , V_436 ) ;
}
static bool F_223 ( const struct V_149 * V_150 )
{
return ( bool ) F_224 ( V_150 -> V_118 ) ;
}
static int T_7 F_225 ( struct V_118 * V_118 )
{
struct V_198 * V_211 ;
struct V_437 V_438 = {
. V_439 = V_440 ,
. V_441 = F_189 ,
} ;
V_211 = F_226 ( V_118 , V_442 , & V_438 ) ;
if ( V_211 == NULL )
return - V_68 ;
V_118 -> V_137 . V_443 = V_211 ;
F_227 ( V_118 -> V_137 . V_211 , V_211 ) ;
return 0 ;
}
static void T_8 F_228 ( struct V_444 * V_445 )
{
struct V_118 * V_118 ;
F_229 (net, net_exit_list, exit_list)
F_230 ( V_118 -> V_137 . V_211 , NULL ) ;
F_231 () ;
F_229 (net, net_exit_list, exit_list)
F_232 ( V_118 -> V_137 . V_443 ) ;
}
static int T_9 F_233 ( void )
{
int V_446 ;
F_204 ( V_447 L_3 ) ;
V_446 = F_234 ( & V_448 ) ;
if ( V_446 < 0 )
return V_446 ;
V_446 = F_235 ( & V_449 ) ;
if ( V_446 < 0 )
F_236 ( & V_448 ) ;
return V_446 ;
}
static void T_10 F_237 ( void )
{
F_238 ( & V_449 ) ;
F_236 ( & V_448 ) ;
}
