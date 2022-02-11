void F_1 ( T_1 V_1 )
{
unsigned int V_2 ;
if ( F_2 () == V_3 ) {
V_2 = F_3 ( V_4 ) & ~ V_5 ;
V_2 |= ( V_1 << V_6 ) ;
F_4 ( V_4 , V_2 ) ;
} else {
V_2 = F_3 ( V_7 ) ;
V_2 = ( V_2 & ~ V_8 ) | V_1 ;
F_4 ( V_7 , V_2 ) ;
}
}
static unsigned int F_5 ( void )
{
if ( F_2 () == V_3 )
return 0 ;
return F_3 ( V_9 ) & V_10 ;
}
void F_6 ( unsigned int V_11 )
{
unsigned int V_12 = 0 ;
V_12 = F_3 ( V_9 ) & ~ V_10 ;
if ( F_2 () == V_3 )
return;
switch ( V_11 ) {
case V_13 :
V_12 |= V_13 ;
break;
case V_14 :
V_12 |= V_14 ;
break;
case V_15 :
V_12 |= V_15 ;
break;
default:
break;
}
if ( V_11 == V_15 ) {
V_12 &= ~ V_16 ;
#ifdef F_7
V_12 &= ~ V_17 ;
#endif
} else {
V_12 |= V_16 ;
#ifdef F_7
V_12 |= V_17 ;
#endif
}
F_4 ( V_9 , V_12 ) ;
}
void F_8 ( unsigned int V_18 )
{
unsigned int V_19 ;
unsigned int V_20 ;
V_20 = F_5 () ;
switch ( V_20 ) {
case V_13 :
V_19 = V_21 ;
break;
case V_14 :
V_19 = V_22 ;
break;
default:
V_19 = V_21 ;
break;
}
F_4 ( V_19 , V_18 ) ;
}
void F_9 ( unsigned int V_23 )
{
T_2 V_18 ;
V_18 = F_3 ( V_24 ) ;
if ( V_23 )
V_18 |= ( V_25 | V_26 ) ;
else
V_18 &= ~ ( V_25 | V_26 ) ;
F_8 ( V_18 ) ;
}
void F_10 ( unsigned int V_23 )
{
T_2 V_18 ;
V_18 = F_3 ( V_24 ) ;
if ( V_23 )
V_18 |= V_27 ;
else
V_18 &= ~ V_27 ;
F_8 ( V_18 ) ;
}
void F_11 ( unsigned int V_23 )
{
T_2 V_18 ;
V_18 = F_3 ( V_24 ) ;
if ( V_23 )
V_18 |= V_28 ;
else
V_18 &= ~ V_28 ;
F_8 ( V_18 ) ;
}
void F_12 ( unsigned int V_23 )
{
T_2 V_18 ;
V_18 = F_3 ( V_24 ) ;
if ( V_23 )
V_18 |= V_29 ;
else
V_18 &= ~ V_29 ;
F_8 ( V_18 ) ;
}
