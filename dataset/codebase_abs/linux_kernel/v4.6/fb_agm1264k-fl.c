static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 . V_5 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < 2 ; ++ V_3 ) {
F_2 ( V_2 , V_3 , 0x3f ) ;
F_2 ( V_2 , V_3 , 0x40 ) ;
F_2 ( V_2 , V_3 , 0xb0 ) ;
F_2 ( V_2 , V_3 , 0xc0 ) ;
}
return 0 ;
}
static void V_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 == - 1 )
return;
F_3 ( V_2 -> V_7 -> V_8 , L_1 , V_9 ) ;
F_4 ( V_2 -> V_6 . V_5 , 0 ) ;
F_5 ( 20 ) ;
F_4 ( V_2 -> V_6 . V_5 , 1 ) ;
F_6 ( 120 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
F_3 ( V_2 -> V_7 -> V_8 ,
L_1 , V_9 ) ;
if ( V_2 -> V_10 < 0 ) {
F_8 ( V_2 -> V_7 -> V_8 ,
L_2 ) ;
return - V_11 ;
}
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
if ( V_2 -> V_6 . V_12 [ V_3 ] < 0 ) {
F_8 ( V_2 -> V_7 -> V_8 ,
L_3 ,
V_3 ) ;
return - V_11 ;
}
}
if ( V_2 -> V_13 < 0 ) {
F_8 ( V_2 -> V_7 -> V_8 ,
L_4 ) ;
return - V_11 ;
}
if ( V_2 -> V_14 < 0 ) {
F_8 ( V_2 -> V_7 -> V_8 ,
L_5 ) ;
return - V_11 ;
}
if ( V_2 -> V_15 < 0 ) {
F_8 ( V_2 -> V_7 -> V_8 ,
L_6 ) ;
return - V_11 ;
}
return 0 ;
}
static unsigned long
F_9 ( struct V_1 * V_2 , const struct V_16 * V_6 )
{
F_3 ( V_2 -> V_7 -> V_8 ,
L_7 , V_9 , V_6 -> V_17 ) ;
if ( strcasecmp ( V_6 -> V_17 , L_8 ) == 0 ) {
V_2 -> V_10 = V_6 -> V_6 ;
return V_18 ;
} else if ( strcasecmp ( V_6 -> V_17 , L_9 ) == 0 ) {
V_2 -> V_13 = V_6 -> V_6 ;
return V_19 ;
} else if ( strcasecmp ( V_6 -> V_17 , L_10 ) == 0 ) {
V_2 -> V_14 = V_6 -> V_6 ;
return V_19 ;
}
else if ( strcasecmp ( V_6 -> V_17 , L_11 ) == 0 ) {
V_2 -> V_15 = V_6 -> V_6 ;
return V_18 ;
}
return V_20 ;
}
static void F_10 ( struct V_1 * V_2 , int V_21 , ... )
{
T_2 args ;
int V_3 , V_22 ;
T_1 * V_23 = V_2 -> V_23 ;
if ( F_11 ( V_2 -> V_24 & V_25 ) ) {
va_start ( args , V_21 ) ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ )
V_23 [ V_3 ] = ( T_1 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_12 ( V_25 , V_2 ,
V_2 -> V_7 -> V_8 , T_1 , V_23 , V_21 , L_12 , V_9 ) ;
}
va_start ( args , V_21 ) ;
* V_23 = ( T_1 ) va_arg (args, unsigned int) ;
if ( * V_23 > 1 ) {
va_end ( args ) ;
F_8 ( V_2 -> V_7 -> V_8 ,
L_13 , * V_23 ) ;
return;
}
if ( * V_23 ) {
F_4 ( V_2 -> V_13 , 1 ) ;
F_4 ( V_2 -> V_14 , 0 ) ;
} else {
F_4 ( V_2 -> V_13 , 0 ) ;
F_4 ( V_2 -> V_14 , 1 ) ;
}
F_4 ( V_2 -> V_26 , 0 ) ;
V_21 -- ;
if ( V_21 ) {
V_3 = V_21 ;
while ( V_3 -- )
* V_23 ++ = ( T_1 ) va_arg (args, unsigned int) ;
V_22 = V_2 -> V_4 . V_27 ( V_2 , V_2 -> V_23 , V_21 * ( sizeof( T_1 ) ) ) ;
if ( V_22 < 0 ) {
va_end ( args ) ;
F_8 ( V_2 -> V_7 -> V_8 ,
L_14 , V_22 ) ;
return;
}
}
va_end ( args ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_28 , int V_29 , int V_30 , int V_31 )
{
V_32 . V_28 = V_28 ;
V_32 . V_33 = V_29 / 8 ;
V_32 . V_30 = V_30 ;
V_32 . V_34 = V_31 / 8 ;
}
static void
F_14 ( struct V_1 * V_2 , T_1 * V_35 , signed short * V_36 ,
int V_28 , int V_30 , int V_37 )
{
int V_38 , V_3 ;
for ( V_38 = V_28 ; V_38 < V_30 ; ++ V_38 ) {
T_1 V_39 = 0 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( V_36 [ ( V_37 * 8 + V_3 ) * V_2 -> V_7 -> V_40 . V_41 + V_38 ] )
V_39 |= 1 << V_3 ;
#ifdef F_15
* V_35 ++ = V_39 ;
#else
* V_35 ++ = ~ V_39 ;
#endif
}
}
static int F_16 ( struct V_1 * V_2 , T_3 V_42 , T_3 V_21 )
{
T_4 * V_43 = ( T_4 * ) V_2 -> V_7 -> V_44 ;
T_1 * V_23 = V_2 -> V_45 . V_23 ;
int V_38 , V_37 ;
int V_22 = 0 ;
signed short * V_46 = F_17 ( V_2 -> V_7 -> V_40 . V_41 *
V_2 -> V_7 -> V_40 . V_47 , sizeof( signed short ) , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_7 -> V_40 . V_41 ; ++ V_38 )
for ( V_37 = 0 ; V_37 < V_2 -> V_7 -> V_40 . V_47 ; ++ V_37 ) {
T_4 V_50 = V_43 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] ;
T_4 V_51 = V_50 & 0x1f ;
T_4 V_52 = ( V_50 & ( 0x3f << 5 ) ) >> 5 ;
T_4 V_53 = ( V_50 & ( 0x1f << ( 5 + 6 ) ) ) >> ( 5 + 6 ) ;
V_50 = ( 299 * V_53 + 587 * V_52 + 114 * V_51 ) / 200 ;
if ( V_50 > 255 )
V_50 = 255 ;
V_46 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] =
( signed short ) V_54 [ V_50 ] ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_7 -> V_40 . V_41 ; ++ V_38 )
for ( V_37 = 0 ; V_37 < V_2 -> V_7 -> V_40 . V_47 ; ++ V_37 ) {
signed short V_50 =
V_46 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] ;
signed short V_55 = V_50 - V_56 ;
signed short V_57 = V_50 - V_58 ;
signed short error ;
T_4 V_3 , V_59 ;
if ( abs ( V_55 ) >= abs ( V_57 ) ) {
error = V_57 ;
V_50 = 0xff ;
} else {
error = V_55 ;
V_50 = 0 ;
}
error /= 8 ;
for ( V_3 = 0 ; V_3 < V_60 ; ++ V_3 )
for ( V_59 = 0 ; V_59 < V_61 ; ++ V_59 ) {
signed short * V_62 ;
signed char V_63 ;
if ( V_38 + V_3 < 0 ||
V_38 + V_3 >= V_2 -> V_7 -> V_40 . V_41
|| V_37 + V_59 >= V_2 -> V_7 -> V_40 . V_47 )
continue;
V_62 = & V_46 [
( V_37 + V_59 ) * V_2 -> V_7 -> V_40 . V_41 +
V_38 + V_3 ] ;
V_63 = V_64 [ V_3 ] [ V_59 ] ;
if ( V_63 == - 1 )
* V_62 = V_50 ;
else {
signed short V_65 = * V_62 +
error * V_63 ;
if ( V_65 > V_58 )
V_65 = V_58 ;
if ( V_65 < V_56 )
V_65 = V_56 ;
* V_62 = V_65 ;
}
}
}
for ( V_37 = V_32 . V_33 ; V_37 <= V_32 . V_34 ; ++ V_37 ) {
if ( V_32 . V_28 < V_2 -> V_7 -> V_40 . V_41 / 2 ) {
F_14 ( V_2 , V_23 , V_46 ,
V_32 . V_28 , V_2 -> V_7 -> V_40 . V_41 / 2 , V_37 ) ;
V_21 = V_2 -> V_7 -> V_40 . V_41 / 2 - V_32 . V_28 ;
F_2 ( V_2 , 0x00 , ( 1 << 6 ) | ( T_1 ) V_32 . V_28 ) ;
F_2 ( V_2 , 0x00 , ( 0x17 << 3 ) | ( T_1 ) V_37 ) ;
F_4 ( V_2 -> V_26 , 1 ) ;
V_22 = V_2 -> V_4 . V_27 ( V_2 , V_23 , V_21 ) ;
if ( V_22 < 0 )
F_8 ( V_2 -> V_7 -> V_8 ,
L_15 ,
V_22 ) ;
}
if ( V_32 . V_30 >= V_2 -> V_7 -> V_40 . V_41 / 2 ) {
F_14 ( V_2 , V_23 ,
V_46 , V_2 -> V_7 -> V_40 . V_41 / 2 ,
V_32 . V_30 + 1 , V_37 ) ;
V_21 = V_32 . V_30 + 1 - V_2 -> V_7 -> V_40 . V_41 / 2 ;
F_2 ( V_2 , 0x01 , 1 << 6 ) ;
F_2 ( V_2 , 0x01 , ( 0x17 << 3 ) | ( T_1 ) V_37 ) ;
F_4 ( V_2 -> V_26 , 1 ) ;
V_2 -> V_4 . V_27 ( V_2 , V_23 , V_21 ) ;
if ( V_22 < 0 )
F_8 ( V_2 -> V_7 -> V_8 ,
L_15 ,
V_22 ) ;
}
}
F_18 ( V_46 ) ;
F_4 ( V_2 -> V_13 , 1 ) ;
F_4 ( V_2 -> V_14 , 1 ) ;
return V_22 ;
}
static int V_27 ( struct V_1 * V_2 , void * V_23 , T_3 V_21 )
{
F_12 ( V_66 , V_2 , V_2 -> V_7 -> V_8 , T_1 , V_23 , V_21 ,
L_16 , V_9 , V_21 ) ;
F_4 ( V_2 -> V_15 , 0 ) ;
while ( V_21 -- ) {
T_1 V_3 , V_67 ;
V_67 = * ( T_1 * ) V_23 ++ ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 )
F_4 ( V_2 -> V_6 . V_12 [ V_3 ] , V_67 & ( 1 << V_3 ) ) ;
F_4 ( V_2 -> V_10 , 1 ) ;
F_5 ( 5 ) ;
F_4 ( V_2 -> V_10 , 0 ) ;
F_5 ( 1 ) ;
}
return 0 ;
}
