static inline void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned F_3 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
unsigned V_7 ;
int V_8 ;
if ( ( F_3 ( V_2 , V_9 ) & 0x1 ) == 0 &&
( F_3 ( V_2 , V_10 ) & 0x1 ) == 0 ) {
F_6 ( V_2 -> V_11 ) ;
F_6 ( V_2 -> V_12 ) ;
F_6 ( V_2 -> V_13 ) ;
F_1 ( V_2 , V_14 , 1 ) ;
}
if ( V_6 == V_15 )
V_7 = V_9 ;
else
V_7 = V_10 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_1 ( V_2 , V_7 + ( V_8 * 4 ) , 1 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 )
{
unsigned V_7 ;
int V_8 ;
if ( V_6 == V_15 )
V_7 = V_9 ;
else
V_7 = V_10 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_1 ( V_2 , V_7 + ( V_8 * 4 ) , 0 ) ;
if ( ( F_3 ( V_2 , V_9 ) & 0x1 ) == 0 &&
( F_3 ( V_2 , V_10 ) & 0x1 ) == 0 ) {
F_1 ( V_2 , V_14 , 0 ) ;
F_8 ( V_2 -> V_13 ) ;
F_8 ( V_2 -> V_12 ) ;
F_8 ( V_2 -> V_11 ) ;
}
}
static int F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
struct V_18 * V_23 = V_21 -> V_23 ;
F_11 ( V_23 , V_17 ,
& V_2 -> V_24 [ V_17 -> V_6 ] ) ;
return 0 ;
}
static void F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_7 ( V_2 , V_17 -> V_6 ) ;
}
static int F_13 ( struct V_18 * V_23 ,
unsigned int V_25 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
unsigned int V_26 , V_27 ;
V_26 = F_3 ( V_2 , V_28 ) ;
V_27 = F_3 ( V_2 , V_29 ) ;
switch ( V_25 & V_30 ) {
case V_31 :
V_26 |= V_32 ;
V_27 &= ~ V_33 ;
break;
case V_34 :
V_26 &= ~ V_32 ;
V_27 &= ~ V_33 ;
break;
case V_35 :
V_26 &= ~ V_32 ;
V_27 |= V_33 ;
break;
default:
return - V_36 ;
}
switch ( V_25 & V_37 ) {
case V_38 :
V_26 |= V_39 ;
break;
case V_40 :
V_26 &= ~ V_39 ;
break;
default:
return - V_36 ;
}
switch ( V_25 & V_41 ) {
case V_42 :
V_26 &= ~ ( V_43 | V_32 ) ;
break;
case V_44 :
V_26 &= ~ V_43 ;
V_26 |= V_32 ;
break;
case V_45 :
V_26 |= V_43 ;
V_26 &= ~ V_32 ;
break;
case V_46 :
V_26 |= V_43 | V_32 ;
break;
}
F_1 ( V_2 , V_28 , V_26 ) ;
F_1 ( V_2 , V_47 , V_26 ) ;
F_1 ( V_2 , V_29 , V_27 ) ;
F_1 ( V_2 , V_48 , V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned V_51 , div , V_52 , V_53 ;
int V_54 ;
switch ( F_15 ( V_50 ) ) {
case V_55 :
V_51 = V_56 ;
break;
case V_57 :
V_51 = V_58 ;
break;
case V_59 :
V_51 = V_60 ;
break;
default:
return - V_36 ;
}
if ( V_17 -> V_6 == V_15 )
F_1 ( V_2 , V_61 , V_51 ) ;
else
F_1 ( V_2 , V_62 , V_51 ) ;
div = F_16 ( V_2 -> V_11 ) / F_17 ( V_50 ) ;
V_52 = 4 ;
if ( div > ( 256 + 512 ) / 2 ) {
V_53 = 128 ;
} else {
V_53 = 64 ;
if ( div < ( 128 + 256 ) / 2 )
V_52 = 2 ;
}
V_54 = F_18 ( V_2 -> V_12 , F_16 ( V_2 -> V_11 ) / V_52 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_18 ( V_2 -> V_13 , F_16 ( V_2 -> V_12 ) / V_53 ) ;
if ( V_54 )
return V_54 ;
F_5 ( V_2 , V_17 -> V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_23 , int V_63 ,
unsigned int V_64 , int V_65 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
if ( V_65 == V_66 || V_63 != 0 )
return - V_36 ;
return F_18 ( V_2 -> V_11 , V_64 ) ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( ! V_19 -> V_67 )
return 0 ;
F_7 ( V_2 , V_15 ) ;
F_7 ( V_2 , V_68 ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( ! V_19 -> V_67 )
return 0 ;
F_5 ( V_2 , V_15 ) ;
F_5 ( V_2 , V_68 ) ;
return 0 ;
}
static int F_22 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
int V_54 ;
V_2 = F_23 ( & V_70 -> V_73 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_72 = F_24 ( V_70 , V_76 , 0 ) ;
if ( ! V_72 )
return - V_77 ;
V_2 -> V_5 = F_25 ( & V_70 -> V_73 , V_72 ) ;
if ( F_26 ( V_2 -> V_5 ) )
return F_27 ( V_2 -> V_5 ) ;
V_2 -> V_11 = F_28 ( & V_70 -> V_73 , L_1 ) ;
if ( F_26 ( V_2 -> V_11 ) ) {
V_54 = F_27 ( V_2 -> V_11 ) ;
goto V_78;
}
V_2 -> V_12 = F_28 ( & V_70 -> V_73 , L_2 ) ;
if ( F_26 ( V_2 -> V_12 ) ) {
V_54 = F_27 ( V_2 -> V_12 ) ;
goto V_79;
}
V_2 -> V_13 = F_28 ( & V_70 -> V_73 , L_3 ) ;
if ( F_26 ( V_2 -> V_13 ) ) {
V_54 = F_27 ( V_2 -> V_13 ) ;
goto V_80;
}
F_29 ( & V_70 -> V_73 , V_2 ) ;
V_2 -> V_24 = V_81 ;
V_54 = F_30 ( & V_70 -> V_73 , & V_82 ) ;
if ( V_54 )
goto V_83;
return 0 ;
V_83:
F_29 ( & V_70 -> V_73 , NULL ) ;
F_31 ( V_2 -> V_13 ) ;
V_80:
F_31 ( V_2 -> V_12 ) ;
V_79:
F_31 ( V_2 -> V_11 ) ;
V_78:
return V_54 ;
}
static int F_32 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_33 ( & V_70 -> V_73 ) ;
F_34 ( & V_70 -> V_73 ) ;
F_29 ( & V_70 -> V_73 , NULL ) ;
F_31 ( V_2 -> V_13 ) ;
F_31 ( V_2 -> V_12 ) ;
F_31 ( V_2 -> V_11 ) ;
return 0 ;
}
