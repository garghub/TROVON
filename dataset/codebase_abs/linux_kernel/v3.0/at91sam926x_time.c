static T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_2 V_4 ;
T_2 V_5 ;
F_2 ( V_3 ) ;
V_4 = V_6 ;
V_5 = F_3 ( V_7 ) ;
F_4 ( V_3 ) ;
V_4 += F_5 ( V_5 ) * V_8 ;
V_4 += F_6 ( V_5 ) ;
return V_4 ;
}
static void
F_7 ( enum V_9 V_10 , struct V_11 * V_12 )
{
switch ( V_10 ) {
case V_13 :
V_6 += V_8 * F_5 ( F_3 ( V_14 ) ) ;
F_8 ( V_15 , ( V_8 - 1 ) | V_16
| V_17 ) ;
break;
case V_18 :
F_9 () ;
case V_19 :
case V_20 :
F_8 ( V_15 , ( V_8 - 1 ) | V_16 ) ;
break;
case V_21 :
break;
}
}
static T_3 F_10 ( int V_22 , void * V_23 )
{
F_11 ( ! F_12 () ) ;
if ( ( V_24 . V_10 == V_13 )
&& ( F_3 ( V_25 ) & V_26 ) ) {
unsigned V_27 ;
V_27 = F_5 ( F_3 ( V_14 ) ) ;
do {
V_6 += V_8 ;
V_24 . V_28 ( & V_24 ) ;
V_27 -- ;
} while ( V_27 );
return V_29 ;
}
return V_30 ;
}
static void F_13 ( void )
{
F_8 ( V_15 , 0 ) ;
while ( F_6 ( F_3 ( V_14 ) ) != 0 )
F_14 () ;
F_8 ( V_15 , ( V_8 - 1 ) | V_16 ) ;
}
static void T_4 F_15 ( void )
{
unsigned long V_31 ;
unsigned V_32 ;
V_31 = F_16 ( F_17 ( NULL , L_1 ) ) / 16 ;
V_8 = ( V_31 + V_33 / 2 ) / V_33 ;
F_18 ( ( ( V_8 - 1 ) & ~ V_34 ) != 0 ) ;
F_13 () ;
V_32 = 12 + F_19 ( V_8 ) ;
V_35 . V_36 = F_20 ( V_32 ) ;
F_21 ( & V_35 , V_31 ) ;
F_22 ( V_37 , & V_38 ) ;
V_24 . V_39 = F_23 ( V_31 , V_40 , V_24 . V_41 ) ;
V_24 . V_42 = F_24 ( 0 ) ;
F_25 ( & V_24 ) ;
}
static void F_26 ( void )
{
F_8 ( V_15 , 0 ) ;
}
