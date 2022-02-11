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
V_9 >>= 28 ;
switch ( V_9 ) {
case V_10 :
F_5 ( V_2 ) ;
break;
default:
F_7 ( V_2 , V_9 ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_9 )
{
F_7 ( V_2 , V_9 >> 28 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x15 ;
F_2 ( V_4 , V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
V_11 = F_11 ( V_2 , 0x21 , 0 ,
V_12 , 0 ) ;
V_11 &= V_13 ;
F_12 ( V_2 , 0x0c , V_14 , 0 ,
V_13 , V_11 ) ;
F_12 ( V_2 , 0x0d , V_14 , 0 ,
V_13 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
V_9 >>= 28 ;
if ( V_9 == V_15 )
F_10 ( V_2 ) ;
else
F_7 ( V_2 , V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x17 ;
F_2 ( V_4 , V_8 ) ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
static const char * const V_20 [] = {
L_1 , L_2 , L_3 ,
L_4 , L_5 , L_6 , L_7 , L_8
} ;
V_19 -> type = V_21 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . V_24 . V_25 = 8 ;
if ( V_19 -> V_23 . V_24 . V_26 >= 8 )
V_19 -> V_23 . V_24 . V_26 = 7 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_20 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_1 V_30 = ( T_1 ) V_17 -> V_31 ;
unsigned int V_32 , V_26 = 0 ;
V_32 = F_11 ( V_2 , V_30 , 0 ,
V_33 , 0 ) ;
if ( V_32 & V_34 ) {
if ( V_32 & V_35 )
V_26 = 2 ;
else
V_26 = 1 ;
} else if ( V_32 & V_36 ) {
switch ( V_32 & V_37 ) {
case V_38 : V_26 = 3 ; break;
case V_39 : V_26 = 4 ; break;
case V_40 : V_26 = 5 ; break;
case V_41 : V_26 = 6 ; break;
case V_42 : V_26 = 7 ; break;
}
}
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_26 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_1 V_30 = ( T_1 ) V_17 -> V_31 ;
static const unsigned int V_43 [] = {
0 , V_34 , V_34 | V_35 ,
V_36 | V_38 ,
V_36 | V_39 ,
V_36 | V_40 ,
V_36 | V_41 ,
V_36 | V_42 ,
} ;
unsigned int V_44 , V_45 ;
V_44 = F_11 ( V_2 , V_30 , 0 ,
V_33 , 0 ) ;
V_45 = V_43 [ V_29 -> V_23 . V_24 . V_26 [ 0 ] ] ;
if ( V_44 != V_45 ) {
int V_46 ;
F_19 ( V_2 , V_30 , 0 ,
V_47 ,
V_45 ) ;
V_46 = V_29 -> V_23 . V_24 . V_26 [ 0 ] >= 3 ?
V_48 : 0 ;
F_12 ( V_2 , V_30 , V_14 , 0 ,
V_48 , V_46 ) ;
return 1 ;
}
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
static const char * const V_20 [] = {
L_9 , L_10 , L_11 , L_12
} ;
V_19 -> type = V_21 ;
V_19 -> V_22 = 1 ;
V_19 -> V_23 . V_24 . V_25 = 4 ;
if ( V_19 -> V_23 . V_24 . V_26 >= 4 )
V_19 -> V_23 . V_24 . V_26 = 3 ;
strcpy ( V_19 -> V_23 . V_24 . V_27 , V_20 [ V_19 -> V_23 . V_24 . V_26 ] ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_1 V_30 = ( T_1 ) V_17 -> V_31 ;
unsigned int V_49 ;
V_49 = F_11 ( V_2 , V_30 , 0 , V_50 , 0 ) ;
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_49 & 3 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_1 V_30 = ( T_1 ) V_17 -> V_31 ;
unsigned int V_49 ;
V_49 = F_11 ( V_2 , V_30 , 0 , V_50 , 0 ) & 3 ;
if ( V_29 -> V_23 . V_24 . V_26 [ 0 ] != V_49 ) {
V_49 = V_29 -> V_23 . V_24 . V_26 [ 0 ] & 3 ;
F_19 ( V_2 , V_30 , 0 ,
V_51 , V_49 ) ;
return 1 ;
}
return 0 ;
}
