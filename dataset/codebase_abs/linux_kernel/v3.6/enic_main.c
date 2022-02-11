int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_4 ;
}
int F_2 ( struct V_1 * V_1 )
{
return ( V_1 -> V_5 & V_6 ) ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_7 ;
}
int F_4 ( struct V_1 * V_1 , int V_8 )
{
#ifdef F_5
return V_8 >= 0 && V_8 < V_1 -> V_9 ;
#else
return 0 ;
#endif
}
static inline unsigned int F_6 ( struct V_1 * V_1 , unsigned int V_10 )
{
return V_10 ;
}
static inline unsigned int F_7 ( struct V_1 * V_1 , unsigned int V_11 )
{
return V_1 -> V_12 + V_11 ;
}
static inline unsigned int F_8 ( void )
{
return 0 ;
}
static inline unsigned int F_9 ( void )
{
return 1 ;
}
static inline unsigned int F_10 ( void )
{
return 2 ;
}
static inline unsigned int F_11 ( struct V_1 * V_1 , unsigned int V_10 )
{
return V_1 -> V_13 [ F_6 ( V_1 , V_10 ) ] . V_14 ;
}
static inline unsigned int F_12 ( struct V_1 * V_1 , unsigned int V_11 )
{
return V_1 -> V_13 [ F_7 ( V_1 , V_11 ) ] . V_14 ;
}
static inline unsigned int F_13 ( struct V_1 * V_1 )
{
return V_1 -> V_12 + V_1 -> V_15 ;
}
static inline unsigned int F_14 ( struct V_1 * V_1 )
{
return V_1 -> V_12 + V_1 -> V_15 + 1 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
V_19 -> V_20 = ( V_21 | V_22 ) ;
V_19 -> V_23 = ( V_24 | V_25 ) ;
V_19 -> V_26 = V_27 ;
V_19 -> V_28 = V_29 ;
if ( F_17 ( V_17 ) ) {
F_18 ( V_19 , F_19 ( V_1 -> V_30 ) ) ;
V_19 -> V_31 = V_32 ;
} else {
F_18 ( V_19 , - 1 ) ;
V_19 -> V_31 = - 1 ;
}
V_19 -> V_33 = V_34 ;
return 0 ;
}
static void F_20 ( struct V_16 * V_17 ,
struct V_35 * V_36 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_37 * V_38 ;
F_21 ( V_1 , & V_38 ) ;
F_22 ( V_36 -> V_39 , V_40 , sizeof( V_36 -> V_39 ) ) ;
F_22 ( V_36 -> V_41 , V_42 , sizeof( V_36 -> V_41 ) ) ;
F_22 ( V_36 -> V_43 , V_38 -> V_43 ,
sizeof( V_36 -> V_43 ) ) ;
F_22 ( V_36 -> V_44 , F_23 ( V_1 -> V_2 ) ,
sizeof( V_36 -> V_44 ) ) ;
}
static void F_24 ( struct V_16 * V_17 , T_1 V_45 , T_2 * V_46 )
{
unsigned int V_47 ;
switch ( V_45 ) {
case V_48 :
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
memcpy ( V_46 , V_50 [ V_47 ] . V_51 , V_52 ) ;
V_46 += V_52 ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
memcpy ( V_46 , V_54 [ V_47 ] . V_51 , V_52 ) ;
V_46 += V_52 ;
}
break;
}
}
static int F_25 ( struct V_16 * V_17 , int V_55 )
{
switch ( V_55 ) {
case V_48 :
return V_49 + V_53 ;
default:
return - V_56 ;
}
}
static void F_26 ( struct V_16 * V_17 ,
struct V_57 * V_58 , T_3 * V_46 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_59 * V_60 ;
unsigned int V_47 ;
F_27 ( V_1 , & V_60 ) ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ )
* ( V_46 ++ ) = ( ( T_3 * ) & V_60 -> V_61 ) [ V_50 [ V_47 ] . V_62 ] ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ )
* ( V_46 ++ ) = ( ( T_3 * ) & V_60 -> V_63 ) [ V_54 [ V_47 ] . V_62 ] ;
}
static T_1 F_28 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
return V_1 -> V_64 ;
}
static void F_29 ( struct V_16 * V_17 , T_1 V_65 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
V_1 -> V_64 = V_65 ;
}
static int F_30 ( struct V_16 * V_17 ,
struct V_66 * V_19 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
V_19 -> V_67 = V_1 -> V_67 ;
V_19 -> V_68 = V_1 -> V_68 ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_66 * V_19 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
T_1 V_67 ;
T_1 V_68 ;
unsigned int V_47 , V_69 ;
V_67 = F_32 ( T_1 , V_19 -> V_67 ,
F_33 ( V_1 -> V_30 ) ) ;
V_68 = F_32 ( T_1 , V_19 -> V_68 ,
F_33 ( V_1 -> V_30 ) ) ;
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_70 :
if ( V_67 != V_68 )
return - V_71 ;
V_69 = F_8 () ;
F_35 ( & V_1 -> V_69 [ V_69 ] ,
V_67 ) ;
break;
case V_72 :
if ( V_67 != V_68 )
return - V_71 ;
F_35 ( & V_1 -> V_69 [ 0 ] ,
V_67 ) ;
break;
case V_73 :
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ ) {
V_69 = F_12 ( V_1 , V_47 ) ;
F_35 ( & V_1 -> V_69 [ V_69 ] ,
V_67 ) ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
V_69 = F_11 ( V_1 , V_47 ) ;
F_35 ( & V_1 -> V_69 [ V_69 ] ,
V_68 ) ;
}
break;
default:
break;
}
V_1 -> V_67 = V_67 ;
V_1 -> V_68 = V_68 ;
return 0 ;
}
static void F_36 ( struct V_74 * V_11 , struct V_75 * V_76 )
{
struct V_1 * V_1 = F_37 ( V_11 -> V_30 ) ;
if ( V_76 -> V_77 )
F_38 ( V_1 -> V_2 , V_76 -> V_78 ,
V_76 -> V_79 , V_80 ) ;
else
F_39 ( V_1 -> V_2 , V_76 -> V_78 ,
V_76 -> V_79 , V_80 ) ;
if ( V_76 -> V_81 )
F_40 ( V_76 -> V_81 ) ;
}
static void F_41 ( struct V_74 * V_11 ,
struct V_82 * V_82 , struct V_75 * V_76 , void * V_83 )
{
F_36 ( V_11 , V_76 ) ;
}
static int F_42 ( struct V_84 * V_30 , struct V_82 * V_82 ,
T_2 type , T_4 V_85 , T_4 V_86 , void * V_83 )
{
struct V_1 * V_1 = F_37 ( V_30 ) ;
F_43 ( & V_1 -> V_87 [ V_85 ] ) ;
F_44 ( & V_1 -> V_11 [ V_85 ] , V_82 ,
V_86 , F_41 ,
V_83 ) ;
if ( F_45 ( V_1 -> V_17 ) &&
F_46 ( & V_1 -> V_11 [ V_85 ] ) >=
( V_88 + V_89 ) )
F_47 ( V_1 -> V_17 ) ;
F_48 ( & V_1 -> V_87 [ V_85 ] ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_1 )
{
unsigned int V_47 ;
T_1 V_90 ;
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ ) {
V_90 = F_50 ( & V_1 -> V_11 [ V_47 ] ) ;
if ( V_90 )
F_51 ( V_1 -> V_17 , L_1 ,
V_47 , V_90 ) ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
V_90 = F_52 ( & V_1 -> V_10 [ V_47 ] ) ;
if ( V_90 )
F_51 ( V_1 -> V_17 , L_2 ,
V_47 , V_90 ) ;
}
}
static void F_53 ( struct V_1 * V_1 )
{
T_1 V_64 = F_54 ( V_1 -> V_30 ) ;
if ( V_64 != V_1 -> V_64 ) {
F_55 ( V_1 -> V_17 , L_3 ,
V_1 -> V_64 , V_64 ) ;
V_1 -> V_64 = V_64 ;
}
}
static void F_56 ( struct V_1 * V_1 )
{
T_1 V_91 = F_57 ( V_1 -> V_30 ) ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_91 && V_91 != V_1 -> V_92 ) {
V_1 -> V_92 = V_91 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
V_91 = F_58 ( int , V_93 ,
F_32 ( int , V_94 , V_91 ) ) ;
if ( V_91 != V_17 -> V_91 )
F_59 ( & V_1 -> V_95 ) ;
} else {
if ( V_91 < V_17 -> V_91 )
F_60 ( V_17 ,
L_4
L_5 ,
V_17 -> V_91 , V_91 ) ;
}
}
}
static void F_61 ( struct V_1 * V_1 )
{
int V_96 = F_62 ( V_1 -> V_30 ) ;
int V_97 = F_17 ( V_1 -> V_17 ) ;
if ( V_96 && ! V_97 ) {
F_55 ( V_1 -> V_17 , L_6 ) ;
F_63 ( V_1 -> V_17 ) ;
} else if ( ! V_96 && V_97 ) {
F_55 ( V_1 -> V_17 , L_7 ) ;
F_64 ( V_1 -> V_17 ) ;
}
}
static void F_65 ( struct V_1 * V_1 )
{
F_53 ( V_1 ) ;
F_56 ( V_1 ) ;
F_61 ( V_1 ) ;
}
static T_5 F_66 ( int V_98 , void * V_46 )
{
struct V_16 * V_17 = V_46 ;
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_99 = F_8 () ;
unsigned int V_100 = F_9 () ;
unsigned int V_101 = F_10 () ;
T_1 V_102 ;
F_67 ( & V_1 -> V_69 [ V_99 ] ) ;
V_102 = F_68 ( V_1 -> V_103 ) ;
if ( ! V_102 ) {
F_69 ( & V_1 -> V_69 [ V_99 ] ) ;
return V_104 ;
}
if ( F_70 ( V_102 , V_101 ) ) {
F_71 ( & V_1 -> V_69 [ V_101 ] ) ;
F_65 ( V_1 ) ;
}
if ( F_70 ( V_102 , V_100 ) ) {
F_71 ( & V_1 -> V_69 [ V_100 ] ) ;
F_49 ( V_1 ) ;
F_59 ( & V_1 -> V_105 ) ;
return V_106 ;
}
if ( F_70 ( V_102 , V_99 ) ) {
if ( F_72 ( & V_1 -> V_107 [ 0 ] ) )
F_73 ( & V_1 -> V_107 [ 0 ] ) ;
} else {
F_69 ( & V_1 -> V_69 [ V_99 ] ) ;
}
return V_106 ;
}
static T_5 F_74 ( int V_98 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
F_75 ( & V_1 -> V_107 [ 0 ] ) ;
return V_106 ;
}
static T_5 F_76 ( int V_98 , void * V_46 )
{
struct V_108 * V_107 = V_46 ;
F_75 ( V_107 ) ;
return V_106 ;
}
static T_5 F_77 ( int V_98 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
unsigned int V_13 = F_7 ( V_1 , 0 ) ;
unsigned int V_69 = F_12 ( V_1 , 0 ) ;
unsigned int V_109 = - 1 ;
unsigned int V_110 ;
V_110 = F_78 ( & V_1 -> V_13 [ V_13 ] ,
V_109 , F_42 , NULL ) ;
F_79 ( & V_1 -> V_69 [ V_69 ] ,
V_110 ,
1 ,
1 ) ;
return V_106 ;
}
static T_5 F_80 ( int V_98 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
unsigned int V_69 = F_13 ( V_1 ) ;
F_71 ( & V_1 -> V_69 [ V_69 ] ) ;
F_49 ( V_1 ) ;
F_59 ( & V_1 -> V_105 ) ;
return V_106 ;
}
static T_5 F_81 ( int V_98 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
unsigned int V_69 = F_14 ( V_1 ) ;
F_71 ( & V_1 -> V_69 [ V_69 ] ) ;
F_65 ( V_1 ) ;
return V_106 ;
}
static inline void F_82 ( struct V_1 * V_1 ,
struct V_74 * V_11 , struct V_111 * V_112 ,
unsigned int V_113 , int V_114 )
{
const T_6 * V_115 ;
for ( V_115 = F_83 ( V_112 ) -> V_116 ; V_113 ; V_115 ++ ) {
V_113 -= F_84 ( V_115 ) ;
F_85 ( V_11 , V_112 ,
F_86 ( & V_1 -> V_2 -> V_117 ,
V_115 , 0 , F_84 ( V_115 ) ,
V_118 ) ,
F_84 ( V_115 ) ,
( V_113 == 0 ) ,
V_114 ) ;
}
}
static inline void F_87 ( struct V_1 * V_1 ,
struct V_74 * V_11 , struct V_111 * V_112 ,
int V_119 , unsigned int V_120 , int V_114 )
{
unsigned int V_121 = F_88 ( V_112 ) ;
unsigned int V_113 = V_112 -> V_79 - V_121 ;
int V_122 = ( V_113 == 0 ) ;
F_89 ( V_11 , V_112 ,
F_90 ( V_1 -> V_2 , V_112 -> V_46 ,
V_121 , V_80 ) ,
V_121 ,
V_119 , V_120 ,
V_122 , V_114 ) ;
if ( ! V_122 )
F_82 ( V_1 , V_11 , V_112 , V_113 , V_114 ) ;
}
static inline void F_91 ( struct V_1 * V_1 ,
struct V_74 * V_11 , struct V_111 * V_112 ,
int V_119 , unsigned int V_120 , int V_114 )
{
unsigned int V_121 = F_88 ( V_112 ) ;
unsigned int V_113 = V_112 -> V_79 - V_121 ;
unsigned int V_123 = F_92 ( V_112 ) ;
unsigned int V_124 = V_123 + V_112 -> V_124 ;
int V_122 = ( V_113 == 0 ) ;
F_93 ( V_11 , V_112 ,
F_90 ( V_1 -> V_2 , V_112 -> V_46 ,
V_121 , V_80 ) ,
V_121 ,
V_124 ,
V_123 ,
V_119 , V_120 ,
V_122 , V_114 ) ;
if ( ! V_122 )
F_82 ( V_1 , V_11 , V_112 , V_113 , V_114 ) ;
}
static inline void F_94 ( struct V_1 * V_1 ,
struct V_74 * V_11 , struct V_111 * V_112 , unsigned int V_125 ,
int V_119 , unsigned int V_120 , int V_114 )
{
unsigned int V_126 = F_88 ( V_112 ) ;
unsigned int V_113 = V_112 -> V_79 - V_126 ;
unsigned int V_123 = F_95 ( V_112 ) + F_96 ( V_112 ) ;
int V_122 = ( V_113 == 0 ) ;
unsigned int V_79 ;
T_7 V_78 ;
unsigned int V_62 = 0 ;
T_6 * V_115 ;
if ( V_112 -> V_127 == F_97 ( V_128 ) ) {
F_98 ( V_112 ) -> V_129 = 0 ;
F_99 ( V_112 ) -> V_129 = ~ F_100 ( F_98 ( V_112 ) -> V_130 ,
F_98 ( V_112 ) -> V_131 , 0 , V_132 , 0 ) ;
} else if ( V_112 -> V_127 == F_97 ( V_133 ) ) {
F_99 ( V_112 ) -> V_129 = ~ F_101 ( & F_102 ( V_112 ) -> V_130 ,
& F_102 ( V_112 ) -> V_131 , 0 , V_132 , 0 ) ;
}
while ( V_126 ) {
V_79 = F_103 ( V_126 , ( unsigned int ) V_134 ) ;
V_78 = F_90 ( V_1 -> V_2 , V_112 -> V_46 + V_62 ,
V_79 , V_80 ) ;
F_104 ( V_11 , V_112 ,
V_78 ,
V_79 ,
V_125 , V_123 ,
V_119 , V_120 ,
V_122 && ( V_79 == V_126 ) , V_114 ) ;
V_126 -= V_79 ;
V_62 += V_79 ;
}
if ( V_122 )
return;
for ( V_115 = F_83 ( V_112 ) -> V_116 ; V_113 ; V_115 ++ ) {
V_113 -= F_84 ( V_115 ) ;
V_126 = F_84 ( V_115 ) ;
V_62 = 0 ;
while ( V_126 ) {
V_79 = F_103 ( V_126 ,
( unsigned int ) V_134 ) ;
V_78 = F_86 ( & V_1 -> V_2 -> V_117 , V_115 ,
V_62 , V_79 ,
V_118 ) ;
F_85 ( V_11 , V_112 ,
V_78 ,
V_79 ,
( V_113 == 0 ) &&
( V_79 == V_126 ) ,
V_114 ) ;
V_126 -= V_79 ;
V_62 += V_79 ;
}
}
}
static inline void F_105 ( struct V_1 * V_1 ,
struct V_74 * V_11 , struct V_111 * V_112 )
{
unsigned int V_125 = F_83 ( V_112 ) -> V_135 ;
unsigned int V_120 = 0 ;
int V_119 = 0 ;
int V_114 = 0 ;
if ( F_106 ( V_112 ) ) {
V_119 = 1 ;
V_120 = F_107 ( V_112 ) ;
} else if ( V_1 -> V_136 ) {
V_120 = V_1 -> V_137 ;
V_114 = 1 ;
}
if ( V_125 )
F_94 ( V_1 , V_11 , V_112 , V_125 ,
V_119 , V_120 , V_114 ) ;
else if ( V_112 -> V_138 == V_139 )
F_91 ( V_1 , V_11 , V_112 ,
V_119 , V_120 , V_114 ) ;
else
F_87 ( V_1 , V_11 , V_112 ,
V_119 , V_120 , V_114 ) ;
}
static T_8 F_108 ( struct V_111 * V_112 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_74 * V_11 = & V_1 -> V_11 [ 0 ] ;
unsigned long V_140 ;
if ( V_112 -> V_79 <= 0 ) {
F_109 ( V_112 ) ;
return V_141 ;
}
if ( F_83 ( V_112 ) -> V_135 == 0 &&
F_83 ( V_112 ) -> V_142 + 1 > V_143 &&
F_110 ( V_112 ) ) {
F_109 ( V_112 ) ;
return V_141 ;
}
F_111 ( & V_1 -> V_87 [ 0 ] , V_140 ) ;
if ( F_46 ( V_11 ) <
F_83 ( V_112 ) -> V_142 + V_89 ) {
F_112 ( V_17 ) ;
F_51 ( V_17 , L_8 ) ;
F_113 ( & V_1 -> V_87 [ 0 ] , V_140 ) ;
return V_144 ;
}
F_105 ( V_1 , V_11 , V_112 ) ;
if ( F_46 ( V_11 ) < V_88 + V_89 )
F_112 ( V_17 ) ;
F_113 ( & V_1 -> V_87 [ 0 ] , V_140 ) ;
return V_141 ;
}
static struct V_145 * F_114 ( struct V_16 * V_17 ,
struct V_145 * V_146 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_59 * V_58 ;
F_27 ( V_1 , & V_58 ) ;
V_146 -> V_147 = V_58 -> V_61 . V_148 ;
V_146 -> V_149 = V_58 -> V_61 . V_150 ;
V_146 -> V_151 = V_58 -> V_61 . V_151 ;
V_146 -> V_152 = V_58 -> V_61 . V_153 ;
V_146 -> V_154 = V_58 -> V_63 . V_155 ;
V_146 -> V_156 = V_58 -> V_63 . V_157 ;
V_146 -> V_158 = V_58 -> V_63 . V_158 ;
V_146 -> V_159 = V_58 -> V_63 . V_160 ;
V_146 -> V_161 = V_1 -> V_162 ;
V_146 -> V_163 = V_1 -> V_164 ;
V_146 -> V_165 = V_58 -> V_63 . V_166 + V_58 -> V_63 . V_167 ;
return V_146 ;
}
void F_115 ( struct V_1 * V_1 )
{
V_1 -> V_168 = 0 ;
V_1 -> V_169 = 0 ;
V_1 -> V_140 = 0 ;
}
static int F_116 ( struct V_16 * V_17 , char * V_170 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
if ( ! F_117 ( V_170 ) && ! F_118 ( V_170 ) )
return - V_171 ;
} else {
if ( ! F_117 ( V_170 ) )
return - V_171 ;
}
memcpy ( V_17 -> V_172 , V_170 , V_17 -> V_173 ) ;
V_17 -> V_174 &= ~ V_175 ;
return 0 ;
}
static int F_119 ( struct V_16 * V_17 , void * V_176 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_177 * V_130 = V_176 ;
char * V_170 = V_130 -> V_178 ;
int V_179 ;
if ( F_120 ( V_1 -> V_17 ) ) {
V_179 = F_121 ( V_1 ) ;
if ( V_179 )
return V_179 ;
}
V_179 = F_116 ( V_17 , V_170 ) ;
if ( V_179 )
return V_179 ;
if ( F_120 ( V_1 -> V_17 ) ) {
V_179 = F_122 ( V_1 ) ;
if ( V_179 )
return V_179 ;
}
return V_179 ;
}
static int F_123 ( struct V_16 * V_17 , void * V_176 )
{
struct V_177 * V_130 = V_176 ;
char * V_170 = V_130 -> V_178 ;
struct V_1 * V_1 = F_16 ( V_17 ) ;
int V_179 ;
V_179 = F_121 ( V_1 ) ;
if ( V_179 )
return V_179 ;
V_179 = F_116 ( V_17 , V_170 ) ;
if ( V_179 )
return V_179 ;
return F_122 ( V_1 ) ;
}
static void F_124 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_180 * V_181 ;
unsigned int V_168 = F_125 ( V_17 ) ;
T_2 V_182 [ V_183 ] [ V_184 ] ;
unsigned int V_47 , V_185 ;
if ( V_168 > V_183 ) {
F_60 ( V_17 , L_9
L_10 ,
V_183 , V_168 ) ;
V_168 = V_183 ;
}
V_47 = 0 ;
F_126 (ha, netdev) {
if ( V_47 == V_168 )
break;
memcpy ( V_182 [ V_47 ++ ] , V_181 -> V_170 , V_184 ) ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_168 ; V_47 ++ ) {
for ( V_185 = 0 ; V_185 < V_168 ; V_185 ++ )
if ( F_127 ( V_1 -> V_182 [ V_47 ] , V_182 [ V_185 ] ) )
break;
if ( V_185 == V_168 )
F_128 ( V_1 , V_1 -> V_182 [ V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_168 ; V_47 ++ ) {
for ( V_185 = 0 ; V_185 < V_1 -> V_168 ; V_185 ++ )
if ( F_127 ( V_182 [ V_47 ] , V_1 -> V_182 [ V_185 ] ) )
break;
if ( V_185 == V_1 -> V_168 )
F_129 ( V_1 , V_182 [ V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_168 ; V_47 ++ )
memcpy ( V_1 -> V_182 [ V_47 ] , V_182 [ V_47 ] , V_184 ) ;
V_1 -> V_168 = V_168 ;
}
static void F_130 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_180 * V_181 ;
unsigned int V_169 = F_131 ( V_17 ) ;
T_2 V_186 [ V_187 ] [ V_184 ] ;
unsigned int V_47 , V_185 ;
if ( V_169 > V_187 ) {
F_60 ( V_17 , L_9
L_11 ,
V_187 , V_169 ) ;
V_169 = V_187 ;
}
V_47 = 0 ;
F_132 (ha, netdev) {
if ( V_47 == V_169 )
break;
memcpy ( V_186 [ V_47 ++ ] , V_181 -> V_170 , V_184 ) ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_169 ; V_47 ++ ) {
for ( V_185 = 0 ; V_185 < V_169 ; V_185 ++ )
if ( F_127 ( V_1 -> V_186 [ V_47 ] , V_186 [ V_185 ] ) )
break;
if ( V_185 == V_169 )
F_128 ( V_1 , V_1 -> V_186 [ V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_169 ; V_47 ++ ) {
for ( V_185 = 0 ; V_185 < V_1 -> V_169 ; V_185 ++ )
if ( F_127 ( V_186 [ V_47 ] , V_1 -> V_186 [ V_185 ] ) )
break;
if ( V_185 == V_1 -> V_169 )
F_129 ( V_1 , V_186 [ V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_169 ; V_47 ++ )
memcpy ( V_1 -> V_186 [ V_47 ] , V_186 [ V_47 ] , V_184 ) ;
V_1 -> V_169 = V_169 ;
}
static void F_133 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
int V_188 = 1 ;
int V_159 = ( V_17 -> V_140 & V_189 ) ? 1 : 0 ;
int V_190 = ( V_17 -> V_140 & V_191 ) ? 1 : 0 ;
int V_192 = ( V_17 -> V_140 & V_193 ) ||
F_131 ( V_17 ) > V_187 ;
int V_194 = ( V_17 -> V_140 & V_195 ) ||
F_125 ( V_17 ) > V_183 ;
unsigned int V_140 = V_17 -> V_140 |
( V_194 ? V_195 : 0 ) |
( V_192 ? V_193 : 0 ) ;
if ( V_1 -> V_140 != V_140 ) {
V_1 -> V_140 = V_140 ;
F_134 ( V_1 , V_188 ,
V_159 , V_190 , V_192 , V_194 ) ;
}
if ( ! V_192 ) {
F_130 ( V_1 ) ;
if ( ! V_194 )
F_124 ( V_1 ) ;
}
}
static void F_135 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
F_59 ( & V_1 -> V_105 ) ;
}
static int F_136 ( struct V_16 * V_17 , int V_8 , T_2 * V_196 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_197 * V_198 ;
int V_179 ;
F_137 ( V_1 , V_8 , V_198 , & V_179 ) ;
if ( V_179 )
return V_179 ;
if ( F_117 ( V_196 ) || F_118 ( V_196 ) ) {
if ( V_8 == V_199 ) {
memcpy ( V_198 -> V_200 , V_196 , V_184 ) ;
return 0 ;
} else {
F_138 ( V_8 , V_179 , V_1 ,
V_201 , V_196 ) ;
return F_139 ( V_179 ) ;
}
} else
return - V_71 ;
}
static int F_140 ( struct V_16 * V_17 , int V_8 ,
struct V_202 * V_26 [] )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_197 V_203 ;
struct V_197 * V_198 ;
int V_179 = 0 , V_204 = 1 ;
F_137 ( V_1 , V_8 , V_198 , & V_179 ) ;
if ( V_179 )
return V_179 ;
if ( ! V_26 [ V_205 ] )
return - V_56 ;
memcpy ( & V_203 , V_198 , sizeof( * V_1 -> V_198 ) ) ;
memset ( V_198 , 0 , sizeof( * V_1 -> V_198 ) ) ;
V_198 -> V_206 |= V_207 ;
V_198 -> V_208 = F_141 ( V_26 [ V_205 ] ) ;
if ( V_26 [ V_209 ] ) {
V_198 -> V_206 |= V_210 ;
memcpy ( V_198 -> V_51 , F_142 ( V_26 [ V_209 ] ) ,
V_211 ) ;
}
if ( V_26 [ V_212 ] ) {
V_198 -> V_206 |= V_213 ;
memcpy ( V_198 -> V_214 ,
F_142 ( V_26 [ V_212 ] ) , V_215 ) ;
}
if ( V_26 [ V_216 ] ) {
V_198 -> V_206 |= V_217 ;
memcpy ( V_198 -> V_218 ,
F_142 ( V_26 [ V_216 ] ) , V_215 ) ;
}
if ( V_8 == V_199 ) {
if ( ! F_118 ( V_203 . V_200 ) )
memcpy ( V_198 -> V_219 , V_203 . V_200 , V_184 ) ;
if ( F_118 ( V_17 -> V_172 ) )
F_143 ( V_17 ) ;
} else {
F_138 ( V_8 , V_179 , V_1 ,
V_220 , V_198 -> V_219 ) ;
if ( V_179 ) {
F_51 ( V_17 , L_12 , V_8 ) ;
memcpy ( V_198 , & V_203 , sizeof( * V_198 ) ) ;
return F_139 ( V_179 ) ;
}
}
V_179 = F_144 ( V_1 , V_8 , & V_203 , & V_204 ) ;
if ( V_179 ) {
if ( V_204 ) {
memcpy ( V_198 , & V_203 , sizeof( * V_198 ) ) ;
} else {
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
if ( V_8 == V_199 )
memset ( V_17 -> V_172 , 0 , V_184 ) ;
}
} else {
V_198 -> V_206 |= V_221 ;
if ( V_198 -> V_208 == V_222 ) {
memset ( V_198 -> V_219 , 0 , V_184 ) ;
if ( V_8 == V_199 )
memset ( V_17 -> V_172 , 0 , V_184 ) ;
}
}
if ( V_8 == V_199 )
memset ( V_198 -> V_200 , 0 , V_184 ) ;
return V_179 ;
}
static int F_145 ( struct V_16 * V_17 , int V_8 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
T_4 V_223 = V_224 ;
struct V_197 * V_198 ;
int V_179 ;
F_137 ( V_1 , V_8 , V_198 , & V_179 ) ;
if ( V_179 )
return V_179 ;
if ( ! ( V_198 -> V_206 & V_221 ) )
return - V_225 ;
V_179 = F_146 ( V_1 , V_8 , V_198 -> V_208 , & V_223 ) ;
if ( V_179 )
return V_179 ;
if ( F_147 ( V_112 , V_205 , V_198 -> V_208 ) ||
F_147 ( V_112 , V_226 , V_223 ) ||
( ( V_198 -> V_206 & V_210 ) &&
F_148 ( V_112 , V_209 , V_211 , V_198 -> V_51 ) ) ||
( ( V_198 -> V_206 & V_213 ) &&
F_148 ( V_112 , V_212 , V_215 ,
V_198 -> V_214 ) ) ||
( ( V_198 -> V_206 & V_217 ) &&
F_148 ( V_112 , V_216 , V_215 , V_198 -> V_218 ) ) )
goto V_227;
return 0 ;
V_227:
return - V_228 ;
}
static void F_149 ( struct V_229 * V_10 , struct V_230 * V_76 )
{
struct V_1 * V_1 = F_37 ( V_10 -> V_30 ) ;
if ( ! V_76 -> V_81 )
return;
F_38 ( V_1 -> V_2 , V_76 -> V_78 ,
V_76 -> V_79 , V_231 ) ;
F_40 ( V_76 -> V_81 ) ;
}
static int F_150 ( struct V_229 * V_10 )
{
struct V_1 * V_1 = F_37 ( V_10 -> V_30 ) ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_111 * V_112 ;
unsigned int V_79 = V_17 -> V_91 + V_232 ;
unsigned int V_233 = 0 ;
T_7 V_78 ;
V_112 = F_151 ( V_17 , V_79 ) ;
if ( ! V_112 )
return - V_234 ;
V_78 = F_90 ( V_1 -> V_2 , V_112 -> V_46 ,
V_79 , V_231 ) ;
F_152 ( V_10 , V_112 , V_233 ,
V_78 , V_79 ) ;
return 0 ;
}
static void F_153 ( struct V_229 * V_10 ,
struct V_82 * V_82 , struct V_230 * V_76 ,
int V_235 , void * V_83 )
{
struct V_1 * V_1 = F_37 ( V_10 -> V_30 ) ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_111 * V_112 ;
T_2 type , V_236 , V_122 , V_77 , V_237 , V_238 ;
T_2 V_239 , V_240 , V_241 , V_242 , V_243 ;
T_2 V_244 , V_245 , V_246 , V_247 ;
T_2 V_248 , V_249 , V_250 , V_251 , V_252 , V_253 ;
T_2 V_254 ;
T_4 V_85 , V_86 , V_255 , V_256 , V_257 ;
T_1 V_258 ;
if ( V_235 )
return;
V_112 = V_76 -> V_81 ;
F_154 ( V_112 -> V_46 - V_259 ) ;
F_38 ( V_1 -> V_2 , V_76 -> V_78 ,
V_76 -> V_79 , V_231 ) ;
F_155 ( (struct V_260 * ) V_82 ,
& type , & V_236 , & V_85 , & V_86 ,
& V_237 , & V_239 , & V_122 , & V_77 , & V_252 ,
& V_253 , & V_258 , & V_255 ,
& V_254 , & V_238 , & V_256 , & V_257 ,
& V_240 , & V_241 , & V_242 ,
& V_243 , & V_244 , & V_245 , & V_246 ,
& V_247 , & V_248 , & V_249 , & V_250 ,
& V_251 ) ;
if ( V_254 ) {
if ( ! V_251 ) {
if ( V_255 > 0 )
V_1 -> V_164 ++ ;
else if ( V_255 == 0 )
V_1 -> V_162 ++ ;
}
F_40 ( V_112 ) ;
return;
}
if ( V_122 && V_255 > 0 ) {
F_156 ( V_112 , V_255 ) ;
V_112 -> V_127 = F_157 ( V_112 , V_17 ) ;
if ( ( V_17 -> V_261 & V_262 ) && ! V_253 ) {
V_112 -> V_263 = F_158 ( V_257 ) ;
V_112 -> V_138 = V_264 ;
}
if ( V_238 )
F_159 ( V_112 , V_256 ) ;
if ( V_17 -> V_261 & V_265 )
F_160 ( & V_1 -> V_107 [ V_85 ] , V_112 ) ;
else
F_161 ( V_112 ) ;
} else {
F_40 ( V_112 ) ;
}
}
static int F_162 ( struct V_84 * V_30 , struct V_82 * V_82 ,
T_2 type , T_4 V_85 , T_4 V_86 , void * V_83 )
{
struct V_1 * V_1 = F_37 ( V_30 ) ;
F_163 ( & V_1 -> V_10 [ V_85 ] , V_82 ,
V_86 , V_266 ,
F_153 , V_83 ) ;
return 0 ;
}
static int F_164 ( struct V_108 * V_107 , int V_267 )
{
struct V_16 * V_17 = V_107 -> V_117 ;
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_268 = F_6 ( V_1 , 0 ) ;
unsigned int V_269 = F_7 ( V_1 , 0 ) ;
unsigned int V_69 = F_8 () ;
unsigned int V_270 = V_267 ;
unsigned int V_109 = - 1 ;
unsigned int V_271 , V_272 , V_110 ;
int V_179 ;
V_272 = F_78 ( & V_1 -> V_13 [ V_268 ] ,
V_270 , F_162 , NULL ) ;
V_110 = F_78 ( & V_1 -> V_13 [ V_269 ] ,
V_109 , F_42 , NULL ) ;
V_271 = V_272 + V_110 ;
if ( V_271 > 0 )
F_79 ( & V_1 -> V_69 [ V_69 ] ,
V_271 ,
0 ,
0 ) ;
V_179 = F_165 ( & V_1 -> V_10 [ 0 ] , F_150 ) ;
if ( V_179 )
V_272 = V_270 ;
if ( V_272 < V_270 ) {
F_166 ( V_107 ) ;
F_69 ( & V_1 -> V_69 [ V_69 ] ) ;
}
return V_272 ;
}
static int F_167 ( struct V_108 * V_107 , int V_267 )
{
struct V_16 * V_17 = V_107 -> V_117 ;
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_10 = ( V_107 - & V_1 -> V_107 [ 0 ] ) ;
unsigned int V_13 = F_6 ( V_1 , V_10 ) ;
unsigned int V_69 = F_11 ( V_1 , V_10 ) ;
unsigned int V_273 = V_267 ;
unsigned int V_271 ;
int V_179 ;
V_271 = F_78 ( & V_1 -> V_13 [ V_13 ] ,
V_273 , F_162 , NULL ) ;
if ( V_271 > 0 )
F_79 ( & V_1 -> V_69 [ V_69 ] ,
V_271 ,
0 ,
0 ) ;
V_179 = F_165 ( & V_1 -> V_10 [ V_10 ] , F_150 ) ;
if ( V_179 )
V_271 = V_273 ;
if ( V_271 < V_273 ) {
F_166 ( V_107 ) ;
F_69 ( & V_1 -> V_69 [ V_69 ] ) ;
}
return V_271 ;
}
static void F_168 ( unsigned long V_46 )
{
struct V_1 * V_1 = (struct V_1 * ) V_46 ;
F_65 ( V_1 ) ;
F_169 ( & V_1 -> V_274 ,
F_170 ( V_275 + V_276 ) ) ;
}
static void F_171 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
unsigned int V_47 ;
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_70 :
F_172 ( V_1 -> V_2 -> V_98 , V_17 ) ;
break;
case V_72 :
F_172 ( V_1 -> V_2 -> V_98 , V_1 ) ;
break;
case V_73 :
for ( V_47 = 0 ; V_47 < F_173 ( V_1 -> V_277 ) ; V_47 ++ )
if ( V_1 -> V_277 [ V_47 ] . V_278 )
F_172 ( V_1 -> V_279 [ V_47 ] . V_280 ,
V_1 -> V_277 [ V_47 ] . V_281 ) ;
break;
default:
break;
}
}
static int F_174 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
unsigned int V_47 , V_69 ;
int V_179 = 0 ;
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_70 :
V_179 = F_175 ( V_1 -> V_2 -> V_98 , F_66 ,
V_282 , V_17 -> V_51 , V_17 ) ;
break;
case V_72 :
V_179 = F_175 ( V_1 -> V_2 -> V_98 , F_74 ,
0 , V_17 -> V_51 , V_1 ) ;
break;
case V_73 :
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
V_69 = F_11 ( V_1 , V_47 ) ;
sprintf ( V_1 -> V_277 [ V_69 ] . V_283 ,
L_13 , V_17 -> V_51 , V_47 ) ;
V_1 -> V_277 [ V_69 ] . V_284 = F_76 ;
V_1 -> V_277 [ V_69 ] . V_281 = & V_1 -> V_107 [ V_47 ] ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ ) {
V_69 = F_12 ( V_1 , V_47 ) ;
sprintf ( V_1 -> V_277 [ V_69 ] . V_283 ,
L_14 , V_17 -> V_51 , V_47 ) ;
V_1 -> V_277 [ V_69 ] . V_284 = F_77 ;
V_1 -> V_277 [ V_69 ] . V_281 = V_1 ;
}
V_69 = F_13 ( V_1 ) ;
sprintf ( V_1 -> V_277 [ V_69 ] . V_283 ,
L_15 , V_17 -> V_51 ) ;
V_1 -> V_277 [ V_69 ] . V_284 = F_80 ;
V_1 -> V_277 [ V_69 ] . V_281 = V_1 ;
V_69 = F_14 ( V_1 ) ;
sprintf ( V_1 -> V_277 [ V_69 ] . V_283 ,
L_16 , V_17 -> V_51 ) ;
V_1 -> V_277 [ V_69 ] . V_284 = F_81 ;
V_1 -> V_277 [ V_69 ] . V_281 = V_1 ;
for ( V_47 = 0 ; V_47 < F_173 ( V_1 -> V_277 ) ; V_47 ++ )
V_1 -> V_277 [ V_47 ] . V_278 = 0 ;
for ( V_47 = 0 ; V_47 < V_1 -> V_285 ; V_47 ++ ) {
V_179 = F_175 ( V_1 -> V_279 [ V_47 ] . V_280 ,
V_1 -> V_277 [ V_47 ] . V_284 , 0 ,
V_1 -> V_277 [ V_47 ] . V_283 ,
V_1 -> V_277 [ V_47 ] . V_281 ) ;
if ( V_179 ) {
F_171 ( V_1 ) ;
break;
}
V_1 -> V_277 [ V_47 ] . V_278 = 1 ;
}
break;
default:
break;
}
return V_179 ;
}
static void F_176 ( struct V_1 * V_1 )
{
unsigned int V_47 ;
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_70 :
case V_72 :
F_177 ( V_1 -> V_2 -> V_98 ) ;
break;
case V_73 :
for ( V_47 = 0 ; V_47 < V_1 -> V_285 ; V_47 ++ )
F_177 ( V_1 -> V_279 [ V_47 ] . V_280 ) ;
break;
default:
break;
}
}
static int F_178 ( struct V_1 * V_1 )
{
int V_179 ;
F_43 ( & V_1 -> V_286 ) ;
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_70 :
V_179 = F_179 ( V_1 -> V_30 ,
F_10 () ) ;
break;
case V_73 :
V_179 = F_179 ( V_1 -> V_30 ,
F_14 ( V_1 ) ) ;
break;
default:
V_179 = F_179 ( V_1 -> V_30 , - 1 ) ;
break;
}
F_48 ( & V_1 -> V_286 ) ;
return V_179 ;
}
static void F_180 ( struct V_1 * V_1 )
{
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_72 :
F_169 ( & V_1 -> V_274 , V_275 ) ;
break;
default:
break;
}
}
static int F_181 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_47 ;
int V_179 ;
V_179 = F_174 ( V_1 ) ;
if ( V_179 ) {
F_51 ( V_17 , L_17 ) ;
return V_179 ;
}
V_179 = F_178 ( V_1 ) ;
if ( V_179 ) {
F_51 ( V_17 ,
L_18 ) ;
goto V_287;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
F_165 ( & V_1 -> V_10 [ V_47 ] , F_150 ) ;
if ( F_182 ( & V_1 -> V_10 [ V_47 ] ) == 0 ) {
F_51 ( V_17 , L_19 ) ;
V_179 = - V_234 ;
goto V_288;
}
}
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ )
F_183 ( & V_1 -> V_11 [ V_47 ] ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_184 ( & V_1 -> V_10 [ V_47 ] ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_122 ( V_1 ) ;
F_133 ( V_17 ) ;
F_47 ( V_17 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_185 ( & V_1 -> V_107 [ V_47 ] ) ;
F_186 ( V_1 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_285 ; V_47 ++ )
F_69 ( & V_1 -> V_69 [ V_47 ] ) ;
F_180 ( V_1 ) ;
return 0 ;
V_288:
F_187 ( V_1 ) ;
V_287:
F_171 ( V_1 ) ;
return V_179 ;
}
static int F_188 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
unsigned int V_47 ;
int V_179 ;
for ( V_47 = 0 ; V_47 < V_1 -> V_285 ; V_47 ++ ) {
F_67 ( & V_1 -> V_69 [ V_47 ] ) ;
( void ) F_189 ( & V_1 -> V_69 [ V_47 ] ) ;
}
F_176 ( V_1 ) ;
F_190 ( & V_1 -> V_274 ) ;
F_191 ( V_1 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_192 ( & V_1 -> V_107 [ V_47 ] ) ;
F_64 ( V_17 ) ;
F_193 ( V_17 ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_121 ( V_1 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ ) {
V_179 = F_194 ( & V_1 -> V_11 [ V_47 ] ) ;
if ( V_179 )
return V_179 ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
V_179 = F_195 ( & V_1 -> V_10 [ V_47 ] ) ;
if ( V_179 )
return V_179 ;
}
F_187 ( V_1 ) ;
F_171 ( V_1 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ )
F_196 ( & V_1 -> V_11 [ V_47 ] , F_36 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_197 ( & V_1 -> V_10 [ V_47 ] , F_149 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_289 ; V_47 ++ )
F_198 ( & V_1 -> V_13 [ V_47 ] ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_285 ; V_47 ++ )
F_199 ( & V_1 -> V_69 [ V_47 ] ) ;
return 0 ;
}
static int F_200 ( struct V_16 * V_17 , int V_290 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
int V_291 = F_120 ( V_17 ) ;
if ( V_290 < V_93 || V_290 > V_94 )
return - V_71 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
return - V_56 ;
if ( V_291 )
F_188 ( V_17 ) ;
V_17 -> V_91 = V_290 ;
if ( V_17 -> V_91 > V_1 -> V_92 )
F_60 ( V_17 ,
L_20 ,
V_17 -> V_91 , V_1 -> V_92 ) ;
if ( V_291 )
F_181 ( V_17 ) ;
return 0 ;
}
static void F_201 ( struct V_292 * V_293 )
{
struct V_1 * V_1 = F_202 ( V_293 , struct V_1 , V_95 ) ;
struct V_16 * V_17 = V_1 -> V_17 ;
int V_290 = F_57 ( V_1 -> V_30 ) ;
int V_179 ;
unsigned int V_47 ;
V_290 = F_58 ( int , V_93 , F_32 ( int , V_94 , V_290 ) ) ;
F_203 () ;
F_190 ( & V_1 -> V_274 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_192 ( & V_1 -> V_107 [ V_47 ] ) ;
F_67 ( & V_1 -> V_69 [ 0 ] ) ;
F_176 ( V_1 ) ;
V_179 = F_195 ( & V_1 -> V_10 [ 0 ] ) ;
if ( V_179 ) {
F_51 ( V_17 , L_21 ) ;
return;
}
F_197 ( & V_1 -> V_10 [ 0 ] , F_149 ) ;
F_198 ( & V_1 -> V_13 [ 0 ] ) ;
F_199 ( & V_1 -> V_69 [ 0 ] ) ;
V_17 -> V_91 = V_290 ;
F_165 ( & V_1 -> V_10 [ 0 ] , F_150 ) ;
if ( F_182 ( & V_1 -> V_10 [ 0 ] ) == 0 ) {
F_51 ( V_17 , L_22 ) ;
return;
}
F_184 ( & V_1 -> V_10 [ 0 ] ) ;
F_185 ( & V_1 -> V_107 [ 0 ] ) ;
F_69 ( & V_1 -> V_69 [ 0 ] ) ;
F_180 ( V_1 ) ;
F_204 () ;
F_55 ( V_17 , L_23 , V_17 -> V_91 ) ;
}
static void F_205 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
struct V_84 * V_30 = V_1 -> V_30 ;
unsigned int V_47 , V_69 ;
switch ( F_34 ( V_30 ) ) {
case V_73 :
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ ) {
V_69 = F_11 ( V_1 , V_47 ) ;
F_76 ( V_1 -> V_279 [ V_69 ] . V_280 ,
& V_1 -> V_107 [ V_47 ] ) ;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ ) {
V_69 = F_12 ( V_1 , V_47 ) ;
F_77 ( V_1 -> V_279 [ V_69 ] . V_280 , V_1 ) ;
}
break;
case V_72 :
F_74 ( V_1 -> V_2 -> V_98 , V_1 ) ;
break;
case V_70 :
F_66 ( V_1 -> V_2 -> V_98 , V_17 ) ;
break;
default:
break;
}
}
static int F_206 ( struct V_84 * V_30 ,
int (* F_207)( struct V_84 * , int ) ,
int (* F_208)( struct V_84 * , int * ) ,
int V_294 )
{
unsigned long time ;
int V_295 ;
int V_179 ;
F_209 ( F_210 () ) ;
V_179 = F_207 ( V_30 , V_294 ) ;
if ( V_179 )
return V_179 ;
time = V_275 + ( V_296 * 2 ) ;
do {
V_179 = F_208 ( V_30 , & V_295 ) ;
if ( V_179 )
return V_179 ;
if ( V_295 )
return 0 ;
F_211 ( V_296 / 10 ) ;
} while ( F_212 ( time , V_275 ) );
return - V_297 ;
}
static int F_213 ( struct V_1 * V_1 )
{
int V_179 ;
V_179 = F_206 ( V_1 -> V_30 , V_298 ,
V_299 , 0 ) ;
if ( V_179 )
F_214 ( F_215 ( V_1 ) , L_24 ,
V_179 ) ;
return V_179 ;
}
static int F_216 ( struct V_1 * V_1 )
{
int V_179 ;
V_179 = F_206 ( V_1 -> V_30 , V_300 ,
V_301 , 0 ) ;
if ( V_179 )
F_51 ( V_1 -> V_17 , L_25 ,
V_179 ) ;
return V_179 ;
}
static int F_217 ( struct V_1 * V_1 )
{
T_7 V_302 ;
union V_303 * V_304 = NULL ;
union V_303 V_305 = {
. V_306 [ 0 ] . V_307 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_306 [ 1 ] . V_307 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_306 [ 2 ] . V_307 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_306 [ 3 ] . V_307 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_179 ;
V_304 = F_218 ( V_1 -> V_2 ,
sizeof( union V_303 ) , & V_302 ) ;
if ( ! V_304 )
return - V_234 ;
memcpy ( V_304 , & V_305 , sizeof( union V_303 ) ) ;
F_43 ( & V_1 -> V_286 ) ;
V_179 = F_219 ( V_1 ,
V_302 ,
sizeof( union V_303 ) ) ;
F_48 ( & V_1 -> V_286 ) ;
F_220 ( V_1 -> V_2 , sizeof( union V_303 ) ,
V_304 , V_302 ) ;
return V_179 ;
}
static int F_221 ( struct V_1 * V_1 , T_2 V_308 )
{
T_7 V_309 ;
union V_310 * V_311 = NULL ;
unsigned int V_47 ;
int V_179 ;
V_311 = F_218 ( V_1 -> V_2 ,
sizeof( union V_310 ) , & V_309 ) ;
if ( ! V_311 )
return - V_234 ;
for ( V_47 = 0 ; V_47 < ( 1 << V_308 ) ; V_47 ++ )
( * V_311 ) . V_312 [ V_47 / 4 ] . V_307 [ V_47 % 4 ] = V_47 % V_1 -> V_12 ;
F_43 ( & V_1 -> V_286 ) ;
V_179 = F_222 ( V_1 ,
V_309 ,
sizeof( union V_310 ) ) ;
F_48 ( & V_1 -> V_286 ) ;
F_220 ( V_1 -> V_2 , sizeof( union V_310 ) ,
V_311 , V_309 ) ;
return V_179 ;
}
static int F_223 ( struct V_1 * V_1 , T_2 V_313 ,
T_2 V_314 , T_2 V_308 , T_2 V_315 , T_2 V_316 )
{
const T_2 V_317 = 0 ;
const T_2 V_318 = 1 ;
int V_179 ;
F_43 ( & V_1 -> V_286 ) ;
V_179 = F_224 ( V_1 ,
V_313 , V_314 ,
V_308 , V_315 ,
V_316 , V_317 ,
V_318 ) ;
F_48 ( & V_1 -> V_286 ) ;
return V_179 ;
}
static int F_225 ( struct V_1 * V_1 )
{
struct V_3 * V_117 = F_215 ( V_1 ) ;
const T_2 V_313 = 0 ;
const T_2 V_314 = V_319 |
V_320 |
V_321 |
V_322 ;
const T_2 V_308 = 7 ;
const T_2 V_315 = 0 ;
T_2 V_316 = F_226 ( V_1 , V_323 ) && ( V_1 -> V_12 > 1 ) ;
if ( V_316 ) {
if ( ! F_217 ( V_1 ) ) {
if ( F_221 ( V_1 , V_308 ) ) {
V_316 = 0 ;
F_227 ( V_117 , L_26
L_27 ) ;
}
} else {
V_316 = 0 ;
F_227 ( V_117 , L_28 ) ;
}
}
return F_223 ( V_1 , V_313 , V_314 ,
V_308 , V_315 , V_316 ) ;
}
static void F_228 ( struct V_292 * V_293 )
{
struct V_1 * V_1 = F_202 ( V_293 , struct V_1 , V_105 ) ;
if ( ! F_120 ( V_1 -> V_17 ) )
return;
F_203 () ;
F_229 ( V_1 ) ;
F_188 ( V_1 -> V_17 ) ;
F_216 ( V_1 ) ;
F_115 ( V_1 ) ;
F_230 ( V_1 ) ;
F_225 ( V_1 ) ;
F_231 ( V_1 ) ;
F_181 ( V_1 -> V_17 ) ;
F_204 () ;
}
static int F_232 ( struct V_1 * V_1 )
{
unsigned int V_324 = F_32 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_325 = F_32 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_47 ;
F_209 ( F_173 ( V_1 -> V_279 ) < V_324 + V_325 + 2 ) ;
for ( V_47 = 0 ; V_47 < V_324 + V_325 + 2 ; V_47 ++ )
V_1 -> V_279 [ V_47 ] . V_326 = V_47 ;
if ( F_226 ( V_1 , V_323 ) &&
V_1 -> V_327 . V_328 < 1 &&
V_1 -> V_12 >= V_324 &&
V_1 -> V_15 >= V_325 &&
V_1 -> V_289 >= V_324 + V_325 &&
V_1 -> V_285 >= V_324 + V_325 + 2 ) {
if ( ! F_233 ( V_1 -> V_2 , V_1 -> V_279 , V_324 + V_325 + 2 ) ) {
V_1 -> V_12 = V_324 ;
V_1 -> V_15 = V_325 ;
V_1 -> V_289 = V_324 + V_325 ;
V_1 -> V_285 = V_324 + V_325 + 2 ;
F_234 ( V_1 -> V_30 ,
V_73 ) ;
return 0 ;
}
}
if ( V_1 -> V_327 . V_328 < 1 &&
V_1 -> V_12 >= 1 &&
V_1 -> V_15 >= V_325 &&
V_1 -> V_289 >= 1 + V_325 &&
V_1 -> V_285 >= 1 + V_325 + 2 ) {
if ( ! F_233 ( V_1 -> V_2 , V_1 -> V_279 , 1 + V_325 + 2 ) ) {
V_1 -> V_12 = 1 ;
V_1 -> V_15 = V_325 ;
V_1 -> V_289 = 1 + V_325 ;
V_1 -> V_285 = 1 + V_325 + 2 ;
F_234 ( V_1 -> V_30 ,
V_73 ) ;
return 0 ;
}
}
if ( V_1 -> V_327 . V_328 < 2 &&
V_1 -> V_12 >= 1 &&
V_1 -> V_15 >= 1 &&
V_1 -> V_289 >= 2 &&
V_1 -> V_285 >= 1 &&
! F_235 ( V_1 -> V_2 ) ) {
V_1 -> V_12 = 1 ;
V_1 -> V_15 = 1 ;
V_1 -> V_289 = 2 ;
V_1 -> V_285 = 1 ;
F_234 ( V_1 -> V_30 , V_72 ) ;
return 0 ;
}
if ( V_1 -> V_327 . V_328 < 3 &&
V_1 -> V_12 >= 1 &&
V_1 -> V_15 >= 1 &&
V_1 -> V_289 >= 2 &&
V_1 -> V_285 >= 3 ) {
V_1 -> V_12 = 1 ;
V_1 -> V_15 = 1 ;
V_1 -> V_289 = 2 ;
V_1 -> V_285 = 3 ;
F_234 ( V_1 -> V_30 , V_70 ) ;
return 0 ;
}
F_234 ( V_1 -> V_30 , V_329 ) ;
return - V_71 ;
}
static void F_236 ( struct V_1 * V_1 )
{
switch ( F_34 ( V_1 -> V_30 ) ) {
case V_73 :
F_237 ( V_1 -> V_2 ) ;
break;
case V_72 :
F_238 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_234 ( V_1 -> V_30 , V_329 ) ;
}
static void F_239 ( struct V_1 * V_1 )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_240 ( & V_1 -> V_107 [ V_47 ] ) ;
F_241 ( V_1 ) ;
F_236 ( V_1 ) ;
}
static int F_242 ( struct V_1 * V_1 )
{
struct V_3 * V_117 = F_215 ( V_1 ) ;
struct V_16 * V_17 = V_1 -> V_17 ;
unsigned int V_47 ;
int V_179 ;
V_179 = F_243 ( V_1 ) ;
if ( V_179 ) {
F_227 ( V_117 , L_29
L_30 ) ;
F_244 ( V_1 -> V_30 ) ;
}
V_179 = F_245 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_31 ) ;
return V_179 ;
}
F_246 ( V_1 ) ;
V_179 = F_232 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_32
L_33 ) ;
return V_179 ;
}
V_179 = F_247 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_34 ) ;
goto V_330;
}
F_230 ( V_1 ) ;
V_179 = F_225 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_35 ) ;
goto V_330;
}
switch ( F_34 ( V_1 -> V_30 ) ) {
default:
F_248 ( V_17 , & V_1 -> V_107 [ 0 ] , F_164 , 64 ) ;
break;
case V_73 :
for ( V_47 = 0 ; V_47 < V_1 -> V_12 ; V_47 ++ )
F_248 ( V_17 , & V_1 -> V_107 [ V_47 ] ,
F_167 , 64 ) ;
break;
}
return 0 ;
V_330:
F_236 ( V_1 ) ;
F_241 ( V_1 ) ;
return V_179 ;
}
static void F_249 ( struct V_1 * V_1 )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < F_173 ( V_1 -> V_331 ) ; V_47 ++ )
if ( V_1 -> V_331 [ V_47 ] . V_332 )
F_250 ( V_1 -> V_331 [ V_47 ] . V_332 ) ;
}
static int T_9 F_251 ( struct V_333 * V_2 ,
const struct V_334 * V_335 )
{
struct V_3 * V_117 = & V_2 -> V_117 ;
struct V_16 * V_17 ;
struct V_1 * V_1 ;
int V_336 = 0 ;
unsigned int V_47 ;
int V_179 ;
#ifdef F_5
int V_337 = 0 ;
#endif
int V_338 = 1 ;
V_17 = F_252 ( sizeof( struct V_1 ) ) ;
if ( ! V_17 )
return - V_234 ;
F_253 ( V_2 , V_17 ) ;
F_254 ( V_17 , & V_2 -> V_117 ) ;
V_1 = F_16 ( V_17 ) ;
V_1 -> V_17 = V_17 ;
V_1 -> V_2 = V_2 ;
V_179 = F_255 ( V_2 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_36 ) ;
goto V_339;
}
V_179 = F_256 ( V_2 , V_40 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_37 ) ;
goto V_340;
}
F_257 ( V_2 ) ;
V_179 = F_258 ( V_2 , F_259 ( 40 ) ) ;
if ( V_179 ) {
V_179 = F_258 ( V_2 , F_259 ( 32 ) ) ;
if ( V_179 ) {
F_214 ( V_117 , L_38 ) ;
goto V_341;
}
V_179 = F_260 ( V_2 , F_259 ( 32 ) ) ;
if ( V_179 ) {
F_214 ( V_117 , L_39
L_40 , 32 ) ;
goto V_341;
}
} else {
V_179 = F_260 ( V_2 , F_259 ( 40 ) ) ;
if ( V_179 ) {
F_214 ( V_117 , L_39
L_40 , 40 ) ;
goto V_341;
}
V_336 = 1 ;
}
for ( V_47 = 0 ; V_47 < F_173 ( V_1 -> V_331 ) ; V_47 ++ ) {
if ( ! ( F_261 ( V_2 , V_47 ) & V_342 ) )
continue;
V_1 -> V_331 [ V_47 ] . V_79 = F_262 ( V_2 , V_47 ) ;
V_1 -> V_331 [ V_47 ] . V_332 = F_263 ( V_2 , V_47 , V_1 -> V_331 [ V_47 ] . V_79 ) ;
if ( ! V_1 -> V_331 [ V_47 ] . V_332 ) {
F_214 ( V_117 , L_41 , V_47 ) ;
V_179 = - V_343 ;
goto V_344;
}
V_1 -> V_331 [ V_47 ] . V_345 = F_264 ( V_2 , V_47 ) ;
}
V_1 -> V_30 = F_265 ( NULL , V_1 , V_2 , V_1 -> V_331 ,
F_173 ( V_1 -> V_331 ) ) ;
if ( ! V_1 -> V_30 ) {
F_214 ( V_117 , L_42 ) ;
V_179 = - V_343 ;
goto V_344;
}
#ifdef F_5
V_337 = F_266 ( V_2 , V_346 ) ;
if ( V_337 ) {
F_267 ( V_2 , V_337 + V_347 ,
& V_1 -> V_9 ) ;
if ( V_1 -> V_9 ) {
V_179 = F_268 ( V_2 , V_1 -> V_9 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_43
L_44 ,
V_179 ) ;
goto V_348;
}
V_1 -> V_5 |= V_6 ;
V_338 = V_1 -> V_9 ;
}
}
#endif
V_1 -> V_198 = F_269 ( V_338 , sizeof( * V_1 -> V_198 ) , V_349 ) ;
if ( ! V_1 -> V_198 ) {
V_179 = - V_234 ;
goto V_350;
}
V_179 = F_213 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_45 ) ;
goto V_351;
}
F_270 ( & V_1 -> V_286 ) ;
V_179 = F_231 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 ,
L_46 ) ;
goto V_352;
}
F_64 ( V_17 ) ;
if ( ! F_1 ( V_1 ) ) {
V_179 = F_271 ( V_1 -> V_30 , 0 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_47 ) ;
goto V_352;
}
}
V_179 = F_242 ( V_1 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_48 ) ;
goto V_352;
}
F_272 ( & V_1 -> V_274 ) ;
V_1 -> V_274 . V_353 = F_168 ;
V_1 -> V_274 . V_46 = ( unsigned long ) V_1 ;
F_273 ( & V_1 -> V_105 , F_228 ) ;
F_273 ( & V_1 -> V_95 , F_201 ) ;
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ )
F_270 ( & V_1 -> V_87 [ V_47 ] ) ;
V_1 -> V_92 = V_1 -> V_327 . V_91 ;
( void ) F_200 ( V_17 , V_1 -> V_92 ) ;
V_179 = F_116 ( V_17 , V_1 -> V_219 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_49 ) ;
goto V_354;
}
V_1 -> V_67 = V_1 -> V_327 . V_355 ;
V_1 -> V_68 = V_1 -> V_67 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
V_17 -> V_356 = & V_357 ;
else
V_17 -> V_356 = & V_358 ;
V_17 -> V_359 = 2 * V_296 ;
V_17 -> V_360 = & V_361 ;
V_17 -> V_261 |= V_362 | V_363 ;
if ( F_226 ( V_1 , V_364 ) ) {
V_17 -> V_261 &= ~ V_362 ;
V_1 -> V_136 = 1 ;
V_1 -> V_137 = V_1 -> V_327 . V_137 ;
F_274 ( V_117 , L_50 , V_1 -> V_137 ) ;
}
if ( F_226 ( V_1 , V_365 ) )
V_17 -> V_366 |= V_367 | V_368 ;
if ( F_226 ( V_1 , V_369 ) )
V_17 -> V_366 |= V_370 |
V_371 | V_372 ;
if ( F_226 ( V_1 , V_373 ) )
V_17 -> V_366 |= V_262 ;
V_17 -> V_261 |= V_17 -> V_366 ;
if ( V_336 )
V_17 -> V_261 |= V_374 ;
V_17 -> V_5 |= V_375 ;
V_179 = F_275 ( V_17 ) ;
if ( V_179 ) {
F_214 ( V_117 , L_51 ) ;
goto V_354;
}
return 0 ;
V_354:
F_239 ( V_1 ) ;
V_352:
F_276 ( V_1 -> V_30 ) ;
V_351:
F_277 ( V_1 -> V_198 ) ;
V_350:
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_278 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
V_348:
#endif
F_279 ( V_1 -> V_30 ) ;
V_344:
F_249 ( V_1 ) ;
V_341:
F_280 ( V_2 ) ;
V_340:
F_281 ( V_2 ) ;
V_339:
F_253 ( V_2 , NULL ) ;
F_282 ( V_17 ) ;
return V_179 ;
}
static void T_10 F_283 ( struct V_333 * V_2 )
{
struct V_16 * V_17 = F_284 ( V_2 ) ;
if ( V_17 ) {
struct V_1 * V_1 = F_16 ( V_17 ) ;
F_285 ( & V_1 -> V_105 ) ;
F_285 ( & V_1 -> V_95 ) ;
F_286 ( V_17 ) ;
F_239 ( V_1 ) ;
F_276 ( V_1 -> V_30 ) ;
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_278 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
#endif
F_277 ( V_1 -> V_198 ) ;
F_279 ( V_1 -> V_30 ) ;
F_249 ( V_1 ) ;
F_280 ( V_2 ) ;
F_281 ( V_2 ) ;
F_253 ( V_2 , NULL ) ;
F_282 ( V_17 ) ;
}
}
static int T_11 F_287 ( void )
{
F_288 ( L_52 , V_376 , V_42 ) ;
return F_289 ( & V_377 ) ;
}
static void T_12 F_290 ( void )
{
F_291 ( & V_377 ) ;
}
