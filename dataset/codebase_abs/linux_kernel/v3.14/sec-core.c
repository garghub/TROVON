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
case V_10 :
return false ;
default:
return true ;
}
}
static struct V_11 * F_3 (
struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_4 ( V_2 , sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 ) {
F_5 ( V_2 , L_1 ) ;
return F_6 ( - V_14 ) ;
}
return V_12 ;
}
static struct V_11 * F_3 (
struct V_1 * V_2 )
{
return NULL ;
}
static inline int F_7 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
#ifdef F_8
if ( V_16 -> V_2 . V_19 ) {
const struct V_20 * V_21 ;
V_21 = F_9 ( V_22 , V_16 -> V_2 . V_19 ) ;
return ( int ) V_21 -> V_23 ;
}
#endif
return ( int ) V_18 -> V_24 ;
}
static int F_10 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_11 * V_25 = F_11 ( & V_16 -> V_2 ) ;
const struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
V_29 = F_4 ( & V_16 -> V_2 , sizeof( struct V_28 ) ,
V_13 ) ;
if ( V_29 == NULL )
return - V_14 ;
F_12 ( V_16 , V_29 ) ;
V_29 -> V_2 = & V_16 -> V_2 ;
V_29 -> V_16 = V_16 ;
V_29 -> V_31 = V_16 -> V_31 ;
V_29 -> type = F_7 ( V_16 , V_18 ) ;
if ( V_29 -> V_2 -> V_19 ) {
V_25 = F_3 ( V_29 -> V_2 ) ;
if ( F_13 ( V_25 ) ) {
V_30 = F_14 ( V_25 ) ;
return V_30 ;
}
V_25 -> V_32 = V_29 -> type ;
}
if ( V_25 ) {
V_29 -> V_32 = V_25 -> V_32 ;
V_29 -> V_33 = V_25 -> V_33 ;
V_29 -> V_34 = V_25 -> V_34 ;
V_29 -> V_35 = V_25 -> V_35 ;
V_29 -> V_25 = V_25 ;
}
switch ( V_29 -> V_32 ) {
case V_36 :
V_27 = & V_37 ;
break;
case V_38 :
V_27 = & V_39 ;
break;
case V_40 :
V_27 = & V_41 ;
break;
default:
V_27 = & V_42 ;
break;
}
V_29 -> V_43 = F_15 ( V_16 , V_27 ) ;
if ( F_13 ( V_29 -> V_43 ) ) {
V_30 = F_14 ( V_29 -> V_43 ) ;
F_5 ( & V_16 -> V_2 , L_2 ,
V_30 ) ;
return V_30 ;
}
V_29 -> V_44 = F_16 ( V_16 -> V_45 , V_46 ) ;
F_12 ( V_29 -> V_44 , V_29 ) ;
V_29 -> V_47 = F_15 ( V_29 -> V_44 ,
& V_48 ) ;
if ( F_13 ( V_29 -> V_47 ) ) {
V_30 = F_14 ( V_29 -> V_47 ) ;
F_5 ( & V_16 -> V_2 , L_3 ,
V_30 ) ;
return V_30 ;
}
if ( V_25 && V_25 -> V_49 )
V_25 -> V_49 () ;
F_17 ( V_29 ) ;
F_18 ( V_29 -> V_2 ) ;
switch ( V_29 -> V_32 ) {
case V_50 :
V_30 = F_19 ( V_29 -> V_2 , - 1 , V_51 ,
F_20 ( V_51 ) , NULL , 0 , NULL ) ;
break;
case V_38 :
V_30 = F_19 ( V_29 -> V_2 , - 1 , V_52 ,
F_20 ( V_52 ) , NULL , 0 , NULL ) ;
break;
case V_40 :
V_30 = F_19 ( V_29 -> V_2 , - 1 , V_53 ,
F_20 ( V_53 ) , NULL , 0 , NULL ) ;
break;
case V_36 :
V_30 = F_19 ( V_29 -> V_2 , - 1 , V_54 ,
F_20 ( V_54 ) , NULL , 0 , NULL ) ;
break;
default:
F_21 () ;
}
if ( V_30 )
goto V_55;
F_22 ( V_29 -> V_2 , V_29 -> V_35 ) ;
return V_30 ;
V_55:
F_23 ( V_29 ) ;
F_24 ( V_29 -> V_44 ) ;
return V_30 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_28 * V_29 = F_26 ( V_16 ) ;
F_27 ( V_29 -> V_2 ) ;
F_23 ( V_29 ) ;
F_24 ( V_29 -> V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_29 ( V_2 , struct V_15 , V_2 ) ;
struct V_28 * V_29 = F_26 ( V_16 ) ;
if ( F_30 ( V_2 ) ) {
F_31 ( V_29 -> V_31 ) ;
F_32 ( V_29 -> V_31 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_29 ( V_2 , struct V_15 , V_2 ) ;
struct V_28 * V_29 = F_26 ( V_16 ) ;
if ( F_30 ( V_2 ) ) {
F_34 ( V_29 -> V_31 ) ;
F_35 ( V_29 -> V_31 ) ;
}
return 0 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_56 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_56 ) ;
}
