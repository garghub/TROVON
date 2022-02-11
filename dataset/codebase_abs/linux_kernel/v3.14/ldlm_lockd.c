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
return 0 ;
}
int F_8 ( struct V_4 * V_5 , int V_1 )
{
return 0 ;
}
void F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_10 ;
F_10 ( V_5 , L_1 ) ;
F_11 ( V_5 ) ;
V_5 -> V_11 |= V_12 ;
if ( V_5 -> V_11 & V_13 )
V_5 -> V_11 |= V_14 ;
V_10 = ( ! V_5 -> V_15 && ! V_5 -> V_16 ) ;
F_12 ( V_5 ) ;
if ( V_10 ) {
F_13 ( V_17 , L_2 ,
V_5 , V_5 -> V_18 ) ;
if ( V_5 -> V_18 != NULL )
V_5 -> V_18 ( V_5 , V_9 , V_5 -> V_19 ,
V_20 ) ;
} else {
F_13 ( V_17 , L_3 ,
V_5 ) ;
}
F_10 ( V_5 , L_4 ) ;
F_14 ( V_5 ) ;
}
static void F_15 ( struct V_21 * V_22 ,
struct V_6 * V_7 ,
struct V_23 * V_24 ,
struct V_4 * V_5 )
{
int V_25 ;
F_16 ( V_26 ) ;
int V_27 = 0 ;
F_10 ( V_5 , L_5 ) ;
if ( F_17 ( V_28 ) ) {
int V_29 = F_2 ( 1 ) ;
while ( V_29 > 0 ) {
F_18 (
V_30 , V_29 ) ;
if ( V_5 -> V_31 == V_5 -> V_32 ||
V_5 -> V_11 & V_33 )
break;
}
}
V_25 = F_19 ( & V_22 -> V_34 , & V_35 , V_36 ) ;
if ( V_25 < 0 ) {
F_20 ( V_5 , L_6 , V_25 ) ;
GOTO ( V_37 , V_27 = V_25 ) ;
} else if ( V_25 > 0 ) {
if ( V_5 -> V_38 > 0 ) {
F_21 ( V_5 -> V_39 != NULL ) ;
if ( F_22 ( V_5 -> V_38 < V_25 ) ) {
F_20 ( V_5 , L_7
L_8
L_9 ,
V_5 -> V_38 , V_25 ) ;
GOTO ( V_37 , V_27 = - V_40 ) ;
}
} else if ( F_23 ( V_5 ) ) {
void * V_41 ;
F_24 ( V_41 , V_25 ) ;
if ( V_41 == NULL ) {
F_20 ( V_5 , L_10 , V_25 ) ;
GOTO ( V_37 , V_27 = - V_42 ) ;
}
F_11 ( V_5 ) ;
F_21 ( V_5 -> V_39 == NULL ) ;
V_5 -> V_39 = V_41 ;
V_5 -> V_38 = V_25 ;
F_12 ( V_5 ) ;
}
}
F_11 ( V_5 ) ;
if ( ( V_5 -> V_11 & V_33 ) ||
V_5 -> V_31 == V_5 -> V_32 ) {
F_12 ( V_5 ) ;
F_10 ( V_5 , L_11 ) ;
GOTO ( V_37 , V_27 = 0 ) ;
}
if ( V_24 -> V_43 . V_31 != V_5 -> V_32 ) {
V_5 -> V_32 = V_24 -> V_43 . V_31 ;
F_10 ( V_5 , L_12 ) ;
}
if ( V_5 -> V_44 -> V_45 != V_46 ) {
F_25 ( V_22 -> V_47 ,
V_24 -> V_43 . V_44 . V_45 ,
& V_24 -> V_43 . V_48 ,
& V_5 -> V_48 ) ;
F_10 ( V_5 , L_13 ) ;
}
F_26 ( V_5 ) ;
if ( memcmp ( & V_24 -> V_43 . V_44 . V_49 ,
& V_5 -> V_44 -> V_49 ,
sizeof( V_5 -> V_44 -> V_49 ) ) != 0 ) {
F_12 ( V_5 ) ;
V_27 = F_27 ( V_7 , V_5 ,
& V_24 -> V_43 . V_44 . V_49 ) ;
if ( V_27 < 0 ) {
F_20 ( V_5 , L_14 ) ;
GOTO ( V_37 , V_27 ) ;
}
F_10 ( V_5 , L_15 ) ;
F_28 ( L_16 ) ;
F_11 ( V_5 ) ;
}
if ( V_24 -> V_50 & V_51 ) {
F_29 ( V_5 ) ;
V_5 -> V_11 |= V_12 | V_52 ;
F_10 ( V_5 , L_17 ) ;
}
if ( V_5 -> V_38 > 0 ) {
V_27 = F_30 ( V_5 , & V_22 -> V_34 , V_36 ,
V_5 -> V_39 , V_25 ) ;
if ( V_27 < 0 ) {
F_12 ( V_5 ) ;
GOTO ( V_37 , V_27 ) ;
}
}
F_31 ( V_5 , & V_26 ) ;
F_12 ( V_5 ) ;
F_10 ( V_5 , L_18 ) ;
F_32 ( V_53 , 2 ) ;
F_33 ( V_7 , & V_26 , V_54 ) ;
F_34 ( L_19 ,
V_5 ) ;
GOTO ( V_37 , V_27 ) ;
V_37:
if ( V_27 < 0 ) {
F_11 ( V_5 ) ;
V_5 -> V_11 |= V_55 ;
F_12 ( V_5 ) ;
F_35 ( & V_5 -> V_56 ) ;
}
F_14 ( V_5 ) ;
}
static void F_36 ( struct V_21 * V_22 ,
struct V_6 * V_7 ,
struct V_23 * V_24 ,
struct V_4 * V_5 )
{
int V_27 = - V_57 ;
F_10 ( V_5 , L_20 ) ;
if ( V_5 -> V_58 != NULL )
V_27 = V_5 -> V_58 ( V_5 , V_22 ) ;
if ( V_22 -> V_59 != NULL ) {
F_37 ( V_22 ) ;
} else {
V_22 -> V_60 = V_27 ;
F_38 ( V_22 ) ;
}
F_11 ( V_5 ) ;
if ( V_5 -> V_31 == V_61 &&
! V_5 -> V_15 && ! V_5 -> V_16 &&
F_39 ( F_40 () ,
F_41 ( V_5 -> V_62 ,
F_2 ( 10 ) ) ) ) {
F_12 ( V_5 ) ;
if ( F_42 ( V_7 , NULL , V_5 ) )
F_9 ( V_7 , NULL , V_5 ) ;
return;
}
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
}
static int F_43 ( struct V_21 * V_22 , int V_27 )
{
if ( V_22 -> V_63 )
return 0 ;
V_22 -> V_60 = V_27 ;
if ( ! V_22 -> V_64 ) {
V_27 = F_44 ( V_22 , 1 , NULL , NULL ) ;
if ( V_27 )
return V_27 ;
}
return F_37 ( V_22 ) ;
}
static int F_45 ( struct V_65 * V_66 ,
T_2 V_67 )
{
struct V_68 * V_69 = V_70 -> V_68 ;
F_46 ( & V_69 -> V_71 ) ;
if ( V_66 -> V_72 &&
V_66 -> V_72 -> V_11 & V_73 ) {
F_47 ( & V_66 -> V_74 , & V_69 -> V_75 ) ;
} else {
F_47 ( & V_66 -> V_74 , & V_69 -> V_76 ) ;
}
F_48 ( & V_69 -> V_71 ) ;
F_35 ( & V_69 -> V_77 ) ;
if ( ! ( V_67 & V_78 ) )
F_49 ( & V_66 -> V_79 ) ;
return 0 ;
}
static inline void F_50 ( struct V_65 * V_66 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_80 * V_81 , int V_82 ,
struct V_4 * V_5 ,
T_2 V_67 )
{
F_51 ( & V_66 -> V_79 ) ;
F_52 ( & V_66 -> V_83 ) ;
if ( F_53 () )
V_66 -> V_84 = 1 ;
V_66 -> V_85 = V_7 ;
V_66 -> V_86 = V_67 ;
if ( V_9 != NULL )
V_66 -> V_87 = * V_9 ;
if ( V_82 ) {
F_54 ( & V_66 -> V_83 , V_81 ) ;
F_55 ( V_81 ) ;
V_66 -> V_88 = V_82 ;
} else {
V_66 -> V_72 = V_5 ;
}
}
static int F_56 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_4 * V_5 ,
struct V_80 * V_81 , int V_82 ,
T_2 V_67 )
{
if ( V_81 && V_82 == 0 )
return 0 ;
if ( V_67 & V_78 ) {
struct V_65 * V_66 ;
F_24 ( V_66 , sizeof( * V_66 ) ) ;
if ( V_66 == NULL )
return - V_42 ;
F_50 ( V_66 , V_7 , V_9 , V_81 , V_82 , V_5 , V_67 ) ;
return F_45 ( V_66 , V_67 ) ;
} else {
struct V_65 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_50 ( & V_66 , V_7 , V_9 , V_81 , V_82 , V_5 , V_67 ) ;
return F_45 ( & V_66 , V_67 ) ;
}
}
int F_42 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_4 * V_5 )
{
return F_56 ( V_7 , V_9 , V_5 , NULL , 0 , V_78 ) ;
}
int F_57 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_80 * V_81 , int V_82 ,
T_2 V_67 )
{
return F_56 ( V_7 , V_9 , NULL , V_81 , V_82 , V_67 ) ;
}
static int F_58 ( struct V_21 * V_22 )
{
struct V_89 * V_90 = V_22 -> V_47 -> V_91 ;
char * V_92 ;
void * V_93 ;
int V_94 , V_95 ;
int V_27 = - V_57 ;
F_59 ( V_96 , V_22 , L_21 , V_90 -> V_97 ) ;
F_60 ( & V_22 -> V_34 , & V_98 ) ;
V_92 = F_61 ( & V_22 -> V_34 , & V_99 ) ;
if ( V_92 == NULL ) {
F_59 ( V_100 , V_22 , L_22 ) ;
return - V_101 ;
}
V_94 = F_19 ( & V_22 -> V_34 , & V_99 ,
V_36 ) ;
V_93 = F_61 ( & V_22 -> V_34 , & V_102 ) ;
if ( V_93 == NULL ) {
F_59 ( V_100 , V_22 , L_23 ) ;
return - V_101 ;
}
V_95 = F_19 ( & V_22 -> V_34 , & V_102 ,
V_36 ) ;
if ( F_62 ( V_103 ) )
V_27 = F_63 ( V_22 -> V_104 -> V_105 ,
V_22 -> V_47 ,
sizeof( V_103 ) ,
V_103 ,
V_95 , V_93 , NULL ) ;
else
F_59 ( V_106 , V_22 , L_24 , V_92 ) ;
return V_27 ;
}
static inline void F_64 ( struct V_21 * V_22 ,
const char * V_107 , int V_27 ,
struct V_108 * V_109 )
{
F_59 ( ( V_22 -> V_63 || V_27 ) ? V_106 : V_17 , V_22 ,
L_25 V_110 L_26 ,
V_107 , F_65 ( V_22 -> V_111 ) , V_27 ,
V_109 ? V_109 -> V_112 : 0 ) ;
if ( V_22 -> V_63 )
F_66 ( L_27 ) ;
else if ( V_27 )
F_66 ( L_28 ) ;
}
static int F_67 ( struct V_21 * V_22 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 = & V_22 -> V_47 -> V_91 -> V_117 . V_116 ;
V_114 = F_61 ( & V_22 -> V_34 , & V_118 ) ;
if ( V_114 == NULL ) {
F_28 ( L_29 ) ;
return - V_119 ;
}
V_114 -> V_120 = F_68 ( V_114 -> V_120 ) ;
V_116 -> V_121 = V_114 -> V_120 ;
return 0 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
int V_27 ;
if ( F_70 ( V_22 -> V_122 ) == V_123 )
return 0 ;
F_71 ( & V_22 -> V_34 , V_22 , V_124 ) ;
if ( V_22 -> V_47 == NULL ) {
V_27 = F_43 ( V_22 , - V_125 ) ;
F_64 ( V_22 , L_30 ,
V_27 , NULL ) ;
return 0 ;
}
F_21 ( V_22 -> V_47 != NULL ) ;
F_21 ( V_22 -> V_47 -> V_91 != NULL ) ;
switch ( F_70 ( V_22 -> V_122 ) ) {
case V_126 :
if ( F_17 ( V_127 ) )
return 0 ;
break;
case V_128 :
if ( F_17 ( V_129 ) )
return 0 ;
break;
case V_130 :
if ( F_17 ( V_131 ) )
return 0 ;
break;
case V_132 :
V_27 = F_58 ( V_22 ) ;
F_43 ( V_22 , V_27 ) ;
return 0 ;
case V_133 :
F_60 ( & V_22 -> V_34 , & V_134 ) ;
if ( F_17 ( V_135 ) )
return 0 ;
V_27 = F_67 ( V_22 ) ;
F_43 ( V_22 , V_27 ) ;
return 0 ;
default:
F_28 ( L_31 ,
F_70 ( V_22 -> V_122 ) ) ;
F_43 ( V_22 , - V_119 ) ;
return 0 ;
}
V_7 = V_22 -> V_47 -> V_91 -> V_136 ;
F_21 ( V_7 != NULL ) ;
F_60 ( & V_22 -> V_34 , & V_137 ) ;
V_24 = F_61 ( & V_22 -> V_34 , & V_138 ) ;
if ( V_24 == NULL ) {
V_27 = F_43 ( V_22 , - V_119 ) ;
F_64 ( V_22 , L_32 , V_27 ,
NULL ) ;
return 0 ;
}
if ( F_17 ( V_28 ) &&
F_70 ( V_22 -> V_122 ) == V_126 ) {
V_27 = F_72 ( & V_24 -> V_139 [ 0 ] , 0 ) ;
if ( V_27 < 0 )
F_28 ( L_33 , V_27 ) ;
}
V_5 = F_73 ( & V_24 -> V_139 [ 0 ] , 0 ) ;
if ( ! V_5 ) {
F_13 ( V_17 , L_34 V_110 L_35
L_36 , V_24 -> V_139 [ 0 ] . V_112 ) ;
V_27 = F_43 ( V_22 , - V_40 ) ;
F_64 ( V_22 , L_37 , V_27 ,
& V_24 -> V_139 [ 0 ] ) ;
return 0 ;
}
if ( ( V_5 -> V_11 & V_140 ) &&
F_70 ( V_22 -> V_122 ) == V_126 )
F_74 ( V_141 ) ;
F_11 ( V_5 ) ;
V_5 -> V_11 |= F_75 ( V_24 -> V_50 &
V_142 ) ;
if ( F_70 ( V_22 -> V_122 ) == V_126 ) {
if ( ( ( V_5 -> V_11 & V_143 ) &&
( V_5 -> V_11 & V_144 ) ) ||
( V_5 -> V_11 & V_55 ) ) {
F_10 ( V_5 , L_34
V_110 L_38 ,
V_24 -> V_139 [ 0 ] . V_112 ) ;
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
V_27 = F_43 ( V_22 , - V_40 ) ;
F_64 ( V_22 , L_39 , V_27 ,
& V_24 -> V_139 [ 0 ] ) ;
return 0 ;
}
F_29 ( V_5 ) ;
V_5 -> V_11 |= V_52 ;
}
F_12 ( V_5 ) ;
switch ( F_70 ( V_22 -> V_122 ) ) {
case V_126 :
F_13 ( V_145 , L_40 ) ;
F_76 ( & V_22 -> V_34 , & V_146 ) ;
if ( ! ( V_5 -> V_11 & V_13 ) ) {
V_27 = F_43 ( V_22 , 0 ) ;
if ( V_22 -> V_63 || V_27 )
F_64 ( V_22 , L_41 , V_27 ,
& V_24 -> V_139 [ 0 ] ) ;
}
if ( F_42 ( V_7 , & V_24 -> V_43 , V_5 ) )
F_9 ( V_7 , & V_24 -> V_43 , V_5 ) ;
break;
case V_128 :
F_13 ( V_145 , L_42 ) ;
F_76 ( & V_22 -> V_34 , & V_147 ) ;
F_43 ( V_22 , 0 ) ;
F_15 ( V_22 , V_7 , V_24 , V_5 ) ;
break;
case V_130 :
F_13 ( V_145 , L_43 ) ;
F_76 ( & V_22 -> V_34 , & V_148 ) ;
F_36 ( V_22 , V_7 , V_24 , V_5 ) ;
break;
default:
F_77 () ;
}
return 0 ;
}
static struct V_65 * F_78 ( struct V_68 * V_69 )
{
struct V_65 * V_66 = NULL ;
static unsigned int V_149 = 0 ;
F_46 ( & V_69 -> V_71 ) ;
if ( ! F_79 ( & V_69 -> V_76 ) &&
( F_79 ( & V_69 -> V_75 ) || V_149 == 0 ) )
V_66 = F_80 ( V_69 -> V_76 . V_150 ,
struct V_65 , V_74 ) ;
else
if ( ! F_79 ( & V_69 -> V_75 ) )
V_66 = F_80 ( V_69 -> V_75 . V_150 ,
struct V_65 ,
V_74 ) ;
if ( V_66 ) {
if ( ++ V_149 >= F_81 ( & V_69 -> V_151 ) )
V_149 = 0 ;
F_82 ( & V_66 -> V_74 ) ;
}
F_48 ( & V_69 -> V_71 ) ;
return V_66 ;
}
static int F_83 ( struct V_68 * V_69 )
{
struct V_152 V_153 = { . V_154 = V_69 } ;
struct V_155 * V_156 ;
F_51 ( & V_153 . V_157 ) ;
V_153 . V_158 = F_81 ( & V_69 -> V_151 ) ;
snprintf ( V_153 . V_159 , sizeof( V_153 . V_159 ) ,
L_44 , V_153 . V_158 ) ;
V_156 = F_84 ( V_160 , & V_153 , L_45 , V_153 . V_159 ) ;
if ( F_85 ( V_156 ) ) {
F_28 ( L_46 ,
F_81 ( & V_69 -> V_151 ) , F_86 ( V_156 ) ) ;
return F_86 ( V_156 ) ;
}
F_49 ( & V_153 . V_157 ) ;
return 0 ;
}
static int V_160 ( void * V_161 )
{
struct V_68 * V_69 ;
{
struct V_152 * V_153 = V_161 ;
V_69 = V_153 -> V_154 ;
F_87 ( & V_69 -> V_151 ) ;
F_87 ( & V_69 -> V_162 ) ;
F_88 ( & V_153 -> V_157 ) ;
}
while ( 1 ) {
struct V_163 V_164 = { 0 } ;
struct V_65 * V_66 = NULL ;
int V_165 ;
V_66 = F_78 ( V_69 ) ;
if ( V_66 == NULL ) {
F_89 ( & V_69 -> V_162 ) ;
F_90 ( V_69 -> V_77 ,
( V_66 = F_78 ( V_69 ) ) != NULL ,
& V_164 ) ;
V_165 = F_91 ( & V_69 -> V_162 ) ;
} else {
V_165 = F_81 ( & V_69 -> V_162 ) ;
}
if ( V_66 -> V_85 == NULL )
break;
if ( F_22 ( V_165 < V_69 -> V_166 &&
V_165 >= F_81 ( & V_69 -> V_151 ) &&
! V_66 -> V_84 ) )
F_83 ( V_69 ) ;
if ( V_66 -> V_84 )
F_92 () ;
if ( V_66 -> V_88 ) {
int V_82 ;
V_82 = F_93 ( & V_66 -> V_83 ,
V_66 -> V_88 ,
V_167 ) ;
F_94 ( & V_66 -> V_83 , V_82 , NULL ,
V_66 -> V_86 ) ;
} else {
F_9 ( V_66 -> V_85 , & V_66 -> V_87 ,
V_66 -> V_72 ) ;
}
if ( V_66 -> V_84 )
F_95 () ;
if ( V_66 -> V_86 & V_78 )
F_96 ( V_66 , sizeof( * V_66 ) ) ;
else
F_88 ( & V_66 -> V_79 ) ;
}
F_89 ( & V_69 -> V_162 ) ;
F_89 ( & V_69 -> V_151 ) ;
F_88 ( & V_69 -> V_168 ) ;
return 0 ;
}
int F_97 ( void )
{
int V_27 = 0 ;
F_98 ( & V_169 ) ;
if ( ++ V_170 == 1 ) {
V_27 = F_99 () ;
if ( V_27 )
V_170 -- ;
}
F_100 ( & V_169 ) ;
return V_27 ;
}
void F_101 ( void )
{
F_98 ( & V_169 ) ;
if ( V_170 == 1 ) {
int V_27 = F_102 () ;
if ( V_27 )
F_28 ( L_47 , V_27 ) ;
else
V_170 -- ;
} else {
V_170 -- ;
}
F_100 ( & V_169 ) ;
}
static unsigned
F_103 ( struct V_171 * V_172 , const void * V_92 , unsigned V_173 )
{
return F_104 ( ( (struct V_108 * ) V_92 ) -> V_112 , V_173 ) ;
}
static void *
F_105 ( struct V_174 * V_175 )
{
struct V_4 * V_5 ;
V_5 = F_106 ( V_175 , struct V_4 , V_176 ) ;
return & V_5 -> V_177 ;
}
static void
F_107 ( struct V_174 * V_175 , void * V_92 )
{
struct V_4 * V_5 ;
V_5 = F_106 ( V_175 , struct V_4 , V_176 ) ;
V_5 -> V_177 = * (struct V_108 * ) V_92 ;
}
static int
F_108 ( const void * V_92 , struct V_174 * V_175 )
{
return F_109 ( F_105 ( V_175 ) , V_92 ) ;
}
static void *
F_110 ( struct V_174 * V_175 )
{
return F_106 ( V_175 , struct V_4 , V_176 ) ;
}
static void
F_111 ( struct V_171 * V_172 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
V_5 = F_106 ( V_175 , struct V_4 , V_176 ) ;
F_112 ( V_5 ) ;
}
static void
F_113 ( struct V_171 * V_172 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
V_5 = F_106 ( V_175 , struct V_4 , V_176 ) ;
F_14 ( V_5 ) ;
}
int F_114 ( struct V_178 * exp )
{
int V_27 ;
exp -> V_179 =
F_115 ( F_116 ( & exp -> V_180 ) ,
V_181 ,
V_182 ,
V_183 , 0 ,
V_184 , V_185 ,
& V_186 ,
V_187 | V_188 |
V_189 ) ;
if ( ! exp -> V_179 )
return - V_42 ;
V_27 = F_117 ( exp ) ;
if ( V_27 )
GOTO ( V_190 , V_27 ) ;
return 0 ;
V_190:
F_118 ( exp ) ;
return V_27 ;
}
void F_118 ( struct V_178 * exp )
{
F_119 ( exp -> V_179 ) ;
exp -> V_179 = NULL ;
F_120 ( exp ) ;
}
static int F_99 ( void )
{
static struct V_191 V_192 ;
struct V_68 * V_69 = NULL ;
int V_27 = 0 ;
int V_193 ;
if ( V_70 != NULL )
return - V_194 ;
F_24 ( V_70 , sizeof( * V_70 ) ) ;
if ( V_70 == NULL )
return - V_42 ;
V_27 = F_121 () ;
if ( V_27 != 0 )
GOTO ( V_37 , V_27 ) ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 = ( F_122 ( V_192 ) ) {
. V_195 = L_48 ,
. V_196 = 2 ,
. V_197 = {
. V_198 = V_199 ,
. V_200 = V_201 ,
. V_202 = V_203 ,
. V_204 = V_205 ,
. V_206 = V_207 ,
. V_208 = V_209 ,
} ,
. V_210 = {
. V_211 = L_49 ,
. V_212 = V_213 ,
. V_214 = V_215 ,
. V_216 = V_217 ,
. V_218 = V_219 ,
. V_220 = V_221 ,
. V_222 = 1 ,
. V_223 = V_224 | V_225 ,
} ,
. V_226 = {
. V_227 = V_228 ,
} ,
. V_229 = {
. V_230 = F_69 ,
} ,
} ;
V_70 -> V_231 = \
F_123 ( & V_192 , V_232 ) ;
if ( F_85 ( V_70 -> V_231 ) ) {
F_28 ( L_50 ) ;
V_27 = F_86 ( V_70 -> V_231 ) ;
V_70 -> V_231 = NULL ;
GOTO ( V_37 , V_27 ) ;
}
F_24 ( V_69 , sizeof( * V_69 ) ) ;
if ( V_69 == NULL )
GOTO ( V_37 , V_27 = - V_42 ) ;
V_70 -> V_68 = V_69 ;
F_124 ( & V_69 -> V_71 ) ;
F_52 ( & V_69 -> V_76 ) ;
F_52 ( & V_69 -> V_75 ) ;
F_125 ( & V_69 -> V_77 ) ;
F_126 ( & V_69 -> V_151 , 0 ) ;
F_126 ( & V_69 -> V_162 , 0 ) ;
if ( V_221 == 0 ) {
V_69 -> V_233 = V_215 ;
V_69 -> V_166 = V_219 ;
} else {
V_69 -> V_233 = V_69 -> V_166 = \
F_127 ( int , V_219 , F_128 ( int , V_215 ,
V_221 ) ) ;
}
for ( V_193 = 0 ; V_193 < V_69 -> V_233 ; V_193 ++ ) {
V_27 = F_83 ( V_69 ) ;
if ( V_27 < 0 )
GOTO ( V_37 , V_27 ) ;
}
V_27 = F_129 () ;
if ( V_27 ) {
F_28 ( L_51 , V_27 ) ;
GOTO ( V_37 , V_27 ) ;
}
return 0 ;
V_37:
F_102 () ;
return V_27 ;
}
static int F_102 ( void )
{
if ( ! F_79 ( F_130 ( V_234 ) ) ||
! F_79 ( F_130 ( V_235 ) ) ) {
F_28 ( L_52 ) ;
F_131 ( V_234 , V_17 ) ;
F_131 ( V_235 , V_17 ) ;
return - V_236 ;
}
F_132 () ;
if ( V_70 -> V_68 != NULL ) {
struct V_68 * V_69 = V_70 -> V_68 ;
while ( F_81 ( & V_69 -> V_151 ) > 0 ) {
struct V_65 V_66 = { . V_85 = NULL } ;
F_51 ( & V_69 -> V_168 ) ;
F_46 ( & V_69 -> V_71 ) ;
F_47 ( & V_66 . V_74 , & V_69 -> V_76 ) ;
F_35 ( & V_69 -> V_77 ) ;
F_48 ( & V_69 -> V_71 ) ;
F_49 ( & V_69 -> V_168 ) ;
}
F_96 ( V_69 , sizeof( * V_69 ) ) ;
}
if ( V_70 -> V_231 != NULL )
F_133 ( V_70 -> V_231 ) ;
F_134 () ;
F_96 ( V_70 , sizeof( * V_70 ) ) ;
V_70 = NULL ;
return 0 ;
}
int F_135 ( void )
{
F_136 ( & V_169 ) ;
F_136 ( F_137 ( V_234 ) ) ;
F_136 ( F_137 ( V_235 ) ) ;
V_237 = F_138 ( L_53 ,
sizeof( struct V_238 ) , 0 ,
V_239 , NULL ) ;
if ( V_237 == NULL )
return - V_42 ;
V_240 = F_138 ( L_54 ,
sizeof( struct V_4 ) , 0 ,
V_239 | V_241 , NULL ) ;
if ( V_240 == NULL ) {
F_139 ( V_237 ) ;
return - V_42 ;
}
V_242 = F_138 ( L_55 ,
sizeof( struct V_243 ) ,
0 , V_239 , NULL ) ;
if ( V_242 == NULL ) {
F_139 ( V_237 ) ;
F_139 ( V_240 ) ;
return - V_42 ;
}
#if V_244
V_245 = V_246 ;
#endif
return 0 ;
}
void F_140 ( void )
{
if ( V_170 )
F_28 ( L_56 , V_170 ) ;
F_139 ( V_237 ) ;
F_141 () ;
F_139 ( V_240 ) ;
F_139 ( V_242 ) ;
}
