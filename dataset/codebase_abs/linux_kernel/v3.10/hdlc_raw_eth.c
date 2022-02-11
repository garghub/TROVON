static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = V_6 - V_2 -> V_7 ;
if ( V_5 > 0 ) {
int V_7 = V_2 -> V_7 ;
if ( F_2 ( V_2 ) < V_5 )
if ( F_3 ( V_2 , 0 , V_5 , V_8 ) ) {
V_4 -> V_9 . V_10 ++ ;
F_4 ( V_2 ) ;
return 0 ;
}
F_5 ( V_2 , V_5 ) ;
memset ( V_2 -> V_11 + V_7 , 0 , V_5 ) ;
}
return F_6 ( V_4 ) -> F_7 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
T_2 T_3 * V_14 = V_13 -> V_15 . V_16 . V_17 ;
const T_4 V_18 = sizeof( T_2 ) ;
T_2 V_19 ;
T_5 * V_20 = F_6 ( V_4 ) ;
int V_21 , V_22 ;
switch ( V_13 -> V_15 . type ) {
case V_23 :
if ( F_6 ( V_4 ) -> V_24 != & V_24 )
return - V_25 ;
V_13 -> V_15 . type = V_26 ;
if ( V_13 -> V_15 . V_18 < V_18 ) {
V_13 -> V_15 . V_18 = V_18 ;
return - V_27 ;
}
if ( F_9 ( V_14 , V_20 -> V_28 , V_18 ) )
return - V_29 ;
return 0 ;
case V_26 :
if ( ! F_10 ( V_30 ) )
return - V_31 ;
if ( V_4 -> V_32 & V_33 )
return - V_34 ;
if ( F_11 ( & V_19 , V_14 , V_18 ) )
return - V_29 ;
if ( V_19 . V_35 == V_36 )
V_19 . V_35 = V_37 ;
if ( V_19 . V_38 == V_39 )
V_19 . V_38 = V_40 ;
V_21 = V_20 -> V_41 ( V_4 , V_19 . V_35 ,
V_19 . V_38 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_4 , & V_24 ,
sizeof( T_2 ) ) ;
if ( V_21 )
return V_21 ;
memcpy ( V_20 -> V_28 , & V_19 , V_18 ) ;
V_22 = V_4 -> V_42 ;
F_13 ( V_4 ) ;
V_4 -> V_42 = V_22 ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
return - V_25 ;
}
static int T_6 F_16 ( void )
{
F_17 ( & V_24 ) ;
return 0 ;
}
static void T_7 F_18 ( void )
{
F_19 ( & V_24 ) ;
}
