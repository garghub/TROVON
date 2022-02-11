static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 -> V_9 ) ;
int V_10 = V_4 -> V_11 ;
V_5 -= V_12 ;
F_3 ( V_7 , 0x62 + V_2 -> V_13 ,
( V_14 [ V_5 ] . V_15 << 4 ) |
( V_14 [ V_5 ] . assert ) ) ;
F_3 ( V_7 , 0x64 + 4 * V_2 -> V_13 + V_10 ,
( V_14 [ V_5 ] . V_15 << 4 ) |
( V_14 [ V_5 ] . assert ) ) ;
F_3 ( V_7 , 0x66 + 4 * V_2 -> V_13 + V_10 ,
( V_14 [ V_5 ] . V_15 << 4 ) |
( V_14 [ V_5 ] . assert ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , V_4 -> V_16 ) ;
}
static int F_5 ( struct V_6 * V_7 , const struct V_17 * V_18 )
{
static const unsigned int V_19 [] = { 0x1F0 , 0x170 } ;
static const unsigned int V_20 [] = { 0x3F6 , 0x376 } ;
struct V_21 V_22 = {
. V_23 = V_24 ,
. V_25 = V_26 ,
. V_27 = & V_28 ,
} ;
const struct V_21 * V_29 [ 2 ] ;
T_1 V_30 ;
void T_2 * V_31 [ 5 ] ;
struct V_32 * V_8 ;
struct V_33 * V_34 ;
int V_35 , V_36 ;
V_36 = F_6 ( V_7 ) ;
if ( V_36 )
return V_36 ;
F_7 ( V_7 , 0x60 , & V_30 ) ;
if ( ( V_30 & 3 ) == 0 )
return - V_37 ;
V_29 [ 0 ] = V_29 [ 1 ] = & V_38 ;
if ( V_30 & 1 )
V_29 [ 0 ] = & V_22 ;
if ( V_30 & 2 )
V_29 [ 1 ] = & V_22 ;
if ( ( V_30 & 0x40 ) == 0 ) {
F_8 ( & V_7 -> V_9 , L_1 ) ;
F_3 ( V_7 , 0x60 , V_30 | 0x40 ) ;
}
V_22 . V_39 = V_18 -> V_40 ;
V_8 = F_9 ( & V_7 -> V_9 , V_29 , 2 ) ;
if ( ! V_8 )
return - V_41 ;
if ( F_10 ( V_7 ) ) {
F_11 (KERN_ERR DRV_NAME L_2 ) ;
return - V_37 ;
}
if ( F_12 ( & V_7 -> V_9 , F_13 ( 32 ) ) ) {
F_11 (KERN_ERR DRV_NAME L_3 ) ;
return - V_37 ;
}
if ( F_14 ( & V_7 -> V_9 , F_13 ( 32 ) ) ) {
F_11 (KERN_ERR DRV_NAME L_4 ) ;
return - V_37 ;
}
V_31 [ 0 ] = F_15 ( & V_7 -> V_9 , V_19 [ 0 ] , 8 ) ;
V_31 [ 1 ] = F_15 ( & V_7 -> V_9 , V_20 [ 0 ] , 1 ) ;
V_31 [ 2 ] = F_15 ( & V_7 -> V_9 , V_19 [ 1 ] , 8 ) ;
V_31 [ 3 ] = F_15 ( & V_7 -> V_9 , V_20 [ 1 ] , 1 ) ;
V_31 [ 4 ] = F_16 ( V_7 , 2 , 0 ) ;
if ( ! V_31 [ 0 ] || ! V_31 [ 1 ] || ! V_31 [ 2 ] || ! V_31 [ 3 ] || ! V_31 [ 4 ] )
return - V_41 ;
V_34 = & V_8 -> V_42 [ 0 ] -> V_34 ;
V_34 -> V_43 = V_31 [ 0 ] ;
V_34 -> V_44 = V_31 [ 1 ] ;
V_34 -> V_45 = V_31 [ 1 ] ;
V_34 -> V_46 = V_31 [ 4 ] ;
F_17 ( V_34 ) ;
F_18 ( V_8 -> V_42 [ 0 ] ,
L_5 , V_19 [ 0 ] , V_20 [ 0 ] ) ;
F_19 ( V_8 -> V_42 [ 0 ] , 4 , 0 , L_6 ) ;
V_34 = & V_8 -> V_42 [ 1 ] -> V_34 ;
V_34 -> V_43 = V_31 [ 2 ] ;
V_34 -> V_44 = V_31 [ 3 ] ;
V_34 -> V_45 = V_31 [ 3 ] ;
V_34 -> V_46 = V_31 [ 4 ] + 8 ;
F_17 ( V_34 ) ;
F_18 ( V_8 -> V_42 [ 1 ] ,
L_5 , V_19 [ 1 ] , V_20 [ 1 ] ) ;
F_19 ( V_8 -> V_42 [ 1 ] , 4 , 8 , L_6 ) ;
F_20 ( V_7 ) ;
V_36 = F_21 ( V_8 ) ;
if ( V_36 )
return V_36 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
static const int V_47 [] = { 14 , 15 } ;
struct V_1 * V_2 = V_8 -> V_42 [ V_35 ] ;
if ( F_22 ( V_2 ) )
continue;
V_36 = F_23 ( & V_7 -> V_9 , V_47 [ V_2 -> V_13 ] ,
V_48 , 0 , V_49 , V_8 ) ;
if ( V_36 )
return V_36 ;
F_18 ( V_2 , L_7 , V_47 [ V_35 ] ) ;
}
return F_24 ( V_8 , & V_50 ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_32 * V_8 = F_26 ( V_7 ) ;
T_1 V_30 ;
int V_36 ;
V_36 = F_27 ( V_7 ) ;
if ( V_36 )
return V_36 ;
F_7 ( V_7 , 0x60 , & V_30 ) ;
if ( ( V_30 & 0x40 ) == 0 )
F_3 ( V_7 , 0x60 , V_30 | 0x40 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 , T_3 V_51 )
{
struct V_32 * V_8 = F_26 ( V_7 ) ;
int V_36 = 0 ;
V_36 = F_30 ( V_8 , V_51 ) ;
if ( V_36 )
return V_36 ;
F_31 ( V_7 ) ;
return 0 ;
}
