static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
}
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
return true ;
}
return false ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_4 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_10 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_35 :
case V_36 :
return true ;
}
return false ;
}
static int F_4 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_41 * V_41 ;
struct V_42 * V_43 = V_38 -> V_2 . V_44 ;
unsigned int V_45 , V_46 ;
int V_47 ;
if ( ! V_43 )
F_5 ( & V_38 -> V_2 , L_1 ) ;
V_41 = F_6 ( & V_38 -> V_2 , sizeof( struct V_41 ) , V_48 ) ;
if ( ! V_41 ) {
F_7 ( & V_38 -> V_2 , L_2 ) ;
return - V_49 ;
}
V_41 -> V_2 = & V_38 -> V_2 ;
F_8 ( V_38 , V_41 ) ;
if ( V_38 -> V_50 )
F_9 ( & V_38 -> V_2 , L_3 ) ;
V_41 -> V_51 = F_10 ( V_38 , & V_52 ) ;
if ( F_11 ( V_41 -> V_51 ) ) {
V_47 = F_12 ( V_41 -> V_51 ) ;
F_7 ( & V_38 -> V_2 , L_4 , V_47 ) ;
return V_47 ;
}
V_47 = F_13 ( V_41 -> V_51 , V_35 , & V_45 ) ;
if ( ! V_47 )
V_47 = F_13 ( V_41 -> V_51 , V_36 , & V_46 ) ;
if ( V_47 < 0 ) {
F_7 ( & V_38 -> V_2 , L_5 , V_47 ) ;
return V_47 ;
}
if ( V_45 != 0x8b )
return - V_53 ;
F_14 ( V_41 -> V_2 , L_6 , V_45 , V_46 ) ;
if ( V_43 ) {
V_54 [ V_55 ] . V_44 = & V_43 -> V_56 ;
V_54 [ V_55 ] . V_57 = sizeof( V_43 -> V_56 ) ;
V_54 [ V_58 ] . V_44 = & V_43 -> V_59 ;
V_54 [ V_58 ] . V_57 = sizeof( V_43 -> V_59 ) ;
} else {
V_54 [ V_55 ] . V_44 = NULL ;
V_54 [ V_55 ] . V_57 = 0 ;
V_54 [ V_58 ] . V_44 = NULL ;
V_54 [ V_58 ] . V_57 = 0 ;
}
V_47 = F_15 ( V_41 -> V_2 , - 1 , V_54 ,
F_16 ( V_54 ) , NULL , 0 , NULL ) ;
if ( V_47 < 0 )
F_7 ( & V_38 -> V_2 , L_7 , V_47 ) ;
return V_47 ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_41 * V_41 = F_18 ( V_38 ) ;
F_19 ( V_41 -> V_2 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_60 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_60 ) ;
}
