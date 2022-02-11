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
if ( V_9 == NULL )
return - V_23 ;
V_22 = F_5 ( V_15 , V_16 , V_9 , V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_15 [ V_25 ] == NULL )
return - V_23 ;
V_18 = F_6 ( V_15 [ V_25 ] ) ;
#ifndef F_7
if ( V_15 [ V_26 ] != NULL )
return - V_27 ;
#endif
V_20 = F_8 ( V_18 -> V_28 , V_12 , V_14 , & V_29 ) ;
if ( ! V_20 ) {
V_20 = F_9 ( V_18 -> V_28 , V_10 , V_12 , sizeof( * V_2 ) ,
V_14 , & V_30 , & V_29 ) ;
if ( F_10 ( V_20 ) )
return F_11 ( V_20 ) ;
V_21 = V_31 ;
} else {
if ( ! V_13 ) {
F_12 ( V_20 , V_14 , & V_29 ) ;
return - V_32 ;
}
}
V_2 = F_13 ( V_20 ) ;
F_14 ( & V_2 -> V_33 ) ;
V_2 -> V_4 = V_18 -> V_34 ;
#ifdef F_7
if ( V_15 [ V_26 ] != NULL ) {
struct V_35 * V_36 = F_6 ( V_15 [ V_26 ] ) ;
V_2 -> V_5 = V_36 -> V_37 ;
V_2 -> V_3 = V_36 -> V_38 ;
V_2 -> V_39 = V_36 -> V_40 ;
}
#endif
F_15 ( & V_2 -> V_33 ) ;
if ( V_21 == V_31 )
F_16 ( V_20 , & V_29 ) ;
return V_21 ;
}
static int F_17 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = V_12 -> V_41 ;
if ( V_2 )
return F_12 ( & V_2 -> V_42 , V_14 , & V_29 ) ;
return 0 ;
}
static int V_1 ( struct V_43 * V_44 , const struct V_11 * V_12 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_12 -> V_41 ;
int V_34 = V_47 ;
F_18 ( & V_2 -> V_33 ) ;
#ifdef F_7
if ( V_2 -> V_39 && V_48 [ V_2 -> V_39 ] != NULL )
V_34 = V_48 [ V_2 -> V_39 ] ( V_2 ) ;
else
V_34 = V_2 -> V_4 ;
#else
V_34 = V_2 -> V_4 ;
#endif
V_2 -> V_6 . V_49 += F_19 ( V_44 ) ;
V_2 -> V_6 . V_7 ++ ;
if ( V_34 == V_47 )
V_2 -> V_50 . V_51 ++ ;
V_2 -> V_52 . V_53 = V_54 ;
F_20 ( & V_2 -> V_33 ) ;
return V_34 ;
}
static int F_21 ( struct V_43 * V_44 , struct V_11 * V_12 , int V_14 , int V_55 )
{
unsigned char * V_56 = F_22 ( V_44 ) ;
struct V_1 * V_2 = V_12 -> V_41 ;
struct V_17 V_57 = {
. V_28 = V_2 -> V_58 ,
. V_59 = V_2 -> V_60 - V_55 ,
. V_61 = V_2 -> V_62 - V_14 ,
. V_34 = V_2 -> V_4 ,
} ;
struct V_63 V_64 ;
F_23 ( V_44 , V_25 , sizeof( V_57 ) , & V_57 ) ;
#ifdef F_7
if ( V_2 -> V_39 ) {
struct V_35 V_65 = {
. V_37 = V_2 -> V_5 ,
. V_38 = V_2 -> V_3 ,
. V_40 = V_2 -> V_39 ,
} ;
F_23 ( V_44 , V_26 , sizeof( V_65 ) , & V_65 ) ;
}
#endif
V_64 . V_66 = F_24 ( V_54 - V_2 -> V_52 . V_66 ) ;
V_64 . V_53 = F_24 ( V_54 - V_2 -> V_52 . V_53 ) ;
V_64 . V_67 = F_24 ( V_2 -> V_52 . V_67 ) ;
F_23 ( V_44 , V_68 , sizeof( V_64 ) , & V_64 ) ;
return V_44 -> V_69 ;
V_70:
F_25 ( V_44 , V_56 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
#ifdef F_7
F_27 ( L_1 ) ;
#else
F_27 ( L_2 ) ;
#endif
return F_28 ( & V_71 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_71 ) ;
}
