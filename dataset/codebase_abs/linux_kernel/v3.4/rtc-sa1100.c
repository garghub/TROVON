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
V_21 = F_7 ( V_4 -> V_22 ) ;
if ( V_21 )
goto V_23;
V_21 = F_8 ( V_4 -> V_24 , F_1 , 0 , L_1 , V_20 ) ;
if ( V_21 ) {
F_9 ( V_20 , L_2 , V_4 -> V_24 ) ;
goto V_25;
}
V_21 = F_8 ( V_4 -> V_26 , F_1 , 0 , L_3 , V_20 ) ;
if ( V_21 ) {
F_9 ( V_20 , L_2 , V_4 -> V_26 ) ;
goto V_27;
}
V_6 -> V_28 = V_29 ;
F_10 ( V_6 , NULL , V_29 ) ;
return 0 ;
V_27:
F_11 ( V_4 -> V_24 , V_20 ) ;
V_25:
F_12 ( V_4 -> V_22 ) ;
V_23:
return V_21 ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
F_14 ( & V_4 -> V_9 ) ;
V_10 = 0 ;
F_15 ( & V_4 -> V_9 ) ;
F_11 ( V_4 -> V_26 , V_20 ) ;
F_11 ( V_4 -> V_24 , V_20 ) ;
F_12 ( V_4 -> V_22 ) ;
}
static int F_16 ( struct V_19 * V_20 , unsigned int V_30 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
F_14 ( & V_4 -> V_9 ) ;
if ( V_30 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
F_15 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 , struct V_31 * V_32 )
{
F_18 ( V_33 , V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , struct V_31 * V_32 )
{
unsigned long time ;
int V_21 ;
V_21 = F_20 ( V_32 , & time ) ;
if ( V_21 == 0 )
V_33 = time ;
return V_21 ;
}
static int F_21 ( struct V_19 * V_20 , struct V_34 * V_35 )
{
T_2 V_7 ;
V_7 = V_10 ;
V_35 -> V_30 = ( V_7 & V_11 ) ? 1 : 0 ;
V_35 -> V_36 = ( V_7 & V_13 ) ? 1 : 0 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
unsigned long time ;
int V_21 ;
F_14 ( & V_4 -> V_9 ) ;
V_21 = F_20 ( & V_35 -> time , & time ) ;
if ( V_21 != 0 )
goto V_37;
V_10 = V_10 & ( V_12 | V_11 | V_13 ) ;
V_38 = time ;
if ( V_35 -> V_30 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
V_37:
F_15 ( & V_4 -> V_9 ) ;
return V_21 ;
}
static int F_23 ( struct V_19 * V_20 , struct V_39 * V_40 )
{
F_24 ( V_40 , L_4 , ( T_2 ) V_41 ) ;
F_24 ( V_40 , L_5 , ( T_2 ) V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_24 , V_26 , V_21 = 0 ;
V_24 = F_26 ( V_43 , L_1 ) ;
V_26 = F_26 ( V_43 , L_6 ) ;
if ( V_24 < 0 || V_26 < 0 )
return - V_44 ;
V_4 = F_27 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_22 = F_28 ( & V_43 -> V_20 , NULL ) ;
if ( F_29 ( V_4 -> V_22 ) ) {
F_9 ( & V_43 -> V_20 , L_7 ) ;
V_21 = F_30 ( V_4 -> V_22 ) ;
goto V_47;
}
V_4 -> V_24 = V_24 ;
V_4 -> V_26 = V_26 ;
F_31 ( & V_4 -> V_9 ) ;
F_32 ( V_43 , V_4 ) ;
if ( V_41 == 0 ) {
V_41 = V_48 + ( V_49 << 16 ) ;
F_33 ( & V_43 -> V_20 , L_8
L_9 ) ;
V_33 = 0 ;
}
F_34 ( & V_43 -> V_20 , 1 ) ;
V_6 = F_35 ( V_43 -> V_50 , & V_43 -> V_20 , & V_51 ,
V_52 ) ;
if ( F_29 ( V_6 ) ) {
V_21 = F_30 ( V_6 ) ;
goto V_53;
}
V_4 -> V_6 = V_6 ;
V_10 = V_13 | V_14 ;
return 0 ;
V_53:
F_32 ( V_43 , NULL ) ;
F_36 ( V_4 -> V_22 ) ;
V_47:
F_37 ( V_4 ) ;
return V_21 ;
}
static int F_38 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_39 ( V_43 ) ;
if ( V_4 ) {
F_40 ( V_4 -> V_6 ) ;
F_36 ( V_4 -> V_22 ) ;
F_32 ( V_43 , NULL ) ;
F_37 ( V_4 ) ;
}
return 0 ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
if ( F_42 ( V_20 ) )
F_43 ( V_4 -> V_26 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
if ( F_42 ( V_20 ) )
F_45 ( V_4 -> V_26 ) ;
return 0 ;
}
