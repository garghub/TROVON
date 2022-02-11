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
if ( ! F_3 ( V_2 ) && ! F_28 ( V_2 ) ) {
F_11 ( V_31 ,
L_4 ) ;
V_79 = - V_93 ;
goto error;
}
if ( F_28 ( V_2 ) )
V_63 -> V_90 = & V_106 ;
else
V_63 -> V_90 = & V_107 ;
break;
case V_20 :
F_30 ( V_63 ) ;
if ( F_28 ( V_2 ) )
V_63 -> V_90 = & V_108 ;
else if ( F_3 ( V_2 ) )
V_63 -> V_90 = & V_109 ;
else
V_63 -> V_90 = & V_110 ;
if ( F_28 ( V_2 ) )
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
struct V_63 * F_31 ( struct V_64 * V_65 , T_2 V_3 , T_3 V_19 )
{
int V_79 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_113 ;
F_11 ( V_114 , L_6 , V_65 , V_3 ) ;
V_63 = F_32 ( V_65 ) ;
if ( ! V_63 ) {
F_33 ( L_7 ,
V_115 , F_34 ( V_116 ) ) ;
return F_35 ( - V_117 ) ;
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
F_38 ( V_63 -> V_86 ) ;
F_39 ( V_63 ) ;
F_40 ( V_63 -> V_86 ) ;
F_41 ( V_63 ) ;
if ( V_67 -> V_72 ) {
F_42 ( V_67 -> V_72 ) ;
V_67 -> V_72 = NULL ;
}
}
static int F_43 ( struct V_63 * V_63 , void * V_118 )
{
int V_119 ;
T_3 V_19 ;
struct V_66 * V_67 = F_23 ( V_63 ) ;
struct V_16 * V_120 = (struct V_16 * ) V_118 ;
struct V_1 * V_2 = F_44 ( V_63 ) ;
V_119 = F_9 ( V_2 , V_120 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_119 & V_89 ) )
return 0 ;
if ( memcmp ( & V_67 -> V_48 . V_49 ,
& V_120 -> V_48 . V_49 , sizeof( V_67 -> V_48 . V_49 ) ) )
return 0 ;
if ( V_67 -> V_48 . type != V_120 -> V_48 . type )
return 0 ;
return 1 ;
}
static int F_45 ( struct V_63 * V_63 , void * V_118 )
{
return 0 ;
}
static int F_46 ( struct V_63 * V_63 , void * V_118 )
{
struct V_66 * V_67 = F_23 ( V_63 ) ;
struct V_16 * V_120 = (struct V_16 * ) V_118 ;
memcpy ( & V_67 -> V_48 , & V_120 -> V_48 , sizeof( V_120 -> V_48 ) ) ;
return 0 ;
}
static struct V_63 * F_47 ( struct V_64 * V_65 ,
struct V_121 * V_48 ,
struct V_16 * V_120 ,
int V_122 )
{
T_3 V_19 ;
int V_123 ;
T_2 V_119 ;
unsigned long V_124 ;
struct V_63 * V_63 ;
struct V_1 * V_2 = V_65 -> V_113 ;
int (* F_48)( struct V_63 * , void * );
if ( V_122 )
F_48 = F_45 ;
else
F_48 = F_43 ;
V_124 = F_49 ( V_48 ) ;
V_63 = F_50 ( V_65 , V_124 , F_48 , F_46 , V_120 ) ;
if ( ! V_63 )
return F_35 ( - V_117 ) ;
if ( ! ( V_63 -> V_125 & V_126 ) )
return V_63 ;
V_63 -> V_124 = V_124 ;
V_119 = F_9 ( V_2 , V_120 , & V_19 ) ;
V_123 = F_26 ( V_2 , V_63 , V_119 , V_19 ) ;
if ( V_123 )
goto error;
F_51 ( V_120 , V_63 , V_65 ) ;
F_52 ( V_63 ) ;
F_53 ( V_63 ) ;
return V_63 ;
error:
F_54 ( V_63 ) ;
return F_35 ( V_123 ) ;
}
struct V_63 *
F_55 ( struct V_1 * V_2 , struct V_127 * V_128 ,
struct V_64 * V_65 , int V_122 )
{
struct V_16 * V_120 ;
struct V_63 * V_63 = NULL ;
V_120 = F_56 ( V_128 ) ;
if ( F_57 ( V_120 ) )
return F_58 ( V_120 ) ;
V_63 = F_47 ( V_65 , & V_120 -> V_48 , V_120 , V_122 ) ;
F_59 ( V_120 ) ;
F_60 ( V_120 ) ;
return V_63 ;
}
static int F_61 ( int V_129 )
{
int V_130 = 0 ;
if ( V_129 & V_131 )
V_130 |= V_132 ;
return V_130 ;
}
static int F_62 ( struct V_63 * V_133 , struct V_134 * V_134 , int V_129 )
{
struct V_63 * V_63 ;
int V_123 = - V_135 ;
struct V_127 * V_136 , * V_137 ;
struct V_1 * V_2 ;
F_11 ( V_114 , L_8 ,
V_133 , V_134 , V_129 ) ;
V_2 = F_44 ( V_133 ) ;
V_63 = F_63 ( V_134 ) ;
V_137 = F_64 ( V_134 -> V_138 ) ;
if ( F_57 ( V_137 ) ) {
V_123 = F_65 ( V_137 ) ;
F_11 ( V_114 , L_9 , V_123 ) ;
return V_123 ;
}
if ( F_28 ( V_2 ) )
V_123 = F_66 ( V_137 , V_134 -> V_139 . V_54 ,
F_61 ( V_129 ) ) ;
if ( V_123 == - V_135 ) {
V_136 = F_67 ( V_134 ) ;
if ( F_57 ( V_136 ) )
return F_65 ( V_136 ) ;
V_123 = F_68 ( V_136 ) ;
}
if ( ! V_123 ) {
if ( V_129 & V_131 ) {
F_69 ( V_63 ) ;
F_70 ( V_133 ) ;
} else
F_70 ( V_63 ) ;
F_71 ( V_63 ) ;
F_71 ( V_133 ) ;
}
return V_123 ;
}
static struct V_127 *
F_72 ( struct V_1 * V_2 , struct V_63 * V_133 ,
struct V_134 * V_134 , char * V_28 , T_1 V_140 , T_4 V_3 )
{
int V_79 ;
char * V_54 ;
struct V_127 * V_137 , * V_141 , * V_128 ;
struct V_63 * V_63 ;
F_11 ( V_114 , L_10 , V_134 ) ;
V_79 = 0 ;
V_141 = NULL ;
V_128 = NULL ;
V_54 = ( char * ) V_134 -> V_139 . V_54 ;
V_137 = F_64 ( V_134 -> V_138 ) ;
if ( F_57 ( V_137 ) ) {
V_79 = F_65 ( V_137 ) ;
F_11 ( V_114 , L_9 , V_79 ) ;
return F_35 ( V_79 ) ;
}
V_141 = F_73 ( V_137 , 0 , NULL , 1 ) ;
if ( F_57 ( V_141 ) ) {
V_79 = F_65 ( V_141 ) ;
F_11 ( V_114 , L_11 , V_79 ) ;
return F_35 ( V_79 ) ;
}
V_79 = F_74 ( V_141 , V_54 , V_140 , V_3 , V_28 ) ;
if ( V_79 < 0 ) {
F_11 ( V_114 , L_12 , V_79 ) ;
goto error;
}
if ( ! ( V_140 & V_142 ) ) {
V_128 = F_73 ( V_137 , 1 , & V_54 , 1 ) ;
if ( F_57 ( V_128 ) ) {
V_79 = F_65 ( V_128 ) ;
F_11 ( V_114 ,
L_11 , V_79 ) ;
V_128 = NULL ;
goto error;
}
V_63 = F_75 ( V_2 , V_128 , V_133 -> V_143 ) ;
if ( F_57 ( V_63 ) ) {
V_79 = F_65 ( V_63 ) ;
F_11 ( V_114 ,
L_13 , V_79 ) ;
goto error;
}
F_76 ( V_134 , V_128 ) ;
F_77 ( V_134 , V_63 ) ;
}
return V_141 ;
error:
if ( V_141 )
F_42 ( V_141 ) ;
if ( V_128 )
F_42 ( V_128 ) ;
return F_35 ( V_79 ) ;
}
static int
F_78 ( struct V_63 * V_133 , struct V_134 * V_134 , T_2 V_3 ,
bool V_144 )
{
struct V_1 * V_2 = F_44 ( V_133 ) ;
T_1 V_140 = F_1 ( V_2 , V_3 ) ;
struct V_127 * V_128 ;
V_128 = F_72 ( V_2 , V_133 , V_134 , NULL , V_140 , V_41 ) ;
if ( F_57 ( V_128 ) )
return F_65 ( V_128 ) ;
F_71 ( V_133 ) ;
F_42 ( V_128 ) ;
return 0 ;
}
static int F_79 ( struct V_63 * V_133 , struct V_134 * V_134 , T_2 V_3 )
{
int V_79 ;
T_1 V_140 ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
F_11 ( V_114 , L_10 , V_134 ) ;
V_79 = 0 ;
V_2 = F_44 ( V_133 ) ;
V_140 = F_1 ( V_2 , V_3 | V_20 ) ;
V_128 = F_72 ( V_2 , V_133 , V_134 , NULL , V_140 , V_37 ) ;
if ( F_57 ( V_128 ) ) {
V_79 = F_65 ( V_128 ) ;
V_128 = NULL ;
} else {
F_30 ( V_133 ) ;
F_71 ( V_133 ) ;
}
if ( V_128 )
F_42 ( V_128 ) ;
return V_79 ;
}
struct V_134 * F_80 ( struct V_63 * V_133 , struct V_134 * V_134 ,
unsigned int V_129 )
{
struct V_134 * V_4 ;
struct V_1 * V_2 ;
struct V_127 * V_137 , * V_128 ;
struct V_63 * V_63 ;
char * V_54 ;
F_11 ( V_114 , L_14 ,
V_133 , V_134 , V_134 , V_129 ) ;
if ( V_134 -> V_139 . V_145 > V_146 )
return F_35 ( - V_147 ) ;
V_2 = F_44 ( V_133 ) ;
V_137 = F_64 ( V_134 -> V_138 ) ;
if ( F_57 ( V_137 ) )
return F_58 ( V_137 ) ;
V_54 = ( char * ) V_134 -> V_139 . V_54 ;
V_128 = F_73 ( V_137 , 1 , & V_54 , 1 ) ;
if ( F_57 ( V_128 ) ) {
if ( V_128 == F_35 ( - V_148 ) ) {
F_81 ( V_134 , NULL ) ;
return NULL ;
}
return F_58 ( V_128 ) ;
}
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
V_63 = F_82 ( V_2 , V_128 , V_133 -> V_143 ) ;
else
V_63 = F_75 ( V_2 , V_128 , V_133 -> V_143 ) ;
if ( F_57 ( V_63 ) ) {
F_42 ( V_128 ) ;
return F_58 ( V_63 ) ;
}
V_4 = F_83 ( V_63 , V_134 ) ;
if ( ! V_4 )
F_76 ( V_134 , V_128 ) ;
else if ( ! F_57 ( V_4 ) )
F_76 ( V_4 , V_128 ) ;
else
F_42 ( V_128 ) ;
return V_4 ;
}
static int
F_84 ( struct V_63 * V_133 , struct V_134 * V_134 ,
struct V_149 * V_149 , unsigned V_129 , T_2 V_3 ,
int * V_150 )
{
int V_79 ;
T_1 V_140 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_127 * V_128 , * V_151 ;
struct V_134 * V_4 = NULL ;
if ( F_85 ( V_134 ) ) {
V_4 = F_80 ( V_133 , V_134 , 0 ) ;
if ( F_57 ( V_4 ) )
return F_65 ( V_4 ) ;
if ( V_4 )
V_134 = V_4 ;
}
if ( ! ( V_129 & V_152 ) || F_86 ( V_134 ) )
return F_87 ( V_149 , V_4 ) ;
V_79 = 0 ;
V_2 = F_44 ( V_133 ) ;
V_140 = F_1 ( V_2 , V_3 ) ;
V_128 = F_72 ( V_2 , V_133 , V_134 , NULL , V_140 ,
F_13 ( V_129 ,
F_3 ( V_2 ) ) ) ;
if ( F_57 ( V_128 ) ) {
V_79 = F_65 ( V_128 ) ;
V_128 = NULL ;
goto error;
}
F_71 ( V_133 ) ;
V_67 = F_23 ( F_63 ( V_134 ) ) ;
F_88 ( & V_67 -> V_74 ) ;
if ( ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 ) &&
! V_67 -> V_72 &&
( ( V_129 & V_153 ) != V_36 ) ) {
V_151 = F_89 ( V_134 ) ;
if ( F_57 ( V_151 ) ) {
V_79 = F_65 ( V_151 ) ;
F_90 ( & V_67 -> V_74 ) ;
goto error;
}
V_67 -> V_72 = ( void * ) V_151 ;
}
F_90 ( & V_67 -> V_74 ) ;
V_79 = F_91 ( V_149 , V_134 , V_154 , V_150 ) ;
if ( V_79 )
goto error;
V_149 -> V_155 = V_128 ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
F_92 ( F_63 ( V_134 ) , V_149 ) ;
* V_150 |= V_156 ;
V_157:
F_93 ( V_4 ) ;
return V_79 ;
error:
if ( V_128 )
F_42 ( V_128 ) ;
goto V_157;
}
int F_94 ( struct V_63 * V_158 , struct V_134 * V_159 )
{
return F_62 ( V_158 , V_159 , 0 ) ;
}
int F_95 ( struct V_63 * V_158 , struct V_134 * V_159 )
{
return F_62 ( V_158 , V_159 , V_131 ) ;
}
int
F_96 ( struct V_63 * V_160 , struct V_134 * V_161 ,
struct V_63 * V_162 , struct V_134 * V_163 )
{
int V_123 ;
struct V_63 * V_164 ;
struct V_63 * F_32 ;
struct V_1 * V_2 ;
struct V_127 * V_165 ;
struct V_127 * V_166 ;
struct V_127 * V_167 ;
struct V_16 V_46 ;
F_11 ( V_114 , L_15 ) ;
V_123 = 0 ;
V_164 = F_63 ( V_161 ) ;
F_32 = F_63 ( V_163 ) ;
V_2 = F_44 ( V_164 ) ;
V_165 = F_64 ( V_161 ) ;
if ( F_57 ( V_165 ) )
return F_65 ( V_165 ) ;
V_166 = F_67 ( V_161 -> V_138 ) ;
if ( F_57 ( V_166 ) ) {
V_123 = F_65 ( V_166 ) ;
goto V_168;
}
V_167 = F_67 ( V_163 -> V_138 ) ;
if ( F_57 ( V_167 ) ) {
V_123 = F_65 ( V_167 ) ;
goto V_169;
}
F_97 ( & V_2 -> V_170 ) ;
if ( F_28 ( V_2 ) ) {
V_123 = F_98 ( V_166 , V_161 -> V_139 . V_54 ,
V_167 , V_163 -> V_139 . V_54 ) ;
if ( V_123 == - V_135 )
V_123 = F_99 ( V_165 , V_167 ,
V_163 -> V_139 . V_54 ) ;
if ( V_123 != - V_135 )
goto V_171;
}
if ( V_161 -> V_138 != V_163 -> V_138 ) {
F_11 ( V_31 , L_16 ) ;
V_123 = - V_172 ;
goto V_171;
}
F_14 ( & V_46 ) ;
V_46 . V_57 = V_2 -> V_173 ;
V_46 . V_54 = ( char * ) V_163 -> V_139 . V_54 ;
V_123 = F_100 ( V_165 , & V_46 ) ;
V_171:
if ( ! V_123 ) {
if ( F_32 ) {
if ( F_2 ( F_32 -> V_94 ) )
F_69 ( F_32 ) ;
else
F_70 ( F_32 ) ;
}
if ( F_2 ( V_164 -> V_94 ) ) {
if ( ! F_32 )
F_30 ( V_162 ) ;
F_70 ( V_160 ) ;
}
F_71 ( V_164 ) ;
F_71 ( V_160 ) ;
F_71 ( V_162 ) ;
F_101 ( V_161 , V_163 ) ;
}
F_102 ( & V_2 -> V_170 ) ;
F_42 ( V_167 ) ;
V_169:
F_42 ( V_166 ) ;
V_168:
return V_123 ;
}
static int
F_103 ( struct V_174 * V_175 , struct V_134 * V_134 ,
struct V_176 * V_17 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 ;
struct V_16 * V_120 ;
F_11 ( V_114 , L_17 , V_134 ) ;
V_2 = F_104 ( V_134 ) ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 ) {
F_105 ( F_63 ( V_134 ) , V_17 ) ;
return 0 ;
}
V_128 = F_64 ( V_134 ) ;
if ( F_57 ( V_128 ) )
return F_65 ( V_128 ) ;
V_120 = F_56 ( V_128 ) ;
if ( F_57 ( V_120 ) )
return F_65 ( V_120 ) ;
F_51 ( V_120 , F_63 ( V_134 ) , F_63 ( V_134 ) -> V_143 ) ;
F_105 ( F_63 ( V_134 ) , V_17 ) ;
F_59 ( V_120 ) ;
F_60 ( V_120 ) ;
return 0 ;
}
static int F_106 ( struct V_134 * V_134 , struct V_177 * V_177 )
{
int V_123 ;
struct V_1 * V_2 ;
struct V_127 * V_128 ;
struct V_16 V_46 ;
F_11 ( V_114 , L_15 ) ;
V_123 = F_107 ( F_63 ( V_134 ) , V_177 ) ;
if ( V_123 )
return V_123 ;
V_123 = - V_178 ;
V_2 = F_104 ( V_134 ) ;
V_128 = F_64 ( V_134 ) ;
if( F_57 ( V_128 ) )
return F_65 ( V_128 ) ;
F_14 ( & V_46 ) ;
if ( V_177 -> V_179 & V_180 )
V_46 . V_3 = F_1 ( V_2 , V_177 -> V_181 ) ;
if ( V_177 -> V_179 & V_182 )
V_46 . V_52 = V_177 -> V_183 . V_184 ;
if ( V_177 -> V_179 & V_185 )
V_46 . V_51 = V_177 -> V_186 . V_184 ;
if ( V_177 -> V_179 & V_187 )
V_46 . V_53 = V_177 -> V_188 ;
if ( F_3 ( V_2 ) ) {
if ( V_177 -> V_179 & V_189 )
V_46 . V_58 = V_177 -> V_190 ;
if ( V_177 -> V_179 & V_191 )
V_46 . V_60 = V_177 -> V_192 ;
}
if ( F_108 ( V_134 ) )
F_109 ( F_63 ( V_134 ) -> V_86 ) ;
V_123 = F_100 ( V_128 , & V_46 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( ( V_177 -> V_179 & V_187 ) &&
V_177 -> V_188 != F_110 ( F_63 ( V_134 ) ) )
F_111 ( F_63 ( V_134 ) , V_177 -> V_188 ) ;
F_71 ( F_63 ( V_134 ) ) ;
F_112 ( F_63 ( V_134 ) , V_177 ) ;
F_113 ( F_63 ( V_134 ) ) ;
return 0 ;
}
void
F_51 ( struct V_16 * V_17 , struct V_63 * V_63 ,
struct V_64 * V_65 )
{
T_2 V_3 ;
char V_25 [ 32 ] ;
char V_193 [ 14 ] ;
unsigned int V_194 ;
struct V_1 * V_2 = V_65 -> V_113 ;
struct V_66 * V_67 = F_23 ( V_63 ) ;
F_114 ( V_63 , 1 ) ;
V_63 -> V_82 . V_184 = V_17 -> V_51 ;
V_63 -> V_83 . V_184 = V_17 -> V_52 ;
V_63 -> V_84 . V_184 = V_17 -> V_52 ;
V_63 -> V_195 = V_2 -> V_196 ;
V_63 -> V_197 = V_2 -> V_198 ;
if ( F_3 ( V_2 ) ) {
V_63 -> V_195 = V_17 -> V_58 ;
V_63 -> V_197 = V_17 -> V_60 ;
}
if ( ( F_115 ( V_63 -> V_94 ) ) || ( F_2 ( V_63 -> V_94 ) ) ) {
if ( F_3 ( V_2 ) && ( V_17 -> V_28 [ 0 ] != '\0' ) ) {
F_10 ( V_25 , V_17 -> V_28 , sizeof( V_25 ) ) ;
sscanf ( V_25 , L_18 , V_193 , & V_194 ) ;
if ( ! strncmp ( V_193 , L_19 , 13 ) )
F_114 ( V_63 , V_194 ) ;
}
}
V_3 = F_8 ( V_2 , V_17 ) ;
V_3 |= V_63 -> V_94 & ~ V_18 ;
V_63 -> V_94 = V_3 ;
F_116 ( V_63 , V_17 -> V_53 ) ;
V_63 -> V_80 = ( F_110 ( V_63 ) + 512 - 1 ) >> 9 ;
V_67 -> V_73 &= ~ V_199 ;
}
T_5 F_49 ( struct V_121 * V_48 )
{
T_6 V_50 = V_48 -> V_50 + 2 ;
T_5 V_158 = 0 ;
if ( sizeof( T_5 ) == sizeof( V_50 ) )
memcpy ( & V_158 , & V_50 , sizeof( T_5 ) ) ;
else
V_158 = ( T_5 ) ( V_50 ^ ( V_50 >> 32 ) ) ;
return V_158 ;
}
static const char * F_117 ( struct V_134 * V_134 , void * * V_200 )
{
struct V_1 * V_2 = F_104 ( V_134 ) ;
struct V_127 * V_128 = F_64 ( V_134 ) ;
struct V_16 * V_120 ;
char * V_4 ;
F_11 ( V_114 , L_20 , V_134 ) ;
if ( F_57 ( V_128 ) )
return F_58 ( V_128 ) ;
if ( ! F_3 ( V_2 ) )
return F_35 ( - V_201 ) ;
V_120 = F_56 ( V_128 ) ;
if ( F_57 ( V_120 ) )
return F_58 ( V_120 ) ;
if ( ! ( V_120 -> V_3 & V_21 ) ) {
F_59 ( V_120 ) ;
F_60 ( V_120 ) ;
return F_35 ( - V_93 ) ;
}
V_4 = V_120 -> V_28 ;
V_120 -> V_28 = NULL ;
if ( strlen ( V_4 ) >= V_202 )
V_4 [ V_202 - 1 ] = '\0' ;
F_59 ( V_120 ) ;
F_60 ( V_120 ) ;
return * V_200 = V_4 ;
}
static int F_118 ( struct V_63 * V_133 , struct V_134 * V_134 ,
T_1 V_140 , const char * V_28 )
{
struct V_127 * V_128 ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_133 ) ;
if ( ! F_3 ( V_2 ) ) {
F_11 ( V_31 , L_21 ) ;
return - V_178 ;
}
V_128 = F_72 ( V_2 , V_133 , V_134 , ( char * ) V_28 , V_140 ,
V_37 ) ;
if ( F_57 ( V_128 ) )
return F_65 ( V_128 ) ;
F_71 ( V_133 ) ;
F_42 ( V_128 ) ;
return 0 ;
}
static int
F_119 ( struct V_63 * V_133 , struct V_134 * V_134 , const char * V_203 )
{
F_11 ( V_114 , L_22 ,
V_133 -> V_124 , V_134 , V_203 ) ;
return F_118 ( V_133 , V_134 , V_21 , V_203 ) ;
}
static int
F_120 ( struct V_134 * V_161 , struct V_63 * V_133 ,
struct V_134 * V_134 )
{
int V_123 ;
char V_54 [ 1 + V_204 + 2 ] ;
struct V_127 * V_165 ;
F_11 ( V_114 , L_23 ,
V_133 -> V_124 , V_134 , V_161 ) ;
V_165 = F_67 ( V_161 ) ;
if ( F_57 ( V_165 ) )
return F_65 ( V_165 ) ;
sprintf ( V_54 , L_24 , V_165 -> V_128 ) ;
V_123 = F_118 ( V_133 , V_134 , V_142 , V_54 ) ;
if ( ! V_123 ) {
F_121 ( V_165 , F_63 ( V_161 ) ) ;
F_71 ( V_133 ) ;
}
F_42 ( V_165 ) ;
return V_123 ;
}
static int
F_122 ( struct V_63 * V_133 , struct V_134 * V_134 , T_2 V_3 , T_3 V_19 )
{
struct V_1 * V_2 = F_44 ( V_133 ) ;
int V_123 ;
char V_54 [ 2 + V_204 + 1 + V_204 + 1 ] ;
T_1 V_140 ;
F_11 ( V_114 , L_25 ,
V_133 -> V_124 , V_134 , V_3 ,
F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
if ( ! F_125 ( V_19 ) )
return - V_93 ;
if ( F_6 ( V_3 ) )
sprintf ( V_54 , L_26 , F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
else if ( F_7 ( V_3 ) )
sprintf ( V_54 , L_27 , F_123 ( V_19 ) , F_124 ( V_19 ) ) ;
else
* V_54 = 0 ;
V_140 = F_1 ( V_2 , V_3 ) ;
V_123 = F_118 ( V_133 , V_134 , V_140 , V_54 ) ;
return V_123 ;
}
int F_121 ( struct V_127 * V_128 , struct V_63 * V_63 )
{
int V_119 ;
T_3 V_19 ;
T_7 V_205 ;
struct V_16 * V_120 ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_63 ) ;
V_120 = F_56 ( V_128 ) ;
if ( F_57 ( V_120 ) )
return F_65 ( V_120 ) ;
V_119 = F_9 ( V_2 , V_120 , & V_19 ) ;
if ( ( V_63 -> V_94 & V_89 ) != ( V_119 & V_89 ) )
goto V_157;
F_126 ( & V_63 -> V_206 ) ;
V_205 = V_63 -> V_205 ;
F_51 ( V_120 , V_63 , V_63 -> V_143 ) ;
if ( V_2 -> V_95 == V_96 || V_2 -> V_95 == V_97 )
V_63 -> V_205 = V_205 ;
F_127 ( & V_63 -> V_206 ) ;
V_157:
F_59 ( V_120 ) ;
F_60 ( V_120 ) ;
return 0 ;
}
