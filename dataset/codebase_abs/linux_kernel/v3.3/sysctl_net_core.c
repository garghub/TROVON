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
if ( V_16 )
F_12 ( & V_23 ) ;
if ( V_15 ) {
F_13 ( & V_23 ) ;
F_14 () ;
F_15 ( V_15 ) ;
}
}
}
F_7 ( & V_17 ) ;
return V_8 ;
}
static T_5 int F_16 ( struct V_24 * V_24 )
{
struct T_1 * V_25 ;
V_24 -> V_26 . V_27 = V_28 ;
V_25 = V_29 ;
if ( ! F_17 ( V_24 , & V_30 ) ) {
V_25 = F_18 ( V_25 , sizeof( V_29 ) , V_31 ) ;
if ( V_25 == NULL )
goto V_32;
V_25 [ 0 ] . V_11 = & V_24 -> V_26 . V_27 ;
}
V_24 -> V_26 . V_33 = F_19 ( V_24 ,
V_34 , V_25 ) ;
if ( V_24 -> V_26 . V_33 == NULL )
goto V_35;
return 0 ;
V_35:
if ( V_25 != V_29 )
F_20 ( V_25 ) ;
V_32:
return - V_20 ;
}
static T_6 void F_21 ( struct V_24 * V_24 )
{
struct T_1 * V_25 ;
V_25 = V_24 -> V_26 . V_33 -> V_36 ;
F_22 ( V_24 -> V_26 . V_33 ) ;
F_23 ( V_25 == V_29 ) ;
F_20 ( V_25 ) ;
}
static T_7 int F_24 ( void )
{
static struct T_1 V_37 [ 1 ] ;
F_25 ( V_34 , V_37 ) ;
F_26 ( V_34 , V_38 ) ;
return F_27 ( & V_39 ) ;
}
