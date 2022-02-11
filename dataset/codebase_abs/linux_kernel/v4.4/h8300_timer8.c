static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
int V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & 0x20 ;
do {
V_7 = V_6 ;
V_3 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_4 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_5 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & 0x20 ;
} while ( F_4 ( ( V_6 != V_7 ) || ( V_3 > V_4 && V_3 < V_5 )
|| ( V_4 > V_5 && V_4 < V_3 ) || ( V_5 > V_3 && V_5 < V_4 ) ) );
V_4 |= V_6 << 10 ;
return V_4 ;
}
static T_1 F_5 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_6 ( F_2 ( V_2 -> V_8 + V_9 ) & ~ 0x40 ,
V_2 -> V_8 + V_9 ) ;
V_2 -> V_13 |= V_14 ;
F_7 ( V_2 -> V_15 , V_2 -> V_8 + V_16 ) ;
if ( ! ( V_2 -> V_13 & V_17 ) ) {
if ( F_8 ( & V_2 -> V_18 ) )
F_7 ( 0x0000 , V_2 -> V_8 + V_19 ) ;
V_2 -> V_18 . V_20 ( & V_2 -> V_18 ) ;
}
V_2 -> V_13 &= ~ ( V_17 | V_14 ) ;
return V_21 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned long V_22 )
{
unsigned long V_13 ;
unsigned long V_23 ;
F_10 ( & V_2 -> V_24 , V_13 ) ;
if ( V_22 >= 0x10000 )
F_11 ( & V_2 -> V_25 -> V_26 , L_1 ) ;
V_23 = F_1 ( V_2 ) ;
V_2 -> V_15 = V_22 ;
F_6 ( F_2 ( V_2 -> V_8 + V_19 ) | 0x40 , V_2 -> V_8 + V_19 ) ;
if ( V_22 > V_23 )
F_7 ( V_22 , V_2 -> V_8 + V_16 ) ;
else
F_7 ( V_23 + 1 , V_2 -> V_8 + V_16 ) ;
F_12 ( & V_2 -> V_24 , V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_27 = F_14 ( V_2 -> V_28 ) / 64 ;
F_7 ( 0xffff , V_2 -> V_8 + V_16 ) ;
F_7 ( 0x0000 , V_2 -> V_8 + V_10 ) ;
F_7 ( 0x0c02 , V_2 -> V_8 + V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
unsigned long V_13 ;
F_10 ( & V_2 -> V_24 , V_13 ) ;
if ( ! ( V_2 -> V_13 & V_30 ) )
V_29 = F_13 ( V_2 ) ;
if ( V_29 )
goto V_31;
V_2 -> V_13 |= V_30 ;
V_31:
F_12 ( & V_2 -> V_24 , V_13 ) ;
return V_29 ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
F_10 ( & V_2 -> V_24 , V_13 ) ;
F_7 ( 0x0000 , V_2 -> V_8 + V_19 ) ;
F_12 ( & V_2 -> V_24 , V_13 ) ;
}
static inline struct V_1 * F_17 ( struct V_32 * V_18 )
{
return F_18 ( V_18 , struct V_1 , V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_33 )
{
struct V_32 * V_18 = & V_2 -> V_18 ;
F_15 ( V_2 ) ;
V_18 -> V_34 = 32 ;
V_18 -> V_35 = F_20 ( V_2 -> V_27 , V_36 , V_18 -> V_34 ) ;
V_18 -> V_37 = F_21 ( 0xffff , V_18 ) ;
V_18 -> V_38 = F_21 ( 0x0001 , V_18 ) ;
F_9 ( V_2 , V_33 ? ( V_2 -> V_27 + V_39 / 2 ) / V_39 : 0x10000 ) ;
}
static int F_22 ( struct V_32 * V_18 )
{
F_16 ( F_17 ( V_18 ) ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
F_24 ( & V_2 -> V_25 -> V_26 , L_2 ) ;
F_16 ( V_2 ) ;
F_19 ( V_2 , V_40 ) ;
return 0 ;
}
static int F_25 ( struct V_32 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
F_24 ( & V_2 -> V_25 -> V_26 , L_3 ) ;
F_16 ( V_2 ) ;
F_19 ( V_2 , V_41 ) ;
return 0 ;
}
static int F_26 ( unsigned long V_22 ,
struct V_32 * V_18 )
{
struct V_1 * V_2 = F_17 ( V_18 ) ;
F_27 ( ! F_8 ( V_18 ) ) ;
F_9 ( V_2 , V_22 - 1 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_42 * V_25 )
{
struct V_43 * V_44 ;
int V_11 ;
int V_29 ;
V_2 -> V_25 = V_25 ;
V_44 = F_29 ( V_2 -> V_25 , V_45 , 0 ) ;
if ( ! V_44 ) {
F_30 ( & V_2 -> V_25 -> V_26 , L_4 ) ;
return - V_46 ;
}
V_11 = F_31 ( V_2 -> V_25 , 0 ) ;
if ( V_11 < 0 ) {
F_30 ( & V_2 -> V_25 -> V_26 , L_5 ) ;
return - V_46 ;
}
V_2 -> V_8 = V_44 -> V_47 ;
V_2 -> V_48 . V_49 = F_32 ( & V_2 -> V_25 -> V_26 ) ;
V_2 -> V_48 . V_50 = F_5 ;
V_2 -> V_48 . V_12 = V_2 ;
V_2 -> V_48 . V_13 = V_51 ;
V_2 -> V_28 = F_33 ( & V_2 -> V_25 -> V_26 , L_6 ) ;
if ( F_34 ( V_2 -> V_28 ) ) {
F_30 ( & V_2 -> V_25 -> V_26 , L_7 ) ;
return F_35 ( V_2 -> V_28 ) ;
}
V_2 -> V_18 . V_49 = V_25 -> V_49 ;
V_2 -> V_18 . V_52 = V_53 |
V_54 ;
V_2 -> V_18 . V_55 = 200 ;
V_2 -> V_18 . V_56 = F_36 ( 0 ) ;
V_2 -> V_18 . V_57 = F_26 ;
V_2 -> V_18 . V_58 = F_22 ;
V_2 -> V_18 . V_59 = F_23 ;
V_2 -> V_18 . V_60 = F_25 ;
V_29 = F_37 ( V_11 , & V_2 -> V_48 ) ;
if ( V_29 < 0 ) {
F_30 ( & V_2 -> V_25 -> V_26 ,
L_8 , V_11 ) ;
return V_29 ;
}
F_38 ( & V_2 -> V_18 ) ;
F_39 ( V_25 , V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_42 * V_25 )
{
struct V_1 * V_2 = F_41 ( V_25 ) ;
if ( V_2 ) {
F_24 ( & V_25 -> V_26 , L_9 ) ;
return 0 ;
}
V_2 = F_42 ( & V_25 -> V_26 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
return F_28 ( V_2 , V_25 ) ;
}
static int F_43 ( struct V_42 * V_25 )
{
return - V_63 ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_64 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_64 ) ;
}
