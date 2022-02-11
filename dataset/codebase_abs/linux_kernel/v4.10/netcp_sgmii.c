static void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static T_2 F_3 ( void T_1 * V_1 , int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static void F_5 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( ( F_4 ( V_1 + V_2 ) | V_3 ) , V_1 + V_2 ) ;
}
int F_6 ( void T_1 * V_4 , int V_5 )
{
F_5 ( V_4 , F_7 ( V_5 ) ,
V_6 ) ;
while ( ( F_3 ( V_4 , F_7 ( V_5 ) ) &
V_6 ) != 0x0 )
;
return 0 ;
}
bool F_8 ( void T_1 * V_4 , int V_5 , bool V_7 )
{
T_2 V_2 ;
bool V_8 ;
V_2 = F_3 ( V_4 , F_7 ( V_5 ) ) ;
V_8 = ( V_2 & V_9 ) != 0x0 ;
if ( V_7 )
V_2 |= V_9 ;
else
V_2 &= ~ V_9 ;
F_1 ( V_4 , F_7 ( V_5 ) , V_2 ) ;
F_9 () ;
return V_8 ;
}
int F_10 ( void T_1 * V_4 , int V_5 )
{
T_2 V_10 = 0 , V_11 = 0 ;
V_10 = F_3 ( V_4 , F_11 ( V_5 ) ) ;
if ( ( V_10 & V_12 ) != 0 )
V_11 = 1 ;
return V_11 ;
}
int F_12 ( void T_1 * V_4 , int V_5 , T_2 V_13 )
{
unsigned int V_14 , V_10 , V_15 ;
T_2 V_16 ;
T_2 V_17 ;
switch ( V_13 ) {
case V_18 :
V_16 = 0x9801 ;
V_17 = 0x21 ;
break;
case V_19 :
case V_20 :
V_16 = 1 ;
V_17 = 1 ;
break;
case V_21 :
V_16 = 0x9801 ;
V_17 = 0x20 ;
break;
case V_22 :
V_16 = 0x20 ;
V_17 = 0x1 ;
break;
default:
F_13 ( 1 , L_1 , V_13 ) ;
return - V_23 ;
}
F_1 ( V_4 , F_14 ( V_5 ) , 0 ) ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
F_15 ( 1000 , 2000 ) ;
V_10 = F_3 ( V_4 , F_11 ( V_5 ) ) ;
if ( ( V_10 & V_24 ) != 0 )
break;
}
if ( ( V_10 & V_24 ) == 0 )
F_16 ( L_2 ) ;
F_1 ( V_4 , F_17 ( V_5 ) , V_16 ) ;
F_1 ( V_4 , F_14 ( V_5 ) , V_17 ) ;
V_15 = V_12 ;
if ( V_17 & V_25 )
V_15 |= V_26 ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
F_15 ( 200 , 500 ) ;
V_10 = F_3 ( V_4 , F_11 ( V_5 ) ) ;
if ( ( V_10 & V_15 ) == V_15 )
break;
}
return 0 ;
}
