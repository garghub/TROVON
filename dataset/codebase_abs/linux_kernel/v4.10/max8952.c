static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 , V_3 ) ;
if ( V_4 > 0 )
V_4 &= 0xff ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_6 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) != 0 )
return - V_10 ;
return ( V_2 -> V_11 -> V_12 [ V_9 ] * 10 + 770 ) * 1000 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
T_1 V_13 = 0 ;
if ( V_2 -> V_14 )
V_13 += 1 ;
if ( V_2 -> V_15 )
V_13 += 2 ;
return V_13 ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( ! F_10 ( V_2 -> V_11 -> V_16 ) ||
! F_10 ( V_2 -> V_11 -> V_17 ) ) {
return - V_18 ;
}
V_2 -> V_14 = V_9 & 0x1 ;
V_2 -> V_15 = ( V_9 >> 1 ) & 0x1 ;
F_11 ( V_2 -> V_11 -> V_16 , V_2 -> V_14 ) ;
F_11 ( V_2 -> V_11 -> V_17 , V_2 -> V_15 ) ;
return 0 ;
}
static struct V_19 * F_12 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 = V_21 -> V_25 ;
int V_4 ;
int V_26 ;
V_22 = F_13 ( V_21 , sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_16 = F_14 ( V_24 , L_1 , 0 ) ;
V_22 -> V_17 = F_14 ( V_24 , L_1 , 1 ) ;
V_22 -> V_28 = F_14 ( V_24 , L_2 , 0 ) ;
if ( F_15 ( V_24 , L_3 , & V_22 -> V_29 ) )
F_16 ( V_21 , L_4 ) ;
V_4 = F_17 ( V_24 , L_5 ,
V_22 -> V_12 , F_18 ( V_22 -> V_12 ) ) ;
if ( V_4 ) {
F_19 ( V_21 , L_6 ) ;
return NULL ;
}
for ( V_26 = 0 ; V_26 < F_18 ( V_22 -> V_12 ) ; ++ V_26 ) {
if ( V_22 -> V_12 [ V_26 ] < 770000 || V_22 -> V_12 [ V_26 ] > 1400000 ) {
F_19 ( V_21 , L_7 , V_26 ) ;
return NULL ;
}
V_22 -> V_12 [ V_26 ] = ( V_22 -> V_12 [ V_26 ] - 770000 ) / 10000 ;
}
if ( F_15 ( V_24 , L_8 , & V_22 -> V_30 ) )
F_16 ( V_21 , L_9 ) ;
if ( F_15 ( V_24 , L_10 , & V_22 -> V_31 ) )
F_16 ( V_21 , L_11 ) ;
V_22 -> V_32 = F_20 ( V_21 , V_24 , & V_33 ) ;
if ( ! V_22 -> V_32 ) {
F_19 ( V_21 , L_12 ) ;
return NULL ;
}
return V_22 ;
}
static struct V_19 * F_12 ( struct V_20 * V_21 )
{
return NULL ;
}
static int F_21 ( struct V_34 * V_5 ,
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_22 ( V_5 -> V_21 . V_39 ) ;
struct V_19 * V_11 = F_23 ( & V_5 -> V_21 ) ;
struct V_40 V_41 = { } ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_4 = 0 , V_42 = 0 ;
if ( V_5 -> V_21 . V_25 )
V_11 = F_12 ( & V_5 -> V_21 ) ;
if ( ! V_11 ) {
F_19 ( & V_5 -> V_21 , L_13 ) ;
return - V_10 ;
}
if ( ! F_24 ( V_38 , V_43 ) )
return - V_44 ;
V_2 = F_13 ( & V_5 -> V_21 , sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_11 = V_11 ;
V_41 . V_21 = & V_5 -> V_21 ;
V_41 . V_46 = V_11 -> V_32 ;
V_41 . V_47 = V_2 ;
V_41 . V_25 = V_5 -> V_21 . V_25 ;
V_41 . V_48 = V_11 -> V_28 ;
if ( V_5 -> V_21 . V_25 )
V_41 . V_49 = true ;
if ( V_11 -> V_32 -> V_50 . V_51 )
V_41 . V_52 |= V_53 ;
V_8 = F_25 ( & V_5 -> V_21 , & V_33 , & V_41 ) ;
if ( F_26 ( V_8 ) ) {
V_4 = F_27 ( V_8 ) ;
F_19 ( & V_5 -> V_21 , L_14 , V_4 ) ;
return V_4 ;
}
V_2 -> V_14 = V_11 -> V_29 & 0x1 ;
V_2 -> V_15 = ( V_11 -> V_29 >> 1 ) & 0x1 ;
if ( F_10 ( V_11 -> V_16 ) &&
F_10 ( V_11 -> V_17 ) ) {
unsigned long V_54 ;
V_54 = V_2 -> V_14 ?
V_53 : V_55 ;
if ( F_28 ( & V_5 -> V_21 , V_11 -> V_16 ,
V_54 , L_15 ) )
V_42 = 1 ;
V_54 = V_2 -> V_15 ?
V_53 : V_55 ;
if ( F_28 ( & V_5 -> V_21 , V_11 -> V_17 ,
V_54 , L_16 ) )
V_42 = 2 ;
} else
V_42 = 3 ;
if ( V_42 ) {
F_16 ( & V_5 -> V_21 , L_17
L_18 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_11 -> V_16 = - 1 ;
V_11 -> V_17 = - 1 ;
F_3 ( V_2 , V_56 , 0x60 ) ;
F_19 ( & V_5 -> V_21 , L_19
L_20 ) ;
} else {
F_3 ( V_2 , V_56 , 0x0 ) ;
}
F_3 ( V_2 , V_57 ,
( F_1 ( V_2 ,
V_57 ) & 0xC0 ) |
( V_11 -> V_12 [ 0 ] & 0x3F ) ) ;
F_3 ( V_2 , V_58 ,
( F_1 ( V_2 ,
V_58 ) & 0xC0 ) |
( V_11 -> V_12 [ 1 ] & 0x3F ) ) ;
F_3 ( V_2 , V_59 ,
( F_1 ( V_2 ,
V_59 ) & 0xC0 ) |
( V_11 -> V_12 [ 2 ] & 0x3F ) ) ;
F_3 ( V_2 , V_60 ,
( F_1 ( V_2 ,
V_60 ) & 0xC0 ) |
( V_11 -> V_12 [ 3 ] & 0x3F ) ) ;
F_3 ( V_2 , V_61 ,
( F_1 ( V_2 , V_61 ) & 0x3F ) |
( ( V_11 -> V_30 & 0x3 ) << 6 ) ) ;
F_3 ( V_2 , V_62 ,
( F_1 ( V_2 , V_62 ) & 0x1F ) |
( ( V_11 -> V_31 & 0x7 ) << 5 ) ) ;
F_29 ( V_5 , V_2 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_63 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_63 ) ;
}
