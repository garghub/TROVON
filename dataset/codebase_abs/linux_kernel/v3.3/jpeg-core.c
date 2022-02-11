static inline void F_1 ( void T_1 * V_1 , const unsigned char * V_2 ,
unsigned long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
F_2 ( ( unsigned int ) V_2 [ V_5 ] , V_1 + V_3 + ( V_5 * 0x04 ) ) ;
}
static inline void F_3 ( void T_1 * V_1 , int V_6 )
{
F_1 ( V_1 , V_7 [ V_6 ] , F_4 ( 0 ) ,
F_5 ( V_7 [ V_6 ] ) ) ;
}
static inline void F_6 ( void T_1 * V_1 , int V_6 )
{
F_1 ( V_1 , V_8 [ V_6 ] , F_4 ( 1 ) ,
F_5 ( V_8 [ V_6 ] ) ) ;
}
static inline void F_7 ( void T_1 * V_1 , const unsigned char * V_9 ,
unsigned long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
F_2 ( ( unsigned int ) V_9 [ V_5 ] , V_1 + V_3 + ( V_5 * 0x04 ) ) ;
}
static inline void F_8 ( void T_1 * V_1 )
{
F_7 ( V_1 , V_10 , F_9 ( 0 ) , F_5 ( V_10 ) ) ;
}
static inline void F_10 ( void T_1 * V_1 )
{
F_7 ( V_1 , V_11 , F_11 ( 0 ) , F_5 ( V_11 ) ) ;
}
static inline void F_12 ( void T_1 * V_1 )
{
F_7 ( V_1 , V_12 , F_13 ( 0 ) , F_5 ( V_12 ) ) ;
}
static inline void F_14 ( void T_1 * V_1 )
{
F_7 ( V_1 , V_13 , F_15 ( 0 ) , F_5 ( V_13 ) ) ;
}
static int F_16 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = F_17 ( V_14 ) ;
struct V_17 * V_18 = F_18 ( V_14 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_20 = F_19 ( sizeof *V_20 , V_23 ) ;
if ( ! V_20 )
return - V_24 ;
V_14 -> V_25 = V_20 ;
V_20 -> V_16 = V_16 ;
if ( V_18 == V_16 -> V_26 ) {
V_20 -> V_27 = V_28 ;
V_22 = F_20 ( V_20 -> V_27 , V_29 ) ;
} else {
V_20 -> V_27 = V_30 ;
V_22 = F_20 ( V_20 -> V_27 , V_31 ) ;
}
V_20 -> V_32 = F_21 ( V_16 -> V_33 , V_20 , V_34 ) ;
if ( F_22 ( V_20 -> V_32 ) ) {
int V_35 = F_23 ( V_20 -> V_32 ) ;
F_24 ( V_20 ) ;
return V_35 ;
}
V_20 -> V_36 . V_37 = V_22 ;
V_20 -> V_38 . V_37 = F_20 ( V_20 -> V_27 , V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_14 )
{
struct V_19 * V_20 = V_14 -> V_25 ;
F_26 ( V_20 -> V_32 ) ;
F_24 ( V_20 ) ;
return 0 ;
}
static unsigned int F_27 ( struct V_14 * V_14 ,
struct V_40 * V_41 )
{
struct V_19 * V_20 = V_14 -> V_25 ;
return F_28 ( V_14 , V_20 -> V_32 , V_41 ) ;
}
static int F_29 ( struct V_14 * V_14 , struct V_42 * V_43 )
{
struct V_19 * V_20 = V_14 -> V_25 ;
return F_30 ( V_14 , V_20 -> V_32 , V_43 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
if ( V_45 -> V_46 >= V_45 -> V_47 )
return - 1 ;
return ( ( unsigned char * ) V_45 -> V_48 ) [ V_45 -> V_46 ++ ] ;
}
static int F_32 ( struct V_44 * V_45 , unsigned int * V_49 )
{
unsigned int V_50 ;
int V_51 ;
V_51 = F_31 ( V_45 ) ;
if ( V_51 == - 1 )
return - 1 ;
V_50 = V_51 << 8 ;
V_51 = F_31 ( V_45 ) ;
if ( V_51 == - 1 )
return - 1 ;
* V_49 = ( unsigned int ) V_51 | V_50 ;
return 0 ;
}
static void F_33 ( struct V_44 * V_45 , long V_4 )
{
if ( V_4 <= 0 )
return;
while ( V_4 -- )
F_31 ( V_45 ) ;
}
static bool F_34 ( struct V_52 * V_53 ,
unsigned long V_54 , unsigned long V_47 )
{
int V_55 , V_56 , V_57 ;
unsigned int V_58 , V_59 , V_49 ;
long V_60 ;
struct V_44 V_61 ;
V_61 . V_47 = V_47 ;
V_61 . V_48 = V_54 ;
V_61 . V_46 = 0 ;
V_57 = 1 ;
while ( V_57 ) {
V_55 = F_31 ( & V_61 ) ;
if ( V_55 == - 1 )
break;
if ( V_55 != 0xff )
continue;
do
V_55 = F_31 ( & V_61 ) ;
while ( V_55 == 0xff );
if ( V_55 == - 1 )
break;
if ( V_55 == 0 )
continue;
V_60 = 0 ;
switch ( V_55 ) {
case V_62 :
if ( F_32 ( & V_61 , & V_49 ) )
break;
if ( F_31 ( & V_61 ) == - 1 )
break;
if ( F_32 ( & V_61 , & V_58 ) )
break;
if ( F_32 ( & V_61 , & V_59 ) )
break;
V_56 = F_31 ( & V_61 ) ;
if ( V_56 == - 1 )
break;
V_57 = 0 ;
F_33 ( & V_61 , V_56 * 3 ) ;
break;
case V_63 ... V_63 + 7 :
case V_64 :
case V_65 :
case V_66 :
break;
default:
if ( F_32 ( & V_61 , & V_49 ) )
break;
V_60 = ( long ) V_49 - 2 ;
F_33 ( & V_61 , V_60 ) ;
break;
}
}
V_53 -> V_67 = V_59 ;
V_53 -> V_68 = V_58 ;
V_53 -> V_47 = V_56 ;
return ! V_57 ;
}
static int F_35 ( struct V_14 * V_14 , void * V_69 ,
struct V_70 * V_71 )
{
struct V_19 * V_20 = V_69 ;
if ( V_20 -> V_27 == V_28 ) {
F_36 ( V_71 -> V_72 , V_73 L_1 ,
sizeof( V_71 -> V_72 ) ) ;
F_36 ( V_71 -> V_74 , V_73 L_1 ,
sizeof( V_71 -> V_74 ) ) ;
} else {
F_36 ( V_71 -> V_72 , V_73 L_2 ,
sizeof( V_71 -> V_72 ) ) ;
F_36 ( V_71 -> V_74 , V_73 L_2 ,
sizeof( V_71 -> V_74 ) ) ;
}
V_71 -> V_75 [ 0 ] = 0 ;
V_71 -> V_76 = V_77 |
V_78 |
V_79 ;
return 0 ;
}
static int F_37 ( struct V_21 * V_80 , int V_81 ,
struct V_82 * V_83 , T_2 type )
{
int V_5 , V_84 = 0 ;
for ( V_5 = 0 ; V_5 < V_81 ; ++ V_5 ) {
if ( V_80 [ V_5 ] . V_85 & type ) {
if ( V_84 == V_83 -> V_86 )
break;
++ V_84 ;
}
}
if ( V_5 >= V_81 )
return - V_87 ;
F_36 ( V_83 -> V_88 , V_80 [ V_5 ] . V_89 , sizeof( V_83 -> V_88 ) ) ;
V_83 -> V_90 = V_80 [ V_5 ] . V_91 ;
return 0 ;
}
static int F_38 ( struct V_14 * V_14 , void * V_69 ,
struct V_82 * V_83 )
{
struct V_19 * V_20 ;
V_20 = V_69 ;
if ( V_20 -> V_27 == V_28 )
return F_37 ( V_92 , V_93 , V_83 ,
V_94 ) ;
return F_37 ( V_95 , V_96 , V_83 , V_94 ) ;
}
static int F_39 ( struct V_14 * V_14 , void * V_69 ,
struct V_82 * V_83 )
{
struct V_19 * V_20 ;
V_20 = V_69 ;
if ( V_20 -> V_27 == V_28 )
return F_37 ( V_92 , V_93 , V_83 ,
V_97 ) ;
return F_37 ( V_95 , V_96 , V_83 , V_97 ) ;
}
static struct V_52 * F_40 ( struct V_19 * V_20 ,
enum V_98 type )
{
if ( type == V_99 )
return & V_20 -> V_36 ;
if ( type == V_100 )
return & V_20 -> V_38 ;
return NULL ;
}
static int F_41 ( struct V_14 * V_14 , void * V_69 , struct V_101 * V_83 )
{
struct V_102 * V_103 ;
struct V_52 * V_104 = NULL ;
struct V_105 * V_106 = & V_83 -> V_37 . V_106 ;
struct V_19 * V_107 = V_69 ;
V_103 = F_42 ( V_107 -> V_32 , V_83 -> type ) ;
if ( ! V_103 )
return - V_87 ;
if ( V_83 -> type == V_100 &&
V_107 -> V_27 == V_30 && ! V_107 -> V_108 )
return - V_87 ;
V_104 = F_40 ( V_107 , V_83 -> type ) ;
F_43 ( V_104 == NULL ) ;
V_106 -> V_59 = V_104 -> V_67 ;
V_106 -> V_58 = V_104 -> V_68 ;
V_106 -> V_109 = V_110 ;
V_106 -> V_90 = V_104 -> V_37 -> V_91 ;
V_106 -> V_111 = 0 ;
if ( V_104 -> V_37 -> V_91 != V_31 ) {
T_2 V_112 = V_104 -> V_67 ;
if ( V_104 -> V_37 -> V_113 == 1 )
V_112 = ( V_112 * V_104 -> V_37 -> V_114 ) >> 3 ;
V_106 -> V_111 = V_112 ;
}
V_106 -> V_115 = V_104 -> V_47 ;
return 0 ;
}
static struct V_21 * F_20 ( unsigned int V_27 ,
T_2 V_90 )
{
unsigned int V_116 ;
struct V_21 * V_80 ;
int V_81 ;
if ( V_27 == V_28 ) {
V_80 = V_92 ;
V_81 = V_93 ;
} else {
V_80 = V_95 ;
V_81 = V_96 ;
}
for ( V_116 = 0 ; V_116 < V_81 ; V_116 ++ ) {
struct V_21 * V_37 = & V_80 [ V_116 ] ;
if ( V_37 -> V_91 == V_90 )
return V_37 ;
}
return NULL ;
}
static void F_44 ( T_2 * V_67 , unsigned int V_117 , unsigned int V_118 ,
unsigned int V_119 ,
T_2 * V_68 , unsigned int V_120 , unsigned int V_121 ,
unsigned int V_122 )
{
int V_59 , V_58 , V_123 , V_124 ;
V_59 = * V_67 ;
V_58 = * V_68 ;
V_123 = 1 << V_119 ;
V_124 = 1 << V_122 ;
F_45 ( V_67 , V_117 , V_118 , V_119 , V_68 , V_120 , V_121 , V_122 , 0 ) ;
if ( * V_67 < V_59 && ( * V_67 + V_123 ) < V_118 )
* V_67 += V_123 ;
if ( * V_68 < V_58 && ( * V_68 + V_124 ) < V_121 )
* V_68 += V_124 ;
}
static int F_46 ( struct V_101 * V_83 , struct V_21 * V_37 ,
struct V_19 * V_20 , int V_125 )
{
struct V_105 * V_106 = & V_83 -> V_37 . V_106 ;
if ( V_106 -> V_109 == V_126 )
V_106 -> V_109 = V_110 ;
else if ( V_106 -> V_109 != V_110 )
return - V_87 ;
if ( V_125 == V_97 )
F_44 ( & V_106 -> V_59 , V_127 ,
V_128 , 0 ,
& V_106 -> V_58 , V_129 ,
V_130 , 0 ) ;
else
F_44 ( & V_106 -> V_59 , V_127 ,
V_128 , V_37 -> V_131 ,
& V_106 -> V_58 , V_129 ,
V_130 , V_37 -> V_132 ) ;
if ( V_37 -> V_91 == V_31 ) {
if ( V_106 -> V_115 <= 0 )
V_106 -> V_115 = V_133 ;
V_106 -> V_111 = 0 ;
} else {
T_2 V_112 = V_106 -> V_111 ;
if ( V_37 -> V_113 > 1 && V_112 < V_106 -> V_59 )
V_112 = V_106 -> V_59 ;
if ( V_37 -> V_113 == 1 &&
( V_112 << 3 ) * V_37 -> V_114 < V_106 -> V_59 )
V_112 = ( V_106 -> V_59 * V_37 -> V_114 ) >> 3 ;
V_106 -> V_111 = V_112 ;
V_106 -> V_115 = ( V_106 -> V_59 * V_106 -> V_58 * V_37 -> V_114 ) >> 3 ;
}
return 0 ;
}
static int F_47 ( struct V_14 * V_14 , void * V_69 ,
struct V_101 * V_83 )
{
struct V_21 * V_37 ;
struct V_19 * V_20 = V_69 ;
V_37 = F_20 ( V_20 -> V_27 , V_83 -> V_37 . V_106 . V_90 ) ;
if ( ! V_37 || ! ( V_37 -> V_85 & V_94 ) ) {
F_48 ( & V_20 -> V_16 -> V_134 ,
L_3 ,
V_83 -> V_37 . V_106 . V_90 ) ;
return - V_87 ;
}
return F_46 ( V_83 , V_37 , V_20 , V_94 ) ;
}
static int F_49 ( struct V_14 * V_14 , void * V_69 ,
struct V_101 * V_83 )
{
struct V_21 * V_37 ;
struct V_19 * V_20 = V_69 ;
V_37 = F_20 ( V_20 -> V_27 , V_83 -> V_37 . V_106 . V_90 ) ;
if ( ! V_37 || ! ( V_37 -> V_85 & V_97 ) ) {
F_48 ( & V_20 -> V_16 -> V_134 ,
L_3 ,
V_83 -> V_37 . V_106 . V_90 ) ;
return - V_87 ;
}
return F_46 ( V_83 , V_37 , V_20 , V_97 ) ;
}
static int F_50 ( struct V_19 * V_107 , struct V_101 * V_83 )
{
struct V_102 * V_103 ;
struct V_52 * V_104 = NULL ;
struct V_105 * V_106 = & V_83 -> V_37 . V_106 ;
V_103 = F_42 ( V_107 -> V_32 , V_83 -> type ) ;
if ( ! V_103 )
return - V_87 ;
V_104 = F_40 ( V_107 , V_83 -> type ) ;
F_43 ( V_104 == NULL ) ;
if ( F_51 ( V_103 ) ) {
F_48 ( & V_107 -> V_16 -> V_134 , L_4 , V_135 ) ;
return - V_136 ;
}
V_104 -> V_37 = F_20 ( V_107 -> V_27 , V_106 -> V_90 ) ;
V_104 -> V_67 = V_106 -> V_59 ;
V_104 -> V_68 = V_106 -> V_58 ;
if ( V_104 -> V_37 -> V_91 != V_31 )
V_104 -> V_47 = V_104 -> V_67 * V_104 -> V_68 * V_104 -> V_37 -> V_114 >> 3 ;
else
V_104 -> V_47 = V_106 -> V_115 ;
return 0 ;
}
static int F_52 ( struct V_14 * V_14 , void * V_69 ,
struct V_101 * V_83 )
{
int V_137 ;
V_137 = F_47 ( V_14 , V_69 , V_83 ) ;
if ( V_137 )
return V_137 ;
return F_50 ( V_69 , V_83 ) ;
}
static int F_53 ( struct V_14 * V_14 , void * V_69 ,
struct V_101 * V_83 )
{
int V_137 ;
V_137 = F_49 ( V_14 , V_69 , V_83 ) ;
if ( V_137 )
return V_137 ;
return F_50 ( V_69 , V_83 ) ;
}
static int F_54 ( struct V_14 * V_14 , void * V_69 ,
struct V_138 * V_139 )
{
struct V_19 * V_20 = V_69 ;
return F_55 ( V_14 , V_20 -> V_32 , V_139 ) ;
}
static int F_56 ( struct V_14 * V_14 , void * V_69 ,
struct V_140 * V_45 )
{
struct V_19 * V_20 = V_69 ;
return F_57 ( V_14 , V_20 -> V_32 , V_45 ) ;
}
static int F_58 ( struct V_14 * V_14 , void * V_69 , struct V_140 * V_45 )
{
struct V_19 * V_20 = V_69 ;
return F_59 ( V_14 , V_20 -> V_32 , V_45 ) ;
}
static int F_60 ( struct V_14 * V_14 , void * V_69 ,
struct V_140 * V_45 )
{
struct V_19 * V_20 = V_69 ;
return F_61 ( V_14 , V_20 -> V_32 , V_45 ) ;
}
static int F_62 ( struct V_14 * V_14 , void * V_69 ,
enum V_98 type )
{
struct V_19 * V_20 = V_69 ;
return F_63 ( V_14 , V_20 -> V_32 , type ) ;
}
static int F_64 ( struct V_14 * V_14 , void * V_69 ,
enum V_98 type )
{
struct V_19 * V_20 = V_69 ;
return F_65 ( V_14 , V_20 -> V_32 , type ) ;
}
int F_66 ( struct V_14 * V_14 , void * V_69 ,
struct V_141 * V_142 )
{
struct V_19 * V_20 = V_69 ;
if ( V_142 -> type != V_99 &&
V_142 -> type != V_100 )
return - V_87 ;
switch ( V_142 -> V_143 ) {
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_142 -> V_149 . V_59 = V_20 -> V_36 . V_67 ;
V_142 -> V_149 . V_58 = V_20 -> V_36 . V_68 ;
break;
case V_150 :
case V_151 :
V_142 -> V_149 . V_59 = V_20 -> V_38 . V_67 ;
V_142 -> V_149 . V_58 = V_20 -> V_38 . V_68 ;
break;
default:
return - V_87 ;
}
V_142 -> V_149 . V_152 = 0 ;
V_142 -> V_149 . V_153 = 0 ;
return 0 ;
}
static int F_67 ( struct V_14 * V_14 , void * V_69 ,
struct V_154 * V_155 )
{
struct V_19 * V_20 = V_69 ;
if ( V_20 -> V_27 == V_30 )
return - V_156 ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_6 = V_20 -> V_157 ;
return 0 ;
}
static int F_68 ( struct V_14 * V_14 , void * V_69 ,
struct V_154 * V_155 )
{
struct V_19 * V_20 = V_69 ;
if ( V_20 -> V_27 == V_30 )
return - V_156 ;
V_155 -> V_6 = F_69 ( V_155 -> V_6 , V_158 ,
V_159 ) ;
V_20 -> V_157 = V_159 - V_155 -> V_6 ;
return 0 ;
}
static void F_70 ( void * V_69 )
{
struct V_19 * V_20 = V_69 ;
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_160 * V_161 , * V_162 ;
unsigned long V_163 , V_164 ;
V_161 = F_71 ( V_20 -> V_32 ) ;
V_162 = F_72 ( V_20 -> V_32 ) ;
V_163 = F_73 ( V_161 , 0 ) ;
V_164 = F_73 ( V_162 , 0 ) ;
F_74 ( V_16 -> V_1 ) ;
F_75 ( V_16 -> V_1 ) ;
F_76 ( V_16 -> V_1 , V_20 -> V_27 ) ;
if ( V_20 -> V_27 == V_28 ) {
if ( V_20 -> V_36 . V_37 -> V_91 == V_29 )
F_77 ( V_16 -> V_1 , V_165 ) ;
else
F_77 ( V_16 -> V_1 , V_166 ) ;
if ( V_20 -> V_38 . V_37 -> V_91 == V_39 )
F_78 ( V_16 -> V_1 ,
V_167 ) ;
else
F_78 ( V_16 -> V_1 ,
V_168 ) ;
F_79 ( V_16 -> V_1 , 0 ) ;
F_80 ( V_16 -> V_1 , V_20 -> V_36 . V_67 ) ;
F_81 ( V_16 -> V_1 , V_20 -> V_36 . V_68 ) ;
F_82 ( V_16 -> V_1 , V_163 ) ;
F_83 ( V_16 -> V_1 , V_164 ) ;
F_84 ( V_16 -> V_1 , V_20 -> V_38 . V_47 ) ;
F_85 ( V_16 -> V_1 , 1 , 1 , V_169 ) ;
F_85 ( V_16 -> V_1 , 1 , 2 , V_170 ) ;
F_85 ( V_16 -> V_1 , 1 , 3 , V_171 ) ;
F_85 ( V_16 -> V_1 , 2 , 1 , V_172 ) ;
F_85 ( V_16 -> V_1 , 2 , 2 , V_173 ) ;
F_85 ( V_16 -> V_1 , 2 , 3 , V_174 ) ;
F_85 ( V_16 -> V_1 , 3 , 1 , V_175 ) ;
F_85 ( V_16 -> V_1 , 3 , 2 , V_176 ) ;
F_85 ( V_16 -> V_1 , 3 , 3 , V_177 ) ;
F_3 ( V_16 -> V_1 , V_20 -> V_157 ) ;
F_6 ( V_16 -> V_1 , V_20 -> V_157 ) ;
F_86 ( V_16 -> V_1 , 1 , 0 ) ;
F_86 ( V_16 -> V_1 , 2 , 1 ) ;
F_86 ( V_16 -> V_1 , 3 , 1 ) ;
F_87 ( V_16 -> V_1 , 1 ) ;
F_88 ( V_16 -> V_1 , 1 ) ;
F_87 ( V_16 -> V_1 , 2 ) ;
F_88 ( V_16 -> V_1 , 2 ) ;
F_87 ( V_16 -> V_1 , 3 ) ;
F_88 ( V_16 -> V_1 , 3 ) ;
} else {
F_89 ( V_16 -> V_1 , true ) ;
F_90 ( V_16 -> V_1 , true ) ;
F_91 ( V_16 -> V_1 , true ) ;
F_92 ( V_16 -> V_1 , V_178 ) ;
F_83 ( V_16 -> V_1 , V_163 ) ;
F_82 ( V_16 -> V_1 , V_164 ) ;
}
F_93 ( V_16 -> V_1 ) ;
}
static int F_94 ( void * V_69 )
{
struct V_19 * V_20 = V_69 ;
if ( V_20 -> V_27 == V_30 )
return V_20 -> V_108 ;
return 1 ;
}
static void F_95 ( void * V_69 )
{
}
static int F_96 ( struct V_102 * V_103 ,
const struct V_101 * V_37 ,
unsigned int * V_179 , unsigned int * V_180 ,
unsigned int V_181 [] , void * V_182 [] )
{
struct V_19 * V_20 = F_97 ( V_103 ) ;
struct V_52 * V_104 = NULL ;
unsigned int V_47 , V_183 = * V_179 ;
V_104 = F_40 ( V_20 , V_103 -> type ) ;
F_43 ( V_104 == NULL ) ;
V_47 = V_104 -> V_47 ;
if ( V_20 -> V_27 == V_30 )
V_183 = 1 ;
* V_179 = V_183 ;
* V_180 = 1 ;
V_181 [ 0 ] = V_47 ;
V_182 [ 0 ] = V_20 -> V_16 -> V_184 ;
return 0 ;
}
static int F_98 ( struct V_160 * V_185 )
{
struct V_19 * V_20 = F_97 ( V_185 -> V_102 ) ;
struct V_52 * V_104 = NULL ;
V_104 = F_40 ( V_20 , V_185 -> V_102 -> type ) ;
F_43 ( V_104 == NULL ) ;
if ( F_99 ( V_185 , 0 ) < V_104 -> V_47 ) {
F_100 ( L_5 ,
V_135 , F_99 ( V_185 , 0 ) ,
( long ) V_104 -> V_47 ) ;
return - V_87 ;
}
F_101 ( V_185 , 0 , V_104 -> V_47 ) ;
return 0 ;
}
static void F_102 ( struct V_160 * V_185 )
{
struct V_19 * V_20 = F_97 ( V_185 -> V_102 ) ;
if ( V_20 -> V_27 == V_30 &&
V_185 -> V_102 -> type == V_99 ) {
struct V_52 V_186 , * V_104 ;
V_20 -> V_108 = F_34 ( & V_186 ,
( unsigned long ) F_103 ( V_185 , 0 ) ,
F_104 ( ( unsigned long ) V_20 -> V_36 . V_47 ,
F_105 ( V_185 , 0 ) ) ) ;
if ( ! V_20 -> V_108 ) {
F_106 ( V_185 , V_187 ) ;
return;
}
V_104 = & V_20 -> V_36 ;
V_104 -> V_67 = V_186 . V_67 ;
V_104 -> V_68 = V_186 . V_68 ;
V_104 = & V_20 -> V_38 ;
V_104 -> V_67 = V_186 . V_67 ;
V_104 -> V_68 = V_186 . V_68 ;
F_44 ( & V_104 -> V_67 , V_127 ,
V_128 , V_104 -> V_37 -> V_131 ,
& V_104 -> V_68 , V_129 ,
V_130 , V_104 -> V_37 -> V_132
) ;
V_104 -> V_47 = V_104 -> V_67 * V_104 -> V_68 * V_104 -> V_37 -> V_114 >> 3 ;
}
if ( V_20 -> V_32 )
F_107 ( V_20 -> V_32 , V_185 ) ;
}
static void F_108 ( struct V_102 * V_103 )
{
struct V_19 * V_20 = F_97 ( V_103 ) ;
F_109 ( & V_20 -> V_16 -> V_188 ) ;
}
static void F_110 ( struct V_102 * V_103 )
{
struct V_19 * V_20 = F_97 ( V_103 ) ;
F_111 ( & V_20 -> V_16 -> V_188 ) ;
}
static int F_112 ( struct V_102 * V_189 , unsigned int V_183 )
{
struct V_19 * V_20 = F_97 ( V_189 ) ;
int V_137 ;
V_137 = F_113 ( V_20 -> V_16 -> V_190 ) ;
return V_137 > 0 ? 0 : V_137 ;
}
static int F_114 ( struct V_102 * V_189 )
{
struct V_19 * V_20 = F_97 ( V_189 ) ;
F_115 ( V_20 -> V_16 -> V_190 ) ;
return 0 ;
}
static int V_34 ( void * V_69 , struct V_102 * V_191 ,
struct V_102 * V_192 )
{
struct V_19 * V_20 = V_69 ;
int V_137 ;
memset ( V_191 , 0 , sizeof( * V_191 ) ) ;
V_191 -> type = V_99 ;
V_191 -> V_193 = V_194 | V_195 ;
V_191 -> V_196 = V_20 ;
V_191 -> V_197 = sizeof( struct V_198 ) ;
V_191 -> V_199 = & V_200 ;
V_191 -> V_201 = & V_202 ;
V_137 = F_116 ( V_191 ) ;
if ( V_137 )
return V_137 ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> type = V_100 ;
V_192 -> V_193 = V_194 | V_195 ;
V_192 -> V_196 = V_20 ;
V_192 -> V_197 = sizeof( struct V_198 ) ;
V_192 -> V_199 = & V_200 ;
V_192 -> V_201 = & V_202 ;
return F_116 ( V_192 ) ;
}
static T_3 F_117 ( int V_203 , void * V_204 )
{
struct V_15 * V_16 = V_204 ;
struct V_19 * V_205 ;
struct V_160 * V_161 , * V_162 ;
unsigned long V_206 = 0 ;
enum V_207 V_208 = V_209 ;
bool V_210 = false ;
bool V_211 = false ;
bool V_212 = false ;
V_205 = F_118 ( V_16 -> V_33 ) ;
V_161 = F_119 ( V_205 -> V_32 ) ;
V_162 = F_120 ( V_205 -> V_32 ) ;
if ( V_205 -> V_27 == V_28 )
V_210 = F_121 ( V_16 -> V_1 ) ;
V_211 = F_122 ( V_16 -> V_1 ) ;
V_212 = F_123 ( V_16 -> V_1 ) ;
if ( V_205 -> V_27 == V_30 )
V_212 = V_212 && F_124 ( V_16 -> V_1 ) ;
if ( V_210 ) {
V_208 = V_187 ;
F_125 ( V_16 -> V_1 ) ;
} else if ( V_211 ) {
V_208 = V_187 ;
F_126 ( V_16 -> V_1 ) ;
} else if ( ! V_212 ) {
V_208 = V_187 ;
} else {
V_206 = F_127 ( V_16 -> V_1 ) ;
}
F_128 ( V_161 , V_208 ) ;
if ( V_205 -> V_27 == V_28 )
F_101 ( V_162 , 0 , V_206 ) ;
F_128 ( V_162 , V_208 ) ;
F_129 ( V_16 -> V_33 , V_205 -> V_32 ) ;
F_130 ( V_16 -> V_1 ) ;
return V_213 ;
}
static int F_131 ( struct V_214 * V_215 )
{
struct V_15 * V_16 ;
struct V_216 * V_217 ;
int V_137 ;
V_16 = F_19 ( sizeof( struct V_15 ) , V_23 ) ;
if ( ! V_16 )
return - V_24 ;
F_132 ( & V_16 -> V_188 ) ;
V_16 -> V_190 = & V_215 -> V_190 ;
V_217 = F_133 ( V_215 , V_218 , 0 ) ;
if ( ! V_217 ) {
F_134 ( & V_215 -> V_190 , L_6 ) ;
V_137 = - V_219 ;
goto V_220;
}
V_16 -> V_221 = F_135 ( V_217 -> V_222 , F_136 ( V_217 ) ,
V_215 -> V_89 ) ;
if ( ! V_16 -> V_221 ) {
F_134 ( & V_215 -> V_190 , L_7 ) ;
V_137 = - V_223 ;
goto V_220;
}
V_16 -> V_1 = F_137 ( V_217 -> V_222 , F_136 ( V_217 ) ) ;
if ( ! V_16 -> V_1 ) {
F_134 ( & V_215 -> V_190 , L_8 ) ;
V_137 = - V_223 ;
goto V_224;
}
F_138 ( & V_215 -> V_190 , L_9 ,
V_16 -> V_1 , V_16 -> V_221 , V_217 ) ;
V_16 -> V_203 = V_137 = F_139 ( V_215 , 0 ) ;
if ( V_137 < 0 ) {
F_134 ( & V_215 -> V_190 , L_10 ) ;
goto V_225;
}
V_137 = F_140 ( V_16 -> V_203 , F_117 , 0 ,
F_141 ( & V_215 -> V_190 ) , V_16 ) ;
if ( V_137 ) {
F_134 ( & V_215 -> V_190 , L_11 , V_16 -> V_203 ) ;
goto V_225;
}
V_16 -> V_226 = F_142 ( & V_215 -> V_190 , L_12 ) ;
if ( F_22 ( V_16 -> V_226 ) ) {
F_134 ( & V_215 -> V_190 , L_13 ) ;
V_137 = F_23 ( V_16 -> V_226 ) ;
goto V_227;
}
F_138 ( & V_215 -> V_190 , L_14 , V_16 -> V_226 ) ;
F_143 ( V_16 -> V_226 ) ;
V_137 = F_144 ( & V_215 -> V_190 , & V_16 -> V_134 ) ;
if ( V_137 ) {
F_134 ( & V_215 -> V_190 , L_15 ) ;
goto V_228;
}
V_16 -> V_33 = F_145 ( & V_229 ) ;
if ( F_22 ( V_16 -> V_33 ) ) {
F_48 ( & V_16 -> V_134 , L_16 ) ;
V_137 = F_23 ( V_16 -> V_33 ) ;
goto V_230;
}
V_16 -> V_184 = F_146 ( & V_215 -> V_190 ) ;
if ( F_22 ( V_16 -> V_184 ) ) {
F_48 ( & V_16 -> V_134 , L_17 ) ;
V_137 = F_23 ( V_16 -> V_184 ) ;
goto V_231;
}
V_16 -> V_26 = F_147 () ;
if ( ! V_16 -> V_26 ) {
F_48 ( & V_16 -> V_134 , L_18 ) ;
V_137 = - V_24 ;
goto V_232;
}
F_36 ( V_16 -> V_26 -> V_89 , V_73 ,
sizeof( V_16 -> V_26 -> V_89 ) ) ;
V_16 -> V_26 -> V_233 = & V_234 ;
V_16 -> V_26 -> V_235 = & V_236 ;
V_16 -> V_26 -> V_237 = - 1 ;
V_16 -> V_26 -> V_238 = V_239 ;
V_16 -> V_26 -> V_188 = & V_16 -> V_188 ;
V_16 -> V_26 -> V_134 = & V_16 -> V_134 ;
V_137 = F_148 ( V_16 -> V_26 , V_240 , - 1 ) ;
if ( V_137 ) {
F_48 ( & V_16 -> V_134 , L_19 ) ;
goto V_241;
}
F_149 ( V_16 -> V_26 , V_16 ) ;
F_150 ( & V_16 -> V_134 ,
L_20 ,
V_16 -> V_26 -> V_84 ) ;
V_16 -> V_242 = F_147 () ;
if ( ! V_16 -> V_242 ) {
F_48 ( & V_16 -> V_134 , L_18 ) ;
V_137 = - V_24 ;
goto V_243;
}
F_36 ( V_16 -> V_242 -> V_89 , V_73 ,
sizeof( V_16 -> V_242 -> V_89 ) ) ;
V_16 -> V_242 -> V_233 = & V_234 ;
V_16 -> V_242 -> V_235 = & V_236 ;
V_16 -> V_242 -> V_237 = - 1 ;
V_16 -> V_242 -> V_238 = V_239 ;
V_16 -> V_242 -> V_188 = & V_16 -> V_188 ;
V_16 -> V_242 -> V_134 = & V_16 -> V_134 ;
V_137 = F_148 ( V_16 -> V_242 , V_240 , - 1 ) ;
if ( V_137 ) {
F_48 ( & V_16 -> V_134 , L_19 ) ;
goto V_244;
}
F_149 ( V_16 -> V_242 , V_16 ) ;
F_150 ( & V_16 -> V_134 ,
L_21 ,
V_16 -> V_242 -> V_84 ) ;
F_151 ( V_215 , V_16 ) ;
F_152 ( & V_215 -> V_190 ) ;
F_150 ( & V_16 -> V_134 , L_22 ) ;
return 0 ;
V_244:
V_239 ( V_16 -> V_242 ) ;
V_243:
F_153 ( V_16 -> V_26 ) ;
V_241:
V_239 ( V_16 -> V_26 ) ;
V_232:
F_154 ( V_16 -> V_184 ) ;
V_231:
F_155 ( V_16 -> V_33 ) ;
V_230:
F_156 ( & V_16 -> V_134 ) ;
V_228:
F_157 ( V_16 -> V_226 ) ;
F_158 ( V_16 -> V_226 ) ;
V_227:
F_159 ( V_16 -> V_203 , V_16 ) ;
V_225:
F_160 ( V_16 -> V_1 ) ;
V_224:
F_161 ( V_16 -> V_221 ) ;
F_162 ( V_16 -> V_221 -> V_222 , F_136 ( V_16 -> V_221 ) ) ;
V_220:
F_24 ( V_16 ) ;
return V_137 ;
}
static int F_163 ( struct V_214 * V_215 )
{
struct V_15 * V_16 = F_164 ( V_215 ) ;
F_165 ( V_16 -> V_190 ) ;
F_153 ( V_16 -> V_242 ) ;
V_239 ( V_16 -> V_242 ) ;
F_153 ( V_16 -> V_26 ) ;
V_239 ( V_16 -> V_26 ) ;
F_154 ( V_16 -> V_184 ) ;
F_155 ( V_16 -> V_33 ) ;
F_156 ( & V_16 -> V_134 ) ;
F_157 ( V_16 -> V_226 ) ;
F_158 ( V_16 -> V_226 ) ;
F_159 ( V_16 -> V_203 , V_16 ) ;
F_160 ( V_16 -> V_1 ) ;
F_161 ( V_16 -> V_221 ) ;
F_162 ( V_16 -> V_221 -> V_222 , F_136 ( V_16 -> V_221 ) ) ;
F_24 ( V_16 ) ;
return 0 ;
}
static int F_166 ( struct V_245 * V_190 )
{
return 0 ;
}
static int F_167 ( struct V_245 * V_190 )
{
struct V_15 * V_16 = F_168 ( V_190 ) ;
F_8 ( V_16 -> V_1 ) ;
F_10 ( V_16 -> V_1 ) ;
F_12 ( V_16 -> V_1 ) ;
F_14 ( V_16 -> V_1 ) ;
return 0 ;
}
static int T_4
F_169 ( void )
{
int V_137 ;
F_170 ( L_23 ) ;
V_137 = F_171 ( & V_246 ) ;
if ( V_137 )
F_100 ( L_24 , V_135 ) ;
return V_137 ;
}
static void T_5
F_172 ( void )
{
F_173 ( & V_246 ) ;
}
