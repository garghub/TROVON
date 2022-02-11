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
case V_28 :
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_19 * V_19 )
{
int V_29 , V_30 ;
V_30 = F_3 ( V_19 -> V_26 , V_31 , & V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! ( V_29 & V_32 ) ) {
V_29 |= V_32 ;
V_30 = F_5 ( V_19 -> V_26 , V_31 ,
V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
static int F_6 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_19 * V_19 ;
int V_30 ;
V_19 = F_7 ( & V_34 -> V_37 , sizeof( struct V_19 ) , V_38 ) ;
if ( ! V_19 )
return - V_39 ;
if ( ! F_8 ( V_34 -> V_40 ,
V_41 ) ) {
F_9 ( & V_34 -> V_37 , L_1 ,
V_42 ) ;
return - V_43 ;
}
V_19 -> V_37 = & V_34 -> V_37 ;
V_19 -> V_44 = V_34 -> V_45 ;
V_19 -> V_46 = F_2 ;
F_10 ( V_34 , V_19 ) ;
V_19 -> V_26 = F_11 ( V_34 , & V_47 ) ;
if ( F_12 ( V_19 -> V_26 ) ) {
V_30 = F_13 ( V_19 -> V_26 ) ;
F_14 ( & V_34 -> V_37 , L_2 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_4 ( V_19 ) ;
if ( V_30 < 0 )
return V_30 ;
#ifdef F_15
if ( ! V_36 ) {
struct V_48 * V_49 = V_34 -> V_37 . V_50 ;
const struct V_51 * V_52 ;
V_52 = F_16 ( V_53 , V_49 ) ;
V_36 = V_52 -> V_54 ;
}
#endif
if ( ! V_36 ) {
V_30 = - V_43 ;
F_14 ( & V_34 -> V_37 , L_3 ) ;
return V_30 ;
}
V_30 = F_17 ( V_19 , V_36 -> V_55 ) ;
if ( V_30 != 0 )
return V_30 ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 )
{
struct V_19 * V_19 = F_19 ( V_34 ) ;
F_20 ( V_19 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_30 ;
V_30 = F_22 ( & V_56 ) ;
if ( V_30 != 0 ) {
F_23 ( L_4 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_56 ) ;
}
