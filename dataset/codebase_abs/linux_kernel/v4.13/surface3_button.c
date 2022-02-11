static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , NULL , V_3 , V_7 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_6 = F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
return V_6 ;
}
static struct V_8 *
F_7 ( struct V_9 * V_10 ,
const struct V_11 * V_12 ,
bool V_13 )
{
const struct V_11 * V_14 ;
struct V_8 * V_15 ;
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
V_6 = F_1 ( & V_10 -> V_2 ,
V_14 -> V_3 ) ;
if ( ! F_10 ( V_6 ) )
continue;
V_17 [ V_20 ] . type = V_14 -> V_25 ;
V_17 [ V_20 ] . V_26 = V_14 -> V_27 ;
V_17 [ V_20 ] . V_6 = V_6 ;
V_17 [ V_20 ] . V_28 = V_14 -> V_28 ;
V_17 [ V_20 ] . V_5 = V_14 -> V_24 ;
V_17 [ V_20 ] . V_29 = V_14 -> V_29 ;
V_20 ++ ;
}
if ( V_20 == 0 ) {
error = - V_30 ;
goto V_31;
}
V_19 -> V_32 = V_17 ;
V_19 -> V_33 = V_20 ;
V_19 -> V_34 = V_13 ;
V_15 = F_11 ( L_1 , V_35 ) ;
if ( ! V_15 ) {
error = - V_23 ;
goto V_31;
}
error = F_12 ( V_15 , V_19 ,
sizeof( * V_19 ) ) ;
if ( error )
goto V_36;
error = F_13 ( V_15 ) ;
if ( error )
goto V_36;
return V_15 ;
V_36:
F_14 ( V_15 ) ;
V_31:
F_15 ( & V_10 -> V_2 , V_19 ) ;
return F_9 ( error ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_37 * V_38 = F_17 ( V_10 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
if ( V_38 -> V_41 [ V_39 ] )
F_18 ( V_38 -> V_41 [ V_39 ] ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 ,
const struct V_42 * V_43 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
struct V_37 * V_38 ;
struct V_8 * V_15 ;
int V_39 ;
int error ;
if ( strncmp ( F_20 ( F_21 ( & V_10 -> V_2 ) ) ,
V_44 ,
strlen ( V_44 ) ) )
return - V_30 ;
error = F_22 ( V_2 , NULL ) ;
if ( error < 0 ) {
F_23 ( V_2 , L_2 ) ;
return error ;
}
V_38 = F_8 ( V_2 , sizeof( * V_38 ) , V_22 ) ;
if ( ! V_38 )
return - V_23 ;
F_24 ( V_10 , V_38 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_15 = F_7 ( V_10 ,
V_45 ,
V_39 == 0 ) ;
if ( F_3 ( V_15 ) ) {
error = F_4 ( V_15 ) ;
if ( error != - V_30 ) {
F_16 ( V_10 ) ;
return error ;
}
continue;
}
V_38 -> V_41 [ V_39 ] = V_15 ;
}
if ( ! V_38 -> V_41 [ 0 ] && ! V_38 -> V_41 [ 1 ] )
return - V_30 ;
return 0 ;
}
