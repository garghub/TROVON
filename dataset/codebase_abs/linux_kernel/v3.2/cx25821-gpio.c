void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 = V_3 ;
T_1 V_6 = V_7 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
if ( V_3 >= 47 )
return;
if ( V_3 > 31 ) {
V_5 = V_3 - 31 ;
V_6 = V_10 ;
}
V_8 = F_2 ( V_6 ) ;
if ( V_4 == 1 )
V_9 = V_8 | F_3 ( V_5 ) ;
else
V_9 = V_8 & F_4 ( V_5 ) ;
F_5 ( V_6 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 = V_3 ;
T_1 V_11 = V_12 ;
T_1 V_9 = 0 ;
if ( V_3 >= 47 )
return;
F_1 ( V_2 , V_3 , 0 ) ;
if ( V_3 > 31 ) {
V_5 = V_3 - 31 ;
V_11 = V_13 ;
}
V_9 = F_2 ( V_11 ) ;
if ( V_4 == 0 )
V_9 &= F_4 ( V_5 ) ;
else
V_9 |= F_3 ( V_5 ) ;
F_5 ( V_11 , V_9 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
switch ( V_2 -> V_14 ) {
case V_15 :
default:
F_6 ( V_2 , 5 , 1 ) ;
F_8 ( 20 ) ;
break;
}
}
