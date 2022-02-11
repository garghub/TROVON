static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int error ;
V_3 = ( V_2 -> V_4 & 0x7f ) | V_5 ;
error = F_2 ( V_2 -> V_6 , V_7 [ V_2 -> V_8 ] , V_3 ) ;
if ( error < 0 )
F_3 ( V_2 -> V_6 -> V_9 , L_1 ,
error ) ;
return error ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 , struct V_1 , V_11 ) ;
F_1 ( V_2 ) ;
}
static void F_6 ( struct V_12 * V_13 ,
enum V_14 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , struct V_1 , V_16 ) ;
V_2 -> V_4 = V_15 ;
F_7 ( & V_2 -> V_11 ) ;
}
static int F_8 ( struct V_6 * V_6 )
{
int error ;
unsigned char V_17 = V_18
| V_19 ;
error = F_9 ( V_6 , V_20 ,
V_21 ,
V_17 ) ;
if ( error < 0 ) {
F_3 ( V_6 -> V_9 , L_2 ,
error ) ;
return error ;
}
error = F_9 ( V_6 , V_20 ,
V_22 ,
V_17 << V_23 ) ;
if ( error < 0 )
F_3 ( V_6 -> V_9 , L_2 ,
error ) ;
return error ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_6 * V_6 ;
struct V_28 * V_29 ;
struct V_1 * V_2 = NULL ;
int error = - V_30 ;
int V_31 ;
V_6 = F_11 ( V_25 -> V_9 . V_32 ) ;
V_27 = V_6 -> V_9 -> V_33 ;
if ( V_27 == NULL ) {
F_3 ( & V_25 -> V_9 , L_3 ) ;
goto V_34;
}
V_29 = V_27 -> V_29 ;
if ( V_29 == NULL ) {
F_3 ( & V_25 -> V_9 , L_4 ) ;
goto V_34;
}
V_2 = F_12 ( & V_25 -> V_9 ,
sizeof( struct V_1 ) * V_29 -> V_35 ,
V_36 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_25 -> V_9 , L_5 ) ;
error = - V_37 ;
goto V_34;
}
for ( V_31 = 0 ; V_31 < V_29 -> V_35 ; V_31 ++ ) {
V_2 [ V_31 ] . V_16 . V_38 = V_29 -> V_39 [ V_31 ] . V_38 ;
V_2 [ V_31 ] . V_16 . V_40 = F_6 ;
V_2 [ V_31 ] . V_16 . V_4 = V_41 ;
V_2 [ V_31 ] . V_16 . V_42 = V_43 ;
V_2 [ V_31 ] . V_4 = V_41 ;
V_2 [ V_31 ] . V_8 = V_29 -> V_39 [ V_31 ] . V_44 ;
V_2 [ V_31 ] . V_6 = F_11 ( V_25 -> V_9 . V_32 ) ;
F_13 ( & V_2 [ V_31 ] . V_11 , F_4 ) ;
error = F_14 ( V_25 -> V_9 . V_32 , & V_2 [ V_31 ] . V_16 ) ;
if ( error ) {
F_3 ( & V_25 -> V_9 , L_6 ,
V_2 [ V_31 ] . V_8 ) ;
goto V_45;
}
error = F_1 ( & V_2 [ V_31 ] ) ;
if ( error ) {
F_3 ( & V_25 -> V_9 , L_7 ,
V_2 [ V_31 ] . V_8 ) ;
continue;
}
}
error = F_8 ( V_2 -> V_6 ) ;
if ( error ) {
F_3 ( & V_25 -> V_9 , L_8 , error ) ;
goto V_45;
}
F_15 ( V_25 , V_2 ) ;
return 0 ;
V_45:
for ( V_31 = V_31 - 1 ; V_31 >= 0 ; V_31 -- ) {
F_16 ( & V_2 [ V_31 ] . V_16 ) ;
F_17 ( & V_2 [ V_31 ] . V_11 ) ;
}
V_34:
return error ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_19 ( V_25 ) ;
struct V_26 * V_27 ;
struct V_6 * V_6 ;
struct V_28 * V_29 ;
int V_31 ;
V_6 = F_11 ( V_25 -> V_9 . V_32 ) ;
V_27 = V_6 -> V_9 -> V_33 ;
V_29 = V_27 -> V_29 ;
for ( V_31 = 0 ; V_31 < V_29 -> V_35 ; V_31 ++ ) {
V_2 [ V_31 ] . V_4 = 0 ;
F_1 ( & V_2 [ V_31 ] ) ;
F_16 ( & V_2 [ V_31 ] . V_16 ) ;
F_17 ( & V_2 [ V_31 ] . V_11 ) ;
}
return 0 ;
}
