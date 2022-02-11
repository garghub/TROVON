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
static void F_16 ( T_3 V_41 , T_3 V_42 , int V_38 ,
int V_37 , signed short * V_43 ,
signed short V_44 , signed short error )
{
T_4 V_3 , V_45 ;
for ( V_3 = 0 ; V_3 < V_46 ; ++ V_3 )
for ( V_45 = 0 ; V_45 < V_47 ; ++ V_45 ) {
signed short * V_48 ;
signed char V_49 ;
if ( V_38 + V_3 < 0 || V_38 + V_3 >= V_41 || V_37 + V_45 >= V_42 )
continue;
V_48 = & V_43 [ ( V_37 + V_45 ) * V_41 + V_38 + V_3 ] ;
V_49 = V_50 [ V_3 ] [ V_45 ] ;
if ( - 1 == V_49 )
* V_48 = V_44 ;
else {
signed short V_51 = * V_48 + error * V_49 ;
if ( V_51 > V_52 )
V_51 = V_52 ;
if ( V_51 < V_53 )
V_51 = V_53 ;
* V_48 = V_51 ;
}
}
}
static int F_17 ( struct V_1 * V_2 , T_5 V_54 , T_5 V_21 )
{
T_4 * V_55 = ( T_4 * ) V_2 -> V_7 -> V_56 ;
T_1 * V_23 = V_2 -> V_57 . V_23 ;
int V_38 , V_37 ;
int V_22 = 0 ;
signed short * V_43 = F_18 ( V_2 -> V_7 -> V_40 . V_41 *
V_2 -> V_7 -> V_40 . V_42 , sizeof( signed short ) , V_58 ) ;
if ( ! V_43 )
return - V_59 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_7 -> V_40 . V_41 ; ++ V_38 )
for ( V_37 = 0 ; V_37 < V_2 -> V_7 -> V_40 . V_42 ; ++ V_37 ) {
T_4 V_44 = V_55 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] ;
T_4 V_60 = V_44 & 0x1f ;
T_4 V_61 = ( V_44 & ( 0x3f << 5 ) ) >> 5 ;
T_4 V_62 = ( V_44 & ( 0x1f << ( 5 + 6 ) ) ) >> ( 5 + 6 ) ;
V_44 = ( 299 * V_62 + 587 * V_61 + 114 * V_60 ) / 200 ;
if ( V_44 > 255 )
V_44 = 255 ;
V_43 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] =
( signed short ) V_63 [ V_44 ] ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_7 -> V_40 . V_41 ; ++ V_38 )
for ( V_37 = 0 ; V_37 < V_2 -> V_7 -> V_40 . V_42 ; ++ V_37 ) {
signed short V_44 =
V_43 [ V_37 * V_2 -> V_7 -> V_40 . V_41 + V_38 ] ;
signed short V_64 = V_44 - V_53 ;
signed short V_65 = V_44 - V_52 ;
signed short error ;
if ( abs ( V_64 ) >= abs ( V_65 ) ) {
error = V_65 ;
V_44 = 0xff ;
} else {
error = V_64 ;
V_44 = 0 ;
}
error /= 8 ;
F_16 ( V_2 -> V_7 -> V_40 . V_41 ,
V_2 -> V_7 -> V_40 . V_42 ,
V_38 , V_37 , V_43 ,
V_44 , error ) ;
}
for ( V_37 = V_32 . V_33 ; V_37 <= V_32 . V_34 ; ++ V_37 ) {
if ( V_32 . V_28 < V_2 -> V_7 -> V_40 . V_41 / 2 ) {
F_14 ( V_2 , V_23 , V_43 ,
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
V_43 , V_2 -> V_7 -> V_40 . V_41 / 2 ,
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
F_19 ( V_43 ) ;
F_4 ( V_2 -> V_13 , 1 ) ;
F_4 ( V_2 -> V_14 , 1 ) ;
return V_22 ;
}
static int V_27 ( struct V_1 * V_2 , void * V_23 , T_5 V_21 )
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
