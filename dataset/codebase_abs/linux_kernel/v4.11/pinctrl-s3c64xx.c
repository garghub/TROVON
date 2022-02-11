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
V_24 = V_19 -> V_28 + V_19 -> V_29 ;
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
unsigned char V_35 = F_11 ( V_19 -> V_36 ) + V_34 -> V_37 ;
void T_1 * V_24 = V_19 -> V_38 + F_12 ( V_19 -> V_36 ) ;
T_3 V_27 ;
V_27 = F_6 ( V_24 ) ;
if ( V_26 )
V_27 |= 1 << V_35 ;
else
V_27 &= ~ ( 1 << V_35 ) ;
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
unsigned char V_35 = F_11 ( V_19 -> V_36 ) + V_34 -> V_37 ;
void T_1 * V_24 = V_19 -> V_38 + F_16 ( V_19 -> V_36 ) ;
F_7 ( 1 << V_35 , V_24 ) ;
}
static int F_17 ( struct V_13 * V_34 , unsigned int type )
{
struct V_18 * V_19 = F_10 ( V_34 ) ;
struct V_17 * V_14 = V_19 -> V_39 ;
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
V_24 = V_19 -> V_38 + F_19 ( V_19 -> V_36 ) ;
V_25 = F_11 ( V_19 -> V_36 ) + V_34 -> V_37 ;
V_25 = 4 * ( V_25 / 4 ) ;
V_27 = F_6 ( V_24 ) ;
V_27 &= ~ ( V_40 << V_25 ) ;
V_27 |= V_1 << V_25 ;
F_7 ( V_27 , V_24 ) ;
F_4 ( V_14 , V_19 , V_34 -> V_37 ) ;
return 0 ;
}
static int F_20 ( struct V_41 * V_42 , unsigned int V_43 ,
T_4 V_44 )
{
struct V_18 * V_19 = V_42 -> V_45 ;
if ( ! ( V_19 -> V_46 & ( 1 << V_44 ) ) )
return - V_12 ;
F_21 ( V_43 ,
& V_47 , V_16 ) ;
F_22 ( V_43 , V_19 ) ;
return 0 ;
}
static void F_23 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = F_25 ( V_49 ) ;
struct V_13 * V_34 = F_26 ( V_49 ) ;
struct V_18 * V_19 = F_10 ( V_34 ) ;
F_27 ( V_51 , V_49 ) ;
do {
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_20 ;
unsigned int V_43 ;
V_54 = F_6 ( V_19 -> V_38 + V_56 ) ;
V_55 = F_28 ( V_54 ) ;
V_20 = V_54 & V_57 ;
if ( ! V_55 )
break;
if ( V_55 == 1 ) {
if ( V_20 < 8 )
V_55 = 0 ;
else
V_20 -= 8 ;
}
V_43 = F_29 ( V_53 -> V_58 [ V_55 ] , V_20 ) ;
F_30 ( ! V_43 ) ;
F_31 ( V_43 ) ;
} while ( 1 );
F_32 ( V_51 , V_49 ) ;
}
static int F_33 ( struct V_17 * V_14 )
{
struct V_52 * V_53 ;
struct V_18 * V_19 ;
struct V_59 * V_60 = V_14 -> V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
if ( ! V_14 -> V_63 ) {
F_34 ( V_60 , L_2 ) ;
return - V_12 ;
}
V_61 = 0 ;
V_19 = V_14 -> V_64 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_65 ; ++ V_62 , ++ V_19 ) {
unsigned int V_66 ;
unsigned int V_26 ;
if ( V_19 -> V_67 != V_68 )
continue;
V_26 = V_19 -> V_46 ;
V_66 = F_35 ( V_26 ) ;
V_19 -> V_41 = F_36 ( V_19 -> V_69 ,
V_66 , & V_70 , V_19 ) ;
if ( ! V_19 -> V_41 ) {
F_34 ( V_60 , L_3 ) ;
return - V_71 ;
}
++ V_61 ;
}
V_53 = F_37 ( V_60 , sizeof( * V_53 )
+ V_61 * sizeof( * V_53 -> V_58 ) , V_72 ) ;
if ( ! V_53 )
return - V_73 ;
V_53 -> V_39 = V_14 ;
V_19 = V_14 -> V_64 ;
V_61 = 0 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_65 ; ++ V_62 , ++ V_19 ) {
if ( V_19 -> V_67 != V_68 )
continue;
V_53 -> V_58 [ V_61 ++ ] = V_19 -> V_41 ;
}
F_38 ( V_14 -> V_63 , F_23 , V_53 ) ;
return 0 ;
}
static inline void F_39 ( struct V_13 * V_34 , bool V_26 )
{
struct V_74 * V_75 =
F_10 ( V_34 ) ;
struct V_18 * V_19 = V_75 -> V_19 ;
T_3 V_27 ;
V_27 = F_6 ( V_19 -> V_38 + V_76 ) ;
if ( V_26 )
V_27 |= 1 << V_75 -> V_77 [ V_34 -> V_37 ] ;
else
V_27 &= ~ ( 1 << V_75 -> V_77 [ V_34 -> V_37 ] ) ;
F_7 ( V_27 , V_19 -> V_38 + V_76 ) ;
}
static void F_40 ( struct V_13 * V_34 )
{
F_39 ( V_34 , false ) ;
}
static void F_41 ( struct V_13 * V_34 )
{
F_39 ( V_34 , true ) ;
}
static void F_42 ( struct V_13 * V_34 )
{
struct V_74 * V_75 =
F_10 ( V_34 ) ;
struct V_18 * V_19 = V_75 -> V_19 ;
F_7 ( 1 << V_75 -> V_77 [ V_34 -> V_37 ] ,
V_19 -> V_38 + V_78 ) ;
}
static int F_43 ( struct V_13 * V_34 , unsigned int type )
{
struct V_74 * V_75 =
F_10 ( V_34 ) ;
struct V_18 * V_19 = V_75 -> V_19 ;
struct V_17 * V_14 = V_75 -> V_19 -> V_39 ;
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
V_24 = V_19 -> V_38 + V_79 ;
V_25 = V_75 -> V_77 [ V_34 -> V_37 ] ;
if ( V_25 >= V_80 ) {
V_24 += 4 ;
V_25 -= V_80 ;
}
V_25 = V_81 * ( V_25 / 2 ) ;
V_27 = F_6 ( V_24 ) ;
V_27 &= ~ ( V_40 << V_25 ) ;
V_27 |= V_1 << V_25 ;
F_7 ( V_27 , V_24 ) ;
F_4 ( V_14 , V_19 , V_34 -> V_37 ) ;
return 0 ;
}
static inline void F_44 ( struct V_48 * V_49 , T_3 V_82 )
{
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_13 * V_34 = F_26 ( V_49 ) ;
struct V_74 * V_75 =
F_10 ( V_34 ) ;
struct V_18 * V_19 = V_75 -> V_19 ;
struct V_83 * V_53 = F_25 ( V_49 ) ;
unsigned int V_84 , V_26 ;
F_27 ( V_51 , V_49 ) ;
V_84 = F_6 ( V_19 -> V_38 + V_78 ) ;
V_26 = F_6 ( V_19 -> V_38 + V_76 ) ;
V_84 = V_84 & V_82 & ~ V_26 ;
V_84 &= V_82 ;
while ( V_84 ) {
unsigned int V_43 , V_63 ;
V_63 = F_35 ( V_84 ) - 1 ;
V_84 &= ~ ( 1 << V_63 ) ;
V_43 = F_29 ( V_53 -> V_58 [ V_63 ] , V_53 -> V_85 [ V_63 ] ) ;
F_30 ( ! V_43 ) ;
F_31 ( V_43 ) ;
}
F_32 ( V_51 , V_49 ) ;
}
static void F_45 ( struct V_48 * V_49 )
{
F_44 ( V_49 , 0xf ) ;
}
static void F_46 ( struct V_48 * V_49 )
{
F_44 ( V_49 , 0xff0 ) ;
}
static void F_47 ( struct V_48 * V_49 )
{
F_44 ( V_49 , 0xff000 ) ;
}
static void F_48 ( struct V_48 * V_49 )
{
F_44 ( V_49 , 0xff00000 ) ;
}
static int F_49 ( struct V_41 * V_42 , unsigned int V_43 ,
T_4 V_44 )
{
struct V_74 * V_75 = V_42 -> V_45 ;
struct V_18 * V_19 = V_75 -> V_19 ;
if ( ! ( V_19 -> V_46 & ( 1 << V_44 ) ) )
return - V_12 ;
F_21 ( V_43 ,
& V_86 , V_16 ) ;
F_22 ( V_43 , V_75 ) ;
return 0 ;
}
static int F_50 ( struct V_17 * V_14 )
{
struct V_59 * V_60 = V_14 -> V_60 ;
struct V_87 * V_88 = NULL ;
struct V_87 * V_89 ;
struct V_18 * V_19 ;
struct V_83 * V_53 ;
unsigned int V_62 ;
F_51 (dev->of_node, np) {
if ( F_52 ( V_90 , V_89 ) ) {
V_88 = V_89 ;
break;
}
}
if ( ! V_88 )
return - V_91 ;
V_53 = F_37 ( V_60 , sizeof( * V_53 ) , V_72 ) ;
if ( ! V_53 )
return - V_73 ;
V_53 -> V_39 = V_14 ;
for ( V_62 = 0 ; V_62 < V_92 ; ++ V_62 ) {
unsigned int V_63 ;
V_63 = F_53 ( V_88 , V_62 ) ;
if ( ! V_63 ) {
F_34 ( V_60 , L_4 , V_62 ) ;
return - V_71 ;
}
F_38 ( V_63 ,
V_93 [ V_62 ] ,
V_53 ) ;
}
V_19 = V_14 -> V_64 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_65 ; ++ V_62 , ++ V_19 ) {
struct V_74 * V_75 ;
unsigned int V_66 ;
unsigned int V_26 ;
unsigned int V_63 ;
unsigned int V_20 ;
if ( V_19 -> V_67 != V_94 )
continue;
V_26 = V_19 -> V_46 ;
V_66 = F_35 ( V_26 ) ;
V_75 = F_37 ( V_60 ,
sizeof( * V_75 ) + V_66 , V_72 ) ;
if ( ! V_75 )
return - V_73 ;
V_75 -> V_19 = V_19 ;
V_19 -> V_41 = F_36 ( V_19 -> V_69 ,
V_66 , & V_95 , V_75 ) ;
if ( ! V_19 -> V_41 ) {
F_34 ( V_60 , L_5 ) ;
return - V_71 ;
}
V_63 = V_19 -> V_36 ;
V_26 = V_19 -> V_46 ;
for ( V_20 = 0 ; V_26 ; ++ V_20 , V_26 >>= 1 ) {
if ( ! ( V_26 & 1 ) )
continue;
V_53 -> V_58 [ V_63 ] = V_19 -> V_41 ;
V_53 -> V_85 [ V_63 ] = V_20 ;
V_75 -> V_77 [ V_20 ] = V_63 ;
++ V_63 ;
}
}
return 0 ;
}
