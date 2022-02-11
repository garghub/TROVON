static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || F_2 () % V_2 -> V_3 )
return V_2 -> V_4 ;
return V_2 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || V_2 -> V_6 . V_7 % V_2 -> V_3 )
return V_2 -> V_4 ;
return V_2 -> V_5 ;
}
static int F_4 ( struct V_8 * V_8 , struct V_9 * V_10 ,
struct V_9 * V_11 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_9 * V_16 [ V_17 + 1 ] ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
int V_23 ;
#ifdef F_5
struct V_24 * V_25 = NULL ;
#endif
if ( V_10 == NULL )
return - V_26 ;
V_23 = F_6 ( V_16 , V_17 , V_10 , V_27 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_16 [ V_28 ] == NULL )
return - V_26 ;
V_19 = F_7 ( V_16 [ V_28 ] ) ;
#ifndef F_5
if ( V_16 [ V_29 ] != NULL )
return - V_30 ;
#else
if ( V_16 [ V_29 ] ) {
V_25 = F_7 ( V_16 [ V_29 ] ) ;
if ( V_25 -> V_31 >= V_32 )
return - V_26 ;
}
#endif
V_21 = F_8 ( V_19 -> V_33 , V_13 , V_15 ) ;
if ( ! V_21 ) {
V_21 = F_9 ( V_19 -> V_33 , V_11 , V_13 , sizeof( * V_2 ) , V_15 ) ;
if ( F_10 ( V_21 ) )
return F_11 ( V_21 ) ;
V_22 = V_34 ;
} else {
if ( V_15 )
return 0 ;
F_12 ( V_21 , V_15 , V_13 -> V_35 -> V_36 ) ;
if ( ! V_14 )
return - V_37 ;
}
V_2 = F_13 ( V_21 ) ;
F_14 ( & V_2 -> V_38 ) ;
V_2 -> V_4 = V_19 -> V_39 ;
#ifdef F_5
if ( V_25 ) {
V_2 -> V_5 = V_25 -> V_40 ;
V_2 -> V_3 = V_25 -> V_41 ;
V_2 -> V_42 = V_25 -> V_31 ;
}
#endif
F_15 ( & V_2 -> V_38 ) ;
if ( V_22 == V_34 )
F_16 ( V_21 , V_13 -> V_35 -> V_36 ) ;
return V_22 ;
}
static int F_17 ( struct V_12 * V_13 , int V_15 )
{
struct V_1 * V_2 = V_13 -> V_43 ;
if ( V_2 )
return F_12 ( & V_2 -> V_44 , V_15 , V_13 -> V_35 -> V_36 ) ;
return 0 ;
}
static int V_1 ( struct V_45 * V_46 , const struct V_12 * V_13 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_13 -> V_43 ;
int V_39 = V_49 ;
F_18 ( & V_2 -> V_38 ) ;
#ifdef F_5
if ( V_2 -> V_42 )
V_39 = V_50 [ V_2 -> V_42 ] ( V_2 ) ;
else
V_39 = V_2 -> V_4 ;
#else
V_39 = V_2 -> V_4 ;
#endif
V_2 -> V_6 . V_51 += F_19 ( V_46 ) ;
V_2 -> V_6 . V_7 ++ ;
if ( V_39 == V_49 )
V_2 -> V_52 . V_53 ++ ;
V_2 -> V_54 . V_55 = V_56 ;
F_20 ( & V_2 -> V_38 ) ;
return V_39 ;
}
static int F_21 ( struct V_45 * V_46 , struct V_12 * V_13 , int V_15 , int V_57 )
{
unsigned char * V_58 = F_22 ( V_46 ) ;
struct V_1 * V_2 = V_13 -> V_43 ;
struct V_18 V_59 = {
. V_33 = V_2 -> V_60 ,
. V_61 = V_2 -> V_62 - V_57 ,
. V_63 = V_2 -> V_64 - V_15 ,
. V_39 = V_2 -> V_4 ,
} ;
struct V_65 V_66 ;
if ( F_23 ( V_46 , V_28 , sizeof( V_59 ) , & V_59 ) )
goto V_67;
#ifdef F_5
if ( V_2 -> V_42 ) {
struct V_24 V_68 = {
. V_40 = V_2 -> V_5 ,
. V_41 = V_2 -> V_3 ,
. V_31 = V_2 -> V_42 ,
} ;
if ( F_23 ( V_46 , V_29 , sizeof( V_68 ) , & V_68 ) )
goto V_67;
}
#endif
V_66 . V_69 = F_24 ( V_56 - V_2 -> V_54 . V_69 ) ;
V_66 . V_55 = F_24 ( V_56 - V_2 -> V_54 . V_55 ) ;
V_66 . V_70 = F_24 ( V_2 -> V_54 . V_70 ) ;
if ( F_23 ( V_46 , V_71 , sizeof( V_66 ) , & V_66 ) )
goto V_67;
return V_46 -> V_72 ;
V_67:
F_25 ( V_46 , V_58 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
int V_23 = F_27 ( & V_73 , V_74 ) ;
if ( V_23 )
return V_23 ;
#ifdef F_5
F_28 ( L_1 ) ;
#else
F_28 ( L_2 ) ;
#endif
return F_29 ( & V_75 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_75 ) ;
F_32 ( & V_73 ) ;
}
