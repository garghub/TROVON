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
if ( ! V_23 ) {
F_5 ( V_22 ) ;
if ( V_2 -> V_31 . V_32 ) {
F_6 ( & V_2 -> V_31 ) ;
V_2 -> V_31 . V_32 = NULL ;
}
} else if ( ! V_2 -> V_31 . V_32 ) {
F_7 ( & V_2 -> V_6 -> V_32 ,
& V_2 -> V_31 , 100 ) ;
}
F_8 ( V_22 ) ;
V_26:
return V_33 ;
}
static int T_3 F_9 ( struct V_5 * V_6 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int error ;
if ( ! F_10 ( V_6 -> V_15 , V_36 ) ) {
F_11 ( & V_6 -> V_32 , L_1 ) ;
return - V_37 ;
}
if ( ! V_6 -> V_20 ) {
F_11 ( & V_6 -> V_32 , L_2 ) ;
return - V_38 ;
}
V_2 = F_12 ( sizeof( struct V_1 ) , V_39 ) ;
V_22 = F_13 () ;
if ( ! V_2 || ! V_22 ) {
error = - V_40 ;
goto V_41;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_22 = V_22 ;
V_22 -> V_42 = L_3 ;
V_22 -> V_35 . V_43 = V_44 ;
V_22 -> V_32 . V_45 = & V_6 -> V_32 ;
F_14 ( V_46 , V_22 -> V_47 ) ;
F_14 ( V_48 , V_22 -> V_47 ) ;
F_14 ( V_49 , V_22 -> V_47 ) ;
F_15 ( V_22 , V_28 , 0 , V_50 , 0 , 0 ) ;
F_15 ( V_22 , V_29 , V_51 , V_52 , 0 , 0 ) ;
F_15 ( V_22 , V_30 , V_53 , V_54 , 0 , 0 ) ;
error = F_16 ( V_6 -> V_20 , NULL , F_3 ,
V_55 , V_6 -> V_42 , V_2 ) ;
if ( error ) {
F_11 ( & V_6 -> V_32 , L_4 ) ;
goto V_41;
}
error = F_17 ( V_2 -> V_22 ) ;
if ( error ) {
F_11 ( & V_6 -> V_32 , L_5 ,
V_22 -> V_42 ) ;
goto V_56;
}
F_18 ( V_6 , V_2 ) ;
F_19 ( & V_6 -> V_32 , 1 ) ;
return 0 ;
V_56:
F_20 ( V_6 -> V_20 , V_2 ) ;
V_41:
F_21 ( V_22 ) ;
F_22 ( V_2 ) ;
return error ;
}
static int T_4 F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
F_19 ( & V_6 -> V_32 , 0 ) ;
F_20 ( V_6 -> V_20 , V_2 ) ;
F_25 ( V_2 -> V_22 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_57 * V_32 )
{
struct V_5 * V_6 = F_27 ( V_32 ) ;
if ( F_28 ( & V_6 -> V_32 ) )
F_29 ( V_6 -> V_20 ) ;
else
F_30 ( V_6 -> V_20 ) ;
return 0 ;
}
static int F_31 ( struct V_57 * V_32 )
{
struct V_5 * V_6 = F_27 ( V_32 ) ;
if ( F_28 ( & V_6 -> V_32 ) )
F_32 ( V_6 -> V_20 ) ;
else
F_33 ( V_6 -> V_20 ) ;
return 0 ;
}
static int T_5 F_34 ( void )
{
return F_35 ( & V_58 ) ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_58 ) ;
}
