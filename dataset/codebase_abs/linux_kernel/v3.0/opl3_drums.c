static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_5 = V_6 [ V_4 -> V_7 ] [ V_4 -> V_8 ] ;
unsigned char V_9 = V_4 -> V_7 ;
unsigned short V_10 ;
V_10 = V_11 | ( V_12 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_14 ) ;
V_10 = V_11 | ( V_15 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_16 ) ;
V_10 = V_11 | ( V_17 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_18 ) ;
V_10 = V_11 | ( V_19 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_20 ) ;
V_10 = V_11 | ( V_21 + V_9 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_22 ) ;
V_10 = V_11 | ( V_23 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_24 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_25 * V_4 )
{
unsigned char V_9 = V_4 -> V_7 ;
unsigned short V_10 ;
V_10 = V_11 | ( V_26 + V_9 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_27 ) ;
V_10 = V_11 | ( V_28 + V_9 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_4 -> V_29 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_30 , struct V_31 * V_32 )
{
unsigned char V_5 = V_6 [ V_4 -> V_7 ] [ V_4 -> V_8 ] ;
unsigned char V_9 = V_4 -> V_7 ;
unsigned char V_33 ;
unsigned short V_10 ;
V_33 = V_4 -> V_16 ;
F_4 ( & V_33 , V_30 , V_32 ) ;
V_10 = V_11 | ( V_15 + V_5 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_33 ) ;
V_33 = V_4 -> V_22 | V_34 ;
if ( V_32 -> V_35 < 43 )
V_33 &= ~ V_36 ;
if ( V_32 -> V_35 > 85 )
V_33 &= ~ V_37 ;
V_10 = V_11 | ( V_21 + V_9 ) ;
V_2 -> V_13 ( V_2 , V_10 , V_33 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , & V_38 ) ;
F_1 ( V_2 , & V_39 ) ;
F_2 ( V_2 , & V_40 ) ;
F_1 ( V_2 , & V_41 ) ;
F_1 ( V_2 , & V_42 ) ;
F_2 ( V_2 , & V_43 ) ;
F_1 ( V_2 , & V_44 ) ;
F_2 ( V_2 , & V_45 ) ;
F_1 ( V_2 , & V_46 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_47 , int V_30 , int V_48 ,
struct V_31 * V_32 )
{
unsigned char V_49 ;
struct V_3 * V_50 ;
if ( ! ( V_2 -> V_51 & V_52 ) )
return;
if ( ( V_47 < 35 ) || ( V_47 > 81 ) )
return;
V_49 = V_53 [ V_47 - 35 ] ;
if ( V_48 ) {
switch ( V_49 ) {
case V_54 :
V_50 = & V_39 ;
break;
case V_55 :
V_50 = & V_41 ;
break;
case V_56 :
V_50 = & V_42 ;
break;
case V_57 :
V_50 = & V_44 ;
break;
case V_58 :
V_50 = & V_46 ;
break;
default:
V_50 = & V_44 ;
}
F_3 ( V_2 , V_50 , V_30 , V_32 ) ;
V_2 -> V_51 |= V_49 ;
} else {
V_2 -> V_51 &= ~ V_49 ;
}
V_2 -> V_13 ( V_2 , V_11 | V_59 ,
V_2 -> V_51 ) ;
}
