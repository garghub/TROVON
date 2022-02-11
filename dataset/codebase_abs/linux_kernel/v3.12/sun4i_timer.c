static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + F_3 ( 1 ) ) ;
while ( ( V_1 - F_2 ( V_2 + F_3 ( 1 ) ) ) < 3 )
F_4 () ;
}
static void F_5 ( T_2 V_3 )
{
T_1 V_4 = F_2 ( V_2 + F_6 ( V_3 ) ) ;
F_7 ( V_4 & ~ V_5 , V_2 + F_6 ( V_3 ) ) ;
F_1 () ;
}
static void F_8 ( T_2 V_3 , unsigned long V_6 )
{
F_7 ( V_6 , V_2 + F_9 ( V_3 ) ) ;
}
static void F_10 ( T_2 V_3 , bool V_7 )
{
T_1 V_4 = F_2 ( V_2 + F_6 ( V_3 ) ) ;
if ( V_7 )
V_4 &= ~ V_8 ;
else
V_4 |= V_8 ;
F_7 ( V_4 | V_5 | V_9 ,
V_2 + F_6 ( V_3 ) ) ;
}
static void F_11 ( enum V_10 V_11 ,
struct V_12 * V_13 )
{
switch ( V_11 ) {
case V_14 :
F_5 ( 0 ) ;
F_8 ( 0 , V_15 ) ;
F_10 ( 0 , true ) ;
break;
case V_16 :
F_5 ( 0 ) ;
F_10 ( 0 , false ) ;
break;
case V_17 :
case V_18 :
default:
F_5 ( 0 ) ;
break;
}
}
static int F_12 ( unsigned long V_19 ,
struct V_12 * V_20 )
{
F_5 ( 0 ) ;
F_8 ( 0 , V_19 ) ;
F_10 ( 0 , false ) ;
return 0 ;
}
static T_3 F_13 ( int V_21 , void * V_22 )
{
struct V_12 * V_19 = (struct V_12 * ) V_22 ;
F_7 ( 0x1 , V_2 + V_23 ) ;
V_19 -> V_24 ( V_19 ) ;
return V_25 ;
}
static T_1 F_14 ( void )
{
return ~ F_2 ( V_2 + F_3 ( 1 ) ) ;
}
static void T_4 F_15 ( struct V_26 * V_27 )
{
unsigned long V_28 = 0 ;
struct V_13 * V_13 ;
int V_29 , V_21 ;
T_1 V_4 ;
V_2 = F_16 ( V_27 , 0 ) ;
if ( ! V_2 )
F_17 ( L_1 ) ;
V_21 = F_18 ( V_27 , 0 ) ;
if ( V_21 <= 0 )
F_17 ( L_2 ) ;
V_13 = F_19 ( V_27 , 0 ) ;
if ( F_20 ( V_13 ) )
F_17 ( L_3 ) ;
F_21 ( V_13 ) ;
V_28 = F_22 ( V_13 ) ;
F_7 ( ~ 0 , V_2 + F_9 ( 1 ) ) ;
F_7 ( V_5 | V_9 |
F_23 ( V_30 ) ,
V_2 + F_6 ( 1 ) ) ;
F_24 ( F_14 , 32 , V_28 ) ;
F_25 ( V_2 + F_3 ( 1 ) , V_27 -> V_31 ,
V_28 , 300 , 32 , V_32 ) ;
V_15 = F_26 ( V_28 , V_33 ) ;
F_7 ( F_23 ( V_30 ) ,
V_2 + F_6 ( 0 ) ) ;
V_29 = F_27 ( V_21 , & V_34 ) ;
if ( V_29 )
F_28 ( L_4 , V_21 ) ;
V_4 = F_2 ( V_2 + V_35 ) ;
F_7 ( V_4 | F_29 ( 0 ) , V_2 + V_35 ) ;
V_36 . V_37 = F_30 ( 0 ) ;
F_31 ( & V_36 , V_28 , 0x1 ,
0xffffffff ) ;
}
