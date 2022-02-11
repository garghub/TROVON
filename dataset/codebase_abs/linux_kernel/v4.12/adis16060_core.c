static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 2 ] = V_3 ;
V_5 = F_4 ( V_7 -> V_10 , V_7 -> V_9 , 3 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_7 -> V_8 ) ;
return V_5 ;
}
V_5 = F_6 ( V_7 -> V_11 , V_7 -> V_9 , 3 ) ;
if ( ! V_5 )
* V_4 = ( ( V_7 -> V_9 [ 0 ] & 0x3 ) << 12 ) |
( V_7 -> V_9 [ 1 ] << 4 ) |
( ( V_7 -> V_9 [ 2 ] >> 4 ) & 0xF ) ;
F_5 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 const * V_13 ,
int * V_4 , int * V_14 ,
long V_15 )
{
T_2 V_16 = 0 ;
int V_5 ;
switch ( V_15 ) {
case V_17 :
V_5 = F_1 ( V_2 ,
V_13 -> V_18 , & V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_4 = V_16 ;
return V_19 ;
case V_20 :
* V_4 = - 7 ;
* V_14 = 461117 ;
return V_21 ;
case V_22 :
* V_4 = 0 ;
* V_14 = 34000 ;
return V_21 ;
}
return - V_23 ;
}
static int F_8 ( struct V_24 * V_25 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_9 ( & V_25 -> V_26 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_27 ;
F_10 ( V_25 , V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_7 -> V_11 = V_25 ;
F_11 ( & V_7 -> V_8 ) ;
V_2 -> V_28 = V_25 -> V_26 . V_29 -> V_28 ;
V_2 -> V_26 . V_30 = & V_25 -> V_26 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_12 ( V_36 ) ;
V_5 = F_13 ( & V_25 -> V_26 , V_2 ) ;
if ( V_5 )
return V_5 ;
V_38 = V_2 ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 )
{
int V_5 ;
struct V_1 * V_2 = V_38 ;
struct V_6 * V_7 ;
if ( ! V_2 ) {
V_5 = - V_39 ;
goto V_40;
}
V_7 = F_2 ( V_2 ) ;
F_10 ( V_25 , V_2 ) ;
V_7 -> V_10 = V_25 ;
return 0 ;
V_40:
return V_5 ;
}
static int F_15 ( struct V_24 * V_25 )
{
return 0 ;
}
static T_3 int F_16 ( void )
{
int V_5 ;
V_5 = F_17 ( & V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_17 ( & V_42 ) ;
if ( V_5 < 0 ) {
F_18 ( & V_41 ) ;
return V_5 ;
}
return 0 ;
}
static T_4 void F_19 ( void )
{
F_18 ( & V_42 ) ;
F_18 ( & V_41 ) ;
}
