T_1 void F_1 ( struct V_1 * V_2 ,
int V_3 ,
unsigned int V_4 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_4 ;
}
T_1 struct V_1 * F_2 ( int V_6 , int V_3 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_9 = F_3 ( V_6 , V_7 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_3 , V_9 -> V_11 ) ;
return V_2 ;
V_10:
return NULL ;
}
int F_5 ( const struct V_1 * V_2 )
{
return V_12 == ( V_2 -> V_3 & V_12 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_8 * V_9 ;
F_7 ( (struct V_13 * ) V_14 ) ;
V_9 = F_8 ( V_2 ) ;
V_2 -> V_14 = (struct V_13 * ) V_14 ;
F_9 ( V_2 -> V_5 , & V_2 -> V_14 -> V_15 ) ;
F_10 ( V_9 , V_14 -> V_16 . V_17 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_12 ( V_2 -> V_5 , & V_14 -> V_15 ) ;
F_13 ( V_14 ) ;
}
struct V_1 * F_14 (
const struct V_13 * V_14 ,
T_3 V_18 , T_3 V_19 , T_3 error , T_3 V_20 ,
T_3 V_21 , struct V_22 * V_23 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
struct V_8 * V_9 ;
if ( V_23 ) {
V_9 = F_15 ( V_23 -> V_9 ,
sizeof( struct V_24 ) , 0 , V_7 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_25 = (struct V_24 * )
F_16 ( V_9 , sizeof( struct V_24 ) ) ;
F_17 ( V_9 , sizeof( struct V_24 ) +
F_18 ( V_23 -> V_26 -> V_27 ) -
sizeof( V_28 ) ) ;
} else {
V_2 = F_2 ( sizeof( struct V_24 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_25 = (struct V_24 * ) F_19 ( V_9 ,
sizeof( struct V_24 ) ) ;
}
V_25 -> V_29 = V_30 ;
V_25 -> V_31 = V_19 ;
V_25 -> V_32 = 0 ;
V_25 -> V_33 = V_9 -> V_4 ;
V_25 -> V_34 = error ;
V_25 -> V_35 = V_20 ;
V_25 -> V_36 = V_21 ;
F_6 ( V_2 , V_14 ) ;
V_25 -> V_37 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_21 (
const struct V_13 * V_14 ,
const struct V_38 * V_39 ,
int V_18 , int V_19 , int error , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_40 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_41 = (struct V_40 * )
F_19 ( V_9 , sizeof( struct V_40 ) ) ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = sizeof( struct V_40 ) ;
V_41 -> V_45 = 0 ;
V_41 -> V_46 = V_19 ;
V_41 -> V_47 = error ;
F_6 ( V_2 , V_14 ) ;
V_41 -> V_48 = F_20 ( V_14 ) ;
memcpy ( & V_41 -> V_49 , V_39 , sizeof( struct V_38 ) ) ;
F_22 ( V_14 -> V_16 . V_17 -> V_50 ) -> F_23 (
F_24 ( V_14 -> V_16 . V_17 ) ,
(union V_51 * ) & V_41 -> V_49 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_25 (
const struct V_13 * V_14 , struct V_22 * V_23 ,
T_3 V_18 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
struct V_8 * V_9 ;
T_4 * V_54 ;
T_5 V_55 ;
int V_56 ;
V_54 = ( T_4 * ) ( V_23 -> V_9 -> V_57 ) ;
V_55 = V_54 -> V_55 ;
V_56 = F_26 ( F_18 ( V_54 -> V_27 ) ) - sizeof( T_4 ) ;
F_27 ( V_23 -> V_9 , sizeof( T_4 ) ) ;
V_9 = F_15 ( V_23 -> V_9 , sizeof( struct V_52 ) ,
0 , V_7 ) ;
F_27 ( V_23 -> V_9 , V_56 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_53 = (struct V_52 * )
F_16 ( V_9 , sizeof( struct V_52 ) ) ;
F_17 ( V_9 , sizeof( struct V_52 ) + V_56 ) ;
V_53 -> V_58 = V_59 ;
V_53 -> V_60 = 0 ;
V_53 -> V_61 = V_9 -> V_4 ;
V_53 -> V_62 = V_55 ;
F_6 ( V_2 , V_14 ) ;
V_53 -> V_63 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_28 (
const struct V_13 * V_14 , struct V_22 * V_23 ,
T_3 V_18 , T_6 error , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
struct V_8 * V_9 ;
int V_4 = F_18 ( V_23 -> V_26 -> V_27 ) ;
V_9 = F_15 ( V_23 -> V_9 ,
sizeof( struct V_64 ) ,
0 ,
V_7 ) ;
if ( ! V_9 )
goto V_10;
F_27 ( V_9 , sizeof( struct V_66 ) ) ;
V_4 -= sizeof( struct V_66 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_65 = (struct V_64 * )
F_16 ( V_9 , sizeof( struct V_64 ) ) ;
V_65 -> V_67 = V_68 ;
V_65 -> V_69 = V_18 ;
V_65 -> V_70 = sizeof( struct V_64 ) + V_4 ;
F_17 ( V_9 , V_65 -> V_70 ) ;
V_65 -> V_71 = error ;
memcpy ( & V_65 -> V_72 , & V_23 -> V_73 , sizeof( struct V_74 ) ) ;
V_65 -> V_72 . V_75 = V_23 -> V_26 -> V_18 ;
F_6 ( V_2 , V_14 ) ;
V_65 -> V_76 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_29 (
const struct V_13 * V_14 ,
T_3 V_18 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_77 * V_78 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_77 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_78 = (struct V_77 * )
F_19 ( V_9 , sizeof( struct V_77 ) ) ;
V_78 -> V_79 = V_80 ;
V_78 -> V_81 = 0 ;
V_78 -> V_82 = sizeof( struct V_77 ) ;
F_6 ( V_2 , V_14 ) ;
V_78 -> V_83 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_30 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_84 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_85 = (struct V_84 * )
F_19 ( V_9 , sizeof( struct V_84 ) ) ;
V_85 -> V_86 = V_87 ;
V_85 -> V_88 = 0 ;
V_85 -> V_89 = sizeof( struct V_84 ) ;
V_85 -> V_90 = V_14 -> V_91 . V_92 ;
F_6 ( V_2 , V_14 ) ;
V_85 -> V_93 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_31 ( struct V_13 * V_14 ,
struct V_22 * V_23 ,
T_2 V_7 )
{
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 ;
T_7 V_94 , V_4 ;
int V_95 ;
if ( V_14 -> V_96 -> V_97 )
V_95 = F_32 ( & V_14 -> V_15 ) ;
else
V_95 = F_32 ( & V_14 -> V_16 . V_17 -> V_98 ) ;
if ( V_95 >= V_14 -> V_16 . V_17 -> V_99 ) {
if ( ( V_14 -> V_16 . V_17 -> V_100 & V_101 ) ||
( ! F_33 ( V_14 -> V_16 . V_17 , V_23 -> V_9 -> V_11 ) ) )
goto V_10;
}
V_9 = F_34 ( V_23 -> V_9 , V_7 ) ;
if ( ! V_9 )
goto V_10;
if ( F_35 ( & V_14 -> V_91 . V_102 ,
F_36 ( V_23 -> V_103 . V_104 -> V_105 ) ,
V_23 -> V_106 ) )
goto V_107;
V_4 = F_18 ( V_23 -> V_26 -> V_27 ) ;
V_94 = F_26 ( V_4 ) - V_4 ;
F_17 ( V_9 , V_23 -> V_108 - V_94 - V_9 -> V_57 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , 0 , V_9 -> V_4 + sizeof( struct V_8 ) ) ;
F_37 ( V_2 , V_14 ) ;
V_2 -> V_109 = F_18 ( V_23 -> V_103 . V_104 -> V_109 ) ;
V_2 -> V_110 = F_18 ( V_23 -> V_103 . V_104 -> V_110 ) ;
V_2 -> V_111 = V_23 -> V_103 . V_104 -> V_111 ;
if ( V_23 -> V_26 -> V_18 & V_112 ) {
V_2 -> V_18 |= V_113 ;
V_2 -> V_114 = F_38 ( & V_14 -> V_91 . V_102 ) ;
}
V_2 -> V_105 = F_36 ( V_23 -> V_103 . V_104 -> V_105 ) ;
V_2 -> V_3 |= V_23 -> V_26 -> V_18 ;
V_2 -> V_115 = F_39 ( V_23 ) ;
return V_2 ;
V_107:
F_40 ( V_9 ) ;
V_10:
return NULL ;
}
struct V_1 * F_41 (
const struct V_13 * V_14 , T_6 V_116 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_117 * V_118 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_117 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_118 = (struct V_117 * )
F_19 ( V_9 , sizeof( struct V_117 ) ) ;
V_118 -> V_119 = V_120 ;
V_118 -> V_121 = 0 ;
V_118 -> V_122 = sizeof( struct V_117 ) ;
V_118 -> V_123 = V_116 ;
F_6 ( V_2 , V_14 ) ;
V_118 -> V_124 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_42 (
const struct V_13 * V_14 , T_3 V_125 ,
T_6 V_116 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_126 * V_127 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_126 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_127 = (struct V_126 * )
F_19 ( V_9 , sizeof( struct V_126 ) ) ;
V_127 -> V_128 = V_129 ;
V_127 -> V_130 = 0 ;
V_127 -> V_131 = sizeof( struct V_126 ) ;
V_127 -> V_132 = V_125 ;
V_127 -> V_133 = 0 ;
V_127 -> V_134 = V_116 ;
F_6 ( V_2 , V_14 ) ;
V_127 -> V_135 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_43 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_136 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_137 = (struct V_136 * )
F_19 ( V_9 , sizeof( struct V_136 ) ) ;
V_137 -> V_138 = V_139 ;
V_137 -> V_140 = 0 ;
V_137 -> V_141 = sizeof( struct V_136 ) ;
F_6 ( V_2 , V_14 ) ;
V_137 -> V_142 = F_20 ( V_14 ) ;
return V_2 ;
}
T_3 F_44 ( const struct V_1 * V_2 )
{
union V_143 * V_144 ;
struct V_8 * V_9 ;
V_9 = F_8 ( V_2 ) ;
V_144 = (union V_143 * ) V_9 -> V_57 ;
return V_144 -> V_145 . V_146 ;
}
void F_45 ( const struct V_1 * V_2 ,
struct V_147 * V_147 )
{
struct V_74 V_73 ;
if ( F_5 ( V_2 ) )
return;
V_73 . V_148 = V_2 -> V_109 ;
V_73 . V_149 = V_2 -> V_110 ;
V_73 . V_150 = V_2 -> V_111 ;
V_73 . V_75 = V_2 -> V_18 ;
V_73 . V_151 = V_2 -> V_105 ;
V_73 . V_152 = V_2 -> V_114 ;
V_73 . V_153 = F_20 ( V_2 -> V_14 ) ;
V_73 . V_154 = V_2 -> V_14 -> V_155 ;
V_73 . V_156 = 0 ;
F_46 ( V_147 , V_157 , V_158 ,
sizeof( struct V_74 ) , ( void * ) & V_73 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 , * V_159 ;
V_9 = F_8 ( V_2 ) ;
F_6 ( V_2 , V_14 ) ;
F_47 ( V_14 , F_48 ( V_9 ) ) ;
if ( ! V_9 -> V_160 )
return;
F_49 (skb, frag)
F_37 ( F_4 ( V_159 ) , V_14 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_159 ;
unsigned int V_4 ;
V_9 = F_8 ( V_2 ) ;
V_4 = V_9 -> V_4 ;
if ( ! V_9 -> V_160 )
goto V_161;
F_49 (skb, frag) {
F_51 ( F_4 ( V_159 ) ) ;
}
V_161:
F_52 ( V_2 -> V_14 , V_4 ) ;
F_11 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_159 ;
V_9 = F_8 ( V_2 ) ;
if ( ! V_9 -> V_160 )
goto V_161;
F_49 (skb, frag) {
F_51 ( F_4 ( V_159 ) ) ;
}
V_161:
F_11 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
F_11 ( V_2 ) ;
else
F_50 ( V_2 ) ;
F_40 ( F_8 ( V_2 ) ) ;
}
unsigned int F_54 ( struct V_162 * V_163 )
{
struct V_8 * V_9 ;
unsigned int V_164 = 0 ;
while ( ( V_9 = F_55 ( V_163 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( ! F_5 ( V_2 ) )
V_164 += V_9 -> V_4 ;
F_53 ( V_2 ) ;
}
return V_164 ;
}
