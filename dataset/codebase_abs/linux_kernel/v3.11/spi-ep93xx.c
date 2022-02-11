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
V_16 = F_19 ( V_6 ) ;
if ( ! V_16 ) {
F_22 ( & V_2 -> V_33 -> V_34 , L_1 ,
V_6 -> V_35 ) ;
V_16 = F_23 ( sizeof( * V_16 ) , V_36 ) ;
if ( ! V_16 )
return - V_37 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_30 = V_6 -> V_38 ;
if ( V_16 -> V_30 && V_16 -> V_30 -> V_39 ) {
int V_40 = V_16 -> V_30 -> V_39 ( V_6 ) ;
if ( V_40 ) {
F_24 ( V_16 ) ;
return V_40 ;
}
}
F_25 ( V_6 , V_16 ) ;
}
if ( V_6 -> V_41 != V_16 -> V_17 ) {
int V_8 ;
V_8 = F_15 ( V_2 , V_16 , V_6 -> V_41 ) ;
if ( V_8 != 0 ) {
F_25 ( V_6 , NULL ) ;
F_24 ( V_16 ) ;
return V_8 ;
}
V_16 -> V_17 = V_6 -> V_41 ;
}
V_16 -> V_42 = F_26 ( V_6 -> V_43 ) ;
F_18 ( V_6 , false ) ;
return 0 ;
}
static int F_27 ( struct V_26 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_46 * V_47 ;
unsigned long V_48 ;
if ( ! V_45 || ! V_45 -> V_49 )
return - V_25 ;
F_28 (t, &msg->transfers, transfer_list) {
if ( V_47 -> V_50 && V_47 -> V_50 < V_2 -> V_21 )
return - V_25 ;
}
V_45 -> V_51 = NULL ;
V_45 -> V_52 = 0 ;
V_45 -> V_53 = 0 ;
F_29 ( & V_2 -> V_54 , V_48 ) ;
if ( ! V_2 -> V_55 ) {
F_30 ( & V_2 -> V_54 , V_48 ) ;
return - V_56 ;
}
F_31 ( & V_45 -> V_57 , & V_2 -> V_58 ) ;
F_32 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_30 ( & V_2 -> V_54 , V_48 ) ;
return 0 ;
}
static void F_33 ( struct V_26 * V_6 )
{
struct V_15 * V_16 ;
V_16 = F_19 ( V_6 ) ;
if ( V_16 ) {
if ( V_16 -> V_30 && V_16 -> V_30 -> V_61 )
V_16 -> V_30 -> V_61 ( V_6 ) ;
F_25 ( V_6 , NULL ) ;
F_24 ( V_16 ) ;
}
}
static void F_34 ( const struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
T_1 V_62 ;
V_62 = V_16 -> V_23 << V_63 ;
V_62 |= ( V_16 -> V_6 -> V_28 & ( V_64 | V_65 ) ) << V_66 ;
V_62 |= V_16 -> V_42 ;
F_22 ( & V_2 -> V_33 -> V_34 , L_2 ,
V_16 -> V_6 -> V_28 , V_16 -> V_24 , V_16 -> V_23 , V_16 -> V_42 ) ;
F_22 ( & V_2 -> V_33 -> V_34 , L_3 , V_62 ) ;
F_1 ( V_2 , V_67 , V_16 -> V_24 ) ;
F_5 ( V_2 , V_68 , V_62 ) ;
}
static inline int V_43 ( const struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
return V_47 -> V_43 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_43 ( V_2 ) > 8 ) {
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
static void F_36 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_43 ( V_2 ) > 8 ) {
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
static int F_37 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
while ( ( F_3 ( V_2 , V_77 ) & V_78 ) ) {
F_36 ( V_2 , V_47 ) ;
V_2 -> V_79 -- ;
}
while ( V_2 -> V_79 < V_80 && V_2 -> V_72 < V_47 -> V_81 ) {
F_35 ( V_2 , V_47 ) ;
V_2 -> V_79 ++ ;
}
if ( V_2 -> V_76 == V_47 -> V_81 )
return 0 ;
return - V_82 ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_39 ( & V_2 -> V_83 ) ;
}
}
static struct V_84 *
F_40 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_46 * V_47 = V_2 -> V_69 -> V_51 ;
struct V_84 * V_87 ;
enum V_88 V_89 ;
struct V_90 V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
const void * V_98 , * V_99 ;
T_3 V_81 = V_47 -> V_81 ;
int V_100 , V_40 , V_101 ;
if ( V_43 ( V_2 ) > 8 )
V_89 = V_102 ;
else
V_89 = V_103 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_104 = V_86 ;
if ( V_86 == V_105 ) {
V_97 = V_2 -> V_106 ;
V_98 = V_47 -> V_75 ;
V_95 = & V_2 -> V_107 ;
V_91 . V_108 = V_2 -> V_109 ;
V_91 . V_110 = V_89 ;
} else {
V_97 = V_2 -> V_111 ;
V_98 = V_47 -> V_71 ;
V_95 = & V_2 -> V_112 ;
V_91 . V_113 = V_2 -> V_109 ;
V_91 . V_114 = V_89 ;
}
V_40 = F_41 ( V_97 , & V_91 ) ;
if ( V_40 )
return F_42 ( V_40 ) ;
V_101 = F_43 ( V_81 , V_115 ) ;
if ( V_101 != V_95 -> V_101 ) {
F_44 ( V_95 ) ;
V_40 = F_45 ( V_95 , V_101 , V_36 ) ;
if ( V_40 )
return F_42 ( V_40 ) ;
}
V_99 = V_98 ;
F_46 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_116 = F_47 ( T_3 , V_81 , V_115 ) ;
if ( V_98 ) {
F_48 ( V_93 , F_49 ( V_99 ) , V_116 ,
F_50 ( V_99 ) ) ;
} else {
F_48 ( V_93 , F_49 ( V_2 -> V_117 ) ,
V_116 , 0 ) ;
}
V_99 += V_116 ;
V_81 -= V_116 ;
}
if ( F_51 ( V_81 ) ) {
F_52 ( & V_2 -> V_33 -> V_34 , L_4 , V_81 ) ;
return F_42 ( - V_25 ) ;
}
V_101 = F_53 ( V_97 -> V_118 -> V_34 , V_95 -> V_119 , V_95 -> V_101 , V_86 ) ;
if ( ! V_101 )
return F_42 ( - V_37 ) ;
V_87 = F_54 ( V_97 , V_95 -> V_119 , V_101 , V_86 , V_120 ) ;
if ( ! V_87 ) {
F_55 ( V_97 -> V_118 -> V_34 , V_95 -> V_119 , V_95 -> V_101 , V_86 ) ;
return F_42 ( - V_37 ) ;
}
return V_87 ;
}
static void F_56 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
struct V_96 * V_97 ;
struct V_94 * V_95 ;
if ( V_86 == V_105 ) {
V_97 = V_2 -> V_106 ;
V_95 = & V_2 -> V_107 ;
} else {
V_97 = V_2 -> V_111 ;
V_95 = & V_2 -> V_112 ;
}
F_55 ( V_97 -> V_118 -> V_34 , V_95 -> V_119 , V_95 -> V_101 , V_86 ) ;
}
static void F_57 ( void * V_121 )
{
V_49 ( V_121 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_84 * V_122 , * V_87 ;
V_122 = F_40 ( V_2 , V_105 ) ;
if ( F_59 ( V_122 ) ) {
F_60 ( & V_2 -> V_33 -> V_34 , L_5 , F_61 ( V_122 ) ) ;
V_45 -> V_52 = F_61 ( V_122 ) ;
return;
}
V_87 = F_40 ( V_2 , V_123 ) ;
if ( F_59 ( V_87 ) ) {
F_56 ( V_2 , V_105 ) ;
F_60 ( & V_2 -> V_33 -> V_34 , L_6 , F_61 ( V_122 ) ) ;
V_45 -> V_52 = F_61 ( V_87 ) ;
return;
}
V_122 -> V_124 = F_57 ;
V_122 -> V_121 = & V_2 -> V_83 ;
F_62 ( V_122 ) ;
F_62 ( V_87 ) ;
F_63 ( V_2 -> V_106 ) ;
F_63 ( V_2 -> V_111 ) ;
F_39 ( & V_2 -> V_83 ) ;
F_56 ( V_2 , V_123 ) ;
F_56 ( V_2 , V_105 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 = F_19 ( V_45 -> V_6 ) ;
V_45 -> V_51 = V_47 ;
if ( V_47 -> V_50 || V_47 -> V_43 ) {
struct V_15 V_125 = * V_16 ;
if ( V_47 -> V_50 ) {
int V_8 ;
V_8 = F_15 ( V_2 , & V_125 ,
V_47 -> V_50 ) ;
if ( V_8 ) {
F_60 ( & V_2 -> V_33 -> V_34 ,
L_7 ) ;
V_45 -> V_52 = V_8 ;
return;
}
}
if ( V_47 -> V_43 )
V_125 . V_42 = F_26 ( V_47 -> V_43 ) ;
F_34 ( V_2 , & V_125 ) ;
}
V_2 -> V_76 = 0 ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_106 && V_47 -> V_81 > V_80 )
F_58 ( V_2 ) ;
else
F_38 ( V_2 ) ;
if ( V_45 -> V_52 )
return;
V_45 -> V_53 += V_47 -> V_81 ;
if ( V_47 -> V_126 ) {
F_65 ( V_127 ) ;
F_66 ( F_67 ( V_47 -> V_126 ) ) ;
}
if ( V_47 -> V_128 ) {
if ( ! F_68 ( & V_47 -> V_129 , & V_45 -> V_130 ) ) {
F_18 ( V_45 -> V_6 , false ) ;
F_69 () ;
F_18 ( V_45 -> V_6 , true ) ;
}
}
if ( V_47 -> V_50 || V_47 -> V_43 )
F_34 ( V_2 , V_16 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned long V_131 ;
struct V_46 * V_47 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_60 ( & V_2 -> V_33 -> V_34 , L_8 ) ;
V_45 -> V_52 = V_8 ;
return;
}
V_131 = V_132 + F_71 ( V_133 ) ;
while ( F_7 ( V_2 , V_77 ) & V_78 ) {
if ( F_72 ( V_132 , V_131 ) ) {
F_52 ( & V_2 -> V_33 -> V_34 ,
L_9 ) ;
V_45 -> V_52 = - V_134 ;
return;
}
F_7 ( V_2 , V_73 ) ;
}
V_2 -> V_79 = 0 ;
F_34 ( V_2 , F_19 ( V_45 -> V_6 ) ) ;
F_18 ( V_45 -> V_6 , true ) ;
F_28 (t, &msg->transfers, transfer_list) {
F_64 ( V_2 , V_45 , V_47 ) ;
if ( V_45 -> V_52 )
break;
}
F_18 ( V_45 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static void F_73 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_74 ( V_136 ) ;
struct V_44 * V_45 ;
F_75 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 || V_2 -> V_69 ||
F_76 ( & V_2 -> V_58 ) ) {
F_77 ( & V_2 -> V_54 ) ;
return;
}
V_45 = F_78 ( & V_2 -> V_58 , struct V_44 , V_57 ) ;
F_79 ( & V_45 -> V_57 ) ;
V_2 -> V_69 = V_45 ;
F_77 ( & V_2 -> V_54 ) ;
F_70 ( V_2 , V_45 ) ;
F_75 ( & V_2 -> V_54 ) ;
V_2 -> V_69 = NULL ;
if ( V_2 -> V_55 && ! F_76 ( & V_2 -> V_58 ) )
F_32 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_77 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_137 ) ;
}
static T_4 F_80 ( int V_138 , void * V_139 )
{
struct V_1 * V_2 = V_139 ;
T_2 V_140 = F_3 ( V_2 , V_141 ) ;
if ( F_81 ( V_140 & V_142 ) ) {
F_1 ( V_2 , V_143 , 0 ) ;
F_52 ( & V_2 -> V_33 -> V_34 ,
L_10 ) ;
V_2 -> V_69 -> V_52 = - V_144 ;
} else {
if ( F_37 ( V_2 ) ) {
return V_145 ;
}
}
F_14 ( V_2 ) ;
V_49 ( & V_2 -> V_83 ) ;
return V_145 ;
}
static bool F_82 ( struct V_96 * V_97 , void * V_146 )
{
if ( F_83 ( V_97 ) )
return false ;
V_97 -> V_147 = V_146 ;
return true ;
}
static int F_84 ( struct V_1 * V_2 )
{
T_5 V_148 ;
int V_40 ;
V_2 -> V_117 = ( void * ) F_85 ( V_36 ) ;
if ( ! V_2 -> V_117 )
return - V_37 ;
F_86 ( V_148 ) ;
F_87 ( V_149 , V_148 ) ;
V_2 -> V_150 . V_151 = V_152 ;
V_2 -> V_150 . V_104 = V_105 ;
V_2 -> V_150 . V_153 = L_11 ;
V_2 -> V_106 = F_88 ( V_148 , F_82 ,
& V_2 -> V_150 ) ;
if ( ! V_2 -> V_106 ) {
V_40 = - V_154 ;
goto V_155;
}
V_2 -> V_156 . V_151 = V_152 ;
V_2 -> V_156 . V_104 = V_123 ;
V_2 -> V_156 . V_153 = L_12 ;
V_2 -> V_111 = F_88 ( V_148 , F_82 ,
& V_2 -> V_156 ) ;
if ( ! V_2 -> V_111 ) {
V_40 = - V_154 ;
goto V_157;
}
return 0 ;
V_157:
F_89 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_155:
F_90 ( ( unsigned long ) V_2 -> V_117 ) ;
return V_40 ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_106 ) {
F_89 ( V_2 -> V_106 ) ;
F_44 ( & V_2 -> V_107 ) ;
}
if ( V_2 -> V_111 ) {
F_89 ( V_2 -> V_111 ) ;
F_44 ( & V_2 -> V_112 ) ;
}
if ( V_2 -> V_117 )
F_90 ( ( unsigned long ) V_2 -> V_117 ) ;
}
static int F_92 ( struct V_158 * V_33 )
{
struct V_159 * V_32 ;
struct V_160 * V_161 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
int V_138 ;
int error ;
V_161 = V_33 -> V_34 . V_164 ;
V_32 = F_93 ( & V_33 -> V_34 , sizeof( * V_2 ) ) ;
if ( ! V_32 ) {
F_60 ( & V_33 -> V_34 , L_13 ) ;
return - V_37 ;
}
V_32 -> V_39 = F_20 ;
V_32 -> V_165 = F_27 ;
V_32 -> V_61 = F_33 ;
V_32 -> V_166 = V_33 -> V_167 ;
V_32 -> V_168 = V_161 -> V_168 ;
V_32 -> V_169 = V_65 | V_64 | V_29 ;
V_32 -> V_170 = F_94 ( 4 , 16 ) ;
F_95 ( V_33 , V_32 ) ;
V_2 = F_21 ( V_32 ) ;
V_2 -> V_9 = F_96 ( & V_33 -> V_34 , NULL ) ;
if ( F_59 ( V_2 -> V_9 ) ) {
F_60 ( & V_33 -> V_34 , L_14 ) ;
error = F_61 ( V_2 -> V_9 ) ;
goto V_171;
}
F_97 ( & V_2 -> V_54 ) ;
F_98 ( & V_2 -> V_83 ) ;
V_2 -> V_22 = F_16 ( V_2 -> V_9 ) / 2 ;
V_2 -> V_21 = F_16 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_33 = V_33 ;
V_138 = F_99 ( V_33 , 0 ) ;
if ( V_138 < 0 ) {
error = - V_172 ;
F_60 ( & V_33 -> V_34 , L_15 ) ;
goto V_173;
}
V_163 = F_100 ( V_33 , V_174 , 0 ) ;
if ( ! V_163 ) {
F_60 ( & V_33 -> V_34 , L_16 ) ;
error = - V_154 ;
goto V_173;
}
V_2 -> V_109 = V_163 -> V_175 + V_73 ;
V_2 -> V_5 = F_101 ( & V_33 -> V_34 , V_163 ) ;
if ( F_59 ( V_2 -> V_5 ) ) {
error = F_61 ( V_2 -> V_5 ) ;
goto V_173;
}
error = F_102 ( & V_33 -> V_34 , V_138 , F_80 ,
0 , L_17 , V_2 ) ;
if ( error ) {
F_60 ( & V_33 -> V_34 , L_18 ) ;
goto V_173;
}
if ( V_161 -> V_176 && F_84 ( V_2 ) )
F_52 ( & V_33 -> V_34 , L_19 ) ;
V_2 -> V_59 = F_103 ( L_20 ) ;
if ( ! V_2 -> V_59 ) {
F_60 ( & V_33 -> V_34 , L_21 ) ;
error = - V_37 ;
goto V_177;
}
F_104 ( & V_2 -> V_60 , F_73 ) ;
F_105 ( & V_2 -> V_58 ) ;
V_2 -> V_55 = true ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_106 ( V_32 ) ;
if ( error ) {
F_60 ( & V_33 -> V_34 , L_22 ) ;
goto V_178;
}
F_107 ( & V_33 -> V_34 , L_23 ,
( unsigned long ) V_163 -> V_175 , V_138 ) ;
return 0 ;
V_178:
F_108 ( V_2 -> V_59 ) ;
V_177:
F_91 ( V_2 ) ;
V_173:
F_109 ( V_2 -> V_9 ) ;
V_171:
F_110 ( V_32 ) ;
return error ;
}
static int F_111 ( struct V_158 * V_33 )
{
struct V_159 * V_32 = F_112 ( V_33 ) ;
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_75 ( & V_2 -> V_54 ) ;
V_2 -> V_55 = false ;
F_77 ( & V_2 -> V_54 ) ;
F_108 ( V_2 -> V_59 ) ;
F_75 ( & V_2 -> V_54 ) ;
while ( ! F_76 ( & V_2 -> V_58 ) ) {
struct V_44 * V_45 ;
V_45 = F_78 ( & V_2 -> V_58 ,
struct V_44 , V_57 ) ;
F_79 ( & V_45 -> V_57 ) ;
V_45 -> V_52 = - V_56 ;
F_77 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_137 ) ;
F_75 ( & V_2 -> V_54 ) ;
}
F_77 ( & V_2 -> V_54 ) ;
F_91 ( V_2 ) ;
F_109 ( V_2 -> V_9 ) ;
F_113 ( V_32 ) ;
return 0 ;
}
