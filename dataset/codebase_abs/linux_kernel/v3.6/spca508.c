static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ,
F_3 ( V_2 , 0 ) ,
0 ,
V_6 | V_7 ,
V_4 , V_3 , NULL , 0 , 500 ) ;
F_4 ( V_8 , L_1 ,
V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( L_2 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_9 * V_9 ,
T_1 V_3 )
{
int V_5 ;
V_5 = F_2 ( V_9 -> V_2 ,
F_7 ( V_9 -> V_2 , 0 ) ,
0 ,
V_10 | V_6 | V_7 ,
0 ,
V_3 ,
V_9 -> V_11 , 1 ,
500 ) ;
F_4 ( V_12 , L_3 ,
V_3 , V_9 -> V_11 [ 0 ] ) ;
if ( V_5 < 0 ) {
F_5 ( L_4 , V_5 ) ;
return V_5 ;
}
return V_9 -> V_11 [ 0 ] ;
}
static int F_8 ( struct V_9 * V_9 ,
T_1 V_13 , T_1 V_14 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_5 , V_15 ;
V_5 = F_1 ( V_2 , 0x8802 , V_13 >> 8 ) ;
if ( V_5 < 0 )
goto V_16;
V_5 = F_1 ( V_2 , 0x8801 , V_13 & 0x00ff ) ;
if ( V_5 < 0 )
goto V_16;
if ( ( V_13 & 0xff00 ) == 0x1000 ) {
V_5 = F_1 ( V_2 , 0x8805 , V_14 & 0x00ff ) ;
if ( V_5 < 0 )
goto V_16;
V_14 >>= 8 ;
}
V_5 = F_1 ( V_2 , 0x8800 , V_14 ) ;
if ( V_5 < 0 )
goto V_16;
V_15 = 10 ;
for (; ; ) {
V_5 = F_6 ( V_9 , 0x8803 ) ;
if ( V_5 < 0 )
break;
if ( V_9 -> V_11 [ 0 ] == 0 )
break;
if ( -- V_15 <= 0 ) {
F_4 ( V_17 , L_5 ,
V_9 -> V_11 [ 0 ] ) ;
V_5 = - 1 ;
break;
}
F_9 ( 8 ) ;
}
V_16:
return V_5 ;
}
static int F_10 ( struct V_9 * V_9 ,
const struct V_18 * V_19 )
{
struct V_20 * V_20 = (struct V_20 * ) V_9 ;
struct V_21 * V_21 ;
const T_1 ( * V_22 ) [ 2 ] ;
static const T_1 ( * ( V_23 [] ) ) [ 2 ] = {
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_27 ,
V_28 ,
} ;
#ifdef F_11
int V_29 , V_30 ;
V_29 = F_6 ( V_9 , 0x8104 ) ;
V_30 = F_6 ( V_9 , 0x8105 ) ;
F_4 ( V_31 , L_6 , V_30 , V_29 ) ;
V_29 = F_6 ( V_9 , 0x8106 ) ;
V_30 = F_6 ( V_9 , 0x8107 ) ;
F_4 ( V_31 , L_7 , V_30 , V_29 ) ;
V_29 = F_6 ( V_9 , 0x8621 ) ;
F_4 ( V_31 , L_8 , V_29 ) ;
#endif
V_21 = & V_9 -> V_21 ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = F_12 ( V_33 ) ;
V_20 -> V_35 = V_19 -> V_36 ;
V_22 = V_23 [ V_20 -> V_35 ] ;
return F_13 ( V_9 , V_22 ) ;
}
static int F_14 ( struct V_9 * V_9 )
{
return 0 ;
}
static int F_15 ( struct V_9 * V_9 )
{
int V_37 ;
V_37 = V_9 -> V_21 . V_32 [ V_9 -> V_38 ] . V_39 ;
F_1 ( V_9 -> V_2 , 0x8500 , V_37 ) ;
switch ( V_37 ) {
case 0 :
case 1 :
F_1 ( V_9 -> V_2 , 0x8700 , 0x28 ) ;
break;
default:
F_1 ( V_9 -> V_2 , 0x8700 , 0x23 ) ;
break;
}
F_1 ( V_9 -> V_2 , 0x8112 , 0x10 | 0x20 ) ;
return 0 ;
}
static void F_16 ( struct V_9 * V_9 )
{
F_1 ( V_9 -> V_2 , 0x8112 , 0x20 ) ;
}
static void F_17 ( struct V_9 * V_9 ,
T_2 * V_40 ,
int V_41 )
{
switch ( V_40 [ 0 ] ) {
case 0 :
F_18 ( V_9 , V_42 , NULL , 0 ) ;
V_40 += V_43 ;
V_41 -= V_43 ;
F_18 ( V_9 , V_44 , V_40 , V_41 ) ;
break;
case 0xff :
break;
default:
V_40 += 1 ;
V_41 -= 1 ;
F_18 ( V_9 , V_45 , V_40 , V_41 ) ;
break;
}
}
static void F_19 ( struct V_9 * V_9 , T_3 V_46 )
{
F_1 ( V_9 -> V_2 , 0x8651 , V_46 ) ;
F_1 ( V_9 -> V_2 , 0x8652 , V_46 ) ;
F_1 ( V_9 -> V_2 , 0x8653 , V_46 ) ;
F_1 ( V_9 -> V_2 , 0x8654 , V_46 ) ;
}
static int F_20 ( struct V_47 * V_48 )
{
struct V_9 * V_9 =
F_21 ( V_48 -> V_49 , struct V_9 , V_50 ) ;
V_9 -> V_51 = 0 ;
if ( ! V_9 -> V_52 )
return 0 ;
switch ( V_48 -> V_19 ) {
case V_53 :
F_19 ( V_9 , V_48 -> V_14 ) ;
break;
}
return V_9 -> V_51 ;
}
static int F_22 ( struct V_9 * V_9 )
{
struct V_54 * V_55 = & V_9 -> V_50 ;
V_9 -> V_56 . V_50 = V_55 ;
F_23 ( V_55 , 5 ) ;
F_24 ( V_55 , & V_57 ,
V_53 , 0 , 255 , 1 , 128 ) ;
if ( V_55 -> error ) {
F_5 ( L_9 ) ;
return V_55 -> error ;
}
return 0 ;
}
static int F_25 ( struct V_58 * V_59 ,
const struct V_18 * V_19 )
{
return F_26 ( V_59 , V_19 , & V_60 , sizeof( struct V_20 ) ,
V_61 ) ;
}
