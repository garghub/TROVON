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
return false ;
default:
return true ;
}
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return false ;
default:
return true ;
}
}
static struct V_17 * F_5 (
struct V_1 * V_2 )
{
struct V_17 * V_18 ;
V_18 = F_6 ( V_2 , sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 ) {
F_7 ( V_2 , L_1 ) ;
return F_8 ( - V_20 ) ;
}
return V_18 ;
}
static struct V_17 * F_5 (
struct V_1 * V_2 )
{
return NULL ;
}
static inline unsigned long F_9 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
#ifdef F_10
if ( V_22 -> V_2 . V_25 ) {
const struct V_26 * V_27 ;
V_27 = F_11 ( V_28 , V_22 -> V_2 . V_25 ) ;
return ( unsigned long ) V_27 -> V_29 ;
}
#endif
return V_24 -> V_30 ;
}
static int F_12 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_17 * V_31 = F_13 ( & V_22 -> V_2 ) ;
const struct V_32 * V_33 ;
const struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
int V_39 , V_40 ;
V_37 = F_6 ( & V_22 -> V_2 , sizeof( struct V_36 ) ,
V_19 ) ;
if ( V_37 == NULL )
return - V_20 ;
F_14 ( V_22 , V_37 ) ;
V_37 -> V_2 = & V_22 -> V_2 ;
V_37 -> V_22 = V_22 ;
V_37 -> V_41 = V_22 -> V_41 ;
V_38 = F_9 ( V_22 , V_24 ) ;
if ( V_37 -> V_2 -> V_25 ) {
V_31 = F_5 ( V_37 -> V_2 ) ;
if ( F_15 ( V_31 ) ) {
V_39 = F_16 ( V_31 ) ;
return V_39 ;
}
V_31 -> V_38 = V_38 ;
}
if ( V_31 ) {
V_37 -> V_38 = V_31 -> V_38 ;
V_37 -> V_42 = V_31 -> V_42 ;
V_37 -> V_43 = V_31 -> V_43 ;
V_37 -> V_44 = V_31 -> V_44 ;
V_37 -> V_31 = V_31 ;
}
switch ( V_37 -> V_38 ) {
case V_45 :
V_33 = & V_46 ;
break;
case V_47 :
V_33 = & V_48 ;
break;
case V_49 :
V_33 = & V_50 ;
break;
case V_51 :
V_33 = & V_52 ;
break;
case V_53 :
V_33 = & V_54 ;
break;
case V_55 :
V_33 = & V_56 ;
break;
case V_57 :
V_33 = & V_58 ;
break;
default:
V_33 = & V_59 ;
break;
}
V_37 -> V_60 = F_17 ( V_22 , V_33 ) ;
if ( F_15 ( V_37 -> V_60 ) ) {
V_39 = F_16 ( V_37 -> V_60 ) ;
F_7 ( & V_22 -> V_2 , L_2 ,
V_39 ) ;
return V_39 ;
}
if ( V_31 && V_31 -> V_61 )
V_31 -> V_61 () ;
F_18 ( V_37 ) ;
F_19 ( V_37 -> V_2 ) ;
switch ( V_37 -> V_38 ) {
case V_62 :
V_35 = V_63 ;
V_40 = F_20 ( V_63 ) ;
break;
case V_53 :
V_35 = V_64 ;
V_40 = F_20 ( V_64 ) ;
break;
case V_55 :
V_35 = V_65 ;
V_40 = F_20 ( V_65 ) ;
break;
case V_45 :
V_35 = V_66 ;
V_40 = F_20 ( V_66 ) ;
break;
case V_47 :
V_35 = V_67 ;
V_40 = F_20 ( V_67 ) ;
break;
case V_49 :
V_35 = V_68 ;
V_40 = F_20 ( V_68 ) ;
break;
case V_51 :
V_35 = V_69 ;
V_40 = F_20 ( V_69 ) ;
break;
case V_57 :
V_35 = V_70 ;
V_40 = F_20 ( V_70 ) ;
break;
default:
F_21 () ;
}
V_39 = F_22 ( V_37 -> V_2 , - 1 , V_35 , V_40 , NULL ,
0 , NULL ) ;
if ( V_39 )
goto V_71;
F_23 ( V_37 -> V_2 , V_37 -> V_44 ) ;
return V_39 ;
V_71:
F_24 ( V_37 ) ;
return V_39 ;
}
static int F_25 ( struct V_21 * V_22 )
{
struct V_36 * V_37 = F_26 ( V_22 ) ;
F_27 ( V_37 -> V_2 ) ;
F_24 ( V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_29 ( V_2 , struct V_21 , V_2 ) ;
struct V_36 * V_37 = F_26 ( V_22 ) ;
if ( F_30 ( V_2 ) )
F_31 ( V_37 -> V_41 ) ;
F_32 ( V_37 -> V_41 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_29 ( V_2 , struct V_21 , V_2 ) ;
struct V_36 * V_37 = F_26 ( V_22 ) ;
if ( F_30 ( V_2 ) )
F_34 ( V_37 -> V_41 ) ;
F_35 ( V_37 -> V_41 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_72 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_72 ) ;
}
