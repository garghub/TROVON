static inline int F_1 ( struct V_1 * V_2 )
{
return sizeof( * V_2 ) + ( ( V_2 -> V_3 + 7 ) / 8 ) ;
}
static int F_2 ( struct V_4 * * V_5 , enum V_6 type )
{
struct V_4 * V_7 = V_5 [ type ] ;
struct V_8 * V_9 ;
if ( ! V_7 )
return 0 ;
V_9 = F_3 ( V_7 ) ;
if ( F_4 ( V_7 ) < F_5 ( V_9 ) )
return - V_10 ;
switch ( type ) {
case V_11 :
case V_12 :
case V_13 :
break;
default:
return - V_10 ;
}
V_9 -> V_14 [ V_15 - 1 ] = '\0' ;
return 0 ;
}
static int F_6 ( struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_16 ] ;
struct V_17 * V_9 ;
if ( ! V_7 )
return 0 ;
V_9 = F_3 ( V_7 ) ;
if ( F_4 ( V_7 ) < F_7 ( V_9 ) )
return - V_10 ;
V_9 -> V_14 [ V_15 - 1 ] = '\0' ;
return 0 ;
}
static int F_8 ( struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_18 ] ;
struct V_1 * V_9 ;
if ( ! V_7 )
return 0 ;
V_9 = F_3 ( V_7 ) ;
if ( F_4 ( V_7 ) < F_1 ( V_9 ) )
return - V_10 ;
V_9 -> V_14 [ V_15 - 1 ] = '\0' ;
return 0 ;
}
static void F_9 ( struct V_4 * * V_5 , enum V_6 type ,
T_1 * * V_19 )
{
struct V_4 * V_7 = V_5 [ type ] ;
if ( V_7 && V_19 )
* V_19 = F_3 ( V_7 ) ;
}
static inline int F_10 ( struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_21 * V_22 ;
if ( ! V_7 )
return 0 ;
V_22 = F_3 ( V_7 ) ;
if ( V_22 -> V_23 != ( sizeof( struct V_21 ) + V_22 -> V_24 ) )
return - V_10 ;
return 0 ;
}
static inline int F_11 ( struct V_25 * V_26 ,
struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_27 ] ;
struct V_28 * V_29 ;
if ( V_26 -> V_30 & V_31 ) {
if ( ! V_7 )
return - V_10 ;
V_29 = F_3 ( V_7 ) ;
if ( V_29 -> V_32 > V_33 / sizeof( V_29 -> V_34 [ 0 ] ) / 8 )
return - V_10 ;
if ( F_4 ( V_7 ) < F_12 ( V_29 ) &&
F_4 ( V_7 ) != sizeof( * V_29 ) )
return - V_10 ;
}
if ( ! V_7 )
return 0 ;
if ( V_26 -> V_35 . V_36 != V_37 )
return - V_10 ;
if ( V_26 -> V_38 != 0 )
return - V_10 ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 ,
struct V_4 * * V_5 )
{
int V_39 ;
V_39 = - V_10 ;
switch ( V_26 -> V_40 ) {
case V_41 :
break;
case V_42 :
#if F_14 ( V_43 )
break;
#else
V_39 = - V_44 ;
goto V_45;
#endif
default:
goto V_45;
}
V_39 = - V_10 ;
switch ( V_26 -> V_35 . V_36 ) {
case V_46 :
if ( ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] ) ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_13 ] ||
V_5 [ V_47 ] )
goto V_45;
break;
case V_37 :
if ( V_5 [ V_13 ] )
goto V_45;
if ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] &&
! V_5 [ V_12 ] &&
! V_5 [ V_18 ] )
goto V_45;
if ( ( V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ) &&
V_5 [ V_18 ] )
goto V_45;
if ( V_5 [ V_47 ] &&
V_26 -> V_48 != V_49 )
goto V_45;
break;
case V_50 :
if ( ! V_5 [ V_13 ] ||
V_5 [ V_18 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ||
V_5 [ V_47 ] )
goto V_45;
break;
#if F_14 ( V_43 )
case V_51 :
case V_52 :
if ( V_5 [ V_13 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_53 ] ||
V_5 [ V_20 ] ||
V_5 [ V_47 ] ||
! V_5 [ V_54 ] )
goto V_45;
break;
#endif
default:
goto V_45;
}
if ( ( V_39 = F_8 ( V_5 ) ) )
goto V_45;
if ( ( V_39 = F_6 ( V_5 ) ) )
goto V_45;
if ( ( V_39 = F_2 ( V_5 , V_11 ) ) )
goto V_45;
if ( ( V_39 = F_2 ( V_5 , V_12 ) ) )
goto V_45;
if ( ( V_39 = F_2 ( V_5 , V_13 ) ) )
goto V_45;
if ( ( V_39 = F_10 ( V_5 ) ) )
goto V_45;
if ( ( V_39 = F_11 ( V_26 , V_5 ) ) )
goto V_45;
V_39 = - V_10 ;
switch ( V_26 -> V_48 ) {
case V_55 :
case V_49 :
case V_56 :
case V_57 :
break;
default:
goto V_45;
}
V_39 = 0 ;
V_45:
return V_39 ;
}
static int F_15 ( struct V_17 * * V_58 , T_2 * V_59 ,
struct V_4 * V_60 )
{
struct V_8 * V_61 ;
struct V_17 * V_26 ;
struct V_62 * V_63 ;
if ( ! V_60 )
return 0 ;
V_61 = F_3 ( V_60 ) ;
V_63 = F_16 ( V_61 -> V_14 , 1 ) ;
if ( ! V_63 )
return - V_64 ;
* V_59 = V_63 -> V_65 . V_66 ;
V_26 = F_17 ( sizeof( * V_26 ) + ( V_61 -> V_3 + 7 ) / 8 , V_67 ) ;
if ( ! V_26 )
return - V_68 ;
strcpy ( V_26 -> V_14 , V_63 -> V_69 ) ;
V_26 -> V_3 = V_61 -> V_3 ;
V_26 -> V_70 = V_63 -> V_71 . V_72 . V_73 ;
memcpy ( V_26 -> V_74 , V_61 -> V_74 , ( V_61 -> V_3 + 7 ) / 8 ) ;
* V_58 = V_26 ;
return 0 ;
}
static int F_18 ( struct V_17 * * V_58 , T_2 * V_59 ,
struct V_4 * V_60 )
{
struct V_17 * V_26 , * V_61 ;
struct V_62 * V_63 ;
if ( ! V_60 )
return 0 ;
V_61 = F_3 ( V_60 ) ;
V_63 = F_16 ( V_61 -> V_14 , 1 ) ;
if ( ! V_63 )
return - V_64 ;
if ( ( V_61 -> V_70 / 8 ) > V_75 ||
V_61 -> V_70 > V_63 -> V_71 . V_72 . V_76 )
return - V_10 ;
* V_59 = V_63 -> V_65 . V_66 ;
V_26 = F_19 ( V_61 , F_7 ( V_61 ) , V_67 ) ;
if ( ! V_26 )
return - V_68 ;
strcpy ( V_26 -> V_14 , V_63 -> V_69 ) ;
if ( ! V_26 -> V_70 )
V_26 -> V_70 = V_63 -> V_71 . V_72 . V_73 ;
* V_58 = V_26 ;
return 0 ;
}
static int F_20 ( struct V_1 * * V_58 , T_2 * V_59 ,
struct V_4 * V_60 )
{
struct V_1 * V_26 , * V_61 ;
struct V_62 * V_63 ;
if ( ! V_60 )
return 0 ;
V_61 = F_3 ( V_60 ) ;
V_63 = F_21 ( V_61 -> V_14 , V_61 -> V_77 , 1 ) ;
if ( ! V_63 )
return - V_64 ;
* V_59 = V_63 -> V_65 . V_66 ;
V_26 = F_19 ( V_61 , F_1 ( V_61 ) , V_67 ) ;
if ( ! V_26 )
return - V_68 ;
strcpy ( V_26 -> V_14 , V_63 -> V_69 ) ;
* V_58 = V_26 ;
return 0 ;
}
static inline int F_22 ( struct V_28 * V_78 ,
struct V_4 * V_79 )
{
struct V_28 * V_80 ;
int V_81 ;
if ( ! V_78 || ! V_79 )
return 0 ;
V_80 = F_3 ( V_79 ) ;
V_81 = F_12 ( V_80 ) ;
if ( F_4 ( V_79 ) < V_81 || F_12 ( V_78 ) != V_81 )
return - V_10 ;
return 0 ;
}
static int F_23 ( struct V_28 * * V_78 ,
struct V_28 * * V_82 ,
struct V_4 * V_60 )
{
struct V_28 * V_26 , * V_83 , * V_80 ;
int V_84 , V_81 ;
if ( ! V_60 )
return 0 ;
V_80 = F_3 ( V_60 ) ;
V_84 = F_12 ( V_80 ) ;
V_81 = F_4 ( V_60 ) >= V_84 ? V_84 : sizeof( * V_80 ) ;
V_26 = F_24 ( V_84 , V_67 ) ;
if ( ! V_26 )
return - V_68 ;
V_83 = F_24 ( V_84 , V_67 ) ;
if ( ! V_83 ) {
F_25 ( V_26 ) ;
return - V_68 ;
}
memcpy ( V_26 , V_80 , V_81 ) ;
memcpy ( V_83 , V_80 , V_81 ) ;
* V_78 = V_26 ;
* V_82 = V_83 ;
return 0 ;
}
static inline int F_26 ( struct V_85 * V_86 )
{
int V_23 = 0 ;
if ( V_86 ) {
V_23 += sizeof( struct V_21 ) ;
V_23 += V_86 -> V_24 ;
}
return V_23 ;
}
static void F_27 ( struct V_87 * V_88 , struct V_25 * V_26 )
{
memcpy ( & V_88 -> V_35 , & V_26 -> V_35 , sizeof( V_88 -> V_35 ) ) ;
memcpy ( & V_88 -> V_89 , & V_26 -> V_89 , sizeof( V_88 -> V_89 ) ) ;
memcpy ( & V_88 -> V_90 , & V_26 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
V_88 -> V_59 . V_48 = V_26 -> V_48 ;
V_88 -> V_59 . V_38 = V_26 -> V_38 ;
V_88 -> V_59 . V_91 = V_26 -> V_91 ;
V_88 -> V_59 . V_40 = V_26 -> V_40 ;
memcpy ( & V_88 -> V_59 . V_92 , & V_26 -> V_92 , sizeof( V_88 -> V_59 . V_92 ) ) ;
V_88 -> V_59 . V_30 = V_26 -> V_30 ;
if ( ! V_88 -> V_89 . V_40 && ! ( V_26 -> V_30 & V_93 ) )
V_88 -> V_89 . V_40 = V_26 -> V_40 ;
}
static void F_28 ( struct V_87 * V_88 , struct V_4 * * V_5 ,
int V_94 )
{
struct V_4 * V_79 = V_5 [ V_95 ] ;
struct V_4 * V_96 = V_94 ? V_5 [ V_27 ] : NULL ;
struct V_4 * V_97 = V_5 [ V_98 ] ;
struct V_4 * V_99 = V_5 [ V_100 ] ;
struct V_4 * V_7 = V_5 [ V_101 ] ;
if ( V_96 ) {
struct V_28 * V_78 ;
V_78 = F_3 ( V_96 ) ;
memcpy ( V_88 -> V_78 , V_78 ,
F_12 ( V_78 ) ) ;
memcpy ( V_88 -> V_82 , V_78 ,
F_12 ( V_78 ) ) ;
}
if ( V_79 ) {
struct V_102 * V_103 ;
V_103 = F_3 ( V_79 ) ;
memcpy ( & V_88 -> V_103 , V_103 , sizeof( * V_103 ) ) ;
memcpy ( & V_88 -> V_104 , V_103 , sizeof( * V_103 ) ) ;
}
if ( V_97 ) {
struct V_105 * V_106 ;
V_106 = F_3 ( V_97 ) ;
V_88 -> V_107 . V_108 = V_106 -> V_108 ;
V_88 -> V_107 . V_109 = V_106 -> V_109 ;
V_88 -> V_107 . V_110 = V_106 -> V_110 ;
V_88 -> V_107 . V_111 = V_106 -> V_111 ;
}
if ( V_99 )
V_88 -> V_112 = F_29 ( V_99 ) ;
if ( V_7 )
V_88 -> V_113 = F_29 ( V_7 ) ;
}
static struct V_87 * F_30 ( struct V_114 * V_114 ,
struct V_25 * V_26 ,
struct V_4 * * V_5 ,
int * V_115 )
{
struct V_87 * V_88 = F_31 ( V_114 ) ;
int V_39 = - V_68 ;
if ( ! V_88 )
goto V_116;
F_27 ( V_88 , V_26 ) ;
if ( V_5 [ V_117 ] )
V_88 -> V_59 . V_118 = F_29 ( V_5 [ V_117 ] ) ;
if ( ( V_39 = F_20 ( & V_88 -> V_119 , & V_88 -> V_59 . V_120 ,
V_5 [ V_18 ] ) ) )
goto error;
if ( ( V_39 = F_18 ( & V_88 -> V_121 , & V_88 -> V_59 . V_122 ,
V_5 [ V_16 ] ) ) )
goto error;
if ( ! V_88 -> V_59 . V_122 ) {
if ( ( V_39 = F_15 ( & V_88 -> V_121 , & V_88 -> V_59 . V_122 ,
V_5 [ V_11 ] ) ) )
goto error;
}
if ( ( V_39 = F_32 ( & V_88 -> V_123 , & V_88 -> V_59 . V_120 ,
V_124 ,
V_5 [ V_12 ] ) ) )
goto error;
if ( ( V_39 = F_32 ( & V_88 -> V_125 , & V_88 -> V_59 . V_126 ,
V_127 ,
V_5 [ V_13 ] ) ) )
goto error;
if ( V_5 [ V_53 ] ) {
V_88 -> V_128 = F_19 ( F_3 ( V_5 [ V_53 ] ) ,
sizeof( * V_88 -> V_128 ) , V_67 ) ;
if ( V_88 -> V_128 == NULL )
goto error;
}
if ( V_5 [ V_47 ] )
V_88 -> V_129 = F_29 ( V_5 [ V_47 ] ) ;
if ( V_5 [ V_54 ] ) {
V_88 -> V_130 = F_19 ( F_3 ( V_5 [ V_54 ] ) ,
sizeof( * V_88 -> V_130 ) , V_67 ) ;
if ( V_88 -> V_130 == NULL )
goto error;
}
F_33 ( V_5 , & V_88 -> V_131 ) ;
V_39 = F_34 ( V_88 , false ) ;
if ( V_39 )
goto error;
if ( V_5 [ V_20 ] &&
F_35 ( V_88 , F_3 ( V_5 [ V_20 ] ) ) )
goto error;
if ( ( V_39 = F_23 ( & V_88 -> V_78 , & V_88 -> V_82 ,
V_5 [ V_27 ] ) ) )
goto error;
V_88 -> V_132 . V_133 = V_26 -> V_133 ;
V_88 -> V_113 = V_114 -> V_134 . V_135 ;
V_88 -> V_112 = ( V_114 -> V_134 . V_136 * V_137 ) / V_138 ;
if ( ( V_39 = F_36 ( V_88 ) ) )
goto error;
F_28 ( V_88 , V_5 , 0 ) ;
return V_88 ;
error:
V_88 -> V_132 . V_139 = V_140 ;
F_37 ( V_88 ) ;
V_116:
* V_115 = V_39 ;
return NULL ;
}
static int F_38 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_25 * V_26 = F_40 ( V_144 ) ;
struct V_87 * V_88 ;
int V_39 ;
struct V_146 V_147 ;
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
V_39 = F_13 ( V_26 , V_5 ) ;
if ( V_39 )
return V_39 ;
V_88 = F_30 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( ! V_88 )
return V_39 ;
F_43 ( V_88 ) ;
if ( V_144 -> V_152 == V_153 )
V_39 = F_44 ( V_88 ) ;
else
V_39 = F_45 ( V_88 ) ;
F_46 ( V_149 , & V_151 ) ;
F_47 ( V_88 , V_39 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_39 < 0 ) {
V_88 -> V_132 . V_139 = V_140 ;
F_48 ( V_88 ) ;
goto V_45;
}
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_49 ( V_88 , & V_147 ) ;
V_45:
F_37 ( V_88 ) ;
return V_39 ;
}
static struct V_87 * F_50 ( struct V_114 * V_114 ,
struct V_158 * V_26 ,
struct V_4 * * V_5 ,
int * V_115 )
{
struct V_87 * V_88 = NULL ;
struct V_159 V_160 ;
int V_39 ;
T_4 V_131 = F_33 ( V_5 , & V_160 ) ;
if ( F_51 ( V_26 -> V_36 , V_161 ) ) {
V_39 = - V_162 ;
V_88 = F_52 ( V_114 , V_131 , & V_26 -> V_163 , V_26 -> V_164 , V_26 -> V_36 , V_26 -> V_40 ) ;
} else {
T_1 * V_92 = NULL ;
F_9 ( V_5 , V_165 , & V_92 ) ;
if ( ! V_92 ) {
V_39 = - V_10 ;
goto V_45;
}
V_39 = - V_162 ;
V_88 = F_53 ( V_114 , V_131 ,
& V_26 -> V_163 , V_92 ,
V_26 -> V_36 , V_26 -> V_40 ) ;
}
V_45:
if ( ! V_88 && V_115 )
* V_115 = V_39 ;
return V_88 ;
}
static int F_54 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_39 = - V_162 ;
struct V_146 V_147 ;
struct V_158 * V_26 = F_40 ( V_144 ) ;
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
V_88 = F_50 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( V_88 == NULL )
return V_39 ;
if ( ( V_39 = F_55 ( V_88 ) ) != 0 )
goto V_45;
if ( F_56 ( V_88 ) ) {
V_39 = - V_166 ;
goto V_45;
}
V_39 = F_57 ( V_88 ) ;
if ( V_39 < 0 )
goto V_45;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_157 = V_144 -> V_152 ;
F_49 ( V_88 , & V_147 ) ;
V_45:
F_46 ( V_149 , & V_151 ) ;
F_58 ( V_88 , V_39 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
F_37 ( V_88 ) ;
return V_39 ;
}
static void F_59 ( struct V_87 * V_88 , struct V_25 * V_26 )
{
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
memcpy ( & V_26 -> V_35 , & V_88 -> V_35 , sizeof( V_26 -> V_35 ) ) ;
memcpy ( & V_26 -> V_89 , & V_88 -> V_89 , sizeof( V_26 -> V_89 ) ) ;
memcpy ( & V_26 -> V_90 , & V_88 -> V_90 , sizeof( V_26 -> V_90 ) ) ;
memcpy ( & V_26 -> V_107 , & V_88 -> V_107 , sizeof( V_26 -> V_107 ) ) ;
memcpy ( & V_26 -> V_167 , & V_88 -> V_167 , sizeof( V_26 -> V_167 ) ) ;
memcpy ( & V_26 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_26 -> V_92 ) ) ;
V_26 -> V_48 = V_88 -> V_59 . V_48 ;
V_26 -> V_38 = V_88 -> V_59 . V_38 ;
V_26 -> V_91 = V_88 -> V_59 . V_91 ;
V_26 -> V_40 = V_88 -> V_59 . V_40 ;
V_26 -> V_30 = V_88 -> V_59 . V_30 ;
V_26 -> V_133 = V_88 -> V_132 . V_133 ;
}
static int F_60 ( struct V_85 * V_168 , struct V_141 * V_142 )
{
struct V_21 * V_22 ;
struct V_4 * V_169 ;
int V_170 = sizeof( * V_22 ) + V_168 -> V_24 ;
V_169 = F_61 ( V_142 , V_20 , V_170 ) ;
if ( V_169 == NULL )
return - V_171 ;
V_22 = F_3 ( V_169 ) ;
V_22 -> V_172 = V_20 ;
V_22 -> V_23 = V_170 ;
V_22 -> V_173 = V_168 -> V_173 ;
V_22 -> V_174 = V_168 -> V_174 ;
V_22 -> V_24 = V_168 -> V_24 ;
memcpy ( V_22 + 1 , V_168 -> V_175 , V_168 -> V_24 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_72 , struct V_141 * V_142 )
{
struct V_8 * V_63 ;
struct V_4 * V_176 ;
V_176 = F_61 ( V_142 , V_11 ,
sizeof( * V_63 ) + ( V_72 -> V_3 + 7 ) / 8 ) ;
if ( ! V_176 )
return - V_171 ;
V_63 = F_3 ( V_176 ) ;
strncpy ( V_63 -> V_14 , V_72 -> V_14 , sizeof( V_63 -> V_14 ) ) ;
memcpy ( V_63 -> V_74 , V_72 -> V_74 , ( V_72 -> V_3 + 7 ) / 8 ) ;
V_63 -> V_3 = V_72 -> V_3 ;
return 0 ;
}
static int F_63 ( struct V_87 * V_88 ,
struct V_25 * V_26 ,
struct V_141 * V_142 )
{
int V_177 = 0 ;
F_59 ( V_88 , V_26 ) ;
if ( V_88 -> V_59 . V_118 ) {
V_177 = F_64 ( V_142 , V_117 ,
V_88 -> V_59 . V_118 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_130 ) {
V_177 = F_65 ( V_142 , V_54 , sizeof( * V_88 -> V_130 ) , V_88 -> V_130 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_178 ) {
V_177 = F_66 ( V_142 , V_179 , V_88 -> V_178 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_119 ) {
V_177 = F_65 ( V_142 , V_18 , F_1 ( V_88 -> V_119 ) , V_88 -> V_119 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_121 ) {
V_177 = F_62 ( V_88 -> V_121 , V_142 ) ;
if ( ! V_177 )
V_177 = F_65 ( V_142 , V_16 ,
F_7 ( V_88 -> V_121 ) , V_88 -> V_121 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_123 ) {
V_177 = F_65 ( V_142 , V_12 , F_5 ( V_88 -> V_123 ) , V_88 -> V_123 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_125 ) {
V_177 = F_65 ( V_142 , V_13 , sizeof( * ( V_88 -> V_125 ) ) , V_88 -> V_125 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_128 ) {
V_177 = F_65 ( V_142 , V_53 , sizeof( * V_88 -> V_128 ) , V_88 -> V_128 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_129 ) {
V_177 = F_64 ( V_142 , V_47 , V_88 -> V_129 ) ;
if ( V_177 )
goto V_45;
}
V_177 = F_67 ( V_142 , & V_88 -> V_131 ) ;
if ( V_177 )
goto V_45;
if ( V_88 -> V_78 ) {
V_177 = F_65 ( V_142 , V_27 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
if ( V_177 )
goto V_45;
}
if ( V_88 -> V_180 )
V_177 = F_60 ( V_88 -> V_180 , V_142 ) ;
V_45:
return V_177 ;
}
static int F_68 ( struct V_87 * V_88 , int V_181 , void * V_182 )
{
struct V_183 * V_184 = V_182 ;
struct V_141 * V_185 = V_184 -> V_185 ;
struct V_141 * V_142 = V_184 -> V_186 ;
struct V_25 * V_26 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , F_70 ( V_185 ) . V_155 , V_184 -> V_154 ,
V_153 , sizeof( * V_26 ) , V_184 -> V_187 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_26 = F_40 ( V_144 ) ;
V_39 = F_63 ( V_88 , V_26 , V_142 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
F_72 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_73 ( struct V_188 * V_189 )
{
struct V_190 * V_191 = (struct V_190 * ) & V_189 -> args [ 1 ] ;
F_74 ( V_191 ) ;
return 0 ;
}
static int F_75 ( struct V_141 * V_142 , struct V_188 * V_189 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_190 * V_191 = (struct V_190 * ) & V_189 -> args [ 1 ] ;
struct V_183 V_192 ;
F_76 ( sizeof( struct V_190 ) >
sizeof( V_189 -> args ) - sizeof( V_189 -> args [ 0 ] ) ) ;
V_192 . V_185 = V_189 -> V_142 ;
V_192 . V_186 = V_142 ;
V_192 . V_154 = V_189 -> V_144 -> V_154 ;
V_192 . V_187 = V_193 ;
if ( ! V_189 -> args [ 0 ] ) {
V_189 -> args [ 0 ] = 1 ;
F_77 ( V_191 , 0 ) ;
}
( void ) V_190 ( V_114 , V_191 , F_68 , & V_192 ) ;
return V_142 -> V_23 ;
}
static struct V_141 * F_78 ( struct V_141 * V_185 ,
struct V_87 * V_88 , T_4 V_133 )
{
struct V_183 V_192 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_79 ( V_194 , V_195 ) ;
if ( ! V_142 )
return F_80 ( - V_68 ) ;
V_192 . V_185 = V_185 ;
V_192 . V_186 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_187 = 0 ;
V_39 = F_68 ( V_88 , 0 , & V_192 ) ;
if ( V_39 ) {
F_81 ( V_142 ) ;
return F_80 ( V_39 ) ;
}
return V_142 ;
}
static inline T_5 F_82 ( void )
{
return F_83 ( 4 )
+ F_84 ( sizeof( struct V_196 ) )
+ F_84 ( sizeof( struct V_197 ) ) ;
}
static int F_85 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_30 )
{
struct V_198 V_199 ;
struct V_196 V_200 ;
struct V_197 V_201 ;
struct V_143 * V_144 ;
int V_39 ;
T_4 * V_202 ;
V_144 = F_69 ( V_142 , V_155 , V_133 , V_203 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_202 = F_40 ( V_144 ) ;
* V_202 = V_30 ;
F_86 ( V_114 , & V_199 ) ;
V_200 . V_204 = V_199 . V_204 ;
V_200 . V_205 = V_199 . V_205 ;
V_200 . V_206 = V_199 . V_206 ;
V_200 . V_207 = V_199 . V_207 ;
V_200 . V_208 = V_199 . V_208 ;
V_200 . V_209 = V_199 . V_209 ;
V_201 . V_210 = V_199 . V_210 ;
V_201 . V_211 = V_199 . V_211 ;
V_39 = F_65 ( V_142 , V_212 , sizeof( V_200 ) , & V_200 ) ;
if ( ! V_39 )
V_39 = F_65 ( V_142 , V_213 , sizeof( V_201 ) , & V_201 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
return F_72 ( V_142 , V_144 ) ;
}
static int F_87 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_141 * V_214 ;
T_4 * V_30 = F_40 ( V_144 ) ;
T_4 V_215 = F_70 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_214 = F_79 ( F_82 () , V_195 ) ;
if ( V_214 == NULL )
return - V_68 ;
if ( F_85 ( V_214 , V_114 , V_215 , V_133 , * V_30 ) < 0 )
F_88 () ;
return F_89 ( V_114 -> V_134 . V_216 , V_214 , V_215 ) ;
}
static inline T_5 F_90 ( void )
{
return F_83 ( 4 )
+ F_84 ( sizeof( struct V_217 ) )
+ F_84 ( 4 ) ;
}
static int F_91 ( struct V_141 * V_142 , struct V_114 * V_114 ,
T_4 V_155 , T_4 V_133 , T_4 V_30 )
{
struct V_218 V_199 ;
struct V_217 V_219 ;
struct V_143 * V_144 ;
int V_39 ;
T_4 * V_202 ;
V_144 = F_69 ( V_142 , V_155 , V_133 , V_220 , sizeof( T_4 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_202 = F_40 ( V_144 ) ;
* V_202 = V_30 ;
F_92 ( V_114 , & V_199 ) ;
V_219 . V_221 = V_199 . V_221 ;
V_219 . V_222 = V_199 . V_222 ;
V_39 = F_64 ( V_142 , V_223 , V_199 . V_224 ) ;
if ( ! V_39 )
V_39 = F_65 ( V_142 , V_225 , sizeof( V_219 ) , & V_219 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
return F_72 ( V_142 , V_144 ) ;
}
static int F_93 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_141 * V_214 ;
T_4 * V_30 = F_40 ( V_144 ) ;
T_4 V_215 = F_70 ( V_142 ) . V_155 ;
T_4 V_133 = V_144 -> V_154 ;
V_214 = F_79 ( F_90 () , V_195 ) ;
if ( V_214 == NULL )
return - V_68 ;
if ( F_91 ( V_214 , V_114 , V_215 , V_133 , * V_30 ) < 0 )
F_88 () ;
return F_89 ( V_114 -> V_134 . V_216 , V_214 , V_215 ) ;
}
static int F_94 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_158 * V_26 = F_40 ( V_144 ) ;
struct V_87 * V_88 ;
struct V_141 * V_226 ;
int V_39 = - V_162 ;
V_88 = F_50 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( V_88 == NULL )
goto V_227;
V_226 = F_78 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_95 ( V_226 ) ) {
V_39 = F_96 ( V_226 ) ;
} else {
V_39 = F_89 ( V_114 -> V_134 . V_216 , V_226 , F_70 ( V_142 ) . V_155 ) ;
}
F_37 ( V_88 ) ;
V_227:
return V_39 ;
}
static int F_97 ( struct V_228 * V_26 )
{
switch ( V_26 -> V_192 . V_35 . V_36 ) {
case V_46 :
case V_37 :
break;
case V_50 :
if ( V_26 -> V_229 >= 0x10000 )
return - V_10 ;
break;
default:
return - V_10 ;
}
if ( V_26 -> V_230 > V_26 -> V_229 )
return - V_10 ;
return 0 ;
}
static int F_98 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_228 * V_26 ;
struct V_141 * V_226 ;
T_1 * V_163 ;
int V_40 ;
int V_39 ;
T_4 V_131 ;
struct V_159 V_160 ;
V_26 = F_40 ( V_144 ) ;
V_39 = F_97 ( V_26 ) ;
if ( V_39 )
goto V_227;
V_40 = V_26 -> V_192 . V_40 ;
V_163 = & V_26 -> V_192 . V_35 . V_163 ;
V_88 = NULL ;
V_131 = F_33 ( V_5 , & V_160 ) ;
if ( V_26 -> V_192 . V_133 ) {
V_88 = F_99 ( V_114 , V_131 , V_26 -> V_192 . V_133 ) ;
if ( V_88 && ! F_100 ( & V_88 -> V_35 . V_163 , V_163 , V_40 ) ) {
F_37 ( V_88 ) ;
V_88 = NULL ;
}
}
if ( ! V_88 )
V_88 = F_101 ( V_114 , & V_160 , V_26 -> V_192 . V_48 , V_26 -> V_192 . V_91 ,
V_26 -> V_192 . V_35 . V_36 , V_163 ,
& V_26 -> V_192 . V_92 , 1 ,
V_40 ) ;
V_39 = - V_231 ;
if ( V_88 == NULL )
goto V_227;
V_39 = F_102 ( V_88 , V_26 -> V_230 , V_26 -> V_229 ) ;
if ( V_39 )
goto V_45;
V_226 = F_78 ( V_142 , V_88 , V_144 -> V_154 ) ;
if ( F_95 ( V_226 ) ) {
V_39 = F_96 ( V_226 ) ;
goto V_45;
}
V_39 = F_89 ( V_114 -> V_134 . V_216 , V_226 , F_70 ( V_142 ) . V_155 ) ;
V_45:
F_37 ( V_88 ) ;
V_227:
return V_39 ;
}
static int F_103 ( T_2 V_232 )
{
switch ( V_232 ) {
case V_233 :
case V_234 :
case V_235 :
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_104 ( T_2 type )
{
switch ( type ) {
case V_236 :
#ifdef F_105
case V_237 :
#endif
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_106 ( struct V_238 * V_26 )
{
switch ( V_26 -> V_239 ) {
case V_240 :
case V_241 :
case V_242 :
case V_243 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_244 ) {
case V_245 :
case V_246 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_89 . V_40 ) {
case V_41 :
break;
case V_42 :
#if F_14 ( V_43 )
break;
#else
return - V_44 ;
#endif
default:
return - V_10 ;
}
return F_103 ( V_26 -> V_232 ) ;
}
static int F_107 ( struct V_247 * V_248 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_21 * V_22 ;
if ( ! V_7 )
return 0 ;
V_22 = F_3 ( V_7 ) ;
return F_108 ( & V_248 -> V_180 , V_22 ) ;
}
static void F_109 ( struct V_247 * V_249 , struct V_250 * V_251 ,
int V_252 )
{
int V_253 ;
V_249 -> V_254 = V_252 ;
for ( V_253 = 0 ; V_253 < V_252 ; V_253 ++ , V_251 ++ ) {
struct V_255 * V_256 = & V_249 -> V_257 [ V_253 ] ;
memcpy ( & V_256 -> V_35 , & V_251 -> V_35 , sizeof( struct V_258 ) ) ;
memcpy ( & V_256 -> V_92 , & V_251 -> V_92 ,
sizeof( T_1 ) ) ;
V_256 -> V_91 = V_251 -> V_91 ;
V_256 -> V_48 = V_251 -> V_48 ;
V_256 -> V_239 = V_251 -> V_239 ;
V_256 -> V_259 = V_251 -> V_259 ;
V_256 -> V_260 = V_251 -> V_260 ;
V_256 -> V_261 = V_251 -> V_261 ;
V_256 -> V_262 = V_251 -> V_262 ;
V_256 -> V_263 = ! ~ ( V_256 -> V_260 & V_256 -> V_261 & V_256 -> V_262 ) ;
V_256 -> V_264 = V_251 -> V_40 ;
}
}
static int F_110 ( int V_252 , struct V_250 * V_251 , T_6 V_40 )
{
int V_253 ;
if ( V_252 > V_265 )
return - V_10 ;
for ( V_253 = 0 ; V_253 < V_252 ; V_253 ++ ) {
if ( ! V_251 [ V_253 ] . V_40 )
V_251 [ V_253 ] . V_40 = V_40 ;
switch ( V_251 [ V_253 ] . V_40 ) {
case V_41 :
break;
#if F_14 ( V_43 )
case V_42 :
break;
#endif
default:
return - V_10 ;
}
}
return 0 ;
}
static int F_111 ( struct V_247 * V_248 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_266 ] ;
if ( ! V_7 ) {
V_248 -> V_254 = 0 ;
} else {
struct V_250 * V_267 = F_3 ( V_7 ) ;
int V_252 = F_4 ( V_7 ) / sizeof( * V_267 ) ;
int V_39 ;
V_39 = F_110 ( V_252 , V_267 , V_248 -> V_40 ) ;
if ( V_39 )
return V_39 ;
F_109 ( V_248 , V_267 , V_252 ) ;
}
return 0 ;
}
static int F_112 ( T_2 * V_268 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_269 ] ;
struct V_270 * V_271 ;
T_2 type = V_236 ;
int V_39 ;
if ( V_7 ) {
V_271 = F_3 ( V_7 ) ;
type = V_271 -> type ;
}
V_39 = F_104 ( type ) ;
if ( V_39 )
return V_39 ;
* V_268 = type ;
return 0 ;
}
static void F_113 ( struct V_247 * V_249 , struct V_238 * V_26 )
{
V_249 -> V_272 = V_26 -> V_272 ;
V_249 -> V_273 = V_26 -> V_273 ;
memcpy ( & V_249 -> V_274 , & V_26 -> V_89 , sizeof( V_249 -> V_274 ) ) ;
memcpy ( & V_249 -> V_90 , & V_26 -> V_90 , sizeof( V_249 -> V_90 ) ) ;
V_249 -> V_244 = V_26 -> V_244 ;
V_249 -> V_30 = V_26 -> V_30 ;
V_249 -> V_40 = V_26 -> V_89 . V_40 ;
}
static void F_114 ( struct V_247 * V_249 , struct V_238 * V_26 , int V_232 )
{
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
memcpy ( & V_26 -> V_89 , & V_249 -> V_274 , sizeof( V_26 -> V_89 ) ) ;
memcpy ( & V_26 -> V_90 , & V_249 -> V_90 , sizeof( V_26 -> V_90 ) ) ;
memcpy ( & V_26 -> V_107 , & V_249 -> V_107 , sizeof( V_26 -> V_107 ) ) ;
V_26 -> V_272 = V_249 -> V_272 ;
V_26 -> V_273 = V_249 -> V_273 ;
V_26 -> V_89 . V_40 = V_249 -> V_40 ;
V_26 -> V_232 = V_232 ;
V_26 -> V_244 = V_249 -> V_244 ;
V_26 -> V_30 = V_249 -> V_30 ;
V_26 -> V_239 = V_240 ;
}
static struct V_247 * F_115 ( struct V_114 * V_114 , struct V_238 * V_26 , struct V_4 * * V_5 , int * V_115 )
{
struct V_247 * V_249 = F_116 ( V_114 , V_67 ) ;
int V_39 ;
if ( ! V_249 ) {
* V_115 = - V_68 ;
return NULL ;
}
F_113 ( V_249 , V_26 ) ;
V_39 = F_112 ( & V_249 -> type , V_5 ) ;
if ( V_39 )
goto error;
if ( ! ( V_39 = F_111 ( V_249 , V_5 ) ) )
V_39 = F_107 ( V_249 , V_5 ) ;
if ( V_39 )
goto error;
F_33 ( V_5 , & V_249 -> V_131 ) ;
return V_249 ;
error:
* V_115 = V_39 ;
V_249 -> V_191 . V_275 = 1 ;
F_117 ( V_249 ) ;
return NULL ;
}
static int F_118 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_238 * V_26 = F_40 ( V_144 ) ;
struct V_247 * V_249 ;
struct V_146 V_147 ;
int V_39 ;
int V_276 ;
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
V_39 = F_106 ( V_26 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_249 = F_115 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( ! V_249 )
return V_39 ;
V_276 = V_144 -> V_152 == V_277 ;
V_39 = F_119 ( V_26 -> V_232 , V_249 , V_276 ) ;
F_46 ( V_149 , & V_151 ) ;
F_120 ( V_249 , V_39 ? 0 : 1 , V_148 , V_150 , V_151 ) ;
if ( V_39 ) {
F_121 ( V_249 -> V_180 ) ;
F_25 ( V_249 ) ;
return V_39 ;
}
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_122 ( V_249 , V_26 -> V_232 , & V_147 ) ;
F_123 ( V_249 ) ;
return 0 ;
}
static int F_124 ( struct V_247 * V_249 , struct V_141 * V_142 )
{
struct V_250 V_278 [ V_265 ] ;
int V_253 ;
if ( V_249 -> V_254 == 0 )
return 0 ;
for ( V_253 = 0 ; V_253 < V_249 -> V_254 ; V_253 ++ ) {
struct V_250 * V_80 = & V_278 [ V_253 ] ;
struct V_255 * V_279 = & V_249 -> V_257 [ V_253 ] ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( & V_80 -> V_35 , & V_279 -> V_35 , sizeof( V_80 -> V_35 ) ) ;
V_80 -> V_40 = V_279 -> V_264 ;
memcpy ( & V_80 -> V_92 , & V_279 -> V_92 , sizeof( V_80 -> V_92 ) ) ;
V_80 -> V_91 = V_279 -> V_91 ;
V_80 -> V_48 = V_279 -> V_48 ;
V_80 -> V_239 = V_279 -> V_239 ;
V_80 -> V_259 = V_279 -> V_259 ;
V_80 -> V_260 = V_279 -> V_260 ;
V_80 -> V_261 = V_279 -> V_261 ;
V_80 -> V_262 = V_279 -> V_262 ;
}
return F_65 ( V_142 , V_266 ,
sizeof( struct V_250 ) * V_249 -> V_254 , V_278 ) ;
}
static inline int F_125 ( struct V_87 * V_88 , struct V_141 * V_142 )
{
if ( V_88 -> V_180 ) {
return F_60 ( V_88 -> V_180 , V_142 ) ;
}
return 0 ;
}
static inline int F_126 ( struct V_247 * V_249 , struct V_141 * V_142 )
{
if ( V_249 -> V_180 )
return F_60 ( V_249 -> V_180 , V_142 ) ;
return 0 ;
}
static inline T_5 F_127 ( void )
{
#ifdef F_105
return F_84 ( sizeof( struct V_270 ) ) ;
#else
return 0 ;
#endif
}
static int F_128 ( T_2 type , struct V_141 * V_142 )
{
struct V_270 V_271 = {
. type = type ,
} ;
return F_65 ( V_142 , V_269 , sizeof( V_271 ) , & V_271 ) ;
}
static inline int F_128 ( T_2 type , struct V_141 * V_142 )
{
return 0 ;
}
static int F_129 ( struct V_247 * V_249 , int V_232 , int V_181 , void * V_182 )
{
struct V_183 * V_184 = V_182 ;
struct V_238 * V_26 ;
struct V_141 * V_185 = V_184 -> V_185 ;
struct V_141 * V_142 = V_184 -> V_186 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , F_70 ( V_185 ) . V_155 , V_184 -> V_154 ,
V_277 , sizeof( * V_26 ) , V_184 -> V_187 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_26 = F_40 ( V_144 ) ;
F_114 ( V_249 , V_26 , V_232 ) ;
V_39 = F_124 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_126 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_249 -> type , V_142 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_142 , & V_249 -> V_131 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
F_72 ( V_142 , V_144 ) ;
return 0 ;
}
static int F_130 ( struct V_188 * V_189 )
{
struct V_280 * V_191 = (struct V_280 * ) & V_189 -> args [ 1 ] ;
F_131 ( V_191 ) ;
return 0 ;
}
static int F_132 ( struct V_141 * V_142 , struct V_188 * V_189 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_280 * V_191 = (struct V_280 * ) & V_189 -> args [ 1 ] ;
struct V_183 V_192 ;
F_76 ( sizeof( struct V_280 ) >
sizeof( V_189 -> args ) - sizeof( V_189 -> args [ 0 ] ) ) ;
V_192 . V_185 = V_189 -> V_142 ;
V_192 . V_186 = V_142 ;
V_192 . V_154 = V_189 -> V_144 -> V_154 ;
V_192 . V_187 = V_193 ;
if ( ! V_189 -> args [ 0 ] ) {
V_189 -> args [ 0 ] = 1 ;
F_133 ( V_191 , V_281 ) ;
}
( void ) V_280 ( V_114 , V_191 , F_129 , & V_192 ) ;
return V_142 -> V_23 ;
}
static struct V_141 * F_134 ( struct V_141 * V_185 ,
struct V_247 * V_249 ,
int V_232 , T_4 V_133 )
{
struct V_183 V_192 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_79 ( V_194 , V_67 ) ;
if ( ! V_142 )
return F_80 ( - V_68 ) ;
V_192 . V_185 = V_185 ;
V_192 . V_186 = V_142 ;
V_192 . V_154 = V_133 ;
V_192 . V_187 = 0 ;
V_39 = F_129 ( V_249 , V_232 , 0 , & V_192 ) ;
if ( V_39 ) {
F_81 ( V_142 ) ;
return F_80 ( V_39 ) ;
}
return V_142 ;
}
static int F_135 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_247 * V_249 ;
struct V_282 * V_26 ;
T_2 type = V_236 ;
int V_39 ;
struct V_146 V_147 ;
int V_283 ;
struct V_159 V_160 ;
T_4 V_131 = F_33 ( V_5 , & V_160 ) ;
V_26 = F_40 ( V_144 ) ;
V_283 = V_144 -> V_152 == V_284 ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_103 ( V_26 -> V_232 ) ;
if ( V_39 )
return V_39 ;
if ( V_26 -> V_273 )
V_249 = F_136 ( V_114 , V_131 , type , V_26 -> V_232 , V_26 -> V_273 , V_283 , & V_39 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_85 * V_285 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_285 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_39 = F_108 ( & V_285 , V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_249 = F_137 ( V_114 , V_131 , type , V_26 -> V_232 , & V_26 -> V_89 ,
V_285 , V_283 , & V_39 ) ;
F_121 ( V_285 ) ;
}
if ( V_249 == NULL )
return - V_231 ;
if ( ! V_283 ) {
struct V_141 * V_226 ;
V_226 = F_134 ( V_142 , V_249 , V_26 -> V_232 , V_144 -> V_154 ) ;
if ( F_95 ( V_226 ) ) {
V_39 = F_96 ( V_226 ) ;
} else {
V_39 = F_89 ( V_114 -> V_134 . V_216 , V_226 ,
F_70 ( V_142 ) . V_155 ) ;
}
} else {
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
F_46 ( V_149 , & V_151 ) ;
F_138 ( V_249 , V_39 ? 0 : 1 , V_148 , V_150 ,
V_151 ) ;
if ( V_39 != 0 )
goto V_45;
V_147 . V_286 . V_287 = V_26 -> V_273 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
F_122 ( V_249 , V_26 -> V_232 , & V_147 ) ;
}
V_45:
F_123 ( V_249 ) ;
if ( V_283 && V_39 == 0 )
F_139 ( V_114 ) ;
return V_39 ;
}
static int F_140 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
struct V_288 * V_26 = F_40 ( V_144 ) ;
struct V_289 V_290 ;
int V_39 ;
V_290 . V_148 = F_41 ( V_149 ) ;
V_290 . V_150 = F_42 ( V_149 ) ;
F_46 ( V_149 , & V_290 . V_291 ) ;
V_39 = F_141 ( V_114 , V_26 -> V_36 , & V_290 ) ;
if ( V_39 ) {
if ( V_39 == - V_162 )
return 0 ;
return V_39 ;
}
V_147 . V_286 . V_36 = V_26 -> V_36 ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_49 ( NULL , & V_147 ) ;
return 0 ;
}
static inline T_5 F_142 ( struct V_87 * V_88 )
{
T_5 V_292 = V_88 -> V_78 ?
F_12 ( V_88 -> V_78 ) :
sizeof( struct V_102 ) ;
return F_83 ( sizeof( struct V_293 ) )
+ F_84 ( V_292 )
+ F_84 ( sizeof( struct V_105 ) )
+ F_84 ( sizeof( struct V_159 ) )
+ F_84 ( 4 )
+ F_84 ( 4 ) ;
}
static int F_143 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_293 * V_35 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_294 , sizeof( * V_35 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_35 = F_40 ( V_144 ) ;
memcpy ( & V_35 -> V_295 . V_163 , & V_88 -> V_35 . V_163 , sizeof( V_88 -> V_35 . V_163 ) ) ;
V_35 -> V_295 . V_164 = V_88 -> V_35 . V_164 ;
V_35 -> V_295 . V_40 = V_88 -> V_59 . V_40 ;
V_35 -> V_295 . V_36 = V_88 -> V_35 . V_36 ;
memcpy ( & V_35 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_88 -> V_59 . V_92 ) ) ;
V_35 -> V_91 = V_88 -> V_59 . V_91 ;
V_35 -> V_30 = V_147 -> V_286 . V_296 ;
if ( V_88 -> V_78 ) {
V_39 = F_65 ( V_142 , V_27 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
} else {
V_39 = F_65 ( V_142 , V_95 , sizeof( V_88 -> V_103 ) ,
& V_88 -> V_103 ) ;
}
if ( V_39 )
goto V_297;
V_39 = F_65 ( V_142 , V_98 , sizeof( V_88 -> V_107 ) , & V_88 -> V_107 ) ;
if ( V_39 )
goto V_297;
if ( V_35 -> V_30 & V_298 ) {
V_39 = F_64 ( V_142 , V_101 , V_88 -> V_113 ) ;
if ( V_39 )
goto V_297;
}
if ( V_35 -> V_30 & V_299 ) {
V_39 = F_64 ( V_142 , V_100 ,
V_88 -> V_112 * 10 / V_137 ) ;
if ( V_39 )
goto V_297;
}
V_39 = F_67 ( V_142 , & V_88 -> V_131 ) ;
if ( V_39 )
goto V_297;
return F_72 ( V_142 , V_144 ) ;
V_297:
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
static int F_144 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_141 * V_214 ;
int V_39 ;
struct V_146 V_147 ;
T_4 V_131 ;
struct V_159 V_160 ;
struct V_293 * V_26 = F_40 ( V_144 ) ;
struct V_158 * V_35 = & V_26 -> V_295 ;
V_131 = F_33 ( V_5 , & V_160 ) ;
V_88 = F_52 ( V_114 , V_131 , & V_35 -> V_163 , V_35 -> V_164 , V_35 -> V_36 , V_35 -> V_40 ) ;
if ( V_88 == NULL )
return - V_162 ;
V_214 = F_79 ( F_142 ( V_88 ) , V_195 ) ;
if ( V_214 == NULL ) {
F_37 ( V_88 ) ;
return - V_68 ;
}
F_145 ( & V_88 -> V_300 ) ;
V_147 . V_286 . V_296 = V_26 -> V_30 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
if ( F_143 ( V_214 , V_88 , & V_147 ) < 0 )
F_88 () ;
V_39 = F_89 ( V_114 -> V_134 . V_216 , V_214 , F_70 ( V_142 ) . V_155 ) ;
F_146 ( & V_88 -> V_300 ) ;
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_147 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
struct V_146 V_147 ;
int V_39 = - V_10 ;
T_4 V_131 = 0 ;
struct V_159 V_160 ;
struct V_293 * V_26 = F_40 ( V_144 ) ;
struct V_4 * V_79 = V_5 [ V_95 ] ;
struct V_4 * V_96 = V_5 [ V_27 ] ;
struct V_4 * V_97 = V_5 [ V_98 ] ;
if ( ! V_97 && ! V_79 && ! V_96 )
return V_39 ;
if ( ! ( V_144 -> V_187 & V_301 ) )
return V_39 ;
V_131 = F_33 ( V_5 , & V_160 ) ;
V_88 = F_52 ( V_114 , V_131 , & V_26 -> V_295 . V_163 , V_26 -> V_295 . V_164 , V_26 -> V_295 . V_36 , V_26 -> V_295 . V_40 ) ;
if ( V_88 == NULL )
return - V_162 ;
if ( V_88 -> V_132 . V_139 != V_302 )
goto V_45;
V_39 = F_22 ( V_88 -> V_78 , V_79 ) ;
if ( V_39 )
goto V_45;
F_145 ( & V_88 -> V_300 ) ;
F_28 ( V_88 , V_5 , 1 ) ;
F_146 ( & V_88 -> V_300 ) ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_286 . V_296 = V_303 ;
F_49 ( V_88 , & V_147 ) ;
V_39 = 0 ;
V_45:
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_148 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_146 V_147 ;
T_2 type = V_236 ;
int V_39 ;
struct V_289 V_290 ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_290 . V_148 = F_41 ( V_149 ) ;
V_290 . V_150 = F_42 ( V_149 ) ;
F_46 ( V_149 , & V_290 . V_291 ) ;
V_39 = F_149 ( V_114 , type , & V_290 ) ;
if ( V_39 ) {
if ( V_39 == - V_162 )
return 0 ;
return V_39 ;
}
V_147 . V_286 . type = type ;
V_147 . V_157 = V_144 -> V_152 ;
V_147 . V_133 = V_144 -> V_154 ;
V_147 . V_155 = V_144 -> V_156 ;
V_147 . V_114 = V_114 ;
F_122 ( NULL , 0 , & V_147 ) ;
return 0 ;
}
static int F_150 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_247 * V_249 ;
struct V_304 * V_80 = F_40 ( V_144 ) ;
struct V_238 * V_26 = & V_80 -> V_248 ;
T_2 type = V_236 ;
int V_39 = - V_231 ;
struct V_159 V_160 ;
T_4 V_131 = F_33 ( V_5 , & V_160 ) ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_103 ( V_26 -> V_232 ) ;
if ( V_39 )
return V_39 ;
if ( V_26 -> V_273 )
V_249 = F_136 ( V_114 , V_131 , type , V_26 -> V_232 , V_26 -> V_273 , 0 , & V_39 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_85 * V_285 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_285 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_39 = F_108 ( & V_285 , V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_249 = F_137 ( V_114 , V_131 , type , V_26 -> V_232 ,
& V_26 -> V_89 , V_285 , 0 , & V_39 ) ;
F_121 ( V_285 ) ;
}
if ( V_249 == NULL )
return - V_231 ;
if ( F_151 ( V_249 -> V_191 . V_275 ) )
goto V_45;
V_39 = 0 ;
if ( V_80 -> V_305 ) {
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
F_46 ( V_149 , & V_151 ) ;
F_152 ( V_249 , V_26 -> V_232 ) ;
F_138 ( V_249 , 1 , V_148 , V_150 , V_151 ) ;
} else {
F_153 ( 1 , L_1 ) ;
}
F_154 ( V_249 , V_26 -> V_232 , V_80 -> V_305 , V_144 -> V_156 ) ;
V_45:
F_123 ( V_249 ) ;
return V_39 ;
}
static int F_155 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_87 * V_88 ;
int V_39 ;
struct V_306 * V_307 = F_40 ( V_144 ) ;
struct V_25 * V_26 = & V_307 -> V_139 ;
struct V_159 V_160 ;
T_4 V_131 = F_33 ( V_5 , & V_160 ) ;
V_88 = F_52 ( V_114 , V_131 , & V_26 -> V_35 . V_163 , V_26 -> V_35 . V_164 , V_26 -> V_35 . V_36 , V_26 -> V_40 ) ;
V_39 = - V_231 ;
if ( V_88 == NULL )
return V_39 ;
F_145 ( & V_88 -> V_300 ) ;
V_39 = - V_10 ;
if ( V_88 -> V_132 . V_139 != V_302 )
goto V_45;
F_156 ( V_88 , V_307 -> V_305 , V_144 -> V_156 ) ;
if ( V_307 -> V_305 ) {
T_3 V_148 = F_41 ( V_149 ) ;
T_4 V_150 = F_42 ( V_149 ) ;
T_4 V_151 ;
F_46 ( V_149 , & V_151 ) ;
F_157 ( V_88 ) ;
F_58 ( V_88 , 1 , V_148 , V_150 , V_151 ) ;
}
V_39 = 0 ;
V_45:
F_146 ( & V_88 -> V_300 ) ;
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_158 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_247 * V_249 ;
struct V_250 * V_251 ;
int V_253 ;
struct V_4 * V_7 = V_5 [ V_266 ] ;
struct V_159 V_131 ;
struct V_308 * V_309 = F_40 ( V_144 ) ;
struct V_87 * V_88 = F_31 ( V_114 ) ;
int V_39 = - V_68 ;
if ( ! V_88 )
goto V_310;
F_33 ( V_5 , & V_131 ) ;
V_39 = F_106 ( & V_309 -> V_311 ) ;
if ( V_39 )
goto V_312;
V_249 = F_115 ( V_114 , & V_309 -> V_311 , V_5 , & V_39 ) ;
if ( ! V_249 )
goto V_313;
memcpy ( & V_88 -> V_35 , & V_309 -> V_35 , sizeof( V_309 -> V_35 ) ) ;
memcpy ( & V_88 -> V_59 . V_92 , & V_309 -> V_92 , sizeof( V_309 -> V_92 ) ) ;
memcpy ( & V_88 -> V_89 , & V_309 -> V_89 , sizeof( V_309 -> V_89 ) ) ;
V_249 -> V_131 . V_160 = V_88 -> V_131 . V_160 = V_131 . V_160 ;
V_249 -> V_131 . V_314 = V_88 -> V_131 . V_314 = V_131 . V_314 ;
V_251 = F_3 ( V_7 ) ;
for ( V_253 = 0 ; V_253 < V_249 -> V_254 ; V_253 ++ , V_251 ++ ) {
struct V_255 * V_256 = & V_249 -> V_257 [ V_253 ] ;
memcpy ( & V_88 -> V_35 , & V_256 -> V_35 , sizeof( V_88 -> V_35 ) ) ;
V_88 -> V_59 . V_48 = V_256 -> V_48 ;
V_88 -> V_59 . V_91 = V_256 -> V_91 ;
V_88 -> V_59 . V_40 = V_251 -> V_40 ;
V_256 -> V_260 = V_309 -> V_260 ;
V_256 -> V_261 = V_309 -> V_261 ;
V_256 -> V_262 = V_309 -> V_262 ;
V_39 = F_159 ( V_88 , V_256 , V_249 ) ;
}
F_25 ( V_88 ) ;
F_25 ( V_249 ) ;
return 0 ;
V_312:
F_153 ( 1 , L_2 ) ;
V_313:
F_25 ( V_88 ) ;
V_310:
return V_39 ;
}
static int F_160 ( struct V_315 * V_316 ,
struct V_317 * V_318 ,
struct V_4 * * V_5 , int * V_319 )
{
struct V_4 * V_7 = V_5 [ V_320 ] ;
struct V_321 * V_322 ;
int V_253 , V_323 ;
if ( V_318 != NULL ) {
struct V_324 * V_325 ;
V_325 = F_3 ( V_5 [ V_326 ] ) ;
memcpy ( & V_318 -> V_327 , & V_325 -> V_327 , sizeof( V_318 -> V_327 ) ) ;
memcpy ( & V_318 -> V_328 , & V_325 -> V_328 , sizeof( V_318 -> V_328 ) ) ;
V_318 -> V_40 = V_325 -> V_40 ;
V_318 -> V_329 = V_325 -> V_329 ;
}
V_322 = F_3 ( V_7 ) ;
V_323 = F_4 ( V_7 ) / sizeof( * V_322 ) ;
if ( V_323 <= 0 || V_323 > V_265 )
return - V_10 ;
for ( V_253 = 0 ; V_253 < V_323 ; V_253 ++ , V_322 ++ , V_316 ++ ) {
memcpy ( & V_316 -> V_330 , & V_322 -> V_330 , sizeof( V_316 -> V_330 ) ) ;
memcpy ( & V_316 -> V_331 , & V_322 -> V_331 , sizeof( V_316 -> V_331 ) ) ;
memcpy ( & V_316 -> V_332 , & V_322 -> V_332 , sizeof( V_316 -> V_332 ) ) ;
memcpy ( & V_316 -> V_333 , & V_322 -> V_333 , sizeof( V_316 -> V_333 ) ) ;
V_316 -> V_36 = V_322 -> V_36 ;
V_316 -> V_48 = V_322 -> V_48 ;
V_316 -> V_91 = V_322 -> V_91 ;
V_316 -> V_334 = V_322 -> V_334 ;
V_316 -> V_335 = V_322 -> V_335 ;
}
* V_319 = V_253 ;
return 0 ;
}
static int F_161 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
struct V_282 * V_336 = F_40 ( V_144 ) ;
struct V_315 V_160 [ V_265 ] ;
struct V_317 V_132 , * V_337 ;
T_2 type ;
int V_39 ;
int V_338 = 0 ;
if ( V_5 [ V_320 ] == NULL )
return - V_10 ;
V_337 = V_5 [ V_326 ] ? & V_132 : NULL ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_160 ( (struct V_315 * ) V_160 , V_337 , V_5 , & V_338 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_338 )
return 0 ;
V_315 ( & V_336 -> V_89 , V_336 -> V_232 , type , V_160 , V_338 , V_337 ) ;
return 0 ;
}
static int F_161 ( struct V_141 * V_142 , struct V_143 * V_144 ,
struct V_4 * * V_5 )
{
return - V_339 ;
}
static int F_162 ( const struct V_315 * V_160 , struct V_141 * V_142 )
{
struct V_321 V_322 ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_36 = V_160 -> V_36 ;
V_322 . V_48 = V_160 -> V_48 ;
V_322 . V_91 = V_160 -> V_91 ;
V_322 . V_334 = V_160 -> V_334 ;
memcpy ( & V_322 . V_330 , & V_160 -> V_330 , sizeof( V_322 . V_330 ) ) ;
memcpy ( & V_322 . V_331 , & V_160 -> V_331 , sizeof( V_322 . V_331 ) ) ;
V_322 . V_335 = V_160 -> V_335 ;
memcpy ( & V_322 . V_332 , & V_160 -> V_332 , sizeof( V_322 . V_332 ) ) ;
memcpy ( & V_322 . V_333 , & V_160 -> V_333 , sizeof( V_322 . V_333 ) ) ;
return F_65 ( V_142 , V_320 , sizeof( V_322 ) , & V_322 ) ;
}
static int F_163 ( const struct V_317 * V_318 , struct V_141 * V_142 )
{
struct V_324 V_325 ;
memset ( & V_325 , 0 , sizeof( V_325 ) ) ;
V_325 . V_40 = V_318 -> V_40 ;
V_325 . V_329 = V_318 -> V_329 ;
memcpy ( & V_325 . V_327 , & V_318 -> V_327 , sizeof( V_325 . V_327 ) ) ;
memcpy ( & V_325 . V_328 , & V_318 -> V_328 , sizeof( V_325 . V_328 ) ) ;
return F_65 ( V_142 , V_326 , sizeof( V_325 ) , & V_325 ) ;
}
static inline T_5 F_164 ( int V_323 , int V_340 )
{
return F_83 ( sizeof( struct V_282 ) )
+ ( V_340 ? F_84 ( sizeof( struct V_317 ) ) : 0 )
+ F_84 ( sizeof( struct V_321 ) * V_323 )
+ F_127 () ;
}
static int F_165 ( struct V_141 * V_142 , const struct V_315 * V_160 ,
int V_323 , const struct V_317 * V_318 ,
const struct V_341 * V_89 , T_2 V_232 , T_2 type )
{
const struct V_315 * V_342 ;
struct V_282 * V_343 ;
struct V_143 * V_144 ;
int V_253 , V_39 ;
V_144 = F_69 ( V_142 , 0 , 0 , V_344 , sizeof( * V_343 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_343 = F_40 ( V_144 ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
memcpy ( & V_343 -> V_89 , V_89 , sizeof( V_343 -> V_89 ) ) ;
V_343 -> V_232 = V_232 ;
if ( V_318 != NULL ) {
V_39 = F_163 ( V_318 , V_142 ) ;
if ( V_39 )
goto V_297;
}
V_39 = F_128 ( type , V_142 ) ;
if ( V_39 )
goto V_297;
for ( V_253 = 0 , V_342 = V_160 ; V_253 < V_323 ; V_253 ++ , V_342 ++ ) {
V_39 = F_162 ( V_342 , V_142 ) ;
if ( V_39 )
goto V_297;
}
return F_72 ( V_142 , V_144 ) ;
V_297:
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
static int F_166 ( const struct V_341 * V_89 , T_2 V_232 , T_2 type ,
const struct V_315 * V_160 , int V_323 ,
const struct V_317 * V_318 )
{
struct V_114 * V_114 = & V_345 ;
struct V_141 * V_142 ;
V_142 = F_79 ( F_164 ( V_323 , ! ! V_318 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_165 ( V_142 , V_160 , V_323 , V_318 , V_89 , V_232 , type ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_346 , V_195 ) ;
}
static int F_166 ( const struct V_341 * V_89 , T_2 V_232 , T_2 type ,
const struct V_315 * V_160 , int V_323 ,
const struct V_317 * V_318 )
{
return - V_339 ;
}
static int F_168 ( struct V_141 * V_142 , struct V_143 * V_144 )
{
struct V_114 * V_114 = F_39 ( V_142 -> V_145 ) ;
struct V_4 * V_5 [ V_347 + 1 ] ;
const struct V_348 * V_349 ;
int type , V_39 ;
type = V_144 -> V_152 ;
if ( type > V_350 )
return - V_10 ;
type -= V_351 ;
V_349 = & V_352 [ type ] ;
if ( ! F_169 ( V_114 -> V_353 , V_354 ) )
return - V_166 ;
if ( ( type == ( V_355 - V_351 ) ||
type == ( V_356 - V_351 ) ) &&
( V_144 -> V_187 & V_357 ) ) {
if ( V_349 -> V_358 == NULL )
return - V_10 ;
{
struct V_359 V_147 = {
. V_358 = V_349 -> V_358 ,
. V_360 = V_349 -> V_360 ,
} ;
return F_170 ( V_114 -> V_134 . V_216 , V_142 , V_144 , & V_147 ) ;
}
}
V_39 = F_171 ( V_144 , V_361 [ type ] , V_5 , V_347 ,
V_362 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_349 -> V_363 == NULL )
return - V_10 ;
return V_349 -> V_363 ( V_142 , V_144 , V_5 ) ;
}
static void F_172 ( struct V_141 * V_142 )
{
F_173 ( & V_364 ) ;
F_174 ( V_142 , & F_168 ) ;
F_175 ( & V_364 ) ;
}
static inline T_5 F_176 ( void )
{
return F_83 ( sizeof( struct V_306 ) )
+ F_84 ( sizeof( struct V_159 ) ) ;
}
static int F_177 ( struct V_141 * V_142 , struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_306 * V_307 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , 0 , V_365 , sizeof( * V_307 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_307 = F_40 ( V_144 ) ;
F_59 ( V_88 , & V_307 -> V_139 ) ;
V_307 -> V_305 = ( V_147 -> V_286 . V_305 != 0 ) ? 1 : 0 ;
V_39 = F_67 ( V_142 , & V_88 -> V_131 ) ;
if ( V_39 )
return V_39 ;
return F_72 ( V_142 , V_144 ) ;
}
static int F_178 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_179 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_79 ( F_176 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_177 ( V_142 , V_88 , V_147 ) < 0 ) {
F_81 ( V_142 ) ;
return - V_171 ;
}
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_366 , V_195 ) ;
}
static int F_180 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_179 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_79 ( F_142 ( V_88 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_143 ( V_142 , V_88 , V_147 ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_367 , V_195 ) ;
}
static int F_181 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_288 * V_26 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_23 = F_83 ( sizeof( struct V_288 ) ) ;
V_142 = F_79 ( V_23 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_368 , sizeof( * V_26 ) , 0 ) ;
if ( V_144 == NULL ) {
F_81 ( V_142 ) ;
return - V_171 ;
}
V_26 = F_40 ( V_144 ) ;
V_26 -> V_36 = V_147 -> V_286 . V_36 ;
F_72 ( V_142 , V_144 ) ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_369 , V_195 ) ;
}
static inline T_5 F_182 ( struct V_87 * V_88 )
{
T_5 V_370 = 0 ;
if ( V_88 -> V_119 )
V_370 += F_84 ( F_1 ( V_88 -> V_119 ) ) ;
if ( V_88 -> V_121 ) {
V_370 += F_84 ( sizeof( struct V_8 ) +
( V_88 -> V_121 -> V_3 + 7 ) / 8 ) ;
V_370 += F_84 ( F_7 ( V_88 -> V_121 ) ) ;
}
if ( V_88 -> V_123 )
V_370 += F_84 ( F_5 ( V_88 -> V_123 ) ) ;
if ( V_88 -> V_125 )
V_370 += F_84 ( sizeof( * V_88 -> V_125 ) ) ;
if ( V_88 -> V_128 )
V_370 += F_84 ( sizeof( * V_88 -> V_128 ) ) ;
if ( V_88 -> V_129 )
V_370 += F_84 ( sizeof( V_88 -> V_129 ) ) ;
if ( V_88 -> V_78 )
V_370 += F_84 ( F_12 ( V_88 -> V_78 ) ) ;
if ( V_88 -> V_180 )
V_370 += F_84 ( sizeof( struct V_21 ) +
V_88 -> V_180 -> V_24 ) ;
if ( V_88 -> V_130 )
V_370 += F_84 ( sizeof( * V_88 -> V_130 ) ) ;
if ( V_88 -> V_59 . V_118 )
V_370 += F_84 ( sizeof( V_88 -> V_59 . V_118 ) ) ;
V_370 += F_84 ( sizeof( V_371 ) ) ;
return V_370 ;
}
static int F_183 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_179 ( V_88 ) ;
struct V_25 * V_26 ;
struct V_158 * V_35 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_23 = F_182 ( V_88 ) ;
int V_372 , V_39 ;
V_372 = sizeof( * V_26 ) ;
if ( V_147 -> V_157 == V_373 ) {
V_23 += F_84 ( V_372 ) ;
V_372 = sizeof( * V_35 ) ;
V_23 += F_84 ( sizeof( struct V_159 ) ) ;
}
V_23 += F_83 ( V_372 ) ;
V_142 = F_79 ( V_23 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_372 , 0 ) ;
V_39 = - V_171 ;
if ( V_144 == NULL )
goto V_374;
V_26 = F_40 ( V_144 ) ;
if ( V_147 -> V_157 == V_373 ) {
struct V_4 * V_169 ;
V_35 = F_40 ( V_144 ) ;
memcpy ( & V_35 -> V_163 , & V_88 -> V_35 . V_163 , sizeof( V_35 -> V_163 ) ) ;
V_35 -> V_164 = V_88 -> V_35 . V_164 ;
V_35 -> V_40 = V_88 -> V_59 . V_40 ;
V_35 -> V_36 = V_88 -> V_35 . V_36 ;
V_169 = F_61 ( V_142 , V_375 , sizeof( * V_26 ) ) ;
V_39 = - V_171 ;
if ( V_169 == NULL )
goto V_374;
V_26 = F_3 ( V_169 ) ;
}
V_39 = F_63 ( V_88 , V_26 , V_142 ) ;
if ( V_39 )
goto V_374;
F_72 ( V_142 , V_144 ) ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_369 , V_195 ) ;
V_374:
F_81 ( V_142 ) ;
return V_39 ;
}
static int F_184 ( struct V_87 * V_88 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_365 :
return F_178 ( V_88 , V_147 ) ;
case V_294 :
return F_180 ( V_88 , V_147 ) ;
case V_373 :
case V_376 :
case V_153 :
return F_183 ( V_88 , V_147 ) ;
case V_368 :
return F_181 ( V_147 ) ;
default:
F_185 ( V_377 L_3 ,
V_147 -> V_157 ) ;
break;
}
return 0 ;
}
static inline T_5 F_186 ( struct V_87 * V_88 ,
struct V_247 * V_249 )
{
return F_83 ( sizeof( struct V_308 ) )
+ F_84 ( sizeof( struct V_250 ) * V_249 -> V_254 )
+ F_84 ( sizeof( struct V_159 ) )
+ F_84 ( F_26 ( V_88 -> V_180 ) )
+ F_127 () ;
}
static int F_187 ( struct V_141 * V_142 , struct V_87 * V_88 ,
struct V_255 * V_378 , struct V_247 * V_249 )
{
T_7 V_133 = F_188 () ;
struct V_308 * V_309 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , 0 , 0 , V_379 , sizeof( * V_309 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_309 = F_40 ( V_144 ) ;
memcpy ( & V_309 -> V_35 , & V_88 -> V_35 , sizeof( V_309 -> V_35 ) ) ;
memcpy ( & V_309 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_309 -> V_92 ) ) ;
memcpy ( & V_309 -> V_89 , & V_88 -> V_89 , sizeof( V_309 -> V_89 ) ) ;
F_114 ( V_249 , & V_309 -> V_311 , V_234 ) ;
V_309 -> V_260 = V_378 -> V_260 ;
V_309 -> V_261 = V_378 -> V_261 ;
V_309 -> V_262 = V_378 -> V_262 ;
V_309 -> V_133 = V_88 -> V_132 . V_133 = V_133 ;
V_39 = F_124 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_125 ( V_88 , V_142 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_249 -> type , V_142 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_142 , & V_249 -> V_131 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
return F_72 ( V_142 , V_144 ) ;
}
static int F_189 ( struct V_87 * V_88 , struct V_255 * V_378 ,
struct V_247 * V_249 )
{
struct V_114 * V_114 = F_179 ( V_88 ) ;
struct V_141 * V_142 ;
V_142 = F_79 ( F_186 ( V_88 , V_249 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_187 ( V_142 , V_88 , V_378 , V_249 ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_380 , V_195 ) ;
}
static struct V_247 * F_190 ( struct V_381 * V_145 , int V_382 ,
T_2 * V_286 , int V_23 , int * V_232 )
{
struct V_114 * V_114 = F_39 ( V_145 ) ;
struct V_238 * V_26 = (struct V_238 * ) V_286 ;
struct V_250 * V_251 = (struct V_250 * ) ( V_26 + 1 ) ;
struct V_247 * V_249 ;
int V_252 ;
switch ( V_145 -> V_383 ) {
case V_41 :
if ( V_382 != V_384 ) {
* V_232 = - V_385 ;
return NULL ;
}
break;
#if F_14 ( V_43 )
case V_42 :
if ( V_382 != V_386 ) {
* V_232 = - V_385 ;
return NULL ;
}
break;
#endif
default:
* V_232 = - V_10 ;
return NULL ;
}
* V_232 = - V_10 ;
if ( V_23 < sizeof( * V_26 ) ||
F_106 ( V_26 ) )
return NULL ;
V_252 = ( ( V_23 - sizeof( * V_26 ) ) / sizeof( * V_251 ) ) ;
if ( F_110 ( V_252 , V_251 , V_26 -> V_89 . V_40 ) )
return NULL ;
if ( V_26 -> V_232 > V_234 )
return NULL ;
V_249 = F_116 ( V_114 , V_195 ) ;
if ( V_249 == NULL ) {
* V_232 = - V_387 ;
return NULL ;
}
F_113 ( V_249 , V_26 ) ;
V_249 -> type = V_236 ;
F_109 ( V_249 , V_251 , V_252 ) ;
* V_232 = V_26 -> V_232 ;
return V_249 ;
}
static inline T_5 F_191 ( struct V_247 * V_249 )
{
return F_83 ( sizeof( struct V_304 ) )
+ F_84 ( sizeof( struct V_250 ) * V_249 -> V_254 )
+ F_84 ( F_26 ( V_249 -> V_180 ) )
+ F_84 ( sizeof( struct V_159 ) )
+ F_127 () ;
}
static int F_192 ( struct V_141 * V_142 , struct V_247 * V_249 ,
int V_232 , const struct V_146 * V_147 )
{
struct V_304 * V_388 ;
int V_305 = V_147 -> V_286 . V_305 ;
struct V_143 * V_144 ;
int V_39 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , 0 , V_389 , sizeof( * V_388 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_388 = F_40 ( V_144 ) ;
F_114 ( V_249 , & V_388 -> V_248 , V_232 ) ;
V_39 = F_124 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_126 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_249 -> type , V_142 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_142 , & V_249 -> V_131 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
V_388 -> V_305 = ! ! V_305 ;
return F_72 ( V_142 , V_144 ) ;
}
static int F_193 ( struct V_247 * V_249 , int V_232 , const struct V_146 * V_147 )
{
struct V_114 * V_114 = F_194 ( V_249 ) ;
struct V_141 * V_142 ;
V_142 = F_79 ( F_191 ( V_249 ) , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_192 ( V_142 , V_249 , V_232 , V_147 ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_366 , V_195 ) ;
}
static int F_195 ( struct V_247 * V_249 , int V_232 , const struct V_146 * V_147 )
{
int V_23 = F_84 ( sizeof( struct V_250 ) * V_249 -> V_254 ) ;
struct V_114 * V_114 = F_194 ( V_249 ) ;
struct V_238 * V_26 ;
struct V_282 * V_35 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_372 , V_39 ;
V_372 = sizeof( * V_26 ) ;
if ( V_147 -> V_157 == V_284 ) {
V_23 += F_84 ( V_372 ) ;
V_372 = sizeof( * V_35 ) ;
}
V_23 += F_127 () ;
V_23 += F_84 ( sizeof( struct V_159 ) ) ;
V_23 += F_83 ( V_372 ) ;
V_142 = F_79 ( V_23 , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_147 -> V_157 , V_372 , 0 ) ;
V_39 = - V_171 ;
if ( V_144 == NULL )
goto V_374;
V_26 = F_40 ( V_144 ) ;
if ( V_147 -> V_157 == V_284 ) {
struct V_4 * V_169 ;
V_35 = F_40 ( V_144 ) ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_232 = V_232 ;
if ( V_147 -> V_286 . V_287 )
V_35 -> V_273 = V_249 -> V_273 ;
else
memcpy ( & V_35 -> V_89 , & V_249 -> V_274 , sizeof( V_35 -> V_89 ) ) ;
V_169 = F_61 ( V_142 , V_390 , sizeof( * V_26 ) ) ;
V_39 = - V_171 ;
if ( V_169 == NULL )
goto V_374;
V_26 = F_3 ( V_169 ) ;
}
F_114 ( V_249 , V_26 , V_232 ) ;
V_39 = F_124 ( V_249 , V_142 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_249 -> type , V_142 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_142 , & V_249 -> V_131 ) ;
if ( V_39 )
goto V_374;
F_72 ( V_142 , V_144 ) ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_391 , V_195 ) ;
V_374:
F_81 ( V_142 ) ;
return V_39 ;
}
static int F_196 ( const struct V_146 * V_147 )
{
struct V_114 * V_114 = V_147 -> V_114 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_79 ( F_127 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
V_144 = F_69 ( V_142 , V_147 -> V_155 , V_147 -> V_133 , V_392 , 0 , 0 ) ;
V_39 = - V_171 ;
if ( V_144 == NULL )
goto V_374;
V_39 = F_128 ( V_147 -> V_286 . type , V_142 ) ;
if ( V_39 )
goto V_374;
F_72 ( V_142 , V_144 ) ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_391 , V_195 ) ;
V_374:
F_81 ( V_142 ) ;
return V_39 ;
}
static int F_197 ( struct V_247 * V_249 , int V_232 , const struct V_146 * V_147 )
{
switch ( V_147 -> V_157 ) {
case V_277 :
case V_393 :
case V_284 :
return F_195 ( V_249 , V_232 , V_147 ) ;
case V_392 :
return F_196 ( V_147 ) ;
case V_389 :
return F_193 ( V_249 , V_232 , V_147 ) ;
default:
F_185 ( V_377 L_4 ,
V_147 -> V_157 ) ;
}
return 0 ;
}
static inline T_5 F_198 ( void )
{
return F_83 ( sizeof( struct V_394 ) ) ;
}
static int F_199 ( struct V_141 * V_142 , T_2 V_36 ,
struct V_341 * V_89 , T_1 * V_395 )
{
struct V_394 * V_396 ;
struct V_143 * V_144 ;
V_144 = F_69 ( V_142 , 0 , 0 , V_397 , sizeof( * V_396 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_396 = F_40 ( V_144 ) ;
V_396 -> V_36 = V_36 ;
memcpy ( & V_396 -> V_89 , V_89 , sizeof( V_396 -> V_89 ) ) ;
if ( V_395 ) {
int V_39 = F_65 ( V_142 , V_54 , sizeof( * V_395 ) , V_395 ) ;
if ( V_39 ) {
F_71 ( V_142 , V_144 ) ;
return V_39 ;
}
}
return F_72 ( V_142 , V_144 ) ;
}
static int F_200 ( struct V_114 * V_114 , T_2 V_36 ,
struct V_341 * V_89 , T_1 * V_395 )
{
struct V_141 * V_142 ;
V_142 = F_79 ( F_198 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_199 ( V_142 , V_36 , V_89 , V_395 ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_398 , V_195 ) ;
}
static inline T_5 F_201 ( void )
{
return F_83 ( sizeof( struct V_399 ) ) ;
}
static int F_202 ( struct V_141 * V_142 , struct V_87 * V_88 ,
T_1 * V_333 , T_8 V_400 )
{
struct V_399 * V_322 ;
struct V_143 * V_144 ;
V_144 = F_69 ( V_142 , 0 , 0 , V_401 , sizeof( * V_322 ) , 0 ) ;
if ( V_144 == NULL )
return - V_171 ;
V_322 = F_40 ( V_144 ) ;
memcpy ( & V_322 -> V_35 . V_163 , & V_88 -> V_35 . V_163 , sizeof( V_322 -> V_35 . V_163 ) ) ;
V_322 -> V_35 . V_164 = V_88 -> V_35 . V_164 ;
V_322 -> V_35 . V_40 = V_88 -> V_59 . V_40 ;
V_322 -> V_35 . V_36 = V_88 -> V_35 . V_36 ;
memcpy ( & V_322 -> V_333 , V_333 , sizeof( V_322 -> V_333 ) ) ;
memcpy ( & V_322 -> V_331 , & V_88 -> V_59 . V_92 , sizeof( V_322 -> V_331 ) ) ;
V_322 -> V_400 = V_400 ;
V_322 -> V_402 = V_88 -> V_128 -> V_403 ;
V_322 -> V_91 = V_88 -> V_59 . V_91 ;
return F_72 ( V_142 , V_144 ) ;
}
static int F_203 ( struct V_87 * V_88 , T_1 * V_404 ,
T_8 V_405 )
{
struct V_114 * V_114 = F_179 ( V_88 ) ;
struct V_141 * V_142 ;
if ( V_88 -> V_35 . V_36 != V_37 )
return - V_10 ;
if ( ! V_88 -> V_128 )
return - V_10 ;
V_142 = F_79 ( F_201 () , V_195 ) ;
if ( V_142 == NULL )
return - V_68 ;
if ( F_202 ( V_142 , V_88 , V_404 , V_405 ) < 0 )
F_88 () ;
return F_167 ( V_114 -> V_134 . V_216 , V_142 , 0 , V_406 , V_195 ) ;
}
static int T_9 F_204 ( struct V_114 * V_114 )
{
struct V_381 * V_216 ;
struct V_407 V_408 = {
. V_409 = V_410 ,
. V_411 = F_172 ,
} ;
V_216 = F_205 ( V_114 , V_412 , & V_408 ) ;
if ( V_216 == NULL )
return - V_68 ;
V_114 -> V_134 . V_413 = V_216 ;
F_206 ( V_114 -> V_134 . V_216 , V_216 ) ;
return 0 ;
}
static void T_10 F_207 ( struct V_414 * V_415 )
{
struct V_114 * V_114 ;
F_208 (net, net_exit_list, exit_list)
F_209 ( V_114 -> V_134 . V_216 , NULL ) ;
F_210 () ;
F_208 (net, net_exit_list, exit_list)
F_211 ( V_114 -> V_134 . V_413 ) ;
}
static int T_11 F_212 ( void )
{
int V_416 ;
F_185 ( V_417 L_5 ) ;
V_416 = F_213 ( & V_418 ) ;
if ( V_416 < 0 )
return V_416 ;
V_416 = F_214 ( & V_419 ) ;
if ( V_416 < 0 )
F_215 ( & V_418 ) ;
return V_416 ;
}
static void T_12 F_216 ( void )
{
F_217 ( & V_419 ) ;
F_215 ( & V_418 ) ;
}
