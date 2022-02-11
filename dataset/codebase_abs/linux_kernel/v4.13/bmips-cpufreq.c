static int F_1 ( unsigned int V_1 )
{
return V_2 * V_1 / 1000 ;
}
static struct V_3 *
F_2 ( const struct V_4 * V_5 )
{
struct V_3 * V_6 ;
unsigned long V_7 ;
int V_8 ;
V_7 = F_1 ( V_9 -> V_1 ) ;
V_6 = F_3 ( ( V_9 -> V_10 + 1 ) * sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return F_4 ( - V_12 ) ;
for ( V_8 = 0 ; V_8 < V_9 -> V_10 ; V_8 ++ ) {
V_6 [ V_8 ] . V_13 = V_7 / ( 1 << V_8 ) ;
V_6 [ V_8 ] . V_14 = V_8 ;
}
V_6 [ V_8 ] . V_13 = V_15 ;
return V_6 ;
}
static unsigned int F_5 ( unsigned int V_16 )
{
unsigned int div ;
T_1 V_17 ;
switch ( V_9 -> V_18 ) {
case V_19 :
case V_20 :
V_17 = F_6 () ;
div = ( ( V_17 >> V_21 ) & V_22 ) ;
break;
default:
div = 0 ;
}
return F_1 ( V_9 -> V_1 ) / ( 1 << div ) ;
}
static int F_7 ( struct V_4 * V_5 ,
unsigned int V_23 )
{
unsigned int div = V_5 -> V_24 [ V_23 ] . V_14 ;
switch ( V_9 -> V_18 ) {
case V_19 :
case V_20 :
F_8 ( V_22 << V_21 ,
( 1 << V_25 ) |
( div << V_21 ) ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_3 * V_24 ;
int V_27 ;
V_24 = F_2 ( V_5 ) ;
if ( F_12 ( V_24 ) ) {
V_27 = F_13 ( V_24 ) ;
F_14 ( L_1 ,
V_28 , V_27 ) ;
return V_27 ;
}
V_27 = F_15 ( V_5 , V_24 , V_29 ) ;
if ( V_27 )
F_9 ( V_5 ) ;
else
F_16 ( L_2 , V_28 ) ;
return V_27 ;
}
static int T_2 F_17 ( void )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
for ( V_31 = V_34 ; V_31 -> V_35 ; V_31 ++ ) {
V_33 = F_18 ( NULL , L_3 , V_31 -> V_35 ) ;
if ( V_33 ) {
F_19 ( V_33 ) ;
V_9 = V_31 ;
break;
}
}
if ( ! V_31 -> V_35 )
return - V_36 ;
return F_20 ( & V_37 ) ;
}
