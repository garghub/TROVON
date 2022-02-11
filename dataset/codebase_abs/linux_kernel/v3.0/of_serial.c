static int T_1 F_1 ( struct V_1 * V_2 ,
int type , struct V_3 * V_4 )
{
struct V_5 V_5 ;
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
const T_2 * V_10 , * V_11 ;
const T_2 * V_12 ;
int V_13 , V_14 ;
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_11 = F_2 ( V_7 , L_1 , NULL ) ;
V_10 = F_2 ( V_7 , L_2 , NULL ) ;
if ( ! V_10 ) {
F_3 ( & V_2 -> V_8 , L_3 ) ;
return - V_15 ;
}
V_13 = F_4 ( V_7 , 0 , & V_5 ) ;
if ( V_13 ) {
F_3 ( & V_2 -> V_8 , L_4 ) ;
return V_13 ;
}
F_5 ( & V_4 -> V_16 ) ;
V_4 -> V_17 = V_5 . V_18 ;
V_12 = F_2 ( V_7 , L_5 , & V_14 ) ;
if ( V_12 && ( V_14 == sizeof( V_19 ) ) )
V_4 -> V_17 += F_6 ( V_12 ) ;
V_12 = F_2 ( V_7 , L_6 , & V_14 ) ;
if ( V_12 && ( V_14 == sizeof( V_19 ) ) )
V_4 -> V_20 = F_6 ( V_12 ) ;
V_4 -> V_21 = F_7 ( V_7 , 0 ) ;
V_4 -> V_22 = V_23 ;
V_4 -> type = type ;
V_4 -> V_24 = F_6 ( V_10 ) ;
V_4 -> V_25 = V_26 | V_27 | V_28
| V_29 | V_30 ;
V_4 -> V_8 = & V_2 -> V_8 ;
if ( V_11 )
V_4 -> V_31 = F_6 ( V_10 ) / ( 16 * ( F_6 ( V_11 ) ) ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_3 V_4 ;
int V_36 ;
int V_13 ;
V_33 = F_9 ( V_37 , & V_2 -> V_8 ) ;
if ( ! V_33 )
return - V_38 ;
if ( F_10 ( V_2 -> V_8 . V_9 , L_7 , NULL ) )
return - V_39 ;
V_35 = F_11 ( sizeof( * V_35 ) , V_40 ) ;
if ( V_35 == NULL )
return - V_41 ;
V_36 = ( unsigned long ) V_33 -> V_42 ;
V_13 = F_1 ( V_2 , V_36 , & V_4 ) ;
if ( V_13 )
goto V_43;
switch ( V_36 ) {
#ifdef F_12
case V_44 ... V_45 :
V_13 = F_13 ( & V_4 ) ;
break;
#endif
#ifdef F_14
case V_46 :
V_13 = F_15 ( & V_4 ) ;
break;
#endif
default:
case V_47 :
F_16 ( & V_2 -> V_8 , L_8 ) ;
V_13 = - V_15 ;
break;
}
if ( V_13 < 0 )
goto V_43;
V_35 -> type = V_36 ;
V_35 -> line = V_13 ;
F_17 ( & V_2 -> V_8 , V_35 ) ;
return 0 ;
V_43:
F_18 ( V_35 ) ;
F_19 ( V_4 . V_21 ) ;
return V_13 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_21 ( & V_2 -> V_8 ) ;
switch ( V_35 -> type ) {
#ifdef F_12
case V_44 ... V_45 :
F_22 ( V_35 -> line ) ;
break;
#endif
#ifdef F_14
case V_46 :
F_23 ( V_35 -> line ) ;
break;
#endif
default:
break;
}
F_18 ( V_35 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_48 ) ;
}
static void T_4 F_26 ( void )
{
return F_27 ( & V_48 ) ;
}
