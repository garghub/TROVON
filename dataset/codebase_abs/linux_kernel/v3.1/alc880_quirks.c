static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x15 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x16 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
switch ( V_11 >> 28 ) {
case V_12 :
F_4 ( V_2 ) ;
break;
default:
F_6 ( V_2 , V_11 ) ;
break;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x15 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
V_13 = F_9 ( V_2 , 0x21 , 0 ,
V_14 , 0 ) ;
V_13 &= V_15 ;
F_10 ( V_2 , 0x0c , V_16 , 0 ,
V_15 , V_13 ) ;
F_10 ( V_2 , 0x0d , V_16 , 0 ,
V_15 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
if ( ( V_11 >> 28 ) == V_17 )
F_8 ( V_2 ) ;
else
F_6 ( V_2 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x17 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x1b ;
V_4 -> V_5 . V_7 [ 0 ] = 0x14 ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_2 ) ;
if ( V_4 -> V_18 )
F_15 ( V_2 , 0x01 , 0 , V_19 , 0 ) ;
else
F_15 ( V_2 , 0x01 , 0 , V_19 , 2 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
if ( ( V_11 >> 28 ) == V_20 )
F_14 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 [ 0 ] = 0x14 ;
V_4 -> V_5 . V_7 [ 0 ] = 0x1b ;
V_4 -> V_8 = 1 ;
V_4 -> V_9 = V_10 ;
}
static int F_18 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
static const char * const V_25 [] = {
L_1 , L_2 , L_3 ,
L_4 , L_5 , L_6 , L_7 , L_8
} ;
V_24 -> type = V_26 ;
V_24 -> V_27 = 1 ;
V_24 -> V_28 . V_29 . V_30 = 8 ;
if ( V_24 -> V_28 . V_29 . V_31 >= 8 )
V_24 -> V_28 . V_29 . V_31 = 7 ;
strcpy ( V_24 -> V_28 . V_29 . V_32 , V_25 [ V_24 -> V_28 . V_29 . V_31 ] ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_20 ( V_22 ) ;
T_1 V_35 = ( T_1 ) V_22 -> V_36 ;
unsigned int V_37 , V_31 = 0 ;
V_37 = F_9 ( V_2 , V_35 , 0 ,
V_38 , 0 ) ;
if ( V_37 & V_39 ) {
if ( V_37 & V_40 )
V_31 = 2 ;
else
V_31 = 1 ;
} else if ( V_37 & V_41 ) {
switch ( V_37 & V_42 ) {
case V_43 : V_31 = 3 ; break;
case V_44 : V_31 = 4 ; break;
case V_45 : V_31 = 5 ; break;
case V_46 : V_31 = 6 ; break;
case V_47 : V_31 = 7 ; break;
}
}
V_34 -> V_28 . V_29 . V_31 [ 0 ] = V_31 ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_20 ( V_22 ) ;
T_1 V_35 = ( T_1 ) V_22 -> V_36 ;
static const unsigned int V_48 [] = {
0 , V_39 , V_39 | V_40 ,
V_41 | V_43 ,
V_41 | V_44 ,
V_41 | V_45 ,
V_41 | V_46 ,
V_41 | V_47 ,
} ;
unsigned int V_49 , V_50 ;
V_49 = F_9 ( V_2 , V_35 , 0 ,
V_38 , 0 ) ;
V_50 = V_48 [ V_34 -> V_28 . V_29 . V_31 [ 0 ] ] ;
if ( V_49 != V_50 ) {
int V_51 ;
F_22 ( V_2 , V_35 , 0 ,
V_52 ,
V_50 ) ;
V_51 = V_34 -> V_28 . V_29 . V_31 [ 0 ] >= 3 ?
V_53 : 0 ;
F_10 ( V_2 , V_35 , V_16 , 0 ,
V_53 , V_51 ) ;
return 1 ;
}
return 0 ;
}
static int F_23 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
static const char * const V_25 [] = {
L_9 , L_10 , L_11 , L_12
} ;
V_24 -> type = V_26 ;
V_24 -> V_27 = 1 ;
V_24 -> V_28 . V_29 . V_30 = 4 ;
if ( V_24 -> V_28 . V_29 . V_31 >= 4 )
V_24 -> V_28 . V_29 . V_31 = 3 ;
strcpy ( V_24 -> V_28 . V_29 . V_32 , V_25 [ V_24 -> V_28 . V_29 . V_31 ] ) ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_20 ( V_22 ) ;
T_1 V_35 = ( T_1 ) V_22 -> V_36 ;
unsigned int V_54 ;
V_54 = F_9 ( V_2 , V_35 , 0 , V_55 , 0 ) ;
V_34 -> V_28 . V_29 . V_31 [ 0 ] = V_54 & 3 ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_20 ( V_22 ) ;
T_1 V_35 = ( T_1 ) V_22 -> V_36 ;
unsigned int V_54 ;
V_54 = F_9 ( V_2 , V_35 , 0 , V_55 , 0 ) & 3 ;
if ( V_34 -> V_28 . V_29 . V_31 [ 0 ] != V_54 ) {
V_54 = V_34 -> V_28 . V_29 . V_31 [ 0 ] & 3 ;
F_22 ( V_2 , V_35 , 0 ,
V_56 , V_54 ) ;
return 1 ;
}
return 0 ;
}
