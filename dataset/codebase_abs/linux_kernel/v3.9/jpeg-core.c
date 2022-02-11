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
V_26 = F_22 ( sizeof( * V_26 ) , V_30 ) ;
if ( ! V_26 )
return - V_31 ;
if ( F_23 ( & V_23 -> V_32 ) ) {
V_29 = - V_33 ;
goto free;
}
F_24 ( & V_26 -> V_7 , V_25 ) ;
V_26 -> V_7 . V_5 = & V_26 -> V_5 ;
V_21 -> V_34 = & V_26 -> V_7 ;
F_25 ( & V_26 -> V_7 ) ;
V_26 -> V_23 = V_23 ;
if ( V_25 == V_23 -> V_35 ) {
V_26 -> V_36 = V_37 ;
V_28 = F_26 ( V_26 -> V_36 , V_38 ) ;
} else {
V_26 -> V_36 = V_39 ;
V_28 = F_26 ( V_26 -> V_36 , V_40 ) ;
}
V_29 = F_27 ( V_26 ) ;
if ( V_29 < 0 )
goto error;
V_26 -> V_41 = F_28 ( V_23 -> V_42 , V_26 , V_43 ) ;
if ( F_29 ( V_26 -> V_41 ) ) {
V_29 = F_30 ( V_26 -> V_41 ) ;
goto error;
}
V_26 -> V_44 . V_45 = V_28 ;
V_26 -> V_46 . V_45 = F_26 ( V_26 -> V_36 , V_47 ) ;
F_31 ( & V_23 -> V_32 ) ;
return 0 ;
error:
F_32 ( & V_26 -> V_7 ) ;
F_33 ( & V_26 -> V_7 ) ;
F_31 ( & V_23 -> V_32 ) ;
free:
F_34 ( V_26 ) ;
return V_29 ;
}
static int F_35 ( struct V_21 * V_21 )
{
struct V_22 * V_23 = F_20 ( V_21 ) ;
struct V_1 * V_26 = F_3 ( V_21 -> V_34 ) ;
F_36 ( & V_23 -> V_32 ) ;
F_37 ( V_26 -> V_41 ) ;
F_31 ( & V_23 -> V_32 ) ;
F_38 ( & V_26 -> V_5 ) ;
F_32 ( & V_26 -> V_7 ) ;
F_33 ( & V_26 -> V_7 ) ;
F_34 ( V_26 ) ;
return 0 ;
}
static unsigned int F_39 ( struct V_21 * V_21 ,
struct V_48 * V_49 )
{
struct V_22 * V_23 = F_20 ( V_21 ) ;
struct V_1 * V_26 = F_3 ( V_21 -> V_34 ) ;
unsigned int V_50 ;
F_36 ( & V_23 -> V_32 ) ;
V_50 = F_40 ( V_21 , V_26 -> V_41 , V_49 ) ;
F_31 ( & V_23 -> V_32 ) ;
return V_50 ;
}
static int F_41 ( struct V_21 * V_21 , struct V_51 * V_52 )
{
struct V_22 * V_23 = F_20 ( V_21 ) ;
struct V_1 * V_26 = F_3 ( V_21 -> V_34 ) ;
int V_29 ;
if ( F_23 ( & V_23 -> V_32 ) )
return - V_33 ;
V_29 = F_42 ( V_21 , V_26 -> V_41 , V_52 ) ;
F_31 ( & V_23 -> V_32 ) ;
return V_29 ;
}
static int F_43 ( struct V_53 * V_54 )
{
if ( V_54 -> V_55 >= V_54 -> V_56 )
return - 1 ;
return ( ( unsigned char * ) V_54 -> V_57 ) [ V_54 -> V_55 ++ ] ;
}
static int F_44 ( struct V_53 * V_54 , unsigned int * V_58 )
{
unsigned int V_59 ;
int V_60 ;
V_60 = F_43 ( V_54 ) ;
if ( V_60 == - 1 )
return - 1 ;
V_59 = V_60 << 8 ;
V_60 = F_43 ( V_54 ) ;
if ( V_60 == - 1 )
return - 1 ;
* V_58 = ( unsigned int ) V_60 | V_59 ;
return 0 ;
}
static void F_45 ( struct V_53 * V_54 , long V_11 )
{
if ( V_11 <= 0 )
return;
while ( V_11 -- )
F_43 ( V_54 ) ;
}
static bool F_46 ( struct V_61 * V_62 ,
unsigned long V_63 , unsigned long V_56 )
{
int V_3 , V_64 , V_65 ;
unsigned int V_66 , V_67 , V_58 ;
long V_68 ;
struct V_53 V_69 ;
V_69 . V_56 = V_56 ;
V_69 . V_57 = V_63 ;
V_69 . V_55 = 0 ;
V_65 = 1 ;
while ( V_65 ) {
V_3 = F_43 ( & V_69 ) ;
if ( V_3 == - 1 )
break;
if ( V_3 != 0xff )
continue;
do
V_3 = F_43 ( & V_69 ) ;
while ( V_3 == 0xff );
if ( V_3 == - 1 )
break;
if ( V_3 == 0 )
continue;
V_68 = 0 ;
switch ( V_3 ) {
case V_70 :
if ( F_44 ( & V_69 , & V_58 ) )
break;
if ( F_43 ( & V_69 ) == - 1 )
break;
if ( F_44 ( & V_69 , & V_66 ) )
break;
if ( F_44 ( & V_69 , & V_67 ) )
break;
V_64 = F_43 ( & V_69 ) ;
if ( V_64 == - 1 )
break;
V_65 = 0 ;
F_45 ( & V_69 , V_64 * 3 ) ;
break;
case V_71 ... V_71 + 7 :
case V_72 :
case V_73 :
case V_74 :
break;
default:
if ( F_44 ( & V_69 , & V_58 ) )
break;
V_68 = ( long ) V_58 - 2 ;
F_45 ( & V_69 , V_68 ) ;
break;
}
}
V_62 -> V_75 = V_67 ;
V_62 -> V_76 = V_66 ;
V_62 -> V_56 = V_64 ;
return ! V_65 ;
}
static int F_47 ( struct V_21 * V_21 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
if ( V_26 -> V_36 == V_37 ) {
F_48 ( V_79 -> V_80 , V_81 L_1 ,
sizeof( V_79 -> V_80 ) ) ;
F_48 ( V_79 -> V_82 , V_81 L_1 ,
sizeof( V_79 -> V_82 ) ) ;
} else {
F_48 ( V_79 -> V_80 , V_81 L_2 ,
sizeof( V_79 -> V_80 ) ) ;
F_48 ( V_79 -> V_82 , V_81 L_2 ,
sizeof( V_79 -> V_82 ) ) ;
}
V_79 -> V_83 [ 0 ] = 0 ;
V_79 -> V_84 = V_85 | V_86 |
V_87 | V_88 ;
return 0 ;
}
static int F_49 ( struct V_27 * V_89 , int V_90 ,
struct V_91 * V_92 , T_2 type )
{
int V_12 , V_93 = 0 ;
for ( V_12 = 0 ; V_12 < V_90 ; ++ V_12 ) {
if ( V_89 [ V_12 ] . V_94 & type ) {
if ( V_93 == V_92 -> V_95 )
break;
++ V_93 ;
}
}
if ( V_12 >= V_90 )
return - V_96 ;
F_48 ( V_92 -> V_97 , V_89 [ V_12 ] . V_98 , sizeof( V_92 -> V_97 ) ) ;
V_92 -> V_99 = V_89 [ V_12 ] . V_100 ;
return 0 ;
}
static int F_50 ( struct V_21 * V_21 , void * V_77 ,
struct V_91 * V_92 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
if ( V_26 -> V_36 == V_37 )
return F_49 ( V_101 , V_102 , V_92 ,
V_103 ) ;
return F_49 ( V_104 , V_105 , V_92 , V_103 ) ;
}
static int F_51 ( struct V_21 * V_21 , void * V_77 ,
struct V_91 * V_92 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
if ( V_26 -> V_36 == V_37 )
return F_49 ( V_101 , V_102 , V_92 ,
V_106 ) ;
return F_49 ( V_104 , V_105 , V_92 , V_106 ) ;
}
static struct V_61 * F_52 ( struct V_1 * V_26 ,
enum V_107 type )
{
if ( type == V_108 )
return & V_26 -> V_44 ;
if ( type == V_109 )
return & V_26 -> V_46 ;
return NULL ;
}
static int F_53 ( struct V_21 * V_21 , void * V_77 , struct V_110 * V_92 )
{
struct V_111 * V_112 ;
struct V_61 * V_113 = NULL ;
struct V_114 * V_115 = & V_92 -> V_45 . V_115 ;
struct V_1 * V_116 = F_3 ( V_77 ) ;
V_112 = F_54 ( V_116 -> V_41 , V_92 -> type ) ;
if ( ! V_112 )
return - V_96 ;
if ( V_92 -> type == V_109 &&
V_116 -> V_36 == V_39 && ! V_116 -> V_117 )
return - V_96 ;
V_113 = F_52 ( V_116 , V_92 -> type ) ;
F_55 ( V_113 == NULL ) ;
V_115 -> V_67 = V_113 -> V_75 ;
V_115 -> V_66 = V_113 -> V_76 ;
V_115 -> V_118 = V_119 ;
V_115 -> V_99 = V_113 -> V_45 -> V_100 ;
V_115 -> V_120 = 0 ;
if ( V_113 -> V_45 -> V_100 != V_40 ) {
T_2 V_121 = V_113 -> V_75 ;
if ( V_113 -> V_45 -> V_122 == 1 )
V_121 = ( V_121 * V_113 -> V_45 -> V_123 ) >> 3 ;
V_115 -> V_120 = V_121 ;
}
V_115 -> V_124 = V_113 -> V_56 ;
return 0 ;
}
static struct V_27 * F_26 ( unsigned int V_36 ,
T_2 V_99 )
{
unsigned int V_125 ;
struct V_27 * V_89 ;
int V_90 ;
if ( V_36 == V_37 ) {
V_89 = V_101 ;
V_90 = V_102 ;
} else {
V_89 = V_104 ;
V_90 = V_105 ;
}
for ( V_125 = 0 ; V_125 < V_90 ; V_125 ++ ) {
struct V_27 * V_45 = & V_89 [ V_125 ] ;
if ( V_45 -> V_100 == V_99 )
return V_45 ;
}
return NULL ;
}
static void F_56 ( T_2 * V_75 , unsigned int V_126 , unsigned int V_127 ,
unsigned int V_128 ,
T_2 * V_76 , unsigned int V_129 , unsigned int V_130 ,
unsigned int V_131 )
{
int V_67 , V_66 , V_132 , V_133 ;
V_67 = * V_75 ;
V_66 = * V_76 ;
V_132 = 1 << V_128 ;
V_133 = 1 << V_131 ;
F_57 ( V_75 , V_126 , V_127 , V_128 , V_76 , V_129 , V_130 , V_131 , 0 ) ;
if ( * V_75 < V_67 && ( * V_75 + V_132 ) < V_127 )
* V_75 += V_132 ;
if ( * V_76 < V_66 && ( * V_76 + V_133 ) < V_130 )
* V_76 += V_133 ;
}
static int F_58 ( struct V_110 * V_92 , struct V_27 * V_45 ,
struct V_1 * V_26 , int V_134 )
{
struct V_114 * V_115 = & V_92 -> V_45 . V_115 ;
if ( V_115 -> V_118 == V_135 )
V_115 -> V_118 = V_119 ;
else if ( V_115 -> V_118 != V_119 )
return - V_96 ;
if ( V_134 == V_106 )
F_56 ( & V_115 -> V_67 , V_136 ,
V_137 , 0 ,
& V_115 -> V_66 , V_138 ,
V_139 , 0 ) ;
else
F_56 ( & V_115 -> V_67 , V_136 ,
V_137 , V_45 -> V_140 ,
& V_115 -> V_66 , V_138 ,
V_139 , V_45 -> V_141 ) ;
if ( V_45 -> V_100 == V_40 ) {
if ( V_115 -> V_124 <= 0 )
V_115 -> V_124 = V_142 ;
V_115 -> V_120 = 0 ;
} else {
T_2 V_121 = V_115 -> V_120 ;
if ( V_45 -> V_122 > 1 && V_121 < V_115 -> V_67 )
V_121 = V_115 -> V_67 ;
if ( V_45 -> V_122 == 1 &&
( V_121 << 3 ) * V_45 -> V_123 < V_115 -> V_67 )
V_121 = ( V_115 -> V_67 * V_45 -> V_123 ) >> 3 ;
V_115 -> V_120 = V_121 ;
V_115 -> V_124 = ( V_115 -> V_67 * V_115 -> V_66 * V_45 -> V_123 ) >> 3 ;
}
return 0 ;
}
static int F_59 ( struct V_21 * V_21 , void * V_77 ,
struct V_110 * V_92 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
struct V_27 * V_45 ;
V_45 = F_26 ( V_26 -> V_36 , V_92 -> V_45 . V_115 . V_99 ) ;
if ( ! V_45 || ! ( V_45 -> V_94 & V_103 ) ) {
F_60 ( & V_26 -> V_23 -> V_143 ,
L_3 ,
V_92 -> V_45 . V_115 . V_99 ) ;
return - V_96 ;
}
return F_58 ( V_92 , V_45 , V_26 , V_103 ) ;
}
static int F_61 ( struct V_21 * V_21 , void * V_77 ,
struct V_110 * V_92 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
struct V_27 * V_45 ;
V_45 = F_26 ( V_26 -> V_36 , V_92 -> V_45 . V_115 . V_99 ) ;
if ( ! V_45 || ! ( V_45 -> V_94 & V_106 ) ) {
F_60 ( & V_26 -> V_23 -> V_143 ,
L_3 ,
V_92 -> V_45 . V_115 . V_99 ) ;
return - V_96 ;
}
return F_58 ( V_92 , V_45 , V_26 , V_106 ) ;
}
static int F_62 ( struct V_1 * V_116 , struct V_110 * V_92 )
{
struct V_111 * V_112 ;
struct V_61 * V_113 = NULL ;
struct V_114 * V_115 = & V_92 -> V_45 . V_115 ;
V_112 = F_54 ( V_116 -> V_41 , V_92 -> type ) ;
if ( ! V_112 )
return - V_96 ;
V_113 = F_52 ( V_116 , V_92 -> type ) ;
F_55 ( V_113 == NULL ) ;
if ( F_63 ( V_112 ) ) {
F_60 ( & V_116 -> V_23 -> V_143 , L_4 , V_144 ) ;
return - V_145 ;
}
V_113 -> V_45 = F_26 ( V_116 -> V_36 , V_115 -> V_99 ) ;
V_113 -> V_75 = V_115 -> V_67 ;
V_113 -> V_76 = V_115 -> V_66 ;
if ( V_113 -> V_45 -> V_100 != V_40 )
V_113 -> V_56 = V_113 -> V_75 * V_113 -> V_76 * V_113 -> V_45 -> V_123 >> 3 ;
else
V_113 -> V_56 = V_115 -> V_124 ;
return 0 ;
}
static int F_64 ( struct V_21 * V_21 , void * V_77 ,
struct V_110 * V_92 )
{
int V_29 ;
V_29 = F_59 ( V_21 , V_77 , V_92 ) ;
if ( V_29 )
return V_29 ;
return F_62 ( F_3 ( V_77 ) , V_92 ) ;
}
static int F_65 ( struct V_21 * V_21 , void * V_77 ,
struct V_110 * V_92 )
{
int V_29 ;
V_29 = F_61 ( V_21 , V_77 , V_92 ) ;
if ( V_29 )
return V_29 ;
return F_62 ( F_3 ( V_77 ) , V_92 ) ;
}
static int F_66 ( struct V_21 * V_21 , void * V_77 ,
struct V_146 * V_147 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_67 ( V_21 , V_26 -> V_41 , V_147 ) ;
}
static int F_68 ( struct V_21 * V_21 , void * V_77 ,
struct V_148 * V_54 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_69 ( V_21 , V_26 -> V_41 , V_54 ) ;
}
static int F_70 ( struct V_21 * V_21 , void * V_77 , struct V_148 * V_54 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_71 ( V_21 , V_26 -> V_41 , V_54 ) ;
}
static int F_72 ( struct V_21 * V_21 , void * V_77 ,
struct V_148 * V_54 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_73 ( V_21 , V_26 -> V_41 , V_54 ) ;
}
static int F_74 ( struct V_21 * V_21 , void * V_77 ,
enum V_107 type )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_75 ( V_21 , V_26 -> V_41 , type ) ;
}
static int F_76 ( struct V_21 * V_21 , void * V_77 ,
enum V_107 type )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
return F_77 ( V_21 , V_26 -> V_41 , type ) ;
}
static int F_78 ( struct V_21 * V_21 , void * V_77 ,
struct V_149 * V_150 )
{
struct V_1 * V_26 = F_3 ( V_77 ) ;
if ( V_150 -> type != V_108 &&
V_150 -> type != V_109 )
return - V_96 ;
switch ( V_150 -> V_151 ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
V_150 -> V_157 . V_67 = V_26 -> V_44 . V_75 ;
V_150 -> V_157 . V_66 = V_26 -> V_44 . V_76 ;
break;
case V_158 :
case V_159 :
V_150 -> V_157 . V_67 = V_26 -> V_46 . V_75 ;
V_150 -> V_157 . V_66 = V_26 -> V_46 . V_76 ;
break;
default:
return - V_96 ;
}
V_150 -> V_157 . V_160 = 0 ;
V_150 -> V_157 . V_161 = 0 ;
return 0 ;
}
static int F_79 ( struct V_2 * V_162 )
{
struct V_1 * V_26 = F_1 ( V_162 ) ;
struct V_22 * V_23 = V_26 -> V_23 ;
unsigned long V_163 ;
switch ( V_162 -> V_164 ) {
case V_165 :
F_80 ( & V_23 -> V_166 , V_163 ) ;
F_81 ( V_26 -> V_167 > V_168 ) ;
if ( V_26 -> V_167 > 2 )
V_162 -> V_169 = V_170 ;
else
V_162 -> V_169 = V_26 -> V_167 ;
F_82 ( & V_23 -> V_166 , V_163 ) ;
break;
}
return 0 ;
}
static int F_83 ( struct V_2 * V_162 )
{
struct V_1 * V_26 = F_1 ( V_162 ) ;
unsigned long V_163 ;
F_80 ( & V_26 -> V_23 -> V_166 , V_163 ) ;
switch ( V_162 -> V_164 ) {
case V_171 :
V_26 -> V_172 = V_173 - V_162 -> V_169 ;
break;
case V_174 :
V_26 -> V_175 = V_162 -> V_169 ;
break;
case V_165 :
V_26 -> V_167 = V_162 -> V_169 ;
break;
}
F_82 ( & V_26 -> V_23 -> V_166 , V_163 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_26 )
{
unsigned int V_176 = ~ 0x27 ;
struct V_2 * V_162 ;
F_84 ( & V_26 -> V_5 , 3 ) ;
if ( V_26 -> V_36 == V_37 ) {
F_85 ( & V_26 -> V_5 , & V_177 ,
V_171 ,
0 , 3 , 1 , 3 ) ;
F_85 ( & V_26 -> V_5 , & V_177 ,
V_174 ,
0 , 3 , 0xffff , 0 ) ;
V_176 = ~ 0x06 ;
}
V_162 = F_86 ( & V_26 -> V_5 , & V_177 ,
V_165 ,
V_170 , V_176 ,
V_178 ) ;
if ( V_26 -> V_5 . error )
return V_26 -> V_5 . error ;
if ( V_26 -> V_36 == V_39 )
V_162 -> V_163 |= V_179 |
V_180 ;
return 0 ;
}
static void F_87 ( void * V_77 )
{
struct V_1 * V_26 = V_77 ;
struct V_22 * V_23 = V_26 -> V_23 ;
struct V_181 * V_182 , * V_183 ;
unsigned long V_184 , V_185 ;
V_182 = F_88 ( V_26 -> V_41 ) ;
V_183 = F_89 ( V_26 -> V_41 ) ;
V_184 = F_90 ( V_182 , 0 ) ;
V_185 = F_90 ( V_183 , 0 ) ;
F_91 ( V_23 -> V_8 ) ;
F_92 ( V_23 -> V_8 ) ;
F_93 ( V_23 -> V_8 , V_26 -> V_36 ) ;
if ( V_26 -> V_36 == V_37 ) {
if ( V_26 -> V_44 . V_45 -> V_100 == V_38 )
F_94 ( V_23 -> V_8 , V_186 ) ;
else
F_94 ( V_23 -> V_8 , V_187 ) ;
F_95 ( V_23 -> V_8 , V_26 -> V_167 ) ;
F_96 ( V_23 -> V_8 , V_26 -> V_175 ) ;
F_97 ( V_23 -> V_8 , V_26 -> V_44 . V_75 ) ;
F_98 ( V_23 -> V_8 , V_26 -> V_44 . V_76 ) ;
F_99 ( V_23 -> V_8 , V_184 ) ;
F_100 ( V_23 -> V_8 , V_185 ) ;
F_101 ( V_23 -> V_8 , V_26 -> V_46 . V_56 ) ;
F_102 ( V_23 -> V_8 , 1 , 1 , V_188 ) ;
F_102 ( V_23 -> V_8 , 1 , 2 , V_189 ) ;
F_102 ( V_23 -> V_8 , 1 , 3 , V_190 ) ;
F_102 ( V_23 -> V_8 , 2 , 1 , V_191 ) ;
F_102 ( V_23 -> V_8 , 2 , 2 , V_192 ) ;
F_102 ( V_23 -> V_8 , 2 , 3 , V_193 ) ;
F_102 ( V_23 -> V_8 , 3 , 1 , V_194 ) ;
F_102 ( V_23 -> V_8 , 3 , 2 , V_195 ) ;
F_102 ( V_23 -> V_8 , 3 , 3 , V_196 ) ;
F_6 ( V_23 -> V_8 , V_26 -> V_172 ) ;
F_9 ( V_23 -> V_8 , V_26 -> V_172 ) ;
F_103 ( V_23 -> V_8 , 1 , 0 ) ;
F_103 ( V_23 -> V_8 , 2 , 1 ) ;
F_103 ( V_23 -> V_8 , 3 , 1 ) ;
F_104 ( V_23 -> V_8 , 1 ) ;
F_105 ( V_23 -> V_8 , 1 ) ;
F_104 ( V_23 -> V_8 , 2 ) ;
F_105 ( V_23 -> V_8 , 2 ) ;
F_104 ( V_23 -> V_8 , 3 ) ;
F_105 ( V_23 -> V_8 , 3 ) ;
} else {
F_106 ( V_23 -> V_8 , true ) ;
F_107 ( V_23 -> V_8 , true ) ;
F_108 ( V_23 -> V_8 , true ) ;
if ( V_26 -> V_46 . V_45 -> V_100 == V_47 )
F_109 ( V_23 -> V_8 , V_197 ) ;
else
F_109 ( V_23 -> V_8 , V_198 ) ;
F_100 ( V_23 -> V_8 , V_184 ) ;
F_99 ( V_23 -> V_8 , V_185 ) ;
}
F_110 ( V_23 -> V_8 ) ;
}
static int F_111 ( void * V_77 )
{
struct V_1 * V_26 = V_77 ;
if ( V_26 -> V_36 == V_39 )
return V_26 -> V_117 ;
return 1 ;
}
static void F_112 ( void * V_77 )
{
}
static int F_113 ( struct V_111 * V_112 ,
const struct V_110 * V_45 ,
unsigned int * V_199 , unsigned int * V_200 ,
unsigned int V_201 [] , void * V_202 [] )
{
struct V_1 * V_26 = F_114 ( V_112 ) ;
struct V_61 * V_113 = NULL ;
unsigned int V_56 , V_203 = * V_199 ;
V_113 = F_52 ( V_26 , V_112 -> type ) ;
F_55 ( V_113 == NULL ) ;
V_56 = V_113 -> V_56 ;
if ( V_26 -> V_36 == V_39 )
V_203 = 1 ;
* V_199 = V_203 ;
* V_200 = 1 ;
V_201 [ 0 ] = V_56 ;
V_202 [ 0 ] = V_26 -> V_23 -> V_204 ;
return 0 ;
}
static int F_115 ( struct V_181 * V_205 )
{
struct V_1 * V_26 = F_114 ( V_205 -> V_111 ) ;
struct V_61 * V_113 = NULL ;
V_113 = F_52 ( V_26 , V_205 -> V_111 -> type ) ;
F_55 ( V_113 == NULL ) ;
if ( F_116 ( V_205 , 0 ) < V_113 -> V_56 ) {
F_117 ( L_5 ,
V_144 , F_116 ( V_205 , 0 ) ,
( long ) V_113 -> V_56 ) ;
return - V_96 ;
}
F_118 ( V_205 , 0 , V_113 -> V_56 ) ;
return 0 ;
}
static void F_119 ( struct V_181 * V_205 )
{
struct V_1 * V_26 = F_114 ( V_205 -> V_111 ) ;
if ( V_26 -> V_36 == V_39 &&
V_205 -> V_111 -> type == V_108 ) {
struct V_61 V_206 , * V_113 ;
V_26 -> V_117 = F_46 ( & V_206 ,
( unsigned long ) F_120 ( V_205 , 0 ) ,
F_121 ( ( unsigned long ) V_26 -> V_44 . V_56 ,
F_122 ( V_205 , 0 ) ) ) ;
if ( ! V_26 -> V_117 ) {
F_123 ( V_205 , V_207 ) ;
return;
}
V_113 = & V_26 -> V_44 ;
V_113 -> V_75 = V_206 . V_75 ;
V_113 -> V_76 = V_206 . V_76 ;
V_113 = & V_26 -> V_46 ;
V_113 -> V_75 = V_206 . V_75 ;
V_113 -> V_76 = V_206 . V_76 ;
F_56 ( & V_113 -> V_75 , V_136 ,
V_137 , V_113 -> V_45 -> V_140 ,
& V_113 -> V_76 , V_138 ,
V_139 , V_113 -> V_45 -> V_141
) ;
V_113 -> V_56 = V_113 -> V_75 * V_113 -> V_76 * V_113 -> V_45 -> V_123 >> 3 ;
}
if ( V_26 -> V_41 )
F_124 ( V_26 -> V_41 , V_205 ) ;
}
static void F_125 ( struct V_111 * V_112 )
{
struct V_1 * V_26 = F_114 ( V_112 ) ;
F_31 ( & V_26 -> V_23 -> V_32 ) ;
}
static void F_126 ( struct V_111 * V_112 )
{
struct V_1 * V_26 = F_114 ( V_112 ) ;
F_36 ( & V_26 -> V_23 -> V_32 ) ;
}
static int F_127 ( struct V_111 * V_208 , unsigned int V_203 )
{
struct V_1 * V_26 = F_114 ( V_208 ) ;
int V_29 ;
V_29 = F_128 ( V_26 -> V_23 -> V_209 ) ;
return V_29 > 0 ? 0 : V_29 ;
}
static int F_129 ( struct V_111 * V_208 )
{
struct V_1 * V_26 = F_114 ( V_208 ) ;
F_130 ( V_26 -> V_23 -> V_209 ) ;
return 0 ;
}
static int V_43 ( void * V_77 , struct V_111 * V_210 ,
struct V_111 * V_211 )
{
struct V_1 * V_26 = V_77 ;
int V_29 ;
V_210 -> type = V_108 ;
V_210 -> V_212 = V_213 | V_214 ;
V_210 -> V_215 = V_26 ;
V_210 -> V_216 = sizeof( struct V_217 ) ;
V_210 -> V_218 = & V_219 ;
V_210 -> V_220 = & V_221 ;
V_29 = F_131 ( V_210 ) ;
if ( V_29 )
return V_29 ;
V_211 -> type = V_109 ;
V_211 -> V_212 = V_213 | V_214 ;
V_211 -> V_215 = V_26 ;
V_211 -> V_216 = sizeof( struct V_217 ) ;
V_211 -> V_218 = & V_219 ;
V_211 -> V_220 = & V_221 ;
return F_131 ( V_211 ) ;
}
static T_3 F_132 ( int V_222 , void * V_223 )
{
struct V_22 * V_23 = V_223 ;
struct V_1 * V_224 ;
struct V_181 * V_182 , * V_183 ;
unsigned long V_225 = 0 ;
enum V_226 V_227 = V_228 ;
bool V_229 = false ;
bool V_230 = false ;
bool V_231 = false ;
F_133 ( & V_23 -> V_166 ) ;
V_224 = F_134 ( V_23 -> V_42 ) ;
V_182 = F_135 ( V_224 -> V_41 ) ;
V_183 = F_136 ( V_224 -> V_41 ) ;
if ( V_224 -> V_36 == V_37 )
V_229 = F_137 ( V_23 -> V_8 ) ;
V_230 = F_138 ( V_23 -> V_8 ) ;
V_231 = F_139 ( V_23 -> V_8 ) ;
if ( V_224 -> V_36 == V_39 )
V_231 = V_231 && F_140 ( V_23 -> V_8 ) ;
if ( V_229 ) {
V_227 = V_207 ;
F_141 ( V_23 -> V_8 ) ;
} else if ( V_230 ) {
V_227 = V_207 ;
F_142 ( V_23 -> V_8 ) ;
} else if ( ! V_231 ) {
V_227 = V_207 ;
} else {
V_225 = F_143 ( V_23 -> V_8 ) ;
}
F_144 ( V_182 , V_227 ) ;
if ( V_224 -> V_36 == V_37 )
F_118 ( V_183 , 0 , V_225 ) ;
F_144 ( V_183 , V_227 ) ;
F_145 ( V_23 -> V_42 , V_224 -> V_41 ) ;
V_224 -> V_167 = F_146 ( V_23 -> V_8 ) ;
F_147 ( & V_23 -> V_166 ) ;
F_148 ( V_23 -> V_8 ) ;
return V_232 ;
}
static int F_149 ( struct V_233 * V_234 )
{
struct V_22 * V_23 ;
struct V_235 * V_50 ;
int V_29 ;
V_23 = F_150 ( & V_234 -> V_209 , sizeof( struct V_22 ) , V_30 ) ;
if ( ! V_23 )
return - V_31 ;
F_151 ( & V_23 -> V_32 ) ;
F_152 ( & V_23 -> V_166 ) ;
V_23 -> V_209 = & V_234 -> V_209 ;
V_50 = F_153 ( V_234 , V_236 , 0 ) ;
V_23 -> V_8 = F_154 ( & V_234 -> V_209 , V_50 ) ;
if ( F_29 ( V_23 -> V_8 ) )
return F_30 ( V_23 -> V_8 ) ;
V_23 -> V_222 = V_29 = F_155 ( V_234 , 0 ) ;
if ( V_29 < 0 ) {
F_156 ( & V_234 -> V_209 , L_6 ) ;
return V_29 ;
}
V_29 = F_157 ( & V_234 -> V_209 , V_23 -> V_222 , F_132 , 0 ,
F_158 ( & V_234 -> V_209 ) , V_23 ) ;
if ( V_29 ) {
F_156 ( & V_234 -> V_209 , L_7 , V_23 -> V_222 ) ;
return V_29 ;
}
V_23 -> V_237 = F_159 ( & V_234 -> V_209 , L_8 ) ;
if ( F_29 ( V_23 -> V_237 ) ) {
F_156 ( & V_234 -> V_209 , L_9 ) ;
V_29 = F_30 ( V_23 -> V_237 ) ;
return V_29 ;
}
F_160 ( & V_234 -> V_209 , L_10 , V_23 -> V_237 ) ;
F_161 ( V_23 -> V_237 ) ;
V_29 = F_162 ( & V_234 -> V_209 , & V_23 -> V_143 ) ;
if ( V_29 ) {
F_156 ( & V_234 -> V_209 , L_11 ) ;
goto V_238;
}
V_23 -> V_42 = F_163 ( & V_239 ) ;
if ( F_29 ( V_23 -> V_42 ) ) {
F_60 ( & V_23 -> V_143 , L_12 ) ;
V_29 = F_30 ( V_23 -> V_42 ) ;
goto V_240;
}
V_23 -> V_204 = F_164 ( & V_234 -> V_209 ) ;
if ( F_29 ( V_23 -> V_204 ) ) {
F_60 ( & V_23 -> V_143 , L_13 ) ;
V_29 = F_30 ( V_23 -> V_204 ) ;
goto V_241;
}
V_23 -> V_35 = F_165 () ;
if ( ! V_23 -> V_35 ) {
F_60 ( & V_23 -> V_143 , L_14 ) ;
V_29 = - V_31 ;
goto V_242;
}
F_48 ( V_23 -> V_35 -> V_98 , V_81 ,
sizeof( V_23 -> V_35 -> V_98 ) ) ;
V_23 -> V_35 -> V_243 = & V_244 ;
V_23 -> V_35 -> V_245 = & V_246 ;
V_23 -> V_35 -> V_247 = - 1 ;
V_23 -> V_35 -> V_248 = V_249 ;
V_23 -> V_35 -> V_32 = & V_23 -> V_32 ;
V_23 -> V_35 -> V_143 = & V_23 -> V_143 ;
V_23 -> V_35 -> V_250 = V_251 ;
V_29 = F_166 ( V_23 -> V_35 , V_252 , - 1 ) ;
if ( V_29 ) {
F_60 ( & V_23 -> V_143 , L_15 ) ;
goto V_253;
}
F_167 ( V_23 -> V_35 , V_23 ) ;
F_168 ( & V_23 -> V_143 ,
L_16 ,
V_23 -> V_35 -> V_93 ) ;
V_23 -> V_254 = F_165 () ;
if ( ! V_23 -> V_254 ) {
F_60 ( & V_23 -> V_143 , L_14 ) ;
V_29 = - V_31 ;
goto V_255;
}
F_48 ( V_23 -> V_254 -> V_98 , V_81 ,
sizeof( V_23 -> V_254 -> V_98 ) ) ;
V_23 -> V_254 -> V_243 = & V_244 ;
V_23 -> V_254 -> V_245 = & V_246 ;
V_23 -> V_254 -> V_247 = - 1 ;
V_23 -> V_254 -> V_248 = V_249 ;
V_23 -> V_254 -> V_32 = & V_23 -> V_32 ;
V_23 -> V_254 -> V_143 = & V_23 -> V_143 ;
V_29 = F_166 ( V_23 -> V_254 , V_252 , - 1 ) ;
if ( V_29 ) {
F_60 ( & V_23 -> V_143 , L_15 ) ;
goto V_256;
}
F_167 ( V_23 -> V_254 , V_23 ) ;
F_168 ( & V_23 -> V_143 ,
L_17 ,
V_23 -> V_254 -> V_93 ) ;
F_169 ( V_234 , V_23 ) ;
F_170 ( & V_234 -> V_209 ) ;
F_168 ( & V_23 -> V_143 , L_18 ) ;
return 0 ;
V_256:
V_249 ( V_23 -> V_254 ) ;
V_255:
F_171 ( V_23 -> V_35 ) ;
V_253:
V_249 ( V_23 -> V_35 ) ;
V_242:
F_172 ( V_23 -> V_204 ) ;
V_241:
F_173 ( V_23 -> V_42 ) ;
V_240:
F_174 ( & V_23 -> V_143 ) ;
V_238:
F_175 ( V_23 -> V_237 ) ;
F_176 ( V_23 -> V_237 ) ;
return V_29 ;
}
static int F_177 ( struct V_233 * V_234 )
{
struct V_22 * V_23 = F_178 ( V_234 ) ;
F_179 ( V_23 -> V_209 ) ;
F_171 ( V_23 -> V_254 ) ;
V_249 ( V_23 -> V_254 ) ;
F_171 ( V_23 -> V_35 ) ;
V_249 ( V_23 -> V_35 ) ;
F_172 ( V_23 -> V_204 ) ;
F_173 ( V_23 -> V_42 ) ;
F_174 ( & V_23 -> V_143 ) ;
F_175 ( V_23 -> V_237 ) ;
F_176 ( V_23 -> V_237 ) ;
return 0 ;
}
static int F_180 ( struct V_257 * V_209 )
{
return 0 ;
}
static int F_181 ( struct V_257 * V_209 )
{
struct V_22 * V_23 = F_182 ( V_209 ) ;
F_11 ( V_23 -> V_8 ) ;
F_13 ( V_23 -> V_8 ) ;
F_15 ( V_23 -> V_8 ) ;
F_17 ( V_23 -> V_8 ) ;
return 0 ;
}
