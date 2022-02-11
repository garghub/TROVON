static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
do {
V_3 = F_2 ( V_2 , V_4 ) ;
} while ( V_3 & ( V_5 | V_6 ) );
F_3 ( V_7 , V_2 -> V_8 . V_9 ) ;
F_3 ( V_10 , V_2 -> V_8 . V_11 ) ;
F_4 ( V_2 , V_12 , V_13 ) ;
memcpy ( V_2 -> V_14 , V_2 -> V_15 , sizeof( V_2 -> V_14 ) ) ;
memcpy ( V_2 -> V_16 , V_2 -> V_17 , sizeof( V_2 -> V_16 ) ) ;
memcpy ( V_2 -> V_18 , V_2 -> V_19 , sizeof( V_2 -> V_18 ) ) ;
memcpy ( V_2 -> V_20 , V_2 -> V_19 + V_21 , sizeof( V_2 -> V_20 ) ) ;
F_4 ( V_2 , V_22 , 0 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_23 ) ; V_3 ++ )
V_2 -> V_23 [ V_3 ] = F_6 ( V_2 , V_24 ) ;
}
static void F_7 ( T_1 V_25 )
{
T_1 V_26 ;
int V_3 ;
F_3 ( V_10 , V_26 ) ;
V_26 |= V_27 ;
V_26 &= ~ V_28 ;
F_8 ( V_10 , V_26 , V_25 ) ;
for ( V_3 = 0 ; V_3 < 200 ; V_3 ++ ) {
F_3 ( V_10 , V_26 ) ;
if ( V_26 & V_29 )
break;
F_9 ( 1 ) ;
}
V_26 &= ~ V_27 ;
F_8 ( V_10 , V_26 , V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_14 ) ; V_3 ++ ) {
switch ( V_3 ) {
case V_30 :
case V_31 :
case V_4 :
case V_32 :
break;
default:
F_11 ( V_2 , V_3 , V_2 -> V_14 [ V_3 ] ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_16 ) ; V_3 ++ ) {
switch ( V_3 ) {
case V_12 :
F_4 ( V_2 , V_12 , V_13 ) ;
break;
case V_33 :
F_4 ( V_2 , V_3 , V_2 -> V_16 [ V_3 ] & ~ ( V_34 |
V_35 |
V_36 |
V_37 ) ) ;
break;
case V_38 :
F_4 ( V_2 , V_3 , V_2 -> V_16 [ V_3 ] & ~ ( V_39 |
V_40 |
V_41 ) ) ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_22 :
case V_24 :
case V_48 :
case V_49 :
case V_50 :
break;
default:
F_4 ( V_2 , V_3 , V_2 -> V_16 [ V_3 ] ) ;
}
}
F_4 ( V_2 , V_22 , 0 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_23 ) ; V_3 ++ )
F_4 ( V_2 , V_24 , V_2 -> V_23 [ V_3 ] ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_3 ;
F_14 ( V_7 , V_2 -> V_8 . V_9 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_18 ) ; V_3 ++ ) {
switch ( V_3 ) {
case V_51 :
F_15 ( V_2 , V_3 , V_2 -> V_18 [ V_3 ] & ~ V_52 ) ;
break;
case V_53 :
F_15 ( V_2 , V_3 , V_2 -> V_18 [ V_3 ] &
~ ( V_54 | V_55 |
V_56 | V_57 ) ) ;
break;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
break;
default:
F_15 ( V_2 , V_3 , V_2 -> V_18 [ V_3 ] ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 )
{
int V_3 ;
F_7 ( ( T_1 ) ( V_2 -> V_8 . V_11 >> 32 ) ) ;
F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_2 -> V_20 ) ; V_3 ++ ) {
if ( V_3 != V_67 && V_3 != V_68 )
F_17 ( V_2 , V_3 , V_2 -> V_20 [ V_3 ] ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_51 , V_2 -> V_18 [ V_51 ] & ~ V_52 ) ;
F_15 ( V_2 , V_53 , V_2 -> V_18 [ V_53 ] & ~ ( V_54 |
V_55 | V_56 | V_57 ) ) ;
F_17 ( V_2 , V_67 , V_2 -> V_20 [ V_67 ] & ~ V_69 ) ;
F_4 ( V_2 , V_12 , V_13 ) ;
F_4 ( V_2 , V_33 , V_2 -> V_16 [ V_33 ] &
~ ( V_34 | V_35 |
V_36 | V_37 ) ) ;
F_4 ( V_2 , V_38 , V_2 -> V_16 [ V_38 ] &
~ ( V_39 | V_40 |
V_41 ) ) ;
F_4 ( V_2 , V_12 , V_70 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_20 = F_20 ( V_2 , V_67 ) ;
if ( V_2 -> V_20 [ V_67 ] & V_69 ) {
if ( ! ( V_20 & ( V_71 | V_72 ) ) )
F_17 ( V_2 , V_67 , V_2 -> V_20 [ V_67 ] ) ;
} else {
if ( ! ( V_20 & ( V_73 | V_74 ) ) )
F_17 ( V_2 , V_67 , V_2 -> V_20 [ V_67 ] ) ;
}
F_15 ( V_2 , V_51 , V_2 -> V_18 [ V_51 ] ) ;
F_15 ( V_2 , V_53 , V_2 -> V_18 [ V_53 ] ) ;
F_4 ( V_2 , V_38 , V_2 -> V_16 [ V_38 ] ) ;
F_4 ( V_2 , V_33 , V_2 -> V_16 [ V_33 ] ) ;
F_4 ( V_2 , V_12 , V_70 ) ;
}
int F_21 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
if ( V_2 -> V_77 )
return 0 ;
F_1 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_77 = 1 ;
return 0 ;
}
int F_22 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
if ( ! V_2 -> V_77 )
return 0 ;
F_16 ( V_2 ) ;
F_19 ( V_2 ) ;
V_2 -> V_77 = 0 ;
return 0 ;
}
