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
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_23 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_33 * V_34 ;
int V_12 = V_16 ;
V_8 = F_24 ( V_6 ) ;
if ( ! V_8 )
goto V_35;
V_10 = V_8 -> V_10 ;
switch ( V_3 ) {
case V_36 :
V_34 = V_4 ;
V_12 = F_25 ( V_10 , V_8 , V_34 -> V_37 ,
V_34 -> V_38 ) ;
if ( V_12 ) {
V_12 = F_20 ( V_12 ) ;
break;
}
F_26 ( V_10 , V_8 , V_34 -> V_37 ,
V_34 -> V_38 ) ;
break;
case V_39 :
V_34 = V_4 ;
V_12 = F_27 ( V_10 , V_8 , V_34 -> V_37 ,
V_34 -> V_38 ) ;
if ( V_12 )
V_12 = F_20 ( V_12 ) ;
break;
case V_40 :
V_34 = V_4 ;
F_26 ( V_10 , V_8 , V_34 -> V_37 ,
V_34 -> V_38 ) ;
break;
}
V_35:
return V_12 ;
}
static void T_1 F_28 ( struct V_41 * V_41 )
{
struct V_5 * V_6 ;
F_29 ( V_42 ) ;
F_30 () ;
F_31 (net, dev)
if ( V_6 -> V_13 & V_14 )
F_32 ( V_6 , & V_42 ) ;
F_33 ( & V_42 ) ;
F_34 () ;
}
static int T_2 F_35 ( void )
{
int V_12 ;
F_36 ( sizeof( struct V_43 ) > F_37 ( struct V_44 , V_45 ) ) ;
V_12 = F_38 ( & V_46 ) ;
if ( V_12 < 0 ) {
F_39 ( L_1 ) ;
return V_12 ;
}
V_12 = F_40 () ;
if ( V_12 )
goto V_47;
V_12 = F_41 ( & V_48 ) ;
if ( V_12 )
goto V_49;
V_12 = F_42 () ;
if ( V_12 )
goto V_50;
V_12 = F_43 ( & V_51 ) ;
if ( V_12 )
goto V_52;
V_12 = F_44 ( & V_53 ) ;
if ( V_12 )
goto V_54;
V_12 = F_45 () ;
if ( V_12 )
goto V_55;
F_46 ( V_56 ) ;
#if F_47 ( V_57 )
V_58 = V_59 ;
#endif
#if F_48 ( V_60 )
F_49 ( L_2
L_3
L_4 ) ;
#endif
return 0 ;
V_55:
F_50 ( & V_53 ) ;
V_54:
F_51 ( & V_51 ) ;
V_52:
F_52 () ;
V_50:
F_53 ( & V_48 ) ;
V_49:
F_54 () ;
V_47:
F_55 ( & V_46 ) ;
return V_12 ;
}
static void T_3 F_56 ( void )
{
F_55 ( & V_46 ) ;
F_57 () ;
F_50 ( & V_53 ) ;
F_51 ( & V_51 ) ;
F_46 ( NULL ) ;
F_53 ( & V_48 ) ;
F_58 () ;
F_52 () ;
#if F_47 ( V_57 )
V_58 = NULL ;
#endif
F_54 () ;
}
