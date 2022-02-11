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
if ( ( V_26 -> V_28 & V_29 ) && ! V_7 )
return - V_10 ;
if ( ! V_7 )
return 0 ;
if ( V_26 -> V_30 . V_31 != V_32 )
return - V_10 ;
if ( V_26 -> V_33 != 0 )
return - V_10 ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 ,
struct V_4 * * V_5 )
{
int V_34 ;
V_34 = - V_10 ;
switch ( V_26 -> V_35 ) {
case V_36 :
break;
case V_37 :
#if F_13 ( V_38 )
break;
#else
V_34 = - V_39 ;
goto V_40;
#endif
default:
goto V_40;
}
V_34 = - V_10 ;
switch ( V_26 -> V_30 . V_31 ) {
case V_41 :
if ( ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] ) ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_13 ] ||
V_5 [ V_42 ] )
goto V_40;
break;
case V_32 :
if ( V_5 [ V_13 ] )
goto V_40;
if ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] &&
! V_5 [ V_12 ] &&
! V_5 [ V_18 ] )
goto V_40;
if ( ( V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ) &&
V_5 [ V_18 ] )
goto V_40;
if ( V_5 [ V_42 ] &&
V_26 -> V_43 != V_44 )
goto V_40;
break;
case V_45 :
if ( ! V_5 [ V_13 ] ||
V_5 [ V_18 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ||
V_5 [ V_42 ] )
goto V_40;
break;
#if F_13 ( V_38 )
case V_46 :
case V_47 :
if ( V_5 [ V_13 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_48 ] ||
V_5 [ V_20 ] ||
V_5 [ V_42 ] ||
! V_5 [ V_49 ] )
goto V_40;
break;
#endif
default:
goto V_40;
}
if ( ( V_34 = F_8 ( V_5 ) ) )
goto V_40;
if ( ( V_34 = F_6 ( V_5 ) ) )
goto V_40;
if ( ( V_34 = F_2 ( V_5 , V_11 ) ) )
goto V_40;
if ( ( V_34 = F_2 ( V_5 , V_12 ) ) )
goto V_40;
if ( ( V_34 = F_2 ( V_5 , V_13 ) ) )
goto V_40;
if ( ( V_34 = F_10 ( V_5 ) ) )
goto V_40;
if ( ( V_34 = F_11 ( V_26 , V_5 ) ) )
goto V_40;
V_34 = - V_10 ;
switch ( V_26 -> V_43 ) {
case V_50 :
case V_44 :
case V_51 :
case V_52 :
break;
default:
goto V_40;
}
V_34 = 0 ;
V_40:
return V_34 ;
}
static int F_14 ( struct V_17 * * V_53 , T_2 * V_54 ,
struct V_4 * V_55 )
{
struct V_8 * V_56 ;
struct V_17 * V_26 ;
struct V_57 * V_58 ;
if ( ! V_55 )
return 0 ;
V_56 = F_3 ( V_55 ) ;
V_58 = F_15 ( V_56 -> V_14 , 1 ) ;
if ( ! V_58 )
return - V_59 ;
* V_54 = V_58 -> V_60 . V_61 ;
V_26 = F_16 ( sizeof( * V_26 ) + ( V_56 -> V_3 + 7 ) / 8 , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
strcpy ( V_26 -> V_14 , V_58 -> V_64 ) ;
V_26 -> V_3 = V_56 -> V_3 ;
V_26 -> V_65 = V_58 -> V_66 . V_67 . V_68 ;
memcpy ( V_26 -> V_69 , V_56 -> V_69 , ( V_56 -> V_3 + 7 ) / 8 ) ;
* V_53 = V_26 ;
return 0 ;
}
static int F_17 ( struct V_17 * * V_53 , T_2 * V_54 ,
struct V_4 * V_55 )
{
struct V_17 * V_26 , * V_56 ;
struct V_57 * V_58 ;
if ( ! V_55 )
return 0 ;
V_56 = F_3 ( V_55 ) ;
V_58 = F_15 ( V_56 -> V_14 , 1 ) ;
if ( ! V_58 )
return - V_59 ;
if ( ( V_56 -> V_65 / 8 ) > V_70 ||
V_56 -> V_65 > V_58 -> V_66 . V_67 . V_71 )
return - V_10 ;
* V_54 = V_58 -> V_60 . V_61 ;
V_26 = F_18 ( V_56 , F_7 ( V_56 ) , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
strcpy ( V_26 -> V_14 , V_58 -> V_64 ) ;
if ( ! V_26 -> V_65 )
V_26 -> V_65 = V_58 -> V_66 . V_67 . V_68 ;
* V_53 = V_26 ;
return 0 ;
}
static int F_19 ( struct V_1 * * V_53 , T_2 * V_54 ,
struct V_4 * V_55 )
{
struct V_1 * V_26 , * V_56 ;
struct V_57 * V_58 ;
if ( ! V_55 )
return 0 ;
V_56 = F_3 ( V_55 ) ;
V_58 = F_20 ( V_56 -> V_14 , V_56 -> V_72 , 1 ) ;
if ( ! V_58 )
return - V_59 ;
* V_54 = V_58 -> V_60 . V_61 ;
V_26 = F_18 ( V_56 , F_1 ( V_56 ) , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
strcpy ( V_26 -> V_14 , V_58 -> V_64 ) ;
* V_53 = V_26 ;
return 0 ;
}
static inline int F_21 ( struct V_73 * V_74 ,
struct V_4 * V_75 )
{
struct V_73 * V_76 ;
if ( ! V_74 || ! V_75 )
return 0 ;
V_76 = F_3 ( V_75 ) ;
if ( F_22 ( V_74 ) !=
F_22 ( V_76 ) )
return - V_10 ;
return 0 ;
}
static int F_23 ( struct V_73 * * V_74 ,
struct V_73 * * V_77 ,
struct V_4 * V_55 )
{
struct V_73 * V_26 , * V_78 , * V_76 ;
if ( ! V_55 )
return 0 ;
V_76 = F_3 ( V_55 ) ;
V_26 = F_18 ( V_76 , F_22 ( V_76 ) , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
V_78 = F_18 ( V_76 , F_22 ( V_76 ) , V_62 ) ;
if ( ! V_78 ) {
F_24 ( V_26 ) ;
return - V_63 ;
}
* V_74 = V_26 ;
* V_77 = V_78 ;
return 0 ;
}
static inline int F_25 ( struct V_79 * V_80 )
{
int V_23 = 0 ;
if ( V_80 ) {
V_23 += sizeof( struct V_21 ) ;
V_23 += V_80 -> V_24 ;
}
return V_23 ;
}
static void F_26 ( struct V_81 * V_82 , struct V_25 * V_26 )
{
memcpy ( & V_82 -> V_30 , & V_26 -> V_30 , sizeof( V_82 -> V_30 ) ) ;
memcpy ( & V_82 -> V_83 , & V_26 -> V_83 , sizeof( V_82 -> V_83 ) ) ;
memcpy ( & V_82 -> V_84 , & V_26 -> V_84 , sizeof( V_82 -> V_84 ) ) ;
V_82 -> V_54 . V_43 = V_26 -> V_43 ;
V_82 -> V_54 . V_33 = V_26 -> V_33 ;
V_82 -> V_54 . V_85 = V_26 -> V_85 ;
V_82 -> V_54 . V_35 = V_26 -> V_35 ;
memcpy ( & V_82 -> V_54 . V_86 , & V_26 -> V_86 , sizeof( V_82 -> V_54 . V_86 ) ) ;
V_82 -> V_54 . V_28 = V_26 -> V_28 ;
if ( ! V_82 -> V_83 . V_35 && ! ( V_26 -> V_28 & V_87 ) )
V_82 -> V_83 . V_35 = V_26 -> V_35 ;
}
static void F_27 ( struct V_81 * V_82 , struct V_4 * * V_5 )
{
struct V_4 * V_75 = V_5 [ V_88 ] ;
struct V_4 * V_89 = V_5 [ V_27 ] ;
struct V_4 * V_90 = V_5 [ V_91 ] ;
struct V_4 * V_92 = V_5 [ V_93 ] ;
struct V_4 * V_7 = V_5 [ V_94 ] ;
if ( V_89 ) {
struct V_73 * V_74 ;
V_74 = F_3 ( V_89 ) ;
memcpy ( V_82 -> V_74 , V_74 ,
F_22 ( V_74 ) ) ;
memcpy ( V_82 -> V_77 , V_74 ,
F_22 ( V_74 ) ) ;
}
if ( V_75 ) {
struct V_95 * V_96 ;
V_96 = F_3 ( V_75 ) ;
memcpy ( & V_82 -> V_96 , V_96 , sizeof( * V_96 ) ) ;
memcpy ( & V_82 -> V_97 , V_96 , sizeof( * V_96 ) ) ;
}
if ( V_90 ) {
struct V_98 * V_99 ;
V_99 = F_3 ( V_90 ) ;
V_82 -> V_100 . V_101 = V_99 -> V_101 ;
V_82 -> V_100 . V_102 = V_99 -> V_102 ;
V_82 -> V_100 . V_103 = V_99 -> V_103 ;
V_82 -> V_100 . V_104 = V_99 -> V_104 ;
}
if ( V_92 )
V_82 -> V_105 = F_28 ( V_92 ) ;
if ( V_7 )
V_82 -> V_106 = F_28 ( V_7 ) ;
}
static struct V_81 * F_29 ( struct V_107 * V_107 ,
struct V_25 * V_26 ,
struct V_4 * * V_5 ,
int * V_108 )
{
struct V_81 * V_82 = F_30 ( V_107 ) ;
int V_34 = - V_63 ;
if ( ! V_82 )
goto V_109;
F_26 ( V_82 , V_26 ) ;
if ( ( V_34 = F_19 ( & V_82 -> V_110 , & V_82 -> V_54 . V_111 ,
V_5 [ V_18 ] ) ) )
goto error;
if ( ( V_34 = F_17 ( & V_82 -> V_112 , & V_82 -> V_54 . V_113 ,
V_5 [ V_16 ] ) ) )
goto error;
if ( ! V_82 -> V_54 . V_113 ) {
if ( ( V_34 = F_14 ( & V_82 -> V_112 , & V_82 -> V_54 . V_113 ,
V_5 [ V_11 ] ) ) )
goto error;
}
if ( ( V_34 = F_31 ( & V_82 -> V_114 , & V_82 -> V_54 . V_111 ,
V_115 ,
V_5 [ V_12 ] ) ) )
goto error;
if ( ( V_34 = F_31 ( & V_82 -> V_116 , & V_82 -> V_54 . V_117 ,
V_118 ,
V_5 [ V_13 ] ) ) )
goto error;
if ( V_5 [ V_48 ] ) {
V_82 -> V_119 = F_18 ( F_3 ( V_5 [ V_48 ] ) ,
sizeof( * V_82 -> V_119 ) , V_62 ) ;
if ( V_82 -> V_119 == NULL )
goto error;
}
if ( V_5 [ V_42 ] )
V_82 -> V_120 = F_28 ( V_5 [ V_42 ] ) ;
if ( V_5 [ V_49 ] ) {
V_82 -> V_121 = F_18 ( F_3 ( V_5 [ V_49 ] ) ,
sizeof( * V_82 -> V_121 ) , V_62 ) ;
if ( V_82 -> V_121 == NULL )
goto error;
}
F_32 ( V_5 , & V_82 -> V_122 ) ;
V_34 = F_33 ( V_82 , false ) ;
if ( V_34 )
goto error;
if ( V_5 [ V_20 ] &&
F_34 ( V_82 , F_3 ( V_5 [ V_20 ] ) ) )
goto error;
if ( ( V_34 = F_23 ( & V_82 -> V_74 , & V_82 -> V_77 ,
V_5 [ V_27 ] ) ) )
goto error;
V_82 -> V_123 . V_124 = V_26 -> V_124 ;
V_82 -> V_106 = V_107 -> V_125 . V_126 ;
V_82 -> V_105 = ( V_107 -> V_125 . V_127 * V_128 ) / V_129 ;
if ( ( V_34 = F_35 ( V_82 ) ) )
goto error;
F_27 ( V_82 , V_5 ) ;
return V_82 ;
error:
V_82 -> V_123 . V_130 = V_131 ;
F_36 ( V_82 ) ;
V_109:
* V_108 = V_34 ;
return NULL ;
}
static int F_37 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_25 * V_26 = F_39 ( V_135 ) ;
struct V_81 * V_82 ;
int V_34 ;
struct V_137 V_138 ;
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
V_34 = F_12 ( V_26 , V_5 ) ;
if ( V_34 )
return V_34 ;
V_82 = F_29 ( V_107 , V_26 , V_5 , & V_34 ) ;
if ( ! V_82 )
return V_34 ;
F_42 ( V_82 ) ;
if ( V_135 -> V_143 == V_144 )
V_34 = F_43 ( V_82 ) ;
else
V_34 = F_44 ( V_82 ) ;
F_45 ( V_140 , & V_142 ) ;
F_46 ( V_82 , V_34 ? 0 : 1 , V_139 , V_141 , V_142 ) ;
if ( V_34 < 0 ) {
V_82 -> V_123 . V_130 = V_131 ;
F_47 ( V_82 ) ;
goto V_40;
}
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
V_138 . V_148 = V_135 -> V_143 ;
F_48 ( V_82 , & V_138 ) ;
V_40:
F_36 ( V_82 ) ;
return V_34 ;
}
static struct V_81 * F_49 ( struct V_107 * V_107 ,
struct V_149 * V_26 ,
struct V_4 * * V_5 ,
int * V_108 )
{
struct V_81 * V_82 = NULL ;
struct V_150 V_151 ;
int V_34 ;
T_4 V_122 = F_32 ( V_5 , & V_151 ) ;
if ( F_50 ( V_26 -> V_31 , V_152 ) ) {
V_34 = - V_153 ;
V_82 = F_51 ( V_107 , V_122 , & V_26 -> V_154 , V_26 -> V_155 , V_26 -> V_31 , V_26 -> V_35 ) ;
} else {
T_1 * V_86 = NULL ;
F_9 ( V_5 , V_156 , & V_86 ) ;
if ( ! V_86 ) {
V_34 = - V_10 ;
goto V_40;
}
V_34 = - V_153 ;
V_82 = F_52 ( V_107 , V_122 ,
& V_26 -> V_154 , V_86 ,
V_26 -> V_31 , V_26 -> V_35 ) ;
}
V_40:
if ( ! V_82 && V_108 )
* V_108 = V_34 ;
return V_82 ;
}
static int F_53 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_81 * V_82 ;
int V_34 = - V_153 ;
struct V_137 V_138 ;
struct V_149 * V_26 = F_39 ( V_135 ) ;
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
V_82 = F_49 ( V_107 , V_26 , V_5 , & V_34 ) ;
if ( V_82 == NULL )
return V_34 ;
if ( ( V_34 = F_54 ( V_82 ) ) != 0 )
goto V_40;
if ( F_55 ( V_82 ) ) {
V_34 = - V_157 ;
goto V_40;
}
V_34 = F_56 ( V_82 ) ;
if ( V_34 < 0 )
goto V_40;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
V_138 . V_148 = V_135 -> V_143 ;
F_48 ( V_82 , & V_138 ) ;
V_40:
F_45 ( V_140 , & V_142 ) ;
F_57 ( V_82 , V_34 ? 0 : 1 , V_139 , V_141 , V_142 ) ;
F_36 ( V_82 ) ;
return V_34 ;
}
static void F_58 ( struct V_81 * V_82 , struct V_25 * V_26 )
{
memcpy ( & V_26 -> V_30 , & V_82 -> V_30 , sizeof( V_26 -> V_30 ) ) ;
memcpy ( & V_26 -> V_83 , & V_82 -> V_83 , sizeof( V_26 -> V_83 ) ) ;
memcpy ( & V_26 -> V_84 , & V_82 -> V_84 , sizeof( V_26 -> V_84 ) ) ;
memcpy ( & V_26 -> V_100 , & V_82 -> V_100 , sizeof( V_26 -> V_100 ) ) ;
memcpy ( & V_26 -> V_158 , & V_82 -> V_158 , sizeof( V_26 -> V_158 ) ) ;
memcpy ( & V_26 -> V_86 , & V_82 -> V_54 . V_86 , sizeof( V_26 -> V_86 ) ) ;
V_26 -> V_43 = V_82 -> V_54 . V_43 ;
V_26 -> V_33 = V_82 -> V_54 . V_33 ;
V_26 -> V_85 = V_82 -> V_54 . V_85 ;
V_26 -> V_35 = V_82 -> V_54 . V_35 ;
V_26 -> V_28 = V_82 -> V_54 . V_28 ;
V_26 -> V_124 = V_82 -> V_123 . V_124 ;
}
static int F_59 ( struct V_79 * V_159 , struct V_132 * V_133 )
{
struct V_21 * V_22 ;
struct V_4 * V_160 ;
int V_161 = sizeof( * V_22 ) + V_159 -> V_24 ;
V_160 = F_60 ( V_133 , V_20 , V_161 ) ;
if ( V_160 == NULL )
return - V_162 ;
V_22 = F_3 ( V_160 ) ;
V_22 -> V_163 = V_20 ;
V_22 -> V_23 = V_161 ;
V_22 -> V_164 = V_159 -> V_164 ;
V_22 -> V_165 = V_159 -> V_165 ;
V_22 -> V_24 = V_159 -> V_24 ;
memcpy ( V_22 + 1 , V_159 -> V_166 , V_159 -> V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_17 * V_67 , struct V_132 * V_133 )
{
struct V_8 * V_58 ;
struct V_4 * V_167 ;
V_167 = F_60 ( V_133 , V_11 ,
sizeof( * V_58 ) + ( V_67 -> V_3 + 7 ) / 8 ) ;
if ( ! V_167 )
return - V_162 ;
V_58 = F_3 ( V_167 ) ;
strcpy ( V_58 -> V_14 , V_67 -> V_14 ) ;
memcpy ( V_58 -> V_69 , V_67 -> V_69 , ( V_67 -> V_3 + 7 ) / 8 ) ;
V_58 -> V_3 = V_67 -> V_3 ;
return 0 ;
}
static int F_62 ( struct V_81 * V_82 ,
struct V_25 * V_26 ,
struct V_132 * V_133 )
{
F_58 ( V_82 , V_26 ) ;
if ( V_82 -> V_121 &&
F_63 ( V_133 , V_49 , sizeof( * V_82 -> V_121 ) , V_82 -> V_121 ) )
goto V_168;
if ( V_82 -> V_169 &&
F_64 ( V_133 , V_170 , V_82 -> V_169 ) )
goto V_168;
if ( V_82 -> V_110 &&
F_63 ( V_133 , V_18 , F_1 ( V_82 -> V_110 ) , V_82 -> V_110 ) )
goto V_168;
if ( V_82 -> V_112 &&
( F_61 ( V_82 -> V_112 , V_133 ) ||
F_63 ( V_133 , V_16 ,
F_7 ( V_82 -> V_112 ) , V_82 -> V_112 ) ) )
goto V_168;
if ( V_82 -> V_114 &&
F_63 ( V_133 , V_12 , F_5 ( V_82 -> V_114 ) , V_82 -> V_114 ) )
goto V_168;
if ( V_82 -> V_116 &&
F_63 ( V_133 , V_13 , sizeof( * ( V_82 -> V_116 ) ) , V_82 -> V_116 ) )
goto V_168;
if ( V_82 -> V_119 &&
F_63 ( V_133 , V_48 , sizeof( * V_82 -> V_119 ) , V_82 -> V_119 ) )
goto V_168;
if ( V_82 -> V_120 &&
F_65 ( V_133 , V_42 , V_82 -> V_120 ) )
goto V_168;
if ( F_66 ( V_133 , & V_82 -> V_122 ) )
goto V_168;
if ( V_82 -> V_74 &&
F_63 ( V_133 , V_27 ,
F_22 ( V_82 -> V_74 ) ,
V_82 -> V_74 ) )
goto V_168;
if ( V_82 -> V_171 && F_59 ( V_82 -> V_171 , V_133 ) )
goto V_168;
return 0 ;
V_168:
return - V_162 ;
}
static int F_67 ( struct V_81 * V_82 , int V_172 , void * V_173 )
{
struct V_174 * V_175 = V_173 ;
struct V_132 * V_176 = V_175 -> V_176 ;
struct V_132 * V_133 = V_175 -> V_177 ;
struct V_25 * V_26 ;
struct V_134 * V_135 ;
int V_34 ;
V_135 = F_68 ( V_133 , F_69 ( V_176 ) . V_146 , V_175 -> V_145 ,
V_144 , sizeof( * V_26 ) , V_175 -> V_178 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_26 = F_39 ( V_135 ) ;
V_34 = F_62 ( V_82 , V_26 , V_133 ) ;
if ( V_34 )
goto V_168;
F_70 ( V_133 , V_135 ) ;
return 0 ;
V_168:
F_71 ( V_133 , V_135 ) ;
return V_34 ;
}
static int F_72 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = (struct V_181 * ) & V_180 -> args [ 1 ] ;
F_73 ( V_182 ) ;
return 0 ;
}
static int F_74 ( struct V_132 * V_133 , struct V_179 * V_180 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_181 * V_182 = (struct V_181 * ) & V_180 -> args [ 1 ] ;
struct V_174 V_183 ;
F_75 ( sizeof( struct V_181 ) >
sizeof( V_180 -> args ) - sizeof( V_180 -> args [ 0 ] ) ) ;
V_183 . V_176 = V_180 -> V_133 ;
V_183 . V_177 = V_133 ;
V_183 . V_145 = V_180 -> V_135 -> V_145 ;
V_183 . V_178 = V_184 ;
if ( ! V_180 -> args [ 0 ] ) {
V_180 -> args [ 0 ] = 1 ;
F_76 ( V_182 , 0 ) ;
}
( void ) V_181 ( V_107 , V_182 , F_67 , & V_183 ) ;
return V_133 -> V_23 ;
}
static struct V_132 * F_77 ( struct V_132 * V_176 ,
struct V_81 * V_82 , T_4 V_124 )
{
struct V_174 V_183 ;
struct V_132 * V_133 ;
V_133 = F_78 ( V_185 , V_186 ) ;
if ( ! V_133 )
return F_79 ( - V_63 ) ;
V_183 . V_176 = V_176 ;
V_183 . V_177 = V_133 ;
V_183 . V_145 = V_124 ;
V_183 . V_178 = 0 ;
if ( F_67 ( V_82 , 0 , & V_183 ) ) {
F_80 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
static inline T_5 F_81 ( void )
{
return F_82 ( 4 )
+ F_83 ( sizeof( struct V_187 ) )
+ F_83 ( sizeof( struct V_188 ) ) ;
}
static int F_84 ( struct V_132 * V_133 , struct V_107 * V_107 ,
T_4 V_146 , T_4 V_124 , T_4 V_28 )
{
struct V_189 V_190 ;
struct V_187 V_191 ;
struct V_188 V_192 ;
struct V_134 * V_135 ;
T_4 * V_193 ;
V_135 = F_68 ( V_133 , V_146 , V_124 , V_194 , sizeof( T_4 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_193 = F_39 ( V_135 ) ;
* V_193 = V_28 ;
F_85 ( V_107 , & V_190 ) ;
V_191 . V_195 = V_190 . V_195 ;
V_191 . V_196 = V_190 . V_196 ;
V_191 . V_197 = V_190 . V_197 ;
V_191 . V_198 = V_190 . V_198 ;
V_191 . V_199 = V_190 . V_199 ;
V_191 . V_200 = V_190 . V_200 ;
V_192 . V_201 = V_190 . V_201 ;
V_192 . V_202 = V_190 . V_202 ;
if ( F_63 ( V_133 , V_203 , sizeof( V_191 ) , & V_191 ) ||
F_63 ( V_133 , V_204 , sizeof( V_192 ) , & V_192 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_86 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_132 * V_205 ;
T_4 * V_28 = F_39 ( V_135 ) ;
T_4 V_206 = F_69 ( V_133 ) . V_146 ;
T_4 V_124 = V_135 -> V_145 ;
V_205 = F_78 ( F_81 () , V_186 ) ;
if ( V_205 == NULL )
return - V_63 ;
if ( F_84 ( V_205 , V_107 , V_206 , V_124 , * V_28 ) < 0 )
F_87 () ;
return F_88 ( V_107 -> V_125 . V_207 , V_205 , V_206 ) ;
}
static inline T_5 F_89 ( void )
{
return F_82 ( 4 )
+ F_83 ( sizeof( struct V_208 ) )
+ F_83 ( 4 ) ;
}
static int F_90 ( struct V_132 * V_133 , struct V_107 * V_107 ,
T_4 V_146 , T_4 V_124 , T_4 V_28 )
{
struct V_209 V_190 ;
struct V_208 V_210 ;
struct V_134 * V_135 ;
T_4 * V_193 ;
V_135 = F_68 ( V_133 , V_146 , V_124 , V_211 , sizeof( T_4 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_193 = F_39 ( V_135 ) ;
* V_193 = V_28 ;
F_91 ( V_107 , & V_190 ) ;
V_210 . V_212 = V_190 . V_212 ;
V_210 . V_213 = V_190 . V_213 ;
if ( F_65 ( V_133 , V_214 , V_190 . V_215 ) ||
F_63 ( V_133 , V_216 , sizeof( V_210 ) , & V_210 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_92 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_132 * V_205 ;
T_4 * V_28 = F_39 ( V_135 ) ;
T_4 V_206 = F_69 ( V_133 ) . V_146 ;
T_4 V_124 = V_135 -> V_145 ;
V_205 = F_78 ( F_89 () , V_186 ) ;
if ( V_205 == NULL )
return - V_63 ;
if ( F_90 ( V_205 , V_107 , V_206 , V_124 , * V_28 ) < 0 )
F_87 () ;
return F_88 ( V_107 -> V_125 . V_207 , V_205 , V_206 ) ;
}
static int F_93 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_149 * V_26 = F_39 ( V_135 ) ;
struct V_81 * V_82 ;
struct V_132 * V_217 ;
int V_34 = - V_153 ;
V_82 = F_49 ( V_107 , V_26 , V_5 , & V_34 ) ;
if ( V_82 == NULL )
goto V_218;
V_217 = F_77 ( V_133 , V_82 , V_135 -> V_145 ) ;
if ( F_94 ( V_217 ) ) {
V_34 = F_95 ( V_217 ) ;
} else {
V_34 = F_88 ( V_107 -> V_125 . V_207 , V_217 , F_69 ( V_133 ) . V_146 ) ;
}
F_36 ( V_82 ) ;
V_218:
return V_34 ;
}
static int F_96 ( struct V_219 * V_26 )
{
switch ( V_26 -> V_183 . V_30 . V_31 ) {
case V_41 :
case V_32 :
break;
case V_45 :
if ( V_26 -> V_220 >= 0x10000 )
return - V_10 ;
break;
default:
return - V_10 ;
}
if ( V_26 -> V_221 > V_26 -> V_220 )
return - V_10 ;
return 0 ;
}
static int F_97 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_81 * V_82 ;
struct V_219 * V_26 ;
struct V_132 * V_217 ;
T_1 * V_154 ;
int V_35 ;
int V_34 ;
T_4 V_122 ;
struct V_150 V_151 ;
V_26 = F_39 ( V_135 ) ;
V_34 = F_96 ( V_26 ) ;
if ( V_34 )
goto V_218;
V_35 = V_26 -> V_183 . V_35 ;
V_154 = & V_26 -> V_183 . V_30 . V_154 ;
V_82 = NULL ;
V_122 = F_32 ( V_5 , & V_151 ) ;
if ( V_26 -> V_183 . V_124 ) {
V_82 = F_98 ( V_107 , V_122 , V_26 -> V_183 . V_124 ) ;
if ( V_82 && F_99 ( & V_82 -> V_30 . V_154 , V_154 , V_35 ) ) {
F_36 ( V_82 ) ;
V_82 = NULL ;
}
}
if ( ! V_82 )
V_82 = F_100 ( V_107 , & V_151 , V_26 -> V_183 . V_43 , V_26 -> V_183 . V_85 ,
V_26 -> V_183 . V_30 . V_31 , V_154 ,
& V_26 -> V_183 . V_86 , 1 ,
V_35 ) ;
V_34 = - V_222 ;
if ( V_82 == NULL )
goto V_218;
V_34 = F_101 ( V_82 , V_26 -> V_221 , V_26 -> V_220 ) ;
if ( V_34 )
goto V_40;
V_217 = F_77 ( V_133 , V_82 , V_135 -> V_145 ) ;
if ( F_94 ( V_217 ) ) {
V_34 = F_95 ( V_217 ) ;
goto V_40;
}
V_34 = F_88 ( V_107 -> V_125 . V_207 , V_217 , F_69 ( V_133 ) . V_146 ) ;
V_40:
F_36 ( V_82 ) ;
V_218:
return V_34 ;
}
static int F_102 ( T_2 V_223 )
{
switch ( V_223 ) {
case V_224 :
case V_225 :
case V_226 :
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_103 ( T_2 type )
{
switch ( type ) {
case V_227 :
#ifdef F_104
case V_228 :
#endif
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_105 ( struct V_229 * V_26 )
{
switch ( V_26 -> V_230 ) {
case V_231 :
case V_232 :
case V_233 :
case V_234 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_235 ) {
case V_236 :
case V_237 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_83 . V_35 ) {
case V_36 :
break;
case V_37 :
#if F_13 ( V_38 )
break;
#else
return - V_39 ;
#endif
default:
return - V_10 ;
}
return F_102 ( V_26 -> V_223 ) ;
}
static int F_106 ( struct V_238 * V_239 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_21 * V_22 ;
if ( ! V_7 )
return 0 ;
V_22 = F_3 ( V_7 ) ;
return F_107 ( & V_239 -> V_171 , V_22 ) ;
}
static void F_108 ( struct V_238 * V_240 , struct V_241 * V_242 ,
int V_243 )
{
int V_244 ;
V_240 -> V_245 = V_243 ;
for ( V_244 = 0 ; V_244 < V_243 ; V_244 ++ , V_242 ++ ) {
struct V_246 * V_247 = & V_240 -> V_248 [ V_244 ] ;
memcpy ( & V_247 -> V_30 , & V_242 -> V_30 , sizeof( struct V_249 ) ) ;
memcpy ( & V_247 -> V_86 , & V_242 -> V_86 ,
sizeof( T_1 ) ) ;
V_247 -> V_85 = V_242 -> V_85 ;
V_247 -> V_43 = V_242 -> V_43 ;
V_247 -> V_230 = V_242 -> V_230 ;
V_247 -> V_250 = V_242 -> V_250 ;
V_247 -> V_251 = V_242 -> V_251 ;
V_247 -> V_252 = V_242 -> V_252 ;
V_247 -> V_253 = V_242 -> V_253 ;
V_247 -> V_254 = ! ~ ( V_247 -> V_251 & V_247 -> V_252 & V_247 -> V_253 ) ;
V_247 -> V_255 = V_242 -> V_35 ;
}
}
static int F_109 ( int V_243 , struct V_241 * V_242 , T_6 V_35 )
{
int V_244 ;
if ( V_243 > V_256 )
return - V_10 ;
for ( V_244 = 0 ; V_244 < V_243 ; V_244 ++ ) {
if ( ! V_242 [ V_244 ] . V_35 )
V_242 [ V_244 ] . V_35 = V_35 ;
switch ( V_242 [ V_244 ] . V_35 ) {
case V_36 :
break;
#if F_13 ( V_38 )
case V_37 :
break;
#endif
default:
return - V_10 ;
}
}
return 0 ;
}
static int F_110 ( struct V_238 * V_239 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_257 ] ;
if ( ! V_7 ) {
V_239 -> V_245 = 0 ;
} else {
struct V_241 * V_258 = F_3 ( V_7 ) ;
int V_243 = F_4 ( V_7 ) / sizeof( * V_258 ) ;
int V_34 ;
V_34 = F_109 ( V_243 , V_258 , V_239 -> V_35 ) ;
if ( V_34 )
return V_34 ;
F_108 ( V_239 , V_258 , V_243 ) ;
}
return 0 ;
}
static int F_111 ( T_2 * V_259 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_260 ] ;
struct V_261 * V_262 ;
T_2 type = V_227 ;
int V_34 ;
if ( V_7 ) {
V_262 = F_3 ( V_7 ) ;
type = V_262 -> type ;
}
V_34 = F_103 ( type ) ;
if ( V_34 )
return V_34 ;
* V_259 = type ;
return 0 ;
}
static void F_112 ( struct V_238 * V_240 , struct V_229 * V_26 )
{
V_240 -> V_263 = V_26 -> V_263 ;
V_240 -> V_264 = V_26 -> V_264 ;
memcpy ( & V_240 -> V_265 , & V_26 -> V_83 , sizeof( V_240 -> V_265 ) ) ;
memcpy ( & V_240 -> V_84 , & V_26 -> V_84 , sizeof( V_240 -> V_84 ) ) ;
V_240 -> V_235 = V_26 -> V_235 ;
V_240 -> V_28 = V_26 -> V_28 ;
V_240 -> V_35 = V_26 -> V_83 . V_35 ;
}
static void F_113 ( struct V_238 * V_240 , struct V_229 * V_26 , int V_223 )
{
memcpy ( & V_26 -> V_83 , & V_240 -> V_265 , sizeof( V_26 -> V_83 ) ) ;
memcpy ( & V_26 -> V_84 , & V_240 -> V_84 , sizeof( V_26 -> V_84 ) ) ;
memcpy ( & V_26 -> V_100 , & V_240 -> V_100 , sizeof( V_26 -> V_100 ) ) ;
V_26 -> V_263 = V_240 -> V_263 ;
V_26 -> V_264 = V_240 -> V_264 ;
V_26 -> V_83 . V_35 = V_240 -> V_35 ;
V_26 -> V_223 = V_223 ;
V_26 -> V_235 = V_240 -> V_235 ;
V_26 -> V_28 = V_240 -> V_28 ;
V_26 -> V_230 = V_231 ;
}
static struct V_238 * F_114 ( struct V_107 * V_107 , struct V_229 * V_26 , struct V_4 * * V_5 , int * V_108 )
{
struct V_238 * V_240 = F_115 ( V_107 , V_62 ) ;
int V_34 ;
if ( ! V_240 ) {
* V_108 = - V_63 ;
return NULL ;
}
F_112 ( V_240 , V_26 ) ;
V_34 = F_111 ( & V_240 -> type , V_5 ) ;
if ( V_34 )
goto error;
if ( ! ( V_34 = F_110 ( V_240 , V_5 ) ) )
V_34 = F_106 ( V_240 , V_5 ) ;
if ( V_34 )
goto error;
F_32 ( V_5 , & V_240 -> V_122 ) ;
return V_240 ;
error:
* V_108 = V_34 ;
V_240 -> V_182 . V_266 = 1 ;
F_116 ( V_240 ) ;
return NULL ;
}
static int F_117 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_229 * V_26 = F_39 ( V_135 ) ;
struct V_238 * V_240 ;
struct V_137 V_138 ;
int V_34 ;
int V_267 ;
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
V_34 = F_105 ( V_26 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_240 = F_114 ( V_107 , V_26 , V_5 , & V_34 ) ;
if ( ! V_240 )
return V_34 ;
V_267 = V_135 -> V_143 == V_268 ;
V_34 = F_118 ( V_26 -> V_223 , V_240 , V_267 ) ;
F_45 ( V_140 , & V_142 ) ;
F_119 ( V_240 , V_34 ? 0 : 1 , V_139 , V_141 , V_142 ) ;
if ( V_34 ) {
F_120 ( V_240 -> V_171 ) ;
F_24 ( V_240 ) ;
return V_34 ;
}
V_138 . V_148 = V_135 -> V_143 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
F_121 ( V_240 , V_26 -> V_223 , & V_138 ) ;
F_122 ( V_240 ) ;
return 0 ;
}
static int F_123 ( struct V_238 * V_240 , struct V_132 * V_133 )
{
struct V_241 V_269 [ V_256 ] ;
int V_244 ;
if ( V_240 -> V_245 == 0 )
return 0 ;
for ( V_244 = 0 ; V_244 < V_240 -> V_245 ; V_244 ++ ) {
struct V_241 * V_76 = & V_269 [ V_244 ] ;
struct V_246 * V_270 = & V_240 -> V_248 [ V_244 ] ;
memcpy ( & V_76 -> V_30 , & V_270 -> V_30 , sizeof( V_76 -> V_30 ) ) ;
V_76 -> V_35 = V_270 -> V_255 ;
memcpy ( & V_76 -> V_86 , & V_270 -> V_86 , sizeof( V_76 -> V_86 ) ) ;
V_76 -> V_85 = V_270 -> V_85 ;
V_76 -> V_43 = V_270 -> V_43 ;
V_76 -> V_230 = V_270 -> V_230 ;
V_76 -> V_250 = V_270 -> V_250 ;
V_76 -> V_251 = V_270 -> V_251 ;
V_76 -> V_252 = V_270 -> V_252 ;
V_76 -> V_253 = V_270 -> V_253 ;
}
return F_63 ( V_133 , V_257 ,
sizeof( struct V_241 ) * V_240 -> V_245 , V_269 ) ;
}
static inline int F_124 ( struct V_81 * V_82 , struct V_132 * V_133 )
{
if ( V_82 -> V_171 ) {
return F_59 ( V_82 -> V_171 , V_133 ) ;
}
return 0 ;
}
static inline int F_125 ( struct V_238 * V_240 , struct V_132 * V_133 )
{
if ( V_240 -> V_171 ) {
return F_59 ( V_240 -> V_171 , V_133 ) ;
}
return 0 ;
}
static inline T_5 F_126 ( void )
{
#ifdef F_104
return F_83 ( sizeof( struct V_261 ) ) ;
#else
return 0 ;
#endif
}
static int F_127 ( T_2 type , struct V_132 * V_133 )
{
struct V_261 V_262 = {
. type = type ,
} ;
return F_63 ( V_133 , V_260 , sizeof( V_262 ) , & V_262 ) ;
}
static inline int F_127 ( T_2 type , struct V_132 * V_133 )
{
return 0 ;
}
static int F_128 ( struct V_238 * V_240 , int V_223 , int V_172 , void * V_173 )
{
struct V_174 * V_175 = V_173 ;
struct V_229 * V_26 ;
struct V_132 * V_176 = V_175 -> V_176 ;
struct V_132 * V_133 = V_175 -> V_177 ;
struct V_134 * V_135 ;
V_135 = F_68 ( V_133 , F_69 ( V_176 ) . V_146 , V_175 -> V_145 ,
V_268 , sizeof( * V_26 ) , V_175 -> V_178 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_26 = F_39 ( V_135 ) ;
F_113 ( V_240 , V_26 , V_223 ) ;
if ( F_123 ( V_240 , V_133 ) < 0 )
goto V_271;
if ( F_125 ( V_240 , V_133 ) )
goto V_271;
if ( F_127 ( V_240 -> type , V_133 ) < 0 )
goto V_271;
if ( F_66 ( V_133 , & V_240 -> V_122 ) )
goto V_168;
F_70 ( V_133 , V_135 ) ;
return 0 ;
V_168:
V_271:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_129 ( struct V_179 * V_180 )
{
struct V_272 * V_182 = (struct V_272 * ) & V_180 -> args [ 1 ] ;
F_130 ( V_182 ) ;
return 0 ;
}
static int F_131 ( struct V_132 * V_133 , struct V_179 * V_180 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_272 * V_182 = (struct V_272 * ) & V_180 -> args [ 1 ] ;
struct V_174 V_183 ;
F_75 ( sizeof( struct V_272 ) >
sizeof( V_180 -> args ) - sizeof( V_180 -> args [ 0 ] ) ) ;
V_183 . V_176 = V_180 -> V_133 ;
V_183 . V_177 = V_133 ;
V_183 . V_145 = V_180 -> V_135 -> V_145 ;
V_183 . V_178 = V_184 ;
if ( ! V_180 -> args [ 0 ] ) {
V_180 -> args [ 0 ] = 1 ;
F_132 ( V_182 , V_273 ) ;
}
( void ) V_272 ( V_107 , V_182 , F_128 , & V_183 ) ;
return V_133 -> V_23 ;
}
static struct V_132 * F_133 ( struct V_132 * V_176 ,
struct V_238 * V_240 ,
int V_223 , T_4 V_124 )
{
struct V_174 V_183 ;
struct V_132 * V_133 ;
V_133 = F_78 ( V_185 , V_62 ) ;
if ( ! V_133 )
return F_79 ( - V_63 ) ;
V_183 . V_176 = V_176 ;
V_183 . V_177 = V_133 ;
V_183 . V_145 = V_124 ;
V_183 . V_178 = 0 ;
if ( F_128 ( V_240 , V_223 , 0 , & V_183 ) < 0 ) {
F_80 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
static int F_134 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_238 * V_240 ;
struct V_274 * V_26 ;
T_2 type = V_227 ;
int V_34 ;
struct V_137 V_138 ;
int V_275 ;
struct V_150 V_151 ;
T_4 V_122 = F_32 ( V_5 , & V_151 ) ;
V_26 = F_39 ( V_135 ) ;
V_275 = V_135 -> V_143 == V_276 ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_102 ( V_26 -> V_223 ) ;
if ( V_34 )
return V_34 ;
if ( V_26 -> V_264 )
V_240 = F_135 ( V_107 , V_122 , type , V_26 -> V_223 , V_26 -> V_264 , V_275 , & V_34 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_79 * V_277 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_277 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_34 = F_107 ( & V_277 , V_22 ) ;
if ( V_34 )
return V_34 ;
}
V_240 = F_136 ( V_107 , V_122 , type , V_26 -> V_223 , & V_26 -> V_83 ,
V_277 , V_275 , & V_34 ) ;
F_120 ( V_277 ) ;
}
if ( V_240 == NULL )
return - V_222 ;
if ( ! V_275 ) {
struct V_132 * V_217 ;
V_217 = F_133 ( V_133 , V_240 , V_26 -> V_223 , V_135 -> V_145 ) ;
if ( F_94 ( V_217 ) ) {
V_34 = F_95 ( V_217 ) ;
} else {
V_34 = F_88 ( V_107 -> V_125 . V_207 , V_217 ,
F_69 ( V_133 ) . V_146 ) ;
}
} else {
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
F_45 ( V_140 , & V_142 ) ;
F_137 ( V_240 , V_34 ? 0 : 1 , V_139 , V_141 ,
V_142 ) ;
if ( V_34 != 0 )
goto V_40;
V_138 . V_278 . V_279 = V_26 -> V_264 ;
V_138 . V_148 = V_135 -> V_143 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
F_121 ( V_240 , V_26 -> V_223 , & V_138 ) ;
}
V_40:
F_122 ( V_240 ) ;
return V_34 ;
}
static int F_138 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_137 V_138 ;
struct V_280 * V_26 = F_39 ( V_135 ) ;
struct V_281 V_282 ;
int V_34 ;
V_282 . V_139 = F_40 ( V_140 ) ;
V_282 . V_141 = F_41 ( V_140 ) ;
F_45 ( V_140 , & V_282 . V_283 ) ;
V_34 = F_139 ( V_107 , V_26 -> V_31 , & V_282 ) ;
if ( V_34 ) {
if ( V_34 == - V_153 )
return 0 ;
return V_34 ;
}
V_138 . V_278 . V_31 = V_26 -> V_31 ;
V_138 . V_148 = V_135 -> V_143 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
V_138 . V_107 = V_107 ;
F_48 ( NULL , & V_138 ) ;
return 0 ;
}
static inline T_5 F_140 ( struct V_81 * V_82 )
{
T_5 V_284 = V_82 -> V_74 ?
F_22 ( V_82 -> V_74 ) :
sizeof( struct V_95 ) ;
return F_82 ( sizeof( struct V_285 ) )
+ F_83 ( V_284 )
+ F_83 ( sizeof( struct V_98 ) )
+ F_83 ( sizeof( struct V_150 ) )
+ F_83 ( 4 )
+ F_83 ( 4 ) ;
}
static int F_141 ( struct V_132 * V_133 , struct V_81 * V_82 , const struct V_137 * V_138 )
{
struct V_285 * V_30 ;
struct V_134 * V_135 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , V_138 -> V_124 , V_286 , sizeof( * V_30 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_30 = F_39 ( V_135 ) ;
memcpy ( & V_30 -> V_287 . V_154 , & V_82 -> V_30 . V_154 , sizeof( V_82 -> V_30 . V_154 ) ) ;
V_30 -> V_287 . V_155 = V_82 -> V_30 . V_155 ;
V_30 -> V_287 . V_35 = V_82 -> V_54 . V_35 ;
V_30 -> V_287 . V_31 = V_82 -> V_30 . V_31 ;
memcpy ( & V_30 -> V_86 , & V_82 -> V_54 . V_86 , sizeof( V_82 -> V_54 . V_86 ) ) ;
V_30 -> V_85 = V_82 -> V_54 . V_85 ;
V_30 -> V_28 = V_138 -> V_278 . V_288 ;
if ( V_82 -> V_74 ) {
if ( F_63 ( V_133 , V_27 ,
F_22 ( V_82 -> V_74 ) ,
V_82 -> V_74 ) )
goto V_168;
} else {
if ( F_63 ( V_133 , V_88 , sizeof( V_82 -> V_96 ) ,
& V_82 -> V_96 ) )
goto V_168;
}
if ( F_63 ( V_133 , V_91 , sizeof( V_82 -> V_100 ) , & V_82 -> V_100 ) )
goto V_168;
if ( ( V_30 -> V_28 & V_289 ) &&
F_65 ( V_133 , V_94 , V_82 -> V_106 ) )
goto V_168;
if ( ( V_30 -> V_28 & V_290 ) &&
F_65 ( V_133 , V_93 ,
V_82 -> V_105 * 10 / V_128 ) )
goto V_168;
if ( F_66 ( V_133 , & V_82 -> V_122 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_142 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_81 * V_82 ;
struct V_132 * V_205 ;
int V_34 ;
struct V_137 V_138 ;
T_4 V_122 ;
struct V_150 V_151 ;
struct V_285 * V_26 = F_39 ( V_135 ) ;
struct V_149 * V_30 = & V_26 -> V_287 ;
V_122 = F_32 ( V_5 , & V_151 ) ;
V_82 = F_51 ( V_107 , V_122 , & V_30 -> V_154 , V_30 -> V_155 , V_30 -> V_31 , V_30 -> V_35 ) ;
if ( V_82 == NULL )
return - V_153 ;
V_205 = F_78 ( F_140 ( V_82 ) , V_186 ) ;
if ( V_205 == NULL ) {
F_36 ( V_82 ) ;
return - V_63 ;
}
F_143 ( & V_82 -> V_291 ) ;
V_138 . V_278 . V_288 = V_26 -> V_28 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
if ( F_141 ( V_205 , V_82 , & V_138 ) < 0 )
F_87 () ;
V_34 = F_88 ( V_107 -> V_125 . V_207 , V_205 , F_69 ( V_133 ) . V_146 ) ;
F_144 ( & V_82 -> V_291 ) ;
F_36 ( V_82 ) ;
return V_34 ;
}
static int F_145 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_81 * V_82 ;
struct V_137 V_138 ;
int V_34 = - V_10 ;
T_4 V_122 = 0 ;
struct V_150 V_151 ;
struct V_285 * V_26 = F_39 ( V_135 ) ;
struct V_4 * V_75 = V_5 [ V_88 ] ;
struct V_4 * V_89 = V_5 [ V_27 ] ;
struct V_4 * V_90 = V_5 [ V_91 ] ;
if ( ! V_90 && ! V_75 && ! V_89 )
return V_34 ;
if ( ! ( V_135 -> V_178 & V_292 ) )
return V_34 ;
V_122 = F_32 ( V_5 , & V_151 ) ;
V_82 = F_51 ( V_107 , V_122 , & V_26 -> V_287 . V_154 , V_26 -> V_287 . V_155 , V_26 -> V_287 . V_31 , V_26 -> V_287 . V_35 ) ;
if ( V_82 == NULL )
return - V_153 ;
if ( V_82 -> V_123 . V_130 != V_293 )
goto V_40;
V_34 = F_21 ( V_82 -> V_74 , V_75 ) ;
if ( V_34 )
goto V_40;
F_143 ( & V_82 -> V_291 ) ;
F_27 ( V_82 , V_5 ) ;
F_144 ( & V_82 -> V_291 ) ;
V_138 . V_148 = V_135 -> V_143 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
V_138 . V_278 . V_288 = V_294 ;
F_48 ( V_82 , & V_138 ) ;
V_34 = 0 ;
V_40:
F_36 ( V_82 ) ;
return V_34 ;
}
static int F_146 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_137 V_138 ;
T_2 type = V_227 ;
int V_34 ;
struct V_281 V_282 ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_282 . V_139 = F_40 ( V_140 ) ;
V_282 . V_141 = F_41 ( V_140 ) ;
F_45 ( V_140 , & V_282 . V_283 ) ;
V_34 = F_147 ( V_107 , type , & V_282 ) ;
if ( V_34 ) {
if ( V_34 == - V_153 )
return 0 ;
return V_34 ;
}
V_138 . V_278 . type = type ;
V_138 . V_148 = V_135 -> V_143 ;
V_138 . V_124 = V_135 -> V_145 ;
V_138 . V_146 = V_135 -> V_147 ;
V_138 . V_107 = V_107 ;
F_121 ( NULL , 0 , & V_138 ) ;
return 0 ;
}
static int F_148 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_238 * V_240 ;
struct V_295 * V_76 = F_39 ( V_135 ) ;
struct V_229 * V_26 = & V_76 -> V_239 ;
T_2 type = V_227 ;
int V_34 = - V_222 ;
struct V_150 V_151 ;
T_4 V_122 = F_32 ( V_5 , & V_151 ) ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_102 ( V_26 -> V_223 ) ;
if ( V_34 )
return V_34 ;
if ( V_26 -> V_264 )
V_240 = F_135 ( V_107 , V_122 , type , V_26 -> V_223 , V_26 -> V_264 , 0 , & V_34 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_79 * V_277 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_277 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_34 = F_107 ( & V_277 , V_22 ) ;
if ( V_34 )
return V_34 ;
}
V_240 = F_136 ( V_107 , V_122 , type , V_26 -> V_223 ,
& V_26 -> V_83 , V_277 , 0 , & V_34 ) ;
F_120 ( V_277 ) ;
}
if ( V_240 == NULL )
return - V_222 ;
if ( F_149 ( V_240 -> V_182 . V_266 ) )
goto V_40;
V_34 = 0 ;
if ( V_76 -> V_296 ) {
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
F_45 ( V_140 , & V_142 ) ;
F_150 ( V_240 , V_26 -> V_223 ) ;
F_137 ( V_240 , 1 , V_139 , V_141 , V_142 ) ;
} else {
F_151 ( 1 , L_1 ) ;
}
F_152 ( V_240 , V_26 -> V_223 , V_76 -> V_296 , V_140 -> V_146 ) ;
V_40:
F_122 ( V_240 ) ;
return V_34 ;
}
static int F_153 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_81 * V_82 ;
int V_34 ;
struct V_297 * V_298 = F_39 ( V_135 ) ;
struct V_25 * V_26 = & V_298 -> V_130 ;
struct V_150 V_151 ;
T_4 V_122 = F_32 ( V_5 , & V_151 ) ;
V_82 = F_51 ( V_107 , V_122 , & V_26 -> V_30 . V_154 , V_26 -> V_30 . V_155 , V_26 -> V_30 . V_31 , V_26 -> V_35 ) ;
V_34 = - V_222 ;
if ( V_82 == NULL )
return V_34 ;
F_143 ( & V_82 -> V_291 ) ;
V_34 = - V_10 ;
if ( V_82 -> V_123 . V_130 != V_293 )
goto V_40;
F_154 ( V_82 , V_298 -> V_296 , V_140 -> V_146 ) ;
if ( V_298 -> V_296 ) {
T_3 V_139 = F_40 ( V_140 ) ;
T_4 V_141 = F_41 ( V_140 ) ;
T_4 V_142 ;
F_45 ( V_140 , & V_142 ) ;
F_155 ( V_82 ) ;
F_57 ( V_82 , 1 , V_139 , V_141 , V_142 ) ;
}
V_34 = 0 ;
V_40:
F_144 ( & V_82 -> V_291 ) ;
F_36 ( V_82 ) ;
return V_34 ;
}
static int F_156 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_238 * V_240 ;
struct V_241 * V_242 ;
int V_244 ;
struct V_4 * V_7 = V_5 [ V_257 ] ;
struct V_150 V_122 ;
struct V_299 * V_300 = F_39 ( V_135 ) ;
struct V_81 * V_82 = F_30 ( V_107 ) ;
int V_34 = - V_63 ;
if ( ! V_82 )
goto V_301;
F_32 ( V_5 , & V_122 ) ;
V_34 = F_105 ( & V_300 -> V_302 ) ;
if ( V_34 )
goto V_303;
V_240 = F_114 ( V_107 , & V_300 -> V_302 , V_5 , & V_34 ) ;
if ( ! V_240 )
goto V_304;
memcpy ( & V_82 -> V_30 , & V_300 -> V_30 , sizeof( V_300 -> V_30 ) ) ;
memcpy ( & V_82 -> V_54 . V_86 , & V_300 -> V_86 , sizeof( V_300 -> V_86 ) ) ;
memcpy ( & V_82 -> V_83 , & V_300 -> V_83 , sizeof( V_300 -> V_83 ) ) ;
V_240 -> V_122 . V_151 = V_82 -> V_122 . V_151 = V_122 . V_151 ;
V_240 -> V_122 . V_305 = V_82 -> V_122 . V_305 = V_122 . V_305 ;
V_242 = F_3 ( V_7 ) ;
for ( V_244 = 0 ; V_244 < V_240 -> V_245 ; V_244 ++ , V_242 ++ ) {
struct V_246 * V_247 = & V_240 -> V_248 [ V_244 ] ;
memcpy ( & V_82 -> V_30 , & V_247 -> V_30 , sizeof( V_82 -> V_30 ) ) ;
V_82 -> V_54 . V_43 = V_247 -> V_43 ;
V_82 -> V_54 . V_85 = V_247 -> V_85 ;
V_82 -> V_54 . V_35 = V_242 -> V_35 ;
V_247 -> V_251 = V_300 -> V_251 ;
V_247 -> V_252 = V_300 -> V_252 ;
V_247 -> V_253 = V_300 -> V_253 ;
V_34 = F_157 ( V_82 , V_247 , V_240 ) ;
}
F_24 ( V_82 ) ;
F_24 ( V_240 ) ;
return 0 ;
V_303:
F_151 ( 1 , L_2 ) ;
V_304:
F_24 ( V_82 ) ;
V_301:
return V_34 ;
}
static int F_158 ( struct V_306 * V_307 ,
struct V_308 * V_309 ,
struct V_4 * * V_5 , int * V_310 )
{
struct V_4 * V_7 = V_5 [ V_311 ] ;
struct V_312 * V_313 ;
int V_244 , V_314 ;
if ( V_309 != NULL ) {
struct V_315 * V_316 ;
V_316 = F_3 ( V_5 [ V_317 ] ) ;
memcpy ( & V_309 -> V_318 , & V_316 -> V_318 , sizeof( V_309 -> V_318 ) ) ;
memcpy ( & V_309 -> V_319 , & V_316 -> V_319 , sizeof( V_309 -> V_319 ) ) ;
V_309 -> V_35 = V_316 -> V_35 ;
V_309 -> V_320 = V_316 -> V_320 ;
}
V_313 = F_3 ( V_7 ) ;
V_314 = F_4 ( V_7 ) / sizeof( * V_313 ) ;
if ( V_314 <= 0 || V_314 > V_256 )
return - V_10 ;
for ( V_244 = 0 ; V_244 < V_314 ; V_244 ++ , V_313 ++ , V_307 ++ ) {
memcpy ( & V_307 -> V_321 , & V_313 -> V_321 , sizeof( V_307 -> V_321 ) ) ;
memcpy ( & V_307 -> V_322 , & V_313 -> V_322 , sizeof( V_307 -> V_322 ) ) ;
memcpy ( & V_307 -> V_323 , & V_313 -> V_323 , sizeof( V_307 -> V_323 ) ) ;
memcpy ( & V_307 -> V_324 , & V_313 -> V_324 , sizeof( V_307 -> V_324 ) ) ;
V_307 -> V_31 = V_313 -> V_31 ;
V_307 -> V_43 = V_313 -> V_43 ;
V_307 -> V_85 = V_313 -> V_85 ;
V_307 -> V_325 = V_313 -> V_325 ;
V_307 -> V_326 = V_313 -> V_326 ;
}
* V_310 = V_244 ;
return 0 ;
}
static int F_159 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
struct V_274 * V_327 = F_39 ( V_135 ) ;
struct V_306 V_151 [ V_256 ] ;
struct V_308 V_123 , * V_328 ;
T_2 type ;
int V_34 ;
int V_329 = 0 ;
if ( V_5 [ V_311 ] == NULL )
return - V_10 ;
V_328 = V_5 [ V_317 ] ? & V_123 : NULL ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_158 ( (struct V_306 * ) V_151 , V_328 , V_5 , & V_329 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_329 )
return 0 ;
V_306 ( & V_327 -> V_83 , V_327 -> V_223 , type , V_151 , V_329 , V_328 ) ;
return 0 ;
}
static int F_159 ( struct V_132 * V_133 , struct V_134 * V_135 ,
struct V_4 * * V_5 )
{
return - V_330 ;
}
static int F_160 ( const struct V_306 * V_151 , struct V_132 * V_133 )
{
struct V_312 V_313 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_31 = V_151 -> V_31 ;
V_313 . V_43 = V_151 -> V_43 ;
V_313 . V_85 = V_151 -> V_85 ;
V_313 . V_325 = V_151 -> V_325 ;
memcpy ( & V_313 . V_321 , & V_151 -> V_321 , sizeof( V_313 . V_321 ) ) ;
memcpy ( & V_313 . V_322 , & V_151 -> V_322 , sizeof( V_313 . V_322 ) ) ;
V_313 . V_326 = V_151 -> V_326 ;
memcpy ( & V_313 . V_323 , & V_151 -> V_323 , sizeof( V_313 . V_323 ) ) ;
memcpy ( & V_313 . V_324 , & V_151 -> V_324 , sizeof( V_313 . V_324 ) ) ;
return F_63 ( V_133 , V_311 , sizeof( V_313 ) , & V_313 ) ;
}
static int F_161 ( const struct V_308 * V_309 , struct V_132 * V_133 )
{
struct V_315 V_316 ;
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
V_316 . V_35 = V_309 -> V_35 ;
V_316 . V_320 = V_309 -> V_320 ;
memcpy ( & V_316 . V_318 , & V_309 -> V_318 , sizeof( V_316 . V_318 ) ) ;
memcpy ( & V_316 . V_319 , & V_309 -> V_319 , sizeof( V_316 . V_319 ) ) ;
return F_63 ( V_133 , V_317 , sizeof( V_316 ) , & V_316 ) ;
}
static inline T_5 F_162 ( int V_314 , int V_331 )
{
return F_82 ( sizeof( struct V_274 ) )
+ ( V_331 ? F_83 ( sizeof( struct V_308 ) ) : 0 )
+ F_83 ( sizeof( struct V_312 ) * V_314 )
+ F_126 () ;
}
static int F_163 ( struct V_132 * V_133 , const struct V_306 * V_151 ,
int V_314 , const struct V_308 * V_309 ,
const struct V_332 * V_83 , T_2 V_223 , T_2 type )
{
const struct V_306 * V_333 ;
struct V_274 * V_334 ;
struct V_134 * V_135 ;
int V_244 ;
V_135 = F_68 ( V_133 , 0 , 0 , V_335 , sizeof( * V_334 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_334 = F_39 ( V_135 ) ;
memset ( V_334 , 0 , sizeof( * V_334 ) ) ;
memcpy ( & V_334 -> V_83 , V_83 , sizeof( V_334 -> V_83 ) ) ;
V_334 -> V_223 = V_223 ;
if ( V_309 != NULL && ( F_161 ( V_309 , V_133 ) < 0 ) )
goto V_271;
if ( F_127 ( type , V_133 ) < 0 )
goto V_271;
for ( V_244 = 0 , V_333 = V_151 ; V_244 < V_314 ; V_244 ++ , V_333 ++ ) {
if ( F_160 ( V_333 , V_133 ) < 0 )
goto V_271;
}
return F_70 ( V_133 , V_135 ) ;
V_271:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_164 ( const struct V_332 * V_83 , T_2 V_223 , T_2 type ,
const struct V_306 * V_151 , int V_314 ,
const struct V_308 * V_309 )
{
struct V_107 * V_107 = & V_336 ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_162 ( V_314 , ! ! V_309 ) , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_163 ( V_133 , V_151 , V_314 , V_309 , V_83 , V_223 , type ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_337 , V_186 ) ;
}
static int F_164 ( const struct V_332 * V_83 , T_2 V_223 , T_2 type ,
const struct V_306 * V_151 , int V_314 ,
const struct V_308 * V_309 )
{
return - V_330 ;
}
static int F_166 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_107 * V_107 = F_38 ( V_133 -> V_136 ) ;
struct V_4 * V_5 [ V_338 + 1 ] ;
struct V_339 * V_340 ;
int type , V_34 ;
type = V_135 -> V_143 ;
if ( type > V_341 )
return - V_10 ;
type -= V_342 ;
V_340 = & V_343 [ type ] ;
if ( ! F_167 ( V_344 ) )
return - V_157 ;
if ( ( type == ( V_345 - V_342 ) ||
type == ( V_346 - V_342 ) ) &&
( V_135 -> V_178 & V_347 ) ) {
if ( V_340 -> V_348 == NULL )
return - V_10 ;
{
struct V_349 V_138 = {
. V_348 = V_340 -> V_348 ,
. V_350 = V_340 -> V_350 ,
} ;
return F_168 ( V_107 -> V_125 . V_207 , V_133 , V_135 , & V_138 ) ;
}
}
V_34 = F_169 ( V_135 , V_351 [ type ] , V_5 , V_338 ,
V_352 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_340 -> V_353 == NULL )
return - V_10 ;
return V_340 -> V_353 ( V_133 , V_135 , V_5 ) ;
}
static void F_170 ( struct V_132 * V_133 )
{
F_171 ( & V_354 ) ;
F_172 ( V_133 , & F_166 ) ;
F_173 ( & V_354 ) ;
}
static inline T_5 F_174 ( void )
{
return F_82 ( sizeof( struct V_297 ) )
+ F_83 ( sizeof( struct V_150 ) ) ;
}
static int F_175 ( struct V_132 * V_133 , struct V_81 * V_82 , const struct V_137 * V_138 )
{
struct V_297 * V_298 ;
struct V_134 * V_135 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , 0 , V_355 , sizeof( * V_298 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_298 = F_39 ( V_135 ) ;
F_58 ( V_82 , & V_298 -> V_130 ) ;
V_298 -> V_296 = ( V_138 -> V_278 . V_296 != 0 ) ? 1 : 0 ;
if ( F_66 ( V_133 , & V_82 -> V_122 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
return - V_162 ;
}
static int F_176 ( struct V_81 * V_82 , const struct V_137 * V_138 )
{
struct V_107 * V_107 = F_177 ( V_82 ) ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_174 () , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_175 ( V_133 , V_82 , V_138 ) < 0 ) {
F_80 ( V_133 ) ;
return - V_162 ;
}
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_356 , V_186 ) ;
}
static int F_178 ( struct V_81 * V_82 , const struct V_137 * V_138 )
{
struct V_107 * V_107 = F_177 ( V_82 ) ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_140 ( V_82 ) , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_141 ( V_133 , V_82 , V_138 ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_357 , V_186 ) ;
}
static int F_179 ( const struct V_137 * V_138 )
{
struct V_107 * V_107 = V_138 -> V_107 ;
struct V_280 * V_26 ;
struct V_134 * V_135 ;
struct V_132 * V_133 ;
int V_23 = F_82 ( sizeof( struct V_280 ) ) ;
V_133 = F_78 ( V_23 , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , V_138 -> V_124 , V_358 , sizeof( * V_26 ) , 0 ) ;
if ( V_135 == NULL ) {
F_80 ( V_133 ) ;
return - V_162 ;
}
V_26 = F_39 ( V_135 ) ;
V_26 -> V_31 = V_138 -> V_278 . V_31 ;
F_70 ( V_133 , V_135 ) ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_359 , V_186 ) ;
}
static inline T_5 F_180 ( struct V_81 * V_82 )
{
T_5 V_360 = 0 ;
if ( V_82 -> V_110 )
V_360 += F_83 ( F_1 ( V_82 -> V_110 ) ) ;
if ( V_82 -> V_112 ) {
V_360 += F_83 ( sizeof( struct V_8 ) +
( V_82 -> V_112 -> V_3 + 7 ) / 8 ) ;
V_360 += F_83 ( F_7 ( V_82 -> V_112 ) ) ;
}
if ( V_82 -> V_114 )
V_360 += F_83 ( F_5 ( V_82 -> V_114 ) ) ;
if ( V_82 -> V_116 )
V_360 += F_83 ( sizeof( * V_82 -> V_116 ) ) ;
if ( V_82 -> V_119 )
V_360 += F_83 ( sizeof( * V_82 -> V_119 ) ) ;
if ( V_82 -> V_120 )
V_360 += F_83 ( sizeof( V_82 -> V_120 ) ) ;
if ( V_82 -> V_74 )
V_360 += F_83 ( F_22 ( V_82 -> V_74 ) ) ;
if ( V_82 -> V_171 )
V_360 += F_83 ( sizeof( struct V_21 ) +
V_82 -> V_171 -> V_24 ) ;
if ( V_82 -> V_121 )
V_360 += F_83 ( sizeof( * V_82 -> V_121 ) ) ;
V_360 += F_83 ( sizeof( V_361 ) ) ;
return V_360 ;
}
static int F_181 ( struct V_81 * V_82 , const struct V_137 * V_138 )
{
struct V_107 * V_107 = F_177 ( V_82 ) ;
struct V_25 * V_26 ;
struct V_149 * V_30 ;
struct V_134 * V_135 ;
struct V_132 * V_133 ;
int V_23 = F_180 ( V_82 ) ;
int V_362 ;
V_362 = sizeof( * V_26 ) ;
if ( V_138 -> V_148 == V_363 ) {
V_23 += F_83 ( V_362 ) ;
V_362 = sizeof( * V_30 ) ;
V_23 += F_83 ( sizeof( struct V_150 ) ) ;
}
V_23 += F_82 ( V_362 ) ;
V_133 = F_78 ( V_23 , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , V_138 -> V_124 , V_138 -> V_148 , V_362 , 0 ) ;
if ( V_135 == NULL )
goto V_168;
V_26 = F_39 ( V_135 ) ;
if ( V_138 -> V_148 == V_363 ) {
struct V_4 * V_160 ;
V_30 = F_39 ( V_135 ) ;
memcpy ( & V_30 -> V_154 , & V_82 -> V_30 . V_154 , sizeof( V_30 -> V_154 ) ) ;
V_30 -> V_155 = V_82 -> V_30 . V_155 ;
V_30 -> V_35 = V_82 -> V_54 . V_35 ;
V_30 -> V_31 = V_82 -> V_30 . V_31 ;
V_160 = F_60 ( V_133 , V_364 , sizeof( * V_26 ) ) ;
if ( V_160 == NULL )
goto V_168;
V_26 = F_3 ( V_160 ) ;
}
if ( F_62 ( V_82 , V_26 , V_133 ) )
goto V_168;
F_70 ( V_133 , V_135 ) ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_359 , V_186 ) ;
V_168:
F_182 ( 1 ) ;
F_80 ( V_133 ) ;
return - 1 ;
}
static int F_183 ( struct V_81 * V_82 , const struct V_137 * V_138 )
{
switch ( V_138 -> V_148 ) {
case V_355 :
return F_176 ( V_82 , V_138 ) ;
case V_286 :
return F_178 ( V_82 , V_138 ) ;
case V_363 :
case V_365 :
case V_144 :
return F_181 ( V_82 , V_138 ) ;
case V_358 :
return F_179 ( V_138 ) ;
default:
F_184 ( V_366 L_3 ,
V_138 -> V_148 ) ;
break;
}
return 0 ;
}
static inline T_5 F_185 ( struct V_81 * V_82 ,
struct V_238 * V_240 )
{
return F_82 ( sizeof( struct V_299 ) )
+ F_83 ( sizeof( struct V_241 ) * V_240 -> V_245 )
+ F_83 ( sizeof( struct V_150 ) )
+ F_83 ( F_25 ( V_82 -> V_171 ) )
+ F_126 () ;
}
static int F_186 ( struct V_132 * V_133 , struct V_81 * V_82 ,
struct V_246 * V_367 , struct V_238 * V_240 ,
int V_223 )
{
struct V_299 * V_300 ;
struct V_134 * V_135 ;
T_7 V_124 = F_187 () ;
V_135 = F_68 ( V_133 , 0 , 0 , V_368 , sizeof( * V_300 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_300 = F_39 ( V_135 ) ;
memcpy ( & V_300 -> V_30 , & V_82 -> V_30 , sizeof( V_300 -> V_30 ) ) ;
memcpy ( & V_300 -> V_86 , & V_82 -> V_54 . V_86 , sizeof( V_300 -> V_86 ) ) ;
memcpy ( & V_300 -> V_83 , & V_82 -> V_83 , sizeof( V_300 -> V_83 ) ) ;
F_113 ( V_240 , & V_300 -> V_302 , V_223 ) ;
V_300 -> V_251 = V_367 -> V_251 ;
V_300 -> V_252 = V_367 -> V_252 ;
V_300 -> V_253 = V_367 -> V_253 ;
V_300 -> V_124 = V_82 -> V_123 . V_124 = V_124 ;
if ( F_123 ( V_240 , V_133 ) < 0 )
goto V_271;
if ( F_124 ( V_82 , V_133 ) )
goto V_271;
if ( F_127 ( V_240 -> type , V_133 ) < 0 )
goto V_271;
if ( F_66 ( V_133 , & V_240 -> V_122 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
V_271:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_188 ( struct V_81 * V_82 , struct V_246 * V_367 ,
struct V_238 * V_240 , int V_223 )
{
struct V_107 * V_107 = F_177 ( V_82 ) ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_185 ( V_82 , V_240 ) , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_186 ( V_133 , V_82 , V_367 , V_240 , V_223 ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_369 , V_186 ) ;
}
static struct V_238 * F_189 ( struct V_370 * V_136 , int V_371 ,
T_2 * V_278 , int V_23 , int * V_223 )
{
struct V_107 * V_107 = F_38 ( V_136 ) ;
struct V_229 * V_26 = (struct V_229 * ) V_278 ;
struct V_241 * V_242 = (struct V_241 * ) ( V_26 + 1 ) ;
struct V_238 * V_240 ;
int V_243 ;
switch ( V_136 -> V_372 ) {
case V_36 :
if ( V_371 != V_373 ) {
* V_223 = - V_374 ;
return NULL ;
}
break;
#if F_13 ( V_38 )
case V_37 :
if ( V_371 != V_375 ) {
* V_223 = - V_374 ;
return NULL ;
}
break;
#endif
default:
* V_223 = - V_10 ;
return NULL ;
}
* V_223 = - V_10 ;
if ( V_23 < sizeof( * V_26 ) ||
F_105 ( V_26 ) )
return NULL ;
V_243 = ( ( V_23 - sizeof( * V_26 ) ) / sizeof( * V_242 ) ) ;
if ( F_109 ( V_243 , V_242 , V_26 -> V_83 . V_35 ) )
return NULL ;
if ( V_26 -> V_223 > V_225 )
return NULL ;
V_240 = F_115 ( V_107 , V_186 ) ;
if ( V_240 == NULL ) {
* V_223 = - V_376 ;
return NULL ;
}
F_112 ( V_240 , V_26 ) ;
V_240 -> type = V_227 ;
F_108 ( V_240 , V_242 , V_243 ) ;
* V_223 = V_26 -> V_223 ;
return V_240 ;
}
static inline T_5 F_190 ( struct V_238 * V_240 )
{
return F_82 ( sizeof( struct V_295 ) )
+ F_83 ( sizeof( struct V_241 ) * V_240 -> V_245 )
+ F_83 ( F_25 ( V_240 -> V_171 ) )
+ F_83 ( sizeof( struct V_150 ) )
+ F_126 () ;
}
static int F_191 ( struct V_132 * V_133 , struct V_238 * V_240 ,
int V_223 , const struct V_137 * V_138 )
{
struct V_295 * V_377 ;
struct V_134 * V_135 ;
int V_296 = V_138 -> V_278 . V_296 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , 0 , V_378 , sizeof( * V_377 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_377 = F_39 ( V_135 ) ;
F_113 ( V_240 , & V_377 -> V_239 , V_223 ) ;
if ( F_123 ( V_240 , V_133 ) < 0 )
goto V_271;
if ( F_125 ( V_240 , V_133 ) )
goto V_271;
if ( F_127 ( V_240 -> type , V_133 ) < 0 )
goto V_271;
if ( F_66 ( V_133 , & V_240 -> V_122 ) )
goto V_168;
V_377 -> V_296 = ! ! V_296 ;
return F_70 ( V_133 , V_135 ) ;
V_168:
V_271:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_192 ( struct V_238 * V_240 , int V_223 , const struct V_137 * V_138 )
{
struct V_107 * V_107 = F_193 ( V_240 ) ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_190 ( V_240 ) , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_191 ( V_133 , V_240 , V_223 , V_138 ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_356 , V_186 ) ;
}
static int F_194 ( struct V_238 * V_240 , int V_223 , const struct V_137 * V_138 )
{
struct V_107 * V_107 = F_193 ( V_240 ) ;
struct V_229 * V_26 ;
struct V_274 * V_30 ;
struct V_134 * V_135 ;
struct V_132 * V_133 ;
int V_23 = F_83 ( sizeof( struct V_241 ) * V_240 -> V_245 ) ;
int V_362 ;
V_362 = sizeof( * V_26 ) ;
if ( V_138 -> V_148 == V_276 ) {
V_23 += F_83 ( V_362 ) ;
V_362 = sizeof( * V_30 ) ;
}
V_23 += F_126 () ;
V_23 += F_83 ( sizeof( struct V_150 ) ) ;
V_23 += F_82 ( V_362 ) ;
V_133 = F_78 ( V_23 , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , V_138 -> V_124 , V_138 -> V_148 , V_362 , 0 ) ;
if ( V_135 == NULL )
goto V_271;
V_26 = F_39 ( V_135 ) ;
if ( V_138 -> V_148 == V_276 ) {
struct V_4 * V_160 ;
V_30 = F_39 ( V_135 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_223 = V_223 ;
if ( V_138 -> V_278 . V_279 )
V_30 -> V_264 = V_240 -> V_264 ;
else
memcpy ( & V_30 -> V_83 , & V_240 -> V_265 , sizeof( V_30 -> V_83 ) ) ;
V_160 = F_60 ( V_133 , V_379 , sizeof( * V_26 ) ) ;
if ( V_160 == NULL )
goto V_271;
V_26 = F_3 ( V_160 ) ;
}
F_113 ( V_240 , V_26 , V_223 ) ;
if ( F_123 ( V_240 , V_133 ) < 0 )
goto V_271;
if ( F_127 ( V_240 -> type , V_133 ) < 0 )
goto V_271;
if ( F_66 ( V_133 , & V_240 -> V_122 ) )
goto V_168;
F_70 ( V_133 , V_135 ) ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_380 , V_186 ) ;
V_168:
V_271:
F_80 ( V_133 ) ;
return - 1 ;
}
static int F_195 ( const struct V_137 * V_138 )
{
struct V_107 * V_107 = V_138 -> V_107 ;
struct V_134 * V_135 ;
struct V_132 * V_133 ;
V_133 = F_78 ( F_126 () , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
V_135 = F_68 ( V_133 , V_138 -> V_146 , V_138 -> V_124 , V_381 , 0 , 0 ) ;
if ( V_135 == NULL )
goto V_271;
if ( F_127 ( V_138 -> V_278 . type , V_133 ) < 0 )
goto V_271;
F_70 ( V_133 , V_135 ) ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_380 , V_186 ) ;
V_271:
F_80 ( V_133 ) ;
return - 1 ;
}
static int F_196 ( struct V_238 * V_240 , int V_223 , const struct V_137 * V_138 )
{
switch ( V_138 -> V_148 ) {
case V_268 :
case V_382 :
case V_276 :
return F_194 ( V_240 , V_223 , V_138 ) ;
case V_381 :
return F_195 ( V_138 ) ;
case V_378 :
return F_192 ( V_240 , V_223 , V_138 ) ;
default:
F_184 ( V_366 L_4 ,
V_138 -> V_148 ) ;
}
return 0 ;
}
static inline T_5 F_197 ( void )
{
return F_82 ( sizeof( struct V_383 ) ) ;
}
static int F_198 ( struct V_132 * V_133 , T_2 V_31 ,
struct V_332 * V_83 , T_1 * V_384 )
{
struct V_383 * V_385 ;
struct V_134 * V_135 ;
V_135 = F_68 ( V_133 , 0 , 0 , V_386 , sizeof( * V_385 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_385 = F_39 ( V_135 ) ;
V_385 -> V_31 = V_31 ;
memcpy ( & V_385 -> V_83 , V_83 , sizeof( V_385 -> V_83 ) ) ;
if ( V_384 &&
F_63 ( V_133 , V_49 , sizeof( * V_384 ) , V_384 ) )
goto V_168;
return F_70 ( V_133 , V_135 ) ;
V_168:
F_71 ( V_133 , V_135 ) ;
return - V_162 ;
}
static int F_199 ( struct V_107 * V_107 , T_2 V_31 ,
struct V_332 * V_83 , T_1 * V_384 )
{
struct V_132 * V_133 ;
V_133 = F_78 ( F_197 () , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_198 ( V_133 , V_31 , V_83 , V_384 ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_387 , V_186 ) ;
}
static inline T_5 F_200 ( void )
{
return F_82 ( sizeof( struct V_388 ) ) ;
}
static int F_201 ( struct V_132 * V_133 , struct V_81 * V_82 ,
T_1 * V_324 , T_8 V_389 )
{
struct V_388 * V_313 ;
struct V_134 * V_135 ;
V_135 = F_68 ( V_133 , 0 , 0 , V_390 , sizeof( * V_313 ) , 0 ) ;
if ( V_135 == NULL )
return - V_162 ;
V_313 = F_39 ( V_135 ) ;
memcpy ( & V_313 -> V_30 . V_154 , & V_82 -> V_30 . V_154 , sizeof( V_313 -> V_30 . V_154 ) ) ;
V_313 -> V_30 . V_155 = V_82 -> V_30 . V_155 ;
V_313 -> V_30 . V_35 = V_82 -> V_54 . V_35 ;
V_313 -> V_30 . V_31 = V_82 -> V_30 . V_31 ;
memcpy ( & V_313 -> V_324 , V_324 , sizeof( V_313 -> V_324 ) ) ;
memcpy ( & V_313 -> V_322 , & V_82 -> V_54 . V_86 , sizeof( V_313 -> V_322 ) ) ;
V_313 -> V_389 = V_389 ;
V_313 -> V_391 = V_82 -> V_119 -> V_392 ;
V_313 -> V_85 = V_82 -> V_54 . V_85 ;
return F_70 ( V_133 , V_135 ) ;
}
static int F_202 ( struct V_81 * V_82 , T_1 * V_393 ,
T_8 V_394 )
{
struct V_107 * V_107 = F_177 ( V_82 ) ;
struct V_132 * V_133 ;
if ( V_82 -> V_30 . V_31 != V_32 )
return - V_10 ;
if ( ! V_82 -> V_119 )
return - V_10 ;
V_133 = F_78 ( F_200 () , V_186 ) ;
if ( V_133 == NULL )
return - V_63 ;
if ( F_201 ( V_133 , V_82 , V_393 , V_394 ) < 0 )
F_87 () ;
return F_165 ( V_107 -> V_125 . V_207 , V_133 , 0 , V_395 , V_186 ) ;
}
static int T_9 F_203 ( struct V_107 * V_107 )
{
struct V_370 * V_207 ;
V_207 = F_204 ( V_107 , V_396 , V_397 ,
F_170 , NULL , V_398 ) ;
if ( V_207 == NULL )
return - V_63 ;
V_107 -> V_125 . V_399 = V_207 ;
F_205 ( V_107 -> V_125 . V_207 , V_207 ) ;
return 0 ;
}
static void T_10 F_206 ( struct V_400 * V_401 )
{
struct V_107 * V_107 ;
F_207 (net, net_exit_list, exit_list)
F_208 ( V_107 -> V_125 . V_207 , NULL ) ;
F_209 () ;
F_207 (net, net_exit_list, exit_list)
F_210 ( V_107 -> V_125 . V_399 ) ;
}
static int T_11 F_211 ( void )
{
int V_402 ;
F_184 ( V_403 L_5 ) ;
V_402 = F_212 ( & V_404 ) ;
if ( V_402 < 0 )
return V_402 ;
V_402 = F_213 ( & V_405 ) ;
if ( V_402 < 0 )
F_214 ( & V_404 ) ;
return V_402 ;
}
static void T_12 F_215 ( void )
{
F_216 ( & V_405 ) ;
F_214 ( & V_404 ) ;
}
