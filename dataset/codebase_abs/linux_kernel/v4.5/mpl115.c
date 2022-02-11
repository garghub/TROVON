static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 -> V_4 , V_5 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( 3000 , 4000 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int * V_6 , int * V_7 )
{
int V_3 ;
T_1 V_8 , V_9 ;
int V_10 , y1 , V_11 ;
unsigned V_12 ;
F_5 ( & V_2 -> V_13 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_14;
V_3 = F_6 ( V_2 -> V_4 , V_15 ) ;
if ( V_3 < 0 )
goto V_14;
V_8 = V_3 >> 6 ;
V_3 = F_6 ( V_2 -> V_4 , V_16 ) ;
if ( V_3 < 0 )
goto V_14;
V_9 = V_3 >> 6 ;
V_10 = V_2 -> V_17 + ( ( V_2 -> V_18 * V_9 ) >> 11 ) ;
y1 = ( V_2 -> V_19 << 10 ) + V_10 * V_8 ;
V_11 = ( y1 + ( ( V_2 -> V_20 * ( int ) V_9 ) >> 1 ) ) >> 9 ;
V_12 = V_11 * ( 115 - 50 ) / 1023 + ( 50 << 4 ) ;
* V_6 = V_12 >> 4 ;
* V_7 = ( V_12 & 15 ) * ( 1000000 >> 4 ) ;
V_14:
F_7 ( & V_2 -> V_13 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
F_5 ( & V_2 -> V_13 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_14;
V_3 = F_6 ( V_2 -> V_4 , V_16 ) ;
V_14:
F_7 ( & V_2 -> V_13 ) ;
return V_3 ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_23 const * V_24 ,
int * V_6 , int * V_7 , long V_25 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_3 ;
switch ( V_25 ) {
case V_26 :
V_3 = F_4 ( V_2 , V_6 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_27 ;
case V_28 :
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_6 = V_3 >> 6 ;
return V_29 ;
case V_30 :
* V_6 = - 605 ;
* V_7 = 750000 ;
return V_27 ;
case V_31 :
* V_6 = - 186 ;
* V_7 = 915888 ;
return V_27 ;
}
return - V_32 ;
}
static int F_11 ( struct V_33 * V_4 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_3 ;
if ( ! F_12 ( V_4 -> V_36 , V_37 ) )
return - V_38 ;
V_22 = F_13 ( & V_4 -> V_39 , sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_40 ;
V_2 = F_10 ( V_22 ) ;
V_2 -> V_4 = V_4 ;
F_14 ( & V_2 -> V_13 ) ;
F_15 ( V_4 , V_22 ) ;
V_22 -> V_41 = & V_42 ;
V_22 -> V_43 = V_35 -> V_43 ;
V_22 -> V_39 . V_44 = & V_4 -> V_39 ;
V_22 -> V_45 = V_46 ;
V_22 -> V_47 = V_48 ;
V_22 -> V_49 = F_16 ( V_48 ) ;
V_3 = F_6 ( V_2 -> V_4 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_19 = V_3 ;
V_3 = F_6 ( V_2 -> V_4 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_17 = V_3 ;
V_3 = F_6 ( V_2 -> V_4 , V_52 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_20 = V_3 ;
V_3 = F_6 ( V_2 -> V_4 , V_53 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_18 = V_3 ;
return F_17 ( & V_4 -> V_39 , V_22 ) ;
}
