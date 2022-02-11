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
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_17 * V_9 = V_6 -> V_9 ;
unsigned int V_18 = V_2 -> V_14 ;
unsigned int V_19 = V_20 * V_18 ;
unsigned int V_21 , V_22 ;
unsigned long V_23 = V_9 -> V_24 + V_4 -> V_11 ;
unsigned int V_12 ;
switch ( type ) {
case V_25 :
V_22 = V_26 ;
break;
case V_27 :
V_22 = V_28 ;
break;
case V_29 :
V_22 = V_30 ;
break;
case V_31 :
V_22 = V_32 ;
break;
case V_33 :
V_22 = V_34 ;
break;
default:
F_8 ( L_1 ) ;
return - V_35 ;
}
if ( type & V_29 )
F_9 ( V_2 -> V_36 , V_37 ) ;
else
F_9 ( V_2 -> V_36 , V_38 ) ;
V_21 = F_3 ( V_6 -> V_13 + V_23 ) ;
V_21 &= ~ ( V_39 << V_19 ) ;
V_21 |= V_22 << V_19 ;
F_4 ( V_21 , V_6 -> V_13 + V_23 ) ;
V_23 = V_4 -> V_40 ;
V_19 = V_18 * V_4 -> V_41 ;
V_12 = ( 1 << V_4 -> V_41 ) - 1 ;
V_21 = F_3 ( V_6 -> V_13 + V_23 ) ;
V_21 &= ~ ( V_12 << V_19 ) ;
V_21 |= V_42 << V_19 ;
F_4 ( V_21 , V_6 -> V_13 + V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_43 * V_44 , unsigned int V_45 ,
T_1 V_46 )
{
struct V_3 * V_47 = V_44 -> V_48 ;
F_11 ( V_45 , V_47 ) ;
F_12 ( V_45 , & V_49 ,
V_38 ) ;
F_13 ( V_45 , V_50 ) ;
return 0 ;
}
static T_2 F_14 ( int V_36 , void * V_51 )
{
struct V_5 * V_6 = V_51 ;
struct V_17 * V_9 = V_6 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_52 ;
unsigned int V_53 , V_54 , V_18 , V_45 ;
V_53 = F_3 ( V_6 -> V_13 + V_9 -> V_53 ) ;
V_54 = F_15 ( V_53 ) ;
V_18 = V_53 & V_55 ;
if ( ! V_54 )
return V_56 ;
V_4 += ( V_54 - 1 ) ;
V_45 = F_16 ( V_4 -> V_43 , V_18 ) ;
if ( ! V_45 )
return V_57 ;
F_17 ( V_45 ) ;
return V_56 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_58 * V_59 = V_6 -> V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
if ( ! V_6 -> V_36 ) {
F_19 ( V_59 , L_2 ) ;
return - V_35 ;
}
V_60 = F_20 ( V_59 , V_6 -> V_36 , F_14 ,
0 , F_21 ( V_59 ) , V_6 ) ;
if ( V_60 ) {
F_19 ( V_59 , L_3 ) ;
return - V_62 ;
}
V_4 = V_6 -> V_9 -> V_52 ;
for ( V_61 = 0 ; V_61 < V_6 -> V_9 -> V_63 ; ++ V_61 , ++ V_4 ) {
if ( V_4 -> V_64 != V_65 )
continue;
V_4 -> V_43 = F_22 ( V_4 -> V_66 ,
V_4 -> V_67 , & V_68 , V_4 ) ;
if ( ! V_4 -> V_43 ) {
F_19 ( V_59 , L_4 ) ;
return - V_62 ;
}
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_47 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_47 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_69 + V_47 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 &= ~ ( 1 << V_2 -> V_14 ) ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_47 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_47 -> V_7 ;
unsigned long V_8 = V_6 -> V_9 -> V_69 + V_47 -> V_11 ;
unsigned long V_12 ;
V_12 = F_3 ( V_6 -> V_13 + V_8 ) ;
V_12 |= 1 << V_2 -> V_14 ;
F_4 ( V_12 , V_6 -> V_13 + V_8 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_47 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_47 -> V_7 ;
unsigned long V_70 = V_6 -> V_9 -> V_71 + V_47 -> V_11 ;
F_4 ( 1 << V_2 -> V_14 , V_6 -> V_13 + V_70 ) ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_18 = V_2 -> V_14 ;
unsigned long V_23 = V_6 -> V_9 -> V_72 + V_4 -> V_11 ;
unsigned long V_19 = V_20 * V_18 ;
unsigned long V_21 , V_22 ;
unsigned int V_12 ;
switch ( type ) {
case V_25 :
V_22 = V_26 ;
break;
case V_27 :
V_22 = V_28 ;
break;
case V_29 :
V_22 = V_30 ;
break;
case V_31 :
V_22 = V_32 ;
break;
case V_33 :
V_22 = V_34 ;
break;
default:
F_8 ( L_1 ) ;
return - V_35 ;
}
if ( type & V_29 )
F_9 ( V_2 -> V_36 , V_37 ) ;
else
F_9 ( V_2 -> V_36 , V_38 ) ;
V_21 = F_3 ( V_6 -> V_13 + V_23 ) ;
V_21 &= ~ ( V_39 << V_19 ) ;
V_21 |= V_22 << V_19 ;
F_4 ( V_21 , V_6 -> V_13 + V_23 ) ;
V_23 = V_4 -> V_40 ;
V_19 = V_18 * V_4 -> V_41 ;
V_12 = ( 1 << V_4 -> V_41 ) - 1 ;
V_21 = F_3 ( V_6 -> V_13 + V_23 ) ;
V_21 &= ~ ( V_12 << V_19 ) ;
V_21 |= V_42 << V_19 ;
F_4 ( V_21 , V_6 -> V_13 + V_23 ) ;
return 0 ;
}
static void F_27 ( unsigned int V_36 , struct V_73 * V_74 )
{
struct V_75 * V_76 = F_28 ( V_36 ) ;
struct V_3 * V_4 = V_76 -> V_4 ;
struct V_77 * V_78 = F_29 ( V_36 ) ;
int V_79 ;
F_30 ( V_78 , V_74 ) ;
V_78 -> V_80 ( & V_74 -> V_1 ) ;
if ( V_78 -> V_81 )
V_78 -> V_81 ( & V_74 -> V_1 ) ;
V_79 = F_16 ( V_4 -> V_43 , V_76 -> V_36 ) ;
F_17 ( V_79 ) ;
V_78 -> V_82 ( & V_74 -> V_1 ) ;
F_31 ( V_78 , V_74 ) ;
}
static inline void F_32 ( unsigned long V_70 ,
struct V_43 * V_83 )
{
unsigned int V_36 ;
while ( V_70 ) {
V_36 = F_33 ( V_70 ) - 1 ;
F_17 ( F_34 ( V_83 , V_36 ) ) ;
V_70 &= ~ ( 1 << V_36 ) ;
}
}
static void F_35 ( unsigned int V_36 , struct V_73 * V_74 )
{
struct V_77 * V_78 = F_29 ( V_36 ) ;
struct V_84 * V_76 = F_28 ( V_36 ) ;
struct V_5 * V_6 = V_76 -> V_85 [ 0 ] -> V_7 ;
struct V_17 * V_9 = V_6 -> V_9 ;
unsigned long V_70 ;
unsigned long V_12 ;
int V_61 ;
F_30 ( V_78 , V_74 ) ;
for ( V_61 = 0 ; V_61 < V_76 -> V_63 ; ++ V_61 ) {
struct V_3 * V_47 = V_76 -> V_85 [ V_61 ] ;
V_70 = F_3 ( V_6 -> V_13 + V_9 -> V_71 + V_47 -> V_11 ) ;
V_12 = F_3 ( V_6 -> V_13 + V_9 -> V_69 + V_47 -> V_11 ) ;
F_32 ( V_70 & ~ V_12 , V_47 -> V_43 ) ;
}
F_31 ( V_78 , V_74 ) ;
}
static int F_36 ( struct V_43 * V_44 , unsigned int V_45 ,
T_1 V_46 )
{
F_12 ( V_45 , & V_86 , V_38 ) ;
F_11 ( V_45 , V_44 -> V_48 ) ;
F_13 ( V_45 , V_50 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_87 * V_88 = NULL ;
struct V_87 * V_89 ;
struct V_3 * V_4 ;
struct V_75 * V_90 ;
struct V_84 * V_91 ;
unsigned int V_92 = 0 ;
unsigned int V_61 ;
int V_93 , V_36 ;
F_38 (dev->of_node, np) {
if ( F_39 ( V_94 , V_89 ) ) {
V_88 = V_89 ;
break;
}
}
if ( ! V_88 )
return - V_95 ;
V_4 = V_6 -> V_9 -> V_52 ;
for ( V_61 = 0 ; V_61 < V_6 -> V_9 -> V_63 ; ++ V_61 , ++ V_4 ) {
if ( V_4 -> V_64 != V_96 )
continue;
V_4 -> V_43 = F_22 ( V_4 -> V_66 ,
V_4 -> V_67 , & V_97 , V_4 ) ;
if ( ! V_4 -> V_43 ) {
F_19 ( V_59 , L_5 ) ;
return - V_62 ;
}
if ( ! F_40 ( V_4 -> V_66 , L_6 , NULL ) ) {
V_4 -> V_64 = V_98 ;
++ V_92 ;
continue;
}
V_90 = F_41 ( V_59 , V_4 -> V_67
* sizeof( * V_90 ) , V_99 ) ;
if ( ! V_90 ) {
F_19 ( V_59 , L_7 ) ;
return - V_100 ;
}
for ( V_93 = 0 ; V_93 < V_4 -> V_67 ; ++ V_93 ) {
V_36 = F_42 ( V_4 -> V_66 , V_93 ) ;
if ( ! V_36 ) {
F_19 ( V_59 , L_8 ,
V_4 -> V_101 , V_93 ) ;
continue;
}
V_90 [ V_93 ] . V_36 = V_93 ;
V_90 [ V_93 ] . V_4 = V_4 ;
F_43 ( V_36 , & V_90 [ V_93 ] ) ;
F_44 ( V_36 , F_27 ) ;
}
}
if ( ! V_92 )
return 0 ;
V_36 = F_42 ( V_88 , 0 ) ;
if ( ! V_36 ) {
F_19 ( V_59 , L_9 ) ;
return 0 ;
}
V_91 = F_41 ( V_59 , sizeof( * V_91 )
+ V_92 * sizeof( struct V_3 * ) , V_99 ) ;
if ( ! V_91 ) {
F_19 ( V_59 , L_10 ) ;
return - V_100 ;
}
F_44 ( V_36 , F_35 ) ;
F_43 ( V_36 , V_91 ) ;
V_4 = V_6 -> V_9 -> V_52 ;
V_93 = 0 ;
for ( V_61 = 0 ; V_61 < V_6 -> V_9 -> V_63 ; ++ V_61 , ++ V_4 ) {
if ( V_4 -> V_64 != V_98 )
continue;
V_91 -> V_85 [ V_93 ++ ] = V_4 ;
}
V_91 -> V_63 = V_92 ;
return 0 ;
}
