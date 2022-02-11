static int F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_5 = F_2 ( V_7 ,
F_3 ( V_7 , 0 ) ,
V_2 ,
V_8 | V_9 ,
V_4 , V_3 , NULL , 0 , 500 ) ;
F_4 ( V_10 , L_1 ,
V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( L_2 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_1 , const T_1 V_11 [] [ 3 ] )
{
int V_5 , V_12 = 0 ;
while ( V_11 [ V_12 ] [ 0 ] != 0 || V_11 [ V_12 ] [ 1 ] != 0 || V_11 [ V_12 ] [ 2 ] != 0 ) {
V_5 = F_1 ( V_1 , V_11 [ V_12 ] [ 0 ] , V_11 [ V_12 ] [ 2 ] ,
V_11 [ V_12 ] [ 1 ] ) ;
if ( V_5 < 0 ) {
F_7 ( L_3 ,
V_11 [ V_12 ] [ 0 ] , V_11 [ V_12 ] [ 1 ] , V_11 [ V_12 ] [ 2 ] ) ;
return V_5 ;
}
V_12 ++ ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_1 , T_2 V_13 )
{
F_1 ( V_1 , V_14 , 0x12 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_2 V_13 )
{
F_1 ( V_1 , 0x00 , 0x00 , ( V_13 >> 8 ) & 0xff ) ;
F_1 ( V_1 , 0x00 , 0x01 , V_13 & 0xff ) ;
}
static void F_10 ( struct V_1 * V_1 , T_2 V_13 )
{
F_1 ( V_1 , V_14 , 0x0c , V_13 ) ;
}
static void F_11 ( struct V_1 * V_1 , T_2 V_13 )
{
F_1 ( V_1 , V_14 , 0x11 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_1 , T_2 V_13 )
{
F_1 ( V_1 , V_14 , 0x13 , V_13 ) ;
}
static int F_13 ( struct V_1 * V_1 ,
const struct V_15 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_18 * V_18 ;
V_18 = & V_1 -> V_18 ;
V_18 -> V_19 = V_20 ;
V_18 -> V_21 = F_14 ( V_20 ) ;
V_17 -> V_22 = V_16 -> V_23 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
switch ( V_17 -> V_22 ) {
case V_24 :
case V_25 :
if ( F_6 ( V_1 , V_26 ) )
goto error;
break;
case V_27 :
if ( F_6 ( V_1 , V_28 ) )
goto error;
break;
default:
if ( F_6 ( V_1 , V_29 ) )
goto error;
break;
}
F_4 ( V_30 , L_4 ) ;
return 0 ;
error:
return - V_31 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_32 ;
switch ( V_17 -> V_22 ) {
case V_33 :
F_6 ( V_1 , V_34 ) ;
break;
case V_24 :
case V_25 :
F_6 ( V_1 , V_35 ) ;
break;
case V_27 :
F_6 ( V_1 , V_36 ) ;
break;
default:
F_6 ( V_1 , V_37 ) ;
}
V_32 = V_1 -> V_18 . V_19 [ ( int ) V_1 -> V_38 ] . V_39 ;
F_1 ( V_1 , V_40 , 0x6 , 0x94 ) ;
switch ( V_32 ) {
case 0 :
F_1 ( V_1 , V_40 , 0x07 , 0x004a ) ;
break;
case 1 :
F_1 ( V_1 , V_40 , 0x07 , 0x104a ) ;
break;
default:
F_1 ( V_1 , V_40 , 0x07 , 0x204a ) ;
break;
}
F_1 ( V_1 , V_41 , 0x01 , 0x02 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_41 , 0x01 , 0x00 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_42 )
return;
F_1 ( V_1 , V_41 , 0x05 , 0x00 ) ;
}
static void F_19 ( struct V_1 * V_1 ,
T_3 * V_11 ,
int V_43 )
{
switch ( V_11 [ 0 ] ) {
case 0 :
F_20 ( V_1 , V_44 , NULL , 0 ) ;
V_11 += V_45 ;
V_43 -= V_45 ;
F_20 ( V_1 , V_46 , V_11 , V_43 ) ;
return;
case 0xff :
return;
}
V_11 ++ ;
V_43 -- ;
F_20 ( V_1 , V_47 , V_11 , V_43 ) ;
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_1 * V_1 =
F_22 ( V_49 -> V_50 , struct V_1 , V_51 ) ;
V_1 -> V_52 = 0 ;
if ( ! V_1 -> V_53 )
return 0 ;
switch ( V_49 -> V_16 ) {
case V_54 :
F_8 ( V_1 , V_49 -> V_13 ) ;
break;
case V_55 :
F_9 ( V_1 , V_49 -> V_13 ) ;
break;
case V_56 :
F_10 ( V_1 , V_49 -> V_13 ) ;
break;
case V_57 :
F_11 ( V_1 , V_49 -> V_13 ) ;
break;
case V_58 :
F_12 ( V_1 , V_49 -> V_13 ) ;
break;
}
return V_1 -> V_52 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = & V_1 -> V_51 ;
V_1 -> V_61 . V_51 = V_60 ;
F_24 ( V_60 , 5 ) ;
F_25 ( V_60 , & V_62 ,
V_54 , 0 , 127 , 1 , 0 ) ;
F_25 ( V_60 , & V_62 ,
V_55 , 0 , 64725 , 1 , 64725 ) ;
F_25 ( V_60 , & V_62 ,
V_56 , 0 , 63 , 1 , 20 ) ;
F_25 ( V_60 , & V_62 ,
V_57 , 0 , 127 , 1 , 0 ) ;
F_25 ( V_60 , & V_62 ,
V_58 , 0 , 127 , 1 , 0 ) ;
if ( V_60 -> error ) {
F_5 ( L_5 ) ;
return V_60 -> error ;
}
return 0 ;
}
static int F_26 ( struct V_63 * V_64 ,
const struct V_15 * V_16 )
{
return F_27 ( V_64 , V_16 , & V_65 , sizeof( struct V_17 ) ,
V_66 ) ;
}
