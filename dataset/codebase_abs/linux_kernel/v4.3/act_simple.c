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
struct V_27 * V_31 [ V_32 + 1 ] ;
struct V_23 * V_33 ;
struct V_7 * V_8 ;
char * V_19 ;
int V_34 = 0 , V_35 ;
if ( V_28 == NULL )
return - V_36 ;
V_35 = F_17 ( V_31 , V_32 , V_28 , V_37 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_31 [ V_38 ] == NULL )
return - V_36 ;
if ( V_31 [ V_39 ] == NULL )
return - V_36 ;
V_33 = F_18 ( V_31 [ V_38 ] ) ;
V_19 = F_18 ( V_31 [ V_39 ] ) ;
if ( ! F_19 ( V_33 -> V_40 , V_4 , V_18 ) ) {
V_34 = F_20 ( V_33 -> V_40 , V_29 , V_4 , sizeof( * V_8 ) ,
V_18 , false ) ;
if ( V_34 )
return V_34 ;
V_8 = F_7 ( V_4 ) ;
V_34 = F_9 ( V_8 , V_19 ) ;
if ( V_34 < 0 ) {
F_21 ( V_4 , V_29 ) ;
return V_34 ;
}
V_8 -> V_17 = V_33 -> V_25 ;
V_34 = V_41 ;
} else {
V_8 = F_7 ( V_4 ) ;
if ( V_18 )
return 0 ;
F_22 ( V_4 , V_18 ) ;
if ( ! V_30 )
return - V_42 ;
F_13 ( V_8 , V_19 , V_33 ) ;
}
if ( V_34 == V_41 )
F_23 ( V_4 ) ;
return V_34 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_18 , int V_43 )
{
unsigned char * V_44 = F_25 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_23 V_45 = {
. V_40 = V_8 -> V_46 ,
. V_47 = V_8 -> V_48 - V_43 ,
. V_49 = V_8 -> V_50 - V_18 ,
. V_25 = V_8 -> V_17 ,
} ;
struct V_51 V_52 ;
if ( F_26 ( V_2 , V_38 , sizeof( V_45 ) , & V_45 ) ||
F_27 ( V_2 , V_39 , V_8 -> V_15 ) )
goto V_53;
V_52 . V_54 = F_28 ( V_13 - V_8 -> V_11 . V_54 ) ;
V_52 . V_12 = F_28 ( V_13 - V_8 -> V_11 . V_12 ) ;
V_52 . V_55 = F_28 ( V_8 -> V_11 . V_55 ) ;
if ( F_26 ( V_2 , V_56 , sizeof( V_52 ) , & V_52 ) )
goto V_53;
return V_2 -> V_57 ;
V_53:
F_29 ( V_2 , V_44 ) ;
return - 1 ;
}
static int T_1 F_30 ( void )
{
int V_34 ;
V_34 = F_31 ( & V_58 , V_59 ) ;
if ( ! V_34 )
F_4 ( L_2 ) ;
return V_34 ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_58 ) ;
}
