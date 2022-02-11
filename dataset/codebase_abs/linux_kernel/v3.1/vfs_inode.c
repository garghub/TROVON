static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = V_3 & 0777 ;
if ( F_2 ( V_3 ) )
V_4 |= V_5 ;
if ( F_3 ( V_2 ) ) {
if ( F_4 ( V_3 ) )
V_4 |= V_6 ;
if ( V_2 -> V_7 == 0 ) {
if ( F_5 ( V_3 ) )
V_4 |= V_8 ;
if ( F_6 ( V_3 ) )
V_4 |= V_9 ;
if ( F_7 ( V_3 ) )
V_4 |= V_10 ;
if ( F_8 ( V_3 ) )
V_4 |= V_10 ;
}
if ( ( V_3 & V_11 ) == V_11 )
V_4 |= V_12 ;
if ( ( V_3 & V_13 ) == V_13 )
V_4 |= V_14 ;
if ( ( V_3 & V_15 ) == V_15 )
V_4 |= V_16 ;
if ( ( V_3 & V_17 ) )
V_4 |= V_17 ;
}
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 , T_1 * V_20 )
{
int V_4 ;
int V_3 = V_19 -> V_3 ;
V_4 = V_3 & V_21 ;
* V_20 = 0 ;
if ( ( V_3 & V_5 ) == V_5 )
V_4 |= V_22 ;
else if ( ( V_3 & V_6 ) && ( F_3 ( V_2 ) ) )
V_4 |= V_23 ;
else if ( ( V_3 & V_8 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) )
V_4 |= V_24 ;
else if ( ( V_3 & V_9 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) )
V_4 |= V_25 ;
else if ( ( V_3 & V_10 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) ) {
char type = 0 , V_26 [ 32 ] ;
int V_27 = - 1 , V_28 = - 1 ;
strncpy ( V_26 , V_19 -> V_29 , sizeof( V_26 ) ) ;
sscanf ( V_26 , L_1 , & type , & V_27 , & V_28 ) ;
switch ( type ) {
case 'c' :
V_4 |= V_30 ;
break;
case 'b' :
V_4 |= V_31 ;
break;
default:
F_10 ( V_32 ,
L_2 , type ,
V_19 -> V_29 ) ;
} ;
* V_20 = F_11 ( V_27 , V_28 ) ;
} else
V_4 |= V_33 ;
if ( F_3 ( V_2 ) ) {
if ( ( V_3 & V_12 ) == V_12 )
V_4 |= V_11 ;
if ( ( V_3 & V_14 ) == V_14 )
V_4 |= V_13 ;
if ( ( V_3 & V_16 ) == V_16 )
V_4 |= V_15 ;
}
return V_4 ;
}
int F_12 ( int V_34 , int V_35 )
{
int V_36 ;
V_36 = 0 ;
switch ( V_34 & 3 ) {
default:
case V_37 :
V_36 = V_38 ;
break;
case V_39 :
V_36 = V_40 ;
break;
case V_41 :
V_36 = V_42 ;
break;
}
if ( V_34 & V_43 )
V_36 |= V_44 ;
if ( V_35 ) {
if ( V_34 & V_45 )
V_36 |= V_46 ;
if ( V_34 & V_47 )
V_36 |= V_48 ;
}
return V_36 ;
}
void
F_13 ( struct V_18 * V_49 )
{
V_49 -> type = ~ 0 ;
V_49 -> V_50 = ~ 0 ;
V_49 -> V_51 . type = ~ 0 ;
V_49 -> V_51 . V_52 = ~ 0 ;
* ( ( long long * ) & V_49 -> V_51 . V_53 ) = ~ 0 ;
V_49 -> V_3 = ~ 0 ;
V_49 -> V_54 = ~ 0 ;
V_49 -> V_55 = ~ 0 ;
V_49 -> V_56 = ~ 0 ;
V_49 -> V_57 = NULL ;
V_49 -> V_58 = NULL ;
V_49 -> V_59 = NULL ;
V_49 -> V_60 = NULL ;
V_49 -> V_61 = ~ 0 ;
V_49 -> V_62 = ~ 0 ;
V_49 -> V_63 = ~ 0 ;
V_49 -> V_29 = NULL ;
}
struct V_64 * F_14 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
V_68 = (struct V_67 * ) F_15 ( V_69 ,
V_70 ) ;
if ( ! V_68 )
return NULL ;
#ifdef F_16
V_68 -> V_71 = NULL ;
F_17 ( & V_68 -> V_72 ) ;
#endif
V_68 -> V_73 = NULL ;
V_68 -> V_74 = 0 ;
F_18 ( & V_68 -> V_75 ) ;
return & V_68 -> V_76 ;
}
static void F_19 ( struct V_77 * V_78 )
{
struct V_64 * V_64 = F_20 ( V_78 , struct V_64 , V_79 ) ;
F_21 ( & V_64 -> V_80 ) ;
F_22 ( V_69 , F_23 ( V_64 ) ) ;
}
void F_24 ( struct V_64 * V_64 )
{
F_25 ( & V_64 -> V_79 , F_19 ) ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_64 * V_64 , int V_3 , T_1 V_20 )
{
int V_81 = 0 ;
F_27 ( V_64 , NULL , V_3 ) ;
V_64 -> V_82 = 0 ;
V_64 -> V_83 = V_20 ;
V_64 -> V_84 = V_64 -> V_85 = V_64 -> V_86 = V_87 ;
V_64 -> V_88 -> V_89 = & V_90 ;
switch ( V_3 & V_91 ) {
case V_25 :
case V_31 :
case V_30 :
case V_24 :
if ( F_28 ( V_2 ) ) {
V_64 -> V_92 = & V_93 ;
V_64 -> V_94 = & V_95 ;
} else if ( F_3 ( V_2 ) ) {
V_64 -> V_92 = & V_96 ;
V_64 -> V_94 = & V_97 ;
} else {
F_10 ( V_32 ,
L_3 ) ;
V_81 = - V_98 ;
goto error;
}
F_29 ( V_64 , V_64 -> V_99 , V_64 -> V_83 ) ;
break;
case V_33 :
if ( F_28 ( V_2 ) ) {
V_64 -> V_92 = & V_93 ;
if ( V_2 -> V_100 )
V_64 -> V_94 =
& V_101 ;
else
V_64 -> V_94 = & V_95 ;
} else {
V_64 -> V_92 = & V_96 ;
if ( V_2 -> V_100 )
V_64 -> V_94 = & V_102 ;
else
V_64 -> V_94 = & V_97 ;
}
break;
case V_23 :
if ( ! F_3 ( V_2 ) && ! F_28 ( V_2 ) ) {
F_10 ( V_32 , L_4
L_5 ) ;
V_81 = - V_98 ;
goto error;
}
if ( F_28 ( V_2 ) )
V_64 -> V_92 = & V_103 ;
else
V_64 -> V_92 = & V_104 ;
break;
case V_22 :
F_30 ( V_64 ) ;
if ( F_28 ( V_2 ) )
V_64 -> V_92 = & V_105 ;
else if ( F_3 ( V_2 ) )
V_64 -> V_92 = & V_106 ;
else
V_64 -> V_92 = & V_107 ;
if ( F_28 ( V_2 ) )
V_64 -> V_94 = & V_108 ;
else
V_64 -> V_94 = & V_109 ;
break;
default:
F_10 ( V_32 , L_6 ,
V_3 , V_3 & V_91 ) ;
V_81 = - V_98 ;
goto error;
}
error:
return V_81 ;
}
struct V_64 * F_31 ( struct V_65 * V_66 , int V_3 , T_1 V_20 )
{
int V_81 ;
struct V_64 * V_64 ;
struct V_1 * V_2 = V_66 -> V_110 ;
F_10 ( V_111 , L_7 , V_66 , V_3 ) ;
V_64 = F_32 ( V_66 ) ;
if ( ! V_64 ) {
F_33 ( V_112 , L_8 ) ;
return F_34 ( - V_113 ) ;
}
V_81 = F_26 ( V_2 , V_64 , V_3 , V_20 ) ;
if ( V_81 ) {
F_35 ( V_64 ) ;
return F_34 ( V_81 ) ;
}
return V_64 ;
}
void F_36 ( struct V_64 * V_64 )
{
struct V_67 * V_68 = F_23 ( V_64 ) ;
F_37 ( V_64 -> V_88 , 0 ) ;
F_38 ( V_64 ) ;
F_39 ( V_64 -> V_88 ) ;
#ifdef F_16
F_40 ( V_64 ) ;
#endif
if ( V_68 -> V_73 ) {
F_41 ( V_68 -> V_73 ) ;
V_68 -> V_73 = NULL ;
}
}
static int F_42 ( struct V_64 * V_64 , void * V_114 )
{
int V_115 ;
T_1 V_20 ;
struct V_67 * V_68 = F_23 ( V_64 ) ;
struct V_18 * V_116 = (struct V_18 * ) V_114 ;
struct V_1 * V_2 = F_43 ( V_64 ) ;
V_115 = F_9 ( V_2 , V_116 , & V_20 ) ;
if ( ( V_64 -> V_99 & V_91 ) != ( V_115 & V_91 ) )
return 0 ;
if ( memcmp ( & V_68 -> V_51 . V_52 ,
& V_116 -> V_51 . V_52 , sizeof( V_68 -> V_51 . V_52 ) ) )
return 0 ;
if ( V_68 -> V_51 . type != V_116 -> V_51 . type )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_64 * V_64 , void * V_114 )
{
return 0 ;
}
static int F_45 ( struct V_64 * V_64 , void * V_114 )
{
struct V_67 * V_68 = F_23 ( V_64 ) ;
struct V_18 * V_116 = (struct V_18 * ) V_114 ;
memcpy ( & V_68 -> V_51 , & V_116 -> V_51 , sizeof( V_116 -> V_51 ) ) ;
return 0 ;
}
static struct V_64 * F_46 ( struct V_65 * V_66 ,
struct V_117 * V_51 ,
struct V_18 * V_116 ,
int V_118 )
{
T_1 V_20 ;
int V_119 , V_115 ;
unsigned long V_120 ;
struct V_64 * V_64 ;
struct V_1 * V_2 = V_66 -> V_110 ;
int (* F_47)( struct V_64 * , void * );
if ( V_118 )
F_47 = F_44 ;
else
F_47 = F_42 ;
V_120 = F_48 ( V_51 ) ;
V_64 = F_49 ( V_66 , V_120 , F_47 , F_45 , V_116 ) ;
if ( ! V_64 )
return F_34 ( - V_113 ) ;
if ( ! ( V_64 -> V_121 & V_122 ) )
return V_64 ;
V_64 -> V_120 = V_120 ;
V_115 = F_9 ( V_2 , V_116 , & V_20 ) ;
V_119 = F_26 ( V_2 , V_64 , V_115 , V_20 ) ;
if ( V_119 )
goto error;
F_50 ( V_116 , V_64 , V_66 ) ;
#ifdef F_16
F_51 ( V_64 ) ;
#endif
F_52 ( V_64 ) ;
return V_64 ;
error:
F_52 ( V_64 ) ;
F_35 ( V_64 ) ;
return F_34 ( V_119 ) ;
}
struct V_64 *
F_53 ( struct V_1 * V_2 , struct V_123 * V_124 ,
struct V_65 * V_66 , int V_118 )
{
struct V_18 * V_116 ;
struct V_64 * V_64 = NULL ;
V_116 = F_54 ( V_124 ) ;
if ( F_55 ( V_116 ) )
return F_56 ( V_116 ) ;
V_64 = F_46 ( V_66 , & V_116 -> V_51 , V_116 , V_118 ) ;
F_57 ( V_116 ) ;
F_58 ( V_116 ) ;
return V_64 ;
}
static int F_59 ( int V_125 )
{
int V_126 = 0 ;
if ( V_125 & V_127 )
V_126 |= V_128 ;
return V_126 ;
}
static int F_60 ( struct V_64 * V_129 , struct V_130 * V_130 , int V_125 )
{
struct V_64 * V_64 ;
int V_119 = - V_131 ;
struct V_123 * V_132 , * V_133 ;
struct V_1 * V_2 ;
F_10 ( V_111 , L_9 ,
V_129 , V_130 , V_125 ) ;
V_2 = F_43 ( V_129 ) ;
V_64 = V_130 -> V_134 ;
V_133 = F_61 ( V_130 -> V_135 ) ;
if ( F_55 ( V_133 ) ) {
V_119 = F_62 ( V_133 ) ;
F_10 ( V_111 , L_10 , V_119 ) ;
return V_119 ;
}
if ( F_28 ( V_2 ) )
V_119 = F_63 ( V_133 , V_130 -> V_136 . V_57 ,
F_59 ( V_125 ) ) ;
if ( V_119 == - V_131 ) {
V_132 = F_64 ( V_130 ) ;
if ( F_55 ( V_132 ) )
return F_62 ( V_132 ) ;
V_119 = F_65 ( V_132 ) ;
}
if ( ! V_119 ) {
if ( V_125 & V_127 ) {
F_66 ( V_64 ) ;
F_67 ( V_129 ) ;
} else
F_67 ( V_64 ) ;
F_68 ( V_64 ) ;
F_68 ( V_129 ) ;
}
return V_119 ;
}
static struct V_123 *
F_69 ( struct V_1 * V_2 , struct V_64 * V_129 ,
struct V_130 * V_130 , char * V_29 , T_2 V_137 , T_3 V_3 )
{
int V_81 ;
char * V_57 ;
struct V_123 * V_133 , * V_138 , * V_124 ;
struct V_64 * V_64 ;
F_10 ( V_111 , L_11 , V_130 -> V_136 . V_57 ) ;
V_81 = 0 ;
V_138 = NULL ;
V_124 = NULL ;
V_57 = ( char * ) V_130 -> V_136 . V_57 ;
V_133 = F_61 ( V_130 -> V_135 ) ;
if ( F_55 ( V_133 ) ) {
V_81 = F_62 ( V_133 ) ;
F_10 ( V_111 , L_10 , V_81 ) ;
return F_34 ( V_81 ) ;
}
V_138 = F_70 ( V_133 , 0 , NULL , 1 ) ;
if ( F_55 ( V_138 ) ) {
V_81 = F_62 ( V_138 ) ;
F_10 ( V_111 , L_12 , V_81 ) ;
return F_34 ( V_81 ) ;
}
V_81 = F_71 ( V_138 , V_57 , V_137 , V_3 , V_29 ) ;
if ( V_81 < 0 ) {
F_10 ( V_111 , L_13 , V_81 ) ;
goto error;
}
V_124 = F_70 ( V_133 , 1 , & V_57 , 1 ) ;
if ( F_55 ( V_124 ) ) {
V_81 = F_62 ( V_124 ) ;
F_10 ( V_111 , L_12 , V_81 ) ;
V_124 = NULL ;
goto error;
}
V_64 = F_72 ( V_2 , V_124 , V_129 -> V_139 ) ;
if ( F_55 ( V_64 ) ) {
V_81 = F_62 ( V_64 ) ;
F_10 ( V_111 , L_14 , V_81 ) ;
goto error;
}
V_81 = F_73 ( V_130 , V_124 ) ;
if ( V_81 < 0 )
goto error;
F_74 ( V_130 , V_64 ) ;
return V_138 ;
error:
if ( V_138 )
F_41 ( V_138 ) ;
if ( V_124 )
F_41 ( V_124 ) ;
return F_34 ( V_81 ) ;
}
static int
F_75 ( struct V_64 * V_129 , struct V_130 * V_130 , int V_3 ,
struct V_140 * V_141 )
{
int V_81 ;
T_2 V_137 ;
int V_125 ;
struct V_142 * V_143 ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
struct V_123 * V_124 , * V_144 ;
V_81 = 0 ;
V_124 = NULL ;
V_2 = F_43 ( V_129 ) ;
V_137 = F_1 ( V_2 , V_3 ) ;
if ( V_141 )
V_125 = V_141 -> V_145 . V_146 . V_125 ;
else
V_125 = V_41 ;
V_124 = F_69 ( V_2 , V_129 , V_130 , NULL , V_137 ,
F_12 ( V_125 ,
F_3 ( V_2 ) ) ) ;
if ( F_55 ( V_124 ) ) {
V_81 = F_62 ( V_124 ) ;
V_124 = NULL ;
goto error;
}
F_68 ( V_129 ) ;
if ( V_141 ) {
V_68 = F_23 ( V_130 -> V_134 ) ;
F_76 ( & V_68 -> V_75 ) ;
if ( V_2 -> V_100 && ! V_68 -> V_73 &&
( ( V_125 & V_147 ) != V_37 ) ) {
V_144 = F_77 ( V_130 ) ;
if ( F_55 ( V_144 ) ) {
V_81 = F_62 ( V_144 ) ;
F_78 ( & V_68 -> V_75 ) ;
goto error;
}
V_68 -> V_73 = ( void * ) V_144 ;
}
F_78 ( & V_68 -> V_75 ) ;
V_143 = F_79 ( V_141 , V_130 , V_148 ) ;
if ( F_55 ( V_143 ) ) {
V_81 = F_62 ( V_143 ) ;
goto error;
}
V_143 -> V_149 = V_124 ;
#ifdef F_16
if ( V_2 -> V_100 )
F_80 ( V_130 -> V_134 , V_143 ) ;
#endif
} else
F_41 ( V_124 ) ;
return 0 ;
error:
if ( V_124 )
F_41 ( V_124 ) ;
return V_81 ;
}
static int F_81 ( struct V_64 * V_129 , struct V_130 * V_130 , int V_3 )
{
int V_81 ;
T_2 V_137 ;
struct V_123 * V_124 ;
struct V_1 * V_2 ;
F_10 ( V_111 , L_11 , V_130 -> V_136 . V_57 ) ;
V_81 = 0 ;
V_2 = F_43 ( V_129 ) ;
V_137 = F_1 ( V_2 , V_3 | V_22 ) ;
V_124 = F_69 ( V_2 , V_129 , V_130 , NULL , V_137 , V_38 ) ;
if ( F_55 ( V_124 ) ) {
V_81 = F_62 ( V_124 ) ;
V_124 = NULL ;
} else {
F_30 ( V_129 ) ;
F_68 ( V_129 ) ;
}
if ( V_124 )
F_41 ( V_124 ) ;
return V_81 ;
}
struct V_130 * F_82 ( struct V_64 * V_129 , struct V_130 * V_130 ,
struct V_140 * V_140 )
{
struct V_130 * V_4 ;
struct V_65 * V_66 ;
struct V_1 * V_2 ;
struct V_123 * V_133 , * V_124 ;
struct V_64 * V_64 ;
char * V_57 ;
int V_150 = 0 ;
F_10 ( V_111 , L_15 ,
V_129 , V_130 -> V_136 . V_57 , V_130 , V_140 ) ;
if ( V_130 -> V_136 . V_151 > V_152 )
return F_34 ( - V_153 ) ;
V_66 = V_129 -> V_139 ;
V_2 = F_43 ( V_129 ) ;
V_133 = F_61 ( V_130 -> V_135 ) ;
if ( F_55 ( V_133 ) )
return F_56 ( V_133 ) ;
V_57 = ( char * ) V_130 -> V_136 . V_57 ;
V_124 = F_70 ( V_133 , 1 , & V_57 , 1 ) ;
if ( F_55 ( V_124 ) ) {
V_150 = F_62 ( V_124 ) ;
if ( V_150 == - V_154 ) {
V_64 = NULL ;
goto V_155;
}
return F_34 ( V_150 ) ;
}
if ( V_2 -> V_100 )
V_64 = F_83 ( V_2 , V_124 , V_129 -> V_139 ) ;
else
V_64 = F_72 ( V_2 , V_124 , V_129 -> V_139 ) ;
if ( F_55 ( V_64 ) ) {
V_150 = F_62 ( V_64 ) ;
V_64 = NULL ;
goto error;
}
V_150 = F_73 ( V_130 , V_124 ) ;
if ( V_150 < 0 )
goto V_156;
V_155:
V_4 = F_84 ( V_130 , V_64 ) ;
if ( ! F_55 ( V_4 ) )
return V_4 ;
V_150 = F_62 ( V_4 ) ;
V_156:
F_35 ( V_64 ) ;
error:
F_41 ( V_124 ) ;
return F_34 ( V_150 ) ;
}
int F_85 ( struct V_64 * V_157 , struct V_130 * V_158 )
{
return F_60 ( V_157 , V_158 , 0 ) ;
}
int F_86 ( struct V_64 * V_157 , struct V_130 * V_158 )
{
return F_60 ( V_157 , V_158 , V_127 ) ;
}
int
F_87 ( struct V_64 * V_159 , struct V_130 * V_160 ,
struct V_64 * V_161 , struct V_130 * V_162 )
{
int V_119 ;
struct V_64 * V_163 ;
struct V_64 * F_32 ;
struct V_1 * V_2 ;
struct V_123 * V_164 ;
struct V_123 * V_165 ;
struct V_123 * V_166 ;
struct V_18 V_49 ;
F_10 ( V_111 , L_16 ) ;
V_119 = 0 ;
V_163 = V_160 -> V_134 ;
F_32 = V_162 -> V_134 ;
V_2 = F_43 ( V_163 ) ;
V_164 = F_61 ( V_160 ) ;
if ( F_55 ( V_164 ) )
return F_62 ( V_164 ) ;
V_165 = F_64 ( V_160 -> V_135 ) ;
if ( F_55 ( V_165 ) ) {
V_119 = F_62 ( V_165 ) ;
goto V_167;
}
V_166 = F_64 ( V_162 -> V_135 ) ;
if ( F_55 ( V_166 ) ) {
V_119 = F_62 ( V_166 ) ;
goto V_168;
}
F_88 ( & V_2 -> V_169 ) ;
if ( F_28 ( V_2 ) ) {
V_119 = F_89 ( V_165 , V_160 -> V_136 . V_57 ,
V_166 , V_162 -> V_136 . V_57 ) ;
if ( V_119 == - V_131 )
V_119 = F_90 ( V_164 , V_166 ,
V_162 -> V_136 . V_57 ) ;
if ( V_119 != - V_131 )
goto V_170;
}
if ( V_160 -> V_135 != V_162 -> V_135 ) {
F_10 ( V_32 ,
L_17 ) ;
V_119 = - V_171 ;
goto V_170;
}
F_13 ( & V_49 ) ;
V_49 . V_60 = V_2 -> V_172 ;
V_49 . V_57 = ( char * ) V_162 -> V_136 . V_57 ;
V_119 = F_91 ( V_164 , & V_49 ) ;
V_170:
if ( ! V_119 ) {
if ( F_32 ) {
if ( F_2 ( F_32 -> V_99 ) )
F_66 ( F_32 ) ;
else
F_67 ( F_32 ) ;
}
if ( F_2 ( V_163 -> V_99 ) ) {
if ( ! F_32 )
F_30 ( V_161 ) ;
F_67 ( V_159 ) ;
}
F_68 ( V_163 ) ;
F_68 ( V_159 ) ;
F_68 ( V_161 ) ;
F_92 ( V_160 , V_162 ) ;
}
F_93 ( & V_2 -> V_169 ) ;
F_41 ( V_166 ) ;
V_168:
F_41 ( V_165 ) ;
V_167:
return V_119 ;
}
static int
F_94 ( struct V_173 * V_174 , struct V_130 * V_130 ,
struct V_175 * V_19 )
{
int V_81 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
struct V_18 * V_116 ;
F_10 ( V_111 , L_18 , V_130 ) ;
V_81 = - V_176 ;
V_2 = F_95 ( V_130 ) ;
if ( V_2 -> V_100 == V_177 || V_2 -> V_100 == V_178 ) {
F_96 ( V_130 -> V_134 , V_19 ) ;
return 0 ;
}
V_124 = F_61 ( V_130 ) ;
if ( F_55 ( V_124 ) )
return F_62 ( V_124 ) ;
V_116 = F_54 ( V_124 ) ;
if ( F_55 ( V_116 ) )
return F_62 ( V_116 ) ;
F_50 ( V_116 , V_130 -> V_134 , V_130 -> V_134 -> V_139 ) ;
F_96 ( V_130 -> V_134 , V_19 ) ;
F_57 ( V_116 ) ;
F_58 ( V_116 ) ;
return 0 ;
}
static int F_97 ( struct V_130 * V_130 , struct V_179 * V_179 )
{
int V_119 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
struct V_18 V_49 ;
F_10 ( V_111 , L_16 ) ;
V_119 = F_98 ( V_130 -> V_134 , V_179 ) ;
if ( V_119 )
return V_119 ;
V_119 = - V_176 ;
V_2 = F_95 ( V_130 ) ;
V_124 = F_61 ( V_130 ) ;
if( F_55 ( V_124 ) )
return F_62 ( V_124 ) ;
F_13 ( & V_49 ) ;
if ( V_179 -> V_180 & V_181 )
V_49 . V_3 = F_1 ( V_2 , V_179 -> V_182 ) ;
if ( V_179 -> V_180 & V_183 )
V_49 . V_55 = V_179 -> V_184 . V_185 ;
if ( V_179 -> V_180 & V_186 )
V_49 . V_54 = V_179 -> V_187 . V_185 ;
if ( V_179 -> V_180 & V_188 )
V_49 . V_56 = V_179 -> V_189 ;
if ( F_3 ( V_2 ) ) {
if ( V_179 -> V_180 & V_190 )
V_49 . V_61 = V_179 -> V_191 ;
if ( V_179 -> V_180 & V_192 )
V_49 . V_62 = V_179 -> V_193 ;
}
if ( F_99 ( V_130 -> V_134 -> V_99 ) )
F_100 ( V_130 -> V_134 -> V_88 ) ;
V_119 = F_91 ( V_124 , & V_49 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ( V_179 -> V_180 & V_188 ) &&
V_179 -> V_189 != F_101 ( V_130 -> V_134 ) )
F_102 ( V_130 -> V_134 , V_179 -> V_189 ) ;
F_68 ( V_130 -> V_134 ) ;
F_103 ( V_130 -> V_134 , V_179 ) ;
F_104 ( V_130 -> V_134 ) ;
return 0 ;
}
void
F_50 ( struct V_18 * V_19 , struct V_64 * V_64 ,
struct V_65 * V_66 )
{
T_4 V_3 ;
char V_26 [ 32 ] ;
char V_194 [ 14 ] ;
unsigned int V_195 ;
struct V_1 * V_2 = V_66 -> V_110 ;
struct V_67 * V_68 = F_23 ( V_64 ) ;
V_64 -> V_195 = 1 ;
V_64 -> V_84 . V_185 = V_19 -> V_54 ;
V_64 -> V_85 . V_185 = V_19 -> V_55 ;
V_64 -> V_86 . V_185 = V_19 -> V_55 ;
V_64 -> V_196 = V_2 -> V_197 ;
V_64 -> V_198 = V_2 -> V_199 ;
if ( F_3 ( V_2 ) ) {
V_64 -> V_196 = V_19 -> V_61 ;
V_64 -> V_198 = V_19 -> V_62 ;
}
if ( ( F_99 ( V_64 -> V_99 ) ) || ( F_2 ( V_64 -> V_99 ) ) ) {
if ( F_3 ( V_2 ) && ( V_19 -> V_29 [ 0 ] != '\0' ) ) {
strncpy ( V_26 , V_19 -> V_29 , sizeof( V_26 ) ) ;
sscanf ( V_26 , L_19 , V_194 , & V_195 ) ;
if ( ! strncmp ( V_194 , L_20 , 13 ) )
V_64 -> V_195 = V_195 ;
}
}
V_3 = V_19 -> V_3 & V_21 ;
V_3 |= V_64 -> V_99 & ~ V_21 ;
V_64 -> V_99 = V_3 ;
F_105 ( V_64 , V_19 -> V_56 ) ;
V_64 -> V_82 = ( F_101 ( V_64 ) + 512 - 1 ) >> 9 ;
V_68 -> V_74 &= ~ V_200 ;
}
T_5 F_48 ( struct V_117 * V_51 )
{
T_6 V_53 = V_51 -> V_53 + 2 ;
T_5 V_157 = 0 ;
if ( sizeof( T_5 ) == sizeof( V_53 ) )
memcpy ( & V_157 , & V_53 , sizeof( T_5 ) ) ;
else
V_157 = ( T_5 ) ( V_53 ^ ( V_53 >> 32 ) ) ;
return V_157 ;
}
static int F_106 ( struct V_130 * V_130 , char * V_201 , int V_202 )
{
int V_119 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
struct V_18 * V_116 ;
F_10 ( V_111 , L_21 , V_130 -> V_136 . V_57 ) ;
V_119 = - V_176 ;
V_2 = F_95 ( V_130 ) ;
V_124 = F_61 ( V_130 ) ;
if ( F_55 ( V_124 ) )
return F_62 ( V_124 ) ;
if ( ! F_3 ( V_2 ) )
return - V_203 ;
V_116 = F_54 ( V_124 ) ;
if ( F_55 ( V_116 ) )
return F_62 ( V_116 ) ;
if ( ! ( V_116 -> V_3 & V_6 ) ) {
V_119 = - V_98 ;
goto V_167;
}
strncpy ( V_201 , V_116 -> V_29 , V_202 ) ;
F_10 ( V_111 ,
L_22 , V_130 -> V_136 . V_57 , V_116 -> V_29 , V_201 ) ;
V_119 = F_107 ( V_201 , V_202 ) ;
V_167:
F_57 ( V_116 ) ;
F_58 ( V_116 ) ;
return V_119 ;
}
static void * F_108 ( struct V_130 * V_130 , struct V_140 * V_141 )
{
int V_151 = 0 ;
char * V_204 = F_109 () ;
F_10 ( V_111 , L_23 , V_130 -> V_136 . V_57 ) ;
if ( ! V_204 )
V_204 = F_34 ( - V_113 ) ;
else {
V_151 = F_106 ( V_130 , V_204 , V_205 ) ;
if ( V_151 < 0 ) {
F_110 ( V_204 ) ;
V_204 = F_34 ( V_151 ) ;
} else
V_204 [ F_111 ( V_151 , V_205 - 1 ) ] = 0 ;
}
F_112 ( V_141 , V_204 ) ;
return NULL ;
}
void
F_113 ( struct V_130 * V_130 , struct V_140 * V_141 , void * V_206 )
{
char * V_207 = F_114 ( V_141 ) ;
F_10 ( V_111 , L_24 , V_130 -> V_136 . V_57 ,
F_55 ( V_207 ) ? L_25 : V_207 ) ;
if ( ! F_55 ( V_207 ) )
F_110 ( V_207 ) ;
}
static int F_115 ( struct V_64 * V_129 , struct V_130 * V_130 ,
int V_3 , const char * V_29 )
{
T_2 V_137 ;
struct V_123 * V_124 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_129 ) ;
if ( ! F_3 ( V_2 ) ) {
F_10 ( V_32 , L_26 ) ;
return - V_176 ;
}
V_137 = F_1 ( V_2 , V_3 ) ;
V_124 = F_69 ( V_2 , V_129 , V_130 , ( char * ) V_29 , V_137 ,
V_38 ) ;
if ( F_55 ( V_124 ) )
return F_62 ( V_124 ) ;
F_68 ( V_129 ) ;
F_41 ( V_124 ) ;
return 0 ;
}
static int
F_116 ( struct V_64 * V_129 , struct V_130 * V_130 , const char * V_208 )
{
F_10 ( V_111 , L_27 , V_129 -> V_120 ,
V_130 -> V_136 . V_57 , V_208 ) ;
return F_115 ( V_129 , V_130 , V_23 , V_208 ) ;
}
static int
F_117 ( struct V_130 * V_160 , struct V_64 * V_129 ,
struct V_130 * V_130 )
{
int V_119 ;
char * V_57 ;
struct V_123 * V_164 ;
F_10 ( V_111 ,
L_27 , V_129 -> V_120 , V_130 -> V_136 . V_57 ,
V_160 -> V_136 . V_57 ) ;
V_164 = F_64 ( V_160 ) ;
if ( F_55 ( V_164 ) )
return F_62 ( V_164 ) ;
V_57 = F_109 () ;
if ( F_118 ( ! V_57 ) ) {
V_119 = - V_113 ;
goto V_209;
}
sprintf ( V_57 , L_28 , V_164 -> V_124 ) ;
V_119 = F_115 ( V_129 , V_130 , V_17 , V_57 ) ;
F_110 ( V_57 ) ;
if ( ! V_119 ) {
F_119 ( V_164 , V_160 -> V_134 ) ;
F_68 ( V_129 ) ;
}
V_209:
F_41 ( V_164 ) ;
return V_119 ;
}
static int
F_120 ( struct V_64 * V_129 , struct V_130 * V_130 , int V_3 , T_1 V_20 )
{
int V_119 ;
char * V_57 ;
F_10 ( V_111 ,
L_29 , V_129 -> V_120 ,
V_130 -> V_136 . V_57 , V_3 , F_121 ( V_20 ) , F_122 ( V_20 ) ) ;
if ( ! F_123 ( V_20 ) )
return - V_98 ;
V_57 = F_109 () ;
if ( ! V_57 )
return - V_113 ;
if ( F_7 ( V_3 ) )
sprintf ( V_57 , L_30 , F_121 ( V_20 ) , F_122 ( V_20 ) ) ;
else if ( F_8 ( V_3 ) )
sprintf ( V_57 , L_31 , F_121 ( V_20 ) , F_122 ( V_20 ) ) ;
else if ( F_6 ( V_3 ) )
* V_57 = 0 ;
else if ( F_5 ( V_3 ) )
* V_57 = 0 ;
else {
F_110 ( V_57 ) ;
return - V_98 ;
}
V_119 = F_115 ( V_129 , V_130 , V_3 , V_57 ) ;
F_110 ( V_57 ) ;
return V_119 ;
}
int F_119 ( struct V_123 * V_124 , struct V_64 * V_64 )
{
int V_115 ;
T_1 V_20 ;
T_7 V_210 ;
struct V_18 * V_116 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_64 ) ;
V_116 = F_54 ( V_124 ) ;
if ( F_55 ( V_116 ) )
return F_62 ( V_116 ) ;
V_115 = F_9 ( V_2 , V_116 , & V_20 ) ;
if ( ( V_64 -> V_99 & V_91 ) != ( V_115 & V_91 ) )
goto V_211;
F_124 ( & V_64 -> V_212 ) ;
V_210 = V_64 -> V_210 ;
F_50 ( V_116 , V_64 , V_64 -> V_139 ) ;
if ( V_2 -> V_100 )
V_64 -> V_210 = V_210 ;
F_125 ( & V_64 -> V_212 ) ;
V_211:
F_57 ( V_116 ) ;
F_58 ( V_116 ) ;
return 0 ;
}
