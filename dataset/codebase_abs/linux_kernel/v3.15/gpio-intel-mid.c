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
return F_5 ( V_17 ) & F_8 ( V_3 % 32 ) ;
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
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_17 ( V_7 -> V_29 , V_3 ) ;
}
static int F_18 ( struct V_30 * V_31 , unsigned type )
{
struct V_6 * V_7 = F_19 ( V_31 ) ;
T_3 V_32 = F_20 ( V_31 ) ;
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
static void F_21 ( struct V_30 * V_31 )
{
}
static void F_22 ( struct V_30 * V_31 )
{
}
static int F_23 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_19 ( V_31 ) ;
if ( F_24 ( & V_7 -> V_2 , F_20 ( V_31 ) ) ) {
F_25 ( V_7 -> V_2 . V_27 ,
L_1 ,
F_20 ( V_31 ) ) ;
return - V_37 ;
}
return 0 ;
}
static void F_26 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_19 ( V_31 ) ;
F_27 ( & V_7 -> V_2 , F_20 ( V_31 ) ) ;
}
static void F_28 ( unsigned V_40 , struct V_41 * V_42 )
{
struct V_30 * V_43 = F_29 ( V_42 ) ;
struct V_6 * V_7 = F_30 ( V_43 ) ;
struct V_44 * V_2 = F_31 ( V_43 ) ;
T_3 V_45 , V_32 , V_46 ;
unsigned long V_47 ;
void T_1 * V_48 ;
for ( V_45 = 0 ; V_45 < V_7 -> V_2 . V_9 ; V_45 += 32 ) {
V_48 = F_1 ( & V_7 -> V_2 , V_45 , V_49 ) ;
while ( ( V_47 = F_5 ( V_48 ) ) ) {
V_32 = F_32 ( V_47 ) ;
V_46 = F_8 ( V_32 ) ;
F_6 ( V_46 , V_48 ) ;
F_33 ( F_34 ( V_7 -> V_29 ,
V_45 + V_32 ) ) ;
}
}
V_2 -> V_50 ( V_43 ) ;
}
static void F_35 ( struct V_6 * V_7 )
{
void T_1 * V_10 ;
unsigned V_45 ;
for ( V_45 = 0 ; V_45 < V_7 -> V_2 . V_9 ; V_45 += 32 ) {
V_10 = F_1 ( & V_7 -> V_2 , V_45 , V_34 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_45 , V_36 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_45 , V_49 ) ;
F_6 ( ~ 0 , V_10 ) ;
}
}
static int F_36 ( struct V_51 * V_31 , unsigned int V_40 ,
T_4 V_52 )
{
struct V_6 * V_7 = V_31 -> V_53 ;
F_37 ( V_40 , & V_54 , V_55 ) ;
F_38 ( V_40 , V_7 ) ;
F_39 ( V_40 , V_56 ) ;
return 0 ;
}
static int F_40 ( struct V_57 * V_27 )
{
int V_58 = F_41 ( V_27 , 500 ) ;
return V_58 ? : - V_59 ;
}
static int F_42 ( struct V_60 * V_26 ,
const struct V_61 * V_62 )
{
void T_1 * V_45 ;
struct V_6 * V_7 ;
T_3 V_63 ;
T_3 V_64 ;
int V_65 ;
struct V_66 * V_67 =
(struct V_66 * ) V_62 -> V_68 ;
V_65 = F_43 ( V_26 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_44 ( V_26 , 1 << 0 | 1 << 1 , F_45 ( V_26 ) ) ;
if ( V_65 ) {
F_25 ( & V_26 -> V_27 , L_2 ) ;
return V_65 ;
}
V_45 = F_46 ( V_26 ) [ 1 ] ;
V_64 = F_5 ( V_45 ) ;
V_63 = F_5 ( sizeof( T_3 ) + V_45 ) ;
F_47 ( V_26 , 1 << 1 ) ;
V_7 = F_48 ( & V_26 -> V_27 , sizeof( * V_7 ) , V_69 ) ;
if ( ! V_7 ) {
F_25 ( & V_26 -> V_27 , L_3 ) ;
return - V_70 ;
}
V_7 -> V_11 = F_46 ( V_26 ) [ 0 ] ;
V_7 -> V_2 . V_71 = F_49 ( & V_26 -> V_27 ) ;
V_7 -> V_2 . V_27 = & V_26 -> V_27 ;
V_7 -> V_2 . V_72 = F_4 ;
V_7 -> V_2 . V_73 = F_10 ;
V_7 -> V_2 . V_74 = F_15 ;
V_7 -> V_2 . V_75 = F_7 ;
V_7 -> V_2 . V_76 = F_9 ;
V_7 -> V_2 . V_77 = F_16 ;
V_7 -> V_2 . V_45 = V_63 ;
V_7 -> V_2 . V_9 = V_67 -> V_9 ;
V_7 -> V_2 . V_78 = false ;
V_7 -> V_26 = V_26 ;
F_50 ( & V_7 -> V_28 ) ;
V_7 -> V_29 = F_51 ( V_26 -> V_27 . V_79 , V_67 -> V_9 ,
V_64 , & V_80 , V_7 ) ;
if ( ! V_7 -> V_29 )
return - V_70 ;
F_52 ( V_26 , V_7 ) ;
V_65 = F_53 ( & V_7 -> V_2 ) ;
if ( V_65 ) {
F_25 ( & V_26 -> V_27 , L_4 , V_65 ) ;
return V_65 ;
}
F_35 ( V_7 ) ;
F_54 ( V_26 -> V_40 , V_7 ) ;
F_55 ( V_26 -> V_40 , F_28 ) ;
F_56 ( & V_26 -> V_27 ) ;
F_57 ( & V_26 -> V_27 ) ;
return 0 ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_81 ) ;
}
