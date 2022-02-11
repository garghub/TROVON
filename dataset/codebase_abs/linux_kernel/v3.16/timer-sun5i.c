static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + F_3 ( 1 ) ) ;
while ( ( V_1 - F_2 ( V_2 + F_3 ( 1 ) ) ) < V_3 )
F_4 () ;
}
static void F_5 ( T_2 V_4 )
{
T_1 V_5 = F_2 ( V_2 + F_6 ( V_4 ) ) ;
F_7 ( V_5 & ~ V_6 , V_2 + F_6 ( V_4 ) ) ;
F_1 () ;
}
static void F_8 ( T_2 V_4 , T_1 V_7 )
{
F_7 ( V_7 , V_2 + F_9 ( V_4 ) ) ;
}
static void F_10 ( T_2 V_4 , bool V_8 )
{
T_1 V_5 = F_2 ( V_2 + F_6 ( V_4 ) ) ;
if ( V_8 )
V_5 &= ~ V_9 ;
else
V_5 |= V_9 ;
F_7 ( V_5 | V_6 | V_10 ,
V_2 + F_6 ( V_4 ) ) ;
}
static void F_11 ( enum V_11 V_12 ,
struct V_13 * V_14 )
{
switch ( V_12 ) {
case V_15 :
F_5 ( 0 ) ;
F_8 ( 0 , V_16 ) ;
F_10 ( 0 , true ) ;
break;
case V_17 :
F_5 ( 0 ) ;
F_10 ( 0 , false ) ;
break;
case V_18 :
case V_19 :
default:
F_5 ( 0 ) ;
break;
}
}
static int F_12 ( unsigned long V_20 ,
struct V_13 * V_21 )
{
F_5 ( 0 ) ;
F_8 ( 0 , V_20 - V_3 ) ;
F_10 ( 0 , false ) ;
return 0 ;
}
static T_3 F_13 ( int V_22 , void * V_23 )
{
struct V_13 * V_20 = (struct V_13 * ) V_23 ;
F_7 ( 0x1 , V_2 + V_24 ) ;
V_20 -> V_25 ( V_20 ) ;
return V_26 ;
}
static T_4 F_14 ( void )
{
return ~ F_2 ( V_2 + F_3 ( 1 ) ) ;
}
static void T_5 F_15 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
unsigned long V_31 ;
struct V_14 * V_14 ;
int V_32 , V_22 ;
T_1 V_5 ;
V_2 = F_16 ( V_28 , 0 ) ;
if ( ! V_2 )
F_17 ( L_1 ) ;
V_22 = F_18 ( V_28 , 0 ) ;
if ( V_22 <= 0 )
F_17 ( L_2 ) ;
V_14 = F_19 ( V_28 , 0 ) ;
if ( F_20 ( V_14 ) )
F_17 ( L_3 ) ;
F_21 ( V_14 ) ;
V_31 = F_22 ( V_14 ) ;
V_30 = F_23 ( V_28 , NULL ) ;
if ( ! F_20 ( V_30 ) )
F_24 ( V_30 ) ;
F_7 ( ~ 0 , V_2 + F_9 ( 1 ) ) ;
F_7 ( V_6 | V_10 ,
V_2 + F_6 ( 1 ) ) ;
F_25 ( F_14 , 32 , V_31 ) ;
F_26 ( V_2 + F_3 ( 1 ) , V_28 -> V_33 ,
V_31 , 340 , 32 , V_34 ) ;
V_16 = F_27 ( V_31 , V_35 ) ;
V_32 = F_28 ( V_22 , & V_36 ) ;
if ( V_32 )
F_29 ( L_4 , V_22 ) ;
V_5 = F_2 ( V_2 + V_37 ) ;
F_7 ( V_5 | F_30 ( 0 ) , V_2 + V_37 ) ;
V_38 . V_39 = V_40 ;
V_38 . V_22 = V_22 ;
F_31 ( & V_38 , V_31 ,
V_3 , 0xffffffff ) ;
}
