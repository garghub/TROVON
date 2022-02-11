static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_5 -> V_9 == NULL || F_2 ( V_5 , & V_7 -> V_10 ) < 0 )
return - V_11 ;
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ( V_7 -> V_12 [ 0 ] | V_7 -> V_12 [ 1 ] ) & ( 0xF8 << V_13 ) )
return V_14 ;
else
return V_15 ;
}
static unsigned long F_5 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct F_2 V_18 ;
unsigned int V_19 ;
V_18 = V_7 -> V_10 ;
F_2 ( V_5 , & V_18 ) ;
V_19 = F_6 ( V_17 , & V_18 ) ;
if ( V_19 & ( 0xF8 << V_13 ) )
V_5 -> V_20 = V_14 ;
return V_19 ;
}
static unsigned long F_7 ( struct V_16 * V_17 , unsigned long V_12 )
{
struct V_6 * V_7 = V_17 -> V_2 -> V_5 -> V_8 ;
return V_12 & V_7 -> V_12 [ V_17 -> V_21 ] ;
}
static void F_8 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
int V_22 = V_17 -> V_21 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_23 * V_24 ;
if ( ! ( V_7 -> V_10 . V_25 & 0x10 ) )
V_22 = 0 ;
V_24 = F_9 ( V_17 -> V_26 ) ;
V_7 -> V_10 . V_27 [ V_22 ] . V_28 = V_24 -> V_29 ;
F_10 ( V_5 , & V_7 -> V_10 ) ;
F_2 ( V_5 , & V_7 -> V_10 ) ;
}
static void F_11 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
int V_22 = V_17 -> V_21 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_23 * V_24 ;
if ( ! ( V_7 -> V_10 . V_25 & 0x10 ) )
V_22 = 0 ;
V_24 = F_9 ( V_17 -> V_30 ) ;
if ( V_17 -> V_30 >= V_31 ) {
V_7 -> V_10 . V_27 [ V_22 ] . V_32 = V_24 -> V_33 ;
V_7 -> V_10 . V_25 |= ( 1 << ( 2 * V_22 ) ) ;
} else {
V_7 -> V_10 . V_27 [ V_22 ] . V_32 = V_24 -> V_29 ;
V_7 -> V_10 . V_25 &= ~ ( 1 << ( 2 * V_22 ) ) ;
}
F_10 ( V_5 , & V_7 -> V_10 ) ;
F_2 ( V_5 , & V_7 -> V_10 ) ;
}
static unsigned int F_12 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
struct V_16 * V_17 = V_35 -> V_36 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_10 . V_25 & 0x10 )
return F_13 ( V_35 ) ;
if ( V_17 != V_7 -> V_37 ) {
F_8 ( V_5 , V_17 ) ;
if ( F_14 ( V_17 ) )
F_11 ( V_5 , V_17 ) ;
V_7 -> V_37 = V_17 ;
}
return F_13 ( V_35 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_38 * V_39 = F_16 ( V_5 -> V_40 -> V_36 ) ;
struct V_6 * V_7 ;
int V_41 ;
if ( V_5 -> V_9 == NULL )
return - V_11 ;
V_7 = V_5 -> V_8 = F_17 ( & V_39 -> V_36 , sizeof( struct V_6 ) , V_42 ) ;
if ( V_5 -> V_8 == NULL )
return - V_43 ;
V_7 -> V_12 [ 0 ] = F_5 ( V_5 , & V_5 -> V_2 . V_44 [ 0 ] ) ;
V_7 -> V_12 [ 1 ] = F_5 ( V_5 , & V_5 -> V_2 . V_44 [ 1 ] ) ;
V_41 = F_18 ( V_5 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_41 ;
}
static int F_19 ( struct V_38 * V_39 , const struct V_45 * V_46 )
{
static const struct V_47 V_48 = {
. V_25 = V_49 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_55 ,
. V_56 = & V_57 ,
} ;
const struct V_47 * V_58 [] = { & V_48 , NULL } ;
if ( V_39 -> V_59 == V_60 ) {
int V_61 = F_20 ( V_39 ) ;
if ( V_61 < 0 )
return V_61 ;
F_21 ( V_39 ) ;
}
return F_22 ( V_39 , V_58 , & V_62 , NULL , 0 ) ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_63 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_63 ) ;
}
