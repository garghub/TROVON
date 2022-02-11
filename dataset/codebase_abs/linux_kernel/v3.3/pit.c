static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
switch ( V_2 ) {
case V_5 :
F_2 ( V_6 , F_3 ( V_7 ) ) ;
F_2 ( V_8 , F_3 ( V_9 ) ) ;
F_2 ( V_10 | V_11 | \
V_12 | V_13 | \
V_14 , F_3 ( V_7 ) ) ;
break;
case V_15 :
case V_16 :
F_2 ( V_6 , F_3 ( V_7 ) ) ;
break;
case V_17 :
F_2 ( V_6 , F_3 ( V_7 ) ) ;
F_2 ( V_10 | V_11 | \
V_12 | V_14 , \
F_3 ( V_7 ) ) ;
break;
case V_18 :
break;
}
}
static int F_4 ( unsigned long V_19 ,
struct V_3 * V_4 )
{
F_2 ( V_19 , F_3 ( V_9 ) ) ;
return 0 ;
}
static T_1 F_5 ( int V_20 , void * V_21 )
{
struct V_3 * V_4 = & V_22 ;
T_2 V_23 ;
V_23 = F_6 ( F_3 ( V_7 ) ) ;
F_2 ( V_23 | V_24 , F_3 ( V_7 ) ) ;
V_25 += V_8 ;
V_4 -> V_26 ( V_4 ) ;
return V_27 ;
}
static T_3 F_7 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
T_4 V_31 ;
T_2 V_32 ;
F_8 ( V_30 ) ;
V_32 = F_6 ( F_3 ( V_33 ) ) ;
V_31 = V_25 ;
F_9 ( V_30 ) ;
return V_31 + V_8 - V_32 ;
}
void F_10 ( void )
{
V_22 . V_34 = F_11 ( F_12 () ) ;
V_22 . V_35 = F_13 ( V_36 , V_37 , 32 ) ;
V_22 . V_38 =
F_14 ( 0xFFFF , & V_22 ) ;
V_22 . V_39 =
F_14 ( 0x3f , & V_22 ) ;
F_15 ( & V_22 ) ;
F_16 ( V_40 + V_41 , & V_42 ) ;
F_17 ( & V_43 , V_36 ) ;
}
