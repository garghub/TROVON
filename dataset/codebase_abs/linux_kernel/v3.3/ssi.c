static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
if ( V_6 -> V_9 ) {
F_2 ( L_1 ) ;
return - V_10 ;
} else
V_6 -> V_9 = 1 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
V_6 -> V_9 = 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_11 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
switch ( V_11 ) {
case V_12 :
F_5 ( V_13 ) |= V_14 | V_15 ;
break;
case V_16 :
F_5 ( V_13 ) &= ~ ( V_14 | V_15 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
unsigned long V_20 = F_5 ( V_13 ) ;
unsigned int V_21 , V_22 , V_23 , V_24 , V_25 ;
V_22 = F_7 ( V_19 ) ;
V_21 = V_19 -> V_26 ;
V_24 = ( V_2 -> V_27 == V_28 ) ? 0 : 1 ;
F_2 ( L_2 , V_20 ) ;
F_2 ( L_3 , V_21 , V_22 ) ;
V_20 &= ~ ( V_29 | V_30 | V_31 | V_32 |
V_33 ) ;
if ( ! V_24 )
V_20 |= V_29 ;
if ( ( V_22 < 2 ) || ( V_22 > 8 ) || ( V_22 & 1 ) ) {
F_2 ( L_4 ) ;
return - V_17 ;
}
V_20 |= ( ( V_22 >> 1 ) - 1 ) << V_34 ;
V_25 = 0 ;
switch ( V_21 ) {
case 32 : ++ V_25 ;
case 24 : ++ V_25 ;
case 22 : ++ V_25 ;
case 20 : ++ V_25 ;
case 18 : ++ V_25 ;
case 16 : ++ V_25 ;
V_20 |= V_25 << V_35 ;
case 8 : break;
default:
F_2 ( L_5 ) ;
return - V_17 ;
}
if ( ( V_21 > 16 ) && ( V_21 <= 24 ) ) {
V_21 = 24 ;
}
V_25 = 0 ;
V_23 = ( V_21 * V_22 ) / 2 ;
switch ( V_23 ) {
case 256 : ++ V_25 ;
case 128 : ++ V_25 ;
case 64 : ++ V_25 ;
case 48 : ++ V_25 ;
case 32 : ++ V_25 ;
case 16 : ++ V_25 ;
V_20 |= V_25 << V_36 ;
case 8 : break;
default:
F_2 ( L_6 ) ;
return - V_17 ;
}
F_5 ( V_13 ) = V_20 ;
F_2 ( L_7 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_37 , int V_38 ,
unsigned int V_39 , int V_40 )
{
struct V_5 * V_6 = & V_7 [ V_37 -> V_8 ] ;
V_6 -> V_41 = V_39 ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , int V_42 , int div )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
unsigned long V_20 ;
int V_25 ;
V_25 = 0 ;
V_20 = F_5 ( V_13 ) & ~ V_43 ;
switch ( div ) {
case 16 : ++ V_25 ;
case 8 : ++ V_25 ;
case 4 : ++ V_25 ;
case 2 : ++ V_25 ;
F_5 ( V_13 ) = V_20 | ( V_25 << V_44 ) ;
case 1 : break;
default:
F_2 ( L_8 , div ) ;
return - V_17 ;
}
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , unsigned int V_45 )
{
struct V_5 * V_6 = & V_7 [ V_4 -> V_8 ] ;
unsigned long V_20 = F_5 ( V_13 ) ;
F_2 ( L_9 , V_20 ) ;
V_20 &= ~ ( V_46 | V_32 | V_47 | V_48 | V_49 |
V_50 | V_51 ) ;
switch ( V_45 & V_52 ) {
case V_53 :
break;
case V_54 :
V_20 |= V_46 | V_32 ;
break;
case V_55 :
V_20 |= V_46 ;
break;
default:
F_2 ( L_10 ) ;
return - V_17 ;
}
switch ( V_45 & V_56 ) {
case V_57 :
break;
case V_58 :
V_20 |= V_47 ;
break;
}
switch ( V_45 & V_59 ) {
case V_60 :
V_20 |= V_49 ;
break;
case V_61 :
V_20 |= V_49 | V_48 ;
break;
case V_62 :
break;
case V_63 :
V_20 |= V_48 ;
break;
default:
F_2 ( L_11 ) ;
return - V_17 ;
}
switch ( V_45 & V_64 ) {
case V_65 :
break;
case V_66 :
V_20 |= V_51 ;
break;
case V_67 :
V_20 |= V_50 ;
break;
case V_68 :
V_20 |= V_50 | V_51 ;
break;
default:
F_2 ( L_12 ) ;
return - V_17 ;
}
F_5 ( V_13 ) = V_20 ;
F_2 ( L_13 , V_20 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_69 * V_70 )
{
return F_12 ( & V_70 -> V_71 , V_72 ,
F_13 ( V_72 ) ) ;
}
static int T_2 F_14 ( struct V_69 * V_70 )
{
F_15 ( & V_70 -> V_71 , F_13 ( V_72 ) ) ;
return 0 ;
}
