void F_1 ( void )
{
struct V_1 V_2 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = 0 ;
V_2 . V_6 = V_7 ;
V_2 . V_8 = V_9 ;
if ( F_2 ( V_10 , & V_2 ) )
F_3 () ;
}
static void T_1 F_4 ( void )
{
T_2 V_11 ;
for ( V_11 = V_12 ;
! F_5 ( V_11 , V_11 + V_12 , V_13 ) ||
F_6 ( V_11 ) ;
V_11 += V_12 )
;
V_9 = F_7 ( V_11 ) ;
F_8 ( V_11 , V_12 ) ;
V_14 = F_9 ( V_11 , V_12 ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( V_14 , V_12 ) ;
V_14 = F_12 ( F_13 ( V_9 ) ) ;
}
static void T_1 F_14 ( void )
{
int V_15 , V_16 ;
T_3 V_17 , V_18 , V_19 , V_20 , V_21 ;
V_21 = F_15 () ;
V_17 = F_16 ( V_21 + 1 ) ;
V_15 = V_17 >> 16 ;
V_16 = V_17 & 0xffff ;
F_17 ( V_22 L_1 , V_15 , V_16 ) ;
V_23 = V_24 ;
if ( F_18 () )
V_25 . V_26 = L_2 ;
else {
T_2 V_27 ;
T_3 V_28 ;
V_25 . V_26 = L_3 ;
V_28 = F_19 ( V_21 + 2 ) ;
V_27 = F_20 ( V_29 ) ;
F_21 ( V_28 , ( V_30 ) V_27 , ( V_30 ) ( V_27 >> 32 ) ) ;
}
F_22 () ;
F_23 ( V_21 + 4 , & V_17 , & V_18 , & V_19 , & V_20 ) ;
if ( V_17 & V_31 )
F_24 ( V_32 , V_18 ) ;
else
F_24 ( V_32 , F_25 () ) ;
}
static void F_26 ( void )
{
F_27 () ;
if ( V_33 )
F_28 ( V_34 ) ;
}
static void F_29 ( struct V_35 * V_36 )
{
F_30 ( V_36 ) ;
F_28 ( V_34 ) ;
}
static int F_31 ( unsigned int V_37 )
{
int V_38 = 0 ;
if ( F_32 ( V_37 ) == V_39 ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
}
if ( F_35 ( V_37 ) != V_40 )
F_36 ( V_32 , V_37 ) = F_35 ( V_37 ) ;
else
F_36 ( V_32 , V_37 ) = V_37 ;
V_38 = F_37 ( V_37 ) ;
if ( V_38 )
return V_38 ;
if ( V_41 && F_38 ( V_42 ) )
F_39 ( V_37 ) ;
V_38 = F_40 ( V_37 ) ;
if ( V_38 ) {
F_41 ( 1 , L_4 ,
V_37 , V_38 ) ;
}
return V_38 ;
}
static int F_42 ( unsigned int V_37 )
{
F_33 ( V_37 ) ;
if ( V_41 && F_38 ( V_42 ) )
F_43 ( V_37 ) ;
return 0 ;
}
static void T_1 F_44 ( void )
{
if ( F_45 () )
return;
F_14 () ;
F_4 () ;
F_1 () ;
F_46 ( 0 ) ;
F_47 () ;
if ( F_38 ( V_43 ) )
V_41 = 1 ;
F_48 () ;
F_49 ( F_50 ( F_31 , F_42 ) ) ;
F_51 () ;
V_44 . V_45 . V_46 = V_47 ;
F_52 () ;
F_53 () ;
if ( F_18 () )
V_48 . V_49 = V_50 ;
#ifdef F_54
V_48 . V_51 = F_26 ;
V_48 . V_52 = F_29 ;
#endif
}
static T_1 int F_55 ( char * V_53 )
{
V_54 = true ;
return 0 ;
}
bool F_56 ( void )
{
if ( V_54 )
return false ;
if ( F_45 () )
return false ;
if ( ! F_57 () )
return false ;
if ( F_38 ( V_55 ) && V_41 )
return false ;
return true ;
}
static T_3 T_1 F_58 ( void )
{
if ( F_45 () || V_54 )
return 0 ;
return F_15 () ;
}
