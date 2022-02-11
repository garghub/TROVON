static int F_1 ( struct V_1 * V_2 , bool * V_3 ,
enum V_4 V_5 )
{
T_1 * V_6 ;
T_1 V_7 ;
int V_8 ;
V_6 = F_2 ( 11 , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
if ( V_5 == V_11 ) {
V_6 [ 0 ] = 0x01 ;
V_7 = 0x0c ;
} else {
V_6 [ 0 ] = 0x00 ;
V_7 = 0x09 ;
}
V_6 [ 1 ] = 0x08 ;
V_6 [ 2 ] = 0xb8 ;
V_6 [ 3 ] = 0x81 ;
V_6 [ 4 ] = V_2 -> V_12 -> V_13 ;
V_6 [ 5 ] = 0x10 ;
V_6 [ 6 ] = 0x02 ;
V_6 [ 7 ] = 0x00 ;
V_6 [ 8 ] = 0x01 ;
V_6 [ 9 ] = 0x01 ;
if ( V_5 == V_11 )
V_6 [ 10 ] = 0xff ;
else
V_6 [ 10 ] = * V_3 ? 0x70 : 0x60 ;
V_8 = F_3 ( V_2 -> V_14 , V_6 , 11 , V_6 , 11 , 0x3fe ) ;
if ( V_8 < 0 )
goto error;
if ( V_8 < 11 ) {
F_4 ( & V_2 -> V_14 -> V_15 , L_1 ) ;
V_8 = - V_16 ;
goto error;
}
if ( V_6 [ 0 ] != V_7 ) {
F_4 ( & V_2 -> V_14 -> V_15 , L_2 ) ;
V_8 = - V_16 ;
goto error;
}
if ( V_5 == V_11 )
* V_3 = V_6 [ 10 ] == 0x70 ;
V_8 = 0 ;
error:
F_5 ( V_6 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned int V_17 ,
enum V_18 V_19 ,
enum V_4 V_5 )
{
T_1 * V_6 ;
T_1 V_7 ;
int V_8 ;
V_6 = F_2 ( 12 , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
if ( V_5 == V_11 ) {
V_6 [ 0 ] = 0x01 ;
V_7 = 0x0c ;
} else {
V_6 [ 0 ] = 0x00 ;
V_7 = 0x09 ;
}
V_6 [ 1 ] = 0x08 ;
V_6 [ 2 ] = 0xb8 ;
V_6 [ 3 ] = 0x81 ;
V_6 [ 4 ] = V_2 -> V_12 -> V_20 ;
V_6 [ 5 ] = V_19 ;
V_6 [ 6 ] = 0x02 ;
V_6 [ 7 ] = V_17 ;
V_6 [ 8 ] = 0x02 ;
V_6 [ 9 ] = 0x02 ;
if ( V_5 == V_11 ) {
V_6 [ 10 ] = 0xff ;
V_6 [ 11 ] = 0xff ;
} else {
V_6 [ 10 ] = * V_3 >> 8 ;
V_6 [ 11 ] = * V_3 ;
}
V_8 = F_3 ( V_2 -> V_14 , V_6 , 12 , V_6 , 12 , 0x3fe ) ;
if ( V_8 < 0 )
goto error;
if ( V_8 < 12 ) {
F_4 ( & V_2 -> V_14 -> V_15 , L_1 ) ;
V_8 = - V_16 ;
goto error;
}
if ( V_6 [ 0 ] != V_7 ) {
F_4 ( & V_2 -> V_14 -> V_15 , L_3 ) ;
V_8 = - V_16 ;
goto error;
}
if ( V_5 == V_11 )
* V_3 = ( V_6 [ 10 ] << 8 ) | V_6 [ 11 ] ;
V_8 = 0 ;
error:
F_5 ( V_6 ) ;
return V_8 ;
}
static int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_3 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
V_3 -> V_3 . integer . V_3 [ 0 ] = ! V_2 -> V_25 ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 ,
struct V_23 * V_3 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
bool V_25 ;
int V_8 ;
V_25 = ! V_3 -> V_3 . integer . V_3 [ 0 ] ;
if ( V_25 == V_2 -> V_25 )
return 0 ;
V_8 = F_1 ( V_2 , & V_25 , V_26 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_25 = V_25 ;
return 1 ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
V_28 -> type = V_29 ;
V_28 -> V_30 = V_2 -> V_12 -> V_31 ;
V_28 -> V_3 . integer . V_32 = V_2 -> V_33 ;
V_28 -> V_3 . integer . V_34 = V_2 -> V_35 ;
return 0 ;
}
static int F_10 ( struct V_21 * V_22 ,
struct V_23 * V_3 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_12 -> V_31 ; ++ V_36 )
V_3 -> V_3 . integer . V_3 [ V_37 [ V_36 ] ] = V_2 -> V_38 [ V_36 ] ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 ,
struct V_23 * V_3 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
unsigned int V_36 , V_39 ;
bool V_40 = true ;
T_2 V_38 ;
int V_8 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_12 -> V_31 ; ++ V_36 ) {
if ( V_3 -> V_3 . integer . V_3 [ V_36 ] < V_2 -> V_33 ||
V_3 -> V_3 . integer . V_3 [ V_36 ] > V_2 -> V_35 )
return - V_41 ;
if ( V_3 -> V_3 . integer . V_3 [ V_36 ] !=
V_3 -> V_3 . integer . V_3 [ 0 ] )
V_40 = false ;
}
V_39 = 0 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_12 -> V_31 ; ++ V_36 )
if ( V_3 -> V_3 . integer . V_3 [ V_37 [ V_36 ] ] !=
V_2 -> V_38 [ V_36 ] )
V_39 |= 1 << ( V_36 + 1 ) ;
if ( V_40 && V_39 != 0 )
V_39 = 1 << 0 ;
for ( V_36 = 0 ; V_36 <= V_2 -> V_12 -> V_31 ; ++ V_36 ) {
V_38 = V_3 -> V_3 . integer . V_3 [ V_37 [ V_36 ? V_36 - 1 : 0 ] ] ;
if ( V_39 & ( 1 << V_36 ) ) {
V_8 = F_6 ( V_2 , & V_38 , V_36 ,
V_42 , V_26 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_36 > 0 )
V_2 -> V_38 [ V_36 - 1 ] = V_38 ;
}
return V_39 != 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
static const struct V_43 V_44 [] = {
{
. V_45 = V_46 ,
. V_47 = L_4 ,
. V_28 = V_48 ,
. V_49 = F_7 ,
. V_50 = F_8 ,
} ,
{
. V_45 = V_46 ,
. V_47 = L_5 ,
. V_28 = F_9 ,
. V_49 = F_10 ,
. V_50 = F_11 ,
} ,
} ;
unsigned int V_36 , V_51 ;
int V_8 ;
V_8 = F_6 ( V_2 , & V_2 -> V_33 ,
0 , V_52 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , & V_2 -> V_35 ,
0 , V_53 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , & V_2 -> V_25 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_51 = V_2 -> V_12 -> V_31 == 1 ? 0 : 1 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_12 -> V_31 ; ++ V_36 ) {
V_8 = F_6 ( V_2 , & V_2 -> V_38 [ V_36 ] ,
V_51 + V_36 , V_42 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_36 = 0 ; V_36 < F_13 ( V_44 ) ; ++ V_36 ) {
V_8 = F_14 ( V_2 -> V_54 ,
F_15 ( & V_44 [ V_36 ] , V_2 ) ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
