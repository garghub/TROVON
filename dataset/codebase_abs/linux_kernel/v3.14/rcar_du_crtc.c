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
V_13 = F_10 ( V_2 -> V_6 ) ;
if ( V_13 < 0 )
F_11 ( V_2 -> clock ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> clock ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 = & V_2 -> V_16 . V_15 ;
unsigned long V_17 ;
T_1 V_12 ;
T_1 div ;
V_17 = F_15 ( V_2 -> clock ) ;
div = F_16 ( V_17 , V_15 -> clock * 1000 ) ;
div = F_17 ( div , 1U , 64U ) - 1 ;
F_18 ( V_2 -> V_6 , V_2 -> V_18 % 2 ? V_19 : V_20 ,
V_21 | div ) ;
F_18 ( V_2 -> V_6 , V_2 -> V_18 % 2 ? V_22 : V_23 , 0 ) ;
V_12 = ( ( V_15 -> V_24 & V_25 ) ? 0 : V_26 )
| ( ( V_15 -> V_24 & V_27 ) ? 0 : V_28 )
| V_29 ;
F_3 ( V_2 , V_30 , V_12 ) ;
F_3 ( V_2 , V_31 , V_15 -> V_32 - V_15 -> V_33 - 19 ) ;
F_3 ( V_2 , V_34 , V_15 -> V_32 - V_15 -> V_33 +
V_15 -> V_35 - 19 ) ;
F_3 ( V_2 , V_36 , V_15 -> V_37 -
V_15 -> V_33 - 1 ) ;
F_3 ( V_2 , V_38 , V_15 -> V_32 - 1 ) ;
F_3 ( V_2 , V_39 , V_15 -> V_40 - V_15 -> V_41 - 2 ) ;
F_3 ( V_2 , V_42 , V_15 -> V_40 - V_15 -> V_41 +
V_15 -> V_43 - 2 ) ;
F_3 ( V_2 , V_44 , V_15 -> V_40 - V_15 -> V_41 +
V_15 -> V_45 - 1 ) ;
F_3 ( V_2 , V_46 , V_15 -> V_40 - 1 ) ;
F_3 ( V_2 , V_47 , V_15 -> V_32 - V_15 -> V_33 ) ;
F_3 ( V_2 , V_48 , V_15 -> V_35 ) ;
}
void F_19 ( struct V_49 * V_16 ,
enum V_50 V_51 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_52 |= F_21 ( V_51 ) ;
if ( F_22 ( V_5 , V_53 ) &&
V_51 == V_54 )
V_5 -> V_55 = V_2 -> V_18 ;
}
void F_23 ( struct V_49 * V_16 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
struct V_56 * V_57 [ V_58 ] ;
unsigned int V_59 = 0 ;
unsigned int V_60 = 0 ;
unsigned int V_61 ;
T_1 V_62 = 0 ;
T_1 V_63 = 0 ;
for ( V_61 = 0 ; V_61 < F_24 ( V_2 -> V_6 -> V_57 . V_57 ) ; ++ V_61 ) {
struct V_56 * V_64 = & V_2 -> V_6 -> V_57 . V_57 [ V_61 ] ;
unsigned int V_65 ;
if ( V_64 -> V_16 != & V_2 -> V_16 || ! V_64 -> V_66 )
continue;
for ( V_65 = V_59 ++ ; V_65 > 0 ; -- V_65 ) {
if ( V_57 [ V_65 - 1 ] -> V_67 <= V_64 -> V_67 )
break;
V_57 [ V_65 ] = V_57 [ V_65 - 1 ] ;
}
V_57 [ V_65 ] = V_64 ;
V_60 += V_64 -> V_68 -> V_57 * 4 ;
}
for ( V_61 = 0 ; V_61 < V_59 ; ++ V_61 ) {
struct V_56 * V_64 = V_57 [ V_61 ] ;
unsigned int V_18 = V_64 -> V_69 ;
V_60 -= 4 ;
V_63 |= ( V_18 + 1 ) << V_60 ;
V_62 |= F_25 ( V_18 ) | F_26 ( V_18 ) ;
if ( V_64 -> V_68 -> V_57 == 2 ) {
V_18 = ( V_18 + 1 ) % 8 ;
V_60 -= 4 ;
V_63 |= ( V_18 + 1 ) << V_60 ;
V_62 |= F_25 ( V_18 ) | F_26 ( V_18 ) ;
}
}
if ( V_2 -> V_18 % 2 ) {
T_1 V_12 = F_27 ( V_2 -> V_6 , V_70 ) ;
if ( V_12 != V_62 ) {
F_18 ( V_2 -> V_6 , V_70 , V_62 ) ;
if ( V_2 -> V_6 -> V_71 )
F_28 ( V_2 -> V_6 ) ;
}
}
F_18 ( V_2 -> V_6 , V_2 -> V_18 % 2 ? V_72 : V_73 ,
V_63 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_49 * V_16 = & V_2 -> V_16 ;
unsigned int V_61 ;
if ( V_2 -> V_74 )
return;
if ( F_30 ( V_2 -> V_64 -> V_68 == NULL ) )
return;
F_3 ( V_2 , V_75 , F_31 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_76 , F_32 ( 0 , 0 , 0 ) ) ;
F_14 ( V_2 ) ;
F_33 ( V_2 -> V_6 ) ;
F_34 ( & V_2 -> V_6 -> V_57 . V_77 ) ;
V_2 -> V_64 -> V_66 = true ;
F_23 ( V_16 ) ;
F_35 ( & V_2 -> V_6 -> V_57 . V_77 ) ;
for ( V_61 = 0 ; V_61 < F_24 ( V_2 -> V_6 -> V_57 . V_57 ) ; ++ V_61 ) {
struct V_56 * V_64 = & V_2 -> V_6 -> V_57 . V_57 [ V_61 ] ;
if ( V_64 -> V_16 != V_16 || ! V_64 -> V_66 )
continue;
F_36 ( V_64 ) ;
}
F_7 ( V_2 , V_78 , V_79 , V_80 ) ;
F_37 ( V_2 -> V_6 , true ) ;
V_2 -> V_74 = true ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_49 * V_16 = & V_2 -> V_16 ;
if ( ! V_2 -> V_74 )
return;
F_34 ( & V_2 -> V_6 -> V_57 . V_77 ) ;
V_2 -> V_64 -> V_66 = false ;
F_23 ( V_16 ) ;
F_35 ( & V_2 -> V_6 -> V_57 . V_77 ) ;
F_7 ( V_2 , V_78 , V_79 , V_81 ) ;
F_37 ( V_2 -> V_6 , false ) ;
V_2 -> V_74 = false ;
}
void F_39 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 != V_83 )
return;
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_49 * V_16 = & V_2 -> V_16 ;
F_42 ( V_2 -> V_64 , V_16 -> V_84 ) ;
F_43 ( V_2 -> V_64 ) ;
}
static void F_44 ( struct V_49 * V_16 , int V_15 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
if ( V_2 -> V_82 == V_15 )
return;
if ( V_15 == V_83 ) {
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
} else {
F_38 ( V_2 ) ;
F_12 ( V_2 ) ;
}
V_2 -> V_82 = V_15 ;
}
static bool F_45 ( struct V_49 * V_16 ,
const struct V_14 * V_15 ,
struct V_14 * V_85 )
{
return true ;
}
static void F_46 ( struct V_49 * V_16 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
F_8 ( V_2 ) ;
F_38 ( V_2 ) ;
F_47 ( V_2 -> V_64 ) ;
V_2 -> V_82 = V_86 ;
}
static int F_48 ( struct V_49 * V_16 ,
struct V_14 * V_15 ,
struct V_14 * V_85 ,
int V_87 , int V_88 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
const struct V_91 * V_68 ;
int V_13 ;
V_68 = V_91 ( V_16 -> V_84 -> V_92 ) ;
if ( V_68 == NULL ) {
F_49 ( V_5 -> V_7 , L_1 ,
V_16 -> V_84 -> V_92 ) ;
V_13 = - V_93 ;
goto error;
}
V_13 = F_50 ( V_2 -> V_64 , V_68 ) ;
if ( V_13 < 0 )
goto error;
V_2 -> V_64 -> V_68 = V_68 ;
V_2 -> V_64 -> V_94 = V_87 ;
V_2 -> V_64 -> V_95 = V_88 ;
V_2 -> V_64 -> V_96 = V_15 -> V_35 ;
V_2 -> V_64 -> V_97 = V_15 -> V_43 ;
F_42 ( V_2 -> V_64 , V_16 -> V_84 ) ;
V_2 -> V_52 = 0 ;
return 0 ;
error:
F_12 ( V_2 ) ;
return V_13 ;
}
static void F_51 ( struct V_49 * V_16 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
F_29 ( V_2 ) ;
V_2 -> V_82 = V_83 ;
}
static int F_52 ( struct V_49 * V_16 , int V_87 , int V_88 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
V_2 -> V_64 -> V_94 = V_87 ;
V_2 -> V_64 -> V_95 = V_88 ;
F_41 ( V_2 ) ;
return 0 ;
}
static void F_53 ( struct V_49 * V_16 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
F_44 ( V_16 , V_86 ) ;
F_47 ( V_2 -> V_64 ) ;
}
void F_54 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 ;
struct V_102 * V_7 = V_2 -> V_16 . V_7 ;
unsigned long V_24 ;
F_55 ( & V_7 -> V_103 , V_24 ) ;
V_101 = V_2 -> V_101 ;
if ( V_101 && V_101 -> V_104 . V_105 == V_99 ) {
V_2 -> V_101 = NULL ;
V_101 -> V_104 . V_106 ( & V_101 -> V_104 ) ;
F_56 ( V_7 , V_2 -> V_18 ) ;
}
F_57 ( & V_7 -> V_103 , V_24 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
struct V_102 * V_7 = V_2 -> V_16 . V_7 ;
unsigned long V_24 ;
F_55 ( & V_7 -> V_103 , V_24 ) ;
V_101 = V_2 -> V_101 ;
V_2 -> V_101 = NULL ;
F_57 ( & V_7 -> V_103 , V_24 ) ;
if ( V_101 == NULL )
return;
F_55 ( & V_7 -> V_103 , V_24 ) ;
F_59 ( V_7 , V_2 -> V_18 , V_101 ) ;
F_57 ( & V_7 -> V_103 , V_24 ) ;
F_56 ( V_7 , V_2 -> V_18 ) ;
}
static T_2 F_60 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
T_2 V_13 = V_109 ;
T_1 V_110 ;
V_110 = F_1 ( V_2 , V_111 ) ;
F_3 ( V_2 , V_112 , V_110 & V_113 ) ;
if ( V_110 & V_114 ) {
F_61 ( V_2 -> V_16 . V_7 , V_2 -> V_18 ) ;
F_58 ( V_2 ) ;
V_13 = V_115 ;
}
return V_13 ;
}
static int F_62 ( struct V_49 * V_16 ,
struct V_89 * V_84 ,
struct V_100 * V_101 ,
T_3 V_116 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
struct V_102 * V_7 = V_2 -> V_16 . V_7 ;
unsigned long V_24 ;
F_55 ( & V_7 -> V_103 , V_24 ) ;
if ( V_2 -> V_101 != NULL ) {
F_57 ( & V_7 -> V_103 , V_24 ) ;
return - V_117 ;
}
F_57 ( & V_7 -> V_103 , V_24 ) ;
V_16 -> V_84 = V_84 ;
F_41 ( V_2 ) ;
if ( V_101 ) {
V_101 -> V_118 = V_2 -> V_18 ;
F_63 ( V_7 , V_2 -> V_18 ) ;
F_55 ( & V_7 -> V_103 , V_24 ) ;
V_2 -> V_101 = V_101 ;
F_57 ( & V_7 -> V_103 , V_24 ) ;
}
return 0 ;
}
int F_64 ( struct V_119 * V_120 , unsigned int V_18 )
{
static const unsigned int V_121 [] = {
V_122 , V_123 , V_124
} ;
struct V_4 * V_5 = V_120 -> V_7 ;
struct V_125 * V_126 = F_65 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_127 [ V_18 ] ;
struct V_49 * V_16 = & V_2 -> V_16 ;
unsigned int V_128 ;
char V_129 [ 5 ] ;
char * V_130 ;
int V_107 ;
int V_13 ;
if ( F_22 ( V_5 , V_131 ) ) {
sprintf ( V_129 , L_2 , V_18 ) ;
V_130 = V_129 ;
} else {
V_130 = NULL ;
}
V_2 -> clock = F_66 ( V_5 -> V_7 , V_130 ) ;
if ( F_67 ( V_2 -> clock ) ) {
F_68 ( V_5 -> V_7 , L_3 , V_18 ) ;
return F_69 ( V_2 -> clock ) ;
}
V_2 -> V_6 = V_120 ;
V_2 -> V_8 = V_121 [ V_18 ] ;
V_2 -> V_18 = V_18 ;
V_2 -> V_82 = V_86 ;
V_2 -> V_64 = & V_120 -> V_57 . V_57 [ V_18 % 2 ] ;
V_2 -> V_64 -> V_16 = V_16 ;
V_13 = F_70 ( V_5 -> V_132 , V_16 , & V_133 ) ;
if ( V_13 < 0 )
return V_13 ;
F_71 ( V_16 , & V_134 ) ;
if ( F_22 ( V_5 , V_131 ) ) {
V_107 = F_72 ( V_126 , V_18 ) ;
V_128 = 0 ;
} else {
V_107 = F_72 ( V_126 , 0 ) ;
V_128 = V_135 ;
}
if ( V_107 < 0 ) {
F_68 ( V_5 -> V_7 , L_4 , V_18 ) ;
return V_13 ;
}
V_13 = F_73 ( V_5 -> V_7 , V_107 , F_60 , V_128 ,
F_74 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_68 ( V_5 -> V_7 ,
L_5 , V_18 ) ;
return V_13 ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 , bool V_136 )
{
if ( V_136 ) {
F_3 ( V_2 , V_112 , V_137 ) ;
F_6 ( V_2 , V_138 , V_139 ) ;
} else {
F_5 ( V_2 , V_138 , V_139 ) ;
}
}
