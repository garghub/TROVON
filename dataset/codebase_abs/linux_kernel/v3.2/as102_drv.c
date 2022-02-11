static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return;
if ( V_4 -> V_5 -> V_6 != NULL )
V_4 -> V_5 -> V_6 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return;
if ( F_3 ( V_4 ) < 0 )
F_4 ( V_9 , L_1 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 = - V_11 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return V_10 ;
if ( V_4 -> V_5 -> V_12 != NULL )
V_10 = V_4 -> V_5 -> V_12 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return - V_11 ;
V_10 = F_7 ( V_4 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_13 , T_1 V_14 , int V_15 ) {
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_10 = - V_11 ;
F_9 () ;
if ( F_2 ( & V_2 -> V_4 . V_8 ) ) {
F_4 ( V_9 , L_2 ) ;
return - V_16 ;
}
switch ( V_15 ) {
case 0 :
V_10 = F_10 ( V_4 , ( V_17 ) V_14 ) ;
F_4 ( V_9 , L_3 ,
V_13 , V_14 , V_10 ) ;
break;
case 1 :
{
struct V_18 V_19 ;
V_19 . type = V_20 ;
V_19 . V_21 = 0xFF ;
V_19 . V_14 = V_14 ;
V_10 = F_11 ( V_4 , & V_19 ) ;
F_4 ( V_9 , L_4 ,
V_13 , V_19 . V_21 , V_19 . V_14 , V_10 ) ;
break;
}
}
F_5 ( & V_2 -> V_4 . V_8 ) ;
F_12 () ;
return V_10 ;
}
static int F_13 ( struct V_22 * V_23 )
{
int V_10 = 0 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
F_9 () ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( V_30 ) {
F_8 ( V_26 ,
V_23 -> V_13 , V_23 -> V_14 , 1 ) ;
}
if ( V_26 -> V_31 ++ == 0 )
V_10 = F_6 ( V_26 ) ;
F_5 ( & V_26 -> V_28 ) ;
F_12 () ;
return V_10 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
F_9 () ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( -- V_26 -> V_31 == 0 )
F_1 ( V_26 ) ;
if ( V_30 ) {
F_8 ( V_26 ,
V_23 -> V_13 , V_23 -> V_14 , 0 ) ;
}
F_5 ( & V_26 -> V_28 ) ;
F_12 () ;
return 0 ;
}
int F_15 ( struct V_1 * V_26 )
{
int V_10 = 0 ;
F_9 () ;
V_10 = F_16 ( & V_26 -> V_32 ,
V_26 -> V_33 ,
V_34 ,
#if F_17 ( V_35 )
& V_26 -> V_4 . V_36 -> V_2
#elif F_17 ( V_37 )
& V_26 -> V_4 . V_38 -> V_2
#else
#error >>> dvb_register_adapter <<<
#endif
#ifdef F_18
, V_39
#endif
) ;
if ( V_10 < 0 ) {
F_19 ( L_5 ,
V_40 , V_10 ) ;
goto V_41;
}
V_26 -> V_42 . V_27 = V_26 ;
V_26 -> V_42 . V_43 = V_30 ? 16 : 256 ;
V_26 -> V_42 . V_44 = 256 ;
V_26 -> V_42 . V_45 = F_13 ;
V_26 -> V_42 . V_46 = F_14 ;
V_26 -> V_42 . V_47 . V_48 = V_49 |
V_50 ;
V_26 -> V_51 . V_43 = V_26 -> V_42 . V_43 ;
V_26 -> V_51 . V_25 = & V_26 -> V_42 . V_47 ;
V_26 -> V_51 . V_48 = 0 ;
V_10 = F_20 ( & V_26 -> V_42 ) ;
if ( V_10 < 0 ) {
F_19 ( L_6 , V_40 , V_10 ) ;
goto V_41;
}
V_10 = F_21 ( & V_26 -> V_51 , & V_26 -> V_32 ) ;
if ( V_10 < 0 ) {
F_19 ( L_7 , V_40 ,
V_10 ) ;
goto V_41;
}
V_10 = F_22 ( V_26 , & V_26 -> V_52 ) ;
if ( V_10 < 0 ) {
F_19 ( L_8 ,
V_40 , V_10 ) ;
goto V_41;
}
F_23 ( & V_26 -> V_4 . V_8 ) ;
F_23 ( & V_26 -> V_28 ) ;
#if F_17 ( V_53 ) || F_17 ( V_54 )
if ( V_55 )
F_24 ( F_25 ( & V_26 -> V_4 ) ,
L_9 ) ;
#endif
V_41:
F_12 () ;
return V_10 ;
}
void F_26 ( struct V_1 * V_26 )
{
F_9 () ;
F_27 ( & V_26 -> V_52 ) ;
F_28 ( & V_26 -> V_51 ) ;
F_29 ( & V_26 -> V_42 ) ;
F_30 ( & V_26 -> V_32 ) ;
F_12 () ;
}
static int T_2 F_31 ( void )
{
int V_10 = 0 ;
F_9 () ;
#if F_17 ( V_35 )
V_10 = F_32 ( & V_56 ) ;
if ( V_10 )
F_19 ( L_10 , V_10 ) ;
#endif
#if F_17 ( V_37 )
V_10 = F_33 ( & V_57 ) ;
if ( V_10 )
F_34 ( V_58 L_11 , V_10 ) ;
#endif
F_12 () ;
return V_10 ;
}
static void T_3 F_35 ( void )
{
F_9 () ;
#if F_17 ( V_35 )
F_36 ( & V_56 ) ;
#endif
#if F_17 ( V_37 )
F_37 ( & V_57 ) ;
#endif
F_12 () ;
}
