static void F_1 ( struct V_1 * V_2 , int V_3 , ... )
{
T_1 args ;
int V_4 , V_5 ;
T_2 * V_6 = V_2 -> V_6 ;
va_start ( args , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
* V_6 ++ = ( T_2 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_2 ( V_7 , V_2 ,
V_2 -> V_8 -> V_9 , T_2 , V_2 -> V_6 , V_3 , L_1 , V_10 ) ;
V_5 = V_2 -> V_11 . V_12 ( V_2 , V_2 -> V_6 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_8 -> V_9 ,
L_2 , V_10 , V_5 ) ;
return;
}
}
static int F_4 ( struct V_1 * V_2 , T_3 V_13 , T_3 V_3 )
{
unsigned V_14 , V_15 ;
T_4 * V_16 = ( T_4 * ) ( V_2 -> V_8 -> V_17 + V_13 ) ;
T_4 * V_18 = V_2 -> V_19 . V_6 + 1 ;
T_4 * V_20 = V_2 -> V_19 . V_6 + 10 ;
int V_4 , V_21 ;
int V_5 = 0 ;
F_5 ( V_22 , V_2 , L_3 , V_10 ) ;
V_14 = V_13 / V_2 -> V_8 -> V_23 . V_24 ;
V_15 = V_14 + ( V_3 / V_2 -> V_8 -> V_23 . V_24 ) - 1 ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 0 ] = V_25 ;
V_18 [ 0 ] = 0 ;
V_18 [ 2 ] = F_6 ( V_2 -> V_8 -> V_26 . V_27 ) ;
V_18 [ 3 ] = F_6 ( 1 ) ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 9 ] = V_28 ;
for ( V_4 = V_14 ; V_4 <= V_15 ; V_4 ++ ) {
V_18 [ 1 ] = F_6 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_8 -> V_26 . V_27 ; V_21 ++ )
V_20 [ V_21 ] = F_6 ( * V_16 ++ ) ;
V_5 = V_2 -> V_11 . V_12 ( V_2 ,
V_2 -> V_19 . V_6 , 10 + V_2 -> V_8 -> V_23 . V_24 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 ( 300 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_13 , T_3 V_3 )
{
unsigned V_14 , V_15 ;
T_4 * V_16 = ( T_4 * ) ( V_2 -> V_8 -> V_17 + V_13 ) ;
T_4 * V_18 = V_2 -> V_19 . V_6 + 1 ;
T_2 * V_29 = V_2 -> V_19 . V_6 + 10 ;
int V_4 , V_21 ;
int V_5 = 0 ;
F_5 ( V_22 , V_2 , L_3 , V_10 ) ;
V_14 = V_13 / V_2 -> V_8 -> V_23 . V_24 ;
V_15 = V_14 + ( V_3 / V_2 -> V_8 -> V_23 . V_24 ) - 1 ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 0 ] = V_25 ;
V_18 [ 0 ] = 0 ;
V_18 [ 2 ] = F_6 ( V_2 -> V_8 -> V_26 . V_27 ) ;
V_18 [ 3 ] = F_6 ( 1 ) ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 9 ] = V_30 ;
for ( V_4 = V_14 ; V_4 <= V_15 ; V_4 ++ ) {
V_18 [ 1 ] = F_6 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_8 -> V_26 . V_27 ; V_21 ++ ) {
V_29 [ V_21 ] = F_9 ( * V_16 ) ;
V_16 ++ ;
}
V_5 = V_2 -> V_11 . V_12 ( V_2 ,
V_2 -> V_19 . V_6 , 10 + V_2 -> V_8 -> V_26 . V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 ( 700 ) ;
}
return 0 ;
}
static unsigned F_10 ( struct V_1 * V_2 )
{
T_2 V_31 [ 4 ] = { 0 , } ;
F_11 ( V_2 , V_32 ) ;
V_2 -> V_11 . V_33 ( V_2 , V_31 , 4 ) ;
if ( V_31 [ 1 ] != '.' )
return 0 ;
return ( V_31 [ 0 ] - '0' ) << 8 | ( V_31 [ 2 ] - '0' ) << 4 | ( V_31 [ 3 ] - '0' ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned V_34 ;
T_2 V_35 ;
F_5 ( V_36 , V_2 , L_3 , V_10 ) ;
V_35 = V_2 -> V_37 -> V_38 ;
V_2 -> V_37 -> V_38 |= V_39 ;
V_5 = V_2 -> V_37 -> V_40 -> V_41 ( V_2 -> V_37 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_4 ) ;
return V_5 ;
}
F_11 ( V_2 , 0x00 ) ;
F_13 ( 50 ) ;
V_2 -> V_11 . V_42 ( V_2 ) ;
F_13 ( 1000 ) ;
V_2 -> V_37 -> V_38 = V_35 ;
V_5 = V_2 -> V_37 -> V_40 -> V_41 ( V_2 -> V_37 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_5 ) ;
return V_5 ;
}
F_11 ( V_2 , 0x00 ) ;
V_34 = F_10 ( V_2 ) ;
F_5 ( V_36 , V_2 , L_6 ,
V_34 >> 8 , V_34 & 0xFF ) ;
if ( V_38 == 332 )
V_2 -> V_11 . F_4 = F_8 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_43 , int V_44 , int V_45 , int V_46 )
{
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_47 ;
F_5 ( V_36 , V_2 , L_3 , V_10 ) ;
switch ( V_2 -> V_8 -> V_26 . V_47 ) {
case 90 :
V_47 = 27 ;
break;
case 180 :
V_47 = 18 ;
break;
case 270 :
V_47 = 9 ;
break;
default:
V_47 = 0 ;
}
F_11 ( V_2 , V_48 , V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 . V_42 < 0 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_7 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_17 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_18 ( V_52 ) ;
int V_53 = V_52 -> V_54 . V_53 ;
F_5 ( V_55 , V_2 ,
L_8 ,
V_10 , V_52 -> V_54 . V_53 , V_52 -> V_54 . V_56 ,
V_52 -> V_54 . V_57 ) ;
if ( V_52 -> V_54 . V_56 != V_58 )
V_53 = 0 ;
if ( V_52 -> V_54 . V_57 != V_58 )
V_53 = 0 ;
F_11 ( V_2 , V_59 , V_53 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_60 V_61 = { 0 , } ;
struct V_62 * V_63 ;
F_5 ( V_55 , V_2 , L_3 , V_10 ) ;
V_63 = F_20 ( V_2 -> V_8 -> V_9 , sizeof( struct V_62 ) ,
V_64 ) ;
if ( ! V_63 ) {
F_3 ( V_2 -> V_8 -> V_9 ,
L_9 ,
V_10 ) ;
return;
}
V_63 -> V_65 = F_17 ;
V_61 . type = V_66 ;
V_61 . V_56 = V_67 ;
V_61 . V_68 = 100 ;
V_61 . V_53 = V_69 ;
V_52 = F_21 ( F_22 ( V_2 -> V_8 -> V_9 ) ,
V_2 -> V_8 -> V_9 , V_2 , V_63 , & V_61 ) ;
if ( F_23 ( V_52 ) ) {
F_3 ( V_2 -> V_8 -> V_9 ,
L_10 ,
F_24 ( V_52 ) ) ;
return;
}
V_2 -> V_8 -> V_70 = V_52 ;
if ( ! V_2 -> V_11 . V_71 )
V_2 -> V_11 . V_71 = V_72 ;
}
