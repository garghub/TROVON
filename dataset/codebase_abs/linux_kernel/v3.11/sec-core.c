int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_7 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
return F_6 ( V_2 -> V_5 , V_3 , V_8 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_8 ( V_2 -> V_5 , V_3 , V_7 , V_6 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 , T_1 V_10 )
{
return F_10 ( V_2 -> V_5 , V_3 , V_10 , V_9 ) ;
}
static struct V_11 * F_11 (
struct V_12 * V_13 )
{
struct V_11 * V_14 ;
V_14 = F_12 ( V_13 , sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 ) {
F_13 ( V_13 , L_1 ) ;
return F_14 ( - V_16 ) ;
}
return V_14 ;
}
static struct V_11 * F_11 (
struct V_12 * V_13 )
{
return 0 ;
}
static inline int F_15 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
#ifdef F_16
if ( V_18 -> V_13 . V_21 ) {
const struct V_22 * V_23 ;
V_23 = F_17 ( V_24 , V_18 -> V_13 . V_21 ) ;
return ( int ) V_23 -> V_25 ;
}
#endif
return ( int ) V_20 -> V_26 ;
}
static int F_18 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_11 * V_27 = V_18 -> V_13 . V_28 ;
const struct V_29 * V_5 ;
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_12 ( & V_18 -> V_13 , sizeof( struct V_1 ) ,
V_15 ) ;
if ( V_2 == NULL )
return - V_16 ;
F_19 ( V_18 , V_2 ) ;
V_2 -> V_13 = & V_18 -> V_13 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_31 = V_18 -> V_31 ;
V_2 -> type = F_15 ( V_18 , V_20 ) ;
if ( V_2 -> V_13 -> V_21 ) {
V_27 = F_11 ( V_2 -> V_13 ) ;
if ( F_20 ( V_27 ) ) {
V_30 = F_21 ( V_27 ) ;
return V_30 ;
}
V_27 -> V_32 = V_2 -> type ;
}
if ( V_27 ) {
V_2 -> V_32 = V_27 -> V_32 ;
V_2 -> V_33 = V_27 -> V_33 ;
V_2 -> V_34 = V_27 -> V_34 ;
V_2 -> V_35 = V_27 -> V_35 ;
V_2 -> V_27 = V_27 ;
}
switch ( V_2 -> V_32 ) {
case V_36 :
V_5 = & V_37 ;
break;
case V_38 :
V_5 = & V_39 ;
break;
case V_40 :
V_5 = & V_41 ;
break;
default:
V_5 = & V_42 ;
break;
}
V_2 -> V_5 = F_22 ( V_18 , V_5 ) ;
if ( F_20 ( V_2 -> V_5 ) ) {
V_30 = F_21 ( V_2 -> V_5 ) ;
F_13 ( & V_18 -> V_13 , L_2 ,
V_30 ) ;
return V_30 ;
}
V_2 -> V_43 = F_23 ( V_18 -> V_44 , V_45 ) ;
F_19 ( V_2 -> V_43 , V_2 ) ;
if ( V_27 && V_27 -> V_46 )
V_27 -> V_46 () ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_13 ) ;
switch ( V_2 -> V_32 ) {
case V_47 :
V_30 = F_26 ( V_2 -> V_13 , - 1 , V_48 ,
F_27 ( V_48 ) , NULL , 0 , NULL ) ;
break;
case V_38 :
V_30 = F_26 ( V_2 -> V_13 , - 1 , V_49 ,
F_27 ( V_49 ) , NULL , 0 , NULL ) ;
break;
case V_40 :
V_30 = F_26 ( V_2 -> V_13 , - 1 , V_50 ,
F_27 ( V_50 ) , NULL , 0 , NULL ) ;
break;
case V_36 :
V_30 = F_26 ( V_2 -> V_13 , - 1 , V_51 ,
F_27 ( V_51 ) , NULL , 0 , NULL ) ;
break;
default:
F_28 () ;
}
if ( V_30 )
goto V_52;
return V_30 ;
V_52:
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_43 ) ;
return V_30 ;
}
static int F_31 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_32 ( V_18 ) ;
F_33 ( V_2 -> V_13 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_43 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_53 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_53 ) ;
}
