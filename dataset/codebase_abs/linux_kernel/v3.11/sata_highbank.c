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
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_23 ;
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
F_4 ( V_2 -> V_14 [ V_40 ] , 1 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_14 [ V_40 ] , 0 ) ;
for ( V_28 = 0 ; V_28 < ( V_41 * V_2 -> V_42 ) ; V_28 ++ ) {
F_4 ( V_2 -> V_14 [ V_43 ] , V_31 & 1 ) ;
V_31 >>= 1 ;
F_3 ( V_2 ) ;
}
V_30 -> V_44 = V_6 ;
F_8 ( & V_38 , V_26 ) ;
return V_18 ;
}
static void F_9 ( struct V_45 * V_46 ,
struct V_19 * V_20 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = V_46 -> V_51 ;
struct V_1 * V_2 = V_20 -> V_23 ;
int V_28 ;
int V_52 ;
for ( V_28 = 0 ; V_28 < V_53 ; V_28 ++ ) {
V_52 = F_10 ( V_50 , L_1 , V_28 ) ;
if ( F_11 ( V_52 ) )
return;
V_2 -> V_14 [ V_28 ] = V_52 ;
V_52 = F_12 ( V_2 -> V_14 [ V_28 ] , L_2 ) ;
if ( V_52 ) {
F_13 ( L_3 ,
V_28 , V_52 ) ;
return;
}
F_14 ( V_2 -> V_14 [ V_28 ] , 1 ) ;
}
F_15 ( V_50 , L_4 ,
V_2 -> V_5 ,
V_2 -> V_42 ) ;
V_20 -> V_54 = 0 ;
V_20 -> V_55 = 4 ;
V_20 -> V_36 = V_37 ;
V_48 -> V_26 |= V_56 | V_57 ;
}
static T_1 F_16 ( T_3 V_58 , T_1 V_59 )
{
T_1 V_60 ;
T_3 V_46 = V_61 [ V_58 ] . V_62 ;
F_17 ( & V_63 ) ;
F_18 ( F_19 ( V_46 , V_59 ) , V_61 [ V_58 ] . V_64 + 0x800 ) ;
V_60 = F_20 ( V_61 [ V_58 ] . V_64 + F_21 ( V_59 ) ) ;
F_22 ( & V_63 ) ;
return V_60 ;
}
static void F_23 ( T_3 V_58 , T_1 V_59 , T_1 V_60 )
{
T_3 V_46 = V_61 [ V_58 ] . V_62 ;
F_17 ( & V_63 ) ;
F_18 ( F_19 ( V_46 , V_59 ) , V_61 [ V_58 ] . V_64 + 0x800 ) ;
F_18 ( V_60 , V_61 [ V_58 ] . V_64 + F_21 ( V_59 ) ) ;
F_22 ( & V_63 ) ;
}
static void F_24 ( T_3 V_58 )
{
while ( F_16 ( V_58 , V_65 ) & V_66 )
F_5 ( 5 ) ;
}
static T_1 F_25 ( T_3 V_58 , T_1 V_59 )
{
F_24 ( V_58 ) ;
F_23 ( V_58 , V_67 , V_59 ) ;
F_23 ( V_58 , V_65 , V_68 ) ;
F_24 ( V_58 ) ;
return F_16 ( V_58 , V_69 ) ;
}
static void F_26 ( T_3 V_58 , T_1 V_59 , T_1 V_60 )
{
F_24 ( V_58 ) ;
F_23 ( V_58 , V_67 , V_59 ) ;
F_23 ( V_58 , V_69 , V_60 ) ;
F_23 ( V_58 , V_65 , V_70 | V_68 ) ;
}
static void F_27 ( T_3 V_58 )
{
T_3 V_71 = V_61 [ V_58 ] . V_72 ;
T_1 V_73 ;
if ( F_28 ( V_61 [ V_58 ] . V_64 == NULL ) )
return;
V_73 = F_25 ( V_58 , V_74 + V_71 * V_75 ) ;
V_73 &= ~ V_76 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
}
static void F_29 ( T_3 V_58 , T_1 V_78 )
{
T_3 V_71 = V_61 [ V_58 ] . V_72 ;
T_1 V_73 ;
V_73 = F_25 ( V_58 , V_74 + V_71 * V_75 ) ;
V_73 &= ~ V_76 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
V_73 |= V_76 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
V_73 &= ~ V_79 ;
V_73 |= V_78 << V_80 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
V_73 |= V_81 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
V_73 &= ~ V_81 ;
F_26 ( V_58 , V_77 + V_71 * V_75 , V_73 ) ;
F_30 ( 15 ) ;
}
static void F_31 ( T_3 V_58 )
{
T_3 V_71 = V_61 [ V_58 ] . V_72 ;
T_1 V_73 , V_82 = 0 ;
if ( F_28 ( V_61 [ V_58 ] . V_64 == NULL ) )
return;
do {
V_73 = F_25 ( V_58 , V_74 +
V_71 * V_75 ) ;
} while ( ( V_73 & V_83 ) && ( V_82 ++ < 1000 ) );
F_29 ( V_58 , 3 ) ;
}
static int F_32 ( struct V_45 * V_46 , void T_4 * V_59 )
{
struct V_49 * V_84 = V_46 -> V_51 ;
int V_85 = 0 , V_86 , V_3 = 0 ;
void T_4 * V_87 [ V_88 ] ;
struct V_49 * V_89 [ V_88 ] ;
memset ( V_61 , 0 , sizeof( struct V_90 ) * V_91 ) ;
memset ( V_89 , 0 , sizeof( struct V_49 * ) * V_88 ) ;
do {
T_1 V_73 ;
struct V_92 V_93 ;
if ( F_33 ( V_84 ,
L_5 , L_6 ,
V_3 , & V_93 ) )
break;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
if ( V_89 [ V_86 ] == V_93 . V_50 )
break;
}
if ( V_89 [ V_86 ] == NULL ) {
V_89 [ V_86 ] = V_93 . V_50 ;
V_87 [ V_86 ] = F_34 ( V_89 [ V_86 ] , 0 ) ;
if ( V_87 [ V_86 ] == NULL ) {
return 0 ;
}
V_85 += 1 ;
}
V_61 [ V_3 ] . V_72 = V_93 . args [ 0 ] ;
F_35 ( V_89 [ V_86 ] , L_7 , & V_73 ) ;
V_61 [ V_3 ] . V_62 = V_73 ;
V_61 [ V_3 ] . V_64 = V_87 [ V_86 ] ;
F_36 ( V_93 . V_50 ) ;
V_3 += 1 ;
} while ( V_3 < V_91 );
return 0 ;
}
static int F_37 ( struct V_94 * V_95 , unsigned int * V_96 ,
unsigned long V_97 )
{
static const unsigned long V_98 [] = { 5 , 100 , 500 } ;
struct V_16 * V_17 = V_95 -> V_17 ;
struct V_24 * V_25 = V_17 -> V_22 ;
T_3 * V_99 = V_25 -> V_100 + V_101 ;
struct V_102 V_103 ;
bool V_104 ;
T_1 V_105 ;
int V_106 ;
int V_107 = 100 ;
F_38 ( V_17 ) ;
F_39 ( V_95 -> V_45 , & V_103 ) ;
V_103 . V_108 = V_109 ;
F_40 ( & V_103 , 0 , 0 , V_99 ) ;
do {
F_27 ( V_95 -> V_17 -> V_39 ) ;
V_106 = F_41 ( V_95 , V_98 , V_97 , & V_104 , NULL ) ;
F_31 ( V_95 -> V_17 -> V_39 ) ;
if ( F_42 ( V_95 , V_110 , & V_105 ) )
break;
if ( ! ( V_105 & 0x3 ) )
break;
} while ( ! V_104 && V_107 -- );
F_43 ( V_17 ) ;
if ( V_104 )
* V_96 = F_44 ( V_17 ) ;
return V_106 ;
}
static int F_45 ( struct V_111 * V_112 )
{
struct V_45 * V_46 = & V_112 -> V_46 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_113 * V_21 ;
struct V_114 * V_115 ;
int V_116 ;
int V_28 ;
int V_106 ;
T_1 V_42 ;
struct V_47 V_48 = V_117 ;
const struct V_47 * V_118 [] = { & V_48 , NULL } ;
V_115 = F_46 ( V_112 , V_119 , 0 ) ;
if ( ! V_115 ) {
F_47 ( V_46 , L_8 ) ;
return - V_35 ;
}
V_116 = F_48 ( V_112 , 0 ) ;
if ( V_116 <= 0 ) {
F_47 ( V_46 , L_9 ) ;
return - V_35 ;
}
V_20 = F_49 ( V_46 , sizeof( * V_20 ) , V_120 ) ;
if ( ! V_20 ) {
F_47 ( V_46 , L_10 ) ;
return - V_121 ;
}
V_2 = F_49 ( V_46 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 ) {
F_47 ( V_46 , L_11 ) ;
return - V_121 ;
}
V_20 -> V_26 |= ( unsigned long ) V_48 . V_22 ;
V_20 -> V_122 = F_50 ( V_46 , V_115 -> V_123 , F_51 ( V_115 ) ) ;
if ( ! V_20 -> V_122 ) {
F_47 ( V_46 , L_12 , V_115 ) ;
return - V_121 ;
}
V_106 = F_32 ( V_46 , V_20 -> V_122 ) ;
if ( V_106 )
return V_106 ;
F_52 ( V_46 , V_20 , 0 , 0 ) ;
if ( V_20 -> V_124 & V_125 )
V_48 . V_26 |= V_126 ;
if ( V_20 -> V_124 & V_127 )
V_48 . V_26 |= V_128 ;
V_42 = F_53 ( F_54 ( V_20 -> V_124 ) , F_55 ( V_20 -> V_129 ) ) ;
V_2 -> V_42 = V_42 ;
V_20 -> V_23 = V_2 ;
F_9 ( V_46 , V_20 , & V_48 ) ;
V_21 = F_56 ( V_46 , V_118 , V_42 ) ;
if ( ! V_21 ) {
V_106 = - V_121 ;
goto V_130;
}
V_21 -> V_22 = V_20 ;
if ( ! ( V_20 -> V_124 & V_131 ) || V_132 )
V_21 -> V_26 |= V_133 ;
for ( V_28 = 0 ; V_28 < V_21 -> V_42 ; V_28 ++ ) {
struct V_16 * V_17 = V_21 -> V_134 [ V_28 ] ;
F_57 ( V_17 , L_13 , V_115 ) ;
F_57 ( V_17 , L_14 , 0x100 + V_17 -> V_39 * 0x80 ) ;
if ( V_17 -> V_26 & V_56 )
V_17 -> V_135 = V_20 -> V_36 ;
if ( ! ( V_20 -> V_129 & ( 1 << V_28 ) ) )
V_17 -> V_136 = & V_137 ;
}
V_106 = F_58 ( V_21 ) ;
if ( V_106 )
goto V_130;
F_59 ( V_21 ) ;
F_60 ( V_21 , L_15 ) ;
V_106 = F_61 ( V_21 , V_116 , V_138 , 0 ,
& V_139 ) ;
if ( V_106 )
goto V_130;
return 0 ;
V_130:
return V_106 ;
}
static int F_62 ( struct V_45 * V_46 )
{
struct V_113 * V_21 = F_63 ( V_46 ) ;
struct V_19 * V_20 = V_21 -> V_22 ;
void T_4 * V_122 = V_20 -> V_122 ;
T_1 V_140 ;
int V_106 ;
if ( V_20 -> V_26 & V_141 ) {
F_47 ( V_46 , L_16 ) ;
return - V_142 ;
}
V_140 = F_20 ( V_122 + V_143 ) ;
V_140 &= ~ V_144 ;
F_18 ( V_140 , V_122 + V_143 ) ;
F_20 ( V_122 + V_143 ) ;
V_106 = F_64 ( V_21 , V_145 ) ;
if ( V_106 )
return V_106 ;
return 0 ;
}
static int F_65 ( struct V_45 * V_46 )
{
struct V_113 * V_21 = F_63 ( V_46 ) ;
int V_106 ;
if ( V_46 -> V_146 . V_147 . V_148 == V_149 ) {
V_106 = F_58 ( V_21 ) ;
if ( V_106 )
return V_106 ;
F_59 ( V_21 ) ;
}
F_66 ( V_21 ) ;
return 0 ;
}
