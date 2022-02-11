static int
F_1 ( T_1 V_1 , int * V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
int V_4 = 0 ;
int V_5 = F_3 ( V_1 ) ;
while ( V_5 != V_6 ) {
if ( V_5 == 0xff && V_4 > 0 ) {
V_5 = F_3 ( V_1 ) ;
if ( V_5 != V_6 && ( V_5 & 0xe0 ) == 0xe0 )
break;
} else
V_5 = F_3 ( V_1 ) ;
V_4 ++ ;
}
if ( F_4 ( V_1 , V_3 , V_7 , V_2 ) == - 1 )
return 0 ;
return V_4 ;
}
static T_3
F_5 ( T_4 * V_8 , T_1 V_1 , struct V_9 * V_10 , T_5 * V_11 ,
T_3 V_12 , int * V_2 , T_6 * * V_13 )
{
T_7 * V_14 = ( T_7 * ) V_8 -> V_15 ;
T_8 V_16 ;
unsigned int V_17 ;
T_9 V_18 = V_14 -> V_19 ;
if ( ! F_6 ( V_1 , & V_16 , sizeof V_16 , V_2 , V_13 ) )
return FALSE ;
if ( F_4 ( V_1 , - ( T_2 ) ( sizeof V_16 ) , V_20 , V_2 ) == - 1 )
return FALSE ;
V_16 = F_7 ( V_16 ) ;
if ( F_8 ( V_16 ) ) {
T_2 V_3 = F_2 ( V_1 ) ;
T_10 V_21 ;
if ( ! F_9 ( V_1 , NULL , 3 , V_2 , V_13 ) )
return FALSE ;
if ( ! F_9 ( V_1 , & V_21 , sizeof V_21 , V_2 , V_13 ) )
return FALSE ;
if ( V_21 == 0xba ) {
T_8 V_22 ;
T_8 V_23 ;
T_11 V_24 ;
T_10 V_25 ;
if ( ! F_9 ( V_1 , & V_22 , sizeof V_22 , V_2 , V_13 ) )
return FALSE ;
if ( ! F_9 ( V_1 , & V_23 , sizeof V_23 , V_2 , V_13 ) )
return FALSE ;
V_24 = ( T_11 ) F_7 ( V_22 ) << 32 | F_7 ( V_23 ) ;
switch ( V_24 >> 62 ) {
case 1 :
if ( ! F_9 ( V_1 , NULL , 1 , V_2 ,
V_13 ) )
return FALSE ;
if ( ! F_9 ( V_1 , & V_25 ,
sizeof V_25 , V_2 , V_13 ) )
return FALSE ;
V_25 &= 0x07 ;
V_17 = 14 + V_25 ;
if ( ! V_12 ) {
T_11 V_26 = V_24 >> 16 ;
T_11 V_27 =
( V_26 >> 43 & 0x0007 ) << 30 |
( V_26 >> 27 & 0x7fff ) << 15 |
( V_26 >> 11 & 0x7fff ) << 0 ;
T_12 V_28 = ( T_12 ) ( ( V_26 >> 1 ) & 0x1ff ) ;
T_11 V_29 = 300 * V_27 + V_28 ;
T_12 V_30 = ( T_12 ) ( V_29 % V_31 ) ;
V_14 -> V_19 . V_32
= V_14 -> V_33 + ( V_34 ) ( V_29 / V_31 ) ;
V_14 -> V_19 . V_35
= ( int ) ( F_10 ( 1000000000 ) * V_30 / V_31 ) ;
}
V_18 = V_14 -> V_19 ;
break;
default:
V_17 = 12 ;
}
} else {
T_13 V_36 ;
if ( ! F_9 ( V_1 , & V_36 , sizeof V_36 , V_2 , V_13 ) )
return FALSE ;
V_36 = F_11 ( V_36 ) ;
V_17 = 6 + V_36 ;
}
if ( F_4 ( V_1 , V_3 , V_7 , V_2 ) == - 1 )
return FALSE ;
} else {
struct V_37 V_37 ;
F_12 ( & V_37 , V_16 ) ;
if ( F_13 ( & V_37 ) ) {
V_17 = F_14 ( & V_37 ) ;
if ( ! V_12 ) {
V_14 -> V_19 . V_35 += F_15 ( & V_37 ) ;
if ( V_14 -> V_19 . V_35 >= 1000000000 ) {
V_14 -> V_19 . V_32 ++ ;
V_14 -> V_19 . V_35 -= 1000000000 ;
}
}
} else {
V_17 = F_1 ( V_1 , V_2 ) ;
if ( V_17 == 0 )
return FALSE ;
}
}
if ( ! F_16 ( V_1 , V_11 , V_17 , V_2 , V_13 ) )
return FALSE ;
V_10 -> V_38 = V_39 ;
if ( ! V_12 ) {
V_10 -> V_40 = V_41 ;
V_10 -> V_18 = V_18 ;
}
V_10 -> V_42 = V_17 ;
V_10 -> V_43 = V_17 ;
return TRUE ;
}
static T_3
F_17 ( T_4 * V_8 , int * V_2 , T_6 * * V_13 , T_2 * V_44 )
{
* V_44 = F_2 ( V_8 -> V_1 ) ;
return F_5 ( V_8 , V_8 -> V_1 , & V_8 -> V_10 , V_8 -> V_45 ,
FALSE , V_2 , V_13 ) ;
}
static T_3
F_18 ( T_4 * V_8 , T_2 V_46 ,
struct V_9 * V_10 , T_5 * V_11 ,
int * V_2 , T_6 * * V_13 )
{
if ( F_4 ( V_8 -> V_47 , V_46 , V_7 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_5 ( V_8 , V_8 -> V_47 , V_10 , V_11 , TRUE , V_2 ,
V_13 ) ) {
if ( * V_2 == 0 )
* V_2 = V_48 ;
return FALSE ;
}
return TRUE ;
}
T_14
F_19 ( T_4 * V_8 , int * V_2 , T_6 * * V_13 )
{
char V_49 [ 16 ] ;
struct V_50 * V_51 ;
T_7 * V_14 ;
if ( ! F_9 ( V_8 -> V_1 , V_49 , sizeof V_49 ,
V_2 , V_13 ) ) {
if ( * V_2 != V_48 )
return V_52 ;
return V_53 ;
}
for ( V_51 = V_54 ; V_51 -> V_55 ; V_51 ++ ) {
if ( memcmp ( V_49 , V_51 -> V_55 , V_51 -> V_43 ) == 0 )
goto V_56;
}
return V_53 ;
V_56:
if ( F_4 ( V_8 -> V_1 , 0 , V_7 , V_2 ) == - 1 )
return V_52 ;
V_8 -> V_57 = V_58 ;
V_8 -> V_59 = V_60 ;
V_8 -> V_61 = V_62 ;
V_8 -> V_63 = F_17 ;
V_8 -> V_64 = F_18 ;
V_8 -> V_65 = 0 ;
V_14 = ( T_7 * ) F_20 ( sizeof( T_7 ) ) ;
V_8 -> V_15 = ( void * ) V_14 ;
V_14 -> V_19 . V_32 = 0 ;
V_14 -> V_19 . V_35 = 0 ;
V_14 -> V_33 = V_14 -> V_19 . V_32 ;
return V_66 ;
}
