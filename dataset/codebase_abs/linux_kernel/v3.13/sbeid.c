char *
F_1 ( T_1 * V_1 )
{
char * V_2 = NULL ;
switch ( V_1 -> V_3 )
{
case F_2 ( V_4 , V_5 ) :
V_2 = L_1 ;
break;
case F_2 ( V_4 , V_6 ) :
V_2 = L_2 ;
break;
case F_2 ( V_4 , V_7 ) :
case F_2 ( V_4 , V_8 ) :
V_2 = L_3 ;
break;
case F_2 ( V_4 , V_9 ) :
case F_2 ( V_4 , V_10 ) :
V_2 = L_4 ;
break;
case F_2 ( V_4 , V_11 ) :
case F_2 ( V_4 , V_12 ) :
V_2 = L_5 ;
break;
case F_2 ( V_4 , V_13 ) :
V_2 = L_6 ;
break;
case F_2 ( V_4 , V_14 ) :
V_2 = L_7 ;
break;
case F_2 ( V_4 , V_15 ) :
V_2 = L_8 ;
break;
default:
V_2 = L_9 ;
break;
}
return V_2 ;
}
void
F_3 ( T_1 * V_1 )
{
switch ( V_1 -> V_3 )
{
case F_2 ( V_4 , V_5 ) :
V_1 -> V_16 = V_17 ;
break;
case F_2 ( V_4 , V_6 ) :
V_1 -> V_16 = V_18 ;
break;
case F_2 ( V_4 , V_7 ) :
case F_2 ( V_4 , V_8 ) :
switch ( V_1 -> V_19 )
{
default:
case 4 :
V_1 -> V_16 = V_20 ;
break;
case 2 :
V_1 -> V_16 = V_21 ;
V_1 -> V_3 = F_2 ( V_4 , V_9 ) ;
break;
case 1 :
V_1 -> V_16 = V_22 ;
V_1 -> V_3 = F_2 ( V_4 , V_11 ) ;
break;
}
break;
case F_2 ( V_4 , V_9 ) :
case F_2 ( V_4 , V_10 ) :
V_1 -> V_16 = V_21 ;
break;
case F_2 ( V_4 , V_11 ) :
case F_2 ( V_4 , V_12 ) :
V_1 -> V_16 = V_22 ;
break;
#ifdef F_4
case 0 :
V_1 -> V_3 = F_2 ( V_4 , V_13 ) ;
#endif
case F_2 ( V_4 , V_13 ) :
switch ( V_1 -> V_19 )
{
default:
case 4 :
V_1 -> V_16 = V_23 ;
break;
case 2 :
V_1 -> V_16 = V_24 ;
V_1 -> V_3 = F_2 ( V_4 , V_14 ) ;
break;
case 1 :
V_1 -> V_16 = V_25 ;
V_1 -> V_3 = F_2 ( V_4 , V_15 ) ;
break;
}
break;
case F_2 ( V_4 , V_14 ) :
V_1 -> V_16 = V_24 ;
break;
case F_2 ( V_4 , V_15 ) :
V_1 -> V_16 = V_25 ;
break;
default:
V_1 -> V_16 = V_20 ;
break;
}
}
void
F_5 ( T_1 * V_1 )
{
switch ( V_1 -> V_16 )
{
case V_26 :
V_1 -> V_3 = F_2 ( V_4 , V_27 ) ;
break;
case V_28 :
V_1 -> V_3 = F_2 ( V_4 , V_29 ) ;
break;
case V_17 :
V_1 -> V_3 = F_2 ( V_4 , V_5 ) ;
break;
case V_18 :
V_1 -> V_3 = F_2 ( V_4 , V_6 ) ;
break;
case V_20 :
V_1 -> V_3 = F_2 ( V_4 , V_7 ) ;
break;
case V_21 :
V_1 -> V_3 = F_2 ( V_4 , V_9 ) ;
break;
case V_22 :
V_1 -> V_3 = F_2 ( V_4 , V_11 ) ;
break;
case V_23 :
V_1 -> V_3 = F_2 ( V_4 , V_13 ) ;
break;
case V_24 :
V_1 -> V_3 = F_2 ( V_4 , V_14 ) ;
break;
case V_25 :
V_1 -> V_3 = F_2 ( V_4 , V_15 ) ;
break;
default:
V_1 -> V_3 = F_2 ( V_4 , V_13 ) ;
break;
}
}
