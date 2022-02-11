static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 += V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_5 + V_2 -> V_4 ) & V_2 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_7 )
{
V_2 -> V_5 = V_2 -> V_4 = 0 ;
V_2 -> V_6 = V_7 - 1 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 -= V_3 ;
V_2 -> V_5 += V_3 ;
V_2 -> V_5 &= V_2 -> V_6 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_4 == 0 ;
}
static inline int F_6 ( int V_8 )
{
return V_8 & ( V_9 - 1 ) ;
}
static struct V_10 * F_7 ( int V_8 )
{
int V_11 ;
struct V_10 * V_12 ;
V_11 = F_6 ( V_8 ) ;
F_8 (con, &connection_hash[r], list) {
if ( V_12 -> V_8 == V_8 )
return V_12 ;
}
return NULL ;
}
static struct V_10 * F_9 ( int V_8 , T_1 V_13 )
{
struct V_10 * V_12 = NULL ;
int V_11 ;
V_12 = F_7 ( V_8 ) ;
if ( V_12 || ! V_13 )
return V_12 ;
V_12 = F_10 ( V_14 , V_13 ) ;
if ( ! V_12 )
return NULL ;
V_11 = F_6 ( V_8 ) ;
F_11 ( & V_12 -> V_15 , & V_16 [ V_11 ] ) ;
V_12 -> V_8 = V_8 ;
F_12 ( & V_12 -> V_17 ) ;
F_13 ( & V_12 -> V_18 ) ;
F_14 ( & V_12 -> V_19 ) ;
F_15 ( & V_12 -> V_20 , V_21 ) ;
F_15 ( & V_12 -> V_22 , V_23 ) ;
if ( V_12 -> V_8 ) {
struct V_10 * V_24 = F_7 ( 0 ) ;
V_12 -> V_25 = V_24 -> V_25 ;
if ( ! V_12 -> V_26 )
V_12 -> V_26 = V_24 -> V_26 ;
}
return V_12 ;
}
static void F_16 ( void (* F_17)( struct V_10 * V_27 ) )
{
int V_28 ;
struct V_29 * V_3 ;
struct V_10 * V_12 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ ) {
F_18 (con, n, &connection_hash[i], list)
F_17 ( V_12 ) ;
}
}
static struct V_10 * F_19 ( int V_8 , T_1 V_30 )
{
struct V_10 * V_12 ;
F_20 ( & V_31 ) ;
V_12 = F_9 ( V_8 , V_30 ) ;
F_21 ( & V_31 ) ;
return V_12 ;
}
static struct V_32 * F_22 ( int V_8 )
{
struct V_32 * V_33 ;
F_23 (na, &dlm_node_addrs, list) {
if ( V_33 -> V_8 == V_8 )
return V_33 ;
}
return NULL ;
}
static int F_24 ( struct V_34 * V_35 , struct V_34 * V_36 )
{
switch ( V_35 -> V_37 ) {
case V_38 : {
struct V_39 * V_40 = (struct V_39 * ) V_35 ;
struct V_39 * V_41 = (struct V_39 * ) V_36 ;
if ( V_40 -> V_42 . V_43 != V_41 -> V_42 . V_43 )
return 0 ;
if ( V_40 -> V_44 != V_41 -> V_44 )
return 0 ;
break;
}
case V_45 : {
struct V_46 * V_40 = (struct V_46 * ) V_35 ;
struct V_46 * V_41 = (struct V_46 * ) V_36 ;
if ( ! F_25 ( & V_40 -> V_47 , & V_41 -> V_47 ) )
return 0 ;
if ( V_40 -> V_48 != V_41 -> V_48 )
return 0 ;
break;
}
default:
return 0 ;
}
return 1 ;
}
static int F_26 ( int V_8 , struct V_34 * V_49 ,
struct V_50 * V_51 , bool V_52 )
{
struct V_34 V_53 ;
struct V_32 * V_33 ;
if ( ! V_54 )
return - 1 ;
F_27 ( & V_55 ) ;
V_33 = F_22 ( V_8 ) ;
if ( V_33 && V_33 -> V_56 ) {
memcpy ( & V_53 , V_33 -> V_57 [ V_33 -> V_58 ] ,
sizeof( struct V_34 ) ) ;
if ( V_52 ) {
V_33 -> V_58 ++ ;
if ( V_33 -> V_58 == V_33 -> V_56 )
V_33 -> V_58 = 0 ;
}
}
F_28 ( & V_55 ) ;
if ( ! V_33 )
return - V_59 ;
if ( ! V_33 -> V_56 )
return - V_60 ;
if ( V_49 )
memcpy ( V_49 , & V_53 , sizeof( struct V_34 ) ) ;
if ( ! V_51 )
return 0 ;
if ( V_61 [ 0 ] -> V_37 == V_38 ) {
struct V_39 * V_62 = (struct V_39 * ) & V_53 ;
struct V_39 * V_63 = (struct V_39 * ) V_51 ;
V_63 -> V_42 . V_43 = V_62 -> V_42 . V_43 ;
} else {
struct V_46 * V_64 = (struct V_46 * ) & V_53 ;
struct V_46 * V_65 = (struct V_46 * ) V_51 ;
V_65 -> V_47 = V_64 -> V_47 ;
}
return 0 ;
}
static int F_29 ( struct V_34 * V_57 , int * V_8 )
{
struct V_32 * V_33 ;
int V_66 = - V_59 ;
int V_67 ;
F_27 ( & V_55 ) ;
F_23 (na, &dlm_node_addrs, list) {
if ( ! V_33 -> V_56 )
continue;
for ( V_67 = 0 ; V_67 < V_33 -> V_56 ; V_67 ++ ) {
if ( F_24 ( V_33 -> V_57 [ V_67 ] , V_57 ) ) {
* V_8 = V_33 -> V_8 ;
V_66 = 0 ;
goto V_68;
}
}
}
V_68:
F_28 ( & V_55 ) ;
return V_66 ;
}
int F_30 ( int V_8 , struct V_34 * V_57 , int V_4 )
{
struct V_34 * V_69 ;
struct V_32 * V_70 , * V_33 ;
V_70 = F_31 ( sizeof( struct V_32 ) , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
V_69 = F_31 ( sizeof( struct V_34 ) , V_71 ) ;
if ( ! V_69 ) {
F_32 ( V_70 ) ;
return - V_72 ;
}
memcpy ( V_69 , V_57 , V_4 ) ;
F_27 ( & V_55 ) ;
V_33 = F_22 ( V_8 ) ;
if ( ! V_33 ) {
V_70 -> V_8 = V_8 ;
V_70 -> V_57 [ 0 ] = V_69 ;
V_70 -> V_56 = 1 ;
F_33 ( & V_70 -> V_15 , & V_73 ) ;
F_28 ( & V_55 ) ;
return 0 ;
}
if ( V_33 -> V_56 >= V_74 ) {
F_28 ( & V_55 ) ;
F_32 ( V_69 ) ;
F_32 ( V_70 ) ;
return - V_75 ;
}
V_33 -> V_57 [ V_33 -> V_56 ++ ] = V_69 ;
F_28 ( & V_55 ) ;
F_32 ( V_70 ) ;
return 0 ;
}
static void F_34 ( struct V_76 * V_77 )
{
struct V_10 * V_12 = F_35 ( V_77 ) ;
if ( V_12 && ! F_36 ( V_78 , & V_12 -> V_79 ) )
F_37 ( V_80 , & V_12 -> V_22 ) ;
}
static void F_38 ( struct V_76 * V_77 )
{
struct V_10 * V_12 = F_35 ( V_77 ) ;
if ( ! V_12 )
return;
F_39 ( V_81 , & V_12 -> V_76 -> V_79 ) ;
if ( F_40 ( V_82 , & V_12 -> V_79 ) ) {
V_12 -> V_76 -> V_77 -> V_83 -- ;
F_39 ( V_84 , & V_12 -> V_76 -> V_79 ) ;
}
if ( ! F_36 ( V_85 , & V_12 -> V_79 ) )
F_37 ( V_86 , & V_12 -> V_20 ) ;
}
static inline void F_41 ( struct V_10 * V_12 )
{
if ( F_42 ( V_87 , & V_12 -> V_79 ) )
return;
if ( ! F_36 ( V_88 , & V_12 -> V_79 ) )
F_37 ( V_86 , & V_12 -> V_20 ) ;
}
static void F_43 ( struct V_76 * V_77 )
{
if ( V_77 -> V_89 ) {
if ( V_77 -> V_89 == V_90 )
F_34 ( V_77 ) ;
} else if ( V_77 -> V_91 == V_92 ) {
F_38 ( V_77 ) ;
}
}
int F_44 ( int V_8 )
{
struct V_10 * V_12 ;
if ( V_8 == F_45 () )
return 0 ;
V_12 = F_19 ( V_8 , V_71 ) ;
if ( ! V_12 )
return - V_72 ;
F_41 ( V_12 ) ;
return 0 ;
}
static void F_46 ( struct V_76 * V_77 )
{
struct V_10 * V_12 ;
struct V_34 V_93 ;
int V_94 ;
void (* F_47)( struct V_76 * ) = NULL ;
F_48 ( & V_77 -> V_95 ) ;
V_12 = F_35 ( V_77 ) ;
if ( V_12 == NULL )
goto V_96;
F_47 = V_12 -> V_97 ;
if ( V_12 -> V_76 == NULL ||
F_49 ( V_12 -> V_76 , (struct V_50 * ) & V_93 , & V_94 ) ) {
F_50 ( V_98 L_1
L_2
L_3 , F_45 () ,
V_12 -> V_8 , V_99 . V_100 ,
V_77 -> V_101 , V_77 -> V_102 ) ;
} else if ( V_93 . V_37 == V_38 ) {
struct V_39 * V_103 = (struct V_39 * ) & V_93 ;
F_50 ( V_98 L_1
L_4
L_3 , F_45 () ,
V_12 -> V_8 , & V_103 -> V_42 . V_43 ,
V_99 . V_100 , V_77 -> V_101 ,
V_77 -> V_102 ) ;
} else {
struct V_46 * V_104 = (struct V_46 * ) & V_93 ;
F_50 ( V_98 L_1
L_5
L_6 , F_45 () ,
V_12 -> V_8 , V_104 -> V_47 . V_105 [ 0 ] ,
V_104 -> V_47 . V_105 [ 1 ] ,
V_104 -> V_47 . V_105 [ 2 ] ,
V_104 -> V_47 . V_105 [ 3 ] ,
V_99 . V_100 , V_77 -> V_101 ,
V_77 -> V_102 ) ;
}
V_96:
F_51 ( & V_77 -> V_95 ) ;
if ( F_47 )
F_47 ( V_77 ) ;
}
static void F_52 ( struct V_10 * V_12 , struct V_76 * V_77 )
{
F_53 ( V_77 ) ;
V_12 -> V_106 = V_77 -> V_107 ;
V_12 -> V_108 = V_77 -> V_109 ;
V_12 -> V_110 = V_77 -> V_111 ;
V_12 -> V_97 = V_77 -> V_112 ;
F_54 ( V_77 ) ;
}
static void F_55 ( struct V_10 * V_12 , struct V_76 * V_77 )
{
F_56 ( & V_77 -> V_95 ) ;
F_53 ( V_77 ) ;
V_77 -> V_113 = NULL ;
V_77 -> V_107 = V_12 -> V_106 ;
V_77 -> V_109 = V_12 -> V_108 ;
V_77 -> V_111 = V_12 -> V_110 ;
V_77 -> V_112 = V_12 -> V_97 ;
F_54 ( V_77 ) ;
F_57 ( & V_77 -> V_95 ) ;
}
static void F_58 ( struct V_114 * V_76 , struct V_10 * V_12 )
{
struct V_76 * V_77 = V_76 -> V_77 ;
F_56 ( & V_77 -> V_95 ) ;
V_12 -> V_76 = V_76 ;
V_77 -> V_113 = V_12 ;
if ( ! F_42 ( V_115 , & V_12 -> V_79 ) )
F_52 ( V_12 , V_77 ) ;
V_77 -> V_107 = F_34 ;
V_77 -> V_111 = F_38 ;
V_77 -> V_109 = F_43 ;
V_77 -> V_116 = V_71 ;
V_77 -> V_112 = F_46 ;
F_57 ( & V_77 -> V_95 ) ;
}
static void F_59 ( struct V_34 * V_93 , T_2 V_117 ,
int * V_118 )
{
V_93 -> V_37 = V_61 [ 0 ] -> V_37 ;
if ( V_93 -> V_37 == V_38 ) {
struct V_39 * V_119 = (struct V_39 * ) V_93 ;
V_119 -> V_44 = F_60 ( V_117 ) ;
* V_118 = sizeof( struct V_39 ) ;
memset ( & V_119 -> V_120 , 0 , sizeof( V_119 -> V_120 ) ) ;
} else {
struct V_46 * V_121 = (struct V_46 * ) V_93 ;
V_121 -> V_48 = F_60 ( V_117 ) ;
* V_118 = sizeof( struct V_46 ) ;
}
memset ( ( char * ) V_93 + * V_118 , 0 , sizeof( struct V_34 ) - * V_118 ) ;
}
static void F_61 ( struct V_10 * V_12 , bool V_122 ,
bool V_123 , bool V_124 )
{
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_39 ( V_85 , & V_12 -> V_79 ) ;
if ( V_123 && F_62 ( & V_12 -> V_20 ) )
F_63 ( L_7 , V_12 -> V_8 ) ;
if ( V_124 && F_62 ( & V_12 -> V_22 ) )
F_63 ( L_8 , V_12 -> V_8 ) ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 ) {
if ( ! F_42 ( V_115 , & V_12 -> V_79 ) )
F_55 ( V_12 , V_12 -> V_76 -> V_77 ) ;
F_64 ( V_12 -> V_76 ) ;
V_12 -> V_76 = NULL ;
}
if ( V_12 -> V_125 && V_122 ) {
F_61 ( V_12 -> V_125 , false , true , true ) ;
}
if ( V_12 -> V_126 ) {
F_65 ( V_12 -> V_126 ) ;
V_12 -> V_126 = NULL ;
}
V_12 -> V_127 = 0 ;
F_21 ( & V_12 -> V_17 ) ;
}
static int F_66 ( struct V_10 * V_12 )
{
int V_128 = 0 ;
struct V_129 V_130 = {} ;
struct V_131 V_132 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_133 = 0 ;
int V_134 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 == NULL ) {
V_128 = - V_135 ;
goto V_136;
}
if ( V_12 -> V_8 == 0 ) {
V_128 = - V_137 ;
goto V_136;
}
if ( V_12 -> V_126 == NULL ) {
V_12 -> V_126 = F_67 ( V_138 ) ;
if ( V_12 -> V_126 == NULL )
goto V_139;
F_3 ( & V_12 -> V_2 , V_140 ) ;
}
V_132 [ 0 ] . V_141 = V_12 -> V_2 . V_5 - F_2 ( & V_12 -> V_2 ) ;
V_132 [ 0 ] . V_142 = F_68 ( V_12 -> V_126 ) + F_2 ( & V_12 -> V_2 ) ;
V_132 [ 1 ] . V_141 = 0 ;
V_134 = 1 ;
if ( F_2 ( & V_12 -> V_2 ) >= V_12 -> V_2 . V_5 ) {
V_132 [ 0 ] . V_141 = V_140 - F_2 ( & V_12 -> V_2 ) ;
V_132 [ 1 ] . V_141 = V_12 -> V_2 . V_5 ;
V_132 [ 1 ] . V_142 = F_68 ( V_12 -> V_126 ) ;
V_134 = 2 ;
}
V_4 = V_132 [ 0 ] . V_141 + V_132 [ 1 ] . V_141 ;
V_11 = V_128 = F_69 ( V_12 -> V_76 , & V_130 , V_132 , V_134 , V_4 ,
V_143 | V_144 ) ;
if ( V_128 <= 0 )
goto V_136;
else if ( V_128 == V_4 )
V_133 = 1 ;
F_1 ( & V_12 -> V_2 , V_128 ) ;
V_128 = F_70 ( V_12 -> V_8 ,
F_68 ( V_12 -> V_126 ) ,
V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_140 ) ;
if ( V_128 == - V_145 ) {
F_63 ( L_9 ,
F_68 ( V_12 -> V_126 ) , V_12 -> V_2 . V_5 ,
V_12 -> V_2 . V_4 , V_11 ) ;
}
if ( V_128 < 0 )
goto V_136;
F_4 ( & V_12 -> V_2 , V_128 ) ;
if ( F_5 ( & V_12 -> V_2 ) && ! V_133 ) {
F_65 ( V_12 -> V_126 ) ;
V_12 -> V_126 = NULL ;
}
if ( V_133 )
goto V_139;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_139:
if ( ! F_36 ( V_78 , & V_12 -> V_79 ) )
F_37 ( V_80 , & V_12 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - V_135 ;
V_136:
F_21 ( & V_12 -> V_17 ) ;
if ( V_128 != - V_135 ) {
F_61 ( V_12 , false , true , false ) ;
}
if ( V_128 == 0 )
V_128 = - V_135 ;
return V_128 ;
}
static int F_71 ( struct V_10 * V_12 )
{
int V_146 ;
struct V_34 V_147 ;
struct V_114 * V_148 ;
int V_4 ;
int V_8 ;
struct V_10 * V_149 ;
struct V_10 * V_150 ;
F_20 ( & V_31 ) ;
if ( ! V_151 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_146 = F_72 ( & V_152 , V_61 [ 0 ] -> V_37 ,
V_153 , V_154 , & V_148 ) ;
if ( V_146 < 0 )
return - V_72 ;
F_73 ( & V_12 -> V_17 , 0 ) ;
V_146 = - V_155 ;
if ( V_12 -> V_76 == NULL )
goto V_156;
V_148 -> type = V_12 -> V_76 -> type ;
V_148 -> V_157 = V_12 -> V_76 -> V_157 ;
V_146 = V_12 -> V_76 -> V_157 -> V_158 ( V_12 -> V_76 , V_148 , V_159 ) ;
if ( V_146 < 0 )
goto V_156;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_148 -> V_157 -> V_160 ( V_148 , (struct V_50 * ) & V_147 ,
& V_4 , 2 ) ) {
V_146 = - V_161 ;
goto V_156;
}
F_59 ( & V_147 , 0 , & V_4 ) ;
if ( F_29 ( & V_147 , & V_8 ) ) {
unsigned char * V_162 = ( unsigned char * ) & V_147 ;
F_63 ( L_10 ) ;
F_74 ( L_11 , V_163 ,
V_162 , sizeof( struct V_34 ) ) ;
F_64 ( V_148 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - 1 ;
}
F_63 ( L_12 , V_8 ) ;
V_149 = F_19 ( V_8 , V_71 ) ;
if ( ! V_149 ) {
V_146 = - V_72 ;
goto V_156;
}
F_73 ( & V_149 -> V_17 , 1 ) ;
if ( V_149 -> V_76 ) {
struct V_10 * V_125 = V_149 -> V_125 ;
if ( ! V_125 ) {
V_125 = F_10 ( V_14 , V_71 ) ;
if ( ! V_125 ) {
F_63 ( L_13 ) ;
F_21 ( & V_149 -> V_17 ) ;
V_146 = - V_72 ;
goto V_156;
}
V_125 -> V_8 = V_8 ;
V_125 -> V_26 = F_66 ;
F_12 ( & V_125 -> V_17 ) ;
F_15 ( & V_125 -> V_20 , V_21 ) ;
F_15 ( & V_125 -> V_22 , V_23 ) ;
F_75 ( V_115 , & V_125 -> V_79 ) ;
}
if ( ! V_125 -> V_76 ) {
V_149 -> V_125 = V_125 ;
V_125 -> V_76 = V_148 ;
V_148 -> V_77 -> V_113 = V_125 ;
F_58 ( V_148 , V_125 ) ;
V_150 = V_125 ;
}
else {
F_76 ( L_14 , V_8 ) ;
V_146 = - V_135 ;
F_21 ( & V_149 -> V_17 ) ;
goto V_156;
}
}
else {
V_148 -> V_77 -> V_113 = V_149 ;
V_149 -> V_26 = F_66 ;
F_58 ( V_148 , V_149 ) ;
V_150 = V_149 ;
}
F_21 ( & V_149 -> V_17 ) ;
if ( ! F_36 ( V_78 , & V_150 -> V_79 ) )
F_37 ( V_80 , & V_150 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_156:
F_21 ( & V_12 -> V_17 ) ;
F_64 ( V_148 ) ;
if ( V_146 != - V_135 )
F_63 ( L_15 , V_146 ) ;
return V_146 ;
}
static int F_77 ( struct V_10 * V_12 )
{
struct V_164 V_165 ;
int V_8 ;
int V_166 , V_128 ;
int V_118 ;
struct V_10 * V_149 ;
struct V_10 * V_150 ;
struct V_114 * V_148 ;
F_20 ( & V_31 ) ;
if ( ! V_151 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
F_73 ( & V_12 -> V_17 , 0 ) ;
V_128 = F_78 ( V_12 -> V_76 , & V_148 , V_159 ) ;
if ( V_128 < 0 )
goto V_156;
memset ( & V_165 , 0 , sizeof( struct V_164 ) ) ;
V_166 = sizeof( struct V_164 ) ;
V_128 = F_79 ( V_148 , V_167 , V_168 ,
( char * ) & V_165 , & V_166 ) ;
if ( V_128 < 0 ) {
F_63 ( L_16 , V_128 ) ;
goto V_156;
}
F_59 ( & V_165 . V_169 , 0 , & V_118 ) ;
if ( F_29 ( & V_165 . V_169 , & V_8 ) ) {
unsigned char * V_162 = ( unsigned char * ) & V_165 . V_169 ;
F_63 ( L_17 ) ;
F_74 ( L_11 , V_163 ,
V_162 , sizeof( struct V_34 ) ) ;
goto V_156;
}
V_149 = F_19 ( V_8 , V_71 ) ;
if ( ! V_149 ) {
V_128 = - V_72 ;
goto V_156;
}
F_73 ( & V_149 -> V_17 , 1 ) ;
if ( V_149 -> V_76 ) {
struct V_10 * V_125 = V_149 -> V_125 ;
if ( ! V_125 ) {
V_125 = F_10 ( V_14 , V_71 ) ;
if ( ! V_125 ) {
F_63 ( L_13 ) ;
F_21 ( & V_149 -> V_17 ) ;
V_128 = - V_72 ;
goto V_156;
}
V_125 -> V_8 = V_8 ;
V_125 -> V_26 = F_66 ;
F_12 ( & V_125 -> V_17 ) ;
F_15 ( & V_125 -> V_20 , V_21 ) ;
F_15 ( & V_125 -> V_22 , V_23 ) ;
F_75 ( V_115 , & V_125 -> V_79 ) ;
}
if ( ! V_125 -> V_76 ) {
V_149 -> V_125 = V_125 ;
V_125 -> V_76 = V_148 ;
V_148 -> V_77 -> V_113 = V_125 ;
F_58 ( V_148 , V_125 ) ;
V_150 = V_125 ;
} else {
F_76 ( L_14 , V_8 ) ;
V_128 = - V_135 ;
F_21 ( & V_149 -> V_17 ) ;
goto V_156;
}
} else {
V_148 -> V_77 -> V_113 = V_149 ;
V_149 -> V_26 = F_66 ;
F_58 ( V_148 , V_149 ) ;
V_150 = V_149 ;
}
F_63 ( L_18 , V_8 ) ;
F_21 ( & V_149 -> V_17 ) ;
if ( ! F_36 ( V_78 , & V_150 -> V_79 ) )
F_37 ( V_80 , & V_150 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_156:
F_21 ( & V_12 -> V_17 ) ;
if ( V_148 )
F_64 ( V_148 ) ;
if ( V_128 != - V_135 )
F_63 ( L_15 , V_128 ) ;
return V_128 ;
}
static void F_80 ( struct V_170 * V_171 )
{
F_65 ( V_171 -> V_172 ) ;
F_32 ( V_171 ) ;
}
static void F_81 ( struct V_170 * V_171 , int V_173 )
{
V_171 -> V_174 += V_173 ;
V_171 -> V_4 -= V_173 ;
if ( V_171 -> V_4 == 0 && V_171 -> V_175 == 0 ) {
F_82 ( & V_171 -> V_15 ) ;
F_80 ( V_171 ) ;
}
}
static int F_83 ( struct V_10 * V_12 , T_2 V_117 )
{
struct V_34 V_176 ;
int V_28 , V_118 , V_146 = 0 ;
for ( V_28 = 0 ; V_28 < V_54 ; V_28 ++ ) {
memcpy ( & V_176 , V_61 [ V_28 ] , sizeof( V_176 ) ) ;
F_59 ( & V_176 , V_117 , & V_118 ) ;
if ( ! V_28 )
V_146 = F_84 ( V_12 -> V_76 ,
(struct V_50 * ) & V_176 ,
V_118 ) ;
else
V_146 = F_85 ( V_12 -> V_76 , V_177 ,
V_178 ,
( char * ) & V_176 , V_118 ) ;
if ( V_146 < 0 ) {
F_63 ( L_19 ,
V_117 , V_28 + 1 , V_146 ) ;
break;
}
}
return V_146 ;
}
static void F_86 ( struct V_10 * V_12 )
{
struct V_34 V_179 ;
int V_180 = 1 ;
int V_146 ;
int V_118 ;
struct V_114 * V_76 ;
if ( V_12 -> V_8 == 0 ) {
F_63 ( L_20 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_127 ++ > V_181 )
goto V_96;
if ( V_12 -> V_76 ) {
F_63 ( L_21 , V_12 -> V_8 ) ;
goto V_96;
}
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_146 = F_26 ( V_12 -> V_8 , & V_179 , NULL , true ) ;
if ( V_146 < 0 ) {
F_63 ( L_22 , V_12 -> V_8 ) ;
goto V_96;
}
V_146 = F_72 ( & V_152 , V_61 [ 0 ] -> V_37 ,
V_153 , V_167 , & V_76 ) ;
if ( V_146 < 0 )
goto V_182;
V_76 -> V_77 -> V_113 = V_12 ;
V_12 -> V_26 = F_66 ;
V_12 -> V_25 = F_86 ;
F_58 ( V_76 , V_12 ) ;
if ( F_83 ( V_12 , 0 ) )
goto V_183;
F_59 ( & V_179 , V_99 . V_100 , & V_118 ) ;
F_63 ( L_23 , V_12 -> V_8 ) ;
F_85 ( V_76 , V_184 , V_185 , ( char * ) & V_180 ,
sizeof( V_180 ) ) ;
V_146 = V_76 -> V_157 -> V_186 ( V_76 , (struct V_50 * ) & V_179 , V_118 ,
V_159 ) ;
if ( V_146 == - V_187 )
V_146 = 0 ;
if ( V_146 == 0 )
goto V_96;
V_183:
V_12 -> V_76 = NULL ;
F_64 ( V_76 ) ;
V_182:
if ( V_146 != - V_188 &&
V_146 != - V_189 &&
V_146 != - V_190 &&
V_146 != - V_137 &&
V_146 != - V_191 ) {
F_63 ( L_24 , V_12 -> V_8 ,
V_12 -> V_127 , V_146 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_87 ( 1000 ) ;
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_41 ( V_12 ) ;
return;
}
V_96:
F_21 ( & V_12 -> V_17 ) ;
F_75 ( V_85 , & V_12 -> V_79 ) ;
}
static void F_88 ( struct V_10 * V_12 )
{
struct V_34 V_93 , V_192 ;
int V_118 ;
struct V_114 * V_76 = NULL ;
int V_180 = 1 ;
int V_146 ;
if ( V_12 -> V_8 == 0 ) {
F_63 ( L_20 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_127 ++ > V_181 )
goto V_96;
if ( V_12 -> V_76 )
goto V_96;
V_146 = F_72 ( & V_152 , V_61 [ 0 ] -> V_37 ,
V_153 , V_154 , & V_76 ) ;
if ( V_146 < 0 )
goto V_193;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_146 = F_26 ( V_12 -> V_8 , & V_93 , NULL , false ) ;
if ( V_146 < 0 ) {
F_63 ( L_22 , V_12 -> V_8 ) ;
goto V_193;
}
V_76 -> V_77 -> V_113 = V_12 ;
V_12 -> V_26 = F_66 ;
V_12 -> V_25 = F_88 ;
F_58 ( V_76 , V_12 ) ;
memcpy ( & V_192 , V_61 [ 0 ] , sizeof( V_192 ) ) ;
F_59 ( & V_192 , 0 , & V_118 ) ;
V_146 = V_76 -> V_157 -> V_194 ( V_76 , (struct V_50 * ) & V_192 ,
V_118 ) ;
if ( V_146 < 0 ) {
F_63 ( L_25 , V_146 ) ;
}
F_59 ( & V_93 , V_99 . V_100 , & V_118 ) ;
F_63 ( L_23 , V_12 -> V_8 ) ;
F_85 ( V_76 , V_184 , V_185 , ( char * ) & V_180 ,
sizeof( V_180 ) ) ;
V_146 = V_76 -> V_157 -> V_186 ( V_76 , (struct V_50 * ) & V_93 , V_118 ,
V_159 ) ;
if ( V_146 == - V_187 )
V_146 = 0 ;
if ( V_146 == 0 )
goto V_96;
V_193:
if ( V_12 -> V_76 ) {
F_64 ( V_12 -> V_76 ) ;
V_12 -> V_76 = NULL ;
} else if ( V_76 ) {
F_64 ( V_76 ) ;
}
if ( V_146 != - V_188 &&
V_146 != - V_189 &&
V_146 != - V_190 &&
V_146 != - V_137 &&
V_146 != - V_191 ) {
F_63 ( L_24 , V_12 -> V_8 ,
V_12 -> V_127 , V_146 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_87 ( 1000 ) ;
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_41 ( V_12 ) ;
return;
}
V_96:
F_21 ( & V_12 -> V_17 ) ;
F_75 ( V_85 , & V_12 -> V_79 ) ;
return;
}
static struct V_114 * F_89 ( struct V_10 * V_12 ,
struct V_34 * V_93 )
{
struct V_114 * V_76 = NULL ;
int V_146 = 0 ;
int V_180 = 1 ;
int V_118 ;
if ( V_61 [ 0 ] -> V_37 == V_38 )
V_118 = sizeof( struct V_39 ) ;
else
V_118 = sizeof( struct V_46 ) ;
V_146 = F_72 ( & V_152 , V_61 [ 0 ] -> V_37 ,
V_153 , V_154 , & V_76 ) ;
if ( V_146 < 0 ) {
F_63 ( L_26 ) ;
goto V_195;
}
F_85 ( V_76 , V_184 , V_185 , ( char * ) & V_180 ,
sizeof( V_180 ) ) ;
V_146 = F_85 ( V_76 , V_196 , V_197 ,
( char * ) & V_180 , sizeof( V_180 ) ) ;
if ( V_146 < 0 ) {
F_63 ( L_27 , V_146 ) ;
}
V_76 -> V_77 -> V_113 = V_12 ;
V_12 -> V_26 = F_71 ;
V_12 -> V_25 = F_88 ;
F_59 ( V_93 , V_99 . V_100 , & V_118 ) ;
V_146 = V_76 -> V_157 -> V_194 ( V_76 , (struct V_50 * ) V_93 , V_118 ) ;
if ( V_146 < 0 ) {
F_63 ( L_28 , V_99 . V_100 ) ;
F_64 ( V_76 ) ;
V_76 = NULL ;
V_12 -> V_76 = NULL ;
goto V_195;
}
V_146 = F_85 ( V_76 , V_196 , V_198 ,
( char * ) & V_180 , sizeof( V_180 ) ) ;
if ( V_146 < 0 ) {
F_63 ( L_29 , V_146 ) ;
}
V_146 = V_76 -> V_157 -> V_199 ( V_76 , 5 ) ;
if ( V_146 < 0 ) {
F_63 ( L_30 , V_99 . V_100 ) ;
F_64 ( V_76 ) ;
V_76 = NULL ;
goto V_195;
}
V_195:
return V_76 ;
}
static void F_90 ( void )
{
struct V_34 V_53 , * V_57 ;
int V_28 ;
V_54 = 0 ;
for ( V_28 = 0 ; V_28 < V_74 ; V_28 ++ ) {
if ( F_91 ( & V_53 , V_28 ) )
break;
V_57 = F_92 ( & V_53 , sizeof( * V_57 ) , V_71 ) ;
if ( ! V_57 )
break;
V_61 [ V_54 ++ ] = V_57 ;
}
}
static int F_93 ( void )
{
struct V_114 * V_76 = NULL ;
int V_146 = - V_137 ;
struct V_10 * V_12 = F_19 ( 0 , V_71 ) ;
int V_200 = V_201 ;
int V_180 = 1 ;
if ( ! V_12 )
return - V_72 ;
F_63 ( L_31 ) ;
V_146 = F_72 ( & V_152 , V_61 [ 0 ] -> V_37 ,
V_153 , V_167 , & V_76 ) ;
if ( V_146 < 0 ) {
F_63 ( L_32 ) ;
goto V_96;
}
V_146 = F_85 ( V_76 , V_196 , V_202 ,
( char * ) & V_200 , sizeof( V_200 ) ) ;
if ( V_146 )
F_63 ( L_33 , V_146 ) ;
V_146 = F_85 ( V_76 , V_177 , V_203 , ( char * ) & V_180 ,
sizeof( V_180 ) ) ;
if ( V_146 < 0 )
F_63 ( L_34 , V_146 ) ;
F_56 ( & V_76 -> V_77 -> V_95 ) ;
V_76 -> V_77 -> V_113 = V_12 ;
V_12 -> V_76 = V_76 ;
V_12 -> V_76 -> V_77 -> V_107 = F_34 ;
V_12 -> V_26 = F_77 ;
V_12 -> V_25 = F_86 ;
F_57 ( & V_76 -> V_77 -> V_95 ) ;
if ( F_83 ( V_12 , V_99 . V_100 ) )
goto V_204;
V_146 = V_76 -> V_157 -> V_199 ( V_76 , 5 ) ;
if ( V_146 < 0 ) {
F_63 ( L_35 ) ;
goto V_204;
}
return 0 ;
V_204:
F_64 ( V_76 ) ;
V_12 -> V_76 = NULL ;
V_96:
return V_146 ;
}
static int F_94 ( void )
{
struct V_114 * V_76 = NULL ;
struct V_10 * V_12 = F_19 ( 0 , V_71 ) ;
int V_146 = - V_137 ;
if ( ! V_12 )
return - V_72 ;
if ( V_61 [ 1 ] != NULL ) {
F_63 ( L_36
L_37 ) ;
return - V_137 ;
}
F_63 ( L_38 ) ;
V_76 = F_89 ( V_12 , V_61 [ 0 ] ) ;
if ( V_76 ) {
F_58 ( V_76 , V_12 ) ;
V_146 = 0 ;
}
else {
V_146 = - V_205 ;
}
return V_146 ;
}
static struct V_170 * F_95 ( struct V_10 * V_12 ,
T_1 V_30 )
{
struct V_170 * V_206 ;
V_206 = F_96 ( sizeof( struct V_170 ) , V_30 ) ;
if ( ! V_206 )
return NULL ;
V_206 -> V_172 = F_67 ( V_30 ) ;
if ( ! V_206 -> V_172 ) {
F_32 ( V_206 ) ;
return NULL ;
}
V_206 -> V_174 = 0 ;
V_206 -> V_4 = 0 ;
V_206 -> V_207 = 0 ;
V_206 -> V_175 = 0 ;
V_206 -> V_12 = V_12 ;
return V_206 ;
}
void * F_97 ( int V_8 , int V_4 , T_1 V_30 , char * * V_208 )
{
struct V_10 * V_12 ;
struct V_170 * V_171 ;
int V_174 = 0 ;
V_12 = F_19 ( V_8 , V_30 ) ;
if ( ! V_12 )
return NULL ;
F_27 ( & V_12 -> V_19 ) ;
V_171 = F_98 ( V_12 -> V_18 . V_209 , struct V_170 , V_15 ) ;
if ( ( & V_171 -> V_15 == & V_12 -> V_18 ) ||
( V_140 - V_171 -> V_207 < V_4 ) ) {
V_171 = NULL ;
} else {
V_174 = V_171 -> V_207 ;
V_171 -> V_207 += V_4 ;
V_171 -> V_175 ++ ;
}
F_28 ( & V_12 -> V_19 ) ;
if ( V_171 ) {
V_210:
* V_208 = F_68 ( V_171 -> V_172 ) + V_174 ;
return V_171 ;
}
V_171 = F_95 ( V_12 , V_30 ) ;
if ( V_171 ) {
F_27 ( & V_12 -> V_19 ) ;
V_174 = V_171 -> V_207 ;
V_171 -> V_207 += V_4 ;
V_171 -> V_175 ++ ;
F_99 ( & V_171 -> V_15 , & V_12 -> V_18 ) ;
F_28 ( & V_12 -> V_19 ) ;
goto V_210;
}
return NULL ;
}
void F_100 ( void * V_211 )
{
struct V_170 * V_171 = (struct V_170 * ) V_211 ;
struct V_10 * V_12 = V_171 -> V_12 ;
int V_175 ;
F_27 ( & V_12 -> V_19 ) ;
V_175 = -- V_171 -> V_175 ;
if ( V_175 )
goto V_96;
V_171 -> V_4 = V_171 -> V_207 - V_171 -> V_174 ;
F_28 ( & V_12 -> V_19 ) ;
if ( ! F_36 ( V_85 , & V_12 -> V_79 ) ) {
F_37 ( V_86 , & V_12 -> V_20 ) ;
}
return;
V_96:
F_28 ( & V_12 -> V_19 ) ;
return;
}
static void F_101 ( struct V_10 * V_12 )
{
int V_128 = 0 ;
const int V_212 = V_143 | V_144 ;
struct V_170 * V_171 ;
int V_4 , V_174 ;
int V_213 = 0 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 == NULL )
goto V_214;
F_27 ( & V_12 -> V_19 ) ;
for (; ; ) {
V_171 = F_98 ( V_12 -> V_18 . V_215 , struct V_170 ,
V_15 ) ;
if ( (struct V_216 * ) V_171 == & V_12 -> V_18 )
break;
V_4 = V_171 -> V_4 ;
V_174 = V_171 -> V_174 ;
F_102 ( V_4 == 0 && V_171 -> V_175 == 0 ) ;
F_28 ( & V_12 -> V_19 ) ;
V_128 = 0 ;
if ( V_4 ) {
V_128 = F_103 ( V_12 -> V_76 , V_171 -> V_172 , V_174 , V_4 ,
V_212 ) ;
if ( V_128 == - V_135 || V_128 == 0 ) {
if ( V_128 == - V_135 &&
F_42 ( V_84 , & V_12 -> V_76 -> V_79 ) &&
! F_36 ( V_82 , & V_12 -> V_79 ) ) {
F_75 ( V_81 , & V_12 -> V_76 -> V_79 ) ;
V_12 -> V_76 -> V_77 -> V_83 ++ ;
}
F_104 () ;
goto V_96;
} else if ( V_128 < 0 )
goto V_217;
}
if ( ++ V_213 >= V_218 ) {
F_104 () ;
V_213 = 0 ;
}
F_27 ( & V_12 -> V_19 ) ;
F_81 ( V_171 , V_128 ) ;
}
F_28 ( & V_12 -> V_19 ) ;
V_96:
F_21 ( & V_12 -> V_17 ) ;
return;
V_217:
F_21 ( & V_12 -> V_17 ) ;
F_61 ( V_12 , false , false , true ) ;
F_41 ( V_12 ) ;
return;
V_214:
F_21 ( & V_12 -> V_17 ) ;
F_41 ( V_12 ) ;
}
static void F_105 ( struct V_10 * V_12 )
{
struct V_170 * V_171 , * V_219 ;
F_27 ( & V_12 -> V_19 ) ;
F_106 (e, safe, &con->writequeue, list) {
F_82 ( & V_171 -> V_15 ) ;
F_80 ( V_171 ) ;
}
F_28 ( & V_12 -> V_19 ) ;
}
int F_107 ( int V_8 )
{
struct V_10 * V_12 ;
struct V_32 * V_33 ;
F_63 ( L_39 , V_8 ) ;
V_12 = F_19 ( V_8 , 0 ) ;
if ( V_12 ) {
F_75 ( V_87 , & V_12 -> V_79 ) ;
F_61 ( V_12 , true , true , true ) ;
F_105 ( V_12 ) ;
}
F_27 ( & V_55 ) ;
V_33 = F_22 ( V_8 ) ;
if ( V_33 ) {
F_82 ( & V_33 -> V_15 ) ;
while ( V_33 -> V_56 -- )
F_32 ( V_33 -> V_57 [ V_33 -> V_56 ] ) ;
F_32 ( V_33 ) ;
}
F_28 ( & V_55 ) ;
return 0 ;
}
static void V_23 ( struct V_220 * V_221 )
{
struct V_10 * V_12 = F_108 ( V_221 , struct V_10 , V_22 ) ;
int V_222 ;
F_39 ( V_78 , & V_12 -> V_79 ) ;
do {
V_222 = V_12 -> V_26 ( V_12 ) ;
} while ( ! V_222 );
}
static void V_21 ( struct V_220 * V_221 )
{
struct V_10 * V_12 = F_108 ( V_221 , struct V_10 , V_20 ) ;
if ( F_40 ( V_88 , & V_12 -> V_79 ) )
V_12 -> V_25 ( V_12 ) ;
if ( F_40 ( V_85 , & V_12 -> V_79 ) )
F_101 ( V_12 ) ;
}
static void F_109 ( void )
{
F_16 ( F_105 ) ;
}
static void F_110 ( void )
{
F_111 ( V_80 ) ;
F_111 ( V_86 ) ;
}
static int F_112 ( void )
{
V_80 = F_113 ( L_40 ,
V_223 | V_224 , 1 ) ;
if ( ! V_80 ) {
F_63 ( L_41 ) ;
return - V_72 ;
}
V_86 = F_113 ( L_42 ,
V_223 | V_224 , 1 ) ;
if ( ! V_86 ) {
F_63 ( L_43 ) ;
F_111 ( V_80 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_114 ( struct V_10 * V_12 )
{
V_12 -> V_79 |= 0x0F ;
if ( V_12 -> V_76 && V_12 -> V_76 -> V_77 )
V_12 -> V_76 -> V_77 -> V_113 = NULL ;
}
static void F_115 ( struct V_10 * V_12 )
{
F_61 ( V_12 , true , true , true ) ;
if ( V_12 -> V_125 )
F_116 ( V_14 , V_12 -> V_125 ) ;
F_117 ( & V_12 -> V_15 ) ;
F_116 ( V_14 , V_12 ) ;
}
void F_118 ( void )
{
F_20 ( & V_31 ) ;
V_151 = 0 ;
F_16 ( F_114 ) ;
F_109 () ;
F_16 ( F_115 ) ;
F_21 ( & V_31 ) ;
F_110 () ;
F_119 ( V_14 ) ;
}
int F_120 ( void )
{
int error = - V_137 ;
struct V_10 * V_12 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ )
F_121 ( & V_16 [ V_28 ] ) ;
F_90 () ;
if ( ! V_54 ) {
error = - V_155 ;
F_63 ( L_44 ) ;
goto V_225;
}
error = - V_72 ;
V_14 = F_122 ( L_45 , sizeof( struct V_10 ) ,
F_123 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_14 )
goto V_225;
error = F_112 () ;
if ( error )
goto V_226;
V_151 = 1 ;
if ( V_99 . V_227 == 0 )
error = F_94 () ;
else
error = F_93 () ;
if ( error )
goto V_228;
return 0 ;
V_228:
V_151 = 0 ;
V_12 = F_19 ( 0 , 0 ) ;
if ( V_12 ) {
F_61 ( V_12 , false , true , true ) ;
F_116 ( V_14 , V_12 ) ;
}
V_226:
F_119 ( V_14 ) ;
V_225:
return error ;
}
void F_124 ( void )
{
struct V_32 * V_33 , * V_219 ;
F_27 ( & V_55 ) ;
F_106 (na, safe, &dlm_node_addrs, list) {
F_82 ( & V_33 -> V_15 ) ;
while ( V_33 -> V_56 -- )
F_32 ( V_33 -> V_57 [ V_33 -> V_56 ] ) ;
F_32 ( V_33 ) ;
}
F_28 ( & V_55 ) ;
}
