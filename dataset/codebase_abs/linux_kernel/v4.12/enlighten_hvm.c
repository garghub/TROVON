void T_1 F_1 ( void )
{
int V_1 ;
struct V_2 V_3 ;
static struct V_4 * V_5 ;
if ( ! V_5 )
V_5 = (struct V_4 * )
F_2 ( V_6 , V_6 ) ;
V_3 . V_7 = V_8 ;
V_3 . V_9 = 0 ;
V_3 . V_10 = V_11 ;
V_3 . V_12 = F_3 ( V_5 ) >> V_13 ;
if ( F_4 ( V_14 , & V_3 ) )
F_5 () ;
V_15 = (struct V_4 * ) V_5 ;
F_6 (cpu) {
if ( F_7 ( V_1 ) >= V_16 )
continue;
F_8 ( V_17 , V_1 ) =
& V_15 -> V_18 [ F_7 ( V_1 ) ] ;
}
}
static void T_2 F_9 ( void )
{
int V_19 , V_20 ;
T_3 V_21 , V_22 , V_23 , V_24 , V_25 ;
V_25 = F_10 () ;
V_21 = F_11 ( V_25 + 1 ) ;
V_19 = V_21 >> 16 ;
V_20 = V_21 & 0xffff ;
F_12 ( V_26 L_1 , V_19 , V_20 ) ;
V_27 = V_28 ;
if ( F_13 () )
V_29 . V_30 = L_2 ;
else {
T_4 V_31 ;
T_3 V_32 ;
V_29 . V_30 = L_3 ;
V_32 = F_14 ( V_25 + 2 ) ;
V_31 = F_3 ( V_33 ) ;
F_15 ( V_32 , ( V_34 ) V_31 , ( V_34 ) ( V_31 >> 32 ) ) ;
}
F_16 () ;
F_17 ( V_25 + 4 , & V_21 , & V_22 , & V_23 , & V_24 ) ;
if ( V_21 & V_35 )
F_18 ( V_36 , V_22 ) ;
else
F_18 ( V_36 , F_19 () ) ;
}
static void F_20 ( void )
{
F_21 () ;
if ( V_37 )
F_22 ( V_38 ) ;
}
static void F_23 ( struct V_39 * V_40 )
{
F_24 ( V_40 ) ;
F_22 ( V_38 ) ;
}
static int F_25 ( unsigned int V_1 )
{
int V_41 ;
if ( F_26 ( V_1 ) == V_42 ) {
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
}
if ( F_29 ( V_1 ) != V_43 )
F_8 ( V_36 , V_1 ) = F_29 ( V_1 ) ;
else
F_8 ( V_36 , V_1 ) = V_1 ;
F_30 ( V_1 ) ;
if ( V_44 && F_31 ( V_45 ) )
F_32 ( V_1 ) ;
V_41 = F_33 ( V_1 ) ;
if ( V_41 ) {
F_34 ( 1 , L_4 ,
V_1 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static int F_35 ( unsigned int V_1 )
{
F_27 ( V_1 ) ;
if ( V_44 && F_31 ( V_45 ) )
F_36 ( V_1 ) ;
return 0 ;
}
static void T_2 F_37 ( void )
{
if ( F_38 () )
return;
F_9 () ;
F_1 () ;
F_39 () ;
if ( F_31 ( V_46 ) )
V_44 = 1 ;
F_40 () ;
F_41 ( F_42 ( F_25 , F_35 ) ) ;
F_43 () ;
V_47 . V_48 . V_49 = V_50 ;
F_44 () ;
F_45 () ;
if ( F_13 () )
V_51 . V_52 = V_53 ;
#ifdef F_46
V_51 . V_54 = F_20 ;
V_51 . V_55 = F_23 ;
#endif
}
static T_2 int F_47 ( char * V_56 )
{
V_57 = true ;
return 0 ;
}
bool F_48 ( void )
{
if ( V_57 )
return false ;
if ( F_38 () )
return false ;
if ( ! F_49 () )
return false ;
if ( F_31 ( V_58 ) && V_44 )
return false ;
return true ;
}
static T_3 T_2 F_50 ( void )
{
if ( F_38 () || V_57 )
return 0 ;
return F_10 () ;
}
