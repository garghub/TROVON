static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_10 + V_4 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
F_3 ( & V_4 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_6 -> V_15 + V_8 ) ;
V_12 |= 1 << V_2 -> V_16 ;
F_5 ( V_12 , V_6 -> V_15 + V_8 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_17 = V_6 -> V_9 -> V_18 + V_4 -> V_11 ;
F_5 ( 1 << V_2 -> V_16 , V_6 -> V_15 + V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_10 + V_4 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
if ( F_9 ( V_2 ) & V_19 )
F_7 ( V_2 ) ;
F_3 ( & V_4 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_6 -> V_15 + V_8 ) ;
V_12 &= ~ ( 1 << V_2 -> V_16 ) ;
F_5 ( V_12 , V_6 -> V_15 + V_8 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_4 -> type ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_22 * V_9 = V_6 -> V_9 ;
unsigned int V_23 = V_2 -> V_16 ;
unsigned int V_24 = V_25 * V_23 ;
unsigned int V_26 , V_27 ;
unsigned long V_28 = V_9 -> V_29 + V_4 -> V_11 ;
unsigned long V_13 ;
unsigned int V_12 ;
switch ( type ) {
case V_30 :
V_27 = V_31 ;
break;
case V_32 :
V_27 = V_33 ;
break;
case V_34 :
V_27 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
break;
case V_38 :
V_27 = V_39 ;
break;
default:
F_11 ( L_1 ) ;
return - V_40 ;
}
if ( type & V_34 )
F_12 ( V_2 -> V_41 , V_42 ) ;
else
F_12 ( V_2 -> V_41 , V_43 ) ;
V_26 = F_4 ( V_6 -> V_15 + V_28 ) ;
V_26 &= ~ ( V_44 << V_24 ) ;
V_26 |= V_27 << V_24 ;
F_5 ( V_26 , V_6 -> V_15 + V_28 ) ;
V_28 = V_4 -> V_45 + V_21 -> V_46 [ V_47 ] ;
V_24 = V_23 * V_21 -> V_48 [ V_47 ] ;
V_12 = ( 1 << V_21 -> V_48 [ V_47 ] ) - 1 ;
F_3 ( & V_4 -> V_14 , V_13 ) ;
V_26 = F_4 ( V_6 -> V_15 + V_28 ) ;
V_26 &= ~ ( V_12 << V_24 ) ;
V_26 |= V_49 << V_24 ;
F_5 ( V_26 , V_6 -> V_15 + V_28 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_50 * V_51 , unsigned int V_52 ,
T_1 V_53 )
{
struct V_3 * V_54 = V_51 -> V_55 ;
F_14 ( V_52 , V_54 ) ;
F_15 ( V_52 , & V_56 ,
V_43 ) ;
F_16 ( V_52 , V_57 ) ;
return 0 ;
}
static T_2 F_17 ( int V_41 , void * V_58 )
{
struct V_5 * V_6 = V_58 ;
struct V_22 * V_9 = V_6 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_59 ;
unsigned int V_60 , V_61 , V_23 , V_52 ;
V_60 = F_4 ( V_6 -> V_15 + V_9 -> V_60 ) ;
V_61 = F_18 ( V_60 ) ;
V_23 = V_60 & V_62 ;
if ( ! V_61 )
return V_63 ;
V_4 += ( V_61 - 1 ) ;
V_52 = F_19 ( V_4 -> V_50 , V_23 ) ;
if ( ! V_52 )
return V_64 ;
F_20 ( V_52 ) ;
return V_63 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_65 * V_66 = V_6 -> V_66 ;
int V_67 ;
int V_68 ;
if ( ! V_6 -> V_41 ) {
F_22 ( V_66 , L_2 ) ;
return - V_40 ;
}
V_67 = F_23 ( V_66 , V_6 -> V_41 , F_17 ,
0 , F_24 ( V_66 ) , V_6 ) ;
if ( V_67 ) {
F_22 ( V_66 , L_3 ) ;
return - V_69 ;
}
V_4 = V_6 -> V_9 -> V_59 ;
for ( V_68 = 0 ; V_68 < V_6 -> V_9 -> V_70 ; ++ V_68 , ++ V_4 ) {
if ( V_4 -> V_71 != V_72 )
continue;
V_4 -> V_50 = F_25 ( V_4 -> V_73 ,
V_4 -> V_74 , & V_75 , V_4 ) ;
if ( ! V_4 -> V_50 ) {
F_22 ( V_66 , L_4 ) ;
V_67 = - V_69 ;
goto V_76;
}
V_4 -> V_77 = F_26 ( V_6 -> V_66 ,
sizeof( struct V_78 ) , V_79 ) ;
if ( ! V_4 -> V_77 ) {
F_27 ( V_4 -> V_50 ) ;
V_67 = - V_80 ;
goto V_76;
}
}
return 0 ;
V_76:
for ( -- V_68 , -- V_4 ; V_68 >= 0 ; -- V_68 , -- V_4 ) {
if ( V_4 -> V_71 != V_72 )
continue;
F_27 ( V_4 -> V_50 ) ;
}
return V_67 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_54 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_81 + V_54 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
F_3 ( & V_54 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_6 -> V_15 + V_8 ) ;
V_12 |= 1 << V_2 -> V_16 ;
F_5 ( V_12 , V_6 -> V_15 + V_8 ) ;
F_6 ( & V_54 -> V_14 , V_13 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_54 -> V_7 ;
unsigned long V_82 = V_6 -> V_9 -> V_83 + V_54 -> V_11 ;
F_5 ( 1 << V_2 -> V_16 , V_6 -> V_15 + V_82 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_54 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_54 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_81 + V_54 -> V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
if ( F_9 ( V_2 ) & V_19 )
F_29 ( V_2 ) ;
F_3 ( & V_54 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_6 -> V_15 + V_8 ) ;
V_12 &= ~ ( 1 << V_2 -> V_16 ) ;
F_5 ( V_12 , V_6 -> V_15 + V_8 ) ;
F_6 ( & V_54 -> V_14 , V_13 ) ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_4 -> type ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_23 = V_2 -> V_16 ;
unsigned long V_28 = V_6 -> V_9 -> V_84 + V_4 -> V_11 ;
unsigned long V_24 = V_25 * V_23 ;
unsigned long V_26 , V_27 ;
unsigned long V_13 ;
unsigned int V_12 ;
switch ( type ) {
case V_30 :
V_27 = V_31 ;
break;
case V_32 :
V_27 = V_33 ;
break;
case V_34 :
V_27 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
break;
case V_38 :
V_27 = V_39 ;
break;
default:
F_11 ( L_1 ) ;
return - V_40 ;
}
if ( type & V_34 )
F_12 ( V_2 -> V_41 , V_42 ) ;
else
F_12 ( V_2 -> V_41 , V_43 ) ;
V_26 = F_4 ( V_6 -> V_15 + V_28 ) ;
V_26 &= ~ ( V_44 << V_24 ) ;
V_26 |= V_27 << V_24 ;
F_5 ( V_26 , V_6 -> V_15 + V_28 ) ;
V_28 = V_4 -> V_45 + V_21 -> V_46 [ V_47 ] ;
V_24 = V_23 * V_21 -> V_48 [ V_47 ] ;
V_12 = ( 1 << V_21 -> V_48 [ V_47 ] ) - 1 ;
F_3 ( & V_4 -> V_14 , V_13 ) ;
V_26 = F_4 ( V_6 -> V_15 + V_28 ) ;
V_26 &= ~ ( V_12 << V_24 ) ;
V_26 |= V_49 << V_24 ;
F_5 ( V_26 , V_6 -> V_15 + V_28 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
return 0 ;
}
T_3 F_32 ( void )
{
return V_85 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_87 = 1UL << ( 2 * V_4 -> V_11 + V_2 -> V_16 ) ;
F_34 ( L_5 , V_86 ? L_6 : L_7 , V_2 -> V_41 ) ;
if ( ! V_86 )
V_85 |= V_87 ;
else
V_85 &= ~ V_87 ;
return 0 ;
}
static void F_35 ( unsigned int V_41 , struct V_88 * V_89 )
{
struct V_90 * V_91 = F_36 ( V_41 ) ;
struct V_3 * V_4 = V_91 -> V_4 ;
struct V_92 * V_93 = F_37 ( V_41 ) ;
int V_94 ;
F_38 ( V_93 , V_89 ) ;
V_93 -> V_95 ( & V_89 -> V_1 ) ;
if ( V_93 -> V_96 )
V_93 -> V_96 ( & V_89 -> V_1 ) ;
V_94 = F_19 ( V_4 -> V_50 , V_91 -> V_41 ) ;
F_20 ( V_94 ) ;
V_93 -> V_97 ( & V_89 -> V_1 ) ;
F_39 ( V_93 , V_89 ) ;
}
static inline void F_40 ( unsigned long V_82 ,
struct V_50 * V_98 )
{
unsigned int V_41 ;
while ( V_82 ) {
V_41 = F_41 ( V_82 ) - 1 ;
F_20 ( F_42 ( V_98 , V_41 ) ) ;
V_82 &= ~ ( 1 << V_41 ) ;
}
}
static void F_43 ( unsigned int V_41 , struct V_88 * V_89 )
{
struct V_92 * V_93 = F_37 ( V_41 ) ;
struct V_99 * V_91 = F_36 ( V_41 ) ;
struct V_5 * V_6 = V_91 -> V_100 [ 0 ] -> V_7 ;
struct V_22 * V_9 = V_6 -> V_9 ;
unsigned long V_82 ;
unsigned long V_12 ;
int V_68 ;
F_38 ( V_93 , V_89 ) ;
for ( V_68 = 0 ; V_68 < V_91 -> V_70 ; ++ V_68 ) {
struct V_3 * V_54 = V_91 -> V_100 [ V_68 ] ;
V_82 = F_4 ( V_6 -> V_15 + V_9 -> V_83 + V_54 -> V_11 ) ;
V_12 = F_4 ( V_6 -> V_15 + V_9 -> V_81 + V_54 -> V_11 ) ;
F_40 ( V_82 & ~ V_12 , V_54 -> V_50 ) ;
}
F_39 ( V_93 , V_89 ) ;
}
static int F_44 ( struct V_50 * V_51 , unsigned int V_52 ,
T_1 V_53 )
{
F_15 ( V_52 , & V_101 , V_43 ) ;
F_14 ( V_52 , V_51 -> V_55 ) ;
F_16 ( V_52 , V_57 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_65 * V_66 = V_6 -> V_66 ;
struct V_102 * V_103 = NULL ;
struct V_102 * V_104 ;
struct V_3 * V_4 ;
struct V_90 * V_105 ;
struct V_99 * V_106 ;
unsigned int V_107 = 0 ;
unsigned int V_68 ;
int V_108 , V_41 ;
F_46 (dev->of_node, np) {
if ( F_47 ( V_109 , V_104 ) ) {
V_103 = V_104 ;
break;
}
}
if ( ! V_103 )
return - V_110 ;
V_4 = V_6 -> V_9 -> V_59 ;
for ( V_68 = 0 ; V_68 < V_6 -> V_9 -> V_70 ; ++ V_68 , ++ V_4 ) {
if ( V_4 -> V_71 != V_111 )
continue;
V_4 -> V_50 = F_25 ( V_4 -> V_73 ,
V_4 -> V_74 , & V_112 , V_4 ) ;
if ( ! V_4 -> V_50 ) {
F_22 ( V_66 , L_8 ) ;
return - V_69 ;
}
if ( ! F_48 ( V_4 -> V_73 , L_9 , NULL ) ) {
V_4 -> V_71 = V_113 ;
++ V_107 ;
continue;
}
V_105 = F_26 ( V_66 , V_4 -> V_74
* sizeof( * V_105 ) , V_79 ) ;
if ( ! V_105 ) {
F_22 ( V_66 , L_10 ) ;
return - V_80 ;
}
for ( V_108 = 0 ; V_108 < V_4 -> V_74 ; ++ V_108 ) {
V_41 = F_49 ( V_4 -> V_73 , V_108 ) ;
if ( ! V_41 ) {
F_22 ( V_66 , L_11 ,
V_4 -> V_114 , V_108 ) ;
continue;
}
V_105 [ V_108 ] . V_41 = V_108 ;
V_105 [ V_108 ] . V_4 = V_4 ;
F_50 ( V_41 , & V_105 [ V_108 ] ) ;
F_51 ( V_41 , F_35 ) ;
}
}
if ( ! V_107 )
return 0 ;
V_41 = F_49 ( V_103 , 0 ) ;
if ( ! V_41 ) {
F_22 ( V_66 , L_12 ) ;
return 0 ;
}
V_106 = F_26 ( V_66 , sizeof( * V_106 )
+ V_107 * sizeof( struct V_3 * ) , V_79 ) ;
if ( ! V_106 ) {
F_22 ( V_66 , L_13 ) ;
return - V_80 ;
}
F_51 ( V_41 , F_43 ) ;
F_50 ( V_41 , V_106 ) ;
V_4 = V_6 -> V_9 -> V_59 ;
V_108 = 0 ;
for ( V_68 = 0 ; V_68 < V_6 -> V_9 -> V_70 ; ++ V_68 , ++ V_4 ) {
if ( V_4 -> V_71 != V_113 )
continue;
V_106 -> V_100 [ V_108 ++ ] = V_4 ;
}
V_106 -> V_70 = V_107 ;
return 0 ;
}
static void F_52 (
struct V_5 * V_7 ,
struct V_3 * V_4 )
{
struct V_78 * V_115 = V_4 -> V_77 ;
void T_4 * V_116 = V_7 -> V_15 ;
V_115 -> V_117 = F_4 ( V_116 + V_118
+ V_4 -> V_11 ) ;
V_115 -> V_119 = F_4 ( V_116 + V_120
+ 2 * V_4 -> V_11 ) ;
V_115 -> V_121 = F_4 ( V_116 + V_120
+ 2 * V_4 -> V_11 + 4 ) ;
F_53 ( L_14 , V_4 -> V_114 , V_115 -> V_117 ) ;
F_53 ( L_15 , V_4 -> V_114 , V_115 -> V_119 ) ;
F_53 ( L_16 , V_4 -> V_114 , V_115 -> V_121 ) ;
}
static void F_54 ( struct V_5 * V_7 )
{
struct V_22 * V_9 = V_7 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_59 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_9 -> V_70 ; ++ V_68 , ++ V_4 )
if ( V_4 -> V_71 == V_72 )
F_52 ( V_7 , V_4 ) ;
}
static void F_55 (
struct V_5 * V_7 ,
struct V_3 * V_4 )
{
struct V_78 * V_115 = V_4 -> V_77 ;
void T_4 * V_116 = V_7 -> V_15 ;
F_53 ( L_17 , V_4 -> V_114 ,
F_4 ( V_116 + V_118
+ V_4 -> V_11 ) , V_115 -> V_117 ) ;
F_53 ( L_18 , V_4 -> V_114 ,
F_4 ( V_116 + V_120
+ 2 * V_4 -> V_11 ) , V_115 -> V_119 ) ;
F_53 ( L_19 , V_4 -> V_114 ,
F_4 ( V_116 + V_120
+ 2 * V_4 -> V_11 + 4 ) , V_115 -> V_121 ) ;
F_5 ( V_115 -> V_117 , V_116 + V_118
+ V_4 -> V_11 ) ;
F_5 ( V_115 -> V_119 , V_116 + V_120
+ 2 * V_4 -> V_11 ) ;
F_5 ( V_115 -> V_121 , V_116 + V_120
+ 2 * V_4 -> V_11 + 4 ) ;
}
static void F_56 ( struct V_5 * V_7 )
{
struct V_22 * V_9 = V_7 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_59 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_9 -> V_70 ; ++ V_68 , ++ V_4 )
if ( V_4 -> V_71 == V_72 )
F_55 ( V_7 , V_4 ) ;
}
