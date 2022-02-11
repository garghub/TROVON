static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_2 ( & V_8 -> V_10 ) ;
V_8 -> V_11 . V_12 = V_13 ;
F_3 ( & V_8 -> V_14 , V_2 ) ;
F_4 ( L_1 ,
( char * ) V_8 -> V_15 , V_8 -> V_14 . V_16 ) ;
F_5 ( & V_8 -> V_10 ) ;
return V_8 -> V_17 ;
}
static void F_6 ( struct V_3 * V_4 , int V_18 )
{
struct V_7 * V_8 = F_7 ( V_4 ) ;
F_8 ( V_8 -> V_15 ) ;
}
static int F_9 ( struct V_7 * V_8 , char * V_19 )
{
V_8 -> V_15 = F_10 ( V_20 , V_21 ) ;
if ( F_11 ( ! V_8 -> V_15 ) )
return - V_22 ;
F_12 ( V_8 -> V_15 , V_19 , V_20 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 , char * V_19 ,
struct V_23 * V_24 )
{
F_14 ( & V_8 -> V_10 ) ;
V_8 -> V_17 = V_24 -> V_25 ;
memset ( V_8 -> V_15 , 0 , V_20 ) ;
F_12 ( V_8 -> V_15 , V_19 , V_20 ) ;
F_15 ( & V_8 -> V_10 ) ;
}
static int F_16 ( struct V_26 * V_26 , struct V_27 * V_28 ,
struct V_27 * V_29 , struct V_3 * V_4 ,
int V_30 , int V_18 )
{
struct V_31 * V_32 = F_17 ( V_26 , V_33 ) ;
struct V_27 * V_34 [ V_35 + 1 ] ;
struct V_23 * V_36 ;
struct V_7 * V_8 ;
char * V_19 ;
int V_37 = 0 , V_38 , V_39 = 0 ;
if ( V_28 == NULL )
return - V_40 ;
V_38 = F_18 ( V_34 , V_35 , V_28 , V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_34 [ V_42 ] == NULL )
return - V_40 ;
V_36 = F_19 ( V_34 [ V_42 ] ) ;
V_39 = F_20 ( V_32 , V_36 -> V_43 , V_4 , V_18 ) ;
if ( V_39 && V_18 )
return 0 ;
if ( V_34 [ V_44 ] == NULL ) {
if ( V_39 )
F_21 ( V_4 , V_18 ) ;
return - V_40 ;
}
V_19 = F_19 ( V_34 [ V_44 ] ) ;
if ( ! V_39 ) {
V_37 = F_22 ( V_32 , V_36 -> V_43 , V_29 , V_4 ,
sizeof( * V_8 ) , V_18 , false ) ;
if ( V_37 )
return V_37 ;
V_8 = F_7 ( V_4 ) ;
V_37 = F_9 ( V_8 , V_19 ) ;
if ( V_37 < 0 ) {
F_23 ( V_4 , V_29 ) ;
return V_37 ;
}
V_8 -> V_17 = V_36 -> V_25 ;
V_37 = V_45 ;
} else {
V_8 = F_7 ( V_4 ) ;
F_21 ( V_4 , V_18 ) ;
if ( ! V_30 )
return - V_46 ;
F_13 ( V_8 , V_19 , V_36 ) ;
}
if ( V_37 == V_45 )
F_24 ( V_32 , V_4 ) ;
return V_37 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_18 , int V_47 )
{
unsigned char * V_48 = F_26 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_23 V_49 = {
. V_43 = V_8 -> V_50 ,
. V_51 = V_8 -> V_52 - V_47 ,
. V_53 = V_8 -> V_54 - V_18 ,
. V_25 = V_8 -> V_17 ,
} ;
struct V_55 V_56 ;
if ( F_27 ( V_2 , V_42 , sizeof( V_49 ) , & V_49 ) ||
F_28 ( V_2 , V_44 , V_8 -> V_15 ) )
goto V_57;
V_56 . V_58 = F_29 ( V_13 - V_8 -> V_11 . V_58 ) ;
V_56 . V_12 = F_29 ( V_13 - V_8 -> V_11 . V_12 ) ;
V_56 . V_59 = F_29 ( V_8 -> V_11 . V_59 ) ;
if ( F_27 ( V_2 , V_60 , sizeof( V_56 ) , & V_56 ) )
goto V_57;
return V_2 -> V_61 ;
V_57:
F_30 ( V_2 , V_48 ) ;
return - 1 ;
}
static int F_31 ( struct V_26 * V_26 , struct V_1 * V_2 ,
struct V_62 * V_63 , int type ,
struct V_3 * V_4 )
{
struct V_31 * V_32 = F_17 ( V_26 , V_33 ) ;
return F_32 ( V_32 , V_2 , V_63 , type , V_4 ) ;
}
static int F_33 ( struct V_26 * V_26 , struct V_3 * V_4 , T_1 V_43 )
{
struct V_31 * V_32 = F_17 ( V_26 , V_33 ) ;
return F_34 ( V_32 , V_4 , V_43 ) ;
}
static T_2 int F_35 ( struct V_26 * V_26 )
{
struct V_31 * V_32 = F_17 ( V_26 , V_33 ) ;
return F_36 ( V_32 , & V_64 , V_65 ) ;
}
static void T_3 F_37 ( struct V_26 * V_26 )
{
struct V_31 * V_32 = F_17 ( V_26 , V_33 ) ;
F_38 ( V_32 ) ;
}
static int T_4 F_39 ( void )
{
int V_37 = F_40 ( & V_64 , & V_66 ) ;
if ( ! V_37 )
F_4 ( L_2 ) ;
return V_37 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_64 , & V_66 ) ;
}
