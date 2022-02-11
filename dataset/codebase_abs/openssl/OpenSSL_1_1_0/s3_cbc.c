static void F_1 ( void * V_1 , unsigned char * V_2 )
{
T_1 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , V_2 ) ;
F_2 ( V_3 -> V_5 , V_2 ) ;
F_2 ( V_3 -> V_6 , V_2 ) ;
F_2 ( V_3 -> V_7 , V_2 ) ;
}
static void F_3 ( void * V_1 , unsigned char * V_2 )
{
T_2 * V_8 = V_1 ;
F_4 ( V_8 -> V_9 , V_2 ) ;
F_4 ( V_8 -> V_10 , V_2 ) ;
F_4 ( V_8 -> V_11 , V_2 ) ;
F_4 ( V_8 -> V_12 , V_2 ) ;
F_4 ( V_8 -> V_13 , V_2 ) ;
}
static void F_5 ( void * V_1 , unsigned char * V_2 )
{
T_3 * V_14 = V_1 ;
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
F_4 ( V_14 -> V_16 [ V_15 ] , V_2 ) ;
}
}
static void F_6 ( void * V_1 , unsigned char * V_2 )
{
T_4 * V_17 = V_1 ;
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
F_7 ( V_17 -> V_16 [ V_15 ] , V_2 ) ;
}
}
char F_8 ( const T_5 * V_1 )
{
if ( F_9 () )
return 0 ;
switch ( F_10 ( V_1 ) ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return 1 ;
default:
return 0 ;
}
}
int F_11 ( const T_5 * V_1 ,
unsigned char * V_2 ,
T_6 * V_24 ,
const unsigned char V_25 [ 13 ] ,
const unsigned char * V_26 ,
T_6 V_27 ,
T_6 V_28 ,
const unsigned char * V_29 ,
unsigned V_30 , char V_31 )
{
union {
double V_32 ;
unsigned char V_33 [ sizeof( V_34 ) ] ;
} V_35 ;
void (* F_12) ( void * V_1 , unsigned char * V_2 );
void (* F_13) ( void * V_1 , const unsigned char * V_36 );
unsigned V_37 , V_38 = 64 ;
unsigned V_39 = 40 , V_40 , V_41 ,
V_42 , V_43 , V_44 ,
V_45 , V_46 , V_47 , V_33 , V_48 , V_49 ;
unsigned int V_50 ;
unsigned char V_51 [ V_52 ] ;
unsigned char V_53 [ V_54 ] ;
unsigned char V_55 [ V_54 ] ;
unsigned char V_56 [ V_57 ] ;
unsigned V_15 , V_58 , V_59 ;
T_5 * V_60 = NULL ;
unsigned V_61 = 8 ;
char V_62 = 1 ;
int V_63 ;
F_14 ( V_28 < 1024 * 1024 ) ;
switch ( F_10 ( V_1 ) ) {
case V_18 :
if ( F_15 ( ( T_1 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_1 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_64 ;
V_37 = 16 ;
V_39 = 48 ;
V_62 = 0 ;
break;
case V_19 :
if ( F_16 ( ( T_2 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_3 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_65 ;
V_37 = 20 ;
break;
case V_20 :
if ( F_17 ( ( T_3 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_5 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_66 ;
V_37 = 224 / 8 ;
break;
case V_21 :
if ( F_18 ( ( T_3 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_5 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_66 ;
V_37 = 32 ;
break;
case V_22 :
if ( F_19 ( ( T_4 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_6 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_67 ;
V_37 = 384 / 8 ;
V_38 = 128 ;
V_61 = 16 ;
break;
case V_23 :
if ( F_20 ( ( T_4 * ) V_35 . V_33 ) <= 0 )
return 0 ;
F_12 = F_6 ;
F_13 =
( void (*) ( void * V_1 , const unsigned char * V_36 ) ) V_67 ;
V_37 = 64 ;
V_38 = 128 ;
V_61 = 16 ;
break;
default:
F_14 ( 0 ) ;
if ( V_24 )
* V_24 = 0 ;
return 0 ;
}
F_14 ( V_61 <= V_52 ) ;
F_14 ( V_38 <= V_54 ) ;
F_14 ( V_37 <= V_57 ) ;
V_40 = 13 ;
if ( V_31 ) {
V_40 = V_30 + V_39 + 8 +
1 +
2 ;
}
V_41 = V_31 ? 2 : 6 ;
V_42 = V_28 + V_40 ;
V_43 = V_42 - V_37 - 1 ;
V_44 =
( V_43 + 1 + V_61 + V_38 -
1 ) / V_38 ;
V_45 = 0 ;
V_46 = 0 ;
V_47 = V_27 + V_40 - V_37 ;
V_33 = V_47 % V_38 ;
V_48 = V_47 / V_38 ;
V_49 = ( V_47 + V_61 ) / V_38 ;
if ( V_44 > V_41 + ( V_31 ? 1 : 0 ) ) {
V_45 = V_44 - V_41 ;
V_46 = V_38 * V_45 ;
}
V_50 = 8 * V_47 ;
if ( ! V_31 ) {
V_50 += 8 * V_38 ;
memset ( V_53 , 0 , V_38 ) ;
F_14 ( V_30 <= sizeof( V_53 ) ) ;
memcpy ( V_53 , V_29 , V_30 ) ;
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ )
V_53 [ V_15 ] ^= 0x36 ;
F_13 ( V_35 . V_33 , V_53 ) ;
}
if ( V_62 ) {
memset ( V_51 , 0 , V_61 - 4 ) ;
V_51 [ V_61 - 4 ] = ( unsigned char ) ( V_50 >> 24 ) ;
V_51 [ V_61 - 3 ] = ( unsigned char ) ( V_50 >> 16 ) ;
V_51 [ V_61 - 2 ] = ( unsigned char ) ( V_50 >> 8 ) ;
V_51 [ V_61 - 1 ] = ( unsigned char ) V_50 ;
} else {
memset ( V_51 , 0 , V_61 ) ;
V_51 [ V_61 - 5 ] = ( unsigned char ) ( V_50 >> 24 ) ;
V_51 [ V_61 - 6 ] = ( unsigned char ) ( V_50 >> 16 ) ;
V_51 [ V_61 - 7 ] = ( unsigned char ) ( V_50 >> 8 ) ;
V_51 [ V_61 - 8 ] = ( unsigned char ) V_50 ;
}
if ( V_46 > 0 ) {
if ( V_31 ) {
unsigned V_68 ;
if ( V_40 <= V_38 ) {
return 0 ;
}
V_68 = V_40 - V_38 ;
F_13 ( V_35 . V_33 , V_25 ) ;
memcpy ( V_55 , V_25 + V_38 , V_68 ) ;
memcpy ( V_55 + V_68 , V_26 , V_38 - V_68 ) ;
F_13 ( V_35 . V_33 , V_55 ) ;
for ( V_15 = 1 ; V_15 < V_46 / V_38 - 1 ; V_15 ++ )
F_13 ( V_35 . V_33 , V_26 + V_38 * V_15 - V_68 ) ;
} else {
memcpy ( V_55 , V_25 , 13 ) ;
memcpy ( V_55 + 13 , V_26 , V_38 - 13 ) ;
F_13 ( V_35 . V_33 , V_55 ) ;
for ( V_15 = 1 ; V_15 < V_46 / V_38 ; V_15 ++ )
F_13 ( V_35 . V_33 , V_26 + V_38 * V_15 - 13 ) ;
}
}
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
for ( V_15 = V_45 ; V_15 <= V_45 + V_41 ;
V_15 ++ ) {
unsigned char V_36 [ V_54 ] ;
unsigned char V_69 = F_21 ( V_15 , V_48 ) ;
unsigned char V_70 = F_21 ( V_15 , V_49 ) ;
for ( V_58 = 0 ; V_58 < V_38 ; V_58 ++ ) {
unsigned char V_71 = 0 , V_72 , V_73 ;
if ( V_46 < V_40 )
V_71 = V_25 [ V_46 ] ;
else if ( V_46 < V_28 + V_40 )
V_71 = V_26 [ V_46 - V_40 ] ;
V_46 ++ ;
V_72 = V_69 & F_22 ( V_58 , V_33 ) ;
V_73 = V_69 & F_22 ( V_58 , V_33 + 1 ) ;
V_71 = F_23 ( V_72 , 0x80 , V_71 ) ;
V_71 = V_71 & ~ V_73 ;
V_71 &= ~ V_70 | V_69 ;
if ( V_58 >= V_38 - V_61 ) {
V_71 = F_23 ( V_70 ,
V_51 [ V_58 -
( V_38 -
V_61 ) ] , V_71 ) ;
}
V_36 [ V_58 ] = V_71 ;
}
F_13 ( V_35 . V_33 , V_36 ) ;
F_12 ( V_35 . V_33 , V_36 ) ;
for ( V_58 = 0 ; V_58 < V_37 ; V_58 ++ )
V_56 [ V_58 ] |= V_36 [ V_58 ] & V_70 ;
}
V_60 = F_24 () ;
if ( V_60 == NULL )
goto V_74;
if ( F_25 ( V_60 , F_26 ( V_1 ) , NULL ) <= 0 )
goto V_74;
if ( V_31 ) {
memset ( V_53 , 0x5c , V_39 ) ;
if ( F_27 ( V_60 , V_29 , V_30 ) <= 0
|| F_27 ( V_60 , V_53 , V_39 ) <= 0
|| F_27 ( V_60 , V_56 , V_37 ) <= 0 )
goto V_74;
} else {
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ )
V_53 [ V_15 ] ^= 0x6a ;
if ( F_27 ( V_60 , V_53 , V_38 ) <= 0
|| F_27 ( V_60 , V_56 , V_37 ) <= 0 )
goto V_74;
}
V_63 = F_28 ( V_60 , V_2 , & V_59 ) ;
if ( V_63 && V_24 )
* V_24 = V_59 ;
F_29 ( V_60 ) ;
return 1 ;
V_74:
F_29 ( V_60 ) ;
return 0 ;
}
int F_30 ( const T_7 * V_75 ,
T_5 * V_76 , const unsigned char * V_26 ,
T_6 V_77 , T_6 V_78 )
{
T_6 V_79 , V_80 , V_81 , V_82 ;
if ( F_31 ( V_75 ) != V_83 )
return 1 ;
V_79 = F_32 ( V_76 ) ;
V_80 = V_79 == 64 ? 21 : 29 ;
V_82 = ( V_78 + V_80 ) / V_79 ;
V_81 = ( V_77 + V_80 ) / V_79 ;
return F_33 ( V_76 , V_26 ,
( V_82 - V_81 + 1 ) * V_79 ) ;
}
