static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
return F_2 ( V_5 , V_2 -> V_9 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
F_4 ( V_5 , V_2 -> V_9 + V_3 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
F_4 ( V_5 , V_2 -> V_9 + V_3 ,
F_2 ( V_5 , V_2 -> V_9 + V_3 ) & ~ V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
F_4 ( V_5 , V_2 -> V_9 + V_3 ,
F_2 ( V_5 , V_2 -> V_9 + V_3 ) | V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_11 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
T_1 V_13 = F_2 ( V_5 , V_2 -> V_9 + V_3 ) ;
F_4 ( V_5 , V_2 -> V_9 + V_3 , ( V_13 & ~ V_11 ) | V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_6 = & V_2 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
const struct V_15 * V_16 = & V_6 -> V_16 ;
unsigned long V_17 ;
T_1 V_13 ;
T_1 div ;
V_17 = F_9 ( V_5 -> clock ) ;
div = F_10 ( V_17 , V_16 -> clock * 1000 ) ;
div = F_11 ( div , 1U , 64U ) - 1 ;
F_4 ( V_5 , V_2 -> V_18 ? V_19 : V_20 ,
V_21 | div ) ;
F_4 ( V_5 , V_2 -> V_18 ? V_22 : V_23 , 0 ) ;
V_13 = ( ( V_16 -> V_24 & V_25 ) ? 0 : V_26 )
| ( ( V_16 -> V_24 & V_27 ) ? 0 : V_28 )
| V_29 ;
F_3 ( V_2 , V_30 , V_13 ) ;
F_3 ( V_2 , V_31 , V_16 -> V_32 - V_16 -> V_33 - 19 ) ;
F_3 ( V_2 , V_34 , V_16 -> V_32 - V_16 -> V_33 +
V_16 -> V_35 - 19 ) ;
F_3 ( V_2 , V_36 , V_16 -> V_37 -
V_16 -> V_33 - 1 ) ;
F_3 ( V_2 , V_38 , V_16 -> V_32 - 1 ) ;
F_3 ( V_2 , V_39 , V_16 -> V_40 - V_16 -> V_41 - 2 ) ;
F_3 ( V_2 , V_42 , V_16 -> V_40 - V_16 -> V_41 +
V_16 -> V_43 - 2 ) ;
F_3 ( V_2 , V_44 , V_16 -> V_40 - V_16 -> V_41 +
V_16 -> V_45 - 1 ) ;
F_3 ( V_2 , V_46 , V_16 -> V_40 - 1 ) ;
F_3 ( V_2 , V_47 , V_16 -> V_32 - V_16 -> V_33 ) ;
F_3 ( V_2 , V_48 , V_16 -> V_35 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
T_1 V_49 = F_2 ( V_5 , V_50 ) ;
V_49 &= ~ ( V_51 | V_52 | V_53 ) ;
if ( V_2 -> V_54 & ( 1 << 1 ) && V_2 -> V_18 == 0 )
V_49 |= V_55 ;
else
V_49 |= V_51 | V_52 | V_56 ;
F_4 ( V_5 , V_50 , V_49 ) ;
}
static void F_13 ( struct V_4 * V_5 , bool V_57 )
{
F_4 ( V_5 , V_58 ,
( F_2 ( V_5 , V_58 ) & ~ ( V_59 | V_60 ) ) |
( V_57 ? V_60 : V_59 ) ) ;
}
static void F_14 ( struct V_4 * V_5 , bool V_57 )
{
if ( V_57 ) {
if ( V_5 -> V_61 ++ != 0 )
F_13 ( V_5 , false ) ;
F_13 ( V_5 , true ) ;
} else {
if ( -- V_5 -> V_61 == 0 )
F_13 ( V_5 , false ) ;
}
}
void F_15 ( struct V_14 * V_6 , unsigned int V_62 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
V_2 -> V_54 |= 1 << V_62 ;
}
void F_17 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
struct V_1 * V_2 = F_16 ( V_6 ) ;
struct V_63 * V_64 [ V_65 ] ;
unsigned int V_66 = 0 ;
unsigned int V_67 = 0 ;
unsigned int V_68 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
for ( V_68 = 0 ; V_68 < F_18 ( V_5 -> V_64 . V_64 ) ; ++ V_68 ) {
struct V_63 * V_71 = & V_5 -> V_64 . V_64 [ V_68 ] ;
unsigned int V_72 ;
if ( V_71 -> V_6 != & V_2 -> V_6 || ! V_71 -> V_73 )
continue;
for ( V_72 = V_66 ++ ; V_72 > 0 ; -- V_72 ) {
if ( V_64 [ V_72 - 1 ] -> V_74 <= V_71 -> V_74 )
break;
V_64 [ V_72 ] = V_64 [ V_72 - 1 ] ;
}
V_64 [ V_72 ] = V_71 ;
V_67 += V_71 -> V_75 -> V_64 * 4 ;
}
for ( V_68 = 0 ; V_68 < V_66 ; ++ V_68 ) {
struct V_63 * V_71 = V_64 [ V_68 ] ;
unsigned int V_18 = V_71 -> V_76 ;
V_67 -= 4 ;
V_70 |= ( V_18 + 1 ) << V_67 ;
V_69 |= F_19 ( V_18 ) | F_20 ( V_18 ) ;
if ( V_71 -> V_75 -> V_64 == 2 ) {
V_18 = ( V_18 + 1 ) % 8 ;
V_67 -= 4 ;
V_70 |= ( V_18 + 1 ) << V_67 ;
V_69 |= F_19 ( V_18 ) | F_20 ( V_18 ) ;
}
}
if ( V_2 -> V_18 ) {
T_1 V_13 = F_2 ( V_5 , V_77 ) ;
if ( V_13 != V_69 ) {
F_4 ( V_5 , V_77 , V_69 ) ;
if ( V_5 -> V_61 ) {
F_13 ( V_5 , false ) ;
F_13 ( V_5 , true ) ;
}
}
}
F_4 ( V_5 , V_2 -> V_18 ? V_78 : V_79 , V_70 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_6 = & V_2 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
unsigned int V_68 ;
if ( V_2 -> V_80 )
return;
if ( F_22 ( V_2 -> V_71 -> V_75 == NULL ) )
return;
F_3 ( V_2 , V_81 , F_23 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_82 , F_24 ( 0 , 0 , 0 ) ) ;
F_8 ( V_2 ) ;
F_12 ( V_2 ) ;
F_25 ( & V_5 -> V_64 . V_83 ) ;
V_2 -> V_71 -> V_73 = true ;
F_17 ( V_6 ) ;
F_26 ( & V_5 -> V_64 . V_83 ) ;
for ( V_68 = 0 ; V_68 < F_18 ( V_5 -> V_64 . V_64 ) ; ++ V_68 ) {
struct V_63 * V_71 = & V_5 -> V_64 . V_64 [ V_68 ] ;
if ( V_71 -> V_6 != V_6 || ! V_71 -> V_73 )
continue;
F_27 ( V_71 ) ;
}
F_7 ( V_2 , V_58 , V_84 , V_85 ) ;
F_14 ( V_5 , true ) ;
V_2 -> V_80 = true ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_14 * V_6 = & V_2 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
if ( ! V_2 -> V_80 )
return;
F_25 ( & V_5 -> V_64 . V_83 ) ;
V_2 -> V_71 -> V_73 = false ;
F_17 ( V_6 ) ;
F_26 ( & V_5 -> V_64 . V_83 ) ;
F_7 ( V_2 , V_58 , V_84 , V_86 ) ;
F_14 ( V_5 , false ) ;
V_2 -> V_80 = false ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
F_28 ( V_2 ) ;
F_30 ( V_5 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
if ( V_2 -> V_87 != V_88 )
return;
F_32 ( V_5 ) ;
F_21 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_6 = & V_2 -> V_6 ;
F_34 ( V_2 -> V_71 , V_6 -> V_89 ) ;
F_35 ( V_2 -> V_71 ) ;
}
static void F_36 ( struct V_14 * V_6 , int V_16 )
{
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
struct V_1 * V_2 = F_16 ( V_6 ) ;
if ( V_2 -> V_87 == V_16 )
return;
if ( V_16 == V_88 ) {
F_32 ( V_5 ) ;
F_21 ( V_2 ) ;
} else {
F_28 ( V_2 ) ;
F_30 ( V_5 ) ;
}
V_2 -> V_87 = V_16 ;
}
static bool F_37 ( struct V_14 * V_6 ,
const struct V_15 * V_16 ,
struct V_15 * V_90 )
{
return true ;
}
static void F_38 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
struct V_1 * V_2 = F_16 ( V_6 ) ;
F_32 ( V_5 ) ;
F_28 ( V_2 ) ;
F_39 ( V_2 -> V_71 ) ;
V_2 -> V_87 = V_91 ;
}
static int F_40 ( struct V_14 * V_6 ,
struct V_15 * V_16 ,
struct V_15 * V_90 ,
int V_92 , int V_93 ,
struct V_94 * V_95 )
{
struct V_4 * V_5 = V_6 -> V_7 -> V_8 ;
struct V_1 * V_2 = F_16 ( V_6 ) ;
const struct V_96 * V_75 ;
int V_97 ;
V_75 = V_96 ( V_6 -> V_89 -> V_98 ) ;
if ( V_75 == NULL ) {
F_41 ( V_5 -> V_7 , L_1 ,
V_6 -> V_89 -> V_98 ) ;
V_97 = - V_99 ;
goto error;
}
V_97 = F_42 ( V_2 -> V_71 , V_75 ) ;
if ( V_97 < 0 )
goto error;
V_2 -> V_71 -> V_75 = V_75 ;
V_2 -> V_71 -> V_100 = V_6 -> V_89 -> V_101 [ 0 ] ;
V_2 -> V_71 -> V_102 = V_92 ;
V_2 -> V_71 -> V_103 = V_93 ;
V_2 -> V_71 -> V_104 = V_16 -> V_35 ;
V_2 -> V_71 -> V_105 = V_16 -> V_43 ;
F_34 ( V_2 -> V_71 , V_6 -> V_89 ) ;
V_2 -> V_54 = 0 ;
return 0 ;
error:
F_30 ( V_5 ) ;
return V_97 ;
}
static void F_43 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
F_21 ( V_2 ) ;
V_2 -> V_87 = V_88 ;
}
static int F_44 ( struct V_14 * V_6 , int V_92 , int V_93 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
V_2 -> V_71 -> V_102 = V_92 ;
V_2 -> V_71 -> V_103 = V_93 ;
F_33 ( F_16 ( V_6 ) ) ;
return 0 ;
}
static void F_45 ( struct V_14 * V_6 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
F_36 ( V_6 , V_91 ) ;
F_39 ( V_2 -> V_71 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 ;
struct V_110 * V_7 = V_2 -> V_6 . V_7 ;
unsigned long V_24 ;
F_47 ( & V_7 -> V_111 , V_24 ) ;
V_109 = V_2 -> V_109 ;
if ( V_109 && V_109 -> V_112 . V_113 == V_107 ) {
V_2 -> V_109 = NULL ;
V_109 -> V_112 . V_114 ( & V_109 -> V_112 ) ;
F_48 ( V_7 , V_2 -> V_18 ) ;
}
F_49 ( & V_7 -> V_111 , V_24 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
struct V_110 * V_7 = V_2 -> V_6 . V_7 ;
unsigned long V_24 ;
F_47 ( & V_7 -> V_111 , V_24 ) ;
V_109 = V_2 -> V_109 ;
V_2 -> V_109 = NULL ;
F_49 ( & V_7 -> V_111 , V_24 ) ;
if ( V_109 == NULL )
return;
F_47 ( & V_7 -> V_111 , V_24 ) ;
F_51 ( V_7 , V_2 -> V_18 , V_109 ) ;
F_49 ( & V_7 -> V_111 , V_24 ) ;
F_48 ( V_7 , V_2 -> V_18 ) ;
}
static int F_52 ( struct V_14 * V_6 ,
struct V_94 * V_89 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
struct V_110 * V_7 = V_2 -> V_6 . V_7 ;
unsigned long V_24 ;
F_47 ( & V_7 -> V_111 , V_24 ) ;
if ( V_2 -> V_109 != NULL ) {
F_49 ( & V_7 -> V_111 , V_24 ) ;
return - V_115 ;
}
F_49 ( & V_7 -> V_111 , V_24 ) ;
V_6 -> V_89 = V_89 ;
F_33 ( V_2 ) ;
if ( V_109 ) {
V_109 -> V_116 = V_2 -> V_18 ;
F_53 ( V_7 , V_2 -> V_18 ) ;
F_47 ( & V_7 -> V_111 , V_24 ) ;
V_2 -> V_109 = V_109 ;
F_49 ( & V_7 -> V_111 , V_24 ) ;
}
return 0 ;
}
int F_54 ( struct V_4 * V_5 , unsigned int V_18 )
{
struct V_1 * V_2 = & V_5 -> V_117 [ V_18 ] ;
struct V_14 * V_6 = & V_2 -> V_6 ;
int V_97 ;
V_2 -> V_9 = V_18 ? V_118 : 0 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_87 = V_91 ;
V_2 -> V_71 = & V_5 -> V_64 . V_64 [ V_18 ] ;
V_2 -> V_71 -> V_6 = V_6 ;
V_97 = F_55 ( V_5 -> V_119 , V_6 , & V_120 ) ;
if ( V_97 < 0 )
return V_97 ;
F_56 ( V_6 , & V_121 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , bool V_122 )
{
if ( V_122 ) {
F_3 ( V_2 , V_123 , V_124 ) ;
F_6 ( V_2 , V_125 , V_126 ) ;
} else {
F_5 ( V_2 , V_125 , V_126 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
T_1 V_127 ;
V_127 = F_1 ( V_2 , V_128 ) ;
F_3 ( V_2 , V_123 , V_127 & V_129 ) ;
if ( V_127 & V_130 ) {
F_59 ( V_2 -> V_6 . V_7 , V_2 -> V_18 ) ;
F_50 ( V_2 ) ;
}
}
