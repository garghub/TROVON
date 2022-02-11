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
V_8 -> V_109 = F_59 ( V_107 ) -> V_110 ? : error ;
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
int error ;
F_60 ( V_8 -> V_99 -> V_116 , NULL , V_8 -> V_99 , 0 ) ;
error = F_59 ( V_8 -> V_99 ) -> V_110 ? - V_117 : 0 ;
F_58 ( V_8 , V_8 -> V_99 , error ) ;
return error ;
}
static void F_61 ( struct V_99 * V_107 , int error )
{
struct V_7 * V_8 = V_107 -> V_118 ;
F_58 ( V_8 , V_107 , error ) ;
if ( V_107 -> V_102 ) {
F_62 ( V_107 -> V_116 , V_107 -> V_102 ) ;
V_107 -> V_102 = NULL ;
}
F_62 ( V_107 -> V_116 , V_107 ) ;
V_8 -> V_99 = NULL ;
V_8 -> V_115 . V_107 = NULL ;
V_8 -> V_35 . V_107 = NULL ;
if ( V_8 -> V_119 )
V_8 -> V_119 ( V_8 , V_8 -> V_120 ) ;
else
F_22 ( V_8 ) ;
}
int F_63 ( struct V_7 * V_8 ,
T_4 * V_121 , void * V_122 )
{
V_8 -> V_99 -> V_118 = V_8 ;
V_8 -> V_120 = V_122 ;
V_8 -> V_119 = V_121 ;
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
static int F_67 ( struct V_7 * V_8 , unsigned V_123 )
{
F_25 ( L_21 , V_123 ) ;
return F_65 ( V_8 , & V_8 -> V_106 , V_123 ) ;
}
static int F_68 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 , unsigned V_124 )
{
unsigned V_123 = V_124 ;
for (; V_29 ; -- V_29 , ++ V_45 )
V_123 += F_27 ( V_8 , V_45 -> V_38 ) ;
F_25 ( L_21 , V_123 ) ;
return F_65 ( V_8 , & V_8 -> V_105 , V_123 ) ;
}
static int F_69 ( struct V_7 * V_8 , unsigned V_54 )
{
F_25 ( L_21 , V_54 ) ;
return F_65 ( V_8 , & V_8 -> V_104 , V_54 ) ;
}
static int F_70 ( struct V_7 * V_8 )
{
F_25 ( L_21 , V_8 -> V_103 . V_123 ) ;
return F_65 ( V_8 , & V_8 -> V_103 , V_8 -> V_103 . V_123 ) ;
}
static void F_71 ( struct V_7 * V_8 ,
T_5 V_125 , const struct V_126 * V_127 , T_2 V_73 , T_2 V_38 )
{
struct V_5 * V_80 = & V_8 -> V_67 . V_68 ;
V_125 &= F_32 ( ~ 0x0080 ) ;
F_25 ( L_22 , F_34 ( V_125 ) ) ;
V_80 -> V_128 . V_129 . V_130 = V_131 ;
V_80 -> V_128 . V_129 . V_132 = V_133 ;
V_80 -> V_128 . V_129 . V_134 = V_125 ;
V_80 -> V_128 . V_135 = F_72 ( V_127 -> V_135 ) ;
V_80 -> V_128 . V_136 = F_72 ( V_127 -> V_137 ) ;
V_80 -> V_128 . V_68 . V_138 = F_72 ( V_38 ) ;
V_80 -> V_128 . V_68 . V_70 = F_72 ( V_73 ) ;
}
static void F_73 ( struct V_7 * V_8 ,
T_5 V_125 , const struct V_126 * V_127 , T_2 V_73 , T_2 V_38 )
{
struct V_3 * V_80 = & V_8 -> V_67 . V_72 ;
F_25 ( L_23 , F_34 ( V_125 ) ) ;
V_80 -> V_128 . V_129 . V_130 = V_131 ;
V_80 -> V_128 . V_129 . V_132 = V_133 ;
V_80 -> V_128 . V_129 . V_134 = V_125 ;
V_80 -> V_128 . V_135 = F_72 ( V_127 -> V_135 ) ;
V_80 -> V_128 . V_136 = F_72 ( V_127 -> V_137 ) ;
V_80 -> V_128 . V_72 . V_138 = F_72 ( V_38 ) ;
V_80 -> V_128 . V_72 . V_70 = F_72 ( V_73 ) ;
}
static void F_74 ( struct V_7 * V_8 ,
T_5 V_125 , const struct V_126 * V_127 , T_2 V_73 , T_2 V_38 )
{
if ( F_4 ( V_8 ) )
F_71 ( V_8 , V_125 , V_127 , V_73 , V_38 ) ;
else
F_73 ( V_8 , V_125 , V_127 , V_73 , V_38 ) ;
}
void F_75 ( struct V_7 * V_8 , T_2 V_139 )
{
F_74 ( V_8 , V_140 , & V_34 , 0 ,
V_139 ) ;
}
int F_76 ( struct V_7 * V_8 ,
T_6 V_141 , struct V_64 * V_61 , unsigned V_29 )
{
return F_77 ( V_8 , 0 , V_141 , V_61 , V_29 ) ;
}
static void F_78 ( struct V_7 * V_8 ,
enum V_142 V_143 )
{
struct V_65 * V_80 = V_65 ( & V_8 -> V_67 ) ;
V_80 -> V_144 = V_143 ;
}
void F_79 ( struct V_7 * V_8 ,
enum V_142 V_143 )
{
F_74 ( V_8 , V_145 , & V_34 , 0 , 0 ) ;
F_78 ( V_8 , V_143 ) ;
}
static void F_80 ( struct V_7 * V_8 ,
T_5 V_125 , T_6 V_135 )
{
struct V_126 V_146 = {
. V_135 = V_135 ,
. V_137 = 0 ,
} ;
F_74 ( V_8 , V_125 , & V_146 , 0 , 0 ) ;
}
void F_81 ( struct V_7 * V_8 , T_6 V_135 )
{
F_80 ( V_8 , V_147 , V_135 ) ;
}
void F_82 ( struct V_7 * V_8 , T_6 V_135 )
{
F_80 ( V_8 , V_148 , V_135 ) ;
}
static int F_83 ( struct V_7 * V_8 ,
T_5 V_149 , const struct V_126 * V_127 , T_6 V_141 ,
struct V_64 * V_61 , unsigned V_29 )
{
struct V_150 * V_116 = F_84 ( V_8 -> V_9 ) ;
T_2 V_38 = V_29 * sizeof( T_6 ) + sizeof( * V_61 ) ;
struct V_101 * V_101 ;
F_74 ( V_8 , V_149 , V_127 , ( T_2 ) V_141 , V_38 ) ;
if ( V_61 -> V_69 )
F_43 ( V_8 , V_61 ) ;
F_85 ( V_8 -> V_115 . V_101 ) ;
V_101 = F_86 ( V_116 , V_61 , V_38 , V_8 -> V_90 ) ;
if ( F_87 ( V_101 ) ) {
F_13 ( L_24 ) ;
return F_88 ( V_101 ) ;
}
F_89 ( V_101 , V_151 , 0 ) ;
V_8 -> V_115 . V_101 = V_101 ;
V_8 -> V_115 . V_123 = V_101 -> V_152 . V_153 ;
return 0 ;
}
int F_90 ( struct V_7 * V_8 ,
T_6 V_135 , T_6 V_141 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_126 V_146 = {
. V_135 = V_135 ,
. V_137 = 0 ,
} ;
return F_91 ( V_8 , & V_146 , V_141 , V_61 ,
V_29 ) ;
}
int F_77 ( struct V_7 * V_8 ,
T_6 V_135 , T_6 V_141 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_126 V_146 = {
. V_135 = V_135 ,
. V_137 = 0 ,
} ;
return F_83 ( V_8 , V_154 , & V_146 , V_141 , V_61 ,
V_29 ) ;
}
void F_92 ( struct V_7 * V_8 ,
T_6 V_135 , enum V_142 V_143 )
{
F_80 ( V_8 , V_155 , V_135 ) ;
F_78 ( V_8 , V_143 ) ;
}
int F_91 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , T_6 V_141 ,
struct V_64 * V_61 , unsigned V_29 )
{
return F_83 ( V_8 , V_156 , V_127 ,
V_141 , V_61 , V_29 ) ;
}
void F_93 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , enum V_142 V_143 )
{
F_74 ( V_8 , V_155 , V_127 , 0 , 0 ) ;
F_78 ( V_8 , V_143 ) ;
}
void F_94 ( struct V_7 * V_8 , struct V_126 * V_127 )
{
F_74 ( V_8 , V_157 , V_127 , 0 , 0 ) ;
}
void F_95 ( struct V_7 * V_8 , struct V_126 * V_127 )
{
F_74 ( V_8 , V_158 , V_127 , 0 , 0 ) ;
}
void F_96 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_159 , V_127 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_35 . V_101 || V_8 -> V_35 . V_123 ) ;
F_85 ( ! F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_123 = V_38 ;
}
int F_99 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_150 * V_160 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_160 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_161 , 0 ) ;
F_96 ( V_8 , V_127 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
void F_100 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , enum V_142 V_143 ,
T_2 V_73 , T_2 V_38 )
{
if ( F_21 ( F_4 ( V_8 ) && ( V_73 || V_38 ) ) ) {
F_25 ( L_25 ) ;
V_73 = 0 ;
V_38 = 0 ;
}
F_74 ( V_8 , V_162 , V_127 , V_73 , V_38 ) ;
F_78 ( V_8 , V_143 ) ;
}
void F_101 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_163 , V_127 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_115 . V_101 || V_8 -> V_115 . V_123 ) ;
F_85 ( F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_115 . V_101 = V_101 ;
V_8 -> V_115 . V_123 = V_38 ;
}
int F_102 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_150 * V_160 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_160 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_101 ( V_8 , V_127 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
static int F_103 ( struct V_7 * V_8 ,
const struct V_164 * V_165 , unsigned V_166 , T_2 * V_38 )
{
struct V_167 * V_168 ;
T_7 V_169 ;
unsigned V_170 ;
int V_31 ;
V_169 = sizeof( * V_168 ) + V_166 * sizeof( V_168 -> V_171 [ 0 ] ) ;
if ( ! V_8 -> V_106 . V_123 ) {
V_8 -> V_106 . V_123 =
sizeof( struct V_172 ) ;
}
V_31 = F_67 ( V_8 , V_8 -> V_106 . V_123 + V_169 ) ;
if ( F_21 ( V_31 ) )
return V_31 ;
V_168 = V_8 -> V_106 . V_97 + V_8 -> V_106 . V_123 ;
V_168 -> V_173 . type = F_32 ( V_174 ) ;
V_168 -> V_173 . V_175 = 0 ;
V_168 -> V_173 . V_138 = F_31 ( V_169 - sizeof( * V_168 ) ) ;
* V_38 = 0 ;
for ( V_170 = 0 ; V_170 < V_166 ; V_170 ++ ) {
V_168 -> V_171 [ V_170 ] . V_73 = F_72 ( V_165 [ V_170 ] . V_73 ) ;
V_168 -> V_171 [ V_170 ] . V_38 = F_72 ( V_165 [ V_170 ] . V_38 ) ;
* V_38 += V_165 [ V_170 ] . V_38 ;
}
V_8 -> V_106 . V_123 += V_169 ;
F_25 ( L_26 ,
V_8 -> V_106 . V_123 , V_169 , V_166 ) ;
return 0 ;
}
static int F_104 ( struct V_7 * V_8 , const V_56 * V_176 )
{
struct V_150 * V_160 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
struct V_172 * V_177 ;
if ( ! V_8 -> V_106 . V_123 )
return 0 ;
V_177 = V_8 -> V_106 . V_97 ;
V_177 -> V_178 = V_179 ;
V_177 -> V_134 = V_66 -> V_129 . V_134 ;
V_101 = F_86 ( V_160 , V_8 -> V_106 . V_97 , V_8 -> V_106 . V_123 ,
V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_161 , 0 ) ;
F_105 ( V_177 -> V_180 , V_101 , V_176 ) ;
V_66 -> V_72 . V_181 = F_31 ( V_8 -> V_106 . V_123 ) ;
V_101 -> V_182 = V_8 -> V_35 . V_101 ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_123 += V_8 -> V_106 . V_123 ;
return 0 ;
}
int F_106 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , struct V_101 * V_101 ,
const struct V_164 * V_165 , unsigned V_166 )
{
T_2 V_38 ;
int V_31 = F_103 ( V_8 , V_165 , V_166 , & V_38 ) ;
if ( V_31 )
return V_31 ;
F_96 ( V_8 , V_127 , 0 , V_101 , V_38 ) ;
return 0 ;
}
int F_107 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , struct V_101 * V_101 ,
const struct V_164 * V_165 , unsigned V_166 )
{
T_2 V_38 ;
T_2 V_183 ;
int V_31 ;
if ( V_166 > 1 ) {
V_183 = 0 ;
V_31 = F_103 ( V_8 , V_165 , V_166 ,
& V_38 ) ;
if ( V_31 )
return V_31 ;
} else {
V_38 = V_165 -> V_38 ;
V_183 = V_165 -> V_73 ;
}
F_101 ( V_8 , V_127 , V_183 , V_101 , V_38 ) ;
return 0 ;
}
static struct V_101 * F_108 ( struct V_7 * V_8 ,
void * * V_97 , const struct V_164 * V_165 , unsigned V_166 )
{
struct V_150 * V_116 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
unsigned V_170 ;
V_101 = F_109 ( V_32 , V_166 ) ;
if ( F_21 ( ! V_101 ) ) {
F_25 ( L_27 , V_166 ) ;
return F_110 ( - V_33 ) ;
}
for ( V_170 = 0 ; V_170 < V_166 ; V_170 ++ ) {
unsigned V_73 = F_111 ( V_97 [ V_170 ] ) ;
struct V_184 * V_184 = F_112 ( V_97 [ V_170 ] ) ;
unsigned V_38 = V_165 [ V_170 ] . V_38 ;
unsigned V_185 ;
F_113 ( V_73 + V_38 > V_186 ) ;
V_185 = F_114 ( V_116 , V_101 , V_184 , V_38 , V_73 ) ;
if ( F_21 ( V_38 != V_185 ) ) {
F_25 ( L_28 ,
V_38 , V_185 ) ;
F_115 ( V_101 ) ;
return F_110 ( - V_33 ) ;
}
}
return V_101 ;
}
int F_116 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , void * * V_97 ,
const struct V_164 * V_165 , unsigned V_166 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_165 , V_166 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_161 , 0 ) ;
F_106 ( V_8 , V_127 , V_101 , V_165 , V_166 ) ;
return 0 ;
}
int F_117 ( struct V_7 * V_8 ,
const struct V_126 * V_127 , void * * V_97 ,
const struct V_164 * V_165 , unsigned V_166 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_165 , V_166 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_107 ( V_8 , V_127 , V_101 , V_165 , V_166 ) ;
return 0 ;
}
void F_9 ( struct V_7 * V_8 ,
const struct V_126 * V_127 )
{
F_74 ( V_8 , V_187 , V_127 , 0 , 0 ) ;
}
void F_118 ( struct V_7 * V_8 ,
const struct V_126 * V_127 )
{
F_74 ( V_8 , V_188 , V_127 , 0 , 0 ) ;
}
int F_119 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_123 = V_8 -> V_105 . V_123 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_189 &&
V_8 -> V_189 != V_190 ) {
F_85 ( 1 ) ;
return - V_191 ;
}
V_8 -> V_189 = V_190 ;
if ( ! V_123 ) {
V_123 = F_40 ( V_8 ) ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_123 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_105 . V_97 ,
V_192 ) ;
}
V_44 = V_8 -> V_105 . V_97 + V_123 ;
for (; V_29 ; -- V_29 ) {
unsigned V_193 = F_27 ( V_8 , V_45 -> V_38 ) ;
V_123 += V_193 ;
if ( F_21 ( V_8 -> V_105 . V_98 < V_123 ) ) {
V_8 -> V_105 . V_123 = V_123 - V_193 ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_123 ) ;
if ( V_31 )
return V_31 ;
V_44 =
V_8 -> V_105 . V_97 + V_8 -> V_105 . V_123 ;
}
F_30 ( V_8 , V_44 , V_45 ) ;
V_44 += V_193 ;
++ V_45 ;
}
V_8 -> V_105 . V_123 = V_123 ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 ,
unsigned V_74 , struct V_95 * V_96 ,
struct V_95 * V_194 , struct V_195 * V_196 )
{
void * V_197 ;
int V_31 ;
if ( V_74 ) {
if ( V_194 &&
( V_74 <= V_194 -> V_98 - V_194 -> V_123 ) )
V_197 = V_194 -> V_97 + V_194 -> V_123 ;
else
V_197 = V_196 -> V_197 ;
V_31 = F_121 ( V_196 -> V_107 -> V_116 , V_196 -> V_107 , V_197 , V_74 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_196 -> V_123 += V_74 ;
}
V_31 = F_121 ( V_196 -> V_107 -> V_116 , V_196 -> V_107 , V_96 -> V_97 , V_96 -> V_123 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_196 -> V_123 += V_96 -> V_123 ;
F_25 ( L_29 , V_74 , V_96 -> V_97 ,
V_96 -> V_123 ) ;
return 0 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_74 ;
int V_31 ;
if ( ! V_8 -> V_105 . V_123 ) {
V_66 -> V_198 . V_199 = V_200 ;
return 0 ;
}
V_66 -> V_198 . V_201 = F_31 ( V_8 -> V_105 . V_123 ) ;
V_66 -> V_198 . V_199 =
F_44 ( V_8 , V_8 -> V_35 . V_123 , & V_74 ) ;
V_31 = F_120 ( V_8 , V_74 , & V_8 -> V_105 ,
V_8 -> V_35 . V_194 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_194 = & V_8 -> V_105 ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_123 = V_8 -> V_104 . V_123 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_189 &&
V_8 -> V_189 != V_190 ) {
F_85 ( 1 ) ;
return - V_191 ;
}
V_8 -> V_189 = V_190 ;
if ( ! V_8 -> V_103 . V_123 )
V_8 -> V_103 . V_123 = F_40 ( V_8 ) ;
if ( ! V_123 ) {
unsigned V_54 ;
V_123 = F_40 ( V_8 ) ;
V_54 = V_123 +
V_29 * sizeof( struct V_202 ) ;
V_31 = F_69 ( V_8 , V_54 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_104 . V_97 ,
V_203 ) ;
}
V_44 = V_8 -> V_104 . V_97 + V_123 ;
for (; V_29 ; -- V_29 ) {
struct V_202 * V_204 ;
const unsigned V_205 = sizeof( * V_204 ) ;
V_123 += V_205 ;
if ( F_21 ( V_8 -> V_104 . V_98 < V_123 ) ) {
V_8 -> V_104 . V_123 = V_123 - V_205 ;
V_31 = F_69 ( V_8 ,
V_123 + V_29 * sizeof( * V_204 ) ) ;
if ( V_31 )
return V_31 ;
V_44 = V_8 -> V_104 . V_97 +
V_8 -> V_104 . V_123 ;
}
V_204 = V_44 ;
V_204 -> V_48 = F_31 ( V_45 -> V_48 ) ;
V_204 -> V_49 = F_31 ( V_45 -> V_49 ) ;
V_44 += V_205 ;
V_8 -> V_103 . V_123 +=
F_27 ( V_8 , V_45 -> V_38 ) ;
++ V_45 ;
}
V_8 -> V_104 . V_123 = V_123 ;
F_25 (
L_30 ,
V_8 -> V_103 . V_123 ,
V_8 -> V_103 . V_123 - F_40 ( V_8 ) ,
V_8 -> V_104 . V_123 ,
( V_8 -> V_104 . V_123 - F_40 ( V_8 ) )
/ sizeof( struct V_202 ) ) ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_206 ;
unsigned V_207 ;
int V_31 ;
if ( ! V_8 -> V_104 . V_123 ) {
V_66 -> V_198 . V_208 = V_200 ;
V_66 -> V_198 . V_209 = V_200 ;
return 0 ;
}
V_31 = F_70 ( V_8 ) ;
if ( V_31 )
return V_31 ;
F_25 ( L_31 ) ;
V_66 -> V_198 . V_210 =
F_31 ( V_8 -> V_104 . V_123 ) ;
V_66 -> V_198 . V_208 =
F_44 ( V_8 , V_8 -> V_35 . V_123 , & V_206 ) ;
V_31 = F_120 ( V_8 , V_206 , & V_8 -> V_104 ,
V_8 -> V_35 . V_194 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_194 = & V_8 -> V_104 ;
F_25 ( L_32 ) ;
V_66 -> V_198 . V_211 =
F_31 ( V_8 -> V_103 . V_123 ) ;
V_66 -> V_198 . V_209 =
F_44 ( V_8 , V_8 -> V_115 . V_123 , & V_207 ) ;
V_31 = F_120 ( V_8 , V_207 , & V_8 -> V_103 , NULL ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_115 . V_194 = & V_8 -> V_103 ;
return 0 ;
}
int F_14 ( struct V_7 * V_8 ,
struct V_14 * V_45 , int * V_29 , void * * V_212 )
{
unsigned V_213 , V_214 ;
int V_215 ;
const unsigned V_216 = F_40 ( V_8 ) ;
void * V_53 ;
if ( ! F_42 ( V_8 , V_8 -> V_103 . V_97 ,
V_192 ) ) {
V_45 -> V_48 = 0 ;
V_45 -> V_49 = 0 ;
V_45 -> V_36 = NULL ;
V_45 -> V_38 = 0 ;
* V_212 = NULL ;
return 0 ;
}
if ( * V_212 ) {
F_113 ( ( * V_212 < V_8 -> V_103 . V_97 ) ||
( V_8 -> V_103 . V_97 + V_8 -> V_103 . V_98 < * V_212 ) ) ;
V_53 = * V_212 ;
V_213 = ( * V_212 - V_8 -> V_103 . V_97 ) - V_216 ;
V_214 = V_8 -> V_103 . V_123 ;
} else {
V_213 = V_216 ;
V_214 = F_37 ( V_8 , V_8 -> V_103 . V_97 ) +
V_216 ;
V_53 = V_8 -> V_103 . V_97 + V_216 ;
if ( V_214 > V_8 -> V_103 . V_98 ) {
F_25 ( L_33
L_34 ,
V_8 -> V_103 . V_98 ,
V_214 + V_216 ) ;
V_214 =
V_8 -> V_103 . V_98 - V_216 ;
}
V_8 -> V_103 . V_123 = V_214 ;
}
for ( V_215 = 0 ; ( V_215 < * V_29 ) && ( V_213 < V_214 ) ; ++ V_215 ) {
int V_55 = F_33 ( V_8 , V_53 , V_45 ,
V_214 - V_213 ) ;
if ( V_55 < 0 ) {
F_13 ( L_35
L_36 ,
V_213 , V_214 , V_215 ) ;
V_45 -> V_36 = NULL ;
V_213 = V_214 ;
break;
}
V_213 += V_55 ;
V_53 += V_55 ;
++ V_45 ;
}
* V_212 = ( V_214 - V_213 ) ? V_53 : NULL ;
* V_29 = V_215 ;
return V_214 - V_213 ;
}
int F_124 ( struct V_7 * V_8 ,
T_7 V_217 , void * V_218 , unsigned V_219 ,
const struct V_14 * V_220 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
if ( V_8 -> V_189 &&
V_8 -> V_189 != V_221 ) {
F_85 ( 1 ) ;
return - V_191 ;
}
V_8 -> V_189 = V_221 ;
V_8 -> V_103 . V_97 = V_218 ;
V_8 -> V_103 . V_123 = V_219 ;
V_66 -> V_222 . V_223 = F_31 ( V_217 ) ;
V_66 -> V_222 . V_211 = F_31 ( V_219 ) ;
if ( ! V_220 || ! V_220 -> V_48 )
return 0 ;
V_8 -> V_105 . V_97 = V_220 -> V_36 ;
V_8 -> V_105 . V_123 = V_220 -> V_38 ;
V_66 -> V_222 . V_224 = F_31 ( V_220 -> V_48 ) ;
V_66 -> V_222 . V_225 = F_31 ( V_220 -> V_49 ) ;
V_66 -> V_222 . V_226 = F_31 ( V_220 -> V_38 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_207 , V_206 ;
int V_31 ;
V_66 -> V_222 . V_209 =
F_44 ( V_8 , V_8 -> V_115 . V_123 , & V_207 ) ;
V_31 = F_120 ( V_8 , V_207 , & V_8 -> V_103 , NULL ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
if ( V_8 -> V_105 . V_123 == 0 )
return 0 ;
V_66 -> V_222 . V_199 =
F_44 ( V_8 , V_8 -> V_35 . V_123 , & V_206 ) ;
V_31 = F_120 ( V_8 , V_206 , & V_8 -> V_105 , NULL ,
& V_8 -> V_35 ) ;
return V_31 ;
}
static inline void F_126 ( bool V_227 ,
struct V_78 * V_228 , T_1 V_73 )
{
if ( V_227 )
V_228 -> V_68 . V_229 = V_73 ;
else
V_228 -> V_72 . V_229 = V_73 ;
}
static inline void F_127 ( bool V_227 ,
struct V_78 * V_228 , T_1 V_73 )
{
if ( V_227 )
V_228 -> V_68 . V_230 = V_73 ;
else
V_228 -> V_72 . V_230 = V_73 ;
}
static int F_128 ( struct V_7 * V_8 ,
bool V_231 , bool V_232 , struct V_101 * V_233 , T_2 V_234 ,
const V_56 * V_176 )
{
struct V_78 * V_228 = F_46 ( V_8 ) ;
int V_31 ;
if ( ! F_129 ( V_228 ) )
return 0 ;
if ( V_232 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_235 ,
. V_123 = sizeof( V_8 -> V_235 ) ,
} ;
unsigned V_236 ;
V_8 -> V_235 . V_237 = F_72 ( V_234 ) ;
V_8 -> V_235 . V_238 = F_72 (
V_8 -> V_105 . V_123 ) ;
V_8 -> V_235 . V_239 = F_72 (
V_8 -> V_104 . V_123 ) ;
F_126 ( F_4 ( V_8 ) , V_228 ,
F_44 ( V_8 , V_8 -> V_35 . V_123 , & V_236 ) ) ;
V_31 = F_120 ( V_8 , V_236 , & V_96 , V_8 -> V_35 . V_194 ,
& V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_194 = NULL ;
F_105 ( & V_8 -> V_235 , V_233 ,
V_176 ) ;
}
if ( V_231 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_240 ,
. V_123 = sizeof( V_8 -> V_240 ) ,
} ;
unsigned V_236 ;
F_127 ( F_4 ( V_8 ) , V_228 ,
F_44 ( V_8 , V_8 -> V_115 . V_123 , & V_236 ) ) ;
V_31 = F_120 ( V_8 , V_236 , & V_96 , V_8 -> V_115 . V_194 ,
& V_8 -> V_115 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_115 . V_194 = NULL ;
}
return 0 ;
}
static struct V_99 * F_130 ( struct V_150 * V_116 , bool V_241 ,
struct V_195 * V_242 , T_3 V_243 )
{
struct V_99 * V_107 ;
struct V_101 * V_101 = V_242 -> V_101 ;
int V_31 ;
V_107 = F_131 ( V_116 , V_241 ? V_244 : V_245 ,
V_243 ) ;
if ( F_87 ( V_107 ) )
return V_107 ;
F_132 ( V_107 ) ;
F_133 (bio) {
struct V_101 * V_246 = V_101 ;
F_134 ( V_107 -> V_116 , & V_246 ) ;
V_31 = F_135 ( V_107 , V_246 ) ;
if ( V_31 )
return F_110 ( V_31 ) ;
}
return V_107 ;
}
static int F_136 ( struct V_7 * V_8 ,
bool V_231 , bool V_232 )
{
T_3 V_243 = V_8 -> V_90 ;
struct V_83 * V_83 = V_8 -> V_9 -> V_83 ;
struct V_150 * V_116 = V_83 -> V_150 ;
struct V_99 * V_107 ;
int V_31 ;
V_107 = F_130 ( V_116 , V_232 , V_232 ? & V_8 -> V_35 : & V_8 -> V_115 , V_243 ) ;
if ( F_87 ( V_107 ) ) {
V_31 = F_88 ( V_107 ) ;
goto V_35;
}
V_8 -> V_99 = V_107 ;
V_107 -> V_247 |= V_248 ;
V_107 -> V_91 = V_8 -> V_91 ;
F_59 ( V_107 ) -> V_92 = V_8 -> V_92 ;
if ( V_232 ) {
V_8 -> V_35 . V_107 = V_107 ;
if ( V_231 ) {
V_107 = F_130 ( V_116 , false , & V_8 -> V_115 , V_243 ) ;
if ( F_87 ( V_107 ) ) {
F_25 ( L_37 ) ;
V_31 = F_88 ( V_107 ) ;
goto V_35;
}
F_132 ( V_107 ) ;
V_8 -> V_115 . V_107 = V_8 -> V_99 -> V_102 = V_107 ;
}
} else if ( V_231 )
V_8 -> V_115 . V_107 = V_107 ;
V_31 = 0 ;
V_35:
F_25 ( L_38 ,
V_8 , V_231 , V_232 , V_31 , V_8 -> V_99 ) ;
return V_31 ;
}
int F_11 ( struct V_7 * V_8 ,
V_56 V_249 , const void * V_250 , const V_56 * V_176 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
bool V_231 , V_232 ;
struct V_101 * V_233 = V_8 -> V_35 . V_101 ;
T_2 V_234 = V_8 -> V_35 . V_123 ;
int V_31 ;
if ( V_249 & V_251 )
V_66 -> V_249 |= V_252 ;
if ( V_249 & V_253 )
V_66 -> V_249 |= V_254 ;
if ( V_249 & V_255 )
V_66 -> V_256 = V_257 ;
F_137 ( & V_8 -> V_67 , V_250 ) ;
V_231 = V_8 -> V_115 . V_101 || V_8 -> V_103 . V_123 ;
V_232 = V_8 -> V_35 . V_101 || V_8 -> V_106 . V_123 ||
V_8 -> V_105 . V_123 || V_8 -> V_104 . V_123 ;
V_31 = F_104 ( V_8 , V_176 ) ;
if ( V_31 ) {
F_25 ( L_39 ) ;
return V_31 ;
}
V_31 = F_136 ( V_8 , V_231 , V_232 ) ;
if ( V_31 ) {
F_25 ( L_40 ) ;
return V_31 ;
}
V_8 -> V_35 . V_197 = V_258 ;
V_8 -> V_115 . V_197 = V_259 ;
if ( ! V_8 -> V_189 )
V_8 -> V_189 = V_190 ;
V_66 -> V_144 |= V_8 -> V_189 ;
if ( V_8 -> V_189 == V_221 ) {
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
V_31 = F_128 ( V_8 , V_231 , V_232 ,
V_233 , V_234 ,
V_176 ) ;
if ( V_31 )
return V_31 ;
F_138 ( & V_8 -> V_67 , V_176 ) ;
F_59 ( V_8 -> V_99 ) -> V_260 = V_8 -> V_67 . V_97 ;
F_59 ( V_8 -> V_99 ) -> V_261 = F_26 ( V_8 ) ;
return 0 ;
}
static bool F_139 ( int V_262 )
{
return ( V_262 == V_263 ) ||
( V_262 == V_264 ) ||
( V_262 == V_265 ) ||
( V_262 == V_266 ) ||
( V_262 == V_267 ) ;
}
int F_140 ( struct V_7 * V_8 ,
struct V_268 * V_269 , bool V_270 ,
struct V_126 * T_8 V_94 , int T_9 V_94 ,
struct V_14 * V_271 , int V_272 )
{
int V_111 , V_273 ;
struct V_268 V_274 ;
struct V_275 * V_276 ;
void * V_277 ;
#if ( V_278 == 0 )
const bool V_279 = false ;
#else
bool V_279 = ! V_270 ;
#endif
int V_31 ;
if ( F_36 ( ! V_8 -> V_109 ) )
return 0 ;
V_269 = V_269 ? : & V_274 ;
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
V_276 = ( F_141 ( V_276 ) ) V_8 -> V_112 ;
V_111 = V_8 -> V_111 ;
if ( ( V_111 < ( int ) sizeof( * V_276 ) || ! V_276 -> V_280 ) ) {
F_13 ( L_44
L_45 ,
V_8 -> V_109 , V_111 , V_276 -> V_280 ) ;
goto V_281;
}
if ( ( V_276 -> V_282 != 0x72 ) && ( V_276 -> V_282 != 0x73 ) ) {
F_13 ( L_46 ,
V_276 -> V_282 , V_111 ) ;
goto V_281;
}
V_269 -> V_283 = V_276 -> V_280 ;
V_269 -> V_284 = F_34 ( V_276 -> V_285 ) ;
V_273 = V_276 -> V_286 + 8 ;
#if ( V_278 == 1 )
if ( V_279 )
V_279 = ( V_269 -> V_283 > V_287 ) ;
#endif
F_142 ( L_47
L_48 ,
V_269 -> V_283 , V_273 , V_111 ,
V_269 -> V_284 , V_8 -> V_108 ,
V_8 -> V_109 ) ;
if ( V_273 < V_111 )
V_111 = V_273 ;
V_277 = V_276 -> V_288 ;
V_111 -= sizeof( * V_276 ) ;
while ( V_111 > 0 ) {
struct V_289 * V_288 = V_277 ;
int V_290 = V_288 -> V_291 + 2 ;
V_111 -= V_290 ;
if ( V_111 < 0 )
break;
switch ( V_288 -> V_292 ) {
case V_293 :
case V_294 :
{
struct V_295
* V_296 = V_277 ;
V_269 -> V_297 =
F_19 ( & V_296 -> V_298 ) ;
F_143 (
L_49 ,
F_18 ( V_269 -> V_297 ) ) ;
break;
}
case V_299 :
{
struct V_300
* V_301 = V_277 ;
V_269 -> V_302 = F_144 ( & V_301 -> V_303 ) ;
F_143 (
L_50
L_51 ,
V_269 -> V_302 , V_301 -> V_304 ) ;
break;
}
case V_305 :
{
struct V_306
* V_307 = V_277 ;
V_269 -> V_308 =
F_145 ( V_307 -> V_309 ) ;
V_269 -> V_310 =
F_145 ( V_307 -> V_311 ) ;
V_269 -> V_127 . V_135 = F_146 ( V_307 -> V_312 ) ;
V_269 -> V_127 . V_137 = F_146 ( V_307 -> V_313 ) ;
F_143 (
L_52 ,
F_18 ( V_269 -> V_127 . V_135 ) , F_18 ( V_269 -> V_127 . V_137 ) ) ;
F_143 (
L_53
L_54 ,
V_269 -> V_308 ,
V_269 -> V_310 ) ;
break;
}
case V_314 :
{
struct V_315
* V_316 = V_277 ;
const unsigned V_38 =
sizeof( V_316 -> V_317 ) ;
char V_318 [ V_38 * 4 + 2 ] ;
F_20 ( V_316 -> V_317 , V_38 ,
32 , 1 , V_318 , sizeof( V_318 ) , true ) ;
F_143 ( L_55 , V_318 ) ;
}
case V_319 :
{
struct V_320
* V_321 = V_277 ;
unsigned V_38 = F_147 ( V_290 , V_111 ) ;
struct V_322 * V_323 = V_321 -> V_324 ;
while ( V_38 >= sizeof( * V_323 ) ) {
T_7 V_48 = F_35 ( V_323 -> V_48 ) ;
T_7 V_49 = F_35 ( V_323 -> V_49 ) ;
if ( ! V_269 -> V_47 . V_48 ) {
V_269 -> V_47 . V_48 = V_48 ;
V_269 -> V_47 . V_49 = V_49 ;
}
if ( V_271 && V_272 ) {
V_271 -> V_48 = V_48 ;
V_271 -> V_49 = V_49 ;
V_271 ++ ;
V_272 -- ;
}
V_38 -= sizeof( * V_323 ) ;
F_143 (
L_56
L_57 ,
V_48 , V_49 ) ;
}
}
case V_325 :
F_143 ( L_58 ) ;
break;
case V_326 :
F_143 ( L_59 ) ;
break;
case V_327 :
F_143 ( L_60 ) ;
break;
case V_328 :
F_143 ( L_61 ) ;
break;
default:
if ( V_288 -> V_292 <= V_329 )
F_143 (
L_62 ,
V_288 -> V_292 ) ;
else
F_143 (
L_63 ,
V_288 -> V_292 ) ;
}
V_277 += V_290 ;
}
V_281:
if ( ! V_269 -> V_283 ) {
if ( V_8 -> V_108 == - V_33 )
V_269 -> V_330 = V_331 ;
else
V_269 -> V_330 = V_332 ;
V_31 = V_8 -> V_108 ;
} else if ( V_269 -> V_283 <= V_287 ) {
V_269 -> V_330 = 0 ;
V_31 = 0 ;
} else if ( V_269 -> V_284 == V_333 ) {
if ( V_269 -> V_334 == V_335 ) {
V_269 -> V_330 = V_336 ;
V_31 = - V_337 ;
} else if ( V_269 -> V_334 == V_338 ) {
V_269 -> V_330 = V_339 ;
V_31 = - V_340 ;
} else if ( V_269 -> V_334 == V_341 ) {
V_269 -> V_330 = V_342 ;
V_31 = - V_343 ;
} else {
V_269 -> V_330 = V_344 ;
V_31 = - V_191 ;
}
} else if ( V_269 -> V_284 == V_345 ) {
V_269 -> V_330 = V_346 ;
V_31 = - V_347 ;
} else if ( F_139 ( V_269 -> V_284 ) ) {
V_269 -> V_330 = V_344 ;
V_31 = - V_191 ;
} else {
V_269 -> V_330 = V_348 ;
V_31 = - V_117 ;
}
if ( ! V_8 -> V_35 . V_113 )
V_8 -> V_35 . V_113 = V_8 -> V_35 . V_123 ;
if ( ! V_8 -> V_115 . V_113 )
V_8 -> V_115 . V_113 = V_8 -> V_115 . V_123 ;
return V_31 ;
}
void F_148 ( void * V_11 ,
const struct V_126 * V_127 , bool V_349 , const bool V_227 )
{
struct V_1 * V_250 = V_11 ;
V_56 type ;
V_56 V_292 ;
if ( F_36 ( V_127 -> V_137 ) ) {
if ( F_21 ( V_349 ) ) {
type = V_350 ;
V_292 = V_227 ? V_351 :
V_352 ;
} else {
type = V_353 ;
V_292 = V_351 ;
}
F_85 ( ! V_127 -> V_135 ) ;
} else {
type = V_127 -> V_135 ? V_354 :
V_355 ;
V_292 = V_356 ;
}
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
V_250 -> V_128 . V_178 = V_357 ;
V_250 -> V_128 . V_358 = 0 ;
V_250 -> V_128 . V_359 = V_360 ;
V_250 -> V_128 . V_361 = type ;
F_149 ( & V_250 -> V_128 , V_362 ) ;
V_250 -> V_128 . V_363 = V_292 ;
V_250 -> V_10 . V_364 . V_365 = 0 ;
V_250 -> V_10 . V_364 . V_366 = F_72 ( V_127 -> V_135 ) ;
V_250 -> V_10 . V_364 . V_367 = F_72 ( V_127 -> V_137 ) ;
}
void F_137 ( struct V_79 * V_67 , const void * V_11 )
{
memcpy ( & V_67 -> V_68 . V_11 , V_11 , V_368 ) ;
}
bool F_129 ( struct V_78 * V_228 V_94 )
{
return false ;
}
void F_138 ( struct V_79 * V_80 V_94 , const V_56 * V_176 V_94 )
{
}
void F_105 ( void * T_10 V_94 ,
struct V_101 * V_101 V_94 , const V_56 * V_176 V_94 )
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
