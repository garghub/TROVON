static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void T_1 * F_3 ( struct V_2 * V_4 , unsigned V_5 ,
enum V_6 V_7 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
unsigned V_9 = V_4 -> V_10 / 32 ;
T_2 V_11 = V_5 / 32 ;
return V_8 -> V_12 + V_7 * V_9 * 4 + V_11 * 4 ;
}
static void T_1 * F_4 ( struct V_2 * V_4 , unsigned V_5 ,
enum V_6 V_7 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
unsigned V_9 = V_4 -> V_10 / 32 ;
T_2 V_11 = V_5 / 16 ;
return V_8 -> V_12 + V_7 * V_9 * 4 + V_11 * 4 ;
}
static int F_5 ( struct V_2 * V_4 , unsigned V_5 )
{
void T_1 * V_13 = F_4 ( V_4 , V_5 , V_14 ) ;
T_3 V_15 = F_6 ( V_13 ) ;
int V_16 = ( V_5 % 16 ) << 1 , V_17 = ( V_15 >> V_16 ) & 3 ;
if ( V_17 ) {
V_15 &= ~ ( 3 << V_16 ) ;
F_7 ( V_15 , V_13 ) ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_4 , unsigned V_5 )
{
void T_1 * V_18 = F_3 ( V_4 , V_5 , V_19 ) ;
return F_6 ( V_18 ) & F_9 ( V_5 % 32 ) ;
}
static void F_10 ( struct V_2 * V_4 , unsigned V_5 , int V_15 )
{
void T_1 * V_20 , * V_21 ;
if ( V_15 ) {
V_20 = F_3 ( V_4 , V_5 , V_22 ) ;
F_7 ( F_9 ( V_5 % 32 ) , V_20 ) ;
} else {
V_21 = F_3 ( V_4 , V_5 , V_23 ) ;
F_7 ( F_9 ( V_5 % 32 ) , V_21 ) ;
}
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
void T_1 * V_24 = F_3 ( V_4 , V_5 , V_25 ) ;
T_3 V_15 ;
unsigned long V_26 ;
if ( V_8 -> V_27 )
F_12 ( & V_8 -> V_27 -> V_28 ) ;
F_13 ( & V_8 -> V_29 , V_26 ) ;
V_15 = F_6 ( V_24 ) ;
V_15 &= ~ F_9 ( V_5 % 32 ) ;
F_7 ( V_15 , V_24 ) ;
F_14 ( & V_8 -> V_29 , V_26 ) ;
if ( V_8 -> V_27 )
F_15 ( & V_8 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_4 ,
unsigned V_5 , int V_15 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
void T_1 * V_24 = F_3 ( V_4 , V_5 , V_25 ) ;
unsigned long V_26 ;
F_10 ( V_4 , V_5 , V_15 ) ;
if ( V_8 -> V_27 )
F_12 ( & V_8 -> V_27 -> V_28 ) ;
F_13 ( & V_8 -> V_29 , V_26 ) ;
V_15 = F_6 ( V_24 ) ;
V_15 |= F_9 ( V_5 % 32 ) ;
F_7 ( V_15 , V_24 ) ;
F_14 ( & V_8 -> V_29 , V_26 ) ;
if ( V_8 -> V_27 )
F_15 ( & V_8 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_30 * V_31 , unsigned type )
{
struct V_2 * V_3 = F_18 ( V_31 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_3 V_32 = F_19 ( V_31 ) ;
unsigned long V_26 ;
T_3 V_15 ;
void T_1 * V_33 = F_3 ( & V_8 -> V_4 , V_32 , V_34 ) ;
void T_1 * V_35 = F_3 ( & V_8 -> V_4 , V_32 , V_36 ) ;
if ( V_32 >= V_8 -> V_4 . V_10 )
return - V_37 ;
if ( V_8 -> V_27 )
F_12 ( & V_8 -> V_27 -> V_28 ) ;
F_13 ( & V_8 -> V_29 , V_26 ) ;
if ( type & V_38 )
V_15 = F_6 ( V_33 ) | F_9 ( V_32 % 32 ) ;
else
V_15 = F_6 ( V_33 ) & ( ~ F_9 ( V_32 % 32 ) ) ;
F_7 ( V_15 , V_33 ) ;
if ( type & V_39 )
V_15 = F_6 ( V_35 ) | F_9 ( V_32 % 32 ) ;
else
V_15 = F_6 ( V_35 ) & ( ~ F_9 ( V_32 % 32 ) ) ;
F_7 ( V_15 , V_35 ) ;
F_14 ( & V_8 -> V_29 , V_26 ) ;
if ( V_8 -> V_27 )
F_15 ( & V_8 -> V_27 -> V_28 ) ;
return 0 ;
}
static void F_20 ( struct V_30 * V_31 )
{
}
static void F_21 ( struct V_30 * V_31 )
{
}
static void F_22 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_23 ( V_41 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_30 * V_42 = F_24 ( V_41 ) ;
struct V_43 * V_4 = F_25 ( V_42 ) ;
T_3 V_44 , V_32 , V_45 ;
unsigned long V_46 ;
void T_1 * V_47 ;
for ( V_44 = 0 ; V_44 < V_8 -> V_4 . V_10 ; V_44 += 32 ) {
V_47 = F_3 ( & V_8 -> V_4 , V_44 , V_48 ) ;
while ( ( V_46 = F_6 ( V_47 ) ) ) {
V_32 = F_26 ( V_46 ) ;
V_45 = F_9 ( V_32 ) ;
F_7 ( V_45 , V_47 ) ;
F_27 ( F_28 ( V_3 -> V_49 ,
V_44 + V_32 ) ) ;
}
}
V_4 -> V_50 ( V_42 ) ;
}
static void F_29 ( struct V_1 * V_8 )
{
void T_1 * V_11 ;
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < V_8 -> V_4 . V_10 ; V_44 += 32 ) {
V_11 = F_3 ( & V_8 -> V_4 , V_44 , V_34 ) ;
F_7 ( 0 , V_11 ) ;
V_11 = F_3 ( & V_8 -> V_4 , V_44 , V_36 ) ;
F_7 ( 0 , V_11 ) ;
V_11 = F_3 ( & V_8 -> V_4 , V_44 , V_48 ) ;
F_7 ( ~ 0 , V_11 ) ;
}
}
static int F_30 ( struct V_51 * V_28 )
{
int V_52 = F_31 ( V_28 , 500 ) ;
return V_52 ? : - V_53 ;
}
static int F_32 ( struct V_54 * V_27 ,
const struct V_55 * V_56 )
{
void T_1 * V_44 ;
struct V_1 * V_8 ;
T_3 V_57 ;
T_3 V_58 ;
int V_59 ;
struct V_60 * V_61 =
(struct V_60 * ) V_56 -> V_62 ;
V_59 = F_33 ( V_27 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_34 ( V_27 , 1 << 0 | 1 << 1 , F_35 ( V_27 ) ) ;
if ( V_59 ) {
F_36 ( & V_27 -> V_28 , L_1 ) ;
return V_59 ;
}
V_44 = F_37 ( V_27 ) [ 1 ] ;
V_58 = F_6 ( V_44 ) ;
V_57 = F_6 ( sizeof( T_3 ) + V_44 ) ;
F_38 ( V_27 , 1 << 1 ) ;
V_8 = F_39 ( & V_27 -> V_28 , sizeof( * V_8 ) , V_63 ) ;
if ( ! V_8 ) {
F_36 ( & V_27 -> V_28 , L_2 ) ;
return - V_64 ;
}
V_8 -> V_12 = F_37 ( V_27 ) [ 0 ] ;
V_8 -> V_4 . V_65 = F_40 ( & V_27 -> V_28 ) ;
V_8 -> V_4 . V_28 = & V_27 -> V_28 ;
V_8 -> V_4 . V_66 = F_5 ;
V_8 -> V_4 . V_67 = F_11 ;
V_8 -> V_4 . V_68 = F_16 ;
V_8 -> V_4 . V_69 = F_8 ;
V_8 -> V_4 . V_70 = F_10 ;
V_8 -> V_4 . V_44 = V_57 ;
V_8 -> V_4 . V_10 = V_61 -> V_10 ;
V_8 -> V_4 . V_71 = false ;
V_8 -> V_27 = V_27 ;
F_41 ( & V_8 -> V_29 ) ;
F_42 ( V_27 , V_8 ) ;
V_59 = F_43 ( & V_8 -> V_4 ) ;
if ( V_59 ) {
F_36 ( & V_27 -> V_28 , L_3 , V_59 ) ;
return V_59 ;
}
V_59 = F_44 ( & V_8 -> V_4 ,
& V_72 ,
V_58 ,
V_73 ,
V_74 ) ;
if ( V_59 ) {
F_36 ( & V_27 -> V_28 ,
L_4 ) ;
return V_59 ;
}
F_29 ( V_8 ) ;
F_45 ( & V_8 -> V_4 ,
& V_72 ,
V_27 -> V_75 ,
F_22 ) ;
F_46 ( & V_27 -> V_28 ) ;
F_47 ( & V_27 -> V_28 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_76 ) ;
}
