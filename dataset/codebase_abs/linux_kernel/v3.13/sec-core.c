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
static bool F_11 ( struct V_11 * V_12 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_13 :
case V_14 :
case V_15 :
return false ;
default:
return true ;
}
}
static bool F_12 ( struct V_11 * V_12 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return false ;
default:
return true ;
}
}
static struct V_20 * F_13 (
struct V_11 * V_12 )
{
struct V_20 * V_21 ;
V_21 = F_14 ( V_12 , sizeof( * V_21 ) , V_22 ) ;
if ( ! V_21 ) {
F_15 ( V_12 , L_1 ) ;
return F_16 ( - V_23 ) ;
}
return V_21 ;
}
static struct V_20 * F_13 (
struct V_11 * V_12 )
{
return 0 ;
}
static inline int F_17 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
#ifdef F_18
if ( V_25 -> V_12 . V_28 ) {
const struct V_29 * V_30 ;
V_30 = F_19 ( V_31 , V_25 -> V_12 . V_28 ) ;
return ( int ) V_30 -> V_32 ;
}
#endif
return ( int ) V_27 -> V_33 ;
}
static int F_20 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
struct V_20 * V_34 = F_21 ( & V_25 -> V_12 ) ;
const struct V_35 * V_36 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_14 ( & V_25 -> V_12 , sizeof( struct V_1 ) ,
V_22 ) ;
if ( V_2 == NULL )
return - V_23 ;
F_22 ( V_25 , V_2 ) ;
V_2 -> V_12 = & V_25 -> V_12 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_38 = V_25 -> V_38 ;
V_2 -> type = F_17 ( V_25 , V_27 ) ;
if ( V_2 -> V_12 -> V_28 ) {
V_34 = F_13 ( V_2 -> V_12 ) ;
if ( F_23 ( V_34 ) ) {
V_37 = F_24 ( V_34 ) ;
return V_37 ;
}
V_34 -> V_39 = V_2 -> type ;
}
if ( V_34 ) {
V_2 -> V_39 = V_34 -> V_39 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_41 = V_34 -> V_41 ;
V_2 -> V_42 = V_34 -> V_42 ;
V_2 -> V_34 = V_34 ;
}
switch ( V_2 -> V_39 ) {
case V_43 :
V_36 = & V_44 ;
break;
case V_45 :
V_36 = & V_46 ;
break;
case V_47 :
V_36 = & V_48 ;
break;
default:
V_36 = & V_49 ;
break;
}
V_2 -> V_5 = F_25 ( V_25 , V_36 ) ;
if ( F_23 ( V_2 -> V_5 ) ) {
V_37 = F_24 ( V_2 -> V_5 ) ;
F_15 ( & V_25 -> V_12 , L_2 ,
V_37 ) ;
return V_37 ;
}
V_2 -> V_50 = F_26 ( V_25 -> V_51 , V_52 ) ;
F_22 ( V_2 -> V_50 , V_2 ) ;
V_2 -> V_53 = F_25 ( V_2 -> V_50 ,
& V_54 ) ;
if ( F_23 ( V_2 -> V_53 ) ) {
V_37 = F_24 ( V_2 -> V_53 ) ;
F_15 ( & V_25 -> V_12 , L_3 ,
V_37 ) ;
return V_37 ;
}
if ( V_34 && V_34 -> V_55 )
V_34 -> V_55 () ;
F_27 ( V_2 ) ;
F_28 ( V_2 -> V_12 ) ;
switch ( V_2 -> V_39 ) {
case V_56 :
V_37 = F_29 ( V_2 -> V_12 , - 1 , V_57 ,
F_30 ( V_57 ) , NULL , 0 , NULL ) ;
break;
case V_45 :
V_37 = F_29 ( V_2 -> V_12 , - 1 , V_58 ,
F_30 ( V_58 ) , NULL , 0 , NULL ) ;
break;
case V_47 :
V_37 = F_29 ( V_2 -> V_12 , - 1 , V_59 ,
F_30 ( V_59 ) , NULL , 0 , NULL ) ;
break;
case V_43 :
V_37 = F_29 ( V_2 -> V_12 , - 1 , V_60 ,
F_30 ( V_60 ) , NULL , 0 , NULL ) ;
break;
default:
F_31 () ;
}
if ( V_37 )
goto V_61;
return V_37 ;
V_61:
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_50 ) ;
return V_37 ;
}
static int F_34 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_35 ( V_25 ) ;
F_36 ( V_2 -> V_12 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_50 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_62 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_62 ) ;
}
