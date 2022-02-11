static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
F_3 ( & V_2 -> V_5 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_4 != V_6 ;
}
static void F_5 ( struct V_1 * V_2 , const void * V_7 )
{
T_1 V_8 = * ( V_9 * ) V_7 ;
if ( ! V_10 )
return;
F_6 ( V_11 , L_1 , V_12 , 16 , 1 , V_7 ,
V_8 , true ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
void * V_7 , V_9 * V_15 )
{
struct V_16 * V_17 ;
V_9 V_18 , V_19 ;
V_9 V_20 , V_21 , V_22 , V_23 ;
V_9 * V_24 ;
if ( ! V_14 -> V_25 . V_26 )
return - V_27 ;
V_17 = V_14 -> V_17 ;
if ( ! V_17 )
return - V_27 ;
F_5 ( V_2 , V_7 ) ;
V_18 = ( * ( V_9 * ) V_7 ) >> 2 ;
if ( ! V_18 )
return - V_27 ;
V_21 = V_17 -> V_28 ;
V_22 = V_17 -> V_29 ;
V_23 = V_17 -> V_30 ;
F_8 () ;
if ( V_22 >= V_21 )
V_20 = V_23 - ( V_22 - V_21 ) ;
else
V_20 = V_21 - V_22 ;
if ( V_20 <= V_18 ) {
V_17 -> V_31 = 1 ;
F_9 () ;
return - V_32 ;
}
V_17 -> V_31 = 0 ;
F_9 () ;
V_19 = V_22 + V_18 ;
V_24 = ( V_9 * ) ( V_14 -> V_25 . V_26 + ( V_22 << 2 ) ) ;
if ( V_19 < V_23 ) {
memcpy ( V_24 , V_7 , V_18 << 2 ) ;
} else {
T_1 V_33 ;
V_19 -= V_23 ;
V_33 = ( V_18 - V_19 ) << 2 ;
memcpy ( V_24 , V_7 , V_33 ) ;
memcpy ( V_14 -> V_25 . V_26 , V_7 + V_33 , V_19 << 2 ) ;
}
F_9 () ;
V_17 -> V_29 = V_19 ;
* V_15 = V_17 -> V_15 ? 1 : 0 ;
F_10 () ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 , void * V_34 , V_9 * V_31 )
{
struct V_16 * V_17 ;
V_9 V_18 , V_35 ;
V_9 V_21 , V_22 , type , V_23 ;
V_9 * V_36 ;
V_9 V_37 = 0 ;
int V_38 = 0 ;
if ( ! V_14 -> V_25 . V_26 )
return - V_27 ;
V_17 = V_14 -> V_17 ;
if ( ! V_17 )
return - V_27 ;
type = V_17 -> type ;
V_21 = V_17 -> V_28 ;
V_22 = V_17 -> V_29 ;
V_23 = V_17 -> V_30 ;
F_8 () ;
if ( type & V_39 )
V_37 = 1 ;
if ( V_21 == V_22 ) {
V_17 -> V_15 = V_37 ;
* V_31 = 0 ;
F_9 () ;
return - V_40 ;
}
V_36 = ( V_9 * ) ( V_14 -> V_25 . V_26 + ( V_21 << 2 ) ) ;
V_18 = * V_36 >> 2 ;
if ( ! V_18 )
return - V_27 ;
V_35 = V_21 + V_18 ;
if ( ( ( V_18 << 2 ) <= V_41 ) && V_21 <= V_23 ) {
if ( V_35 < V_23 ) {
memcpy ( V_34 , V_36 , V_18 << 2 ) ;
} else {
T_1 V_33 ;
V_35 -= V_23 ;
V_33 = ( V_18 - V_35 ) << 2 ;
memcpy ( V_34 , V_36 , V_33 ) ;
memcpy ( V_34 + V_33 , V_14 -> V_25 . V_26 , V_35 << 2 ) ;
}
} else {
V_35 = V_17 -> V_29 ;
V_38 = - V_42 ;
}
F_8 () ;
V_17 -> V_28 = V_35 ;
F_9 () ;
V_21 = V_17 -> V_28 ;
V_22 = V_17 -> V_29 ;
F_8 () ;
if ( V_21 != V_22 )
V_17 -> V_15 = 0 ;
else
V_17 -> V_15 = V_37 ;
* V_31 = V_17 -> V_31 ? 1 : 0 ;
F_10 () ;
F_5 ( V_2 , V_34 ) ;
return V_38 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_43 * V_44 ,
V_9 V_45 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
V_44 -> V_49 = V_50 ;
V_44 -> V_45 = F_13 ( V_45 , V_51 ) ;
V_44 -> V_26 = F_14 ( V_47 , V_45 , & V_44 -> V_52 , V_53 ,
V_44 -> V_49 ) ;
if ( ! V_44 -> V_26 )
return - V_54 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_43 * V_55 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
F_16 ( V_47 , V_55 -> V_45 , V_55 -> V_26 , V_55 -> V_52 , V_55 -> V_49 ) ;
}
static void F_17 ( struct V_1 * V_2 , V_9 V_56 , V_9 V_57 )
{
F_18 ( V_57 , V_2 -> V_48 -> V_58 + V_56 ) ;
}
static V_9 F_19 ( struct V_1 * V_2 , V_9 V_56 )
{
return F_20 ( V_2 -> V_48 -> V_58 + V_56 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
const struct V_59 * V_60 = V_2 -> V_48 -> V_60 ;
const struct V_61 * V_62 = V_60 -> V_63 ;
unsigned int V_64 = V_60 -> V_65 ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ )
F_17 ( V_2 , V_62 [ V_66 ] . V_56 , V_62 [ V_66 ] . V_57 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_67 , F_23 ( V_68 ) ) ;
}
static int F_24 ( struct V_1 * V_2 ,
void * V_34 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
struct V_69 * V_70 ;
struct V_13 * V_14 ;
V_9 V_15 ;
int V_38 ;
if ( ! F_4 ( V_2 ) )
return - V_27 ;
V_70 = (struct V_69 * ) V_34 ;
V_2 -> V_71 = V_70 -> V_72 ;
V_14 = & V_2 -> V_73 [ V_74 ] ;
V_38 = F_7 ( V_2 , V_14 , V_34 , & V_15 ) ;
if ( V_38 ) {
F_25 ( V_47 , L_2 , V_38 ) ;
return V_38 ;
}
if ( V_15 )
F_22 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_34 )
{
int V_38 ;
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_24 ( V_2 , V_34 ) ;
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
static int F_27 ( struct V_75 * V_48 , V_9 V_76 ,
V_9 V_45 , V_9 V_77 , void * V_78 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_79 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
if ( V_76 == V_81 )
return 0 ;
V_34 = (struct V_79 * ) V_7 ;
V_38 = F_29 ( V_34 , V_76 , V_45 , V_77 , V_78 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
static const unsigned int V_82 = 100 ;
V_9 V_83 = 0 ;
unsigned int V_64 = 0 ;
int V_38 = 0 ;
F_17 ( V_2 , V_84 , F_23 ( V_85 ) ) ;
F_17 ( V_2 , V_86 , V_87 ) ;
F_17 ( V_2 , V_88 , 1 ) ;
while ( ! V_83 && V_64 < V_82 ) {
V_83 = F_19 ( V_2 , V_89 ) ;
if ( ( V_83 & V_90 ) == 4 ) {
F_25 ( V_47 , L_3 ) ;
V_38 = - V_27 ;
break;
}
F_31 ( 500 , 1000 ) ;
V_64 ++ ;
}
if ( V_64 >= V_82 )
V_38 = - V_91 ;
return V_38 ;
}
static V_9 F_32 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
V_9 V_92 = F_19 ( V_2 , V_93 ) ;
V_9 V_94 , V_95 , V_96 ;
V_94 = V_92 & V_97 ;
V_94 = V_94 >> V_98 ;
V_95 = V_92 & V_99 ;
V_95 = V_95 >> V_100 ;
V_96 = V_92 & V_101 ;
F_33 ( V_47 , L_4 , V_94 , V_95 , V_96 ) ;
return V_94 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
int V_38 ;
F_21 ( V_2 ) ;
F_17 ( V_2 , V_102 , V_2 -> V_103 . V_52 ) ;
F_17 ( V_2 , V_104 , V_105 ) ;
F_17 ( V_2 , V_106 , V_2 -> V_103 . V_52 ) ;
F_17 ( V_2 , V_107 , 0x01 ) ;
if ( V_2 -> V_108 . V_52 )
F_17 ( V_2 , V_109 , V_2 -> V_108 . V_52 ) ;
V_38 = F_30 ( V_2 ) ;
if ( V_38 ) {
F_25 ( V_47 , L_5 ) ;
return V_38 ;
}
F_32 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
void T_3 * V_58 = V_2 -> V_48 -> V_58 ;
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
V_9 V_110 ;
int V_38 ;
V_110 = F_19 ( V_2 , V_111 ) ;
V_110 |= V_112 ;
F_17 ( V_2 , V_111 , V_110 ) ;
V_38 = F_36 ( V_58 + V_113 , V_110 ,
V_110 & V_114 ,
V_115 ,
V_116 ) ;
if ( V_38 ) {
F_25 ( V_47 , L_6 ) ;
return V_38 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_38 ;
if ( ! V_2 -> V_117 )
return 0 ;
V_38 = F_38 ( V_118 , 0 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_35 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_117 = false ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_117 )
return 0 ;
V_38 = F_38 ( V_119 , 0 ) ;
if ( V_38 )
goto V_120;
V_38 = F_34 ( V_2 ) ;
if ( V_38 )
goto V_121;
V_2 -> V_117 = true ;
return 0 ;
V_121:
F_38 ( V_118 , 0 ) ;
V_120:
V_2 -> V_117 = false ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
void * V_34 )
{
struct V_13 * V_14 ;
V_9 V_31 ;
int V_38 ;
if ( ! F_4 ( V_2 ) )
return - V_27 ;
V_14 = & V_2 -> V_73 [ V_122 ] ;
V_38 = F_11 ( V_2 , V_14 , V_34 , & V_31 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 )
F_22 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_34 )
{
int V_38 ;
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_40 ( V_2 , V_34 ) ;
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 ,
void * V_34 )
{
struct V_13 * V_14 ;
V_9 V_31 ;
int V_38 ;
V_38 = F_4 ( V_2 ) ;
if ( ! V_38 )
return - V_27 ;
V_14 = & V_2 -> V_73 [ V_123 ] ;
V_38 = F_11 ( V_2 , V_14 , V_34 , & V_31 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 )
F_22 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_34 )
{
int V_38 ;
if ( ! V_34 )
return - V_27 ;
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_42 ( V_2 , V_34 ) ;
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
static void F_44 ( struct V_16 * V_17 )
{
V_17 -> V_124 = 1 ;
V_17 -> type = V_125 ;
V_17 -> V_30 = V_126 / 4 ;
V_17 -> V_8 = 0 ;
V_17 -> V_127 = 1 ;
V_17 -> V_128 = 1 ;
V_17 -> V_15 = 1 ;
V_17 -> V_31 = 0 ;
V_17 -> V_129 = 0 ;
V_17 -> V_130 = 0 ;
V_17 -> V_28 = 0 ;
V_17 -> V_29 = 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_5 ) ;
F_15 ( V_2 , & V_2 -> V_103 ) ;
F_15 ( V_2 , & V_2 -> V_108 ) ;
memset ( V_2 -> V_73 , 0 , sizeof( V_2 -> V_73 ) ) ;
memset ( & V_2 -> V_103 , 0 , sizeof( V_2 -> V_103 ) ) ;
memset ( & V_2 -> V_108 , 0 , sizeof( V_2 -> V_108 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
struct V_13 * V_14 ;
struct V_133 * V_108 ;
struct V_43 V_44 = { 0 } ;
unsigned int V_134 ;
unsigned int V_66 ;
int V_38 ;
V_38 = F_12 ( V_2 , & V_44 , V_135 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_103 . V_26 = V_44 . V_26 ;
V_2 -> V_103 . V_52 = V_44 . V_52 ;
V_2 -> V_103 . V_45 = V_136 ;
V_134 = V_2 -> V_103 . V_45 ;
for ( V_66 = 0 ; V_66 < V_137 ; V_66 ++ ) {
V_14 = & V_2 -> V_73 [ V_66 ] ;
V_14 -> V_25 . V_52 = V_44 . V_52 + V_134 ;
V_14 -> V_25 . V_26 = V_44 . V_26 + V_134 ;
V_14 -> V_25 . V_45 = V_126 ;
V_134 += V_14 -> V_25 . V_45 ;
V_14 -> V_17 =
F_47 ( V_2 -> V_103 . V_26 , V_66 ) ;
F_44 ( V_14 -> V_17 ) ;
V_14 -> V_17 -> V_138 = V_14 -> V_25 . V_52 ;
if ( V_66 == V_74 )
V_14 -> V_17 -> type |= V_139 ;
else if ( V_66 == V_122 )
V_14 -> V_17 -> type |= V_39 ;
else if ( V_66 == V_123 )
V_14 -> V_17 -> type |= V_140 ;
}
V_132 = V_2 -> V_103 . V_26 ;
V_132 -> V_141 = 0 ;
V_132 -> V_45 = V_136 ;
V_132 -> V_142 = sizeof( struct V_131 ) ;
V_132 -> V_143 = sizeof( struct V_16 ) ;
V_132 -> V_144 = V_137 ;
V_132 -> V_145 = V_137 ;
V_14 = & V_2 -> V_73 [ V_123 ] ;
V_14 -> V_17 -> V_15 = 0 ;
V_38 = F_12 ( V_2 , & V_44 , V_146 ) ;
if ( V_38 ) {
V_2 -> V_108 . V_52 = 0 ;
} else {
V_2 -> V_108 . V_52 = V_44 . V_52 ;
V_2 -> V_108 . V_26 = V_44 . V_26 ;
V_2 -> V_108 . V_45 = V_146 ;
V_108 = V_2 -> V_108 . V_26 ;
V_108 -> V_147 = V_146 ;
}
F_9 () ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , V_9 V_148 )
{
struct V_149 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
V_34 = (struct V_149 * ) V_7 ;
F_49 ( V_34 , V_150 , V_148 ) ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , V_9 V_151 )
{
struct V_149 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
V_34 = (struct V_149 * ) V_7 ;
F_51 ( V_34 , V_151 ) ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
bool V_152 )
{
struct V_149 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
if ( ! V_152 )
return 0 ;
V_34 = (struct V_149 * ) V_7 ;
F_53 ( V_34 , V_152 ) ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
bool V_152 )
{
struct V_149 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
V_34 = (struct V_149 * ) V_7 ;
F_55 ( V_34 , V_152 ) ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
unsigned int V_153 )
{
struct V_16 * V_17 ;
if ( V_153 >= V_137 )
return - V_27 ;
V_17 = V_2 -> V_73 [ V_153 ] . V_17 ;
if ( ! V_17 )
return - V_27 ;
return abs ( V_17 -> V_28 - V_17 -> V_29 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
int V_38 ;
V_38 = F_48 ( V_2 , V_154 ) ;
if ( V_38 )
F_58 ( V_47 , L_7 , V_38 ) ;
V_38 = F_52 ( V_2 , V_155 ) ;
if ( V_38 )
F_58 ( V_47 , L_8 , V_38 ) ;
V_38 = F_54 ( V_2 , V_156 ) ;
if ( V_38 )
F_58 ( V_47 , L_9 ,
V_38 ) ;
return V_38 ;
}
static int F_59 ( struct V_157 * V_158 , V_9 V_72 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_159 V_34 ;
F_60 ( & V_34 , V_72 , V_158 ) ;
return F_26 ( V_2 , & V_34 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
void * V_7 = V_2 -> V_160 ;
while ( ! F_43 ( V_2 , V_7 ) ) {
struct V_161 * V_34 = V_7 ;
if ( V_34 -> V_162 . V_72 != V_163 ) {
struct V_164 * V_34 = V_7 ;
F_33 ( V_47 , L_10 , V_34 -> V_165 ) ;
}
}
}
static int F_62 ( struct V_1 * V_2 ,
bool V_166 )
{
unsigned long V_167 = F_63 ( V_168 ) ;
struct V_169 V_34 ;
int V_38 ;
F_64 ( & V_2 -> V_170 ) ;
F_65 ( & V_34 ) ;
V_38 = F_26 ( V_2 , & V_34 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_166 )
return 0 ;
V_38 = F_66 ( & V_2 -> V_170 , V_167 ) ;
if ( ! V_38 ) {
F_61 ( V_2 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_171 , V_172 ;
V_171 = F_56 ( V_2 , V_122 ) ;
if ( V_171 < 0 )
return V_171 ;
V_172 = F_56 ( V_2 , V_74 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( ! V_171 && ! V_172 )
return 1 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
struct V_133 * V_108 = V_2 -> V_108 . V_26 ;
void * V_173 ;
if ( ! V_108 )
return;
V_173 = memchr ( V_108 -> V_174 , '\0' , V_108 -> V_147 ) ;
if ( ! V_173 )
V_108 -> V_174 [ V_108 -> V_147 - 1 ] = '\0' ;
F_69 ( V_47 , L_11 , V_108 -> V_174 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
void * V_7 )
{
struct V_175 * V_176 = V_7 ;
if ( V_176 -> V_177 != V_178 )
return;
F_1 ( V_2 , V_6 ) ;
F_35 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static T_4 F_71 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
const struct V_59 * V_60 ;
void * V_34 ;
V_9 V_179 ;
if ( ! V_2 )
return V_180 ;
V_60 = V_2 -> V_48 -> V_60 ;
V_34 = V_2 -> V_181 ;
if ( V_2 -> V_182 & V_183 ) {
F_68 ( V_2 ) ;
F_72 ( V_48 ) ;
}
while ( ! F_41 ( V_2 , V_34 ) ) {
V_179 = F_73 ( V_48 , V_34 ) ;
switch ( V_179 ) {
case V_184 :
F_70 ( V_2 , V_34 ) ;
break;
case V_185 :
F_27 ( V_48 , V_60 -> V_186 ,
V_60 -> V_187 ,
V_60 -> V_188 ,
V_2 ) ;
break;
case V_189 :
F_74 ( & V_2 -> V_190 ) ;
break;
case V_191 :
F_74 ( & V_2 -> V_170 ) ;
break;
default:
break;
}
}
F_61 ( V_2 ) ;
return V_192 ;
}
static T_4 F_75 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
V_9 V_124 ;
if ( ! V_2 )
return V_180 ;
V_124 = F_19 ( V_2 , V_193 ) ;
if ( V_124 & V_194 ||
V_124 & V_183 ||
V_124 & V_195 )
V_2 -> V_182 = V_124 ;
F_17 ( V_2 , V_196 , 1 ) ;
F_17 ( V_2 , V_197 , V_124 ) ;
return V_198 ;
}
static int F_76 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_46 * V_47 = V_48 -> V_47 ;
struct V_199 V_200 ;
struct V_201 V_34 ;
int V_38 ;
F_77 ( & V_34 , V_202 ) ;
F_1 ( V_2 , V_203 ) ;
V_38 = F_26 ( V_2 , & V_34 ) ;
if ( V_38 )
return V_38 ;
F_78 ( & V_200 ) ;
V_38 = F_26 ( V_2 , & V_200 ) ;
if ( V_38 )
F_58 ( V_47 , L_12 ) ;
return 0 ;
}
static int F_79 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
F_1 ( V_2 , V_6 ) ;
V_2 -> V_204 = true ;
V_2 -> V_117 = false ;
return 0 ;
}
static int F_80 ( struct V_75 * V_48 , V_9 V_78 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_205 V_34 ;
F_81 ( & V_34 , V_78 ) ;
return F_26 ( V_2 , & V_34 ) ;
}
static int F_82 ( struct V_75 * V_48 , V_9 V_206 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_207 V_34 ;
int V_38 ;
V_38 = F_83 ( & V_34 , V_206 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , & V_34 ) ;
}
static int F_84 ( struct V_157 * V_158 , V_9 V_208 ,
V_9 V_209 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_210 V_34 ;
int V_38 ;
V_38 = F_57 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_85 ( & V_34 , V_158 , V_208 , V_209 ) ;
if ( V_38 )
goto V_120;
V_38 = F_26 ( V_2 , & V_34 ) ;
if ( V_38 )
goto V_120;
return 0 ;
V_120:
F_61 ( V_2 ) ;
return V_38 ;
}
static int F_86 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_46 * V_47 = V_2 -> V_48 -> V_47 ;
if ( V_211 ) {
if ( F_50 ( V_2 , V_211 ) )
F_58 ( V_47 , L_13 ) ;
}
return F_59 ( V_158 , V_212 ) ;
}
static int F_87 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
F_61 ( V_2 ) ;
return F_59 ( V_158 , V_213 ) ;
}
static int F_88 ( struct V_157 * V_158 , V_9 V_214 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_215 V_34 ;
int V_38 ;
V_38 = F_89 ( & V_34 , V_158 , V_214 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , & V_34 ) ;
}
static int F_90 ( struct V_157 * V_158 )
{
return F_59 ( V_158 , V_216 ) ;
}
static int F_91 ( struct V_157 * V_158 )
{
return F_59 ( V_158 , V_217 ) ;
}
static int F_92 ( struct V_157 * V_158 )
{
return F_59 ( V_158 , V_218 ) ;
}
static int F_93 ( struct V_157 * V_158 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
V_9 V_208 = V_158 -> V_208 ;
int V_38 ;
if ( V_208 == V_221 ) {
struct V_222 V_34 ;
V_38 = F_94 ( & V_34 , V_158 , V_220 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_26 ( V_2 , & V_34 ) ;
} else if ( V_208 == V_223 ) {
struct V_224 V_34 ;
V_38 = F_95 ( & V_34 , V_158 , V_220 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_26 ( V_2 , & V_34 ) ;
} else {
V_38 = - V_27 ;
}
return V_38 ;
}
static int F_96 ( struct V_157 * V_158 ,
struct V_219 * V_225 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_226 V_34 ;
int V_38 ;
V_38 = F_97 ( & V_34 , V_158 , V_225 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , & V_34 ) ;
}
static int F_98 ( struct V_157 * V_158 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_229 * V_34 ;
T_2 V_7 [ V_230 ] ;
int V_38 ;
if ( V_228 -> V_231 == V_232 )
return 0 ;
V_34 = (struct V_229 * ) V_7 ;
V_38 = F_99 ( V_34 , V_158 , V_228 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , V_34 ) ;
}
static int F_100 ( struct V_157 * V_158 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_233 * V_34 ;
T_2 V_7 [ V_230 ] ;
int V_38 ;
if ( V_228 -> V_231 == V_232 )
return 0 ;
V_34 = (struct V_233 * ) V_7 ;
V_38 = F_101 ( V_34 , V_158 , V_228 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , V_34 ) ;
}
static int F_102 ( struct V_157 * V_158 )
{
return F_59 ( V_158 , V_234 ) ;
}
static int F_103 ( struct V_157 * V_158 )
{
return F_59 ( V_158 , V_235 ) ;
}
static int F_104 ( struct V_157 * V_158 , V_9 V_236 ,
V_9 V_237 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_238 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
V_34 = (struct V_238 * ) V_7 ;
V_38 = F_105 ( V_34 , V_158 , V_236 , V_237 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_26 ( V_2 , V_34 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_106 ( struct V_157 * V_158 , V_9 V_236 ,
V_9 V_237 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_239 * V_34 ;
T_2 V_7 [ V_80 ] ;
int V_38 ;
V_34 = (struct V_239 * ) V_7 ;
V_38 = F_107 ( V_34 , V_158 , V_236 , V_237 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , V_34 ) ;
}
static int F_108 ( struct V_157 * V_158 , V_9 V_240 ,
void * V_241 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_242 * V_34 ;
T_2 V_7 [ V_230 ] ;
int V_38 ;
V_34 = (struct V_242 * ) V_7 ;
V_38 = F_109 ( V_34 , V_158 , V_240 , V_241 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , V_34 ) ;
}
static int F_110 ( struct V_157 * V_158 , V_9 V_240 )
{
struct V_1 * V_2 = F_28 ( V_158 -> V_48 ) ;
struct V_243 V_34 ;
int V_38 ;
V_38 = F_111 ( & V_34 , V_158 , V_240 ) ;
if ( V_38 )
return V_38 ;
return F_26 ( V_2 , & V_34 ) ;
}
static int F_112 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
int V_38 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_204 )
goto V_244;
V_38 = F_39 ( V_2 ) ;
V_244:
if ( ! V_38 )
V_2 -> V_204 = false ;
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
static int F_113 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_46 * V_47 = V_48 -> V_47 ;
V_9 V_83 ;
int V_38 ;
if ( ! V_2 -> V_117 || V_2 -> V_204 )
return 0 ;
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_4 ( V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
if ( ! V_38 ) {
F_25 ( V_47 , L_14 ) ;
return - V_27 ;
}
V_38 = F_62 ( V_2 , true ) ;
if ( V_38 ) {
F_25 ( V_47 , L_15 , V_38 ) ;
return V_38 ;
}
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_71 != V_245 ) {
F_3 ( & V_2 -> V_5 ) ;
return - V_27 ;
}
V_38 = F_67 ( V_2 ) ;
if ( V_38 < 0 || ! V_38 ) {
F_3 ( & V_2 -> V_5 ) ;
return - V_27 ;
}
V_83 = F_19 ( V_2 , V_89 ) ;
if ( ! ( V_83 & V_246 ) ) {
F_3 ( & V_2 -> V_5 ) ;
return - V_27 ;
}
V_38 = F_37 ( V_2 ) ;
if ( V_38 ) {
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
V_2 -> V_204 = true ;
F_3 ( & V_2 -> V_5 ) ;
return 0 ;
}
static int F_114 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
struct V_46 * V_47 = V_48 -> V_47 ;
V_9 V_83 , V_247 ;
int V_38 ;
int V_248 = 100 ;
if ( ! V_2 -> V_117 || V_2 -> V_204 )
return 0 ;
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_4 ( V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
if ( ! V_38 ) {
F_25 ( V_47 , L_14 ) ;
return - V_27 ;
}
V_83 = F_19 ( V_2 , V_89 ) ;
if ( ! ( V_83 & V_246 ) ) {
V_247 = F_19 ( V_2 , V_249 ) ;
V_83 = F_19 ( V_2 , V_89 ) ;
V_38 = F_62 ( V_2 , false ) ;
if ( V_38 ) {
F_25 ( V_47 , L_15 ,
V_38 ) ;
return V_38 ;
}
V_248 = 100 ;
while ( V_248 -- ) {
V_247 = F_19 ( V_2 , V_249 ) ;
V_83 = F_19 ( V_2 , V_89 ) ;
if ( V_83 & V_246 &&
V_247 & F_23 ( 0 ) )
break;
F_31 ( 1000 , 1500 ) ;
}
}
F_2 ( & V_2 -> V_5 ) ;
V_38 = F_37 ( V_2 ) ;
if ( V_38 ) {
F_25 ( V_47 , L_16 , V_38 ) ;
F_3 ( & V_2 -> V_5 ) ;
return V_38 ;
}
V_2 -> V_204 = true ;
F_3 ( & V_2 -> V_5 ) ;
return 0 ;
}
static int F_115 ( struct V_75 * V_48 )
{
if ( V_48 -> V_60 -> V_250 == V_251 )
return F_114 ( V_48 ) ;
return F_113 ( V_48 ) ;
}
void F_116 ( struct V_75 * V_48 )
{
struct V_1 * V_2 = F_28 ( V_48 ) ;
F_45 ( V_2 ) ;
F_117 ( & V_2 -> V_5 ) ;
F_118 ( V_2 ) ;
V_48 -> V_252 = NULL ;
V_48 -> V_253 = NULL ;
}
int F_119 ( struct V_75 * V_48 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = F_120 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_121 ( & V_2 -> V_5 ) ;
V_2 -> V_48 = V_48 ;
V_2 -> V_204 = true ;
V_48 -> V_252 = V_2 ;
V_48 -> V_253 = & V_254 ;
V_48 -> V_255 = V_256 | V_257 |
V_258 |
V_259 ;
V_38 = F_46 ( V_2 ) ;
if ( V_38 )
goto V_260;
return 0 ;
V_260:
F_118 ( V_2 ) ;
V_48 -> V_252 = NULL ;
V_48 -> V_253 = NULL ;
return V_38 ;
}
