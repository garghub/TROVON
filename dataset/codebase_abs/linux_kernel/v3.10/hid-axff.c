static int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_9 -> V_11 ;
int V_12 = 0 ;
int V_13 , V_14 ;
int V_15 , V_16 ;
V_13 = V_5 -> V_17 . V_18 . V_19 ;
V_14 = V_5 -> V_17 . V_18 . V_20 ;
F_3 ( L_1 , V_13 , V_14 ) ;
V_13 = V_13 * 0xff / 0xffff ;
V_14 = V_14 * 0xff / 0xffff ;
for ( V_15 = 0 ; V_15 < V_11 -> V_21 ; V_15 ++ ) {
for ( V_16 = 0 ; V_16 < V_11 -> V_22 [ V_15 ] -> V_23 ; V_16 ++ ) {
V_11 -> V_22 [ V_15 ] -> V_24 [ V_16 ] =
V_12 % 2 ? V_14 : V_13 ;
V_12 ++ ;
}
}
F_3 ( L_2 , V_13 , V_14 ) ;
F_4 ( V_7 , V_9 -> V_11 , V_25 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_26 * V_27 = F_6 ( & V_7 -> V_28 , struct V_26 , V_29 ) ;
struct V_30 * V_31 = & V_7 -> V_32 [ V_33 ] . V_31 ;
struct V_1 * V_2 = V_27 -> V_34 ;
int V_12 = 0 ;
int V_15 , V_16 ;
int error ;
if ( F_7 ( V_31 ) ) {
F_8 ( V_7 , L_3 ) ;
return - V_35 ;
}
V_11 = F_6 ( V_31 , struct V_10 , V_29 ) ;
for ( V_15 = 0 ; V_15 < V_11 -> V_21 ; V_15 ++ ) {
for ( V_16 = 0 ; V_16 < V_11 -> V_22 [ V_15 ] -> V_23 ; V_16 ++ ) {
V_11 -> V_22 [ V_15 ] -> V_24 [ V_16 ] = 0x00 ;
V_12 ++ ;
}
}
if ( V_12 < 4 ) {
F_8 ( V_7 , L_4 ,
V_12 ) ;
return - V_35 ;
}
V_9 = F_9 ( sizeof( struct V_8 ) , V_36 ) ;
if ( ! V_9 )
return - V_37 ;
F_10 ( V_38 , V_2 -> V_39 ) ;
error = F_11 ( V_2 , V_9 , F_1 ) ;
if ( error )
goto V_40;
V_9 -> V_11 = V_11 ;
F_4 ( V_7 , V_9 -> V_11 , V_25 ) ;
F_12 ( V_7 , L_5 ) ;
return 0 ;
V_40:
F_13 ( V_9 ) ;
return error ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_41 , const struct V_42 * V_43 )
{
int error ;
F_15 ( & V_41 -> V_2 , L_6 ) ;
error = F_16 ( V_41 ) ;
if ( error ) {
F_8 ( V_41 , L_7 ) ;
return error ;
}
error = F_17 ( V_41 , V_44 & ~ V_45 ) ;
if ( error ) {
F_8 ( V_41 , L_8 ) ;
return error ;
}
error = F_5 ( V_41 ) ;
if ( error ) {
F_18 ( V_41 ,
L_9 ,
error ) ;
}
error = F_19 ( V_41 ) ;
if ( error ) {
F_20 ( & V_41 -> V_2 , L_10 ) ;
F_21 ( V_41 ) ;
return error ;
}
return 0 ;
}
static void F_22 ( struct V_6 * V_41 )
{
F_23 ( V_41 ) ;
F_21 ( V_41 ) ;
}
