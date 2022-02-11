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
struct V_30 * V_31 = F_7 ( V_24 , V_32 ) ;
struct V_25 * V_33 [ V_34 + 1 ] ;
struct V_35 * V_36 ;
struct F_1 * V_7 ;
T_1 V_14 = 0 , * V_16 = NULL , * V_22 = NULL ;
T_2 * V_20 = NULL ;
int V_37 = 0 , V_38 , V_39 = 0 ;
if ( V_26 == NULL )
return - V_40 ;
V_38 = F_8 ( V_33 , V_34 , V_26 , V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_33 [ V_42 ] == NULL )
return - V_40 ;
if ( V_33 [ V_43 ] != NULL ) {
V_14 |= V_15 ;
V_16 = F_9 ( V_33 [ V_43 ] ) ;
}
if ( V_33 [ V_44 ] != NULL ) {
V_14 |= V_17 ;
V_20 = F_9 ( V_33 [ V_44 ] ) ;
}
if ( V_33 [ V_45 ] != NULL ) {
V_14 |= V_21 ;
V_22 = F_9 ( V_33 [ V_45 ] ) ;
}
V_36 = F_9 ( V_33 [ V_42 ] ) ;
V_39 = F_10 ( V_31 , V_36 -> V_46 , V_4 , V_29 ) ;
if ( V_39 && V_29 )
return 0 ;
if ( ! V_14 ) {
F_11 ( V_4 , V_29 ) ;
return - V_40 ;
}
if ( ! V_39 ) {
V_37 = F_12 ( V_31 , V_36 -> V_46 , V_27 , V_4 ,
sizeof( * V_7 ) , V_29 , false ) ;
if ( V_37 )
return V_37 ;
V_7 = F_13 ( V_4 ) ;
V_37 = V_47 ;
} else {
V_7 = F_13 ( V_4 ) ;
F_11 ( V_4 , V_29 ) ;
if ( ! V_28 )
return - V_48 ;
}
F_14 ( & V_7 -> V_9 ) ;
V_7 -> V_14 = V_14 ;
if ( V_14 & V_15 )
V_7 -> V_16 = * V_16 ;
if ( V_14 & V_17 )
V_7 -> V_20 = * V_20 ;
if ( V_14 & V_21 )
V_7 -> V_22 = * V_22 ;
V_7 -> V_23 = V_36 -> V_49 ;
F_15 ( & V_7 -> V_9 ) ;
if ( V_37 == V_47 )
F_16 ( V_31 , V_4 ) ;
return V_37 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_29 , int V_50 )
{
unsigned char * V_51 = F_18 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_35 V_52 = {
. V_46 = V_7 -> V_53 ,
. V_54 = V_7 -> V_55 - V_50 ,
. V_56 = V_7 -> V_57 - V_29 ,
. V_49 = V_7 -> V_23 ,
} ;
struct V_58 V_59 ;
if ( F_19 ( V_2 , V_42 , sizeof( V_52 ) , & V_52 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_15 ) &&
F_19 ( V_2 , V_43 , sizeof( V_7 -> V_16 ) ,
& V_7 -> V_16 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_17 ) &&
F_19 ( V_2 , V_44 ,
sizeof( V_7 -> V_20 ) , & V_7 -> V_20 ) )
goto V_60;
if ( ( V_7 -> V_14 & V_21 ) &&
F_19 ( V_2 , V_45 , sizeof( V_7 -> V_22 ) ,
& V_7 -> V_22 ) )
goto V_60;
V_59 . V_61 = F_20 ( V_12 - V_7 -> V_10 . V_61 ) ;
V_59 . V_11 = F_20 ( V_12 - V_7 -> V_10 . V_11 ) ;
V_59 . V_62 = F_20 ( V_7 -> V_10 . V_62 ) ;
if ( F_21 ( V_2 , V_63 , sizeof( V_59 ) , & V_59 , V_64 ) )
goto V_60;
return V_2 -> V_65 ;
V_60:
F_22 ( V_2 , V_51 ) ;
return - 1 ;
}
static int F_23 ( struct V_24 * V_24 , struct V_1 * V_2 ,
struct V_66 * V_67 , int type ,
struct V_3 * V_4 )
{
struct V_30 * V_31 = F_7 ( V_24 , V_32 ) ;
return F_24 ( V_31 , V_2 , V_67 , type , V_4 ) ;
}
static int F_25 ( struct V_24 * V_24 , struct V_3 * V_4 , T_1 V_46 )
{
struct V_30 * V_31 = F_7 ( V_24 , V_32 ) ;
return F_26 ( V_31 , V_4 , V_46 ) ;
}
static T_3 int F_27 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_7 ( V_24 , V_32 ) ;
return F_28 ( V_31 , & V_68 , V_69 ) ;
}
static void T_4 F_29 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_7 ( V_24 , V_32 ) ;
F_30 ( V_31 ) ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_68 , & V_70 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_68 , & V_70 ) ;
}
