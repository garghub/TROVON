static int T_1 F_1 ( struct V_1 * V_2 ,
int type , struct V_3 * V_4 )
{
struct V_5 V_5 ;
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
T_2 V_10 , V_11 , V_12 ;
int V_13 ;
memset ( V_4 , 0 , sizeof *V_4 ) ;
if ( F_2 ( V_7 , L_1 , & V_10 ) ) {
F_3 ( & V_2 -> V_8 , L_2 ) ;
return - V_14 ;
}
if ( F_2 ( V_7 , L_3 , & V_11 ) == 0 )
V_4 -> V_15 = V_10 / ( 16 * V_11 ) ;
V_13 = F_4 ( V_7 , 0 , & V_5 ) ;
if ( V_13 ) {
F_3 ( & V_2 -> V_8 , L_4 ) ;
return V_13 ;
}
F_5 ( & V_4 -> V_16 ) ;
V_4 -> V_17 = V_5 . V_18 ;
if ( F_2 ( V_7 , L_5 , & V_12 ) == 0 )
V_4 -> V_17 += V_12 ;
if ( F_2 ( V_7 , L_6 , & V_12 ) == 0 )
V_4 -> V_19 = V_12 ;
V_4 -> V_20 = F_6 ( V_7 , 0 ) ;
V_4 -> V_21 = V_22 ;
if ( F_2 ( V_7 , L_7 , & V_12 ) == 0 ) {
switch ( V_12 ) {
case 1 :
V_4 -> V_21 = V_22 ;
break;
case 4 :
V_4 -> V_21 = V_23 ;
break;
default:
F_3 ( & V_2 -> V_8 , L_8 ,
V_12 ) ;
return - V_24 ;
}
}
V_4 -> type = type ;
V_4 -> V_25 = V_10 ;
V_4 -> V_26 = V_27 | V_28 | V_29
| V_30 | V_31 ;
V_4 -> V_8 = & V_2 -> V_8 ;
return 0 ;
}
static int T_1 F_7 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_3 V_4 ;
int V_36 ;
int V_13 ;
V_33 = F_8 ( V_37 , & V_2 -> V_8 ) ;
if ( ! V_33 )
return - V_24 ;
if ( F_9 ( V_2 -> V_8 . V_9 , L_9 , NULL ) )
return - V_38 ;
V_35 = F_10 ( sizeof( * V_35 ) , V_39 ) ;
if ( V_35 == NULL )
return - V_40 ;
V_36 = ( unsigned long ) V_33 -> V_41 ;
V_13 = F_1 ( V_2 , V_36 , & V_4 ) ;
if ( V_13 )
goto V_42;
switch ( V_36 ) {
#ifdef F_11
case V_43 ... V_44 :
V_13 = F_12 ( & V_4 ) ;
break;
#endif
#ifdef F_13
case V_45 :
V_13 = F_14 ( & V_4 ) ;
break;
#endif
default:
case V_46 :
F_15 ( & V_2 -> V_8 , L_10 ) ;
V_13 = - V_14 ;
break;
}
if ( V_13 < 0 )
goto V_42;
V_35 -> type = V_36 ;
V_35 -> line = V_13 ;
F_16 ( & V_2 -> V_8 , V_35 ) ;
return 0 ;
V_42:
F_17 ( V_35 ) ;
F_18 ( V_4 . V_20 ) ;
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_20 ( & V_2 -> V_8 ) ;
switch ( V_35 -> type ) {
#ifdef F_11
case V_43 ... V_44 :
F_21 ( V_35 -> line ) ;
break;
#endif
#ifdef F_13
case V_45 :
F_22 ( V_35 -> line ) ;
break;
#endif
default:
break;
}
F_17 ( V_35 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_47 ) ;
}
static void T_4 F_25 ( void )
{
return F_26 ( & V_47 ) ;
}
