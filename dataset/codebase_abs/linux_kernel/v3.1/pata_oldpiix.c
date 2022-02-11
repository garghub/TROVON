static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
static const struct V_10 V_11 [] = {
{ 0x41U , 1U , 0x80UL , 0x80UL } ,
{ 0x43U , 1U , 0x80UL , 0x80UL } ,
} ;
if ( ! F_3 ( V_7 , & V_11 [ V_5 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
unsigned int V_16 = V_15 -> V_17 - V_18 ;
struct V_6 * V_9 = F_2 ( V_5 -> V_8 -> V_9 ) ;
unsigned int V_19 = V_5 -> V_12 ? 0x42 : 0x40 ;
T_1 V_20 ;
int V_21 = 0 ;
static const
T_2 V_22 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_16 > 1 )
V_21 |= 1 ;
if ( F_6 ( V_15 ) )
V_21 |= 2 ;
if ( V_15 -> V_23 == V_24 )
V_21 |= 4 ;
F_7 ( V_9 , V_19 , & V_20 ) ;
if ( V_15 -> V_25 == 0 ) {
V_20 &= 0xCCE0 ;
V_20 |= V_21 ;
} else {
V_20 &= 0xCC0E ;
V_20 |= ( V_21 << 4 ) ;
}
V_20 |= ( V_22 [ V_16 ] [ 0 ] << 12 ) |
( V_22 [ V_16 ] [ 1 ] << 8 ) ;
F_8 ( V_9 , V_19 , V_20 ) ;
V_5 -> V_26 = V_15 ;
}
static void F_9 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_6 * V_9 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_2 V_19 = V_5 -> V_12 ? 0x42 : 0x40 ;
T_1 V_20 ;
static const
T_2 V_22 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
unsigned int V_27 = V_15 -> V_28 - V_29 ;
unsigned int V_21 ;
const unsigned int V_30 [ 3 ] = {
V_18 , V_31 , V_32
} ;
int V_16 = V_30 [ V_27 ] - V_18 ;
F_7 ( V_9 , V_19 , & V_20 ) ;
V_21 = 3 ;
if ( V_15 -> V_23 == V_24 )
V_21 |= 4 ;
if ( V_15 -> V_17 < V_30 [ V_27 ] )
V_21 |= 8 ;
if ( V_15 -> V_25 == 0 ) {
V_20 &= 0xCCE0 ;
V_20 |= V_21 ;
} else {
V_20 &= 0xCC0E ;
V_20 |= ( V_21 << 4 ) ;
}
V_20 |= ( V_22 [ V_16 ] [ 0 ] << 12 ) | ( V_22 [ V_16 ] [ 1 ] << 8 ) ;
F_8 ( V_9 , V_19 , V_20 ) ;
V_5 -> V_26 = V_15 ;
}
static unsigned int F_10 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_14 * V_15 = V_34 -> V_9 ;
if ( V_15 != V_5 -> V_26 ) {
F_5 ( V_5 , V_15 ) ;
if ( F_11 ( V_15 ) )
F_9 ( V_5 , V_15 ) ;
}
return F_12 ( V_34 ) ;
}
static int F_13 ( struct V_6 * V_7 , const struct V_35 * V_36 )
{
static const struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_42 ,
. V_43 = V_44 ,
. V_45 = & V_46 ,
} ;
const struct V_37 * V_47 [] = { & V_38 , NULL } ;
F_14 ( & V_7 -> V_9 , V_48 ) ;
return F_15 ( V_7 , V_47 , & V_49 , NULL , 0 ) ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_50 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_50 ) ;
}
