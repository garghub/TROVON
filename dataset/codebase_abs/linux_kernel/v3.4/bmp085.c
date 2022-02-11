static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_4 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & ( V_6 -> V_9 ) ;
T_1 V_10 = F_3 ( V_2 ,
V_11 ,
V_4 * sizeof( T_2 ) ,
( V_12 * ) V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 != V_4 * sizeof( T_2 ) )
return - V_13 ;
V_8 -> V_14 = F_4 ( V_3 [ 0 ] ) ;
V_8 -> V_15 = F_4 ( V_3 [ 1 ] ) ;
V_8 -> V_16 = F_4 ( V_3 [ 2 ] ) ;
V_8 -> V_17 = F_4 ( V_3 [ 3 ] ) ;
V_8 -> V_18 = F_4 ( V_3 [ 4 ] ) ;
V_8 -> V_19 = F_4 ( V_3 [ 5 ] ) ;
V_8 -> V_20 = F_4 ( V_3 [ 6 ] ) ;
V_8 -> V_21 = F_4 ( V_3 [ 7 ] ) ;
V_8 -> V_22 = F_4 ( V_3 [ 8 ] ) ;
V_8 -> V_23 = F_4 ( V_3 [ 9 ] ) ;
V_8 -> V_24 = F_4 ( V_3 [ 10 ] ) ;
return 0 ;
}
static T_1 F_5 ( struct V_5 * V_6 )
{
T_2 V_3 ;
T_1 V_10 ;
F_6 ( & V_6 -> V_25 ) ;
V_10 = F_7 ( V_6 -> V_2 , V_26 ,
V_27 ) ;
if ( V_10 != 0 ) {
F_8 ( & V_6 -> V_2 -> V_28 ,
L_1 ) ;
goto exit;
}
F_9 ( V_29 ) ;
V_10 = F_3 ( V_6 -> V_2 ,
V_30 , sizeof( V_3 ) , ( V_12 * ) & V_3 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_10 != sizeof( V_3 ) ) {
F_8 ( & V_6 -> V_2 -> V_28 ,
L_2 ) ;
V_10 = - V_13 ;
goto exit;
}
V_6 -> V_31 = F_4 ( V_3 ) ;
V_6 -> V_32 = V_33 ;
V_10 = 0 ;
exit:
F_10 ( & V_6 -> V_25 ) ;
return V_10 ;
}
static T_1 F_11 ( struct V_5 * V_6 )
{
T_3 V_3 = 0 ;
T_1 V_10 ;
F_6 ( & V_6 -> V_25 ) ;
V_10 = F_7 ( V_6 -> V_2 , V_26 ,
V_34 + ( V_6 -> V_35 << 6 ) ) ;
if ( V_10 != 0 ) {
F_8 ( & V_6 -> V_2 -> V_28 ,
L_3 ) ;
goto exit;
}
F_9 ( 2 + ( 3 << V_6 -> V_35 ) ) ;
V_10 = F_3 ( V_6 -> V_2 ,
V_30 , 3 , ( ( V_12 * ) & V_3 ) + 1 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_10 != 3 ) {
F_8 ( & V_6 -> V_2 -> V_28 ,
L_4 ) ;
V_10 = - V_13 ;
goto exit;
}
V_6 -> V_36 = F_12 ( ( V_3 ) ) ;
V_6 -> V_36 >>= ( 8 - V_6 -> V_35 ) ;
V_10 = 0 ;
exit:
F_10 ( & V_6 -> V_25 ) ;
return V_10 ;
}
static T_1 F_13 ( struct V_5 * V_6 , int * V_37 )
{
struct V_7 * V_8 = & V_6 -> V_9 ;
long V_38 , V_39 ;
int V_10 ;
V_10 = F_5 ( V_6 ) ;
if ( V_10 != 0 )
goto exit;
V_38 = ( ( V_6 -> V_31 - V_8 -> V_19 ) * V_8 -> V_18 ) >> 15 ;
V_39 = ( V_8 -> V_23 << 11 ) / ( V_38 + V_8 -> V_24 ) ;
V_6 -> V_40 = V_38 + V_39 - 4000 ;
if ( V_37 != NULL )
* V_37 = ( V_38 + V_39 + 8 ) >> 4 ;
exit:
return V_10 ;
}
static T_1 F_14 ( struct V_5 * V_6 , int * V_41 )
{
struct V_7 * V_8 = & V_6 -> V_9 ;
T_1 V_38 , V_39 , V_42 , V_43 ;
T_3 V_44 , V_45 ;
T_1 V_46 ;
int V_10 ;
if ( V_6 -> V_32 == 0 ||
F_15 ( V_6 -> V_32 + 1 * V_47 ) ) {
V_10 = F_13 ( V_6 , NULL ) ;
if ( V_10 != 0 )
goto exit;
}
V_10 = F_11 ( V_6 ) ;
if ( V_10 != 0 )
goto exit;
V_38 = ( V_6 -> V_40 * V_6 -> V_40 ) >> 12 ;
V_38 *= V_8 -> V_21 ;
V_38 >>= 11 ;
V_39 = V_8 -> V_15 * V_6 -> V_40 ;
V_39 >>= 11 ;
V_42 = V_38 + V_39 ;
V_43 = ( ( ( ( ( T_1 ) V_8 -> V_14 ) * 4 + V_42 ) << V_6 -> V_35 ) + 2 ) ;
V_43 >>= 2 ;
V_38 = ( V_8 -> V_16 * V_6 -> V_40 ) >> 13 ;
V_39 = ( V_8 -> V_20 * ( ( V_6 -> V_40 * V_6 -> V_40 ) >> 12 ) ) >> 16 ;
V_42 = ( V_38 + V_39 + 2 ) >> 2 ;
V_44 = ( V_8 -> V_17 * ( T_3 ) ( V_42 + 32768 ) ) >> 15 ;
V_45 = ( ( T_3 ) V_6 -> V_36 - V_43 ) *
( 50000 >> V_6 -> V_35 ) ;
V_46 = ( ( V_45 < 0x80000000 ) ? ( ( V_45 << 1 ) / V_44 ) : ( ( V_45 / V_44 ) * 2 ) ) ;
V_38 = V_46 >> 8 ;
V_38 *= V_38 ;
V_38 = ( V_38 * 3038 ) >> 16 ;
V_39 = ( - 7357 * V_46 ) >> 16 ;
V_46 += ( V_38 + V_39 + 3791 ) >> 4 ;
* V_41 = V_46 ;
exit:
return V_10 ;
}
static void F_16 ( struct V_5 * V_6 ,
unsigned char V_48 )
{
if ( V_48 > 3 )
V_48 = 3 ;
V_6 -> V_35 = V_48 ;
}
static unsigned char F_17 ( struct V_5 * V_6 )
{
return V_6 -> V_35 ;
}
static T_4 F_18 ( struct V_49 * V_28 ,
struct V_50 * V_51 ,
const char * V_52 , T_5 V_53 )
{
struct V_1 * V_2 = F_19 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_48 ;
int V_54 = F_20 ( V_52 , 10 , & V_48 ) ;
if ( V_54 == 0 ) {
F_16 ( V_6 , V_48 ) ;
return V_53 ;
}
return V_54 ;
}
static T_4 F_21 ( struct V_49 * V_28 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_1 * V_2 = F_19 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_52 , L_5 , F_17 ( V_6 ) ) ;
}
static T_4 F_22 ( struct V_49 * V_28 ,
struct V_50 * V_51 , char * V_52 )
{
int V_37 ;
int V_10 ;
struct V_1 * V_2 = F_19 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_10 = F_13 ( V_6 , & V_37 ) ;
if ( V_10 != 0 )
return V_10 ;
else
return sprintf ( V_52 , L_6 , V_37 ) ;
}
static T_4 F_23 ( struct V_49 * V_28 ,
struct V_50 * V_51 , char * V_52 )
{
int V_41 ;
int V_10 ;
struct V_1 * V_2 = F_19 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_10 = F_14 ( V_6 , & V_41 ) ;
if ( V_10 != 0 )
return V_10 ;
else
return sprintf ( V_52 , L_6 , V_41 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( V_2 -> V_57 != V_58 )
return - V_59 ;
if ( F_25 ( V_2 , V_60 ) != V_61 )
return - V_59 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned char V_62 ;
int V_10 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 != 0 )
goto exit;
V_62 = F_25 ( V_2 , V_63 ) ;
V_6 -> V_32 = 0 ;
V_6 -> V_35 = 3 ;
F_27 ( & V_6 -> V_25 ) ;
F_28 ( & V_6 -> V_2 -> V_28 , L_7 ,
( V_62 & 0x0F ) , ( V_62 & 0xF0 ) >> 4 ) ;
exit:
return V_10 ;
}
static int T_6 F_29 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 ;
int V_66 = 0 ;
V_6 = F_30 ( sizeof( struct V_5 ) , V_67 ) ;
if ( ! V_6 ) {
V_66 = - V_68 ;
goto exit;
}
V_6 -> V_35 = 0x00 ;
F_31 ( V_2 , V_6 ) ;
V_66 = F_26 ( V_2 ) ;
if ( V_66 != 0 )
goto V_69;
V_66 = F_32 ( & V_2 -> V_28 . V_70 , & V_71 ) ;
if ( V_66 )
goto V_69;
F_28 ( & V_6 -> V_2 -> V_28 , L_8 ) ;
goto exit;
V_69:
F_33 ( V_6 ) ;
exit:
return V_66 ;
}
static int T_7 F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_28 . V_70 , & V_71 ) ;
F_33 ( F_2 ( V_2 ) ) ;
return 0 ;
}
