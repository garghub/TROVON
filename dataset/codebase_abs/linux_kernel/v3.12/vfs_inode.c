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
F_10 ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_1 , & type , & V_26 , & V_27 ) ;
switch ( type ) {
case 'c' :
V_4 |= V_29 ;
break;
case 'b' :
V_4 |= V_30 ;
break;
default:
F_11 ( V_31 , L_2 ,
type , V_17 -> V_28 ) ;
} ;
* V_19 = F_12 ( V_26 , V_27 ) ;
} else
V_4 |= V_32 ;
return V_4 ;
}
int F_13 ( int V_33 , int V_34 )
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
if ( V_34 ) {
if ( V_33 & V_42 )
V_35 |= V_43 ;
if ( V_33 & V_44 )
V_35 |= V_45 ;
}
return V_35 ;
}
void
F_14 ( struct V_16 * V_46 )
{
V_46 -> type = ~ 0 ;
V_46 -> V_47 = ~ 0 ;
V_46 -> V_48 . type = ~ 0 ;
V_46 -> V_48 . V_49 = ~ 0 ;
* ( ( long long * ) & V_46 -> V_48 . V_50 ) = ~ 0 ;
V_46 -> V_3 = ~ 0 ;
V_46 -> V_51 = ~ 0 ;
V_46 -> V_52 = ~ 0 ;
V_46 -> V_53 = ~ 0 ;
V_46 -> V_54 = NULL ;
V_46 -> V_55 = NULL ;
V_46 -> V_56 = NULL ;
V_46 -> V_57 = NULL ;
V_46 -> V_58 = V_59 ;
V_46 -> V_60 = V_61 ;
V_46 -> V_62 = V_59 ;
V_46 -> V_28 = NULL ;
}
struct V_63 * F_15 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
V_67 = (struct V_66 * ) F_16 ( V_68 ,
V_69 ) ;
if ( ! V_67 )
return NULL ;
#ifdef F_17
V_67 -> V_70 = NULL ;
F_18 ( & V_67 -> V_71 ) ;
#endif
V_67 -> V_72 = NULL ;
V_67 -> V_73 = 0 ;
F_19 ( & V_67 -> V_74 ) ;
return & V_67 -> V_75 ;
}
static void F_20 ( struct V_76 * V_77 )
{
struct V_63 * V_63 = F_21 ( V_77 , struct V_63 , V_78 ) ;
F_22 ( V_68 , F_23 ( V_63 ) ) ;
}
void F_24 ( struct V_63 * V_63 )
{
F_25 ( & V_63 -> V_78 , F_20 ) ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_63 * V_63 , T_2 V_3 , T_3 V_19 )
{
int V_79 = 0 ;
F_27 ( V_63 , NULL , V_3 ) ;
V_63 -> V_80 = 0 ;
V_63 -> V_81 = V_19 ;
V_63 -> V_82 = V_63 -> V_83 = V_63 -> V_84 = V_85 ;
V_63 -> V_86 -> V_87 = & V_88 ;
switch ( V_3 & V_89 ) {
case V_24 :
case V_30 :
case V_29 :
case V_23 :
if ( F_28 ( V_2 ) ) {
V_63 -> V_90 = & V_91 ;
} else if ( F_3 ( V_2 ) ) {
V_63 -> V_90 = & V_92 ;
} else {
F_11 ( V_31 ,
L_3 ) ;
V_79 = - V_93 ;
goto error;
}
F_29 ( V_63 , V_63 -> V_94 , V_63 -> V_81 ) ;
break;
case V_32 :
if ( F_28 ( V_2 ) ) {
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
if ( ! F_3 ( V_2 ) && ! F_28 ( V_2 ) ) {
F_11 ( V_31 ,
L_4 ) ;
V_79 = - V_93 ;
goto error;
}
if ( F_28 ( V_2 ) )
V_63 -> V_90 = & V_101 ;
else
V_63 -> V_90 = & V_102 ;
break;
case V_20 :
F_30 ( V_63 ) ;
if ( F_28 ( V_2 ) )
V_63 -> V_90 = & V_103 ;
else if ( F_3 ( V_2 ) )
V_63 -> V_90 = & V_104 ;
else
V_63 -> V_90 = & V_105 ;
if ( F_28 ( V_2 ) )
V_63 -> V_96 = & V_106 ;
else
V_63 -> V_96 = & V_107 ;
break;
default:
F_11 ( V_31 , L_5 ,
V_3 , V_3 & V_89 ) ;
V_79 = - V_93 ;
goto error;
}
error:
return V_79 ;
}
struct V_63 * F_31 ( struct V_64 * V_65 , T_2 V_3 , T_3 V_19 )
{
int V_79 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_108 ;
F_11 ( V_109 , L_6 , V_65 , V_3 ) ;
V_63 = F_32 ( V_65 ) ;
if ( ! V_63 ) {
F_33 ( L_7 ,
V_110 , F_34 ( V_111 ) ) ;
return F_35 ( - V_112 ) ;
}
V_79 = F_26 ( V_2 , V_63 , V_3 , V_19 ) ;
if ( V_79 ) {
F_36 ( V_63 ) ;
return F_35 ( V_79 ) ;
}
return V_63 ;
}
void F_37 ( struct V_63 * V_63 )
{
struct V_66 * V_67 = F_23 ( V_63 ) ;
F_38 ( V_63 -> V_86 , 0 ) ;
F_39 ( V_63 ) ;
F_40 ( V_63 -> V_86 ) ;
#ifdef F_17
F_41 ( V_63 ) ;
#endif
if ( V_67 -> V_72 ) {
F_42 ( V_67 -> V_72 ) ;
V_67 -> V_72 = NULL ;
}
}
static int F_43 ( struct V_63 * V_63 , void * V_113 )
{
int V_114 ;
T_3 V_19 ;
struct V_66 * V_67 = F_23 ( V_63 ) ;
struct V_16 * V_115 = (struct V_16 * ) V_113 ;
struct V_1 * V_2 = F_44 ( V_63 ) ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_114 & V_89 ) )
return 0 ;
if ( memcmp ( & V_67 -> V_48 . V_49 ,
& V_115 -> V_48 . V_49 , sizeof( V_67 -> V_48 . V_49 ) ) )
return 0 ;
if ( V_67 -> V_48 . type != V_115 -> V_48 . type )
return 0 ;
return 1 ;
}
static int F_45 ( struct V_63 * V_63 , void * V_113 )
{
return 0 ;
}
static int F_46 ( struct V_63 * V_63 , void * V_113 )
{
struct V_66 * V_67 = F_23 ( V_63 ) ;
struct V_16 * V_115 = (struct V_16 * ) V_113 ;
memcpy ( & V_67 -> V_48 , & V_115 -> V_48 , sizeof( V_115 -> V_48 ) ) ;
return 0 ;
}
static struct V_63 * F_47 ( struct V_64 * V_65 ,
struct V_116 * V_48 ,
struct V_16 * V_115 ,
int V_117 )
{
T_3 V_19 ;
int V_118 ;
T_2 V_114 ;
unsigned long V_119 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_108 ;
int (* F_48)( struct V_63 * , void * );
if ( V_117 )
F_48 = F_45 ;
else
F_48 = F_43 ;
V_119 = F_49 ( V_48 ) ;
V_63 = F_50 ( V_65 , V_119 , F_48 , F_46 , V_115 ) ;
if ( ! V_63 )
return F_35 ( - V_112 ) ;
if ( ! ( V_63 -> V_120 & V_121 ) )
return V_63 ;
V_63 -> V_119 = V_119 ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
V_118 = F_26 ( V_2 , V_63 , V_114 , V_19 ) ;
if ( V_118 )
goto error;
F_51 ( V_115 , V_63 , V_65 ) ;
#ifdef F_17
F_52 ( V_63 ) ;
#endif
F_53 ( V_63 ) ;
return V_63 ;
error:
F_53 ( V_63 ) ;
F_36 ( V_63 ) ;
return F_35 ( V_118 ) ;
}
struct V_63 *
F_54 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_64 * V_65 , int V_117 )
{
struct V_16 * V_115 ;
struct V_63 * V_63 = NULL ;
V_115 = F_55 ( V_123 ) ;
if ( F_56 ( V_115 ) )
return F_57 ( V_115 ) ;
V_63 = F_47 ( V_65 , & V_115 -> V_48 , V_115 , V_117 ) ;
F_58 ( V_115 ) ;
F_59 ( V_115 ) ;
return V_63 ;
}
static int F_60 ( int V_124 )
{
int V_125 = 0 ;
if ( V_124 & V_126 )
V_125 |= V_127 ;
return V_125 ;
}
static int F_61 ( struct V_63 * V_128 , struct V_129 * V_129 , int V_124 )
{
struct V_63 * V_63 ;
int V_118 = - V_130 ;
struct V_122 * V_131 , * V_132 ;
struct V_1 * V_2 ;
F_11 ( V_109 , L_8 ,
V_128 , V_129 , V_124 ) ;
V_2 = F_44 ( V_128 ) ;
V_63 = V_129 -> V_133 ;
V_132 = F_62 ( V_129 -> V_134 ) ;
if ( F_56 ( V_132 ) ) {
V_118 = F_63 ( V_132 ) ;
F_11 ( V_109 , L_9 , V_118 ) ;
return V_118 ;
}
if ( F_28 ( V_2 ) )
V_118 = F_64 ( V_132 , V_129 -> V_135 . V_54 ,
F_60 ( V_124 ) ) ;
if ( V_118 == - V_130 ) {
V_131 = F_65 ( V_129 ) ;
if ( F_56 ( V_131 ) )
return F_63 ( V_131 ) ;
V_118 = F_66 ( V_131 ) ;
}
if ( ! V_118 ) {
if ( V_124 & V_126 ) {
F_67 ( V_63 ) ;
F_68 ( V_128 ) ;
} else
F_68 ( V_63 ) ;
F_69 ( V_63 ) ;
F_69 ( V_128 ) ;
}
return V_118 ;
}
static struct V_122 *
F_70 ( struct V_1 * V_2 , struct V_63 * V_128 ,
struct V_129 * V_129 , char * V_28 , T_1 V_136 , T_4 V_3 )
{
int V_79 ;
char * V_54 ;
struct V_122 * V_132 , * V_137 , * V_123 ;
struct V_63 * V_63 ;
F_11 ( V_109 , L_10 , V_129 -> V_135 . V_54 ) ;
V_79 = 0 ;
V_137 = NULL ;
V_123 = NULL ;
V_54 = ( char * ) V_129 -> V_135 . V_54 ;
V_132 = F_62 ( V_129 -> V_134 ) ;
if ( F_56 ( V_132 ) ) {
V_79 = F_63 ( V_132 ) ;
F_11 ( V_109 , L_9 , V_79 ) ;
return F_35 ( V_79 ) ;
}
V_137 = F_71 ( V_132 , 0 , NULL , 1 ) ;
if ( F_56 ( V_137 ) ) {
V_79 = F_63 ( V_137 ) ;
F_11 ( V_109 , L_11 , V_79 ) ;
return F_35 ( V_79 ) ;
}
V_79 = F_72 ( V_137 , V_54 , V_136 , V_3 , V_28 ) ;
if ( V_79 < 0 ) {
F_11 ( V_109 , L_12 , V_79 ) ;
goto error;
}
if ( ! ( V_136 & V_138 ) ) {
V_123 = F_71 ( V_132 , 1 , & V_54 , 1 ) ;
if ( F_56 ( V_123 ) ) {
V_79 = F_63 ( V_123 ) ;
F_11 ( V_109 ,
L_11 , V_79 ) ;
V_123 = NULL ;
goto error;
}
V_63 = F_73 ( V_2 , V_123 , V_128 -> V_139 ) ;
if ( F_56 ( V_63 ) ) {
V_79 = F_63 ( V_63 ) ;
F_11 ( V_109 ,
L_13 , V_79 ) ;
goto error;
}
F_74 ( V_129 , V_123 ) ;
F_75 ( V_129 , V_63 ) ;
}
return V_137 ;
error:
if ( V_137 )
F_42 ( V_137 ) ;
if ( V_123 )
F_42 ( V_123 ) ;
return F_35 ( V_79 ) ;
}
static int
F_76 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 ,
bool V_140 )
{
struct V_1 * V_2 = F_44 ( V_128 ) ;
T_1 V_136 = F_1 ( V_2 , V_3 ) ;
struct V_122 * V_123 ;
V_123 = F_70 ( V_2 , V_128 , V_129 , NULL , V_136 , V_41 ) ;
if ( F_56 ( V_123 ) )
return F_63 ( V_123 ) ;
F_69 ( V_128 ) ;
F_42 ( V_123 ) ;
return 0 ;
}
static int F_77 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 )
{
int V_79 ;
T_1 V_136 ;
struct V_122 * V_123 ;
struct V_1 * V_2 ;
F_11 ( V_109 , L_10 , V_129 -> V_135 . V_54 ) ;
V_79 = 0 ;
V_2 = F_44 ( V_128 ) ;
V_136 = F_1 ( V_2 , V_3 | V_20 ) ;
V_123 = F_70 ( V_2 , V_128 , V_129 , NULL , V_136 , V_37 ) ;
if ( F_56 ( V_123 ) ) {
V_79 = F_63 ( V_123 ) ;
V_123 = NULL ;
} else {
F_30 ( V_128 ) ;
F_69 ( V_128 ) ;
}
if ( V_123 )
F_42 ( V_123 ) ;
return V_79 ;
}
struct V_129 * F_78 ( struct V_63 * V_128 , struct V_129 * V_129 ,
unsigned int V_124 )
{
struct V_129 * V_4 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
struct V_122 * V_132 , * V_123 ;
struct V_63 * V_63 ;
char * V_54 ;
F_11 ( V_109 , L_14 ,
V_128 , V_129 -> V_135 . V_54 , V_129 , V_124 ) ;
if ( V_129 -> V_135 . V_141 > V_142 )
return F_35 ( - V_143 ) ;
V_65 = V_128 -> V_139 ;
V_2 = F_44 ( V_128 ) ;
V_132 = F_62 ( V_129 -> V_134 ) ;
if ( F_56 ( V_132 ) )
return F_57 ( V_132 ) ;
V_54 = ( char * ) V_129 -> V_135 . V_54 ;
V_123 = F_71 ( V_132 , 1 , & V_54 , 1 ) ;
if ( F_56 ( V_123 ) ) {
if ( V_123 == F_35 ( - V_144 ) ) {
F_79 ( V_129 , NULL ) ;
return NULL ;
}
return F_57 ( V_123 ) ;
}
if ( V_2 -> V_95 )
V_63 = F_80 ( V_2 , V_123 , V_128 -> V_139 ) ;
else
V_63 = F_73 ( V_2 , V_123 , V_128 -> V_139 ) ;
if ( F_56 ( V_63 ) ) {
F_42 ( V_123 ) ;
return F_57 ( V_63 ) ;
}
V_4 = F_81 ( V_129 , V_63 ) ;
if ( ! V_4 )
F_74 ( V_129 , V_123 ) ;
else if ( ! F_56 ( V_4 ) )
F_74 ( V_4 , V_123 ) ;
else
F_42 ( V_123 ) ;
return V_4 ;
}
static int
F_82 ( struct V_63 * V_128 , struct V_129 * V_129 ,
struct V_145 * V_145 , unsigned V_124 , T_2 V_3 ,
int * V_146 )
{
int V_79 ;
T_1 V_136 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_122 * V_123 , * V_147 ;
struct V_129 * V_4 = NULL ;
if ( F_83 ( V_129 ) ) {
V_4 = F_78 ( V_128 , V_129 , 0 ) ;
if ( F_56 ( V_4 ) )
return F_63 ( V_4 ) ;
if ( V_4 )
V_129 = V_4 ;
}
if ( ! ( V_124 & V_148 ) || V_129 -> V_133 )
return F_84 ( V_145 , V_4 ) ;
V_79 = 0 ;
V_123 = NULL ;
V_2 = F_44 ( V_128 ) ;
V_136 = F_1 ( V_2 , V_3 ) ;
V_123 = F_70 ( V_2 , V_128 , V_129 , NULL , V_136 ,
F_13 ( V_124 ,
F_3 ( V_2 ) ) ) ;
if ( F_56 ( V_123 ) ) {
V_79 = F_63 ( V_123 ) ;
V_123 = NULL ;
goto error;
}
F_69 ( V_128 ) ;
V_67 = F_23 ( V_129 -> V_133 ) ;
F_85 ( & V_67 -> V_74 ) ;
if ( V_2 -> V_95 && ! V_67 -> V_72 &&
( ( V_124 & V_149 ) != V_36 ) ) {
V_147 = F_86 ( V_129 ) ;
if ( F_56 ( V_147 ) ) {
V_79 = F_63 ( V_147 ) ;
F_87 ( & V_67 -> V_74 ) ;
goto error;
}
V_67 -> V_72 = ( void * ) V_147 ;
}
F_87 ( & V_67 -> V_74 ) ;
V_79 = F_88 ( V_145 , V_129 , V_150 , V_146 ) ;
if ( V_79 )
goto error;
V_145 -> V_151 = V_123 ;
#ifdef F_17
if ( V_2 -> V_95 )
F_89 ( V_129 -> V_133 , V_145 ) ;
#endif
* V_146 |= V_152 ;
V_153:
F_90 ( V_4 ) ;
return V_79 ;
error:
if ( V_123 )
F_42 ( V_123 ) ;
goto V_153;
}
int F_91 ( struct V_63 * V_154 , struct V_129 * V_155 )
{
return F_61 ( V_154 , V_155 , 0 ) ;
}
int F_92 ( struct V_63 * V_154 , struct V_129 * V_155 )
{
return F_61 ( V_154 , V_155 , V_126 ) ;
}
int
F_93 ( struct V_63 * V_156 , struct V_129 * V_157 ,
struct V_63 * V_158 , struct V_129 * V_159 )
{
int V_118 ;
struct V_63 * V_160 ;
struct V_63 * F_32 ;
struct V_1 * V_2 ;
struct V_122 * V_161 ;
struct V_122 * V_162 ;
struct V_122 * V_163 ;
struct V_16 V_46 ;
F_11 ( V_109 , L_15 ) ;
V_118 = 0 ;
V_160 = V_157 -> V_133 ;
F_32 = V_159 -> V_133 ;
V_2 = F_44 ( V_160 ) ;
V_161 = F_62 ( V_157 ) ;
if ( F_56 ( V_161 ) )
return F_63 ( V_161 ) ;
V_162 = F_65 ( V_157 -> V_134 ) ;
if ( F_56 ( V_162 ) ) {
V_118 = F_63 ( V_162 ) ;
goto V_164;
}
V_163 = F_65 ( V_159 -> V_134 ) ;
if ( F_56 ( V_163 ) ) {
V_118 = F_63 ( V_163 ) ;
goto V_165;
}
F_94 ( & V_2 -> V_166 ) ;
if ( F_28 ( V_2 ) ) {
V_118 = F_95 ( V_162 , V_157 -> V_135 . V_54 ,
V_163 , V_159 -> V_135 . V_54 ) ;
if ( V_118 == - V_130 )
V_118 = F_96 ( V_161 , V_163 ,
V_159 -> V_135 . V_54 ) ;
if ( V_118 != - V_130 )
goto V_167;
}
if ( V_157 -> V_134 != V_159 -> V_134 ) {
F_11 ( V_31 , L_16 ) ;
V_118 = - V_168 ;
goto V_167;
}
F_14 ( & V_46 ) ;
V_46 . V_57 = V_2 -> V_169 ;
V_46 . V_54 = ( char * ) V_159 -> V_135 . V_54 ;
V_118 = F_97 ( V_161 , & V_46 ) ;
V_167:
if ( ! V_118 ) {
if ( F_32 ) {
if ( F_2 ( F_32 -> V_94 ) )
F_67 ( F_32 ) ;
else
F_68 ( F_32 ) ;
}
if ( F_2 ( V_160 -> V_94 ) ) {
if ( ! F_32 )
F_30 ( V_158 ) ;
F_68 ( V_156 ) ;
}
F_69 ( V_160 ) ;
F_69 ( V_156 ) ;
F_69 ( V_158 ) ;
F_98 ( V_157 , V_159 ) ;
}
F_99 ( & V_2 -> V_166 ) ;
F_42 ( V_163 ) ;
V_165:
F_42 ( V_162 ) ;
V_164:
return V_118 ;
}
static int
F_100 ( struct V_170 * V_171 , struct V_129 * V_129 ,
struct V_172 * V_17 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 * V_115 ;
F_11 ( V_109 , L_17 , V_129 ) ;
V_2 = F_101 ( V_129 ) ;
if ( V_2 -> V_95 == V_173 || V_2 -> V_95 == V_174 ) {
F_102 ( V_129 -> V_133 , V_17 ) ;
return 0 ;
}
V_123 = F_62 ( V_129 ) ;
if ( F_56 ( V_123 ) )
return F_63 ( V_123 ) ;
V_115 = F_55 ( V_123 ) ;
if ( F_56 ( V_115 ) )
return F_63 ( V_115 ) ;
F_51 ( V_115 , V_129 -> V_133 , V_129 -> V_133 -> V_139 ) ;
F_102 ( V_129 -> V_133 , V_17 ) ;
F_58 ( V_115 ) ;
F_59 ( V_115 ) ;
return 0 ;
}
static int F_103 ( struct V_129 * V_129 , struct V_175 * V_175 )
{
int V_118 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 V_46 ;
F_11 ( V_109 , L_15 ) ;
V_118 = F_104 ( V_129 -> V_133 , V_175 ) ;
if ( V_118 )
return V_118 ;
V_118 = - V_176 ;
V_2 = F_101 ( V_129 ) ;
V_123 = F_62 ( V_129 ) ;
if( F_56 ( V_123 ) )
return F_63 ( V_123 ) ;
F_14 ( & V_46 ) ;
if ( V_175 -> V_177 & V_178 )
V_46 . V_3 = F_1 ( V_2 , V_175 -> V_179 ) ;
if ( V_175 -> V_177 & V_180 )
V_46 . V_52 = V_175 -> V_181 . V_182 ;
if ( V_175 -> V_177 & V_183 )
V_46 . V_51 = V_175 -> V_184 . V_182 ;
if ( V_175 -> V_177 & V_185 )
V_46 . V_53 = V_175 -> V_186 ;
if ( F_3 ( V_2 ) ) {
if ( V_175 -> V_177 & V_187 )
V_46 . V_58 = V_175 -> V_188 ;
if ( V_175 -> V_177 & V_189 )
V_46 . V_60 = V_175 -> V_190 ;
}
if ( F_105 ( V_129 -> V_133 -> V_94 ) )
F_106 ( V_129 -> V_133 -> V_86 ) ;
V_118 = F_97 ( V_123 , & V_46 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ( V_175 -> V_177 & V_185 ) &&
V_175 -> V_186 != F_107 ( V_129 -> V_133 ) )
F_108 ( V_129 -> V_133 , V_175 -> V_186 ) ;
F_69 ( V_129 -> V_133 ) ;
F_109 ( V_129 -> V_133 , V_175 ) ;
F_110 ( V_129 -> V_133 ) ;
return 0 ;
}
void
F_51 ( struct V_16 * V_17 , struct V_63 * V_63 ,
struct V_64 * V_65 )
{
T_2 V_3 ;
char V_25 [ 32 ] ;
char V_191 [ 14 ] ;
unsigned int V_192 ;
struct V_1 * V_2 = V_65 -> V_108 ;
struct V_66 * V_67 = F_23 ( V_63 ) ;
F_111 ( V_63 , 1 ) ;
V_63 -> V_82 . V_182 = V_17 -> V_51 ;
V_63 -> V_83 . V_182 = V_17 -> V_52 ;
V_63 -> V_84 . V_182 = V_17 -> V_52 ;
V_63 -> V_193 = V_2 -> V_194 ;
V_63 -> V_195 = V_2 -> V_196 ;
if ( F_3 ( V_2 ) ) {
V_63 -> V_193 = V_17 -> V_58 ;
V_63 -> V_195 = V_17 -> V_60 ;
}
if ( ( F_105 ( V_63 -> V_94 ) ) || ( F_2 ( V_63 -> V_94 ) ) ) {
if ( F_3 ( V_2 ) && ( V_17 -> V_28 [ 0 ] != '\0' ) ) {
F_10 ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_18 , V_191 , & V_192 ) ;
if ( ! strncmp ( V_191 , L_19 , 13 ) )
F_111 ( V_63 , V_192 ) ;
}
}
V_3 = F_8 ( V_2 , V_17 ) ;
V_3 |= V_63 -> V_94 & ~ V_18 ;
V_63 -> V_94 = V_3 ;
F_112 ( V_63 , V_17 -> V_53 ) ;
V_63 -> V_80 = ( F_107 ( V_63 ) + 512 - 1 ) >> 9 ;
V_67 -> V_73 &= ~ V_197 ;
}
T_5 F_49 ( struct V_116 * V_48 )
{
T_6 V_50 = V_48 -> V_50 + 2 ;
T_5 V_154 = 0 ;
if ( sizeof( T_5 ) == sizeof( V_50 ) )
memcpy ( & V_154 , & V_50 , sizeof( T_5 ) ) ;
else
V_154 = ( T_5 ) ( V_50 ^ ( V_50 >> 32 ) ) ;
return V_154 ;
}
static int F_113 ( struct V_129 * V_129 , char * V_198 , int V_199 )
{
int V_118 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_16 * V_115 ;
F_11 ( V_109 , L_20 , V_129 -> V_135 . V_54 ) ;
V_118 = - V_176 ;
V_2 = F_101 ( V_129 ) ;
V_123 = F_62 ( V_129 ) ;
if ( F_56 ( V_123 ) )
return F_63 ( V_123 ) ;
if ( ! F_3 ( V_2 ) )
return - V_200 ;
V_115 = F_55 ( V_123 ) ;
if ( F_56 ( V_115 ) )
return F_63 ( V_115 ) ;
if ( ! ( V_115 -> V_3 & V_21 ) ) {
V_118 = - V_93 ;
goto V_164;
}
V_118 = F_114 ( strlen ( V_115 -> V_28 ) + 1 , ( V_201 ) V_199 ) ;
memcpy ( V_198 , V_115 -> V_28 , V_118 ) ;
F_11 ( V_109 , L_21 ,
V_129 -> V_135 . V_54 , V_115 -> V_28 , V_199 , V_198 ) ;
V_164:
F_58 ( V_115 ) ;
F_59 ( V_115 ) ;
return V_118 ;
}
static void * F_115 ( struct V_129 * V_129 , struct V_202 * V_203 )
{
int V_141 = 0 ;
char * V_204 = F_116 () ;
F_11 ( V_109 , L_22 , V_129 -> V_135 . V_54 ) ;
if ( ! V_204 )
V_204 = F_35 ( - V_112 ) ;
else {
V_141 = F_113 ( V_129 , V_204 , V_205 ) ;
if ( V_141 < 0 ) {
F_117 ( V_204 ) ;
V_204 = F_35 ( V_141 ) ;
} else
V_204 [ F_114 ( V_141 , V_205 - 1 ) ] = 0 ;
}
F_118 ( V_203 , V_204 ) ;
return NULL ;
}
void
F_119 ( struct V_129 * V_129 , struct V_202 * V_203 , void * V_206 )
{
char * V_207 = F_120 ( V_203 ) ;
F_11 ( V_109 , L_23 ,
V_129 -> V_135 . V_54 , F_56 ( V_207 ) ? L_24 : V_207 ) ;
if ( ! F_56 ( V_207 ) )
F_117 ( V_207 ) ;
}
static int F_121 ( struct V_63 * V_128 , struct V_129 * V_129 ,
T_1 V_136 , const char * V_28 )
{
struct V_122 * V_123 ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_128 ) ;
if ( ! F_3 ( V_2 ) ) {
F_11 ( V_31 , L_25 ) ;
return - V_176 ;
}
V_123 = F_70 ( V_2 , V_128 , V_129 , ( char * ) V_28 , V_136 ,
V_37 ) ;
if ( F_56 ( V_123 ) )
return F_63 ( V_123 ) ;
F_69 ( V_128 ) ;
F_42 ( V_123 ) ;
return 0 ;
}
static int
F_122 ( struct V_63 * V_128 , struct V_129 * V_129 , const char * V_208 )
{
F_11 ( V_109 , L_26 ,
V_128 -> V_119 , V_129 -> V_135 . V_54 , V_208 ) ;
return F_121 ( V_128 , V_129 , V_21 , V_208 ) ;
}
static int
F_123 ( struct V_129 * V_157 , struct V_63 * V_128 ,
struct V_129 * V_129 )
{
int V_118 ;
char * V_54 ;
struct V_122 * V_161 ;
F_11 ( V_109 , L_26 ,
V_128 -> V_119 , V_129 -> V_135 . V_54 , V_157 -> V_135 . V_54 ) ;
V_161 = F_65 ( V_157 ) ;
if ( F_56 ( V_161 ) )
return F_63 ( V_161 ) ;
V_54 = F_116 () ;
if ( F_124 ( ! V_54 ) ) {
V_118 = - V_112 ;
goto V_209;
}
sprintf ( V_54 , L_27 , V_161 -> V_123 ) ;
V_118 = F_121 ( V_128 , V_129 , V_138 , V_54 ) ;
F_117 ( V_54 ) ;
if ( ! V_118 ) {
F_125 ( V_161 , V_157 -> V_133 ) ;
F_69 ( V_128 ) ;
}
V_209:
F_42 ( V_161 ) ;
return V_118 ;
}
static int
F_126 ( struct V_63 * V_128 , struct V_129 * V_129 , T_2 V_3 , T_3 V_19 )
{
struct V_1 * V_2 = F_44 ( V_128 ) ;
int V_118 ;
char * V_54 ;
T_1 V_136 ;
F_11 ( V_109 , L_28 ,
V_128 -> V_119 , V_129 -> V_135 . V_54 , V_3 ,
F_127 ( V_19 ) , F_128 ( V_19 ) ) ;
if ( ! F_129 ( V_19 ) )
return - V_93 ;
V_54 = F_116 () ;
if ( ! V_54 )
return - V_112 ;
if ( F_6 ( V_3 ) )
sprintf ( V_54 , L_29 , F_127 ( V_19 ) , F_128 ( V_19 ) ) ;
else if ( F_7 ( V_3 ) )
sprintf ( V_54 , L_30 , F_127 ( V_19 ) , F_128 ( V_19 ) ) ;
else if ( F_5 ( V_3 ) )
* V_54 = 0 ;
else if ( F_4 ( V_3 ) )
* V_54 = 0 ;
else {
F_117 ( V_54 ) ;
return - V_93 ;
}
V_136 = F_1 ( V_2 , V_3 ) ;
V_118 = F_121 ( V_128 , V_129 , V_136 , V_54 ) ;
F_117 ( V_54 ) ;
return V_118 ;
}
int F_125 ( struct V_122 * V_123 , struct V_63 * V_63 )
{
int V_114 ;
T_3 V_19 ;
T_7 V_210 ;
struct V_16 * V_115 ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_63 ) ;
V_115 = F_55 ( V_123 ) ;
if ( F_56 ( V_115 ) )
return F_63 ( V_115 ) ;
V_114 = F_9 ( V_2 , V_115 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_114 & V_89 ) )
goto V_153;
F_130 ( & V_63 -> V_211 ) ;
V_210 = V_63 -> V_210 ;
F_51 ( V_115 , V_63 , V_63 -> V_139 ) ;
if ( V_2 -> V_95 )
V_63 -> V_210 = V_210 ;
F_131 ( & V_63 -> V_211 ) ;
V_153:
F_58 ( V_115 ) ;
F_59 ( V_115 ) ;
return 0 ;
}
