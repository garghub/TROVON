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
int V_20 = 0 ;
int V_21 ;
#ifdef F_5
struct V_22 * V_23 = NULL ;
#endif
if ( V_10 == NULL )
return - V_24 ;
V_21 = F_6 ( V_16 , V_17 , V_10 , V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_16 [ V_26 ] == NULL )
return - V_24 ;
V_19 = F_7 ( V_16 [ V_26 ] ) ;
#ifndef F_5
if ( V_16 [ V_27 ] != NULL )
return - V_28 ;
#else
if ( V_16 [ V_27 ] ) {
V_23 = F_7 ( V_16 [ V_27 ] ) ;
if ( V_23 -> V_29 >= V_30 )
return - V_24 ;
}
#endif
if ( ! F_8 ( V_19 -> V_31 , V_13 , V_15 ) ) {
V_20 = F_9 ( V_19 -> V_31 , V_11 , V_13 , sizeof( * V_2 ) , V_15 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_32 ;
} else {
if ( V_15 )
return 0 ;
F_10 ( V_13 , V_15 ) ;
if ( ! V_14 )
return - V_33 ;
}
V_2 = F_11 ( V_13 ) ;
F_12 ( & V_2 -> V_34 ) ;
V_2 -> V_4 = V_19 -> V_35 ;
#ifdef F_5
if ( V_23 ) {
V_2 -> V_5 = V_23 -> V_36 ;
V_2 -> V_3 = V_23 -> V_37 ;
V_2 -> V_38 = V_23 -> V_29 ;
}
#endif
F_13 ( & V_2 -> V_34 ) ;
if ( V_20 == V_32 )
F_14 ( V_13 ) ;
return V_20 ;
}
static int V_1 ( struct V_39 * V_40 , const struct V_12 * V_13 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_13 -> V_43 ;
int V_35 = V_44 ;
F_15 ( & V_2 -> V_34 ) ;
#ifdef F_5
if ( V_2 -> V_38 )
V_35 = V_45 [ V_2 -> V_38 ] ( V_2 ) ;
else
V_35 = V_2 -> V_4 ;
#else
V_35 = V_2 -> V_4 ;
#endif
V_2 -> V_6 . V_46 += F_16 ( V_40 ) ;
V_2 -> V_6 . V_7 ++ ;
if ( V_35 == V_44 )
V_2 -> V_47 . V_48 ++ ;
V_2 -> V_49 . V_50 = V_51 ;
F_17 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_12 * V_13 , int V_15 , int V_52 )
{
unsigned char * V_53 = F_19 ( V_40 ) ;
struct V_1 * V_2 = V_13 -> V_43 ;
struct V_18 V_54 = {
. V_31 = V_2 -> V_55 ,
. V_56 = V_2 -> V_57 - V_52 ,
. V_58 = V_2 -> V_59 - V_15 ,
. V_35 = V_2 -> V_4 ,
} ;
struct V_60 V_61 ;
if ( F_20 ( V_40 , V_26 , sizeof( V_54 ) , & V_54 ) )
goto V_62;
#ifdef F_5
if ( V_2 -> V_38 ) {
struct V_22 V_63 = {
. V_36 = V_2 -> V_5 ,
. V_37 = V_2 -> V_3 ,
. V_29 = V_2 -> V_38 ,
} ;
if ( F_20 ( V_40 , V_27 , sizeof( V_63 ) , & V_63 ) )
goto V_62;
}
#endif
V_61 . V_64 = F_21 ( V_51 - V_2 -> V_49 . V_64 ) ;
V_61 . V_50 = F_21 ( V_51 - V_2 -> V_49 . V_50 ) ;
V_61 . V_65 = F_21 ( V_2 -> V_49 . V_65 ) ;
if ( F_20 ( V_40 , V_66 , sizeof( V_61 ) , & V_61 ) )
goto V_62;
return V_40 -> V_67 ;
V_62:
F_22 ( V_40 , V_53 ) ;
return - 1 ;
}
static int T_1 F_23 ( void )
{
#ifdef F_5
F_24 ( L_1 ) ;
#else
F_24 ( L_2 ) ;
#endif
return F_25 ( & V_68 , V_69 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_68 ) ;
}
