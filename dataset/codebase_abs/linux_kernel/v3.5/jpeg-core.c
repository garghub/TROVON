static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_1 , V_7 ) ;
}
static inline void F_4 ( void T_1 * V_8 , const unsigned char * V_9 ,
unsigned long V_10 , int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
F_5 ( ( unsigned int ) V_9 [ V_12 ] , V_8 + V_10 + ( V_12 * 0x04 ) ) ;
}
static inline void F_6 ( void T_1 * V_8 , int V_13 )
{
F_4 ( V_8 , V_14 [ V_13 ] , F_7 ( 0 ) ,
F_8 ( V_14 [ V_13 ] ) ) ;
}
static inline void F_9 ( void T_1 * V_8 , int V_13 )
{
F_4 ( V_8 , V_15 [ V_13 ] , F_7 ( 1 ) ,
F_8 ( V_15 [ V_13 ] ) ) ;
}
static inline void F_10 ( void T_1 * V_8 , const unsigned char * V_16 ,
unsigned long V_10 , int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
F_5 ( ( unsigned int ) V_16 [ V_12 ] , V_8 + V_10 + ( V_12 * 0x04 ) ) ;
}
static inline void F_11 ( void T_1 * V_8 )
{
F_10 ( V_8 , V_17 , F_12 ( 0 ) , F_8 ( V_17 ) ) ;
}
static inline void F_13 ( void T_1 * V_8 )
{
F_10 ( V_8 , V_18 , F_14 ( 0 ) , F_8 ( V_18 ) ) ;
}
static inline void F_15 ( void T_1 * V_8 )
{
F_10 ( V_8 , V_19 , F_16 ( 0 ) , F_8 ( V_19 ) ) ;
}
static inline void F_17 ( void T_1 * V_8 )
{
F_10 ( V_8 , V_20 , F_18 ( 0 ) , F_8 ( V_20 ) ) ;
}
static int F_19 ( struct V_21 * V_21 )
{
struct V_22 * V_23 = F_20 ( V_21 ) ;
struct V_24 * V_25 = F_21 ( V_21 ) ;
struct V_1 * V_26 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
V_26 = F_22 ( sizeof *V_26 , V_30 ) ;
if ( ! V_26 )
return - V_31 ;
F_23 ( & V_26 -> V_7 , V_25 ) ;
V_26 -> V_7 . V_5 = & V_26 -> V_5 ;
V_21 -> V_32 = & V_26 -> V_7 ;
F_24 ( & V_26 -> V_7 ) ;
V_26 -> V_23 = V_23 ;
if ( V_25 == V_23 -> V_33 ) {
V_26 -> V_34 = V_35 ;
V_28 = F_25 ( V_26 -> V_34 , V_36 ) ;
} else {
V_26 -> V_34 = V_37 ;
V_28 = F_25 ( V_26 -> V_34 , V_38 ) ;
}
V_29 = F_26 ( V_26 ) ;
if ( V_29 < 0 )
goto error;
V_26 -> V_39 = F_27 ( V_23 -> V_40 , V_26 , V_41 ) ;
if ( F_28 ( V_26 -> V_39 ) ) {
V_29 = F_29 ( V_26 -> V_39 ) ;
goto error;
}
V_26 -> V_42 . V_43 = V_28 ;
V_26 -> V_44 . V_43 = F_25 ( V_26 -> V_34 , V_45 ) ;
return 0 ;
error:
F_30 ( & V_26 -> V_7 ) ;
F_31 ( & V_26 -> V_7 ) ;
F_32 ( V_26 ) ;
return V_29 ;
}
static int F_33 ( struct V_21 * V_21 )
{
struct V_1 * V_26 = F_3 ( V_21 -> V_32 ) ;
F_34 ( V_26 -> V_39 ) ;
F_35 ( & V_26 -> V_5 ) ;
F_30 ( & V_26 -> V_7 ) ;
F_31 ( & V_26 -> V_7 ) ;
F_32 ( V_26 ) ;
return 0 ;
}
static unsigned int F_36 ( struct V_21 * V_21 ,
struct V_46 * V_47 )
{
struct V_1 * V_26 = F_3 ( V_21 -> V_32 ) ;
return F_37 ( V_21 , V_26 -> V_39 , V_47 ) ;
}
static int F_38 ( struct V_21 * V_21 , struct V_48 * V_49 )
{
struct V_1 * V_26 = F_3 ( V_21 -> V_32 ) ;
return F_39 ( V_21 , V_26 -> V_39 , V_49 ) ;
}
static int F_40 ( struct V_50 * V_51 )
{
if ( V_51 -> V_52 >= V_51 -> V_53 )
return - 1 ;
return ( ( unsigned char * ) V_51 -> V_54 ) [ V_51 -> V_52 ++ ] ;
}
static int F_41 ( struct V_50 * V_51 , unsigned int * V_55 )
{
unsigned int V_56 ;
int V_57 ;
V_57 = F_40 ( V_51 ) ;
if ( V_57 == - 1 )
return - 1 ;
V_56 = V_57 << 8 ;
V_57 = F_40 ( V_51 ) ;
if ( V_57 == - 1 )
return - 1 ;
* V_55 = ( unsigned int ) V_57 | V_56 ;
return 0 ;
}
static void F_42 ( struct V_50 * V_51 , long V_11 )
{
if ( V_11 <= 0 )
return;
while ( V_11 -- )
F_40 ( V_51 ) ;
}
static bool F_43 ( struct V_58 * V_59 ,
unsigned long V_60 , unsigned long V_53 )
{
int V_3 , V_61 , V_62 ;
unsigned int V_63 , V_64 , V_55 ;
long V_65 ;
struct V_50 V_66 ;
V_66 . V_53 = V_53 ;
V_66 . V_54 = V_60 ;
V_66 . V_52 = 0 ;
V_62 = 1 ;
while ( V_62 ) {
V_3 = F_40 ( & V_66 ) ;
if ( V_3 == - 1 )
break;
if ( V_3 != 0xff )
continue;
do
V_3 = F_40 ( & V_66 ) ;
while ( V_3 == 0xff );
if ( V_3 == - 1 )
break;
if ( V_3 == 0 )
continue;
V_65 = 0 ;
switch ( V_3 ) {
case V_67 :
if ( F_41 ( & V_66 , & V_55 ) )
break;
if ( F_40 ( & V_66 ) == - 1 )
break;
if ( F_41 ( & V_66 , & V_63 ) )
break;
if ( F_41 ( & V_66 , & V_64 ) )
break;
V_61 = F_40 ( & V_66 ) ;
if ( V_61 == - 1 )
break;
V_62 = 0 ;
F_42 ( & V_66 , V_61 * 3 ) ;
break;
case V_68 ... V_68 + 7 :
case V_69 :
case V_70 :
case V_71 :
break;
default:
if ( F_41 ( & V_66 , & V_55 ) )
break;
V_65 = ( long ) V_55 - 2 ;
F_42 ( & V_66 , V_65 ) ;
break;
}
}
V_59 -> V_72 = V_64 ;
V_59 -> V_73 = V_63 ;
V_59 -> V_53 = V_61 ;
return ! V_62 ;
}
static int F_44 ( struct V_21 * V_21 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
if ( V_26 -> V_34 == V_35 ) {
F_45 ( V_76 -> V_77 , V_78 L_1 ,
sizeof( V_76 -> V_77 ) ) ;
F_45 ( V_76 -> V_79 , V_78 L_1 ,
sizeof( V_76 -> V_79 ) ) ;
} else {
F_45 ( V_76 -> V_77 , V_78 L_2 ,
sizeof( V_76 -> V_77 ) ) ;
F_45 ( V_76 -> V_79 , V_78 L_2 ,
sizeof( V_76 -> V_79 ) ) ;
}
V_76 -> V_80 [ 0 ] = 0 ;
V_76 -> V_81 = V_82 |
V_83 |
V_84 ;
return 0 ;
}
static int F_46 ( struct V_27 * V_85 , int V_86 ,
struct V_87 * V_88 , T_2 type )
{
int V_12 , V_89 = 0 ;
for ( V_12 = 0 ; V_12 < V_86 ; ++ V_12 ) {
if ( V_85 [ V_12 ] . V_90 & type ) {
if ( V_89 == V_88 -> V_91 )
break;
++ V_89 ;
}
}
if ( V_12 >= V_86 )
return - V_92 ;
F_45 ( V_88 -> V_93 , V_85 [ V_12 ] . V_94 , sizeof( V_88 -> V_93 ) ) ;
V_88 -> V_95 = V_85 [ V_12 ] . V_96 ;
return 0 ;
}
static int F_47 ( struct V_21 * V_21 , void * V_74 ,
struct V_87 * V_88 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
if ( V_26 -> V_34 == V_35 )
return F_46 ( V_97 , V_98 , V_88 ,
V_99 ) ;
return F_46 ( V_100 , V_101 , V_88 , V_99 ) ;
}
static int F_48 ( struct V_21 * V_21 , void * V_74 ,
struct V_87 * V_88 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
if ( V_26 -> V_34 == V_35 )
return F_46 ( V_97 , V_98 , V_88 ,
V_102 ) ;
return F_46 ( V_100 , V_101 , V_88 , V_102 ) ;
}
static struct V_58 * F_49 ( struct V_1 * V_26 ,
enum V_103 type )
{
if ( type == V_104 )
return & V_26 -> V_42 ;
if ( type == V_105 )
return & V_26 -> V_44 ;
return NULL ;
}
static int F_50 ( struct V_21 * V_21 , void * V_74 , struct V_106 * V_88 )
{
struct V_107 * V_108 ;
struct V_58 * V_109 = NULL ;
struct V_110 * V_111 = & V_88 -> V_43 . V_111 ;
struct V_1 * V_112 = F_3 ( V_74 ) ;
V_108 = F_51 ( V_112 -> V_39 , V_88 -> type ) ;
if ( ! V_108 )
return - V_92 ;
if ( V_88 -> type == V_105 &&
V_112 -> V_34 == V_37 && ! V_112 -> V_113 )
return - V_92 ;
V_109 = F_49 ( V_112 , V_88 -> type ) ;
F_52 ( V_109 == NULL ) ;
V_111 -> V_64 = V_109 -> V_72 ;
V_111 -> V_63 = V_109 -> V_73 ;
V_111 -> V_114 = V_115 ;
V_111 -> V_95 = V_109 -> V_43 -> V_96 ;
V_111 -> V_116 = 0 ;
if ( V_109 -> V_43 -> V_96 != V_38 ) {
T_2 V_117 = V_109 -> V_72 ;
if ( V_109 -> V_43 -> V_118 == 1 )
V_117 = ( V_117 * V_109 -> V_43 -> V_119 ) >> 3 ;
V_111 -> V_116 = V_117 ;
}
V_111 -> V_120 = V_109 -> V_53 ;
return 0 ;
}
static struct V_27 * F_25 ( unsigned int V_34 ,
T_2 V_95 )
{
unsigned int V_121 ;
struct V_27 * V_85 ;
int V_86 ;
if ( V_34 == V_35 ) {
V_85 = V_97 ;
V_86 = V_98 ;
} else {
V_85 = V_100 ;
V_86 = V_101 ;
}
for ( V_121 = 0 ; V_121 < V_86 ; V_121 ++ ) {
struct V_27 * V_43 = & V_85 [ V_121 ] ;
if ( V_43 -> V_96 == V_95 )
return V_43 ;
}
return NULL ;
}
static void F_53 ( T_2 * V_72 , unsigned int V_122 , unsigned int V_123 ,
unsigned int V_124 ,
T_2 * V_73 , unsigned int V_125 , unsigned int V_126 ,
unsigned int V_127 )
{
int V_64 , V_63 , V_128 , V_129 ;
V_64 = * V_72 ;
V_63 = * V_73 ;
V_128 = 1 << V_124 ;
V_129 = 1 << V_127 ;
F_54 ( V_72 , V_122 , V_123 , V_124 , V_73 , V_125 , V_126 , V_127 , 0 ) ;
if ( * V_72 < V_64 && ( * V_72 + V_128 ) < V_123 )
* V_72 += V_128 ;
if ( * V_73 < V_63 && ( * V_73 + V_129 ) < V_126 )
* V_73 += V_129 ;
}
static int F_55 ( struct V_106 * V_88 , struct V_27 * V_43 ,
struct V_1 * V_26 , int V_130 )
{
struct V_110 * V_111 = & V_88 -> V_43 . V_111 ;
if ( V_111 -> V_114 == V_131 )
V_111 -> V_114 = V_115 ;
else if ( V_111 -> V_114 != V_115 )
return - V_92 ;
if ( V_130 == V_102 )
F_53 ( & V_111 -> V_64 , V_132 ,
V_133 , 0 ,
& V_111 -> V_63 , V_134 ,
V_135 , 0 ) ;
else
F_53 ( & V_111 -> V_64 , V_132 ,
V_133 , V_43 -> V_136 ,
& V_111 -> V_63 , V_134 ,
V_135 , V_43 -> V_137 ) ;
if ( V_43 -> V_96 == V_38 ) {
if ( V_111 -> V_120 <= 0 )
V_111 -> V_120 = V_138 ;
V_111 -> V_116 = 0 ;
} else {
T_2 V_117 = V_111 -> V_116 ;
if ( V_43 -> V_118 > 1 && V_117 < V_111 -> V_64 )
V_117 = V_111 -> V_64 ;
if ( V_43 -> V_118 == 1 &&
( V_117 << 3 ) * V_43 -> V_119 < V_111 -> V_64 )
V_117 = ( V_111 -> V_64 * V_43 -> V_119 ) >> 3 ;
V_111 -> V_116 = V_117 ;
V_111 -> V_120 = ( V_111 -> V_64 * V_111 -> V_63 * V_43 -> V_119 ) >> 3 ;
}
return 0 ;
}
static int F_56 ( struct V_21 * V_21 , void * V_74 ,
struct V_106 * V_88 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
struct V_27 * V_43 ;
V_43 = F_25 ( V_26 -> V_34 , V_88 -> V_43 . V_111 . V_95 ) ;
if ( ! V_43 || ! ( V_43 -> V_90 & V_99 ) ) {
F_57 ( & V_26 -> V_23 -> V_139 ,
L_3 ,
V_88 -> V_43 . V_111 . V_95 ) ;
return - V_92 ;
}
return F_55 ( V_88 , V_43 , V_26 , V_99 ) ;
}
static int F_58 ( struct V_21 * V_21 , void * V_74 ,
struct V_106 * V_88 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
struct V_27 * V_43 ;
V_43 = F_25 ( V_26 -> V_34 , V_88 -> V_43 . V_111 . V_95 ) ;
if ( ! V_43 || ! ( V_43 -> V_90 & V_102 ) ) {
F_57 ( & V_26 -> V_23 -> V_139 ,
L_3 ,
V_88 -> V_43 . V_111 . V_95 ) ;
return - V_92 ;
}
return F_55 ( V_88 , V_43 , V_26 , V_102 ) ;
}
static int F_59 ( struct V_1 * V_112 , struct V_106 * V_88 )
{
struct V_107 * V_108 ;
struct V_58 * V_109 = NULL ;
struct V_110 * V_111 = & V_88 -> V_43 . V_111 ;
V_108 = F_51 ( V_112 -> V_39 , V_88 -> type ) ;
if ( ! V_108 )
return - V_92 ;
V_109 = F_49 ( V_112 , V_88 -> type ) ;
F_52 ( V_109 == NULL ) ;
if ( F_60 ( V_108 ) ) {
F_57 ( & V_112 -> V_23 -> V_139 , L_4 , V_140 ) ;
return - V_141 ;
}
V_109 -> V_43 = F_25 ( V_112 -> V_34 , V_111 -> V_95 ) ;
V_109 -> V_72 = V_111 -> V_64 ;
V_109 -> V_73 = V_111 -> V_63 ;
if ( V_109 -> V_43 -> V_96 != V_38 )
V_109 -> V_53 = V_109 -> V_72 * V_109 -> V_73 * V_109 -> V_43 -> V_119 >> 3 ;
else
V_109 -> V_53 = V_111 -> V_120 ;
return 0 ;
}
static int F_61 ( struct V_21 * V_21 , void * V_74 ,
struct V_106 * V_88 )
{
int V_29 ;
V_29 = F_56 ( V_21 , V_74 , V_88 ) ;
if ( V_29 )
return V_29 ;
return F_59 ( F_3 ( V_74 ) , V_88 ) ;
}
static int F_62 ( struct V_21 * V_21 , void * V_74 ,
struct V_106 * V_88 )
{
int V_29 ;
V_29 = F_58 ( V_21 , V_74 , V_88 ) ;
if ( V_29 )
return V_29 ;
return F_59 ( F_3 ( V_74 ) , V_88 ) ;
}
static int F_63 ( struct V_21 * V_21 , void * V_74 ,
struct V_142 * V_143 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_64 ( V_21 , V_26 -> V_39 , V_143 ) ;
}
static int F_65 ( struct V_21 * V_21 , void * V_74 ,
struct V_144 * V_51 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_66 ( V_21 , V_26 -> V_39 , V_51 ) ;
}
static int F_67 ( struct V_21 * V_21 , void * V_74 , struct V_144 * V_51 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_68 ( V_21 , V_26 -> V_39 , V_51 ) ;
}
static int F_69 ( struct V_21 * V_21 , void * V_74 ,
struct V_144 * V_51 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_70 ( V_21 , V_26 -> V_39 , V_51 ) ;
}
static int F_71 ( struct V_21 * V_21 , void * V_74 ,
enum V_103 type )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_72 ( V_21 , V_26 -> V_39 , type ) ;
}
static int F_73 ( struct V_21 * V_21 , void * V_74 ,
enum V_103 type )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
return F_74 ( V_21 , V_26 -> V_39 , type ) ;
}
static int F_75 ( struct V_21 * V_21 , void * V_74 ,
struct V_145 * V_146 )
{
struct V_1 * V_26 = F_3 ( V_74 ) ;
if ( V_146 -> type != V_104 &&
V_146 -> type != V_105 )
return - V_92 ;
switch ( V_146 -> V_147 ) {
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_146 -> V_153 . V_64 = V_26 -> V_42 . V_72 ;
V_146 -> V_153 . V_63 = V_26 -> V_42 . V_73 ;
break;
case V_154 :
case V_155 :
V_146 -> V_153 . V_64 = V_26 -> V_44 . V_72 ;
V_146 -> V_153 . V_63 = V_26 -> V_44 . V_73 ;
break;
default:
return - V_92 ;
}
V_146 -> V_153 . V_156 = 0 ;
V_146 -> V_153 . V_157 = 0 ;
return 0 ;
}
static int F_76 ( struct V_2 * V_158 )
{
struct V_1 * V_26 = F_1 ( V_158 ) ;
struct V_22 * V_23 = V_26 -> V_23 ;
unsigned long V_159 ;
switch ( V_158 -> V_160 ) {
case V_161 :
F_77 ( & V_23 -> V_162 , V_159 ) ;
F_78 ( V_26 -> V_163 > V_164 ) ;
if ( V_26 -> V_163 > 2 )
V_158 -> V_165 = V_166 ;
else
V_158 -> V_165 = V_26 -> V_163 ;
F_79 ( & V_23 -> V_162 , V_159 ) ;
break;
}
return 0 ;
}
static int F_80 ( struct V_2 * V_158 )
{
struct V_1 * V_26 = F_1 ( V_158 ) ;
unsigned long V_159 ;
F_77 ( & V_26 -> V_23 -> V_162 , V_159 ) ;
switch ( V_158 -> V_160 ) {
case V_167 :
V_26 -> V_168 = V_169 - V_158 -> V_165 ;
break;
case V_170 :
V_26 -> V_171 = V_158 -> V_165 ;
break;
case V_161 :
V_26 -> V_163 = V_158 -> V_165 ;
break;
}
F_79 ( & V_26 -> V_23 -> V_162 , V_159 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_26 )
{
unsigned int V_172 = ~ 0x27 ;
struct V_2 * V_158 ;
F_81 ( & V_26 -> V_5 , 3 ) ;
if ( V_26 -> V_34 == V_35 ) {
F_82 ( & V_26 -> V_5 , & V_173 ,
V_167 ,
0 , 3 , 1 , 3 ) ;
F_82 ( & V_26 -> V_5 , & V_173 ,
V_170 ,
0 , 3 , 0xffff , 0 ) ;
V_172 = ~ 0x06 ;
}
V_158 = F_83 ( & V_26 -> V_5 , & V_173 ,
V_161 ,
V_166 , V_172 ,
V_174 ) ;
if ( V_26 -> V_5 . error )
return V_26 -> V_5 . error ;
if ( V_26 -> V_34 == V_37 )
V_158 -> V_159 |= V_175 |
V_176 ;
return 0 ;
}
static void F_84 ( void * V_74 )
{
struct V_1 * V_26 = V_74 ;
struct V_22 * V_23 = V_26 -> V_23 ;
struct V_177 * V_178 , * V_179 ;
unsigned long V_180 , V_181 ;
V_178 = F_85 ( V_26 -> V_39 ) ;
V_179 = F_86 ( V_26 -> V_39 ) ;
V_180 = F_87 ( V_178 , 0 ) ;
V_181 = F_87 ( V_179 , 0 ) ;
F_88 ( V_23 -> V_8 ) ;
F_89 ( V_23 -> V_8 ) ;
F_90 ( V_23 -> V_8 , V_26 -> V_34 ) ;
if ( V_26 -> V_34 == V_35 ) {
if ( V_26 -> V_42 . V_43 -> V_96 == V_36 )
F_91 ( V_23 -> V_8 , V_182 ) ;
else
F_91 ( V_23 -> V_8 , V_183 ) ;
F_92 ( V_23 -> V_8 , V_26 -> V_163 ) ;
F_93 ( V_23 -> V_8 , V_26 -> V_171 ) ;
F_94 ( V_23 -> V_8 , V_26 -> V_42 . V_72 ) ;
F_95 ( V_23 -> V_8 , V_26 -> V_42 . V_73 ) ;
F_96 ( V_23 -> V_8 , V_180 ) ;
F_97 ( V_23 -> V_8 , V_181 ) ;
F_98 ( V_23 -> V_8 , V_26 -> V_44 . V_53 ) ;
F_99 ( V_23 -> V_8 , 1 , 1 , V_184 ) ;
F_99 ( V_23 -> V_8 , 1 , 2 , V_185 ) ;
F_99 ( V_23 -> V_8 , 1 , 3 , V_186 ) ;
F_99 ( V_23 -> V_8 , 2 , 1 , V_187 ) ;
F_99 ( V_23 -> V_8 , 2 , 2 , V_188 ) ;
F_99 ( V_23 -> V_8 , 2 , 3 , V_189 ) ;
F_99 ( V_23 -> V_8 , 3 , 1 , V_190 ) ;
F_99 ( V_23 -> V_8 , 3 , 2 , V_191 ) ;
F_99 ( V_23 -> V_8 , 3 , 3 , V_192 ) ;
F_6 ( V_23 -> V_8 , V_26 -> V_168 ) ;
F_9 ( V_23 -> V_8 , V_26 -> V_168 ) ;
F_100 ( V_23 -> V_8 , 1 , 0 ) ;
F_100 ( V_23 -> V_8 , 2 , 1 ) ;
F_100 ( V_23 -> V_8 , 3 , 1 ) ;
F_101 ( V_23 -> V_8 , 1 ) ;
F_102 ( V_23 -> V_8 , 1 ) ;
F_101 ( V_23 -> V_8 , 2 ) ;
F_102 ( V_23 -> V_8 , 2 ) ;
F_101 ( V_23 -> V_8 , 3 ) ;
F_102 ( V_23 -> V_8 , 3 ) ;
} else {
F_103 ( V_23 -> V_8 , true ) ;
F_104 ( V_23 -> V_8 , true ) ;
F_105 ( V_23 -> V_8 , true ) ;
if ( V_26 -> V_44 . V_43 -> V_96 == V_45 )
F_106 ( V_23 -> V_8 , V_193 ) ;
else
F_106 ( V_23 -> V_8 , V_194 ) ;
F_97 ( V_23 -> V_8 , V_180 ) ;
F_96 ( V_23 -> V_8 , V_181 ) ;
}
F_107 ( V_23 -> V_8 ) ;
}
static int F_108 ( void * V_74 )
{
struct V_1 * V_26 = V_74 ;
if ( V_26 -> V_34 == V_37 )
return V_26 -> V_113 ;
return 1 ;
}
static void F_109 ( void * V_74 )
{
}
static int F_110 ( struct V_107 * V_108 ,
const struct V_106 * V_43 ,
unsigned int * V_195 , unsigned int * V_196 ,
unsigned int V_197 [] , void * V_198 [] )
{
struct V_1 * V_26 = F_111 ( V_108 ) ;
struct V_58 * V_109 = NULL ;
unsigned int V_53 , V_199 = * V_195 ;
V_109 = F_49 ( V_26 , V_108 -> type ) ;
F_52 ( V_109 == NULL ) ;
V_53 = V_109 -> V_53 ;
if ( V_26 -> V_34 == V_37 )
V_199 = 1 ;
* V_195 = V_199 ;
* V_196 = 1 ;
V_197 [ 0 ] = V_53 ;
V_198 [ 0 ] = V_26 -> V_23 -> V_200 ;
return 0 ;
}
static int F_112 ( struct V_177 * V_201 )
{
struct V_1 * V_26 = F_111 ( V_201 -> V_107 ) ;
struct V_58 * V_109 = NULL ;
V_109 = F_49 ( V_26 , V_201 -> V_107 -> type ) ;
F_52 ( V_109 == NULL ) ;
if ( F_113 ( V_201 , 0 ) < V_109 -> V_53 ) {
F_114 ( L_5 ,
V_140 , F_113 ( V_201 , 0 ) ,
( long ) V_109 -> V_53 ) ;
return - V_92 ;
}
F_115 ( V_201 , 0 , V_109 -> V_53 ) ;
return 0 ;
}
static void F_116 ( struct V_177 * V_201 )
{
struct V_1 * V_26 = F_111 ( V_201 -> V_107 ) ;
if ( V_26 -> V_34 == V_37 &&
V_201 -> V_107 -> type == V_104 ) {
struct V_58 V_202 , * V_109 ;
V_26 -> V_113 = F_43 ( & V_202 ,
( unsigned long ) F_117 ( V_201 , 0 ) ,
F_118 ( ( unsigned long ) V_26 -> V_42 . V_53 ,
F_119 ( V_201 , 0 ) ) ) ;
if ( ! V_26 -> V_113 ) {
F_120 ( V_201 , V_203 ) ;
return;
}
V_109 = & V_26 -> V_42 ;
V_109 -> V_72 = V_202 . V_72 ;
V_109 -> V_73 = V_202 . V_73 ;
V_109 = & V_26 -> V_44 ;
V_109 -> V_72 = V_202 . V_72 ;
V_109 -> V_73 = V_202 . V_73 ;
F_53 ( & V_109 -> V_72 , V_132 ,
V_133 , V_109 -> V_43 -> V_136 ,
& V_109 -> V_73 , V_134 ,
V_135 , V_109 -> V_43 -> V_137
) ;
V_109 -> V_53 = V_109 -> V_72 * V_109 -> V_73 * V_109 -> V_43 -> V_119 >> 3 ;
}
if ( V_26 -> V_39 )
F_121 ( V_26 -> V_39 , V_201 ) ;
}
static void F_122 ( struct V_107 * V_108 )
{
struct V_1 * V_26 = F_111 ( V_108 ) ;
F_123 ( & V_26 -> V_23 -> V_204 ) ;
}
static void F_124 ( struct V_107 * V_108 )
{
struct V_1 * V_26 = F_111 ( V_108 ) ;
F_125 ( & V_26 -> V_23 -> V_204 ) ;
}
static int F_126 ( struct V_107 * V_205 , unsigned int V_199 )
{
struct V_1 * V_26 = F_111 ( V_205 ) ;
int V_29 ;
V_29 = F_127 ( V_26 -> V_23 -> V_206 ) ;
return V_29 > 0 ? 0 : V_29 ;
}
static int F_128 ( struct V_107 * V_205 )
{
struct V_1 * V_26 = F_111 ( V_205 ) ;
F_129 ( V_26 -> V_23 -> V_206 ) ;
return 0 ;
}
static int V_41 ( void * V_74 , struct V_107 * V_207 ,
struct V_107 * V_208 )
{
struct V_1 * V_26 = V_74 ;
int V_29 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
V_207 -> type = V_104 ;
V_207 -> V_209 = V_210 | V_211 ;
V_207 -> V_212 = V_26 ;
V_207 -> V_213 = sizeof( struct V_214 ) ;
V_207 -> V_215 = & V_216 ;
V_207 -> V_217 = & V_218 ;
V_29 = F_130 ( V_207 ) ;
if ( V_29 )
return V_29 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_208 -> type = V_105 ;
V_208 -> V_209 = V_210 | V_211 ;
V_208 -> V_212 = V_26 ;
V_208 -> V_213 = sizeof( struct V_214 ) ;
V_208 -> V_215 = & V_216 ;
V_208 -> V_217 = & V_218 ;
return F_130 ( V_208 ) ;
}
static T_3 F_131 ( int V_219 , void * V_220 )
{
struct V_22 * V_23 = V_220 ;
struct V_1 * V_221 ;
struct V_177 * V_178 , * V_179 ;
unsigned long V_222 = 0 ;
enum V_223 V_224 = V_225 ;
bool V_226 = false ;
bool V_227 = false ;
bool V_228 = false ;
F_132 ( & V_23 -> V_162 ) ;
V_221 = F_133 ( V_23 -> V_40 ) ;
V_178 = F_134 ( V_221 -> V_39 ) ;
V_179 = F_135 ( V_221 -> V_39 ) ;
if ( V_221 -> V_34 == V_35 )
V_226 = F_136 ( V_23 -> V_8 ) ;
V_227 = F_137 ( V_23 -> V_8 ) ;
V_228 = F_138 ( V_23 -> V_8 ) ;
if ( V_221 -> V_34 == V_37 )
V_228 = V_228 && F_139 ( V_23 -> V_8 ) ;
if ( V_226 ) {
V_224 = V_203 ;
F_140 ( V_23 -> V_8 ) ;
} else if ( V_227 ) {
V_224 = V_203 ;
F_141 ( V_23 -> V_8 ) ;
} else if ( ! V_228 ) {
V_224 = V_203 ;
} else {
V_222 = F_142 ( V_23 -> V_8 ) ;
}
F_143 ( V_178 , V_224 ) ;
if ( V_221 -> V_34 == V_35 )
F_115 ( V_179 , 0 , V_222 ) ;
F_143 ( V_179 , V_224 ) ;
F_144 ( V_23 -> V_40 , V_221 -> V_39 ) ;
V_221 -> V_163 = F_145 ( V_23 -> V_8 ) ;
F_146 ( & V_23 -> V_162 ) ;
F_147 ( V_23 -> V_8 ) ;
return V_229 ;
}
static int F_148 ( struct V_230 * V_231 )
{
struct V_22 * V_23 ;
struct V_232 * V_233 ;
int V_29 ;
V_23 = F_149 ( & V_231 -> V_206 , sizeof( struct V_22 ) , V_30 ) ;
if ( ! V_23 )
return - V_31 ;
F_150 ( & V_23 -> V_204 ) ;
F_151 ( & V_23 -> V_162 ) ;
V_23 -> V_206 = & V_231 -> V_206 ;
V_233 = F_152 ( V_231 , V_234 , 0 ) ;
V_23 -> V_8 = F_153 ( & V_231 -> V_206 , V_233 ) ;
if ( V_23 -> V_8 == NULL ) {
F_154 ( & V_231 -> V_206 , L_6 ) ;
return - V_235 ;
}
V_23 -> V_219 = V_29 = F_155 ( V_231 , 0 ) ;
if ( V_29 < 0 ) {
F_154 ( & V_231 -> V_206 , L_7 ) ;
return V_29 ;
}
V_29 = F_156 ( & V_231 -> V_206 , V_23 -> V_219 , F_131 , 0 ,
F_157 ( & V_231 -> V_206 ) , V_23 ) ;
if ( V_29 ) {
F_154 ( & V_231 -> V_206 , L_8 , V_23 -> V_219 ) ;
return V_29 ;
}
V_23 -> V_236 = F_158 ( & V_231 -> V_206 , L_9 ) ;
if ( F_28 ( V_23 -> V_236 ) ) {
F_154 ( & V_231 -> V_206 , L_10 ) ;
V_29 = F_29 ( V_23 -> V_236 ) ;
return V_29 ;
}
F_159 ( & V_231 -> V_206 , L_11 , V_23 -> V_236 ) ;
F_160 ( V_23 -> V_236 ) ;
V_29 = F_161 ( & V_231 -> V_206 , & V_23 -> V_139 ) ;
if ( V_29 ) {
F_154 ( & V_231 -> V_206 , L_12 ) ;
goto V_237;
}
V_23 -> V_40 = F_162 ( & V_238 ) ;
if ( F_28 ( V_23 -> V_40 ) ) {
F_57 ( & V_23 -> V_139 , L_13 ) ;
V_29 = F_29 ( V_23 -> V_40 ) ;
goto V_239;
}
V_23 -> V_200 = F_163 ( & V_231 -> V_206 ) ;
if ( F_28 ( V_23 -> V_200 ) ) {
F_57 ( & V_23 -> V_139 , L_14 ) ;
V_29 = F_29 ( V_23 -> V_200 ) ;
goto V_240;
}
V_23 -> V_33 = F_164 () ;
if ( ! V_23 -> V_33 ) {
F_57 ( & V_23 -> V_139 , L_15 ) ;
V_29 = - V_31 ;
goto V_241;
}
F_45 ( V_23 -> V_33 -> V_94 , V_78 ,
sizeof( V_23 -> V_33 -> V_94 ) ) ;
V_23 -> V_33 -> V_242 = & V_243 ;
V_23 -> V_33 -> V_244 = & V_245 ;
V_23 -> V_33 -> V_246 = - 1 ;
V_23 -> V_33 -> V_247 = V_248 ;
V_23 -> V_33 -> V_204 = & V_23 -> V_204 ;
V_23 -> V_33 -> V_139 = & V_23 -> V_139 ;
F_165 ( V_249 , & V_23 -> V_33 -> V_159 ) ;
V_29 = F_166 ( V_23 -> V_33 , V_250 , - 1 ) ;
if ( V_29 ) {
F_57 ( & V_23 -> V_139 , L_16 ) ;
goto V_251;
}
F_167 ( V_23 -> V_33 , V_23 ) ;
F_168 ( & V_23 -> V_139 ,
L_17 ,
V_23 -> V_33 -> V_89 ) ;
V_23 -> V_252 = F_164 () ;
if ( ! V_23 -> V_252 ) {
F_57 ( & V_23 -> V_139 , L_15 ) ;
V_29 = - V_31 ;
goto V_253;
}
F_45 ( V_23 -> V_252 -> V_94 , V_78 ,
sizeof( V_23 -> V_252 -> V_94 ) ) ;
V_23 -> V_252 -> V_242 = & V_243 ;
V_23 -> V_252 -> V_244 = & V_245 ;
V_23 -> V_252 -> V_246 = - 1 ;
V_23 -> V_252 -> V_247 = V_248 ;
V_23 -> V_252 -> V_204 = & V_23 -> V_204 ;
V_23 -> V_252 -> V_139 = & V_23 -> V_139 ;
F_165 ( V_249 , & V_23 -> V_252 -> V_159 ) ;
V_29 = F_166 ( V_23 -> V_252 , V_250 , - 1 ) ;
if ( V_29 ) {
F_57 ( & V_23 -> V_139 , L_16 ) ;
goto V_254;
}
F_167 ( V_23 -> V_252 , V_23 ) ;
F_168 ( & V_23 -> V_139 ,
L_18 ,
V_23 -> V_252 -> V_89 ) ;
F_169 ( V_231 , V_23 ) ;
F_170 ( & V_231 -> V_206 ) ;
F_168 ( & V_23 -> V_139 , L_19 ) ;
return 0 ;
V_254:
V_248 ( V_23 -> V_252 ) ;
V_253:
F_171 ( V_23 -> V_33 ) ;
V_251:
V_248 ( V_23 -> V_33 ) ;
V_241:
F_172 ( V_23 -> V_200 ) ;
V_240:
F_173 ( V_23 -> V_40 ) ;
V_239:
F_174 ( & V_23 -> V_139 ) ;
V_237:
F_175 ( V_23 -> V_236 ) ;
F_176 ( V_23 -> V_236 ) ;
return V_29 ;
}
static int F_177 ( struct V_230 * V_231 )
{
struct V_22 * V_23 = F_178 ( V_231 ) ;
F_179 ( V_23 -> V_206 ) ;
F_171 ( V_23 -> V_252 ) ;
V_248 ( V_23 -> V_252 ) ;
F_171 ( V_23 -> V_33 ) ;
V_248 ( V_23 -> V_33 ) ;
F_172 ( V_23 -> V_200 ) ;
F_173 ( V_23 -> V_40 ) ;
F_174 ( & V_23 -> V_139 ) ;
F_175 ( V_23 -> V_236 ) ;
F_176 ( V_23 -> V_236 ) ;
return 0 ;
}
static int F_180 ( struct V_255 * V_206 )
{
return 0 ;
}
static int F_181 ( struct V_255 * V_206 )
{
struct V_22 * V_23 = F_182 ( V_206 ) ;
F_11 ( V_23 -> V_8 ) ;
F_13 ( V_23 -> V_8 ) ;
F_15 ( V_23 -> V_8 ) ;
F_17 ( V_23 -> V_8 ) ;
return 0 ;
}
static int T_4
F_183 ( void )
{
int V_29 ;
F_184 ( L_20 ) ;
V_29 = F_185 ( & V_256 ) ;
if ( V_29 )
F_114 ( L_21 , V_140 ) ;
return V_29 ;
}
static void T_5
F_186 ( void )
{
F_187 ( & V_256 ) ;
}
