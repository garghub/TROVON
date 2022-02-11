static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 |= V_6 ;
F_3 ( V_4 -> V_7 , V_8 ,
V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 &= ~ V_6 ;
F_3 ( V_4 -> V_7 , V_8 ,
V_4 -> V_5 ) ;
return 0 ;
}
static T_1 F_5 ( int V_9 , bool V_10 )
{
int V_11 = F_6 ( V_9 ,
V_10 ? V_12 :
V_13 , V_14 ) ;
return ( V_11 * 2 / 125 ) & 0x1fff ;
}
static int F_7 ( T_2 V_15 )
{
V_15 &= 0x1fff ;
if ( V_15 & 0x1000 )
V_15 |= 0xf000 ;
return V_15 * 125 / 2 ;
}
static T_3 F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
int V_9 , V_19 ;
if ( F_10 ( V_4 ) )
return F_11 ( V_4 ) ;
V_9 = F_7 ( V_4 -> V_20 ) ;
V_19 = V_21 [ ( V_4 -> V_5 & V_22 )
>> V_23 ] ;
return sprintf ( V_18 , L_1 , V_9 - V_19 ) ;
}
static T_3 F_12 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
int V_9 , V_19 ;
if ( F_10 ( V_4 ) )
return F_11 ( V_4 ) ;
V_9 = F_7 ( V_4 -> V_24 ) ;
V_19 = V_21 [ ( V_4 -> V_5 & V_22 )
>> V_23 ] ;
return sprintf ( V_18 , L_1 , V_9 - V_19 ) ;
}
static T_3 F_13 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_4 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_26 ;
int V_27 , V_19 ;
int V_28 ;
int V_29 = V_25 ;
if ( F_14 ( V_18 , 10 , & V_26 ) < 0 )
return - V_30 ;
V_27 = F_7 ( V_4 -> V_20 ) - V_26 ;
V_19 = 0 ;
if ( V_27 > 0 ) {
if ( V_27 < 2250 )
V_19 = 1 ;
else if ( V_27 < 4500 )
V_19 = 2 ;
else
V_19 = 3 ;
}
F_15 ( & V_4 -> V_31 ) ;
V_4 -> V_5 = ( V_4 -> V_5 & ~ V_22 )
| ( V_19 << V_23 ) ;
V_28 = F_3 ( V_4 -> V_7 , V_8 ,
V_4 -> V_5 ) ;
if ( V_28 < 0 )
V_29 = V_28 ;
F_16 ( & V_4 -> V_31 ) ;
return V_29 ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
T_1 V_32 = F_18 ( V_17 ) -> V_33 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
T_1 V_26 ;
if ( F_10 ( V_4 ) )
return F_11 ( V_4 ) ;
V_26 = V_4 -> V_34 ;
if ( V_32 != V_35 && ( V_4 -> V_5 & V_36 ) )
V_26 = 0 ;
return sprintf ( V_18 , L_2 , ( V_26 >> V_32 ) & 1 ) ;
}
static T_5 F_19 ( struct V_37 * V_38 ,
struct V_39 * V_17 , int V_33 )
{
struct V_1 * V_2 = F_20 ( V_38 , struct V_1 , V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = V_4 -> V_5 ;
bool V_40 ;
if ( V_17 == & V_41 . V_17 )
V_40 = V_5 & V_42 ;
else if ( V_17 == & V_43 . V_17 ||
V_17 == & V_44 . V_17 )
V_40 = V_5 & V_45 ;
else if ( V_17 == & V_46 . V_17 )
V_40 = V_5 & ( V_45 | V_42 ) ;
else
V_40 = true ;
return V_47 | ( V_40 ? 0 : V_48 ) ;
}
static int F_21 ( struct V_49 * V_7 , struct V_50 * V_51 )
{
struct V_52 * V_53 = V_7 -> V_53 ;
int V_54 , V_5 , V_55 , V_56 , V_57 ;
if ( ! F_22 ( V_53 , V_58 |
V_59 ) )
return - V_60 ;
V_55 = F_23 ( V_7 , V_61 ) ;
V_5 = F_23 ( V_7 , V_8 ) ;
V_56 = F_23 ( V_7 , V_62 ) ;
V_57 = F_23 ( V_7 , V_63 ) ;
if ( V_55 < 0 || V_5 < 0 || V_56 < 0 || V_57 < 0 )
return - V_60 ;
if ( ( V_55 & 0xff00 ) || ( V_5 & 0xf800 ) )
return - V_60 ;
for ( V_54 = 0 ; V_54 < F_24 ( V_64 ) ; V_54 ++ ) {
struct V_64 * V_65 = & V_64 [ V_54 ] ;
if ( V_56 == V_65 -> V_56 &&
( V_57 & V_65 -> V_66 ) == V_65 -> V_57 ) {
F_25 ( V_51 -> type , L_3 , V_67 ) ;
return 0 ;
}
}
return - V_60 ;
}
static int F_26 ( struct V_49 * V_7 , const struct V_68 * V_69 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_1 * V_70 ;
struct V_3 * V_4 ;
int V_5 , V_55 ;
V_4 = F_27 ( V_2 , sizeof( struct V_3 ) , V_71 ) ;
if ( ! V_4 )
return - V_72 ;
V_4 -> V_7 = V_7 ;
F_28 ( V_7 , V_4 ) ;
F_29 ( & V_4 -> V_31 ) ;
V_55 = F_23 ( V_7 , V_61 ) ;
if ( V_55 < 0 )
return V_55 ;
V_4 -> V_10 = ! ! ( V_55 & V_73 ) ;
V_5 = F_23 ( V_7 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_74 = V_5 ;
if ( V_5 & V_6 ) {
V_5 &= ~ V_6 ;
F_3 ( V_7 , V_8 , V_5 ) ;
}
V_4 -> V_5 = V_5 ;
V_70 = F_30 ( V_2 , V_7 -> V_75 ,
V_4 ,
V_76 ) ;
return F_31 ( V_70 ) ;
}
static int F_32 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_33 ( V_7 ) ;
if ( ( V_4 -> V_5 & ~ V_22 ) !=
( V_4 -> V_74 & ~ V_22 ) ) {
int V_5 ;
V_5 = ( V_4 -> V_74 & ~ V_22 )
| ( V_4 -> V_5 & V_22 ) ;
F_3 ( V_7 , V_8 , V_5 ) ;
}
return 0 ;
}
static struct V_3 * F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_49 * V_7 = V_4 -> V_7 ;
struct V_3 * V_29 = V_4 ;
int V_26 ;
F_15 ( & V_4 -> V_31 ) ;
if ( F_34 ( V_77 , V_4 -> V_78 + V_79 ) || ! V_4 -> V_80 ) {
V_26 = F_23 ( V_7 , V_81 ) ;
if ( V_26 < 0 ) {
V_29 = F_35 ( V_26 ) ;
goto abort;
}
V_4 -> V_34 = V_26 ;
V_26 = F_23 ( V_7 ,
V_82 ) ;
if ( V_26 < 0 ) {
V_29 = F_35 ( V_26 ) ;
goto abort;
}
V_4 -> V_20 = V_26 ;
V_26 = F_23 ( V_7 , V_83 ) ;
if ( V_26 < 0 ) {
V_29 = F_35 ( V_26 ) ;
goto abort;
}
V_4 -> V_84 = V_26 ;
V_26 = F_23 ( V_7 , V_85 ) ;
if ( V_26 < 0 ) {
V_29 = F_35 ( V_26 ) ;
goto abort;
}
V_4 -> V_24 = V_26 ;
V_4 -> V_78 = V_77 ;
V_4 -> V_80 = true ;
}
abort:
F_16 ( & V_4 -> V_31 ) ;
return V_29 ;
}
