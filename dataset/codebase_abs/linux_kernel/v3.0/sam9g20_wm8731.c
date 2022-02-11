static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , V_12 |
V_13 | V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 | V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_3 ( struct V_15 * V_16 ,
enum V_17 V_18 )
{
static int V_19 ;
int V_11 = 0 ;
switch ( V_18 ) {
case V_20 :
case V_21 :
if ( ! V_19 )
V_11 = F_4 ( V_22 ) ;
if ( V_11 == 0 )
V_19 = 1 ;
break;
case V_23 :
case V_24 :
if ( V_19 )
F_5 ( V_22 ) ;
V_19 = 0 ;
break;
}
return V_11 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_26 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
int V_11 ;
F_7 ( V_29
L_1
L_2 ) ;
V_11 = F_8 ( V_9 , V_30 ,
V_31 , V_32 ) ;
if ( V_11 < 0 ) {
F_7 ( V_33 L_3 , V_11 ) ;
return V_11 ;
}
F_9 ( V_28 , V_34 ,
F_10 ( V_34 ) ) ;
F_11 ( V_28 , V_35 , F_10 ( V_35 ) ) ;
F_12 ( V_28 , L_4 ) ;
F_12 ( V_28 , L_5 ) ;
#ifdef F_13
F_14 ( V_28 , L_6 ) ;
#else
F_12 ( V_28 , L_6 ) ;
#endif
F_14 ( V_28 , L_7 ) ;
F_15 ( V_28 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
struct V_36 * V_37 ;
int V_11 ;
if ( ! ( F_17 () || F_18 () ) )
return - V_38 ;
V_11 = F_19 ( 0 ) ;
if ( V_11 != 0 ) {
F_20 ( L_8 , V_11 ) ;
return V_11 ;
}
V_22 = F_21 ( NULL , L_9 ) ;
if ( F_22 ( V_22 ) ) {
F_7 ( V_33 L_10 ) ;
V_11 = F_23 ( V_22 ) ;
goto V_39;
}
V_37 = F_21 ( NULL , L_11 ) ;
if ( F_22 ( V_37 ) ) {
F_7 ( V_33 L_12 ) ;
V_11 = F_23 ( V_37 ) ;
goto V_40;
}
V_11 = F_24 ( V_22 , V_37 ) ;
F_25 ( V_37 ) ;
if ( V_11 != 0 ) {
F_7 ( V_33 L_13 ) ;
goto V_40;
}
F_26 ( V_22 , V_31 ) ;
V_41 = F_27 ( L_14 , - 1 ) ;
if ( ! V_41 ) {
F_7 ( V_33 L_15 ) ;
V_11 = - V_42 ;
goto V_40;
}
F_28 ( V_41 ,
& V_43 ) ;
V_11 = F_29 ( V_41 ) ;
if ( V_11 ) {
F_7 ( V_33 L_15 ) ;
goto V_44;
}
return V_11 ;
V_44:
F_30 ( V_41 ) ;
V_40:
F_25 ( V_22 ) ;
V_22 = NULL ;
V_39:
return V_11 ;
}
static void T_2 F_31 ( void )
{
F_32 ( V_41 ) ;
V_41 = NULL ;
F_25 ( V_22 ) ;
V_22 = NULL ;
}
