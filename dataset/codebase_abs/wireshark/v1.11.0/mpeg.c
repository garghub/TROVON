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
F_9 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 , T_4 * V_16 )
{
T_7 * V_17 = ( T_7 * ) V_1 -> V_18 ;
T_5 V_10 ;
int V_11 = F_5 ( V_1 , V_2 , T_3 , & V_10 ) ;
unsigned int V_19 ;
struct V_20 V_21 = V_17 -> V_22 ;
if ( V_11 == - 1 )
return FALSE ;
if ( F_10 ( V_10 ) ) {
T_4 V_4 = F_2 ( V_1 -> V_5 ) ;
T_8 V_23 ;
if ( V_4 == - 1 )
return - 1 ;
if ( F_4 ( V_1 -> V_5 , 3 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_11 = F_6 ( & V_23 , sizeof V_23 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_23 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
return FALSE ;
}
if ( V_23 == 0xba ) {
T_5 V_24 ;
T_5 V_25 ;
T_9 V_26 ;
T_8 V_27 ;
V_11 = F_6 ( & V_24 , sizeof V_24 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_24 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_11 = F_6 ( & V_25 , sizeof V_25 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_25 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_26 = ( T_9 ) F_8 ( V_24 ) << 32 | F_8 ( V_25 ) ;
switch ( V_26 >> 62 ) {
case 1 :
if ( F_4 ( V_1 -> V_5 , 1 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_11 = F_6 ( & V_27 ,
sizeof V_27 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_27 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
return FALSE ;
}
V_27 &= 0x07 ;
V_19 = 14 + V_27 ;
{
T_9 V_28 = V_26 >> 16 ;
T_9 V_29 =
( V_28 >> 43 & 0x0007 ) << 30 |
( V_28 >> 27 & 0x7fff ) << 15 |
( V_28 >> 11 & 0x7fff ) << 0 ;
T_10 V_30 = ( T_10 ) ( ( V_28 >> 1 ) & 0x1ff ) ;
T_9 V_31 = 300 * V_29 + V_30 ;
T_10 V_32 = ( T_10 ) ( V_31 % V_33 ) ;
V_17 -> V_22 . V_34
= V_17 -> V_35 + ( V_36 ) ( V_31 / V_33 ) ;
V_17 -> V_22 . V_37
= ( int ) ( F_11 ( 1000000000 ) * V_32 / V_33 ) ;
}
V_21 = V_17 -> V_22 ;
break;
default:
V_19 = 12 ;
}
} else {
T_11 V_38 ;
V_11 = F_6 ( & V_38 , sizeof V_38 , V_1 -> V_5 ) ;
if ( V_11 != sizeof V_38 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 == 0 && V_11 != 0 )
* V_2 = V_14 ;
return FALSE ;
}
V_38 = F_12 ( V_38 ) ;
V_19 = 6 + V_38 ;
}
if ( F_4 ( V_1 -> V_5 , V_4 , V_9 , V_2 ) == - 1 )
return FALSE ;
} else {
struct V_39 V_39 ;
F_13 ( & V_39 , V_10 ) ;
if ( F_14 ( & V_39 ) ) {
V_19 = F_15 ( & V_39 ) ;
V_17 -> V_22 . V_37 += F_16 ( & V_39 ) ;
if ( V_17 -> V_22 . V_37 >= 1000000000 ) {
V_17 -> V_22 . V_34 ++ ;
V_17 -> V_22 . V_37 -= 1000000000 ;
}
} else {
V_19 = F_1 ( V_1 , V_2 , T_3 ) ;
if ( V_19 == 0 )
return FALSE ;
}
}
* V_16 = F_2 ( V_1 -> V_5 ) ;
if ( ! F_17 ( V_1 -> V_5 , V_1 -> V_40 ,
V_19 , V_2 , T_3 ) )
return FALSE ;
V_1 -> V_41 . V_42 = V_43 ;
V_1 -> V_41 . V_21 = V_21 ;
V_1 -> V_41 . V_44 = V_19 ;
V_1 -> V_41 . V_45 = V_19 ;
return TRUE ;
}
static T_6
F_18 ( T_1 * V_1 , T_4 V_46 ,
struct V_47 * V_41 V_3 , T_12 * V_48 , int V_38 ,
int * V_2 , T_2 * * T_3 )
{
if ( F_4 ( V_1 -> V_49 , V_46 , V_9 , V_2 ) == - 1 )
return FALSE ;
return F_17 ( V_1 -> V_49 , V_48 , V_38 , V_2 , T_3 ) ;
}
int
F_19 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 )
{
int V_11 ;
char V_50 [ 16 ] ;
struct V_51 * V_52 ;
T_7 * V_17 ;
V_12 = V_13 ;
V_11 = F_6 ( V_50 , sizeof V_50 , V_1 -> V_5 ) ;
if ( V_11 != ( int ) sizeof V_50 ) {
* V_2 = F_7 ( V_1 -> V_5 , T_3 ) ;
if ( * V_2 != 0 && * V_2 != V_14 )
return - 1 ;
return 0 ;
}
for ( V_52 = V_53 ; V_52 -> V_54 ; V_52 ++ ) {
if ( memcmp ( V_50 , V_52 -> V_54 , V_52 -> V_45 ) == 0 )
goto V_55;
}
return 0 ;
V_55:
if ( F_4 ( V_1 -> V_5 , 0 , V_9 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_58 = V_59 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_62 = F_9 ;
V_1 -> V_63 = F_18 ;
V_1 -> V_64 = 0 ;
V_17 = ( T_7 * ) F_20 ( sizeof( T_7 ) ) ;
V_1 -> V_18 = ( void * ) V_17 ;
V_17 -> V_22 . V_34 = 0 ;
V_17 -> V_22 . V_37 = 0 ;
V_17 -> V_35 = V_17 -> V_22 . V_34 ;
return 1 ;
}
