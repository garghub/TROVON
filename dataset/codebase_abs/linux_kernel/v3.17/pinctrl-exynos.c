static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_12 = V_6 -> V_13 + V_8 -> V_14 ;
unsigned long V_15 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = F_7 ( V_10 -> V_18 + V_12 ) ;
V_15 |= 1 << V_5 -> V_19 ;
F_8 ( V_15 , V_10 -> V_18 + V_12 ) ;
F_9 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_20 = V_6 -> V_21 + V_8 -> V_14 ;
F_8 ( 1 << V_5 -> V_19 , V_10 -> V_18 + V_20 ) ;
}
static void F_11 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_12 = V_6 -> V_13 + V_8 -> V_14 ;
unsigned long V_15 ;
unsigned long V_16 ;
if ( F_12 ( V_5 ) & V_22 )
F_10 ( V_5 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = F_7 ( V_10 -> V_18 + V_12 ) ;
V_15 &= ~ ( 1 << V_5 -> V_19 ) ;
F_8 ( V_15 , V_10 -> V_18 + V_12 ) ;
F_9 ( & V_8 -> V_17 , V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 , unsigned int type )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_23 = V_24 * V_5 -> V_19 ;
unsigned int V_25 , V_26 ;
unsigned long V_27 = V_6 -> V_28 + V_8 -> V_14 ;
switch ( type ) {
case V_29 :
V_26 = V_30 ;
break;
case V_31 :
V_26 = V_32 ;
break;
case V_33 :
V_26 = V_34 ;
break;
case V_35 :
V_26 = V_36 ;
break;
case V_37 :
V_26 = V_38 ;
break;
default:
F_14 ( L_1 ) ;
return - V_39 ;
}
if ( type & V_33 )
F_15 ( V_5 -> V_40 , V_41 ) ;
else
F_15 ( V_5 -> V_40 , V_42 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_43 << V_23 ) ;
V_25 |= V_26 << V_23 ;
F_8 ( V_25 , V_10 -> V_18 + V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_44 * V_45 = V_8 -> type ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_23 = V_24 * V_5 -> V_19 ;
unsigned long V_27 = V_6 -> V_28 + V_8 -> V_14 ;
unsigned long V_16 ;
unsigned int V_15 ;
unsigned int V_25 ;
int V_46 ;
V_46 = F_17 ( & V_8 -> V_47 , V_5 -> V_19 ) ;
if ( V_46 ) {
F_18 ( V_8 -> V_47 . V_48 , L_2 ,
V_8 -> V_49 , V_5 -> V_19 ) ;
return V_46 ;
}
V_27 = V_8 -> V_50 + V_45 -> V_51 [ V_52 ] ;
V_23 = V_5 -> V_19 * V_45 -> V_53 [ V_52 ] ;
V_15 = ( 1 << V_45 -> V_53 [ V_52 ] ) - 1 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_15 << V_23 ) ;
V_25 |= V_54 << V_23 ;
F_8 ( V_25 , V_10 -> V_18 + V_27 ) ;
F_9 ( & V_8 -> V_17 , V_16 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_44 * V_45 = V_8 -> type ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_23 = V_24 * V_5 -> V_19 ;
unsigned long V_27 = V_6 -> V_28 + V_8 -> V_14 ;
unsigned long V_16 ;
unsigned int V_15 ;
unsigned int V_25 ;
V_27 = V_8 -> V_50 + V_45 -> V_51 [ V_52 ] ;
V_23 = V_5 -> V_19 * V_45 -> V_53 [ V_52 ] ;
V_15 = ( 1 << V_45 -> V_53 [ V_52 ] ) - 1 ;
F_3 ( V_5 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_15 << V_23 ) ;
V_25 |= V_55 << V_23 ;
F_8 ( V_25 , V_10 -> V_18 + V_27 ) ;
F_9 ( & V_8 -> V_17 , V_16 ) ;
F_20 ( & V_8 -> V_47 , V_5 -> V_19 ) ;
}
static int F_21 ( struct V_56 * V_57 , unsigned int V_58 ,
T_1 V_59 )
{
struct V_7 * V_60 = V_57 -> V_61 ;
F_22 ( V_58 , V_60 ) ;
F_23 ( V_58 , & V_62 . V_3 ,
V_42 ) ;
F_24 ( V_58 , V_63 ) ;
return 0 ;
}
static T_2 F_25 ( int V_40 , void * V_64 )
{
struct V_9 * V_10 = V_64 ;
struct V_65 * V_66 = V_10 -> V_66 ;
struct V_7 * V_8 = V_66 -> V_67 ;
unsigned int V_68 , V_69 , V_70 , V_58 ;
V_68 = F_7 ( V_10 -> V_18 + V_71 ) ;
V_69 = F_26 ( V_68 ) ;
V_70 = V_68 & V_72 ;
if ( ! V_69 )
return V_73 ;
V_8 += ( V_69 - 1 ) ;
V_58 = F_27 ( V_8 -> V_56 , V_70 ) ;
if ( ! V_58 )
return V_74 ;
F_28 ( V_58 ) ;
return V_73 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_75 * V_48 = V_10 -> V_48 ;
int V_46 ;
int V_76 ;
if ( ! V_10 -> V_40 ) {
F_18 ( V_48 , L_3 ) ;
return - V_39 ;
}
V_46 = F_30 ( V_48 , V_10 -> V_40 , F_25 ,
0 , F_31 ( V_48 ) , V_10 ) ;
if ( V_46 ) {
F_18 ( V_48 , L_4 ) ;
return - V_77 ;
}
V_8 = V_10 -> V_66 -> V_67 ;
for ( V_76 = 0 ; V_76 < V_10 -> V_66 -> V_78 ; ++ V_76 , ++ V_8 ) {
if ( V_8 -> V_79 != V_80 )
continue;
V_8 -> V_56 = F_32 ( V_8 -> V_81 ,
V_8 -> V_82 , & V_83 , V_8 ) ;
if ( ! V_8 -> V_56 ) {
F_18 ( V_48 , L_5 ) ;
V_46 = - V_77 ;
goto V_84;
}
V_8 -> V_85 = F_33 ( V_10 -> V_48 ,
sizeof( struct V_86 ) , V_87 ) ;
if ( ! V_8 -> V_85 ) {
F_34 ( V_8 -> V_56 ) ;
V_46 = - V_88 ;
goto V_84;
}
}
return 0 ;
V_84:
for ( -- V_76 , -- V_8 ; V_76 >= 0 ; -- V_76 , -- V_8 ) {
if ( V_8 -> V_79 != V_80 )
continue;
F_34 ( V_8 -> V_56 ) ;
}
return V_46 ;
}
T_3 F_35 ( void )
{
return V_89 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned int V_90 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_91 = 1UL << ( 2 * V_8 -> V_14 + V_5 -> V_19 ) ;
F_37 ( L_6 , V_90 ? L_7 : L_8 , V_5 -> V_40 ) ;
if ( ! V_90 )
V_89 |= V_91 ;
else
V_89 &= ~ V_91 ;
return 0 ;
}
static void F_38 ( unsigned int V_40 , struct V_92 * V_93 )
{
struct V_94 * V_95 = F_39 ( V_40 ) ;
struct V_7 * V_8 = V_95 -> V_8 ;
struct V_2 * V_3 = F_40 ( V_40 ) ;
int V_96 ;
F_41 ( V_3 , V_93 ) ;
V_3 -> V_97 ( & V_93 -> V_4 ) ;
if ( V_3 -> V_98 )
V_3 -> V_98 ( & V_93 -> V_4 ) ;
V_96 = F_27 ( V_8 -> V_56 , V_95 -> V_40 ) ;
F_28 ( V_96 ) ;
V_3 -> V_99 ( & V_93 -> V_4 ) ;
F_42 ( V_3 , V_93 ) ;
}
static inline void F_43 ( unsigned long V_100 ,
struct V_56 * V_101 )
{
unsigned int V_40 ;
while ( V_100 ) {
V_40 = F_44 ( V_100 ) - 1 ;
F_28 ( F_45 ( V_101 , V_40 ) ) ;
V_100 &= ~ ( 1 << V_40 ) ;
}
}
static void F_46 ( unsigned int V_40 , struct V_92 * V_93 )
{
struct V_2 * V_3 = F_40 ( V_40 ) ;
struct V_102 * V_95 = F_39 ( V_40 ) ;
struct V_9 * V_10 = V_95 -> V_103 [ 0 ] -> V_11 ;
unsigned long V_100 ;
unsigned long V_15 ;
int V_76 ;
F_41 ( V_3 , V_93 ) ;
for ( V_76 = 0 ; V_76 < V_95 -> V_78 ; ++ V_76 ) {
struct V_7 * V_60 = V_95 -> V_103 [ V_76 ] ;
V_100 = F_7 ( V_10 -> V_18 + V_104
+ V_60 -> V_14 ) ;
V_15 = F_7 ( V_10 -> V_18 + V_105
+ V_60 -> V_14 ) ;
F_43 ( V_100 & ~ V_15 , V_60 -> V_56 ) ;
}
F_42 ( V_3 , V_93 ) ;
}
static int F_47 ( struct V_56 * V_57 , unsigned int V_58 ,
T_1 V_59 )
{
F_23 ( V_58 , & V_106 . V_3 ,
V_42 ) ;
F_22 ( V_58 , V_57 -> V_61 ) ;
F_24 ( V_58 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
struct V_75 * V_48 = V_10 -> V_48 ;
struct V_107 * V_108 = NULL ;
struct V_107 * V_109 ;
struct V_7 * V_8 ;
struct V_94 * V_110 ;
struct V_102 * V_111 ;
unsigned int V_112 = 0 ;
unsigned int V_76 ;
int V_113 , V_40 ;
F_49 (dev->of_node, np) {
if ( F_50 ( V_114 , V_109 ) ) {
V_108 = V_109 ;
break;
}
}
if ( ! V_108 )
return - V_115 ;
V_8 = V_10 -> V_66 -> V_67 ;
for ( V_76 = 0 ; V_76 < V_10 -> V_66 -> V_78 ; ++ V_76 , ++ V_8 ) {
if ( V_8 -> V_79 != V_116 )
continue;
V_8 -> V_56 = F_32 ( V_8 -> V_81 ,
V_8 -> V_82 , & V_117 , V_8 ) ;
if ( ! V_8 -> V_56 ) {
F_18 ( V_48 , L_9 ) ;
return - V_77 ;
}
if ( ! F_51 ( V_8 -> V_81 , L_10 , NULL ) ) {
V_8 -> V_79 = V_118 ;
++ V_112 ;
continue;
}
V_110 = F_33 ( V_48 , V_8 -> V_82
* sizeof( * V_110 ) , V_87 ) ;
if ( ! V_110 ) {
F_18 ( V_48 , L_11 ) ;
return - V_88 ;
}
for ( V_113 = 0 ; V_113 < V_8 -> V_82 ; ++ V_113 ) {
V_40 = F_52 ( V_8 -> V_81 , V_113 ) ;
if ( ! V_40 ) {
F_18 ( V_48 , L_12 ,
V_8 -> V_49 , V_113 ) ;
continue;
}
V_110 [ V_113 ] . V_40 = V_113 ;
V_110 [ V_113 ] . V_8 = V_8 ;
F_53 ( V_40 , & V_110 [ V_113 ] ) ;
F_54 ( V_40 , F_38 ) ;
}
}
if ( ! V_112 )
return 0 ;
V_40 = F_52 ( V_108 , 0 ) ;
if ( ! V_40 ) {
F_18 ( V_48 , L_13 ) ;
return 0 ;
}
V_111 = F_33 ( V_48 , sizeof( * V_111 )
+ V_112 * sizeof( struct V_7 * ) , V_87 ) ;
if ( ! V_111 ) {
F_18 ( V_48 , L_14 ) ;
return - V_88 ;
}
F_54 ( V_40 , F_46 ) ;
F_53 ( V_40 , V_111 ) ;
V_8 = V_10 -> V_66 -> V_67 ;
V_113 = 0 ;
for ( V_76 = 0 ; V_76 < V_10 -> V_66 -> V_78 ; ++ V_76 , ++ V_8 ) {
if ( V_8 -> V_79 != V_118 )
continue;
V_111 -> V_103 [ V_113 ++ ] = V_8 ;
}
V_111 -> V_78 = V_112 ;
return 0 ;
}
static void F_55 (
struct V_9 * V_11 ,
struct V_7 * V_8 )
{
struct V_86 * V_119 = V_8 -> V_85 ;
void T_4 * V_120 = V_11 -> V_18 ;
V_119 -> V_28 = F_7 ( V_120 + V_121
+ V_8 -> V_14 ) ;
V_119 -> V_122 = F_7 ( V_120 + V_123
+ 2 * V_8 -> V_14 ) ;
V_119 -> V_124 = F_7 ( V_120 + V_123
+ 2 * V_8 -> V_14 + 4 ) ;
F_56 ( L_15 , V_8 -> V_49 , V_119 -> V_28 ) ;
F_56 ( L_16 , V_8 -> V_49 , V_119 -> V_122 ) ;
F_56 ( L_17 , V_8 -> V_49 , V_119 -> V_124 ) ;
}
static void F_57 ( struct V_9 * V_11 )
{
struct V_65 * V_66 = V_11 -> V_66 ;
struct V_7 * V_8 = V_66 -> V_67 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_66 -> V_78 ; ++ V_76 , ++ V_8 )
if ( V_8 -> V_79 == V_80 )
F_55 ( V_11 , V_8 ) ;
}
static void F_58 (
struct V_9 * V_11 ,
struct V_7 * V_8 )
{
struct V_86 * V_119 = V_8 -> V_85 ;
void T_4 * V_120 = V_11 -> V_18 ;
F_56 ( L_18 , V_8 -> V_49 ,
F_7 ( V_120 + V_121
+ V_8 -> V_14 ) , V_119 -> V_28 ) ;
F_56 ( L_19 , V_8 -> V_49 ,
F_7 ( V_120 + V_123
+ 2 * V_8 -> V_14 ) , V_119 -> V_122 ) ;
F_56 ( L_20 , V_8 -> V_49 ,
F_7 ( V_120 + V_123
+ 2 * V_8 -> V_14 + 4 ) , V_119 -> V_124 ) ;
F_8 ( V_119 -> V_28 , V_120 + V_121
+ V_8 -> V_14 ) ;
F_8 ( V_119 -> V_122 , V_120 + V_123
+ 2 * V_8 -> V_14 ) ;
F_8 ( V_119 -> V_124 , V_120 + V_123
+ 2 * V_8 -> V_14 + 4 ) ;
}
static void F_59 ( struct V_9 * V_11 )
{
struct V_65 * V_66 = V_11 -> V_66 ;
struct V_7 * V_8 = V_66 -> V_67 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_66 -> V_78 ; ++ V_76 , ++ V_8 )
if ( V_8 -> V_79 == V_80 )
F_58 ( V_11 , V_8 ) ;
}
