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
if ( V_60 -> V_70 > V_62 -> V_71 . V_72 . V_75 )
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
V_62 = F_22 ( V_60 -> V_11 , V_60 -> V_76 , 1 ) ;
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
static inline int F_23 ( struct V_26 * V_77 ,
struct V_1 * V_78 )
{
struct V_26 * V_79 ;
int V_80 ;
if ( ! V_77 || ! V_78 )
return 0 ;
V_79 = F_2 ( V_78 ) ;
V_80 = F_12 ( V_79 ) ;
if ( F_3 ( V_78 ) < V_80 || F_12 ( V_77 ) != V_80 )
return - V_7 ;
return 0 ;
}
static int F_24 ( struct V_26 * * V_77 ,
struct V_26 * * V_81 ,
struct V_1 * V_59 )
{
struct V_26 * V_24 , * V_82 , * V_79 ;
int V_83 , V_80 ;
if ( ! V_59 )
return 0 ;
V_79 = F_2 ( V_59 ) ;
V_83 = F_12 ( V_79 ) ;
V_80 = F_3 ( V_59 ) >= V_83 ? V_83 : sizeof( * V_79 ) ;
V_24 = F_25 ( V_83 , V_67 ) ;
if ( ! V_24 )
return - V_68 ;
V_82 = F_25 ( V_83 , V_67 ) ;
if ( ! V_82 ) {
F_26 ( V_24 ) ;
return - V_68 ;
}
memcpy ( V_24 , V_79 , V_80 ) ;
memcpy ( V_82 , V_79 , V_80 ) ;
* V_77 = V_24 ;
* V_81 = V_82 ;
return 0 ;
}
static inline int F_27 ( struct V_84 * V_85 )
{
int V_21 = 0 ;
if ( V_85 ) {
V_21 += sizeof( struct V_19 ) ;
V_21 += V_85 -> V_22 ;
}
return V_21 ;
}
static void F_28 ( struct V_86 * V_87 , struct V_23 * V_24 )
{
memcpy ( & V_87 -> V_33 , & V_24 -> V_33 , sizeof( V_87 -> V_33 ) ) ;
memcpy ( & V_87 -> V_88 , & V_24 -> V_88 , sizeof( V_87 -> V_88 ) ) ;
memcpy ( & V_87 -> V_89 , & V_24 -> V_89 , sizeof( V_87 -> V_89 ) ) ;
V_87 -> V_58 . V_46 = V_24 -> V_46 ;
V_87 -> V_58 . V_37 = F_29 (unsigned int, p->replay_window,
sizeof(x->replay.bitmap) * 8 ) ;
V_87 -> V_58 . V_90 = V_24 -> V_90 ;
V_87 -> V_58 . V_39 = V_24 -> V_39 ;
memcpy ( & V_87 -> V_58 . V_91 , & V_24 -> V_91 , sizeof( V_87 -> V_58 . V_91 ) ) ;
V_87 -> V_58 . V_28 = V_24 -> V_28 ;
if ( ! V_87 -> V_88 . V_39 && ! ( V_24 -> V_28 & V_92 ) )
V_87 -> V_88 . V_39 = V_24 -> V_39 ;
}
static void F_30 ( struct V_86 * V_87 , struct V_1 * * V_2 ,
int V_93 )
{
struct V_1 * V_78 = V_2 [ V_94 ] ;
struct V_1 * V_95 = V_93 ? V_2 [ V_25 ] : NULL ;
struct V_1 * V_96 = V_2 [ V_97 ] ;
struct V_1 * V_98 = V_2 [ V_99 ] ;
struct V_1 * V_4 = V_2 [ V_100 ] ;
if ( V_95 ) {
struct V_26 * V_77 ;
V_77 = F_2 ( V_95 ) ;
memcpy ( V_87 -> V_77 , V_77 ,
F_12 ( V_77 ) ) ;
memcpy ( V_87 -> V_81 , V_77 ,
F_12 ( V_77 ) ) ;
}
if ( V_78 ) {
struct V_101 * V_102 ;
V_102 = F_2 ( V_78 ) ;
memcpy ( & V_87 -> V_102 , V_102 , sizeof( * V_102 ) ) ;
memcpy ( & V_87 -> V_103 , V_102 , sizeof( * V_102 ) ) ;
}
if ( V_96 ) {
struct V_104 * V_105 ;
V_105 = F_2 ( V_96 ) ;
V_87 -> V_106 . V_107 = V_105 -> V_107 ;
V_87 -> V_106 . V_108 = V_105 -> V_108 ;
V_87 -> V_106 . V_109 = V_105 -> V_109 ;
V_87 -> V_106 . V_110 = V_105 -> V_110 ;
}
if ( V_98 )
V_87 -> V_111 = F_31 ( V_98 ) ;
if ( V_4 )
V_87 -> V_112 = F_31 ( V_4 ) ;
}
static struct V_86 * F_32 ( struct V_113 * V_113 ,
struct V_23 * V_24 ,
struct V_1 * * V_2 ,
int * V_114 )
{
struct V_86 * V_87 = F_33 ( V_113 ) ;
int V_38 = - V_68 ;
if ( ! V_87 )
goto V_115;
F_28 ( V_87 , V_24 ) ;
if ( V_2 [ V_116 ] )
V_87 -> V_58 . V_117 = F_31 ( V_2 [ V_116 ] ) ;
if ( ( V_38 = F_21 ( & V_87 -> V_118 , & V_87 -> V_58 . V_119 ,
V_2 [ V_15 ] ) ) )
goto error;
if ( ( V_38 = F_19 ( & V_87 -> V_120 , & V_87 -> V_58 . V_121 ,
V_2 [ V_13 ] ) ) )
goto error;
if ( ! V_87 -> V_58 . V_121 ) {
if ( ( V_38 = F_16 ( & V_87 -> V_120 , & V_87 -> V_58 . V_121 ,
V_2 [ V_8 ] ) ) )
goto error;
}
if ( ( V_38 = F_34 ( & V_87 -> V_122 , & V_87 -> V_58 . V_119 ,
V_123 ,
V_2 [ V_9 ] ) ) )
goto error;
if ( ( V_38 = F_34 ( & V_87 -> V_124 , & V_87 -> V_58 . V_125 ,
V_126 ,
V_2 [ V_10 ] ) ) )
goto error;
if ( V_2 [ V_52 ] ) {
V_87 -> V_127 = F_20 ( F_2 ( V_2 [ V_52 ] ) ,
sizeof( * V_87 -> V_127 ) , V_67 ) ;
if ( V_87 -> V_127 == NULL )
goto error;
}
if ( V_2 [ V_45 ] )
V_87 -> V_128 = F_31 ( V_2 [ V_45 ] ) ;
if ( V_2 [ V_53 ] ) {
V_87 -> V_129 = F_20 ( F_2 ( V_2 [ V_53 ] ) ,
sizeof( * V_87 -> V_129 ) , V_67 ) ;
if ( V_87 -> V_129 == NULL )
goto error;
}
F_35 ( V_2 , & V_87 -> V_130 ) ;
V_38 = F_36 ( V_87 , false ) ;
if ( V_38 )
goto error;
if ( V_2 [ V_18 ] &&
F_37 ( V_87 , F_2 ( V_2 [ V_18 ] ) ) )
goto error;
if ( ( V_38 = F_24 ( & V_87 -> V_77 , & V_87 -> V_81 ,
V_2 [ V_25 ] ) ) )
goto error;
V_87 -> V_131 . V_132 = V_24 -> V_132 ;
V_87 -> V_112 = V_113 -> V_133 . V_134 ;
V_87 -> V_111 = ( V_113 -> V_133 . V_135 * V_136 ) / V_137 ;
if ( ( V_38 = F_38 ( V_87 ) ) )
goto error;
F_30 ( V_87 , V_2 , 0 ) ;
return V_87 ;
error:
V_87 -> V_131 . V_138 = V_139 ;
F_39 ( V_87 ) ;
V_115:
* V_114 = V_38 ;
return NULL ;
}
static int F_40 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_23 * V_24 = F_42 ( V_143 ) ;
struct V_86 * V_87 ;
int V_38 ;
struct V_145 V_146 ;
V_38 = F_13 ( V_24 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_87 = F_32 ( V_113 , V_24 , V_2 , & V_38 ) ;
if ( ! V_87 )
return V_38 ;
F_43 ( V_87 ) ;
if ( V_143 -> V_147 == V_148 )
V_38 = F_44 ( V_87 ) ;
else
V_38 = F_45 ( V_87 ) ;
F_46 ( V_87 , V_38 ? 0 : 1 , true ) ;
if ( V_38 < 0 ) {
V_87 -> V_131 . V_138 = V_139 ;
F_47 ( V_87 ) ;
goto V_44;
}
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
V_146 . V_152 = V_143 -> V_147 ;
F_48 ( V_87 , & V_146 ) ;
V_44:
F_39 ( V_87 ) ;
return V_38 ;
}
static struct V_86 * F_49 ( struct V_113 * V_113 ,
struct V_153 * V_24 ,
struct V_1 * * V_2 ,
int * V_114 )
{
struct V_86 * V_87 = NULL ;
struct V_154 V_155 ;
int V_38 ;
T_3 V_130 = F_35 ( V_2 , & V_155 ) ;
if ( F_50 ( V_24 -> V_34 , V_156 ) ) {
V_38 = - V_157 ;
V_87 = F_51 ( V_113 , V_130 , & V_24 -> V_158 , V_24 -> V_49 , V_24 -> V_34 , V_24 -> V_39 ) ;
} else {
T_1 * V_91 = NULL ;
F_9 ( V_2 , V_159 , & V_91 ) ;
if ( ! V_91 ) {
V_38 = - V_7 ;
goto V_44;
}
V_38 = - V_157 ;
V_87 = F_52 ( V_113 , V_130 ,
& V_24 -> V_158 , V_91 ,
V_24 -> V_34 , V_24 -> V_39 ) ;
}
V_44:
if ( ! V_87 && V_114 )
* V_114 = V_38 ;
return V_87 ;
}
static int F_53 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_86 * V_87 ;
int V_38 = - V_157 ;
struct V_145 V_146 ;
struct V_153 * V_24 = F_42 ( V_143 ) ;
V_87 = F_49 ( V_113 , V_24 , V_2 , & V_38 ) ;
if ( V_87 == NULL )
return V_38 ;
if ( ( V_38 = F_54 ( V_87 ) ) != 0 )
goto V_44;
if ( F_55 ( V_87 ) ) {
V_38 = - V_160 ;
goto V_44;
}
V_38 = F_56 ( V_87 ) ;
if ( V_38 < 0 )
goto V_44;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
V_146 . V_152 = V_143 -> V_147 ;
F_48 ( V_87 , & V_146 ) ;
V_44:
F_57 ( V_87 , V_38 ? 0 : 1 , true ) ;
F_39 ( V_87 ) ;
return V_38 ;
}
static void F_58 ( struct V_86 * V_87 , struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_33 , & V_87 -> V_33 , sizeof( V_24 -> V_33 ) ) ;
memcpy ( & V_24 -> V_88 , & V_87 -> V_88 , sizeof( V_24 -> V_88 ) ) ;
memcpy ( & V_24 -> V_89 , & V_87 -> V_89 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_106 , & V_87 -> V_106 , sizeof( V_24 -> V_106 ) ) ;
memcpy ( & V_24 -> V_161 , & V_87 -> V_161 , sizeof( V_24 -> V_161 ) ) ;
memcpy ( & V_24 -> V_91 , & V_87 -> V_58 . V_91 , sizeof( V_24 -> V_91 ) ) ;
V_24 -> V_46 = V_87 -> V_58 . V_46 ;
V_24 -> V_37 = V_87 -> V_58 . V_37 ;
V_24 -> V_90 = V_87 -> V_58 . V_90 ;
V_24 -> V_39 = V_87 -> V_58 . V_39 ;
V_24 -> V_28 = V_87 -> V_58 . V_28 ;
V_24 -> V_132 = V_87 -> V_131 . V_132 ;
}
static int F_59 ( struct V_84 * V_162 , struct V_140 * V_141 )
{
struct V_19 * V_20 ;
struct V_1 * V_163 ;
int V_164 = sizeof( * V_20 ) + V_162 -> V_22 ;
V_163 = F_60 ( V_141 , V_18 , V_164 ) ;
if ( V_163 == NULL )
return - V_165 ;
V_20 = F_2 ( V_163 ) ;
V_20 -> V_166 = V_18 ;
V_20 -> V_21 = V_164 ;
V_20 -> V_167 = V_162 -> V_167 ;
V_20 -> V_168 = V_162 -> V_168 ;
V_20 -> V_22 = V_162 -> V_22 ;
memcpy ( V_20 + 1 , V_162 -> V_169 , V_162 -> V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_72 , struct V_140 * V_141 )
{
struct V_5 * V_62 ;
struct V_1 * V_170 ;
V_170 = F_60 ( V_141 , V_8 ,
sizeof( * V_62 ) + ( V_72 -> V_66 + 7 ) / 8 ) ;
if ( ! V_170 )
return - V_165 ;
V_62 = F_2 ( V_170 ) ;
strncpy ( V_62 -> V_11 , V_72 -> V_11 , sizeof( V_62 -> V_11 ) ) ;
memcpy ( V_62 -> V_74 , V_72 -> V_74 , ( V_72 -> V_66 + 7 ) / 8 ) ;
V_62 -> V_66 = V_72 -> V_66 ;
return 0 ;
}
static int F_62 ( struct V_86 * V_87 ,
struct V_23 * V_24 ,
struct V_140 * V_141 )
{
int V_171 = 0 ;
F_58 ( V_87 , V_24 ) ;
if ( V_87 -> V_58 . V_117 ) {
V_171 = F_63 ( V_141 , V_116 ,
V_87 -> V_58 . V_117 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_129 ) {
V_171 = F_64 ( V_141 , V_53 , sizeof( * V_87 -> V_129 ) , V_87 -> V_129 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_172 ) {
V_171 = F_65 ( V_141 , V_173 , V_87 -> V_172 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_118 ) {
V_171 = F_64 ( V_141 , V_15 , F_8 ( V_87 -> V_118 ) , V_87 -> V_118 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_120 ) {
V_171 = F_61 ( V_87 -> V_120 , V_141 ) ;
if ( ! V_171 )
V_171 = F_64 ( V_141 , V_13 ,
F_6 ( V_87 -> V_120 ) , V_87 -> V_120 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_122 ) {
V_171 = F_64 ( V_141 , V_9 , F_4 ( V_87 -> V_122 ) , V_87 -> V_122 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_124 ) {
V_171 = F_64 ( V_141 , V_10 , sizeof( * ( V_87 -> V_124 ) ) , V_87 -> V_124 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_127 ) {
V_171 = F_64 ( V_141 , V_52 , sizeof( * V_87 -> V_127 ) , V_87 -> V_127 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_128 ) {
V_171 = F_63 ( V_141 , V_45 , V_87 -> V_128 ) ;
if ( V_171 )
goto V_44;
}
V_171 = F_66 ( V_141 , & V_87 -> V_130 ) ;
if ( V_171 )
goto V_44;
if ( V_87 -> V_77 ) {
V_171 = F_64 ( V_141 , V_25 ,
F_12 ( V_87 -> V_77 ) ,
V_87 -> V_77 ) ;
if ( V_171 )
goto V_44;
}
if ( V_87 -> V_174 )
V_171 = F_59 ( V_87 -> V_174 , V_141 ) ;
V_44:
return V_171 ;
}
static int F_67 ( struct V_86 * V_87 , int V_175 , void * V_176 )
{
struct V_177 * V_178 = V_176 ;
struct V_140 * V_179 = V_178 -> V_179 ;
struct V_140 * V_141 = V_178 -> V_180 ;
struct V_23 * V_24 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , F_69 ( V_179 ) . V_150 , V_178 -> V_149 ,
V_148 , sizeof( * V_24 ) , V_178 -> V_181 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_24 = F_42 ( V_143 ) ;
V_38 = F_62 ( V_87 , V_24 , V_141 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
F_71 ( V_141 , V_143 ) ;
return 0 ;
}
static int F_72 ( struct V_182 * V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) & V_183 -> args [ 1 ] ;
struct V_186 * V_144 = V_183 -> V_141 -> V_144 ;
struct V_113 * V_113 = F_41 ( V_144 ) ;
F_73 ( V_185 , V_113 ) ;
return 0 ;
}
static int F_74 ( struct V_140 * V_141 , struct V_182 * V_183 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_184 * V_185 = (struct V_184 * ) & V_183 -> args [ 1 ] ;
struct V_177 V_187 ;
F_75 ( sizeof( struct V_184 ) >
sizeof( V_183 -> args ) - sizeof( V_183 -> args [ 0 ] ) ) ;
V_187 . V_179 = V_183 -> V_141 ;
V_187 . V_180 = V_141 ;
V_187 . V_149 = V_183 -> V_143 -> V_149 ;
V_187 . V_181 = V_188 ;
if ( ! V_183 -> args [ 0 ] ) {
struct V_1 * V_2 [ V_189 + 1 ] ;
struct V_190 * V_191 = NULL ;
T_2 V_34 = 0 ;
int V_38 ;
V_183 -> args [ 0 ] = 1 ;
V_38 = F_76 ( V_183 -> V_143 , 0 , V_2 , V_189 ,
V_192 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 [ V_193 ] ) {
V_191 = F_18 ( sizeof( * V_191 ) , V_67 ) ;
if ( V_191 == NULL )
return - V_68 ;
memcpy ( V_191 , F_2 ( V_2 [ V_193 ] ) ,
sizeof( * V_191 ) ) ;
}
if ( V_2 [ V_194 ] )
V_34 = F_77 ( V_2 [ V_194 ] ) ;
F_78 ( V_185 , V_34 , V_191 ) ;
}
( void ) V_184 ( V_113 , V_185 , F_67 , & V_187 ) ;
return V_141 -> V_21 ;
}
static struct V_140 * F_79 ( struct V_140 * V_179 ,
struct V_86 * V_87 , T_3 V_132 )
{
struct V_177 V_187 ;
struct V_140 * V_141 ;
int V_38 ;
V_141 = F_80 ( V_195 , V_196 ) ;
if ( ! V_141 )
return F_81 ( - V_68 ) ;
V_187 . V_179 = V_179 ;
V_187 . V_180 = V_141 ;
V_187 . V_149 = V_132 ;
V_187 . V_181 = 0 ;
V_38 = F_67 ( V_87 , 0 , & V_187 ) ;
if ( V_38 ) {
F_82 ( V_141 ) ;
return F_81 ( V_38 ) ;
}
return V_141 ;
}
static inline int F_83 ( struct V_113 * V_113 , struct V_140 * V_141 ,
T_3 V_197 , unsigned int V_198 )
{
struct V_186 * V_199 = F_84 ( V_113 -> V_133 . V_199 ) ;
if ( V_199 )
return F_85 ( V_199 , V_141 , V_197 , V_198 , V_196 ) ;
else
return - 1 ;
}
static inline T_4 F_86 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_200 ) )
+ F_88 ( sizeof( struct V_201 ) )
+ F_88 ( sizeof( struct V_202 ) )
+ F_88 ( sizeof( struct V_202 ) ) ;
}
static int F_89 ( struct V_140 * V_141 , struct V_113 * V_113 ,
T_3 V_150 , T_3 V_132 , T_3 V_28 )
{
struct V_203 V_204 ;
struct V_200 V_205 ;
struct V_201 V_206 ;
struct V_202 V_207 , V_208 ;
struct V_142 * V_143 ;
int V_38 ;
T_3 * V_209 ;
unsigned V_210 ;
V_143 = F_68 ( V_141 , V_150 , V_132 , V_211 , sizeof( T_3 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_209 = F_42 ( V_143 ) ;
* V_209 = V_28 ;
F_90 ( V_113 , & V_204 ) ;
V_205 . V_212 = V_204 . V_212 ;
V_205 . V_213 = V_204 . V_213 ;
V_205 . V_214 = V_204 . V_214 ;
V_205 . V_215 = V_204 . V_215 ;
V_205 . V_216 = V_204 . V_216 ;
V_205 . V_217 = V_204 . V_217 ;
V_206 . V_218 = V_204 . V_218 ;
V_206 . V_219 = V_204 . V_219 ;
do {
V_210 = F_91 ( & V_113 -> V_133 . V_220 . V_221 ) ;
V_207 . V_222 = V_113 -> V_133 . V_220 . V_223 ;
V_207 . V_224 = V_113 -> V_133 . V_220 . V_225 ;
V_208 . V_222 = V_113 -> V_133 . V_220 . V_226 ;
V_208 . V_224 = V_113 -> V_133 . V_220 . V_227 ;
} while ( F_92 ( & V_113 -> V_133 . V_220 . V_221 , V_210 ) );
V_38 = F_64 ( V_141 , V_228 , sizeof( V_205 ) , & V_205 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_141 , V_229 , sizeof( V_206 ) , & V_206 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_141 , V_230 , sizeof( V_207 ) , & V_207 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_141 , V_231 , sizeof( V_208 ) , & V_208 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
return F_71 ( V_141 , V_143 ) ;
}
static int F_93 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_202 * V_232 = NULL ;
struct V_202 * V_233 = NULL ;
if ( V_2 [ V_230 ] ) {
struct V_1 * V_59 = V_2 [ V_230 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_232 ) )
return - V_7 ;
V_232 = F_2 ( V_59 ) ;
if ( V_232 -> V_222 > 32 || V_232 -> V_224 > 32 )
return - V_7 ;
}
if ( V_2 [ V_231 ] ) {
struct V_1 * V_59 = V_2 [ V_231 ] ;
if ( F_3 ( V_59 ) < sizeof( * V_233 ) )
return - V_7 ;
V_233 = F_2 ( V_59 ) ;
if ( V_233 -> V_222 > 128 || V_233 -> V_224 > 128 )
return - V_7 ;
}
if ( V_232 || V_233 ) {
F_94 ( & V_113 -> V_133 . V_220 . V_221 ) ;
if ( V_232 ) {
V_113 -> V_133 . V_220 . V_223 = V_232 -> V_222 ;
V_113 -> V_133 . V_220 . V_225 = V_232 -> V_224 ;
}
if ( V_233 ) {
V_113 -> V_133 . V_220 . V_226 = V_233 -> V_222 ;
V_113 -> V_133 . V_220 . V_227 = V_233 -> V_224 ;
}
F_95 ( & V_113 -> V_133 . V_220 . V_221 ) ;
F_96 ( V_113 ) ;
}
return 0 ;
}
static int F_97 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_140 * V_234 ;
T_3 * V_28 = F_42 ( V_143 ) ;
T_3 V_235 = F_69 ( V_141 ) . V_150 ;
T_3 V_132 = V_143 -> V_149 ;
V_234 = F_80 ( F_86 () , V_196 ) ;
if ( V_234 == NULL )
return - V_68 ;
if ( F_89 ( V_234 , V_113 , V_235 , V_132 , * V_28 ) < 0 )
F_98 () ;
return F_99 ( V_113 -> V_133 . V_199 , V_234 , V_235 ) ;
}
static inline T_4 F_100 ( void )
{
return F_87 ( 4 )
+ F_88 ( sizeof( struct V_236 ) )
+ F_88 ( 4 ) ;
}
static int F_101 ( struct V_140 * V_141 , struct V_113 * V_113 ,
T_3 V_150 , T_3 V_132 , T_3 V_28 )
{
struct V_237 V_204 ;
struct V_236 V_238 ;
struct V_142 * V_143 ;
int V_38 ;
T_3 * V_209 ;
V_143 = F_68 ( V_141 , V_150 , V_132 , V_239 , sizeof( T_3 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_209 = F_42 ( V_143 ) ;
* V_209 = V_28 ;
F_102 ( V_113 , & V_204 ) ;
V_238 . V_240 = V_204 . V_240 ;
V_238 . V_241 = V_204 . V_241 ;
V_38 = F_63 ( V_141 , V_242 , V_204 . V_243 ) ;
if ( ! V_38 )
V_38 = F_64 ( V_141 , V_244 , sizeof( V_238 ) , & V_238 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
return F_71 ( V_141 , V_143 ) ;
}
static int F_103 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_140 * V_234 ;
T_3 * V_28 = F_42 ( V_143 ) ;
T_3 V_235 = F_69 ( V_141 ) . V_150 ;
T_3 V_132 = V_143 -> V_149 ;
V_234 = F_80 ( F_100 () , V_196 ) ;
if ( V_234 == NULL )
return - V_68 ;
if ( F_101 ( V_234 , V_113 , V_235 , V_132 , * V_28 ) < 0 )
F_98 () ;
return F_99 ( V_113 -> V_133 . V_199 , V_234 , V_235 ) ;
}
static int F_104 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_153 * V_24 = F_42 ( V_143 ) ;
struct V_86 * V_87 ;
struct V_140 * V_245 ;
int V_38 = - V_157 ;
V_87 = F_49 ( V_113 , V_24 , V_2 , & V_38 ) ;
if ( V_87 == NULL )
goto V_246;
V_245 = F_79 ( V_141 , V_87 , V_143 -> V_149 ) ;
if ( F_105 ( V_245 ) ) {
V_38 = F_106 ( V_245 ) ;
} else {
V_38 = F_99 ( V_113 -> V_133 . V_199 , V_245 , F_69 ( V_141 ) . V_150 ) ;
}
F_39 ( V_87 ) ;
V_246:
return V_38 ;
}
static int F_107 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_86 * V_87 ;
struct V_247 * V_24 ;
struct V_140 * V_245 ;
T_1 * V_158 ;
int V_39 ;
int V_38 ;
T_3 V_130 ;
struct V_154 V_155 ;
V_24 = F_42 ( V_143 ) ;
V_38 = F_108 ( V_24 -> V_187 . V_33 . V_34 , V_24 -> V_248 , V_24 -> V_249 ) ;
if ( V_38 )
goto V_246;
V_39 = V_24 -> V_187 . V_39 ;
V_158 = & V_24 -> V_187 . V_33 . V_158 ;
V_87 = NULL ;
V_130 = F_35 ( V_2 , & V_155 ) ;
if ( V_24 -> V_187 . V_132 ) {
V_87 = F_109 ( V_113 , V_130 , V_24 -> V_187 . V_132 ) ;
if ( V_87 && ! F_110 ( & V_87 -> V_33 . V_158 , V_158 , V_39 ) ) {
F_39 ( V_87 ) ;
V_87 = NULL ;
}
}
if ( ! V_87 )
V_87 = F_111 ( V_113 , & V_155 , V_24 -> V_187 . V_46 , V_24 -> V_187 . V_90 ,
V_24 -> V_187 . V_33 . V_34 , V_158 ,
& V_24 -> V_187 . V_91 , 1 ,
V_39 ) ;
V_38 = - V_250 ;
if ( V_87 == NULL )
goto V_246;
V_38 = F_112 ( V_87 , V_24 -> V_248 , V_24 -> V_249 ) ;
if ( V_38 )
goto V_44;
V_245 = F_79 ( V_141 , V_87 , V_143 -> V_149 ) ;
if ( F_105 ( V_245 ) ) {
V_38 = F_106 ( V_245 ) ;
goto V_44;
}
V_38 = F_99 ( V_113 -> V_133 . V_199 , V_245 , F_69 ( V_141 ) . V_150 ) ;
V_44:
F_39 ( V_87 ) ;
V_246:
return V_38 ;
}
static int F_113 ( T_2 V_251 )
{
switch ( V_251 ) {
case V_252 :
case V_253 :
case V_254 :
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_114 ( T_2 type )
{
switch ( type ) {
case V_255 :
#ifdef F_115
case V_256 :
#endif
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_116 ( struct V_257 * V_24 )
{
int V_171 ;
switch ( V_24 -> V_258 ) {
case V_259 :
case V_260 :
case V_261 :
case V_262 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_263 ) {
case V_264 :
case V_265 :
break;
default:
return - V_7 ;
}
switch ( V_24 -> V_88 . V_39 ) {
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
V_171 = F_113 ( V_24 -> V_251 ) ;
if ( V_171 )
return V_171 ;
if ( V_24 -> V_266 && ( ( V_24 -> V_266 & V_267 ) != V_24 -> V_251 ) )
return - V_7 ;
return 0 ;
}
static int F_117 ( struct V_268 * V_269 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_19 * V_20 ;
if ( ! V_4 )
return 0 ;
V_20 = F_2 ( V_4 ) ;
return F_118 ( & V_269 -> V_174 , V_20 , V_67 ) ;
}
static void F_119 ( struct V_268 * V_270 , struct V_271 * V_272 ,
int V_273 )
{
int V_274 ;
V_270 -> V_275 = V_273 ;
for ( V_274 = 0 ; V_274 < V_273 ; V_274 ++ , V_272 ++ ) {
struct V_276 * V_277 = & V_270 -> V_278 [ V_274 ] ;
memcpy ( & V_277 -> V_33 , & V_272 -> V_33 , sizeof( struct V_279 ) ) ;
memcpy ( & V_277 -> V_91 , & V_272 -> V_91 ,
sizeof( T_1 ) ) ;
V_277 -> V_90 = V_272 -> V_90 ;
V_277 -> V_46 = V_272 -> V_46 ;
V_277 -> V_258 = V_272 -> V_258 ;
V_277 -> V_280 = V_272 -> V_280 ;
V_277 -> V_281 = V_272 -> V_281 ;
V_277 -> V_282 = V_272 -> V_282 ;
V_277 -> V_283 = V_272 -> V_283 ;
V_277 -> V_284 = ! ~ ( V_277 -> V_281 & V_277 -> V_282 & V_277 -> V_283 ) ;
V_277 -> V_285 = V_272 -> V_39 ;
}
}
static int F_120 ( int V_273 , struct V_271 * V_272 , T_5 V_39 )
{
int V_274 ;
if ( V_273 > V_286 )
return - V_7 ;
for ( V_274 = 0 ; V_274 < V_273 ; V_274 ++ ) {
if ( ! V_272 [ V_274 ] . V_39 )
V_272 [ V_274 ] . V_39 = V_39 ;
switch ( V_272 [ V_274 ] . V_39 ) {
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
static int F_121 ( struct V_268 * V_269 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_287 ] ;
if ( ! V_4 ) {
V_269 -> V_275 = 0 ;
} else {
struct V_271 * V_288 = F_2 ( V_4 ) ;
int V_273 = F_3 ( V_4 ) / sizeof( * V_288 ) ;
int V_38 ;
V_38 = F_120 ( V_273 , V_288 , V_269 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_119 ( V_269 , V_288 , V_273 ) ;
}
return 0 ;
}
static int F_122 ( T_2 * V_289 , struct V_1 * * V_2 )
{
struct V_1 * V_4 = V_2 [ V_290 ] ;
struct V_291 * V_292 ;
T_2 type = V_255 ;
int V_38 ;
if ( V_4 ) {
V_292 = F_2 ( V_4 ) ;
type = V_292 -> type ;
}
V_38 = F_114 ( type ) ;
if ( V_38 )
return V_38 ;
* V_289 = type ;
return 0 ;
}
static void F_123 ( struct V_268 * V_270 , struct V_257 * V_24 )
{
V_270 -> V_293 = V_24 -> V_293 ;
V_270 -> V_266 = V_24 -> V_266 ;
memcpy ( & V_270 -> V_294 , & V_24 -> V_88 , sizeof( V_270 -> V_294 ) ) ;
memcpy ( & V_270 -> V_89 , & V_24 -> V_89 , sizeof( V_270 -> V_89 ) ) ;
V_270 -> V_263 = V_24 -> V_263 ;
V_270 -> V_28 = V_24 -> V_28 ;
V_270 -> V_39 = V_24 -> V_88 . V_39 ;
}
static void F_124 ( struct V_268 * V_270 , struct V_257 * V_24 , int V_251 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
memcpy ( & V_24 -> V_88 , & V_270 -> V_294 , sizeof( V_24 -> V_88 ) ) ;
memcpy ( & V_24 -> V_89 , & V_270 -> V_89 , sizeof( V_24 -> V_89 ) ) ;
memcpy ( & V_24 -> V_106 , & V_270 -> V_106 , sizeof( V_24 -> V_106 ) ) ;
V_24 -> V_293 = V_270 -> V_293 ;
V_24 -> V_266 = V_270 -> V_266 ;
V_24 -> V_88 . V_39 = V_270 -> V_39 ;
V_24 -> V_251 = V_251 ;
V_24 -> V_263 = V_270 -> V_263 ;
V_24 -> V_28 = V_270 -> V_28 ;
V_24 -> V_258 = V_259 ;
}
static struct V_268 * F_125 ( struct V_113 * V_113 , struct V_257 * V_24 , struct V_1 * * V_2 , int * V_114 )
{
struct V_268 * V_270 = F_126 ( V_113 , V_67 ) ;
int V_38 ;
if ( ! V_270 ) {
* V_114 = - V_68 ;
return NULL ;
}
F_123 ( V_270 , V_24 ) ;
V_38 = F_122 ( & V_270 -> type , V_2 ) ;
if ( V_38 )
goto error;
if ( ! ( V_38 = F_121 ( V_270 , V_2 ) ) )
V_38 = F_117 ( V_270 , V_2 ) ;
if ( V_38 )
goto error;
F_35 ( V_2 , & V_270 -> V_130 ) ;
return V_270 ;
error:
* V_114 = V_38 ;
V_270 -> V_185 . V_295 = 1 ;
F_127 ( V_270 ) ;
return NULL ;
}
static int F_128 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_257 * V_24 = F_42 ( V_143 ) ;
struct V_268 * V_270 ;
struct V_145 V_146 ;
int V_38 ;
int V_296 ;
V_38 = F_116 ( V_24 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_270 = F_125 ( V_113 , V_24 , V_2 , & V_38 ) ;
if ( ! V_270 )
return V_38 ;
V_296 = V_143 -> V_147 == V_297 ;
V_38 = F_129 ( V_24 -> V_251 , V_270 , V_296 ) ;
F_130 ( V_270 , V_38 ? 0 : 1 , true ) ;
if ( V_38 ) {
F_131 ( V_270 -> V_174 ) ;
F_26 ( V_270 ) ;
return V_38 ;
}
V_146 . V_152 = V_143 -> V_147 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
F_132 ( V_270 , V_24 -> V_251 , & V_146 ) ;
F_133 ( V_270 ) ;
return 0 ;
}
static int F_134 ( struct V_268 * V_270 , struct V_140 * V_141 )
{
struct V_271 V_298 [ V_286 ] ;
int V_274 ;
if ( V_270 -> V_275 == 0 )
return 0 ;
for ( V_274 = 0 ; V_274 < V_270 -> V_275 ; V_274 ++ ) {
struct V_271 * V_79 = & V_298 [ V_274 ] ;
struct V_276 * V_299 = & V_270 -> V_278 [ V_274 ] ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
memcpy ( & V_79 -> V_33 , & V_299 -> V_33 , sizeof( V_79 -> V_33 ) ) ;
V_79 -> V_39 = V_299 -> V_285 ;
memcpy ( & V_79 -> V_91 , & V_299 -> V_91 , sizeof( V_79 -> V_91 ) ) ;
V_79 -> V_90 = V_299 -> V_90 ;
V_79 -> V_46 = V_299 -> V_46 ;
V_79 -> V_258 = V_299 -> V_258 ;
V_79 -> V_280 = V_299 -> V_280 ;
V_79 -> V_281 = V_299 -> V_281 ;
V_79 -> V_282 = V_299 -> V_282 ;
V_79 -> V_283 = V_299 -> V_283 ;
}
return F_64 ( V_141 , V_287 ,
sizeof( struct V_271 ) * V_270 -> V_275 , V_298 ) ;
}
static inline int F_135 ( struct V_86 * V_87 , struct V_140 * V_141 )
{
if ( V_87 -> V_174 ) {
return F_59 ( V_87 -> V_174 , V_141 ) ;
}
return 0 ;
}
static inline int F_136 ( struct V_268 * V_270 , struct V_140 * V_141 )
{
if ( V_270 -> V_174 )
return F_59 ( V_270 -> V_174 , V_141 ) ;
return 0 ;
}
static inline T_4 F_137 ( void )
{
#ifdef F_115
return F_88 ( sizeof( struct V_291 ) ) ;
#else
return 0 ;
#endif
}
static int F_138 ( T_2 type , struct V_140 * V_141 )
{
struct V_291 V_292 = {
. type = type ,
} ;
return F_64 ( V_141 , V_290 , sizeof( V_292 ) , & V_292 ) ;
}
static inline int F_138 ( T_2 type , struct V_140 * V_141 )
{
return 0 ;
}
static int F_139 ( struct V_268 * V_270 , int V_251 , int V_175 , void * V_176 )
{
struct V_177 * V_178 = V_176 ;
struct V_257 * V_24 ;
struct V_140 * V_179 = V_178 -> V_179 ;
struct V_140 * V_141 = V_178 -> V_180 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , F_69 ( V_179 ) . V_150 , V_178 -> V_149 ,
V_297 , sizeof( * V_24 ) , V_178 -> V_181 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_24 = F_42 ( V_143 ) ;
F_124 ( V_270 , V_24 , V_251 ) ;
V_38 = F_134 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_136 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_270 -> type , V_141 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_141 , & V_270 -> V_130 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
F_71 ( V_141 , V_143 ) ;
return 0 ;
}
static int F_140 ( struct V_182 * V_183 )
{
struct V_300 * V_185 = (struct V_300 * ) & V_183 -> args [ 1 ] ;
struct V_113 * V_113 = F_41 ( V_183 -> V_141 -> V_144 ) ;
F_141 ( V_185 , V_113 ) ;
return 0 ;
}
static int F_142 ( struct V_140 * V_141 , struct V_182 * V_183 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_300 * V_185 = (struct V_300 * ) & V_183 -> args [ 1 ] ;
struct V_177 V_187 ;
F_75 ( sizeof( struct V_300 ) >
sizeof( V_183 -> args ) - sizeof( V_183 -> args [ 0 ] ) ) ;
V_187 . V_179 = V_183 -> V_141 ;
V_187 . V_180 = V_141 ;
V_187 . V_149 = V_183 -> V_143 -> V_149 ;
V_187 . V_181 = V_188 ;
if ( ! V_183 -> args [ 0 ] ) {
V_183 -> args [ 0 ] = 1 ;
F_143 ( V_185 , V_301 ) ;
}
( void ) V_300 ( V_113 , V_185 , F_139 , & V_187 ) ;
return V_141 -> V_21 ;
}
static struct V_140 * F_144 ( struct V_140 * V_179 ,
struct V_268 * V_270 ,
int V_251 , T_3 V_132 )
{
struct V_177 V_187 ;
struct V_140 * V_141 ;
int V_38 ;
V_141 = F_80 ( V_195 , V_67 ) ;
if ( ! V_141 )
return F_81 ( - V_68 ) ;
V_187 . V_179 = V_179 ;
V_187 . V_180 = V_141 ;
V_187 . V_149 = V_132 ;
V_187 . V_181 = 0 ;
V_38 = F_139 ( V_270 , V_251 , 0 , & V_187 ) ;
if ( V_38 ) {
F_82 ( V_141 ) ;
return F_81 ( V_38 ) ;
}
return V_141 ;
}
static int F_145 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_268 * V_270 ;
struct V_302 * V_24 ;
T_2 type = V_255 ;
int V_38 ;
struct V_145 V_146 ;
int V_303 ;
struct V_154 V_155 ;
T_3 V_130 = F_35 ( V_2 , & V_155 ) ;
V_24 = F_42 ( V_143 ) ;
V_303 = V_143 -> V_147 == V_304 ;
V_38 = F_122 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_113 ( V_24 -> V_251 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_266 )
V_270 = F_146 ( V_113 , V_130 , type , V_24 -> V_251 , V_24 -> V_266 , V_303 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_84 * V_305 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_305 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_118 ( & V_305 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_270 = F_147 ( V_113 , V_130 , type , V_24 -> V_251 , & V_24 -> V_88 ,
V_305 , V_303 , & V_38 ) ;
F_131 ( V_305 ) ;
}
if ( V_270 == NULL )
return - V_250 ;
if ( ! V_303 ) {
struct V_140 * V_245 ;
V_245 = F_144 ( V_141 , V_270 , V_24 -> V_251 , V_143 -> V_149 ) ;
if ( F_105 ( V_245 ) ) {
V_38 = F_106 ( V_245 ) ;
} else {
V_38 = F_99 ( V_113 -> V_133 . V_199 , V_245 ,
F_69 ( V_141 ) . V_150 ) ;
}
} else {
F_148 ( V_270 , V_38 ? 0 : 1 , true ) ;
if ( V_38 != 0 )
goto V_44;
V_146 . V_306 . V_307 = V_24 -> V_266 ;
V_146 . V_152 = V_143 -> V_147 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
F_132 ( V_270 , V_24 -> V_251 , & V_146 ) ;
}
V_44:
F_133 ( V_270 ) ;
if ( V_303 && V_38 == 0 )
F_149 ( V_113 ) ;
return V_38 ;
}
static int F_150 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_145 V_146 ;
struct V_308 * V_24 = F_42 ( V_143 ) ;
int V_38 ;
V_38 = F_151 ( V_113 , V_24 -> V_34 , true ) ;
if ( V_38 ) {
if ( V_38 == - V_157 )
return 0 ;
return V_38 ;
}
V_146 . V_306 . V_34 = V_24 -> V_34 ;
V_146 . V_152 = V_143 -> V_147 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
V_146 . V_113 = V_113 ;
F_48 ( NULL , & V_146 ) ;
return 0 ;
}
static inline T_4 F_152 ( struct V_86 * V_87 )
{
T_4 V_309 = V_87 -> V_77 ?
F_12 ( V_87 -> V_77 ) :
sizeof( struct V_101 ) ;
return F_87 ( sizeof( struct V_310 ) )
+ F_88 ( V_309 )
+ F_88 ( sizeof( struct V_104 ) )
+ F_88 ( sizeof( struct V_154 ) )
+ F_88 ( 4 )
+ F_88 ( 4 ) ;
}
static int F_153 ( struct V_140 * V_141 , struct V_86 * V_87 , const struct V_145 * V_146 )
{
struct V_310 * V_33 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , V_146 -> V_132 , V_311 , sizeof( * V_33 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_33 = F_42 ( V_143 ) ;
memcpy ( & V_33 -> V_312 . V_158 , & V_87 -> V_33 . V_158 , sizeof( V_87 -> V_33 . V_158 ) ) ;
V_33 -> V_312 . V_49 = V_87 -> V_33 . V_49 ;
V_33 -> V_312 . V_39 = V_87 -> V_58 . V_39 ;
V_33 -> V_312 . V_34 = V_87 -> V_33 . V_34 ;
memcpy ( & V_33 -> V_91 , & V_87 -> V_58 . V_91 , sizeof( V_87 -> V_58 . V_91 ) ) ;
V_33 -> V_90 = V_87 -> V_58 . V_90 ;
V_33 -> V_28 = V_146 -> V_306 . V_313 ;
if ( V_87 -> V_77 ) {
V_38 = F_64 ( V_141 , V_25 ,
F_12 ( V_87 -> V_77 ) ,
V_87 -> V_77 ) ;
} else {
V_38 = F_64 ( V_141 , V_94 , sizeof( V_87 -> V_102 ) ,
& V_87 -> V_102 ) ;
}
if ( V_38 )
goto V_314;
V_38 = F_64 ( V_141 , V_97 , sizeof( V_87 -> V_106 ) , & V_87 -> V_106 ) ;
if ( V_38 )
goto V_314;
if ( V_33 -> V_28 & V_315 ) {
V_38 = F_63 ( V_141 , V_100 , V_87 -> V_112 ) ;
if ( V_38 )
goto V_314;
}
if ( V_33 -> V_28 & V_316 ) {
V_38 = F_63 ( V_141 , V_99 ,
V_87 -> V_111 * 10 / V_136 ) ;
if ( V_38 )
goto V_314;
}
V_38 = F_66 ( V_141 , & V_87 -> V_130 ) ;
if ( V_38 )
goto V_314;
return F_71 ( V_141 , V_143 ) ;
V_314:
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
static int F_154 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_86 * V_87 ;
struct V_140 * V_234 ;
int V_38 ;
struct V_145 V_146 ;
T_3 V_130 ;
struct V_154 V_155 ;
struct V_310 * V_24 = F_42 ( V_143 ) ;
struct V_153 * V_33 = & V_24 -> V_312 ;
V_130 = F_35 ( V_2 , & V_155 ) ;
V_87 = F_51 ( V_113 , V_130 , & V_33 -> V_158 , V_33 -> V_49 , V_33 -> V_34 , V_33 -> V_39 ) ;
if ( V_87 == NULL )
return - V_157 ;
V_234 = F_80 ( F_152 ( V_87 ) , V_196 ) ;
if ( V_234 == NULL ) {
F_39 ( V_87 ) ;
return - V_68 ;
}
F_155 ( & V_87 -> V_221 ) ;
V_146 . V_306 . V_313 = V_24 -> V_28 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
if ( F_153 ( V_234 , V_87 , & V_146 ) < 0 )
F_98 () ;
V_38 = F_99 ( V_113 -> V_133 . V_199 , V_234 , F_69 ( V_141 ) . V_150 ) ;
F_156 ( & V_87 -> V_221 ) ;
F_39 ( V_87 ) ;
return V_38 ;
}
static int F_157 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_86 * V_87 ;
struct V_145 V_146 ;
int V_38 = - V_7 ;
T_3 V_130 = 0 ;
struct V_154 V_155 ;
struct V_310 * V_24 = F_42 ( V_143 ) ;
struct V_1 * V_78 = V_2 [ V_94 ] ;
struct V_1 * V_95 = V_2 [ V_25 ] ;
struct V_1 * V_96 = V_2 [ V_97 ] ;
if ( ! V_96 && ! V_78 && ! V_95 )
return V_38 ;
if ( ! ( V_143 -> V_181 & V_317 ) )
return V_38 ;
V_130 = F_35 ( V_2 , & V_155 ) ;
V_87 = F_51 ( V_113 , V_130 , & V_24 -> V_312 . V_158 , V_24 -> V_312 . V_49 , V_24 -> V_312 . V_34 , V_24 -> V_312 . V_39 ) ;
if ( V_87 == NULL )
return - V_157 ;
if ( V_87 -> V_131 . V_138 != V_318 )
goto V_44;
V_38 = F_23 ( V_87 -> V_77 , V_95 ) ;
if ( V_38 )
goto V_44;
F_155 ( & V_87 -> V_221 ) ;
F_30 ( V_87 , V_2 , 1 ) ;
F_156 ( & V_87 -> V_221 ) ;
V_146 . V_152 = V_143 -> V_147 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
V_146 . V_306 . V_313 = V_319 ;
F_48 ( V_87 , & V_146 ) ;
V_38 = 0 ;
V_44:
F_39 ( V_87 ) ;
return V_38 ;
}
static int F_158 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_145 V_146 ;
T_2 type = V_255 ;
int V_38 ;
V_38 = F_122 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_159 ( V_113 , type , true ) ;
if ( V_38 ) {
if ( V_38 == - V_157 )
return 0 ;
return V_38 ;
}
V_146 . V_306 . type = type ;
V_146 . V_152 = V_143 -> V_147 ;
V_146 . V_132 = V_143 -> V_149 ;
V_146 . V_150 = V_143 -> V_151 ;
V_146 . V_113 = V_113 ;
F_132 ( NULL , 0 , & V_146 ) ;
return 0 ;
}
static int F_160 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_268 * V_270 ;
struct V_320 * V_79 = F_42 ( V_143 ) ;
struct V_257 * V_24 = & V_79 -> V_269 ;
T_2 type = V_255 ;
int V_38 = - V_250 ;
struct V_154 V_155 ;
T_3 V_130 = F_35 ( V_2 , & V_155 ) ;
V_38 = F_122 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_113 ( V_24 -> V_251 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_266 )
V_270 = F_146 ( V_113 , V_130 , type , V_24 -> V_251 , V_24 -> V_266 , 0 , & V_38 ) ;
else {
struct V_1 * V_4 = V_2 [ V_18 ] ;
struct V_84 * V_305 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_305 = NULL ;
if ( V_4 ) {
struct V_19 * V_20 = F_2 ( V_4 ) ;
V_38 = F_118 ( & V_305 , V_20 , V_67 ) ;
if ( V_38 )
return V_38 ;
}
V_270 = F_147 ( V_113 , V_130 , type , V_24 -> V_251 ,
& V_24 -> V_88 , V_305 , 0 , & V_38 ) ;
F_131 ( V_305 ) ;
}
if ( V_270 == NULL )
return - V_250 ;
if ( F_161 ( V_270 -> V_185 . V_295 ) )
goto V_44;
V_38 = 0 ;
if ( V_79 -> V_321 ) {
F_162 ( V_270 , V_24 -> V_251 ) ;
F_148 ( V_270 , 1 , true ) ;
} else {
F_163 ( 1 , L_1 ) ;
}
F_164 ( V_270 , V_24 -> V_251 , V_79 -> V_321 , V_143 -> V_151 ) ;
V_44:
F_133 ( V_270 ) ;
return V_38 ;
}
static int F_165 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_86 * V_87 ;
int V_38 ;
struct V_322 * V_323 = F_42 ( V_143 ) ;
struct V_23 * V_24 = & V_323 -> V_138 ;
struct V_154 V_155 ;
T_3 V_130 = F_35 ( V_2 , & V_155 ) ;
V_87 = F_51 ( V_113 , V_130 , & V_24 -> V_33 . V_158 , V_24 -> V_33 . V_49 , V_24 -> V_33 . V_34 , V_24 -> V_39 ) ;
V_38 = - V_250 ;
if ( V_87 == NULL )
return V_38 ;
F_155 ( & V_87 -> V_221 ) ;
V_38 = - V_7 ;
if ( V_87 -> V_131 . V_138 != V_318 )
goto V_44;
F_166 ( V_87 , V_323 -> V_321 , V_143 -> V_151 ) ;
if ( V_323 -> V_321 ) {
F_167 ( V_87 ) ;
F_57 ( V_87 , 1 , true ) ;
}
V_38 = 0 ;
V_44:
F_156 ( & V_87 -> V_221 ) ;
F_39 ( V_87 ) ;
return V_38 ;
}
static int F_168 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_268 * V_270 ;
struct V_271 * V_272 ;
int V_274 ;
struct V_1 * V_4 = V_2 [ V_287 ] ;
struct V_154 V_130 ;
struct V_324 * V_325 = F_42 ( V_143 ) ;
struct V_86 * V_87 = F_33 ( V_113 ) ;
int V_38 = - V_68 ;
if ( ! V_87 )
goto V_326;
F_35 ( V_2 , & V_130 ) ;
V_38 = F_116 ( & V_325 -> V_327 ) ;
if ( V_38 )
goto V_328;
V_270 = F_125 ( V_113 , & V_325 -> V_327 , V_2 , & V_38 ) ;
if ( ! V_270 )
goto V_329;
memcpy ( & V_87 -> V_33 , & V_325 -> V_33 , sizeof( V_325 -> V_33 ) ) ;
memcpy ( & V_87 -> V_58 . V_91 , & V_325 -> V_91 , sizeof( V_325 -> V_91 ) ) ;
memcpy ( & V_87 -> V_88 , & V_325 -> V_88 , sizeof( V_325 -> V_88 ) ) ;
V_270 -> V_130 . V_155 = V_87 -> V_130 . V_155 = V_130 . V_155 ;
V_270 -> V_130 . V_330 = V_87 -> V_130 . V_330 = V_130 . V_330 ;
V_272 = F_2 ( V_4 ) ;
for ( V_274 = 0 ; V_274 < V_270 -> V_275 ; V_274 ++ , V_272 ++ ) {
struct V_276 * V_277 = & V_270 -> V_278 [ V_274 ] ;
memcpy ( & V_87 -> V_33 , & V_277 -> V_33 , sizeof( V_87 -> V_33 ) ) ;
V_87 -> V_58 . V_46 = V_277 -> V_46 ;
V_87 -> V_58 . V_90 = V_277 -> V_90 ;
V_87 -> V_58 . V_39 = V_272 -> V_39 ;
V_277 -> V_281 = V_325 -> V_281 ;
V_277 -> V_282 = V_325 -> V_282 ;
V_277 -> V_283 = V_325 -> V_283 ;
V_38 = F_169 ( V_87 , V_277 , V_270 ) ;
}
F_26 ( V_87 ) ;
F_26 ( V_270 ) ;
return 0 ;
V_328:
F_163 ( 1 , L_2 ) ;
V_329:
F_26 ( V_87 ) ;
V_326:
return V_38 ;
}
static int F_170 ( struct V_331 * V_332 ,
struct V_333 * V_334 ,
struct V_1 * * V_2 , int * V_335 )
{
struct V_1 * V_4 = V_2 [ V_336 ] ;
struct V_337 * V_338 ;
int V_274 , V_339 ;
if ( V_334 != NULL ) {
struct V_340 * V_341 ;
V_341 = F_2 ( V_2 [ V_342 ] ) ;
memcpy ( & V_334 -> V_343 , & V_341 -> V_343 , sizeof( V_334 -> V_343 ) ) ;
memcpy ( & V_334 -> V_344 , & V_341 -> V_344 , sizeof( V_334 -> V_344 ) ) ;
V_334 -> V_39 = V_341 -> V_39 ;
V_334 -> V_345 = V_341 -> V_345 ;
}
V_338 = F_2 ( V_4 ) ;
V_339 = F_3 ( V_4 ) / sizeof( * V_338 ) ;
if ( V_339 <= 0 || V_339 > V_286 )
return - V_7 ;
for ( V_274 = 0 ; V_274 < V_339 ; V_274 ++ , V_338 ++ , V_332 ++ ) {
memcpy ( & V_332 -> V_346 , & V_338 -> V_346 , sizeof( V_332 -> V_346 ) ) ;
memcpy ( & V_332 -> V_347 , & V_338 -> V_347 , sizeof( V_332 -> V_347 ) ) ;
memcpy ( & V_332 -> V_348 , & V_338 -> V_348 , sizeof( V_332 -> V_348 ) ) ;
memcpy ( & V_332 -> V_349 , & V_338 -> V_349 , sizeof( V_332 -> V_349 ) ) ;
V_332 -> V_34 = V_338 -> V_34 ;
V_332 -> V_46 = V_338 -> V_46 ;
V_332 -> V_90 = V_338 -> V_90 ;
V_332 -> V_350 = V_338 -> V_350 ;
V_332 -> V_351 = V_338 -> V_351 ;
}
* V_335 = V_274 ;
return 0 ;
}
static int F_171 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
struct V_302 * V_352 = F_42 ( V_143 ) ;
struct V_331 V_155 [ V_286 ] ;
struct V_333 V_131 , * V_353 ;
T_2 type ;
int V_38 ;
int V_354 = 0 ;
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
if ( V_2 [ V_336 ] == NULL )
return - V_7 ;
V_353 = V_2 [ V_342 ] ? & V_131 : NULL ;
V_38 = F_122 ( & type , V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_170 ( (struct V_331 * ) V_155 , V_353 , V_2 , & V_354 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_354 )
return 0 ;
V_331 ( & V_352 -> V_88 , V_352 -> V_251 , type , V_155 , V_354 , V_353 , V_113 ) ;
return 0 ;
}
static int F_171 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_1 * * V_2 )
{
return - V_355 ;
}
static int F_172 ( const struct V_331 * V_155 , struct V_140 * V_141 )
{
struct V_337 V_338 ;
memset ( & V_338 , 0 , sizeof( V_338 ) ) ;
V_338 . V_34 = V_155 -> V_34 ;
V_338 . V_46 = V_155 -> V_46 ;
V_338 . V_90 = V_155 -> V_90 ;
V_338 . V_350 = V_155 -> V_350 ;
memcpy ( & V_338 . V_346 , & V_155 -> V_346 , sizeof( V_338 . V_346 ) ) ;
memcpy ( & V_338 . V_347 , & V_155 -> V_347 , sizeof( V_338 . V_347 ) ) ;
V_338 . V_351 = V_155 -> V_351 ;
memcpy ( & V_338 . V_348 , & V_155 -> V_348 , sizeof( V_338 . V_348 ) ) ;
memcpy ( & V_338 . V_349 , & V_155 -> V_349 , sizeof( V_338 . V_349 ) ) ;
return F_64 ( V_141 , V_336 , sizeof( V_338 ) , & V_338 ) ;
}
static int F_173 ( const struct V_333 * V_334 , struct V_140 * V_141 )
{
struct V_340 V_341 ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_39 = V_334 -> V_39 ;
V_341 . V_345 = V_334 -> V_345 ;
memcpy ( & V_341 . V_343 , & V_334 -> V_343 , sizeof( V_341 . V_343 ) ) ;
memcpy ( & V_341 . V_344 , & V_334 -> V_344 , sizeof( V_341 . V_344 ) ) ;
return F_64 ( V_141 , V_342 , sizeof( V_341 ) , & V_341 ) ;
}
static inline T_4 F_174 ( int V_339 , int V_356 )
{
return F_87 ( sizeof( struct V_302 ) )
+ ( V_356 ? F_88 ( sizeof( struct V_333 ) ) : 0 )
+ F_88 ( sizeof( struct V_337 ) * V_339 )
+ F_137 () ;
}
static int F_175 ( struct V_140 * V_141 , const struct V_331 * V_155 ,
int V_339 , const struct V_333 * V_334 ,
const struct V_357 * V_88 , T_2 V_251 , T_2 type )
{
const struct V_331 * V_358 ;
struct V_302 * V_359 ;
struct V_142 * V_143 ;
int V_274 , V_38 ;
V_143 = F_68 ( V_141 , 0 , 0 , V_360 , sizeof( * V_359 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_359 = F_42 ( V_143 ) ;
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
memcpy ( & V_359 -> V_88 , V_88 , sizeof( V_359 -> V_88 ) ) ;
V_359 -> V_251 = V_251 ;
if ( V_334 != NULL ) {
V_38 = F_173 ( V_334 , V_141 ) ;
if ( V_38 )
goto V_314;
}
V_38 = F_138 ( type , V_141 ) ;
if ( V_38 )
goto V_314;
for ( V_274 = 0 , V_358 = V_155 ; V_274 < V_339 ; V_274 ++ , V_358 ++ ) {
V_38 = F_172 ( V_358 , V_141 ) ;
if ( V_38 )
goto V_314;
}
return F_71 ( V_141 , V_143 ) ;
V_314:
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
static int F_176 ( const struct V_357 * V_88 , T_2 V_251 , T_2 type ,
const struct V_331 * V_155 , int V_339 ,
const struct V_333 * V_334 )
{
struct V_113 * V_113 = & V_361 ;
struct V_140 * V_141 ;
V_141 = F_80 ( F_174 ( V_339 , ! ! V_334 ) , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_175 ( V_141 , V_155 , V_339 , V_334 , V_88 , V_251 , type ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_362 ) ;
}
static int F_176 ( const struct V_357 * V_88 , T_2 V_251 , T_2 type ,
const struct V_331 * V_155 , int V_339 ,
const struct V_333 * V_334 )
{
return - V_355 ;
}
static int F_177 ( struct V_140 * V_141 , struct V_142 * V_143 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
struct V_1 * V_2 [ V_189 + 1 ] ;
const struct V_363 * V_364 ;
int type , V_38 ;
type = V_143 -> V_147 ;
if ( type > V_365 )
return - V_7 ;
type -= V_366 ;
V_364 = & V_367 [ type ] ;
if ( ! F_178 ( V_141 , V_368 ) )
return - V_160 ;
if ( ( type == ( V_369 - V_366 ) ||
type == ( V_370 - V_366 ) ) &&
( V_143 -> V_181 & V_371 ) ) {
if ( V_364 -> V_372 == NULL )
return - V_7 ;
{
struct V_373 V_146 = {
. V_372 = V_364 -> V_372 ,
. V_374 = V_364 -> V_374 ,
} ;
return F_179 ( V_113 -> V_133 . V_199 , V_141 , V_143 , & V_146 ) ;
}
}
V_38 = F_76 ( V_143 , V_375 [ type ] , V_2 ,
V_364 -> V_376 ? : V_189 ,
V_364 -> V_377 ? : V_192 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_364 -> V_378 == NULL )
return - V_7 ;
return V_364 -> V_378 ( V_141 , V_143 , V_2 ) ;
}
static void F_180 ( struct V_140 * V_141 )
{
struct V_113 * V_113 = F_41 ( V_141 -> V_144 ) ;
F_181 ( & V_113 -> V_133 . V_379 ) ;
F_182 ( V_141 , & F_177 ) ;
F_183 ( & V_113 -> V_133 . V_379 ) ;
}
static inline T_4 F_184 ( void )
{
return F_87 ( sizeof( struct V_322 ) )
+ F_88 ( sizeof( struct V_154 ) ) ;
}
static int F_185 ( struct V_140 * V_141 , struct V_86 * V_87 , const struct V_145 * V_146 )
{
struct V_322 * V_323 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , 0 , V_380 , sizeof( * V_323 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_323 = F_42 ( V_143 ) ;
F_58 ( V_87 , & V_323 -> V_138 ) ;
V_323 -> V_321 = ( V_146 -> V_306 . V_321 != 0 ) ? 1 : 0 ;
V_38 = F_66 ( V_141 , & V_87 -> V_130 ) ;
if ( V_38 )
return V_38 ;
return F_71 ( V_141 , V_143 ) ;
}
static int F_186 ( struct V_86 * V_87 , const struct V_145 * V_146 )
{
struct V_113 * V_113 = F_187 ( V_87 ) ;
struct V_140 * V_141 ;
V_141 = F_80 ( F_184 () , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_185 ( V_141 , V_87 , V_146 ) < 0 ) {
F_82 ( V_141 ) ;
return - V_165 ;
}
return F_83 ( V_113 , V_141 , 0 , V_381 ) ;
}
static int F_188 ( struct V_86 * V_87 , const struct V_145 * V_146 )
{
struct V_113 * V_113 = F_187 ( V_87 ) ;
struct V_140 * V_141 ;
V_141 = F_80 ( F_152 ( V_87 ) , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_153 ( V_141 , V_87 , V_146 ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_382 ) ;
}
static int F_189 ( const struct V_145 * V_146 )
{
struct V_113 * V_113 = V_146 -> V_113 ;
struct V_308 * V_24 ;
struct V_142 * V_143 ;
struct V_140 * V_141 ;
int V_21 = F_87 ( sizeof( struct V_308 ) ) ;
V_141 = F_80 ( V_21 , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , V_146 -> V_132 , V_383 , sizeof( * V_24 ) , 0 ) ;
if ( V_143 == NULL ) {
F_82 ( V_141 ) ;
return - V_165 ;
}
V_24 = F_42 ( V_143 ) ;
V_24 -> V_34 = V_146 -> V_306 . V_34 ;
F_71 ( V_141 , V_143 ) ;
return F_83 ( V_113 , V_141 , 0 , V_384 ) ;
}
static inline T_4 F_190 ( struct V_86 * V_87 )
{
T_4 V_385 = 0 ;
if ( V_87 -> V_118 )
V_385 += F_88 ( F_8 ( V_87 -> V_118 ) ) ;
if ( V_87 -> V_120 ) {
V_385 += F_88 ( sizeof( struct V_5 ) +
( V_87 -> V_120 -> V_66 + 7 ) / 8 ) ;
V_385 += F_88 ( F_6 ( V_87 -> V_120 ) ) ;
}
if ( V_87 -> V_122 )
V_385 += F_88 ( F_4 ( V_87 -> V_122 ) ) ;
if ( V_87 -> V_124 )
V_385 += F_88 ( sizeof( * V_87 -> V_124 ) ) ;
if ( V_87 -> V_127 )
V_385 += F_88 ( sizeof( * V_87 -> V_127 ) ) ;
if ( V_87 -> V_128 )
V_385 += F_88 ( sizeof( V_87 -> V_128 ) ) ;
if ( V_87 -> V_77 )
V_385 += F_88 ( F_12 ( V_87 -> V_77 ) ) ;
if ( V_87 -> V_174 )
V_385 += F_88 ( sizeof( struct V_19 ) +
V_87 -> V_174 -> V_22 ) ;
if ( V_87 -> V_129 )
V_385 += F_88 ( sizeof( * V_87 -> V_129 ) ) ;
if ( V_87 -> V_58 . V_117 )
V_385 += F_88 ( sizeof( V_87 -> V_58 . V_117 ) ) ;
V_385 += F_88 ( sizeof( V_386 ) ) ;
return V_385 ;
}
static int F_191 ( struct V_86 * V_87 , const struct V_145 * V_146 )
{
struct V_113 * V_113 = F_187 ( V_87 ) ;
struct V_23 * V_24 ;
struct V_153 * V_33 ;
struct V_142 * V_143 ;
struct V_140 * V_141 ;
int V_21 = F_190 ( V_87 ) ;
int V_387 , V_38 ;
V_387 = sizeof( * V_24 ) ;
if ( V_146 -> V_152 == V_388 ) {
V_21 += F_88 ( V_387 ) ;
V_387 = sizeof( * V_33 ) ;
V_21 += F_88 ( sizeof( struct V_154 ) ) ;
}
V_21 += F_87 ( V_387 ) ;
V_141 = F_80 ( V_21 , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , V_146 -> V_132 , V_146 -> V_152 , V_387 , 0 ) ;
V_38 = - V_165 ;
if ( V_143 == NULL )
goto V_389;
V_24 = F_42 ( V_143 ) ;
if ( V_146 -> V_152 == V_388 ) {
struct V_1 * V_163 ;
V_33 = F_42 ( V_143 ) ;
memcpy ( & V_33 -> V_158 , & V_87 -> V_33 . V_158 , sizeof( V_33 -> V_158 ) ) ;
V_33 -> V_49 = V_87 -> V_33 . V_49 ;
V_33 -> V_39 = V_87 -> V_58 . V_39 ;
V_33 -> V_34 = V_87 -> V_33 . V_34 ;
V_163 = F_60 ( V_141 , V_390 , sizeof( * V_24 ) ) ;
V_38 = - V_165 ;
if ( V_163 == NULL )
goto V_389;
V_24 = F_2 ( V_163 ) ;
}
V_38 = F_62 ( V_87 , V_24 , V_141 ) ;
if ( V_38 )
goto V_389;
F_71 ( V_141 , V_143 ) ;
return F_83 ( V_113 , V_141 , 0 , V_384 ) ;
V_389:
F_82 ( V_141 ) ;
return V_38 ;
}
static int F_192 ( struct V_86 * V_87 , const struct V_145 * V_146 )
{
switch ( V_146 -> V_152 ) {
case V_380 :
return F_186 ( V_87 , V_146 ) ;
case V_311 :
return F_188 ( V_87 , V_146 ) ;
case V_388 :
case V_391 :
case V_148 :
return F_191 ( V_87 , V_146 ) ;
case V_383 :
return F_189 ( V_146 ) ;
default:
F_193 ( V_392 L_3 ,
V_146 -> V_152 ) ;
break;
}
return 0 ;
}
static inline T_4 F_194 ( struct V_86 * V_87 ,
struct V_268 * V_270 )
{
return F_87 ( sizeof( struct V_324 ) )
+ F_88 ( sizeof( struct V_271 ) * V_270 -> V_275 )
+ F_88 ( sizeof( struct V_154 ) )
+ F_88 ( F_27 ( V_87 -> V_174 ) )
+ F_137 () ;
}
static int F_195 ( struct V_140 * V_141 , struct V_86 * V_87 ,
struct V_276 * V_393 , struct V_268 * V_270 )
{
T_6 V_132 = F_196 () ;
struct V_324 * V_325 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , 0 , 0 , V_394 , sizeof( * V_325 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_325 = F_42 ( V_143 ) ;
memcpy ( & V_325 -> V_33 , & V_87 -> V_33 , sizeof( V_325 -> V_33 ) ) ;
memcpy ( & V_325 -> V_91 , & V_87 -> V_58 . V_91 , sizeof( V_325 -> V_91 ) ) ;
memcpy ( & V_325 -> V_88 , & V_87 -> V_88 , sizeof( V_325 -> V_88 ) ) ;
F_124 ( V_270 , & V_325 -> V_327 , V_253 ) ;
V_325 -> V_281 = V_393 -> V_281 ;
V_325 -> V_282 = V_393 -> V_282 ;
V_325 -> V_283 = V_393 -> V_283 ;
V_325 -> V_132 = V_87 -> V_131 . V_132 = V_132 ;
V_38 = F_134 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_135 ( V_87 , V_141 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_270 -> type , V_141 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_141 , & V_270 -> V_130 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
return F_71 ( V_141 , V_143 ) ;
}
static int F_197 ( struct V_86 * V_87 , struct V_276 * V_393 ,
struct V_268 * V_270 )
{
struct V_113 * V_113 = F_187 ( V_87 ) ;
struct V_140 * V_141 ;
V_141 = F_80 ( F_194 ( V_87 , V_270 ) , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_195 ( V_141 , V_87 , V_393 , V_270 ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_395 ) ;
}
static struct V_268 * F_198 ( struct V_186 * V_144 , int V_396 ,
T_2 * V_306 , int V_21 , int * V_251 )
{
struct V_113 * V_113 = F_41 ( V_144 ) ;
struct V_257 * V_24 = (struct V_257 * ) V_306 ;
struct V_271 * V_272 = (struct V_271 * ) ( V_24 + 1 ) ;
struct V_268 * V_270 ;
int V_273 ;
switch ( V_144 -> V_397 ) {
case V_40 :
if ( V_396 != V_398 ) {
* V_251 = - V_399 ;
return NULL ;
}
break;
#if F_14 ( V_42 )
case V_41 :
if ( V_396 != V_400 ) {
* V_251 = - V_399 ;
return NULL ;
}
break;
#endif
default:
* V_251 = - V_7 ;
return NULL ;
}
* V_251 = - V_7 ;
if ( V_21 < sizeof( * V_24 ) ||
F_116 ( V_24 ) )
return NULL ;
V_273 = ( ( V_21 - sizeof( * V_24 ) ) / sizeof( * V_272 ) ) ;
if ( F_120 ( V_273 , V_272 , V_24 -> V_88 . V_39 ) )
return NULL ;
if ( V_24 -> V_251 > V_253 )
return NULL ;
V_270 = F_126 ( V_113 , V_196 ) ;
if ( V_270 == NULL ) {
* V_251 = - V_401 ;
return NULL ;
}
F_123 ( V_270 , V_24 ) ;
V_270 -> type = V_255 ;
F_119 ( V_270 , V_272 , V_273 ) ;
* V_251 = V_24 -> V_251 ;
return V_270 ;
}
static inline T_4 F_199 ( struct V_268 * V_270 )
{
return F_87 ( sizeof( struct V_320 ) )
+ F_88 ( sizeof( struct V_271 ) * V_270 -> V_275 )
+ F_88 ( F_27 ( V_270 -> V_174 ) )
+ F_88 ( sizeof( struct V_154 ) )
+ F_137 () ;
}
static int F_200 ( struct V_140 * V_141 , struct V_268 * V_270 ,
int V_251 , const struct V_145 * V_146 )
{
struct V_320 * V_402 ;
int V_321 = V_146 -> V_306 . V_321 ;
struct V_142 * V_143 ;
int V_38 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , 0 , V_403 , sizeof( * V_402 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_402 = F_42 ( V_143 ) ;
F_124 ( V_270 , & V_402 -> V_269 , V_251 ) ;
V_38 = F_134 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_136 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_270 -> type , V_141 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_141 , & V_270 -> V_130 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
V_402 -> V_321 = ! ! V_321 ;
return F_71 ( V_141 , V_143 ) ;
}
static int F_201 ( struct V_268 * V_270 , int V_251 , const struct V_145 * V_146 )
{
struct V_113 * V_113 = F_202 ( V_270 ) ;
struct V_140 * V_141 ;
V_141 = F_80 ( F_199 ( V_270 ) , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_200 ( V_141 , V_270 , V_251 , V_146 ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_381 ) ;
}
static int F_203 ( struct V_268 * V_270 , int V_251 , const struct V_145 * V_146 )
{
int V_21 = F_88 ( sizeof( struct V_271 ) * V_270 -> V_275 ) ;
struct V_113 * V_113 = F_202 ( V_270 ) ;
struct V_257 * V_24 ;
struct V_302 * V_33 ;
struct V_142 * V_143 ;
struct V_140 * V_141 ;
int V_387 , V_38 ;
V_387 = sizeof( * V_24 ) ;
if ( V_146 -> V_152 == V_304 ) {
V_21 += F_88 ( V_387 ) ;
V_387 = sizeof( * V_33 ) ;
}
V_21 += F_137 () ;
V_21 += F_88 ( sizeof( struct V_154 ) ) ;
V_21 += F_87 ( V_387 ) ;
V_141 = F_80 ( V_21 , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , V_146 -> V_132 , V_146 -> V_152 , V_387 , 0 ) ;
V_38 = - V_165 ;
if ( V_143 == NULL )
goto V_389;
V_24 = F_42 ( V_143 ) ;
if ( V_146 -> V_152 == V_304 ) {
struct V_1 * V_163 ;
V_33 = F_42 ( V_143 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_251 = V_251 ;
if ( V_146 -> V_306 . V_307 )
V_33 -> V_266 = V_270 -> V_266 ;
else
memcpy ( & V_33 -> V_88 , & V_270 -> V_294 , sizeof( V_33 -> V_88 ) ) ;
V_163 = F_60 ( V_141 , V_404 , sizeof( * V_24 ) ) ;
V_38 = - V_165 ;
if ( V_163 == NULL )
goto V_389;
V_24 = F_2 ( V_163 ) ;
}
F_124 ( V_270 , V_24 , V_251 ) ;
V_38 = F_134 ( V_270 , V_141 ) ;
if ( ! V_38 )
V_38 = F_138 ( V_270 -> type , V_141 ) ;
if ( ! V_38 )
V_38 = F_66 ( V_141 , & V_270 -> V_130 ) ;
if ( V_38 )
goto V_389;
F_71 ( V_141 , V_143 ) ;
return F_83 ( V_113 , V_141 , 0 , V_405 ) ;
V_389:
F_82 ( V_141 ) ;
return V_38 ;
}
static int F_204 ( const struct V_145 * V_146 )
{
struct V_113 * V_113 = V_146 -> V_113 ;
struct V_142 * V_143 ;
struct V_140 * V_141 ;
int V_38 ;
V_141 = F_80 ( F_137 () , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
V_143 = F_68 ( V_141 , V_146 -> V_150 , V_146 -> V_132 , V_406 , 0 , 0 ) ;
V_38 = - V_165 ;
if ( V_143 == NULL )
goto V_389;
V_38 = F_138 ( V_146 -> V_306 . type , V_141 ) ;
if ( V_38 )
goto V_389;
F_71 ( V_141 , V_143 ) ;
return F_83 ( V_113 , V_141 , 0 , V_405 ) ;
V_389:
F_82 ( V_141 ) ;
return V_38 ;
}
static int F_205 ( struct V_268 * V_270 , int V_251 , const struct V_145 * V_146 )
{
switch ( V_146 -> V_152 ) {
case V_297 :
case V_407 :
case V_304 :
return F_203 ( V_270 , V_251 , V_146 ) ;
case V_406 :
return F_204 ( V_146 ) ;
case V_403 :
return F_201 ( V_270 , V_251 , V_146 ) ;
default:
F_193 ( V_392 L_4 ,
V_146 -> V_152 ) ;
}
return 0 ;
}
static inline T_4 F_206 ( void )
{
return F_87 ( sizeof( struct V_408 ) ) ;
}
static int F_207 ( struct V_140 * V_141 , T_2 V_34 ,
struct V_357 * V_88 , T_1 * V_409 )
{
struct V_408 * V_410 ;
struct V_142 * V_143 ;
V_143 = F_68 ( V_141 , 0 , 0 , V_411 , sizeof( * V_410 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_410 = F_42 ( V_143 ) ;
V_410 -> V_34 = V_34 ;
memcpy ( & V_410 -> V_88 , V_88 , sizeof( V_410 -> V_88 ) ) ;
if ( V_409 ) {
int V_38 = F_64 ( V_141 , V_53 , sizeof( * V_409 ) , V_409 ) ;
if ( V_38 ) {
F_70 ( V_141 , V_143 ) ;
return V_38 ;
}
}
return F_71 ( V_141 , V_143 ) ;
}
static int F_208 ( struct V_113 * V_113 , T_2 V_34 ,
struct V_357 * V_88 , T_1 * V_409 )
{
struct V_140 * V_141 ;
V_141 = F_80 ( F_206 () , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_207 ( V_141 , V_34 , V_88 , V_409 ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_412 ) ;
}
static inline T_4 F_209 ( void )
{
return F_87 ( sizeof( struct V_413 ) ) ;
}
static int F_210 ( struct V_140 * V_141 , struct V_86 * V_87 ,
T_1 * V_349 , T_7 V_414 )
{
struct V_413 * V_338 ;
struct V_142 * V_143 ;
V_143 = F_68 ( V_141 , 0 , 0 , V_415 , sizeof( * V_338 ) , 0 ) ;
if ( V_143 == NULL )
return - V_165 ;
V_338 = F_42 ( V_143 ) ;
memcpy ( & V_338 -> V_33 . V_158 , & V_87 -> V_33 . V_158 , sizeof( V_338 -> V_33 . V_158 ) ) ;
V_338 -> V_33 . V_49 = V_87 -> V_33 . V_49 ;
V_338 -> V_33 . V_39 = V_87 -> V_58 . V_39 ;
V_338 -> V_33 . V_34 = V_87 -> V_33 . V_34 ;
memcpy ( & V_338 -> V_349 , V_349 , sizeof( V_338 -> V_349 ) ) ;
memcpy ( & V_338 -> V_347 , & V_87 -> V_58 . V_91 , sizeof( V_338 -> V_347 ) ) ;
V_338 -> V_414 = V_414 ;
V_338 -> V_416 = V_87 -> V_127 -> V_417 ;
V_338 -> V_90 = V_87 -> V_58 . V_90 ;
return F_71 ( V_141 , V_143 ) ;
}
static int F_211 ( struct V_86 * V_87 , T_1 * V_418 ,
T_7 V_419 )
{
struct V_113 * V_113 = F_187 ( V_87 ) ;
struct V_140 * V_141 ;
if ( V_87 -> V_33 . V_34 != V_35 )
return - V_7 ;
if ( ! V_87 -> V_127 )
return - V_7 ;
V_141 = F_80 ( F_209 () , V_196 ) ;
if ( V_141 == NULL )
return - V_68 ;
if ( F_210 ( V_141 , V_87 , V_418 , V_419 ) < 0 )
F_98 () ;
return F_83 ( V_113 , V_141 , 0 , V_420 ) ;
}
static bool F_212 ( const struct V_145 * V_146 )
{
return ( bool ) F_213 ( V_146 -> V_113 ) ;
}
static int T_8 F_214 ( struct V_113 * V_113 )
{
struct V_186 * V_199 ;
struct V_421 V_422 = {
. V_423 = V_424 ,
. V_425 = F_180 ,
} ;
V_199 = F_215 ( V_113 , V_426 , & V_422 ) ;
if ( V_199 == NULL )
return - V_68 ;
V_113 -> V_133 . V_427 = V_199 ;
F_216 ( V_113 -> V_133 . V_199 , V_199 ) ;
return 0 ;
}
static void T_9 F_217 ( struct V_428 * V_429 )
{
struct V_113 * V_113 ;
F_218 (net, net_exit_list, exit_list)
F_219 ( V_113 -> V_133 . V_199 , NULL ) ;
F_220 () ;
F_218 (net, net_exit_list, exit_list)
F_221 ( V_113 -> V_133 . V_427 ) ;
}
static int T_10 F_222 ( void )
{
int V_430 ;
F_193 ( V_431 L_5 ) ;
V_430 = F_223 ( & V_432 ) ;
if ( V_430 < 0 )
return V_430 ;
V_430 = F_224 ( & V_433 ) ;
if ( V_430 < 0 )
F_225 ( & V_432 ) ;
return V_430 ;
}
static void T_11 F_226 ( void )
{
F_227 ( & V_433 ) ;
F_225 ( & V_432 ) ;
}
