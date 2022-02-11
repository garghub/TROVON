static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
switch ( V_2 -> V_4 ) {
case 0 :
V_3 = F_2 ( 0 ) ;
break;
case 1 :
V_3 = F_3 ( 0 ) ;
break;
case 2 :
F_4 ( F_5 ( 4 ) , F_6 ( 5 ) ) ;
F_4 ( F_5 ( 5 ) , F_6 ( 5 ) ) ;
F_4 ( F_5 ( 7 ) , F_6 ( 5 ) ) ;
F_7 ( F_8 ( 6 ) , 4 , F_6 ( 5 ) ) ;
return 0 ;
default:
F_9 ( V_5 L_1 ,
V_2 -> V_4 ) ;
return - V_6 ;
}
F_7 ( V_3 , 5 , F_6 ( 3 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
switch ( V_2 -> V_4 ) {
case 0 :
V_3 = F_2 ( 0 ) ;
break;
case 1 :
V_3 = F_3 ( 0 ) ;
break;
default:
F_9 ( V_5 L_2 ,
V_2 -> V_4 ) ;
return - V_6 ;
}
F_7 ( V_3 , 5 , F_6 ( 2 ) ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( 0 ) , 5 , F_6 ( 4 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_7 ( F_3 ( 0 ) , 5 , F_6 ( 4 ) ) ;
}
void T_1 F_13 ( int V_7 )
{
if ( V_7 == V_8 )
V_9 . V_10 = F_11 ;
else
V_9 . V_10 = F_12 ;
}
