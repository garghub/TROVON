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
F_31 ( & V_42 -> V_65 , V_66 ) ;
F_32 ( & V_42 -> V_65 , V_63 ) ;
F_33 ( V_29 -> V_32 , V_63 , V_6 -> V_34 ) ;
V_32 = V_29 -> V_32 % V_6 -> V_34 ;
F_25 ( V_32 != 0 ) ;
}
V_42 = ( void * ) V_29 + V_64 + V_32 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
F_31 ( & V_42 -> V_65 , V_67 ) ;
F_32 ( & V_42 -> V_65 , V_40 ) ;
V_42 -> V_7 = V_1 -> V_7 ;
V_47 = & V_42 -> V_53 . V_47 [ 0 ] ;
F_34 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, i) {
T_1 V_68 = F_35 ( ( T_1 ) V_45 -> V_69 ,
F_17 ( V_6 -> V_36 , V_6 -> V_38 ) ) ;
void * V_70 = F_36 ( F_37 ( V_45 ) ) + V_45 -> V_20 ;
void * V_71 = ( void * ) V_29 + V_6 -> V_72 + V_6 -> V_36 ;
if ( V_1 -> V_2 -> V_73 == V_74 ) {
memcpy ( V_71 , V_70 , V_68 ) ;
F_11 ( V_71 , V_68 ) ;
}
V_47 -> V_75 = V_68 ;
V_47 -> V_76 = ( void * ) V_6 -> V_72 + V_6 -> V_36 ;
V_48 ++ ;
V_47 ++ ;
F_33 ( V_6 -> V_36 , V_68 , V_6 -> V_38 ) ;
if ( V_45 -> V_69 != V_68 ) {
V_70 += V_68 ;
V_68 = V_45 -> V_69 - V_68 ;
V_47 -> V_75 = V_68 ;
V_47 -> V_76 = ( void * ) V_6 -> V_72 + V_6 -> V_36 ;
if ( V_2 -> V_73 == V_74 ) {
V_71 = ( void * ) V_29 + V_6 -> V_72 + V_6 -> V_36 ;
memcpy ( V_71 , V_70 , V_68 ) ;
F_11 ( V_71 , V_68 ) ;
}
V_48 ++ ;
V_47 ++ ;
F_33 ( V_6 -> V_36 , V_68 , V_6 -> V_38 ) ;
}
F_38 ( V_70 ) ;
}
V_42 -> V_53 . V_48 = V_48 ;
V_49 = V_64 + V_32 + V_39 ;
memcpy ( ( void * ) V_29 + V_49 , V_2 -> V_55 , F_24 ( V_2 -> V_55 ) ) ;
V_42 -> V_53 . V_49 = V_49 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
F_33 ( V_29 -> V_32 , V_40 , V_6 -> V_34 ) ;
F_11 ( V_29 , sizeof( * V_29 ) ) ;
F_8 ( & V_6 -> V_57 ) ;
F_39 ( & V_6 -> V_77 ) ;
F_40 ( & V_6 -> V_78 ,
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
return - V_79 ;
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
static void F_45 ( struct V_1 * V_80 , struct V_41 * V_42 )
{
struct V_2 * V_2 = V_80 -> V_2 ;
struct V_5 * V_6 = V_80 -> V_5 ;
if ( F_21 ( V_81 , & V_80 -> V_51 ) ) {
F_33 ( V_6 -> V_37 , V_80 -> V_10 , V_6 -> V_38 ) ;
return;
}
if ( V_42 -> V_82 . V_83 == V_84 ) {
memcpy ( V_2 -> V_85 , V_42 -> V_82 . V_85 ,
V_2 -> V_86 ) ;
F_33 ( V_6 -> V_37 , V_80 -> V_10 , V_6 -> V_38 ) ;
}
else if ( V_2 -> V_73 == V_87 ) {
struct V_44 * V_45 ;
int V_43 ;
F_34 (se_cmd->t_data_sg, sg, se_cmd->t_data_nents, i) {
T_1 V_68 ;
void * V_71 ;
void * V_70 ;
V_68 = F_35 ( ( T_1 ) V_45 -> V_69 ,
F_17 ( V_6 -> V_37 , V_6 -> V_38 ) ) ;
V_71 = F_36 ( F_37 ( V_45 ) ) + V_45 -> V_20 ;
F_25 ( V_45 -> V_69 + V_45 -> V_20 > V_22 ) ;
V_70 = ( void * ) V_6 -> V_30 + V_6 -> V_72 + V_6 -> V_37 ;
F_11 ( V_70 , V_68 ) ;
memcpy ( V_71 , V_70 , V_68 ) ;
F_33 ( V_6 -> V_37 , V_68 , V_6 -> V_38 ) ;
if ( V_45 -> V_69 != V_68 ) {
V_70 = ( void * ) V_6 -> V_30 + V_6 -> V_72 + V_6 -> V_37 ;
F_25 ( V_6 -> V_37 ) ;
V_71 += V_68 ;
V_68 = V_45 -> V_69 - V_68 ;
F_11 ( V_70 , V_68 ) ;
memcpy ( V_71 , V_70 , V_68 ) ;
F_33 ( V_6 -> V_37 , V_68 , V_6 -> V_38 ) ;
}
F_38 ( V_71 ) ;
}
} else if ( V_2 -> V_73 == V_74 ) {
F_33 ( V_6 -> V_37 , V_80 -> V_10 , V_6 -> V_38 ) ;
} else {
F_26 ( L_8 , V_2 -> V_73 ) ;
}
F_46 ( V_80 -> V_2 , V_42 -> V_82 . V_83 ) ;
V_80 -> V_2 = NULL ;
F_10 ( V_8 , V_80 ) ;
}
static unsigned int F_47 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
F_48 ( V_88 ) ;
unsigned long V_51 ;
int V_89 = 0 ;
if ( F_21 ( V_50 , & V_6 -> V_51 ) ) {
F_43 ( L_9 ) ;
return 0 ;
}
F_49 ( & V_6 -> V_57 , V_51 ) ;
V_29 = V_6 -> V_30 ;
F_11 ( V_29 , sizeof( * V_29 ) ) ;
while ( V_6 -> V_35 != F_50 ( V_29 -> V_90 ) ) {
struct V_41 * V_42 = ( void * ) V_29 + V_64 + V_6 -> V_35 ;
struct V_1 * V_80 ;
F_11 ( V_42 , sizeof( * V_42 ) ) ;
if ( F_51 ( & V_42 -> V_65 ) == V_66 ) {
F_33 ( V_6 -> V_35 , F_52 ( & V_42 -> V_65 ) , V_6 -> V_34 ) ;
continue;
}
F_25 ( F_51 ( & V_42 -> V_65 ) != V_67 ) ;
F_53 ( & V_6 -> V_14 ) ;
V_80 = F_54 ( & V_6 -> V_15 , V_42 -> V_7 ) ;
if ( V_80 )
F_44 ( & V_6 -> V_15 , V_80 -> V_7 ) ;
F_55 ( & V_6 -> V_14 ) ;
if ( ! V_80 ) {
F_43 ( L_10 ) ;
F_56 ( V_50 , & V_6 -> V_51 ) ;
break;
}
F_45 ( V_80 , V_42 ) ;
F_33 ( V_6 -> V_35 , F_52 ( & V_42 -> V_65 ) , V_6 -> V_34 ) ;
V_89 ++ ;
}
if ( V_29 -> V_90 == V_29 -> V_32 )
F_57 ( & V_6 -> V_78 ) ;
F_58 ( & V_6 -> V_57 , V_51 ) ;
F_59 ( & V_6 -> V_60 ) ;
return V_89 ;
}
static int F_60 ( int V_91 , void * V_92 , void * V_93 )
{
struct V_1 * V_80 = V_92 ;
if ( F_21 ( V_81 , & V_80 -> V_51 ) )
return 0 ;
if ( ! F_61 ( V_80 -> V_11 , V_12 ) )
return 0 ;
F_56 ( V_81 , & V_80 -> V_51 ) ;
F_46 ( V_80 -> V_2 , V_84 ) ;
V_80 -> V_2 = NULL ;
F_10 ( V_8 , V_80 ) ;
return 0 ;
}
static void F_62 ( unsigned long V_93 )
{
struct V_5 * V_6 = (struct V_5 * ) V_93 ;
unsigned long V_51 ;
int V_89 ;
V_89 = F_47 ( V_6 ) ;
F_26 ( L_11 , V_89 ) ;
F_49 ( & V_6 -> V_14 , V_51 ) ;
F_63 ( & V_6 -> V_15 , F_60 , NULL ) ;
F_58 ( & V_6 -> V_14 , V_51 ) ;
}
static int F_64 ( struct V_94 * V_95 , T_2 V_96 )
{
struct V_97 * V_97 ;
V_97 = F_65 ( sizeof( struct V_97 ) , V_9 ) ;
if ( ! V_97 )
return - V_79 ;
V_97 -> V_96 = V_96 ;
V_95 -> V_98 = V_97 ;
return 0 ;
}
static void F_66 ( struct V_94 * V_95 )
{
F_67 ( V_95 -> V_98 ) ;
V_95 -> V_98 = NULL ;
}
static struct V_3 * F_68 ( struct V_94 * V_95 , const char * V_99 )
{
struct V_5 * V_6 ;
V_6 = F_65 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_99 = F_69 ( V_99 , V_9 ) ;
if ( ! V_6 -> V_99 ) {
F_67 ( V_6 ) ;
return NULL ;
}
V_6 -> V_95 = V_95 ;
F_70 ( & V_6 -> V_60 ) ;
F_71 ( & V_6 -> V_57 ) ;
F_72 ( & V_6 -> V_15 ) ;
F_71 ( & V_6 -> V_14 ) ;
F_73 ( & V_6 -> V_78 , F_62 ,
( unsigned long ) V_6 ) ;
V_6 -> V_100 = V_101 ;
return & V_6 -> V_4 ;
}
static int F_74 ( struct V_77 * V_102 , T_5 V_103 )
{
struct V_5 * V_5 = F_75 ( V_102 , struct V_5 , V_77 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_104 * V_105 )
{
struct V_5 * V_6 = V_105 -> V_106 ;
struct V_77 * V_102 = & V_6 -> V_77 ;
if ( V_105 -> V_107 < V_108 ) {
if ( V_102 -> V_109 [ V_105 -> V_107 ] . V_19 == 0 )
return - 1 ;
return ( int ) V_105 -> V_107 ;
}
return - 1 ;
}
static int F_77 ( struct V_104 * V_105 , struct V_110 * V_111 )
{
struct V_5 * V_6 = V_105 -> V_106 ;
struct V_77 * V_102 = & V_6 -> V_77 ;
struct V_112 * V_112 ;
unsigned long V_20 ;
void * V_113 ;
int V_114 = F_76 ( V_105 ) ;
if ( V_114 < 0 )
return V_115 ;
V_20 = ( V_111 -> V_116 - V_114 ) << V_117 ;
V_113 = ( void * ) ( unsigned long ) V_102 -> V_109 [ V_114 ] . V_113 + V_20 ;
if ( V_102 -> V_109 [ V_114 ] . V_118 == V_119 )
V_112 = F_14 ( V_113 ) ;
else
V_112 = F_78 ( V_113 ) ;
F_79 ( V_112 ) ;
V_111 -> V_112 = V_112 ;
return 0 ;
}
static int F_80 ( struct V_77 * V_102 , struct V_104 * V_105 )
{
struct V_5 * V_6 = F_75 ( V_102 , struct V_5 , V_77 ) ;
V_105 -> V_120 |= V_121 | V_122 ;
V_105 -> V_123 = & V_124 ;
V_105 -> V_106 = V_6 ;
if ( F_81 ( V_105 ) != ( V_125 >> V_117 ) )
return - V_52 ;
return 0 ;
}
static int F_82 ( struct V_77 * V_102 , struct V_126 * V_126 )
{
struct V_5 * V_6 = F_75 ( V_102 , struct V_5 , V_77 ) ;
if ( F_83 ( V_127 , & V_6 -> V_51 ) )
return - V_128 ;
F_19 ( L_12 ) ;
return 0 ;
}
static int F_84 ( struct V_77 * V_102 , struct V_126 * V_126 )
{
struct V_5 * V_6 = F_75 ( V_102 , struct V_5 , V_77 ) ;
F_85 ( V_127 , & V_6 -> V_51 ) ;
F_19 ( L_13 ) ;
return 0 ;
}
static int F_86 ( enum V_129 V_80 , const char * V_99 , int V_130 )
{
struct V_131 * V_132 ;
void * V_133 ;
int V_58 = - V_79 ;
V_132 = F_87 ( V_134 , V_9 ) ;
if ( ! V_132 )
return V_58 ;
V_133 = F_88 ( V_132 , 0 , 0 , & V_135 , 0 , V_80 ) ;
if ( ! V_133 )
goto V_136;
V_58 = F_89 ( V_132 , V_137 , V_99 ) ;
if ( V_58 < 0 )
goto V_136;
V_58 = F_90 ( V_132 , V_138 , V_130 ) ;
if ( V_58 < 0 )
goto V_136;
V_58 = F_91 ( V_132 , V_133 ) ;
if ( V_58 < 0 )
goto V_136;
V_58 = F_92 ( & V_135 , V_132 , 0 ,
V_139 , V_9 ) ;
if ( V_58 == - V_140 )
V_58 = 0 ;
return V_58 ;
V_136:
F_93 ( V_132 ) ;
return V_58 ;
}
static int F_94 ( struct V_3 * V_141 )
{
struct V_5 * V_6 = F_2 ( V_141 ) ;
struct V_97 * V_95 = V_6 -> V_95 -> V_98 ;
struct V_77 * V_102 ;
struct V_28 * V_29 ;
T_1 V_19 ;
T_1 V_142 ;
int V_58 = 0 ;
char * V_143 ;
V_102 = & V_6 -> V_77 ;
V_19 = snprintf ( NULL , 0 , L_14 , V_95 -> V_96 , V_6 -> V_99 ,
V_6 -> V_144 ) ;
V_19 += 1 ;
V_143 = F_95 ( V_19 , V_9 ) ;
if ( ! V_143 )
return - V_79 ;
V_142 = snprintf ( V_143 , V_19 , L_15 , V_95 -> V_96 , V_6 -> V_99 ) ;
if ( V_6 -> V_144 [ 0 ] )
snprintf ( V_143 + V_142 , V_19 - V_142 , L_16 , V_6 -> V_144 ) ;
V_102 -> V_99 = V_143 ;
V_6 -> V_30 = F_96 ( V_125 ) ;
if ( ! V_6 -> V_30 ) {
V_58 = - V_79 ;
goto V_145;
}
V_6 -> V_34 = V_146 - V_64 ;
V_6 -> V_72 = V_146 ;
V_6 -> V_38 = V_125 - V_146 ;
V_29 = V_6 -> V_30 ;
V_29 -> V_147 = 1 ;
V_29 -> V_148 = V_64 ;
V_29 -> V_34 = V_6 -> V_34 ;
F_25 ( ! F_97 ( V_6 -> V_72 ) ) ;
F_25 ( V_6 -> V_38 % V_22 ) ;
V_102 -> V_147 = L_17 ;
V_102 -> V_109 [ 0 ] . V_99 = L_18 ;
V_102 -> V_109 [ 0 ] . V_113 = ( V_149 ) V_6 -> V_30 ;
V_102 -> V_109 [ 0 ] . V_19 = V_125 ;
V_102 -> V_109 [ 0 ] . V_118 = V_150 ;
V_102 -> V_151 = F_74 ;
V_102 -> V_152 = V_153 ;
V_102 -> V_154 = F_80 ;
V_102 -> V_155 = F_82 ;
V_102 -> V_156 = F_84 ;
V_58 = F_98 ( V_157 , V_102 ) ;
if ( V_58 )
goto V_158;
V_141 -> V_159 . V_160 = 512 ;
V_141 -> V_159 . V_161 = 128 ;
V_141 -> V_159 . V_162 = 128 ;
V_58 = F_86 ( V_163 , V_6 -> V_77 . V_99 ,
V_6 -> V_77 . V_164 -> V_130 ) ;
if ( V_58 )
goto V_165;
return 0 ;
V_165:
F_99 ( & V_6 -> V_77 ) ;
V_158:
F_100 ( V_6 -> V_30 ) ;
V_145:
F_67 ( V_102 -> V_99 ) ;
return V_58 ;
}
static int F_101 ( int V_91 , void * V_92 , void * V_93 )
{
struct V_1 * V_80 = V_92 ;
if ( F_21 ( V_81 , & V_80 -> V_51 ) )
return 0 ;
return - V_52 ;
}
static void F_102 ( struct V_3 * V_141 )
{
struct V_5 * V_6 = F_2 ( V_141 ) ;
int V_43 ;
F_103 ( & V_6 -> V_78 ) ;
F_100 ( V_6 -> V_30 ) ;
F_6 ( & V_6 -> V_14 ) ;
V_43 = F_63 ( & V_6 -> V_15 , F_101 , NULL ) ;
F_104 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_25 ( V_43 ) ;
if ( V_6 -> V_77 . V_164 ) {
F_86 ( V_166 , V_6 -> V_77 . V_99 ,
V_6 -> V_77 . V_164 -> V_130 ) ;
F_99 ( & V_6 -> V_77 ) ;
F_67 ( V_6 -> V_77 . V_99 ) ;
F_67 ( V_6 -> V_99 ) ;
}
F_67 ( V_6 ) ;
}
static T_6 F_105 ( struct V_3 * V_141 ,
const char * V_112 , T_6 V_167 )
{
struct V_5 * V_6 = F_2 ( V_141 ) ;
char * V_168 , * V_169 , * V_170 , * V_171 ;
T_7 args [ V_172 ] ;
int V_58 = 0 , V_173 ;
int V_174 ;
V_170 = F_69 ( V_112 , V_9 ) ;
if ( ! V_170 )
return - V_79 ;
V_168 = V_170 ;
while ( ( V_169 = F_106 ( & V_170 , L_19 ) ) != NULL ) {
if ( ! * V_169 )
continue;
V_173 = F_107 ( V_169 , V_175 , args ) ;
switch ( V_173 ) {
case V_176 :
if ( F_108 ( V_6 -> V_144 , & args [ 0 ] ,
V_177 ) == 0 ) {
V_58 = - V_52 ;
break;
}
F_19 ( L_20 , V_6 -> V_144 ) ;
break;
case V_178 :
V_171 = F_109 ( & args [ 0 ] ) ;
if ( ! V_171 ) {
V_58 = - V_79 ;
break;
}
V_58 = F_110 ( V_171 , 0 , ( unsigned long * ) & V_6 -> V_179 ) ;
F_67 ( V_171 ) ;
if ( V_58 < 0 )
F_43 ( L_21 ) ;
break;
case V_180 :
F_111 ( args , & V_174 ) ;
if ( V_174 >= V_181 ) {
F_26 ( L_22 , V_174 ) ;
break;
}
F_19 ( L_23 , V_174 ) ;
V_6 -> V_100 = V_174 ;
break;
default:
break;
}
}
F_67 ( V_168 ) ;
return ( ! V_58 ) ? V_167 : V_58 ;
}
static T_6 F_112 ( struct V_3 * V_141 , char * V_182 )
{
struct V_5 * V_6 = F_2 ( V_141 ) ;
T_6 V_183 = 0 ;
V_183 = sprintf ( V_182 + V_183 , L_24 ,
V_6 -> V_144 [ 0 ] ? V_6 -> V_144 : L_25 ) ;
V_183 += sprintf ( V_182 + V_183 , L_26 ,
V_6 -> V_179 , V_6 -> V_100 ) ;
return V_183 ;
}
static T_8 F_113 ( struct V_3 * V_141 )
{
struct V_5 * V_6 = F_2 ( V_141 ) ;
return F_114 ( V_6 -> V_179 - V_141 -> V_159 . V_184 ,
V_141 -> V_159 . V_184 ) ;
}
static T_9
F_115 ( struct V_2 * V_2 , struct V_44 * V_185 , T_2 V_186 ,
enum V_187 V_73 )
{
int V_58 ;
V_58 = F_42 ( V_2 ) ;
if ( V_58 != 0 )
return V_188 ;
else
return V_189 ;
}
static T_9
F_116 ( struct V_2 * V_2 )
{
int V_58 = F_42 ( V_2 ) ;
if ( V_58 != 0 )
return V_188 ;
else
return V_189 ;
}
static T_9
F_117 ( struct V_2 * V_80 )
{
unsigned char * V_190 = V_80 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_80 -> V_4 ) ;
T_9 V_58 ;
switch ( V_6 -> V_100 ) {
case V_101 :
switch ( V_190 [ 0 ] ) {
case V_191 :
V_80 -> V_192 = V_193 ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
V_80 -> V_203 |= V_204 ;
default:
V_80 -> V_192 = F_116 ;
}
V_58 = V_189 ;
break;
case V_205 :
V_58 = F_118 ( V_80 , & V_206 ) ;
break;
default:
F_43 ( L_27 , V_6 -> V_100 ) ;
V_58 = V_207 ;
}
return V_58 ;
}
static int T_10 F_119 ( void )
{
int V_58 ;
F_120 ( ( sizeof( struct V_41 ) % V_56 ) != 0 ) ;
V_8 = F_121 ( L_28 ,
sizeof( struct V_1 ) ,
F_122 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_79 ;
V_157 = F_123 ( L_29 ) ;
if ( F_124 ( V_157 ) ) {
V_58 = F_125 ( V_157 ) ;
goto V_208;
}
V_58 = F_126 ( & V_135 ) ;
if ( V_58 < 0 ) {
goto V_209;
}
V_58 = F_127 ( & V_210 ) ;
if ( V_58 )
goto V_211;
return 0 ;
V_211:
F_128 ( & V_135 ) ;
V_209:
F_129 ( V_157 ) ;
V_208:
F_130 ( V_8 ) ;
return V_58 ;
}
static void T_11 F_131 ( void )
{
F_132 ( & V_210 ) ;
F_128 ( & V_135 ) ;
F_129 ( V_157 ) ;
F_130 ( V_8 ) ;
}
