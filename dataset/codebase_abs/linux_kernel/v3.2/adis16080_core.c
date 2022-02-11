static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_6 -> V_8 [ 0 ] = V_3 >> 8 ;
V_6 -> V_8 [ 1 ] = V_3 ;
V_4 = F_4 ( V_6 -> V_9 , V_6 -> V_8 , 2 ) ;
F_5 ( & V_6 -> V_7 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_4 = F_7 ( V_6 -> V_9 , V_6 -> V_8 , 2 ) ;
if ( V_4 == 0 )
* V_3 = ( ( V_6 -> V_8 [ 0 ] & 0xF ) << 8 ) | V_6 -> V_8 [ 1 ] ;
F_5 ( & V_6 -> V_7 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 const * V_11 ,
int * V_3 ,
int * V_12 ,
long V_13 )
{
int V_4 = - V_14 ;
T_1 V_15 ;
F_3 ( & V_2 -> V_16 ) ;
switch ( V_13 ) {
case 0 :
V_4 = F_1 ( V_2 ,
V_11 -> V_17 |
V_18 ) ;
if ( V_4 < 0 )
break;
V_4 = F_6 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
break;
* V_3 = V_15 ;
V_4 = V_19 ;
break;
}
F_5 ( & V_2 -> V_16 ) ;
return V_4 ;
}
static int T_2 F_9 ( struct V_20 * V_21 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
V_4 = - V_22 ;
goto V_23;
}
V_6 = F_2 ( V_2 ) ;
F_11 ( V_21 , V_2 ) ;
V_6 -> V_9 = V_21 ;
F_12 ( & V_6 -> V_7 ) ;
V_2 -> V_24 = V_21 -> V_25 . V_26 -> V_24 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = F_13 ( V_28 ) ;
V_2 -> V_25 . V_30 = & V_21 -> V_25 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_4 = F_14 ( V_2 ) ;
if ( V_4 )
goto V_35;
return 0 ;
V_35:
F_15 ( V_2 ) ;
V_23:
return V_4 ;
}
static int F_16 ( struct V_20 * V_21 )
{
F_17 ( F_18 ( V_21 ) ) ;
F_15 ( F_18 ( V_21 ) ) ;
return 0 ;
}
static T_3 int F_19 ( void )
{
return F_20 ( & V_36 ) ;
}
static T_4 void F_21 ( void )
{
F_22 ( & V_36 ) ;
}
