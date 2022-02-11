static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = V_8 -> V_10 . V_11 . V_12 ;
return V_9 ;
}
static void F_3 ( struct V_7 * V_8 )
{
T_1 V_13 ;
int V_14 ;
V_13 = F_4 ( V_15 ) ;
V_13 &= V_16 ;
F_5 ( V_15 , V_13 ) ;
V_13 = F_4 ( V_15 ) ;
V_13 |= V_17 ;
F_5 ( V_15 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_8 -> V_18 ; V_14 ++ ) {
if ( ! ( F_4 ( V_15 ) & V_19 ) )
break;
F_6 ( 1 ) ;
}
V_13 = F_4 ( V_15 ) ;
V_13 &= ~ V_17 ;
F_5 ( V_15 , V_13 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
T_1 V_13 ;
V_13 = F_4 ( V_15 ) ;
if ( ( V_13 & V_20 ) &&
( V_13 & V_21 ) ) {
V_13 |= V_16 ;
F_5 ( V_15 , V_13 ) ;
}
}
static void F_8 ( struct V_7 * V_8 ,
bool V_22 )
{
T_1 V_13 ;
V_13 = F_4 ( V_15 ) & ~ V_23 ;
if ( V_22 )
V_13 |= F_9 ( 1 ) ;
else
V_13 |= F_9 ( 0 ) ;
F_5 ( V_15 , V_13 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
T_1 V_13 ;
V_13 = F_4 ( V_24 ) & ~ V_25 ;
V_13 |= F_11 ( 3 ) ;
F_5 ( V_24 , V_13 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
T_1 V_13 ;
V_13 = F_4 ( V_24 ) ;
V_13 &= ~ V_26 ;
V_13 |= F_13 ( 4 ) ;
V_13 &= ~ V_27 ;
V_13 &= ~ V_28 ;
F_5 ( V_24 , V_13 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
T_1 V_13 ;
V_13 = F_4 ( V_24 ) & ~ V_26 ;
V_13 |= F_13 ( 8 ) ;
F_5 ( V_24 , V_13 ) ;
V_13 = F_15 ( V_29 ) ;
V_13 |= V_30 ;
V_13 &= ~ V_31 ;
V_13 &= ~ V_32 ;
V_13 |= V_33 ;
F_16 ( V_29 , V_13 ) ;
}
static int F_17 ( struct V_7 * V_8 ,
T_1 clock , struct V_34 * V_35 )
{
int V_36 ;
struct V_37 V_38 ;
V_36 = F_18 ( V_8 , V_39 ,
clock , false , & V_38 ) ;
if ( V_36 )
return V_36 ;
if ( V_38 . V_40 )
V_35 -> V_41 = 2 + ( V_38 . V_42 & 0xF ) + ( V_38 . V_42 >> 4 ) ;
else
V_35 -> V_41 = 1 ;
V_35 -> V_43 = clock * V_35 -> V_41 ;
return 0 ;
}
static void F_19 ( struct V_7 * V_8 ,
T_1 V_44 , struct V_34 * V_35 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_45 = V_8 -> clock . V_46 . V_47 ;
T_1 V_48 ;
T_1 V_49 = F_20 ( V_8 ,
V_50 *
V_9 -> V_51 ,
V_52 ) ;
F_21 ( V_8 , V_44 , true ) ;
F_22 ( V_8 , V_44 , false ) ;
if ( V_35 -> V_41 == 1 )
F_23 ( V_8 , V_44 , false ) ;
else {
T_1 V_53 = ( V_35 -> V_41 - 2 ) / 2 ;
T_1 V_54 = V_35 -> V_41 - 2 - V_53 ;
F_23 ( V_8 , V_44 , true ) ;
F_24 ( V_8 , V_44 , ( V_54 << 4 ) | V_53 ) ;
}
V_48 = ( ( V_35 -> V_43 * V_9 -> V_51 ) / V_45 ) >>
V_9 -> V_55 ;
F_25 ( V_8 , V_44 ,
V_9 -> V_51 - 1 ) ;
F_26 ( V_8 , V_44 , V_48 ) ;
F_27 ( V_8 , V_44 , V_49 ) ;
}
static struct V_34 F_28 ( struct V_7 * V_8 ,
struct V_34 * V_56 ,
bool V_57 , T_1 V_58 )
{
struct V_34 V_59 ;
V_59 . V_41 = V_56 -> V_41 ;
if ( V_57 )
V_59 . V_43 = ( V_56 -> V_43 * ( 100 + V_58 ) ) / 100 ;
else
V_59 . V_43 = ( V_56 -> V_43 * 100 + 99 + V_58 ) / ( 100 + V_58 ) ;
return V_59 ;
}
static bool F_29 ( struct V_7 * V_8 ,
struct V_34 * V_56 ,
struct V_34 * V_60 )
{
return ( V_56 -> V_41 > V_60 -> V_41 ) &&
( ( V_56 -> V_43 * V_60 -> V_41 ) <=
( V_60 -> V_43 * ( V_56 -> V_41 - 1 ) ) ) ;
}
static struct V_34 F_30 ( struct V_7 * V_8 ,
struct V_34 * V_56 ,
struct V_34 * V_60 )
{
struct V_34 V_59 = * V_56 ;
while ( F_29 ( V_8 , & V_59 , V_60 ) )
V_59 . V_41 -- ;
return V_59 ;
}
static bool F_31 ( struct V_7 * V_8 ,
struct V_34 * V_56 ,
struct V_34 * V_60 ,
bool V_57 )
{
return ( V_57 && ( V_56 -> V_43 >= V_60 -> V_43 ) ) ||
( ! V_57 && ( V_56 -> V_43 <= V_60 -> V_43 ) ) ;
}
static void F_32 ( struct V_7 * V_8 ,
T_1 V_61 , T_1 V_62 ,
T_1 V_63 , T_2 * V_64 )
{
struct V_34 V_56 ;
struct V_34 V_60 ;
bool V_57 ;
T_1 V_44 = V_63 ;
F_17 ( V_8 , V_61 , & V_56 ) ;
F_17 ( V_8 , V_62 , & V_60 ) ;
F_19 ( V_8 , V_44 ++ , & V_56 ) ;
V_57 = ( V_60 . V_43 >= V_56 . V_43 ) ;
if ( V_60 . V_41 > V_56 . V_41 )
V_56 . V_41 = V_60 . V_41 ;
while ( 1 ) {
struct V_34 V_59 ;
if ( F_29 ( V_8 , & V_56 , & V_60 ) )
V_59 = F_30 ( V_8 , & V_56 , & V_60 ) ;
else
V_59 = F_28 ( V_8 , & V_56 , V_57 , V_65 ) ;
if ( F_31 ( V_8 , & V_59 , & V_60 , V_57 ) ) {
struct V_34 V_66 =
F_28 ( V_8 , & V_60 , ! V_57 , V_67 ) ;
V_66 . V_41 = V_59 . V_41 ;
if ( ! F_31 ( V_8 , & V_66 , & V_56 , ! V_57 ) )
F_19 ( V_8 , V_44 ++ , & V_66 ) ;
if ( ( V_59 . V_41 != V_60 . V_41 ) &&
( V_59 . V_43 != V_60 . V_43 ) ) {
struct V_34 V_68 ;
V_68 . V_43 = V_60 . V_43 ;
V_68 . V_41 = V_59 . V_41 ;
F_19 ( V_8 , V_44 ++ , & V_68 ) ;
}
F_19 ( V_8 , V_44 ++ , & V_60 ) ;
break;
} else
F_19 ( V_8 , V_44 ++ , & V_59 ) ;
V_56 = V_59 ;
}
* V_64 = ( T_2 ) V_44 - 1 ;
}
static void F_33 ( struct V_7 * V_8 ,
T_1 clock , T_1 V_69 )
{
struct V_34 V_35 ;
F_17 ( V_8 , clock , & V_35 ) ;
F_19 ( V_8 , V_69 , & V_35 ) ;
}
static void F_34 ( struct V_7 * V_8 ,
T_1 V_63 , T_1 V_64 )
{
T_1 V_44 ;
for ( V_44 = V_63 + 1 ; V_44 < V_64 ; V_44 ++ )
F_21 ( V_8 , V_44 , false ) ;
}
static void F_35 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_70 )
{
F_36 ( V_71 + ( V_69 * 4 ) ,
F_37 ( V_70 ) , ~ V_72 ) ;
}
static void F_38 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_73 )
{
F_36 ( V_71 + ( V_69 * 4 ) ,
F_39 ( V_73 ) , ~ V_74 ) ;
}
static void F_40 ( struct V_7 * V_8 ,
T_1 V_69 , bool V_22 )
{
if ( V_22 )
F_36 ( V_71 + ( V_69 * 4 ) ,
V_75 , ~ V_75 ) ;
else
F_36 ( V_71 + ( V_69 * 4 ) ,
0 , ~ V_75 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
T_1 V_70 )
{
F_36 ( V_76 , F_37 ( V_70 ) , ~ V_72 ) ;
}
static void F_42 ( struct V_7 * V_8 ,
T_1 V_73 )
{
F_36 ( V_76 , F_39 ( V_73 ) , ~ V_74 ) ;
}
static void F_43 ( struct V_7 * V_8 ,
bool V_22 )
{
if ( V_22 )
F_36 ( V_76 , V_75 , ~ V_75 ) ;
else
F_36 ( V_76 , 0 , ~ V_75 ) ;
}
static void F_44 ( struct V_7 * V_8 ,
bool V_22 )
{
if ( V_22 )
F_36 ( V_77 , V_78 , ~ V_78 ) ;
else
F_36 ( V_77 , 0 , ~ V_78 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
T_1 V_69 , bool V_22 )
{
if ( V_22 )
F_36 ( V_79 + ( V_69 * 4 ) ,
V_80 , ~ V_80 ) ;
else
F_36 ( V_79 + ( V_69 * 4 ) , 0 , ~ V_80 ) ;
}
static void F_46 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_81 )
{
F_36 ( V_79 + ( V_69 * 4 ) ,
F_47 ( V_81 ) , ~ V_82 ) ;
}
static void F_48 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_81 )
{
F_36 ( V_79 + ( V_69 * 4 ) , F_49 ( V_81 ) ,
~ V_83 ) ;
}
static void F_50 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_81 )
{
F_36 ( V_79 + ( V_69 * 4 ) ,
F_51 ( V_81 ) , ~ V_84 ) ;
}
static void F_52 ( struct V_7 * V_8 , T_1 V_85 )
{
F_36 ( V_86 , F_53 ( V_85 ) , ~ V_87 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_36 ( V_88 , V_89 , ~ V_89 ) ;
}
static T_1 F_55 ( T_1 V_90 )
{
T_1 V_13 = 1 << ( 2 * V_90 ) ;
return V_13 ;
}
static T_1 F_20 ( struct V_7 * V_8 ,
T_1 V_91 , T_1 V_90 )
{
T_1 V_92 = F_55 ( V_90 ) ;
return ( V_91 + V_92 - 1 ) / V_92 ;
}
static T_1 F_56 ( struct V_7 * V_8 ,
T_1 V_93 , T_1 V_90 )
{
T_1 V_45 = V_8 -> clock . V_46 . V_47 ;
return F_20 ( V_8 , V_93 * ( V_45 / 100 ) , V_90 ) ;
}
static void F_57 ( struct V_7 * V_8 ,
struct V_1 * V_94 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_96 [ V_97 ] =
V_94 -> V_61 . V_98 ;
V_9 -> V_95 . V_96 [ V_99 ] =
V_94 -> V_100 . V_98 ;
V_9 -> V_95 . V_96 [ V_101 ] =
V_94 -> V_62 . V_98 ;
V_9 -> V_95 . V_102 = V_97 ;
V_9 -> V_95 . V_103 = V_99 ;
V_9 -> V_95 . V_104 = V_101 ;
}
static void F_58 ( struct V_7 * V_8 ,
struct V_1 * V_94 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_105 [ V_106 ] =
V_94 -> V_62 . V_107 ;
V_9 -> V_95 . V_105 [ V_101 ] =
V_94 -> V_62 . V_107 ;
V_9 -> V_95 . V_105 [ V_99 ] =
V_94 -> V_100 . V_107 ;
V_9 -> V_95 . V_105 [ V_97 ] =
V_94 -> V_61 . V_107 ;
V_9 -> V_95 . V_108 = V_101 ;
if ( V_94 -> V_62 . V_107 == V_94 -> V_100 . V_107 )
V_9 -> V_95 . V_109 =
V_9 -> V_95 . V_108 ;
else
V_9 -> V_95 . V_109 = V_99 ;
if ( V_94 -> V_100 . V_107 == V_94 -> V_61 . V_107 )
V_9 -> V_95 . V_110 =
V_9 -> V_95 . V_109 ;
else
V_9 -> V_95 . V_110 = V_97 ;
}
static void F_59 ( struct V_7 * V_8 ,
struct V_1 * V_94 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_111 [ V_106 ] = V_94 -> V_62 . V_111 ;
V_9 -> V_95 . V_111 [ V_101 ] = V_94 -> V_62 . V_111 ;
V_9 -> V_95 . V_111 [ V_99 ] = V_94 -> V_100 . V_111 ;
V_9 -> V_95 . V_111 [ V_97 ] = V_94 -> V_61 . V_111 ;
V_9 -> V_95 . V_112 [ V_106 ] =
( V_94 -> V_62 . V_113 & V_114 ) ? true : false ;
V_9 -> V_95 . V_112 [ V_101 ] =
( V_94 -> V_62 . V_113 & V_114 ) ? true : false ;
V_9 -> V_95 . V_112 [ V_99 ] =
( V_94 -> V_100 . V_113 & V_114 ) ? true : false ;
V_9 -> V_95 . V_112 [ V_97 ] =
( V_94 -> V_61 . V_113 & V_114 ) ? true : false ;
V_9 -> V_95 . V_115 [ V_101 ] =
( V_94 -> V_62 . V_113 & V_116 ) ? true : false ;
V_9 -> V_95 . V_115 [ V_99 ] =
( V_94 -> V_100 . V_113 & V_116 ) ? true : false ;
V_9 -> V_95 . V_115 [ V_97 ] =
( V_94 -> V_61 . V_113 & V_116 ) ? true : false ;
V_9 -> V_95 . V_117 = V_101 ;
if ( ( V_94 -> V_62 . V_111 == V_94 -> V_100 . V_111 ) &&
( ( V_94 -> V_62 . V_113 & V_114 ) ==
( V_94 -> V_100 . V_113 & V_114 ) ) )
V_9 -> V_95 . V_118 =
V_9 -> V_95 . V_117 ;
else
V_9 -> V_95 . V_118 = V_99 ;
if ( ( V_94 -> V_100 . V_111 == V_94 -> V_61 . V_111 ) &&
( ( V_94 -> V_100 . V_113 & V_114 ) ==
( V_94 -> V_61 . V_113 & V_114 ) ) )
V_9 -> V_95 . V_119 =
V_9 -> V_95 . V_118 ;
else
V_9 -> V_95 . V_118 = V_97 ;
}
static inline T_1 F_60 ( T_1 V_120 ,
struct V_37 * V_38 ,
T_1 V_121 )
{
return V_120 * ( ( V_38 -> V_122 & ~ 1 ) << V_121 ) /
( V_38 -> V_123 + 1 ) ;
}
static inline T_1 F_61 ( T_1 V_124 , T_1 V_125 ,
T_1 V_126 , T_1 V_127 ,
T_1 V_121 )
{
T_1 V_48 = V_124 / V_125 ;
return ( V_127 * V_126 * 4 * ( V_48 * V_48 ) /
( 5375 * ( ( V_124 * 10 ) / ( 4096 >> V_121 ) ) ) ) ;
}
static inline T_1 F_62 ( T_1 V_126 , T_1 V_125 )
{
return ( ( ( V_125 * 10 ) / ( V_126 * 2 ) ) - 1 ) / 4 ;
}
static void F_63 ( struct V_7 * V_8 ,
T_1 clock , enum V_128 V_129 )
{
T_1 V_45 = V_8 -> clock . V_46 . V_47 ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_37 V_38 ;
struct V_130 V_131 ;
T_1 V_124 , V_73 , V_70 ;
F_40 ( V_8 , V_129 , false ) ;
if ( clock && V_9 -> V_132 ) {
if ( F_18 ( V_8 , V_39 , clock , false , & V_38 ) == 0 ) {
V_124 = F_60 ( V_45 , & V_38 ,
V_9 -> V_55 ) ;
if ( F_64 ( V_8 , & V_131 ,
V_133 , V_124 ) ) {
V_73 = F_61 ( V_124 ,
( V_45 / ( V_38 . V_123 + 1 ) ) ,
V_131 . V_134 ,
V_131 . V_135 ,
V_9 -> V_55 ) ;
V_70 = F_62 ( V_131 . V_134 ,
( V_45 / ( V_38 . V_123 + 1 ) ) ) ;
F_38 ( V_8 , V_129 , V_73 ) ;
F_35 ( V_8 , V_129 , V_70 ) ;
F_40 ( V_8 , V_129 , true ) ;
}
}
}
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_63 ( V_8 ,
V_9 -> V_95 . V_96 [ V_101 ] ,
V_101 ) ;
F_63 ( V_8 ,
V_9 -> V_95 . V_96 [ V_99 ] ,
V_99 ) ;
}
static int F_66 ( struct V_7 * V_8 ,
T_1 V_136 , T_1 clock )
{
struct V_37 V_38 ;
if ( F_18 ( V_8 , V_137 , clock , false , & V_38 ) )
return - V_138 ;
F_50 ( V_8 , V_136 , V_38 . V_123 ) ;
F_48 ( V_8 , V_136 , V_38 . V_122 ) ;
F_46 ( V_8 , V_136 , V_38 . V_42 ) ;
if ( V_38 . V_40 )
F_45 ( V_8 , V_136 , true ) ;
else
F_45 ( V_8 , V_136 , false ) ;
return 0 ;
}
static void F_67 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_14 ;
for ( V_14 = 1 ; V_14 < V_139 ; V_14 ++ ) {
if ( V_9 -> V_95 . V_105 [ V_14 ] )
F_66 ( V_8 , V_14 ,
V_9 -> V_95 . V_105 [ V_14 ] ) ;
}
}
static void F_68 ( struct V_7 * V_8 ,
T_1 V_140 ,
T_1 V_45 ,
struct V_37 * V_38 ,
T_1 * V_124 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_37 V_141 ;
T_1 V_142 ;
if ( F_18 ( V_8 , V_137 ,
V_140 , false , & V_141 ) == 0 ) {
V_142 = F_60 ( V_45 , & V_141 ,
V_9 -> V_55 ) ;
if ( V_142 > * V_124 ) {
* V_38 = V_141 ;
* V_124 = V_142 ;
}
}
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_45 = V_8 -> clock . V_143 . V_47 ;
struct V_37 V_38 ;
struct V_130 V_131 ;
T_1 V_124 = 0 , V_73 , V_70 ;
F_43 ( V_8 , false ) ;
if ( V_9 -> V_144 ) {
F_68 ( V_8 ,
V_9 -> V_95 . V_105 [ V_9 -> V_95 . V_108 ] ,
V_45 ,
& V_38 ,
& V_124 ) ;
F_68 ( V_8 ,
V_9 -> V_95 . V_105 [ V_9 -> V_95 . V_109 ] ,
V_45 ,
& V_38 ,
& V_124 ) ;
F_68 ( V_8 ,
V_9 -> V_95 . V_105 [ V_9 -> V_95 . V_110 ] ,
V_45 ,
& V_38 ,
& V_124 ) ;
if ( V_124 ) {
if ( F_64 ( V_8 , & V_131 ,
V_145 , V_124 ) ) {
V_73 = F_61 ( V_124 ,
( V_45 / ( V_38 . V_123 + 1 ) ) ,
V_131 . V_134 ,
V_131 . V_135 ,
V_9 -> V_55 ) ;
V_70 = F_62 ( V_131 . V_134 ,
( V_45 / ( V_38 . V_123 + 1 ) ) ) ;
F_42 ( V_8 , V_73 ) ;
F_41 ( V_8 , V_70 ) ;
F_43 ( V_8 , true ) ;
}
}
}
}
static int F_70 ( struct V_7 * V_8 ,
T_1 V_136 , T_3 V_146 )
{
T_1 V_147 , V_148 ;
int V_36 ;
V_36 = F_71 ( V_8 , V_146 ,
V_149 ,
& V_148 , & V_147 ) ;
if ( V_36 )
return V_36 ;
F_72 ( V_8 , V_136 , V_148 ) ;
return 0 ;
}
static void F_73 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_14 ;
for ( V_14 = 1 ; V_14 < V_150 ; V_14 ++ )
F_70 ( V_8 , V_14 ,
V_9 -> V_95 . V_111 [ V_14 ] ) ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_95 . V_112 [ 1 ] )
F_36 ( V_151 , V_152 , ~ V_152 ) ;
else
F_36 ( V_151 , 0 , ~ V_152 ) ;
if ( V_9 -> V_95 . V_112 [ 2 ] )
F_36 ( V_151 , V_153 , ~ V_153 ) ;
else
F_36 ( V_151 , 0 , ~ V_153 ) ;
}
static void F_75 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_63 ( V_8 ,
V_9 -> V_95 . V_96 [ V_97 ] ,
V_97 ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_95 . V_105 [ 0 ] )
F_66 ( V_8 , 0 ,
V_9 -> V_95 . V_105 [ 0 ] ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_70 ( V_8 , 0 ,
V_9 -> V_95 . V_111 [ 0 ] ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_95 . V_112 [ 0 ] )
F_36 ( V_151 , V_154 , ~ V_154 ) ;
else
F_36 ( V_151 , 0 , ~ V_154 ) ;
}
static T_1 F_79 ( struct V_7 * V_8 ,
T_1 V_155 )
{
T_1 V_156 , V_157 ;
T_1 V_13 ;
V_13 = ( F_80 ( V_158 ) & V_159 ) >> V_160 ;
V_156 = 1 << ( V_13 + 10 ) ;
V_157 = 1 << ( ( F_80 ( V_161 ) & 0x3 ) + 3 ) ;
return ( ( V_155 * 10 ) * V_157 / V_156 - 32 ) / 64 ;
}
static void F_81 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_162 ;
T_1 V_163 ;
T_1 V_164 ;
if ( V_9 -> V_95 . V_96 [ V_101 ] <
( V_9 -> V_95 . V_96 [ V_97 ] * 0xFF / 0x40 ) )
V_164 = V_9 -> V_95 . V_96 [ V_101 ] ;
else
V_164 =
V_9 -> V_95 . V_96 [ V_97 ] * 0xFF / 0x40 ;
F_82 ( V_8 , V_164 , 0 ) ;
V_162 = ( F_83 ( 64 * V_164 / V_9 -> V_95 . V_96 [ V_97 ] ) |
F_84 ( 64 * V_164 / V_9 -> V_95 . V_96 [ V_99 ] ) |
F_85 ( 64 * V_164 / V_9 -> V_95 . V_96 [ V_101 ] ) |
F_86 ( 64 * V_164 / V_9 -> V_95 . V_96 [ V_101 ] ) ) ;
F_87 ( V_165 , V_162 ) ;
V_163 =
( F_88 ( F_79 ( V_8 ,
V_9 -> V_95 . V_96 [ V_97 ] ) ) |
F_89 ( F_79 ( V_8 ,
V_9 -> V_95 . V_96 [ V_99 ] ) ) |
F_90 ( F_79 ( V_8 ,
V_9 -> V_95 . V_96 [ V_101 ] ) ) |
F_91 ( F_79 ( V_8 ,
V_9 -> V_95 . V_96 [ V_101 ] ) ) ) ;
F_87 ( V_166 , V_163 ) ;
}
static void F_92 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_93 ( V_8 , V_167 *
V_9 -> V_168 ) ;
F_94 ( V_8 , V_169 ) ;
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_45 = V_8 -> clock . V_46 . V_47 ;
F_96 ( V_170 ,
V_45 , 16 ,
& V_9 -> V_171 ,
& V_9 -> V_172 ) ;
F_97 ( V_8 , V_9 -> V_172 , V_9 -> V_171 ) ;
}
static void F_98 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_99 ( V_8 ,
( V_9 -> V_95 . V_173 [ 0 ] * V_9 -> V_171 ) / 200 ,
( V_9 -> V_95 . V_173 [ 1 ] * V_9 -> V_171 ) / 200 ,
( V_9 -> V_95 . V_174 [ 2 ] * V_9 -> V_171 ) / 200 ,
( V_9 -> V_95 . V_174 [ 1 ] * V_9 -> V_171 ) / 200 ) ;
}
static void F_100 ( struct V_7 * V_8 )
{
F_101 ( V_8 , V_175 ) ;
}
static void F_102 ( struct V_7 * V_8 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_176 ; V_14 ++ )
F_103 ( V_8 , V_14 , V_177 [ V_14 ] , V_178 [ V_14 ] ) ;
F_104 ( V_8 , V_179 ) ;
}
static void F_105 ( struct V_7 * V_8 )
{
F_106 ( V_8 , V_180 ) ;
}
static void F_107 ( struct V_7 * V_8 )
{
F_106 ( V_8 , 0 ) ;
}
static void F_108 ( struct V_7 * V_8 )
{
F_109 ( V_8 , V_181 ) ;
F_110 ( V_8 , V_182 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
F_112 ( V_8 , V_183 ) ;
F_113 ( V_8 , V_184 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_115 ( V_8 , V_185 ) ;
F_116 ( V_8 , V_186 ) ;
}
static void F_117 ( struct V_7 * V_8 )
{
F_118 ( V_8 , V_187 ) ;
F_119 ( V_8 , V_188 ) ;
F_120 ( V_8 , V_189 ) ;
F_121 ( V_8 , V_190 ) ;
F_122 ( V_8 , V_191 ) ;
}
static void F_123 ( struct V_7 * V_8 )
{
T_1 V_85 ;
F_124 ( V_8 , V_192 ) ;
F_125 ( V_8 ,
F_56 ( V_8 ,
V_8 -> V_10 . V_11 . V_193 ,
V_192 ) ) ;
V_85 = F_56 ( V_8 ,
V_8 -> V_10 . V_11 . V_194 ,
V_192 ) ;
F_52 ( V_8 , ( V_85 + 0x1F ) >> 5 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
F_127 ( V_8 , V_52 ) ;
F_54 ( V_8 ) ;
}
static T_4 F_128 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_4 V_195 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_150 ; V_14 ++ ) {
T_1 V_196 , V_197 ;
int V_36 ;
V_36 = F_71 ( V_8 ,
V_9 -> V_95 . V_111 [ V_14 ] ,
V_149 ,
& V_197 , & V_196 ) ;
if ( V_36 == 0 )
V_195 |= V_196 ;
}
return V_195 ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_130 ( V_8 ,
F_128 ( V_8 ) ) ;
}
static void F_131 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
bool V_22 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
if ( V_22 )
F_132 ( V_8 ,
V_199 -> V_61 . V_111 ,
V_149 ) ;
else
F_133 ( V_8 ,
F_128 ( V_8 ) ) ;
}
static void F_134 ( struct V_7 * V_8 , bool V_22 )
{
if ( V_22 ) {
T_1 V_13 = ( F_135 ( V_200 ) |
F_136 ( V_200 ) |
F_137 ( V_201 ) |
F_138 ( V_201 ) |
F_139 ( 0x3FFF ) |
F_140 ( 7 ) ) ;
F_87 ( V_202 , V_13 ) ;
F_36 ( V_203 , V_204 , ~ V_204 ) ;
} else
F_36 ( V_203 , 0 , ~ V_204 ) ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_142 ( V_8 , V_99 ) ;
}
static void F_143 ( T_1 V_205 , T_1 V_206 , int V_207 ,
int V_208 , int V_209 , T_2 * V_210 , T_2 * V_211 )
{
int V_212 , V_213 , V_214 , V_215 ;
V_214 = V_208 ;
V_215 = 100 - V_209 ;
V_212 = ( int ) V_206 * V_208 + ( int ) V_205 * ( V_207 - V_209 ) ;
V_213 = ( int ) V_205 * V_215 + ( int ) V_206 * V_214 ;
if ( V_213 != 0 ) {
* V_210 = V_208 - V_214 * V_212 / V_213 ;
* V_211 = V_209 + V_215 * V_212 / V_213 ;
}
}
static void F_144 ( struct V_7 * V_8 ,
struct V_1 * V_94 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_174 [ 0 ] = 0 ;
V_9 -> V_95 . V_173 [ V_216 - 1 ]
= 100 ;
F_143 ( V_94 -> V_61 . V_98 ,
V_94 -> V_100 . V_98 ,
V_217 ,
V_218 ,
V_219 ,
& V_9 -> V_95 . V_174 [ 1 ] ,
& V_9 -> V_95 . V_173 [ 0 ] ) ;
F_143 ( V_94 -> V_100 . V_98 ,
V_94 -> V_62 . V_98 ,
V_217 ,
V_220 ,
V_221 ,
& V_9 -> V_95 . V_174 [ 2 ] ,
& V_9 -> V_95 . V_173 [ 1 ] ) ;
}
static void F_145 ( struct V_7 * V_8 ,
struct V_2 * V_198 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
F_57 ( V_8 , V_199 ) ;
F_58 ( V_8 , V_199 ) ;
F_59 ( V_8 , V_199 ) ;
F_144 ( V_8 , V_199 ) ;
}
static void F_146 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_67 ( V_8 ) ;
if ( V_9 -> V_222 )
F_73 ( V_8 ) ;
F_74 ( V_8 ) ;
F_65 ( V_8 ) ;
F_69 ( V_8 ) ;
F_81 ( V_8 ) ;
}
static void F_147 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_76 ( V_8 ) ;
if ( V_9 -> V_222 )
F_77 ( V_8 ) ;
F_78 ( V_8 ) ;
F_75 ( V_8 ) ;
}
static void F_148 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_149 ( V_8 , V_97 ,
V_9 -> V_95 . V_119 ) ;
F_150 ( V_8 , V_97 ,
V_9 -> V_95 . V_110 ) ;
F_151 ( V_8 , V_97 ,
V_9 -> V_95 . V_102 ) ;
F_152 ( V_8 , V_97 ,
V_223 ) ;
F_153 ( V_8 , V_97 ,
V_9 -> V_95 . V_115 [ V_97 ] ) ;
}
static void F_154 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_149 ( V_8 , V_97 , 0 ) ;
F_150 ( V_8 , V_97 , 0 ) ;
F_151 ( V_8 , V_97 , 0 ) ;
F_152 ( V_8 , V_97 ,
V_223 ) ;
F_153 ( V_8 , V_97 ,
V_9 -> V_95 . V_115 [ V_97 ] ) ;
}
static void F_155 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_149 ( V_8 , V_99 ,
V_9 -> V_95 . V_118 ) ;
F_150 ( V_8 , V_99 ,
V_9 -> V_95 . V_109 ) ;
F_151 ( V_8 , V_99 ,
V_9 -> V_95 . V_103 ) ;
F_152 ( V_8 , V_99 ,
V_223 ) ;
F_153 ( V_8 , V_99 ,
V_9 -> V_95 . V_115 [ V_99 ] ) ;
}
static void F_156 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_66 ( V_8 ,
V_106 ,
V_9 -> V_95 . V_105 [ V_9 -> V_95 . V_110 ] ) ;
F_149 ( V_8 , V_99 , 1 ) ;
F_150 ( V_8 , V_99 ,
V_106 ) ;
F_151 ( V_8 , V_99 ,
V_9 -> V_95 . V_103 ) ;
F_152 ( V_8 , V_99 ,
V_223 ) ;
F_40 ( V_8 , V_99 , false ) ;
F_153 ( V_8 , V_99 ,
V_9 -> V_95 . V_115 [ V_97 ] ) ;
}
static void F_157 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_149 ( V_8 , V_101 ,
V_9 -> V_95 . V_117 ) ;
F_150 ( V_8 , V_101 ,
V_9 -> V_95 . V_108 ) ;
F_151 ( V_8 , V_101 ,
V_9 -> V_95 . V_104 ) ;
F_152 ( V_8 , V_101 ,
V_224 ) ;
F_153 ( V_8 , V_101 ,
V_9 -> V_95 . V_115 [ V_101 ] ) ;
}
static void F_158 ( struct V_7 * V_8 , bool V_22 )
{
if ( V_22 )
F_36 ( V_77 , V_225 | V_226 ,
~ ( V_225 | V_226 ) ) ;
else
F_36 ( V_77 , 0 ,
~ ( V_227 | V_225 | V_226 ) ) ;
}
static void F_159 ( struct V_7 * V_8 )
{
T_1 V_13 = F_80 ( V_202 ) ;
V_13 &= ~ ( V_228 | V_229 ) ;
if ( V_8 -> V_10 . V_11 . V_230 & 1 ) {
V_13 |= F_137 ( V_231 ) ;
V_13 |= F_138 ( V_201 ) ;
} else if ( V_8 -> V_10 . V_11 . V_230 & 2 ) {
V_13 |= F_137 ( V_201 ) ;
V_13 |= F_138 ( V_231 ) ;
} else {
V_13 |= F_137 ( V_201 ) ;
V_13 |= F_138 ( V_201 ) ;
}
F_87 ( V_202 , V_13 ) ;
}
static void F_160 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
T_3 V_234 ;
V_234 = ( V_199 -> V_61 . V_111 >= V_233 -> V_61 . V_111 ) ?
V_199 -> V_61 . V_111 : V_233 -> V_61 . V_111 ;
F_70 ( V_8 , V_106 ,
V_234 ) ;
F_36 ( V_77 , F_161 ( V_106 ) ,
~ V_235 ) ;
}
static void F_162 ( struct V_7 * V_8 ,
struct V_2 * V_232 )
{
struct V_1 * V_233 = F_1 ( V_232 ) ;
F_70 ( V_8 , V_106 ,
V_233 -> V_61 . V_111 ) ;
F_36 ( V_77 , F_161 ( V_106 ) ,
~ V_235 ) ;
}
static void F_163 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
if ( ( V_199 -> V_61 . V_113 & V_114 ) &&
( V_233 -> V_61 . V_113 & V_114 ) )
F_36 ( V_77 , V_227 , ~ V_227 ) ;
else
F_36 ( V_77 , 0 , ~ V_227 ) ;
}
static void F_164 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
if ( ( V_199 -> V_61 . V_113 & V_116 ) !=
( V_233 -> V_61 . V_113 & V_116 ) )
F_3 ( V_8 ) ;
}
static void F_165 ( struct V_7 * V_8 ,
bool V_22 )
{
if ( V_22 )
F_36 ( V_77 , V_236 , ~ V_236 ) ;
else
F_36 ( V_77 , 0 , ~ V_236 ) ;
}
static void F_166 ( struct V_7 * V_8 ,
bool V_22 )
{
if ( V_22 )
F_36 ( V_77 , V_226 , ~ V_226 ) ;
else
F_36 ( V_77 , 0 , ~ V_226 ) ;
}
static int F_167 ( struct V_7 * V_8 ,
T_3 V_237 ,
T_3 V_238 )
{
T_3 V_239 ;
T_3 V_240 ;
T_3 V_241 ;
int V_242 ;
if ( ( F_168 ( V_8 , V_149 ,
& V_241 ) ) ||
( F_169 ( V_8 , V_149 ,
V_237 , & V_239 ) ) ||
( F_169 ( V_8 , V_149 ,
V_238 , & V_240 ) ) )
return - V_138 ;
if ( V_240 < V_239 )
V_242 = - ( int ) V_241 ;
else
V_242 = V_241 ;
while ( V_239 != V_240 ) {
V_239 += V_242 ;
F_70 ( V_8 , V_106 ,
V_239 ) ;
F_170 ( ( V_8 -> V_10 . V_11 . V_193 + 999 ) / 1000 ) ;
}
return 0 ;
}
static int F_171 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
if ( V_199 -> V_61 . V_111 > V_233 -> V_61 . V_111 )
return F_167 ( V_8 ,
V_233 -> V_61 . V_111 ,
V_199 -> V_61 . V_111 ) ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
if ( V_199 -> V_61 . V_111 < V_233 -> V_61 . V_111 )
return F_167 ( V_8 ,
V_233 -> V_61 . V_111 ,
V_199 -> V_61 . V_111 ) ;
else
return 0 ;
}
static void F_173 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( ( V_9 -> V_243 < 1 ) ||
( V_9 -> V_243 == 3 ) )
F_174 ( V_8 , V_101 , true ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_243 < 2 )
F_174 ( V_8 , V_99 , true ) ;
}
static void F_176 ( struct V_7 * V_8 , T_1 V_244 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
bool V_245 ;
enum V_246 V_247 ;
switch ( V_244 ) {
case 0 :
default:
V_245 = false ;
break;
case ( 1 << V_248 ) :
V_245 = true ;
V_247 = V_249 ;
break;
case ( 1 << V_250 ) :
V_245 = true ;
V_247 = V_251 ;
break;
case ( ( 1 << V_250 ) |
( 1 << V_248 ) ) :
V_245 = true ;
V_247 = V_252 ;
break;
}
if ( V_245 ) {
F_36 ( V_253 , F_177 ( V_247 ) , ~ V_254 ) ;
if ( V_9 -> V_255 )
F_36 ( V_77 , 0 , ~ V_256 ) ;
} else {
F_36 ( V_77 , V_256 , ~ V_256 ) ;
}
}
static void F_178 ( struct V_7 * V_8 ,
enum V_257 V_258 ,
bool V_22 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_22 ) {
if ( ! ( V_9 -> V_259 & ( 1 << V_258 ) ) ) {
V_9 -> V_259 |= 1 << V_258 ;
F_176 ( V_8 , V_9 -> V_259 ) ;
}
} else {
if ( V_9 -> V_259 & ( 1 << V_258 ) ) {
V_9 -> V_259 &= ~ ( 1 << V_258 ) ;
F_176 ( V_8 , V_9 -> V_259 ) ;
}
}
}
static void F_179 ( struct V_7 * V_8 ,
bool V_22 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_259 )
F_180 ( V_8 , V_22 ) ;
}
static void F_181 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_233 = F_1 ( V_232 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_32 ( V_8 ,
V_233 -> V_61 . V_98 ,
V_199 -> V_61 . V_98 ,
0 , & V_9 -> V_95 . V_103 ) ;
}
static void F_182 ( struct V_7 * V_8 ,
struct V_2 * V_198 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_102 = 0 ;
F_33 ( V_8 ,
V_199 -> V_61 . V_98 ,
0 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_34 ( V_8 , 0 ,
V_9 -> V_95 . V_103 ) ;
}
static void F_184 ( struct V_7 * V_8 ,
struct V_2 * V_198 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_95 . V_102 = 0 ;
F_32 ( V_8 ,
V_199 -> V_61 . V_98 ,
V_199 -> V_100 . V_98 ,
0 ,
& V_9 -> V_95 . V_103 ) ;
F_32 ( V_8 ,
V_199 -> V_100 . V_98 ,
V_199 -> V_62 . V_98 ,
V_9 -> V_95 . V_103 ,
& V_9 -> V_95 . V_104 ) ;
}
static void F_185 ( struct V_7 * V_8 ,
bool V_22 )
{
if ( V_22 )
F_44 ( V_8 , true ) ;
else {
F_40 ( V_8 , V_97 , false ) ;
F_40 ( V_8 , V_99 , false ) ;
F_40 ( V_8 , V_101 , false ) ;
F_44 ( V_8 , false ) ;
F_43 ( V_8 , false ) ;
}
}
static void F_186 ( struct V_7 * V_8 )
{
if ( F_187 ( V_8 ) )
F_36 ( V_260 , V_261 , ~ V_261 ) ;
else
F_36 ( V_262 , V_261 , ~ V_261 ) ;
}
static void F_188 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
bool V_22 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
if ( V_22 ) {
F_8 ( V_8 , true ) ;
F_7 ( V_8 ) ;
F_189 ( V_8 , true ) ;
} else {
if ( ! ( V_199 -> V_61 . V_113 & V_116 ) )
F_3 ( V_8 ) ;
F_8 ( V_8 , false ) ;
F_189 ( V_8 , false ) ;
}
}
static void F_190 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_263 = F_1 ( V_232 ) ;
if ( ( V_198 -> V_264 == V_232 -> V_264 ) &&
( V_198 -> V_265 == V_232 -> V_265 ) )
return;
if ( V_199 -> V_62 . V_98 >= V_263 -> V_62 . V_98 )
return;
F_191 ( V_8 , V_198 -> V_264 , V_198 -> V_265 ) ;
}
static void F_192 ( struct V_7 * V_8 ,
struct V_2 * V_198 ,
struct V_2 * V_232 )
{
struct V_1 * V_199 = F_1 ( V_198 ) ;
struct V_1 * V_263 = F_1 ( V_232 ) ;
if ( ( V_198 -> V_264 == V_232 -> V_264 ) &&
( V_198 -> V_265 == V_232 -> V_265 ) )
return;
if ( V_199 -> V_62 . V_98 < V_263 -> V_62 . V_98 )
return;
F_191 ( V_8 , V_198 -> V_264 , V_198 -> V_265 ) ;
}
int F_193 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_266 = V_8 -> V_10 . V_11 . V_266 ;
if ( F_194 ( V_8 ) )
return - V_138 ;
if ( V_8 -> V_10 . V_11 . V_267 & V_268 )
F_158 ( V_8 , true ) ;
if ( V_9 -> V_269 )
F_185 ( V_8 , true ) ;
F_92 ( V_8 ) ;
F_95 ( V_8 ) ;
F_100 ( V_8 ) ;
F_102 ( V_8 ) ;
F_108 ( V_8 ) ;
F_111 ( V_8 ) ;
F_114 ( V_8 ) ;
F_117 ( V_8 ) ;
F_123 ( V_8 ) ;
F_126 ( V_8 ) ;
F_134 ( V_8 , true ) ;
if ( V_9 -> V_270 == false )
F_134 ( V_8 , false ) ;
F_141 ( V_8 ) ;
F_145 ( V_8 , V_266 ) ;
if ( V_9 -> V_222 )
F_129 ( V_8 ) ;
F_184 ( V_8 , V_266 ) ;
F_146 ( V_8 ) ;
F_147 ( V_8 ) ;
F_148 ( V_8 ) ;
F_155 ( V_8 ) ;
F_157 ( V_8 ) ;
F_105 ( V_8 ) ;
F_98 ( V_8 ) ;
F_174 ( V_8 , V_97 , true ) ;
F_174 ( V_8 , V_99 , true ) ;
F_174 ( V_8 , V_101 , true ) ;
F_178 ( V_8 , V_248 , true ) ;
F_195 ( V_8 ) ;
if ( V_9 -> V_222 )
F_131 ( V_8 , V_266 , false ) ;
if ( V_9 -> V_271 )
F_188 ( V_8 , V_266 , true ) ;
if ( V_9 -> V_272 )
F_196 ( V_8 , true ) ;
return 0 ;
}
void F_197 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_266 = V_8 -> V_10 . V_11 . V_266 ;
if ( ! F_194 ( V_8 ) )
return;
F_174 ( V_8 , V_97 , true ) ;
F_174 ( V_8 , V_99 , true ) ;
F_134 ( V_8 , false ) ;
F_107 ( V_8 ) ;
F_99 ( V_8 , 0xFFFF , 0xFFFF , 0xFFFF , 0xFFFF ) ;
if ( V_9 -> V_255 )
F_180 ( V_8 , false ) ;
F_198 ( V_8 , V_97 ) ;
F_174 ( V_8 , V_101 , false ) ;
F_174 ( V_8 , V_99 , false ) ;
if ( V_8 -> V_10 . V_11 . V_267 & V_268 )
F_158 ( V_8 , false ) ;
F_185 ( V_8 , false ) ;
if ( V_9 -> V_222 )
F_131 ( V_8 , V_266 , true ) ;
if ( V_9 -> V_271 )
F_188 ( V_8 , V_266 , false ) ;
if ( V_8 -> V_273 . V_274 &&
F_199 ( V_8 -> V_10 . V_275 ) ) {
V_8 -> V_273 . V_276 = false ;
F_200 ( V_8 ) ;
}
if ( V_9 -> V_272 )
F_196 ( V_8 , false ) ;
F_201 ( V_8 ) ;
}
int F_202 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_198 = V_8 -> V_10 . V_11 . V_277 ;
struct V_2 * V_232 = V_8 -> V_10 . V_11 . V_278 ;
int V_36 ;
V_9 -> V_243 = 0 ;
F_190 ( V_8 , V_198 , V_232 ) ;
F_107 ( V_8 ) ;
F_174 ( V_8 , V_97 , true ) ;
F_99 ( V_8 , 0xFFFF , 0xFFFF , 0xFFFF , 0xFFFF ) ;
if ( V_9 -> V_255 )
F_180 ( V_8 , false ) ;
F_198 ( V_8 , V_97 ) ;
F_174 ( V_8 , V_101 , false ) ;
F_174 ( V_8 , V_99 , false ) ;
F_181 ( V_8 , V_198 , V_232 ) ;
F_156 ( V_8 ) ;
if ( V_9 -> V_222 ) {
F_160 ( V_8 , V_198 , V_232 ) ;
if ( V_8 -> V_10 . V_11 . V_267 & V_279 )
F_162 ( V_8 , V_232 ) ;
}
if ( V_8 -> V_10 . V_11 . V_267 & V_268 )
F_163 ( V_8 , V_198 , V_232 ) ;
if ( V_9 -> V_271 )
F_164 ( V_8 , V_198 , V_232 ) ;
if ( V_9 -> V_222 )
F_165 ( V_8 , false ) ;
if ( V_8 -> V_10 . V_11 . V_267 & V_268 )
F_166 ( V_8 , false ) ;
if ( V_9 -> V_222 ) {
if ( V_8 -> V_10 . V_11 . V_267 & V_279 )
F_171 ( V_8 , V_198 , V_232 ) ;
F_170 ( ( V_8 -> V_10 . V_11 . V_193 + 999 ) / 1000 ) ;
}
F_174 ( V_8 , V_99 , true ) ;
F_174 ( V_8 , V_97 , false ) ;
F_203 ( V_8 , V_97 ) ;
F_182 ( V_8 , V_198 ) ;
F_183 ( V_8 ) ;
F_145 ( V_8 , V_198 ) ;
F_147 ( V_8 ) ;
F_154 ( V_8 ) ;
F_174 ( V_8 , V_97 , true ) ;
F_198 ( V_8 , V_97 ) ;
F_174 ( V_8 , V_99 , false ) ;
if ( V_9 -> V_222 ) {
if ( V_8 -> V_10 . V_11 . V_267 & V_279 ) {
V_36 = F_172 ( V_8 , V_198 , V_232 ) ;
if ( V_36 )
return V_36 ;
}
F_165 ( V_8 , true ) ;
}
if ( V_8 -> V_10 . V_11 . V_267 & V_268 )
F_166 ( V_8 , true ) ;
if ( V_9 -> V_271 )
F_188 ( V_8 , V_198 , true ) ;
F_186 ( V_8 ) ;
F_184 ( V_8 , V_198 ) ;
F_146 ( V_8 ) ;
F_148 ( V_8 ) ;
F_155 ( V_8 ) ;
F_157 ( V_8 ) ;
F_175 ( V_8 ) ;
F_173 ( V_8 ) ;
if ( V_9 -> V_255 )
F_179 ( V_8 , true ) ;
F_105 ( V_8 ) ;
F_98 ( V_8 ) ;
F_192 ( V_8 , V_198 , V_232 ) ;
return 0 ;
}
void F_204 ( struct V_7 * V_8 )
{
F_205 ( V_8 ) ;
if ( V_280 != 0 ) {
if ( V_8 -> V_10 . V_11 . V_267 & V_281 )
F_10 ( V_8 ) ;
if ( V_8 -> V_10 . V_11 . V_267 & V_282 )
F_12 ( V_8 ) ;
if ( V_8 -> V_10 . V_11 . V_267 & V_283 )
F_14 ( V_8 ) ;
}
}
void F_206 ( struct V_7 * V_8 )
{
F_159 ( V_8 ) ;
}
static void F_207 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_284 * V_285 )
{
V_3 -> V_286 = F_208 ( V_285 -> V_287 ) ;
V_3 -> V_288 = F_209 ( V_285 -> V_289 ) ;
V_3 -> V_290 = F_209 ( V_285 -> V_291 ) ;
if ( F_210 ( V_3 -> V_288 , V_3 -> V_290 ) ) {
V_3 -> V_264 = V_292 ;
V_3 -> V_265 = V_293 ;
} else {
V_3 -> V_264 = 0 ;
V_3 -> V_265 = 0 ;
}
if ( V_3 -> V_288 & V_294 )
V_8 -> V_10 . V_11 . V_266 = V_3 ;
if ( V_3 -> V_288 & V_295 )
V_8 -> V_10 . V_11 . V_296 = V_3 ;
}
static void F_211 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_69 ,
union V_297 * V_298 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_98 , V_107 ;
T_3 V_111 ;
struct V_299 * V_300 ;
switch ( V_69 ) {
case 0 :
V_300 = & V_4 -> V_61 ;
break;
case 1 :
V_300 = & V_4 -> V_100 ;
break;
case 2 :
default:
V_300 = & V_4 -> V_62 ;
break;
}
V_98 = F_209 ( V_298 -> V_301 . V_302 ) ;
V_98 |= V_298 -> V_301 . V_303 << 16 ;
V_107 = F_209 ( V_298 -> V_301 . V_304 ) ;
V_107 |= V_298 -> V_301 . V_305 << 16 ;
V_300 -> V_107 = V_107 ;
V_300 -> V_98 = V_98 ;
V_300 -> V_111 = F_209 ( V_298 -> V_301 . V_306 ) ;
V_300 -> V_113 = F_208 ( V_298 -> V_301 . V_307 ) ;
if ( V_300 -> V_111 == 0xff01 ) {
if ( F_212 ( V_8 , 0 , 0 , & V_111 ) == 0 )
V_300 -> V_111 = V_111 ;
}
if ( V_300 -> V_113 & V_116 ) {
if ( ( V_8 -> V_308 == V_309 ) || ( V_8 -> V_308 == V_310 ) ) {
if ( V_300 -> V_111 < 1100 )
V_300 -> V_113 &= ~ V_116 ;
}
}
if ( V_3 -> V_288 & V_294 ) {
T_3 V_111 , V_311 , V_312 ;
F_213 ( V_8 , & V_111 , & V_311 , & V_312 ) ;
V_300 -> V_107 = V_8 -> clock . V_313 ;
V_300 -> V_98 = V_8 -> clock . V_314 ;
V_300 -> V_111 = V_111 ;
}
}
static int F_214 ( struct V_7 * V_8 )
{
struct V_315 * V_316 = & V_8 -> V_316 ;
struct V_284 * V_285 ;
union V_317 * V_318 ;
int V_14 , V_319 ;
union V_297 * V_298 ;
union V_320 * V_320 ;
int V_69 = F_215 ( V_321 , V_322 ) ;
T_3 V_323 ;
T_2 V_324 , V_325 ;
struct V_1 * V_4 ;
if ( ! F_216 ( V_316 -> V_326 , V_69 , NULL ,
& V_324 , & V_325 , & V_323 ) )
return - V_138 ;
V_320 = (union V_320 * ) ( V_316 -> V_326 -> V_327 + V_323 ) ;
V_8 -> V_10 . V_11 . V_4 = F_217 ( sizeof( struct V_2 ) *
V_320 -> V_328 . V_329 , V_330 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_331 ;
for ( V_14 = 0 ; V_14 < V_320 -> V_328 . V_329 ; V_14 ++ ) {
V_318 = (union V_317 * )
( V_316 -> V_326 -> V_327 + V_323 +
F_209 ( V_320 -> V_328 . V_332 ) +
V_14 * V_320 -> V_328 . V_333 ) ;
V_285 = (struct V_284 * )
( V_316 -> V_326 -> V_327 + V_323 +
F_209 ( V_320 -> V_328 . V_334 ) +
( V_318 -> V_335 . V_336 *
V_320 -> V_328 . V_337 ) ) ;
if ( V_320 -> V_328 . V_333 - 1 ) {
T_2 * V_338 ;
V_4 = F_217 ( sizeof( struct V_1 ) , V_330 ) ;
if ( V_4 == NULL ) {
F_218 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_331 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_14 ] . V_5 = V_4 ;
F_207 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_14 ] ,
V_285 ) ;
V_338 = ( T_2 * ) & V_318 -> V_335 . V_339 [ 0 ] ;
for ( V_319 = 0 ; V_319 < ( V_320 -> V_328 . V_333 - 1 ) ; V_319 ++ ) {
V_298 = (union V_297 * )
( V_316 -> V_326 -> V_327 + V_323 +
F_209 ( V_320 -> V_328 . V_340 ) +
( V_338 [ V_319 ] * V_320 -> V_328 . V_341 ) ) ;
F_211 ( V_8 ,
& V_8 -> V_10 . V_11 . V_4 [ V_14 ] , V_319 ,
V_298 ) ;
}
}
}
V_8 -> V_10 . V_11 . V_342 = V_320 -> V_328 . V_329 ;
return 0 ;
}
int F_219 ( struct V_7 * V_8 )
{
struct V_130 V_131 ;
struct V_37 V_38 ;
struct V_6 * V_9 ;
int V_36 ;
V_9 = F_217 ( sizeof( struct V_6 ) , V_330 ) ;
if ( V_9 == NULL )
return - V_331 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
V_36 = F_220 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_214 ( V_8 ) ;
if ( V_36 )
return V_36 ;
if ( V_8 -> V_10 . V_11 . V_193 == 0 )
V_8 -> V_10 . V_11 . V_193 = V_343 ;
if ( V_8 -> V_10 . V_11 . V_194 == 0 )
V_8 -> V_10 . V_11 . V_194 = V_344 ;
V_36 = F_18 ( V_8 , V_39 ,
0 , false , & V_38 ) ;
if ( V_36 )
V_9 -> V_51 = V_38 . V_123 + 1 ;
else
V_9 -> V_51 = V_345 ;
V_36 = F_18 ( V_8 , V_137 ,
0 , false , & V_38 ) ;
if ( V_36 )
V_9 -> V_168 = V_38 . V_123 + 1 ;
else
V_9 -> V_168 = V_345 ;
if ( V_8 -> V_308 >= V_346 )
V_9 -> V_55 = 1 ;
else
V_9 -> V_55 = 0 ;
V_9 -> V_222 =
F_221 ( V_8 , V_149 , 0 ) ;
V_9 -> V_272 = true ;
V_9 -> V_132 = F_64 ( V_8 , & V_131 ,
V_133 , 0 ) ;
V_9 -> V_144 = F_64 ( V_8 , & V_131 ,
V_145 , 0 ) ;
V_9 -> V_132 = false ;
if ( V_9 -> V_132 || V_9 -> V_144 )
V_9 -> V_269 = true ;
else
V_9 -> V_269 = false ;
V_9 -> V_271 = true ;
if ( V_9 -> V_272 &&
( V_8 -> V_10 . V_275 != V_347 ) )
V_9 -> V_255 = true ;
else
V_9 -> V_255 = false ;
V_9 -> V_270 = true ;
return 0 ;
}
void F_222 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_299 * V_300 ;
F_223 ( V_3 -> V_288 , V_3 -> V_290 ) ;
F_224 ( V_3 -> V_286 ) ;
F_225 ( L_1 , V_3 -> V_264 , V_3 -> V_265 ) ;
V_300 = & V_4 -> V_61 ;
F_225 ( L_2 ,
V_300 -> V_98 , V_300 -> V_107 , V_300 -> V_111 ) ;
V_300 = & V_4 -> V_100 ;
F_225 ( L_3 ,
V_300 -> V_98 , V_300 -> V_107 , V_300 -> V_111 ) ;
V_300 = & V_4 -> V_62 ;
F_225 ( L_4 ,
V_300 -> V_98 , V_300 -> V_107 , V_300 -> V_111 ) ;
F_226 ( V_8 , V_3 ) ;
}
void F_227 ( struct V_7 * V_8 ,
struct V_348 * V_349 )
{
struct V_2 * V_3 = V_8 -> V_10 . V_11 . V_278 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_299 * V_300 ;
T_1 V_350 =
( F_80 ( V_351 ) & V_352 ) >>
V_353 ;
if ( V_350 > 2 ) {
F_228 ( V_349 , L_5 , V_350 ) ;
} else {
if ( V_350 == 0 )
V_300 = & V_4 -> V_61 ;
else if ( V_350 == 1 )
V_300 = & V_4 -> V_100 ;
else
V_300 = & V_4 -> V_62 ;
F_228 ( V_349 , L_6 , V_3 -> V_264 , V_3 -> V_265 ) ;
F_228 ( V_349 , L_7 ,
V_350 , V_300 -> V_98 , V_300 -> V_107 , V_300 -> V_111 ) ;
}
}
T_1 F_229 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 . V_11 . V_278 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_299 * V_300 ;
T_1 V_350 =
( F_80 ( V_351 ) & V_352 ) >>
V_353 ;
if ( V_350 > 2 ) {
return 0 ;
} else {
if ( V_350 == 0 )
V_300 = & V_4 -> V_61 ;
else if ( V_350 == 1 )
V_300 = & V_4 -> V_100 ;
else
V_300 = & V_4 -> V_62 ;
return V_300 -> V_98 ;
}
}
T_1 F_230 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 . V_11 . V_278 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_299 * V_300 ;
T_1 V_350 =
( F_80 ( V_351 ) & V_352 ) >>
V_353 ;
if ( V_350 > 2 ) {
return 0 ;
} else {
if ( V_350 == 0 )
V_300 = & V_4 -> V_61 ;
else if ( V_350 == 1 )
V_300 = & V_4 -> V_100 ;
else
V_300 = & V_4 -> V_62 ;
return V_300 -> V_107 ;
}
}
void F_231 ( struct V_7 * V_8 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_8 -> V_10 . V_11 . V_342 ; V_14 ++ ) {
F_218 ( V_8 -> V_10 . V_11 . V_4 [ V_14 ] . V_5 ) ;
}
F_218 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_218 ( V_8 -> V_10 . V_11 . V_12 ) ;
}
T_1 F_232 ( struct V_7 * V_8 , bool V_61 )
{
struct V_1 * V_354 = F_1 ( V_8 -> V_10 . V_11 . V_277 ) ;
if ( V_61 )
return V_354 -> V_61 . V_98 ;
else
return V_354 -> V_62 . V_98 ;
}
T_1 F_233 ( struct V_7 * V_8 , bool V_61 )
{
struct V_1 * V_354 = F_1 ( V_8 -> V_10 . V_11 . V_277 ) ;
if ( V_61 )
return V_354 -> V_61 . V_107 ;
else
return V_354 -> V_62 . V_107 ;
}
int F_234 ( struct V_7 * V_8 ,
enum V_355 V_129 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_129 == V_356 ) {
V_9 -> V_243 = 3 ;
} else if ( V_129 == V_357 ) {
V_9 -> V_243 = 2 ;
} else {
V_9 -> V_243 = 0 ;
}
F_107 ( V_8 ) ;
F_174 ( V_8 , V_97 , true ) ;
F_99 ( V_8 , 0xFFFF , 0xFFFF , 0xFFFF , 0xFFFF ) ;
F_198 ( V_8 , V_97 ) ;
F_174 ( V_8 , V_101 , false ) ;
F_174 ( V_8 , V_99 , false ) ;
F_175 ( V_8 ) ;
F_173 ( V_8 ) ;
if ( V_9 -> V_243 == 3 )
F_174 ( V_8 , V_97 , false ) ;
F_105 ( V_8 ) ;
F_98 ( V_8 ) ;
V_8 -> V_10 . V_11 . V_358 = V_129 ;
return 0 ;
}
