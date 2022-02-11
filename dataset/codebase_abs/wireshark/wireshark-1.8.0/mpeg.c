static int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 V_3 )
{
T_4 V_4 = F_2 ( V_1 -> V_5 ) ;
int V_6 = 0 ;
int V_7 = F_3 ( V_1 -> V_5 ) ;
while ( V_7 != V_8 ) {
if ( V_7 == 0xff && V_6 > 0 ) {
V_7 = F_3 ( V_1 -> V_5 ) ;
if ( V_7 != V_8 && ( V_7 & 0xe0 ) == 0xe0 )
break;
} else
V_7 = F_3 ( V_1 -> V_5 ) ;
V_6 ++ ;
}
if ( F_4 ( V_1 -> V_5 , V_4 , V_9 , V_2 ) == - 1 )
return 0 ;
return V_6 ;
}
static int
F_5 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 , T_5 * V_10 )
{
int V_11 ;
V_12 = V_13 ;
V_11 = F_6 ( V_10 , sizeof *V_10 , V_1 -> V_5 ) ;
if ( V_11 != sizeof *V_10 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return - 1 ;
}
* V_10 = F_8 ( * V_10 ) ;
if ( F_4 ( V_1 -> V_5 , - ( T_4 ) ( sizeof *V_10 ) , V_15 , V_2 ) == - 1 )
return - 1 ;
return V_11 ;
}
static T_6
F_9 ( T_7 V_5 , T_8 * V_16 , int V_17 , int * V_2 ,
T_2 * * T_3 )
{
int V_11 ;
V_12 = V_13 ;
V_11 = F_6 ( V_16 , V_17 , V_5 ) ;
if ( V_11 != V_17 ) {
* V_2 = F_7 ( V_5 , T_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_14 ;
return FALSE ;
}
return TRUE ;
}
static T_6
F_10 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 , T_4 * V_18 )
{
T_9 * V_19 = ( T_9 * ) V_1 -> V_20 ;
T_5 V_10 ;
int V_11 = F_5 ( V_1 , V_2 , T_3 , & V_10 ) ;
unsigned int V_21 ;
struct V_22 V_23 = V_19 -> V_24 ;
if ( V_11 == - 1 )
return FALSE ;
if ( F_11 ( V_10 ) ) {
T_4 V_4 = F_2 ( V_1 -> V_5 ) ;
T_8 V_25 ;
if ( V_4 == - 1 )
return - 1 ;
if ( F_4 ( V_1 -> V_5 , 3 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_11 = F_6 ( & V_25 , sizeof V_25 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_25 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
return FALSE ;
}
if ( V_25 == 0xba ) {
T_5 V_26 ;
T_5 V_27 ;
T_10 V_28 ;
T_8 V_29 ;
V_11 = F_6 ( & V_26 , sizeof V_26 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_26 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_11 = F_6 ( & V_27 , sizeof V_27 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_27 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_28 = ( T_10 ) F_8 ( V_26 ) << 32 | F_8 ( V_27 ) ;
switch ( V_28 >> 62 ) {
case 1 :
if ( F_4 ( V_1 -> V_5 , 1 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_11 = F_6 ( & V_29 ,
sizeof V_29 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_29 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
return FALSE ;
}
V_29 &= 0x07 ;
V_21 = 14 + V_29 ;
{
T_10 V_30 = V_28 >> 16 ;
T_10 V_31 =
( V_30 >> 43 & 0x0007 ) << 30 |
( V_30 >> 27 & 0x7fff ) << 15 |
( V_30 >> 11 & 0x7fff ) << 0 ;
unsigned V_32 = ( unsigned ) ( ( V_30 >> 1 ) & 0x1ff ) ;
T_10 V_33 = 300 * V_31 + V_32 ;
unsigned V_34 = ( unsigned ) ( V_33 % V_35 ) ;
V_19 -> V_24 . V_36
= V_19 -> V_37 + ( V_38 ) ( V_33 / V_35 ) ;
V_19 -> V_24 . V_39
= ( int ) ( F_12 ( 1000000000 ) * V_34 / V_35 ) ;
}
V_23 = V_19 -> V_24 ;
break;
default:
V_21 = 12 ;
}
} else {
T_11 V_17 ;
V_11 = F_6 ( & V_17 , sizeof V_17 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_17 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_17 = F_13 ( V_17 ) ;
V_21 = 6 + V_17 ;
}
if ( F_4 ( V_1 -> V_5 , V_4 , V_9 , V_2 ) == - 1 )
return FALSE ;
} else {
struct V_40 V_40 ;
F_14 ( & V_40 , V_10 ) ;
if ( F_15 ( & V_40 ) ) {
V_21 = F_16 ( & V_40 ) ;
V_19 -> V_24 . V_39 += F_17 ( & V_40 ) ;
if ( V_19 -> V_24 . V_39 >= 1000000000 ) {
V_19 -> V_24 . V_36 ++ ;
V_19 -> V_24 . V_39 -= 1000000000 ;
}
} else {
V_21 = F_1 ( V_1 , V_2 , T_3 ) ;
if ( V_21 == 0 )
return FALSE ;
}
}
* V_18 = F_2 ( V_1 -> V_5 ) ;
F_18 ( V_1 -> V_41 , V_21 ) ;
if ( ! F_9 ( V_1 -> V_5 , F_19 ( V_1 -> V_41 ) ,
V_21 , V_2 , T_3 ) )
return FALSE ;
V_1 -> V_42 . V_43 = V_44 ;
V_1 -> V_42 . V_23 = V_23 ;
V_1 -> V_42 . V_45 = V_21 ;
V_1 -> V_42 . V_46 = V_21 ;
return TRUE ;
}
static T_6
F_20 ( T_1 * V_1 , T_4 V_47 ,
union V_48 * T_12 V_3 , T_8 * V_16 , int V_17 ,
int * V_2 , T_2 * * T_3 )
{
if ( F_4 ( V_1 -> V_49 , V_47 , V_9 , V_2 ) == - 1 )
return FALSE ;
return F_9 ( V_1 -> V_49 , V_16 , V_17 , V_2 , T_3 ) ;
}
int
F_21 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 )
{
int V_11 ;
char V_50 [ 16 ] ;
struct V_51 * V_52 ;
T_9 * V_19 ;
V_12 = V_13 ;
V_11 = F_6 ( V_50 , sizeof V_50 , V_1 -> V_5 ) ;
if ( V_11 != ( int ) sizeof V_50 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
for ( V_52 = V_53 ; V_52 -> V_54 ; V_52 ++ ) {
if ( memcmp ( V_50 , V_52 -> V_54 , V_52 -> V_46 ) == 0 )
goto V_55;
}
return 0 ;
V_55:
if ( F_4 ( V_1 -> V_5 , 0 , V_9 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_58 = V_59 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_62 = F_10 ;
V_1 -> V_63 = F_20 ;
V_1 -> V_64 = 0 ;
V_19 = ( T_9 * ) F_22 ( sizeof( T_9 ) ) ;
V_1 -> V_20 = ( void * ) V_19 ;
V_19 -> V_24 . V_36 = 0 ;
V_19 -> V_24 . V_39 = 0 ;
V_19 -> V_37 = V_19 -> V_24 . V_36 ;
return 1 ;
}
