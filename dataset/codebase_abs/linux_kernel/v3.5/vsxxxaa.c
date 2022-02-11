static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 >= V_2 -> V_4 ) {
V_2 -> V_4 = 0 ;
} else {
memmove ( V_2 -> V_5 , V_2 -> V_5 + V_3 - 1 , V_6 - V_3 ) ;
V_2 -> V_4 -= V_3 ;
}
}
static void F_2 ( struct V_1 * V_2 , unsigned char V_7 )
{
if ( V_2 -> V_4 == V_6 ) {
F_3 ( V_8 L_1 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_1 ( V_2 , 1 ) ;
}
F_4 ( V_11 L_2 , V_7 ) ;
V_2 -> V_5 [ V_2 -> V_4 ++ ] = V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case 0x02 :
F_6 ( V_2 -> V_9 , L_3 ,
sizeof( V_2 -> V_9 ) ) ;
break;
case 0x04 :
F_6 ( V_2 -> V_9 , L_4 ,
sizeof( V_2 -> V_9 ) ) ;
break;
default:
snprintf ( V_2 -> V_9 , sizeof( V_2 -> V_9 ) ,
L_5 ,
V_2 -> type ) ;
break;
}
F_3 ( V_11
L_6 ,
V_2 -> V_9 , V_2 -> V_12 , V_2 -> V_13 , V_2 -> V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_14 )
{
int V_15 ;
if ( ! F_8 ( V_2 -> V_5 [ 0 ] ) ) {
F_4 ( L_7 , V_14 , V_2 -> V_5 [ 0 ] ) ;
return 1 ;
}
for ( V_15 = 1 ; V_15 < V_14 ; V_15 ++ ) {
if ( F_8 ( V_2 -> V_5 [ V_15 ] ) ) {
F_3 ( V_8
L_8 ,
V_15 - 1 ) ;
F_4 ( V_11 L_9 ,
V_14 , V_15 , V_2 -> V_5 [ V_15 ] ) ;
return V_15 - 1 ;
}
}
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
unsigned char type , T_1 V_16 )
{
return V_2 -> V_4 >= V_16 && F_10 ( V_2 -> V_5 [ 0 ] , type ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned char * V_5 = V_2 -> V_5 ;
int V_19 , V_20 , V_21 ;
int V_22 , V_23 ;
V_22 = V_5 [ 1 ] & 0x7f ;
V_22 *= ( ( V_5 [ 0 ] >> 4 ) & 0x01 ) ? 1 : - 1 ;
V_23 = V_5 [ 2 ] & 0x7f ;
V_23 *= ( ( V_5 [ 0 ] >> 3 ) & 0x01 ) ? - 1 : 1 ;
V_19 = V_5 [ 0 ] & 0x04 ;
V_20 = V_5 [ 0 ] & 0x02 ;
V_21 = V_5 [ 0 ] & 0x01 ;
F_1 ( V_2 , 3 ) ;
F_4 ( V_11 L_10 ,
V_2 -> V_9 , V_2 -> V_10 , V_22 , V_23 ,
V_19 ? L_11 : L_12 , V_20 ? L_13 : L_14 , V_21 ? L_15 : L_16 ) ;
F_12 ( V_18 , V_24 , V_19 ) ;
F_12 ( V_18 , V_25 , V_20 ) ;
F_12 ( V_18 , V_26 , V_21 ) ;
F_12 ( V_18 , V_27 , 0 ) ;
F_13 ( V_18 , V_28 , V_22 ) ;
F_13 ( V_18 , V_29 , V_23 ) ;
F_14 ( V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned char * V_5 = V_2 -> V_5 ;
int V_19 , V_20 , V_21 , V_30 ;
int V_31 , V_32 ;
V_31 = ( ( V_5 [ 2 ] & 0x3f ) << 6 ) | ( V_5 [ 1 ] & 0x3f ) ;
V_32 = ( ( V_5 [ 4 ] & 0x3f ) << 6 ) | ( V_5 [ 3 ] & 0x3f ) ;
V_32 = 1023 - V_32 ;
V_19 = V_5 [ 0 ] & 0x02 ;
V_20 = V_5 [ 0 ] & 0x04 ;
V_21 = V_5 [ 0 ] & 0x08 ;
V_30 = V_5 [ 0 ] & 0x10 ;
F_1 ( V_2 , 5 ) ;
F_4 ( V_11 L_17 ,
V_2 -> V_9 , V_2 -> V_10 , V_31 , V_32 ,
V_19 ? L_11 : L_12 , V_20 ? L_13 : L_14 ,
V_21 ? L_15 : L_16 , V_30 ? L_18 : L_19 ) ;
F_12 ( V_18 , V_24 , V_19 ) ;
F_12 ( V_18 , V_25 , V_20 ) ;
F_12 ( V_18 , V_26 , V_21 ) ;
F_12 ( V_18 , V_27 , V_30 ) ;
F_16 ( V_18 , V_33 , V_31 ) ;
F_16 ( V_18 , V_34 , V_32 ) ;
F_14 ( V_18 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned char * V_5 = V_2 -> V_5 ;
int V_19 , V_20 , V_21 ;
unsigned char error ;
V_2 -> V_12 = V_5 [ 0 ] & 0x0f ;
V_2 -> V_13 = ( V_5 [ 1 ] >> 4 ) & 0x07 ;
V_2 -> type = V_5 [ 1 ] & 0x0f ;
error = V_5 [ 2 ] & 0x7f ;
V_19 = V_5 [ 0 ] & 0x04 ;
V_20 = V_5 [ 0 ] & 0x02 ;
V_21 = V_5 [ 0 ] & 0x01 ;
F_1 ( V_2 , 4 ) ;
F_5 ( V_2 ) ;
if ( error <= 0x1f ) {
F_12 ( V_18 , V_24 , V_19 ) ;
F_12 ( V_18 , V_25 , V_20 ) ;
F_12 ( V_18 , V_26 , V_21 ) ;
F_12 ( V_18 , V_27 , 0 ) ;
F_14 ( V_18 ) ;
if ( error != 0 )
F_3 ( V_11 L_20 ,
V_2 -> V_9 , V_2 -> V_10 , error ) ;
}
F_3 ( V_35
L_21
L_22 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_18 ( V_2 -> V_36 , 'S' ) ;
F_19 ( 50 ) ;
F_18 ( V_2 -> V_36 , 'R' ) ;
F_19 ( 50 ) ;
F_18 ( V_2 -> V_36 , 'L' ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned char * V_5 = V_2 -> V_5 ;
int V_37 ;
do {
while ( V_2 -> V_4 > 0 && ! F_8 ( V_5 [ 0 ] ) ) {
F_3 ( V_8 L_23
L_24 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_1 ( V_2 , 1 ) ;
}
if ( F_9 ( V_2 , V_38 , 3 ) ) {
V_37 = F_7 ( V_2 , 3 ) ;
if ( ! V_37 )
F_11 ( V_2 ) ;
} else if ( F_9 ( V_2 ,
V_39 , 5 ) ) {
V_37 = F_7 ( V_2 , 5 ) ;
if ( ! V_37 )
F_15 ( V_2 ) ;
} else if ( F_9 ( V_2 ,
V_40 , 4 ) ) {
V_37 = F_7 ( V_2 , 4 ) ;
if ( ! V_37 )
F_17 ( V_2 ) ;
} else {
break;
}
if ( V_37 > 0 ) {
F_3 ( V_8 L_25 ,
V_37 ) ;
F_1 ( V_2 , V_37 ) ;
}
} while ( 1 );
}
static T_2 F_21 ( struct V_36 * V_36 ,
unsigned char V_41 , unsigned int V_42 )
{
struct V_1 * V_2 = F_22 ( V_36 ) ;
F_2 ( V_2 , V_41 ) ;
F_20 ( V_2 ) ;
return V_43 ;
}
static void F_23 ( struct V_36 * V_36 )
{
struct V_1 * V_2 = F_22 ( V_36 ) ;
F_24 ( V_36 ) ;
F_25 ( V_36 , NULL ) ;
F_26 ( V_2 -> V_18 ) ;
F_27 ( V_2 ) ;
}
static int F_28 ( struct V_36 * V_36 , struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_17 * V_17 ;
int V_46 = - V_47 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_48 ) ;
V_17 = F_30 () ;
if ( ! V_2 || ! V_17 )
goto V_49;
V_2 -> V_18 = V_17 ;
V_2 -> V_36 = V_36 ;
F_31 ( V_2 -> V_9 , L_26 ,
sizeof( V_2 -> V_9 ) ) ;
snprintf ( V_2 -> V_10 , sizeof( V_2 -> V_10 ) , L_27 , V_36 -> V_10 ) ;
V_17 -> V_9 = V_2 -> V_9 ;
V_17 -> V_10 = V_2 -> V_10 ;
V_17 -> V_50 . V_51 = V_52 ;
V_17 -> V_18 . V_53 = & V_36 -> V_18 ;
F_32 ( V_54 , V_17 -> V_55 ) ;
F_32 ( V_56 , V_17 -> V_55 ) ;
F_32 ( V_57 , V_17 -> V_55 ) ;
F_32 ( V_24 , V_17 -> V_58 ) ;
F_32 ( V_25 , V_17 -> V_58 ) ;
F_32 ( V_26 , V_17 -> V_58 ) ;
F_32 ( V_27 , V_17 -> V_58 ) ;
F_32 ( V_28 , V_17 -> V_59 ) ;
F_32 ( V_29 , V_17 -> V_59 ) ;
F_33 ( V_17 , V_33 , 0 , 1023 , 0 , 0 ) ;
F_33 ( V_17 , V_34 , 0 , 1023 , 0 , 0 ) ;
F_25 ( V_36 , V_2 ) ;
V_46 = F_34 ( V_36 , V_45 ) ;
if ( V_46 )
goto V_60;
F_18 ( V_36 , 'T' ) ;
V_46 = F_35 ( V_17 ) ;
if ( V_46 )
goto V_61;
return 0 ;
V_61: F_24 ( V_36 ) ;
V_60: F_25 ( V_36 , NULL ) ;
V_49: F_36 ( V_17 ) ;
F_27 ( V_2 ) ;
return V_46 ;
}
