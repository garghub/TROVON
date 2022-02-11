static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 ) ;
if ( F_3 ( V_2 , & V_3 ) < 0 ) {
F_4 ( V_2 -> V_5 -> V_6 ,
L_1 ) ;
V_2 -> V_7 = FALSE ;
return - V_8 ;
}
V_2 -> V_7 = ( V_3 == V_9 ) ;
return V_2 -> V_7 ? 0 : - V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 , char V_11 )
{
if ( V_2 -> V_12 )
V_10 |= V_13 ;
else
V_10 &= ~ V_13 ;
F_6 ( V_2 -> V_5 -> V_6 , L_2 , V_10 ) ;
V_10 = F_7 ( V_10 ) ;
if ( V_10 != V_2 -> V_14 -> V_15 || V_11 ) {
if ( F_8 ( V_2 ) )
return - V_8 ;
V_2 -> V_14 -> V_15 = V_10 ;
F_9 ( V_2 ) ;
return F_2 ( V_2 , V_16 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_17 )
{
F_6 ( V_2 -> V_5 -> V_6 , L_3 , V_17 ) ;
V_2 -> V_12 = V_17 ;
return F_11 ( V_2 , V_2 -> V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_19 )
{
T_2 V_20 ;
int V_21 , V_22 , V_23 ;
if ( V_2 -> V_24 )
return - V_8 ;
if ( F_13 ( V_2 -> V_25 ) )
return - V_26 ;
if ( F_13 ( ! ( V_2 -> V_27 & ( 1 << V_19 ) ) ) )
return - V_28 ;
V_20 = V_2 -> V_29 ;
V_21 = F_14 ( V_2 , V_19 ) ;
if ( V_21 >= 0 && V_20 != V_19 &&
( V_20 == V_30 || V_19 == V_30 ) ) {
F_15 ( & V_2 -> V_31 ) ;
for ( V_23 = 0 ; V_23 < F_16 ( V_2 ) ; V_23 ++ )
for ( V_22 = 0 ; V_22 < F_17 ( V_2 ) ; V_22 ++ )
F_18 ( V_2 , V_23 , V_22 ,
V_2 -> V_32 [ V_23 ] [ V_22 ] ) ;
#ifdef F_19
for ( V_22 = 0 ; V_22 < F_17 ( V_2 ) ; V_22 ++ )
F_20 ( V_2 , V_22 , V_2 -> V_33 [ V_22 ] ) ;
F_21 ( V_2 ) ;
#endif
for ( V_23 = 0 ; V_23 < F_16 ( V_2 ) ; V_23 ++ )
F_22 ( V_2 , V_23 , V_2 -> V_34 [ V_23 ] ) ;
F_23 ( V_2 ) ;
F_24 ( & V_2 -> V_31 ) ;
}
return V_21 ;
}
static int F_25 ( struct V_1 * V_2 , char V_35 )
{
T_1 V_36 ;
int V_21 ;
V_36 = F_26 ( V_2 -> V_14 -> V_15 ) ;
V_36 &= V_37 ;
V_36 |= V_38 | V_39 |
V_40 ;
if ( V_35 ) {
V_36 |= V_41 ;
switch ( V_2 -> V_42 ) {
case 32000 :
V_36 |= V_43 |
V_44 ;
break;
case 44100 :
V_36 |= V_43 ;
break;
case 48000 :
V_36 |= V_44 ;
break;
}
} else {
switch ( V_2 -> V_42 ) {
case 32000 :
V_36 |= V_43 |
V_44 ;
break;
case 48000 :
V_36 |= V_44 ;
break;
}
}
if ( ( V_21 = F_5 ( V_2 , V_36 , FALSE ) ) )
return V_21 ;
V_2 -> V_45 = V_35 ;
F_6 ( V_2 -> V_5 -> V_6 , L_4 ,
V_35 ? L_5 : L_6 ) ;
return 0 ;
}
