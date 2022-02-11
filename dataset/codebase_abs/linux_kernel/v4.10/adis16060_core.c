static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_6 -> V_8 [ 2 ] = V_3 ;
V_4 = F_4 ( V_6 -> V_9 , V_6 -> V_8 , 3 ) ;
F_5 ( & V_6 -> V_7 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_4 = F_7 ( V_6 -> V_10 , V_6 -> V_8 , 3 ) ;
if ( ! V_4 )
* V_3 = ( ( V_6 -> V_8 [ 0 ] & 0x3 ) << 12 ) |
( V_6 -> V_8 [ 1 ] << 4 ) |
( ( V_6 -> V_8 [ 2 ] >> 4 ) & 0xF ) ;
F_5 ( & V_6 -> V_7 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_11 const * V_12 ,
int * V_3 , int * V_13 ,
long V_14 )
{
T_2 V_15 = 0 ;
int V_4 ;
switch ( V_14 ) {
case V_16 :
F_3 ( & V_2 -> V_17 ) ;
V_4 = F_1 ( V_2 , V_12 -> V_18 ) ;
if ( V_4 < 0 )
goto V_19;
V_4 = F_6 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
goto V_19;
F_5 ( & V_2 -> V_17 ) ;
* V_3 = V_15 ;
return V_20 ;
case V_21 :
* V_3 = - 7 ;
* V_13 = 461117 ;
return V_22 ;
case V_23 :
* V_3 = 0 ;
* V_13 = 34000 ;
return V_22 ;
}
return - V_24 ;
V_19:
F_5 ( & V_2 -> V_17 ) ;
return V_4 ;
}
static int F_9 ( struct V_25 * V_26 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_10 ( & V_26 -> V_27 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_28 ;
F_11 ( V_26 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_10 = V_26 ;
F_12 ( & V_6 -> V_7 ) ;
V_2 -> V_29 = V_26 -> V_27 . V_30 -> V_29 ;
V_2 -> V_27 . V_31 = & V_26 -> V_27 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_13 ( V_37 ) ;
V_4 = F_14 ( & V_26 -> V_27 , V_2 ) ;
if ( V_4 )
return V_4 ;
V_39 = V_2 ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 )
{
int V_4 ;
struct V_1 * V_2 = V_39 ;
struct V_5 * V_6 ;
if ( ! V_2 ) {
V_4 = - V_40 ;
goto V_41;
}
V_6 = F_2 ( V_2 ) ;
F_11 ( V_26 , V_2 ) ;
V_6 -> V_9 = V_26 ;
return 0 ;
V_41:
return V_4 ;
}
static int F_16 ( struct V_25 * V_26 )
{
return 0 ;
}
static T_3 int F_17 ( void )
{
int V_4 ;
V_4 = F_18 ( & V_42 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_18 ( & V_43 ) ;
if ( V_4 < 0 ) {
F_19 ( & V_42 ) ;
return V_4 ;
}
return 0 ;
}
static T_4 void F_20 ( void )
{
F_19 ( & V_43 ) ;
F_19 ( & V_42 ) ;
}
