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
V_1 -> V_11 = V_12 + F_4 ( V_13 ) ;
F_5 ( V_9 ) ;
F_6 ( & V_6 -> V_14 ) ;
V_7 = F_7 ( & V_6 -> V_15 , V_1 , 0 ,
V_16 , V_17 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_9 () ;
if ( V_7 < 0 ) {
F_10 ( V_8 , V_1 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return V_1 ;
}
static inline void F_11 ( void * V_18 , T_1 V_19 )
{
unsigned long V_20 = ( unsigned long ) V_18 & ~ V_21 ;
V_19 = F_12 ( V_19 + V_20 , V_22 ) ;
V_18 -= V_20 ;
while ( V_19 ) {
F_13 ( F_14 ( V_18 ) ) ;
V_19 -= V_22 ;
}
}
static inline T_1 F_15 ( T_1 V_23 , T_1 V_24 , T_1 V_19 )
{
int V_25 = V_23 - V_24 ;
if ( V_25 >= 0 )
return V_25 ;
else
return V_19 + V_25 ;
}
static inline T_1 F_16 ( T_1 V_23 , T_1 V_24 , T_1 V_19 )
{
return ( V_19 - F_15 ( V_23 , V_24 , V_19 ) - 1 ) ;
}
static inline T_1 F_17 ( T_1 V_23 , T_1 V_19 )
{
return V_19 - V_23 ;
}
static bool F_18 ( struct V_5 * V_6 , T_1 V_26 , T_1 V_27 )
{
struct V_28 * V_29 = V_6 -> V_30 ;
T_1 V_31 ;
T_2 V_32 ;
T_1 V_33 ;
F_11 ( V_29 , sizeof( * V_29 ) ) ;
V_32 = V_29 -> V_32 % V_6 -> V_34 ;
if ( F_17 ( V_32 , V_6 -> V_34 ) >= V_26 )
V_33 = V_26 ;
else
V_33 = V_26 + F_17 ( V_32 , V_6 -> V_34 ) ;
V_31 = F_16 ( V_32 , V_6 -> V_35 , V_6 -> V_34 ) ;
if ( V_31 < V_33 ) {
F_19 ( L_1 , V_32 ,
V_6 -> V_35 , V_6 -> V_34 ) ;
return false ;
}
V_31 = F_16 ( V_6 -> V_36 , V_6 -> V_37 , V_6 -> V_38 ) ;
if ( V_31 < V_27 ) {
F_19 ( L_2 , V_6 -> V_36 ,
V_6 -> V_37 , V_6 -> V_38 ) ;
return false ;
}
return true ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_39 , V_40 ;
struct V_28 * V_29 ;
struct V_41 * V_42 ;
int V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_48 = 0 ;
T_3 V_32 ;
T_4 V_49 ;
if ( F_21 ( V_50 , & V_6 -> V_51 ) )
return - V_52 ;
V_39 = F_22 ( F_23 ( struct V_41 ,
V_53 . V_47 [ V_2 -> V_54 + 2 ] ) ,
sizeof( struct V_41 ) ) ;
V_40 = V_39
+ F_12 ( F_24 ( V_2 -> V_55 ) , V_56 ) ;
F_25 ( V_40 & ( V_56 - 1 ) ) ;
F_6 ( & V_6 -> V_57 ) ;
V_29 = V_6 -> V_30 ;
V_32 = V_29 -> V_32 % V_6 -> V_34 ;
if ( ( V_40 > ( V_6 -> V_34 / 2 ) )
|| V_1 -> V_10 > ( V_6 -> V_38 - 1 ) )
F_26 ( L_3
L_4 , V_40 , V_1 -> V_10 ,
V_6 -> V_34 , V_6 -> V_38 ) ;
while ( ! F_18 ( V_6 , V_40 , V_1 -> V_10 ) ) {
int V_58 ;
F_27 ( V_59 ) ;
F_28 ( & V_6 -> V_60 , & V_59 , V_61 ) ;
F_19 ( L_5 ) ;
F_8 ( & V_6 -> V_57 ) ;
V_58 = F_29 ( F_4 ( V_13 ) ) ;
F_30 ( & V_6 -> V_60 , & V_59 ) ;
if ( ! V_58 ) {
F_26 ( L_6 ) ;
return - V_62 ;
}
F_6 ( & V_6 -> V_57 ) ;
V_32 = V_29 -> V_32 % V_6 -> V_34 ;
}
if ( F_17 ( V_32 , V_6 -> V_34 ) < V_40 ) {
T_1 V_63 = F_17 ( V_32 , V_6 -> V_34 ) ;
V_42 = ( void * ) V_29 + V_64 + V_32 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
F_31 ( & V_42 -> V_65 . V_66 , V_67 ) ;
F_32 ( & V_42 -> V_65 . V_66 , V_63 ) ;
V_42 -> V_65 . V_7 = 0 ;
V_42 -> V_65 . V_68 = 0 ;
V_42 -> V_65 . V_69 = 0 ;
F_33 ( V_29 -> V_32 , V_63 , V_6 -> V_34 ) ;
V_32 = V_29 -> V_32 % V_6 -> V_34 ;
F_25 ( V_32 != 0 ) ;
}
V_42 = ( void * ) V_29 + V_64 + V_32 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
F_31 ( & V_42 -> V_65 . V_66 , V_70 ) ;
F_32 ( & V_42 -> V_65 . V_66 , V_40 ) ;
V_42 -> V_65 . V_7 = V_1 -> V_7 ;
V_42 -> V_65 . V_68 = 0 ;
V_42 -> V_65 . V_69 = 0 ;
V_47 = & V_42 -> V_53 . V_47 [ 0 ] ;
F_34 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, i) {
T_1 V_71 = F_35 ( ( T_1 ) V_45 -> V_72 ,
F_17 ( V_6 -> V_36 , V_6 -> V_38 ) ) ;
void * V_73 = F_36 ( F_37 ( V_45 ) ) + V_45 -> V_20 ;
void * V_74 = ( void * ) V_29 + V_6 -> V_75 + V_6 -> V_36 ;
if ( V_1 -> V_2 -> V_76 == V_77 ) {
memcpy ( V_74 , V_73 , V_71 ) ;
F_11 ( V_74 , V_71 ) ;
}
V_47 -> V_78 = V_71 ;
V_47 -> V_79 = ( void V_80 * ) V_6 -> V_75 +
V_6 -> V_36 ;
V_48 ++ ;
V_47 ++ ;
F_33 ( V_6 -> V_36 , V_71 , V_6 -> V_38 ) ;
if ( V_45 -> V_72 != V_71 ) {
V_73 += V_71 ;
V_71 = V_45 -> V_72 - V_71 ;
V_47 -> V_78 = V_71 ;
V_47 -> V_79 = ( void V_80 * ) V_6 -> V_75 +
V_6 -> V_36 ;
if ( V_2 -> V_76 == V_77 ) {
V_74 = ( void * ) V_29 + V_6 -> V_75 + V_6 -> V_36 ;
memcpy ( V_74 , V_73 , V_71 ) ;
F_11 ( V_74 , V_71 ) ;
}
V_48 ++ ;
V_47 ++ ;
F_33 ( V_6 -> V_36 , V_71 , V_6 -> V_38 ) ;
}
F_38 ( V_73 ) ;
}
V_42 -> V_53 . V_48 = V_48 ;
V_42 -> V_53 . V_81 = 0 ;
V_42 -> V_53 . V_82 = 0 ;
V_49 = V_64 + V_32 + V_39 ;
memcpy ( ( void * ) V_29 + V_49 , V_2 -> V_55 , F_24 ( V_2 -> V_55 ) ) ;
V_42 -> V_53 . V_49 = V_49 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
F_33 ( V_29 -> V_32 , V_40 , V_6 -> V_34 ) ;
F_11 ( V_29 , sizeof( * V_29 ) ) ;
F_8 ( & V_6 -> V_57 ) ;
F_39 ( & V_6 -> V_83 ) ;
F_40 ( & V_6 -> V_84 ,
F_41 ( V_12 + F_4 ( V_13 ) ) ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_58 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_85 ;
V_58 = F_20 ( V_1 ) ;
if ( V_58 < 0 ) {
F_43 ( L_7 ) ;
F_6 ( & V_6 -> V_14 ) ;
F_44 ( & V_6 -> V_15 , V_1 -> V_7 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_10 ( V_8 , V_1 ) ;
}
return V_58 ;
}
static void F_45 ( struct V_1 * V_86 , struct V_41 * V_42 )
{
struct V_2 * V_2 = V_86 -> V_2 ;
struct V_5 * V_6 = V_86 -> V_5 ;
if ( F_21 ( V_87 , & V_86 -> V_51 ) ) {
F_33 ( V_6 -> V_37 , V_86 -> V_10 , V_6 -> V_38 ) ;
return;
}
if ( V_42 -> V_65 . V_69 & V_88 ) {
F_33 ( V_6 -> V_37 , V_86 -> V_10 , V_6 -> V_38 ) ;
F_26 ( L_8 ,
V_86 -> V_2 ) ;
F_46 ( V_86 -> V_2 ,
V_89 ) ;
V_86 -> V_2 = NULL ;
F_10 ( V_8 , V_86 ) ;
return;
}
if ( V_42 -> V_90 . V_91 == V_92 ) {
memcpy ( V_2 -> V_93 , V_42 -> V_90 . V_93 ,
V_2 -> V_94 ) ;
F_33 ( V_6 -> V_37 , V_86 -> V_10 , V_6 -> V_38 ) ;
}
else if ( V_2 -> V_76 == V_95 ) {
struct V_44 * V_45 ;
int V_43 ;
F_34 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, i) {
T_1 V_71 ;
void * V_74 ;
void * V_73 ;
V_71 = F_35 ( ( T_1 ) V_45 -> V_72 ,
F_17 ( V_6 -> V_37 , V_6 -> V_38 ) ) ;
V_74 = F_36 ( F_37 ( V_45 ) ) + V_45 -> V_20 ;
F_25 ( V_45 -> V_72 + V_45 -> V_20 > V_22 ) ;
V_73 = ( void * ) V_6 -> V_30 + V_6 -> V_75 + V_6 -> V_37 ;
F_11 ( V_73 , V_71 ) ;
memcpy ( V_74 , V_73 , V_71 ) ;
F_33 ( V_6 -> V_37 , V_71 , V_6 -> V_38 ) ;
if ( V_45 -> V_72 != V_71 ) {
V_73 = ( void * ) V_6 -> V_30 + V_6 -> V_75 + V_6 -> V_37 ;
F_25 ( V_6 -> V_37 ) ;
V_74 += V_71 ;
V_71 = V_45 -> V_72 - V_71 ;
F_11 ( V_73 , V_71 ) ;
memcpy ( V_74 , V_73 , V_71 ) ;
F_33 ( V_6 -> V_37 , V_71 , V_6 -> V_38 ) ;
}
F_38 ( V_74 ) ;
}
} else if ( V_2 -> V_76 == V_77 ) {
F_33 ( V_6 -> V_37 , V_86 -> V_10 , V_6 -> V_38 ) ;
} else {
F_26 ( L_9 , V_2 -> V_76 ) ;
}
F_47 ( V_86 -> V_2 , V_42 -> V_90 . V_91 ) ;
V_86 -> V_2 = NULL ;
F_10 ( V_8 , V_86 ) ;
}
static unsigned int F_48 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
F_49 ( V_96 ) ;
unsigned long V_51 ;
int V_97 = 0 ;
if ( F_21 ( V_50 , & V_6 -> V_51 ) ) {
F_43 ( L_10 ) ;
return 0 ;
}
F_50 ( & V_6 -> V_57 , V_51 ) ;
V_29 = V_6 -> V_30 ;
F_11 ( V_29 , sizeof( * V_29 ) ) ;
while ( V_6 -> V_35 != F_51 ( V_29 -> V_98 ) ) {
struct V_41 * V_42 = ( void * ) V_29 + V_64 + V_6 -> V_35 ;
struct V_1 * V_86 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
if ( F_52 ( V_42 -> V_65 . V_66 ) == V_67 ) {
F_33 ( V_6 -> V_35 ,
F_53 ( V_42 -> V_65 . V_66 ) ,
V_6 -> V_34 ) ;
continue;
}
F_25 ( F_52 ( V_42 -> V_65 . V_66 ) != V_70 ) ;
F_54 ( & V_6 -> V_14 ) ;
V_86 = F_55 ( & V_6 -> V_15 , V_42 -> V_65 . V_7 ) ;
if ( V_86 )
F_44 ( & V_6 -> V_15 , V_86 -> V_7 ) ;
F_56 ( & V_6 -> V_14 ) ;
if ( ! V_86 ) {
F_43 ( L_11 ) ;
F_57 ( V_50 , & V_6 -> V_51 ) ;
break;
}
F_45 ( V_86 , V_42 ) ;
F_33 ( V_6 -> V_35 ,
F_53 ( V_42 -> V_65 . V_66 ) ,
V_6 -> V_34 ) ;
V_97 ++ ;
}
if ( V_29 -> V_98 == V_29 -> V_32 )
F_58 ( & V_6 -> V_84 ) ;
F_59 ( & V_6 -> V_57 , V_51 ) ;
F_60 ( & V_6 -> V_60 ) ;
return V_97 ;
}
static int F_61 ( int V_99 , void * V_100 , void * V_101 )
{
struct V_1 * V_86 = V_100 ;
if ( F_21 ( V_87 , & V_86 -> V_51 ) )
return 0 ;
if ( ! F_62 ( V_86 -> V_11 , V_12 ) )
return 0 ;
F_57 ( V_87 , & V_86 -> V_51 ) ;
F_47 ( V_86 -> V_2 , V_92 ) ;
V_86 -> V_2 = NULL ;
F_10 ( V_8 , V_86 ) ;
return 0 ;
}
static void F_63 ( unsigned long V_101 )
{
struct V_5 * V_6 = (struct V_5 * ) V_101 ;
unsigned long V_51 ;
int V_97 ;
V_97 = F_48 ( V_6 ) ;
F_26 ( L_12 , V_97 ) ;
F_50 ( & V_6 -> V_14 , V_51 ) ;
F_64 ( & V_6 -> V_15 , F_61 , NULL ) ;
F_59 ( & V_6 -> V_14 , V_51 ) ;
}
static int F_65 ( struct V_102 * V_103 , T_2 V_104 )
{
struct V_105 * V_105 ;
V_105 = F_66 ( sizeof( struct V_105 ) , V_9 ) ;
if ( ! V_105 )
return - V_85 ;
V_105 -> V_104 = V_104 ;
V_103 -> V_106 = V_105 ;
return 0 ;
}
static void F_67 ( struct V_102 * V_103 )
{
F_68 ( V_103 -> V_106 ) ;
V_103 -> V_106 = NULL ;
}
static struct V_3 * F_69 ( struct V_102 * V_103 , const char * V_107 )
{
struct V_5 * V_6 ;
V_6 = F_66 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_107 = F_70 ( V_107 , V_9 ) ;
if ( ! V_6 -> V_107 ) {
F_68 ( V_6 ) ;
return NULL ;
}
V_6 -> V_103 = V_103 ;
F_71 ( & V_6 -> V_60 ) ;
F_72 ( & V_6 -> V_57 ) ;
F_73 ( & V_6 -> V_15 ) ;
F_72 ( & V_6 -> V_14 ) ;
F_74 ( & V_6 -> V_84 , F_63 ,
( unsigned long ) V_6 ) ;
return & V_6 -> V_4 ;
}
static int F_75 ( struct V_83 * V_108 , T_5 V_109 )
{
struct V_5 * V_5 = F_76 ( V_108 , struct V_5 , V_83 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
static int F_77 ( struct V_110 * V_111 )
{
struct V_5 * V_6 = V_111 -> V_112 ;
struct V_83 * V_108 = & V_6 -> V_83 ;
if ( V_111 -> V_113 < V_114 ) {
if ( V_108 -> V_115 [ V_111 -> V_113 ] . V_19 == 0 )
return - 1 ;
return ( int ) V_111 -> V_113 ;
}
return - 1 ;
}
static int F_78 ( struct V_110 * V_111 , struct V_116 * V_117 )
{
struct V_5 * V_6 = V_111 -> V_112 ;
struct V_83 * V_108 = & V_6 -> V_83 ;
struct V_118 * V_118 ;
unsigned long V_20 ;
void * V_119 ;
int V_120 = F_77 ( V_111 ) ;
if ( V_120 < 0 )
return V_121 ;
V_20 = ( V_117 -> V_122 - V_120 ) << V_123 ;
V_119 = ( void * ) ( unsigned long ) V_108 -> V_115 [ V_120 ] . V_119 + V_20 ;
if ( V_108 -> V_115 [ V_120 ] . V_124 == V_125 )
V_118 = F_14 ( V_119 ) ;
else
V_118 = F_79 ( V_119 ) ;
F_80 ( V_118 ) ;
V_117 -> V_118 = V_118 ;
return 0 ;
}
static int F_81 ( struct V_83 * V_108 , struct V_110 * V_111 )
{
struct V_5 * V_6 = F_76 ( V_108 , struct V_5 , V_83 ) ;
V_111 -> V_126 |= V_127 | V_128 ;
V_111 -> V_129 = & V_130 ;
V_111 -> V_112 = V_6 ;
if ( F_82 ( V_111 ) != ( V_131 >> V_123 ) )
return - V_52 ;
return 0 ;
}
static int F_83 ( struct V_83 * V_108 , struct V_132 * V_132 )
{
struct V_5 * V_6 = F_76 ( V_108 , struct V_5 , V_83 ) ;
if ( F_84 ( V_133 , & V_6 -> V_51 ) )
return - V_134 ;
F_19 ( L_13 ) ;
return 0 ;
}
static int F_85 ( struct V_83 * V_108 , struct V_132 * V_132 )
{
struct V_5 * V_6 = F_76 ( V_108 , struct V_5 , V_83 ) ;
F_86 ( V_133 , & V_6 -> V_51 ) ;
F_19 ( L_14 ) ;
return 0 ;
}
static int F_87 ( enum V_135 V_86 , const char * V_107 , int V_136 )
{
struct V_137 * V_138 ;
void * V_139 ;
int V_58 = - V_85 ;
V_138 = F_88 ( V_140 , V_9 ) ;
if ( ! V_138 )
return V_58 ;
V_139 = F_89 ( V_138 , 0 , 0 , & V_141 , 0 , V_86 ) ;
if ( ! V_139 )
goto V_142;
V_58 = F_90 ( V_138 , V_143 , V_107 ) ;
if ( V_58 < 0 )
goto V_142;
V_58 = F_91 ( V_138 , V_144 , V_136 ) ;
if ( V_58 < 0 )
goto V_142;
F_92 ( V_138 , V_139 ) ;
V_58 = F_93 ( & V_141 , V_138 , 0 ,
V_145 , V_9 ) ;
if ( V_58 == - V_146 )
V_58 = 0 ;
return V_58 ;
V_142:
F_94 ( V_138 ) ;
return V_58 ;
}
static int F_95 ( struct V_3 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_147 ) ;
struct V_105 * V_103 = V_6 -> V_103 -> V_106 ;
struct V_83 * V_108 ;
struct V_28 * V_29 ;
T_1 V_19 ;
T_1 V_148 ;
int V_58 = 0 ;
char * V_149 ;
V_108 = & V_6 -> V_83 ;
V_19 = snprintf ( NULL , 0 , L_15 , V_103 -> V_104 , V_6 -> V_107 ,
V_6 -> V_150 ) ;
V_19 += 1 ;
V_149 = F_96 ( V_19 , V_9 ) ;
if ( ! V_149 )
return - V_85 ;
V_148 = snprintf ( V_149 , V_19 , L_16 , V_103 -> V_104 , V_6 -> V_107 ) ;
if ( V_6 -> V_150 [ 0 ] )
snprintf ( V_149 + V_148 , V_19 - V_148 , L_17 , V_6 -> V_150 ) ;
V_108 -> V_107 = V_149 ;
V_6 -> V_30 = F_97 ( V_131 ) ;
if ( ! V_6 -> V_30 ) {
V_58 = - V_85 ;
goto V_151;
}
V_6 -> V_34 = V_152 - V_64 ;
V_6 -> V_75 = V_152 ;
V_6 -> V_38 = V_131 - V_152 ;
V_29 = V_6 -> V_30 ;
V_29 -> V_153 = V_154 ;
V_29 -> V_155 = V_64 ;
V_29 -> V_34 = V_6 -> V_34 ;
F_25 ( ! F_98 ( V_6 -> V_75 ) ) ;
F_25 ( V_6 -> V_38 % V_22 ) ;
V_108 -> V_153 = F_99 ( V_154 ) ;
V_108 -> V_115 [ 0 ] . V_107 = L_18 ;
V_108 -> V_115 [ 0 ] . V_119 = ( V_156 ) V_6 -> V_30 ;
V_108 -> V_115 [ 0 ] . V_19 = V_131 ;
V_108 -> V_115 [ 0 ] . V_124 = V_157 ;
V_108 -> V_158 = F_75 ;
V_108 -> V_159 = V_160 ;
V_108 -> V_161 = F_81 ;
V_108 -> V_162 = F_83 ;
V_108 -> V_163 = F_85 ;
V_58 = F_100 ( V_164 , V_108 ) ;
if ( V_58 )
goto V_165;
V_147 -> V_166 . V_167 = 512 ;
V_147 -> V_166 . V_168 = 128 ;
V_147 -> V_166 . V_169 = 128 ;
V_58 = F_87 ( V_170 , V_6 -> V_83 . V_107 ,
V_6 -> V_83 . V_171 -> V_136 ) ;
if ( V_58 )
goto V_172;
return 0 ;
V_172:
F_101 ( & V_6 -> V_83 ) ;
V_165:
F_102 ( V_6 -> V_30 ) ;
V_151:
F_68 ( V_108 -> V_107 ) ;
return V_58 ;
}
static int F_103 ( int V_99 , void * V_100 , void * V_101 )
{
struct V_1 * V_86 = V_100 ;
if ( F_21 ( V_87 , & V_86 -> V_51 ) )
return 0 ;
return - V_52 ;
}
static void F_104 ( struct V_3 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_147 ) ;
int V_43 ;
F_105 ( & V_6 -> V_84 ) ;
F_102 ( V_6 -> V_30 ) ;
F_6 ( & V_6 -> V_14 ) ;
V_43 = F_64 ( & V_6 -> V_15 , F_103 , NULL ) ;
F_106 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_25 ( V_43 ) ;
if ( V_6 -> V_83 . V_171 ) {
F_87 ( V_173 , V_6 -> V_83 . V_107 ,
V_6 -> V_83 . V_171 -> V_136 ) ;
F_101 ( & V_6 -> V_83 ) ;
F_68 ( V_6 -> V_83 . V_107 ) ;
F_68 ( V_6 -> V_107 ) ;
}
F_68 ( V_6 ) ;
}
static T_6 F_107 ( struct V_3 * V_147 ,
const char * V_118 , T_6 V_174 )
{
struct V_5 * V_6 = F_2 ( V_147 ) ;
char * V_175 , * V_176 , * V_177 , * V_178 ;
T_7 args [ V_179 ] ;
int V_58 = 0 , V_180 ;
unsigned long V_181 ;
V_177 = F_70 ( V_118 , V_9 ) ;
if ( ! V_177 )
return - V_85 ;
V_175 = V_177 ;
while ( ( V_176 = F_108 ( & V_177 , L_19 ) ) != NULL ) {
if ( ! * V_176 )
continue;
V_180 = F_109 ( V_176 , V_182 , args ) ;
switch ( V_180 ) {
case V_183 :
if ( F_110 ( V_6 -> V_150 , & args [ 0 ] ,
V_184 ) == 0 ) {
V_58 = - V_52 ;
break;
}
F_19 ( L_20 , V_6 -> V_150 ) ;
break;
case V_185 :
V_178 = F_111 ( & args [ 0 ] ) ;
if ( ! V_178 ) {
V_58 = - V_85 ;
break;
}
V_58 = F_112 ( V_178 , 0 , ( unsigned long * ) & V_6 -> V_186 ) ;
F_68 ( V_178 ) ;
if ( V_58 < 0 )
F_43 ( L_21 ) ;
break;
case V_187 :
V_178 = F_111 ( & args [ 0 ] ) ;
if ( ! V_178 ) {
V_58 = - V_85 ;
break;
}
V_58 = F_112 ( V_178 , 0 , & V_181 ) ;
F_68 ( V_178 ) ;
if ( V_58 < 0 ) {
F_43 ( L_22 ) ;
break;
}
if ( ! V_181 ) {
F_43 ( L_23 ) ;
break;
}
V_147 -> V_166 . V_167 = V_181 ;
break;
default:
break;
}
}
F_68 ( V_175 ) ;
return ( ! V_58 ) ? V_174 : V_58 ;
}
static T_6 F_113 ( struct V_3 * V_147 , char * V_188 )
{
struct V_5 * V_6 = F_2 ( V_147 ) ;
T_6 V_189 = 0 ;
V_189 = sprintf ( V_188 + V_189 , L_24 ,
V_6 -> V_150 [ 0 ] ? V_6 -> V_150 : L_25 ) ;
V_189 += sprintf ( V_188 + V_189 , L_26 , V_6 -> V_186 ) ;
return V_189 ;
}
static T_8 F_114 ( struct V_3 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_147 ) ;
return F_115 ( V_6 -> V_186 - V_147 -> V_166 . V_190 ,
V_147 -> V_166 . V_190 ) ;
}
static T_9
F_116 ( struct V_2 * V_2 )
{
int V_58 = F_42 ( V_2 ) ;
if ( V_58 != 0 )
return V_89 ;
else
return V_191 ;
}
static T_9
F_117 ( struct V_2 * V_86 )
{
return F_118 ( V_86 , F_116 ) ;
}
static int T_10 F_119 ( void )
{
struct V_192 * V_193 = & V_194 . V_195 ;
int V_58 ;
F_120 ( ( sizeof( struct V_41 ) % V_56 ) != 0 ) ;
V_8 = F_121 ( L_27 ,
sizeof( struct V_1 ) ,
F_122 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_85 ;
V_164 = F_123 ( L_28 ) ;
if ( F_124 ( V_164 ) ) {
V_58 = F_125 ( V_164 ) ;
goto V_196;
}
V_58 = F_126 ( & V_141 ) ;
if ( V_58 < 0 ) {
goto V_197;
}
F_127 ( & V_194 ) ;
V_193 -> V_198 . V_199 = V_200 ;
V_58 = F_128 ( & V_194 ) ;
if ( V_58 )
goto V_201;
return 0 ;
V_201:
F_129 ( & V_141 ) ;
V_197:
F_130 ( V_164 ) ;
V_196:
F_131 ( V_8 ) ;
return V_58 ;
}
static void T_11 F_132 ( void )
{
F_133 ( & V_194 ) ;
F_129 ( & V_141 ) ;
F_130 ( V_164 ) ;
F_131 ( V_8 ) ;
}
