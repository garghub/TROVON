static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! V_7 -> V_8 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) )
F_5 ( V_2 , 0 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( V_2 , V_4 ) ;
V_6 = V_4 -> V_9 ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 )
F_9 ( & V_6 -> V_12 , & V_6 -> V_11 -> V_13 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_6 , 1 ) ;
}
static bool F_14 ( const struct V_5 * V_6 )
{
return V_6 -> V_15 -> V_16 . V_17 == V_18 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_15 ;
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_22 * V_23 = V_20 -> V_24 ;
unsigned int V_25 = V_6 -> V_26 -> V_27 - V_20 -> V_16 . V_28 ;
struct V_29 * V_30 = V_23 -> V_31 + V_25 ;
if ( V_30 -> V_32 == 0 )
return;
if ( V_2 -> V_33 . V_34 )
F_16 ( V_2 , V_23 -> V_35 , V_6 -> V_26 , V_30 , 1 , NULL ) ;
memcpy ( V_30 -> V_32 + V_30 -> V_36 ,
V_6 -> V_26 -> V_37 + V_30 -> V_36 , V_30 -> V_38 ) ;
F_17 ( V_39 , & V_30 -> V_40 ) ;
V_23 -> V_41 = V_23 -> V_42 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_2 ( ! F_6 ( V_4 ) ) ;
F_2 ( ! F_19 ( V_4 ) ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 ) ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 ) {
F_23 ( & V_6 -> V_12 ) ;
F_24 ( V_4 ) ;
} else {
struct V_19 * V_20 = V_6 -> V_15 ;
F_25 ( & V_6 -> V_45 , & V_20 -> V_46 ) ;
F_12 ( & V_20 -> V_47 ) ;
}
V_6 -> V_11 = V_44 ;
F_25 ( & V_6 -> V_12 , & V_44 -> V_48 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_17 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_13 ( V_6 , 0 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_2 -> V_14 ) ;
}
static inline struct V_51 * F_28 ( struct V_3 * V_4 )
{
return (struct V_51 * ) V_4 -> V_37 ;
}
static inline T_1 * F_29 ( struct V_3 * V_4 )
{
struct V_51 * V_52 = F_28 ( V_4 ) ;
return ( V_53 T_1 * ) ( V_52 + 1 ) ;
}
static inline T_1 * F_30 ( struct V_3 * V_4 )
{
return ( V_53 T_1 * ) ( V_4 -> V_37 + V_4 -> V_54 ) ;
}
static void F_31 ( struct V_3 * V_4 , int V_55 )
{
struct V_1 * V_2 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
F_32 ( V_4 , V_55 ) ;
if ( F_33 ( & V_2 -> V_56 ) )
F_34 ( & V_2 -> V_57 ) ;
}
static struct V_3 * F_35 ( struct V_1 * V_2 )
{
T_2 V_58 = F_36 ( V_2 , V_2 -> V_59 ) ;
struct V_3 * V_4 ;
V_4 = F_37 ( V_2 -> V_60 , V_58 ) ;
F_20 ( V_4 ) ;
memset ( V_4 -> V_37 , 0 , V_4 -> V_54 ) ;
F_38 ( V_4 ) ;
F_3 ( V_4 ) ;
F_39 ( V_2 ) ;
F_12 ( & V_2 -> V_56 ) ;
V_4 -> V_9 = V_2 ;
V_4 -> V_61 = F_31 ;
return V_4 ;
}
static void F_40 ( struct V_3 * V_4 , int V_55 )
{
struct V_3 * V_62 = V_4 -> V_9 ;
struct V_5 * V_6 = V_62 -> V_9 ;
struct V_1 * V_2 = V_6 -> V_15 -> V_21 ;
F_32 ( V_4 , V_55 ) ;
F_41 ( V_4 , V_63 ) ;
F_26 ( V_62 ) ;
F_24 ( V_62 ) ;
if ( F_33 ( & V_2 -> V_56 ) )
F_34 ( & V_2 -> V_57 ) ;
}
static struct V_3 * F_42 ( struct V_1 * V_2 ,
struct V_3 * V_64 )
{
T_2 V_58 = F_36 ( V_2 , V_2 -> V_59 ) ;
struct V_3 * V_4 ;
V_4 = F_43 ( V_63 , V_65 ) ;
F_44 ( & V_4 -> V_66 , 1 ) ;
V_4 -> V_67 = ( 1 << V_68 ) | ( 1 << V_69 ) | ( 1 << V_70 ) ;
F_45 ( V_4 , V_64 -> V_71 , F_46 ( V_64 ) ) ;
V_4 -> V_27 = V_58 ;
V_4 -> V_54 = V_2 -> V_72 . V_73 ;
V_4 -> V_74 = V_2 -> V_60 -> V_75 ;
V_4 -> V_9 = V_64 ;
V_4 -> V_61 = F_40 ;
F_39 ( V_2 ) ;
F_12 ( & V_2 -> V_56 ) ;
return V_4 ;
}
static struct V_3 * F_47 ( struct V_1 * V_2 , T_3 V_76 )
{
struct V_3 * V_4 = F_35 ( V_2 ) ;
struct V_51 * V_52 = F_28 ( V_4 ) ;
V_52 -> V_77 . V_78 = F_48 ( V_79 ) ;
V_52 -> V_77 . V_80 = F_48 ( V_81 ) ;
V_52 -> V_77 . V_82 = F_48 ( V_83 ) ;
V_52 -> V_76 = F_48 ( V_76 ) ;
V_52 -> V_84 = 0 ;
V_52 -> V_85 = 0 ;
V_52 -> V_86 = 0 ;
memset ( V_52 -> V_87 , 0 , sizeof( V_52 -> V_87 ) ) ;
return V_4 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_5 * V_6 = F_50 ( V_89 , struct V_5 , V_90 ) ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
F_20 ( V_6 -> V_26 ) ;
F_51 ( V_2 ) ;
if ( ! F_52 ( & V_6 -> V_95 ) )
goto V_96;
V_94 = V_7 -> V_8 ;
V_94 -> V_97 = 1 ;
V_94 -> V_98 ++ ;
F_25 ( & V_6 -> V_95 , & V_94 -> V_99 ) ;
if ( ! F_52 ( & V_89 -> V_100 ) )
goto V_96;
F_53 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_53 ( V_101 , & V_6 -> V_15 -> V_50 ) ;
F_54 ( V_2 , V_6 -> V_26 ) ;
F_1 ( V_2 , V_6 -> V_26 ) ;
V_92 = (struct V_91 * ) V_6 -> V_26 -> V_37 ;
V_92 -> V_102 = F_55 ( 0 ) ;
V_92 -> V_103 = F_48 ( V_2 -> V_104 -> V_105 ) ;
V_2 -> V_106 ++ ;
F_25 ( & V_89 -> V_100 , & V_2 -> V_107 ) ;
V_94 -> V_108 ++ ;
V_96:
F_56 ( V_2 ) ;
F_26 ( V_6 -> V_26 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_51 * V_52 ;
struct V_5 * V_109 = NULL , * V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
unsigned int V_113 ;
unsigned V_114 ;
T_1 * V_115 ;
V_112 = F_58 ( V_2 ) ;
F_51 ( V_2 ) ;
V_111 = V_2 -> V_106 ;
V_109 = V_110 = F_59 ( V_109 , & V_2 -> V_107 , V_90 . V_100 ) ;
while( V_111 ) {
V_113 = V_111 ;
if ( V_111 > V_112 )
V_113 = V_112 ;
F_56 ( V_2 ) ;
V_4 = F_47 ( V_2 , V_116 ) ;
F_51 ( V_2 ) ;
V_52 = F_28 ( V_4 ) ;
V_115 = F_29 ( V_4 ) ;
V_52 -> V_84 = F_48 ( V_113 + 1 ) ;
V_52 -> V_85 = F_48 ( V_113 ) ;
V_114 = 0 ;
F_60 (bd1, &sdp->sd_log_le_buf,
bd_le.le_list) {
* V_115 ++ = F_55 ( V_109 -> V_26 -> V_27 ) ;
if ( ++ V_114 >= V_113 )
break;
}
F_56 ( V_2 ) ;
F_61 ( V_117 , V_4 ) ;
F_51 ( V_2 ) ;
V_114 = 0 ;
F_60 (bd2, &sdp->sd_log_le_buf,
bd_le.le_list) {
F_11 ( V_110 -> V_26 ) ;
F_56 ( V_2 ) ;
F_20 ( V_110 -> V_26 ) ;
V_4 = F_42 ( V_2 , V_110 -> V_26 ) ;
F_61 ( V_117 , V_4 ) ;
F_51 ( V_2 ) ;
if ( ++ V_114 >= V_113 )
break;
}
F_2 ( V_111 < V_113 ) ;
V_111 -= V_113 ;
}
F_56 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_118 * V_119 = & V_2 -> V_107 ;
struct V_5 * V_6 ;
while ( ! F_52 ( V_119 ) ) {
V_6 = F_63 ( V_119 -> V_120 , struct V_5 , V_90 . V_100 ) ;
F_64 ( & V_6 -> V_90 . V_100 ) ;
V_2 -> V_106 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_65 ( V_2 , ! V_2 -> V_106 ) ;
}
static void F_66 ( struct V_121 * V_122 ,
struct V_123 * V_119 , int V_124 )
{
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
if ( V_124 != 0 )
return;
V_2 -> V_126 = 0 ;
V_2 -> V_127 = 0 ;
}
static int F_68 ( struct V_121 * V_122 , unsigned int V_128 ,
struct V_51 * V_52 , T_1 * V_115 ,
int V_124 )
{
struct V_129 * V_130 = F_69 ( V_122 -> V_125 ) ;
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
struct V_19 * V_20 = V_130 -> V_131 ;
unsigned int V_132 = F_70 ( V_52 -> V_85 ) ;
struct V_3 * V_133 , * V_134 ;
T_2 V_58 ;
int error = 0 ;
if ( V_124 != 1 || F_70 ( V_52 -> V_76 ) != V_116 )
return 0 ;
F_71 ( V_2 , & V_128 ) ;
for (; V_132 ; F_71 ( V_2 , & V_128 ) , V_132 -- ) {
V_58 = F_72 ( * V_115 ++ ) ;
V_2 -> V_126 ++ ;
if ( F_73 ( V_2 , V_58 , V_128 ) )
continue;
error = F_74 ( V_122 , V_128 , & V_133 ) ;
if ( error )
return error ;
V_134 = F_75 ( V_20 , V_58 ) ;
memcpy ( V_134 -> V_37 , V_133 -> V_37 , V_133 -> V_54 ) ;
if ( F_54 ( V_2 , V_134 ) )
error = - V_135 ;
else
F_21 ( V_134 ) ;
F_24 ( V_133 ) ;
F_24 ( V_134 ) ;
if ( error )
break;
V_2 -> V_127 ++ ;
}
return error ;
}
static void F_76 ( struct V_121 * V_122 , int error , int V_124 )
{
struct V_129 * V_130 = F_69 ( V_122 -> V_125 ) ;
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
if ( error ) {
F_77 ( V_130 -> V_131 ) ;
return;
}
if ( V_124 != 1 )
return;
F_77 ( V_130 -> V_131 ) ;
F_78 ( V_2 , L_1 ,
V_122 -> V_105 , V_2 -> V_127 , V_2 -> V_126 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_5 * V_6 = F_50 ( V_89 , struct V_5 , V_90 ) ;
struct V_19 * V_20 = V_6 -> V_15 ;
struct V_93 * V_94 ;
V_94 = V_7 -> V_8 ;
V_94 -> V_97 = 1 ;
V_94 -> V_136 ++ ;
V_2 -> V_137 ++ ;
F_12 ( & V_20 -> V_138 ) ;
F_53 ( V_49 , & V_20 -> V_50 ) ;
F_25 ( & V_89 -> V_100 , & V_2 -> V_139 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_91 * V_92 ;
struct V_3 * V_4 ;
unsigned int V_140 ;
struct V_118 * V_119 = & V_2 -> V_139 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_137 )
return;
V_4 = F_47 ( V_2 , V_141 ) ;
V_52 = F_28 ( V_4 ) ;
V_52 -> V_84 = F_48 ( F_81 ( V_2 , V_2 -> V_137 ,
sizeof( T_2 ) ) ) ;
V_52 -> V_85 = F_48 ( V_2 -> V_137 ) ;
V_140 = sizeof( struct V_51 ) ;
F_82 (bd, head, bd_le.le_list) {
V_2 -> V_137 -- ;
if ( V_140 + sizeof( T_2 ) > V_2 -> V_72 . V_73 ) {
F_61 ( V_117 , V_4 ) ;
V_4 = F_35 ( V_2 ) ;
V_92 = (struct V_91 * ) V_4 -> V_37 ;
V_92 -> V_78 = F_48 ( V_79 ) ;
V_92 -> V_80 = F_48 ( V_142 ) ;
V_92 -> V_82 = F_48 ( V_143 ) ;
V_140 = sizeof( struct V_91 ) ;
}
* ( T_1 * ) ( V_4 -> V_37 + V_140 ) = F_55 ( V_6 -> V_144 ) ;
V_140 += sizeof( T_2 ) ;
}
F_5 ( V_2 , ! V_2 -> V_137 ) ;
F_61 ( V_117 , V_4 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_118 * V_119 = & V_2 -> V_139 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_52 ( V_119 ) ) {
V_6 = F_63 ( V_119 -> V_120 , struct V_5 , V_90 . V_100 ) ;
F_64 ( & V_6 -> V_90 . V_100 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_138 ) ;
F_17 ( V_49 , & V_20 -> V_50 ) ;
F_84 ( V_145 , V_6 ) ;
}
}
static void F_85 ( struct V_121 * V_122 ,
struct V_123 * V_119 , int V_124 )
{
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
if ( V_124 != 0 )
return;
V_2 -> V_146 = 0 ;
V_2 -> V_147 = V_119 -> V_148 ;
}
static int F_86 ( struct V_121 * V_122 , unsigned int V_128 ,
struct V_51 * V_52 , T_1 * V_115 ,
int V_124 )
{
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
unsigned int V_132 = F_70 ( V_52 -> V_84 ) ;
unsigned int V_149 = F_70 ( V_52 -> V_85 ) ;
struct V_3 * V_4 ;
unsigned int V_140 ;
T_2 V_58 ;
int V_150 = 1 ;
int error ;
if ( V_124 != 0 || F_70 ( V_52 -> V_76 ) != V_141 )
return 0 ;
V_140 = sizeof( struct V_51 ) ;
for (; V_132 ; F_71 ( V_2 , & V_128 ) , V_132 -- ) {
error = F_74 ( V_122 , V_128 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_150 )
F_87 ( V_2 , V_4 , V_142 ) ;
while ( V_140 + sizeof( T_2 ) <= V_2 -> V_72 . V_73 ) {
V_58 = F_72 ( * ( T_1 * ) ( V_4 -> V_37 + V_140 ) ) ;
error = F_88 ( V_2 , V_58 , V_128 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_2 -> V_146 ++ ;
if ( ! -- V_149 )
break;
V_140 += sizeof( T_2 ) ;
}
F_24 ( V_4 ) ;
V_140 = sizeof( struct V_91 ) ;
V_150 = 0 ;
}
return 0 ;
}
static void F_89 ( struct V_121 * V_122 , int error , int V_124 )
{
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
if ( error ) {
F_90 ( V_2 ) ;
return;
}
if ( V_124 != 1 )
return;
F_78 ( V_2 , L_2 ,
V_122 -> V_105 , V_2 -> V_146 ) ;
F_90 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_5 * V_6 = F_50 ( V_89 , struct V_5 , V_90 ) ;
struct V_93 * V_94 = V_7 -> V_8 ;
struct V_151 * V_152 = V_6 -> V_26 -> V_71 -> V_152 ;
struct V_129 * V_130 = F_69 ( V_152 -> V_153 ) ;
F_20 ( V_6 -> V_26 ) ;
F_51 ( V_2 ) ;
if ( V_94 ) {
if ( ! F_52 ( & V_6 -> V_95 ) )
goto V_96;
V_94 -> V_97 = 1 ;
if ( F_92 ( V_130 ) ) {
V_94 -> V_98 ++ ;
F_25 ( & V_6 -> V_95 , & V_94 -> V_99 ) ;
}
}
if ( ! F_52 ( & V_89 -> V_100 ) )
goto V_96;
F_53 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_53 ( V_101 , & V_6 -> V_15 -> V_50 ) ;
if ( F_92 ( V_130 ) ) {
F_1 ( V_2 , V_6 -> V_26 ) ;
V_94 -> V_154 ++ ;
V_2 -> V_155 ++ ;
F_93 ( & V_89 -> V_100 , & V_2 -> V_156 ) ;
} else {
F_93 ( & V_89 -> V_100 , & V_2 -> V_157 ) ;
}
V_96:
F_56 ( V_2 ) ;
F_26 ( V_6 -> V_26 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
void * V_158 ;
T_4 * V_115 ;
F_95 ( V_4 ) ;
V_158 = F_96 ( V_4 -> V_71 ) ;
V_115 = V_158 + F_46 ( V_4 ) ;
if ( * V_115 == F_48 ( V_79 ) )
F_97 ( V_4 ) ;
F_98 ( V_158 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_118 * V_159 , struct V_118 * V_160 ,
unsigned int V_114 )
{
struct V_3 * V_161 ;
struct V_51 * V_52 ;
struct V_5 * V_6 ;
T_1 * V_115 ;
if ( ! V_4 )
return;
V_52 = F_28 ( V_4 ) ;
V_52 -> V_84 = F_48 ( V_114 + 1 ) ;
V_52 -> V_85 = F_48 ( V_114 ) ;
V_115 = F_29 ( V_4 ) ;
F_11 ( V_4 ) ;
F_61 ( V_117 , V_4 ) ;
F_51 ( V_2 ) ;
while( ! F_52 ( V_159 ) ) {
V_6 = F_63 ( V_159 -> V_120 , struct V_5 , V_90 . V_100 ) ;
F_100 ( & V_6 -> V_90 . V_100 , V_160 ) ;
F_11 ( V_6 -> V_26 ) ;
while ( F_72 ( * V_115 ) != V_6 -> V_26 -> V_27 ) {
F_39 ( V_2 ) ;
V_115 += 2 ;
}
F_56 ( V_2 ) ;
F_20 ( V_6 -> V_26 ) ;
if ( F_101 ( V_6 -> V_26 ) ) {
void * V_158 ;
V_161 = F_35 ( V_2 ) ;
V_158 = F_96 ( V_6 -> V_26 -> V_71 ) ;
memcpy ( V_161 -> V_37 , V_158 + F_46 ( V_6 -> V_26 ) ,
V_161 -> V_54 ) ;
F_98 ( V_158 ) ;
* ( T_4 * ) V_161 -> V_37 = 0 ;
F_95 ( V_6 -> V_26 ) ;
F_26 ( V_6 -> V_26 ) ;
F_24 ( V_6 -> V_26 ) ;
} else {
V_161 = F_42 ( V_2 , V_6 -> V_26 ) ;
}
F_61 ( V_117 , V_161 ) ;
F_51 ( V_2 ) ;
V_115 += 2 ;
}
F_56 ( V_2 ) ;
F_24 ( V_4 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned int V_114 = 0 ;
T_1 * V_115 = NULL , * V_162 = NULL ;
F_103 ( V_163 ) ;
F_103 ( V_164 ) ;
F_51 ( V_2 ) ;
while ( ! F_52 ( & V_2 -> V_156 ) ) {
if ( V_115 == V_162 ) {
F_56 ( V_2 ) ;
F_99 ( V_2 , V_4 , & V_164 , & V_163 , V_114 ) ;
V_114 = 0 ;
V_4 = F_47 ( V_2 , V_165 ) ;
V_115 = F_29 ( V_4 ) ;
V_162 = F_30 ( V_4 ) - 1 ;
F_51 ( V_2 ) ;
continue;
}
V_6 = F_63 ( V_2 -> V_156 . V_120 , struct V_5 , V_90 . V_100 ) ;
F_100 ( & V_6 -> V_90 . V_100 , & V_164 ) ;
F_94 ( V_6 -> V_26 ) ;
* V_115 ++ = F_55 ( V_6 -> V_26 -> V_27 ) ;
* V_115 ++ = F_55 ( F_101 ( V_4 ) ? 1 : 0 ) ;
V_114 ++ ;
}
F_56 ( V_2 ) ;
F_99 ( V_2 , V_4 , & V_164 , & V_163 , V_114 ) ;
F_51 ( V_2 ) ;
F_104 ( & V_163 , & V_2 -> V_156 ) ;
F_56 ( V_2 ) ;
}
static int F_105 ( struct V_121 * V_122 , unsigned int V_128 ,
struct V_51 * V_52 ,
T_1 * V_115 , int V_124 )
{
struct V_129 * V_130 = F_69 ( V_122 -> V_125 ) ;
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
struct V_19 * V_20 = V_130 -> V_131 ;
unsigned int V_132 = F_70 ( V_52 -> V_85 ) ;
struct V_3 * V_133 , * V_134 ;
T_2 V_58 ;
T_2 V_166 ;
int error = 0 ;
if ( V_124 != 1 || F_70 ( V_52 -> V_76 ) != V_165 )
return 0 ;
F_71 ( V_2 , & V_128 ) ;
for (; V_132 ; F_71 ( V_2 , & V_128 ) , V_132 -- ) {
V_58 = F_72 ( * V_115 ++ ) ;
V_166 = F_72 ( * V_115 ++ ) ;
V_2 -> V_126 ++ ;
if ( F_73 ( V_2 , V_58 , V_128 ) )
continue;
error = F_74 ( V_122 , V_128 , & V_133 ) ;
if ( error )
return error ;
V_134 = F_75 ( V_20 , V_58 ) ;
memcpy ( V_134 -> V_37 , V_133 -> V_37 , V_133 -> V_54 ) ;
if ( V_166 ) {
T_4 * V_167 = ( T_4 * ) V_134 -> V_37 ;
* V_167 = F_48 ( V_79 ) ;
}
F_21 ( V_134 ) ;
F_24 ( V_133 ) ;
F_24 ( V_134 ) ;
V_2 -> V_127 ++ ;
}
return error ;
}
static void F_106 ( struct V_121 * V_122 , int error , int V_124 )
{
struct V_129 * V_130 = F_69 ( V_122 -> V_125 ) ;
struct V_1 * V_2 = F_67 ( V_122 -> V_125 ) ;
if ( error ) {
F_77 ( V_130 -> V_131 ) ;
return;
}
if ( V_124 != 1 )
return;
F_77 ( V_130 -> V_131 ) ;
F_78 ( V_2 , L_3 ,
V_122 -> V_105 , V_2 -> V_127 , V_2 -> V_126 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_118 * V_119 = & V_2 -> V_156 ;
struct V_5 * V_6 ;
while ( ! F_52 ( V_119 ) ) {
V_6 = F_63 ( V_119 -> V_120 , struct V_5 , V_90 . V_100 ) ;
F_64 ( & V_6 -> V_90 . V_100 ) ;
V_2 -> V_155 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_65 ( V_2 , ! V_2 -> V_155 ) ;
}
