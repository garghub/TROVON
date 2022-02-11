static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
const T_1 V_5 [ 4 ] = { 0xe104 , 0xe108 , 0xe280 , 0xe284 } ;
if ( V_2 -> line >= 32 )
return - V_6 ;
* V_3 = V_5 [ V_2 -> line >> 3 ] ;
* V_4 = ( V_2 -> line & 7 ) << 2 ;
return 0 ;
}
int
F_2 ( struct V_7 * V_8 , enum V_9 V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 , V_12 , V_13 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return - V_14 ;
if ( F_1 ( V_2 , & V_11 , & V_12 ) )
return - V_6 ;
V_13 = F_4 ( V_8 , V_11 ) >> ( V_12 + 2 ) ;
return ( ( V_13 & 1 ) == ( V_2 -> V_15 [ 1 ] & 1 ) ) ;
}
int
F_5 ( struct V_7 * V_8 , enum V_9 V_10 , int V_15 )
{
struct V_1 * V_2 ;
T_1 V_11 , V_12 , V_13 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return - V_14 ;
if ( F_1 ( V_2 , & V_11 , & V_12 ) )
return - V_6 ;
V_13 = F_4 ( V_8 , V_11 ) & ~ ( 0x3 << V_12 ) ;
V_13 |= ( V_2 -> V_15 [ V_15 ] ^ 2 ) << V_12 ;
F_6 ( V_8 , V_11 , V_13 ) ;
return 0 ;
}
int
F_7 ( struct V_7 * V_8 , enum V_9 V_10 )
{
struct V_1 * V_2 ;
T_2 V_13 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return - V_14 ;
V_13 = F_4 ( V_8 , 0x00d610 + ( V_2 -> line * 4 ) ) ;
V_13 &= 0x00004000 ;
return ( ! ! V_13 == ( V_2 -> V_15 [ 1 ] & 1 ) ) ;
}
int
F_8 ( struct V_7 * V_8 , enum V_9 V_10 , int V_15 )
{
struct V_1 * V_2 ;
T_2 V_13 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return - V_14 ;
V_13 = V_2 -> V_15 [ V_15 ] ^ 2 ;
F_9 ( V_8 , 0x00d610 + ( V_2 -> line * 4 ) , 0x00003000 , V_13 << 12 ) ;
return 0 ;
}
int
F_10 ( struct V_7 * V_8 , enum V_9 V_10 ,
void (* F_11)( void * , int ) , void * V_16 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
struct V_23 * V_24 = V_21 -> V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
unsigned long V_27 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return - V_14 ;
V_26 = F_12 ( sizeof( * V_26 ) , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
F_13 ( & V_26 -> V_30 , V_31 ) ;
V_26 -> V_8 = V_8 ;
V_26 -> V_2 = V_2 ;
V_26 -> F_11 = F_11 ;
V_26 -> V_16 = V_16 ;
F_14 ( & V_24 -> V_32 , V_27 ) ;
F_15 ( & V_26 -> V_33 , & V_24 -> V_34 ) ;
F_16 ( & V_24 -> V_32 , V_27 ) ;
return 0 ;
}
void
F_17 ( struct V_7 * V_8 , enum V_9 V_10 ,
void (* F_11)( void * , int ) , void * V_16 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
struct V_23 * V_24 = V_21 -> V_24 ;
struct V_25 * V_26 , * V_35 ;
struct V_1 * V_2 ;
F_18 ( V_36 ) ;
unsigned long V_27 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return;
F_14 ( & V_24 -> V_32 , V_27 ) ;
F_19 (gpioh, tmp, &priv->handlers, head) {
if ( V_26 -> V_2 != V_2 ||
V_26 -> F_11 != F_11 ||
V_26 -> V_16 != V_16 )
continue;
F_20 ( & V_26 -> V_33 , & V_36 ) ;
}
F_16 ( & V_24 -> V_32 , V_27 ) ;
F_19 (gpioh, tmp, &tofree, head) {
F_21 ( & V_26 -> V_30 ) ;
F_22 ( V_26 ) ;
}
}
bool
F_23 ( struct V_7 * V_8 , enum V_9 V_10 , bool V_37 )
{
struct V_1 * V_2 ;
T_2 V_3 , V_38 ;
V_2 = F_3 ( V_8 , V_10 ) ;
if ( ! V_2 )
return false ;
V_3 = V_2 -> line < 16 ? 0xe050 : 0xe070 ;
V_38 = 0x00010001 << ( V_2 -> line & 0xf ) ;
F_6 ( V_8 , V_3 + 4 , V_38 ) ;
V_3 = F_9 ( V_8 , V_3 + 0 , V_38 , V_37 ? V_38 : 0 ) ;
return ( V_3 & V_38 ) == V_38 ;
}
static int
F_24 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
struct V_23 * V_24 ;
V_24 = F_12 ( sizeof( * V_24 ) , V_28 ) ;
if ( ! V_24 )
return - V_29 ;
F_25 ( & V_24 -> V_34 ) ;
F_26 ( & V_24 -> V_32 ) ;
V_21 -> V_24 = V_24 ;
return 0 ;
}
static void
F_27 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
F_22 ( V_21 -> V_24 ) ;
V_21 -> V_24 = NULL ;
}
int
F_28 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
int V_39 ;
if ( ! V_21 -> V_24 ) {
V_39 = F_24 ( V_8 ) ;
if ( V_39 )
return V_39 ;
}
F_6 ( V_8 , 0xe050 , 0x00000000 ) ;
F_6 ( V_8 , 0xe054 , 0xffffffff ) ;
if ( V_18 -> V_40 >= 0x90 ) {
F_6 ( V_8 , 0xe070 , 0x00000000 ) ;
F_6 ( V_8 , 0xe074 , 0xffffffff ) ;
}
F_29 ( V_8 , 21 , V_41 ) ;
return 0 ;
}
void
F_30 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
F_6 ( V_8 , 0xe050 , 0x00000000 ) ;
if ( V_18 -> V_40 >= 0x90 )
F_6 ( V_8 , 0xe070 , 0x00000000 ) ;
F_31 ( V_8 , 21 ) ;
F_27 ( V_8 ) ;
}
static void
V_31 ( struct V_42 * V_30 )
{
struct V_25 * V_26 =
F_32 ( V_30 , struct V_25 , V_30 ) ;
struct V_17 * V_18 = V_26 -> V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
struct V_23 * V_24 = V_21 -> V_24 ;
unsigned long V_27 ;
int V_15 ;
V_15 = V_21 -> V_43 ( V_26 -> V_8 , V_26 -> V_2 -> V_10 ) ;
if ( V_15 < 0 )
return;
V_26 -> F_11 ( V_26 -> V_16 , V_15 ) ;
F_14 ( & V_24 -> V_32 , V_27 ) ;
V_26 -> V_44 = false ;
F_16 ( & V_24 -> V_32 , V_27 ) ;
}
static void
V_41 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_22 . V_2 ;
struct V_23 * V_24 = V_21 -> V_24 ;
struct V_25 * V_26 ;
T_2 V_45 , V_46 = 0 ;
T_2 V_47 , V_48 , V_49 ;
V_45 = F_4 ( V_8 , 0xe054 ) & F_4 ( V_8 , 0xe050 ) ;
if ( V_18 -> V_40 >= 0x90 )
V_46 = F_4 ( V_8 , 0xe074 ) & F_4 ( V_8 , 0xe070 ) ;
V_47 = ( V_45 & 0x0000ffff ) | ( V_46 << 16 ) ;
V_48 = ( V_45 >> 16 ) | ( V_46 & 0xffff0000 ) ;
V_49 = V_47 | V_48 ;
F_6 ( V_8 , 0xe054 , V_45 ) ;
if ( V_18 -> V_40 >= 0x90 )
F_6 ( V_8 , 0xe074 , V_46 ) ;
F_33 ( & V_24 -> V_32 ) ;
F_34 (gpioh, &priv->handlers, head) {
if ( ! ( V_49 & ( 1 << V_26 -> V_2 -> line ) ) )
continue;
if ( V_26 -> V_44 )
continue;
V_26 -> V_44 = true ;
F_35 ( & V_26 -> V_30 ) ;
}
F_36 ( & V_24 -> V_32 ) ;
}
