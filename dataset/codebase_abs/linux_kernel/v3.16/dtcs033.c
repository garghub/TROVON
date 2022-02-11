static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_2 V_6 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
int V_10 ;
if ( V_1 -> V_11 < 0 )
return;
V_10 = F_2 ( V_8 ,
F_3 ( V_8 , 0 ) ,
V_3 ,
V_2 ,
V_4 , V_5 ,
V_1 -> V_12 , V_6 , 500 ) ;
if ( V_10 < 0 ) {
V_1 -> V_11 = V_10 ;
F_4 ( L_1 , V_10 ) ;
}
return;
}
static int F_5 ( struct V_1 * V_1 ,
const struct V_13 * V_14 , int V_15 )
{
int V_16 = 0 ;
const struct V_13 * V_17 ;
while ( ( V_16 < V_15 ) && ( V_1 -> V_11 >= 0 ) ) {
V_17 = & V_14 [ V_16 ] ;
F_1 ( V_1 , V_17 -> V_2 , V_17 -> V_3 ,
V_17 -> V_4 , V_17 -> V_5 , V_17 -> V_6 ) ;
if ( V_1 -> V_11 < 0 ) {
F_6 ( L_2 ,
V_16 , V_15 ) ;
} else if ( V_17 -> V_2 & V_18 ) {
F_7 ( V_19 ,
L_3 ,
V_16 ,
V_17 -> V_6 ,
V_1 -> V_12 [ 0 ] ,
V_1 -> V_12 [ 1 ] ,
V_1 -> V_12 [ 2 ] ,
V_17 -> V_6 > 3 ? L_4 : L_5 ) ;
}
V_16 ++ ;
}
return V_1 -> V_11 ;
}
static int F_8 ( struct V_1 * V_1 ,
const struct V_20 * V_21 )
{
V_1 -> V_22 . V_23 = V_24 ;
V_1 -> V_22 . V_25 = F_9 ( V_24 ) ;
V_1 -> V_22 . V_26 = 1 ;
V_1 -> V_22 . V_27 = 1 ;
V_1 -> V_22 . V_28 = V_29 * 512 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_11 ( struct V_1 * V_1 ,
T_1 * V_30 ,
int V_31 )
{
if ( V_31 != V_29 * 512 ) {
V_1 -> V_32 = V_33 ;
return;
}
F_12 ( V_1 , V_34 , NULL , 0 ) ;
F_12 ( V_1 , V_35 ,
V_30 + 16 * V_29 ,
V_31 - 32 * V_29 ) ;
F_12 ( V_1 , V_36 , NULL , 0 ) ;
return;
}
static void F_13 ( struct V_1 * V_1 ,
T_3 V_37 , T_3 V_38 )
{
T_2 V_39 = ( T_2 ) V_38 ;
T_2 V_40 = 224 + ( V_39 - 14 ) * ( 768 - 224 ) / ( 33 - 14 ) ;
T_2 V_5 = 0x0100 | ( 0x00FF & V_40 ) ;
T_2 V_4 = ( 0xFF00 & V_40 ) >> 8 ;
T_2 V_41 = ( T_2 ) V_37 ;
T_2 V_42 = ( 524 * ( 150 - ( V_41 - 1 ) ) ) / 150 ;
const T_1 V_2 =
V_43 | V_44 | V_45 ;
const T_1 V_3 = 0x18 ;
F_1 ( V_1 ,
V_2 , V_3 , V_4 , V_5 , 0 ) ;
if ( V_1 -> V_11 < 0 )
F_6 ( L_6 ) ;
F_1 ( V_1 ,
V_2 , V_3 , ( V_42 << 4 ) , 0x6300 , 0 ) ;
if ( V_1 -> V_11 < 0 )
F_6 ( L_7 ) ;
}
static int F_14 ( struct V_46 * V_47 )
{
struct V_1 * V_1 =
F_15 ( V_47 -> V_48 ,
struct V_1 , V_49 ) ;
struct V_50 * V_50 = (struct V_50 * ) V_1 ;
V_1 -> V_11 = 0 ;
if ( ! V_1 -> V_51 )
return 0 ;
switch ( V_47 -> V_21 ) {
case V_52 :
F_13 ( V_1 ,
V_47 -> V_53 , V_50 -> V_38 -> V_53 ) ;
break;
case V_54 :
F_13 ( V_1 ,
V_50 -> V_55 -> V_53 , V_47 -> V_53 ) ;
break;
}
return V_1 -> V_11 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_56 * V_57 = & V_1 -> V_49 ;
struct V_50 * V_50 = (struct V_50 * ) V_1 ;
V_1 -> V_58 . V_49 = V_57 ;
F_17 ( V_57 , 2 ) ;
V_50 -> V_55 = F_18 ( V_57 , & V_59 ,
V_52 ,
1 , 150 , 1 , 75 ) ;
V_50 -> V_38 = F_18 ( V_57 , & V_59 ,
V_54 ,
14 , 33 , 1 , 24 ) ;
if ( V_57 -> error ) {
F_6 ( L_8 ,
V_57 -> error ) ;
return V_57 -> error ;
}
F_19 ( 2 , & V_50 -> V_55 ) ;
return 0 ;
}
static int F_20 ( struct V_60 * V_61 ,
const struct V_20 * V_21 )
{
return F_21 ( V_61 , V_21 ,
& V_62 , sizeof( struct V_50 ) ,
V_63 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
return F_5 ( V_1 , V_64 ,
F_9 ( V_64 ) ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_65 ,
F_9 ( V_65 ) ) ;
return;
}
