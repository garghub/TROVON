static void F_1 ( const struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_2 F_3 ( const struct V_1 * V_6 , T_1 V_3 )
{
return F_4 ( V_6 -> V_5 + V_3 ) ;
}
static void F_5 ( const struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_7 ( const struct V_1 * V_6 , T_1 V_3 )
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
unsigned long V_15 ,
T_2 * V_16 , T_2 * V_17 )
{
unsigned long V_18 = F_16 ( V_2 -> V_9 ) ;
int V_19 , V_20 ;
V_15 = F_17 ( V_15 , V_2 -> V_21 , V_2 -> V_22 ) ;
for ( V_19 = 2 ; V_19 <= 254 ; V_19 += 2 ) {
for ( V_20 = 0 ; V_20 <= 255 ; V_20 ++ ) {
if ( ( V_18 / ( V_19 * ( V_20 + 1 ) ) ) <= V_15 ) {
* V_17 = ( T_2 ) V_20 ;
* V_16 = ( T_2 ) V_19 ;
return 0 ;
}
}
}
return - V_23 ;
}
static void F_18 ( struct V_24 * V_6 , bool V_25 )
{
struct V_26 * V_27 = F_19 ( V_6 ) ;
int V_4 = ( V_6 -> V_28 & V_29 ) ? V_25 : ! V_25 ;
if ( V_27 -> V_30 && V_27 -> V_30 -> V_31 )
V_27 -> V_30 -> V_31 ( V_6 , V_4 ) ;
}
static int F_20 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_26 * V_27 ;
V_27 = F_19 ( V_6 ) ;
if ( ! V_27 ) {
F_22 ( & V_2 -> V_33 -> V_34 , L_1 ,
V_6 -> V_35 ) ;
V_27 = F_23 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
return - V_37 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_30 = V_6 -> V_38 ;
if ( V_27 -> V_30 && V_27 -> V_30 -> V_39 ) {
int V_40 = V_27 -> V_30 -> V_39 ( V_6 ) ;
if ( V_40 ) {
F_24 ( V_27 ) ;
return V_40 ;
}
}
F_25 ( V_6 , V_27 ) ;
}
F_18 ( V_6 , false ) ;
return 0 ;
}
static void F_26 ( struct V_24 * V_6 )
{
struct V_26 * V_27 ;
V_27 = F_19 ( V_6 ) ;
if ( V_27 ) {
if ( V_27 -> V_30 && V_27 -> V_30 -> V_41 )
V_27 -> V_30 -> V_41 ( V_6 ) ;
F_25 ( V_6 , NULL ) ;
F_24 ( V_27 ) ;
}
}
static int F_27 ( const struct V_1 * V_2 ,
const struct V_26 * V_27 ,
T_3 V_42 , T_2 V_43 )
{
T_2 V_44 = F_28 ( V_43 ) ;
T_2 V_16 = 0 ;
T_2 V_17 = 0 ;
T_1 V_45 ;
int V_8 ;
V_8 = F_15 ( V_2 , V_42 , & V_16 , & V_17 ) ;
if ( V_8 )
return V_8 ;
V_45 = V_17 << V_46 ;
V_45 |= ( V_27 -> V_6 -> V_28 & ( V_47 | V_48 ) ) << V_49 ;
V_45 |= V_44 ;
F_22 ( & V_2 -> V_33 -> V_34 , L_2 ,
V_27 -> V_6 -> V_28 , V_16 , V_17 , V_44 ) ;
F_22 ( & V_2 -> V_33 -> V_34 , L_3 , V_45 ) ;
F_1 ( V_2 , V_50 , V_16 ) ;
F_5 ( V_2 , V_51 , V_45 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
if ( V_53 -> V_43 > 8 ) {
T_1 V_54 = 0 ;
if ( V_53 -> V_55 )
V_54 = ( ( T_1 * ) V_53 -> V_55 ) [ V_2 -> V_56 ] ;
F_5 ( V_2 , V_57 , V_54 ) ;
V_2 -> V_56 += sizeof( V_54 ) ;
} else {
T_2 V_54 = 0 ;
if ( V_53 -> V_55 )
V_54 = ( ( T_2 * ) V_53 -> V_55 ) [ V_2 -> V_56 ] ;
F_1 ( V_2 , V_57 , V_54 ) ;
V_2 -> V_56 += sizeof( V_54 ) ;
}
}
static void F_30 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
if ( V_53 -> V_43 > 8 ) {
T_1 V_58 ;
V_58 = F_7 ( V_2 , V_57 ) ;
if ( V_53 -> V_59 )
( ( T_1 * ) V_53 -> V_59 ) [ V_2 -> V_60 ] = V_58 ;
V_2 -> V_60 += sizeof( V_58 ) ;
} else {
T_2 V_58 ;
V_58 = F_3 ( V_2 , V_57 ) ;
if ( V_53 -> V_59 )
( ( T_2 * ) V_53 -> V_59 ) [ V_2 -> V_60 ] = V_58 ;
V_2 -> V_60 += sizeof( V_58 ) ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
struct V_52 * V_53 = V_62 -> V_64 ;
while ( ( F_3 ( V_2 , V_65 ) & V_66 ) ) {
F_30 ( V_2 , V_53 ) ;
V_2 -> V_67 -- ;
}
while ( V_2 -> V_67 < V_68 && V_2 -> V_56 < V_53 -> V_69 ) {
F_29 ( V_2 , V_53 ) ;
V_2 -> V_67 ++ ;
}
if ( V_2 -> V_60 == V_53 -> V_69 )
return 0 ;
return - V_70 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( F_31 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_33 ( & V_2 -> V_71 ) ;
}
}
static struct V_72 *
F_34 ( struct V_1 * V_2 , enum V_73 V_74 )
{
struct V_52 * V_53 = V_2 -> V_63 -> V_64 ;
struct V_72 * V_75 ;
enum V_76 V_77 ;
struct V_78 V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
const void * V_86 , * V_87 ;
T_4 V_69 = V_53 -> V_69 ;
int V_88 , V_40 , V_89 ;
if ( V_53 -> V_43 > 8 )
V_77 = V_90 ;
else
V_77 = V_91 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_92 = V_74 ;
if ( V_74 == V_93 ) {
V_85 = V_2 -> V_94 ;
V_86 = V_53 -> V_59 ;
V_83 = & V_2 -> V_95 ;
V_79 . V_96 = V_2 -> V_97 ;
V_79 . V_98 = V_77 ;
} else {
V_85 = V_2 -> V_99 ;
V_86 = V_53 -> V_55 ;
V_83 = & V_2 -> V_100 ;
V_79 . V_101 = V_2 -> V_97 ;
V_79 . V_102 = V_77 ;
}
V_40 = F_35 ( V_85 , & V_79 ) ;
if ( V_40 )
return F_36 ( V_40 ) ;
V_89 = F_37 ( V_69 , V_103 ) ;
if ( V_89 != V_83 -> V_89 ) {
F_38 ( V_83 ) ;
V_40 = F_39 ( V_83 , V_89 , V_36 ) ;
if ( V_40 )
return F_36 ( V_40 ) ;
}
V_87 = V_86 ;
F_40 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_104 = F_41 ( T_4 , V_69 , V_103 ) ;
if ( V_86 ) {
F_42 ( V_81 , F_43 ( V_87 ) , V_104 ,
F_44 ( V_87 ) ) ;
} else {
F_42 ( V_81 , F_43 ( V_2 -> V_105 ) ,
V_104 , 0 ) ;
}
V_87 += V_104 ;
V_69 -= V_104 ;
}
if ( F_45 ( V_69 ) ) {
F_46 ( & V_2 -> V_33 -> V_34 , L_4 , V_69 ) ;
return F_36 ( - V_23 ) ;
}
V_89 = F_47 ( V_85 -> V_106 -> V_34 , V_83 -> V_107 , V_83 -> V_89 , V_74 ) ;
if ( ! V_89 )
return F_36 ( - V_37 ) ;
V_75 = F_48 ( V_85 , V_83 -> V_107 , V_89 , V_74 , V_108 ) ;
if ( ! V_75 ) {
F_49 ( V_85 -> V_106 -> V_34 , V_83 -> V_107 , V_83 -> V_89 , V_74 ) ;
return F_36 ( - V_37 ) ;
}
return V_75 ;
}
static void F_50 ( struct V_1 * V_2 ,
enum V_73 V_74 )
{
struct V_84 * V_85 ;
struct V_82 * V_83 ;
if ( V_74 == V_93 ) {
V_85 = V_2 -> V_94 ;
V_83 = & V_2 -> V_95 ;
} else {
V_85 = V_2 -> V_99 ;
V_83 = & V_2 -> V_100 ;
}
F_49 ( V_85 -> V_106 -> V_34 , V_83 -> V_107 , V_83 -> V_89 , V_74 ) ;
}
static void F_51 ( void * V_109 )
{
F_52 ( V_109 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
struct V_72 * V_110 , * V_75 ;
V_110 = F_34 ( V_2 , V_93 ) ;
if ( F_54 ( V_110 ) ) {
F_55 ( & V_2 -> V_33 -> V_34 , L_5 , F_56 ( V_110 ) ) ;
V_62 -> V_111 = F_56 ( V_110 ) ;
return;
}
V_75 = F_34 ( V_2 , V_112 ) ;
if ( F_54 ( V_75 ) ) {
F_50 ( V_2 , V_93 ) ;
F_55 ( & V_2 -> V_33 -> V_34 , L_6 , F_56 ( V_110 ) ) ;
V_62 -> V_111 = F_56 ( V_75 ) ;
return;
}
V_110 -> V_113 = F_51 ;
V_110 -> V_109 = & V_2 -> V_71 ;
F_57 ( V_110 ) ;
F_57 ( V_75 ) ;
F_58 ( V_2 -> V_94 ) ;
F_58 ( V_2 -> V_99 ) ;
F_33 ( & V_2 -> V_71 ) ;
F_50 ( V_2 , V_112 ) ;
F_50 ( V_2 , V_93 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_52 * V_53 )
{
struct V_26 * V_27 = F_19 ( V_62 -> V_6 ) ;
int V_8 ;
V_62 -> V_64 = V_53 ;
V_8 = F_27 ( V_2 , V_27 , V_53 -> V_42 , V_53 -> V_43 ) ;
if ( V_8 ) {
F_55 ( & V_2 -> V_33 -> V_34 ,
L_7 ) ;
V_62 -> V_111 = V_8 ;
return;
}
V_2 -> V_60 = 0 ;
V_2 -> V_56 = 0 ;
if ( V_2 -> V_94 && V_53 -> V_69 > V_68 )
F_53 ( V_2 ) ;
else
F_32 ( V_2 ) ;
if ( V_62 -> V_111 )
return;
V_62 -> V_114 += V_53 -> V_69 ;
if ( V_53 -> V_115 ) {
F_60 ( V_116 ) ;
F_61 ( F_62 ( V_53 -> V_115 ) ) ;
}
if ( V_53 -> V_117 ) {
if ( ! F_63 ( & V_53 -> V_118 , & V_62 -> V_119 ) ) {
F_18 ( V_62 -> V_6 , false ) ;
F_64 () ;
F_18 ( V_62 -> V_6 , true ) ;
}
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
unsigned long V_120 ;
struct V_52 * V_53 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_55 ( & V_2 -> V_33 -> V_34 , L_8 ) ;
V_62 -> V_111 = V_8 ;
return;
}
V_120 = V_121 + F_66 ( V_122 ) ;
while ( F_7 ( V_2 , V_65 ) & V_66 ) {
if ( F_67 ( V_121 , V_120 ) ) {
F_46 ( & V_2 -> V_33 -> V_34 ,
L_9 ) ;
V_62 -> V_111 = - V_123 ;
return;
}
F_7 ( V_2 , V_57 ) ;
}
V_2 -> V_67 = 0 ;
F_18 ( V_62 -> V_6 , true ) ;
F_68 (t, &msg->transfers, transfer_list) {
F_59 ( V_2 , V_62 , V_53 ) ;
if ( V_62 -> V_111 )
break;
}
F_18 ( V_62 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static int F_69 ( struct V_124 * V_32 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_52 * V_53 ;
F_68 (t, &msg->transfers, transfer_list) {
if ( V_53 -> V_42 < V_2 -> V_21 )
return - V_23 ;
}
V_62 -> V_64 = NULL ;
V_62 -> V_111 = 0 ;
V_62 -> V_114 = 0 ;
V_2 -> V_63 = V_62 ;
F_65 ( V_2 , V_62 ) ;
V_2 -> V_63 = NULL ;
F_70 ( V_32 ) ;
return 0 ;
}
static T_5 F_71 ( int V_125 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
T_2 V_127 = F_3 ( V_2 , V_128 ) ;
if ( F_72 ( V_127 & V_129 ) ) {
F_1 ( V_2 , V_130 , 0 ) ;
F_46 ( & V_2 -> V_33 -> V_34 ,
L_10 ) ;
V_2 -> V_63 -> V_111 = - V_131 ;
} else {
if ( F_31 ( V_2 ) ) {
return V_132 ;
}
}
F_14 ( V_2 ) ;
F_52 ( & V_2 -> V_71 ) ;
return V_132 ;
}
static bool F_73 ( struct V_84 * V_85 , void * V_133 )
{
if ( F_74 ( V_85 ) )
return false ;
V_85 -> V_134 = V_133 ;
return true ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_6 V_135 ;
int V_40 ;
V_2 -> V_105 = ( void * ) F_76 ( V_36 ) ;
if ( ! V_2 -> V_105 )
return - V_37 ;
F_77 ( V_135 ) ;
F_78 ( V_136 , V_135 ) ;
V_2 -> V_137 . V_138 = V_139 ;
V_2 -> V_137 . V_92 = V_93 ;
V_2 -> V_137 . V_140 = L_11 ;
V_2 -> V_94 = F_79 ( V_135 , F_73 ,
& V_2 -> V_137 ) ;
if ( ! V_2 -> V_94 ) {
V_40 = - V_141 ;
goto V_142;
}
V_2 -> V_143 . V_138 = V_139 ;
V_2 -> V_143 . V_92 = V_112 ;
V_2 -> V_143 . V_140 = L_12 ;
V_2 -> V_99 = F_79 ( V_135 , F_73 ,
& V_2 -> V_143 ) ;
if ( ! V_2 -> V_99 ) {
V_40 = - V_141 ;
goto V_144;
}
return 0 ;
V_144:
F_80 ( V_2 -> V_94 ) ;
V_2 -> V_94 = NULL ;
V_142:
F_81 ( ( unsigned long ) V_2 -> V_105 ) ;
return V_40 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 ) {
F_80 ( V_2 -> V_94 ) ;
F_38 ( & V_2 -> V_95 ) ;
}
if ( V_2 -> V_99 ) {
F_80 ( V_2 -> V_99 ) ;
F_38 ( & V_2 -> V_100 ) ;
}
if ( V_2 -> V_105 )
F_81 ( ( unsigned long ) V_2 -> V_105 ) ;
}
static int F_83 ( struct V_145 * V_33 )
{
struct V_124 * V_32 ;
struct V_146 * V_147 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
int V_125 ;
int error ;
V_147 = F_84 ( & V_33 -> V_34 ) ;
V_125 = F_85 ( V_33 , 0 ) ;
if ( V_125 < 0 ) {
F_55 ( & V_33 -> V_34 , L_13 ) ;
return - V_150 ;
}
V_149 = F_86 ( V_33 , V_151 , 0 ) ;
if ( ! V_149 ) {
F_55 ( & V_33 -> V_34 , L_14 ) ;
return - V_141 ;
}
V_32 = F_87 ( & V_33 -> V_34 , sizeof( * V_2 ) ) ;
if ( ! V_32 )
return - V_37 ;
V_32 -> V_39 = F_20 ;
V_32 -> V_152 = F_69 ;
V_32 -> V_41 = F_26 ;
V_32 -> V_153 = V_33 -> V_154 ;
V_32 -> V_155 = V_147 -> V_155 ;
V_32 -> V_156 = V_48 | V_47 | V_29 ;
V_32 -> V_157 = F_88 ( 4 , 16 ) ;
F_89 ( V_33 , V_32 ) ;
V_2 = F_21 ( V_32 ) ;
V_2 -> V_9 = F_90 ( & V_33 -> V_34 , NULL ) ;
if ( F_54 ( V_2 -> V_9 ) ) {
F_55 ( & V_33 -> V_34 , L_15 ) ;
error = F_56 ( V_2 -> V_9 ) ;
goto V_158;
}
F_91 ( & V_2 -> V_71 ) ;
V_2 -> V_22 = F_16 ( V_2 -> V_9 ) / 2 ;
V_2 -> V_21 = F_16 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_97 = V_149 -> V_159 + V_57 ;
V_2 -> V_5 = F_92 ( & V_33 -> V_34 , V_149 ) ;
if ( F_54 ( V_2 -> V_5 ) ) {
error = F_56 ( V_2 -> V_5 ) ;
goto V_158;
}
error = F_93 ( & V_33 -> V_34 , V_125 , F_71 ,
0 , L_16 , V_2 ) ;
if ( error ) {
F_55 ( & V_33 -> V_34 , L_17 ) ;
goto V_158;
}
if ( V_147 -> V_160 && F_75 ( V_2 ) )
F_46 ( & V_33 -> V_34 , L_18 ) ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_94 ( V_32 ) ;
if ( error ) {
F_55 ( & V_33 -> V_34 , L_19 ) ;
goto V_161;
}
F_95 ( & V_33 -> V_34 , L_20 ,
( unsigned long ) V_149 -> V_159 , V_125 ) ;
return 0 ;
V_161:
F_82 ( V_2 ) ;
V_158:
F_96 ( V_32 ) ;
return error ;
}
static int F_97 ( struct V_145 * V_33 )
{
struct V_124 * V_32 = F_98 ( V_33 ) ;
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_82 ( V_2 ) ;
F_99 ( V_32 ) ;
return 0 ;
}
