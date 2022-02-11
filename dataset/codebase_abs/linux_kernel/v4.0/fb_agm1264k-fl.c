static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_4 , V_2 , L_1 , V_5 ) ;
V_2 -> V_6 . V_7 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < 2 ; ++ V_3 ) {
F_3 ( V_2 , V_3 , 0x3f ) ;
F_3 ( V_2 , V_3 , 0x40 ) ;
F_3 ( V_2 , V_3 , 0xb0 ) ;
F_3 ( V_2 , V_3 , 0xc0 ) ;
}
return 0 ;
}
static void V_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_7 == - 1 )
return;
F_4 ( V_9 , V_2 , V_2 -> V_10 -> V_11 , L_1 , V_5 ) ;
F_5 ( V_2 -> V_8 . V_7 , 0 ) ;
F_6 ( 20 ) ;
F_5 ( V_2 -> V_8 . V_7 , 1 ) ;
F_7 ( 120 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
F_4 ( V_12 , V_2 , V_2 -> V_10 -> V_11 ,
L_1 , V_5 ) ;
if ( V_2 -> V_13 < 0 ) {
F_9 ( V_2 -> V_10 -> V_11 ,
L_2 ) ;
return - V_14 ;
}
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
if ( V_2 -> V_8 . V_15 [ V_3 ] < 0 ) {
F_9 ( V_2 -> V_10 -> V_11 ,
L_3 ,
V_3 ) ;
return - V_14 ;
}
}
if ( V_2 -> V_16 < 0 ) {
F_9 ( V_2 -> V_10 -> V_11 ,
L_4 ) ;
return - V_14 ;
}
if ( V_2 -> V_17 < 0 ) {
F_9 ( V_2 -> V_10 -> V_11 ,
L_5 ) ;
return - V_14 ;
}
if ( V_2 -> V_18 < 0 ) {
F_9 ( V_2 -> V_10 -> V_11 ,
L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static unsigned long
F_10 ( struct V_1 * V_2 , const struct V_19 * V_8 )
{
F_4 ( V_20 , V_2 , V_2 -> V_10 -> V_11 ,
L_7 , V_5 , V_8 -> V_21 ) ;
if ( strcasecmp ( V_8 -> V_21 , L_8 ) == 0 ) {
V_2 -> V_13 = V_8 -> V_8 ;
return V_22 ;
} else if ( strcasecmp ( V_8 -> V_21 , L_9 ) == 0 ) {
V_2 -> V_16 = V_8 -> V_8 ;
return V_23 ;
} else if ( strcasecmp ( V_8 -> V_21 , L_10 ) == 0 ) {
V_2 -> V_17 = V_8 -> V_8 ;
return V_23 ;
}
else if ( strcasecmp ( V_8 -> V_21 , L_11 ) == 0 ) {
V_2 -> V_18 = V_8 -> V_8 ;
return V_22 ;
}
return V_24 ;
}
static void F_11 ( struct V_1 * V_2 , int V_25 , ... )
{
T_2 args ;
int V_3 , V_26 ;
T_1 * V_27 = ( T_1 * ) V_2 -> V_27 ;
if ( F_12 ( V_2 -> V_28 & V_29 ) ) {
va_start ( args , V_25 ) ;
for ( V_3 = 0 ; V_3 < V_25 ; V_3 ++ )
V_27 [ V_3 ] = ( T_1 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_13 ( V_29 , V_2 ,
V_2 -> V_10 -> V_11 , T_1 , V_27 , V_25 , L_12 , V_5 ) ;
}
va_start ( args , V_25 ) ;
* V_27 = ( T_1 ) va_arg (args, unsigned int) ;
if ( * V_27 > 1 ) {
va_end ( args ) ;
F_9 ( V_2 -> V_10 -> V_11 , L_13 ,
V_5 , * V_27 ) ;
return;
}
if ( * V_27 ) {
F_5 ( V_2 -> V_16 , 1 ) ;
F_5 ( V_2 -> V_17 , 0 ) ;
} else {
F_5 ( V_2 -> V_16 , 0 ) ;
F_5 ( V_2 -> V_17 , 1 ) ;
}
F_5 ( V_2 -> V_30 , 0 ) ;
V_25 -- ;
if ( V_25 ) {
V_3 = V_25 ;
while ( V_3 -- )
* V_27 ++ = ( T_1 ) va_arg (args, unsigned int) ;
V_26 = V_2 -> V_6 . V_31 ( V_2 , V_2 -> V_27 , V_25 * ( sizeof( T_1 ) ) ) ;
if ( V_26 < 0 ) {
va_end ( args ) ;
F_9 ( V_2 -> V_10 -> V_11 , L_14 ,
V_5 , V_26 ) ;
return;
}
}
va_end ( args ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_32 , int V_33 , int V_34 , int V_35 )
{
V_36 . V_32 = V_32 ;
V_36 . V_37 = V_33 / 8 ;
V_36 . V_34 = V_34 ;
V_36 . V_38 = V_35 / 8 ;
F_2 ( V_39 , V_2 ,
L_15 , V_5 ,
V_36 . V_32 , V_36 . V_37 , V_36 . V_34 , V_36 . V_38 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 * V_40 , signed short * V_41 ,
int V_32 , int V_34 , int V_42 )
{
int V_43 , V_3 ;
for ( V_43 = V_32 ; V_43 < V_34 ; ++ V_43 ) {
T_1 V_44 = 0 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( V_41 [ ( V_42 * 8 + V_3 ) * V_2 -> V_10 -> V_45 . V_46 + V_43 ] )
V_44 |= 1 << V_3 ;
#ifdef F_16
* V_40 ++ = V_44 ;
#else
* V_40 ++ = ~ V_44 ;
#endif
}
}
static int F_17 ( struct V_1 * V_2 , T_3 V_47 , T_3 V_25 )
{
T_4 * V_48 = ( T_4 * ) V_2 -> V_10 -> V_49 ;
T_1 * V_27 = V_2 -> V_50 . V_27 ;
int V_43 , V_42 ;
int V_26 = 0 ;
signed short * V_51 = F_18 ( V_2 -> V_10 -> V_45 . V_46 *
V_2 -> V_10 -> V_45 . V_52 * sizeof( signed short ) , V_53 ) ;
F_2 ( V_54 , V_2 , L_1 , V_5 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_10 -> V_45 . V_46 ; ++ V_43 )
for ( V_42 = 0 ; V_42 < V_2 -> V_10 -> V_45 . V_52 ; ++ V_42 ) {
T_4 V_55 = V_48 [ V_42 * V_2 -> V_10 -> V_45 . V_46 + V_43 ] ;
T_4 V_56 = V_55 & 0x1f ;
T_4 V_57 = ( V_55 & ( 0x3f << 5 ) ) >> 5 ;
T_4 V_58 = ( V_55 & ( 0x1f << ( 5 + 6 ) ) ) >> ( 5 + 6 ) ;
V_55 = ( 299 * V_58 + 587 * V_57 + 114 * V_56 ) / 200 ;
if ( V_55 > 255 )
V_55 = 255 ;
V_51 [ V_42 * V_2 -> V_10 -> V_45 . V_46 + V_43 ] =
( signed short ) V_59 [ V_55 ] ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_10 -> V_45 . V_46 ; ++ V_43 )
for ( V_42 = 0 ; V_42 < V_2 -> V_10 -> V_45 . V_52 ; ++ V_42 ) {
signed short V_55 =
V_51 [ V_42 * V_2 -> V_10 -> V_45 . V_46 + V_43 ] ;
signed short V_60 = V_55 - V_61 ;
signed short V_62 = V_55 - V_63 ;
signed short error ;
T_4 V_3 , V_64 ;
if ( abs ( V_60 ) >= abs ( V_62 ) ) {
error = V_62 ;
V_55 = 0xff ;
} else {
error = V_60 ;
V_55 = 0 ;
}
error /= 8 ;
for ( V_3 = 0 ; V_3 < V_65 ; ++ V_3 )
for ( V_64 = 0 ; V_64 < V_66 ; ++ V_64 ) {
signed short * V_67 ;
signed char V_68 ;
if ( V_43 + V_3 < 0 ||
V_43 + V_3 >= V_2 -> V_10 -> V_45 . V_46
|| V_42 + V_64 >= V_2 -> V_10 -> V_45 . V_52 )
continue;
V_67 = & V_51 [
( V_42 + V_64 ) * V_2 -> V_10 -> V_45 . V_46 +
V_43 + V_3 ] ;
V_68 = V_69 [ V_3 ] [ V_64 ] ;
if ( V_68 == - 1 )
* V_67 = V_55 ;
else {
signed short V_70 = * V_67 +
error * V_68 ;
if ( V_70 > V_63 )
V_70 = V_63 ;
if ( V_70 < V_61 )
V_70 = V_61 ;
* V_67 = V_70 ;
}
}
}
for ( V_42 = V_36 . V_37 ; V_42 <= V_36 . V_38 ; ++ V_42 ) {
if ( V_36 . V_32 < V_2 -> V_10 -> V_45 . V_46 / 2 ) {
F_15 ( V_2 , V_27 , V_51 ,
V_36 . V_32 , V_2 -> V_10 -> V_45 . V_46 / 2 , V_42 ) ;
V_25 = V_2 -> V_10 -> V_45 . V_46 / 2 - V_36 . V_32 ;
F_3 ( V_2 , 0x00 , ( 1 << 6 ) | ( T_1 ) V_36 . V_32 ) ;
F_3 ( V_2 , 0x00 , ( 0x17 << 3 ) | ( T_1 ) V_42 ) ;
F_5 ( V_2 -> V_30 , 1 ) ;
V_26 = V_2 -> V_6 . V_31 ( V_2 , V_27 , V_25 ) ;
if ( V_26 < 0 )
F_9 ( V_2 -> V_10 -> V_11 ,
L_16 ,
V_5 , V_26 ) ;
}
if ( V_36 . V_34 >= V_2 -> V_10 -> V_45 . V_46 / 2 ) {
F_15 ( V_2 , V_27 ,
V_51 , V_2 -> V_10 -> V_45 . V_46 / 2 ,
V_36 . V_34 + 1 , V_42 ) ;
V_25 = V_36 . V_34 + 1 - V_2 -> V_10 -> V_45 . V_46 / 2 ;
F_3 ( V_2 , 0x01 , ( 1 << 6 ) ) ;
F_3 ( V_2 , 0x01 , ( 0x17 << 3 ) | ( T_1 ) V_42 ) ;
F_5 ( V_2 -> V_30 , 1 ) ;
V_2 -> V_6 . V_31 ( V_2 , V_27 , V_25 ) ;
if ( V_26 < 0 )
F_9 ( V_2 -> V_10 -> V_11 ,
L_16 ,
V_5 , V_26 ) ;
}
}
F_19 ( V_51 ) ;
F_5 ( V_2 -> V_16 , 1 ) ;
F_5 ( V_2 -> V_17 , 1 ) ;
return V_26 ;
}
static int V_31 ( struct V_1 * V_2 , void * V_27 , T_3 V_25 )
{
F_13 ( V_71 , V_2 , V_2 -> V_10 -> V_11 , T_1 , V_27 , V_25 ,
L_17 , V_5 , V_25 ) ;
F_5 ( V_2 -> V_18 , 0 ) ;
while ( V_25 -- ) {
T_1 V_3 , V_72 ;
V_72 = * ( T_1 * ) V_27 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 )
F_5 ( V_2 -> V_8 . V_15 [ V_3 ] , V_72 & ( 1 << V_3 ) ) ;
F_5 ( V_2 -> V_13 , 1 ) ;
F_6 ( 5 ) ;
F_5 ( V_2 -> V_13 , 0 ) ;
F_6 ( 1 ) ;
}
return 0 ;
}
