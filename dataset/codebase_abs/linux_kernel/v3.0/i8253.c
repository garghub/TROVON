static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_5 ) ;
switch( V_2 ) {
case V_6 :
F_3 ( 0x34 , V_7 ) ;
F_3 ( V_8 & 0xff , V_9 ) ;
F_4 ( V_8 >> 8 , V_9 ) ;
break;
case V_10 :
case V_11 :
if ( V_4 -> V_2 == V_6 ||
V_4 -> V_2 == V_12 ) {
F_3 ( 0x30 , V_7 ) ;
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_9 ) ;
}
break;
case V_12 :
F_3 ( 0x38 , V_7 ) ;
break;
case V_13 :
break;
}
F_5 ( & V_5 ) ;
}
static int F_6 ( unsigned long V_14 , struct V_3 * V_4 )
{
F_2 ( & V_5 ) ;
F_3 ( V_14 & 0xff , V_9 ) ;
F_4 ( V_14 >> 8 , V_9 ) ;
F_5 ( & V_5 ) ;
return 0 ;
}
static T_1 F_7 ( int V_15 , void * V_16 )
{
V_17 . V_18 ( & V_17 ) ;
return V_19 ;
}
void T_2 F_8 ( void )
{
struct V_3 * V_20 = & V_17 ;
unsigned int V_21 = F_9 () ;
V_20 -> V_22 = F_10 ( V_21 ) ;
F_11 ( V_20 , V_23 ) ;
V_20 -> V_24 = F_12 ( 0x7FFF , V_20 ) ;
V_20 -> V_25 = F_12 ( 0xF , V_20 ) ;
F_13 ( V_20 ) ;
F_14 ( 0 , & V_26 ) ;
}
static int T_2 F_15 ( void )
{
if ( F_16 () > 1 )
return 0 ;
return F_17 () ;
}
