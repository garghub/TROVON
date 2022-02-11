static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( 10 ) ;
F_3 ( 3 , V_4 + V_5 ) ;
while ( ( F_4 ( ( V_4 + V_6 ) ) & V_7 )
&& -- V_3 )
F_5 () ;
return F_4 ( V_4 + V_8 ) ;
}
static int F_6 ( unsigned long V_9 ,
struct V_10 * V_11 )
{
int V_3 = F_2 ( 10 ) ;
T_1 V_12 = V_1 . V_13 ( & V_1 ) + V_9 ;
while ( ( F_4 ( V_4 + V_6 ) & V_14 )
&& -- V_3 )
F_5 () ;
F_3 ( ( unsigned long ) V_12 , V_4 + V_15 ) ;
if ( ( signed ) ( V_12 - V_1 . V_13 ( & V_1 ) ) <= 16 )
return - V_16 ;
F_3 ( 1 , V_4 + V_17 ) ;
return 0 ;
}
static void F_7 ( enum V_18 V_19 ,
struct V_10 * V_11 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
break;
case V_22 :
case V_23 :
case V_24 :
F_3 ( F_4 ( V_4 + V_5 ) | 1 ,
V_4 + V_5 ) ;
F_3 ( 0 , V_4 + V_17 ) ;
break;
}
}
static T_2 F_8 ( int V_25 , void * V_26 )
{
struct V_10 * V_11 = V_26 ;
F_3 ( 0xf , V_4 + V_27 ) ;
V_11 -> V_28 ( V_11 ) ;
return V_29 ;
}
static void T_3 F_9 ( void )
{
V_4 = F_10 ( V_30 + V_31 , 0x28 ) ;
if ( ! V_4 )
F_11 ( V_32 L_1 ) ;
F_3 ( 1 , V_4 + V_5 ) ;
F_3 ( 0xf , V_4 + V_27 ) ;
F_3 ( ~ 0 , V_4 + V_15 ) ;
if ( F_12 ( & V_1 , V_33 ) )
F_11 ( V_32 L_2 ,
V_1 . V_34 ) ;
F_13 ( & V_35 , V_33 , 4 ) ;
V_35 . V_36 =
F_14 ( 0xf0000000 , & V_35 ) ;
V_35 . V_37 = F_14 ( 4 , & V_35 ) ;
V_35 . V_38 = F_15 ( 0 ) ;
if ( F_16 ( V_39 , & V_25 ) )
F_11 ( V_32 L_3 ,
V_35 . V_34 ) ;
F_17 ( & V_35 ) ;
}
