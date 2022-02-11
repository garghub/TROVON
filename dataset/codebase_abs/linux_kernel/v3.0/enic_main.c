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
return V_5 ;
}
static inline unsigned int F_8 ( struct V_1 * V_1 , unsigned int V_6 )
{
return V_1 -> V_7 + V_6 ;
}
static inline unsigned int F_9 ( struct V_1 * V_1 )
{
return V_1 -> V_7 + V_1 -> V_8 ;
}
static inline unsigned int F_10 ( struct V_1 * V_1 )
{
return V_1 -> V_7 + V_1 -> V_8 + 1 ;
}
static int F_11 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
V_12 -> V_13 = ( V_14 | V_15 ) ;
V_12 -> V_16 = ( V_17 | V_18 ) ;
V_12 -> V_19 = V_20 ;
V_12 -> V_21 = V_22 ;
if ( F_13 ( V_10 ) ) {
F_14 ( V_12 , F_15 ( V_1 -> V_23 ) ) ;
V_12 -> V_24 = V_25 ;
} else {
F_14 ( V_12 , - 1 ) ;
V_12 -> V_24 = - 1 ;
}
V_12 -> V_26 = V_27 ;
return 0 ;
}
static void F_16 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_30 * V_31 ;
F_17 ( V_1 , & V_31 ) ;
strncpy ( V_29 -> V_32 , V_33 , sizeof( V_29 -> V_32 ) ) ;
strncpy ( V_29 -> V_34 , V_35 , sizeof( V_29 -> V_34 ) ) ;
strncpy ( V_29 -> V_36 , V_31 -> V_36 ,
sizeof( V_29 -> V_36 ) ) ;
strncpy ( V_29 -> V_37 , F_18 ( V_1 -> V_2 ) ,
sizeof( V_29 -> V_37 ) ) ;
}
static void F_19 ( struct V_9 * V_10 , T_1 V_38 , T_2 * V_39 )
{
unsigned int V_40 ;
switch ( V_38 ) {
case V_41 :
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ ) {
memcpy ( V_39 , V_43 [ V_40 ] . V_44 , V_45 ) ;
V_39 += V_45 ;
}
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
memcpy ( V_39 , V_47 [ V_40 ] . V_44 , V_45 ) ;
V_39 += V_45 ;
}
break;
}
}
static int F_20 ( struct V_9 * V_10 , int V_48 )
{
switch ( V_48 ) {
case V_41 :
return V_42 + V_46 ;
default:
return - V_49 ;
}
}
static void F_21 ( struct V_9 * V_10 ,
struct V_50 * V_51 , T_3 * V_39 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_52 * V_53 ;
unsigned int V_40 ;
F_22 ( V_1 , & V_53 ) ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_53 -> V_54 ) [ V_43 [ V_40 ] . V_55 ] ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_53 -> V_56 ) [ V_47 [ V_40 ] . V_55 ] ;
}
static T_1 F_23 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
return V_1 -> V_57 ;
}
static void F_24 ( struct V_9 * V_10 , T_1 V_58 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
V_1 -> V_57 = V_58 ;
}
static int F_25 ( struct V_9 * V_10 ,
struct V_59 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
V_12 -> V_60 = V_1 -> V_60 ;
V_12 -> V_61 = V_1 -> V_61 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_59 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
T_1 V_60 ;
T_1 V_61 ;
unsigned int V_40 , V_62 ;
V_60 = F_27 ( T_1 ,
F_28 ( V_63 ) ,
V_12 -> V_60 ) ;
V_61 = F_27 ( T_1 ,
F_28 ( V_63 ) ,
V_12 -> V_61 ) ;
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_64 :
if ( V_60 != V_61 )
return - V_65 ;
V_62 = F_4 () ;
F_30 ( & V_1 -> V_62 [ V_62 ] ,
F_31 ( V_60 ) ) ;
break;
case V_66 :
if ( V_60 != V_61 )
return - V_65 ;
F_30 ( & V_1 -> V_62 [ 0 ] ,
F_31 ( V_60 ) ) ;
break;
case V_67 :
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ ) {
V_62 = F_8 ( V_1 , V_40 ) ;
F_30 ( & V_1 -> V_62 [ V_62 ] ,
F_31 ( V_60 ) ) ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
V_62 = F_7 ( V_1 , V_40 ) ;
F_30 ( & V_1 -> V_62 [ V_62 ] ,
F_31 ( V_61 ) ) ;
}
break;
default:
break;
}
V_1 -> V_60 = V_60 ;
V_1 -> V_61 = V_61 ;
return 0 ;
}
static void F_32 ( struct V_68 * V_6 , struct V_69 * V_70 )
{
struct V_1 * V_1 = F_33 ( V_6 -> V_23 ) ;
if ( V_70 -> V_71 )
F_34 ( V_1 -> V_2 , V_70 -> V_72 ,
V_70 -> V_73 , V_74 ) ;
else
F_35 ( V_1 -> V_2 , V_70 -> V_72 ,
V_70 -> V_73 , V_74 ) ;
if ( V_70 -> V_75 )
F_36 ( V_70 -> V_75 ) ;
}
static void F_37 ( struct V_68 * V_6 ,
struct V_76 * V_76 , struct V_69 * V_70 , void * V_77 )
{
F_32 ( V_6 , V_70 ) ;
}
static int F_38 ( struct V_78 * V_23 , struct V_76 * V_76 ,
T_2 type , T_4 V_79 , T_4 V_80 , void * V_77 )
{
struct V_1 * V_1 = F_33 ( V_23 ) ;
F_39 ( & V_1 -> V_81 [ V_79 ] ) ;
F_40 ( & V_1 -> V_6 [ V_79 ] , V_76 ,
V_80 , F_37 ,
V_77 ) ;
if ( F_41 ( V_1 -> V_10 ) &&
F_42 ( & V_1 -> V_6 [ V_79 ] ) >=
( V_82 + V_83 ) )
F_43 ( V_1 -> V_10 ) ;
F_44 ( & V_1 -> V_81 [ V_79 ] ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_1 )
{
unsigned int V_40 ;
T_1 V_84 ;
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ ) {
V_84 = F_46 ( & V_1 -> V_6 [ V_40 ] ) ;
if ( V_84 )
F_47 ( V_1 -> V_10 , L_1 ,
V_40 , V_84 ) ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
V_84 = F_48 ( & V_1 -> V_5 [ V_40 ] ) ;
if ( V_84 )
F_47 ( V_1 -> V_10 , L_2 ,
V_40 , V_84 ) ;
}
}
static void F_49 ( struct V_1 * V_1 )
{
T_1 V_57 = F_50 ( V_1 -> V_23 ) ;
if ( V_57 != V_1 -> V_57 ) {
F_51 ( V_1 -> V_10 , L_3 ,
V_1 -> V_57 , V_57 ) ;
V_1 -> V_57 = V_57 ;
}
}
static void F_52 ( struct V_1 * V_1 )
{
T_1 V_85 = F_53 ( V_1 -> V_23 ) ;
struct V_9 * V_10 = V_1 -> V_10 ;
if ( V_85 && V_85 != V_1 -> V_86 ) {
V_1 -> V_86 = V_85 ;
if ( V_85 < V_10 -> V_85 )
F_54 ( V_10 ,
L_4
L_5 ,
V_10 -> V_85 , V_85 ) ;
}
}
static void F_55 ( struct V_1 * V_1 )
{
int V_87 = F_56 ( V_1 -> V_23 ) ;
int V_88 = F_13 ( V_1 -> V_10 ) ;
if ( V_87 && ! V_88 ) {
F_51 ( V_1 -> V_10 , L_6 ) ;
F_57 ( V_1 -> V_10 ) ;
} else if ( ! V_87 && V_88 ) {
F_51 ( V_1 -> V_10 , L_7 ) ;
F_58 ( V_1 -> V_10 ) ;
}
}
static void F_59 ( struct V_1 * V_1 )
{
F_49 ( V_1 ) ;
F_52 ( V_1 ) ;
F_55 ( V_1 ) ;
}
static T_5 F_60 ( int V_89 , void * V_39 )
{
struct V_9 * V_10 = V_39 ;
struct V_1 * V_1 = F_12 ( V_10 ) ;
unsigned int V_90 = F_4 () ;
unsigned int V_91 = F_5 () ;
unsigned int V_92 = F_6 () ;
T_1 V_93 ;
F_61 ( & V_1 -> V_62 [ V_90 ] ) ;
V_93 = F_62 ( V_1 -> V_94 ) ;
if ( ! V_93 ) {
F_63 ( & V_1 -> V_62 [ V_90 ] ) ;
return V_95 ;
}
if ( F_64 ( V_93 , V_92 ) ) {
F_65 ( & V_1 -> V_62 [ V_92 ] ) ;
F_59 ( V_1 ) ;
}
if ( F_64 ( V_93 , V_91 ) ) {
F_65 ( & V_1 -> V_62 [ V_91 ] ) ;
F_45 ( V_1 ) ;
F_66 ( & V_1 -> V_96 ) ;
return V_97 ;
}
if ( F_64 ( V_93 , V_90 ) ) {
if ( F_67 ( & V_1 -> V_98 [ 0 ] ) )
F_68 ( & V_1 -> V_98 [ 0 ] ) ;
} else {
F_63 ( & V_1 -> V_62 [ V_90 ] ) ;
}
return V_97 ;
}
static T_5 F_69 ( int V_89 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
F_70 ( & V_1 -> V_98 [ 0 ] ) ;
return V_97 ;
}
static T_5 F_71 ( int V_89 , void * V_39 )
{
struct V_99 * V_98 = V_39 ;
F_70 ( V_98 ) ;
return V_97 ;
}
static T_5 F_72 ( int V_89 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
unsigned int V_100 = F_3 ( V_1 , 0 ) ;
unsigned int V_62 = F_8 ( V_1 , 0 ) ;
unsigned int V_101 = - 1 ;
unsigned int V_102 ;
V_102 = F_73 ( & V_1 -> V_100 [ V_100 ] ,
V_101 , F_38 , NULL ) ;
F_74 ( & V_1 -> V_62 [ V_62 ] ,
V_102 ,
1 ,
1 ) ;
return V_97 ;
}
static T_5 F_75 ( int V_89 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
unsigned int V_62 = F_9 ( V_1 ) ;
F_65 ( & V_1 -> V_62 [ V_62 ] ) ;
F_45 ( V_1 ) ;
F_66 ( & V_1 -> V_96 ) ;
return V_97 ;
}
static T_5 F_76 ( int V_89 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
unsigned int V_62 = F_10 ( V_1 ) ;
F_65 ( & V_1 -> V_62 [ V_62 ] ) ;
F_59 ( V_1 ) ;
return V_97 ;
}
static inline void F_77 ( struct V_1 * V_1 ,
struct V_68 * V_6 , struct V_103 * V_104 ,
unsigned int V_105 , int V_106 )
{
T_6 * V_107 ;
for ( V_107 = F_78 ( V_104 ) -> V_108 ; V_105 ; V_107 ++ ) {
V_105 -= V_107 -> V_109 ;
F_79 ( V_6 , V_104 ,
F_80 ( V_1 -> V_2 , V_107 -> V_110 ,
V_107 -> V_111 , V_107 -> V_109 ,
V_74 ) ,
V_107 -> V_109 ,
( V_105 == 0 ) ,
V_106 ) ;
}
}
static inline void F_81 ( struct V_1 * V_1 ,
struct V_68 * V_6 , struct V_103 * V_104 ,
int V_112 , unsigned int V_113 , int V_106 )
{
unsigned int V_114 = F_82 ( V_104 ) ;
unsigned int V_105 = V_104 -> V_73 - V_114 ;
int V_115 = ( V_105 == 0 ) ;
F_83 ( V_6 , V_104 ,
F_84 ( V_1 -> V_2 , V_104 -> V_39 ,
V_114 , V_74 ) ,
V_114 ,
V_112 , V_113 ,
V_115 , V_106 ) ;
if ( ! V_115 )
F_77 ( V_1 , V_6 , V_104 , V_105 , V_106 ) ;
}
static inline void F_85 ( struct V_1 * V_1 ,
struct V_68 * V_6 , struct V_103 * V_104 ,
int V_112 , unsigned int V_113 , int V_106 )
{
unsigned int V_114 = F_82 ( V_104 ) ;
unsigned int V_105 = V_104 -> V_73 - V_114 ;
unsigned int V_116 = F_86 ( V_104 ) ;
unsigned int V_117 = V_116 + V_104 -> V_117 ;
int V_115 = ( V_105 == 0 ) ;
F_87 ( V_6 , V_104 ,
F_84 ( V_1 -> V_2 , V_104 -> V_39 ,
V_114 , V_74 ) ,
V_114 ,
V_117 ,
V_116 ,
V_112 , V_113 ,
V_115 , V_106 ) ;
if ( ! V_115 )
F_77 ( V_1 , V_6 , V_104 , V_105 , V_106 ) ;
}
static inline void F_88 ( struct V_1 * V_1 ,
struct V_68 * V_6 , struct V_103 * V_104 , unsigned int V_118 ,
int V_112 , unsigned int V_113 , int V_106 )
{
unsigned int V_119 = F_82 ( V_104 ) ;
unsigned int V_105 = V_104 -> V_73 - V_119 ;
unsigned int V_116 = F_89 ( V_104 ) + F_90 ( V_104 ) ;
int V_115 = ( V_105 == 0 ) ;
unsigned int V_73 ;
T_7 V_72 ;
unsigned int V_55 = 0 ;
T_6 * V_107 ;
if ( V_104 -> V_120 == F_91 ( V_121 ) ) {
F_92 ( V_104 ) -> V_122 = 0 ;
F_93 ( V_104 ) -> V_122 = ~ F_94 ( F_92 ( V_104 ) -> V_123 ,
F_92 ( V_104 ) -> V_124 , 0 , V_125 , 0 ) ;
} else if ( V_104 -> V_120 == F_91 ( V_126 ) ) {
F_93 ( V_104 ) -> V_122 = ~ F_95 ( & F_96 ( V_104 ) -> V_123 ,
& F_96 ( V_104 ) -> V_124 , 0 , V_125 , 0 ) ;
}
while ( V_119 ) {
V_73 = F_97 ( V_119 , ( unsigned int ) V_127 ) ;
V_72 = F_84 ( V_1 -> V_2 , V_104 -> V_39 + V_55 ,
V_73 , V_74 ) ;
F_98 ( V_6 , V_104 ,
V_72 ,
V_73 ,
V_118 , V_116 ,
V_112 , V_113 ,
V_115 && ( V_73 == V_119 ) , V_106 ) ;
V_119 -= V_73 ;
V_55 += V_73 ;
}
if ( V_115 )
return;
for ( V_107 = F_78 ( V_104 ) -> V_108 ; V_105 ; V_107 ++ ) {
V_105 -= V_107 -> V_109 ;
V_119 = V_107 -> V_109 ;
V_55 = V_107 -> V_111 ;
while ( V_119 ) {
V_73 = F_97 ( V_119 ,
( unsigned int ) V_127 ) ;
V_72 = F_80 ( V_1 -> V_2 , V_107 -> V_110 ,
V_55 , V_73 ,
V_74 ) ;
F_79 ( V_6 , V_104 ,
V_72 ,
V_73 ,
( V_105 == 0 ) &&
( V_73 == V_119 ) ,
V_106 ) ;
V_119 -= V_73 ;
V_55 += V_73 ;
}
}
}
static inline void F_99 ( struct V_1 * V_1 ,
struct V_68 * V_6 , struct V_103 * V_104 )
{
unsigned int V_118 = F_78 ( V_104 ) -> V_128 ;
unsigned int V_113 = 0 ;
int V_112 = 0 ;
int V_106 = 0 ;
if ( F_100 ( V_104 ) ) {
V_112 = 1 ;
V_113 = F_101 ( V_104 ) ;
} else if ( V_1 -> V_129 ) {
V_113 = V_1 -> V_130 ;
V_106 = 1 ;
}
if ( V_118 )
F_88 ( V_1 , V_6 , V_104 , V_118 ,
V_112 , V_113 , V_106 ) ;
else if ( V_104 -> V_131 == V_132 )
F_85 ( V_1 , V_6 , V_104 ,
V_112 , V_113 , V_106 ) ;
else
F_81 ( V_1 , V_6 , V_104 ,
V_112 , V_113 , V_106 ) ;
}
static T_8 F_102 ( struct V_103 * V_104 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_68 * V_6 = & V_1 -> V_6 [ 0 ] ;
unsigned long V_133 ;
if ( V_104 -> V_73 <= 0 ) {
F_103 ( V_104 ) ;
return V_134 ;
}
if ( F_78 ( V_104 ) -> V_128 == 0 &&
F_78 ( V_104 ) -> V_135 + 1 > V_136 &&
F_104 ( V_104 ) ) {
F_103 ( V_104 ) ;
return V_134 ;
}
F_105 ( & V_1 -> V_81 [ 0 ] , V_133 ) ;
if ( F_42 ( V_6 ) <
F_78 ( V_104 ) -> V_135 + V_83 ) {
F_106 ( V_10 ) ;
F_47 ( V_10 , L_8 ) ;
F_107 ( & V_1 -> V_81 [ 0 ] , V_133 ) ;
return V_137 ;
}
F_99 ( V_1 , V_6 , V_104 ) ;
if ( F_42 ( V_6 ) < V_82 + V_83 )
F_106 ( V_10 ) ;
F_107 ( & V_1 -> V_81 [ 0 ] , V_133 ) ;
return V_134 ;
}
static struct V_138 * F_108 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_138 * V_139 = & V_10 -> V_51 ;
struct V_52 * V_51 ;
F_22 ( V_1 , & V_51 ) ;
V_139 -> V_140 = V_51 -> V_54 . V_141 ;
V_139 -> V_142 = V_51 -> V_54 . V_143 ;
V_139 -> V_144 = V_51 -> V_54 . V_144 ;
V_139 -> V_145 = V_51 -> V_54 . V_146 ;
V_139 -> V_147 = V_51 -> V_56 . V_148 ;
V_139 -> V_149 = V_51 -> V_56 . V_150 ;
V_139 -> V_151 = V_51 -> V_56 . V_151 ;
V_139 -> V_152 = V_51 -> V_56 . V_153 ;
V_139 -> V_154 = V_1 -> V_155 ;
V_139 -> V_156 = V_1 -> V_157 ;
V_139 -> V_158 = V_51 -> V_56 . V_159 + V_51 -> V_56 . V_160 ;
return V_139 ;
}
void F_109 ( struct V_1 * V_1 )
{
V_1 -> V_161 = 0 ;
V_1 -> V_162 = 0 ;
V_1 -> V_133 = 0 ;
}
static int F_110 ( struct V_9 * V_10 , char * V_163 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_111 ( V_163 ) && ! F_112 ( V_163 ) )
return - V_164 ;
} else {
if ( ! F_111 ( V_163 ) )
return - V_164 ;
}
memcpy ( V_10 -> V_165 , V_163 , V_10 -> V_166 ) ;
return 0 ;
}
static int F_113 ( struct V_9 * V_10 , void * V_167 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_168 * V_123 = V_167 ;
char * V_163 = V_123 -> V_169 ;
int V_170 ;
if ( F_114 ( V_1 -> V_10 ) ) {
V_170 = F_115 ( V_1 ) ;
if ( V_170 )
return V_170 ;
}
V_170 = F_110 ( V_10 , V_163 ) ;
if ( V_170 )
return V_170 ;
if ( F_114 ( V_1 -> V_10 ) ) {
V_170 = F_116 ( V_1 ) ;
if ( V_170 )
return V_170 ;
}
return V_170 ;
}
static int F_117 ( struct V_9 * V_10 , void * V_167 )
{
struct V_168 * V_123 = V_167 ;
char * V_163 = V_123 -> V_169 ;
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_170 ;
V_170 = F_115 ( V_1 ) ;
if ( V_170 )
return V_170 ;
V_170 = F_110 ( V_10 , V_163 ) ;
if ( V_170 )
return V_170 ;
return F_116 ( V_1 ) ;
}
static void F_118 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_171 * V_172 ;
unsigned int V_161 = F_119 ( V_10 ) ;
T_2 V_173 [ V_174 ] [ V_175 ] ;
unsigned int V_40 , V_176 ;
if ( V_161 > V_174 ) {
F_54 ( V_10 , L_9
L_10 ,
V_174 , V_161 ) ;
V_161 = V_174 ;
}
V_40 = 0 ;
F_120 (ha, netdev) {
if ( V_40 == V_161 )
break;
memcpy ( V_173 [ V_40 ++ ] , V_172 -> V_163 , V_175 ) ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_161 ; V_40 ++ ) {
for ( V_176 = 0 ; V_176 < V_161 ; V_176 ++ )
if ( F_121 ( V_1 -> V_173 [ V_40 ] ,
V_173 [ V_176 ] ) == 0 )
break;
if ( V_176 == V_161 )
F_122 ( V_1 , V_1 -> V_173 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < V_161 ; V_40 ++ ) {
for ( V_176 = 0 ; V_176 < V_1 -> V_161 ; V_176 ++ )
if ( F_121 ( V_173 [ V_40 ] ,
V_1 -> V_173 [ V_176 ] ) == 0 )
break;
if ( V_176 == V_1 -> V_161 )
F_123 ( V_1 , V_173 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < V_161 ; V_40 ++ )
memcpy ( V_1 -> V_173 [ V_40 ] , V_173 [ V_40 ] , V_175 ) ;
V_1 -> V_161 = V_161 ;
}
static void F_124 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_171 * V_172 ;
unsigned int V_162 = F_125 ( V_10 ) ;
T_2 V_177 [ V_178 ] [ V_175 ] ;
unsigned int V_40 , V_176 ;
if ( V_162 > V_178 ) {
F_54 ( V_10 , L_9
L_11 ,
V_178 , V_162 ) ;
V_162 = V_178 ;
}
V_40 = 0 ;
F_126 (ha, netdev) {
if ( V_40 == V_162 )
break;
memcpy ( V_177 [ V_40 ++ ] , V_172 -> V_163 , V_175 ) ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_162 ; V_40 ++ ) {
for ( V_176 = 0 ; V_176 < V_162 ; V_176 ++ )
if ( F_121 ( V_1 -> V_177 [ V_40 ] ,
V_177 [ V_176 ] ) == 0 )
break;
if ( V_176 == V_162 )
F_122 ( V_1 , V_1 -> V_177 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < V_162 ; V_40 ++ ) {
for ( V_176 = 0 ; V_176 < V_1 -> V_162 ; V_176 ++ )
if ( F_121 ( V_177 [ V_40 ] ,
V_1 -> V_177 [ V_176 ] ) == 0 )
break;
if ( V_176 == V_1 -> V_162 )
F_123 ( V_1 , V_177 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < V_162 ; V_40 ++ )
memcpy ( V_1 -> V_177 [ V_40 ] , V_177 [ V_40 ] , V_175 ) ;
V_1 -> V_162 = V_162 ;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_179 = 1 ;
int V_152 = ( V_10 -> V_133 & V_180 ) ? 1 : 0 ;
int V_181 = ( V_10 -> V_133 & V_182 ) ? 1 : 0 ;
int V_183 = ( V_10 -> V_133 & V_184 ) ||
F_125 ( V_10 ) > V_178 ;
int V_185 = ( V_10 -> V_133 & V_186 ) ||
F_119 ( V_10 ) > V_174 ;
unsigned int V_133 = V_10 -> V_133 |
( V_185 ? V_186 : 0 ) |
( V_183 ? V_184 : 0 ) ;
if ( V_1 -> V_133 != V_133 ) {
V_1 -> V_133 = V_133 ;
F_128 ( V_1 , V_179 ,
V_152 , V_181 , V_183 , V_185 ) ;
}
if ( ! V_183 ) {
F_124 ( V_1 ) ;
if ( ! V_185 )
F_118 ( V_1 ) ;
}
}
static void F_129 ( struct V_9 * V_10 ,
struct V_187 * V_187 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
V_1 -> V_187 = V_187 ;
}
static void F_130 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
F_66 ( & V_1 -> V_96 ) ;
}
static int F_131 ( struct V_9 * V_10 , int V_188 , T_2 * V_189 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
if ( V_188 != V_190 )
return - V_49 ;
if ( F_111 ( V_189 ) ) {
memcpy ( V_1 -> V_191 . V_192 , V_189 , V_175 ) ;
return 0 ;
} else
return - V_65 ;
}
static int F_132 ( struct V_9 * V_10 , int V_188 ,
struct V_193 * V_19 [] )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_194 V_195 ;
int V_170 = 0 , V_196 = 1 ;
if ( V_188 != V_190 )
return - V_49 ;
if ( ! V_19 [ V_197 ] )
return - V_49 ;
memcpy ( & V_195 , & V_1 -> V_191 , sizeof( V_1 -> V_191 ) ) ;
memset ( & V_1 -> V_191 , 0 , sizeof( V_1 -> V_191 ) ) ;
V_1 -> V_191 . V_198 |= V_199 ;
V_1 -> V_191 . V_200 = F_133 ( V_19 [ V_197 ] ) ;
if ( V_19 [ V_201 ] ) {
V_1 -> V_191 . V_198 |= V_202 ;
memcpy ( V_1 -> V_191 . V_44 , F_134 ( V_19 [ V_201 ] ) ,
V_203 ) ;
}
if ( V_19 [ V_204 ] ) {
V_1 -> V_191 . V_198 |= V_205 ;
memcpy ( V_1 -> V_191 . V_206 ,
F_134 ( V_19 [ V_204 ] ) , V_207 ) ;
}
if ( V_19 [ V_208 ] ) {
V_1 -> V_191 . V_198 |= V_209 ;
memcpy ( V_1 -> V_191 . V_210 ,
F_134 ( V_19 [ V_208 ] ) , V_207 ) ;
}
if ( ! F_112 ( V_195 . V_192 ) )
memcpy ( V_1 -> V_191 . V_211 , V_195 . V_192 , V_175 ) ;
if ( F_112 ( V_10 -> V_165 ) )
F_135 ( V_10 -> V_165 ) ;
V_170 = F_136 ( V_1 , & V_195 , & V_196 ) ;
if ( V_170 ) {
if ( V_196 ) {
memcpy ( & V_1 -> V_191 , & V_195 , sizeof( V_1 -> V_191 ) ) ;
} else {
memset ( & V_1 -> V_191 , 0 , sizeof( V_1 -> V_191 ) ) ;
memset ( V_10 -> V_165 , 0 , V_175 ) ;
}
} else {
V_1 -> V_191 . V_198 |= V_212 ;
if ( V_1 -> V_191 . V_200 == V_213 ) {
memset ( V_1 -> V_191 . V_211 , 0 , V_175 ) ;
memset ( V_10 -> V_165 , 0 , V_175 ) ;
}
}
memset ( V_1 -> V_191 . V_192 , 0 , V_175 ) ;
return V_170 ;
}
static int F_137 ( struct V_9 * V_10 , int V_188 ,
struct V_103 * V_104 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
T_4 V_214 = V_215 ;
int V_170 ;
if ( ! ( V_1 -> V_191 . V_198 & V_212 ) )
return - V_216 ;
V_170 = F_138 ( V_1 , V_1 -> V_191 . V_200 , & V_214 ) ;
if ( V_170 )
return V_170 ;
F_139 ( V_104 , V_197 , V_1 -> V_191 . V_200 ) ;
F_139 ( V_104 , V_217 , V_214 ) ;
if ( V_1 -> V_191 . V_198 & V_202 )
F_140 ( V_104 , V_201 , V_203 ,
V_1 -> V_191 . V_44 ) ;
if ( V_1 -> V_191 . V_198 & V_205 )
F_140 ( V_104 , V_204 , V_207 ,
V_1 -> V_191 . V_206 ) ;
if ( V_1 -> V_191 . V_198 & V_209 )
F_140 ( V_104 , V_208 , V_207 ,
V_1 -> V_191 . V_210 ) ;
return 0 ;
V_218:
return - V_219 ;
}
static void F_141 ( struct V_220 * V_5 , struct V_221 * V_70 )
{
struct V_1 * V_1 = F_33 ( V_5 -> V_23 ) ;
if ( ! V_70 -> V_75 )
return;
F_34 ( V_1 -> V_2 , V_70 -> V_72 ,
V_70 -> V_73 , V_222 ) ;
F_36 ( V_70 -> V_75 ) ;
}
static int F_142 ( struct V_220 * V_5 )
{
struct V_1 * V_1 = F_33 ( V_5 -> V_23 ) ;
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_103 * V_104 ;
unsigned int V_73 = V_10 -> V_85 + V_223 ;
unsigned int V_224 = 0 ;
T_7 V_72 ;
V_104 = F_143 ( V_10 , V_73 ) ;
if ( ! V_104 )
return - V_225 ;
V_72 = F_84 ( V_1 -> V_2 , V_104 -> V_39 ,
V_73 , V_222 ) ;
F_144 ( V_5 , V_104 , V_224 ,
V_72 , V_73 ) ;
return 0 ;
}
static void F_145 ( struct V_220 * V_5 ,
struct V_76 * V_76 , struct V_221 * V_70 ,
int V_226 , void * V_77 )
{
struct V_1 * V_1 = F_33 ( V_5 -> V_23 ) ;
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_103 * V_104 ;
T_2 type , V_227 , V_115 , V_71 , V_228 , V_229 ;
T_2 V_230 , V_231 , V_232 , V_233 , V_234 ;
T_2 V_235 , V_236 , V_237 , V_238 ;
T_2 V_239 , V_240 , V_241 , V_242 , V_243 , V_244 ;
T_2 V_245 ;
T_4 V_79 , V_80 , V_246 , V_247 , V_248 ;
T_1 V_249 ;
if ( V_226 )
return;
V_104 = V_70 -> V_75 ;
F_146 ( V_104 -> V_39 - V_250 ) ;
F_34 ( V_1 -> V_2 , V_70 -> V_72 ,
V_70 -> V_73 , V_222 ) ;
F_147 ( (struct V_251 * ) V_76 ,
& type , & V_227 , & V_79 , & V_80 ,
& V_228 , & V_230 , & V_115 , & V_71 , & V_243 ,
& V_244 , & V_249 , & V_246 ,
& V_245 , & V_229 , & V_247 , & V_248 ,
& V_231 , & V_232 , & V_233 ,
& V_234 , & V_235 , & V_236 , & V_237 ,
& V_238 , & V_239 , & V_240 , & V_241 ,
& V_242 ) ;
if ( V_245 ) {
if ( ! V_242 ) {
if ( V_246 > 0 )
V_1 -> V_157 ++ ;
else if ( V_246 == 0 )
V_1 -> V_155 ++ ;
}
F_36 ( V_104 ) ;
return;
}
if ( V_115 && V_246 > 0 ) {
F_148 ( V_104 , V_246 ) ;
V_104 -> V_120 = F_149 ( V_104 , V_10 ) ;
if ( ( V_10 -> V_252 & V_253 ) && ! V_244 ) {
V_104 -> V_254 = F_150 ( V_248 ) ;
V_104 -> V_131 = V_255 ;
}
V_104 -> V_256 = V_10 ;
if ( V_1 -> V_187 && V_229 &&
( V_247 & V_257 ) ) {
if ( V_10 -> V_252 & V_258 )
F_151 ( & V_1 -> V_98 [ V_79 ] ,
V_1 -> V_187 , V_247 , V_104 ) ;
else
F_152 ( V_104 ,
V_1 -> V_187 , V_247 ) ;
} else {
if ( V_10 -> V_252 & V_258 )
F_153 ( & V_1 -> V_98 [ V_79 ] , V_104 ) ;
else
F_154 ( V_104 ) ;
}
} else {
F_36 ( V_104 ) ;
}
}
static int F_155 ( struct V_78 * V_23 , struct V_76 * V_76 ,
T_2 type , T_4 V_79 , T_4 V_80 , void * V_77 )
{
struct V_1 * V_1 = F_33 ( V_23 ) ;
F_156 ( & V_1 -> V_5 [ V_79 ] , V_76 ,
V_80 , V_259 ,
F_145 , V_77 ) ;
return 0 ;
}
static int F_157 ( struct V_99 * V_98 , int V_260 )
{
struct V_9 * V_10 = V_98 -> V_256 ;
struct V_1 * V_1 = F_12 ( V_10 ) ;
unsigned int V_261 = F_2 ( V_1 , 0 ) ;
unsigned int V_262 = F_3 ( V_1 , 0 ) ;
unsigned int V_62 = F_4 () ;
unsigned int V_263 = V_260 ;
unsigned int V_101 = - 1 ;
unsigned int V_264 , V_265 , V_102 ;
int V_170 ;
V_265 = F_73 ( & V_1 -> V_100 [ V_261 ] ,
V_263 , F_155 , NULL ) ;
V_102 = F_73 ( & V_1 -> V_100 [ V_262 ] ,
V_101 , F_38 , NULL ) ;
V_264 = V_265 + V_102 ;
if ( V_264 > 0 )
F_74 ( & V_1 -> V_62 [ V_62 ] ,
V_264 ,
0 ,
0 ) ;
V_170 = F_158 ( & V_1 -> V_5 [ 0 ] , F_142 ) ;
if ( V_170 )
V_265 = V_263 ;
if ( V_265 < V_263 ) {
F_159 ( V_98 ) ;
F_63 ( & V_1 -> V_62 [ V_62 ] ) ;
}
return V_265 ;
}
static int F_160 ( struct V_99 * V_98 , int V_260 )
{
struct V_9 * V_10 = V_98 -> V_256 ;
struct V_1 * V_1 = F_12 ( V_10 ) ;
unsigned int V_5 = ( V_98 - & V_1 -> V_98 [ 0 ] ) ;
unsigned int V_100 = F_2 ( V_1 , V_5 ) ;
unsigned int V_62 = F_7 ( V_1 , V_5 ) ;
unsigned int V_266 = V_260 ;
unsigned int V_264 ;
int V_170 ;
V_264 = F_73 ( & V_1 -> V_100 [ V_100 ] ,
V_266 , F_155 , NULL ) ;
if ( V_264 > 0 )
F_74 ( & V_1 -> V_62 [ V_62 ] ,
V_264 ,
0 ,
0 ) ;
V_170 = F_158 ( & V_1 -> V_5 [ V_5 ] , F_142 ) ;
if ( V_170 )
V_264 = V_266 ;
if ( V_264 < V_266 ) {
F_159 ( V_98 ) ;
F_63 ( & V_1 -> V_62 [ V_62 ] ) ;
}
return V_264 ;
}
static void F_161 ( unsigned long V_39 )
{
struct V_1 * V_1 = (struct V_1 * ) V_39 ;
F_59 ( V_1 ) ;
F_162 ( & V_1 -> V_267 ,
F_163 ( V_268 + V_269 ) ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
unsigned int V_40 ;
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_64 :
F_165 ( V_1 -> V_2 -> V_89 , V_10 ) ;
break;
case V_66 :
F_165 ( V_1 -> V_2 -> V_89 , V_1 ) ;
break;
case V_67 :
for ( V_40 = 0 ; V_40 < F_166 ( V_1 -> V_270 ) ; V_40 ++ )
if ( V_1 -> V_270 [ V_40 ] . V_271 )
F_165 ( V_1 -> V_272 [ V_40 ] . V_273 ,
V_1 -> V_270 [ V_40 ] . V_274 ) ;
break;
default:
break;
}
}
static int F_167 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
unsigned int V_40 , V_62 ;
int V_170 = 0 ;
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_64 :
V_170 = F_168 ( V_1 -> V_2 -> V_89 , F_60 ,
V_275 , V_10 -> V_44 , V_10 ) ;
break;
case V_66 :
V_170 = F_168 ( V_1 -> V_2 -> V_89 , F_69 ,
0 , V_10 -> V_44 , V_1 ) ;
break;
case V_67 :
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
V_62 = F_7 ( V_1 , V_40 ) ;
sprintf ( V_1 -> V_270 [ V_62 ] . V_276 ,
L_12 , V_10 -> V_44 , V_40 ) ;
V_1 -> V_270 [ V_62 ] . V_277 = F_71 ;
V_1 -> V_270 [ V_62 ] . V_274 = & V_1 -> V_98 [ V_40 ] ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ ) {
V_62 = F_8 ( V_1 , V_40 ) ;
sprintf ( V_1 -> V_270 [ V_62 ] . V_276 ,
L_13 , V_10 -> V_44 , V_40 ) ;
V_1 -> V_270 [ V_62 ] . V_277 = F_72 ;
V_1 -> V_270 [ V_62 ] . V_274 = V_1 ;
}
V_62 = F_9 ( V_1 ) ;
sprintf ( V_1 -> V_270 [ V_62 ] . V_276 ,
L_14 , V_10 -> V_44 ) ;
V_1 -> V_270 [ V_62 ] . V_277 = F_75 ;
V_1 -> V_270 [ V_62 ] . V_274 = V_1 ;
V_62 = F_10 ( V_1 ) ;
sprintf ( V_1 -> V_270 [ V_62 ] . V_276 ,
L_15 , V_10 -> V_44 ) ;
V_1 -> V_270 [ V_62 ] . V_277 = F_76 ;
V_1 -> V_270 [ V_62 ] . V_274 = V_1 ;
for ( V_40 = 0 ; V_40 < F_166 ( V_1 -> V_270 ) ; V_40 ++ )
V_1 -> V_270 [ V_40 ] . V_271 = 0 ;
for ( V_40 = 0 ; V_40 < V_1 -> V_278 ; V_40 ++ ) {
V_170 = F_168 ( V_1 -> V_272 [ V_40 ] . V_273 ,
V_1 -> V_270 [ V_40 ] . V_277 , 0 ,
V_1 -> V_270 [ V_40 ] . V_276 ,
V_1 -> V_270 [ V_40 ] . V_274 ) ;
if ( V_170 ) {
F_164 ( V_1 ) ;
break;
}
V_1 -> V_270 [ V_40 ] . V_271 = 1 ;
}
break;
default:
break;
}
return V_170 ;
}
static void F_169 ( struct V_1 * V_1 )
{
unsigned int V_40 ;
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_64 :
case V_66 :
F_170 ( V_1 -> V_2 -> V_89 ) ;
break;
case V_67 :
for ( V_40 = 0 ; V_40 < V_1 -> V_278 ; V_40 ++ )
F_170 ( V_1 -> V_272 [ V_40 ] . V_273 ) ;
break;
default:
break;
}
}
static int F_171 ( struct V_1 * V_1 )
{
int V_170 ;
F_39 ( & V_1 -> V_279 ) ;
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_64 :
V_170 = F_172 ( V_1 -> V_23 ,
F_6 () ) ;
break;
case V_67 :
V_170 = F_172 ( V_1 -> V_23 ,
F_10 ( V_1 ) ) ;
break;
default:
V_170 = F_172 ( V_1 -> V_23 , - 1 ) ;
break;
}
F_44 ( & V_1 -> V_279 ) ;
return V_170 ;
}
static void F_173 ( struct V_1 * V_1 )
{
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_66 :
F_162 ( & V_1 -> V_267 , V_268 ) ;
break;
default:
break;
} ;
}
static int F_174 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
unsigned int V_40 ;
int V_170 ;
V_170 = F_167 ( V_1 ) ;
if ( V_170 ) {
F_47 ( V_10 , L_16 ) ;
return V_170 ;
}
V_170 = F_171 ( V_1 ) ;
if ( V_170 ) {
F_47 ( V_10 ,
L_17 ) ;
goto V_280;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
F_158 ( & V_1 -> V_5 [ V_40 ] , F_142 ) ;
if ( F_175 ( & V_1 -> V_5 [ V_40 ] ) == 0 ) {
F_47 ( V_10 , L_18 ) ;
V_170 = - V_225 ;
goto V_281;
}
}
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ )
F_176 ( & V_1 -> V_6 [ V_40 ] ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_177 ( & V_1 -> V_5 [ V_40 ] ) ;
if ( F_1 ( V_1 ) && ! F_112 ( V_1 -> V_191 . V_211 ) )
F_123 ( V_1 , V_1 -> V_191 . V_211 ) ;
else
F_116 ( V_1 ) ;
F_127 ( V_10 ) ;
F_43 ( V_10 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_178 ( & V_1 -> V_98 [ V_40 ] ) ;
F_179 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_278 ; V_40 ++ )
F_63 ( & V_1 -> V_62 [ V_40 ] ) ;
F_173 ( V_1 ) ;
return 0 ;
V_281:
F_180 ( V_1 ) ;
V_280:
F_164 ( V_1 ) ;
return V_170 ;
}
static int F_181 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
unsigned int V_40 ;
int V_170 ;
for ( V_40 = 0 ; V_40 < V_1 -> V_278 ; V_40 ++ ) {
F_61 ( & V_1 -> V_62 [ V_40 ] ) ;
( void ) F_182 ( & V_1 -> V_62 [ V_40 ] ) ;
}
F_169 ( V_1 ) ;
F_183 ( & V_1 -> V_267 ) ;
F_184 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_185 ( & V_1 -> V_98 [ V_40 ] ) ;
F_58 ( V_10 ) ;
F_186 ( V_10 ) ;
if ( F_1 ( V_1 ) && ! F_112 ( V_1 -> V_191 . V_211 ) )
F_122 ( V_1 , V_1 -> V_191 . V_211 ) ;
else
F_115 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ ) {
V_170 = F_187 ( & V_1 -> V_6 [ V_40 ] ) ;
if ( V_170 )
return V_170 ;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
V_170 = F_188 ( & V_1 -> V_5 [ V_40 ] ) ;
if ( V_170 )
return V_170 ;
}
F_180 ( V_1 ) ;
F_164 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ )
F_189 ( & V_1 -> V_6 [ V_40 ] , F_32 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_190 ( & V_1 -> V_5 [ V_40 ] , F_141 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_282 ; V_40 ++ )
F_191 ( & V_1 -> V_100 [ V_40 ] ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_278 ; V_40 ++ )
F_192 ( & V_1 -> V_62 [ V_40 ] ) ;
return 0 ;
}
static int F_193 ( struct V_9 * V_10 , int V_283 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_284 = F_114 ( V_10 ) ;
if ( V_283 < V_285 || V_283 > V_286 )
return - V_65 ;
if ( V_284 )
F_181 ( V_10 ) ;
V_10 -> V_85 = V_283 ;
if ( V_10 -> V_85 > V_1 -> V_86 )
F_54 ( V_10 ,
L_19 ,
V_10 -> V_85 , V_1 -> V_86 ) ;
if ( V_284 )
F_174 ( V_10 ) ;
return 0 ;
}
static void F_194 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
struct V_78 * V_23 = V_1 -> V_23 ;
unsigned int V_40 , V_62 ;
switch ( F_29 ( V_23 ) ) {
case V_67 :
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ ) {
V_62 = F_7 ( V_1 , V_40 ) ;
F_71 ( V_1 -> V_272 [ V_62 ] . V_273 ,
& V_1 -> V_98 [ V_40 ] ) ;
}
V_62 = F_8 ( V_1 , V_40 ) ;
F_72 ( V_1 -> V_272 [ V_62 ] . V_273 , V_1 ) ;
break;
case V_66 :
F_69 ( V_1 -> V_2 -> V_89 , V_1 ) ;
break;
case V_64 :
F_60 ( V_1 -> V_2 -> V_89 , V_10 ) ;
break;
default:
break;
}
}
static int F_195 ( struct V_78 * V_23 ,
int (* F_196)( struct V_78 * , int ) ,
int (* F_197)( struct V_78 * , int * ) ,
int V_287 )
{
unsigned long time ;
int V_288 ;
int V_170 ;
F_198 ( F_199 () ) ;
V_170 = F_196 ( V_23 , V_287 ) ;
if ( V_170 )
return V_170 ;
time = V_268 + ( V_289 * 2 ) ;
do {
V_170 = F_197 ( V_23 , & V_288 ) ;
if ( V_170 )
return V_170 ;
if ( V_288 )
return 0 ;
F_200 ( V_289 / 10 ) ;
} while ( F_201 ( time , V_268 ) );
return - V_290 ;
}
static int F_202 ( struct V_1 * V_1 )
{
int V_170 ;
V_170 = F_195 ( V_1 -> V_23 , V_291 ,
V_292 , 0 ) ;
if ( V_170 )
F_203 ( F_204 ( V_1 ) , L_20 ,
V_170 ) ;
return V_170 ;
}
static int F_205 ( struct V_1 * V_1 )
{
int V_170 ;
V_170 = F_195 ( V_1 -> V_23 , V_293 ,
V_294 , 0 ) ;
if ( V_170 )
F_47 ( V_1 -> V_10 , L_21 ,
V_170 ) ;
return V_170 ;
}
static int F_206 ( struct V_1 * V_1 )
{
T_7 V_295 ;
union V_296 * V_297 = NULL ;
union V_296 V_298 = {
. V_299 [ 0 ] . V_300 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_299 [ 1 ] . V_300 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_299 [ 2 ] . V_300 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_299 [ 3 ] . V_300 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_170 ;
V_297 = F_207 ( V_1 -> V_2 ,
sizeof( union V_296 ) , & V_295 ) ;
if ( ! V_297 )
return - V_225 ;
memcpy ( V_297 , & V_298 , sizeof( union V_296 ) ) ;
F_39 ( & V_1 -> V_279 ) ;
V_170 = F_208 ( V_1 ,
V_295 ,
sizeof( union V_296 ) ) ;
F_44 ( & V_1 -> V_279 ) ;
F_209 ( V_1 -> V_2 , sizeof( union V_296 ) ,
V_297 , V_295 ) ;
return V_170 ;
}
static int F_210 ( struct V_1 * V_1 , T_2 V_301 )
{
T_7 V_302 ;
union V_303 * V_304 = NULL ;
unsigned int V_40 ;
int V_170 ;
V_304 = F_207 ( V_1 -> V_2 ,
sizeof( union V_303 ) , & V_302 ) ;
if ( ! V_304 )
return - V_225 ;
for ( V_40 = 0 ; V_40 < ( 1 << V_301 ) ; V_40 ++ )
( * V_304 ) . V_305 [ V_40 / 4 ] . V_300 [ V_40 % 4 ] = V_40 % V_1 -> V_7 ;
F_39 ( & V_1 -> V_279 ) ;
V_170 = F_211 ( V_1 ,
V_302 ,
sizeof( union V_303 ) ) ;
F_44 ( & V_1 -> V_279 ) ;
F_209 ( V_1 -> V_2 , sizeof( union V_303 ) ,
V_304 , V_302 ) ;
return V_170 ;
}
static int F_212 ( struct V_1 * V_1 , T_2 V_306 ,
T_2 V_307 , T_2 V_301 , T_2 V_308 , T_2 V_309 )
{
const T_2 V_310 = 0 ;
const T_2 V_311 = 1 ;
int V_170 ;
F_39 ( & V_1 -> V_279 ) ;
V_170 = F_213 ( V_1 ,
V_306 , V_307 ,
V_301 , V_308 ,
V_309 , V_310 ,
V_311 ) ;
F_44 ( & V_1 -> V_279 ) ;
return V_170 ;
}
static int F_214 ( struct V_1 * V_1 )
{
struct V_3 * V_256 = F_204 ( V_1 ) ;
const T_2 V_306 = 0 ;
const T_2 V_307 = V_312 |
V_313 |
V_314 |
V_315 ;
const T_2 V_301 = 7 ;
const T_2 V_308 = 0 ;
T_2 V_309 = F_215 ( V_1 , V_316 ) && ( V_1 -> V_7 > 1 ) ;
if ( V_309 ) {
if ( ! F_206 ( V_1 ) ) {
if ( F_210 ( V_1 , V_301 ) ) {
V_309 = 0 ;
F_216 ( V_256 , L_22
L_23 ) ;
}
} else {
V_309 = 0 ;
F_216 ( V_256 , L_24 ) ;
}
}
return F_212 ( V_1 , V_306 , V_307 ,
V_301 , V_308 , V_309 ) ;
}
static void F_217 ( struct V_317 * V_318 )
{
struct V_1 * V_1 = F_218 ( V_318 , struct V_1 , V_96 ) ;
if ( ! F_114 ( V_1 -> V_10 ) )
return;
F_219 () ;
F_220 ( V_1 ) ;
F_181 ( V_1 -> V_10 ) ;
F_205 ( V_1 ) ;
F_109 ( V_1 ) ;
F_221 ( V_1 ) ;
F_214 ( V_1 ) ;
F_222 ( V_1 ) ;
F_174 ( V_1 -> V_10 ) ;
F_223 () ;
}
static int F_224 ( struct V_1 * V_1 )
{
unsigned int V_319 = F_27 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_320 = F_27 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_40 ;
F_198 ( F_166 ( V_1 -> V_272 ) < V_319 + V_320 + 2 ) ;
for ( V_40 = 0 ; V_40 < V_319 + V_320 + 2 ; V_40 ++ )
V_1 -> V_272 [ V_40 ] . V_321 = V_40 ;
if ( F_215 ( V_1 , V_316 ) &&
V_1 -> V_322 . V_323 < 1 &&
V_1 -> V_7 >= V_319 &&
V_1 -> V_8 >= V_320 &&
V_1 -> V_282 >= V_319 + V_320 &&
V_1 -> V_278 >= V_319 + V_320 + 2 ) {
if ( ! F_225 ( V_1 -> V_2 , V_1 -> V_272 , V_319 + V_320 + 2 ) ) {
V_1 -> V_7 = V_319 ;
V_1 -> V_8 = V_320 ;
V_1 -> V_282 = V_319 + V_320 ;
V_1 -> V_278 = V_319 + V_320 + 2 ;
F_226 ( V_1 -> V_23 ,
V_67 ) ;
return 0 ;
}
}
if ( V_1 -> V_322 . V_323 < 1 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_8 >= V_320 &&
V_1 -> V_282 >= 1 + V_320 &&
V_1 -> V_278 >= 1 + V_320 + 2 ) {
if ( ! F_225 ( V_1 -> V_2 , V_1 -> V_272 , 1 + V_320 + 2 ) ) {
V_1 -> V_7 = 1 ;
V_1 -> V_8 = V_320 ;
V_1 -> V_282 = 1 + V_320 ;
V_1 -> V_278 = 1 + V_320 + 2 ;
F_226 ( V_1 -> V_23 ,
V_67 ) ;
return 0 ;
}
}
if ( V_1 -> V_322 . V_323 < 2 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_8 >= 1 &&
V_1 -> V_282 >= 2 &&
V_1 -> V_278 >= 1 &&
! F_227 ( V_1 -> V_2 ) ) {
V_1 -> V_7 = 1 ;
V_1 -> V_8 = 1 ;
V_1 -> V_282 = 2 ;
V_1 -> V_278 = 1 ;
F_226 ( V_1 -> V_23 , V_66 ) ;
return 0 ;
}
if ( V_1 -> V_322 . V_323 < 3 &&
V_1 -> V_7 >= 1 &&
V_1 -> V_8 >= 1 &&
V_1 -> V_282 >= 2 &&
V_1 -> V_278 >= 3 ) {
V_1 -> V_7 = 1 ;
V_1 -> V_8 = 1 ;
V_1 -> V_282 = 2 ;
V_1 -> V_278 = 3 ;
F_226 ( V_1 -> V_23 , V_64 ) ;
return 0 ;
}
F_226 ( V_1 -> V_23 , V_324 ) ;
return - V_65 ;
}
static void F_228 ( struct V_1 * V_1 )
{
switch ( F_29 ( V_1 -> V_23 ) ) {
case V_67 :
F_229 ( V_1 -> V_2 ) ;
break;
case V_66 :
F_230 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_226 ( V_1 -> V_23 , V_324 ) ;
}
static void F_231 ( struct V_1 * V_1 )
{
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_232 ( & V_1 -> V_98 [ V_40 ] ) ;
F_233 ( V_1 ) ;
F_228 ( V_1 ) ;
}
static int F_234 ( struct V_1 * V_1 )
{
struct V_3 * V_256 = F_204 ( V_1 ) ;
struct V_9 * V_10 = V_1 -> V_10 ;
unsigned int V_40 ;
int V_170 ;
V_170 = F_235 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_25 ) ;
return V_170 ;
}
F_236 ( V_1 ) ;
V_170 = F_224 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_26
L_27 ) ;
return V_170 ;
}
V_170 = F_237 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_28 ) ;
goto V_325;
}
F_221 ( V_1 ) ;
V_170 = F_214 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_29 ) ;
goto V_325;
}
switch ( F_29 ( V_1 -> V_23 ) ) {
default:
F_238 ( V_10 , & V_1 -> V_98 [ 0 ] , F_157 , 64 ) ;
break;
case V_67 :
for ( V_40 = 0 ; V_40 < V_1 -> V_7 ; V_40 ++ )
F_238 ( V_10 , & V_1 -> V_98 [ V_40 ] ,
F_160 , 64 ) ;
break;
}
return 0 ;
V_325:
F_228 ( V_1 ) ;
F_233 ( V_1 ) ;
return V_170 ;
}
static void F_239 ( struct V_1 * V_1 )
{
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < F_166 ( V_1 -> V_326 ) ; V_40 ++ )
if ( V_1 -> V_326 [ V_40 ] . V_327 )
F_240 ( V_1 -> V_326 [ V_40 ] . V_327 ) ;
}
static int T_9 F_241 ( struct V_328 * V_2 ,
const struct V_329 * V_330 )
{
struct V_3 * V_256 = & V_2 -> V_256 ;
struct V_9 * V_10 ;
struct V_1 * V_1 ;
int V_331 = 0 ;
unsigned int V_40 ;
int V_170 ;
V_10 = F_242 ( sizeof( struct V_1 ) ) ;
if ( ! V_10 ) {
F_243 ( L_30 ) ;
return - V_225 ;
}
F_244 ( V_2 , V_10 ) ;
F_245 ( V_10 , & V_2 -> V_256 ) ;
V_1 = F_12 ( V_10 ) ;
V_1 -> V_10 = V_10 ;
V_1 -> V_2 = V_2 ;
V_170 = F_246 ( V_2 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_31 ) ;
goto V_332;
}
V_170 = F_247 ( V_2 , V_33 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_32 ) ;
goto V_333;
}
F_248 ( V_2 ) ;
V_170 = F_249 ( V_2 , F_250 ( 40 ) ) ;
if ( V_170 ) {
V_170 = F_249 ( V_2 , F_250 ( 32 ) ) ;
if ( V_170 ) {
F_203 ( V_256 , L_33 ) ;
goto V_334;
}
V_170 = F_251 ( V_2 , F_250 ( 32 ) ) ;
if ( V_170 ) {
F_203 ( V_256 , L_34
L_35 , 32 ) ;
goto V_334;
}
} else {
V_170 = F_251 ( V_2 , F_250 ( 40 ) ) ;
if ( V_170 ) {
F_203 ( V_256 , L_34
L_35 , 40 ) ;
goto V_334;
}
V_331 = 1 ;
}
for ( V_40 = 0 ; V_40 < F_166 ( V_1 -> V_326 ) ; V_40 ++ ) {
if ( ! ( F_252 ( V_2 , V_40 ) & V_335 ) )
continue;
V_1 -> V_326 [ V_40 ] . V_73 = F_253 ( V_2 , V_40 ) ;
V_1 -> V_326 [ V_40 ] . V_327 = F_254 ( V_2 , V_40 , V_1 -> V_326 [ V_40 ] . V_73 ) ;
if ( ! V_1 -> V_326 [ V_40 ] . V_327 ) {
F_203 ( V_256 , L_36 , V_40 ) ;
V_170 = - V_336 ;
goto V_337;
}
V_1 -> V_326 [ V_40 ] . V_338 = F_255 ( V_2 , V_40 ) ;
}
V_1 -> V_23 = F_256 ( NULL , V_1 , V_2 , V_1 -> V_326 ,
F_166 ( V_1 -> V_326 ) ) ;
if ( ! V_1 -> V_23 ) {
F_203 ( V_256 , L_37 ) ;
V_170 = - V_336 ;
goto V_337;
}
V_170 = F_202 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_38 ) ;
goto V_339;
}
F_257 ( & V_1 -> V_279 ) ;
V_170 = F_222 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 ,
L_39 ) ;
goto V_340;
}
F_58 ( V_10 ) ;
if ( ! F_1 ( V_1 ) ) {
V_170 = F_258 ( V_1 -> V_23 , 0 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_40 ) ;
goto V_340;
}
}
V_170 = F_234 ( V_1 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_41 ) ;
goto V_340;
}
F_259 ( & V_1 -> V_267 ) ;
V_1 -> V_267 . V_341 = F_161 ;
V_1 -> V_267 . V_39 = ( unsigned long ) V_1 ;
F_260 ( & V_1 -> V_96 , F_217 ) ;
for ( V_40 = 0 ; V_40 < V_1 -> V_8 ; V_40 ++ )
F_257 ( & V_1 -> V_81 [ V_40 ] ) ;
V_1 -> V_86 = V_1 -> V_322 . V_85 ;
( void ) F_193 ( V_10 , V_1 -> V_86 ) ;
V_170 = F_110 ( V_10 , V_1 -> V_211 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_42 ) ;
goto V_342;
}
V_1 -> V_60 = V_1 -> V_322 . V_343 ;
V_1 -> V_61 = V_1 -> V_60 ;
if ( F_1 ( V_1 ) )
V_10 -> V_344 = & V_345 ;
else
V_10 -> V_344 = & V_346 ;
V_10 -> V_347 = 2 * V_289 ;
V_10 -> V_348 = & V_349 ;
V_10 -> V_252 |= V_350 | V_351 ;
if ( F_215 ( V_1 , V_352 ) ) {
V_10 -> V_252 &= ~ V_350 ;
V_1 -> V_129 = 1 ;
V_1 -> V_130 = V_1 -> V_322 . V_130 ;
F_261 ( V_256 , L_43 , V_1 -> V_130 ) ;
}
if ( F_215 ( V_1 , V_353 ) )
V_10 -> V_354 |= V_355 | V_356 ;
if ( F_215 ( V_1 , V_357 ) )
V_10 -> V_354 |= V_358 |
V_359 | V_360 ;
if ( F_215 ( V_1 , V_361 ) )
V_10 -> V_354 |= V_253 ;
V_10 -> V_252 |= V_10 -> V_354 ;
if ( V_331 )
V_10 -> V_252 |= V_362 ;
V_170 = F_262 ( V_10 ) ;
if ( V_170 ) {
F_203 ( V_256 , L_44 ) ;
goto V_342;
}
return 0 ;
V_342:
F_231 ( V_1 ) ;
V_340:
F_263 ( V_1 -> V_23 ) ;
V_339:
F_264 ( V_1 -> V_23 ) ;
V_337:
F_239 ( V_1 ) ;
V_334:
F_265 ( V_2 ) ;
V_333:
F_266 ( V_2 ) ;
V_332:
F_244 ( V_2 , NULL ) ;
F_267 ( V_10 ) ;
return V_170 ;
}
static void T_10 F_268 ( struct V_328 * V_2 )
{
struct V_9 * V_10 = F_269 ( V_2 ) ;
if ( V_10 ) {
struct V_1 * V_1 = F_12 ( V_10 ) ;
F_270 ( & V_1 -> V_96 ) ;
F_271 ( V_10 ) ;
F_231 ( V_1 ) ;
F_263 ( V_1 -> V_23 ) ;
F_264 ( V_1 -> V_23 ) ;
F_239 ( V_1 ) ;
F_265 ( V_2 ) ;
F_266 ( V_2 ) ;
F_244 ( V_2 , NULL ) ;
F_267 ( V_10 ) ;
}
}
static int T_11 F_272 ( void )
{
F_273 ( L_45 , V_363 , V_35 ) ;
return F_274 ( & V_364 ) ;
}
static void T_12 F_275 ( void )
{
F_276 ( & V_364 ) ;
}
