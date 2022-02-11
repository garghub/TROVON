void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) & 0x7fff , V_1 ) ;
}
void F_4 ( void )
{
F_2 ( 0xe310 , V_1 ) ;
}
static void F_5 ( enum V_2 V_3 ,
struct V_4 * V_5 )
{
F_6 ( & V_6 ) ;
switch ( V_3 ) {
case V_7 :
F_2 ( V_8 , V_9 ) ;
F_2 ( 0 , V_10 ) ;
F_4 () ;
break;
case V_11 :
case V_12 :
if ( V_5 -> V_3 == V_7 ||
V_5 -> V_3 == V_13 )
F_1 () ;
break;
case V_13 :
break;
case V_14 :
break;
}
F_7 ( & V_6 ) ;
}
static T_1 F_8 ( int V_15 , void * V_16 )
{
T_2 V_17 ;
F_9 ( F_10 ( V_18 ) , & V_17 , & V_19 ) ;
F_2 ( F_3 ( V_1 ) | 0x4000 , V_1 ) ;
V_20 . V_21 ( & V_20 ) ;
return V_22 ;
}
void T_3 F_11 ( void )
{
T_2 V_17 ;
struct V_4 * V_23 = & V_20 ;
unsigned int V_24 = F_12 () ;
V_23 -> V_25 = F_13 ( V_24 ) ;
F_14 ( V_23 , V_26 ) ;
V_23 -> V_27 = F_15 ( 0xffff , V_23 ) ;
V_23 -> V_28 = F_15 ( 0xf , V_23 ) ;
F_16 ( F_10 ( V_29 ) , 0 , 0x100 ) ;
F_16 ( F_10 ( V_30 ) , 0 , 0x50000 ) ;
F_9 ( F_10 ( V_18 ) , & V_17 , & V_19 ) ;
F_17 ( V_23 ) ;
F_18 ( V_31 , & V_32 ) ;
}
static T_4 F_19 ( struct V_33 * V_34 )
{
unsigned long V_35 ;
int V_36 ;
T_2 V_37 ;
static int V_38 ;
static T_2 V_39 ;
F_20 ( & V_6 , V_35 ) ;
V_37 = V_40 ;
V_36 = F_3 ( V_10 ) ;
if ( V_36 < V_38 && V_37 == V_39 )
V_36 = V_38 ;
V_38 = V_36 ;
V_39 = V_37 ;
F_21 ( & V_6 , V_35 ) ;
return ( T_4 ) ( V_37 * V_8 ) + V_36 ;
}
int T_3 F_22 ( void )
{
if ( F_23 () > 1 )
return 0 ;
return F_24 ( & V_41 , V_26 ) ;
}
