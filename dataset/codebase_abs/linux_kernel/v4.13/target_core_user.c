static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 , V_11 , V_12 = 0 ;
bool V_13 = ( V_3 == V_14 ) ;
if ( ! V_2 -> V_15 [ V_16 ] ||
! V_2 -> V_15 [ V_17 ] ) {
F_2 ( V_18 L_1 ) ;
return - V_19 ;
}
V_10 = F_3 ( V_2 -> V_15 [ V_17 ] ) ;
V_11 = F_4 ( V_2 -> V_15 [ V_16 ] ) ;
V_5 = F_5 ( V_10 , ! V_13 ) ;
if ( ! V_5 ) {
F_2 ( V_18 L_2 ,
V_3 , V_11 , V_10 ) ;
return - V_20 ;
}
V_7 = F_6 ( V_5 ) ;
F_7 ( & V_7 -> V_21 ) ;
V_9 = & V_7 -> V_22 ;
F_8 ( L_3 , V_10 ,
V_9 -> V_23 , V_3 , V_11 ) ;
if ( V_9 -> V_23 != V_3 ) {
F_2 ( V_18 L_4 ,
V_3 , V_9 -> V_23 ) ;
V_12 = - V_19 ;
} else {
V_9 -> V_24 = V_11 ;
}
F_9 ( & V_7 -> V_21 ) ;
if ( ! V_13 )
F_10 ( & V_5 -> V_25 . V_26 ) ;
if ( ! V_12 )
F_11 ( & V_9 -> F_11 ) ;
return V_12 ;
}
static int F_12 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
return F_1 ( V_2 , V_14 ) ;
}
static int F_13 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
return F_1 ( V_2 , V_29 ) ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
return F_1 ( V_2 , V_30 ) ;
}
static int F_15 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
if ( V_2 -> V_15 [ V_31 ] ) {
V_32 =
F_16 ( V_2 -> V_15 [ V_31 ] ) ;
F_2 ( V_33 L_5 ,
V_32 ) ;
}
return 0 ;
}
static void F_17 ( struct V_34 * V_34 , T_1 V_35 )
{
struct V_6 * V_7 = V_34 -> V_6 ;
T_1 V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
F_18 ( V_34 -> V_37 [ V_36 ] , V_7 -> V_38 ) ;
}
static inline bool F_19 ( struct V_6 * V_7 ,
struct V_34 * V_34 )
{
struct V_39 * V_39 ;
int V_12 , V_37 ;
V_37 = F_20 ( V_7 -> V_38 , V_7 -> V_40 ) ;
if ( V_37 == V_7 -> V_40 )
return false ;
V_39 = F_21 ( & V_7 -> V_41 , V_37 ) ;
if ( ! V_39 ) {
if ( F_22 ( 1 , & V_42 ) >
V_43 ) {
F_23 ( & V_42 ) ;
return false ;
}
V_39 = F_24 ( V_44 ) ;
if ( ! V_39 )
goto V_45;
V_12 = F_25 ( & V_7 -> V_41 , V_37 , V_39 ) ;
if ( V_12 )
goto V_46;
}
if ( V_37 > V_7 -> V_47 )
V_7 -> V_47 = V_37 ;
F_26 ( V_37 , V_7 -> V_38 ) ;
F_27 ( V_34 , V_37 ) ;
return true ;
V_46:
F_28 ( V_39 ) ;
V_45:
F_23 ( & V_42 ) ;
return false ;
}
static bool F_29 ( struct V_6 * V_7 ,
struct V_34 * V_34 )
{
int V_36 ;
V_7 -> V_48 = false ;
for ( V_36 = V_34 -> V_49 ; V_36 < V_34 -> V_50 ; V_36 ++ ) {
if ( ! F_19 ( V_7 , V_34 ) )
goto V_51;
}
return true ;
V_51:
V_7 -> V_48 = true ;
F_30 ( & V_52 ) ;
return false ;
}
static inline struct V_39 *
F_31 ( struct V_6 * V_7 , T_1 V_37 )
{
return F_21 ( & V_7 -> V_41 , V_37 ) ;
}
static inline void F_32 ( struct V_34 * V_34 )
{
F_33 ( V_34 -> V_37 ) ;
F_34 ( V_53 , V_34 ) ;
}
static inline T_2 F_35 ( struct V_34 * V_34 )
{
struct V_54 * V_54 = V_34 -> V_54 ;
T_2 V_55 = F_36 ( V_54 -> V_55 , V_56 ) ;
if ( V_54 -> V_57 & V_58 ) {
F_37 ( ! ( V_54 -> V_59 && V_54 -> V_60 ) ) ;
V_55 += F_36 ( V_54 -> V_59 -> V_61 ,
V_56 ) ;
}
return V_55 ;
}
static inline T_1 F_38 ( struct V_34 * V_34 )
{
T_2 V_55 = F_35 ( V_34 ) ;
return V_55 / V_56 ;
}
static struct V_34 * F_39 ( struct V_54 * V_54 )
{
struct V_4 * V_62 = V_54 -> V_62 ;
struct V_6 * V_7 = F_6 ( V_62 ) ;
struct V_34 * V_34 ;
int V_63 ;
V_34 = F_40 ( V_53 , V_44 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_54 = V_54 ;
V_34 -> V_6 = V_7 ;
if ( V_7 -> V_64 )
V_34 -> V_65 = V_66 +
F_41 ( V_7 -> V_64 ) ;
F_42 ( V_34 ) ;
V_34 -> V_50 = F_38 ( V_34 ) ;
V_34 -> V_37 = F_43 ( V_34 -> V_50 , sizeof( T_1 ) ,
V_44 ) ;
if ( ! V_34 -> V_37 ) {
F_34 ( V_53 , V_34 ) ;
return NULL ;
}
F_44 ( V_44 ) ;
F_45 ( & V_7 -> V_67 ) ;
V_63 = F_46 ( & V_7 -> V_68 , V_34 , 0 ,
V_69 , V_70 ) ;
F_47 ( & V_7 -> V_67 ) ;
F_48 () ;
if ( V_63 < 0 ) {
F_32 ( V_34 ) ;
return NULL ;
}
V_34 -> V_63 = V_63 ;
return V_34 ;
}
static inline void F_49 ( void * V_71 , T_2 V_72 )
{
unsigned long V_73 = F_50 ( V_71 ) ;
V_72 = F_36 ( V_72 + V_73 , V_74 ) ;
V_71 -= V_73 ;
while ( V_72 ) {
F_51 ( F_52 ( V_71 ) ) ;
V_72 -= V_74 ;
}
}
static inline T_2 F_53 ( T_2 V_75 , T_2 V_76 , T_2 V_72 )
{
int V_77 = V_75 - V_76 ;
if ( V_77 >= 0 )
return V_77 ;
else
return V_72 + V_77 ;
}
static inline T_2 F_54 ( T_2 V_75 , T_2 V_76 , T_2 V_72 )
{
return ( V_72 - F_53 ( V_75 , V_76 , V_72 ) - 1 ) ;
}
static inline T_2 F_55 ( T_2 V_75 , T_2 V_72 )
{
return V_72 - V_75 ;
}
static inline void F_56 ( struct V_78 * * V_79 , int * V_80 ,
struct V_6 * V_7 )
{
struct V_78 * V_78 ;
if ( * V_80 != 0 )
( * V_79 ) ++ ;
( * V_80 ) ++ ;
V_78 = * V_79 ;
memset ( V_78 , 0 , sizeof( struct V_78 ) ) ;
}
static inline T_2 F_57 ( struct V_6 * V_5 ,
int V_37 , int V_81 )
{
return V_5 -> V_82 + V_37 * V_56 +
V_56 - V_81 ;
}
static inline T_2 F_58 ( struct V_78 * V_79 )
{
return ( T_2 ) V_79 -> V_83 + V_79 -> V_84 ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_34 * V_34 , struct V_85 * V_86 ,
unsigned int V_87 , struct V_78 * * V_79 ,
int * V_80 , bool V_88 )
{
int V_36 , V_37 ;
int V_89 = 0 ;
void * V_90 , * V_91 = NULL ;
T_2 V_92 , V_93 , V_73 ;
struct V_85 * V_94 ;
struct V_39 * V_39 ;
F_60 (data_sg, sg, data_nents, i) {
int V_95 = V_94 -> V_61 ;
V_90 = F_61 ( F_62 ( V_94 ) ) + V_94 -> V_73 ;
while ( V_95 > 0 ) {
if ( V_89 == 0 ) {
if ( V_91 )
F_63 ( V_91 ) ;
V_89 = V_56 ;
V_37 = F_64 ( V_34 ) ;
V_39 = F_31 ( V_7 , V_37 ) ;
V_91 = F_61 ( V_39 ) ;
}
V_92 = F_65 ( T_2 , V_95 ,
V_89 ) ;
V_93 = F_57 ( V_7 , V_37 ,
V_89 ) ;
if ( * V_80 != 0 &&
V_93 == F_58 ( * V_79 ) ) {
( * V_79 ) -> V_84 += V_92 ;
} else {
F_56 ( V_79 , V_80 , V_7 ) ;
( * V_79 ) -> V_83 = ( void V_96 * ) V_93 ;
( * V_79 ) -> V_84 = V_92 ;
}
if ( V_88 ) {
V_73 = V_56 - V_89 ;
memcpy ( V_91 + V_73 ,
V_90 + V_94 -> V_61 - V_95 ,
V_92 ) ;
F_49 ( V_91 , V_92 ) ;
}
V_95 -= V_92 ;
V_89 -= V_92 ;
}
F_63 ( V_90 - V_94 -> V_73 ) ;
}
if ( V_91 )
F_63 ( V_91 ) ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 , struct V_34 * V_23 ,
bool V_97 )
{
struct V_54 * V_54 = V_23 -> V_54 ;
int V_36 , V_37 ;
int V_89 = 0 ;
void * V_90 = NULL , * V_91 ;
T_2 V_92 , V_73 ;
struct V_85 * V_94 , * V_86 ;
struct V_39 * V_39 ;
unsigned int V_87 ;
T_1 V_98 = 0 ;
if ( ! V_97 ) {
V_86 = V_54 -> V_99 ;
V_87 = V_54 -> V_100 ;
} else {
V_98 = F_67 ( V_54 -> V_55 , V_56 ) ;
V_86 = V_54 -> V_59 ;
V_87 = V_54 -> V_60 ;
}
F_68 ( V_23 , V_98 ) ;
F_60 (data_sg, sg, data_nents, i) {
int V_95 = V_94 -> V_61 ;
V_91 = F_61 ( F_62 ( V_94 ) ) + V_94 -> V_73 ;
while ( V_95 > 0 ) {
if ( V_89 == 0 ) {
if ( V_90 )
F_63 ( V_90 ) ;
V_89 = V_56 ;
V_37 = F_64 ( V_23 ) ;
V_39 = F_31 ( V_7 , V_37 ) ;
V_90 = F_61 ( V_39 ) ;
}
V_92 = F_65 ( T_2 , V_95 ,
V_89 ) ;
V_73 = V_56 - V_89 ;
F_49 ( V_90 , V_92 ) ;
memcpy ( V_91 + V_94 -> V_61 - V_95 , V_90 + V_73 ,
V_92 ) ;
V_95 -= V_92 ;
V_89 -= V_92 ;
}
F_63 ( V_91 - V_94 -> V_73 ) ;
}
if ( V_90 )
F_63 ( V_90 ) ;
}
static inline T_2 F_69 ( unsigned long * V_101 , T_1 V_102 )
{
return V_56 * ( V_102 - F_70 ( V_101 , V_102 ) ) ;
}
static bool F_71 ( struct V_6 * V_7 , struct V_34 * V_23 ,
T_2 V_103 , T_2 V_104 )
{
struct V_105 * V_106 = V_7 -> V_107 ;
T_1 V_108 = ( V_104 + V_56 - 1 )
/ V_56 ;
T_2 V_109 , V_110 ;
T_3 V_111 ;
F_49 ( V_106 , sizeof( * V_106 ) ) ;
V_111 = V_106 -> V_111 % V_7 -> V_112 ;
if ( F_55 ( V_111 , V_7 -> V_112 ) >= V_103 )
V_110 = V_103 ;
else
V_110 = V_103 + F_55 ( V_111 , V_7 -> V_112 ) ;
V_109 = F_54 ( V_111 , V_7 -> V_113 , V_7 -> V_112 ) ;
if ( V_109 < V_110 ) {
F_8 ( L_6 , V_111 ,
V_7 -> V_113 , V_7 -> V_112 ) ;
return false ;
}
V_109 = F_69 ( V_7 -> V_38 , V_7 -> V_40 ) ;
if ( V_109 < V_104 ) {
unsigned long V_114 = V_115 - V_7 -> V_40 ;
unsigned long V_116 ;
if ( V_114 < V_108 ) {
F_8 ( L_7 ,
V_114 * V_56 ,
V_104 ) ;
return false ;
}
if ( ! V_7 -> V_40 ) {
T_1 V_117 = V_118 ;
V_7 -> V_40 = F_72 ( V_108 , V_117 ) ;
} else {
V_116 = F_72 ( V_108 , V_7 -> V_40 / 2 ) ;
V_7 -> V_40 += V_116 ;
if ( V_7 -> V_40 > V_115 )
V_7 -> V_40 = V_115 ;
}
}
return F_29 ( V_7 , V_23 ) ;
}
static inline T_2 F_73 ( T_2 V_80 )
{
return F_72 ( F_74 ( struct V_119 , V_120 . V_79 [ V_80 ] ) ,
sizeof( struct V_119 ) ) ;
}
static inline T_2 F_75 ( struct V_34 * V_34 ,
T_2 V_121 )
{
struct V_54 * V_54 = V_34 -> V_54 ;
T_2 V_122 ;
V_122 = V_121 +
F_36 ( F_76 ( V_54 -> V_123 ) ,
V_124 ) ;
F_77 ( V_122 & ( V_124 - 1 ) ) ;
return V_122 ;
}
static T_4
F_78 ( struct V_34 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_6 ;
struct V_54 * V_54 = V_34 -> V_54 ;
T_2 V_121 , V_122 ;
struct V_105 * V_106 ;
struct V_119 * V_125 ;
struct V_78 * V_79 ;
int V_80 , V_12 ;
T_1 V_111 ;
T_5 V_126 ;
bool V_127 ;
T_2 V_55 = F_35 ( V_34 ) ;
if ( F_79 ( V_128 , & V_7 -> V_129 ) )
return V_130 ;
V_121 = F_73 ( V_34 -> V_50 ) ;
V_122 = F_75 ( V_34 , V_121 ) ;
F_80 ( & V_7 -> V_131 ) ;
V_106 = V_7 -> V_107 ;
V_111 = V_106 -> V_111 % V_7 -> V_112 ;
if ( ( V_122 > ( V_7 -> V_112 / 2 ) ) ||
V_55 > V_7 -> V_132 ) {
F_81 ( L_8
L_9 , V_122 , V_55 ,
V_7 -> V_112 , V_7 -> V_132 ) ;
F_82 ( & V_7 -> V_131 ) ;
return V_133 ;
}
while ( ! F_71 ( V_7 , V_34 , V_122 , V_55 ) ) {
int V_12 ;
F_83 ( V_134 ) ;
F_84 ( & V_7 -> V_135 , & V_134 , V_136 ) ;
F_8 ( L_10 ) ;
F_82 ( & V_7 -> V_131 ) ;
if ( V_7 -> V_64 )
V_12 = F_85 (
F_41 ( V_7 -> V_64 ) ) ;
else
V_12 = F_85 ( F_41 ( V_137 ) ) ;
F_86 ( & V_7 -> V_135 , & V_134 ) ;
if ( ! V_12 ) {
F_81 ( L_11 ) ;
return V_130 ;
}
F_80 ( & V_7 -> V_131 ) ;
V_111 = V_106 -> V_111 % V_7 -> V_112 ;
}
if ( F_55 ( V_111 , V_7 -> V_112 ) < V_122 ) {
T_2 V_138 = F_55 ( V_111 , V_7 -> V_112 ) ;
V_125 = ( void * ) V_106 + V_139 + V_111 ;
F_87 ( & V_125 -> V_140 . V_141 , V_142 ) ;
F_88 ( & V_125 -> V_140 . V_141 , V_138 ) ;
V_125 -> V_140 . V_63 = 0 ;
V_125 -> V_140 . V_143 = 0 ;
V_125 -> V_140 . V_144 = 0 ;
F_49 ( V_125 , sizeof( * V_125 ) ) ;
F_89 ( V_106 -> V_111 , V_138 , V_7 -> V_112 ) ;
F_49 ( V_106 , sizeof( * V_106 ) ) ;
V_111 = V_106 -> V_111 % V_7 -> V_112 ;
F_77 ( V_111 != 0 ) ;
}
V_125 = ( void * ) V_106 + V_139 + V_111 ;
memset ( V_125 , 0 , V_122 ) ;
F_87 ( & V_125 -> V_140 . V_141 , V_145 ) ;
V_125 -> V_140 . V_63 = V_34 -> V_63 ;
F_42 ( V_34 ) ;
V_79 = & V_125 -> V_120 . V_79 [ 0 ] ;
V_80 = 0 ;
V_127 = ( V_54 -> V_146 == V_147
|| V_54 -> V_57 & V_58 ) ;
V_12 = F_59 ( V_7 , V_34 , V_54 -> V_99 ,
V_54 -> V_100 , & V_79 , & V_80 ,
V_127 ) ;
if ( V_12 ) {
F_17 ( V_34 , V_34 -> V_50 ) ;
F_82 ( & V_7 -> V_131 ) ;
F_90 ( L_12 ) ;
return V_130 ;
}
V_125 -> V_120 . V_80 = V_80 ;
V_80 = 0 ;
if ( V_54 -> V_57 & V_58 ) {
V_79 ++ ;
V_12 = F_59 ( V_7 , V_34 ,
V_54 -> V_59 ,
V_54 -> V_60 ,
& V_79 , & V_80 , false ) ;
if ( V_12 ) {
F_17 ( V_34 , V_34 -> V_50 ) ;
F_82 ( & V_7 -> V_131 ) ;
F_90 ( L_13 ) ;
return V_130 ;
}
}
V_125 -> V_120 . V_148 = V_80 ;
V_121 = F_73 ( V_125 -> V_120 . V_80 +
V_125 -> V_120 . V_148 ) ;
V_122 = F_75 ( V_34 , V_121 ) ;
F_88 ( & V_125 -> V_140 . V_141 , V_122 ) ;
V_126 = V_139 + V_111 + V_121 ;
memcpy ( ( void * ) V_106 + V_126 , V_54 -> V_123 , F_76 ( V_54 -> V_123 ) ) ;
V_125 -> V_120 . V_126 = V_126 ;
F_49 ( V_125 , sizeof( * V_125 ) ) ;
F_89 ( V_106 -> V_111 , V_122 , V_7 -> V_112 ) ;
F_49 ( V_106 , sizeof( * V_106 ) ) ;
F_82 ( & V_7 -> V_131 ) ;
F_91 ( & V_7 -> V_149 ) ;
if ( V_7 -> V_64 )
F_92 ( & V_7 -> V_150 , F_93 ( V_66 +
F_41 ( V_7 -> V_64 ) ) ) ;
return V_151 ;
}
static T_4
F_94 ( struct V_54 * V_54 )
{
struct V_4 * V_62 = V_54 -> V_62 ;
struct V_6 * V_7 = F_6 ( V_62 ) ;
struct V_34 * V_34 ;
T_4 V_12 ;
V_34 = F_39 ( V_54 ) ;
if ( ! V_34 )
return V_130 ;
V_12 = F_78 ( V_34 ) ;
if ( V_12 != V_151 ) {
F_90 ( L_14 ) ;
F_45 ( & V_7 -> V_67 ) ;
F_95 ( & V_7 -> V_68 , V_34 -> V_63 ) ;
F_47 ( & V_7 -> V_67 ) ;
F_32 ( V_34 ) ;
}
return V_12 ;
}
static void F_96 ( struct V_34 * V_23 , struct V_119 * V_125 )
{
struct V_54 * V_54 = V_23 -> V_54 ;
struct V_6 * V_7 = V_23 -> V_6 ;
if ( F_79 ( V_152 , & V_23 -> V_129 ) )
goto V_153;
F_42 ( V_23 ) ;
if ( V_125 -> V_140 . V_144 & V_154 ) {
F_81 ( L_15 ,
V_23 -> V_54 ) ;
V_125 -> V_155 . V_156 = V_157 ;
} else if ( V_125 -> V_155 . V_156 == V_157 ) {
F_97 ( V_54 , V_125 -> V_155 . V_158 ) ;
} else if ( V_54 -> V_57 & V_58 ) {
F_66 ( V_7 , V_23 , true ) ;
} else if ( V_54 -> V_146 == V_159 ) {
F_66 ( V_7 , V_23 , false ) ;
} else if ( V_54 -> V_146 == V_147 ) {
} else if ( V_54 -> V_146 != V_160 ) {
F_81 ( L_16 ,
V_54 -> V_146 ) ;
}
F_98 ( V_23 -> V_54 , V_125 -> V_155 . V_156 ) ;
V_153:
V_23 -> V_54 = NULL ;
F_17 ( V_23 , V_23 -> V_50 ) ;
F_32 ( V_23 ) ;
}
static unsigned int F_99 ( struct V_6 * V_7 )
{
struct V_105 * V_106 ;
int V_161 = 0 ;
if ( F_79 ( V_128 , & V_7 -> V_129 ) ) {
F_90 ( L_17 ) ;
return 0 ;
}
V_106 = V_7 -> V_107 ;
F_49 ( V_106 , sizeof( * V_106 ) ) ;
while ( V_7 -> V_113 != F_100 ( V_106 -> V_162 ) ) {
struct V_119 * V_125 = ( void * ) V_106 + V_139 + V_7 -> V_113 ;
struct V_34 * V_23 ;
F_49 ( V_125 , sizeof( * V_125 ) ) ;
if ( F_101 ( V_125 -> V_140 . V_141 ) == V_142 ) {
F_89 ( V_7 -> V_113 ,
F_102 ( V_125 -> V_140 . V_141 ) ,
V_7 -> V_112 ) ;
continue;
}
F_77 ( F_101 ( V_125 -> V_140 . V_141 ) != V_145 ) ;
F_7 ( & V_7 -> V_67 ) ;
V_23 = F_95 ( & V_7 -> V_68 , V_125 -> V_140 . V_63 ) ;
F_9 ( & V_7 -> V_67 ) ;
if ( ! V_23 ) {
F_90 ( L_18 ) ;
F_26 ( V_128 , & V_7 -> V_129 ) ;
break;
}
F_96 ( V_23 , V_125 ) ;
F_89 ( V_7 -> V_113 ,
F_102 ( V_125 -> V_140 . V_141 ) ,
V_7 -> V_112 ) ;
V_161 ++ ;
}
if ( V_106 -> V_162 == V_106 -> V_111 )
F_103 ( & V_7 -> V_150 ) ;
F_30 ( & V_7 -> V_135 ) ;
return V_161 ;
}
static int F_104 ( int V_163 , void * V_164 , void * V_165 )
{
struct V_34 * V_23 = V_164 ;
if ( F_79 ( V_152 , & V_23 -> V_129 ) )
return 0 ;
if ( ! F_105 ( V_66 , V_23 -> V_65 ) )
return 0 ;
F_26 ( V_152 , & V_23 -> V_129 ) ;
F_98 ( V_23 -> V_54 , V_157 ) ;
V_23 -> V_54 = NULL ;
return 0 ;
}
static void F_106 ( unsigned long V_165 )
{
struct V_6 * V_7 = (struct V_6 * ) V_165 ;
unsigned long V_129 ;
F_107 ( & V_7 -> V_67 , V_129 ) ;
F_108 ( & V_7 -> V_68 , F_104 , NULL ) ;
F_109 ( & V_7 -> V_67 , V_129 ) ;
F_30 ( & V_52 ) ;
}
static int F_110 ( struct V_166 * V_167 , T_3 V_168 )
{
struct V_169 * V_169 ;
V_169 = F_111 ( sizeof( struct V_169 ) , V_44 ) ;
if ( ! V_169 )
return - V_170 ;
V_169 -> V_168 = V_168 ;
V_167 -> V_171 = V_169 ;
return 0 ;
}
static void F_112 ( struct V_166 * V_167 )
{
F_33 ( V_167 -> V_171 ) ;
V_167 -> V_171 = NULL ;
}
static struct V_4 * F_113 ( struct V_166 * V_167 , const char * V_172 )
{
struct V_6 * V_7 ;
V_7 = F_111 ( sizeof( struct V_6 ) , V_44 ) ;
if ( ! V_7 )
return NULL ;
F_114 ( & V_7 -> V_173 ) ;
V_7 -> V_172 = F_115 ( V_172 , V_44 ) ;
if ( ! V_7 -> V_172 ) {
F_33 ( V_7 ) ;
return NULL ;
}
V_7 -> V_167 = V_167 ;
V_7 -> V_64 = V_137 ;
F_116 ( & V_7 -> V_135 ) ;
F_117 ( & V_7 -> V_131 ) ;
F_118 ( & V_7 -> V_68 ) ;
F_119 ( & V_7 -> V_67 ) ;
F_120 ( & V_7 -> V_150 , F_106 ,
( unsigned long ) V_7 ) ;
F_116 ( & V_7 -> V_174 ) ;
F_119 ( & V_7 -> V_21 ) ;
return & V_7 -> V_62 ;
}
static int F_121 ( struct V_149 * V_2 , T_6 V_175 )
{
struct V_6 * V_6 = F_122 ( V_2 , struct V_6 , V_149 ) ;
F_80 ( & V_6 -> V_131 ) ;
F_99 ( V_6 ) ;
F_82 ( & V_6 -> V_131 ) ;
return 0 ;
}
static int F_123 ( struct V_176 * V_177 )
{
struct V_6 * V_7 = V_177 -> V_178 ;
struct V_149 * V_2 = & V_7 -> V_149 ;
if ( V_177 -> V_179 < V_180 ) {
if ( V_2 -> V_181 [ V_177 -> V_179 ] . V_72 == 0 )
return - 1 ;
return ( int ) V_177 -> V_179 ;
}
return - 1 ;
}
static struct V_39 * F_124 ( struct V_6 * V_7 , T_1 V_37 )
{
struct V_39 * V_39 ;
int V_12 ;
F_80 ( & V_7 -> V_131 ) ;
V_39 = F_31 ( V_7 , V_37 ) ;
if ( F_125 ( V_39 ) ) {
F_82 ( & V_7 -> V_131 ) ;
return V_39 ;
}
F_81 ( L_19 , V_37 ) ;
F_81 ( L_20 ) ;
if ( V_37 >= V_7 -> V_40 ) {
V_7 -> V_40 = V_37 + 1 ;
V_7 -> V_47 = V_37 ;
}
V_39 = F_21 ( & V_7 -> V_41 , V_37 ) ;
if ( ! V_39 ) {
V_39 = F_24 ( V_44 | V_182 ) ;
if ( ! V_39 ) {
F_82 ( & V_7 -> V_131 ) ;
return NULL ;
}
V_12 = F_25 ( & V_7 -> V_41 , V_37 , V_39 ) ;
if ( V_12 ) {
F_82 ( & V_7 -> V_131 ) ;
F_28 ( V_39 ) ;
return NULL ;
}
F_126 ( & V_42 ) ;
}
F_82 ( & V_7 -> V_131 ) ;
return V_39 ;
}
static int F_127 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = V_184 -> V_177 -> V_178 ;
struct V_149 * V_2 = & V_7 -> V_149 ;
struct V_39 * V_39 ;
unsigned long V_73 ;
void * V_185 ;
int V_186 = F_123 ( V_184 -> V_177 ) ;
if ( V_186 < 0 )
return V_187 ;
V_73 = ( V_184 -> V_188 - V_186 ) << V_189 ;
if ( V_73 < V_7 -> V_82 ) {
V_185 = ( void * ) ( unsigned long ) V_2 -> V_181 [ V_186 ] . V_185 + V_73 ;
V_39 = F_128 ( V_185 ) ;
} else {
T_1 V_37 ;
V_37 = ( V_73 - V_7 -> V_82 ) / V_56 ;
V_39 = F_124 ( V_7 , V_37 ) ;
if ( ! V_39 )
return V_190 ;
}
F_129 ( V_39 ) ;
V_184 -> V_39 = V_39 ;
return 0 ;
}
static int F_130 ( struct V_149 * V_2 , struct V_176 * V_177 )
{
struct V_6 * V_7 = F_122 ( V_2 , struct V_6 , V_149 ) ;
V_177 -> V_191 |= V_192 | V_193 ;
V_177 -> V_194 = & V_195 ;
V_177 -> V_178 = V_7 ;
if ( F_131 ( V_177 ) != ( V_196 >> V_189 ) )
return - V_19 ;
return 0 ;
}
static int F_132 ( struct V_149 * V_2 , struct V_197 * V_197 )
{
struct V_6 * V_7 = F_122 ( V_2 , struct V_6 , V_149 ) ;
if ( F_133 ( V_198 , & V_7 -> V_129 ) )
return - V_199 ;
V_7 -> V_197 = V_197 ;
F_134 ( & V_7 -> V_173 ) ;
F_8 ( L_21 ) ;
return 0 ;
}
static void F_135 ( struct V_200 * V_164 )
{
struct V_4 * V_5 = F_122 ( V_164 , struct V_4 , V_200 ) ;
struct V_6 * V_7 = F_6 ( V_5 ) ;
F_33 ( V_7 -> V_149 . V_172 ) ;
F_33 ( V_7 -> V_172 ) ;
F_33 ( V_7 ) ;
}
static void F_136 ( struct V_173 * V_173 )
{
struct V_6 * V_7 = F_122 ( V_173 , struct V_6 , V_173 ) ;
struct V_4 * V_5 = & V_7 -> V_62 ;
F_137 ( & V_5 -> V_200 , F_135 ) ;
}
static int F_138 ( struct V_149 * V_2 , struct V_197 * V_197 )
{
struct V_6 * V_7 = F_122 ( V_2 , struct V_6 , V_149 ) ;
F_18 ( V_198 , & V_7 -> V_129 ) ;
F_8 ( L_22 ) ;
F_139 ( & V_7 -> V_173 , F_136 ) ;
return 0 ;
}
static void F_140 ( struct V_6 * V_7 , int V_23 )
{
struct V_8 * V_9 = & V_7 -> V_22 ;
if ( ! V_32 )
return;
V_201:
F_7 ( & V_7 -> V_21 ) ;
if ( V_9 -> V_23 != V_202 ) {
F_9 ( & V_7 -> V_21 ) ;
F_8 ( L_23 ) ;
F_141 ( V_7 -> V_174 , ( V_9 -> V_23 == V_202 ) ) ;
goto V_201;
}
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_23 = V_23 ;
F_142 ( & V_9 -> F_11 ) ;
F_9 ( & V_7 -> V_21 ) ;
}
static int F_143 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_22 ;
int V_12 ;
F_83 ( V_134 ) ;
if ( ! V_32 )
return 0 ;
F_8 ( L_24 ) ;
F_144 ( & V_9 -> F_11 ) ;
F_7 ( & V_7 -> V_21 ) ;
V_9 -> V_23 = V_202 ;
V_12 = V_9 -> V_24 ;
V_9 -> V_24 = 0 ;
F_9 ( & V_7 -> V_21 ) ;
F_145 ( & V_7 -> V_174 ) ;
return V_12 ; ;
}
static int F_146 ( struct V_6 * V_7 , enum V_203 V_23 ,
int V_204 , const void * V_205 )
{
struct V_27 * V_28 ;
void * V_206 ;
int V_12 = - V_170 ;
V_28 = F_147 ( V_207 , V_44 ) ;
if ( ! V_28 )
return V_12 ;
V_206 = F_148 ( V_28 , 0 , 0 , & V_208 , 0 , V_23 ) ;
if ( ! V_206 )
goto V_209;
V_12 = F_149 ( V_28 , V_210 , V_7 -> V_149 . V_172 ) ;
if ( V_12 < 0 )
goto V_209;
V_12 = F_150 ( V_28 , V_211 , V_7 -> V_149 . V_212 -> V_213 ) ;
if ( V_12 < 0 )
goto V_209;
V_12 = F_150 ( V_28 , V_17 , V_7 -> V_62 . V_214 ) ;
if ( V_12 < 0 )
goto V_209;
if ( V_23 == V_30 ) {
switch ( V_204 ) {
case V_215 :
V_12 = F_149 ( V_28 , V_204 , V_205 ) ;
break;
case V_216 :
V_12 = F_151 ( V_28 , V_204 ,
* ( ( V_217 * ) V_205 ) ,
V_218 ) ;
break;
case V_219 :
V_12 = F_152 ( V_28 , V_204 ,
* ( ( V_220 * ) V_205 ) ) ;
break;
default:
F_153 () ;
}
if ( V_12 < 0 )
goto V_209;
}
F_154 ( V_28 , V_206 ) ;
F_140 ( V_7 , V_23 ) ;
V_12 = F_155 ( & V_208 , V_28 , 0 ,
V_221 , V_44 ) ;
if ( V_12 == - V_222 )
V_12 = 0 ;
if ( ! V_12 )
V_12 = F_143 ( V_7 ) ;
return V_12 ;
V_209:
F_156 ( V_28 ) ;
return V_12 ;
}
static int F_157 ( struct V_6 * V_7 )
{
struct V_169 * V_167 = V_7 -> V_167 -> V_171 ;
struct V_149 * V_2 ;
T_2 V_72 , V_223 ;
char * V_224 ;
V_2 = & V_7 -> V_149 ;
V_72 = snprintf ( NULL , 0 , L_25 , V_167 -> V_168 , V_7 -> V_172 ,
V_7 -> V_225 ) ;
V_72 += 1 ;
V_224 = F_158 ( V_72 , V_44 ) ;
if ( ! V_224 )
return - V_170 ;
V_223 = snprintf ( V_224 , V_72 , L_26 , V_167 -> V_168 , V_7 -> V_172 ) ;
if ( V_7 -> V_225 [ 0 ] )
snprintf ( V_224 + V_223 , V_72 - V_223 , L_27 , V_7 -> V_225 ) ;
F_33 ( V_2 -> V_172 ) ;
V_2 -> V_172 = V_224 ;
return 0 ;
}
static int F_159 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
struct V_149 * V_2 ;
struct V_105 * V_106 ;
int V_12 = 0 ;
V_12 = F_157 ( V_7 ) ;
if ( V_12 )
return V_12 ;
V_2 = & V_7 -> V_149 ;
V_7 -> V_107 = F_160 ( V_226 ) ;
if ( ! V_7 -> V_107 ) {
V_12 = - V_170 ;
goto V_227;
}
V_7 -> V_112 = V_226 - V_139 ;
V_7 -> V_82 = V_226 ;
V_7 -> V_132 = V_228 ;
V_7 -> V_40 = 0 ;
V_7 -> V_48 = false ;
V_106 = V_7 -> V_107 ;
V_106 -> V_229 = V_230 ;
V_106 -> V_129 = V_231 ;
V_106 -> V_232 = V_139 ;
V_106 -> V_112 = V_7 -> V_112 ;
F_77 ( ! F_161 ( V_7 -> V_82 ) ) ;
F_77 ( V_7 -> V_132 % V_74 ) ;
F_77 ( V_7 -> V_132 % V_56 ) ;
F_162 ( & V_7 -> V_41 , V_44 ) ;
V_2 -> V_229 = F_163 ( V_230 ) ;
V_2 -> V_181 [ 0 ] . V_172 = L_28 ;
V_2 -> V_181 [ 0 ] . V_185 = ( V_233 ) ( V_234 ) V_7 -> V_107 ;
V_2 -> V_181 [ 0 ] . V_72 = V_196 ;
V_2 -> V_181 [ 0 ] . V_235 = V_236 ;
V_2 -> V_237 = F_121 ;
V_2 -> V_238 = V_239 ;
V_2 -> V_240 = F_130 ;
V_2 -> V_241 = F_132 ;
V_2 -> V_242 = F_138 ;
V_12 = F_164 ( V_243 , V_2 ) ;
if ( V_12 )
goto V_244;
if ( V_5 -> V_245 . V_246 == 0 )
V_5 -> V_245 . V_246 = 512 ;
if ( ! V_5 -> V_245 . V_247 )
V_5 -> V_245 . V_247 = 128 ;
if ( ! V_5 -> V_245 . V_248 )
V_5 -> V_245 . V_248 = 0 ;
V_5 -> V_245 . V_249 = 128 ;
F_134 ( & V_7 -> V_173 ) ;
V_12 = F_146 ( V_7 , V_29 , 0 , NULL ) ;
if ( V_12 )
goto V_250;
F_80 ( & V_251 ) ;
F_165 ( & V_7 -> V_252 , & V_253 ) ;
F_82 ( & V_251 ) ;
return 0 ;
V_250:
F_139 ( & V_7 -> V_173 , F_136 ) ;
F_166 ( & V_7 -> V_149 ) ;
V_244:
F_167 ( V_7 -> V_107 ) ;
V_227:
F_33 ( V_2 -> V_172 ) ;
V_2 -> V_172 = NULL ;
return V_12 ;
}
static int F_168 ( struct V_34 * V_23 )
{
if ( F_79 ( V_152 , & V_23 -> V_129 ) ) {
F_34 ( V_53 , V_23 ) ;
return 0 ;
}
return - V_19 ;
}
static bool F_169 ( struct V_6 * V_7 )
{
return V_7 -> V_149 . V_212 ? true : false ;
}
static void F_170 ( struct V_6 * V_7 )
{
int V_36 ;
struct V_39 * V_39 ;
F_80 ( & V_7 -> V_131 ) ;
for ( V_36 = 0 ; V_36 <= V_7 -> V_47 ; V_36 ++ ) {
V_39 = F_171 ( & V_7 -> V_41 , V_36 ) ;
if ( V_39 ) {
F_28 ( V_39 ) ;
F_23 ( & V_42 ) ;
}
}
F_82 ( & V_7 -> V_131 ) ;
}
static void F_172 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
F_139 ( & V_7 -> V_173 , F_136 ) ;
}
static void F_173 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
struct V_34 * V_23 ;
bool V_254 = true ;
int V_36 ;
F_174 ( & V_7 -> V_150 ) ;
F_80 ( & V_251 ) ;
F_175 ( & V_7 -> V_252 ) ;
F_82 ( & V_251 ) ;
F_167 ( V_7 -> V_107 ) ;
F_45 ( & V_7 -> V_67 ) ;
F_176 (&udev->commands, cmd, i) {
if ( F_168 ( V_23 ) != 0 )
V_254 = false ;
}
F_177 ( & V_7 -> V_68 ) ;
F_47 ( & V_7 -> V_67 ) ;
F_77 ( ! V_254 ) ;
F_170 ( V_7 ) ;
F_146 ( V_7 , V_14 , 0 , NULL ) ;
F_166 ( & V_7 -> V_149 ) ;
F_139 ( & V_7 -> V_173 , F_136 ) ;
}
static int F_178 ( T_7 * V_255 , T_3 * V_245 )
{
unsigned long V_256 ;
char * V_257 ;
int V_12 ;
V_257 = F_179 ( V_255 ) ;
if ( ! V_257 )
return - V_170 ;
V_12 = F_180 ( V_257 , 0 , & V_256 ) ;
F_33 ( V_257 ) ;
if ( V_12 < 0 ) {
F_90 ( L_29 ) ;
return V_12 ;
}
if ( ! V_256 ) {
F_90 ( L_30 ) ;
return - V_19 ;
}
* V_245 = V_256 ;
return 0 ;
}
static T_8 F_181 ( struct V_4 * V_5 ,
const char * V_39 , T_8 V_98 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
char * V_258 , * V_259 , * V_260 , * V_257 ;
T_7 args [ V_261 ] ;
int V_12 = 0 , V_262 ;
V_260 = F_115 ( V_39 , V_44 ) ;
if ( ! V_260 )
return - V_170 ;
V_258 = V_260 ;
while ( ( V_259 = F_182 ( & V_260 , L_31 ) ) != NULL ) {
if ( ! * V_259 )
continue;
V_262 = F_183 ( V_259 , V_263 , args ) ;
switch ( V_262 ) {
case V_264 :
if ( F_184 ( V_7 -> V_225 , & args [ 0 ] ,
V_265 ) == 0 ) {
V_12 = - V_19 ;
break;
}
F_8 ( L_32 , V_7 -> V_225 ) ;
break;
case V_266 :
V_257 = F_179 ( & args [ 0 ] ) ;
if ( ! V_257 ) {
V_12 = - V_170 ;
break;
}
V_12 = F_180 ( V_257 , 0 , ( unsigned long * ) & V_7 -> V_267 ) ;
F_33 ( V_257 ) ;
if ( V_12 < 0 )
F_90 ( L_33 ) ;
break;
case V_268 :
V_12 = F_178 ( & args [ 0 ] ,
& ( V_5 -> V_245 . V_246 ) ) ;
break;
case V_269 :
V_12 = F_178 ( & args [ 0 ] ,
& ( V_5 -> V_245 . V_247 ) ) ;
break;
default:
break;
}
if ( V_12 )
break;
}
F_33 ( V_258 ) ;
return ( ! V_12 ) ? V_98 : V_12 ;
}
static T_8 F_185 ( struct V_4 * V_5 , char * V_270 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
T_8 V_271 = 0 ;
V_271 = sprintf ( V_270 + V_271 , L_34 ,
V_7 -> V_225 [ 0 ] ? V_7 -> V_225 : L_35 ) ;
V_271 += sprintf ( V_270 + V_271 , L_36 , V_7 -> V_267 ) ;
return V_271 ;
}
static T_9 F_186 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
return F_187 ( V_7 -> V_267 - V_5 -> V_245 . V_272 ,
V_5 -> V_245 . V_272 ) ;
}
static T_4
F_188 ( struct V_54 * V_23 )
{
return F_189 ( V_23 , F_94 ) ;
}
static T_8 F_190 ( struct V_273 * V_274 , char * V_39 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_122 ( V_276 -> V_278 ,
struct V_6 , V_62 ) ;
return snprintf ( V_39 , V_74 , L_37 , V_7 -> V_64 / V_279 ) ;
}
static T_8 F_192 ( struct V_273 * V_274 , const char * V_39 ,
T_2 V_98 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_122 ( V_276 -> V_278 ,
struct V_6 , V_62 ) ;
T_3 V_280 ;
int V_12 ;
if ( V_276 -> V_278 -> V_281 ) {
F_90 ( L_38 ) ;
return - V_19 ;
}
V_12 = F_193 ( V_39 , 0 , & V_280 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_64 = V_280 * V_279 ;
return V_98 ;
}
static T_8 F_194 ( struct V_273 * V_274 , char * V_39 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_6 ( V_276 -> V_278 ) ;
return snprintf ( V_39 , V_74 , L_39 , V_7 -> V_225 ) ;
}
static T_8 F_195 ( struct V_273 * V_274 , const char * V_39 ,
T_2 V_98 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_6 ( V_276 -> V_278 ) ;
int V_12 , V_35 ;
V_35 = strlen ( V_39 ) ;
if ( ! V_35 || V_35 > V_265 - 1 )
return - V_19 ;
if ( F_169 ( V_7 ) ) {
V_12 = F_146 ( V_7 , V_30 ,
V_215 , V_39 ) ;
if ( V_12 ) {
F_90 ( L_40 ) ;
return V_12 ;
}
F_196 ( V_7 -> V_225 , V_39 , V_265 ) ;
V_12 = F_157 ( V_7 ) ;
if ( V_12 )
return V_12 ;
return V_98 ;
}
F_196 ( V_7 -> V_225 , V_39 , V_265 ) ;
return V_98 ;
}
static T_8 F_197 ( struct V_273 * V_274 , char * V_39 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_6 ( V_276 -> V_278 ) ;
return snprintf ( V_39 , V_74 , L_41 , V_7 -> V_267 ) ;
}
static T_8 F_198 ( struct V_273 * V_274 , const char * V_39 ,
T_2 V_98 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_6 ( V_276 -> V_278 ) ;
V_217 V_280 ;
int V_12 ;
V_12 = F_199 ( V_39 , 0 , & V_280 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_169 ( V_7 ) ) {
V_12 = F_146 ( V_7 , V_30 ,
V_216 , & V_280 ) ;
if ( V_12 ) {
F_90 ( L_40 ) ;
return V_12 ;
}
}
V_7 -> V_267 = V_280 ;
return V_98 ;
}
static T_8 F_200 ( struct V_273 * V_274 ,
char * V_39 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
return snprintf ( V_39 , V_74 , L_42 , V_276 -> V_248 ) ;
}
static T_8 F_201 ( struct V_273 * V_274 ,
const char * V_39 , T_2 V_98 )
{
struct V_275 * V_276 = F_122 ( F_191 ( V_274 ) ,
struct V_275 , V_277 ) ;
struct V_6 * V_7 = F_6 ( V_276 -> V_278 ) ;
V_220 V_280 ;
int V_12 ;
V_12 = F_202 ( V_39 , 0 , & V_280 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_169 ( V_7 ) ) {
V_12 = F_146 ( V_7 , V_30 ,
V_219 , & V_280 ) ;
if ( V_12 ) {
F_90 ( L_40 ) ;
return V_12 ;
}
}
V_276 -> V_248 = V_280 ;
return V_98 ;
}
static int F_203 ( void * V_165 )
{
struct V_6 * V_7 ;
T_10 V_282 ;
T_1 V_283 , V_284 , V_285 ;
struct V_39 * V_39 ;
int V_36 ;
while ( ! F_204 () ) {
F_83 ( V_134 ) ;
F_84 ( & V_52 , & V_134 , V_136 ) ;
F_205 () ;
F_86 ( & V_52 , & V_134 ) ;
if ( F_204 () )
break;
F_80 ( & V_251 ) ;
F_206 (udev, &root_udev, node) {
F_80 ( & V_7 -> V_131 ) ;
F_99 ( V_7 ) ;
if ( V_7 -> V_48 || ! V_7 -> V_40 ) {
F_82 ( & V_7 -> V_131 ) ;
continue;
}
V_284 = V_7 -> V_47 + 1 ;
V_285 = F_207 ( V_7 -> V_38 , V_284 ) ;
if ( V_285 == V_7 -> V_47 ) {
F_82 ( & V_7 -> V_131 ) ;
continue;
} else if ( V_285 == V_284 ) {
V_7 -> V_40 = V_283 = 0 ;
V_7 -> V_47 = 0 ;
} else {
V_7 -> V_40 = V_283 = V_285 + 1 ;
V_7 -> V_47 = V_285 ;
}
V_282 = V_7 -> V_82 + V_283 * V_56 ;
F_208 ( V_7 -> V_197 -> V_286 , V_282 , 0 , 1 ) ;
for ( V_36 = V_283 ; V_36 < V_284 ; V_36 ++ ) {
V_39 = F_171 ( & V_7 -> V_41 , V_36 ) ;
if ( V_39 ) {
F_28 ( V_39 ) ;
F_23 ( & V_42 ) ;
}
}
F_82 ( & V_7 -> V_131 ) ;
}
F_206 (udev, &root_udev, node) {
if ( V_7 -> V_48 )
F_30 ( & V_7 -> V_135 ) ;
}
F_82 ( & V_251 ) ;
}
return 0 ;
}
static int T_11 F_209 ( void )
{
int V_12 , V_36 , V_287 , V_35 = 0 ;
F_210 ( ( sizeof( struct V_119 ) % V_124 ) != 0 ) ;
V_53 = F_211 ( L_43 ,
sizeof( struct V_34 ) ,
F_212 ( struct V_34 ) ,
0 , NULL ) ;
if ( ! V_53 )
return - V_170 ;
V_243 = F_213 ( L_44 ) ;
if ( F_214 ( V_243 ) ) {
V_12 = F_215 ( V_243 ) ;
goto V_288;
}
V_12 = F_216 ( & V_208 ) ;
if ( V_12 < 0 ) {
goto V_289;
}
for ( V_36 = 0 ; V_290 [ V_36 ] != NULL ; V_36 ++ ) {
V_35 += sizeof( struct V_291 * ) ;
}
for ( V_36 = 0 ; V_292 [ V_36 ] != NULL ; V_36 ++ ) {
V_35 += sizeof( struct V_291 * ) ;
}
V_35 += sizeof( struct V_291 * ) ;
V_293 = F_111 ( V_35 , V_44 ) ;
if ( ! V_293 ) {
V_12 = - V_170 ;
goto V_294;
}
for ( V_36 = 0 ; V_290 [ V_36 ] != NULL ; V_36 ++ ) {
V_293 [ V_36 ] = V_290 [ V_36 ] ;
}
for ( V_287 = 0 ; V_292 [ V_287 ] != NULL ; V_287 ++ ) {
V_293 [ V_36 ] = V_292 [ V_287 ] ;
V_36 ++ ;
}
V_295 . V_296 = V_293 ;
V_12 = F_217 ( & V_295 ) ;
if ( V_12 )
goto V_297;
F_116 ( & V_52 ) ;
V_298 = F_218 ( F_203 , NULL , L_45 ) ;
if ( F_214 ( V_298 ) ) {
V_12 = F_215 ( V_298 ) ;
goto V_299;
}
return 0 ;
V_299:
F_219 ( & V_295 ) ;
V_297:
F_33 ( V_293 ) ;
V_294:
F_220 ( & V_208 ) ;
V_289:
F_221 ( V_243 ) ;
V_288:
F_222 ( V_53 ) ;
return V_12 ;
}
static void T_12 F_223 ( void )
{
F_224 ( V_298 ) ;
F_219 ( & V_295 ) ;
F_33 ( V_293 ) ;
F_220 ( & V_208 ) ;
F_221 ( V_243 ) ;
F_222 ( V_53 ) ;
}
