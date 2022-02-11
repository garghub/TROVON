int F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
T_1 V_5 = V_2 -> V_6 ;
T_1 V_7 = V_2 -> V_8 ;
if ( ! V_3 || ( V_3 & ( V_9 - 1 ) ) )
return 0 ;
if ( ! V_7 || ( V_7 & ( V_9 - 1 ) ) )
return 0 ;
if ( V_7 < V_3 || V_7 % V_3 )
return 0 ;
if ( ! V_5 )
return 0 ;
return 1 ;
}
void F_2 ( struct V_1 * V_10 ,
struct V_11 * V_12 )
{
V_10 -> V_4 = F_3 ( V_12 -> V_13 ) ;
V_10 -> V_6 = F_3 ( V_12 -> V_14 ) ;
V_10 -> V_8 = F_3 ( V_12 -> V_15 ) ;
V_10 -> V_16 = F_3 ( V_12 -> V_17 ) ;
if ( V_10 -> V_16 == 0 && V_10 -> V_4 == 0 &&
V_10 -> V_6 == 0 && V_10 -> V_8 == 0 )
V_10 -> V_16 = - 1 ;
}
void F_4 ( struct V_1 * V_10 ,
struct V_11 * V_12 )
{
V_12 -> V_13 = F_5 ( V_10 -> V_4 ) ;
V_12 -> V_14 = F_5 ( V_10 -> V_6 ) ;
V_12 -> V_15 = F_5 ( V_10 -> V_8 ) ;
if ( V_10 -> V_16 >= 0 )
V_12 -> V_17 = F_5 ( V_10 -> V_16 ) ;
else
V_12 -> V_17 = 0 ;
}
int F_6 ( int V_18 )
{
int V_19 ;
#ifdef F_7
if ( ( V_18 & F_7 ) == F_7 )
return V_20 ;
#endif
switch ( V_18 & V_21 ) {
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
case V_26 :
case V_21 :
V_19 = V_27 ;
break;
}
#ifdef F_8
if ( V_18 & F_8 )
V_19 |= V_28 ;
#endif
return V_19 ;
}
int F_9 ( int V_19 )
{
int V_29 = V_30 ;
if ( V_19 & V_25 )
V_29 |= V_31 |
V_32 | V_33 ;
if ( V_19 & V_23 )
V_29 |= V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 | V_40 ;
if ( V_19 & V_28 )
V_29 |= V_41 ;
return V_29 ;
}
