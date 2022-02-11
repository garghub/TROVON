static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_5 ) ;
}
static int F_3 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
T_2 T_3 * V_8 = V_7 -> V_9 . V_10 . V_11 ;
const T_4 V_12 = sizeof( T_2 ) ;
T_2 V_13 ;
T_5 * V_14 = F_4 ( V_4 ) ;
int V_15 ;
switch ( V_7 -> V_9 . type ) {
case V_16 :
if ( F_4 ( V_4 ) -> V_17 != & V_17 )
return - V_18 ;
V_7 -> V_9 . type = V_19 ;
if ( V_7 -> V_9 . V_12 < V_12 ) {
V_7 -> V_9 . V_12 = V_12 ;
return - V_20 ;
}
if ( F_5 ( V_8 , V_14 -> V_21 , V_12 ) )
return - V_22 ;
return 0 ;
case V_19 :
if ( ! F_6 ( V_23 ) )
return - V_24 ;
if ( V_4 -> V_25 & V_26 )
return - V_27 ;
if ( F_7 ( & V_13 , V_8 , V_12 ) )
return - V_22 ;
if ( V_13 . V_28 == V_29 )
V_13 . V_28 = V_30 ;
if ( V_13 . V_31 == V_32 )
V_13 . V_31 = V_33 ;
V_15 = V_14 -> V_34 ( V_4 , V_13 . V_28 ,
V_13 . V_31 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_8 ( V_4 , & V_17 ,
sizeof( T_2 ) ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_14 -> V_21 , & V_13 , V_12 ) ;
V_4 -> type = V_35 ;
F_9 ( V_36 , V_4 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
return - V_18 ;
}
static int T_6 F_11 ( void )
{
F_12 ( & V_17 ) ;
return 0 ;
}
static void T_7 F_13 ( void )
{
F_14 ( & V_17 ) ;
}
