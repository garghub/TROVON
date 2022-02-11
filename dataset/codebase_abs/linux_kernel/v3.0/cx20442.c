static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_4 ;
if ( V_3 >= V_2 -> V_5 -> V_6 )
return - V_7 ;
return V_4 [ V_3 ] ;
}
static int F_2 ( T_1 V_8 )
{
switch ( V_8 & ~ ( 1 << V_9 ) ) {
case 0 :
return V_10 ;
case ( 1 << V_11 ) :
case ( 1 << V_12 ) :
case ( 1 << V_11 ) | ( 1 << V_12 ) :
return V_13 ;
case ( 1 << V_14 ) :
case ( 1 << V_15 ) :
case ( 1 << V_14 ) | ( 1 << V_15 ) :
return V_16 ;
case ( 1 << V_14 ) | ( 1 << V_12 ) :
return V_17 ;
}
return - V_7 ;
}
static int F_3 ( T_1 V_8 )
{
switch ( V_8 & ~ ( 1 << V_9 ) ) {
case ( 1 << V_11 ) :
case ( 1 << V_12 ) :
case ( 1 << V_11 ) | ( 1 << V_12 ) :
return ( bool ) ( V_8 & ( 1 << V_9 ) ) ;
}
return ( V_8 & ( 1 << V_9 ) ) ? - V_7 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_1 * V_4 = V_2 -> V_4 ;
int V_20 , V_21 , V_22 , V_23 ;
char V_24 [ 18 ] ;
if ( V_3 >= V_2 -> V_5 -> V_6 )
return - V_7 ;
if ( ! V_2 -> V_25 || ! V_19 -> V_26 )
return - V_27 ;
V_22 = V_4 [ V_3 ] ;
V_4 [ V_3 ] = V_8 ;
V_20 = F_2 ( V_8 ) ;
if ( V_20 < 0 )
return V_20 ;
V_21 = F_3 ( V_8 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ( V_20 == V_10 ) ||
( V_20 == F_2 ( V_22 ) ) ) {
if ( V_21 == F_3 ( V_22 ) )
return 0 ;
V_23 = snprintf ( V_24 , F_6 ( V_24 ) , L_1 , V_21 ) ;
} else if ( V_21 == F_3 ( V_22 ) )
V_23 = snprintf ( V_24 , F_6 ( V_24 ) , L_2 , V_20 ) ;
else
V_23 = snprintf ( V_24 , F_6 ( V_24 ) ,
L_3 , V_20 , V_21 ) ;
if ( F_7 ( V_23 > ( F_6 ( V_24 ) - 1 ) ) )
return - V_28 ;
F_8 ( V_2 -> V_29 , L_4 , V_30 , V_24 ) ;
if ( V_2 -> V_25 ( V_19 -> V_26 , V_24 , V_23 ) != V_23 )
return - V_27 ;
return 0 ;
}
static int F_9 ( struct V_31 * V_32 )
{
int V_33 , V_23 = strlen ( V_34 ) ;
if ( ! V_32 -> V_35 -> V_36 )
return - V_7 ;
if ( ! V_32 -> V_37 )
return - V_38 ;
if ( V_32 -> V_35 -> V_36 ( V_32 , V_34 , V_23 ) != V_23 ) {
V_33 = - V_27 ;
goto V_39;
}
return 0 ;
V_39:
V_32 -> V_37 = NULL ;
return V_33 ;
}
static void F_10 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_37 ;
struct V_18 * V_19 ;
V_32 -> V_37 = NULL ;
if ( ! V_2 )
return;
V_19 = F_5 ( V_2 ) ;
V_2 -> V_25 = NULL ;
V_19 -> V_26 = NULL ;
V_2 -> V_40 -> V_41 = 0 ;
}
static int F_11 ( struct V_31 * V_32 )
{
F_10 ( V_32 ) ;
return 0 ;
}
static void F_12 ( struct V_31 * V_32 ,
const unsigned char * V_42 , char * V_43 , int V_44 )
{
struct V_1 * V_2 = V_32 -> V_37 ;
struct V_18 * V_19 ;
if ( ! V_2 )
return;
V_19 = F_5 ( V_2 ) ;
if ( ! V_19 -> V_26 ) {
V_19 -> V_26 = V_32 ;
V_2 -> V_25 = ( V_45 ) V_32 -> V_35 -> V_36 ;
V_2 -> V_40 -> V_41 = 1 ;
}
}
static void F_13 ( struct V_31 * V_32 )
{
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
V_19 = F_15 ( sizeof( struct V_18 ) , V_46 ) ;
if ( V_19 == NULL )
return - V_28 ;
F_16 ( V_2 , V_19 ) ;
V_19 -> V_26 = NULL ;
V_2 -> V_25 = NULL ;
V_2 -> V_40 -> V_41 = 0 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
if ( V_19 -> V_26 ) {
struct V_31 * V_32 = V_19 -> V_26 ;
F_18 ( V_32 ) ;
}
F_19 ( V_19 ) ;
return 0 ;
}
static int F_20 ( struct V_47 * V_48 )
{
return F_21 ( & V_48 -> V_29 ,
& V_49 , & V_50 , 1 ) ;
}
static int T_2 F_22 ( struct V_47 * V_48 )
{
F_23 ( & V_48 -> V_29 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_51 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_51 ) ;
}
