static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
return F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) & ~ V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) | V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_1 V_12 = F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , ( V_12 & ~ V_10 ) | V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_9 ( V_2 -> clock ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_2 -> V_14 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_10 ( V_2 -> V_6 ) ;
if ( V_13 < 0 )
goto V_16;
return 0 ;
V_16:
F_11 ( V_2 -> V_14 ) ;
V_15:
F_11 ( V_2 -> clock ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> V_14 ) ;
F_11 ( V_2 -> clock ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = & V_2 -> V_19 . V_20 -> V_21 ;
unsigned long V_22 = V_18 -> clock * 1000 ;
unsigned long V_23 ;
T_1 V_12 ;
T_1 V_24 ;
T_1 div ;
V_23 = F_15 ( V_2 -> clock ) ;
div = F_16 ( V_23 , V_22 ) ;
div = F_17 ( div , 1U , 64U ) - 1 ;
V_24 = div | V_25 ;
if ( V_2 -> V_14 ) {
unsigned long V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
T_1 V_29 ;
V_26 = F_15 ( V_2 -> V_14 ) ;
V_29 = F_16 ( V_26 , V_22 ) ;
V_29 = F_17 ( V_29 , 1U , 64U ) - 1 ;
V_28 = V_23 / ( div + 1 ) ;
V_27 = V_26 / ( V_29 + 1 ) ;
if ( abs ( ( long ) V_27 - ( long ) V_22 ) <
abs ( ( long ) V_28 - ( long ) V_22 ) ) {
F_18 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_1 , V_2 -> V_30 ) ;
V_24 = V_29 | V_31 ;
}
}
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_32 : V_33 ,
V_24 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_34 : V_35 , 0 ) ;
V_12 = ( ( V_18 -> V_36 & V_37 ) ? 0 : V_38 )
| ( ( V_18 -> V_36 & V_39 ) ? 0 : V_40 )
| V_41 | V_42 ;
F_3 ( V_2 , V_43 , V_12 ) ;
F_3 ( V_2 , V_44 , V_18 -> V_45 - V_18 -> V_46 - 19 ) ;
F_3 ( V_2 , V_47 , V_18 -> V_45 - V_18 -> V_46 +
V_18 -> V_48 - 19 ) ;
F_3 ( V_2 , V_49 , V_18 -> V_50 -
V_18 -> V_46 - 1 ) ;
F_3 ( V_2 , V_51 , V_18 -> V_45 - 1 ) ;
F_3 ( V_2 , V_52 , V_18 -> V_53 -
V_18 -> V_54 - 2 ) ;
F_3 ( V_2 , V_55 , V_18 -> V_53 -
V_18 -> V_54 +
V_18 -> V_56 - 2 ) ;
F_3 ( V_2 , V_57 , V_18 -> V_53 -
V_18 -> V_54 +
V_18 -> V_58 - 1 ) ;
F_3 ( V_2 , V_59 , V_18 -> V_53 - 1 ) ;
F_3 ( V_2 , V_60 , V_18 -> V_45 - V_18 -> V_46 ) ;
F_3 ( V_2 , V_61 , V_18 -> V_48 ) ;
}
void F_20 ( struct V_62 * V_19 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_65 |= F_22 ( V_64 ) ;
if ( V_64 == V_66 )
V_5 -> V_67 = V_2 -> V_30 ;
}
static unsigned int F_23 ( struct V_68 * V_69 )
{
return F_24 ( V_69 -> V_69 . V_20 ) -> V_70 ;
}
static const struct V_71 *
F_25 ( struct V_68 * V_69 )
{
return F_24 ( V_69 -> V_69 . V_20 ) -> V_72 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_68 * V_73 [ V_74 ] ;
unsigned int V_75 = 0 ;
unsigned int V_76 = 0 ;
unsigned int V_77 ;
T_1 V_78 = 0 ;
T_1 V_79 = 0 ;
for ( V_77 = 0 ; V_77 < F_27 ( V_2 -> V_6 -> V_73 . V_73 ) ; ++ V_77 ) {
struct V_68 * V_69 = & V_2 -> V_6 -> V_73 . V_73 [ V_77 ] ;
unsigned int V_80 ;
if ( V_69 -> V_69 . V_20 -> V_19 != & V_2 -> V_19 )
continue;
for ( V_80 = V_75 ++ ; V_80 > 0 ; -- V_80 ) {
if ( F_23 ( V_73 [ V_80 - 1 ] ) <= F_23 ( V_69 ) )
break;
V_73 [ V_80 ] = V_73 [ V_80 - 1 ] ;
}
V_73 [ V_80 ] = V_69 ;
V_76 += F_25 ( V_69 ) -> V_73 * 4 ;
}
for ( V_77 = 0 ; V_77 < V_75 ; ++ V_77 ) {
struct V_68 * V_69 = V_73 [ V_77 ] ;
struct V_81 * V_20 = V_69 -> V_69 . V_20 ;
unsigned int V_30 = F_24 ( V_20 ) -> V_82 ;
V_76 -= 4 ;
V_79 |= ( V_30 + 1 ) << V_76 ;
V_78 |= F_28 ( V_30 ) | F_29 ( V_30 ) ;
if ( F_25 ( V_69 ) -> V_73 == 2 ) {
V_30 = ( V_30 + 1 ) % 8 ;
V_76 -= 4 ;
V_79 |= ( V_30 + 1 ) << V_76 ;
V_78 |= F_28 ( V_30 ) | F_29 ( V_30 ) ;
}
}
if ( V_2 -> V_30 % 2 ) {
F_30 ( & V_2 -> V_6 -> V_83 ) ;
if ( F_31 ( V_2 -> V_6 , V_84 ) != V_78 ) {
F_19 ( V_2 -> V_6 , V_84 , V_78 ) ;
if ( V_2 -> V_6 -> V_85 )
F_32 ( V_2 -> V_6 ) ;
}
F_33 ( & V_2 -> V_6 -> V_83 ) ;
}
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_86 : V_87 ,
V_79 ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_90 * V_91 ;
struct V_92 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
F_35 ( & V_7 -> V_93 , V_36 ) ;
V_91 = V_2 -> V_91 ;
if ( V_91 && V_91 -> V_94 . V_95 == V_89 ) {
V_2 -> V_91 = NULL ;
V_91 -> V_94 . V_96 ( & V_91 -> V_94 ) ;
F_36 ( & V_2 -> V_19 ) ;
}
F_37 ( & V_7 -> V_93 , V_36 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_92 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
F_35 ( & V_7 -> V_93 , V_36 ) ;
V_91 = V_2 -> V_91 ;
V_2 -> V_91 = NULL ;
F_37 ( & V_7 -> V_93 , V_36 ) ;
if ( V_91 == NULL )
return;
F_35 ( & V_7 -> V_93 , V_36 ) ;
F_39 ( V_7 , V_2 -> V_30 , V_91 ) ;
F_40 ( & V_2 -> V_97 ) ;
F_37 ( & V_7 -> V_93 , V_36 ) ;
F_36 ( & V_2 -> V_19 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_92 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
bool V_98 ;
F_35 ( & V_7 -> V_93 , V_36 ) ;
V_98 = V_2 -> V_91 != NULL ;
F_37 ( & V_7 -> V_93 , V_36 ) ;
return V_98 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_43 ( V_2 -> V_97 ,
! F_41 ( V_2 ) ,
F_44 ( 50 ) ) )
return;
F_45 ( V_5 -> V_7 , L_2 ) ;
F_38 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_62 * V_19 = & V_2 -> V_19 ;
bool V_99 ;
if ( V_2 -> V_100 )
return;
F_3 ( V_2 , V_101 , F_47 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_102 , F_48 ( 0 , 0 , 0 ) ) ;
F_14 ( V_2 ) ;
F_49 ( V_2 -> V_6 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_86 : V_87 , 0 ) ;
V_99 = V_2 -> V_19 . V_18 . V_36 & V_103 ;
F_7 ( V_2 , V_104 , V_105 | V_106 ,
( V_99 ? V_107 : 0 ) |
V_108 ) ;
F_50 ( V_2 -> V_6 , true ) ;
F_51 ( V_19 ) ;
V_2 -> V_100 = true ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_62 * V_19 = & V_2 -> V_19 ;
if ( ! V_2 -> V_100 )
return;
F_42 ( V_2 ) ;
F_53 ( V_19 ) ;
F_7 ( V_2 , V_104 , V_105 , V_109 ) ;
F_50 ( V_2 -> V_6 , false ) ;
V_2 -> V_100 = false ;
}
void F_54 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
unsigned int V_77 ;
if ( ! V_2 -> V_110 )
return;
F_8 ( V_2 ) ;
F_46 ( V_2 ) ;
for ( V_77 = 0 ; V_77 < F_27 ( V_2 -> V_6 -> V_73 . V_73 ) ; ++ V_77 ) {
struct V_68 * V_69 = & V_2 -> V_6 -> V_73 . V_73 [ V_77 ] ;
if ( V_69 -> V_69 . V_20 -> V_19 != & V_2 -> V_19 )
continue;
F_56 ( V_69 ) ;
}
F_26 ( V_2 ) ;
}
static void F_57 ( struct V_62 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
if ( V_2 -> V_110 )
return;
F_8 ( V_2 ) ;
F_46 ( V_2 ) ;
V_2 -> V_110 = true ;
}
static void F_58 ( struct V_62 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
if ( ! V_2 -> V_110 )
return;
F_52 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_110 = false ;
V_2 -> V_65 = 0 ;
}
static bool F_59 ( struct V_62 * V_19 ,
const struct V_17 * V_18 ,
struct V_17 * V_21 )
{
return true ;
}
static void F_60 ( struct V_62 * V_19 )
{
struct V_90 * V_91 = V_19 -> V_20 -> V_91 ;
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_92 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
if ( V_91 ) {
F_61 ( F_62 ( V_19 ) != 0 ) ;
F_35 ( & V_7 -> V_93 , V_36 ) ;
V_2 -> V_91 = V_91 ;
F_37 ( & V_7 -> V_93 , V_36 ) ;
}
}
static void F_63 ( struct V_62 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_26 ( V_2 ) ;
}
static T_2 F_64 ( int V_111 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
T_2 V_13 = V_113 ;
T_1 V_114 ;
V_114 = F_1 ( V_2 , V_115 ) ;
F_3 ( V_2 , V_116 , V_114 & V_117 ) ;
if ( V_114 & V_118 ) {
F_65 ( V_2 -> V_19 . V_7 , V_2 -> V_30 ) ;
F_38 ( V_2 ) ;
V_13 = V_119 ;
}
return V_13 ;
}
int F_66 ( struct V_120 * V_121 , unsigned int V_30 )
{
static const unsigned int V_122 [] = {
V_123 , V_124 , V_125
} ;
struct V_4 * V_5 = V_121 -> V_7 ;
struct V_126 * V_127 = F_67 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_128 [ V_30 ] ;
struct V_62 * V_19 = & V_2 -> V_19 ;
unsigned int V_129 ;
struct V_23 * V_23 ;
char V_130 [ 9 ] ;
char * V_131 ;
int V_111 ;
int V_13 ;
if ( F_68 ( V_5 , V_132 ) ) {
sprintf ( V_130 , L_3 , V_30 ) ;
V_131 = V_130 ;
} else {
V_131 = NULL ;
}
V_2 -> clock = F_69 ( V_5 -> V_7 , V_131 ) ;
if ( F_70 ( V_2 -> clock ) ) {
F_71 ( V_5 -> V_7 , L_4 , V_30 ) ;
return F_72 ( V_2 -> clock ) ;
}
sprintf ( V_130 , L_5 , V_30 ) ;
V_23 = F_69 ( V_5 -> V_7 , V_130 ) ;
if ( ! F_70 ( V_23 ) ) {
V_2 -> V_14 = V_23 ;
} else if ( F_72 ( V_2 -> clock ) == - V_133 ) {
F_73 ( V_5 -> V_7 , L_6 , V_30 ) ;
return - V_133 ;
}
F_74 ( & V_2 -> V_97 ) ;
V_2 -> V_6 = V_121 ;
V_2 -> V_8 = V_122 [ V_30 ] ;
V_2 -> V_30 = V_30 ;
V_2 -> V_110 = false ;
V_13 = F_75 ( V_5 -> V_134 , V_19 ,
& V_121 -> V_73 . V_73 [ V_30 % 2 ] . V_69 ,
NULL , & V_135 ) ;
if ( V_13 < 0 )
return V_13 ;
F_76 ( V_19 , & V_136 ) ;
F_53 ( V_19 ) ;
if ( F_68 ( V_5 , V_132 ) ) {
V_111 = F_77 ( V_127 , V_30 ) ;
V_129 = 0 ;
} else {
V_111 = F_77 ( V_127 , 0 ) ;
V_129 = V_137 ;
}
if ( V_111 < 0 ) {
F_71 ( V_5 -> V_7 , L_7 , V_30 ) ;
return V_111 ;
}
V_13 = F_78 ( V_5 -> V_7 , V_111 , F_64 , V_129 ,
F_79 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_71 ( V_5 -> V_7 ,
L_8 , V_30 ) ;
return V_13 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_2 , bool V_138 )
{
if ( V_138 ) {
F_3 ( V_2 , V_116 , V_139 ) ;
F_6 ( V_2 , V_140 , V_141 ) ;
} else {
F_5 ( V_2 , V_140 , V_141 ) ;
}
}
