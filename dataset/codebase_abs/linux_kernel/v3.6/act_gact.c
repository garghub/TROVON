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
static int F_4 ( struct V_8 * V_9 , struct V_8 * V_10 ,
struct V_11 * V_12 , int V_13 , int V_14 )
{
struct V_8 * V_15 [ V_16 + 1 ] ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
int V_22 ;
#ifdef F_5
struct V_23 * V_24 = NULL ;
#endif
if ( V_9 == NULL )
return - V_25 ;
V_22 = F_6 ( V_15 , V_16 , V_9 , V_26 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_15 [ V_27 ] == NULL )
return - V_25 ;
V_18 = F_7 ( V_15 [ V_27 ] ) ;
#ifndef F_5
if ( V_15 [ V_28 ] != NULL )
return - V_29 ;
#else
if ( V_15 [ V_28 ] ) {
V_24 = F_7 ( V_15 [ V_28 ] ) ;
if ( V_24 -> V_30 >= V_31 )
return - V_25 ;
}
#endif
V_20 = F_8 ( V_18 -> V_32 , V_12 , V_14 , & V_33 ) ;
if ( ! V_20 ) {
V_20 = F_9 ( V_18 -> V_32 , V_10 , V_12 , sizeof( * V_2 ) ,
V_14 , & V_34 , & V_33 ) ;
if ( F_10 ( V_20 ) )
return F_11 ( V_20 ) ;
V_21 = V_35 ;
} else {
if ( ! V_13 ) {
F_12 ( V_20 , V_14 , & V_33 ) ;
return - V_36 ;
}
}
V_2 = F_13 ( V_20 ) ;
F_14 ( & V_2 -> V_37 ) ;
V_2 -> V_4 = V_18 -> V_38 ;
#ifdef F_5
if ( V_24 ) {
V_2 -> V_5 = V_24 -> V_39 ;
V_2 -> V_3 = V_24 -> V_40 ;
V_2 -> V_41 = V_24 -> V_30 ;
}
#endif
F_15 ( & V_2 -> V_37 ) ;
if ( V_21 == V_35 )
F_16 ( V_20 , & V_33 ) ;
return V_21 ;
}
static int F_17 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = V_12 -> V_42 ;
if ( V_2 )
return F_12 ( & V_2 -> V_43 , V_14 , & V_33 ) ;
return 0 ;
}
static int V_1 ( struct V_44 * V_45 , const struct V_11 * V_12 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_12 -> V_42 ;
int V_38 = V_48 ;
F_18 ( & V_2 -> V_37 ) ;
#ifdef F_5
if ( V_2 -> V_41 )
V_38 = V_49 [ V_2 -> V_41 ] ( V_2 ) ;
else
V_38 = V_2 -> V_4 ;
#else
V_38 = V_2 -> V_4 ;
#endif
V_2 -> V_6 . V_50 += F_19 ( V_45 ) ;
V_2 -> V_6 . V_7 ++ ;
if ( V_38 == V_48 )
V_2 -> V_51 . V_52 ++ ;
V_2 -> V_53 . V_54 = V_55 ;
F_20 ( & V_2 -> V_37 ) ;
return V_38 ;
}
static int F_21 ( struct V_44 * V_45 , struct V_11 * V_12 , int V_14 , int V_56 )
{
unsigned char * V_57 = F_22 ( V_45 ) ;
struct V_1 * V_2 = V_12 -> V_42 ;
struct V_17 V_58 = {
. V_32 = V_2 -> V_59 ,
. V_60 = V_2 -> V_61 - V_56 ,
. V_62 = V_2 -> V_63 - V_14 ,
. V_38 = V_2 -> V_4 ,
} ;
struct V_64 V_65 ;
if ( F_23 ( V_45 , V_27 , sizeof( V_58 ) , & V_58 ) )
goto V_66;
#ifdef F_5
if ( V_2 -> V_41 ) {
struct V_23 V_67 = {
. V_39 = V_2 -> V_5 ,
. V_40 = V_2 -> V_3 ,
. V_30 = V_2 -> V_41 ,
} ;
if ( F_23 ( V_45 , V_28 , sizeof( V_67 ) , & V_67 ) )
goto V_66;
}
#endif
V_65 . V_68 = F_24 ( V_55 - V_2 -> V_53 . V_68 ) ;
V_65 . V_54 = F_24 ( V_55 - V_2 -> V_53 . V_54 ) ;
V_65 . V_69 = F_24 ( V_2 -> V_53 . V_69 ) ;
if ( F_23 ( V_45 , V_70 , sizeof( V_65 ) , & V_65 ) )
goto V_66;
return V_45 -> V_71 ;
V_66:
F_25 ( V_45 , V_57 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
#ifdef F_5
F_27 ( L_1 ) ;
#else
F_27 ( L_2 ) ;
#endif
return F_28 ( & V_72 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_72 ) ;
}
