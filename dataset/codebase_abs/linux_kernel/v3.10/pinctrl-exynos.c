static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_10 + V_4 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 &= ~ ( 1 << V_2 -> V_14 ) ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_10 + V_4 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 |= 1 << V_2 -> V_14 ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_15 = V_6 -> V_9 -> V_16 + V_4 -> V_11 ;
F_4 ( 1 << V_2 -> V_14 , V_6 -> V_13 + V_15 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_4 -> type ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_19 * V_9 = V_6 -> V_9 ;
unsigned int V_20 = V_2 -> V_14 ;
unsigned int V_21 = V_22 * V_20 ;
unsigned int V_23 , V_24 ;
unsigned long V_25 = V_9 -> V_26 + V_4 -> V_11 ;
unsigned long V_27 ;
unsigned int V_12 ;
switch ( type ) {
case V_28 :
V_24 = V_29 ;
break;
case V_30 :
V_24 = V_31 ;
break;
case V_32 :
V_24 = V_33 ;
break;
case V_34 :
V_24 = V_35 ;
break;
case V_36 :
V_24 = V_37 ;
break;
default:
F_8 ( L_1 ) ;
return - V_38 ;
}
if ( type & V_32 )
F_9 ( V_2 -> V_39 , V_40 ) ;
else
F_9 ( V_2 -> V_39 , V_41 ) ;
V_23 = F_3 ( V_6 -> V_13 + V_25 ) ;
V_23 &= ~ ( V_42 << V_21 ) ;
V_23 |= V_24 << V_21 ;
F_4 ( V_23 , V_6 -> V_13 + V_25 ) ;
V_25 = V_4 -> V_43 + V_18 -> V_44 [ V_45 ] ;
V_21 = V_20 * V_18 -> V_46 [ V_45 ] ;
V_12 = ( 1 << V_18 -> V_46 [ V_45 ] ) - 1 ;
F_10 ( & V_4 -> V_47 , V_27 ) ;
V_23 = F_3 ( V_6 -> V_13 + V_25 ) ;
V_23 &= ~ ( V_12 << V_21 ) ;
V_23 |= V_48 << V_21 ;
F_4 ( V_23 , V_6 -> V_13 + V_25 ) ;
F_11 ( & V_4 -> V_47 , V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_49 * V_50 , unsigned int V_51 ,
T_1 V_52 )
{
struct V_3 * V_53 = V_50 -> V_54 ;
F_13 ( V_51 , V_53 ) ;
F_14 ( V_51 , & V_55 ,
V_41 ) ;
F_15 ( V_51 , V_56 ) ;
return 0 ;
}
static T_2 F_16 ( int V_39 , void * V_57 )
{
struct V_5 * V_6 = V_57 ;
struct V_19 * V_9 = V_6 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_58 ;
unsigned int V_59 , V_60 , V_20 , V_51 ;
V_59 = F_3 ( V_6 -> V_13 + V_9 -> V_59 ) ;
V_60 = F_17 ( V_59 ) ;
V_20 = V_59 & V_61 ;
if ( ! V_60 )
return V_62 ;
V_4 += ( V_60 - 1 ) ;
V_51 = F_18 ( V_4 -> V_49 , V_20 ) ;
if ( ! V_51 )
return V_63 ;
F_19 ( V_51 ) ;
return V_62 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_64 * V_65 = V_6 -> V_65 ;
int V_66 ;
int V_67 ;
if ( ! V_6 -> V_39 ) {
F_21 ( V_65 , L_2 ) ;
return - V_38 ;
}
V_66 = F_22 ( V_65 , V_6 -> V_39 , F_16 ,
0 , F_23 ( V_65 ) , V_6 ) ;
if ( V_66 ) {
F_21 ( V_65 , L_3 ) ;
return - V_68 ;
}
V_4 = V_6 -> V_9 -> V_58 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 -> V_69 ; ++ V_67 , ++ V_4 ) {
if ( V_4 -> V_70 != V_71 )
continue;
V_4 -> V_49 = F_24 ( V_4 -> V_72 ,
V_4 -> V_73 , & V_74 , V_4 ) ;
if ( ! V_4 -> V_49 ) {
F_21 ( V_65 , L_4 ) ;
V_66 = - V_68 ;
goto V_75;
}
V_4 -> V_76 = F_25 ( V_6 -> V_65 ,
sizeof( struct V_77 ) , V_78 ) ;
if ( ! V_4 -> V_76 ) {
F_26 ( V_4 -> V_49 ) ;
V_66 = - V_79 ;
goto V_75;
}
}
return 0 ;
V_75:
for ( -- V_67 , -- V_4 ; V_67 >= 0 ; -- V_67 , -- V_4 ) {
if ( V_4 -> V_70 != V_71 )
continue;
F_26 ( V_4 -> V_49 ) ;
}
return V_66 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_53 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_53 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_80 + V_53 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 &= ~ ( 1 << V_2 -> V_14 ) ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_53 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_53 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_80 + V_53 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 |= 1 << V_2 -> V_14 ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_53 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_53 -> V_7 ;
unsigned long V_81 = V_6 -> V_9 -> V_82 + V_53 -> V_11 ;
F_4 ( 1 << V_2 -> V_14 , V_6 -> V_13 + V_81 ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_4 -> type ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_20 = V_2 -> V_14 ;
unsigned long V_25 = V_6 -> V_9 -> V_83 + V_4 -> V_11 ;
unsigned long V_21 = V_22 * V_20 ;
unsigned long V_23 , V_24 ;
unsigned long V_27 ;
unsigned int V_12 ;
switch ( type ) {
case V_28 :
V_24 = V_29 ;
break;
case V_30 :
V_24 = V_31 ;
break;
case V_32 :
V_24 = V_33 ;
break;
case V_34 :
V_24 = V_35 ;
break;
case V_36 :
V_24 = V_37 ;
break;
default:
F_8 ( L_1 ) ;
return - V_38 ;
}
if ( type & V_32 )
F_9 ( V_2 -> V_39 , V_40 ) ;
else
F_9 ( V_2 -> V_39 , V_41 ) ;
V_23 = F_3 ( V_6 -> V_13 + V_25 ) ;
V_23 &= ~ ( V_42 << V_21 ) ;
V_23 |= V_24 << V_21 ;
F_4 ( V_23 , V_6 -> V_13 + V_25 ) ;
V_25 = V_4 -> V_43 + V_18 -> V_44 [ V_45 ] ;
V_21 = V_20 * V_18 -> V_46 [ V_45 ] ;
V_12 = ( 1 << V_18 -> V_46 [ V_45 ] ) - 1 ;
F_10 ( & V_4 -> V_47 , V_27 ) ;
V_23 = F_3 ( V_6 -> V_13 + V_25 ) ;
V_23 &= ~ ( V_12 << V_21 ) ;
V_23 |= V_48 << V_21 ;
F_4 ( V_23 , V_6 -> V_13 + V_25 ) ;
F_11 ( & V_4 -> V_47 , V_27 ) ;
return 0 ;
}
T_3 F_31 ( void )
{
return V_84 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_85 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_86 = 1UL << ( 2 * V_4 -> V_11 + V_2 -> V_14 ) ;
F_33 ( L_5 , V_85 ? L_6 : L_7 , V_2 -> V_39 ) ;
if ( ! V_85 )
V_84 |= V_86 ;
else
V_84 &= ~ V_86 ;
return 0 ;
}
static void F_34 ( unsigned int V_39 , struct V_87 * V_88 )
{
struct V_89 * V_90 = F_35 ( V_39 ) ;
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_91 * V_92 = F_36 ( V_39 ) ;
int V_93 ;
F_37 ( V_92 , V_88 ) ;
V_92 -> V_94 ( & V_88 -> V_1 ) ;
if ( V_92 -> V_95 )
V_92 -> V_95 ( & V_88 -> V_1 ) ;
V_93 = F_18 ( V_4 -> V_49 , V_90 -> V_39 ) ;
F_19 ( V_93 ) ;
V_92 -> V_96 ( & V_88 -> V_1 ) ;
F_38 ( V_92 , V_88 ) ;
}
static inline void F_39 ( unsigned long V_81 ,
struct V_49 * V_97 )
{
unsigned int V_39 ;
while ( V_81 ) {
V_39 = F_40 ( V_81 ) - 1 ;
F_19 ( F_41 ( V_97 , V_39 ) ) ;
V_81 &= ~ ( 1 << V_39 ) ;
}
}
static void F_42 ( unsigned int V_39 , struct V_87 * V_88 )
{
struct V_91 * V_92 = F_36 ( V_39 ) ;
struct V_98 * V_90 = F_35 ( V_39 ) ;
struct V_5 * V_6 = V_90 -> V_99 [ 0 ] -> V_7 ;
struct V_19 * V_9 = V_6 -> V_9 ;
unsigned long V_81 ;
unsigned long V_12 ;
int V_67 ;
F_37 ( V_92 , V_88 ) ;
for ( V_67 = 0 ; V_67 < V_90 -> V_69 ; ++ V_67 ) {
struct V_3 * V_53 = V_90 -> V_99 [ V_67 ] ;
V_81 = F_3 ( V_6 -> V_13 + V_9 -> V_82 + V_53 -> V_11 ) ;
V_12 = F_3 ( V_6 -> V_13 + V_9 -> V_80 + V_53 -> V_11 ) ;
F_39 ( V_81 & ~ V_12 , V_53 -> V_49 ) ;
}
F_38 ( V_92 , V_88 ) ;
}
static int F_43 ( struct V_49 * V_50 , unsigned int V_51 ,
T_1 V_52 )
{
F_14 ( V_51 , & V_100 , V_41 ) ;
F_13 ( V_51 , V_50 -> V_54 ) ;
F_15 ( V_51 , V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_64 * V_65 = V_6 -> V_65 ;
struct V_101 * V_102 = NULL ;
struct V_101 * V_103 ;
struct V_3 * V_4 ;
struct V_89 * V_104 ;
struct V_98 * V_105 ;
unsigned int V_106 = 0 ;
unsigned int V_67 ;
int V_107 , V_39 ;
F_45 (dev->of_node, np) {
if ( F_46 ( V_108 , V_103 ) ) {
V_102 = V_103 ;
break;
}
}
if ( ! V_102 )
return - V_109 ;
V_4 = V_6 -> V_9 -> V_58 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 -> V_69 ; ++ V_67 , ++ V_4 ) {
if ( V_4 -> V_70 != V_110 )
continue;
V_4 -> V_49 = F_24 ( V_4 -> V_72 ,
V_4 -> V_73 , & V_111 , V_4 ) ;
if ( ! V_4 -> V_49 ) {
F_21 ( V_65 , L_8 ) ;
return - V_68 ;
}
if ( ! F_47 ( V_4 -> V_72 , L_9 , NULL ) ) {
V_4 -> V_70 = V_112 ;
++ V_106 ;
continue;
}
V_104 = F_25 ( V_65 , V_4 -> V_73
* sizeof( * V_104 ) , V_78 ) ;
if ( ! V_104 ) {
F_21 ( V_65 , L_10 ) ;
return - V_79 ;
}
for ( V_107 = 0 ; V_107 < V_4 -> V_73 ; ++ V_107 ) {
V_39 = F_48 ( V_4 -> V_72 , V_107 ) ;
if ( ! V_39 ) {
F_21 ( V_65 , L_11 ,
V_4 -> V_113 , V_107 ) ;
continue;
}
V_104 [ V_107 ] . V_39 = V_107 ;
V_104 [ V_107 ] . V_4 = V_4 ;
F_49 ( V_39 , & V_104 [ V_107 ] ) ;
F_50 ( V_39 , F_34 ) ;
}
}
if ( ! V_106 )
return 0 ;
V_39 = F_48 ( V_102 , 0 ) ;
if ( ! V_39 ) {
F_21 ( V_65 , L_12 ) ;
return 0 ;
}
V_105 = F_25 ( V_65 , sizeof( * V_105 )
+ V_106 * sizeof( struct V_3 * ) , V_78 ) ;
if ( ! V_105 ) {
F_21 ( V_65 , L_13 ) ;
return - V_79 ;
}
F_50 ( V_39 , F_42 ) ;
F_49 ( V_39 , V_105 ) ;
V_4 = V_6 -> V_9 -> V_58 ;
V_107 = 0 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 -> V_69 ; ++ V_67 , ++ V_4 ) {
if ( V_4 -> V_70 != V_112 )
continue;
V_105 -> V_99 [ V_107 ++ ] = V_4 ;
}
V_105 -> V_69 = V_106 ;
return 0 ;
}
static void F_51 (
struct V_5 * V_7 ,
struct V_3 * V_4 )
{
struct V_77 * V_114 = V_4 -> V_76 ;
void T_4 * V_115 = V_7 -> V_13 ;
V_114 -> V_116 = F_3 ( V_115 + V_117
+ V_4 -> V_11 ) ;
V_114 -> V_118 = F_3 ( V_115 + V_119
+ 2 * V_4 -> V_11 ) ;
V_114 -> V_120 = F_3 ( V_115 + V_119
+ 2 * V_4 -> V_11 + 4 ) ;
F_52 ( L_14 , V_4 -> V_113 , V_114 -> V_116 ) ;
F_52 ( L_15 , V_4 -> V_113 , V_114 -> V_118 ) ;
F_52 ( L_16 , V_4 -> V_113 , V_114 -> V_120 ) ;
}
static void F_53 ( struct V_5 * V_7 )
{
struct V_19 * V_9 = V_7 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_58 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_9 -> V_69 ; ++ V_67 , ++ V_4 )
if ( V_4 -> V_70 == V_71 )
F_51 ( V_7 , V_4 ) ;
}
static void F_54 (
struct V_5 * V_7 ,
struct V_3 * V_4 )
{
struct V_77 * V_114 = V_4 -> V_76 ;
void T_4 * V_115 = V_7 -> V_13 ;
F_52 ( L_17 , V_4 -> V_113 ,
F_3 ( V_115 + V_117
+ V_4 -> V_11 ) , V_114 -> V_116 ) ;
F_52 ( L_18 , V_4 -> V_113 ,
F_3 ( V_115 + V_119
+ 2 * V_4 -> V_11 ) , V_114 -> V_118 ) ;
F_52 ( L_19 , V_4 -> V_113 ,
F_3 ( V_115 + V_119
+ 2 * V_4 -> V_11 + 4 ) , V_114 -> V_120 ) ;
F_4 ( V_114 -> V_116 , V_115 + V_117
+ V_4 -> V_11 ) ;
F_4 ( V_114 -> V_118 , V_115 + V_119
+ 2 * V_4 -> V_11 ) ;
F_4 ( V_114 -> V_120 , V_115 + V_119
+ 2 * V_4 -> V_11 + 4 ) ;
}
static void F_55 ( struct V_5 * V_7 )
{
struct V_19 * V_9 = V_7 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_58 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_9 -> V_69 ; ++ V_67 , ++ V_4 )
if ( V_4 -> V_70 == V_71 )
F_54 ( V_7 , V_4 ) ;
}
