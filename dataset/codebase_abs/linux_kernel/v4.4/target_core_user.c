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
unsigned long V_25 = ( unsigned long ) V_23 & ~ V_26 ;
V_24 = F_13 ( V_24 + V_25 , V_27 ) ;
V_23 -= V_25 ;
while ( V_24 ) {
F_14 ( F_15 ( V_23 ) ) ;
V_24 -= V_27 ;
}
}
static inline T_1 F_16 ( T_1 V_28 , T_1 V_29 , T_1 V_24 )
{
int V_30 = V_28 - V_29 ;
if ( V_30 >= 0 )
return V_30 ;
else
return V_24 + V_30 ;
}
static inline T_1 F_17 ( T_1 V_28 , T_1 V_29 , T_1 V_24 )
{
return ( V_24 - F_16 ( V_28 , V_29 , V_24 ) - 1 ) ;
}
static inline T_1 F_18 ( T_1 V_28 , T_1 V_24 )
{
return V_24 - V_28 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_31 * V_32 , unsigned int V_33 ,
struct V_34 * * V_35 , int * V_36 , bool V_37 )
{
int V_38 ;
void * V_39 , * V_40 ;
T_1 V_41 ;
struct V_31 * V_42 ;
F_20 (data_sg, sg, data_nents, i) {
V_41 = F_21 ( T_1 , V_42 -> V_15 ,
F_18 ( V_6 -> V_43 , V_6 -> V_44 ) ) ;
V_39 = F_22 ( F_23 ( V_42 ) ) + V_42 -> V_25 ;
V_40 = ( void * ) V_6 -> V_45 + V_6 -> V_46 + V_6 -> V_43 ;
if ( V_37 ) {
memcpy ( V_40 , V_39 , V_41 ) ;
F_12 ( V_40 , V_41 ) ;
}
( * V_35 ) -> V_47 = V_41 ;
( * V_35 ) -> V_48 = ( void V_49 * ) V_6 -> V_46 +
V_6 -> V_43 ;
( * V_36 ) ++ ;
( * V_35 ) ++ ;
F_24 ( V_6 -> V_43 , V_41 , V_6 -> V_44 ) ;
if ( V_42 -> V_15 != V_41 ) {
void * V_50 = V_39 + V_41 ;
V_41 = V_42 -> V_15 - V_41 ;
( * V_35 ) -> V_47 = V_41 ;
( * V_35 ) -> V_48 = ( void V_49 * ) V_6 -> V_46 +
V_6 -> V_43 ;
if ( V_37 ) {
V_40 = ( void * ) V_6 -> V_45 +
V_6 -> V_46 + V_6 -> V_43 ;
memcpy ( V_40 , V_50 , V_41 ) ;
F_12 ( V_40 , V_41 ) ;
}
( * V_36 ) ++ ;
( * V_35 ) ++ ;
F_24 ( V_6 -> V_43 ,
V_41 , V_6 -> V_44 ) ;
}
F_25 ( V_39 - V_42 -> V_25 ) ;
}
}
static void F_26 ( struct V_5 * V_6 ,
struct V_31 * V_32 , unsigned int V_33 )
{
int V_38 ;
void * V_39 , * V_40 ;
T_1 V_41 ;
struct V_31 * V_42 ;
F_20 (data_sg, sg, data_nents, i) {
V_41 = F_21 ( T_1 , V_42 -> V_15 ,
F_18 ( V_6 -> V_51 , V_6 -> V_44 ) ) ;
V_40 = F_22 ( F_23 ( V_42 ) ) + V_42 -> V_25 ;
F_27 ( V_42 -> V_15 + V_42 -> V_25 > V_27 ) ;
V_39 = ( void * ) V_6 -> V_45 +
V_6 -> V_46 + V_6 -> V_51 ;
F_12 ( V_39 , V_41 ) ;
memcpy ( V_40 , V_39 , V_41 ) ;
F_24 ( V_6 -> V_51 , V_41 , V_6 -> V_44 ) ;
if ( V_42 -> V_15 != V_41 ) {
void * V_52 = V_40 + V_41 ;
V_39 = ( void * ) V_6 -> V_45 +
V_6 -> V_46 + V_6 -> V_51 ;
F_27 ( V_6 -> V_51 ) ;
V_41 = V_42 -> V_15 - V_41 ;
F_12 ( V_39 , V_41 ) ;
memcpy ( V_52 , V_39 , V_41 ) ;
F_24 ( V_6 -> V_51 ,
V_41 , V_6 -> V_44 ) ;
}
F_25 ( V_40 - V_42 -> V_25 ) ;
}
}
static bool F_28 ( struct V_5 * V_6 , T_1 V_53 , T_1 V_54 )
{
struct V_55 * V_56 = V_6 -> V_45 ;
T_1 V_57 ;
T_2 V_58 ;
T_1 V_59 ;
F_12 ( V_56 , sizeof( * V_56 ) ) ;
V_58 = V_56 -> V_58 % V_6 -> V_60 ;
if ( F_18 ( V_58 , V_6 -> V_60 ) >= V_53 )
V_59 = V_53 ;
else
V_59 = V_53 + F_18 ( V_58 , V_6 -> V_60 ) ;
V_57 = F_17 ( V_58 , V_6 -> V_61 , V_6 -> V_60 ) ;
if ( V_57 < V_59 ) {
F_29 ( L_1 , V_58 ,
V_6 -> V_61 , V_6 -> V_60 ) ;
return false ;
}
V_57 = F_17 ( V_6 -> V_43 , V_6 -> V_51 , V_6 -> V_44 ) ;
if ( V_57 < V_54 ) {
F_29 ( L_2 , V_6 -> V_43 ,
V_6 -> V_51 , V_6 -> V_44 ) ;
return false ;
}
return true ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_62 , V_63 ;
struct V_55 * V_56 ;
struct V_64 * V_65 ;
struct V_34 * V_35 ;
int V_36 ;
T_3 V_58 ;
T_4 V_66 ;
bool V_67 ;
if ( F_31 ( V_68 , & V_6 -> V_69 ) )
return - V_70 ;
V_62 = F_32 ( F_33 ( struct V_64 ,
V_71 . V_35 [ V_2 -> V_14 +
V_2 -> V_72 + 2 ] ) ,
sizeof( struct V_64 ) ) ;
V_63 = V_62
+ F_13 ( F_34 ( V_2 -> V_73 ) , V_74 ) ;
F_27 ( V_63 & ( V_74 - 1 ) ) ;
F_7 ( & V_6 -> V_75 ) ;
V_56 = V_6 -> V_45 ;
V_58 = V_56 -> V_58 % V_6 -> V_60 ;
if ( ( V_63 > ( V_6 -> V_60 / 2 ) )
|| V_1 -> V_10 > ( V_6 -> V_44 - 1 ) )
F_35 ( L_3
L_4 , V_63 , V_1 -> V_10 ,
V_6 -> V_60 , V_6 -> V_44 ) ;
while ( ! F_28 ( V_6 , V_63 , V_1 -> V_10 ) ) {
int V_76 ;
F_36 ( V_77 ) ;
F_37 ( & V_6 -> V_78 , & V_77 , V_79 ) ;
F_29 ( L_5 ) ;
F_9 ( & V_6 -> V_75 ) ;
V_76 = F_38 ( F_5 ( V_18 ) ) ;
F_39 ( & V_6 -> V_78 , & V_77 ) ;
if ( ! V_76 ) {
F_35 ( L_6 ) ;
return - V_80 ;
}
F_7 ( & V_6 -> V_75 ) ;
V_58 = V_56 -> V_58 % V_6 -> V_60 ;
}
if ( F_18 ( V_58 , V_6 -> V_60 ) < V_63 ) {
T_1 V_81 = F_18 ( V_58 , V_6 -> V_60 ) ;
V_65 = ( void * ) V_56 + V_82 + V_58 ;
F_12 ( V_65 , sizeof( * V_65 ) ) ;
F_40 ( & V_65 -> V_83 . V_84 , V_85 ) ;
F_41 ( & V_65 -> V_83 . V_84 , V_81 ) ;
V_65 -> V_83 . V_7 = 0 ;
V_65 -> V_83 . V_86 = 0 ;
V_65 -> V_83 . V_87 = 0 ;
F_24 ( V_56 -> V_58 , V_81 , V_6 -> V_60 ) ;
V_58 = V_56 -> V_58 % V_6 -> V_60 ;
F_27 ( V_58 != 0 ) ;
}
V_65 = ( void * ) V_56 + V_82 + V_58 ;
F_12 ( V_65 , sizeof( * V_65 ) ) ;
F_40 ( & V_65 -> V_83 . V_84 , V_88 ) ;
F_41 ( & V_65 -> V_83 . V_84 , V_63 ) ;
V_65 -> V_83 . V_7 = V_1 -> V_7 ;
V_65 -> V_83 . V_86 = 0 ;
V_65 -> V_83 . V_87 = 0 ;
V_35 = & V_65 -> V_71 . V_35 [ 0 ] ;
V_36 = 0 ;
V_67 = ( V_2 -> V_89 == V_90
|| V_2 -> V_11 & V_12 ) ;
F_19 ( V_6 , V_2 -> V_91 ,
V_2 -> V_72 , & V_35 , & V_36 , V_67 ) ;
V_65 -> V_71 . V_36 = V_36 ;
V_65 -> V_71 . V_92 = 0 ;
V_36 = 0 ;
F_19 ( V_6 , V_2 -> V_13 ,
V_2 -> V_14 , & V_35 , & V_36 , false ) ;
V_65 -> V_71 . V_93 = V_36 ;
V_66 = V_82 + V_58 + V_62 ;
memcpy ( ( void * ) V_56 + V_66 , V_2 -> V_73 , F_34 ( V_2 -> V_73 ) ) ;
V_65 -> V_71 . V_66 = V_66 ;
F_12 ( V_65 , sizeof( * V_65 ) ) ;
F_24 ( V_56 -> V_58 , V_63 , V_6 -> V_60 ) ;
F_12 ( V_56 , sizeof( * V_56 ) ) ;
F_9 ( & V_6 -> V_75 ) ;
F_42 ( & V_6 -> V_94 ) ;
F_43 ( & V_6 -> V_95 ,
F_44 ( V_17 + F_5 ( V_18 ) ) ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_76 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_96 ;
V_76 = F_30 ( V_1 ) ;
if ( V_76 < 0 ) {
F_46 ( L_7 ) ;
F_7 ( & V_6 -> V_19 ) ;
F_47 ( & V_6 -> V_20 , V_1 -> V_7 ) ;
F_9 ( & V_6 -> V_19 ) ;
F_11 ( V_8 , V_1 ) ;
}
return V_76 ;
}
static void F_48 ( struct V_1 * V_97 , struct V_64 * V_65 )
{
struct V_2 * V_2 = V_97 -> V_2 ;
struct V_5 * V_6 = V_97 -> V_5 ;
if ( F_31 ( V_98 , & V_97 -> V_69 ) ) {
F_24 ( V_6 -> V_51 , V_97 -> V_10 , V_6 -> V_44 ) ;
return;
}
if ( V_65 -> V_83 . V_87 & V_99 ) {
F_24 ( V_6 -> V_51 , V_97 -> V_10 , V_6 -> V_44 ) ;
F_35 ( L_8 ,
V_97 -> V_2 ) ;
V_65 -> V_100 . V_101 = V_102 ;
} else if ( V_65 -> V_100 . V_101 == V_102 ) {
memcpy ( V_2 -> V_103 , V_65 -> V_100 . V_103 ,
V_2 -> V_104 ) ;
F_24 ( V_6 -> V_51 , V_97 -> V_10 , V_6 -> V_44 ) ;
} else if ( V_2 -> V_11 & V_12 ) {
F_24 ( V_6 -> V_51 ,
( T_1 ) V_2 -> V_91 -> V_15 , V_6 -> V_44 ) ;
F_26 ( V_6 ,
V_2 -> V_13 , V_2 -> V_14 ) ;
} else if ( V_2 -> V_89 == V_105 ) {
F_26 ( V_6 ,
V_2 -> V_91 , V_2 -> V_72 ) ;
} else if ( V_2 -> V_89 == V_90 ) {
F_24 ( V_6 -> V_51 , V_97 -> V_10 , V_6 -> V_44 ) ;
} else if ( V_2 -> V_89 != V_106 ) {
F_35 ( L_9 ,
V_2 -> V_89 ) ;
}
F_49 ( V_97 -> V_2 , V_65 -> V_100 . V_101 ) ;
V_97 -> V_2 = NULL ;
F_11 ( V_8 , V_97 ) ;
}
static unsigned int F_50 ( struct V_5 * V_6 )
{
struct V_55 * V_56 ;
unsigned long V_69 ;
int V_107 = 0 ;
if ( F_31 ( V_68 , & V_6 -> V_69 ) ) {
F_46 ( L_10 ) ;
return 0 ;
}
F_51 ( & V_6 -> V_75 , V_69 ) ;
V_56 = V_6 -> V_45 ;
F_12 ( V_56 , sizeof( * V_56 ) ) ;
while ( V_6 -> V_61 != F_52 ( V_56 -> V_108 ) ) {
struct V_64 * V_65 = ( void * ) V_56 + V_82 + V_6 -> V_61 ;
struct V_1 * V_97 ;
F_12 ( V_65 , sizeof( * V_65 ) ) ;
if ( F_53 ( V_65 -> V_83 . V_84 ) == V_85 ) {
F_24 ( V_6 -> V_61 ,
F_54 ( V_65 -> V_83 . V_84 ) ,
V_6 -> V_60 ) ;
continue;
}
F_27 ( F_53 ( V_65 -> V_83 . V_84 ) != V_88 ) ;
F_55 ( & V_6 -> V_19 ) ;
V_97 = F_56 ( & V_6 -> V_20 , V_65 -> V_83 . V_7 ) ;
if ( V_97 )
F_47 ( & V_6 -> V_20 , V_97 -> V_7 ) ;
F_57 ( & V_6 -> V_19 ) ;
if ( ! V_97 ) {
F_46 ( L_11 ) ;
F_58 ( V_68 , & V_6 -> V_69 ) ;
break;
}
F_48 ( V_97 , V_65 ) ;
F_24 ( V_6 -> V_61 ,
F_54 ( V_65 -> V_83 . V_84 ) ,
V_6 -> V_60 ) ;
V_107 ++ ;
}
if ( V_56 -> V_108 == V_56 -> V_58 )
F_59 ( & V_6 -> V_95 ) ;
F_60 ( & V_6 -> V_75 , V_69 ) ;
F_61 ( & V_6 -> V_78 ) ;
return V_107 ;
}
static int F_62 ( int V_109 , void * V_110 , void * V_111 )
{
struct V_1 * V_97 = V_110 ;
if ( F_31 ( V_98 , & V_97 -> V_69 ) )
return 0 ;
if ( ! F_63 ( V_17 , V_97 -> V_16 ) )
return 0 ;
F_58 ( V_98 , & V_97 -> V_69 ) ;
F_49 ( V_97 -> V_2 , V_102 ) ;
V_97 -> V_2 = NULL ;
F_11 ( V_8 , V_97 ) ;
return 0 ;
}
static void F_64 ( unsigned long V_111 )
{
struct V_5 * V_6 = (struct V_5 * ) V_111 ;
unsigned long V_69 ;
int V_107 ;
V_107 = F_50 ( V_6 ) ;
F_35 ( L_12 , V_107 ) ;
F_51 ( & V_6 -> V_19 , V_69 ) ;
F_65 ( & V_6 -> V_20 , F_62 , NULL ) ;
F_60 ( & V_6 -> V_19 , V_69 ) ;
}
static int F_66 ( struct V_112 * V_113 , T_2 V_114 )
{
struct V_115 * V_115 ;
V_115 = F_67 ( sizeof( struct V_115 ) , V_9 ) ;
if ( ! V_115 )
return - V_96 ;
V_115 -> V_114 = V_114 ;
V_113 -> V_116 = V_115 ;
return 0 ;
}
static void F_68 ( struct V_112 * V_113 )
{
F_69 ( V_113 -> V_116 ) ;
V_113 -> V_116 = NULL ;
}
static struct V_3 * F_70 ( struct V_112 * V_113 , const char * V_117 )
{
struct V_5 * V_6 ;
V_6 = F_67 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_117 = F_71 ( V_117 , V_9 ) ;
if ( ! V_6 -> V_117 ) {
F_69 ( V_6 ) ;
return NULL ;
}
V_6 -> V_113 = V_113 ;
F_72 ( & V_6 -> V_78 ) ;
F_73 ( & V_6 -> V_75 ) ;
F_74 ( & V_6 -> V_20 ) ;
F_73 ( & V_6 -> V_19 ) ;
F_75 ( & V_6 -> V_95 , F_64 ,
( unsigned long ) V_6 ) ;
return & V_6 -> V_4 ;
}
static int F_76 ( struct V_94 * V_118 , T_5 V_119 )
{
struct V_5 * V_5 = F_77 ( V_118 , struct V_5 , V_94 ) ;
F_50 ( V_5 ) ;
return 0 ;
}
static int F_78 ( struct V_120 * V_121 )
{
struct V_5 * V_6 = V_121 -> V_122 ;
struct V_94 * V_118 = & V_6 -> V_94 ;
if ( V_121 -> V_123 < V_124 ) {
if ( V_118 -> V_125 [ V_121 -> V_123 ] . V_24 == 0 )
return - 1 ;
return ( int ) V_121 -> V_123 ;
}
return - 1 ;
}
static int F_79 ( struct V_120 * V_121 , struct V_126 * V_127 )
{
struct V_5 * V_6 = V_121 -> V_122 ;
struct V_94 * V_118 = & V_6 -> V_94 ;
struct V_128 * V_128 ;
unsigned long V_25 ;
void * V_129 ;
int V_130 = F_78 ( V_121 ) ;
if ( V_130 < 0 )
return V_131 ;
V_25 = ( V_127 -> V_132 - V_130 ) << V_133 ;
V_129 = ( void * ) ( unsigned long ) V_118 -> V_125 [ V_130 ] . V_129 + V_25 ;
if ( V_118 -> V_125 [ V_130 ] . V_134 == V_135 )
V_128 = F_15 ( V_129 ) ;
else
V_128 = F_80 ( V_129 ) ;
F_81 ( V_128 ) ;
V_127 -> V_128 = V_128 ;
return 0 ;
}
static int F_82 ( struct V_94 * V_118 , struct V_120 * V_121 )
{
struct V_5 * V_6 = F_77 ( V_118 , struct V_5 , V_94 ) ;
V_121 -> V_136 |= V_137 | V_138 ;
V_121 -> V_139 = & V_140 ;
V_121 -> V_122 = V_6 ;
if ( F_83 ( V_121 ) != ( V_141 >> V_133 ) )
return - V_70 ;
return 0 ;
}
static int F_84 ( struct V_94 * V_118 , struct V_142 * V_142 )
{
struct V_5 * V_6 = F_77 ( V_118 , struct V_5 , V_94 ) ;
if ( F_85 ( V_143 , & V_6 -> V_69 ) )
return - V_144 ;
F_29 ( L_13 ) ;
return 0 ;
}
static int F_86 ( struct V_94 * V_118 , struct V_142 * V_142 )
{
struct V_5 * V_6 = F_77 ( V_118 , struct V_5 , V_94 ) ;
F_87 ( V_143 , & V_6 -> V_69 ) ;
F_29 ( L_14 ) ;
return 0 ;
}
static int F_88 ( enum V_145 V_97 , const char * V_117 , int V_146 )
{
struct V_147 * V_148 ;
void * V_149 ;
int V_76 = - V_96 ;
V_148 = F_89 ( V_150 , V_9 ) ;
if ( ! V_148 )
return V_76 ;
V_149 = F_90 ( V_148 , 0 , 0 , & V_151 , 0 , V_97 ) ;
if ( ! V_149 )
goto V_152;
V_76 = F_91 ( V_148 , V_153 , V_117 ) ;
if ( V_76 < 0 )
goto V_152;
V_76 = F_92 ( V_148 , V_154 , V_146 ) ;
if ( V_76 < 0 )
goto V_152;
F_93 ( V_148 , V_149 ) ;
V_76 = F_94 ( & V_151 , V_148 , 0 ,
V_155 , V_9 ) ;
if ( V_76 == - V_156 )
V_76 = 0 ;
return V_76 ;
V_152:
F_95 ( V_148 ) ;
return V_76 ;
}
static int F_96 ( struct V_3 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_157 ) ;
struct V_115 * V_113 = V_6 -> V_113 -> V_116 ;
struct V_94 * V_118 ;
struct V_55 * V_56 ;
T_1 V_24 ;
T_1 V_158 ;
int V_76 = 0 ;
char * V_159 ;
V_118 = & V_6 -> V_94 ;
V_24 = snprintf ( NULL , 0 , L_15 , V_113 -> V_114 , V_6 -> V_117 ,
V_6 -> V_160 ) ;
V_24 += 1 ;
V_159 = F_97 ( V_24 , V_9 ) ;
if ( ! V_159 )
return - V_96 ;
V_158 = snprintf ( V_159 , V_24 , L_16 , V_113 -> V_114 , V_6 -> V_117 ) ;
if ( V_6 -> V_160 [ 0 ] )
snprintf ( V_159 + V_158 , V_24 - V_158 , L_17 , V_6 -> V_160 ) ;
V_118 -> V_117 = V_159 ;
V_6 -> V_45 = F_98 ( V_141 ) ;
if ( ! V_6 -> V_45 ) {
V_76 = - V_96 ;
goto V_161;
}
V_6 -> V_60 = V_162 - V_82 ;
V_6 -> V_46 = V_162 ;
V_6 -> V_44 = V_141 - V_162 ;
V_56 = V_6 -> V_45 ;
V_56 -> V_163 = V_164 ;
V_56 -> V_165 = V_82 ;
V_56 -> V_60 = V_6 -> V_60 ;
F_27 ( ! F_99 ( V_6 -> V_46 ) ) ;
F_27 ( V_6 -> V_44 % V_27 ) ;
V_118 -> V_163 = F_100 ( V_164 ) ;
V_118 -> V_125 [ 0 ] . V_117 = L_18 ;
V_118 -> V_125 [ 0 ] . V_129 = ( V_166 ) V_6 -> V_45 ;
V_118 -> V_125 [ 0 ] . V_24 = V_141 ;
V_118 -> V_125 [ 0 ] . V_134 = V_167 ;
V_118 -> V_168 = F_76 ;
V_118 -> V_169 = V_170 ;
V_118 -> V_171 = F_82 ;
V_118 -> V_172 = F_84 ;
V_118 -> V_173 = F_86 ;
V_76 = F_101 ( V_174 , V_118 ) ;
if ( V_76 )
goto V_175;
V_157 -> V_176 . V_177 = 512 ;
V_157 -> V_176 . V_178 = 128 ;
V_157 -> V_176 . V_179 = 128 ;
V_76 = F_88 ( V_180 , V_6 -> V_94 . V_117 ,
V_6 -> V_94 . V_181 -> V_146 ) ;
if ( V_76 )
goto V_182;
return 0 ;
V_182:
F_102 ( & V_6 -> V_94 ) ;
V_175:
F_103 ( V_6 -> V_45 ) ;
V_161:
F_69 ( V_118 -> V_117 ) ;
return V_76 ;
}
static int F_104 ( int V_109 , void * V_110 , void * V_111 )
{
struct V_1 * V_97 = V_110 ;
if ( F_31 ( V_98 , & V_97 -> V_69 ) )
return 0 ;
return - V_70 ;
}
static void F_105 ( struct V_183 * V_110 )
{
struct V_3 * V_157 = F_77 ( V_110 , struct V_3 , V_183 ) ;
struct V_5 * V_6 = F_2 ( V_157 ) ;
F_69 ( V_6 ) ;
}
static void F_106 ( struct V_3 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_157 ) ;
int V_38 ;
F_107 ( & V_6 -> V_95 ) ;
F_103 ( V_6 -> V_45 ) ;
F_7 ( & V_6 -> V_19 ) ;
V_38 = F_65 ( & V_6 -> V_20 , F_104 , NULL ) ;
F_108 ( & V_6 -> V_20 ) ;
F_9 ( & V_6 -> V_19 ) ;
F_27 ( V_38 ) ;
if ( V_6 -> V_94 . V_181 ) {
F_88 ( V_184 , V_6 -> V_94 . V_117 ,
V_6 -> V_94 . V_181 -> V_146 ) ;
F_102 ( & V_6 -> V_94 ) ;
F_69 ( V_6 -> V_94 . V_117 ) ;
F_69 ( V_6 -> V_117 ) ;
}
F_109 ( & V_157 -> V_183 , F_105 ) ;
}
static T_6 F_110 ( struct V_3 * V_157 ,
const char * V_128 , T_6 V_185 )
{
struct V_5 * V_6 = F_2 ( V_157 ) ;
char * V_186 , * V_187 , * V_188 , * V_189 ;
T_7 args [ V_190 ] ;
int V_76 = 0 , V_191 ;
unsigned long V_192 ;
V_188 = F_71 ( V_128 , V_9 ) ;
if ( ! V_188 )
return - V_96 ;
V_186 = V_188 ;
while ( ( V_187 = F_111 ( & V_188 , L_19 ) ) != NULL ) {
if ( ! * V_187 )
continue;
V_191 = F_112 ( V_187 , V_193 , args ) ;
switch ( V_191 ) {
case V_194 :
if ( F_113 ( V_6 -> V_160 , & args [ 0 ] ,
V_195 ) == 0 ) {
V_76 = - V_70 ;
break;
}
F_29 ( L_20 , V_6 -> V_160 ) ;
break;
case V_196 :
V_189 = F_114 ( & args [ 0 ] ) ;
if ( ! V_189 ) {
V_76 = - V_96 ;
break;
}
V_76 = F_115 ( V_189 , 0 , ( unsigned long * ) & V_6 -> V_197 ) ;
F_69 ( V_189 ) ;
if ( V_76 < 0 )
F_46 ( L_21 ) ;
break;
case V_198 :
V_189 = F_114 ( & args [ 0 ] ) ;
if ( ! V_189 ) {
V_76 = - V_96 ;
break;
}
V_76 = F_115 ( V_189 , 0 , & V_192 ) ;
F_69 ( V_189 ) ;
if ( V_76 < 0 ) {
F_46 ( L_22 ) ;
break;
}
if ( ! V_192 ) {
F_46 ( L_23 ) ;
break;
}
V_157 -> V_176 . V_177 = V_192 ;
break;
default:
break;
}
}
F_69 ( V_186 ) ;
return ( ! V_76 ) ? V_185 : V_76 ;
}
static T_6 F_116 ( struct V_3 * V_157 , char * V_199 )
{
struct V_5 * V_6 = F_2 ( V_157 ) ;
T_6 V_200 = 0 ;
V_200 = sprintf ( V_199 + V_200 , L_24 ,
V_6 -> V_160 [ 0 ] ? V_6 -> V_160 : L_25 ) ;
V_200 += sprintf ( V_199 + V_200 , L_26 , V_6 -> V_197 ) ;
return V_200 ;
}
static T_8 F_117 ( struct V_3 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_157 ) ;
return F_118 ( V_6 -> V_197 - V_157 -> V_176 . V_201 ,
V_157 -> V_176 . V_201 ) ;
}
static T_9
F_119 ( struct V_2 * V_2 )
{
int V_76 = F_45 ( V_2 ) ;
if ( V_76 != 0 )
return V_202 ;
else
return V_203 ;
}
static T_9
F_120 ( struct V_2 * V_97 )
{
return F_121 ( V_97 , F_119 ) ;
}
static int T_10 F_122 ( void )
{
int V_76 ;
F_123 ( ( sizeof( struct V_64 ) % V_74 ) != 0 ) ;
V_8 = F_124 ( L_27 ,
sizeof( struct V_1 ) ,
F_125 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_96 ;
V_174 = F_126 ( L_28 ) ;
if ( F_127 ( V_174 ) ) {
V_76 = F_128 ( V_174 ) ;
goto V_204;
}
V_76 = F_129 ( & V_151 ) ;
if ( V_76 < 0 ) {
goto V_205;
}
V_76 = F_130 ( & V_206 ) ;
if ( V_76 )
goto V_207;
return 0 ;
V_207:
F_131 ( & V_151 ) ;
V_205:
F_132 ( V_174 ) ;
V_204:
F_133 ( V_8 ) ;
return V_76 ;
}
static void T_11 F_134 ( void )
{
F_135 ( & V_206 ) ;
F_131 ( & V_151 ) ;
F_132 ( V_174 ) ;
F_133 ( V_8 ) ;
}
