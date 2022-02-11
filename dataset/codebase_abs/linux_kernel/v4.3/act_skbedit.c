static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
F_2 ( & V_7 -> V_9 ) ;
V_7 -> V_10 . V_11 = V_12 ;
F_3 ( & V_7 -> V_13 , V_2 ) ;
if ( V_7 -> V_14 & V_15 )
V_2 -> V_16 = V_7 -> V_16 ;
if ( V_7 -> V_14 & V_17 &&
V_2 -> V_18 -> V_19 > V_7 -> V_20 )
F_4 ( V_2 , V_7 -> V_20 ) ;
if ( V_7 -> V_14 & V_21 )
V_2 -> V_22 = V_7 -> V_22 ;
F_5 ( & V_7 -> V_9 ) ;
return V_7 -> V_23 ;
}
static int F_6 ( struct V_24 * V_24 , struct V_25 * V_26 ,
struct V_25 * V_27 , struct V_3 * V_4 ,
int V_28 , int V_29 )
{
struct V_25 * V_30 [ V_31 + 1 ] ;
struct V_32 * V_33 ;
struct F_1 * V_7 ;
T_1 V_14 = 0 , * V_16 = NULL , * V_22 = NULL ;
T_2 * V_20 = NULL ;
int V_34 = 0 , V_35 ;
if ( V_26 == NULL )
return - V_36 ;
V_35 = F_7 ( V_30 , V_31 , V_26 , V_37 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_30 [ V_38 ] == NULL )
return - V_36 ;
if ( V_30 [ V_39 ] != NULL ) {
V_14 |= V_15 ;
V_16 = F_8 ( V_30 [ V_39 ] ) ;
}
if ( V_30 [ V_40 ] != NULL ) {
V_14 |= V_17 ;
V_20 = F_8 ( V_30 [ V_40 ] ) ;
}
if ( V_30 [ V_41 ] != NULL ) {
V_14 |= V_21 ;
V_22 = F_8 ( V_30 [ V_41 ] ) ;
}
if ( ! V_14 )
return - V_36 ;
V_33 = F_8 ( V_30 [ V_38 ] ) ;
if ( ! F_9 ( V_33 -> V_42 , V_4 , V_29 ) ) {
V_34 = F_10 ( V_33 -> V_42 , V_27 , V_4 , sizeof( * V_7 ) ,
V_29 , false ) ;
if ( V_34 )
return V_34 ;
V_7 = F_11 ( V_4 ) ;
V_34 = V_43 ;
} else {
V_7 = F_11 ( V_4 ) ;
if ( V_29 )
return 0 ;
F_12 ( V_4 , V_29 ) ;
if ( ! V_28 )
return - V_44 ;
}
F_13 ( & V_7 -> V_9 ) ;
V_7 -> V_14 = V_14 ;
if ( V_14 & V_15 )
V_7 -> V_16 = * V_16 ;
if ( V_14 & V_17 )
V_7 -> V_20 = * V_20 ;
if ( V_14 & V_21 )
V_7 -> V_22 = * V_22 ;
V_7 -> V_23 = V_33 -> V_45 ;
F_14 ( & V_7 -> V_9 ) ;
if ( V_34 == V_43 )
F_15 ( V_4 ) ;
return V_34 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_29 , int V_46 )
{
unsigned char * V_47 = F_17 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_32 V_48 = {
. V_42 = V_7 -> V_49 ,
. V_50 = V_7 -> V_51 - V_46 ,
. V_52 = V_7 -> V_53 - V_29 ,
. V_45 = V_7 -> V_23 ,
} ;
struct V_54 V_55 ;
if ( F_18 ( V_2 , V_38 , sizeof( V_48 ) , & V_48 ) )
goto V_56;
if ( ( V_7 -> V_14 & V_15 ) &&
F_18 ( V_2 , V_39 , sizeof( V_7 -> V_16 ) ,
& V_7 -> V_16 ) )
goto V_56;
if ( ( V_7 -> V_14 & V_17 ) &&
F_18 ( V_2 , V_40 ,
sizeof( V_7 -> V_20 ) , & V_7 -> V_20 ) )
goto V_56;
if ( ( V_7 -> V_14 & V_21 ) &&
F_18 ( V_2 , V_41 , sizeof( V_7 -> V_22 ) ,
& V_7 -> V_22 ) )
goto V_56;
V_55 . V_57 = F_19 ( V_12 - V_7 -> V_10 . V_57 ) ;
V_55 . V_11 = F_19 ( V_12 - V_7 -> V_10 . V_11 ) ;
V_55 . V_58 = F_19 ( V_7 -> V_10 . V_58 ) ;
if ( F_18 ( V_2 , V_59 , sizeof( V_55 ) , & V_55 ) )
goto V_56;
return V_2 -> V_60 ;
V_56:
F_20 ( V_2 , V_47 ) ;
return - 1 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_61 , V_62 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_61 ) ;
}
