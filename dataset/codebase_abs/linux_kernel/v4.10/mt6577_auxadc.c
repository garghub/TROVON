static inline void F_1 ( void T_1 * V_1 ,
T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 ) ;
V_4 |= V_2 ;
V_4 &= ~ V_3 ;
F_3 ( V_4 , V_1 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 const * V_8 )
{
T_2 V_4 ;
void T_1 * V_9 ;
int V_10 ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
V_9 = V_12 -> V_13 + V_14 +
V_8 -> V_15 * 0x04 ;
F_6 ( & V_12 -> V_16 ) ;
F_1 ( V_12 -> V_13 + V_17 ,
0 , 1 << V_8 -> V_15 ) ;
V_10 = F_7 ( V_9 , V_4 ,
( ( V_4 & V_18 ) == 0 ) ,
V_19 ,
V_20 ) ;
if ( V_10 < 0 ) {
F_8 ( V_6 -> V_21 . V_22 ,
L_1 ,
V_8 -> V_15 ) ;
goto V_23;
}
F_1 ( V_12 -> V_13 + V_17 ,
1 << V_8 -> V_15 , 0 ) ;
F_9 ( V_24 ) ;
V_10 = F_7 ( V_12 -> V_13 + V_25 , V_4 ,
( ( V_4 & V_26 ) == 0 ) ,
V_19 ,
V_20 ) ;
if ( V_10 < 0 ) {
F_8 ( V_6 -> V_21 . V_22 ,
L_2 ) ;
goto V_23;
}
V_10 = F_7 ( V_9 , V_4 ,
( ( V_4 & V_18 ) != 0 ) ,
V_19 ,
V_20 ) ;
if ( V_10 < 0 ) {
F_8 ( V_6 -> V_21 . V_22 ,
L_3 ,
V_8 -> V_15 ) ;
goto V_23;
}
V_4 = F_2 ( V_9 ) & V_27 ;
F_10 ( & V_12 -> V_16 ) ;
return V_4 ;
V_23:
F_10 ( & V_12 -> V_16 ) ;
return - V_28 ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_7 const * V_8 ,
int * V_4 ,
int * V_29 ,
long V_30 )
{
switch ( V_30 ) {
case V_31 :
* V_4 = F_4 ( V_6 , V_8 ) ;
if ( * V_4 < 0 ) {
F_8 ( V_6 -> V_21 . V_22 ,
L_4 ,
V_8 -> V_15 ) ;
return * V_4 ;
}
return V_32 ;
default:
return - V_33 ;
}
}
static int F_12 ( struct V_34 * V_35 )
{
struct V_11 * V_12 ;
unsigned long V_36 ;
struct V_37 * V_38 ;
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_13 ( & V_35 -> V_21 , sizeof( * V_12 ) ) ;
if ( ! V_6 )
return - V_39 ;
V_12 = F_5 ( V_6 ) ;
V_6 -> V_21 . V_22 = & V_35 -> V_21 ;
V_6 -> V_40 = F_14 ( & V_35 -> V_21 ) ;
V_6 -> V_30 = & V_41 ;
V_6 -> V_42 = V_43 ;
V_6 -> V_44 = V_45 ;
V_6 -> V_46 = F_15 ( V_45 ) ;
V_38 = F_16 ( V_35 , V_47 , 0 ) ;
V_12 -> V_13 = F_17 ( & V_35 -> V_21 , V_38 ) ;
if ( F_18 ( V_12 -> V_13 ) ) {
F_8 ( & V_35 -> V_21 , L_5 ) ;
return F_19 ( V_12 -> V_13 ) ;
}
V_12 -> V_48 = F_20 ( & V_35 -> V_21 , L_6 ) ;
if ( F_18 ( V_12 -> V_48 ) ) {
F_8 ( & V_35 -> V_21 , L_7 ) ;
return F_19 ( V_12 -> V_48 ) ;
}
V_10 = F_21 ( V_12 -> V_48 ) ;
if ( V_10 ) {
F_8 ( & V_35 -> V_21 , L_8 ) ;
return V_10 ;
}
V_36 = F_22 ( V_12 -> V_48 ) ;
if ( ! V_36 ) {
V_10 = - V_33 ;
F_8 ( & V_35 -> V_21 , L_9 ) ;
goto V_49;
}
F_23 ( & V_12 -> V_16 ) ;
F_1 ( V_12 -> V_13 + V_50 ,
V_51 , 0 ) ;
F_24 ( V_52 ) ;
F_25 ( V_35 , V_6 ) ;
V_10 = F_26 ( V_6 ) ;
if ( V_10 < 0 ) {
F_8 ( & V_35 -> V_21 , L_10 ) ;
goto V_53;
}
return 0 ;
V_53:
F_1 ( V_12 -> V_13 + V_50 ,
0 , V_51 ) ;
V_49:
F_27 ( V_12 -> V_48 ) ;
return V_10 ;
}
static int F_28 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = F_29 ( V_35 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
F_30 ( V_6 ) ;
F_1 ( V_12 -> V_13 + V_50 ,
0 , V_51 ) ;
F_27 ( V_12 -> V_48 ) ;
return 0 ;
}
