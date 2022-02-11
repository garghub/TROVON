static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 V_8 [ 2 ] ;
int error ;
T_1 V_9 ;
T_1 V_10 [ 10 ] ;
V_8 [ 0 ] . V_11 = V_6 -> V_11 ;
V_8 [ 0 ] . V_12 = 0 ;
V_8 [ 0 ] . V_13 = 1 ;
V_8 [ 0 ] . V_10 = & V_9 ;
V_9 = 0x10 ;
V_8 [ 1 ] . V_11 = V_2 -> V_6 -> V_11 ;
V_8 [ 1 ] . V_12 = V_14 ;
V_8 [ 1 ] . V_13 = sizeof( V_10 ) ;
V_8 [ 1 ] . V_10 = V_10 ;
error = F_2 ( V_6 -> V_15 , V_8 , 2 ) ;
if ( error < 0 )
return error ;
V_4 [ 0 ] . V_16 = V_10 [ 2 ] >> 7 ;
V_4 [ 1 ] . V_16 = V_10 [ 5 ] >> 7 ;
if ( V_4 [ 0 ] . V_16 ) {
V_4 [ 0 ] . V_17 = ( ( V_10 [ 2 ] & 0x0070 ) << 4 ) | V_10 [ 3 ] ;
V_4 [ 0 ] . V_18 = ( ( V_10 [ 2 ] & 0x0007 ) << 8 ) | V_10 [ 4 ] ;
V_4 [ 0 ] . V_19 = V_10 [ 8 ] ;
}
if ( V_4 [ 1 ] . V_16 ) {
V_4 [ 1 ] . V_17 = ( ( V_10 [ 5 ] & 0x0070 ) << 4 ) | V_10 [ 6 ] ;
V_4 [ 1 ] . V_18 = ( ( V_10 [ 5 ] & 0x0007 ) << 8 ) | V_10 [ 7 ] ;
V_4 [ 1 ] . V_19 = V_10 [ 9 ] ;
}
return 0 ;
}
static T_2 F_3 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_22 = V_2 -> V_22 ;
int V_23 = 0 ;
int V_24 , V_25 ;
V_25 = F_1 ( V_2 ) ;
if ( V_25 < 0 )
goto V_26;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
if ( ! V_4 [ V_24 ] . V_16 )
continue;
F_4 ( V_22 , V_28 , V_4 [ V_24 ] . V_19 ) ;
F_4 ( V_22 , V_29 , V_4 [ V_24 ] . V_17 ) ;
F_4 ( V_22 , V_30 , V_4 [ V_24 ] . V_18 ) ;
F_5 ( V_22 ) ;
V_23 ++ ;
}
if ( ! V_23 )
F_5 ( V_22 ) ;
F_6 ( V_22 ) ;
V_26:
return V_31 ;
}
static int T_3 F_7 ( struct V_5 * V_6 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int error ;
if ( ! F_8 ( V_6 -> V_15 , V_34 ) ) {
F_9 ( & V_6 -> V_35 , L_1 ) ;
return - V_36 ;
}
if ( ! V_6 -> V_20 ) {
F_9 ( & V_6 -> V_35 , L_2 ) ;
return - V_37 ;
}
V_2 = F_10 ( sizeof( struct V_1 ) , V_38 ) ;
V_22 = F_11 () ;
if ( ! V_2 || ! V_22 ) {
error = - V_39 ;
goto V_40;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_22 = V_22 ;
V_22 -> V_41 = L_3 ;
V_22 -> V_33 . V_42 = V_43 ;
V_22 -> V_35 . V_44 = & V_6 -> V_35 ;
F_12 ( V_45 , V_22 -> V_46 ) ;
F_12 ( V_47 , V_22 -> V_46 ) ;
F_12 ( V_48 , V_22 -> V_46 ) ;
F_13 ( V_22 , V_28 , 0 , V_49 , 0 , 0 ) ;
F_13 ( V_22 , V_29 , V_50 , V_51 , 0 , 0 ) ;
F_13 ( V_22 , V_30 , V_52 , V_53 , 0 , 0 ) ;
error = F_14 ( V_6 -> V_20 , NULL , F_3 ,
V_54 , V_6 -> V_41 , V_2 ) ;
if ( error ) {
F_9 ( & V_6 -> V_35 , L_4 ) ;
goto V_40;
}
error = F_15 ( V_2 -> V_22 ) ;
if ( error ) {
F_9 ( & V_6 -> V_35 , L_5 ,
V_22 -> V_41 ) ;
goto V_55;
}
F_16 ( V_6 , V_2 ) ;
F_17 ( & V_6 -> V_35 , 1 ) ;
return 0 ;
V_55:
F_18 ( V_6 -> V_20 , V_2 ) ;
V_40:
F_19 ( V_22 ) ;
F_20 ( V_2 ) ;
return error ;
}
static int T_4 F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_22 ( V_6 ) ;
F_17 ( & V_6 -> V_35 , 0 ) ;
F_18 ( V_6 -> V_20 , V_2 ) ;
F_23 ( V_2 -> V_22 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_56 * V_35 )
{
struct V_5 * V_6 = F_25 ( V_35 ) ;
if ( F_26 ( & V_6 -> V_35 ) )
F_27 ( V_6 -> V_20 ) ;
else
F_28 ( V_6 -> V_20 ) ;
return 0 ;
}
static int F_29 ( struct V_56 * V_35 )
{
struct V_5 * V_6 = F_25 ( V_35 ) ;
if ( F_26 ( & V_6 -> V_35 ) )
F_30 ( V_6 -> V_20 ) ;
else
F_31 ( V_6 -> V_20 ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_57 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_57 ) ;
}
