static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
int error ;
V_5 = ( V_4 & 0x7f ) | V_6 ;
error = F_2 ( V_2 -> V_7 , V_8 [ V_2 -> V_9 ] , V_5 ) ;
if ( error < 0 )
F_3 ( V_2 -> V_7 -> V_10 , L_1 ,
error ) ;
return error ;
}
static int F_4 ( struct V_11 * V_12 ,
enum V_3 V_13 )
{
struct V_1 * V_2 =
F_5 ( V_12 , struct V_1 , V_14 ) ;
return F_1 ( V_2 , V_13 ) ;
}
static int F_6 ( struct V_7 * V_7 )
{
int error ;
unsigned char V_15 = V_16
| V_17 ;
error = F_7 ( V_7 , V_18 ,
V_19 ,
V_15 ) ;
if ( error < 0 ) {
F_3 ( V_7 -> V_10 , L_2 ,
error ) ;
return error ;
}
error = F_7 ( V_7 , V_18 ,
V_20 ,
V_15 << V_21 ) ;
if ( error < 0 )
F_3 ( V_7 -> V_10 , L_2 ,
error ) ;
return error ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_7 * V_7 ;
struct V_26 * V_27 ;
struct V_1 * V_2 = NULL ;
int error = - V_28 ;
int V_29 ;
V_7 = F_9 ( V_23 -> V_10 . V_30 ) ;
V_25 = F_10 ( V_7 -> V_10 ) ;
if ( V_25 == NULL ) {
F_3 ( & V_23 -> V_10 , L_3 ) ;
goto V_31;
}
V_27 = V_25 -> V_27 ;
if ( V_27 == NULL ) {
F_3 ( & V_23 -> V_10 , L_4 ) ;
goto V_31;
}
V_2 = F_11 ( & V_23 -> V_10 ,
sizeof( struct V_1 ) * V_27 -> V_32 ,
V_33 ) ;
if ( ! V_2 ) {
error = - V_34 ;
goto V_31;
}
for ( V_29 = 0 ; V_29 < V_27 -> V_32 ; V_29 ++ ) {
V_2 [ V_29 ] . V_14 . V_35 = V_27 -> V_36 [ V_29 ] . V_35 ;
V_2 [ V_29 ] . V_14 . V_37 = F_4 ;
V_2 [ V_29 ] . V_14 . V_4 = V_38 ;
V_2 [ V_29 ] . V_14 . V_39 = V_40 ;
V_2 [ V_29 ] . V_9 = V_27 -> V_36 [ V_29 ] . V_41 ;
V_2 [ V_29 ] . V_7 = F_9 ( V_23 -> V_10 . V_30 ) ;
error = F_12 ( V_23 -> V_10 . V_30 , & V_2 [ V_29 ] . V_14 ) ;
if ( error ) {
F_3 ( & V_23 -> V_10 , L_5 ,
V_2 [ V_29 ] . V_9 ) ;
goto V_42;
}
error = F_1 ( & V_2 [ V_29 ] ,
V_2 [ V_29 ] . V_14 . V_4 ) ;
if ( error ) {
F_3 ( & V_23 -> V_10 , L_6 ,
V_2 [ V_29 ] . V_9 ) ;
continue;
}
}
error = F_6 ( V_2 -> V_7 ) ;
if ( error ) {
F_3 ( & V_23 -> V_10 , L_7 , error ) ;
goto V_42;
}
F_13 ( V_23 , V_2 ) ;
return 0 ;
V_42:
for ( V_29 = V_29 - 1 ; V_29 >= 0 ; V_29 -- )
F_14 ( & V_2 [ V_29 ] . V_14 ) ;
V_31:
return error ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_24 * V_25 ;
struct V_7 * V_7 ;
struct V_26 * V_27 ;
int V_29 ;
V_7 = F_9 ( V_23 -> V_10 . V_30 ) ;
V_25 = F_10 ( V_7 -> V_10 ) ;
V_27 = V_25 -> V_27 ;
for ( V_29 = 0 ; V_29 < V_27 -> V_32 ; V_29 ++ ) {
F_1 ( & V_2 [ V_29 ] , V_38 ) ;
F_14 ( & V_2 [ V_29 ] . V_14 ) ;
}
return 0 ;
}
