struct V_1 * F_1 ( void )
{
return V_2 ;
}
static T_1 F_2 ( struct V_3 * V_4 )
{
T_1 V_5 = F_3 ( V_2 ) ;
if ( V_5 == V_6 )
F_4 ( V_7 , V_5 ) ;
return V_5 ;
}
static T_1 F_5 ( struct V_3 * V_4 )
{
T_1 V_5 ;
F_4 ( V_7 , V_5 ) ;
return V_5 ;
}
static int F_6 ( unsigned int V_8 )
{
T_1 V_9 ;
F_7 ( V_9 ) ;
V_10 [ F_8 () ] = V_9 ;
if ( V_9 > V_11 )
V_11 = V_9 ;
return 0 ;
}
void F_9 ( void )
{
T_1 V_12 ;
union V_13 V_14 ;
if ( V_15 != & V_16 )
return;
V_10 = F_10 ( F_11 () , sizeof( * V_10 ) ,
V_17 ) ;
if ( ! V_10 )
return;
if ( F_12 ( V_18 , L_1 ,
F_6 , NULL ) < 0 )
goto V_19;
V_12 = F_13 ( 0 , V_20 , 0 ) ;
F_14 ( V_21 , V_12 ) ;
V_22 = F_15 ( V_23 , V_17 , V_24 ) ;
if ( V_22 == NULL ) {
F_14 ( V_21 , 0 ) ;
goto V_19;
}
F_4 ( V_25 , V_14 . V_26 ) ;
V_14 . V_27 = 1 ;
V_14 . V_28 = F_16 ( V_22 ) ;
F_14 ( V_25 , V_14 . V_26 ) ;
F_17 () ;
#ifdef F_18
if ( V_29 . V_30 & V_31 ) {
union V_13 V_32 ;
V_2 = F_15 ( V_23 , V_17 , V_33 ) ;
if ( ! V_2 )
goto V_34;
V_35 = & V_36 ;
F_4 ( V_37 , V_32 . V_26 ) ;
V_32 . V_27 = 1 ;
V_32 . V_28 = F_16 ( V_2 ) ;
F_14 ( V_37 , V_32 . V_26 ) ;
V_36 . V_38 . V_39 = V_40 ;
F_19 ( & V_36 , V_41 / 100 ) ;
return;
}
V_34:
#endif
V_35 = & V_42 ;
if ( V_29 . V_30 & V_43 )
F_19 ( & V_42 , V_41 / 100 ) ;
return;
V_19:
F_20 ( V_10 ) ;
V_10 = NULL ;
}
void F_21 ( void )
{
union V_13 V_14 ;
F_14 ( V_21 , 0 ) ;
V_14 . V_26 = 0 ;
F_14 ( V_25 , V_14 . V_26 ) ;
V_14 . V_26 = 0 ;
F_14 ( V_37 , V_14 . V_26 ) ;
}
void F_22 ( struct V_44 * V_45 )
{
static bool V_46 ;
if ( V_46 )
return;
V_46 = true ;
F_14 ( V_47 , V_45 -> V_48 ) ;
F_14 ( V_49 , V_45 -> V_50 ) ;
F_14 ( V_51 , V_45 -> V_52 ) ;
F_14 ( V_53 , V_45 -> V_54 ) ;
F_14 ( V_55 , V_45 -> V_56 ) ;
F_14 ( V_57 , V_58 ) ;
}
bool F_23 ( void )
{
union V_13 V_14 ;
V_14 . V_26 = 0 ;
F_4 ( V_25 , V_14 . V_26 ) ;
if ( ! V_14 . V_27 )
return false ;
return true ;
}
