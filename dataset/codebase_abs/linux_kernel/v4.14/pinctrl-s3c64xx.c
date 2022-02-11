static int F_1 ( unsigned int type )
{
int V_1 ;
switch ( type ) {
case V_2 :
V_1 = V_3 ;
break;
case V_4 :
V_1 = V_5 ;
break;
case V_6 :
V_1 = V_7 ;
break;
case V_8 :
V_1 = V_9 ;
break;
case V_10 :
V_1 = V_11 ;
break;
default:
return - V_12 ;
}
return V_1 ;
}
static void F_2 ( struct V_13 * V_14 , unsigned int type )
{
if ( type & V_6 )
F_3 ( V_14 , V_15 ) ;
else
F_3 ( V_14 , V_16 ) ;
}
static void F_4 ( struct V_17 * V_14 ,
struct V_18 * V_19 , int V_20 )
{
const struct V_21 * V_22 = V_19 -> type ;
unsigned long V_23 ;
void T_1 * V_24 ;
T_2 V_25 ;
T_3 V_26 ;
T_3 V_27 ;
V_24 = V_14 -> V_28 + V_19 -> V_29 ;
V_25 = V_20 ;
if ( V_22 -> V_30 [ V_31 ] * V_25 >= 32 ) {
V_24 += 4 ;
V_25 -= 8 ;
}
V_25 = V_25 * V_22 -> V_30 [ V_31 ] ;
V_26 = ( 1 << V_22 -> V_30 [ V_31 ] ) - 1 ;
F_5 ( & V_19 -> V_32 , V_23 ) ;
V_27 = F_6 ( V_24 ) ;
V_27 &= ~ ( V_26 << V_25 ) ;
V_27 |= V_19 -> V_33 << V_25 ;
F_7 ( V_27 , V_24 ) ;
F_8 ( & V_19 -> V_32 , V_23 ) ;
}
static inline void F_9 ( struct V_13 * V_34 , bool V_26 )
{
struct V_18 * V_19 = F_10 ( V_34 ) ;
struct V_17 * V_14 = V_19 -> V_35 ;
unsigned char V_36 = F_11 ( V_19 -> V_37 ) + V_34 -> V_38 ;
void T_1 * V_24 = V_14 -> V_28 + F_12 ( V_19 -> V_37 ) ;
T_3 V_27 ;
V_27 = F_6 ( V_24 ) ;
if ( V_26 )
V_27 |= 1 << V_36 ;
else
V_27 &= ~ ( 1 << V_36 ) ;
F_7 ( V_27 , V_24 ) ;
}
static void F_13 ( struct V_13 * V_34 )
{
F_9 ( V_34 , false ) ;
}
static void F_14 ( struct V_13 * V_34 )
{
F_9 ( V_34 , true ) ;
}
static void F_15 ( struct V_13 * V_34 )
{
struct V_18 * V_19 = F_10 ( V_34 ) ;
struct V_17 * V_14 = V_19 -> V_35 ;
unsigned char V_36 = F_11 ( V_19 -> V_37 ) + V_34 -> V_38 ;
void T_1 * V_24 = V_14 -> V_28 + F_16 ( V_19 -> V_37 ) ;
F_7 ( 1 << V_36 , V_24 ) ;
}
static int F_17 ( struct V_13 * V_34 , unsigned int type )
{
struct V_18 * V_19 = F_10 ( V_34 ) ;
struct V_17 * V_14 = V_19 -> V_35 ;
void T_1 * V_24 ;
int V_1 ;
T_2 V_25 ;
T_3 V_27 ;
V_1 = F_1 ( type ) ;
if ( V_1 < 0 ) {
F_18 ( L_1 ) ;
return - V_12 ;
}
F_2 ( V_34 , type ) ;
V_24 = V_14 -> V_28 + F_19 ( V_19 -> V_37 ) ;
V_25 = F_11 ( V_19 -> V_37 ) + V_34 -> V_38 ;
V_25 = 4 * ( V_25 / 4 ) ;
V_27 = F_6 ( V_24 ) ;
V_27 &= ~ ( V_39 << V_25 ) ;
V_27 |= V_1 << V_25 ;
F_7 ( V_27 , V_24 ) ;
F_4 ( V_14 , V_19 , V_34 -> V_38 ) ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 , unsigned int V_42 ,
T_4 V_43 )
{
struct V_18 * V_19 = V_41 -> V_44 ;
if ( ! ( V_19 -> V_45 & ( 1 << V_43 ) ) )
return - V_12 ;
F_21 ( V_42 ,
& V_46 , V_16 ) ;
F_22 ( V_42 , V_19 ) ;
return 0 ;
}
static void F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_24 ( V_48 ) ;
struct V_51 * V_52 = F_25 ( V_48 ) ;
struct V_17 * V_35 = V_52 -> V_35 ;
F_26 ( V_50 , V_48 ) ;
do {
unsigned int V_53 ;
unsigned int V_54 ;
unsigned int V_20 ;
unsigned int V_42 ;
V_53 = F_6 ( V_35 -> V_28 + V_55 ) ;
V_54 = F_27 ( V_53 ) ;
V_20 = V_53 & V_56 ;
if ( ! V_54 )
break;
if ( V_54 == 1 ) {
if ( V_20 < 8 )
V_54 = 0 ;
else
V_20 -= 8 ;
}
V_42 = F_28 ( V_52 -> V_57 [ V_54 ] , V_20 ) ;
F_29 ( ! V_42 ) ;
F_30 ( V_42 ) ;
} while ( 1 );
F_31 ( V_50 , V_48 ) ;
}
static int F_32 ( struct V_17 * V_14 )
{
struct V_51 * V_52 ;
struct V_18 * V_19 ;
struct V_58 * V_59 = V_14 -> V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
if ( ! V_14 -> V_62 ) {
F_33 ( V_59 , L_2 ) ;
return - V_12 ;
}
V_60 = 0 ;
V_19 = V_14 -> V_63 ;
for ( V_61 = 0 ; V_61 < V_14 -> V_64 ; ++ V_61 , ++ V_19 ) {
unsigned int V_65 ;
unsigned int V_26 ;
if ( V_19 -> V_66 != V_67 )
continue;
V_26 = V_19 -> V_45 ;
V_65 = F_34 ( V_26 ) ;
V_19 -> V_40 = F_35 ( V_19 -> V_68 ,
V_65 , & V_69 , V_19 ) ;
if ( ! V_19 -> V_40 ) {
F_33 ( V_59 , L_3 ) ;
return - V_70 ;
}
++ V_60 ;
}
V_52 = F_36 ( V_59 , sizeof( * V_52 )
+ V_60 * sizeof( * V_52 -> V_57 ) , V_71 ) ;
if ( ! V_52 )
return - V_72 ;
V_52 -> V_35 = V_14 ;
V_19 = V_14 -> V_63 ;
V_60 = 0 ;
for ( V_61 = 0 ; V_61 < V_14 -> V_64 ; ++ V_61 , ++ V_19 ) {
if ( V_19 -> V_66 != V_67 )
continue;
V_52 -> V_57 [ V_60 ++ ] = V_19 -> V_40 ;
}
F_37 ( V_14 -> V_62 , F_23 , V_52 ) ;
return 0 ;
}
static inline void F_38 ( struct V_13 * V_34 , bool V_26 )
{
struct V_73 * V_74 =
F_10 ( V_34 ) ;
struct V_17 * V_14 = V_74 -> V_19 -> V_35 ;
T_3 V_27 ;
V_27 = F_6 ( V_14 -> V_28 + V_75 ) ;
if ( V_26 )
V_27 |= 1 << V_74 -> V_76 [ V_34 -> V_38 ] ;
else
V_27 &= ~ ( 1 << V_74 -> V_76 [ V_34 -> V_38 ] ) ;
F_7 ( V_27 , V_14 -> V_28 + V_75 ) ;
}
static void F_39 ( struct V_13 * V_34 )
{
F_38 ( V_34 , false ) ;
}
static void F_40 ( struct V_13 * V_34 )
{
F_38 ( V_34 , true ) ;
}
static void F_41 ( struct V_13 * V_34 )
{
struct V_73 * V_74 =
F_10 ( V_34 ) ;
struct V_17 * V_14 = V_74 -> V_19 -> V_35 ;
F_7 ( 1 << V_74 -> V_76 [ V_34 -> V_38 ] ,
V_14 -> V_28 + V_77 ) ;
}
static int F_42 ( struct V_13 * V_34 , unsigned int type )
{
struct V_73 * V_74 =
F_10 ( V_34 ) ;
struct V_18 * V_19 = V_74 -> V_19 ;
struct V_17 * V_14 = V_19 -> V_35 ;
void T_1 * V_24 ;
int V_1 ;
T_2 V_25 ;
T_3 V_27 ;
V_1 = F_1 ( type ) ;
if ( V_1 < 0 ) {
F_18 ( L_1 ) ;
return - V_12 ;
}
F_2 ( V_34 , type ) ;
V_24 = V_14 -> V_28 + V_78 ;
V_25 = V_74 -> V_76 [ V_34 -> V_38 ] ;
if ( V_25 >= V_79 ) {
V_24 += 4 ;
V_25 -= V_79 ;
}
V_25 = V_80 * ( V_25 / 2 ) ;
V_27 = F_6 ( V_24 ) ;
V_27 &= ~ ( V_39 << V_25 ) ;
V_27 |= V_1 << V_25 ;
F_7 ( V_27 , V_24 ) ;
F_4 ( V_14 , V_19 , V_34 -> V_38 ) ;
return 0 ;
}
static inline void F_43 ( struct V_47 * V_48 , T_3 V_81 )
{
struct V_49 * V_50 = F_24 ( V_48 ) ;
struct V_82 * V_52 = F_25 ( V_48 ) ;
struct V_17 * V_35 = V_52 -> V_35 ;
unsigned int V_83 , V_26 ;
F_26 ( V_50 , V_48 ) ;
V_83 = F_6 ( V_35 -> V_28 + V_77 ) ;
V_26 = F_6 ( V_35 -> V_28 + V_75 ) ;
V_83 = V_83 & V_81 & ~ V_26 ;
V_83 &= V_81 ;
while ( V_83 ) {
unsigned int V_42 , V_62 ;
V_62 = F_34 ( V_83 ) - 1 ;
V_83 &= ~ ( 1 << V_62 ) ;
V_42 = F_28 ( V_52 -> V_57 [ V_62 ] , V_52 -> V_84 [ V_62 ] ) ;
F_29 ( ! V_42 ) ;
F_30 ( V_42 ) ;
}
F_31 ( V_50 , V_48 ) ;
}
static void F_44 ( struct V_47 * V_48 )
{
F_43 ( V_48 , 0xf ) ;
}
static void F_45 ( struct V_47 * V_48 )
{
F_43 ( V_48 , 0xff0 ) ;
}
static void F_46 ( struct V_47 * V_48 )
{
F_43 ( V_48 , 0xff000 ) ;
}
static void F_47 ( struct V_47 * V_48 )
{
F_43 ( V_48 , 0xff00000 ) ;
}
static int F_48 ( struct V_40 * V_41 , unsigned int V_42 ,
T_4 V_43 )
{
struct V_73 * V_74 = V_41 -> V_44 ;
struct V_18 * V_19 = V_74 -> V_19 ;
if ( ! ( V_19 -> V_45 & ( 1 << V_43 ) ) )
return - V_12 ;
F_21 ( V_42 ,
& V_85 , V_16 ) ;
F_22 ( V_42 , V_74 ) ;
return 0 ;
}
static int F_49 ( struct V_17 * V_14 )
{
struct V_58 * V_59 = V_14 -> V_59 ;
struct V_86 * V_87 = NULL ;
struct V_86 * V_88 ;
struct V_18 * V_19 ;
struct V_82 * V_52 ;
unsigned int V_61 ;
F_50 (dev->of_node, np) {
if ( F_51 ( V_89 , V_88 ) ) {
V_87 = V_88 ;
break;
}
}
if ( ! V_87 )
return - V_90 ;
V_52 = F_36 ( V_59 , sizeof( * V_52 ) , V_71 ) ;
if ( ! V_52 )
return - V_72 ;
V_52 -> V_35 = V_14 ;
for ( V_61 = 0 ; V_61 < V_91 ; ++ V_61 ) {
unsigned int V_62 ;
V_62 = F_52 ( V_87 , V_61 ) ;
if ( ! V_62 ) {
F_33 ( V_59 , L_4 , V_61 ) ;
return - V_70 ;
}
F_37 ( V_62 ,
V_92 [ V_61 ] ,
V_52 ) ;
}
V_19 = V_14 -> V_63 ;
for ( V_61 = 0 ; V_61 < V_14 -> V_64 ; ++ V_61 , ++ V_19 ) {
struct V_73 * V_74 ;
unsigned int V_65 ;
unsigned int V_26 ;
unsigned int V_62 ;
unsigned int V_20 ;
if ( V_19 -> V_66 != V_93 )
continue;
V_26 = V_19 -> V_45 ;
V_65 = F_34 ( V_26 ) ;
V_74 = F_36 ( V_59 ,
sizeof( * V_74 ) + V_65 , V_71 ) ;
if ( ! V_74 )
return - V_72 ;
V_74 -> V_19 = V_19 ;
V_19 -> V_40 = F_35 ( V_19 -> V_68 ,
V_65 , & V_94 , V_74 ) ;
if ( ! V_19 -> V_40 ) {
F_33 ( V_59 , L_5 ) ;
return - V_70 ;
}
V_62 = V_19 -> V_37 ;
V_26 = V_19 -> V_45 ;
for ( V_20 = 0 ; V_26 ; ++ V_20 , V_26 >>= 1 ) {
if ( ! ( V_26 & 1 ) )
continue;
V_52 -> V_57 [ V_62 ] = V_19 -> V_40 ;
V_52 -> V_84 [ V_62 ] = V_20 ;
V_74 -> V_76 [ V_20 ] = V_62 ;
++ V_62 ;
}
}
return 0 ;
}
