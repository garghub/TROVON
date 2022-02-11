static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 7000000 )
V_3 [ 3 ] |= 0x10 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 8000000 )
V_3 [ 3 ] ^= 0x10 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 8000000 )
V_3 [ 3 ] |= 0x08 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 7000000 )
V_3 [ 3 ] |= 0x08 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 8000000 )
V_3 [ 3 ] |= 0x04 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_7 * V_8 = & V_2 -> V_5 ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_12 = ( V_8 -> V_13 * 27 ) / 32000 ;
struct V_14 V_15 = {
. V_16 = V_10 -> V_17 ,
. V_18 = 0 ,
. V_3 = V_3 ,
. V_19 = 4
} ;
int V_20 ;
T_1 V_21 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
F_8 ( L_1 ,
V_25 , V_20 ) ;
if ( V_12 <= 10000 )
V_21 = 0xc ;
else if ( V_12 <= 12000 )
V_21 = 0x2 ;
else if ( V_12 <= 14000 )
V_21 = 0xa ;
else if ( V_12 <= 16000 )
V_21 = 0x6 ;
else if ( V_12 <= 18000 )
V_21 = 0xe ;
else if ( V_12 <= 20000 )
V_21 = 0x1 ;
else if ( V_12 <= 22000 )
V_21 = 0x9 ;
else if ( V_12 <= 24000 )
V_21 = 0x5 ;
else if ( V_12 <= 26000 )
V_21 = 0xd ;
else if ( V_12 <= 28000 )
V_21 = 0x3 ;
else
V_21 = 0xb ;
V_3 [ 2 ] ^= 0x1c ;
V_3 [ 2 ] |= ( ( V_21 >> 2 ) & 0x3 ) << 3 ;
V_3 [ 3 ] |= ( V_21 & 0x3 ) << 2 ;
return;
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_14 V_15 = {
. V_16 = V_10 -> V_17 ,
. V_18 = 0 ,
. V_3 = V_3 ,
. V_19 = 4
} ;
int V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
F_8 ( L_1 ,
V_25 , V_20 ) ;
V_3 [ 2 ] = 0x9e ;
V_3 [ 3 ] = 0x90 ;
return;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_2 V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
const struct V_27 * V_28 = V_10 -> V_29 ;
T_2 div ;
int V_30 ;
if ( V_26 && ( V_26 < V_28 -> V_31 || V_26 > V_28 -> V_32 ) )
return - V_33 ;
for ( V_30 = 0 ; V_30 < V_28 -> V_34 ; V_30 ++ ) {
if ( V_26 > V_28 -> V_35 [ V_30 ] . V_36 )
continue;
break;
}
if ( V_37 )
F_11 ( L_2 , V_28 -> V_38 ,
V_26 , V_30 , V_28 -> V_34 ) ;
if ( V_30 == V_28 -> V_34 )
return - V_33 ;
div = ( V_26 + V_28 -> V_39 +
V_28 -> V_35 [ V_30 ] . V_40 / 2 ) / V_28 -> V_35 [ V_30 ] . V_40 ;
V_3 [ 0 ] = div >> 8 ;
V_3 [ 1 ] = div & 0xff ;
V_3 [ 2 ] = V_28 -> V_35 [ V_30 ] . V_41 ;
V_3 [ 3 ] = V_28 -> V_35 [ V_30 ] . V_42 ;
if ( V_28 -> V_43 )
V_28 -> V_43 ( V_2 , V_3 ) ;
if ( V_37 )
F_11 ( L_3 ,
V_28 -> V_38 , div , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
return ( div * V_28 -> V_35 [ V_30 ] . V_40 ) - V_28 -> V_39 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_24 == NULL )
return - V_33 ;
if ( V_10 -> V_29 -> V_44 ) {
struct V_14 V_15 = { . V_18 = 0 ,
. V_16 = V_10 -> V_17 ,
. V_3 = V_10 -> V_29 -> V_44 + 1 ,
. V_19 = V_10 -> V_29 -> V_44 [ 0 ] } ;
int V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
if ( ( V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ) != 1 ) {
return V_20 ;
}
return 0 ;
}
return - V_33 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_5 ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_3 [ 4 ] ;
struct V_14 V_15 =
{ . V_16 = V_10 -> V_17 , . V_18 = 0 ,
. V_3 = V_3 , . V_19 = sizeof( V_3 ) } ;
int V_20 ;
T_2 V_26 = 0 ;
if ( V_10 -> V_24 == NULL )
return - V_33 ;
V_20 = F_10 ( V_2 , V_3 , V_8 -> V_26 ) ;
if ( V_20 < 0 )
return V_20 ;
else
V_26 = V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
if ( ( V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ) != 1 ) {
return V_20 ;
}
V_10 -> V_26 = V_26 ;
V_10 -> V_45 = V_8 -> V_6 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_46 )
{
struct V_7 * V_8 = & V_2 -> V_5 ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_20 ;
T_2 V_26 = 0 ;
if ( V_46 < 5 )
return - V_33 ;
V_20 = F_10 ( V_2 , V_3 + 1 , V_8 -> V_26 ) ;
if ( V_20 < 0 )
return V_20 ;
else
V_26 = V_20 ;
V_3 [ 0 ] = V_10 -> V_17 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_45 = V_8 -> V_6 ;
return 5 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_26 = V_10 -> V_26 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_45 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_45 = V_10 -> V_45 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_24 == NULL )
return - V_33 ;
if ( V_10 -> V_29 -> V_47 ) {
struct V_14 V_15 = { . V_18 = 0 ,
. V_16 = V_10 -> V_17 ,
. V_3 = V_10 -> V_29 -> V_47 + 1 ,
. V_19 = V_10 -> V_29 -> V_47 [ 0 ] } ;
int V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
return V_20 ;
if ( V_10 -> V_29 -> V_48 ) {
V_15 . V_3 = V_10 -> V_29 -> V_48 + 1 ;
V_15 . V_19 = V_10 -> V_29 -> V_48 [ 0 ] ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_7 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
return V_20 ;
}
return 0 ;
}
return - V_33 ;
}
struct V_1 * F_20 ( struct V_1 * V_2 , int V_49 ,
struct V_50 * V_24 ,
unsigned int V_51 )
{
T_1 * V_52 ;
struct V_14 V_15 = { . V_16 = V_49 , . V_18 = V_53 , . V_19 = 1 } ;
struct V_9 * V_10 = NULL ;
int V_54 ;
const struct V_27 * V_28 ;
V_52 = F_21 ( 1 , V_55 ) ;
if ( ! V_52 )
return NULL ;
V_52 [ 0 ] = 0 ;
V_15 . V_3 = V_52 ;
if ( ( V_56 [ V_57 ] > V_58 ) &&
( V_56 [ V_57 ] < F_22 ( V_59 ) ) )
V_51 = V_56 [ V_57 ] ;
F_23 ( V_51 < 1 || V_51 >= F_22 ( V_59 ) ) ;
V_28 = V_59 [ V_51 ] ;
if ( V_24 != NULL ) {
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_54 = F_7 ( V_24 , & V_15 , 1 ) ;
if ( V_54 != 1 ) {
F_13 ( V_52 ) ;
return NULL ;
}
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 0 ) ;
}
V_10 = F_24 ( sizeof( struct V_9 ) , V_55 ) ;
if ( ! V_10 ) {
F_13 ( V_52 ) ;
return NULL ;
}
V_10 -> V_17 = V_49 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_29 = V_28 ;
V_10 -> V_60 = V_57 ++ ;
memcpy ( & V_2 -> V_22 . V_61 , & V_62 ,
sizeof( struct V_63 ) ) ;
strncpy ( V_2 -> V_22 . V_61 . V_64 . V_38 , V_28 -> V_38 ,
sizeof( V_2 -> V_22 . V_61 . V_64 . V_38 ) ) ;
V_2 -> V_22 . V_61 . V_64 . V_65 = V_28 -> V_31 ;
V_2 -> V_22 . V_61 . V_64 . V_66 = V_28 -> V_32 ;
if ( ! V_28 -> V_47 )
V_2 -> V_22 . V_61 . V_67 = NULL ;
if ( ! V_28 -> V_44 )
V_2 -> V_22 . V_61 . V_68 = NULL ;
V_2 -> V_11 = V_10 ;
if ( ( V_37 ) || ( V_56 [ V_10 -> V_60 ] == V_51 ) ) {
F_11 ( L_4 , V_10 -> V_60 ) ;
if ( V_24 != NULL )
F_25 ( L_5 , F_26 ( V_24 ) , V_49 ) ;
F_25 ( L_6 , V_51 , V_28 -> V_38 ,
V_56 [ V_10 -> V_60 ] == V_51 ?
L_7 : L_8 ) ;
}
F_13 ( V_52 ) ;
return V_2 ;
}
