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
if ( ( V_39 = F_20 ( & V_88 -> V_117 , & V_88 -> V_59 . V_118 ,
V_5 [ V_18 ] ) ) )
goto error;
if ( ( V_39 = F_18 ( & V_88 -> V_119 , & V_88 -> V_59 . V_120 ,
V_5 [ V_16 ] ) ) )
goto error;
if ( ! V_88 -> V_59 . V_120 ) {
if ( ( V_39 = F_15 ( & V_88 -> V_119 , & V_88 -> V_59 . V_120 ,
V_5 [ V_11 ] ) ) )
goto error;
}
if ( ( V_39 = F_32 ( & V_88 -> V_121 , & V_88 -> V_59 . V_118 ,
V_122 ,
V_5 [ V_12 ] ) ) )
goto error;
if ( ( V_39 = F_32 ( & V_88 -> V_123 , & V_88 -> V_59 . V_124 ,
V_125 ,
V_5 [ V_13 ] ) ) )
goto error;
if ( V_5 [ V_53 ] ) {
V_88 -> V_126 = F_19 ( F_3 ( V_5 [ V_53 ] ) ,
sizeof( * V_88 -> V_126 ) , V_67 ) ;
if ( V_88 -> V_126 == NULL )
goto error;
}
if ( V_5 [ V_47 ] )
V_88 -> V_127 = F_29 ( V_5 [ V_47 ] ) ;
if ( V_5 [ V_54 ] ) {
V_88 -> V_128 = F_19 ( F_3 ( V_5 [ V_54 ] ) ,
sizeof( * V_88 -> V_128 ) , V_67 ) ;
if ( V_88 -> V_128 == NULL )
goto error;
}
F_33 ( V_5 , & V_88 -> V_129 ) ;
V_39 = F_34 ( V_88 , false ) ;
if ( V_39 )
goto error;
if ( V_5 [ V_20 ] &&
F_35 ( V_88 , F_3 ( V_5 [ V_20 ] ) ) )
goto error;
if ( ( V_39 = F_23 ( & V_88 -> V_78 , & V_88 -> V_82 ,
V_5 [ V_27 ] ) ) )
goto error;
V_88 -> V_130 . V_131 = V_26 -> V_131 ;
V_88 -> V_113 = V_114 -> V_132 . V_133 ;
V_88 -> V_112 = ( V_114 -> V_132 . V_134 * V_135 ) / V_136 ;
if ( ( V_39 = F_36 ( V_88 ) ) )
goto error;
F_28 ( V_88 , V_5 , 0 ) ;
return V_88 ;
error:
V_88 -> V_130 . V_137 = V_138 ;
F_37 ( V_88 ) ;
V_116:
* V_115 = V_39 ;
return NULL ;
}
static int F_38 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_25 * V_26 = F_40 ( V_142 ) ;
struct V_87 * V_88 ;
int V_39 ;
struct V_144 V_145 ;
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
V_39 = F_13 ( V_26 , V_5 ) ;
if ( V_39 )
return V_39 ;
V_88 = F_30 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( ! V_88 )
return V_39 ;
F_43 ( V_88 ) ;
if ( V_142 -> V_150 == V_151 )
V_39 = F_44 ( V_88 ) ;
else
V_39 = F_45 ( V_88 ) ;
F_46 ( V_147 , & V_149 ) ;
F_47 ( V_88 , V_39 ? 0 : 1 , V_146 , V_148 , V_149 ) ;
if ( V_39 < 0 ) {
V_88 -> V_130 . V_137 = V_138 ;
F_48 ( V_88 ) ;
goto V_45;
}
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
V_145 . V_155 = V_142 -> V_150 ;
F_49 ( V_88 , & V_145 ) ;
V_45:
F_37 ( V_88 ) ;
return V_39 ;
}
static struct V_87 * F_50 ( struct V_114 * V_114 ,
struct V_156 * V_26 ,
struct V_4 * * V_5 ,
int * V_115 )
{
struct V_87 * V_88 = NULL ;
struct V_157 V_158 ;
int V_39 ;
T_4 V_129 = F_33 ( V_5 , & V_158 ) ;
if ( F_51 ( V_26 -> V_36 , V_159 ) ) {
V_39 = - V_160 ;
V_88 = F_52 ( V_114 , V_129 , & V_26 -> V_161 , V_26 -> V_162 , V_26 -> V_36 , V_26 -> V_40 ) ;
} else {
T_1 * V_92 = NULL ;
F_9 ( V_5 , V_163 , & V_92 ) ;
if ( ! V_92 ) {
V_39 = - V_10 ;
goto V_45;
}
V_39 = - V_160 ;
V_88 = F_53 ( V_114 , V_129 ,
& V_26 -> V_161 , V_92 ,
V_26 -> V_36 , V_26 -> V_40 ) ;
}
V_45:
if ( ! V_88 && V_115 )
* V_115 = V_39 ;
return V_88 ;
}
static int F_54 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_87 * V_88 ;
int V_39 = - V_160 ;
struct V_144 V_145 ;
struct V_156 * V_26 = F_40 ( V_142 ) ;
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
V_88 = F_50 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( V_88 == NULL )
return V_39 ;
if ( ( V_39 = F_55 ( V_88 ) ) != 0 )
goto V_45;
if ( F_56 ( V_88 ) ) {
V_39 = - V_164 ;
goto V_45;
}
V_39 = F_57 ( V_88 ) ;
if ( V_39 < 0 )
goto V_45;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
V_145 . V_155 = V_142 -> V_150 ;
F_49 ( V_88 , & V_145 ) ;
V_45:
F_46 ( V_147 , & V_149 ) ;
F_58 ( V_88 , V_39 ? 0 : 1 , V_146 , V_148 , V_149 ) ;
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
memcpy ( & V_26 -> V_165 , & V_88 -> V_165 , sizeof( V_26 -> V_165 ) ) ;
memcpy ( & V_26 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_26 -> V_92 ) ) ;
V_26 -> V_48 = V_88 -> V_59 . V_48 ;
V_26 -> V_38 = V_88 -> V_59 . V_38 ;
V_26 -> V_91 = V_88 -> V_59 . V_91 ;
V_26 -> V_40 = V_88 -> V_59 . V_40 ;
V_26 -> V_30 = V_88 -> V_59 . V_30 ;
V_26 -> V_131 = V_88 -> V_130 . V_131 ;
}
static int F_60 ( struct V_85 * V_166 , struct V_139 * V_140 )
{
struct V_21 * V_22 ;
struct V_4 * V_167 ;
int V_168 = sizeof( * V_22 ) + V_166 -> V_24 ;
V_167 = F_61 ( V_140 , V_20 , V_168 ) ;
if ( V_167 == NULL )
return - V_169 ;
V_22 = F_3 ( V_167 ) ;
V_22 -> V_170 = V_20 ;
V_22 -> V_23 = V_168 ;
V_22 -> V_171 = V_166 -> V_171 ;
V_22 -> V_172 = V_166 -> V_172 ;
V_22 -> V_24 = V_166 -> V_24 ;
memcpy ( V_22 + 1 , V_166 -> V_173 , V_166 -> V_24 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_72 , struct V_139 * V_140 )
{
struct V_8 * V_63 ;
struct V_4 * V_174 ;
V_174 = F_61 ( V_140 , V_11 ,
sizeof( * V_63 ) + ( V_72 -> V_3 + 7 ) / 8 ) ;
if ( ! V_174 )
return - V_169 ;
V_63 = F_3 ( V_174 ) ;
strncpy ( V_63 -> V_14 , V_72 -> V_14 , sizeof( V_63 -> V_14 ) ) ;
memcpy ( V_63 -> V_74 , V_72 -> V_74 , ( V_72 -> V_3 + 7 ) / 8 ) ;
V_63 -> V_3 = V_72 -> V_3 ;
return 0 ;
}
static int F_63 ( struct V_87 * V_88 ,
struct V_25 * V_26 ,
struct V_139 * V_140 )
{
int V_175 = 0 ;
F_59 ( V_88 , V_26 ) ;
if ( V_88 -> V_128 ) {
V_175 = F_64 ( V_140 , V_54 , sizeof( * V_88 -> V_128 ) , V_88 -> V_128 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_176 ) {
V_175 = F_65 ( V_140 , V_177 , V_88 -> V_176 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_117 ) {
V_175 = F_64 ( V_140 , V_18 , F_1 ( V_88 -> V_117 ) , V_88 -> V_117 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_119 ) {
V_175 = F_62 ( V_88 -> V_119 , V_140 ) ;
if ( ! V_175 )
V_175 = F_64 ( V_140 , V_16 ,
F_7 ( V_88 -> V_119 ) , V_88 -> V_119 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_121 ) {
V_175 = F_64 ( V_140 , V_12 , F_5 ( V_88 -> V_121 ) , V_88 -> V_121 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_123 ) {
V_175 = F_64 ( V_140 , V_13 , sizeof( * ( V_88 -> V_123 ) ) , V_88 -> V_123 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_126 ) {
V_175 = F_64 ( V_140 , V_53 , sizeof( * V_88 -> V_126 ) , V_88 -> V_126 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_127 ) {
V_175 = F_66 ( V_140 , V_47 , V_88 -> V_127 ) ;
if ( V_175 )
goto V_45;
}
V_175 = F_67 ( V_140 , & V_88 -> V_129 ) ;
if ( V_175 )
goto V_45;
if ( V_88 -> V_78 ) {
V_175 = F_64 ( V_140 , V_27 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
if ( V_175 )
goto V_45;
}
if ( V_88 -> V_178 )
V_175 = F_60 ( V_88 -> V_178 , V_140 ) ;
V_45:
return V_175 ;
}
static int F_68 ( struct V_87 * V_88 , int V_179 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_139 * V_183 = V_182 -> V_183 ;
struct V_139 * V_140 = V_182 -> V_184 ;
struct V_25 * V_26 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , F_70 ( V_183 ) . V_153 , V_182 -> V_152 ,
V_151 , sizeof( * V_26 ) , V_182 -> V_185 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_26 = F_40 ( V_142 ) ;
V_39 = F_63 ( V_88 , V_26 , V_140 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
F_72 ( V_140 , V_142 ) ;
return 0 ;
}
static int F_73 ( struct V_186 * V_187 )
{
struct V_188 * V_189 = (struct V_188 * ) & V_187 -> args [ 1 ] ;
F_74 ( V_189 ) ;
return 0 ;
}
static int F_75 ( struct V_139 * V_140 , struct V_186 * V_187 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_188 * V_189 = (struct V_188 * ) & V_187 -> args [ 1 ] ;
struct V_181 V_190 ;
F_76 ( sizeof( struct V_188 ) >
sizeof( V_187 -> args ) - sizeof( V_187 -> args [ 0 ] ) ) ;
V_190 . V_183 = V_187 -> V_140 ;
V_190 . V_184 = V_140 ;
V_190 . V_152 = V_187 -> V_142 -> V_152 ;
V_190 . V_185 = V_191 ;
if ( ! V_187 -> args [ 0 ] ) {
V_187 -> args [ 0 ] = 1 ;
F_77 ( V_189 , 0 ) ;
}
( void ) V_188 ( V_114 , V_189 , F_68 , & V_190 ) ;
return V_140 -> V_23 ;
}
static struct V_139 * F_78 ( struct V_139 * V_183 ,
struct V_87 * V_88 , T_4 V_131 )
{
struct V_181 V_190 ;
struct V_139 * V_140 ;
int V_39 ;
V_140 = F_79 ( V_192 , V_193 ) ;
if ( ! V_140 )
return F_80 ( - V_68 ) ;
V_190 . V_183 = V_183 ;
V_190 . V_184 = V_140 ;
V_190 . V_152 = V_131 ;
V_190 . V_185 = 0 ;
V_39 = F_68 ( V_88 , 0 , & V_190 ) ;
if ( V_39 ) {
F_81 ( V_140 ) ;
return F_80 ( V_39 ) ;
}
return V_140 ;
}
static inline T_5 F_82 ( void )
{
return F_83 ( 4 )
+ F_84 ( sizeof( struct V_194 ) )
+ F_84 ( sizeof( struct V_195 ) ) ;
}
static int F_85 ( struct V_139 * V_140 , struct V_114 * V_114 ,
T_4 V_153 , T_4 V_131 , T_4 V_30 )
{
struct V_196 V_197 ;
struct V_194 V_198 ;
struct V_195 V_199 ;
struct V_141 * V_142 ;
int V_39 ;
T_4 * V_200 ;
V_142 = F_69 ( V_140 , V_153 , V_131 , V_201 , sizeof( T_4 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_200 = F_40 ( V_142 ) ;
* V_200 = V_30 ;
F_86 ( V_114 , & V_197 ) ;
V_198 . V_202 = V_197 . V_202 ;
V_198 . V_203 = V_197 . V_203 ;
V_198 . V_204 = V_197 . V_204 ;
V_198 . V_205 = V_197 . V_205 ;
V_198 . V_206 = V_197 . V_206 ;
V_198 . V_207 = V_197 . V_207 ;
V_199 . V_208 = V_197 . V_208 ;
V_199 . V_209 = V_197 . V_209 ;
V_39 = F_64 ( V_140 , V_210 , sizeof( V_198 ) , & V_198 ) ;
if ( ! V_39 )
V_39 = F_64 ( V_140 , V_211 , sizeof( V_199 ) , & V_199 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
return F_72 ( V_140 , V_142 ) ;
}
static int F_87 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_139 * V_212 ;
T_4 * V_30 = F_40 ( V_142 ) ;
T_4 V_213 = F_70 ( V_140 ) . V_153 ;
T_4 V_131 = V_142 -> V_152 ;
V_212 = F_79 ( F_82 () , V_193 ) ;
if ( V_212 == NULL )
return - V_68 ;
if ( F_85 ( V_212 , V_114 , V_213 , V_131 , * V_30 ) < 0 )
F_88 () ;
return F_89 ( V_114 -> V_132 . V_214 , V_212 , V_213 ) ;
}
static inline T_5 F_90 ( void )
{
return F_83 ( 4 )
+ F_84 ( sizeof( struct V_215 ) )
+ F_84 ( 4 ) ;
}
static int F_91 ( struct V_139 * V_140 , struct V_114 * V_114 ,
T_4 V_153 , T_4 V_131 , T_4 V_30 )
{
struct V_216 V_197 ;
struct V_215 V_217 ;
struct V_141 * V_142 ;
int V_39 ;
T_4 * V_200 ;
V_142 = F_69 ( V_140 , V_153 , V_131 , V_218 , sizeof( T_4 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_200 = F_40 ( V_142 ) ;
* V_200 = V_30 ;
F_92 ( V_114 , & V_197 ) ;
V_217 . V_219 = V_197 . V_219 ;
V_217 . V_220 = V_197 . V_220 ;
V_39 = F_66 ( V_140 , V_221 , V_197 . V_222 ) ;
if ( ! V_39 )
V_39 = F_64 ( V_140 , V_223 , sizeof( V_217 ) , & V_217 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
return F_72 ( V_140 , V_142 ) ;
}
static int F_93 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_139 * V_212 ;
T_4 * V_30 = F_40 ( V_142 ) ;
T_4 V_213 = F_70 ( V_140 ) . V_153 ;
T_4 V_131 = V_142 -> V_152 ;
V_212 = F_79 ( F_90 () , V_193 ) ;
if ( V_212 == NULL )
return - V_68 ;
if ( F_91 ( V_212 , V_114 , V_213 , V_131 , * V_30 ) < 0 )
F_88 () ;
return F_89 ( V_114 -> V_132 . V_214 , V_212 , V_213 ) ;
}
static int F_94 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_156 * V_26 = F_40 ( V_142 ) ;
struct V_87 * V_88 ;
struct V_139 * V_224 ;
int V_39 = - V_160 ;
V_88 = F_50 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( V_88 == NULL )
goto V_225;
V_224 = F_78 ( V_140 , V_88 , V_142 -> V_152 ) ;
if ( F_95 ( V_224 ) ) {
V_39 = F_96 ( V_224 ) ;
} else {
V_39 = F_89 ( V_114 -> V_132 . V_214 , V_224 , F_70 ( V_140 ) . V_153 ) ;
}
F_37 ( V_88 ) ;
V_225:
return V_39 ;
}
static int F_97 ( struct V_226 * V_26 )
{
switch ( V_26 -> V_190 . V_35 . V_36 ) {
case V_46 :
case V_37 :
break;
case V_50 :
if ( V_26 -> V_227 >= 0x10000 )
return - V_10 ;
break;
default:
return - V_10 ;
}
if ( V_26 -> V_228 > V_26 -> V_227 )
return - V_10 ;
return 0 ;
}
static int F_98 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_87 * V_88 ;
struct V_226 * V_26 ;
struct V_139 * V_224 ;
T_1 * V_161 ;
int V_40 ;
int V_39 ;
T_4 V_129 ;
struct V_157 V_158 ;
V_26 = F_40 ( V_142 ) ;
V_39 = F_97 ( V_26 ) ;
if ( V_39 )
goto V_225;
V_40 = V_26 -> V_190 . V_40 ;
V_161 = & V_26 -> V_190 . V_35 . V_161 ;
V_88 = NULL ;
V_129 = F_33 ( V_5 , & V_158 ) ;
if ( V_26 -> V_190 . V_131 ) {
V_88 = F_99 ( V_114 , V_129 , V_26 -> V_190 . V_131 ) ;
if ( V_88 && F_100 ( & V_88 -> V_35 . V_161 , V_161 , V_40 ) ) {
F_37 ( V_88 ) ;
V_88 = NULL ;
}
}
if ( ! V_88 )
V_88 = F_101 ( V_114 , & V_158 , V_26 -> V_190 . V_48 , V_26 -> V_190 . V_91 ,
V_26 -> V_190 . V_35 . V_36 , V_161 ,
& V_26 -> V_190 . V_92 , 1 ,
V_40 ) ;
V_39 = - V_229 ;
if ( V_88 == NULL )
goto V_225;
V_39 = F_102 ( V_88 , V_26 -> V_228 , V_26 -> V_227 ) ;
if ( V_39 )
goto V_45;
V_224 = F_78 ( V_140 , V_88 , V_142 -> V_152 ) ;
if ( F_95 ( V_224 ) ) {
V_39 = F_96 ( V_224 ) ;
goto V_45;
}
V_39 = F_89 ( V_114 -> V_132 . V_214 , V_224 , F_70 ( V_140 ) . V_153 ) ;
V_45:
F_37 ( V_88 ) ;
V_225:
return V_39 ;
}
static int F_103 ( T_2 V_230 )
{
switch ( V_230 ) {
case V_231 :
case V_232 :
case V_233 :
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_104 ( T_2 type )
{
switch ( type ) {
case V_234 :
#ifdef F_105
case V_235 :
#endif
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_106 ( struct V_236 * V_26 )
{
switch ( V_26 -> V_237 ) {
case V_238 :
case V_239 :
case V_240 :
case V_241 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_242 ) {
case V_243 :
case V_244 :
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
return F_103 ( V_26 -> V_230 ) ;
}
static int F_107 ( struct V_245 * V_246 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_21 * V_22 ;
if ( ! V_7 )
return 0 ;
V_22 = F_3 ( V_7 ) ;
return F_108 ( & V_246 -> V_178 , V_22 ) ;
}
static void F_109 ( struct V_245 * V_247 , struct V_248 * V_249 ,
int V_250 )
{
int V_251 ;
V_247 -> V_252 = V_250 ;
for ( V_251 = 0 ; V_251 < V_250 ; V_251 ++ , V_249 ++ ) {
struct V_253 * V_254 = & V_247 -> V_255 [ V_251 ] ;
memcpy ( & V_254 -> V_35 , & V_249 -> V_35 , sizeof( struct V_256 ) ) ;
memcpy ( & V_254 -> V_92 , & V_249 -> V_92 ,
sizeof( T_1 ) ) ;
V_254 -> V_91 = V_249 -> V_91 ;
V_254 -> V_48 = V_249 -> V_48 ;
V_254 -> V_237 = V_249 -> V_237 ;
V_254 -> V_257 = V_249 -> V_257 ;
V_254 -> V_258 = V_249 -> V_258 ;
V_254 -> V_259 = V_249 -> V_259 ;
V_254 -> V_260 = V_249 -> V_260 ;
V_254 -> V_261 = ! ~ ( V_254 -> V_258 & V_254 -> V_259 & V_254 -> V_260 ) ;
V_254 -> V_262 = V_249 -> V_40 ;
}
}
static int F_110 ( int V_250 , struct V_248 * V_249 , T_6 V_40 )
{
int V_251 ;
if ( V_250 > V_263 )
return - V_10 ;
for ( V_251 = 0 ; V_251 < V_250 ; V_251 ++ ) {
if ( ! V_249 [ V_251 ] . V_40 )
V_249 [ V_251 ] . V_40 = V_40 ;
switch ( V_249 [ V_251 ] . V_40 ) {
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
static int F_111 ( struct V_245 * V_246 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_264 ] ;
if ( ! V_7 ) {
V_246 -> V_252 = 0 ;
} else {
struct V_248 * V_265 = F_3 ( V_7 ) ;
int V_250 = F_4 ( V_7 ) / sizeof( * V_265 ) ;
int V_39 ;
V_39 = F_110 ( V_250 , V_265 , V_246 -> V_40 ) ;
if ( V_39 )
return V_39 ;
F_109 ( V_246 , V_265 , V_250 ) ;
}
return 0 ;
}
static int F_112 ( T_2 * V_266 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_267 ] ;
struct V_268 * V_269 ;
T_2 type = V_234 ;
int V_39 ;
if ( V_7 ) {
V_269 = F_3 ( V_7 ) ;
type = V_269 -> type ;
}
V_39 = F_104 ( type ) ;
if ( V_39 )
return V_39 ;
* V_266 = type ;
return 0 ;
}
static void F_113 ( struct V_245 * V_247 , struct V_236 * V_26 )
{
V_247 -> V_270 = V_26 -> V_270 ;
V_247 -> V_271 = V_26 -> V_271 ;
memcpy ( & V_247 -> V_272 , & V_26 -> V_89 , sizeof( V_247 -> V_272 ) ) ;
memcpy ( & V_247 -> V_90 , & V_26 -> V_90 , sizeof( V_247 -> V_90 ) ) ;
V_247 -> V_242 = V_26 -> V_242 ;
V_247 -> V_30 = V_26 -> V_30 ;
V_247 -> V_40 = V_26 -> V_89 . V_40 ;
}
static void F_114 ( struct V_245 * V_247 , struct V_236 * V_26 , int V_230 )
{
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
memcpy ( & V_26 -> V_89 , & V_247 -> V_272 , sizeof( V_26 -> V_89 ) ) ;
memcpy ( & V_26 -> V_90 , & V_247 -> V_90 , sizeof( V_26 -> V_90 ) ) ;
memcpy ( & V_26 -> V_107 , & V_247 -> V_107 , sizeof( V_26 -> V_107 ) ) ;
V_26 -> V_270 = V_247 -> V_270 ;
V_26 -> V_271 = V_247 -> V_271 ;
V_26 -> V_89 . V_40 = V_247 -> V_40 ;
V_26 -> V_230 = V_230 ;
V_26 -> V_242 = V_247 -> V_242 ;
V_26 -> V_30 = V_247 -> V_30 ;
V_26 -> V_237 = V_238 ;
}
static struct V_245 * F_115 ( struct V_114 * V_114 , struct V_236 * V_26 , struct V_4 * * V_5 , int * V_115 )
{
struct V_245 * V_247 = F_116 ( V_114 , V_67 ) ;
int V_39 ;
if ( ! V_247 ) {
* V_115 = - V_68 ;
return NULL ;
}
F_113 ( V_247 , V_26 ) ;
V_39 = F_112 ( & V_247 -> type , V_5 ) ;
if ( V_39 )
goto error;
if ( ! ( V_39 = F_111 ( V_247 , V_5 ) ) )
V_39 = F_107 ( V_247 , V_5 ) ;
if ( V_39 )
goto error;
F_33 ( V_5 , & V_247 -> V_129 ) ;
return V_247 ;
error:
* V_115 = V_39 ;
V_247 -> V_189 . V_273 = 1 ;
F_117 ( V_247 ) ;
return NULL ;
}
static int F_118 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_236 * V_26 = F_40 ( V_142 ) ;
struct V_245 * V_247 ;
struct V_144 V_145 ;
int V_39 ;
int V_274 ;
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
V_39 = F_106 ( V_26 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_247 = F_115 ( V_114 , V_26 , V_5 , & V_39 ) ;
if ( ! V_247 )
return V_39 ;
V_274 = V_142 -> V_150 == V_275 ;
V_39 = F_119 ( V_26 -> V_230 , V_247 , V_274 ) ;
F_46 ( V_147 , & V_149 ) ;
F_120 ( V_247 , V_39 ? 0 : 1 , V_146 , V_148 , V_149 ) ;
if ( V_39 ) {
F_121 ( V_247 -> V_178 ) ;
F_25 ( V_247 ) ;
return V_39 ;
}
V_145 . V_155 = V_142 -> V_150 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
F_122 ( V_247 , V_26 -> V_230 , & V_145 ) ;
F_123 ( V_247 ) ;
return 0 ;
}
static int F_124 ( struct V_245 * V_247 , struct V_139 * V_140 )
{
struct V_248 V_276 [ V_263 ] ;
int V_251 ;
if ( V_247 -> V_252 == 0 )
return 0 ;
for ( V_251 = 0 ; V_251 < V_247 -> V_252 ; V_251 ++ ) {
struct V_248 * V_80 = & V_276 [ V_251 ] ;
struct V_253 * V_277 = & V_247 -> V_255 [ V_251 ] ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( & V_80 -> V_35 , & V_277 -> V_35 , sizeof( V_80 -> V_35 ) ) ;
V_80 -> V_40 = V_277 -> V_262 ;
memcpy ( & V_80 -> V_92 , & V_277 -> V_92 , sizeof( V_80 -> V_92 ) ) ;
V_80 -> V_91 = V_277 -> V_91 ;
V_80 -> V_48 = V_277 -> V_48 ;
V_80 -> V_237 = V_277 -> V_237 ;
V_80 -> V_257 = V_277 -> V_257 ;
V_80 -> V_258 = V_277 -> V_258 ;
V_80 -> V_259 = V_277 -> V_259 ;
V_80 -> V_260 = V_277 -> V_260 ;
}
return F_64 ( V_140 , V_264 ,
sizeof( struct V_248 ) * V_247 -> V_252 , V_276 ) ;
}
static inline int F_125 ( struct V_87 * V_88 , struct V_139 * V_140 )
{
if ( V_88 -> V_178 ) {
return F_60 ( V_88 -> V_178 , V_140 ) ;
}
return 0 ;
}
static inline int F_126 ( struct V_245 * V_247 , struct V_139 * V_140 )
{
if ( V_247 -> V_178 )
return F_60 ( V_247 -> V_178 , V_140 ) ;
return 0 ;
}
static inline T_5 F_127 ( void )
{
#ifdef F_105
return F_84 ( sizeof( struct V_268 ) ) ;
#else
return 0 ;
#endif
}
static int F_128 ( T_2 type , struct V_139 * V_140 )
{
struct V_268 V_269 = {
. type = type ,
} ;
return F_64 ( V_140 , V_267 , sizeof( V_269 ) , & V_269 ) ;
}
static inline int F_128 ( T_2 type , struct V_139 * V_140 )
{
return 0 ;
}
static int F_129 ( struct V_245 * V_247 , int V_230 , int V_179 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_236 * V_26 ;
struct V_139 * V_183 = V_182 -> V_183 ;
struct V_139 * V_140 = V_182 -> V_184 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , F_70 ( V_183 ) . V_153 , V_182 -> V_152 ,
V_275 , sizeof( * V_26 ) , V_182 -> V_185 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_26 = F_40 ( V_142 ) ;
F_114 ( V_247 , V_26 , V_230 ) ;
V_39 = F_124 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_126 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_247 -> type , V_140 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_140 , & V_247 -> V_129 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
F_72 ( V_140 , V_142 ) ;
return 0 ;
}
static int F_130 ( struct V_186 * V_187 )
{
struct V_278 * V_189 = (struct V_278 * ) & V_187 -> args [ 1 ] ;
F_131 ( V_189 ) ;
return 0 ;
}
static int F_132 ( struct V_139 * V_140 , struct V_186 * V_187 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_278 * V_189 = (struct V_278 * ) & V_187 -> args [ 1 ] ;
struct V_181 V_190 ;
F_76 ( sizeof( struct V_278 ) >
sizeof( V_187 -> args ) - sizeof( V_187 -> args [ 0 ] ) ) ;
V_190 . V_183 = V_187 -> V_140 ;
V_190 . V_184 = V_140 ;
V_190 . V_152 = V_187 -> V_142 -> V_152 ;
V_190 . V_185 = V_191 ;
if ( ! V_187 -> args [ 0 ] ) {
V_187 -> args [ 0 ] = 1 ;
F_133 ( V_189 , V_279 ) ;
}
( void ) V_278 ( V_114 , V_189 , F_129 , & V_190 ) ;
return V_140 -> V_23 ;
}
static struct V_139 * F_134 ( struct V_139 * V_183 ,
struct V_245 * V_247 ,
int V_230 , T_4 V_131 )
{
struct V_181 V_190 ;
struct V_139 * V_140 ;
int V_39 ;
V_140 = F_79 ( V_192 , V_67 ) ;
if ( ! V_140 )
return F_80 ( - V_68 ) ;
V_190 . V_183 = V_183 ;
V_190 . V_184 = V_140 ;
V_190 . V_152 = V_131 ;
V_190 . V_185 = 0 ;
V_39 = F_129 ( V_247 , V_230 , 0 , & V_190 ) ;
if ( V_39 ) {
F_81 ( V_140 ) ;
return F_80 ( V_39 ) ;
}
return V_140 ;
}
static int F_135 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_245 * V_247 ;
struct V_280 * V_26 ;
T_2 type = V_234 ;
int V_39 ;
struct V_144 V_145 ;
int V_281 ;
struct V_157 V_158 ;
T_4 V_129 = F_33 ( V_5 , & V_158 ) ;
V_26 = F_40 ( V_142 ) ;
V_281 = V_142 -> V_150 == V_282 ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_103 ( V_26 -> V_230 ) ;
if ( V_39 )
return V_39 ;
if ( V_26 -> V_271 )
V_247 = F_136 ( V_114 , V_129 , type , V_26 -> V_230 , V_26 -> V_271 , V_281 , & V_39 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_85 * V_283 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_283 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_39 = F_108 ( & V_283 , V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_247 = F_137 ( V_114 , V_129 , type , V_26 -> V_230 , & V_26 -> V_89 ,
V_283 , V_281 , & V_39 ) ;
F_121 ( V_283 ) ;
}
if ( V_247 == NULL )
return - V_229 ;
if ( ! V_281 ) {
struct V_139 * V_224 ;
V_224 = F_134 ( V_140 , V_247 , V_26 -> V_230 , V_142 -> V_152 ) ;
if ( F_95 ( V_224 ) ) {
V_39 = F_96 ( V_224 ) ;
} else {
V_39 = F_89 ( V_114 -> V_132 . V_214 , V_224 ,
F_70 ( V_140 ) . V_153 ) ;
}
} else {
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
F_46 ( V_147 , & V_149 ) ;
F_138 ( V_247 , V_39 ? 0 : 1 , V_146 , V_148 ,
V_149 ) ;
if ( V_39 != 0 )
goto V_45;
V_145 . V_284 . V_285 = V_26 -> V_271 ;
V_145 . V_155 = V_142 -> V_150 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
F_122 ( V_247 , V_26 -> V_230 , & V_145 ) ;
}
V_45:
F_123 ( V_247 ) ;
return V_39 ;
}
static int F_139 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_144 V_145 ;
struct V_286 * V_26 = F_40 ( V_142 ) ;
struct V_287 V_288 ;
int V_39 ;
V_288 . V_146 = F_41 ( V_147 ) ;
V_288 . V_148 = F_42 ( V_147 ) ;
F_46 ( V_147 , & V_288 . V_289 ) ;
V_39 = F_140 ( V_114 , V_26 -> V_36 , & V_288 ) ;
if ( V_39 ) {
if ( V_39 == - V_160 )
return 0 ;
return V_39 ;
}
V_145 . V_284 . V_36 = V_26 -> V_36 ;
V_145 . V_155 = V_142 -> V_150 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
V_145 . V_114 = V_114 ;
F_49 ( NULL , & V_145 ) ;
return 0 ;
}
static inline T_5 F_141 ( struct V_87 * V_88 )
{
T_5 V_290 = V_88 -> V_78 ?
F_12 ( V_88 -> V_78 ) :
sizeof( struct V_102 ) ;
return F_83 ( sizeof( struct V_291 ) )
+ F_84 ( V_290 )
+ F_84 ( sizeof( struct V_105 ) )
+ F_84 ( sizeof( struct V_157 ) )
+ F_84 ( 4 )
+ F_84 ( 4 ) ;
}
static int F_142 ( struct V_139 * V_140 , struct V_87 * V_88 , const struct V_144 * V_145 )
{
struct V_291 * V_35 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , V_145 -> V_131 , V_292 , sizeof( * V_35 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_35 = F_40 ( V_142 ) ;
memcpy ( & V_35 -> V_293 . V_161 , & V_88 -> V_35 . V_161 , sizeof( V_88 -> V_35 . V_161 ) ) ;
V_35 -> V_293 . V_162 = V_88 -> V_35 . V_162 ;
V_35 -> V_293 . V_40 = V_88 -> V_59 . V_40 ;
V_35 -> V_293 . V_36 = V_88 -> V_35 . V_36 ;
memcpy ( & V_35 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_88 -> V_59 . V_92 ) ) ;
V_35 -> V_91 = V_88 -> V_59 . V_91 ;
V_35 -> V_30 = V_145 -> V_284 . V_294 ;
if ( V_88 -> V_78 ) {
V_39 = F_64 ( V_140 , V_27 ,
F_12 ( V_88 -> V_78 ) ,
V_88 -> V_78 ) ;
} else {
V_39 = F_64 ( V_140 , V_95 , sizeof( V_88 -> V_103 ) ,
& V_88 -> V_103 ) ;
}
if ( V_39 )
goto V_295;
V_39 = F_64 ( V_140 , V_98 , sizeof( V_88 -> V_107 ) , & V_88 -> V_107 ) ;
if ( V_39 )
goto V_295;
if ( V_35 -> V_30 & V_296 ) {
V_39 = F_66 ( V_140 , V_101 , V_88 -> V_113 ) ;
if ( V_39 )
goto V_295;
}
if ( V_35 -> V_30 & V_297 ) {
V_39 = F_66 ( V_140 , V_100 ,
V_88 -> V_112 * 10 / V_135 ) ;
if ( V_39 )
goto V_295;
}
V_39 = F_67 ( V_140 , & V_88 -> V_129 ) ;
if ( V_39 )
goto V_295;
return F_72 ( V_140 , V_142 ) ;
V_295:
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
static int F_143 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_87 * V_88 ;
struct V_139 * V_212 ;
int V_39 ;
struct V_144 V_145 ;
T_4 V_129 ;
struct V_157 V_158 ;
struct V_291 * V_26 = F_40 ( V_142 ) ;
struct V_156 * V_35 = & V_26 -> V_293 ;
V_129 = F_33 ( V_5 , & V_158 ) ;
V_88 = F_52 ( V_114 , V_129 , & V_35 -> V_161 , V_35 -> V_162 , V_35 -> V_36 , V_35 -> V_40 ) ;
if ( V_88 == NULL )
return - V_160 ;
V_212 = F_79 ( F_141 ( V_88 ) , V_193 ) ;
if ( V_212 == NULL ) {
F_37 ( V_88 ) ;
return - V_68 ;
}
F_144 ( & V_88 -> V_298 ) ;
V_145 . V_284 . V_294 = V_26 -> V_30 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
if ( F_142 ( V_212 , V_88 , & V_145 ) < 0 )
F_88 () ;
V_39 = F_89 ( V_114 -> V_132 . V_214 , V_212 , F_70 ( V_140 ) . V_153 ) ;
F_145 ( & V_88 -> V_298 ) ;
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_146 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_87 * V_88 ;
struct V_144 V_145 ;
int V_39 = - V_10 ;
T_4 V_129 = 0 ;
struct V_157 V_158 ;
struct V_291 * V_26 = F_40 ( V_142 ) ;
struct V_4 * V_79 = V_5 [ V_95 ] ;
struct V_4 * V_96 = V_5 [ V_27 ] ;
struct V_4 * V_97 = V_5 [ V_98 ] ;
if ( ! V_97 && ! V_79 && ! V_96 )
return V_39 ;
if ( ! ( V_142 -> V_185 & V_299 ) )
return V_39 ;
V_129 = F_33 ( V_5 , & V_158 ) ;
V_88 = F_52 ( V_114 , V_129 , & V_26 -> V_293 . V_161 , V_26 -> V_293 . V_162 , V_26 -> V_293 . V_36 , V_26 -> V_293 . V_40 ) ;
if ( V_88 == NULL )
return - V_160 ;
if ( V_88 -> V_130 . V_137 != V_300 )
goto V_45;
V_39 = F_22 ( V_88 -> V_78 , V_79 ) ;
if ( V_39 )
goto V_45;
F_144 ( & V_88 -> V_298 ) ;
F_28 ( V_88 , V_5 , 1 ) ;
F_145 ( & V_88 -> V_298 ) ;
V_145 . V_155 = V_142 -> V_150 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
V_145 . V_284 . V_294 = V_301 ;
F_49 ( V_88 , & V_145 ) ;
V_39 = 0 ;
V_45:
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_147 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_144 V_145 ;
T_2 type = V_234 ;
int V_39 ;
struct V_287 V_288 ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_288 . V_146 = F_41 ( V_147 ) ;
V_288 . V_148 = F_42 ( V_147 ) ;
F_46 ( V_147 , & V_288 . V_289 ) ;
V_39 = F_148 ( V_114 , type , & V_288 ) ;
if ( V_39 ) {
if ( V_39 == - V_160 )
return 0 ;
return V_39 ;
}
V_145 . V_284 . type = type ;
V_145 . V_155 = V_142 -> V_150 ;
V_145 . V_131 = V_142 -> V_152 ;
V_145 . V_153 = V_142 -> V_154 ;
V_145 . V_114 = V_114 ;
F_122 ( NULL , 0 , & V_145 ) ;
return 0 ;
}
static int F_149 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_245 * V_247 ;
struct V_302 * V_80 = F_40 ( V_142 ) ;
struct V_236 * V_26 = & V_80 -> V_246 ;
T_2 type = V_234 ;
int V_39 = - V_229 ;
struct V_157 V_158 ;
T_4 V_129 = F_33 ( V_5 , & V_158 ) ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_103 ( V_26 -> V_230 ) ;
if ( V_39 )
return V_39 ;
if ( V_26 -> V_271 )
V_247 = F_136 ( V_114 , V_129 , type , V_26 -> V_230 , V_26 -> V_271 , 0 , & V_39 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_85 * V_283 ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_283 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_39 = F_108 ( & V_283 , V_22 ) ;
if ( V_39 )
return V_39 ;
}
V_247 = F_137 ( V_114 , V_129 , type , V_26 -> V_230 ,
& V_26 -> V_89 , V_283 , 0 , & V_39 ) ;
F_121 ( V_283 ) ;
}
if ( V_247 == NULL )
return - V_229 ;
if ( F_150 ( V_247 -> V_189 . V_273 ) )
goto V_45;
V_39 = 0 ;
if ( V_80 -> V_303 ) {
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
F_46 ( V_147 , & V_149 ) ;
F_151 ( V_247 , V_26 -> V_230 ) ;
F_138 ( V_247 , 1 , V_146 , V_148 , V_149 ) ;
} else {
F_152 ( 1 , L_1 ) ;
}
F_153 ( V_247 , V_26 -> V_230 , V_80 -> V_303 , V_142 -> V_154 ) ;
V_45:
F_123 ( V_247 ) ;
return V_39 ;
}
static int F_154 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_87 * V_88 ;
int V_39 ;
struct V_304 * V_305 = F_40 ( V_142 ) ;
struct V_25 * V_26 = & V_305 -> V_137 ;
struct V_157 V_158 ;
T_4 V_129 = F_33 ( V_5 , & V_158 ) ;
V_88 = F_52 ( V_114 , V_129 , & V_26 -> V_35 . V_161 , V_26 -> V_35 . V_162 , V_26 -> V_35 . V_36 , V_26 -> V_40 ) ;
V_39 = - V_229 ;
if ( V_88 == NULL )
return V_39 ;
F_144 ( & V_88 -> V_298 ) ;
V_39 = - V_10 ;
if ( V_88 -> V_130 . V_137 != V_300 )
goto V_45;
F_155 ( V_88 , V_305 -> V_303 , V_142 -> V_154 ) ;
if ( V_305 -> V_303 ) {
T_3 V_146 = F_41 ( V_147 ) ;
T_4 V_148 = F_42 ( V_147 ) ;
T_4 V_149 ;
F_46 ( V_147 , & V_149 ) ;
F_156 ( V_88 ) ;
F_58 ( V_88 , 1 , V_146 , V_148 , V_149 ) ;
}
V_39 = 0 ;
V_45:
F_145 ( & V_88 -> V_298 ) ;
F_37 ( V_88 ) ;
return V_39 ;
}
static int F_157 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_245 * V_247 ;
struct V_248 * V_249 ;
int V_251 ;
struct V_4 * V_7 = V_5 [ V_264 ] ;
struct V_157 V_129 ;
struct V_306 * V_307 = F_40 ( V_142 ) ;
struct V_87 * V_88 = F_31 ( V_114 ) ;
int V_39 = - V_68 ;
if ( ! V_88 )
goto V_308;
F_33 ( V_5 , & V_129 ) ;
V_39 = F_106 ( & V_307 -> V_309 ) ;
if ( V_39 )
goto V_310;
V_247 = F_115 ( V_114 , & V_307 -> V_309 , V_5 , & V_39 ) ;
if ( ! V_247 )
goto V_311;
memcpy ( & V_88 -> V_35 , & V_307 -> V_35 , sizeof( V_307 -> V_35 ) ) ;
memcpy ( & V_88 -> V_59 . V_92 , & V_307 -> V_92 , sizeof( V_307 -> V_92 ) ) ;
memcpy ( & V_88 -> V_89 , & V_307 -> V_89 , sizeof( V_307 -> V_89 ) ) ;
V_247 -> V_129 . V_158 = V_88 -> V_129 . V_158 = V_129 . V_158 ;
V_247 -> V_129 . V_312 = V_88 -> V_129 . V_312 = V_129 . V_312 ;
V_249 = F_3 ( V_7 ) ;
for ( V_251 = 0 ; V_251 < V_247 -> V_252 ; V_251 ++ , V_249 ++ ) {
struct V_253 * V_254 = & V_247 -> V_255 [ V_251 ] ;
memcpy ( & V_88 -> V_35 , & V_254 -> V_35 , sizeof( V_88 -> V_35 ) ) ;
V_88 -> V_59 . V_48 = V_254 -> V_48 ;
V_88 -> V_59 . V_91 = V_254 -> V_91 ;
V_88 -> V_59 . V_40 = V_249 -> V_40 ;
V_254 -> V_258 = V_307 -> V_258 ;
V_254 -> V_259 = V_307 -> V_259 ;
V_254 -> V_260 = V_307 -> V_260 ;
V_39 = F_158 ( V_88 , V_254 , V_247 ) ;
}
F_25 ( V_88 ) ;
F_25 ( V_247 ) ;
return 0 ;
V_310:
F_152 ( 1 , L_2 ) ;
V_311:
F_25 ( V_88 ) ;
V_308:
return V_39 ;
}
static int F_159 ( struct V_313 * V_314 ,
struct V_315 * V_316 ,
struct V_4 * * V_5 , int * V_317 )
{
struct V_4 * V_7 = V_5 [ V_318 ] ;
struct V_319 * V_320 ;
int V_251 , V_321 ;
if ( V_316 != NULL ) {
struct V_322 * V_323 ;
V_323 = F_3 ( V_5 [ V_324 ] ) ;
memcpy ( & V_316 -> V_325 , & V_323 -> V_325 , sizeof( V_316 -> V_325 ) ) ;
memcpy ( & V_316 -> V_326 , & V_323 -> V_326 , sizeof( V_316 -> V_326 ) ) ;
V_316 -> V_40 = V_323 -> V_40 ;
V_316 -> V_327 = V_323 -> V_327 ;
}
V_320 = F_3 ( V_7 ) ;
V_321 = F_4 ( V_7 ) / sizeof( * V_320 ) ;
if ( V_321 <= 0 || V_321 > V_263 )
return - V_10 ;
for ( V_251 = 0 ; V_251 < V_321 ; V_251 ++ , V_320 ++ , V_314 ++ ) {
memcpy ( & V_314 -> V_328 , & V_320 -> V_328 , sizeof( V_314 -> V_328 ) ) ;
memcpy ( & V_314 -> V_329 , & V_320 -> V_329 , sizeof( V_314 -> V_329 ) ) ;
memcpy ( & V_314 -> V_330 , & V_320 -> V_330 , sizeof( V_314 -> V_330 ) ) ;
memcpy ( & V_314 -> V_331 , & V_320 -> V_331 , sizeof( V_314 -> V_331 ) ) ;
V_314 -> V_36 = V_320 -> V_36 ;
V_314 -> V_48 = V_320 -> V_48 ;
V_314 -> V_91 = V_320 -> V_91 ;
V_314 -> V_332 = V_320 -> V_332 ;
V_314 -> V_333 = V_320 -> V_333 ;
}
* V_317 = V_251 ;
return 0 ;
}
static int F_160 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
struct V_280 * V_334 = F_40 ( V_142 ) ;
struct V_313 V_158 [ V_263 ] ;
struct V_315 V_130 , * V_335 ;
T_2 type ;
int V_39 ;
int V_336 = 0 ;
if ( V_5 [ V_318 ] == NULL )
return - V_10 ;
V_335 = V_5 [ V_324 ] ? & V_130 : NULL ;
V_39 = F_112 ( & type , V_5 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_159 ( (struct V_313 * ) V_158 , V_335 , V_5 , & V_336 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_336 )
return 0 ;
V_313 ( & V_334 -> V_89 , V_334 -> V_230 , type , V_158 , V_336 , V_335 ) ;
return 0 ;
}
static int F_160 ( struct V_139 * V_140 , struct V_141 * V_142 ,
struct V_4 * * V_5 )
{
return - V_337 ;
}
static int F_161 ( const struct V_313 * V_158 , struct V_139 * V_140 )
{
struct V_319 V_320 ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
V_320 . V_36 = V_158 -> V_36 ;
V_320 . V_48 = V_158 -> V_48 ;
V_320 . V_91 = V_158 -> V_91 ;
V_320 . V_332 = V_158 -> V_332 ;
memcpy ( & V_320 . V_328 , & V_158 -> V_328 , sizeof( V_320 . V_328 ) ) ;
memcpy ( & V_320 . V_329 , & V_158 -> V_329 , sizeof( V_320 . V_329 ) ) ;
V_320 . V_333 = V_158 -> V_333 ;
memcpy ( & V_320 . V_330 , & V_158 -> V_330 , sizeof( V_320 . V_330 ) ) ;
memcpy ( & V_320 . V_331 , & V_158 -> V_331 , sizeof( V_320 . V_331 ) ) ;
return F_64 ( V_140 , V_318 , sizeof( V_320 ) , & V_320 ) ;
}
static int F_162 ( const struct V_315 * V_316 , struct V_139 * V_140 )
{
struct V_322 V_323 ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
V_323 . V_40 = V_316 -> V_40 ;
V_323 . V_327 = V_316 -> V_327 ;
memcpy ( & V_323 . V_325 , & V_316 -> V_325 , sizeof( V_323 . V_325 ) ) ;
memcpy ( & V_323 . V_326 , & V_316 -> V_326 , sizeof( V_323 . V_326 ) ) ;
return F_64 ( V_140 , V_324 , sizeof( V_323 ) , & V_323 ) ;
}
static inline T_5 F_163 ( int V_321 , int V_338 )
{
return F_83 ( sizeof( struct V_280 ) )
+ ( V_338 ? F_84 ( sizeof( struct V_315 ) ) : 0 )
+ F_84 ( sizeof( struct V_319 ) * V_321 )
+ F_127 () ;
}
static int F_164 ( struct V_139 * V_140 , const struct V_313 * V_158 ,
int V_321 , const struct V_315 * V_316 ,
const struct V_339 * V_89 , T_2 V_230 , T_2 type )
{
const struct V_313 * V_340 ;
struct V_280 * V_341 ;
struct V_141 * V_142 ;
int V_251 , V_39 ;
V_142 = F_69 ( V_140 , 0 , 0 , V_342 , sizeof( * V_341 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_341 = F_40 ( V_142 ) ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
memcpy ( & V_341 -> V_89 , V_89 , sizeof( V_341 -> V_89 ) ) ;
V_341 -> V_230 = V_230 ;
if ( V_316 != NULL ) {
V_39 = F_162 ( V_316 , V_140 ) ;
if ( V_39 )
goto V_295;
}
V_39 = F_128 ( type , V_140 ) ;
if ( V_39 )
goto V_295;
for ( V_251 = 0 , V_340 = V_158 ; V_251 < V_321 ; V_251 ++ , V_340 ++ ) {
V_39 = F_161 ( V_340 , V_140 ) ;
if ( V_39 )
goto V_295;
}
return F_72 ( V_140 , V_142 ) ;
V_295:
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
static int F_165 ( const struct V_339 * V_89 , T_2 V_230 , T_2 type ,
const struct V_313 * V_158 , int V_321 ,
const struct V_315 * V_316 )
{
struct V_114 * V_114 = & V_343 ;
struct V_139 * V_140 ;
V_140 = F_79 ( F_163 ( V_321 , ! ! V_316 ) , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_164 ( V_140 , V_158 , V_321 , V_316 , V_89 , V_230 , type ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_344 , V_193 ) ;
}
static int F_165 ( const struct V_339 * V_89 , T_2 V_230 , T_2 type ,
const struct V_313 * V_158 , int V_321 ,
const struct V_315 * V_316 )
{
return - V_337 ;
}
static int F_167 ( struct V_139 * V_140 , struct V_141 * V_142 )
{
struct V_114 * V_114 = F_39 ( V_140 -> V_143 ) ;
struct V_4 * V_5 [ V_345 + 1 ] ;
struct V_346 * V_347 ;
int type , V_39 ;
type = V_142 -> V_150 ;
if ( type > V_348 )
return - V_10 ;
type -= V_349 ;
V_347 = & V_350 [ type ] ;
if ( ! F_168 ( V_351 ) )
return - V_164 ;
if ( ( type == ( V_352 - V_349 ) ||
type == ( V_353 - V_349 ) ) &&
( V_142 -> V_185 & V_354 ) ) {
if ( V_347 -> V_355 == NULL )
return - V_10 ;
{
struct V_356 V_145 = {
. V_355 = V_347 -> V_355 ,
. V_357 = V_347 -> V_357 ,
} ;
return F_169 ( V_114 -> V_132 . V_214 , V_140 , V_142 , & V_145 ) ;
}
}
V_39 = F_170 ( V_142 , V_358 [ type ] , V_5 , V_345 ,
V_359 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_347 -> V_360 == NULL )
return - V_10 ;
return V_347 -> V_360 ( V_140 , V_142 , V_5 ) ;
}
static void F_171 ( struct V_139 * V_140 )
{
F_172 ( & V_361 ) ;
F_173 ( V_140 , & F_167 ) ;
F_174 ( & V_361 ) ;
}
static inline T_5 F_175 ( void )
{
return F_83 ( sizeof( struct V_304 ) )
+ F_84 ( sizeof( struct V_157 ) ) ;
}
static int F_176 ( struct V_139 * V_140 , struct V_87 * V_88 , const struct V_144 * V_145 )
{
struct V_304 * V_305 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , 0 , V_362 , sizeof( * V_305 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_305 = F_40 ( V_142 ) ;
F_59 ( V_88 , & V_305 -> V_137 ) ;
V_305 -> V_303 = ( V_145 -> V_284 . V_303 != 0 ) ? 1 : 0 ;
V_39 = F_67 ( V_140 , & V_88 -> V_129 ) ;
if ( V_39 )
return V_39 ;
return F_72 ( V_140 , V_142 ) ;
}
static int F_177 ( struct V_87 * V_88 , const struct V_144 * V_145 )
{
struct V_114 * V_114 = F_178 ( V_88 ) ;
struct V_139 * V_140 ;
V_140 = F_79 ( F_175 () , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_176 ( V_140 , V_88 , V_145 ) < 0 ) {
F_81 ( V_140 ) ;
return - V_169 ;
}
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_363 , V_193 ) ;
}
static int F_179 ( struct V_87 * V_88 , const struct V_144 * V_145 )
{
struct V_114 * V_114 = F_178 ( V_88 ) ;
struct V_139 * V_140 ;
V_140 = F_79 ( F_141 ( V_88 ) , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_142 ( V_140 , V_88 , V_145 ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_364 , V_193 ) ;
}
static int F_180 ( const struct V_144 * V_145 )
{
struct V_114 * V_114 = V_145 -> V_114 ;
struct V_286 * V_26 ;
struct V_141 * V_142 ;
struct V_139 * V_140 ;
int V_23 = F_83 ( sizeof( struct V_286 ) ) ;
V_140 = F_79 ( V_23 , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , V_145 -> V_131 , V_365 , sizeof( * V_26 ) , 0 ) ;
if ( V_142 == NULL ) {
F_81 ( V_140 ) ;
return - V_169 ;
}
V_26 = F_40 ( V_142 ) ;
V_26 -> V_36 = V_145 -> V_284 . V_36 ;
F_72 ( V_140 , V_142 ) ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_366 , V_193 ) ;
}
static inline T_5 F_181 ( struct V_87 * V_88 )
{
T_5 V_367 = 0 ;
if ( V_88 -> V_117 )
V_367 += F_84 ( F_1 ( V_88 -> V_117 ) ) ;
if ( V_88 -> V_119 ) {
V_367 += F_84 ( sizeof( struct V_8 ) +
( V_88 -> V_119 -> V_3 + 7 ) / 8 ) ;
V_367 += F_84 ( F_7 ( V_88 -> V_119 ) ) ;
}
if ( V_88 -> V_121 )
V_367 += F_84 ( F_5 ( V_88 -> V_121 ) ) ;
if ( V_88 -> V_123 )
V_367 += F_84 ( sizeof( * V_88 -> V_123 ) ) ;
if ( V_88 -> V_126 )
V_367 += F_84 ( sizeof( * V_88 -> V_126 ) ) ;
if ( V_88 -> V_127 )
V_367 += F_84 ( sizeof( V_88 -> V_127 ) ) ;
if ( V_88 -> V_78 )
V_367 += F_84 ( F_12 ( V_88 -> V_78 ) ) ;
if ( V_88 -> V_178 )
V_367 += F_84 ( sizeof( struct V_21 ) +
V_88 -> V_178 -> V_24 ) ;
if ( V_88 -> V_128 )
V_367 += F_84 ( sizeof( * V_88 -> V_128 ) ) ;
V_367 += F_84 ( sizeof( V_368 ) ) ;
return V_367 ;
}
static int F_182 ( struct V_87 * V_88 , const struct V_144 * V_145 )
{
struct V_114 * V_114 = F_178 ( V_88 ) ;
struct V_25 * V_26 ;
struct V_156 * V_35 ;
struct V_141 * V_142 ;
struct V_139 * V_140 ;
int V_23 = F_181 ( V_88 ) ;
int V_369 , V_39 ;
V_369 = sizeof( * V_26 ) ;
if ( V_145 -> V_155 == V_370 ) {
V_23 += F_84 ( V_369 ) ;
V_369 = sizeof( * V_35 ) ;
V_23 += F_84 ( sizeof( struct V_157 ) ) ;
}
V_23 += F_83 ( V_369 ) ;
V_140 = F_79 ( V_23 , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , V_145 -> V_131 , V_145 -> V_155 , V_369 , 0 ) ;
V_39 = - V_169 ;
if ( V_142 == NULL )
goto V_371;
V_26 = F_40 ( V_142 ) ;
if ( V_145 -> V_155 == V_370 ) {
struct V_4 * V_167 ;
V_35 = F_40 ( V_142 ) ;
memcpy ( & V_35 -> V_161 , & V_88 -> V_35 . V_161 , sizeof( V_35 -> V_161 ) ) ;
V_35 -> V_162 = V_88 -> V_35 . V_162 ;
V_35 -> V_40 = V_88 -> V_59 . V_40 ;
V_35 -> V_36 = V_88 -> V_35 . V_36 ;
V_167 = F_61 ( V_140 , V_372 , sizeof( * V_26 ) ) ;
V_39 = - V_169 ;
if ( V_167 == NULL )
goto V_371;
V_26 = F_3 ( V_167 ) ;
}
V_39 = F_63 ( V_88 , V_26 , V_140 ) ;
if ( V_39 )
goto V_371;
F_72 ( V_140 , V_142 ) ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_366 , V_193 ) ;
V_371:
F_81 ( V_140 ) ;
return V_39 ;
}
static int F_183 ( struct V_87 * V_88 , const struct V_144 * V_145 )
{
switch ( V_145 -> V_155 ) {
case V_362 :
return F_177 ( V_88 , V_145 ) ;
case V_292 :
return F_179 ( V_88 , V_145 ) ;
case V_370 :
case V_373 :
case V_151 :
return F_182 ( V_88 , V_145 ) ;
case V_365 :
return F_180 ( V_145 ) ;
default:
F_184 ( V_374 L_3 ,
V_145 -> V_155 ) ;
break;
}
return 0 ;
}
static inline T_5 F_185 ( struct V_87 * V_88 ,
struct V_245 * V_247 )
{
return F_83 ( sizeof( struct V_306 ) )
+ F_84 ( sizeof( struct V_248 ) * V_247 -> V_252 )
+ F_84 ( sizeof( struct V_157 ) )
+ F_84 ( F_26 ( V_88 -> V_178 ) )
+ F_127 () ;
}
static int F_186 ( struct V_139 * V_140 , struct V_87 * V_88 ,
struct V_253 * V_375 , struct V_245 * V_247 )
{
T_7 V_131 = F_187 () ;
struct V_306 * V_307 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , 0 , 0 , V_376 , sizeof( * V_307 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_307 = F_40 ( V_142 ) ;
memcpy ( & V_307 -> V_35 , & V_88 -> V_35 , sizeof( V_307 -> V_35 ) ) ;
memcpy ( & V_307 -> V_92 , & V_88 -> V_59 . V_92 , sizeof( V_307 -> V_92 ) ) ;
memcpy ( & V_307 -> V_89 , & V_88 -> V_89 , sizeof( V_307 -> V_89 ) ) ;
F_114 ( V_247 , & V_307 -> V_309 , V_232 ) ;
V_307 -> V_258 = V_375 -> V_258 ;
V_307 -> V_259 = V_375 -> V_259 ;
V_307 -> V_260 = V_375 -> V_260 ;
V_307 -> V_131 = V_88 -> V_130 . V_131 = V_131 ;
V_39 = F_124 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_125 ( V_88 , V_140 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_247 -> type , V_140 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_140 , & V_247 -> V_129 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
return F_72 ( V_140 , V_142 ) ;
}
static int F_188 ( struct V_87 * V_88 , struct V_253 * V_375 ,
struct V_245 * V_247 )
{
struct V_114 * V_114 = F_178 ( V_88 ) ;
struct V_139 * V_140 ;
V_140 = F_79 ( F_185 ( V_88 , V_247 ) , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_186 ( V_140 , V_88 , V_375 , V_247 ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_377 , V_193 ) ;
}
static struct V_245 * F_189 ( struct V_378 * V_143 , int V_379 ,
T_2 * V_284 , int V_23 , int * V_230 )
{
struct V_114 * V_114 = F_39 ( V_143 ) ;
struct V_236 * V_26 = (struct V_236 * ) V_284 ;
struct V_248 * V_249 = (struct V_248 * ) ( V_26 + 1 ) ;
struct V_245 * V_247 ;
int V_250 ;
switch ( V_143 -> V_380 ) {
case V_41 :
if ( V_379 != V_381 ) {
* V_230 = - V_382 ;
return NULL ;
}
break;
#if F_14 ( V_43 )
case V_42 :
if ( V_379 != V_383 ) {
* V_230 = - V_382 ;
return NULL ;
}
break;
#endif
default:
* V_230 = - V_10 ;
return NULL ;
}
* V_230 = - V_10 ;
if ( V_23 < sizeof( * V_26 ) ||
F_106 ( V_26 ) )
return NULL ;
V_250 = ( ( V_23 - sizeof( * V_26 ) ) / sizeof( * V_249 ) ) ;
if ( F_110 ( V_250 , V_249 , V_26 -> V_89 . V_40 ) )
return NULL ;
if ( V_26 -> V_230 > V_232 )
return NULL ;
V_247 = F_116 ( V_114 , V_193 ) ;
if ( V_247 == NULL ) {
* V_230 = - V_384 ;
return NULL ;
}
F_113 ( V_247 , V_26 ) ;
V_247 -> type = V_234 ;
F_109 ( V_247 , V_249 , V_250 ) ;
* V_230 = V_26 -> V_230 ;
return V_247 ;
}
static inline T_5 F_190 ( struct V_245 * V_247 )
{
return F_83 ( sizeof( struct V_302 ) )
+ F_84 ( sizeof( struct V_248 ) * V_247 -> V_252 )
+ F_84 ( F_26 ( V_247 -> V_178 ) )
+ F_84 ( sizeof( struct V_157 ) )
+ F_127 () ;
}
static int F_191 ( struct V_139 * V_140 , struct V_245 * V_247 ,
int V_230 , const struct V_144 * V_145 )
{
struct V_302 * V_385 ;
int V_303 = V_145 -> V_284 . V_303 ;
struct V_141 * V_142 ;
int V_39 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , 0 , V_386 , sizeof( * V_385 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_385 = F_40 ( V_142 ) ;
F_114 ( V_247 , & V_385 -> V_246 , V_230 ) ;
V_39 = F_124 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_126 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_247 -> type , V_140 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_140 , & V_247 -> V_129 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
V_385 -> V_303 = ! ! V_303 ;
return F_72 ( V_140 , V_142 ) ;
}
static int F_192 ( struct V_245 * V_247 , int V_230 , const struct V_144 * V_145 )
{
struct V_114 * V_114 = F_193 ( V_247 ) ;
struct V_139 * V_140 ;
V_140 = F_79 ( F_190 ( V_247 ) , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_191 ( V_140 , V_247 , V_230 , V_145 ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_363 , V_193 ) ;
}
static int F_194 ( struct V_245 * V_247 , int V_230 , const struct V_144 * V_145 )
{
int V_23 = F_84 ( sizeof( struct V_248 ) * V_247 -> V_252 ) ;
struct V_114 * V_114 = F_193 ( V_247 ) ;
struct V_236 * V_26 ;
struct V_280 * V_35 ;
struct V_141 * V_142 ;
struct V_139 * V_140 ;
int V_369 , V_39 ;
V_369 = sizeof( * V_26 ) ;
if ( V_145 -> V_155 == V_282 ) {
V_23 += F_84 ( V_369 ) ;
V_369 = sizeof( * V_35 ) ;
}
V_23 += F_127 () ;
V_23 += F_84 ( sizeof( struct V_157 ) ) ;
V_23 += F_83 ( V_369 ) ;
V_140 = F_79 ( V_23 , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , V_145 -> V_131 , V_145 -> V_155 , V_369 , 0 ) ;
V_39 = - V_169 ;
if ( V_142 == NULL )
goto V_371;
V_26 = F_40 ( V_142 ) ;
if ( V_145 -> V_155 == V_282 ) {
struct V_4 * V_167 ;
V_35 = F_40 ( V_142 ) ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_230 = V_230 ;
if ( V_145 -> V_284 . V_285 )
V_35 -> V_271 = V_247 -> V_271 ;
else
memcpy ( & V_35 -> V_89 , & V_247 -> V_272 , sizeof( V_35 -> V_89 ) ) ;
V_167 = F_61 ( V_140 , V_387 , sizeof( * V_26 ) ) ;
V_39 = - V_169 ;
if ( V_167 == NULL )
goto V_371;
V_26 = F_3 ( V_167 ) ;
}
F_114 ( V_247 , V_26 , V_230 ) ;
V_39 = F_124 ( V_247 , V_140 ) ;
if ( ! V_39 )
V_39 = F_128 ( V_247 -> type , V_140 ) ;
if ( ! V_39 )
V_39 = F_67 ( V_140 , & V_247 -> V_129 ) ;
if ( V_39 )
goto V_371;
F_72 ( V_140 , V_142 ) ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_388 , V_193 ) ;
V_371:
F_81 ( V_140 ) ;
return V_39 ;
}
static int F_195 ( const struct V_144 * V_145 )
{
struct V_114 * V_114 = V_145 -> V_114 ;
struct V_141 * V_142 ;
struct V_139 * V_140 ;
int V_39 ;
V_140 = F_79 ( F_127 () , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
V_142 = F_69 ( V_140 , V_145 -> V_153 , V_145 -> V_131 , V_389 , 0 , 0 ) ;
V_39 = - V_169 ;
if ( V_142 == NULL )
goto V_371;
V_39 = F_128 ( V_145 -> V_284 . type , V_140 ) ;
if ( V_39 )
goto V_371;
F_72 ( V_140 , V_142 ) ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_388 , V_193 ) ;
V_371:
F_81 ( V_140 ) ;
return V_39 ;
}
static int F_196 ( struct V_245 * V_247 , int V_230 , const struct V_144 * V_145 )
{
switch ( V_145 -> V_155 ) {
case V_275 :
case V_390 :
case V_282 :
return F_194 ( V_247 , V_230 , V_145 ) ;
case V_389 :
return F_195 ( V_145 ) ;
case V_386 :
return F_192 ( V_247 , V_230 , V_145 ) ;
default:
F_184 ( V_374 L_4 ,
V_145 -> V_155 ) ;
}
return 0 ;
}
static inline T_5 F_197 ( void )
{
return F_83 ( sizeof( struct V_391 ) ) ;
}
static int F_198 ( struct V_139 * V_140 , T_2 V_36 ,
struct V_339 * V_89 , T_1 * V_392 )
{
struct V_391 * V_393 ;
struct V_141 * V_142 ;
V_142 = F_69 ( V_140 , 0 , 0 , V_394 , sizeof( * V_393 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_393 = F_40 ( V_142 ) ;
V_393 -> V_36 = V_36 ;
memcpy ( & V_393 -> V_89 , V_89 , sizeof( V_393 -> V_89 ) ) ;
if ( V_392 ) {
int V_39 = F_64 ( V_140 , V_54 , sizeof( * V_392 ) , V_392 ) ;
if ( V_39 ) {
F_71 ( V_140 , V_142 ) ;
return V_39 ;
}
}
return F_72 ( V_140 , V_142 ) ;
}
static int F_199 ( struct V_114 * V_114 , T_2 V_36 ,
struct V_339 * V_89 , T_1 * V_392 )
{
struct V_139 * V_140 ;
V_140 = F_79 ( F_197 () , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_198 ( V_140 , V_36 , V_89 , V_392 ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_395 , V_193 ) ;
}
static inline T_5 F_200 ( void )
{
return F_83 ( sizeof( struct V_396 ) ) ;
}
static int F_201 ( struct V_139 * V_140 , struct V_87 * V_88 ,
T_1 * V_331 , T_8 V_397 )
{
struct V_396 * V_320 ;
struct V_141 * V_142 ;
V_142 = F_69 ( V_140 , 0 , 0 , V_398 , sizeof( * V_320 ) , 0 ) ;
if ( V_142 == NULL )
return - V_169 ;
V_320 = F_40 ( V_142 ) ;
memcpy ( & V_320 -> V_35 . V_161 , & V_88 -> V_35 . V_161 , sizeof( V_320 -> V_35 . V_161 ) ) ;
V_320 -> V_35 . V_162 = V_88 -> V_35 . V_162 ;
V_320 -> V_35 . V_40 = V_88 -> V_59 . V_40 ;
V_320 -> V_35 . V_36 = V_88 -> V_35 . V_36 ;
memcpy ( & V_320 -> V_331 , V_331 , sizeof( V_320 -> V_331 ) ) ;
memcpy ( & V_320 -> V_329 , & V_88 -> V_59 . V_92 , sizeof( V_320 -> V_329 ) ) ;
V_320 -> V_397 = V_397 ;
V_320 -> V_399 = V_88 -> V_126 -> V_400 ;
V_320 -> V_91 = V_88 -> V_59 . V_91 ;
return F_72 ( V_140 , V_142 ) ;
}
static int F_202 ( struct V_87 * V_88 , T_1 * V_401 ,
T_8 V_402 )
{
struct V_114 * V_114 = F_178 ( V_88 ) ;
struct V_139 * V_140 ;
if ( V_88 -> V_35 . V_36 != V_37 )
return - V_10 ;
if ( ! V_88 -> V_126 )
return - V_10 ;
V_140 = F_79 ( F_200 () , V_193 ) ;
if ( V_140 == NULL )
return - V_68 ;
if ( F_201 ( V_140 , V_88 , V_401 , V_402 ) < 0 )
F_88 () ;
return F_166 ( V_114 -> V_132 . V_214 , V_140 , 0 , V_403 , V_193 ) ;
}
static int T_9 F_203 ( struct V_114 * V_114 )
{
struct V_378 * V_214 ;
struct V_404 V_405 = {
. V_406 = V_407 ,
. V_408 = F_171 ,
} ;
V_214 = F_204 ( V_114 , V_409 , & V_405 ) ;
if ( V_214 == NULL )
return - V_68 ;
V_114 -> V_132 . V_410 = V_214 ;
F_205 ( V_114 -> V_132 . V_214 , V_214 ) ;
return 0 ;
}
static void T_10 F_206 ( struct V_411 * V_412 )
{
struct V_114 * V_114 ;
F_207 (net, net_exit_list, exit_list)
F_208 ( V_114 -> V_132 . V_214 , NULL ) ;
F_209 () ;
F_207 (net, net_exit_list, exit_list)
F_210 ( V_114 -> V_132 . V_410 ) ;
}
static int T_11 F_211 ( void )
{
int V_413 ;
F_184 ( V_414 L_5 ) ;
V_413 = F_212 ( & V_415 ) ;
if ( V_413 < 0 )
return V_413 ;
V_413 = F_213 ( & V_416 ) ;
if ( V_413 < 0 )
F_214 ( & V_415 ) ;
return V_413 ;
}
static void T_12 F_215 ( void )
{
F_216 ( & V_416 ) ;
F_214 ( & V_415 ) ;
}
