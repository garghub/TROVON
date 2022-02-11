static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 , V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_3 = F_3 ( V_2 -> V_7 ,
V_2 -> V_8 & ~ V_9 ) ;
if ( V_3 < 0 )
goto V_10;
F_4 ( 125 + 10 ) ;
V_3 = F_5 ( V_2 -> V_11 ) ;
if ( V_3 < 0 )
goto V_10;
V_4 = V_3 ;
V_3 = F_5 ( V_2 -> V_7 ) ;
if ( V_3 < 0 )
goto V_10;
V_5 = V_3 ;
V_3 = F_3 ( V_2 -> V_7 , V_2 -> V_8 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = ( V_4 << 8 ) | V_5 ;
V_10:
F_6 ( & V_2 -> V_6 ) ;
return V_3 ;
}
static int F_7 ( unsigned V_12 )
{
unsigned V_13 [ 11 ] = {
187 , 373 , 560 ,
746 , 933 , 1120 ,
1308 , 1494 ,
1681 , 1868 , 2054 } ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_8 ( V_13 ) ; V_14 ++ )
if ( V_12 <= V_13 [ V_14 ] )
return V_14 ;
return 11 ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int * V_12 , int * V_19 , long V_20 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
int V_3 ;
switch ( V_20 ) {
case V_21 :
case V_22 :
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_20 == V_22 )
* V_12 = F_7 ( V_3 ) ;
else
* V_12 = V_3 ;
return V_23 ;
default:
return - V_24 ;
}
}
static int F_11 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_3 ;
V_16 = F_12 ( & V_26 -> V_29 , sizeof( * V_2 ) ) ;
if ( ! V_16 )
return - V_30 ;
V_2 = F_10 ( V_16 ) ;
F_13 ( V_26 , V_16 ) ;
V_2 -> V_7 = V_26 ;
F_14 ( & V_2 -> V_6 ) ;
V_16 -> V_29 . V_31 = & V_26 -> V_29 ;
V_16 -> V_32 = & V_33 ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = F_8 ( V_35 ) ;
V_16 -> V_37 = V_38 ;
V_16 -> V_39 = V_40 ;
V_2 -> V_11 = F_15 ( V_26 -> V_41 , V_42 ) ;
if ( ! V_2 -> V_11 ) {
F_16 ( & V_26 -> V_29 , L_1 ) ;
return - V_43 ;
}
V_2 -> V_8 = V_44 | V_45 |
V_9 ;
V_3 = F_3 ( V_2 -> V_7 , V_2 -> V_8 ) ;
if ( V_3 < 0 )
goto V_46;
V_3 = F_17 ( V_16 ) ;
if ( V_3 < 0 )
goto V_46;
return V_3 ;
V_46:
F_18 ( V_2 -> V_11 ) ;
return V_3 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = F_20 ( V_26 ) ;
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_21 ( V_16 ) ;
F_18 ( V_2 -> V_11 ) ;
return 0 ;
}
