static void * F_1 ( struct V_1 * V_2 , void * V_3 ,
int V_4 )
{
struct V_5 * V_5 = V_3 ;
struct V_6 * V_7 ;
int V_8 = V_2 -> V_9 ;
int V_10 , V_11 ;
if ( V_5 ) {
if ( V_4 < sizeof( * V_5 ) ) {
V_10 = - V_12 ;
goto V_13;
}
V_8 = F_2 ( V_5 -> V_14 ) ;
V_11 = F_3 ( V_8 ) - 1 ;
if ( V_8 != ( 1 << V_11 ) && V_8 != ( 1 << V_11 ) +
( 1 << ( V_11 + 1 ) ) ) {
V_10 = - V_12 ;
goto V_13;
}
}
V_8 = F_4 ( int , V_8 , V_15 ) ;
V_7 = F_5 ( sizeof( * V_7 ) , V_16 ) ;
if ( V_7 == NULL ) {
V_10 = - V_17 ;
goto V_13;
}
V_7 -> V_18 = F_6 ( V_19 , V_8 ) ;
if ( V_7 -> V_18 == NULL ) {
F_7 ( V_7 ) ;
V_10 = - V_17 ;
goto V_13;
}
return V_7 ;
V_13:
ERROR ( L_1 ) ;
return F_8 ( V_10 ) ;
}
static void F_9 ( void * V_20 )
{
struct V_6 * V_7 = V_20 ;
if ( V_7 ) {
F_10 ( V_7 -> V_18 ) ;
F_7 ( V_7 ) ;
}
}
static int F_11 ( struct V_1 * V_2 , void * * V_21 ,
struct V_22 * * V_23 , int V_24 , int V_25 , int V_26 , int V_27 ,
int V_28 )
{
enum V_29 V_30 ;
int V_31 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_12 ( & V_2 -> V_35 ) ;
F_13 ( V_7 -> V_18 ) ;
V_7 -> V_36 . V_37 = 0 ;
V_7 -> V_36 . V_38 = 0 ;
V_7 -> V_36 . V_39 = 0 ;
V_7 -> V_36 . V_40 = V_41 ;
V_7 -> V_36 . V_42 = V_21 [ V_34 ++ ] ;
do {
if ( V_7 -> V_36 . V_37 == V_7 -> V_36 . V_38 && V_33 < V_24 ) {
V_31 = F_14 ( V_26 , V_2 -> V_43 - V_25 ) ;
V_26 -= V_31 ;
F_15 ( V_23 [ V_33 ] ) ;
if ( ! F_16 ( V_23 [ V_33 ] ) )
goto V_44;
V_7 -> V_36 . V_45 = V_23 [ V_33 ] -> V_46 + V_25 ;
V_7 -> V_36 . V_38 = V_31 ;
V_7 -> V_36 . V_37 = 0 ;
V_25 = 0 ;
}
if ( V_7 -> V_36 . V_39 == V_7 -> V_36 . V_40
&& V_34 < V_28 ) {
V_7 -> V_36 . V_42 = V_21 [ V_34 ++ ] ;
V_7 -> V_36 . V_39 = 0 ;
V_32 += V_41 ;
}
V_30 = F_17 ( V_7 -> V_18 , & V_7 -> V_36 ) ;
if ( V_7 -> V_36 . V_37 == V_7 -> V_36 . V_38 && V_33 < V_24 )
F_18 ( V_23 [ V_33 ++ ] ) ;
} while ( V_30 == V_47 );
if ( V_30 != V_48 ) {
ERROR ( L_2 ) ;
goto V_44;
}
if ( V_33 < V_24 ) {
ERROR ( L_3 ) ;
goto V_44;
}
V_32 += V_7 -> V_36 . V_39 ;
F_19 ( & V_2 -> V_35 ) ;
return V_32 ;
V_44:
F_19 ( & V_2 -> V_35 ) ;
for (; V_33 < V_24 ; V_33 ++ )
F_18 ( V_23 [ V_33 ] ) ;
return - V_12 ;
}
