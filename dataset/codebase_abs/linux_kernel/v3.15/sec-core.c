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
const struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
V_33 = F_5 ( & V_19 -> V_2 , sizeof( struct V_32 ) ,
V_16 ) ;
if ( V_33 == NULL )
return - V_17 ;
F_13 ( V_19 , V_33 ) ;
V_33 -> V_2 = & V_19 -> V_2 ;
V_33 -> V_19 = V_19 ;
V_33 -> V_35 = V_19 -> V_35 ;
V_33 -> type = F_8 ( V_19 , V_21 ) ;
if ( V_33 -> V_2 -> V_22 ) {
V_28 = F_4 ( V_33 -> V_2 ) ;
if ( F_14 ( V_28 ) ) {
V_34 = F_15 ( V_28 ) ;
return V_34 ;
}
V_28 -> V_36 = V_33 -> type ;
}
if ( V_28 ) {
V_33 -> V_36 = V_28 -> V_36 ;
V_33 -> V_37 = V_28 -> V_37 ;
V_33 -> V_38 = V_28 -> V_38 ;
V_33 -> V_39 = V_28 -> V_39 ;
V_33 -> V_28 = V_28 ;
}
switch ( V_33 -> V_36 ) {
case V_40 :
V_30 = & V_41 ;
V_31 = & V_42 ;
break;
case V_43 :
V_30 = & V_44 ;
V_31 = & V_42 ;
break;
case V_45 :
V_30 = & V_46 ;
V_31 = & V_47 ;
break;
case V_48 :
V_30 = & V_49 ;
V_31 = & V_42 ;
break;
case V_50 :
V_30 = & V_51 ;
V_31 = & V_42 ;
break;
default:
V_30 = & V_52 ;
V_31 = & V_42 ;
break;
}
V_33 -> V_53 = F_16 ( V_19 , V_30 ) ;
if ( F_14 ( V_33 -> V_53 ) ) {
V_34 = F_15 ( V_33 -> V_53 ) ;
F_6 ( & V_19 -> V_2 , L_2 ,
V_34 ) ;
return V_34 ;
}
V_33 -> V_54 = F_17 ( V_19 -> V_55 , V_56 ) ;
if ( ! V_33 -> V_54 ) {
F_6 ( & V_19 -> V_2 , L_3 ) ;
return - V_57 ;
}
F_13 ( V_33 -> V_54 , V_33 ) ;
V_33 -> V_31 = F_16 ( V_33 -> V_54 , V_31 ) ;
if ( F_14 ( V_33 -> V_31 ) ) {
V_34 = F_15 ( V_33 -> V_31 ) ;
F_6 ( & V_19 -> V_2 , L_4 ,
V_34 ) ;
goto V_58;
}
if ( V_28 && V_28 -> V_59 )
V_28 -> V_59 () ;
F_18 ( V_33 ) ;
F_19 ( V_33 -> V_2 ) ;
switch ( V_33 -> V_36 ) {
case V_60 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_61 ,
F_21 ( V_61 ) , NULL , 0 , NULL ) ;
break;
case V_48 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_62 ,
F_21 ( V_62 ) , NULL , 0 , NULL ) ;
break;
case V_50 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_63 ,
F_21 ( V_63 ) , NULL , 0 , NULL ) ;
break;
case V_40 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_64 ,
F_21 ( V_64 ) , NULL , 0 , NULL ) ;
break;
case V_43 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_65 ,
F_21 ( V_65 ) , NULL , 0 , NULL ) ;
break;
case V_45 :
V_34 = F_20 ( V_33 -> V_2 , - 1 , V_66 ,
F_21 ( V_66 ) , NULL , 0 , NULL ) ;
break;
default:
F_22 () ;
}
if ( V_34 )
goto V_67;
F_23 ( V_33 -> V_2 , V_33 -> V_39 ) ;
return V_34 ;
V_67:
F_24 ( V_33 ) ;
V_58:
F_25 ( V_33 -> V_54 ) ;
return V_34 ;
}
static int F_26 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = F_27 ( V_19 ) ;
F_28 ( V_33 -> V_2 ) ;
F_24 ( V_33 ) ;
F_25 ( V_33 -> V_54 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_30 ( V_2 , struct V_18 , V_2 ) ;
struct V_32 * V_33 = F_27 ( V_19 ) ;
if ( F_31 ( V_2 ) ) {
F_32 ( V_33 -> V_35 ) ;
F_33 ( V_33 -> V_35 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_30 ( V_2 , struct V_18 , V_2 ) ;
struct V_32 * V_33 = F_27 ( V_19 ) ;
if ( F_31 ( V_2 ) ) {
F_35 ( V_33 -> V_35 ) ;
F_36 ( V_33 -> V_35 ) ;
}
return 0 ;
}
static int T_1 F_37 ( void )
{
return F_38 ( & V_68 ) ;
}
static void T_2 F_39 ( void )
{
F_40 ( & V_68 ) ;
}
