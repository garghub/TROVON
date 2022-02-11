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
if ( ! V_7 || F_11 ( V_7 -> V_1 , & V_5 ) )
return V_23 ;
if ( V_19 == V_24 ) {
if ( V_7 -> V_25 . V_26 ) {
int V_27 ;
F_12 ( L_2 ,
V_7 -> V_28 ) ;
V_7 -> V_25 . V_26 = 0 ;
V_27 = F_13 ( V_5 ) ;
F_14 ( V_27 , L_3 , V_7 -> V_28 ) ;
} else {
F_3 ( V_7 , 0 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 , V_19 ) ;
F_7 ( V_7 ) ;
}
} else if ( V_19 == V_29 ) {
F_16 ( V_7 , V_19 ) ;
}
return V_30 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_3 V_31 ;
int V_32 = 0 ;
if ( ! V_7 )
return - V_33 ;
if ( V_7 -> V_25 . V_26 )
return 0 ;
#ifdef F_17
F_3 ( V_7 , 0 ) ;
F_18 ( V_7 ) ;
#endif
F_19 ( V_7 ) ;
if ( V_7 -> V_25 . V_34 )
V_7 -> V_25 . V_35 = 1 ;
if ( ! F_20 () || F_20 () == & V_36 )
F_21 ( V_7 ) ;
V_7 -> V_37 = F_22 ( L_4 , V_5 ,
& V_38 ) ;
if ( F_23 ( V_7 -> V_37 ) ) {
V_32 = F_24 ( V_7 -> V_37 ) ;
goto V_39;
}
F_25 ( & V_5 -> V_13 , L_5 ,
V_7 -> V_37 -> V_28 ) ;
V_32 = F_26 ( & V_5 -> V_13 . V_40 ,
& V_7 -> V_37 -> V_5 . V_40 ,
L_6 ) ;
if ( V_32 ) {
F_27 ( & V_5 -> V_13 ,
L_7 ) ;
goto V_41;
}
V_32 = F_26 ( & V_7 -> V_37 -> V_5 . V_40 ,
& V_5 -> V_13 . V_40 ,
L_8 ) ;
if ( V_32 ) {
F_27 ( & V_7 -> V_37 -> V_5 ,
L_9 ) ;
goto V_42;
}
V_31 = F_28 ( V_5 -> V_1 , V_43 ,
F_1 , V_5 ) ;
if ( F_29 ( V_31 ) )
return 0 ;
F_30 ( & V_7 -> V_37 -> V_5 . V_40 , L_8 ) ;
V_42:
F_30 ( & V_5 -> V_13 . V_40 , L_6 ) ;
V_41:
F_31 ( V_7 -> V_37 ) ;
V_39:
F_32 ( V_7 ) ;
return V_32 ;
}
static int F_33 ( struct V_5 * V_13 )
{
struct V_4 * V_5 ;
if ( F_11 ( F_34 ( V_13 ) , & V_5 ) )
return - V_33 ;
return F_13 ( V_5 ) ;
}
static int F_35 ( struct V_5 * V_13 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( F_11 ( F_34 ( V_13 ) , & V_5 ) )
return 0 ;
F_36 ( V_5 -> V_1 , V_43 ,
F_1 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
F_32 ( V_7 ) ;
if ( V_7 -> V_37 ) {
F_30 ( & V_5 -> V_13 . V_40 , L_6 ) ;
F_30 ( & V_7 -> V_37 -> V_5 . V_40 , L_8 ) ;
F_31 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
}
return 0 ;
}
static int T_4 F_37 ( void )
{
int V_32 = 0 ;
if ( V_44 )
return 0 ;
V_32 = F_38 ( & V_45 ) ;
if ( V_32 < 0 )
return V_32 ;
F_39 () ;
F_40 ( & V_46 ) ;
F_41 () ;
F_42 () ;
F_43 () ;
return 0 ;
}
static void T_5 F_44 ( void )
{
if ( V_44 )
return;
F_45 () ;
F_46 () ;
F_47 ( & V_46 ) ;
F_48 () ;
F_49 ( & V_45 ) ;
}
