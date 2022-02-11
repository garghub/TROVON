static int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
if ( F_3 () % V_2 -> V_3 )
return V_2 -> V_4 ;
return V_2 -> V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_6 = F_5 ( & V_2 -> V_7 ) ;
F_2 () ;
if ( V_6 % V_2 -> V_3 )
return V_2 -> V_4 ;
return V_2 -> V_5 ;
}
static int F_6 ( struct V_8 * V_8 , struct V_9 * V_10 ,
struct V_9 * V_11 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
struct V_9 * V_19 [ V_20 + 1 ] ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
int V_24 ;
#ifdef F_8
struct V_25 * V_26 = NULL ;
#endif
if ( V_10 == NULL )
return - V_27 ;
V_24 = F_9 ( V_19 , V_20 , V_10 , V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_19 [ V_29 ] == NULL )
return - V_27 ;
V_22 = F_10 ( V_19 [ V_29 ] ) ;
#ifndef F_8
if ( V_19 [ V_30 ] != NULL )
return - V_31 ;
#else
if ( V_19 [ V_30 ] ) {
V_26 = F_10 ( V_19 [ V_30 ] ) ;
if ( V_26 -> V_32 >= V_33 )
return - V_27 ;
}
#endif
if ( ! F_11 ( V_17 , V_22 -> V_34 , V_13 , V_15 ) ) {
V_23 = F_12 ( V_17 , V_22 -> V_34 , V_11 , V_13 ,
sizeof( * V_2 ) , V_15 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = V_35 ;
} else {
if ( V_15 )
return 0 ;
F_13 ( V_13 , V_15 ) ;
if ( ! V_14 )
return - V_36 ;
}
V_2 = F_14 ( V_13 ) ;
F_15 () ;
V_2 -> V_4 = V_22 -> V_37 ;
#ifdef F_8
if ( V_26 ) {
V_2 -> V_5 = V_26 -> V_38 ;
V_2 -> V_3 = F_16 ( V_39 , 1 , V_26 -> V_40 ) ;
F_17 () ;
V_2 -> V_41 = V_26 -> V_32 ;
}
#endif
if ( V_23 == V_35 )
F_18 ( V_17 , V_13 ) ;
return V_23 ;
}
static int V_1 ( struct V_42 * V_43 , const struct V_12 * V_13 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_13 -> V_46 ;
int V_37 = F_19 ( V_2 -> V_4 ) ;
#ifdef F_8
{
T_1 V_32 = F_19 ( V_2 -> V_41 ) ;
if ( V_32 )
V_37 = V_47 [ V_32 ] ( V_2 ) ;
}
#endif
F_20 ( F_21 ( V_2 -> V_48 . V_49 ) , V_43 ) ;
if ( V_37 == V_50 )
F_22 ( F_21 ( V_2 -> V_48 . V_51 ) ) ;
F_23 ( & V_2 -> V_52 ) ;
return V_37 ;
}
static int F_24 ( struct V_42 * V_43 , struct V_12 * V_13 , int V_15 , int V_53 )
{
unsigned char * V_54 = F_25 ( V_43 ) ;
struct V_1 * V_2 = V_13 -> V_46 ;
struct V_21 V_55 = {
. V_34 = V_2 -> V_56 ,
. V_57 = V_2 -> V_58 - V_53 ,
. V_59 = V_2 -> V_60 - V_15 ,
. V_37 = V_2 -> V_4 ,
} ;
struct V_61 V_62 ;
if ( F_26 ( V_43 , V_29 , sizeof( V_55 ) , & V_55 ) )
goto V_63;
#ifdef F_8
if ( V_2 -> V_41 ) {
struct V_25 V_64 = {
. V_38 = V_2 -> V_5 ,
. V_40 = V_2 -> V_3 ,
. V_32 = V_2 -> V_41 ,
} ;
if ( F_26 ( V_43 , V_30 , sizeof( V_64 ) , & V_64 ) )
goto V_63;
}
#endif
V_62 . V_65 = F_27 ( V_66 - V_2 -> V_52 . V_65 ) ;
V_62 . V_67 = F_27 ( V_66 - V_2 -> V_52 . V_67 ) ;
V_62 . V_68 = F_27 ( V_2 -> V_52 . V_68 ) ;
if ( F_26 ( V_43 , V_69 , sizeof( V_62 ) , & V_62 ) )
goto V_63;
return V_43 -> V_70 ;
V_63:
F_28 ( V_43 , V_54 ) ;
return - 1 ;
}
static int F_29 ( struct V_8 * V_8 , struct V_42 * V_43 ,
struct V_71 * V_72 , int type ,
struct V_12 * V_13 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_30 ( V_17 , V_43 , V_72 , type , V_13 ) ;
}
static int F_31 ( struct V_8 * V_8 , struct V_12 * V_13 , T_1 V_34 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_32 ( V_17 , V_13 , V_34 ) ;
}
static T_2 int F_33 ( struct V_8 * V_8 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_34 ( V_17 , & V_73 , V_74 ) ;
}
static void T_3 F_35 ( struct V_8 * V_8 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
F_36 ( V_17 ) ;
}
static int T_4 F_37 ( void )
{
#ifdef F_8
F_38 ( L_1 ) ;
#else
F_38 ( L_2 ) ;
#endif
return F_39 ( & V_73 , & V_75 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_73 , & V_75 ) ;
}
