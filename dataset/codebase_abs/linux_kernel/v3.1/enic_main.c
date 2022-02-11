static int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_4 ;
}
static inline unsigned int F_2 ( struct V_1 * V_1 , unsigned int V_5 )
{
return V_5 ;
}
static inline unsigned int F_3 ( struct V_1 * V_1 , unsigned int V_6 )
{
return V_1 -> V_7 + V_6 ;
}
static inline unsigned int F_4 ( void )
{
return 0 ;
}
static inline unsigned int F_5 ( void )
{
return 1 ;
}
static inline unsigned int F_6 ( void )
{
return 2 ;
}
static inline unsigned int F_7 ( struct V_1 * V_1 , unsigned int V_5 )
{
return V_1 -> V_8 [ F_2 ( V_1 , V_5 ) ] . V_9 ;
}
static inline unsigned int F_8 ( struct V_1 * V_1 , unsigned int V_6 )
{
return V_1 -> V_8 [ F_3 ( V_1 , V_6 ) ] . V_9 ;
}
static inline unsigned int F_9 ( struct V_1 * V_1 )
{
return V_1 -> V_7 + V_1 -> V_10 ;
}
static inline unsigned int F_10 ( struct V_1 * V_1 )
{
return V_1 -> V_7 + V_1 -> V_10 + 1 ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
V_14 -> V_15 = ( V_16 | V_17 ) ;
V_14 -> V_18 = ( V_19 | V_20 ) ;
V_14 -> V_21 = V_22 ;
V_14 -> V_23 = V_24 ;
if ( F_13 ( V_12 ) ) {
F_14 ( V_14 , F_15 ( V_1 -> V_25 ) ) ;
V_14 -> V_26 = V_27 ;
} else {
F_14 ( V_14 , - 1 ) ;
V_14 -> V_26 = - 1 ;
}
V_14 -> V_28 = V_29 ;
return 0 ;
}
static void F_16 ( struct V_11 * V_12 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_32 * V_33 ;
F_17 ( V_1 , & V_33 ) ;
strncpy ( V_31 -> V_34 , V_35 , sizeof( V_31 -> V_34 ) ) ;
strncpy ( V_31 -> V_36 , V_37 , sizeof( V_31 -> V_36 ) ) ;
strncpy ( V_31 -> V_38 , V_33 -> V_38 ,
sizeof( V_31 -> V_38 ) ) ;
strncpy ( V_31 -> V_39 , F_18 ( V_1 -> V_2 ) ,
sizeof( V_31 -> V_39 ) ) ;
}
static void F_19 ( struct V_11 * V_12 , T_1 V_40 , T_2 * V_41 )
{
unsigned int V_42 ;
switch ( V_40 ) {
case V_43 :
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
memcpy ( V_41 , V_45 [ V_42 ] . V_46 , V_47 ) ;
V_41 += V_47 ;
}
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ ) {
memcpy ( V_41 , V_49 [ V_42 ] . V_46 , V_47 ) ;
V_41 += V_47 ;
}
break;
}
}
static int F_20 ( struct V_11 * V_12 , int V_50 )
{
switch ( V_50 ) {
case V_43 :
return V_44 + V_48 ;
default:
return - V_51 ;
}
}
static void F_21 ( struct V_11 * V_12 ,
struct V_52 * V_53 , T_3 * V_41 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_54 * V_55 ;
unsigned int V_42 ;
F_22 ( V_1 , & V_55 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
* ( V_41 ++ ) = ( ( T_3 * ) & V_55 -> V_56 ) [ V_45 [ V_42 ] . V_57 ] ;
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ )
* ( V_41 ++ ) = ( ( T_3 * ) & V_55 -> V_58 ) [ V_49 [ V_42 ] . V_57 ] ;
}
static T_1 F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
return V_1 -> V_59 ;
}
static void F_24 ( struct V_11 * V_12 , T_1 V_60 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
V_1 -> V_59 = V_60 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_61 * V_14 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
V_14 -> V_62 = V_1 -> V_62 ;
V_14 -> V_63 = V_1 -> V_63 ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 ,
struct V_61 * V_14 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
T_1 V_62 ;
T_1 V_63 ;
unsigned int V_42 , V_64 ;
V_62 = F_27 ( T_1 , V_14 -> V_62 ,
F_28 ( V_1 -> V_25 ) ) ;
V_63 = F_27 ( T_1 , V_14 -> V_63 ,
F_28 ( V_1 -> V_25 ) ) ;
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_65 :
if ( V_62 != V_63 )
return - V_66 ;
V_64 = F_4 () ;
F_30 ( & V_1 -> V_64 [ V_64 ] ,
V_62 ) ;
break;
case V_67 :
if ( V_62 != V_63 )
return - V_66 ;
F_30 ( & V_1 -> V_64 [ 0 ] ,
V_62 ) ;
break;
case V_68 :
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ ) {
V_64 = F_8 ( V_1 , V_42 ) ;
F_30 ( & V_1 -> V_64 [ V_64 ] ,
V_62 ) ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
V_64 = F_7 ( V_1 , V_42 ) ;
F_30 ( & V_1 -> V_64 [ V_64 ] ,
V_63 ) ;
}
break;
default:
break;
}
V_1 -> V_62 = V_62 ;
V_1 -> V_63 = V_63 ;
return 0 ;
}
static void F_31 ( struct V_69 * V_6 , struct V_70 * V_71 )
{
struct V_1 * V_1 = F_32 ( V_6 -> V_25 ) ;
if ( V_71 -> V_72 )
F_33 ( V_1 -> V_2 , V_71 -> V_73 ,
V_71 -> V_74 , V_75 ) ;
else
F_34 ( V_1 -> V_2 , V_71 -> V_73 ,
V_71 -> V_74 , V_75 ) ;
if ( V_71 -> V_76 )
F_35 ( V_71 -> V_76 ) ;
}
static void F_36 ( struct V_69 * V_6 ,
struct V_77 * V_77 , struct V_70 * V_71 , void * V_78 )
{
F_31 ( V_6 , V_71 ) ;
}
static int F_37 ( struct V_79 * V_25 , struct V_77 * V_77 ,
T_2 type , T_4 V_80 , T_4 V_81 , void * V_78 )
{
struct V_1 * V_1 = F_32 ( V_25 ) ;
F_38 ( & V_1 -> V_82 [ V_80 ] ) ;
F_39 ( & V_1 -> V_6 [ V_80 ] , V_77 ,
V_81 , F_36 ,
V_78 ) ;
if ( F_40 ( V_1 -> V_12 ) &&
F_41 ( & V_1 -> V_6 [ V_80 ] ) >=
( V_83 + V_84 ) )
F_42 ( V_1 -> V_12 ) ;
F_43 ( & V_1 -> V_82 [ V_80 ] ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_1 )
{
unsigned int V_42 ;
T_1 V_85 ;
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ ) {
V_85 = F_45 ( & V_1 -> V_6 [ V_42 ] ) ;
if ( V_85 )
F_46 ( V_1 -> V_12 , L_1 ,
V_42 , V_85 ) ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
V_85 = F_47 ( & V_1 -> V_5 [ V_42 ] ) ;
if ( V_85 )
F_46 ( V_1 -> V_12 , L_2 ,
V_42 , V_85 ) ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
T_1 V_59 = F_49 ( V_1 -> V_25 ) ;
if ( V_59 != V_1 -> V_59 ) {
F_50 ( V_1 -> V_12 , L_3 ,
V_1 -> V_59 , V_59 ) ;
V_1 -> V_59 = V_59 ;
}
}
static void F_51 ( struct V_1 * V_1 )
{
T_1 V_86 = F_52 ( V_1 -> V_25 ) ;
struct V_11 * V_12 = V_1 -> V_12 ;
if ( V_86 && V_86 != V_1 -> V_87 ) {
V_1 -> V_87 = V_86 ;
if ( F_1 ( V_1 ) ) {
V_86 = F_53 ( int , V_88 ,
F_27 ( int , V_89 , V_86 ) ) ;
if ( V_86 != V_12 -> V_86 )
F_54 ( & V_1 -> V_90 ) ;
} else {
if ( V_86 < V_12 -> V_86 )
F_55 ( V_12 ,
L_4
L_5 ,
V_12 -> V_86 , V_86 ) ;
}
}
}
static void F_56 ( struct V_1 * V_1 )
{
int V_91 = F_57 ( V_1 -> V_25 ) ;
int V_92 = F_13 ( V_1 -> V_12 ) ;
if ( V_91 && ! V_92 ) {
F_50 ( V_1 -> V_12 , L_6 ) ;
F_58 ( V_1 -> V_12 ) ;
} else if ( ! V_91 && V_92 ) {
F_50 ( V_1 -> V_12 , L_7 ) ;
F_59 ( V_1 -> V_12 ) ;
}
}
static void F_60 ( struct V_1 * V_1 )
{
F_48 ( V_1 ) ;
F_51 ( V_1 ) ;
F_56 ( V_1 ) ;
}
static T_5 F_61 ( int V_93 , void * V_41 )
{
struct V_11 * V_12 = V_41 ;
struct V_1 * V_1 = F_12 ( V_12 ) ;
unsigned int V_94 = F_4 () ;
unsigned int V_95 = F_5 () ;
unsigned int V_96 = F_6 () ;
T_1 V_97 ;
F_62 ( & V_1 -> V_64 [ V_94 ] ) ;
V_97 = F_63 ( V_1 -> V_98 ) ;
if ( ! V_97 ) {
F_64 ( & V_1 -> V_64 [ V_94 ] ) ;
return V_99 ;
}
if ( F_65 ( V_97 , V_96 ) ) {
F_66 ( & V_1 -> V_64 [ V_96 ] ) ;
F_60 ( V_1 ) ;
}
if ( F_65 ( V_97 , V_95 ) ) {
F_66 ( & V_1 -> V_64 [ V_95 ] ) ;
F_44 ( V_1 ) ;
F_54 ( & V_1 -> V_100 ) ;
return V_101 ;
}
if ( F_65 ( V_97 , V_94 ) ) {
if ( F_67 ( & V_1 -> V_102 [ 0 ] ) )
F_68 ( & V_1 -> V_102 [ 0 ] ) ;
} else {
F_64 ( & V_1 -> V_64 [ V_94 ] ) ;
}
return V_101 ;
}
static T_5 F_69 ( int V_93 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
F_70 ( & V_1 -> V_102 [ 0 ] ) ;
return V_101 ;
}
static T_5 F_71 ( int V_93 , void * V_41 )
{
struct V_103 * V_102 = V_41 ;
F_70 ( V_102 ) ;
return V_101 ;
}
static T_5 F_72 ( int V_93 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
unsigned int V_8 = F_3 ( V_1 , 0 ) ;
unsigned int V_64 = F_8 ( V_1 , 0 ) ;
unsigned int V_104 = - 1 ;
unsigned int V_105 ;
V_105 = F_73 ( & V_1 -> V_8 [ V_8 ] ,
V_104 , F_37 , NULL ) ;
F_74 ( & V_1 -> V_64 [ V_64 ] ,
V_105 ,
1 ,
1 ) ;
return V_101 ;
}
static T_5 F_75 ( int V_93 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
unsigned int V_64 = F_9 ( V_1 ) ;
F_66 ( & V_1 -> V_64 [ V_64 ] ) ;
F_44 ( V_1 ) ;
F_54 ( & V_1 -> V_100 ) ;
return V_101 ;
}
static T_5 F_76 ( int V_93 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
unsigned int V_64 = F_10 ( V_1 ) ;
F_66 ( & V_1 -> V_64 [ V_64 ] ) ;
F_60 ( V_1 ) ;
return V_101 ;
}
static inline void F_77 ( struct V_1 * V_1 ,
struct V_69 * V_6 , struct V_106 * V_107 ,
unsigned int V_108 , int V_109 )
{
T_6 * V_110 ;
for ( V_110 = F_78 ( V_107 ) -> V_111 ; V_108 ; V_110 ++ ) {
V_108 -= V_110 -> V_112 ;
F_79 ( V_6 , V_107 ,
F_80 ( V_1 -> V_2 , V_110 -> V_113 ,
V_110 -> V_114 , V_110 -> V_112 ,
V_75 ) ,
V_110 -> V_112 ,
( V_108 == 0 ) ,
V_109 ) ;
}
}
static inline void F_81 ( struct V_1 * V_1 ,
struct V_69 * V_6 , struct V_106 * V_107 ,
int V_115 , unsigned int V_116 , int V_109 )
{
unsigned int V_117 = F_82 ( V_107 ) ;
unsigned int V_108 = V_107 -> V_74 - V_117 ;
int V_118 = ( V_108 == 0 ) ;
F_83 ( V_6 , V_107 ,
F_84 ( V_1 -> V_2 , V_107 -> V_41 ,
V_117 , V_75 ) ,
V_117 ,
V_115 , V_116 ,
V_118 , V_109 ) ;
if ( ! V_118 )
F_77 ( V_1 , V_6 , V_107 , V_108 , V_109 ) ;
}
static inline void F_85 ( struct V_1 * V_1 ,
struct V_69 * V_6 , struct V_106 * V_107 ,
int V_115 , unsigned int V_116 , int V_109 )
{
unsigned int V_117 = F_82 ( V_107 ) ;
unsigned int V_108 = V_107 -> V_74 - V_117 ;
unsigned int V_119 = F_86 ( V_107 ) ;
unsigned int V_120 = V_119 + V_107 -> V_120 ;
int V_118 = ( V_108 == 0 ) ;
F_87 ( V_6 , V_107 ,
F_84 ( V_1 -> V_2 , V_107 -> V_41 ,
V_117 , V_75 ) ,
V_117 ,
V_120 ,
V_119 ,
V_115 , V_116 ,
V_118 , V_109 ) ;
if ( ! V_118 )
F_77 ( V_1 , V_6 , V_107 , V_108 , V_109 ) ;
}
static inline void F_88 ( struct V_1 * V_1 ,
struct V_69 * V_6 , struct V_106 * V_107 , unsigned int V_121 ,
int V_115 , unsigned int V_116 , int V_109 )
{
unsigned int V_122 = F_82 ( V_107 ) ;
unsigned int V_108 = V_107 -> V_74 - V_122 ;
unsigned int V_119 = F_89 ( V_107 ) + F_90 ( V_107 ) ;
int V_118 = ( V_108 == 0 ) ;
unsigned int V_74 ;
T_7 V_73 ;
unsigned int V_57 = 0 ;
T_6 * V_110 ;
if ( V_107 -> V_123 == F_91 ( V_124 ) ) {
F_92 ( V_107 ) -> V_125 = 0 ;
F_93 ( V_107 ) -> V_125 = ~ F_94 ( F_92 ( V_107 ) -> V_126 ,
F_92 ( V_107 ) -> V_127 , 0 , V_128 , 0 ) ;
} else if ( V_107 -> V_123 == F_91 ( V_129 ) ) {
F_93 ( V_107 ) -> V_125 = ~ F_95 ( & F_96 ( V_107 ) -> V_126 ,
& F_96 ( V_107 ) -> V_127 , 0 , V_128 , 0 ) ;
}
while ( V_122 ) {
V_74 = F_97 ( V_122 , ( unsigned int ) V_130 ) ;
V_73 = F_84 ( V_1 -> V_2 , V_107 -> V_41 + V_57 ,
V_74 , V_75 ) ;
F_98 ( V_6 , V_107 ,
V_73 ,
V_74 ,
V_121 , V_119 ,
V_115 , V_116 ,
V_118 && ( V_74 == V_122 ) , V_109 ) ;
V_122 -= V_74 ;
V_57 += V_74 ;
}
if ( V_118 )
return;
for ( V_110 = F_78 ( V_107 ) -> V_111 ; V_108 ; V_110 ++ ) {
V_108 -= V_110 -> V_112 ;
V_122 = V_110 -> V_112 ;
V_57 = V_110 -> V_114 ;
while ( V_122 ) {
V_74 = F_97 ( V_122 ,
( unsigned int ) V_130 ) ;
V_73 = F_80 ( V_1 -> V_2 , V_110 -> V_113 ,
V_57 , V_74 ,
V_75 ) ;
F_79 ( V_6 , V_107 ,
V_73 ,
V_74 ,
( V_108 == 0 ) &&
( V_74 == V_122 ) ,
V_109 ) ;
V_122 -= V_74 ;
V_57 += V_74 ;
}
}
}
static inline void F_99 ( struct V_1 * V_1 ,
struct V_69 * V_6 , struct V_106 * V_107 )
{
unsigned int V_121 = F_78 ( V_107 ) -> V_131 ;
unsigned int V_116 = 0 ;
int V_115 = 0 ;
int V_109 = 0 ;
if ( F_100 ( V_107 ) ) {
V_115 = 1 ;
V_116 = F_101 ( V_107 ) ;
} else if ( V_1 -> V_132 ) {
V_116 = V_1 -> V_133 ;
V_109 = 1 ;
}
if ( V_121 )
F_88 ( V_1 , V_6 , V_107 , V_121 ,
V_115 , V_116 , V_109 ) ;
else if ( V_107 -> V_134 == V_135 )
F_85 ( V_1 , V_6 , V_107 ,
V_115 , V_116 , V_109 ) ;
else
F_81 ( V_1 , V_6 , V_107 ,
V_115 , V_116 , V_109 ) ;
}
static T_8 F_102 ( struct V_106 * V_107 ,
struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_69 * V_6 = & V_1 -> V_6 [ 0 ] ;
unsigned long V_136 ;
if ( V_107 -> V_74 <= 0 ) {
F_103 ( V_107 ) ;
return V_137 ;
}
if ( F_78 ( V_107 ) -> V_131 == 0 &&
F_78 ( V_107 ) -> V_138 + 1 > V_139 &&
F_104 ( V_107 ) ) {
F_103 ( V_107 ) ;
return V_137 ;
}
F_105 ( & V_1 -> V_82 [ 0 ] , V_136 ) ;
if ( F_41 ( V_6 ) <
F_78 ( V_107 ) -> V_138 + V_84 ) {
F_106 ( V_12 ) ;
F_46 ( V_12 , L_8 ) ;
F_107 ( & V_1 -> V_82 [ 0 ] , V_136 ) ;
return V_140 ;
}
F_99 ( V_1 , V_6 , V_107 ) ;
if ( F_41 ( V_6 ) < V_83 + V_84 )
F_106 ( V_12 ) ;
F_107 ( & V_1 -> V_82 [ 0 ] , V_136 ) ;
return V_137 ;
}
static struct V_141 * F_108 ( struct V_11 * V_12 ,
struct V_141 * V_142 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_54 * V_53 ;
F_22 ( V_1 , & V_53 ) ;
V_142 -> V_143 = V_53 -> V_56 . V_144 ;
V_142 -> V_145 = V_53 -> V_56 . V_146 ;
V_142 -> V_147 = V_53 -> V_56 . V_147 ;
V_142 -> V_148 = V_53 -> V_56 . V_149 ;
V_142 -> V_150 = V_53 -> V_58 . V_151 ;
V_142 -> V_152 = V_53 -> V_58 . V_153 ;
V_142 -> V_154 = V_53 -> V_58 . V_154 ;
V_142 -> V_155 = V_53 -> V_58 . V_156 ;
V_142 -> V_157 = V_1 -> V_158 ;
V_142 -> V_159 = V_1 -> V_160 ;
V_142 -> V_161 = V_53 -> V_58 . V_162 + V_53 -> V_58 . V_163 ;
return V_142 ;
}
void F_109 ( struct V_1 * V_1 )
{
V_1 -> V_164 = 0 ;
V_1 -> V_165 = 0 ;
V_1 -> V_136 = 0 ;
}
static int F_110 ( struct V_11 * V_12 , char * V_166 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_111 ( V_166 ) && ! F_112 ( V_166 ) )
return - V_167 ;
} else {
if ( ! F_111 ( V_166 ) )
return - V_167 ;
}
memcpy ( V_12 -> V_168 , V_166 , V_12 -> V_169 ) ;
return 0 ;
}
static int F_113 ( struct V_11 * V_12 , void * V_170 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_171 * V_126 = V_170 ;
char * V_166 = V_126 -> V_172 ;
int V_173 ;
if ( F_114 ( V_1 -> V_12 ) ) {
V_173 = F_115 ( V_1 ) ;
if ( V_173 )
return V_173 ;
}
V_173 = F_110 ( V_12 , V_166 ) ;
if ( V_173 )
return V_173 ;
if ( F_114 ( V_1 -> V_12 ) ) {
V_173 = F_116 ( V_1 ) ;
if ( V_173 )
return V_173 ;
}
return V_173 ;
}
static int F_117 ( struct V_11 * V_12 , void * V_170 )
{
struct V_171 * V_126 = V_170 ;
char * V_166 = V_126 -> V_172 ;
struct V_1 * V_1 = F_12 ( V_12 ) ;
int V_173 ;
V_173 = F_115 ( V_1 ) ;
if ( V_173 )
return V_173 ;
V_173 = F_110 ( V_12 , V_166 ) ;
if ( V_173 )
return V_173 ;
return F_116 ( V_1 ) ;
}
static void F_118 ( struct V_1 * V_1 )
{
struct V_11 * V_12 = V_1 -> V_12 ;
struct V_174 * V_175 ;
unsigned int V_164 = F_119 ( V_12 ) ;
T_2 V_176 [ V_177 ] [ V_178 ] ;
unsigned int V_42 , V_179 ;
if ( V_164 > V_177 ) {
F_55 ( V_12 , L_9
L_10 ,
V_177 , V_164 ) ;
V_164 = V_177 ;
}
V_42 = 0 ;
F_120 (ha, netdev) {
if ( V_42 == V_164 )
break;
memcpy ( V_176 [ V_42 ++ ] , V_175 -> V_166 , V_178 ) ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_164 ; V_42 ++ ) {
for ( V_179 = 0 ; V_179 < V_164 ; V_179 ++ )
if ( F_121 ( V_1 -> V_176 [ V_42 ] ,
V_176 [ V_179 ] ) == 0 )
break;
if ( V_179 == V_164 )
F_122 ( V_1 , V_1 -> V_176 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_164 ; V_42 ++ ) {
for ( V_179 = 0 ; V_179 < V_1 -> V_164 ; V_179 ++ )
if ( F_121 ( V_176 [ V_42 ] ,
V_1 -> V_176 [ V_179 ] ) == 0 )
break;
if ( V_179 == V_1 -> V_164 )
F_123 ( V_1 , V_176 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_164 ; V_42 ++ )
memcpy ( V_1 -> V_176 [ V_42 ] , V_176 [ V_42 ] , V_178 ) ;
V_1 -> V_164 = V_164 ;
}
static void F_124 ( struct V_1 * V_1 )
{
struct V_11 * V_12 = V_1 -> V_12 ;
struct V_174 * V_175 ;
unsigned int V_165 = F_125 ( V_12 ) ;
T_2 V_180 [ V_181 ] [ V_178 ] ;
unsigned int V_42 , V_179 ;
if ( V_165 > V_181 ) {
F_55 ( V_12 , L_9
L_11 ,
V_181 , V_165 ) ;
V_165 = V_181 ;
}
V_42 = 0 ;
F_126 (ha, netdev) {
if ( V_42 == V_165 )
break;
memcpy ( V_180 [ V_42 ++ ] , V_175 -> V_166 , V_178 ) ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_165 ; V_42 ++ ) {
for ( V_179 = 0 ; V_179 < V_165 ; V_179 ++ )
if ( F_121 ( V_1 -> V_180 [ V_42 ] ,
V_180 [ V_179 ] ) == 0 )
break;
if ( V_179 == V_165 )
F_122 ( V_1 , V_1 -> V_180 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_165 ; V_42 ++ ) {
for ( V_179 = 0 ; V_179 < V_1 -> V_165 ; V_179 ++ )
if ( F_121 ( V_180 [ V_42 ] ,
V_1 -> V_180 [ V_179 ] ) == 0 )
break;
if ( V_179 == V_1 -> V_165 )
F_123 ( V_1 , V_180 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_165 ; V_42 ++ )
memcpy ( V_1 -> V_180 [ V_42 ] , V_180 [ V_42 ] , V_178 ) ;
V_1 -> V_165 = V_165 ;
}
static void F_127 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
int V_182 = 1 ;
int V_155 = ( V_12 -> V_136 & V_183 ) ? 1 : 0 ;
int V_184 = ( V_12 -> V_136 & V_185 ) ? 1 : 0 ;
int V_186 = ( V_12 -> V_136 & V_187 ) ||
F_125 ( V_12 ) > V_181 ;
int V_188 = ( V_12 -> V_136 & V_189 ) ||
F_119 ( V_12 ) > V_177 ;
unsigned int V_136 = V_12 -> V_136 |
( V_188 ? V_189 : 0 ) |
( V_186 ? V_187 : 0 ) ;
if ( V_1 -> V_136 != V_136 ) {
V_1 -> V_136 = V_136 ;
F_128 ( V_1 , V_182 ,
V_155 , V_184 , V_186 , V_188 ) ;
}
if ( ! V_186 ) {
F_124 ( V_1 ) ;
if ( ! V_188 )
F_118 ( V_1 ) ;
}
}
static void F_129 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
F_54 ( & V_1 -> V_100 ) ;
}
static int F_130 ( struct V_11 * V_12 , int V_190 , T_2 * V_191 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
if ( V_190 != V_192 )
return - V_51 ;
if ( F_111 ( V_191 ) ) {
memcpy ( V_1 -> V_193 . V_194 , V_191 , V_178 ) ;
return 0 ;
} else
return - V_66 ;
}
static int F_131 ( struct V_11 * V_12 , int V_190 ,
struct V_195 * V_21 [] )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_196 V_197 ;
int V_173 = 0 , V_198 = 1 ;
if ( V_190 != V_192 )
return - V_51 ;
if ( ! V_21 [ V_199 ] )
return - V_51 ;
memcpy ( & V_197 , & V_1 -> V_193 , sizeof( V_1 -> V_193 ) ) ;
memset ( & V_1 -> V_193 , 0 , sizeof( V_1 -> V_193 ) ) ;
V_1 -> V_193 . V_200 |= V_201 ;
V_1 -> V_193 . V_202 = F_132 ( V_21 [ V_199 ] ) ;
if ( V_21 [ V_203 ] ) {
V_1 -> V_193 . V_200 |= V_204 ;
memcpy ( V_1 -> V_193 . V_46 , F_133 ( V_21 [ V_203 ] ) ,
V_205 ) ;
}
if ( V_21 [ V_206 ] ) {
V_1 -> V_193 . V_200 |= V_207 ;
memcpy ( V_1 -> V_193 . V_208 ,
F_133 ( V_21 [ V_206 ] ) , V_209 ) ;
}
if ( V_21 [ V_210 ] ) {
V_1 -> V_193 . V_200 |= V_211 ;
memcpy ( V_1 -> V_193 . V_212 ,
F_133 ( V_21 [ V_210 ] ) , V_209 ) ;
}
if ( ! F_112 ( V_197 . V_194 ) )
memcpy ( V_1 -> V_193 . V_213 , V_197 . V_194 , V_178 ) ;
if ( F_112 ( V_12 -> V_168 ) )
F_134 ( V_12 -> V_168 ) ;
V_173 = F_135 ( V_1 , & V_197 , & V_198 ) ;
if ( V_173 ) {
if ( V_198 ) {
memcpy ( & V_1 -> V_193 , & V_197 , sizeof( V_1 -> V_193 ) ) ;
} else {
memset ( & V_1 -> V_193 , 0 , sizeof( V_1 -> V_193 ) ) ;
memset ( V_12 -> V_168 , 0 , V_178 ) ;
}
} else {
V_1 -> V_193 . V_200 |= V_214 ;
if ( V_1 -> V_193 . V_202 == V_215 ) {
memset ( V_1 -> V_193 . V_213 , 0 , V_178 ) ;
memset ( V_12 -> V_168 , 0 , V_178 ) ;
}
}
memset ( V_1 -> V_193 . V_194 , 0 , V_178 ) ;
return V_173 ;
}
static int F_136 ( struct V_11 * V_12 , int V_190 ,
struct V_106 * V_107 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
T_4 V_216 = V_217 ;
int V_173 ;
if ( ! ( V_1 -> V_193 . V_200 & V_214 ) )
return - V_218 ;
V_173 = F_137 ( V_1 , V_1 -> V_193 . V_202 , & V_216 ) ;
if ( V_173 )
return V_173 ;
F_138 ( V_107 , V_199 , V_1 -> V_193 . V_202 ) ;
F_138 ( V_107 , V_219 , V_216 ) ;
if ( V_1 -> V_193 . V_200 & V_204 )
F_139 ( V_107 , V_203 , V_205 ,
V_1 -> V_193 . V_46 ) ;
if ( V_1 -> V_193 . V_200 & V_207 )
F_139 ( V_107 , V_206 , V_209 ,
V_1 -> V_193 . V_208 ) ;
if ( V_1 -> V_193 . V_200 & V_211 )
F_139 ( V_107 , V_210 , V_209 ,
V_1 -> V_193 . V_212 ) ;
return 0 ;
V_220:
return - V_221 ;
}
static void F_140 ( struct V_222 * V_5 , struct V_223 * V_71 )
{
struct V_1 * V_1 = F_32 ( V_5 -> V_25 ) ;
if ( ! V_71 -> V_76 )
return;
F_33 ( V_1 -> V_2 , V_71 -> V_73 ,
V_71 -> V_74 , V_224 ) ;
F_35 ( V_71 -> V_76 ) ;
}
static int F_141 ( struct V_222 * V_5 )
{
struct V_1 * V_1 = F_32 ( V_5 -> V_25 ) ;
struct V_11 * V_12 = V_1 -> V_12 ;
struct V_106 * V_107 ;
unsigned int V_74 = V_12 -> V_86 + V_225 ;
unsigned int V_226 = 0 ;
T_7 V_73 ;
V_107 = F_142 ( V_12 , V_74 ) ;
if ( ! V_107 )
return - V_227 ;
V_73 = F_84 ( V_1 -> V_2 , V_107 -> V_41 ,
V_74 , V_224 ) ;
F_143 ( V_5 , V_107 , V_226 ,
V_73 , V_74 ) ;
return 0 ;
}
static void F_144 ( struct V_222 * V_5 ,
struct V_77 * V_77 , struct V_223 * V_71 ,
int V_228 , void * V_78 )
{
struct V_1 * V_1 = F_32 ( V_5 -> V_25 ) ;
struct V_11 * V_12 = V_1 -> V_12 ;
struct V_106 * V_107 ;
T_2 type , V_229 , V_118 , V_72 , V_230 , V_231 ;
T_2 V_232 , V_233 , V_234 , V_235 , V_236 ;
T_2 V_237 , V_238 , V_239 , V_240 ;
T_2 V_241 , V_242 , V_243 , V_244 , V_245 , V_246 ;
T_2 V_247 ;
T_4 V_80 , V_81 , V_248 , V_249 , V_250 ;
T_1 V_251 ;
if ( V_228 )
return;
V_107 = V_71 -> V_76 ;
F_145 ( V_107 -> V_41 - V_252 ) ;
F_33 ( V_1 -> V_2 , V_71 -> V_73 ,
V_71 -> V_74 , V_224 ) ;
F_146 ( (struct V_253 * ) V_77 ,
& type , & V_229 , & V_80 , & V_81 ,
& V_230 , & V_232 , & V_118 , & V_72 , & V_245 ,
& V_246 , & V_251 , & V_248 ,
& V_247 , & V_231 , & V_249 , & V_250 ,
& V_233 , & V_234 , & V_235 ,
& V_236 , & V_237 , & V_238 , & V_239 ,
& V_240 , & V_241 , & V_242 , & V_243 ,
& V_244 ) ;
if ( V_247 ) {
if ( ! V_244 ) {
if ( V_248 > 0 )
V_1 -> V_160 ++ ;
else if ( V_248 == 0 )
V_1 -> V_158 ++ ;
}
F_35 ( V_107 ) ;
return;
}
if ( V_118 && V_248 > 0 ) {
F_147 ( V_107 , V_248 ) ;
V_107 -> V_123 = F_148 ( V_107 , V_12 ) ;
if ( ( V_12 -> V_254 & V_255 ) && ! V_246 ) {
V_107 -> V_256 = F_149 ( V_250 ) ;
V_107 -> V_134 = V_257 ;
}
V_107 -> V_258 = V_12 ;
if ( V_231 )
F_150 ( V_107 , V_249 ) ;
if ( V_12 -> V_254 & V_259 )
F_151 ( & V_1 -> V_102 [ V_80 ] , V_107 ) ;
else
F_152 ( V_107 ) ;
} else {
F_35 ( V_107 ) ;
}
}
static int F_153 ( struct V_79 * V_25 , struct V_77 * V_77 ,
T_2 type , T_4 V_80 , T_4 V_81 , void * V_78 )
{
struct V_1 * V_1 = F_32 ( V_25 ) ;
F_154 ( & V_1 -> V_5 [ V_80 ] , V_77 ,
V_81 , V_260 ,
F_144 , V_78 ) ;
return 0 ;
}
static int F_155 ( struct V_103 * V_102 , int V_261 )
{
struct V_11 * V_12 = V_102 -> V_258 ;
struct V_1 * V_1 = F_12 ( V_12 ) ;
unsigned int V_262 = F_2 ( V_1 , 0 ) ;
unsigned int V_263 = F_3 ( V_1 , 0 ) ;
unsigned int V_64 = F_4 () ;
unsigned int V_264 = V_261 ;
unsigned int V_104 = - 1 ;
unsigned int V_265 , V_266 , V_105 ;
int V_173 ;
V_266 = F_73 ( & V_1 -> V_8 [ V_262 ] ,
V_264 , F_153 , NULL ) ;
V_105 = F_73 ( & V_1 -> V_8 [ V_263 ] ,
V_104 , F_37 , NULL ) ;
V_265 = V_266 + V_105 ;
if ( V_265 > 0 )
F_74 ( & V_1 -> V_64 [ V_64 ] ,
V_265 ,
0 ,
0 ) ;
V_173 = F_156 ( & V_1 -> V_5 [ 0 ] , F_141 ) ;
if ( V_173 )
V_266 = V_264 ;
if ( V_266 < V_264 ) {
F_157 ( V_102 ) ;
F_64 ( & V_1 -> V_64 [ V_64 ] ) ;
}
return V_266 ;
}
static int F_158 ( struct V_103 * V_102 , int V_261 )
{
struct V_11 * V_12 = V_102 -> V_258 ;
struct V_1 * V_1 = F_12 ( V_12 ) ;
unsigned int V_5 = ( V_102 - & V_1 -> V_102 [ 0 ] ) ;
unsigned int V_8 = F_2 ( V_1 , V_5 ) ;
unsigned int V_64 = F_7 ( V_1 , V_5 ) ;
unsigned int V_267 = V_261 ;
unsigned int V_265 ;
int V_173 ;
V_265 = F_73 ( & V_1 -> V_8 [ V_8 ] ,
V_267 , F_153 , NULL ) ;
if ( V_265 > 0 )
F_74 ( & V_1 -> V_64 [ V_64 ] ,
V_265 ,
0 ,
0 ) ;
V_173 = F_156 ( & V_1 -> V_5 [ V_5 ] , F_141 ) ;
if ( V_173 )
V_265 = V_267 ;
if ( V_265 < V_267 ) {
F_157 ( V_102 ) ;
F_64 ( & V_1 -> V_64 [ V_64 ] ) ;
}
return V_265 ;
}
static void F_159 ( unsigned long V_41 )
{
struct V_1 * V_1 = (struct V_1 * ) V_41 ;
F_60 ( V_1 ) ;
F_160 ( & V_1 -> V_268 ,
F_161 ( V_269 + V_270 ) ) ;
}
static void F_162 ( struct V_1 * V_1 )
{
struct V_11 * V_12 = V_1 -> V_12 ;
unsigned int V_42 ;
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_65 :
F_163 ( V_1 -> V_2 -> V_93 , V_12 ) ;
break;
case V_67 :
F_163 ( V_1 -> V_2 -> V_93 , V_1 ) ;
break;
case V_68 :
for ( V_42 = 0 ; V_42 < F_164 ( V_1 -> V_271 ) ; V_42 ++ )
if ( V_1 -> V_271 [ V_42 ] . V_272 )
F_163 ( V_1 -> V_273 [ V_42 ] . V_274 ,
V_1 -> V_271 [ V_42 ] . V_275 ) ;
break;
default:
break;
}
}
static int F_165 ( struct V_1 * V_1 )
{
struct V_11 * V_12 = V_1 -> V_12 ;
unsigned int V_42 , V_64 ;
int V_173 = 0 ;
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_65 :
V_173 = F_166 ( V_1 -> V_2 -> V_93 , F_61 ,
V_276 , V_12 -> V_46 , V_12 ) ;
break;
case V_67 :
V_173 = F_166 ( V_1 -> V_2 -> V_93 , F_69 ,
0 , V_12 -> V_46 , V_1 ) ;
break;
case V_68 :
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
V_64 = F_7 ( V_1 , V_42 ) ;
sprintf ( V_1 -> V_271 [ V_64 ] . V_277 ,
L_12 , V_12 -> V_46 , V_42 ) ;
V_1 -> V_271 [ V_64 ] . V_278 = F_71 ;
V_1 -> V_271 [ V_64 ] . V_275 = & V_1 -> V_102 [ V_42 ] ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ ) {
V_64 = F_8 ( V_1 , V_42 ) ;
sprintf ( V_1 -> V_271 [ V_64 ] . V_277 ,
L_13 , V_12 -> V_46 , V_42 ) ;
V_1 -> V_271 [ V_64 ] . V_278 = F_72 ;
V_1 -> V_271 [ V_64 ] . V_275 = V_1 ;
}
V_64 = F_9 ( V_1 ) ;
sprintf ( V_1 -> V_271 [ V_64 ] . V_277 ,
L_14 , V_12 -> V_46 ) ;
V_1 -> V_271 [ V_64 ] . V_278 = F_75 ;
V_1 -> V_271 [ V_64 ] . V_275 = V_1 ;
V_64 = F_10 ( V_1 ) ;
sprintf ( V_1 -> V_271 [ V_64 ] . V_277 ,
L_15 , V_12 -> V_46 ) ;
V_1 -> V_271 [ V_64 ] . V_278 = F_76 ;
V_1 -> V_271 [ V_64 ] . V_275 = V_1 ;
for ( V_42 = 0 ; V_42 < F_164 ( V_1 -> V_271 ) ; V_42 ++ )
V_1 -> V_271 [ V_42 ] . V_272 = 0 ;
for ( V_42 = 0 ; V_42 < V_1 -> V_279 ; V_42 ++ ) {
V_173 = F_166 ( V_1 -> V_273 [ V_42 ] . V_274 ,
V_1 -> V_271 [ V_42 ] . V_278 , 0 ,
V_1 -> V_271 [ V_42 ] . V_277 ,
V_1 -> V_271 [ V_42 ] . V_275 ) ;
if ( V_173 ) {
F_162 ( V_1 ) ;
break;
}
V_1 -> V_271 [ V_42 ] . V_272 = 1 ;
}
break;
default:
break;
}
return V_173 ;
}
static void F_167 ( struct V_1 * V_1 )
{
unsigned int V_42 ;
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_65 :
case V_67 :
F_168 ( V_1 -> V_2 -> V_93 ) ;
break;
case V_68 :
for ( V_42 = 0 ; V_42 < V_1 -> V_279 ; V_42 ++ )
F_168 ( V_1 -> V_273 [ V_42 ] . V_274 ) ;
break;
default:
break;
}
}
static int F_169 ( struct V_1 * V_1 )
{
int V_173 ;
F_38 ( & V_1 -> V_280 ) ;
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_65 :
V_173 = F_170 ( V_1 -> V_25 ,
F_6 () ) ;
break;
case V_68 :
V_173 = F_170 ( V_1 -> V_25 ,
F_10 ( V_1 ) ) ;
break;
default:
V_173 = F_170 ( V_1 -> V_25 , - 1 ) ;
break;
}
F_43 ( & V_1 -> V_280 ) ;
return V_173 ;
}
static void F_171 ( struct V_1 * V_1 )
{
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_67 :
F_160 ( & V_1 -> V_268 , V_269 ) ;
break;
default:
break;
}
}
static int F_172 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
unsigned int V_42 ;
int V_173 ;
V_173 = F_165 ( V_1 ) ;
if ( V_173 ) {
F_46 ( V_12 , L_16 ) ;
return V_173 ;
}
V_173 = F_169 ( V_1 ) ;
if ( V_173 ) {
F_46 ( V_12 ,
L_17 ) ;
goto V_281;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
F_156 ( & V_1 -> V_5 [ V_42 ] , F_141 ) ;
if ( F_173 ( & V_1 -> V_5 [ V_42 ] ) == 0 ) {
F_46 ( V_12 , L_18 ) ;
V_173 = - V_227 ;
goto V_282;
}
}
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ )
F_174 ( & V_1 -> V_6 [ V_42 ] ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_175 ( & V_1 -> V_5 [ V_42 ] ) ;
if ( F_1 ( V_1 ) && ! F_112 ( V_1 -> V_193 . V_213 ) )
F_123 ( V_1 , V_1 -> V_193 . V_213 ) ;
else
F_116 ( V_1 ) ;
F_127 ( V_12 ) ;
F_42 ( V_12 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_176 ( & V_1 -> V_102 [ V_42 ] ) ;
F_177 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_279 ; V_42 ++ )
F_64 ( & V_1 -> V_64 [ V_42 ] ) ;
F_171 ( V_1 ) ;
return 0 ;
V_282:
F_178 ( V_1 ) ;
V_281:
F_162 ( V_1 ) ;
return V_173 ;
}
static int F_179 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
unsigned int V_42 ;
int V_173 ;
for ( V_42 = 0 ; V_42 < V_1 -> V_279 ; V_42 ++ ) {
F_62 ( & V_1 -> V_64 [ V_42 ] ) ;
( void ) F_180 ( & V_1 -> V_64 [ V_42 ] ) ;
}
F_167 ( V_1 ) ;
F_181 ( & V_1 -> V_268 ) ;
F_182 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_183 ( & V_1 -> V_102 [ V_42 ] ) ;
F_59 ( V_12 ) ;
F_184 ( V_12 ) ;
if ( F_1 ( V_1 ) && ! F_112 ( V_1 -> V_193 . V_213 ) )
F_122 ( V_1 , V_1 -> V_193 . V_213 ) ;
else
F_115 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ ) {
V_173 = F_185 ( & V_1 -> V_6 [ V_42 ] ) ;
if ( V_173 )
return V_173 ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
V_173 = F_186 ( & V_1 -> V_5 [ V_42 ] ) ;
if ( V_173 )
return V_173 ;
}
F_178 ( V_1 ) ;
F_162 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ )
F_187 ( & V_1 -> V_6 [ V_42 ] , F_31 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_188 ( & V_1 -> V_5 [ V_42 ] , F_140 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_283 ; V_42 ++ )
F_189 ( & V_1 -> V_8 [ V_42 ] ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_279 ; V_42 ++ )
F_190 ( & V_1 -> V_64 [ V_42 ] ) ;
return 0 ;
}
static int F_191 ( struct V_11 * V_12 , int V_284 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
int V_285 = F_114 ( V_12 ) ;
if ( V_284 < V_88 || V_284 > V_89 )
return - V_66 ;
if ( F_1 ( V_1 ) )
return - V_51 ;
if ( V_285 )
F_179 ( V_12 ) ;
V_12 -> V_86 = V_284 ;
if ( V_12 -> V_86 > V_1 -> V_87 )
F_55 ( V_12 ,
L_19 ,
V_12 -> V_86 , V_1 -> V_87 ) ;
if ( V_285 )
F_172 ( V_12 ) ;
return 0 ;
}
static void F_192 ( struct V_286 * V_287 )
{
struct V_1 * V_1 = F_193 ( V_287 , struct V_1 , V_90 ) ;
struct V_11 * V_12 = V_1 -> V_12 ;
int V_284 = F_52 ( V_1 -> V_25 ) ;
int V_173 ;
unsigned int V_42 ;
V_284 = F_53 ( int , V_88 , F_27 ( int , V_89 , V_284 ) ) ;
F_194 () ;
F_181 ( & V_1 -> V_268 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_183 ( & V_1 -> V_102 [ V_42 ] ) ;
F_62 ( & V_1 -> V_64 [ 0 ] ) ;
F_167 ( V_1 ) ;
V_173 = F_186 ( & V_1 -> V_5 [ 0 ] ) ;
if ( V_173 ) {
F_46 ( V_12 , L_20 ) ;
return;
}
F_188 ( & V_1 -> V_5 [ 0 ] , F_140 ) ;
F_189 ( & V_1 -> V_8 [ 0 ] ) ;
F_190 ( & V_1 -> V_64 [ 0 ] ) ;
V_12 -> V_86 = V_284 ;
F_156 ( & V_1 -> V_5 [ 0 ] , F_141 ) ;
if ( F_173 ( & V_1 -> V_5 [ 0 ] ) == 0 ) {
F_46 ( V_12 , L_21 ) ;
return;
}
F_175 ( & V_1 -> V_5 [ 0 ] ) ;
F_176 ( & V_1 -> V_102 [ 0 ] ) ;
F_64 ( & V_1 -> V_64 [ 0 ] ) ;
F_171 ( V_1 ) ;
F_195 () ;
F_50 ( V_12 , L_22 , V_12 -> V_86 ) ;
}
static void F_196 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
struct V_79 * V_25 = V_1 -> V_25 ;
unsigned int V_42 , V_64 ;
switch ( F_29 ( V_25 ) ) {
case V_68 :
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ ) {
V_64 = F_7 ( V_1 , V_42 ) ;
F_71 ( V_1 -> V_273 [ V_64 ] . V_274 ,
& V_1 -> V_102 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ ) {
V_64 = F_8 ( V_1 , V_42 ) ;
F_72 ( V_1 -> V_273 [ V_64 ] . V_274 , V_1 ) ;
}
break;
case V_67 :
F_69 ( V_1 -> V_2 -> V_93 , V_1 ) ;
break;
case V_65 :
F_61 ( V_1 -> V_2 -> V_93 , V_12 ) ;
break;
default:
break;
}
}
static int F_197 ( struct V_79 * V_25 ,
int (* F_198)( struct V_79 * , int ) ,
int (* F_199)( struct V_79 * , int * ) ,
int V_288 )
{
unsigned long time ;
int V_289 ;
int V_173 ;
F_200 ( F_201 () ) ;
V_173 = F_198 ( V_25 , V_288 ) ;
if ( V_173 )
return V_173 ;
time = V_269 + ( V_290 * 2 ) ;
do {
V_173 = F_199 ( V_25 , & V_289 ) ;
if ( V_173 )
return V_173 ;
if ( V_289 )
return 0 ;
F_202 ( V_290 / 10 ) ;
} while ( F_203 ( time , V_269 ) );
return - V_291 ;
}
static int F_204 ( struct V_1 * V_1 )
{
int V_173 ;
V_173 = F_197 ( V_1 -> V_25 , V_292 ,
V_293 , 0 ) ;
if ( V_173 )
F_205 ( F_206 ( V_1 ) , L_23 ,
V_173 ) ;
return V_173 ;
}
static int F_207 ( struct V_1 * V_1 )
{
int V_173 ;
V_173 = F_197 ( V_1 -> V_25 , V_294 ,
V_295 , 0 ) ;
if ( V_173 )
F_46 ( V_1 -> V_12 , L_24 ,
V_173 ) ;
return V_173 ;
}
static int F_208 ( struct V_1 * V_1 )
{
T_7 V_296 ;
union V_297 * V_298 = NULL ;
union V_297 V_299 = {
. V_300 [ 0 ] . V_301 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_300 [ 1 ] . V_301 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_300 [ 2 ] . V_301 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_300 [ 3 ] . V_301 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_173 ;
V_298 = F_209 ( V_1 -> V_2 ,
sizeof( union V_297 ) , & V_296 ) ;
if ( ! V_298 )
return - V_227 ;
memcpy ( V_298 , & V_299 , sizeof( union V_297 ) ) ;
F_38 ( & V_1 -> V_280 ) ;
V_173 = F_210 ( V_1 ,
V_296 ,
sizeof( union V_297 ) ) ;
F_43 ( & V_1 -> V_280 ) ;
F_211 ( V_1 -> V_2 , sizeof( union V_297 ) ,
V_298 , V_296 ) ;
return V_173 ;
}
static int F_212 ( struct V_1 * V_1 , T_2 V_302 )
{
T_7 V_303 ;
union V_304 * V_305 = NULL ;
unsigned int V_42 ;
int V_173 ;
V_305 = F_209 ( V_1 -> V_2 ,
sizeof( union V_304 ) , & V_303 ) ;
if ( ! V_305 )
return - V_227 ;
for ( V_42 = 0 ; V_42 < ( 1 << V_302 ) ; V_42 ++ )
( * V_305 ) . V_306 [ V_42 / 4 ] . V_301 [ V_42 % 4 ] = V_42 % V_1 -> V_7 ;
F_38 ( & V_1 -> V_280 ) ;
V_173 = F_213 ( V_1 ,
V_303 ,
sizeof( union V_304 ) ) ;
F_43 ( & V_1 -> V_280 ) ;
F_211 ( V_1 -> V_2 , sizeof( union V_304 ) ,
V_305 , V_303 ) ;
return V_173 ;
}
static int F_214 ( struct V_1 * V_1 , T_2 V_307 ,
T_2 V_308 , T_2 V_302 , T_2 V_309 , T_2 V_310 )
{
const T_2 V_311 = 0 ;
const T_2 V_312 = 1 ;
int V_173 ;
F_38 ( & V_1 -> V_280 ) ;
V_173 = F_215 ( V_1 ,
V_307 , V_308 ,
V_302 , V_309 ,
V_310 , V_311 ,
V_312 ) ;
F_43 ( & V_1 -> V_280 ) ;
return V_173 ;
}
static int F_216 ( struct V_1 * V_1 )
{
struct V_3 * V_258 = F_206 ( V_1 ) ;
const T_2 V_307 = 0 ;
const T_2 V_308 = V_313 |
V_314 |
V_315 |
V_316 ;
const T_2 V_302 = 7 ;
const T_2 V_309 = 0 ;
T_2 V_310 = F_217 ( V_1 , V_317 ) && ( V_1 -> V_7 > 1 ) ;
if ( V_310 ) {
if ( ! F_208 ( V_1 ) ) {
if ( F_212 ( V_1 , V_302 ) ) {
V_310 = 0 ;
F_218 ( V_258 , L_25
L_26 ) ;
}
} else {
V_310 = 0 ;
F_218 ( V_258 , L_27 ) ;
}
}
return F_214 ( V_1 , V_307 , V_308 ,
V_302 , V_309 , V_310 ) ;
}
static void F_219 ( struct V_286 * V_287 )
{
struct V_1 * V_1 = F_193 ( V_287 , struct V_1 , V_100 ) ;
if ( ! F_114 ( V_1 -> V_12 ) )
return;
F_194 () ;
F_220 ( V_1 ) ;
F_179 ( V_1 -> V_12 ) ;
F_207 ( V_1 ) ;
F_109 ( V_1 ) ;
F_221 ( V_1 ) ;
F_216 ( V_1 ) ;
F_222 ( V_1 ) ;
F_172 ( V_1 -> V_12 ) ;
F_195 () ;
}
static int F_223 ( struct V_1 * V_1 )
{
unsigned int V_318 = F_27 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_319 = F_27 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_42 ;
F_200 ( F_164 ( V_1 -> V_273 ) < V_318 + V_319 + 2 ) ;
for ( V_42 = 0 ; V_42 < V_318 + V_319 + 2 ; V_42 ++ )
V_1 -> V_273 [ V_42 ] . V_320 = V_42 ;
if ( F_217 ( V_1 , V_317 ) &&
V_1 -> V_321 . V_322 < 1 &&
V_1 -> V_7 >= V_318 &&
V_1 -> V_10 >= V_319 &&
V_1 -> V_283 >= V_318 + V_319 &&
V_1 -> V_279 >= V_318 + V_319 + 2 ) {
if ( ! F_224 ( V_1 -> V_2 , V_1 -> V_273 , V_318 + V_319 + 2 ) ) {
V_1 -> V_7 = V_318 ;
V_1 -> V_10 = V_319 ;
V_1 -> V_283 = V_318 + V_319 ;
V_1 -> V_279 = V_318 + V_319 + 2 ;
F_225 ( V_1 -> V_25 ,
V_68 ) ;
return 0 ;
}
}
if ( V_1 -> V_321 . V_322 < 1 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_10 >= V_319 &&
V_1 -> V_283 >= 1 + V_319 &&
V_1 -> V_279 >= 1 + V_319 + 2 ) {
if ( ! F_224 ( V_1 -> V_2 , V_1 -> V_273 , 1 + V_319 + 2 ) ) {
V_1 -> V_7 = 1 ;
V_1 -> V_10 = V_319 ;
V_1 -> V_283 = 1 + V_319 ;
V_1 -> V_279 = 1 + V_319 + 2 ;
F_225 ( V_1 -> V_25 ,
V_68 ) ;
return 0 ;
}
}
if ( V_1 -> V_321 . V_322 < 2 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_10 >= 1 &&
V_1 -> V_283 >= 2 &&
V_1 -> V_279 >= 1 &&
! F_226 ( V_1 -> V_2 ) ) {
V_1 -> V_7 = 1 ;
V_1 -> V_10 = 1 ;
V_1 -> V_283 = 2 ;
V_1 -> V_279 = 1 ;
F_225 ( V_1 -> V_25 , V_67 ) ;
return 0 ;
}
if ( V_1 -> V_321 . V_322 < 3 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_10 >= 1 &&
V_1 -> V_283 >= 2 &&
V_1 -> V_279 >= 3 ) {
V_1 -> V_7 = 1 ;
V_1 -> V_10 = 1 ;
V_1 -> V_283 = 2 ;
V_1 -> V_279 = 3 ;
F_225 ( V_1 -> V_25 , V_65 ) ;
return 0 ;
}
F_225 ( V_1 -> V_25 , V_323 ) ;
return - V_66 ;
}
static void F_227 ( struct V_1 * V_1 )
{
switch ( F_29 ( V_1 -> V_25 ) ) {
case V_68 :
F_228 ( V_1 -> V_2 ) ;
break;
case V_67 :
F_229 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_225 ( V_1 -> V_25 , V_323 ) ;
}
static void F_230 ( struct V_1 * V_1 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_231 ( & V_1 -> V_102 [ V_42 ] ) ;
F_232 ( V_1 ) ;
F_227 ( V_1 ) ;
}
static int F_233 ( struct V_1 * V_1 )
{
struct V_3 * V_258 = F_206 ( V_1 ) ;
struct V_11 * V_12 = V_1 -> V_12 ;
unsigned int V_42 ;
int V_173 ;
V_173 = F_234 ( V_1 ) ;
if ( V_173 ) {
F_218 ( V_258 , L_28
L_29 ) ;
F_235 ( V_1 -> V_25 ) ;
}
V_173 = F_236 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_30 ) ;
return V_173 ;
}
F_237 ( V_1 ) ;
V_173 = F_223 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_31
L_32 ) ;
return V_173 ;
}
V_173 = F_238 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_33 ) ;
goto V_324;
}
F_221 ( V_1 ) ;
V_173 = F_216 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_34 ) ;
goto V_324;
}
switch ( F_29 ( V_1 -> V_25 ) ) {
default:
F_239 ( V_12 , & V_1 -> V_102 [ 0 ] , F_155 , 64 ) ;
break;
case V_68 :
for ( V_42 = 0 ; V_42 < V_1 -> V_7 ; V_42 ++ )
F_239 ( V_12 , & V_1 -> V_102 [ V_42 ] ,
F_158 , 64 ) ;
break;
}
return 0 ;
V_324:
F_227 ( V_1 ) ;
F_232 ( V_1 ) ;
return V_173 ;
}
static void F_240 ( struct V_1 * V_1 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < F_164 ( V_1 -> V_325 ) ; V_42 ++ )
if ( V_1 -> V_325 [ V_42 ] . V_326 )
F_241 ( V_1 -> V_325 [ V_42 ] . V_326 ) ;
}
static int T_9 F_242 ( struct V_327 * V_2 ,
const struct V_328 * V_329 )
{
struct V_3 * V_258 = & V_2 -> V_258 ;
struct V_11 * V_12 ;
struct V_1 * V_1 ;
int V_330 = 0 ;
unsigned int V_42 ;
int V_173 ;
V_12 = F_243 ( sizeof( struct V_1 ) ) ;
if ( ! V_12 ) {
F_244 ( L_35 ) ;
return - V_227 ;
}
F_245 ( V_2 , V_12 ) ;
F_246 ( V_12 , & V_2 -> V_258 ) ;
V_1 = F_12 ( V_12 ) ;
V_1 -> V_12 = V_12 ;
V_1 -> V_2 = V_2 ;
V_173 = F_247 ( V_2 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_36 ) ;
goto V_331;
}
V_173 = F_248 ( V_2 , V_35 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_37 ) ;
goto V_332;
}
F_249 ( V_2 ) ;
V_173 = F_250 ( V_2 , F_251 ( 40 ) ) ;
if ( V_173 ) {
V_173 = F_250 ( V_2 , F_251 ( 32 ) ) ;
if ( V_173 ) {
F_205 ( V_258 , L_38 ) ;
goto V_333;
}
V_173 = F_252 ( V_2 , F_251 ( 32 ) ) ;
if ( V_173 ) {
F_205 ( V_258 , L_39
L_40 , 32 ) ;
goto V_333;
}
} else {
V_173 = F_252 ( V_2 , F_251 ( 40 ) ) ;
if ( V_173 ) {
F_205 ( V_258 , L_39
L_40 , 40 ) ;
goto V_333;
}
V_330 = 1 ;
}
for ( V_42 = 0 ; V_42 < F_164 ( V_1 -> V_325 ) ; V_42 ++ ) {
if ( ! ( F_253 ( V_2 , V_42 ) & V_334 ) )
continue;
V_1 -> V_325 [ V_42 ] . V_74 = F_254 ( V_2 , V_42 ) ;
V_1 -> V_325 [ V_42 ] . V_326 = F_255 ( V_2 , V_42 , V_1 -> V_325 [ V_42 ] . V_74 ) ;
if ( ! V_1 -> V_325 [ V_42 ] . V_326 ) {
F_205 ( V_258 , L_41 , V_42 ) ;
V_173 = - V_335 ;
goto V_336;
}
V_1 -> V_325 [ V_42 ] . V_337 = F_256 ( V_2 , V_42 ) ;
}
V_1 -> V_25 = F_257 ( NULL , V_1 , V_2 , V_1 -> V_325 ,
F_164 ( V_1 -> V_325 ) ) ;
if ( ! V_1 -> V_25 ) {
F_205 ( V_258 , L_42 ) ;
V_173 = - V_335 ;
goto V_336;
}
V_173 = F_204 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_43 ) ;
goto V_338;
}
F_258 ( & V_1 -> V_280 ) ;
V_173 = F_222 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 ,
L_44 ) ;
goto V_339;
}
F_59 ( V_12 ) ;
if ( ! F_1 ( V_1 ) ) {
V_173 = F_259 ( V_1 -> V_25 , 0 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_45 ) ;
goto V_339;
}
}
V_173 = F_233 ( V_1 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_46 ) ;
goto V_339;
}
F_260 ( & V_1 -> V_268 ) ;
V_1 -> V_268 . V_340 = F_159 ;
V_1 -> V_268 . V_41 = ( unsigned long ) V_1 ;
F_261 ( & V_1 -> V_100 , F_219 ) ;
F_261 ( & V_1 -> V_90 , F_192 ) ;
for ( V_42 = 0 ; V_42 < V_1 -> V_10 ; V_42 ++ )
F_258 ( & V_1 -> V_82 [ V_42 ] ) ;
V_1 -> V_87 = V_1 -> V_321 . V_86 ;
( void ) F_191 ( V_12 , V_1 -> V_87 ) ;
V_173 = F_110 ( V_12 , V_1 -> V_213 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_47 ) ;
goto V_341;
}
V_1 -> V_62 = V_1 -> V_321 . V_342 ;
V_1 -> V_63 = V_1 -> V_62 ;
if ( F_1 ( V_1 ) )
V_12 -> V_343 = & V_344 ;
else
V_12 -> V_343 = & V_345 ;
V_12 -> V_346 = 2 * V_290 ;
V_12 -> V_347 = & V_348 ;
V_12 -> V_254 |= V_349 | V_350 ;
if ( F_217 ( V_1 , V_351 ) ) {
V_12 -> V_254 &= ~ V_349 ;
V_1 -> V_132 = 1 ;
V_1 -> V_133 = V_1 -> V_321 . V_133 ;
F_262 ( V_258 , L_48 , V_1 -> V_133 ) ;
}
if ( F_217 ( V_1 , V_352 ) )
V_12 -> V_353 |= V_354 | V_355 ;
if ( F_217 ( V_1 , V_356 ) )
V_12 -> V_353 |= V_357 |
V_358 | V_359 ;
if ( F_217 ( V_1 , V_360 ) )
V_12 -> V_353 |= V_255 ;
V_12 -> V_254 |= V_12 -> V_353 ;
if ( V_330 )
V_12 -> V_254 |= V_361 ;
V_173 = F_263 ( V_12 ) ;
if ( V_173 ) {
F_205 ( V_258 , L_49 ) ;
goto V_341;
}
return 0 ;
V_341:
F_230 ( V_1 ) ;
V_339:
F_264 ( V_1 -> V_25 ) ;
V_338:
F_265 ( V_1 -> V_25 ) ;
V_336:
F_240 ( V_1 ) ;
V_333:
F_266 ( V_2 ) ;
V_332:
F_267 ( V_2 ) ;
V_331:
F_245 ( V_2 , NULL ) ;
F_268 ( V_12 ) ;
return V_173 ;
}
static void T_10 F_269 ( struct V_327 * V_2 )
{
struct V_11 * V_12 = F_270 ( V_2 ) ;
if ( V_12 ) {
struct V_1 * V_1 = F_12 ( V_12 ) ;
F_271 ( & V_1 -> V_100 ) ;
F_271 ( & V_1 -> V_90 ) ;
F_272 ( V_12 ) ;
F_230 ( V_1 ) ;
F_264 ( V_1 -> V_25 ) ;
F_265 ( V_1 -> V_25 ) ;
F_240 ( V_1 ) ;
F_266 ( V_2 ) ;
F_267 ( V_2 ) ;
F_245 ( V_2 , NULL ) ;
F_268 ( V_12 ) ;
}
}
static int T_11 F_273 ( void )
{
F_274 ( L_50 , V_362 , V_37 ) ;
return F_275 ( & V_363 ) ;
}
static void T_12 F_276 ( void )
{
F_277 ( & V_363 ) ;
}
