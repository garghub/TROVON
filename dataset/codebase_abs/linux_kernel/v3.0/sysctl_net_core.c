static int F_1 ( T_1 * V_1 , int V_2 ,
void T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
unsigned int V_6 , V_7 ;
int V_8 , V_9 ;
T_1 V_10 = {
. V_11 = & V_7 ,
. V_12 = sizeof( V_7 ) ,
. V_13 = V_1 -> V_13
} ;
struct V_14 * V_15 , * V_16 ;
static F_2 ( V_17 ) ;
F_3 ( & V_17 ) ;
V_15 = F_4 ( V_14 ,
F_5 ( & V_17 ) ) ;
V_7 = V_6 = V_15 ? V_15 -> V_18 + 1 : 0 ;
V_8 = F_6 ( & V_10 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_2 ) {
if ( V_7 ) {
if ( V_7 > 1 << 30 ) {
F_7 ( & V_17 ) ;
return - V_19 ;
}
V_7 = F_8 ( V_7 ) ;
if ( V_7 != V_6 ) {
V_16 =
F_9 ( F_10 ( V_7 ) ) ;
if ( ! V_16 ) {
F_7 ( & V_17 ) ;
return - V_20 ;
}
V_16 -> V_18 = V_7 - 1 ;
} else
V_16 = V_15 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ )
V_16 -> V_21 [ V_9 ] = V_22 ;
} else
V_16 = NULL ;
if ( V_16 != V_15 ) {
F_11 ( V_14 , V_16 ) ;
F_12 () ;
F_13 ( V_15 ) ;
}
}
F_7 ( & V_17 ) ;
return V_8 ;
}
static T_5 int F_14 ( struct V_23 * V_23 )
{
struct T_1 * V_24 ;
V_23 -> V_25 . V_26 = V_27 ;
V_24 = V_28 ;
if ( ! F_15 ( V_23 , & V_29 ) ) {
V_24 = F_16 ( V_24 , sizeof( V_28 ) , V_30 ) ;
if ( V_24 == NULL )
goto V_31;
V_24 [ 0 ] . V_11 = & V_23 -> V_25 . V_26 ;
}
V_23 -> V_25 . V_32 = F_17 ( V_23 ,
V_33 , V_24 ) ;
if ( V_23 -> V_25 . V_32 == NULL )
goto V_34;
return 0 ;
V_34:
if ( V_24 != V_28 )
F_18 ( V_24 ) ;
V_31:
return - V_20 ;
}
static T_6 void F_19 ( struct V_23 * V_23 )
{
struct T_1 * V_24 ;
V_24 = V_23 -> V_25 . V_32 -> V_35 ;
F_20 ( V_23 -> V_25 . V_32 ) ;
F_21 ( V_24 == V_28 ) ;
F_18 ( V_24 ) ;
}
static T_7 int F_22 ( void )
{
static struct T_1 V_36 [ 1 ] ;
F_23 ( V_33 , V_36 ) ;
F_24 ( V_33 , V_37 ) ;
return F_25 ( & V_38 ) ;
}
