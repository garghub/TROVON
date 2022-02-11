static int F_1 ( unsigned int type )
{
switch ( type ) {
case V_1 :
return V_2 ;
break;
case V_3 :
return V_4 ;
break;
case V_5 :
return V_6 ;
break;
case V_7 :
return V_8 ;
break;
case V_9 :
return V_10 ;
break;
default:
return - V_11 ;
}
}
static void F_2 ( unsigned int V_12 , unsigned int type )
{
if ( type & V_5 )
F_3 ( V_12 , V_13 ) ;
else
F_3 ( V_12 , V_14 ) ;
}
static void F_4 ( struct V_15 * V_16 ,
struct V_17 * V_18 , int V_19 )
{
const struct V_20 * V_21 = V_18 -> type ;
unsigned long V_22 ;
void T_1 * V_23 ;
T_2 V_24 ;
T_3 V_25 ;
T_3 V_26 ;
V_23 = V_16 -> V_27 + V_18 -> V_28 ;
V_24 = V_19 * V_21 -> V_29 [ V_30 ] ;
V_25 = ( 1 << V_21 -> V_29 [ V_30 ] ) - 1 ;
F_5 ( & V_18 -> V_31 , V_22 ) ;
V_26 = F_6 ( V_23 ) ;
V_26 &= ~ ( V_25 << V_24 ) ;
V_26 |= V_18 -> V_32 << V_24 ;
F_7 ( V_26 , V_23 ) ;
F_8 ( & V_18 -> V_31 , V_22 ) ;
}
static int F_9 ( struct V_33 * V_34 , unsigned int type )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
int V_36 = V_18 -> V_37 + V_34 -> V_38 ;
void T_1 * V_23 ;
int V_39 ;
T_2 V_24 ;
T_3 V_26 ;
V_39 = F_1 ( type ) ;
if ( V_39 < 0 ) {
F_11 ( V_16 -> V_40 , L_1 ) ;
return - V_11 ;
}
F_2 ( V_34 -> V_12 , type ) ;
V_23 = V_16 -> V_27 + F_12 ( V_36 ) ;
V_24 = F_13 ( V_36 ) ;
V_26 = F_6 ( V_23 ) ;
V_26 &= ~ ( V_41 << V_24 ) ;
V_26 |= V_39 << V_24 ;
F_7 ( V_26 , V_23 ) ;
F_4 ( V_16 , V_18 , V_34 -> V_38 ) ;
return 0 ;
}
static void F_14 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_34 -> V_38 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_52 ( F_16 ( V_48 ) ) ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_34 -> V_38 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_53 ( F_16 ( V_48 ) ) ;
}
static void F_18 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_34 -> V_38 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_54 ( F_16 ( V_48 ) ) ;
}
static void F_19 ( unsigned int V_12 , struct V_55 * V_56 )
{
struct V_33 * V_34 = F_20 ( V_56 ) ;
struct V_46 * V_47 = F_21 ( V_12 ) ;
unsigned int V_57 ;
V_57 = F_22 ( V_47 -> V_58 [ V_34 -> V_38 ] , V_34 -> V_38 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
}
static void F_25 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned long V_59 = 1UL << V_34 -> V_38 ;
F_7 ( V_59 , V_16 -> V_27 + V_60 ) ;
}
static void F_26 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned long V_25 ;
V_25 = F_6 ( V_16 -> V_27 + V_61 ) ;
V_25 |= ( 1UL << V_34 -> V_38 ) ;
F_7 ( V_25 , V_16 -> V_27 + V_61 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned long V_25 ;
V_25 = F_6 ( V_16 -> V_27 + V_61 ) ;
V_25 &= ~ ( 1UL << V_34 -> V_38 ) ;
F_7 ( V_25 , V_16 -> V_27 + V_61 ) ;
}
static void F_28 ( unsigned int V_12 , struct V_55 * V_56 )
{
struct V_50 * V_62 = F_15 ( V_12 ) ;
struct V_33 * V_34 = F_20 ( V_56 ) ;
struct V_46 * V_47 = F_21 ( V_12 ) ;
unsigned int V_57 ;
F_29 ( V_62 , V_56 ) ;
V_57 = F_22 ( V_47 -> V_58 [ V_34 -> V_38 ] , V_34 -> V_38 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
F_30 ( V_62 , V_56 ) ;
}
static void F_31 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned char V_36 = V_18 -> V_37 + V_34 -> V_38 ;
F_7 ( 1UL << V_36 , V_16 -> V_27 + V_60 ) ;
}
static void F_32 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned char V_36 = V_18 -> V_37 + V_34 -> V_38 ;
unsigned long V_25 ;
V_25 = F_6 ( V_16 -> V_27 + V_61 ) ;
V_25 |= ( 1UL << V_36 ) ;
F_7 ( V_25 , V_16 -> V_27 + V_61 ) ;
}
static void F_33 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_34 ) ;
struct V_15 * V_16 = V_18 -> V_35 ;
unsigned char V_36 = V_18 -> V_37 + V_34 -> V_38 ;
unsigned long V_25 ;
V_25 = F_6 ( V_16 -> V_27 + V_61 ) ;
V_25 &= ~ ( 1UL << V_36 ) ;
F_7 ( V_25 , V_16 -> V_27 + V_61 ) ;
}
static inline void F_34 ( unsigned int V_12 , struct V_55 * V_56 ,
T_3 V_63 , T_3 V_64 )
{
struct V_50 * V_62 = F_15 ( V_12 ) ;
struct V_46 * V_34 = F_21 ( V_12 ) ;
struct V_15 * V_16 = V_34 -> V_35 ;
unsigned int V_65 , V_25 ;
F_29 ( V_62 , V_56 ) ;
V_65 = F_6 ( V_16 -> V_27 + V_60 ) ;
V_25 = F_6 ( V_16 -> V_27 + V_61 ) ;
V_65 &= ~ V_25 ;
V_65 &= V_64 ;
while ( V_65 ) {
unsigned int V_57 ;
V_12 = F_35 ( V_65 ) ;
V_65 &= ~ ( 1 << V_12 ) ;
V_57 = F_22 ( V_34 -> V_58 [ V_12 ] , V_12 - V_63 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
}
F_30 ( V_62 , V_56 ) ;
}
static void F_36 ( unsigned int V_12 , struct V_55 * V_56 )
{
F_34 ( V_12 , V_56 , 0 , 0xf0 ) ;
}
static void F_37 ( unsigned int V_12 , struct V_55 * V_56 )
{
F_34 ( V_12 , V_56 , 8 , 0xffff00 ) ;
}
static int F_38 ( struct V_44 * V_66 , unsigned int V_57 ,
T_4 V_67 )
{
struct V_42 * V_43 = V_66 -> V_45 ;
struct V_17 * V_18 = V_43 -> V_18 ;
if ( ! ( V_18 -> V_68 & ( 1 << ( V_18 -> V_37 + V_67 ) ) ) )
return - V_11 ;
if ( V_67 <= 3 ) {
if ( V_43 -> V_69 )
F_39 ( V_57 , & V_70 ,
V_13 ) ;
else
F_39 ( V_57 , & V_71 ,
V_13 ) ;
} else {
F_39 ( V_57 , & V_72 ,
V_13 ) ;
}
F_40 ( V_57 , V_18 ) ;
F_41 ( V_57 , V_73 ) ;
return 0 ;
}
static int F_42 ( struct V_44 * V_66 , unsigned int V_57 ,
T_4 V_67 )
{
struct V_42 * V_43 = V_66 -> V_45 ;
struct V_17 * V_18 = V_43 -> V_18 ;
if ( ! ( V_18 -> V_68 & ( 1 << ( V_18 -> V_37 + V_67 ) ) ) )
return - V_11 ;
F_39 ( V_57 , & V_72 , V_13 ) ;
F_40 ( V_57 , V_18 ) ;
F_41 ( V_57 , V_73 ) ;
return 0 ;
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_74 * V_40 = V_16 -> V_40 ;
const struct V_75 * V_76 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_79 ;
struct V_17 * V_18 ;
struct V_46 * V_47 ;
const struct V_80 * V_81 ;
unsigned int V_82 ;
bool V_69 ;
T_5 * V_83 ;
F_44 (dev->of_node, np) {
V_76 = F_45 ( V_84 , V_79 ) ;
if ( V_76 ) {
V_78 = V_79 ;
V_69 = ( bool ) V_76 -> V_34 ;
break;
}
}
if ( ! V_78 )
return - V_85 ;
V_47 = F_46 ( V_40 , sizeof( * V_47 ) , V_86 ) ;
if ( ! V_47 )
return - V_87 ;
V_47 -> V_35 = V_16 ;
V_83 = V_69 ? V_88
: V_89 ;
for ( V_82 = 0 ; V_82 < V_90 ; ++ V_82 ) {
unsigned int V_12 ;
V_12 = F_47 ( V_78 , V_82 ) ;
if ( ! V_12 ) {
F_11 ( V_40 , L_2 , V_82 ) ;
return - V_91 ;
}
V_47 -> V_49 [ V_82 ] = V_12 ;
F_48 ( V_12 , V_83 [ V_82 ] , V_47 ) ;
}
V_18 = V_16 -> V_92 ;
for ( V_82 = 0 ; V_82 < V_16 -> V_93 ; ++ V_82 , ++ V_18 ) {
struct V_42 * V_43 ;
unsigned int V_25 ;
unsigned int V_12 ;
unsigned int V_19 ;
if ( V_18 -> V_94 != V_95 )
continue;
V_43 = F_46 ( V_40 , sizeof( * V_43 ) , V_86 ) ;
if ( ! V_43 )
return - V_87 ;
V_43 -> V_18 = V_18 ;
V_43 -> V_47 = V_47 ;
V_43 -> V_69 = V_69 ;
V_81 = ( V_18 -> V_37 == 0 ) ? & V_96
: & V_97 ;
V_18 -> V_44 = F_49 ( V_18 -> V_98 ,
V_18 -> V_99 , V_81 , V_43 ) ;
if ( ! V_18 -> V_44 ) {
F_11 ( V_40 , L_3 ) ;
return - V_91 ;
}
V_12 = V_18 -> V_37 ;
V_25 = V_18 -> V_68 ;
for ( V_19 = 0 ; V_25 ; ++ V_19 , V_25 >>= 1 ) {
if ( V_12 >= V_100 )
break;
if ( ! ( V_25 & 1 ) )
continue;
V_47 -> V_58 [ V_12 ] = V_18 -> V_44 ;
++ V_12 ;
}
}
return 0 ;
}
