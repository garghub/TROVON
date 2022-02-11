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
const struct V_44 * V_45 = V_8 -> type ;
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
const struct V_44 * V_45 = V_8 -> type ;
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
F_23 ( V_58 , & V_60 -> V_2 -> V_3 ,
V_42 ) ;
F_24 ( V_58 , V_62 ) ;
return 0 ;
}
static T_2 F_25 ( int V_40 , void * V_63 )
{
struct V_9 * V_10 = V_63 ;
struct V_7 * V_8 = V_10 -> V_64 ;
unsigned int V_65 , V_66 , V_67 , V_58 ;
V_65 = F_7 ( V_10 -> V_18 + V_68 ) ;
V_66 = F_26 ( V_65 ) ;
V_67 = V_65 & V_69 ;
if ( ! V_66 )
return V_70 ;
V_8 += ( V_66 - 1 ) ;
V_58 = F_27 ( V_8 -> V_56 , V_67 ) ;
if ( ! V_58 )
return V_71 ;
F_28 ( V_58 ) ;
return V_70 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_72 * V_48 = V_10 -> V_48 ;
int V_46 ;
int V_73 ;
if ( ! V_10 -> V_40 ) {
F_18 ( V_48 , L_3 ) ;
return - V_39 ;
}
V_46 = F_30 ( V_48 , V_10 -> V_40 , F_25 ,
0 , F_31 ( V_48 ) , V_10 ) ;
if ( V_46 ) {
F_18 ( V_48 , L_4 ) ;
return - V_74 ;
}
V_8 = V_10 -> V_64 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
V_8 -> V_56 = F_32 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_56 ) {
F_18 ( V_48 , L_5 ) ;
V_46 = - V_74 ;
goto V_81;
}
V_8 -> V_82 = F_33 ( V_10 -> V_48 ,
sizeof( struct V_83 ) , V_84 ) ;
if ( ! V_8 -> V_82 ) {
F_34 ( V_8 -> V_56 ) ;
V_46 = - V_85 ;
goto V_81;
}
V_8 -> V_2 = & V_86 ;
}
return 0 ;
V_81:
for ( -- V_73 , -- V_8 ; V_73 >= 0 ; -- V_73 , -- V_8 ) {
if ( V_8 -> V_76 != V_77 )
continue;
F_34 ( V_8 -> V_56 ) ;
}
return V_46 ;
}
T_3 F_35 ( void )
{
return V_87 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned int V_88 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
unsigned long V_89 = 1UL << ( 2 * V_8 -> V_14 + V_5 -> V_19 ) ;
F_37 ( L_6 , V_88 ? L_7 : L_8 , V_5 -> V_40 ) ;
if ( ! V_88 )
V_87 |= V_89 ;
else
V_87 &= ~ V_89 ;
return 0 ;
}
static void F_38 ( unsigned int V_40 , struct V_90 * V_91 )
{
struct V_92 * V_93 = F_39 ( V_40 ) ;
struct V_7 * V_8 = V_93 -> V_8 ;
struct V_2 * V_3 = F_40 ( V_40 ) ;
int V_94 ;
F_41 ( V_3 , V_91 ) ;
V_3 -> V_95 ( & V_91 -> V_4 ) ;
if ( V_3 -> V_96 )
V_3 -> V_96 ( & V_91 -> V_4 ) ;
V_94 = F_27 ( V_8 -> V_56 , V_93 -> V_40 ) ;
F_28 ( V_94 ) ;
V_3 -> V_97 ( & V_91 -> V_4 ) ;
F_42 ( V_3 , V_91 ) ;
}
static inline void F_43 ( unsigned long V_98 ,
struct V_56 * V_99 )
{
unsigned int V_40 ;
while ( V_98 ) {
V_40 = F_44 ( V_98 ) - 1 ;
F_28 ( F_45 ( V_99 , V_40 ) ) ;
V_98 &= ~ ( 1 << V_40 ) ;
}
}
static void F_46 ( unsigned int V_40 , struct V_90 * V_91 )
{
struct V_2 * V_3 = F_40 ( V_40 ) ;
struct V_100 * V_93 = F_39 ( V_40 ) ;
struct V_9 * V_10 = V_93 -> V_101 [ 0 ] -> V_11 ;
unsigned long V_98 ;
unsigned long V_15 ;
int V_73 ;
F_41 ( V_3 , V_91 ) ;
for ( V_73 = 0 ; V_73 < V_93 -> V_75 ; ++ V_73 ) {
struct V_7 * V_60 = V_93 -> V_101 [ V_73 ] ;
V_98 = F_7 ( V_10 -> V_18 + V_60 -> V_2 -> V_21
+ V_60 -> V_14 ) ;
V_15 = F_7 ( V_10 -> V_18 + V_60 -> V_2 -> V_13
+ V_60 -> V_14 ) ;
F_43 ( V_98 & ~ V_15 , V_60 -> V_56 ) ;
}
F_42 ( V_3 , V_91 ) ;
}
static int F_47 ( struct V_9 * V_10 )
{
struct V_72 * V_48 = V_10 -> V_48 ;
struct V_102 * V_103 = NULL ;
struct V_102 * V_104 ;
struct V_7 * V_8 ;
struct V_92 * V_105 ;
struct V_100 * V_106 ;
struct V_1 * V_2 ;
unsigned int V_107 = 0 ;
unsigned int V_73 ;
int V_108 , V_40 ;
F_48 (dev->of_node, np) {
const struct V_109 * V_110 ;
V_110 = F_49 ( V_111 , V_104 ) ;
if ( V_110 ) {
V_2 = F_50 ( V_110 -> V_63 ,
sizeof( * V_2 ) , V_84 ) ;
V_103 = V_104 ;
break;
}
}
if ( ! V_103 )
return - V_112 ;
V_8 = V_10 -> V_64 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_113 )
continue;
V_8 -> V_56 = F_32 ( V_8 -> V_78 ,
V_8 -> V_79 , & V_80 , V_8 ) ;
if ( ! V_8 -> V_56 ) {
F_18 ( V_48 , L_9 ) ;
return - V_74 ;
}
V_8 -> V_2 = V_2 ;
if ( ! F_51 ( V_8 -> V_78 , L_10 , NULL ) ) {
V_8 -> V_76 = V_114 ;
++ V_107 ;
continue;
}
V_105 = F_33 ( V_48 , V_8 -> V_79
* sizeof( * V_105 ) , V_84 ) ;
if ( ! V_105 ) {
F_18 ( V_48 , L_11 ) ;
return - V_85 ;
}
for ( V_108 = 0 ; V_108 < V_8 -> V_79 ; ++ V_108 ) {
V_40 = F_52 ( V_8 -> V_78 , V_108 ) ;
if ( ! V_40 ) {
F_18 ( V_48 , L_12 ,
V_8 -> V_49 , V_108 ) ;
continue;
}
V_105 [ V_108 ] . V_40 = V_108 ;
V_105 [ V_108 ] . V_8 = V_8 ;
F_53 ( V_40 , & V_105 [ V_108 ] ) ;
F_54 ( V_40 , F_38 ) ;
}
}
if ( ! V_107 )
return 0 ;
V_40 = F_52 ( V_103 , 0 ) ;
if ( ! V_40 ) {
F_18 ( V_48 , L_13 ) ;
return 0 ;
}
V_106 = F_33 ( V_48 , sizeof( * V_106 )
+ V_107 * sizeof( struct V_7 * ) , V_84 ) ;
if ( ! V_106 ) {
F_18 ( V_48 , L_14 ) ;
return - V_85 ;
}
F_55 ( V_40 , F_46 ,
V_106 ) ;
V_8 = V_10 -> V_64 ;
V_108 = 0 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_75 ; ++ V_73 , ++ V_8 ) {
if ( V_8 -> V_76 != V_114 )
continue;
V_106 -> V_101 [ V_108 ++ ] = V_8 ;
}
V_106 -> V_75 = V_107 ;
return 0 ;
}
static void F_56 (
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
F_57 ( L_15 , V_8 -> V_49 , V_115 -> V_28 ) ;
F_57 ( L_16 , V_8 -> V_49 , V_115 -> V_118 ) ;
F_57 ( L_17 , V_8 -> V_49 , V_115 -> V_120 ) ;
}
static void F_58 ( struct V_9 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_64 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_11 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_56 ( V_11 , V_8 ) ;
}
static void F_59 (
struct V_9 * V_11 ,
struct V_7 * V_8 )
{
struct V_83 * V_115 = V_8 -> V_82 ;
void T_4 * V_116 = V_11 -> V_18 ;
F_57 ( L_18 , V_8 -> V_49 ,
F_7 ( V_116 + V_117
+ V_8 -> V_14 ) , V_115 -> V_28 ) ;
F_57 ( L_19 , V_8 -> V_49 ,
F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 ) , V_115 -> V_118 ) ;
F_57 ( L_20 , V_8 -> V_49 ,
F_7 ( V_116 + V_119
+ 2 * V_8 -> V_14 + 4 ) , V_115 -> V_120 ) ;
F_8 ( V_115 -> V_28 , V_116 + V_117
+ V_8 -> V_14 ) ;
F_8 ( V_115 -> V_118 , V_116 + V_119
+ 2 * V_8 -> V_14 ) ;
F_8 ( V_115 -> V_120 , V_116 + V_119
+ 2 * V_8 -> V_14 + 4 ) ;
}
static void F_60 ( struct V_9 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_64 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_11 -> V_75 ; ++ V_73 , ++ V_8 )
if ( V_8 -> V_76 == V_77 )
F_59 ( V_11 , V_8 ) ;
}
