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
static void F_2 ( struct V_12 * V_13 , unsigned int type )
{
if ( type & V_5 )
F_3 ( V_13 , V_14 ) ;
else
F_3 ( V_13 , V_15 ) ;
}
static void F_4 ( struct V_16 * V_13 ,
struct V_17 * V_18 , int V_19 )
{
const struct V_20 * V_21 = V_18 -> type ;
unsigned long V_22 ;
void T_1 * V_23 ;
T_2 V_24 ;
T_3 V_25 ;
T_3 V_26 ;
V_23 = V_18 -> V_27 + V_18 -> V_28 ;
V_24 = V_19 * V_21 -> V_29 [ V_30 ] ;
V_25 = ( 1 << V_21 -> V_29 [ V_30 ] ) - 1 ;
F_5 ( & V_18 -> V_31 , V_22 ) ;
V_26 = F_6 ( V_23 ) ;
V_26 &= ~ ( V_25 << V_24 ) ;
V_26 |= V_18 -> V_32 << V_24 ;
F_7 ( V_26 , V_23 ) ;
F_8 ( & V_18 -> V_31 , V_22 ) ;
}
static int F_9 ( struct V_12 * V_33 , unsigned int type )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
struct V_16 * V_13 = V_18 -> V_34 ;
int V_35 = V_18 -> V_36 + V_33 -> V_37 ;
void T_1 * V_23 ;
int V_38 ;
T_2 V_24 ;
T_3 V_26 ;
V_38 = F_1 ( type ) ;
if ( V_38 < 0 ) {
F_11 ( V_13 -> V_39 , L_1 ) ;
return - V_11 ;
}
F_2 ( V_33 , type ) ;
V_23 = V_18 -> V_40 + F_12 ( V_35 ) ;
V_24 = F_13 ( V_35 ) ;
V_26 = F_6 ( V_23 ) ;
V_26 &= ~ ( V_41 << V_24 ) ;
V_26 |= V_38 << V_24 ;
F_7 ( V_26 , V_23 ) ;
F_4 ( V_13 , V_18 , V_33 -> V_37 ) ;
return 0 ;
}
static void F_14 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_33 -> V_37 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_52 ( F_16 ( V_48 ) ) ;
}
static void F_17 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_33 -> V_37 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_53 ( F_16 ( V_48 ) ) ;
}
static void F_18 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
struct V_42 * V_43 = V_18 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
int V_48 = V_47 -> V_49 [ V_33 -> V_37 ] ;
struct V_50 * V_51 = F_15 ( V_48 ) ;
V_51 -> V_54 ( F_16 ( V_48 ) ) ;
}
static void F_19 ( struct V_55 * V_56 )
{
struct V_12 * V_33 = F_20 ( V_56 ) ;
struct V_46 * V_47 = F_21 ( V_56 ) ;
unsigned int V_57 ;
V_57 = F_22 ( V_47 -> V_58 [ V_33 -> V_37 ] , V_33 -> V_37 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
}
static void F_25 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned long V_59 = 1UL << V_33 -> V_37 ;
F_7 ( V_59 , V_18 -> V_40 + V_60 ) ;
}
static void F_26 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned long V_25 ;
V_25 = F_6 ( V_18 -> V_40 + V_61 ) ;
V_25 |= ( 1UL << V_33 -> V_37 ) ;
F_7 ( V_25 , V_18 -> V_40 + V_61 ) ;
}
static void F_27 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned long V_25 ;
V_25 = F_6 ( V_18 -> V_40 + V_61 ) ;
V_25 &= ~ ( 1UL << V_33 -> V_37 ) ;
F_7 ( V_25 , V_18 -> V_40 + V_61 ) ;
}
static void F_28 ( struct V_55 * V_56 )
{
struct V_46 * V_47 = F_21 ( V_56 ) ;
struct V_12 * V_33 = F_20 ( V_56 ) ;
struct V_50 * V_62 = F_29 ( V_33 ) ;
unsigned int V_57 ;
F_30 ( V_62 , V_56 ) ;
V_57 = F_22 ( V_47 -> V_58 [ V_33 -> V_37 ] , V_33 -> V_37 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
F_31 ( V_62 , V_56 ) ;
}
static void F_32 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned char V_35 = V_18 -> V_36 + V_33 -> V_37 ;
F_7 ( 1UL << V_35 , V_18 -> V_40 + V_60 ) ;
}
static void F_33 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned char V_35 = V_18 -> V_36 + V_33 -> V_37 ;
unsigned long V_25 ;
V_25 = F_6 ( V_18 -> V_40 + V_61 ) ;
V_25 |= ( 1UL << V_35 ) ;
F_7 ( V_25 , V_18 -> V_40 + V_61 ) ;
}
static void F_34 ( struct V_12 * V_33 )
{
struct V_17 * V_18 = F_10 ( V_33 ) ;
unsigned char V_35 = V_18 -> V_36 + V_33 -> V_37 ;
unsigned long V_25 ;
V_25 = F_6 ( V_18 -> V_40 + V_61 ) ;
V_25 &= ~ ( 1UL << V_35 ) ;
F_7 ( V_25 , V_18 -> V_40 + V_61 ) ;
}
static inline void F_35 ( struct V_55 * V_56 ,
T_3 V_63 , T_3 V_64 )
{
struct V_46 * V_33 = F_21 ( V_56 ) ;
struct V_50 * V_62 = F_36 ( V_56 ) ;
struct V_12 * V_65 = F_20 ( V_56 ) ;
struct V_17 * V_18 = F_10 ( V_65 ) ;
unsigned int V_66 , V_25 ;
F_30 ( V_62 , V_56 ) ;
V_66 = F_6 ( V_18 -> V_40 + V_60 ) ;
V_25 = F_6 ( V_18 -> V_40 + V_61 ) ;
V_66 &= ~ V_25 ;
V_66 &= V_64 ;
while ( V_66 ) {
unsigned int V_57 , V_67 ;
V_67 = F_37 ( V_66 ) ;
V_66 &= ~ ( 1 << V_67 ) ;
V_57 = F_22 ( V_33 -> V_58 [ V_67 ] , V_67 - V_63 ) ;
F_23 ( ! V_57 ) ;
F_24 ( V_57 ) ;
}
F_31 ( V_62 , V_56 ) ;
}
static void F_38 ( struct V_55 * V_56 )
{
F_35 ( V_56 , 0 , 0xf0 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
F_35 ( V_56 , 8 , 0xffff00 ) ;
}
static int F_40 ( struct V_44 * V_68 , unsigned int V_57 ,
T_4 V_69 )
{
struct V_42 * V_43 = V_68 -> V_45 ;
struct V_17 * V_18 = V_43 -> V_18 ;
if ( ! ( V_18 -> V_70 & ( 1 << ( V_18 -> V_36 + V_69 ) ) ) )
return - V_11 ;
if ( V_69 <= 3 ) {
if ( V_43 -> V_71 )
F_41 ( V_57 , & V_72 ,
V_14 ) ;
else
F_41 ( V_57 , & V_73 ,
V_14 ) ;
} else {
F_41 ( V_57 , & V_74 ,
V_14 ) ;
}
F_42 ( V_57 , V_18 ) ;
return 0 ;
}
static int F_43 ( struct V_44 * V_68 , unsigned int V_57 ,
T_4 V_69 )
{
struct V_42 * V_43 = V_68 -> V_45 ;
struct V_17 * V_18 = V_43 -> V_18 ;
if ( ! ( V_18 -> V_70 & ( 1 << ( V_18 -> V_36 + V_69 ) ) ) )
return - V_11 ;
F_41 ( V_57 , & V_74 , V_14 ) ;
F_42 ( V_57 , V_18 ) ;
return 0 ;
}
static int F_44 ( struct V_16 * V_13 )
{
struct V_75 * V_39 = V_13 -> V_39 ;
const struct V_76 * V_77 ;
struct V_78 * V_79 = NULL ;
struct V_78 * V_80 ;
struct V_17 * V_18 ;
struct V_46 * V_47 ;
const struct V_81 * V_82 ;
unsigned int V_83 ;
bool V_71 ;
T_5 * V_84 ;
F_45 (dev->of_node, np) {
V_77 = F_46 ( V_85 , V_80 ) ;
if ( V_77 ) {
V_79 = V_80 ;
V_71 = ( bool ) V_77 -> V_33 ;
break;
}
}
if ( ! V_79 )
return - V_86 ;
V_47 = F_47 ( V_39 , sizeof( * V_47 ) , V_87 ) ;
if ( ! V_47 )
return - V_88 ;
V_47 -> V_34 = V_13 ;
V_84 = V_71 ? V_89
: V_90 ;
for ( V_83 = 0 ; V_83 < V_91 ; ++ V_83 ) {
unsigned int V_67 ;
V_67 = F_48 ( V_79 , V_83 ) ;
if ( ! V_67 ) {
F_11 ( V_39 , L_2 , V_83 ) ;
return - V_92 ;
}
V_47 -> V_49 [ V_83 ] = V_67 ;
F_49 ( V_67 , V_84 [ V_83 ] , V_47 ) ;
}
V_18 = V_13 -> V_93 ;
for ( V_83 = 0 ; V_83 < V_13 -> V_94 ; ++ V_83 , ++ V_18 ) {
struct V_42 * V_43 ;
unsigned int V_25 ;
unsigned int V_67 ;
unsigned int V_19 ;
if ( V_18 -> V_95 != V_96 )
continue;
V_43 = F_47 ( V_39 , sizeof( * V_43 ) , V_87 ) ;
if ( ! V_43 )
return - V_88 ;
V_43 -> V_18 = V_18 ;
V_43 -> V_47 = V_47 ;
V_43 -> V_71 = V_71 ;
V_82 = ( V_18 -> V_36 == 0 ) ? & V_97
: & V_98 ;
V_18 -> V_44 = F_50 ( V_18 -> V_99 ,
V_18 -> V_100 , V_82 , V_43 ) ;
if ( ! V_18 -> V_44 ) {
F_11 ( V_39 , L_3 ) ;
return - V_92 ;
}
V_67 = V_18 -> V_36 ;
V_25 = V_18 -> V_70 ;
for ( V_19 = 0 ; V_25 ; ++ V_19 , V_25 >>= 1 ) {
if ( V_67 >= V_101 )
break;
if ( ! ( V_25 & 1 ) )
continue;
V_47 -> V_58 [ V_67 ] = V_18 -> V_44 ;
++ V_67 ;
}
}
return 0 ;
}
