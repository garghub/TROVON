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
F_5 ( V_4 , F_7 ( V_5 ) , 0x1 ) ;
while ( F_3 ( V_4 , F_7 ( V_5 ) ) != 0x0 )
;
return 0 ;
}
int F_8 ( void T_1 * V_4 , int V_5 )
{
T_2 V_6 = 0 , V_7 = 0 ;
V_6 = F_3 ( V_4 , F_9 ( V_5 ) ) ;
if ( ( V_6 & V_8 ) != 0 )
V_7 = 1 ;
return V_7 ;
}
int F_10 ( void T_1 * V_4 , int V_5 , T_2 V_9 )
{
unsigned int V_10 , V_6 , V_11 ;
T_2 V_12 ;
T_2 V_13 ;
switch ( V_9 ) {
case V_14 :
V_12 = 0x9801 ;
V_13 = 0x21 ;
break;
case V_15 :
case V_16 :
V_12 = 1 ;
V_13 = 1 ;
break;
case V_17 :
V_12 = 0x9801 ;
V_13 = 0x20 ;
break;
case V_18 :
V_12 = 0x20 ;
V_13 = 0x1 ;
break;
default:
F_11 ( 1 , L_1 , V_9 ) ;
return - V_19 ;
}
F_1 ( V_4 , F_12 ( V_5 ) , 0 ) ;
for ( V_10 = 0 ; V_10 < 1000 ; V_10 ++ ) {
F_13 ( 1000 , 2000 ) ;
V_6 = F_3 ( V_4 , F_9 ( V_5 ) ) ;
if ( ( V_6 & V_20 ) != 0 )
break;
}
if ( ( V_6 & V_20 ) == 0 )
F_14 ( L_2 ) ;
F_1 ( V_4 , F_15 ( V_5 ) , V_12 ) ;
F_1 ( V_4 , F_12 ( V_5 ) , V_13 ) ;
V_11 = V_8 ;
if ( V_13 & V_21 )
V_11 |= V_22 ;
for ( V_10 = 0 ; V_10 < 1000 ; V_10 ++ ) {
F_13 ( 200 , 500 ) ;
V_6 = F_3 ( V_4 , F_9 ( V_5 ) ) ;
if ( ( V_6 & V_11 ) == V_11 )
break;
}
return 0 ;
}
