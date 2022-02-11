void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
if ( V_2 -> V_5 -> type != V_6 )
return;
F_2 ( L_1 ) ;
V_4 = F_3 ( V_7 ) ;
V_3 = F_3 ( V_8 ) ;
V_3 |= 0x80 ;
F_4 ( V_3 , V_8 ) ;
V_4 = ( V_4 & ~ 0xF ) | 1 ;
F_4 ( V_4 , V_7 ) ;
F_5 ( F_6 ( 1 ) ) ;
V_4 |= 2 ;
F_4 ( V_4 , V_7 ) ;
V_3 &= ~ 0x80 ;
F_4 ( V_3 , V_8 ) ;
}
int F_7 ( void * V_9 , int V_10 , int V_11 , int V_12 )
{
struct V_13 * V_14 = V_9 ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_4 ;
if ( V_11 != V_16 )
return 0 ;
F_2 ( L_2 ) ;
V_4 = F_3 ( V_7 ) ;
V_4 &= ~ ( 1 << V_2 -> V_5 -> V_17 ) ;
F_4 ( V_4 , V_7 ) ;
F_5 ( F_6 ( 1 ) ) ;
V_4 |= 1 << V_2 -> V_5 -> V_17 ;
F_4 ( V_4 , V_7 ) ;
F_5 ( F_6 ( 1 ) ) ;
return 0 ;
}
static inline struct V_1 * F_8 ( struct V_18 * V_19 )
{
return F_9 ( V_19 , struct V_1 , V_20 ) ;
}
static inline struct V_18 * F_10 ( struct V_21 * V_22 )
{
return & F_9 ( V_22 -> V_23 , struct V_1 , V_24 ) -> V_20 ;
}
static int F_11 ( struct V_18 * V_19 , T_1 V_25 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
V_26 = V_2 -> V_5 -> V_27 . V_26 ;
switch ( V_25 ) {
case 32000 :
V_15 = V_2 -> V_5 -> V_27 . V_28 ;
break;
case 44100 :
V_15 = V_2 -> V_5 -> V_27 . V_29 ;
break;
case 48000 :
default:
V_15 = V_2 -> V_5 -> V_27 . V_30 ;
break;
}
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) | ( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 ;
V_26 = V_2 -> V_5 -> V_33 . V_26 ;
if ( V_26 == 0 || ( F_3 ( V_34 ) & V_26 ) )
V_32 -> V_35 = V_36 |
V_37 | V_38 ;
else
V_32 -> V_35 = V_39 ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 , const struct V_31 * V_32 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
V_26 = V_2 -> V_5 -> V_40 . V_26 ;
switch ( V_32 -> V_41 ) {
case V_42 :
V_15 = V_2 -> V_5 -> V_40 . V_43 ;
break;
case V_44 :
V_15 = V_2 -> V_5 -> V_40 . V_45 ;
break;
case V_46 :
V_15 = V_2 -> V_5 -> V_40 . V_47 ;
break;
case V_48 :
case V_49 :
default:
V_15 = V_2 -> V_5 -> V_40 . V_50 ;
break;
}
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) | ( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
V_26 = V_2 -> V_5 -> V_51 . V_26 ;
V_15 = V_2 -> V_5 -> V_51 . V_52 ;
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) | ( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
if ( V_53 > 2 )
return - V_56 ;
V_26 = V_2 -> V_5 -> V_51 . V_26 ;
switch ( V_53 ) {
case 0 :
V_15 = V_2 -> V_5 -> V_51 . V_57 ;
break;
case 1 :
V_15 = V_2 -> V_5 -> V_51 . V_58 ;
break;
case 2 :
default:
V_15 = V_2 -> V_5 -> V_51 . V_52 ;
break;
}
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) | ( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_18 * V_19 = F_10 ( V_22 ) ;
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
switch ( V_22 -> V_59 ) {
case V_60 :
V_26 = V_2 -> V_5 -> V_61 . V_26 ;
V_15 = V_22 -> V_62 ? V_2 -> V_5 -> V_61 . V_63 : 0 ;
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) |
( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
F_18 ( L_3 ,
F_3 ( V_8 ) , F_3 ( V_7 ) ,
F_3 ( V_34 ) ) ;
F_19 ( & V_2 -> V_24 , V_19 -> V_64 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
T_2 V_26 , V_15 ;
if ( V_53 > 2 )
return - V_56 ;
V_26 = V_2 -> V_5 -> V_65 . V_26 ;
if ( V_53 == 0 )
V_15 = V_2 -> V_5 -> V_65 . V_57 ;
else if ( V_53 == 1 )
V_15 = V_2 -> V_5 -> V_65 . V_66 ;
else
V_15 = V_2 -> V_5 -> V_65 . V_67 ;
if ( V_26 )
F_4 ( ( F_3 ( V_7 ) & ~ V_26 ) | ( V_15 & V_26 ) , V_7 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_68 = 0 ;
if ( V_2 -> V_5 -> V_17 )
V_68 = 1 << V_2 -> V_5 -> V_17 ;
if ( ( V_2 -> V_5 -> V_69 . V_70 | V_68 ) == 0 )
return 0 ;
F_2 ( L_4 ,
F_3 ( V_8 ) , F_3 ( V_7 ) ) ;
F_4 ( V_2 -> V_5 -> V_69 . V_71 | V_68 , V_7 ) ;
F_4 ( V_2 -> V_5 -> V_69 . V_70 | V_68 , V_8 ) ;
F_22 ( & V_2 -> V_20 , & V_72 ) ;
snprintf ( V_2 -> V_20 . V_64 , sizeof( V_2 -> V_20 . V_64 ) , L_5 , V_2 -> V_73 . V_64 ) ;
V_2 -> V_20 . V_74 = V_75 ;
F_23 ( & V_2 -> V_24 , 1 ) ;
F_24 ( & V_2 -> V_24 , & V_76 ,
V_60 , 0 , 1 , 1 , 0 ) ;
if ( V_2 -> V_24 . error )
return V_2 -> V_24 . error ;
V_2 -> V_20 . V_77 = & V_2 -> V_24 ;
F_25 ( & V_2 -> V_24 ) ;
return F_26 ( & V_2 -> V_73 , & V_2 -> V_20 ) ;
}
