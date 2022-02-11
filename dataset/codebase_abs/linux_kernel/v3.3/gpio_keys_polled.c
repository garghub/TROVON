static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( V_6 -> V_8 )
V_7 = ! ! F_2 ( V_4 -> V_9 ) ;
else
V_7 = ! ! F_3 ( V_4 -> V_9 ) ;
if ( V_7 != V_6 -> V_10 ) {
unsigned int type = V_4 -> type ? : V_11 ;
F_4 ( V_2 , type , V_4 -> V_12 ,
! ! ( V_7 ^ V_4 -> V_13 ) ) ;
F_5 ( V_2 ) ;
V_6 -> V_14 = 0 ;
V_6 -> V_10 = V_7 ;
}
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_18 -> V_21 -> V_23 ; V_22 ++ ) {
struct V_5 * V_6 = & V_18 -> V_24 [ V_22 ] ;
if ( V_6 -> V_14 < V_6 -> V_25 )
V_6 -> V_14 ++ ;
else
F_1 ( V_2 , & V_21 -> V_26 [ V_22 ] ,
V_6 ) ;
}
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_27 )
V_21 -> V_27 ( V_18 -> V_16 ) ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_28 )
V_21 -> V_28 ( V_18 -> V_16 ) ;
}
static int T_1 F_9 ( struct V_29 * V_30 )
{
struct V_20 * V_21 = V_30 -> V_16 . V_31 ;
struct V_32 * V_16 = & V_30 -> V_16 ;
struct V_17 * V_18 ;
struct V_15 * V_33 ;
struct V_1 * V_2 ;
int error ;
int V_22 ;
if ( ! V_21 || ! V_21 -> V_34 )
return - V_35 ;
V_18 = F_10 ( sizeof( struct V_17 ) +
V_21 -> V_23 * sizeof( struct V_5 ) ,
V_36 ) ;
if ( ! V_18 ) {
F_11 ( V_16 , L_1 ) ;
return - V_37 ;
}
V_33 = F_12 () ;
if ( ! V_33 ) {
F_11 ( V_16 , L_2 ) ;
error = - V_37 ;
goto V_38;
}
V_33 -> V_19 = V_18 ;
V_33 -> V_39 = F_6 ;
V_33 -> V_34 = V_21 -> V_34 ;
V_33 -> V_40 = F_7 ;
V_33 -> V_41 = F_8 ;
V_2 = V_33 -> V_2 ;
V_2 -> V_42 [ 0 ] = F_13 ( V_11 ) ;
V_2 -> V_43 = V_30 -> V_43 ;
V_2 -> V_44 = V_45 L_3 ;
V_2 -> V_16 . V_46 = & V_30 -> V_16 ;
V_2 -> V_47 . V_48 = V_49 ;
V_2 -> V_47 . V_50 = 0x0001 ;
V_2 -> V_47 . V_51 = 0x0001 ;
V_2 -> V_47 . V_52 = 0x0100 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
struct V_3 * V_4 = & V_21 -> V_26 [ V_22 ] ;
struct V_5 * V_6 = & V_18 -> V_24 [ V_22 ] ;
unsigned int V_9 = V_4 -> V_9 ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( V_4 -> V_53 ) {
F_11 ( V_16 , V_45 L_4 ) ;
error = - V_35 ;
goto V_54;
}
error = F_14 ( V_9 ,
V_4 -> V_55 ? V_4 -> V_55 : V_45 ) ;
if ( error ) {
F_11 ( V_16 , L_5 ,
V_9 , error ) ;
goto V_54;
}
error = F_15 ( V_9 ) ;
if ( error ) {
F_11 ( V_16 ,
L_6 ,
V_9 , error ) ;
goto V_54;
}
V_6 -> V_8 = F_16 ( V_9 ) ;
V_6 -> V_10 = - 1 ;
V_6 -> V_25 = F_17 ( V_4 -> V_56 ,
V_21 -> V_34 ) ;
F_18 ( V_2 , type , V_4 -> V_12 ) ;
}
V_18 -> V_33 = V_33 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_21 = V_21 ;
F_19 ( V_30 , V_18 ) ;
error = F_20 ( V_33 ) ;
if ( error ) {
F_11 ( V_16 , L_7 ,
error ) ;
goto V_54;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ )
F_1 ( V_2 , & V_21 -> V_26 [ V_22 ] ,
& V_18 -> V_24 [ V_22 ] ) ;
return 0 ;
V_54:
while ( -- V_22 >= 0 )
F_21 ( V_21 -> V_26 [ V_22 ] . V_9 ) ;
F_22 ( V_33 ) ;
V_38:
F_23 ( V_18 ) ;
F_19 ( V_30 , NULL ) ;
return error ;
}
static int T_2 F_24 ( struct V_29 * V_30 )
{
struct V_17 * V_18 = F_25 ( V_30 ) ;
struct V_20 * V_21 = V_18 -> V_21 ;
int V_22 ;
F_26 ( V_18 -> V_33 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ )
F_21 ( V_21 -> V_26 [ V_22 ] . V_9 ) ;
F_22 ( V_18 -> V_33 ) ;
F_23 ( V_18 ) ;
F_19 ( V_30 , NULL ) ;
return 0 ;
}
