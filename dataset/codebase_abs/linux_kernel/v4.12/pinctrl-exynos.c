static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_9 = V_6 -> V_10 + V_8 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
F_6 ( & V_8 -> V_14 , V_13 ) ;
V_12 = F_7 ( V_8 -> V_15 + V_9 ) ;
V_12 |= 1 << V_5 -> V_16 ;
F_8 ( V_12 , V_8 -> V_15 + V_9 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_17 = V_6 -> V_18 + V_8 -> V_11 ;
F_8 ( 1 << V_5 -> V_16 , V_8 -> V_15 + V_17 ) ;
}
static void F_11 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_9 = V_6 -> V_10 + V_8 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
if ( F_12 ( V_5 ) & V_19 )
F_10 ( V_5 ) ;
F_6 ( & V_8 -> V_14 , V_13 ) ;
V_12 = F_7 ( V_8 -> V_15 + V_9 ) ;
V_12 &= ~ ( 1 << V_5 -> V_16 ) ;
F_8 ( V_12 , V_8 -> V_15 + V_9 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
}
static int F_13 ( struct V_4 * V_5 , unsigned int type )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned int V_20 = V_21 * V_5 -> V_16 ;
unsigned int V_22 , V_23 ;
unsigned long V_24 = V_6 -> V_25 + V_8 -> V_11 ;
switch ( type ) {
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
case V_30 :
V_23 = V_31 ;
break;
case V_32 :
V_23 = V_33 ;
break;
case V_34 :
V_23 = V_35 ;
break;
default:
F_14 ( L_1 ) ;
return - V_36 ;
}
if ( type & V_30 )
F_15 ( V_5 , V_37 ) ;
else
F_15 ( V_5 , V_38 ) ;
V_22 = F_7 ( V_8 -> V_15 + V_24 ) ;
V_22 &= ~ ( V_39 << V_20 ) ;
V_22 |= V_23 << V_20 ;
F_8 ( V_22 , V_8 -> V_15 + V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
const struct V_40 * V_41 = V_8 -> type ;
unsigned int V_20 = V_21 * V_5 -> V_16 ;
unsigned long V_24 = V_6 -> V_25 + V_8 -> V_11 ;
unsigned long V_13 ;
unsigned int V_12 ;
unsigned int V_22 ;
int V_42 ;
V_42 = F_17 ( & V_8 -> V_43 , V_5 -> V_16 ) ;
if ( V_42 ) {
F_18 ( V_8 -> V_43 . V_44 ,
L_2 ,
V_8 -> V_45 , V_5 -> V_16 ) ;
return V_42 ;
}
V_24 = V_8 -> V_46 + V_41 -> V_47 [ V_48 ] ;
V_20 = V_5 -> V_16 * V_41 -> V_49 [ V_48 ] ;
V_12 = ( 1 << V_41 -> V_49 [ V_48 ] ) - 1 ;
F_6 ( & V_8 -> V_14 , V_13 ) ;
V_22 = F_7 ( V_8 -> V_15 + V_24 ) ;
V_22 &= ~ ( V_12 << V_20 ) ;
V_22 |= V_50 << V_20 ;
F_8 ( V_22 , V_8 -> V_15 + V_24 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
const struct V_40 * V_41 = V_8 -> type ;
unsigned int V_20 = V_21 * V_5 -> V_16 ;
unsigned long V_24 = V_6 -> V_25 + V_8 -> V_11 ;
unsigned long V_13 ;
unsigned int V_12 ;
unsigned int V_22 ;
V_24 = V_8 -> V_46 + V_41 -> V_47 [ V_48 ] ;
V_20 = V_5 -> V_16 * V_41 -> V_49 [ V_48 ] ;
V_12 = ( 1 << V_41 -> V_49 [ V_48 ] ) - 1 ;
F_3 ( V_5 ) ;
F_6 ( & V_8 -> V_14 , V_13 ) ;
V_22 = F_7 ( V_8 -> V_15 + V_24 ) ;
V_22 &= ~ ( V_12 << V_20 ) ;
V_22 |= V_51 << V_20 ;
F_8 ( V_22 , V_8 -> V_15 + V_24 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
F_20 ( & V_8 -> V_43 , V_5 -> V_16 ) ;
}
static int F_21 ( struct V_52 * V_53 , unsigned int V_54 ,
T_1 V_55 )
{
struct V_7 * V_56 = V_53 -> V_57 ;
F_22 ( V_54 , V_56 ) ;
F_23 ( V_54 , & V_56 -> V_2 -> V_3 ,
V_38 ) ;
return 0 ;
}
static T_2 F_24 ( int V_58 , void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_7 * V_8 = V_61 -> V_62 ;
unsigned int V_63 , V_64 , V_65 , V_54 ;
V_63 = F_7 ( V_8 -> V_15 + V_66 ) ;
V_64 = F_25 ( V_63 ) ;
V_65 = V_63 & V_67 ;
if ( ! V_64 )
return V_68 ;
V_8 += ( V_64 - 1 ) ;
V_54 = F_26 ( V_8 -> V_52 , V_65 ) ;
if ( ! V_54 )
return V_69 ;
F_27 ( V_54 ) ;
return V_68 ;
}
static int F_28 ( struct V_60 * V_61 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 = V_61 -> V_71 ;
int V_42 ;
int V_72 ;
if ( ! V_61 -> V_58 ) {
F_18 ( V_71 , L_3 ) ;
return - V_36 ;
}
V_42 = F_29 ( V_71 , V_61 -> V_58 , F_24 ,
0 , F_30 ( V_71 ) , V_61 ) ;
if ( V_42 ) {
F_18 ( V_71 , L_4 ) ;
return - V_73 ;
}
V_8 = V_61 -> V_62 ;
for ( V_72 = 0 ; V_72 < V_61 -> V_74 ; ++ V_72 , ++ V_8 ) {
if ( V_8 -> V_75 != V_76 )
continue;
V_8 -> V_52 = F_31 ( V_8 -> V_77 ,
V_8 -> V_78 , & V_79 , V_8 ) ;
if ( ! V_8 -> V_52 ) {
F_18 ( V_71 , L_5 ) ;
V_42 = - V_73 ;
goto V_80;
}
V_8 -> V_81 = F_32 ( V_61 -> V_71 ,
sizeof( struct V_82 ) , V_83 ) ;
if ( ! V_8 -> V_81 ) {
F_33 ( V_8 -> V_52 ) ;
V_42 = - V_84 ;
goto V_80;
}
V_8 -> V_2 = & V_85 ;
}
return 0 ;
V_80:
for ( -- V_72 , -- V_8 ; V_72 >= 0 ; -- V_72 , -- V_8 ) {
if ( V_8 -> V_75 != V_76 )
continue;
F_33 ( V_8 -> V_52 ) ;
}
return V_42 ;
}
T_3 F_34 ( void )
{
return V_86 ;
}
static int F_35 ( struct V_4 * V_5 , unsigned int V_87 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_88 = 1UL << ( 2 * V_8 -> V_11 + V_5 -> V_16 ) ;
F_36 ( L_6 , V_87 ? L_7 : L_8 , V_5 -> V_58 ) ;
if ( ! V_87 )
V_86 |= V_88 ;
else
V_86 &= ~ V_88 ;
return 0 ;
}
static void F_37 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = F_38 ( V_90 ) ;
struct V_7 * V_8 = V_92 -> V_8 ;
struct V_2 * V_3 = F_39 ( V_90 ) ;
int V_93 ;
F_40 ( V_3 , V_90 ) ;
V_93 = F_26 ( V_8 -> V_52 , V_92 -> V_58 ) ;
F_27 ( V_93 ) ;
F_41 ( V_3 , V_90 ) ;
}
static inline void F_42 ( unsigned long V_94 ,
struct V_52 * V_95 )
{
unsigned int V_58 ;
while ( V_94 ) {
V_58 = F_43 ( V_94 ) - 1 ;
F_27 ( F_44 ( V_95 , V_58 ) ) ;
V_94 &= ~ ( 1 << V_58 ) ;
}
}
static void F_45 ( struct V_89 * V_90 )
{
struct V_2 * V_3 = F_39 ( V_90 ) ;
struct V_96 * V_92 = F_38 ( V_90 ) ;
unsigned long V_94 ;
unsigned long V_12 ;
int V_72 ;
F_40 ( V_3 , V_90 ) ;
for ( V_72 = 0 ; V_72 < V_92 -> V_74 ; ++ V_72 ) {
struct V_7 * V_56 = V_92 -> V_97 [ V_72 ] ;
V_94 = F_7 ( V_56 -> V_15 + V_56 -> V_2 -> V_18
+ V_56 -> V_11 ) ;
V_12 = F_7 ( V_56 -> V_15 + V_56 -> V_2 -> V_10
+ V_56 -> V_11 ) ;
F_42 ( V_94 & ~ V_12 , V_56 -> V_52 ) ;
}
F_41 ( V_3 , V_90 ) ;
}
static int F_46 ( struct V_60 * V_61 )
{
struct V_70 * V_71 = V_61 -> V_71 ;
struct V_98 * V_99 = NULL ;
struct V_98 * V_100 ;
struct V_7 * V_8 ;
struct V_91 * V_101 ;
struct V_96 * V_102 ;
struct V_1 * V_2 ;
unsigned int V_103 = 0 ;
unsigned int V_72 ;
int V_104 , V_58 ;
F_47 (dev->of_node, np) {
const struct V_105 * V_106 ;
V_106 = F_48 ( V_107 , V_100 ) ;
if ( V_106 ) {
V_2 = F_49 ( V_106 -> V_59 ,
sizeof( * V_2 ) , V_83 ) ;
V_99 = V_100 ;
break;
}
}
if ( ! V_99 )
return - V_108 ;
V_8 = V_61 -> V_62 ;
for ( V_72 = 0 ; V_72 < V_61 -> V_74 ; ++ V_72 , ++ V_8 ) {
if ( V_8 -> V_75 != V_109 )
continue;
V_8 -> V_52 = F_31 ( V_8 -> V_77 ,
V_8 -> V_78 , & V_79 , V_8 ) ;
if ( ! V_8 -> V_52 ) {
F_18 ( V_71 , L_9 ) ;
return - V_73 ;
}
V_8 -> V_2 = V_2 ;
if ( ! F_50 ( V_8 -> V_77 , L_10 , NULL ) ) {
V_8 -> V_75 = V_110 ;
++ V_103 ;
continue;
}
V_101 = F_32 ( V_71 , V_8 -> V_78
* sizeof( * V_101 ) , V_83 ) ;
if ( ! V_101 )
return - V_84 ;
for ( V_104 = 0 ; V_104 < V_8 -> V_78 ; ++ V_104 ) {
V_58 = F_51 ( V_8 -> V_77 , V_104 ) ;
if ( ! V_58 ) {
F_18 ( V_71 , L_11 ,
V_8 -> V_45 , V_104 ) ;
continue;
}
V_101 [ V_104 ] . V_58 = V_104 ;
V_101 [ V_104 ] . V_8 = V_8 ;
F_52 ( V_58 ,
F_37 ,
& V_101 [ V_104 ] ) ;
}
}
if ( ! V_103 )
return 0 ;
V_58 = F_51 ( V_99 , 0 ) ;
if ( ! V_58 ) {
F_18 ( V_71 , L_12 ) ;
return 0 ;
}
V_102 = F_32 ( V_71 , sizeof( * V_102 )
+ V_103 * sizeof( struct V_7 * ) , V_83 ) ;
if ( ! V_102 )
return - V_84 ;
F_52 ( V_58 , F_45 ,
V_102 ) ;
V_8 = V_61 -> V_62 ;
V_104 = 0 ;
for ( V_72 = 0 ; V_72 < V_61 -> V_74 ; ++ V_72 , ++ V_8 ) {
if ( V_8 -> V_75 != V_110 )
continue;
V_102 -> V_97 [ V_104 ++ ] = V_8 ;
}
V_102 -> V_74 = V_103 ;
return 0 ;
}
static void F_53 (
struct V_60 * V_111 ,
struct V_7 * V_8 )
{
struct V_82 * V_112 = V_8 -> V_81 ;
void T_4 * V_113 = V_8 -> V_15 ;
V_112 -> V_25 = F_7 ( V_113 + V_114
+ V_8 -> V_11 ) ;
V_112 -> V_115 = F_7 ( V_113 + V_116
+ 2 * V_8 -> V_11 ) ;
V_112 -> V_117 = F_7 ( V_113 + V_116
+ 2 * V_8 -> V_11 + 4 ) ;
F_54 ( L_13 , V_8 -> V_45 , V_112 -> V_25 ) ;
F_54 ( L_14 , V_8 -> V_45 , V_112 -> V_115 ) ;
F_54 ( L_15 , V_8 -> V_45 , V_112 -> V_117 ) ;
}
static void F_55 ( struct V_60 * V_111 )
{
struct V_7 * V_8 = V_111 -> V_62 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_111 -> V_74 ; ++ V_72 , ++ V_8 )
if ( V_8 -> V_75 == V_76 )
F_53 ( V_111 , V_8 ) ;
}
static void F_56 (
struct V_60 * V_111 ,
struct V_7 * V_8 )
{
struct V_82 * V_112 = V_8 -> V_81 ;
void T_4 * V_113 = V_8 -> V_15 ;
F_54 ( L_16 , V_8 -> V_45 ,
F_7 ( V_113 + V_114
+ V_8 -> V_11 ) , V_112 -> V_25 ) ;
F_54 ( L_17 , V_8 -> V_45 ,
F_7 ( V_113 + V_116
+ 2 * V_8 -> V_11 ) , V_112 -> V_115 ) ;
F_54 ( L_18 , V_8 -> V_45 ,
F_7 ( V_113 + V_116
+ 2 * V_8 -> V_11 + 4 ) , V_112 -> V_117 ) ;
F_8 ( V_112 -> V_25 , V_113 + V_114
+ V_8 -> V_11 ) ;
F_8 ( V_112 -> V_115 , V_113 + V_116
+ 2 * V_8 -> V_11 ) ;
F_8 ( V_112 -> V_117 , V_113 + V_116
+ 2 * V_8 -> V_11 + 4 ) ;
}
static void F_57 ( struct V_60 * V_111 )
{
struct V_7 * V_8 = V_111 -> V_62 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_111 -> V_74 ; ++ V_72 , ++ V_8 )
if ( V_8 -> V_75 == V_76 )
F_56 ( V_111 , V_8 ) ;
}
static void F_58 ( struct V_60 * V_111 )
{
void * V_118 = V_111 -> V_119 -> V_120 ;
T_3 V_121 ;
V_121 = F_59 ( V_118 + V_122 ) ;
V_121 |= ( V_123 | V_124 | V_125 |
V_126 ) ;
F_60 ( V_121 , V_118 + V_122 ) ;
}
static struct V_127 *
F_61 ( struct V_60 * V_111 ,
const struct V_128 * V_59 )
{
struct V_127 * V_129 ;
struct V_98 * V_100 ;
void * V_118 ;
V_129 = F_32 ( V_111 -> V_71 , sizeof( * V_129 ) , V_83 ) ;
if ( ! V_129 )
return F_62 ( - V_84 ) ;
V_100 = F_63 ( NULL , NULL , L_19 ) ;
if ( ! V_100 ) {
F_14 ( L_20 ,
V_130 ) ;
return F_62 ( - V_108 ) ;
}
V_118 = F_64 ( V_100 , 0 ) ;
if ( ! V_118 ) {
F_14 ( L_21 , V_130 ) ;
return F_62 ( - V_36 ) ;
}
V_129 -> V_120 = V_118 ;
V_129 -> V_131 = F_58 ;
return V_129 ;
}
static void F_65 ( struct V_60 * V_111 )
{
if ( V_111 -> V_119 -> V_132 )
F_66 ( V_111 -> V_119 -> V_132 ) ;
}
static void F_67 ( struct V_60 * V_111 )
{
struct V_127 * V_129 = V_111 -> V_119 ;
struct V_133 * V_134 = V_129 -> V_120 ;
int V_72 ;
if ( V_129 -> V_132 && ! F_68 ( V_129 -> V_132 ) )
return;
for ( V_72 = 0 ; V_72 < V_129 -> V_135 ; V_72 ++ )
F_69 ( V_134 , V_129 -> V_113 [ V_72 ] , V_129 -> V_136 ) ;
}
static struct V_127 *
F_70 ( struct V_60 * V_111 ,
const struct V_128 * V_59 )
{
struct V_127 * V_129 ;
struct V_133 * V_134 ;
int V_72 ;
V_129 = F_32 ( V_111 -> V_71 , sizeof( * V_129 ) , V_83 ) ;
if ( ! V_129 )
return F_62 ( - V_84 ) ;
V_134 = F_71 () ;
if ( F_72 ( V_134 ) )
return F_73 ( V_134 ) ;
V_129 -> V_120 = V_134 ;
V_129 -> V_113 = V_59 -> V_113 ;
V_129 -> V_135 = V_59 -> V_135 ;
V_129 -> V_136 = V_59 -> V_136 ;
V_129 -> V_132 = V_59 -> V_132 ;
V_129 -> V_137 = F_65 ;
V_129 -> V_131 = F_67 ;
for ( V_72 = 0 ; V_72 < V_129 -> V_135 ; V_72 ++ )
F_69 ( V_134 , V_129 -> V_113 [ V_72 ] , V_129 -> V_136 ) ;
return V_129 ;
}
