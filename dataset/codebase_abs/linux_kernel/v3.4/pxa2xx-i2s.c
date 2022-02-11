static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_8 = V_6 -> V_8 ;
if ( F_2 ( V_9 ) )
return F_3 ( V_9 ) ;
if ( ! V_8 -> V_10 )
V_11 = 0 ;
return 0 ;
}
static int F_4 ( void )
{
int V_12 ;
for( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_13 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_8 ,
unsigned int V_14 )
{
switch ( V_14 & V_15 ) {
case V_16 :
V_17 . V_14 = 0 ;
break;
case V_18 :
V_17 . V_14 = V_19 ;
break;
}
switch ( V_14 & V_20 ) {
case V_21 :
V_17 . V_22 = 1 ;
break;
case V_23 :
V_17 . V_22 = 0 ;
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_3 * V_8 ,
int V_24 , unsigned int V_25 , int V_26 )
{
if ( V_24 != V_27 )
return - V_28 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_31 * V_32 ;
F_8 ( F_2 ( V_9 ) ) ;
F_9 ( V_9 ) ;
V_33 = 1 ;
F_4 () ;
if ( V_2 -> V_34 == V_35 )
V_32 = & V_36 ;
else
V_32 = & V_37 ;
F_10 ( V_4 , V_2 , V_32 ) ;
if ( ! ( V_11 & V_38 ) ) {
V_11 = 0 ;
if ( V_17 . V_22 )
V_11 |= V_39 ;
V_11 |= F_11 ( 14 ) | F_12 ( 1 ) ;
V_40 |= V_17 . V_14 ;
}
if ( V_2 -> V_34 == V_35 )
V_41 |= V_42 ;
else
V_41 |= V_43 ;
switch ( F_13 ( V_30 ) ) {
case 8000 :
V_44 = 0x48 ;
break;
case 11025 :
V_44 = 0x34 ;
break;
case 16000 :
V_44 = 0x24 ;
break;
case 22050 :
V_44 = 0x1a ;
break;
case 44100 :
V_44 = 0xd ;
break;
case 48000 :
V_44 = 0xc ;
break;
case 96000 :
V_44 = 0x6 ;
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_45 ,
struct V_3 * V_4 )
{
int V_46 = 0 ;
switch ( V_45 ) {
case V_47 :
if ( V_2 -> V_34 == V_35 )
V_40 &= ~ V_48 ;
else
V_40 &= ~ V_49 ;
V_11 |= V_38 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
default:
V_46 = - V_55 ;
}
return V_46 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_34 == V_35 ) {
V_40 |= V_48 ;
V_41 &= ~ V_42 ;
} else {
V_40 |= V_49 ;
V_41 &= ~ V_43 ;
}
if ( ( V_40 & ( V_49 | V_48 ) ) == ( V_49 | V_48 ) ) {
V_11 &= ~ V_38 ;
F_4 () ;
if ( V_33 ) {
F_16 ( V_9 ) ;
V_33 = 0 ;
}
}
}
static int F_17 ( struct V_3 * V_4 )
{
V_17 . V_56 = V_11 ;
V_17 . V_57 = V_40 ;
V_17 . V_58 = V_41 ;
V_17 . V_59 = V_44 ;
V_11 &= ~ V_38 ;
F_4 () ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
F_4 () ;
V_11 = V_17 . V_56 & ~ V_38 ;
V_40 = V_17 . V_57 ;
V_41 = V_17 . V_58 ;
V_44 = V_17 . V_59 ;
V_11 = V_17 . V_56 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
V_9 = F_20 ( V_4 -> V_60 , L_1 ) ;
if ( F_2 ( V_9 ) )
return F_3 ( V_9 ) ;
V_11 = V_61 ;
V_11 = 0 ;
V_40 = V_48 | V_49 ;
V_41 &= ~ ( V_43 | V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
F_22 ( V_9 ) ;
V_9 = F_23 ( - V_62 ) ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 )
{
return F_25 ( & V_64 -> V_60 , & V_65 ) ;
}
static int T_1 F_26 ( struct V_63 * V_64 )
{
F_27 ( & V_64 -> V_60 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
V_9 = F_23 ( - V_62 ) ;
return F_29 ( & V_66 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_66 ) ;
}
