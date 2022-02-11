static int F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 ) {
if ( V_3 [ V_2 ] == V_1 )
return V_2 ;
}
return - V_4 ;
}
static int F_3 (
enum V_5 V_6 ,
T_1 V_7 ,
T_1 * V_8 ,
struct V_9 * V_10 )
{
int V_11 ;
if ( V_10 -> V_12 != V_13 ) {
V_11 =
F_1 ( V_7 ) ;
if ( V_11 < 0 )
return - V_4 ;
}
switch ( V_10 -> V_12 ) {
case V_13 :
* V_8 = V_14 ;
break;
case V_15 :
if ( V_11 >
F_2 ( V_16 ) - 1 )
return - V_4 ;
* V_8 = V_16 [ V_11 ] ;
break;
case V_17 :
if ( V_11 >
F_2 ( V_18 ) - 1 )
return - V_4 ;
* V_8 = V_18 [ V_11 ] ;
break;
default:
* V_8 = V_14 ;
break;
}
return 0 ;
}
static inline struct V_9 * F_4 ( struct V_19 * V_20 )
{
return F_5 ( V_20 -> V_21 , struct V_9 , V_22 ) ;
}
static inline struct V_9 * F_6 ( struct V_23 * V_24 )
{
return F_5 ( V_24 , struct V_9 , V_24 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
F_8 ( V_10 -> V_12 > 3 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 ) {
if ( V_10 -> V_12 > 2 )
return V_13 ;
return V_10 -> V_12 ;
} else {
if ( V_10 -> V_12 > 2 )
return V_15 ;
return V_29 [ V_10 -> V_12 ] ;
}
}
static inline void F_9 ( void T_2 * V_30 ,
const unsigned char * V_31 ,
unsigned long V_32 , int V_33 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ )
F_10 ( ( unsigned int ) V_31 [ V_2 ] , V_30 + V_32 + ( V_2 * 0x04 ) ) ;
}
static inline void F_11 ( void T_2 * V_30 , int V_34 )
{
F_9 ( V_30 , V_35 [ V_34 ] ,
F_12 ( 0 ) ,
F_2 ( V_35 [ V_34 ] ) ) ;
}
static inline void F_13 ( void T_2 * V_30 , int V_34 )
{
F_9 ( V_30 , V_36 [ V_34 ] ,
F_12 ( 1 ) ,
F_2 ( V_36 [ V_34 ] ) ) ;
}
static inline void F_14 ( void T_2 * V_30 ,
const unsigned char * V_37 ,
unsigned long V_32 , int V_33 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ )
F_10 ( ( unsigned int ) V_37 [ V_2 ] , V_30 + V_32 + ( V_2 * 0x04 ) ) ;
}
static inline void F_15 ( void T_2 * V_30 )
{
F_14 ( V_30 , V_38 , F_16 ( 0 ) ,
F_2 ( V_38 ) ) ;
}
static inline void F_17 ( void T_2 * V_30 )
{
F_14 ( V_30 , V_39 , F_18 ( 0 ) ,
F_2 ( V_39 ) ) ;
}
static inline void F_19 ( void T_2 * V_30 )
{
F_14 ( V_30 , V_40 , F_20 ( 0 ) ,
F_2 ( V_40 ) ) ;
}
static inline void F_21 ( void T_2 * V_30 )
{
F_14 ( V_30 , V_41 , F_22 ( 0 ) ,
F_2 ( V_41 ) ) ;
}
static inline void F_23 ( void T_2 * V_30 ,
const unsigned char * V_42 ,
unsigned long V_32 , int V_33 )
{
int V_2 ;
unsigned int V_43 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 += 4 ) {
V_43 = V_42 [ V_2 ] |
( V_42 [ V_2 + 1 ] << 8 ) |
( V_42 [ V_2 + 2 ] << 16 ) |
( V_42 [ V_2 + 3 ] << 24 ) ;
F_10 ( V_43 , V_30 + V_32 + V_2 ) ;
}
}
static inline void F_24 ( void T_2 * V_30 , int V_34 )
{
F_23 ( V_30 , V_35 [ V_34 ] ,
F_25 ( 0 ) ,
F_2 ( V_35 [ V_34 ] ) ) ;
}
static inline void F_26 ( void T_2 * V_30 , int V_34 )
{
F_23 ( V_30 , V_36 [ V_34 ] ,
F_25 ( 1 ) ,
F_2 ( V_36 [ V_34 ] ) ) ;
}
void F_27 ( void T_2 * V_44 )
{
F_23 ( V_44 , V_38 , V_45 ,
F_2 ( V_38 ) ) ;
F_23 ( V_44 , V_38 , V_46 ,
F_2 ( V_38 ) ) ;
F_23 ( V_44 , V_39 , V_47 ,
F_2 ( V_39 ) ) ;
F_23 ( V_44 , V_39 , V_48 ,
F_2 ( V_39 ) ) ;
F_23 ( V_44 , V_40 , V_49 ,
F_2 ( V_40 ) ) ;
F_23 ( V_44 , V_40 , V_50 ,
F_2 ( V_40 ) ) ;
F_23 ( V_44 , V_41 , V_51 ,
F_2 ( V_41 ) ) ;
F_23 ( V_44 , V_41 , V_52 ,
F_2 ( V_41 ) ) ;
}
static int F_28 ( struct V_53 * V_53 )
{
struct V_54 * V_25 = F_29 ( V_53 ) ;
struct V_55 * V_56 = F_30 ( V_53 ) ;
struct V_9 * V_10 ;
struct V_57 * V_58 , * V_59 ;
int V_60 = 0 ;
V_10 = F_31 ( sizeof( * V_10 ) , V_61 ) ;
if ( ! V_10 )
return - V_62 ;
if ( F_32 ( & V_25 -> V_63 ) ) {
V_60 = - V_64 ;
goto free;
}
F_33 ( & V_10 -> V_24 , V_56 ) ;
V_10 -> V_24 . V_22 = & V_10 -> V_22 ;
V_53 -> V_65 = & V_10 -> V_24 ;
F_34 ( & V_10 -> V_24 ) ;
V_10 -> V_25 = V_25 ;
if ( V_56 == V_25 -> V_66 ) {
V_10 -> V_67 = V_68 ;
V_58 = F_35 ( V_10 , V_69 ,
V_70 ) ;
V_59 = F_35 ( V_10 , V_71 ,
V_72 ) ;
} else {
V_10 -> V_67 = V_73 ;
V_58 = F_35 ( V_10 , V_71 ,
V_70 ) ;
V_59 = F_35 ( V_10 , V_74 ,
V_72 ) ;
}
V_10 -> V_24 . V_75 = F_36 ( V_25 -> V_76 , V_10 , V_77 ) ;
if ( F_37 ( V_10 -> V_24 . V_75 ) ) {
V_60 = F_38 ( V_10 -> V_24 . V_75 ) ;
goto error;
}
V_10 -> V_78 . V_79 = V_58 ;
V_10 -> V_80 . V_79 = V_59 ;
V_60 = F_39 ( V_10 ) ;
if ( V_60 < 0 )
goto error;
F_40 ( & V_25 -> V_63 ) ;
return 0 ;
error:
F_41 ( & V_10 -> V_24 ) ;
F_42 ( & V_10 -> V_24 ) ;
F_40 ( & V_25 -> V_63 ) ;
free:
F_43 ( V_10 ) ;
return V_60 ;
}
static int F_44 ( struct V_53 * V_53 )
{
struct V_54 * V_25 = F_29 ( V_53 ) ;
struct V_9 * V_10 = F_6 ( V_53 -> V_65 ) ;
F_45 ( & V_25 -> V_63 ) ;
F_46 ( V_10 -> V_24 . V_75 ) ;
F_47 ( & V_10 -> V_22 ) ;
F_41 ( & V_10 -> V_24 ) ;
F_42 ( & V_10 -> V_24 ) ;
F_43 ( V_10 ) ;
F_40 ( & V_25 -> V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_81 * V_82 )
{
if ( V_82 -> V_83 >= V_82 -> V_84 )
return - 1 ;
return ( ( unsigned char * ) V_82 -> V_85 ) [ V_82 -> V_83 ++ ] ;
}
static int F_49 ( struct V_81 * V_82 , unsigned int * V_86 )
{
unsigned int V_87 ;
int V_88 ;
V_88 = F_48 ( V_82 ) ;
if ( V_88 == - 1 )
return - 1 ;
V_87 = V_88 << 8 ;
V_88 = F_48 ( V_82 ) ;
if ( V_88 == - 1 )
return - 1 ;
* V_86 = ( unsigned int ) V_88 | V_87 ;
return 0 ;
}
static void F_50 ( struct V_81 * V_82 , long V_33 )
{
if ( V_33 <= 0 )
return;
while ( V_33 -- )
F_48 ( V_82 ) ;
}
static bool F_51 ( struct V_89 * V_90 ,
unsigned long V_91 , unsigned long V_84 ,
struct V_9 * V_10 )
{
int V_20 , V_92 , V_93 ;
unsigned int V_94 , V_95 , V_86 , V_12 = 0 ;
long V_96 ;
struct V_81 V_97 ;
V_97 . V_84 = V_84 ;
V_97 . V_85 = V_91 ;
V_97 . V_83 = 0 ;
V_93 = 1 ;
while ( V_93 ) {
V_20 = F_48 ( & V_97 ) ;
if ( V_20 == - 1 )
break;
if ( V_20 != 0xff )
continue;
do
V_20 = F_48 ( & V_97 ) ;
while ( V_20 == 0xff );
if ( V_20 == - 1 )
break;
if ( V_20 == 0 )
continue;
V_96 = 0 ;
switch ( V_20 ) {
case V_98 :
if ( F_49 ( & V_97 , & V_86 ) )
break;
if ( F_48 ( & V_97 ) == - 1 )
break;
if ( F_49 ( & V_97 , & V_94 ) )
break;
if ( F_49 ( & V_97 , & V_95 ) )
break;
V_92 = F_48 ( & V_97 ) ;
if ( V_92 == - 1 )
break;
V_93 = 0 ;
if ( V_92 == 1 ) {
V_12 = 0x33 ;
} else {
F_50 ( & V_97 , 1 ) ;
V_12 = F_48 ( & V_97 ) ;
F_50 ( & V_97 , 1 ) ;
}
F_50 ( & V_97 , V_92 * 2 ) ;
break;
case V_99 ... V_99 + 7 :
case V_100 :
case V_101 :
case V_102 :
break;
default:
if ( F_49 ( & V_97 , & V_86 ) )
break;
V_96 = ( long ) V_86 - 2 ;
F_50 ( & V_97 , V_96 ) ;
break;
}
}
V_90 -> V_103 = V_95 ;
V_90 -> V_104 = V_94 ;
V_90 -> V_84 = V_92 ;
switch ( V_12 ) {
case 0x11 :
V_10 -> V_12 = V_105 ;
break;
case 0x21 :
V_10 -> V_12 = V_17 ;
break;
case 0x22 :
V_10 -> V_12 = V_15 ;
break;
case 0x33 :
V_10 -> V_12 = V_13 ;
break;
default:
return false ;
}
return ! V_93 ;
}
static int F_52 ( struct V_53 * V_53 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
if ( V_10 -> V_67 == V_68 ) {
F_53 ( V_108 -> V_109 , V_110 L_1 ,
sizeof( V_108 -> V_109 ) ) ;
F_53 ( V_108 -> V_111 , V_110 L_1 ,
sizeof( V_108 -> V_111 ) ) ;
} else {
F_53 ( V_108 -> V_109 , V_110 L_2 ,
sizeof( V_108 -> V_109 ) ) ;
F_53 ( V_108 -> V_111 , V_110 L_2 ,
sizeof( V_108 -> V_111 ) ) ;
}
V_108 -> V_112 [ 0 ] = 0 ;
V_108 -> V_113 = V_114 | V_115 |
V_116 | V_117 ;
return 0 ;
}
static int F_54 ( struct V_57 * V_118 , int V_119 ,
struct V_120 * V_121 , T_1 type )
{
int V_2 , V_122 = 0 ;
for ( V_2 = 0 ; V_2 < V_119 ; ++ V_2 ) {
if ( V_118 [ V_2 ] . V_123 & type ) {
if ( V_122 == V_121 -> V_124 )
break;
++ V_122 ;
}
}
if ( V_2 >= V_119 )
return - V_4 ;
F_53 ( V_121 -> V_125 , V_118 [ V_2 ] . V_126 , sizeof( V_121 -> V_125 ) ) ;
V_121 -> V_127 = V_118 [ V_2 ] . V_1 ;
return 0 ;
}
static int F_55 ( struct V_53 * V_53 , void * V_106 ,
struct V_120 * V_121 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
if ( V_10 -> V_67 == V_68 )
return F_54 ( V_118 , V_128 , V_121 ,
V_129 ) ;
return F_54 ( V_118 , V_128 , V_121 ,
V_130 ) ;
}
static int F_56 ( struct V_53 * V_53 , void * V_106 ,
struct V_120 * V_121 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
if ( V_10 -> V_67 == V_68 )
return F_54 ( V_118 , V_128 , V_121 ,
V_131 ) ;
return F_54 ( V_118 , V_128 , V_121 ,
V_132 ) ;
}
static struct V_89 * F_57 ( struct V_9 * V_10 ,
enum V_133 type )
{
if ( type == V_134 )
return & V_10 -> V_78 ;
if ( type == V_135 )
return & V_10 -> V_80 ;
return NULL ;
}
static int F_58 ( struct V_53 * V_53 , void * V_106 , struct V_136 * V_121 )
{
struct V_137 * V_138 ;
struct V_89 * V_139 = NULL ;
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
struct V_9 * V_142 = F_6 ( V_106 ) ;
V_138 = F_59 ( V_142 -> V_24 . V_75 , V_121 -> type ) ;
if ( ! V_138 )
return - V_4 ;
if ( V_121 -> type == V_135 &&
V_142 -> V_67 == V_73 && ! V_142 -> V_143 )
return - V_4 ;
V_139 = F_57 ( V_142 , V_121 -> type ) ;
F_60 ( V_139 == NULL ) ;
V_141 -> V_95 = V_139 -> V_103 ;
V_141 -> V_94 = V_139 -> V_104 ;
V_141 -> V_144 = V_145 ;
V_141 -> V_127 = V_139 -> V_79 -> V_1 ;
V_141 -> V_146 = 0 ;
if ( V_139 -> V_79 -> V_1 != V_71 ) {
T_1 V_147 = V_139 -> V_103 ;
if ( V_139 -> V_79 -> V_148 == 1 )
V_147 = ( V_147 * V_139 -> V_79 -> V_149 ) >> 3 ;
V_141 -> V_146 = V_147 ;
}
V_141 -> V_150 = V_139 -> V_84 ;
return 0 ;
}
static struct V_57 * F_35 ( struct V_9 * V_10 ,
T_1 V_127 , unsigned int V_151 )
{
unsigned int V_152 , V_153 ;
if ( V_10 -> V_67 == V_68 )
V_153 = ( V_151 == V_70 ) ?
V_131 :
V_129 ;
else
V_153 = ( V_151 == V_70 ) ?
V_132 :
V_130 ;
for ( V_152 = 0 ; V_152 < F_2 ( V_118 ) ; V_152 ++ ) {
struct V_57 * V_79 = & V_118 [ V_152 ] ;
if ( V_79 -> V_1 == V_127 &&
V_79 -> V_123 & V_153 &&
V_79 -> V_123 & V_10 -> V_25 -> V_26 -> V_154 ) {
return V_79 ;
}
}
return NULL ;
}
static void F_61 ( T_1 * V_103 , unsigned int V_155 , unsigned int V_156 ,
unsigned int V_157 ,
T_1 * V_104 , unsigned int V_158 , unsigned int V_159 ,
unsigned int V_160 )
{
int V_95 , V_94 , V_161 , V_162 ;
V_95 = * V_103 ;
V_94 = * V_104 ;
V_161 = 1 << V_157 ;
V_162 = 1 << V_160 ;
F_62 ( V_103 , V_155 , V_156 , V_157 , V_104 , V_158 , V_159 , V_160 , 0 ) ;
if ( * V_103 < V_95 && ( * V_103 + V_161 ) < V_156 )
* V_103 += V_161 ;
if ( * V_104 < V_94 && ( * V_104 + V_162 ) < V_159 )
* V_104 += V_162 ;
}
static int F_63 ( struct V_136 * V_121 , struct V_57 * V_79 ,
struct V_9 * V_10 , int V_163 )
{
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
if ( V_141 -> V_144 == V_164 )
V_141 -> V_144 = V_145 ;
else if ( V_141 -> V_144 != V_145 )
return - V_4 ;
if ( V_163 == V_70 )
F_61 ( & V_141 -> V_95 , V_165 ,
V_166 , 0 ,
& V_141 -> V_94 , V_167 ,
V_168 , 0 ) ;
else
F_61 ( & V_141 -> V_95 , V_165 ,
V_166 , V_79 -> V_169 ,
& V_141 -> V_94 , V_167 ,
V_168 , V_79 -> V_170 ) ;
if ( V_79 -> V_1 == V_71 ) {
if ( V_141 -> V_150 <= 0 )
V_141 -> V_150 = V_171 ;
V_141 -> V_146 = 0 ;
} else {
T_1 V_147 = V_141 -> V_146 ;
if ( V_79 -> V_148 > 1 && V_147 < V_141 -> V_95 )
V_147 = V_141 -> V_95 ;
if ( V_79 -> V_148 == 1 &&
( V_147 << 3 ) / V_79 -> V_149 < V_141 -> V_95 )
V_147 = ( V_141 -> V_95 * V_79 -> V_149 ) >> 3 ;
V_141 -> V_146 = V_147 ;
V_141 -> V_150 = ( V_141 -> V_95 * V_141 -> V_94 * V_79 -> V_149 ) >> 3 ;
}
return 0 ;
}
static int F_64 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
struct V_57 * V_79 ;
int V_60 ;
V_79 = F_35 ( V_10 , V_121 -> V_79 . V_141 . V_127 ,
V_72 ) ;
if ( ! V_79 ) {
F_65 ( & V_10 -> V_25 -> V_172 ,
L_3 ,
V_121 -> V_79 . V_141 . V_127 ) ;
return - V_4 ;
}
if ( ( V_10 -> V_25 -> V_26 -> V_27 != V_173 ) ||
( V_10 -> V_67 != V_73 ) )
goto exit;
if ( ( V_79 -> V_123 & V_174 ) &&
( V_79 -> V_12 < V_10 -> V_12 ) ) {
V_60 = F_3 ( V_10 -> V_12 ,
V_79 -> V_1 ,
& V_141 -> V_127 ,
V_10 ) ;
if ( V_60 < 0 )
V_141 -> V_127 = V_14 ;
V_79 = F_35 ( V_10 , V_141 -> V_127 ,
V_72 ) ;
}
if ( V_10 -> V_12 == V_15 &&
( V_10 -> V_78 . V_103 & 1 ) &&
( V_141 -> V_127 == V_175 ||
V_141 -> V_127 == V_176 ||
V_141 -> V_127 == V_177 ) ) {
V_141 -> V_127 = V_69 ;
V_79 = F_35 ( V_10 , V_141 -> V_127 ,
V_72 ) ;
}
exit:
return F_63 ( V_121 , V_79 , V_10 , V_72 ) ;
}
static int F_66 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
struct V_57 * V_79 ;
V_79 = F_35 ( V_10 , V_121 -> V_79 . V_141 . V_127 ,
V_70 ) ;
if ( ! V_79 ) {
F_65 ( & V_10 -> V_25 -> V_172 ,
L_3 ,
V_121 -> V_79 . V_141 . V_127 ) ;
return - V_4 ;
}
return F_63 ( V_121 , V_79 , V_10 , V_70 ) ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_136 * V_121 ,
int V_178 )
{
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
T_1 V_179 = V_121 -> V_79 . V_141 . V_127 ;
int V_103 = V_141 -> V_95 , V_104 = V_141 -> V_94 , V_180 ;
if ( V_179 == V_181 ||
V_179 == V_182 ||
V_179 == V_183 ||
V_179 == V_175 ||
V_179 == V_176 ||
V_179 == V_177 )
V_180 = 4 ;
else
V_180 = 1 ;
F_61 ( & V_103 , V_165 ,
V_166 , V_180 ,
& V_104 , V_167 ,
V_168 , V_180 ) ;
return V_103 * V_104 * V_178 >> 3 ;
}
static int F_68 ( struct V_9 * V_142 , struct V_136 * V_121 )
{
struct V_137 * V_138 ;
struct V_89 * V_139 = NULL ;
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
struct V_19 * V_184 ;
unsigned int V_185 ;
V_138 = F_59 ( V_142 -> V_24 . V_75 , V_121 -> type ) ;
if ( ! V_138 )
return - V_4 ;
V_139 = F_57 ( V_142 , V_121 -> type ) ;
F_60 ( V_139 == NULL ) ;
if ( F_69 ( V_138 ) ) {
F_65 ( & V_142 -> V_25 -> V_172 , L_4 , V_186 ) ;
return - V_187 ;
}
V_185 = F_70 ( V_121 -> type ) ?
V_70 : V_72 ;
V_139 -> V_79 = F_35 ( V_142 , V_141 -> V_127 , V_185 ) ;
V_139 -> V_103 = V_141 -> V_95 ;
V_139 -> V_104 = V_141 -> V_94 ;
if ( V_139 -> V_79 -> V_1 != V_71 ) {
if ( V_142 -> V_25 -> V_26 -> V_27 == V_173 &&
V_185 == V_70 && V_142 -> V_67 == V_68 )
V_139 -> V_84 = F_67 ( V_142 ,
V_121 ,
V_139 -> V_79 -> V_149 ) ;
else
V_139 -> V_84 = V_139 -> V_103 * V_139 -> V_104 *
V_139 -> V_79 -> V_149 >> 3 ;
} else {
V_139 -> V_84 = V_141 -> V_150 ;
}
if ( V_185 == V_70 ) {
V_184 = F_71 ( & V_142 -> V_22 ,
V_188 ) ;
if ( V_184 )
F_72 ( V_184 , V_139 -> V_79 -> V_12 ) ;
}
return 0 ;
}
static int F_73 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
int V_60 ;
V_60 = F_64 ( V_53 , V_106 , V_121 ) ;
if ( V_60 )
return V_60 ;
return F_68 ( F_6 ( V_106 ) , V_121 ) ;
}
static int F_74 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
int V_60 ;
V_60 = F_66 ( V_53 , V_106 , V_121 ) ;
if ( V_60 )
return V_60 ;
return F_68 ( F_6 ( V_106 ) , V_121 ) ;
}
static int F_75 ( struct V_53 * V_53 , void * V_106 ,
struct V_189 * V_190 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
if ( V_190 -> type != V_134 &&
V_190 -> type != V_135 )
return - V_4 ;
switch ( V_190 -> V_191 ) {
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_190 -> V_197 . V_95 = V_10 -> V_78 . V_103 ;
V_190 -> V_197 . V_94 = V_10 -> V_78 . V_104 ;
break;
case V_198 :
case V_199 :
V_190 -> V_197 . V_95 = V_10 -> V_80 . V_103 ;
V_190 -> V_197 . V_94 = V_10 -> V_80 . V_104 ;
break;
default:
return - V_4 ;
}
V_190 -> V_197 . V_200 = 0 ;
V_190 -> V_197 . V_201 = 0 ;
return 0 ;
}
static int F_76 ( struct V_19 * V_202 )
{
struct V_9 * V_10 = F_4 ( V_202 ) ;
struct V_54 * V_25 = V_10 -> V_25 ;
unsigned long V_123 ;
switch ( V_202 -> V_203 ) {
case V_188 :
F_77 ( & V_25 -> V_204 , V_123 ) ;
V_202 -> V_205 = F_7 ( V_10 ) ;
F_78 ( & V_25 -> V_204 , V_123 ) ;
break;
}
return 0 ;
}
static int F_79 ( struct V_19 * V_202 )
{
struct V_9 * V_10 = F_4 ( V_202 ) ;
unsigned long V_123 ;
int V_60 = 0 ;
F_77 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
if ( V_202 -> V_203 == V_188 ) {
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
goto V_206;
if ( V_10 -> V_78 . V_79 -> V_1 != V_14 &&
V_202 -> V_205 == V_13 ) {
V_60 = - V_4 ;
goto V_206;
}
if ( V_10 -> V_78 . V_79 -> V_12 > V_202 -> V_205 )
V_202 -> V_205 = V_10 -> V_78 . V_79 -> V_12 ;
}
V_206:
F_78 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
return V_60 ;
}
static int F_80 ( struct V_19 * V_202 )
{
struct V_9 * V_10 = F_4 ( V_202 ) ;
unsigned long V_123 ;
F_77 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
switch ( V_202 -> V_203 ) {
case V_207 :
V_10 -> V_208 = V_202 -> V_205 ;
break;
case V_209 :
V_10 -> V_210 = V_202 -> V_205 ;
break;
case V_188 :
V_10 -> V_12 = V_202 -> V_205 ;
break;
}
F_78 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
return 0 ;
}
static int F_39 ( struct V_9 * V_10 )
{
unsigned int V_211 = ~ 0x27 ;
struct V_19 * V_202 ;
int V_60 ;
F_81 ( & V_10 -> V_22 , 3 ) ;
if ( V_10 -> V_67 == V_68 ) {
F_82 ( & V_10 -> V_22 , & V_212 ,
V_207 ,
0 , 3 , 1 , V_213 ) ;
F_82 ( & V_10 -> V_22 , & V_212 ,
V_209 ,
0 , 3 , 0xffff , 0 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_211 = ~ 0x06 ;
}
V_202 = F_83 ( & V_10 -> V_22 , & V_212 ,
V_188 ,
V_13 , V_211 ,
V_17 ) ;
if ( V_10 -> V_22 . error ) {
V_60 = V_10 -> V_22 . error ;
goto V_206;
}
if ( V_10 -> V_67 == V_73 )
V_202 -> V_123 |= V_214 |
V_215 ;
V_60 = F_84 ( & V_10 -> V_22 ) ;
if ( V_60 < 0 )
goto V_206;
return V_60 ;
V_206:
F_47 ( & V_10 -> V_22 ) ;
return V_60 ;
}
static void F_85 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_216 * V_217 , * V_218 ;
unsigned long V_219 , V_220 , V_123 ;
F_77 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
V_217 = F_86 ( V_10 -> V_24 . V_75 ) ;
V_218 = F_87 ( V_10 -> V_24 . V_75 ) ;
V_219 = F_88 ( V_217 , 0 ) ;
V_220 = F_88 ( V_218 , 0 ) ;
F_89 ( V_25 -> V_30 ) ;
F_90 ( V_25 -> V_30 ) ;
F_91 ( V_25 -> V_30 , V_10 -> V_67 ) ;
if ( V_10 -> V_67 == V_68 ) {
if ( V_10 -> V_78 . V_79 -> V_1 == V_69 )
F_92 ( V_25 -> V_30 ,
V_221 ) ;
else
F_92 ( V_25 -> V_30 ,
V_222 ) ;
F_93 ( V_25 -> V_30 , V_10 -> V_12 ) ;
F_94 ( V_25 -> V_30 , V_10 -> V_210 ) ;
F_95 ( V_25 -> V_30 , V_10 -> V_78 . V_103 ) ;
F_96 ( V_25 -> V_30 , V_10 -> V_78 . V_104 ) ;
F_97 ( V_25 -> V_30 , V_219 ) ;
F_98 ( V_25 -> V_30 , V_220 ) ;
F_99 ( V_25 -> V_30 , V_10 -> V_80 . V_84 ) ;
F_100 ( V_25 -> V_30 , 1 , 1 , V_223 ) ;
F_100 ( V_25 -> V_30 , 1 , 2 , V_224 ) ;
F_100 ( V_25 -> V_30 , 1 , 3 , V_225 ) ;
F_100 ( V_25 -> V_30 , 2 , 1 , V_226 ) ;
F_100 ( V_25 -> V_30 , 2 , 2 , V_227 ) ;
F_100 ( V_25 -> V_30 , 2 , 3 , V_228 ) ;
F_100 ( V_25 -> V_30 , 3 , 1 , V_229 ) ;
F_100 ( V_25 -> V_30 , 3 , 2 , V_230 ) ;
F_100 ( V_25 -> V_30 , 3 , 3 , V_231 ) ;
F_11 ( V_25 -> V_30 , V_10 -> V_208 ) ;
F_13 ( V_25 -> V_30 , V_10 -> V_208 ) ;
F_101 ( V_25 -> V_30 , 1 , 0 ) ;
F_101 ( V_25 -> V_30 , 2 , 1 ) ;
F_101 ( V_25 -> V_30 , 3 , 1 ) ;
F_102 ( V_25 -> V_30 , 1 ) ;
F_103 ( V_25 -> V_30 , 1 ) ;
F_102 ( V_25 -> V_30 , 2 ) ;
F_103 ( V_25 -> V_30 , 2 ) ;
F_102 ( V_25 -> V_30 , 3 ) ;
F_103 ( V_25 -> V_30 , 3 ) ;
} else {
F_104 ( V_25 -> V_30 , true ) ;
F_105 ( V_25 -> V_30 , true ) ;
F_106 ( V_25 -> V_30 , true ) ;
if ( V_10 -> V_80 . V_79 -> V_1 == V_74 )
F_107 ( V_25 -> V_30 , V_232 ) ;
else
F_107 ( V_25 -> V_30 , V_233 ) ;
F_98 ( V_25 -> V_30 , V_219 ) ;
F_97 ( V_25 -> V_30 , V_220 ) ;
}
F_108 ( V_25 -> V_30 ) ;
F_78 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_57 * V_79 ;
struct V_216 * V_234 ;
struct V_235 V_236 ;
T_1 V_237 , V_238 = 0 ;
V_237 = V_10 -> V_80 . V_103 * V_10 -> V_80 . V_104 ;
if ( V_10 -> V_67 == V_68 ) {
V_234 = F_86 ( V_10 -> V_24 . V_75 ) ;
V_79 = V_10 -> V_78 . V_79 ;
if ( V_10 -> V_78 . V_103 % 2 && V_79 -> V_169 > 0 )
V_238 = V_10 -> V_78 . V_104 ;
} else {
V_79 = V_10 -> V_80 . V_79 ;
V_234 = F_87 ( V_10 -> V_24 . V_75 ) ;
}
V_236 . V_239 = F_88 ( V_234 , 0 ) ;
if ( V_79 -> V_148 == 2 ) {
V_236 . V_240 = V_236 . V_239 + V_237 - V_238 ;
} else if ( V_79 -> V_148 == 3 ) {
V_236 . V_240 = V_236 . V_239 + V_237 ;
if ( V_79 -> V_1 == V_177 )
V_236 . V_241 = V_236 . V_240 + V_237 / 4 ;
else
V_236 . V_241 = V_236 . V_240 + V_237 / 2 ;
}
F_110 ( V_25 -> V_30 , & V_236 ) ;
}
static void F_111 ( struct V_9 * V_10 )
{
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_216 * V_234 ;
unsigned int V_236 = 0 ;
if ( V_10 -> V_67 == V_68 )
V_234 = F_87 ( V_10 -> V_24 . V_75 ) ;
else
V_234 = F_86 ( V_10 -> V_24 . V_75 ) ;
V_236 = F_88 ( V_234 , 0 ) ;
F_112 ( V_25 -> V_30 , V_236 ) ;
}
static void F_113 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
struct V_54 * V_25 = V_10 -> V_25 ;
unsigned int V_242 ;
unsigned long V_123 ;
F_77 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
if ( V_10 -> V_67 == V_68 ) {
F_114 ( V_25 -> V_30 ) ;
F_115 ( V_25 -> V_30 ) ;
F_116 ( V_25 -> V_30 , 1 ) ;
F_27 ( V_25 -> V_30 ) ;
F_24 ( V_25 -> V_30 , V_10 -> V_208 ) ;
F_26 ( V_25 -> V_30 , V_10 -> V_208 ) ;
F_117 ( V_25 -> V_30 ,
V_10 -> V_208 ) ;
F_118 ( V_25 -> V_30 , V_10 -> V_80 . V_103 ,
V_10 -> V_80 . V_104 ) ;
F_119 ( V_25 -> V_30 , V_10 -> V_12 ) ;
F_120 ( V_25 -> V_30 , V_10 -> V_78 . V_79 -> V_1 ) ;
F_109 ( V_10 ) ;
F_111 ( V_10 ) ;
F_121 ( V_25 -> V_30 ,
V_10 -> V_78 . V_79 -> V_1 ) ;
} else {
F_114 ( V_25 -> V_30 ) ;
F_115 ( V_25 -> V_30 ) ;
F_109 ( V_10 ) ;
F_111 ( V_10 ) ;
F_120 ( V_25 -> V_30 , V_10 -> V_80 . V_79 -> V_1 ) ;
V_242 = F_122 ( V_10 -> V_78 . V_84 , 32 ) ;
F_123 ( V_25 -> V_30 , V_242 ) ;
}
F_124 ( V_25 -> V_30 , V_10 -> V_67 ) ;
F_78 ( & V_10 -> V_25 -> V_204 , V_123 ) ;
}
static int F_125 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
if ( V_10 -> V_67 == V_73 )
return V_10 -> V_143 ;
return 1 ;
}
static void F_126 ( void * V_106 )
{
}
static int F_127 ( struct V_137 * V_138 ,
const struct V_136 * V_79 ,
unsigned int * V_243 , unsigned int * V_244 ,
unsigned int V_245 [] , void * V_246 [] )
{
struct V_9 * V_10 = F_128 ( V_138 ) ;
struct V_89 * V_139 = NULL ;
unsigned int V_84 , V_247 = * V_243 ;
V_139 = F_57 ( V_10 , V_138 -> type ) ;
F_60 ( V_139 == NULL ) ;
V_84 = V_139 -> V_84 ;
if ( V_10 -> V_67 == V_73 )
V_247 = 1 ;
* V_243 = V_247 ;
* V_244 = 1 ;
V_245 [ 0 ] = V_84 ;
V_246 [ 0 ] = V_10 -> V_25 -> V_248 ;
return 0 ;
}
static int F_129 ( struct V_216 * V_234 )
{
struct V_9 * V_10 = F_128 ( V_234 -> V_137 ) ;
struct V_89 * V_139 = NULL ;
V_139 = F_57 ( V_10 , V_234 -> V_137 -> type ) ;
F_60 ( V_139 == NULL ) ;
if ( F_130 ( V_234 , 0 ) < V_139 -> V_84 ) {
F_131 ( L_5 ,
V_186 , F_130 ( V_234 , 0 ) ,
( long ) V_139 -> V_84 ) ;
return - V_4 ;
}
F_132 ( V_234 , 0 , V_139 -> V_84 ) ;
return 0 ;
}
static void F_133 ( struct V_216 * V_234 )
{
struct V_9 * V_10 = F_128 ( V_234 -> V_137 ) ;
if ( V_10 -> V_67 == V_73 &&
V_234 -> V_137 -> type == V_134 ) {
struct V_89 V_249 , * V_139 ;
V_10 -> V_143 = F_51 ( & V_249 ,
( unsigned long ) F_134 ( V_234 , 0 ) ,
F_135 ( ( unsigned long ) V_10 -> V_78 . V_84 ,
F_136 ( V_234 , 0 ) ) , V_10 ) ;
if ( ! V_10 -> V_143 ) {
F_137 ( V_234 , V_250 ) ;
return;
}
V_139 = & V_10 -> V_78 ;
V_139 -> V_103 = V_249 . V_103 ;
V_139 -> V_104 = V_249 . V_104 ;
V_139 = & V_10 -> V_80 ;
V_139 -> V_103 = V_249 . V_103 ;
V_139 -> V_104 = V_249 . V_104 ;
}
F_138 ( V_10 -> V_24 . V_75 , V_234 ) ;
}
static int F_139 ( struct V_137 * V_251 , unsigned int V_247 )
{
struct V_9 * V_10 = F_128 ( V_251 ) ;
int V_60 ;
V_60 = F_140 ( V_10 -> V_25 -> V_252 ) ;
return V_60 > 0 ? 0 : V_60 ;
}
static void F_141 ( struct V_137 * V_251 )
{
struct V_9 * V_10 = F_128 ( V_251 ) ;
F_142 ( V_10 -> V_25 -> V_252 ) ;
}
static int V_77 ( void * V_106 , struct V_137 * V_253 ,
struct V_137 * V_254 )
{
struct V_9 * V_10 = V_106 ;
int V_60 ;
V_253 -> type = V_134 ;
V_253 -> V_255 = V_256 | V_257 ;
V_253 -> V_258 = V_10 ;
V_253 -> V_259 = sizeof( struct V_260 ) ;
V_253 -> V_261 = & V_262 ;
V_253 -> V_263 = & V_264 ;
V_253 -> V_265 = V_266 ;
V_253 -> V_63 = & V_10 -> V_25 -> V_63 ;
V_60 = F_143 ( V_253 ) ;
if ( V_60 )
return V_60 ;
V_254 -> type = V_135 ;
V_254 -> V_255 = V_256 | V_257 ;
V_254 -> V_258 = V_10 ;
V_254 -> V_259 = sizeof( struct V_260 ) ;
V_254 -> V_261 = & V_262 ;
V_254 -> V_263 = & V_264 ;
V_254 -> V_265 = V_266 ;
V_254 -> V_63 = & V_10 -> V_25 -> V_63 ;
return F_143 ( V_254 ) ;
}
static T_3 F_144 ( int V_267 , void * V_268 )
{
struct V_54 * V_25 = V_268 ;
struct V_9 * V_269 ;
struct V_216 * V_217 , * V_218 ;
unsigned long V_270 = 0 ;
enum V_271 V_272 = V_273 ;
bool V_274 = false ;
bool V_275 = false ;
bool V_276 = false ;
F_145 ( & V_25 -> V_204 ) ;
V_269 = F_146 ( V_25 -> V_76 ) ;
V_217 = F_147 ( V_269 -> V_24 . V_75 ) ;
V_218 = F_148 ( V_269 -> V_24 . V_75 ) ;
if ( V_269 -> V_67 == V_68 )
V_274 = F_149 ( V_25 -> V_30 ) ;
V_275 = F_150 ( V_25 -> V_30 ) ;
V_276 = F_151 ( V_25 -> V_30 ) ;
if ( V_269 -> V_67 == V_73 )
V_276 = V_276 &&
F_152 ( V_25 -> V_30 ) ;
if ( V_274 ) {
V_272 = V_250 ;
F_153 ( V_25 -> V_30 ) ;
} else if ( V_275 ) {
V_272 = V_250 ;
F_154 ( V_25 -> V_30 ) ;
} else if ( ! V_276 ) {
V_272 = V_250 ;
} else {
V_270 = F_155 ( V_25 -> V_30 ) ;
}
V_218 -> V_277 . V_278 = V_217 -> V_277 . V_278 ;
V_218 -> V_277 . V_279 = V_217 -> V_277 . V_279 ;
V_218 -> V_277 . V_123 &= ~ V_280 ;
V_218 -> V_277 . V_123 |=
V_217 -> V_277 . V_123 & V_280 ;
F_156 ( V_217 , V_272 ) ;
if ( V_269 -> V_67 == V_68 )
F_132 ( V_218 , 0 , V_270 ) ;
F_156 ( V_218 , V_272 ) ;
F_157 ( V_25 -> V_76 , V_269 -> V_24 . V_75 ) ;
V_269 -> V_12 = F_158 ( V_25 -> V_30 ) ;
F_159 ( & V_25 -> V_204 ) ;
F_160 ( V_25 -> V_30 ) ;
return V_281 ;
}
static T_3 F_161 ( int V_267 , void * V_106 )
{
unsigned int V_282 ;
struct V_216 * V_283 , * V_284 ;
struct V_54 * V_25 = V_106 ;
struct V_9 * V_269 ;
unsigned long V_270 = 0 ;
F_145 ( & V_25 -> V_204 ) ;
V_269 = F_146 ( V_25 -> V_76 ) ;
V_283 = F_147 ( V_269 -> V_24 . V_75 ) ;
V_284 = F_148 ( V_269 -> V_24 . V_75 ) ;
V_282 = F_162 ( V_25 -> V_30 ) ;
if ( V_282 ) {
switch ( V_282 & 0x1f ) {
case 0x1 :
V_25 -> V_285 = V_286 ;
break;
case 0x2 :
V_25 -> V_285 = V_287 ;
break;
case 0x4 :
V_25 -> V_285 = V_288 ;
break;
case 0x8 :
V_25 -> V_285 = V_289 ;
break;
case 0x10 :
V_25 -> V_285 = V_290 ;
break;
default:
V_25 -> V_285 = V_291 ;
break;
}
} else {
V_25 -> V_285 = V_291 ;
}
if ( V_25 -> V_285 == V_287 ) {
if ( V_269 -> V_67 == V_68 ) {
V_270 = F_163 ( V_25 -> V_30 ) ;
F_132 ( V_284 , 0 , V_270 ) ;
}
F_156 ( V_283 , V_273 ) ;
F_156 ( V_284 , V_273 ) ;
} else {
F_156 ( V_283 , V_250 ) ;
F_156 ( V_284 , V_250 ) ;
}
F_157 ( V_25 -> V_76 , V_269 -> V_24 . V_75 ) ;
V_269 -> V_12 = F_164 ( V_25 -> V_30 ) ;
F_159 ( & V_25 -> V_204 ) ;
return V_281 ;
}
static int F_165 ( struct V_292 * V_293 )
{
struct V_54 * V_25 ;
struct V_294 * V_295 ;
int V_60 ;
V_25 = F_166 ( & V_293 -> V_252 , sizeof( struct V_54 ) , V_61 ) ;
if ( ! V_25 )
return - V_62 ;
V_25 -> V_26 = F_167 ( & V_293 -> V_252 ) ;
F_168 ( & V_25 -> V_63 ) ;
F_169 ( & V_25 -> V_204 ) ;
V_25 -> V_252 = & V_293 -> V_252 ;
V_295 = F_170 ( V_293 , V_296 , 0 ) ;
V_25 -> V_30 = F_171 ( & V_293 -> V_252 , V_295 ) ;
if ( F_37 ( V_25 -> V_30 ) )
return F_38 ( V_25 -> V_30 ) ;
V_25 -> V_267 = V_60 = F_172 ( V_293 , 0 ) ;
if ( V_60 < 0 ) {
F_173 ( & V_293 -> V_252 , L_6 ) ;
return V_60 ;
}
V_60 = F_174 ( & V_293 -> V_252 , V_25 -> V_267 , V_25 -> V_26 -> V_297 ,
0 , F_175 ( & V_293 -> V_252 ) , V_25 ) ;
if ( V_60 ) {
F_173 ( & V_293 -> V_252 , L_7 , V_25 -> V_267 ) ;
return V_60 ;
}
V_25 -> V_298 = F_176 ( & V_293 -> V_252 , L_8 ) ;
if ( F_37 ( V_25 -> V_298 ) ) {
F_173 ( & V_293 -> V_252 , L_9 ) ;
V_60 = F_38 ( V_25 -> V_298 ) ;
return V_60 ;
}
F_177 ( & V_293 -> V_252 , L_10 , V_25 -> V_298 ) ;
V_60 = F_178 ( & V_293 -> V_252 , & V_25 -> V_172 ) ;
if ( V_60 ) {
F_173 ( & V_293 -> V_252 , L_11 ) ;
goto V_299;
}
V_25 -> V_76 = F_179 ( V_25 -> V_26 -> V_300 ) ;
if ( F_37 ( V_25 -> V_76 ) ) {
F_65 ( & V_25 -> V_172 , L_12 ) ;
V_60 = F_38 ( V_25 -> V_76 ) ;
goto V_301;
}
V_25 -> V_248 = F_180 ( & V_293 -> V_252 ) ;
if ( F_37 ( V_25 -> V_248 ) ) {
F_65 ( & V_25 -> V_172 , L_13 ) ;
V_60 = F_38 ( V_25 -> V_248 ) ;
goto V_302;
}
V_25 -> V_66 = F_181 () ;
if ( ! V_25 -> V_66 ) {
F_65 ( & V_25 -> V_172 , L_14 ) ;
V_60 = - V_62 ;
goto V_303;
}
snprintf ( V_25 -> V_66 -> V_126 , sizeof( V_25 -> V_66 -> V_126 ) ,
L_15 , V_110 ) ;
V_25 -> V_66 -> V_304 = & V_305 ;
V_25 -> V_66 -> V_306 = & V_307 ;
V_25 -> V_66 -> V_308 = - 1 ;
V_25 -> V_66 -> V_309 = V_310 ;
V_25 -> V_66 -> V_63 = & V_25 -> V_63 ;
V_25 -> V_66 -> V_172 = & V_25 -> V_172 ;
V_25 -> V_66 -> V_311 = V_312 ;
V_60 = F_182 ( V_25 -> V_66 , V_313 , - 1 ) ;
if ( V_60 ) {
F_65 ( & V_25 -> V_172 , L_16 ) ;
goto V_314;
}
F_183 ( V_25 -> V_66 , V_25 ) ;
F_184 ( & V_25 -> V_172 ,
L_17 ,
V_25 -> V_66 -> V_122 ) ;
V_25 -> V_315 = F_181 () ;
if ( ! V_25 -> V_315 ) {
F_65 ( & V_25 -> V_172 , L_14 ) ;
V_60 = - V_62 ;
goto V_316;
}
snprintf ( V_25 -> V_315 -> V_126 , sizeof( V_25 -> V_315 -> V_126 ) ,
L_18 , V_110 ) ;
V_25 -> V_315 -> V_304 = & V_305 ;
V_25 -> V_315 -> V_306 = & V_307 ;
V_25 -> V_315 -> V_308 = - 1 ;
V_25 -> V_315 -> V_309 = V_310 ;
V_25 -> V_315 -> V_63 = & V_25 -> V_63 ;
V_25 -> V_315 -> V_172 = & V_25 -> V_172 ;
V_25 -> V_315 -> V_311 = V_312 ;
V_60 = F_182 ( V_25 -> V_315 , V_313 , - 1 ) ;
if ( V_60 ) {
F_65 ( & V_25 -> V_172 , L_16 ) ;
goto V_317;
}
F_183 ( V_25 -> V_315 , V_25 ) ;
F_184 ( & V_25 -> V_172 ,
L_19 ,
V_25 -> V_315 -> V_122 ) ;
F_185 ( V_293 , V_25 ) ;
F_186 ( & V_293 -> V_252 ) ;
F_184 ( & V_25 -> V_172 , L_20 ) ;
return 0 ;
V_317:
V_310 ( V_25 -> V_315 ) ;
V_316:
F_187 ( V_25 -> V_66 ) ;
V_314:
V_310 ( V_25 -> V_66 ) ;
V_303:
F_188 ( V_25 -> V_248 ) ;
V_302:
F_189 ( V_25 -> V_76 ) ;
V_301:
F_190 ( & V_25 -> V_172 ) ;
V_299:
F_191 ( V_25 -> V_298 ) ;
return V_60 ;
}
static int F_192 ( struct V_292 * V_293 )
{
struct V_54 * V_25 = F_193 ( V_293 ) ;
F_194 ( V_25 -> V_252 ) ;
F_187 ( V_25 -> V_315 ) ;
V_310 ( V_25 -> V_315 ) ;
F_187 ( V_25 -> V_66 ) ;
V_310 ( V_25 -> V_66 ) ;
F_188 ( V_25 -> V_248 ) ;
F_189 ( V_25 -> V_76 ) ;
F_190 ( & V_25 -> V_172 ) ;
if ( ! F_195 ( & V_293 -> V_252 ) )
F_196 ( V_25 -> V_298 ) ;
F_191 ( V_25 -> V_298 ) ;
return 0 ;
}
static int F_197 ( struct V_318 * V_252 )
{
struct V_54 * V_25 = F_198 ( V_252 ) ;
F_196 ( V_25 -> V_298 ) ;
return 0 ;
}
static int F_199 ( struct V_318 * V_252 )
{
struct V_54 * V_25 = F_198 ( V_252 ) ;
unsigned long V_123 ;
int V_60 ;
V_60 = F_200 ( V_25 -> V_298 ) ;
if ( V_60 < 0 )
return V_60 ;
F_77 ( & V_25 -> V_204 , V_123 ) ;
if ( V_25 -> V_26 -> V_27 == V_28 ) {
F_15 ( V_25 -> V_30 ) ;
F_17 ( V_25 -> V_30 ) ;
F_19 ( V_25 -> V_30 ) ;
F_21 ( V_25 -> V_30 ) ;
}
F_78 ( & V_25 -> V_204 , V_123 ) ;
return 0 ;
}
static int F_201 ( struct V_318 * V_252 )
{
if ( F_202 ( V_252 ) )
return 0 ;
return F_197 ( V_252 ) ;
}
static int F_203 ( struct V_318 * V_252 )
{
if ( F_202 ( V_252 ) )
return 0 ;
return F_199 ( V_252 ) ;
}
static void * F_167 ( struct V_318 * V_252 )
{
struct V_319 * V_320 = NULL ;
const struct V_321 * V_322 ;
if ( ! F_204 ( V_323 ) || ! V_252 -> V_324 )
return & V_325 ;
V_322 = F_205 ( V_326 , V_252 -> V_324 ) ;
if ( V_322 )
V_320 = (struct V_319 * ) V_322 -> V_85 ;
return V_320 ;
}
