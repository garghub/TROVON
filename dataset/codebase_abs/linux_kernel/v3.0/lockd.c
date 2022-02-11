static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * * V_6 )
{
T_1 V_7 ;
struct V_8 V_9 ;
F_2 ( & V_9 , 0 ) ;
V_9 . V_10 . V_11 = V_4 -> V_12 ;
memcpy ( ( char * ) & V_9 . V_10 . V_13 , V_4 -> V_14 , V_4 -> V_12 ) ;
V_9 . V_15 = NULL ;
F_3 () ;
V_7 = F_4 ( V_2 , & V_9 , V_16 , V_17 , V_6 ) ;
F_5 ( & V_9 ) ;
F_6 () ;
switch ( V_7 ) {
case V_18 :
return 0 ;
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
default:
return V_23 ;
}
}
static void
F_7 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
}
void
F_9 ( void )
{
F_10 ( L_1 ) ;
V_24 = & V_25 ;
}
void
F_11 ( void )
{
V_24 = NULL ;
}
