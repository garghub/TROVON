static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_6 -> V_7 , V_6 -> V_8 , sizeof( V_6 -> V_8 ) ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 , L_1 ) ;
return V_4 ;
}
if ( V_6 -> V_8 [ 0 ] ) {
F_4 ( & V_2 -> V_9 , L_2 ) ;
return - V_10 ;
}
* V_3 = ( V_6 -> V_8 [ 1 ] << 8 ) | V_6 -> V_8 [ 2 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 const * V_12 ,
int * V_3 , int * V_13 , long V_14 )
{
int V_4 , V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_14 ) {
case V_16 :
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
return V_17 ;
case V_18 :
V_15 = F_6 ( V_6 -> V_19 ) ;
if ( V_15 < 0 )
return - V_10 ;
* V_3 = V_15 / 1000 ;
* V_13 = V_20 ;
return V_21 ;
}
return - V_10 ;
}
static int F_7 ( struct V_22 * V_7 )
{
int V_4 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_8 ( & V_7 -> V_9 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_23 ;
F_9 ( V_7 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 = V_7 ;
V_2 -> V_9 . V_24 = & V_7 -> V_9 ;
V_2 -> V_9 . V_25 = V_7 -> V_9 . V_25 ;
V_2 -> V_26 = L_3 ;
V_2 -> V_14 = & V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_31 ,
V_2 -> V_32 = F_10 ( V_31 ) ,
V_6 -> V_19 = F_11 ( & V_7 -> V_9 , L_4 ) ;
if ( F_12 ( V_6 -> V_19 ) )
return F_13 ( V_6 -> V_19 ) ;
V_4 = F_14 ( V_6 -> V_19 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_15 ( V_2 ) ;
if ( V_4 )
goto V_33;
return 0 ;
V_33:
F_16 ( V_6 -> V_19 ) ;
return V_4 ;
}
static int F_17 ( struct V_22 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
F_16 ( V_6 -> V_19 ) ;
return 0 ;
}
