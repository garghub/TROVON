static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
return 1 << ( 3 * V_2 -> V_5 [ V_3 ] + V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
if ( V_6 & V_7 )
V_2 -> V_8 |= F_1 ( V_2 , V_3 ,
V_9 ) ;
else
V_2 -> V_8 &= ~ F_1 ( V_2 , V_3 ,
V_9 ) ;
if ( V_6 & V_10 )
V_2 -> V_8 |= F_1 ( V_2 , V_3 ,
V_11 ) ;
else
V_2 -> V_8 &= ~ F_1 ( V_2 , V_3 ,
V_11 ) ;
if ( V_6 & V_12 )
V_2 -> V_8 |= F_1 ( V_2 , V_3 ,
V_13 ) ;
else
V_2 -> V_8 &= ~ F_1 ( V_2 , V_3 ,
V_13 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_14 [ V_15 ] , 1 ) ;
F_5 ( 50 ) ;
F_4 ( V_2 -> V_14 [ V_15 ] , 0 ) ;
F_5 ( 50 ) ;
}
static T_2 F_6 ( struct V_16 * V_17 , T_1 V_6 ,
T_2 V_18 )
{
struct V_19 * V_20 = V_17 -> V_21 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_23 ;
struct V_24 * V_25 = V_17 -> V_22 ;
unsigned long V_26 ;
int V_27 , V_28 ;
struct V_29 * V_30 ;
T_1 V_31 ;
V_27 = ( V_6 & V_32 ) >> 8 ;
if ( V_27 < V_33 )
V_30 = & V_25 -> V_34 [ V_27 ] ;
else
return - V_35 ;
if ( ! ( V_20 -> V_36 & V_37 ) )
return V_18 ;
F_7 ( & V_38 , V_26 ) ;
F_2 ( V_2 , V_17 -> V_39 , V_6 ) ;
V_31 = V_2 -> V_8 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_40 ; V_28 ++ )
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_14 [ V_41 ] , 1 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_14 [ V_41 ] , 0 ) ;
for ( V_28 = 0 ; V_28 < ( V_42 * V_2 -> V_43 ) ; V_28 ++ ) {
F_4 ( V_2 -> V_14 [ V_44 ] , V_31 & 1 ) ;
V_31 >>= 1 ;
F_3 ( V_2 ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_45 ; V_28 ++ )
F_3 ( V_2 ) ;
V_30 -> V_46 = V_6 ;
F_8 ( & V_38 , V_26 ) ;
return V_18 ;
}
static void F_9 ( struct V_47 * V_48 ,
struct V_19 * V_20 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_48 -> V_53 ;
struct V_1 * V_2 = V_20 -> V_23 ;
int V_28 ;
int V_54 ;
for ( V_28 = 0 ; V_28 < V_55 ; V_28 ++ ) {
V_54 = F_10 ( V_52 , L_1 , V_28 ) ;
if ( V_54 < 0 )
return;
V_2 -> V_14 [ V_28 ] = V_54 ;
V_54 = F_11 ( V_2 -> V_14 [ V_28 ] , L_2 ) ;
if ( V_54 ) {
F_12 ( L_3 ,
V_28 , V_54 ) ;
return;
}
F_13 ( V_2 -> V_14 [ V_28 ] , 1 ) ;
}
F_14 ( V_52 , L_4 ,
V_2 -> V_5 ,
V_2 -> V_43 ) ;
if ( F_15 ( V_52 , L_5 , & V_2 -> V_40 ) )
V_2 -> V_40 = 0 ;
if ( F_15 ( V_52 , L_6 ,
& V_2 -> V_45 ) )
V_2 -> V_45 = 0 ;
V_20 -> V_56 = 0 ;
V_20 -> V_57 = 4 ;
V_20 -> V_36 = V_37 ;
V_50 -> V_26 |= V_58 | V_59 ;
}
static T_1 F_16 ( T_3 V_60 , T_1 V_61 )
{
T_1 V_62 ;
T_3 V_48 = V_63 [ V_60 ] . V_64 ;
F_17 ( & V_65 ) ;
F_18 ( F_19 ( V_48 , V_61 ) , V_63 [ V_60 ] . V_66 + 0x800 ) ;
V_62 = F_20 ( V_63 [ V_60 ] . V_66 + F_21 ( V_61 ) ) ;
F_22 ( & V_65 ) ;
return V_62 ;
}
static void F_23 ( T_3 V_60 , T_1 V_61 , T_1 V_62 )
{
T_3 V_48 = V_63 [ V_60 ] . V_64 ;
F_17 ( & V_65 ) ;
F_18 ( F_19 ( V_48 , V_61 ) , V_63 [ V_60 ] . V_66 + 0x800 ) ;
F_18 ( V_62 , V_63 [ V_60 ] . V_66 + F_21 ( V_61 ) ) ;
F_22 ( & V_65 ) ;
}
static void F_24 ( T_3 V_60 )
{
while ( F_16 ( V_60 , V_67 ) & V_68 )
F_5 ( 5 ) ;
}
static T_1 F_25 ( T_3 V_60 , T_1 V_61 )
{
F_24 ( V_60 ) ;
F_23 ( V_60 , V_69 , V_61 ) ;
F_23 ( V_60 , V_67 , V_70 ) ;
F_24 ( V_60 ) ;
return F_16 ( V_60 , V_71 ) ;
}
static void F_26 ( T_3 V_60 , T_1 V_61 , T_1 V_62 )
{
F_24 ( V_60 ) ;
F_23 ( V_60 , V_69 , V_61 ) ;
F_23 ( V_60 , V_71 , V_62 ) ;
F_23 ( V_60 , V_67 , V_72 | V_70 ) ;
}
static void F_27 ( T_3 V_60 )
{
T_3 V_73 = V_63 [ V_60 ] . V_74 ;
T_1 V_75 ;
if ( F_28 ( V_63 [ V_60 ] . V_66 == NULL ) )
return;
V_75 = F_25 ( V_60 , V_76 + V_73 * V_77 ) ;
V_75 &= ~ V_78 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
}
static void F_29 ( T_3 V_60 , T_1 V_80 )
{
T_3 V_73 = V_63 [ V_60 ] . V_74 ;
T_1 V_75 ;
if ( V_80 & 0x8 )
return;
V_75 = F_25 ( V_60 , V_81 + V_73 * V_77 ) ;
V_75 &= ~ V_82 ;
F_26 ( V_60 , V_83 + V_73 * V_77 , V_75 ) ;
V_75 |= V_82 ;
F_26 ( V_60 , V_83 + V_73 * V_77 , V_75 ) ;
V_75 |= ( V_80 << V_84 ) & V_85 ;
F_26 ( V_60 , V_83 + V_73 * V_77 , V_75 ) ;
}
static void F_30 ( T_3 V_60 , T_1 V_80 )
{
T_3 V_73 = V_63 [ V_60 ] . V_74 ;
T_1 V_75 ;
V_75 = F_25 ( V_60 , V_76 + V_73 * V_77 ) ;
V_75 &= ~ V_78 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
V_75 |= V_78 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
V_75 &= ~ V_86 ;
V_75 |= V_80 << V_87 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
V_75 |= V_88 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
V_75 &= ~ V_88 ;
F_26 ( V_60 , V_79 + V_73 * V_77 , V_75 ) ;
F_31 ( 15 ) ;
}
static void F_32 ( T_3 V_60 )
{
T_3 V_73 = V_63 [ V_60 ] . V_74 ;
T_1 V_75 , V_89 = 0 ;
if ( F_28 ( V_63 [ V_60 ] . V_66 == NULL ) )
return;
do {
V_75 = F_25 ( V_60 , V_76 +
V_73 * V_77 ) ;
} while ( ( V_75 & V_90 ) && ( V_89 ++ < 1000 ) );
F_30 ( V_60 , 3 ) ;
F_29 ( V_60 , V_63 [ V_60 ] . V_91 ) ;
}
static int F_33 ( struct V_47 * V_48 , void T_4 * V_61 )
{
struct V_51 * V_92 = V_48 -> V_53 ;
int V_93 = 0 , V_94 , V_3 = 0 , V_28 ;
void T_4 * V_95 [ V_96 ] = {} ;
struct V_51 * V_97 [ V_96 ] = {} ;
T_1 V_91 [ V_98 ] = {} ;
memset ( V_63 , 0 , sizeof( struct V_99 ) * V_98 ) ;
do {
T_1 V_75 ;
struct V_100 V_101 ;
if ( F_34 ( V_92 ,
L_7 , L_8 ,
V_3 , & V_101 ) )
break;
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ ) {
if ( V_97 [ V_94 ] == V_101 . V_52 )
break;
}
if ( V_97 [ V_94 ] == NULL ) {
V_97 [ V_94 ] = V_101 . V_52 ;
V_95 [ V_94 ] = F_35 ( V_97 [ V_94 ] , 0 ) ;
if ( V_95 [ V_94 ] == NULL ) {
return 0 ;
}
V_93 += 1 ;
}
V_63 [ V_3 ] . V_74 = V_101 . args [ 0 ] ;
F_15 ( V_97 [ V_94 ] , L_9 , & V_75 ) ;
V_63 [ V_3 ] . V_64 = V_75 ;
V_63 [ V_3 ] . V_66 = V_95 [ V_94 ] ;
F_36 ( V_101 . V_52 ) ;
V_3 += 1 ;
} while ( V_3 < V_98 );
F_14 ( V_92 , L_10 ,
V_91 , V_3 ) ;
for ( V_28 = 0 ; V_28 < V_3 ; V_28 ++ )
V_63 [ V_28 ] . V_91 = ( T_3 ) V_91 [ V_28 ] ;
return 0 ;
}
static int F_37 ( struct V_102 * V_103 , unsigned int * V_104 ,
unsigned long V_105 )
{
static const unsigned long V_106 [] = { 5 , 100 , 500 } ;
struct V_16 * V_17 = V_103 -> V_17 ;
struct V_24 * V_25 = V_17 -> V_22 ;
struct V_19 * V_20 = V_17 -> V_21 -> V_22 ;
T_3 * V_107 = V_25 -> V_108 + V_109 ;
struct V_110 V_111 ;
bool V_112 ;
T_1 V_113 ;
int V_114 ;
int V_115 = 100 ;
F_38 ( V_17 ) ;
F_39 ( V_103 -> V_47 , & V_111 ) ;
V_111 . V_116 = V_117 ;
F_40 ( & V_111 , 0 , 0 , V_107 ) ;
do {
F_27 ( V_103 -> V_17 -> V_39 ) ;
V_114 = F_41 ( V_103 , V_106 , V_105 , & V_112 , NULL ) ;
F_32 ( V_103 -> V_17 -> V_39 ) ;
if ( F_42 ( V_103 , V_118 , & V_113 ) )
break;
if ( ! ( V_113 & 0x3 ) )
break;
} while ( ! V_112 && V_115 -- );
V_20 -> V_119 ( V_17 ) ;
if ( V_112 )
* V_104 = F_43 ( V_17 ) ;
return V_114 ;
}
static int F_44 ( struct V_120 * V_121 )
{
struct V_47 * V_48 = & V_121 -> V_48 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_122 * V_21 ;
struct V_123 * V_124 ;
int V_125 ;
int V_28 ;
int V_114 ;
T_1 V_43 ;
struct V_49 V_50 = V_126 ;
const struct V_49 * V_127 [] = { & V_50 , NULL } ;
V_124 = F_45 ( V_121 , V_128 , 0 ) ;
if ( ! V_124 ) {
F_46 ( V_48 , L_11 ) ;
return - V_35 ;
}
V_125 = F_47 ( V_121 , 0 ) ;
if ( V_125 <= 0 ) {
F_46 ( V_48 , L_12 ) ;
return - V_35 ;
}
V_20 = F_48 ( V_48 , sizeof( * V_20 ) , V_129 ) ;
if ( ! V_20 ) {
F_46 ( V_48 , L_13 ) ;
return - V_130 ;
}
V_2 = F_48 ( V_48 , sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 ) {
F_46 ( V_48 , L_14 ) ;
return - V_130 ;
}
V_20 -> V_125 = V_125 ;
V_20 -> V_26 |= ( unsigned long ) V_50 . V_22 ;
V_20 -> V_131 = F_49 ( V_48 , V_124 -> V_132 , F_50 ( V_124 ) ) ;
if ( ! V_20 -> V_131 ) {
F_46 ( V_48 , L_15 , V_124 ) ;
return - V_130 ;
}
V_114 = F_33 ( V_48 , V_20 -> V_131 ) ;
if ( V_114 )
return V_114 ;
F_51 ( V_48 , V_20 ) ;
if ( V_20 -> V_133 & V_134 )
V_50 . V_26 |= V_135 ;
if ( V_20 -> V_133 & V_136 )
V_50 . V_26 |= V_137 ;
if ( V_20 -> V_133 & V_138 )
F_52 ( V_48 , F_53 ( 64 ) ) ;
V_43 = F_54 ( F_55 ( V_20 -> V_133 ) , F_56 ( V_20 -> V_139 ) ) ;
V_2 -> V_43 = V_43 ;
V_20 -> V_23 = V_2 ;
F_9 ( V_48 , V_20 , & V_50 ) ;
V_21 = F_57 ( V_48 , V_127 , V_43 ) ;
if ( ! V_21 ) {
V_114 = - V_130 ;
goto V_140;
}
V_21 -> V_22 = V_20 ;
if ( ! ( V_20 -> V_133 & V_141 ) || V_142 )
V_21 -> V_26 |= V_143 ;
for ( V_28 = 0 ; V_28 < V_21 -> V_43 ; V_28 ++ ) {
struct V_16 * V_17 = V_21 -> V_144 [ V_28 ] ;
F_58 ( V_17 , L_16 , V_124 ) ;
F_58 ( V_17 , L_17 , 0x100 + V_17 -> V_39 * 0x80 ) ;
if ( V_17 -> V_26 & V_58 )
V_17 -> V_145 = V_20 -> V_36 ;
if ( ! ( V_20 -> V_139 & ( 1 << V_28 ) ) )
V_17 -> V_146 = & V_147 ;
}
V_114 = F_59 ( V_21 ) ;
if ( V_114 )
goto V_140;
F_60 ( V_21 ) ;
F_61 ( V_21 , L_18 ) ;
V_114 = F_62 ( V_21 , & V_148 ) ;
if ( V_114 )
goto V_140;
return 0 ;
V_140:
return V_114 ;
}
static int F_63 ( struct V_47 * V_48 )
{
struct V_122 * V_21 = F_64 ( V_48 ) ;
struct V_19 * V_20 = V_21 -> V_22 ;
void T_4 * V_131 = V_20 -> V_131 ;
T_1 V_149 ;
int V_114 ;
if ( V_20 -> V_26 & V_150 ) {
F_46 ( V_48 , L_19 ) ;
return - V_151 ;
}
V_149 = F_20 ( V_131 + V_152 ) ;
V_149 &= ~ V_153 ;
F_18 ( V_149 , V_131 + V_152 ) ;
F_20 ( V_131 + V_152 ) ;
V_114 = F_65 ( V_21 , V_154 ) ;
if ( V_114 )
return V_114 ;
return 0 ;
}
static int F_66 ( struct V_47 * V_48 )
{
struct V_122 * V_21 = F_64 ( V_48 ) ;
int V_114 ;
if ( V_48 -> V_155 . V_156 . V_157 == V_158 ) {
V_114 = F_59 ( V_21 ) ;
if ( V_114 )
return V_114 ;
F_60 ( V_21 ) ;
}
F_67 ( V_21 ) ;
return 0 ;
}
