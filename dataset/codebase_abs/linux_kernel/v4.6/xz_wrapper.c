static void * F_1 ( struct V_1 * V_2 ,
void * V_3 , int V_4 )
{
struct V_5 * V_6 = V_3 ;
struct V_6 * V_7 ;
int V_8 = 0 , V_9 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_10 ) ;
if ( V_7 == NULL ) {
V_8 = - V_11 ;
goto V_12;
}
if ( V_6 ) {
if ( V_4 < sizeof( * V_6 ) ) {
V_8 = - V_13 ;
goto V_14;
}
V_7 -> V_15 = F_3 ( V_6 -> V_16 ) ;
V_9 = F_4 ( V_7 -> V_15 ) - 1 ;
if ( V_7 -> V_15 != ( 1 << V_9 ) && V_7 -> V_15 != ( 1 << V_9 ) +
( 1 << ( V_9 + 1 ) ) ) {
V_8 = - V_13 ;
goto V_14;
}
} else
V_7 -> V_15 = F_5 ( int , V_2 -> V_17 ,
V_18 ) ;
return V_7 ;
V_14:
F_6 ( V_7 ) ;
V_12:
return F_7 ( V_8 ) ;
}
static void * F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_6 = V_3 ;
struct V_19 * V_20 ;
int V_8 ;
V_20 = F_2 ( sizeof( * V_20 ) , V_10 ) ;
if ( V_20 == NULL ) {
V_8 = - V_11 ;
goto V_21;
}
V_20 -> V_22 = F_9 ( V_23 , V_6 -> V_15 ) ;
if ( V_20 -> V_22 == NULL ) {
F_6 ( V_20 ) ;
V_8 = - V_11 ;
goto V_21;
}
return V_20 ;
V_21:
ERROR ( L_1 ) ;
return F_7 ( V_8 ) ;
}
static void F_10 ( void * V_24 )
{
struct V_19 * V_20 = V_24 ;
if ( V_20 ) {
F_11 ( V_20 -> V_22 ) ;
F_6 ( V_20 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , void * V_24 ,
struct V_25 * * V_26 , int V_27 , int V_28 , int V_29 ,
struct V_30 * V_31 )
{
enum V_32 V_33 ;
int V_34 , V_35 = 0 , V_36 = 0 ;
struct V_19 * V_20 = V_24 ;
F_13 ( V_20 -> V_22 ) ;
V_20 -> V_37 . V_38 = 0 ;
V_20 -> V_37 . V_39 = 0 ;
V_20 -> V_37 . V_40 = 0 ;
V_20 -> V_37 . V_41 = V_42 ;
V_20 -> V_37 . V_14 = F_14 ( V_31 ) ;
do {
if ( V_20 -> V_37 . V_38 == V_20 -> V_37 . V_39 && V_36 < V_27 ) {
V_34 = F_15 ( V_29 , V_2 -> V_43 - V_28 ) ;
V_29 -= V_34 ;
V_20 -> V_37 . V_44 = V_26 [ V_36 ] -> V_45 + V_28 ;
V_20 -> V_37 . V_39 = V_34 ;
V_20 -> V_37 . V_38 = 0 ;
V_28 = 0 ;
}
if ( V_20 -> V_37 . V_40 == V_20 -> V_37 . V_41 ) {
V_20 -> V_37 . V_14 = F_16 ( V_31 ) ;
if ( V_20 -> V_37 . V_14 != NULL ) {
V_20 -> V_37 . V_40 = 0 ;
V_35 += V_42 ;
}
}
V_33 = F_17 ( V_20 -> V_22 , & V_20 -> V_37 ) ;
if ( V_20 -> V_37 . V_38 == V_20 -> V_37 . V_39 && V_36 < V_27 )
F_18 ( V_26 [ V_36 ++ ] ) ;
} while ( V_33 == V_46 );
F_19 ( V_31 ) ;
if ( V_33 != V_47 || V_36 < V_27 )
goto V_14;
return V_35 + V_20 -> V_37 . V_40 ;
V_14:
for (; V_36 < V_27 ; V_36 ++ )
F_18 ( V_26 [ V_36 ] ) ;
return - V_13 ;
}
