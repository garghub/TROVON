static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 |= V_8 ;
F_4 ( V_4 , V_9 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 &= ~ V_8 ;
F_4 ( V_4 , V_9 , V_6 -> V_7 ) ;
return 0 ;
}
static T_1 F_6 ( int V_10 , bool V_11 )
{
int V_12 = F_7 ( V_10 ,
V_11 ? V_13 :
V_14 , V_15 ) ;
return ( V_12 * 2 / 125 ) & 0x1fff ;
}
static int F_8 ( T_2 V_16 )
{
V_16 &= 0x1fff ;
if ( V_16 & 0x1000 )
V_16 |= 0xf000 ;
return V_16 * 125 / 2 ;
}
static T_3 F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
int V_10 , V_20 ;
if ( F_11 ( V_6 ) )
return F_12 ( V_6 ) ;
V_10 = F_8 ( V_6 -> V_21 ) ;
V_20 = V_22 [ ( V_6 -> V_7 >> V_23 )
& V_24 ] ;
return sprintf ( V_19 , L_1 , V_10 - V_20 ) ;
}
static T_3 F_13 ( struct V_1 * V_2 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
int V_10 , V_20 ;
if ( F_11 ( V_6 ) )
return F_12 ( V_6 ) ;
V_10 = F_8 ( V_6 -> V_25 ) ;
V_20 = V_22 [ ( V_6 -> V_7 >> V_23 )
& V_24 ] ;
return sprintf ( V_19 , L_1 , V_10 - V_20 ) ;
}
static T_3 F_14 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const char * V_19 , T_4 V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned long V_27 ;
int V_28 , V_20 ;
int V_29 ;
int V_30 = V_26 ;
if ( F_15 ( V_19 , 10 , & V_27 ) < 0 )
return - V_31 ;
V_28 = F_8 ( V_6 -> V_21 ) - V_27 ;
V_20 = 0 ;
if ( V_28 > 0 ) {
if ( V_28 < 2250 )
V_20 = 1 ;
else if ( V_28 < 4500 )
V_20 = 2 ;
else
V_20 = 3 ;
}
F_16 ( & V_6 -> V_32 ) ;
V_6 -> V_7 = ( V_6 -> V_7
& ~ ( V_24 << V_23 ) )
| ( V_20 << V_23 ) ;
V_29 = F_4 ( V_4 , V_9 ,
V_6 -> V_7 ) ;
if ( V_29 < 0 )
V_30 = V_29 ;
F_17 ( & V_6 -> V_32 ) ;
return V_30 ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 , char * V_19 )
{
T_1 V_33 = F_19 ( V_18 ) -> V_34 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_1 V_27 ;
if ( F_11 ( V_6 ) )
return F_12 ( V_6 ) ;
V_27 = V_6 -> V_35 ;
if ( V_33 != V_36 && ( V_6 -> V_7 & V_37 ) )
V_27 = 0 ;
return sprintf ( V_19 , L_2 , ( V_27 >> V_33 ) & 1 ) ;
}
static T_5 F_20 ( struct V_38 * V_39 ,
struct V_40 * V_18 , int V_34 )
{
struct V_1 * V_2 = F_21 ( V_39 , struct V_1 , V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned int V_7 = V_6 -> V_7 ;
bool V_41 ;
if ( V_18 == & V_42 . V_18 )
V_41 = V_7 & V_43 ;
else if ( V_18 == & V_44 . V_18 ||
V_18 == & V_45 . V_18 )
V_41 = V_7 & V_46 ;
else if ( V_18 == & V_47 . V_18 )
V_41 = V_7 & ( V_46 | V_43 ) ;
else
V_41 = true ;
return V_48 | ( V_41 ? 0 : V_49 ) ;
}
static int F_22 ( struct V_3 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_50 -> V_54 ;
int V_55 , V_7 , V_56 , V_57 , V_58 ;
if ( ! F_23 ( V_54 , V_59 |
V_60 ) )
return - V_61 ;
V_56 = F_24 ( V_50 , V_62 ) ;
V_7 = F_24 ( V_50 , V_9 ) ;
V_57 = F_24 ( V_50 , V_63 ) ;
V_58 = F_24 ( V_50 , V_64 ) ;
if ( V_56 < 0 || V_7 < 0 || V_57 < 0 || V_58 < 0 )
return - V_61 ;
if ( ( V_56 & 0xff00 ) || ( V_7 & 0xf800 ) )
return - V_61 ;
for ( V_55 = 0 ; V_55 < F_25 ( V_65 ) ; V_55 ++ ) {
struct V_65 * V_66 = & V_65 [ V_55 ] ;
if ( V_57 == V_66 -> V_57 &&
( V_58 & V_66 -> V_67 ) == V_66 -> V_58 ) {
F_26 ( V_52 -> type , L_3 , V_68 ) ;
return 0 ;
}
}
return - V_61 ;
}
static int F_27 ( struct V_3 * V_50 ,
const struct V_69 * V_70 )
{
struct V_5 * V_6 ;
int V_7 , V_56 , V_29 ;
V_6 = F_28 ( sizeof( struct V_5 ) , V_71 ) ;
if ( ! V_6 ) {
V_29 = - V_72 ;
goto exit;
}
F_29 ( V_50 , V_6 ) ;
F_30 ( & V_6 -> V_32 ) ;
V_56 = F_24 ( V_50 , V_62 ) ;
if ( V_56 < 0 ) {
V_29 = - V_31 ;
goto V_73;
}
V_6 -> V_11 = ! ! ( V_56 & V_74 ) ;
V_7 = F_24 ( V_50 , V_9 ) ;
if ( V_7 < 0 ) {
V_29 = - V_31 ;
goto V_73;
}
V_6 -> V_75 = V_7 ;
if ( V_7 & V_8 ) {
V_7 &= ~ V_8 ;
F_4 ( V_50 , V_9 ,
V_7 ) ;
}
V_6 -> V_7 = V_7 ;
V_29 = F_31 ( & V_50 -> V_2 . V_39 , & V_76 ) ;
if ( V_29 )
goto V_73;
V_6 -> V_77 = F_32 ( & V_50 -> V_2 ) ;
if ( F_11 ( V_6 -> V_77 ) ) {
V_29 = F_12 ( V_6 -> V_77 ) ;
goto V_78;
}
return 0 ;
V_78:
F_33 ( & V_50 -> V_2 . V_39 , & V_76 ) ;
V_73:
F_34 ( V_6 ) ;
exit:
return V_29 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_36 ( V_6 -> V_77 ) ;
F_33 ( & V_4 -> V_2 . V_39 , & V_76 ) ;
if ( V_6 -> V_7 != V_6 -> V_75 )
F_4 ( V_4 , V_9 ,
V_6 -> V_75 ) ;
F_34 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_5 * V_30 = V_6 ;
int V_27 ;
F_16 ( & V_6 -> V_32 ) ;
if ( F_37 ( V_79 , V_6 -> V_80 + V_81 ) || ! V_6 -> V_82 ) {
V_27 = F_24 ( V_4 , V_83 ) ;
if ( V_27 < 0 ) {
V_30 = F_38 ( V_27 ) ;
goto abort;
}
V_6 -> V_35 = V_27 ;
V_27 = F_24 ( V_4 ,
V_84 ) ;
if ( V_27 < 0 ) {
V_30 = F_38 ( V_27 ) ;
goto abort;
}
V_6 -> V_21 = V_27 ;
V_27 = F_24 ( V_4 , V_85 ) ;
if ( V_27 < 0 ) {
V_30 = F_38 ( V_27 ) ;
goto abort;
}
V_6 -> V_86 = V_27 ;
V_27 = F_24 ( V_4 , V_87 ) ;
if ( V_27 < 0 ) {
V_30 = F_38 ( V_27 ) ;
goto abort;
}
V_6 -> V_25 = V_27 ;
V_6 -> V_80 = V_79 ;
V_6 -> V_82 = true ;
}
abort:
F_17 ( & V_6 -> V_32 ) ;
return V_30 ;
}
static int T_6 F_39 ( void )
{
return F_40 ( & V_88 ) ;
}
static void T_7 F_41 ( void )
{
F_42 ( & V_88 ) ;
}
