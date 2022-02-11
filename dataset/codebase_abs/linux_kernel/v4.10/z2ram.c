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
void * V_16 = F_7 ( V_4 -> V_17 ) ;
if ( V_6 < V_14 )
V_14 = V_6 ;
V_12 += V_18 [ V_5 >> V_19 ] ;
if ( F_8 ( V_4 ) == V_20 )
memcpy ( V_16 , ( char * ) V_12 , V_14 ) ;
else
memcpy ( ( char * ) V_12 , V_16 , V_14 ) ;
V_5 += V_14 ;
V_6 -= V_14 ;
}
V_11:
if ( ! F_9 ( V_4 , V_7 ) )
V_4 = F_2 ( V_2 ) ;
}
}
static void
F_10 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 / V_15 ; V_21 ++ )
{
if ( F_11 ( V_21 , V_23 ) )
{
V_24 ++ ;
V_18 [ V_8 ++ ] = ( unsigned long ) F_12 ( V_25 ) +
( V_21 << V_19 ) ;
F_13 ( V_21 , V_23 ) ;
}
}
return;
}
static void
F_14 ( void )
{
while ( F_15 () > ( V_15 * 4 ) )
{
V_26 ++ ;
V_18 [ V_8 ] =
( V_27 ) F_16 ( V_15 , L_3 ) ;
if ( V_18 [ V_8 ] == 0 )
{
break;
}
V_8 ++ ;
}
return;
}
static int F_17 ( struct V_28 * V_29 , T_1 V_30 )
{
int V_31 ;
int V_32 = ( V_22 / V_15 ) *
sizeof( V_18 [ 0 ] ) ;
int V_33 = ( V_34 / V_15 ) *
sizeof( V_18 [ 0 ] ) ;
int V_35 = - V_36 ;
V_31 = F_18 ( V_29 -> V_37 ) ;
F_19 ( & V_38 ) ;
if ( V_39 != - 1 && V_39 != V_31 )
{
V_35 = - V_40 ;
goto V_41;
}
if ( V_39 == - 1 )
{
V_24 = 0 ;
V_26 = 0 ;
V_42 = 0 ;
V_8 = 0 ;
if ( V_31 >= V_43 && V_31 <= V_44 ) {
int V_45 = V_31 - V_43 + 1 ;
unsigned long V_14 , V_46 , V_47 ;
if ( V_45 >= V_48 ) {
F_20 ( KERN_ERR DEVICE_NAME
L_4 ) ;
goto V_41;
}
V_46 = V_49 [ V_45 ] . V_12 ;
V_14 = V_49 [ V_45 ] . V_14 & ~ ( V_15 - 1 ) ;
#ifdef F_21
{
F_22 ( F_23 ( V_14 ) ) ;
}
V_47 = ( unsigned long ) F_24 ( V_46 , V_14 ,
V_50 ) ;
#else
V_47 = ( unsigned long ) F_25 ( V_46 , V_14 ) ;
#endif
V_18 =
F_26 ( ( V_14 / V_15 ) * sizeof( V_18 [ 0 ] ) ,
V_51 ) ;
if ( V_18 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_41;
}
while ( V_14 ) {
V_18 [ V_8 ++ ] = V_47 ;
V_14 -= V_15 ;
V_47 += V_15 ;
V_42 ++ ;
}
if ( V_8 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_6 ,
list_count * Z2RAM_CHUNK1024, index ) ;
} else
switch ( V_31 )
{
case V_52 :
V_18 = F_26 ( V_32 + V_33 , V_51 ) ;
if ( V_18 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_41;
}
F_10 () ;
F_14 () ;
if ( V_8 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_7 ,
z2_count * Z2RAM_CHUNK1024,
chip_count * Z2RAM_CHUNK1024,
( z2_count + chip_count ) * Z2RAM_CHUNK1024 ) ;
break;
case V_53 :
V_18 = F_26 ( V_32 , V_51 ) ;
if ( V_18 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_41;
}
F_10 () ;
if ( V_8 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_8 ,
z2_count * Z2RAM_CHUNK1024 ) ;
break;
case V_54 :
V_18 = F_26 ( V_33 , V_51 ) ;
if ( V_18 == NULL )
{
F_20 ( KERN_ERR DEVICE_NAME
L_5 ) ;
goto V_41;
}
F_14 () ;
if ( V_8 != 0 )
F_20 ( KERN_INFO DEVICE_NAME
L_9 ,
chip_count * Z2RAM_CHUNK1024 ) ;
break;
default:
V_35 = - V_55 ;
goto V_41;
break;
}
if ( V_8 == 0 )
{
F_20 ( KERN_NOTICE DEVICE_NAME
L_10 ) ;
goto V_56;
}
V_39 = V_31 ;
V_8 <<= V_19 ;
F_27 ( V_57 , V_8 >> 9 ) ;
}
F_28 ( & V_38 ) ;
return 0 ;
V_56:
F_29 ( V_18 ) ;
V_41:
F_28 ( & V_38 ) ;
return V_35 ;
}
static void
F_30 ( struct V_58 * V_59 , T_1 V_30 )
{
F_19 ( & V_38 ) ;
if ( V_39 == - 1 ) {
F_28 ( & V_38 ) ;
return;
}
F_28 ( & V_38 ) ;
}
static struct V_60 * F_31 ( T_2 V_61 , int * V_62 , void * V_63 )
{
* V_62 = 0 ;
return F_32 ( V_57 ) ;
}
static int T_3
F_33 ( void )
{
int V_64 ;
if ( ! V_65 )
return - V_55 ;
V_64 = - V_40 ;
if ( F_34 ( V_66 , V_9 ) )
goto V_7;
V_64 = - V_36 ;
V_57 = F_35 ( 1 ) ;
if ( ! V_57 )
goto V_67;
V_68 = F_36 ( F_1 , & V_69 ) ;
if ( ! V_68 )
goto V_70;
V_57 -> V_71 = V_66 ;
V_57 -> V_72 = 0 ;
V_57 -> V_73 = & V_74 ;
sprintf ( V_57 -> V_75 , L_3 ) ;
V_57 -> V_76 = V_68 ;
F_37 ( V_57 ) ;
F_38 ( F_39 ( V_66 , 0 ) , V_77 , V_78 ,
F_31 , NULL , NULL ) ;
return 0 ;
V_70:
F_40 ( V_57 ) ;
V_67:
F_41 ( V_66 , V_9 ) ;
V_7:
return V_64 ;
}
static void T_4 F_42 ( void )
{
int V_21 , V_79 ;
F_43 ( F_39 ( V_66 , 0 ) , V_77 ) ;
F_41 ( V_66 , V_9 ) ;
F_44 ( V_57 ) ;
F_40 ( V_57 ) ;
F_45 ( V_68 ) ;
if ( V_39 != - 1 )
{
V_21 = 0 ;
for ( V_79 = 0 ; V_79 < V_24 ; V_79 ++ )
{
F_46 ( V_21 ++ , V_23 ) ;
}
for ( V_79 = 0 ; V_79 < V_26 ; V_79 ++ )
{
if ( V_18 [ V_21 ] )
{
F_47 ( ( void * ) V_18 [ V_21 ++ ] ) ;
}
}
if ( V_18 != NULL )
{
F_29 ( V_18 ) ;
}
}
return;
}
