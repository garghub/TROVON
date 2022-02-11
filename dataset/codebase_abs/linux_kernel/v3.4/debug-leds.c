static void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
if ( ! ( V_4 & V_5 ) && V_1 != V_6 )
goto V_7;
switch ( V_1 ) {
case V_6 :
if ( V_8 )
V_4 |= V_5 ;
break;
case V_9 :
case V_10 :
if ( ! ( F_3 () || F_4 () ) ) {
F_5 ( V_11 , 0 ) ;
F_5 ( V_12 , 0 ) ;
}
F_6 ( ~ 0 , & V_8 -> V_13 ) ;
V_4 &= ~ V_5 ;
goto V_7;
case V_14 :
V_4 |= V_15 ;
V_16 = 0 ;
break;
case V_17 :
V_4 &= ~ V_15 ;
break;
#ifdef F_7
case V_18 :
V_4 ^= V_19 ;
if ( F_3 () || F_4 () )
V_16 ^= V_20 ;
else {
F_5 ( V_11 ,
V_4 & V_19 ) ;
goto V_7;
}
break;
#endif
#ifdef F_8
case V_21 :
if ( F_3 () || F_4 () )
V_16 &= ~ V_22 ;
else {
F_5 ( V_12 , 1 ) ;
goto V_7;
}
break;
case V_23 :
if ( F_3 () || F_4 () )
V_16 |= V_22 ;
else {
F_5 ( V_12 , 0 ) ;
goto V_7;
}
break;
#endif
case V_24 :
V_16 |= V_25 ;
break;
case V_26 :
V_16 &= ~ V_25 ;
break;
case V_27 :
V_16 |= V_28 ;
break;
case V_29 :
V_16 &= ~ V_28 ;
break;
case V_30 :
V_16 |= V_31 ;
break;
case V_32 :
V_16 &= ~ V_31 ;
break;
case V_33 :
V_16 |= V_34 ;
break;
case V_35 :
V_16 &= ~ V_34 ;
break;
default:
break;
}
if ( V_4 & V_5 )
F_6 ( ~ V_16 , & V_8 -> V_13 ) ;
V_7:
F_9 ( & V_3 , V_2 ) ;
}
static void
F_10 ( struct V_36 * V_37 , enum V_38 V_39 )
{
struct V_40 * V_41 = F_11 ( V_37 , struct V_40 , V_37 ) ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
if ( V_39 == V_42 )
V_16 &= ~ V_41 -> V_43 ;
else
V_16 |= V_41 -> V_43 ;
F_6 ( ~ V_16 , & V_8 -> V_13 ) ;
F_9 ( & V_3 , V_2 ) ;
}
static void T_2 F_12 ( struct V_44 * V_45 )
{
unsigned V_46 ;
struct V_40 * V_41 ;
int V_47 ;
for ( V_46 = 0 , V_41 = V_48 ; V_46 < F_13 ( V_48 ) ; V_46 ++ , V_41 ++ ) {
V_41 -> V_37 . V_49 = F_10 ;
V_47 = F_14 ( V_45 , & V_41 -> V_37 ) ;
if ( V_47 < 0 )
break;
}
return;
}
static int F_15 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
F_16 ( & V_3 ) ;
V_53 = F_17 ( V_51 , V_54 , 0 ) ;
if ( ! V_53 )
return - V_55 ;
V_8 = F_18 ( V_53 -> V_56 , V_57 ) ;
F_6 ( ~ 0 , & V_8 -> V_13 ) ;
#ifdef F_19
V_58 = F_1 ;
V_58 ( V_6 ) ;
#endif
if ( F_20 () ) {
F_12 ( & V_51 -> V_45 ) ;
}
return 0 ;
}
static int F_21 ( struct V_44 * V_45 )
{
F_6 ( ~ 0 , & V_8 -> V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 )
{
F_6 ( ~ V_16 , & V_8 -> V_13 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
if ( F_4 ()
|| F_24 ()
|| F_25 ()
|| F_3 ()
)
return F_26 ( & V_59 ) ;
return 0 ;
}
