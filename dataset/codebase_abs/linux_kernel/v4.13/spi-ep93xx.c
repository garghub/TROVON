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
if ( V_6 -> V_29 & V_30 )
V_28 = ! V_28 ;
if ( F_20 ( V_6 -> V_31 ) )
F_21 ( V_6 -> V_31 , ! V_28 ) ;
}
static int F_22 ( const struct V_1 * V_2 ,
struct V_27 * V_6 ,
struct V_32 * V_33 )
{
T_2 V_34 = F_23 ( V_33 -> V_35 ) ;
T_2 V_16 = 0 ;
T_2 V_17 = 0 ;
T_1 V_36 ;
int V_8 ;
V_8 = F_15 ( V_2 , V_33 -> V_37 ,
& V_16 , & V_17 ) ;
if ( V_8 )
return V_8 ;
V_36 = V_17 << V_38 ;
V_36 |= ( V_6 -> V_29 & ( V_39 | V_40 ) ) << V_41 ;
V_36 |= V_34 ;
F_24 ( & V_2 -> V_20 -> V_42 , L_1 ,
V_6 -> V_29 , V_16 , V_17 , V_34 ) ;
F_24 ( & V_2 -> V_20 -> V_42 , L_2 , V_36 ) ;
F_1 ( V_2 , V_43 , V_16 ) ;
F_5 ( V_2 , V_44 , V_36 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_32 * V_45 )
{
if ( V_45 -> V_35 > 8 ) {
T_1 V_46 = 0 ;
if ( V_45 -> V_47 )
V_46 = ( ( T_1 * ) V_45 -> V_47 ) [ V_2 -> V_48 ] ;
F_5 ( V_2 , V_49 , V_46 ) ;
V_2 -> V_48 += sizeof( V_46 ) ;
} else {
T_2 V_46 = 0 ;
if ( V_45 -> V_47 )
V_46 = ( ( T_2 * ) V_45 -> V_47 ) [ V_2 -> V_48 ] ;
F_1 ( V_2 , V_49 , V_46 ) ;
V_2 -> V_48 += sizeof( V_46 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_32 * V_45 )
{
if ( V_45 -> V_35 > 8 ) {
T_1 V_50 ;
V_50 = F_7 ( V_2 , V_49 ) ;
if ( V_45 -> V_51 )
( ( T_1 * ) V_45 -> V_51 ) [ V_2 -> V_52 ] = V_50 ;
V_2 -> V_52 += sizeof( V_50 ) ;
} else {
T_2 V_50 ;
V_50 = F_3 ( V_2 , V_49 ) ;
if ( V_45 -> V_51 )
( ( T_2 * ) V_45 -> V_51 ) [ V_2 -> V_52 ] = V_50 ;
V_2 -> V_52 += sizeof( V_50 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_55 ;
struct V_32 * V_45 = V_54 -> V_56 ;
while ( ( F_3 ( V_2 , V_57 ) & V_58 ) ) {
F_26 ( V_2 , V_45 ) ;
V_2 -> V_59 -- ;
}
while ( V_2 -> V_59 < V_60 && V_2 -> V_48 < V_45 -> V_61 ) {
F_25 ( V_2 , V_45 ) ;
V_2 -> V_59 ++ ;
}
if ( V_2 -> V_52 == V_45 -> V_61 )
return 0 ;
return - V_62 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( F_27 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_29 ( & V_2 -> V_63 ) ;
}
}
static struct V_64 *
F_30 ( struct V_1 * V_2 , enum V_65 V_66 )
{
struct V_32 * V_45 = V_2 -> V_55 -> V_56 ;
struct V_64 * V_67 ;
enum V_68 V_69 ;
struct V_70 V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
const void * V_78 , * V_79 ;
T_4 V_61 = V_45 -> V_61 ;
int V_80 , V_81 , V_82 ;
if ( V_45 -> V_35 > 8 )
V_69 = V_83 ;
else
V_69 = V_84 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_85 = V_66 ;
if ( V_66 == V_86 ) {
V_77 = V_2 -> V_87 ;
V_78 = V_45 -> V_51 ;
V_75 = & V_2 -> V_88 ;
V_71 . V_89 = V_2 -> V_90 ;
V_71 . V_91 = V_69 ;
} else {
V_77 = V_2 -> V_92 ;
V_78 = V_45 -> V_47 ;
V_75 = & V_2 -> V_93 ;
V_71 . V_94 = V_2 -> V_90 ;
V_71 . V_95 = V_69 ;
}
V_81 = F_31 ( V_77 , & V_71 ) ;
if ( V_81 )
return F_32 ( V_81 ) ;
V_82 = F_33 ( V_61 , V_96 ) ;
if ( V_82 != V_75 -> V_82 ) {
F_34 ( V_75 ) ;
V_81 = F_35 ( V_75 , V_82 , V_97 ) ;
if ( V_81 )
return F_32 ( V_81 ) ;
}
V_79 = V_78 ;
F_36 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_98 = F_37 ( T_4 , V_61 , V_96 ) ;
if ( V_78 ) {
F_38 ( V_73 , F_39 ( V_79 ) , V_98 ,
F_40 ( V_79 ) ) ;
} else {
F_38 ( V_73 , F_39 ( V_2 -> V_99 ) ,
V_98 , 0 ) ;
}
V_79 += V_98 ;
V_61 -= V_98 ;
}
if ( F_41 ( V_61 ) ) {
F_42 ( & V_2 -> V_20 -> V_42 , L_3 , V_61 ) ;
return F_32 ( - V_26 ) ;
}
V_82 = F_43 ( V_77 -> V_100 -> V_42 , V_75 -> V_101 , V_75 -> V_82 , V_66 ) ;
if ( ! V_82 )
return F_32 ( - V_102 ) ;
V_67 = F_44 ( V_77 , V_75 -> V_101 , V_82 , V_66 , V_103 ) ;
if ( ! V_67 ) {
F_45 ( V_77 -> V_100 -> V_42 , V_75 -> V_101 , V_75 -> V_82 , V_66 ) ;
return F_32 ( - V_102 ) ;
}
return V_67 ;
}
static void F_46 ( struct V_1 * V_2 ,
enum V_65 V_66 )
{
struct V_76 * V_77 ;
struct V_74 * V_75 ;
if ( V_66 == V_86 ) {
V_77 = V_2 -> V_87 ;
V_75 = & V_2 -> V_88 ;
} else {
V_77 = V_2 -> V_92 ;
V_75 = & V_2 -> V_93 ;
}
F_45 ( V_77 -> V_100 -> V_42 , V_75 -> V_101 , V_75 -> V_82 , V_66 ) ;
}
static void F_47 ( void * V_104 )
{
F_48 ( V_104 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_55 ;
struct V_64 * V_105 , * V_67 ;
V_105 = F_30 ( V_2 , V_86 ) ;
if ( F_50 ( V_105 ) ) {
F_51 ( & V_2 -> V_20 -> V_42 , L_4 , F_52 ( V_105 ) ) ;
V_54 -> V_106 = F_52 ( V_105 ) ;
return;
}
V_67 = F_30 ( V_2 , V_107 ) ;
if ( F_50 ( V_67 ) ) {
F_46 ( V_2 , V_86 ) ;
F_51 ( & V_2 -> V_20 -> V_42 , L_5 , F_52 ( V_67 ) ) ;
V_54 -> V_106 = F_52 ( V_67 ) ;
return;
}
V_105 -> V_108 = F_47 ;
V_105 -> V_104 = & V_2 -> V_63 ;
F_53 ( V_105 ) ;
F_53 ( V_67 ) ;
F_54 ( V_2 -> V_87 ) ;
F_54 ( V_2 -> V_92 ) ;
F_29 ( & V_2 -> V_63 ) ;
F_46 ( V_2 , V_107 ) ;
F_46 ( V_2 , V_86 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_32 * V_45 )
{
int V_8 ;
V_54 -> V_56 = V_45 ;
V_8 = F_22 ( V_2 , V_54 -> V_6 , V_45 ) ;
if ( V_8 ) {
F_51 ( & V_2 -> V_20 -> V_42 ,
L_6 ) ;
V_54 -> V_106 = V_8 ;
return;
}
V_2 -> V_52 = 0 ;
V_2 -> V_48 = 0 ;
if ( V_2 -> V_87 && V_45 -> V_61 > V_60 )
F_49 ( V_2 ) ;
else
F_28 ( V_2 ) ;
if ( V_54 -> V_106 )
return;
V_54 -> V_109 += V_45 -> V_61 ;
if ( V_45 -> V_110 ) {
F_56 ( V_111 ) ;
F_57 ( F_58 ( V_45 -> V_110 ) ) ;
}
if ( V_45 -> V_112 ) {
if ( ! F_59 ( & V_45 -> V_113 , & V_54 -> V_114 ) ) {
F_19 ( V_54 -> V_6 , false ) ;
F_60 () ;
F_19 ( V_54 -> V_6 , true ) ;
}
}
}
static void F_61 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
unsigned long V_115 ;
struct V_32 * V_45 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_51 ( & V_2 -> V_20 -> V_42 , L_7 ) ;
V_54 -> V_106 = V_8 ;
return;
}
V_115 = V_116 + F_62 ( V_117 ) ;
while ( F_7 ( V_2 , V_57 ) & V_58 ) {
if ( F_63 ( V_116 , V_115 ) ) {
F_42 ( & V_2 -> V_20 -> V_42 ,
L_8 ) ;
V_54 -> V_106 = - V_118 ;
return;
}
F_7 ( V_2 , V_49 ) ;
}
V_2 -> V_59 = 0 ;
F_19 ( V_54 -> V_6 , true ) ;
F_64 (t, &msg->transfers, transfer_list) {
F_55 ( V_2 , V_54 , V_45 ) ;
if ( V_54 -> V_106 )
break;
}
F_19 ( V_54 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static int F_65 ( struct V_18 * V_19 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_66 ( V_19 ) ;
V_54 -> V_56 = NULL ;
V_54 -> V_106 = 0 ;
V_54 -> V_109 = 0 ;
V_2 -> V_55 = V_54 ;
F_61 ( V_2 , V_54 ) ;
V_2 -> V_55 = NULL ;
F_67 ( V_19 ) ;
return 0 ;
}
static T_5 F_68 ( int V_119 , void * V_120 )
{
struct V_1 * V_2 = V_120 ;
T_2 V_121 = F_3 ( V_2 , V_122 ) ;
if ( F_69 ( V_121 & V_123 ) ) {
F_1 ( V_2 , V_124 , 0 ) ;
F_42 ( & V_2 -> V_20 -> V_42 ,
L_9 ) ;
V_2 -> V_55 -> V_106 = - V_125 ;
} else {
if ( F_27 ( V_2 ) ) {
return V_126 ;
}
}
F_14 ( V_2 ) ;
F_48 ( & V_2 -> V_63 ) ;
return V_126 ;
}
static bool F_70 ( struct V_76 * V_77 , void * V_127 )
{
if ( F_71 ( V_77 ) )
return false ;
V_77 -> V_128 = V_127 ;
return true ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_6 V_129 ;
int V_81 ;
V_2 -> V_99 = ( void * ) F_73 ( V_97 ) ;
if ( ! V_2 -> V_99 )
return - V_102 ;
F_74 ( V_129 ) ;
F_75 ( V_130 , V_129 ) ;
V_2 -> V_131 . V_132 = V_133 ;
V_2 -> V_131 . V_85 = V_86 ;
V_2 -> V_131 . V_134 = L_10 ;
V_2 -> V_87 = F_76 ( V_129 , F_70 ,
& V_2 -> V_131 ) ;
if ( ! V_2 -> V_87 ) {
V_81 = - V_135 ;
goto V_136;
}
V_2 -> V_137 . V_132 = V_133 ;
V_2 -> V_137 . V_85 = V_107 ;
V_2 -> V_137 . V_134 = L_11 ;
V_2 -> V_92 = F_76 ( V_129 , F_70 ,
& V_2 -> V_137 ) ;
if ( ! V_2 -> V_92 ) {
V_81 = - V_135 ;
goto V_138;
}
return 0 ;
V_138:
F_77 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
V_136:
F_78 ( ( unsigned long ) V_2 -> V_99 ) ;
return V_81 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_77 ( V_2 -> V_87 ) ;
F_34 ( & V_2 -> V_88 ) ;
}
if ( V_2 -> V_92 ) {
F_77 ( V_2 -> V_92 ) ;
F_34 ( & V_2 -> V_93 ) ;
}
if ( V_2 -> V_99 )
F_78 ( ( unsigned long ) V_2 -> V_99 ) ;
}
static int F_80 ( struct V_139 * V_20 )
{
struct V_18 * V_19 ;
struct V_140 * V_141 ;
struct V_1 * V_2 ;
struct V_142 * V_143 ;
int V_119 ;
int error ;
int V_80 ;
V_141 = F_81 ( & V_20 -> V_42 ) ;
if ( ! V_141 ) {
F_51 ( & V_20 -> V_42 , L_12 ) ;
return - V_26 ;
}
V_119 = F_82 ( V_20 , 0 ) ;
if ( V_119 < 0 ) {
F_51 ( & V_20 -> V_42 , L_13 ) ;
return - V_144 ;
}
V_143 = F_83 ( V_20 , V_145 , 0 ) ;
if ( ! V_143 ) {
F_51 ( & V_20 -> V_42 , L_14 ) ;
return - V_135 ;
}
V_19 = F_84 ( & V_20 -> V_42 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_102 ;
V_19 -> V_146 = F_65 ;
V_19 -> V_147 = V_20 -> V_148 ;
V_19 -> V_149 = V_40 | V_39 | V_30 ;
V_19 -> V_150 = F_85 ( 4 , 16 ) ;
V_19 -> V_151 = V_141 -> V_151 ;
V_19 -> V_152 = F_86 ( & V_19 -> V_42 ,
sizeof( int ) * V_19 -> V_151 ,
V_97 ) ;
if ( ! V_19 -> V_152 ) {
error = - V_102 ;
goto V_153;
}
for ( V_80 = 0 ; V_80 < V_19 -> V_151 ; V_80 ++ ) {
V_19 -> V_152 [ V_80 ] = V_141 -> V_154 [ V_80 ] ;
if ( ! F_20 ( V_19 -> V_152 [ V_80 ] ) )
continue;
error = F_87 ( & V_20 -> V_42 , V_19 -> V_152 [ V_80 ] ,
V_155 ,
L_15 ) ;
if ( error ) {
F_51 ( & V_20 -> V_42 , L_16 ,
V_19 -> V_152 [ V_80 ] ) ;
goto V_153;
}
}
F_88 ( V_20 , V_19 ) ;
V_2 = F_66 ( V_19 ) ;
V_2 -> V_9 = F_89 ( & V_20 -> V_42 , NULL ) ;
if ( F_50 ( V_2 -> V_9 ) ) {
F_51 ( & V_20 -> V_42 , L_17 ) ;
error = F_52 ( V_2 -> V_9 ) ;
goto V_153;
}
F_90 ( & V_2 -> V_63 ) ;
V_19 -> V_25 = F_17 ( V_2 -> V_9 ) / 2 ;
V_19 -> V_24 = F_17 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_90 = V_143 -> V_156 + V_49 ;
V_2 -> V_5 = F_91 ( & V_20 -> V_42 , V_143 ) ;
if ( F_50 ( V_2 -> V_5 ) ) {
error = F_52 ( V_2 -> V_5 ) ;
goto V_153;
}
error = F_92 ( & V_20 -> V_42 , V_119 , F_68 ,
0 , L_15 , V_2 ) ;
if ( error ) {
F_51 ( & V_20 -> V_42 , L_18 ) ;
goto V_153;
}
if ( V_141 -> V_157 && F_72 ( V_2 ) )
F_42 ( & V_20 -> V_42 , L_19 ) ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_93 ( & V_20 -> V_42 , V_19 ) ;
if ( error ) {
F_51 ( & V_20 -> V_42 , L_20 ) ;
goto V_158;
}
F_94 ( & V_20 -> V_42 , L_21 ,
( unsigned long ) V_143 -> V_156 , V_119 ) ;
return 0 ;
V_158:
F_79 ( V_2 ) ;
V_153:
F_95 ( V_19 ) ;
return error ;
}
static int F_96 ( struct V_139 * V_20 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
struct V_1 * V_2 = F_66 ( V_19 ) ;
F_79 ( V_2 ) ;
return 0 ;
}
