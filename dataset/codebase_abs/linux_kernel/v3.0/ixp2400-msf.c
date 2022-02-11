static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
T_1 V_5 ;
V_3 = ! ! ( V_2 -> V_6 & V_7 ) ;
V_4 = ! ! ( V_2 -> V_8 & V_9 ) ;
V_5 = F_2 ( V_10 ) ;
V_5 |= 0x0000f0f0 ;
F_3 ( V_10 , V_5 ) ;
V_5 &= ~ 0x03000000 ;
V_5 |= ( V_3 << 24 ) | ( V_4 << 25 ) ;
V_5 &= ~ 0x00ff0000 ;
V_5 |= V_2 -> V_11 << 16 ;
V_5 |= V_2 -> V_12 << 18 ;
V_5 |= V_2 -> V_13 << 20 ;
V_5 |= V_2 -> V_14 << 22 ;
F_3 ( V_10 , V_5 ) ;
V_5 &= ~ ( 0x00005000 | V_3 << 13 | V_4 << 15 ) ;
F_3 ( V_10 , V_5 ) ;
V_5 &= ~ ( 0x00000050 | V_3 << 5 | V_4 << 7 ) ;
F_3 ( V_10 , V_5 ) ;
F_4 ( 100 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_15 ;
int V_16 ;
V_15 = V_2 -> V_6 & V_17 ;
if ( V_15 == V_18 ) {
for ( V_16 = 1 ; V_16 < 128 ; V_16 ++ ) {
if ( V_16 == 9 || V_16 == 18 || V_16 == 27 )
continue;
F_3 ( V_19 , V_16 ) ;
}
} else if ( V_15 == V_20 ) {
for ( V_16 = 1 ; V_16 < 64 ; V_16 ++ ) {
if ( V_16 == 4 || V_16 == 9 || V_16 == 13 )
continue;
F_3 ( V_19 , V_16 ) ;
}
} else if ( V_15 == V_21 ) {
for ( V_16 = 1 ; V_16 < 32 ; V_16 ++ ) {
if ( V_16 == 2 || V_16 == 4 || V_16 == 6 )
continue;
F_3 ( V_19 , V_16 ) ;
}
}
}
static T_1 F_6 ( T_1 V_22 )
{
T_1 V_23 ;
V_23 = 0 ;
switch ( V_22 & V_7 ) {
case V_24 :
V_23 = 0x1 ;
if ( V_22 & V_25 &&
! ( V_22 & V_26 ) )
V_23 = 0xf ;
break;
case V_27 :
V_23 = 0x5 ;
break;
case V_28 :
V_23 = 0xf ;
break;
case V_29 :
V_23 = 0xd ;
break;
}
return V_23 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_2 ( V_30 ) & 0x0fffffff ;
V_5 |= F_6 ( V_2 -> V_6 ) << 28 ;
F_3 ( V_30 , V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_2 ( V_31 ) & 0x0fffffff ;
V_5 |= F_6 ( V_2 -> V_8 ) << 28 ;
F_3 ( V_31 , V_5 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_16 ;
F_1 ( V_2 ) ;
V_5 = F_2 ( V_32 ) ;
F_3 ( V_32 , V_5 | 0x80 ) ;
F_3 ( V_32 , V_5 & ~ 0x80 ) ;
F_3 ( V_33 , V_2 -> V_34 - 1 ) ;
F_3 ( V_30 , V_2 -> V_6 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
F_3 ( V_35 + V_16 ,
V_2 -> V_36 [ V_16 ] ) ;
}
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
F_3 ( V_37 , V_2 -> V_38 - 1 ) ;
F_3 ( V_31 , V_2 -> V_8 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
F_3 ( V_39 + V_16 ,
V_2 -> V_40 [ V_16 ] ) ;
}
F_8 ( V_2 ) ;
}
