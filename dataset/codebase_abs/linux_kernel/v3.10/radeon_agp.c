int F_1 ( struct V_1 * V_2 )
{
#if V_3
struct V_4 * V_5 = V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
T_1 V_11 ;
int V_12 ;
bool V_13 ;
int V_14 ;
V_14 = F_2 ( V_2 -> V_15 ) ;
if ( V_14 ) {
F_3 ( L_1 , V_14 ) ;
return V_14 ;
}
V_14 = V_9 ( V_2 -> V_15 , & V_10 ) ;
if ( V_14 ) {
F_4 ( V_2 -> V_15 ) ;
F_3 ( L_2 , V_14 ) ;
return V_14 ;
}
if ( V_2 -> V_15 -> V_16 -> V_17 . V_18 < 32 ) {
F_4 ( V_2 -> V_15 ) ;
F_5 ( V_2 -> V_19 , L_3
L_4 ,
V_2 -> V_15 -> V_16 -> V_17 . V_18 ) ;
return - V_20 ;
}
V_8 . V_8 = V_10 . V_8 ;
if ( V_2 -> V_21 <= V_22 )
V_11 = ( F_6 ( V_23 ) | V_24 ) & V_8 . V_8 ;
else
V_11 = V_8 . V_8 ;
V_13 = ! ! ( V_11 & V_24 ) ;
if ( V_13 ) {
V_12 = ( V_11 & V_25 ) ? 8 : 4 ;
} else {
if ( V_11 & V_26 ) {
V_12 = 4 ;
} else if ( V_11 & V_27 ) {
V_12 = 2 ;
} else {
V_12 = 1 ;
}
}
while ( V_5 && V_5 -> V_28 != 0 ) {
if ( V_10 . V_29 == V_5 -> V_30 &&
V_10 . V_31 == V_5 -> V_32 &&
V_2 -> V_33 -> V_34 == V_5 -> V_35 &&
V_2 -> V_33 -> V_36 == V_5 -> V_28 &&
V_2 -> V_33 -> V_37 == V_5 -> V_38 &&
V_2 -> V_33 -> V_39 == V_5 -> V_40 ) {
V_12 = V_5 -> V_12 ;
}
++ V_5 ;
}
if ( V_41 > 0 ) {
if ( ( V_41 < ( V_13 ? 4 : 1 ) ) ||
( V_41 > ( V_13 ? 8 : 4 ) ) ||
( V_41 & ( V_41 - 1 ) ) ) {
F_3 ( L_5 ,
V_41 , V_13 ? L_6 : L_7 ,
V_12 ) ;
V_41 = V_12 ;
} else {
F_7 ( L_8 , V_41 ) ;
}
} else {
V_41 = V_12 ;
}
V_8 . V_8 &= ~ V_42 ;
if ( V_13 ) {
switch ( V_41 ) {
case 8 :
V_8 . V_8 |= V_25 ;
break;
case 4 :
default:
V_8 . V_8 |= V_43 ;
break;
}
} else {
switch ( V_41 ) {
case 4 :
V_8 . V_8 |= V_26 ;
break;
case 2 :
V_8 . V_8 |= V_27 ;
break;
case 1 :
default:
V_8 . V_8 |= V_44 ;
break;
}
}
V_8 . V_8 &= ~ V_45 ;
V_14 = F_8 ( V_2 -> V_15 , V_8 ) ;
if ( V_14 ) {
F_3 ( L_9 , V_8 . V_8 ) ;
F_4 ( V_2 -> V_15 ) ;
return V_14 ;
}
V_2 -> V_46 . V_47 = V_2 -> V_15 -> V_16 -> V_17 . V_48 ;
V_2 -> V_46 . V_49 = V_2 -> V_15 -> V_16 -> V_17 . V_18 << 20 ;
V_2 -> V_46 . V_50 = V_2 -> V_46 . V_47 ;
V_2 -> V_46 . V_51 = V_2 -> V_46 . V_50 + V_2 -> V_46 . V_49 - 1 ;
F_9 ( V_2 -> V_19 , L_10 ,
V_2 -> V_46 . V_49 >> 20 , V_2 -> V_46 . V_50 , V_2 -> V_46 . V_51 ) ;
if ( V_2 -> V_21 < V_52 ) {
F_10 ( V_53 , F_6 ( V_53 ) | 0x000e0000 ) ;
}
return 0 ;
#else
return 0 ;
#endif
}
void F_11 ( struct V_1 * V_2 )
{
#if V_3
int V_54 ;
if ( V_2 -> V_55 & V_56 ) {
V_54 = F_1 ( V_2 ) ;
if ( V_54 )
F_5 ( V_2 -> V_19 , L_11 ) ;
}
#endif
}
void F_12 ( struct V_1 * V_2 )
{
#if V_3
if ( V_2 -> V_15 -> V_16 && V_2 -> V_15 -> V_16 -> V_57 ) {
F_4 ( V_2 -> V_15 ) ;
}
#endif
}
void F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
