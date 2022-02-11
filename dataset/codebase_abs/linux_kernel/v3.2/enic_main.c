int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_4 ;
}
int F_2 ( struct V_1 * V_1 )
{
return ( V_1 -> V_5 & V_6 ) ? 1 : 0 ;
}
int F_3 ( struct V_1 * V_1 , int V_7 )
{
#ifdef F_4
return V_7 >= 0 && V_7 < V_1 -> V_8 ;
#else
return 0 ;
#endif
}
static inline unsigned int F_5 ( struct V_1 * V_1 , unsigned int V_9 )
{
return V_9 ;
}
static inline unsigned int F_6 ( struct V_1 * V_1 , unsigned int V_10 )
{
return V_1 -> V_11 + V_10 ;
}
static inline unsigned int F_7 ( void )
{
return 0 ;
}
static inline unsigned int F_8 ( void )
{
return 1 ;
}
static inline unsigned int F_9 ( void )
{
return 2 ;
}
static inline unsigned int F_10 ( struct V_1 * V_1 , unsigned int V_9 )
{
return V_1 -> V_12 [ F_5 ( V_1 , V_9 ) ] . V_13 ;
}
static inline unsigned int F_11 ( struct V_1 * V_1 , unsigned int V_10 )
{
return V_1 -> V_12 [ F_6 ( V_1 , V_10 ) ] . V_13 ;
}
static inline unsigned int F_12 ( struct V_1 * V_1 )
{
return V_1 -> V_11 + V_1 -> V_14 ;
}
static inline unsigned int F_13 ( struct V_1 * V_1 )
{
return V_1 -> V_11 + V_1 -> V_14 + 1 ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
V_18 -> V_19 = ( V_20 | V_21 ) ;
V_18 -> V_22 = ( V_23 | V_24 ) ;
V_18 -> V_25 = V_26 ;
V_18 -> V_27 = V_28 ;
if ( F_16 ( V_16 ) ) {
F_17 ( V_18 , F_18 ( V_1 -> V_29 ) ) ;
V_18 -> V_30 = V_31 ;
} else {
F_17 ( V_18 , - 1 ) ;
V_18 -> V_30 = - 1 ;
}
V_18 -> V_32 = V_33 ;
return 0 ;
}
static void F_19 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_36 * V_37 ;
F_20 ( V_1 , & V_37 ) ;
strncpy ( V_35 -> V_38 , V_39 , sizeof( V_35 -> V_38 ) ) ;
strncpy ( V_35 -> V_40 , V_41 , sizeof( V_35 -> V_40 ) ) ;
strncpy ( V_35 -> V_42 , V_37 -> V_42 ,
sizeof( V_35 -> V_42 ) ) ;
strncpy ( V_35 -> V_43 , F_21 ( V_1 -> V_2 ) ,
sizeof( V_35 -> V_43 ) ) ;
}
static void F_22 ( struct V_15 * V_16 , T_1 V_44 , T_2 * V_45 )
{
unsigned int V_46 ;
switch ( V_44 ) {
case V_47 :
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
memcpy ( V_45 , V_49 [ V_46 ] . V_50 , V_51 ) ;
V_45 += V_51 ;
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
memcpy ( V_45 , V_53 [ V_46 ] . V_50 , V_51 ) ;
V_45 += V_51 ;
}
break;
}
}
static int F_23 ( struct V_15 * V_16 , int V_54 )
{
switch ( V_54 ) {
case V_47 :
return V_48 + V_52 ;
default:
return - V_55 ;
}
}
static void F_24 ( struct V_15 * V_16 ,
struct V_56 * V_57 , T_3 * V_45 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_58 * V_59 ;
unsigned int V_46 ;
F_25 ( V_1 , & V_59 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
* ( V_45 ++ ) = ( ( T_3 * ) & V_59 -> V_60 ) [ V_49 [ V_46 ] . V_61 ] ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ )
* ( V_45 ++ ) = ( ( T_3 * ) & V_59 -> V_62 ) [ V_53 [ V_46 ] . V_61 ] ;
}
static T_1 F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
return V_1 -> V_63 ;
}
static void F_27 ( struct V_15 * V_16 , T_1 V_64 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
V_1 -> V_63 = V_64 ;
}
static int F_28 ( struct V_15 * V_16 ,
struct V_65 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
V_18 -> V_66 = V_1 -> V_66 ;
V_18 -> V_67 = V_1 -> V_67 ;
return 0 ;
}
static int F_29 ( struct V_15 * V_16 ,
struct V_65 * V_18 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
T_1 V_66 ;
T_1 V_67 ;
unsigned int V_46 , V_68 ;
V_66 = F_30 ( T_1 , V_18 -> V_66 ,
F_31 ( V_1 -> V_29 ) ) ;
V_67 = F_30 ( T_1 , V_18 -> V_67 ,
F_31 ( V_1 -> V_29 ) ) ;
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_69 :
if ( V_66 != V_67 )
return - V_70 ;
V_68 = F_7 () ;
F_33 ( & V_1 -> V_68 [ V_68 ] ,
V_66 ) ;
break;
case V_71 :
if ( V_66 != V_67 )
return - V_70 ;
F_33 ( & V_1 -> V_68 [ 0 ] ,
V_66 ) ;
break;
case V_72 :
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ ) {
V_68 = F_11 ( V_1 , V_46 ) ;
F_33 ( & V_1 -> V_68 [ V_68 ] ,
V_66 ) ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
V_68 = F_10 ( V_1 , V_46 ) ;
F_33 ( & V_1 -> V_68 [ V_68 ] ,
V_67 ) ;
}
break;
default:
break;
}
V_1 -> V_66 = V_66 ;
V_1 -> V_67 = V_67 ;
return 0 ;
}
static void F_34 ( struct V_73 * V_10 , struct V_74 * V_75 )
{
struct V_1 * V_1 = F_35 ( V_10 -> V_29 ) ;
if ( V_75 -> V_76 )
F_36 ( V_1 -> V_2 , V_75 -> V_77 ,
V_75 -> V_78 , V_79 ) ;
else
F_37 ( V_1 -> V_2 , V_75 -> V_77 ,
V_75 -> V_78 , V_79 ) ;
if ( V_75 -> V_80 )
F_38 ( V_75 -> V_80 ) ;
}
static void F_39 ( struct V_73 * V_10 ,
struct V_81 * V_81 , struct V_74 * V_75 , void * V_82 )
{
F_34 ( V_10 , V_75 ) ;
}
static int F_40 ( struct V_83 * V_29 , struct V_81 * V_81 ,
T_2 type , T_4 V_84 , T_4 V_85 , void * V_82 )
{
struct V_1 * V_1 = F_35 ( V_29 ) ;
F_41 ( & V_1 -> V_86 [ V_84 ] ) ;
F_42 ( & V_1 -> V_10 [ V_84 ] , V_81 ,
V_85 , F_39 ,
V_82 ) ;
if ( F_43 ( V_1 -> V_16 ) &&
F_44 ( & V_1 -> V_10 [ V_84 ] ) >=
( V_87 + V_88 ) )
F_45 ( V_1 -> V_16 ) ;
F_46 ( & V_1 -> V_86 [ V_84 ] ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
T_1 V_89 ;
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ ) {
V_89 = F_48 ( & V_1 -> V_10 [ V_46 ] ) ;
if ( V_89 )
F_49 ( V_1 -> V_16 , L_1 ,
V_46 , V_89 ) ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
V_89 = F_50 ( & V_1 -> V_9 [ V_46 ] ) ;
if ( V_89 )
F_49 ( V_1 -> V_16 , L_2 ,
V_46 , V_89 ) ;
}
}
static void F_51 ( struct V_1 * V_1 )
{
T_1 V_63 = F_52 ( V_1 -> V_29 ) ;
if ( V_63 != V_1 -> V_63 ) {
F_53 ( V_1 -> V_16 , L_3 ,
V_1 -> V_63 , V_63 ) ;
V_1 -> V_63 = V_63 ;
}
}
static void F_54 ( struct V_1 * V_1 )
{
T_1 V_90 = F_55 ( V_1 -> V_29 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
if ( V_90 && V_90 != V_1 -> V_91 ) {
V_1 -> V_91 = V_90 ;
if ( F_1 ( V_1 ) ) {
V_90 = F_56 ( int , V_92 ,
F_30 ( int , V_93 , V_90 ) ) ;
if ( V_90 != V_16 -> V_90 )
F_57 ( & V_1 -> V_94 ) ;
} else {
if ( V_90 < V_16 -> V_90 )
F_58 ( V_16 ,
L_4
L_5 ,
V_16 -> V_90 , V_90 ) ;
}
}
}
static void F_59 ( struct V_1 * V_1 )
{
int V_95 = F_60 ( V_1 -> V_29 ) ;
int V_96 = F_16 ( V_1 -> V_16 ) ;
if ( V_95 && ! V_96 ) {
F_53 ( V_1 -> V_16 , L_6 ) ;
F_61 ( V_1 -> V_16 ) ;
} else if ( ! V_95 && V_96 ) {
F_53 ( V_1 -> V_16 , L_7 ) ;
F_62 ( V_1 -> V_16 ) ;
}
}
static void F_63 ( struct V_1 * V_1 )
{
F_51 ( V_1 ) ;
F_54 ( V_1 ) ;
F_59 ( V_1 ) ;
}
static T_5 F_64 ( int V_97 , void * V_45 )
{
struct V_15 * V_16 = V_45 ;
struct V_1 * V_1 = F_15 ( V_16 ) ;
unsigned int V_98 = F_7 () ;
unsigned int V_99 = F_8 () ;
unsigned int V_100 = F_9 () ;
T_1 V_101 ;
F_65 ( & V_1 -> V_68 [ V_98 ] ) ;
V_101 = F_66 ( V_1 -> V_102 ) ;
if ( ! V_101 ) {
F_67 ( & V_1 -> V_68 [ V_98 ] ) ;
return V_103 ;
}
if ( F_68 ( V_101 , V_100 ) ) {
F_69 ( & V_1 -> V_68 [ V_100 ] ) ;
F_63 ( V_1 ) ;
}
if ( F_68 ( V_101 , V_99 ) ) {
F_69 ( & V_1 -> V_68 [ V_99 ] ) ;
F_47 ( V_1 ) ;
F_57 ( & V_1 -> V_104 ) ;
return V_105 ;
}
if ( F_68 ( V_101 , V_98 ) ) {
if ( F_70 ( & V_1 -> V_106 [ 0 ] ) )
F_71 ( & V_1 -> V_106 [ 0 ] ) ;
} else {
F_67 ( & V_1 -> V_68 [ V_98 ] ) ;
}
return V_105 ;
}
static T_5 F_72 ( int V_97 , void * V_45 )
{
struct V_1 * V_1 = V_45 ;
F_73 ( & V_1 -> V_106 [ 0 ] ) ;
return V_105 ;
}
static T_5 F_74 ( int V_97 , void * V_45 )
{
struct V_107 * V_106 = V_45 ;
F_73 ( V_106 ) ;
return V_105 ;
}
static T_5 F_75 ( int V_97 , void * V_45 )
{
struct V_1 * V_1 = V_45 ;
unsigned int V_12 = F_6 ( V_1 , 0 ) ;
unsigned int V_68 = F_11 ( V_1 , 0 ) ;
unsigned int V_108 = - 1 ;
unsigned int V_109 ;
V_109 = F_76 ( & V_1 -> V_12 [ V_12 ] ,
V_108 , F_40 , NULL ) ;
F_77 ( & V_1 -> V_68 [ V_68 ] ,
V_109 ,
1 ,
1 ) ;
return V_105 ;
}
static T_5 F_78 ( int V_97 , void * V_45 )
{
struct V_1 * V_1 = V_45 ;
unsigned int V_68 = F_12 ( V_1 ) ;
F_69 ( & V_1 -> V_68 [ V_68 ] ) ;
F_47 ( V_1 ) ;
F_57 ( & V_1 -> V_104 ) ;
return V_105 ;
}
static T_5 F_79 ( int V_97 , void * V_45 )
{
struct V_1 * V_1 = V_45 ;
unsigned int V_68 = F_13 ( V_1 ) ;
F_69 ( & V_1 -> V_68 [ V_68 ] ) ;
F_63 ( V_1 ) ;
return V_105 ;
}
static inline void F_80 ( struct V_1 * V_1 ,
struct V_73 * V_10 , struct V_110 * V_111 ,
unsigned int V_112 , int V_113 )
{
const T_6 * V_114 ;
for ( V_114 = F_81 ( V_111 ) -> V_115 ; V_112 ; V_114 ++ ) {
V_112 -= F_82 ( V_114 ) ;
F_83 ( V_10 , V_111 ,
F_84 ( & V_1 -> V_2 -> V_116 ,
V_114 , 0 , F_82 ( V_114 ) ,
V_117 ) ,
F_82 ( V_114 ) ,
( V_112 == 0 ) ,
V_113 ) ;
}
}
static inline void F_85 ( struct V_1 * V_1 ,
struct V_73 * V_10 , struct V_110 * V_111 ,
int V_118 , unsigned int V_119 , int V_113 )
{
unsigned int V_120 = F_86 ( V_111 ) ;
unsigned int V_112 = V_111 -> V_78 - V_120 ;
int V_121 = ( V_112 == 0 ) ;
F_87 ( V_10 , V_111 ,
F_88 ( V_1 -> V_2 , V_111 -> V_45 ,
V_120 , V_79 ) ,
V_120 ,
V_118 , V_119 ,
V_121 , V_113 ) ;
if ( ! V_121 )
F_80 ( V_1 , V_10 , V_111 , V_112 , V_113 ) ;
}
static inline void F_89 ( struct V_1 * V_1 ,
struct V_73 * V_10 , struct V_110 * V_111 ,
int V_118 , unsigned int V_119 , int V_113 )
{
unsigned int V_120 = F_86 ( V_111 ) ;
unsigned int V_112 = V_111 -> V_78 - V_120 ;
unsigned int V_122 = F_90 ( V_111 ) ;
unsigned int V_123 = V_122 + V_111 -> V_123 ;
int V_121 = ( V_112 == 0 ) ;
F_91 ( V_10 , V_111 ,
F_88 ( V_1 -> V_2 , V_111 -> V_45 ,
V_120 , V_79 ) ,
V_120 ,
V_123 ,
V_122 ,
V_118 , V_119 ,
V_121 , V_113 ) ;
if ( ! V_121 )
F_80 ( V_1 , V_10 , V_111 , V_112 , V_113 ) ;
}
static inline void F_92 ( struct V_1 * V_1 ,
struct V_73 * V_10 , struct V_110 * V_111 , unsigned int V_124 ,
int V_118 , unsigned int V_119 , int V_113 )
{
unsigned int V_125 = F_86 ( V_111 ) ;
unsigned int V_112 = V_111 -> V_78 - V_125 ;
unsigned int V_122 = F_93 ( V_111 ) + F_94 ( V_111 ) ;
int V_121 = ( V_112 == 0 ) ;
unsigned int V_78 ;
T_7 V_77 ;
unsigned int V_61 = 0 ;
T_6 * V_114 ;
if ( V_111 -> V_126 == F_95 ( V_127 ) ) {
F_96 ( V_111 ) -> V_128 = 0 ;
F_97 ( V_111 ) -> V_128 = ~ F_98 ( F_96 ( V_111 ) -> V_129 ,
F_96 ( V_111 ) -> V_130 , 0 , V_131 , 0 ) ;
} else if ( V_111 -> V_126 == F_95 ( V_132 ) ) {
F_97 ( V_111 ) -> V_128 = ~ F_99 ( & F_100 ( V_111 ) -> V_129 ,
& F_100 ( V_111 ) -> V_130 , 0 , V_131 , 0 ) ;
}
while ( V_125 ) {
V_78 = F_101 ( V_125 , ( unsigned int ) V_133 ) ;
V_77 = F_88 ( V_1 -> V_2 , V_111 -> V_45 + V_61 ,
V_78 , V_79 ) ;
F_102 ( V_10 , V_111 ,
V_77 ,
V_78 ,
V_124 , V_122 ,
V_118 , V_119 ,
V_121 && ( V_78 == V_125 ) , V_113 ) ;
V_125 -= V_78 ;
V_61 += V_78 ;
}
if ( V_121 )
return;
for ( V_114 = F_81 ( V_111 ) -> V_115 ; V_112 ; V_114 ++ ) {
V_112 -= F_82 ( V_114 ) ;
V_125 = F_82 ( V_114 ) ;
V_61 = 0 ;
while ( V_125 ) {
V_78 = F_101 ( V_125 ,
( unsigned int ) V_133 ) ;
V_77 = F_84 ( & V_1 -> V_2 -> V_116 , V_114 ,
V_61 , V_78 ,
V_117 ) ;
F_83 ( V_10 , V_111 ,
V_77 ,
V_78 ,
( V_112 == 0 ) &&
( V_78 == V_125 ) ,
V_113 ) ;
V_125 -= V_78 ;
V_61 += V_78 ;
}
}
}
static inline void F_103 ( struct V_1 * V_1 ,
struct V_73 * V_10 , struct V_110 * V_111 )
{
unsigned int V_124 = F_81 ( V_111 ) -> V_134 ;
unsigned int V_119 = 0 ;
int V_118 = 0 ;
int V_113 = 0 ;
if ( F_104 ( V_111 ) ) {
V_118 = 1 ;
V_119 = F_105 ( V_111 ) ;
} else if ( V_1 -> V_135 ) {
V_119 = V_1 -> V_136 ;
V_113 = 1 ;
}
if ( V_124 )
F_92 ( V_1 , V_10 , V_111 , V_124 ,
V_118 , V_119 , V_113 ) ;
else if ( V_111 -> V_137 == V_138 )
F_89 ( V_1 , V_10 , V_111 ,
V_118 , V_119 , V_113 ) ;
else
F_85 ( V_1 , V_10 , V_111 ,
V_118 , V_119 , V_113 ) ;
}
static T_8 F_106 ( struct V_110 * V_111 ,
struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_73 * V_10 = & V_1 -> V_10 [ 0 ] ;
unsigned long V_139 ;
if ( V_111 -> V_78 <= 0 ) {
F_107 ( V_111 ) ;
return V_140 ;
}
if ( F_81 ( V_111 ) -> V_134 == 0 &&
F_81 ( V_111 ) -> V_141 + 1 > V_142 &&
F_108 ( V_111 ) ) {
F_107 ( V_111 ) ;
return V_140 ;
}
F_109 ( & V_1 -> V_86 [ 0 ] , V_139 ) ;
if ( F_44 ( V_10 ) <
F_81 ( V_111 ) -> V_141 + V_88 ) {
F_110 ( V_16 ) ;
F_49 ( V_16 , L_8 ) ;
F_111 ( & V_1 -> V_86 [ 0 ] , V_139 ) ;
return V_143 ;
}
F_103 ( V_1 , V_10 , V_111 ) ;
if ( F_44 ( V_10 ) < V_87 + V_88 )
F_110 ( V_16 ) ;
F_111 ( & V_1 -> V_86 [ 0 ] , V_139 ) ;
return V_140 ;
}
static struct V_144 * F_112 ( struct V_15 * V_16 ,
struct V_144 * V_145 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_58 * V_57 ;
F_25 ( V_1 , & V_57 ) ;
V_145 -> V_146 = V_57 -> V_60 . V_147 ;
V_145 -> V_148 = V_57 -> V_60 . V_149 ;
V_145 -> V_150 = V_57 -> V_60 . V_150 ;
V_145 -> V_151 = V_57 -> V_60 . V_152 ;
V_145 -> V_153 = V_57 -> V_62 . V_154 ;
V_145 -> V_155 = V_57 -> V_62 . V_156 ;
V_145 -> V_157 = V_57 -> V_62 . V_157 ;
V_145 -> V_158 = V_57 -> V_62 . V_159 ;
V_145 -> V_160 = V_1 -> V_161 ;
V_145 -> V_162 = V_1 -> V_163 ;
V_145 -> V_164 = V_57 -> V_62 . V_165 + V_57 -> V_62 . V_166 ;
return V_145 ;
}
void F_113 ( struct V_1 * V_1 )
{
V_1 -> V_167 = 0 ;
V_1 -> V_168 = 0 ;
V_1 -> V_139 = 0 ;
}
static int F_114 ( struct V_15 * V_16 , char * V_169 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_115 ( V_169 ) && ! F_116 ( V_169 ) )
return - V_170 ;
} else {
if ( ! F_115 ( V_169 ) )
return - V_170 ;
}
memcpy ( V_16 -> V_171 , V_169 , V_16 -> V_172 ) ;
return 0 ;
}
static int F_117 ( struct V_15 * V_16 , void * V_173 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_174 * V_129 = V_173 ;
char * V_169 = V_129 -> V_175 ;
int V_176 ;
if ( F_118 ( V_1 -> V_16 ) ) {
V_176 = F_119 ( V_1 ) ;
if ( V_176 )
return V_176 ;
}
V_176 = F_114 ( V_16 , V_169 ) ;
if ( V_176 )
return V_176 ;
if ( F_118 ( V_1 -> V_16 ) ) {
V_176 = F_120 ( V_1 ) ;
if ( V_176 )
return V_176 ;
}
return V_176 ;
}
static int F_121 ( struct V_15 * V_16 , void * V_173 )
{
struct V_174 * V_129 = V_173 ;
char * V_169 = V_129 -> V_175 ;
struct V_1 * V_1 = F_15 ( V_16 ) ;
int V_176 ;
V_176 = F_119 ( V_1 ) ;
if ( V_176 )
return V_176 ;
V_176 = F_114 ( V_16 , V_169 ) ;
if ( V_176 )
return V_176 ;
return F_120 ( V_1 ) ;
}
static void F_122 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
struct V_177 * V_178 ;
unsigned int V_167 = F_123 ( V_16 ) ;
T_2 V_179 [ V_180 ] [ V_181 ] ;
unsigned int V_46 , V_182 ;
if ( V_167 > V_180 ) {
F_58 ( V_16 , L_9
L_10 ,
V_180 , V_167 ) ;
V_167 = V_180 ;
}
V_46 = 0 ;
F_124 (ha, netdev) {
if ( V_46 == V_167 )
break;
memcpy ( V_179 [ V_46 ++ ] , V_178 -> V_169 , V_181 ) ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_167 ; V_46 ++ ) {
for ( V_182 = 0 ; V_182 < V_167 ; V_182 ++ )
if ( F_125 ( V_1 -> V_179 [ V_46 ] ,
V_179 [ V_182 ] ) == 0 )
break;
if ( V_182 == V_167 )
F_126 ( V_1 , V_1 -> V_179 [ V_46 ] ) ;
}
for ( V_46 = 0 ; V_46 < V_167 ; V_46 ++ ) {
for ( V_182 = 0 ; V_182 < V_1 -> V_167 ; V_182 ++ )
if ( F_125 ( V_179 [ V_46 ] ,
V_1 -> V_179 [ V_182 ] ) == 0 )
break;
if ( V_182 == V_1 -> V_167 )
F_127 ( V_1 , V_179 [ V_46 ] ) ;
}
for ( V_46 = 0 ; V_46 < V_167 ; V_46 ++ )
memcpy ( V_1 -> V_179 [ V_46 ] , V_179 [ V_46 ] , V_181 ) ;
V_1 -> V_167 = V_167 ;
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
struct V_177 * V_178 ;
unsigned int V_168 = F_129 ( V_16 ) ;
T_2 V_183 [ V_184 ] [ V_181 ] ;
unsigned int V_46 , V_182 ;
if ( V_168 > V_184 ) {
F_58 ( V_16 , L_9
L_11 ,
V_184 , V_168 ) ;
V_168 = V_184 ;
}
V_46 = 0 ;
F_130 (ha, netdev) {
if ( V_46 == V_168 )
break;
memcpy ( V_183 [ V_46 ++ ] , V_178 -> V_169 , V_181 ) ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_168 ; V_46 ++ ) {
for ( V_182 = 0 ; V_182 < V_168 ; V_182 ++ )
if ( F_125 ( V_1 -> V_183 [ V_46 ] ,
V_183 [ V_182 ] ) == 0 )
break;
if ( V_182 == V_168 )
F_126 ( V_1 , V_1 -> V_183 [ V_46 ] ) ;
}
for ( V_46 = 0 ; V_46 < V_168 ; V_46 ++ ) {
for ( V_182 = 0 ; V_182 < V_1 -> V_168 ; V_182 ++ )
if ( F_125 ( V_183 [ V_46 ] ,
V_1 -> V_183 [ V_182 ] ) == 0 )
break;
if ( V_182 == V_1 -> V_168 )
F_127 ( V_1 , V_183 [ V_46 ] ) ;
}
for ( V_46 = 0 ; V_46 < V_168 ; V_46 ++ )
memcpy ( V_1 -> V_183 [ V_46 ] , V_183 [ V_46 ] , V_181 ) ;
V_1 -> V_168 = V_168 ;
}
static void F_131 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
int V_185 = 1 ;
int V_158 = ( V_16 -> V_139 & V_186 ) ? 1 : 0 ;
int V_187 = ( V_16 -> V_139 & V_188 ) ? 1 : 0 ;
int V_189 = ( V_16 -> V_139 & V_190 ) ||
F_129 ( V_16 ) > V_184 ;
int V_191 = ( V_16 -> V_139 & V_192 ) ||
F_123 ( V_16 ) > V_180 ;
unsigned int V_139 = V_16 -> V_139 |
( V_191 ? V_192 : 0 ) |
( V_189 ? V_190 : 0 ) ;
if ( V_1 -> V_139 != V_139 ) {
V_1 -> V_139 = V_139 ;
F_132 ( V_1 , V_185 ,
V_158 , V_187 , V_189 , V_191 ) ;
}
if ( ! V_189 ) {
F_128 ( V_1 ) ;
if ( ! V_191 )
F_122 ( V_1 ) ;
}
}
static void F_133 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
F_57 ( & V_1 -> V_104 ) ;
}
static int F_134 ( struct V_15 * V_16 , int V_7 , T_2 * V_193 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_194 * V_195 ;
int V_176 ;
F_135 ( V_1 , V_7 , V_195 , & V_176 ) ;
if ( V_176 )
return V_176 ;
if ( F_115 ( V_193 ) ) {
memcpy ( V_195 -> V_196 , V_193 , V_181 ) ;
return 0 ;
} else
return - V_70 ;
}
static int F_136 ( struct V_15 * V_16 , int V_7 ,
struct V_197 * V_25 [] )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_194 V_198 ;
struct V_194 * V_195 ;
int V_176 = 0 , V_199 = 1 ;
F_135 ( V_1 , V_7 , V_195 , & V_176 ) ;
if ( V_176 )
return V_176 ;
if ( ! V_25 [ V_200 ] )
return - V_55 ;
memcpy ( & V_198 , V_195 , sizeof( * V_1 -> V_195 ) ) ;
memset ( V_195 , 0 , sizeof( * V_1 -> V_195 ) ) ;
V_195 -> V_201 |= V_202 ;
V_195 -> V_203 = F_137 ( V_25 [ V_200 ] ) ;
if ( V_25 [ V_204 ] ) {
V_195 -> V_201 |= V_205 ;
memcpy ( V_195 -> V_50 , F_138 ( V_25 [ V_204 ] ) ,
V_206 ) ;
}
if ( V_25 [ V_207 ] ) {
V_195 -> V_201 |= V_208 ;
memcpy ( V_195 -> V_209 ,
F_138 ( V_25 [ V_207 ] ) , V_210 ) ;
}
if ( V_25 [ V_211 ] ) {
V_195 -> V_201 |= V_212 ;
memcpy ( V_195 -> V_213 ,
F_138 ( V_25 [ V_211 ] ) , V_210 ) ;
}
if ( ! F_116 ( V_198 . V_196 ) )
memcpy ( V_195 -> V_214 , V_198 . V_196 , V_181 ) ;
if ( V_7 == V_215 && F_116 ( V_16 -> V_171 ) )
F_139 ( V_16 -> V_171 ) ;
V_176 = F_140 ( V_1 , V_7 , & V_198 , & V_199 ) ;
if ( V_176 ) {
if ( V_199 ) {
memcpy ( V_195 , & V_198 , sizeof( * V_195 ) ) ;
} else {
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
if ( V_7 == V_215 )
memset ( V_16 -> V_171 , 0 , V_181 ) ;
}
} else {
V_195 -> V_201 |= V_216 ;
if ( V_195 -> V_203 == V_217 ) {
memset ( V_195 -> V_214 , 0 , V_181 ) ;
if ( V_7 == V_215 )
memset ( V_16 -> V_171 , 0 , V_181 ) ;
}
}
memset ( V_195 -> V_196 , 0 , V_181 ) ;
return V_176 ;
}
static int F_141 ( struct V_15 * V_16 , int V_7 ,
struct V_110 * V_111 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
T_4 V_218 = V_219 ;
struct V_194 * V_195 ;
int V_176 ;
F_135 ( V_1 , V_7 , V_195 , & V_176 ) ;
if ( V_176 )
return V_176 ;
if ( ! ( V_195 -> V_201 & V_216 ) )
return - V_220 ;
V_176 = F_142 ( V_1 , V_7 , V_195 -> V_203 , & V_218 ) ;
if ( V_176 )
return V_176 ;
F_143 ( V_111 , V_200 , V_195 -> V_203 ) ;
F_143 ( V_111 , V_221 , V_218 ) ;
if ( V_195 -> V_201 & V_205 )
F_144 ( V_111 , V_204 , V_206 ,
V_195 -> V_50 ) ;
if ( V_195 -> V_201 & V_208 )
F_144 ( V_111 , V_207 , V_210 ,
V_195 -> V_209 ) ;
if ( V_195 -> V_201 & V_212 )
F_144 ( V_111 , V_211 , V_210 ,
V_195 -> V_213 ) ;
return 0 ;
V_222:
return - V_223 ;
}
static void F_145 ( struct V_224 * V_9 , struct V_225 * V_75 )
{
struct V_1 * V_1 = F_35 ( V_9 -> V_29 ) ;
if ( ! V_75 -> V_80 )
return;
F_36 ( V_1 -> V_2 , V_75 -> V_77 ,
V_75 -> V_78 , V_226 ) ;
F_38 ( V_75 -> V_80 ) ;
}
static int F_146 ( struct V_224 * V_9 )
{
struct V_1 * V_1 = F_35 ( V_9 -> V_29 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
struct V_110 * V_111 ;
unsigned int V_78 = V_16 -> V_90 + V_227 ;
unsigned int V_228 = 0 ;
T_7 V_77 ;
V_111 = F_147 ( V_16 , V_78 ) ;
if ( ! V_111 )
return - V_229 ;
V_77 = F_88 ( V_1 -> V_2 , V_111 -> V_45 ,
V_78 , V_226 ) ;
F_148 ( V_9 , V_111 , V_228 ,
V_77 , V_78 ) ;
return 0 ;
}
static void F_149 ( struct V_224 * V_9 ,
struct V_81 * V_81 , struct V_225 * V_75 ,
int V_230 , void * V_82 )
{
struct V_1 * V_1 = F_35 ( V_9 -> V_29 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
struct V_110 * V_111 ;
T_2 type , V_231 , V_121 , V_76 , V_232 , V_233 ;
T_2 V_234 , V_235 , V_236 , V_237 , V_238 ;
T_2 V_239 , V_240 , V_241 , V_242 ;
T_2 V_243 , V_244 , V_245 , V_246 , V_247 , V_248 ;
T_2 V_249 ;
T_4 V_84 , V_85 , V_250 , V_251 , V_252 ;
T_1 V_253 ;
if ( V_230 )
return;
V_111 = V_75 -> V_80 ;
F_150 ( V_111 -> V_45 - V_254 ) ;
F_36 ( V_1 -> V_2 , V_75 -> V_77 ,
V_75 -> V_78 , V_226 ) ;
F_151 ( (struct V_255 * ) V_81 ,
& type , & V_231 , & V_84 , & V_85 ,
& V_232 , & V_234 , & V_121 , & V_76 , & V_247 ,
& V_248 , & V_253 , & V_250 ,
& V_249 , & V_233 , & V_251 , & V_252 ,
& V_235 , & V_236 , & V_237 ,
& V_238 , & V_239 , & V_240 , & V_241 ,
& V_242 , & V_243 , & V_244 , & V_245 ,
& V_246 ) ;
if ( V_249 ) {
if ( ! V_246 ) {
if ( V_250 > 0 )
V_1 -> V_163 ++ ;
else if ( V_250 == 0 )
V_1 -> V_161 ++ ;
}
F_38 ( V_111 ) ;
return;
}
if ( V_121 && V_250 > 0 ) {
F_152 ( V_111 , V_250 ) ;
V_111 -> V_126 = F_153 ( V_111 , V_16 ) ;
if ( ( V_16 -> V_256 & V_257 ) && ! V_248 ) {
V_111 -> V_258 = F_154 ( V_252 ) ;
V_111 -> V_137 = V_259 ;
}
V_111 -> V_116 = V_16 ;
if ( V_233 )
F_155 ( V_111 , V_251 ) ;
if ( V_16 -> V_256 & V_260 )
F_156 ( & V_1 -> V_106 [ V_84 ] , V_111 ) ;
else
F_157 ( V_111 ) ;
} else {
F_38 ( V_111 ) ;
}
}
static int F_158 ( struct V_83 * V_29 , struct V_81 * V_81 ,
T_2 type , T_4 V_84 , T_4 V_85 , void * V_82 )
{
struct V_1 * V_1 = F_35 ( V_29 ) ;
F_159 ( & V_1 -> V_9 [ V_84 ] , V_81 ,
V_85 , V_261 ,
F_149 , V_82 ) ;
return 0 ;
}
static int F_160 ( struct V_107 * V_106 , int V_262 )
{
struct V_15 * V_16 = V_106 -> V_116 ;
struct V_1 * V_1 = F_15 ( V_16 ) ;
unsigned int V_263 = F_5 ( V_1 , 0 ) ;
unsigned int V_264 = F_6 ( V_1 , 0 ) ;
unsigned int V_68 = F_7 () ;
unsigned int V_265 = V_262 ;
unsigned int V_108 = - 1 ;
unsigned int V_266 , V_267 , V_109 ;
int V_176 ;
V_267 = F_76 ( & V_1 -> V_12 [ V_263 ] ,
V_265 , F_158 , NULL ) ;
V_109 = F_76 ( & V_1 -> V_12 [ V_264 ] ,
V_108 , F_40 , NULL ) ;
V_266 = V_267 + V_109 ;
if ( V_266 > 0 )
F_77 ( & V_1 -> V_68 [ V_68 ] ,
V_266 ,
0 ,
0 ) ;
V_176 = F_161 ( & V_1 -> V_9 [ 0 ] , F_146 ) ;
if ( V_176 )
V_267 = V_265 ;
if ( V_267 < V_265 ) {
F_162 ( V_106 ) ;
F_67 ( & V_1 -> V_68 [ V_68 ] ) ;
}
return V_267 ;
}
static int F_163 ( struct V_107 * V_106 , int V_262 )
{
struct V_15 * V_16 = V_106 -> V_116 ;
struct V_1 * V_1 = F_15 ( V_16 ) ;
unsigned int V_9 = ( V_106 - & V_1 -> V_106 [ 0 ] ) ;
unsigned int V_12 = F_5 ( V_1 , V_9 ) ;
unsigned int V_68 = F_10 ( V_1 , V_9 ) ;
unsigned int V_268 = V_262 ;
unsigned int V_266 ;
int V_176 ;
V_266 = F_76 ( & V_1 -> V_12 [ V_12 ] ,
V_268 , F_158 , NULL ) ;
if ( V_266 > 0 )
F_77 ( & V_1 -> V_68 [ V_68 ] ,
V_266 ,
0 ,
0 ) ;
V_176 = F_161 ( & V_1 -> V_9 [ V_9 ] , F_146 ) ;
if ( V_176 )
V_266 = V_268 ;
if ( V_266 < V_268 ) {
F_162 ( V_106 ) ;
F_67 ( & V_1 -> V_68 [ V_68 ] ) ;
}
return V_266 ;
}
static void F_164 ( unsigned long V_45 )
{
struct V_1 * V_1 = (struct V_1 * ) V_45 ;
F_63 ( V_1 ) ;
F_165 ( & V_1 -> V_269 ,
F_166 ( V_270 + V_271 ) ) ;
}
static void F_167 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
unsigned int V_46 ;
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_69 :
F_168 ( V_1 -> V_2 -> V_97 , V_16 ) ;
break;
case V_71 :
F_168 ( V_1 -> V_2 -> V_97 , V_1 ) ;
break;
case V_72 :
for ( V_46 = 0 ; V_46 < F_169 ( V_1 -> V_272 ) ; V_46 ++ )
if ( V_1 -> V_272 [ V_46 ] . V_273 )
F_168 ( V_1 -> V_274 [ V_46 ] . V_275 ,
V_1 -> V_272 [ V_46 ] . V_276 ) ;
break;
default:
break;
}
}
static int F_170 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
unsigned int V_46 , V_68 ;
int V_176 = 0 ;
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_69 :
V_176 = F_171 ( V_1 -> V_2 -> V_97 , F_64 ,
V_277 , V_16 -> V_50 , V_16 ) ;
break;
case V_71 :
V_176 = F_171 ( V_1 -> V_2 -> V_97 , F_72 ,
0 , V_16 -> V_50 , V_1 ) ;
break;
case V_72 :
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
V_68 = F_10 ( V_1 , V_46 ) ;
sprintf ( V_1 -> V_272 [ V_68 ] . V_278 ,
L_12 , V_16 -> V_50 , V_46 ) ;
V_1 -> V_272 [ V_68 ] . V_279 = F_74 ;
V_1 -> V_272 [ V_68 ] . V_276 = & V_1 -> V_106 [ V_46 ] ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ ) {
V_68 = F_11 ( V_1 , V_46 ) ;
sprintf ( V_1 -> V_272 [ V_68 ] . V_278 ,
L_13 , V_16 -> V_50 , V_46 ) ;
V_1 -> V_272 [ V_68 ] . V_279 = F_75 ;
V_1 -> V_272 [ V_68 ] . V_276 = V_1 ;
}
V_68 = F_12 ( V_1 ) ;
sprintf ( V_1 -> V_272 [ V_68 ] . V_278 ,
L_14 , V_16 -> V_50 ) ;
V_1 -> V_272 [ V_68 ] . V_279 = F_78 ;
V_1 -> V_272 [ V_68 ] . V_276 = V_1 ;
V_68 = F_13 ( V_1 ) ;
sprintf ( V_1 -> V_272 [ V_68 ] . V_278 ,
L_15 , V_16 -> V_50 ) ;
V_1 -> V_272 [ V_68 ] . V_279 = F_79 ;
V_1 -> V_272 [ V_68 ] . V_276 = V_1 ;
for ( V_46 = 0 ; V_46 < F_169 ( V_1 -> V_272 ) ; V_46 ++ )
V_1 -> V_272 [ V_46 ] . V_273 = 0 ;
for ( V_46 = 0 ; V_46 < V_1 -> V_280 ; V_46 ++ ) {
V_176 = F_171 ( V_1 -> V_274 [ V_46 ] . V_275 ,
V_1 -> V_272 [ V_46 ] . V_279 , 0 ,
V_1 -> V_272 [ V_46 ] . V_278 ,
V_1 -> V_272 [ V_46 ] . V_276 ) ;
if ( V_176 ) {
F_167 ( V_1 ) ;
break;
}
V_1 -> V_272 [ V_46 ] . V_273 = 1 ;
}
break;
default:
break;
}
return V_176 ;
}
static void F_172 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_69 :
case V_71 :
F_173 ( V_1 -> V_2 -> V_97 ) ;
break;
case V_72 :
for ( V_46 = 0 ; V_46 < V_1 -> V_280 ; V_46 ++ )
F_173 ( V_1 -> V_274 [ V_46 ] . V_275 ) ;
break;
default:
break;
}
}
static int F_174 ( struct V_1 * V_1 )
{
int V_176 ;
F_41 ( & V_1 -> V_281 ) ;
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_69 :
V_176 = F_175 ( V_1 -> V_29 ,
F_9 () ) ;
break;
case V_72 :
V_176 = F_175 ( V_1 -> V_29 ,
F_13 ( V_1 ) ) ;
break;
default:
V_176 = F_175 ( V_1 -> V_29 , - 1 ) ;
break;
}
F_46 ( & V_1 -> V_281 ) ;
return V_176 ;
}
static void F_176 ( struct V_1 * V_1 )
{
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_71 :
F_165 ( & V_1 -> V_269 , V_270 ) ;
break;
default:
break;
}
}
static int F_177 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
unsigned int V_46 ;
int V_176 ;
V_176 = F_170 ( V_1 ) ;
if ( V_176 ) {
F_49 ( V_16 , L_16 ) ;
return V_176 ;
}
V_176 = F_174 ( V_1 ) ;
if ( V_176 ) {
F_49 ( V_16 ,
L_17 ) ;
goto V_282;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
F_161 ( & V_1 -> V_9 [ V_46 ] , F_146 ) ;
if ( F_178 ( & V_1 -> V_9 [ V_46 ] ) == 0 ) {
F_49 ( V_16 , L_18 ) ;
V_176 = - V_229 ;
goto V_283;
}
}
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ )
F_179 ( & V_1 -> V_10 [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_180 ( & V_1 -> V_9 [ V_46 ] ) ;
if ( ! F_1 ( V_1 ) )
F_120 ( V_1 ) ;
F_131 ( V_16 ) ;
F_45 ( V_16 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_181 ( & V_1 -> V_106 [ V_46 ] ) ;
F_182 ( V_1 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_280 ; V_46 ++ )
F_67 ( & V_1 -> V_68 [ V_46 ] ) ;
F_176 ( V_1 ) ;
return 0 ;
V_283:
F_183 ( V_1 ) ;
V_282:
F_167 ( V_1 ) ;
return V_176 ;
}
static int F_184 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
unsigned int V_46 ;
int V_176 ;
for ( V_46 = 0 ; V_46 < V_1 -> V_280 ; V_46 ++ ) {
F_65 ( & V_1 -> V_68 [ V_46 ] ) ;
( void ) F_185 ( & V_1 -> V_68 [ V_46 ] ) ;
}
F_172 ( V_1 ) ;
F_186 ( & V_1 -> V_269 ) ;
F_187 ( V_1 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_188 ( & V_1 -> V_106 [ V_46 ] ) ;
F_62 ( V_16 ) ;
F_189 ( V_16 ) ;
if ( ! F_1 ( V_1 ) )
F_119 ( V_1 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ ) {
V_176 = F_190 ( & V_1 -> V_10 [ V_46 ] ) ;
if ( V_176 )
return V_176 ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
V_176 = F_191 ( & V_1 -> V_9 [ V_46 ] ) ;
if ( V_176 )
return V_176 ;
}
F_183 ( V_1 ) ;
F_167 ( V_1 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ )
F_192 ( & V_1 -> V_10 [ V_46 ] , F_34 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_193 ( & V_1 -> V_9 [ V_46 ] , F_145 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_284 ; V_46 ++ )
F_194 ( & V_1 -> V_12 [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_280 ; V_46 ++ )
F_195 ( & V_1 -> V_68 [ V_46 ] ) ;
return 0 ;
}
static int F_196 ( struct V_15 * V_16 , int V_285 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
int V_286 = F_118 ( V_16 ) ;
if ( V_285 < V_92 || V_285 > V_93 )
return - V_70 ;
if ( F_1 ( V_1 ) )
return - V_55 ;
if ( V_286 )
F_184 ( V_16 ) ;
V_16 -> V_90 = V_285 ;
if ( V_16 -> V_90 > V_1 -> V_91 )
F_58 ( V_16 ,
L_19 ,
V_16 -> V_90 , V_1 -> V_91 ) ;
if ( V_286 )
F_177 ( V_16 ) ;
return 0 ;
}
static void F_197 ( struct V_287 * V_288 )
{
struct V_1 * V_1 = F_198 ( V_288 , struct V_1 , V_94 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
int V_285 = F_55 ( V_1 -> V_29 ) ;
int V_176 ;
unsigned int V_46 ;
V_285 = F_56 ( int , V_92 , F_30 ( int , V_93 , V_285 ) ) ;
F_199 () ;
F_186 ( & V_1 -> V_269 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_188 ( & V_1 -> V_106 [ V_46 ] ) ;
F_65 ( & V_1 -> V_68 [ 0 ] ) ;
F_172 ( V_1 ) ;
V_176 = F_191 ( & V_1 -> V_9 [ 0 ] ) ;
if ( V_176 ) {
F_49 ( V_16 , L_20 ) ;
return;
}
F_193 ( & V_1 -> V_9 [ 0 ] , F_145 ) ;
F_194 ( & V_1 -> V_12 [ 0 ] ) ;
F_195 ( & V_1 -> V_68 [ 0 ] ) ;
V_16 -> V_90 = V_285 ;
F_161 ( & V_1 -> V_9 [ 0 ] , F_146 ) ;
if ( F_178 ( & V_1 -> V_9 [ 0 ] ) == 0 ) {
F_49 ( V_16 , L_21 ) ;
return;
}
F_180 ( & V_1 -> V_9 [ 0 ] ) ;
F_181 ( & V_1 -> V_106 [ 0 ] ) ;
F_67 ( & V_1 -> V_68 [ 0 ] ) ;
F_176 ( V_1 ) ;
F_200 () ;
F_53 ( V_16 , L_22 , V_16 -> V_90 ) ;
}
static void F_201 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 ) ;
struct V_83 * V_29 = V_1 -> V_29 ;
unsigned int V_46 , V_68 ;
switch ( F_32 ( V_29 ) ) {
case V_72 :
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ ) {
V_68 = F_10 ( V_1 , V_46 ) ;
F_74 ( V_1 -> V_274 [ V_68 ] . V_275 ,
& V_1 -> V_106 [ V_46 ] ) ;
}
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ ) {
V_68 = F_11 ( V_1 , V_46 ) ;
F_75 ( V_1 -> V_274 [ V_68 ] . V_275 , V_1 ) ;
}
break;
case V_71 :
F_72 ( V_1 -> V_2 -> V_97 , V_1 ) ;
break;
case V_69 :
F_64 ( V_1 -> V_2 -> V_97 , V_16 ) ;
break;
default:
break;
}
}
static int F_202 ( struct V_83 * V_29 ,
int (* F_203)( struct V_83 * , int ) ,
int (* F_204)( struct V_83 * , int * ) ,
int V_289 )
{
unsigned long time ;
int V_290 ;
int V_176 ;
F_205 ( F_206 () ) ;
V_176 = F_203 ( V_29 , V_289 ) ;
if ( V_176 )
return V_176 ;
time = V_270 + ( V_291 * 2 ) ;
do {
V_176 = F_204 ( V_29 , & V_290 ) ;
if ( V_176 )
return V_176 ;
if ( V_290 )
return 0 ;
F_207 ( V_291 / 10 ) ;
} while ( F_208 ( time , V_270 ) );
return - V_292 ;
}
static int F_209 ( struct V_1 * V_1 )
{
int V_176 ;
V_176 = F_202 ( V_1 -> V_29 , V_293 ,
V_294 , 0 ) ;
if ( V_176 )
F_210 ( F_211 ( V_1 ) , L_23 ,
V_176 ) ;
return V_176 ;
}
static int F_212 ( struct V_1 * V_1 )
{
int V_176 ;
V_176 = F_202 ( V_1 -> V_29 , V_295 ,
V_296 , 0 ) ;
if ( V_176 )
F_49 ( V_1 -> V_16 , L_24 ,
V_176 ) ;
return V_176 ;
}
static int F_213 ( struct V_1 * V_1 )
{
T_7 V_297 ;
union V_298 * V_299 = NULL ;
union V_298 V_300 = {
. V_301 [ 0 ] . V_302 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_301 [ 1 ] . V_302 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_301 [ 2 ] . V_302 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_301 [ 3 ] . V_302 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_176 ;
V_299 = F_214 ( V_1 -> V_2 ,
sizeof( union V_298 ) , & V_297 ) ;
if ( ! V_299 )
return - V_229 ;
memcpy ( V_299 , & V_300 , sizeof( union V_298 ) ) ;
F_41 ( & V_1 -> V_281 ) ;
V_176 = F_215 ( V_1 ,
V_297 ,
sizeof( union V_298 ) ) ;
F_46 ( & V_1 -> V_281 ) ;
F_216 ( V_1 -> V_2 , sizeof( union V_298 ) ,
V_299 , V_297 ) ;
return V_176 ;
}
static int F_217 ( struct V_1 * V_1 , T_2 V_303 )
{
T_7 V_304 ;
union V_305 * V_306 = NULL ;
unsigned int V_46 ;
int V_176 ;
V_306 = F_214 ( V_1 -> V_2 ,
sizeof( union V_305 ) , & V_304 ) ;
if ( ! V_306 )
return - V_229 ;
for ( V_46 = 0 ; V_46 < ( 1 << V_303 ) ; V_46 ++ )
( * V_306 ) . V_307 [ V_46 / 4 ] . V_302 [ V_46 % 4 ] = V_46 % V_1 -> V_11 ;
F_41 ( & V_1 -> V_281 ) ;
V_176 = F_218 ( V_1 ,
V_304 ,
sizeof( union V_305 ) ) ;
F_46 ( & V_1 -> V_281 ) ;
F_216 ( V_1 -> V_2 , sizeof( union V_305 ) ,
V_306 , V_304 ) ;
return V_176 ;
}
static int F_219 ( struct V_1 * V_1 , T_2 V_308 ,
T_2 V_309 , T_2 V_303 , T_2 V_310 , T_2 V_311 )
{
const T_2 V_312 = 0 ;
const T_2 V_313 = 1 ;
int V_176 ;
F_41 ( & V_1 -> V_281 ) ;
V_176 = F_220 ( V_1 ,
V_308 , V_309 ,
V_303 , V_310 ,
V_311 , V_312 ,
V_313 ) ;
F_46 ( & V_1 -> V_281 ) ;
return V_176 ;
}
static int F_221 ( struct V_1 * V_1 )
{
struct V_3 * V_116 = F_211 ( V_1 ) ;
const T_2 V_308 = 0 ;
const T_2 V_309 = V_314 |
V_315 |
V_316 |
V_317 ;
const T_2 V_303 = 7 ;
const T_2 V_310 = 0 ;
T_2 V_311 = F_222 ( V_1 , V_318 ) && ( V_1 -> V_11 > 1 ) ;
if ( V_311 ) {
if ( ! F_213 ( V_1 ) ) {
if ( F_217 ( V_1 , V_303 ) ) {
V_311 = 0 ;
F_223 ( V_116 , L_25
L_26 ) ;
}
} else {
V_311 = 0 ;
F_223 ( V_116 , L_27 ) ;
}
}
return F_219 ( V_1 , V_308 , V_309 ,
V_303 , V_310 , V_311 ) ;
}
static void F_224 ( struct V_287 * V_288 )
{
struct V_1 * V_1 = F_198 ( V_288 , struct V_1 , V_104 ) ;
if ( ! F_118 ( V_1 -> V_16 ) )
return;
F_199 () ;
F_225 ( V_1 ) ;
F_184 ( V_1 -> V_16 ) ;
F_212 ( V_1 ) ;
F_113 ( V_1 ) ;
F_226 ( V_1 ) ;
F_221 ( V_1 ) ;
F_227 ( V_1 ) ;
F_177 ( V_1 -> V_16 ) ;
F_200 () ;
}
static int F_228 ( struct V_1 * V_1 )
{
unsigned int V_319 = F_30 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_320 = F_30 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_46 ;
F_205 ( F_169 ( V_1 -> V_274 ) < V_319 + V_320 + 2 ) ;
for ( V_46 = 0 ; V_46 < V_319 + V_320 + 2 ; V_46 ++ )
V_1 -> V_274 [ V_46 ] . V_321 = V_46 ;
if ( F_222 ( V_1 , V_318 ) &&
V_1 -> V_322 . V_323 < 1 &&
V_1 -> V_11 >= V_319 &&
V_1 -> V_14 >= V_320 &&
V_1 -> V_284 >= V_319 + V_320 &&
V_1 -> V_280 >= V_319 + V_320 + 2 ) {
if ( ! F_229 ( V_1 -> V_2 , V_1 -> V_274 , V_319 + V_320 + 2 ) ) {
V_1 -> V_11 = V_319 ;
V_1 -> V_14 = V_320 ;
V_1 -> V_284 = V_319 + V_320 ;
V_1 -> V_280 = V_319 + V_320 + 2 ;
F_230 ( V_1 -> V_29 ,
V_72 ) ;
return 0 ;
}
}
if ( V_1 -> V_322 . V_323 < 1 &&
V_1 -> V_11 >= 1 &&
V_1 -> V_14 >= V_320 &&
V_1 -> V_284 >= 1 + V_320 &&
V_1 -> V_280 >= 1 + V_320 + 2 ) {
if ( ! F_229 ( V_1 -> V_2 , V_1 -> V_274 , 1 + V_320 + 2 ) ) {
V_1 -> V_11 = 1 ;
V_1 -> V_14 = V_320 ;
V_1 -> V_284 = 1 + V_320 ;
V_1 -> V_280 = 1 + V_320 + 2 ;
F_230 ( V_1 -> V_29 ,
V_72 ) ;
return 0 ;
}
}
if ( V_1 -> V_322 . V_323 < 2 &&
V_1 -> V_11 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_284 >= 2 &&
V_1 -> V_280 >= 1 &&
! F_231 ( V_1 -> V_2 ) ) {
V_1 -> V_11 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_284 = 2 ;
V_1 -> V_280 = 1 ;
F_230 ( V_1 -> V_29 , V_71 ) ;
return 0 ;
}
if ( V_1 -> V_322 . V_323 < 3 &&
V_1 -> V_11 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_284 >= 2 &&
V_1 -> V_280 >= 3 ) {
V_1 -> V_11 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_284 = 2 ;
V_1 -> V_280 = 3 ;
F_230 ( V_1 -> V_29 , V_69 ) ;
return 0 ;
}
F_230 ( V_1 -> V_29 , V_324 ) ;
return - V_70 ;
}
static void F_232 ( struct V_1 * V_1 )
{
switch ( F_32 ( V_1 -> V_29 ) ) {
case V_72 :
F_233 ( V_1 -> V_2 ) ;
break;
case V_71 :
F_234 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_230 ( V_1 -> V_29 , V_324 ) ;
}
static void F_235 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_236 ( & V_1 -> V_106 [ V_46 ] ) ;
F_237 ( V_1 ) ;
F_232 ( V_1 ) ;
}
static int F_238 ( struct V_1 * V_1 )
{
struct V_3 * V_116 = F_211 ( V_1 ) ;
struct V_15 * V_16 = V_1 -> V_16 ;
unsigned int V_46 ;
int V_176 ;
V_176 = F_239 ( V_1 ) ;
if ( V_176 ) {
F_223 ( V_116 , L_28
L_29 ) ;
F_240 ( V_1 -> V_29 ) ;
}
V_176 = F_241 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_30 ) ;
return V_176 ;
}
F_242 ( V_1 ) ;
V_176 = F_228 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_31
L_32 ) ;
return V_176 ;
}
V_176 = F_243 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_33 ) ;
goto V_325;
}
F_226 ( V_1 ) ;
V_176 = F_221 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_34 ) ;
goto V_325;
}
switch ( F_32 ( V_1 -> V_29 ) ) {
default:
F_244 ( V_16 , & V_1 -> V_106 [ 0 ] , F_160 , 64 ) ;
break;
case V_72 :
for ( V_46 = 0 ; V_46 < V_1 -> V_11 ; V_46 ++ )
F_244 ( V_16 , & V_1 -> V_106 [ V_46 ] ,
F_163 , 64 ) ;
break;
}
return 0 ;
V_325:
F_232 ( V_1 ) ;
F_237 ( V_1 ) ;
return V_176 ;
}
static void F_245 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_169 ( V_1 -> V_326 ) ; V_46 ++ )
if ( V_1 -> V_326 [ V_46 ] . V_327 )
F_246 ( V_1 -> V_326 [ V_46 ] . V_327 ) ;
}
static int T_9 F_247 ( struct V_328 * V_2 ,
const struct V_329 * V_330 )
{
struct V_3 * V_116 = & V_2 -> V_116 ;
struct V_15 * V_16 ;
struct V_1 * V_1 ;
int V_331 = 0 ;
unsigned int V_46 ;
int V_176 ;
int V_332 = 1 ;
#ifdef F_4
int V_333 = 0 ;
#endif
V_16 = F_248 ( sizeof( struct V_1 ) ) ;
if ( ! V_16 ) {
F_249 ( L_35 ) ;
return - V_229 ;
}
F_250 ( V_2 , V_16 ) ;
F_251 ( V_16 , & V_2 -> V_116 ) ;
V_1 = F_15 ( V_16 ) ;
V_1 -> V_16 = V_16 ;
V_1 -> V_2 = V_2 ;
V_176 = F_252 ( V_2 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_36 ) ;
goto V_334;
}
V_176 = F_253 ( V_2 , V_39 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_37 ) ;
goto V_335;
}
F_254 ( V_2 ) ;
V_176 = F_255 ( V_2 , F_256 ( 40 ) ) ;
if ( V_176 ) {
V_176 = F_255 ( V_2 , F_256 ( 32 ) ) ;
if ( V_176 ) {
F_210 ( V_116 , L_38 ) ;
goto V_336;
}
V_176 = F_257 ( V_2 , F_256 ( 32 ) ) ;
if ( V_176 ) {
F_210 ( V_116 , L_39
L_40 , 32 ) ;
goto V_336;
}
} else {
V_176 = F_257 ( V_2 , F_256 ( 40 ) ) ;
if ( V_176 ) {
F_210 ( V_116 , L_39
L_40 , 40 ) ;
goto V_336;
}
V_331 = 1 ;
}
for ( V_46 = 0 ; V_46 < F_169 ( V_1 -> V_326 ) ; V_46 ++ ) {
if ( ! ( F_258 ( V_2 , V_46 ) & V_337 ) )
continue;
V_1 -> V_326 [ V_46 ] . V_78 = F_259 ( V_2 , V_46 ) ;
V_1 -> V_326 [ V_46 ] . V_327 = F_260 ( V_2 , V_46 , V_1 -> V_326 [ V_46 ] . V_78 ) ;
if ( ! V_1 -> V_326 [ V_46 ] . V_327 ) {
F_210 ( V_116 , L_41 , V_46 ) ;
V_176 = - V_338 ;
goto V_339;
}
V_1 -> V_326 [ V_46 ] . V_340 = F_261 ( V_2 , V_46 ) ;
}
V_1 -> V_29 = F_262 ( NULL , V_1 , V_2 , V_1 -> V_326 ,
F_169 ( V_1 -> V_326 ) ) ;
if ( ! V_1 -> V_29 ) {
F_210 ( V_116 , L_42 ) ;
V_176 = - V_338 ;
goto V_339;
}
#ifdef F_4
V_333 = F_263 ( V_2 , V_341 ) ;
if ( V_333 ) {
F_264 ( V_2 , V_333 + V_342 ,
( T_4 * ) & V_1 -> V_8 ) ;
if ( V_1 -> V_8 ) {
V_176 = F_265 ( V_2 , V_1 -> V_8 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_43
L_44 ,
V_176 ) ;
goto V_343;
}
V_1 -> V_5 |= V_6 ;
V_332 = V_1 -> V_8 ;
}
}
#endif
V_1 -> V_195 = F_266 ( V_332 * sizeof( * V_1 -> V_195 ) , V_344 ) ;
if ( ! V_1 -> V_195 ) {
F_249 ( L_45 ) ;
V_176 = - V_229 ;
goto V_345;
}
V_176 = F_209 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_46 ) ;
goto V_346;
}
F_267 ( & V_1 -> V_281 ) ;
V_176 = F_227 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 ,
L_47 ) ;
goto V_347;
}
F_62 ( V_16 ) ;
if ( ! F_1 ( V_1 ) ) {
V_176 = F_268 ( V_1 -> V_29 , 0 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_48 ) ;
goto V_347;
}
}
V_176 = F_238 ( V_1 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_49 ) ;
goto V_347;
}
F_269 ( & V_1 -> V_269 ) ;
V_1 -> V_269 . V_348 = F_164 ;
V_1 -> V_269 . V_45 = ( unsigned long ) V_1 ;
F_270 ( & V_1 -> V_104 , F_224 ) ;
F_270 ( & V_1 -> V_94 , F_197 ) ;
for ( V_46 = 0 ; V_46 < V_1 -> V_14 ; V_46 ++ )
F_267 ( & V_1 -> V_86 [ V_46 ] ) ;
V_1 -> V_91 = V_1 -> V_322 . V_90 ;
( void ) F_196 ( V_16 , V_1 -> V_91 ) ;
#ifdef F_4
if ( F_1 ( V_1 ) && V_2 -> V_349 &&
F_116 ( V_1 -> V_214 ) )
F_139 ( V_1 -> V_214 ) ;
#endif
V_176 = F_114 ( V_16 , V_1 -> V_214 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_50 ) ;
goto V_350;
}
V_1 -> V_66 = V_1 -> V_322 . V_351 ;
V_1 -> V_67 = V_1 -> V_66 ;
if ( F_1 ( V_1 ) )
V_16 -> V_352 = & V_353 ;
else
V_16 -> V_352 = & V_354 ;
V_16 -> V_355 = 2 * V_291 ;
V_16 -> V_356 = & V_357 ;
V_16 -> V_256 |= V_358 | V_359 ;
if ( F_222 ( V_1 , V_360 ) ) {
V_16 -> V_256 &= ~ V_358 ;
V_1 -> V_135 = 1 ;
V_1 -> V_136 = V_1 -> V_322 . V_136 ;
F_271 ( V_116 , L_51 , V_1 -> V_136 ) ;
}
if ( F_222 ( V_1 , V_361 ) )
V_16 -> V_362 |= V_363 | V_364 ;
if ( F_222 ( V_1 , V_365 ) )
V_16 -> V_362 |= V_366 |
V_367 | V_368 ;
if ( F_222 ( V_1 , V_369 ) )
V_16 -> V_362 |= V_257 ;
V_16 -> V_256 |= V_16 -> V_362 ;
if ( V_331 )
V_16 -> V_256 |= V_370 ;
V_16 -> V_5 |= V_371 ;
V_176 = F_272 ( V_16 ) ;
if ( V_176 ) {
F_210 ( V_116 , L_52 ) ;
goto V_350;
}
return 0 ;
V_350:
F_235 ( V_1 ) ;
V_347:
F_273 ( V_1 -> V_29 ) ;
V_346:
F_274 ( V_1 -> V_195 ) ;
V_345:
#ifdef F_4
if ( F_2 ( V_1 ) ) {
F_275 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
V_343:
F_276 ( V_1 -> V_29 ) ;
#endif
V_339:
F_245 ( V_1 ) ;
V_336:
F_277 ( V_2 ) ;
V_335:
F_278 ( V_2 ) ;
V_334:
F_250 ( V_2 , NULL ) ;
F_279 ( V_16 ) ;
return V_176 ;
}
static void T_10 F_280 ( struct V_328 * V_2 )
{
struct V_15 * V_16 = F_281 ( V_2 ) ;
if ( V_16 ) {
struct V_1 * V_1 = F_15 ( V_16 ) ;
F_282 ( & V_1 -> V_104 ) ;
F_282 ( & V_1 -> V_94 ) ;
F_283 ( V_16 ) ;
F_235 ( V_1 ) ;
F_273 ( V_1 -> V_29 ) ;
#ifdef F_4
if ( F_2 ( V_1 ) ) {
F_275 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
#endif
F_274 ( V_1 -> V_195 ) ;
F_276 ( V_1 -> V_29 ) ;
F_245 ( V_1 ) ;
F_277 ( V_2 ) ;
F_278 ( V_2 ) ;
F_250 ( V_2 , NULL ) ;
F_279 ( V_16 ) ;
}
}
static int T_11 F_284 ( void )
{
F_285 ( L_53 , V_372 , V_41 ) ;
return F_286 ( & V_373 ) ;
}
static void T_12 F_287 ( void )
{
F_288 ( & V_373 ) ;
}
