static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_2 ( V_5 ) == NULL || F_3 ( V_5 , & V_7 -> V_9 ) < 0 )
return - V_10 ;
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ( V_7 -> V_11 [ 0 ] | V_7 -> V_11 [ 1 ] ) & ( 0xF8 << V_12 ) )
return V_13 ;
else
return V_14 ;
}
static unsigned long F_6 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct F_3 V_17 ;
unsigned int V_18 ;
V_17 = V_7 -> V_9 ;
F_3 ( V_5 , & V_17 ) ;
V_18 = F_7 ( V_16 , & V_17 ) ;
if ( V_18 & ( 0xF8 << V_12 ) )
V_5 -> V_19 = V_13 ;
return V_18 ;
}
static unsigned long F_8 ( struct V_15 * V_16 , unsigned long V_11 )
{
struct V_6 * V_7 = V_16 -> V_2 -> V_5 -> V_8 ;
return V_11 & V_7 -> V_11 [ V_16 -> V_20 ] ;
}
static void F_9 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_21 = V_16 -> V_20 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_22 * V_23 ;
if ( ! ( V_7 -> V_9 . V_24 & 0x10 ) )
V_21 = 0 ;
V_23 = F_10 ( V_16 -> V_25 ) ;
V_7 -> V_9 . V_26 [ V_21 ] . V_27 = V_23 -> V_28 ;
F_11 ( V_5 , & V_7 -> V_9 ) ;
F_3 ( V_5 , & V_7 -> V_9 ) ;
}
static void F_12 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_21 = V_16 -> V_20 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_22 * V_23 ;
if ( ! ( V_7 -> V_9 . V_24 & 0x10 ) )
V_21 = 0 ;
V_23 = F_10 ( V_16 -> V_29 ) ;
if ( V_16 -> V_29 >= V_30 ) {
V_7 -> V_9 . V_26 [ V_21 ] . V_31 = V_23 -> V_32 ;
V_7 -> V_9 . V_24 |= ( 1 << ( 2 * V_21 ) ) ;
} else {
V_7 -> V_9 . V_26 [ V_21 ] . V_31 = V_23 -> V_28 ;
V_7 -> V_9 . V_24 &= ~ ( 1 << ( 2 * V_21 ) ) ;
}
F_11 ( V_5 , & V_7 -> V_9 ) ;
F_3 ( V_5 , & V_7 -> V_9 ) ;
}
static unsigned int F_13 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_15 * V_16 = V_34 -> V_35 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 . V_24 & 0x10 )
return F_14 ( V_34 ) ;
if ( V_16 != V_7 -> V_36 ) {
F_9 ( V_5 , V_16 ) ;
if ( F_15 ( V_16 ) )
F_12 ( V_5 , V_16 ) ;
V_7 -> V_36 = V_16 ;
}
return F_14 ( V_34 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_37 * V_38 = F_17 ( V_5 -> V_39 -> V_35 ) ;
struct V_6 * V_7 ;
if ( F_2 ( V_5 ) == NULL )
return - V_10 ;
V_7 = V_5 -> V_8 = F_18 ( & V_38 -> V_35 , sizeof( struct V_6 ) , V_40 ) ;
if ( V_5 -> V_8 == NULL )
return - V_41 ;
V_7 -> V_11 [ 0 ] = F_6 ( V_5 , & V_5 -> V_2 . V_42 [ 0 ] ) ;
V_7 -> V_11 [ 1 ] = F_6 ( V_5 , & V_5 -> V_2 . V_42 [ 1 ] ) ;
return F_19 ( V_5 ) ;
}
static int F_20 ( struct V_37 * V_38 , const struct V_43 * V_44 )
{
static const struct V_45 V_46 = {
. V_24 = V_47 ,
. V_48 = V_49 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = & V_55 ,
} ;
const struct V_45 * V_56 [] = { & V_46 , NULL } ;
if ( V_38 -> V_57 == V_58 ) {
int V_59 = F_21 ( V_38 ) ;
if ( V_59 < 0 )
return V_59 ;
F_22 ( V_38 ) ;
}
return F_23 ( V_38 , V_56 , & V_60 , NULL , 0 ) ;
}
