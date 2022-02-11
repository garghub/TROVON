static void F_1 ( T_1 V_1 , struct V_2 * V_3 , int V_4 )
{
F_2 ( V_1 , V_3 -> V_5 + V_4 ) ;
F_3 ( 5 ) ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_10 ;
F_6 ( & V_3 -> V_11 ) ;
time = F_7 ( V_3 -> V_5 + V_12 ) ;
V_10 = F_7 ( V_3 -> V_5 + V_12 ) ;
if ( ( V_10 - time ) > 1 )
V_10 = F_7 ( V_3 -> V_5 + V_12 ) ;
F_8 ( & V_3 -> V_11 ) ;
F_9 ( V_10 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
int V_13 = 0 ;
unsigned long time ;
V_13 = F_11 ( V_9 , & time ) ;
if ( V_13 )
goto V_14;
F_6 ( & V_3 -> V_11 ) ;
F_1 ( 0 , V_3 , V_15 ) ;
F_12 ( 100 ) ;
F_1 ( time , V_3 , V_12 ) ;
F_8 ( & V_3 -> V_11 ) ;
V_14:
return V_13 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_16 * V_17 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_18 ;
T_1 V_1 ;
F_14 ( & V_3 -> V_19 , V_18 ) ;
time = F_7 ( V_3 -> V_5 + V_20 ) ;
V_1 = F_7 ( V_3 -> V_5 + V_21 ) & V_22 ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
V_17 -> V_23 = V_1 ? 1 : 0 ;
F_9 ( time , & V_17 -> time ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_16 * V_17 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_18 ;
int V_13 = 0 ;
T_1 V_1 ;
V_13 = F_11 ( & V_17 -> time , & time ) ;
if ( V_13 )
goto V_14;
F_14 ( & V_3 -> V_19 , V_18 ) ;
F_1 ( time , V_3 , V_20 ) ;
if ( V_17 -> V_23 ) {
F_1 ( V_22 , V_3 , V_21 ) ;
V_1 = F_7 ( V_3 -> V_24 + V_25 ) ;
F_2 ( V_1 | V_26 ,
V_3 -> V_24 + V_25 ) ;
}
F_15 ( & V_3 -> V_19 , V_18 ) ;
V_14:
return V_13 ;
}
static int F_17 ( struct V_6 * V_7 ,
unsigned int V_23 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long V_18 ;
F_14 ( & V_3 -> V_19 , V_18 ) ;
if ( V_23 )
F_1 ( V_22 , V_3 , V_21 ) ;
else
F_1 ( 0 , V_3 , V_21 ) ;
F_15 ( & V_3 -> V_19 , V_18 ) ;
return 0 ;
}
static T_2 F_18 ( int V_27 , void * V_28 )
{
struct V_2 * V_3 = V_28 ;
T_1 V_1 ;
int V_29 = V_30 | V_31 ;
F_19 ( & V_3 -> V_32 -> V_7 , L_1 , V_33 , V_27 ) ;
F_20 ( & V_3 -> V_19 ) ;
V_1 = F_7 ( V_3 -> V_24 + V_25 ) ;
F_2 ( V_1 & ~ V_34 , V_3 -> V_24 + V_25 ) ;
V_1 = F_7 ( V_3 -> V_5 + V_21 ) ;
F_1 ( 0 , V_3 , V_21 ) ;
F_1 ( V_35 , V_3 , V_15 ) ;
F_21 ( & V_3 -> V_19 ) ;
if ( V_1 & V_36 ) {
if ( V_1 & V_37 )
V_29 |= V_38 ;
else
V_29 |= V_39 ;
}
F_22 ( V_3 -> V_32 , 1 , V_29 ) ;
return V_40 ;
}
static T_3 int F_23 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_24 ( & V_42 -> V_7 , sizeof( struct V_2 ) ,
V_45 ) ;
if ( ! V_3 )
return - V_46 ;
F_25 ( & V_3 -> V_19 ) ;
F_26 ( & V_3 -> V_11 ) ;
V_44 = F_27 ( V_42 , V_47 , L_2 ) ;
V_3 -> V_5 = F_28 ( & V_42 -> V_7 , V_44 ) ;
if ( F_29 ( V_3 -> V_5 ) )
return F_30 ( V_3 -> V_5 ) ;
V_44 = F_27 ( V_42 , V_47 , L_3 ) ;
V_3 -> V_24 = F_28 ( & V_42 -> V_7 , V_44 ) ;
if ( F_29 ( V_3 -> V_24 ) )
return F_30 ( V_3 -> V_24 ) ;
V_3 -> V_27 = F_31 ( V_42 , 0 ) ;
if ( V_3 -> V_27 < 0 ) {
F_32 ( & V_42 -> V_7 , L_4 ) ;
return V_3 -> V_27 ;
}
if ( F_33 ( & V_42 -> V_7 , V_3 -> V_27 , F_18 ,
0 , V_42 -> V_48 , V_3 ) < 0 ) {
F_34 ( & V_42 -> V_7 , L_5 ) ;
V_3 -> V_27 = - 1 ;
V_49 . V_50 = NULL ;
V_49 . V_51 = NULL ;
}
F_35 ( V_42 , V_3 ) ;
if ( V_3 -> V_27 != - 1 )
F_36 ( & V_42 -> V_7 , 1 ) ;
V_3 -> V_32 = F_37 ( & V_42 -> V_7 , V_42 -> V_48 ,
& V_49 , V_52 ) ;
if ( F_29 ( V_3 -> V_32 ) ) {
V_13 = F_30 ( V_3 -> V_32 ) ;
F_32 ( & V_42 -> V_7 , L_6 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 ) ) {
struct V_2 * V_3 = F_5 ( V_7 ) ;
return F_40 ( V_3 -> V_27 ) ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 ) ) {
struct V_2 * V_3 = F_5 ( V_7 ) ;
return F_42 ( V_3 -> V_27 ) ;
}
return 0 ;
}
