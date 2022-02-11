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
struct V_10 * V_12 = F_35 ( V_77 ) ;
struct V_34 V_93 ;
if ( F_26 ( V_12 -> V_8 , & V_93 , NULL , false ) ) {
F_47 ( V_94 L_1
L_2
L_3 , F_45 () ,
V_12 -> V_8 , V_95 . V_96 ,
V_77 -> V_97 , V_77 -> V_98 ) ;
return;
} else if ( V_93 . V_37 == V_38 ) {
struct V_39 * V_99 = (struct V_39 * ) & V_93 ;
F_47 ( V_94 L_1
L_4
L_3 , F_45 () ,
V_12 -> V_8 , & V_99 -> V_42 . V_43 ,
V_95 . V_96 , V_77 -> V_97 ,
V_77 -> V_98 ) ;
} else {
struct V_46 * V_100 = (struct V_46 * ) & V_93 ;
F_47 ( V_94 L_1
L_5
L_6 , F_45 () ,
V_12 -> V_8 , V_100 -> V_47 . V_101 [ 0 ] ,
V_100 -> V_47 . V_101 [ 1 ] ,
V_100 -> V_47 . V_101 [ 2 ] ,
V_100 -> V_47 . V_101 [ 3 ] ,
V_95 . V_96 , V_77 -> V_97 ,
V_77 -> V_98 ) ;
}
V_12 -> V_102 ( V_77 ) ;
}
static void F_48 ( struct V_103 * V_76 , struct V_10 * V_12 )
{
V_12 -> V_76 = V_76 ;
V_12 -> V_76 -> V_77 -> V_104 = F_34 ;
V_12 -> V_76 -> V_77 -> V_105 = F_38 ;
V_12 -> V_76 -> V_77 -> V_106 = F_43 ;
V_12 -> V_76 -> V_77 -> V_107 = V_12 ;
V_12 -> V_76 -> V_77 -> V_108 = V_71 ;
V_12 -> V_102 = V_12 -> V_76 -> V_77 -> V_109 ;
V_12 -> V_76 -> V_77 -> V_109 = F_46 ;
}
static void F_49 ( struct V_34 * V_93 , T_2 V_110 ,
int * V_111 )
{
V_93 -> V_37 = V_61 [ 0 ] -> V_37 ;
if ( V_93 -> V_37 == V_38 ) {
struct V_39 * V_112 = (struct V_39 * ) V_93 ;
V_112 -> V_44 = F_50 ( V_110 ) ;
* V_111 = sizeof( struct V_39 ) ;
memset ( & V_112 -> V_113 , 0 , sizeof( V_112 -> V_113 ) ) ;
} else {
struct V_46 * V_114 = (struct V_46 * ) V_93 ;
V_114 -> V_48 = F_50 ( V_110 ) ;
* V_111 = sizeof( struct V_46 ) ;
}
memset ( ( char * ) V_93 + * V_111 , 0 , sizeof( struct V_34 ) - * V_111 ) ;
}
static void F_51 ( struct V_10 * V_12 , bool V_115 ,
bool V_116 , bool V_117 )
{
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_39 ( V_85 , & V_12 -> V_79 ) ;
if ( V_116 && F_52 ( & V_12 -> V_20 ) )
F_53 ( L_7 , V_12 -> V_8 ) ;
if ( V_117 && F_52 ( & V_12 -> V_22 ) )
F_53 ( L_8 , V_12 -> V_8 ) ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 ) {
F_54 ( V_12 -> V_76 ) ;
V_12 -> V_76 = NULL ;
}
if ( V_12 -> V_118 && V_115 ) {
F_51 ( V_12 -> V_118 , false , true , true ) ;
}
if ( V_12 -> V_119 ) {
F_55 ( V_12 -> V_119 ) ;
V_12 -> V_119 = NULL ;
}
V_12 -> V_120 = 0 ;
F_21 ( & V_12 -> V_17 ) ;
}
static int F_56 ( struct V_10 * V_12 )
{
int V_121 = 0 ;
struct V_122 V_123 = {} ;
struct V_124 V_125 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_126 = 0 ;
int V_127 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 == NULL ) {
V_121 = - V_128 ;
goto V_129;
}
if ( V_12 -> V_8 == 0 ) {
V_121 = - V_130 ;
goto V_129;
}
if ( V_12 -> V_119 == NULL ) {
V_12 -> V_119 = F_57 ( V_131 ) ;
if ( V_12 -> V_119 == NULL )
goto V_132;
F_3 ( & V_12 -> V_2 , V_133 ) ;
}
V_125 [ 0 ] . V_134 = V_12 -> V_2 . V_5 - F_2 ( & V_12 -> V_2 ) ;
V_125 [ 0 ] . V_135 = F_58 ( V_12 -> V_119 ) + F_2 ( & V_12 -> V_2 ) ;
V_125 [ 1 ] . V_134 = 0 ;
V_127 = 1 ;
if ( F_2 ( & V_12 -> V_2 ) >= V_12 -> V_2 . V_5 ) {
V_125 [ 0 ] . V_134 = V_133 - F_2 ( & V_12 -> V_2 ) ;
V_125 [ 1 ] . V_134 = V_12 -> V_2 . V_5 ;
V_125 [ 1 ] . V_135 = F_58 ( V_12 -> V_119 ) ;
V_127 = 2 ;
}
V_4 = V_125 [ 0 ] . V_134 + V_125 [ 1 ] . V_134 ;
V_11 = V_121 = F_59 ( V_12 -> V_76 , & V_123 , V_125 , V_127 , V_4 ,
V_136 | V_137 ) ;
if ( V_121 <= 0 )
goto V_129;
else if ( V_121 == V_4 )
V_126 = 1 ;
F_1 ( & V_12 -> V_2 , V_121 ) ;
V_121 = F_60 ( V_12 -> V_8 ,
F_58 ( V_12 -> V_119 ) ,
V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_133 ) ;
if ( V_121 == - V_138 ) {
F_53 ( L_9 ,
F_58 ( V_12 -> V_119 ) , V_12 -> V_2 . V_5 ,
V_12 -> V_2 . V_4 , V_11 ) ;
}
if ( V_121 < 0 )
goto V_129;
F_4 ( & V_12 -> V_2 , V_121 ) ;
if ( F_5 ( & V_12 -> V_2 ) && ! V_126 ) {
F_55 ( V_12 -> V_119 ) ;
V_12 -> V_119 = NULL ;
}
if ( V_126 )
goto V_132;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_132:
if ( ! F_36 ( V_78 , & V_12 -> V_79 ) )
F_37 ( V_80 , & V_12 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - V_128 ;
V_129:
F_21 ( & V_12 -> V_17 ) ;
if ( V_121 != - V_128 ) {
F_51 ( V_12 , false , true , false ) ;
}
if ( V_121 == 0 )
V_121 = - V_128 ;
return V_121 ;
}
static int F_61 ( struct V_10 * V_12 )
{
int V_139 ;
struct V_34 V_140 ;
struct V_103 * V_141 ;
int V_4 ;
int V_8 ;
struct V_10 * V_142 ;
struct V_10 * V_143 ;
F_20 ( & V_31 ) ;
if ( ! V_144 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_139 = F_62 ( & V_145 , V_61 [ 0 ] -> V_37 ,
V_146 , V_147 , & V_141 ) ;
if ( V_139 < 0 )
return - V_72 ;
F_63 ( & V_12 -> V_17 , 0 ) ;
V_139 = - V_148 ;
if ( V_12 -> V_76 == NULL )
goto V_149;
V_141 -> type = V_12 -> V_76 -> type ;
V_141 -> V_150 = V_12 -> V_76 -> V_150 ;
V_139 = V_12 -> V_76 -> V_150 -> V_151 ( V_12 -> V_76 , V_141 , V_152 ) ;
if ( V_139 < 0 )
goto V_149;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( V_141 -> V_150 -> V_153 ( V_141 , (struct V_50 * ) & V_140 ,
& V_4 , 2 ) ) {
V_139 = - V_154 ;
goto V_149;
}
F_49 ( & V_140 , 0 , & V_4 ) ;
if ( F_29 ( & V_140 , & V_8 ) ) {
unsigned char * V_155 = ( unsigned char * ) & V_140 ;
F_53 ( L_10 ) ;
F_64 ( L_11 , V_156 ,
V_155 , sizeof( struct V_34 ) ) ;
F_54 ( V_141 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - 1 ;
}
F_53 ( L_12 , V_8 ) ;
V_142 = F_19 ( V_8 , V_71 ) ;
if ( ! V_142 ) {
V_139 = - V_72 ;
goto V_149;
}
F_63 ( & V_142 -> V_17 , 1 ) ;
if ( V_142 -> V_76 ) {
struct V_10 * V_118 = V_142 -> V_118 ;
if ( ! V_118 ) {
V_118 = F_10 ( V_14 , V_71 ) ;
if ( ! V_118 ) {
F_53 ( L_13 ) ;
F_21 ( & V_142 -> V_17 ) ;
V_139 = - V_72 ;
goto V_149;
}
V_118 -> V_8 = V_8 ;
V_118 -> V_26 = F_56 ;
F_12 ( & V_118 -> V_17 ) ;
F_15 ( & V_118 -> V_20 , V_21 ) ;
F_15 ( & V_118 -> V_22 , V_23 ) ;
F_65 ( V_157 , & V_118 -> V_79 ) ;
}
if ( ! V_118 -> V_76 ) {
V_142 -> V_118 = V_118 ;
V_118 -> V_76 = V_141 ;
V_141 -> V_77 -> V_107 = V_118 ;
F_48 ( V_141 , V_118 ) ;
V_143 = V_118 ;
}
else {
F_66 ( L_14 , V_8 ) ;
V_139 = - V_128 ;
F_21 ( & V_142 -> V_17 ) ;
goto V_149;
}
}
else {
V_141 -> V_77 -> V_107 = V_142 ;
V_142 -> V_26 = F_56 ;
F_48 ( V_141 , V_142 ) ;
V_143 = V_142 ;
}
F_21 ( & V_142 -> V_17 ) ;
if ( ! F_36 ( V_78 , & V_143 -> V_79 ) )
F_37 ( V_80 , & V_143 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_149:
F_21 ( & V_12 -> V_17 ) ;
F_54 ( V_141 ) ;
if ( V_139 != - V_128 )
F_53 ( L_15 , V_139 ) ;
return V_139 ;
}
static int F_67 ( struct V_10 * V_12 )
{
struct V_158 V_159 ;
int V_8 ;
int V_160 , V_121 ;
int V_111 ;
struct V_10 * V_142 ;
struct V_10 * V_143 ;
struct V_103 * V_141 ;
F_20 ( & V_31 ) ;
if ( ! V_144 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
F_63 ( & V_12 -> V_17 , 0 ) ;
V_121 = F_68 ( V_12 -> V_76 , & V_141 , V_152 ) ;
if ( V_121 < 0 )
goto V_149;
memset ( & V_159 , 0 , sizeof( struct V_158 ) ) ;
V_160 = sizeof( struct V_158 ) ;
V_121 = F_69 ( V_141 , V_161 , V_162 ,
( char * ) & V_159 , & V_160 ) ;
if ( V_121 < 0 ) {
F_53 ( L_16 , V_121 ) ;
goto V_149;
}
F_49 ( & V_159 . V_163 , 0 , & V_111 ) ;
if ( F_29 ( & V_159 . V_163 , & V_8 ) ) {
unsigned char * V_155 = ( unsigned char * ) & V_159 . V_163 ;
F_53 ( L_17 ) ;
F_64 ( L_11 , V_156 ,
V_155 , sizeof( struct V_34 ) ) ;
goto V_149;
}
V_142 = F_19 ( V_8 , V_71 ) ;
if ( ! V_142 ) {
V_121 = - V_72 ;
goto V_149;
}
F_63 ( & V_142 -> V_17 , 1 ) ;
if ( V_142 -> V_76 ) {
struct V_10 * V_118 = V_142 -> V_118 ;
if ( ! V_118 ) {
V_118 = F_10 ( V_14 , V_71 ) ;
if ( ! V_118 ) {
F_53 ( L_13 ) ;
F_21 ( & V_142 -> V_17 ) ;
V_121 = - V_72 ;
goto V_149;
}
V_118 -> V_8 = V_8 ;
V_118 -> V_26 = F_56 ;
F_12 ( & V_118 -> V_17 ) ;
F_15 ( & V_118 -> V_20 , V_21 ) ;
F_15 ( & V_118 -> V_22 , V_23 ) ;
F_65 ( V_157 , & V_118 -> V_79 ) ;
}
if ( ! V_118 -> V_76 ) {
V_142 -> V_118 = V_118 ;
V_118 -> V_76 = V_141 ;
V_141 -> V_77 -> V_107 = V_118 ;
F_48 ( V_141 , V_118 ) ;
V_143 = V_118 ;
} else {
F_66 ( L_14 , V_8 ) ;
V_121 = - V_128 ;
F_21 ( & V_142 -> V_17 ) ;
goto V_149;
}
} else {
V_141 -> V_77 -> V_107 = V_142 ;
V_142 -> V_26 = F_56 ;
F_48 ( V_141 , V_142 ) ;
V_143 = V_142 ;
}
F_53 ( L_18 , V_8 ) ;
F_21 ( & V_142 -> V_17 ) ;
if ( ! F_36 ( V_78 , & V_143 -> V_79 ) )
F_37 ( V_80 , & V_143 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_149:
F_21 ( & V_12 -> V_17 ) ;
if ( V_141 )
F_54 ( V_141 ) ;
if ( V_121 != - V_128 )
F_53 ( L_15 , V_121 ) ;
return V_121 ;
}
static void F_70 ( struct V_164 * V_165 )
{
F_55 ( V_165 -> V_166 ) ;
F_32 ( V_165 ) ;
}
static void F_71 ( struct V_164 * V_165 , int V_167 )
{
V_165 -> V_168 += V_167 ;
V_165 -> V_4 -= V_167 ;
if ( V_165 -> V_4 == 0 && V_165 -> V_169 == 0 ) {
F_72 ( & V_165 -> V_15 ) ;
F_70 ( V_165 ) ;
}
}
static int F_73 ( struct V_10 * V_12 , T_2 V_110 )
{
struct V_34 V_170 ;
int V_28 , V_111 , V_139 = 0 ;
for ( V_28 = 0 ; V_28 < V_54 ; V_28 ++ ) {
memcpy ( & V_170 , V_61 [ V_28 ] , sizeof( V_170 ) ) ;
F_49 ( & V_170 , V_110 , & V_111 ) ;
if ( ! V_28 )
V_139 = F_74 ( V_12 -> V_76 ,
(struct V_50 * ) & V_170 ,
V_111 ) ;
else
V_139 = F_75 ( V_12 -> V_76 , V_171 ,
V_172 ,
( char * ) & V_170 , V_111 ) ;
if ( V_139 < 0 ) {
F_53 ( L_19 ,
V_110 , V_28 + 1 , V_139 ) ;
break;
}
}
return V_139 ;
}
static void F_76 ( struct V_10 * V_12 )
{
struct V_34 V_173 ;
int V_174 = 1 ;
int V_139 ;
int V_111 ;
struct V_103 * V_76 ;
if ( V_12 -> V_8 == 0 ) {
F_53 ( L_20 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_120 ++ > V_175 )
goto V_176;
if ( V_12 -> V_76 ) {
F_53 ( L_21 , V_12 -> V_8 ) ;
goto V_176;
}
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_139 = F_26 ( V_12 -> V_8 , & V_173 , NULL , true ) ;
if ( V_139 < 0 ) {
F_53 ( L_22 , V_12 -> V_8 ) ;
goto V_176;
}
V_139 = F_62 ( & V_145 , V_61 [ 0 ] -> V_37 ,
V_146 , V_161 , & V_76 ) ;
if ( V_139 < 0 )
goto V_177;
V_76 -> V_77 -> V_107 = V_12 ;
V_12 -> V_26 = F_56 ;
V_12 -> V_25 = F_76 ;
F_48 ( V_76 , V_12 ) ;
if ( F_73 ( V_12 , 0 ) )
goto V_178;
F_49 ( & V_173 , V_95 . V_96 , & V_111 ) ;
F_53 ( L_23 , V_12 -> V_8 ) ;
F_75 ( V_76 , V_179 , V_180 , ( char * ) & V_174 ,
sizeof( V_174 ) ) ;
V_139 = V_76 -> V_150 -> V_181 ( V_76 , (struct V_50 * ) & V_173 , V_111 ,
V_152 ) ;
if ( V_139 == - V_182 )
V_139 = 0 ;
if ( V_139 == 0 )
goto V_176;
V_178:
V_12 -> V_76 = NULL ;
F_54 ( V_76 ) ;
V_177:
if ( V_139 != - V_183 &&
V_139 != - V_184 &&
V_139 != - V_185 &&
V_139 != - V_130 &&
V_139 != - V_186 ) {
F_53 ( L_24 , V_12 -> V_8 ,
V_12 -> V_120 , V_139 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_77 ( 1000 ) ;
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_41 ( V_12 ) ;
return;
}
V_176:
F_21 ( & V_12 -> V_17 ) ;
F_65 ( V_85 , & V_12 -> V_79 ) ;
}
static void F_78 ( struct V_10 * V_12 )
{
struct V_34 V_93 , V_187 ;
int V_111 ;
struct V_103 * V_76 = NULL ;
int V_174 = 1 ;
int V_139 ;
if ( V_12 -> V_8 == 0 ) {
F_53 ( L_20 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_120 ++ > V_175 )
goto V_176;
if ( V_12 -> V_76 )
goto V_176;
V_139 = F_62 ( & V_145 , V_61 [ 0 ] -> V_37 ,
V_146 , V_147 , & V_76 ) ;
if ( V_139 < 0 )
goto V_188;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_139 = F_26 ( V_12 -> V_8 , & V_93 , NULL , false ) ;
if ( V_139 < 0 ) {
F_53 ( L_22 , V_12 -> V_8 ) ;
goto V_188;
}
V_76 -> V_77 -> V_107 = V_12 ;
V_12 -> V_26 = F_56 ;
V_12 -> V_25 = F_78 ;
F_48 ( V_76 , V_12 ) ;
memcpy ( & V_187 , V_61 [ 0 ] , sizeof( V_187 ) ) ;
F_49 ( & V_187 , 0 , & V_111 ) ;
V_139 = V_76 -> V_150 -> V_189 ( V_76 , (struct V_50 * ) & V_187 ,
V_111 ) ;
if ( V_139 < 0 ) {
F_53 ( L_25 , V_139 ) ;
}
F_49 ( & V_93 , V_95 . V_96 , & V_111 ) ;
F_53 ( L_23 , V_12 -> V_8 ) ;
F_75 ( V_76 , V_179 , V_180 , ( char * ) & V_174 ,
sizeof( V_174 ) ) ;
V_139 = V_76 -> V_150 -> V_181 ( V_76 , (struct V_50 * ) & V_93 , V_111 ,
V_152 ) ;
if ( V_139 == - V_182 )
V_139 = 0 ;
if ( V_139 == 0 )
goto V_176;
V_188:
if ( V_12 -> V_76 ) {
F_54 ( V_12 -> V_76 ) ;
V_12 -> V_76 = NULL ;
} else if ( V_76 ) {
F_54 ( V_76 ) ;
}
if ( V_139 != - V_183 &&
V_139 != - V_184 &&
V_139 != - V_185 &&
V_139 != - V_130 &&
V_139 != - V_186 ) {
F_53 ( L_24 , V_12 -> V_8 ,
V_12 -> V_120 , V_139 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_77 ( 1000 ) ;
F_39 ( V_88 , & V_12 -> V_79 ) ;
F_41 ( V_12 ) ;
return;
}
V_176:
F_21 ( & V_12 -> V_17 ) ;
F_65 ( V_85 , & V_12 -> V_79 ) ;
return;
}
static struct V_103 * F_79 ( struct V_10 * V_12 ,
struct V_34 * V_93 )
{
struct V_103 * V_76 = NULL ;
int V_139 = 0 ;
int V_174 = 1 ;
int V_111 ;
if ( V_61 [ 0 ] -> V_37 == V_38 )
V_111 = sizeof( struct V_39 ) ;
else
V_111 = sizeof( struct V_46 ) ;
V_139 = F_62 ( & V_145 , V_61 [ 0 ] -> V_37 ,
V_146 , V_147 , & V_76 ) ;
if ( V_139 < 0 ) {
F_53 ( L_26 ) ;
goto V_190;
}
F_75 ( V_76 , V_179 , V_180 , ( char * ) & V_174 ,
sizeof( V_174 ) ) ;
V_139 = F_75 ( V_76 , V_191 , V_192 ,
( char * ) & V_174 , sizeof( V_174 ) ) ;
if ( V_139 < 0 ) {
F_53 ( L_27 , V_139 ) ;
}
V_12 -> V_26 = F_61 ;
V_12 -> V_25 = F_78 ;
F_49 ( V_93 , V_95 . V_96 , & V_111 ) ;
V_139 = V_76 -> V_150 -> V_189 ( V_76 , (struct V_50 * ) V_93 , V_111 ) ;
if ( V_139 < 0 ) {
F_53 ( L_28 , V_95 . V_96 ) ;
F_54 ( V_76 ) ;
V_76 = NULL ;
V_12 -> V_76 = NULL ;
goto V_190;
}
V_139 = F_75 ( V_76 , V_191 , V_193 ,
( char * ) & V_174 , sizeof( V_174 ) ) ;
if ( V_139 < 0 ) {
F_53 ( L_29 , V_139 ) ;
}
V_139 = V_76 -> V_150 -> V_194 ( V_76 , 5 ) ;
if ( V_139 < 0 ) {
F_53 ( L_30 , V_95 . V_96 ) ;
F_54 ( V_76 ) ;
V_76 = NULL ;
goto V_190;
}
V_190:
return V_76 ;
}
static void F_80 ( void )
{
struct V_34 V_53 , * V_57 ;
int V_28 ;
V_54 = 0 ;
for ( V_28 = 0 ; V_28 < V_74 ; V_28 ++ ) {
if ( F_81 ( & V_53 , V_28 ) )
break;
V_57 = F_82 ( sizeof( * V_57 ) , V_71 ) ;
if ( ! V_57 )
break;
memcpy ( V_57 , & V_53 , sizeof( * V_57 ) ) ;
V_61 [ V_54 ++ ] = V_57 ;
}
}
static int F_83 ( void )
{
struct V_103 * V_76 = NULL ;
int V_139 = - V_130 ;
struct V_10 * V_12 = F_19 ( 0 , V_71 ) ;
int V_195 = V_196 ;
int V_174 = 1 ;
if ( ! V_12 )
return - V_72 ;
F_53 ( L_31 ) ;
V_139 = F_62 ( & V_145 , V_61 [ 0 ] -> V_37 ,
V_146 , V_161 , & V_76 ) ;
if ( V_139 < 0 ) {
F_53 ( L_32 ) ;
goto V_176;
}
V_139 = F_75 ( V_76 , V_191 , V_197 ,
( char * ) & V_195 , sizeof( V_195 ) ) ;
if ( V_139 )
F_53 ( L_33 , V_139 ) ;
V_139 = F_75 ( V_76 , V_171 , V_198 , ( char * ) & V_174 ,
sizeof( V_174 ) ) ;
if ( V_139 < 0 )
F_53 ( L_34 , V_139 ) ;
V_76 -> V_77 -> V_107 = V_12 ;
V_12 -> V_76 = V_76 ;
V_12 -> V_76 -> V_77 -> V_104 = F_34 ;
V_12 -> V_26 = F_67 ;
V_12 -> V_25 = F_76 ;
if ( F_73 ( V_12 , V_95 . V_96 ) )
goto V_199;
V_139 = V_76 -> V_150 -> V_194 ( V_76 , 5 ) ;
if ( V_139 < 0 ) {
F_53 ( L_35 ) ;
goto V_199;
}
return 0 ;
V_199:
F_54 ( V_76 ) ;
V_12 -> V_76 = NULL ;
V_176:
return V_139 ;
}
static int F_84 ( void )
{
struct V_103 * V_76 = NULL ;
struct V_10 * V_12 = F_19 ( 0 , V_71 ) ;
int V_139 = - V_130 ;
if ( ! V_12 )
return - V_72 ;
if ( V_61 [ 1 ] != NULL ) {
F_53 ( L_36
L_37 ) ;
return - V_130 ;
}
F_53 ( L_38 ) ;
V_76 = F_79 ( V_12 , V_61 [ 0 ] ) ;
if ( V_76 ) {
F_48 ( V_76 , V_12 ) ;
V_139 = 0 ;
}
else {
V_139 = - V_200 ;
}
return V_139 ;
}
static struct V_164 * F_85 ( struct V_10 * V_12 ,
T_1 V_30 )
{
struct V_164 * V_201 ;
V_201 = F_82 ( sizeof( struct V_164 ) , V_30 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_166 = F_57 ( V_30 ) ;
if ( ! V_201 -> V_166 ) {
F_32 ( V_201 ) ;
return NULL ;
}
V_201 -> V_168 = 0 ;
V_201 -> V_4 = 0 ;
V_201 -> V_202 = 0 ;
V_201 -> V_169 = 0 ;
V_201 -> V_12 = V_12 ;
return V_201 ;
}
void * F_86 ( int V_8 , int V_4 , T_1 V_30 , char * * V_203 )
{
struct V_10 * V_12 ;
struct V_164 * V_165 ;
int V_168 = 0 ;
V_12 = F_19 ( V_8 , V_30 ) ;
if ( ! V_12 )
return NULL ;
F_27 ( & V_12 -> V_19 ) ;
V_165 = F_87 ( V_12 -> V_18 . V_204 , struct V_164 , V_15 ) ;
if ( ( & V_165 -> V_15 == & V_12 -> V_18 ) ||
( V_133 - V_165 -> V_202 < V_4 ) ) {
V_165 = NULL ;
} else {
V_168 = V_165 -> V_202 ;
V_165 -> V_202 += V_4 ;
V_165 -> V_169 ++ ;
}
F_28 ( & V_12 -> V_19 ) ;
if ( V_165 ) {
V_205:
* V_203 = F_58 ( V_165 -> V_166 ) + V_168 ;
return V_165 ;
}
V_165 = F_85 ( V_12 , V_30 ) ;
if ( V_165 ) {
F_27 ( & V_12 -> V_19 ) ;
V_168 = V_165 -> V_202 ;
V_165 -> V_202 += V_4 ;
V_165 -> V_169 ++ ;
F_88 ( & V_165 -> V_15 , & V_12 -> V_18 ) ;
F_28 ( & V_12 -> V_19 ) ;
goto V_205;
}
return NULL ;
}
void F_89 ( void * V_206 )
{
struct V_164 * V_165 = (struct V_164 * ) V_206 ;
struct V_10 * V_12 = V_165 -> V_12 ;
int V_169 ;
F_27 ( & V_12 -> V_19 ) ;
V_169 = -- V_165 -> V_169 ;
if ( V_169 )
goto V_176;
V_165 -> V_4 = V_165 -> V_202 - V_165 -> V_168 ;
F_28 ( & V_12 -> V_19 ) ;
if ( ! F_36 ( V_85 , & V_12 -> V_79 ) ) {
F_37 ( V_86 , & V_12 -> V_20 ) ;
}
return;
V_176:
F_28 ( & V_12 -> V_19 ) ;
return;
}
static void F_90 ( struct V_10 * V_12 )
{
int V_121 = 0 ;
const int V_207 = V_136 | V_137 ;
struct V_164 * V_165 ;
int V_4 , V_168 ;
int V_208 = 0 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_76 == NULL )
goto V_209;
F_27 ( & V_12 -> V_19 ) ;
for (; ; ) {
V_165 = F_87 ( V_12 -> V_18 . V_210 , struct V_164 ,
V_15 ) ;
if ( (struct V_211 * ) V_165 == & V_12 -> V_18 )
break;
V_4 = V_165 -> V_4 ;
V_168 = V_165 -> V_168 ;
F_91 ( V_4 == 0 && V_165 -> V_169 == 0 ) ;
F_28 ( & V_12 -> V_19 ) ;
V_121 = 0 ;
if ( V_4 ) {
V_121 = F_92 ( V_12 -> V_76 , V_165 -> V_166 , V_168 , V_4 ,
V_207 ) ;
if ( V_121 == - V_128 || V_121 == 0 ) {
if ( V_121 == - V_128 &&
F_42 ( V_84 , & V_12 -> V_76 -> V_79 ) &&
! F_36 ( V_82 , & V_12 -> V_79 ) ) {
F_65 ( V_81 , & V_12 -> V_76 -> V_79 ) ;
V_12 -> V_76 -> V_77 -> V_83 ++ ;
}
F_93 () ;
goto V_176;
} else if ( V_121 < 0 )
goto V_212;
}
if ( ++ V_208 >= V_213 ) {
F_93 () ;
V_208 = 0 ;
}
F_27 ( & V_12 -> V_19 ) ;
F_71 ( V_165 , V_121 ) ;
}
F_28 ( & V_12 -> V_19 ) ;
V_176:
F_21 ( & V_12 -> V_17 ) ;
return;
V_212:
F_21 ( & V_12 -> V_17 ) ;
F_51 ( V_12 , false , false , true ) ;
F_41 ( V_12 ) ;
return;
V_209:
F_21 ( & V_12 -> V_17 ) ;
F_41 ( V_12 ) ;
}
static void F_94 ( struct V_10 * V_12 )
{
struct V_164 * V_165 , * V_214 ;
F_27 ( & V_12 -> V_19 ) ;
F_95 (e, safe, &con->writequeue, list) {
F_72 ( & V_165 -> V_15 ) ;
F_70 ( V_165 ) ;
}
F_28 ( & V_12 -> V_19 ) ;
}
int F_96 ( int V_8 )
{
struct V_10 * V_12 ;
struct V_32 * V_33 ;
F_53 ( L_39 , V_8 ) ;
V_12 = F_19 ( V_8 , 0 ) ;
if ( V_12 ) {
F_65 ( V_87 , & V_12 -> V_79 ) ;
F_51 ( V_12 , true , true , true ) ;
F_94 ( V_12 ) ;
}
F_27 ( & V_55 ) ;
V_33 = F_22 ( V_8 ) ;
if ( V_33 ) {
F_72 ( & V_33 -> V_15 ) ;
while ( V_33 -> V_56 -- )
F_32 ( V_33 -> V_57 [ V_33 -> V_56 ] ) ;
F_32 ( V_33 ) ;
}
F_28 ( & V_55 ) ;
return 0 ;
}
static void V_23 ( struct V_215 * V_216 )
{
struct V_10 * V_12 = F_97 ( V_216 , struct V_10 , V_22 ) ;
int V_217 ;
F_39 ( V_78 , & V_12 -> V_79 ) ;
do {
V_217 = V_12 -> V_26 ( V_12 ) ;
} while ( ! V_217 );
}
static void V_21 ( struct V_215 * V_216 )
{
struct V_10 * V_12 = F_97 ( V_216 , struct V_10 , V_20 ) ;
if ( F_40 ( V_88 , & V_12 -> V_79 ) )
V_12 -> V_25 ( V_12 ) ;
if ( F_40 ( V_85 , & V_12 -> V_79 ) )
F_90 ( V_12 ) ;
}
static void F_98 ( void )
{
F_16 ( F_94 ) ;
}
static void F_99 ( void )
{
F_100 ( V_80 ) ;
F_100 ( V_86 ) ;
}
static int F_101 ( void )
{
V_80 = F_102 ( L_40 ,
V_218 | V_219 , 1 ) ;
if ( ! V_80 ) {
F_53 ( L_41 ) ;
return - V_72 ;
}
V_86 = F_102 ( L_42 ,
V_218 | V_219 , 1 ) ;
if ( ! V_86 ) {
F_53 ( L_43 ) ;
F_100 ( V_80 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_103 ( struct V_10 * V_12 )
{
V_12 -> V_79 |= 0x0F ;
if ( V_12 -> V_76 && V_12 -> V_76 -> V_77 )
V_12 -> V_76 -> V_77 -> V_107 = NULL ;
}
static void F_104 ( struct V_10 * V_12 )
{
F_51 ( V_12 , true , true , true ) ;
if ( V_12 -> V_118 )
F_105 ( V_14 , V_12 -> V_118 ) ;
F_106 ( & V_12 -> V_15 ) ;
F_105 ( V_14 , V_12 ) ;
}
void F_107 ( void )
{
F_20 ( & V_31 ) ;
V_144 = 0 ;
F_16 ( F_103 ) ;
F_21 ( & V_31 ) ;
F_99 () ;
F_20 ( & V_31 ) ;
F_98 () ;
F_16 ( F_104 ) ;
F_21 ( & V_31 ) ;
F_108 ( V_14 ) ;
}
int F_109 ( void )
{
int error = - V_130 ;
struct V_10 * V_12 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ )
F_110 ( & V_16 [ V_28 ] ) ;
F_80 () ;
if ( ! V_54 ) {
error = - V_148 ;
F_53 ( L_44 ) ;
goto V_220;
}
error = - V_72 ;
V_14 = F_111 ( L_45 , sizeof( struct V_10 ) ,
F_112 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_14 )
goto V_220;
error = F_101 () ;
if ( error )
goto V_221;
V_144 = 1 ;
if ( V_95 . V_222 == 0 )
error = F_84 () ;
else
error = F_83 () ;
if ( error )
goto V_223;
return 0 ;
V_223:
V_144 = 0 ;
V_12 = F_19 ( 0 , 0 ) ;
if ( V_12 ) {
F_51 ( V_12 , false , true , true ) ;
F_105 ( V_14 , V_12 ) ;
}
V_221:
F_108 ( V_14 ) ;
V_220:
return error ;
}
void F_113 ( void )
{
struct V_32 * V_33 , * V_214 ;
F_27 ( & V_55 ) ;
F_95 (na, safe, &dlm_node_addrs, list) {
F_72 ( & V_33 -> V_15 ) ;
while ( V_33 -> V_56 -- )
F_32 ( V_33 -> V_57 [ V_33 -> V_56 ] ) ;
F_32 ( V_33 ) ;
}
F_28 ( & V_55 ) ;
}
