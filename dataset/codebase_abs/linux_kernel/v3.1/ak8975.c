static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
struct V_8 V_9 ;
T_1 V_10 [ 2 ] ;
int V_11 = 0 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
V_7 = V_13 -> V_14 [ V_3 ] ;
V_7 &= ~ V_5 ;
V_7 |= V_4 << V_6 ;
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = V_7 ;
V_9 . V_15 = V_2 -> V_15 ;
V_9 . V_16 = 0 ;
V_9 . V_17 = 2 ;
V_9 . V_18 = V_10 ;
V_11 = F_3 ( V_2 -> V_19 , & V_9 , 1 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_1 , V_11 ) ;
return V_11 ;
}
V_13 -> V_14 [ V_3 ] = V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_21 , T_1 * V_22 )
{
struct V_8 V_9 [ 2 ] ;
T_1 V_10 [ 2 ] ;
int V_11 ;
V_10 [ 0 ] = V_3 ;
V_9 [ 0 ] . V_15 = V_2 -> V_15 ;
V_9 [ 0 ] . V_16 = V_23 ;
V_9 [ 0 ] . V_17 = 1 ;
V_9 [ 0 ] . V_18 = V_10 ;
V_9 [ 1 ] . V_15 = V_2 -> V_15 ;
V_9 [ 1 ] . V_16 = V_24 ;
V_9 [ 1 ] . V_17 = V_21 ;
V_9 [ 1 ] . V_18 = V_22 ;
V_11 = F_3 ( V_2 -> V_19 , V_9 , 2 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
T_1 V_25 ;
int V_11 ;
V_11 = F_5 ( V_2 , V_26 , 1 , & V_25 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_3 ) ;
return V_11 ;
}
if ( V_25 != V_27 ) {
F_4 ( & V_2 -> V_20 , L_4 ) ;
return - V_28 ;
}
V_11 = F_1 ( V_2 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_5 ) ;
return V_11 ;
}
V_11 = F_5 ( V_2 , V_33 , 3 , V_13 -> V_34 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_6 ) ;
return V_11 ;
}
V_13 -> V_35 [ 0 ] = ( ( V_13 -> V_34 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_13 -> V_35 [ 1 ] = ( ( V_13 -> V_34 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_13 -> V_35 [ 2 ] = ( ( V_13 -> V_34 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static T_2 F_7 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = F_9 ( V_40 ) ;
return sprintf ( V_18 , L_7 , V_13 -> V_41 ) ;
}
static T_2 F_10 ( struct V_36 * V_20 , struct V_37 * V_38 ,
const char * V_18 , T_3 V_42 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = F_9 ( V_40 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_43 ;
int V_11 ;
if ( F_11 ( V_18 , 10 , & V_43 ) )
return - V_44 ;
if ( V_43 > 1 ) {
F_4 ( V_20 , L_8 ) ;
return - V_44 ;
}
F_12 ( & V_13 -> V_45 ) ;
if ( V_13 -> V_41 != V_43 ) {
V_11 = F_1 ( V_2 ,
V_29 ,
( T_1 ) V_43 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_9 ) ;
F_13 ( & V_13 -> V_45 ) ;
return V_11 ;
}
V_13 -> V_41 = V_43 ;
}
F_13 ( & V_13 -> V_45 ) ;
return V_42 ;
}
static T_2 F_14 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = F_9 ( V_40 ) ;
struct V_46 * V_47 = F_15 ( V_38 ) ;
return sprintf ( V_18 , L_10 , V_13 -> V_35 [ V_47 -> V_48 ] ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_49 ;
T_4 V_50 = V_51 ;
int V_11 ;
while ( V_50 ) {
F_17 ( V_52 ) ;
if ( F_18 ( V_13 -> V_53 ) )
break;
V_50 -= V_52 ;
}
if ( ! V_50 ) {
F_4 ( & V_2 -> V_20 , L_11 ) ;
return - V_44 ;
}
V_11 = F_5 ( V_2 , V_54 , 1 , & V_49 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_12 ) ;
return V_11 ;
}
return V_49 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_49 ;
T_4 V_50 = V_51 ;
int V_11 ;
while ( V_50 ) {
F_17 ( V_52 ) ;
V_11 = F_5 ( V_2 , V_54 , 1 , & V_49 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_12 ) ;
return V_11 ;
}
if ( V_49 )
break;
V_50 -= V_52 ;
}
if ( ! V_50 ) {
F_4 ( & V_2 -> V_20 , L_11 ) ;
return - V_44 ;
}
return V_49 ;
}
static T_2 F_20 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = F_9 ( V_40 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_46 * V_47 = F_15 ( V_38 ) ;
T_5 V_55 ;
T_6 V_56 ;
T_1 V_49 ;
int V_11 ;
F_12 ( & V_13 -> V_45 ) ;
if ( V_13 -> V_41 == 0 ) {
F_4 ( & V_2 -> V_20 , L_13 ) ;
V_11 = - V_57 ;
goto exit;
}
V_11 = F_1 ( V_2 ,
V_29 ,
V_58 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_14 ) ;
goto exit;
}
if ( V_13 -> V_53 )
V_11 = F_16 ( V_13 ) ;
else
V_11 = F_19 ( V_13 ) ;
if ( V_11 < 0 )
goto exit;
V_49 = V_11 ;
if ( V_49 & V_59 ) {
V_11 = F_5 ( V_2 , V_60 , 1 , & V_49 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_15 ) ;
goto exit;
}
if ( V_49 & ( V_61 |
V_62 ) ) {
F_4 ( & V_2 -> V_20 , L_16 ,
V_49 ) ;
V_11 = - V_44 ;
goto exit;
}
}
V_11 = F_5 ( V_2 , V_47 -> V_48 , 2 , ( T_1 * ) & V_55 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_17 ) ;
goto exit;
}
F_13 ( & V_13 -> V_45 ) ;
V_56 = ( T_6 ) ( F_21 ( V_55 ) ) ;
V_56 = F_22 ( T_6 , V_56 , - 4096 , 4095 ) ;
return sprintf ( V_18 , L_18 , V_56 ) ;
exit:
F_13 ( & V_13 -> V_45 ) ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_63 * V_64 )
{
struct V_12 * V_13 ;
struct V_39 * V_40 ;
int V_53 ;
int V_65 ;
V_53 = F_24 ( V_2 -> V_66 ) ;
if ( V_53 > 0 ) {
V_65 = F_25 ( V_53 , L_19 ) ;
if ( V_65 < 0 ) {
F_4 ( & V_2 -> V_20 ,
L_20 ,
V_53 , V_65 ) ;
goto exit;
}
V_65 = F_26 ( V_53 ) ;
if ( V_65 < 0 ) {
F_4 ( & V_2 -> V_20 ,
L_21 ,
V_53 , V_65 ) ;
goto V_67;
}
} else
V_53 = 0 ;
V_40 = F_27 ( sizeof( * V_13 ) ) ;
if ( V_40 == NULL ) {
V_65 = - V_68 ;
goto V_67;
}
V_13 = F_9 ( V_40 ) ;
V_65 = F_6 ( V_2 ) ;
if ( V_65 < 0 ) {
F_4 ( & V_2 -> V_20 , L_22 ) ;
goto V_67;
}
F_28 ( V_2 , V_40 ) ;
V_13 -> V_2 = V_2 ;
F_29 ( & V_13 -> V_45 ) ;
V_13 -> V_69 = V_2 -> V_66 ;
V_13 -> V_53 = V_53 ;
V_40 -> V_20 . V_70 = & V_2 -> V_20 ;
V_40 -> V_71 = & V_72 ;
V_40 -> V_73 = V_74 ;
V_65 = F_30 ( V_40 ) ;
if ( V_65 < 0 )
goto V_75;
return 0 ;
V_75:
F_31 ( V_40 ) ;
V_67:
if ( V_53 )
F_32 ( V_53 ) ;
exit:
return V_65 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_40 ) ;
int V_53 = V_13 -> V_53 ;
F_34 ( V_40 ) ;
F_31 ( V_40 ) ;
if ( V_53 )
F_32 ( V_53 ) ;
return 0 ;
}
static int T_7 F_35 ( void )
{
return F_36 ( & V_76 ) ;
}
static void T_8 F_37 ( void )
{
F_38 ( & V_76 ) ;
}
