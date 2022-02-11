inline unsigned long F_1 ( unsigned long V_1 )
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
F_13 ( V_17 ,
L_2 , V_5 ,
V_5 -> V_18 ) ;
if ( V_5 -> V_18 != NULL )
V_5 -> V_18 ( V_5 , V_9 , V_5 -> V_19 ,
V_20 ) ;
} else {
F_13 ( V_17 ,
L_3 ,
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
F_18 ( V_30 ) ;
F_19 ( V_29 ) ;
if ( V_5 -> V_31 == V_5 -> V_32 ||
V_5 -> V_11 & V_33 )
break;
}
}
V_25 = F_20 ( & V_22 -> V_34 , & V_35 , V_36 ) ;
if ( V_25 < 0 ) {
F_21 ( V_5 , L_6 , V_25 ) ;
V_27 = V_25 ;
goto V_37;
} else if ( V_25 > 0 ) {
if ( V_5 -> V_38 > 0 ) {
F_22 ( V_5 -> V_39 != NULL ) ;
if ( F_23 ( V_5 -> V_38 < V_25 ) ) {
F_21 ( V_5 , L_7 ,
V_5 -> V_38 , V_25 ) ;
V_27 = - V_40 ;
goto V_37;
}
} else if ( F_24 ( V_5 ) ) {
void * V_41 ;
F_25 ( V_41 , V_25 ) ;
if ( V_41 == NULL ) {
F_21 ( V_5 , L_8 , V_25 ) ;
V_27 = - V_42 ;
goto V_37;
}
F_11 ( V_5 ) ;
F_22 ( V_5 -> V_39 == NULL ) ;
V_5 -> V_43 = V_44 ;
V_5 -> V_39 = V_41 ;
V_5 -> V_38 = V_25 ;
F_12 ( V_5 ) ;
}
}
F_11 ( V_5 ) ;
if ( ( V_5 -> V_11 & V_33 ) ||
V_5 -> V_31 == V_5 -> V_32 ) {
F_12 ( V_5 ) ;
F_10 ( V_5 , L_9 ) ;
V_27 = 0 ;
goto V_37;
}
if ( V_24 -> V_45 . V_31 != V_5 -> V_32 ) {
V_5 -> V_32 = V_24 -> V_45 . V_31 ;
F_10 ( V_5 , L_10 ) ;
}
if ( V_5 -> V_46 -> V_47 != V_48 ) {
F_26 ( V_22 -> V_49 ,
V_24 -> V_45 . V_46 . V_47 ,
& V_24 -> V_45 . V_50 ,
& V_5 -> V_50 ) ;
F_10 ( V_5 , L_11 ) ;
}
F_27 ( V_5 ) ;
if ( memcmp ( & V_24 -> V_45 . V_46 . V_51 ,
& V_5 -> V_46 -> V_51 ,
sizeof( V_5 -> V_46 -> V_51 ) ) != 0 ) {
F_12 ( V_5 ) ;
V_27 = F_28 ( V_7 , V_5 ,
& V_24 -> V_45 . V_46 . V_51 ) ;
if ( V_27 < 0 ) {
F_21 ( V_5 , L_12 ) ;
goto V_37;
}
F_10 ( V_5 , L_13 ) ;
F_29 ( L_14 ) ;
F_11 ( V_5 ) ;
}
if ( V_24 -> V_52 & V_53 ) {
F_30 ( V_5 ) ;
V_5 -> V_11 |= V_12 | V_54 ;
F_10 ( V_5 , L_15 ) ;
}
if ( V_5 -> V_38 > 0 ) {
V_27 = F_31 ( V_5 , & V_22 -> V_34 , V_36 ,
V_5 -> V_39 , V_25 ) ;
if ( V_27 < 0 ) {
F_12 ( V_5 ) ;
goto V_37;
}
}
F_32 ( V_5 , & V_26 ) ;
F_12 ( V_5 ) ;
F_10 ( V_5 , L_16 ) ;
F_33 ( V_55 , 2 ) ;
F_34 ( V_7 , & V_26 , V_56 ) ;
F_35 ( L_17 ,
V_5 ) ;
goto V_37;
V_37:
if ( V_27 < 0 ) {
F_11 ( V_5 ) ;
V_5 -> V_11 |= V_57 ;
F_12 ( V_5 ) ;
F_36 ( & V_5 -> V_58 ) ;
}
F_14 ( V_5 ) ;
}
static void F_37 ( struct V_21 * V_22 ,
struct V_6 * V_7 ,
struct V_23 * V_24 ,
struct V_4 * V_5 )
{
int V_27 = - V_59 ;
F_10 ( V_5 , L_18 ) ;
if ( V_5 -> V_60 != NULL )
V_27 = V_5 -> V_60 ( V_5 , V_22 ) ;
if ( V_22 -> V_61 != NULL ) {
F_38 ( V_22 ) ;
} else {
V_22 -> V_62 = V_27 ;
F_39 ( V_22 ) ;
}
F_11 ( V_5 ) ;
if ( V_5 -> V_31 == V_63 &&
! V_5 -> V_15 && ! V_5 -> V_16 &&
F_40 ( F_41 () ,
F_42 ( V_5 -> V_64 ,
F_2 ( 10 ) ) ) ) {
F_12 ( V_5 ) ;
if ( F_43 ( V_7 , NULL , V_5 ) )
F_9 ( V_7 , NULL , V_5 ) ;
return;
}
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
}
static int F_44 ( struct V_21 * V_22 , int V_27 )
{
if ( V_22 -> V_65 )
return 0 ;
V_22 -> V_62 = V_27 ;
if ( ! V_22 -> V_66 ) {
V_27 = F_45 ( V_22 , 1 , NULL , NULL ) ;
if ( V_27 )
return V_27 ;
}
return F_38 ( V_22 ) ;
}
static int F_46 ( struct V_67 * V_68 ,
T_1 V_69 )
{
struct V_70 * V_71 = V_72 -> V_70 ;
F_47 ( & V_71 -> V_73 ) ;
if ( V_68 -> V_74 &&
V_68 -> V_74 -> V_11 & V_75 ) {
F_48 ( & V_68 -> V_76 , & V_71 -> V_77 ) ;
} else {
F_48 ( & V_68 -> V_76 , & V_71 -> V_78 ) ;
}
F_49 ( & V_71 -> V_73 ) ;
F_36 ( & V_71 -> V_79 ) ;
if ( ! ( V_69 & V_80 ) )
F_50 ( & V_68 -> V_81 ) ;
return 0 ;
}
static inline void F_51 ( struct V_67 * V_68 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_82 * V_83 , int V_84 ,
struct V_4 * V_5 ,
T_1 V_69 )
{
F_52 ( & V_68 -> V_81 ) ;
F_53 ( & V_68 -> V_85 ) ;
if ( F_54 () )
V_68 -> V_86 = 1 ;
V_68 -> V_87 = V_7 ;
V_68 -> V_88 = V_69 ;
if ( V_9 != NULL )
V_68 -> V_89 = * V_9 ;
if ( V_84 ) {
F_55 ( & V_68 -> V_85 , V_83 ) ;
F_56 ( V_83 ) ;
V_68 -> V_90 = V_84 ;
} else {
V_68 -> V_74 = V_5 ;
}
}
static int F_57 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_4 * V_5 ,
struct V_82 * V_83 , int V_84 ,
T_1 V_69 )
{
if ( V_83 && V_84 == 0 )
return 0 ;
if ( V_69 & V_80 ) {
struct V_67 * V_68 ;
F_25 ( V_68 , sizeof( * V_68 ) ) ;
if ( V_68 == NULL )
return - V_42 ;
F_51 ( V_68 , V_7 , V_9 , V_83 , V_84 , V_5 , V_69 ) ;
return F_46 ( V_68 , V_69 ) ;
} else {
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_51 ( & V_68 , V_7 , V_9 , V_83 , V_84 , V_5 , V_69 ) ;
return F_46 ( & V_68 , V_69 ) ;
}
}
int F_43 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_4 * V_5 )
{
return F_57 ( V_7 , V_9 , V_5 , NULL , 0 , V_80 ) ;
}
int F_58 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_82 * V_83 , int V_84 ,
T_1 V_69 )
{
return F_57 ( V_7 , V_9 , NULL , V_83 , V_84 , V_69 ) ;
}
static int F_59 ( struct V_21 * V_22 )
{
struct V_91 * V_92 = V_22 -> V_49 -> V_93 ;
char * V_94 ;
void * V_95 ;
int V_96 , V_97 ;
int V_27 = - V_59 ;
F_60 ( V_98 , V_22 , L_19 , V_92 -> V_99 ) ;
F_61 ( & V_22 -> V_34 , & V_100 ) ;
V_94 = F_62 ( & V_22 -> V_34 , & V_101 ) ;
if ( V_94 == NULL ) {
F_60 ( V_102 , V_22 , L_20 ) ;
return - V_103 ;
}
V_96 = F_20 ( & V_22 -> V_34 , & V_101 ,
V_36 ) ;
V_95 = F_62 ( & V_22 -> V_34 , & V_104 ) ;
if ( V_95 == NULL ) {
F_60 ( V_102 , V_22 , L_21 ) ;
return - V_103 ;
}
V_97 = F_20 ( & V_22 -> V_34 , & V_104 ,
V_36 ) ;
if ( F_63 ( V_105 ) )
V_27 = F_64 ( V_22 -> V_106 -> V_107 ,
V_22 -> V_49 ,
sizeof( V_105 ) ,
V_105 ,
V_97 , V_95 , NULL ) ;
else
F_60 ( V_108 , V_22 , L_22 , V_94 ) ;
return V_27 ;
}
static inline void F_65 ( struct V_21 * V_22 ,
const char * V_109 , int V_27 ,
struct V_110 * V_111 )
{
F_60 ( ( V_22 -> V_65 || V_27 ) ? V_108 : V_17 , V_22 ,
L_23 ,
V_109 , F_66 ( V_22 -> V_112 ) , V_27 ,
V_111 ? V_111 -> V_113 : 0 ) ;
if ( V_22 -> V_65 )
F_67 ( L_24 ) ;
else if ( V_27 )
F_67 ( L_25 ) ;
}
static int F_68 ( struct V_21 * V_22 )
{
struct V_114 * V_115 ;
struct V_116 * V_117 = & V_22 -> V_49 -> V_93 -> V_118 . V_117 ;
V_115 = F_62 ( & V_22 -> V_34 , & V_119 ) ;
if ( V_115 == NULL ) {
F_29 ( L_26 ) ;
return - V_120 ;
}
V_115 -> V_121 = F_69 ( V_115 -> V_121 ) ;
V_117 -> V_122 = V_115 -> V_121 ;
return 0 ;
}
static int F_70 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
int V_27 ;
if ( F_71 ( V_22 -> V_123 ) == V_124 )
return 0 ;
F_72 ( & V_22 -> V_34 , V_22 , V_125 ) ;
if ( V_22 -> V_49 == NULL ) {
V_27 = F_44 ( V_22 , - V_126 ) ;
F_65 ( V_22 , L_27 ,
V_27 , NULL ) ;
return 0 ;
}
F_22 ( V_22 -> V_49 != NULL ) ;
F_22 ( V_22 -> V_49 -> V_93 != NULL ) ;
switch ( F_71 ( V_22 -> V_123 ) ) {
case V_127 :
if ( F_17 ( V_128 ) )
return 0 ;
break;
case V_129 :
if ( F_17 ( V_130 ) )
return 0 ;
break;
case V_131 :
if ( F_17 ( V_132 ) )
return 0 ;
break;
case V_133 :
V_27 = F_59 ( V_22 ) ;
F_44 ( V_22 , V_27 ) ;
return 0 ;
case V_134 :
F_61 ( & V_22 -> V_34 , & V_135 ) ;
if ( F_17 ( V_136 ) )
return 0 ;
V_27 = F_68 ( V_22 ) ;
F_44 ( V_22 , V_27 ) ;
return 0 ;
default:
F_29 ( L_28 ,
F_71 ( V_22 -> V_123 ) ) ;
F_44 ( V_22 , - V_120 ) ;
return 0 ;
}
V_7 = V_22 -> V_49 -> V_93 -> V_137 ;
F_22 ( V_7 != NULL ) ;
F_61 ( & V_22 -> V_34 , & V_138 ) ;
V_24 = F_62 ( & V_22 -> V_34 , & V_139 ) ;
if ( V_24 == NULL ) {
V_27 = F_44 ( V_22 , - V_120 ) ;
F_65 ( V_22 , L_29 , V_27 ,
NULL ) ;
return 0 ;
}
if ( F_17 ( V_28 ) &&
F_71 ( V_22 -> V_123 ) == V_127 ) {
V_27 = F_73 ( & V_24 -> V_140 [ 0 ] , 0 ) ;
if ( V_27 < 0 )
F_29 ( L_30 , V_27 ) ;
}
V_5 = F_74 ( & V_24 -> V_140 [ 0 ] , 0 ) ;
if ( ! V_5 ) {
F_13 ( V_17 , L_31 ,
V_24 -> V_140 [ 0 ] . V_113 ) ;
V_27 = F_44 ( V_22 , - V_40 ) ;
F_65 ( V_22 , L_32 , V_27 ,
& V_24 -> V_140 [ 0 ] ) ;
return 0 ;
}
if ( ( V_5 -> V_11 & V_141 ) &&
F_71 ( V_22 -> V_123 ) == V_127 )
F_75 ( V_142 ) ;
F_11 ( V_5 ) ;
V_5 -> V_11 |= F_76 ( V_24 -> V_52 &
V_143 ) ;
if ( F_71 ( V_22 -> V_123 ) == V_127 ) {
if ( ( ( V_5 -> V_11 & V_144 ) &&
( V_5 -> V_11 & V_145 ) ) ||
( V_5 -> V_11 & V_57 ) ) {
F_10 ( V_5 , L_31 ,
V_24 -> V_140 [ 0 ] . V_113 ) ;
F_12 ( V_5 ) ;
F_14 ( V_5 ) ;
V_27 = F_44 ( V_22 , - V_40 ) ;
F_65 ( V_22 , L_33 , V_27 ,
& V_24 -> V_140 [ 0 ] ) ;
return 0 ;
}
F_30 ( V_5 ) ;
V_5 -> V_11 |= V_54 ;
}
F_12 ( V_5 ) ;
switch ( F_71 ( V_22 -> V_123 ) ) {
case V_127 :
F_13 ( V_146 , L_34 ) ;
F_77 ( & V_22 -> V_34 , & V_147 ) ;
if ( ! ( V_5 -> V_11 & V_13 ) ) {
V_27 = F_44 ( V_22 , 0 ) ;
if ( V_22 -> V_65 || V_27 )
F_65 ( V_22 , L_35 , V_27 ,
& V_24 -> V_140 [ 0 ] ) ;
}
if ( F_43 ( V_7 , & V_24 -> V_45 , V_5 ) )
F_9 ( V_7 , & V_24 -> V_45 , V_5 ) ;
break;
case V_129 :
F_13 ( V_146 , L_36 ) ;
F_77 ( & V_22 -> V_34 , & V_148 ) ;
F_44 ( V_22 , 0 ) ;
F_15 ( V_22 , V_7 , V_24 , V_5 ) ;
break;
case V_131 :
F_13 ( V_146 , L_37 ) ;
F_77 ( & V_22 -> V_34 , & V_149 ) ;
F_37 ( V_22 , V_7 , V_24 , V_5 ) ;
break;
default:
F_78 () ;
}
return 0 ;
}
static struct V_67 * F_79 ( struct V_70 * V_71 )
{
struct V_67 * V_68 = NULL ;
static unsigned int V_150 ;
F_47 ( & V_71 -> V_73 ) ;
if ( ! F_80 ( & V_71 -> V_78 ) &&
( F_80 ( & V_71 -> V_77 ) || V_150 == 0 ) )
V_68 = F_81 ( V_71 -> V_78 . V_151 ,
struct V_67 , V_76 ) ;
else
if ( ! F_80 ( & V_71 -> V_77 ) )
V_68 = F_81 ( V_71 -> V_77 . V_151 ,
struct V_67 ,
V_76 ) ;
if ( V_68 ) {
if ( ++ V_150 >= F_82 ( & V_71 -> V_152 ) )
V_150 = 0 ;
F_83 ( & V_68 -> V_76 ) ;
}
F_49 ( & V_71 -> V_73 ) ;
return V_68 ;
}
static int F_84 ( struct V_70 * V_71 )
{
struct V_153 V_154 = { . V_155 = V_71 } ;
struct V_156 * V_157 ;
F_52 ( & V_154 . V_158 ) ;
V_154 . V_159 = F_82 ( & V_71 -> V_152 ) ;
snprintf ( V_154 . V_160 , sizeof( V_154 . V_160 ) ,
L_38 , V_154 . V_159 ) ;
V_157 = F_85 ( V_161 , & V_154 , L_39 , V_154 . V_160 ) ;
if ( F_86 ( V_157 ) ) {
F_29 ( L_40 ,
F_82 ( & V_71 -> V_152 ) , F_87 ( V_157 ) ) ;
return F_87 ( V_157 ) ;
}
F_50 ( & V_154 . V_158 ) ;
return 0 ;
}
static int V_161 ( void * V_162 )
{
struct V_70 * V_71 ;
{
struct V_153 * V_154 = V_162 ;
V_71 = V_154 -> V_155 ;
F_88 ( & V_71 -> V_152 ) ;
F_88 ( & V_71 -> V_163 ) ;
F_89 ( & V_154 -> V_158 ) ;
}
while ( 1 ) {
struct V_164 V_165 = { 0 } ;
struct V_67 * V_68 = NULL ;
int V_166 ;
V_68 = F_79 ( V_71 ) ;
if ( V_68 == NULL ) {
F_90 ( & V_71 -> V_163 ) ;
F_91 ( V_71 -> V_79 ,
( V_68 = F_79 ( V_71 ) ) != NULL ,
& V_165 ) ;
V_166 = F_92 ( & V_71 -> V_163 ) ;
} else {
V_166 = F_82 ( & V_71 -> V_163 ) ;
}
if ( V_68 -> V_87 == NULL )
break;
if ( F_23 ( V_166 < V_71 -> V_167 &&
V_166 >= F_82 ( & V_71 -> V_152 ) &&
! V_68 -> V_86 ) )
F_84 ( V_71 ) ;
if ( V_68 -> V_86 )
F_93 () ;
if ( V_68 -> V_90 ) {
int V_84 ;
V_84 = F_94 ( & V_68 -> V_85 ,
V_68 -> V_90 ,
V_168 ) ;
F_95 ( & V_68 -> V_85 , V_84 , NULL ,
V_68 -> V_88 ) ;
} else {
F_9 ( V_68 -> V_87 , & V_68 -> V_89 ,
V_68 -> V_74 ) ;
}
if ( V_68 -> V_86 )
F_96 () ;
if ( V_68 -> V_88 & V_80 )
F_97 ( V_68 , sizeof( * V_68 ) ) ;
else
F_89 ( & V_68 -> V_81 ) ;
}
F_90 ( & V_71 -> V_163 ) ;
F_90 ( & V_71 -> V_152 ) ;
F_89 ( & V_71 -> V_169 ) ;
return 0 ;
}
int F_98 ( void )
{
int V_27 = 0 ;
F_99 ( & V_170 ) ;
if ( ++ V_171 == 1 ) {
V_27 = F_100 () ;
if ( V_27 )
V_171 -- ;
}
F_101 ( & V_170 ) ;
return V_27 ;
}
void F_102 ( void )
{
F_99 ( & V_170 ) ;
if ( V_171 == 1 ) {
int V_27 = F_103 () ;
if ( V_27 )
F_29 ( L_41 , V_27 ) ;
else
V_171 -- ;
} else {
V_171 -- ;
}
F_101 ( & V_170 ) ;
}
static unsigned
F_104 ( struct V_172 * V_173 , const void * V_94 , unsigned V_174 )
{
return F_105 ( ( (struct V_110 * ) V_94 ) -> V_113 , V_174 ) ;
}
static void *
F_106 ( struct V_175 * V_176 )
{
struct V_4 * V_5 ;
V_5 = F_107 ( V_176 , struct V_4 , V_177 ) ;
return & V_5 -> V_178 ;
}
static void
F_108 ( struct V_175 * V_176 , void * V_94 )
{
struct V_4 * V_5 ;
V_5 = F_107 ( V_176 , struct V_4 , V_177 ) ;
V_5 -> V_178 = * (struct V_110 * ) V_94 ;
}
static int
F_109 ( const void * V_94 , struct V_175 * V_176 )
{
return F_110 ( F_106 ( V_176 ) , V_94 ) ;
}
static void *
F_111 ( struct V_175 * V_176 )
{
return F_107 ( V_176 , struct V_4 , V_177 ) ;
}
static void
F_112 ( struct V_172 * V_173 , struct V_175 * V_176 )
{
struct V_4 * V_5 ;
V_5 = F_107 ( V_176 , struct V_4 , V_177 ) ;
F_113 ( V_5 ) ;
}
static void
F_114 ( struct V_172 * V_173 , struct V_175 * V_176 )
{
struct V_4 * V_5 ;
V_5 = F_107 ( V_176 , struct V_4 , V_177 ) ;
F_14 ( V_5 ) ;
}
int F_115 ( struct V_179 * exp )
{
int V_27 ;
exp -> V_180 =
F_116 ( F_117 ( & exp -> V_181 ) ,
V_182 ,
V_183 ,
V_184 , 0 ,
V_185 , V_186 ,
& V_187 ,
V_188 | V_189 |
V_190 ) ;
if ( ! exp -> V_180 )
return - V_42 ;
V_27 = F_118 ( exp ) ;
if ( V_27 )
goto V_191;
return 0 ;
V_191:
F_119 ( exp ) ;
return V_27 ;
}
void F_119 ( struct V_179 * exp )
{
F_120 ( exp -> V_180 ) ;
exp -> V_180 = NULL ;
F_121 ( exp ) ;
}
static int F_100 ( void )
{
static struct V_192 V_193 ;
struct V_70 * V_71 = NULL ;
int V_27 = 0 ;
int V_194 ;
if ( V_72 != NULL )
return - V_195 ;
F_25 ( V_72 , sizeof( * V_72 ) ) ;
if ( V_72 == NULL )
return - V_42 ;
V_27 = F_122 () ;
if ( V_27 != 0 )
goto V_37;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 = ( F_123 ( V_193 ) ) {
. V_196 = L_42 ,
. V_197 = 2 ,
. V_198 = {
. V_199 = V_200 ,
. V_201 = V_202 ,
. V_203 = V_204 ,
. V_205 = V_206 ,
. V_207 = V_208 ,
. V_209 = V_210 ,
} ,
. V_211 = {
. V_212 = L_43 ,
. V_213 = V_214 ,
. V_215 = V_216 ,
. V_217 = V_218 ,
. V_219 = V_220 ,
. V_221 = V_222 ,
. V_223 = 1 ,
. V_224 = V_225 | V_226 ,
} ,
. V_227 = {
. V_228 = V_229 ,
} ,
. V_230 = {
. V_231 = F_70 ,
} ,
} ;
V_72 -> V_232 =
F_124 ( & V_193 , V_233 ) ;
if ( F_86 ( V_72 -> V_232 ) ) {
F_29 ( L_44 ) ;
V_27 = F_87 ( V_72 -> V_232 ) ;
V_72 -> V_232 = NULL ;
goto V_37;
}
F_25 ( V_71 , sizeof( * V_71 ) ) ;
if ( V_71 == NULL ) {
V_27 = - V_42 ;
goto V_37;
}
V_72 -> V_70 = V_71 ;
F_125 ( & V_71 -> V_73 ) ;
F_53 ( & V_71 -> V_78 ) ;
F_53 ( & V_71 -> V_77 ) ;
F_126 ( & V_71 -> V_79 ) ;
F_127 ( & V_71 -> V_152 , 0 ) ;
F_127 ( & V_71 -> V_163 , 0 ) ;
if ( V_222 == 0 ) {
V_71 -> V_234 = V_216 ;
V_71 -> V_167 = V_220 ;
} else {
V_71 -> V_234 = V_71 -> V_167 =
F_128 ( int , V_220 , F_129 ( int , V_216 ,
V_222 ) ) ;
}
for ( V_194 = 0 ; V_194 < V_71 -> V_234 ; V_194 ++ ) {
V_27 = F_84 ( V_71 ) ;
if ( V_27 < 0 )
goto V_37;
}
V_27 = F_130 () ;
if ( V_27 ) {
F_29 ( L_45 , V_27 ) ;
goto V_37;
}
return 0 ;
V_37:
F_103 () ;
return V_27 ;
}
static int F_103 ( void )
{
if ( ! F_80 ( F_131 ( V_235 ) ) ||
! F_80 ( F_131 ( V_236 ) ) ) {
F_29 ( L_46 ) ;
F_132 ( V_235 , V_17 ) ;
F_132 ( V_236 , V_17 ) ;
return - V_237 ;
}
F_133 () ;
if ( V_72 -> V_70 != NULL ) {
struct V_70 * V_71 = V_72 -> V_70 ;
while ( F_82 ( & V_71 -> V_152 ) > 0 ) {
struct V_67 V_68 = { . V_87 = NULL } ;
F_52 ( & V_71 -> V_169 ) ;
F_47 ( & V_71 -> V_73 ) ;
F_48 ( & V_68 . V_76 , & V_71 -> V_78 ) ;
F_36 ( & V_71 -> V_79 ) ;
F_49 ( & V_71 -> V_73 ) ;
F_50 ( & V_71 -> V_169 ) ;
}
F_97 ( V_71 , sizeof( * V_71 ) ) ;
}
if ( V_72 -> V_232 != NULL )
F_134 ( V_72 -> V_232 ) ;
F_135 () ;
F_97 ( V_72 , sizeof( * V_72 ) ) ;
V_72 = NULL ;
return 0 ;
}
int F_136 ( void )
{
F_137 ( & V_170 ) ;
F_137 ( F_138 ( V_235 ) ) ;
F_137 ( F_138 ( V_236 ) ) ;
V_238 = F_139 ( L_47 ,
sizeof( struct V_239 ) , 0 ,
V_240 , NULL ) ;
if ( V_238 == NULL )
return - V_42 ;
V_241 = F_139 ( L_48 ,
sizeof( struct V_4 ) , 0 ,
V_240 | V_242 , NULL ) ;
if ( V_241 == NULL ) {
F_140 ( V_238 ) ;
return - V_42 ;
}
V_243 = F_139 ( L_49 ,
sizeof( struct V_244 ) ,
0 , V_240 , NULL ) ;
if ( V_243 == NULL ) {
F_140 ( V_238 ) ;
F_140 ( V_241 ) ;
return - V_42 ;
}
#if V_245
V_246 = V_247 ;
#endif
return 0 ;
}
void F_141 ( void )
{
if ( V_171 )
F_29 ( L_50 , V_171 ) ;
F_140 ( V_238 ) ;
F_142 () ;
F_140 ( V_241 ) ;
F_140 ( V_243 ) ;
}
