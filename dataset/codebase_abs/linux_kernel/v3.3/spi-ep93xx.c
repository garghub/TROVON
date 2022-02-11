static inline void
F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_2
F_3 ( const struct V_1 * V_6 , T_1 V_3 )
{
return F_4 ( V_6 -> V_5 + V_3 ) ;
}
static inline void
F_5 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1
F_7 ( const struct V_1 * V_6 , T_1 V_3 )
{
return F_8 ( V_6 -> V_5 + V_3 ) ;
}
static int F_9 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
int V_8 ;
V_8 = F_10 ( V_2 -> V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 |= V_11 ;
F_1 ( V_2 , V_10 , V_7 ) ;
return 0 ;
}
static void F_11 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 &= ~ V_11 ;
F_1 ( V_2 , V_10 , V_7 ) ;
F_12 ( V_2 -> V_9 ) ;
}
static void F_13 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 |= ( V_12 | V_13 | V_14 ) ;
F_1 ( V_2 , V_10 , V_7 ) ;
}
static void F_14 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 &= ~ ( V_12 | V_13 | V_14 ) ;
F_1 ( V_2 , V_10 , V_7 ) ;
}
static int F_15 ( const struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned long V_17 )
{
unsigned long V_18 = F_16 ( V_2 -> V_9 ) ;
int V_19 , V_20 ;
V_17 = F_17 ( V_17 , V_2 -> V_21 , V_2 -> V_22 ) ;
for ( V_19 = 2 ; V_19 <= 254 ; V_19 += 2 ) {
for ( V_20 = 0 ; V_20 <= 255 ; V_20 ++ ) {
if ( ( V_18 / ( V_19 * ( V_20 + 1 ) ) ) <= V_17 ) {
V_16 -> V_23 = ( T_2 ) V_20 ;
V_16 -> V_24 = ( T_2 ) V_19 ;
return 0 ;
}
}
}
return - V_25 ;
}
static void F_18 ( struct V_26 * V_6 , bool V_27 )
{
struct V_15 * V_16 = F_19 ( V_6 ) ;
int V_4 = ( V_6 -> V_28 & V_29 ) ? V_27 : ! V_27 ;
if ( V_16 -> V_30 && V_16 -> V_30 -> V_31 )
V_16 -> V_30 -> V_31 ( V_6 , V_4 ) ;
}
static int F_20 ( struct V_26 * V_6 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_15 * V_16 ;
if ( V_6 -> V_33 < 4 || V_6 -> V_33 > 16 ) {
F_22 ( & V_2 -> V_34 -> V_35 , L_1 ,
V_6 -> V_33 ) ;
return - V_25 ;
}
V_16 = F_19 ( V_6 ) ;
if ( ! V_16 ) {
F_23 ( & V_2 -> V_34 -> V_35 , L_2 ,
V_6 -> V_36 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_37 ) ;
if ( ! V_16 )
return - V_38 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_30 = V_6 -> V_39 ;
if ( V_16 -> V_30 && V_16 -> V_30 -> V_40 ) {
int V_41 = V_16 -> V_30 -> V_40 ( V_6 ) ;
if ( V_41 ) {
F_25 ( V_16 ) ;
return V_41 ;
}
}
F_26 ( V_6 , V_16 ) ;
}
if ( V_6 -> V_42 != V_16 -> V_17 ) {
int V_8 ;
V_8 = F_15 ( V_2 , V_16 , V_6 -> V_42 ) ;
if ( V_8 != 0 ) {
F_26 ( V_6 , NULL ) ;
F_25 ( V_16 ) ;
return V_8 ;
}
V_16 -> V_17 = V_6 -> V_42 ;
}
V_16 -> V_43 = F_27 ( V_6 -> V_33 ) ;
F_18 ( V_6 , false ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_46 * V_47 ;
unsigned long V_48 ;
if ( ! V_45 || ! V_45 -> V_49 )
return - V_25 ;
F_29 (t, &msg->transfers, transfer_list) {
if ( V_47 -> V_33 ) {
if ( V_47 -> V_33 < 4 || V_47 -> V_33 > 16 )
return - V_25 ;
}
if ( V_47 -> V_50 && V_47 -> V_50 < V_2 -> V_21 )
return - V_25 ;
}
V_45 -> V_51 = NULL ;
V_45 -> V_52 = 0 ;
V_45 -> V_53 = 0 ;
F_30 ( & V_2 -> V_54 , V_48 ) ;
if ( ! V_2 -> V_55 ) {
F_31 ( & V_2 -> V_54 , V_48 ) ;
return - V_56 ;
}
F_32 ( & V_45 -> V_57 , & V_2 -> V_58 ) ;
F_33 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_31 ( & V_2 -> V_54 , V_48 ) ;
return 0 ;
}
static void F_34 ( struct V_26 * V_6 )
{
struct V_15 * V_16 ;
V_16 = F_19 ( V_6 ) ;
if ( V_16 ) {
if ( V_16 -> V_30 && V_16 -> V_30 -> V_61 )
V_16 -> V_30 -> V_61 ( V_6 ) ;
F_26 ( V_6 , NULL ) ;
F_25 ( V_16 ) ;
}
}
static void F_35 ( const struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
T_1 V_62 ;
V_62 = V_16 -> V_23 << V_63 ;
V_62 |= ( V_16 -> V_6 -> V_28 & ( V_64 | V_65 ) ) << V_66 ;
V_62 |= V_16 -> V_43 ;
F_23 ( & V_2 -> V_34 -> V_35 , L_3 ,
V_16 -> V_6 -> V_28 , V_16 -> V_24 , V_16 -> V_23 , V_16 -> V_43 ) ;
F_23 ( & V_2 -> V_34 -> V_35 , L_4 , V_62 ) ;
F_1 ( V_2 , V_67 , V_16 -> V_24 ) ;
F_5 ( V_2 , V_68 , V_62 ) ;
}
static inline int V_33 ( const struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
return V_47 -> V_33 ? V_47 -> V_33 : V_45 -> V_6 -> V_33 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_33 ( V_2 ) > 8 ) {
T_1 V_70 = 0 ;
if ( V_47 -> V_71 )
V_70 = ( ( T_1 * ) V_47 -> V_71 ) [ V_2 -> V_72 ] ;
F_5 ( V_2 , V_73 , V_70 ) ;
V_2 -> V_72 += sizeof( V_70 ) ;
} else {
T_2 V_70 = 0 ;
if ( V_47 -> V_71 )
V_70 = ( ( T_2 * ) V_47 -> V_71 ) [ V_2 -> V_72 ] ;
F_1 ( V_2 , V_73 , V_70 ) ;
V_2 -> V_72 += sizeof( V_70 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_33 ( V_2 ) > 8 ) {
T_1 V_74 ;
V_74 = F_7 ( V_2 , V_73 ) ;
if ( V_47 -> V_75 )
( ( T_1 * ) V_47 -> V_75 ) [ V_2 -> V_76 ] = V_74 ;
V_2 -> V_76 += sizeof( V_74 ) ;
} else {
T_2 V_74 ;
V_74 = F_3 ( V_2 , V_73 ) ;
if ( V_47 -> V_75 )
( ( T_2 * ) V_47 -> V_75 ) [ V_2 -> V_76 ] = V_74 ;
V_2 -> V_76 += sizeof( V_74 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
while ( ( F_3 ( V_2 , V_77 ) & V_78 ) ) {
F_37 ( V_2 , V_47 ) ;
V_2 -> V_79 -- ;
}
while ( V_2 -> V_79 < V_80 && V_2 -> V_72 < V_47 -> V_81 ) {
F_36 ( V_2 , V_47 ) ;
V_2 -> V_79 ++ ;
}
if ( V_2 -> V_76 == V_47 -> V_81 )
return 0 ;
return - V_82 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_38 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_40 ( & V_2 -> V_83 ) ;
}
}
static struct V_84 *
F_41 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_46 * V_47 = V_2 -> V_69 -> V_51 ;
struct V_84 * V_87 ;
enum V_88 V_89 ;
struct V_90 V_91 ;
enum V_92 V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
const void * V_100 , * V_101 ;
T_3 V_81 = V_47 -> V_81 ;
int V_102 , V_41 , V_103 ;
if ( V_33 ( V_2 ) > 8 )
V_89 = V_104 ;
else
V_89 = V_105 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_106 = V_86 ;
if ( V_86 == V_107 ) {
V_99 = V_2 -> V_108 ;
V_100 = V_47 -> V_75 ;
V_97 = & V_2 -> V_109 ;
V_91 . V_110 = V_2 -> V_111 ;
V_91 . V_112 = V_89 ;
V_93 = V_113 ;
} else {
V_99 = V_2 -> V_114 ;
V_100 = V_47 -> V_71 ;
V_97 = & V_2 -> V_115 ;
V_91 . V_116 = V_2 -> V_111 ;
V_91 . V_117 = V_89 ;
V_93 = V_118 ;
}
V_41 = F_42 ( V_99 , & V_91 ) ;
if ( V_41 )
return F_43 ( V_41 ) ;
V_103 = F_44 ( V_81 , V_119 ) ;
if ( V_103 != V_97 -> V_103 ) {
F_45 ( V_97 ) ;
V_41 = F_46 ( V_97 , V_103 , V_37 ) ;
if ( V_41 )
return F_43 ( V_41 ) ;
}
V_101 = V_100 ;
F_47 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_120 = F_48 ( T_3 , V_81 , V_119 ) ;
if ( V_100 ) {
F_49 ( V_95 , F_50 ( V_101 ) , V_120 ,
F_51 ( V_101 ) ) ;
} else {
F_49 ( V_95 , F_50 ( V_2 -> V_121 ) ,
V_120 , 0 ) ;
}
V_101 += V_120 ;
V_81 -= V_120 ;
}
if ( F_52 ( V_81 ) ) {
F_53 ( & V_2 -> V_34 -> V_35 , L_5 , V_81 ) ;
return F_43 ( - V_25 ) ;
}
V_103 = F_54 ( V_99 -> V_122 -> V_35 , V_97 -> V_123 , V_97 -> V_103 , V_86 ) ;
if ( ! V_103 )
return F_43 ( - V_38 ) ;
V_87 = V_99 -> V_122 -> V_124 ( V_99 , V_97 -> V_123 , V_103 ,
V_93 , V_125 ) ;
if ( ! V_87 ) {
F_55 ( V_99 -> V_122 -> V_35 , V_97 -> V_123 , V_97 -> V_103 , V_86 ) ;
return F_43 ( - V_38 ) ;
}
return V_87 ;
}
static void F_56 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
struct V_98 * V_99 ;
struct V_96 * V_97 ;
if ( V_86 == V_107 ) {
V_99 = V_2 -> V_108 ;
V_97 = & V_2 -> V_109 ;
} else {
V_99 = V_2 -> V_114 ;
V_97 = & V_2 -> V_115 ;
}
F_55 ( V_99 -> V_122 -> V_35 , V_97 -> V_123 , V_97 -> V_103 , V_86 ) ;
}
static void F_57 ( void * V_126 )
{
V_49 ( V_126 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_84 * V_127 , * V_87 ;
V_127 = F_41 ( V_2 , V_107 ) ;
if ( F_59 ( V_127 ) ) {
F_22 ( & V_2 -> V_34 -> V_35 , L_6 , F_60 ( V_127 ) ) ;
V_45 -> V_52 = F_60 ( V_127 ) ;
return;
}
V_87 = F_41 ( V_2 , V_128 ) ;
if ( F_59 ( V_87 ) ) {
F_56 ( V_2 , V_107 ) ;
F_22 ( & V_2 -> V_34 -> V_35 , L_7 , F_60 ( V_127 ) ) ;
V_45 -> V_52 = F_60 ( V_87 ) ;
return;
}
V_127 -> V_129 = F_57 ;
V_127 -> V_126 = & V_2 -> V_83 ;
F_61 ( V_127 ) ;
F_61 ( V_87 ) ;
F_62 ( V_2 -> V_108 ) ;
F_62 ( V_2 -> V_114 ) ;
F_40 ( & V_2 -> V_83 ) ;
F_56 ( V_2 , V_128 ) ;
F_56 ( V_2 , V_107 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 = F_19 ( V_45 -> V_6 ) ;
V_45 -> V_51 = V_47 ;
if ( V_47 -> V_50 || V_47 -> V_33 ) {
struct V_15 V_130 = * V_16 ;
if ( V_47 -> V_50 ) {
int V_8 ;
V_8 = F_15 ( V_2 , & V_130 ,
V_47 -> V_50 ) ;
if ( V_8 ) {
F_22 ( & V_2 -> V_34 -> V_35 ,
L_8 ) ;
V_45 -> V_52 = V_8 ;
return;
}
}
if ( V_47 -> V_33 )
V_130 . V_43 = F_27 ( V_47 -> V_33 ) ;
F_35 ( V_2 , & V_130 ) ;
}
V_2 -> V_76 = 0 ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_108 && V_47 -> V_81 > V_80 )
F_58 ( V_2 ) ;
else
F_39 ( V_2 ) ;
if ( V_45 -> V_52 )
return;
V_45 -> V_53 += V_47 -> V_81 ;
if ( V_47 -> V_131 ) {
F_64 ( V_132 ) ;
F_65 ( F_66 ( V_47 -> V_131 ) ) ;
}
if ( V_47 -> V_133 ) {
if ( ! F_67 ( & V_47 -> V_134 , & V_45 -> V_135 ) ) {
F_18 ( V_45 -> V_6 , false ) ;
F_68 () ;
F_18 ( V_45 -> V_6 , true ) ;
}
}
if ( V_47 -> V_50 || V_47 -> V_33 )
F_35 ( V_2 , V_16 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned long V_136 ;
struct V_46 * V_47 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_22 ( & V_2 -> V_34 -> V_35 , L_9 ) ;
V_45 -> V_52 = V_8 ;
return;
}
V_136 = V_137 + F_70 ( V_138 ) ;
while ( F_7 ( V_2 , V_77 ) & V_78 ) {
if ( F_71 ( V_137 , V_136 ) ) {
F_53 ( & V_2 -> V_34 -> V_35 ,
L_10 ) ;
V_45 -> V_52 = - V_139 ;
return;
}
F_7 ( V_2 , V_73 ) ;
}
V_2 -> V_79 = 0 ;
F_35 ( V_2 , F_19 ( V_45 -> V_6 ) ) ;
F_18 ( V_45 -> V_6 , true ) ;
F_29 (t, &msg->transfers, transfer_list) {
F_63 ( V_2 , V_45 , V_47 ) ;
if ( V_45 -> V_52 )
break;
}
F_18 ( V_45 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static void F_72 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_73 ( V_141 ) ;
struct V_44 * V_45 ;
F_74 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 || V_2 -> V_69 ||
F_75 ( & V_2 -> V_58 ) ) {
F_76 ( & V_2 -> V_54 ) ;
return;
}
V_45 = F_77 ( & V_2 -> V_58 , struct V_44 , V_57 ) ;
F_78 ( & V_45 -> V_57 ) ;
V_2 -> V_69 = V_45 ;
F_76 ( & V_2 -> V_54 ) ;
F_69 ( V_2 , V_45 ) ;
F_74 ( & V_2 -> V_54 ) ;
V_2 -> V_69 = NULL ;
if ( V_2 -> V_55 && ! F_75 ( & V_2 -> V_58 ) )
F_33 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_76 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_142 ) ;
}
static T_4 F_79 ( int V_143 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
T_2 V_145 = F_3 ( V_2 , V_146 ) ;
if ( F_80 ( V_145 & V_147 ) ) {
F_1 ( V_2 , V_148 , 0 ) ;
F_53 ( & V_2 -> V_34 -> V_35 ,
L_11 ) ;
V_2 -> V_69 -> V_52 = - V_149 ;
} else {
if ( F_38 ( V_2 ) ) {
return V_150 ;
}
}
F_14 ( V_2 ) ;
V_49 ( & V_2 -> V_83 ) ;
return V_150 ;
}
static bool F_81 ( struct V_98 * V_99 , void * V_151 )
{
if ( F_82 ( V_99 ) )
return false ;
V_99 -> V_152 = V_151 ;
return true ;
}
static int F_83 ( struct V_1 * V_2 )
{
T_5 V_153 ;
int V_41 ;
V_2 -> V_121 = ( void * ) F_84 ( V_37 ) ;
if ( ! V_2 -> V_121 )
return - V_38 ;
F_85 ( V_153 ) ;
F_86 ( V_154 , V_153 ) ;
V_2 -> V_155 . V_156 = V_157 ;
V_2 -> V_155 . V_106 = V_113 ;
V_2 -> V_155 . V_158 = L_12 ;
V_2 -> V_108 = F_87 ( V_153 , F_81 ,
& V_2 -> V_155 ) ;
if ( ! V_2 -> V_108 ) {
V_41 = - V_159 ;
goto V_160;
}
V_2 -> V_161 . V_156 = V_157 ;
V_2 -> V_161 . V_106 = V_118 ;
V_2 -> V_161 . V_158 = L_13 ;
V_2 -> V_114 = F_87 ( V_153 , F_81 ,
& V_2 -> V_161 ) ;
if ( ! V_2 -> V_114 ) {
V_41 = - V_159 ;
goto V_162;
}
return 0 ;
V_162:
F_88 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
V_160:
F_89 ( ( unsigned long ) V_2 -> V_121 ) ;
return V_41 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_108 ) {
F_88 ( V_2 -> V_108 ) ;
F_45 ( & V_2 -> V_109 ) ;
}
if ( V_2 -> V_114 ) {
F_88 ( V_2 -> V_114 ) ;
F_45 ( & V_2 -> V_115 ) ;
}
if ( V_2 -> V_121 )
F_89 ( ( unsigned long ) V_2 -> V_121 ) ;
}
static int T_6 F_91 ( struct V_163 * V_34 )
{
struct V_164 * V_32 ;
struct V_165 * V_166 ;
struct V_1 * V_2 ;
struct V_167 * V_168 ;
int error ;
V_166 = V_34 -> V_35 . V_169 ;
V_32 = F_92 ( & V_34 -> V_35 , sizeof( * V_2 ) ) ;
if ( ! V_32 ) {
F_22 ( & V_34 -> V_35 , L_14 ) ;
return - V_38 ;
}
V_32 -> V_40 = F_20 ;
V_32 -> V_170 = F_28 ;
V_32 -> V_61 = F_34 ;
V_32 -> V_171 = V_34 -> V_172 ;
V_32 -> V_173 = V_166 -> V_173 ;
V_32 -> V_174 = V_65 | V_64 | V_29 ;
F_93 ( V_34 , V_32 ) ;
V_2 = F_21 ( V_32 ) ;
V_2 -> V_9 = F_94 ( & V_34 -> V_35 , NULL ) ;
if ( F_59 ( V_2 -> V_9 ) ) {
F_22 ( & V_34 -> V_35 , L_15 ) ;
error = F_60 ( V_2 -> V_9 ) ;
goto V_175;
}
F_95 ( & V_2 -> V_54 ) ;
F_96 ( & V_2 -> V_83 ) ;
V_2 -> V_22 = F_16 ( V_2 -> V_9 ) / 2 ;
V_2 -> V_21 = F_16 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_34 = V_34 ;
V_2 -> V_143 = F_97 ( V_34 , 0 ) ;
if ( V_2 -> V_143 < 0 ) {
error = - V_176 ;
F_22 ( & V_34 -> V_35 , L_16 ) ;
goto V_177;
}
V_168 = F_98 ( V_34 , V_178 , 0 ) ;
if ( ! V_168 ) {
F_22 ( & V_34 -> V_35 , L_17 ) ;
error = - V_159 ;
goto V_177;
}
V_168 = F_99 ( V_168 -> V_179 , F_100 ( V_168 ) , V_34 -> V_158 ) ;
if ( ! V_168 ) {
F_22 ( & V_34 -> V_35 , L_18 ) ;
error = - V_176 ;
goto V_177;
}
V_2 -> V_111 = V_168 -> V_179 + V_73 ;
V_2 -> V_5 = F_101 ( V_168 -> V_179 , F_100 ( V_168 ) ) ;
if ( ! V_2 -> V_5 ) {
F_22 ( & V_34 -> V_35 , L_19 ) ;
error = - V_159 ;
goto V_180;
}
error = F_102 ( V_2 -> V_143 , F_79 , 0 ,
L_20 , V_2 ) ;
if ( error ) {
F_22 ( & V_34 -> V_35 , L_21 ) ;
goto V_181;
}
if ( V_166 -> V_182 && F_83 ( V_2 ) )
F_53 ( & V_34 -> V_35 , L_22 ) ;
V_2 -> V_59 = F_103 ( L_23 ) ;
if ( ! V_2 -> V_59 ) {
F_22 ( & V_34 -> V_35 , L_24 ) ;
goto V_183;
}
F_104 ( & V_2 -> V_60 , F_72 ) ;
F_105 ( & V_2 -> V_58 ) ;
V_2 -> V_55 = true ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_106 ( V_32 ) ;
if ( error ) {
F_22 ( & V_34 -> V_35 , L_25 ) ;
goto V_184;
}
F_107 ( & V_34 -> V_35 , L_26 ,
( unsigned long ) V_168 -> V_179 , V_2 -> V_143 ) ;
return 0 ;
V_184:
F_108 ( V_2 -> V_59 ) ;
V_183:
F_90 ( V_2 ) ;
F_109 ( V_2 -> V_143 , V_2 ) ;
V_181:
F_110 ( V_2 -> V_5 ) ;
V_180:
F_111 ( V_168 -> V_179 , F_100 ( V_168 ) ) ;
V_177:
F_112 ( V_2 -> V_9 ) ;
V_175:
F_113 ( V_32 ) ;
F_93 ( V_34 , NULL ) ;
return error ;
}
static int T_7 F_114 ( struct V_163 * V_34 )
{
struct V_164 * V_32 = F_115 ( V_34 ) ;
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_167 * V_168 ;
F_74 ( & V_2 -> V_54 ) ;
V_2 -> V_55 = false ;
F_76 ( & V_2 -> V_54 ) ;
F_108 ( V_2 -> V_59 ) ;
F_74 ( & V_2 -> V_54 ) ;
while ( ! F_75 ( & V_2 -> V_58 ) ) {
struct V_44 * V_45 ;
V_45 = F_77 ( & V_2 -> V_58 ,
struct V_44 , V_57 ) ;
F_78 ( & V_45 -> V_57 ) ;
V_45 -> V_52 = - V_56 ;
F_76 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_142 ) ;
F_74 ( & V_2 -> V_54 ) ;
}
F_76 ( & V_2 -> V_54 ) ;
F_90 ( V_2 ) ;
F_109 ( V_2 -> V_143 , V_2 ) ;
F_110 ( V_2 -> V_5 ) ;
V_168 = F_98 ( V_34 , V_178 , 0 ) ;
F_111 ( V_168 -> V_179 , F_100 ( V_168 ) ) ;
F_112 ( V_2 -> V_9 ) ;
F_93 ( V_34 , NULL ) ;
F_116 ( V_32 ) ;
return 0 ;
}
