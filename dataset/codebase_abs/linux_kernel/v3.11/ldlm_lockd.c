inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( ( int ) F_3 ( F_4 ( V_1 , 0 ) ) + 1 ) ;
}
static inline unsigned int F_5 ( void )
{
unsigned int V_1 = F_6 ( V_2 , V_3 / 3 ) ;
return V_1 < 1 ? 1 : V_1 ;
}
int F_7 ( struct V_4 * V_5 )
{
RETURN ( 0 ) ;
}
int F_8 ( struct V_4 * V_5 , int V_1 )
{
RETURN ( 0 ) ;
}
void F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_10 ;
V_11 ;
F_10 ( V_5 , L_1 ) ;
F_11 ( V_5 ) ;
V_5 -> V_12 |= V_13 ;
if ( V_5 -> V_12 & V_14 )
V_5 -> V_12 |= V_15 ;
V_10 = ( ! V_5 -> V_16 && ! V_5 -> V_17 ) ;
F_12 ( V_5 ) ;
if ( V_10 ) {
F_13 ( V_18 , L_2 ,
V_5 , V_5 -> V_19 ) ;
if ( V_5 -> V_19 != NULL )
V_5 -> V_19 ( V_5 , V_9 , V_5 -> V_20 ,
V_21 ) ;
} else {
F_13 ( V_18 , L_3 ,
V_5 ) ;
}
F_10 ( V_5 , L_4 ) ;
F_14 ( V_5 ) ;
EXIT ;
}
static void F_15 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
struct V_24 * V_25 ,
struct V_4 * V_5 )
{
int V_26 ;
F_16 ( V_27 ) ;
int V_28 = 0 ;
V_11 ;
F_10 ( V_5 , L_5 ) ;
if ( F_17 ( V_29 ) ) {
int V_30 = F_2 ( 1 ) ;
while ( V_30 > 0 ) {
F_18 (
V_31 , V_30 ) ;
if ( V_5 -> V_32 == V_5 -> V_33 ||
V_5 -> V_34 )
break;
}
}
V_26 = F_19 ( & V_23 -> V_35 , & V_36 , V_37 ) ;
if ( V_26 < 0 ) {
F_20 ( V_5 , L_6 , V_26 ) ;
GOTO ( V_38 , V_28 = V_26 ) ;
} else if ( V_26 > 0 ) {
if ( V_5 -> V_39 > 0 ) {
F_21 ( V_5 -> V_40 != NULL ) ;
if ( F_22 ( V_5 -> V_39 < V_26 ) ) {
F_20 ( V_5 , L_7
L_8
L_9 ,
V_5 -> V_39 , V_26 ) ;
GOTO ( V_38 , V_28 = - V_41 ) ;
}
} else if ( F_23 ( V_5 ) ) {
void * V_42 ;
F_24 ( V_42 , V_26 ) ;
if ( V_42 == NULL ) {
F_20 ( V_5 , L_10 , V_26 ) ;
GOTO ( V_38 , V_28 = - V_43 ) ;
}
F_11 ( V_5 ) ;
F_21 ( V_5 -> V_40 == NULL ) ;
V_5 -> V_40 = V_42 ;
V_5 -> V_39 = V_26 ;
F_12 ( V_5 ) ;
}
}
F_11 ( V_5 ) ;
if ( V_5 -> V_34 ||
V_5 -> V_32 == V_5 -> V_33 ) {
F_12 ( V_5 ) ;
F_10 ( V_5 , L_11 ) ;
GOTO ( V_38 , V_28 = 0 ) ;
}
if ( V_25 -> V_44 . V_32 != V_5 -> V_33 ) {
V_5 -> V_33 = V_25 -> V_44 . V_32 ;
F_10 ( V_5 , L_12 ) ;
}
if ( V_5 -> V_45 -> V_46 != V_47 ) {
F_25 ( V_23 -> V_48 ,
V_25 -> V_44 . V_45 . V_46 ,
& V_25 -> V_44 . V_49 ,
& V_5 -> V_49 ) ;
F_10 ( V_5 , L_13 ) ;
}
F_26 ( V_5 ) ;
if ( memcmp ( & V_25 -> V_44 . V_45 . V_50 ,
& V_5 -> V_45 -> V_50 ,
sizeof( V_5 -> V_45 -> V_50 ) ) != 0 ) {
F_12 ( V_5 ) ;
V_28 = F_27 ( V_7 , V_5 ,
& V_25 -> V_44 . V_45 . V_50 ) ;
if ( V_28 < 0 ) {
F_20 ( V_5 , L_14 ) ;
GOTO ( V_38 , V_28 ) ;
}
F_10 ( V_5 , L_15 ) ;
F_28 ( L_16 ) ;
F_11 ( V_5 ) ;
}
if ( V_25 -> V_51 & V_52 ) {
F_29 ( V_5 ) ;
V_5 -> V_12 |= V_13 | V_53 ;
F_10 ( V_5 , L_17 ) ;
}
if ( V_5 -> V_39 > 0 ) {
V_28 = F_30 ( V_5 , & V_23 -> V_35 , V_37 ,
V_5 -> V_40 , V_26 ) ;
if ( V_28 < 0 ) {
F_12 ( V_5 ) ;
GOTO ( V_38 , V_28 ) ;
}
}
F_31 ( V_5 , & V_27 ) ;
F_12 ( V_5 ) ;
F_10 ( V_5 , L_18 ) ;
F_32 ( V_54 , 2 ) ;
F_33 ( V_7 , & V_27 , V_55 ) ;
F_34 ( L_19 ,
V_5 ) ;
GOTO ( V_38 , V_28 ) ;
V_38:
if ( V_28 < 0 ) {
F_11 ( V_5 ) ;
V_5 -> V_12 |= V_56 ;
F_12 ( V_5 ) ;
F_35 ( & V_5 -> V_57 ) ;
}
F_14 ( V_5 ) ;
}
static void F_36 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
struct V_24 * V_25 ,
struct V_4 * V_5 )
{
int V_28 = - V_58 ;
V_11 ;
F_10 ( V_5 , L_20 ) ;
if ( V_5 -> V_59 != NULL )
V_28 = V_5 -> V_59 ( V_5 , V_23 ) ;
if ( V_23 -> V_60 != NULL ) {
F_37 ( V_23 ) ;
} else {
V_23 -> V_61 = V_28 ;
F_38 ( V_23 ) ;
}
F_11 ( V_5 ) ;
if ( V_5 -> V_32 == V_62 &&
! V_5 -> V_16 && ! V_5 -> V_17 &&
F_39 ( F_40 () ,
F_41 ( V_5 -> V_63 ,
F_2 ( 10 ) ) ) ) {
F_12 ( V_5 ) ;
if ( F_42 ( V_7 , NULL , V_5 ) )
F_9 ( V_7 , NULL , V_5 ) ;
EXIT ;
return;
}
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
EXIT ;
}
static int F_43 ( struct V_22 * V_23 , int V_28 )
{
if ( V_23 -> V_64 )
return 0 ;
V_23 -> V_61 = V_28 ;
if ( ! V_23 -> V_65 ) {
V_28 = F_44 ( V_23 , 1 , NULL , NULL ) ;
if ( V_28 )
return V_28 ;
}
return F_37 ( V_23 ) ;
}
static int F_45 ( struct V_66 * V_67 ,
T_2 V_68 )
{
struct V_69 * V_70 = V_71 -> V_69 ;
V_11 ;
F_46 ( & V_70 -> V_72 ) ;
if ( V_67 -> V_73 &&
V_67 -> V_73 -> V_12 & V_74 ) {
F_47 ( & V_67 -> V_75 , & V_70 -> V_76 ) ;
} else {
F_47 ( & V_67 -> V_75 , & V_70 -> V_77 ) ;
}
F_48 ( & V_70 -> V_72 ) ;
F_35 ( & V_70 -> V_78 ) ;
if ( ! ( V_68 & V_79 ) )
F_49 ( & V_67 -> V_80 ) ;
RETURN ( 0 ) ;
}
static inline void F_50 ( struct V_66 * V_67 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_81 * V_82 , int V_83 ,
struct V_4 * V_5 ,
T_2 V_68 )
{
F_51 ( & V_67 -> V_80 ) ;
F_52 ( & V_67 -> V_84 ) ;
if ( F_53 () )
V_67 -> V_85 = 1 ;
V_67 -> V_86 = V_7 ;
V_67 -> V_87 = V_68 ;
if ( V_9 != NULL )
V_67 -> V_88 = * V_9 ;
if ( V_83 ) {
F_54 ( & V_67 -> V_84 , V_82 ) ;
F_55 ( V_82 ) ;
V_67 -> V_89 = V_83 ;
} else {
V_67 -> V_73 = V_5 ;
}
}
static int F_56 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_4 * V_5 ,
struct V_81 * V_82 , int V_83 ,
T_2 V_68 )
{
V_11 ;
if ( V_82 && V_83 == 0 )
RETURN ( 0 ) ;
if ( V_68 & V_79 ) {
struct V_66 * V_67 ;
F_24 ( V_67 , sizeof( * V_67 ) ) ;
if ( V_67 == NULL )
RETURN ( - V_43 ) ;
F_50 ( V_67 , V_7 , V_9 , V_82 , V_83 , V_5 , V_68 ) ;
RETURN ( F_45 ( V_67 , V_68 ) ) ;
} else {
struct V_66 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_50 ( & V_67 , V_7 , V_9 , V_82 , V_83 , V_5 , V_68 ) ;
RETURN ( F_45 ( & V_67 , V_68 ) ) ;
}
}
int F_42 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_4 * V_5 )
{
return F_56 ( V_7 , V_9 , V_5 , NULL , 0 , V_79 ) ;
}
int F_57 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_81 * V_82 , int V_83 ,
T_2 V_68 )
{
return F_56 ( V_7 , V_9 , NULL , V_82 , V_83 , V_68 ) ;
}
static int F_58 ( struct V_22 * V_23 )
{
struct V_90 * V_91 = V_23 -> V_48 -> V_92 ;
char * V_93 ;
void * V_94 ;
int V_95 , V_96 ;
int V_28 = - V_58 ;
V_11 ;
F_59 ( V_97 , V_23 , L_21 , V_91 -> V_98 ) ;
F_60 ( & V_23 -> V_35 , & V_99 ) ;
V_93 = F_61 ( & V_23 -> V_35 , & V_100 ) ;
if ( V_93 == NULL ) {
F_59 ( V_101 , V_23 , L_22 ) ;
RETURN ( - V_102 ) ;
}
V_95 = F_19 ( & V_23 -> V_35 , & V_100 ,
V_37 ) ;
V_94 = F_61 ( & V_23 -> V_35 , & V_103 ) ;
if ( V_94 == NULL ) {
F_59 ( V_101 , V_23 , L_23 ) ;
RETURN ( - V_102 ) ;
}
V_96 = F_19 ( & V_23 -> V_35 , & V_103 ,
V_37 ) ;
if ( F_62 ( V_104 ) )
V_28 = F_63 ( V_23 -> V_105 -> V_106 ,
V_23 -> V_48 ,
sizeof( V_104 ) ,
V_104 ,
V_96 , V_94 , NULL ) ;
else
F_59 ( V_107 , V_23 , L_24 , V_93 ) ;
return V_28 ;
}
static inline void F_64 ( struct V_22 * V_23 ,
const char * V_108 , int V_28 ,
struct V_109 * V_110 )
{
F_59 ( ( V_23 -> V_64 || V_28 ) ? V_107 : V_18 , V_23 ,
L_25 V_111 L_26 ,
V_108 , F_65 ( V_23 -> V_112 ) , V_28 ,
V_110 ? V_110 -> V_113 : 0 ) ;
if ( V_23 -> V_64 )
F_66 ( L_27 ) ;
else if ( V_28 )
F_66 ( L_28 ) ;
}
static int F_67 ( struct V_22 * V_23 )
{
struct V_114 * V_115 ;
struct V_116 * V_117 = & V_23 -> V_48 -> V_92 -> V_118 . V_117 ;
V_115 = F_61 ( & V_23 -> V_35 , & V_119 ) ;
if ( V_115 == NULL ) {
F_28 ( L_29 ) ;
RETURN ( - V_120 ) ;
}
V_117 -> V_121 = V_115 -> V_122 ;
return 0 ;
}
static int F_68 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_4 * V_5 ;
int V_28 ;
V_11 ;
if ( F_69 ( V_23 -> V_123 ) == V_124 )
RETURN ( 0 ) ;
F_70 ( & V_23 -> V_35 , V_23 , V_125 ) ;
if ( V_23 -> V_48 == NULL ) {
V_28 = F_43 ( V_23 , - V_126 ) ;
F_64 ( V_23 , L_30 ,
V_28 , NULL ) ;
RETURN ( 0 ) ;
}
F_21 ( V_23 -> V_48 != NULL ) ;
F_21 ( V_23 -> V_48 -> V_92 != NULL ) ;
switch ( F_69 ( V_23 -> V_123 ) ) {
case V_127 :
if ( F_17 ( V_128 ) )
RETURN ( 0 ) ;
break;
case V_129 :
if ( F_17 ( V_130 ) )
RETURN ( 0 ) ;
break;
case V_131 :
if ( F_17 ( V_132 ) )
RETURN ( 0 ) ;
break;
case V_133 :
V_28 = F_58 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_134 :
F_28 ( L_31 ) ;
F_60 ( & V_23 -> V_35 , & V_135 ) ;
if ( F_17 ( V_136 ) )
RETURN ( 0 ) ;
V_28 = F_71 ( V_23 ) ;
if ( F_17 ( V_137 ) )
RETURN ( 0 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_138 :
F_60 ( & V_23 -> V_35 , & V_139 ) ;
if ( F_17 ( V_140 ) )
RETURN ( 0 ) ;
V_28 = F_72 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_141 :
F_60 ( & V_23 -> V_35 ,
& V_142 ) ;
if ( F_17 ( V_140 ) )
RETURN ( 0 ) ;
V_28 = F_73 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_143 :
F_60 ( & V_23 -> V_35 ,
& V_144 ) ;
if ( F_17 ( V_140 ) )
RETURN ( 0 ) ;
V_28 = F_74 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_145 :
if ( F_17 ( V_140 ) )
RETURN ( 0 ) ;
V_28 = F_75 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
case V_146 :
F_60 ( & V_23 -> V_35 , & V_147 ) ;
if ( F_17 ( V_148 ) )
RETURN ( 0 ) ;
V_28 = F_67 ( V_23 ) ;
F_43 ( V_23 , V_28 ) ;
RETURN ( 0 ) ;
default:
F_28 ( L_32 ,
F_69 ( V_23 -> V_123 ) ) ;
F_43 ( V_23 , - V_120 ) ;
RETURN ( 0 ) ;
}
V_7 = V_23 -> V_48 -> V_92 -> V_149 ;
F_21 ( V_7 != NULL ) ;
F_60 ( & V_23 -> V_35 , & V_150 ) ;
V_25 = F_61 ( & V_23 -> V_35 , & V_151 ) ;
if ( V_25 == NULL ) {
V_28 = F_43 ( V_23 , - V_120 ) ;
F_64 ( V_23 , L_33 , V_28 ,
NULL ) ;
RETURN ( 0 ) ;
}
if ( F_17 ( V_29 ) &&
F_69 ( V_23 -> V_123 ) == V_127 ) {
V_28 = F_76 ( & V_25 -> V_152 [ 0 ] , 0 ) ;
if ( V_28 < 0 )
F_28 ( L_34 , V_28 ) ;
}
V_5 = F_77 ( & V_25 -> V_152 [ 0 ] , 0 ) ;
if ( ! V_5 ) {
F_13 ( V_18 , L_35 V_111 L_36
L_37 , V_25 -> V_152 [ 0 ] . V_113 ) ;
V_28 = F_43 ( V_23 , - V_41 ) ;
F_64 ( V_23 , L_38 , V_28 ,
& V_25 -> V_152 [ 0 ] ) ;
RETURN ( 0 ) ;
}
if ( ( V_5 -> V_12 & V_153 ) &&
F_69 ( V_23 -> V_123 ) == V_127 )
F_78 ( V_154 ) ;
F_11 ( V_5 ) ;
V_5 -> V_12 |= F_79 ( V_25 -> V_51 &
V_155 ) ;
if ( F_69 ( V_23 -> V_123 ) == V_127 ) {
if ( ( ( V_5 -> V_12 & V_156 ) &&
( V_5 -> V_12 & V_157 ) ) ||
( V_5 -> V_12 & V_56 ) ) {
F_10 ( V_5 , L_35
V_111 L_39 ,
V_25 -> V_152 [ 0 ] . V_113 ) ;
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
V_28 = F_43 ( V_23 , - V_41 ) ;
F_64 ( V_23 , L_40 , V_28 ,
& V_25 -> V_152 [ 0 ] ) ;
RETURN ( 0 ) ;
}
F_29 ( V_5 ) ;
V_5 -> V_12 |= V_53 ;
}
F_12 ( V_5 ) ;
switch ( F_69 ( V_23 -> V_123 ) ) {
case V_127 :
F_13 ( V_158 , L_41 ) ;
F_80 ( & V_23 -> V_35 , & V_159 ) ;
if ( ! ( V_5 -> V_12 & V_14 ) ) {
V_28 = F_43 ( V_23 , 0 ) ;
if ( V_23 -> V_64 || V_28 )
F_64 ( V_23 , L_42 , V_28 ,
& V_25 -> V_152 [ 0 ] ) ;
}
if ( F_42 ( V_7 , & V_25 -> V_44 , V_5 ) )
F_9 ( V_7 , & V_25 -> V_44 , V_5 ) ;
break;
case V_129 :
F_13 ( V_158 , L_43 ) ;
F_80 ( & V_23 -> V_35 , & V_160 ) ;
F_43 ( V_23 , 0 ) ;
F_15 ( V_23 , V_7 , V_25 , V_5 ) ;
break;
case V_131 :
F_13 ( V_158 , L_44 ) ;
F_80 ( & V_23 -> V_35 , & V_161 ) ;
F_36 ( V_23 , V_7 , V_25 , V_5 ) ;
break;
default:
F_81 () ;
}
RETURN ( 0 ) ;
}
static struct V_66 * F_82 ( struct V_69 * V_70 )
{
struct V_66 * V_67 = NULL ;
static unsigned int V_162 = 0 ;
F_46 ( & V_70 -> V_72 ) ;
if ( ! F_83 ( & V_70 -> V_77 ) &&
( F_83 ( & V_70 -> V_76 ) || V_162 == 0 ) )
V_67 = F_84 ( V_70 -> V_77 . V_163 ,
struct V_66 , V_75 ) ;
else
if ( ! F_83 ( & V_70 -> V_76 ) )
V_67 = F_84 ( V_70 -> V_76 . V_163 ,
struct V_66 ,
V_75 ) ;
if ( V_67 ) {
if ( ++ V_162 >= F_85 ( & V_70 -> V_164 ) )
V_162 = 0 ;
F_86 ( & V_67 -> V_75 ) ;
}
F_48 ( & V_70 -> V_72 ) ;
return V_67 ;
}
static int F_87 ( struct V_69 * V_70 )
{
struct V_165 V_166 = { . V_167 = V_70 } ;
T_3 * V_168 ;
F_51 ( & V_166 . V_169 ) ;
V_166 . V_170 = F_85 ( & V_70 -> V_164 ) ;
snprintf ( V_166 . V_171 , sizeof( V_166 . V_171 ) - 1 ,
L_45 , V_166 . V_170 ) ;
V_168 = F_88 ( V_172 , & V_166 , V_166 . V_171 ) ;
if ( F_89 ( V_168 ) ) {
F_28 ( L_46 ,
F_85 ( & V_70 -> V_164 ) , F_90 ( V_168 ) ) ;
return F_90 ( V_168 ) ;
}
F_49 ( & V_166 . V_169 ) ;
return 0 ;
}
static int V_172 ( void * V_173 )
{
struct V_69 * V_70 ;
V_11 ;
{
struct V_165 * V_166 = V_173 ;
V_70 = V_166 -> V_167 ;
F_91 ( & V_70 -> V_164 ) ;
F_91 ( & V_70 -> V_174 ) ;
F_92 ( & V_166 -> V_169 ) ;
}
while ( 1 ) {
struct V_175 V_176 = { 0 } ;
struct V_66 * V_67 = NULL ;
int V_177 ;
V_67 = F_82 ( V_70 ) ;
if ( V_67 == NULL ) {
F_93 ( & V_70 -> V_174 ) ;
F_94 ( V_70 -> V_78 ,
( V_67 = F_82 ( V_70 ) ) != NULL ,
& V_176 ) ;
V_177 = F_95 ( & V_70 -> V_174 ) ;
} else {
V_177 = F_85 ( & V_70 -> V_174 ) ;
}
if ( V_67 -> V_86 == NULL )
break;
if ( F_22 ( V_177 < V_70 -> V_178 &&
V_177 >= F_85 ( & V_70 -> V_164 ) &&
! V_67 -> V_85 ) )
F_87 ( V_70 ) ;
if ( V_67 -> V_85 )
F_96 () ;
if ( V_67 -> V_89 ) {
int V_83 ;
V_83 = F_97 ( & V_67 -> V_84 ,
V_67 -> V_89 ,
V_179 ) ;
F_98 ( & V_67 -> V_84 , V_83 , NULL ,
V_67 -> V_87 ) ;
} else {
F_9 ( V_67 -> V_86 , & V_67 -> V_88 ,
V_67 -> V_73 ) ;
}
if ( V_67 -> V_85 )
F_99 () ;
if ( V_67 -> V_87 & V_79 )
F_100 ( V_67 , sizeof( * V_67 ) ) ;
else
F_92 ( & V_67 -> V_80 ) ;
}
F_93 ( & V_70 -> V_174 ) ;
F_93 ( & V_70 -> V_164 ) ;
F_92 ( & V_70 -> V_180 ) ;
RETURN ( 0 ) ;
}
int F_101 ( void )
{
int V_28 = 0 ;
V_11 ;
F_102 ( & V_181 ) ;
if ( ++ V_182 == 1 ) {
V_28 = F_103 () ;
if ( V_28 )
V_182 -- ;
}
F_104 ( & V_181 ) ;
RETURN ( V_28 ) ;
}
void F_105 ( void )
{
V_11 ;
F_102 ( & V_181 ) ;
if ( V_182 == 1 ) {
int V_28 = F_106 () ;
if ( V_28 )
F_28 ( L_47 , V_28 ) ;
else
V_182 -- ;
} else {
V_182 -- ;
}
F_104 ( & V_181 ) ;
EXIT ;
}
static unsigned
F_107 ( T_4 * V_183 , const void * V_93 , unsigned V_184 )
{
return F_108 ( ( (struct V_109 * ) V_93 ) -> V_113 , V_184 ) ;
}
static void *
F_109 ( struct V_185 * V_186 )
{
struct V_4 * V_5 ;
V_5 = F_110 ( V_186 , struct V_4 , V_187 ) ;
return & V_5 -> V_188 ;
}
static void
F_111 ( struct V_185 * V_186 , void * V_93 )
{
struct V_4 * V_5 ;
V_5 = F_110 ( V_186 , struct V_4 , V_187 ) ;
V_5 -> V_188 = * (struct V_109 * ) V_93 ;
}
static int
F_112 ( const void * V_93 , struct V_185 * V_186 )
{
return F_113 ( F_109 ( V_186 ) , V_93 ) ;
}
static void *
F_114 ( struct V_185 * V_186 )
{
return F_110 ( V_186 , struct V_4 , V_187 ) ;
}
static void
F_115 ( T_4 * V_183 , struct V_185 * V_186 )
{
struct V_4 * V_5 ;
V_5 = F_110 ( V_186 , struct V_4 , V_187 ) ;
F_116 ( V_5 ) ;
}
static void
F_117 ( T_4 * V_183 , struct V_185 * V_186 )
{
struct V_4 * V_5 ;
V_5 = F_110 ( V_186 , struct V_4 , V_187 ) ;
F_14 ( V_5 ) ;
}
int F_118 ( struct V_189 * exp )
{
V_11 ;
exp -> V_190 =
F_119 ( F_120 ( & exp -> V_191 ) ,
V_192 ,
V_193 ,
V_194 , 0 ,
V_195 , V_196 ,
& V_197 ,
V_198 | V_199 |
V_200 ) ;
if ( ! exp -> V_190 )
RETURN ( - V_43 ) ;
RETURN ( 0 ) ;
}
void F_121 ( struct V_189 * exp )
{
V_11 ;
F_122 ( exp -> V_190 ) ;
exp -> V_190 = NULL ;
F_123 ( exp ) ;
EXIT ;
}
static int F_103 ( void )
{
static struct V_201 V_202 ;
struct V_69 * V_70 = NULL ;
int V_28 = 0 ;
int V_203 ;
V_11 ;
if ( V_71 != NULL )
RETURN ( - V_204 ) ;
F_24 ( V_71 , sizeof( * V_71 ) ) ;
if ( V_71 == NULL )
RETURN ( - V_43 ) ;
#ifdef F_124
V_28 = F_125 () ;
if ( V_28 != 0 )
GOTO ( V_38 , V_28 ) ;
#endif
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 = ( F_126 ( V_202 ) ) {
. V_205 = L_48 ,
. V_206 = 2 ,
. V_207 = {
. V_208 = V_209 ,
. V_210 = V_211 ,
. V_212 = V_213 ,
. V_214 = V_215 ,
. V_216 = V_217 ,
. V_218 = V_219 ,
} ,
. V_220 = {
. V_221 = L_49 ,
. V_222 = V_223 ,
. V_224 = V_225 ,
. V_226 = V_227 ,
. V_228 = V_229 ,
. V_230 = V_231 ,
. V_232 = 1 ,
. V_233 = V_234 | V_235 ,
} ,
. V_236 = {
. V_237 = V_238 ,
} ,
. V_239 = {
. V_240 = F_68 ,
} ,
} ;
V_71 -> V_241 = \
F_127 ( & V_202 , V_242 ) ;
if ( F_89 ( V_71 -> V_241 ) ) {
F_28 ( L_50 ) ;
V_28 = F_90 ( V_71 -> V_241 ) ;
V_71 -> V_241 = NULL ;
GOTO ( V_38 , V_28 ) ;
}
F_24 ( V_70 , sizeof( * V_70 ) ) ;
if ( V_70 == NULL )
GOTO ( V_38 , V_28 = - V_43 ) ;
V_71 -> V_69 = V_70 ;
F_128 ( & V_70 -> V_72 ) ;
F_52 ( & V_70 -> V_77 ) ;
F_52 ( & V_70 -> V_76 ) ;
F_129 ( & V_70 -> V_78 ) ;
F_130 ( & V_70 -> V_164 , 0 ) ;
F_130 ( & V_70 -> V_174 , 0 ) ;
if ( V_231 == 0 ) {
V_70 -> V_243 = V_225 ;
V_70 -> V_178 = V_229 ;
} else {
V_70 -> V_243 = V_70 -> V_178 = \
F_131 ( int , V_229 , F_132 ( int , V_225 ,
V_231 ) ) ;
}
for ( V_203 = 0 ; V_203 < V_70 -> V_243 ; V_203 ++ ) {
V_28 = F_87 ( V_70 ) ;
if ( V_28 < 0 )
GOTO ( V_38 , V_28 ) ;
}
V_28 = F_133 () ;
if ( V_28 ) {
F_28 ( L_51 , V_28 ) ;
GOTO ( V_38 , V_28 ) ;
}
RETURN ( 0 ) ;
V_38:
F_106 () ;
RETURN ( V_28 ) ;
}
static int F_106 ( void )
{
V_11 ;
if ( ! F_83 ( F_134 ( V_244 ) ) ||
! F_83 ( F_134 ( V_245 ) ) ) {
F_28 ( L_52 ) ;
F_135 ( V_244 , V_18 ) ;
F_135 ( V_245 , V_18 ) ;
RETURN ( - V_246 ) ;
}
F_136 () ;
if ( V_71 -> V_69 != NULL ) {
struct V_69 * V_70 = V_71 -> V_69 ;
while ( F_85 ( & V_70 -> V_164 ) > 0 ) {
struct V_66 V_67 = { . V_86 = NULL } ;
F_51 ( & V_70 -> V_180 ) ;
F_46 ( & V_70 -> V_72 ) ;
F_47 ( & V_67 . V_75 , & V_70 -> V_77 ) ;
F_35 ( & V_70 -> V_78 ) ;
F_48 ( & V_70 -> V_72 ) ;
F_49 ( & V_70 -> V_180 ) ;
}
F_100 ( V_70 , sizeof( * V_70 ) ) ;
}
if ( V_71 -> V_241 != NULL )
F_137 ( V_71 -> V_241 ) ;
F_138 () ;
F_100 ( V_71 , sizeof( * V_71 ) ) ;
V_71 = NULL ;
RETURN ( 0 ) ;
}
int F_139 ( void )
{
F_140 ( & V_181 ) ;
F_140 ( F_141 ( V_244 ) ) ;
F_140 ( F_141 ( V_245 ) ) ;
V_247 = F_142 ( L_53 ,
sizeof( struct V_248 ) , 0 ,
V_249 , NULL ) ;
if ( V_247 == NULL )
return - V_43 ;
V_250 = F_142 ( L_54 ,
sizeof( struct V_4 ) , 0 ,
V_249 | V_251 , NULL ) ;
if ( V_250 == NULL ) {
F_143 ( V_247 ) ;
return - V_43 ;
}
V_252 = F_142 ( L_55 ,
sizeof( struct V_253 ) ,
0 , V_249 , NULL ) ;
if ( V_252 == NULL ) {
F_143 ( V_247 ) ;
F_143 ( V_250 ) ;
return - V_43 ;
}
#if V_254
V_255 = V_256 ;
#endif
return 0 ;
}
void F_144 ( void )
{
if ( V_182 )
F_28 ( L_56 , V_182 ) ;
F_143 ( V_247 ) ;
F_145 () ;
F_143 ( V_250 ) ;
F_143 ( V_252 ) ;
}
