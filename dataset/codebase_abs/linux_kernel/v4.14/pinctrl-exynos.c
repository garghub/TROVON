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
struct V_7 * V_8 = F_5 ( V_5 ) ;
const struct V_40 * V_41 = V_8 -> type ;
unsigned long V_24 , V_13 ;
unsigned int V_20 , V_12 , V_22 ;
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
V_22 = F_7 ( V_8 -> V_50 + V_24 ) ;
V_22 &= ~ ( V_12 << V_20 ) ;
V_22 |= V_51 << V_20 ;
F_8 ( V_22 , V_8 -> V_50 + V_24 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
const struct V_40 * V_41 = V_8 -> type ;
unsigned long V_24 , V_13 ;
unsigned int V_20 , V_12 , V_22 ;
V_24 = V_8 -> V_46 + V_41 -> V_47 [ V_48 ] ;
V_20 = V_5 -> V_16 * V_41 -> V_49 [ V_48 ] ;
V_12 = ( 1 << V_41 -> V_49 [ V_48 ] ) - 1 ;
F_6 ( & V_8 -> V_14 , V_13 ) ;
V_22 = F_7 ( V_8 -> V_50 + V_24 ) ;
V_22 &= ~ ( V_12 << V_20 ) ;
V_22 |= V_52 << V_20 ;
F_8 ( V_22 , V_8 -> V_50 + V_24 ) ;
F_9 ( & V_8 -> V_14 , V_13 ) ;
F_20 ( & V_8 -> V_43 , V_5 -> V_16 ) ;
}
static int F_21 ( struct V_53 * V_54 , unsigned int V_55 ,
T_1 V_56 )
{
struct V_7 * V_57 = V_54 -> V_58 ;
F_22 ( V_55 , V_57 ) ;
F_23 ( V_55 , & V_57 -> V_2 -> V_3 ,
V_38 ) ;
return 0 ;
}
static T_2 F_24 ( int V_59 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_7 * V_8 = V_62 -> V_63 ;
unsigned int V_64 , V_65 , V_66 , V_55 ;
V_64 = F_7 ( V_8 -> V_15 + V_67 ) ;
V_65 = F_25 ( V_64 ) ;
V_66 = V_64 & V_68 ;
if ( ! V_65 )
return V_69 ;
V_8 += ( V_65 - 1 ) ;
V_55 = F_26 ( V_8 -> V_53 , V_66 ) ;
if ( ! V_55 )
return V_70 ;
F_27 ( V_55 ) ;
return V_69 ;
}
int F_28 ( struct V_61 * V_62 )
{
struct V_7 * V_8 ;
struct V_71 * V_72 = V_62 -> V_72 ;
int V_42 ;
int V_73 ;
if ( ! V_62 -> V_59 ) {
F_18 ( V_72 , L_3 ) ;
return - V_36 ;
}
V_42 = F_29 ( V_72 , V_62 -> V_59 , F_24 ,
0 , F_30 ( V_72 ) , V_62 ) ;
if ( V_42 ) {
F_18 ( V_72 , L_4 ) ;
return - V_74 ;
}
V_8 = V_62 -> V_63 ;
for ( V_73 = 0 ; V_73 < V_62 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
V_8 -> V_53 = F_31 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_53 ) {
F_18 ( V_72 , L_5 ) ;
V_42 = - V_74 ;
goto V_81;
}
V_8 -> V_82 = F_32 ( V_62 -> V_72 ,
sizeof( struct V_83 ) , V_84 ) ;
if ( ! V_8 -> V_82 ) {
F_33 ( V_8 -> V_53 ) ;
V_42 = - V_85 ;
goto V_81;
}
V_8 -> V_2 = & V_86 ;
}
return 0 ;
V_81:
for ( -- V_73 , -- V_8 ; V_73 >= 0 ; -- V_73 , -- V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
F_33 ( V_8 -> V_53 ) ;
}
return V_42 ;
}
T_3 F_34 ( void )
{
return V_87 ;
}
static int F_35 ( struct V_4 * V_5 , unsigned int V_88 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_89 = 1UL << ( 2 * V_8 -> V_11 + V_5 -> V_16 ) ;
F_36 ( L_6 , V_88 ? L_7 : L_8 , V_5 -> V_59 ) ;
if ( ! V_88 )
V_87 |= V_89 ;
else
V_87 &= ~ V_89 ;
return 0 ;
}
static void F_37 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_38 ( V_91 ) ;
struct V_7 * V_8 = V_93 -> V_8 ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
int V_94 ;
F_40 ( V_3 , V_91 ) ;
V_94 = F_26 ( V_8 -> V_53 , V_93 -> V_59 ) ;
F_27 ( V_94 ) ;
F_41 ( V_3 , V_91 ) ;
}
static inline void F_42 ( unsigned long V_95 ,
struct V_53 * V_96 )
{
unsigned int V_59 ;
while ( V_95 ) {
V_59 = F_43 ( V_95 ) - 1 ;
F_27 ( F_44 ( V_96 , V_59 ) ) ;
V_95 &= ~ ( 1 << V_59 ) ;
}
}
static void F_45 ( struct V_90 * V_91 )
{
struct V_2 * V_3 = F_39 ( V_91 ) ;
struct V_97 * V_93 = F_38 ( V_91 ) ;
unsigned long V_95 ;
unsigned long V_12 ;
int V_73 ;
F_40 ( V_3 , V_91 ) ;
for ( V_73 = 0 ; V_73 < V_93 -> V_75 ; ++ V_73 ) {
struct V_7 * V_57 = V_93 -> V_98 [ V_73 ] ;
V_95 = F_7 ( V_57 -> V_15 + V_57 -> V_2 -> V_18
+ V_57 -> V_11 ) ;
V_12 = F_7 ( V_57 -> V_15 + V_57 -> V_2 -> V_10
+ V_57 -> V_11 ) ;
F_42 ( V_95 & ~ V_12 , V_57 -> V_53 ) ;
}
F_41 ( V_3 , V_91 ) ;
}
int F_46 ( struct V_61 * V_62 )
{
struct V_71 * V_72 = V_62 -> V_72 ;
struct V_99 * V_100 = NULL ;
struct V_99 * V_101 ;
struct V_7 * V_8 ;
struct V_92 * V_102 ;
struct V_97 * V_103 ;
struct V_1 * V_2 ;
unsigned int V_104 = 0 ;
unsigned int V_73 ;
int V_105 , V_59 ;
F_47 (dev->of_node, np) {
const struct V_106 * V_107 ;
V_107 = F_48 ( V_108 , V_101 ) ;
if ( V_107 ) {
V_2 = F_49 ( V_107 -> V_60 ,
sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_100 = V_101 ;
break;
}
}
if ( ! V_100 )
return - V_109 ;
V_8 = V_62 -> V_63 ;
for ( V_73 = 0 ; V_73 < V_62 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_110 )
continue;
V_8 -> V_53 = F_31 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_53 ) {
F_18 ( V_72 , L_9 ) ;
return - V_74 ;
}
V_8 -> V_2 = V_2 ;
if ( ! F_50 ( V_8 -> V_78 , L_10 , NULL ) ) {
V_8 -> V_76 = V_111 ;
++ V_104 ;
continue;
}
V_102 = F_32 ( V_72 , V_8 -> V_79
* sizeof( * V_102 ) , V_84 ) ;
if ( ! V_102 )
return - V_85 ;
for ( V_105 = 0 ; V_105 < V_8 -> V_79 ; ++ V_105 ) {
V_59 = F_51 ( V_8 -> V_78 , V_105 ) ;
if ( ! V_59 ) {
F_18 ( V_72 , L_11 ,
V_8 -> V_45 , V_105 ) ;
continue;
}
V_102 [ V_105 ] . V_59 = V_105 ;
V_102 [ V_105 ] . V_8 = V_8 ;
F_52 ( V_59 ,
F_37 ,
& V_102 [ V_105 ] ) ;
}
}
if ( ! V_104 )
return 0 ;
V_59 = F_51 ( V_100 , 0 ) ;
if ( ! V_59 ) {
F_18 ( V_72 , L_12 ) ;
return 0 ;
}
V_103 = F_32 ( V_72 , sizeof( * V_103 )
+ V_104 * sizeof( struct V_7 * ) , V_84 ) ;
if ( ! V_103 )
return - V_85 ;
F_52 ( V_59 , F_45 ,
V_103 ) ;
V_8 = V_62 -> V_63 ;
V_105 = 0 ;
for ( V_73 = 0 ; V_73 < V_62 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_111 )
continue;
V_103 -> V_98 [ V_105 ++ ] = V_8 ;
}
V_103 -> V_75 = V_104 ;
return 0 ;
}
static void F_53 (
struct V_61 * V_112 ,
struct V_7 * V_8 )
{
struct V_83 * V_113 = V_8 -> V_82 ;
void T_4 * V_114 = V_8 -> V_15 ;
V_113 -> V_25 = F_7 ( V_114 + V_115
+ V_8 -> V_11 ) ;
V_113 -> V_116 = F_7 ( V_114 + V_117
+ 2 * V_8 -> V_11 ) ;
V_113 -> V_118 = F_7 ( V_114 + V_117
+ 2 * V_8 -> V_11 + 4 ) ;
F_54 ( L_13 , V_8 -> V_45 , V_113 -> V_25 ) ;
F_54 ( L_14 , V_8 -> V_45 , V_113 -> V_116 ) ;
F_54 ( L_15 , V_8 -> V_45 , V_113 -> V_118 ) ;
}
void F_55 ( struct V_61 * V_112 )
{
struct V_7 * V_8 = V_112 -> V_63 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_112 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_53 ( V_112 , V_8 ) ;
}
static void F_56 (
struct V_61 * V_112 ,
struct V_7 * V_8 )
{
struct V_83 * V_113 = V_8 -> V_82 ;
void T_4 * V_114 = V_8 -> V_15 ;
F_54 ( L_16 , V_8 -> V_45 ,
F_7 ( V_114 + V_115
+ V_8 -> V_11 ) , V_113 -> V_25 ) ;
F_54 ( L_17 , V_8 -> V_45 ,
F_7 ( V_114 + V_117
+ 2 * V_8 -> V_11 ) , V_113 -> V_116 ) ;
F_54 ( L_18 , V_8 -> V_45 ,
F_7 ( V_114 + V_117
+ 2 * V_8 -> V_11 + 4 ) , V_113 -> V_118 ) ;
F_8 ( V_113 -> V_25 , V_114 + V_115
+ V_8 -> V_11 ) ;
F_8 ( V_113 -> V_116 , V_114 + V_117
+ 2 * V_8 -> V_11 ) ;
F_8 ( V_113 -> V_118 , V_114 + V_117
+ 2 * V_8 -> V_11 + 4 ) ;
}
void F_57 ( struct V_61 * V_112 )
{
struct V_7 * V_8 = V_112 -> V_63 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_112 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_56 ( V_112 , V_8 ) ;
}
static void F_58 ( struct V_61 * V_112 )
{
if ( V_112 -> V_119 -> V_120 )
F_59 ( V_112 -> V_119 -> V_120 ) ;
}
static void F_60 ( struct V_61 * V_112 )
{
struct V_121 * V_122 = V_112 -> V_119 ;
struct V_123 * V_124 = V_122 -> V_125 ;
int V_73 ;
if ( V_122 -> V_120 && ! F_61 ( V_122 -> V_120 ) )
return;
for ( V_73 = 0 ; V_73 < V_122 -> V_126 ; V_73 ++ )
F_62 ( V_124 , V_122 -> V_114 [ V_73 ] , V_122 -> V_127 ) ;
}
struct V_121 *
F_63 ( struct V_61 * V_112 ,
const struct V_128 * V_60 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
int V_73 ;
V_122 = F_32 ( V_112 -> V_72 , sizeof( * V_122 ) , V_84 ) ;
if ( ! V_122 )
return F_64 ( - V_85 ) ;
V_124 = F_65 () ;
if ( F_66 ( V_124 ) )
return F_67 ( V_124 ) ;
V_122 -> V_125 = V_124 ;
V_122 -> V_114 = V_60 -> V_114 ;
V_122 -> V_126 = V_60 -> V_126 ;
V_122 -> V_127 = V_60 -> V_127 ;
V_122 -> V_120 = V_60 -> V_120 ;
V_122 -> V_129 = F_58 ;
V_122 -> V_130 = F_60 ;
for ( V_73 = 0 ; V_73 < V_122 -> V_126 ; V_73 ++ )
F_62 ( V_124 , V_122 -> V_114 [ V_73 ] , V_122 -> V_127 ) ;
return V_122 ;
}
