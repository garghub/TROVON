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
static void F_7 ( struct V_10 * V_10 , T_2 V_14 )
{
F_1 ( V_10 -> V_2 , V_15 , 0x12 , V_14 ) ;
}
static void F_8 ( struct V_10 * V_10 , T_2 V_14 )
{
F_1 ( V_10 -> V_2 , 0x00 , 0x00 ,
( V_14 >> 8 ) & 0xff ) ;
F_1 ( V_10 -> V_2 , 0x00 , 0x01 ,
V_14 & 0xff ) ;
}
static void F_9 ( struct V_10 * V_10 , T_2 V_14 )
{
F_1 ( V_10 -> V_2 , V_15 , 0x0c , V_14 ) ;
}
static void F_10 ( struct V_10 * V_10 , T_2 V_14 )
{
F_1 ( V_10 -> V_2 , V_15 , 0x11 , V_14 ) ;
}
static void F_11 ( struct V_10 * V_10 , T_2 V_14 )
{
F_1 ( V_10 -> V_2 , V_15 , 0x13 , V_14 ) ;
}
static int F_12 ( struct V_10 * V_10 ,
const struct V_16 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_10 ;
struct V_19 * V_19 ;
V_19 = & V_10 -> V_19 ;
V_19 -> V_20 = V_21 ;
V_19 -> V_22 = F_13 ( V_21 ) ;
V_18 -> V_23 = V_17 -> V_24 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_10 )
{
struct V_18 * V_18 = (struct V_18 * ) V_10 ;
switch ( V_18 -> V_23 ) {
case V_25 :
case V_26 :
if ( F_6 ( V_10 , V_27 ) )
goto error;
break;
case V_28 :
if ( F_6 ( V_10 , V_29 ) )
goto error;
break;
default:
if ( F_6 ( V_10 , V_30 ) )
goto error;
break;
}
F_4 ( V_31 , L_4 ) ;
return 0 ;
error:
return - V_32 ;
}
static int F_15 ( struct V_10 * V_10 )
{
struct V_18 * V_18 = (struct V_18 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_33 ;
switch ( V_18 -> V_23 ) {
case V_34 :
F_6 ( V_10 , V_35 ) ;
break;
case V_25 :
case V_26 :
F_6 ( V_10 , V_36 ) ;
break;
case V_28 :
F_6 ( V_10 , V_37 ) ;
break;
default:
F_6 ( V_10 , V_38 ) ;
}
V_33 = V_10 -> V_19 . V_20 [ ( int ) V_10 -> V_39 ] . V_40 ;
F_1 ( V_2 , V_41 , 0x6 , 0x94 ) ;
switch ( V_33 ) {
case 0 :
F_1 ( V_2 , V_41 , 0x07 , 0x004a ) ;
break;
case 1 :
F_1 ( V_2 , V_41 , 0x07 , 0x104a ) ;
break;
default:
F_1 ( V_2 , V_41 , 0x07 , 0x204a ) ;
break;
}
F_1 ( V_2 , V_42 , 0x01 , 0x02 ) ;
return 0 ;
}
static void F_16 ( struct V_10 * V_10 )
{
F_1 ( V_10 -> V_2 , V_42 , 0x01 , 0x00 ) ;
}
static void F_17 ( struct V_10 * V_10 )
{
if ( ! V_10 -> V_43 )
return;
F_1 ( V_10 -> V_2 , V_42 , 0x05 , 0x00 ) ;
}
static void F_18 ( struct V_10 * V_10 ,
T_3 * V_11 ,
int V_44 )
{
switch ( V_11 [ 0 ] ) {
case 0 :
F_19 ( V_10 , V_45 , NULL , 0 ) ;
V_11 += V_46 ;
V_44 -= V_46 ;
F_19 ( V_10 , V_47 , V_11 , V_44 ) ;
return;
case 0xff :
return;
}
V_11 ++ ;
V_44 -- ;
F_19 ( V_10 , V_48 , V_11 , V_44 ) ;
}
static int F_20 ( struct V_49 * V_50 )
{
struct V_10 * V_10 =
F_21 ( V_50 -> V_51 , struct V_10 , V_52 ) ;
V_10 -> V_53 = 0 ;
if ( ! V_10 -> V_54 )
return 0 ;
switch ( V_50 -> V_17 ) {
case V_55 :
F_7 ( V_10 , V_50 -> V_14 ) ;
break;
case V_56 :
F_8 ( V_10 , V_50 -> V_14 ) ;
break;
case V_57 :
F_9 ( V_10 , V_50 -> V_14 ) ;
break;
case V_58 :
F_10 ( V_10 , V_50 -> V_14 ) ;
break;
case V_59 :
F_11 ( V_10 , V_50 -> V_14 ) ;
break;
}
return V_10 -> V_53 ;
}
static int F_22 ( struct V_10 * V_10 )
{
struct V_60 * V_61 = & V_10 -> V_52 ;
V_10 -> V_62 . V_52 = V_61 ;
F_23 ( V_61 , 5 ) ;
F_24 ( V_61 , & V_63 ,
V_55 , 0 , 127 , 1 , 0 ) ;
F_24 ( V_61 , & V_63 ,
V_56 , 0 , 64725 , 1 , 64725 ) ;
F_24 ( V_61 , & V_63 ,
V_57 , 0 , 63 , 1 , 20 ) ;
F_24 ( V_61 , & V_63 ,
V_58 , 0 , 127 , 1 , 0 ) ;
F_24 ( V_61 , & V_63 ,
V_59 , 0 , 127 , 1 , 0 ) ;
if ( V_61 -> error ) {
F_5 ( L_5 ) ;
return V_61 -> error ;
}
return 0 ;
}
static int F_25 ( struct V_64 * V_65 ,
const struct V_16 * V_17 )
{
return F_26 ( V_65 , V_17 , & V_66 , sizeof( struct V_18 ) ,
V_67 ) ;
}
