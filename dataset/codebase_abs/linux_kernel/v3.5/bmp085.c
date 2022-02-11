static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_4 ] ;
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
T_1 V_8 = F_2 ( V_2 -> V_9 ,
V_10 , ( V_11 * ) V_3 ,
( V_4 << 1 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_12 = F_3 ( V_3 [ 0 ] ) ;
V_6 -> V_13 = F_3 ( V_3 [ 1 ] ) ;
V_6 -> V_14 = F_3 ( V_3 [ 2 ] ) ;
V_6 -> V_15 = F_3 ( V_3 [ 3 ] ) ;
V_6 -> V_16 = F_3 ( V_3 [ 4 ] ) ;
V_6 -> V_17 = F_3 ( V_3 [ 5 ] ) ;
V_6 -> V_18 = F_3 ( V_3 [ 6 ] ) ;
V_6 -> V_19 = F_3 ( V_3 [ 7 ] ) ;
V_6 -> V_20 = F_3 ( V_3 [ 8 ] ) ;
V_6 -> V_21 = F_3 ( V_3 [ 9 ] ) ;
V_6 -> V_22 = F_3 ( V_3 [ 10 ] ) ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_3 ;
T_1 V_8 ;
F_5 ( & V_2 -> V_23 ) ;
V_8 = F_6 ( V_2 -> V_9 , V_24 ,
V_25 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_26 ,
L_1 ) ;
goto exit;
}
F_8 ( V_27 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_28 ,
& V_3 , sizeof( V_3 ) ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_26 ,
L_2 ) ;
goto exit;
}
V_2 -> V_29 = F_3 ( V_3 ) ;
V_2 -> V_30 = V_31 ;
V_8 = 0 ;
exit:
F_9 ( & V_2 -> V_23 ) ;
return V_8 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_3 V_3 = 0 ;
T_1 V_8 ;
F_5 ( & V_2 -> V_23 ) ;
V_8 = F_6 ( V_2 -> V_9 , V_24 ,
V_32 +
( V_2 -> V_33 << 6 ) ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_26 ,
L_3 ) ;
goto exit;
}
F_8 ( 2 + ( 3 << V_2 -> V_33 ) ) ;
V_8 = F_2 ( V_2 -> V_9 , V_28 ,
( ( V_11 * ) & V_3 ) + 1 , 3 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 -> V_26 ,
L_4 ) ;
goto exit;
}
V_2 -> V_34 = F_11 ( ( V_3 ) ) ;
V_2 -> V_34 >>= ( 8 - V_2 -> V_33 ) ;
V_8 = 0 ;
exit:
F_9 ( & V_2 -> V_23 ) ;
return V_8 ;
}
static T_1 F_12 ( struct V_1 * V_2 , int * V_35 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
long V_36 , V_37 ;
int V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 < 0 )
goto exit;
V_36 = ( ( V_2 -> V_29 - V_6 -> V_17 ) * V_6 -> V_16 ) >> 15 ;
V_37 = ( V_6 -> V_21 << 11 ) / ( V_36 + V_6 -> V_22 ) ;
V_2 -> V_38 = V_36 + V_37 - 4000 ;
if ( V_35 != NULL )
* V_35 = ( V_36 + V_37 + 8 ) >> 4 ;
exit:
return V_8 ;
}
static T_1 F_13 ( struct V_1 * V_2 , int * V_39 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
T_1 V_36 , V_37 , V_40 , V_41 ;
T_3 V_42 , V_43 ;
T_1 V_44 ;
int V_8 ;
if ( ( V_2 -> V_30 == 0 ) ||
F_14 ( V_2 -> V_30 + 1 * V_45 ) ) {
V_8 = F_12 ( V_2 , NULL ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_10 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_36 = ( V_2 -> V_38 * V_2 -> V_38 ) >> 12 ;
V_36 *= V_6 -> V_19 ;
V_36 >>= 11 ;
V_37 = V_6 -> V_13 * V_2 -> V_38 ;
V_37 >>= 11 ;
V_40 = V_36 + V_37 ;
V_41 = ( ( ( ( ( T_1 ) V_6 -> V_12 ) * 4 + V_40 ) << V_2 -> V_33 ) + 2 ) ;
V_41 >>= 2 ;
V_36 = ( V_6 -> V_14 * V_2 -> V_38 ) >> 13 ;
V_37 = ( V_6 -> V_18 * ( ( V_2 -> V_38 * V_2 -> V_38 ) >> 12 ) ) >> 16 ;
V_40 = ( V_36 + V_37 + 2 ) >> 2 ;
V_42 = ( V_6 -> V_15 * ( T_3 ) ( V_40 + 32768 ) ) >> 15 ;
V_43 = ( ( T_3 ) V_2 -> V_34 - V_41 ) *
( 50000 >> V_2 -> V_33 ) ;
V_44 = ( ( V_43 < 0x80000000 ) ? ( ( V_43 << 1 ) / V_42 ) : ( ( V_43 / V_42 ) * 2 ) ) ;
V_36 = V_44 >> 8 ;
V_36 *= V_36 ;
V_36 = ( V_36 * 3038 ) >> 16 ;
V_37 = ( - 7357 * V_44 ) >> 16 ;
V_44 += ( V_36 + V_37 + 3791 ) >> 4 ;
* V_39 = V_44 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned char V_46 )
{
if ( V_46 > 3 )
V_46 = 3 ;
V_2 -> V_33 = V_46 ;
}
static unsigned char F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static T_4 F_17 ( struct V_47 * V_26 ,
struct V_48 * V_49 ,
const char * V_50 , T_5 V_51 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
unsigned long V_46 ;
int V_52 = F_19 ( V_50 , 10 , & V_46 ) ;
if ( V_52 == 0 ) {
F_5 ( & V_2 -> V_23 ) ;
F_15 ( V_2 , V_46 ) ;
F_9 ( & V_2 -> V_23 ) ;
return V_51 ;
}
return V_52 ;
}
static T_4 F_20 ( struct V_47 * V_26 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
return sprintf ( V_50 , L_5 , F_16 ( V_2 ) ) ;
}
static T_4 F_21 ( struct V_47 * V_26 ,
struct V_48 * V_49 , char * V_50 )
{
int V_35 ;
int V_8 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_8 = F_12 ( V_2 , & V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
else
return sprintf ( V_50 , L_6 , V_35 ) ;
}
static T_4 F_22 ( struct V_47 * V_26 ,
struct V_48 * V_49 , char * V_50 )
{
int V_39 ;
int V_8 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_8 = F_13 ( V_2 , & V_39 ) ;
if ( V_8 < 0 )
return V_8 ;
else
return sprintf ( V_50 , L_6 , V_39 ) ;
}
int F_23 ( struct V_47 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
unsigned int V_53 ;
int V_54 ;
V_54 = F_24 ( V_2 -> V_9 , V_55 , & V_53 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_53 != V_2 -> V_56 )
return - V_57 ;
return 0 ;
}
static void T_6 F_25 ( struct V_1 * V_2 )
{
#ifdef F_26
struct V_58 * V_59 = V_2 -> V_26 -> V_60 ;
T_3 V_61 ;
if ( ! V_59 )
return;
if ( ! F_27 ( V_59 , L_7 , & V_61 ) )
V_2 -> V_56 = V_61 & 0xff ;
if ( ! F_27 ( V_59 , L_8 , & V_61 ) )
V_2 -> V_62 = ( V_61 / 100 ) * V_45 ;
if ( ! F_27 ( V_59 , L_9 , & V_61 ) )
V_2 -> V_33 = V_61 & 0xff ;
#endif
}
static int F_28 ( struct V_1 * V_2 )
{
int V_8 = F_1 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_56 = V_63 ;
V_2 -> V_30 = 0 ;
V_2 -> V_62 = 1 * V_45 ;
V_2 -> V_33 = 3 ;
F_25 ( V_2 ) ;
F_29 ( & V_2 -> V_23 ) ;
return 0 ;
}
T_7 int F_30 ( struct V_47 * V_26 , struct V_9 * V_9 )
{
struct V_1 * V_2 ;
int V_52 = 0 ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 ) {
V_52 = - V_65 ;
goto exit;
}
F_32 ( V_26 , V_2 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_9 = V_9 ;
V_52 = F_28 ( V_2 ) ;
if ( V_52 < 0 )
goto V_66;
V_52 = F_23 ( V_26 ) ;
if ( V_52 < 0 ) {
F_7 ( V_26 , L_10 , V_67 ) ;
goto V_66;
}
V_52 = F_33 ( & V_26 -> V_68 , & V_69 ) ;
if ( V_52 )
goto V_66;
F_34 ( V_26 , L_11 , V_67 ) ;
return 0 ;
V_66:
F_35 ( V_2 ) ;
exit:
return V_52 ;
}
int F_36 ( struct V_47 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_37 ( & V_2 -> V_26 -> V_68 , & V_69 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
