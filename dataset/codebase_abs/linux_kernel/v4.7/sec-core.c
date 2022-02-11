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
static void F_5 ( struct V_17 * V_18 )
{
unsigned int V_19 ;
if ( ! F_6 ( V_18 -> V_20 , V_21 , & V_19 ) )
F_7 ( V_18 -> V_2 , L_1 , V_19 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
int V_22 ;
if ( V_18 -> V_23 != V_24 )
return;
if ( V_18 -> V_25 -> V_26 ) {
V_22 = F_9 ( V_18 -> V_20 ,
V_27 ,
V_28 , 0x0 ) ;
if ( V_22 )
F_10 ( V_18 -> V_2 ,
L_2 ,
V_22 ) ;
}
}
static struct V_29 * F_11 (
struct V_1 * V_2 )
{
struct V_29 * V_30 ;
V_30 = F_12 ( V_2 , sizeof( * V_30 ) , V_31 ) ;
if ( ! V_30 )
return F_13 ( - V_32 ) ;
V_30 -> V_33 = F_14 ( V_2 -> V_34 ,
L_3 ) ;
V_30 -> V_26 = F_14 ( V_2 -> V_34 ,
L_4 ) ;
return V_30 ;
}
static struct V_29 * F_11 (
struct V_1 * V_2 )
{
return NULL ;
}
static inline unsigned long F_15 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
#ifdef F_16
if ( V_36 -> V_2 . V_34 ) {
const struct V_39 * V_40 ;
V_40 = F_17 ( V_41 , V_36 -> V_2 . V_34 ) ;
return ( unsigned long ) V_40 -> V_42 ;
}
#endif
return V_38 -> V_43 ;
}
static int F_18 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_29 * V_25 = F_19 ( & V_36 -> V_2 ) ;
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
struct V_17 * V_18 ;
unsigned long V_23 ;
int V_48 , V_49 ;
V_18 = F_12 ( & V_36 -> V_2 , sizeof( struct V_17 ) ,
V_31 ) ;
if ( V_18 == NULL )
return - V_32 ;
F_20 ( V_36 , V_18 ) ;
V_18 -> V_2 = & V_36 -> V_2 ;
V_18 -> V_36 = V_36 ;
V_18 -> V_50 = V_36 -> V_50 ;
V_23 = F_15 ( V_36 , V_38 ) ;
if ( V_18 -> V_2 -> V_34 ) {
V_25 = F_11 ( V_18 -> V_2 ) ;
if ( F_21 ( V_25 ) ) {
V_48 = F_22 ( V_25 ) ;
return V_48 ;
}
V_25 -> V_23 = V_23 ;
}
if ( V_25 ) {
V_18 -> V_23 = V_25 -> V_23 ;
V_18 -> V_51 = V_25 -> V_51 ;
V_18 -> V_52 = V_25 -> V_52 ;
V_18 -> V_25 = V_25 ;
}
switch ( V_18 -> V_23 ) {
case V_53 :
V_45 = & V_54 ;
break;
case V_55 :
V_45 = & V_56 ;
break;
case V_24 :
V_45 = & V_57 ;
break;
case V_58 :
V_45 = & V_59 ;
break;
case V_60 :
V_45 = & V_61 ;
break;
case V_62 :
V_45 = & V_63 ;
break;
case V_64 :
V_45 = & V_65 ;
break;
case V_66 :
V_45 = & V_67 ;
break;
default:
V_45 = & V_68 ;
break;
}
V_18 -> V_20 = F_23 ( V_36 , V_45 ) ;
if ( F_21 ( V_18 -> V_20 ) ) {
V_48 = F_22 ( V_18 -> V_20 ) ;
F_24 ( & V_36 -> V_2 , L_5 ,
V_48 ) ;
return V_48 ;
}
if ( V_25 && V_25 -> V_69 )
V_25 -> V_69 () ;
F_25 ( V_18 ) ;
F_26 ( V_18 -> V_2 ) ;
switch ( V_18 -> V_23 ) {
case V_70 :
V_47 = V_71 ;
V_49 = F_27 ( V_71 ) ;
break;
case V_62 :
V_47 = V_72 ;
V_49 = F_27 ( V_72 ) ;
break;
case V_64 :
V_47 = V_73 ;
V_49 = F_27 ( V_73 ) ;
break;
case V_53 :
V_47 = V_74 ;
V_49 = F_27 ( V_74 ) ;
break;
case V_55 :
V_47 = V_75 ;
V_49 = F_27 ( V_75 ) ;
break;
case V_24 :
V_47 = V_76 ;
V_49 = F_27 ( V_76 ) ;
break;
case V_58 :
V_47 = V_77 ;
V_49 = F_27 ( V_77 ) ;
break;
case V_60 :
V_47 = V_78 ;
V_49 = F_27 ( V_78 ) ;
break;
case V_66 :
V_47 = V_79 ;
V_49 = F_27 ( V_79 ) ;
break;
default:
F_28 () ;
}
V_48 = F_29 ( V_18 -> V_2 , - 1 , V_47 , V_49 ,
NULL , 0 , NULL ) ;
if ( V_48 )
return V_48 ;
F_30 ( V_18 -> V_2 , V_18 -> V_52 ) ;
F_8 ( V_18 ) ;
F_5 ( V_18 ) ;
return V_48 ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_32 ( V_36 ) ;
unsigned int V_3 , V_80 ;
if ( ! V_18 -> V_25 -> V_33 )
return;
switch ( V_18 -> V_23 ) {
case V_55 :
V_3 = V_81 ;
V_80 = V_82 ;
break;
default:
F_10 ( V_18 -> V_2 ,
L_6 ,
V_18 -> V_23 ) ;
return;
}
F_9 ( V_18 -> V_20 , V_3 , V_80 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_34 ( V_2 ) ;
struct V_17 * V_18 = F_32 ( V_36 ) ;
if ( F_35 ( V_2 ) )
F_36 ( V_18 -> V_50 ) ;
F_37 ( V_18 -> V_50 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_34 ( V_2 ) ;
struct V_17 * V_18 = F_32 ( V_36 ) ;
if ( F_35 ( V_2 ) )
F_39 ( V_18 -> V_50 ) ;
F_40 ( V_18 -> V_50 ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
return F_42 ( & V_83 ) ;
}
static void T_2 F_43 ( void )
{
F_44 ( & V_83 ) ;
}
