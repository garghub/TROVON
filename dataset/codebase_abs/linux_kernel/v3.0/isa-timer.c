static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( V_5 ) ;
switch ( V_2 ) {
case V_6 :
F_3 ( 0x34 , V_7 ) ;
F_3 ( V_8 & 0xff , V_9 ) ;
F_3 ( V_8 >> 8 , V_9 ) ;
break;
case V_10 :
case V_11 :
F_3 ( 0x30 , V_7 ) ;
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_9 ) ;
break;
case V_12 :
case V_13 :
break;
}
F_4 ( V_5 ) ;
}
static int F_5 ( unsigned long V_14 ,
struct V_3 * V_4 )
{
return 0 ;
}
static T_1 F_6 ( int V_15 , void * V_16 )
{
struct V_3 * V_17 = V_16 ;
V_17 -> V_18 ( V_17 ) ;
return V_19 ;
}
static void T_2 F_7 ( void )
{
V_20 . V_21 = F_8 ( F_9 () ) ;
V_20 . V_22 = F_10 ( V_23 , V_24 , V_20 . V_25 ) ;
V_20 . V_26 = F_11 ( 0x7fff , & V_20 ) ;
V_20 . V_27 = F_11 ( 0x000f , & V_20 ) ;
F_12 () ;
F_13 ( V_20 . V_15 , & V_28 ) ;
F_14 ( & V_20 ) ;
}
