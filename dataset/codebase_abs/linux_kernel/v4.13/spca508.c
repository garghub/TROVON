static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_6 ;
V_4 = F_2 ( V_6 ,
F_3 ( V_6 , 0 ) ,
0 ,
V_7 | V_8 ,
V_3 , V_2 , NULL , 0 , 500 ) ;
F_4 ( V_9 , L_1 ,
V_2 , V_3 ) ;
if ( V_4 < 0 )
F_5 ( L_2 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 ,
T_1 V_2 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_6 ,
F_7 ( V_1 -> V_6 , 0 ) ,
0 ,
V_10 | V_7 | V_8 ,
0 ,
V_2 ,
V_1 -> V_11 , 1 ,
500 ) ;
F_4 ( V_12 , L_3 ,
V_2 , V_1 -> V_11 [ 0 ] ) ;
if ( V_4 < 0 ) {
F_5 ( L_4 , V_4 ) ;
return V_4 ;
}
return V_1 -> V_11 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_1 ,
T_1 V_13 , T_1 V_14 )
{
int V_4 , V_15 ;
V_4 = F_1 ( V_1 , 0x8802 , V_13 >> 8 ) ;
if ( V_4 < 0 )
goto V_16;
V_4 = F_1 ( V_1 , 0x8801 , V_13 & 0x00ff ) ;
if ( V_4 < 0 )
goto V_16;
if ( ( V_13 & 0xff00 ) == 0x1000 ) {
V_4 = F_1 ( V_1 , 0x8805 , V_14 & 0x00ff ) ;
if ( V_4 < 0 )
goto V_16;
V_14 >>= 8 ;
}
V_4 = F_1 ( V_1 , 0x8800 , V_14 ) ;
if ( V_4 < 0 )
goto V_16;
V_15 = 10 ;
for (; ; ) {
V_4 = F_6 ( V_1 , 0x8803 ) ;
if ( V_4 < 0 )
break;
if ( V_1 -> V_11 [ 0 ] == 0 )
break;
if ( -- V_15 <= 0 ) {
F_9 ( L_5 , V_1 -> V_11 [ 0 ] ) ;
V_4 = - 1 ;
break;
}
F_10 ( 8 ) ;
}
V_16:
return V_4 ;
}
static int F_11 ( struct V_1 * V_1 ,
const struct V_17 * V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_20 * V_20 ;
const T_1 ( * V_21 ) [ 2 ] ;
static const T_1 ( * ( V_22 [] ) ) [ 2 ] = {
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_26 ,
V_27 ,
} ;
int V_28 , V_29 ;
V_28 = F_6 ( V_1 , 0x8104 ) ;
V_29 = F_6 ( V_1 , 0x8105 ) ;
F_4 ( V_30 , L_6 , V_29 , V_28 ) ;
V_28 = F_6 ( V_1 , 0x8106 ) ;
V_29 = F_6 ( V_1 , 0x8107 ) ;
F_4 ( V_30 , L_7 , V_29 , V_28 ) ;
V_28 = F_6 ( V_1 , 0x8621 ) ;
F_4 ( V_30 , L_8 , V_28 ) ;
V_20 = & V_1 -> V_20 ;
V_20 -> V_31 = V_32 ;
V_20 -> V_33 = F_12 ( V_32 ) ;
V_19 -> V_34 = V_18 -> V_35 ;
V_21 = V_22 [ V_19 -> V_34 ] ;
return F_13 ( V_1 , V_21 ) ;
}
static int F_14 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_36 ;
V_36 = V_1 -> V_20 . V_31 [ V_1 -> V_37 ] . V_38 ;
F_1 ( V_1 , 0x8500 , V_36 ) ;
switch ( V_36 ) {
case 0 :
case 1 :
F_1 ( V_1 , 0x8700 , 0x28 ) ;
break;
default:
F_1 ( V_1 , 0x8700 , 0x23 ) ;
break;
}
F_1 ( V_1 , 0x8112 , 0x10 | 0x20 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x8112 , 0x20 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
T_2 * V_39 ,
int V_40 )
{
switch ( V_39 [ 0 ] ) {
case 0 :
F_18 ( V_1 , V_41 , NULL , 0 ) ;
V_39 += V_42 ;
V_40 -= V_42 ;
F_18 ( V_1 , V_43 , V_39 , V_40 ) ;
break;
case 0xff :
break;
default:
V_39 += 1 ;
V_40 -= 1 ;
F_18 ( V_1 , V_44 , V_39 , V_40 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_1 , T_3 V_45 )
{
F_1 ( V_1 , 0x8651 , V_45 ) ;
F_1 ( V_1 , 0x8652 , V_45 ) ;
F_1 ( V_1 , 0x8653 , V_45 ) ;
F_1 ( V_1 , 0x8654 , V_45 ) ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_1 * V_1 =
F_21 ( V_47 -> V_48 , struct V_1 , V_49 ) ;
V_1 -> V_50 = 0 ;
if ( ! V_1 -> V_51 )
return 0 ;
switch ( V_47 -> V_18 ) {
case V_52 :
F_19 ( V_1 , V_47 -> V_14 ) ;
break;
}
return V_1 -> V_50 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_53 * V_54 = & V_1 -> V_49 ;
V_1 -> V_55 . V_49 = V_54 ;
F_23 ( V_54 , 5 ) ;
F_24 ( V_54 , & V_56 ,
V_52 , 0 , 255 , 1 , 128 ) ;
if ( V_54 -> error ) {
F_5 ( L_9 ) ;
return V_54 -> error ;
}
return 0 ;
}
static int F_25 ( struct V_57 * V_58 ,
const struct V_17 * V_18 )
{
return F_26 ( V_58 , V_18 , & V_59 , sizeof( struct V_19 ) ,
V_60 ) ;
}
