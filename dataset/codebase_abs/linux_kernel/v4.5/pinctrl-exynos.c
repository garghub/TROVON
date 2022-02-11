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
F_15 ( V_5 , V_40 ) ;
else
F_15 ( V_5 , V_41 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_42 << V_23 ) ;
V_25 |= V_26 << V_23 ;
F_8 ( V_25 , V_10 -> V_18 + V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
const struct V_43 * V_44 = V_8 -> type ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_23 = V_24 * V_5 -> V_19 ;
unsigned long V_27 = V_6 -> V_28 + V_8 -> V_14 ;
unsigned long V_16 ;
unsigned int V_15 ;
unsigned int V_25 ;
int V_45 ;
V_45 = F_17 ( & V_8 -> V_46 , V_5 -> V_19 ) ;
if ( V_45 ) {
F_18 ( V_8 -> V_46 . V_47 ,
L_2 ,
V_8 -> V_48 , V_5 -> V_19 ) ;
return V_45 ;
}
V_27 = V_8 -> V_49 + V_44 -> V_50 [ V_51 ] ;
V_23 = V_5 -> V_19 * V_44 -> V_52 [ V_51 ] ;
V_15 = ( 1 << V_44 -> V_52 [ V_51 ] ) - 1 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_15 << V_23 ) ;
V_25 |= V_53 << V_23 ;
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
const struct V_43 * V_44 = V_8 -> type ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_23 = V_24 * V_5 -> V_19 ;
unsigned long V_27 = V_6 -> V_28 + V_8 -> V_14 ;
unsigned long V_16 ;
unsigned int V_15 ;
unsigned int V_25 ;
V_27 = V_8 -> V_49 + V_44 -> V_50 [ V_51 ] ;
V_23 = V_5 -> V_19 * V_44 -> V_52 [ V_51 ] ;
V_15 = ( 1 << V_44 -> V_52 [ V_51 ] ) - 1 ;
F_3 ( V_5 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_7 ( V_10 -> V_18 + V_27 ) ;
V_25 &= ~ ( V_15 << V_23 ) ;
V_25 |= V_54 << V_23 ;
F_8 ( V_25 , V_10 -> V_18 + V_27 ) ;
F_9 ( & V_8 -> V_17 , V_16 ) ;
F_20 ( & V_8 -> V_46 , V_5 -> V_19 ) ;
}
static int F_21 ( struct V_55 * V_56 , unsigned int V_57 ,
T_1 V_58 )
{
struct V_7 * V_59 = V_56 -> V_60 ;
F_22 ( V_57 , V_59 ) ;
F_23 ( V_57 , & V_59 -> V_2 -> V_3 ,
V_41 ) ;
return 0 ;
}
static T_2 F_24 ( int V_61 , void * V_62 )
{
struct V_9 * V_10 = V_62 ;
struct V_7 * V_8 = V_10 -> V_63 ;
unsigned int V_64 , V_65 , V_66 , V_57 ;
V_64 = F_7 ( V_10 -> V_18 + V_67 ) ;
V_65 = F_25 ( V_64 ) ;
V_66 = V_64 & V_68 ;
if ( ! V_65 )
return V_69 ;
V_8 += ( V_65 - 1 ) ;
V_57 = F_26 ( V_8 -> V_55 , V_66 ) ;
if ( ! V_57 )
return V_70 ;
F_27 ( V_57 ) ;
return V_69 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_71 * V_72 = V_10 -> V_72 ;
int V_45 ;
int V_73 ;
if ( ! V_10 -> V_61 ) {
F_18 ( V_72 , L_3 ) ;
return - V_39 ;
}
V_45 = F_29 ( V_72 , V_10 -> V_61 , F_24 ,
0 , F_30 ( V_72 ) , V_10 ) ;
if ( V_45 ) {
F_18 ( V_72 , L_4 ) ;
return - V_74 ;
}
V_8 = V_10 -> V_63 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
V_8 -> V_55 = F_31 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_55 ) {
F_18 ( V_72 , L_5 ) ;
V_45 = - V_74 ;
goto V_81;
}
V_8 -> V_82 = F_32 ( V_10 -> V_72 ,
sizeof( struct V_83 ) , V_84 ) ;
if ( ! V_8 -> V_82 ) {
F_33 ( V_8 -> V_55 ) ;
V_45 = - V_85 ;
goto V_81;
}
V_8 -> V_2 = & V_86 ;
}
return 0 ;
V_81:
for ( -- V_73 , -- V_8 ; V_73 >= 0 ; -- V_73 , -- V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
F_33 ( V_8 -> V_55 ) ;
}
return V_45 ;
}
T_3 F_34 ( void )
{
return V_87 ;
}
static int F_35 ( struct V_4 * V_5 , unsigned int V_88 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_89 = 1UL << ( 2 * V_8 -> V_14 + V_5 -> V_19 ) ;
F_36 ( L_6 , V_88 ? L_7 : L_8 , V_5 -> V_61 ) ;
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
V_3 -> V_95 ( & V_91 -> V_4 ) ;
if ( V_3 -> V_96 )
V_3 -> V_96 ( & V_91 -> V_4 ) ;
V_94 = F_26 ( V_8 -> V_55 , V_93 -> V_61 ) ;
F_27 ( V_94 ) ;
V_3 -> V_97 ( & V_91 -> V_4 ) ;
F_41 ( V_3 , V_91 ) ;
}
static inline void F_42 ( unsigned long V_98 ,
struct V_55 * V_99 )
{
unsigned int V_61 ;
while ( V_98 ) {
V_61 = F_43 ( V_98 ) - 1 ;
F_27 ( F_44 ( V_99 , V_61 ) ) ;
V_98 &= ~ ( 1 << V_61 ) ;
}
}
static void F_45 ( struct V_90 * V_91 )
{
struct V_2 * V_3 = F_39 ( V_91 ) ;
struct V_100 * V_93 = F_38 ( V_91 ) ;
struct V_9 * V_10 = V_93 -> V_101 [ 0 ] -> V_11 ;
unsigned long V_98 ;
unsigned long V_15 ;
int V_73 ;
F_40 ( V_3 , V_91 ) ;
for ( V_73 = 0 ; V_73 < V_93 -> V_75 ; ++ V_73 ) {
struct V_7 * V_59 = V_93 -> V_101 [ V_73 ] ;
V_98 = F_7 ( V_10 -> V_18 + V_59 -> V_2 -> V_21
+ V_59 -> V_14 ) ;
V_15 = F_7 ( V_10 -> V_18 + V_59 -> V_2 -> V_13
+ V_59 -> V_14 ) ;
F_42 ( V_98 & ~ V_15 , V_59 -> V_55 ) ;
}
F_41 ( V_3 , V_91 ) ;
}
static int F_46 ( struct V_9 * V_10 )
{
struct V_71 * V_72 = V_10 -> V_72 ;
struct V_102 * V_103 = NULL ;
struct V_102 * V_104 ;
struct V_7 * V_8 ;
struct V_92 * V_105 ;
struct V_100 * V_106 ;
struct V_1 * V_2 ;
unsigned int V_107 = 0 ;
unsigned int V_73 ;
int V_108 , V_61 ;
F_47 (dev->of_node, np) {
const struct V_109 * V_110 ;
V_110 = F_48 ( V_111 , V_104 ) ;
if ( V_110 ) {
V_2 = F_49 ( V_110 -> V_62 ,
sizeof( * V_2 ) , V_84 ) ;
V_103 = V_104 ;
break;
}
}
if ( ! V_103 )
return - V_112 ;
V_8 = V_10 -> V_63 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_113 )
continue;
V_8 -> V_55 = F_31 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_55 ) {
F_18 ( V_72 , L_9 ) ;
return - V_74 ;
}
V_8 -> V_2 = V_2 ;
if ( ! F_50 ( V_8 -> V_78 , L_10 , NULL ) ) {
V_8 -> V_76 = V_114 ;
++ V_107 ;
continue;
}
V_105 = F_32 ( V_72 , V_8 -> V_79
* sizeof( * V_105 ) , V_84 ) ;
if ( ! V_105 ) {
F_18 ( V_72 , L_11 ) ;
return - V_85 ;
}
for ( V_108 = 0 ; V_108 < V_8 -> V_79 ; ++ V_108 ) {
V_61 = F_51 ( V_8 -> V_78 , V_108 ) ;
if ( ! V_61 ) {
F_18 ( V_72 , L_12 ,
V_8 -> V_48 , V_108 ) ;
continue;
}
V_105 [ V_108 ] . V_61 = V_108 ;
V_105 [ V_108 ] . V_8 = V_8 ;
F_52 ( V_61 ,
F_37 ,
& V_105 [ V_108 ] ) ;
}
}
if ( ! V_107 )
return 0 ;
V_61 = F_51 ( V_103 , 0 ) ;
if ( ! V_61 ) {
F_18 ( V_72 , L_13 ) ;
return 0 ;
}
V_106 = F_32 ( V_72 , sizeof( * V_106 )
+ V_107 * sizeof( struct V_7 * ) , V_84 ) ;
if ( ! V_106 ) {
F_18 ( V_72 , L_14 ) ;
return - V_85 ;
}
F_52 ( V_61 , F_45 ,
V_106 ) ;
V_8 = V_10 -> V_63 ;
V_108 = 0 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_114 )
continue;
V_106 -> V_101 [ V_108 ++ ] = V_8 ;
}
V_106 -> V_75 = V_107 ;
return 0 ;
}
static void F_53 (
struct V_9 * V_11 ,
struct V_7 * V_8 )
{
struct V_83 * V_115 = V_8 -> V_82 ;
void T_4 * V_116 = V_11 -> V_18 ;
V_115 -> V_28 = F_7 ( V_116 + V_117
+ V_8 -> V_14 ) ;
V_115 -> V_118 = F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 ) ;
V_115 -> V_120 = F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 + 4 ) ;
F_54 ( L_15 , V_8 -> V_48 , V_115 -> V_28 ) ;
F_54 ( L_16 , V_8 -> V_48 , V_115 -> V_118 ) ;
F_54 ( L_17 , V_8 -> V_48 , V_115 -> V_120 ) ;
}
static void F_55 ( struct V_9 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_11 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_53 ( V_11 , V_8 ) ;
}
static void F_56 (
struct V_9 * V_11 ,
struct V_7 * V_8 )
{
struct V_83 * V_115 = V_8 -> V_82 ;
void T_4 * V_116 = V_11 -> V_18 ;
F_54 ( L_18 , V_8 -> V_48 ,
F_7 ( V_116 + V_117
+ V_8 -> V_14 ) , V_115 -> V_28 ) ;
F_54 ( L_19 , V_8 -> V_48 ,
F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 ) , V_115 -> V_118 ) ;
F_54 ( L_20 , V_8 -> V_48 ,
F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 + 4 ) , V_115 -> V_120 ) ;
F_8 ( V_115 -> V_28 , V_116 + V_117
+ V_8 -> V_14 ) ;
F_8 ( V_115 -> V_118 , V_116 + V_119
+ 2 * V_8 -> V_14 ) ;
F_8 ( V_115 -> V_120 , V_116 + V_119
+ 2 * V_8 -> V_14 + 4 ) ;
}
static void F_57 ( struct V_9 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_11 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_56 ( V_11 , V_8 ) ;
}
