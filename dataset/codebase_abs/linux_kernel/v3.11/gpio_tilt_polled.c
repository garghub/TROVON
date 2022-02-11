static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = NULL ;
int V_12 , V_13 ;
if ( V_4 -> V_14 < V_4 -> V_15 ) {
V_4 -> V_14 ++ ;
} else {
V_12 = 0 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ )
V_12 |= ( ! ! F_2 ( V_7 -> V_17 [ V_13 ] . V_18 ) << V_13 ) ;
if ( V_12 != V_4 -> V_19 ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_20 ; V_13 ++ )
if ( V_7 -> V_21 [ V_13 ] . V_17 == V_12 )
V_11 = & V_7 -> V_21 [ V_13 ] ;
if ( V_11 ) {
for ( V_13 = 0 ; V_13 < V_7 -> V_22 ; V_13 ++ )
F_3 ( V_9 ,
V_7 -> V_23 [ V_13 ] . V_24 ,
V_11 -> V_23 [ V_13 ] ) ;
F_4 ( V_9 ) ;
}
V_4 -> V_14 = 0 ;
V_4 -> V_19 = V_12 ;
}
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_7 ;
if ( V_7 -> V_25 )
V_7 -> V_25 ( V_4 -> V_2 ) ;
V_4 -> V_19 = - 1 ;
V_4 -> V_14 = V_4 -> V_15 ;
F_1 ( V_4 -> V_26 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_7 ;
if ( V_7 -> V_27 )
V_7 -> V_27 ( V_4 -> V_2 ) ;
}
static int F_7 ( struct V_28 * V_29 )
{
const struct V_6 * V_7 = V_29 -> V_2 . V_30 ;
struct V_31 * V_2 = & V_29 -> V_2 ;
struct V_3 * V_4 ;
struct V_1 * V_26 ;
struct V_8 * V_9 ;
int error , V_13 ;
if ( ! V_7 || ! V_7 -> V_32 )
return - V_33 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_34 ) ;
if ( ! V_4 ) {
F_9 ( V_2 , L_1 ) ;
return - V_35 ;
}
error = F_10 ( V_7 -> V_17 , V_7 -> V_16 ) ;
if ( error ) {
F_9 ( V_2 ,
L_2 , error ) ;
goto V_36;
}
V_26 = F_11 () ;
if ( ! V_26 ) {
F_9 ( V_2 , L_3 ) ;
error = - V_35 ;
goto V_37;
}
V_26 -> V_5 = V_4 ;
V_26 -> V_38 = F_1 ;
V_26 -> V_32 = V_7 -> V_32 ;
V_26 -> V_39 = F_5 ;
V_26 -> V_40 = F_6 ;
V_9 = V_26 -> V_9 ;
V_9 -> V_41 = V_29 -> V_41 ;
V_9 -> V_42 = V_43 L_4 ;
V_9 -> V_2 . V_44 = & V_29 -> V_2 ;
V_9 -> V_45 . V_46 = V_47 ;
V_9 -> V_45 . V_48 = 0x0001 ;
V_9 -> V_45 . V_49 = 0x0001 ;
V_9 -> V_45 . V_50 = 0x0100 ;
F_12 ( V_51 , V_9 -> V_52 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_22 ; V_13 ++ )
F_13 ( V_9 , V_7 -> V_23 [ V_13 ] . V_24 ,
V_7 -> V_23 [ V_13 ] . V_53 , V_7 -> V_23 [ V_13 ] . V_54 ,
V_7 -> V_23 [ V_13 ] . V_55 , V_7 -> V_23 [ V_13 ] . V_56 ) ;
V_4 -> V_15 = F_14 ( V_7 -> V_57 ,
V_7 -> V_32 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = V_7 ;
error = F_15 ( V_26 ) ;
if ( error ) {
F_9 ( V_2 , L_5 ,
error ) ;
goto V_58;
}
F_16 ( V_29 , V_4 ) ;
return 0 ;
V_58:
F_17 ( V_26 ) ;
V_37:
F_18 ( V_7 -> V_17 , V_7 -> V_16 ) ;
V_36:
F_19 ( V_4 ) ;
return error ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_21 ( V_29 ) ;
const struct V_6 * V_7 = V_4 -> V_7 ;
F_22 ( V_4 -> V_26 ) ;
F_17 ( V_4 -> V_26 ) ;
F_18 ( V_7 -> V_17 , V_7 -> V_16 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
