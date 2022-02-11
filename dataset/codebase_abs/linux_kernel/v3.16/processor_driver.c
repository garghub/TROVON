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
if ( V_19 == V_23 || V_19 == V_24 )
return V_25 ;
if ( ! V_7 || F_11 ( V_7 -> V_1 , & V_5 ) )
return V_25 ;
if ( V_19 == V_26 ) {
if ( V_7 -> V_27 . V_28 ) {
int V_29 ;
F_12 ( L_2 ,
V_7 -> V_30 ) ;
V_7 -> V_27 . V_28 = 0 ;
V_29 = F_13 ( V_5 ) ;
F_14 ( V_29 , L_3 , V_7 -> V_30 ) ;
} else {
F_3 ( V_7 , 0 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 , V_19 ) ;
F_7 ( V_7 ) ;
}
} else if ( V_19 == V_31 ) {
F_16 ( V_7 , V_19 ) ;
}
return V_32 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_3 V_33 ;
int V_34 = 0 ;
if ( ! V_7 )
return - V_35 ;
if ( V_7 -> V_27 . V_28 )
return 0 ;
#ifdef F_17
F_3 ( V_7 , 0 ) ;
#endif
F_18 ( V_7 ) ;
if ( V_7 -> V_27 . V_36 )
V_7 -> V_27 . V_37 = 1 ;
if ( ! F_19 () || F_19 () == & V_38 )
F_20 ( V_7 ) ;
V_7 -> V_39 = F_21 ( L_4 , V_5 ,
& V_40 ) ;
if ( F_22 ( V_7 -> V_39 ) ) {
V_34 = F_23 ( V_7 -> V_39 ) ;
goto V_41;
}
F_24 ( & V_5 -> V_13 , L_5 ,
V_7 -> V_39 -> V_30 ) ;
V_34 = F_25 ( & V_5 -> V_13 . V_42 ,
& V_7 -> V_39 -> V_5 . V_42 ,
L_6 ) ;
if ( V_34 ) {
F_26 ( & V_5 -> V_13 ,
L_7 ) ;
goto V_43;
}
V_34 = F_25 ( & V_7 -> V_39 -> V_5 . V_42 ,
& V_5 -> V_13 . V_42 ,
L_8 ) ;
if ( V_34 ) {
F_26 ( & V_7 -> V_39 -> V_5 ,
L_9 ) ;
goto V_44;
}
V_33 = F_27 ( V_5 -> V_1 , V_45 ,
F_1 , V_5 ) ;
if ( F_28 ( V_33 ) )
return 0 ;
F_29 ( & V_7 -> V_39 -> V_5 . V_42 , L_8 ) ;
V_44:
F_29 ( & V_5 -> V_13 . V_42 , L_6 ) ;
V_43:
F_30 ( V_7 -> V_39 ) ;
V_41:
F_31 ( V_7 ) ;
return V_34 ;
}
static int F_32 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_33 ( V_13 ) ;
if ( ! V_5 )
return - V_35 ;
return F_13 ( V_5 ) ;
}
static int F_34 ( struct V_5 * V_13 )
{
struct V_4 * V_5 = F_33 ( V_13 ) ;
struct V_6 * V_7 ;
if ( ! V_5 )
return 0 ;
F_35 ( V_5 -> V_1 , V_45 ,
F_1 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
F_31 ( V_7 ) ;
if ( V_7 -> V_39 ) {
F_29 ( & V_5 -> V_13 . V_42 , L_6 ) ;
F_29 ( & V_7 -> V_39 -> V_5 . V_42 , L_8 ) ;
F_30 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
}
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_34 = 0 ;
if ( V_46 )
return 0 ;
V_34 = F_37 ( & V_47 ) ;
if ( V_34 < 0 )
return V_34 ;
F_38 () ;
F_39 ( & V_48 ) ;
F_40 () ;
F_41 () ;
F_42 () ;
return 0 ;
}
static void T_5 F_43 ( void )
{
if ( V_46 )
return;
F_44 () ;
F_45 () ;
F_46 ( & V_48 ) ;
F_47 () ;
F_48 ( & V_47 ) ;
}
