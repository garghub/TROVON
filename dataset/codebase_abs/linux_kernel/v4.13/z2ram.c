static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
while ( V_4 ) {
unsigned long V_5 = F_3 ( V_4 ) << 9 ;
unsigned long V_6 = F_4 ( V_4 ) ;
T_1 V_7 = V_8 ;
if ( V_5 + V_6 > V_9 ) {
F_5 ( V_10 L_1
L_2 ,
( unsigned long long ) F_3 ( V_4 ) ,
F_6 ( V_4 ) ) ;
V_7 = V_11 ;
goto V_12;
}
while ( V_6 ) {
unsigned long V_13 = V_5 & V_14 ;
unsigned long V_15 = V_16 - V_13 ;
void * V_17 = F_7 ( V_4 -> V_18 ) ;
if ( V_6 < V_15 )
V_15 = V_6 ;
V_13 += V_19 [ V_5 >> V_20 ] ;
if ( F_8 ( V_4 ) == V_21 )
memcpy ( V_17 , ( char * ) V_13 , V_15 ) ;
else
memcpy ( ( char * ) V_13 , V_17 , V_15 ) ;
V_5 += V_15 ;
V_6 -= V_15 ;
}
V_12:
if ( ! F_9 ( V_4 , V_7 ) )
V_4 = F_2 ( V_2 ) ;
}
}
static void
F_10 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 / V_16 ; V_22 ++ )
{
if ( F_11 ( V_22 , V_24 ) )
{
V_25 ++ ;
V_19 [ V_9 ++ ] = ( unsigned long ) F_12 ( V_26 ) +
( V_22 << V_20 ) ;
F_13 ( V_22 , V_24 ) ;
}
}
return;
}
static void
F_14 ( void )
{
while ( F_15 () > ( V_16 * 4 ) )
{
V_27 ++ ;
V_19 [ V_9 ] =
( V_28 ) F_16 ( V_16 , L_3 ) ;
if ( V_19 [ V_9 ] == 0 )
{
break;
}
V_9 ++ ;
}
return;
}
static int F_17 ( struct V_29 * V_30 , T_2 V_31 )
{
int V_32 ;
int V_33 = ( V_23 / V_16 ) *
sizeof( V_19 [ 0 ] ) ;
int V_34 = ( V_35 / V_16 ) *
sizeof( V_19 [ 0 ] ) ;
int V_36 = - V_37 ;
V_32 = F_18 ( V_30 -> V_38 ) ;
F_19 ( & V_39 ) ;
if ( V_40 != - 1 && V_40 != V_32 )
{
V_36 = - V_41 ;
goto V_42;
}
if ( V_40 == - 1 )
{
V_25 = 0 ;
V_27 = 0 ;
V_43 = 0 ;
V_9 = 0 ;
if ( V_32 >= V_44 && V_32 <= V_45 ) {
int V_46 = V_32 - V_44 + 1 ;
unsigned long V_15 , V_47 , V_48 ;
if ( V_46 >= V_49 ) {
F_20 ( KERN_ERR DEVICE_NAME
L_4 ) ;
goto V_42;
}
V_47 = V_50 [ V_46 ] . V_13 ;
V_15 = V_50 [ V_46 ] . V_15 & ~ ( V_16 - 1 ) ;
#ifdef F_21
{
F_22 ( F_23 ( V_15 ) ) ;
}
V_48 = ( unsigned long ) F_24 ( V_47 , V_15 ,
V_51 ) ;
#else
V_48 = ( unsigned long ) F_25 ( V_47 , V_15 ) ;
#endif
V_19 =
F_26 ( ( V_15 / V_16 ) * sizeof( V_19 [ 0 ] ) ,
V_52 ) ;
if ( V_19 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_42;
}
while ( V_15 ) {
V_19 [ V_9 ++ ] = V_48 ;
V_15 -= V_16 ;
V_48 += V_16 ;
V_43 ++ ;
}
if ( V_9 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_6 ,
list_count * Z2RAM_CHUNK1024, index ) ;
} else
switch ( V_32 )
{
case V_53 :
V_19 = F_26 ( V_33 + V_34 , V_52 ) ;
if ( V_19 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_42;
}
F_10 () ;
F_14 () ;
if ( V_9 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_7 ,
z2_count * Z2RAM_CHUNK1024,
chip_count * Z2RAM_CHUNK1024,
( z2_count + chip_count ) * Z2RAM_CHUNK1024 ) ;
break;
case V_54 :
V_19 = F_26 ( V_33 , V_52 ) ;
if ( V_19 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_42;
}
F_10 () ;
if ( V_9 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_8 ,
z2_count * Z2RAM_CHUNK1024 ) ;
break;
case V_55 :
V_19 = F_26 ( V_34 , V_52 ) ;
if ( V_19 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_42;
}
F_14 () ;
if ( V_9 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_9 ,
chip_count * Z2RAM_CHUNK1024 ) ;
break;
default:
V_36 = - V_56 ;
goto V_42;
break;
}
if ( V_9 == 0 )
{
F_20 ( KERN_NOTICE DEVICE_NAME
L_10 ) ;
goto V_57;
}
V_40 = V_32 ;
V_9 <<= V_20 ;
F_27 ( V_58 , V_9 >> 9 ) ;
}
F_28 ( & V_39 ) ;
return 0 ;
V_57:
F_29 ( V_19 ) ;
V_42:
F_28 ( & V_39 ) ;
return V_36 ;
}
static void
F_30 ( struct V_59 * V_60 , T_2 V_31 )
{
F_19 ( & V_39 ) ;
if ( V_40 == - 1 ) {
F_28 ( & V_39 ) ;
return;
}
F_28 ( & V_39 ) ;
}
static struct V_61 * F_31 ( T_3 V_62 , int * V_63 , void * V_64 )
{
* V_63 = 0 ;
return F_32 ( V_58 ) ;
}
static int T_4
F_33 ( void )
{
int V_65 ;
if ( ! V_66 )
return - V_56 ;
V_65 = - V_41 ;
if ( F_34 ( V_67 , V_10 ) )
goto V_7;
V_65 = - V_37 ;
V_58 = F_35 ( 1 ) ;
if ( ! V_58 )
goto V_68;
V_69 = F_36 ( F_1 , & V_70 ) ;
if ( ! V_69 )
goto V_71;
V_58 -> V_72 = V_67 ;
V_58 -> V_73 = 0 ;
V_58 -> V_74 = & V_75 ;
sprintf ( V_58 -> V_76 , L_3 ) ;
V_58 -> V_77 = V_69 ;
F_37 ( V_58 ) ;
F_38 ( F_39 ( V_67 , 0 ) , V_78 , V_79 ,
F_31 , NULL , NULL ) ;
return 0 ;
V_71:
F_40 ( V_58 ) ;
V_68:
F_41 ( V_67 , V_10 ) ;
V_7:
return V_65 ;
}
static void T_5 F_42 ( void )
{
int V_22 , V_80 ;
F_43 ( F_39 ( V_67 , 0 ) , V_78 ) ;
F_41 ( V_67 , V_10 ) ;
F_44 ( V_58 ) ;
F_40 ( V_58 ) ;
F_45 ( V_69 ) ;
if ( V_40 != - 1 )
{
V_22 = 0 ;
for ( V_80 = 0 ; V_80 < V_25 ; V_80 ++ )
{
F_46 ( V_22 ++ , V_24 ) ;
}
for ( V_80 = 0 ; V_80 < V_27 ; V_80 ++ )
{
if ( V_19 [ V_22 ] )
{
F_47 ( ( void * ) V_19 [ V_22 ++ ] ) ;
}
}
if ( V_19 != NULL )
{
F_29 ( V_19 ) ;
}
}
return;
}
