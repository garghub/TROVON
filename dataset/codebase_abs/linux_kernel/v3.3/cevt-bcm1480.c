static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = F_2 () ;
void T_1 * V_6 , * V_7 ;
V_6 = F_3 ( F_4 ( V_5 , V_8 ) ) ;
V_7 = F_3 ( F_4 ( V_5 , V_9 ) ) ;
switch ( V_2 ) {
case V_10 :
F_5 ( 0 , V_6 ) ;
F_5 ( ( V_11 / V_12 ) - 1 , V_7 ) ;
F_5 ( V_13 | V_14 ,
V_6 ) ;
break;
case V_15 :
case V_16 :
F_5 ( 0 , V_6 ) ;
break;
case V_17 :
case V_18 :
;
}
}
static int F_6 ( unsigned long V_19 , struct V_3 * V_20 )
{
unsigned int V_5 = F_2 () ;
void T_1 * V_6 , * V_7 ;
V_6 = F_3 ( F_4 ( V_5 , V_8 ) ) ;
V_7 = F_3 ( F_4 ( V_5 , V_9 ) ) ;
F_5 ( 0 , V_6 ) ;
F_5 ( V_19 - 1 , V_7 ) ;
F_5 ( V_13 , V_6 ) ;
return 0 ;
}
static T_2 F_7 ( int V_21 , void * V_22 )
{
unsigned int V_5 = F_2 () ;
struct V_3 * V_20 = V_22 ;
void T_1 * V_6 ;
unsigned long V_23 ;
if ( V_20 -> V_2 == V_10 )
V_23 = V_13 | V_14 ;
else
V_23 = 0 ;
V_6 = F_3 ( F_4 ( V_5 , V_8 ) ) ;
F_8 ( V_23 , V_6 ) ;
V_20 -> V_24 ( V_20 ) ;
return V_25 ;
}
void T_3 F_9 ( void )
{
unsigned int V_5 = F_2 () ;
unsigned int V_21 = V_26 + V_5 ;
struct V_27 * V_28 = & F_10 ( V_29 , V_5 ) ;
struct V_3 * V_20 = & F_10 ( V_30 , V_5 ) ;
unsigned char * V_31 = F_10 ( V_32 , V_5 ) ;
F_11 ( V_5 > 3 ) ;
sprintf ( V_31 , L_1 , V_5 ) ;
V_20 -> V_31 = V_31 ;
V_20 -> V_33 = V_34 |
V_35 ;
F_12 ( V_20 , V_11 ) ;
V_20 -> V_36 = F_13 ( 0x7fffff , V_20 ) ;
V_20 -> V_37 = F_13 ( 2 , V_20 ) ;
V_20 -> V_38 = 200 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_39 = F_14 ( V_5 ) ;
V_20 -> V_40 = F_6 ;
V_20 -> V_41 = F_1 ;
F_15 ( V_20 ) ;
F_16 ( V_5 , V_21 ) ;
F_5 ( V_42 ,
F_3 ( F_17 ( V_5 ,
V_43 ) + ( V_21 << 3 ) ) ) ;
F_18 ( V_5 , V_21 ) ;
V_28 -> V_44 = F_7 ;
V_28 -> V_45 = V_46 | V_47 ;
V_28 -> V_31 = V_31 ;
V_28 -> V_22 = V_20 ;
F_19 ( V_21 , F_14 ( V_5 ) ) ;
F_20 ( V_21 , V_28 ) ;
}
