static void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_6 == V_5 -> V_7 . V_8 . V_9 )
V_3 [ 3 ] |= 0x10 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_5 -> V_7 . V_8 . V_9 == V_10 )
V_3 [ 3 ] |= 0x08 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_6 != V_5 -> V_7 . V_8 . V_9 )
V_3 [ 3 ] |= 0x08 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_5 -> V_7 . V_8 . V_9 == V_10 )
V_3 [ 3 ] |= 0x04 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_14 = ( V_5 -> V_7 . V_15 . V_16 * 27 ) / 32000 ;
struct V_17 V_18 = {
. V_19 = V_12 -> V_20 ,
. V_21 = 0 ,
. V_3 = V_3 ,
. V_22 = 4
} ;
int V_23 ;
T_1 V_24 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ;
if ( V_23 != 1 )
F_7 ( V_28 L_1 ,
V_29 , V_23 ) ;
if ( V_14 <= 10000 )
V_24 = 0xc ;
else if ( V_14 <= 12000 )
V_24 = 0x2 ;
else if ( V_14 <= 14000 )
V_24 = 0xa ;
else if ( V_14 <= 16000 )
V_24 = 0x6 ;
else if ( V_14 <= 18000 )
V_24 = 0xe ;
else if ( V_14 <= 20000 )
V_24 = 0x1 ;
else if ( V_14 <= 22000 )
V_24 = 0x9 ;
else if ( V_14 <= 24000 )
V_24 = 0x5 ;
else if ( V_14 <= 26000 )
V_24 = 0xd ;
else if ( V_14 <= 28000 )
V_24 = 0x3 ;
else
V_24 = 0xb ;
V_3 [ 2 ] ^= 0x1c ;
V_3 [ 2 ] |= ( ( V_24 >> 2 ) & 0x3 ) << 3 ;
V_3 [ 3 ] |= ( V_24 & 0x3 ) << 2 ;
return;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_17 V_18 = {
. V_19 = V_12 -> V_20 ,
. V_21 = 0 ,
. V_3 = V_3 ,
. V_22 = 4
} ;
int V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ;
if ( V_23 != 1 )
F_7 ( V_28 L_1 ,
V_29 , V_23 ) ;
V_3 [ 2 ] = 0x9e ;
V_3 [ 3 ] = 0x90 ;
return;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
const struct V_4 * V_5 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_30 * V_31 = V_12 -> V_32 ;
T_2 div ;
int V_33 ;
if ( V_5 -> V_34 != 0 && ( V_5 -> V_34 < V_31 -> V_35 ||
V_5 -> V_34 > V_31 -> V_36 ) )
return - V_37 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_38 ; V_33 ++ ) {
if ( V_5 -> V_34 > V_31 -> V_39 [ V_33 ] . V_40 )
continue;
break;
}
if ( V_41 )
F_7 ( L_2 , V_31 -> V_42 ,
V_5 -> V_34 , V_33 , V_31 -> V_38 ) ;
if ( V_33 == V_31 -> V_38 )
return - V_37 ;
div = ( V_5 -> V_34 + V_31 -> V_43 +
V_31 -> V_39 [ V_33 ] . V_44 / 2 ) / V_31 -> V_39 [ V_33 ] . V_44 ;
V_3 [ 0 ] = div >> 8 ;
V_3 [ 1 ] = div & 0xff ;
V_3 [ 2 ] = V_31 -> V_39 [ V_33 ] . V_45 ;
V_3 [ 3 ] = V_31 -> V_39 [ V_33 ] . V_46 ;
if ( V_31 -> V_47 )
V_31 -> V_47 ( V_2 , V_3 , V_5 ) ;
if ( V_41 )
F_7 ( L_3 ,
V_31 -> V_42 , div , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
return ( div * V_31 -> V_39 [ V_33 ] . V_44 ) - V_31 -> V_43 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 -> V_27 == NULL )
return - V_37 ;
if ( V_12 -> V_32 -> V_48 ) {
struct V_17 V_18 = { . V_21 = 0 ,
. V_19 = V_12 -> V_20 ,
. V_3 = V_12 -> V_32 -> V_48 + 1 ,
. V_22 = V_12 -> V_32 -> V_48 [ 0 ] } ;
int V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
if ( ( V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ) != 1 ) {
return V_23 ;
}
return 0 ;
}
return - V_37 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_3 [ 4 ] ;
struct V_17 V_18 =
{ . V_19 = V_12 -> V_20 , . V_21 = 0 ,
. V_3 = V_3 , . V_22 = sizeof( V_3 ) } ;
int V_23 ;
T_2 V_34 = 0 ;
if ( V_12 -> V_27 == NULL )
return - V_37 ;
if ( ( V_23 = F_9 ( V_2 , V_3 , V_5 ) ) < 0 )
return V_23 ;
else
V_34 = V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
if ( ( V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ) != 1 ) {
return V_23 ;
}
V_12 -> V_34 = V_34 ;
V_12 -> V_9 = ( V_2 -> V_25 . V_49 . type == V_50 ) ? V_5 -> V_7 . V_8 . V_9 : 0 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
T_1 * V_3 , int V_51 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_23 ;
T_2 V_34 = 0 ;
if ( V_51 < 5 )
return - V_37 ;
if ( ( V_23 = F_9 ( V_2 , V_3 + 1 , V_5 ) ) < 0 )
return V_23 ;
else
V_34 = V_23 ;
V_3 [ 0 ] = V_12 -> V_20 ;
V_12 -> V_34 = V_34 ;
V_12 -> V_9 = ( V_2 -> V_25 . V_49 . type == V_50 ) ? V_5 -> V_7 . V_8 . V_9 : 0 ;
return 5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_34 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
* V_34 = V_12 -> V_34 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_9 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
* V_9 = V_12 -> V_9 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 -> V_27 == NULL )
return - V_37 ;
if ( V_12 -> V_32 -> V_52 ) {
struct V_17 V_18 = { . V_21 = 0 ,
. V_19 = V_12 -> V_20 ,
. V_3 = V_12 -> V_32 -> V_52 + 1 ,
. V_22 = V_12 -> V_32 -> V_52 [ 0 ] } ;
int V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ;
if ( V_23 != 1 )
return V_23 ;
if ( V_12 -> V_32 -> V_53 ) {
V_18 . V_3 = V_12 -> V_32 -> V_53 + 1 ;
V_18 . V_22 = V_12 -> V_32 -> V_53 [ 0 ] ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
V_23 = F_6 ( V_12 -> V_27 , & V_18 , 1 ) ;
if ( V_23 != 1 )
return V_23 ;
}
return 0 ;
}
return - V_37 ;
}
struct V_1 * F_18 ( struct V_1 * V_2 , int V_54 ,
struct V_55 * V_27 ,
unsigned int V_56 )
{
T_1 V_57 [] = { 0 } ;
struct V_17 V_18 = { . V_19 = V_54 , . V_21 = V_58 ,
. V_3 = V_57 , . V_22 = 1 } ;
struct V_11 * V_12 = NULL ;
int V_59 ;
struct V_30 * V_31 ;
if ( ( V_60 [ V_61 ] > V_62 ) &&
( V_60 [ V_61 ] < F_19 ( V_63 ) ) )
V_56 = V_60 [ V_61 ] ;
F_20 ( V_56 < 1 || V_56 >= F_19 ( V_63 ) ) ;
V_31 = V_63 [ V_56 ] ;
if ( V_27 != NULL ) {
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 1 ) ;
V_59 = F_6 ( V_27 , & V_18 , 1 ) ;
if ( V_59 != 1 )
return NULL ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 , 0 ) ;
}
V_12 = F_21 ( sizeof( struct V_11 ) , V_64 ) ;
if ( V_12 == NULL )
return NULL ;
V_12 -> V_20 = V_54 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_32 = V_31 ;
V_12 -> V_65 = V_61 ++ ;
memcpy ( & V_2 -> V_25 . V_66 , & V_67 ,
sizeof( struct V_68 ) ) ;
strncpy ( V_2 -> V_25 . V_66 . V_49 . V_42 , V_31 -> V_42 ,
sizeof( V_2 -> V_25 . V_66 . V_49 . V_42 ) ) ;
V_2 -> V_25 . V_66 . V_49 . V_69 = V_31 -> V_35 ;
V_2 -> V_25 . V_66 . V_49 . V_70 = V_31 -> V_36 ;
if ( ! V_31 -> V_52 )
V_2 -> V_25 . V_66 . V_71 = NULL ;
if ( ! V_31 -> V_48 )
V_2 -> V_25 . V_66 . V_72 = NULL ;
V_2 -> V_13 = V_12 ;
if ( ( V_41 ) || ( V_60 [ V_12 -> V_65 ] == V_56 ) ) {
F_7 ( L_4 , V_12 -> V_65 ) ;
if ( V_27 != NULL )
F_7 ( L_5 , F_22 ( V_27 ) , V_54 ) ;
F_7 ( L_6 , V_56 , V_31 -> V_42 ,
V_60 [ V_12 -> V_65 ] == V_56 ?
L_7 : L_8 ) ;
}
return V_2 ;
}
