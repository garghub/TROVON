static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] = {
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = & V_3 , . V_12 = 1 } ,
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = V_13 , . V_11 = V_4 , . V_12 = 1 } ,
} ;
if ( F_2 ( V_2 -> V_14 , V_6 , 2 ) != 2 ) {
F_3 ( V_15 L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_11 [ 2 ] = { V_3 , V_4 } ;
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = V_11 , . V_12 = 2
} ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_11 , T_1 V_12 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_11 = V_11 , . V_12 = V_12
} ;
if ( F_2 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_3 ( V_15 L_3 , ( int ) V_12 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_6 ( T_2 V_17 , T_2 V_18 , T_2 V_19 )
{
int V_20 , V_21 ;
int V_22 , V_23 , V_24 ;
V_23 = 1000000 ;
for ( V_20 = 1 ; V_20 < 10 ; V_20 ++ ) {
V_21 = ( ( 2 * V_20 * V_17 ) / V_18 + 1 ) / 2 ;
V_24 = V_20 * ( int ) V_17 - V_21 * ( int ) V_18 ;
if ( V_24 < 0 ) V_24 = - V_24 ;
V_22 = ( V_24 - ( int ) V_19 ) ;
if ( V_22 < 0 ) V_22 = - V_22 ;
if ( V_23 > V_22 ) V_23 = V_22 ;
}
return V_23 ;
}
static int F_7 ( T_2 V_17 , T_2 V_18 , T_2 V_19 )
{
T_2 V_25 , V_26 , V_27 ;
int V_20 , V_21 ;
V_20 = 0 ;
V_21 = 1000 ;
V_25 = F_6 ( V_17 , V_18 , V_19 ) ;
if ( V_25 < V_28 ) {
F_8 ( L_4 ,
( int ) V_17 , ( int ) V_18 ) ;
V_20 = 1000 ;
V_26 = F_6 ( V_17 + V_20 , V_18 + V_20 , V_19 ) ;
V_27 = F_6 ( V_17 - V_20 , V_18 - V_20 , V_19 ) ;
if ( V_26 < V_27 ) {
V_21 = - V_21 ; V_20 = - V_20 ; V_25 = V_27 ;
} else
V_25 = V_26 ;
while ( V_25 < V_28 ) {
V_20 += V_21 ;
V_25 = F_6 ( V_17 + V_20 , V_18 + V_20 , V_19 ) ;
}
F_8 ( L_5 ,
( int ) ( V_17 + V_20 ) , ( int ) ( V_18 + V_20 ) ) ;
}
return V_20 ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_30 -> V_33 ;
struct V_1 * V_2 ;
int V_34 = 0 ;
T_2 V_35 ;
T_1 V_36 ;
T_2 V_37 , V_38 ;
T_2 V_39 , V_40 , V_41 , V_42 ;
T_1 V_43 [ 8 ] ;
T_2 V_44 ;
V_2 = V_30 -> V_45 ;
V_44 = V_2 -> V_46 ;
V_43 [ 0 ] = V_47 ;
V_43 [ 1 ] = 0xFF ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 1 ) ;
F_5 ( V_2 , V_43 , 2 ) ;
V_35 = V_32 -> V_50 / 1000 ;
V_37 = V_35 + V_44 * 1000 ;
V_37 = ( V_37 / 250 ) * 250 ;
V_38 = V_37 - V_35 - V_51 ;
V_38 = ( ( V_38 + 25 ) / 50 ) * 50 ;
V_2 -> V_50 = ( V_37 - V_38 - V_51 ) * 1000 ,
#ifdef F_10
V_40 = F_7 ( V_37 , V_38 , V_51 ) ;
V_37 += V_40 ;
V_38 += V_40 ;
#endif
V_40 = V_37 / ( V_52 / 64 ) ;
V_39 = V_40 / 64 ;
V_40 &= 0x3f ;
V_42 = V_38 * 64 / ( V_52 / 128 ) ;
V_41 = V_42 / 8192 ;
V_42 &= 0x1fff ;
if ( V_35 <= 95000 ) V_36 = 0xB0 ; else
if ( V_35 <= 180000 ) V_36 = 0xA0 ; else
if ( V_35 <= 260000 ) V_36 = 0x90 ; else
if ( V_35 <= 335000 ) V_36 = 0x80 ; else
if ( V_35 <= 425000 ) V_36 = 0x70 ; else
if ( V_35 <= 480000 ) V_36 = 0x60 ; else
if ( V_35 <= 570000 ) V_36 = 0x50 ; else
if ( V_35 <= 645000 ) V_36 = 0x40 ; else
if ( V_35 <= 730000 ) V_36 = 0x30 ; else
if ( V_35 <= 810000 ) V_36 = 0x20 ; else V_36 = 0x10 ;
V_43 [ 0 ] = V_53 ;
V_43 [ 1 ] = V_36 | ( ( V_40 >> 2 ) & 0x0F ) ;
V_43 [ 2 ] = V_39 ;
V_43 [ 3 ] = ( V_42 & 0x0F ) | ( ( V_40 & 3 ) << 4 ) ;
V_43 [ 4 ] = V_42 >> 4 ;
V_43 [ 5 ] = ( ( V_42 >> 12 ) & 1 ) | ( V_41 << 1 ) ;
F_8 ( L_6 , ( int ) V_44 ) ;
F_8 ( L_7 , ( int ) V_35 , ( int ) V_37 , ( int ) V_38 ) ;
F_8 ( L_8 , ( int ) V_39 , ( int ) V_40 , ( int ) V_41 , ( int ) V_42 ) ;
F_8 ( L_9 , ( int ) V_43 [ 1 ] , ( int ) V_43 [ 2 ] , ( int ) V_43 [ 3 ] , ( int ) V_43 [ 4 ] , ( int ) V_43 [ 5 ] ) ;
F_5 ( V_2 , V_43 , 6 ) ;
V_34 = 0 ;
do {
F_1 ( V_2 , V_54 , V_43 ) ;
if ( ( V_43 [ 0 ] & 0x88 ) == 0x88 )
break;
F_11 ( 4 ) ;
V_34 ++ ;
} while ( V_34 < 10 );
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 0 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_43 = 0 ;
int V_34 = 0 ;
if ( F_5 ( V_2 , V_55 , sizeof( V_55 ) ) )
return;
if ( F_5 ( V_2 , V_56 , sizeof( V_56 ) ) )
return;
F_4 ( V_2 , V_57 , ( V_2 -> V_8 -> V_58 << 6 ) | 0x30 ) ;
do {
V_43 |= ( 1 << 6 ) ;
F_4 ( V_2 , V_59 , V_43 ) ;
F_11 ( 20 ) ;
if ( V_34 == 0 ) {
V_43 |= ( 1 << 7 ) ;
F_4 ( V_2 , V_59 , V_43 ) ;
V_43 &= ~ ( 1 << 7 ) ;
F_11 ( 20 ) ;
}
V_43 &= ~ ( 1 << 6 ) ;
F_4 ( V_2 , V_59 , V_43 ) ;
F_11 ( 20 ) ;
V_34 ++ ;
} while ( V_34 < 9 );
V_34 = 0 ;
while ( V_34 ++ < 10 && F_1 ( V_2 , V_60 , & V_43 ) == 0 && ( V_43 & ( 1 << 6 ) ) == 0 )
F_11 ( 20 ) ;
if ( V_34 <= 10 ) {
F_1 ( V_2 , V_61 , & V_2 -> V_62 ) ;
F_8 ( L_10 , ( int ) V_2 -> V_62 ) ;
} else
F_8 ( L_11 ) ;
}
static int F_13 ( struct V_29 * V_30 , T_2 * V_50 )
{
struct V_1 * V_2 = V_30 -> V_45 ;
* V_50 = V_2 -> V_50 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 , T_2 * V_50 )
{
* V_50 = V_51 * 1000 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_45 ;
int V_63 ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 1 ) ;
V_63 = F_4 ( V_2 , V_57 ,
( V_2 -> V_8 -> V_58 << 6 ) | 0x33 ) ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 0 ) ;
return V_63 ;
}
static int F_16 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_45 ;
int V_63 ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 1 ) ;
V_63 = F_4 ( V_2 , V_57 ,
( V_2 -> V_8 -> V_58 << 6 ) | 0x30 ) ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 0 ) ;
return V_63 ;
}
static void F_17 ( struct V_29 * V_30 )
{
F_18 ( V_30 -> V_45 ) ;
V_30 -> V_45 = NULL ;
}
struct V_29 * F_19 ( struct V_29 * V_30 , struct V_64 * V_14 , struct V_65 * V_8 , T_3 V_44 )
{
struct V_1 * V_2 = NULL ;
T_1 V_66 = 0 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_67 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_46 = V_44 ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 1 ) ;
if ( F_1 ( V_2 , V_68 , & V_66 ) != 0 ) {
F_18 ( V_2 ) ;
return NULL ;
}
if ( V_66 != V_69 ) {
F_18 ( V_2 ) ;
return NULL ;
}
F_3 ( V_70 L_12 , V_44 ) ;
memcpy ( & V_30 -> V_48 . V_71 , & V_72 , sizeof( struct V_73 ) ) ;
V_30 -> V_45 = V_2 ;
F_12 ( V_2 ) ;
if ( V_30 -> V_48 . V_49 )
V_30 -> V_48 . V_49 ( V_30 , 0 ) ;
return V_30 ;
}
