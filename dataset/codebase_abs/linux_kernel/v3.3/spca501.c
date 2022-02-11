static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 ,
F_3 ( V_2 , 0 ) ,
V_3 ,
V_7 | V_8 ,
V_5 , V_4 , NULL , 0 , 500 ) ;
F_4 ( V_9 , L_1 ,
V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
F_5 ( L_2 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_10 * V_10 ,
const T_1 V_11 [] [ 3 ] )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_6 , V_12 = 0 ;
while ( V_11 [ V_12 ] [ 0 ] != 0 || V_11 [ V_12 ] [ 1 ] != 0 || V_11 [ V_12 ] [ 2 ] != 0 ) {
V_6 = F_1 ( V_2 , V_11 [ V_12 ] [ 0 ] , V_11 [ V_12 ] [ 2 ] , V_11 [ V_12 ] [ 1 ] ) ;
if ( V_6 < 0 ) {
F_4 ( V_13 ,
L_3 ,
V_11 [ V_12 ] [ 0 ] , V_11 [ V_12 ] [ 1 ] , V_11 [ V_12 ] [ 2 ] ) ;
return V_6 ;
}
V_12 ++ ;
}
return 0 ;
}
static void F_7 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
F_1 ( V_10 -> V_2 , V_15 , 0x12 , V_14 -> V_16 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
F_1 ( V_10 -> V_2 , 0x00 , 0x00 ,
( V_14 -> V_17 >> 8 ) & 0xff ) ;
F_1 ( V_10 -> V_2 , 0x00 , 0x01 ,
V_14 -> V_17 & 0xff ) ;
}
static void F_9 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
F_1 ( V_10 -> V_2 , V_15 , 0x0c , V_14 -> V_18 ) ;
}
static void F_10 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
F_1 ( V_10 -> V_2 , V_15 , 0x11 , V_14 -> V_19 ) ;
}
static void F_11 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
F_1 ( V_10 -> V_2 , V_15 , 0x13 , V_14 -> V_20 ) ;
}
static int F_12 ( struct V_10 * V_10 ,
const struct V_21 * V_22 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
struct V_23 * V_23 ;
V_23 = & V_10 -> V_23 ;
V_23 -> V_24 = V_25 ;
V_23 -> V_26 = F_13 ( V_25 ) ;
V_14 -> V_27 = V_22 -> V_28 ;
V_14 -> V_16 = V_29 [ V_30 ] . V_31 . V_32 ;
V_14 -> V_17 = V_29 [ V_33 ] . V_31 . V_32 ;
V_14 -> V_18 = V_29 [ V_34 ] . V_31 . V_32 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
switch ( V_14 -> V_27 ) {
case V_35 :
case V_36 :
if ( F_6 ( V_10 , V_37 ) )
goto error;
break;
case V_38 :
if ( F_6 ( V_10 , V_39 ) )
goto error;
break;
default:
if ( F_6 ( V_10 , V_40 ) )
goto error;
break;
}
F_4 ( V_41 , L_4 ) ;
return 0 ;
error:
return - V_42 ;
}
static int F_15 ( struct V_10 * V_10 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_43 ;
switch ( V_14 -> V_27 ) {
case V_44 :
F_6 ( V_10 , V_45 ) ;
break;
case V_35 :
case V_36 :
F_6 ( V_10 , V_46 ) ;
break;
case V_38 :
F_6 ( V_10 , V_47 ) ;
break;
default:
F_6 ( V_10 , V_48 ) ;
}
V_43 = V_10 -> V_23 . V_24 [ ( int ) V_10 -> V_49 ] . V_50 ;
F_1 ( V_2 , V_51 , 0x6 , 0x94 ) ;
switch ( V_43 ) {
case 0 :
F_1 ( V_2 , V_51 , 0x07 , 0x004a ) ;
break;
case 1 :
F_1 ( V_2 , V_51 , 0x07 , 0x104a ) ;
break;
default:
F_1 ( V_2 , V_51 , 0x07 , 0x204a ) ;
break;
}
F_1 ( V_2 , V_52 , 0x01 , 0x02 ) ;
F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static void F_16 ( struct V_10 * V_10 )
{
F_1 ( V_10 -> V_2 , V_52 , 0x01 , 0x00 ) ;
}
static void F_17 ( struct V_10 * V_10 )
{
if ( ! V_10 -> V_53 )
return;
F_1 ( V_10 -> V_2 , V_52 , 0x05 , 0x00 ) ;
}
static void F_18 ( struct V_10 * V_10 ,
T_2 * V_11 ,
int V_54 )
{
switch ( V_11 [ 0 ] ) {
case 0 :
F_19 ( V_10 , V_55 , NULL , 0 ) ;
V_11 += V_56 ;
V_54 -= V_56 ;
F_19 ( V_10 , V_57 , V_11 , V_54 ) ;
return;
case 0xff :
return;
}
V_11 ++ ;
V_54 -- ;
F_19 ( V_10 , V_58 , V_11 , V_54 ) ;
}
static int F_20 ( struct V_10 * V_10 , T_3 V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
V_14 -> V_16 = V_59 ;
if ( V_10 -> V_60 )
F_7 ( V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_10 , T_3 * V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
* V_59 = V_14 -> V_16 ;
return 0 ;
}
static int F_22 ( struct V_10 * V_10 , T_3 V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
V_14 -> V_17 = V_59 ;
if ( V_10 -> V_60 )
F_8 ( V_10 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_10 , T_3 * V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
* V_59 = V_14 -> V_17 ;
return 0 ;
}
static int F_24 ( struct V_10 * V_10 , T_3 V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
V_14 -> V_18 = V_59 ;
if ( V_10 -> V_60 )
F_9 ( V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_10 , T_3 * V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
* V_59 = V_14 -> V_18 ;
return 0 ;
}
static int F_26 ( struct V_10 * V_10 , T_3 V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
V_14 -> V_19 = V_59 ;
if ( V_10 -> V_60 )
F_10 ( V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_10 , T_3 * V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
* V_59 = V_14 -> V_19 ;
return 0 ;
}
static int F_28 ( struct V_10 * V_10 , T_3 V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
V_14 -> V_20 = V_59 ;
if ( V_10 -> V_60 )
F_11 ( V_10 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_10 , T_3 * V_59 )
{
struct V_14 * V_14 = (struct V_14 * ) V_10 ;
* V_59 = V_14 -> V_20 ;
return 0 ;
}
static int F_30 ( struct V_61 * V_62 ,
const struct V_21 * V_22 )
{
return F_31 ( V_62 , V_22 , & V_63 , sizeof( struct V_14 ) ,
V_64 ) ;
}
