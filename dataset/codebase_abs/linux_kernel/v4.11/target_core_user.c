static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_3 ( V_8 , V_9 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_5 = V_6 ;
if ( V_6 -> V_10 )
V_1 -> V_11 = V_12 +
F_4 ( V_6 -> V_10 ) ;
F_5 ( V_9 ) ;
F_6 ( & V_6 -> V_13 ) ;
V_7 = F_7 ( & V_6 -> V_14 , V_1 , 0 ,
V_15 , V_16 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_9 () ;
if ( V_7 < 0 ) {
F_10 ( V_8 , V_1 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return V_1 ;
}
static inline void F_11 ( void * V_17 , T_1 V_18 )
{
unsigned long V_19 = F_12 ( V_17 ) ;
V_18 = F_13 ( V_18 + V_19 , V_20 ) ;
V_17 -= V_19 ;
while ( V_18 ) {
F_14 ( F_15 ( V_17 ) ) ;
V_18 -= V_20 ;
}
}
static inline T_1 F_16 ( T_1 V_21 , T_1 V_22 , T_1 V_18 )
{
int V_23 = V_21 - V_22 ;
if ( V_23 >= 0 )
return V_23 ;
else
return V_18 + V_23 ;
}
static inline T_1 F_17 ( T_1 V_21 , T_1 V_22 , T_1 V_18 )
{
return ( V_18 - F_16 ( V_21 , V_22 , V_18 ) - 1 ) ;
}
static inline T_1 F_18 ( T_1 V_21 , T_1 V_18 )
{
return V_18 - V_21 ;
}
static inline void F_19 ( struct V_24 * * V_25 , int * V_26 ,
struct V_5 * V_6 )
{
struct V_24 * V_24 ;
if ( * V_26 != 0 )
( * V_25 ) ++ ;
( * V_26 ) ++ ;
V_24 = * V_25 ;
memset ( V_24 , 0 , sizeof( struct V_24 ) ) ;
}
static inline T_1 F_20 ( struct V_5 * V_27 ,
int V_28 , int V_29 )
{
return V_27 -> V_30 + V_28 * V_31 +
V_31 - V_29 ;
}
static inline T_1 F_21 ( struct V_5 * V_6 , struct V_24 * V_25 )
{
return ( T_1 ) V_25 -> V_32 + V_25 -> V_33 ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_34 * V_35 , unsigned int V_36 ,
struct V_24 * * V_25 , int * V_26 , bool V_37 )
{
int V_38 , V_28 ;
int V_39 = 0 ;
void * V_40 , * V_41 ;
T_1 V_42 , V_43 ;
struct V_34 * V_44 ;
F_23 (data_sg, sg, data_nents, i) {
int V_45 = V_44 -> V_46 ;
V_40 = F_24 ( F_25 ( V_44 ) ) + V_44 -> V_19 ;
while ( V_45 > 0 ) {
if ( V_39 == 0 ) {
V_28 = F_26 ( V_6 -> V_47 ,
V_48 ) ;
V_39 = V_31 ;
F_27 ( V_28 , V_6 -> V_47 ) ;
}
V_42 = F_28 ( T_1 , V_45 ,
V_39 ) ;
V_43 = F_20 ( V_6 , V_28 ,
V_39 ) ;
V_41 = ( void * ) V_6 -> V_49 + V_43 ;
if ( * V_26 != 0 &&
V_43 == F_21 ( V_6 , * V_25 ) ) {
( * V_25 ) -> V_33 += V_42 ;
} else {
F_19 ( V_25 , V_26 , V_6 ) ;
( * V_25 ) -> V_32 = ( void V_50 * ) V_43 ;
( * V_25 ) -> V_33 = V_42 ;
}
if ( V_37 ) {
memcpy ( V_41 , V_40 + V_44 -> V_46 - V_45 ,
V_42 ) ;
F_11 ( V_41 , V_42 ) ;
}
V_45 -= V_42 ;
V_39 -= V_42 ;
}
F_29 ( V_40 - V_44 -> V_19 ) ;
}
}
static void F_30 ( struct V_5 * V_6 , struct V_1 * V_51 )
{
F_31 ( V_6 -> V_47 , V_6 -> V_47 , V_51 -> V_47 ,
V_48 ) ;
}
static void F_32 ( struct V_5 * V_6 , struct V_1 * V_51 ,
bool V_52 )
{
struct V_2 * V_2 = V_51 -> V_2 ;
int V_38 , V_28 ;
int V_39 = 0 ;
void * V_40 , * V_41 ;
T_1 V_42 , V_53 ;
struct V_34 * V_44 , * V_35 ;
unsigned int V_36 ;
F_33 ( V_54 , V_48 ) ;
F_34 ( V_54 , V_51 -> V_47 , V_48 ) ;
if ( ! V_52 ) {
V_35 = V_2 -> V_55 ;
V_36 = V_2 -> V_56 ;
} else {
T_2 V_57 ;
V_57 = F_35 ( V_2 -> V_58 , V_31 ) ;
while ( V_57 -- ) {
V_28 = F_36 ( V_54 , V_48 ) ;
F_37 ( V_28 , V_54 ) ;
}
V_35 = V_2 -> V_59 ;
V_36 = V_2 -> V_60 ;
}
F_23 (data_sg, sg, data_nents, i) {
int V_45 = V_44 -> V_46 ;
V_41 = F_24 ( F_25 ( V_44 ) ) + V_44 -> V_19 ;
while ( V_45 > 0 ) {
if ( V_39 == 0 ) {
V_28 = F_36 ( V_54 ,
V_48 ) ;
V_39 = V_31 ;
F_37 ( V_28 , V_54 ) ;
}
V_42 = F_28 ( T_1 , V_45 ,
V_39 ) ;
V_53 = F_20 ( V_6 , V_28 ,
V_39 ) ;
V_40 = ( void * ) V_6 -> V_49 + V_53 ;
F_11 ( V_40 , V_42 ) ;
memcpy ( V_41 + V_44 -> V_46 - V_45 , V_40 ,
V_42 ) ;
V_45 -= V_42 ;
V_39 -= V_42 ;
}
F_29 ( V_41 - V_44 -> V_19 ) ;
}
}
static inline T_1 F_38 ( unsigned long * V_54 )
{
return V_31 * ( V_48 -
F_39 ( V_54 , V_48 ) ) ;
}
static bool F_40 ( struct V_5 * V_6 , T_1 V_61 , T_1 V_62 )
{
struct V_63 * V_64 = V_6 -> V_49 ;
T_1 V_65 , V_66 ;
T_3 V_67 ;
F_11 ( V_64 , sizeof( * V_64 ) ) ;
V_67 = V_64 -> V_67 % V_6 -> V_68 ;
if ( F_18 ( V_67 , V_6 -> V_68 ) >= V_61 )
V_66 = V_61 ;
else
V_66 = V_61 + F_18 ( V_67 , V_6 -> V_68 ) ;
V_65 = F_17 ( V_67 , V_6 -> V_69 , V_6 -> V_68 ) ;
if ( V_65 < V_66 ) {
F_41 ( L_1 , V_67 ,
V_6 -> V_69 , V_6 -> V_68 ) ;
return false ;
}
V_65 = F_38 ( V_6 -> V_47 ) ;
if ( V_65 < V_62 ) {
F_41 ( L_2 ,
V_65 , V_62 ) ;
return false ;
}
return true ;
}
static inline T_1 F_42 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_58 = F_13 ( V_2 -> V_58 , V_31 ) ;
if ( V_2 -> V_70 & V_71 ) {
F_43 ( ! ( V_2 -> V_59 && V_2 -> V_60 ) ) ;
V_58 += F_13 ( V_2 -> V_59 -> V_46 ,
V_31 ) ;
}
return V_58 ;
}
static inline T_2 F_44 ( struct V_1 * V_1 )
{
T_1 V_58 = F_42 ( V_1 ) ;
return V_58 / V_31 ;
}
static T_4
F_45 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_72 , V_73 ;
struct V_63 * V_64 ;
struct V_74 * V_75 ;
struct V_24 * V_25 ;
int V_26 ;
T_2 V_67 ;
T_5 V_76 ;
bool V_77 ;
T_1 V_58 = F_42 ( V_1 ) ;
F_33 ( V_78 , V_48 ) ;
if ( F_46 ( V_79 , & V_6 -> V_80 ) )
return V_81 ;
V_72 = F_47 ( F_48 ( struct V_74 ,
V_82 . V_25 [ F_44 ( V_1 ) ] ) ,
sizeof( struct V_74 ) ) ;
V_73 = V_72
+ F_13 ( F_49 ( V_2 -> V_83 ) , V_84 ) ;
F_50 ( V_73 & ( V_84 - 1 ) ) ;
F_6 ( & V_6 -> V_85 ) ;
V_64 = V_6 -> V_49 ;
V_67 = V_64 -> V_67 % V_6 -> V_68 ;
if ( ( V_73 > ( V_6 -> V_68 / 2 ) ) ||
V_58 > V_6 -> V_86 ) {
F_51 ( L_3
L_4 , V_73 , V_58 ,
V_6 -> V_68 , V_6 -> V_86 ) ;
F_8 ( & V_6 -> V_85 ) ;
return V_87 ;
}
while ( ! F_40 ( V_6 , V_73 , V_58 ) ) {
int V_88 ;
F_52 ( V_89 ) ;
F_53 ( & V_6 -> V_90 , & V_89 , V_91 ) ;
F_41 ( L_5 ) ;
F_8 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_10 )
V_88 = F_54 (
F_4 ( V_6 -> V_10 ) ) ;
else
V_88 = F_54 ( F_4 ( V_92 ) ) ;
F_55 ( & V_6 -> V_90 , & V_89 ) ;
if ( ! V_88 ) {
F_51 ( L_6 ) ;
return V_81 ;
}
F_6 ( & V_6 -> V_85 ) ;
V_67 = V_64 -> V_67 % V_6 -> V_68 ;
}
if ( F_18 ( V_67 , V_6 -> V_68 ) < V_73 ) {
T_1 V_93 = F_18 ( V_67 , V_6 -> V_68 ) ;
V_75 = ( void * ) V_64 + V_94 + V_67 ;
F_11 ( V_75 , sizeof( * V_75 ) ) ;
F_56 ( & V_75 -> V_95 . V_96 , V_97 ) ;
F_57 ( & V_75 -> V_95 . V_96 , V_93 ) ;
V_75 -> V_95 . V_7 = 0 ;
V_75 -> V_95 . V_98 = 0 ;
V_75 -> V_95 . V_99 = 0 ;
F_58 ( V_64 -> V_67 , V_93 , V_6 -> V_68 ) ;
V_67 = V_64 -> V_67 % V_6 -> V_68 ;
F_50 ( V_67 != 0 ) ;
}
V_75 = ( void * ) V_64 + V_94 + V_67 ;
F_11 ( V_75 , sizeof( * V_75 ) ) ;
F_56 ( & V_75 -> V_95 . V_96 , V_100 ) ;
F_57 ( & V_75 -> V_95 . V_96 , V_73 ) ;
V_75 -> V_95 . V_7 = V_1 -> V_7 ;
V_75 -> V_95 . V_98 = 0 ;
V_75 -> V_95 . V_99 = 0 ;
F_34 ( V_78 , V_6 -> V_47 , V_48 ) ;
V_25 = & V_75 -> V_82 . V_25 [ 0 ] ;
V_26 = 0 ;
V_77 = ( V_2 -> V_101 == V_102
|| V_2 -> V_70 & V_71 ) ;
F_22 ( V_6 , V_2 -> V_55 ,
V_2 -> V_56 , & V_25 , & V_26 , V_77 ) ;
V_75 -> V_82 . V_26 = V_26 ;
V_75 -> V_82 . V_103 = 0 ;
if ( V_2 -> V_70 & V_71 ) {
V_26 = 0 ;
V_25 ++ ;
F_22 ( V_6 , V_2 -> V_59 ,
V_2 -> V_60 , & V_25 , & V_26 ,
false ) ;
V_75 -> V_82 . V_104 = V_26 ;
}
F_31 ( V_1 -> V_47 , V_78 , V_6 -> V_47 ,
V_48 ) ;
V_76 = V_94 + V_67 + V_72 ;
memcpy ( ( void * ) V_64 + V_76 , V_2 -> V_83 , F_49 ( V_2 -> V_83 ) ) ;
V_75 -> V_82 . V_76 = V_76 ;
F_11 ( V_75 , sizeof( * V_75 ) ) ;
F_58 ( V_64 -> V_67 , V_73 , V_6 -> V_68 ) ;
F_11 ( V_64 , sizeof( * V_64 ) ) ;
F_8 ( & V_6 -> V_85 ) ;
F_59 ( & V_6 -> V_105 ) ;
if ( V_6 -> V_10 )
F_60 ( & V_6 -> V_106 , F_61 ( V_12 +
F_4 ( V_6 -> V_10 ) ) ) ;
return V_107 ;
}
static T_4
F_62 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
T_4 V_88 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return V_81 ;
V_88 = F_45 ( V_1 ) ;
if ( V_88 != V_107 ) {
F_63 ( L_7 ) ;
F_6 ( & V_6 -> V_13 ) ;
F_64 ( & V_6 -> V_14 , V_1 -> V_7 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_10 ( V_8 , V_1 ) ;
}
return V_88 ;
}
static void F_65 ( struct V_1 * V_51 , struct V_74 * V_75 )
{
struct V_2 * V_2 = V_51 -> V_2 ;
struct V_5 * V_6 = V_51 -> V_5 ;
if ( F_46 ( V_108 , & V_51 -> V_80 ) ) {
F_30 ( V_6 , V_51 ) ;
F_10 ( V_8 , V_51 ) ;
return;
}
if ( V_75 -> V_95 . V_99 & V_109 ) {
F_30 ( V_6 , V_51 ) ;
F_51 ( L_8 ,
V_51 -> V_2 ) ;
V_75 -> V_110 . V_111 = V_112 ;
} else if ( V_75 -> V_110 . V_111 == V_112 ) {
memcpy ( V_2 -> V_113 , V_75 -> V_110 . V_113 ,
V_2 -> V_114 ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_70 & V_71 ) {
F_32 ( V_6 , V_51 , true ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_101 == V_115 ) {
F_32 ( V_6 , V_51 , false ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_101 == V_102 ) {
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_101 != V_116 ) {
F_51 ( L_9 ,
V_2 -> V_101 ) ;
}
F_66 ( V_51 -> V_2 , V_75 -> V_110 . V_111 ) ;
V_51 -> V_2 = NULL ;
F_10 ( V_8 , V_51 ) ;
}
static unsigned int F_67 ( struct V_5 * V_6 )
{
struct V_63 * V_64 ;
unsigned long V_80 ;
int V_117 = 0 ;
if ( F_46 ( V_79 , & V_6 -> V_80 ) ) {
F_63 ( L_10 ) ;
return 0 ;
}
F_68 ( & V_6 -> V_85 , V_80 ) ;
V_64 = V_6 -> V_49 ;
F_11 ( V_64 , sizeof( * V_64 ) ) ;
while ( V_6 -> V_69 != F_69 ( V_64 -> V_118 ) ) {
struct V_74 * V_75 = ( void * ) V_64 + V_94 + V_6 -> V_69 ;
struct V_1 * V_51 ;
F_11 ( V_75 , sizeof( * V_75 ) ) ;
if ( F_70 ( V_75 -> V_95 . V_96 ) == V_97 ) {
F_58 ( V_6 -> V_69 ,
F_71 ( V_75 -> V_95 . V_96 ) ,
V_6 -> V_68 ) ;
continue;
}
F_50 ( F_70 ( V_75 -> V_95 . V_96 ) != V_100 ) ;
F_72 ( & V_6 -> V_13 ) ;
V_51 = F_64 ( & V_6 -> V_14 , V_75 -> V_95 . V_7 ) ;
F_73 ( & V_6 -> V_13 ) ;
if ( ! V_51 ) {
F_63 ( L_11 ) ;
F_27 ( V_79 , & V_6 -> V_80 ) ;
break;
}
F_65 ( V_51 , V_75 ) ;
F_58 ( V_6 -> V_69 ,
F_71 ( V_75 -> V_95 . V_96 ) ,
V_6 -> V_68 ) ;
V_117 ++ ;
}
if ( V_64 -> V_118 == V_64 -> V_67 )
F_74 ( & V_6 -> V_106 ) ;
F_75 ( & V_6 -> V_85 , V_80 ) ;
F_76 ( & V_6 -> V_90 ) ;
return V_117 ;
}
static int F_77 ( int V_119 , void * V_120 , void * V_121 )
{
struct V_1 * V_51 = V_120 ;
if ( F_46 ( V_108 , & V_51 -> V_80 ) )
return 0 ;
if ( ! F_78 ( V_12 , V_51 -> V_11 ) )
return 0 ;
F_27 ( V_108 , & V_51 -> V_80 ) ;
F_66 ( V_51 -> V_2 , V_112 ) ;
V_51 -> V_2 = NULL ;
return 0 ;
}
static void F_79 ( unsigned long V_121 )
{
struct V_5 * V_6 = (struct V_5 * ) V_121 ;
unsigned long V_80 ;
int V_117 ;
V_117 = F_67 ( V_6 ) ;
F_51 ( L_12 , V_117 ) ;
F_68 ( & V_6 -> V_13 , V_80 ) ;
F_80 ( & V_6 -> V_14 , F_77 , NULL ) ;
F_75 ( & V_6 -> V_13 , V_80 ) ;
}
static int F_81 ( struct V_122 * V_123 , T_3 V_124 )
{
struct V_125 * V_125 ;
V_125 = F_82 ( sizeof( struct V_125 ) , V_9 ) ;
if ( ! V_125 )
return - V_126 ;
V_125 -> V_124 = V_124 ;
V_123 -> V_127 = V_125 ;
return 0 ;
}
static void F_83 ( struct V_122 * V_123 )
{
F_84 ( V_123 -> V_127 ) ;
V_123 -> V_127 = NULL ;
}
static struct V_3 * F_85 ( struct V_122 * V_123 , const char * V_128 )
{
struct V_5 * V_6 ;
V_6 = F_82 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_128 = F_86 ( V_128 , V_9 ) ;
if ( ! V_6 -> V_128 ) {
F_84 ( V_6 ) ;
return NULL ;
}
V_6 -> V_123 = V_123 ;
V_6 -> V_10 = V_92 ;
F_87 ( & V_6 -> V_90 ) ;
F_88 ( & V_6 -> V_85 ) ;
F_89 ( & V_6 -> V_14 ) ;
F_88 ( & V_6 -> V_13 ) ;
F_90 ( & V_6 -> V_106 , F_79 ,
( unsigned long ) V_6 ) ;
return & V_6 -> V_4 ;
}
static int F_91 ( struct V_105 * V_129 , T_6 V_130 )
{
struct V_5 * V_5 = F_92 ( V_129 , struct V_5 , V_105 ) ;
F_67 ( V_5 ) ;
return 0 ;
}
static int F_93 ( struct V_131 * V_132 )
{
struct V_5 * V_6 = V_132 -> V_133 ;
struct V_105 * V_129 = & V_6 -> V_105 ;
if ( V_132 -> V_134 < V_135 ) {
if ( V_129 -> V_136 [ V_132 -> V_134 ] . V_18 == 0 )
return - 1 ;
return ( int ) V_132 -> V_134 ;
}
return - 1 ;
}
static int F_94 ( struct V_137 * V_138 )
{
struct V_5 * V_6 = V_138 -> V_132 -> V_133 ;
struct V_105 * V_129 = & V_6 -> V_105 ;
struct V_139 * V_139 ;
unsigned long V_19 ;
void * V_140 ;
int V_141 = F_93 ( V_138 -> V_132 ) ;
if ( V_141 < 0 )
return V_142 ;
V_19 = ( V_138 -> V_143 - V_141 ) << V_144 ;
V_140 = ( void * ) ( unsigned long ) V_129 -> V_136 [ V_141 ] . V_140 + V_19 ;
if ( V_129 -> V_136 [ V_141 ] . V_145 == V_146 )
V_139 = F_15 ( V_140 ) ;
else
V_139 = F_95 ( V_140 ) ;
F_96 ( V_139 ) ;
V_138 -> V_139 = V_139 ;
return 0 ;
}
static int F_97 ( struct V_105 * V_129 , struct V_131 * V_132 )
{
struct V_5 * V_6 = F_92 ( V_129 , struct V_5 , V_105 ) ;
V_132 -> V_147 |= V_148 | V_149 ;
V_132 -> V_150 = & V_151 ;
V_132 -> V_133 = V_6 ;
if ( F_98 ( V_132 ) != ( V_152 >> V_144 ) )
return - V_153 ;
return 0 ;
}
static int F_99 ( struct V_105 * V_129 , struct V_154 * V_154 )
{
struct V_5 * V_6 = F_92 ( V_129 , struct V_5 , V_105 ) ;
if ( F_100 ( V_155 , & V_6 -> V_80 ) )
return - V_156 ;
F_41 ( L_13 ) ;
return 0 ;
}
static int F_101 ( struct V_105 * V_129 , struct V_154 * V_154 )
{
struct V_5 * V_6 = F_92 ( V_129 , struct V_5 , V_105 ) ;
F_37 ( V_155 , & V_6 -> V_80 ) ;
F_41 ( L_14 ) ;
return 0 ;
}
static int F_102 ( enum V_157 V_51 , const char * V_128 , int V_158 )
{
struct V_159 * V_160 ;
void * V_161 ;
int V_88 = - V_126 ;
V_160 = F_103 ( V_162 , V_9 ) ;
if ( ! V_160 )
return V_88 ;
V_161 = F_104 ( V_160 , 0 , 0 , & V_163 , 0 , V_51 ) ;
if ( ! V_161 )
goto V_164;
V_88 = F_105 ( V_160 , V_165 , V_128 ) ;
if ( V_88 < 0 )
goto V_164;
V_88 = F_106 ( V_160 , V_166 , V_158 ) ;
if ( V_88 < 0 )
goto V_164;
F_107 ( V_160 , V_161 ) ;
V_88 = F_108 ( & V_163 , V_160 , 0 ,
V_167 , V_9 ) ;
if ( V_88 == - V_168 )
V_88 = 0 ;
return V_88 ;
V_164:
F_109 ( V_160 ) ;
return V_88 ;
}
static int F_110 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
struct V_125 * V_123 = V_6 -> V_123 -> V_127 ;
struct V_105 * V_129 ;
struct V_63 * V_64 ;
T_1 V_18 ;
T_1 V_169 ;
int V_88 = 0 ;
char * V_170 ;
V_129 = & V_6 -> V_105 ;
V_18 = snprintf ( NULL , 0 , L_15 , V_123 -> V_124 , V_6 -> V_128 ,
V_6 -> V_171 ) ;
V_18 += 1 ;
V_170 = F_111 ( V_18 , V_9 ) ;
if ( ! V_170 )
return - V_126 ;
V_169 = snprintf ( V_170 , V_18 , L_16 , V_123 -> V_124 , V_6 -> V_128 ) ;
if ( V_6 -> V_171 [ 0 ] )
snprintf ( V_170 + V_169 , V_18 - V_169 , L_17 , V_6 -> V_171 ) ;
V_129 -> V_128 = V_170 ;
V_6 -> V_49 = F_112 ( V_152 ) ;
if ( ! V_6 -> V_49 ) {
V_88 = - V_126 ;
goto V_172;
}
V_6 -> V_68 = V_173 - V_94 ;
V_6 -> V_30 = V_173 ;
V_6 -> V_86 = V_152 - V_173 ;
V_64 = V_6 -> V_49 ;
V_64 -> V_174 = V_175 ;
V_64 -> V_80 = V_176 ;
V_64 -> V_177 = V_94 ;
V_64 -> V_68 = V_6 -> V_68 ;
F_50 ( ! F_113 ( V_6 -> V_30 ) ) ;
F_50 ( V_6 -> V_86 % V_20 ) ;
F_50 ( V_6 -> V_86 % V_31 ) ;
V_129 -> V_174 = F_114 ( V_175 ) ;
V_129 -> V_136 [ 0 ] . V_128 = L_18 ;
V_129 -> V_136 [ 0 ] . V_140 = ( V_178 ) ( V_179 ) V_6 -> V_49 ;
V_129 -> V_136 [ 0 ] . V_18 = V_152 ;
V_129 -> V_136 [ 0 ] . V_145 = V_180 ;
V_129 -> V_181 = F_91 ;
V_129 -> V_182 = V_183 ;
V_129 -> V_184 = F_97 ;
V_129 -> V_185 = F_99 ;
V_129 -> V_186 = F_101 ;
V_88 = F_115 ( V_187 , V_129 ) ;
if ( V_88 )
goto V_188;
if ( V_27 -> V_189 . V_190 == 0 )
V_27 -> V_189 . V_190 = 512 ;
if ( ! V_27 -> V_189 . V_191 )
V_27 -> V_189 . V_191 = 128 ;
V_27 -> V_189 . V_192 = 128 ;
V_88 = F_102 ( V_193 , V_6 -> V_105 . V_128 ,
V_6 -> V_105 . V_194 -> V_158 ) ;
if ( V_88 )
goto V_195;
return 0 ;
V_195:
F_116 ( & V_6 -> V_105 ) ;
V_188:
F_117 ( V_6 -> V_49 ) ;
V_172:
F_84 ( V_129 -> V_128 ) ;
return V_88 ;
}
static int F_118 ( struct V_1 * V_51 )
{
if ( F_46 ( V_108 , & V_51 -> V_80 ) ) {
F_10 ( V_8 , V_51 ) ;
return 0 ;
}
return - V_153 ;
}
static void F_119 ( struct V_196 * V_120 )
{
struct V_3 * V_27 = F_92 ( V_120 , struct V_3 , V_196 ) ;
struct V_5 * V_6 = F_2 ( V_27 ) ;
F_84 ( V_6 ) ;
}
static bool F_120 ( struct V_5 * V_6 )
{
return V_6 -> V_105 . V_194 ? true : false ;
}
static void F_121 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
struct V_1 * V_51 ;
bool V_197 = true ;
int V_38 ;
F_122 ( & V_6 -> V_106 ) ;
F_117 ( V_6 -> V_49 ) ;
F_6 ( & V_6 -> V_13 ) ;
F_123 (&udev->commands, cmd, i) {
if ( F_118 ( V_51 ) != 0 )
V_197 = false ;
}
F_124 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_50 ( ! V_197 ) ;
if ( F_120 ( V_6 ) ) {
F_102 ( V_198 , V_6 -> V_105 . V_128 ,
V_6 -> V_105 . V_194 -> V_158 ) ;
F_116 ( & V_6 -> V_105 ) ;
F_84 ( V_6 -> V_105 . V_128 ) ;
F_84 ( V_6 -> V_128 ) ;
}
F_125 ( & V_27 -> V_196 , F_119 ) ;
}
static int F_126 ( T_7 * V_199 , T_3 * V_189 )
{
unsigned long V_200 ;
char * V_201 ;
int V_88 ;
V_201 = F_127 ( V_199 ) ;
if ( ! V_201 )
return - V_126 ;
V_88 = F_128 ( V_201 , 0 , & V_200 ) ;
F_84 ( V_201 ) ;
if ( V_88 < 0 ) {
F_63 ( L_19 ) ;
return V_88 ;
}
if ( ! V_200 ) {
F_63 ( L_20 ) ;
return - V_153 ;
}
* V_189 = V_200 ;
return 0 ;
}
static T_8 F_129 ( struct V_3 * V_27 ,
const char * V_139 , T_8 V_57 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
char * V_202 , * V_203 , * V_204 , * V_201 ;
T_7 args [ V_205 ] ;
int V_88 = 0 , V_206 ;
V_204 = F_86 ( V_139 , V_9 ) ;
if ( ! V_204 )
return - V_126 ;
V_202 = V_204 ;
while ( ( V_203 = F_130 ( & V_204 , L_21 ) ) != NULL ) {
if ( ! * V_203 )
continue;
V_206 = F_131 ( V_203 , V_207 , args ) ;
switch ( V_206 ) {
case V_208 :
if ( F_132 ( V_6 -> V_171 , & args [ 0 ] ,
V_209 ) == 0 ) {
V_88 = - V_153 ;
break;
}
F_41 ( L_22 , V_6 -> V_171 ) ;
break;
case V_210 :
V_201 = F_127 ( & args [ 0 ] ) ;
if ( ! V_201 ) {
V_88 = - V_126 ;
break;
}
V_88 = F_128 ( V_201 , 0 , ( unsigned long * ) & V_6 -> V_211 ) ;
F_84 ( V_201 ) ;
if ( V_88 < 0 )
F_63 ( L_23 ) ;
break;
case V_212 :
V_88 = F_126 ( & args [ 0 ] ,
& ( V_27 -> V_189 . V_190 ) ) ;
break;
case V_213 :
V_88 = F_126 ( & args [ 0 ] ,
& ( V_27 -> V_189 . V_191 ) ) ;
break;
default:
break;
}
if ( V_88 )
break;
}
F_84 ( V_202 ) ;
return ( ! V_88 ) ? V_57 : V_88 ;
}
static T_8 F_133 ( struct V_3 * V_27 , char * V_214 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
T_8 V_215 = 0 ;
V_215 = sprintf ( V_214 + V_215 , L_24 ,
V_6 -> V_171 [ 0 ] ? V_6 -> V_171 : L_25 ) ;
V_215 += sprintf ( V_214 + V_215 , L_26 , V_6 -> V_211 ) ;
return V_215 ;
}
static T_9 F_134 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
return F_135 ( V_6 -> V_211 - V_27 -> V_189 . V_216 ,
V_27 -> V_189 . V_216 ) ;
}
static T_4
F_136 ( struct V_2 * V_51 )
{
return F_137 ( V_51 , F_62 ) ;
}
static T_8 F_138 ( struct V_217 * V_218 , char * V_139 )
{
struct V_219 * V_220 = F_92 ( F_139 ( V_218 ) ,
struct V_219 , V_221 ) ;
struct V_5 * V_6 = F_92 ( V_220 -> V_222 ,
struct V_5 , V_4 ) ;
return snprintf ( V_139 , V_20 , L_27 , V_6 -> V_10 / V_223 ) ;
}
static T_8 F_140 ( struct V_217 * V_218 , const char * V_139 ,
T_1 V_57 )
{
struct V_219 * V_220 = F_92 ( F_139 ( V_218 ) ,
struct V_219 , V_221 ) ;
struct V_5 * V_6 = F_92 ( V_220 -> V_222 ,
struct V_5 , V_4 ) ;
T_3 V_224 ;
int V_88 ;
if ( V_220 -> V_222 -> V_225 ) {
F_63 ( L_28 ) ;
return - V_153 ;
}
V_88 = F_141 ( V_139 , 0 , & V_224 ) ;
if ( V_88 < 0 )
return V_88 ;
V_6 -> V_10 = V_224 * V_223 ;
return V_57 ;
}
static int T_10 F_142 ( void )
{
int V_88 , V_38 , V_226 = 0 ;
F_143 ( ( sizeof( struct V_74 ) % V_84 ) != 0 ) ;
V_8 = F_144 ( L_29 ,
sizeof( struct V_1 ) ,
F_145 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_126 ;
V_187 = F_146 ( L_30 ) ;
if ( F_147 ( V_187 ) ) {
V_88 = F_148 ( V_187 ) ;
goto V_227;
}
V_88 = F_149 ( & V_163 ) ;
if ( V_88 < 0 ) {
goto V_228;
}
for ( V_38 = 0 ; V_229 [ V_38 ] != NULL ; V_38 ++ ) {
V_226 += sizeof( struct V_230 * ) ;
}
V_226 += sizeof( struct V_230 * ) * 2 ;
V_231 = F_82 ( V_226 , V_9 ) ;
if ( ! V_231 ) {
V_88 = - V_126 ;
goto V_232;
}
for ( V_38 = 0 ; V_229 [ V_38 ] != NULL ; V_38 ++ ) {
V_231 [ V_38 ] = V_229 [ V_38 ] ;
}
V_231 [ V_38 ] = & V_233 ;
V_234 . V_235 = V_231 ;
V_88 = F_150 ( & V_234 ) ;
if ( V_88 )
goto V_236;
return 0 ;
V_236:
F_84 ( V_231 ) ;
V_232:
F_151 ( & V_163 ) ;
V_228:
F_152 ( V_187 ) ;
V_227:
F_153 ( V_8 ) ;
return V_88 ;
}
static void T_11 F_154 ( void )
{
F_155 ( & V_234 ) ;
F_84 ( V_231 ) ;
F_151 ( & V_163 ) ;
F_152 ( V_187 ) ;
F_153 ( V_8 ) ;
}
