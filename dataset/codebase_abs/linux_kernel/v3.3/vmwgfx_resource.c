static inline struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
V_5 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
return F_1 ( V_6 , struct V_5 , V_7 ) ;
}
struct V_8 * F_2 ( struct V_8 * V_9 )
{
F_3 ( & V_9 -> V_10 ) ;
return V_9 ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_5 ( & V_12 -> V_13 ) ;
if ( V_9 -> V_14 != - 1 )
F_6 ( V_9 -> V_15 , V_9 -> V_14 ) ;
V_9 -> V_14 = - 1 ;
F_7 ( & V_12 -> V_13 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_8 * V_9 =
F_1 ( V_10 , struct V_8 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_14 = V_9 -> V_14 ;
struct V_15 * V_15 = V_9 -> V_15 ;
V_9 -> V_16 = false ;
if ( V_9 -> V_17 != NULL )
V_9 -> V_17 ( V_9 ) ;
F_7 ( & V_12 -> V_13 ) ;
if ( F_9 ( V_9 -> V_18 != NULL ) )
V_9 -> V_18 ( V_9 ) ;
if ( V_9 -> V_19 != NULL )
V_9 -> V_19 ( V_9 ) ;
else
F_10 ( V_9 ) ;
F_5 ( & V_12 -> V_13 ) ;
if ( V_14 != - 1 )
F_6 ( V_15 , V_14 ) ;
}
void F_11 ( struct V_8 * * V_20 )
{
struct V_8 * V_9 = * V_20 ;
struct V_11 * V_12 = V_9 -> V_12 ;
* V_20 = NULL ;
F_5 ( & V_12 -> V_13 ) ;
F_12 ( & V_9 -> V_10 , F_8 ) ;
F_7 ( & V_12 -> V_13 ) ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_8 * V_9 )
{
int V_21 ;
F_14 ( V_9 -> V_14 != - 1 ) ;
do {
if ( F_15 ( F_16 ( V_9 -> V_15 , V_22 ) == 0 ) )
return - V_23 ;
F_5 ( & V_12 -> V_13 ) ;
V_21 = F_17 ( V_9 -> V_15 , V_9 , 1 , & V_9 -> V_14 ) ;
F_7 ( & V_12 -> V_13 ) ;
} while ( V_21 == - V_24 );
return V_21 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_8 * V_9 ,
struct V_15 * V_15 ,
enum V_25 V_26 ,
bool V_27 ,
void (* V_19) ( struct V_8 * V_9 ) ,
void (* V_17)
( struct V_8 * V_9 ) )
{
F_19 ( & V_9 -> V_10 ) ;
V_9 -> V_18 = NULL ;
V_9 -> V_19 = V_19 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_28 = V_26 ;
V_9 -> V_15 = V_15 ;
V_9 -> V_16 = false ;
V_9 -> V_12 = V_12 ;
F_20 ( & V_9 -> V_29 ) ;
F_20 ( & V_9 -> V_30 ) ;
V_9 -> V_14 = - 1 ;
if ( V_27 )
return 0 ;
else
return F_13 ( V_12 , V_9 ) ;
}
static void F_21 ( struct V_8 * V_9 ,
void (* V_18) ( struct V_8 * ) )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_5 ( & V_12 -> V_13 ) ;
V_9 -> V_16 = true ;
V_9 -> V_18 = V_18 ;
F_7 ( & V_12 -> V_13 ) ;
}
struct V_8 * F_22 ( struct V_11 * V_12 ,
struct V_15 * V_15 , int V_14 )
{
struct V_8 * V_9 ;
F_23 ( & V_12 -> V_13 ) ;
V_9 = F_24 ( V_15 , V_14 ) ;
if ( V_9 && V_9 -> V_16 )
F_3 ( & V_9 -> V_10 ) ;
else
V_9 = NULL ;
F_25 ( & V_12 -> V_13 ) ;
if ( F_15 ( V_9 == NULL ) )
return NULL ;
return V_9 ;
}
static void F_26 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct {
T_1 V_31 ;
T_2 V_32 ;
} * V_33 ;
F_27 ( V_12 , true , V_9 -> V_14 ) ;
V_33 = F_28 ( V_12 , sizeof( * V_33 ) ) ;
if ( F_15 ( V_33 == NULL ) ) {
F_29 ( L_1
L_2 ) ;
return;
}
V_33 -> V_31 . V_14 = F_30 ( V_34 ) ;
V_33 -> V_31 . V_35 = F_30 ( sizeof( V_33 -> V_32 ) ) ;
V_33 -> V_32 . V_36 = F_30 ( V_9 -> V_14 ) ;
F_31 ( V_12 , sizeof( * V_33 ) ) ;
F_32 ( V_12 , false ) ;
}
static int F_33 ( struct V_11 * V_12 ,
struct V_8 * V_9 ,
void (* V_19) ( struct V_8 * V_9 ) )
{
int V_21 ;
struct {
T_1 V_31 ;
T_3 V_32 ;
} * V_33 ;
V_21 = F_18 ( V_12 , V_9 , & V_12 -> V_37 ,
V_38 , false , V_19 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_29 ( L_3 ) ;
goto V_39;
}
if ( F_15 ( V_9 -> V_14 >= V_40 ) ) {
F_29 ( L_4 ) ;
F_11 ( & V_9 ) ;
return - V_23 ;
}
V_33 = F_28 ( V_12 , sizeof( * V_33 ) ) ;
if ( F_15 ( V_33 == NULL ) ) {
F_29 ( L_5 ) ;
F_11 ( & V_9 ) ;
return - V_23 ;
}
V_33 -> V_31 . V_14 = F_30 ( V_41 ) ;
V_33 -> V_31 . V_35 = F_30 ( sizeof( V_33 -> V_32 ) ) ;
V_33 -> V_32 . V_36 = F_30 ( V_9 -> V_14 ) ;
F_31 ( V_12 , sizeof( * V_33 ) ) ;
( void ) F_34 ( V_12 , false ) ;
F_21 ( V_9 , F_26 ) ;
return 0 ;
V_39:
if ( V_19 == NULL )
F_10 ( V_9 ) ;
else
V_19 ( V_9 ) ;
return V_21 ;
}
struct V_8 * F_35 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_36 ( sizeof( * V_9 ) , V_22 ) ;
int V_21 ;
if ( F_15 ( V_9 == NULL ) )
return NULL ;
V_21 = F_33 ( V_12 , V_9 , NULL ) ;
return ( V_21 == 0 ) ? V_9 : NULL ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_42 * V_43 =
F_1 ( V_9 , struct V_42 , V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_10 ( V_43 ) ;
F_38 ( F_39 ( V_12 ) ,
V_44 ) ;
}
static void F_40 ( struct V_45 * * V_46 )
{
struct V_45 * V_4 = * V_46 ;
struct V_42 * V_43 =
F_1 ( V_4 , struct V_42 , V_4 ) ;
struct V_8 * V_9 = & V_43 -> V_9 ;
* V_46 = NULL ;
F_11 ( & V_9 ) ;
}
int F_41 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
struct V_8 * V_9 ;
struct V_42 * V_43 ;
struct V_52 * V_53 = (struct V_52 * ) V_49 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
int V_21 = 0 ;
V_9 = F_22 ( V_12 , & V_12 -> V_37 , V_53 -> V_36 ) ;
if ( F_15 ( V_9 == NULL ) )
return - V_56 ;
if ( V_9 -> V_19 != & F_37 ) {
V_21 = - V_56 ;
goto V_57;
}
V_43 = F_1 ( V_9 , struct V_42 , V_9 ) ;
if ( V_43 -> V_4 . V_55 != V_55 && ! V_43 -> V_4 . V_58 ) {
V_21 = - V_59 ;
goto V_57;
}
F_44 ( V_55 , V_43 -> V_4 . V_60 . V_61 , V_62 ) ;
V_57:
F_11 ( & V_9 ) ;
return V_21 ;
}
int F_45 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
struct V_42 * V_43 ;
struct V_8 * V_9 ;
struct V_8 * V_63 ;
struct V_52 * V_53 = (struct V_52 * ) V_49 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
struct V_64 * V_65 = V_64 ( V_51 -> V_66 ) ;
int V_21 ;
if ( F_15 ( V_44 == 0 ) )
V_44 = F_46 ( sizeof( * V_43 ) ) + 128 ;
V_21 = F_47 ( & V_65 -> V_67 , true ) ;
if ( F_15 ( V_21 != 0 ) )
return V_21 ;
V_21 = F_48 ( F_39 ( V_12 ) ,
V_44 ,
false , true ) ;
if ( F_15 ( V_21 != 0 ) ) {
if ( V_21 != - V_68 )
F_29 ( L_6
L_7 ) ;
goto V_69;
}
V_43 = F_36 ( sizeof( * V_43 ) , V_22 ) ;
if ( F_15 ( V_43 == NULL ) ) {
F_38 ( F_39 ( V_12 ) ,
V_44 ) ;
V_21 = - V_23 ;
goto V_69;
}
V_9 = & V_43 -> V_9 ;
V_43 -> V_4 . V_58 = false ;
V_43 -> V_4 . V_55 = NULL ;
V_21 = F_33 ( V_12 , V_9 , F_37 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_69;
V_63 = F_2 ( & V_43 -> V_9 ) ;
V_21 = F_49 ( V_55 , & V_43 -> V_4 , false , V_38 ,
& F_40 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_11 ( & V_63 ) ;
goto V_70;
}
V_53 -> V_36 = V_9 -> V_14 ;
V_70:
F_11 ( & V_9 ) ;
V_69:
F_50 ( & V_65 -> V_67 ) ;
return V_21 ;
}
int F_51 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
int V_14 ,
struct V_8 * * V_20 )
{
struct V_8 * V_9 ;
int V_21 = 0 ;
F_23 ( & V_12 -> V_13 ) ;
V_9 = F_24 ( & V_12 -> V_37 , V_14 ) ;
if ( V_9 && V_9 -> V_16 ) {
struct V_42 * V_43 =
F_1 ( V_9 , struct V_42 , V_9 ) ;
if ( V_43 -> V_4 . V_55 != V_55 && ! V_43 -> V_4 . V_58 )
V_21 = - V_59 ;
if ( V_20 )
* V_20 = F_2 ( V_9 ) ;
} else
V_21 = - V_56 ;
F_25 ( & V_12 -> V_13 ) ;
return V_21 ;
}
static inline T_4 F_52 ( const struct V_71 * V_72 )
{
return V_72 -> V_73 * sizeof( struct V_74 ) ;
}
static inline T_4 F_53 ( const struct V_71 * V_72 )
{
return sizeof( struct V_75 ) + V_72 -> V_73 *
sizeof( V_76 ) ;
}
static inline T_4 F_54 ( void )
{
return sizeof( struct V_77 ) ;
}
static void F_55 ( T_4 V_14 ,
void * V_78 )
{
struct V_77 * V_33 = (struct V_77 * )
V_78 ;
V_33 -> V_31 . V_14 = V_79 ;
V_33 -> V_31 . V_35 = sizeof( V_33 -> V_32 ) ;
V_33 -> V_32 . V_80 = V_14 ;
}
static void F_56 ( const struct V_71 * V_72 ,
void * V_78 )
{
struct V_75 * V_33 = (struct V_75 * )
V_78 ;
struct V_81 * V_82 ;
V_76 * V_83 ;
T_4 V_84 ;
int V_85 ;
V_84 = sizeof( V_33 -> V_32 ) + V_72 -> V_73 * sizeof( V_76 ) ;
V_33 -> V_31 . V_14 = V_86 ;
V_33 -> V_31 . V_35 = V_84 ;
V_33 -> V_32 . V_80 = V_72 -> V_9 . V_14 ;
V_33 -> V_32 . V_87 = V_72 -> V_88 ;
V_33 -> V_32 . V_89 = F_30 ( V_72 -> V_89 ) ;
for ( V_85 = 0 ; V_85 < V_90 ; ++ V_85 )
V_33 -> V_32 . V_91 [ V_85 ] . V_92 = V_72 -> V_93 [ V_85 ] ;
V_33 += 1 ;
V_83 = ( V_76 * ) V_33 ;
V_82 = V_72 -> V_94 ;
for ( V_85 = 0 ; V_85 < V_72 -> V_73 ; ++ V_85 , V_83 ++ , V_82 ++ ) {
V_83 -> V_95 = V_82 -> V_95 ;
V_83 -> V_96 = V_82 -> V_96 ;
V_83 -> V_97 = V_82 -> V_97 ;
}
}
static void F_57 ( struct V_71 * V_72 ,
void * V_78 ,
const T_5 * V_98 ,
bool V_99 )
{
T_4 V_85 ;
T_4 V_100 = V_101 [ V_72 -> V_89 ] . V_100 ;
T_4 V_102 = V_101 [ V_72 -> V_89 ] . V_103 ;
struct V_74 * V_33 = (struct V_74 * ) V_78 ;
for ( V_85 = 0 ; V_85 < V_72 -> V_73 ; ++ V_85 ) {
T_1 * V_31 = & V_33 -> V_31 ;
T_6 * V_32 = & V_33 -> V_32 ;
T_7 * V_104 = & V_33 -> V_104 ;
T_8 * V_105 = & V_33 -> V_105 ;
const struct V_106 * V_107 = & V_72 -> V_108 [ V_85 ] ;
const struct V_81 * V_109 = & V_72 -> V_94 [ V_85 ] ;
V_31 -> V_14 = V_110 ;
V_31 -> V_35 = sizeof( * V_32 ) + sizeof( * V_104 ) + sizeof( * V_105 ) ;
V_32 -> V_111 . V_98 = * V_98 ;
V_32 -> V_111 . V_98 . V_112 += V_107 -> V_113 ;
V_32 -> V_111 . V_114 = ( V_109 -> V_95 * V_102 + 7 ) >> 3 ;
V_32 -> V_115 . V_80 = V_72 -> V_9 . V_14 ;
V_32 -> V_115 . V_91 = V_107 -> V_91 ;
V_32 -> V_115 . V_116 = V_107 -> V_117 ;
V_32 -> V_118 = ( ( V_99 ) ? V_119 :
V_120 ) ;
V_104 -> V_121 = 0 ;
V_104 -> V_122 = 0 ;
V_104 -> V_123 = 0 ;
V_104 -> V_124 = 0 ;
V_104 -> V_125 = 0 ;
V_104 -> V_126 = 0 ;
V_104 -> V_127 = V_109 -> V_95 ;
V_104 -> V_128 = V_109 -> V_96 ;
V_104 -> V_129 = V_109 -> V_97 ;
V_105 -> V_130 = sizeof( * V_105 ) ;
V_105 -> V_131 = V_32 -> V_111 . V_114 * V_109 -> V_96 *
V_109 -> V_97 * V_100 / V_102 ;
V_105 -> V_88 . V_132 = 0 ;
V_105 -> V_88 . V_133 = 0 ;
V_105 -> V_88 . V_134 = 0 ;
++ V_33 ;
}
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_71 * V_72 ;
void * V_33 ;
if ( V_9 -> V_14 != - 1 ) {
V_33 = F_28 ( V_12 , F_54 () ) ;
if ( F_15 ( V_33 == NULL ) ) {
F_29 ( L_1
L_2 ) ;
return;
}
F_55 ( V_9 -> V_14 , V_33 ) ;
F_31 ( V_12 , F_54 () ) ;
F_59 ( & V_12 -> V_135 ) ;
V_72 = F_1 ( V_9 , struct V_71 , V_9 ) ;
V_12 -> V_136 -= V_72 -> V_137 ;
F_60 ( & V_12 -> V_135 ) ;
}
F_32 ( V_12 , false ) ;
}
void F_61 ( struct V_8 * V_9 )
{
struct V_71 * V_72 = F_1 ( V_9 , struct V_71 , V_9 ) ;
if ( V_72 -> V_138 )
F_62 ( & V_72 -> V_138 ) ;
F_10 ( V_72 -> V_108 ) ;
F_10 ( V_72 -> V_94 ) ;
F_10 ( V_72 -> V_139 . V_140 ) ;
F_10 ( V_72 ) ;
}
int F_63 ( struct V_11 * V_12 ,
struct V_71 * V_72 )
{
struct V_8 * V_9 = & V_72 -> V_9 ;
struct V_141 V_142 ;
struct V_143 V_144 ;
T_4 V_145 ;
T_9 * V_33 ;
int V_21 ;
if ( F_9 ( V_9 -> V_14 != - 1 ) )
return 0 ;
if ( F_15 ( V_12 -> V_136 + V_72 -> V_137 >=
V_12 -> V_146 ) )
return - V_147 ;
if ( V_72 -> V_138 ) {
F_20 ( & V_142 ) ;
V_144 . V_3 = F_64 ( V_72 -> V_138 ) ;
V_144 . V_148 = ( void * ) ( ( unsigned long )
V_149 ) ;
F_65 ( & V_144 . V_150 , & V_142 ) ;
V_21 = F_66 ( & V_142 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_151;
V_21 = F_67 ( V_72 -> V_138 , & V_152 ,
true , false , false ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_153;
}
V_21 = F_13 ( V_12 , V_9 ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_29 ( L_8 ) ;
goto V_154;
}
if ( F_15 ( V_9 -> V_14 >= V_155 ) ) {
V_21 = - V_147 ;
goto V_156;
}
V_145 = F_53 ( V_72 ) ;
if ( V_72 -> V_138 )
V_145 += F_52 ( V_72 ) ;
V_33 = F_28 ( V_12 , V_145 ) ;
if ( F_15 ( V_33 == NULL ) ) {
F_29 ( L_1
L_9 ) ;
V_21 = - V_23 ;
goto V_156;
}
F_56 ( V_72 , V_33 ) ;
if ( V_72 -> V_138 ) {
T_5 V_98 ;
V_33 += F_53 ( V_72 ) ;
F_68 ( V_72 -> V_138 , & V_98 ) ;
F_57 ( V_72 , V_33 , & V_98 , true ) ;
}
F_31 ( V_12 , V_145 ) ;
if ( V_72 -> V_138 ) {
struct V_157 * V_158 ;
( void ) F_69 ( NULL , V_12 ,
& V_158 , NULL ) ;
F_70 ( & V_142 , V_158 ) ;
if ( F_9 ( V_158 != NULL ) )
F_71 ( & V_158 ) ;
F_62 ( & V_144 . V_3 ) ;
F_62 ( & V_72 -> V_138 ) ;
}
V_12 -> V_136 += V_72 -> V_137 ;
return 0 ;
V_156:
F_4 ( V_9 ) ;
V_154:
V_153:
if ( V_72 -> V_138 )
F_72 ( & V_142 ) ;
V_151:
if ( V_72 -> V_138 )
F_62 ( & V_144 . V_3 ) ;
return V_21 ;
}
int F_73 ( struct V_11 * V_12 ,
struct V_71 * V_72 )
{
struct V_8 * V_9 = & V_72 -> V_9 ;
struct V_141 V_142 ;
struct V_143 V_144 ;
T_4 V_145 ;
T_9 * V_33 ;
int V_21 ;
struct V_157 * V_158 ;
T_5 V_98 ;
F_14 ( V_9 -> V_14 == - 1 ) ;
if ( ! V_72 -> V_138 ) {
V_21 = F_74 ( & V_12 -> V_159 , V_72 -> V_137 ,
V_160 ,
& V_152 , 0 , 0 , true ,
NULL , & V_72 -> V_138 ) ;
if ( F_15 ( V_21 != 0 ) )
return V_21 ;
}
F_20 ( & V_142 ) ;
V_144 . V_3 = F_64 ( V_72 -> V_138 ) ;
V_144 . V_148 = ( void * ) ( unsigned long )
V_149 ;
F_65 ( & V_144 . V_150 , & V_142 ) ;
V_21 = F_66 ( & V_142 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_151;
V_21 = F_67 ( V_72 -> V_138 , & V_152 ,
true , false , false ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_153;
V_145 = F_52 ( V_72 ) + F_54 () ;
V_33 = F_28 ( V_12 , V_145 ) ;
if ( F_15 ( V_33 == NULL ) ) {
F_29 ( L_1
L_10 ) ;
V_21 = - V_23 ;
goto V_156;
}
F_68 ( V_72 -> V_138 , & V_98 ) ;
F_57 ( V_72 , V_33 , & V_98 , false ) ;
V_33 += F_52 ( V_72 ) ;
F_55 ( V_9 -> V_14 , V_33 ) ;
F_31 ( V_12 , V_145 ) ;
V_12 -> V_136 -= V_72 -> V_137 ;
( void ) F_69 ( NULL , V_12 ,
& V_158 , NULL ) ;
F_70 ( & V_142 , V_158 ) ;
if ( F_9 ( V_158 != NULL ) )
F_71 ( & V_158 ) ;
F_62 ( & V_144 . V_3 ) ;
F_4 ( V_9 ) ;
return 0 ;
V_156:
V_153:
if ( V_72 -> V_138 )
F_72 ( & V_142 ) ;
V_151:
F_62 ( & V_144 . V_3 ) ;
F_62 ( & V_72 -> V_138 ) ;
return V_21 ;
}
int F_75 ( struct V_11 * V_12 ,
struct V_71 * V_72 )
{
int V_21 ;
struct V_71 * V_161 ;
do {
F_5 ( & V_12 -> V_13 ) ;
F_76 ( & V_72 -> V_162 ) ;
F_7 ( & V_12 -> V_13 ) ;
V_21 = F_63 ( V_12 , V_72 ) ;
if ( F_9 ( V_21 != - V_147 ) )
break;
F_5 ( & V_12 -> V_13 ) ;
if ( F_77 ( & V_12 -> V_163 ) ) {
F_29 ( L_11 ) ;
V_21 = - V_147 ;
F_7 ( & V_12 -> V_13 ) ;
break;
}
V_161 = F_78
( F_79 ( & V_12 -> V_163 ,
struct V_71 ,
V_162 ) ) ;
F_76 ( & V_161 -> V_162 ) ;
F_7 ( & V_12 -> V_13 ) ;
( void ) F_73 ( V_12 , V_161 ) ;
F_80 ( & V_161 ) ;
} while ( 1 );
if ( F_15 ( V_21 != 0 && V_72 -> V_9 . V_14 != - 1 ) ) {
F_5 ( & V_12 -> V_13 ) ;
F_65 ( & V_72 -> V_162 , & V_12 -> V_163 ) ;
F_7 ( & V_12 -> V_13 ) ;
}
return V_21 ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_71 * V_72 = F_1 ( V_9 , struct V_71 , V_9 ) ;
F_76 ( & V_72 -> V_162 ) ;
}
int F_82 ( struct V_11 * V_12 ,
struct V_71 * V_72 ,
void (* V_19) ( struct V_8 * V_9 ) )
{
int V_21 ;
struct V_8 * V_9 = & V_72 -> V_9 ;
F_14 ( V_19 == NULL ) ;
F_20 ( & V_72 -> V_162 ) ;
V_21 = F_18 ( V_12 , V_9 , & V_12 -> V_164 ,
V_165 , true , V_19 ,
F_81 ) ;
if ( F_15 ( V_21 != 0 ) )
V_19 ( V_9 ) ;
( void ) F_34 ( V_12 , false ) ;
F_21 ( V_9 , F_58 ) ;
return V_21 ;
}
static void F_83 ( struct V_8 * V_9 )
{
struct V_71 * V_72 = F_1 ( V_9 , struct V_71 , V_9 ) ;
struct V_166 * V_167 =
F_1 ( V_72 , struct V_166 , V_72 ) ;
struct V_11 * V_12 = V_72 -> V_9 . V_12 ;
T_4 V_35 = V_167 -> V_35 ;
if ( V_72 -> V_138 )
F_62 ( & V_72 -> V_138 ) ;
F_10 ( V_72 -> V_108 ) ;
F_10 ( V_72 -> V_94 ) ;
F_10 ( V_72 -> V_139 . V_140 ) ;
F_10 ( V_167 ) ;
F_38 ( F_39 ( V_12 ) , V_35 ) ;
}
void F_84 ( struct V_141 * V_168 )
{
struct V_8 * V_9 ;
struct V_71 * V_72 ;
T_10 * V_67 = NULL ;
F_85 (res, list, validate_head) {
if ( V_9 -> V_19 != & F_61 &&
V_9 -> V_19 != & F_83 )
continue;
if ( F_15 ( V_67 == NULL ) ) {
V_67 = & V_9 -> V_12 -> V_13 ;
F_5 ( V_67 ) ;
}
V_72 = F_1 ( V_9 , struct V_71 , V_9 ) ;
F_76 ( & V_72 -> V_162 ) ;
F_65 ( & V_72 -> V_162 , & V_9 -> V_12 -> V_163 ) ;
}
if ( V_67 != NULL )
F_7 ( V_67 ) ;
}
int F_86 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
T_4 V_169 ,
struct V_71 * * V_170 ,
struct V_1 * * V_171 )
{
int V_21 ;
F_14 ( * V_170 || * V_171 ) ;
V_21 = F_87 ( V_12 , V_55 , V_169 , V_170 ) ;
if ( ! V_21 )
return 0 ;
V_21 = F_88 ( V_55 , V_169 , V_171 ) ;
return V_21 ;
}
int F_87 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
T_4 V_169 , struct V_71 * * V_57 )
{
struct V_8 * V_9 ;
struct V_71 * V_72 ;
struct V_166 * V_167 ;
struct V_45 * V_4 ;
int V_21 = - V_56 ;
V_4 = F_89 ( V_55 , V_169 ) ;
if ( F_15 ( V_4 == NULL ) )
return - V_56 ;
if ( F_15 ( V_4 -> V_172 != V_165 ) )
goto V_173;
V_167 = F_1 ( V_4 , struct V_166 , V_4 ) ;
V_72 = & V_167 -> V_72 ;
V_9 = & V_72 -> V_9 ;
F_23 ( & V_12 -> V_13 ) ;
if ( ! V_9 -> V_16 || V_9 -> V_19 != & F_83 ) {
F_25 ( & V_12 -> V_13 ) ;
goto V_173;
}
F_3 ( & V_9 -> V_10 ) ;
F_25 ( & V_12 -> V_13 ) ;
* V_57 = V_72 ;
V_21 = 0 ;
V_173:
F_90 ( & V_4 ) ;
return V_21 ;
}
static void F_91 ( struct V_45 * * V_46 )
{
struct V_45 * V_4 = * V_46 ;
struct V_166 * V_167 =
F_1 ( V_4 , struct V_166 , V_4 ) ;
struct V_8 * V_9 = & V_167 -> V_72 . V_9 ;
* V_46 = NULL ;
F_11 ( & V_9 ) ;
}
int F_92 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_174 * V_53 = (struct V_174 * ) V_49 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
return F_44 ( V_55 , V_53 -> V_80 , V_62 ) ;
}
int F_93 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
struct V_166 * V_167 ;
struct V_71 * V_72 ;
struct V_8 * V_9 ;
struct V_8 * V_63 ;
union V_175 * V_53 =
(union V_175 * ) V_49 ;
struct V_176 * V_177 = & V_53 -> V_177 ;
struct V_174 * V_178 = & V_53 -> V_178 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
struct V_81 T_11 * V_179 ;
int V_21 ;
int V_85 , V_180 ;
T_4 V_181 ;
struct V_81 * V_109 ;
struct V_106 * V_107 ;
T_4 V_102 ;
T_4 V_100 ;
T_4 V_73 ;
T_4 V_35 ;
struct V_64 * V_65 = V_64 ( V_51 -> V_66 ) ;
if ( F_15 ( V_182 == 0 ) )
V_182 = F_46 ( sizeof( * V_167 ) ) +
128 ;
V_73 = 0 ;
for ( V_85 = 0 ; V_85 < V_90 ; ++ V_85 )
V_73 += V_177 -> V_93 [ V_85 ] ;
if ( V_73 > V_90 *
V_183 )
return - V_56 ;
V_35 = V_182 + 128 +
F_46 ( V_73 * sizeof( struct V_81 ) ) +
F_46 ( V_73 * sizeof( struct V_106 ) ) ;
V_21 = F_47 ( & V_65 -> V_67 , true ) ;
if ( F_15 ( V_21 != 0 ) )
return V_21 ;
V_21 = F_48 ( F_39 ( V_12 ) ,
V_35 , false , true ) ;
if ( F_15 ( V_21 != 0 ) ) {
if ( V_21 != - V_68 )
F_29 ( L_12
L_7 ) ;
goto V_69;
}
V_167 = F_36 ( sizeof( * V_167 ) , V_22 ) ;
if ( F_15 ( V_167 == NULL ) ) {
V_21 = - V_23 ;
goto V_184;
}
V_72 = & V_167 -> V_72 ;
V_9 = & V_72 -> V_9 ;
V_72 -> V_88 = V_177 -> V_88 ;
V_72 -> V_89 = V_177 -> V_89 ;
V_72 -> V_185 = V_177 -> V_185 ;
V_72 -> V_138 = NULL ;
memcpy ( V_72 -> V_93 , V_177 -> V_93 , sizeof( V_72 -> V_93 ) ) ;
V_72 -> V_73 = V_73 ;
V_167 -> V_35 = V_35 ;
V_72 -> V_94 = F_36 ( V_72 -> V_73 * sizeof( * V_72 -> V_94 ) , V_22 ) ;
if ( F_15 ( V_72 -> V_94 == NULL ) ) {
V_21 = - V_23 ;
goto V_186;
}
V_72 -> V_108 = F_36 ( V_72 -> V_73 * sizeof( * V_72 -> V_108 ) ,
V_22 ) ;
if ( F_15 ( V_72 -> V_94 == NULL ) ) {
V_21 = - V_23 ;
goto V_187;
}
V_179 = (struct V_81 T_11 * ) ( unsigned long )
V_177 -> V_188 ;
V_21 = F_94 ( V_72 -> V_94 , V_179 ,
V_72 -> V_73 * sizeof( * V_72 -> V_94 ) ) ;
if ( F_15 ( V_21 != 0 ) ) {
V_21 = - V_189 ;
goto V_190;
}
V_181 = 0 ;
V_107 = V_72 -> V_108 ;
V_109 = V_72 -> V_94 ;
V_100 = V_101 [ V_72 -> V_89 ] . V_100 ;
V_102 = V_101 [ V_72 -> V_89 ] . V_103 ;
for ( V_85 = 0 ; V_85 < V_90 ; ++ V_85 ) {
for ( V_180 = 0 ; V_180 < V_72 -> V_93 [ V_85 ] ; ++ V_180 ) {
T_4 V_191 =
( V_109 -> V_95 * V_102 + 7 ) >> 3 ;
V_107 -> V_91 = V_85 ;
V_107 -> V_117 = V_180 ;
V_107 -> V_113 = V_181 ;
V_181 += V_191 * V_109 -> V_96 *
V_109 -> V_97 * V_100 / V_102 ;
++ V_107 ;
++ V_109 ;
}
}
V_72 -> V_137 = V_181 ;
if ( V_72 -> V_185 &&
V_72 -> V_73 == 1 &&
V_72 -> V_94 [ 0 ] . V_95 == 64 &&
V_72 -> V_94 [ 0 ] . V_96 == 64 &&
V_72 -> V_89 == V_192 ) {
V_72 -> V_139 . V_140 = F_95 ( 64 * 64 * 4 , V_22 ) ;
if ( ! V_72 -> V_139 . V_140 ) {
F_29 ( L_13 ) ;
V_21 = - V_23 ;
goto V_190;
}
} else {
V_72 -> V_139 . V_140 = NULL ;
}
V_72 -> V_139 . V_193 = NULL ;
V_167 -> V_4 . V_58 = false ;
V_167 -> V_4 . V_55 = NULL ;
V_21 = F_82 ( V_12 , V_72 , F_83 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_69;
V_63 = F_2 ( & V_72 -> V_9 ) ;
V_21 = F_49 ( V_55 , & V_167 -> V_4 ,
V_177 -> V_58 , V_165 ,
& F_91 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_11 ( & V_63 ) ;
F_11 ( & V_9 ) ;
goto V_69;
}
V_178 -> V_80 = V_167 -> V_4 . V_60 . V_61 ;
if ( V_178 -> V_80 == V_194 )
F_29 ( L_14 ) ;
F_11 ( & V_9 ) ;
F_50 ( & V_65 -> V_67 ) ;
return 0 ;
V_190:
F_10 ( V_72 -> V_108 ) ;
V_187:
F_10 ( V_72 -> V_94 ) ;
V_186:
F_10 ( V_167 ) ;
V_184:
F_38 ( F_39 ( V_12 ) , V_35 ) ;
V_69:
F_50 ( & V_65 -> V_67 ) ;
return V_21 ;
}
int F_96 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
union V_195 * V_53 =
(union V_195 * ) V_49 ;
struct V_174 * V_177 = & V_53 -> V_177 ;
struct V_176 * V_178 = & V_53 -> V_178 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
struct V_71 * V_72 ;
struct V_166 * V_167 ;
struct V_81 T_11 * V_179 ;
struct V_45 * V_4 ;
int V_21 = - V_56 ;
V_4 = F_89 ( V_55 , V_177 -> V_80 ) ;
if ( F_15 ( V_4 == NULL ) ) {
F_29 ( L_15 ) ;
return - V_56 ;
}
if ( F_15 ( V_4 -> V_172 != V_165 ) )
goto V_173;
V_167 = F_1 ( V_4 , struct V_166 , V_4 ) ;
V_72 = & V_167 -> V_72 ;
V_21 = F_97 ( V_55 , & V_167 -> V_4 , V_62 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_29 ( L_16 ) ;
goto V_196;
}
V_178 -> V_88 = V_72 -> V_88 ;
V_178 -> V_89 = V_72 -> V_89 ;
memcpy ( V_178 -> V_93 , V_72 -> V_93 , sizeof( V_72 -> V_93 ) ) ;
V_179 = (struct V_81 T_11 * ) ( unsigned long )
V_178 -> V_188 ;
if ( V_179 )
V_21 = F_98 ( V_179 , V_72 -> V_94 ,
V_72 -> V_73 * sizeof( * V_72 -> V_94 ) ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_29 ( L_17 ,
V_179 , V_72 -> V_73 ) ;
V_21 = - V_189 ;
}
V_173:
V_196:
F_90 ( & V_4 ) ;
return V_21 ;
}
int F_99 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
T_4 V_169 , int * V_14 )
{
struct V_45 * V_4 ;
struct V_166 * V_167 ;
int V_21 = - V_59 ;
V_4 = F_89 ( V_55 , V_169 ) ;
if ( F_15 ( V_4 == NULL ) )
return - V_56 ;
if ( F_15 ( V_4 -> V_172 != V_165 ) )
goto V_197;
V_167 = F_1 ( V_4 , struct V_166 , V_4 ) ;
* V_14 = V_167 -> V_72 . V_9 . V_14 ;
V_21 = 0 ;
V_197:
F_90 ( & V_4 ) ;
return V_21 ;
}
void F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_10 ( V_6 ) ;
}
int F_101 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_12 V_35 , struct V_198 * V_199 ,
bool V_200 ,
void (* F_102) ( struct V_2 * V_3 ) )
{
struct V_201 * V_159 = & V_12 -> V_159 ;
T_12 V_202 ;
int V_21 ;
F_14 ( ! F_102 ) ;
V_202 = F_103 ( V_159 , V_35 , sizeof( struct V_1 ) ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_20 ( & V_6 -> V_203 ) ;
V_21 = F_104 ( V_159 , & V_6 -> V_4 , V_35 ,
V_160 , V_199 ,
0 , 0 , V_200 ,
NULL , V_202 , F_102 ) ;
return V_21 ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_5 * V_204 = V_5 ( V_3 ) ;
F_10 ( V_204 ) ;
}
static void F_106 ( struct V_45 * * V_46 )
{
struct V_5 * V_204 ;
struct V_45 * V_4 = * V_46 ;
struct V_2 * V_3 ;
* V_46 = NULL ;
if ( F_15 ( V_4 == NULL ) )
return;
V_204 = F_1 ( V_4 , struct V_5 , V_4 ) ;
V_3 = & V_204 -> V_7 . V_4 ;
F_62 ( & V_3 ) ;
}
int F_107 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
union V_205 * V_53 =
(union V_205 * ) V_49 ;
struct V_206 * V_177 = & V_53 -> V_177 ;
struct V_207 * V_178 = & V_53 -> V_178 ;
struct V_5 * V_204 ;
struct V_2 * V_63 ;
struct V_64 * V_65 = V_64 ( V_51 -> V_66 ) ;
int V_21 ;
V_204 = F_95 ( sizeof( * V_204 ) , V_22 ) ;
if ( F_15 ( V_204 == NULL ) )
return - V_23 ;
V_21 = F_47 ( & V_65 -> V_67 , true ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_10 ( V_204 ) ;
return V_21 ;
}
V_21 = F_101 ( V_12 , & V_204 -> V_7 , V_177 -> V_35 ,
& V_208 , true ,
& F_105 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_209;
V_63 = F_64 ( & V_204 -> V_7 . V_4 ) ;
V_21 = F_49 ( F_43 ( V_51 ) -> V_55 ,
& V_204 -> V_4 ,
false ,
V_210 ,
& F_106 , NULL ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_211;
else {
V_178 -> V_169 = V_204 -> V_4 . V_60 . V_61 ;
V_178 -> V_212 = V_204 -> V_7 . V_4 . V_213 ;
V_178 -> V_214 = V_204 -> V_4 . V_60 . V_61 ;
V_178 -> V_215 = 0 ;
}
V_211:
F_62 ( & V_63 ) ;
V_209:
F_50 ( & V_65 -> V_67 ) ;
return V_21 ;
}
int F_108 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_216 * V_53 =
(struct V_216 * ) V_49 ;
return F_44 ( F_43 ( V_51 ) -> V_55 ,
V_53 -> V_169 ,
V_62 ) ;
}
T_4 F_109 ( struct V_2 * V_3 ,
T_4 V_217 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
if ( F_9 ( V_6 -> V_218 ) )
return V_6 -> V_217 ;
V_6 -> V_217 = V_217 ;
V_6 -> V_218 = true ;
return V_217 ;
}
void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
V_6 -> V_218 = false ;
}
int F_88 ( struct V_54 * V_55 ,
T_4 V_169 , struct V_1 * * V_57 )
{
struct V_5 * V_204 ;
struct V_45 * V_4 ;
V_4 = F_89 ( V_55 , V_169 ) ;
if ( F_15 ( V_4 == NULL ) ) {
F_111 ( V_219 L_18 ,
( unsigned long ) V_169 ) ;
return - V_220 ;
}
if ( F_15 ( V_4 -> V_172 != V_210 ) ) {
F_90 ( & V_4 ) ;
F_111 ( V_219 L_18 ,
( unsigned long ) V_169 ) ;
return - V_56 ;
}
V_204 = F_1 ( V_4 , struct V_5 , V_4 ) ;
( void ) F_64 ( & V_204 -> V_7 . V_4 ) ;
F_90 ( & V_4 ) ;
* V_57 = & V_204 -> V_7 ;
return 0 ;
}
static void F_112 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_221 * V_222 ;
int V_21 ;
F_113 ( L_19 , V_223 ) ;
V_222 = F_1 ( V_9 , struct V_221 , V_9 ) ;
V_21 = F_114 ( V_12 , V_222 -> V_224 ) ;
F_115 ( V_21 != 0 ) ;
}
static int F_116 ( struct V_11 * V_12 ,
struct V_221 * V_222 ,
void (* V_19) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_222 -> V_9 ;
int V_21 ;
V_21 = F_18 ( V_12 , V_9 , & V_12 -> V_225 ,
V_226 , false , V_19 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
if ( V_19 == NULL )
F_10 ( V_222 ) ;
else
V_19 ( & V_222 -> V_9 ) ;
return V_21 ;
}
V_21 = F_117 ( V_12 , & V_222 -> V_224 ) ;
if ( V_21 ) {
F_11 ( & V_9 ) ;
return V_21 ;
}
F_113 ( L_20 , V_223 ) ;
F_21 ( & V_222 -> V_9 , F_112 ) ;
return 0 ;
}
static void F_118 ( struct V_8 * V_9 )
{
struct V_227 * V_222 =
F_1 ( V_9 , struct V_227 , V_222 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_10 ( V_222 ) ;
F_38 ( F_39 ( V_12 ) ,
V_228 ) ;
}
static void F_119 ( struct V_45 * * V_46 )
{
struct V_45 * V_4 = * V_46 ;
struct V_227 * V_222 =
F_1 ( V_4 , struct V_227 , V_4 ) ;
struct V_8 * V_9 = & V_222 -> V_222 . V_9 ;
* V_46 = NULL ;
F_11 ( & V_9 ) ;
}
int F_120 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
struct V_8 * V_9 ;
struct V_227 * V_222 ;
struct V_229 * V_53 = (struct V_229 * ) V_49 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
int V_21 = 0 ;
V_9 = F_22 ( V_12 , & V_12 -> V_225 , V_53 -> V_224 ) ;
if ( F_15 ( V_9 == NULL ) )
return - V_56 ;
if ( V_9 -> V_19 != & F_118 ) {
V_21 = - V_56 ;
goto V_57;
}
V_222 = F_1 ( V_9 , struct V_227 , V_222 . V_9 ) ;
if ( V_222 -> V_4 . V_55 != V_55 ) {
V_21 = - V_56 ;
goto V_57;
}
F_44 ( V_55 , V_222 -> V_4 . V_60 . V_61 , V_62 ) ;
V_57:
F_11 ( & V_9 ) ;
return V_21 ;
}
int F_121 ( struct V_47 * V_48 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 = F_42 ( V_48 ) ;
struct V_227 * V_222 ;
struct V_8 * V_9 ;
struct V_8 * V_63 ;
struct V_229 * V_53 = (struct V_229 * ) V_49 ;
struct V_54 * V_55 = F_43 ( V_51 ) -> V_55 ;
struct V_64 * V_65 = V_64 ( V_51 -> V_66 ) ;
int V_21 ;
if ( F_15 ( V_228 == 0 ) )
V_228 = F_46 ( sizeof( * V_222 ) ) + 128 ;
V_21 = F_47 ( & V_65 -> V_67 , true ) ;
if ( F_15 ( V_21 != 0 ) )
return V_21 ;
V_21 = F_48 ( F_39 ( V_12 ) ,
V_228 ,
false , true ) ;
if ( F_15 ( V_21 != 0 ) ) {
if ( V_21 != - V_68 )
F_29 ( L_21
L_7 ) ;
goto V_69;
}
V_222 = F_36 ( sizeof( * V_222 ) , V_22 ) ;
if ( F_15 ( V_222 == NULL ) ) {
F_38 ( F_39 ( V_12 ) ,
V_228 ) ;
V_21 = - V_23 ;
goto V_69;
}
V_9 = & V_222 -> V_222 . V_9 ;
V_222 -> V_4 . V_58 = false ;
V_222 -> V_4 . V_55 = NULL ;
V_21 = F_116 ( V_12 , & V_222 -> V_222 , F_118 ) ;
if ( F_15 ( V_21 != 0 ) )
goto V_69;
V_63 = F_2 ( V_9 ) ;
V_21 = F_49 ( V_55 , & V_222 -> V_4 , false , V_226 ,
& F_119 , NULL ) ;
if ( F_15 ( V_21 != 0 ) ) {
F_11 ( & V_63 ) ;
goto V_70;
}
V_53 -> V_224 = V_9 -> V_14 ;
V_70:
F_11 ( & V_9 ) ;
V_69:
F_50 ( & V_65 -> V_67 ) ;
return V_21 ;
}
int F_122 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
T_4 * V_230 , struct V_8 * * V_57 )
{
struct V_227 * V_222 ;
struct V_8 * V_9 ;
int V_21 ;
V_9 = F_22 ( V_12 , & V_12 -> V_225 , * V_230 ) ;
if ( F_15 ( V_9 == NULL ) )
return - V_56 ;
if ( V_9 -> V_19 != & F_118 ) {
V_21 = - V_56 ;
goto V_231;
}
V_222 = F_1 ( V_9 , struct V_227 , V_222 . V_9 ) ;
if ( V_222 -> V_4 . V_55 != V_55 ) {
V_21 = - V_59 ;
goto V_231;
}
* V_230 = V_222 -> V_222 . V_224 ;
* V_57 = V_9 ;
return 0 ;
V_231:
F_11 ( & V_9 ) ;
return V_21 ;
}
