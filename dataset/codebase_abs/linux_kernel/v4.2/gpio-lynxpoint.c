static unsigned long F_1 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
int V_7 ;
if ( V_4 == V_8 || V_4 == V_9 )
V_7 = V_3 * 8 ;
else
V_7 = ( V_3 / 32 ) * 4 ;
return V_6 -> V_10 + V_4 + V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_11 = F_1 ( V_2 , V_3 , V_9 ) ;
unsigned long V_12 = F_1 ( V_2 , V_3 , V_13 ) ;
F_4 ( & V_6 -> V_14 -> V_15 ) ;
if ( ! ( F_5 ( V_12 ) & F_6 ( V_3 % 32 ) ) ) {
F_7 ( & V_6 -> V_14 -> V_15 , L_1 , V_3 ) ;
return - V_16 ;
}
if ( ! ( F_5 ( V_4 ) & V_17 ) )
return - V_18 ;
F_8 ( F_5 ( V_11 ) & ~ V_19 , V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_11 = F_1 ( V_2 , V_3 , V_9 ) ;
F_8 ( F_5 ( V_11 ) | V_19 , V_11 ) ;
F_10 ( & V_6 -> V_14 -> V_15 ) ;
}
static int F_11 ( struct V_20 * V_21 , unsigned type )
{
struct V_1 * V_22 = F_12 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_22 , struct V_5 , V_2 ) ;
T_1 V_23 = F_13 ( V_21 ) ;
unsigned long V_24 ;
T_1 V_25 ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_23 , V_8 ) ;
if ( V_23 >= V_6 -> V_2 . V_26 )
return - V_27 ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
V_25 = F_5 ( V_4 ) ;
if ( type & V_29 )
V_25 &= ~ ( V_30 | V_31 ) ;
if ( type & V_32 )
V_25 = ( V_25 | V_31 ) & ~ V_30 ;
if ( type & V_33 )
V_25 = ( V_25 | V_30 ) & ~ V_31 ;
if ( type & V_34 )
V_25 |= V_30 | V_31 ;
F_8 ( V_25 , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
return ! ! ( F_5 ( V_4 ) & V_35 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_3 , int V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_24 ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
if ( V_25 )
F_8 ( F_5 ( V_4 ) | V_36 , V_4 ) ;
else
F_8 ( F_5 ( V_4 ) & ~ V_36 , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_24 ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
F_8 ( F_5 ( V_4 ) | V_37 , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_3 , int V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_4 = F_1 ( V_2 , V_3 , V_8 ) ;
unsigned long V_24 ;
F_17 ( V_2 , V_3 , V_25 ) ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
F_8 ( F_5 ( V_4 ) & ~ V_37 , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
return 0 ;
}
static void F_20 ( unsigned V_23 , struct V_38 * V_39 )
{
struct V_20 * V_40 = F_21 ( V_39 ) ;
struct V_1 * V_22 = F_22 ( V_39 ) ;
struct V_5 * V_6 = F_2 ( V_22 , struct V_5 , V_2 ) ;
struct V_41 * V_2 = F_23 ( V_40 ) ;
T_1 V_42 , V_43 , V_44 ;
unsigned long V_4 , V_45 , V_46 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_2 . V_26 ; V_42 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_42 , V_47 ) ;
V_45 = F_1 ( & V_6 -> V_2 , V_42 , V_48 ) ;
while ( ( V_46 = ( F_5 ( V_4 ) & F_5 ( V_45 ) ) ) ) {
unsigned V_49 ;
V_43 = F_24 ( V_46 ) ;
V_44 = F_6 ( V_43 ) ;
F_8 ( V_44 , V_4 ) ;
V_49 = F_25 ( V_6 -> V_2 . V_50 , V_42 + V_43 ) ;
F_26 ( V_49 ) ;
}
}
V_2 -> V_51 ( V_40 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
}
static void F_28 ( struct V_20 * V_21 )
{
}
static void F_29 ( struct V_20 * V_21 )
{
struct V_1 * V_22 = F_12 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_22 , struct V_5 , V_2 ) ;
T_1 V_23 = F_13 ( V_21 ) ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_23 , V_48 ) ;
unsigned long V_24 ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
F_8 ( F_5 ( V_4 ) | F_6 ( V_23 % 32 ) , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
}
static void F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_22 = F_12 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_22 , struct V_5 , V_2 ) ;
T_1 V_23 = F_13 ( V_21 ) ;
unsigned long V_4 = F_1 ( & V_6 -> V_2 , V_23 , V_48 ) ;
unsigned long V_24 ;
F_14 ( & V_6 -> V_28 , V_24 ) ;
F_8 ( F_5 ( V_4 ) & ~ F_6 ( V_23 % 32 ) , V_4 ) ;
F_15 ( & V_6 -> V_28 , V_24 ) ;
}
static void F_31 ( struct V_5 * V_6 )
{
unsigned long V_4 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_2 . V_26 ; V_42 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_42 , V_48 ) ;
F_8 ( 0 , V_4 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_42 , V_47 ) ;
F_8 ( 0xffffffff , V_4 ) ;
}
}
static int F_32 ( struct V_52 * V_14 )
{
struct V_5 * V_6 ;
struct V_1 * V_22 ;
struct V_53 * V_54 , * V_55 ;
struct V_56 * V_15 = & V_14 -> V_15 ;
unsigned long V_57 ;
int V_58 = - V_18 ;
V_6 = F_33 ( V_15 , sizeof( struct V_5 ) , V_59 ) ;
if ( ! V_6 )
return - V_60 ;
V_6 -> V_14 = V_14 ;
F_34 ( V_14 , V_6 ) ;
V_54 = F_35 ( V_14 , V_61 , 0 ) ;
V_55 = F_35 ( V_14 , V_62 , 0 ) ;
if ( ! V_54 ) {
F_7 ( V_15 , L_2 ) ;
return - V_27 ;
}
V_6 -> V_10 = V_54 -> V_63 ;
V_57 = F_36 ( V_54 ) ;
if ( ! F_37 ( V_15 , V_6 -> V_10 , V_57 , L_3 ) ) {
F_7 ( V_15 , L_4 ,
( unsigned int ) V_6 -> V_10 ) ;
return - V_16 ;
}
F_38 ( & V_6 -> V_28 ) ;
V_22 = & V_6 -> V_2 ;
V_22 -> V_64 = F_39 ( V_15 ) ;
V_22 -> V_65 = V_66 ;
V_22 -> V_67 = F_3 ;
V_22 -> free = F_9 ;
V_22 -> V_68 = F_18 ;
V_22 -> V_69 = F_19 ;
V_22 -> V_70 = F_16 ;
V_22 -> V_71 = F_17 ;
V_22 -> V_42 = - 1 ;
V_22 -> V_26 = V_72 ;
V_22 -> V_73 = false ;
V_22 -> V_15 = V_15 ;
V_58 = F_40 ( V_22 ) ;
if ( V_58 ) {
F_7 ( V_15 , L_5 ) ;
return V_58 ;
}
if ( V_55 && V_55 -> V_63 ) {
F_31 ( V_6 ) ;
V_58 = F_41 ( V_22 , & V_74 , 0 ,
V_75 , V_76 ) ;
if ( V_58 ) {
F_7 ( V_15 , L_6 ) ;
F_42 ( V_22 ) ;
return V_58 ;
}
F_43 ( V_22 , & V_74 ,
( unsigned ) V_55 -> V_63 ,
F_20 ) ;
}
F_44 ( V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_15 )
{
return 0 ;
}
static int F_46 ( struct V_56 * V_15 )
{
return 0 ;
}
static int F_47 ( struct V_56 * V_15 )
{
struct V_52 * V_14 = F_48 ( V_15 ) ;
struct V_5 * V_6 = F_49 ( V_14 ) ;
unsigned long V_4 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_6 -> V_2 . V_26 ; V_77 ++ ) {
if ( F_50 ( & V_6 -> V_2 , V_77 ) != NULL ) {
V_4 = F_1 ( & V_6 -> V_2 , V_77 , V_9 ) ;
F_8 ( F_5 ( V_4 ) & ~ V_19 , V_4 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_52 * V_14 )
{
struct V_5 * V_6 = F_49 ( V_14 ) ;
F_52 ( & V_14 -> V_15 ) ;
F_42 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_78 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_78 ) ;
}
