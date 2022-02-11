static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
while ( V_4 ) {
unsigned long V_5 = F_3 ( V_4 ) << 9 ;
unsigned long V_6 = F_4 ( V_4 ) ;
int V_7 = 0 ;
if ( V_5 + V_6 > V_8 ) {
F_5 ( V_9 L_1
L_2 ,
( unsigned long long ) F_3 ( V_4 ) ,
F_6 ( V_4 ) ) ;
V_7 = - V_10 ;
goto V_11;
}
while ( V_6 ) {
unsigned long V_12 = V_5 & V_13 ;
unsigned long V_14 = V_15 - V_12 ;
if ( V_6 < V_14 )
V_14 = V_6 ;
V_12 += V_16 [ V_5 >> V_17 ] ;
if ( F_7 ( V_4 ) == V_18 )
memcpy ( V_4 -> V_19 , ( char * ) V_12 , V_14 ) ;
else
memcpy ( ( char * ) V_12 , V_4 -> V_19 , V_14 ) ;
V_5 += V_14 ;
V_6 -= V_14 ;
}
V_11:
if ( ! F_8 ( V_4 , V_7 ) )
V_4 = F_2 ( V_2 ) ;
}
}
static void
F_9 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 / V_15 ; V_20 ++ )
{
if ( F_10 ( V_20 , V_22 ) )
{
V_23 ++ ;
V_16 [ V_8 ++ ] = ( unsigned long ) F_11 ( V_24 ) +
( V_20 << V_17 ) ;
F_12 ( V_20 , V_22 ) ;
}
}
return;
}
static void
F_13 ( void )
{
while ( F_14 () > ( V_15 * 4 ) )
{
V_25 ++ ;
V_16 [ V_8 ] =
( V_26 ) F_15 ( V_15 , L_3 ) ;
if ( V_16 [ V_8 ] == 0 )
{
break;
}
V_8 ++ ;
}
return;
}
static int F_16 ( struct V_27 * V_28 , T_1 V_29 )
{
int V_30 ;
int V_31 = ( V_21 / V_15 ) *
sizeof( V_16 [ 0 ] ) ;
int V_32 = ( V_33 / V_15 ) *
sizeof( V_16 [ 0 ] ) ;
int V_34 = - V_35 ;
V_30 = F_17 ( V_28 -> V_36 ) ;
F_18 ( & V_37 ) ;
if ( V_38 != - 1 && V_38 != V_30 )
{
V_34 = - V_39 ;
goto V_40;
}
if ( V_38 == - 1 )
{
V_23 = 0 ;
V_25 = 0 ;
V_41 = 0 ;
V_8 = 0 ;
if ( V_30 >= V_42 && V_30 <= V_43 ) {
int V_44 = V_30 - V_42 + 1 ;
unsigned long V_14 , V_45 , V_46 ;
if ( V_44 >= V_47 ) {
F_19 ( KERN_ERR DEVICE_NAME
L_4 ) ;
goto V_40;
}
V_45 = V_48 [ V_44 ] . V_12 ;
V_14 = V_48 [ V_44 ] . V_14 & ~ ( V_15 - 1 ) ;
#ifdef F_20
{
F_21 ( F_22 ( V_14 ) ) ;
}
V_46 = ( unsigned long ) F_23 ( V_45 , V_14 ,
V_49 ) ;
#else
V_46 = ( unsigned long ) F_24 ( V_45 , V_14 ) ;
#endif
V_16 =
F_25 ( ( V_14 / V_15 ) * sizeof( V_16 [ 0 ] ) ,
V_50 ) ;
if ( V_16 == NULL )
{
F_19 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_40;
}
while ( V_14 ) {
V_16 [ V_8 ++ ] = V_46 ;
V_14 -= V_15 ;
V_46 += V_15 ;
V_41 ++ ;
}
if ( V_8 != 0 )
F_19 ( KERN_INFO DEVICE_NAME
L_6 ,
list_count * Z2RAM_CHUNK1024, index ) ;
} else
switch ( V_30 )
{
case V_51 :
V_16 = F_25 ( V_31 + V_32 , V_50 ) ;
if ( V_16 == NULL )
{
F_19 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_40;
}
F_9 () ;
F_13 () ;
if ( V_8 != 0 )
F_19 ( KERN_INFO DEVICE_NAME
L_7 ,
z2_count * Z2RAM_CHUNK1024,
chip_count * Z2RAM_CHUNK1024,
( z2_count + chip_count ) * Z2RAM_CHUNK1024 ) ;
break;
case V_52 :
V_16 = F_25 ( V_31 , V_50 ) ;
if ( V_16 == NULL )
{
F_19 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_40;
}
F_9 () ;
if ( V_8 != 0 )
F_19 ( KERN_INFO DEVICE_NAME
L_8 ,
z2_count * Z2RAM_CHUNK1024 ) ;
break;
case V_53 :
V_16 = F_25 ( V_32 , V_50 ) ;
if ( V_16 == NULL )
{
F_19 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_40;
}
F_13 () ;
if ( V_8 != 0 )
F_19 ( KERN_INFO DEVICE_NAME
L_9 ,
chip_count * Z2RAM_CHUNK1024 ) ;
break;
default:
V_34 = - V_54 ;
goto V_40;
break;
}
if ( V_8 == 0 )
{
F_19 ( KERN_NOTICE DEVICE_NAME
L_10 ) ;
goto V_55;
}
V_38 = V_30 ;
V_8 <<= V_17 ;
F_26 ( V_56 , V_8 >> 9 ) ;
}
F_27 ( & V_37 ) ;
return 0 ;
V_55:
F_28 ( V_16 ) ;
V_40:
F_27 ( & V_37 ) ;
return V_34 ;
}
static void
F_29 ( struct V_57 * V_58 , T_1 V_29 )
{
F_18 ( & V_37 ) ;
if ( V_38 == - 1 ) {
F_27 ( & V_37 ) ;
return;
}
F_27 ( & V_37 ) ;
}
static struct V_59 * F_30 ( T_2 V_60 , int * V_61 , void * V_62 )
{
* V_61 = 0 ;
return F_31 ( V_56 ) ;
}
static int T_3
F_32 ( void )
{
int V_63 ;
if ( ! V_64 )
return - V_54 ;
V_63 = - V_39 ;
if ( F_33 ( V_65 , V_9 ) )
goto V_7;
V_63 = - V_35 ;
V_56 = F_34 ( 1 ) ;
if ( ! V_56 )
goto V_66;
V_67 = F_35 ( F_1 , & V_68 ) ;
if ( ! V_67 )
goto V_69;
V_56 -> V_70 = V_65 ;
V_56 -> V_71 = 0 ;
V_56 -> V_72 = & V_73 ;
sprintf ( V_56 -> V_74 , L_3 ) ;
V_56 -> V_75 = V_67 ;
F_36 ( V_56 ) ;
F_37 ( F_38 ( V_65 , 0 ) , V_76 , V_77 ,
F_30 , NULL , NULL ) ;
return 0 ;
V_69:
F_39 ( V_56 ) ;
V_66:
F_40 ( V_65 , V_9 ) ;
V_7:
return V_63 ;
}
static void T_4 F_41 ( void )
{
int V_20 , V_78 ;
F_42 ( F_38 ( V_65 , 0 ) , V_76 ) ;
F_40 ( V_65 , V_9 ) ;
F_43 ( V_56 ) ;
F_39 ( V_56 ) ;
F_44 ( V_67 ) ;
if ( V_38 != - 1 )
{
V_20 = 0 ;
for ( V_78 = 0 ; V_78 < V_23 ; V_78 ++ )
{
F_45 ( V_20 ++ , V_22 ) ;
}
for ( V_78 = 0 ; V_78 < V_25 ; V_78 ++ )
{
if ( V_16 [ V_20 ] )
{
F_46 ( ( void * ) V_16 [ V_20 ++ ] ) ;
}
}
if ( V_16 != NULL )
{
F_28 ( V_16 ) ;
}
}
return;
}
