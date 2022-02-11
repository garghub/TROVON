static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
void T_1 * V_5 = V_2 -> V_6 + V_3 ;
T_2 V_7 ;
V_7 = F_2 ( V_5 ) ;
V_7 &= ~ V_4 ;
F_3 ( V_7 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
void T_1 * V_5 = V_2 -> V_6 + V_3 ;
T_2 V_7 ;
V_7 = F_2 ( V_5 ) ;
V_7 |= V_4 ;
F_3 ( V_7 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 , unsigned int V_9 )
{
T_2 V_7 = F_2 ( V_2 -> V_6 + V_3 ) & ~ V_9 ;
V_7 |= V_8 & V_9 ;
F_3 ( V_8 , V_2 -> V_6 + V_3 ) ;
}
void F_6 ( struct V_10 * V_11 ,
void (* F_7)( bool V_12 , struct V_10 * V_11 ) ,
struct V_10 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned long V_14 ;
F_9 ( & V_2 -> V_15 , V_14 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> F_7 = F_7 ;
F_10 ( & V_2 -> V_15 , V_14 ) ;
}
bool F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_16 ;
V_16 = F_2 ( V_2 -> V_6 + V_17 ) ;
return ( V_16 & ( V_18 | V_19 ) ) == ( V_18 | V_19 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_20 , 0 | V_21 , V_22 | V_21 ) ;
F_4 ( V_2 , V_23 , V_24 |
V_25 | V_26 ) ;
F_5 ( V_2 , V_23 , 0 , V_24 | V_25 |
V_26 | V_27 |
V_28 | V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_17 , V_30 | V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_17 , V_30 | V_31 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_32 , V_33 ) ;
F_4 ( V_2 , V_34 , V_35 |
V_36 | V_37 ) ;
F_4 ( V_2 , V_23 , V_24 |
V_25 | V_26 ) ;
F_16 ( 5 , 10 ) ;
F_1 ( V_2 , V_34 , V_35 |
V_36 | V_37 ) ;
F_1 ( V_2 , V_32 , V_33 ) ;
F_1 ( V_2 , V_23 , V_24 |
V_25 | V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_12 )
{
void (* F_7)( bool V_12 , struct V_10 * V_11 );
struct V_10 * V_13 ;
unsigned long V_14 ;
F_9 ( & V_2 -> V_15 , V_14 ) ;
F_7 = V_2 -> F_7 ;
V_13 = V_2 -> V_13 ;
F_10 ( & V_2 -> V_15 , V_14 ) ;
if ( F_7 )
F_7 ( V_12 , V_13 ) ;
}
static T_3 F_18 ( int V_38 , void * V_39 )
{
struct V_10 * V_11 = V_39 ;
struct V_1 * V_2 = F_8 ( V_11 ) ;
bool V_12 ;
F_15 ( V_2 ) ;
V_12 = F_11 ( V_11 ) ;
if ( V_2 -> V_12 != V_12 ) {
F_19 ( V_11 , L_1 ,
V_2 -> V_12 , V_12 ) ;
V_2 -> V_12 = V_12 ;
F_17 ( V_2 , V_12 ) ;
}
return V_40 ;
}
static int F_20 ( struct V_41 * V_42 )
{
struct V_10 * V_11 = & V_42 -> V_11 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_45 ;
V_2 = F_21 ( V_11 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
F_22 ( V_42 , V_2 ) ;
F_23 ( & V_2 -> V_15 ) ;
V_44 = F_24 ( V_42 , V_48 , 0 ) ;
V_2 -> V_6 = F_25 ( V_11 , V_44 ) ;
if ( F_26 ( V_2 -> V_6 ) ) {
V_45 = F_27 ( V_2 -> V_6 ) ;
F_28 ( V_11 , L_2 , V_45 ) ;
return V_45 ;
}
V_2 -> V_49 = F_29 ( V_11 , NULL ) ;
if ( F_26 ( V_2 -> V_49 ) ) {
V_45 = F_27 ( V_2 -> V_49 ) ;
F_28 ( V_11 , L_3 , V_45 ) ;
return V_45 ;
}
V_2 -> V_38 = F_30 ( V_42 , 0 ) ;
if ( V_2 -> V_38 < 0 ) {
F_28 ( V_11 , L_4 , V_2 -> V_38 ) ;
return V_2 -> V_38 ;
}
V_45 = F_31 ( V_11 , V_2 -> V_38 , NULL ,
F_18 ,
V_50 | V_51 |
V_52 , L_5 , V_11 ) ;
if ( V_45 ) {
F_28 ( V_11 , L_6 , V_45 ) ;
return V_45 ;
}
V_45 = F_32 ( V_2 -> V_49 ) ;
if ( V_45 ) {
F_28 ( V_11 , L_7 , V_45 ) ;
return V_45 ;
}
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
F_14 ( V_2 ) ;
F_35 ( V_2 -> V_49 ) ;
return 0 ;
}
