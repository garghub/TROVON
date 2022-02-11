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
static int F_6 ( struct V_24 * V_25 , struct V_24 * V_26 ,
struct V_3 * V_4 , int V_27 , int V_28 )
{
struct V_24 * V_29 [ V_30 + 1 ] ;
struct V_31 * V_32 ;
struct F_1 * V_7 ;
struct V_33 * V_34 ;
T_1 V_14 = 0 , * V_16 = NULL , * V_22 = NULL ;
T_2 * V_20 = NULL ;
int V_35 = 0 , V_36 ;
if ( V_25 == NULL )
return - V_37 ;
V_36 = F_7 ( V_29 , V_30 , V_25 , V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_29 [ V_39 ] == NULL )
return - V_37 ;
if ( V_29 [ V_40 ] != NULL ) {
V_14 |= V_15 ;
V_16 = F_8 ( V_29 [ V_40 ] ) ;
}
if ( V_29 [ V_41 ] != NULL ) {
V_14 |= V_17 ;
V_20 = F_8 ( V_29 [ V_41 ] ) ;
}
if ( V_29 [ V_42 ] != NULL ) {
V_14 |= V_21 ;
V_22 = F_8 ( V_29 [ V_42 ] ) ;
}
if ( ! V_14 )
return - V_37 ;
V_32 = F_8 ( V_29 [ V_39 ] ) ;
V_34 = F_9 ( V_32 -> V_43 , V_4 , V_28 , & V_44 ) ;
if ( ! V_34 ) {
V_34 = F_10 ( V_32 -> V_43 , V_26 , V_4 , sizeof( * V_7 ) , V_28 ,
& V_45 , & V_44 ) ;
if ( F_11 ( V_34 ) )
return F_12 ( V_34 ) ;
V_7 = F_13 ( V_34 ) ;
V_35 = V_46 ;
} else {
V_7 = F_13 ( V_34 ) ;
if ( ! V_27 ) {
F_14 ( V_34 , V_28 , & V_44 ) ;
return - V_47 ;
}
}
F_15 ( & V_7 -> V_9 ) ;
V_7 -> V_14 = V_14 ;
if ( V_14 & V_15 )
V_7 -> V_16 = * V_16 ;
if ( V_14 & V_17 )
V_7 -> V_20 = * V_20 ;
if ( V_14 & V_21 )
V_7 -> V_22 = * V_22 ;
V_7 -> V_23 = V_32 -> V_48 ;
F_16 ( & V_7 -> V_9 ) ;
if ( V_35 == V_46 )
F_17 ( V_34 , & V_44 ) ;
return V_35 ;
}
static int F_18 ( struct V_3 * V_4 , int V_28 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
if ( V_7 )
return F_14 ( & V_7 -> V_49 , V_28 , & V_44 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_28 , int V_50 )
{
unsigned char * V_51 = F_20 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_31 V_52 = {
. V_43 = V_7 -> V_53 ,
. V_54 = V_7 -> V_55 - V_50 ,
. V_56 = V_7 -> V_57 - V_28 ,
. V_48 = V_7 -> V_23 ,
} ;
struct V_58 V_59 ;
if ( F_21 ( V_2 , V_39 , sizeof( V_52 ) , & V_52 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_15 ) &&
F_21 ( V_2 , V_40 , sizeof( V_7 -> V_16 ) ,
& V_7 -> V_16 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_17 ) &&
F_21 ( V_2 , V_41 ,
sizeof( V_7 -> V_20 ) , & V_7 -> V_20 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_21 ) &&
F_21 ( V_2 , V_42 , sizeof( V_7 -> V_22 ) ,
& V_7 -> V_22 ) )
goto V_60;
V_59 . V_61 = F_22 ( V_12 - V_7 -> V_10 . V_61 ) ;
V_59 . V_11 = F_22 ( V_12 - V_7 -> V_10 . V_11 ) ;
V_59 . V_62 = F_22 ( V_7 -> V_10 . V_62 ) ;
if ( F_21 ( V_2 , V_63 , sizeof( V_59 ) , & V_59 ) )
goto V_60;
return V_2 -> V_64 ;
V_60:
F_23 ( V_2 , V_51 ) ;
return - 1 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_65 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_65 ) ;
}
