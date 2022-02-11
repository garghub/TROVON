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
static int
F_5 ( T_1 V_1 , int * V_2 , T_3 * * V_8 , T_4 * V_9 )
{
int V_10 ;
V_11 = V_12 ;
V_10 = F_6 ( V_9 , sizeof *V_9 , V_1 ) ;
if ( V_10 != sizeof *V_9 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
if ( * V_2 == 0 && V_10 != 0 )
* V_2 = V_13 ;
return - 1 ;
}
* V_9 = F_8 ( * V_9 ) ;
if ( F_4 ( V_1 , - ( T_2 ) ( sizeof *V_9 ) , V_14 , V_2 ) == - 1 )
return - 1 ;
return V_10 ;
}
static T_5
F_9 ( T_6 * V_15 , T_1 V_1 , struct V_16 * V_17 , T_7 * V_18 ,
T_5 V_19 , int * V_2 , T_3 * * V_8 )
{
T_8 * V_20 = ( T_8 * ) V_15 -> V_21 ;
T_4 V_9 ;
int V_10 ;
unsigned int V_22 ;
T_9 V_23 = V_20 -> V_24 ;
V_10 = F_5 ( V_1 , V_2 , V_8 , & V_9 ) ;
if ( V_10 == - 1 )
return FALSE ;
if ( F_10 ( V_9 ) ) {
T_2 V_3 = F_2 ( V_1 ) ;
T_10 V_25 ;
if ( F_4 ( V_1 , 3 , V_14 , V_2 ) == - 1 )
return FALSE ;
V_10 = F_6 ( & V_25 , sizeof V_25 , V_1 ) ;
if ( V_10 != sizeof V_25 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
return FALSE ;
}
if ( V_25 == 0xba ) {
T_4 V_26 ;
T_4 V_27 ;
T_11 V_28 ;
T_10 V_29 ;
V_10 = F_6 ( & V_26 , sizeof V_26 , V_1 ) ;
if ( V_10 != sizeof V_26 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
if ( * V_2 == 0 && V_10 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_10 = F_6 ( & V_27 , sizeof V_27 , V_1 ) ;
if ( V_10 != sizeof V_27 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
if ( * V_2 == 0 && V_10 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_28 = ( T_11 ) F_8 ( V_26 ) << 32 | F_8 ( V_27 ) ;
switch ( V_28 >> 62 ) {
case 1 :
if ( F_4 ( V_1 , 1 , V_14 , V_2 ) == - 1 )
return FALSE ;
V_10 = F_6 ( & V_29 ,
sizeof V_29 , V_1 ) ;
if ( V_10 != sizeof V_29 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
return FALSE ;
}
V_29 &= 0x07 ;
V_22 = 14 + V_29 ;
if ( ! V_19 ) {
T_11 V_30 = V_28 >> 16 ;
T_11 V_31 =
( V_30 >> 43 & 0x0007 ) << 30 |
( V_30 >> 27 & 0x7fff ) << 15 |
( V_30 >> 11 & 0x7fff ) << 0 ;
T_12 V_32 = ( T_12 ) ( ( V_30 >> 1 ) & 0x1ff ) ;
T_11 V_33 = 300 * V_31 + V_32 ;
T_12 V_34 = ( T_12 ) ( V_33 % V_35 ) ;
V_20 -> V_24 . V_36
= V_20 -> V_37 + ( V_38 ) ( V_33 / V_35 ) ;
V_20 -> V_24 . V_39
= ( int ) ( F_11 ( 1000000000 ) * V_34 / V_35 ) ;
}
V_23 = V_20 -> V_24 ;
break;
default:
V_22 = 12 ;
}
} else {
T_13 V_40 ;
V_10 = F_6 ( & V_40 , sizeof V_40 , V_1 ) ;
if ( V_10 != sizeof V_40 ) {
* V_2 = F_7 ( V_1 , V_8 ) ;
if ( * V_2 == 0 && V_10 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_40 = F_12 ( V_40 ) ;
V_22 = 6 + V_40 ;
}
if ( F_4 ( V_1 , V_3 , V_7 , V_2 ) == - 1 )
return FALSE ;
} else {
struct V_41 V_41 ;
F_13 ( & V_41 , V_9 ) ;
if ( F_14 ( & V_41 ) ) {
V_22 = F_15 ( & V_41 ) ;
if ( ! V_19 ) {
V_20 -> V_24 . V_39 += F_16 ( & V_41 ) ;
if ( V_20 -> V_24 . V_39 >= 1000000000 ) {
V_20 -> V_24 . V_36 ++ ;
V_20 -> V_24 . V_39 -= 1000000000 ;
}
}
} else {
V_22 = F_1 ( V_1 , V_2 ) ;
if ( V_22 == 0 )
return FALSE ;
}
}
if ( ! F_17 ( V_1 , V_18 , V_22 , V_2 , V_8 ) )
return FALSE ;
V_17 -> V_42 = V_43 ;
if ( ! V_19 ) {
V_17 -> V_44 = V_45 ;
V_17 -> V_23 = V_23 ;
}
V_17 -> V_46 = V_22 ;
V_17 -> V_47 = V_22 ;
return TRUE ;
}
static T_5
F_18 ( T_6 * V_15 , int * V_2 , T_3 * * V_8 , T_2 * V_48 )
{
* V_48 = F_2 ( V_15 -> V_1 ) ;
return F_9 ( V_15 , V_15 -> V_1 , & V_15 -> V_17 , V_15 -> V_49 ,
FALSE , V_2 , V_8 ) ;
}
static T_5
F_19 ( T_6 * V_15 , T_2 V_50 ,
struct V_16 * V_17 , T_7 * V_18 ,
int * V_2 , T_3 * * V_8 )
{
if ( F_4 ( V_15 -> V_51 , V_50 , V_7 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_9 ( V_15 , V_15 -> V_51 , V_17 , V_18 , TRUE , V_2 ,
V_8 ) ) {
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
int
F_20 ( T_6 * V_15 , int * V_2 , T_3 * * V_8 )
{
int V_10 ;
char V_52 [ 16 ] ;
struct V_53 * V_54 ;
T_8 * V_20 ;
V_11 = V_12 ;
V_10 = F_6 ( V_52 , sizeof V_52 , V_15 -> V_1 ) ;
if ( V_10 != ( int ) sizeof V_52 ) {
* V_2 = F_7 ( V_15 -> V_1 , V_8 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
for ( V_54 = V_55 ; V_54 -> V_56 ; V_54 ++ ) {
if ( memcmp ( V_52 , V_54 -> V_56 , V_54 -> V_47 ) == 0 )
goto V_57;
}
return 0 ;
V_57:
if ( F_4 ( V_15 -> V_1 , 0 , V_7 , V_2 ) == - 1 )
return - 1 ;
V_15 -> V_58 = V_59 ;
V_15 -> V_60 = V_61 ;
V_15 -> V_62 = V_63 ;
V_15 -> V_64 = F_18 ;
V_15 -> V_65 = F_19 ;
V_15 -> V_66 = 0 ;
V_20 = ( T_8 * ) F_21 ( sizeof( T_8 ) ) ;
V_15 -> V_21 = ( void * ) V_20 ;
V_20 -> V_24 . V_36 = 0 ;
V_20 -> V_24 . V_39 = 0 ;
V_20 -> V_37 = V_20 -> V_24 . V_36 ;
return 1 ;
}
