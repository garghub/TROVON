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
V_3 [ 3 ] |= 0x08 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 7000000 )
V_3 [ 3 ] |= 0x08 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = V_2 -> V_5 . V_6 ;
if ( V_4 == 8000000 )
V_3 [ 3 ] |= 0x04 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 )
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
V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
F_7 ( V_25 L_1 ,
V_26 , V_20 ) ;
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
static void F_8 ( struct V_1 * V_2 , T_1 * V_3 )
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
V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
F_7 ( V_25 L_1 ,
V_26 , V_20 ) ;
V_3 [ 2 ] = 0x9e ;
V_3 [ 3 ] = 0x90 ;
return;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_2 V_27 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_28 * V_29 = V_10 -> V_30 ;
T_2 div ;
int V_31 ;
if ( V_27 && ( V_27 < V_29 -> V_32 || V_27 > V_29 -> V_33 ) )
return - V_34 ;
for ( V_31 = 0 ; V_31 < V_29 -> V_35 ; V_31 ++ ) {
if ( V_27 > V_29 -> V_36 [ V_31 ] . V_37 )
continue;
break;
}
if ( V_38 )
F_7 ( L_2 , V_29 -> V_39 ,
V_27 , V_31 , V_29 -> V_35 ) ;
if ( V_31 == V_29 -> V_35 )
return - V_34 ;
div = ( V_27 + V_29 -> V_40 +
V_29 -> V_36 [ V_31 ] . V_41 / 2 ) / V_29 -> V_36 [ V_31 ] . V_41 ;
V_3 [ 0 ] = div >> 8 ;
V_3 [ 1 ] = div & 0xff ;
V_3 [ 2 ] = V_29 -> V_36 [ V_31 ] . V_42 ;
V_3 [ 3 ] = V_29 -> V_36 [ V_31 ] . V_43 ;
if ( V_29 -> V_44 )
V_29 -> V_44 ( V_2 , V_3 ) ;
if ( V_38 )
F_7 ( L_3 ,
V_29 -> V_39 , div , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
return ( div * V_29 -> V_36 [ V_31 ] . V_41 ) - V_29 -> V_40 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_24 == NULL )
return - V_34 ;
if ( V_10 -> V_30 -> V_45 ) {
struct V_14 V_15 = { . V_18 = 0 ,
. V_16 = V_10 -> V_17 ,
. V_3 = V_10 -> V_30 -> V_45 + 1 ,
. V_19 = V_10 -> V_30 -> V_45 [ 0 ] } ;
int V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
if ( ( V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ) != 1 ) {
return V_20 ;
}
return 0 ;
}
return - V_34 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_5 ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_3 [ 4 ] ;
struct V_14 V_15 =
{ . V_16 = V_10 -> V_17 , . V_18 = 0 ,
. V_3 = V_3 , . V_19 = sizeof( V_3 ) } ;
int V_20 ;
T_2 V_27 = 0 ;
if ( V_10 -> V_24 == NULL )
return - V_34 ;
V_20 = F_9 ( V_2 , V_3 , V_8 -> V_27 ) ;
if ( V_20 < 0 )
return V_20 ;
else
V_27 = V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
if ( ( V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ) != 1 ) {
return V_20 ;
}
V_10 -> V_27 = V_27 ;
V_10 -> V_46 = V_8 -> V_6 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_47 )
{
struct V_7 * V_8 = & V_2 -> V_5 ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_20 ;
T_2 V_27 = 0 ;
if ( V_47 < 5 )
return - V_34 ;
V_20 = F_9 ( V_2 , V_3 + 1 , V_8 -> V_27 ) ;
if ( V_20 < 0 )
return V_20 ;
else
V_27 = V_20 ;
V_3 [ 0 ] = V_10 -> V_17 ;
V_10 -> V_27 = V_27 ;
V_10 -> V_46 = V_8 -> V_6 ;
return 5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_27 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_27 = V_10 -> V_27 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_46 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_46 = V_10 -> V_46 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_24 == NULL )
return - V_34 ;
if ( V_10 -> V_30 -> V_48 ) {
struct V_14 V_15 = { . V_18 = 0 ,
. V_16 = V_10 -> V_17 ,
. V_3 = V_10 -> V_30 -> V_48 + 1 ,
. V_19 = V_10 -> V_30 -> V_48 [ 0 ] } ;
int V_20 ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
return V_20 ;
if ( V_10 -> V_30 -> V_49 ) {
V_15 . V_3 = V_10 -> V_30 -> V_49 + 1 ;
V_15 . V_19 = V_10 -> V_30 -> V_49 [ 0 ] ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_20 = F_6 ( V_10 -> V_24 , & V_15 , 1 ) ;
if ( V_20 != 1 )
return V_20 ;
}
return 0 ;
}
return - V_34 ;
}
struct V_1 * F_18 ( struct V_1 * V_2 , int V_50 ,
struct V_51 * V_24 ,
unsigned int V_52 )
{
T_1 V_53 [] = { 0 } ;
struct V_14 V_15 = { . V_16 = V_50 , . V_18 = V_54 ,
. V_3 = V_53 , . V_19 = 1 } ;
struct V_9 * V_10 = NULL ;
int V_55 ;
struct V_28 * V_29 ;
if ( ( V_56 [ V_57 ] > V_58 ) &&
( V_56 [ V_57 ] < F_19 ( V_59 ) ) )
V_52 = V_56 [ V_57 ] ;
F_20 ( V_52 < 1 || V_52 >= F_19 ( V_59 ) ) ;
V_29 = V_59 [ V_52 ] ;
if ( V_24 != NULL ) {
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 1 ) ;
V_55 = F_6 ( V_24 , & V_15 , 1 ) ;
if ( V_55 != 1 )
return NULL ;
if ( V_2 -> V_22 . V_23 )
V_2 -> V_22 . V_23 ( V_2 , 0 ) ;
}
V_10 = F_21 ( sizeof( struct V_9 ) , V_60 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_17 = V_50 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_30 = V_29 ;
V_10 -> V_61 = V_57 ++ ;
memcpy ( & V_2 -> V_22 . V_62 , & V_63 ,
sizeof( struct V_64 ) ) ;
strncpy ( V_2 -> V_22 . V_62 . V_65 . V_39 , V_29 -> V_39 ,
sizeof( V_2 -> V_22 . V_62 . V_65 . V_39 ) ) ;
V_2 -> V_22 . V_62 . V_65 . V_66 = V_29 -> V_32 ;
V_2 -> V_22 . V_62 . V_65 . V_67 = V_29 -> V_33 ;
if ( ! V_29 -> V_48 )
V_2 -> V_22 . V_62 . V_68 = NULL ;
if ( ! V_29 -> V_45 )
V_2 -> V_22 . V_62 . V_69 = NULL ;
V_2 -> V_11 = V_10 ;
if ( ( V_38 ) || ( V_56 [ V_10 -> V_61 ] == V_52 ) ) {
F_7 ( L_4 , V_10 -> V_61 ) ;
if ( V_24 != NULL )
F_7 ( L_5 , F_22 ( V_24 ) , V_50 ) ;
F_7 ( L_6 , V_52 , V_29 -> V_39 ,
V_56 [ V_10 -> V_61 ] == V_52 ?
L_7 : L_8 ) ;
}
return V_2 ;
}
