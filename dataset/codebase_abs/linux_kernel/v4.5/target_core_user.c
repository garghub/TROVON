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
V_1 -> V_10 = V_2 -> V_10 ;
if ( V_2 -> V_11 & V_12 ) {
F_4 ( ! ( V_2 -> V_13 && V_2 -> V_14 ) ) ;
V_1 -> V_10 += V_2 -> V_13 -> V_15 ;
}
V_1 -> V_16 = V_17 + F_5 ( V_18 ) ;
F_6 ( V_9 ) ;
F_7 ( & V_6 -> V_19 ) ;
V_7 = F_8 ( & V_6 -> V_20 , V_1 , 0 ,
V_21 , V_22 ) ;
F_9 ( & V_6 -> V_19 ) ;
F_10 () ;
if ( V_7 < 0 ) {
F_11 ( V_8 , V_1 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return V_1 ;
}
static inline void F_12 ( void * V_23 , T_1 V_24 )
{
unsigned long V_25 = F_13 ( V_23 ) ;
V_24 = F_14 ( V_24 + V_25 , V_26 ) ;
V_23 -= V_25 ;
while ( V_24 ) {
F_15 ( F_16 ( V_23 ) ) ;
V_24 -= V_26 ;
}
}
static inline T_1 F_17 ( T_1 V_27 , T_1 V_28 , T_1 V_24 )
{
int V_29 = V_27 - V_28 ;
if ( V_29 >= 0 )
return V_29 ;
else
return V_24 + V_29 ;
}
static inline T_1 F_18 ( T_1 V_27 , T_1 V_28 , T_1 V_24 )
{
return ( V_24 - F_17 ( V_27 , V_28 , V_24 ) - 1 ) ;
}
static inline T_1 F_19 ( T_1 V_27 , T_1 V_24 )
{
return V_24 - V_27 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_30 * V_31 , unsigned int V_32 ,
struct V_33 * * V_34 , int * V_35 , bool V_36 )
{
int V_37 ;
void * V_38 , * V_39 ;
T_1 V_40 ;
struct V_30 * V_41 ;
F_21 (data_sg, sg, data_nents, i) {
V_40 = F_22 ( T_1 , V_41 -> V_15 ,
F_19 ( V_6 -> V_42 , V_6 -> V_43 ) ) ;
V_38 = F_23 ( F_24 ( V_41 ) ) + V_41 -> V_25 ;
V_39 = ( void * ) V_6 -> V_44 + V_6 -> V_45 + V_6 -> V_42 ;
if ( V_36 ) {
memcpy ( V_39 , V_38 , V_40 ) ;
F_12 ( V_39 , V_40 ) ;
}
( * V_34 ) -> V_46 = V_40 ;
( * V_34 ) -> V_47 = ( void V_48 * ) V_6 -> V_45 +
V_6 -> V_42 ;
( * V_35 ) ++ ;
( * V_34 ) ++ ;
F_25 ( V_6 -> V_42 , V_40 , V_6 -> V_43 ) ;
if ( V_41 -> V_15 != V_40 ) {
void * V_49 = V_38 + V_40 ;
V_40 = V_41 -> V_15 - V_40 ;
( * V_34 ) -> V_46 = V_40 ;
( * V_34 ) -> V_47 = ( void V_48 * ) V_6 -> V_45 +
V_6 -> V_42 ;
if ( V_36 ) {
V_39 = ( void * ) V_6 -> V_44 +
V_6 -> V_45 + V_6 -> V_42 ;
memcpy ( V_39 , V_49 , V_40 ) ;
F_12 ( V_39 , V_40 ) ;
}
( * V_35 ) ++ ;
( * V_34 ) ++ ;
F_25 ( V_6 -> V_42 ,
V_40 , V_6 -> V_43 ) ;
}
F_26 ( V_38 - V_41 -> V_25 ) ;
}
}
static void F_27 ( struct V_5 * V_6 ,
struct V_30 * V_31 , unsigned int V_32 )
{
int V_37 ;
void * V_38 , * V_39 ;
T_1 V_40 ;
struct V_30 * V_41 ;
F_21 (data_sg, sg, data_nents, i) {
V_40 = F_22 ( T_1 , V_41 -> V_15 ,
F_19 ( V_6 -> V_50 , V_6 -> V_43 ) ) ;
V_39 = F_23 ( F_24 ( V_41 ) ) + V_41 -> V_25 ;
F_28 ( V_41 -> V_15 + V_41 -> V_25 > V_26 ) ;
V_38 = ( void * ) V_6 -> V_44 +
V_6 -> V_45 + V_6 -> V_50 ;
F_12 ( V_38 , V_40 ) ;
memcpy ( V_39 , V_38 , V_40 ) ;
F_25 ( V_6 -> V_50 , V_40 , V_6 -> V_43 ) ;
if ( V_41 -> V_15 != V_40 ) {
void * V_51 = V_39 + V_40 ;
V_38 = ( void * ) V_6 -> V_44 +
V_6 -> V_45 + V_6 -> V_50 ;
F_28 ( V_6 -> V_50 ) ;
V_40 = V_41 -> V_15 - V_40 ;
F_12 ( V_38 , V_40 ) ;
memcpy ( V_51 , V_38 , V_40 ) ;
F_25 ( V_6 -> V_50 ,
V_40 , V_6 -> V_43 ) ;
}
F_26 ( V_39 - V_41 -> V_25 ) ;
}
}
static bool F_29 ( struct V_5 * V_6 , T_1 V_52 , T_1 V_53 )
{
struct V_54 * V_55 = V_6 -> V_44 ;
T_1 V_56 ;
T_2 V_57 ;
T_1 V_58 ;
F_12 ( V_55 , sizeof( * V_55 ) ) ;
V_57 = V_55 -> V_57 % V_6 -> V_59 ;
if ( F_19 ( V_57 , V_6 -> V_59 ) >= V_52 )
V_58 = V_52 ;
else
V_58 = V_52 + F_19 ( V_57 , V_6 -> V_59 ) ;
V_56 = F_18 ( V_57 , V_6 -> V_60 , V_6 -> V_59 ) ;
if ( V_56 < V_58 ) {
F_30 ( L_1 , V_57 ,
V_6 -> V_60 , V_6 -> V_59 ) ;
return false ;
}
V_56 = F_18 ( V_6 -> V_42 , V_6 -> V_50 , V_6 -> V_43 ) ;
if ( V_56 < V_53 ) {
F_30 ( L_2 , V_6 -> V_42 ,
V_6 -> V_50 , V_6 -> V_43 ) ;
return false ;
}
return true ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_61 , V_62 ;
struct V_54 * V_55 ;
struct V_63 * V_64 ;
struct V_33 * V_34 ;
int V_35 ;
T_3 V_57 ;
T_4 V_65 ;
bool V_66 ;
if ( F_32 ( V_67 , & V_6 -> V_68 ) )
return - V_69 ;
V_61 = F_33 ( F_34 ( struct V_63 ,
V_70 . V_34 [ V_2 -> V_14 +
V_2 -> V_71 + 2 ] ) ,
sizeof( struct V_63 ) ) ;
V_62 = V_61
+ F_14 ( F_35 ( V_2 -> V_72 ) , V_73 ) ;
F_28 ( V_62 & ( V_73 - 1 ) ) ;
F_7 ( & V_6 -> V_74 ) ;
V_55 = V_6 -> V_44 ;
V_57 = V_55 -> V_57 % V_6 -> V_59 ;
if ( ( V_62 > ( V_6 -> V_59 / 2 ) )
|| V_1 -> V_10 > ( V_6 -> V_43 - 1 ) )
F_36 ( L_3
L_4 , V_62 , V_1 -> V_10 ,
V_6 -> V_59 , V_6 -> V_43 ) ;
while ( ! F_29 ( V_6 , V_62 , V_1 -> V_10 ) ) {
int V_75 ;
F_37 ( V_76 ) ;
F_38 ( & V_6 -> V_77 , & V_76 , V_78 ) ;
F_30 ( L_5 ) ;
F_9 ( & V_6 -> V_74 ) ;
V_75 = F_39 ( F_5 ( V_18 ) ) ;
F_40 ( & V_6 -> V_77 , & V_76 ) ;
if ( ! V_75 ) {
F_36 ( L_6 ) ;
return - V_79 ;
}
F_7 ( & V_6 -> V_74 ) ;
V_57 = V_55 -> V_57 % V_6 -> V_59 ;
}
if ( F_19 ( V_57 , V_6 -> V_59 ) < V_62 ) {
T_1 V_80 = F_19 ( V_57 , V_6 -> V_59 ) ;
V_64 = ( void * ) V_55 + V_81 + V_57 ;
F_12 ( V_64 , sizeof( * V_64 ) ) ;
F_41 ( & V_64 -> V_82 . V_83 , V_84 ) ;
F_42 ( & V_64 -> V_82 . V_83 , V_80 ) ;
V_64 -> V_82 . V_7 = 0 ;
V_64 -> V_82 . V_85 = 0 ;
V_64 -> V_82 . V_86 = 0 ;
F_25 ( V_55 -> V_57 , V_80 , V_6 -> V_59 ) ;
V_57 = V_55 -> V_57 % V_6 -> V_59 ;
F_28 ( V_57 != 0 ) ;
}
V_64 = ( void * ) V_55 + V_81 + V_57 ;
F_12 ( V_64 , sizeof( * V_64 ) ) ;
F_41 ( & V_64 -> V_82 . V_83 , V_87 ) ;
F_42 ( & V_64 -> V_82 . V_83 , V_62 ) ;
V_64 -> V_82 . V_7 = V_1 -> V_7 ;
V_64 -> V_82 . V_85 = 0 ;
V_64 -> V_82 . V_86 = 0 ;
V_34 = & V_64 -> V_70 . V_34 [ 0 ] ;
V_35 = 0 ;
V_66 = ( V_2 -> V_88 == V_89
|| V_2 -> V_11 & V_12 ) ;
F_20 ( V_6 , V_2 -> V_90 ,
V_2 -> V_71 , & V_34 , & V_35 , V_66 ) ;
V_64 -> V_70 . V_35 = V_35 ;
V_64 -> V_70 . V_91 = 0 ;
V_35 = 0 ;
F_20 ( V_6 , V_2 -> V_13 ,
V_2 -> V_14 , & V_34 , & V_35 , false ) ;
V_64 -> V_70 . V_92 = V_35 ;
V_65 = V_81 + V_57 + V_61 ;
memcpy ( ( void * ) V_55 + V_65 , V_2 -> V_72 , F_35 ( V_2 -> V_72 ) ) ;
V_64 -> V_70 . V_65 = V_65 ;
F_12 ( V_64 , sizeof( * V_64 ) ) ;
F_25 ( V_55 -> V_57 , V_62 , V_6 -> V_59 ) ;
F_12 ( V_55 , sizeof( * V_55 ) ) ;
F_9 ( & V_6 -> V_74 ) ;
F_43 ( & V_6 -> V_93 ) ;
F_44 ( & V_6 -> V_94 ,
F_45 ( V_17 + F_5 ( V_18 ) ) ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_75 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_95 ;
V_75 = F_31 ( V_1 ) ;
if ( V_75 < 0 ) {
F_47 ( L_7 ) ;
F_7 ( & V_6 -> V_19 ) ;
F_48 ( & V_6 -> V_20 , V_1 -> V_7 ) ;
F_9 ( & V_6 -> V_19 ) ;
F_11 ( V_8 , V_1 ) ;
}
return V_75 ;
}
static void F_49 ( struct V_1 * V_96 , struct V_63 * V_64 )
{
struct V_2 * V_2 = V_96 -> V_2 ;
struct V_5 * V_6 = V_96 -> V_5 ;
if ( F_32 ( V_97 , & V_96 -> V_68 ) ) {
F_25 ( V_6 -> V_50 , V_96 -> V_10 , V_6 -> V_43 ) ;
return;
}
if ( V_64 -> V_82 . V_86 & V_98 ) {
F_25 ( V_6 -> V_50 , V_96 -> V_10 , V_6 -> V_43 ) ;
F_36 ( L_8 ,
V_96 -> V_2 ) ;
V_64 -> V_99 . V_100 = V_101 ;
} else if ( V_64 -> V_99 . V_100 == V_101 ) {
memcpy ( V_2 -> V_102 , V_64 -> V_99 . V_102 ,
V_2 -> V_103 ) ;
F_25 ( V_6 -> V_50 , V_96 -> V_10 , V_6 -> V_43 ) ;
} else if ( V_2 -> V_11 & V_12 ) {
F_25 ( V_6 -> V_50 ,
( T_1 ) V_2 -> V_90 -> V_15 , V_6 -> V_43 ) ;
F_27 ( V_6 ,
V_2 -> V_13 , V_2 -> V_14 ) ;
} else if ( V_2 -> V_88 == V_104 ) {
F_27 ( V_6 ,
V_2 -> V_90 , V_2 -> V_71 ) ;
} else if ( V_2 -> V_88 == V_89 ) {
F_25 ( V_6 -> V_50 , V_96 -> V_10 , V_6 -> V_43 ) ;
} else if ( V_2 -> V_88 != V_105 ) {
F_36 ( L_9 ,
V_2 -> V_88 ) ;
}
F_50 ( V_96 -> V_2 , V_64 -> V_99 . V_100 ) ;
V_96 -> V_2 = NULL ;
F_11 ( V_8 , V_96 ) ;
}
static unsigned int F_51 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
unsigned long V_68 ;
int V_106 = 0 ;
if ( F_32 ( V_67 , & V_6 -> V_68 ) ) {
F_47 ( L_10 ) ;
return 0 ;
}
F_52 ( & V_6 -> V_74 , V_68 ) ;
V_55 = V_6 -> V_44 ;
F_12 ( V_55 , sizeof( * V_55 ) ) ;
while ( V_6 -> V_60 != F_53 ( V_55 -> V_107 ) ) {
struct V_63 * V_64 = ( void * ) V_55 + V_81 + V_6 -> V_60 ;
struct V_1 * V_96 ;
F_12 ( V_64 , sizeof( * V_64 ) ) ;
if ( F_54 ( V_64 -> V_82 . V_83 ) == V_84 ) {
F_25 ( V_6 -> V_60 ,
F_55 ( V_64 -> V_82 . V_83 ) ,
V_6 -> V_59 ) ;
continue;
}
F_28 ( F_54 ( V_64 -> V_82 . V_83 ) != V_87 ) ;
F_56 ( & V_6 -> V_19 ) ;
V_96 = F_57 ( & V_6 -> V_20 , V_64 -> V_82 . V_7 ) ;
if ( V_96 )
F_48 ( & V_6 -> V_20 , V_96 -> V_7 ) ;
F_58 ( & V_6 -> V_19 ) ;
if ( ! V_96 ) {
F_47 ( L_11 ) ;
F_59 ( V_67 , & V_6 -> V_68 ) ;
break;
}
F_49 ( V_96 , V_64 ) ;
F_25 ( V_6 -> V_60 ,
F_55 ( V_64 -> V_82 . V_83 ) ,
V_6 -> V_59 ) ;
V_106 ++ ;
}
if ( V_55 -> V_107 == V_55 -> V_57 )
F_60 ( & V_6 -> V_94 ) ;
F_61 ( & V_6 -> V_74 , V_68 ) ;
F_62 ( & V_6 -> V_77 ) ;
return V_106 ;
}
static int F_63 ( int V_108 , void * V_109 , void * V_110 )
{
struct V_1 * V_96 = V_109 ;
if ( F_32 ( V_97 , & V_96 -> V_68 ) )
return 0 ;
if ( ! F_64 ( V_17 , V_96 -> V_16 ) )
return 0 ;
F_59 ( V_97 , & V_96 -> V_68 ) ;
F_50 ( V_96 -> V_2 , V_101 ) ;
V_96 -> V_2 = NULL ;
F_11 ( V_8 , V_96 ) ;
return 0 ;
}
static void F_65 ( unsigned long V_110 )
{
struct V_5 * V_6 = (struct V_5 * ) V_110 ;
unsigned long V_68 ;
int V_106 ;
V_106 = F_51 ( V_6 ) ;
F_36 ( L_12 , V_106 ) ;
F_52 ( & V_6 -> V_19 , V_68 ) ;
F_66 ( & V_6 -> V_20 , F_63 , NULL ) ;
F_61 ( & V_6 -> V_19 , V_68 ) ;
}
static int F_67 ( struct V_111 * V_112 , T_2 V_113 )
{
struct V_114 * V_114 ;
V_114 = F_68 ( sizeof( struct V_114 ) , V_9 ) ;
if ( ! V_114 )
return - V_95 ;
V_114 -> V_113 = V_113 ;
V_112 -> V_115 = V_114 ;
return 0 ;
}
static void F_69 ( struct V_111 * V_112 )
{
F_70 ( V_112 -> V_115 ) ;
V_112 -> V_115 = NULL ;
}
static struct V_3 * F_71 ( struct V_111 * V_112 , const char * V_116 )
{
struct V_5 * V_6 ;
V_6 = F_68 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_116 = F_72 ( V_116 , V_9 ) ;
if ( ! V_6 -> V_116 ) {
F_70 ( V_6 ) ;
return NULL ;
}
V_6 -> V_112 = V_112 ;
F_73 ( & V_6 -> V_77 ) ;
F_74 ( & V_6 -> V_74 ) ;
F_75 ( & V_6 -> V_20 ) ;
F_74 ( & V_6 -> V_19 ) ;
F_76 ( & V_6 -> V_94 , F_65 ,
( unsigned long ) V_6 ) ;
return & V_6 -> V_4 ;
}
static int F_77 ( struct V_93 * V_117 , T_5 V_118 )
{
struct V_5 * V_5 = F_78 ( V_117 , struct V_5 , V_93 ) ;
F_51 ( V_5 ) ;
return 0 ;
}
static int F_79 ( struct V_119 * V_120 )
{
struct V_5 * V_6 = V_120 -> V_121 ;
struct V_93 * V_117 = & V_6 -> V_93 ;
if ( V_120 -> V_122 < V_123 ) {
if ( V_117 -> V_124 [ V_120 -> V_122 ] . V_24 == 0 )
return - 1 ;
return ( int ) V_120 -> V_122 ;
}
return - 1 ;
}
static int F_80 ( struct V_119 * V_120 , struct V_125 * V_126 )
{
struct V_5 * V_6 = V_120 -> V_121 ;
struct V_93 * V_117 = & V_6 -> V_93 ;
struct V_127 * V_127 ;
unsigned long V_25 ;
void * V_128 ;
int V_129 = F_79 ( V_120 ) ;
if ( V_129 < 0 )
return V_130 ;
V_25 = ( V_126 -> V_131 - V_129 ) << V_132 ;
V_128 = ( void * ) ( unsigned long ) V_117 -> V_124 [ V_129 ] . V_128 + V_25 ;
if ( V_117 -> V_124 [ V_129 ] . V_133 == V_134 )
V_127 = F_16 ( V_128 ) ;
else
V_127 = F_81 ( V_128 ) ;
F_82 ( V_127 ) ;
V_126 -> V_127 = V_127 ;
return 0 ;
}
static int F_83 ( struct V_93 * V_117 , struct V_119 * V_120 )
{
struct V_5 * V_6 = F_78 ( V_117 , struct V_5 , V_93 ) ;
V_120 -> V_135 |= V_136 | V_137 ;
V_120 -> V_138 = & V_139 ;
V_120 -> V_121 = V_6 ;
if ( F_84 ( V_120 ) != ( V_140 >> V_132 ) )
return - V_69 ;
return 0 ;
}
static int F_85 ( struct V_93 * V_117 , struct V_141 * V_141 )
{
struct V_5 * V_6 = F_78 ( V_117 , struct V_5 , V_93 ) ;
if ( F_86 ( V_142 , & V_6 -> V_68 ) )
return - V_143 ;
F_30 ( L_13 ) ;
return 0 ;
}
static int F_87 ( struct V_93 * V_117 , struct V_141 * V_141 )
{
struct V_5 * V_6 = F_78 ( V_117 , struct V_5 , V_93 ) ;
F_88 ( V_142 , & V_6 -> V_68 ) ;
F_30 ( L_14 ) ;
return 0 ;
}
static int F_89 ( enum V_144 V_96 , const char * V_116 , int V_145 )
{
struct V_146 * V_147 ;
void * V_148 ;
int V_75 = - V_95 ;
V_147 = F_90 ( V_149 , V_9 ) ;
if ( ! V_147 )
return V_75 ;
V_148 = F_91 ( V_147 , 0 , 0 , & V_150 , 0 , V_96 ) ;
if ( ! V_148 )
goto V_151;
V_75 = F_92 ( V_147 , V_152 , V_116 ) ;
if ( V_75 < 0 )
goto V_151;
V_75 = F_93 ( V_147 , V_153 , V_145 ) ;
if ( V_75 < 0 )
goto V_151;
F_94 ( V_147 , V_148 ) ;
V_75 = F_95 ( & V_150 , V_147 , 0 ,
V_154 , V_9 ) ;
if ( V_75 == - V_155 )
V_75 = 0 ;
return V_75 ;
V_151:
F_96 ( V_147 ) ;
return V_75 ;
}
static int F_97 ( struct V_3 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_156 ) ;
struct V_114 * V_112 = V_6 -> V_112 -> V_115 ;
struct V_93 * V_117 ;
struct V_54 * V_55 ;
T_1 V_24 ;
T_1 V_157 ;
int V_75 = 0 ;
char * V_158 ;
V_117 = & V_6 -> V_93 ;
V_24 = snprintf ( NULL , 0 , L_15 , V_112 -> V_113 , V_6 -> V_116 ,
V_6 -> V_159 ) ;
V_24 += 1 ;
V_158 = F_98 ( V_24 , V_9 ) ;
if ( ! V_158 )
return - V_95 ;
V_157 = snprintf ( V_158 , V_24 , L_16 , V_112 -> V_113 , V_6 -> V_116 ) ;
if ( V_6 -> V_159 [ 0 ] )
snprintf ( V_158 + V_157 , V_24 - V_157 , L_17 , V_6 -> V_159 ) ;
V_117 -> V_116 = V_158 ;
V_6 -> V_44 = F_99 ( V_140 ) ;
if ( ! V_6 -> V_44 ) {
V_75 = - V_95 ;
goto V_160;
}
V_6 -> V_59 = V_161 - V_81 ;
V_6 -> V_45 = V_161 ;
V_6 -> V_43 = V_140 - V_161 ;
V_55 = V_6 -> V_44 ;
V_55 -> V_162 = V_163 ;
V_55 -> V_164 = V_81 ;
V_55 -> V_59 = V_6 -> V_59 ;
F_28 ( ! F_100 ( V_6 -> V_45 ) ) ;
F_28 ( V_6 -> V_43 % V_26 ) ;
V_117 -> V_162 = F_101 ( V_163 ) ;
V_117 -> V_124 [ 0 ] . V_116 = L_18 ;
V_117 -> V_124 [ 0 ] . V_128 = ( V_165 ) ( V_166 ) V_6 -> V_44 ;
V_117 -> V_124 [ 0 ] . V_24 = V_140 ;
V_117 -> V_124 [ 0 ] . V_133 = V_167 ;
V_117 -> V_168 = F_77 ;
V_117 -> V_169 = V_170 ;
V_117 -> V_171 = F_83 ;
V_117 -> V_172 = F_85 ;
V_117 -> V_173 = F_87 ;
V_75 = F_102 ( V_174 , V_117 ) ;
if ( V_75 )
goto V_175;
if ( V_156 -> V_176 . V_177 == 0 )
V_156 -> V_176 . V_177 = 512 ;
V_156 -> V_176 . V_178 = 128 ;
V_156 -> V_176 . V_179 = 128 ;
V_75 = F_89 ( V_180 , V_6 -> V_93 . V_116 ,
V_6 -> V_93 . V_181 -> V_145 ) ;
if ( V_75 )
goto V_182;
return 0 ;
V_182:
F_103 ( & V_6 -> V_93 ) ;
V_175:
F_104 ( V_6 -> V_44 ) ;
V_160:
F_70 ( V_117 -> V_116 ) ;
return V_75 ;
}
static int F_105 ( int V_108 , void * V_109 , void * V_110 )
{
struct V_1 * V_96 = V_109 ;
if ( F_32 ( V_97 , & V_96 -> V_68 ) )
return 0 ;
return - V_69 ;
}
static void F_106 ( struct V_183 * V_109 )
{
struct V_3 * V_156 = F_78 ( V_109 , struct V_3 , V_183 ) ;
struct V_5 * V_6 = F_2 ( V_156 ) ;
F_70 ( V_6 ) ;
}
static void F_107 ( struct V_3 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_156 ) ;
int V_37 ;
F_108 ( & V_6 -> V_94 ) ;
F_104 ( V_6 -> V_44 ) ;
F_7 ( & V_6 -> V_19 ) ;
V_37 = F_66 ( & V_6 -> V_20 , F_105 , NULL ) ;
F_109 ( & V_6 -> V_20 ) ;
F_9 ( & V_6 -> V_19 ) ;
F_28 ( V_37 ) ;
if ( V_6 -> V_93 . V_181 ) {
F_89 ( V_184 , V_6 -> V_93 . V_116 ,
V_6 -> V_93 . V_181 -> V_145 ) ;
F_103 ( & V_6 -> V_93 ) ;
F_70 ( V_6 -> V_93 . V_116 ) ;
F_70 ( V_6 -> V_116 ) ;
}
F_110 ( & V_156 -> V_183 , F_106 ) ;
}
static T_6 F_111 ( struct V_3 * V_156 ,
const char * V_127 , T_6 V_185 )
{
struct V_5 * V_6 = F_2 ( V_156 ) ;
char * V_186 , * V_187 , * V_188 , * V_189 ;
T_7 args [ V_190 ] ;
int V_75 = 0 , V_191 ;
unsigned long V_192 ;
V_188 = F_72 ( V_127 , V_9 ) ;
if ( ! V_188 )
return - V_95 ;
V_186 = V_188 ;
while ( ( V_187 = F_112 ( & V_188 , L_19 ) ) != NULL ) {
if ( ! * V_187 )
continue;
V_191 = F_113 ( V_187 , V_193 , args ) ;
switch ( V_191 ) {
case V_194 :
if ( F_114 ( V_6 -> V_159 , & args [ 0 ] ,
V_195 ) == 0 ) {
V_75 = - V_69 ;
break;
}
F_30 ( L_20 , V_6 -> V_159 ) ;
break;
case V_196 :
V_189 = F_115 ( & args [ 0 ] ) ;
if ( ! V_189 ) {
V_75 = - V_95 ;
break;
}
V_75 = F_116 ( V_189 , 0 , ( unsigned long * ) & V_6 -> V_197 ) ;
F_70 ( V_189 ) ;
if ( V_75 < 0 )
F_47 ( L_21 ) ;
break;
case V_198 :
V_189 = F_115 ( & args [ 0 ] ) ;
if ( ! V_189 ) {
V_75 = - V_95 ;
break;
}
V_75 = F_116 ( V_189 , 0 , & V_192 ) ;
F_70 ( V_189 ) ;
if ( V_75 < 0 ) {
F_47 ( L_22 ) ;
break;
}
if ( ! V_192 ) {
F_47 ( L_23 ) ;
break;
}
V_156 -> V_176 . V_177 = V_192 ;
break;
default:
break;
}
}
F_70 ( V_186 ) ;
return ( ! V_75 ) ? V_185 : V_75 ;
}
static T_6 F_117 ( struct V_3 * V_156 , char * V_199 )
{
struct V_5 * V_6 = F_2 ( V_156 ) ;
T_6 V_200 = 0 ;
V_200 = sprintf ( V_199 + V_200 , L_24 ,
V_6 -> V_159 [ 0 ] ? V_6 -> V_159 : L_25 ) ;
V_200 += sprintf ( V_199 + V_200 , L_26 , V_6 -> V_197 ) ;
return V_200 ;
}
static T_8 F_118 ( struct V_3 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_156 ) ;
return F_119 ( V_6 -> V_197 - V_156 -> V_176 . V_201 ,
V_156 -> V_176 . V_201 ) ;
}
static T_9
F_120 ( struct V_2 * V_2 )
{
int V_75 = F_46 ( V_2 ) ;
if ( V_75 != 0 )
return V_202 ;
else
return V_203 ;
}
static T_9
F_121 ( struct V_2 * V_96 )
{
return F_122 ( V_96 , F_120 ) ;
}
static int T_10 F_123 ( void )
{
int V_75 ;
F_124 ( ( sizeof( struct V_63 ) % V_73 ) != 0 ) ;
V_8 = F_125 ( L_27 ,
sizeof( struct V_1 ) ,
F_126 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_95 ;
V_174 = F_127 ( L_28 ) ;
if ( F_128 ( V_174 ) ) {
V_75 = F_129 ( V_174 ) ;
goto V_204;
}
V_75 = F_130 ( & V_150 ) ;
if ( V_75 < 0 ) {
goto V_205;
}
V_75 = F_131 ( & V_206 ) ;
if ( V_75 )
goto V_207;
return 0 ;
V_207:
F_132 ( & V_150 ) ;
V_205:
F_133 ( V_174 ) ;
V_204:
F_134 ( V_8 ) ;
return V_75 ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_206 ) ;
F_132 ( & V_150 ) ;
F_133 ( V_174 ) ;
F_134 ( V_8 ) ;
}
