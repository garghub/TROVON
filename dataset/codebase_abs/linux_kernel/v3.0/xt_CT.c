static unsigned int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_2 -> V_10 != NULL )
return V_11 ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
V_2 -> V_10 = & V_9 -> V_12 ;
V_2 -> V_14 = V_15 ;
return V_11 ;
}
static T_1 F_3 ( const struct V_16 * V_4 )
{
if ( V_4 -> V_17 == V_18 ) {
const struct V_19 * V_20 = V_4 -> V_21 ;
if ( V_20 -> V_22 . V_23 & V_24 )
return 0 ;
return V_20 -> V_22 . V_25 ;
} else if ( V_4 -> V_17 == V_26 ) {
const struct V_27 * V_20 = V_4 -> V_21 ;
if ( V_20 -> V_28 . V_23 & V_29 )
return 0 ;
return V_20 -> V_28 . V_25 ;
} else
return 0 ;
}
static int F_4 ( const struct V_16 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_30 V_31 ;
struct V_32 * V_33 ;
struct V_8 * V_9 ;
int V_34 = 0 ;
T_1 V_25 ;
if ( V_6 -> V_35 & ~ V_36 )
return - V_37 ;
if ( V_6 -> V_35 & V_36 ) {
V_9 = F_5 () ;
F_2 ( & V_9 -> V_12 . V_13 ) ;
goto V_38;
}
#ifndef F_6
if ( V_6 -> V_39 )
goto V_40;
#endif
V_34 = F_7 ( V_4 -> V_17 ) ;
if ( V_34 < 0 )
goto V_40;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_9 = F_8 ( V_4 -> V_41 , V_6 -> V_39 , & V_31 , & V_31 , V_42 ) ;
V_34 = F_9 ( V_9 ) ;
if ( F_10 ( V_9 ) )
goto V_43;
V_34 = 0 ;
if ( ( V_6 -> V_44 || V_6 -> V_45 ) &&
! F_11 ( V_9 , V_6 -> V_44 , V_6 -> V_45 ,
V_42 ) )
goto V_46;
if ( V_6 -> V_47 [ 0 ] ) {
V_34 = - V_48 ;
V_25 = F_3 ( V_4 ) ;
if ( ! V_25 )
goto V_46;
V_34 = - V_49 ;
V_33 = F_12 ( V_9 , V_42 ) ;
if ( V_33 == NULL )
goto V_46;
V_34 = - V_48 ;
V_33 -> V_47 = F_13 ( V_6 -> V_47 ,
V_4 -> V_17 ,
V_25 ) ;
if ( V_33 -> V_47 == NULL )
goto V_46;
}
F_14 ( V_50 , & V_9 -> V_51 ) ;
F_14 ( V_52 , & V_9 -> V_51 ) ;
V_38:
V_6 -> V_9 = V_9 ;
return 0 ;
V_46:
F_15 ( V_9 ) ;
V_43:
F_16 ( V_4 -> V_17 ) ;
V_40:
return V_34 ;
}
static void F_17 ( const struct V_53 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_32 * V_33 ;
if ( ! F_18 ( V_9 ) ) {
V_33 = F_19 ( V_9 ) ;
if ( V_33 )
F_20 ( V_33 -> V_47 -> V_54 ) ;
F_16 ( V_4 -> V_17 ) ;
}
F_21 ( V_6 -> V_9 ) ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_55 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_55 ) ;
}
