static void F_1 ( T_1 V_1 , T_2 V_2 )
{
void T_3 * V_3 = F_2 ( V_4 ) + V_1 ;
F_3 ( V_2 , V_3 ) ;
F_4 () ;
F_5 ( V_3 ) ;
}
T_2 F_6 ( unsigned int V_5 )
{
T_1 V_1 = V_6 [ V_5 ] ;
void T_3 * V_3 = F_2 ( V_4 ) + V_1 ;
return F_7 ( V_3 ) ;
}
void F_8 ( unsigned int V_5 , T_2 V_2 )
{
return F_1 ( V_6 [ V_5 ] , V_2 ) ;
}
void F_9 ( unsigned int V_5 , T_2 V_2 )
{
return F_1 ( V_7 [ V_5 ] , V_2 ) ;
}
void F_10 ( unsigned int V_5 )
{
unsigned int V_8 ;
int V_9 ;
V_8 = F_6 ( V_5 ) ;
switch ( V_10 ) {
case V_11 :
V_8 &= ~ V_12 ;
V_8 &= ~ V_13 ;
V_8 |= V_14 << V_5 ;
break;
case V_15 :
case V_16 :
case V_17 :
V_8 &= ~ V_18 ;
V_8 &= ~ V_19 ;
V_8 |= V_20 << V_5 ;
break;
}
V_8 |= V_21 ;
V_8 |= V_22 ;
V_8 |= V_23 ;
F_8 ( V_5 , V_8 ) ;
for ( V_9 = 0 ; V_9 < F_11 () ; V_9 ++ ) {
if ( V_9 == V_5 )
continue;
V_8 = F_6 ( V_9 ) ;
V_8 |= V_22 ;
V_8 |= V_21 ;
F_8 ( V_9 , V_8 ) ;
}
}
void F_12 ( unsigned int V_5 )
{
unsigned int V_8 ;
V_8 = F_6 ( V_5 ) ;
switch ( V_10 ) {
case V_11 :
V_8 &= ~ V_12 ;
V_8 &= ~ V_13 ;
break;
case V_15 :
case V_16 :
case V_17 :
V_8 &= ~ V_18 ;
V_8 &= ~ V_19 ;
break;
}
V_8 &= ~ V_23 ;
V_8 |= V_21 ;
V_8 |= V_22 ;
F_8 ( V_5 , V_8 ) ;
}
