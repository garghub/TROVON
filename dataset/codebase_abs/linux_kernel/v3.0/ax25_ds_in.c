static int F_1 ( T_1 * V_1 , struct V_2 * V_3 , int V_4 , int V_5 , int type )
{
switch ( V_4 ) {
case V_6 :
V_1 -> V_7 = V_8 ;
V_1 -> V_9 = V_1 -> V_10 -> V_11 [ V_12 ] ;
F_2 ( V_1 , V_13 , V_5 , V_14 ) ;
break;
case V_15 :
V_1 -> V_7 = V_16 ;
V_1 -> V_9 = V_1 -> V_10 -> V_11 [ V_17 ] ;
F_2 ( V_1 , V_13 , V_5 , V_14 ) ;
break;
case V_18 :
F_2 ( V_1 , V_19 , V_5 , V_14 ) ;
break;
case V_13 :
F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
V_1 -> V_20 = 0 ;
V_1 -> V_21 = 0 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = 0 ;
if ( V_1 -> V_26 != NULL ) {
F_7 ( V_1 -> V_26 ) ;
V_1 -> V_26 -> V_27 = V_28 ;
if ( ! F_8 ( V_1 -> V_26 , V_29 ) )
V_1 -> V_26 -> V_30 ( V_1 -> V_26 ) ;
F_9 ( V_1 -> V_26 ) ;
}
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
break;
case V_19 :
if ( V_5 )
F_12 ( V_1 , V_31 ) ;
break;
default:
if ( V_5 )
F_2 ( V_1 , V_6 , V_32 , V_33 ) ;
break;
}
return 0 ;
}
static int F_13 ( T_1 * V_1 , struct V_2 * V_3 , int V_4 , int V_5 , int type )
{
switch ( V_4 ) {
case V_6 :
case V_15 :
F_2 ( V_1 , V_18 , V_32 , V_33 ) ;
F_14 ( V_1 ) ;
break;
case V_18 :
F_2 ( V_1 , V_13 , V_5 , V_14 ) ;
F_14 ( V_1 ) ;
F_12 ( V_1 , 0 ) ;
break;
case V_19 :
case V_13 :
if ( V_5 ) {
F_14 ( V_1 ) ;
F_12 ( V_1 , 0 ) ;
}
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( V_5 ) {
F_2 ( V_1 , V_18 , V_32 , V_33 ) ;
F_14 ( V_1 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_15 ( T_1 * V_1 , struct V_2 * V_3 , int V_4 , int V_38 , int V_39 , int V_5 , int type )
{
int V_40 = 0 ;
switch ( V_4 ) {
case V_6 :
case V_15 :
if ( V_4 == V_6 ) {
V_1 -> V_7 = V_8 ;
V_1 -> V_9 = V_1 -> V_10 -> V_11 [ V_12 ] ;
} else {
V_1 -> V_7 = V_16 ;
V_1 -> V_9 = V_1 -> V_10 -> V_11 [ V_17 ] ;
}
F_2 ( V_1 , V_13 , V_5 , V_14 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
V_1 -> V_41 = 0x00 ;
V_1 -> V_20 = 0 ;
V_1 -> V_21 = 0 ;
V_1 -> V_22 = 0 ;
F_16 ( V_1 ) ;
F_10 ( V_1 ) ;
break;
case V_18 :
F_2 ( V_1 , V_13 , V_5 , V_14 ) ;
F_14 ( V_1 ) ;
F_12 ( V_1 , 0 ) ;
break;
case V_19 :
F_14 ( V_1 ) ;
F_12 ( V_1 , V_42 ) ;
break;
case V_37 :
case V_36 :
if ( V_4 == V_37 )
V_1 -> V_41 &= ~ V_43 ;
else
V_1 -> V_41 |= V_43 ;
if ( F_17 ( V_1 , V_39 ) ) {
if ( F_18 ( V_1 , V_39 ) )
V_1 -> V_25 = 0 ;
if ( type == V_33 && V_5 )
F_19 ( V_1 ) ;
} else {
F_20 ( V_1 ) ;
V_1 -> V_23 = V_44 ;
}
break;
case V_35 :
V_1 -> V_41 &= ~ V_43 ;
if ( F_17 ( V_1 , V_39 ) ) {
if ( V_1 -> V_21 != V_39 )
V_1 -> V_25 = 0 ;
F_21 ( V_1 , V_39 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_16 ( V_1 ) ;
if ( type == V_33 && V_5 )
F_19 ( V_1 ) ;
} else {
F_20 ( V_1 ) ;
V_1 -> V_23 = V_44 ;
}
break;
case V_34 :
if ( ! F_17 ( V_1 , V_39 ) ) {
F_20 ( V_1 ) ;
V_1 -> V_23 = V_44 ;
break;
}
if ( V_1 -> V_41 & V_43 ) {
F_21 ( V_1 , V_39 ) ;
V_1 -> V_25 = 0 ;
} else {
if ( F_18 ( V_1 , V_39 ) )
V_1 -> V_25 = 0 ;
}
if ( V_1 -> V_41 & V_45 ) {
if ( V_5 ) F_19 ( V_1 ) ;
break;
}
if ( V_38 == V_1 -> V_22 ) {
V_1 -> V_22 = ( V_1 -> V_22 + 1 ) % V_1 -> V_7 ;
V_40 = F_22 ( V_1 , V_3 ) ;
if ( V_1 -> V_41 & V_45 )
V_1 -> V_22 = V_38 ;
V_1 -> V_41 &= ~ V_46 ;
if ( V_5 ) {
F_19 ( V_1 ) ;
} else {
if ( ! ( V_1 -> V_41 & V_47 ) ) {
V_1 -> V_41 |= V_47 ;
F_23 ( V_1 ) ;
}
}
} else {
if ( V_1 -> V_41 & V_46 ) {
if ( V_5 ) F_19 ( V_1 ) ;
} else {
V_1 -> V_41 |= V_46 ;
F_19 ( V_1 ) ;
V_1 -> V_41 &= ~ V_47 ;
}
}
break;
case V_48 :
case V_49 :
F_24 ( V_1 ) ;
V_1 -> V_23 = V_44 ;
break;
default:
break;
}
return V_40 ;
}
int F_25 ( T_1 * V_1 , struct V_2 * V_3 , int type )
{
int V_40 = 0 , V_4 , V_38 , V_39 , V_5 ;
V_4 = F_26 ( V_1 , V_3 , & V_38 , & V_39 , & V_5 ) ;
switch ( V_1 -> V_23 ) {
case V_44 :
V_40 = F_1 ( V_1 , V_3 , V_4 , V_5 , type ) ;
break;
case V_50 :
V_40 = F_13 ( V_1 , V_3 , V_4 , V_5 , type ) ;
break;
case V_24 :
V_40 = F_15 ( V_1 , V_3 , V_4 , V_38 , V_39 , V_5 , type ) ;
break;
}
return V_40 ;
}
