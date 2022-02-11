static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 * sizeof( struct V_4 ) ;
}
static inline T_1 F_2 ( const struct V_1 * V_2 )
{
return sizeof( struct V_5 ) + V_2 -> V_3 *
sizeof( V_6 ) ;
}
static inline T_1 F_3 ( void )
{
return sizeof( struct V_7 ) ;
}
static void F_4 ( T_1 V_8 ,
void * V_9 )
{
struct V_7 * V_10 = (struct V_7 * )
V_9 ;
V_10 -> V_11 . V_8 = V_12 ;
V_10 -> V_11 . V_13 = sizeof( V_10 -> V_14 ) ;
V_10 -> V_14 . V_15 = V_8 ;
}
static void F_5 ( const struct V_1 * V_2 ,
void * V_9 )
{
struct V_5 * V_10 = (struct V_5 * )
V_9 ;
struct V_16 * V_17 ;
V_6 * V_18 ;
T_1 V_19 ;
int V_20 ;
V_19 = sizeof( V_10 -> V_14 ) + V_2 -> V_3 * sizeof( V_6 ) ;
V_10 -> V_11 . V_8 = V_21 ;
V_10 -> V_11 . V_13 = V_19 ;
V_10 -> V_14 . V_15 = V_2 -> V_22 . V_8 ;
V_10 -> V_14 . V_23 = V_2 -> V_24 ;
V_10 -> V_14 . V_25 = F_6 ( V_2 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_10 -> V_14 . V_27 [ V_20 ] . V_28 = V_2 -> V_29 [ V_20 ] ;
V_10 += 1 ;
V_18 = ( V_6 * ) V_10 ;
V_17 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_3 ; ++ V_20 , V_18 ++ , V_17 ++ ) {
V_18 -> V_31 = V_17 -> V_31 ;
V_18 -> V_32 = V_17 -> V_32 ;
V_18 -> V_33 = V_17 -> V_33 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
void * V_9 ,
const T_2 * V_34 ,
bool V_35 )
{
T_1 V_20 ;
struct V_4 * V_10 = (struct V_4 * ) V_9 ;
const struct V_36 * V_37 =
F_8 ( V_2 -> V_25 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_3 ; ++ V_20 ) {
T_3 * V_11 = & V_10 -> V_11 ;
T_4 * V_14 = & V_10 -> V_14 ;
T_5 * V_38 = & V_10 -> V_38 ;
T_6 * V_39 = & V_10 -> V_39 ;
const struct V_40 * V_41 = & V_2 -> V_42 [ V_20 ] ;
const struct V_16 * V_43 = & V_2 -> V_30 [ V_20 ] ;
V_11 -> V_8 = V_44 ;
V_11 -> V_13 = sizeof( * V_14 ) + sizeof( * V_38 ) + sizeof( * V_39 ) ;
V_14 -> V_45 . V_34 = * V_34 ;
V_14 -> V_45 . V_34 . V_46 += V_41 -> V_47 ;
V_14 -> V_45 . V_48 = F_9 ( V_37 ,
V_43 ) ;
V_14 -> V_49 . V_15 = V_2 -> V_22 . V_8 ;
V_14 -> V_49 . V_27 = V_41 -> V_27 ;
V_14 -> V_49 . V_50 = V_41 -> V_51 ;
V_14 -> V_52 = ( ( V_35 ) ? V_53 :
V_54 ) ;
V_38 -> V_55 = 0 ;
V_38 -> V_56 = 0 ;
V_38 -> V_57 = 0 ;
V_38 -> V_58 = 0 ;
V_38 -> V_59 = 0 ;
V_38 -> V_60 = 0 ;
V_38 -> V_61 = V_43 -> V_31 ;
V_38 -> V_62 = V_43 -> V_32 ;
V_38 -> V_63 = V_43 -> V_33 ;
V_39 -> V_64 = sizeof( * V_39 ) ;
V_39 -> V_65 =
F_10 ( V_37 , V_43 ,
V_14 -> V_45 . V_48 ) ;
V_39 -> V_24 . V_66 = 0 ;
V_39 -> V_24 . V_67 = 0 ;
V_39 -> V_24 . V_68 = 0 ;
++ V_10 ;
}
}
static void F_11 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 ;
void * V_10 ;
if ( V_22 -> V_72 -> V_73 == V_74 ) {
( void ) V_74 ( V_22 ) ;
return;
}
if ( V_22 -> V_8 != - 1 ) {
V_10 = F_12 ( V_71 , F_3 () ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_2 ) ;
return;
}
F_4 ( V_22 -> V_8 , V_10 ) ;
F_15 ( V_71 , F_3 () ) ;
F_16 ( & V_71 -> V_75 ) ;
V_2 = F_17 ( V_22 ) ;
V_71 -> V_76 -= V_22 -> V_77 ;
F_18 ( & V_71 -> V_75 ) ;
}
F_19 ( V_71 , false ) ;
}
static int F_20 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 ;
T_1 V_78 ;
T_7 * V_10 ;
int V_79 ;
if ( F_21 ( V_22 -> V_8 != - 1 ) )
return 0 ;
V_2 = F_17 ( V_22 ) ;
if ( F_13 ( V_71 -> V_76 + V_22 -> V_77 >=
V_71 -> V_80 ) )
return - V_81 ;
V_79 = F_22 ( V_22 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_3 ) ;
goto V_82;
}
if ( F_13 ( V_22 -> V_8 >= V_83 ) ) {
V_79 = - V_81 ;
goto V_84;
}
V_78 = F_2 ( V_2 ) ;
V_10 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_4 ) ;
V_79 = - V_85 ;
goto V_84;
}
F_5 ( V_2 , V_10 ) ;
F_15 ( V_71 , V_78 ) ;
V_71 -> V_76 += V_22 -> V_77 ;
return 0 ;
V_84:
F_23 ( V_22 ) ;
V_82:
return V_79 ;
}
static int F_24 ( struct V_69 * V_22 ,
struct V_86 * V_87 ,
bool V_88 )
{
T_2 V_34 ;
struct V_89 * V_90 ;
T_1 V_78 ;
struct V_1 * V_2 = F_17 ( V_22 ) ;
T_7 * V_10 ;
struct V_70 * V_71 = V_22 -> V_71 ;
F_25 ( V_87 -> V_91 == NULL ) ;
V_78 = F_1 ( V_2 ) ;
V_10 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_5 ) ;
return - V_85 ;
}
F_26 ( V_87 -> V_91 , & V_34 ) ;
F_7 ( V_2 , V_10 , & V_34 , V_88 ) ;
F_15 ( V_71 , V_78 ) ;
( void ) F_27 ( NULL , V_71 ,
& V_90 , NULL ) ;
F_28 ( V_87 -> V_91 , V_90 ) ;
if ( F_21 ( V_90 != NULL ) )
F_29 ( & V_90 ) ;
return 0 ;
}
static int F_30 ( struct V_69 * V_22 ,
struct V_86 * V_87 )
{
if ( ! V_22 -> V_92 )
return 0 ;
return F_24 ( V_22 , V_87 , true ) ;
}
static int F_31 ( struct V_69 * V_22 ,
bool V_93 ,
struct V_86 * V_87 )
{
if ( F_13 ( V_93 ) )
return F_24 ( V_22 , V_87 , false ) ;
return 0 ;
}
static int F_32 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
T_1 V_78 ;
T_7 * V_10 ;
F_25 ( V_22 -> V_8 == - 1 ) ;
V_78 = F_3 () ;
V_10 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_6 ) ;
return - V_85 ;
}
F_4 ( V_22 -> V_8 , V_10 ) ;
F_15 ( V_71 , V_78 ) ;
V_71 -> V_76 -= V_22 -> V_77 ;
F_23 ( V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_70 * V_71 ,
struct V_1 * V_2 ,
void (* F_34) ( struct V_69 * V_22 ) )
{
int V_79 ;
struct V_69 * V_22 = & V_2 -> V_22 ;
F_25 ( F_34 == NULL ) ;
if ( ! V_71 -> V_94 )
( void ) F_35 ( V_71 , false ) ;
V_79 = F_36 ( V_71 , V_22 , true , F_34 ,
( V_71 -> V_94 ) ? & V_95 :
& V_96 ) ;
if ( F_13 ( V_79 != 0 ) ) {
if ( ! V_71 -> V_94 )
F_19 ( V_71 , false ) ;
F_34 ( V_22 ) ;
return V_79 ;
}
F_37 ( V_22 , F_11 ) ;
return V_79 ;
}
static struct V_69 *
F_38 ( struct V_97 * V_98 )
{
return & ( F_39 ( V_98 , struct V_99 ,
V_100 . V_98 ) -> V_2 . V_22 ) ;
}
static void F_40 ( struct V_69 * V_22 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
struct V_99 * V_101 =
F_39 ( V_2 , struct V_99 , V_2 ) ;
struct V_70 * V_71 = V_2 -> V_22 . V_71 ;
T_1 V_13 = V_101 -> V_13 ;
F_41 ( V_2 -> V_42 ) ;
F_41 ( V_2 -> V_30 ) ;
F_41 ( V_2 -> V_102 . V_103 ) ;
F_42 ( V_101 , V_100 ) ;
F_43 ( F_44 ( V_71 ) , V_13 ) ;
}
static void F_45 ( struct V_97 * * V_104 )
{
struct V_97 * V_98 = * V_104 ;
struct V_99 * V_101 =
F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
struct V_69 * V_22 = & V_101 -> V_2 . V_22 ;
* V_104 = NULL ;
F_46 ( & V_22 ) ;
}
int F_47 ( struct V_105 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 = (struct V_110 * ) V_107 ;
struct V_112 * V_113 = F_48 ( V_109 ) -> V_113 ;
return F_49 ( V_113 , V_111 -> V_15 , V_114 ) ;
}
int F_50 ( struct V_105 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_70 * V_71 = F_51 ( V_106 ) ;
struct V_99 * V_101 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_115 ;
union V_116 * V_111 =
(union V_116 * ) V_107 ;
struct V_117 * V_118 = & V_111 -> V_118 ;
struct V_110 * V_119 = & V_111 -> V_119 ;
struct V_112 * V_113 = F_48 ( V_109 ) -> V_113 ;
struct V_16 T_8 * V_120 ;
int V_79 ;
int V_20 , V_121 ;
T_1 V_122 ;
struct V_16 * V_43 ;
struct V_40 * V_41 ;
T_1 V_3 ;
T_1 V_13 ;
struct V_123 * V_124 = V_123 ( V_109 -> V_125 ) ;
const struct V_36 * V_37 ;
if ( F_13 ( V_126 == 0 ) )
V_126 = F_52 ( sizeof( * V_101 ) ) +
128 ;
V_3 = 0 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_3 += V_118 -> V_29 [ V_20 ] ;
if ( V_3 > V_26 *
V_127 )
return - V_128 ;
V_13 = V_126 + 128 +
F_52 ( V_3 * sizeof( struct V_16 ) ) +
F_52 ( V_3 * sizeof( struct V_40 ) ) ;
V_37 = F_8 ( V_118 -> V_25 ) ;
if ( F_13 ( V_37 -> V_129 == V_130 ) ) {
F_14 ( L_7 ) ;
return - V_128 ;
}
V_79 = F_53 ( & V_124 -> V_131 , true ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_79 = F_54 ( F_44 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_79 != 0 ) ) {
if ( V_79 != - V_132 )
F_14 ( L_8
L_9 ) ;
goto V_133;
}
V_101 = F_55 ( sizeof( * V_101 ) , V_134 ) ;
if ( F_13 ( V_101 == NULL ) ) {
V_79 = - V_85 ;
goto V_135;
}
V_2 = & V_101 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_118 -> V_24 ;
V_2 -> V_25 = V_118 -> V_25 ;
V_2 -> V_136 = V_118 -> V_136 ;
memcpy ( V_2 -> V_29 , V_118 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_2 -> V_3 = V_3 ;
V_101 -> V_13 = V_13 ;
V_2 -> V_30 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_30 ) , V_134 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_79 = - V_85 ;
goto V_137;
}
V_2 -> V_42 = F_56 ( V_2 -> V_3 * sizeof( * V_2 -> V_42 ) ,
V_134 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_79 = - V_85 ;
goto V_138;
}
V_120 = (struct V_16 T_8 * ) ( unsigned long )
V_118 -> V_139 ;
V_79 = F_57 ( V_2 -> V_30 , V_120 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_79 != 0 ) ) {
V_79 = - V_140 ;
goto V_141;
}
V_2 -> V_142 = * V_2 -> V_30 ;
V_2 -> V_143 = V_144 ;
V_2 -> V_145 = 0 ;
V_122 = 0 ;
V_41 = V_2 -> V_42 ;
V_43 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 ) {
for ( V_121 = 0 ; V_121 < V_2 -> V_29 [ V_20 ] ; ++ V_121 ) {
T_1 V_146 = F_9
( V_37 , V_43 ) ;
V_41 -> V_27 = V_20 ;
V_41 -> V_51 = V_121 ;
V_41 -> V_47 = V_122 ;
V_122 += F_10
( V_37 , V_43 , V_146 ) ;
++ V_41 ;
++ V_43 ;
}
}
V_22 -> V_77 = V_122 ;
if ( V_2 -> V_136 &&
V_2 -> V_3 == 1 &&
V_2 -> V_30 [ 0 ] . V_31 == 64 &&
V_2 -> V_30 [ 0 ] . V_32 == 64 &&
V_2 -> V_25 == V_147 ) {
V_2 -> V_102 . V_103 = F_56 ( 64 * 64 * 4 , V_134 ) ;
if ( V_2 -> V_102 . V_103 ) {
memset ( V_2 -> V_102 . V_103 , 0x00 , 64 * 64 * 4 ) ;
} else {
F_14 ( L_10 ) ;
V_79 = - V_85 ;
goto V_141;
}
} else {
V_2 -> V_102 . V_103 = NULL ;
}
V_2 -> V_102 . V_148 = NULL ;
V_101 -> V_100 . V_98 . V_149 = false ;
V_101 -> V_100 . V_98 . V_113 = NULL ;
V_79 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_79 != 0 ) )
goto V_133;
if ( V_71 -> V_94 && V_118 -> V_149 ) {
T_1 V_150 ;
V_79 = F_58 ( V_71 , V_113 ,
V_22 -> V_77 ,
true ,
& V_150 ,
& V_22 -> V_151 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_46 ( & V_22 ) ;
goto V_133;
}
}
V_115 = F_59 ( & V_2 -> V_22 ) ;
V_79 = F_60 ( V_113 , V_22 -> V_77 , & V_101 -> V_100 ,
V_118 -> V_149 , V_152 ,
& F_45 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_46 ( & V_115 ) ;
F_46 ( & V_22 ) ;
goto V_133;
}
V_119 -> V_15 = V_101 -> V_100 . V_98 . V_153 . V_154 ;
F_46 ( & V_22 ) ;
F_61 ( & V_124 -> V_131 ) ;
return 0 ;
V_141:
F_41 ( V_2 -> V_42 ) ;
V_138:
F_41 ( V_2 -> V_30 ) ;
V_137:
F_42 ( V_101 , V_100 ) ;
V_135:
F_43 ( F_44 ( V_71 ) , V_13 ) ;
V_133:
F_61 ( & V_124 -> V_131 ) ;
return V_79 ;
}
int F_62 ( struct V_105 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_70 * V_71 = F_51 ( V_106 ) ;
union V_155 * V_111 =
(union V_155 * ) V_107 ;
struct V_110 * V_118 = & V_111 -> V_118 ;
struct V_117 * V_119 = & V_111 -> V_119 ;
struct V_112 * V_113 = F_48 ( V_109 ) -> V_113 ;
struct V_1 * V_2 ;
struct V_99 * V_101 ;
struct V_16 T_8 * V_120 ;
struct V_97 * V_98 ;
int V_79 = - V_128 ;
V_98 = F_63 ( V_71 -> V_156 , V_118 -> V_15 ) ;
if ( F_13 ( V_98 == NULL ) ) {
F_14 ( L_11 ) ;
return - V_128 ;
}
if ( F_13 ( F_64 ( V_98 ) != V_152 ) )
goto V_157;
V_101 = F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
V_2 = & V_101 -> V_2 ;
V_79 = F_65 ( V_113 , & V_101 -> V_100 . V_98 ,
V_114 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_12 ) ;
goto V_158;
}
V_119 -> V_24 = V_2 -> V_24 ;
V_119 -> V_25 = V_2 -> V_25 ;
memcpy ( V_119 -> V_29 , V_2 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_120 = (struct V_16 T_8 * ) ( unsigned long )
V_119 -> V_139 ;
if ( V_120 )
V_79 = F_66 ( V_120 , & V_2 -> V_142 ,
sizeof( V_2 -> V_142 ) ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_13 ,
V_120 , V_2 -> V_3 ) ;
V_79 = - V_140 ;
}
V_157:
V_158:
F_67 ( & V_98 ) ;
return V_79 ;
}
static int F_68 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 = F_17 ( V_22 ) ;
T_1 V_19 , V_159 ;
int V_79 ;
struct {
T_3 V_11 ;
T_9 V_14 ;
} * V_10 ;
if ( F_21 ( V_22 -> V_8 != - 1 ) )
return 0 ;
( void ) F_35 ( V_71 , false ) ;
V_79 = F_22 ( V_22 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_3 ) ;
goto V_82;
}
if ( F_13 ( V_22 -> V_8 >= V_160 ) ) {
V_79 = - V_81 ;
goto V_84;
}
V_19 = sizeof( V_10 -> V_14 ) ;
V_159 = sizeof( * V_10 ) ;
V_10 = F_12 ( V_71 , V_159 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_4 ) ;
V_79 = - V_85 ;
goto V_84;
}
V_10 -> V_11 . V_8 = V_161 ;
V_10 -> V_11 . V_13 = V_19 ;
V_10 -> V_14 . V_15 = V_2 -> V_22 . V_8 ;
V_10 -> V_14 . V_23 = V_2 -> V_24 ;
V_10 -> V_14 . V_25 = F_6 ( V_2 -> V_25 ) ;
V_10 -> V_14 . V_28 = V_2 -> V_29 [ 0 ] ;
V_10 -> V_14 . V_162 = V_2 -> V_145 ;
V_10 -> V_14 . V_163 = V_2 -> V_143 ;
V_10 -> V_14 . V_13 . V_31 = V_2 -> V_142 . V_31 ;
V_10 -> V_14 . V_13 . V_32 = V_2 -> V_142 . V_32 ;
V_10 -> V_14 . V_13 . V_33 = V_2 -> V_142 . V_33 ;
F_15 ( V_71 , V_159 ) ;
return 0 ;
V_84:
F_23 ( V_22 ) ;
V_82:
F_19 ( V_71 , false ) ;
return V_79 ;
}
static int F_69 ( struct V_69 * V_22 ,
struct V_86 * V_87 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct {
T_3 V_11 ;
T_10 V_14 ;
} * V_164 ;
struct {
T_3 V_11 ;
T_11 V_14 ;
} * V_165 ;
T_1 V_78 ;
struct V_166 * V_91 = V_87 -> V_91 ;
F_25 ( V_91 -> V_167 . V_168 != V_169 ) ;
V_78 = sizeof( * V_164 ) + ( V_22 -> V_92 ? sizeof( * V_165 ) : 0 ) ;
V_164 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_164 == NULL ) ) {
F_14 ( L_1
L_14 ) ;
return - V_85 ;
}
V_164 -> V_11 . V_8 = V_170 ;
V_164 -> V_11 . V_13 = sizeof( V_164 -> V_14 ) ;
V_164 -> V_14 . V_15 = V_22 -> V_8 ;
V_164 -> V_14 . V_171 = V_91 -> V_167 . V_172 ;
if ( V_22 -> V_92 ) {
V_165 = ( void * ) & V_164 [ 1 ] ;
V_165 -> V_11 . V_8 = V_173 ;
V_165 -> V_11 . V_13 = sizeof( V_165 -> V_14 ) ;
V_165 -> V_14 . V_15 = V_22 -> V_8 ;
V_22 -> V_92 = false ;
}
F_15 ( V_71 , V_78 ) ;
return 0 ;
}
static int F_70 ( struct V_69 * V_22 ,
bool V_93 ,
struct V_86 * V_87 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_166 * V_91 = V_87 -> V_91 ;
struct V_89 * V_90 ;
struct {
T_3 V_11 ;
T_12 V_14 ;
} * V_164 ;
struct {
T_3 V_11 ;
T_13 V_14 ;
} * V_165 ;
struct {
T_3 V_11 ;
T_10 V_14 ;
} * V_174 ;
T_1 V_78 ;
T_7 * V_10 ;
F_25 ( V_91 -> V_167 . V_168 != V_169 ) ;
V_78 = sizeof( * V_174 ) + ( V_93 ? sizeof( * V_164 ) : sizeof( * V_165 ) ) ;
V_10 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_15 ) ;
return - V_85 ;
}
if ( V_93 ) {
V_164 = ( void * ) V_10 ;
V_164 -> V_11 . V_8 = V_175 ;
V_164 -> V_11 . V_13 = sizeof( V_164 -> V_14 ) ;
V_164 -> V_14 . V_15 = V_22 -> V_8 ;
V_174 = ( void * ) & V_164 [ 1 ] ;
} else {
V_165 = ( void * ) V_10 ;
V_165 -> V_11 . V_8 = V_176 ;
V_165 -> V_11 . V_13 = sizeof( V_165 -> V_14 ) ;
V_165 -> V_14 . V_15 = V_22 -> V_8 ;
V_174 = ( void * ) & V_165 [ 1 ] ;
}
V_174 -> V_11 . V_8 = V_170 ;
V_174 -> V_11 . V_13 = sizeof( V_174 -> V_14 ) ;
V_174 -> V_14 . V_15 = V_22 -> V_8 ;
V_174 -> V_14 . V_171 = V_177 ;
F_15 ( V_71 , V_78 ) ;
( void ) F_27 ( NULL , V_71 ,
& V_90 , NULL ) ;
F_28 ( V_87 -> V_91 , V_90 ) ;
if ( F_21 ( V_90 != NULL ) )
F_29 ( & V_90 ) ;
return 0 ;
}
static int V_74 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct {
T_3 V_11 ;
T_14 V_14 ;
} * V_10 ;
if ( F_21 ( V_22 -> V_8 == - 1 ) )
return 0 ;
F_16 ( & V_71 -> V_178 ) ;
F_71 ( & V_22 -> V_179 ) ;
V_10 = F_12 ( V_71 , sizeof( * V_10 ) ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_2 ) ;
F_18 ( & V_71 -> V_178 ) ;
return - V_85 ;
}
V_10 -> V_11 . V_8 = V_180 ;
V_10 -> V_11 . V_13 = sizeof( V_10 -> V_14 ) ;
V_10 -> V_14 . V_15 = V_22 -> V_8 ;
F_15 ( V_71 , sizeof( * V_10 ) ) ;
F_18 ( & V_71 -> V_178 ) ;
F_23 ( V_22 ) ;
F_19 ( V_71 , false ) ;
return 0 ;
}
int F_72 ( struct V_105 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_70 * V_71 = F_51 ( V_106 ) ;
struct V_99 * V_101 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_115 ;
union V_181 * V_111 =
(union V_181 * ) V_107 ;
struct V_182 * V_118 = & V_111 -> V_118 ;
struct V_183 * V_119 = & V_111 -> V_119 ;
struct V_112 * V_113 = F_48 ( V_109 ) -> V_113 ;
int V_79 ;
T_1 V_13 ;
struct V_123 * V_124 = V_123 ( V_109 -> V_125 ) ;
const struct V_36 * V_37 ;
T_1 V_150 ;
if ( F_13 ( V_126 == 0 ) )
V_126 = F_52 ( sizeof( * V_101 ) ) +
128 ;
V_13 = V_126 + 128 ;
V_37 = F_8 ( V_118 -> V_25 ) ;
if ( F_13 ( V_37 -> V_129 == V_130 ) ) {
F_14 ( L_7 ) ;
return - V_128 ;
}
V_79 = F_53 ( & V_124 -> V_131 , true ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_79 = F_54 ( F_44 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_79 != 0 ) ) {
if ( V_79 != - V_132 )
F_14 ( L_8
L_9 ) ;
goto V_133;
}
V_101 = F_55 ( sizeof( * V_101 ) , V_134 ) ;
if ( F_13 ( V_101 == NULL ) ) {
V_79 = - V_85 ;
goto V_135;
}
V_2 = & V_101 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_118 -> V_184 ;
V_2 -> V_25 = V_118 -> V_25 ;
V_2 -> V_136 = V_118 -> V_185 & V_186 ;
V_2 -> V_29 [ 0 ] = V_118 -> V_29 ;
V_2 -> V_3 = 1 ;
V_2 -> V_30 = NULL ;
V_2 -> V_42 = NULL ;
V_101 -> V_13 = V_13 ;
V_2 -> V_142 = V_118 -> V_142 ;
V_2 -> V_143 = V_144 ;
V_2 -> V_145 = V_118 -> V_145 ;
V_22 -> V_77 = F_73
( V_2 -> V_25 , V_2 -> V_142 , V_2 -> V_29 [ 0 ] ,
V_2 -> V_24 & V_187 ) ;
V_101 -> V_100 . V_98 . V_149 = false ;
V_101 -> V_100 . V_98 . V_113 = NULL ;
V_79 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_79 != 0 ) )
goto V_133;
if ( V_118 -> V_188 != V_177 ) {
V_79 = F_74 ( V_113 , V_118 -> V_188 ,
& V_22 -> V_151 ) ;
} else if ( V_118 -> V_185 &
V_189 )
V_79 = F_58 ( V_71 , V_113 ,
V_22 -> V_77 ,
V_118 -> V_185 &
V_190 ,
& V_150 ,
& V_22 -> V_151 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_46 ( & V_22 ) ;
goto V_133;
}
V_115 = F_59 ( & V_2 -> V_22 ) ;
V_79 = F_60 ( V_113 , V_22 -> V_77 , & V_101 -> V_100 ,
V_118 -> V_185 &
V_190 ,
V_152 ,
& F_45 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_46 ( & V_115 ) ;
F_46 ( & V_22 ) ;
goto V_133;
}
V_119 -> V_191 = V_101 -> V_100 . V_98 . V_153 . V_154 ;
V_119 -> V_77 = V_22 -> V_77 ;
if ( V_22 -> V_151 ) {
V_119 -> V_192 =
F_75 ( & V_22 -> V_151 -> V_98 . V_193 ) ;
V_119 -> V_194 = V_22 -> V_151 -> V_98 . V_195 * V_196 ;
V_119 -> V_188 = V_150 ;
} else {
V_119 -> V_192 = 0 ;
V_119 -> V_194 = 0 ;
V_119 -> V_188 = V_177 ;
}
F_46 ( & V_22 ) ;
F_61 ( & V_124 -> V_131 ) ;
return 0 ;
V_135:
F_43 ( F_44 ( V_71 ) , V_13 ) ;
V_133:
F_61 ( & V_124 -> V_131 ) ;
return V_79 ;
}
int F_76 ( struct V_105 * V_106 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_70 * V_71 = F_51 ( V_106 ) ;
union V_197 * V_111 =
(union V_197 * ) V_107 ;
struct V_110 * V_118 = & V_111 -> V_118 ;
struct V_198 * V_119 = & V_111 -> V_119 ;
struct V_112 * V_113 = F_48 ( V_109 ) -> V_113 ;
struct V_1 * V_2 ;
struct V_99 * V_101 ;
struct V_97 * V_98 ;
T_1 V_150 ;
int V_79 = - V_128 ;
V_98 = F_63 ( V_71 -> V_156 , V_118 -> V_15 ) ;
if ( F_13 ( V_98 == NULL ) ) {
F_14 ( L_11 ) ;
return - V_128 ;
}
if ( F_13 ( F_64 ( V_98 ) != V_152 ) )
goto V_157;
V_101 = F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
V_2 = & V_101 -> V_2 ;
if ( V_2 -> V_22 . V_151 == NULL ) {
F_14 ( L_16 ) ;
goto V_157;
}
V_79 = F_65 ( V_113 , & V_101 -> V_100 . V_98 ,
V_114 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_17 ) ;
goto V_157;
}
F_16 ( & V_71 -> V_75 ) ;
V_79 = F_77 ( V_113 , V_2 -> V_22 . V_151 ,
& V_150 ) ;
F_18 ( & V_71 -> V_75 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_18
L_19 ) ;
( void ) F_49 ( F_48 ( V_109 ) -> V_113 ,
V_118 -> V_15 ,
V_114 ) ;
goto V_157;
}
V_119 -> V_199 . V_184 = V_2 -> V_24 ;
V_119 -> V_199 . V_25 = V_2 -> V_25 ;
V_119 -> V_199 . V_29 = V_2 -> V_29 [ 0 ] ;
V_119 -> V_199 . V_185 = 0 ;
V_119 -> V_199 . V_145 = V_2 -> V_145 ;
V_119 -> V_199 . V_143 = V_2 -> V_143 ;
V_119 -> V_199 . V_188 = V_150 ;
V_119 -> V_199 . V_142 = V_2 -> V_142 ;
V_119 -> V_200 . V_191 = V_101 -> V_100 . V_98 . V_153 . V_154 ;
V_119 -> V_200 . V_77 = V_2 -> V_22 . V_77 ;
V_119 -> V_200 . V_188 = V_150 ;
V_119 -> V_200 . V_192 =
F_75 ( & V_2 -> V_22 . V_151 -> V_98 . V_193 ) ;
V_119 -> V_200 . V_194 = V_2 -> V_22 . V_151 -> V_98 . V_195 * V_196 ;
V_157:
F_67 ( & V_98 ) ;
return V_79 ;
}
