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
V_37 = F_38 ( V_57 , false ) ;
if ( V_37 )
goto error;
if ( V_2 [ V_17 ] ) {
V_37 = F_39 ( V_57 ,
F_2 ( V_2 [ V_17 ] ) ) ;
if ( V_37 )
goto error;
}
if ( V_2 [ V_132 ] ) {
V_37 = F_40 ( V_118 , V_57 ,
F_2 ( V_2 [ V_132 ] ) ) ;
if ( V_37 )
goto error;
}
if ( ( V_37 = F_26 ( & V_57 -> V_83 , & V_57 -> V_88 ,
V_2 [ V_24 ] ) ) )
goto error;
V_57 -> V_133 . V_134 = V_23 -> V_134 ;
V_57 -> V_117 = V_118 -> V_135 . V_136 ;
V_57 -> V_116 = ( V_118 -> V_135 . V_137 * V_138 ) / V_139 ;
if ( ( V_37 = F_41 ( V_57 ) ) )
goto error;
F_32 ( V_57 , V_2 , 0 ) ;
return V_57 ;
error:
V_57 -> V_133 . V_140 = V_141 ;
F_42 ( V_57 ) ;
V_120:
* V_119 = V_37 ;
return NULL ;
}
static int F_43 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_22 * V_23 = F_45 ( V_145 ) ;
struct V_56 * V_57 ;
int V_37 ;
struct V_147 V_148 ;
V_37 = F_13 ( V_23 , V_2 ) ;
if ( V_37 )
return V_37 ;
V_57 = F_34 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( ! V_57 )
return V_37 ;
F_46 ( V_57 ) ;
if ( V_145 -> V_149 == V_150 )
V_37 = F_47 ( V_57 ) ;
else
V_37 = F_48 ( V_57 ) ;
F_49 ( V_57 , V_37 ? 0 : 1 , true ) ;
if ( V_37 < 0 ) {
V_57 -> V_133 . V_140 = V_141 ;
F_50 ( V_57 ) ;
goto V_43;
}
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_154 = V_145 -> V_149 ;
F_51 ( V_57 , & V_148 ) ;
V_43:
F_42 ( V_57 ) ;
return V_37 ;
}
static struct V_56 * F_52 ( struct V_118 * V_118 ,
struct V_155 * V_23 ,
struct V_1 * * V_2 ,
int * V_119 )
{
struct V_56 * V_57 = NULL ;
struct V_156 V_157 ;
int V_37 ;
T_3 V_131 = F_37 ( V_2 , & V_157 ) ;
if ( F_53 ( V_23 -> V_33 , V_158 ) ) {
V_37 = - V_159 ;
V_57 = F_54 ( V_118 , V_131 , & V_23 -> V_160 , V_23 -> V_48 , V_23 -> V_33 , V_23 -> V_38 ) ;
} else {
T_1 * V_96 = NULL ;
F_9 ( V_2 , V_161 , & V_96 ) ;
if ( ! V_96 ) {
V_37 = - V_7 ;
goto V_43;
}
V_37 = - V_159 ;
V_57 = F_55 ( V_118 , V_131 ,
& V_23 -> V_160 , V_96 ,
V_23 -> V_33 , V_23 -> V_38 ) ;
}
V_43:
if ( ! V_57 && V_119 )
* V_119 = V_37 ;
return V_57 ;
}
static int F_56 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_56 * V_57 ;
int V_37 = - V_159 ;
struct V_147 V_148 ;
struct V_155 * V_23 = F_45 ( V_145 ) ;
V_57 = F_52 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( V_57 == NULL )
return V_37 ;
if ( ( V_37 = F_57 ( V_57 ) ) != 0 )
goto V_43;
if ( F_58 ( V_57 ) ) {
V_37 = - V_162 ;
goto V_43;
}
V_37 = F_59 ( V_57 ) ;
if ( V_37 < 0 )
goto V_43;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_154 = V_145 -> V_149 ;
F_51 ( V_57 , & V_148 ) ;
V_43:
F_60 ( V_57 , V_37 ? 0 : 1 , true ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static void F_61 ( struct V_56 * V_57 , struct V_22 * V_23 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
memcpy ( & V_23 -> V_32 , & V_57 -> V_32 , sizeof( V_23 -> V_32 ) ) ;
memcpy ( & V_23 -> V_93 , & V_57 -> V_93 , sizeof( V_23 -> V_93 ) ) ;
memcpy ( & V_23 -> V_94 , & V_57 -> V_94 , sizeof( V_23 -> V_94 ) ) ;
memcpy ( & V_23 -> V_111 , & V_57 -> V_111 , sizeof( V_23 -> V_111 ) ) ;
F_62 ( V_57 -> V_163 . V_36 , & V_23 -> V_163 . V_36 ) ;
F_62 ( V_57 -> V_163 . V_107 , & V_23 -> V_163 . V_107 ) ;
F_62 ( V_57 -> V_163 . V_164 , & V_23 -> V_163 . V_164 ) ;
memcpy ( & V_23 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_23 -> V_96 ) ) ;
V_23 -> V_45 = V_57 -> V_63 . V_45 ;
V_23 -> V_36 = V_57 -> V_63 . V_36 ;
V_23 -> V_95 = V_57 -> V_63 . V_95 ;
V_23 -> V_38 = V_57 -> V_63 . V_38 ;
V_23 -> V_27 = V_57 -> V_63 . V_27 ;
V_23 -> V_134 = V_57 -> V_133 . V_134 ;
}
static int F_63 ( struct V_91 * V_165 , struct V_142 * V_143 )
{
struct V_18 * V_19 ;
struct V_1 * V_166 ;
int V_167 = sizeof( * V_19 ) + V_165 -> V_21 ;
V_166 = F_64 ( V_143 , V_17 , V_167 ) ;
if ( V_166 == NULL )
return - V_168 ;
V_19 = F_2 ( V_166 ) ;
V_19 -> V_169 = V_17 ;
V_19 -> V_20 = V_167 ;
V_19 -> V_170 = V_165 -> V_170 ;
V_19 -> V_171 = V_165 -> V_171 ;
V_19 -> V_21 = V_165 -> V_21 ;
memcpy ( V_19 + 1 , V_165 -> V_172 , V_165 -> V_21 ) ;
return 0 ;
}
static int F_65 ( struct V_173 * V_174 , struct V_142 * V_143 )
{
struct V_175 * V_176 ;
struct V_1 * V_166 ;
V_166 = F_64 ( V_143 , V_132 , sizeof( * V_176 ) ) ;
if ( V_166 == NULL )
return - V_168 ;
V_176 = F_2 ( V_166 ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_177 = V_174 -> V_178 -> V_177 ;
V_176 -> V_27 = V_174 -> V_27 ;
return 0 ;
}
static int F_66 ( struct V_13 * V_77 , struct V_142 * V_143 )
{
struct V_5 * V_61 ;
struct V_1 * V_179 ;
V_179 = F_64 ( V_143 , V_8 ,
sizeof( * V_61 ) + ( V_77 -> V_75 + 7 ) / 8 ) ;
if ( ! V_179 )
return - V_168 ;
V_61 = F_2 ( V_179 ) ;
strncpy ( V_61 -> V_11 , V_77 -> V_11 , sizeof( V_61 -> V_11 ) ) ;
memcpy ( V_61 -> V_79 , V_77 -> V_79 , ( V_77 -> V_75 + 7 ) / 8 ) ;
V_61 -> V_75 = V_77 -> V_75 ;
return 0 ;
}
static int F_67 ( struct V_56 * V_57 ,
struct V_22 * V_23 ,
struct V_142 * V_143 )
{
int V_180 = 0 ;
F_61 ( V_57 , V_23 ) ;
if ( V_57 -> V_63 . V_122 ) {
V_180 = F_68 ( V_143 , V_121 ,
V_57 -> V_63 . V_122 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_130 ) {
V_180 = F_69 ( V_143 , V_52 , sizeof( * V_57 -> V_130 ) , V_57 -> V_130 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_181 ) {
V_180 = F_70 ( V_143 , V_182 , V_57 -> V_181 ,
V_183 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_82 ) {
V_180 = F_69 ( V_143 , V_14 , F_8 ( V_57 -> V_82 ) , V_57 -> V_82 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_123 ) {
V_180 = F_66 ( V_57 -> V_123 , V_143 ) ;
if ( ! V_180 )
V_180 = F_69 ( V_143 , V_12 ,
F_6 ( V_57 -> V_123 ) , V_57 -> V_123 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_70 ) {
V_180 = F_69 ( V_143 , V_9 , F_4 ( V_57 -> V_70 ) , V_57 -> V_70 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_125 ) {
V_180 = F_69 ( V_143 , V_10 , sizeof( * ( V_57 -> V_125 ) ) , V_57 -> V_125 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_128 ) {
V_180 = F_69 ( V_143 , V_51 , sizeof( * V_57 -> V_128 ) , V_57 -> V_128 ) ;
if ( V_180 )
goto V_43;
}
if ( V_57 -> V_129 ) {
V_180 = F_68 ( V_143 , V_44 , V_57 -> V_129 ) ;
if ( V_180 )
goto V_43;
}
V_180 = F_71 ( V_143 , & V_57 -> V_131 ) ;
if ( V_180 )
goto V_43;
if ( V_57 -> V_83 )
V_180 = F_69 ( V_143 , V_24 ,
F_12 ( V_57 -> V_83 ) ,
V_57 -> V_83 ) ;
else
V_180 = F_69 ( V_143 , V_99 , sizeof( V_57 -> V_107 ) ,
& V_57 -> V_107 ) ;
if ( V_180 )
goto V_43;
if( V_57 -> V_174 . V_178 )
V_180 = F_65 ( & V_57 -> V_174 , V_143 ) ;
if ( V_180 )
goto V_43;
if ( V_57 -> V_184 )
V_180 = F_63 ( V_57 -> V_184 , V_143 ) ;
V_43:
return V_180 ;
}
static int F_72 ( struct V_56 * V_57 , int V_185 , void * V_186 )
{
struct V_187 * V_188 = V_186 ;
struct V_142 * V_189 = V_188 -> V_189 ;
struct V_142 * V_143 = V_188 -> V_190 ;
struct V_22 * V_23 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , F_74 ( V_189 ) . V_152 , V_188 -> V_151 ,
V_150 , sizeof( * V_23 ) , V_188 -> V_191 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_23 = F_45 ( V_145 ) ;
V_37 = F_67 ( V_57 , V_23 , V_143 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_77 ( struct V_192 * V_193 )
{
struct V_194 * V_195 = (struct V_194 * ) & V_193 -> args [ 1 ] ;
struct V_196 * V_146 = V_193 -> V_143 -> V_146 ;
struct V_118 * V_118 = F_44 ( V_146 ) ;
if ( V_193 -> args [ 0 ] )
F_78 ( V_195 , V_118 ) ;
return 0 ;
}
static int F_79 ( struct V_142 * V_143 , struct V_192 * V_193 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_194 * V_195 = (struct V_194 * ) & V_193 -> args [ 1 ] ;
struct V_187 V_197 ;
F_80 ( sizeof( struct V_194 ) >
sizeof( V_193 -> args ) - sizeof( V_193 -> args [ 0 ] ) ) ;
V_197 . V_189 = V_193 -> V_143 ;
V_197 . V_190 = V_143 ;
V_197 . V_151 = V_193 -> V_145 -> V_151 ;
V_197 . V_191 = V_198 ;
if ( ! V_193 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_199 + 1 ] ;
struct V_200 * V_201 = NULL ;
T_2 V_33 = 0 ;
int V_37 ;
V_37 = F_81 ( V_193 -> V_145 , 0 , V_2 , V_199 , V_202 ,
NULL ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 [ V_203 ] ) {
V_201 = F_18 ( F_2 ( V_2 [ V_203 ] ) ,
sizeof( * V_201 ) , V_67 ) ;
if ( V_201 == NULL )
return - V_68 ;
}
if ( V_2 [ V_204 ] )
V_33 = F_82 ( V_2 [ V_204 ] ) ;
F_83 ( V_195 , V_33 , V_201 ) ;
V_193 -> args [ 0 ] = 1 ;
}
( void ) V_194 ( V_118 , V_195 , F_72 , & V_197 ) ;
return V_143 -> V_20 ;
}
static struct V_142 * F_84 ( struct V_142 * V_189 ,
struct V_56 * V_57 , T_3 V_134 )
{
struct V_187 V_197 ;
struct V_142 * V_143 ;
int V_37 ;
V_143 = F_85 ( V_205 , V_206 ) ;
if ( ! V_143 )
return F_86 ( - V_68 ) ;
V_197 . V_189 = V_189 ;
V_197 . V_190 = V_143 ;
V_197 . V_151 = V_134 ;
V_197 . V_191 = 0 ;
V_37 = F_72 ( V_57 , 0 , & V_197 ) ;
if ( V_37 ) {
F_87 ( V_143 ) ;
return F_86 ( V_37 ) ;
}
return V_143 ;
}
static inline int F_88 ( struct V_118 * V_118 , struct V_142 * V_143 ,
T_3 V_207 , unsigned int V_208 )
{
struct V_196 * V_209 = F_89 ( V_118 -> V_135 . V_209 ) ;
if ( V_209 )
return F_90 ( V_209 , V_143 , V_207 , V_208 , V_206 ) ;
else
return - 1 ;
}
static inline T_4 F_91 ( void )
{
return F_92 ( 4 )
+ F_93 ( sizeof( struct V_210 ) )
+ F_93 ( sizeof( struct V_211 ) )
+ F_93 ( sizeof( struct V_212 ) )
+ F_93 ( sizeof( struct V_212 ) ) ;
}
static int F_94 ( struct V_142 * V_143 , struct V_118 * V_118 ,
T_3 V_152 , T_3 V_134 , T_3 V_27 )
{
struct V_213 V_214 ;
struct V_210 V_215 ;
struct V_211 V_216 ;
struct V_212 V_217 , V_218 ;
struct V_144 * V_145 ;
int V_37 ;
T_3 * V_219 ;
unsigned V_220 ;
V_145 = F_73 ( V_143 , V_152 , V_134 , V_221 , sizeof( T_3 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_219 = F_45 ( V_145 ) ;
* V_219 = V_27 ;
F_95 ( V_118 , & V_214 ) ;
V_215 . V_222 = V_214 . V_222 ;
V_215 . V_223 = V_214 . V_223 ;
V_215 . V_224 = V_214 . V_224 ;
V_215 . V_225 = V_214 . V_225 ;
V_215 . V_226 = V_214 . V_226 ;
V_215 . V_227 = V_214 . V_227 ;
V_216 . V_228 = V_214 . V_228 ;
V_216 . V_229 = V_214 . V_229 ;
do {
V_220 = F_96 ( & V_118 -> V_135 . V_230 . V_231 ) ;
V_217 . V_232 = V_118 -> V_135 . V_230 . V_233 ;
V_217 . V_234 = V_118 -> V_135 . V_230 . V_235 ;
V_218 . V_232 = V_118 -> V_135 . V_230 . V_236 ;
V_218 . V_234 = V_118 -> V_135 . V_230 . V_237 ;
} while ( F_97 ( & V_118 -> V_135 . V_230 . V_231 , V_220 ) );
V_37 = F_69 ( V_143 , V_238 , sizeof( V_215 ) , & V_215 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_143 , V_239 , sizeof( V_216 ) , & V_216 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_143 , V_240 , sizeof( V_217 ) , & V_217 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_143 , V_241 , sizeof( V_218 ) , & V_218 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_98 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_212 * V_242 = NULL ;
struct V_212 * V_243 = NULL ;
if ( V_2 [ V_240 ] ) {
struct V_1 * V_58 = V_2 [ V_240 ] ;
if ( F_3 ( V_58 ) < sizeof( * V_242 ) )
return - V_7 ;
V_242 = F_2 ( V_58 ) ;
if ( V_242 -> V_232 > 32 || V_242 -> V_234 > 32 )
return - V_7 ;
}
if ( V_2 [ V_241 ] ) {
struct V_1 * V_58 = V_2 [ V_241 ] ;
if ( F_3 ( V_58 ) < sizeof( * V_243 ) )
return - V_7 ;
V_243 = F_2 ( V_58 ) ;
if ( V_243 -> V_232 > 128 || V_243 -> V_234 > 128 )
return - V_7 ;
}
if ( V_242 || V_243 ) {
F_99 ( & V_118 -> V_135 . V_230 . V_231 ) ;
if ( V_242 ) {
V_118 -> V_135 . V_230 . V_233 = V_242 -> V_232 ;
V_118 -> V_135 . V_230 . V_235 = V_242 -> V_234 ;
}
if ( V_243 ) {
V_118 -> V_135 . V_230 . V_236 = V_243 -> V_232 ;
V_118 -> V_135 . V_230 . V_237 = V_243 -> V_234 ;
}
F_100 ( & V_118 -> V_135 . V_230 . V_231 ) ;
F_101 ( V_118 ) ;
}
return 0 ;
}
static int F_102 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_142 * V_244 ;
T_3 * V_27 = F_45 ( V_145 ) ;
T_3 V_245 = F_74 ( V_143 ) . V_152 ;
T_3 V_134 = V_145 -> V_151 ;
V_244 = F_85 ( F_91 () , V_206 ) ;
if ( V_244 == NULL )
return - V_68 ;
if ( F_94 ( V_244 , V_118 , V_245 , V_134 , * V_27 ) < 0 )
F_103 () ;
return F_104 ( V_118 -> V_135 . V_209 , V_244 , V_245 ) ;
}
static inline T_4 F_105 ( void )
{
return F_92 ( 4 )
+ F_93 ( sizeof( struct V_246 ) )
+ F_93 ( 4 ) ;
}
static int F_106 ( struct V_142 * V_143 , struct V_118 * V_118 ,
T_3 V_152 , T_3 V_134 , T_3 V_27 )
{
struct V_247 V_214 ;
struct V_246 V_248 ;
struct V_144 * V_145 ;
int V_37 ;
T_3 * V_219 ;
V_145 = F_73 ( V_143 , V_152 , V_134 , V_249 , sizeof( T_3 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_219 = F_45 ( V_145 ) ;
* V_219 = V_27 ;
F_107 ( V_118 , & V_214 ) ;
V_248 . V_250 = V_214 . V_250 ;
V_248 . V_251 = V_214 . V_251 ;
V_37 = F_68 ( V_143 , V_252 , V_214 . V_253 ) ;
if ( ! V_37 )
V_37 = F_69 ( V_143 , V_254 , sizeof( V_248 ) , & V_248 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_108 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_142 * V_244 ;
T_3 * V_27 = F_45 ( V_145 ) ;
T_3 V_245 = F_74 ( V_143 ) . V_152 ;
T_3 V_134 = V_145 -> V_151 ;
V_244 = F_85 ( F_105 () , V_206 ) ;
if ( V_244 == NULL )
return - V_68 ;
if ( F_106 ( V_244 , V_118 , V_245 , V_134 , * V_27 ) < 0 )
F_103 () ;
return F_104 ( V_118 -> V_135 . V_209 , V_244 , V_245 ) ;
}
static int F_109 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_155 * V_23 = F_45 ( V_145 ) ;
struct V_56 * V_57 ;
struct V_142 * V_255 ;
int V_37 = - V_159 ;
V_57 = F_52 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( V_57 == NULL )
goto V_256;
V_255 = F_84 ( V_143 , V_57 , V_145 -> V_151 ) ;
if ( F_110 ( V_255 ) ) {
V_37 = F_111 ( V_255 ) ;
} else {
V_37 = F_104 ( V_118 -> V_135 . V_209 , V_255 , F_74 ( V_143 ) . V_152 ) ;
}
F_42 ( V_57 ) ;
V_256:
return V_37 ;
}
static int F_112 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_56 * V_57 ;
struct V_257 * V_23 ;
struct V_142 * V_255 ;
T_1 * V_160 ;
int V_38 ;
int V_37 ;
T_3 V_131 ;
struct V_156 V_157 ;
V_23 = F_45 ( V_145 ) ;
V_37 = F_113 ( V_23 -> V_197 . V_32 . V_33 , V_23 -> V_258 , V_23 -> V_259 ) ;
if ( V_37 )
goto V_256;
V_38 = V_23 -> V_197 . V_38 ;
V_160 = & V_23 -> V_197 . V_32 . V_160 ;
V_57 = NULL ;
V_131 = F_37 ( V_2 , & V_157 ) ;
if ( V_23 -> V_197 . V_134 ) {
V_57 = F_114 ( V_118 , V_131 , V_23 -> V_197 . V_134 ) ;
if ( V_57 && ! F_115 ( & V_57 -> V_32 . V_160 , V_160 , V_38 ) ) {
F_42 ( V_57 ) ;
V_57 = NULL ;
}
}
if ( ! V_57 )
V_57 = F_116 ( V_118 , & V_157 , V_23 -> V_197 . V_45 , V_23 -> V_197 . V_95 ,
V_23 -> V_197 . V_32 . V_33 , V_160 ,
& V_23 -> V_197 . V_96 , 1 ,
V_38 ) ;
V_37 = - V_260 ;
if ( V_57 == NULL )
goto V_256;
V_37 = F_117 ( V_57 , V_23 -> V_258 , V_23 -> V_259 ) ;
if ( V_37 )
goto V_43;
V_255 = F_84 ( V_143 , V_57 , V_145 -> V_151 ) ;
if ( F_110 ( V_255 ) ) {
V_37 = F_111 ( V_255 ) ;
goto V_43;
}
V_37 = F_104 ( V_118 -> V_135 . V_209 , V_255 , F_74 ( V_143 ) . V_152 ) ;
V_43:
F_42 ( V_57 ) ;
V_256:
return V_37 ;
}
static int F_118 ( T_2 V_261 )
{
switch ( V_261 ) {
case V_262 :
case V_263 :
case V_264 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_119 ( T_2 type )
{
switch ( type ) {
case V_265 :
#ifdef F_120
case V_266 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_121 ( struct V_267 * V_23 )
{
int V_180 ;
switch ( V_23 -> V_268 ) {
case V_269 :
case V_270 :
case V_271 :
case V_272 :
break;
default:
return - V_7 ;
}
switch ( V_23 -> V_273 ) {
case V_274 :
case V_275 :
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
V_180 = F_118 ( V_23 -> V_261 ) ;
if ( V_180 )
return V_180 ;
if ( V_23 -> V_276 && ( ( V_23 -> V_276 & V_277 ) != V_23 -> V_261 ) )
return - V_7 ;
return 0 ;
}
static int F_122 ( struct V_278 * V_279 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_18 * V_19 ;
if ( ! V_4 )
return 0 ;
V_19 = F_2 ( V_4 ) ;
return F_123 ( & V_279 -> V_184 , V_19 , V_67 ) ;
}
static void F_124 ( struct V_278 * V_280 , struct V_281 * V_282 ,
int V_283 )
{
int V_284 ;
V_280 -> V_285 = V_283 ;
for ( V_284 = 0 ; V_284 < V_283 ; V_284 ++ , V_282 ++ ) {
struct V_286 * V_287 = & V_280 -> V_288 [ V_284 ] ;
memcpy ( & V_287 -> V_32 , & V_282 -> V_32 , sizeof( struct V_289 ) ) ;
memcpy ( & V_287 -> V_96 , & V_282 -> V_96 ,
sizeof( T_1 ) ) ;
V_287 -> V_95 = V_282 -> V_95 ;
V_287 -> V_45 = V_282 -> V_45 ;
V_287 -> V_268 = V_282 -> V_268 ;
V_287 -> V_290 = V_282 -> V_290 ;
V_287 -> V_291 = V_282 -> V_291 ;
V_287 -> V_292 = V_282 -> V_292 ;
V_287 -> V_293 = V_282 -> V_293 ;
V_287 -> V_294 = ! ~ ( V_287 -> V_291 & V_287 -> V_292 & V_287 -> V_293 ) ;
V_287 -> V_295 = V_282 -> V_38 ;
}
}
static int F_125 ( int V_283 , struct V_281 * V_282 , T_5 V_38 )
{
int V_284 ;
if ( V_283 > V_296 )
return - V_7 ;
for ( V_284 = 0 ; V_284 < V_283 ; V_284 ++ ) {
if ( ! V_282 [ V_284 ] . V_38 )
V_282 [ V_284 ] . V_38 = V_38 ;
switch ( V_282 [ V_284 ] . V_38 ) {
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
static int F_126 ( struct V_278 * V_279 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_297 ] ;
if ( ! V_4 ) {
V_279 -> V_285 = 0 ;
} else {
struct V_281 * V_298 = F_2 ( V_4 ) ;
int V_283 = F_3 ( V_4 ) / sizeof( * V_298 ) ;
int V_37 ;
V_37 = F_125 ( V_283 , V_298 , V_279 -> V_38 ) ;
if ( V_37 )
return V_37 ;
F_124 ( V_279 , V_298 , V_283 ) ;
}
return 0 ;
}
static int F_127 ( T_2 * V_299 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_300 ] ;
struct V_301 * V_302 ;
T_2 type = V_265 ;
int V_37 ;
if ( V_4 ) {
V_302 = F_2 ( V_4 ) ;
type = V_302 -> type ;
}
V_37 = F_119 ( type ) ;
if ( V_37 )
return V_37 ;
* V_299 = type ;
return 0 ;
}
static void F_128 ( struct V_278 * V_280 , struct V_267 * V_23 )
{
V_280 -> V_303 = V_23 -> V_303 ;
V_280 -> V_276 = V_23 -> V_276 ;
memcpy ( & V_280 -> V_304 , & V_23 -> V_93 , sizeof( V_280 -> V_304 ) ) ;
memcpy ( & V_280 -> V_94 , & V_23 -> V_94 , sizeof( V_280 -> V_94 ) ) ;
V_280 -> V_273 = V_23 -> V_273 ;
V_280 -> V_27 = V_23 -> V_27 ;
V_280 -> V_38 = V_23 -> V_93 . V_38 ;
}
static void F_129 ( struct V_278 * V_280 , struct V_267 * V_23 , int V_261 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
memcpy ( & V_23 -> V_93 , & V_280 -> V_304 , sizeof( V_23 -> V_93 ) ) ;
memcpy ( & V_23 -> V_94 , & V_280 -> V_94 , sizeof( V_23 -> V_94 ) ) ;
memcpy ( & V_23 -> V_111 , & V_280 -> V_111 , sizeof( V_23 -> V_111 ) ) ;
V_23 -> V_303 = V_280 -> V_303 ;
V_23 -> V_276 = V_280 -> V_276 ;
V_23 -> V_93 . V_38 = V_280 -> V_38 ;
V_23 -> V_261 = V_261 ;
V_23 -> V_273 = V_280 -> V_273 ;
V_23 -> V_27 = V_280 -> V_27 ;
V_23 -> V_268 = V_269 ;
}
static struct V_278 * F_130 ( struct V_118 * V_118 , struct V_267 * V_23 , struct V_1 * * V_2 , int * V_119 )
{
struct V_278 * V_280 = F_131 ( V_118 , V_67 ) ;
int V_37 ;
if ( ! V_280 ) {
* V_119 = - V_68 ;
return NULL ;
}
F_128 ( V_280 , V_23 ) ;
V_37 = F_127 ( & V_280 -> type , V_2 ) ;
if ( V_37 )
goto error;
if ( ! ( V_37 = F_126 ( V_280 , V_2 ) ) )
V_37 = F_122 ( V_280 , V_2 ) ;
if ( V_37 )
goto error;
F_37 ( V_2 , & V_280 -> V_131 ) ;
return V_280 ;
error:
* V_119 = V_37 ;
V_280 -> V_195 . V_305 = 1 ;
F_132 ( V_280 ) ;
return NULL ;
}
static int F_133 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_267 * V_23 = F_45 ( V_145 ) ;
struct V_278 * V_280 ;
struct V_147 V_148 ;
int V_37 ;
int V_306 ;
V_37 = F_121 ( V_23 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_280 = F_130 ( V_118 , V_23 , V_2 , & V_37 ) ;
if ( ! V_280 )
return V_37 ;
V_306 = V_145 -> V_149 == V_307 ;
V_37 = F_134 ( V_23 -> V_261 , V_280 , V_306 ) ;
F_135 ( V_280 , V_37 ? 0 : 1 , true ) ;
if ( V_37 ) {
F_136 ( V_280 -> V_184 ) ;
F_28 ( V_280 ) ;
return V_37 ;
}
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
F_137 ( V_280 , V_23 -> V_261 , & V_148 ) ;
F_138 ( V_280 ) ;
return 0 ;
}
static int F_139 ( struct V_278 * V_280 , struct V_142 * V_143 )
{
struct V_281 V_308 [ V_296 ] ;
int V_284 ;
if ( V_280 -> V_285 == 0 )
return 0 ;
for ( V_284 = 0 ; V_284 < V_280 -> V_285 ; V_284 ++ ) {
struct V_281 * V_85 = & V_308 [ V_284 ] ;
struct V_286 * V_309 = & V_280 -> V_288 [ V_284 ] ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
memcpy ( & V_85 -> V_32 , & V_309 -> V_32 , sizeof( V_85 -> V_32 ) ) ;
V_85 -> V_38 = V_309 -> V_295 ;
memcpy ( & V_85 -> V_96 , & V_309 -> V_96 , sizeof( V_85 -> V_96 ) ) ;
V_85 -> V_95 = V_309 -> V_95 ;
V_85 -> V_45 = V_309 -> V_45 ;
V_85 -> V_268 = V_309 -> V_268 ;
V_85 -> V_290 = V_309 -> V_290 ;
V_85 -> V_291 = V_309 -> V_291 ;
V_85 -> V_292 = V_309 -> V_292 ;
V_85 -> V_293 = V_309 -> V_293 ;
}
return F_69 ( V_143 , V_297 ,
sizeof( struct V_281 ) * V_280 -> V_285 , V_308 ) ;
}
static inline int F_140 ( struct V_56 * V_57 , struct V_142 * V_143 )
{
if ( V_57 -> V_184 ) {
return F_63 ( V_57 -> V_184 , V_143 ) ;
}
return 0 ;
}
static inline int F_141 ( struct V_278 * V_280 , struct V_142 * V_143 )
{
if ( V_280 -> V_184 )
return F_63 ( V_280 -> V_184 , V_143 ) ;
return 0 ;
}
static inline T_4 F_142 ( void )
{
#ifdef F_120
return F_93 ( sizeof( struct V_301 ) ) ;
#else
return 0 ;
#endif
}
static int F_143 ( T_2 type , struct V_142 * V_143 )
{
struct V_301 V_302 = {
. type = type ,
} ;
return F_69 ( V_143 , V_300 , sizeof( V_302 ) , & V_302 ) ;
}
static inline int F_143 ( T_2 type , struct V_142 * V_143 )
{
return 0 ;
}
static int F_144 ( struct V_278 * V_280 , int V_261 , int V_185 , void * V_186 )
{
struct V_187 * V_188 = V_186 ;
struct V_267 * V_23 ;
struct V_142 * V_189 = V_188 -> V_189 ;
struct V_142 * V_143 = V_188 -> V_190 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , F_74 ( V_189 ) . V_152 , V_188 -> V_151 ,
V_307 , sizeof( * V_23 ) , V_188 -> V_191 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_23 = F_45 ( V_145 ) ;
F_129 ( V_280 , V_23 , V_261 ) ;
V_37 = F_139 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_141 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_143 ( V_280 -> type , V_143 ) ;
if ( ! V_37 )
V_37 = F_71 ( V_143 , & V_280 -> V_131 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_145 ( struct V_192 * V_193 )
{
struct V_310 * V_195 = (struct V_310 * ) & V_193 -> args [ 1 ] ;
struct V_118 * V_118 = F_44 ( V_193 -> V_143 -> V_146 ) ;
F_146 ( V_195 , V_118 ) ;
return 0 ;
}
static int F_147 ( struct V_142 * V_143 , struct V_192 * V_193 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_310 * V_195 = (struct V_310 * ) & V_193 -> args [ 1 ] ;
struct V_187 V_197 ;
F_80 ( sizeof( struct V_310 ) >
sizeof( V_193 -> args ) - sizeof( V_193 -> args [ 0 ] ) ) ;
V_197 . V_189 = V_193 -> V_143 ;
V_197 . V_190 = V_143 ;
V_197 . V_151 = V_193 -> V_145 -> V_151 ;
V_197 . V_191 = V_198 ;
if ( ! V_193 -> args [ 0 ] ) {
V_193 -> args [ 0 ] = 1 ;
F_148 ( V_195 , V_311 ) ;
}
( void ) V_310 ( V_118 , V_195 , F_144 , & V_197 ) ;
return V_143 -> V_20 ;
}
static struct V_142 * F_149 ( struct V_142 * V_189 ,
struct V_278 * V_280 ,
int V_261 , T_3 V_134 )
{
struct V_187 V_197 ;
struct V_142 * V_143 ;
int V_37 ;
V_143 = F_85 ( V_205 , V_67 ) ;
if ( ! V_143 )
return F_86 ( - V_68 ) ;
V_197 . V_189 = V_189 ;
V_197 . V_190 = V_143 ;
V_197 . V_151 = V_134 ;
V_197 . V_191 = 0 ;
V_37 = F_144 ( V_280 , V_261 , 0 , & V_197 ) ;
if ( V_37 ) {
F_87 ( V_143 ) ;
return F_86 ( V_37 ) ;
}
return V_143 ;
}
static int F_150 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_278 * V_280 ;
struct V_312 * V_23 ;
T_2 type = V_265 ;
int V_37 ;
struct V_147 V_148 ;
int V_313 ;
struct V_156 V_157 ;
T_3 V_131 = F_37 ( V_2 , & V_157 ) ;
V_23 = F_45 ( V_145 ) ;
V_313 = V_145 -> V_149 == V_314 ;
V_37 = F_127 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_118 ( V_23 -> V_261 ) ;
if ( V_37 )
return V_37 ;
if ( V_23 -> V_276 )
V_280 = F_151 ( V_118 , V_131 , type , V_23 -> V_261 , V_23 -> V_276 , V_313 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_91 * V_315 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_315 = NULL ;
if ( V_4 ) {
struct V_18 * V_19 = F_2 ( V_4 ) ;
V_37 = F_123 ( & V_315 , V_19 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_280 = F_152 ( V_118 , V_131 , type , V_23 -> V_261 , & V_23 -> V_93 ,
V_315 , V_313 , & V_37 ) ;
F_136 ( V_315 ) ;
}
if ( V_280 == NULL )
return - V_260 ;
if ( ! V_313 ) {
struct V_142 * V_255 ;
V_255 = F_149 ( V_143 , V_280 , V_23 -> V_261 , V_145 -> V_151 ) ;
if ( F_110 ( V_255 ) ) {
V_37 = F_111 ( V_255 ) ;
} else {
V_37 = F_104 ( V_118 -> V_135 . V_209 , V_255 ,
F_74 ( V_143 ) . V_152 ) ;
}
} else {
F_153 ( V_280 , V_37 ? 0 : 1 , true ) ;
if ( V_37 != 0 )
goto V_43;
V_148 . V_316 . V_317 = V_23 -> V_276 ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
F_137 ( V_280 , V_23 -> V_261 , & V_148 ) ;
}
V_43:
F_138 ( V_280 ) ;
if ( V_313 && V_37 == 0 )
F_154 ( V_118 ) ;
return V_37 ;
}
static int F_155 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_147 V_148 ;
struct V_318 * V_23 = F_45 ( V_145 ) ;
int V_37 ;
V_37 = F_156 ( V_118 , V_23 -> V_33 , true ) ;
if ( V_37 ) {
if ( V_37 == - V_159 )
return 0 ;
return V_37 ;
}
V_148 . V_316 . V_33 = V_23 -> V_33 ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_118 = V_118 ;
F_51 ( NULL , & V_148 ) ;
return 0 ;
}
static inline T_4 F_157 ( struct V_56 * V_57 )
{
T_4 V_319 = V_57 -> V_83 ?
F_12 ( V_57 -> V_83 ) :
sizeof( struct V_106 ) ;
return F_92 ( sizeof( struct V_320 ) )
+ F_93 ( V_319 )
+ F_158 ( sizeof( struct V_109 ) )
+ F_93 ( sizeof( struct V_156 ) )
+ F_93 ( 4 )
+ F_93 ( 4 ) ;
}
static int F_159 ( struct V_142 * V_143 , struct V_56 * V_57 , const struct V_147 * V_148 )
{
struct V_320 * V_32 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_321 , sizeof( * V_32 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_32 = F_45 ( V_145 ) ;
memset ( & V_32 -> V_322 , 0 , sizeof( V_32 -> V_322 ) ) ;
memcpy ( & V_32 -> V_322 . V_160 , & V_57 -> V_32 . V_160 , sizeof( V_57 -> V_32 . V_160 ) ) ;
V_32 -> V_322 . V_48 = V_57 -> V_32 . V_48 ;
V_32 -> V_322 . V_38 = V_57 -> V_63 . V_38 ;
V_32 -> V_322 . V_33 = V_57 -> V_32 . V_33 ;
memcpy ( & V_32 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_57 -> V_63 . V_96 ) ) ;
V_32 -> V_95 = V_57 -> V_63 . V_95 ;
V_32 -> V_27 = V_148 -> V_316 . V_323 ;
if ( V_57 -> V_83 ) {
V_37 = F_69 ( V_143 , V_24 ,
F_12 ( V_57 -> V_83 ) ,
V_57 -> V_83 ) ;
} else {
V_37 = F_69 ( V_143 , V_99 , sizeof( V_57 -> V_107 ) ,
& V_57 -> V_107 ) ;
}
if ( V_37 )
goto V_324;
V_37 = F_160 ( V_143 , V_102 , sizeof( V_57 -> V_111 ) , & V_57 -> V_111 ,
V_183 ) ;
if ( V_37 )
goto V_324;
if ( V_32 -> V_27 & V_325 ) {
V_37 = F_68 ( V_143 , V_105 , V_57 -> V_117 ) ;
if ( V_37 )
goto V_324;
}
if ( V_32 -> V_27 & V_326 ) {
V_37 = F_68 ( V_143 , V_104 ,
V_57 -> V_116 * 10 / V_138 ) ;
if ( V_37 )
goto V_324;
}
V_37 = F_71 ( V_143 , & V_57 -> V_131 ) ;
if ( V_37 )
goto V_324;
F_76 ( V_143 , V_145 ) ;
return 0 ;
V_324:
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
static int F_161 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_56 * V_57 ;
struct V_142 * V_244 ;
int V_37 ;
struct V_147 V_148 ;
T_3 V_131 ;
struct V_156 V_157 ;
struct V_320 * V_23 = F_45 ( V_145 ) ;
struct V_155 * V_32 = & V_23 -> V_322 ;
V_131 = F_37 ( V_2 , & V_157 ) ;
V_57 = F_54 ( V_118 , V_131 , & V_32 -> V_160 , V_32 -> V_48 , V_32 -> V_33 , V_32 -> V_38 ) ;
if ( V_57 == NULL )
return - V_159 ;
V_244 = F_85 ( F_157 ( V_57 ) , V_206 ) ;
if ( V_244 == NULL ) {
F_42 ( V_57 ) ;
return - V_68 ;
}
F_162 ( & V_57 -> V_231 ) ;
V_148 . V_316 . V_323 = V_23 -> V_27 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
if ( F_159 ( V_244 , V_57 , & V_148 ) < 0 )
F_103 () ;
V_37 = F_104 ( V_118 -> V_135 . V_209 , V_244 , F_74 ( V_143 ) . V_152 ) ;
F_163 ( & V_57 -> V_231 ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_164 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_56 * V_57 ;
struct V_147 V_148 ;
int V_37 = - V_7 ;
T_3 V_131 = 0 ;
struct V_156 V_157 ;
struct V_320 * V_23 = F_45 ( V_145 ) ;
struct V_1 * V_84 = V_2 [ V_99 ] ;
struct V_1 * V_100 = V_2 [ V_24 ] ;
struct V_1 * V_101 = V_2 [ V_102 ] ;
struct V_1 * V_103 = V_2 [ V_104 ] ;
struct V_1 * V_4 = V_2 [ V_105 ] ;
if ( ! V_101 && ! V_84 && ! V_100 && ! V_103 && ! V_4 )
return V_37 ;
if ( ! ( V_145 -> V_191 & V_327 ) )
return V_37 ;
V_131 = F_37 ( V_2 , & V_157 ) ;
V_57 = F_54 ( V_118 , V_131 , & V_23 -> V_322 . V_160 , V_23 -> V_322 . V_48 , V_23 -> V_322 . V_33 , V_23 -> V_322 . V_38 ) ;
if ( V_57 == NULL )
return - V_159 ;
if ( V_57 -> V_133 . V_140 != V_328 )
goto V_43;
V_37 = F_25 ( V_57 -> V_83 , V_100 ) ;
if ( V_37 )
goto V_43;
F_162 ( & V_57 -> V_231 ) ;
F_32 ( V_57 , V_2 , 1 ) ;
F_163 ( & V_57 -> V_231 ) ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_316 . V_323 = V_329 ;
F_51 ( V_57 , & V_148 ) ;
V_37 = 0 ;
V_43:
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_165 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_147 V_148 ;
T_2 type = V_265 ;
int V_37 ;
V_37 = F_127 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_166 ( V_118 , type , true ) ;
if ( V_37 ) {
if ( V_37 == - V_159 )
return 0 ;
return V_37 ;
}
F_154 ( V_118 ) ;
V_148 . V_316 . type = type ;
V_148 . V_154 = V_145 -> V_149 ;
V_148 . V_134 = V_145 -> V_151 ;
V_148 . V_152 = V_145 -> V_153 ;
V_148 . V_118 = V_118 ;
F_137 ( NULL , 0 , & V_148 ) ;
return 0 ;
}
static int F_167 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_278 * V_280 ;
struct V_330 * V_85 = F_45 ( V_145 ) ;
struct V_267 * V_23 = & V_85 -> V_279 ;
T_2 type = V_265 ;
int V_37 = - V_260 ;
struct V_156 V_157 ;
T_3 V_131 = F_37 ( V_2 , & V_157 ) ;
V_37 = F_127 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_118 ( V_23 -> V_261 ) ;
if ( V_37 )
return V_37 ;
if ( V_23 -> V_276 )
V_280 = F_151 ( V_118 , V_131 , type , V_23 -> V_261 , V_23 -> V_276 , 0 , & V_37 ) ;
else {
struct V_1 * V_4 = V_2 [ V_17 ] ;
struct V_91 * V_315 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_315 = NULL ;
if ( V_4 ) {
struct V_18 * V_19 = F_2 ( V_4 ) ;
V_37 = F_123 ( & V_315 , V_19 , V_67 ) ;
if ( V_37 )
return V_37 ;
}
V_280 = F_152 ( V_118 , V_131 , type , V_23 -> V_261 ,
& V_23 -> V_93 , V_315 , 0 , & V_37 ) ;
F_136 ( V_315 ) ;
}
if ( V_280 == NULL )
return - V_260 ;
if ( F_168 ( V_280 -> V_195 . V_305 ) )
goto V_43;
V_37 = 0 ;
if ( V_85 -> V_331 ) {
F_169 ( V_280 , V_23 -> V_261 ) ;
F_153 ( V_280 , 1 , true ) ;
}
F_170 ( V_280 , V_23 -> V_261 , V_85 -> V_331 , V_145 -> V_153 ) ;
V_43:
F_138 ( V_280 ) ;
return V_37 ;
}
static int F_171 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_56 * V_57 ;
int V_37 ;
struct V_332 * V_333 = F_45 ( V_145 ) ;
struct V_22 * V_23 = & V_333 -> V_140 ;
struct V_156 V_157 ;
T_3 V_131 = F_37 ( V_2 , & V_157 ) ;
V_57 = F_54 ( V_118 , V_131 , & V_23 -> V_32 . V_160 , V_23 -> V_32 . V_48 , V_23 -> V_32 . V_33 , V_23 -> V_38 ) ;
V_37 = - V_260 ;
if ( V_57 == NULL )
return V_37 ;
F_162 ( & V_57 -> V_231 ) ;
V_37 = - V_7 ;
if ( V_57 -> V_133 . V_140 != V_328 )
goto V_43;
F_172 ( V_57 , V_333 -> V_331 , V_145 -> V_153 ) ;
if ( V_333 -> V_331 ) {
F_173 ( V_57 ) ;
F_60 ( V_57 , 1 , true ) ;
}
V_37 = 0 ;
V_43:
F_163 ( & V_57 -> V_231 ) ;
F_42 ( V_57 ) ;
return V_37 ;
}
static int F_174 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_278 * V_280 ;
struct V_281 * V_282 ;
int V_284 ;
struct V_1 * V_4 = V_2 [ V_297 ] ;
struct V_156 V_131 ;
struct V_334 * V_335 = F_45 ( V_145 ) ;
struct V_56 * V_57 = F_35 ( V_118 ) ;
int V_37 = - V_68 ;
if ( ! V_57 )
goto V_336;
F_37 ( V_2 , & V_131 ) ;
V_37 = F_121 ( & V_335 -> V_337 ) ;
if ( V_37 )
goto V_338;
V_280 = F_130 ( V_118 , & V_335 -> V_337 , V_2 , & V_37 ) ;
if ( ! V_280 )
goto V_338;
memcpy ( & V_57 -> V_32 , & V_335 -> V_32 , sizeof( V_335 -> V_32 ) ) ;
memcpy ( & V_57 -> V_63 . V_96 , & V_335 -> V_96 , sizeof( V_335 -> V_96 ) ) ;
memcpy ( & V_57 -> V_93 , & V_335 -> V_93 , sizeof( V_335 -> V_93 ) ) ;
V_280 -> V_131 . V_157 = V_57 -> V_131 . V_157 = V_131 . V_157 ;
V_280 -> V_131 . V_339 = V_57 -> V_131 . V_339 = V_131 . V_339 ;
V_282 = F_2 ( V_4 ) ;
for ( V_284 = 0 ; V_284 < V_280 -> V_285 ; V_284 ++ , V_282 ++ ) {
struct V_286 * V_287 = & V_280 -> V_288 [ V_284 ] ;
memcpy ( & V_57 -> V_32 , & V_287 -> V_32 , sizeof( V_57 -> V_32 ) ) ;
V_57 -> V_63 . V_45 = V_287 -> V_45 ;
V_57 -> V_63 . V_95 = V_287 -> V_95 ;
V_57 -> V_63 . V_38 = V_282 -> V_38 ;
V_287 -> V_291 = V_335 -> V_291 ;
V_287 -> V_292 = V_335 -> V_292 ;
V_287 -> V_293 = V_335 -> V_293 ;
V_37 = F_175 ( V_57 , V_287 , V_280 ) ;
}
F_28 ( V_57 ) ;
F_28 ( V_280 ) ;
return 0 ;
V_338:
F_28 ( V_57 ) ;
V_336:
return V_37 ;
}
static int F_176 ( struct V_340 * V_341 ,
struct V_342 * V_343 ,
struct V_1 * * V_2 , int * V_344 )
{
struct V_1 * V_4 = V_2 [ V_345 ] ;
struct V_346 * V_347 ;
int V_284 , V_348 ;
if ( V_343 != NULL ) {
struct V_349 * V_350 ;
V_350 = F_2 ( V_2 [ V_351 ] ) ;
memcpy ( & V_343 -> V_352 , & V_350 -> V_352 , sizeof( V_343 -> V_352 ) ) ;
memcpy ( & V_343 -> V_353 , & V_350 -> V_353 , sizeof( V_343 -> V_353 ) ) ;
V_343 -> V_38 = V_350 -> V_38 ;
V_343 -> V_354 = V_350 -> V_354 ;
}
V_347 = F_2 ( V_4 ) ;
V_348 = F_3 ( V_4 ) / sizeof( * V_347 ) ;
if ( V_348 <= 0 || V_348 > V_296 )
return - V_7 ;
for ( V_284 = 0 ; V_284 < V_348 ; V_284 ++ , V_347 ++ , V_341 ++ ) {
memcpy ( & V_341 -> V_355 , & V_347 -> V_355 , sizeof( V_341 -> V_355 ) ) ;
memcpy ( & V_341 -> V_356 , & V_347 -> V_356 , sizeof( V_341 -> V_356 ) ) ;
memcpy ( & V_341 -> V_357 , & V_347 -> V_357 , sizeof( V_341 -> V_357 ) ) ;
memcpy ( & V_341 -> V_358 , & V_347 -> V_358 , sizeof( V_341 -> V_358 ) ) ;
V_341 -> V_33 = V_347 -> V_33 ;
V_341 -> V_45 = V_347 -> V_45 ;
V_341 -> V_95 = V_347 -> V_95 ;
V_341 -> V_359 = V_347 -> V_359 ;
V_341 -> V_360 = V_347 -> V_360 ;
}
* V_344 = V_284 ;
return 0 ;
}
static int F_177 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
struct V_312 * V_361 = F_45 ( V_145 ) ;
struct V_340 V_157 [ V_296 ] ;
struct V_342 V_133 , * V_362 ;
T_2 type ;
int V_37 ;
int V_363 = 0 ;
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_364 * V_128 = NULL ;
if ( V_2 [ V_345 ] == NULL )
return - V_7 ;
V_362 = V_2 [ V_351 ] ? & V_133 : NULL ;
V_37 = F_127 ( & type , V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_176 ( (struct V_340 * ) V_157 , V_362 , V_2 , & V_363 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_363 )
return 0 ;
if ( V_2 [ V_51 ] ) {
V_128 = F_18 ( F_2 ( V_2 [ V_51 ] ) ,
sizeof( * V_128 ) , V_67 ) ;
if ( ! V_128 )
return 0 ;
}
V_37 = V_340 ( & V_361 -> V_93 , V_361 -> V_261 , type , V_157 , V_363 , V_362 , V_118 , V_128 ) ;
F_28 ( V_128 ) ;
return V_37 ;
}
static int F_177 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_1 * * V_2 )
{
return - V_365 ;
}
static int F_178 ( const struct V_340 * V_157 , struct V_142 * V_143 )
{
struct V_346 V_347 ;
memset ( & V_347 , 0 , sizeof( V_347 ) ) ;
V_347 . V_33 = V_157 -> V_33 ;
V_347 . V_45 = V_157 -> V_45 ;
V_347 . V_95 = V_157 -> V_95 ;
V_347 . V_359 = V_157 -> V_359 ;
memcpy ( & V_347 . V_355 , & V_157 -> V_355 , sizeof( V_347 . V_355 ) ) ;
memcpy ( & V_347 . V_356 , & V_157 -> V_356 , sizeof( V_347 . V_356 ) ) ;
V_347 . V_360 = V_157 -> V_360 ;
memcpy ( & V_347 . V_357 , & V_157 -> V_357 , sizeof( V_347 . V_357 ) ) ;
memcpy ( & V_347 . V_358 , & V_157 -> V_358 , sizeof( V_347 . V_358 ) ) ;
return F_69 ( V_143 , V_345 , sizeof( V_347 ) , & V_347 ) ;
}
static int F_179 ( const struct V_342 * V_343 , struct V_142 * V_143 )
{
struct V_349 V_350 ;
memset ( & V_350 , 0 , sizeof( V_350 ) ) ;
V_350 . V_38 = V_343 -> V_38 ;
V_350 . V_354 = V_343 -> V_354 ;
memcpy ( & V_350 . V_352 , & V_343 -> V_352 , sizeof( V_350 . V_352 ) ) ;
memcpy ( & V_350 . V_353 , & V_343 -> V_353 , sizeof( V_350 . V_353 ) ) ;
return F_69 ( V_143 , V_351 , sizeof( V_350 ) , & V_350 ) ;
}
static inline T_4 F_180 ( int V_348 , int V_366 ,
int V_367 )
{
return F_92 ( sizeof( struct V_312 ) )
+ ( V_366 ? F_93 ( sizeof( struct V_342 ) ) : 0 )
+ ( V_367 ? F_93 ( sizeof( struct V_364 ) ) : 0 )
+ F_93 ( sizeof( struct V_346 ) * V_348 )
+ F_142 () ;
}
static int F_181 ( struct V_142 * V_143 , const struct V_340 * V_157 ,
int V_348 , const struct V_342 * V_343 ,
const struct V_368 * V_93 ,
const struct V_364 * V_128 , T_2 V_261 , T_2 type )
{
const struct V_340 * V_369 ;
struct V_312 * V_370 ;
struct V_144 * V_145 ;
int V_284 , V_37 ;
V_145 = F_73 ( V_143 , 0 , 0 , V_371 , sizeof( * V_370 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_370 = F_45 ( V_145 ) ;
memset ( V_370 , 0 , sizeof( * V_370 ) ) ;
memcpy ( & V_370 -> V_93 , V_93 , sizeof( V_370 -> V_93 ) ) ;
V_370 -> V_261 = V_261 ;
if ( V_343 != NULL ) {
V_37 = F_179 ( V_343 , V_143 ) ;
if ( V_37 )
goto V_324;
}
if ( V_128 ) {
V_37 = F_69 ( V_143 , V_51 , sizeof( * V_128 ) , V_128 ) ;
if ( V_37 )
goto V_324;
}
V_37 = F_143 ( type , V_143 ) ;
if ( V_37 )
goto V_324;
for ( V_284 = 0 , V_369 = V_157 ; V_284 < V_348 ; V_284 ++ , V_369 ++ ) {
V_37 = F_178 ( V_369 , V_143 ) ;
if ( V_37 )
goto V_324;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
V_324:
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
static int F_182 ( const struct V_368 * V_93 , T_2 V_261 , T_2 type ,
const struct V_340 * V_157 , int V_348 ,
const struct V_342 * V_343 ,
const struct V_364 * V_128 )
{
struct V_118 * V_118 = & V_372 ;
struct V_142 * V_143 ;
V_143 = F_85 ( F_180 ( V_348 , ! ! V_343 , ! ! V_128 ) ,
V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_181 ( V_143 , V_157 , V_348 , V_343 , V_93 , V_128 , V_261 , type ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_373 ) ;
}
static int F_182 ( const struct V_368 * V_93 , T_2 V_261 , T_2 type ,
const struct V_340 * V_157 , int V_348 ,
const struct V_342 * V_343 ,
const struct V_364 * V_128 )
{
return - V_365 ;
}
static int F_183 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_374 * V_375 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
struct V_1 * V_2 [ V_199 + 1 ] ;
const struct V_376 * V_377 ;
int type , V_37 ;
#ifdef F_184
if ( F_185 () )
return - V_378 ;
#endif
type = V_145 -> V_149 ;
if ( type > V_379 )
return - V_7 ;
type -= V_380 ;
V_377 = & V_381 [ type ] ;
if ( ! F_186 ( V_143 , V_382 ) )
return - V_162 ;
if ( ( type == ( V_383 - V_380 ) ||
type == ( V_384 - V_380 ) ) &&
( V_145 -> V_191 & V_385 ) ) {
if ( V_377 -> V_386 == NULL )
return - V_7 ;
{
struct V_387 V_148 = {
. V_386 = V_377 -> V_386 ,
. V_388 = V_377 -> V_388 ,
} ;
return F_187 ( V_118 -> V_135 . V_209 , V_143 , V_145 , & V_148 ) ;
}
}
V_37 = F_81 ( V_145 , V_389 [ type ] , V_2 ,
V_377 -> V_390 ? : V_199 ,
V_377 -> V_391 ? : V_202 , V_375 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_377 -> V_392 == NULL )
return - V_7 ;
return V_377 -> V_392 ( V_143 , V_145 , V_2 ) ;
}
static void F_188 ( struct V_142 * V_143 )
{
struct V_118 * V_118 = F_44 ( V_143 -> V_146 ) ;
F_189 ( & V_118 -> V_135 . V_393 ) ;
F_190 ( V_143 , & F_183 ) ;
F_191 ( & V_118 -> V_135 . V_393 ) ;
}
static inline T_4 F_192 ( void )
{
return F_92 ( sizeof( struct V_332 ) )
+ F_93 ( sizeof( struct V_156 ) ) ;
}
static int F_193 ( struct V_142 * V_143 , struct V_56 * V_57 , const struct V_147 * V_148 )
{
struct V_332 * V_333 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , 0 , V_394 , sizeof( * V_333 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_333 = F_45 ( V_145 ) ;
F_61 ( V_57 , & V_333 -> V_140 ) ;
V_333 -> V_331 = ( V_148 -> V_316 . V_331 != 0 ) ? 1 : 0 ;
memset ( & V_333 -> V_331 + 1 , 0 , sizeof( * V_333 ) - F_194 ( F_195 ( * V_333 ) , V_331 ) ) ;
V_37 = F_71 ( V_143 , & V_57 -> V_131 ) ;
if ( V_37 )
return V_37 ;
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_196 ( struct V_56 * V_57 , const struct V_147 * V_148 )
{
struct V_118 * V_118 = F_197 ( V_57 ) ;
struct V_142 * V_143 ;
V_143 = F_85 ( F_192 () , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_193 ( V_143 , V_57 , V_148 ) < 0 ) {
F_87 ( V_143 ) ;
return - V_168 ;
}
return F_88 ( V_118 , V_143 , 0 , V_395 ) ;
}
static int F_198 ( struct V_56 * V_57 , const struct V_147 * V_148 )
{
struct V_118 * V_118 = F_197 ( V_57 ) ;
struct V_142 * V_143 ;
V_143 = F_85 ( F_157 ( V_57 ) , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_159 ( V_143 , V_57 , V_148 ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_396 ) ;
}
static int F_199 ( const struct V_147 * V_148 )
{
struct V_118 * V_118 = V_148 -> V_118 ;
struct V_318 * V_23 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_20 = F_92 ( sizeof( struct V_318 ) ) ;
V_143 = F_85 ( V_20 , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_397 , sizeof( * V_23 ) , 0 ) ;
if ( V_145 == NULL ) {
F_87 ( V_143 ) ;
return - V_168 ;
}
V_23 = F_45 ( V_145 ) ;
V_23 -> V_33 = V_148 -> V_316 . V_33 ;
F_76 ( V_143 , V_145 ) ;
return F_88 ( V_118 , V_143 , 0 , V_398 ) ;
}
static inline T_4 F_200 ( struct V_56 * V_57 )
{
T_4 V_399 = 0 ;
if ( V_57 -> V_82 )
V_399 += F_93 ( F_8 ( V_57 -> V_82 ) ) ;
if ( V_57 -> V_123 ) {
V_399 += F_93 ( sizeof( struct V_5 ) +
( V_57 -> V_123 -> V_75 + 7 ) / 8 ) ;
V_399 += F_93 ( F_6 ( V_57 -> V_123 ) ) ;
}
if ( V_57 -> V_70 )
V_399 += F_93 ( F_4 ( V_57 -> V_70 ) ) ;
if ( V_57 -> V_125 )
V_399 += F_93 ( sizeof( * V_57 -> V_125 ) ) ;
if ( V_57 -> V_128 )
V_399 += F_93 ( sizeof( * V_57 -> V_128 ) ) ;
if ( V_57 -> V_129 )
V_399 += F_93 ( sizeof( V_57 -> V_129 ) ) ;
if ( V_57 -> V_83 )
V_399 += F_93 ( F_12 ( V_57 -> V_83 ) ) ;
else
V_399 += F_93 ( sizeof( struct V_106 ) ) ;
if ( V_57 -> V_184 )
V_399 += F_93 ( sizeof( struct V_18 ) +
V_57 -> V_184 -> V_21 ) ;
if ( V_57 -> V_130 )
V_399 += F_93 ( sizeof( * V_57 -> V_130 ) ) ;
if ( V_57 -> V_63 . V_122 )
V_399 += F_93 ( sizeof( V_57 -> V_63 . V_122 ) ) ;
if ( V_57 -> V_174 . V_178 )
V_399 += F_93 ( sizeof( V_57 -> V_174 ) ) ;
V_399 += F_158 ( sizeof( V_400 ) ) ;
return V_399 ;
}
static int F_201 ( struct V_56 * V_57 , const struct V_147 * V_148 )
{
struct V_118 * V_118 = F_197 ( V_57 ) ;
struct V_22 * V_23 ;
struct V_155 * V_32 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_20 = F_200 ( V_57 ) ;
int V_401 , V_37 ;
V_401 = sizeof( * V_23 ) ;
if ( V_148 -> V_154 == V_402 ) {
V_20 += F_93 ( V_401 ) ;
V_401 = sizeof( * V_32 ) ;
V_20 += F_93 ( sizeof( struct V_156 ) ) ;
}
V_20 += F_92 ( V_401 ) ;
V_143 = F_85 ( V_20 , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_148 -> V_154 , V_401 , 0 ) ;
V_37 = - V_168 ;
if ( V_145 == NULL )
goto V_403;
V_23 = F_45 ( V_145 ) ;
if ( V_148 -> V_154 == V_402 ) {
struct V_1 * V_166 ;
V_32 = F_45 ( V_145 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
memcpy ( & V_32 -> V_160 , & V_57 -> V_32 . V_160 , sizeof( V_32 -> V_160 ) ) ;
V_32 -> V_48 = V_57 -> V_32 . V_48 ;
V_32 -> V_38 = V_57 -> V_63 . V_38 ;
V_32 -> V_33 = V_57 -> V_32 . V_33 ;
V_166 = F_64 ( V_143 , V_404 , sizeof( * V_23 ) ) ;
V_37 = - V_168 ;
if ( V_166 == NULL )
goto V_403;
V_23 = F_2 ( V_166 ) ;
}
V_37 = F_67 ( V_57 , V_23 , V_143 ) ;
if ( V_37 )
goto V_403;
F_76 ( V_143 , V_145 ) ;
return F_88 ( V_118 , V_143 , 0 , V_398 ) ;
V_403:
F_87 ( V_143 ) ;
return V_37 ;
}
static int F_202 ( struct V_56 * V_57 , const struct V_147 * V_148 )
{
switch ( V_148 -> V_154 ) {
case V_394 :
return F_196 ( V_57 , V_148 ) ;
case V_321 :
return F_198 ( V_57 , V_148 ) ;
case V_402 :
case V_405 :
case V_150 :
return F_201 ( V_57 , V_148 ) ;
case V_397 :
return F_199 ( V_148 ) ;
default:
F_203 ( V_406 L_1 ,
V_148 -> V_154 ) ;
break;
}
return 0 ;
}
static inline T_4 F_204 ( struct V_56 * V_57 ,
struct V_278 * V_280 )
{
return F_92 ( sizeof( struct V_334 ) )
+ F_93 ( sizeof( struct V_281 ) * V_280 -> V_285 )
+ F_93 ( sizeof( struct V_156 ) )
+ F_93 ( F_29 ( V_57 -> V_184 ) )
+ F_142 () ;
}
static int F_205 ( struct V_142 * V_143 , struct V_56 * V_57 ,
struct V_286 * V_407 , struct V_278 * V_280 )
{
V_87 V_134 = F_206 () ;
struct V_334 * V_335 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , 0 , 0 , V_408 , sizeof( * V_335 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_335 = F_45 ( V_145 ) ;
memcpy ( & V_335 -> V_32 , & V_57 -> V_32 , sizeof( V_335 -> V_32 ) ) ;
memcpy ( & V_335 -> V_96 , & V_57 -> V_63 . V_96 , sizeof( V_335 -> V_96 ) ) ;
memcpy ( & V_335 -> V_93 , & V_57 -> V_93 , sizeof( V_335 -> V_93 ) ) ;
F_129 ( V_280 , & V_335 -> V_337 , V_263 ) ;
V_335 -> V_291 = V_407 -> V_291 ;
V_335 -> V_292 = V_407 -> V_292 ;
V_335 -> V_293 = V_407 -> V_293 ;
V_335 -> V_134 = V_57 -> V_133 . V_134 = V_134 ;
V_37 = F_139 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_140 ( V_57 , V_143 ) ;
if ( ! V_37 )
V_37 = F_143 ( V_280 -> type , V_143 ) ;
if ( ! V_37 )
V_37 = F_71 ( V_143 , & V_280 -> V_131 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_207 ( struct V_56 * V_57 , struct V_286 * V_407 ,
struct V_278 * V_280 )
{
struct V_118 * V_118 = F_197 ( V_57 ) ;
struct V_142 * V_143 ;
V_143 = F_85 ( F_204 ( V_57 , V_280 ) , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_205 ( V_143 , V_57 , V_407 , V_280 ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_409 ) ;
}
static struct V_278 * F_208 ( struct V_196 * V_146 , int V_410 ,
T_2 * V_316 , int V_20 , int * V_261 )
{
struct V_118 * V_118 = F_44 ( V_146 ) ;
struct V_267 * V_23 = (struct V_267 * ) V_316 ;
struct V_281 * V_282 = (struct V_281 * ) ( V_23 + 1 ) ;
struct V_278 * V_280 ;
int V_283 ;
switch ( V_146 -> V_411 ) {
case V_39 :
if ( V_410 != V_412 ) {
* V_261 = - V_378 ;
return NULL ;
}
break;
#if F_14 ( V_41 )
case V_40 :
if ( V_410 != V_413 ) {
* V_261 = - V_378 ;
return NULL ;
}
break;
#endif
default:
* V_261 = - V_7 ;
return NULL ;
}
* V_261 = - V_7 ;
if ( V_20 < sizeof( * V_23 ) ||
F_121 ( V_23 ) )
return NULL ;
V_283 = ( ( V_20 - sizeof( * V_23 ) ) / sizeof( * V_282 ) ) ;
if ( F_125 ( V_283 , V_282 , V_23 -> V_93 . V_38 ) )
return NULL ;
if ( V_23 -> V_261 > V_263 )
return NULL ;
V_280 = F_131 ( V_118 , V_206 ) ;
if ( V_280 == NULL ) {
* V_261 = - V_414 ;
return NULL ;
}
F_128 ( V_280 , V_23 ) ;
V_280 -> type = V_265 ;
F_124 ( V_280 , V_282 , V_283 ) ;
* V_261 = V_23 -> V_261 ;
return V_280 ;
}
static inline T_4 F_209 ( struct V_278 * V_280 )
{
return F_92 ( sizeof( struct V_330 ) )
+ F_93 ( sizeof( struct V_281 ) * V_280 -> V_285 )
+ F_93 ( F_29 ( V_280 -> V_184 ) )
+ F_93 ( sizeof( struct V_156 ) )
+ F_142 () ;
}
static int F_210 ( struct V_142 * V_143 , struct V_278 * V_280 ,
int V_261 , const struct V_147 * V_148 )
{
struct V_330 * V_415 ;
int V_331 = V_148 -> V_316 . V_331 ;
struct V_144 * V_145 ;
int V_37 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , 0 , V_416 , sizeof( * V_415 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_415 = F_45 ( V_145 ) ;
F_129 ( V_280 , & V_415 -> V_279 , V_261 ) ;
V_37 = F_139 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_141 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_143 ( V_280 -> type , V_143 ) ;
if ( ! V_37 )
V_37 = F_71 ( V_143 , & V_280 -> V_131 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
V_415 -> V_331 = ! ! V_331 ;
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_211 ( struct V_278 * V_280 , int V_261 , const struct V_147 * V_148 )
{
struct V_118 * V_118 = F_212 ( V_280 ) ;
struct V_142 * V_143 ;
V_143 = F_85 ( F_209 ( V_280 ) , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_210 ( V_143 , V_280 , V_261 , V_148 ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_395 ) ;
}
static int F_213 ( struct V_278 * V_280 , int V_261 , const struct V_147 * V_148 )
{
int V_20 = F_93 ( sizeof( struct V_281 ) * V_280 -> V_285 ) ;
struct V_118 * V_118 = F_212 ( V_280 ) ;
struct V_267 * V_23 ;
struct V_312 * V_32 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_401 , V_37 ;
V_401 = sizeof( * V_23 ) ;
if ( V_148 -> V_154 == V_314 ) {
V_20 += F_93 ( V_401 ) ;
V_401 = sizeof( * V_32 ) ;
}
V_20 += F_142 () ;
V_20 += F_93 ( sizeof( struct V_156 ) ) ;
V_20 += F_92 ( V_401 ) ;
V_143 = F_85 ( V_20 , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_148 -> V_154 , V_401 , 0 ) ;
V_37 = - V_168 ;
if ( V_145 == NULL )
goto V_403;
V_23 = F_45 ( V_145 ) ;
if ( V_148 -> V_154 == V_314 ) {
struct V_1 * V_166 ;
V_32 = F_45 ( V_145 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_261 = V_261 ;
if ( V_148 -> V_316 . V_317 )
V_32 -> V_276 = V_280 -> V_276 ;
else
memcpy ( & V_32 -> V_93 , & V_280 -> V_304 , sizeof( V_32 -> V_93 ) ) ;
V_166 = F_64 ( V_143 , V_417 , sizeof( * V_23 ) ) ;
V_37 = - V_168 ;
if ( V_166 == NULL )
goto V_403;
V_23 = F_2 ( V_166 ) ;
}
F_129 ( V_280 , V_23 , V_261 ) ;
V_37 = F_139 ( V_280 , V_143 ) ;
if ( ! V_37 )
V_37 = F_143 ( V_280 -> type , V_143 ) ;
if ( ! V_37 )
V_37 = F_71 ( V_143 , & V_280 -> V_131 ) ;
if ( V_37 )
goto V_403;
F_76 ( V_143 , V_145 ) ;
return F_88 ( V_118 , V_143 , 0 , V_418 ) ;
V_403:
F_87 ( V_143 ) ;
return V_37 ;
}
static int F_214 ( const struct V_147 * V_148 )
{
struct V_118 * V_118 = V_148 -> V_118 ;
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_37 ;
V_143 = F_85 ( F_142 () , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
V_145 = F_73 ( V_143 , V_148 -> V_152 , V_148 -> V_134 , V_419 , 0 , 0 ) ;
V_37 = - V_168 ;
if ( V_145 == NULL )
goto V_403;
V_37 = F_143 ( V_148 -> V_316 . type , V_143 ) ;
if ( V_37 )
goto V_403;
F_76 ( V_143 , V_145 ) ;
return F_88 ( V_118 , V_143 , 0 , V_418 ) ;
V_403:
F_87 ( V_143 ) ;
return V_37 ;
}
static int F_215 ( struct V_278 * V_280 , int V_261 , const struct V_147 * V_148 )
{
switch ( V_148 -> V_154 ) {
case V_307 :
case V_420 :
case V_314 :
return F_213 ( V_280 , V_261 , V_148 ) ;
case V_419 :
return F_214 ( V_148 ) ;
case V_416 :
return F_211 ( V_280 , V_261 , V_148 ) ;
default:
F_203 ( V_406 L_2 ,
V_148 -> V_154 ) ;
}
return 0 ;
}
static inline T_4 F_216 ( void )
{
return F_92 ( sizeof( struct V_421 ) ) ;
}
static int F_217 ( struct V_142 * V_143 , T_2 V_33 ,
struct V_368 * V_93 , T_1 * V_422 )
{
struct V_421 * V_423 ;
struct V_144 * V_145 ;
V_145 = F_73 ( V_143 , 0 , 0 , V_424 , sizeof( * V_423 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_423 = F_45 ( V_145 ) ;
V_423 -> V_33 = V_33 ;
memcpy ( & V_423 -> V_93 , V_93 , sizeof( V_423 -> V_93 ) ) ;
if ( V_422 ) {
int V_37 = F_69 ( V_143 , V_52 , sizeof( * V_422 ) , V_422 ) ;
if ( V_37 ) {
F_75 ( V_143 , V_145 ) ;
return V_37 ;
}
}
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_218 ( struct V_118 * V_118 , T_2 V_33 ,
struct V_368 * V_93 , T_1 * V_422 )
{
struct V_142 * V_143 ;
V_143 = F_85 ( F_216 () , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_217 ( V_143 , V_33 , V_93 , V_422 ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_425 ) ;
}
static inline T_4 F_219 ( void )
{
return F_92 ( sizeof( struct V_426 ) ) ;
}
static int F_220 ( struct V_142 * V_143 , struct V_56 * V_57 ,
T_1 * V_358 , T_6 V_427 )
{
struct V_426 * V_347 ;
struct V_144 * V_145 ;
V_145 = F_73 ( V_143 , 0 , 0 , V_428 , sizeof( * V_347 ) , 0 ) ;
if ( V_145 == NULL )
return - V_168 ;
V_347 = F_45 ( V_145 ) ;
memcpy ( & V_347 -> V_32 . V_160 , & V_57 -> V_32 . V_160 , sizeof( V_347 -> V_32 . V_160 ) ) ;
V_347 -> V_32 . V_48 = V_57 -> V_32 . V_48 ;
V_347 -> V_32 . V_38 = V_57 -> V_63 . V_38 ;
V_347 -> V_32 . V_33 = V_57 -> V_32 . V_33 ;
memcpy ( & V_347 -> V_358 , V_358 , sizeof( V_347 -> V_358 ) ) ;
memcpy ( & V_347 -> V_356 , & V_57 -> V_63 . V_96 , sizeof( V_347 -> V_356 ) ) ;
V_347 -> V_427 = V_427 ;
V_347 -> V_429 = V_57 -> V_128 -> V_430 ;
V_347 -> V_95 = V_57 -> V_63 . V_95 ;
F_76 ( V_143 , V_145 ) ;
return 0 ;
}
static int F_221 ( struct V_56 * V_57 , T_1 * V_431 ,
T_6 V_432 )
{
struct V_118 * V_118 = F_197 ( V_57 ) ;
struct V_142 * V_143 ;
if ( V_57 -> V_32 . V_33 != V_34 )
return - V_7 ;
if ( ! V_57 -> V_128 )
return - V_7 ;
V_143 = F_85 ( F_219 () , V_206 ) ;
if ( V_143 == NULL )
return - V_68 ;
if ( F_220 ( V_143 , V_57 , V_431 , V_432 ) < 0 )
F_103 () ;
return F_88 ( V_118 , V_143 , 0 , V_433 ) ;
}
static bool F_222 ( const struct V_147 * V_148 )
{
return ( bool ) F_223 ( V_148 -> V_118 ) ;
}
static int T_7 F_224 ( struct V_118 * V_118 )
{
struct V_196 * V_209 ;
struct V_434 V_435 = {
. V_436 = V_437 ,
. V_438 = F_188 ,
} ;
V_209 = F_225 ( V_118 , V_439 , & V_435 ) ;
if ( V_209 == NULL )
return - V_68 ;
V_118 -> V_135 . V_440 = V_209 ;
F_226 ( V_118 -> V_135 . V_209 , V_209 ) ;
return 0 ;
}
static void T_8 F_227 ( struct V_441 * V_442 )
{
struct V_118 * V_118 ;
F_228 (net, net_exit_list, exit_list)
F_229 ( V_118 -> V_135 . V_209 , NULL ) ;
F_230 () ;
F_228 (net, net_exit_list, exit_list)
F_231 ( V_118 -> V_135 . V_440 ) ;
}
static int T_9 F_232 ( void )
{
int V_443 ;
F_203 ( V_444 L_3 ) ;
V_443 = F_233 ( & V_445 ) ;
if ( V_443 < 0 )
return V_443 ;
V_443 = F_234 ( & V_446 ) ;
if ( V_443 < 0 )
F_235 ( & V_445 ) ;
return V_443 ;
}
static void T_10 F_236 ( void )
{
F_237 ( & V_446 ) ;
F_235 ( & V_445 ) ;
}
