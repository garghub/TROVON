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
struct V_34 * V_35 ;
T_1 V_14 = 0 , * V_16 = NULL , * V_22 = NULL ;
T_2 * V_20 = NULL ;
int V_36 = 0 , V_37 ;
if ( V_26 == NULL )
return - V_38 ;
V_37 = F_7 ( V_30 , V_31 , V_26 , V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_30 [ V_40 ] == NULL )
return - V_38 ;
if ( V_30 [ V_41 ] != NULL ) {
V_14 |= V_15 ;
V_16 = F_8 ( V_30 [ V_41 ] ) ;
}
if ( V_30 [ V_42 ] != NULL ) {
V_14 |= V_17 ;
V_20 = F_8 ( V_30 [ V_42 ] ) ;
}
if ( V_30 [ V_43 ] != NULL ) {
V_14 |= V_21 ;
V_22 = F_8 ( V_30 [ V_43 ] ) ;
}
if ( ! V_14 )
return - V_38 ;
V_33 = F_8 ( V_30 [ V_40 ] ) ;
V_35 = F_9 ( V_33 -> V_44 , V_4 , V_29 ) ;
if ( ! V_35 ) {
V_35 = F_10 ( V_33 -> V_44 , V_27 , V_4 , sizeof( * V_7 ) , V_29 ) ;
if ( F_11 ( V_35 ) )
return F_12 ( V_35 ) ;
V_7 = F_13 ( V_35 ) ;
V_36 = V_45 ;
} else {
V_7 = F_13 ( V_35 ) ;
if ( V_29 )
return 0 ;
F_14 ( V_35 , V_29 , V_4 -> V_46 -> V_47 ) ;
if ( ! V_28 )
return - V_48 ;
}
F_15 ( & V_7 -> V_9 ) ;
V_7 -> V_14 = V_14 ;
if ( V_14 & V_15 )
V_7 -> V_16 = * V_16 ;
if ( V_14 & V_17 )
V_7 -> V_20 = * V_20 ;
if ( V_14 & V_21 )
V_7 -> V_22 = * V_22 ;
V_7 -> V_23 = V_33 -> V_49 ;
F_16 ( & V_7 -> V_9 ) ;
if ( V_36 == V_45 )
F_17 ( V_35 , V_4 -> V_46 -> V_47 ) ;
return V_36 ;
}
static int F_18 ( struct V_3 * V_4 , int V_29 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
if ( V_7 )
return F_14 ( & V_7 -> V_50 , V_29 , & V_51 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_29 , int V_52 )
{
unsigned char * V_53 = F_20 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_32 V_54 = {
. V_44 = V_7 -> V_55 ,
. V_56 = V_7 -> V_57 - V_52 ,
. V_58 = V_7 -> V_59 - V_29 ,
. V_49 = V_7 -> V_23 ,
} ;
struct V_60 V_61 ;
if ( F_21 ( V_2 , V_40 , sizeof( V_54 ) , & V_54 ) )
goto V_62;
if ( ( V_7 -> V_14 & V_15 ) &&
F_21 ( V_2 , V_41 , sizeof( V_7 -> V_16 ) ,
& V_7 -> V_16 ) )
goto V_62;
if ( ( V_7 -> V_14 & V_17 ) &&
F_21 ( V_2 , V_42 ,
sizeof( V_7 -> V_20 ) , & V_7 -> V_20 ) )
goto V_62;
if ( ( V_7 -> V_14 & V_21 ) &&
F_21 ( V_2 , V_43 , sizeof( V_7 -> V_22 ) ,
& V_7 -> V_22 ) )
goto V_62;
V_61 . V_63 = F_22 ( V_12 - V_7 -> V_10 . V_63 ) ;
V_61 . V_11 = F_22 ( V_12 - V_7 -> V_10 . V_11 ) ;
V_61 . V_64 = F_22 ( V_7 -> V_10 . V_64 ) ;
if ( F_21 ( V_2 , V_65 , sizeof( V_61 ) , & V_61 ) )
goto V_62;
return V_2 -> V_66 ;
V_62:
F_23 ( V_2 , V_53 ) ;
return - 1 ;
}
static int T_3 F_24 ( void )
{
int V_37 = F_25 ( & V_51 , V_67 ) ;
if ( V_37 )
return V_37 ;
return F_26 ( & V_68 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_51 ) ;
F_29 ( & V_68 ) ;
}
