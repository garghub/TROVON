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
T_3 V_15 , T_2 * V_16 , T_2 * V_17 )
{
struct V_18 * V_19 = F_16 ( V_2 -> V_20 ) ;
unsigned long V_21 = F_17 ( V_2 -> V_9 ) ;
int V_22 , V_23 ;
V_15 = F_18 ( V_15 , V_19 -> V_24 , V_19 -> V_25 ) ;
for ( V_22 = 2 ; V_22 <= 254 ; V_22 += 2 ) {
for ( V_23 = 0 ; V_23 <= 255 ; V_23 ++ ) {
if ( ( V_21 / ( V_22 * ( V_23 + 1 ) ) ) <= V_15 ) {
* V_17 = ( T_2 ) V_23 ;
* V_16 = ( T_2 ) V_22 ;
return 0 ;
}
}
}
return - V_26 ;
}
static void F_19 ( struct V_27 * V_6 , bool V_28 )
{
struct V_29 * V_30 = F_20 ( V_6 ) ;
int V_4 = ( V_6 -> V_31 & V_32 ) ? V_28 : ! V_28 ;
if ( V_30 -> V_33 && V_30 -> V_33 -> V_34 )
V_30 -> V_33 -> V_34 ( V_6 , V_4 ) ;
}
static int F_21 ( struct V_27 * V_6 )
{
struct V_1 * V_2 = F_22 ( V_6 -> V_19 ) ;
struct V_29 * V_30 ;
V_30 = F_20 ( V_6 ) ;
if ( ! V_30 ) {
F_23 ( & V_2 -> V_20 -> V_35 , L_1 ,
V_6 -> V_36 ) ;
V_30 = F_24 ( sizeof( * V_30 ) , V_37 ) ;
if ( ! V_30 )
return - V_38 ;
V_30 -> V_6 = V_6 ;
V_30 -> V_33 = V_6 -> V_39 ;
if ( V_30 -> V_33 && V_30 -> V_33 -> V_40 ) {
int V_41 = V_30 -> V_33 -> V_40 ( V_6 ) ;
if ( V_41 ) {
F_25 ( V_30 ) ;
return V_41 ;
}
}
F_26 ( V_6 , V_30 ) ;
}
F_19 ( V_6 , false ) ;
return 0 ;
}
static void F_27 ( struct V_27 * V_6 )
{
struct V_29 * V_30 ;
V_30 = F_20 ( V_6 ) ;
if ( V_30 ) {
if ( V_30 -> V_33 && V_30 -> V_33 -> V_42 )
V_30 -> V_33 -> V_42 ( V_6 ) ;
F_26 ( V_6 , NULL ) ;
F_25 ( V_30 ) ;
}
}
static int F_28 ( const struct V_1 * V_2 ,
const struct V_29 * V_30 ,
T_3 V_43 , T_2 V_44 )
{
T_2 V_45 = F_29 ( V_44 ) ;
T_2 V_16 = 0 ;
T_2 V_17 = 0 ;
T_1 V_46 ;
int V_8 ;
V_8 = F_15 ( V_2 , V_43 , & V_16 , & V_17 ) ;
if ( V_8 )
return V_8 ;
V_46 = V_17 << V_47 ;
V_46 |= ( V_30 -> V_6 -> V_31 & ( V_48 | V_49 ) ) << V_50 ;
V_46 |= V_45 ;
F_23 ( & V_2 -> V_20 -> V_35 , L_2 ,
V_30 -> V_6 -> V_31 , V_16 , V_17 , V_45 ) ;
F_23 ( & V_2 -> V_20 -> V_35 , L_3 , V_46 ) ;
F_1 ( V_2 , V_51 , V_16 ) ;
F_5 ( V_2 , V_52 , V_46 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
if ( V_54 -> V_44 > 8 ) {
T_1 V_55 = 0 ;
if ( V_54 -> V_56 )
V_55 = ( ( T_1 * ) V_54 -> V_56 ) [ V_2 -> V_57 ] ;
F_5 ( V_2 , V_58 , V_55 ) ;
V_2 -> V_57 += sizeof( V_55 ) ;
} else {
T_2 V_55 = 0 ;
if ( V_54 -> V_56 )
V_55 = ( ( T_2 * ) V_54 -> V_56 ) [ V_2 -> V_57 ] ;
F_1 ( V_2 , V_58 , V_55 ) ;
V_2 -> V_57 += sizeof( V_55 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
if ( V_54 -> V_44 > 8 ) {
T_1 V_59 ;
V_59 = F_7 ( V_2 , V_58 ) ;
if ( V_54 -> V_60 )
( ( T_1 * ) V_54 -> V_60 ) [ V_2 -> V_61 ] = V_59 ;
V_2 -> V_61 += sizeof( V_59 ) ;
} else {
T_2 V_59 ;
V_59 = F_3 ( V_2 , V_58 ) ;
if ( V_54 -> V_60 )
( ( T_2 * ) V_54 -> V_60 ) [ V_2 -> V_61 ] = V_59 ;
V_2 -> V_61 += sizeof( V_59 ) ;
}
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_64 ;
struct V_53 * V_54 = V_63 -> V_65 ;
while ( ( F_3 ( V_2 , V_66 ) & V_67 ) ) {
F_31 ( V_2 , V_54 ) ;
V_2 -> V_68 -- ;
}
while ( V_2 -> V_68 < V_69 && V_2 -> V_57 < V_54 -> V_70 ) {
F_30 ( V_2 , V_54 ) ;
V_2 -> V_68 ++ ;
}
if ( V_2 -> V_61 == V_54 -> V_70 )
return 0 ;
return - V_71 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_34 ( & V_2 -> V_72 ) ;
}
}
static struct V_73 *
F_35 ( struct V_1 * V_2 , enum V_74 V_75 )
{
struct V_53 * V_54 = V_2 -> V_64 -> V_65 ;
struct V_73 * V_76 ;
enum V_77 V_78 ;
struct V_79 V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
const void * V_87 , * V_88 ;
T_4 V_70 = V_54 -> V_70 ;
int V_89 , V_41 , V_90 ;
if ( V_54 -> V_44 > 8 )
V_78 = V_91 ;
else
V_78 = V_92 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_93 = V_75 ;
if ( V_75 == V_94 ) {
V_86 = V_2 -> V_95 ;
V_87 = V_54 -> V_60 ;
V_84 = & V_2 -> V_96 ;
V_80 . V_97 = V_2 -> V_98 ;
V_80 . V_99 = V_78 ;
} else {
V_86 = V_2 -> V_100 ;
V_87 = V_54 -> V_56 ;
V_84 = & V_2 -> V_101 ;
V_80 . V_102 = V_2 -> V_98 ;
V_80 . V_103 = V_78 ;
}
V_41 = F_36 ( V_86 , & V_80 ) ;
if ( V_41 )
return F_37 ( V_41 ) ;
V_90 = F_38 ( V_70 , V_104 ) ;
if ( V_90 != V_84 -> V_90 ) {
F_39 ( V_84 ) ;
V_41 = F_40 ( V_84 , V_90 , V_37 ) ;
if ( V_41 )
return F_37 ( V_41 ) ;
}
V_88 = V_87 ;
F_41 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_105 = F_42 ( T_4 , V_70 , V_104 ) ;
if ( V_87 ) {
F_43 ( V_82 , F_44 ( V_88 ) , V_105 ,
F_45 ( V_88 ) ) ;
} else {
F_43 ( V_82 , F_44 ( V_2 -> V_106 ) ,
V_105 , 0 ) ;
}
V_88 += V_105 ;
V_70 -= V_105 ;
}
if ( F_46 ( V_70 ) ) {
F_47 ( & V_2 -> V_20 -> V_35 , L_4 , V_70 ) ;
return F_37 ( - V_26 ) ;
}
V_90 = F_48 ( V_86 -> V_107 -> V_35 , V_84 -> V_108 , V_84 -> V_90 , V_75 ) ;
if ( ! V_90 )
return F_37 ( - V_38 ) ;
V_76 = F_49 ( V_86 , V_84 -> V_108 , V_90 , V_75 , V_109 ) ;
if ( ! V_76 ) {
F_50 ( V_86 -> V_107 -> V_35 , V_84 -> V_108 , V_84 -> V_90 , V_75 ) ;
return F_37 ( - V_38 ) ;
}
return V_76 ;
}
static void F_51 ( struct V_1 * V_2 ,
enum V_74 V_75 )
{
struct V_85 * V_86 ;
struct V_83 * V_84 ;
if ( V_75 == V_94 ) {
V_86 = V_2 -> V_95 ;
V_84 = & V_2 -> V_96 ;
} else {
V_86 = V_2 -> V_100 ;
V_84 = & V_2 -> V_101 ;
}
F_50 ( V_86 -> V_107 -> V_35 , V_84 -> V_108 , V_84 -> V_90 , V_75 ) ;
}
static void F_52 ( void * V_110 )
{
F_53 ( V_110 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_64 ;
struct V_73 * V_111 , * V_76 ;
V_111 = F_35 ( V_2 , V_94 ) ;
if ( F_55 ( V_111 ) ) {
F_56 ( & V_2 -> V_20 -> V_35 , L_5 , F_57 ( V_111 ) ) ;
V_63 -> V_112 = F_57 ( V_111 ) ;
return;
}
V_76 = F_35 ( V_2 , V_113 ) ;
if ( F_55 ( V_76 ) ) {
F_51 ( V_2 , V_94 ) ;
F_56 ( & V_2 -> V_20 -> V_35 , L_6 , F_57 ( V_111 ) ) ;
V_63 -> V_112 = F_57 ( V_76 ) ;
return;
}
V_111 -> V_114 = F_52 ;
V_111 -> V_110 = & V_2 -> V_72 ;
F_58 ( V_111 ) ;
F_58 ( V_76 ) ;
F_59 ( V_2 -> V_95 ) ;
F_59 ( V_2 -> V_100 ) ;
F_34 ( & V_2 -> V_72 ) ;
F_51 ( V_2 , V_113 ) ;
F_51 ( V_2 , V_94 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_53 * V_54 )
{
struct V_29 * V_30 = F_20 ( V_63 -> V_6 ) ;
int V_8 ;
V_63 -> V_65 = V_54 ;
V_8 = F_28 ( V_2 , V_30 , V_54 -> V_43 , V_54 -> V_44 ) ;
if ( V_8 ) {
F_56 ( & V_2 -> V_20 -> V_35 ,
L_7 ) ;
V_63 -> V_112 = V_8 ;
return;
}
V_2 -> V_61 = 0 ;
V_2 -> V_57 = 0 ;
if ( V_2 -> V_95 && V_54 -> V_70 > V_69 )
F_54 ( V_2 ) ;
else
F_33 ( V_2 ) ;
if ( V_63 -> V_112 )
return;
V_63 -> V_115 += V_54 -> V_70 ;
if ( V_54 -> V_116 ) {
F_61 ( V_117 ) ;
F_62 ( F_63 ( V_54 -> V_116 ) ) ;
}
if ( V_54 -> V_118 ) {
if ( ! F_64 ( & V_54 -> V_119 , & V_63 -> V_120 ) ) {
F_19 ( V_63 -> V_6 , false ) ;
F_65 () ;
F_19 ( V_63 -> V_6 , true ) ;
}
}
}
static void F_66 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
unsigned long V_121 ;
struct V_53 * V_54 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_56 ( & V_2 -> V_20 -> V_35 , L_8 ) ;
V_63 -> V_112 = V_8 ;
return;
}
V_121 = V_122 + F_67 ( V_123 ) ;
while ( F_7 ( V_2 , V_66 ) & V_67 ) {
if ( F_68 ( V_122 , V_121 ) ) {
F_47 ( & V_2 -> V_20 -> V_35 ,
L_9 ) ;
V_63 -> V_112 = - V_124 ;
return;
}
F_7 ( V_2 , V_58 ) ;
}
V_2 -> V_68 = 0 ;
F_19 ( V_63 -> V_6 , true ) ;
F_69 (t, &msg->transfers, transfer_list) {
F_60 ( V_2 , V_63 , V_54 ) ;
if ( V_63 -> V_112 )
break;
}
F_19 ( V_63 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static int F_70 ( struct V_18 * V_19 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_22 ( V_19 ) ;
V_63 -> V_65 = NULL ;
V_63 -> V_112 = 0 ;
V_63 -> V_115 = 0 ;
V_2 -> V_64 = V_63 ;
F_66 ( V_2 , V_63 ) ;
V_2 -> V_64 = NULL ;
F_71 ( V_19 ) ;
return 0 ;
}
static T_5 F_72 ( int V_125 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
T_2 V_127 = F_3 ( V_2 , V_128 ) ;
if ( F_73 ( V_127 & V_129 ) ) {
F_1 ( V_2 , V_130 , 0 ) ;
F_47 ( & V_2 -> V_20 -> V_35 ,
L_10 ) ;
V_2 -> V_64 -> V_112 = - V_131 ;
} else {
if ( F_32 ( V_2 ) ) {
return V_132 ;
}
}
F_14 ( V_2 ) ;
F_53 ( & V_2 -> V_72 ) ;
return V_132 ;
}
static bool F_74 ( struct V_85 * V_86 , void * V_133 )
{
if ( F_75 ( V_86 ) )
return false ;
V_86 -> V_134 = V_133 ;
return true ;
}
static int F_76 ( struct V_1 * V_2 )
{
T_6 V_135 ;
int V_41 ;
V_2 -> V_106 = ( void * ) F_77 ( V_37 ) ;
if ( ! V_2 -> V_106 )
return - V_38 ;
F_78 ( V_135 ) ;
F_79 ( V_136 , V_135 ) ;
V_2 -> V_137 . V_138 = V_139 ;
V_2 -> V_137 . V_93 = V_94 ;
V_2 -> V_137 . V_140 = L_11 ;
V_2 -> V_95 = F_80 ( V_135 , F_74 ,
& V_2 -> V_137 ) ;
if ( ! V_2 -> V_95 ) {
V_41 = - V_141 ;
goto V_142;
}
V_2 -> V_143 . V_138 = V_139 ;
V_2 -> V_143 . V_93 = V_113 ;
V_2 -> V_143 . V_140 = L_12 ;
V_2 -> V_100 = F_80 ( V_135 , F_74 ,
& V_2 -> V_143 ) ;
if ( ! V_2 -> V_100 ) {
V_41 = - V_141 ;
goto V_144;
}
return 0 ;
V_144:
F_81 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
V_142:
F_82 ( ( unsigned long ) V_2 -> V_106 ) ;
return V_41 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 ) {
F_81 ( V_2 -> V_95 ) ;
F_39 ( & V_2 -> V_96 ) ;
}
if ( V_2 -> V_100 ) {
F_81 ( V_2 -> V_100 ) ;
F_39 ( & V_2 -> V_101 ) ;
}
if ( V_2 -> V_106 )
F_82 ( ( unsigned long ) V_2 -> V_106 ) ;
}
static int F_84 ( struct V_145 * V_20 )
{
struct V_18 * V_19 ;
struct V_146 * V_147 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
int V_125 ;
int error ;
V_147 = F_85 ( & V_20 -> V_35 ) ;
V_125 = F_86 ( V_20 , 0 ) ;
if ( V_125 < 0 ) {
F_56 ( & V_20 -> V_35 , L_13 ) ;
return - V_150 ;
}
V_149 = F_87 ( V_20 , V_151 , 0 ) ;
if ( ! V_149 ) {
F_56 ( & V_20 -> V_35 , L_14 ) ;
return - V_141 ;
}
V_19 = F_88 ( & V_20 -> V_35 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_38 ;
V_19 -> V_40 = F_21 ;
V_19 -> V_152 = F_70 ;
V_19 -> V_42 = F_27 ;
V_19 -> V_153 = V_20 -> V_154 ;
V_19 -> V_155 = V_147 -> V_155 ;
V_19 -> V_156 = V_49 | V_48 | V_32 ;
V_19 -> V_157 = F_89 ( 4 , 16 ) ;
F_90 ( V_20 , V_19 ) ;
V_2 = F_22 ( V_19 ) ;
V_2 -> V_9 = F_91 ( & V_20 -> V_35 , NULL ) ;
if ( F_55 ( V_2 -> V_9 ) ) {
F_56 ( & V_20 -> V_35 , L_15 ) ;
error = F_57 ( V_2 -> V_9 ) ;
goto V_158;
}
F_92 ( & V_2 -> V_72 ) ;
V_19 -> V_25 = F_17 ( V_2 -> V_9 ) / 2 ;
V_19 -> V_24 = F_17 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_98 = V_149 -> V_159 + V_58 ;
V_2 -> V_5 = F_93 ( & V_20 -> V_35 , V_149 ) ;
if ( F_55 ( V_2 -> V_5 ) ) {
error = F_57 ( V_2 -> V_5 ) ;
goto V_158;
}
error = F_94 ( & V_20 -> V_35 , V_125 , F_72 ,
0 , L_16 , V_2 ) ;
if ( error ) {
F_56 ( & V_20 -> V_35 , L_17 ) ;
goto V_158;
}
if ( V_147 -> V_160 && F_76 ( V_2 ) )
F_47 ( & V_20 -> V_35 , L_18 ) ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_95 ( & V_20 -> V_35 , V_19 ) ;
if ( error ) {
F_56 ( & V_20 -> V_35 , L_19 ) ;
goto V_161;
}
F_96 ( & V_20 -> V_35 , L_20 ,
( unsigned long ) V_149 -> V_159 , V_125 ) ;
return 0 ;
V_161:
F_83 ( V_2 ) ;
V_158:
F_97 ( V_19 ) ;
return error ;
}
static int F_98 ( struct V_145 * V_20 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
struct V_1 * V_2 = F_22 ( V_19 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
