static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_7 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
F_2 ( 3000 , 4000 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_8 , int * V_9 )
{
int V_3 ;
T_1 V_10 , V_11 ;
int V_12 , y1 , V_13 ;
unsigned V_14 ;
F_4 ( & V_2 -> V_15 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_16;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_18 ) ;
if ( V_3 < 0 )
goto V_16;
V_10 = V_3 >> 6 ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_19 ) ;
if ( V_3 < 0 )
goto V_16;
V_11 = V_3 >> 6 ;
V_12 = V_2 -> V_20 + ( ( V_2 -> V_21 * V_11 ) >> 11 ) ;
y1 = ( V_2 -> V_22 << 10 ) + V_12 * V_10 ;
V_13 = ( y1 + ( ( V_2 -> V_23 * ( int ) V_11 ) >> 1 ) ) >> 9 ;
V_14 = V_13 * ( 115 - 50 ) / 1023 + ( 50 << 4 ) ;
* V_8 = V_14 >> 4 ;
* V_9 = ( V_14 & 15 ) * ( 1000000 >> 4 ) ;
V_16:
F_5 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
F_4 ( & V_2 -> V_15 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_16;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_19 ) ;
V_16:
F_5 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static int F_7 ( struct V_24 * V_25 ,
struct V_26 const * V_27 ,
int * V_8 , int * V_9 , long V_28 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
int V_3 ;
switch ( V_28 ) {
case V_29 :
V_3 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_30 ;
case V_31 :
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_8 = V_3 >> 6 ;
return V_32 ;
case V_33 :
* V_8 = - 605 ;
* V_9 = 750000 ;
return V_30 ;
case V_34 :
* V_8 = - 186 ;
* V_9 = 915888 ;
return V_30 ;
}
return - V_35 ;
}
int F_9 ( struct V_36 * V_6 , const char * V_37 ,
const struct V_38 * V_4 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_3 ;
V_25 = F_10 ( V_6 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_39 ;
V_2 = F_8 ( V_25 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_4 ;
F_11 ( & V_2 -> V_15 ) ;
V_25 -> V_40 = & V_41 ;
V_25 -> V_37 = V_37 ;
V_25 -> V_6 . V_42 = V_6 ;
V_25 -> V_43 = V_44 ;
V_25 -> V_45 = V_46 ;
V_25 -> V_47 = F_12 ( V_46 ) ;
V_3 = V_2 -> V_4 -> V_48 ( V_2 -> V_6 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_49 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_22 = V_3 ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_20 = V_3 ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_23 = V_3 ;
V_3 = V_2 -> V_4 -> V_17 ( V_2 -> V_6 , V_52 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_21 = V_3 ;
return F_13 ( V_6 , V_25 ) ;
}
