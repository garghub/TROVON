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
if ( V_101 -> V_102 )
F_41 ( & V_101 -> V_102 ) ;
F_42 ( V_2 -> V_42 ) ;
F_42 ( V_2 -> V_30 ) ;
F_42 ( V_2 -> V_103 . V_104 ) ;
F_43 ( V_101 , V_100 ) ;
F_44 ( F_45 ( V_71 ) , V_13 ) ;
}
static void F_46 ( struct V_97 * * V_105 )
{
struct V_97 * V_98 = * V_105 ;
struct V_99 * V_101 =
F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
struct V_69 * V_22 = & V_101 -> V_2 . V_22 ;
* V_105 = NULL ;
F_47 ( & V_22 ) ;
}
int F_48 ( struct V_106 * V_107 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = (struct V_111 * ) V_108 ;
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
return F_50 ( V_114 , V_112 -> V_15 , V_115 ) ;
}
int F_51 ( struct V_106 * V_107 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_70 * V_71 = F_52 ( V_107 ) ;
struct V_99 * V_101 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_116 ;
union V_117 * V_112 =
(union V_117 * ) V_108 ;
struct V_118 * V_119 = & V_112 -> V_119 ;
struct V_111 * V_120 = & V_112 -> V_120 ;
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
struct V_16 T_8 * V_121 ;
int V_79 ;
int V_20 , V_122 ;
T_1 V_123 ;
struct V_16 * V_43 ;
struct V_40 * V_41 ;
T_1 V_3 ;
T_1 V_13 ;
const struct V_36 * V_37 ;
if ( F_13 ( V_124 == 0 ) )
V_124 = F_53 ( sizeof( * V_101 ) ) +
128 ;
V_3 = 0 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_3 += V_119 -> V_29 [ V_20 ] ;
if ( V_3 > V_26 *
V_125 )
return - V_126 ;
V_13 = V_124 + 128 +
F_53 ( V_3 * sizeof( struct V_16 ) ) +
F_53 ( V_3 * sizeof( struct V_40 ) ) ;
V_37 = F_8 ( V_119 -> V_25 ) ;
if ( F_13 ( V_37 -> V_127 == V_128 ) ) {
F_14 ( L_7 ) ;
return - V_126 ;
}
V_79 = F_54 ( & V_71 -> V_129 , true ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_79 = F_55 ( F_45 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_79 != 0 ) ) {
if ( V_79 != - V_130 )
F_14 ( L_8
L_9 ) ;
goto V_131;
}
V_101 = F_56 ( sizeof( * V_101 ) , V_132 ) ;
if ( F_13 ( V_101 == NULL ) ) {
V_79 = - V_85 ;
goto V_133;
}
V_2 = & V_101 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_119 -> V_24 ;
V_2 -> V_25 = V_119 -> V_25 ;
V_2 -> V_134 = V_119 -> V_134 ;
memcpy ( V_2 -> V_29 , V_119 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_2 -> V_3 = V_3 ;
V_101 -> V_13 = V_13 ;
V_2 -> V_30 = F_57 ( V_2 -> V_3 * sizeof( * V_2 -> V_30 ) , V_132 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_79 = - V_85 ;
goto V_135;
}
V_2 -> V_42 = F_57 ( V_2 -> V_3 * sizeof( * V_2 -> V_42 ) ,
V_132 ) ;
if ( F_13 ( V_2 -> V_30 == NULL ) ) {
V_79 = - V_85 ;
goto V_136;
}
V_121 = (struct V_16 T_8 * ) ( unsigned long )
V_119 -> V_137 ;
V_79 = F_58 ( V_2 -> V_30 , V_121 ,
V_2 -> V_3 * sizeof( * V_2 -> V_30 ) ) ;
if ( F_13 ( V_79 != 0 ) ) {
V_79 = - V_138 ;
goto V_139;
}
V_2 -> V_140 = * V_2 -> V_30 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_143 = 0 ;
V_123 = 0 ;
V_41 = V_2 -> V_42 ;
V_43 = V_2 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 ) {
for ( V_122 = 0 ; V_122 < V_2 -> V_29 [ V_20 ] ; ++ V_122 ) {
T_1 V_144 = F_9
( V_37 , V_43 ) ;
V_41 -> V_27 = V_20 ;
V_41 -> V_51 = V_122 ;
V_41 -> V_47 = V_123 ;
V_123 += F_10
( V_37 , V_43 , V_144 ) ;
++ V_41 ;
++ V_43 ;
}
}
V_22 -> V_77 = V_123 ;
if ( V_2 -> V_134 &&
V_2 -> V_3 == 1 &&
V_2 -> V_30 [ 0 ] . V_31 == 64 &&
V_2 -> V_30 [ 0 ] . V_32 == 64 &&
V_2 -> V_25 == V_145 ) {
V_2 -> V_103 . V_104 = F_57 ( 64 * 64 * 4 , V_132 ) ;
if ( V_2 -> V_103 . V_104 ) {
memset ( V_2 -> V_103 . V_104 , 0x00 , 64 * 64 * 4 ) ;
} else {
F_14 ( L_10 ) ;
V_79 = - V_85 ;
goto V_139;
}
} else {
V_2 -> V_103 . V_104 = NULL ;
}
V_2 -> V_103 . V_146 = NULL ;
V_101 -> V_100 . V_98 . V_147 = false ;
V_101 -> V_100 . V_98 . V_114 = NULL ;
if ( F_59 ( V_110 ) )
V_101 -> V_102 = F_60 ( V_110 -> V_102 ) ;
V_79 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_79 != 0 ) )
goto V_131;
if ( V_71 -> V_94 && V_119 -> V_147 ) {
T_1 V_148 ;
V_79 = F_61 ( V_71 , V_114 ,
V_22 -> V_77 ,
true ,
& V_148 ,
& V_22 -> V_149 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_47 ( & V_22 ) ;
goto V_131;
}
}
V_116 = F_62 ( & V_2 -> V_22 ) ;
V_79 = F_63 ( V_114 , V_22 -> V_77 , & V_101 -> V_100 ,
V_119 -> V_147 , V_150 ,
& F_46 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_47 ( & V_116 ) ;
F_47 ( & V_22 ) ;
goto V_131;
}
V_120 -> V_15 = V_101 -> V_100 . V_98 . V_151 . V_152 ;
F_47 ( & V_22 ) ;
F_64 ( & V_71 -> V_129 ) ;
return 0 ;
V_139:
F_42 ( V_2 -> V_42 ) ;
V_136:
F_42 ( V_2 -> V_30 ) ;
V_135:
F_43 ( V_101 , V_100 ) ;
V_133:
F_44 ( F_45 ( V_71 ) , V_13 ) ;
V_131:
F_64 ( & V_71 -> V_129 ) ;
return V_79 ;
}
static int
F_65 ( struct V_70 * V_71 ,
struct V_109 * V_110 ,
T_1 V_153 ,
enum V_154 V_155 ,
struct V_97 * * V_156 )
{
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
struct V_99 * V_101 ;
T_1 V_157 ;
struct V_97 * V_98 ;
int V_79 ;
if ( V_155 == V_158 ) {
V_79 = F_66 ( V_114 , V_153 , & V_157 ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
} else {
if ( F_13 ( F_67 ( V_110 ) ) ) {
F_14 ( L_11
L_12 ) ;
return - V_159 ;
}
V_157 = V_153 ;
}
V_79 = - V_126 ;
V_98 = F_68 ( V_71 -> V_160 , V_157 ) ;
if ( F_13 ( V_98 == NULL ) ) {
F_14 ( L_13 ) ;
goto V_161;
}
if ( F_13 ( F_69 ( V_98 ) != V_150 ) ) {
F_14 ( L_14 ) ;
goto V_162;
}
if ( V_155 != V_158 ) {
V_101 = F_39 ( V_98 , struct V_99 ,
V_100 . V_98 ) ;
if ( F_59 ( V_110 ) &&
V_101 -> V_102 != V_110 -> V_102 ) {
F_14 ( L_15
L_16 ) ;
V_79 = - V_159 ;
goto V_162;
}
V_79 = F_70 ( V_114 , V_98 , V_115 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_17 ) ;
goto V_162;
}
}
* V_156 = V_98 ;
return 0 ;
V_162:
F_71 ( & V_98 ) ;
V_161:
if ( V_155 == V_158 )
( void ) F_50 ( V_114 , V_157 , V_115 ) ;
return V_79 ;
}
int F_72 ( struct V_106 * V_107 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_70 * V_71 = F_52 ( V_107 ) ;
union V_163 * V_112 =
(union V_163 * ) V_108 ;
struct V_111 * V_119 = & V_112 -> V_119 ;
struct V_118 * V_120 = & V_112 -> V_120 ;
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
struct V_1 * V_2 ;
struct V_99 * V_101 ;
struct V_16 T_8 * V_121 ;
struct V_97 * V_98 ;
int V_79 ;
V_79 = F_65 ( V_71 , V_110 , V_119 -> V_15 ,
V_119 -> V_155 , & V_98 ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_101 = F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
V_2 = & V_101 -> V_2 ;
V_120 -> V_24 = V_2 -> V_24 ;
V_120 -> V_25 = V_2 -> V_25 ;
memcpy ( V_120 -> V_29 , V_2 -> V_29 , sizeof( V_2 -> V_29 ) ) ;
V_121 = (struct V_16 T_8 * ) ( unsigned long )
V_120 -> V_137 ;
if ( V_121 )
V_79 = F_73 ( V_121 , & V_2 -> V_140 ,
sizeof( V_2 -> V_140 ) ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_18 ,
V_121 , V_2 -> V_3 ) ;
F_50 ( V_114 , V_98 -> V_151 . V_152 , V_115 ) ;
V_79 = - V_138 ;
}
F_71 ( & V_98 ) ;
return V_79 ;
}
static int F_74 ( struct V_69 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_1 * V_2 = F_17 ( V_22 ) ;
T_1 V_19 , V_164 ;
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
if ( F_13 ( V_22 -> V_8 >= V_165 ) ) {
V_79 = - V_81 ;
goto V_84;
}
V_19 = sizeof( V_10 -> V_14 ) ;
V_164 = sizeof( * V_10 ) ;
V_10 = F_12 ( V_71 , V_164 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_4 ) ;
V_79 = - V_85 ;
goto V_84;
}
V_10 -> V_11 . V_8 = V_166 ;
V_10 -> V_11 . V_13 = V_19 ;
V_10 -> V_14 . V_15 = V_2 -> V_22 . V_8 ;
V_10 -> V_14 . V_23 = V_2 -> V_24 ;
V_10 -> V_14 . V_25 = F_6 ( V_2 -> V_25 ) ;
V_10 -> V_14 . V_28 = V_2 -> V_29 [ 0 ] ;
V_10 -> V_14 . V_167 = V_2 -> V_143 ;
V_10 -> V_14 . V_168 = V_2 -> V_141 ;
V_10 -> V_14 . V_13 . V_31 = V_2 -> V_140 . V_31 ;
V_10 -> V_14 . V_13 . V_32 = V_2 -> V_140 . V_32 ;
V_10 -> V_14 . V_13 . V_33 = V_2 -> V_140 . V_33 ;
F_15 ( V_71 , V_164 ) ;
return 0 ;
V_84:
F_23 ( V_22 ) ;
V_82:
F_19 ( V_71 , false ) ;
return V_79 ;
}
static int F_75 ( struct V_69 * V_22 ,
struct V_86 * V_87 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct {
T_3 V_11 ;
T_10 V_14 ;
} * V_169 ;
struct {
T_3 V_11 ;
T_11 V_14 ;
} * V_170 ;
T_1 V_78 ;
struct V_171 * V_91 = V_87 -> V_91 ;
F_25 ( V_91 -> V_172 . V_173 != V_174 ) ;
V_78 = sizeof( * V_169 ) + ( V_22 -> V_92 ? sizeof( * V_170 ) : 0 ) ;
V_169 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_169 == NULL ) ) {
F_14 ( L_1
L_19 ) ;
return - V_85 ;
}
V_169 -> V_11 . V_8 = V_175 ;
V_169 -> V_11 . V_13 = sizeof( V_169 -> V_14 ) ;
V_169 -> V_14 . V_15 = V_22 -> V_8 ;
V_169 -> V_14 . V_176 = V_91 -> V_172 . V_177 ;
if ( V_22 -> V_92 ) {
V_170 = ( void * ) & V_169 [ 1 ] ;
V_170 -> V_11 . V_8 = V_178 ;
V_170 -> V_11 . V_13 = sizeof( V_170 -> V_14 ) ;
V_170 -> V_14 . V_15 = V_22 -> V_8 ;
V_22 -> V_92 = false ;
}
F_15 ( V_71 , V_78 ) ;
return 0 ;
}
static int F_76 ( struct V_69 * V_22 ,
bool V_93 ,
struct V_86 * V_87 )
{
struct V_70 * V_71 = V_22 -> V_71 ;
struct V_171 * V_91 = V_87 -> V_91 ;
struct V_89 * V_90 ;
struct {
T_3 V_11 ;
T_12 V_14 ;
} * V_169 ;
struct {
T_3 V_11 ;
T_13 V_14 ;
} * V_170 ;
struct {
T_3 V_11 ;
T_10 V_14 ;
} * V_179 ;
T_1 V_78 ;
T_7 * V_10 ;
F_25 ( V_91 -> V_172 . V_173 != V_174 ) ;
V_78 = sizeof( * V_179 ) + ( V_93 ? sizeof( * V_169 ) : sizeof( * V_170 ) ) ;
V_10 = F_12 ( V_71 , V_78 ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_20 ) ;
return - V_85 ;
}
if ( V_93 ) {
V_169 = ( void * ) V_10 ;
V_169 -> V_11 . V_8 = V_180 ;
V_169 -> V_11 . V_13 = sizeof( V_169 -> V_14 ) ;
V_169 -> V_14 . V_15 = V_22 -> V_8 ;
V_179 = ( void * ) & V_169 [ 1 ] ;
} else {
V_170 = ( void * ) V_10 ;
V_170 -> V_11 . V_8 = V_181 ;
V_170 -> V_11 . V_13 = sizeof( V_170 -> V_14 ) ;
V_170 -> V_14 . V_15 = V_22 -> V_8 ;
V_179 = ( void * ) & V_170 [ 1 ] ;
}
V_179 -> V_11 . V_8 = V_175 ;
V_179 -> V_11 . V_13 = sizeof( V_179 -> V_14 ) ;
V_179 -> V_14 . V_15 = V_22 -> V_8 ;
V_179 -> V_14 . V_176 = V_182 ;
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
F_16 ( & V_71 -> V_183 ) ;
F_77 ( & V_22 -> V_184 ) ;
V_10 = F_12 ( V_71 , sizeof( * V_10 ) ) ;
if ( F_13 ( V_10 == NULL ) ) {
F_14 ( L_1
L_2 ) ;
F_18 ( & V_71 -> V_183 ) ;
return - V_85 ;
}
V_10 -> V_11 . V_8 = V_185 ;
V_10 -> V_11 . V_13 = sizeof( V_10 -> V_14 ) ;
V_10 -> V_14 . V_15 = V_22 -> V_8 ;
F_15 ( V_71 , sizeof( * V_10 ) ) ;
F_18 ( & V_71 -> V_183 ) ;
F_23 ( V_22 ) ;
F_19 ( V_71 , false ) ;
return 0 ;
}
int F_78 ( struct V_106 * V_107 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_70 * V_71 = F_52 ( V_107 ) ;
struct V_99 * V_101 ;
struct V_1 * V_2 ;
struct V_69 * V_22 ;
struct V_69 * V_116 ;
union V_186 * V_112 =
(union V_186 * ) V_108 ;
struct V_187 * V_119 = & V_112 -> V_119 ;
struct V_188 * V_120 = & V_112 -> V_120 ;
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
int V_79 ;
T_1 V_13 ;
const struct V_36 * V_37 ;
T_1 V_148 ;
if ( F_13 ( V_124 == 0 ) )
V_124 = F_53 ( sizeof( * V_101 ) ) +
128 ;
V_13 = V_124 + 128 ;
V_37 = F_8 ( V_119 -> V_25 ) ;
if ( F_13 ( V_37 -> V_127 == V_128 ) ) {
F_14 ( L_7 ) ;
return - V_126 ;
}
V_79 = F_54 ( & V_71 -> V_129 , true ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_79 = F_55 ( F_45 ( V_71 ) ,
V_13 , false , true ) ;
if ( F_13 ( V_79 != 0 ) ) {
if ( V_79 != - V_130 )
F_14 ( L_8
L_9 ) ;
goto V_131;
}
V_101 = F_56 ( sizeof( * V_101 ) , V_132 ) ;
if ( F_13 ( V_101 == NULL ) ) {
V_79 = - V_85 ;
goto V_133;
}
V_2 = & V_101 -> V_2 ;
V_22 = & V_2 -> V_22 ;
V_2 -> V_24 = V_119 -> V_189 ;
V_2 -> V_25 = V_119 -> V_25 ;
V_2 -> V_134 = V_119 -> V_190 & V_191 ;
V_2 -> V_29 [ 0 ] = V_119 -> V_29 ;
V_2 -> V_3 = 1 ;
V_2 -> V_30 = NULL ;
V_2 -> V_42 = NULL ;
V_101 -> V_13 = V_13 ;
V_2 -> V_140 = V_119 -> V_140 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_143 = V_119 -> V_143 ;
V_22 -> V_77 = F_79
( V_2 -> V_25 , V_2 -> V_140 , V_2 -> V_29 [ 0 ] ,
V_2 -> V_24 & V_192 ) ;
V_101 -> V_100 . V_98 . V_147 = false ;
V_101 -> V_100 . V_98 . V_114 = NULL ;
if ( F_59 ( V_110 ) )
V_101 -> V_102 = F_60 ( V_110 -> V_102 ) ;
V_79 = F_33 ( V_71 , V_2 , F_40 ) ;
if ( F_13 ( V_79 != 0 ) )
goto V_131;
if ( V_119 -> V_193 != V_182 ) {
V_79 = F_80 ( V_114 , V_119 -> V_193 ,
& V_22 -> V_149 ) ;
} else if ( V_119 -> V_190 &
V_194 )
V_79 = F_61 ( V_71 , V_114 ,
V_22 -> V_77 ,
V_119 -> V_190 &
V_195 ,
& V_148 ,
& V_22 -> V_149 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_47 ( & V_22 ) ;
goto V_131;
}
V_116 = F_62 ( & V_2 -> V_22 ) ;
V_79 = F_63 ( V_114 , V_22 -> V_77 , & V_101 -> V_100 ,
V_119 -> V_190 &
V_195 ,
V_150 ,
& F_46 , NULL ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_47 ( & V_116 ) ;
F_47 ( & V_22 ) ;
goto V_131;
}
V_120 -> V_157 = V_101 -> V_100 . V_98 . V_151 . V_152 ;
V_120 -> V_77 = V_22 -> V_77 ;
if ( V_22 -> V_149 ) {
V_120 -> V_196 =
F_81 ( & V_22 -> V_149 -> V_98 . V_197 ) ;
V_120 -> V_198 = V_22 -> V_149 -> V_98 . V_199 * V_200 ;
V_120 -> V_193 = V_148 ;
} else {
V_120 -> V_196 = 0 ;
V_120 -> V_198 = 0 ;
V_120 -> V_193 = V_182 ;
}
F_47 ( & V_22 ) ;
F_64 ( & V_71 -> V_129 ) ;
return 0 ;
V_133:
F_44 ( F_45 ( V_71 ) , V_13 ) ;
V_131:
F_64 ( & V_71 -> V_129 ) ;
return V_79 ;
}
int F_82 ( struct V_106 * V_107 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_70 * V_71 = F_52 ( V_107 ) ;
union V_201 * V_112 =
(union V_201 * ) V_108 ;
struct V_111 * V_119 = & V_112 -> V_119 ;
struct V_202 * V_120 = & V_112 -> V_120 ;
struct V_113 * V_114 = F_49 ( V_110 ) -> V_114 ;
struct V_1 * V_2 ;
struct V_99 * V_101 ;
struct V_97 * V_98 ;
T_1 V_148 ;
int V_79 = - V_126 ;
V_79 = F_65 ( V_71 , V_110 , V_119 -> V_15 ,
V_119 -> V_155 , & V_98 ) ;
if ( F_13 ( V_79 != 0 ) )
return V_79 ;
V_101 = F_39 ( V_98 , struct V_99 , V_100 . V_98 ) ;
V_2 = & V_101 -> V_2 ;
if ( V_2 -> V_22 . V_149 == NULL ) {
F_14 ( L_21 ) ;
goto V_162;
}
F_16 ( & V_71 -> V_75 ) ;
V_79 = F_83 ( V_114 , V_2 -> V_22 . V_149 ,
& V_148 ) ;
F_18 ( & V_71 -> V_75 ) ;
if ( F_13 ( V_79 != 0 ) ) {
F_14 ( L_22
L_23 ) ;
( void ) F_50 ( V_114 , V_98 -> V_151 . V_152 ,
V_115 ) ;
goto V_162;
}
V_120 -> V_203 . V_189 = V_2 -> V_24 ;
V_120 -> V_203 . V_25 = V_2 -> V_25 ;
V_120 -> V_203 . V_29 = V_2 -> V_29 [ 0 ] ;
V_120 -> V_203 . V_190 = 0 ;
V_120 -> V_203 . V_143 = V_2 -> V_143 ;
V_120 -> V_203 . V_141 = V_2 -> V_141 ;
V_120 -> V_203 . V_193 = V_148 ;
V_120 -> V_203 . V_140 = V_2 -> V_140 ;
V_120 -> V_204 . V_157 = V_101 -> V_100 . V_98 . V_151 . V_152 ;
V_120 -> V_204 . V_77 = V_2 -> V_22 . V_77 ;
V_120 -> V_204 . V_193 = V_148 ;
V_120 -> V_204 . V_196 =
F_81 ( & V_2 -> V_22 . V_149 -> V_98 . V_197 ) ;
V_120 -> V_204 . V_198 = V_2 -> V_22 . V_149 -> V_98 . V_199 * V_200 ;
V_162:
F_71 ( & V_98 ) ;
return V_79 ;
}
