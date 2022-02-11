static T_1 F_1 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
char * V_6 = V_7 . V_8 . V_9 == V_10 ? V_11 : V_12 ;
T_1 V_13 , V_14 ;
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
V_14 = V_13 = F_2 ( T_4 , V_2 , V_5 ) ;
if ( F_3 ( V_15 , V_1 , V_13 ) )
return - V_16 ;
while ( V_13 > 0 ) {
* V_15 = V_6 [ * V_15 ] + 128 ;
V_15 ++ ;
V_13 -- ;
}
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_4 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
V_14 = V_13 = F_2 ( T_4 , V_2 , V_5 ) ;
if ( F_3 ( V_15 , V_1 , V_13 ) )
return - V_16 ;
while ( V_13 > 0 ) {
* V_15 = * V_15 + 128 ;
V_15 ++ ;
V_13 -- ;
}
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_5 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
V_14 = V_13 = F_2 ( T_4 , V_2 , V_5 ) ;
if ( F_3 ( V_15 , V_1 , V_13 ) )
return - V_16 ;
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_6 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
unsigned char * V_6 = ( unsigned char * )
( V_7 . V_8 . V_9 == V_10 ? V_11 : V_12 ) ;
unsigned int V_17 = V_18 ;
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
if ( V_19 < 0 ) {
if ( V_2 == 0 )
break;
if ( F_7 ( V_27 , V_1 ++ ) )
return - V_16 ;
V_17 = V_6 [ V_27 ] ;
V_17 += 0x80 ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static T_1 F_8 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
unsigned int V_17 = V_18 ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
if ( V_19 < 0 ) {
if ( V_2 == 0 )
break;
if ( F_7 ( V_27 , V_1 ++ ) )
return - V_16 ;
V_17 = V_27 ;
V_17 += 0x80 ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static T_1 F_9 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
unsigned int V_17 = V_18 ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
if ( V_19 < 0 ) {
if ( V_2 == 0 )
break;
if ( F_7 ( V_27 , V_1 ++ ) )
return - V_16 ;
V_17 = V_27 ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static T_1 F_10 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
unsigned char * V_6 = ( unsigned char * )
( V_7 . V_8 . V_9 == V_10 ? V_11 : V_12 ) ;
unsigned int V_17 = V_18 ;
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
while( V_19 < 0 ) {
if ( V_2 == 0 )
goto V_28;
if ( ! ( V_19 < ( - V_21 ) ) ) {
if ( F_7 ( V_27 , V_1 ) )
return - V_16 ;
V_17 = 0x80 + V_6 [ V_27 ] ;
}
V_1 ++ ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_28:
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static T_1 F_11 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
unsigned int V_17 = V_18 ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
while ( V_19 < 0 ) {
if ( V_2 == 0 )
goto V_28;
if ( ! ( V_19 < ( - V_21 ) ) ) {
if ( F_7 ( V_27 , V_1 ) )
return - V_16 ;
V_17 = V_27 + 0x80 ;
}
V_1 ++ ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_28:
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static T_1 F_12 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_2 * V_15 = ( T_2 * ) & V_3 [ * V_4 ] ;
unsigned int V_17 = V_18 ;
int V_19 = V_20 ;
int V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
int V_25 , V_26 ;
V_26 = V_5 ;
V_25 = V_2 ;
while ( V_5 ) {
T_2 V_27 ;
while ( V_19 < 0 ) {
if ( V_2 == 0 )
goto V_28;
if ( ! ( V_19 < ( - V_21 ) ) ) {
if ( F_7 ( V_27 , V_1 ) )
return - V_16 ;
V_17 = V_27 ;
}
V_1 ++ ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_28:
V_20 = V_19 ;
V_18 = V_17 ;
* V_4 += ( V_26 - V_5 ) ;
V_25 -= V_2 ;
return V_25 ;
}
static void * F_13 ( unsigned int V_29 , T_5 V_30 )
{
return F_14 ( V_29 , V_30 ) ;
}
static void F_15 ( void * V_31 , unsigned int V_29 )
{
F_16 ( V_31 ) ;
}
static int T_6 F_17 ( void )
{
if ( F_18 ( V_32 , V_33 , 0 ,
L_1 , V_34 ) )
return 0 ;
return ( 1 ) ;
}
static void F_19 ( void )
{
F_20 ( 0 , V_35 ) ;
F_21 ( V_32 , V_34 ) ;
}
static void F_22 ( void )
{
F_20 ( 0 , V_35 ) ;
* V_36 = * V_37 = 127 ;
}
static void F_23 ( int V_38 )
{
T_2 * V_39 ;
T_7 V_29 ;
T_2 V_23 ;
int error ;
V_39 = V_40 . V_41 [ V_40 . V_42 ] ;
V_29 = ( V_40 . V_13 == V_38 ? V_40 . V_43 : V_40 . V_44 ) ;
V_45 = V_39 ;
V_46 = V_29 ;
V_40 . V_42 = ( V_40 . V_42 + 1 ) % V_40 . V_47 ;
V_40 . V_48 ++ ;
V_23 = ( V_7 . V_22 . V_23 == 10000 ? 0 : 1 ) ;
F_20 ( 0 , V_35 ) ;
F_21 ( V_32 , V_34 ) ;
if ( V_7 . V_8 . V_49 )
error = F_18 ( V_32 , V_33 , 0 ,
L_2 , V_34 ) ;
else
error = F_18 ( V_32 , V_50 , 0 ,
L_2 , V_34 ) ;
if ( error && F_24 () )
F_25 ( L_3 ) ;
F_20 ( V_23 , V_51 ) ;
F_20 ( 1 , V_52 ) ;
F_20 ( 1 , V_35 ) ;
}
static void F_26 ( void )
{
unsigned long V_30 ;
if ( V_40 . V_48 || V_40 . V_13 <= 0 ) {
return;
}
if ( V_40 . V_13 <= 1 && V_40 . V_43 < V_40 . V_44 && ! V_40 . V_53 ) {
return;
}
F_27 ( & V_7 . V_54 , V_30 ) ;
F_23 ( 1 ) ;
F_28 ( & V_7 . V_54 , V_30 ) ;
}
static T_8 V_33 ( int V_55 , void * V_56 )
{
F_29 ( & V_7 . V_54 ) ;
if ( V_46 > 1 ) {
* V_36 = * V_45 ++ ;
* V_37 = * V_45 ++ ;
V_46 -= 2 ;
F_20 ( 1 , V_52 ) ;
} else V_34 () ;
F_30 ( & V_7 . V_54 ) ;
return V_57 ;
}
static T_8 V_50 ( int V_55 , void * V_56 )
{
F_29 ( & V_7 . V_54 ) ;
if ( V_46 > 0 ) {
* V_36 = * V_45 ;
* V_37 = * V_45 ++ ;
V_46 -- ;
F_20 ( 1 , V_52 ) ;
} else V_34 () ;
F_30 ( & V_7 . V_54 ) ;
return V_57 ;
}
static void V_34 ( void )
{
if ( ! V_40 . V_48 ) {
F_31 ( V_40 . V_58 ) ;
F_20 ( 0 , V_35 ) ;
goto exit;
} else V_40 . V_48 = 0 ;
V_40 . V_13 -- ;
F_26 () ;
if ( V_46 < 2 )
{
F_20 ( 0 , V_35 ) ;
* V_36 = * V_37 = 127 ;
}
F_31 ( V_40 . V_59 ) ;
exit:
F_20 ( 1 , V_52 ) ;
}
static void F_32 ( void )
{
int V_60 , V_61 ;
const int V_62 [] = { 10000 , 20000 } ;
V_61 = - 1 ;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ )
if ( ( 100 * abs ( V_7 . V_8 . V_23 - V_62 [ V_60 ] ) / V_62 [ V_60 ] ) <= V_63 )
V_61 = V_60 ;
V_7 . V_22 = V_7 . V_8 ;
V_7 . V_22 . V_29 = 8 ;
if ( V_61 > - 1 ) {
V_7 . V_8 . V_23 = V_62 [ V_61 ] ;
V_7 . V_64 = & V_65 ;
} else
V_7 . V_64 = & V_66 ;
F_22 () ;
if ( V_7 . V_22 . V_23 > 20200 ) {
V_7 . V_22 . V_23 = 20000 ;
V_7 . V_64 = & V_67 ;
} else if ( V_7 . V_22 . V_23 > 10000 ) {
V_7 . V_22 . V_23 = 20000 ;
} else {
V_7 . V_22 . V_23 = 10000 ;
}
V_20 = - V_7 . V_8 . V_23 ;
}
static int F_33 ( int V_9 )
{
switch ( V_9 ) {
case V_68 :
return ( V_7 . V_8 . V_9 ) ;
case V_10 :
case V_69 :
case V_70 :
case V_71 :
break;
default:
V_9 = V_70 ;
}
V_7 . V_8 . V_9 = V_9 ;
V_7 . V_8 . V_29 = 8 ;
if ( V_7 . V_72 == V_73 ) {
V_7 . V_74 . V_9 = V_9 ;
V_7 . V_74 . V_29 = 8 ;
}
F_32 () ;
return ( V_9 ) ;
}
static int F_34 ( int V_75 )
{
return 0 ;
}
static int T_6 F_35 ( void )
{
if ( V_76 ) {
V_7 . V_77 = V_78 ;
V_7 . V_77 . V_79 = V_80 ;
V_7 . V_77 . V_81 = V_82 ;
return F_36 () ;
} else
return - V_83 ;
}
static void T_9 F_37 ( void )
{
F_38 () ;
}
