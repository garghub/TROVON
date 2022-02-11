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
F_4 ( V_2 -> V_9 -> V_10 , L_1 , V_5 ) ;
F_5 ( V_2 -> V_8 . V_7 , 0 ) ;
F_6 ( 20 ) ;
F_5 ( V_2 -> V_8 . V_7 , 1 ) ;
F_7 ( 120 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
F_4 ( V_2 -> V_9 -> V_10 ,
L_1 , V_5 ) ;
if ( V_2 -> V_11 < 0 ) {
F_9 ( V_2 -> V_9 -> V_10 ,
L_2 ) ;
return - V_12 ;
}
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
if ( V_2 -> V_8 . V_13 [ V_3 ] < 0 ) {
F_9 ( V_2 -> V_9 -> V_10 ,
L_3 ,
V_3 ) ;
return - V_12 ;
}
}
if ( V_2 -> V_14 < 0 ) {
F_9 ( V_2 -> V_9 -> V_10 ,
L_4 ) ;
return - V_12 ;
}
if ( V_2 -> V_15 < 0 ) {
F_9 ( V_2 -> V_9 -> V_10 ,
L_5 ) ;
return - V_12 ;
}
if ( V_2 -> V_16 < 0 ) {
F_9 ( V_2 -> V_9 -> V_10 ,
L_6 ) ;
return - V_12 ;
}
return 0 ;
}
static unsigned long
F_10 ( struct V_1 * V_2 , const struct V_17 * V_8 )
{
F_4 ( V_2 -> V_9 -> V_10 ,
L_7 , V_5 , V_8 -> V_18 ) ;
if ( strcasecmp ( V_8 -> V_18 , L_8 ) == 0 ) {
V_2 -> V_11 = V_8 -> V_8 ;
return V_19 ;
} else if ( strcasecmp ( V_8 -> V_18 , L_9 ) == 0 ) {
V_2 -> V_14 = V_8 -> V_8 ;
return V_20 ;
} else if ( strcasecmp ( V_8 -> V_18 , L_10 ) == 0 ) {
V_2 -> V_15 = V_8 -> V_8 ;
return V_20 ;
}
else if ( strcasecmp ( V_8 -> V_18 , L_11 ) == 0 ) {
V_2 -> V_16 = V_8 -> V_8 ;
return V_19 ;
}
return V_21 ;
}
static void F_11 ( struct V_1 * V_2 , int V_22 , ... )
{
T_2 args ;
int V_3 , V_23 ;
T_1 * V_24 = ( T_1 * ) V_2 -> V_24 ;
if ( F_12 ( V_2 -> V_25 & V_26 ) ) {
va_start ( args , V_22 ) ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ )
V_24 [ V_3 ] = ( T_1 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_13 ( V_26 , V_2 ,
V_2 -> V_9 -> V_10 , T_1 , V_24 , V_22 , L_12 , V_5 ) ;
}
va_start ( args , V_22 ) ;
* V_24 = ( T_1 ) va_arg (args, unsigned int) ;
if ( * V_24 > 1 ) {
va_end ( args ) ;
F_9 ( V_2 -> V_9 -> V_10 ,
L_13 , * V_24 ) ;
return;
}
if ( * V_24 ) {
F_5 ( V_2 -> V_14 , 1 ) ;
F_5 ( V_2 -> V_15 , 0 ) ;
} else {
F_5 ( V_2 -> V_14 , 0 ) ;
F_5 ( V_2 -> V_15 , 1 ) ;
}
F_5 ( V_2 -> V_27 , 0 ) ;
V_22 -- ;
if ( V_22 ) {
V_3 = V_22 ;
while ( V_3 -- )
* V_24 ++ = ( T_1 ) va_arg (args, unsigned int) ;
V_23 = V_2 -> V_6 . V_28 ( V_2 , V_2 -> V_24 , V_22 * ( sizeof( T_1 ) ) ) ;
if ( V_23 < 0 ) {
va_end ( args ) ;
F_9 ( V_2 -> V_9 -> V_10 ,
L_14 , V_23 ) ;
return;
}
}
va_end ( args ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_29 , int V_30 , int V_31 , int V_32 )
{
V_33 . V_29 = V_29 ;
V_33 . V_34 = V_30 / 8 ;
V_33 . V_31 = V_31 ;
V_33 . V_35 = V_32 / 8 ;
F_2 ( V_36 , V_2 ,
L_15 , V_5 ,
V_33 . V_29 , V_33 . V_34 , V_33 . V_31 , V_33 . V_35 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 * V_37 , signed short * V_38 ,
int V_29 , int V_31 , int V_39 )
{
int V_40 , V_3 ;
for ( V_40 = V_29 ; V_40 < V_31 ; ++ V_40 ) {
T_1 V_41 = 0 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( V_38 [ ( V_39 * 8 + V_3 ) * V_2 -> V_9 -> V_42 . V_43 + V_40 ] )
V_41 |= 1 << V_3 ;
#ifdef F_16
* V_37 ++ = V_41 ;
#else
* V_37 ++ = ~ V_41 ;
#endif
}
}
static int F_17 ( struct V_1 * V_2 , T_3 V_44 , T_3 V_22 )
{
T_4 * V_45 = ( T_4 * ) V_2 -> V_9 -> V_46 ;
T_1 * V_24 = V_2 -> V_47 . V_24 ;
int V_40 , V_39 ;
int V_23 = 0 ;
signed short * V_48 = F_18 ( V_2 -> V_9 -> V_42 . V_43 *
V_2 -> V_9 -> V_42 . V_49 * sizeof( signed short ) , V_50 ) ;
if ( ! V_48 )
return - V_51 ;
F_2 ( V_52 , V_2 , L_1 , V_5 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_9 -> V_42 . V_43 ; ++ V_40 )
for ( V_39 = 0 ; V_39 < V_2 -> V_9 -> V_42 . V_49 ; ++ V_39 ) {
T_4 V_53 = V_45 [ V_39 * V_2 -> V_9 -> V_42 . V_43 + V_40 ] ;
T_4 V_54 = V_53 & 0x1f ;
T_4 V_55 = ( V_53 & ( 0x3f << 5 ) ) >> 5 ;
T_4 V_56 = ( V_53 & ( 0x1f << ( 5 + 6 ) ) ) >> ( 5 + 6 ) ;
V_53 = ( 299 * V_56 + 587 * V_55 + 114 * V_54 ) / 200 ;
if ( V_53 > 255 )
V_53 = 255 ;
V_48 [ V_39 * V_2 -> V_9 -> V_42 . V_43 + V_40 ] =
( signed short ) V_57 [ V_53 ] ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_9 -> V_42 . V_43 ; ++ V_40 )
for ( V_39 = 0 ; V_39 < V_2 -> V_9 -> V_42 . V_49 ; ++ V_39 ) {
signed short V_53 =
V_48 [ V_39 * V_2 -> V_9 -> V_42 . V_43 + V_40 ] ;
signed short V_58 = V_53 - V_59 ;
signed short V_60 = V_53 - V_61 ;
signed short error ;
T_4 V_3 , V_62 ;
if ( abs ( V_58 ) >= abs ( V_60 ) ) {
error = V_60 ;
V_53 = 0xff ;
} else {
error = V_58 ;
V_53 = 0 ;
}
error /= 8 ;
for ( V_3 = 0 ; V_3 < V_63 ; ++ V_3 )
for ( V_62 = 0 ; V_62 < V_64 ; ++ V_62 ) {
signed short * V_65 ;
signed char V_66 ;
if ( V_40 + V_3 < 0 ||
V_40 + V_3 >= V_2 -> V_9 -> V_42 . V_43
|| V_39 + V_62 >= V_2 -> V_9 -> V_42 . V_49 )
continue;
V_65 = & V_48 [
( V_39 + V_62 ) * V_2 -> V_9 -> V_42 . V_43 +
V_40 + V_3 ] ;
V_66 = V_67 [ V_3 ] [ V_62 ] ;
if ( V_66 == - 1 )
* V_65 = V_53 ;
else {
signed short V_68 = * V_65 +
error * V_66 ;
if ( V_68 > V_61 )
V_68 = V_61 ;
if ( V_68 < V_59 )
V_68 = V_59 ;
* V_65 = V_68 ;
}
}
}
for ( V_39 = V_33 . V_34 ; V_39 <= V_33 . V_35 ; ++ V_39 ) {
if ( V_33 . V_29 < V_2 -> V_9 -> V_42 . V_43 / 2 ) {
F_15 ( V_2 , V_24 , V_48 ,
V_33 . V_29 , V_2 -> V_9 -> V_42 . V_43 / 2 , V_39 ) ;
V_22 = V_2 -> V_9 -> V_42 . V_43 / 2 - V_33 . V_29 ;
F_3 ( V_2 , 0x00 , ( 1 << 6 ) | ( T_1 ) V_33 . V_29 ) ;
F_3 ( V_2 , 0x00 , ( 0x17 << 3 ) | ( T_1 ) V_39 ) ;
F_5 ( V_2 -> V_27 , 1 ) ;
V_23 = V_2 -> V_6 . V_28 ( V_2 , V_24 , V_22 ) ;
if ( V_23 < 0 )
F_9 ( V_2 -> V_9 -> V_10 ,
L_16 ,
V_23 ) ;
}
if ( V_33 . V_31 >= V_2 -> V_9 -> V_42 . V_43 / 2 ) {
F_15 ( V_2 , V_24 ,
V_48 , V_2 -> V_9 -> V_42 . V_43 / 2 ,
V_33 . V_31 + 1 , V_39 ) ;
V_22 = V_33 . V_31 + 1 - V_2 -> V_9 -> V_42 . V_43 / 2 ;
F_3 ( V_2 , 0x01 , 1 << 6 ) ;
F_3 ( V_2 , 0x01 , ( 0x17 << 3 ) | ( T_1 ) V_39 ) ;
F_5 ( V_2 -> V_27 , 1 ) ;
V_2 -> V_6 . V_28 ( V_2 , V_24 , V_22 ) ;
if ( V_23 < 0 )
F_9 ( V_2 -> V_9 -> V_10 ,
L_16 ,
V_23 ) ;
}
}
F_19 ( V_48 ) ;
F_5 ( V_2 -> V_14 , 1 ) ;
F_5 ( V_2 -> V_15 , 1 ) ;
return V_23 ;
}
static int V_28 ( struct V_1 * V_2 , void * V_24 , T_3 V_22 )
{
F_13 ( V_69 , V_2 , V_2 -> V_9 -> V_10 , T_1 , V_24 , V_22 ,
L_17 , V_5 , V_22 ) ;
F_5 ( V_2 -> V_16 , 0 ) ;
while ( V_22 -- ) {
T_1 V_3 , V_70 ;
V_70 = * ( T_1 * ) V_24 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 )
F_5 ( V_2 -> V_8 . V_13 [ V_3 ] , V_70 & ( 1 << V_3 ) ) ;
F_5 ( V_2 -> V_11 , 1 ) ;
F_6 ( 5 ) ;
F_5 ( V_2 -> V_11 , 0 ) ;
F_6 ( 1 ) ;
}
return 0 ;
}
