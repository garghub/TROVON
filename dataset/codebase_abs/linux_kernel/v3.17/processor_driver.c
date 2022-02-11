static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 ;
int V_8 ;
if ( V_5 -> V_1 != V_1 )
return;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return;
switch ( V_2 ) {
case V_9 :
V_8 = V_7 -> V_10 ;
F_3 ( V_7 , 1 ) ;
if ( V_8 == V_7 -> V_10 )
break;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 ,
V_7 -> V_10 ) ;
break;
case V_14 :
F_6 ( V_7 ) ;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
case V_15 :
F_7 ( V_7 ) ;
F_4 ( V_5 -> V_11 . V_12 ,
F_5 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
default:
F_8 ( ( V_16 ,
L_1 , V_2 ) ) ;
break;
}
return;
}
static int F_9 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
unsigned int V_21 = ( unsigned long ) V_20 ;
struct V_6 * V_7 = F_10 ( V_22 , V_21 ) ;
struct V_4 * V_5 ;
V_19 &= ~ V_23 ;
if ( V_19 == V_24 || V_19 == V_25 )
return V_26 ;
if ( ! V_7 || F_11 ( V_7 -> V_1 , & V_5 ) )
return V_26 ;
if ( V_19 == V_27 ) {
if ( V_7 -> V_28 . V_29 ) {
int V_30 ;
F_12 ( L_2 ,
V_7 -> V_31 ) ;
V_7 -> V_28 . V_29 = 0 ;
V_30 = F_13 ( V_5 ) ;
F_14 ( V_30 , L_3 , V_7 -> V_31 ) ;
} else {
F_3 ( V_7 , 0 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 , V_19 ) ;
F_7 ( V_7 ) ;
}
} else if ( V_19 == V_32 ) {
F_16 ( V_7 , V_19 ) ;
}
return V_33 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_3 V_34 ;
int V_35 = 0 ;
if ( ! V_7 )
return - V_36 ;
if ( V_7 -> V_28 . V_29 )
return 0 ;
#ifdef F_17
F_3 ( V_7 , 0 ) ;
#endif
F_18 ( V_7 ) ;
if ( V_7 -> V_28 . V_37 )
V_7 -> V_28 . V_38 = 1 ;
if ( ! F_19 () || F_19 () == & V_39 )
F_20 ( V_7 ) ;
V_7 -> V_40 = F_21 ( L_4 , V_5 ,
& V_41 ) ;
if ( F_22 ( V_7 -> V_40 ) ) {
V_35 = F_23 ( V_7 -> V_40 ) ;
goto V_42;
}
F_24 ( & V_5 -> V_13 , L_5 ,
V_7 -> V_40 -> V_31 ) ;
V_35 = F_25 ( & V_5 -> V_13 . V_43 ,
& V_7 -> V_40 -> V_5 . V_43 ,
L_6 ) ;
if ( V_35 ) {
F_26 ( & V_5 -> V_13 ,
L_7 ) ;
goto V_44;
}
V_35 = F_25 ( & V_7 -> V_40 -> V_5 . V_43 ,
& V_5 -> V_13 . V_43 ,
L_8 ) ;
if ( V_35 ) {
F_26 ( & V_7 -> V_40 -> V_5 ,
L_9 ) ;
goto V_45;
}
V_34 = F_27 ( V_5 -> V_1 , V_46 ,
F_1 , V_5 ) ;
if ( F_28 ( V_34 ) )
return 0 ;
F_29 ( & V_7 -> V_40 -> V_5 . V_43 , L_8 ) ;
V_45:
F_29 ( & V_5 -> V_13 . V_43 , L_6 ) ;
V_44:
F_30 ( V_7 -> V_40 ) ;
V_42:
F_31 ( V_7 ) ;
return V_35 ;
}
static int F_32 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_33 ( V_13 ) ;
if ( ! V_5 )
return - V_36 ;
return F_13 ( V_5 ) ;
}
static int F_34 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_33 ( V_13 ) ;
struct V_6 * V_7 ;
if ( ! V_5 )
return 0 ;
F_35 ( V_5 -> V_1 , V_46 ,
F_1 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
F_31 ( V_7 ) ;
if ( V_7 -> V_40 ) {
F_29 ( & V_5 -> V_13 . V_43 , L_6 ) ;
F_29 ( & V_7 -> V_40 -> V_5 . V_43 , L_8 ) ;
F_30 ( V_7 -> V_40 ) ;
V_7 -> V_40 = NULL ;
}
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_35 = 0 ;
if ( V_47 )
return 0 ;
V_35 = F_37 ( & V_48 ) ;
if ( V_35 < 0 )
return V_35 ;
F_38 () ;
F_39 ( & V_49 ) ;
F_40 () ;
F_41 () ;
F_42 () ;
return 0 ;
}
static void T_5 F_43 ( void )
{
if ( V_47 )
return;
F_44 () ;
F_45 () ;
F_46 ( & V_49 ) ;
F_47 () ;
F_48 ( & V_48 ) ;
}
