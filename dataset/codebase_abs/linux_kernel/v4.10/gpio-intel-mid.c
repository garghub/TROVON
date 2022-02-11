static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = V_2 -> V_9 / 32 ;
T_2 V_10 = V_3 / 32 ;
return V_7 -> V_11 + V_5 * V_8 * 4 + V_10 * 4 ;
}
static void T_1 * F_3 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = V_2 -> V_9 / 32 ;
T_2 V_10 = V_3 / 16 ;
return V_7 -> V_11 + V_5 * V_8 * 4 + V_10 * 4 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_12 = F_3 ( V_2 , V_3 , V_13 ) ;
T_3 V_14 = F_5 ( V_12 ) ;
int V_15 = ( V_3 % 16 ) << 1 , V_16 = ( V_14 >> V_15 ) & 3 ;
if ( V_16 ) {
V_14 &= ~ ( 3 << V_15 ) ;
F_6 ( V_14 , V_12 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_17 = F_1 ( V_2 , V_3 , V_18 ) ;
return ! ! ( F_5 ( V_17 ) & F_8 ( V_3 % 32 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_14 )
{
void T_1 * V_19 , * V_20 ;
if ( V_14 ) {
V_19 = F_1 ( V_2 , V_3 , V_21 ) ;
F_6 ( F_8 ( V_3 % 32 ) , V_19 ) ;
} else {
V_20 = F_1 ( V_2 , V_3 , V_22 ) ;
F_6 ( F_8 ( V_3 % 32 ) , V_20 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
void T_1 * V_23 = F_1 ( V_2 , V_3 , V_24 ) ;
T_3 V_14 ;
unsigned long V_25 ;
if ( V_7 -> V_26 )
F_11 ( & V_7 -> V_26 -> V_27 ) ;
F_12 ( & V_7 -> V_28 , V_25 ) ;
V_14 = F_5 ( V_23 ) ;
V_14 &= ~ F_8 ( V_3 % 32 ) ;
F_6 ( V_14 , V_23 ) ;
F_13 ( & V_7 -> V_28 , V_25 ) ;
if ( V_7 -> V_26 )
F_14 ( & V_7 -> V_26 -> V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
void T_1 * V_23 = F_1 ( V_2 , V_3 , V_24 ) ;
unsigned long V_25 ;
F_9 ( V_2 , V_3 , V_14 ) ;
if ( V_7 -> V_26 )
F_11 ( & V_7 -> V_26 -> V_27 ) ;
F_12 ( & V_7 -> V_28 , V_25 ) ;
V_14 = F_5 ( V_23 ) ;
V_14 |= F_8 ( V_3 % 32 ) ;
F_6 ( V_14 , V_23 ) ;
F_13 ( & V_7 -> V_28 , V_25 ) ;
if ( V_7 -> V_26 )
F_14 ( & V_7 -> V_26 -> V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 , unsigned type )
{
struct V_1 * V_31 = F_17 ( V_30 ) ;
struct V_6 * V_7 = F_2 ( V_31 ) ;
T_3 V_32 = F_18 ( V_30 ) ;
unsigned long V_25 ;
T_3 V_14 ;
void T_1 * V_33 = F_1 ( & V_7 -> V_2 , V_32 , V_34 ) ;
void T_1 * V_35 = F_1 ( & V_7 -> V_2 , V_32 , V_36 ) ;
if ( V_32 >= V_7 -> V_2 . V_9 )
return - V_37 ;
if ( V_7 -> V_26 )
F_11 ( & V_7 -> V_26 -> V_27 ) ;
F_12 ( & V_7 -> V_28 , V_25 ) ;
if ( type & V_38 )
V_14 = F_5 ( V_33 ) | F_8 ( V_32 % 32 ) ;
else
V_14 = F_5 ( V_33 ) & ( ~ F_8 ( V_32 % 32 ) ) ;
F_6 ( V_14 , V_33 ) ;
if ( type & V_39 )
V_14 = F_5 ( V_35 ) | F_8 ( V_32 % 32 ) ;
else
V_14 = F_5 ( V_35 ) & ( ~ F_8 ( V_32 % 32 ) ) ;
F_6 ( V_14 , V_35 ) ;
F_13 ( & V_7 -> V_28 , V_25 ) ;
if ( V_7 -> V_26 )
F_14 ( & V_7 -> V_26 -> V_27 ) ;
return 0 ;
}
static void F_19 ( struct V_29 * V_30 )
{
}
static void F_20 ( struct V_29 * V_30 )
{
}
static void F_21 ( struct V_40 * V_41 )
{
struct V_1 * V_31 = F_22 ( V_41 ) ;
struct V_6 * V_7 = F_2 ( V_31 ) ;
struct V_29 * V_42 = F_23 ( V_41 ) ;
struct V_43 * V_2 = F_24 ( V_42 ) ;
T_3 V_44 , V_32 , V_45 ;
unsigned long V_46 ;
void T_1 * V_47 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_2 . V_9 ; V_44 += 32 ) {
V_47 = F_1 ( & V_7 -> V_2 , V_44 , V_48 ) ;
while ( ( V_46 = F_5 ( V_47 ) ) ) {
V_32 = F_25 ( V_46 ) ;
V_45 = F_8 ( V_32 ) ;
F_6 ( V_45 , V_47 ) ;
F_26 ( F_27 ( V_31 -> V_49 ,
V_44 + V_32 ) ) ;
}
}
V_2 -> V_50 ( V_42 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
void T_1 * V_10 ;
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_2 . V_9 ; V_44 += 32 ) {
V_10 = F_1 ( & V_7 -> V_2 , V_44 , V_34 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_44 , V_36 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_44 , V_48 ) ;
F_6 ( ~ 0 , V_10 ) ;
}
}
static int F_29 ( struct V_51 * V_27 )
{
int V_52 = F_30 ( V_27 , 500 ) ;
return V_52 ? : - V_53 ;
}
static int F_31 ( struct V_54 * V_26 ,
const struct V_55 * V_56 )
{
void T_1 * V_44 ;
struct V_6 * V_7 ;
T_3 V_57 ;
T_3 V_58 ;
int V_59 ;
struct V_60 * V_61 =
(struct V_60 * ) V_56 -> V_62 ;
V_59 = F_32 ( V_26 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_33 ( V_26 , 1 << 0 | 1 << 1 , F_34 ( V_26 ) ) ;
if ( V_59 ) {
F_35 ( & V_26 -> V_27 , L_1 ) ;
return V_59 ;
}
V_44 = F_36 ( V_26 ) [ 1 ] ;
V_58 = F_5 ( V_44 ) ;
V_57 = F_5 ( sizeof( T_3 ) + V_44 ) ;
F_37 ( V_26 , 1 << 1 ) ;
V_7 = F_38 ( & V_26 -> V_27 , sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 ) {
F_35 ( & V_26 -> V_27 , L_2 ) ;
return - V_64 ;
}
V_7 -> V_11 = F_36 ( V_26 ) [ 0 ] ;
V_7 -> V_2 . V_65 = F_39 ( & V_26 -> V_27 ) ;
V_7 -> V_2 . V_66 = & V_26 -> V_27 ;
V_7 -> V_2 . V_67 = F_4 ;
V_7 -> V_2 . V_68 = F_10 ;
V_7 -> V_2 . V_69 = F_15 ;
V_7 -> V_2 . V_70 = F_7 ;
V_7 -> V_2 . V_71 = F_9 ;
V_7 -> V_2 . V_44 = V_57 ;
V_7 -> V_2 . V_9 = V_61 -> V_9 ;
V_7 -> V_2 . V_72 = false ;
V_7 -> V_26 = V_26 ;
F_40 ( & V_7 -> V_28 ) ;
F_41 ( V_26 , V_7 ) ;
V_59 = F_42 ( & V_26 -> V_27 , & V_7 -> V_2 , V_7 ) ;
if ( V_59 ) {
F_35 ( & V_26 -> V_27 , L_3 , V_59 ) ;
return V_59 ;
}
V_59 = F_43 ( & V_7 -> V_2 ,
& V_73 ,
V_58 ,
V_74 ,
V_75 ) ;
if ( V_59 ) {
F_35 ( & V_26 -> V_27 ,
L_4 ) ;
return V_59 ;
}
F_28 ( V_7 ) ;
F_44 ( & V_7 -> V_2 ,
& V_73 ,
V_26 -> V_76 ,
F_21 ) ;
F_45 ( & V_26 -> V_27 ) ;
F_46 ( & V_26 -> V_27 ) ;
return 0 ;
}
