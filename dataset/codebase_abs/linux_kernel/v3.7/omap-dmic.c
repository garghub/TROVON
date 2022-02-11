static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_2 V_6 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_8 ,
V_9 ) ;
F_1 ( V_2 , V_7 , V_6 | V_2 -> V_10 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_2 V_6 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 ,
V_6 & ~ V_11 ) ;
F_1 ( V_2 , V_12 ,
V_9 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_7 ) &
V_11 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_17 = 0 ;
F_10 ( & V_2 -> V_18 ) ;
if ( ! V_16 -> V_19 )
V_2 -> V_19 = 1 ;
else
V_17 = - V_20 ;
F_11 ( & V_2 -> V_18 ) ;
F_12 ( V_16 , V_14 , & V_21 ) ;
return V_17 ;
}
static void F_13 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_10 ( & V_2 -> V_18 ) ;
if ( ! V_16 -> V_19 )
V_2 -> V_19 = 0 ;
F_11 ( & V_2 -> V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_22 )
{
int V_23 = - V_24 ;
if ( V_22 == 192000 ) {
if ( V_2 -> V_25 == 19200000 && V_2 -> V_26 == 3840000 )
V_23 = 0x6 ;
else
F_15 ( V_2 -> V_27 ,
L_1 ) ;
return V_23 ;
}
switch ( V_2 -> V_26 ) {
case 1536000 :
if ( V_2 -> V_25 != 24576000 )
goto V_28;
V_23 = 0x4 ;
break;
case 2400000 :
switch ( V_2 -> V_25 ) {
case 12000000 :
V_23 = 0x5 ;
break;
case 19200000 :
V_23 = 0x0 ;
break;
case 24000000 :
V_23 = 0x2 ;
break;
default:
goto V_28;
}
break;
case 3072000 :
if ( V_2 -> V_25 != 24576000 )
goto V_28;
V_23 = 0x3 ;
break;
case 3840000 :
if ( V_2 -> V_25 != 19200000 )
goto V_28;
V_23 = 0x1 ;
break;
default:
F_15 ( V_2 -> V_27 , L_2 ,
V_2 -> V_26 ) ;
break;
}
return V_23 ;
V_28:
F_15 ( V_2 -> V_27 , L_3 ,
V_2 -> V_26 , V_2 -> V_25 ) ;
return - V_24 ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_29 * V_30 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_31 * V_32 ;
int V_33 ;
V_2 -> V_34 = F_14 ( V_2 , F_17 ( V_30 ) ) ;
if ( V_2 -> V_34 < 0 ) {
F_15 ( V_2 -> V_27 , L_4 ,
V_2 -> V_26 , V_2 -> V_25 ) ;
return - V_24 ;
}
V_2 -> V_10 = 0 ;
V_33 = F_18 ( V_30 ) ;
switch ( V_33 ) {
case 6 :
V_2 -> V_10 |= V_35 ;
case 4 :
V_2 -> V_10 |= V_36 ;
case 2 :
V_2 -> V_10 |= V_37 ;
break;
default:
F_15 ( V_2 -> V_27 , L_5 ) ;
return - V_24 ;
}
V_32 = F_19 ( V_16 , V_14 ) ;
V_32 -> V_38 = V_2 -> V_39 * V_33 ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_2 V_6 ;
F_1 ( V_2 , V_40 , V_2 -> V_39 ) ;
V_6 = F_3 ( V_2 , V_7 ) ;
V_6 &= ~ ( V_41 | V_42 ) ;
V_6 |= ( V_43 | V_44 |
V_45 | V_46 ) ;
V_6 &= ~ V_47 ;
V_6 |= F_21 ( V_2 -> V_34 ) ;
F_1 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_7 ,
V_6 | V_43 | V_44 |
V_45 | V_46 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 ,
int V_48 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
switch ( V_48 ) {
case V_49 :
F_5 ( V_2 ) ;
break;
case V_50 :
F_6 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_51 ,
unsigned int V_52 )
{
struct V_53 * V_54 ;
char * V_55 ;
int V_17 = 0 ;
switch ( V_52 ) {
case 12000000 :
case 19200000 :
case 24000000 :
case 24576000 :
break;
default:
F_15 ( V_2 -> V_27 , L_6 , V_52 ) ;
V_2 -> V_25 = 0 ;
return - V_24 ;
}
if ( V_2 -> V_56 == V_51 ) {
V_2 -> V_25 = V_52 ;
return 0 ;
}
if ( V_2 -> V_19 && F_7 ( V_2 ) ) {
F_15 ( V_2 -> V_27 , L_7 ) ;
return - V_20 ;
}
switch ( V_51 ) {
case V_57 :
V_55 = L_8 ;
break;
case V_58 :
V_55 = L_9 ;
break;
case V_59 :
V_55 = L_10 ;
break;
default:
F_15 ( V_2 -> V_27 , L_11 , V_51 ) ;
return - V_24 ;
}
V_54 = F_24 ( V_2 -> V_27 , V_55 ) ;
if ( F_25 ( V_54 ) ) {
F_15 ( V_2 -> V_27 , L_12 , V_55 ) ;
return - V_60 ;
}
F_10 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_19 ) {
F_26 ( V_2 -> V_27 ) ;
V_17 = F_27 ( V_2 -> V_61 , V_54 ) ;
F_28 ( V_2 -> V_27 ) ;
} else {
V_17 = F_27 ( V_2 -> V_61 , V_54 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
if ( V_17 < 0 ) {
F_15 ( V_2 -> V_27 , L_13 ) ;
goto V_62;
}
V_2 -> V_56 = V_51 ;
V_2 -> V_25 = V_52 ;
V_62:
F_29 ( V_54 ) ;
return V_17 ;
}
static int F_30 ( struct V_1 * V_2 , int V_51 ,
unsigned int V_52 )
{
int V_17 = 0 ;
if ( V_51 != V_63 ) {
F_15 ( V_2 -> V_27 , L_14 ,
V_51 ) ;
return - V_24 ;
}
switch ( V_52 ) {
case 1536000 :
case 2400000 :
case 3072000 :
case 3840000 :
V_2 -> V_26 = V_52 ;
break;
default:
F_15 ( V_2 -> V_27 , L_2 , V_52 ) ;
V_2 -> V_26 = 0 ;
V_17 = - V_24 ;
}
return V_17 ;
}
static int F_31 ( struct V_15 * V_16 , int V_51 ,
unsigned int V_52 , int V_64 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
if ( V_64 == V_65 )
return F_23 ( V_2 , V_51 , V_52 ) ;
else if ( V_64 == V_66 )
return F_30 ( V_2 , V_51 , V_52 ) ;
F_15 ( V_2 -> V_27 , L_15 , V_64 ) ;
return - V_24 ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_33 ( V_2 -> V_27 ) ;
F_28 ( V_2 -> V_27 ) ;
F_1 ( V_2 , V_7 , 0x00 ) ;
F_26 ( V_2 -> V_27 ) ;
V_2 -> V_39 = V_67 - 3 ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_35 ( V_2 -> V_27 ) ;
return 0 ;
}
static T_3 int F_36 ( struct V_68 * V_69 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_17 ;
V_2 = F_37 ( & V_69 -> V_27 , sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
F_38 ( V_69 , V_2 ) ;
V_2 -> V_27 = & V_69 -> V_27 ;
V_2 -> V_56 = V_59 ;
F_39 ( & V_2 -> V_18 ) ;
V_2 -> V_61 = F_24 ( V_2 -> V_27 , L_16 ) ;
if ( F_25 ( V_2 -> V_61 ) ) {
F_15 ( V_2 -> V_27 , L_17 ) ;
return - V_60 ;
}
V_71 = F_40 ( V_69 , V_74 , L_18 ) ;
if ( ! V_71 ) {
F_15 ( V_2 -> V_27 , L_19 ) ;
V_17 = - V_60 ;
goto V_75;
}
V_21 . V_76 = V_71 -> V_77 + V_78 ;
V_71 = F_41 ( V_69 , V_79 , 0 ) ;
if ( ! V_71 ) {
F_15 ( V_2 -> V_27 , L_20 ) ;
V_17 = - V_60 ;
goto V_75;
}
V_21 . V_80 = V_71 -> V_77 ;
V_71 = F_40 ( V_69 , V_74 , L_21 ) ;
if ( ! V_71 ) {
F_15 ( V_2 -> V_27 , L_22 ) ;
V_17 = - V_60 ;
goto V_75;
}
if ( ! F_42 ( & V_69 -> V_27 , V_71 -> V_77 ,
F_43 ( V_71 ) , V_69 -> V_81 ) ) {
F_15 ( V_2 -> V_27 , L_23 ) ;
V_17 = - V_60 ;
goto V_75;
}
V_2 -> V_5 = F_44 ( & V_69 -> V_27 , V_71 -> V_77 ,
F_43 ( V_71 ) ) ;
if ( ! V_2 -> V_5 ) {
V_17 = - V_73 ;
goto V_75;
}
V_17 = F_45 ( & V_69 -> V_27 , & V_82 ) ;
if ( V_17 )
goto V_75;
return 0 ;
V_75:
F_29 ( V_2 -> V_61 ) ;
return V_17 ;
}
static int T_4 F_46 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_47 ( V_69 ) ;
F_48 ( & V_69 -> V_27 ) ;
F_29 ( V_2 -> V_61 ) ;
return 0 ;
}
