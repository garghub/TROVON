static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 , T_2 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_8 = F_3 ( V_7 -> V_9 ) ;
int V_10 , V_11 ;
V_3 = F_4 ( V_3 , V_2 -> V_12 , V_2 -> V_13 ) ;
for ( V_10 = 2 ; V_10 <= 254 ; V_10 += 2 ) {
for ( V_11 = 0 ; V_11 <= 255 ; V_11 ++ ) {
if ( ( V_8 / ( V_10 * ( V_11 + 1 ) ) ) <= V_3 ) {
* V_5 = ( T_2 ) V_11 ;
* V_4 = ( T_2 ) V_10 ;
return 0 ;
}
}
}
return - V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_19 = F_6 ( V_18 -> V_20 ) ;
T_2 V_4 = 0 ;
T_2 V_5 = 0 ;
T_3 V_21 ;
int V_22 ;
V_22 = F_1 ( V_2 , V_18 -> V_23 ,
& V_4 , & V_5 ) ;
if ( V_22 )
return V_22 ;
V_21 = V_5 << V_24 ;
V_21 |= ( V_16 -> V_25 & ( V_26 | V_27 ) ) << V_28 ;
V_21 |= V_19 ;
F_7 ( & V_2 -> V_29 , L_1 ,
V_16 -> V_25 , V_4 , V_5 , V_19 ) ;
F_7 ( & V_2 -> V_29 , L_2 , V_21 ) ;
F_8 ( V_4 , V_7 -> V_30 + V_31 ) ;
F_8 ( V_21 , V_7 -> V_30 + V_32 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_33 -> V_34 ;
T_1 V_35 = 0 ;
if ( V_18 -> V_20 > 8 ) {
if ( V_18 -> V_36 )
V_35 = ( ( T_3 * ) V_18 -> V_36 ) [ V_7 -> V_37 ] ;
V_7 -> V_37 += 2 ;
} else {
if ( V_18 -> V_36 )
V_35 = ( ( T_2 * ) V_18 -> V_36 ) [ V_7 -> V_37 ] ;
V_7 -> V_37 += 1 ;
}
F_8 ( V_35 , V_7 -> V_30 + V_38 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_33 -> V_34 ;
T_1 V_35 ;
V_35 = F_11 ( V_7 -> V_30 + V_38 ) ;
if ( V_18 -> V_20 > 8 ) {
if ( V_18 -> V_39 )
( ( T_3 * ) V_18 -> V_39 ) [ V_7 -> V_40 ] = V_35 ;
V_7 -> V_40 += 2 ;
} else {
if ( V_18 -> V_39 )
( ( T_2 * ) V_18 -> V_39 ) [ V_7 -> V_40 ] = V_35 ;
V_7 -> V_40 += 1 ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_33 -> V_34 ;
while ( ( F_11 ( V_7 -> V_30 + V_41 ) & V_42 ) ) {
F_10 ( V_2 ) ;
V_7 -> V_43 -- ;
}
while ( V_7 -> V_43 < V_44 && V_7 -> V_37 < V_18 -> V_45 ) {
F_9 ( V_2 ) ;
V_7 -> V_43 ++ ;
}
if ( V_7 -> V_40 == V_18 -> V_45 )
return 0 ;
return - V_46 ;
}
static struct V_47 *
F_13 ( struct V_1 * V_2 ,
enum V_48 V_49 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_33 -> V_34 ;
struct V_47 * V_50 ;
enum V_51 V_52 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
const void * V_61 , * V_62 ;
T_4 V_45 = V_18 -> V_45 ;
int V_63 , V_64 , V_65 ;
if ( V_18 -> V_20 > 8 )
V_52 = V_66 ;
else
V_52 = V_67 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_68 = V_49 ;
if ( V_49 == V_69 ) {
V_60 = V_7 -> V_70 ;
V_61 = V_18 -> V_39 ;
V_58 = & V_7 -> V_71 ;
V_54 . V_72 = V_7 -> V_73 ;
V_54 . V_74 = V_52 ;
} else {
V_60 = V_7 -> V_75 ;
V_61 = V_18 -> V_36 ;
V_58 = & V_7 -> V_76 ;
V_54 . V_77 = V_7 -> V_73 ;
V_54 . V_78 = V_52 ;
}
V_64 = F_14 ( V_60 , & V_54 ) ;
if ( V_64 )
return F_15 ( V_64 ) ;
V_65 = F_16 ( V_45 , V_79 ) ;
if ( V_65 != V_58 -> V_65 ) {
F_17 ( V_58 ) ;
V_64 = F_18 ( V_58 , V_65 , V_80 ) ;
if ( V_64 )
return F_15 ( V_64 ) ;
}
V_62 = V_61 ;
F_19 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_81 = F_20 ( T_4 , V_45 , V_79 ) ;
if ( V_61 ) {
F_21 ( V_56 , F_22 ( V_62 ) , V_81 ,
F_23 ( V_62 ) ) ;
} else {
F_21 ( V_56 , F_22 ( V_7 -> V_82 ) ,
V_81 , 0 ) ;
}
V_62 += V_81 ;
V_45 -= V_81 ;
}
if ( F_24 ( V_45 ) ) {
F_25 ( & V_2 -> V_29 , L_3 , V_45 ) ;
return F_15 ( - V_14 ) ;
}
V_65 = F_26 ( V_60 -> V_83 -> V_29 , V_58 -> V_84 , V_58 -> V_65 , V_49 ) ;
if ( ! V_65 )
return F_15 ( - V_85 ) ;
V_50 = F_27 ( V_60 , V_58 -> V_84 , V_65 , V_49 , V_86 ) ;
if ( ! V_50 ) {
F_28 ( V_60 -> V_83 -> V_29 , V_58 -> V_84 , V_58 -> V_65 , V_49 ) ;
return F_15 ( - V_85 ) ;
}
return V_50 ;
}
static void F_29 ( struct V_1 * V_2 ,
enum V_48 V_49 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_59 * V_60 ;
struct V_57 * V_58 ;
if ( V_49 == V_69 ) {
V_60 = V_7 -> V_70 ;
V_58 = & V_7 -> V_71 ;
} else {
V_60 = V_7 -> V_75 ;
V_58 = & V_7 -> V_76 ;
}
F_28 ( V_60 -> V_83 -> V_29 , V_58 -> V_84 , V_58 -> V_65 , V_49 ) ;
}
static void F_30 ( void * V_87 )
{
struct V_1 * V_2 = V_87 ;
F_29 ( V_2 , V_88 ) ;
F_29 ( V_2 , V_69 ) ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_47 * V_89 , * V_50 ;
V_89 = F_13 ( V_2 , V_69 ) ;
if ( F_33 ( V_89 ) ) {
F_34 ( & V_2 -> V_29 , L_4 , F_35 ( V_89 ) ) ;
return F_35 ( V_89 ) ;
}
V_50 = F_13 ( V_2 , V_88 ) ;
if ( F_33 ( V_50 ) ) {
F_29 ( V_2 , V_69 ) ;
F_34 ( & V_2 -> V_29 , L_5 , F_35 ( V_50 ) ) ;
return F_35 ( V_50 ) ;
}
V_89 -> V_90 = F_30 ;
V_89 -> V_87 = V_2 ;
F_36 ( V_89 ) ;
F_36 ( V_50 ) ;
F_37 ( V_7 -> V_70 ) ;
F_37 ( V_7 -> V_75 ) ;
return 1 ;
}
static T_5 F_38 ( int V_91 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_35 ;
if ( F_11 ( V_7 -> V_30 + V_93 ) & V_94 ) {
F_8 ( 0 , V_7 -> V_30 + V_95 ) ;
F_25 ( & V_2 -> V_29 ,
L_6 ) ;
V_2 -> V_33 -> V_96 = - V_97 ;
} else {
if ( F_12 ( V_2 ) ) {
return V_98 ;
}
}
V_35 = F_11 ( V_7 -> V_30 + V_99 ) ;
V_35 &= ~ ( V_100 | V_101 | V_102 ) ;
F_8 ( V_35 , V_7 -> V_30 + V_99 ) ;
F_31 ( V_2 ) ;
return V_98 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_35 ;
int V_64 ;
V_64 = F_5 ( V_2 , V_16 , V_18 ) ;
if ( V_64 ) {
F_34 ( & V_2 -> V_29 , L_7 ) ;
return V_64 ;
}
V_2 -> V_33 -> V_34 = V_18 ;
V_7 -> V_40 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_7 -> V_70 && V_18 -> V_45 > V_44 )
return F_32 ( V_2 ) ;
F_12 ( V_2 ) ;
V_35 = F_11 ( V_7 -> V_30 + V_99 ) ;
V_35 |= ( V_100 | V_101 | V_102 ) ;
F_8 ( V_35 , V_7 -> V_30 + V_99 ) ;
return 1 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_105 ;
V_105 = V_106 + F_41 ( V_107 ) ;
while ( F_11 ( V_7 -> V_30 + V_41 ) & V_42 ) {
if ( F_42 ( V_106 , V_105 ) ) {
F_25 ( & V_2 -> V_29 ,
L_8 ) ;
return - V_108 ;
}
F_11 ( V_7 -> V_30 + V_38 ) ;
}
V_7 -> V_43 = 0 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_35 ;
int V_64 ;
V_64 = F_44 ( V_7 -> V_9 ) ;
if ( V_64 )
return V_64 ;
V_35 = F_11 ( V_7 -> V_30 + V_99 ) ;
V_35 |= V_109 ;
F_8 ( V_35 , V_7 -> V_30 + V_99 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_35 ;
V_35 = F_11 ( V_7 -> V_30 + V_99 ) ;
V_35 &= ~ V_109 ;
F_8 ( V_35 , V_7 -> V_30 + V_99 ) ;
F_46 ( V_7 -> V_9 ) ;
return 0 ;
}
static bool F_47 ( struct V_59 * V_60 , void * V_110 )
{
if ( F_48 ( V_60 ) )
return false ;
V_60 -> V_111 = V_110 ;
return true ;
}
static int F_49 ( struct V_6 * V_7 )
{
T_6 V_112 ;
int V_64 ;
V_7 -> V_82 = ( void * ) F_50 ( V_80 ) ;
if ( ! V_7 -> V_82 )
return - V_85 ;
F_51 ( V_112 ) ;
F_52 ( V_113 , V_112 ) ;
V_7 -> V_114 . V_115 = V_116 ;
V_7 -> V_114 . V_68 = V_69 ;
V_7 -> V_114 . V_117 = L_9 ;
V_7 -> V_70 = F_53 ( V_112 , F_47 ,
& V_7 -> V_114 ) ;
if ( ! V_7 -> V_70 ) {
V_64 = - V_118 ;
goto V_119;
}
V_7 -> V_120 . V_115 = V_116 ;
V_7 -> V_120 . V_68 = V_88 ;
V_7 -> V_120 . V_117 = L_10 ;
V_7 -> V_75 = F_53 ( V_112 , F_47 ,
& V_7 -> V_120 ) ;
if ( ! V_7 -> V_75 ) {
V_64 = - V_118 ;
goto V_121;
}
return 0 ;
V_121:
F_54 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
V_119:
F_55 ( ( unsigned long ) V_7 -> V_82 ) ;
return V_64 ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( V_7 -> V_70 ) {
F_54 ( V_7 -> V_70 ) ;
F_17 ( & V_7 -> V_71 ) ;
}
if ( V_7 -> V_75 ) {
F_54 ( V_7 -> V_75 ) ;
F_17 ( & V_7 -> V_76 ) ;
}
if ( V_7 -> V_82 )
F_55 ( ( unsigned long ) V_7 -> V_82 ) ;
}
static int F_57 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 ;
struct V_6 * V_7 ;
struct V_126 * V_127 ;
int V_91 ;
int error ;
int V_63 ;
V_125 = F_58 ( & V_123 -> V_29 ) ;
if ( ! V_125 ) {
F_34 ( & V_123 -> V_29 , L_11 ) ;
return - V_14 ;
}
V_91 = F_59 ( V_123 , 0 ) ;
if ( V_91 < 0 ) {
F_34 ( & V_123 -> V_29 , L_12 ) ;
return - V_128 ;
}
V_127 = F_60 ( V_123 , V_129 , 0 ) ;
if ( ! V_127 ) {
F_34 ( & V_123 -> V_29 , L_13 ) ;
return - V_118 ;
}
V_2 = F_61 ( & V_123 -> V_29 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_130 = F_43 ;
V_2 -> V_131 = F_45 ;
V_2 -> V_132 = F_40 ;
V_2 -> V_133 = F_39 ;
V_2 -> V_134 = V_123 -> V_135 ;
V_2 -> V_136 = V_27 | V_26 | V_137 ;
V_2 -> V_138 = F_62 ( 4 , 16 ) ;
V_2 -> V_139 = V_125 -> V_139 ;
V_2 -> V_140 = F_63 ( & V_2 -> V_29 ,
sizeof( int ) * V_2 -> V_139 ,
V_80 ) ;
if ( ! V_2 -> V_140 ) {
error = - V_85 ;
goto V_141;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_139 ; V_63 ++ ) {
V_2 -> V_140 [ V_63 ] = V_125 -> V_142 [ V_63 ] ;
if ( ! F_64 ( V_2 -> V_140 [ V_63 ] ) )
continue;
error = F_65 ( & V_123 -> V_29 , V_2 -> V_140 [ V_63 ] ,
V_143 ,
L_14 ) ;
if ( error ) {
F_34 ( & V_123 -> V_29 , L_15 ,
V_2 -> V_140 [ V_63 ] ) ;
goto V_141;
}
}
F_66 ( V_123 , V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_7 -> V_9 = F_67 ( & V_123 -> V_29 , NULL ) ;
if ( F_33 ( V_7 -> V_9 ) ) {
F_34 ( & V_123 -> V_29 , L_16 ) ;
error = F_35 ( V_7 -> V_9 ) ;
goto V_141;
}
V_2 -> V_13 = F_3 ( V_7 -> V_9 ) / 2 ;
V_2 -> V_12 = F_3 ( V_7 -> V_9 ) / ( 254 * 256 ) ;
V_7 -> V_73 = V_127 -> V_144 + V_38 ;
V_7 -> V_30 = F_68 ( & V_123 -> V_29 , V_127 ) ;
if ( F_33 ( V_7 -> V_30 ) ) {
error = F_35 ( V_7 -> V_30 ) ;
goto V_141;
}
error = F_69 ( & V_123 -> V_29 , V_91 , F_38 ,
0 , L_14 , V_2 ) ;
if ( error ) {
F_34 ( & V_123 -> V_29 , L_17 ) ;
goto V_141;
}
if ( V_125 -> V_145 && F_49 ( V_7 ) )
F_25 ( & V_123 -> V_29 , L_18 ) ;
F_8 ( 0 , V_7 -> V_30 + V_99 ) ;
error = F_70 ( & V_123 -> V_29 , V_2 ) ;
if ( error ) {
F_34 ( & V_123 -> V_29 , L_19 ) ;
goto V_146;
}
F_71 ( & V_123 -> V_29 , L_20 ,
( unsigned long ) V_127 -> V_144 , V_91 ) ;
return 0 ;
V_146:
F_56 ( V_7 ) ;
V_141:
F_72 ( V_2 ) ;
return error ;
}
static int F_73 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_74 ( V_123 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
