T_1
F_1 ( char * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_6 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
V_7 = * F_4 ( T_2 , V_1 ) ;
V_8 = V_4 ;
if ( V_2 ) {
V_9 = V_2 ;
}
if ( V_3 ) {
V_10 = V_3 ;
}
( void ) F_5 ( V_6 ) ;
return ( V_11 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
T_1 V_5 ;
F_7 () ;
V_5 = F_2 ( V_6 ) ;
if ( F_3 ( V_5 ) ) {
return;
}
if ( ( ! V_7 ) ||
( V_7 != V_13 -> V_14 -> V_1 . integer ) ) {
goto exit;
}
V_15 = V_16 ;
V_17 = V_18 ;
V_16 = 0x00FFFFFF ;
V_18 = V_19 ;
if ( V_9 ) {
V_16 = V_9 ;
}
if ( V_10 ) {
V_18 = V_10 ;
}
exit:
( void ) F_5 ( V_6 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
T_1 V_5 ;
F_7 () ;
V_5 = F_2 ( V_6 ) ;
if ( F_3 ( V_5 ) ) {
return;
}
if ( ( ! V_7 ) ||
( V_7 != V_13 -> V_14 -> V_1 . integer ) ) {
goto exit;
}
if ( V_8 & 1 ) {
V_7 = 0 ;
V_9 = 0 ;
V_10 = 0 ;
}
V_16 = V_15 ;
V_18 = V_17 ;
exit:
( void ) F_5 ( V_6 ) ;
}
T_1 F_9 ( struct V_12 * V_13 )
{
T_1 V_5 ;
union V_20 * V_21 ;
struct V_22 * V_23 ;
F_10 ( V_24 ) ;
F_11 () ;
if ( ! V_13 || ! V_13 -> V_14 ) {
F_12 ( V_25 ) ;
}
V_5 =
F_13 ( V_13 -> V_14 , V_13 -> V_26 , NULL ) ;
if ( F_3 ( V_5 ) ) {
F_12 ( V_5 ) ;
}
F_14 ( V_13 , V_27 ) ;
F_6 ( V_13 ) ;
F_15 ( ( V_28 ,
L_1 ,
V_13 -> V_14 -> V_1 . V_29 , V_13 -> V_14 , V_13 -> V_26 ) ) ;
V_21 = F_16 () ;
if ( ! V_21 ) {
V_5 = V_30 ;
goto V_31;
}
V_13 -> V_32 = V_33 ;
V_23 =
F_17 ( V_13 -> V_26 -> V_34 . V_35 , NULL ,
NULL , NULL ) ;
if ( ! V_23 ) {
V_5 = V_30 ;
goto V_31;
}
V_5 = F_18 ( V_23 , V_21 , V_13 -> V_14 ,
V_13 -> V_26 -> V_34 . V_36 ,
V_13 -> V_26 -> V_34 . V_37 , V_13 ,
V_13 -> V_32 ) ;
if ( F_3 ( V_5 ) ) {
F_19 ( V_23 ) ;
goto V_31;
}
if ( V_13 -> V_26 -> V_34 . V_38 & V_39 ) {
V_23 -> V_40 |= V_41 ;
}
if ( V_13 -> V_26 -> V_34 . V_38 & V_42 ) {
V_5 =
V_13 -> V_26 -> V_34 . V_43 . V_44 ( V_23 ) ;
V_13 -> V_45 = V_23 -> V_46 ;
F_20 ( V_23 ) ;
F_21 ( & V_23 -> V_47 ) ;
F_22 ( V_23 -> V_48 ,
V_23 ) ;
F_19 ( V_23 ) ;
goto V_31;
}
if ( V_49 ) {
V_23 -> V_50 =
F_23 ( ( V_51 ) 0 ) ;
if ( ! V_23 -> V_50 ) {
V_5 = V_30 ;
F_19 ( V_23 ) ;
goto V_31;
}
}
V_5 = F_24 ( V_23 ) ;
V_31:
F_25 ( V_21 ) ;
F_8 ( V_13 ) ;
F_14 ( V_13 , V_52 ) ;
if ( F_3 ( V_5 ) ) {
F_12 ( V_5 ) ;
}
if ( V_13 -> V_45 ) {
F_15 ( ( V_28 , L_2 ,
V_13 -> V_45 ) ) ;
F_26 ( V_13 -> V_45 ) ;
V_5 = V_53 ;
}
F_12 ( V_5 ) ;
}
static void
F_14 ( struct V_12 * V_13 , T_3 V_54 )
{
T_2 V_55 ;
if ( V_13 -> V_56 ) {
for ( V_55 = 0 ; V_13 -> V_56 [ V_55 ] ; V_55 ++ ) {
( void ) F_27 ( V_13 ->
V_56 [ V_55 ] ,
V_54 ) ;
}
}
}
