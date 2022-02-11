int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 ;
int V_4 = 0 , V_5 ;
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_2 == NULL )
V_3 = F_2 ( V_1 ) ;
else
V_3 = V_2 ;
if ( V_3 == NULL ) return ( 0 ) ;
switch ( V_3 -> type )
{
case V_6 :
V_4 = V_7 | V_8 ;
V_4 |= V_9 ;
break;
case V_10 :
V_4 = V_11 | V_8 ;
break;
case V_12 :
V_4 = V_13 | V_8 | V_14 ;
break;
case V_15 :
V_4 = V_16 | V_14 ;
break;
default:
break;
}
V_5 = F_3 ( V_1 ) ;
switch ( V_5 )
{
case V_6 :
V_4 |= V_17 ;
break;
case V_10 :
V_4 |= V_18 ;
break;
case V_12 :
V_4 |= V_19 ;
break;
default:
break;
}
if ( F_4 ( V_3 ) <= 1024 / 8 )
V_4 |= V_20 ;
if( V_2 == NULL ) F_5 ( V_3 ) ;
return ( V_4 ) ;
}
