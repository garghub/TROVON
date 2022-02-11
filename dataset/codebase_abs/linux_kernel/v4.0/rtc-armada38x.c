static void F_1 ( T_1 V_1 , struct V_2 * V_3 , int V_4 )
{
F_2 ( V_1 , V_3 -> V_5 + V_4 ) ;
F_3 ( 5 ) ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_10 , V_11 ;
F_6 ( & V_3 -> V_12 , V_11 ) ;
time = F_7 ( V_3 -> V_5 + V_13 ) ;
V_10 = F_7 ( V_3 -> V_5 + V_13 ) ;
if ( ( V_10 - time ) > 1 )
V_10 = F_7 ( V_3 -> V_5 + V_13 ) ;
F_8 ( & V_3 -> V_12 , V_11 ) ;
F_9 ( V_10 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
int V_14 = 0 ;
unsigned long time , V_11 ;
V_14 = F_11 ( V_9 , & time ) ;
if ( V_14 )
goto V_15;
F_6 ( & V_3 -> V_12 , V_11 ) ;
F_1 ( 0 , V_3 , V_16 ) ;
F_8 ( & V_3 -> V_12 , V_11 ) ;
F_12 ( 100 ) ;
F_6 ( & V_3 -> V_12 , V_11 ) ;
F_1 ( time , V_3 , V_13 ) ;
F_8 ( & V_3 -> V_12 , V_11 ) ;
V_15:
return V_14 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_11 ;
T_1 V_1 ;
F_6 ( & V_3 -> V_12 , V_11 ) ;
time = F_7 ( V_3 -> V_5 + V_19 ) ;
V_1 = F_7 ( V_3 -> V_5 + V_20 ) & V_21 ;
F_8 ( & V_3 -> V_12 , V_11 ) ;
V_18 -> V_22 = V_1 ? 1 : 0 ;
F_9 ( time , & V_18 -> time ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long time , V_11 ;
int V_14 = 0 ;
T_1 V_1 ;
V_14 = F_11 ( & V_18 -> time , & time ) ;
if ( V_14 )
goto V_15;
F_6 ( & V_3 -> V_12 , V_11 ) ;
F_1 ( time , V_3 , V_19 ) ;
if ( V_18 -> V_22 ) {
F_1 ( V_21 , V_3 , V_20 ) ;
V_1 = F_7 ( V_3 -> V_23 + V_24 ) ;
F_2 ( V_1 | V_25 ,
V_3 -> V_23 + V_24 ) ;
}
F_8 ( & V_3 -> V_12 , V_11 ) ;
V_15:
return V_14 ;
}
static int F_15 ( struct V_6 * V_7 ,
unsigned int V_22 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
unsigned long V_11 ;
F_6 ( & V_3 -> V_12 , V_11 ) ;
if ( V_22 )
F_1 ( V_21 , V_3 , V_20 ) ;
else
F_1 ( 0 , V_3 , V_20 ) ;
F_8 ( & V_3 -> V_12 , V_11 ) ;
return 0 ;
}
static T_2 F_16 ( int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_27 ;
T_1 V_1 ;
int V_28 = V_29 | V_30 ;
F_17 ( & V_3 -> V_31 -> V_7 , L_1 , V_32 , V_26 ) ;
F_18 ( & V_3 -> V_12 ) ;
V_1 = F_7 ( V_3 -> V_23 + V_24 ) ;
F_2 ( V_1 & ~ V_33 , V_3 -> V_23 + V_24 ) ;
V_1 = F_7 ( V_3 -> V_5 + V_20 ) ;
F_1 ( 0 , V_3 , V_20 ) ;
F_1 ( V_34 , V_3 , V_16 ) ;
F_19 ( & V_3 -> V_12 ) ;
if ( V_1 & V_35 ) {
if ( V_1 & V_36 )
V_28 |= V_37 ;
else
V_28 |= V_38 ;
}
F_20 ( V_3 -> V_31 , 1 , V_28 ) ;
return V_39 ;
}
static T_3 int F_21 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_2 * V_3 ;
int V_14 ;
V_3 = F_22 ( & V_41 -> V_7 , sizeof( struct V_2 ) ,
V_44 ) ;
if ( ! V_3 )
return - V_45 ;
F_23 ( & V_3 -> V_12 ) ;
V_43 = F_24 ( V_41 , V_46 , L_2 ) ;
V_3 -> V_5 = F_25 ( & V_41 -> V_7 , V_43 ) ;
if ( F_26 ( V_3 -> V_5 ) )
return F_27 ( V_3 -> V_5 ) ;
V_43 = F_24 ( V_41 , V_46 , L_3 ) ;
V_3 -> V_23 = F_25 ( & V_41 -> V_7 , V_43 ) ;
if ( F_26 ( V_3 -> V_23 ) )
return F_27 ( V_3 -> V_23 ) ;
V_3 -> V_26 = F_28 ( V_41 , 0 ) ;
if ( V_3 -> V_26 < 0 ) {
F_29 ( & V_41 -> V_7 , L_4 ) ;
return V_3 -> V_26 ;
}
if ( F_30 ( & V_41 -> V_7 , V_3 -> V_26 , F_16 ,
0 , V_41 -> V_47 , V_3 ) < 0 ) {
F_31 ( & V_41 -> V_7 , L_5 ) ;
V_3 -> V_26 = - 1 ;
V_48 . V_49 = NULL ;
V_48 . V_50 = NULL ;
}
F_32 ( V_41 , V_3 ) ;
if ( V_3 -> V_26 != - 1 )
F_33 ( & V_41 -> V_7 , 1 ) ;
V_3 -> V_31 = F_34 ( & V_41 -> V_7 , V_41 -> V_47 ,
& V_48 , V_51 ) ;
if ( F_26 ( V_3 -> V_31 ) ) {
V_14 = F_27 ( V_3 -> V_31 ) ;
F_29 ( & V_41 -> V_7 , L_6 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
if ( F_36 ( V_7 ) ) {
struct V_2 * V_3 = F_5 ( V_7 ) ;
return F_37 ( V_3 -> V_26 ) ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
if ( F_36 ( V_7 ) ) {
struct V_2 * V_3 = F_5 ( V_7 ) ;
return F_39 ( V_3 -> V_26 ) ;
}
return 0 ;
}
