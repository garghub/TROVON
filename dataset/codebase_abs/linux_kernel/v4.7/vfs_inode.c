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
F_11 ( V_31 ,
L_3 ) ;
V_79 = - V_93 ;
goto error;
}
F_28 ( V_63 , V_63 -> V_94 , V_63 -> V_81 ) ;
break;
case V_32 :
if ( F_27 ( V_2 ) ) {
V_63 -> V_90 = & V_91 ;
if ( V_2 -> V_95 == V_96 ||
V_2 -> V_95 == V_97 )
V_63 -> V_98 =
& V_99 ;
else if ( V_2 -> V_95 == V_100 )
V_63 -> V_98 = & V_101 ;
else
V_63 -> V_98 = & V_102 ;
} else {
V_63 -> V_90 = & V_92 ;
if ( V_2 -> V_95 == V_96 ||
V_2 -> V_95 == V_97 )
V_63 -> V_98 =
& V_103 ;
else if ( V_2 -> V_95 == V_100 )
V_63 -> V_98 = & V_104 ;
else
V_63 -> V_98 = & V_105 ;
}
break;
case V_22 :
if ( ! F_3 ( V_2 ) && ! F_27 ( V_2 ) ) {
F_11 ( V_31 ,
L_4 ) ;
V_79 = - V_93 ;
goto error;
}
if ( F_27 ( V_2 ) )
V_63 -> V_90 = & V_106 ;
else
V_63 -> V_90 = & V_107 ;
break;
case V_20 :
F_29 ( V_63 ) ;
if ( F_27 ( V_2 ) )
V_63 -> V_90 = & V_108 ;
else if ( F_3 ( V_2 ) )
V_63 -> V_90 = & V_109 ;
else
V_63 -> V_90 = & V_110 ;
if ( F_27 ( V_2 ) )
V_63 -> V_98 = & V_111 ;
else
V_63 -> V_98 = & V_112 ;
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
struct V_63 * F_30 ( struct V_64 * V_65 , T_2 V_3 , T_3 V_19 )
{
int V_79 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_113 ;
F_11 ( V_114 , L_6 , V_65 , V_3 ) ;
V_63 = F_31 ( V_65 ) ;
if ( ! V_63 ) {
F_32 ( L_7 ,
V_115 , F_33 ( V_116 ) ) ;
return F_34 ( - V_117 ) ;
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
F_37 ( & V_63 -> V_118 ) ;
F_38 ( V_63 ) ;
F_39 ( & V_63 -> V_118 ) ;
F_40 ( V_63 ) ;
if ( V_67 -> V_72 ) {
F_41 ( V_67 -> V_72 ) ;
V_67 -> V_72 = NULL ;
}
}
static int F_42 ( struct V_63 * V_63 , void * V_119 )
{
int V_120 ;
T_3 V_19 ;
struct V_66 * V_67 = F_22 ( V_63 ) ;
struct V_16 * V_121 = (struct V_16 * ) V_119 ;
struct V_1 * V_2 = F_43 ( V_63 ) ;
V_120 = F_9 ( V_2 , V_121 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_120 & V_89 ) )
return 0 ;
if ( memcmp ( & V_67 -> V_48 . V_49 ,
& V_121 -> V_48 . V_49 , sizeof( V_67 -> V_48 . V_49 ) ) )
return 0 ;
if ( V_67 -> V_48 . type != V_121 -> V_48 . type )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_63 * V_63 , void * V_119 )
{
return 0 ;
}
static int F_45 ( struct V_63 * V_63 , void * V_119 )
{
struct V_66 * V_67 = F_22 ( V_63 ) ;
struct V_16 * V_121 = (struct V_16 * ) V_119 ;
memcpy ( & V_67 -> V_48 , & V_121 -> V_48 , sizeof( V_121 -> V_48 ) ) ;
return 0 ;
}
static struct V_63 * F_46 ( struct V_64 * V_65 ,
struct V_122 * V_48 ,
struct V_16 * V_121 ,
int V_123 )
{
T_3 V_19 ;
int V_124 ;
T_2 V_120 ;
unsigned long V_125 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_113 ;
int (* F_47)( struct V_63 * , void * );
if ( V_123 )
F_47 = F_44 ;
else
F_47 = F_42 ;
V_125 = F_48 ( V_48 ) ;
V_63 = F_49 ( V_65 , V_125 , F_47 , F_45 , V_121 ) ;
if ( ! V_63 )
return F_34 ( - V_117 ) ;
if ( ! ( V_63 -> V_126 & V_127 ) )
return V_63 ;
V_63 -> V_125 = V_125 ;
V_120 = F_9 ( V_2 , V_121 , & V_19 ) ;
V_124 = F_25 ( V_2 , V_63 , V_120 , V_19 ) ;
if ( V_124 )
goto error;
F_50 ( V_121 , V_63 , V_65 ) ;
F_51 ( V_63 ) ;
F_52 ( V_63 ) ;
return V_63 ;
error:
F_53 ( V_63 ) ;
return F_34 ( V_124 ) ;
}
struct V_63 *
F_54 ( struct V_1 * V_2 , struct V_128 * V_129 ,
struct V_64 * V_65 , int V_123 )
{
struct V_16 * V_121 ;
struct V_63 * V_63 = NULL ;
V_121 = F_55 ( V_129 ) ;
if ( F_56 ( V_121 ) )
return F_57 ( V_121 ) ;
V_63 = F_46 ( V_65 , & V_121 -> V_48 , V_121 , V_123 ) ;
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
return V_63 ;
}
static int F_60 ( int V_130 )
{
int V_131 = 0 ;
if ( V_130 & V_132 )
V_131 |= V_133 ;
return V_131 ;
}
static int F_61 ( struct V_63 * V_134 , struct V_135 * V_135 , int V_130 )
{
struct V_63 * V_63 ;
int V_124 = - V_136 ;
struct V_128 * V_137 , * V_138 ;
struct V_1 * V_2 ;
F_11 ( V_114 , L_8 ,
V_134 , V_135 , V_130 ) ;
V_2 = F_43 ( V_134 ) ;
V_63 = F_62 ( V_135 ) ;
V_138 = F_63 ( V_135 -> V_139 ) ;
if ( F_56 ( V_138 ) ) {
V_124 = F_64 ( V_138 ) ;
F_11 ( V_114 , L_9 , V_124 ) ;
return V_124 ;
}
if ( F_27 ( V_2 ) )
V_124 = F_65 ( V_138 , V_135 -> V_140 . V_54 ,
F_60 ( V_130 ) ) ;
if ( V_124 == - V_136 ) {
V_137 = F_66 ( V_135 ) ;
if ( F_56 ( V_137 ) )
return F_64 ( V_137 ) ;
V_124 = F_67 ( V_137 ) ;
}
if ( ! V_124 ) {
if ( V_130 & V_132 ) {
F_68 ( V_63 ) ;
F_69 ( V_134 ) ;
} else
F_69 ( V_63 ) ;
F_70 ( V_63 ) ;
F_70 ( V_134 ) ;
}
return V_124 ;
}
static struct V_128 *
F_71 ( struct V_1 * V_2 , struct V_63 * V_134 ,
struct V_135 * V_135 , char * V_28 , T_1 V_141 , T_4 V_3 )
{
int V_79 ;
char * V_54 ;
struct V_128 * V_138 , * V_142 , * V_129 ;
struct V_63 * V_63 ;
F_11 ( V_114 , L_10 , V_135 ) ;
V_79 = 0 ;
V_142 = NULL ;
V_129 = NULL ;
V_54 = ( char * ) V_135 -> V_140 . V_54 ;
V_138 = F_63 ( V_135 -> V_139 ) ;
if ( F_56 ( V_138 ) ) {
V_79 = F_64 ( V_138 ) ;
F_11 ( V_114 , L_9 , V_79 ) ;
return F_34 ( V_79 ) ;
}
V_142 = F_72 ( V_138 , 0 , NULL , 1 ) ;
if ( F_56 ( V_142 ) ) {
V_79 = F_64 ( V_142 ) ;
F_11 ( V_114 , L_11 , V_79 ) ;
return F_34 ( V_79 ) ;
}
V_79 = F_73 ( V_142 , V_54 , V_141 , V_3 , V_28 ) ;
if ( V_79 < 0 ) {
F_11 ( V_114 , L_12 , V_79 ) ;
goto error;
}
if ( ! ( V_141 & V_143 ) ) {
V_129 = F_72 ( V_138 , 1 , & V_54 , 1 ) ;
if ( F_56 ( V_129 ) ) {
V_79 = F_64 ( V_129 ) ;
F_11 ( V_114 ,
L_11 , V_79 ) ;
V_129 = NULL ;
goto error;
}
V_63 = F_74 ( V_2 , V_129 , V_134 -> V_144 ) ;
if ( F_56 ( V_63 ) ) {
V_79 = F_64 ( V_63 ) ;
F_11 ( V_114 ,
L_13 , V_79 ) ;
goto error;
}
F_75 ( V_135 , V_129 ) ;
F_76 ( V_135 , V_63 ) ;
}
return V_142 ;
error:
if ( V_142 )
F_41 ( V_142 ) ;
if ( V_129 )
F_41 ( V_129 ) ;
return F_34 ( V_79 ) ;
}
static int
F_77 ( struct V_63 * V_134 , struct V_135 * V_135 , T_2 V_3 ,
bool V_145 )
{
struct V_1 * V_2 = F_43 ( V_134 ) ;
T_1 V_141 = F_1 ( V_2 , V_3 ) ;
struct V_128 * V_129 ;
V_129 = F_71 ( V_2 , V_134 , V_135 , NULL , V_141 , V_41 ) ;
if ( F_56 ( V_129 ) )
return F_64 ( V_129 ) ;
F_70 ( V_134 ) ;
F_41 ( V_129 ) ;
return 0 ;
}
static int F_78 ( struct V_63 * V_134 , struct V_135 * V_135 , T_2 V_3 )
{
int V_79 ;
T_1 V_141 ;
struct V_128 * V_129 ;
struct V_1 * V_2 ;
F_11 ( V_114 , L_10 , V_135 ) ;
V_79 = 0 ;
V_2 = F_43 ( V_134 ) ;
V_141 = F_1 ( V_2 , V_3 | V_20 ) ;
V_129 = F_71 ( V_2 , V_134 , V_135 , NULL , V_141 , V_37 ) ;
if ( F_56 ( V_129 ) ) {
V_79 = F_64 ( V_129 ) ;
V_129 = NULL ;
} else {
F_29 ( V_134 ) ;
F_70 ( V_134 ) ;
}
if ( V_129 )
F_41 ( V_129 ) ;
return V_79 ;
}
struct V_135 * F_79 ( struct V_63 * V_134 , struct V_135 * V_135 ,
unsigned int V_130 )
{
struct V_135 * V_4 ;
struct V_1 * V_2 ;
struct V_128 * V_138 , * V_129 ;
struct V_63 * V_63 ;
char * V_54 ;
F_11 ( V_114 , L_14 ,
V_134 , V_135 , V_135 , V_130 ) ;
if ( V_135 -> V_140 . V_146 > V_147 )
return F_34 ( - V_148 ) ;
V_2 = F_43 ( V_134 ) ;
V_138 = F_63 ( V_135 -> V_139 ) ;
if ( F_56 ( V_138 ) )
return F_57 ( V_138 ) ;
V_54 = ( char * ) V_135 -> V_140 . V_54 ;
V_129 = F_72 ( V_138 , 1 , & V_54 , 1 ) ;
if ( F_56 ( V_129 ) ) {
if ( V_129 == F_34 ( - V_149 ) ) {
F_80 ( V_135 , NULL ) ;
return NULL ;
}
return F_57 ( V_129 ) ;
}
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
V_63 = F_81 ( V_2 , V_129 , V_134 -> V_144 ) ;
else
V_63 = F_74 ( V_2 , V_129 , V_134 -> V_144 ) ;
if ( F_56 ( V_63 ) ) {
F_41 ( V_129 ) ;
return F_57 ( V_63 ) ;
}
V_4 = F_82 ( V_63 , V_135 ) ;
if ( ! V_4 )
F_75 ( V_135 , V_129 ) ;
else if ( ! F_56 ( V_4 ) )
F_75 ( V_4 , V_129 ) ;
else
F_41 ( V_129 ) ;
return V_4 ;
}
static int
F_83 ( struct V_63 * V_134 , struct V_135 * V_135 ,
struct V_150 * V_150 , unsigned V_130 , T_2 V_3 ,
int * V_151 )
{
int V_79 ;
T_1 V_141 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_128 * V_129 , * V_152 ;
struct V_135 * V_4 = NULL ;
if ( F_84 ( V_135 ) ) {
V_4 = F_79 ( V_134 , V_135 , 0 ) ;
if ( F_56 ( V_4 ) )
return F_64 ( V_4 ) ;
if ( V_4 )
V_135 = V_4 ;
}
if ( ! ( V_130 & V_153 ) || F_85 ( V_135 ) )
return F_86 ( V_150 , V_4 ) ;
V_79 = 0 ;
V_2 = F_43 ( V_134 ) ;
V_141 = F_1 ( V_2 , V_3 ) ;
V_129 = F_71 ( V_2 , V_134 , V_135 , NULL , V_141 ,
F_13 ( V_130 ,
F_3 ( V_2 ) ) ) ;
if ( F_56 ( V_129 ) ) {
V_79 = F_64 ( V_129 ) ;
V_129 = NULL ;
goto error;
}
F_70 ( V_134 ) ;
V_67 = F_22 ( F_62 ( V_135 ) ) ;
F_87 ( & V_67 -> V_74 ) ;
if ( ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 ) &&
! V_67 -> V_72 &&
( ( V_130 & V_154 ) != V_36 ) ) {
V_152 = F_88 ( V_135 ) ;
if ( F_56 ( V_152 ) ) {
V_79 = F_64 ( V_152 ) ;
F_89 ( & V_67 -> V_74 ) ;
goto error;
}
V_67 -> V_72 = ( void * ) V_152 ;
}
F_89 ( & V_67 -> V_74 ) ;
V_79 = F_90 ( V_150 , V_135 , V_155 , V_151 ) ;
if ( V_79 )
goto error;
V_150 -> V_156 = V_129 ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
F_91 ( F_62 ( V_135 ) , V_150 ) ;
* V_151 |= V_157 ;
V_158:
F_92 ( V_4 ) ;
return V_79 ;
error:
if ( V_129 )
F_41 ( V_129 ) ;
goto V_158;
}
int F_93 ( struct V_63 * V_159 , struct V_135 * V_160 )
{
return F_61 ( V_159 , V_160 , 0 ) ;
}
int F_94 ( struct V_63 * V_159 , struct V_135 * V_160 )
{
return F_61 ( V_159 , V_160 , V_132 ) ;
}
int
F_95 ( struct V_63 * V_161 , struct V_135 * V_162 ,
struct V_63 * V_163 , struct V_135 * V_164 )
{
int V_124 ;
struct V_63 * V_165 ;
struct V_63 * F_31 ;
struct V_1 * V_2 ;
struct V_128 * V_166 ;
struct V_128 * V_167 ;
struct V_128 * V_168 ;
struct V_16 V_46 ;
F_11 ( V_114 , L_15 ) ;
V_124 = 0 ;
V_165 = F_62 ( V_162 ) ;
F_31 = F_62 ( V_164 ) ;
V_2 = F_43 ( V_165 ) ;
V_166 = F_63 ( V_162 ) ;
if ( F_56 ( V_166 ) )
return F_64 ( V_166 ) ;
V_167 = F_66 ( V_162 -> V_139 ) ;
if ( F_56 ( V_167 ) ) {
V_124 = F_64 ( V_167 ) ;
goto V_169;
}
V_168 = F_66 ( V_164 -> V_139 ) ;
if ( F_56 ( V_168 ) ) {
V_124 = F_64 ( V_168 ) ;
goto V_170;
}
F_96 ( & V_2 -> V_171 ) ;
if ( F_27 ( V_2 ) ) {
V_124 = F_97 ( V_167 , V_162 -> V_140 . V_54 ,
V_168 , V_164 -> V_140 . V_54 ) ;
if ( V_124 == - V_136 )
V_124 = F_98 ( V_166 , V_168 ,
V_164 -> V_140 . V_54 ) ;
if ( V_124 != - V_136 )
goto V_172;
}
if ( V_162 -> V_139 != V_164 -> V_139 ) {
F_11 ( V_31 , L_16 ) ;
V_124 = - V_173 ;
goto V_172;
}
F_14 ( & V_46 ) ;
V_46 . V_57 = V_2 -> V_174 ;
V_46 . V_54 = ( char * ) V_164 -> V_140 . V_54 ;
V_124 = F_99 ( V_166 , & V_46 ) ;
V_172:
if ( ! V_124 ) {
if ( F_31 ) {
if ( F_2 ( F_31 -> V_94 ) )
F_68 ( F_31 ) ;
else
F_69 ( F_31 ) ;
}
if ( F_2 ( V_165 -> V_94 ) ) {
if ( ! F_31 )
F_29 ( V_163 ) ;
F_69 ( V_161 ) ;
}
F_70 ( V_165 ) ;
F_70 ( V_161 ) ;
F_70 ( V_163 ) ;
F_100 ( V_162 , V_164 ) ;
}
F_101 ( & V_2 -> V_171 ) ;
F_41 ( V_168 ) ;
V_170:
F_41 ( V_167 ) ;
V_169:
return V_124 ;
}
static int
F_102 ( struct V_175 * V_176 , struct V_135 * V_135 ,
struct V_177 * V_17 )
{
struct V_1 * V_2 ;
struct V_128 * V_129 ;
struct V_16 * V_121 ;
F_11 ( V_114 , L_17 , V_135 ) ;
V_2 = F_103 ( V_135 ) ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 ) {
F_104 ( F_62 ( V_135 ) , V_17 ) ;
return 0 ;
}
V_129 = F_63 ( V_135 ) ;
if ( F_56 ( V_129 ) )
return F_64 ( V_129 ) ;
V_121 = F_55 ( V_129 ) ;
if ( F_56 ( V_121 ) )
return F_64 ( V_121 ) ;
F_50 ( V_121 , F_62 ( V_135 ) , V_135 -> V_178 ) ;
F_104 ( F_62 ( V_135 ) , V_17 ) ;
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
return 0 ;
}
static int F_105 ( struct V_135 * V_135 , struct V_179 * V_179 )
{
int V_124 ;
struct V_1 * V_2 ;
struct V_128 * V_129 ;
struct V_16 V_46 ;
F_11 ( V_114 , L_15 ) ;
V_124 = F_106 ( F_62 ( V_135 ) , V_179 ) ;
if ( V_124 )
return V_124 ;
V_124 = - V_180 ;
V_2 = F_103 ( V_135 ) ;
V_129 = F_63 ( V_135 ) ;
if( F_56 ( V_129 ) )
return F_64 ( V_129 ) ;
F_14 ( & V_46 ) ;
if ( V_179 -> V_181 & V_182 )
V_46 . V_3 = F_1 ( V_2 , V_179 -> V_183 ) ;
if ( V_179 -> V_181 & V_184 )
V_46 . V_52 = V_179 -> V_185 . V_186 ;
if ( V_179 -> V_181 & V_187 )
V_46 . V_51 = V_179 -> V_188 . V_186 ;
if ( V_179 -> V_181 & V_189 )
V_46 . V_53 = V_179 -> V_190 ;
if ( F_3 ( V_2 ) ) {
if ( V_179 -> V_181 & V_191 )
V_46 . V_58 = V_179 -> V_192 ;
if ( V_179 -> V_181 & V_193 )
V_46 . V_60 = V_179 -> V_194 ;
}
if ( F_107 ( V_135 ) )
F_108 ( F_62 ( V_135 ) -> V_86 ) ;
V_124 = F_99 ( V_129 , & V_46 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ( V_179 -> V_181 & V_189 ) &&
V_179 -> V_190 != F_109 ( F_62 ( V_135 ) ) )
F_110 ( F_62 ( V_135 ) , V_179 -> V_190 ) ;
F_70 ( F_62 ( V_135 ) ) ;
F_111 ( F_62 ( V_135 ) , V_179 ) ;
F_112 ( F_62 ( V_135 ) ) ;
return 0 ;
}
void
F_50 ( struct V_16 * V_17 , struct V_63 * V_63 ,
struct V_64 * V_65 )
{
T_2 V_3 ;
char V_25 [ 32 ] ;
char V_195 [ 14 ] ;
unsigned int V_196 ;
struct V_1 * V_2 = V_65 -> V_113 ;
struct V_66 * V_67 = F_22 ( V_63 ) ;
F_113 ( V_63 , 1 ) ;
V_63 -> V_82 . V_186 = V_17 -> V_51 ;
V_63 -> V_83 . V_186 = V_17 -> V_52 ;
V_63 -> V_84 . V_186 = V_17 -> V_52 ;
V_63 -> V_197 = V_2 -> V_198 ;
V_63 -> V_199 = V_2 -> V_200 ;
if ( F_3 ( V_2 ) ) {
V_63 -> V_197 = V_17 -> V_58 ;
V_63 -> V_199 = V_17 -> V_60 ;
}
if ( ( F_114 ( V_63 -> V_94 ) ) || ( F_2 ( V_63 -> V_94 ) ) ) {
if ( F_3 ( V_2 ) && ( V_17 -> V_28 [ 0 ] != '\0' ) ) {
F_10 ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_18 , V_195 , & V_196 ) ;
if ( ! strncmp ( V_195 , L_19 , 13 ) )
F_113 ( V_63 , V_196 ) ;
}
}
V_3 = F_8 ( V_2 , V_17 ) ;
V_3 |= V_63 -> V_94 & ~ V_18 ;
V_63 -> V_94 = V_3 ;
F_115 ( V_63 , V_17 -> V_53 ) ;
V_63 -> V_80 = ( F_109 ( V_63 ) + 512 - 1 ) >> 9 ;
V_67 -> V_73 &= ~ V_201 ;
}
T_5 F_48 ( struct V_122 * V_48 )
{
T_6 V_50 = V_48 -> V_50 + 2 ;
T_5 V_159 = 0 ;
if ( sizeof( T_5 ) == sizeof( V_50 ) )
memcpy ( & V_159 , & V_50 , sizeof( T_5 ) ) ;
else
V_159 = ( T_5 ) ( V_50 ^ ( V_50 >> 32 ) ) ;
return V_159 ;
}
static const char * F_116 ( struct V_135 * V_135 ,
struct V_63 * V_63 ,
struct V_202 * V_169 )
{
struct V_1 * V_2 ;
struct V_128 * V_129 ;
struct V_16 * V_121 ;
char * V_4 ;
if ( ! V_135 )
return F_34 ( - V_203 ) ;
V_2 = F_103 ( V_135 ) ;
V_129 = F_63 ( V_135 ) ;
F_11 ( V_114 , L_20 , V_135 ) ;
if ( F_56 ( V_129 ) )
return F_57 ( V_129 ) ;
if ( ! F_3 ( V_2 ) )
return F_34 ( - V_204 ) ;
V_121 = F_55 ( V_129 ) ;
if ( F_56 ( V_121 ) )
return F_57 ( V_121 ) ;
if ( ! ( V_121 -> V_3 & V_21 ) ) {
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
return F_34 ( - V_93 ) ;
}
V_4 = V_121 -> V_28 ;
V_121 -> V_28 = NULL ;
if ( strlen ( V_4 ) >= V_205 )
V_4 [ V_205 - 1 ] = '\0' ;
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
F_117 ( V_169 , V_206 , V_4 ) ;
return V_4 ;
}
static int F_118 ( struct V_63 * V_134 , struct V_135 * V_135 ,
T_1 V_141 , const char * V_28 )
{
struct V_128 * V_129 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_134 ) ;
if ( ! F_3 ( V_2 ) ) {
F_11 ( V_31 , L_21 ) ;
return - V_180 ;
}
V_129 = F_71 ( V_2 , V_134 , V_135 , ( char * ) V_28 , V_141 ,
V_37 ) ;
if ( F_56 ( V_129 ) )
return F_64 ( V_129 ) ;
F_70 ( V_134 ) ;
F_41 ( V_129 ) ;
return 0 ;
}
static int
F_119 ( struct V_63 * V_134 , struct V_135 * V_135 , const char * V_207 )
{
F_11 ( V_114 , L_22 ,
V_134 -> V_125 , V_135 , V_207 ) ;
return F_118 ( V_134 , V_135 , V_21 , V_207 ) ;
}
static int
F_120 ( struct V_135 * V_162 , struct V_63 * V_134 ,
struct V_135 * V_135 )
{
int V_124 ;
char V_54 [ 1 + V_208 + 2 ] ;
struct V_128 * V_166 ;
F_11 ( V_114 , L_23 ,
V_134 -> V_125 , V_135 , V_162 ) ;
V_166 = F_66 ( V_162 ) ;
if ( F_56 ( V_166 ) )
return F_64 ( V_166 ) ;
sprintf ( V_54 , L_24 , V_166 -> V_129 ) ;
V_124 = F_118 ( V_134 , V_135 , V_143 , V_54 ) ;
if ( ! V_124 ) {
F_121 ( V_166 , F_62 ( V_162 ) ) ;
F_70 ( V_134 ) ;
}
F_41 ( V_166 ) ;
return V_124 ;
}
static int
F_122 ( struct V_63 * V_134 , struct V_135 * V_135 , T_2 V_3 , T_3 V_19 )
{
struct V_1 * V_2 = F_43 ( V_134 ) ;
int V_124 ;
char V_54 [ 2 + V_208 + 1 + V_208 + 1 ] ;
T_1 V_141 ;
F_11 ( V_114 , L_25 ,
V_134 -> V_125 , V_135 , V_3 ,
F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
if ( F_6 ( V_3 ) )
sprintf ( V_54 , L_26 , F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
else if ( F_7 ( V_3 ) )
sprintf ( V_54 , L_27 , F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
else
* V_54 = 0 ;
V_141 = F_1 ( V_2 , V_3 ) ;
V_124 = F_118 ( V_134 , V_135 , V_141 , V_54 ) ;
return V_124 ;
}
int F_121 ( struct V_128 * V_129 , struct V_63 * V_63 )
{
int V_120 ;
T_3 V_19 ;
T_7 V_209 ;
struct V_16 * V_121 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_63 ) ;
V_121 = F_55 ( V_129 ) ;
if ( F_56 ( V_121 ) )
return F_64 ( V_121 ) ;
V_120 = F_9 ( V_2 , V_121 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_120 & V_89 ) )
goto V_158;
F_125 ( & V_63 -> V_210 ) ;
V_209 = V_63 -> V_209 ;
F_50 ( V_121 , V_63 , V_63 -> V_144 ) ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
V_63 -> V_209 = V_209 ;
F_126 ( & V_63 -> V_210 ) ;
V_158:
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
return 0 ;
}
