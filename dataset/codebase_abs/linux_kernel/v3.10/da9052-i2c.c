static inline bool F_1 ( unsigned char V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_19 * V_19 , unsigned char V_1 )
{
int V_20 ;
switch ( V_19 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if ( ! F_1 ( V_1 ) )
return F_3 ( V_19 -> V_26 ,
V_27 ,
& V_20 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_19 * V_19 )
{
int V_28 , V_29 ;
V_29 = F_3 ( V_19 -> V_26 , V_30 , & V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_28 & V_31 ) {
V_28 &= ~ V_31 ;
V_29 = F_5 ( V_19 -> V_26 , V_30 ,
V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_6 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
struct V_19 * V_19 ;
int V_29 ;
V_19 = F_7 ( & V_33 -> V_36 , sizeof( struct V_19 ) , V_37 ) ;
if ( ! V_19 )
return - V_38 ;
if ( ! F_8 ( V_33 -> V_39 ,
V_40 ) ) {
F_9 ( & V_33 -> V_36 , L_1 ,
V_41 ) ;
return - V_42 ;
}
V_19 -> V_36 = & V_33 -> V_36 ;
V_19 -> V_43 = V_33 -> V_44 ;
V_19 -> V_45 = F_2 ;
F_10 ( V_33 , V_19 ) ;
V_19 -> V_26 = F_11 ( V_33 , & V_46 ) ;
if ( F_12 ( V_19 -> V_26 ) ) {
V_29 = F_13 ( V_19 -> V_26 ) ;
F_14 ( & V_33 -> V_36 , L_2 ,
V_29 ) ;
return V_29 ;
}
V_29 = F_4 ( V_19 ) ;
if ( V_29 < 0 )
return V_29 ;
#ifdef F_15
if ( ! V_35 ) {
struct V_47 * V_48 = V_33 -> V_36 . V_49 ;
const struct V_50 * V_51 ;
V_51 = F_16 ( V_52 , V_48 ) ;
V_35 = V_51 -> V_53 ;
}
#endif
if ( ! V_35 ) {
V_29 = - V_42 ;
F_14 ( & V_33 -> V_36 , L_3 ) ;
return V_29 ;
}
V_29 = F_17 ( V_19 , V_35 -> V_54 ) ;
if ( V_29 != 0 )
return V_29 ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_19 * V_19 = F_19 ( V_33 ) ;
F_20 ( V_19 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_29 ;
V_29 = F_22 ( & V_55 ) ;
if ( V_29 != 0 ) {
F_23 ( L_4 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_55 ) ;
}
