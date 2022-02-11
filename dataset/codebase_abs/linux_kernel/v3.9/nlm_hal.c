void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 -> V_4 = F_3 ( V_1 ) ;
V_3 -> V_5 = F_4 ( V_1 ) ;
V_3 -> V_6 = F_5 () & ( ~ ( ( 1 << 12 ) - 1 ) ) ;
F_6 ( & V_3 -> V_7 ) ;
}
int F_7 ( int V_8 )
{
if ( ! F_8 ( V_8 ) )
return - 1 ;
switch ( V_8 ) {
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
default:
return - 1 ;
}
}
unsigned int F_9 ( int V_1 , int V_39 )
{
unsigned int V_40 , V_41 , V_42 , V_43 ;
unsigned int V_44 , V_45 , V_46 ;
T_1 V_47 , V_4 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
V_44 = F_10 ( V_4 , V_48 ) ;
V_45 = F_10 ( V_4 , V_49 ) ;
V_40 = ( ( V_44 >> 10 ) & 0x7f ) + 1 ;
V_41 = ( ( V_44 >> 8 ) & 0x3 ) + 1 ;
V_43 = ( ( V_44 >> 30 ) & 0x3 ) + 1 ;
V_42 = ( ( V_45 >> ( V_39 * 4 ) ) & 0xf ) + 1 ;
V_47 = 800000000ULL * V_40 ;
V_46 = 3 * V_41 * V_43 * V_42 ;
F_11 ( V_47 , V_46 ) ;
return ( unsigned int ) V_47 ;
}
unsigned int F_12 ( void )
{
return F_9 ( 0 , 0 ) ;
}
