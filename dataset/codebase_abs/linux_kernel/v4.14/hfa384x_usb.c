static inline const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7
} ;
return V_3 [ V_2 ] ;
}
static inline struct V_4 * F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_7 . V_8 . V_9 , struct V_4 , V_10 ) ;
}
void F_4 ( struct V_11 * V_11 )
{
F_5 ( L_8 , V_11 -> V_12 ) ;
F_5 ( L_9 , V_11 -> V_13 ) ;
F_5 ( L_10 , V_11 -> V_14 ) ;
F_5 ( L_11 ,
( unsigned int ) V_11 -> V_15 ) ;
F_5 ( L_12 ,
V_11 -> V_16 ) ;
F_5 ( L_13 , V_11 -> V_17 ) ;
F_5 ( L_14 , V_11 -> V_18 ) ;
F_5 ( L_15 ,
( unsigned int ) V_11 -> V_19 ) ;
F_5 ( L_16 , V_11 -> V_20 ) ;
F_5 ( L_17 , V_11 -> V_21 ) ;
F_5 ( L_18 , V_11 -> V_22 ) ;
F_5 ( L_19 , V_11 -> V_23 ) ;
F_5 ( L_20 , ( unsigned int ) V_11 -> V_24 ) ;
F_5 ( L_21 , ( unsigned int ) V_11 -> V_25 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_26 )
{
struct V_27 * V_28 ;
int V_29 ;
V_28 = F_7 ( sizeof( union V_30 ) ) ;
if ( ! V_28 ) {
V_29 = - V_31 ;
goto V_32;
}
F_8 ( & V_6 -> V_33 , V_6 -> V_34 ,
V_6 -> V_35 ,
V_28 -> V_36 , sizeof( union V_30 ) ,
V_37 , V_6 -> V_38 ) ;
V_6 -> V_39 = V_28 ;
V_29 = - V_40 ;
if ( ! V_6 -> V_38 -> V_41 &&
! F_9 ( V_42 , & V_6 -> V_43 ) ) {
V_29 = F_10 ( & V_6 -> V_33 , V_26 ) ;
if ( V_29 == - V_44 ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_22 ,
V_6 -> V_38 -> V_45 -> V_46 ) ;
if ( ! F_12 ( V_42 , & V_6 -> V_43 ) )
F_13 ( & V_6 -> V_47 ) ;
}
}
if ( V_29 != 0 ) {
F_14 ( V_28 ) ;
V_6 -> V_39 = NULL ;
}
V_32:
return V_29 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_11 * V_48 , T_1 V_26 )
{
struct V_49 * V_45 = V_6 -> V_38 -> V_45 ;
int V_29 ;
V_29 = - V_40 ;
if ( F_16 ( V_45 ) ) {
if ( ! V_6 -> V_38 -> V_41 &&
! F_9 ( V_50 , & V_6 -> V_43 ) ) {
V_29 = F_10 ( V_48 , V_26 ) ;
if ( V_29 == - V_44 ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_23 ,
V_45 -> V_46 ) ;
F_17 ( V_50 , & V_6 -> V_43 ) ;
F_13 ( & V_6 -> V_47 ) ;
} else if ( V_29 == 0 ) {
F_18 ( V_45 ) ;
}
}
}
return V_29 ;
}
static void F_19 ( struct V_51 * V_36 )
{
struct V_5 * V_6 = F_20 ( V_36 , struct V_5 , V_47 ) ;
struct V_49 * V_45 = V_6 -> V_38 -> V_45 ;
if ( V_6 -> V_38 -> V_41 )
return;
if ( F_9 ( V_42 , & V_6 -> V_43 ) ) {
int V_52 ;
F_21 ( & V_6 -> V_33 ) ;
V_52 = F_22 ( V_6 -> V_34 , V_6 -> V_35 ) ;
if ( V_52 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_24 ,
V_45 -> V_46 , V_52 ) ;
} else {
F_24 ( V_6 -> V_38 -> V_45 , L_25 ,
V_45 -> V_46 ) ;
F_25 ( V_42 , & V_6 -> V_43 ) ;
F_17 ( V_53 , & V_6 -> V_43 ) ;
}
}
if ( F_9 ( V_53 , & V_6 -> V_43 ) ) {
int V_52 ;
V_52 = F_6 ( V_6 , V_54 ) ;
if ( V_52 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_26 ,
V_45 -> V_46 ) ;
} else {
F_25 ( V_53 , & V_6 -> V_43 ) ;
}
}
if ( F_9 ( V_50 , & V_6 -> V_43 ) ) {
int V_52 ;
F_21 ( & V_6 -> V_48 ) ;
V_52 = F_22 ( V_6 -> V_34 , V_6 -> V_55 ) ;
if ( V_52 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_27 ,
V_45 -> V_46 , V_52 ) ;
} else {
F_24 ( V_6 -> V_38 -> V_45 , L_28 ,
V_45 -> V_46 ) ;
F_25 ( V_50 , & V_6 -> V_43 ) ;
F_17 ( V_56 , & V_6 -> V_43 ) ;
F_26 ( V_6 ) ;
}
}
if ( F_27 ( V_56 , & V_6 -> V_43 ) )
F_28 ( V_6 -> V_38 -> V_45 ) ;
}
void F_29 ( struct V_5 * V_6 , struct V_57 * V_34 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_34 = V_34 ;
V_6 -> V_35 = F_30 ( V_34 , 1 ) ;
V_6 -> V_55 = F_31 ( V_34 , 2 ) ;
F_32 ( & V_6 -> V_58 ) ;
F_33 ( & V_6 -> V_7 . V_59 ) ;
F_34 ( & V_6 -> V_7 . V_60 ) ;
F_34 ( & V_6 -> V_7 . V_8 ) ;
F_34 ( & V_6 -> V_7 . V_61 ) ;
F_34 ( & V_6 -> V_7 . V_62 ) ;
F_35 ( & V_6 -> V_63 ) ;
F_36 ( & V_6 -> V_64 ,
V_65 , ( unsigned long ) V_6 ) ;
F_36 ( & V_6 -> V_66 ,
V_67 , ( unsigned long ) V_6 ) ;
F_37 ( & V_6 -> V_68 , V_69 ) ;
F_37 ( & V_6 -> V_47 , F_19 ) ;
F_38 ( & V_6 -> V_70 , V_71 , ( unsigned long ) V_6 ) ;
F_38 ( & V_6 -> V_72 , V_73 ,
( unsigned long ) V_6 ) ;
F_38 ( & V_6 -> V_74 , V_75 ,
( unsigned long ) V_6 ) ;
F_39 ( & V_6 -> V_33 ) ;
F_39 ( & V_6 -> V_48 ) ;
F_39 ( & V_6 -> V_76 ) ;
V_6 -> V_77 = V_78 ;
V_6 -> V_79 = V_80 ;
F_37 ( & V_6 -> V_81 , V_82 ) ;
F_38 ( & V_6 -> V_83 , V_84 ,
( unsigned long ) V_6 ) ;
}
void F_40 ( struct V_5 * V_6 )
{
struct V_27 * V_28 ;
if ( V_6 -> V_79 == V_85 )
F_41 ( V_6 ) ;
V_6 -> V_79 = V_86 ;
F_42 ( V_6 -> V_87 ) ;
V_6 -> V_87 = NULL ;
while ( ( V_28 = F_43 ( & V_6 -> V_63 ) ) )
F_14 ( V_28 ) ;
}
static struct V_4 * F_44 ( void )
{
struct V_4 * V_88 ;
V_88 = F_45 ( sizeof( * V_88 ) ,
F_46 () ? V_89 : V_54 ) ;
if ( V_88 )
F_47 ( & V_88 -> V_32 ) ;
return V_88 ;
}
static int
F_48 ( const struct V_90 * V_91 ,
struct V_92 * V_29 )
{
V_29 -> V_13 = F_49 ( V_91 -> V_13 ) ;
V_29 -> V_93 = F_49 ( V_91 -> V_93 ) ;
V_29 -> V_94 = F_49 ( V_91 -> V_94 ) ;
V_29 -> V_95 = F_49 ( V_91 -> V_95 ) ;
F_5 ( L_29 ,
V_29 -> V_13 , V_29 -> V_93 , V_29 -> V_94 , V_29 -> V_95 ) ;
return V_29 -> V_13 & V_96 ;
}
static void
F_50 ( const struct V_97 * V_98 ,
struct V_99 * V_29 )
{
V_29 -> V_100 = F_49 ( V_98 -> V_100 ) ;
V_29 -> V_101 = V_98 -> V_36 ;
V_29 -> V_102 = ( ( F_49 ( V_98 -> V_103 ) - 1 ) * 2 ) ;
}
static inline int F_51 ( struct V_104 * V_105 )
{
struct V_106 * V_25 ;
V_25 = (struct V_106 * ) V_105 ;
return F_48 ( V_25 -> V_91 , V_25 -> V_29 ) ;
}
static inline struct V_104 *
F_52 ( struct V_106 * V_107 ,
const struct V_90 * V_91 ,
struct V_92 * V_29 )
{
V_107 -> V_105 . V_25 = F_51 ;
V_107 -> V_91 = V_91 ;
V_107 -> V_29 = V_29 ;
return & V_107 -> V_105 ;
}
static int F_53 ( struct V_104 * V_105 )
{
struct V_108 * V_25 ;
struct V_99 V_109 ;
V_25 = (struct V_108 * ) V_105 ;
F_50 ( V_25 -> V_98 , & V_109 ) ;
if ( V_109 . V_102 != V_25 -> V_110 ) {
F_54 ( L_30 ,
V_109 . V_100 ,
V_25 -> V_110 , V_109 . V_102 ) ;
return - V_111 ;
}
memcpy ( V_25 -> V_101 , V_109 . V_101 , V_25 -> V_110 ) ;
return 0 ;
}
static inline struct V_104 *
F_55 ( struct V_108 * V_107 ,
const struct V_97 * V_98 ,
void * V_101 ,
unsigned int V_110 )
{
V_107 -> V_105 . V_25 = F_53 ;
V_107 -> V_98 = V_98 ;
V_107 -> V_101 = V_101 ;
V_107 -> V_110 = V_110 ;
return & V_107 -> V_105 ;
}
static int F_56 ( struct V_104 * V_105 )
{
struct V_112 * V_25 =
(struct V_112 * ) V_105 ;
F_5 ( L_31 , V_25 -> V_113 -> V_103 ) ;
memcpy ( V_25 -> V_36 , V_25 -> V_113 -> V_36 , V_25 -> V_114 ) ;
return 0 ;
}
static inline struct V_104 *
F_57 ( struct V_112 * V_107 ,
struct V_115 * V_113 ,
void * V_36 ,
unsigned int V_114 )
{
V_107 -> V_105 . V_25 = F_56 ;
V_107 -> V_113 = V_113 ;
V_107 -> V_36 = V_36 ;
V_107 -> V_114 = V_114 ;
return & V_107 -> V_105 ;
}
static void F_58 ( struct V_5 * V_6 ,
const struct V_4 * V_88 )
{
if ( V_88 -> V_116 ) {
struct V_92 V_117 ;
if ( V_88 -> V_79 != V_118 ) {
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_13 =
F_59 ( V_119 ) ;
} else {
F_48 ( & V_88 -> V_120 . V_91 , & V_117 ) ;
}
V_88 -> V_116 ( V_6 , & V_117 , V_88 -> V_121 ) ;
}
}
static inline int F_60 ( struct V_5 * V_6 ,
struct V_122 * V_123 )
{
return F_61 ( V_6 , V_124 , V_123 , NULL , NULL , NULL ) ;
}
static inline int
F_62 ( struct V_5 * V_6 ,
struct V_122 * V_123 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
return F_61 ( V_6 , V_126 , V_123 , V_125 , V_116 , V_121 ) ;
}
static inline int
F_63 ( struct V_5 * V_6 , T_4 V_100 , void * V_101 ,
unsigned int V_110 )
{
return F_64 ( V_6 , V_124 ,
V_100 , V_101 , V_110 , NULL , NULL , NULL ) ;
}
static inline int
F_65 ( struct V_5 * V_6 ,
T_4 V_100 , void * V_101 , unsigned int V_110 ,
T_2 V_125 ,
T_3 V_116 , void * V_121 )
{
return F_64 ( V_6 , V_126 ,
V_100 , V_101 , V_110 ,
V_125 , V_116 , V_121 ) ;
}
static inline int
F_66 ( struct V_5 * V_6 , T_4 V_100 , void * V_101 ,
unsigned int V_110 )
{
return F_67 ( V_6 , V_124 ,
V_100 , V_101 , V_110 , NULL , NULL , NULL ) ;
}
static inline int
F_68 ( struct V_5 * V_6 ,
T_4 V_100 , void * V_101 , unsigned int V_110 ,
T_2 V_125 ,
T_3 V_116 , void * V_121 )
{
return F_67 ( V_6 , V_126 ,
V_100 , V_101 , V_110 ,
V_125 , V_116 , V_121 ) ;
}
static inline int
F_69 ( struct V_5 * V_6 ,
T_4 V_127 , T_4 V_128 , void * V_36 , unsigned int V_114 )
{
return F_70 ( V_6 , V_124 ,
V_127 , V_128 , V_36 , V_114 , NULL , NULL , NULL ) ;
}
static inline int
F_71 ( struct V_5 * V_6 ,
T_4 V_127 , T_4 V_128 , void * V_36 , unsigned int V_114 ,
T_2 V_125 ,
T_3 V_116 , void * V_121 )
{
return F_70 ( V_6 , V_126 ,
V_127 , V_128 , V_36 , V_114 ,
V_125 , V_116 , V_121 ) ;
}
static inline int
F_72 ( struct V_5 * V_6 ,
T_4 V_127 , T_4 V_128 , void * V_36 , unsigned int V_114 )
{
return F_73 ( V_6 , V_124 ,
V_127 , V_128 , V_36 , V_114 , NULL , NULL , NULL ) ;
}
static inline int
F_74 ( struct V_5 * V_6 ,
T_4 V_127 ,
T_4 V_128 ,
void * V_36 ,
unsigned int V_114 ,
T_2 V_125 ,
T_3 V_116 , void * V_121 )
{
return F_73 ( V_6 , V_126 ,
V_127 , V_128 , V_36 , V_114 ,
V_125 , V_116 , V_121 ) ;
}
int F_75 ( struct V_5 * V_6 )
{
int V_29 = 0 ;
int V_129 ;
struct V_122 V_123 ;
V_123 . V_123 = V_130 ;
V_123 . V_131 = 0 ;
V_123 . V_132 = 0 ;
V_123 . V_133 = 0 ;
V_29 = F_60 ( V_6 , & V_123 ) ;
F_5 ( L_32 ,
V_123 . V_29 . V_13 ,
V_123 . V_29 . V_93 , V_123 . V_29 . V_94 , V_123 . V_29 . V_95 ) ;
if ( V_29 == 0 ) {
for ( V_129 = 0 ; V_129 < V_134 ; V_129 ++ )
V_6 -> V_135 [ V_129 ] = 0 ;
}
V_6 -> V_77 = V_78 ;
return V_29 ;
}
int F_76 ( struct V_5 * V_6 , T_4 V_136 )
{
struct V_122 V_123 ;
V_123 . V_123 = F_77 ( V_137 ) |
F_78 ( V_136 ) ;
V_123 . V_131 = 0 ;
V_123 . V_132 = 0 ;
V_123 . V_133 = 0 ;
return F_60 ( V_6 , & V_123 ) ;
}
int F_79 ( struct V_5 * V_6 , T_4 V_136 )
{
struct V_122 V_123 ;
V_123 . V_123 = F_77 ( V_138 ) |
F_78 ( V_136 ) ;
V_123 . V_131 = 0 ;
V_123 . V_132 = 0 ;
V_123 . V_133 = 0 ;
return F_60 ( V_6 , & V_123 ) ;
}
int F_80 ( struct V_5 * V_6 , T_4 V_139 )
{
struct V_122 V_123 ;
V_123 . V_123 = F_77 ( V_140 ) |
F_81 ( V_139 ) ;
V_123 . V_131 = 0 ;
V_123 . V_132 = 0 ;
V_123 . V_133 = 0 ;
return F_60 ( V_6 , & V_123 ) ;
}
int F_82 ( struct V_5 * V_6 , T_4 V_141 , T_4 V_142 ,
T_4 V_143 , T_4 V_144 )
{
struct V_122 V_123 ;
F_5 ( L_33 ,
V_141 , V_142 , V_143 , V_144 ) ;
V_123 . V_123 = ( F_77 ( V_145 ) |
F_83 ( V_141 ) ) ;
V_123 . V_131 = V_142 ;
V_123 . V_132 = V_143 ;
V_123 . V_133 = V_144 ;
return F_60 ( V_6 , & V_123 ) ;
}
int F_84 ( struct V_5 * V_6 , int V_146 ,
int V_147 , int V_148 )
{
int V_29 ;
V_29 = F_85 ( V_6 -> V_34 ) ;
if ( V_29 < 0 ) {
F_23 ( V_6 -> V_38 -> V_45 , L_34 ,
V_29 ) ;
}
return V_29 ;
}
static int F_86 ( struct V_5 * V_6 ,
struct V_4 * V_88 ,
struct V_104 * V_107 )
{
unsigned long V_149 ;
int V_29 ;
V_29 = F_87 ( & V_88 -> V_32 ) ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_150:
if ( V_6 -> V_38 -> V_41 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_29 = - V_151 ;
} else if ( V_29 != 0 ) {
int V_152 = 0 ;
if ( V_88 == F_2 ( V_6 ) ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_90 ( & V_6 -> V_74 ) ;
F_90 ( & V_6 -> V_72 ) ;
V_6 -> V_153 = 1 ;
V_6 -> V_154 = 1 ;
F_21 ( & V_6 -> V_76 ) ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_152 = 1 ;
if ( V_6 -> V_38 -> V_41 )
goto V_150;
}
V_88 -> V_62 = 1 ;
V_88 -> V_79 = V_155 ;
F_91 ( & V_88 -> V_10 , & V_6 -> V_7 . V_61 ) ;
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( V_152 )
F_26 ( V_6 ) ;
} else {
if ( V_88 -> V_79 == V_118 ) {
V_29 = V_107 -> V_25 ( V_107 ) ;
} else {
F_11 ( V_6 -> V_38 -> V_45 , L_35 ,
F_49 ( V_88 -> V_156 . type ) ,
F_1 ( V_88 -> V_79 ) ) ;
V_29 = - V_157 ;
}
F_92 ( & V_88 -> V_10 ) ;
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_42 ( V_88 ) ;
}
return V_29 ;
}
static int
F_61 ( struct V_5 * V_6 ,
enum V_158 V_141 ,
struct V_122 * V_123 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
int V_29 ;
struct V_4 * V_88 ;
V_88 = F_44 () ;
if ( ! V_88 ) {
V_29 = - V_31 ;
goto V_32;
}
V_88 -> V_156 . V_159 . type = F_93 ( V_160 ) ;
V_88 -> V_156 . V_159 . V_123 = F_93 ( V_123 -> V_123 ) ;
V_88 -> V_156 . V_159 . V_131 = F_93 ( V_123 -> V_131 ) ;
V_88 -> V_156 . V_159 . V_132 = F_93 ( V_123 -> V_132 ) ;
V_88 -> V_156 . V_159 . V_133 = F_93 ( V_123 -> V_133 ) ;
V_88 -> V_161 = sizeof( V_88 -> V_156 . V_159 ) ;
F_5 ( L_36 ,
V_123 -> V_123 , V_123 -> V_131 , V_123 -> V_132 , V_123 -> V_133 ) ;
V_88 -> V_62 = V_141 ;
V_88 -> V_125 = V_125 ;
V_88 -> V_116 = V_116 ;
V_88 -> V_121 = V_121 ;
V_29 = F_94 ( V_6 , V_88 ) ;
if ( V_29 != 0 ) {
F_42 ( V_88 ) ;
} else if ( V_141 == V_124 ) {
struct V_106 V_162 ;
struct V_104 * V_107 ;
V_107 = F_52 ( & V_162 ,
& V_88 -> V_120 . V_91 ,
& V_123 -> V_29 ) ;
V_29 = F_86 ( V_6 , V_88 , V_107 ) ;
}
V_32:
return V_29 ;
}
static int
F_64 ( struct V_5 * V_6 ,
enum V_158 V_141 ,
T_4 V_100 ,
void * V_101 ,
unsigned int V_110 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
int V_29 ;
struct V_4 * V_88 ;
V_88 = F_44 () ;
if ( ! V_88 ) {
V_29 = - V_31 ;
goto V_32;
}
V_88 -> V_156 . V_163 . type = F_93 ( V_164 ) ;
V_88 -> V_156 . V_163 . V_103 =
F_93 ( sizeof( V_88 -> V_156 . V_163 . V_100 ) ) ;
V_88 -> V_156 . V_163 . V_100 = F_93 ( V_100 ) ;
V_88 -> V_161 = sizeof( V_88 -> V_156 . V_163 ) ;
V_88 -> V_62 = V_141 ;
V_88 -> V_125 = V_125 ;
V_88 -> V_116 = V_116 ;
V_88 -> V_121 = V_121 ;
V_29 = F_94 ( V_6 , V_88 ) ;
if ( V_29 != 0 ) {
F_42 ( V_88 ) ;
} else if ( V_141 == V_124 ) {
struct V_108 V_107 ;
V_29 =
F_86 ( V_6 , V_88 ,
F_55
( & V_107 ,
& V_88 -> V_120 . V_98 ,
V_101 , V_110 ) ) ;
}
V_32:
return V_29 ;
}
static int
F_67 ( struct V_5 * V_6 ,
enum V_158 V_141 ,
T_4 V_100 ,
void * V_101 ,
unsigned int V_110 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
int V_29 ;
struct V_4 * V_88 ;
V_88 = F_44 () ;
if ( ! V_88 ) {
V_29 = - V_31 ;
goto V_32;
}
V_88 -> V_156 . V_165 . type = F_93 ( V_166 ) ;
V_88 -> V_156 . V_165 . V_103 = F_93 ( ( sizeof
( V_88 -> V_156 . V_165 . V_100 ) +
V_110 + 1 ) / 2 ) ;
V_88 -> V_156 . V_165 . V_100 = F_93 ( V_100 ) ;
memcpy ( V_88 -> V_156 . V_165 . V_36 , V_101 , V_110 ) ;
V_88 -> V_161 = sizeof( V_88 -> V_156 . V_165 . type ) +
sizeof( V_88 -> V_156 . V_165 . V_103 ) +
sizeof( V_88 -> V_156 . V_165 . V_100 ) + V_110 ;
V_88 -> V_62 = V_141 ;
V_88 -> V_125 = V_125 ;
V_88 -> V_116 = V_116 ;
V_88 -> V_121 = V_121 ;
V_29 = F_94 ( V_6 , V_88 ) ;
if ( V_29 != 0 ) {
F_42 ( V_88 ) ;
} else if ( V_141 == V_124 ) {
struct V_106 V_107 ;
struct V_92 V_167 ;
V_29 = F_86 ( V_6 ,
V_88 ,
F_95
( & V_107 ,
& V_88 -> V_120 . V_168 ,
& V_167 ) ) ;
}
V_32:
return V_29 ;
}
static int
F_70 ( struct V_5 * V_6 ,
enum V_158 V_141 ,
T_4 V_127 ,
T_4 V_128 ,
void * V_36 ,
unsigned int V_114 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
int V_29 ;
struct V_4 * V_88 ;
V_88 = F_44 () ;
if ( ! V_88 ) {
V_29 = - V_31 ;
goto V_32;
}
V_88 -> V_156 . V_169 . type = F_93 ( V_170 ) ;
V_88 -> V_156 . V_169 . V_103 =
F_93 ( sizeof( V_88 -> V_156 . V_169 . V_128 ) +
sizeof( V_88 -> V_156 . V_169 . V_127 ) + V_114 ) ;
V_88 -> V_156 . V_169 . V_128 = F_93 ( V_128 ) ;
V_88 -> V_156 . V_169 . V_127 = F_93 ( V_127 ) ;
V_88 -> V_161 = sizeof( V_88 -> V_156 . V_169 ) ;
F_5 ( L_37 ,
V_88 -> V_156 . V_169 . type ,
V_88 -> V_156 . V_169 . V_103 ,
V_88 -> V_156 . V_169 . V_128 , V_88 -> V_156 . V_169 . V_127 ) ;
F_5 ( L_38 , F_96 ( sizeof( V_88 -> V_156 . V_169 ) ) ) ;
V_88 -> V_62 = V_141 ;
V_88 -> V_125 = V_125 ;
V_88 -> V_116 = V_116 ;
V_88 -> V_121 = V_121 ;
V_29 = F_94 ( V_6 , V_88 ) ;
if ( V_29 != 0 ) {
F_42 ( V_88 ) ;
} else if ( V_141 == V_124 ) {
struct V_112 V_107 ;
V_29 =
F_86 ( V_6 , V_88 ,
F_57
( & V_107 ,
& V_88 -> V_120 . V_113 , V_36 ,
V_114 ) ) ;
}
V_32:
return V_29 ;
}
static int
F_73 ( struct V_5 * V_6 ,
enum V_158 V_141 ,
T_4 V_127 ,
T_4 V_128 ,
void * V_36 ,
unsigned int V_114 ,
T_2 V_125 , T_3 V_116 , void * V_121 )
{
int V_29 ;
struct V_4 * V_88 ;
F_5 ( L_39 , V_127 , V_128 , V_114 ) ;
V_88 = F_44 () ;
if ( ! V_88 ) {
V_29 = - V_31 ;
goto V_32;
}
V_88 -> V_156 . V_171 . type = F_93 ( V_172 ) ;
V_88 -> V_156 . V_171 . V_103 =
F_93 ( sizeof( V_88 -> V_156 . V_171 . V_128 ) +
sizeof( V_88 -> V_156 . V_171 . V_127 ) + V_114 ) ;
V_88 -> V_156 . V_171 . V_128 = F_93 ( V_128 ) ;
V_88 -> V_156 . V_171 . V_127 = F_93 ( V_127 ) ;
memcpy ( V_88 -> V_156 . V_171 . V_36 , V_36 , V_114 ) ;
V_88 -> V_161 = sizeof( V_88 -> V_156 . V_171 . type ) +
sizeof( V_88 -> V_156 . V_171 . V_103 ) +
sizeof( V_88 -> V_156 . V_171 . V_128 ) +
sizeof( V_88 -> V_156 . V_171 . V_127 ) + V_114 ;
V_88 -> V_62 = V_141 ;
V_88 -> V_125 = V_125 ;
V_88 -> V_116 = V_116 ;
V_88 -> V_121 = V_121 ;
V_29 = F_94 ( V_6 , V_88 ) ;
if ( V_29 != 0 ) {
F_42 ( V_88 ) ;
} else if ( V_141 == V_124 ) {
struct V_106 V_107 ;
struct V_92 V_173 ;
V_29 = F_86 ( V_6 ,
V_88 ,
F_97
( & V_107 ,
& V_88 -> V_120 . V_174 ,
& V_173 ) ) ;
}
V_32:
return V_29 ;
}
int F_98 ( struct V_5 * V_6 , T_4 V_136 )
{
int V_29 = 0 ;
if ( ( ! V_6 -> V_175 && V_136 != 0 ) ||
( V_6 -> V_175 && ! ( V_136 <= V_176 ) ) ||
! ( V_6 -> V_135 [ V_136 ] ) ) {
V_29 = - V_177 ;
} else {
V_29 = F_76 ( V_6 , V_136 ) ;
if ( V_29 == 0 )
V_6 -> V_135 [ V_136 ] = 0 ;
}
return V_29 ;
}
int F_99 ( struct V_5 * V_6 , T_4 V_136 )
{
int V_29 = 0 ;
if ( ( ! V_6 -> V_175 && V_136 != 0 ) ||
( V_6 -> V_175 && ! ( V_136 <= V_176 ) ) ||
( V_6 -> V_135 [ V_136 ] ) ) {
V_29 = - V_177 ;
} else {
V_29 = F_79 ( V_6 , V_136 ) ;
if ( V_29 == 0 )
V_6 -> V_135 [ V_136 ] = 1 ;
}
return V_29 ;
}
int F_100 ( struct V_5 * V_6 )
{
int V_29 = 0 ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_176 ; V_129 ++ ) {
if ( V_6 -> V_135 [ V_129 ] ) {
F_5 ( L_40 ) ;
return - V_177 ;
}
}
if ( V_6 -> V_178 != V_179 )
return - V_177 ;
V_29 = F_101 ( V_6 , V_180 ,
& V_6 -> V_181 , sizeof( V_6 -> V_181 ) ) ;
if ( V_29 )
return V_29 ;
F_102 ( & V_6 -> V_181 . V_127 ) ;
F_102 ( & V_6 -> V_181 . V_128 ) ;
F_102 ( & V_6 -> V_181 . V_114 ) ;
V_29 = F_103 ( V_6 , V_182 ,
& V_6 -> V_183 ) ;
if ( V_29 )
return V_29 ;
F_102 ( & V_6 -> V_183 ) ;
F_5 ( L_41 ) ;
V_6 -> V_178 = V_184 ;
return V_29 ;
}
int F_104 ( struct V_5 * V_6 )
{
if ( V_6 -> V_178 != V_184 )
return - V_177 ;
F_5 ( L_41 ) ;
F_82 ( V_6 , V_185 , 0 , 0 , 0 ) ;
V_6 -> V_178 = V_179 ;
return 0 ;
}
int F_105 ( struct V_5 * V_6 , T_5 V_186 ,
void * V_187 , T_5 V_114 )
{
int V_29 = 0 ;
T_5 V_188 ;
int V_189 ;
T_5 V_190 ;
T_5 V_191 ;
T_4 V_192 ;
T_4 V_193 ;
int V_194 ;
T_6 * V_195 ;
T_4 V_196 ;
T_4 V_197 ;
T_5 V_198 ;
int V_129 ;
int V_199 ;
F_5 ( L_42 , V_186 , V_114 ) ;
if ( V_6 -> V_178 != V_184 )
return - V_177 ;
F_24 ( V_6 -> V_38 -> V_45 ,
L_43 , V_114 , V_186 ) ;
V_188 =
F_106 ( V_6 -> V_181 . V_127 , V_6 -> V_181 . V_128 ) ;
F_5 ( L_44 ,
V_6 -> V_181 . V_127 , V_6 -> V_181 . V_128 , V_188 ) ;
V_189 = V_114 / V_6 -> V_181 . V_114 ;
V_189 += ( V_114 % V_6 -> V_181 . V_114 ) ? 1 : 0 ;
V_194 = V_6 -> V_181 . V_114 / V_200 ;
V_194 += ( V_6 -> V_181 . V_114 % V_200 ) ? 1 : 0 ;
for ( V_129 = 0 ; V_129 < V_189 ; V_129 ++ ) {
V_190 = ( V_114 - ( V_6 -> V_181 . V_114 * V_129 ) ) > V_6 -> V_181 . V_114 ?
V_6 -> V_181 . V_114 : ( V_114 - ( V_6 -> V_181 . V_114 * V_129 ) ) ;
V_191 = V_186 + ( V_6 -> V_181 . V_114 * V_129 ) ;
V_192 = F_107 ( V_191 ) ;
V_193 = F_108 ( V_191 ) ;
F_24 ( V_6 -> V_38 -> V_45 , L_45 ,
V_190 , V_191 ) ;
V_29 = F_82 ( V_6 , V_201 ,
V_192 , V_193 , V_190 ) ;
if ( V_29 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_46 ,
V_192 , V_193 , V_190 , V_29 ) ;
goto V_202;
}
for ( V_199 = 0 ; V_199 < V_194 ; V_199 ++ ) {
V_195 = V_187 +
( V_129 * V_6 -> V_181 . V_114 ) +
( V_199 * V_200 ) ;
V_196 = F_108 ( V_188 +
( V_199 * V_200 ) ) ;
V_197 = F_107 ( V_188 +
( V_199 * V_200 ) ) ;
V_198 = V_190 - ( V_199 * V_200 ) ;
V_198 = V_198 > V_200 ?
V_200 : V_198 ;
V_29 = F_72 ( V_6 ,
V_196 ,
V_197 ,
V_195 , V_198 ) ;
}
V_29 = F_82 ( V_6 ,
V_203 ,
0 , 0 , 0 ) ;
if ( V_29 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_47 ,
V_192 , V_193 , V_190 , V_29 ) ;
goto V_202;
}
}
V_202:
return V_29 ;
}
int F_101 ( struct V_5 * V_6 , T_4 V_100 , void * V_187 , T_4 V_114 )
{
return F_63 ( V_6 , V_100 , V_187 , V_114 ) ;
}
int
F_109 ( struct V_5 * V_6 ,
T_4 V_100 ,
void * V_187 ,
T_4 V_114 , T_3 V_116 , void * V_121 )
{
return F_68 ( V_6 , V_100 , V_187 , V_114 ,
F_58 , V_116 , V_121 ) ;
}
int F_110 ( struct V_5 * V_6 )
{
if ( V_6 -> V_178 != V_204 )
return - V_177 ;
F_5 ( L_48 ) ;
F_82 ( V_6 , V_185 , 0 , 0 , 0 ) ;
V_6 -> V_178 = V_179 ;
return 0 ;
}
int F_111 ( struct V_5 * V_6 , T_5 V_205 )
{
int V_29 = 0 ;
T_4 V_142 ;
T_4 V_206 ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_176 ; V_129 ++ ) {
if ( V_6 -> V_135 [ V_129 ] ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_49 ) ;
return - V_177 ;
}
}
if ( V_6 -> V_178 != V_179 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_50 ) ;
return - V_177 ;
}
F_5 ( L_51 , V_205 ) ;
V_142 = F_107 ( V_205 ) ;
V_206 = F_108 ( V_205 ) ;
V_29 = F_82 ( V_6 , V_207 ,
V_142 , V_206 , 0 ) ;
if ( V_29 == 0 ) {
V_6 -> V_178 = V_204 ;
} else {
F_5 ( L_52 ,
V_142 , V_206 , V_29 ) ;
}
return V_29 ;
}
int F_112 ( struct V_5 * V_6 , T_5 V_186 , void * V_187 , T_5 V_114 )
{
int V_29 = 0 ;
int V_194 ;
T_6 * V_36 = V_187 ;
int V_129 ;
T_5 V_208 ;
T_4 V_209 ;
T_4 V_210 ;
T_4 V_211 ;
if ( V_6 -> V_178 != V_204 )
return - V_177 ;
F_24 ( V_6 -> V_38 -> V_45 , L_53 ,
V_114 , V_186 ) ;
V_194 = V_114 / V_200 ;
V_194 += V_114 % V_200 ? 1 : 0 ;
for ( V_129 = 0 ; V_129 < V_194 ; V_129 ++ ) {
V_208 = V_186 + ( V_129 * V_200 ) ;
V_209 = F_108 ( V_208 ) ;
V_210 = F_107 ( V_208 ) ;
V_211 = V_114 - ( V_129 * V_200 ) ;
if ( V_211 > V_200 )
V_211 = V_200 ;
V_29 = F_72 ( V_6 ,
V_209 ,
V_210 ,
V_36 +
( V_129 * V_200 ) ,
V_211 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
int F_113 ( struct V_5 * V_6 , void * V_187 , unsigned int V_114 )
{
int V_29 = 0 ;
T_7 * V_212 = V_187 ;
int V_213 = 0 ;
int V_214 = 1 ;
int V_215 = 0 ;
T_8 V_129 ;
T_4 V_216 ;
T_4 V_217 ;
T_4 V_209 ;
T_4 V_210 ;
struct V_218 {
T_5 V_219 ;
T_4 V_220 ;
} V_218 [] = {
{
V_221 , 0 } , {
V_222 , 0 } , {
V_223 , 0 }
} ;
for ( V_129 = 0 ; V_129 < F_114 ( V_218 ) ; V_129 ++ ) {
V_209 = F_108 ( V_218 [ V_129 ] . V_219 ) ;
V_210 = F_107 ( V_218 [ V_129 ] . V_219 ) ;
V_29 = F_69 ( V_6 , V_209 , V_210 , V_187 ,
V_114 ) ;
if ( V_29 ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_54 ,
V_129 ) ;
continue;
}
V_213 = 1 ;
V_214 = 1 ;
while ( V_213 && V_214 ) {
V_216 = F_49 ( V_212 [ V_215 ] ) * 2 ;
V_217 = F_49 ( V_212 [ V_215 + 1 ] ) ;
if ( V_216 > V_224 || V_216 == 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_55 , V_216 ) ;
V_213 = 0 ;
break;
}
if ( ! F_115 ( V_217 ) ) {
F_23 ( V_6 -> V_38 -> V_45 , L_56 ,
V_217 ) ;
V_213 = 0 ;
break;
}
if ( V_217 == V_225 )
V_214 = 0 ;
if ( V_214 ) {
V_215 += F_49 ( V_212 [ V_215 ] ) + 1 ;
}
}
if ( V_213 ) {
F_24 ( V_6 -> V_38 -> V_45 ,
L_57 ,
V_218 [ V_129 ] . V_219 ,
V_218 [ V_129 ] . V_220 == 0 ? L_58 :
V_218 [ V_129 ] . V_220 == 1 ? L_59 :
V_218 [ V_129 ] . V_220 == 2 ? L_60 :
V_218 [ V_129 ] . V_220 == 3 ? L_61 :
L_62 ) ;
break;
}
}
V_29 = V_213 ? 0 : - V_111 ;
if ( V_29 )
F_5 ( L_63 ) ;
return V_29 ;
}
int F_116 ( struct V_5 * V_6 , T_4 V_100 , void * V_187 , T_4 V_114 )
{
return F_66 ( V_6 , V_100 , V_187 , V_114 ) ;
}
int F_117 ( struct V_5 * V_6 )
{
int V_29 , V_226 , V_227 ;
T_4 V_13 ;
F_118 () ;
V_29 =
F_119 ( V_6 -> V_34 , V_228 , V_6 -> V_35 , & V_13 ) ;
if ( V_29 < 0 ) {
F_23 ( V_6 -> V_38 -> V_45 , L_64 ) ;
goto V_32;
}
if ( ( V_13 == 1 ) && F_22 ( V_6 -> V_34 , V_6 -> V_35 ) )
F_23 ( V_6 -> V_38 -> V_45 , L_65 ) ;
V_29 =
F_119 ( V_6 -> V_34 , V_228 , V_6 -> V_55 , & V_13 ) ;
if ( V_29 < 0 ) {
F_23 ( V_6 -> V_38 -> V_45 , L_66 ) ;
goto V_32;
}
if ( ( V_13 == 1 ) && F_22 ( V_6 -> V_34 , V_6 -> V_55 ) )
F_23 ( V_6 -> V_38 -> V_45 , L_67 ) ;
F_21 ( & V_6 -> V_33 ) ;
V_29 = F_6 ( V_6 , V_54 ) ;
if ( V_29 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_68 ,
V_29 ) ;
goto V_32;
}
V_226 = F_75 ( V_6 ) ;
F_120 ( 1000 ) ;
V_29 = F_75 ( V_6 ) ;
V_227 = V_29 ;
if ( V_226 != 0 ) {
if ( V_227 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_69 ,
V_226 , V_227 ) ;
F_21 ( & V_6 -> V_33 ) ;
goto V_32;
} else {
F_5 ( L_70 ,
V_226 ) ;
F_5 ( L_71 ) ;
}
} else if ( V_227 != 0 ) {
F_11 ( V_6 -> V_38 -> V_45 , L_72 ,
V_227 ) ;
F_11 ( V_6 -> V_38 -> V_45 ,
L_73 ) ;
goto V_32;
}
V_6 -> V_79 = V_85 ;
V_32:
return V_29 ;
}
int F_41 ( struct V_5 * V_6 )
{
int V_129 ;
F_118 () ;
if ( ! V_6 -> V_38 -> V_41 ) {
F_75 ( V_6 ) ;
F_21 ( & V_6 -> V_33 ) ;
}
V_6 -> V_77 = V_78 ;
V_6 -> V_79 = V_80 ;
F_121 ( & V_6 -> V_83 ) ;
for ( V_129 = 0 ; V_129 < V_134 ; V_129 ++ )
V_6 -> V_135 [ V_129 ] = 0 ;
return 0 ;
}
int F_122 ( struct V_5 * V_6 , struct V_27 * V_28 ,
union V_229 * V_229 ,
struct V_230 * V_231 )
{
int V_232 = sizeof( struct V_233 ) ;
int V_29 ;
int V_52 ;
char * V_234 ;
if ( V_6 -> V_48 . V_13 == - V_235 ) {
F_11 ( V_6 -> V_38 -> V_45 , L_74 ) ;
V_29 = 3 ;
goto exit;
}
memset ( & V_6 -> V_236 . V_237 . V_238 , 0 , sizeof( V_6 -> V_236 . V_237 . V_238 ) ) ;
V_6 -> V_236 . type = F_93 ( V_239 ) ;
V_6 -> V_236 . V_237 . V_238 . V_240 = 0x0123 ;
#if F_123 ( V_241 )
V_6 -> V_236 . V_237 . V_238 . V_242 =
F_124 ( 0 ) | F_125 ( 1 ) |
F_126 ( 1 ) | F_127 ( 1 ) ;
#elif F_123 ( V_243 )
V_6 -> V_236 . V_237 . V_238 . V_242 =
F_124 ( 0 ) | F_125 ( 1 ) |
F_126 ( 1 ) | F_127 ( 0 ) ;
#else
V_6 -> V_236 . V_237 . V_238 . V_242 =
F_124 ( 0 ) | F_125 ( 1 ) |
F_126 ( 0 ) | F_127 ( 0 ) ;
#endif
F_128 ( & V_6 -> V_236 . V_237 . V_238 . V_242 ) ;
memcpy ( & V_6 -> V_236 . V_237 . V_238 . V_244 , V_229 ,
sizeof( union V_229 ) ) ;
if ( V_231 -> V_36 ) {
V_6 -> V_236 . V_237 . V_238 . V_245 = F_93 ( V_28 -> V_114 + 8 ) ;
V_232 += 8 ;
} else {
V_6 -> V_236 . V_237 . V_238 . V_245 = F_93 ( V_28 -> V_114 ) ;
}
V_232 += V_28 -> V_114 ;
V_234 = V_6 -> V_236 . V_237 . V_36 ;
if ( V_231 -> V_36 ) {
memcpy ( V_234 , V_231 -> V_246 , sizeof( V_231 -> V_246 ) ) ;
V_234 += sizeof( V_231 -> V_246 ) ;
memcpy ( V_234 , V_231 -> V_36 , V_28 -> V_114 ) ;
} else {
memcpy ( V_234 , V_28 -> V_36 , V_28 -> V_114 ) ;
}
V_234 += V_28 -> V_114 ;
if ( V_231 -> V_36 )
memcpy ( V_234 , V_231 -> V_247 , sizeof( V_231 -> V_247 ) ) ;
F_8 ( & V_6 -> V_48 , V_6 -> V_34 ,
V_6 -> V_55 ,
& V_6 -> V_236 , F_96 ( V_232 ) ,
V_248 , V_6 -> V_38 ) ;
V_6 -> V_48 . V_14 |= V_249 ;
V_29 = 1 ;
V_52 = F_15 ( V_6 , & V_6 -> V_48 , V_89 ) ;
if ( V_52 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_75 , V_52 ) ;
V_29 = 3 ;
}
exit:
return V_29 ;
}
void F_129 ( struct V_250 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_251 ;
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( ! V_6 -> V_38 -> V_41 ) {
int V_252 ;
V_252 = ! F_12 ( V_50 , & V_6 -> V_43 ) ;
V_252 |= ! F_12 ( V_42 , & V_6 -> V_43 ) ;
if ( V_252 )
F_13 ( & V_6 -> V_47 ) ;
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static void V_65 ( unsigned long V_36 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
struct V_4 * V_88 , * V_253 ;
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_130 (ctlx, temp, &hw->ctlxq.reapable, list) {
F_92 ( & V_88 -> V_10 ) ;
F_42 ( V_88 ) ;
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static void V_67 ( unsigned long V_36 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
struct V_4 * V_88 , * V_253 ;
unsigned long V_149 ;
int V_254 = 0 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_130 (ctlx, temp, &hw->ctlxq.completing, list) {
if ( V_88 -> V_125 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_88 -> V_125 ( V_6 , V_88 ) ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_88 -> V_125 = NULL ;
if ( V_6 -> V_38 -> V_41 ) {
V_254 = 0 ;
break;
}
}
if ( V_88 -> V_62 ) {
F_91 ( & V_88 -> V_10 , & V_6 -> V_7 . V_62 ) ;
V_254 = 1 ;
}
V_25 ( & V_88 -> V_32 ) ;
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( V_254 )
F_131 ( & V_6 -> V_64 ) ;
}
static int F_132 ( struct V_5 * V_6 ,
struct V_4 * V_88 )
{
int V_52 ;
V_6 -> V_76 . V_14 |= V_255 ;
V_52 = F_133 ( & V_6 -> V_76 ) ;
if ( V_52 != - V_235 ) {
V_88 -> V_79 = V_155 ;
F_134 ( V_6 , V_88 ) ;
V_52 = 0 ;
}
return V_52 ;
}
static void F_134 ( struct V_5 * V_6 ,
struct V_4 * V_88 )
{
F_91 ( & V_88 -> V_10 , & V_6 -> V_7 . V_61 ) ;
F_131 ( & V_6 -> V_66 ) ;
switch ( V_88 -> V_79 ) {
case V_118 :
case V_155 :
break;
default:
F_23 ( V_6 -> V_38 -> V_45 , L_76 ,
F_49 ( V_88 -> V_156 . type ) ,
F_1 ( V_88 -> V_79 ) ) ;
break;
}
}
static void F_26 ( struct V_5 * V_6 )
{
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( ! F_135 ( & V_6 -> V_7 . V_8 ) ||
F_9 ( V_50 , & V_6 -> V_43 ) || V_6 -> V_38 -> V_41 )
goto V_256;
while ( ! F_135 ( & V_6 -> V_7 . V_60 ) ) {
struct V_4 * V_105 ;
int V_29 ;
V_105 = F_3 ( V_6 -> V_7 . V_60 . V_9 ,
struct V_4 , V_10 ) ;
F_91 ( & V_105 -> V_10 , & V_6 -> V_7 . V_8 ) ;
F_8 ( & V_6 -> V_76 , V_6 -> V_34 ,
V_6 -> V_55 ,
& V_105 -> V_156 , F_96 ( V_105 -> V_161 ) ,
V_257 , V_6 ) ;
V_6 -> V_76 . V_14 |= V_249 ;
V_29 = F_10 ( & V_6 -> V_76 , V_89 ) ;
if ( V_29 == 0 ) {
V_105 -> V_79 = V_258 ;
V_6 -> V_153 = 0 ;
V_6 -> V_74 . V_259 = V_260 + V_261 ;
F_136 ( & V_6 -> V_74 ) ;
V_6 -> V_154 = 0 ;
V_6 -> V_72 . V_259 = V_260 + 2 * V_261 ;
F_136 ( & V_6 -> V_72 ) ;
break;
}
if ( V_29 == - V_44 ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_23 ,
V_6 -> V_38 -> V_45 -> V_46 ) ;
F_137 ( & V_105 -> V_10 , & V_6 -> V_7 . V_60 ) ;
F_17 ( V_50 , & V_6 -> V_43 ) ;
F_13 ( & V_6 -> V_47 ) ;
break;
}
if ( V_29 == - V_262 ) {
F_11 ( V_6 -> V_38 -> V_45 , L_77 ,
V_6 -> V_38 -> V_45 -> V_46 ) ;
break;
}
F_23 ( V_6 -> V_38 -> V_45 , L_78 ,
F_49 ( V_105 -> V_156 . type ) , V_29 ) ;
F_134 ( V_6 , V_105 ) ;
}
V_256:
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static void V_37 ( struct V_11 * V_11 )
{
struct V_250 * V_38 = V_11 -> V_24 ;
struct V_5 * V_6 ;
union V_30 * V_263 ;
struct V_27 * V_28 = NULL ;
int V_29 ;
int V_264 ;
T_4 type ;
enum T_9 {
V_265 ,
V_266 ,
ABORT
} V_267 ;
if ( ! V_38 || ! V_38 -> V_45 || V_38 -> V_41 )
goto exit;
V_6 = V_38 -> V_251 ;
if ( ! V_6 )
goto exit;
V_28 = V_6 -> V_39 ;
if ( ! V_28 || ( V_28 -> V_36 != V_11 -> V_15 ) ) {
F_138 ( 1 ) ;
return;
}
V_6 -> V_39 = NULL ;
switch ( V_11 -> V_13 ) {
case 0 :
V_267 = V_265 ;
if ( V_11 -> V_17 == 0 ) {
V_38 -> V_45 -> V_268 . V_269 ++ ;
V_38 -> V_45 -> V_268 . V_270 ++ ;
V_267 = V_266 ;
}
break;
case - V_44 :
F_11 ( V_6 -> V_38 -> V_45 , L_22 ,
V_38 -> V_45 -> V_46 ) ;
if ( ! F_12 ( V_42 , & V_6 -> V_43 ) )
F_13 ( & V_6 -> V_47 ) ;
V_38 -> V_45 -> V_268 . V_269 ++ ;
V_267 = ABORT ;
break;
case - V_271 :
case - V_272 :
case - V_273 :
if ( ! F_12 ( V_274 , & V_6 -> V_43 ) &&
! F_139 ( & V_6 -> V_70 ) ) {
F_140 ( & V_6 -> V_70 , V_260 + V_275 ) ;
}
V_38 -> V_45 -> V_268 . V_269 ++ ;
V_267 = ABORT ;
break;
case - V_276 :
V_38 -> V_45 -> V_268 . V_277 ++ ;
V_267 = V_266 ;
break;
case - V_151 :
case - V_262 :
F_5 ( L_79 , V_11 -> V_13 ) ;
V_267 = ABORT ;
break;
case - V_278 :
case - V_279 :
F_5 ( L_80 , V_11 -> V_13 ) ;
V_267 = ABORT ;
break;
default:
F_5 ( L_81 ,
V_11 -> V_13 , V_11 -> V_14 ) ;
V_38 -> V_45 -> V_268 . V_269 ++ ;
V_267 = V_266 ;
break;
}
V_264 = V_11 -> V_13 ;
if ( V_267 != ABORT ) {
V_29 = F_6 ( V_6 , V_89 ) ;
if ( V_29 != 0 ) {
F_23 ( V_6 -> V_38 -> V_45 ,
L_82 ,
V_29 ) ;
}
}
V_263 = (union V_30 * ) V_11 -> V_15 ;
type = F_49 ( V_263 -> type ) ;
if ( F_141 ( type ) ) {
if ( V_267 == V_265 ) {
if ( V_263 -> V_237 . V_238 . V_240 == 0x0123 ) {
F_142 ( V_38 , V_263 ) ;
} else {
F_143 ( V_28 , sizeof( * V_263 ) ) ;
F_144 ( V_38 , V_28 ) ;
V_28 = NULL ;
}
}
goto exit;
}
if ( F_145 ( type ) ) {
if ( V_267 == V_265 )
F_142 ( V_38 , V_263 ) ;
goto exit;
}
switch ( type ) {
case V_280 :
if ( V_267 == ABORT )
goto exit;
if ( V_267 == V_265 )
F_146 ( V_38 , V_263 ) ;
break;
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
F_147 ( V_6 , V_263 , V_264 ) ;
break;
case V_286 :
F_5 ( L_83 ,
V_263 -> V_287 . V_103 ) ;
break;
case V_288 :
F_5 ( L_84 ,
V_263 -> V_289 . V_290 ) ;
break;
default:
F_5 ( L_85 ,
V_263 -> type , V_264 ) ;
break;
}
exit:
if ( V_28 )
F_14 ( V_28 ) ;
}
static void F_147 ( struct V_5 * V_6 , union V_30 * V_263 ,
int V_264 )
{
struct V_4 * V_88 ;
int V_291 = 0 ;
unsigned long V_149 ;
V_292:
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( F_135 ( & V_6 -> V_7 . V_8 ) )
goto V_256;
if ( F_148 ( & V_6 -> V_72 ) == 0 ) {
if ( V_6 -> V_154 == 0 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
goto V_292;
}
} else {
V_6 -> V_154 = 1 ;
}
V_88 = F_2 ( V_6 ) ;
if ( V_264 != 0 ) {
if ( F_132 ( V_6 , V_88 ) == 0 )
V_291 = 1 ;
} else {
const T_7 V_293 = ( V_263 -> type & ~ F_93 ( 0x8000 ) ) ;
if ( V_88 -> V_156 . type != V_293 ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_86 ,
F_49 ( V_88 -> V_156 . type ) ,
F_49 ( V_293 ) ) ;
goto V_256;
}
memcpy ( & V_88 -> V_120 , V_263 , sizeof( V_88 -> V_120 ) ) ;
switch ( V_88 -> V_79 ) {
case V_258 :
F_5 ( L_87 ) ;
V_88 -> V_79 = V_294 ;
break;
case V_295 :
V_88 -> V_79 = V_118 ;
F_134 ( V_6 , V_88 ) ;
V_291 = 1 ;
break;
default:
F_23 ( V_6 -> V_38 -> V_45 ,
L_88 ,
F_49 ( V_88 -> V_156 . type ) ,
F_1 ( V_88 -> V_79 ) ) ;
if ( F_132 ( V_6 , V_88 ) == 0 )
V_291 = 1 ;
break;
}
}
V_256:
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( V_291 )
F_26 ( V_6 ) ;
}
static void F_142 ( struct V_250 * V_38 ,
union V_30 * V_263 )
{
T_4 V_13 ;
V_13 = F_49 ( V_263 -> type ) ;
if ( F_149 ( V_13 ) )
F_150 ( V_38 , V_13 ) ;
else
F_151 ( V_38 , V_13 ) ;
}
static void F_144 ( struct V_250 * V_38 , struct V_27 * V_28 )
{
union V_30 * V_263 = (union V_30 * ) V_28 -> V_36 ;
struct V_5 * V_6 = V_38 -> V_251 ;
int V_296 ;
struct V_297 * V_298 ;
T_4 V_245 ;
T_4 V_299 ;
F_102 ( & V_263 -> V_300 . V_238 . V_13 ) ;
F_152 ( & V_263 -> V_300 . V_238 . time ) ;
switch ( F_153 ( V_263 -> V_300 . V_238 . V_13 ) ) {
case 0 :
V_299 = F_49 ( V_263 -> V_300 . V_238 . V_244 ) ;
if ( ( V_38 -> V_301 & V_302 ) &&
! F_154 ( V_299 ) ) {
break;
}
V_245 = F_49 ( V_263 -> V_300 . V_238 . V_245 ) ;
V_296 = F_155 ( V_299 ) ;
F_156 ( V_28 , sizeof( struct V_303 ) ) ;
memmove ( F_157 ( V_28 , V_296 ) ,
& V_263 -> V_300 . V_238 . V_244 , V_296 ) ;
V_28 -> V_304 = V_38 -> V_45 ;
F_158 ( V_28 , V_245 + V_296 ) ;
memset ( F_143 ( V_28 , V_305 ) , 0xff , V_305 ) ;
F_159 ( V_28 ) ;
F_160 ( V_38 , V_28 ) ;
V_298 = F_161 ( V_28 ) ;
V_298 -> V_306 = V_263 -> V_300 . V_238 . time ;
V_298 -> V_307 = V_263 -> V_300 . V_238 . V_308 ;
V_298 -> signal = V_263 -> V_300 . V_238 . signal - V_6 -> V_309 ;
V_298 -> V_310 = V_263 -> V_300 . V_238 . V_311 - V_6 -> V_309 ;
F_162 ( V_38 , V_28 ) ;
break;
case 7 :
if ( ! F_163 ( V_263 -> V_300 . V_238 . V_13 ) ) {
F_164 ( V_38 , & V_263 -> V_300 ) ;
F_14 ( V_28 ) ;
} else {
F_5 ( L_89 ) ;
}
break;
default:
F_11 ( V_6 -> V_38 -> V_45 , L_90 ,
F_153 (
V_263 -> V_300 . V_238 . V_13 ) ) ;
break;
}
}
static void F_164 ( struct V_250 * V_38 ,
struct V_312 * V_300 )
{
struct V_303 * V_313 = & V_300 -> V_238 ;
unsigned int V_296 = 0 ;
unsigned int V_314 = 0 ;
unsigned int V_315 = 0 ;
T_6 * V_316 ;
T_4 V_299 ;
struct V_27 * V_28 ;
struct V_5 * V_6 = V_38 -> V_251 ;
V_299 = F_49 ( V_313 -> V_244 ) ;
V_296 = F_155 ( V_299 ) ;
V_314 = F_49 ( V_313 -> V_245 ) ;
V_315 = sizeof( struct V_317 ) + V_296 + V_314 + V_305 ;
if ( V_315 >
( sizeof( struct V_317 ) +
V_318 + V_319 + V_305 ) ) {
F_5 ( L_91 ,
V_315 - sizeof( struct V_317 ) ) ;
}
V_28 = F_7 ( V_315 ) ;
if ( ! V_28 )
return;
if ( ( V_38 -> V_45 -> type == V_320 ) &&
( V_6 -> V_321 != 0 ) ) {
struct V_317 * V_322 ;
V_316 = F_143 ( V_28 , sizeof( struct V_317 ) ) ;
V_322 = (struct V_317 * ) V_316 ;
V_322 -> V_323 = F_165 ( V_324 ) ;
V_322 -> V_325 = F_165 ( sizeof( struct V_317 ) ) ;
V_322 -> V_306 = F_166 ( V_313 -> time * 1000 ) ;
V_322 -> V_326 = F_166 ( V_260 ) ;
V_322 -> V_327 = F_165 ( 4 ) ;
V_322 -> V_328 = F_165 ( V_6 -> V_329 ) ;
V_322 -> V_330 = F_165 ( V_313 -> V_308 ) ;
V_322 -> V_331 = F_165 ( 0 ) ;
V_322 -> V_332 = F_165 ( 0 ) ;
V_322 -> V_333 = F_165 ( 3 ) ;
V_322 -> V_334 = F_165 ( V_313 -> signal ) ;
V_322 -> V_335 = F_165 ( V_313 -> V_311 ) ;
V_322 -> V_336 = F_165 ( 0 ) ;
V_322 -> V_337 = F_165 ( 1 ) ;
}
F_167 ( V_28 , & V_313 -> V_244 , V_296 ) ;
if ( V_314 > 0 ) {
V_316 = F_167 ( V_28 , V_300 -> V_36 , V_314 ) ;
if ( * ( V_316 - V_296 + 1 ) & 0x40 )
if ( ( * ( V_316 ) == 0xaa ) && ( * ( V_316 + 1 ) == 0xaa ) )
* ( V_316 - V_296 + 1 ) &= 0xbf ;
}
if ( V_6 -> V_338 ) {
V_316 = F_143 ( V_28 , V_305 ) ;
memset ( V_316 , 0xff , V_305 ) ;
}
F_162 ( V_38 , V_28 ) ;
}
static void F_146 ( struct V_250 * V_38 ,
union V_30 * V_263 )
{
F_102 ( & V_263 -> V_339 . V_340 . V_341 ) ;
F_168 ( V_38 , & V_263 -> V_339 . V_340 ) ;
}
static void V_248 ( struct V_11 * V_11 )
{
struct V_250 * V_38 = V_11 -> V_24 ;
#ifdef F_169
F_4 ( V_11 ) ;
#endif
if ( V_38 && V_38 -> V_45 ) {
switch ( V_11 -> V_13 ) {
case 0 :
F_170 ( V_38 ) ;
break;
case - V_44 :
{
struct V_5 * V_6 = V_38 -> V_251 ;
F_11 ( V_6 -> V_38 -> V_45 ,
L_23 ,
V_38 -> V_45 -> V_46 ) ;
if ( ! F_12
( V_50 , & V_6 -> V_43 ) )
F_13 ( & V_6 -> V_47 ) ;
V_38 -> V_45 -> V_268 . V_342 ++ ;
break;
}
case - V_273 :
case - V_272 :
case - V_271 :
{
struct V_5 * V_6 = V_38 -> V_251 ;
if ( ! F_12
( V_343 , & V_6 -> V_43 ) &&
! F_139 ( & V_6 -> V_70 ) ) {
F_140 ( & V_6 -> V_70 ,
V_260 + V_275 ) ;
}
V_38 -> V_45 -> V_268 . V_342 ++ ;
F_18 ( V_38 -> V_45 ) ;
break;
}
case - V_278 :
case - V_262 :
break;
default:
F_24 ( V_38 -> V_45 , L_92 ,
V_11 -> V_13 ) ;
V_38 -> V_45 -> V_268 . V_342 ++ ;
break;
}
}
}
static void V_257 ( struct V_11 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_24 ;
int V_344 = 0 ;
int V_345 = 1 ;
int V_291 = 0 ;
struct V_4 * V_88 ;
unsigned long V_149 ;
F_5 ( L_93 , V_11 -> V_13 ) ;
#ifdef F_169
F_4 ( V_11 ) ;
#endif
if ( ( V_11 -> V_13 == - V_262 ) ||
( V_11 -> V_13 == - V_151 ) || ! V_6 )
return;
V_292:
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( F_135 ( & V_6 -> V_7 . V_8 ) ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
return;
}
if ( F_148 ( & V_6 -> V_74 ) == 0 ) {
if ( V_6 -> V_153 == 0 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
goto V_292;
}
} else {
V_6 -> V_153 = 1 ;
}
V_88 = F_2 ( V_6 ) ;
if ( V_11 -> V_13 == 0 ) {
switch ( V_88 -> V_79 ) {
case V_258 :
V_88 -> V_79 = V_295 ;
break;
case V_294 :
V_88 -> V_79 = V_118 ;
F_134 ( V_6 , V_88 ) ;
V_291 = 1 ;
break;
default:
F_23 ( V_6 -> V_38 -> V_45 ,
L_94 ,
F_49 ( V_88 -> V_156 . type ) ,
F_1 ( V_88 -> V_79 ) , V_11 -> V_13 ) ;
break;
}
} else {
if ( ( V_11 -> V_13 == - V_44 ) &&
! F_12 ( V_50 , & V_6 -> V_43 ) ) {
F_11 ( V_6 -> V_38 -> V_45 ,
L_23 ,
V_6 -> V_38 -> V_45 -> V_46 ) ;
F_13 ( & V_6 -> V_47 ) ;
}
V_88 -> V_79 = V_155 ;
F_134 ( V_6 , V_88 ) ;
V_344 = 1 ;
V_291 = 1 ;
}
V_346:
if ( V_344 ) {
V_345 = F_148 ( & V_6 -> V_72 ) ;
if ( V_345 != 0 )
V_6 -> V_154 = 1 ;
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( ! V_345 && ( V_6 -> V_154 == 0 ) ) {
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
goto V_346;
}
if ( V_291 )
F_26 ( V_6 ) ;
}
static void V_75 ( unsigned long V_36 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_6 -> V_153 = 1 ;
if ( ! F_135 ( & V_6 -> V_7 . V_8 ) ) {
V_6 -> V_76 . V_14 |= V_255 ;
if ( F_133 ( & V_6 -> V_76 ) == - V_235 ) {
struct V_4 * V_88 = F_2 ( V_6 ) ;
V_88 -> V_79 = V_155 ;
if ( F_148 ( & V_6 -> V_72 ) != 0 )
V_6 -> V_154 = 1 ;
}
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static void V_73 ( unsigned long V_36 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
V_6 -> V_154 = 1 ;
if ( ! F_135 ( & V_6 -> V_7 . V_8 ) ) {
struct V_4 * V_88 = F_2 ( V_6 ) ;
if ( F_132 ( V_6 , V_88 ) == 0 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_26 ( V_6 ) ;
return;
}
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static void V_71 ( unsigned long V_36 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_5 ( L_95 , V_6 -> V_43 ) ;
if ( ! V_6 -> V_38 -> V_41 &&
( ( F_27 ( V_274 , & V_6 -> V_43 ) &&
! F_12 ( V_53 , & V_6 -> V_43 ) ) |
( F_27 ( V_343 , & V_6 -> V_43 ) &&
! F_12 ( V_56 , & V_6 -> V_43 ) )
) ) {
F_13 ( & V_6 -> V_47 ) ;
}
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_4 * V_88 )
{
unsigned long V_149 ;
F_88 ( & V_6 -> V_7 . V_59 , V_149 ) ;
if ( V_6 -> V_38 -> V_41 ) {
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
return - V_151 ;
}
V_88 -> V_79 = V_347 ;
F_171 ( & V_88 -> V_10 , & V_6 -> V_7 . V_60 ) ;
F_89 ( & V_6 -> V_7 . V_59 , V_149 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int F_115 ( T_4 V_217 )
{
switch ( V_217 ) {
case V_225 :
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
case V_375 :
return 1 ;
default:
if ( V_217 < 0x1000 ) {
F_5 ( L_96 ,
V_217 ) ;
return 1 ;
}
break;
}
F_5 ( L_97 ,
V_217 ) ;
return 0 ;
}
