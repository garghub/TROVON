void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_2 ( & F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_16 ) {
V_14 -> V_15 . V_17 |= V_18 ;
V_14 -> V_15 . V_19 = V_20 ;
F_6 ( V_14 ) ;
} else
F_7 ( V_2 , V_14 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & F_3 ( V_2 ) , F_4 ) ;
F_10 ( & V_2 -> V_21 [ V_22 ] . V_23 ) ;
}
static int T_1 F_11 ( void )
{
F_1 ( & V_24 ) ;
return 0 ;
}
void T_1 F_12 ( void )
{
F_13 ( L_1 ,
#if V_25 <= 32
L_2 ,
#else
L_3 ,
#endif
V_22 , V_26 ) ;
}
static inline struct V_13 * F_14 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_15 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return F_17 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_18 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_19 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return F_17 ( V_12 ) ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline struct V_13 * F_20 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_21 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return (struct V_13 * ) V_12 ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline void F_22 ( struct V_13 * V_12 )
{
F_23 () ;
F_24 ( & V_12 -> V_15 ) ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_5 ( V_29 , struct V_30 , V_32 ) ;
struct V_13 * V_14 = F_26 ( V_31 ) ;
F_27 ( V_14 ) ;
F_28 ( V_29 ) ;
}
static inline void F_29 ( struct V_1 * V_2 , struct V_13 * V_33 )
{
F_30 ( & F_3 ( V_2 ) , & V_33 -> V_15 ) ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
V_14 = F_20 ( V_39 -> V_2 , V_39 -> V_27 ) ;
F_32 ( F_16 ( V_14 ) ) ;
V_14 -> V_40 = F_33 () ;
V_14 -> V_41 = F_34 ( V_42 ) ;
V_14 -> V_16 ++ ;
F_6 ( V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_36 * V_43 ;
V_43 = V_14 -> V_43 ;
V_14 -> V_43 = NULL ;
V_2 -> V_10 -= ( V_14 -> V_44 + V_45 - 1 ) >> V_46 ;
F_29 ( V_2 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! F_35 ( V_43 ) )
F_36 ( V_43 , 0 , V_14 -> V_47 ) ;
else if ( V_14 -> V_47 )
F_37 ( F_38 ( V_43 ) -> V_48 , V_14 -> V_47 ) ;
F_39 ( V_43 ) ;
F_40 ( V_14 , F_25 ) ;
}
static bool F_41 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_42 ( struct V_34 * V_35 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_39 -> V_2 ;
F_43 ( & F_3 ( V_2 ) . V_49 ) ;
V_14 = F_20 ( V_2 , V_39 -> V_27 ) ;
F_32 ( F_16 ( V_14 ) ) ;
V_14 -> V_41 = F_34 ( V_42 ) ;
V_14 -> V_50 = F_33 () ;
V_14 -> V_16 -- ;
if ( F_41 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_44 ( & F_3 ( V_2 ) . V_49 ) ;
}
static int F_45 ( int V_27 , void * V_31 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_11 * V_12 = V_31 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_52 != V_42 )
return 0 ;
V_14 -> V_52 = NULL ;
if ( ! V_2 -> V_9 )
return 0 ;
if ( F_41 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
static int F_46 ( int V_27 , void * V_31 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_11 * V_12 = V_31 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_52 != NULL )
return 0 ;
if ( F_41 ( V_2 , V_14 ) ) {
F_22 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_43 ( & F_3 ( V_2 ) . V_49 ) ;
if ( F_3 ( V_2 ) . V_53 )
F_48 ( & F_3 ( V_2 ) . V_23 , & F_46 , V_2 ) ;
F_44 ( & F_3 ( V_2 ) . V_49 ) ;
}
void F_49 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 -> V_57 ;
if ( F_3 ( V_2 ) . V_53 == 0 )
return;
F_43 ( & F_3 ( V_2 ) . V_49 ) ;
if ( F_3 ( V_2 ) . V_53 )
F_48 ( & F_3 ( V_2 ) . V_23 , & F_45 , V_2 ) ;
F_44 ( & F_3 ( V_2 ) . V_49 ) ;
}
static int F_50 ( struct V_34 * V_35 , struct V_58 * V_59 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_60 -> V_61 ( V_35 , V_59 ) ;
}
static int F_51 ( struct V_34 * V_35 , struct V_62 * V_63 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_64 = 0 ;
if ( V_39 -> V_60 -> V_65 )
V_64 = V_39 -> V_60 -> V_65 ( V_35 , V_63 ) ;
return V_64 ;
}
static struct V_62 * F_52 ( struct V_34 * V_35 ,
unsigned long V_66 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_38 ( V_36 ) ;
struct V_62 * V_67 = NULL ;
if ( V_39 -> V_60 -> V_68 )
V_67 = V_39 -> V_60 -> V_68 ( V_35 , V_66 ) ;
else if ( V_35 -> V_69 )
V_67 = V_35 -> V_69 ;
return V_67 ;
}
static int F_53 ( struct V_36 * V_36 , struct V_34 * V_35 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
int V_70 ;
V_70 = V_39 -> V_36 -> V_71 -> V_72 ( V_39 -> V_36 , V_35 ) ;
if ( V_70 != 0 )
return V_70 ;
V_39 -> V_60 = V_35 -> V_60 ;
#ifdef F_54
F_32 ( ! V_39 -> V_60 -> V_61 ) ;
#endif
V_35 -> V_60 = & V_73 ;
F_31 ( V_35 ) ;
return V_70 ;
}
static int F_55 ( struct V_74 * V_75 , struct V_36 * V_36 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
F_56 ( V_39 -> V_2 ) ;
V_38 ( V_36 ) = NULL ;
F_57 ( V_39 ) ;
return 0 ;
}
static int F_58 ( struct V_36 * V_36 , T_2 V_76 , T_2 V_77 , int V_78 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_71 -> V_79 )
return - V_80 ;
return V_39 -> V_36 -> V_71 -> V_79 ( V_39 -> V_36 , V_76 , V_77 , V_78 ) ;
}
static long F_59 ( struct V_36 * V_36 , int V_17 , T_2 V_81 ,
T_2 V_82 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
if ( ! V_39 -> V_36 -> V_71 -> V_83 )
return - V_84 ;
return V_39 -> V_36 -> V_71 -> V_83 ( V_36 , V_17 , V_81 , V_82 ) ;
}
static unsigned long F_60 ( struct V_36 * V_36 ,
unsigned long V_66 , unsigned long V_82 , unsigned long V_85 ,
unsigned long V_86 )
{
struct V_38 * V_39 = V_38 ( V_36 ) ;
return V_39 -> V_36 -> V_71 -> V_87 ( V_39 -> V_36 , V_66 , V_82 ,
V_85 , V_86 ) ;
}
int F_61 ( struct V_36 * V_36 )
{
return V_36 -> V_71 == & V_88 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
T_3 V_19 = V_90 -> V_19 ;
int V_91 = V_90 -> V_92 ;
T_4 V_93 = V_90 -> V_94 . V_93 ;
int error ;
struct V_13 * V_14 ;
T_4 V_95 = ( V_93 + V_45 - 1 ) >> V_46 ;
struct V_36 * V_36 ;
char V_96 [ 13 ] ;
int V_27 ;
T_5 V_97 = 0 ;
if ( V_93 < V_98 || V_93 > V_2 -> V_3 )
return - V_80 ;
if ( V_2 -> V_10 + V_95 > V_2 -> V_5 )
return - V_99 ;
V_14 = F_63 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_100 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_91 & V_101 ) ;
V_14 -> V_47 = NULL ;
V_14 -> V_15 . V_102 = NULL ;
error = F_64 ( V_14 ) ;
if ( error ) {
F_40 ( V_14 , F_28 ) ;
return error ;
}
sprintf ( V_96 , L_4 , V_19 ) ;
if ( V_91 & V_103 ) {
struct V_104 * V_105 ;
T_4 V_106 ;
V_105 = F_65 ( ( V_91 >> V_107 ) & V_108 ) ;
if ( ! V_105 ) {
error = - V_80 ;
goto V_109;
}
V_106 = F_66 ( V_93 , F_67 ( V_105 ) ) ;
if ( V_91 & V_110 )
V_97 = V_111 ;
V_36 = F_68 ( V_96 , V_106 , V_97 ,
& V_14 -> V_47 , V_112 ,
( V_91 >> V_107 ) & V_108 ) ;
} else {
if ( ( V_91 & V_110 ) &&
V_113 != V_114 )
V_97 = V_111 ;
V_36 = F_69 ( V_96 , V_93 , V_97 ) ;
}
error = F_70 ( V_36 ) ;
if ( F_16 ( V_36 ) )
goto V_109;
V_27 = F_71 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_115;
}
V_14 -> V_116 = F_34 ( V_42 ) ;
V_14 -> V_41 = 0 ;
V_14 -> V_40 = V_14 -> V_50 = 0 ;
V_14 -> V_117 = F_33 () ;
V_14 -> V_44 = V_93 ;
V_14 -> V_16 = 0 ;
V_14 -> V_43 = V_36 ;
V_14 -> V_52 = V_42 ;
F_38 ( V_36 ) -> V_118 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_95 ;
error = V_14 -> V_15 . V_27 ;
F_72 ( & V_14 -> V_15 ) ;
F_73 () ;
return error ;
V_115:
if ( F_35 ( V_36 ) && V_14 -> V_47 )
F_37 ( V_93 , V_14 -> V_47 ) ;
F_39 ( V_36 ) ;
V_109:
F_40 ( V_14 , F_25 ) ;
return error ;
}
static inline int F_74 ( struct V_11 * V_12 , int V_91 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_75 ( V_14 , V_91 ) ;
}
static inline int F_76 ( struct V_11 * V_12 ,
struct V_89 * V_90 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_44 < V_90 -> V_94 . V_93 )
return - V_80 ;
return 0 ;
}
static inline unsigned long F_77 ( void T_6 * V_119 , struct V_120 * V_121 , int V_122 )
{
switch( V_122 ) {
case V_123 :
return F_78 ( V_119 , V_121 , sizeof( * V_121 ) ) ;
case V_124 :
{
struct V_125 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
F_79 ( & V_121 -> V_15 , & V_126 . V_15 ) ;
V_126 . V_44 = V_121 -> V_44 ;
V_126 . V_127 = V_121 -> V_127 ;
V_126 . V_128 = V_121 -> V_128 ;
V_126 . V_129 = V_121 -> V_129 ;
V_126 . V_130 = V_121 -> V_130 ;
V_126 . V_131 = V_121 -> V_131 ;
V_126 . V_16 = V_121 -> V_16 ;
return F_78 ( V_119 , & V_126 , sizeof( V_126 ) ) ;
}
default:
return - V_80 ;
}
}
static inline unsigned long
F_80 ( struct V_120 * V_126 , void T_6 * V_119 , int V_122 )
{
switch( V_122 ) {
case V_123 :
if ( F_81 ( V_126 , V_119 , sizeof( * V_126 ) ) )
return - V_132 ;
return 0 ;
case V_124 :
{
struct V_125 V_133 ;
if ( F_81 ( & V_133 , V_119 , sizeof( V_133 ) ) )
return - V_132 ;
V_126 -> V_15 . V_134 = V_133 . V_15 . V_134 ;
V_126 -> V_15 . V_135 = V_133 . V_15 . V_135 ;
V_126 -> V_15 . V_17 = V_133 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_80 ;
}
}
static inline unsigned long F_82 ( void T_6 * V_119 , struct V_136 * V_121 , int V_122 )
{
switch( V_122 ) {
case V_123 :
return F_78 ( V_119 , V_121 , sizeof( * V_121 ) ) ;
case V_124 :
{
struct V_137 V_126 ;
if( V_121 -> V_138 > V_139 )
V_126 . V_138 = V_139 ;
else
V_126 . V_138 = ( int ) V_121 -> V_138 ;
V_126 . V_140 = V_121 -> V_140 ;
V_126 . V_141 = V_121 -> V_141 ;
V_126 . V_142 = V_121 -> V_142 ;
V_126 . V_143 = V_121 -> V_143 ;
return F_78 ( V_119 , & V_126 , sizeof( V_126 ) ) ;
}
default:
return - V_80 ;
}
}
static void F_83 ( struct V_13 * V_14 ,
unsigned long * V_144 , unsigned long * V_145 )
{
struct V_74 * V_74 ;
V_74 = F_38 ( V_14 -> V_43 ) ;
if ( F_35 ( V_14 -> V_43 ) ) {
struct V_146 * V_147 = V_74 -> V_148 ;
struct V_104 * V_149 = F_84 ( V_14 -> V_43 ) ;
* V_144 += F_85 ( V_149 ) * V_147 -> V_150 ;
} else {
#ifdef F_86
struct V_151 * V_152 = F_87 ( V_74 ) ;
F_88 ( & V_152 -> V_153 ) ;
* V_144 += V_74 -> V_148 -> V_150 ;
* V_145 += V_152 -> V_154 ;
F_89 ( & V_152 -> V_153 ) ;
#else
* V_144 += V_74 -> V_148 -> V_150 ;
#endif
}
}
static void F_90 ( struct V_1 * V_2 , unsigned long * V_155 ,
unsigned long * V_156 )
{
int V_157 ;
int V_158 , V_53 ;
* V_155 = 0 ;
* V_156 = 0 ;
V_53 = F_3 ( V_2 ) . V_53 ;
for ( V_158 = 0 , V_157 = 0 ; V_158 < V_53 ; V_157 ++ ) {
struct V_11 * V_159 ;
struct V_13 * V_14 ;
V_159 = F_91 ( & F_3 ( V_2 ) . V_23 , V_157 ) ;
if ( V_159 == NULL )
continue;
V_14 = F_5 ( V_159 , struct V_13 , V_15 ) ;
F_83 ( V_14 , V_155 , V_156 ) ;
V_158 ++ ;
}
}
static int F_92 ( struct V_1 * V_2 , int V_160 , int V_161 ,
struct V_125 T_6 * V_119 , int V_122 )
{
struct V_11 * V_12 ;
struct V_120 V_162 ;
struct V_13 * V_14 ;
int V_64 ;
if ( V_161 == V_163 ) {
if ( F_80 ( & V_162 , V_119 , V_122 ) )
return - V_132 ;
}
F_43 ( & F_3 ( V_2 ) . V_49 ) ;
F_23 () ;
V_12 = F_93 ( V_2 , & F_3 ( V_2 ) , V_160 , V_161 ,
& V_162 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) ) {
V_64 = F_70 ( V_12 ) ;
goto V_164;
}
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_64 = F_94 ( V_14 , V_161 ) ;
if ( V_64 )
goto V_164;
switch ( V_161 ) {
case V_165 :
F_24 ( & V_14 -> V_15 ) ;
F_4 ( V_2 , V_12 ) ;
goto V_166;
case V_163 :
F_24 ( & V_14 -> V_15 ) ;
V_64 = F_95 ( & V_162 . V_15 , V_12 ) ;
if ( V_64 )
goto V_167;
V_14 -> V_117 = F_33 () ;
break;
default:
V_64 = - V_80 ;
goto V_164;
}
V_167:
F_72 ( & V_14 -> V_15 ) ;
V_164:
F_73 () ;
V_166:
F_44 ( & F_3 ( V_2 ) . V_49 ) ;
return V_64 ;
}
static int F_96 ( struct V_1 * V_2 , int V_160 ,
int V_161 , int V_122 , void T_6 * V_119 )
{
int V_64 ;
struct V_13 * V_14 ;
if ( V_161 == V_168 || V_161 == V_169 ) {
V_64 = F_94 ( NULL , V_161 ) ;
if ( V_64 )
return V_64 ;
}
switch ( V_161 ) {
case V_168 :
{
struct V_136 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_141 = V_137 . V_142 = V_2 -> V_7 ;
V_137 . V_138 = V_2 -> V_3 ;
V_137 . V_143 = V_2 -> V_5 ;
V_137 . V_140 = V_98 ;
if( F_82 ( V_119 , & V_137 , V_122 ) )
return - V_132 ;
F_97 ( & F_3 ( V_2 ) . V_49 ) ;
V_64 = F_98 ( & F_3 ( V_2 ) ) ;
F_99 ( & F_3 ( V_2 ) . V_49 ) ;
if( V_64 < 0 )
V_64 = 0 ;
goto V_126;
}
case V_169 :
{
struct V_170 V_170 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
F_97 ( & F_3 ( V_2 ) . V_49 ) ;
V_170 . V_171 = F_3 ( V_2 ) . V_53 ;
F_90 ( V_2 , & V_170 . V_172 , & V_170 . V_173 ) ;
V_170 . V_10 = V_2 -> V_10 ;
V_170 . V_174 = 0 ;
V_170 . V_175 = 0 ;
V_64 = F_98 ( & F_3 ( V_2 ) ) ;
F_99 ( & F_3 ( V_2 ) . V_49 ) ;
if ( F_78 ( V_119 , & V_170 , sizeof( V_170 ) ) ) {
V_64 = - V_132 ;
goto V_126;
}
V_64 = V_64 < 0 ? 0 : V_64 ;
goto V_126;
}
case V_176 :
case V_177 :
{
struct V_120 V_178 ;
int V_179 ;
F_23 () ;
if ( V_161 == V_176 ) {
V_14 = F_14 ( V_2 , V_160 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_70 ( V_14 ) ;
goto V_180;
}
V_179 = V_14 -> V_15 . V_27 ;
} else {
V_14 = F_18 ( V_2 , V_160 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_70 ( V_14 ) ;
goto V_180;
}
V_179 = 0 ;
}
V_64 = - V_181 ;
if ( F_100 ( V_2 , & V_14 -> V_15 , V_182 ) )
goto V_180;
V_64 = F_94 ( V_14 , V_161 ) ;
if ( V_64 )
goto V_180;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
F_101 ( & V_14 -> V_15 , & V_178 . V_15 ) ;
V_178 . V_44 = V_14 -> V_44 ;
V_178 . V_127 = V_14 -> V_40 ;
V_178 . V_128 = V_14 -> V_50 ;
V_178 . V_129 = V_14 -> V_117 ;
V_178 . V_130 = V_14 -> V_116 ;
V_178 . V_131 = V_14 -> V_41 ;
V_178 . V_16 = V_14 -> V_16 ;
F_73 () ;
if ( F_77 ( V_119 , & V_178 , V_122 ) )
V_64 = - V_132 ;
else
V_64 = V_179 ;
goto V_126;
}
default:
return - V_80 ;
}
V_180:
F_73 () ;
V_126:
return V_64 ;
}
long F_102 ( int V_160 , char T_6 * V_183 , int V_91 , T_7 * V_184 ,
unsigned long V_185 )
{
struct V_13 * V_14 ;
unsigned long V_66 ;
unsigned long V_93 ;
struct V_36 * V_36 ;
int V_64 ;
unsigned long V_86 ;
unsigned long V_186 ;
int V_187 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_188 V_188 ;
T_8 V_189 ;
unsigned long V_190 = 0 ;
V_64 = - V_80 ;
if ( V_160 < 0 )
goto V_126;
else if ( ( V_66 = ( T_7 ) V_183 ) ) {
if ( V_66 & ( V_185 - 1 ) ) {
if ( V_91 & V_191 )
V_66 &= ~ ( V_185 - 1 ) ;
else
#ifndef F_103
if ( V_66 & ~ V_192 )
#endif
goto V_126;
}
V_86 = V_193 | V_194 ;
} else {
if ( ( V_91 & V_195 ) )
goto V_126;
V_86 = V_193 ;
}
if ( V_91 & V_196 ) {
V_186 = V_197 ;
V_187 = V_182 ;
V_189 = V_198 ;
} else {
V_186 = V_197 | V_199 ;
V_187 = V_182 | V_200 ;
V_189 = V_198 | V_201 ;
}
if ( V_91 & V_202 ) {
V_186 |= V_203 ;
V_187 |= V_204 ;
}
V_2 = V_42 -> V_56 -> V_57 ;
F_23 () ;
V_14 = F_18 ( V_2 , V_160 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_70 ( V_14 ) ;
goto V_180;
}
V_64 = - V_181 ;
if ( F_100 ( V_2 , & V_14 -> V_15 , V_187 ) )
goto V_180;
V_64 = F_104 ( V_14 , V_183 , V_91 ) ;
if ( V_64 )
goto V_180;
F_24 ( & V_14 -> V_15 ) ;
if ( V_14 -> V_43 == NULL ) {
F_72 ( & V_14 -> V_15 ) ;
V_64 = - V_205 ;
goto V_180;
}
V_188 = V_14 -> V_43 -> V_206 ;
F_105 ( & V_188 ) ;
V_14 -> V_16 ++ ;
V_93 = F_106 ( V_188 . V_207 -> V_208 ) ;
F_72 ( & V_14 -> V_15 ) ;
F_73 () ;
V_64 = - V_100 ;
V_39 = F_107 ( sizeof( * V_39 ) , V_209 ) ;
if ( ! V_39 ) {
F_108 ( & V_188 ) ;
goto V_210;
}
V_36 = F_109 ( & V_188 , V_189 ,
F_35 ( V_14 -> V_43 ) ?
& V_88 :
& V_211 ) ;
V_64 = F_70 ( V_36 ) ;
if ( F_16 ( V_36 ) ) {
F_57 ( V_39 ) ;
F_108 ( & V_188 ) ;
goto V_210;
}
V_36 -> V_212 = V_39 ;
V_36 -> V_213 = V_14 -> V_43 -> V_213 ;
V_39 -> V_27 = V_14 -> V_15 . V_27 ;
V_39 -> V_2 = F_110 ( V_2 ) ;
V_39 -> V_36 = V_14 -> V_43 ;
V_39 -> V_60 = NULL ;
V_64 = F_111 ( V_36 , V_186 , V_86 ) ;
if ( V_64 )
goto V_214;
F_43 ( & V_42 -> V_215 -> V_216 ) ;
if ( V_66 && ! ( V_91 & V_195 ) ) {
V_64 = - V_80 ;
if ( F_112 ( V_42 -> V_215 , V_66 , V_66 + V_93 ) )
goto V_217;
if ( V_66 < V_42 -> V_215 -> V_218 &&
V_66 > V_42 -> V_215 -> V_218 - V_93 - V_45 * 5 )
goto V_217;
}
V_66 = F_113 ( V_36 , V_66 , V_93 , V_186 , V_86 , 0 , & V_190 ) ;
* V_184 = V_66 ;
V_64 = 0 ;
if ( F_114 ( V_66 ) )
V_64 = ( long ) V_66 ;
V_217:
F_44 ( & V_42 -> V_215 -> V_216 ) ;
if ( V_190 )
F_115 ( V_66 , V_190 ) ;
V_214:
F_39 ( V_36 ) ;
V_210:
F_43 ( & F_3 ( V_2 ) . V_49 ) ;
V_14 = F_20 ( V_2 , V_160 ) ;
F_32 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_41 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_44 ( & F_3 ( V_2 ) . V_49 ) ;
return V_64 ;
V_180:
F_73 () ;
V_126:
return V_64 ;
}
static int V_26 ( struct V_219 * V_33 , void * V_220 )
{
struct V_221 * V_222 = F_116 ( V_33 ) ;
struct V_13 * V_14 = V_220 ;
unsigned long V_155 = 0 , V_156 = 0 ;
F_83 ( V_14 , & V_155 , & V_156 ) ;
#if V_25 <= 32
#define F_117 "%10lu"
#else
#define F_117 "%21lu"
#endif
return F_118 ( V_33 ,
L_5 F_117 L_6
L_7
F_117 L_8 F_117 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_44 ,
V_14 -> V_116 ,
V_14 -> V_41 ,
V_14 -> V_16 ,
F_119 ( V_222 , V_14 -> V_15 . V_134 ) ,
F_120 ( V_222 , V_14 -> V_15 . V_135 ) ,
F_119 ( V_222 , V_14 -> V_15 . V_223 ) ,
F_120 ( V_222 , V_14 -> V_15 . V_224 ) ,
V_14 -> V_40 ,
V_14 -> V_50 ,
V_14 -> V_117 ,
V_155 * V_45 ,
V_156 * V_45 ) ;
}
