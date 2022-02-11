static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != V_2 ) ;
F_2 ( sizeof( struct V_3 ) != V_4 ) ;
F_2 ( sizeof( struct V_5 ) != V_6 ) ;
}
static const char * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 ) ? L_1 : L_2 ;
}
static int F_5 ( struct V_9 * V_10 ,
void * V_11 , struct V_12 * V_13 )
{
struct V_7 * V_8 ;
struct V_14 V_15 [] = {
F_6 ( V_16 , 8 ) ,
F_6 ( V_17 , 16 ) ,
F_6 ( V_18 , 32 ) ,
F_6 ( V_19 , 4 ) ,
F_6 ( V_20 , 64 ) ,
F_6 ( V_21 , 64 ) ,
F_6 ( V_22 , 8 ) ,
F_6 ( V_23 , 8 ) ,
F_6 ( V_24 , 8 ) ,
F_6 ( V_25 , 6 ) ,
F_6 ( V_26 , 20 ) ,
} ;
void * V_27 = NULL , * V_28 ;
int V_29 = F_7 ( V_15 ) , V_30 = 0 ;
int V_31 ;
V_8 = F_8 ( V_10 , V_32 ) ;
if ( ! V_8 )
return - V_33 ;
F_9 ( V_8 , & V_34 ) ;
F_10 ( V_8 , V_15 , F_7 ( V_15 ) ) ;
V_31 = F_11 ( V_8 , 0 , V_11 , NULL ) ;
if ( V_31 )
goto V_35;
V_31 = F_12 ( V_8 ) ;
if ( V_31 ) {
F_13 ( L_3 , F_3 ( V_8 ) , V_31 ) ;
goto V_35;
}
F_14 ( V_8 , V_15 , & V_29 , & V_27 ) ;
F_15 ( L_4 ,
F_3 ( V_8 ) ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_5 ,
( char * ) V_28 ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_6 ,
( char * ) V_28 ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_7 ,
( char * ) V_28 ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_8 ,
V_28 ? F_16 ( V_28 ) : ~ 0U ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_9 ,
( char * ) V_28 ) ;
V_13 -> V_37 = V_15 [ V_30 ] . V_38 ;
V_13 -> V_39 = F_17 ( V_13 -> V_37 + 1 , V_32 ) ;
if ( ! V_13 -> V_39 ) {
V_31 = - V_33 ;
goto V_35;
}
if ( V_13 -> V_37 )
memcpy ( V_13 -> V_39 , V_15 [ V_30 ] . V_36 , V_13 -> V_37 ) ;
F_15 ( L_10 , V_13 -> V_39 ) ;
V_30 ++ ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_11 ,
V_28 ? F_18 ( F_19 ( V_28 ) ) : ~ 0ULL ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_12 ,
V_28 ? F_18 ( F_19 ( V_28 ) ) : ~ 0ULL ) ;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_13 ,
V_28 ? F_18 ( F_19 ( V_28 ) ) : ~ 0ULL ) ;
if ( V_30 >= V_29 )
goto V_35;
V_28 = V_15 [ V_30 ++ ] . V_36 ;
F_15 ( L_14 , V_28 ) ;
if ( V_30 < V_29 ) {
unsigned V_38 = V_15 [ V_30 ] . V_38 ;
char V_40 [ 32 * 4 + 2 ] ;
F_20 ( V_15 [ V_30 ] . V_36 , V_38 , 32 , 1 ,
V_40 , sizeof( V_40 ) , true ) ;
F_15 ( L_15
L_16 , V_38 , V_40 ) ;
if ( F_21 ( V_38 > sizeof( V_13 -> V_41 ) ) ) {
F_13 ( L_17
L_18 , V_38 ) ;
V_38 = sizeof( V_13 -> V_41 ) ;
}
V_13 -> V_42 = V_38 ;
memcpy ( V_13 -> V_41 , V_15 [ V_30 ] . V_36 , V_38 ) ;
V_30 ++ ;
}
V_35:
F_22 ( V_8 ) ;
return V_31 ;
}
int F_23 ( struct V_9 * V_10 ,
void * V_11 , struct V_12 * V_13 )
{
int V_31 ;
V_31 = F_5 ( V_10 , V_11 , V_13 ) ;
if ( V_31 ) {
F_24 ( V_10 , V_43 ) ;
F_25 ( L_19 ) ;
V_31 = F_5 ( V_10 , V_11 , V_13 ) ;
}
return V_31 ;
}
static unsigned F_26 ( struct V_7 * V_8 )
{
return F_4 ( V_8 ) ? V_6 : V_4 ;
}
static unsigned F_27 ( struct V_7 * V_8 , unsigned V_38 )
{
return F_4 ( V_8 ) ?
F_28 ( V_38 ) :
F_29 ( V_38 ) ;
}
static void F_30 ( struct V_7 * V_8 ,
void * V_44 , const struct V_14 * V_45 )
{
if ( F_4 ( V_8 ) ) {
struct V_46 * V_47 = V_44 ;
V_47 -> V_48 = F_31 ( V_45 -> V_48 ) ;
V_47 -> V_49 = F_31 ( V_45 -> V_49 ) ;
V_47 -> V_50 = F_32 ( V_45 -> V_38 ) ;
memcpy ( V_47 -> V_51 , V_45 -> V_36 , V_45 -> V_38 ) ;
} else {
struct V_52 * V_47 = V_44 ;
V_47 -> V_48 = F_31 ( V_45 -> V_48 ) ;
V_47 -> V_49 = F_31 ( V_45 -> V_49 ) ;
V_47 -> V_50 = F_32 ( V_45 -> V_38 ) ;
memcpy ( V_47 -> V_51 , V_45 -> V_36 , V_45 -> V_38 ) ;
}
}
static int F_33 ( struct V_7 * V_8 ,
void * V_53 , struct V_14 * V_45 , unsigned V_54 )
{
unsigned V_55 ;
if ( F_4 ( V_8 ) ) {
struct V_46 * V_47 = V_53 ;
if ( V_54 < sizeof( * V_47 ) )
return - 1 ;
V_45 -> V_38 = F_34 ( V_47 -> V_50 ) ;
V_55 = F_27 ( V_8 , V_45 -> V_38 ) ;
if ( V_55 > V_54 )
return - 1 ;
V_45 -> V_48 = F_35 ( V_47 -> V_48 ) ;
V_45 -> V_49 = F_35 ( V_47 -> V_49 ) ;
V_45 -> V_36 = F_36 ( V_45 -> V_38 ) ? V_47 -> V_51 :
( V_56 * ) & V_47 -> V_50 ;
} else {
struct V_52 * V_47 = V_53 ;
if ( V_54 < sizeof( * V_47 ) )
return - 1 ;
V_45 -> V_38 = F_34 ( V_47 -> V_50 ) ;
V_55 = F_27 ( V_8 , V_45 -> V_38 ) ;
if ( V_55 > V_54 )
return - 1 ;
V_45 -> V_48 = F_35 ( V_47 -> V_48 ) ;
V_45 -> V_49 = F_35 ( V_47 -> V_49 ) ;
V_45 -> V_36 = F_36 ( V_45 -> V_38 ) ? V_47 -> V_51 : V_47 -> V_57 ;
}
return V_55 ;
}
static unsigned F_37 ( struct V_7 * V_8 , void * V_58 )
{
return F_4 ( V_8 ) ?
F_38 ( V_58 ) :
F_39 ( V_58 ) ;
}
static unsigned F_40 ( struct V_7 * V_8 )
{
return F_4 ( V_8 ) ?
sizeof( struct V_59 ) :
sizeof( struct V_60 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
void * V_61 , int V_62 )
{
if ( F_4 ( V_8 ) ) {
struct V_59 * V_63 = V_61 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_62 ;
} else {
struct V_60 * V_63 = V_61 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_62 ;
}
}
static bool F_42 ( struct V_7 * V_8 ,
void * V_61 , int V_62 )
{
if ( ! V_61 )
return false ;
if ( F_4 ( V_8 ) ) {
struct V_59 * V_63 = V_61 ;
return V_63 -> type == V_62 ;
} else {
struct V_60 * V_63 = V_61 ;
return V_63 -> type == V_62 ;
}
}
static void F_43 ( struct V_7 * V_8 ,
struct V_64 * V_61 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
if ( F_4 ( V_8 ) ) {
V_66 -> V_68 . V_69 = V_61 -> V_69 ;
V_66 -> V_68 . V_70 = V_61 -> V_71 ;
} else {
V_66 -> V_72 . V_69 = V_61 -> V_69 ;
V_66 -> V_72 . V_70 = V_61 -> V_71 ;
}
}
static T_1 F_44 ( struct V_7 * V_8 ,
T_2 V_73 , unsigned * V_74 )
{
return F_45 ( V_73 , V_74 ,
F_4 ( V_8 ) ?
V_75 : V_76 ,
V_77 ) ;
}
static struct V_78 *
F_46 ( struct V_7 * V_8 )
{
struct V_79 * V_80 = & V_8 -> V_67 ;
if ( F_4 ( V_8 ) )
return (struct V_78 * ) & V_80 -> V_68 . V_81 ;
else
return (struct V_78 * ) & V_80 -> V_72 . V_81 ;
}
void F_47 ( struct V_9 * V_82 , struct V_83 * V_83 )
{
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_83 = V_83 ;
V_82 -> V_84 = V_85 ;
#ifdef F_48
V_82 -> V_86 = V_87 ;
#endif
}
void F_49 ( struct V_9 * V_82 )
{
V_82 -> V_83 = NULL ;
}
static struct V_7 * F_50 ( T_3 V_88 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( sizeof( * V_8 ) , V_88 ) ;
return V_8 ;
}
static void F_51 ( struct V_7 * V_8 )
{
F_52 ( V_8 ) ;
}
struct V_7 * F_8 ( struct V_9 * V_89 , T_3 V_88 )
{
struct V_7 * V_8 ;
V_8 = F_50 ( V_88 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_9 = V_89 ;
V_8 -> V_90 = V_88 ;
V_8 -> V_91 = V_89 -> V_84 ;
V_8 -> V_92 = V_93 ;
return V_8 ;
}
static void F_53 ( struct V_7 * V_8 V_94 ,
struct V_95 * V_96 )
{
if ( ! V_96 -> V_97 || ! V_96 -> V_98 )
return;
F_52 ( V_96 -> V_97 ) ;
V_96 -> V_97 = NULL ;
V_96 -> V_98 = 0 ;
}
static void F_54 ( struct V_99 * V_100 )
{
if ( F_21 ( V_100 -> V_101 ) )
F_55 ( V_100 , - V_33 , F_56 ( V_100 ) ) ;
else
F_57 ( V_100 ) ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_99 * V_100 = V_8 -> V_99 ;
if ( V_100 ) {
if ( V_100 -> V_102 ) {
F_54 ( V_100 -> V_102 ) ;
V_100 -> V_102 = NULL ;
}
F_54 ( V_100 ) ;
}
F_53 ( V_8 , & V_8 -> V_103 ) ;
F_53 ( V_8 , & V_8 -> V_104 ) ;
F_53 ( V_8 , & V_8 -> V_105 ) ;
F_53 ( V_8 , & V_8 -> V_106 ) ;
F_51 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 , struct V_99 * V_107 ,
int error )
{
V_8 -> V_108 = error ;
V_8 -> V_109 = V_107 -> V_110 ? : error ;
V_8 -> V_111 = F_59 ( V_107 ) -> V_111 ;
if ( V_8 -> V_111 )
memcpy ( V_8 -> V_112 , F_59 ( V_107 ) -> V_112 , V_8 -> V_111 ) ;
if ( V_8 -> V_35 . V_107 )
V_8 -> V_35 . V_113 = F_59 ( V_8 -> V_35 . V_107 ) -> V_114 ;
if ( V_8 -> V_115 . V_107 )
V_8 -> V_115 . V_113 = F_59 ( V_8 -> V_115 . V_107 ) -> V_114 ;
}
int F_12 ( struct V_7 * V_8 )
{
int error = F_60 ( V_8 -> V_99 -> V_116 , NULL , V_8 -> V_99 , 0 ) ;
F_58 ( V_8 , V_8 -> V_99 , error ) ;
return error ;
}
static void F_61 ( struct V_99 * V_107 , int error )
{
struct V_7 * V_8 = V_107 -> V_117 ;
F_58 ( V_8 , V_107 , error ) ;
if ( V_107 -> V_102 ) {
F_62 ( V_107 -> V_116 , V_107 -> V_102 ) ;
V_107 -> V_102 = NULL ;
}
F_62 ( V_107 -> V_116 , V_107 ) ;
V_8 -> V_99 = NULL ;
V_8 -> V_115 . V_107 = NULL ;
V_8 -> V_35 . V_107 = NULL ;
if ( V_8 -> V_118 )
V_8 -> V_118 ( V_8 , V_8 -> V_119 ) ;
else
F_22 ( V_8 ) ;
}
int F_63 ( struct V_7 * V_8 ,
T_4 * V_120 , void * V_121 )
{
V_8 -> V_99 -> V_117 = V_8 ;
V_8 -> V_119 = V_121 ;
V_8 -> V_118 = V_120 ;
F_64 ( V_8 -> V_99 -> V_116 , NULL , V_8 -> V_99 , 0 ,
F_61 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_8 ,
struct V_95 * V_96 , unsigned V_54 )
{
void * V_97 ;
if ( V_96 -> V_98 >= V_54 )
return 0 ;
V_97 = F_66 ( V_96 -> V_97 , V_54 , V_8 -> V_90 ) ;
if ( ! V_97 ) {
F_13 ( L_20 , V_54 ,
V_96 -> V_98 ) ;
return - V_33 ;
}
memset ( V_97 + V_96 -> V_98 , 0 , V_54 - V_96 -> V_98 ) ;
V_96 -> V_97 = V_97 ;
V_96 -> V_98 = V_54 ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , unsigned V_122 )
{
F_25 ( L_21 , V_122 ) ;
return F_65 ( V_8 , & V_8 -> V_106 , V_122 ) ;
}
static int F_68 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 , unsigned V_123 )
{
unsigned V_122 = V_123 ;
for (; V_29 ; -- V_29 , ++ V_45 )
V_122 += F_27 ( V_8 , V_45 -> V_38 ) ;
F_25 ( L_21 , V_122 ) ;
return F_65 ( V_8 , & V_8 -> V_105 , V_122 ) ;
}
static int F_69 ( struct V_7 * V_8 , unsigned V_54 )
{
F_25 ( L_21 , V_54 ) ;
return F_65 ( V_8 , & V_8 -> V_104 , V_54 ) ;
}
static int F_70 ( struct V_7 * V_8 )
{
F_25 ( L_21 , V_8 -> V_103 . V_122 ) ;
return F_65 ( V_8 , & V_8 -> V_103 , V_8 -> V_103 . V_122 ) ;
}
static void F_71 ( struct V_7 * V_8 ,
T_5 V_124 , const struct V_125 * V_126 , T_2 V_73 , T_2 V_38 )
{
struct V_5 * V_80 = & V_8 -> V_67 . V_68 ;
V_124 &= F_32 ( ~ 0x0080 ) ;
F_25 ( L_22 , F_34 ( V_124 ) ) ;
V_80 -> V_127 . V_128 . V_129 = V_130 ;
V_80 -> V_127 . V_128 . V_131 = V_132 ;
V_80 -> V_127 . V_128 . V_133 = V_124 ;
V_80 -> V_127 . V_134 = F_72 ( V_126 -> V_134 ) ;
V_80 -> V_127 . V_135 = F_72 ( V_126 -> V_136 ) ;
V_80 -> V_127 . V_68 . V_137 = F_72 ( V_38 ) ;
V_80 -> V_127 . V_68 . V_70 = F_72 ( V_73 ) ;
}
static void F_73 ( struct V_7 * V_8 ,
T_5 V_124 , const struct V_125 * V_126 , T_2 V_73 , T_2 V_38 )
{
struct V_3 * V_80 = & V_8 -> V_67 . V_72 ;
F_25 ( L_23 , F_34 ( V_124 ) ) ;
V_80 -> V_127 . V_128 . V_129 = V_130 ;
V_80 -> V_127 . V_128 . V_131 = V_132 ;
V_80 -> V_127 . V_128 . V_133 = V_124 ;
V_80 -> V_127 . V_134 = F_72 ( V_126 -> V_134 ) ;
V_80 -> V_127 . V_135 = F_72 ( V_126 -> V_136 ) ;
V_80 -> V_127 . V_72 . V_137 = F_72 ( V_38 ) ;
V_80 -> V_127 . V_72 . V_70 = F_72 ( V_73 ) ;
}
static void F_74 ( struct V_7 * V_8 ,
T_5 V_124 , const struct V_125 * V_126 , T_2 V_73 , T_2 V_38 )
{
if ( F_4 ( V_8 ) )
F_71 ( V_8 , V_124 , V_126 , V_73 , V_38 ) ;
else
F_73 ( V_8 , V_124 , V_126 , V_73 , V_38 ) ;
}
void F_75 ( struct V_7 * V_8 , T_2 V_138 )
{
F_74 ( V_8 , V_139 , & V_34 , 0 ,
V_138 ) ;
}
int F_76 ( struct V_7 * V_8 ,
T_6 V_140 , struct V_64 * V_61 , unsigned V_29 )
{
return F_77 ( V_8 , 0 , V_140 , V_61 , V_29 ) ;
}
static void F_78 ( struct V_7 * V_8 ,
enum V_141 V_142 )
{
struct V_65 * V_80 = V_65 ( & V_8 -> V_67 ) ;
V_80 -> V_143 = V_142 ;
}
void F_79 ( struct V_7 * V_8 ,
enum V_141 V_142 )
{
F_74 ( V_8 , V_144 , & V_34 , 0 , 0 ) ;
F_78 ( V_8 , V_142 ) ;
}
static void F_80 ( struct V_7 * V_8 ,
T_5 V_124 , T_6 V_134 )
{
struct V_125 V_145 = {
. V_134 = V_134 ,
. V_136 = 0 ,
} ;
F_74 ( V_8 , V_124 , & V_145 , 0 , 0 ) ;
}
void F_81 ( struct V_7 * V_8 , T_6 V_134 )
{
F_80 ( V_8 , V_146 , V_134 ) ;
}
void F_82 ( struct V_7 * V_8 , T_6 V_134 )
{
F_80 ( V_8 , V_147 , V_134 ) ;
}
static int F_83 ( struct V_7 * V_8 ,
T_5 V_148 , const struct V_125 * V_126 , T_6 V_140 ,
struct V_64 * V_61 , unsigned V_29 )
{
struct V_149 * V_116 = F_84 ( V_8 -> V_9 ) ;
T_2 V_38 = V_29 * sizeof( T_6 ) + sizeof( * V_61 ) ;
struct V_101 * V_101 ;
F_74 ( V_8 , V_148 , V_126 , ( T_2 ) V_140 , V_38 ) ;
if ( V_61 -> V_69 )
F_43 ( V_8 , V_61 ) ;
F_85 ( V_8 -> V_115 . V_101 ) ;
V_101 = F_86 ( V_116 , V_61 , V_38 , V_8 -> V_90 ) ;
if ( F_87 ( V_101 ) ) {
F_13 ( L_24 ) ;
return F_88 ( V_101 ) ;
}
F_89 ( V_101 , V_150 , 0 ) ;
V_8 -> V_115 . V_101 = V_101 ;
V_8 -> V_115 . V_122 = V_101 -> V_151 . V_152 ;
return 0 ;
}
int F_90 ( struct V_7 * V_8 ,
T_6 V_134 , T_6 V_140 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_125 V_145 = {
. V_134 = V_134 ,
. V_136 = 0 ,
} ;
return F_91 ( V_8 , & V_145 , V_140 , V_61 ,
V_29 ) ;
}
int F_77 ( struct V_7 * V_8 ,
T_6 V_134 , T_6 V_140 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_125 V_145 = {
. V_134 = V_134 ,
. V_136 = 0 ,
} ;
return F_83 ( V_8 , V_153 , & V_145 , V_140 , V_61 ,
V_29 ) ;
}
void F_92 ( struct V_7 * V_8 ,
T_6 V_134 , enum V_141 V_142 )
{
F_80 ( V_8 , V_154 , V_134 ) ;
F_78 ( V_8 , V_142 ) ;
}
int F_91 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , T_6 V_140 ,
struct V_64 * V_61 , unsigned V_29 )
{
return F_83 ( V_8 , V_155 , V_126 ,
V_140 , V_61 , V_29 ) ;
}
void F_93 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , enum V_141 V_142 )
{
F_74 ( V_8 , V_154 , V_126 , 0 , 0 ) ;
F_78 ( V_8 , V_142 ) ;
}
void F_94 ( struct V_7 * V_8 , struct V_125 * V_126 )
{
F_74 ( V_8 , V_156 , V_126 , 0 , 0 ) ;
}
void F_95 ( struct V_7 * V_8 , struct V_125 * V_126 )
{
F_74 ( V_8 , V_157 , V_126 , 0 , 0 ) ;
}
void F_96 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_158 , V_126 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_35 . V_101 || V_8 -> V_35 . V_122 ) ;
F_85 ( ! F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_122 = V_38 ;
}
int F_99 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_149 * V_159 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_159 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_160 , 0 ) ;
F_96 ( V_8 , V_126 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
void F_100 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , enum V_141 V_142 ,
T_2 V_73 , T_2 V_38 )
{
if ( F_21 ( F_4 ( V_8 ) && ( V_73 || V_38 ) ) ) {
F_25 ( L_25 ) ;
V_73 = 0 ;
V_38 = 0 ;
}
F_74 ( V_8 , V_161 , V_126 , V_73 , V_38 ) ;
F_78 ( V_8 , V_142 ) ;
}
void F_101 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_162 , V_126 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_115 . V_101 || V_8 -> V_115 . V_122 ) ;
F_85 ( F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_115 . V_101 = V_101 ;
V_8 -> V_115 . V_122 = V_38 ;
}
int F_102 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_149 * V_159 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_159 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_101 ( V_8 , V_126 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
static int F_103 ( struct V_7 * V_8 ,
const struct V_163 * V_164 , unsigned V_165 , T_2 * V_38 )
{
struct V_166 * V_167 ;
T_7 V_168 ;
unsigned V_169 ;
int V_31 ;
V_168 = sizeof( * V_167 ) + V_165 * sizeof( V_167 -> V_170 [ 0 ] ) ;
if ( ! V_8 -> V_106 . V_122 ) {
V_8 -> V_106 . V_122 =
sizeof( struct V_171 ) ;
}
V_31 = F_67 ( V_8 , V_8 -> V_106 . V_122 + V_168 ) ;
if ( F_21 ( V_31 ) )
return V_31 ;
V_167 = V_8 -> V_106 . V_97 + V_8 -> V_106 . V_122 ;
V_167 -> V_172 . type = F_32 ( V_173 ) ;
V_167 -> V_172 . V_174 = 0 ;
V_167 -> V_172 . V_137 = F_31 ( V_168 - sizeof( * V_167 ) ) ;
* V_38 = 0 ;
for ( V_169 = 0 ; V_169 < V_165 ; V_169 ++ ) {
V_167 -> V_170 [ V_169 ] . V_73 = F_72 ( V_164 [ V_169 ] . V_73 ) ;
V_167 -> V_170 [ V_169 ] . V_38 = F_72 ( V_164 [ V_169 ] . V_38 ) ;
* V_38 += V_164 [ V_169 ] . V_38 ;
}
V_8 -> V_106 . V_122 += V_168 ;
F_25 ( L_26 ,
V_8 -> V_106 . V_122 , V_168 , V_165 ) ;
return 0 ;
}
static int F_104 ( struct V_7 * V_8 , const V_56 * V_175 )
{
struct V_149 * V_159 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
struct V_171 * V_176 ;
if ( ! V_8 -> V_106 . V_122 )
return 0 ;
V_176 = V_8 -> V_106 . V_97 ;
V_176 -> V_177 = V_178 ;
V_176 -> V_133 = V_66 -> V_128 . V_133 ;
V_101 = F_86 ( V_159 , V_8 -> V_106 . V_97 , V_8 -> V_106 . V_122 ,
V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_160 , 0 ) ;
F_105 ( V_176 -> V_179 , V_101 , V_175 ) ;
V_66 -> V_72 . V_180 = F_31 ( V_8 -> V_106 . V_122 ) ;
V_101 -> V_181 = V_8 -> V_35 . V_101 ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_122 += V_8 -> V_106 . V_122 ;
return 0 ;
}
int F_106 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , struct V_101 * V_101 ,
const struct V_163 * V_164 , unsigned V_165 )
{
T_2 V_38 ;
int V_31 = F_103 ( V_8 , V_164 , V_165 , & V_38 ) ;
if ( V_31 )
return V_31 ;
F_96 ( V_8 , V_126 , 0 , V_101 , V_38 ) ;
return 0 ;
}
int F_107 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , struct V_101 * V_101 ,
const struct V_163 * V_164 , unsigned V_165 )
{
T_2 V_38 ;
T_2 V_182 ;
int V_31 ;
if ( V_165 > 1 ) {
V_182 = 0 ;
V_31 = F_103 ( V_8 , V_164 , V_165 ,
& V_38 ) ;
if ( V_31 )
return V_31 ;
} else {
V_38 = V_164 -> V_38 ;
V_182 = V_164 -> V_73 ;
}
F_101 ( V_8 , V_126 , V_182 , V_101 , V_38 ) ;
return 0 ;
}
static struct V_101 * F_108 ( struct V_7 * V_8 ,
void * * V_97 , const struct V_163 * V_164 , unsigned V_165 )
{
struct V_149 * V_116 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
unsigned V_169 ;
V_101 = F_109 ( V_32 , V_165 ) ;
if ( F_21 ( ! V_101 ) ) {
F_25 ( L_27 , V_165 ) ;
return F_110 ( - V_33 ) ;
}
for ( V_169 = 0 ; V_169 < V_165 ; V_169 ++ ) {
unsigned V_73 = F_111 ( V_97 [ V_169 ] ) ;
struct V_183 * V_183 = F_112 ( V_97 [ V_169 ] ) ;
unsigned V_38 = V_164 [ V_169 ] . V_38 ;
unsigned V_184 ;
F_113 ( V_73 + V_38 > V_185 ) ;
V_184 = F_114 ( V_116 , V_101 , V_183 , V_38 , V_73 ) ;
if ( F_21 ( V_38 != V_184 ) ) {
F_25 ( L_28 ,
V_38 , V_184 ) ;
F_115 ( V_101 ) ;
return F_110 ( - V_33 ) ;
}
}
return V_101 ;
}
int F_116 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , void * * V_97 ,
const struct V_163 * V_164 , unsigned V_165 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_164 , V_165 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_160 , 0 ) ;
F_106 ( V_8 , V_126 , V_101 , V_164 , V_165 ) ;
return 0 ;
}
int F_117 ( struct V_7 * V_8 ,
const struct V_125 * V_126 , void * * V_97 ,
const struct V_163 * V_164 , unsigned V_165 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_164 , V_165 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_107 ( V_8 , V_126 , V_101 , V_164 , V_165 ) ;
return 0 ;
}
void F_9 ( struct V_7 * V_8 ,
const struct V_125 * V_126 )
{
F_74 ( V_8 , V_186 , V_126 , 0 , 0 ) ;
}
void F_118 ( struct V_7 * V_8 ,
const struct V_125 * V_126 )
{
F_74 ( V_8 , V_187 , V_126 , 0 , 0 ) ;
}
int F_119 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_122 = V_8 -> V_105 . V_122 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_188 &&
V_8 -> V_188 != V_189 ) {
F_85 ( 1 ) ;
return - V_190 ;
}
V_8 -> V_188 = V_189 ;
if ( ! V_122 ) {
V_122 = F_40 ( V_8 ) ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_122 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_105 . V_97 ,
V_191 ) ;
}
V_44 = V_8 -> V_105 . V_97 + V_122 ;
for (; V_29 ; -- V_29 ) {
unsigned V_192 = F_27 ( V_8 , V_45 -> V_38 ) ;
V_122 += V_192 ;
if ( F_21 ( V_8 -> V_105 . V_98 < V_122 ) ) {
V_8 -> V_105 . V_122 = V_122 - V_192 ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_122 ) ;
if ( V_31 )
return V_31 ;
V_44 =
V_8 -> V_105 . V_97 + V_8 -> V_105 . V_122 ;
}
F_30 ( V_8 , V_44 , V_45 ) ;
V_44 += V_192 ;
++ V_45 ;
}
V_8 -> V_105 . V_122 = V_122 ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 ,
unsigned V_74 , struct V_95 * V_96 ,
struct V_95 * V_193 , struct V_194 * V_195 )
{
void * V_196 ;
int V_31 ;
if ( V_74 ) {
if ( V_193 &&
( V_74 <= V_193 -> V_98 - V_193 -> V_122 ) )
V_196 = V_193 -> V_97 + V_193 -> V_122 ;
else
V_196 = V_195 -> V_196 ;
V_31 = F_121 ( V_195 -> V_107 -> V_116 , V_195 -> V_107 , V_196 , V_74 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_195 -> V_122 += V_74 ;
}
V_31 = F_121 ( V_195 -> V_107 -> V_116 , V_195 -> V_107 , V_96 -> V_97 , V_96 -> V_122 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_195 -> V_122 += V_96 -> V_122 ;
F_25 ( L_29 , V_74 , V_96 -> V_97 ,
V_96 -> V_122 ) ;
return 0 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_74 ;
int V_31 ;
if ( ! V_8 -> V_105 . V_122 ) {
V_66 -> V_197 . V_198 = V_199 ;
return 0 ;
}
V_66 -> V_197 . V_200 = F_31 ( V_8 -> V_105 . V_122 ) ;
V_66 -> V_197 . V_198 =
F_44 ( V_8 , V_8 -> V_35 . V_122 , & V_74 ) ;
V_31 = F_120 ( V_8 , V_74 , & V_8 -> V_105 ,
V_8 -> V_35 . V_193 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_193 = & V_8 -> V_105 ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_122 = V_8 -> V_104 . V_122 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_188 &&
V_8 -> V_188 != V_189 ) {
F_85 ( 1 ) ;
return - V_190 ;
}
V_8 -> V_188 = V_189 ;
if ( ! V_8 -> V_103 . V_122 )
V_8 -> V_103 . V_122 = F_40 ( V_8 ) ;
if ( ! V_122 ) {
unsigned V_54 ;
V_122 = F_40 ( V_8 ) ;
V_54 = V_122 +
V_29 * sizeof( struct V_201 ) ;
V_31 = F_69 ( V_8 , V_54 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_104 . V_97 ,
V_202 ) ;
}
V_44 = V_8 -> V_104 . V_97 + V_122 ;
for (; V_29 ; -- V_29 ) {
struct V_201 * V_203 ;
const unsigned V_204 = sizeof( * V_203 ) ;
V_122 += V_204 ;
if ( F_21 ( V_8 -> V_104 . V_98 < V_122 ) ) {
V_8 -> V_104 . V_122 = V_122 - V_204 ;
V_31 = F_69 ( V_8 ,
V_122 + V_29 * sizeof( * V_203 ) ) ;
if ( V_31 )
return V_31 ;
V_44 = V_8 -> V_104 . V_97 +
V_8 -> V_104 . V_122 ;
}
V_203 = V_44 ;
V_203 -> V_48 = F_31 ( V_45 -> V_48 ) ;
V_203 -> V_49 = F_31 ( V_45 -> V_49 ) ;
V_44 += V_204 ;
V_8 -> V_103 . V_122 +=
F_27 ( V_8 , V_45 -> V_38 ) ;
++ V_45 ;
}
V_8 -> V_104 . V_122 = V_122 ;
F_25 (
L_30 ,
V_8 -> V_103 . V_122 ,
V_8 -> V_103 . V_122 - F_40 ( V_8 ) ,
V_8 -> V_104 . V_122 ,
( V_8 -> V_104 . V_122 - F_40 ( V_8 ) )
/ sizeof( struct V_201 ) ) ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_205 ;
unsigned V_206 ;
int V_31 ;
if ( ! V_8 -> V_104 . V_122 ) {
V_66 -> V_197 . V_207 = V_199 ;
V_66 -> V_197 . V_208 = V_199 ;
return 0 ;
}
V_31 = F_70 ( V_8 ) ;
if ( V_31 )
return V_31 ;
F_25 ( L_31 ) ;
V_66 -> V_197 . V_209 =
F_31 ( V_8 -> V_104 . V_122 ) ;
V_66 -> V_197 . V_207 =
F_44 ( V_8 , V_8 -> V_35 . V_122 , & V_205 ) ;
V_31 = F_120 ( V_8 , V_205 , & V_8 -> V_104 ,
V_8 -> V_35 . V_193 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_193 = & V_8 -> V_104 ;
F_25 ( L_32 ) ;
V_66 -> V_197 . V_210 =
F_31 ( V_8 -> V_103 . V_122 ) ;
V_66 -> V_197 . V_208 =
F_44 ( V_8 , V_8 -> V_115 . V_122 , & V_206 ) ;
V_31 = F_120 ( V_8 , V_206 , & V_8 -> V_103 , NULL ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_115 . V_193 = & V_8 -> V_103 ;
return 0 ;
}
int F_14 ( struct V_7 * V_8 ,
struct V_14 * V_45 , int * V_29 , void * * V_211 )
{
unsigned V_212 , V_213 ;
int V_214 ;
const unsigned V_215 = F_40 ( V_8 ) ;
void * V_53 ;
if ( ! F_42 ( V_8 , V_8 -> V_103 . V_97 ,
V_191 ) ) {
V_45 -> V_48 = 0 ;
V_45 -> V_49 = 0 ;
V_45 -> V_36 = NULL ;
V_45 -> V_38 = 0 ;
* V_211 = NULL ;
return 0 ;
}
if ( * V_211 ) {
F_113 ( ( * V_211 < V_8 -> V_103 . V_97 ) ||
( V_8 -> V_103 . V_97 + V_8 -> V_103 . V_98 < * V_211 ) ) ;
V_53 = * V_211 ;
V_212 = ( * V_211 - V_8 -> V_103 . V_97 ) - V_215 ;
V_213 = V_8 -> V_103 . V_122 ;
} else {
V_212 = V_215 ;
V_213 = F_37 ( V_8 , V_8 -> V_103 . V_97 ) +
V_215 ;
V_53 = V_8 -> V_103 . V_97 + V_215 ;
if ( V_213 > V_8 -> V_103 . V_98 ) {
F_25 ( L_33
L_34 ,
V_8 -> V_103 . V_98 ,
V_213 + V_215 ) ;
V_213 =
V_8 -> V_103 . V_98 - V_215 ;
}
V_8 -> V_103 . V_122 = V_213 ;
}
for ( V_214 = 0 ; ( V_214 < * V_29 ) && ( V_212 < V_213 ) ; ++ V_214 ) {
int V_55 = F_33 ( V_8 , V_53 , V_45 ,
V_213 - V_212 ) ;
if ( V_55 < 0 ) {
F_13 ( L_35
L_36 ,
V_212 , V_213 , V_214 ) ;
V_45 -> V_36 = NULL ;
V_212 = V_213 ;
break;
}
V_212 += V_55 ;
V_53 += V_55 ;
++ V_45 ;
}
* V_211 = ( V_213 - V_212 ) ? V_53 : NULL ;
* V_29 = V_214 ;
return V_213 - V_212 ;
}
int F_124 ( struct V_7 * V_8 ,
T_7 V_216 , void * V_217 , unsigned V_218 ,
const struct V_14 * V_219 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
if ( V_8 -> V_188 &&
V_8 -> V_188 != V_220 ) {
F_85 ( 1 ) ;
return - V_190 ;
}
V_8 -> V_188 = V_220 ;
V_8 -> V_103 . V_97 = V_217 ;
V_8 -> V_103 . V_122 = V_218 ;
V_66 -> V_221 . V_222 = F_31 ( V_216 ) ;
V_66 -> V_221 . V_210 = F_31 ( V_218 ) ;
if ( ! V_219 || ! V_219 -> V_48 )
return 0 ;
V_8 -> V_105 . V_97 = V_219 -> V_36 ;
V_8 -> V_105 . V_122 = V_219 -> V_38 ;
V_66 -> V_221 . V_223 = F_31 ( V_219 -> V_48 ) ;
V_66 -> V_221 . V_224 = F_31 ( V_219 -> V_49 ) ;
V_66 -> V_221 . V_225 = F_31 ( V_219 -> V_38 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_206 , V_205 ;
int V_31 ;
V_66 -> V_221 . V_208 =
F_44 ( V_8 , V_8 -> V_115 . V_122 , & V_206 ) ;
V_31 = F_120 ( V_8 , V_206 , & V_8 -> V_103 , NULL ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
if ( V_8 -> V_105 . V_122 == 0 )
return 0 ;
V_66 -> V_221 . V_198 =
F_44 ( V_8 , V_8 -> V_35 . V_122 , & V_205 ) ;
V_31 = F_120 ( V_8 , V_205 , & V_8 -> V_105 , NULL ,
& V_8 -> V_35 ) ;
return V_31 ;
}
static inline void F_126 ( bool V_226 ,
struct V_78 * V_227 , T_1 V_73 )
{
if ( V_226 )
V_227 -> V_68 . V_228 = V_73 ;
else
V_227 -> V_72 . V_228 = V_73 ;
}
static inline void F_127 ( bool V_226 ,
struct V_78 * V_227 , T_1 V_73 )
{
if ( V_226 )
V_227 -> V_68 . V_229 = V_73 ;
else
V_227 -> V_72 . V_229 = V_73 ;
}
static int F_128 ( struct V_7 * V_8 ,
bool V_230 , bool V_231 , struct V_101 * V_232 , T_2 V_233 ,
const V_56 * V_175 )
{
struct V_78 * V_227 = F_46 ( V_8 ) ;
int V_31 ;
if ( ! F_129 ( V_227 ) )
return 0 ;
if ( V_231 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_234 ,
. V_122 = sizeof( V_8 -> V_234 ) ,
} ;
unsigned V_235 ;
V_8 -> V_234 . V_236 = F_72 ( V_233 ) ;
V_8 -> V_234 . V_237 = F_72 (
V_8 -> V_105 . V_122 ) ;
V_8 -> V_234 . V_238 = F_72 (
V_8 -> V_104 . V_122 ) ;
F_126 ( F_4 ( V_8 ) , V_227 ,
F_44 ( V_8 , V_8 -> V_35 . V_122 , & V_235 ) ) ;
V_31 = F_120 ( V_8 , V_235 , & V_96 , V_8 -> V_35 . V_193 ,
& V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_193 = NULL ;
F_105 ( & V_8 -> V_234 , V_232 ,
V_175 ) ;
}
if ( V_230 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_239 ,
. V_122 = sizeof( V_8 -> V_239 ) ,
} ;
unsigned V_235 ;
F_127 ( F_4 ( V_8 ) , V_227 ,
F_44 ( V_8 , V_8 -> V_115 . V_122 , & V_235 ) ) ;
V_31 = F_120 ( V_8 , V_235 , & V_96 , V_8 -> V_115 . V_193 ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_115 . V_193 = NULL ;
}
return 0 ;
}
static struct V_99 * F_130 ( struct V_149 * V_116 , bool V_240 ,
struct V_194 * V_241 , T_3 V_242 )
{
struct V_99 * V_107 ;
struct V_101 * V_101 = V_241 -> V_101 ;
int V_31 ;
V_107 = F_131 ( V_116 , V_240 ? V_243 : V_244 ,
V_242 ) ;
if ( F_87 ( V_107 ) )
return V_107 ;
F_132 ( V_107 ) ;
F_133 (bio) {
struct V_101 * V_245 = V_101 ;
F_134 ( V_107 -> V_116 , & V_245 ) ;
V_31 = F_135 ( V_107 , V_245 ) ;
if ( V_31 )
return F_110 ( V_31 ) ;
}
return V_107 ;
}
static int F_136 ( struct V_7 * V_8 ,
bool V_230 , bool V_231 )
{
T_3 V_242 = V_8 -> V_90 ;
struct V_83 * V_83 = V_8 -> V_9 -> V_83 ;
struct V_149 * V_116 = V_83 -> V_149 ;
struct V_99 * V_107 ;
int V_31 ;
V_107 = F_130 ( V_116 , V_231 , V_231 ? & V_8 -> V_35 : & V_8 -> V_115 , V_242 ) ;
if ( F_87 ( V_107 ) ) {
V_31 = F_88 ( V_107 ) ;
goto V_35;
}
V_8 -> V_99 = V_107 ;
V_107 -> V_246 |= V_247 ;
V_107 -> V_91 = V_8 -> V_91 ;
V_107 -> V_92 = V_8 -> V_92 ;
if ( V_231 ) {
V_8 -> V_35 . V_107 = V_107 ;
if ( V_230 ) {
V_107 = F_130 ( V_116 , false , & V_8 -> V_115 , V_242 ) ;
if ( F_87 ( V_107 ) ) {
F_25 ( L_37 ) ;
V_31 = F_88 ( V_107 ) ;
goto V_35;
}
F_132 ( V_107 ) ;
V_8 -> V_115 . V_107 = V_8 -> V_99 -> V_102 = V_107 ;
}
} else if ( V_230 )
V_8 -> V_115 . V_107 = V_107 ;
V_31 = 0 ;
V_35:
F_25 ( L_38 ,
V_8 , V_230 , V_231 , V_31 , V_8 -> V_99 ) ;
return V_31 ;
}
int F_11 ( struct V_7 * V_8 ,
V_56 V_248 , const void * V_249 , const V_56 * V_175 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
bool V_230 , V_231 ;
struct V_101 * V_232 = V_8 -> V_35 . V_101 ;
T_2 V_233 = V_8 -> V_35 . V_122 ;
int V_31 ;
if ( V_248 & V_250 )
V_66 -> V_248 |= V_251 ;
if ( V_248 & V_252 )
V_66 -> V_248 |= V_253 ;
if ( V_248 & V_254 )
V_66 -> V_255 = V_256 ;
F_137 ( & V_8 -> V_67 , V_249 ) ;
V_230 = V_8 -> V_115 . V_101 || V_8 -> V_103 . V_122 ;
V_231 = V_8 -> V_35 . V_101 || V_8 -> V_106 . V_122 ||
V_8 -> V_105 . V_122 || V_8 -> V_104 . V_122 ;
V_31 = F_104 ( V_8 , V_175 ) ;
if ( V_31 ) {
F_25 ( L_39 ) ;
return V_31 ;
}
V_31 = F_136 ( V_8 , V_230 , V_231 ) ;
if ( V_31 ) {
F_25 ( L_40 ) ;
return V_31 ;
}
V_8 -> V_35 . V_196 = V_257 ;
V_8 -> V_115 . V_196 = V_258 ;
if ( ! V_8 -> V_188 )
V_8 -> V_188 = V_189 ;
V_66 -> V_143 |= V_8 -> V_188 ;
if ( V_8 -> V_188 == V_220 ) {
V_31 = F_125 ( V_8 ) ;
if ( V_31 ) {
F_25 ( L_41 ) ;
return V_31 ;
}
} else {
V_31 = F_122 ( V_8 ) ;
if ( V_31 ) {
F_25 ( L_42 ) ;
return V_31 ;
}
V_31 = F_123 ( V_8 ) ;
if ( V_31 ) {
F_25 ( L_43 ) ;
return V_31 ;
}
}
V_31 = F_128 ( V_8 , V_230 , V_231 ,
V_232 , V_233 ,
V_175 ) ;
if ( V_31 )
return V_31 ;
F_138 ( & V_8 -> V_67 , V_175 ) ;
F_59 ( V_8 -> V_99 ) -> V_259 = V_8 -> V_67 . V_97 ;
F_59 ( V_8 -> V_99 ) -> V_260 = F_26 ( V_8 ) ;
return 0 ;
}
static bool F_139 ( int V_261 )
{
return ( V_261 == V_262 ) ||
( V_261 == V_263 ) ||
( V_261 == V_264 ) ||
( V_261 == V_265 ) ||
( V_261 == V_266 ) ;
}
int F_140 ( struct V_7 * V_8 ,
struct V_267 * V_268 , bool V_269 ,
struct V_125 * T_8 V_94 , int T_9 V_94 ,
struct V_14 * V_270 , int V_271 )
{
int V_111 , V_272 ;
struct V_267 V_273 ;
struct V_274 * V_275 ;
void * V_276 ;
#if ( V_277 == 0 )
const bool V_278 = false ;
#else
bool V_278 = ! V_269 ;
#endif
int V_31 ;
if ( F_36 ( ! V_8 -> V_109 ) )
return 0 ;
V_268 = V_268 ? : & V_273 ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
V_275 = ( F_141 ( V_275 ) ) V_8 -> V_112 ;
V_111 = V_8 -> V_111 ;
if ( ( V_111 < ( int ) sizeof( * V_275 ) || ! V_275 -> V_279 ) ) {
F_13 ( L_44
L_45 ,
V_8 -> V_109 , V_111 , V_275 -> V_279 ) ;
goto V_280;
}
if ( ( V_275 -> V_281 != 0x72 ) && ( V_275 -> V_281 != 0x73 ) ) {
F_13 ( L_46 ,
V_275 -> V_281 , V_111 ) ;
goto V_280;
}
V_268 -> V_282 = V_275 -> V_279 ;
V_268 -> V_283 = F_34 ( V_275 -> V_284 ) ;
V_272 = V_275 -> V_285 + 8 ;
#if ( V_277 == 1 )
if ( V_278 )
V_278 = ( V_268 -> V_282 > V_286 ) ;
#endif
F_142 ( L_47
L_48 ,
V_268 -> V_282 , V_272 , V_111 ,
V_268 -> V_283 , V_8 -> V_108 ,
V_8 -> V_109 ) ;
if ( V_272 < V_111 )
V_111 = V_272 ;
V_276 = V_275 -> V_287 ;
V_111 -= sizeof( * V_275 ) ;
while ( V_111 > 0 ) {
struct V_288 * V_287 = V_276 ;
int V_289 = V_287 -> V_290 + 2 ;
V_111 -= V_289 ;
if ( V_111 < 0 )
break;
switch ( V_287 -> V_291 ) {
case V_292 :
case V_293 :
{
struct V_294
* V_295 = V_276 ;
V_268 -> V_296 =
F_19 ( & V_295 -> V_297 ) ;
F_143 (
L_49 ,
F_18 ( V_268 -> V_296 ) ) ;
break;
}
case V_298 :
{
struct V_299
* V_300 = V_276 ;
V_268 -> V_301 = F_144 ( & V_300 -> V_302 ) ;
F_143 (
L_50
L_51 ,
V_268 -> V_301 , V_300 -> V_303 ) ;
break;
}
case V_304 :
{
struct V_305
* V_306 = V_276 ;
V_268 -> V_307 =
F_145 ( V_306 -> V_308 ) ;
V_268 -> V_309 =
F_145 ( V_306 -> V_310 ) ;
V_268 -> V_126 . V_134 = F_146 ( V_306 -> V_311 ) ;
V_268 -> V_126 . V_136 = F_146 ( V_306 -> V_312 ) ;
F_143 (
L_52 ,
F_18 ( V_268 -> V_126 . V_134 ) , F_18 ( V_268 -> V_126 . V_136 ) ) ;
F_143 (
L_53
L_54 ,
V_268 -> V_307 ,
V_268 -> V_309 ) ;
break;
}
case V_313 :
{
struct V_314
* V_315 = V_276 ;
const unsigned V_38 =
sizeof( V_315 -> V_316 ) ;
char V_317 [ V_38 * 4 + 2 ] ;
F_20 ( V_315 -> V_316 , V_38 ,
32 , 1 , V_317 , sizeof( V_317 ) , true ) ;
F_143 ( L_55 , V_317 ) ;
}
case V_318 :
{
struct V_319
* V_320 = V_276 ;
unsigned V_38 = F_147 ( V_289 , V_111 ) ;
struct V_321 * V_322 = V_320 -> V_323 ;
while ( V_38 >= sizeof( * V_322 ) ) {
T_7 V_48 = F_35 ( V_322 -> V_48 ) ;
T_7 V_49 = F_35 ( V_322 -> V_49 ) ;
if ( ! V_268 -> V_47 . V_48 ) {
V_268 -> V_47 . V_48 = V_48 ;
V_268 -> V_47 . V_49 = V_49 ;
}
if ( V_270 && V_271 ) {
V_270 -> V_48 = V_48 ;
V_270 -> V_49 = V_49 ;
V_270 ++ ;
V_271 -- ;
}
V_38 -= sizeof( * V_322 ) ;
F_143 (
L_56
L_57 ,
V_48 , V_49 ) ;
}
}
case V_324 :
F_143 ( L_58 ) ;
break;
case V_325 :
F_143 ( L_59 ) ;
break;
case V_326 :
F_143 ( L_60 ) ;
break;
case V_327 :
F_143 ( L_61 ) ;
break;
default:
if ( V_287 -> V_291 <= V_328 )
F_143 (
L_62 ,
V_287 -> V_291 ) ;
else
F_143 (
L_63 ,
V_287 -> V_291 ) ;
}
V_276 += V_289 ;
}
V_280:
if ( ! V_268 -> V_282 ) {
if ( V_8 -> V_108 == - V_33 )
V_268 -> V_329 = V_330 ;
else
V_268 -> V_329 = V_331 ;
V_31 = V_8 -> V_108 ;
} else if ( V_268 -> V_282 <= V_286 ) {
V_268 -> V_329 = 0 ;
V_31 = 0 ;
} else if ( V_268 -> V_283 == V_332 ) {
if ( V_268 -> V_333 == V_334 ) {
V_268 -> V_329 = V_335 ;
V_31 = - V_336 ;
} else if ( V_268 -> V_333 == V_337 ) {
V_268 -> V_329 = V_338 ;
V_31 = - V_339 ;
} else if ( V_268 -> V_333 == V_340 ) {
V_268 -> V_329 = V_341 ;
V_31 = - V_342 ;
} else {
V_268 -> V_329 = V_343 ;
V_31 = - V_190 ;
}
} else if ( V_268 -> V_283 == V_344 ) {
V_268 -> V_329 = V_345 ;
V_31 = - V_346 ;
} else if ( F_139 ( V_268 -> V_283 ) ) {
V_268 -> V_329 = V_343 ;
V_31 = - V_190 ;
} else {
V_268 -> V_329 = V_347 ;
V_31 = - V_348 ;
}
if ( ! V_8 -> V_35 . V_113 )
V_8 -> V_35 . V_113 = V_8 -> V_35 . V_122 ;
if ( ! V_8 -> V_115 . V_113 )
V_8 -> V_115 . V_113 = V_8 -> V_115 . V_122 ;
return V_31 ;
}
void F_148 ( void * V_11 ,
const struct V_125 * V_126 , bool V_349 , const bool V_226 )
{
struct V_1 * V_249 = V_11 ;
V_56 type ;
V_56 V_291 ;
if ( F_36 ( V_126 -> V_136 ) ) {
if ( F_21 ( V_349 ) ) {
type = V_350 ;
V_291 = V_226 ? V_351 :
V_352 ;
} else {
type = V_353 ;
V_291 = V_351 ;
}
F_85 ( ! V_126 -> V_134 ) ;
} else {
type = V_126 -> V_134 ? V_354 :
V_355 ;
V_291 = V_356 ;
}
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_249 -> V_127 . V_177 = V_357 ;
V_249 -> V_127 . V_358 = 0 ;
V_249 -> V_127 . V_359 = V_360 ;
V_249 -> V_127 . V_361 = type ;
F_149 ( & V_249 -> V_127 , V_362 ) ;
V_249 -> V_127 . V_363 = V_291 ;
V_249 -> V_10 . V_364 . V_365 = 0 ;
V_249 -> V_10 . V_364 . V_366 = F_72 ( V_126 -> V_134 ) ;
V_249 -> V_10 . V_364 . V_367 = F_72 ( V_126 -> V_136 ) ;
}
void F_137 ( struct V_79 * V_67 , const void * V_11 )
{
memcpy ( & V_67 -> V_68 . V_11 , V_11 , V_368 ) ;
}
bool F_129 ( struct V_78 * V_227 V_94 )
{
return false ;
}
void F_138 ( struct V_79 * V_80 V_94 , const V_56 * V_175 V_94 )
{
}
void F_105 ( void * T_10 V_94 ,
struct V_101 * V_101 V_94 , const V_56 * V_175 V_94 )
{
}
T_1 F_45 (
T_2 V_73 , unsigned * V_74 , int V_369 , int V_370 )
{
T_2 V_371 = - 1 , V_372 , V_373 ;
T_1 V_374 ;
int V_375 ;
* V_74 = 0 ;
if ( ! V_73 )
return 0 ;
for ( V_375 = V_369 ; V_375 < V_370 ; ++ V_375 ) {
V_371 = V_73 >> V_375 ;
if ( V_371 < ( 1 << V_376 ) )
break;
}
F_113 ( V_375 == V_370 ) ;
V_373 = 1 << V_375 ;
V_372 = V_73 & ( V_373 - 1 ) ;
if ( V_372 ) {
* V_74 = V_373 - V_372 ;
V_371 += 1 ;
}
V_371 |= ( ( V_375 - 8 ) & 0xf ) << 28 ;
V_374 = F_31 ( ( T_7 ) V_371 ) ;
F_25 ( L_64 ,
F_18 ( V_73 ) , F_18 ( V_371 & 0x0FFFFFFF ) , V_375 ,
V_374 , * V_74 ) ;
return V_374 ;
}
