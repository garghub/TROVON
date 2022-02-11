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
unsigned int V_152 , V_153 , V_154 ;
if ( V_10 -> V_67 == V_68 )
V_153 = ( V_151 == V_70 ) ?
V_131 :
V_129 ;
else
V_153 = ( V_151 == V_70 ) ?
V_132 :
V_130 ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_154 = V_155 ;
else
V_154 = V_156 ;
for ( V_152 = 0 ; V_152 < F_2 ( V_118 ) ; V_152 ++ ) {
struct V_57 * V_79 = & V_118 [ V_152 ] ;
if ( V_79 -> V_1 == V_127 &&
V_79 -> V_123 & V_153 &&
V_79 -> V_123 & V_154 ) {
return V_79 ;
}
}
return NULL ;
}
static void F_61 ( T_1 * V_103 , unsigned int V_157 , unsigned int V_158 ,
unsigned int V_159 ,
T_1 * V_104 , unsigned int V_160 , unsigned int V_161 ,
unsigned int V_162 )
{
int V_95 , V_94 , V_163 , V_164 ;
V_95 = * V_103 ;
V_94 = * V_104 ;
V_163 = 1 << V_159 ;
V_164 = 1 << V_162 ;
F_62 ( V_103 , V_157 , V_158 , V_159 , V_104 , V_160 , V_161 , V_162 , 0 ) ;
if ( * V_103 < V_95 && ( * V_103 + V_163 ) < V_158 )
* V_103 += V_163 ;
if ( * V_104 < V_94 && ( * V_104 + V_164 ) < V_161 )
* V_104 += V_164 ;
}
static int F_63 ( struct V_136 * V_121 , struct V_57 * V_79 ,
struct V_9 * V_10 , int V_165 )
{
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
if ( V_141 -> V_144 == V_166 )
V_141 -> V_144 = V_145 ;
else if ( V_141 -> V_144 != V_145 )
return - V_4 ;
if ( V_165 == V_70 )
F_61 ( & V_141 -> V_95 , V_167 ,
V_168 , 0 ,
& V_141 -> V_94 , V_169 ,
V_170 , 0 ) ;
else
F_61 ( & V_141 -> V_95 , V_167 ,
V_168 , V_79 -> V_171 ,
& V_141 -> V_94 , V_169 ,
V_170 , V_79 -> V_172 ) ;
if ( V_79 -> V_1 == V_71 ) {
if ( V_141 -> V_150 <= 0 )
V_141 -> V_150 = V_173 ;
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
F_65 ( & V_10 -> V_25 -> V_174 ,
L_3 ,
V_121 -> V_79 . V_141 . V_127 ) ;
return - V_4 ;
}
if ( ( V_10 -> V_25 -> V_26 -> V_27 != V_28 ) &&
( V_10 -> V_67 == V_73 ) &&
( V_79 -> V_123 & V_175 ) &&
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
F_65 ( & V_10 -> V_25 -> V_174 ,
L_3 ,
V_121 -> V_79 . V_141 . V_127 ) ;
return - V_4 ;
}
return F_63 ( V_121 , V_79 , V_10 , V_70 ) ;
}
static int F_67 ( struct V_9 * V_142 , struct V_136 * V_121 )
{
struct V_137 * V_138 ;
struct V_89 * V_139 = NULL ;
struct V_140 * V_141 = & V_121 -> V_79 . V_141 ;
struct V_19 * V_176 ;
unsigned int V_177 ;
V_138 = F_59 ( V_142 -> V_24 . V_75 , V_121 -> type ) ;
if ( ! V_138 )
return - V_4 ;
V_139 = F_57 ( V_142 , V_121 -> type ) ;
F_60 ( V_139 == NULL ) ;
if ( F_68 ( V_138 ) ) {
F_65 ( & V_142 -> V_25 -> V_174 , L_4 , V_178 ) ;
return - V_179 ;
}
V_177 = F_69 ( V_121 -> type ) ?
V_70 : V_72 ;
V_139 -> V_79 = F_35 ( V_142 , V_141 -> V_127 , V_177 ) ;
V_139 -> V_103 = V_141 -> V_95 ;
V_139 -> V_104 = V_141 -> V_94 ;
if ( V_139 -> V_79 -> V_1 != V_71 )
V_139 -> V_84 = V_139 -> V_103 * V_139 -> V_104 * V_139 -> V_79 -> V_149 >> 3 ;
else
V_139 -> V_84 = V_141 -> V_150 ;
if ( V_177 == V_70 ) {
V_176 = F_70 ( & V_142 -> V_22 ,
V_180 ) ;
if ( V_176 )
F_71 ( V_176 , V_139 -> V_79 -> V_12 ) ;
}
return 0 ;
}
static int F_72 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
int V_60 ;
V_60 = F_64 ( V_53 , V_106 , V_121 ) ;
if ( V_60 )
return V_60 ;
return F_67 ( F_6 ( V_106 ) , V_121 ) ;
}
static int F_73 ( struct V_53 * V_53 , void * V_106 ,
struct V_136 * V_121 )
{
int V_60 ;
V_60 = F_66 ( V_53 , V_106 , V_121 ) ;
if ( V_60 )
return V_60 ;
return F_67 ( F_6 ( V_106 ) , V_121 ) ;
}
static int F_74 ( struct V_53 * V_53 , void * V_106 ,
struct V_181 * V_182 )
{
struct V_9 * V_10 = F_6 ( V_106 ) ;
if ( V_182 -> type != V_134 &&
V_182 -> type != V_135 &&
V_10 -> V_25 -> V_26 -> V_27 != V_28 )
return - V_4 ;
switch ( V_182 -> V_183 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
V_182 -> V_189 . V_95 = V_10 -> V_78 . V_103 ;
V_182 -> V_189 . V_94 = V_10 -> V_78 . V_104 ;
break;
case V_190 :
case V_191 :
V_182 -> V_189 . V_95 = V_10 -> V_80 . V_103 ;
V_182 -> V_189 . V_94 = V_10 -> V_80 . V_104 ;
break;
default:
return - V_4 ;
}
V_182 -> V_189 . V_192 = 0 ;
V_182 -> V_189 . V_193 = 0 ;
return 0 ;
}
static int F_75 ( struct V_19 * V_194 )
{
struct V_9 * V_10 = F_4 ( V_194 ) ;
struct V_54 * V_25 = V_10 -> V_25 ;
unsigned long V_123 ;
switch ( V_194 -> V_195 ) {
case V_180 :
F_76 ( & V_25 -> V_196 , V_123 ) ;
V_194 -> V_197 = F_7 ( V_10 ) ;
F_77 ( & V_25 -> V_196 , V_123 ) ;
break;
}
return 0 ;
}
static int F_78 ( struct V_19 * V_194 )
{
struct V_9 * V_10 = F_4 ( V_194 ) ;
unsigned long V_123 ;
int V_60 = 0 ;
F_76 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
if ( V_194 -> V_195 == V_180 ) {
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
goto V_198;
if ( V_10 -> V_78 . V_79 -> V_1 != V_14 &&
V_194 -> V_197 == V_13 ) {
V_60 = - V_4 ;
goto V_198;
}
if ( V_10 -> V_78 . V_79 -> V_12 > V_194 -> V_197 )
V_194 -> V_197 = V_10 -> V_78 . V_79 -> V_12 ;
}
V_198:
F_77 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
return V_60 ;
}
static int F_79 ( struct V_19 * V_194 )
{
struct V_9 * V_10 = F_4 ( V_194 ) ;
unsigned long V_123 ;
F_76 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
switch ( V_194 -> V_195 ) {
case V_199 :
V_10 -> V_200 = V_194 -> V_197 ;
break;
case V_201 :
V_10 -> V_202 = V_194 -> V_197 ;
break;
case V_180 :
V_10 -> V_12 = V_194 -> V_197 ;
break;
}
F_77 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
return 0 ;
}
static int F_39 ( struct V_9 * V_10 )
{
unsigned int V_203 = ~ 0x27 ;
struct V_19 * V_194 ;
int V_60 ;
F_80 ( & V_10 -> V_22 , 3 ) ;
if ( V_10 -> V_67 == V_68 ) {
F_81 ( & V_10 -> V_22 , & V_204 ,
V_199 ,
0 , 3 , 1 , V_205 ) ;
F_81 ( & V_10 -> V_22 , & V_204 ,
V_201 ,
0 , 3 , 0xffff , 0 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_203 = ~ 0x06 ;
}
V_194 = F_82 ( & V_10 -> V_22 , & V_204 ,
V_180 ,
V_13 , V_203 ,
V_17 ) ;
if ( V_10 -> V_22 . error ) {
V_60 = V_10 -> V_22 . error ;
goto V_198;
}
if ( V_10 -> V_67 == V_73 )
V_194 -> V_123 |= V_206 |
V_207 ;
V_60 = F_83 ( & V_10 -> V_22 ) ;
if ( V_60 < 0 )
goto V_198;
return V_60 ;
V_198:
F_47 ( & V_10 -> V_22 ) ;
return V_60 ;
}
static void F_84 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_208 * V_209 , * V_210 ;
unsigned long V_211 , V_212 , V_123 ;
F_76 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
V_209 = F_85 ( V_10 -> V_24 . V_75 ) ;
V_210 = F_86 ( V_10 -> V_24 . V_75 ) ;
V_211 = F_87 ( V_209 , 0 ) ;
V_212 = F_87 ( V_210 , 0 ) ;
F_88 ( V_25 -> V_30 ) ;
F_89 ( V_25 -> V_30 ) ;
F_90 ( V_25 -> V_30 , V_10 -> V_67 ) ;
if ( V_10 -> V_67 == V_68 ) {
if ( V_10 -> V_78 . V_79 -> V_1 == V_69 )
F_91 ( V_25 -> V_30 ,
V_213 ) ;
else
F_91 ( V_25 -> V_30 ,
V_214 ) ;
F_92 ( V_25 -> V_30 , V_10 -> V_12 ) ;
F_93 ( V_25 -> V_30 , V_10 -> V_202 ) ;
F_94 ( V_25 -> V_30 , V_10 -> V_78 . V_103 ) ;
F_95 ( V_25 -> V_30 , V_10 -> V_78 . V_104 ) ;
F_96 ( V_25 -> V_30 , V_211 ) ;
F_97 ( V_25 -> V_30 , V_212 ) ;
F_98 ( V_25 -> V_30 , V_10 -> V_80 . V_84 ) ;
F_99 ( V_25 -> V_30 , 1 , 1 , V_215 ) ;
F_99 ( V_25 -> V_30 , 1 , 2 , V_216 ) ;
F_99 ( V_25 -> V_30 , 1 , 3 , V_217 ) ;
F_99 ( V_25 -> V_30 , 2 , 1 , V_218 ) ;
F_99 ( V_25 -> V_30 , 2 , 2 , V_219 ) ;
F_99 ( V_25 -> V_30 , 2 , 3 , V_220 ) ;
F_99 ( V_25 -> V_30 , 3 , 1 , V_221 ) ;
F_99 ( V_25 -> V_30 , 3 , 2 , V_222 ) ;
F_99 ( V_25 -> V_30 , 3 , 3 , V_223 ) ;
F_11 ( V_25 -> V_30 , V_10 -> V_200 ) ;
F_13 ( V_25 -> V_30 , V_10 -> V_200 ) ;
F_100 ( V_25 -> V_30 , 1 , 0 ) ;
F_100 ( V_25 -> V_30 , 2 , 1 ) ;
F_100 ( V_25 -> V_30 , 3 , 1 ) ;
F_101 ( V_25 -> V_30 , 1 ) ;
F_102 ( V_25 -> V_30 , 1 ) ;
F_101 ( V_25 -> V_30 , 2 ) ;
F_102 ( V_25 -> V_30 , 2 ) ;
F_101 ( V_25 -> V_30 , 3 ) ;
F_102 ( V_25 -> V_30 , 3 ) ;
} else {
F_103 ( V_25 -> V_30 , true ) ;
F_104 ( V_25 -> V_30 , true ) ;
F_105 ( V_25 -> V_30 , true ) ;
if ( V_10 -> V_80 . V_79 -> V_1 == V_74 )
F_106 ( V_25 -> V_30 , V_224 ) ;
else
F_106 ( V_25 -> V_30 , V_225 ) ;
F_97 ( V_25 -> V_30 , V_211 ) ;
F_96 ( V_25 -> V_30 , V_212 ) ;
}
F_107 ( V_25 -> V_30 ) ;
F_77 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_57 * V_79 ;
struct V_208 * V_226 ;
struct V_227 V_228 ;
T_1 V_229 , V_230 = 0 ;
V_229 = V_10 -> V_80 . V_103 * V_10 -> V_80 . V_104 ;
if ( V_10 -> V_67 == V_68 ) {
V_226 = F_85 ( V_10 -> V_24 . V_75 ) ;
V_79 = V_10 -> V_78 . V_79 ;
if ( V_10 -> V_78 . V_103 % 2 && V_79 -> V_171 > 0 )
V_230 = V_10 -> V_78 . V_104 ;
} else {
V_79 = V_10 -> V_80 . V_79 ;
V_226 = F_86 ( V_10 -> V_24 . V_75 ) ;
}
V_228 . V_231 = F_87 ( V_226 , 0 ) ;
if ( V_79 -> V_148 == 2 ) {
V_228 . V_232 = V_228 . V_231 + V_229 - V_230 ;
} else if ( V_79 -> V_148 == 3 ) {
V_228 . V_232 = V_228 . V_231 + V_229 ;
if ( V_79 -> V_1 == V_233 )
V_228 . V_234 = V_228 . V_232 + V_229 / 4 ;
else
V_228 . V_234 = V_228 . V_232 + V_229 / 2 ;
}
F_109 ( V_25 -> V_30 , & V_228 ) ;
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_54 * V_25 = V_10 -> V_25 ;
struct V_208 * V_226 ;
unsigned int V_228 = 0 ;
if ( V_10 -> V_67 == V_68 )
V_226 = F_86 ( V_10 -> V_24 . V_75 ) ;
else
V_226 = F_85 ( V_10 -> V_24 . V_75 ) ;
V_228 = F_87 ( V_226 , 0 ) ;
F_111 ( V_25 -> V_30 , V_228 ) ;
}
static void F_112 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
struct V_54 * V_25 = V_10 -> V_25 ;
unsigned int V_235 ;
unsigned long V_123 ;
F_76 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
if ( V_10 -> V_67 == V_68 ) {
F_113 ( V_25 -> V_30 ) ;
F_114 ( V_25 -> V_30 ) ;
F_115 ( V_25 -> V_30 , 1 ) ;
F_27 ( V_25 -> V_30 ) ;
F_24 ( V_25 -> V_30 , V_10 -> V_200 ) ;
F_26 ( V_25 -> V_30 , V_10 -> V_200 ) ;
F_116 ( V_25 -> V_30 ,
V_10 -> V_200 ) ;
F_117 ( V_25 -> V_30 , V_10 -> V_80 . V_103 ,
V_10 -> V_80 . V_104 ) ;
F_118 ( V_25 -> V_30 , V_10 -> V_12 ) ;
F_119 ( V_25 -> V_30 , V_10 -> V_78 . V_79 -> V_1 ) ;
F_108 ( V_10 ) ;
F_110 ( V_10 ) ;
F_120 ( V_25 -> V_30 ,
V_10 -> V_78 . V_79 -> V_1 ) ;
} else {
F_113 ( V_25 -> V_30 ) ;
F_114 ( V_25 -> V_30 ) ;
F_108 ( V_10 ) ;
F_110 ( V_10 ) ;
F_119 ( V_25 -> V_30 , V_10 -> V_80 . V_79 -> V_1 ) ;
V_235 = F_121 ( V_10 -> V_78 . V_84 , 32 ) ;
F_122 ( V_25 -> V_30 , V_235 ) ;
}
F_123 ( V_25 -> V_30 , V_10 -> V_67 ) ;
F_77 ( & V_10 -> V_25 -> V_196 , V_123 ) ;
}
static int F_124 ( void * V_106 )
{
struct V_9 * V_10 = V_106 ;
if ( V_10 -> V_67 == V_73 )
return V_10 -> V_143 ;
return 1 ;
}
static void F_125 ( void * V_106 )
{
}
static int F_126 ( struct V_137 * V_138 ,
const struct V_136 * V_79 ,
unsigned int * V_236 , unsigned int * V_237 ,
unsigned int V_238 [] , void * V_239 [] )
{
struct V_9 * V_10 = F_127 ( V_138 ) ;
struct V_89 * V_139 = NULL ;
unsigned int V_84 , V_240 = * V_236 ;
V_139 = F_57 ( V_10 , V_138 -> type ) ;
F_60 ( V_139 == NULL ) ;
V_84 = V_139 -> V_84 ;
if ( V_10 -> V_67 == V_73 )
V_240 = 1 ;
* V_236 = V_240 ;
* V_237 = 1 ;
V_238 [ 0 ] = V_84 ;
V_239 [ 0 ] = V_10 -> V_25 -> V_241 ;
return 0 ;
}
static int F_128 ( struct V_208 * V_226 )
{
struct V_9 * V_10 = F_127 ( V_226 -> V_137 ) ;
struct V_89 * V_139 = NULL ;
V_139 = F_57 ( V_10 , V_226 -> V_137 -> type ) ;
F_60 ( V_139 == NULL ) ;
if ( F_129 ( V_226 , 0 ) < V_139 -> V_84 ) {
F_130 ( L_5 ,
V_178 , F_129 ( V_226 , 0 ) ,
( long ) V_139 -> V_84 ) ;
return - V_4 ;
}
F_131 ( V_226 , 0 , V_139 -> V_84 ) ;
return 0 ;
}
static void F_132 ( struct V_208 * V_226 )
{
struct V_9 * V_10 = F_127 ( V_226 -> V_137 ) ;
if ( V_10 -> V_67 == V_73 &&
V_226 -> V_137 -> type == V_134 ) {
struct V_89 V_242 , * V_139 ;
V_10 -> V_143 = F_51 ( & V_242 ,
( unsigned long ) F_133 ( V_226 , 0 ) ,
F_134 ( ( unsigned long ) V_10 -> V_78 . V_84 ,
F_135 ( V_226 , 0 ) ) , V_10 ) ;
if ( ! V_10 -> V_143 ) {
F_136 ( V_226 , V_243 ) ;
return;
}
V_139 = & V_10 -> V_78 ;
V_139 -> V_103 = V_242 . V_103 ;
V_139 -> V_104 = V_242 . V_104 ;
V_139 = & V_10 -> V_80 ;
V_139 -> V_103 = V_242 . V_103 ;
V_139 -> V_104 = V_242 . V_104 ;
}
F_137 ( V_10 -> V_24 . V_75 , V_226 ) ;
}
static int F_138 ( struct V_137 * V_244 , unsigned int V_240 )
{
struct V_9 * V_10 = F_127 ( V_244 ) ;
int V_60 ;
V_60 = F_139 ( V_10 -> V_25 -> V_245 ) ;
return V_60 > 0 ? 0 : V_60 ;
}
static int F_140 ( struct V_137 * V_244 )
{
struct V_9 * V_10 = F_127 ( V_244 ) ;
F_141 ( V_10 -> V_25 -> V_245 ) ;
return 0 ;
}
static int V_77 ( void * V_106 , struct V_137 * V_246 ,
struct V_137 * V_247 )
{
struct V_9 * V_10 = V_106 ;
int V_60 ;
V_246 -> type = V_134 ;
V_246 -> V_248 = V_249 | V_250 ;
V_246 -> V_251 = V_10 ;
V_246 -> V_252 = sizeof( struct V_253 ) ;
V_246 -> V_254 = & V_255 ;
V_246 -> V_256 = & V_257 ;
V_246 -> V_258 = V_259 ;
V_246 -> V_63 = & V_10 -> V_25 -> V_63 ;
V_60 = F_142 ( V_246 ) ;
if ( V_60 )
return V_60 ;
V_247 -> type = V_135 ;
V_247 -> V_248 = V_249 | V_250 ;
V_247 -> V_251 = V_10 ;
V_247 -> V_252 = sizeof( struct V_253 ) ;
V_247 -> V_254 = & V_255 ;
V_247 -> V_256 = & V_257 ;
V_247 -> V_258 = V_259 ;
V_247 -> V_63 = & V_10 -> V_25 -> V_63 ;
return F_142 ( V_247 ) ;
}
static T_3 F_143 ( int V_260 , void * V_261 )
{
struct V_54 * V_25 = V_261 ;
struct V_9 * V_262 ;
struct V_208 * V_209 , * V_210 ;
unsigned long V_263 = 0 ;
enum V_264 V_265 = V_266 ;
bool V_267 = false ;
bool V_268 = false ;
bool V_269 = false ;
F_144 ( & V_25 -> V_196 ) ;
V_262 = F_145 ( V_25 -> V_76 ) ;
V_209 = F_146 ( V_262 -> V_24 . V_75 ) ;
V_210 = F_147 ( V_262 -> V_24 . V_75 ) ;
if ( V_262 -> V_67 == V_68 )
V_267 = F_148 ( V_25 -> V_30 ) ;
V_268 = F_149 ( V_25 -> V_30 ) ;
V_269 = F_150 ( V_25 -> V_30 ) ;
if ( V_262 -> V_67 == V_73 )
V_269 = V_269 &&
F_151 ( V_25 -> V_30 ) ;
if ( V_267 ) {
V_265 = V_243 ;
F_152 ( V_25 -> V_30 ) ;
} else if ( V_268 ) {
V_265 = V_243 ;
F_153 ( V_25 -> V_30 ) ;
} else if ( ! V_269 ) {
V_265 = V_243 ;
} else {
V_263 = F_154 ( V_25 -> V_30 ) ;
}
V_210 -> V_270 . V_271 = V_209 -> V_270 . V_271 ;
V_210 -> V_270 . V_272 = V_209 -> V_270 . V_272 ;
F_155 ( V_209 , V_265 ) ;
if ( V_262 -> V_67 == V_68 )
F_131 ( V_210 , 0 , V_263 ) ;
F_155 ( V_210 , V_265 ) ;
F_156 ( V_25 -> V_76 , V_262 -> V_24 . V_75 ) ;
V_262 -> V_12 = F_157 ( V_25 -> V_30 ) ;
F_158 ( & V_25 -> V_196 ) ;
F_159 ( V_25 -> V_30 ) ;
return V_273 ;
}
static T_3 F_160 ( int V_260 , void * V_106 )
{
unsigned int V_274 ;
struct V_208 * V_275 , * V_276 ;
struct V_54 * V_25 = V_106 ;
struct V_9 * V_262 ;
unsigned long V_263 = 0 ;
F_144 ( & V_25 -> V_196 ) ;
V_262 = F_145 ( V_25 -> V_76 ) ;
V_275 = F_146 ( V_262 -> V_24 . V_75 ) ;
V_276 = F_147 ( V_262 -> V_24 . V_75 ) ;
V_274 = F_161 ( V_25 -> V_30 ) ;
if ( V_274 ) {
switch ( V_274 & 0x1f ) {
case 0x1 :
V_25 -> V_277 = V_278 ;
break;
case 0x2 :
V_25 -> V_277 = V_279 ;
break;
case 0x4 :
V_25 -> V_277 = V_280 ;
break;
case 0x8 :
V_25 -> V_277 = V_281 ;
break;
case 0x10 :
V_25 -> V_277 = V_282 ;
break;
default:
V_25 -> V_277 = V_283 ;
break;
}
} else {
V_25 -> V_277 = V_283 ;
}
if ( V_25 -> V_277 == V_279 ) {
if ( V_262 -> V_67 == V_68 ) {
V_263 = F_162 ( V_25 -> V_30 ) ;
F_131 ( V_276 , 0 , V_263 ) ;
}
F_155 ( V_275 , V_266 ) ;
F_155 ( V_276 , V_266 ) ;
} else {
F_155 ( V_275 , V_243 ) ;
F_155 ( V_276 , V_243 ) ;
}
F_156 ( V_25 -> V_76 , V_262 -> V_24 . V_75 ) ;
V_262 -> V_12 = F_163 ( V_25 -> V_30 ) ;
F_158 ( & V_25 -> V_196 ) ;
return V_273 ;
}
static int F_164 ( struct V_284 * V_285 )
{
struct V_54 * V_25 ;
struct V_286 * V_287 ;
struct V_288 * V_289 ;
int V_60 ;
if ( ! V_285 -> V_245 . V_290 )
return - V_291 ;
V_25 = F_165 ( & V_285 -> V_245 , sizeof( struct V_54 ) , V_61 ) ;
if ( ! V_25 )
return - V_62 ;
V_25 -> V_26 = F_166 ( V_285 ) ;
F_167 ( & V_25 -> V_63 ) ;
F_168 ( & V_25 -> V_196 ) ;
V_25 -> V_245 = & V_285 -> V_245 ;
V_287 = F_169 ( V_285 , V_292 , 0 ) ;
V_25 -> V_30 = F_170 ( & V_285 -> V_245 , V_287 ) ;
if ( F_37 ( V_25 -> V_30 ) )
return F_38 ( V_25 -> V_30 ) ;
V_25 -> V_260 = V_60 = F_171 ( V_285 , 0 ) ;
if ( V_60 < 0 ) {
F_172 ( & V_285 -> V_245 , L_6 ) ;
return V_60 ;
}
V_60 = F_173 ( & V_285 -> V_245 , V_25 -> V_260 , V_25 -> V_26 -> V_293 ,
0 , F_174 ( & V_285 -> V_245 ) , V_25 ) ;
if ( V_60 ) {
F_172 ( & V_285 -> V_245 , L_7 , V_25 -> V_260 ) ;
return V_60 ;
}
V_25 -> V_294 = F_175 ( & V_285 -> V_245 , L_8 ) ;
if ( F_37 ( V_25 -> V_294 ) ) {
F_172 ( & V_285 -> V_245 , L_9 ) ;
V_60 = F_38 ( V_25 -> V_294 ) ;
return V_60 ;
}
F_176 ( & V_285 -> V_245 , L_10 , V_25 -> V_294 ) ;
V_60 = F_177 ( & V_285 -> V_245 , & V_25 -> V_174 ) ;
if ( V_60 ) {
F_172 ( & V_285 -> V_245 , L_11 ) ;
goto V_295;
}
if ( V_25 -> V_26 -> V_27 == V_28 )
V_289 = & V_296 ;
else
V_289 = & V_297 ;
V_25 -> V_76 = F_178 ( V_289 ) ;
if ( F_37 ( V_25 -> V_76 ) ) {
F_65 ( & V_25 -> V_174 , L_12 ) ;
V_60 = F_38 ( V_25 -> V_76 ) ;
goto V_298;
}
V_25 -> V_241 = F_179 ( & V_285 -> V_245 ) ;
if ( F_37 ( V_25 -> V_241 ) ) {
F_65 ( & V_25 -> V_174 , L_13 ) ;
V_60 = F_38 ( V_25 -> V_241 ) ;
goto V_299;
}
V_25 -> V_66 = F_180 () ;
if ( ! V_25 -> V_66 ) {
F_65 ( & V_25 -> V_174 , L_14 ) ;
V_60 = - V_62 ;
goto V_300;
}
snprintf ( V_25 -> V_66 -> V_126 , sizeof( V_25 -> V_66 -> V_126 ) ,
L_15 , V_110 ) ;
V_25 -> V_66 -> V_301 = & V_302 ;
V_25 -> V_66 -> V_303 = & V_304 ;
V_25 -> V_66 -> V_305 = - 1 ;
V_25 -> V_66 -> V_306 = V_307 ;
V_25 -> V_66 -> V_63 = & V_25 -> V_63 ;
V_25 -> V_66 -> V_174 = & V_25 -> V_174 ;
V_25 -> V_66 -> V_308 = V_309 ;
V_60 = F_181 ( V_25 -> V_66 , V_310 , - 1 ) ;
if ( V_60 ) {
F_65 ( & V_25 -> V_174 , L_16 ) ;
goto V_311;
}
F_182 ( V_25 -> V_66 , V_25 ) ;
F_183 ( & V_25 -> V_174 ,
L_17 ,
V_25 -> V_66 -> V_122 ) ;
V_25 -> V_312 = F_180 () ;
if ( ! V_25 -> V_312 ) {
F_65 ( & V_25 -> V_174 , L_14 ) ;
V_60 = - V_62 ;
goto V_313;
}
snprintf ( V_25 -> V_312 -> V_126 , sizeof( V_25 -> V_312 -> V_126 ) ,
L_18 , V_110 ) ;
V_25 -> V_312 -> V_301 = & V_302 ;
V_25 -> V_312 -> V_303 = & V_304 ;
V_25 -> V_312 -> V_305 = - 1 ;
V_25 -> V_312 -> V_306 = V_307 ;
V_25 -> V_312 -> V_63 = & V_25 -> V_63 ;
V_25 -> V_312 -> V_174 = & V_25 -> V_174 ;
V_25 -> V_312 -> V_308 = V_309 ;
V_60 = F_181 ( V_25 -> V_312 , V_310 , - 1 ) ;
if ( V_60 ) {
F_65 ( & V_25 -> V_174 , L_16 ) ;
goto V_314;
}
F_182 ( V_25 -> V_312 , V_25 ) ;
F_183 ( & V_25 -> V_174 ,
L_19 ,
V_25 -> V_312 -> V_122 ) ;
F_184 ( V_285 , V_25 ) ;
F_185 ( & V_285 -> V_245 ) ;
F_183 ( & V_25 -> V_174 , L_20 ) ;
return 0 ;
V_314:
V_307 ( V_25 -> V_312 ) ;
V_313:
F_186 ( V_25 -> V_66 ) ;
V_311:
V_307 ( V_25 -> V_66 ) ;
V_300:
F_187 ( V_25 -> V_241 ) ;
V_299:
F_188 ( V_25 -> V_76 ) ;
V_298:
F_189 ( & V_25 -> V_174 ) ;
V_295:
F_190 ( V_25 -> V_294 ) ;
return V_60 ;
}
static int F_191 ( struct V_284 * V_285 )
{
struct V_54 * V_25 = F_192 ( V_285 ) ;
F_193 ( V_25 -> V_245 ) ;
F_186 ( V_25 -> V_312 ) ;
V_307 ( V_25 -> V_312 ) ;
F_186 ( V_25 -> V_66 ) ;
V_307 ( V_25 -> V_66 ) ;
F_187 ( V_25 -> V_241 ) ;
F_188 ( V_25 -> V_76 ) ;
F_189 ( & V_25 -> V_174 ) ;
if ( ! F_194 ( & V_285 -> V_245 ) )
F_195 ( V_25 -> V_294 ) ;
F_190 ( V_25 -> V_294 ) ;
return 0 ;
}
static int F_196 ( struct V_315 * V_245 )
{
struct V_54 * V_25 = F_197 ( V_245 ) ;
F_195 ( V_25 -> V_294 ) ;
return 0 ;
}
static int F_198 ( struct V_315 * V_245 )
{
struct V_54 * V_25 = F_197 ( V_245 ) ;
unsigned long V_123 ;
int V_60 ;
V_60 = F_199 ( V_25 -> V_294 ) ;
if ( V_60 < 0 )
return V_60 ;
F_76 ( & V_25 -> V_196 , V_123 ) ;
if ( V_25 -> V_26 -> V_27 == V_28 ) {
F_15 ( V_25 -> V_30 ) ;
F_17 ( V_25 -> V_30 ) ;
F_19 ( V_25 -> V_30 ) ;
F_21 ( V_25 -> V_30 ) ;
}
F_77 ( & V_25 -> V_196 , V_123 ) ;
return 0 ;
}
static int F_200 ( struct V_315 * V_245 )
{
if ( F_201 ( V_245 ) )
return 0 ;
return F_196 ( V_245 ) ;
}
static int F_202 ( struct V_315 * V_245 )
{
if ( F_201 ( V_245 ) )
return 0 ;
return F_198 ( V_245 ) ;
}
static void * F_166 ( struct V_284 * V_285 )
{
struct V_316 * V_317 = NULL ;
const struct V_318 * V_319 ;
V_319 = F_203 ( F_204 ( V_320 ) ,
V_285 -> V_245 . V_290 ) ;
if ( V_319 )
V_317 = (struct V_316 * ) V_319 -> V_85 ;
return V_317 ;
}
