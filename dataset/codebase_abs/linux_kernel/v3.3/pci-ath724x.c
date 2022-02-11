static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
unsigned long V_7 , V_8 , V_9 , V_10 ;
if ( V_3 )
return V_11 ;
if ( V_4 & ( V_5 - 1 ) )
return V_12 ;
F_2 ( & V_13 , V_7 ) ;
switch ( V_5 ) {
case 1 :
V_8 = V_4 & ~ 3 ;
V_10 = 0xff000000 >> ( ( V_4 % 4 ) * 8 ) ;
V_9 = F_3 ( V_14 + V_8 ) ;
V_9 = V_9 & ~ V_10 ;
* V_6 = ( V_9 >> ( ( 4 - ( V_4 % 4 ) ) * 8 ) ) ;
break;
case 2 :
V_8 = V_4 & ~ 3 ;
V_10 = 0xffff0000 >> ( ( V_4 % 4 ) * 8 ) ;
V_9 = F_3 ( V_14 + V_8 ) ;
V_9 = V_9 & ~ V_10 ;
* V_6 = ( V_9 >> ( ( 4 - ( V_4 % 4 ) ) * 8 ) ) ;
break;
case 4 :
* V_6 = F_3 ( V_14 + V_4 ) ;
break;
default:
F_4 ( & V_13 , V_7 ) ;
return V_12 ;
}
F_4 ( & V_13 , V_7 ) ;
return V_15 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
unsigned long V_7 , V_9 , V_8 , V_10 ;
if ( V_3 )
return V_11 ;
if ( V_4 & ( V_5 - 1 ) )
return V_12 ;
F_2 ( & V_13 , V_7 ) ;
switch ( V_5 ) {
case 1 :
V_8 = ( V_14 + V_4 ) & ~ 3 ;
V_10 = 0xff000000 >> ( ( V_4 % 4 ) * 8 ) ;
V_9 = F_3 ( V_8 ) ;
V_9 = V_9 & ~ V_10 ;
V_9 |= ( V_6 << ( ( 4 - ( V_4 % 4 ) ) * 8 ) ) & V_10 ;
F_6 ( V_8 , V_9 ) ;
break;
case 2 :
V_8 = ( V_14 + V_4 ) & ~ 3 ;
V_10 = 0xffff0000 >> ( ( V_4 % 4 ) * 8 ) ;
V_9 = F_3 ( V_8 ) ;
V_9 = V_9 & ~ V_10 ;
V_9 |= ( V_6 << ( ( 4 - ( V_4 % 4 ) ) * 8 ) ) & V_10 ;
F_6 ( V_8 , V_9 ) ;
break;
case 4 :
F_6 ( ( V_14 + V_4 ) , V_6 ) ;
break;
default:
F_4 ( & V_13 , V_7 ) ;
return V_12 ;
}
F_4 ( & V_13 , V_7 ) ;
return V_15 ;
}
void F_7 ( struct V_16 * V_17 , int V_5 )
{
V_18 = V_17 ;
V_19 = V_5 ;
}
int T_2 F_8 ( const struct V_20 * V_21 , T_3 V_22 , T_3 V_23 )
{
unsigned int V_3 = V_21 -> V_3 ;
int V_24 = - 1 ;
if ( V_3 > V_19 - 1 )
return V_24 ;
V_24 = V_18 [ V_3 ] . V_24 ;
return V_24 ;
}
int F_9 ( struct V_20 * V_21 )
{
unsigned int V_3 = V_21 -> V_3 ;
if ( V_3 > V_19 - 1 )
return V_11 ;
V_21 -> V_21 . V_25 = V_18 [ V_3 ] . V_26 ;
return V_15 ;
}
static int T_2 F_10 ( void )
{
F_11 ( & V_27 ) ;
return V_15 ;
}
