static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static T_2 F_3 ( struct V_3 * V_4 )
{
T_3 V_7 [ V_8 ] ;
struct V_9 * V_10 = & ( V_4 -> V_11 ) ;
T_2 V_12 = F_4 ( V_4 -> V_13 ,
V_14 , ( V_15 * ) V_7 ,
( V_8 << 1 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_10 -> V_16 = F_5 ( V_7 [ 0 ] ) ;
V_10 -> V_17 = F_5 ( V_7 [ 1 ] ) ;
V_10 -> V_18 = F_5 ( V_7 [ 2 ] ) ;
V_10 -> V_19 = F_5 ( V_7 [ 3 ] ) ;
V_10 -> V_20 = F_5 ( V_7 [ 4 ] ) ;
V_10 -> V_21 = F_5 ( V_7 [ 5 ] ) ;
V_10 -> V_22 = F_5 ( V_7 [ 6 ] ) ;
V_10 -> V_23 = F_5 ( V_7 [ 7 ] ) ;
V_10 -> V_24 = F_5 ( V_7 [ 8 ] ) ;
V_10 -> V_25 = F_5 ( V_7 [ 9 ] ) ;
V_10 -> V_26 = F_5 ( V_7 [ 10 ] ) ;
return 0 ;
}
static T_2 F_6 ( struct V_3 * V_4 )
{
T_3 V_7 ;
T_2 V_12 ;
F_7 ( & V_4 -> V_27 ) ;
F_8 ( & V_4 -> V_5 ) ;
V_12 = F_9 ( V_4 -> V_13 , V_28 ,
V_29 ) ;
if ( V_12 < 0 ) {
F_10 ( V_4 -> V_30 ,
L_1 ) ;
goto exit;
}
F_11 ( & V_4 -> V_5 , 1 + F_12 (
V_31 ) ) ;
V_12 = F_4 ( V_4 -> V_13 , V_32 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_12 < 0 ) {
F_10 ( V_4 -> V_30 ,
L_2 ) ;
goto exit;
}
V_4 -> V_33 = F_5 ( V_7 ) ;
V_4 -> V_34 = V_35 ;
V_12 = 0 ;
exit:
F_13 ( & V_4 -> V_27 ) ;
return V_12 ;
}
static T_2 F_14 ( struct V_3 * V_4 )
{
T_4 V_7 = 0 ;
T_2 V_12 ;
F_7 ( & V_4 -> V_27 ) ;
F_8 ( & V_4 -> V_5 ) ;
V_12 = F_9 ( V_4 -> V_13 , V_28 ,
V_36 +
( V_4 -> V_37 << 6 ) ) ;
if ( V_12 < 0 ) {
F_10 ( V_4 -> V_30 ,
L_3 ) ;
goto exit;
}
F_11 ( & V_4 -> V_5 , 1 + F_12 (
2 + ( 3 << V_4 -> V_37 ) ) ) ;
V_12 = F_4 ( V_4 -> V_13 , V_32 ,
( ( V_15 * ) & V_7 ) + 1 , 3 ) ;
if ( V_12 < 0 ) {
F_10 ( V_4 -> V_30 ,
L_4 ) ;
goto exit;
}
V_4 -> V_38 = F_15 ( ( V_7 ) ) ;
V_4 -> V_38 >>= ( 8 - V_4 -> V_37 ) ;
V_12 = 0 ;
exit:
F_13 ( & V_4 -> V_27 ) ;
return V_12 ;
}
static T_2 F_16 ( struct V_3 * V_4 , int * V_39 )
{
struct V_9 * V_10 = & V_4 -> V_11 ;
long V_40 , V_41 ;
int V_12 ;
V_12 = F_6 ( V_4 ) ;
if ( V_12 < 0 )
goto exit;
V_40 = ( ( V_4 -> V_33 - V_10 -> V_21 ) * V_10 -> V_20 ) >> 15 ;
V_41 = ( V_10 -> V_25 << 11 ) / ( V_40 + V_10 -> V_26 ) ;
V_4 -> V_42 = V_40 + V_41 - 4000 ;
if ( V_39 != NULL )
* V_39 = ( V_40 + V_41 + 8 ) >> 4 ;
exit:
return V_12 ;
}
static T_2 F_17 ( struct V_3 * V_4 , int * V_43 )
{
struct V_9 * V_10 = & V_4 -> V_11 ;
T_2 V_40 , V_41 , V_44 , V_45 ;
T_4 V_46 , V_47 ;
T_2 V_48 ;
int V_12 ;
if ( ( V_4 -> V_34 == 0 ) ||
F_18 ( V_4 -> V_34 + 1 * V_49 ) ) {
V_12 = F_16 ( V_4 , NULL ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_14 ( V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_40 = ( V_4 -> V_42 * V_4 -> V_42 ) >> 12 ;
V_40 *= V_10 -> V_23 ;
V_40 >>= 11 ;
V_41 = V_10 -> V_17 * V_4 -> V_42 ;
V_41 >>= 11 ;
V_44 = V_40 + V_41 ;
V_45 = ( ( ( ( ( T_2 ) V_10 -> V_16 ) * 4 + V_44 ) << V_4 -> V_37 ) + 2 ) ;
V_45 >>= 2 ;
V_40 = ( V_10 -> V_18 * V_4 -> V_42 ) >> 13 ;
V_41 = ( V_10 -> V_22 * ( ( V_4 -> V_42 * V_4 -> V_42 ) >> 12 ) ) >> 16 ;
V_44 = ( V_40 + V_41 + 2 ) >> 2 ;
V_46 = ( V_10 -> V_19 * ( T_4 ) ( V_44 + 32768 ) ) >> 15 ;
V_47 = ( ( T_4 ) V_4 -> V_38 - V_45 ) *
( 50000 >> V_4 -> V_37 ) ;
V_48 = ( ( V_47 < 0x80000000 ) ? ( ( V_47 << 1 ) / V_46 ) : ( ( V_47 / V_46 ) * 2 ) ) ;
V_40 = V_48 >> 8 ;
V_40 *= V_40 ;
V_40 = ( V_40 * 3038 ) >> 16 ;
V_41 = ( - 7357 * V_48 ) >> 16 ;
V_48 += ( V_40 + V_41 + 3791 ) >> 4 ;
* V_43 = V_48 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 ,
unsigned char V_50 )
{
if ( V_50 > 3 )
V_50 = 3 ;
V_4 -> V_37 = V_50 ;
}
static unsigned char F_20 ( struct V_3 * V_4 )
{
return V_4 -> V_37 ;
}
static T_5 F_21 ( struct V_51 * V_30 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_55 )
{
struct V_3 * V_4 = F_22 ( V_30 ) ;
unsigned long V_50 ;
int V_56 = F_23 ( V_54 , 10 , & V_50 ) ;
if ( V_56 == 0 ) {
F_7 ( & V_4 -> V_27 ) ;
F_19 ( V_4 , V_50 ) ;
F_13 ( & V_4 -> V_27 ) ;
return V_55 ;
}
return V_56 ;
}
static T_5 F_24 ( struct V_51 * V_30 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_3 * V_4 = F_22 ( V_30 ) ;
return sprintf ( V_54 , L_5 , F_20 ( V_4 ) ) ;
}
static T_5 F_25 ( struct V_51 * V_30 ,
struct V_52 * V_53 , char * V_54 )
{
int V_39 ;
int V_12 ;
struct V_3 * V_4 = F_22 ( V_30 ) ;
V_12 = F_16 ( V_4 , & V_39 ) ;
if ( V_12 < 0 )
return V_12 ;
else
return sprintf ( V_54 , L_6 , V_39 ) ;
}
static T_5 F_26 ( struct V_51 * V_30 ,
struct V_52 * V_53 , char * V_54 )
{
int V_43 ;
int V_12 ;
struct V_3 * V_4 = F_22 ( V_30 ) ;
V_12 = F_17 ( V_4 , & V_43 ) ;
if ( V_12 < 0 )
return V_12 ;
else
return sprintf ( V_54 , L_6 , V_43 ) ;
}
int F_27 ( struct V_51 * V_30 )
{
struct V_3 * V_4 = F_22 ( V_30 ) ;
unsigned int V_57 ;
int V_58 ;
V_58 = F_28 ( V_4 -> V_13 , V_59 , & V_57 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_57 != V_4 -> V_60 )
return - V_61 ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 )
{
#ifdef F_30
struct V_62 * V_63 = V_4 -> V_30 -> V_64 ;
T_4 V_65 ;
if ( ! V_63 )
return;
if ( ! F_31 ( V_63 , L_7 , & V_65 ) )
V_4 -> V_60 = V_65 & 0xff ;
if ( ! F_31 ( V_63 , L_8 , & V_65 ) )
V_4 -> V_66 = ( V_65 / 100 ) * V_49 ;
if ( ! F_31 ( V_63 , L_9 , & V_65 ) )
V_4 -> V_37 = V_65 & 0xff ;
#endif
}
static int F_32 ( struct V_3 * V_4 )
{
int V_12 = F_3 ( V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_4 -> V_60 = V_67 ;
V_4 -> V_34 = 0 ;
V_4 -> V_66 = 1 * V_49 ;
V_4 -> V_37 = 3 ;
F_29 ( V_4 ) ;
F_33 ( & V_4 -> V_27 ) ;
return 0 ;
}
int F_34 ( struct V_51 * V_30 , struct V_13 * V_13 , int V_1 )
{
struct V_3 * V_4 ;
int V_56 = 0 ;
V_4 = F_35 ( sizeof( struct V_3 ) , V_68 ) ;
if ( ! V_4 ) {
V_56 = - V_69 ;
goto exit;
}
F_36 ( V_30 , V_4 ) ;
V_4 -> V_30 = V_30 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_1 = V_1 ;
if ( V_4 -> V_1 > 0 ) {
V_56 = F_37 ( V_30 , V_4 -> V_1 , F_1 ,
V_70 , L_10 ,
V_4 ) ;
if ( V_56 < 0 )
goto V_71;
}
V_56 = F_32 ( V_4 ) ;
if ( V_56 < 0 )
goto V_71;
V_56 = F_27 ( V_30 ) ;
if ( V_56 < 0 ) {
F_10 ( V_30 , L_11 , V_72 ) ;
goto V_71;
}
V_56 = F_38 ( & V_30 -> V_73 , & V_74 ) ;
if ( V_56 )
goto V_71;
F_39 ( V_30 , L_12 , V_72 ) ;
return 0 ;
V_71:
F_40 ( V_4 ) ;
exit:
return V_56 ;
}
int F_41 ( struct V_51 * V_30 )
{
struct V_3 * V_4 = F_22 ( V_30 ) ;
F_42 ( & V_4 -> V_30 -> V_73 , & V_74 ) ;
F_40 ( V_4 ) ;
return 0 ;
}
