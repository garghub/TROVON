static inline T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
static const T_2 V_4 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_5 [] = { 16 , 8 , 0 , 24 } ;
if ( F_2 ( V_2 ) -> V_6 == 0xaf )
return V_4 [ V_3 ] ;
return V_5 [ V_3 ] ;
}
int
F_3 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_9 ,
T_3 type , T_3 V_10 , T_1 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_2 ) ;
struct V_16 V_17 ;
T_2 V_18 , V_19 , V_20 , V_21 ;
T_3 V_22 ;
V_22 = F_4 ( V_15 , type , V_10 , & V_18 , & V_19 , & V_20 , & V_21 , & V_17 ) ;
if ( V_22 ) {
struct V_23 V_24 = {
. V_25 = F_5 ( V_2 ) ,
. V_15 = V_15 ,
. V_22 = V_13 ,
. V_26 = V_9 ,
. V_27 = 1 ,
} ;
if ( V_11 & V_28 )
V_24 . V_29 = V_17 . V_30 [ 2 ] ;
else
V_24 . V_29 = V_17 . V_30 [ 3 ] ;
F_6 ( & V_24 ) ;
V_24 . V_29 = V_17 . V_30 [ 0 ] ;
F_6 ( & V_24 ) ;
}
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_9 ,
T_3 type , T_3 V_10 , T_1 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_2 ) ;
struct V_16 V_17 ;
T_2 V_18 , V_19 , V_20 , V_21 ;
T_3 V_22 ;
V_22 = F_4 ( V_15 , type , V_10 , & V_18 , & V_19 , & V_20 , & V_21 , & V_17 ) ;
if ( V_22 ) {
struct V_23 V_24 = {
. V_25 = F_5 ( V_2 ) ,
. V_15 = V_15 ,
. V_29 = V_17 . V_30 [ 1 ] ,
. V_22 = V_13 ,
. V_26 = V_9 ,
. V_27 = 1 ,
} ;
F_6 ( & V_24 ) ;
}
return 0 ;
}
int
F_8 ( struct V_1 * V_2 , int V_7 , int V_8 ,
T_3 type , T_3 V_10 , T_1 V_11 , struct V_12 * V_17 )
{
const T_1 V_31 = ( V_7 * 0x800 ) + ( V_8 * 0x80 ) ;
const T_1 V_32 = ( V_11 & V_33 ) ;
F_9 ( V_2 , 0x61c10c + V_31 , 0x0f000000 , V_32 << 24 ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_9 ,
T_3 type , T_3 V_10 , T_1 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_2 ) ;
const T_1 V_31 = ( V_7 * 0x800 ) + ( V_8 * 0x80 ) ;
const T_1 V_34 = ( V_7 * 0x800 ) ;
T_3 V_35 = ( V_11 & V_36 ) >> 8 ;
T_2 V_37 = ( V_11 & V_38 ) ;
T_1 V_39 = 0x00000000 ;
T_1 V_40 = 0x00000000 ;
T_1 V_22 , V_3 = 0 ;
T_2 V_18 , V_19 , V_20 , V_21 ;
struct V_16 V_17 ;
int V_41 ;
V_35 *= 2700 ;
V_22 = F_4 ( V_15 , type , V_10 , & V_18 , & V_19 , & V_20 , & V_21 , & V_17 ) ;
if ( V_22 && V_17 . V_42 ) {
struct V_23 V_24 = {
. V_25 = F_5 ( V_2 ) ,
. V_15 = V_15 ,
. V_29 = 0x0000 ,
. V_22 = V_13 ,
. V_26 = V_9 ,
. V_27 = 1 ,
} ;
while ( V_35 < F_11 ( V_15 , V_17 . V_42 ) )
V_17 . V_42 += 4 ;
V_24 . V_29 = F_11 ( V_15 , V_17 . V_42 + 2 ) ;
F_6 ( & V_24 ) ;
}
V_39 |= ( ( 1 << V_37 ) - 1 ) << 16 ;
if ( V_11 & V_43 )
V_39 |= 0x00004000 ;
if ( V_35 > 16200 )
V_40 |= 0x00040000 ;
for ( V_41 = 0 ; V_41 < V_37 ; V_41 ++ )
V_3 |= 1 << ( F_1 ( V_2 , V_41 ) >> 3 ) ;
F_9 ( V_2 , 0x614300 + V_34 , 0x000c0000 , V_40 ) ;
F_9 ( V_2 , 0x61c10c + V_31 , 0x001f4000 , V_39 ) ;
F_9 ( V_2 , 0x61c130 + V_31 , 0x0000000f , V_3 ) ;
return 0 ;
}
int
F_12 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_3 ,
T_3 type , T_3 V_10 , T_1 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_2 ) ;
const T_1 V_31 = ( V_7 * 0x800 ) + ( V_8 * 0x80 ) ;
const T_2 V_44 = ( V_11 & V_45 ) >> 8 ;
const T_2 V_46 = ( V_11 & V_47 ) ;
T_1 V_48 , V_49 = F_1 ( V_2 , V_3 ) ;
T_2 V_18 , V_19 , V_20 , V_21 ;
struct V_16 V_22 ;
struct V_50 V_51 ;
V_48 = F_4 ( V_15 , type , V_10 , & V_18 , & V_19 , & V_20 , & V_21 , & V_22 ) ;
if ( ! V_48 )
return - V_52 ;
V_48 = F_13 ( V_15 , V_48 , 0 , V_44 , V_46 , & V_18 , & V_19 , & V_20 , & V_21 , & V_51 ) ;
if ( ! V_48 )
return - V_53 ;
F_9 ( V_2 , 0x61c118 + V_31 , 0x000000ff << V_49 , V_51 . V_54 << V_49 ) ;
F_9 ( V_2 , 0x61c120 + V_31 , 0x000000ff << V_49 , V_51 . V_55 << V_49 ) ;
F_9 ( V_2 , 0x61c130 + V_31 , 0x0000ff00 , V_51 . V_56 << 8 ) ;
return 0 ;
}
