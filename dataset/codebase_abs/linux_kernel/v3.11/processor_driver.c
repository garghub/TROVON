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
F_4 ( V_5 , V_2 ,
V_7 -> V_10 ) ;
F_5 ( V_5 -> V_11 . V_12 ,
F_6 ( & V_5 -> V_13 ) , V_2 ,
V_7 -> V_10 ) ;
break;
case V_14 :
F_7 ( V_7 ) ;
F_4 ( V_5 , V_2 , 0 ) ;
F_5 ( V_5 -> V_11 . V_12 ,
F_6 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
case V_15 :
F_8 ( V_7 ) ;
F_4 ( V_5 , V_2 , 0 ) ;
F_5 ( V_5 -> V_11 . V_12 ,
F_6 ( & V_5 -> V_13 ) , V_2 , 0 ) ;
break;
default:
F_9 ( ( V_16 ,
L_1 , V_2 ) ) ;
break;
}
return;
}
static int F_10 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
unsigned int V_21 = ( unsigned long ) V_20 ;
struct V_6 * V_7 = F_11 ( V_22 , V_21 ) ;
struct V_4 * V_5 ;
if ( ! V_7 || F_12 ( V_7 -> V_1 , & V_5 ) )
return V_23 ;
if ( V_19 == V_24 ) {
if ( V_7 -> V_25 . V_26 ) {
int V_27 ;
F_13 ( L_2 ,
V_7 -> V_28 ) ;
V_7 -> V_25 . V_26 = 0 ;
V_27 = F_14 ( V_5 ) ;
F_15 ( V_27 , L_3 , V_7 -> V_28 ) ;
} else {
F_3 ( V_7 , 0 ) ;
F_16 ( V_7 ) ;
F_17 ( V_7 , V_19 ) ;
F_8 ( V_7 ) ;
}
} else if ( V_19 == V_29 ) {
F_17 ( V_7 , V_19 ) ;
}
return V_30 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_3 V_31 ;
int V_32 = 0 ;
if ( ! V_7 )
return - V_33 ;
if ( V_7 -> V_25 . V_26 )
return 0 ;
#ifdef F_18
F_3 ( V_7 , 0 ) ;
F_19 ( V_7 ) ;
#endif
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
if ( ! F_22 () || F_22 () == & V_34 )
F_23 ( V_7 ) ;
V_7 -> V_35 = F_24 ( L_4 , V_5 ,
& V_36 ) ;
if ( F_25 ( V_7 -> V_35 ) ) {
V_32 = F_26 ( V_7 -> V_35 ) ;
goto V_37;
}
F_27 ( & V_5 -> V_13 , L_5 ,
V_7 -> V_35 -> V_28 ) ;
V_32 = F_28 ( & V_5 -> V_13 . V_38 ,
& V_7 -> V_35 -> V_5 . V_38 ,
L_6 ) ;
if ( V_32 ) {
F_29 ( & V_5 -> V_13 ,
L_7 ) ;
goto V_39;
}
V_32 = F_28 ( & V_7 -> V_35 -> V_5 . V_38 ,
& V_5 -> V_13 . V_38 ,
L_8 ) ;
if ( V_32 ) {
F_29 ( & V_7 -> V_35 -> V_5 ,
L_9 ) ;
goto V_40;
}
V_31 = F_30 ( V_5 -> V_1 , V_41 ,
F_1 , V_5 ) ;
if ( F_31 ( V_31 ) )
return 0 ;
F_32 ( & V_7 -> V_35 -> V_5 . V_38 , L_8 ) ;
V_40:
F_32 ( & V_5 -> V_13 . V_38 , L_6 ) ;
V_39:
F_33 ( V_7 -> V_35 ) ;
V_37:
F_34 ( V_7 ) ;
return V_32 ;
}
static int F_35 ( struct V_5 * V_13 )
{
struct V_4 * V_5 ;
if ( F_12 ( F_36 ( V_13 ) , & V_5 ) )
return - V_33 ;
return F_14 ( V_5 ) ;
}
static int F_37 ( struct V_5 * V_13 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( F_12 ( F_36 ( V_13 ) , & V_5 ) )
return 0 ;
F_38 ( V_5 -> V_1 , V_41 ,
F_1 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
F_34 ( V_7 ) ;
if ( V_7 -> V_35 ) {
F_32 ( & V_5 -> V_13 . V_38 , L_6 ) ;
F_32 ( & V_7 -> V_35 -> V_5 . V_38 , L_8 ) ;
F_33 ( V_7 -> V_35 ) ;
V_7 -> V_35 = NULL ;
}
return 0 ;
}
static int T_4 F_39 ( void )
{
int V_32 = 0 ;
if ( V_42 )
return 0 ;
V_32 = F_40 ( & V_43 ) ;
if ( V_32 < 0 )
return V_32 ;
F_41 () ;
F_42 ( & V_44 ) ;
F_43 () ;
F_44 () ;
F_45 () ;
return 0 ;
}
static void T_5 F_46 ( void )
{
if ( V_42 )
return;
F_47 () ;
F_48 () ;
F_49 ( & V_44 ) ;
F_50 () ;
F_51 ( & V_43 ) ;
}
