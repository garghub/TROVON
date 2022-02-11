static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = V_3 & 0777 ;
if ( F_2 ( V_3 ) )
V_4 |= V_5 ;
if ( F_3 ( V_2 ) ) {
if ( V_2 -> V_6 == 0 ) {
if ( F_4 ( V_3 ) )
V_4 |= V_7 ;
if ( F_5 ( V_3 ) )
V_4 |= V_8 ;
if ( F_6 ( V_3 ) )
V_4 |= V_9 ;
if ( F_7 ( V_3 ) )
V_4 |= V_9 ;
}
if ( ( V_3 & V_10 ) == V_10 )
V_4 |= V_11 ;
if ( ( V_3 & V_12 ) == V_12 )
V_4 |= V_13 ;
if ( ( V_3 & V_14 ) == V_14 )
V_4 |= V_15 ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_4 ;
int V_3 = V_17 -> V_3 ;
V_4 = V_3 & V_18 ;
if ( F_3 ( V_2 ) ) {
if ( ( V_3 & V_11 ) == V_11 )
V_4 |= V_10 ;
if ( ( V_3 & V_13 ) == V_13 )
V_4 |= V_12 ;
if ( ( V_3 & V_15 ) == V_15 )
V_4 |= V_14 ;
}
return V_4 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_3 * V_19 )
{
int V_4 ;
T_1 V_3 = V_17 -> V_3 ;
* V_19 = 0 ;
V_4 = F_8 ( V_2 , V_17 ) ;
if ( ( V_3 & V_5 ) == V_5 )
V_4 |= V_20 ;
else if ( ( V_3 & V_21 ) && ( F_3 ( V_2 ) ) )
V_4 |= V_22 ;
else if ( ( V_3 & V_7 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_6 == 0 ) )
V_4 |= V_23 ;
else if ( ( V_3 & V_8 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_6 == 0 ) )
V_4 |= V_24 ;
else if ( ( V_3 & V_9 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_6 == 0 ) ) {
char type = 0 , V_25 [ 32 ] ;
int V_26 = - 1 , V_27 = - 1 ;
strncpy ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_1 , & type , & V_26 , & V_27 ) ;
switch ( type ) {
case 'c' :
V_4 |= V_29 ;
break;
case 'b' :
V_4 |= V_30 ;
break;
default:
F_10 ( V_31 , L_2 ,
type , V_17 -> V_28 ) ;
} ;
* V_19 = F_11 ( V_26 , V_27 ) ;
} else
V_4 |= V_32 ;
return V_4 ;
}
int F_12 ( int V_33 , int V_34 )
{
int V_35 ;
V_35 = 0 ;
switch ( V_33 & 3 ) {
default:
case V_36 :
V_35 = V_37 ;
break;
case V_38 :
V_35 = V_39 ;
break;
case V_40 :
V_35 = V_41 ;
break;
}
if ( V_33 & V_42 )
V_35 |= V_43 ;
if ( V_34 ) {
if ( V_33 & V_44 )
V_35 |= V_45 ;
if ( V_33 & V_46 )
V_35 |= V_47 ;
}
return V_35 ;
}
void
F_13 ( struct V_16 * V_48 )
{
V_48 -> type = ~ 0 ;
V_48 -> V_49 = ~ 0 ;
V_48 -> V_50 . type = ~ 0 ;
V_48 -> V_50 . V_51 = ~ 0 ;
* ( ( long long * ) & V_48 -> V_50 . V_52 ) = ~ 0 ;
V_48 -> V_3 = ~ 0 ;
V_48 -> V_53 = ~ 0 ;
V_48 -> V_54 = ~ 0 ;
V_48 -> V_55 = ~ 0 ;
V_48 -> V_56 = NULL ;
V_48 -> V_57 = NULL ;
V_48 -> V_58 = NULL ;
V_48 -> V_59 = NULL ;
V_48 -> V_60 = ~ 0 ;
V_48 -> V_61 = ~ 0 ;
V_48 -> V_62 = ~ 0 ;
V_48 -> V_28 = NULL ;
}
struct V_63 * F_14 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
V_67 = (struct V_66 * ) F_15 ( V_68 ,
V_69 ) ;
if ( ! V_67 )
return NULL ;
#ifdef F_16
V_67 -> V_70 = NULL ;
F_17 ( & V_67 -> V_71 ) ;
#endif
V_67 -> V_72 = NULL ;
V_67 -> V_73 = 0 ;
F_18 ( & V_67 -> V_74 ) ;
return & V_67 -> V_75 ;
}
static void F_19 ( struct V_76 * V_77 )
{
struct V_63 * V_63 = F_20 ( V_77 , struct V_63 , V_78 ) ;
F_21 ( V_68 , F_22 ( V_63 ) ) ;
}
void F_23 ( struct V_63 * V_63 )
{
F_24 ( & V_63 -> V_78 , F_19 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_63 * V_63 , T_2 V_3 , T_3 V_19 )
{
int V_79 = 0 ;
F_26 ( V_63 , NULL , V_3 ) ;
V_63 -> V_80 = 0 ;
V_63 -> V_81 = V_19 ;
V_63 -> V_82 = V_63 -> V_83 = V_63 -> V_84 = V_85 ;
V_63 -> V_86 -> V_87 = & V_88 ;
switch ( V_3 & V_89 ) {
case V_24 :
case V_30 :
case V_29 :
case V_23 :
if ( F_27 ( V_2 ) ) {
V_63 -> V_90 = & V_91 ;
} else if ( F_3 ( V_2 ) ) {
V_63 -> V_90 = & V_92 ;
} else {
F_10 ( V_31 ,
L_3 ) ;
V_79 = - V_93 ;
goto error;
}
F_28 ( V_63 , V_63 -> V_94 , V_63 -> V_81 ) ;
break;
case V_32 :
if ( F_27 ( V_2 ) ) {
V_63 -> V_90 = & V_91 ;
if ( V_2 -> V_95 )
V_63 -> V_96 =
& V_97 ;
else
V_63 -> V_96 = & V_98 ;
} else {
V_63 -> V_90 = & V_92 ;
if ( V_2 -> V_95 )
V_63 -> V_96 = & V_99 ;
else
V_63 -> V_96 = & V_100 ;
}
break;
case V_22 :
if ( ! F_3 ( V_2 ) && ! F_27 ( V_2 ) ) {
F_10 ( V_31 ,
L_4 ) ;
V_79 = - V_93 ;
goto error;
}
if ( F_27 ( V_2 ) )
V_63 -> V_90 = & V_101 ;
else
V_63 -> V_90 = & V_102 ;
break;
case V_20 :
F_29 ( V_63 ) ;
if ( F_27 ( V_2 ) )
V_63 -> V_90 = & V_103 ;
else if ( F_3 ( V_2 ) )
V_63 -> V_90 = & V_104 ;
else
V_63 -> V_90 = & V_105 ;
if ( F_27 ( V_2 ) )
V_63 -> V_96 = & V_106 ;
else
V_63 -> V_96 = & V_107 ;
break;
default:
F_10 ( V_31 , L_5 ,
V_3 , V_3 & V_89 ) ;
V_79 = - V_93 ;
goto error;
}
error:
return V_79 ;
}
struct V_63 * F_30 ( struct V_64 * V_65 , T_2 V_3 , T_3 V_19 )
{
int V_79 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_108 ;
F_10 ( V_109 , L_6 , V_65 , V_3 ) ;
V_63 = F_31 ( V_65 ) ;
if ( ! V_63 ) {
F_32 ( L_7 ,
V_110 , F_33 ( V_111 ) ) ;
return F_34 ( - V_112 ) ;
}
V_79 = F_25 ( V_2 , V_63 , V_3 , V_19 ) ;
if ( V_79 ) {
F_35 ( V_63 ) ;
return F_34 ( V_79 ) ;
}
return V_63 ;
}
void F_36 ( struct V_63 * V_63 )
{
struct V_66 * V_67 = F_22 ( V_63 ) ;
F_37 ( V_63 -> V_86 , 0 ) ;
F_38 ( V_63 ) ;
F_39 ( V_63 -> V_86 ) ;
#ifdef F_16
F_40 ( V_63 ) ;
#endif
if ( V_67 -> V_72 ) {
F_41 ( V_67 -> V_72 ) ;
V_67 -> V_72 = NULL ;
}
}
static int F_42 ( struct V_63 * V_63 , void * V_113 )
{
int V_114 ;
T_3 V_19 ;
struct V_66 * V_67 = F_22 ( V_63 ) ;
struct V_16 * V_115 = (struct V_16 * ) V_113 ;
struct V_1 * V_2 = F_43 ( V_63 ) ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_114 & V_89 ) )
return 0 ;
if ( memcmp ( & V_67 -> V_50 . V_51 ,
& V_115 -> V_50 . V_51 , sizeof( V_67 -> V_50 . V_51 ) ) )
return 0 ;
if ( V_67 -> V_50 . type != V_115 -> V_50 . type )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_63 * V_63 , void * V_113 )
{
return 0 ;
}
static int F_45 ( struct V_63 * V_63 , void * V_113 )
{
struct V_66 * V_67 = F_22 ( V_63 ) ;
struct V_16 * V_115 = (struct V_16 * ) V_113 ;
memcpy ( & V_67 -> V_50 , & V_115 -> V_50 , sizeof( V_115 -> V_50 ) ) ;
return 0 ;
}
static struct V_63 * F_46 ( struct V_64 * V_65 ,
struct V_116 * V_50 ,
struct V_16 * V_115 ,
int V_117 )
{
T_3 V_19 ;
int V_118 ;
T_2 V_114 ;
unsigned long V_119 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_108 ;
int (* F_47)( struct V_63 * , void * );
if ( V_117 )
F_47 = F_44 ;
else
F_47 = F_42 ;
V_119 = F_48 ( V_50 ) ;
V_63 = F_49 ( V_65 , V_119 , F_47 , F_45 , V_115 ) ;
if ( ! V_63 )
return F_34 ( - V_112 ) ;
if ( ! ( V_63 -> V_120 & V_121 ) )
return V_63 ;
V_63 -> V_119 = V_119 ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
V_118 = F_25 ( V_2 , V_63 , V_114 , V_19 ) ;
if ( V_118 )
goto error;
F_50 ( V_115 , V_63 , V_65 ) ;
#ifdef F_16
F_51 ( V_63 ) ;
#endif
F_52 ( V_63 ) ;
return V_63 ;
error:
F_52 ( V_63 ) ;
F_35 ( V_63 ) ;
return F_34 ( V_118 ) ;
}
struct V_63 *
F_53 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_64 * V_65 , int V_117 )
{
struct V_16 * V_115 ;
struct V_63 * V_63 = NULL ;
V_115 = F_54 ( V_123 ) ;
if ( F_55 ( V_115 ) )
return F_56 ( V_115 ) ;
V_63 = F_46 ( V_65 , & V_115 -> V_50 , V_115 , V_117 ) ;
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
return V_63 ;
}
static int F_59 ( int V_124 )
{
int V_125 = 0 ;
if ( V_124 & V_126 )
V_125 |= V_127 ;
return V_125 ;
}
static int F_60 ( struct V_63 * V_128 , struct V_129 * V_129 , int V_124 )
{
struct V_63 * V_63 ;
int V_118 = - V_130 ;
struct V_122 * V_131 , * V_132 ;
struct V_1 * V_2 ;
F_10 ( V_109 , L_8 ,
V_128 , V_129 , V_124 ) ;
V_2 = F_43 ( V_128 ) ;
V_63 = V_129 -> V_133 ;
V_132 = F_61 ( V_129 -> V_134 ) ;
if ( F_55 ( V_132 ) ) {
V_118 = F_62 ( V_132 ) ;
F_10 ( V_109 , L_9 , V_118 ) ;
return V_118 ;
}
if ( F_27 ( V_2 ) )
V_118 = F_63 ( V_132 , V_129 -> V_135 . V_56 ,
F_59 ( V_124 ) ) ;
if ( V_118 == - V_130 ) {
V_131 = F_64 ( V_129 ) ;
if ( F_55 ( V_131 ) )
return F_62 ( V_131 ) ;
V_118 = F_65 ( V_131 ) ;
}
if ( ! V_118 ) {
if ( V_124 & V_126 ) {
F_66 ( V_63 ) ;
F_67 ( V_128 ) ;
} else
F_67 ( V_63 ) ;
F_68 ( V_63 ) ;
F_68 ( V_128 ) ;
}
return V_118 ;
}
static struct V_122 *
F_69 ( struct V_1 * V_2 , struct V_63 * V_128 ,
struct V_129 * V_129 , char * V_28 , T_1 V_136 , T_4 V_3 )
{
int V_79 ;
char * V_56 ;
struct V_122 * V_132 , * V_137 , * V_123 ;
struct V_63 * V_63 ;
F_10 ( V_109 , L_10 , V_129 -> V_135 . V_56 ) ;
V_79 = 0 ;
V_137 = NULL ;
V_123 = NULL ;
V_56 = ( char * ) V_129 -> V_135 . V_56 ;
V_132 = F_61 ( V_129 -> V_134 ) ;
if ( F_55 ( V_132 ) ) {
V_79 = F_62 ( V_132 ) ;
F_10 ( V_109 , L_9 , V_79 ) ;
return F_34 ( V_79 ) ;
}
V_137 = F_70 ( V_132 , 0 , NULL , 1 ) ;
if ( F_55 ( V_137 ) ) {
V_79 = F_62 ( V_137 ) ;
F_10 ( V_109 , L_11 , V_79 ) ;
return F_34 ( V_79 ) ;
}
V_79 = F_71 ( V_137 , V_56 , V_136 , V_3 , V_28 ) ;
if ( V_79 < 0 ) {
F_10 ( V_109 , L_12 , V_79 ) ;
goto error;
}
if ( ! ( V_136 & V_138 ) ) {
V_123 = F_70 ( V_132 , 1 , & V_56 , 1 ) ;
if ( F_55 ( V_123 ) ) {
V_79 = F_62 ( V_123 ) ;
F_10 ( V_109 ,
L_11 , V_79 ) ;
V_123 = NULL ;
goto error;
}
V_63 = F_72 ( V_2 , V_123 , V_128 -> V_139 ) ;
if ( F_55 ( V_63 ) ) {
V_79 = F_62 ( V_63 ) ;
F_10 ( V_109 ,
L_13 , V_79 ) ;
goto error;
}
V_79 = F_73 ( V_129 , V_123 ) ;
if ( V_79 < 0 )
goto error;
F_74 ( V_129 , V_63 ) ;
}
return V_137 ;
error:
if ( V_137 )
F_41 ( V_137 ) ;
if ( V_123 )
F_41 ( V_123 ) ;
return F_34 ( V_79 ) ;
}
static int
F_75 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 ,
bool V_140 )
{
struct V_1 * V_2 = F_43 ( V_128 ) ;
T_1 V_136 = F_1 ( V_2 , V_3 ) ;
struct V_122 * V_123 ;
V_123 = F_69 ( V_2 , V_128 , V_129 , NULL , V_136 , V_41 ) ;
if ( F_55 ( V_123 ) )
return F_62 ( V_123 ) ;
F_68 ( V_128 ) ;
F_41 ( V_123 ) ;
return 0 ;
}
static int F_76 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 )
{
int V_79 ;
T_1 V_136 ;
struct V_122 * V_123 ;
struct V_1 * V_2 ;
F_10 ( V_109 , L_10 , V_129 -> V_135 . V_56 ) ;
V_79 = 0 ;
V_2 = F_43 ( V_128 ) ;
V_136 = F_1 ( V_2 , V_3 | V_20 ) ;
V_123 = F_69 ( V_2 , V_128 , V_129 , NULL , V_136 , V_37 ) ;
if ( F_55 ( V_123 ) ) {
V_79 = F_62 ( V_123 ) ;
V_123 = NULL ;
} else {
F_29 ( V_128 ) ;
F_68 ( V_128 ) ;
}
if ( V_123 )
F_41 ( V_123 ) ;
return V_79 ;
}
struct V_129 * F_77 ( struct V_63 * V_128 , struct V_129 * V_129 ,
unsigned int V_124 )
{
struct V_129 * V_4 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
struct V_122 * V_132 , * V_123 ;
struct V_63 * V_63 ;
char * V_56 ;
int V_141 = 0 ;
F_10 ( V_109 , L_14 ,
V_128 , V_129 -> V_135 . V_56 , V_129 , V_124 ) ;
if ( V_129 -> V_135 . V_142 > V_143 )
return F_34 ( - V_144 ) ;
V_65 = V_128 -> V_139 ;
V_2 = F_43 ( V_128 ) ;
V_132 = F_61 ( V_129 -> V_134 ) ;
if ( F_55 ( V_132 ) )
return F_56 ( V_132 ) ;
V_56 = ( char * ) V_129 -> V_135 . V_56 ;
V_123 = F_70 ( V_132 , 1 , & V_56 , 1 ) ;
if ( F_55 ( V_123 ) ) {
V_141 = F_62 ( V_123 ) ;
if ( V_141 == - V_145 ) {
V_63 = NULL ;
goto V_146;
}
return F_34 ( V_141 ) ;
}
if ( V_2 -> V_95 )
V_63 = F_78 ( V_2 , V_123 , V_128 -> V_139 ) ;
else
V_63 = F_72 ( V_2 , V_123 , V_128 -> V_139 ) ;
if ( F_55 ( V_63 ) ) {
V_141 = F_62 ( V_63 ) ;
V_63 = NULL ;
goto error;
}
V_141 = F_73 ( V_129 , V_123 ) ;
if ( V_141 < 0 )
goto V_147;
V_146:
V_4 = F_79 ( V_129 , V_63 ) ;
if ( ! F_55 ( V_4 ) )
return V_4 ;
V_141 = F_62 ( V_4 ) ;
V_147:
F_35 ( V_63 ) ;
error:
F_41 ( V_123 ) ;
return F_34 ( V_141 ) ;
}
static int
F_80 ( struct V_63 * V_128 , struct V_129 * V_129 ,
struct V_148 * V_148 , unsigned V_124 , T_2 V_3 ,
int * V_149 )
{
int V_79 ;
T_1 V_136 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_122 * V_123 , * V_150 ;
struct V_129 * V_4 = NULL ;
if ( F_81 ( V_129 ) ) {
V_4 = F_77 ( V_128 , V_129 , 0 ) ;
if ( F_55 ( V_4 ) )
return F_62 ( V_4 ) ;
if ( V_4 )
V_129 = V_4 ;
}
if ( ! ( V_124 & V_151 ) || V_129 -> V_133 )
return F_82 ( V_148 , V_4 ) ;
V_79 = 0 ;
V_123 = NULL ;
V_2 = F_43 ( V_128 ) ;
V_136 = F_1 ( V_2 , V_3 ) ;
V_123 = F_69 ( V_2 , V_128 , V_129 , NULL , V_136 ,
F_12 ( V_124 ,
F_3 ( V_2 ) ) ) ;
if ( F_55 ( V_123 ) ) {
V_79 = F_62 ( V_123 ) ;
V_123 = NULL ;
goto error;
}
F_68 ( V_128 ) ;
V_67 = F_22 ( V_129 -> V_133 ) ;
F_83 ( & V_67 -> V_74 ) ;
if ( V_2 -> V_95 && ! V_67 -> V_72 &&
( ( V_124 & V_152 ) != V_36 ) ) {
V_150 = F_84 ( V_129 ) ;
if ( F_55 ( V_150 ) ) {
V_79 = F_62 ( V_150 ) ;
F_85 ( & V_67 -> V_74 ) ;
goto error;
}
V_67 -> V_72 = ( void * ) V_150 ;
}
F_85 ( & V_67 -> V_74 ) ;
V_79 = F_86 ( V_148 , V_129 , V_153 , V_149 ) ;
if ( V_79 )
goto error;
V_148 -> V_154 = V_123 ;
#ifdef F_16
if ( V_2 -> V_95 )
F_87 ( V_129 -> V_133 , V_148 ) ;
#endif
* V_149 |= V_155 ;
V_156:
F_88 ( V_4 ) ;
return V_79 ;
error:
if ( V_123 )
F_41 ( V_123 ) ;
goto V_156;
}
int F_89 ( struct V_63 * V_157 , struct V_129 * V_158 )
{
return F_60 ( V_157 , V_158 , 0 ) ;
}
int F_90 ( struct V_63 * V_157 , struct V_129 * V_158 )
{
return F_60 ( V_157 , V_158 , V_126 ) ;
}
int
F_91 ( struct V_63 * V_159 , struct V_129 * V_160 ,
struct V_63 * V_161 , struct V_129 * V_162 )
{
int V_118 ;
struct V_63 * V_163 ;
struct V_63 * F_31 ;
struct V_1 * V_2 ;
struct V_122 * V_164 ;
struct V_122 * V_165 ;
struct V_122 * V_166 ;
struct V_16 V_48 ;
F_10 ( V_109 , L_15 ) ;
V_118 = 0 ;
V_163 = V_160 -> V_133 ;
F_31 = V_162 -> V_133 ;
V_2 = F_43 ( V_163 ) ;
V_164 = F_61 ( V_160 ) ;
if ( F_55 ( V_164 ) )
return F_62 ( V_164 ) ;
V_165 = F_64 ( V_160 -> V_134 ) ;
if ( F_55 ( V_165 ) ) {
V_118 = F_62 ( V_165 ) ;
goto V_167;
}
V_166 = F_64 ( V_162 -> V_134 ) ;
if ( F_55 ( V_166 ) ) {
V_118 = F_62 ( V_166 ) ;
goto V_168;
}
F_92 ( & V_2 -> V_169 ) ;
if ( F_27 ( V_2 ) ) {
V_118 = F_93 ( V_165 , V_160 -> V_135 . V_56 ,
V_166 , V_162 -> V_135 . V_56 ) ;
if ( V_118 == - V_130 )
V_118 = F_94 ( V_164 , V_166 ,
V_162 -> V_135 . V_56 ) ;
if ( V_118 != - V_130 )
goto V_170;
}
if ( V_160 -> V_134 != V_162 -> V_134 ) {
F_10 ( V_31 , L_16 ) ;
V_118 = - V_171 ;
goto V_170;
}
F_13 ( & V_48 ) ;
V_48 . V_59 = V_2 -> V_172 ;
V_48 . V_56 = ( char * ) V_162 -> V_135 . V_56 ;
V_118 = F_95 ( V_164 , & V_48 ) ;
V_170:
if ( ! V_118 ) {
if ( F_31 ) {
if ( F_2 ( F_31 -> V_94 ) )
F_66 ( F_31 ) ;
else
F_67 ( F_31 ) ;
}
if ( F_2 ( V_163 -> V_94 ) ) {
if ( ! F_31 )
F_29 ( V_161 ) ;
F_67 ( V_159 ) ;
}
F_68 ( V_163 ) ;
F_68 ( V_159 ) ;
F_68 ( V_161 ) ;
F_96 ( V_160 , V_162 ) ;
}
F_97 ( & V_2 -> V_169 ) ;
F_41 ( V_166 ) ;
V_168:
F_41 ( V_165 ) ;
V_167:
return V_118 ;
}
static int
F_98 ( struct V_173 * V_174 , struct V_129 * V_129 ,
struct V_175 * V_17 )
{
int V_79 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 * V_115 ;
F_10 ( V_109 , L_17 , V_129 ) ;
V_79 = - V_176 ;
V_2 = F_99 ( V_129 ) ;
if ( V_2 -> V_95 == V_177 || V_2 -> V_95 == V_178 ) {
F_100 ( V_129 -> V_133 , V_17 ) ;
return 0 ;
}
V_123 = F_61 ( V_129 ) ;
if ( F_55 ( V_123 ) )
return F_62 ( V_123 ) ;
V_115 = F_54 ( V_123 ) ;
if ( F_55 ( V_115 ) )
return F_62 ( V_115 ) ;
F_50 ( V_115 , V_129 -> V_133 , V_129 -> V_133 -> V_139 ) ;
F_100 ( V_129 -> V_133 , V_17 ) ;
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
return 0 ;
}
static int F_101 ( struct V_129 * V_129 , struct V_179 * V_179 )
{
int V_118 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 V_48 ;
F_10 ( V_109 , L_15 ) ;
V_118 = F_102 ( V_129 -> V_133 , V_179 ) ;
if ( V_118 )
return V_118 ;
V_118 = - V_176 ;
V_2 = F_99 ( V_129 ) ;
V_123 = F_61 ( V_129 ) ;
if( F_55 ( V_123 ) )
return F_62 ( V_123 ) ;
F_13 ( & V_48 ) ;
if ( V_179 -> V_180 & V_181 )
V_48 . V_3 = F_1 ( V_2 , V_179 -> V_182 ) ;
if ( V_179 -> V_180 & V_183 )
V_48 . V_54 = V_179 -> V_184 . V_185 ;
if ( V_179 -> V_180 & V_186 )
V_48 . V_53 = V_179 -> V_187 . V_185 ;
if ( V_179 -> V_180 & V_188 )
V_48 . V_55 = V_179 -> V_189 ;
if ( F_3 ( V_2 ) ) {
if ( V_179 -> V_180 & V_190 )
V_48 . V_60 = V_179 -> V_191 ;
if ( V_179 -> V_180 & V_192 )
V_48 . V_61 = V_179 -> V_193 ;
}
if ( F_103 ( V_129 -> V_133 -> V_94 ) )
F_104 ( V_129 -> V_133 -> V_86 ) ;
V_118 = F_95 ( V_123 , & V_48 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ( V_179 -> V_180 & V_188 ) &&
V_179 -> V_189 != F_105 ( V_129 -> V_133 ) )
F_106 ( V_129 -> V_133 , V_179 -> V_189 ) ;
F_68 ( V_129 -> V_133 ) ;
F_107 ( V_129 -> V_133 , V_179 ) ;
F_108 ( V_129 -> V_133 ) ;
return 0 ;
}
void
F_50 ( struct V_16 * V_17 , struct V_63 * V_63 ,
struct V_64 * V_65 )
{
T_2 V_3 ;
char V_25 [ 32 ] ;
char V_194 [ 14 ] ;
unsigned int V_195 ;
struct V_1 * V_2 = V_65 -> V_108 ;
struct V_66 * V_67 = F_22 ( V_63 ) ;
F_109 ( V_63 , 1 ) ;
V_63 -> V_82 . V_185 = V_17 -> V_53 ;
V_63 -> V_83 . V_185 = V_17 -> V_54 ;
V_63 -> V_84 . V_185 = V_17 -> V_54 ;
V_63 -> V_196 = V_2 -> V_197 ;
V_63 -> V_198 = V_2 -> V_199 ;
if ( F_3 ( V_2 ) ) {
V_63 -> V_196 = V_17 -> V_60 ;
V_63 -> V_198 = V_17 -> V_61 ;
}
if ( ( F_103 ( V_63 -> V_94 ) ) || ( F_2 ( V_63 -> V_94 ) ) ) {
if ( F_3 ( V_2 ) && ( V_17 -> V_28 [ 0 ] != '\0' ) ) {
strncpy ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_18 , V_194 , & V_195 ) ;
if ( ! strncmp ( V_194 , L_19 , 13 ) )
F_109 ( V_63 , V_195 ) ;
}
}
V_3 = F_8 ( V_2 , V_17 ) ;
V_3 |= V_63 -> V_94 & ~ V_18 ;
V_63 -> V_94 = V_3 ;
F_110 ( V_63 , V_17 -> V_55 ) ;
V_63 -> V_80 = ( F_105 ( V_63 ) + 512 - 1 ) >> 9 ;
V_67 -> V_73 &= ~ V_200 ;
}
T_5 F_48 ( struct V_116 * V_50 )
{
T_6 V_52 = V_50 -> V_52 + 2 ;
T_5 V_157 = 0 ;
if ( sizeof( T_5 ) == sizeof( V_52 ) )
memcpy ( & V_157 , & V_52 , sizeof( T_5 ) ) ;
else
V_157 = ( T_5 ) ( V_52 ^ ( V_52 >> 32 ) ) ;
return V_157 ;
}
static int F_111 ( struct V_129 * V_129 , char * V_201 , int V_202 )
{
int V_118 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 * V_115 ;
F_10 ( V_109 , L_20 , V_129 -> V_135 . V_56 ) ;
V_118 = - V_176 ;
V_2 = F_99 ( V_129 ) ;
V_123 = F_61 ( V_129 ) ;
if ( F_55 ( V_123 ) )
return F_62 ( V_123 ) ;
if ( ! F_3 ( V_2 ) )
return - V_203 ;
V_115 = F_54 ( V_123 ) ;
if ( F_55 ( V_115 ) )
return F_62 ( V_115 ) ;
if ( ! ( V_115 -> V_3 & V_21 ) ) {
V_118 = - V_93 ;
goto V_167;
}
strncpy ( V_201 , V_115 -> V_28 , V_202 ) ;
F_10 ( V_109 , L_21 ,
V_129 -> V_135 . V_56 , V_115 -> V_28 , V_201 ) ;
V_118 = F_112 ( V_201 , V_202 ) ;
V_167:
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
return V_118 ;
}
static void * F_113 ( struct V_129 * V_129 , struct V_204 * V_205 )
{
int V_142 = 0 ;
char * V_206 = F_114 () ;
F_10 ( V_109 , L_22 , V_129 -> V_135 . V_56 ) ;
if ( ! V_206 )
V_206 = F_34 ( - V_112 ) ;
else {
V_142 = F_111 ( V_129 , V_206 , V_207 ) ;
if ( V_142 < 0 ) {
F_115 ( V_206 ) ;
V_206 = F_34 ( V_142 ) ;
} else
V_206 [ F_116 ( V_142 , V_207 - 1 ) ] = 0 ;
}
F_117 ( V_205 , V_206 ) ;
return NULL ;
}
void
F_118 ( struct V_129 * V_129 , struct V_204 * V_205 , void * V_208 )
{
char * V_209 = F_119 ( V_205 ) ;
F_10 ( V_109 , L_23 ,
V_129 -> V_135 . V_56 , F_55 ( V_209 ) ? L_24 : V_209 ) ;
if ( ! F_55 ( V_209 ) )
F_115 ( V_209 ) ;
}
static int F_120 ( struct V_63 * V_128 , struct V_129 * V_129 ,
T_1 V_136 , const char * V_28 )
{
struct V_122 * V_123 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_128 ) ;
if ( ! F_3 ( V_2 ) ) {
F_10 ( V_31 , L_25 ) ;
return - V_176 ;
}
V_123 = F_69 ( V_2 , V_128 , V_129 , ( char * ) V_28 , V_136 ,
V_37 ) ;
if ( F_55 ( V_123 ) )
return F_62 ( V_123 ) ;
F_68 ( V_128 ) ;
F_41 ( V_123 ) ;
return 0 ;
}
static int
F_121 ( struct V_63 * V_128 , struct V_129 * V_129 , const char * V_210 )
{
F_10 ( V_109 , L_26 ,
V_128 -> V_119 , V_129 -> V_135 . V_56 , V_210 ) ;
return F_120 ( V_128 , V_129 , V_21 , V_210 ) ;
}
static int
F_122 ( struct V_129 * V_160 , struct V_63 * V_128 ,
struct V_129 * V_129 )
{
int V_118 ;
char * V_56 ;
struct V_122 * V_164 ;
F_10 ( V_109 , L_26 ,
V_128 -> V_119 , V_129 -> V_135 . V_56 , V_160 -> V_135 . V_56 ) ;
V_164 = F_64 ( V_160 ) ;
if ( F_55 ( V_164 ) )
return F_62 ( V_164 ) ;
V_56 = F_114 () ;
if ( F_123 ( ! V_56 ) ) {
V_118 = - V_112 ;
goto V_211;
}
sprintf ( V_56 , L_27 , V_164 -> V_123 ) ;
V_118 = F_120 ( V_128 , V_129 , V_138 , V_56 ) ;
F_115 ( V_56 ) ;
if ( ! V_118 ) {
F_124 ( V_164 , V_160 -> V_133 ) ;
F_68 ( V_128 ) ;
}
V_211:
F_41 ( V_164 ) ;
return V_118 ;
}
static int
F_125 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 , T_3 V_19 )
{
struct V_1 * V_2 = F_43 ( V_128 ) ;
int V_118 ;
char * V_56 ;
T_1 V_136 ;
F_10 ( V_109 , L_28 ,
V_128 -> V_119 , V_129 -> V_135 . V_56 , V_3 ,
F_126 ( V_19 ) , F_127 ( V_19 ) ) ;
if ( ! F_128 ( V_19 ) )
return - V_93 ;
V_56 = F_114 () ;
if ( ! V_56 )
return - V_112 ;
if ( F_6 ( V_3 ) )
sprintf ( V_56 , L_29 , F_126 ( V_19 ) , F_127 ( V_19 ) ) ;
else if ( F_7 ( V_3 ) )
sprintf ( V_56 , L_30 , F_126 ( V_19 ) , F_127 ( V_19 ) ) ;
else if ( F_5 ( V_3 ) )
* V_56 = 0 ;
else if ( F_4 ( V_3 ) )
* V_56 = 0 ;
else {
F_115 ( V_56 ) ;
return - V_93 ;
}
V_136 = F_1 ( V_2 , V_3 ) ;
V_118 = F_120 ( V_128 , V_129 , V_136 , V_56 ) ;
F_115 ( V_56 ) ;
return V_118 ;
}
int F_124 ( struct V_122 * V_123 , struct V_63 * V_63 )
{
int V_114 ;
T_3 V_19 ;
T_7 V_212 ;
struct V_16 * V_115 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_63 ) ;
V_115 = F_54 ( V_123 ) ;
if ( F_55 ( V_115 ) )
return F_62 ( V_115 ) ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_114 & V_89 ) )
goto V_156;
F_129 ( & V_63 -> V_213 ) ;
V_212 = V_63 -> V_212 ;
F_50 ( V_115 , V_63 , V_63 -> V_139 ) ;
if ( V_2 -> V_95 )
V_63 -> V_212 = V_212 ;
F_130 ( & V_63 -> V_213 ) ;
V_156:
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
return 0 ;
}
