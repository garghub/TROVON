static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 ) ;
if ( F_3 ( V_2 , & V_3 ) < 0 ) {
F_4 ( ( L_1 ) ) ;
V_2 -> V_5 = FALSE ;
return - V_6 ;
}
V_2 -> V_5 = ( V_3 == V_7 ) ;
return V_2 -> V_5 ? 0 : - V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_8 , char V_9 )
{
if ( V_2 -> V_10 )
V_8 |= V_11 ;
else
V_8 &= ~ V_11 ;
F_6 ( ( L_2 , V_8 ) ) ;
V_8 = F_7 ( V_8 ) ;
if ( V_8 != V_2 -> V_12 -> V_13 || V_9 ) {
if ( F_8 ( V_2 ) )
return - V_6 ;
V_2 -> V_12 -> V_13 = V_8 ;
F_9 ( V_2 ) ;
return F_2 ( V_2 , V_14 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_15 )
{
F_6 ( ( L_3 , V_15 ) ) ;
V_2 -> V_10 = V_15 ;
return F_11 ( V_2 , V_2 -> V_16 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 ;
int V_19 , V_20 , V_21 ;
if ( V_2 -> V_22 )
return - V_6 ;
if ( F_13 ( V_2 -> V_23 ) )
return - V_24 ;
if ( F_13 ( ! ( V_2 -> V_25 & ( 1 << V_17 ) ) ) )
return - V_26 ;
V_18 = V_2 -> V_27 ;
V_19 = F_14 ( V_2 , V_17 ) ;
if ( V_19 >= 0 && V_18 != V_17 &&
( V_18 == V_28 || V_17 == V_28 ) ) {
F_15 ( & V_2 -> V_29 ) ;
for ( V_21 = 0 ; V_21 < F_16 ( V_2 ) ; V_21 ++ )
for ( V_20 = 0 ; V_20 < F_17 ( V_2 ) ; V_20 ++ )
F_18 ( V_2 , V_21 , V_20 ,
V_2 -> V_30 [ V_21 ] [ V_20 ] ) ;
#ifdef F_19
for ( V_20 = 0 ; V_20 < F_17 ( V_2 ) ; V_20 ++ )
F_20 ( V_2 , V_20 , V_2 -> V_31 [ V_20 ] ) ;
F_21 ( V_2 ) ;
#endif
for ( V_21 = 0 ; V_21 < F_16 ( V_2 ) ; V_21 ++ )
F_22 ( V_2 , V_21 , V_2 -> V_32 [ V_21 ] ) ;
F_23 ( V_2 ) ;
F_24 ( & V_2 -> V_29 ) ;
}
return V_19 ;
}
static int F_25 ( struct V_1 * V_2 , char V_33 )
{
T_1 V_34 ;
int V_19 ;
V_34 = F_26 ( V_2 -> V_12 -> V_13 ) ;
V_34 &= V_35 ;
V_34 |= V_36 | V_37 |
V_38 ;
if ( V_33 ) {
V_34 |= V_39 ;
switch ( V_2 -> V_40 ) {
case 32000 :
V_34 |= V_41 |
V_42 ;
break;
case 44100 :
V_34 |= V_41 ;
break;
case 48000 :
V_34 |= V_42 ;
break;
}
} else {
switch ( V_2 -> V_40 ) {
case 32000 :
V_34 |= V_41 |
V_42 ;
break;
case 48000 :
V_34 |= V_42 ;
break;
}
}
if ( ( V_19 = F_5 ( V_2 , V_34 , FALSE ) ) )
return V_19 ;
V_2 -> V_43 = V_33 ;
F_6 ( ( L_4 ,
V_33 ? L_5 : L_6 ) ) ;
return 0 ;
}
