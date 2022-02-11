static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_5 , V_3 ) ;
F_3 ( L_1 , V_3 ? L_2 : L_3 ) ;
}
void F_4 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_6 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_7 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_8 [ 6 ] )
{
T_2 V_9 , V_10 ;
V_10 = V_2 -> V_11 ( V_2 , V_12 ) ;
V_9 . V_13 . V_14 = V_8 [ 0 ] ;
V_9 . V_13 . V_15 = V_8 [ 1 ] ;
V_9 . V_13 . V_16 = V_8 [ 2 ] ;
V_9 . V_13 . V_17 = V_8 [ 3 ] ;
V_10 . V_12 . V_18 = V_8 [ 4 ] ;
V_10 . V_12 . V_19 = V_8 [ 5 ] ;
V_2 -> V_20 ( V_2 , V_13 , V_9 ) ;
V_2 -> V_20 ( V_2 , V_12 , V_10 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_21 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_3 V_22 , T_3 V_23 )
{
T_2 V_24 ;
V_24 . V_25 . V_26 = V_22 ;
V_24 . V_25 . V_27 = V_23 ;
V_2 -> V_20 ( V_2 , V_28 , V_24 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_29 , V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_30 , V_31 , V_32 ,
V_33 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_30 , V_34 , V_35 ,
V_36 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_37 , V_38 , V_39 , V_40 , 0 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_37 , V_41 , V_42 , V_43 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_44 , V_45 , V_46 , V_47 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_3 V_22 , int V_3 )
{
F_11 ( V_44 , V_48 , V_49 , V_50 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
int V_51 , T_3 V_22 , int V_3 )
{
if ( V_22 == 0x2000 )
return;
F_3 ( L_4 ,
V_22 , V_22 , V_51 , V_3 ? L_2 : L_3 ) ;
if ( V_2 -> V_52 )
V_51 += 6 ;
switch ( V_51 ) {
case 0 :
F_10 ( V_2 , V_22 , V_3 ) ;
break;
case 1 :
F_12 ( V_2 , V_22 , V_3 ) ;
break;
case 2 :
F_13 ( V_2 , V_22 , V_3 ) ;
break;
case 3 :
F_14 ( V_2 , V_22 , V_3 ) ;
break;
case 4 :
F_15 ( V_2 , V_22 , V_3 ) ;
break;
case 5 :
F_16 ( V_2 , V_22 , V_3 ) ;
break;
default:
if ( V_2 -> V_53 && V_51 < 38 ) {
T_2 V_54 , V_55 ;
V_55 = V_2 -> V_11 ( V_2 , V_56 ) ;
V_55 . V_56 . V_57 = V_51 - 6 ;
V_2 -> V_20 ( V_2 , V_56 , V_55 ) ;
V_54 = V_2 -> V_11 ( V_2 , V_58 ) ;
V_54 . V_58 . V_59 = V_3 ? V_22 : 0x1fff ;
V_54 . V_58 . V_60 = V_3 ;
V_2 -> V_20 ( V_2 , V_58 , V_54 ) ;
}
break;
}
}
static int F_18 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_61 != V_3 ) {
F_3 ( L_5 , V_3 ? L_6 : L_7 ) ;
F_8 ( V_2 , 0 , 0x1fe0 * ( ! V_3 ) ) ;
F_9 ( V_2 , V_3 ) ;
V_2 -> V_61 = V_3 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_62 * V_63 , int V_3 )
{
int V_64 = 6 ;
V_64 -= 6 * V_2 -> V_52 ;
V_64 += 32 * V_2 -> V_53 ;
V_2 -> V_65 += V_3 ? 1 : - 1 ;
if ( V_63 -> V_51 >= V_64 )
V_2 -> V_66 += V_3 ? 1 : - 1 ;
if ( ! V_2 -> V_67 && V_2 -> V_65 == V_3 )
F_18 ( V_2 , V_3 ) ;
if ( V_2 -> V_67 ) {
F_17 \
( V_2 , V_63 -> V_51 , V_63 -> V_22 , V_3 ) ;
if ( V_2 -> V_66 > 0 )
F_18 ( V_2 , 1 ) ;
else if ( V_63 -> V_22 == 0x2000 )
F_18 ( V_2 , V_3 ) ;
else
F_18 ( V_2 , 0 ) ;
}
if ( V_2 -> V_65 == V_3 ) {
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_68 )
V_2 -> V_68 ( V_2 , V_3 ) ;
if ( V_3 == 0 ) {
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_69 ;
T_2 V_70 ;
int V_64 = 6 ;
V_64 -= 6 * V_2 -> V_52 ;
V_64 += 32 * V_2 -> V_53 ;
for ( V_69 = 0 ; V_69 < V_64 ; V_69 ++ )
F_17 ( V_2 , V_69 , 0x1fff , 0 ) ;
F_8 ( V_2 , 0 , 0x1fe0 ) ;
F_9 ( V_2 , 0 ) ;
V_70 = V_2 -> V_11 ( V_2 , V_44 ) ;
V_70 . V_44 . V_71 = 1 ;
V_70 . V_44 . V_72 = 0 ;
V_2 -> V_20 ( V_2 , V_44 , V_70 ) ;
F_5 ( V_2 , 1 ) ;
}
