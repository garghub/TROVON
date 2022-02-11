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
L_2 , V_5 ) ;
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
V_14 = V_13 / V_2 -> V_8 -> V_22 . V_23 ;
V_15 = V_14 + ( V_3 / V_2 -> V_8 -> V_22 . V_23 ) - 1 ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 0 ] = V_24 ;
V_18 [ 0 ] = 0 ;
V_18 [ 2 ] = F_5 ( V_2 -> V_8 -> V_25 . V_26 ) ;
V_18 [ 3 ] = F_5 ( 1 ) ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 9 ] = V_27 ;
for ( V_4 = V_14 ; V_4 <= V_15 ; V_4 ++ ) {
V_18 [ 1 ] = F_5 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_8 -> V_25 . V_26 ; V_21 ++ )
V_20 [ V_21 ] = F_5 ( * V_16 ++ ) ;
V_5 = V_2 -> V_11 . V_12 ( V_2 ,
V_2 -> V_19 . V_6 , 10 + V_2 -> V_8 -> V_22 . V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
F_6 ( 300 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 V_13 , T_3 V_3 )
{
unsigned V_14 , V_15 ;
T_4 * V_16 = ( T_4 * ) ( V_2 -> V_8 -> V_17 + V_13 ) ;
T_4 * V_18 = V_2 -> V_19 . V_6 + 1 ;
T_2 * V_28 = V_2 -> V_19 . V_6 + 10 ;
int V_4 , V_21 ;
int V_5 = 0 ;
V_14 = V_13 / V_2 -> V_8 -> V_22 . V_23 ;
V_15 = V_14 + ( V_3 / V_2 -> V_8 -> V_22 . V_23 ) - 1 ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 0 ] = V_24 ;
V_18 [ 0 ] = 0 ;
V_18 [ 2 ] = F_5 ( V_2 -> V_8 -> V_25 . V_26 ) ;
V_18 [ 3 ] = F_5 ( 1 ) ;
( ( T_2 * ) V_2 -> V_19 . V_6 ) [ 9 ] = V_29 ;
for ( V_4 = V_14 ; V_4 <= V_15 ; V_4 ++ ) {
V_18 [ 1 ] = F_5 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_8 -> V_25 . V_26 ; V_21 ++ ) {
V_28 [ V_21 ] = F_8 ( * V_16 ) ;
V_16 ++ ;
}
V_5 = V_2 -> V_11 . V_12 ( V_2 ,
V_2 -> V_19 . V_6 , 10 + V_2 -> V_8 -> V_25 . V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
F_6 ( 700 ) ;
}
return 0 ;
}
static unsigned F_9 ( struct V_1 * V_2 )
{
T_2 V_30 [ 4 ] = { 0 , } ;
F_10 ( V_2 , V_31 ) ;
V_2 -> V_11 . V_32 ( V_2 , V_30 , 4 ) ;
if ( V_30 [ 1 ] != '.' )
return 0 ;
return ( V_30 [ 0 ] - '0' ) << 8 | ( V_30 [ 2 ] - '0' ) << 4 | ( V_30 [ 3 ] - '0' ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned V_33 ;
T_2 V_34 ;
V_34 = V_2 -> V_35 -> V_36 ;
V_2 -> V_35 -> V_36 |= V_37 ;
V_5 = F_12 ( V_2 -> V_35 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_3 ) ;
return V_5 ;
}
F_10 ( V_2 , 0x00 ) ;
F_13 ( 50 ) ;
V_2 -> V_11 . V_38 ( V_2 ) ;
F_13 ( 1000 ) ;
V_2 -> V_35 -> V_36 = V_34 ;
V_5 = F_12 ( V_2 -> V_35 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_4 ) ;
return V_5 ;
}
F_10 ( V_2 , 0x00 ) ;
V_33 = F_9 ( V_2 ) ;
F_14 ( V_39 , V_2 , L_5 ,
V_33 >> 8 , V_33 & 0xFF ) ;
if ( V_36 == 332 )
V_2 -> V_11 . F_4 = F_7 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , int V_40 , int V_41 , int V_42 , int V_43 )
{
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_44 ;
switch ( V_2 -> V_8 -> V_25 . V_44 ) {
case 90 :
V_44 = 27 ;
break;
case 180 :
V_44 = 18 ;
break;
case 270 :
V_44 = 9 ;
break;
default:
V_44 = 0 ;
}
F_10 ( V_2 , V_45 , V_44 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 . V_38 < 0 ) {
F_3 ( V_2 -> V_8 -> V_9 , L_6 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_18 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
int V_50 = V_49 -> V_51 . V_50 ;
F_14 ( V_52 , V_2 ,
L_7 ,
V_10 , V_49 -> V_51 . V_50 , V_49 -> V_51 . V_53 ,
V_49 -> V_51 . V_54 ) ;
if ( V_49 -> V_51 . V_53 != V_55 )
V_50 = 0 ;
if ( V_49 -> V_51 . V_54 != V_55 )
V_50 = 0 ;
F_10 ( V_2 , V_56 , V_50 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_57 V_58 = { 0 , } ;
V_58 . type = V_59 ;
V_58 . V_53 = V_60 ;
V_58 . V_61 = 100 ;
V_58 . V_50 = V_62 ;
V_49 = F_21 ( F_22 ( V_2 -> V_8 -> V_9 ) ,
V_2 -> V_8 -> V_9 , V_2 , & V_63 , & V_58 ) ;
if ( F_23 ( V_49 ) ) {
F_3 ( V_2 -> V_8 -> V_9 ,
L_8 ,
F_24 ( V_49 ) ) ;
return;
}
V_2 -> V_8 -> V_64 = V_49 ;
if ( ! V_2 -> V_11 . V_65 )
V_2 -> V_11 . V_65 = V_66 ;
}
