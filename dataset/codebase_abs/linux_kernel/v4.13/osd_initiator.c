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
F_55 ( V_100 , V_102 , F_56 ( V_100 ) ) ;
else
F_57 ( V_100 ) ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_99 * V_100 = V_8 -> V_99 ;
if ( V_100 ) {
if ( V_100 -> V_103 ) {
F_54 ( V_100 -> V_103 ) ;
V_100 -> V_103 = NULL ;
}
F_54 ( V_100 ) ;
}
F_53 ( V_8 , & V_8 -> V_104 ) ;
F_53 ( V_8 , & V_8 -> V_105 ) ;
F_53 ( V_8 , & V_8 -> V_106 ) ;
F_53 ( V_8 , & V_8 -> V_107 ) ;
F_51 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 , struct V_99 * V_108 ,
T_4 error )
{
V_8 -> V_109 = error ;
V_8 -> V_110 = F_59 ( V_108 ) -> V_111 ;
V_8 -> V_112 = F_59 ( V_108 ) -> V_112 ;
if ( V_8 -> V_112 )
memcpy ( V_8 -> V_113 , F_59 ( V_108 ) -> V_113 , V_8 -> V_112 ) ;
if ( V_8 -> V_35 . V_108 )
V_8 -> V_35 . V_114 = F_59 ( V_8 -> V_35 . V_108 ) -> V_115 ;
if ( V_8 -> V_116 . V_108 )
V_8 -> V_116 . V_114 = F_59 ( V_8 -> V_116 . V_108 ) -> V_115 ;
}
int F_12 ( struct V_7 * V_8 )
{
F_60 ( V_8 -> V_99 -> V_117 , NULL , V_8 -> V_99 , 0 ) ;
if ( F_59 ( V_8 -> V_99 ) -> V_111 ) {
F_58 ( V_8 , V_8 -> V_99 , V_102 ) ;
return - V_118 ;
}
F_58 ( V_8 , V_8 -> V_99 , V_119 ) ;
return 0 ;
}
static void F_61 ( struct V_99 * V_108 , T_4 error )
{
struct V_7 * V_8 = V_108 -> V_120 ;
F_58 ( V_8 , V_108 , error ) ;
if ( V_108 -> V_103 ) {
F_62 ( V_108 -> V_117 , V_108 -> V_103 ) ;
V_108 -> V_103 = NULL ;
}
F_62 ( V_108 -> V_117 , V_108 ) ;
V_8 -> V_99 = NULL ;
V_8 -> V_116 . V_108 = NULL ;
V_8 -> V_35 . V_108 = NULL ;
if ( V_8 -> V_121 )
V_8 -> V_121 ( V_8 , V_8 -> V_122 ) ;
else
F_22 ( V_8 ) ;
}
int F_63 ( struct V_7 * V_8 ,
T_5 * V_123 , void * V_124 )
{
V_8 -> V_99 -> V_120 = V_8 ;
V_8 -> V_122 = V_124 ;
V_8 -> V_121 = V_123 ;
F_64 ( V_8 -> V_99 -> V_117 , NULL , V_8 -> V_99 , 0 ,
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
static int F_67 ( struct V_7 * V_8 , unsigned V_125 )
{
F_25 ( L_21 , V_125 ) ;
return F_65 ( V_8 , & V_8 -> V_107 , V_125 ) ;
}
static int F_68 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 , unsigned V_126 )
{
unsigned V_125 = V_126 ;
for (; V_29 ; -- V_29 , ++ V_45 )
V_125 += F_27 ( V_8 , V_45 -> V_38 ) ;
F_25 ( L_21 , V_125 ) ;
return F_65 ( V_8 , & V_8 -> V_106 , V_125 ) ;
}
static int F_69 ( struct V_7 * V_8 , unsigned V_54 )
{
F_25 ( L_21 , V_54 ) ;
return F_65 ( V_8 , & V_8 -> V_105 , V_54 ) ;
}
static int F_70 ( struct V_7 * V_8 )
{
F_25 ( L_21 , V_8 -> V_104 . V_125 ) ;
return F_65 ( V_8 , & V_8 -> V_104 , V_8 -> V_104 . V_125 ) ;
}
static void F_71 ( struct V_7 * V_8 ,
T_6 V_127 , const struct V_128 * V_129 , T_2 V_73 , T_2 V_38 )
{
struct V_5 * V_80 = & V_8 -> V_67 . V_68 ;
V_127 &= F_32 ( ~ 0x0080 ) ;
F_25 ( L_22 , F_34 ( V_127 ) ) ;
V_80 -> V_130 . V_131 . V_132 = V_133 ;
V_80 -> V_130 . V_131 . V_134 = V_135 ;
V_80 -> V_130 . V_131 . V_136 = V_127 ;
V_80 -> V_130 . V_137 = F_72 ( V_129 -> V_137 ) ;
V_80 -> V_130 . V_138 = F_72 ( V_129 -> V_139 ) ;
V_80 -> V_130 . V_68 . V_140 = F_72 ( V_38 ) ;
V_80 -> V_130 . V_68 . V_70 = F_72 ( V_73 ) ;
}
static void F_73 ( struct V_7 * V_8 ,
T_6 V_127 , const struct V_128 * V_129 , T_2 V_73 , T_2 V_38 )
{
struct V_3 * V_80 = & V_8 -> V_67 . V_72 ;
F_25 ( L_23 , F_34 ( V_127 ) ) ;
V_80 -> V_130 . V_131 . V_132 = V_133 ;
V_80 -> V_130 . V_131 . V_134 = V_135 ;
V_80 -> V_130 . V_131 . V_136 = V_127 ;
V_80 -> V_130 . V_137 = F_72 ( V_129 -> V_137 ) ;
V_80 -> V_130 . V_138 = F_72 ( V_129 -> V_139 ) ;
V_80 -> V_130 . V_72 . V_140 = F_72 ( V_38 ) ;
V_80 -> V_130 . V_72 . V_70 = F_72 ( V_73 ) ;
}
static void F_74 ( struct V_7 * V_8 ,
T_6 V_127 , const struct V_128 * V_129 , T_2 V_73 , T_2 V_38 )
{
if ( F_4 ( V_8 ) )
F_71 ( V_8 , V_127 , V_129 , V_73 , V_38 ) ;
else
F_73 ( V_8 , V_127 , V_129 , V_73 , V_38 ) ;
}
void F_75 ( struct V_7 * V_8 , T_2 V_141 )
{
F_74 ( V_8 , V_142 , & V_34 , 0 ,
V_141 ) ;
}
int F_76 ( struct V_7 * V_8 ,
T_7 V_143 , struct V_64 * V_61 , unsigned V_29 )
{
return F_77 ( V_8 , 0 , V_143 , V_61 , V_29 ) ;
}
static void F_78 ( struct V_7 * V_8 ,
enum V_144 V_145 )
{
struct V_65 * V_80 = V_65 ( & V_8 -> V_67 ) ;
V_80 -> V_146 = V_145 ;
}
void F_79 ( struct V_7 * V_8 ,
enum V_144 V_145 )
{
F_74 ( V_8 , V_147 , & V_34 , 0 , 0 ) ;
F_78 ( V_8 , V_145 ) ;
}
static void F_80 ( struct V_7 * V_8 ,
T_6 V_127 , T_7 V_137 )
{
struct V_128 V_148 = {
. V_137 = V_137 ,
. V_139 = 0 ,
} ;
F_74 ( V_8 , V_127 , & V_148 , 0 , 0 ) ;
}
void F_81 ( struct V_7 * V_8 , T_7 V_137 )
{
F_80 ( V_8 , V_149 , V_137 ) ;
}
void F_82 ( struct V_7 * V_8 , T_7 V_137 )
{
F_80 ( V_8 , V_150 , V_137 ) ;
}
static int F_83 ( struct V_7 * V_8 ,
T_6 V_151 , const struct V_128 * V_129 , T_7 V_143 ,
struct V_64 * V_61 , unsigned V_29 )
{
struct V_152 * V_117 = F_84 ( V_8 -> V_9 ) ;
T_2 V_38 = V_29 * sizeof( T_7 ) + sizeof( * V_61 ) ;
struct V_101 * V_101 ;
F_74 ( V_8 , V_151 , V_129 , ( T_2 ) V_143 , V_38 ) ;
if ( V_61 -> V_69 )
F_43 ( V_8 , V_61 ) ;
F_85 ( V_8 -> V_116 . V_101 ) ;
V_101 = F_86 ( V_117 , V_61 , V_38 , V_8 -> V_90 ) ;
if ( F_87 ( V_101 ) ) {
F_13 ( L_24 ) ;
return F_88 ( V_101 ) ;
}
F_89 ( V_101 , V_153 , 0 ) ;
V_8 -> V_116 . V_101 = V_101 ;
V_8 -> V_116 . V_125 = V_101 -> V_154 . V_155 ;
return 0 ;
}
int F_90 ( struct V_7 * V_8 ,
T_7 V_137 , T_7 V_143 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_128 V_148 = {
. V_137 = V_137 ,
. V_139 = 0 ,
} ;
return F_91 ( V_8 , & V_148 , V_143 , V_61 ,
V_29 ) ;
}
int F_77 ( struct V_7 * V_8 ,
T_7 V_137 , T_7 V_143 , struct V_64 * V_61 ,
unsigned V_29 )
{
struct V_128 V_148 = {
. V_137 = V_137 ,
. V_139 = 0 ,
} ;
return F_83 ( V_8 , V_156 , & V_148 , V_143 , V_61 ,
V_29 ) ;
}
void F_92 ( struct V_7 * V_8 ,
T_7 V_137 , enum V_144 V_145 )
{
F_80 ( V_8 , V_157 , V_137 ) ;
F_78 ( V_8 , V_145 ) ;
}
int F_91 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , T_7 V_143 ,
struct V_64 * V_61 , unsigned V_29 )
{
return F_83 ( V_8 , V_158 , V_129 ,
V_143 , V_61 , V_29 ) ;
}
void F_93 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , enum V_144 V_145 )
{
F_74 ( V_8 , V_157 , V_129 , 0 , 0 ) ;
F_78 ( V_8 , V_145 ) ;
}
void F_94 ( struct V_7 * V_8 , struct V_128 * V_129 )
{
F_74 ( V_8 , V_159 , V_129 , 0 , 0 ) ;
}
void F_95 ( struct V_7 * V_8 , struct V_128 * V_129 )
{
F_74 ( V_8 , V_160 , V_129 , 0 , 0 ) ;
}
void F_96 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_161 , V_129 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_35 . V_101 || V_8 -> V_35 . V_125 ) ;
F_85 ( ! F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_125 = V_38 ;
}
int F_99 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_152 * V_162 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_162 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_163 , 0 ) ;
F_96 ( V_8 , V_129 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
void F_100 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , enum V_144 V_145 ,
T_2 V_73 , T_2 V_38 )
{
if ( F_21 ( F_4 ( V_8 ) && ( V_73 || V_38 ) ) ) {
F_25 ( L_25 ) ;
V_73 = 0 ;
V_38 = 0 ;
}
F_74 ( V_8 , V_164 , V_129 , V_73 , V_38 ) ;
F_78 ( V_8 , V_145 ) ;
}
void F_101 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , T_2 V_73 ,
struct V_101 * V_101 , T_2 V_38 )
{
F_74 ( V_8 , V_165 , V_129 , V_73 , V_38 ) ;
F_85 ( V_8 -> V_116 . V_101 || V_8 -> V_116 . V_125 ) ;
F_85 ( F_97 ( F_98 ( V_101 ) ) ) ;
V_8 -> V_116 . V_101 = V_101 ;
V_8 -> V_116 . V_125 = V_38 ;
}
int F_102 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , T_2 V_73 , void * V_97 , T_2 V_38 )
{
struct V_152 * V_162 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 = F_86 ( V_162 , V_97 , V_38 , V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_101 ( V_8 , V_129 , V_73 , V_101 , V_38 ) ;
return 0 ;
}
static int F_103 ( struct V_7 * V_8 ,
const struct V_166 * V_167 , unsigned V_168 , T_2 * V_38 )
{
struct V_169 * V_170 ;
T_8 V_171 ;
unsigned V_172 ;
int V_31 ;
V_171 = sizeof( * V_170 ) + V_168 * sizeof( V_170 -> V_173 [ 0 ] ) ;
if ( ! V_8 -> V_107 . V_125 ) {
V_8 -> V_107 . V_125 =
sizeof( struct V_174 ) ;
}
V_31 = F_67 ( V_8 , V_8 -> V_107 . V_125 + V_171 ) ;
if ( F_21 ( V_31 ) )
return V_31 ;
V_170 = V_8 -> V_107 . V_97 + V_8 -> V_107 . V_125 ;
V_170 -> V_175 . type = F_32 ( V_176 ) ;
V_170 -> V_175 . V_177 = 0 ;
V_170 -> V_175 . V_140 = F_31 ( V_171 - sizeof( * V_170 ) ) ;
* V_38 = 0 ;
for ( V_172 = 0 ; V_172 < V_168 ; V_172 ++ ) {
V_170 -> V_173 [ V_172 ] . V_73 = F_72 ( V_167 [ V_172 ] . V_73 ) ;
V_170 -> V_173 [ V_172 ] . V_38 = F_72 ( V_167 [ V_172 ] . V_38 ) ;
* V_38 += V_167 [ V_172 ] . V_38 ;
}
V_8 -> V_107 . V_125 += V_171 ;
F_25 ( L_26 ,
V_8 -> V_107 . V_125 , V_171 , V_168 ) ;
return 0 ;
}
static int F_104 ( struct V_7 * V_8 , const V_56 * V_178 )
{
struct V_152 * V_162 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
struct V_174 * V_179 ;
if ( ! V_8 -> V_107 . V_125 )
return 0 ;
V_179 = V_8 -> V_107 . V_97 ;
V_179 -> V_180 = V_181 ;
V_179 -> V_136 = V_66 -> V_131 . V_136 ;
V_101 = F_86 ( V_162 , V_8 -> V_107 . V_97 , V_8 -> V_107 . V_125 ,
V_32 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_163 , 0 ) ;
F_105 ( V_179 -> V_182 , V_101 , V_178 ) ;
V_66 -> V_72 . V_183 = F_31 ( V_8 -> V_107 . V_125 ) ;
V_101 -> V_184 = V_8 -> V_35 . V_101 ;
V_8 -> V_35 . V_101 = V_101 ;
V_8 -> V_35 . V_125 += V_8 -> V_107 . V_125 ;
return 0 ;
}
int F_106 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , struct V_101 * V_101 ,
const struct V_166 * V_167 , unsigned V_168 )
{
T_2 V_38 ;
int V_31 = F_103 ( V_8 , V_167 , V_168 , & V_38 ) ;
if ( V_31 )
return V_31 ;
F_96 ( V_8 , V_129 , 0 , V_101 , V_38 ) ;
return 0 ;
}
int F_107 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , struct V_101 * V_101 ,
const struct V_166 * V_167 , unsigned V_168 )
{
T_2 V_38 ;
T_2 V_185 ;
int V_31 ;
if ( V_168 > 1 ) {
V_185 = 0 ;
V_31 = F_103 ( V_8 , V_167 , V_168 ,
& V_38 ) ;
if ( V_31 )
return V_31 ;
} else {
V_38 = V_167 -> V_38 ;
V_185 = V_167 -> V_73 ;
}
F_101 ( V_8 , V_129 , V_185 , V_101 , V_38 ) ;
return 0 ;
}
static struct V_101 * F_108 ( struct V_7 * V_8 ,
void * * V_97 , const struct V_166 * V_167 , unsigned V_168 )
{
struct V_152 * V_117 = F_84 ( V_8 -> V_9 ) ;
struct V_101 * V_101 ;
unsigned V_172 ;
V_101 = F_109 ( V_32 , V_168 ) ;
if ( F_21 ( ! V_101 ) ) {
F_25 ( L_27 , V_168 ) ;
return F_110 ( - V_33 ) ;
}
for ( V_172 = 0 ; V_172 < V_168 ; V_172 ++ ) {
unsigned V_73 = F_111 ( V_97 [ V_172 ] ) ;
struct V_186 * V_186 = F_112 ( V_97 [ V_172 ] ) ;
unsigned V_38 = V_167 [ V_172 ] . V_38 ;
unsigned V_187 ;
F_113 ( V_73 + V_38 > V_188 ) ;
V_187 = F_114 ( V_117 , V_101 , V_186 , V_38 , V_73 ) ;
if ( F_21 ( V_38 != V_187 ) ) {
F_25 ( L_28 ,
V_38 , V_187 ) ;
F_115 ( V_101 ) ;
return F_110 ( - V_33 ) ;
}
}
return V_101 ;
}
int F_116 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , void * * V_97 ,
const struct V_166 * V_167 , unsigned V_168 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_167 , V_168 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_89 ( V_101 , V_163 , 0 ) ;
F_106 ( V_8 , V_129 , V_101 , V_167 , V_168 ) ;
return 0 ;
}
int F_117 ( struct V_7 * V_8 ,
const struct V_128 * V_129 , void * * V_97 ,
const struct V_166 * V_167 , unsigned V_168 )
{
struct V_101 * V_101 = F_108 ( V_8 , V_97 , V_167 , V_168 ) ;
if ( F_87 ( V_101 ) )
return F_88 ( V_101 ) ;
F_107 ( V_8 , V_129 , V_101 , V_167 , V_168 ) ;
return 0 ;
}
void F_9 ( struct V_7 * V_8 ,
const struct V_128 * V_129 )
{
F_74 ( V_8 , V_189 , V_129 , 0 , 0 ) ;
}
void F_118 ( struct V_7 * V_8 ,
const struct V_128 * V_129 )
{
F_74 ( V_8 , V_190 , V_129 , 0 , 0 ) ;
}
int F_119 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_125 = V_8 -> V_106 . V_125 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_191 &&
V_8 -> V_191 != V_192 ) {
F_85 ( 1 ) ;
return - V_193 ;
}
V_8 -> V_191 = V_192 ;
if ( ! V_125 ) {
V_125 = F_40 ( V_8 ) ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_125 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_106 . V_97 ,
V_194 ) ;
}
V_44 = V_8 -> V_106 . V_97 + V_125 ;
for (; V_29 ; -- V_29 ) {
unsigned V_195 = F_27 ( V_8 , V_45 -> V_38 ) ;
V_125 += V_195 ;
if ( F_21 ( V_8 -> V_106 . V_98 < V_125 ) ) {
V_8 -> V_106 . V_125 = V_125 - V_195 ;
V_31 = F_68 ( V_8 , V_45 , V_29 , V_125 ) ;
if ( V_31 )
return V_31 ;
V_44 =
V_8 -> V_106 . V_97 + V_8 -> V_106 . V_125 ;
}
F_30 ( V_8 , V_44 , V_45 ) ;
V_44 += V_195 ;
++ V_45 ;
}
V_8 -> V_106 . V_125 = V_125 ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 ,
unsigned V_74 , struct V_95 * V_96 ,
struct V_95 * V_196 , struct V_197 * V_198 )
{
void * V_199 ;
int V_31 ;
if ( V_74 ) {
if ( V_196 &&
( V_74 <= V_196 -> V_98 - V_196 -> V_125 ) )
V_199 = V_196 -> V_97 + V_196 -> V_125 ;
else
V_199 = V_198 -> V_199 ;
V_31 = F_121 ( V_198 -> V_108 -> V_117 , V_198 -> V_108 , V_199 , V_74 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_198 -> V_125 += V_74 ;
}
V_31 = F_121 ( V_198 -> V_108 -> V_117 , V_198 -> V_108 , V_96 -> V_97 , V_96 -> V_125 ,
V_8 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_198 -> V_125 += V_96 -> V_125 ;
F_25 ( L_29 , V_74 , V_96 -> V_97 ,
V_96 -> V_125 ) ;
return 0 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_74 ;
int V_31 ;
if ( ! V_8 -> V_106 . V_125 ) {
V_66 -> V_200 . V_201 = V_202 ;
return 0 ;
}
V_66 -> V_200 . V_203 = F_31 ( V_8 -> V_106 . V_125 ) ;
V_66 -> V_200 . V_201 =
F_44 ( V_8 , V_8 -> V_35 . V_125 , & V_74 ) ;
V_31 = F_120 ( V_8 , V_74 , & V_8 -> V_106 ,
V_8 -> V_35 . V_196 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_196 = & V_8 -> V_106 ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 ,
const struct V_14 * V_45 , unsigned V_29 )
{
unsigned V_125 = V_8 -> V_105 . V_125 ;
void * V_44 ;
int V_31 ;
if ( V_8 -> V_191 &&
V_8 -> V_191 != V_192 ) {
F_85 ( 1 ) ;
return - V_193 ;
}
V_8 -> V_191 = V_192 ;
if ( ! V_8 -> V_104 . V_125 )
V_8 -> V_104 . V_125 = F_40 ( V_8 ) ;
if ( ! V_125 ) {
unsigned V_54 ;
V_125 = F_40 ( V_8 ) ;
V_54 = V_125 +
V_29 * sizeof( struct V_204 ) ;
V_31 = F_69 ( V_8 , V_54 ) ;
if ( V_31 )
return V_31 ;
F_41 ( V_8 , V_8 -> V_105 . V_97 ,
V_205 ) ;
}
V_44 = V_8 -> V_105 . V_97 + V_125 ;
for (; V_29 ; -- V_29 ) {
struct V_204 * V_206 ;
const unsigned V_207 = sizeof( * V_206 ) ;
V_125 += V_207 ;
if ( F_21 ( V_8 -> V_105 . V_98 < V_125 ) ) {
V_8 -> V_105 . V_125 = V_125 - V_207 ;
V_31 = F_69 ( V_8 ,
V_125 + V_29 * sizeof( * V_206 ) ) ;
if ( V_31 )
return V_31 ;
V_44 = V_8 -> V_105 . V_97 +
V_8 -> V_105 . V_125 ;
}
V_206 = V_44 ;
V_206 -> V_48 = F_31 ( V_45 -> V_48 ) ;
V_206 -> V_49 = F_31 ( V_45 -> V_49 ) ;
V_44 += V_207 ;
V_8 -> V_104 . V_125 +=
F_27 ( V_8 , V_45 -> V_38 ) ;
++ V_45 ;
}
V_8 -> V_105 . V_125 = V_125 ;
F_25 (
L_30 ,
V_8 -> V_104 . V_125 ,
V_8 -> V_104 . V_125 - F_40 ( V_8 ) ,
V_8 -> V_105 . V_125 ,
( V_8 -> V_105 . V_125 - F_40 ( V_8 ) )
/ sizeof( struct V_204 ) ) ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_208 ;
unsigned V_209 ;
int V_31 ;
if ( ! V_8 -> V_105 . V_125 ) {
V_66 -> V_200 . V_210 = V_202 ;
V_66 -> V_200 . V_211 = V_202 ;
return 0 ;
}
V_31 = F_70 ( V_8 ) ;
if ( V_31 )
return V_31 ;
F_25 ( L_31 ) ;
V_66 -> V_200 . V_212 =
F_31 ( V_8 -> V_105 . V_125 ) ;
V_66 -> V_200 . V_210 =
F_44 ( V_8 , V_8 -> V_35 . V_125 , & V_208 ) ;
V_31 = F_120 ( V_8 , V_208 , & V_8 -> V_105 ,
V_8 -> V_35 . V_196 , & V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_196 = & V_8 -> V_105 ;
F_25 ( L_32 ) ;
V_66 -> V_200 . V_213 =
F_31 ( V_8 -> V_104 . V_125 ) ;
V_66 -> V_200 . V_211 =
F_44 ( V_8 , V_8 -> V_116 . V_125 , & V_209 ) ;
V_31 = F_120 ( V_8 , V_209 , & V_8 -> V_104 , NULL ,
& V_8 -> V_116 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_116 . V_196 = & V_8 -> V_104 ;
return 0 ;
}
int F_14 ( struct V_7 * V_8 ,
struct V_14 * V_45 , int * V_29 , void * * V_214 )
{
unsigned V_215 , V_216 ;
int V_217 ;
const unsigned V_218 = F_40 ( V_8 ) ;
void * V_53 ;
if ( ! F_42 ( V_8 , V_8 -> V_104 . V_97 ,
V_194 ) ) {
V_45 -> V_48 = 0 ;
V_45 -> V_49 = 0 ;
V_45 -> V_36 = NULL ;
V_45 -> V_38 = 0 ;
* V_214 = NULL ;
return 0 ;
}
if ( * V_214 ) {
F_113 ( ( * V_214 < V_8 -> V_104 . V_97 ) ||
( V_8 -> V_104 . V_97 + V_8 -> V_104 . V_98 < * V_214 ) ) ;
V_53 = * V_214 ;
V_215 = ( * V_214 - V_8 -> V_104 . V_97 ) - V_218 ;
V_216 = V_8 -> V_104 . V_125 ;
} else {
V_215 = V_218 ;
V_216 = F_37 ( V_8 , V_8 -> V_104 . V_97 ) +
V_218 ;
V_53 = V_8 -> V_104 . V_97 + V_218 ;
if ( V_216 > V_8 -> V_104 . V_98 ) {
F_25 ( L_33
L_34 ,
V_8 -> V_104 . V_98 ,
V_216 + V_218 ) ;
V_216 =
V_8 -> V_104 . V_98 - V_218 ;
}
V_8 -> V_104 . V_125 = V_216 ;
}
for ( V_217 = 0 ; ( V_217 < * V_29 ) && ( V_215 < V_216 ) ; ++ V_217 ) {
int V_55 = F_33 ( V_8 , V_53 , V_45 ,
V_216 - V_215 ) ;
if ( V_55 < 0 ) {
F_13 ( L_35
L_36 ,
V_215 , V_216 , V_217 ) ;
V_45 -> V_36 = NULL ;
V_215 = V_216 ;
break;
}
V_215 += V_55 ;
V_53 += V_55 ;
++ V_45 ;
}
* V_214 = ( V_216 - V_215 ) ? V_53 : NULL ;
* V_29 = V_217 ;
return V_216 - V_215 ;
}
int F_124 ( struct V_7 * V_8 ,
T_8 V_219 , void * V_220 , unsigned V_221 ,
const struct V_14 * V_222 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
if ( V_8 -> V_191 &&
V_8 -> V_191 != V_223 ) {
F_85 ( 1 ) ;
return - V_193 ;
}
V_8 -> V_191 = V_223 ;
V_8 -> V_104 . V_97 = V_220 ;
V_8 -> V_104 . V_125 = V_221 ;
V_66 -> V_224 . V_225 = F_31 ( V_219 ) ;
V_66 -> V_224 . V_213 = F_31 ( V_221 ) ;
if ( ! V_222 || ! V_222 -> V_48 )
return 0 ;
V_8 -> V_106 . V_97 = V_222 -> V_36 ;
V_8 -> V_106 . V_125 = V_222 -> V_38 ;
V_66 -> V_224 . V_226 = F_31 ( V_222 -> V_48 ) ;
V_66 -> V_224 . V_227 = F_31 ( V_222 -> V_49 ) ;
V_66 -> V_224 . V_228 = F_31 ( V_222 -> V_38 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
unsigned V_209 , V_208 ;
int V_31 ;
V_66 -> V_224 . V_211 =
F_44 ( V_8 , V_8 -> V_116 . V_125 , & V_209 ) ;
V_31 = F_120 ( V_8 , V_209 , & V_8 -> V_104 , NULL ,
& V_8 -> V_116 ) ;
if ( V_31 )
return V_31 ;
if ( V_8 -> V_106 . V_125 == 0 )
return 0 ;
V_66 -> V_224 . V_201 =
F_44 ( V_8 , V_8 -> V_35 . V_125 , & V_208 ) ;
V_31 = F_120 ( V_8 , V_208 , & V_8 -> V_106 , NULL ,
& V_8 -> V_35 ) ;
return V_31 ;
}
static inline void F_126 ( bool V_229 ,
struct V_78 * V_230 , T_1 V_73 )
{
if ( V_229 )
V_230 -> V_68 . V_231 = V_73 ;
else
V_230 -> V_72 . V_231 = V_73 ;
}
static inline void F_127 ( bool V_229 ,
struct V_78 * V_230 , T_1 V_73 )
{
if ( V_229 )
V_230 -> V_68 . V_232 = V_73 ;
else
V_230 -> V_72 . V_232 = V_73 ;
}
static int F_128 ( struct V_7 * V_8 ,
bool V_233 , bool V_234 , struct V_101 * V_235 , T_2 V_236 ,
const V_56 * V_178 )
{
struct V_78 * V_230 = F_46 ( V_8 ) ;
int V_31 ;
if ( ! F_129 ( V_230 ) )
return 0 ;
if ( V_234 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_237 ,
. V_125 = sizeof( V_8 -> V_237 ) ,
} ;
unsigned V_238 ;
V_8 -> V_237 . V_239 = F_72 ( V_236 ) ;
V_8 -> V_237 . V_240 = F_72 (
V_8 -> V_106 . V_125 ) ;
V_8 -> V_237 . V_241 = F_72 (
V_8 -> V_105 . V_125 ) ;
F_126 ( F_4 ( V_8 ) , V_230 ,
F_44 ( V_8 , V_8 -> V_35 . V_125 , & V_238 ) ) ;
V_31 = F_120 ( V_8 , V_238 , & V_96 , V_8 -> V_35 . V_196 ,
& V_8 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_35 . V_196 = NULL ;
F_105 ( & V_8 -> V_237 , V_235 ,
V_178 ) ;
}
if ( V_233 ) {
struct V_95 V_96 = {
. V_97 = & V_8 -> V_242 ,
. V_125 = sizeof( V_8 -> V_242 ) ,
} ;
unsigned V_238 ;
F_127 ( F_4 ( V_8 ) , V_230 ,
F_44 ( V_8 , V_8 -> V_116 . V_125 , & V_238 ) ) ;
V_31 = F_120 ( V_8 , V_238 , & V_96 , V_8 -> V_116 . V_196 ,
& V_8 -> V_116 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_116 . V_196 = NULL ;
}
return 0 ;
}
static struct V_99 * F_130 ( struct V_152 * V_117 , bool V_243 ,
struct V_197 * V_244 , T_3 V_245 )
{
struct V_99 * V_108 ;
struct V_101 * V_101 = V_244 -> V_101 ;
int V_31 ;
V_108 = F_131 ( V_117 , V_243 ? V_246 : V_247 ,
V_245 ) ;
if ( F_87 ( V_108 ) )
return V_108 ;
F_132 (bio) {
V_31 = F_133 ( V_108 , V_101 ) ;
if ( V_31 )
return F_110 ( V_31 ) ;
}
return V_108 ;
}
static int F_134 ( struct V_7 * V_8 ,
bool V_233 , bool V_234 )
{
T_3 V_245 = V_8 -> V_90 ;
struct V_83 * V_83 = V_8 -> V_9 -> V_83 ;
struct V_152 * V_117 = V_83 -> V_152 ;
struct V_99 * V_108 ;
int V_31 ;
V_108 = F_130 ( V_117 , V_234 , V_234 ? & V_8 -> V_35 : & V_8 -> V_116 , V_245 ) ;
if ( F_87 ( V_108 ) ) {
V_31 = F_88 ( V_108 ) ;
goto V_35;
}
V_8 -> V_99 = V_108 ;
V_108 -> V_248 |= V_249 ;
V_108 -> V_91 = V_8 -> V_91 ;
F_59 ( V_108 ) -> V_92 = V_8 -> V_92 ;
if ( V_234 ) {
V_8 -> V_35 . V_108 = V_108 ;
if ( V_233 ) {
V_108 = F_130 ( V_117 , false , & V_8 -> V_116 , V_245 ) ;
if ( F_87 ( V_108 ) ) {
F_25 ( L_37 ) ;
V_31 = F_88 ( V_108 ) ;
goto V_35;
}
V_8 -> V_116 . V_108 = V_8 -> V_99 -> V_103 = V_108 ;
}
} else if ( V_233 )
V_8 -> V_116 . V_108 = V_108 ;
V_31 = 0 ;
V_35:
F_25 ( L_38 ,
V_8 , V_233 , V_234 , V_31 , V_8 -> V_99 ) ;
return V_31 ;
}
int F_11 ( struct V_7 * V_8 ,
V_56 V_250 , const void * V_251 , const V_56 * V_178 )
{
struct V_65 * V_66 = V_65 ( & V_8 -> V_67 ) ;
bool V_233 , V_234 ;
struct V_101 * V_235 = V_8 -> V_35 . V_101 ;
T_2 V_236 = V_8 -> V_35 . V_125 ;
int V_31 ;
if ( V_250 & V_252 )
V_66 -> V_250 |= V_253 ;
if ( V_250 & V_254 )
V_66 -> V_250 |= V_255 ;
if ( V_250 & V_256 )
V_66 -> V_257 = V_258 ;
F_135 ( & V_8 -> V_67 , V_251 ) ;
V_233 = V_8 -> V_116 . V_101 || V_8 -> V_104 . V_125 ;
V_234 = V_8 -> V_35 . V_101 || V_8 -> V_107 . V_125 ||
V_8 -> V_106 . V_125 || V_8 -> V_105 . V_125 ;
V_31 = F_104 ( V_8 , V_178 ) ;
if ( V_31 ) {
F_25 ( L_39 ) ;
return V_31 ;
}
V_31 = F_134 ( V_8 , V_233 , V_234 ) ;
if ( V_31 ) {
F_25 ( L_40 ) ;
return V_31 ;
}
V_8 -> V_35 . V_199 = V_259 ;
V_8 -> V_116 . V_199 = V_260 ;
if ( ! V_8 -> V_191 )
V_8 -> V_191 = V_192 ;
V_66 -> V_146 |= V_8 -> V_191 ;
if ( V_8 -> V_191 == V_223 ) {
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
V_31 = F_128 ( V_8 , V_233 , V_234 ,
V_235 , V_236 ,
V_178 ) ;
if ( V_31 )
return V_31 ;
F_136 ( & V_8 -> V_67 , V_178 ) ;
F_59 ( V_8 -> V_99 ) -> V_261 = V_8 -> V_67 . V_97 ;
F_59 ( V_8 -> V_99 ) -> V_262 = F_26 ( V_8 ) ;
return 0 ;
}
static bool F_137 ( int V_263 )
{
return ( V_263 == V_264 ) ||
( V_263 == V_265 ) ||
( V_263 == V_266 ) ||
( V_263 == V_267 ) ||
( V_263 == V_268 ) ;
}
int F_138 ( struct V_7 * V_8 ,
struct V_269 * V_270 , bool V_271 ,
struct V_128 * T_9 V_94 , int T_10 V_94 ,
struct V_14 * V_272 , int V_273 )
{
int V_112 , V_274 ;
struct V_269 V_275 ;
struct V_276 * V_277 ;
void * V_278 ;
#if ( V_279 == 0 )
const bool V_280 = false ;
#else
bool V_280 = ! V_271 ;
#endif
int V_31 ;
if ( F_36 ( ! V_8 -> V_110 ) )
return 0 ;
V_270 = V_270 ? : & V_275 ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_277 = ( F_139 ( V_277 ) ) V_8 -> V_113 ;
V_112 = V_8 -> V_112 ;
if ( ( V_112 < ( int ) sizeof( * V_277 ) || ! V_277 -> V_281 ) ) {
F_13 ( L_44
L_45 ,
V_8 -> V_110 , V_112 , V_277 -> V_281 ) ;
goto V_282;
}
if ( ( V_277 -> V_283 != 0x72 ) && ( V_277 -> V_283 != 0x73 ) ) {
F_13 ( L_46 ,
V_277 -> V_283 , V_112 ) ;
goto V_282;
}
V_270 -> V_284 = V_277 -> V_281 ;
V_270 -> V_285 = F_34 ( V_277 -> V_286 ) ;
V_274 = V_277 -> V_287 + 8 ;
#if ( V_279 == 1 )
if ( V_280 )
V_280 = ( V_270 -> V_284 > V_288 ) ;
#endif
F_140 ( L_47
L_48 ,
V_270 -> V_284 , V_274 , V_112 ,
V_270 -> V_285 , V_8 -> V_109 ,
V_8 -> V_110 ) ;
if ( V_274 < V_112 )
V_112 = V_274 ;
V_278 = V_277 -> V_289 ;
V_112 -= sizeof( * V_277 ) ;
while ( V_112 > 0 ) {
struct V_290 * V_289 = V_278 ;
int V_291 = V_289 -> V_292 + 2 ;
V_112 -= V_291 ;
if ( V_112 < 0 )
break;
switch ( V_289 -> V_293 ) {
case V_294 :
case V_295 :
{
struct V_296
* V_297 = V_278 ;
V_270 -> V_298 =
F_19 ( & V_297 -> V_299 ) ;
F_141 (
L_49 ,
F_18 ( V_270 -> V_298 ) ) ;
break;
}
case V_300 :
{
struct V_301
* V_302 = V_278 ;
V_270 -> V_303 = F_142 ( & V_302 -> V_304 ) ;
F_141 (
L_50
L_51 ,
V_270 -> V_303 , V_302 -> V_305 ) ;
break;
}
case V_306 :
{
struct V_307
* V_308 = V_278 ;
V_270 -> V_309 =
F_143 ( V_308 -> V_310 ) ;
V_270 -> V_311 =
F_143 ( V_308 -> V_312 ) ;
V_270 -> V_129 . V_137 = F_144 ( V_308 -> V_313 ) ;
V_270 -> V_129 . V_139 = F_144 ( V_308 -> V_314 ) ;
F_141 (
L_52 ,
F_18 ( V_270 -> V_129 . V_137 ) , F_18 ( V_270 -> V_129 . V_139 ) ) ;
F_141 (
L_53
L_54 ,
V_270 -> V_309 ,
V_270 -> V_311 ) ;
break;
}
case V_315 :
{
struct V_316
* V_317 = V_278 ;
const unsigned V_38 =
sizeof( V_317 -> V_318 ) ;
char V_319 [ V_38 * 4 + 2 ] ;
F_20 ( V_317 -> V_318 , V_38 ,
32 , 1 , V_319 , sizeof( V_319 ) , true ) ;
F_141 ( L_55 , V_319 ) ;
}
case V_320 :
{
struct V_321
* V_322 = V_278 ;
unsigned V_38 = F_145 ( V_291 , V_112 ) ;
struct V_323 * V_324 = V_322 -> V_325 ;
while ( V_38 >= sizeof( * V_324 ) ) {
T_8 V_48 = F_35 ( V_324 -> V_48 ) ;
T_8 V_49 = F_35 ( V_324 -> V_49 ) ;
if ( ! V_270 -> V_47 . V_48 ) {
V_270 -> V_47 . V_48 = V_48 ;
V_270 -> V_47 . V_49 = V_49 ;
}
if ( V_272 && V_273 ) {
V_272 -> V_48 = V_48 ;
V_272 -> V_49 = V_49 ;
V_272 ++ ;
V_273 -- ;
}
V_38 -= sizeof( * V_324 ) ;
F_141 (
L_56
L_57 ,
V_48 , V_49 ) ;
}
}
case V_326 :
F_141 ( L_58 ) ;
break;
case V_327 :
F_141 ( L_59 ) ;
break;
case V_328 :
F_141 ( L_60 ) ;
break;
case V_329 :
F_141 ( L_61 ) ;
break;
default:
if ( V_289 -> V_293 <= V_330 )
F_141 (
L_62 ,
V_289 -> V_293 ) ;
else
F_141 (
L_63 ,
V_289 -> V_293 ) ;
}
V_278 += V_291 ;
}
V_282:
if ( ! V_270 -> V_284 ) {
if ( V_8 -> V_109 == V_331 )
V_270 -> V_332 = V_333 ;
else
V_270 -> V_332 = V_334 ;
V_31 = V_8 -> V_109 ;
} else if ( V_270 -> V_284 <= V_288 ) {
V_270 -> V_332 = 0 ;
V_31 = 0 ;
} else if ( V_270 -> V_285 == V_335 ) {
if ( V_270 -> V_336 == V_337 ) {
V_270 -> V_332 = V_338 ;
V_31 = - V_339 ;
} else if ( V_270 -> V_336 == V_340 ) {
V_270 -> V_332 = V_341 ;
V_31 = - V_342 ;
} else if ( V_270 -> V_336 == V_343 ) {
V_270 -> V_332 = V_344 ;
V_31 = - V_345 ;
} else {
V_270 -> V_332 = V_346 ;
V_31 = - V_193 ;
}
} else if ( V_270 -> V_285 == V_347 ) {
V_270 -> V_332 = V_348 ;
V_31 = - V_349 ;
} else if ( F_137 ( V_270 -> V_285 ) ) {
V_270 -> V_332 = V_346 ;
V_31 = - V_193 ;
} else {
V_270 -> V_332 = V_350 ;
V_31 = - V_118 ;
}
if ( ! V_8 -> V_35 . V_114 )
V_8 -> V_35 . V_114 = V_8 -> V_35 . V_125 ;
if ( ! V_8 -> V_116 . V_114 )
V_8 -> V_116 . V_114 = V_8 -> V_116 . V_125 ;
return V_31 ;
}
void F_146 ( void * V_11 ,
const struct V_128 * V_129 , bool V_351 , const bool V_229 )
{
struct V_1 * V_251 = V_11 ;
V_56 type ;
V_56 V_293 ;
if ( F_36 ( V_129 -> V_139 ) ) {
if ( F_21 ( V_351 ) ) {
type = V_352 ;
V_293 = V_229 ? V_353 :
V_354 ;
} else {
type = V_355 ;
V_293 = V_353 ;
}
F_85 ( ! V_129 -> V_137 ) ;
} else {
type = V_129 -> V_137 ? V_356 :
V_357 ;
V_293 = V_358 ;
}
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_130 . V_180 = V_359 ;
V_251 -> V_130 . V_360 = 0 ;
V_251 -> V_130 . V_361 = V_362 ;
V_251 -> V_130 . V_363 = type ;
F_147 ( & V_251 -> V_130 , V_364 ) ;
V_251 -> V_130 . V_365 = V_293 ;
V_251 -> V_10 . V_366 . V_367 = 0 ;
V_251 -> V_10 . V_366 . V_368 = F_72 ( V_129 -> V_137 ) ;
V_251 -> V_10 . V_366 . V_369 = F_72 ( V_129 -> V_139 ) ;
}
void F_135 ( struct V_79 * V_67 , const void * V_11 )
{
memcpy ( & V_67 -> V_68 . V_11 , V_11 , V_370 ) ;
}
bool F_129 ( struct V_78 * V_230 V_94 )
{
return false ;
}
void F_136 ( struct V_79 * V_80 V_94 , const V_56 * V_178 V_94 )
{
}
void F_105 ( void * T_11 V_94 ,
struct V_101 * V_101 V_94 , const V_56 * V_178 V_94 )
{
}
T_1 F_45 (
T_2 V_73 , unsigned * V_74 , int V_371 , int V_372 )
{
T_2 V_373 = - 1 , V_374 , V_375 ;
T_1 V_376 ;
int V_377 ;
* V_74 = 0 ;
if ( ! V_73 )
return 0 ;
for ( V_377 = V_371 ; V_377 < V_372 ; ++ V_377 ) {
V_373 = V_73 >> V_377 ;
if ( V_373 < ( 1 << V_378 ) )
break;
}
F_113 ( V_377 == V_372 ) ;
V_375 = 1 << V_377 ;
V_374 = V_73 & ( V_375 - 1 ) ;
if ( V_374 ) {
* V_74 = V_375 - V_374 ;
V_373 += 1 ;
}
V_373 |= ( ( V_377 - 8 ) & 0xf ) << 28 ;
V_376 = F_31 ( ( T_8 ) V_373 ) ;
F_25 ( L_64 ,
F_18 ( V_73 ) , F_18 ( V_373 & 0x0FFFFFFF ) , V_377 ,
V_376 , * V_74 ) ;
return V_376 ;
}
