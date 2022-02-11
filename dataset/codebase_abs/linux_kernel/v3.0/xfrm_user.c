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
#if F_13 ( V_38 ) || F_13 ( V_39 )
break;
#else
V_34 = - V_40 ;
goto V_41;
#endif
default:
goto V_41;
}
V_34 = - V_10 ;
switch ( V_26 -> V_30 . V_31 ) {
case V_42 :
if ( ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] ) ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_13 ] ||
V_5 [ V_43 ] )
goto V_41;
break;
case V_32 :
if ( V_5 [ V_13 ] )
goto V_41;
if ( ! V_5 [ V_11 ] &&
! V_5 [ V_16 ] &&
! V_5 [ V_12 ] &&
! V_5 [ V_18 ] )
goto V_41;
if ( ( V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ) &&
V_5 [ V_18 ] )
goto V_41;
if ( V_5 [ V_43 ] &&
V_26 -> V_44 != V_45 )
goto V_41;
break;
case V_46 :
if ( ! V_5 [ V_13 ] ||
V_5 [ V_18 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_12 ] ||
V_5 [ V_43 ] )
goto V_41;
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_47 :
case V_48 :
if ( V_5 [ V_13 ] ||
V_5 [ V_11 ] ||
V_5 [ V_16 ] ||
V_5 [ V_18 ] ||
V_5 [ V_12 ] ||
V_5 [ V_49 ] ||
V_5 [ V_20 ] ||
V_5 [ V_43 ] ||
! V_5 [ V_50 ] )
goto V_41;
break;
#endif
default:
goto V_41;
}
if ( ( V_34 = F_8 ( V_5 ) ) )
goto V_41;
if ( ( V_34 = F_6 ( V_5 ) ) )
goto V_41;
if ( ( V_34 = F_2 ( V_5 , V_11 ) ) )
goto V_41;
if ( ( V_34 = F_2 ( V_5 , V_12 ) ) )
goto V_41;
if ( ( V_34 = F_2 ( V_5 , V_13 ) ) )
goto V_41;
if ( ( V_34 = F_10 ( V_5 ) ) )
goto V_41;
if ( ( V_34 = F_11 ( V_26 , V_5 ) ) )
goto V_41;
V_34 = - V_10 ;
switch ( V_26 -> V_44 ) {
case V_51 :
case V_45 :
case V_52 :
case V_53 :
break;
default:
goto V_41;
}
V_34 = 0 ;
V_41:
return V_34 ;
}
static int F_14 ( struct V_17 * * V_54 , T_2 * V_55 ,
struct V_4 * V_56 )
{
struct V_8 * V_57 ;
struct V_17 * V_26 ;
struct V_58 * V_59 ;
if ( ! V_56 )
return 0 ;
V_57 = F_3 ( V_56 ) ;
V_59 = F_15 ( V_57 -> V_14 , 1 ) ;
if ( ! V_59 )
return - V_60 ;
* V_55 = V_59 -> V_61 . V_62 ;
V_26 = F_16 ( sizeof( * V_26 ) + ( V_57 -> V_3 + 7 ) / 8 , V_63 ) ;
if ( ! V_26 )
return - V_64 ;
strcpy ( V_26 -> V_14 , V_59 -> V_65 ) ;
V_26 -> V_3 = V_57 -> V_3 ;
V_26 -> V_66 = V_59 -> V_67 . V_68 . V_69 ;
memcpy ( V_26 -> V_70 , V_57 -> V_70 , ( V_57 -> V_3 + 7 ) / 8 ) ;
* V_54 = V_26 ;
return 0 ;
}
static int F_17 ( struct V_17 * * V_54 , T_2 * V_55 ,
struct V_4 * V_56 )
{
struct V_17 * V_26 , * V_57 ;
struct V_58 * V_59 ;
if ( ! V_56 )
return 0 ;
V_57 = F_3 ( V_56 ) ;
V_59 = F_15 ( V_57 -> V_14 , 1 ) ;
if ( ! V_59 )
return - V_60 ;
if ( ( V_57 -> V_66 / 8 ) > V_71 ||
V_57 -> V_66 > V_59 -> V_67 . V_68 . V_72 )
return - V_10 ;
* V_55 = V_59 -> V_61 . V_62 ;
V_26 = F_18 ( V_57 , F_7 ( V_57 ) , V_63 ) ;
if ( ! V_26 )
return - V_64 ;
strcpy ( V_26 -> V_14 , V_59 -> V_65 ) ;
if ( ! V_26 -> V_66 )
V_26 -> V_66 = V_59 -> V_67 . V_68 . V_69 ;
* V_54 = V_26 ;
return 0 ;
}
static int F_19 ( struct V_1 * * V_54 , T_2 * V_55 ,
struct V_4 * V_56 )
{
struct V_1 * V_26 , * V_57 ;
struct V_58 * V_59 ;
if ( ! V_56 )
return 0 ;
V_57 = F_3 ( V_56 ) ;
V_59 = F_20 ( V_57 -> V_14 , V_57 -> V_73 , 1 ) ;
if ( ! V_59 )
return - V_60 ;
* V_55 = V_59 -> V_61 . V_62 ;
V_26 = F_18 ( V_57 , F_1 ( V_57 ) , V_63 ) ;
if ( ! V_26 )
return - V_64 ;
strcpy ( V_26 -> V_14 , V_59 -> V_65 ) ;
* V_54 = V_26 ;
return 0 ;
}
static inline int F_21 ( struct V_74 * V_75 ,
struct V_4 * V_76 )
{
struct V_74 * V_77 ;
if ( ! V_75 || ! V_76 )
return 0 ;
V_77 = F_3 ( V_76 ) ;
if ( F_22 ( V_75 ) !=
F_22 ( V_77 ) )
return - V_10 ;
return 0 ;
}
static int F_23 ( struct V_74 * * V_75 ,
struct V_74 * * V_78 ,
struct V_4 * V_56 )
{
struct V_74 * V_26 , * V_79 , * V_77 ;
if ( ! V_56 )
return 0 ;
V_77 = F_3 ( V_56 ) ;
V_26 = F_18 ( V_77 , F_22 ( V_77 ) , V_63 ) ;
if ( ! V_26 )
return - V_64 ;
V_79 = F_18 ( V_77 , F_22 ( V_77 ) , V_63 ) ;
if ( ! V_79 ) {
F_24 ( V_26 ) ;
return - V_64 ;
}
* V_75 = V_26 ;
* V_78 = V_79 ;
return 0 ;
}
static inline int F_25 ( struct V_80 * V_81 )
{
int V_23 = 0 ;
if ( V_81 ) {
V_23 += sizeof( struct V_21 ) ;
V_23 += V_81 -> V_24 ;
}
return V_23 ;
}
static void F_26 ( struct V_82 * V_83 , struct V_25 * V_26 )
{
memcpy ( & V_83 -> V_30 , & V_26 -> V_30 , sizeof( V_83 -> V_30 ) ) ;
memcpy ( & V_83 -> V_84 , & V_26 -> V_84 , sizeof( V_83 -> V_84 ) ) ;
memcpy ( & V_83 -> V_85 , & V_26 -> V_85 , sizeof( V_83 -> V_85 ) ) ;
V_83 -> V_55 . V_44 = V_26 -> V_44 ;
V_83 -> V_55 . V_33 = V_26 -> V_33 ;
V_83 -> V_55 . V_86 = V_26 -> V_86 ;
V_83 -> V_55 . V_35 = V_26 -> V_35 ;
memcpy ( & V_83 -> V_55 . V_87 , & V_26 -> V_87 , sizeof( V_83 -> V_55 . V_87 ) ) ;
V_83 -> V_55 . V_28 = V_26 -> V_28 ;
if ( ! V_83 -> V_84 . V_35 && ! ( V_26 -> V_28 & V_88 ) )
V_83 -> V_84 . V_35 = V_26 -> V_35 ;
}
static void F_27 ( struct V_82 * V_83 , struct V_4 * * V_5 )
{
struct V_4 * V_76 = V_5 [ V_89 ] ;
struct V_4 * V_90 = V_5 [ V_27 ] ;
struct V_4 * V_91 = V_5 [ V_92 ] ;
struct V_4 * V_93 = V_5 [ V_94 ] ;
struct V_4 * V_7 = V_5 [ V_95 ] ;
if ( V_90 ) {
struct V_74 * V_75 ;
V_75 = F_3 ( V_90 ) ;
memcpy ( V_83 -> V_75 , V_75 ,
F_22 ( V_75 ) ) ;
memcpy ( V_83 -> V_78 , V_75 ,
F_22 ( V_75 ) ) ;
}
if ( V_76 ) {
struct V_96 * V_97 ;
V_97 = F_3 ( V_76 ) ;
memcpy ( & V_83 -> V_97 , V_97 , sizeof( * V_97 ) ) ;
memcpy ( & V_83 -> V_98 , V_97 , sizeof( * V_97 ) ) ;
}
if ( V_91 ) {
struct V_99 * V_100 ;
V_100 = F_3 ( V_91 ) ;
V_83 -> V_101 . V_102 = V_100 -> V_102 ;
V_83 -> V_101 . V_103 = V_100 -> V_103 ;
V_83 -> V_101 . V_104 = V_100 -> V_104 ;
V_83 -> V_101 . V_105 = V_100 -> V_105 ;
}
if ( V_93 )
V_83 -> V_106 = F_28 ( V_93 ) ;
if ( V_7 )
V_83 -> V_107 = F_28 ( V_7 ) ;
}
static struct V_82 * F_29 ( struct V_108 * V_108 ,
struct V_25 * V_26 ,
struct V_4 * * V_5 ,
int * V_109 )
{
struct V_82 * V_83 = F_30 ( V_108 ) ;
int V_34 = - V_64 ;
if ( ! V_83 )
goto V_110;
F_26 ( V_83 , V_26 ) ;
if ( ( V_34 = F_19 ( & V_83 -> V_111 , & V_83 -> V_55 . V_112 ,
V_5 [ V_18 ] ) ) )
goto error;
if ( ( V_34 = F_17 ( & V_83 -> V_113 , & V_83 -> V_55 . V_114 ,
V_5 [ V_16 ] ) ) )
goto error;
if ( ! V_83 -> V_55 . V_114 ) {
if ( ( V_34 = F_14 ( & V_83 -> V_113 , & V_83 -> V_55 . V_114 ,
V_5 [ V_11 ] ) ) )
goto error;
}
if ( ( V_34 = F_31 ( & V_83 -> V_115 , & V_83 -> V_55 . V_112 ,
V_116 ,
V_5 [ V_12 ] ) ) )
goto error;
if ( ( V_34 = F_31 ( & V_83 -> V_117 , & V_83 -> V_55 . V_118 ,
V_119 ,
V_5 [ V_13 ] ) ) )
goto error;
if ( V_5 [ V_49 ] ) {
V_83 -> V_120 = F_18 ( F_3 ( V_5 [ V_49 ] ) ,
sizeof( * V_83 -> V_120 ) , V_63 ) ;
if ( V_83 -> V_120 == NULL )
goto error;
}
if ( V_5 [ V_43 ] )
V_83 -> V_121 = F_28 ( V_5 [ V_43 ] ) ;
if ( V_5 [ V_50 ] ) {
V_83 -> V_122 = F_18 ( F_3 ( V_5 [ V_50 ] ) ,
sizeof( * V_83 -> V_122 ) , V_63 ) ;
if ( V_83 -> V_122 == NULL )
goto error;
}
F_32 ( V_5 , & V_83 -> V_123 ) ;
V_34 = F_33 ( V_83 , false ) ;
if ( V_34 )
goto error;
if ( V_5 [ V_20 ] &&
F_34 ( V_83 , F_3 ( V_5 [ V_20 ] ) ) )
goto error;
if ( ( V_34 = F_23 ( & V_83 -> V_75 , & V_83 -> V_78 ,
V_5 [ V_27 ] ) ) )
goto error;
V_83 -> V_124 . V_125 = V_26 -> V_125 ;
V_83 -> V_107 = V_108 -> V_126 . V_127 ;
V_83 -> V_106 = ( V_108 -> V_126 . V_128 * V_129 ) / V_130 ;
if ( ( V_34 = F_35 ( V_83 ) ) )
goto error;
F_27 ( V_83 , V_5 ) ;
return V_83 ;
error:
V_83 -> V_124 . V_131 = V_132 ;
F_36 ( V_83 ) ;
V_110:
* V_109 = V_34 ;
return NULL ;
}
static int F_37 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_25 * V_26 = F_39 ( V_136 ) ;
struct V_82 * V_83 ;
int V_34 ;
struct V_138 V_139 ;
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
V_34 = F_12 ( V_26 , V_5 ) ;
if ( V_34 )
return V_34 ;
V_83 = F_29 ( V_108 , V_26 , V_5 , & V_34 ) ;
if ( ! V_83 )
return V_34 ;
F_42 ( V_83 ) ;
if ( V_136 -> V_144 == V_145 )
V_34 = F_43 ( V_83 ) ;
else
V_34 = F_44 ( V_83 ) ;
F_45 ( V_141 , & V_143 ) ;
F_46 ( V_83 , V_34 ? 0 : 1 , V_140 , V_142 , V_143 ) ;
if ( V_34 < 0 ) {
V_83 -> V_124 . V_131 = V_132 ;
F_47 ( V_83 ) ;
goto V_41;
}
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
V_139 . V_149 = V_136 -> V_144 ;
F_48 ( V_83 , & V_139 ) ;
V_41:
F_36 ( V_83 ) ;
return V_34 ;
}
static struct V_82 * F_49 ( struct V_108 * V_108 ,
struct V_150 * V_26 ,
struct V_4 * * V_5 ,
int * V_109 )
{
struct V_82 * V_83 = NULL ;
struct V_151 V_152 ;
int V_34 ;
T_4 V_123 = F_32 ( V_5 , & V_152 ) ;
if ( F_50 ( V_26 -> V_31 , V_153 ) ) {
V_34 = - V_154 ;
V_83 = F_51 ( V_108 , V_123 , & V_26 -> V_155 , V_26 -> V_156 , V_26 -> V_31 , V_26 -> V_35 ) ;
} else {
T_1 * V_87 = NULL ;
F_9 ( V_5 , V_157 , & V_87 ) ;
if ( ! V_87 ) {
V_34 = - V_10 ;
goto V_41;
}
V_34 = - V_154 ;
V_83 = F_52 ( V_108 , V_123 ,
& V_26 -> V_155 , V_87 ,
V_26 -> V_31 , V_26 -> V_35 ) ;
}
V_41:
if ( ! V_83 && V_109 )
* V_109 = V_34 ;
return V_83 ;
}
static int F_53 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_82 * V_83 ;
int V_34 = - V_154 ;
struct V_138 V_139 ;
struct V_150 * V_26 = F_39 ( V_136 ) ;
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
V_83 = F_49 ( V_108 , V_26 , V_5 , & V_34 ) ;
if ( V_83 == NULL )
return V_34 ;
if ( ( V_34 = F_54 ( V_83 ) ) != 0 )
goto V_41;
if ( F_55 ( V_83 ) ) {
V_34 = - V_158 ;
goto V_41;
}
V_34 = F_56 ( V_83 ) ;
if ( V_34 < 0 )
goto V_41;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
V_139 . V_149 = V_136 -> V_144 ;
F_48 ( V_83 , & V_139 ) ;
V_41:
F_45 ( V_141 , & V_143 ) ;
F_57 ( V_83 , V_34 ? 0 : 1 , V_140 , V_142 , V_143 ) ;
F_36 ( V_83 ) ;
return V_34 ;
}
static void F_58 ( struct V_82 * V_83 , struct V_25 * V_26 )
{
memcpy ( & V_26 -> V_30 , & V_83 -> V_30 , sizeof( V_26 -> V_30 ) ) ;
memcpy ( & V_26 -> V_84 , & V_83 -> V_84 , sizeof( V_26 -> V_84 ) ) ;
memcpy ( & V_26 -> V_85 , & V_83 -> V_85 , sizeof( V_26 -> V_85 ) ) ;
memcpy ( & V_26 -> V_101 , & V_83 -> V_101 , sizeof( V_26 -> V_101 ) ) ;
memcpy ( & V_26 -> V_159 , & V_83 -> V_159 , sizeof( V_26 -> V_159 ) ) ;
memcpy ( & V_26 -> V_87 , & V_83 -> V_55 . V_87 , sizeof( V_26 -> V_87 ) ) ;
V_26 -> V_44 = V_83 -> V_55 . V_44 ;
V_26 -> V_33 = V_83 -> V_55 . V_33 ;
V_26 -> V_86 = V_83 -> V_55 . V_86 ;
V_26 -> V_35 = V_83 -> V_55 . V_35 ;
V_26 -> V_28 = V_83 -> V_55 . V_28 ;
V_26 -> V_125 = V_83 -> V_124 . V_125 ;
}
static int F_59 ( struct V_80 * V_160 , struct V_133 * V_134 )
{
struct V_21 * V_22 ;
struct V_4 * V_161 ;
int V_162 = sizeof( * V_22 ) + V_160 -> V_24 ;
V_161 = F_60 ( V_134 , V_20 , V_162 ) ;
if ( V_161 == NULL )
return - V_163 ;
V_22 = F_3 ( V_161 ) ;
V_22 -> V_164 = V_20 ;
V_22 -> V_23 = V_162 ;
V_22 -> V_165 = V_160 -> V_165 ;
V_22 -> V_166 = V_160 -> V_166 ;
V_22 -> V_24 = V_160 -> V_24 ;
memcpy ( V_22 + 1 , V_160 -> V_167 , V_160 -> V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_17 * V_68 , struct V_133 * V_134 )
{
struct V_8 * V_59 ;
struct V_4 * V_168 ;
V_168 = F_60 ( V_134 , V_11 ,
sizeof( * V_59 ) + ( V_68 -> V_3 + 7 ) / 8 ) ;
if ( ! V_168 )
return - V_163 ;
V_59 = F_3 ( V_168 ) ;
strcpy ( V_59 -> V_14 , V_68 -> V_14 ) ;
memcpy ( V_59 -> V_70 , V_68 -> V_70 , ( V_68 -> V_3 + 7 ) / 8 ) ;
V_59 -> V_3 = V_68 -> V_3 ;
return 0 ;
}
static int F_62 ( struct V_82 * V_83 ,
struct V_25 * V_26 ,
struct V_133 * V_134 )
{
F_58 ( V_83 , V_26 ) ;
if ( V_83 -> V_122 )
F_63 ( V_134 , V_50 , sizeof( * V_83 -> V_122 ) , V_83 -> V_122 ) ;
if ( V_83 -> V_169 )
F_64 ( V_134 , V_170 , V_83 -> V_169 ) ;
if ( V_83 -> V_111 )
F_63 ( V_134 , V_18 , F_1 ( V_83 -> V_111 ) , V_83 -> V_111 ) ;
if ( V_83 -> V_113 ) {
if ( F_61 ( V_83 -> V_113 , V_134 ) )
goto V_171;
F_63 ( V_134 , V_16 ,
F_7 ( V_83 -> V_113 ) , V_83 -> V_113 ) ;
}
if ( V_83 -> V_115 )
F_63 ( V_134 , V_12 , F_5 ( V_83 -> V_115 ) , V_83 -> V_115 ) ;
if ( V_83 -> V_117 )
F_63 ( V_134 , V_13 , sizeof( * ( V_83 -> V_117 ) ) , V_83 -> V_117 ) ;
if ( V_83 -> V_120 )
F_63 ( V_134 , V_49 , sizeof( * V_83 -> V_120 ) , V_83 -> V_120 ) ;
if ( V_83 -> V_121 )
F_65 ( V_134 , V_43 , V_83 -> V_121 ) ;
if ( F_66 ( V_134 , & V_83 -> V_123 ) )
goto V_171;
if ( V_83 -> V_75 )
F_63 ( V_134 , V_27 ,
F_22 ( V_83 -> V_75 ) , V_83 -> V_75 ) ;
if ( V_83 -> V_172 && F_59 ( V_83 -> V_172 , V_134 ) < 0 )
goto V_171;
return 0 ;
V_171:
return - V_163 ;
}
static int F_67 ( struct V_82 * V_83 , int V_173 , void * V_174 )
{
struct V_175 * V_176 = V_174 ;
struct V_133 * V_177 = V_176 -> V_177 ;
struct V_133 * V_134 = V_176 -> V_178 ;
struct V_25 * V_26 ;
struct V_135 * V_136 ;
int V_34 ;
V_136 = F_68 ( V_134 , F_69 ( V_177 ) . V_147 , V_176 -> V_146 ,
V_145 , sizeof( * V_26 ) , V_176 -> V_179 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_26 = F_39 ( V_136 ) ;
V_34 = F_62 ( V_83 , V_26 , V_134 ) ;
if ( V_34 )
goto V_171;
F_70 ( V_134 , V_136 ) ;
return 0 ;
V_171:
F_71 ( V_134 , V_136 ) ;
return V_34 ;
}
static int F_72 ( struct V_180 * V_181 )
{
struct V_182 * V_183 = (struct V_182 * ) & V_181 -> args [ 1 ] ;
F_73 ( V_183 ) ;
return 0 ;
}
static int F_74 ( struct V_133 * V_134 , struct V_180 * V_181 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_182 * V_183 = (struct V_182 * ) & V_181 -> args [ 1 ] ;
struct V_175 V_184 ;
F_75 ( sizeof( struct V_182 ) >
sizeof( V_181 -> args ) - sizeof( V_181 -> args [ 0 ] ) ) ;
V_184 . V_177 = V_181 -> V_134 ;
V_184 . V_178 = V_134 ;
V_184 . V_146 = V_181 -> V_136 -> V_146 ;
V_184 . V_179 = V_185 ;
if ( ! V_181 -> args [ 0 ] ) {
V_181 -> args [ 0 ] = 1 ;
F_76 ( V_183 , 0 ) ;
}
( void ) V_182 ( V_108 , V_183 , F_67 , & V_184 ) ;
return V_134 -> V_23 ;
}
static struct V_133 * F_77 ( struct V_133 * V_177 ,
struct V_82 * V_83 , T_4 V_125 )
{
struct V_175 V_184 ;
struct V_133 * V_134 ;
V_134 = F_78 ( V_186 , V_187 ) ;
if ( ! V_134 )
return F_79 ( - V_64 ) ;
V_184 . V_177 = V_177 ;
V_184 . V_178 = V_134 ;
V_184 . V_146 = V_125 ;
V_184 . V_179 = 0 ;
if ( F_67 ( V_83 , 0 , & V_184 ) ) {
F_80 ( V_134 ) ;
return NULL ;
}
return V_134 ;
}
static inline T_5 F_81 ( void )
{
return F_82 ( 4 )
+ F_83 ( sizeof( struct V_188 ) )
+ F_83 ( sizeof( struct V_189 ) ) ;
}
static int F_84 ( struct V_133 * V_134 , struct V_108 * V_108 ,
T_4 V_147 , T_4 V_125 , T_4 V_28 )
{
struct V_190 V_191 ;
struct V_188 V_192 ;
struct V_189 V_193 ;
struct V_135 * V_136 ;
T_4 * V_194 ;
V_136 = F_68 ( V_134 , V_147 , V_125 , V_195 , sizeof( T_4 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_194 = F_39 ( V_136 ) ;
* V_194 = V_28 ;
F_85 ( V_108 , & V_191 ) ;
V_192 . V_196 = V_191 . V_196 ;
V_192 . V_197 = V_191 . V_197 ;
V_192 . V_198 = V_191 . V_198 ;
V_192 . V_199 = V_191 . V_199 ;
V_192 . V_200 = V_191 . V_200 ;
V_192 . V_201 = V_191 . V_201 ;
V_193 . V_202 = V_191 . V_202 ;
V_193 . V_203 = V_191 . V_203 ;
F_63 ( V_134 , V_204 , sizeof( V_192 ) , & V_192 ) ;
F_63 ( V_134 , V_205 , sizeof( V_193 ) , & V_193 ) ;
return F_70 ( V_134 , V_136 ) ;
V_171:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_86 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_133 * V_206 ;
T_4 * V_28 = F_39 ( V_136 ) ;
T_4 V_207 = F_69 ( V_134 ) . V_147 ;
T_4 V_125 = V_136 -> V_146 ;
V_206 = F_78 ( F_81 () , V_187 ) ;
if ( V_206 == NULL )
return - V_64 ;
if ( F_84 ( V_206 , V_108 , V_207 , V_125 , * V_28 ) < 0 )
F_87 () ;
return F_88 ( V_108 -> V_126 . V_208 , V_206 , V_207 ) ;
}
static inline T_5 F_89 ( void )
{
return F_82 ( 4 )
+ F_83 ( sizeof( struct V_209 ) )
+ F_83 ( 4 ) ;
}
static int F_90 ( struct V_133 * V_134 , struct V_108 * V_108 ,
T_4 V_147 , T_4 V_125 , T_4 V_28 )
{
struct V_210 V_191 ;
struct V_209 V_211 ;
struct V_135 * V_136 ;
T_4 * V_194 ;
V_136 = F_68 ( V_134 , V_147 , V_125 , V_212 , sizeof( T_4 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_194 = F_39 ( V_136 ) ;
* V_194 = V_28 ;
F_91 ( V_108 , & V_191 ) ;
V_211 . V_213 = V_191 . V_213 ;
V_211 . V_214 = V_191 . V_214 ;
F_65 ( V_134 , V_215 , V_191 . V_216 ) ;
F_63 ( V_134 , V_217 , sizeof( V_211 ) , & V_211 ) ;
return F_70 ( V_134 , V_136 ) ;
V_171:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_92 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_133 * V_206 ;
T_4 * V_28 = F_39 ( V_136 ) ;
T_4 V_207 = F_69 ( V_134 ) . V_147 ;
T_4 V_125 = V_136 -> V_146 ;
V_206 = F_78 ( F_89 () , V_187 ) ;
if ( V_206 == NULL )
return - V_64 ;
if ( F_90 ( V_206 , V_108 , V_207 , V_125 , * V_28 ) < 0 )
F_87 () ;
return F_88 ( V_108 -> V_126 . V_208 , V_206 , V_207 ) ;
}
static int F_93 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_150 * V_26 = F_39 ( V_136 ) ;
struct V_82 * V_83 ;
struct V_133 * V_218 ;
int V_34 = - V_154 ;
V_83 = F_49 ( V_108 , V_26 , V_5 , & V_34 ) ;
if ( V_83 == NULL )
goto V_219;
V_218 = F_77 ( V_134 , V_83 , V_136 -> V_146 ) ;
if ( F_94 ( V_218 ) ) {
V_34 = F_95 ( V_218 ) ;
} else {
V_34 = F_88 ( V_108 -> V_126 . V_208 , V_218 , F_69 ( V_134 ) . V_147 ) ;
}
F_36 ( V_83 ) ;
V_219:
return V_34 ;
}
static int F_96 ( struct V_220 * V_26 )
{
switch ( V_26 -> V_184 . V_30 . V_31 ) {
case V_42 :
case V_32 :
break;
case V_46 :
if ( V_26 -> V_221 >= 0x10000 )
return - V_10 ;
break;
default:
return - V_10 ;
}
if ( V_26 -> V_222 > V_26 -> V_221 )
return - V_10 ;
return 0 ;
}
static int F_97 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_82 * V_83 ;
struct V_220 * V_26 ;
struct V_133 * V_218 ;
T_1 * V_155 ;
int V_35 ;
int V_34 ;
T_4 V_123 ;
struct V_151 V_152 ;
V_26 = F_39 ( V_136 ) ;
V_34 = F_96 ( V_26 ) ;
if ( V_34 )
goto V_219;
V_35 = V_26 -> V_184 . V_35 ;
V_155 = & V_26 -> V_184 . V_30 . V_155 ;
V_83 = NULL ;
V_123 = F_32 ( V_5 , & V_152 ) ;
if ( V_26 -> V_184 . V_125 ) {
V_83 = F_98 ( V_108 , V_123 , V_26 -> V_184 . V_125 ) ;
if ( V_83 && F_99 ( & V_83 -> V_30 . V_155 , V_155 , V_35 ) ) {
F_36 ( V_83 ) ;
V_83 = NULL ;
}
}
if ( ! V_83 )
V_83 = F_100 ( V_108 , & V_152 , V_26 -> V_184 . V_44 , V_26 -> V_184 . V_86 ,
V_26 -> V_184 . V_30 . V_31 , V_155 ,
& V_26 -> V_184 . V_87 , 1 ,
V_35 ) ;
V_34 = - V_223 ;
if ( V_83 == NULL )
goto V_219;
V_34 = F_101 ( V_83 , V_26 -> V_222 , V_26 -> V_221 ) ;
if ( V_34 )
goto V_41;
V_218 = F_77 ( V_134 , V_83 , V_136 -> V_146 ) ;
if ( F_94 ( V_218 ) ) {
V_34 = F_95 ( V_218 ) ;
goto V_41;
}
V_34 = F_88 ( V_108 -> V_126 . V_208 , V_218 , F_69 ( V_134 ) . V_147 ) ;
V_41:
F_36 ( V_83 ) ;
V_219:
return V_34 ;
}
static int F_102 ( T_2 V_224 )
{
switch ( V_224 ) {
case V_225 :
case V_226 :
case V_227 :
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_103 ( T_2 type )
{
switch ( type ) {
case V_228 :
#ifdef F_104
case V_229 :
#endif
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_105 ( struct V_230 * V_26 )
{
switch ( V_26 -> V_231 ) {
case V_232 :
case V_233 :
case V_234 :
case V_235 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_236 ) {
case V_237 :
case V_238 :
break;
default:
return - V_10 ;
}
switch ( V_26 -> V_84 . V_35 ) {
case V_36 :
break;
case V_37 :
#if F_13 ( V_38 ) || F_13 ( V_39 )
break;
#else
return - V_40 ;
#endif
default:
return - V_10 ;
}
return F_102 ( V_26 -> V_224 ) ;
}
static int F_106 ( struct V_239 * V_240 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_21 * V_22 ;
if ( ! V_7 )
return 0 ;
V_22 = F_3 ( V_7 ) ;
return F_107 ( & V_240 -> V_172 , V_22 ) ;
}
static void F_108 ( struct V_239 * V_241 , struct V_242 * V_243 ,
int V_244 )
{
int V_245 ;
V_241 -> V_246 = V_244 ;
for ( V_245 = 0 ; V_245 < V_244 ; V_245 ++ , V_243 ++ ) {
struct V_247 * V_248 = & V_241 -> V_249 [ V_245 ] ;
memcpy ( & V_248 -> V_30 , & V_243 -> V_30 , sizeof( struct V_250 ) ) ;
memcpy ( & V_248 -> V_87 , & V_243 -> V_87 ,
sizeof( T_1 ) ) ;
V_248 -> V_86 = V_243 -> V_86 ;
V_248 -> V_44 = V_243 -> V_44 ;
V_248 -> V_231 = V_243 -> V_231 ;
V_248 -> V_251 = V_243 -> V_251 ;
V_248 -> V_252 = V_243 -> V_252 ;
V_248 -> V_253 = V_243 -> V_253 ;
V_248 -> V_254 = V_243 -> V_254 ;
V_248 -> V_255 = ! ~ ( V_248 -> V_252 & V_248 -> V_253 & V_248 -> V_254 ) ;
V_248 -> V_256 = V_243 -> V_35 ;
}
}
static int F_109 ( int V_244 , struct V_242 * V_243 , T_6 V_35 )
{
int V_245 ;
if ( V_244 > V_257 )
return - V_10 ;
for ( V_245 = 0 ; V_245 < V_244 ; V_245 ++ ) {
if ( ! V_243 [ V_245 ] . V_35 )
V_243 [ V_245 ] . V_35 = V_35 ;
switch ( V_243 [ V_245 ] . V_35 ) {
case V_36 :
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_37 :
break;
#endif
default:
return - V_10 ;
}
}
return 0 ;
}
static int F_110 ( struct V_239 * V_240 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_258 ] ;
if ( ! V_7 ) {
V_240 -> V_246 = 0 ;
} else {
struct V_242 * V_259 = F_3 ( V_7 ) ;
int V_244 = F_4 ( V_7 ) / sizeof( * V_259 ) ;
int V_34 ;
V_34 = F_109 ( V_244 , V_259 , V_240 -> V_35 ) ;
if ( V_34 )
return V_34 ;
F_108 ( V_240 , V_259 , V_244 ) ;
}
return 0 ;
}
static int F_111 ( T_2 * V_260 , struct V_4 * * V_5 )
{
struct V_4 * V_7 = V_5 [ V_261 ] ;
struct V_262 * V_263 ;
T_2 type = V_228 ;
int V_34 ;
if ( V_7 ) {
V_263 = F_3 ( V_7 ) ;
type = V_263 -> type ;
}
V_34 = F_103 ( type ) ;
if ( V_34 )
return V_34 ;
* V_260 = type ;
return 0 ;
}
static void F_112 ( struct V_239 * V_241 , struct V_230 * V_26 )
{
V_241 -> V_264 = V_26 -> V_264 ;
V_241 -> V_265 = V_26 -> V_265 ;
memcpy ( & V_241 -> V_266 , & V_26 -> V_84 , sizeof( V_241 -> V_266 ) ) ;
memcpy ( & V_241 -> V_85 , & V_26 -> V_85 , sizeof( V_241 -> V_85 ) ) ;
V_241 -> V_236 = V_26 -> V_236 ;
V_241 -> V_28 = V_26 -> V_28 ;
V_241 -> V_35 = V_26 -> V_84 . V_35 ;
}
static void F_113 ( struct V_239 * V_241 , struct V_230 * V_26 , int V_224 )
{
memcpy ( & V_26 -> V_84 , & V_241 -> V_266 , sizeof( V_26 -> V_84 ) ) ;
memcpy ( & V_26 -> V_85 , & V_241 -> V_85 , sizeof( V_26 -> V_85 ) ) ;
memcpy ( & V_26 -> V_101 , & V_241 -> V_101 , sizeof( V_26 -> V_101 ) ) ;
V_26 -> V_264 = V_241 -> V_264 ;
V_26 -> V_265 = V_241 -> V_265 ;
V_26 -> V_84 . V_35 = V_241 -> V_35 ;
V_26 -> V_224 = V_224 ;
V_26 -> V_236 = V_241 -> V_236 ;
V_26 -> V_28 = V_241 -> V_28 ;
V_26 -> V_231 = V_232 ;
}
static struct V_239 * F_114 ( struct V_108 * V_108 , struct V_230 * V_26 , struct V_4 * * V_5 , int * V_109 )
{
struct V_239 * V_241 = F_115 ( V_108 , V_63 ) ;
int V_34 ;
if ( ! V_241 ) {
* V_109 = - V_64 ;
return NULL ;
}
F_112 ( V_241 , V_26 ) ;
V_34 = F_111 ( & V_241 -> type , V_5 ) ;
if ( V_34 )
goto error;
if ( ! ( V_34 = F_110 ( V_241 , V_5 ) ) )
V_34 = F_106 ( V_241 , V_5 ) ;
if ( V_34 )
goto error;
F_32 ( V_5 , & V_241 -> V_123 ) ;
return V_241 ;
error:
* V_109 = V_34 ;
V_241 -> V_183 . V_267 = 1 ;
F_116 ( V_241 ) ;
return NULL ;
}
static int F_117 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_230 * V_26 = F_39 ( V_136 ) ;
struct V_239 * V_241 ;
struct V_138 V_139 ;
int V_34 ;
int V_268 ;
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
V_34 = F_105 ( V_26 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_241 = F_114 ( V_108 , V_26 , V_5 , & V_34 ) ;
if ( ! V_241 )
return V_34 ;
V_268 = V_136 -> V_144 == V_269 ;
V_34 = F_118 ( V_26 -> V_224 , V_241 , V_268 ) ;
F_45 ( V_141 , & V_143 ) ;
F_119 ( V_241 , V_34 ? 0 : 1 , V_140 , V_142 , V_143 ) ;
if ( V_34 ) {
F_120 ( V_241 -> V_172 ) ;
F_24 ( V_241 ) ;
return V_34 ;
}
V_139 . V_149 = V_136 -> V_144 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
F_121 ( V_241 , V_26 -> V_224 , & V_139 ) ;
F_122 ( V_241 ) ;
return 0 ;
}
static int F_123 ( struct V_239 * V_241 , struct V_133 * V_134 )
{
struct V_242 V_270 [ V_257 ] ;
int V_245 ;
if ( V_241 -> V_246 == 0 )
return 0 ;
for ( V_245 = 0 ; V_245 < V_241 -> V_246 ; V_245 ++ ) {
struct V_242 * V_77 = & V_270 [ V_245 ] ;
struct V_247 * V_271 = & V_241 -> V_249 [ V_245 ] ;
memcpy ( & V_77 -> V_30 , & V_271 -> V_30 , sizeof( V_77 -> V_30 ) ) ;
V_77 -> V_35 = V_271 -> V_256 ;
memcpy ( & V_77 -> V_87 , & V_271 -> V_87 , sizeof( V_77 -> V_87 ) ) ;
V_77 -> V_86 = V_271 -> V_86 ;
V_77 -> V_44 = V_271 -> V_44 ;
V_77 -> V_231 = V_271 -> V_231 ;
V_77 -> V_251 = V_271 -> V_251 ;
V_77 -> V_252 = V_271 -> V_252 ;
V_77 -> V_253 = V_271 -> V_253 ;
V_77 -> V_254 = V_271 -> V_254 ;
}
return F_124 ( V_134 , V_258 ,
sizeof( struct V_242 ) * V_241 -> V_246 , V_270 ) ;
}
static inline int F_125 ( struct V_82 * V_83 , struct V_133 * V_134 )
{
if ( V_83 -> V_172 ) {
return F_59 ( V_83 -> V_172 , V_134 ) ;
}
return 0 ;
}
static inline int F_126 ( struct V_239 * V_241 , struct V_133 * V_134 )
{
if ( V_241 -> V_172 ) {
return F_59 ( V_241 -> V_172 , V_134 ) ;
}
return 0 ;
}
static inline T_5 F_127 ( void )
{
#ifdef F_104
return F_83 ( sizeof( struct V_262 ) ) ;
#else
return 0 ;
#endif
}
static int F_128 ( T_2 type , struct V_133 * V_134 )
{
struct V_262 V_263 = {
. type = type ,
} ;
return F_124 ( V_134 , V_261 , sizeof( V_263 ) , & V_263 ) ;
}
static inline int F_128 ( T_2 type , struct V_133 * V_134 )
{
return 0 ;
}
static int F_129 ( struct V_239 * V_241 , int V_224 , int V_173 , void * V_174 )
{
struct V_175 * V_176 = V_174 ;
struct V_230 * V_26 ;
struct V_133 * V_177 = V_176 -> V_177 ;
struct V_133 * V_134 = V_176 -> V_178 ;
struct V_135 * V_136 ;
V_136 = F_68 ( V_134 , F_69 ( V_177 ) . V_147 , V_176 -> V_146 ,
V_269 , sizeof( * V_26 ) , V_176 -> V_179 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_26 = F_39 ( V_136 ) ;
F_113 ( V_241 , V_26 , V_224 ) ;
if ( F_123 ( V_241 , V_134 ) < 0 )
goto V_272;
if ( F_126 ( V_241 , V_134 ) )
goto V_272;
if ( F_128 ( V_241 -> type , V_134 ) < 0 )
goto V_272;
if ( F_66 ( V_134 , & V_241 -> V_123 ) )
goto V_171;
F_70 ( V_134 , V_136 ) ;
return 0 ;
V_171:
V_272:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_130 ( struct V_180 * V_181 )
{
struct V_273 * V_183 = (struct V_273 * ) & V_181 -> args [ 1 ] ;
F_131 ( V_183 ) ;
return 0 ;
}
static int F_132 ( struct V_133 * V_134 , struct V_180 * V_181 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_273 * V_183 = (struct V_273 * ) & V_181 -> args [ 1 ] ;
struct V_175 V_184 ;
F_75 ( sizeof( struct V_273 ) >
sizeof( V_181 -> args ) - sizeof( V_181 -> args [ 0 ] ) ) ;
V_184 . V_177 = V_181 -> V_134 ;
V_184 . V_178 = V_134 ;
V_184 . V_146 = V_181 -> V_136 -> V_146 ;
V_184 . V_179 = V_185 ;
if ( ! V_181 -> args [ 0 ] ) {
V_181 -> args [ 0 ] = 1 ;
F_133 ( V_183 , V_274 ) ;
}
( void ) V_273 ( V_108 , V_183 , F_129 , & V_184 ) ;
return V_134 -> V_23 ;
}
static struct V_133 * F_134 ( struct V_133 * V_177 ,
struct V_239 * V_241 ,
int V_224 , T_4 V_125 )
{
struct V_175 V_184 ;
struct V_133 * V_134 ;
V_134 = F_78 ( V_186 , V_63 ) ;
if ( ! V_134 )
return F_79 ( - V_64 ) ;
V_184 . V_177 = V_177 ;
V_184 . V_178 = V_134 ;
V_184 . V_146 = V_125 ;
V_184 . V_179 = 0 ;
if ( F_129 ( V_241 , V_224 , 0 , & V_184 ) < 0 ) {
F_80 ( V_134 ) ;
return NULL ;
}
return V_134 ;
}
static int F_135 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_239 * V_241 ;
struct V_275 * V_26 ;
T_2 type = V_228 ;
int V_34 ;
struct V_138 V_139 ;
int V_276 ;
struct V_151 V_152 ;
T_4 V_123 = F_32 ( V_5 , & V_152 ) ;
V_26 = F_39 ( V_136 ) ;
V_276 = V_136 -> V_144 == V_277 ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_102 ( V_26 -> V_224 ) ;
if ( V_34 )
return V_34 ;
if ( V_26 -> V_265 )
V_241 = F_136 ( V_108 , V_123 , type , V_26 -> V_224 , V_26 -> V_265 , V_276 , & V_34 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_80 * V_278 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_278 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_34 = F_107 ( & V_278 , V_22 ) ;
if ( V_34 )
return V_34 ;
}
V_241 = F_137 ( V_108 , V_123 , type , V_26 -> V_224 , & V_26 -> V_84 ,
V_278 , V_276 , & V_34 ) ;
F_120 ( V_278 ) ;
}
if ( V_241 == NULL )
return - V_223 ;
if ( ! V_276 ) {
struct V_133 * V_218 ;
V_218 = F_134 ( V_134 , V_241 , V_26 -> V_224 , V_136 -> V_146 ) ;
if ( F_94 ( V_218 ) ) {
V_34 = F_95 ( V_218 ) ;
} else {
V_34 = F_88 ( V_108 -> V_126 . V_208 , V_218 ,
F_69 ( V_134 ) . V_147 ) ;
}
} else {
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
F_45 ( V_141 , & V_143 ) ;
F_138 ( V_241 , V_34 ? 0 : 1 , V_140 , V_142 ,
V_143 ) ;
if ( V_34 != 0 )
goto V_41;
V_139 . V_279 . V_280 = V_26 -> V_265 ;
V_139 . V_149 = V_136 -> V_144 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
F_121 ( V_241 , V_26 -> V_224 , & V_139 ) ;
}
V_41:
F_122 ( V_241 ) ;
return V_34 ;
}
static int F_139 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_138 V_139 ;
struct V_281 * V_26 = F_39 ( V_136 ) ;
struct V_282 V_283 ;
int V_34 ;
V_283 . V_140 = F_40 ( V_141 ) ;
V_283 . V_142 = F_41 ( V_141 ) ;
F_45 ( V_141 , & V_283 . V_284 ) ;
V_34 = F_140 ( V_108 , V_26 -> V_31 , & V_283 ) ;
if ( V_34 ) {
if ( V_34 == - V_154 )
return 0 ;
return V_34 ;
}
V_139 . V_279 . V_31 = V_26 -> V_31 ;
V_139 . V_149 = V_136 -> V_144 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
V_139 . V_108 = V_108 ;
F_48 ( NULL , & V_139 ) ;
return 0 ;
}
static inline T_5 F_141 ( struct V_82 * V_83 )
{
T_5 V_285 = V_83 -> V_75 ?
F_22 ( V_83 -> V_75 ) :
sizeof( struct V_96 ) ;
return F_82 ( sizeof( struct V_286 ) )
+ F_83 ( V_285 )
+ F_83 ( sizeof( struct V_99 ) )
+ F_83 ( sizeof( struct V_151 ) )
+ F_83 ( 4 )
+ F_83 ( 4 ) ;
}
static int F_142 ( struct V_133 * V_134 , struct V_82 * V_83 , const struct V_138 * V_139 )
{
struct V_286 * V_30 ;
struct V_135 * V_136 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , V_139 -> V_125 , V_287 , sizeof( * V_30 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_30 = F_39 ( V_136 ) ;
memcpy ( & V_30 -> V_288 . V_155 , & V_83 -> V_30 . V_155 , sizeof( V_83 -> V_30 . V_155 ) ) ;
V_30 -> V_288 . V_156 = V_83 -> V_30 . V_156 ;
V_30 -> V_288 . V_35 = V_83 -> V_55 . V_35 ;
V_30 -> V_288 . V_31 = V_83 -> V_30 . V_31 ;
memcpy ( & V_30 -> V_87 , & V_83 -> V_55 . V_87 , sizeof( V_83 -> V_55 . V_87 ) ) ;
V_30 -> V_86 = V_83 -> V_55 . V_86 ;
V_30 -> V_28 = V_139 -> V_279 . V_289 ;
if ( V_83 -> V_75 )
F_63 ( V_134 , V_27 ,
F_22 ( V_83 -> V_75 ) ,
V_83 -> V_75 ) ;
else
F_63 ( V_134 , V_89 , sizeof( V_83 -> V_97 ) , & V_83 -> V_97 ) ;
F_63 ( V_134 , V_92 , sizeof( V_83 -> V_101 ) , & V_83 -> V_101 ) ;
if ( V_30 -> V_28 & V_290 )
F_65 ( V_134 , V_95 , V_83 -> V_107 ) ;
if ( V_30 -> V_28 & V_291 )
F_65 ( V_134 , V_94 ,
V_83 -> V_106 * 10 / V_129 ) ;
if ( F_66 ( V_134 , & V_83 -> V_123 ) )
goto V_171;
return F_70 ( V_134 , V_136 ) ;
V_171:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_143 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_82 * V_83 ;
struct V_133 * V_206 ;
int V_34 ;
struct V_138 V_139 ;
T_4 V_123 ;
struct V_151 V_152 ;
struct V_286 * V_26 = F_39 ( V_136 ) ;
struct V_150 * V_30 = & V_26 -> V_288 ;
V_123 = F_32 ( V_5 , & V_152 ) ;
V_83 = F_51 ( V_108 , V_123 , & V_30 -> V_155 , V_30 -> V_156 , V_30 -> V_31 , V_30 -> V_35 ) ;
if ( V_83 == NULL )
return - V_154 ;
V_206 = F_78 ( F_141 ( V_83 ) , V_187 ) ;
if ( V_206 == NULL ) {
F_36 ( V_83 ) ;
return - V_64 ;
}
F_144 ( & V_83 -> V_292 ) ;
V_139 . V_279 . V_289 = V_26 -> V_28 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
if ( F_142 ( V_206 , V_83 , & V_139 ) < 0 )
F_87 () ;
V_34 = F_88 ( V_108 -> V_126 . V_208 , V_206 , F_69 ( V_134 ) . V_147 ) ;
F_145 ( & V_83 -> V_292 ) ;
F_36 ( V_83 ) ;
return V_34 ;
}
static int F_146 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_82 * V_83 ;
struct V_138 V_139 ;
int V_34 = - V_10 ;
T_4 V_123 = 0 ;
struct V_151 V_152 ;
struct V_286 * V_26 = F_39 ( V_136 ) ;
struct V_4 * V_76 = V_5 [ V_89 ] ;
struct V_4 * V_90 = V_5 [ V_27 ] ;
struct V_4 * V_91 = V_5 [ V_92 ] ;
if ( ! V_91 && ! V_76 && ! V_90 )
return V_34 ;
if ( ! ( V_136 -> V_179 & V_293 ) )
return V_34 ;
V_123 = F_32 ( V_5 , & V_152 ) ;
V_83 = F_51 ( V_108 , V_123 , & V_26 -> V_288 . V_155 , V_26 -> V_288 . V_156 , V_26 -> V_288 . V_31 , V_26 -> V_288 . V_35 ) ;
if ( V_83 == NULL )
return - V_154 ;
if ( V_83 -> V_124 . V_131 != V_294 )
goto V_41;
V_34 = F_21 ( V_83 -> V_75 , V_76 ) ;
if ( V_34 )
goto V_41;
F_144 ( & V_83 -> V_292 ) ;
F_27 ( V_83 , V_5 ) ;
F_145 ( & V_83 -> V_292 ) ;
V_139 . V_149 = V_136 -> V_144 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
V_139 . V_279 . V_289 = V_295 ;
F_48 ( V_83 , & V_139 ) ;
V_34 = 0 ;
V_41:
F_36 ( V_83 ) ;
return V_34 ;
}
static int F_147 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_138 V_139 ;
T_2 type = V_228 ;
int V_34 ;
struct V_282 V_283 ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_283 . V_140 = F_40 ( V_141 ) ;
V_283 . V_142 = F_41 ( V_141 ) ;
F_45 ( V_141 , & V_283 . V_284 ) ;
V_34 = F_148 ( V_108 , type , & V_283 ) ;
if ( V_34 ) {
if ( V_34 == - V_154 )
return 0 ;
return V_34 ;
}
V_139 . V_279 . type = type ;
V_139 . V_149 = V_136 -> V_144 ;
V_139 . V_125 = V_136 -> V_146 ;
V_139 . V_147 = V_136 -> V_148 ;
V_139 . V_108 = V_108 ;
F_121 ( NULL , 0 , & V_139 ) ;
return 0 ;
}
static int F_149 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_239 * V_241 ;
struct V_296 * V_77 = F_39 ( V_136 ) ;
struct V_230 * V_26 = & V_77 -> V_240 ;
T_2 type = V_228 ;
int V_34 = - V_223 ;
struct V_151 V_152 ;
T_4 V_123 = F_32 ( V_5 , & V_152 ) ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_102 ( V_26 -> V_224 ) ;
if ( V_34 )
return V_34 ;
if ( V_26 -> V_265 )
V_241 = F_136 ( V_108 , V_123 , type , V_26 -> V_224 , V_26 -> V_265 , 0 , & V_34 ) ;
else {
struct V_4 * V_7 = V_5 [ V_20 ] ;
struct V_80 * V_278 ;
V_34 = F_10 ( V_5 ) ;
if ( V_34 )
return V_34 ;
V_278 = NULL ;
if ( V_7 ) {
struct V_21 * V_22 = F_3 ( V_7 ) ;
V_34 = F_107 ( & V_278 , V_22 ) ;
if ( V_34 )
return V_34 ;
}
V_241 = F_137 ( V_108 , V_123 , type , V_26 -> V_224 ,
& V_26 -> V_84 , V_278 , 0 , & V_34 ) ;
F_120 ( V_278 ) ;
}
if ( V_241 == NULL )
return - V_223 ;
if ( F_150 ( V_241 -> V_183 . V_267 ) )
goto V_41;
V_34 = 0 ;
if ( V_77 -> V_297 ) {
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
F_45 ( V_141 , & V_143 ) ;
F_151 ( V_241 , V_26 -> V_224 ) ;
F_138 ( V_241 , 1 , V_140 , V_142 , V_143 ) ;
} else {
F_152 ( 1 , L_1 ) ;
}
F_153 ( V_241 , V_26 -> V_224 , V_77 -> V_297 , V_141 -> V_147 ) ;
V_41:
F_122 ( V_241 ) ;
return V_34 ;
}
static int F_154 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_82 * V_83 ;
int V_34 ;
struct V_298 * V_299 = F_39 ( V_136 ) ;
struct V_25 * V_26 = & V_299 -> V_131 ;
struct V_151 V_152 ;
T_4 V_123 = F_32 ( V_5 , & V_152 ) ;
V_83 = F_51 ( V_108 , V_123 , & V_26 -> V_30 . V_155 , V_26 -> V_30 . V_156 , V_26 -> V_30 . V_31 , V_26 -> V_35 ) ;
V_34 = - V_223 ;
if ( V_83 == NULL )
return V_34 ;
F_144 ( & V_83 -> V_292 ) ;
V_34 = - V_10 ;
if ( V_83 -> V_124 . V_131 != V_294 )
goto V_41;
F_155 ( V_83 , V_299 -> V_297 , V_141 -> V_147 ) ;
if ( V_299 -> V_297 ) {
T_3 V_140 = F_40 ( V_141 ) ;
T_4 V_142 = F_41 ( V_141 ) ;
T_4 V_143 ;
F_45 ( V_141 , & V_143 ) ;
F_156 ( V_83 ) ;
F_57 ( V_83 , 1 , V_140 , V_142 , V_143 ) ;
}
V_34 = 0 ;
V_41:
F_145 ( & V_83 -> V_292 ) ;
F_36 ( V_83 ) ;
return V_34 ;
}
static int F_157 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_239 * V_241 ;
struct V_242 * V_243 ;
int V_245 ;
struct V_4 * V_7 = V_5 [ V_258 ] ;
struct V_151 V_123 ;
struct V_300 * V_301 = F_39 ( V_136 ) ;
struct V_82 * V_83 = F_30 ( V_108 ) ;
int V_34 = - V_64 ;
if ( ! V_83 )
goto V_302;
F_32 ( V_5 , & V_123 ) ;
V_34 = F_105 ( & V_301 -> V_303 ) ;
if ( V_34 )
goto V_304;
V_241 = F_114 ( V_108 , & V_301 -> V_303 , V_5 , & V_34 ) ;
if ( ! V_241 )
goto V_305;
memcpy ( & V_83 -> V_30 , & V_301 -> V_30 , sizeof( V_301 -> V_30 ) ) ;
memcpy ( & V_83 -> V_55 . V_87 , & V_301 -> V_87 , sizeof( V_301 -> V_87 ) ) ;
memcpy ( & V_83 -> V_84 , & V_301 -> V_84 , sizeof( V_301 -> V_84 ) ) ;
V_241 -> V_123 . V_152 = V_83 -> V_123 . V_152 = V_123 . V_152 ;
V_241 -> V_123 . V_306 = V_83 -> V_123 . V_306 = V_123 . V_306 ;
V_243 = F_3 ( V_7 ) ;
for ( V_245 = 0 ; V_245 < V_241 -> V_246 ; V_245 ++ , V_243 ++ ) {
struct V_247 * V_248 = & V_241 -> V_249 [ V_245 ] ;
memcpy ( & V_83 -> V_30 , & V_248 -> V_30 , sizeof( V_83 -> V_30 ) ) ;
V_83 -> V_55 . V_44 = V_248 -> V_44 ;
V_83 -> V_55 . V_86 = V_248 -> V_86 ;
V_83 -> V_55 . V_35 = V_243 -> V_35 ;
V_248 -> V_252 = V_301 -> V_252 ;
V_248 -> V_253 = V_301 -> V_253 ;
V_248 -> V_254 = V_301 -> V_254 ;
V_34 = F_158 ( V_83 , V_248 , V_241 ) ;
}
F_24 ( V_83 ) ;
F_24 ( V_241 ) ;
return 0 ;
V_304:
F_152 ( 1 , L_2 ) ;
V_305:
F_24 ( V_83 ) ;
V_302:
return V_34 ;
}
static int F_159 ( struct V_307 * V_308 ,
struct V_309 * V_310 ,
struct V_4 * * V_5 , int * V_311 )
{
struct V_4 * V_7 = V_5 [ V_312 ] ;
struct V_313 * V_314 ;
int V_245 , V_315 ;
if ( V_310 != NULL ) {
struct V_316 * V_317 ;
V_317 = F_3 ( V_5 [ V_318 ] ) ;
memcpy ( & V_310 -> V_319 , & V_317 -> V_319 , sizeof( V_310 -> V_319 ) ) ;
memcpy ( & V_310 -> V_320 , & V_317 -> V_320 , sizeof( V_310 -> V_320 ) ) ;
V_310 -> V_35 = V_317 -> V_35 ;
V_310 -> V_321 = V_317 -> V_321 ;
}
V_314 = F_3 ( V_7 ) ;
V_315 = F_4 ( V_7 ) / sizeof( * V_314 ) ;
if ( V_315 <= 0 || V_315 > V_257 )
return - V_10 ;
for ( V_245 = 0 ; V_245 < V_315 ; V_245 ++ , V_314 ++ , V_308 ++ ) {
memcpy ( & V_308 -> V_322 , & V_314 -> V_322 , sizeof( V_308 -> V_322 ) ) ;
memcpy ( & V_308 -> V_323 , & V_314 -> V_323 , sizeof( V_308 -> V_323 ) ) ;
memcpy ( & V_308 -> V_324 , & V_314 -> V_324 , sizeof( V_308 -> V_324 ) ) ;
memcpy ( & V_308 -> V_325 , & V_314 -> V_325 , sizeof( V_308 -> V_325 ) ) ;
V_308 -> V_31 = V_314 -> V_31 ;
V_308 -> V_44 = V_314 -> V_44 ;
V_308 -> V_86 = V_314 -> V_86 ;
V_308 -> V_326 = V_314 -> V_326 ;
V_308 -> V_327 = V_314 -> V_327 ;
}
* V_311 = V_245 ;
return 0 ;
}
static int F_160 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
struct V_275 * V_328 = F_39 ( V_136 ) ;
struct V_307 V_152 [ V_257 ] ;
struct V_309 V_124 , * V_329 ;
T_2 type ;
int V_34 ;
int V_330 = 0 ;
if ( V_5 [ V_312 ] == NULL )
return - V_10 ;
V_329 = V_5 [ V_318 ] ? & V_124 : NULL ;
V_34 = F_111 ( & type , V_5 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_159 ( (struct V_307 * ) V_152 , V_329 , V_5 , & V_330 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_330 )
return 0 ;
V_307 ( & V_328 -> V_84 , V_328 -> V_224 , type , V_152 , V_330 , V_329 ) ;
return 0 ;
}
static int F_160 ( struct V_133 * V_134 , struct V_135 * V_136 ,
struct V_4 * * V_5 )
{
return - V_331 ;
}
static int F_161 ( const struct V_307 * V_152 , struct V_133 * V_134 )
{
struct V_313 V_314 ;
memset ( & V_314 , 0 , sizeof( V_314 ) ) ;
V_314 . V_31 = V_152 -> V_31 ;
V_314 . V_44 = V_152 -> V_44 ;
V_314 . V_86 = V_152 -> V_86 ;
V_314 . V_326 = V_152 -> V_326 ;
memcpy ( & V_314 . V_322 , & V_152 -> V_322 , sizeof( V_314 . V_322 ) ) ;
memcpy ( & V_314 . V_323 , & V_152 -> V_323 , sizeof( V_314 . V_323 ) ) ;
V_314 . V_327 = V_152 -> V_327 ;
memcpy ( & V_314 . V_324 , & V_152 -> V_324 , sizeof( V_314 . V_324 ) ) ;
memcpy ( & V_314 . V_325 , & V_152 -> V_325 , sizeof( V_314 . V_325 ) ) ;
return F_124 ( V_134 , V_312 , sizeof( V_314 ) , & V_314 ) ;
}
static int F_162 ( const struct V_309 * V_310 , struct V_133 * V_134 )
{
struct V_316 V_317 ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
V_317 . V_35 = V_310 -> V_35 ;
V_317 . V_321 = V_310 -> V_321 ;
memcpy ( & V_317 . V_319 , & V_310 -> V_319 , sizeof( V_317 . V_319 ) ) ;
memcpy ( & V_317 . V_320 , & V_310 -> V_320 , sizeof( V_317 . V_320 ) ) ;
return F_124 ( V_134 , V_318 , sizeof( V_317 ) , & V_317 ) ;
}
static inline T_5 F_163 ( int V_315 , int V_332 )
{
return F_82 ( sizeof( struct V_275 ) )
+ ( V_332 ? F_83 ( sizeof( struct V_309 ) ) : 0 )
+ F_83 ( sizeof( struct V_313 ) * V_315 )
+ F_127 () ;
}
static int F_164 ( struct V_133 * V_134 , const struct V_307 * V_152 ,
int V_315 , const struct V_309 * V_310 ,
const struct V_333 * V_84 , T_2 V_224 , T_2 type )
{
const struct V_307 * V_334 ;
struct V_275 * V_335 ;
struct V_135 * V_136 ;
int V_245 ;
V_136 = F_68 ( V_134 , 0 , 0 , V_336 , sizeof( * V_335 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_335 = F_39 ( V_136 ) ;
memset ( V_335 , 0 , sizeof( * V_335 ) ) ;
memcpy ( & V_335 -> V_84 , V_84 , sizeof( V_335 -> V_84 ) ) ;
V_335 -> V_224 = V_224 ;
if ( V_310 != NULL && ( F_162 ( V_310 , V_134 ) < 0 ) )
goto V_272;
if ( F_128 ( type , V_134 ) < 0 )
goto V_272;
for ( V_245 = 0 , V_334 = V_152 ; V_245 < V_315 ; V_245 ++ , V_334 ++ ) {
if ( F_161 ( V_334 , V_134 ) < 0 )
goto V_272;
}
return F_70 ( V_134 , V_136 ) ;
V_272:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_165 ( const struct V_333 * V_84 , T_2 V_224 , T_2 type ,
const struct V_307 * V_152 , int V_315 ,
const struct V_309 * V_310 )
{
struct V_108 * V_108 = & V_337 ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_163 ( V_315 , ! ! V_310 ) , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_164 ( V_134 , V_152 , V_315 , V_310 , V_84 , V_224 , type ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_338 , V_187 ) ;
}
static int F_165 ( const struct V_333 * V_84 , T_2 V_224 , T_2 type ,
const struct V_307 * V_152 , int V_315 ,
const struct V_309 * V_310 )
{
return - V_331 ;
}
static int F_167 ( struct V_133 * V_134 , struct V_135 * V_136 )
{
struct V_108 * V_108 = F_38 ( V_134 -> V_137 ) ;
struct V_4 * V_5 [ V_339 + 1 ] ;
struct V_340 * V_341 ;
int type , V_34 ;
type = V_136 -> V_144 ;
if ( type > V_342 )
return - V_10 ;
type -= V_343 ;
V_341 = & V_344 [ type ] ;
if ( F_168 ( V_134 , V_345 ) )
return - V_158 ;
if ( ( type == ( V_346 - V_343 ) ||
type == ( V_347 - V_343 ) ) &&
( V_136 -> V_179 & V_348 ) ) {
if ( V_341 -> V_349 == NULL )
return - V_10 ;
return F_169 ( V_108 -> V_126 . V_208 , V_134 , V_136 , V_341 -> V_349 , V_341 -> V_350 ) ;
}
V_34 = F_170 ( V_136 , V_351 [ type ] , V_5 , V_339 ,
V_352 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_341 -> V_353 == NULL )
return - V_10 ;
return V_341 -> V_353 ( V_134 , V_136 , V_5 ) ;
}
static void F_171 ( struct V_133 * V_134 )
{
F_172 ( & V_354 ) ;
F_173 ( V_134 , & F_167 ) ;
F_174 ( & V_354 ) ;
}
static inline T_5 F_175 ( void )
{
return F_82 ( sizeof( struct V_298 ) )
+ F_83 ( sizeof( struct V_151 ) ) ;
}
static int F_176 ( struct V_133 * V_134 , struct V_82 * V_83 , const struct V_138 * V_139 )
{
struct V_298 * V_299 ;
struct V_135 * V_136 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , 0 , V_355 , sizeof( * V_299 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_299 = F_39 ( V_136 ) ;
F_58 ( V_83 , & V_299 -> V_131 ) ;
V_299 -> V_297 = ( V_139 -> V_279 . V_297 != 0 ) ? 1 : 0 ;
if ( F_66 ( V_134 , & V_83 -> V_123 ) )
goto V_171;
return F_70 ( V_134 , V_136 ) ;
V_171:
return - V_163 ;
}
static int F_177 ( struct V_82 * V_83 , const struct V_138 * V_139 )
{
struct V_108 * V_108 = F_178 ( V_83 ) ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_175 () , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_176 ( V_134 , V_83 , V_139 ) < 0 ) {
F_80 ( V_134 ) ;
return - V_163 ;
}
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_356 , V_187 ) ;
}
static int F_179 ( struct V_82 * V_83 , const struct V_138 * V_139 )
{
struct V_108 * V_108 = F_178 ( V_83 ) ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_141 ( V_83 ) , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_142 ( V_134 , V_83 , V_139 ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_357 , V_187 ) ;
}
static int F_180 ( const struct V_138 * V_139 )
{
struct V_108 * V_108 = V_139 -> V_108 ;
struct V_281 * V_26 ;
struct V_135 * V_136 ;
struct V_133 * V_134 ;
int V_23 = F_82 ( sizeof( struct V_281 ) ) ;
V_134 = F_78 ( V_23 , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , V_139 -> V_125 , V_358 , sizeof( * V_26 ) , 0 ) ;
if ( V_136 == NULL ) {
F_80 ( V_134 ) ;
return - V_163 ;
}
V_26 = F_39 ( V_136 ) ;
V_26 -> V_31 = V_139 -> V_279 . V_31 ;
F_70 ( V_134 , V_136 ) ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_359 , V_187 ) ;
}
static inline T_5 F_181 ( struct V_82 * V_83 )
{
T_5 V_360 = 0 ;
if ( V_83 -> V_111 )
V_360 += F_83 ( F_1 ( V_83 -> V_111 ) ) ;
if ( V_83 -> V_113 ) {
V_360 += F_83 ( sizeof( struct V_8 ) +
( V_83 -> V_113 -> V_3 + 7 ) / 8 ) ;
V_360 += F_83 ( F_7 ( V_83 -> V_113 ) ) ;
}
if ( V_83 -> V_115 )
V_360 += F_83 ( F_5 ( V_83 -> V_115 ) ) ;
if ( V_83 -> V_117 )
V_360 += F_83 ( sizeof( * V_83 -> V_117 ) ) ;
if ( V_83 -> V_120 )
V_360 += F_83 ( sizeof( * V_83 -> V_120 ) ) ;
if ( V_83 -> V_121 )
V_360 += F_83 ( sizeof( V_83 -> V_121 ) ) ;
if ( V_83 -> V_75 )
V_360 += F_83 ( F_22 ( V_83 -> V_75 ) ) ;
if ( V_83 -> V_172 )
V_360 += F_83 ( sizeof( struct V_21 ) +
V_83 -> V_172 -> V_24 ) ;
if ( V_83 -> V_122 )
V_360 += F_83 ( sizeof( * V_83 -> V_122 ) ) ;
V_360 += F_83 ( sizeof( V_361 ) ) ;
return V_360 ;
}
static int F_182 ( struct V_82 * V_83 , const struct V_138 * V_139 )
{
struct V_108 * V_108 = F_178 ( V_83 ) ;
struct V_25 * V_26 ;
struct V_150 * V_30 ;
struct V_135 * V_136 ;
struct V_133 * V_134 ;
int V_23 = F_181 ( V_83 ) ;
int V_362 ;
V_362 = sizeof( * V_26 ) ;
if ( V_139 -> V_149 == V_363 ) {
V_23 += F_83 ( V_362 ) ;
V_362 = sizeof( * V_30 ) ;
V_23 += F_83 ( sizeof( struct V_151 ) ) ;
}
V_23 += F_82 ( V_362 ) ;
V_134 = F_78 ( V_23 , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , V_139 -> V_125 , V_139 -> V_149 , V_362 , 0 ) ;
if ( V_136 == NULL )
goto V_171;
V_26 = F_39 ( V_136 ) ;
if ( V_139 -> V_149 == V_363 ) {
struct V_4 * V_161 ;
V_30 = F_39 ( V_136 ) ;
memcpy ( & V_30 -> V_155 , & V_83 -> V_30 . V_155 , sizeof( V_30 -> V_155 ) ) ;
V_30 -> V_156 = V_83 -> V_30 . V_156 ;
V_30 -> V_35 = V_83 -> V_55 . V_35 ;
V_30 -> V_31 = V_83 -> V_30 . V_31 ;
V_161 = F_60 ( V_134 , V_364 , sizeof( * V_26 ) ) ;
if ( V_161 == NULL )
goto V_171;
V_26 = F_3 ( V_161 ) ;
}
if ( F_62 ( V_83 , V_26 , V_134 ) )
goto V_171;
F_70 ( V_134 , V_136 ) ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_359 , V_187 ) ;
V_171:
F_183 ( 1 ) ;
F_80 ( V_134 ) ;
return - 1 ;
}
static int F_184 ( struct V_82 * V_83 , const struct V_138 * V_139 )
{
switch ( V_139 -> V_149 ) {
case V_355 :
return F_177 ( V_83 , V_139 ) ;
case V_287 :
return F_179 ( V_83 , V_139 ) ;
case V_363 :
case V_365 :
case V_145 :
return F_182 ( V_83 , V_139 ) ;
case V_358 :
return F_180 ( V_139 ) ;
default:
F_185 ( V_366 L_3 ,
V_139 -> V_149 ) ;
break;
}
return 0 ;
}
static inline T_5 F_186 ( struct V_82 * V_83 ,
struct V_239 * V_241 )
{
return F_82 ( sizeof( struct V_300 ) )
+ F_83 ( sizeof( struct V_242 ) * V_241 -> V_246 )
+ F_83 ( sizeof( struct V_151 ) )
+ F_83 ( F_25 ( V_83 -> V_172 ) )
+ F_127 () ;
}
static int F_187 ( struct V_133 * V_134 , struct V_82 * V_83 ,
struct V_247 * V_367 , struct V_239 * V_241 ,
int V_224 )
{
struct V_300 * V_301 ;
struct V_135 * V_136 ;
T_7 V_125 = F_188 () ;
V_136 = F_68 ( V_134 , 0 , 0 , V_368 , sizeof( * V_301 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_301 = F_39 ( V_136 ) ;
memcpy ( & V_301 -> V_30 , & V_83 -> V_30 , sizeof( V_301 -> V_30 ) ) ;
memcpy ( & V_301 -> V_87 , & V_83 -> V_55 . V_87 , sizeof( V_301 -> V_87 ) ) ;
memcpy ( & V_301 -> V_84 , & V_83 -> V_84 , sizeof( V_301 -> V_84 ) ) ;
F_113 ( V_241 , & V_301 -> V_303 , V_224 ) ;
V_301 -> V_252 = V_367 -> V_252 ;
V_301 -> V_253 = V_367 -> V_253 ;
V_301 -> V_254 = V_367 -> V_254 ;
V_301 -> V_125 = V_83 -> V_124 . V_125 = V_125 ;
if ( F_123 ( V_241 , V_134 ) < 0 )
goto V_272;
if ( F_125 ( V_83 , V_134 ) )
goto V_272;
if ( F_128 ( V_241 -> type , V_134 ) < 0 )
goto V_272;
if ( F_66 ( V_134 , & V_241 -> V_123 ) )
goto V_171;
return F_70 ( V_134 , V_136 ) ;
V_171:
V_272:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_189 ( struct V_82 * V_83 , struct V_247 * V_367 ,
struct V_239 * V_241 , int V_224 )
{
struct V_108 * V_108 = F_178 ( V_83 ) ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_186 ( V_83 , V_241 ) , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_187 ( V_134 , V_83 , V_367 , V_241 , V_224 ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_369 , V_187 ) ;
}
static struct V_239 * F_190 ( struct V_370 * V_137 , int V_371 ,
T_2 * V_279 , int V_23 , int * V_224 )
{
struct V_108 * V_108 = F_38 ( V_137 ) ;
struct V_230 * V_26 = (struct V_230 * ) V_279 ;
struct V_242 * V_243 = (struct V_242 * ) ( V_26 + 1 ) ;
struct V_239 * V_241 ;
int V_244 ;
switch ( V_137 -> V_372 ) {
case V_36 :
if ( V_371 != V_373 ) {
* V_224 = - V_374 ;
return NULL ;
}
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_37 :
if ( V_371 != V_375 ) {
* V_224 = - V_374 ;
return NULL ;
}
break;
#endif
default:
* V_224 = - V_10 ;
return NULL ;
}
* V_224 = - V_10 ;
if ( V_23 < sizeof( * V_26 ) ||
F_105 ( V_26 ) )
return NULL ;
V_244 = ( ( V_23 - sizeof( * V_26 ) ) / sizeof( * V_243 ) ) ;
if ( F_109 ( V_244 , V_243 , V_26 -> V_84 . V_35 ) )
return NULL ;
if ( V_26 -> V_224 > V_226 )
return NULL ;
V_241 = F_115 ( V_108 , V_187 ) ;
if ( V_241 == NULL ) {
* V_224 = - V_376 ;
return NULL ;
}
F_112 ( V_241 , V_26 ) ;
V_241 -> type = V_228 ;
F_108 ( V_241 , V_243 , V_244 ) ;
* V_224 = V_26 -> V_224 ;
return V_241 ;
}
static inline T_5 F_191 ( struct V_239 * V_241 )
{
return F_82 ( sizeof( struct V_296 ) )
+ F_83 ( sizeof( struct V_242 ) * V_241 -> V_246 )
+ F_83 ( F_25 ( V_241 -> V_172 ) )
+ F_83 ( sizeof( struct V_151 ) )
+ F_127 () ;
}
static int F_192 ( struct V_133 * V_134 , struct V_239 * V_241 ,
int V_224 , const struct V_138 * V_139 )
{
struct V_296 * V_377 ;
struct V_135 * V_136 ;
int V_297 = V_139 -> V_279 . V_297 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , 0 , V_378 , sizeof( * V_377 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_377 = F_39 ( V_136 ) ;
F_113 ( V_241 , & V_377 -> V_240 , V_224 ) ;
if ( F_123 ( V_241 , V_134 ) < 0 )
goto V_272;
if ( F_126 ( V_241 , V_134 ) )
goto V_272;
if ( F_128 ( V_241 -> type , V_134 ) < 0 )
goto V_272;
if ( F_66 ( V_134 , & V_241 -> V_123 ) )
goto V_171;
V_377 -> V_297 = ! ! V_297 ;
return F_70 ( V_134 , V_136 ) ;
V_171:
V_272:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_193 ( struct V_239 * V_241 , int V_224 , const struct V_138 * V_139 )
{
struct V_108 * V_108 = F_194 ( V_241 ) ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_191 ( V_241 ) , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_192 ( V_134 , V_241 , V_224 , V_139 ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_356 , V_187 ) ;
}
static int F_195 ( struct V_239 * V_241 , int V_224 , const struct V_138 * V_139 )
{
struct V_108 * V_108 = F_194 ( V_241 ) ;
struct V_230 * V_26 ;
struct V_275 * V_30 ;
struct V_135 * V_136 ;
struct V_133 * V_134 ;
int V_23 = F_83 ( sizeof( struct V_242 ) * V_241 -> V_246 ) ;
int V_362 ;
V_362 = sizeof( * V_26 ) ;
if ( V_139 -> V_149 == V_277 ) {
V_23 += F_83 ( V_362 ) ;
V_362 = sizeof( * V_30 ) ;
}
V_23 += F_127 () ;
V_23 += F_83 ( sizeof( struct V_151 ) ) ;
V_23 += F_82 ( V_362 ) ;
V_134 = F_78 ( V_23 , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , V_139 -> V_125 , V_139 -> V_149 , V_362 , 0 ) ;
if ( V_136 == NULL )
goto V_272;
V_26 = F_39 ( V_136 ) ;
if ( V_139 -> V_149 == V_277 ) {
struct V_4 * V_161 ;
V_30 = F_39 ( V_136 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_224 = V_224 ;
if ( V_139 -> V_279 . V_280 )
V_30 -> V_265 = V_241 -> V_265 ;
else
memcpy ( & V_30 -> V_84 , & V_241 -> V_266 , sizeof( V_30 -> V_84 ) ) ;
V_161 = F_60 ( V_134 , V_379 , sizeof( * V_26 ) ) ;
if ( V_161 == NULL )
goto V_272;
V_26 = F_3 ( V_161 ) ;
}
F_113 ( V_241 , V_26 , V_224 ) ;
if ( F_123 ( V_241 , V_134 ) < 0 )
goto V_272;
if ( F_128 ( V_241 -> type , V_134 ) < 0 )
goto V_272;
if ( F_66 ( V_134 , & V_241 -> V_123 ) )
goto V_171;
F_70 ( V_134 , V_136 ) ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_380 , V_187 ) ;
V_171:
V_272:
F_80 ( V_134 ) ;
return - 1 ;
}
static int F_196 ( const struct V_138 * V_139 )
{
struct V_108 * V_108 = V_139 -> V_108 ;
struct V_135 * V_136 ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_127 () , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
V_136 = F_68 ( V_134 , V_139 -> V_147 , V_139 -> V_125 , V_381 , 0 , 0 ) ;
if ( V_136 == NULL )
goto V_272;
if ( F_128 ( V_139 -> V_279 . type , V_134 ) < 0 )
goto V_272;
F_70 ( V_134 , V_136 ) ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_380 , V_187 ) ;
V_272:
F_80 ( V_134 ) ;
return - 1 ;
}
static int F_197 ( struct V_239 * V_241 , int V_224 , const struct V_138 * V_139 )
{
switch ( V_139 -> V_149 ) {
case V_269 :
case V_382 :
case V_277 :
return F_195 ( V_241 , V_224 , V_139 ) ;
case V_381 :
return F_196 ( V_139 ) ;
case V_378 :
return F_193 ( V_241 , V_224 , V_139 ) ;
default:
F_185 ( V_366 L_4 ,
V_139 -> V_149 ) ;
}
return 0 ;
}
static inline T_5 F_198 ( void )
{
return F_82 ( sizeof( struct V_383 ) ) ;
}
static int F_199 ( struct V_133 * V_134 , T_2 V_31 ,
struct V_333 * V_84 , T_1 * V_384 )
{
struct V_383 * V_385 ;
struct V_135 * V_136 ;
V_136 = F_68 ( V_134 , 0 , 0 , V_386 , sizeof( * V_385 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_385 = F_39 ( V_136 ) ;
V_385 -> V_31 = V_31 ;
memcpy ( & V_385 -> V_84 , V_84 , sizeof( V_385 -> V_84 ) ) ;
if ( V_384 )
F_63 ( V_134 , V_50 , sizeof( * V_384 ) , V_384 ) ;
return F_70 ( V_134 , V_136 ) ;
V_171:
F_71 ( V_134 , V_136 ) ;
return - V_163 ;
}
static int F_200 ( struct V_108 * V_108 , T_2 V_31 ,
struct V_333 * V_84 , T_1 * V_384 )
{
struct V_133 * V_134 ;
V_134 = F_78 ( F_198 () , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_199 ( V_134 , V_31 , V_84 , V_384 ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_387 , V_187 ) ;
}
static inline T_5 F_201 ( void )
{
return F_82 ( sizeof( struct V_388 ) ) ;
}
static int F_202 ( struct V_133 * V_134 , struct V_82 * V_83 ,
T_1 * V_325 , T_8 V_389 )
{
struct V_388 * V_314 ;
struct V_135 * V_136 ;
V_136 = F_68 ( V_134 , 0 , 0 , V_390 , sizeof( * V_314 ) , 0 ) ;
if ( V_136 == NULL )
return - V_163 ;
V_314 = F_39 ( V_136 ) ;
memcpy ( & V_314 -> V_30 . V_155 , & V_83 -> V_30 . V_155 , sizeof( V_314 -> V_30 . V_155 ) ) ;
V_314 -> V_30 . V_156 = V_83 -> V_30 . V_156 ;
V_314 -> V_30 . V_35 = V_83 -> V_55 . V_35 ;
V_314 -> V_30 . V_31 = V_83 -> V_30 . V_31 ;
memcpy ( & V_314 -> V_325 , V_325 , sizeof( V_314 -> V_325 ) ) ;
memcpy ( & V_314 -> V_323 , & V_83 -> V_55 . V_87 , sizeof( V_314 -> V_323 ) ) ;
V_314 -> V_389 = V_389 ;
V_314 -> V_391 = V_83 -> V_120 -> V_392 ;
V_314 -> V_86 = V_83 -> V_55 . V_86 ;
return F_70 ( V_134 , V_136 ) ;
}
static int F_203 ( struct V_82 * V_83 , T_1 * V_393 ,
T_8 V_394 )
{
struct V_108 * V_108 = F_178 ( V_83 ) ;
struct V_133 * V_134 ;
if ( V_83 -> V_30 . V_31 != V_32 )
return - V_10 ;
if ( ! V_83 -> V_120 )
return - V_10 ;
V_134 = F_78 ( F_201 () , V_187 ) ;
if ( V_134 == NULL )
return - V_64 ;
if ( F_202 ( V_134 , V_83 , V_393 , V_394 ) < 0 )
F_87 () ;
return F_166 ( V_108 -> V_126 . V_208 , V_134 , 0 , V_395 , V_187 ) ;
}
static int T_9 F_204 ( struct V_108 * V_108 )
{
struct V_370 * V_208 ;
V_208 = F_205 ( V_108 , V_396 , V_397 ,
F_171 , NULL , V_398 ) ;
if ( V_208 == NULL )
return - V_64 ;
V_108 -> V_126 . V_399 = V_208 ;
F_206 ( V_108 -> V_126 . V_208 , V_208 ) ;
return 0 ;
}
static void T_10 F_207 ( struct V_400 * V_401 )
{
struct V_108 * V_108 ;
F_208 (net, net_exit_list, exit_list)
F_206 ( V_108 -> V_126 . V_208 , NULL ) ;
F_209 () ;
F_208 (net, net_exit_list, exit_list)
F_210 ( V_108 -> V_126 . V_399 ) ;
}
static int T_11 F_211 ( void )
{
int V_402 ;
F_185 ( V_403 L_5 ) ;
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
