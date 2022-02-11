static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
bool V_11 ;
int V_12 ;
if ( ( V_6 -> V_13 & V_14 ) && V_3 == V_15 ) {
F_3 ( V_6 ) ;
return V_16 ;
}
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
return V_16 ;
V_10 = V_8 -> V_10 ;
switch ( V_3 ) {
case V_17 :
F_5 ( V_10 -> V_6 , F_6 ( V_10 ) ) ;
break;
case V_18 :
F_7 ( & V_10 -> V_19 ) ;
F_8 ( V_8 , V_6 -> V_20 ) ;
V_11 = F_9 ( V_10 ) ;
F_10 ( & V_10 -> V_19 ) ;
if ( V_11 )
F_11 ( V_18 , V_10 -> V_6 ) ;
break;
case V_21 :
F_12 ( V_8 ) ;
break;
case V_22 :
F_13 ( V_10 -> V_6 ) ;
break;
case V_23 :
F_7 ( & V_10 -> V_19 ) ;
if ( V_10 -> V_6 -> V_24 & V_25 )
F_14 ( V_8 ) ;
F_10 ( & V_10 -> V_19 ) ;
break;
case V_26 :
if ( F_15 ( V_10 -> V_6 ) && F_16 ( V_6 ) ) {
F_7 ( & V_10 -> V_19 ) ;
F_17 ( V_8 ) ;
F_10 ( & V_10 -> V_19 ) ;
}
break;
case V_27 :
F_18 ( V_10 , V_6 ) ;
break;
case V_28 :
V_12 = F_19 ( V_8 ) ;
if ( V_12 )
return F_20 ( V_12 ) ;
break;
case V_29 :
return V_30 ;
case V_31 :
F_11 ( V_3 , V_10 -> V_6 ) ;
break;
}
if ( V_3 == V_18 || V_3 == V_26 ||
V_3 == V_21 || V_3 == V_23 )
F_21 ( V_32 , V_8 ) ;
return V_16 ;
}
static void T_1 F_22 ( struct V_33 * V_33 )
{
struct V_5 * V_6 ;
F_23 ( V_34 ) ;
F_24 () ;
F_25 (net, dev)
if ( V_6 -> V_13 & V_14 )
F_26 ( V_6 , & V_34 ) ;
F_27 ( & V_34 ) ;
F_28 () ;
}
static int T_2 F_29 ( void )
{
int V_12 ;
V_12 = F_30 ( & V_35 ) ;
if ( V_12 < 0 ) {
F_31 ( L_1 ) ;
return V_12 ;
}
V_12 = F_32 () ;
if ( V_12 )
goto V_36;
V_12 = F_33 ( & V_37 ) ;
if ( V_12 )
goto V_38;
V_12 = F_34 () ;
if ( V_12 )
goto V_39;
V_12 = F_35 ( & V_40 ) ;
if ( V_12 )
goto V_41;
V_12 = F_36 () ;
if ( V_12 )
goto V_42;
F_37 ( V_43 ) ;
#if F_38 ( V_44 )
V_45 = V_46 ;
#endif
return 0 ;
V_42:
F_39 ( & V_40 ) ;
V_41:
F_40 () ;
V_39:
F_41 ( & V_37 ) ;
V_38:
F_42 () ;
V_36:
F_43 ( & V_35 ) ;
return V_12 ;
}
static void T_3 F_44 ( void )
{
F_43 ( & V_35 ) ;
F_45 () ;
F_39 ( & V_40 ) ;
F_37 ( NULL ) ;
F_41 ( & V_37 ) ;
F_46 () ;
F_40 () ;
#if F_38 ( V_44 )
V_45 = NULL ;
#endif
F_42 () ;
}
