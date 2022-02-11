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
static void F_24 ( struct V_12 * V_13 , T_2 V_53 , T_1 V_7 ,
T_2 V_54 )
{
struct V_1 * V_2 = V_13 -> V_46 ;
int V_37 = F_19 ( V_2 -> V_4 ) ;
struct V_55 * V_56 = & V_2 -> V_52 ;
F_25 ( F_21 ( V_2 -> V_48 . V_49 ) , V_53 , V_7 ) ;
if ( V_37 == V_50 )
F_21 ( V_2 -> V_48 . V_51 ) -> V_57 += V_7 ;
V_56 -> V_54 = V_54 ;
}
static int F_26 ( struct V_42 * V_43 , struct V_12 * V_13 , int V_15 , int V_58 )
{
unsigned char * V_59 = F_27 ( V_43 ) ;
struct V_1 * V_2 = V_13 -> V_46 ;
struct V_21 V_60 = {
. V_34 = V_2 -> V_61 ,
. V_62 = V_2 -> V_63 - V_58 ,
. V_64 = V_2 -> V_65 - V_15 ,
. V_37 = V_2 -> V_4 ,
} ;
struct V_55 V_66 ;
if ( F_28 ( V_43 , V_29 , sizeof( V_60 ) , & V_60 ) )
goto V_67;
#ifdef F_8
if ( V_2 -> V_41 ) {
struct V_25 V_68 = {
. V_38 = V_2 -> V_5 ,
. V_40 = V_2 -> V_3 ,
. V_32 = V_2 -> V_41 ,
} ;
if ( F_28 ( V_43 , V_30 , sizeof( V_68 ) , & V_68 ) )
goto V_67;
}
#endif
V_66 . V_69 = F_29 ( V_70 - V_2 -> V_52 . V_69 ) ;
V_66 . V_54 = F_29 ( V_70 - V_2 -> V_52 . V_54 ) ;
V_66 . V_71 = F_29 ( V_2 -> V_52 . V_71 ) ;
if ( F_30 ( V_43 , V_72 , sizeof( V_66 ) , & V_66 , V_73 ) )
goto V_67;
return V_43 -> V_74 ;
V_67:
F_31 ( V_43 , V_59 ) ;
return - 1 ;
}
static int F_32 ( struct V_8 * V_8 , struct V_42 * V_43 ,
struct V_75 * V_76 , int type ,
struct V_12 * V_13 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_33 ( V_17 , V_43 , V_76 , type , V_13 ) ;
}
static int F_34 ( struct V_8 * V_8 , struct V_12 * V_13 , T_1 V_34 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_35 ( V_17 , V_13 , V_34 ) ;
}
static T_3 int F_36 ( struct V_8 * V_8 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
return F_37 ( V_17 , & V_77 , V_78 ) ;
}
static void T_4 F_38 ( struct V_8 * V_8 )
{
struct V_16 * V_17 = F_7 ( V_8 , V_18 ) ;
F_39 ( V_17 ) ;
}
static int T_5 F_40 ( void )
{
#ifdef F_8
F_41 ( L_1 ) ;
#else
F_41 ( L_2 ) ;
#endif
return F_42 ( & V_77 , & V_79 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_77 , & V_79 ) ;
}
