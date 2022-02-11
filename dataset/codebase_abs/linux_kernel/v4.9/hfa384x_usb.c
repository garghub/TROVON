static inline const char * F_1 ( T_1 V_1 )
{
static const char * const V_2 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7
} ;
return V_2 [ V_1 ] ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 -> V_6 . V_7 . V_8 , struct V_3 , V_9 ) ;
}
void F_4 ( struct V_10 * V_10 )
{
F_5 ( L_8 , V_10 -> V_11 ) ;
F_5 ( L_9 , V_10 -> V_12 ) ;
F_5 ( L_10 , V_10 -> V_13 ) ;
F_5 ( L_11 ,
( unsigned int ) V_10 -> V_14 ) ;
F_5 ( L_12 ,
V_10 -> V_15 ) ;
F_5 ( L_13 , V_10 -> V_16 ) ;
F_5 ( L_14 , V_10 -> V_17 ) ;
F_5 ( L_15 ,
( unsigned int ) V_10 -> V_18 ) ;
F_5 ( L_16 , V_10 -> V_19 ) ;
F_5 ( L_17 , V_10 -> V_20 ) ;
F_5 ( L_18 , V_10 -> V_21 ) ;
F_5 ( L_19 , V_10 -> V_22 ) ;
F_5 ( L_20 , ( unsigned int ) V_10 -> V_23 ) ;
F_5 ( L_21 , ( unsigned int ) V_10 -> V_24 ) ;
}
static int F_6 ( struct V_4 * V_5 , T_2 V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
V_27 = F_7 ( sizeof( union V_29 ) ) ;
if ( ! V_27 ) {
V_28 = - V_30 ;
goto V_31;
}
F_8 ( & V_5 -> V_32 , V_5 -> V_33 ,
V_5 -> V_34 ,
V_27 -> V_35 , sizeof( union V_29 ) ,
V_36 , V_5 -> V_37 ) ;
V_5 -> V_38 = V_27 ;
V_28 = - V_39 ;
if ( ! V_5 -> V_37 -> V_40 &&
! F_9 ( V_41 , & V_5 -> V_42 ) ) {
V_28 = F_10 ( & V_5 -> V_32 , V_25 ) ;
if ( V_28 == - V_43 ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_22 ,
V_5 -> V_37 -> V_44 -> V_45 ) ;
if ( ! F_12 ( V_41 , & V_5 -> V_42 ) )
F_13 ( & V_5 -> V_46 ) ;
}
}
if ( V_28 != 0 ) {
F_14 ( V_27 ) ;
V_5 -> V_38 = NULL ;
}
V_31:
return V_28 ;
}
static int F_15 ( struct V_4 * V_5 , struct V_10 * V_47 , T_2 V_25 )
{
struct V_48 * V_44 = V_5 -> V_37 -> V_44 ;
int V_28 ;
V_28 = - V_39 ;
if ( F_16 ( V_44 ) ) {
if ( ! V_5 -> V_37 -> V_40 &&
! F_9 ( V_49 , & V_5 -> V_42 ) ) {
V_28 = F_10 ( V_47 , V_25 ) ;
if ( V_28 == - V_43 ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_23 ,
V_44 -> V_45 ) ;
F_17 ( V_49 , & V_5 -> V_42 ) ;
F_13 ( & V_5 -> V_46 ) ;
} else if ( V_28 == 0 ) {
F_18 ( V_44 ) ;
}
}
}
return V_28 ;
}
static void F_19 ( struct V_50 * V_35 )
{
struct V_4 * V_5 = F_20 ( V_35 , struct V_4 , V_46 ) ;
struct V_48 * V_44 = V_5 -> V_37 -> V_44 ;
if ( V_5 -> V_37 -> V_40 )
return;
if ( F_9 ( V_41 , & V_5 -> V_42 ) ) {
int V_51 ;
F_21 ( & V_5 -> V_32 ) ;
V_51 = F_22 ( V_5 -> V_33 , V_5 -> V_34 ) ;
if ( V_51 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_24 ,
V_44 -> V_45 , V_51 ) ;
} else {
F_24 ( V_5 -> V_37 -> V_44 , L_25 ,
V_44 -> V_45 ) ;
F_25 ( V_41 , & V_5 -> V_42 ) ;
F_17 ( V_52 , & V_5 -> V_42 ) ;
}
}
if ( F_9 ( V_52 , & V_5 -> V_42 ) ) {
int V_51 ;
V_51 = F_6 ( V_5 , V_53 ) ;
if ( V_51 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_26 ,
V_44 -> V_45 ) ;
} else {
F_25 ( V_52 , & V_5 -> V_42 ) ;
}
}
if ( F_9 ( V_49 , & V_5 -> V_42 ) ) {
int V_51 ;
F_21 ( & V_5 -> V_47 ) ;
V_51 = F_22 ( V_5 -> V_33 , V_5 -> V_54 ) ;
if ( V_51 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_27 ,
V_44 -> V_45 , V_51 ) ;
} else {
F_24 ( V_5 -> V_37 -> V_44 , L_28 ,
V_44 -> V_45 ) ;
F_25 ( V_49 , & V_5 -> V_42 ) ;
F_17 ( V_55 , & V_5 -> V_42 ) ;
F_26 ( V_5 ) ;
}
}
if ( F_27 ( V_55 , & V_5 -> V_42 ) )
F_28 ( V_5 -> V_37 -> V_44 ) ;
}
void F_29 ( struct V_4 * V_5 , struct V_56 * V_33 )
{
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_33 = V_33 ;
V_5 -> V_34 = F_30 ( V_33 , 1 ) ;
V_5 -> V_54 = F_31 ( V_33 , 2 ) ;
F_32 ( & V_5 -> V_57 ) ;
F_33 ( & V_5 -> V_6 . V_58 ) ;
F_34 ( & V_5 -> V_6 . V_59 ) ;
F_34 ( & V_5 -> V_6 . V_7 ) ;
F_34 ( & V_5 -> V_6 . V_60 ) ;
F_34 ( & V_5 -> V_6 . V_61 ) ;
F_35 ( & V_5 -> V_62 ) ;
F_36 ( & V_5 -> V_63 ,
V_64 , ( unsigned long ) V_5 ) ;
F_36 ( & V_5 -> V_65 ,
V_66 , ( unsigned long ) V_5 ) ;
F_37 ( & V_5 -> V_67 , V_68 ) ;
F_37 ( & V_5 -> V_46 , F_19 ) ;
F_38 ( & V_5 -> V_69 , V_70 , ( unsigned long ) V_5 ) ;
F_38 ( & V_5 -> V_71 , V_72 ,
( unsigned long ) V_5 ) ;
F_38 ( & V_5 -> V_73 , V_74 ,
( unsigned long ) V_5 ) ;
F_39 ( & V_5 -> V_32 ) ;
F_39 ( & V_5 -> V_47 ) ;
F_39 ( & V_5 -> V_75 ) ;
V_5 -> V_76 = V_77 ;
V_5 -> V_78 = V_79 ;
F_37 ( & V_5 -> V_80 , V_81 ) ;
F_38 ( & V_5 -> V_82 , V_83 ,
( unsigned long ) V_5 ) ;
}
void F_40 ( struct V_4 * V_5 )
{
struct V_26 * V_27 ;
if ( V_5 -> V_78 == V_84 )
F_41 ( V_5 ) ;
V_5 -> V_78 = V_85 ;
F_42 ( V_5 -> V_86 ) ;
V_5 -> V_86 = NULL ;
while ( ( V_27 = F_43 ( & V_5 -> V_62 ) ) )
F_14 ( V_27 ) ;
}
static struct V_3 * F_44 ( void )
{
struct V_3 * V_87 ;
V_87 = F_45 ( sizeof( * V_87 ) ,
F_46 () ? V_88 : V_53 ) ;
if ( V_87 )
F_47 ( & V_87 -> V_31 ) ;
return V_87 ;
}
static int
F_48 ( const struct V_89 * V_90 ,
struct V_91 * V_28 )
{
V_28 -> V_12 = F_49 ( V_90 -> V_12 ) ;
V_28 -> V_92 = F_49 ( V_90 -> V_92 ) ;
V_28 -> V_93 = F_49 ( V_90 -> V_93 ) ;
V_28 -> V_94 = F_49 ( V_90 -> V_94 ) ;
F_5 ( L_29 ,
V_28 -> V_12 , V_28 -> V_92 , V_28 -> V_93 , V_28 -> V_94 ) ;
return V_28 -> V_12 & V_95 ;
}
static void
F_50 ( const struct V_96 * V_97 ,
struct V_98 * V_28 )
{
V_28 -> V_99 = F_49 ( V_97 -> V_99 ) ;
V_28 -> V_100 = V_97 -> V_35 ;
V_28 -> V_101 = ( ( F_49 ( V_97 -> V_102 ) - 1 ) * 2 ) ;
}
static inline int F_51 ( struct V_103 * V_104 )
{
struct V_105 * V_24 ;
V_24 = (struct V_105 * ) V_104 ;
return F_48 ( V_24 -> V_90 , V_24 -> V_28 ) ;
}
static inline struct V_103 * F_52 (
struct V_105
* V_106 ,
const struct V_89
* V_90 ,
struct V_91 * V_28 )
{
V_106 -> V_104 . V_24 = F_51 ;
V_106 -> V_90 = V_90 ;
V_106 -> V_28 = V_28 ;
return & ( V_106 -> V_104 ) ;
}
static int F_53 ( struct V_103 * V_104 )
{
struct V_107 * V_24 ;
struct V_98 V_108 ;
V_24 = (struct V_107 * ) V_104 ;
F_50 ( V_24 -> V_97 , & V_108 ) ;
if ( V_108 . V_101 != V_24 -> V_109 ) {
F_54 ( L_30 ,
V_108 . V_99 ,
V_24 -> V_109 , V_108 . V_101 ) ;
return - V_110 ;
}
memcpy ( V_24 -> V_100 , V_108 . V_100 , V_24 -> V_109 ) ;
return 0 ;
}
static inline struct V_103 * F_55 (
struct V_107
* V_106 ,
const struct V_96
* V_97 ,
void * V_100 ,
unsigned int V_109 )
{
V_106 -> V_104 . V_24 = F_53 ;
V_106 -> V_97 = V_97 ;
V_106 -> V_100 = V_100 ;
V_106 -> V_109 = V_109 ;
return & ( V_106 -> V_104 ) ;
}
static int F_56 ( struct V_103 * V_104 )
{
struct V_111 * V_24 =
(struct V_111 * ) V_104 ;
F_5 ( L_31 , V_24 -> V_112 -> V_102 ) ;
memcpy ( V_24 -> V_35 , V_24 -> V_112 -> V_35 , V_24 -> V_113 ) ;
return 0 ;
}
static inline struct V_103 * F_57 (
struct V_111
* V_106 ,
struct V_114
* V_112 ,
void * V_35 ,
unsigned int V_113 )
{
V_106 -> V_104 . V_24 = F_56 ;
V_106 -> V_112 = V_112 ;
V_106 -> V_35 = V_35 ;
V_106 -> V_113 = V_113 ;
return & ( V_106 -> V_104 ) ;
}
static void F_58 ( struct V_4 * V_5 , const struct V_3 * V_87 )
{
if ( V_87 -> V_115 ) {
struct V_91 V_116 ;
if ( V_87 -> V_78 != V_117 ) {
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_12 =
F_59 ( V_118 ) ;
} else {
F_48 ( & V_87 -> V_119 . V_90 , & V_116 ) ;
}
V_87 -> V_115 ( V_5 , & V_116 , V_87 -> V_120 ) ;
}
}
static inline int F_60 ( struct V_4 * V_5 , struct V_121 * V_122 )
{
return F_61 ( V_5 , V_123 , V_122 , NULL , NULL , NULL ) ;
}
static inline int
F_62 ( struct V_4 * V_5 ,
struct V_121 * V_122 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
return F_61 ( V_5 , V_125 , V_122 , V_124 , V_115 , V_120 ) ;
}
static inline int
F_63 ( struct V_4 * V_5 , T_5 V_99 , void * V_100 ,
unsigned int V_109 )
{
return F_64 ( V_5 , V_123 ,
V_99 , V_100 , V_109 , NULL , NULL , NULL ) ;
}
static inline int
F_65 ( struct V_4 * V_5 ,
T_5 V_99 , void * V_100 , unsigned int V_109 ,
T_3 V_124 ,
T_4 V_115 , void * V_120 )
{
return F_64 ( V_5 , V_125 ,
V_99 , V_100 , V_109 ,
V_124 , V_115 , V_120 ) ;
}
static inline int
F_66 ( struct V_4 * V_5 , T_5 V_99 , void * V_100 ,
unsigned int V_109 )
{
return F_67 ( V_5 , V_123 ,
V_99 , V_100 , V_109 , NULL , NULL , NULL ) ;
}
static inline int
F_68 ( struct V_4 * V_5 ,
T_5 V_99 , void * V_100 , unsigned int V_109 ,
T_3 V_124 ,
T_4 V_115 , void * V_120 )
{
return F_67 ( V_5 , V_125 ,
V_99 , V_100 , V_109 ,
V_124 , V_115 , V_120 ) ;
}
static inline int
F_69 ( struct V_4 * V_5 ,
T_5 V_126 , T_5 V_127 , void * V_35 , unsigned int V_113 )
{
return F_70 ( V_5 , V_123 ,
V_126 , V_127 , V_35 , V_113 , NULL , NULL , NULL ) ;
}
static inline int
F_71 ( struct V_4 * V_5 ,
T_5 V_126 , T_5 V_127 , void * V_35 , unsigned int V_113 ,
T_3 V_124 ,
T_4 V_115 , void * V_120 )
{
return F_70 ( V_5 , V_125 ,
V_126 , V_127 , V_35 , V_113 ,
V_124 , V_115 , V_120 ) ;
}
static inline int
F_72 ( struct V_4 * V_5 ,
T_5 V_126 , T_5 V_127 , void * V_35 , unsigned int V_113 )
{
return F_73 ( V_5 , V_123 ,
V_126 , V_127 , V_35 , V_113 , NULL , NULL , NULL ) ;
}
static inline int
F_74 ( struct V_4 * V_5 ,
T_5 V_126 ,
T_5 V_127 ,
void * V_35 ,
unsigned int V_113 ,
T_3 V_124 ,
T_4 V_115 , void * V_120 )
{
return F_73 ( V_5 , V_125 ,
V_126 , V_127 , V_35 , V_113 ,
V_124 , V_115 , V_120 ) ;
}
int F_75 ( struct V_4 * V_5 )
{
int V_28 = 0 ;
int V_128 ;
struct V_121 V_122 ;
V_122 . V_122 = V_129 ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
V_28 = F_60 ( V_5 , & V_122 ) ;
F_5 ( L_32 ,
V_122 . V_28 . V_12 ,
V_122 . V_28 . V_92 , V_122 . V_28 . V_93 , V_122 . V_28 . V_94 ) ;
if ( V_28 == 0 ) {
for ( V_128 = 0 ; V_128 < V_133 ; V_128 ++ )
V_5 -> V_134 [ V_128 ] = 0 ;
}
V_5 -> V_76 = V_77 ;
return V_28 ;
}
int F_76 ( struct V_4 * V_5 , T_5 V_135 )
{
struct V_121 V_122 ;
V_122 . V_122 = F_77 ( V_136 ) |
F_78 ( V_135 ) ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
return F_60 ( V_5 , & V_122 ) ;
}
int F_79 ( struct V_4 * V_5 , T_5 V_135 )
{
struct V_121 V_122 ;
V_122 . V_122 = F_77 ( V_137 ) |
F_78 ( V_135 ) ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
return F_60 ( V_5 , & V_122 ) ;
}
int F_80 ( struct V_4 * V_5 , T_5 V_138 )
{
struct V_121 V_122 ;
V_122 . V_122 = F_77 ( V_139 ) |
F_81 ( V_138 ) ;
V_122 . V_130 = 0 ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
return F_60 ( V_5 , & V_122 ) ;
}
int F_82 ( struct V_4 * V_5 , T_5 V_140 , T_5 V_141 ,
T_5 V_142 , T_5 V_143 )
{
struct V_121 V_122 ;
F_5 ( L_33 ,
V_140 , V_141 , V_142 , V_143 ) ;
V_122 . V_122 = ( F_77 ( V_144 ) |
F_83 ( V_140 ) ) ;
V_122 . V_130 = V_141 ;
V_122 . V_131 = V_142 ;
V_122 . V_132 = V_143 ;
return F_60 ( V_5 , & V_122 ) ;
}
int F_84 ( struct V_4 * V_5 , int V_145 , int V_146 , int V_147 )
{
int V_28 ;
V_28 = F_85 ( V_5 -> V_33 ) ;
if ( V_28 < 0 ) {
F_23 ( V_5 -> V_37 -> V_44 , L_34 ,
V_28 ) ;
}
return V_28 ;
}
static int F_86 ( struct V_4 * V_5 ,
struct V_3 * V_87 ,
struct V_103 * V_106 )
{
unsigned long V_148 ;
int V_28 ;
V_28 = F_87 ( & V_87 -> V_31 ) ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_149:
if ( V_5 -> V_37 -> V_40 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_28 = - V_150 ;
} else if ( V_28 != 0 ) {
int V_151 = 0 ;
if ( V_87 == F_2 ( V_5 ) ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_90 ( & V_5 -> V_73 ) ;
F_90 ( & V_5 -> V_71 ) ;
V_5 -> V_152 = 1 ;
V_5 -> V_153 = 1 ;
F_21 ( & V_5 -> V_75 ) ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_151 = 1 ;
if ( V_5 -> V_37 -> V_40 )
goto V_149;
}
V_87 -> V_61 = 1 ;
V_87 -> V_78 = V_154 ;
F_91 ( & V_87 -> V_9 , & V_5 -> V_6 . V_60 ) ;
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( V_151 )
F_26 ( V_5 ) ;
} else {
if ( V_87 -> V_78 == V_117 ) {
V_28 = V_106 -> V_24 ( V_106 ) ;
} else {
F_11 ( V_5 -> V_37 -> V_44 , L_35 ,
F_49 ( V_87 -> V_155 . type ) ,
F_1 ( V_87 -> V_78 ) ) ;
V_28 = - V_156 ;
}
F_92 ( & V_87 -> V_9 ) ;
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_42 ( V_87 ) ;
}
return V_28 ;
}
static int
F_61 ( struct V_4 * V_5 ,
enum V_157 V_140 ,
struct V_121 * V_122 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
int V_28 ;
struct V_3 * V_87 ;
V_87 = F_44 () ;
if ( ! V_87 ) {
V_28 = - V_30 ;
goto V_31;
}
V_87 -> V_155 . V_158 . type = F_93 ( V_159 ) ;
V_87 -> V_155 . V_158 . V_122 = F_93 ( V_122 -> V_122 ) ;
V_87 -> V_155 . V_158 . V_130 = F_93 ( V_122 -> V_130 ) ;
V_87 -> V_155 . V_158 . V_131 = F_93 ( V_122 -> V_131 ) ;
V_87 -> V_155 . V_158 . V_132 = F_93 ( V_122 -> V_132 ) ;
V_87 -> V_160 = sizeof( V_87 -> V_155 . V_158 ) ;
F_5 ( L_36 ,
V_122 -> V_122 , V_122 -> V_130 , V_122 -> V_131 , V_122 -> V_132 ) ;
V_87 -> V_61 = V_140 ;
V_87 -> V_124 = V_124 ;
V_87 -> V_115 = V_115 ;
V_87 -> V_120 = V_120 ;
V_28 = F_94 ( V_5 , V_87 ) ;
if ( V_28 != 0 ) {
F_42 ( V_87 ) ;
} else if ( V_140 == V_123 ) {
struct V_105 V_106 ;
V_28 =
F_86 ( V_5 , V_87 ,
F_52 ( & V_106 ,
& V_87 ->
V_119 .
V_90 ,
& V_122 ->
V_28 ) ) ;
}
V_31:
return V_28 ;
}
static int
F_64 ( struct V_4 * V_5 ,
enum V_157 V_140 ,
T_5 V_99 ,
void * V_100 ,
unsigned int V_109 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
int V_28 ;
struct V_3 * V_87 ;
V_87 = F_44 () ;
if ( ! V_87 ) {
V_28 = - V_30 ;
goto V_31;
}
V_87 -> V_155 . V_161 . type = F_93 ( V_162 ) ;
V_87 -> V_155 . V_161 . V_102 =
F_93 ( sizeof( V_87 -> V_155 . V_161 . V_99 ) ) ;
V_87 -> V_155 . V_161 . V_99 = F_93 ( V_99 ) ;
V_87 -> V_160 = sizeof( V_87 -> V_155 . V_161 ) ;
V_87 -> V_61 = V_140 ;
V_87 -> V_124 = V_124 ;
V_87 -> V_115 = V_115 ;
V_87 -> V_120 = V_120 ;
V_28 = F_94 ( V_5 , V_87 ) ;
if ( V_28 != 0 ) {
F_42 ( V_87 ) ;
} else if ( V_140 == V_123 ) {
struct V_107 V_106 ;
V_28 =
F_86 ( V_5 , V_87 ,
F_55
( & V_106 ,
& V_87 -> V_119 . V_97 ,
V_100 , V_109 ) ) ;
}
V_31:
return V_28 ;
}
static int
F_67 ( struct V_4 * V_5 ,
enum V_157 V_140 ,
T_5 V_99 ,
void * V_100 ,
unsigned int V_109 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
int V_28 ;
struct V_3 * V_87 ;
V_87 = F_44 () ;
if ( ! V_87 ) {
V_28 = - V_30 ;
goto V_31;
}
V_87 -> V_155 . V_163 . type = F_93 ( V_164 ) ;
V_87 -> V_155 . V_163 . V_102 = F_93 ( ( sizeof
( V_87 -> V_155 . V_163 . V_99 ) +
V_109 + 1 ) / 2 ) ;
V_87 -> V_155 . V_163 . V_99 = F_93 ( V_99 ) ;
memcpy ( V_87 -> V_155 . V_163 . V_35 , V_100 , V_109 ) ;
V_87 -> V_160 = sizeof( V_87 -> V_155 . V_163 . type ) +
sizeof( V_87 -> V_155 . V_163 . V_102 ) +
sizeof( V_87 -> V_155 . V_163 . V_99 ) + V_109 ;
V_87 -> V_61 = V_140 ;
V_87 -> V_124 = V_124 ;
V_87 -> V_115 = V_115 ;
V_87 -> V_120 = V_120 ;
V_28 = F_94 ( V_5 , V_87 ) ;
if ( V_28 != 0 ) {
F_42 ( V_87 ) ;
} else if ( V_140 == V_123 ) {
struct V_105 V_106 ;
struct V_91 V_165 ;
V_28 = F_86 ( V_5 ,
V_87 ,
F_95
( & V_106 ,
& V_87 -> V_119 . V_166 ,
& V_165 ) ) ;
}
V_31:
return V_28 ;
}
static int
F_70 ( struct V_4 * V_5 ,
enum V_157 V_140 ,
T_5 V_126 ,
T_5 V_127 ,
void * V_35 ,
unsigned int V_113 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
int V_28 ;
struct V_3 * V_87 ;
V_87 = F_44 () ;
if ( ! V_87 ) {
V_28 = - V_30 ;
goto V_31;
}
V_87 -> V_155 . V_167 . type = F_93 ( V_168 ) ;
V_87 -> V_155 . V_167 . V_102 =
F_93 ( sizeof( V_87 -> V_155 . V_167 . V_127 ) +
sizeof( V_87 -> V_155 . V_167 . V_126 ) + V_113 ) ;
V_87 -> V_155 . V_167 . V_127 = F_93 ( V_127 ) ;
V_87 -> V_155 . V_167 . V_126 = F_93 ( V_126 ) ;
V_87 -> V_160 = sizeof( V_87 -> V_155 . V_167 ) ;
F_5 ( L_37 ,
V_87 -> V_155 . V_167 . type ,
V_87 -> V_155 . V_167 . V_102 ,
V_87 -> V_155 . V_167 . V_127 , V_87 -> V_155 . V_167 . V_126 ) ;
F_5 ( L_38 , F_96 ( sizeof( V_87 -> V_155 . V_167 ) ) ) ;
V_87 -> V_61 = V_140 ;
V_87 -> V_124 = V_124 ;
V_87 -> V_115 = V_115 ;
V_87 -> V_120 = V_120 ;
V_28 = F_94 ( V_5 , V_87 ) ;
if ( V_28 != 0 ) {
F_42 ( V_87 ) ;
} else if ( V_140 == V_123 ) {
struct V_111 V_106 ;
V_28 =
F_86 ( V_5 , V_87 ,
F_57
( & V_106 ,
& V_87 -> V_119 . V_112 , V_35 ,
V_113 ) ) ;
}
V_31:
return V_28 ;
}
static int
F_73 ( struct V_4 * V_5 ,
enum V_157 V_140 ,
T_5 V_126 ,
T_5 V_127 ,
void * V_35 ,
unsigned int V_113 ,
T_3 V_124 , T_4 V_115 , void * V_120 )
{
int V_28 ;
struct V_3 * V_87 ;
F_5 ( L_39 , V_126 , V_127 , V_113 ) ;
V_87 = F_44 () ;
if ( ! V_87 ) {
V_28 = - V_30 ;
goto V_31;
}
V_87 -> V_155 . V_169 . type = F_93 ( V_170 ) ;
V_87 -> V_155 . V_169 . V_102 =
F_93 ( sizeof( V_87 -> V_155 . V_169 . V_127 ) +
sizeof( V_87 -> V_155 . V_169 . V_126 ) + V_113 ) ;
V_87 -> V_155 . V_169 . V_127 = F_93 ( V_127 ) ;
V_87 -> V_155 . V_169 . V_126 = F_93 ( V_126 ) ;
memcpy ( V_87 -> V_155 . V_169 . V_35 , V_35 , V_113 ) ;
V_87 -> V_160 = sizeof( V_87 -> V_155 . V_169 . type ) +
sizeof( V_87 -> V_155 . V_169 . V_102 ) +
sizeof( V_87 -> V_155 . V_169 . V_127 ) +
sizeof( V_87 -> V_155 . V_169 . V_126 ) + V_113 ;
V_87 -> V_61 = V_140 ;
V_87 -> V_124 = V_124 ;
V_87 -> V_115 = V_115 ;
V_87 -> V_120 = V_120 ;
V_28 = F_94 ( V_5 , V_87 ) ;
if ( V_28 != 0 ) {
F_42 ( V_87 ) ;
} else if ( V_140 == V_123 ) {
struct V_105 V_106 ;
struct V_91 V_171 ;
V_28 = F_86 ( V_5 ,
V_87 ,
F_97
( & V_106 ,
& V_87 -> V_119 . V_172 ,
& V_171 ) ) ;
}
V_31:
return V_28 ;
}
int F_98 ( struct V_4 * V_5 , T_5 V_135 )
{
int V_28 = 0 ;
if ( ( ! V_5 -> V_173 && V_135 != 0 ) ||
( V_5 -> V_173 && ! ( V_135 <= V_174 ) ) ||
! ( V_5 -> V_134 [ V_135 ] ) ) {
V_28 = - V_175 ;
} else {
V_28 = F_76 ( V_5 , V_135 ) ;
if ( V_28 == 0 )
V_5 -> V_134 [ V_135 ] = 0 ;
}
return V_28 ;
}
int F_99 ( struct V_4 * V_5 , T_5 V_135 )
{
int V_28 = 0 ;
if ( ( ! V_5 -> V_173 && V_135 != 0 ) ||
( V_5 -> V_173 && ! ( V_135 <= V_174 ) ) ||
( V_5 -> V_134 [ V_135 ] ) ) {
V_28 = - V_175 ;
} else {
V_28 = F_79 ( V_5 , V_135 ) ;
if ( V_28 == 0 )
V_5 -> V_134 [ V_135 ] = 1 ;
}
return V_28 ;
}
int F_100 ( struct V_4 * V_5 )
{
int V_28 = 0 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_174 ; V_128 ++ ) {
if ( V_5 -> V_134 [ V_128 ] ) {
F_5 ( L_40 ) ;
return - V_175 ;
}
}
if ( V_5 -> V_176 != V_177 )
return - V_175 ;
V_28 = F_101 ( V_5 , V_178 ,
& ( V_5 -> V_179 ) , sizeof( V_5 -> V_179 ) ) ;
if ( V_28 )
return V_28 ;
V_5 -> V_179 . V_126 = F_49 ( V_5 -> V_179 . V_126 ) ;
V_5 -> V_179 . V_127 = F_49 ( V_5 -> V_179 . V_127 ) ;
V_5 -> V_179 . V_113 = F_49 ( V_5 -> V_179 . V_113 ) ;
V_28 = F_102 ( V_5 , V_180 ,
& ( V_5 -> V_181 ) ) ;
if ( V_28 )
return V_28 ;
V_5 -> V_181 = F_49 ( V_5 -> V_181 ) ;
F_5 ( L_41 ) ;
V_5 -> V_176 = V_182 ;
return V_28 ;
}
int F_103 ( struct V_4 * V_5 )
{
if ( V_5 -> V_176 != V_182 )
return - V_175 ;
F_5 ( L_41 ) ;
F_82 ( V_5 , V_183 , 0 , 0 , 0 ) ;
V_5 -> V_176 = V_177 ;
return 0 ;
}
int F_104 ( struct V_4 * V_5 , T_6 V_184 , void * V_185 , T_6 V_113 )
{
int V_28 = 0 ;
T_6 V_186 ;
int V_187 ;
T_6 V_188 ;
T_6 V_189 ;
T_5 V_190 ;
T_5 V_191 ;
int V_192 ;
T_7 * V_193 ;
T_5 V_194 ;
T_5 V_195 ;
T_6 V_196 ;
int V_128 ;
int V_197 ;
F_5 ( L_42 , V_184 , V_113 ) ;
if ( V_5 -> V_176 != V_182 )
return - V_175 ;
F_24 ( V_5 -> V_37 -> V_44 ,
L_43 , V_113 , V_184 ) ;
V_186 =
F_105 ( V_5 -> V_179 . V_126 , V_5 -> V_179 . V_127 ) ;
F_5 ( L_44 ,
V_5 -> V_179 . V_126 , V_5 -> V_179 . V_127 , V_186 ) ;
V_187 = V_113 / V_5 -> V_179 . V_113 ;
V_187 += ( V_113 % V_5 -> V_179 . V_113 ) ? 1 : 0 ;
V_192 = V_5 -> V_179 . V_113 / V_198 ;
V_192 += ( V_5 -> V_179 . V_113 % V_198 ) ? 1 : 0 ;
for ( V_128 = 0 ; V_128 < V_187 ; V_128 ++ ) {
V_188 = ( V_113 - ( V_5 -> V_179 . V_113 * V_128 ) ) > V_5 -> V_179 . V_113 ?
V_5 -> V_179 . V_113 : ( V_113 - ( V_5 -> V_179 . V_113 * V_128 ) ) ;
V_189 = V_184 + ( V_5 -> V_179 . V_113 * V_128 ) ;
V_190 = F_106 ( V_189 ) ;
V_191 = F_107 ( V_189 ) ;
F_24 ( V_5 -> V_37 -> V_44 , L_45 ,
V_188 , V_189 ) ;
V_28 = F_82 ( V_5 , V_199 ,
V_190 , V_191 , V_188 ) ;
if ( V_28 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_46 ,
V_190 , V_191 , V_188 , V_28 ) ;
goto V_200;
}
for ( V_197 = 0 ; V_197 < V_192 ; V_197 ++ ) {
V_193 = V_185 +
( V_128 * V_5 -> V_179 . V_113 ) +
( V_197 * V_198 ) ;
V_194 = F_107 ( V_186 +
( V_197 * V_198 ) ) ;
V_195 = F_106 ( V_186 +
( V_197 * V_198 ) ) ;
V_196 = V_188 - ( V_197 * V_198 ) ;
V_196 = V_196 > V_198 ?
V_198 : V_196 ;
V_28 = F_72 ( V_5 ,
V_194 ,
V_195 ,
V_193 , V_196 ) ;
}
V_28 = F_82 ( V_5 ,
V_201 ,
0 , 0 , 0 ) ;
if ( V_28 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_47 ,
V_190 , V_191 , V_188 , V_28 ) ;
goto V_200;
}
}
V_200:
return V_28 ;
}
int F_101 ( struct V_4 * V_5 , T_5 V_99 , void * V_185 , T_5 V_113 )
{
return F_63 ( V_5 , V_99 , V_185 , V_113 ) ;
}
int
F_108 ( struct V_4 * V_5 ,
T_5 V_99 ,
void * V_185 ,
T_5 V_113 , T_4 V_115 , void * V_120 )
{
return F_68 ( V_5 , V_99 , V_185 , V_113 ,
F_58 , V_115 , V_120 ) ;
}
int F_109 ( struct V_4 * V_5 )
{
if ( V_5 -> V_176 != V_202 )
return - V_175 ;
F_5 ( L_48 ) ;
F_82 ( V_5 , V_183 , 0 , 0 , 0 ) ;
V_5 -> V_176 = V_177 ;
return 0 ;
}
int F_110 ( struct V_4 * V_5 , T_6 V_203 )
{
int V_28 = 0 ;
T_5 V_141 ;
T_5 V_204 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_174 ; V_128 ++ ) {
if ( V_5 -> V_134 [ V_128 ] ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_49 ) ;
return - V_175 ;
}
}
if ( V_5 -> V_176 != V_177 ) {
F_23 ( V_5 -> V_37 -> V_44 , L_50 ) ;
return - V_175 ;
}
F_5 ( L_51 , V_203 ) ;
V_141 = F_106 ( V_203 ) ;
V_204 = F_107 ( V_203 ) ;
V_28 = F_82 ( V_5 , V_205 ,
V_141 , V_204 , 0 ) ;
if ( V_28 == 0 ) {
V_5 -> V_176 = V_202 ;
} else {
F_5 ( L_52 ,
V_141 , V_204 , V_28 ) ;
}
return V_28 ;
}
int F_111 ( struct V_4 * V_5 , T_6 V_184 , void * V_185 , T_6 V_113 )
{
int V_28 = 0 ;
int V_192 ;
T_7 * V_35 = V_185 ;
int V_128 ;
T_6 V_206 ;
T_5 V_207 ;
T_5 V_208 ;
T_5 V_209 ;
if ( V_5 -> V_176 != V_202 )
return - V_175 ;
F_24 ( V_5 -> V_37 -> V_44 , L_53 ,
V_113 , V_184 ) ;
V_192 = V_113 / V_198 ;
V_192 += V_113 % V_198 ? 1 : 0 ;
for ( V_128 = 0 ; V_128 < V_192 ; V_128 ++ ) {
V_206 = V_184 + ( V_128 * V_198 ) ;
V_207 = F_107 ( V_206 ) ;
V_208 = F_106 ( V_206 ) ;
V_209 = V_113 - ( V_128 * V_198 ) ;
if ( V_209 > V_198 )
V_209 = V_198 ;
V_28 = F_72 ( V_5 ,
V_207 ,
V_208 ,
V_35 +
( V_128 * V_198 ) ,
V_209 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
int F_112 ( struct V_4 * V_5 , void * V_185 , unsigned int V_113 )
{
int V_28 = 0 ;
T_5 * V_210 = V_185 ;
int V_211 = 0 ;
int V_212 = 1 ;
int V_213 = 0 ;
T_8 V_128 ;
T_5 V_214 ;
T_5 V_215 ;
T_5 V_207 ;
T_5 V_208 ;
struct V_216 {
T_6 V_217 ;
T_5 V_218 ;
} V_216 [] = {
{
V_219 , 0 } , {
V_220 , 0 } , {
V_221 , 0 }
} ;
for ( V_128 = 0 ; V_128 < F_113 ( V_216 ) ; V_128 ++ ) {
V_207 = F_107 ( V_216 [ V_128 ] . V_217 ) ;
V_208 = F_106 ( V_216 [ V_128 ] . V_217 ) ;
V_28 = F_69 ( V_5 , V_207 , V_208 , V_185 ,
V_113 ) ;
if ( V_28 ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_54 ,
V_128 ) ;
continue;
}
V_211 = 1 ;
V_212 = 1 ;
while ( V_211 && V_212 ) {
V_214 = F_49 ( V_210 [ V_213 ] ) * 2 ;
V_215 = F_49 ( V_210 [ V_213 + 1 ] ) ;
if ( V_214 > V_222 || V_214 == 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_55 , V_214 ) ;
V_211 = 0 ;
break;
}
if ( ! F_114 ( V_215 ) ) {
F_23 ( V_5 -> V_37 -> V_44 , L_56 ,
V_215 ) ;
V_211 = 0 ;
break;
}
if ( V_215 == V_223 )
V_212 = 0 ;
if ( V_212 ) {
V_213 += F_49 ( V_210 [ V_213 ] ) + 1 ;
}
}
if ( V_211 ) {
F_24 ( V_5 -> V_37 -> V_44 ,
L_57 ,
V_216 [ V_128 ] . V_217 ,
V_216 [ V_128 ] . V_218 == 0 ? L_58 :
V_216 [ V_128 ] . V_218 == 1 ? L_59 :
V_216 [ V_128 ] . V_218 == 2 ? L_60 :
V_216 [ V_128 ] . V_218 == 3 ? L_61 :
L_62 ) ;
break;
}
}
V_28 = V_211 ? 0 : - V_110 ;
if ( V_28 )
F_5 ( L_63 ) ;
return V_28 ;
}
int F_115 ( struct V_4 * V_5 , T_5 V_99 , void * V_185 , T_5 V_113 )
{
return F_66 ( V_5 , V_99 , V_185 , V_113 ) ;
}
int F_116 ( struct V_4 * V_5 )
{
int V_28 , V_224 , V_225 ;
T_5 V_12 ;
F_117 () ;
V_28 =
F_118 ( V_5 -> V_33 , V_226 , V_5 -> V_34 , & V_12 ) ;
if ( V_28 < 0 ) {
F_23 ( V_5 -> V_37 -> V_44 , L_64 ) ;
goto V_31;
}
if ( ( V_12 == 1 ) && F_22 ( V_5 -> V_33 , V_5 -> V_34 ) )
F_23 ( V_5 -> V_37 -> V_44 , L_65 ) ;
V_28 =
F_118 ( V_5 -> V_33 , V_226 , V_5 -> V_54 , & V_12 ) ;
if ( V_28 < 0 ) {
F_23 ( V_5 -> V_37 -> V_44 , L_66 ) ;
goto V_31;
}
if ( ( V_12 == 1 ) && F_22 ( V_5 -> V_33 , V_5 -> V_54 ) )
F_23 ( V_5 -> V_37 -> V_44 , L_67 ) ;
F_21 ( & V_5 -> V_32 ) ;
V_28 = F_6 ( V_5 , V_53 ) ;
if ( V_28 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_68 ,
V_28 ) ;
goto V_31;
}
V_224 = F_75 ( V_5 ) ;
F_119 ( 1000 ) ;
V_28 = F_75 ( V_5 ) ;
V_225 = V_28 ;
if ( V_224 != 0 ) {
if ( V_225 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_69 ,
V_224 , V_225 ) ;
F_21 ( & V_5 -> V_32 ) ;
goto V_31;
} else {
F_5 ( L_70 ,
V_224 ) ;
F_5 ( L_71 ) ;
}
} else if ( V_225 != 0 ) {
F_11 ( V_5 -> V_37 -> V_44 , L_72 ,
V_225 ) ;
F_11 ( V_5 -> V_37 -> V_44 ,
L_73 ) ;
goto V_31;
}
V_5 -> V_78 = V_84 ;
V_31:
return V_28 ;
}
int F_41 ( struct V_4 * V_5 )
{
int V_128 ;
F_117 () ;
if ( ! V_5 -> V_37 -> V_40 ) {
F_75 ( V_5 ) ;
F_21 ( & V_5 -> V_32 ) ;
}
V_5 -> V_76 = V_77 ;
V_5 -> V_78 = V_79 ;
F_120 ( & V_5 -> V_82 ) ;
for ( V_128 = 0 ; V_128 < V_133 ; V_128 ++ )
V_5 -> V_134 [ V_128 ] = 0 ;
return 0 ;
}
int F_121 ( struct V_4 * V_5 , struct V_26 * V_27 ,
union V_227 * V_227 ,
struct V_228 * V_229 )
{
int V_230 = sizeof( struct V_231 ) ;
int V_28 ;
int V_51 ;
char * V_232 ;
if ( V_5 -> V_47 . V_12 == - V_233 ) {
F_11 ( V_5 -> V_37 -> V_44 , L_74 ) ;
V_28 = 3 ;
goto exit;
}
memset ( & V_5 -> V_234 . V_235 . V_236 , 0 , sizeof( V_5 -> V_234 . V_235 . V_236 ) ) ;
V_5 -> V_234 . type = F_93 ( V_237 ) ;
V_5 -> V_234 . V_235 . V_236 . V_238 = 0x0123 ;
#if F_122 ( V_239 )
V_5 -> V_234 . V_235 . V_236 . V_240 =
F_123 ( 0 ) | F_124 ( 1 ) |
F_125 ( 1 ) | F_126 ( 1 ) ;
#elif F_122 ( V_241 )
V_5 -> V_234 . V_235 . V_236 . V_240 =
F_123 ( 0 ) | F_124 ( 1 ) |
F_125 ( 1 ) | F_126 ( 0 ) ;
#else
V_5 -> V_234 . V_235 . V_236 . V_240 =
F_123 ( 0 ) | F_124 ( 1 ) |
F_125 ( 0 ) | F_126 ( 0 ) ;
#endif
V_5 -> V_234 . V_235 . V_236 . V_240 =
F_93 ( V_5 -> V_234 . V_235 . V_236 . V_240 ) ;
memcpy ( & ( V_5 -> V_234 . V_235 . V_236 . V_242 ) , V_227 ,
sizeof( union V_227 ) ) ;
if ( V_229 -> V_35 ) {
V_5 -> V_234 . V_235 . V_236 . V_243 = F_93 ( V_27 -> V_113 + 8 ) ;
V_230 += 8 ;
} else {
V_5 -> V_234 . V_235 . V_236 . V_243 = F_93 ( V_27 -> V_113 ) ;
}
V_230 += V_27 -> V_113 ;
V_232 = V_5 -> V_234 . V_235 . V_35 ;
if ( V_229 -> V_35 ) {
memcpy ( V_232 , V_229 -> V_244 , sizeof( V_229 -> V_244 ) ) ;
V_232 += sizeof( V_229 -> V_244 ) ;
memcpy ( V_232 , V_229 -> V_35 , V_27 -> V_113 ) ;
} else {
memcpy ( V_232 , V_27 -> V_35 , V_27 -> V_113 ) ;
}
V_232 += V_27 -> V_113 ;
if ( V_229 -> V_35 )
memcpy ( V_232 , V_229 -> V_245 , sizeof( V_229 -> V_245 ) ) ;
F_8 ( & ( V_5 -> V_47 ) , V_5 -> V_33 ,
V_5 -> V_54 ,
& ( V_5 -> V_234 ) , F_96 ( V_230 ) ,
V_246 , V_5 -> V_37 ) ;
V_5 -> V_47 . V_13 |= V_247 ;
V_28 = 1 ;
V_51 = F_15 ( V_5 , & V_5 -> V_47 , V_88 ) ;
if ( V_51 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_75 , V_51 ) ;
V_28 = 3 ;
}
exit:
return V_28 ;
}
void F_127 ( struct V_248 * V_37 )
{
struct V_4 * V_5 = V_37 -> V_249 ;
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( ! V_5 -> V_37 -> V_40 ) {
int V_250 ;
V_250 = ! F_12 ( V_49 , & V_5 -> V_42 ) ;
V_250 |= ! F_12 ( V_41 , & V_5 -> V_42 ) ;
if ( V_250 )
F_13 ( & V_5 -> V_46 ) ;
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static void V_64 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
struct V_3 * V_87 , * V_251 ;
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_128 (ctlx, temp, &hw->ctlxq.reapable, list) {
F_92 ( & V_87 -> V_9 ) ;
F_42 ( V_87 ) ;
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static void V_66 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
struct V_3 * V_87 , * V_251 ;
unsigned long V_148 ;
int V_252 = 0 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_128 (ctlx, temp, &hw->ctlxq.completing, list) {
if ( V_87 -> V_124 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_87 -> V_124 ( V_5 , V_87 ) ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_87 -> V_124 = NULL ;
if ( V_5 -> V_37 -> V_40 ) {
V_252 = 0 ;
break;
}
}
if ( V_87 -> V_61 ) {
F_91 ( & V_87 -> V_9 , & V_5 -> V_6 . V_61 ) ;
V_252 = 1 ;
}
V_24 ( & V_87 -> V_31 ) ;
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( V_252 )
F_129 ( & V_5 -> V_63 ) ;
}
static int F_130 ( struct V_4 * V_5 ,
struct V_3 * V_87 )
{
int V_51 ;
V_5 -> V_75 . V_13 |= V_253 ;
V_51 = F_131 ( & V_5 -> V_75 ) ;
if ( V_51 != - V_233 ) {
V_87 -> V_78 = V_154 ;
F_132 ( V_5 , V_87 ) ;
V_51 = 0 ;
}
return V_51 ;
}
static void F_132 ( struct V_4 * V_5 , struct V_3 * V_87 )
{
F_91 ( & V_87 -> V_9 , & V_5 -> V_6 . V_60 ) ;
F_129 ( & V_5 -> V_65 ) ;
switch ( V_87 -> V_78 ) {
case V_117 :
case V_154 :
break;
default:
F_23 ( V_5 -> V_37 -> V_44 , L_76 ,
F_49 ( V_87 -> V_155 . type ) ,
F_1 ( V_87 -> V_78 ) ) ;
break;
}
}
static void F_26 ( struct V_4 * V_5 )
{
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( ! F_133 ( & V_5 -> V_6 . V_7 ) ||
F_9 ( V_49 , & V_5 -> V_42 ) || V_5 -> V_37 -> V_40 )
goto V_254;
while ( ! F_133 ( & V_5 -> V_6 . V_59 ) ) {
struct V_3 * V_104 ;
int V_28 ;
V_104 = F_3 ( V_5 -> V_6 . V_59 . V_8 ,
struct V_3 , V_9 ) ;
F_91 ( & V_104 -> V_9 , & V_5 -> V_6 . V_7 ) ;
F_8 ( & ( V_5 -> V_75 ) , V_5 -> V_33 ,
V_5 -> V_54 ,
& ( V_104 -> V_155 ) , F_96 ( V_104 -> V_160 ) ,
V_255 , V_5 ) ;
V_5 -> V_75 . V_13 |= V_247 ;
V_28 = F_10 ( & V_5 -> V_75 , V_88 ) ;
if ( V_28 == 0 ) {
V_104 -> V_78 = V_256 ;
V_5 -> V_152 = 0 ;
V_5 -> V_73 . V_257 = V_258 + V_259 ;
F_134 ( & V_5 -> V_73 ) ;
V_5 -> V_153 = 0 ;
V_5 -> V_71 . V_257 = V_258 + 2 * V_259 ;
F_134 ( & V_5 -> V_71 ) ;
break;
}
if ( V_28 == - V_43 ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_23 ,
V_5 -> V_37 -> V_44 -> V_45 ) ;
F_135 ( & V_104 -> V_9 , & V_5 -> V_6 . V_59 ) ;
F_17 ( V_49 , & V_5 -> V_42 ) ;
F_13 ( & V_5 -> V_46 ) ;
break;
}
if ( V_28 == - V_260 ) {
F_11 ( V_5 -> V_37 -> V_44 , L_77 ,
V_5 -> V_37 -> V_44 -> V_45 ) ;
break;
}
F_23 ( V_5 -> V_37 -> V_44 , L_78 ,
F_49 ( V_104 -> V_155 . type ) , V_28 ) ;
F_132 ( V_5 , V_104 ) ;
}
V_254:
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static void V_36 ( struct V_10 * V_10 )
{
struct V_248 * V_37 = V_10 -> V_23 ;
struct V_4 * V_5 ;
union V_29 * V_261 = (union V_29 * ) V_10 -> V_14 ;
struct V_26 * V_27 = NULL ;
int V_28 ;
int V_262 ;
T_5 type ;
enum T_9 {
V_263 ,
V_264 ,
ABORT
} V_265 ;
if ( ! V_37 || ! V_37 -> V_44 || V_37 -> V_40 )
goto exit;
V_5 = V_37 -> V_249 ;
if ( ! V_5 )
goto exit;
V_27 = V_5 -> V_38 ;
F_136 ( ! V_27 || ( V_27 -> V_35 != V_10 -> V_14 ) ) ;
V_5 -> V_38 = NULL ;
switch ( V_10 -> V_12 ) {
case 0 :
V_265 = V_263 ;
if ( V_10 -> V_16 == 0 ) {
V_37 -> V_44 -> V_266 . V_267 ++ ;
V_37 -> V_44 -> V_266 . V_268 ++ ;
V_265 = V_264 ;
}
break;
case - V_43 :
F_11 ( V_5 -> V_37 -> V_44 , L_22 ,
V_37 -> V_44 -> V_45 ) ;
if ( ! F_12 ( V_41 , & V_5 -> V_42 ) )
F_13 ( & V_5 -> V_46 ) ;
V_37 -> V_44 -> V_266 . V_267 ++ ;
V_265 = ABORT ;
break;
case - V_269 :
case - V_270 :
case - V_271 :
if ( ! F_12 ( V_272 , & V_5 -> V_42 ) &&
! F_137 ( & V_5 -> V_69 ) ) {
F_138 ( & V_5 -> V_69 , V_258 + V_273 ) ;
}
V_37 -> V_44 -> V_266 . V_267 ++ ;
V_265 = ABORT ;
break;
case - V_274 :
V_37 -> V_44 -> V_266 . V_275 ++ ;
V_265 = V_264 ;
break;
case - V_150 :
case - V_260 :
F_5 ( L_79 , V_10 -> V_12 ) ;
V_265 = ABORT ;
break;
case - V_276 :
case - V_277 :
F_5 ( L_80 , V_10 -> V_12 ) ;
V_265 = ABORT ;
break;
default:
F_5 ( L_81 ,
V_10 -> V_12 , V_10 -> V_13 ) ;
V_37 -> V_44 -> V_266 . V_267 ++ ;
V_265 = V_264 ;
break;
}
V_262 = V_10 -> V_12 ;
if ( V_265 != ABORT ) {
V_28 = F_6 ( V_5 , V_88 ) ;
if ( V_28 != 0 ) {
F_23 ( V_5 -> V_37 -> V_44 ,
L_82 ,
V_28 ) ;
}
}
type = F_49 ( V_261 -> type ) ;
if ( F_139 ( type ) ) {
if ( V_265 == V_263 ) {
if ( V_261 -> V_235 . V_236 . V_238 == 0x0123 ) {
F_140 ( V_37 , V_261 ) ;
} else {
F_141 ( V_27 , sizeof( * V_261 ) ) ;
F_142 ( V_37 , V_27 ) ;
V_27 = NULL ;
}
}
goto exit;
}
if ( F_143 ( type ) ) {
if ( V_265 == V_263 )
F_140 ( V_37 , V_261 ) ;
goto exit;
}
switch ( type ) {
case V_278 :
if ( V_265 == ABORT )
goto exit;
if ( V_265 == V_263 )
F_144 ( V_37 , V_261 ) ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
F_145 ( V_5 , V_261 , V_262 ) ;
break;
case V_284 :
F_5 ( L_83 ,
V_261 -> V_285 . V_102 ) ;
break;
case V_286 :
F_5 ( L_84 ,
V_261 -> V_287 . V_288 ) ;
break;
default:
F_5 ( L_85 ,
V_261 -> type , V_262 ) ;
break;
}
exit:
if ( V_27 )
F_14 ( V_27 ) ;
}
static void F_145 ( struct V_4 * V_5 , union V_29 * V_261 ,
int V_262 )
{
struct V_3 * V_87 ;
int V_289 = 0 ;
unsigned long V_148 ;
V_290:
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( F_133 ( & V_5 -> V_6 . V_7 ) )
goto V_254;
if ( F_146 ( & V_5 -> V_71 ) == 0 ) {
if ( V_5 -> V_153 == 0 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
goto V_290;
}
} else {
V_5 -> V_153 = 1 ;
}
V_87 = F_2 ( V_5 ) ;
if ( V_262 != 0 ) {
if ( F_130 ( V_5 , V_87 ) == 0 )
V_289 = 1 ;
} else {
const T_10 V_291 = ( V_261 -> type & ~ F_93 ( 0x8000 ) ) ;
if ( V_87 -> V_155 . type != V_291 ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_86 ,
F_49 ( V_87 -> V_155 . type ) ,
F_49 ( V_291 ) ) ;
goto V_254;
}
memcpy ( & V_87 -> V_119 , V_261 , sizeof( V_87 -> V_119 ) ) ;
switch ( V_87 -> V_78 ) {
case V_256 :
F_5 ( L_87 ) ;
V_87 -> V_78 = V_292 ;
break;
case V_293 :
V_87 -> V_78 = V_117 ;
F_132 ( V_5 , V_87 ) ;
V_289 = 1 ;
break;
default:
F_23 ( V_5 -> V_37 -> V_44 ,
L_88 ,
F_49 ( V_87 -> V_155 . type ) ,
F_1 ( V_87 -> V_78 ) ) ;
if ( F_130 ( V_5 , V_87 ) == 0 )
V_289 = 1 ;
break;
}
}
V_254:
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( V_289 )
F_26 ( V_5 ) ;
}
static void F_140 ( struct V_248 * V_37 ,
union V_29 * V_261 )
{
T_5 V_12 ;
V_12 = F_49 ( V_261 -> type ) ;
if ( F_147 ( V_12 ) )
F_148 ( V_37 , V_12 ) ;
else
F_149 ( V_37 , V_12 ) ;
}
static void F_142 ( struct V_248 * V_37 , struct V_26 * V_27 )
{
union V_29 * V_261 = (union V_29 * ) V_27 -> V_35 ;
struct V_4 * V_5 = V_37 -> V_249 ;
int V_294 ;
struct V_295 * V_296 ;
T_5 V_243 ;
T_5 V_297 ;
V_261 -> V_298 . V_236 . V_12 = F_49 ( V_261 -> V_298 . V_236 . V_12 ) ;
V_261 -> V_298 . V_236 . time = F_150 ( V_261 -> V_298 . V_236 . time ) ;
switch ( F_151 ( V_261 -> V_298 . V_236 . V_12 ) ) {
case 0 :
V_297 = F_49 ( V_261 -> V_298 . V_236 . V_242 ) ;
if ( ( V_37 -> V_299 & V_300 ) &&
! F_152 ( V_297 ) ) {
break;
}
V_243 = F_49 ( V_261 -> V_298 . V_236 . V_243 ) ;
V_294 = F_153 ( V_297 ) ;
F_154 ( V_27 , sizeof( struct V_301 ) ) ;
memmove ( F_155 ( V_27 , V_294 ) ,
& V_261 -> V_298 . V_236 . V_242 , V_294 ) ;
V_27 -> V_302 = V_37 -> V_44 ;
V_27 -> V_302 -> V_303 = V_258 ;
F_156 ( V_27 , V_243 + V_294 ) ;
memset ( F_141 ( V_27 , V_304 ) , 0xff , V_304 ) ;
F_157 ( V_27 ) ;
F_158 ( V_37 , V_27 ) ;
V_296 = F_159 ( V_27 ) ;
V_296 -> V_305 = V_261 -> V_298 . V_236 . time ;
V_296 -> V_306 = V_261 -> V_298 . V_236 . V_307 ;
V_296 -> signal = V_261 -> V_298 . V_236 . signal - V_5 -> V_308 ;
V_296 -> V_309 = V_261 -> V_298 . V_236 . V_310 - V_5 -> V_308 ;
F_160 ( V_37 , V_27 ) ;
break;
case 7 :
if ( ! F_161 ( V_261 -> V_298 . V_236 . V_12 ) ) {
F_162 ( V_37 , & V_261 -> V_298 ) ;
F_14 ( V_27 ) ;
} else {
F_5 ( L_89 ) ;
}
break;
default:
F_11 ( V_5 -> V_37 -> V_44 , L_90 ,
F_151 (
V_261 -> V_298 . V_236 . V_12 ) ) ;
break;
}
}
static void F_162 ( struct V_248 * V_37 ,
struct V_311 * V_298 )
{
struct V_301 * V_312 = & ( V_298 -> V_236 ) ;
unsigned int V_294 = 0 ;
unsigned int V_313 = 0 ;
unsigned int V_314 = 0 ;
T_7 * V_315 ;
T_5 V_297 ;
struct V_26 * V_27 ;
struct V_4 * V_5 = V_37 -> V_249 ;
V_297 = F_49 ( V_312 -> V_242 ) ;
V_294 = F_153 ( V_297 ) ;
V_313 = F_49 ( V_312 -> V_243 ) ;
V_314 = sizeof( struct V_316 ) + V_294 + V_313 + V_304 ;
if ( V_314 >
( sizeof( struct V_316 ) +
V_317 + V_318 + V_304 ) ) {
F_5 ( L_91 ,
V_314 - sizeof( struct V_316 ) ) ;
}
V_27 = F_7 ( V_314 ) ;
if ( ! V_27 )
return;
if ( ( V_37 -> V_44 -> type == V_319 ) &&
( V_5 -> V_320 != 0 ) ) {
struct V_316 * V_321 ;
V_315 = F_141 ( V_27 , sizeof( struct V_316 ) ) ;
V_321 = (struct V_316 * ) V_315 ;
V_321 -> V_322 = F_163 ( V_323 ) ;
V_321 -> V_324 = F_163 ( sizeof( struct V_316 ) ) ;
V_321 -> V_305 = F_164 ( V_312 -> time ) * 1000 ;
V_321 -> V_325 = F_164 ( V_258 ) ;
V_321 -> V_326 = F_163 ( 4 ) ;
V_321 -> V_327 = F_163 ( V_5 -> V_328 ) ;
V_321 -> V_329 = F_163 ( V_312 -> V_307 ) ;
V_321 -> V_330 = F_163 ( 0 ) ;
V_321 -> V_331 = F_163 ( 0 ) ;
V_321 -> V_332 = F_163 ( 3 ) ;
V_321 -> V_333 = F_163 ( V_312 -> signal ) ;
V_321 -> V_334 = F_163 ( V_312 -> V_310 ) ;
V_321 -> V_335 = F_163 ( 0 ) ;
V_321 -> V_336 = F_163 ( 1 ) ;
}
V_315 = F_141 ( V_27 , V_294 ) ;
memcpy ( V_315 , & ( V_312 -> V_242 ) , V_294 ) ;
if ( V_313 > 0 ) {
V_315 = F_141 ( V_27 , V_313 ) ;
memcpy ( V_315 , V_298 -> V_35 , V_313 ) ;
if ( * ( V_315 - V_294 + 1 ) & 0x40 )
if ( ( * ( V_315 ) == 0xaa ) && ( * ( V_315 + 1 ) == 0xaa ) )
* ( V_315 - V_294 + 1 ) &= 0xbf ;
}
if ( V_5 -> V_337 ) {
V_315 = F_141 ( V_27 , V_304 ) ;
memset ( V_315 , 0xff , V_304 ) ;
}
F_160 ( V_37 , V_27 ) ;
}
static void F_144 ( struct V_248 * V_37 ,
union V_29 * V_261 )
{
V_261 -> V_338 . V_339 . V_340 =
F_49 ( V_261 -> V_338 . V_339 . V_340 ) ;
F_165 ( V_37 , & V_261 -> V_338 . V_339 ) ;
}
static void V_246 ( struct V_10 * V_10 )
{
struct V_248 * V_37 = V_10 -> V_23 ;
#ifdef F_166
F_4 ( V_10 ) ;
#endif
if ( V_37 && V_37 -> V_44 ) {
switch ( V_10 -> V_12 ) {
case 0 :
F_167 ( V_37 ) ;
break;
case - V_43 :
{
struct V_4 * V_5 = V_37 -> V_249 ;
F_11 ( V_5 -> V_37 -> V_44 ,
L_23 ,
V_37 -> V_44 -> V_45 ) ;
if ( ! F_12
( V_49 , & V_5 -> V_42 ) )
F_13 ( & V_5 -> V_46 ) ;
V_37 -> V_44 -> V_266 . V_341 ++ ;
break;
}
case - V_271 :
case - V_270 :
case - V_269 :
{
struct V_4 * V_5 = V_37 -> V_249 ;
if ( ! F_12
( V_342 , & V_5 -> V_42 ) &&
! F_137 ( & V_5 -> V_69 ) ) {
F_138 ( & V_5 -> V_69 ,
V_258 + V_273 ) ;
}
V_37 -> V_44 -> V_266 . V_341 ++ ;
F_18 ( V_37 -> V_44 ) ;
break;
}
case - V_276 :
case - V_260 :
break;
default:
F_24 ( V_37 -> V_44 , L_92 ,
V_10 -> V_12 ) ;
V_37 -> V_44 -> V_266 . V_341 ++ ;
break;
}
}
}
static void V_255 ( struct V_10 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_23 ;
int V_343 = 0 ;
int V_344 = 1 ;
int V_289 = 0 ;
struct V_3 * V_87 ;
unsigned long V_148 ;
F_5 ( L_93 , V_10 -> V_12 ) ;
#ifdef F_166
F_4 ( V_10 ) ;
#endif
if ( ( V_10 -> V_12 == - V_260 ) ||
( V_10 -> V_12 == - V_150 ) || ! V_5 )
return;
V_290:
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( F_133 ( & V_5 -> V_6 . V_7 ) ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
return;
}
if ( F_146 ( & V_5 -> V_73 ) == 0 ) {
if ( V_5 -> V_152 == 0 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
goto V_290;
}
} else {
V_5 -> V_152 = 1 ;
}
V_87 = F_2 ( V_5 ) ;
if ( V_10 -> V_12 == 0 ) {
switch ( V_87 -> V_78 ) {
case V_256 :
V_87 -> V_78 = V_293 ;
break;
case V_292 :
V_87 -> V_78 = V_117 ;
F_132 ( V_5 , V_87 ) ;
V_289 = 1 ;
break;
default:
F_23 ( V_5 -> V_37 -> V_44 ,
L_94 ,
F_49 ( V_87 -> V_155 . type ) ,
F_1 ( V_87 -> V_78 ) , V_10 -> V_12 ) ;
break;
}
} else {
if ( ( V_10 -> V_12 == - V_43 ) &&
! F_12 ( V_49 , & V_5 -> V_42 ) ) {
F_11 ( V_5 -> V_37 -> V_44 ,
L_23 ,
V_5 -> V_37 -> V_44 -> V_45 ) ;
F_13 ( & V_5 -> V_46 ) ;
}
V_87 -> V_78 = V_154 ;
F_132 ( V_5 , V_87 ) ;
V_343 = 1 ;
V_289 = 1 ;
}
V_345:
if ( V_343 ) {
V_344 = F_146 ( & V_5 -> V_71 ) ;
if ( V_344 != 0 )
V_5 -> V_153 = 1 ;
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( ! V_344 && ( V_5 -> V_153 == 0 ) ) {
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
goto V_345;
}
if ( V_289 )
F_26 ( V_5 ) ;
}
static void V_74 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_5 -> V_152 = 1 ;
if ( ! F_133 ( & V_5 -> V_6 . V_7 ) ) {
V_5 -> V_75 . V_13 |= V_253 ;
if ( F_131 ( & V_5 -> V_75 ) == - V_233 ) {
struct V_3 * V_87 = F_2 ( V_5 ) ;
V_87 -> V_78 = V_154 ;
if ( F_146 ( & V_5 -> V_71 ) != 0 )
V_5 -> V_153 = 1 ;
}
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static void V_72 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
V_5 -> V_153 = 1 ;
if ( ! F_133 ( & V_5 -> V_6 . V_7 ) ) {
struct V_3 * V_87 = F_2 ( V_5 ) ;
if ( F_130 ( V_5 , V_87 ) == 0 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_26 ( V_5 ) ;
return;
}
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static void V_70 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_5 ( L_95 , V_5 -> V_42 ) ;
if ( ! V_5 -> V_37 -> V_40 &&
( ( F_27 ( V_272 , & V_5 -> V_42 ) &&
! F_12 ( V_52 , & V_5 -> V_42 ) ) |
( F_27 ( V_342 , & V_5 -> V_42 ) &&
! F_12 ( V_55 , & V_5 -> V_42 ) )
) ) {
F_13 ( & V_5 -> V_46 ) ;
}
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
}
static int F_94 ( struct V_4 * V_5 , struct V_3 * V_87 )
{
unsigned long V_148 ;
F_88 ( & V_5 -> V_6 . V_58 , V_148 ) ;
if ( V_5 -> V_37 -> V_40 ) {
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
return - V_150 ;
}
V_87 -> V_78 = V_346 ;
F_168 ( & V_87 -> V_9 , & V_5 -> V_6 . V_59 ) ;
F_89 ( & V_5 -> V_6 . V_58 , V_148 ) ;
F_26 ( V_5 ) ;
return 0 ;
}
static int F_114 ( T_5 V_215 )
{
switch ( V_215 ) {
case V_223 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
return 1 ;
default:
if ( V_215 < 0x1000 ) {
F_5 ( L_96 ,
V_215 ) ;
return 1 ;
}
break;
}
F_5 ( L_97 ,
V_215 ) ;
return 0 ;
}
