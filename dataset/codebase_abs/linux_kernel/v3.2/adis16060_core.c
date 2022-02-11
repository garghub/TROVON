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
if ( V_4 == 0 )
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
case 0 :
F_3 ( & V_2 -> V_16 ) ;
V_4 = F_1 ( V_2 , V_12 -> V_17 ) ;
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_16 ) ;
return V_4 ;
}
V_4 = F_6 ( V_2 , & V_15 ) ;
F_5 ( & V_2 -> V_16 ) ;
* V_3 = V_15 ;
return V_18 ;
case ( 1 << V_19 ) :
* V_3 = - 7 ;
* V_13 = 461117 ;
return V_20 ;
case ( 1 << V_21 ) :
* V_3 = 0 ;
* V_13 = 34000 ;
return V_20 ;
}
return - V_22 ;
}
static int T_3 F_9 ( struct V_23 * V_24 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
V_4 = - V_25 ;
goto V_26;
}
F_11 ( V_24 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_10 = V_24 ;
F_12 ( & V_6 -> V_7 ) ;
V_2 -> V_27 = V_24 -> V_28 . V_29 -> V_27 ;
V_2 -> V_28 . V_30 = & V_24 -> V_28 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_13 ( V_36 ) ;
V_4 = F_14 ( V_2 ) ;
if ( V_4 )
goto V_38;
V_39 = V_2 ;
return 0 ;
V_38:
F_15 ( V_2 ) ;
V_26:
return V_4 ;
}
static int F_16 ( struct V_23 * V_24 )
{
F_17 ( F_18 ( V_24 ) ) ;
F_15 ( F_18 ( V_24 ) ) ;
return 0 ;
}
static int T_3 F_19 ( struct V_23 * V_24 )
{
int V_4 ;
struct V_1 * V_2 = V_39 ;
struct V_5 * V_6 ;
if ( ! V_2 ) {
V_4 = - V_40 ;
goto V_26;
}
V_6 = F_2 ( V_2 ) ;
F_11 ( V_24 , V_2 ) ;
V_6 -> V_9 = V_24 ;
return 0 ;
V_26:
return V_4 ;
}
static int F_20 ( struct V_23 * V_24 )
{
return 0 ;
}
static T_4 int F_21 ( void )
{
int V_4 ;
V_4 = F_22 ( & V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_22 ( & V_42 ) ;
if ( V_4 < 0 ) {
F_23 ( & V_41 ) ;
return V_4 ;
}
return 0 ;
}
static T_5 void F_24 ( void )
{
F_23 ( & V_42 ) ;
F_23 ( & V_41 ) ;
}
