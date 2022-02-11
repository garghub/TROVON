static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static void F_3 ( unsigned int V_1 , unsigned int V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 |= V_3 ;
F_4 ( V_4 , V_1 + V_2 ) ;
F_2 ( V_1 + V_2 ) ;
}
static void F_5 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 &= ~ V_3 ;
F_4 ( V_4 , V_1 + V_2 ) ;
F_2 ( V_1 + V_2 ) ;
}
static void F_6 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
F_2 ( V_1 + V_2 ) ;
}
int F_7 ( unsigned int V_1 )
{
unsigned long V_5 ;
if ( F_8 () ) {
F_3 ( V_1 , V_6 , ( 1 << V_7 )
| ( 1 << V_8 ) ) ;
}
F_3 ( V_1 , V_6 , 1 << V_9 ) ;
F_3 ( V_1 , V_6 , 1 << V_10 ) ;
F_5 ( V_1 , V_11 , V_12
| V_13 | V_14
| V_15 | V_16
| V_17 | V_18 ) ;
F_3 ( V_1 , V_11 , ( 0xee << V_19 )
| ( 0xb << V_20 )
| ( 3 << V_21 )
| ( 3 << V_22 )
| ( 3 << V_23 )
| ( 1 << V_24 ) | ( 3 << V_25 ) ) ;
F_5 ( V_1 , V_26 , V_27
| V_28
| V_29 | V_30
| V_31 | V_32 ) ;
F_3 ( V_1 , V_26 , ( 3 << V_33 )
| ( 4 << V_34 )
| ( 4 << V_35 )
| ( 8 << V_36 )
| ( 3 << V_37 ) ) ;
F_5 ( V_1 , V_38 , V_39
| V_40 ) ;
if ( F_9 () )
F_3 ( V_1 , V_38 , ( 7 << V_41 )
| ( 2 << V_42 ) ) ;
else
F_3 ( V_1 , V_38 , ( 0x7 << V_41 )
| ( 2 << V_42 ) ) ;
if ( F_9 () )
F_6 ( V_1 , V_43 , 0x4bf ) ;
V_5 = V_44 + 100 ;
while ( ( F_1 ( V_1 , V_11 ) & V_45 ) == 0 ) {
if ( F_10 ( V_44 , V_5 ) )
return - V_46 ;
F_11 () ;
}
F_12 ( 200 ) ;
F_3 ( V_1 , V_11 , V_47 ) ;
F_12 ( 40 ) ;
F_5 ( V_1 , V_11 , V_47 ) ;
F_12 ( 200 ) ;
F_3 ( V_1 , V_26 , V_48 ) ;
F_12 ( 40 ) ;
F_5 ( V_1 , V_26 , V_48 ) ;
F_12 ( 200 ) ;
V_5 = V_44 + 100 ;
while ( ( F_1 ( V_1 , V_11 ) & V_45 ) == 0 ) {
if ( F_10 ( V_44 , V_5 ) )
return - V_46 ;
F_11 () ;
}
if ( F_9 () ) {
F_3 ( V_1 , V_49 , 1 << 5 ) ;
F_6 ( V_1 , V_50 , 1 ) ;
}
return 0 ;
}
int F_7 ( unsigned int V_1 )
{
return 0 ;
}
