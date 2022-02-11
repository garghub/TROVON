static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , V_7 , V_3 , V_8 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_6 = F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
return V_6 ;
}
static struct V_9 *
F_7 ( struct V_9 * V_10 ,
const struct V_11 * V_12 ,
bool V_13 )
{
const struct V_11 * V_14 ;
struct V_9 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
int V_6 ;
int error ;
V_19 = F_8 ( & V_10 -> V_2 ,
sizeof( * V_19 ) +
sizeof( * V_17 ) * V_21 ,
V_22 ) ;
if ( ! V_19 )
return F_9 ( - V_23 ) ;
V_17 = ( void * ) ( V_19 + 1 ) ;
for ( V_14 = V_12 ; V_14 -> V_24 ; V_14 ++ ) {
if ( V_14 -> V_13 != V_13 )
continue;
V_6 = F_1 ( & V_10 -> V_2 , V_14 -> V_3 ) ;
if ( ! F_10 ( V_6 ) )
continue;
V_17 [ V_20 ] . type = V_14 -> V_25 ;
V_17 [ V_20 ] . V_26 = V_14 -> V_27 ;
V_17 [ V_20 ] . V_6 = V_6 ;
V_17 [ V_20 ] . V_28 = 1 ;
V_17 [ V_20 ] . V_5 = V_14 -> V_24 ;
V_17 [ V_20 ] . V_29 = V_14 -> V_29 ;
V_17 [ V_20 ] . V_30 = 50 ;
V_20 ++ ;
}
if ( V_20 == 0 ) {
error = - V_31 ;
goto V_32;
}
V_19 -> V_33 = V_17 ;
V_19 -> V_34 = V_20 ;
V_19 -> V_35 = V_13 ;
V_15 = F_11 ( L_1 , V_36 ) ;
if ( ! V_15 ) {
error = - V_23 ;
goto V_32;
}
error = F_12 ( V_15 , V_19 ,
sizeof( * V_19 ) ) ;
if ( error )
goto V_37;
error = F_13 ( V_15 ) ;
if ( error )
goto V_37;
return V_15 ;
V_37:
F_14 ( V_15 ) ;
V_32:
F_15 ( & V_10 -> V_2 , V_19 ) ;
return F_9 ( error ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_38 * V_39 = F_17 ( V_10 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
if ( V_39 -> V_42 [ V_40 ] )
F_18 ( V_39 -> V_42 [ V_40 ] ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
const struct V_43 * V_44 ;
struct V_11 * V_12 ;
struct V_38 * V_39 ;
struct V_9 * V_15 ;
int V_40 ;
int error ;
V_44 = F_20 ( V_2 -> V_45 -> V_46 , V_2 ) ;
if ( ! V_44 )
return - V_31 ;
V_12 = (struct V_11 * ) V_44 -> V_47 ;
if ( F_21 ( V_2 , V_7 ) <= 0 ) {
F_22 ( V_2 , L_2 ) ;
return - V_31 ;
}
V_39 = F_8 ( V_2 , sizeof( * V_39 ) , V_22 ) ;
if ( ! V_39 )
return - V_23 ;
F_23 ( V_10 , V_39 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
V_15 = F_7 ( V_10 , V_12 , V_40 == 0 ) ;
if ( F_3 ( V_15 ) ) {
error = F_4 ( V_15 ) ;
if ( error != - V_31 ) {
F_16 ( V_10 ) ;
return error ;
}
continue;
}
V_39 -> V_42 [ V_40 ] = V_15 ;
}
if ( ! V_39 -> V_42 [ 0 ] && ! V_39 -> V_42 [ 1 ] )
return - V_31 ;
return 0 ;
}
