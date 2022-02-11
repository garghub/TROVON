static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
int V_8 ;
int V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + 2 * V_13 ) || ! V_4 -> V_14 ) {
int V_15 ;
F_5 ( & V_6 -> V_3 , L_1 ) ;
V_9 = F_6 ( V_6 ,
V_16 ) ;
if ( V_9 < 0 ) {
V_7 = F_7 ( V_9 ) ;
goto abort;
}
V_4 -> V_17 = V_9 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_15 = F_6 ( V_6 ,
F_8 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_7 ( V_15 ) ;
goto abort;
}
V_4 -> V_18 [ V_8 ] = V_15 ;
V_15 = F_6 ( V_6 ,
F_9 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_7 ( V_15 ) ;
goto abort;
}
V_4 -> V_19 [ V_8 ] = V_15 >> 5 ;
V_4 -> V_20 [ V_8 ] = V_15 & 0x01 ;
V_15 = F_6 ( V_6 ,
F_10 ( V_8 ) ) ;
if ( V_15 < 0 ) {
V_7 = F_7 ( V_15 ) ;
goto abort;
}
V_4 -> V_19 [ V_8 ] |= V_15 << 3 ;
}
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = 1 ;
}
abort:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
long V_19 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_13 ( V_22 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_19 = V_4 -> V_19 [ V_25 -> V_26 ] * 125 ;
return sprintf ( V_23 , L_2 , V_19 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_13 ( V_22 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_23 , L_3 , V_4 -> V_20 [ V_25 -> V_26 ] ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
return sprintf ( V_23 , L_3 , ( V_4 -> V_27 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_19 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_27 [ V_25 -> V_26 ] = F_20 ( V_29 ) ;
F_21 ( V_6 ,
F_22 ( V_25 -> V_26 ) ,
V_4 -> V_27 [ V_25 -> V_26 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_28 ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
return sprintf ( V_23 , L_3 , ( V_4 -> V_30 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_19 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_30 [ V_25 -> V_26 ] = F_20 ( V_29 ) ;
F_21 ( V_6 ,
F_25 ( V_25 -> V_26 ) ,
V_4 -> V_30 [ V_25 -> V_26 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_28 ;
}
static T_1 F_26 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
return sprintf ( V_23 , L_3 , ( V_4 -> V_31 [ V_25 -> V_26 ] * 1000 ) ) ;
}
static T_1 F_27 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_19 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_31 [ V_25 -> V_26 ] = F_20 ( V_29 ) ;
F_21 ( V_6 ,
F_28 ( V_25 -> V_26 ) ,
V_4 -> V_31 [ V_25 -> V_26 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_28 ;
}
static T_1 F_29 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
return sprintf ( V_23 , L_3 , V_4 -> V_32 [ V_25 -> V_26 ] * 255 / 120 ) ;
}
static T_1 F_30 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_28 )
{
struct V_24 * V_25 = F_13 ( V_22 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_29 ;
int V_15 ;
V_15 = F_19 ( V_23 , 10 , & V_29 ) ;
if ( V_15 )
return V_15 ;
V_29 = F_31 ( V_29 , 0 , 255 ) ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_32 [ V_25 -> V_26 ] = ( V_33 ) ( V_29 * 120 / 255 ) ;
F_21 ( V_6 ,
F_32 ( V_25 -> V_26 ) ,
V_4 -> V_32 [ V_25 -> V_26 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_28 ;
}
static T_1 F_33 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_13 ( V_22 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_23 , L_3 , F_34 ( V_4 -> V_18 [ V_25 -> V_26 ] ,
V_4 -> V_34 ) ) ;
}
static T_1 F_35 ( struct V_2 * V_3 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_24 * V_25 = F_13 ( V_22 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_23 , L_3 , ! ! ( V_4 -> V_17 & ( 1 << V_25 -> V_26 ) ) ) ;
}
static int F_36 ( int V_35 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_37 ( V_36 ) ; V_8 ++ ) {
if ( V_36 [ V_8 ] == V_35 )
return V_8 ;
}
return 1 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
struct V_37 * V_38 =
F_39 ( & V_6 -> V_3 ) ;
int V_8 ;
int V_34 = 1 ;
int V_39 ;
V_39 = F_21 ( V_6 , V_40 ,
V_41 ) ;
if ( V_39 )
goto exit;
if ( V_38 && V_38 -> V_42 > 0 &&
V_38 -> V_42 < 5 )
V_4 -> V_42 = V_38 -> V_42 ;
else
V_4 -> V_42 = 2 ;
V_4 -> V_42 -= 1 ;
if ( V_38 )
V_34 = F_36 ( V_38 -> V_34 ) ;
V_4 -> V_34 = V_34 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_39 = F_21 ( V_6 ,
F_40 ( V_8 ) ,
V_4 -> V_42 << 6 ) ;
if ( V_39 )
goto exit;
V_39 = F_21 ( V_6 ,
F_41 ( V_8 ) ,
V_43 | V_34 ) ;
if ( V_39 )
goto exit;
if ( V_38 && V_38 -> V_44 == 0 )
V_39 = F_21 ( V_6 ,
F_42 ( V_8 ) , 0x00 ) ;
else
V_39 = F_21 ( V_6 ,
F_42 ( V_8 ) , 0x02 ) ;
if ( V_39 )
goto exit;
V_39 = F_21 ( V_6 ,
F_43 ( V_8 ) ,
V_45 | 0x03 ) ;
if ( V_39 )
goto exit;
V_4 -> V_27 [ V_8 ] = 80 ;
V_4 -> V_30 [ V_8 ] = 90 ;
V_4 -> V_31 [ V_8 ] = 100 ;
V_39 = F_21 ( V_6 ,
F_22 ( V_8 ) ,
V_4 -> V_27 [ V_8 ] ) ;
if ( V_39 )
goto exit;
V_39 = F_21 ( V_6 ,
F_25 ( V_8 ) ,
V_4 -> V_30 [ V_8 ] ) ;
if ( V_39 )
goto exit;
V_39 = F_21 ( V_6 ,
F_28 ( V_8 ) , V_4 -> V_31 [ V_8 ] ) ;
if ( V_39 )
goto exit;
V_4 -> V_32 [ V_8 ] = 120 ;
V_39 = F_21 ( V_6 ,
F_32 ( V_8 ) , V_4 -> V_32 [ V_8 ] ) ;
if ( V_39 )
goto exit;
}
V_39 = F_21 ( V_6 , V_40 ,
V_46 | V_47 |
V_48 ) ;
exit:
return V_39 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_6 -> V_52 ;
int V_53 , V_54 ;
if ( ! F_45 ( V_52 , V_55 ) )
return - V_56 ;
V_53 = F_6 ( V_6 , V_57 ) ;
V_54 = F_6 ( V_6 , V_58 ) ;
if ( V_53 != 0x58 || V_54 != 0x4D )
return - V_56 ;
F_46 ( V_50 -> type , L_4 , V_59 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
const struct V_60 * V_61 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_62 ;
int V_39 ;
V_4 = F_48 ( V_3 , sizeof( struct V_1 ) , V_63 ) ;
if ( ! V_4 )
return - V_64 ;
V_4 -> V_6 = V_6 ;
F_49 ( & V_4 -> V_10 ) ;
V_39 = F_38 ( V_6 , V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_62 = F_50 ( V_3 , V_6 -> V_65 ,
V_4 ,
V_66 ) ;
return F_51 ( V_62 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_3 ) ;
int V_4 = F_6 ( V_6 , V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_21 ( V_6 ,
V_40 , V_4 | V_67 ) ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_3 ) ;
int V_4 = F_6 ( V_6 , V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_21 ( V_6 ,
V_40 , V_4 & ~ V_67 ) ;
}
