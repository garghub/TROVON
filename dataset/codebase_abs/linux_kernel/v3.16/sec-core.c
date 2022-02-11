static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return false ;
default:
return true ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
return false ;
default:
return true ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return false ;
default:
return true ;
}
}
static struct V_14 * F_4 (
struct V_1 * V_2 )
{
struct V_14 * V_15 ;
V_15 = F_5 ( V_2 , sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 ) {
F_6 ( V_2 , L_1 ) ;
return F_7 ( - V_17 ) ;
}
return V_15 ;
}
static struct V_14 * F_4 (
struct V_1 * V_2 )
{
return NULL ;
}
static inline unsigned long F_8 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
#ifdef F_9
if ( V_19 -> V_2 . V_22 ) {
const struct V_23 * V_24 ;
V_24 = F_10 ( V_25 , V_19 -> V_2 . V_22 ) ;
return ( unsigned long ) V_24 -> V_26 ;
}
#endif
return V_21 -> V_27 ;
}
static int F_11 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_14 * V_28 = F_12 ( & V_19 -> V_2 ) ;
const struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
int V_34 ;
V_32 = F_5 ( & V_19 -> V_2 , sizeof( struct V_31 ) ,
V_16 ) ;
if ( V_32 == NULL )
return - V_17 ;
F_13 ( V_19 , V_32 ) ;
V_32 -> V_2 = & V_19 -> V_2 ;
V_32 -> V_19 = V_19 ;
V_32 -> V_35 = V_19 -> V_35 ;
V_33 = F_8 ( V_19 , V_21 ) ;
if ( V_32 -> V_2 -> V_22 ) {
V_28 = F_4 ( V_32 -> V_2 ) ;
if ( F_14 ( V_28 ) ) {
V_34 = F_15 ( V_28 ) ;
return V_34 ;
}
V_28 -> V_33 = V_33 ;
}
if ( V_28 ) {
V_32 -> V_33 = V_28 -> V_33 ;
V_32 -> V_36 = V_28 -> V_36 ;
V_32 -> V_37 = V_28 -> V_37 ;
V_32 -> V_38 = V_28 -> V_38 ;
V_32 -> V_28 = V_28 ;
}
switch ( V_32 -> V_33 ) {
case V_39 :
V_30 = & V_40 ;
break;
case V_41 :
V_30 = & V_42 ;
break;
case V_43 :
V_30 = & V_44 ;
break;
case V_45 :
V_30 = & V_46 ;
break;
case V_47 :
V_30 = & V_48 ;
break;
default:
V_30 = & V_49 ;
break;
}
V_32 -> V_50 = F_16 ( V_19 , V_30 ) ;
if ( F_14 ( V_32 -> V_50 ) ) {
V_34 = F_15 ( V_32 -> V_50 ) ;
F_6 ( & V_19 -> V_2 , L_2 ,
V_34 ) ;
return V_34 ;
}
if ( V_28 && V_28 -> V_51 )
V_28 -> V_51 () ;
F_17 ( V_32 ) ;
F_18 ( V_32 -> V_2 ) ;
switch ( V_32 -> V_33 ) {
case V_52 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_53 ,
F_20 ( V_53 ) , NULL , 0 , NULL ) ;
break;
case V_45 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_54 ,
F_20 ( V_54 ) , NULL , 0 , NULL ) ;
break;
case V_47 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_55 ,
F_20 ( V_55 ) , NULL , 0 , NULL ) ;
break;
case V_39 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_56 ,
F_20 ( V_56 ) , NULL , 0 , NULL ) ;
break;
case V_41 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_57 ,
F_20 ( V_57 ) , NULL , 0 , NULL ) ;
break;
case V_43 :
V_34 = F_19 ( V_32 -> V_2 , - 1 , V_58 ,
F_20 ( V_58 ) , NULL , 0 , NULL ) ;
break;
default:
F_21 () ;
}
if ( V_34 )
goto V_59;
F_22 ( V_32 -> V_2 , V_32 -> V_38 ) ;
return V_34 ;
V_59:
F_23 ( V_32 ) ;
return V_34 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_31 * V_32 = F_25 ( V_19 ) ;
F_26 ( V_32 -> V_2 ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_28 ( V_2 , struct V_18 , V_2 ) ;
struct V_31 * V_32 = F_25 ( V_19 ) ;
if ( F_29 ( V_2 ) )
F_30 ( V_32 -> V_35 ) ;
F_31 ( V_32 -> V_35 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_28 ( V_2 , struct V_18 , V_2 ) ;
struct V_31 * V_32 = F_25 ( V_19 ) ;
if ( F_29 ( V_2 ) )
F_33 ( V_32 -> V_35 ) ;
F_34 ( V_32 -> V_35 ) ;
return 0 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_60 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_60 ) ;
}
