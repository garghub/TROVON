static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( F_2 ( V_7 ) & V_8 )
break;
F_3 ( 1 ) ;
}
V_4 = F_4 ( V_3 ) | V_9 ;
F_5 ( V_10 , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( F_2 ( V_10 ) & V_9 )
break;
F_3 ( 1 ) ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( F_2 ( V_7 ) & V_11 )
break;
F_3 ( 1 ) ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( F_2 ( V_7 ) & V_8 )
break;
F_3 ( 1 ) ;
}
V_4 &= ~ V_9 ;
F_5 ( V_10 , V_4 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
T_1 V_5 ;
if ( ! V_13 -> V_14 )
return;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
F_8 ( V_16 + ( V_5 * 4 ) ,
V_13 -> V_17 . V_18 [ V_5 ] ) ;
for (; V_5 < V_15 * 2 ; V_5 ++ )
F_8 ( V_16 + ( V_5 * 4 ) ,
V_13 -> V_17 . V_19 [ V_5 % V_15 ] ) ;
for (; V_5 < V_15 * 3 ; V_5 ++ )
F_8 ( V_16 + ( V_5 * 4 ) ,
V_13 -> V_17 . V_20 [ V_5 % V_15 ] ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
bool V_21 = false ;
if ( ! V_13 -> V_22 )
return V_21 ;
if ( ( V_2 -> V_23 == V_24 ) || ( V_2 -> V_23 == V_25 ) ) {
if ( V_13 -> V_26 >= 0x00010C00 )
V_21 = true ;
}
return V_21 ;
}
void F_10 ( struct V_1 * V_2 ,
bool V_27 , bool V_28 )
{
T_1 V_29 = 0 ;
if ( ! F_9 ( V_2 ) )
return;
if ( V_27 )
V_29 |= 1 ;
if ( V_28 )
V_29 |= 2 ;
F_8 ( V_30 , V_29 ) ;
F_1 ( V_2 , V_31 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_32 ) ;
}
static T_1 F_12 ( T_1 V_33 )
{
T_1 V_34 = 1 ;
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ )
V_34 *= 4 ;
return V_34 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
T_1 V_35 , V_33 , V_36 ;
T_1 V_37 = F_14 ( V_2 ) ;
V_33 = ( F_15 ( V_38 ) & V_39 )
>> V_40 ;
V_35 = 100 * ( V_37 / 100 / F_12 ( V_33 ) ) ;
V_36 = ( V_35 << 16 ) | ( V_33 << 4 ) ;
F_8 ( V_41 , V_36 ) ;
F_8 ( V_42 , V_13 -> V_17 . V_43 ) ;
F_8 ( V_44 , V_13 -> V_17 . V_45 ) ;
F_8 ( V_46 , V_13 -> V_17 . V_47 ) ;
F_8 ( V_48 , V_13 -> V_17 . V_49 ) ;
F_1 ( V_2 , V_50 ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_51 , T_1 V_52 )
{
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0xFFF ;
T_1 V_56 ;
switch ( V_51 ) {
case 0 :
V_53 = V_57 ;
V_54 = 16 ;
break;
case 1 :
V_53 = V_57 ;
V_54 = 0 ;
break;
case 2 :
V_53 = V_58 ;
V_54 = 16 ;
break;
case 3 :
V_53 = V_58 ;
V_54 = 0 ;
break;
case 4 :
V_53 = V_59 ;
V_54 = 16 ;
break;
case 7 :
V_53 = V_59 ;
V_54 = 0 ;
break;
default:
break;
}
V_56 = F_15 ( V_53 ) ;
V_56 &= ~ ( V_55 << V_54 ) ;
V_56 |= ( V_52 << V_54 ) ;
F_8 ( V_53 , V_56 ) ;
}
void F_17 ( struct V_1 * V_2 , bool V_60 )
{
T_1 V_61 = F_15 ( V_62 ) ;
V_61 &= 0xFFFFFFFE ;
V_61 |= ( V_60 ? 0 : 1 ) ;
F_8 ( V_62 , V_61 ) ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
return F_15 ( V_63 ) ;
}
