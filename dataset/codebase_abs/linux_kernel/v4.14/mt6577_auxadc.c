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
static int T_3 F_12 ( struct V_34 * V_21 )
{
struct V_5 * V_6 = F_13 ( V_21 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
int V_10 ;
V_10 = F_14 ( V_12 -> V_35 ) ;
if ( V_10 ) {
F_15 ( L_5 ) ;
return V_10 ;
}
F_1 ( V_12 -> V_13 + V_36 ,
V_37 , 0 ) ;
F_16 ( V_38 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_34 * V_21 )
{
struct V_5 * V_6 = F_13 ( V_21 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
F_1 ( V_12 -> V_13 + V_36 ,
0 , V_37 ) ;
F_18 ( V_12 -> V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_11 * V_12 ;
unsigned long V_41 ;
struct V_42 * V_43 ;
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_20 ( & V_40 -> V_21 , sizeof( * V_12 ) ) ;
if ( ! V_6 )
return - V_44 ;
V_12 = F_5 ( V_6 ) ;
V_6 -> V_21 . V_22 = & V_40 -> V_21 ;
V_6 -> V_45 = F_21 ( & V_40 -> V_21 ) ;
V_6 -> V_30 = & V_46 ;
V_6 -> V_47 = V_48 ;
V_6 -> V_49 = V_50 ;
V_6 -> V_51 = F_22 ( V_50 ) ;
V_43 = F_23 ( V_40 , V_52 , 0 ) ;
V_12 -> V_13 = F_24 ( & V_40 -> V_21 , V_43 ) ;
if ( F_25 ( V_12 -> V_13 ) ) {
F_8 ( & V_40 -> V_21 , L_6 ) ;
return F_26 ( V_12 -> V_13 ) ;
}
V_12 -> V_35 = F_27 ( & V_40 -> V_21 , L_7 ) ;
if ( F_25 ( V_12 -> V_35 ) ) {
F_8 ( & V_40 -> V_21 , L_8 ) ;
return F_26 ( V_12 -> V_35 ) ;
}
V_10 = F_14 ( V_12 -> V_35 ) ;
if ( V_10 ) {
F_8 ( & V_40 -> V_21 , L_5 ) ;
return V_10 ;
}
V_41 = F_28 ( V_12 -> V_35 ) ;
if ( ! V_41 ) {
V_10 = - V_33 ;
F_8 ( & V_40 -> V_21 , L_9 ) ;
goto V_53;
}
F_29 ( & V_12 -> V_16 ) ;
F_1 ( V_12 -> V_13 + V_36 ,
V_37 , 0 ) ;
F_16 ( V_38 ) ;
F_30 ( V_40 , V_6 ) ;
V_10 = F_31 ( V_6 ) ;
if ( V_10 < 0 ) {
F_8 ( & V_40 -> V_21 , L_10 ) ;
goto V_54;
}
return 0 ;
V_54:
F_1 ( V_12 -> V_13 + V_36 ,
0 , V_37 ) ;
V_53:
F_18 ( V_12 -> V_35 ) ;
return V_10 ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_33 ( V_40 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
F_34 ( V_6 ) ;
F_1 ( V_12 -> V_13 + V_36 ,
0 , V_37 ) ;
F_18 ( V_12 -> V_35 ) ;
return 0 ;
}
