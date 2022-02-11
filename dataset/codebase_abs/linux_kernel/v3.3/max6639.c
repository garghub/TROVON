static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
int V_8 ;
int V_9 ;
F_4 ( & V_6 -> V_10 ) ;
if ( F_5 ( V_11 , V_6 -> V_12 + 2 * V_13 ) || ! V_6 -> V_14 ) {
int V_15 ;
F_6 ( & V_5 -> V_3 , L_1 ) ;
V_9 = F_7 ( V_5 ,
V_16 ) ;
if ( V_9 < 0 ) {
V_7 = F_8 ( V_9 ) ;
goto abort;
}
V_6 -> V_17 = V_9 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_15 = F_7 ( V_5 ,
F_9 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_8 ( V_15 ) ;
goto abort;
}
V_6 -> V_18 [ V_8 ] = V_15 ;
V_15 = F_7 ( V_5 ,
F_10 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_8 ( V_15 ) ;
goto abort;
}
V_6 -> V_19 [ V_8 ] = V_15 >> 5 ;
V_6 -> V_20 [ V_8 ] = V_15 & 0x01 ;
V_15 = F_7 ( V_5 ,
F_11 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_8 ( V_15 ) ;
goto abort;
}
V_6 -> V_19 [ V_8 ] |= V_15 << 3 ;
}
V_6 -> V_12 = V_11 ;
V_6 -> V_14 = 1 ;
}
abort:
F_12 ( & V_6 -> V_10 ) ;
return V_7 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
long V_19 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
V_19 = V_6 -> V_19 [ V_25 -> V_26 ] * 125 ;
return sprintf ( V_23 , L_2 , V_19 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_23 , L_3 , V_6 -> V_20 [ V_25 -> V_26 ] ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
return sprintf ( V_23 , L_3 , ( V_6 -> V_27 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_19 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_20 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_27 [ V_25 -> V_26 ] = F_21 ( V_29 ) ;
F_22 ( V_5 ,
F_23 ( V_25 -> V_26 ) ,
V_6 -> V_27 [ V_25 -> V_26 ] ) ;
F_12 ( & V_6 -> V_10 ) ;
return V_28 ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
return sprintf ( V_23 , L_3 , ( V_6 -> V_30 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_25 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_20 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_30 [ V_25 -> V_26 ] = F_21 ( V_29 ) ;
F_22 ( V_5 ,
F_26 ( V_25 -> V_26 ) ,
V_6 -> V_30 [ V_25 -> V_26 ] ) ;
F_12 ( & V_6 -> V_10 ) ;
return V_28 ;
}
static T_1 F_27 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
return sprintf ( V_23 , L_3 , ( V_6 -> V_31 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_28 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_20 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_31 [ V_25 -> V_26 ] = F_21 ( V_29 ) ;
F_22 ( V_5 ,
F_29 ( V_25 -> V_26 ) ,
V_6 -> V_31 [ V_25 -> V_26 ] ) ;
F_12 ( & V_6 -> V_10 ) ;
return V_28 ;
}
static T_1 F_30 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
return sprintf ( V_23 , L_3 , V_6 -> V_32 [ V_25 -> V_26 ] * 255 / 120 ) ;
}
static T_1 F_31 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_20 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
V_29 = F_32 ( V_29 , 0 , 255 ) ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_32 [ V_25 -> V_26 ] = ( V_33 ) ( V_29 * 120 / 255 ) ;
F_22 ( V_5 ,
F_33 ( V_25 -> V_26 ) ,
V_6 -> V_32 [ V_25 -> V_26 ] ) ;
F_12 ( & V_6 -> V_10 ) ;
return V_28 ;
}
static T_1 F_34 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_23 , L_3 , F_35 ( V_6 -> V_18 [ V_25 -> V_26 ] ,
V_6 -> V_34 ) ) ;
}
static T_1 F_36 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_14 ( V_22 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_23 , L_3 , ! ! ( V_6 -> V_17 & ( 1 << V_25 -> V_26 ) ) ) ;
}
static int F_37 ( int V_35 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_38 ( V_36 ) ; V_8 ++ ) {
if ( V_36 [ V_8 ] == V_35 )
return V_8 ;
}
return 1 ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_37 * V_38 =
V_5 -> V_3 . V_39 ;
int V_8 ;
int V_34 = 1 ;
int V_40 ;
V_40 = F_22 ( V_5 , V_41 ,
V_42 ) ;
if ( V_40 )
goto exit;
if ( V_38 && V_38 -> V_43 > 0 &&
V_38 -> V_43 < 5 )
V_6 -> V_43 = V_38 -> V_43 ;
else
V_6 -> V_43 = 2 ;
V_6 -> V_43 -= 1 ;
if ( V_38 )
V_34 = F_37 ( V_38 -> V_34 ) ;
V_6 -> V_34 = V_34 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_40 = F_22 ( V_5 ,
F_40 ( V_8 ) ,
V_6 -> V_43 << 6 ) ;
if ( V_40 )
goto exit;
V_40 = F_22 ( V_5 ,
F_41 ( V_8 ) ,
V_44 | V_34 ) ;
if ( V_40 )
goto exit;
if ( V_38 && V_38 -> V_45 == 0 )
V_40 = F_22 ( V_5 ,
F_42 ( V_8 ) , 0x00 ) ;
else
V_40 = F_22 ( V_5 ,
F_42 ( V_8 ) , 0x02 ) ;
if ( V_40 )
goto exit;
V_40 = F_22 ( V_5 ,
F_43 ( V_8 ) ,
V_46 | 0x03 ) ;
if ( V_40 )
goto exit;
V_6 -> V_27 [ V_8 ] = 80 ;
V_6 -> V_30 [ V_8 ] = 90 ;
V_6 -> V_31 [ V_8 ] = 100 ;
V_40 = F_22 ( V_5 ,
F_23 ( V_8 ) ,
V_6 -> V_27 [ V_8 ] ) ;
if ( V_40 )
goto exit;
V_40 = F_22 ( V_5 ,
F_26 ( V_8 ) ,
V_6 -> V_30 [ V_8 ] ) ;
if ( V_40 )
goto exit;
V_40 = F_22 ( V_5 ,
F_29 ( V_8 ) , V_6 -> V_31 [ V_8 ] ) ;
if ( V_40 )
goto exit;
V_6 -> V_32 [ V_8 ] = 120 ;
V_40 = F_22 ( V_5 ,
F_33 ( V_8 ) , V_6 -> V_32 [ V_8 ] ) ;
if ( V_40 )
goto exit;
}
V_40 = F_22 ( V_5 , V_41 ,
V_47 | V_48 |
V_49 ) ;
exit:
return V_40 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = V_5 -> V_53 ;
int V_54 , V_55 ;
if ( ! F_45 ( V_53 , V_56 ) )
return - V_57 ;
V_54 = F_7 ( V_5 , V_58 ) ;
V_55 = F_7 ( V_5 , V_59 ) ;
if ( V_54 != 0x58 || V_55 != 0x4D )
return - V_57 ;
F_46 ( V_51 -> type , L_4 , V_60 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 ,
const struct V_61 * V_62 )
{
struct V_1 * V_6 ;
int V_40 ;
V_6 = F_48 ( sizeof( struct V_1 ) , V_63 ) ;
if ( ! V_6 ) {
V_40 = - V_64 ;
goto exit;
}
F_49 ( V_5 , V_6 ) ;
F_50 ( & V_6 -> V_10 ) ;
V_40 = F_39 ( V_5 ) ;
if ( V_40 < 0 )
goto V_65;
V_40 = F_51 ( & V_5 -> V_3 . V_66 , & V_67 ) ;
if ( V_40 )
goto V_65;
V_6 -> V_68 = F_52 ( & V_5 -> V_3 ) ;
if ( F_15 ( V_6 -> V_68 ) ) {
V_40 = F_16 ( V_6 -> V_68 ) ;
goto V_69;
}
F_53 ( & V_5 -> V_3 , L_5 ) ;
return 0 ;
V_69:
F_54 ( & V_5 -> V_3 . V_66 , & V_67 ) ;
V_65:
F_55 ( V_6 ) ;
exit:
return V_40 ;
}
static int F_56 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_57 ( V_6 -> V_68 ) ;
F_54 ( & V_5 -> V_3 . V_66 , & V_67 ) ;
F_55 ( V_6 ) ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 , T_3 V_70 )
{
int V_6 = F_7 ( V_5 , V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_22 ( V_5 ,
V_41 , V_6 | V_71 ) ;
}
static int F_59 ( struct V_4 * V_5 )
{
int V_6 = F_7 ( V_5 , V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_22 ( V_5 ,
V_41 , V_6 & ~ V_71 ) ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_72 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_72 ) ;
}
