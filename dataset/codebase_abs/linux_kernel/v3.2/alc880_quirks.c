static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x15 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x16 ;
F_2 ( V_4 , V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
switch ( V_9 >> 28 ) {
case V_10 :
F_5 ( V_2 ) ;
break;
default:
F_7 ( V_2 , V_9 ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x15 ;
F_2 ( V_4 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
V_11 = F_10 ( V_2 , 0x21 , 0 ,
V_12 , 0 ) ;
V_11 &= V_13 ;
F_11 ( V_2 , 0x0c , V_14 , 0 ,
V_13 , V_11 ) ;
F_11 ( V_2 , 0x0d , V_14 , 0 ,
V_13 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
if ( ( V_9 >> 28 ) == V_15 )
F_9 ( V_2 ) ;
else
F_7 ( V_2 , V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x17 ;
F_2 ( V_4 , V_8 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x14 ;
F_2 ( V_4 , V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_2 ) ;
if ( V_4 -> V_16 )
F_16 ( V_2 , 0x01 , 0 , V_17 , 0 ) ;
else
F_16 ( V_2 , 0x01 , 0 , V_17 , 2 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
if ( ( V_9 >> 28 ) == V_18 )
F_15 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x1b ;
F_2 ( V_4 , V_8 ) ;
}
static int F_19 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
static const char * const V_23 [] = {
L_1 , L_2 , L_3 ,
L_4 , L_5 , L_6 , L_7 , L_8
} ;
V_22 -> type = V_24 ;
V_22 -> V_25 = 1 ;
V_22 -> V_26 . V_27 . V_28 = 8 ;
if ( V_22 -> V_26 . V_27 . V_29 >= 8 )
V_22 -> V_26 . V_27 . V_29 = 7 ;
strcpy ( V_22 -> V_26 . V_27 . V_30 , V_23 [ V_22 -> V_26 . V_27 . V_29 ] ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
T_1 V_33 = ( T_1 ) V_20 -> V_34 ;
unsigned int V_35 , V_29 = 0 ;
V_35 = F_10 ( V_2 , V_33 , 0 ,
V_36 , 0 ) ;
if ( V_35 & V_37 ) {
if ( V_35 & V_38 )
V_29 = 2 ;
else
V_29 = 1 ;
} else if ( V_35 & V_39 ) {
switch ( V_35 & V_40 ) {
case V_41 : V_29 = 3 ; break;
case V_42 : V_29 = 4 ; break;
case V_43 : V_29 = 5 ; break;
case V_44 : V_29 = 6 ; break;
case V_45 : V_29 = 7 ; break;
}
}
V_32 -> V_26 . V_27 . V_29 [ 0 ] = V_29 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
T_1 V_33 = ( T_1 ) V_20 -> V_34 ;
static const unsigned int V_46 [] = {
0 , V_37 , V_37 | V_38 ,
V_39 | V_41 ,
V_39 | V_42 ,
V_39 | V_43 ,
V_39 | V_44 ,
V_39 | V_45 ,
} ;
unsigned int V_47 , V_48 ;
V_47 = F_10 ( V_2 , V_33 , 0 ,
V_36 , 0 ) ;
V_48 = V_46 [ V_32 -> V_26 . V_27 . V_29 [ 0 ] ] ;
if ( V_47 != V_48 ) {
int V_49 ;
F_23 ( V_2 , V_33 , 0 ,
V_50 ,
V_48 ) ;
V_49 = V_32 -> V_26 . V_27 . V_29 [ 0 ] >= 3 ?
V_51 : 0 ;
F_11 ( V_2 , V_33 , V_14 , 0 ,
V_51 , V_49 ) ;
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
static const char * const V_23 [] = {
L_9 , L_10 , L_11 , L_12
} ;
V_22 -> type = V_24 ;
V_22 -> V_25 = 1 ;
V_22 -> V_26 . V_27 . V_28 = 4 ;
if ( V_22 -> V_26 . V_27 . V_29 >= 4 )
V_22 -> V_26 . V_27 . V_29 = 3 ;
strcpy ( V_22 -> V_26 . V_27 . V_30 , V_23 [ V_22 -> V_26 . V_27 . V_29 ] ) ;
return 0 ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
T_1 V_33 = ( T_1 ) V_20 -> V_34 ;
unsigned int V_52 ;
V_52 = F_10 ( V_2 , V_33 , 0 , V_53 , 0 ) ;
V_32 -> V_26 . V_27 . V_29 [ 0 ] = V_52 & 3 ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
T_1 V_33 = ( T_1 ) V_20 -> V_34 ;
unsigned int V_52 ;
V_52 = F_10 ( V_2 , V_33 , 0 , V_53 , 0 ) & 3 ;
if ( V_32 -> V_26 . V_27 . V_29 [ 0 ] != V_52 ) {
V_52 = V_32 -> V_26 . V_27 . V_29 [ 0 ] & 3 ;
F_23 ( V_2 , V_33 , 0 ,
V_54 , V_52 ) ;
return 1 ;
}
return 0 ;
}
