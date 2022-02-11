static T_1 T_2 F_1 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static int
F_3 ( unsigned long V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
F_4 ( V_7 , V_1 + V_8 ) ;
F_4 ( V_3 , V_1 + V_9 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
V_6 = ( ( V_6 & ~ V_11 ) | V_12 |
F_5 ( V_13 ) ) ;
F_4 ( V_6 , V_1 + V_10 ) ;
return 0 ;
}
static void
F_6 ( enum V_14 V_15 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
if ( V_15 == V_16 ) {
F_4 ( V_17 - 1 , V_1 + V_18 ) ;
F_4 ( V_17 - 1 , V_1 + V_9 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( ( V_6 | V_12 | V_11 |
F_5 ( V_13 ) ) ,
V_1 + V_10 ) ;
} else {
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( V_6 & ~ V_12 , V_1 + V_10 ) ;
F_4 ( V_7 , V_1 + V_8 ) ;
}
}
static T_3 F_7 ( int V_19 , void * V_20 )
{
F_4 ( V_7 , V_1 + V_8 ) ;
V_21 . V_22 ( & V_21 ) ;
return V_23 ;
}
void T_4 F_8 ( void )
{
T_1 V_6 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
int V_27 ;
V_25 = F_9 ( NULL , NULL , L_1 ) ;
V_1 = F_10 ( V_25 , 0 ) ;
F_11 ( ! V_1 ) ;
if ( F_12 ( V_25 , L_2 , NULL ) ) {
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( V_6 | V_28 | V_29 ,
V_1 + V_10 ) ;
V_26 = 25000000 ;
} else {
T_1 V_30 = 0 ;
V_27 = F_13 ( V_25 , L_3 , & V_30 ) ;
F_11 ( ! V_30 || V_27 < 0 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( V_6 & ~ ( V_28 | V_29 ) ,
V_1 + V_10 ) ;
V_26 = V_30 / V_31 ;
}
V_32 = F_14 ( V_25 , 1 ) ;
V_17 = ( V_26 + V_33 / 2 ) / V_33 ;
F_15 ( F_1 , 32 , V_26 ) ;
F_4 ( 0xffffffff , V_1 + V_2 ) ;
F_4 ( 0xffffffff , V_1 + V_34 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( ( V_6 | V_35 | V_36 |
F_16 ( V_13 ) ) , V_1 + V_10 ) ;
F_17 ( V_1 + V_2 ,
L_4 ,
V_26 , 300 , 32 , V_37 ) ;
F_18 ( V_32 , & V_38 ) ;
V_21 . V_39 = F_19 ( 0 ) ;
F_20 ( & V_21 ,
V_26 , 1 , 0xfffffffe ) ;
}
