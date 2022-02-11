static T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - * V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
* V_5 = V_2 -> V_3 ;
* V_6 = 0 ;
* V_7 = V_8 | V_9 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
* V_7 = 0 ;
}
static int F_4 ( unsigned long V_10 ,
struct V_11 * V_12 )
{
* V_13 = 0 ;
* V_14 = V_10 ;
* V_15 = V_8 | V_9 ;
return 0 ;
}
static void F_5 ( enum V_16 V_17 ,
struct V_11 * V_12 )
{
switch ( V_17 ) {
case V_18 :
case V_19 :
* V_13 = 0 ;
* V_14 = ( V_20 + 8 * V_21 ) / ( 16 * V_21 ) ;
* V_15 = V_8 | V_22 |
V_9 ;
break;
case V_23 :
case V_24 :
case V_25 :
* V_15 = 0 ;
break;
}
}
static T_2 F_6 ( int V_26 , void * V_27 )
{
struct V_11 * V_28 = V_27 ;
* V_13 = 0 ;
if ( V_28 -> V_17 == V_23 )
* V_15 = 0 ;
V_28 -> V_29 ( V_28 ) ;
return V_30 ;
}
void T_3 F_7 ( void )
{
struct V_11 * V_28 = & V_31 ;
unsigned V_32 = F_8 ( V_20 , 16 ) ;
F_9 ( & V_33 , V_32 ) ;
F_10 ( V_28 -> V_26 , & V_34 ) ;
V_28 -> V_35 = F_11 ( F_12 () ) ;
F_13 ( V_28 , V_32 , 0x4 , 0xffffff ) ;
}
static T_4 T_5 F_14 ( void )
{
return ~ * V_36 ;
}
void T_3 F_15 ( void )
{
unsigned V_32 = F_8 ( V_20 , 16 ) ;
* V_37 = 0 ;
* V_38 = 0 ;
* V_39 = V_8 | V_9 ;
F_16 ( F_14 , 24 , V_32 ) ;
}
