static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
static const struct V_10 V_11 [] = {
{ 0x43 , 1 , 0x08 , 0x08 } ,
{ 0x47 , 1 , 0x08 , 0x08 }
} ;
if ( ! F_3 ( V_7 , & V_11 [ V_5 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_16 = 0x40 + 4 * V_5 -> V_12 ;
T_1 V_17 , V_18 ;
struct V_19 V_20 ;
static const T_1 V_21 [ 15 ] = {
0 , 1 , 2 , 3 , 4 ,
5 , 5 , 6 , 6 , 6 ,
6 , 7 , 7 , 7 , 7
} ;
static const T_1 V_22 [ 12 ] = {
0 , 1 , 2 , 3 , 4 , 5 , 6 , 6 , 7 , 7 , 7 , 7
} ;
F_6 ( V_7 , V_16 + 3 , & V_18 ) ;
if ( F_7 ( V_15 ) )
V_18 |= 0x04 ;
else
V_18 &= ~ 0x04 ;
if ( F_8 ( V_15 , V_15 -> V_23 , & V_20 , 30303 , 1 ) < 0 ) {
F_9 ( & V_7 -> V_9 , L_1 , V_15 -> V_23 ) ;
return;
}
V_20 . V_24 = F_10 ( V_20 . V_24 , 2 , 16 ) - 2 ;
V_20 . V_25 = F_10 ( V_20 . V_25 , 1 , 4 ) - 1 ;
V_20 . V_26 = F_10 ( V_20 . V_26 , 1 , 12 ) - 1 ;
V_17 = ( V_20 . V_25 << 6 ) | ( V_22 [ V_20 . V_26 ] << 3 ) | V_21 [ V_20 . V_24 ] ;
F_11 ( V_7 , V_16 , V_17 ) ;
F_11 ( V_7 , V_16 + 3 , V_18 ) ;
V_5 -> V_27 = V_15 ;
}
static unsigned int F_12 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_14 * V_15 = V_29 -> V_9 ;
if ( V_15 -> V_23 && V_15 != V_5 -> V_27 )
F_5 ( V_5 , V_15 ) ;
return F_13 ( V_29 ) ;
}
static int F_14 ( struct V_6 * V_9 , const struct V_30 * V_31 )
{
static const struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = V_37 ,
. V_38 = & V_39
} ;
const struct V_32 * V_40 [] = { & V_33 , NULL } ;
return F_15 ( V_9 , V_40 , & V_41 , NULL , 0 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_42 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_42 ) ;
}
