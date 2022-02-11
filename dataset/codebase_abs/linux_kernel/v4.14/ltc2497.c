static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 () , V_2 -> V_4 ) ;
if ( V_3 < V_5 ) {
if ( F_4 (
V_5 - V_3 ) )
return - V_6 ;
return 0 ;
}
if ( V_3 - V_5 <= 0 ) {
return 0 ;
}
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_7 , int * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 || V_2 -> V_12 != V_7 ) {
V_11 = F_6 ( V_2 -> V_10 ,
V_13 | V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_12 = V_7 ;
if ( F_4 ( V_5 ) )
return - V_6 ;
}
V_11 = F_7 ( V_10 , ( char * ) & V_2 -> V_14 , 3 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_10 -> V_15 , L_1 ) ;
return V_11 ;
}
V_2 -> V_4 = F_3 () ;
* V_8 = ( F_9 ( V_2 -> V_14 ) >> 14 ) - ( 1 << 17 ) ;
return V_11 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int * V_8 , int * V_20 , long V_21 )
{
struct V_1 * V_2 = F_11 ( V_17 ) ;
int V_11 ;
switch ( V_21 ) {
case V_22 :
F_12 ( & V_17 -> V_23 ) ;
V_11 = F_5 ( V_2 , V_19 -> V_7 , V_8 ) ;
F_13 ( & V_17 -> V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_24 ;
case V_25 :
V_11 = F_14 ( V_2 -> V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_8 = V_11 / 1000 ;
* V_20 = 17 ;
return V_27 ;
default:
return - V_28 ;
}
}
static int F_15 ( struct V_9 * V_10 ,
const struct V_29 * V_30 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_11 ;
if ( ! F_16 ( V_10 -> V_33 , V_34 |
V_35 ) )
return - V_36 ;
V_17 = F_17 ( & V_10 -> V_15 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_37 ;
V_2 = F_11 ( V_17 ) ;
F_18 ( V_10 , V_17 ) ;
V_2 -> V_10 = V_10 ;
V_17 -> V_15 . V_38 = & V_10 -> V_15 ;
V_17 -> V_39 = V_30 -> V_39 ;
V_17 -> V_40 = & V_41 ;
V_17 -> V_42 = V_43 ;
V_17 -> V_44 = V_45 ;
V_17 -> V_46 = F_19 ( V_45 ) ;
V_2 -> V_26 = F_20 ( & V_10 -> V_15 , L_2 ) ;
if ( F_21 ( V_2 -> V_26 ) )
return F_22 ( V_2 -> V_26 ) ;
V_11 = F_23 ( V_2 -> V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_10 -> V_15 . V_47 ) {
V_32 = ( (struct V_31 * ) V_10 -> V_15 . V_47 ) ;
V_11 = F_24 ( V_17 , V_32 ) ;
if ( V_11 ) {
F_8 ( & V_17 -> V_15 , L_3 , V_11 ) ;
goto V_48;
}
}
V_11 = F_6 ( V_2 -> V_10 , V_49 ) ;
if ( V_11 < 0 )
goto V_50;
V_2 -> V_12 = V_49 ;
V_2 -> V_4 = F_3 () ;
V_11 = F_25 ( V_17 ) ;
if ( V_11 < 0 )
goto V_50;
return 0 ;
V_50:
F_26 ( V_17 ) ;
V_48:
F_27 ( V_2 -> V_26 ) ;
return V_11 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_29 ( V_10 ) ;
struct V_1 * V_2 = F_11 ( V_17 ) ;
F_26 ( V_17 ) ;
F_30 ( V_17 ) ;
F_27 ( V_2 -> V_26 ) ;
return 0 ;
}
