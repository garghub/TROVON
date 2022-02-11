inline unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( ( int ) F_3 ( F_4 ( V_1 , 0 ) ) + 1 ) ;
}
int F_5 ( struct V_2 * V_3 )
{
return 0 ;
}
int F_6 ( struct V_2 * V_3 , int V_1 )
{
return 0 ;
}
void F_7 ( struct V_4 * V_5 ,
struct V_6 * V_7 , struct V_2 * V_3 )
{
int V_8 ;
F_8 ( V_3 , L_1 ) ;
F_9 ( V_3 ) ;
V_3 -> V_9 |= V_10 ;
if ( V_3 -> V_9 & V_11 )
V_3 -> V_9 |= V_12 ;
V_8 = ! V_3 -> V_13 && ! V_3 -> V_14 ;
F_10 ( V_3 ) ;
if ( V_8 ) {
F_11 ( V_15 ,
L_2 , V_3 ,
V_3 -> V_16 ) ;
if ( V_3 -> V_16 != NULL )
V_3 -> V_16 ( V_3 , V_7 , V_3 -> V_17 ,
V_18 ) ;
} else {
F_11 ( V_15 ,
L_3 ,
V_3 ) ;
}
F_8 ( V_3 , L_4 ) ;
F_12 ( V_3 ) ;
}
static void F_13 ( struct V_19 * V_20 ,
struct V_4 * V_5 ,
struct V_21 * V_22 ,
struct V_2 * V_3 )
{
int V_23 ;
F_14 ( V_24 ) ;
int V_25 = 0 ;
F_8 ( V_3 , L_5 ) ;
if ( F_15 ( V_26 ) ) {
int V_27 = F_2 ( 1 ) ;
while ( V_27 > 0 ) {
F_16 ( V_28 ) ;
F_17 ( V_27 ) ;
if ( V_3 -> V_29 == V_3 -> V_30 ||
V_3 -> V_9 & V_31 )
break;
}
}
V_23 = F_18 ( & V_20 -> V_32 , & V_33 , V_34 ) ;
if ( V_23 < 0 ) {
F_19 ( V_3 , L_6 , V_23 ) ;
V_25 = V_23 ;
goto V_35;
} else if ( V_23 > 0 ) {
if ( V_3 -> V_36 > 0 ) {
F_20 ( V_3 -> V_37 != NULL ) ;
if ( F_21 ( V_3 -> V_36 < V_23 ) ) {
F_19 ( V_3 , L_7 ,
V_3 -> V_36 , V_23 ) ;
V_25 = - V_38 ;
goto V_35;
}
} else if ( F_22 ( V_3 ) ) {
void * V_39 ;
V_39 = F_23 ( V_23 , V_40 ) ;
if ( ! V_39 ) {
F_19 ( V_3 , L_8 , V_23 ) ;
V_25 = - V_41 ;
goto V_35;
}
F_9 ( V_3 ) ;
F_20 ( V_3 -> V_37 == NULL ) ;
V_3 -> V_42 = V_43 ;
V_3 -> V_37 = V_39 ;
V_3 -> V_36 = V_23 ;
F_10 ( V_3 ) ;
}
}
F_9 ( V_3 ) ;
if ( ( V_3 -> V_9 & V_31 ) ||
V_3 -> V_29 == V_3 -> V_30 ) {
F_10 ( V_3 ) ;
F_8 ( V_3 , L_9 ) ;
V_25 = 0 ;
goto V_35;
}
if ( V_22 -> V_44 . V_29 != V_3 -> V_30 ) {
V_3 -> V_30 = V_22 -> V_44 . V_29 ;
F_8 ( V_3 , L_10 ) ;
}
if ( V_3 -> V_45 -> V_46 != V_47 ) {
F_24 ( V_20 -> V_48 ,
V_22 -> V_44 . V_45 . V_46 ,
& V_22 -> V_44 . V_49 ,
& V_3 -> V_49 ) ;
F_8 ( V_3 , L_11 ) ;
}
F_25 ( V_3 ) ;
if ( memcmp ( & V_22 -> V_44 . V_45 . V_50 ,
& V_3 -> V_45 -> V_50 ,
sizeof( V_3 -> V_45 -> V_50 ) ) != 0 ) {
F_10 ( V_3 ) ;
V_25 = F_26 ( V_5 , V_3 ,
& V_22 -> V_44 . V_45 . V_50 ) ;
if ( V_25 < 0 ) {
F_19 ( V_3 , L_12 ) ;
goto V_35;
}
F_8 ( V_3 , L_13 ) ;
F_27 ( L_14 ) ;
F_9 ( V_3 ) ;
}
if ( V_22 -> V_51 & V_52 ) {
F_28 ( V_3 ) ;
V_3 -> V_9 |= V_10 | V_53 ;
F_8 ( V_3 , L_15 ) ;
}
if ( V_3 -> V_36 > 0 ) {
V_25 = F_29 ( V_3 , & V_20 -> V_32 , V_34 ,
V_3 -> V_37 , V_23 ) ;
if ( V_25 < 0 ) {
F_10 ( V_3 ) ;
goto V_35;
}
}
F_30 ( V_3 , & V_24 ) ;
F_10 ( V_3 ) ;
F_8 ( V_3 , L_16 ) ;
F_31 ( V_54 , 2 ) ;
F_32 ( V_5 , & V_24 , V_55 ) ;
F_33 ( L_17 ,
V_3 ) ;
goto V_35;
V_35:
if ( V_25 < 0 ) {
F_9 ( V_3 ) ;
V_3 -> V_9 |= V_56 ;
F_10 ( V_3 ) ;
F_34 ( & V_3 -> V_57 ) ;
}
F_12 ( V_3 ) ;
}
static void F_35 ( struct V_19 * V_20 ,
struct V_4 * V_5 ,
struct V_21 * V_22 ,
struct V_2 * V_3 )
{
int V_25 = - V_58 ;
F_8 ( V_3 , L_18 ) ;
if ( V_3 -> V_59 != NULL )
V_25 = V_3 -> V_59 ( V_3 , V_20 ) ;
if ( V_20 -> V_60 != NULL ) {
F_36 ( V_20 ) ;
} else {
V_20 -> V_61 = V_25 ;
F_37 ( V_20 ) ;
}
F_9 ( V_3 ) ;
if ( V_3 -> V_29 == V_62 &&
! V_3 -> V_13 && ! V_3 -> V_14 &&
F_38 ( F_39 () ,
F_40 ( V_3 -> V_63 ,
F_2 ( 10 ) ) ) ) {
F_10 ( V_3 ) ;
if ( F_41 ( V_5 , NULL , V_3 ) )
F_7 ( V_5 , NULL , V_3 ) ;
return;
}
F_10 ( V_3 ) ;
F_12 ( V_3 ) ;
}
static int F_42 ( struct V_19 * V_20 , int V_25 )
{
if ( V_20 -> V_64 )
return 0 ;
V_20 -> V_61 = V_25 ;
if ( ! V_20 -> V_65 ) {
V_25 = F_43 ( V_20 , 1 , NULL , NULL ) ;
if ( V_25 )
return V_25 ;
}
return F_36 ( V_20 ) ;
}
static int F_44 ( struct V_66 * V_67 ,
T_1 V_68 )
{
struct V_69 * V_70 = V_71 -> V_69 ;
F_45 ( & V_70 -> V_72 ) ;
if ( V_67 -> V_73 &&
V_67 -> V_73 -> V_9 & V_74 ) {
F_46 ( & V_67 -> V_75 , & V_70 -> V_76 ) ;
} else {
F_46 ( & V_67 -> V_75 , & V_70 -> V_77 ) ;
}
F_47 ( & V_70 -> V_72 ) ;
F_34 ( & V_70 -> V_78 ) ;
if ( ! ( V_68 & V_79 ) )
F_48 ( & V_67 -> V_80 ) ;
return 0 ;
}
static inline void F_49 ( struct V_66 * V_67 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_81 * V_82 , int V_83 ,
struct V_2 * V_3 ,
T_1 V_68 )
{
F_50 ( & V_67 -> V_80 ) ;
F_51 ( & V_67 -> V_84 ) ;
if ( F_52 () )
V_67 -> V_85 = 1 ;
V_67 -> V_86 = V_5 ;
V_67 -> V_87 = V_68 ;
if ( V_7 != NULL )
V_67 -> V_88 = * V_7 ;
if ( V_83 ) {
F_53 ( & V_67 -> V_84 , V_82 ) ;
F_54 ( V_82 ) ;
V_67 -> V_89 = V_83 ;
} else {
V_67 -> V_73 = V_3 ;
}
}
static int F_55 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_2 * V_3 ,
struct V_81 * V_82 , int V_83 ,
T_1 V_68 )
{
if ( V_82 && V_83 == 0 )
return 0 ;
if ( V_68 & V_79 ) {
struct V_66 * V_67 ;
V_67 = F_23 ( sizeof( * V_67 ) , V_40 ) ;
if ( ! V_67 )
return - V_41 ;
F_49 ( V_67 , V_5 , V_7 , V_82 , V_83 , V_3 , V_68 ) ;
return F_44 ( V_67 , V_68 ) ;
} else {
struct V_66 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_49 ( & V_67 , V_5 , V_7 , V_82 , V_83 , V_3 , V_68 ) ;
return F_44 ( & V_67 , V_68 ) ;
}
}
int F_41 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_2 * V_3 )
{
return F_55 ( V_5 , V_7 , V_3 , NULL , 0 , V_79 ) ;
}
int F_56 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_81 * V_82 , int V_83 ,
T_1 V_68 )
{
return F_55 ( V_5 , V_7 , NULL , V_82 , V_83 , V_68 ) ;
}
static int F_57 ( struct V_19 * V_20 )
{
struct V_90 * V_91 = V_20 -> V_48 -> V_92 ;
char * V_93 ;
void * V_94 ;
int V_95 , V_96 ;
int V_25 = - V_58 ;
F_58 ( V_97 , V_20 , L_19 , V_91 -> V_98 ) ;
F_59 ( & V_20 -> V_32 , & V_99 ) ;
V_93 = F_60 ( & V_20 -> V_32 , & V_100 ) ;
if ( V_93 == NULL ) {
F_58 ( V_101 , V_20 , L_20 ) ;
return - V_102 ;
}
V_95 = F_18 ( & V_20 -> V_32 , & V_100 ,
V_34 ) ;
V_94 = F_60 ( & V_20 -> V_32 , & V_103 ) ;
if ( V_94 == NULL ) {
F_58 ( V_101 , V_20 , L_21 ) ;
return - V_102 ;
}
V_96 = F_18 ( & V_20 -> V_32 , & V_103 ,
V_34 ) ;
if ( F_61 ( V_104 ) )
V_25 = F_62 ( V_20 -> V_105 -> V_106 ,
V_20 -> V_48 ,
sizeof( V_104 ) ,
V_104 ,
V_96 , V_94 , NULL ) ;
else
F_58 ( V_107 , V_20 , L_22 , V_93 ) ;
return V_25 ;
}
static inline void F_63 ( struct V_19 * V_20 ,
const char * V_108 , int V_25 ,
struct V_109 * V_110 )
{
F_58 ( ( V_20 -> V_64 || V_25 ) ? V_107 : V_15 , V_20 ,
L_23 ,
V_108 , F_64 ( V_20 -> V_111 ) , V_25 ,
V_110 ? V_110 -> V_112 : 0 ) ;
if ( V_20 -> V_64 )
F_65 ( L_24 ) ;
else if ( V_25 )
F_65 ( L_25 ) ;
}
static int F_66 ( struct V_19 * V_20 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 = & V_20 -> V_48 -> V_92 -> V_117 . V_116 ;
V_114 = F_60 ( & V_20 -> V_32 , & V_118 ) ;
if ( V_114 == NULL ) {
F_27 ( L_26 ) ;
return - V_119 ;
}
V_114 -> V_120 = F_67 ( V_114 -> V_120 ) ;
V_116 -> V_121 = V_114 -> V_120 ;
return 0 ;
}
static int F_68 ( struct V_19 * V_20 )
{
struct V_4 * V_5 ;
struct V_21 * V_22 ;
struct V_2 * V_3 ;
int V_25 ;
if ( F_69 ( V_20 -> V_122 ) == V_123 )
return 0 ;
F_70 ( & V_20 -> V_32 , V_20 , V_124 ) ;
if ( V_20 -> V_48 == NULL ) {
V_25 = F_42 ( V_20 , - V_125 ) ;
F_63 ( V_20 , L_27 ,
V_25 , NULL ) ;
return 0 ;
}
F_20 ( V_20 -> V_48 != NULL ) ;
F_20 ( V_20 -> V_48 -> V_92 != NULL ) ;
switch ( F_69 ( V_20 -> V_122 ) ) {
case V_126 :
if ( F_15 ( V_127 ) )
return 0 ;
break;
case V_128 :
if ( F_15 ( V_129 ) )
return 0 ;
break;
case V_130 :
if ( F_15 ( V_131 ) )
return 0 ;
break;
case V_132 :
V_25 = F_57 ( V_20 ) ;
F_42 ( V_20 , V_25 ) ;
return 0 ;
case V_133 :
F_59 ( & V_20 -> V_32 , & V_134 ) ;
if ( F_15 ( V_135 ) )
return 0 ;
V_25 = F_66 ( V_20 ) ;
F_42 ( V_20 , V_25 ) ;
return 0 ;
default:
F_27 ( L_28 ,
F_69 ( V_20 -> V_122 ) ) ;
F_42 ( V_20 , - V_119 ) ;
return 0 ;
}
V_5 = V_20 -> V_48 -> V_92 -> V_136 ;
F_20 ( V_5 != NULL ) ;
F_59 ( & V_20 -> V_32 , & V_137 ) ;
V_22 = F_60 ( & V_20 -> V_32 , & V_138 ) ;
if ( V_22 == NULL ) {
V_25 = F_42 ( V_20 , - V_119 ) ;
F_63 ( V_20 , L_29 , V_25 ,
NULL ) ;
return 0 ;
}
if ( F_15 ( V_26 ) &&
F_69 ( V_20 -> V_122 ) == V_126 ) {
V_25 = F_71 ( & V_22 -> V_139 [ 0 ] , 0 ) ;
if ( V_25 < 0 )
F_27 ( L_30 , V_25 ) ;
}
V_3 = F_72 ( & V_22 -> V_139 [ 0 ] , 0 ) ;
if ( ! V_3 ) {
F_11 ( V_15 , L_31 ,
V_22 -> V_139 [ 0 ] . V_112 ) ;
V_25 = F_42 ( V_20 , - V_38 ) ;
F_63 ( V_20 , L_32 , V_25 ,
& V_22 -> V_139 [ 0 ] ) ;
return 0 ;
}
if ( ( V_3 -> V_9 & V_140 ) &&
F_69 ( V_20 -> V_122 ) == V_126 )
F_73 ( V_141 ) ;
F_9 ( V_3 ) ;
V_3 -> V_9 |= F_74 ( V_22 -> V_51 &
V_142 ) ;
if ( F_69 ( V_20 -> V_122 ) == V_126 ) {
if ( ( ( V_3 -> V_9 & V_143 ) &&
( V_3 -> V_9 & V_144 ) ) ||
( V_3 -> V_9 & V_56 ) ) {
F_8 ( V_3 , L_31 ,
V_22 -> V_139 [ 0 ] . V_112 ) ;
F_10 ( V_3 ) ;
F_12 ( V_3 ) ;
V_25 = F_42 ( V_20 , - V_38 ) ;
F_63 ( V_20 , L_33 , V_25 ,
& V_22 -> V_139 [ 0 ] ) ;
return 0 ;
}
F_28 ( V_3 ) ;
V_3 -> V_9 |= V_53 ;
}
F_10 ( V_3 ) ;
switch ( F_69 ( V_20 -> V_122 ) ) {
case V_126 :
F_11 ( V_145 , L_34 ) ;
F_75 ( & V_20 -> V_32 , & V_146 ) ;
if ( ! ( V_3 -> V_9 & V_11 ) ) {
V_25 = F_42 ( V_20 , 0 ) ;
if ( V_20 -> V_64 || V_25 )
F_63 ( V_20 , L_35 , V_25 ,
& V_22 -> V_139 [ 0 ] ) ;
}
if ( F_41 ( V_5 , & V_22 -> V_44 , V_3 ) )
F_7 ( V_5 , & V_22 -> V_44 , V_3 ) ;
break;
case V_128 :
F_11 ( V_145 , L_36 ) ;
F_75 ( & V_20 -> V_32 , & V_147 ) ;
F_42 ( V_20 , 0 ) ;
F_13 ( V_20 , V_5 , V_22 , V_3 ) ;
break;
case V_130 :
F_11 ( V_145 , L_37 ) ;
F_75 ( & V_20 -> V_32 , & V_148 ) ;
F_35 ( V_20 , V_5 , V_22 , V_3 ) ;
break;
default:
F_76 () ;
}
return 0 ;
}
static struct V_66 * F_77 ( struct V_69 * V_70 )
{
struct V_66 * V_67 = NULL ;
static unsigned int V_149 ;
F_45 ( & V_70 -> V_72 ) ;
if ( ! F_78 ( & V_70 -> V_77 ) &&
( F_78 ( & V_70 -> V_76 ) || V_149 == 0 ) )
V_67 = F_79 ( V_70 -> V_77 . V_150 ,
struct V_66 , V_75 ) ;
else
if ( ! F_78 ( & V_70 -> V_76 ) )
V_67 = F_79 ( V_70 -> V_76 . V_150 ,
struct V_66 ,
V_75 ) ;
if ( V_67 ) {
if ( ++ V_149 >= F_80 ( & V_70 -> V_151 ) )
V_149 = 0 ;
F_81 ( & V_67 -> V_75 ) ;
}
F_47 ( & V_70 -> V_72 ) ;
return V_67 ;
}
static int F_82 ( struct V_69 * V_70 )
{
struct V_152 V_153 = { . V_154 = V_70 } ;
struct V_155 * V_156 ;
F_50 ( & V_153 . V_157 ) ;
V_153 . V_158 = F_80 ( & V_70 -> V_151 ) ;
snprintf ( V_153 . V_159 , sizeof( V_153 . V_159 ) ,
L_38 , V_153 . V_158 ) ;
V_156 = F_83 ( V_160 , & V_153 , L_39 , V_153 . V_159 ) ;
if ( F_84 ( V_156 ) ) {
F_27 ( L_40 ,
F_80 ( & V_70 -> V_151 ) , F_85 ( V_156 ) ) ;
return F_85 ( V_156 ) ;
}
F_48 ( & V_153 . V_157 ) ;
return 0 ;
}
static int V_160 ( void * V_161 )
{
struct V_69 * V_70 ;
{
struct V_152 * V_153 = V_161 ;
V_70 = V_153 -> V_154 ;
F_86 ( & V_70 -> V_151 ) ;
F_86 ( & V_70 -> V_162 ) ;
F_87 ( & V_153 -> V_157 ) ;
}
while ( 1 ) {
struct V_163 V_164 = { 0 } ;
struct V_66 * V_67 = NULL ;
int V_165 ;
V_67 = F_77 ( V_70 ) ;
if ( V_67 == NULL ) {
F_88 ( & V_70 -> V_162 ) ;
F_89 ( V_70 -> V_78 ,
( V_67 = F_77 ( V_70 ) ) != NULL ,
& V_164 ) ;
V_165 = F_90 ( & V_70 -> V_162 ) ;
} else {
V_165 = F_80 ( & V_70 -> V_162 ) ;
}
if ( V_67 -> V_86 == NULL )
break;
if ( F_21 ( V_165 < V_70 -> V_166 &&
V_165 >= F_80 ( & V_70 -> V_151 ) &&
! V_67 -> V_85 ) )
F_82 ( V_70 ) ;
if ( V_67 -> V_85 )
F_91 () ;
if ( V_67 -> V_89 ) {
int V_83 ;
V_83 = F_92 ( & V_67 -> V_84 ,
V_67 -> V_89 ,
V_167 ) ;
F_93 ( & V_67 -> V_84 , V_83 , NULL ,
V_67 -> V_87 ) ;
} else {
F_7 ( V_67 -> V_86 , & V_67 -> V_88 ,
V_67 -> V_73 ) ;
}
if ( V_67 -> V_85 )
F_94 () ;
if ( V_67 -> V_87 & V_79 )
F_95 ( V_67 ) ;
else
F_87 ( & V_67 -> V_80 ) ;
}
F_88 ( & V_70 -> V_162 ) ;
F_88 ( & V_70 -> V_151 ) ;
F_87 ( & V_70 -> V_168 ) ;
return 0 ;
}
int F_96 ( void )
{
int V_25 = 0 ;
F_97 ( & V_169 ) ;
if ( ++ V_170 == 1 ) {
V_25 = F_98 () ;
if ( V_25 )
V_170 -- ;
}
F_99 ( & V_169 ) ;
return V_25 ;
}
void F_100 ( void )
{
F_97 ( & V_169 ) ;
if ( V_170 == 1 ) {
int V_25 = F_101 () ;
if ( V_25 )
F_27 ( L_41 , V_25 ) ;
else
V_170 -- ;
} else {
V_170 -- ;
}
F_99 ( & V_169 ) ;
}
static unsigned
F_102 ( struct V_171 * V_172 , const void * V_93 , unsigned V_173 )
{
return F_103 ( ( (struct V_109 * ) V_93 ) -> V_112 , V_173 ) ;
}
static void *
F_104 ( struct V_174 * V_175 )
{
struct V_2 * V_3 ;
V_3 = F_105 ( V_175 , struct V_2 , V_176 ) ;
return & V_3 -> V_177 ;
}
static void
F_106 ( struct V_174 * V_175 , void * V_93 )
{
struct V_2 * V_3 ;
V_3 = F_105 ( V_175 , struct V_2 , V_176 ) ;
V_3 -> V_177 = * (struct V_109 * ) V_93 ;
}
static int
F_107 ( const void * V_93 , struct V_174 * V_175 )
{
return F_108 ( F_104 ( V_175 ) , V_93 ) ;
}
static void *
F_109 ( struct V_174 * V_175 )
{
return F_105 ( V_175 , struct V_2 , V_176 ) ;
}
static void
F_110 ( struct V_171 * V_172 , struct V_174 * V_175 )
{
struct V_2 * V_3 ;
V_3 = F_105 ( V_175 , struct V_2 , V_176 ) ;
F_111 ( V_3 ) ;
}
static void
F_112 ( struct V_171 * V_172 , struct V_174 * V_175 )
{
struct V_2 * V_3 ;
V_3 = F_105 ( V_175 , struct V_2 , V_176 ) ;
F_12 ( V_3 ) ;
}
int F_113 ( struct V_178 * exp )
{
int V_25 ;
exp -> V_179 =
F_114 ( F_115 ( & exp -> V_180 ) ,
V_181 ,
V_182 ,
V_183 , 0 ,
V_184 , V_185 ,
& V_186 ,
V_187 | V_188 |
V_189 ) ;
if ( ! exp -> V_179 )
return - V_41 ;
V_25 = F_116 ( exp ) ;
if ( V_25 )
goto V_190;
return 0 ;
V_190:
F_117 ( exp ) ;
return V_25 ;
}
void F_117 ( struct V_178 * exp )
{
F_118 ( exp -> V_179 ) ;
exp -> V_179 = NULL ;
F_119 ( exp ) ;
}
static T_2 F_120 ( struct V_191 * V_192 ,
struct V_193 * V_194 ,
char * V_195 )
{
return sprintf ( V_195 , L_42 , V_196 ) ;
}
static T_2 F_121 ( struct V_191 * V_192 ,
struct V_193 * V_194 ,
const char * V_197 ,
T_3 V_83 )
{
int V_25 ;
unsigned long V_94 ;
V_25 = F_122 ( V_197 , 10 , & V_94 ) ;
if ( V_25 )
return V_25 ;
V_196 = V_94 ;
return V_83 ;
}
static int F_98 ( void )
{
static struct V_198 V_199 ;
struct V_69 * V_70 = NULL ;
int V_25 = 0 ;
int V_200 ;
if ( V_71 != NULL )
return - V_201 ;
V_71 = F_23 ( sizeof( * V_71 ) , V_40 ) ;
if ( ! V_71 )
return - V_41 ;
V_202 = F_123 ( L_43 , V_203 ) ;
if ( ! V_202 ) {
V_25 = - V_41 ;
goto V_35;
}
V_25 = F_124 ( V_202 , & V_204 ) ;
if ( V_25 )
goto V_35;
V_205 = F_125 ( L_44 , NULL , V_202 ) ;
if ( ! V_205 ) {
V_25 = - V_41 ;
goto V_35;
}
V_206 = F_125 ( L_45 , NULL , V_202 ) ;
if ( ! V_206 ) {
V_25 = - V_41 ;
goto V_35;
}
V_25 = F_126 () ;
if ( V_25 != 0 )
goto V_35;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 = ( F_127 ( V_199 ) ) {
. V_207 = L_46 ,
. V_208 = 2 ,
. V_209 = {
. V_210 = V_211 ,
. V_212 = V_213 ,
. V_214 = V_215 ,
. V_216 = V_217 ,
. V_218 = V_219 ,
. V_220 = V_221 ,
} ,
. V_222 = {
. V_223 = L_47 ,
. V_224 = V_225 ,
. V_226 = V_227 ,
. V_228 = V_229 ,
. V_230 = V_231 ,
. V_232 = V_233 ,
. V_234 = 1 ,
. V_235 = V_236 | V_237 ,
} ,
. V_238 = {
. V_239 = V_240 ,
} ,
. V_241 = {
. V_242 = F_68 ,
} ,
} ;
V_71 -> V_243 =
F_128 ( & V_199 , V_206 ,
V_244 ) ;
if ( F_84 ( V_71 -> V_243 ) ) {
F_27 ( L_48 ) ;
V_25 = F_85 ( V_71 -> V_243 ) ;
V_71 -> V_243 = NULL ;
goto V_35;
}
V_70 = F_23 ( sizeof( * V_70 ) , V_40 ) ;
if ( ! V_70 ) {
V_25 = - V_41 ;
goto V_35;
}
V_71 -> V_69 = V_70 ;
F_129 ( & V_70 -> V_72 ) ;
F_51 ( & V_70 -> V_77 ) ;
F_51 ( & V_70 -> V_76 ) ;
F_130 ( & V_70 -> V_78 ) ;
F_131 ( & V_70 -> V_151 , 0 ) ;
F_131 ( & V_70 -> V_162 , 0 ) ;
if ( V_233 == 0 ) {
V_70 -> V_245 = V_227 ;
V_70 -> V_166 = V_231 ;
} else {
V_70 -> V_245 = V_70 -> V_166 =
F_132 ( int , V_231 , F_133 ( int , V_227 ,
V_233 ) ) ;
}
for ( V_200 = 0 ; V_200 < V_70 -> V_245 ; V_200 ++ ) {
V_25 = F_82 ( V_70 ) ;
if ( V_25 < 0 )
goto V_35;
}
V_25 = F_134 () ;
if ( V_25 ) {
F_27 ( L_49 , V_25 ) ;
goto V_35;
}
return 0 ;
V_35:
F_101 () ;
return V_25 ;
}
static int F_101 ( void )
{
if ( ! F_78 ( F_135 ( V_246 ) ) ||
! F_78 ( F_135 ( V_247 ) ) ) {
F_27 ( L_50 ) ;
F_136 ( V_246 , V_15 ) ;
F_136 ( V_247 , V_15 ) ;
return - V_248 ;
}
F_137 () ;
if ( V_71 -> V_69 != NULL ) {
struct V_69 * V_70 = V_71 -> V_69 ;
while ( F_80 ( & V_70 -> V_151 ) > 0 ) {
struct V_66 V_67 = { . V_86 = NULL } ;
F_50 ( & V_70 -> V_168 ) ;
F_45 ( & V_70 -> V_72 ) ;
F_46 ( & V_67 . V_75 , & V_70 -> V_77 ) ;
F_34 ( & V_70 -> V_78 ) ;
F_47 ( & V_70 -> V_72 ) ;
F_48 ( & V_70 -> V_168 ) ;
}
F_95 ( V_70 ) ;
}
if ( V_71 -> V_243 != NULL )
F_138 ( V_71 -> V_243 ) ;
if ( V_205 )
F_139 ( V_205 ) ;
if ( V_206 )
F_139 ( V_206 ) ;
if ( V_202 )
F_140 ( V_202 ) ;
F_141 () ;
F_95 ( V_71 ) ;
V_71 = NULL ;
return 0 ;
}
int F_142 ( void )
{
F_143 ( & V_169 ) ;
F_143 ( F_144 ( V_246 ) ) ;
F_143 ( F_144 ( V_247 ) ) ;
V_249 = F_145 ( L_51 ,
sizeof( struct V_250 ) , 0 ,
V_251 , NULL ) ;
if ( V_249 == NULL )
return - V_41 ;
V_252 = F_145 ( L_52 ,
sizeof( struct V_2 ) , 0 ,
V_251 | V_253 , NULL ) ;
if ( V_252 == NULL ) {
F_146 ( V_249 ) ;
return - V_41 ;
}
V_254 = F_145 ( L_53 ,
sizeof( struct V_255 ) ,
0 , V_251 , NULL ) ;
if ( V_254 == NULL ) {
F_146 ( V_249 ) ;
F_146 ( V_252 ) ;
return - V_41 ;
}
#if V_256
V_257 = V_258 ;
#endif
return 0 ;
}
void F_147 ( void )
{
if ( V_170 )
F_27 ( L_54 , V_170 ) ;
F_146 ( V_249 ) ;
F_148 () ;
F_146 ( V_252 ) ;
F_146 ( V_254 ) ;
}
