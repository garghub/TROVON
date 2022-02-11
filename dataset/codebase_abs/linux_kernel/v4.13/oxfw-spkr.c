static int F_1 ( struct V_1 * V_2 , T_1 V_3 , bool * V_4 ,
enum V_5 V_6 )
{
T_1 * V_7 ;
T_1 V_8 ;
int V_9 ;
V_7 = F_2 ( 11 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_6 == V_12 ) {
V_7 [ 0 ] = 0x01 ;
V_8 = 0x0c ;
} else {
V_7 [ 0 ] = 0x00 ;
V_8 = 0x09 ;
}
V_7 [ 1 ] = 0x08 ;
V_7 [ 2 ] = 0xb8 ;
V_7 [ 3 ] = 0x81 ;
V_7 [ 4 ] = V_3 ;
V_7 [ 5 ] = 0x10 ;
V_7 [ 6 ] = 0x02 ;
V_7 [ 7 ] = 0x00 ;
V_7 [ 8 ] = 0x01 ;
V_7 [ 9 ] = 0x01 ;
if ( V_6 == V_12 )
V_7 [ 10 ] = 0xff ;
else
V_7 [ 10 ] = * V_4 ? 0x70 : 0x60 ;
V_9 = F_3 ( V_2 , V_7 , 11 , V_7 , 11 , 0x3fe ) ;
if ( V_9 < 0 )
goto error;
if ( V_9 < 11 ) {
F_4 ( & V_2 -> V_13 , L_1 ) ;
V_9 = - V_14 ;
goto error;
}
if ( V_7 [ 0 ] != V_8 ) {
F_4 ( & V_2 -> V_13 , L_2 ) ;
V_9 = - V_14 ;
goto error;
}
if ( V_6 == V_12 )
* V_4 = V_7 [ 10 ] == 0x70 ;
V_9 = 0 ;
error:
F_5 ( V_7 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
unsigned int V_15 ,
enum V_16 V_17 ,
enum V_5 V_6 )
{
T_1 * V_7 ;
T_1 V_8 ;
int V_9 ;
V_7 = F_2 ( 12 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_6 == V_12 ) {
V_7 [ 0 ] = 0x01 ;
V_8 = 0x0c ;
} else {
V_7 [ 0 ] = 0x00 ;
V_8 = 0x09 ;
}
V_7 [ 1 ] = 0x08 ;
V_7 [ 2 ] = 0xb8 ;
V_7 [ 3 ] = 0x81 ;
V_7 [ 4 ] = V_3 ;
V_7 [ 5 ] = V_17 ;
V_7 [ 6 ] = 0x02 ;
V_7 [ 7 ] = V_15 ;
V_7 [ 8 ] = 0x02 ;
V_7 [ 9 ] = 0x02 ;
if ( V_6 == V_12 ) {
V_7 [ 10 ] = 0xff ;
V_7 [ 11 ] = 0xff ;
} else {
V_7 [ 10 ] = * V_4 >> 8 ;
V_7 [ 11 ] = * V_4 ;
}
V_9 = F_3 ( V_2 , V_7 , 12 , V_7 , 12 , 0x3fe ) ;
if ( V_9 < 0 )
goto error;
if ( V_9 < 12 ) {
F_4 ( & V_2 -> V_13 , L_1 ) ;
V_9 = - V_14 ;
goto error;
}
if ( V_7 [ 0 ] != V_8 ) {
F_4 ( & V_2 -> V_13 , L_3 ) ;
V_9 = - V_14 ;
goto error;
}
if ( V_6 == V_12 )
* V_4 = ( V_7 [ 10 ] << 8 ) | V_7 [ 11 ] ;
V_9 = 0 ;
error:
F_5 ( V_7 ) ;
return V_9 ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_4 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
V_4 -> V_4 . integer . V_4 [ 0 ] = ! V_25 -> V_27 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_4 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
bool V_27 ;
int V_9 ;
V_27 = ! V_4 -> V_4 . integer . V_4 [ 0 ] ;
if ( V_27 == V_25 -> V_27 )
return 0 ;
V_9 = F_1 ( V_22 -> V_2 , V_25 -> V_28 , & V_27 ,
V_29 ) ;
if ( V_9 < 0 )
return V_9 ;
V_25 -> V_27 = V_27 ;
return 1 ;
}
static int F_9 ( struct V_18 * V_19 ,
struct V_30 * V_31 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
V_31 -> type = V_32 ;
V_31 -> V_33 = V_25 -> V_34 ;
V_31 -> V_4 . integer . V_35 = V_25 -> V_36 ;
V_31 -> V_4 . integer . V_37 = V_25 -> V_38 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_4 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_25 -> V_34 ; ++ V_39 )
V_4 -> V_4 . integer . V_4 [ V_40 [ V_39 ] ] = V_25 -> V_41 [ V_39 ] ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_20 * V_4 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_39 , V_42 ;
bool V_43 = true ;
T_2 V_41 ;
int V_9 ;
for ( V_39 = 0 ; V_39 < V_25 -> V_34 ; ++ V_39 ) {
if ( V_4 -> V_4 . integer . V_4 [ V_39 ] < V_25 -> V_36 ||
V_4 -> V_4 . integer . V_4 [ V_39 ] > V_25 -> V_38 )
return - V_44 ;
if ( V_4 -> V_4 . integer . V_4 [ V_39 ] !=
V_4 -> V_4 . integer . V_4 [ 0 ] )
V_43 = false ;
}
V_42 = 0 ;
for ( V_39 = 0 ; V_39 < V_25 -> V_34 ; ++ V_39 )
if ( V_4 -> V_4 . integer . V_4 [ V_40 [ V_39 ] ] !=
V_25 -> V_41 [ V_39 ] )
V_42 |= 1 << ( V_39 + 1 ) ;
if ( V_43 && V_42 != 0 )
V_42 = 1 << 0 ;
for ( V_39 = 0 ; V_39 <= V_25 -> V_34 ; ++ V_39 ) {
V_41 = V_4 -> V_4 . integer . V_4 [ V_40 [ V_39 ? V_39 - 1 : 0 ] ] ;
if ( V_42 & ( 1 << V_39 ) ) {
V_9 = F_6 ( V_22 -> V_2 ,
V_25 -> V_45 , & V_41 ,
V_39 , V_46 , V_29 ) ;
if ( V_9 < 0 )
return V_9 ;
}
if ( V_39 > 0 )
V_25 -> V_41 [ V_39 - 1 ] = V_41 ;
}
return V_42 != 0 ;
}
int F_12 ( struct V_21 * V_22 , bool V_47 )
{
static const struct V_48 V_49 [] = {
{
. V_50 = V_51 ,
. V_52 = L_4 ,
. V_31 = V_53 ,
. V_54 = F_7 ,
. V_55 = F_8 ,
} ,
{
. V_50 = V_51 ,
. V_52 = L_5 ,
. V_31 = F_9 ,
. V_54 = F_10 ,
. V_55 = F_11 ,
} ,
} ;
struct V_24 * V_25 ;
unsigned int V_39 , V_56 ;
int V_9 ;
V_25 = F_13 ( sizeof( struct V_24 ) , V_10 ) ;
if ( V_25 == NULL )
return - V_11 ;
V_22 -> V_26 = V_25 ;
if ( V_47 ) {
V_25 -> V_34 = 1 ;
V_25 -> V_28 = 0x01 ;
V_25 -> V_45 = 0x01 ;
} else {
V_25 -> V_34 = 6 ;
V_25 -> V_28 = 0x01 ;
V_25 -> V_45 = 0x02 ;
}
V_9 = F_6 ( V_22 -> V_2 , V_25 -> V_45 ,
& V_25 -> V_36 , 0 , V_57 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_22 -> V_2 , V_25 -> V_45 ,
& V_25 -> V_38 , 0 , V_58 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_1 ( V_22 -> V_2 , V_25 -> V_28 , & V_25 -> V_27 ,
V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_56 = V_25 -> V_34 == 1 ? 0 : 1 ;
for ( V_39 = 0 ; V_39 < V_25 -> V_34 ; ++ V_39 ) {
V_9 = F_6 ( V_22 -> V_2 , V_25 -> V_45 ,
& V_25 -> V_41 [ V_39 ] , V_56 + V_39 ,
V_46 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
}
for ( V_39 = 0 ; V_39 < F_14 ( V_49 ) ; ++ V_39 ) {
V_9 = F_15 ( V_22 -> V_59 ,
F_16 ( & V_49 [ V_39 ] , V_22 ) ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
