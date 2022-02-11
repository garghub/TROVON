static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
unsigned long V_8 = 0 ;
F_3 ( & V_4 -> V_9 ) ;
V_7 = V_10 ;
V_10 = 0 ;
if ( V_7 & ( V_11 | V_12 ) ) {
V_10 = ( V_13 | V_14 ) & ( V_7 >> 2 ) ;
} else {
V_10 = V_13 | V_14 ;
}
if ( V_7 & V_13 )
V_7 &= ~ V_11 ;
V_10 = V_7 & ( V_11 | V_12 ) ;
if ( V_7 & V_13 )
V_8 |= V_15 | V_16 ;
if ( V_7 & V_14 )
V_8 |= V_17 | V_16 ;
F_4 ( V_6 , 1 , V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_18 ;
}
static int F_6 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_21 ;
V_21 = F_7 ( V_4 -> V_22 , F_1 , 0 , L_1 , V_20 ) ;
if ( V_21 ) {
F_8 ( V_20 , L_2 , V_4 -> V_22 ) ;
goto V_23;
}
V_21 = F_7 ( V_4 -> V_24 , F_1 , 0 , L_3 , V_20 ) ;
if ( V_21 ) {
F_8 ( V_20 , L_2 , V_4 -> V_24 ) ;
goto V_25;
}
V_6 -> V_26 = V_27 ;
F_9 ( V_6 , NULL , V_27 ) ;
return 0 ;
V_25:
F_10 ( V_4 -> V_22 , V_20 ) ;
V_23:
F_11 ( V_4 -> V_28 ) ;
return V_21 ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
F_13 ( & V_4 -> V_9 ) ;
V_10 = 0 ;
F_14 ( & V_4 -> V_9 ) ;
F_10 ( V_4 -> V_24 , V_20 ) ;
F_10 ( V_4 -> V_22 , V_20 ) ;
}
static int F_15 ( struct V_19 * V_20 , unsigned int V_29 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
F_13 ( & V_4 -> V_9 ) ;
if ( V_29 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
F_14 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
F_17 ( V_32 , V_31 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
unsigned long time ;
int V_21 ;
V_21 = F_19 ( V_31 , & time ) ;
if ( V_21 == 0 )
V_32 = time ;
return V_21 ;
}
static int F_20 ( struct V_19 * V_20 , struct V_33 * V_34 )
{
T_2 V_7 ;
V_7 = V_10 ;
V_34 -> V_29 = ( V_7 & V_11 ) ? 1 : 0 ;
V_34 -> V_35 = ( V_7 & V_13 ) ? 1 : 0 ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , struct V_33 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
unsigned long time ;
int V_21 ;
F_13 ( & V_4 -> V_9 ) ;
V_21 = F_19 ( & V_34 -> time , & time ) ;
if ( V_21 != 0 )
goto V_36;
V_10 = V_10 & ( V_12 | V_11 | V_13 ) ;
V_37 = time ;
if ( V_34 -> V_29 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
V_36:
F_14 ( & V_4 -> V_9 ) ;
return V_21 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_38 * V_39 )
{
F_23 ( V_39 , L_4 , ( T_2 ) V_40 ) ;
F_23 ( V_39 , L_5 , ( T_2 ) V_10 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 , V_24 , V_21 = 0 ;
V_22 = F_25 ( V_42 , L_1 ) ;
V_24 = F_25 ( V_42 , L_6 ) ;
if ( V_22 < 0 || V_24 < 0 )
return - V_43 ;
V_4 = F_26 ( & V_42 -> V_20 , sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_28 = F_27 ( & V_42 -> V_20 , NULL ) ;
if ( F_28 ( V_4 -> V_28 ) ) {
F_8 ( & V_42 -> V_20 , L_7 ) ;
return F_29 ( V_4 -> V_28 ) ;
}
V_4 -> V_22 = V_22 ;
V_4 -> V_24 = V_24 ;
F_30 ( & V_4 -> V_9 ) ;
F_31 ( V_42 , V_4 ) ;
V_21 = F_32 ( V_4 -> V_28 ) ;
if ( V_21 )
return V_21 ;
if ( V_40 == 0 ) {
V_40 = V_46 + ( V_47 << 16 ) ;
F_33 ( & V_42 -> V_20 , L_8
L_9 ) ;
V_32 = 0 ;
}
F_34 ( & V_42 -> V_20 , 1 ) ;
V_6 = F_35 ( & V_42 -> V_20 , V_42 -> V_48 , & V_49 ,
V_50 ) ;
if ( F_28 ( V_6 ) ) {
V_21 = F_29 ( V_6 ) ;
goto V_51;
}
V_4 -> V_6 = V_6 ;
V_10 = V_13 | V_14 ;
return 0 ;
V_51:
F_11 ( V_4 -> V_28 ) ;
return V_21 ;
}
static int F_36 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = F_37 ( V_42 ) ;
if ( V_4 )
F_11 ( V_4 -> V_28 ) ;
return 0 ;
}
static int F_38 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
if ( F_39 ( V_20 ) )
F_40 ( V_4 -> V_24 ) ;
return 0 ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
if ( F_39 ( V_20 ) )
F_42 ( V_4 -> V_24 ) ;
return 0 ;
}
