static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned int F_3 ( unsigned int V_4 )
{
return ( V_4 == 0 ) ? 0 : ( V_4 + 1 ) ;
}
static void F_4 ( struct V_1 * V_5 ,
unsigned int V_4 , T_1 V_6 )
{
T_1 V_7 = F_5 ( V_4 ) ;
unsigned long V_8 ;
T_2 V_9 ;
T_1 V_10 ;
V_10 = ( F_6 ( V_6 ) - 1 ) - V_5 -> V_11 . V_12 ;
F_7 ( & V_13 , V_8 ) ;
V_9 = F_8 ( V_5 -> V_14 + V_15 ) ;
V_9 &= ~ ( V_16 << V_7 ) ;
V_9 |= V_10 << V_7 ;
F_9 ( V_9 , V_5 -> V_14 + V_15 ) ;
F_10 ( & V_13 , V_8 ) ;
}
static int F_11 ( struct V_1 * V_3 , unsigned int V_17 )
{
struct V_18 * V_11 = & V_3 -> V_11 ;
T_2 V_9 ;
V_9 = F_8 ( V_3 -> V_14 + V_15 ) ;
V_9 >>= F_5 ( V_17 ) ;
V_9 &= V_16 ;
return ( F_12 ( V_9 ) & V_11 -> V_19 ) == 0 ;
}
static unsigned long F_13 ( struct V_1 * V_3 ,
unsigned int V_17 )
{
unsigned long V_20 ;
T_2 V_9 ;
V_20 = F_14 ( V_3 -> V_21 ) ;
V_9 = F_8 ( V_3 -> V_14 + V_22 ) ;
if ( V_17 >= 2 )
V_9 >>= V_23 ;
V_9 &= V_24 ;
return V_20 / ( V_9 + 1 ) ;
}
static unsigned long F_15 ( struct V_1 * V_3 ,
unsigned int V_17 , unsigned long V_25 )
{
struct V_18 * V_11 = & V_3 -> V_11 ;
unsigned long V_20 ;
struct V_26 * V_26 ;
T_1 div ;
if ( ! F_11 ( V_3 , V_17 ) ) {
V_26 = ( V_17 < 2 ) ? V_3 -> V_27 : V_3 -> V_28 ;
if ( ! F_16 ( V_26 ) ) {
V_20 = F_14 ( V_26 ) ;
if ( V_20 )
return V_20 ;
}
F_17 ( V_3 -> V_3 . V_29 ,
L_1 , V_17 ) ;
}
V_20 = F_13 ( V_3 , V_17 ) ;
F_18 ( V_3 -> V_3 . V_29 , L_2 , V_20 ) ;
for ( div = V_11 -> V_12 ; div < 4 ; ++ div )
if ( ( V_20 >> ( V_11 -> V_10 + div ) ) < V_25 )
break;
F_4 ( V_3 , V_17 , F_12 ( div ) ) ;
return V_20 >> div ;
}
static int F_19 ( struct V_2 * V_3 , struct V_30 * V_5 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
struct V_32 * V_33 ;
if ( ! ( V_31 -> V_11 . V_34 & F_12 ( V_5 -> V_35 ) ) ) {
F_17 ( V_3 -> V_29 ,
L_3 ,
V_5 -> V_35 ) ;
return - V_36 ;
}
V_33 = F_20 ( V_3 -> V_29 , sizeof( * V_33 ) , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
F_21 ( V_5 , V_33 ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_3 , struct V_30 * V_5 )
{
F_23 ( V_3 -> V_29 , F_24 ( V_5 ) ) ;
F_21 ( V_5 , NULL ) ;
}
static int F_25 ( struct V_2 * V_3 , struct V_30 * V_5 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
unsigned int V_39 = F_3 ( V_5 -> V_35 ) ;
unsigned long V_8 ;
T_2 V_40 ;
F_7 ( & V_13 , V_8 ) ;
V_40 = F_8 ( V_31 -> V_14 + V_41 ) ;
V_40 &= ~ F_26 ( V_39 ) ;
V_40 |= F_27 ( V_39 ) ;
F_9 ( V_40 , V_31 -> V_14 + V_41 ) ;
V_40 &= ~ F_27 ( V_39 ) ;
V_40 |= F_26 ( V_39 ) | F_28 ( V_39 ) ;
F_9 ( V_40 , V_31 -> V_14 + V_41 ) ;
F_10 ( & V_13 , V_8 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 , struct V_30 * V_5 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
unsigned int V_39 = F_3 ( V_5 -> V_35 ) ;
unsigned long V_8 ;
T_2 V_40 ;
F_7 ( & V_13 , V_8 ) ;
V_40 = F_8 ( V_31 -> V_14 + V_41 ) ;
V_40 &= ~ F_28 ( V_39 ) ;
F_9 ( V_40 , V_31 -> V_14 + V_41 ) ;
F_10 ( & V_13 , V_8 ) ;
}
static void F_30 ( struct V_1 * V_3 ,
struct V_30 * V_5 )
{
unsigned int V_39 = F_3 ( V_5 -> V_35 ) ;
T_2 V_40 ;
unsigned long V_8 ;
F_7 ( & V_13 , V_8 ) ;
V_40 = F_8 ( V_3 -> V_14 + V_41 ) ;
V_40 |= F_27 ( V_39 ) ;
F_9 ( V_40 , V_3 -> V_14 + V_41 ) ;
V_40 &= ~ F_27 ( V_39 ) ;
F_9 ( V_40 , V_3 -> V_14 + V_41 ) ;
F_10 ( & V_13 , V_8 ) ;
}
static int F_31 ( struct V_2 * V_3 , struct V_30 * V_5 ,
int V_42 , int V_43 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
struct V_32 * V_17 = F_24 ( V_5 ) ;
T_2 V_44 = V_17 -> V_44 , V_45 , V_46 , V_47 ;
if ( V_43 > V_48 )
return - V_49 ;
if ( V_43 == V_17 -> V_43 && V_42 == V_17 -> V_42 )
return 0 ;
V_45 = F_8 ( V_31 -> V_14 + F_32 ( V_5 -> V_35 ) ) ;
V_47 = F_8 ( V_31 -> V_14 + F_33 ( V_5 -> V_35 ) ) ;
++ V_45 ;
if ( V_17 -> V_43 != V_43 ) {
unsigned long V_50 ;
T_2 V_51 ;
V_51 = V_48 / V_43 ;
F_18 ( V_31 -> V_3 . V_29 , L_4 ,
V_42 , V_43 , V_51 ) ;
V_50 = F_15 ( V_31 , V_5 -> V_35 , V_51 ) ;
F_18 ( V_31 -> V_3 . V_29 , L_5 , V_50 ) ;
V_44 = V_48 / V_50 ;
V_45 = V_43 / V_44 ;
}
if ( V_45 <= 1 )
return - V_49 ;
V_46 = V_42 / V_44 ;
if ( ! V_46 )
++ V_46 ;
V_46 = V_45 - V_46 ;
-- V_45 ;
-- V_46 ;
F_18 ( V_31 -> V_3 . V_29 ,
L_6 , V_44 , V_46 , V_45 ) ;
F_9 ( V_45 , V_31 -> V_14 + F_32 ( V_5 -> V_35 ) ) ;
F_9 ( V_46 , V_31 -> V_14 + F_33 ( V_5 -> V_35 ) ) ;
if ( V_47 == ( T_2 ) - 1 ) {
F_18 ( V_31 -> V_3 . V_29 , L_7 ) ;
F_30 ( V_31 , V_5 ) ;
}
V_17 -> V_43 = V_43 ;
V_17 -> V_44 = V_44 ;
V_17 -> V_42 = V_42 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_3 ,
unsigned int V_4 , bool V_52 )
{
unsigned int V_39 = F_3 ( V_4 ) ;
unsigned long V_8 ;
T_2 V_40 ;
F_7 ( & V_13 , V_8 ) ;
V_40 = F_8 ( V_3 -> V_14 + V_41 ) ;
if ( V_52 ) {
V_3 -> V_53 |= F_12 ( V_4 ) ;
V_40 |= F_35 ( V_39 ) ;
} else {
V_3 -> V_53 &= ~ F_12 ( V_4 ) ;
V_40 &= ~ F_35 ( V_39 ) ;
}
F_9 ( V_40 , V_3 -> V_14 + V_41 ) ;
F_10 ( & V_13 , V_8 ) ;
}
static int F_36 ( struct V_2 * V_3 ,
struct V_30 * V_5 ,
enum V_54 V_55 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
bool V_52 = ( V_55 == V_56 ) ;
F_34 ( V_31 , V_5 -> V_35 , V_52 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_3 . V_29 -> V_59 ;
const struct V_60 * V_61 ;
struct V_62 * V_63 ;
const T_3 * V_64 ;
T_2 V_65 ;
V_61 = F_38 ( V_66 , V_58 ) ;
if ( ! V_61 )
return - V_67 ;
memcpy ( & V_3 -> V_11 , V_61 -> V_68 , sizeof( V_3 -> V_11 ) ) ;
F_39 (np, L_8 , prop, cur, val) {
if ( V_65 >= V_69 ) {
F_40 ( V_3 -> V_3 . V_29 ,
L_9 ,
V_70 ) ;
continue;
}
V_3 -> V_11 . V_34 |= F_12 ( V_65 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_3 )
{
return - V_67 ;
}
static int F_41 ( struct V_71 * V_72 )
{
struct V_73 * V_29 = & V_72 -> V_29 ;
struct V_1 * V_3 ;
struct V_74 * V_75 ;
unsigned int V_17 ;
int V_76 ;
V_3 = F_20 ( & V_72 -> V_29 , sizeof( * V_3 ) , V_37 ) ;
if ( V_3 == NULL )
return - V_38 ;
V_3 -> V_3 . V_29 = & V_72 -> V_29 ;
V_3 -> V_3 . V_77 = & V_78 ;
V_3 -> V_3 . V_14 = - 1 ;
V_3 -> V_3 . V_79 = V_69 ;
V_3 -> V_53 = F_12 ( V_69 ) - 1 ;
if ( F_42 ( V_80 ) && V_72 -> V_29 . V_59 ) {
V_76 = F_37 ( V_3 ) ;
if ( V_76 )
return V_76 ;
V_3 -> V_3 . V_81 = V_82 ;
V_3 -> V_3 . V_83 = 3 ;
} else {
if ( ! V_72 -> V_29 . V_84 ) {
F_40 ( & V_72 -> V_29 , L_10 ) ;
return - V_36 ;
}
memcpy ( & V_3 -> V_11 , V_72 -> V_29 . V_84 ,
sizeof( V_3 -> V_11 ) ) ;
}
V_75 = F_43 ( V_72 , V_85 , 0 ) ;
V_3 -> V_14 = F_44 ( & V_72 -> V_29 , V_75 ) ;
if ( F_16 ( V_3 -> V_14 ) )
return F_45 ( V_3 -> V_14 ) ;
V_3 -> V_21 = F_46 ( & V_72 -> V_29 , L_11 ) ;
if ( F_16 ( V_3 -> V_21 ) ) {
F_40 ( V_29 , L_12 ) ;
return F_45 ( V_3 -> V_21 ) ;
}
V_76 = F_47 ( V_3 -> V_21 ) ;
if ( V_76 < 0 ) {
F_40 ( V_29 , L_13 ) ;
return V_76 ;
}
for ( V_17 = 0 ; V_17 < V_69 ; ++ V_17 )
if ( V_3 -> V_11 . V_34 & F_12 ( V_17 ) )
F_34 ( V_3 , V_17 , true ) ;
V_3 -> V_27 = F_46 ( & V_72 -> V_29 , L_14 ) ;
V_3 -> V_28 = F_46 ( & V_72 -> V_29 , L_15 ) ;
F_48 ( V_72 , V_3 ) ;
V_76 = F_49 ( & V_3 -> V_3 ) ;
if ( V_76 < 0 ) {
F_40 ( V_29 , L_16 ) ;
F_50 ( V_3 -> V_21 ) ;
return V_76 ;
}
F_18 ( V_29 , L_17 ,
F_14 ( V_3 -> V_21 ) ,
! F_16 ( V_3 -> V_27 ) ? F_14 ( V_3 -> V_27 ) : 0 ,
! F_16 ( V_3 -> V_28 ) ? F_14 ( V_3 -> V_28 ) : 0 ) ;
return 0 ;
}
static int F_51 ( struct V_71 * V_72 )
{
struct V_1 * V_3 = F_52 ( V_72 ) ;
int V_76 ;
V_76 = F_53 ( & V_3 -> V_3 ) ;
if ( V_76 < 0 )
return V_76 ;
F_50 ( V_3 -> V_21 ) ;
return 0 ;
}
static int F_54 ( struct V_73 * V_29 )
{
struct V_1 * V_3 = F_55 ( V_29 ) ;
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_69 ; ++ V_86 ) {
struct V_30 * V_5 = & V_3 -> V_3 . V_87 [ V_86 ] ;
struct V_32 * V_17 = F_24 ( V_5 ) ;
if ( ! V_17 )
continue;
V_17 -> V_43 = 0 ;
V_17 -> V_42 = 0 ;
}
return 0 ;
}
static int F_56 ( struct V_73 * V_29 )
{
struct V_1 * V_3 = F_55 ( V_29 ) ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_69 ; ++ V_17 ) {
if ( V_3 -> V_11 . V_34 & F_12 ( V_17 ) )
F_34 ( V_3 , V_17 ,
V_3 -> V_53 & F_12 ( V_17 ) ) ;
}
return 0 ;
}
