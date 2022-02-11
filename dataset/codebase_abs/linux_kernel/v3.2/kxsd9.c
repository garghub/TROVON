static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_8 = false ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ )
if ( V_3 == V_9 [ V_5 ] ) {
V_8 = true ;
break;
}
if ( ! V_8 )
return - V_10 ;
F_3 ( & V_7 -> V_11 ) ;
V_4 = F_4 ( V_7 -> V_12 , F_5 ( V_13 ) ) ;
if ( V_4 )
goto V_14;
V_7 -> V_15 [ 0 ] = F_6 ( V_13 ) ;
V_7 -> V_15 [ 1 ] = ( V_4 & ~ V_16 ) | V_5 ;
V_4 = F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
V_14:
F_8 ( & V_7 -> V_11 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_18 V_19 ;
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 V_21 [] = {
{
. V_22 = 8 ,
. V_23 = 1 ,
. V_24 = 200 ,
. V_25 = V_7 -> V_15 ,
} , {
. V_22 = 8 ,
. V_23 = 2 ,
. V_26 = V_7 -> V_27 ,
} ,
} ;
F_3 ( & V_7 -> V_11 ) ;
V_7 -> V_15 [ 0 ] = F_5 ( V_17 ) ;
F_10 ( & V_19 ) ;
F_11 ( & V_21 [ 0 ] , & V_19 ) ;
F_11 ( & V_21 [ 1 ] , & V_19 ) ;
V_4 = F_12 ( V_7 -> V_12 , & V_19 ) ;
if ( V_4 )
return V_4 ;
return ( ( ( V_28 ) ( V_7 -> V_27 [ 0 ] ) ) << 8 ) | ( V_7 -> V_27 [ 1 ] & 0xF0 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_29 const * V_30 ,
int V_31 ,
int V_32 ,
long V_33 )
{
int V_4 = - V_10 ;
if ( V_33 == ( 1 << V_34 ) ) {
if ( V_31 )
return - V_10 ;
V_4 = F_1 ( V_2 , V_32 ) ;
}
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_29 const * V_30 ,
int * V_31 , int * V_32 , long V_33 )
{
int V_4 = - V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_33 ) {
case 0 :
V_4 = F_9 ( V_2 , V_30 -> V_17 ) ;
if ( V_4 < 0 )
goto V_14;
* V_31 = V_4 ;
break;
case ( 1 << V_34 ) :
V_4 = F_4 ( V_7 -> V_12 , F_5 ( V_13 ) ) ;
if ( V_4 )
goto V_14;
* V_32 = V_9 [ V_4 & V_16 ] ;
V_4 = V_35 ;
break;
} ;
V_14:
return V_4 ;
}
static int T_2 F_15 ( struct V_6 * V_7 )
{
int V_4 ;
V_7 -> V_15 [ 0 ] = 0x0d ;
V_7 -> V_15 [ 1 ] = 0x40 ;
V_4 = F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
if ( V_4 )
return V_4 ;
V_7 -> V_15 [ 0 ] = 0x0c ;
V_7 -> V_15 [ 1 ] = 0x9b ;
return F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
}
static int T_2 F_16 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_4 = 0 ;
V_2 = F_17 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_4 = - V_38 ;
goto V_14;
}
V_7 = F_2 ( V_2 ) ;
F_18 ( V_37 , V_2 ) ;
V_7 -> V_12 = V_37 ;
F_19 ( & V_7 -> V_11 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = F_20 ( V_40 ) ;
V_2 -> V_42 = F_21 ( V_37 ) -> V_42 ;
V_2 -> V_43 . V_44 = & V_37 -> V_43 ;
V_2 -> V_45 = & V_46 ;
V_2 -> V_47 = V_48 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 )
goto V_49;
V_37 -> V_50 = V_51 ;
F_23 ( V_37 ) ;
F_15 ( V_7 ) ;
return 0 ;
V_49:
F_24 ( V_2 ) ;
V_14:
return V_4 ;
}
static int T_3 F_25 ( struct V_36 * V_37 )
{
F_26 ( F_27 ( V_37 ) ) ;
F_24 ( F_27 ( V_37 ) ) ;
return 0 ;
}
static T_4 int F_28 ( void )
{
return F_29 ( & V_52 ) ;
}
static T_5 void F_30 ( void )
{
F_31 ( & V_52 ) ;
}
