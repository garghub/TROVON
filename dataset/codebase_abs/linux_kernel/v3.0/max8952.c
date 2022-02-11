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
static int F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
return ( V_2 -> V_8 -> V_9 [ V_7 ] * 10 + 770 ) * 1000 ;
}
static int F_6 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( F_8 ( V_11 ) != 0 )
return - V_13 ;
return F_5 ( V_2 , V_12 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_14 ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( F_11 ( V_2 -> V_8 -> V_15 ) )
F_12 ( V_2 -> V_8 -> V_15 , 1 ) ;
V_2 -> V_14 = true ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( F_11 ( V_2 -> V_8 -> V_15 ) )
F_12 ( V_2 -> V_8 -> V_15 , 0 ) ;
else
return - V_16 ;
V_2 -> V_14 = false ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
T_1 V_17 = 0 ;
if ( V_2 -> V_18 )
V_17 += 1 ;
if ( V_2 -> V_19 )
V_17 += 2 ;
return F_5 ( V_2 , V_17 ) ;
}
static int F_15 ( struct V_10 * V_11 ,
int V_20 , int V_21 , unsigned * V_12 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
T_2 V_17 = - 1 , V_22 ;
if ( ! F_11 ( V_2 -> V_8 -> V_23 ) ||
! F_11 ( V_2 -> V_8 -> V_24 ) ) {
return - V_16 ;
}
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
int V_26 = F_5 ( V_2 , V_22 ) ;
if ( V_26 <= V_21 && V_26 >= V_20 )
if ( V_17 == - 1 || F_5 ( V_2 , V_17 ) > V_26 )
V_17 = V_22 ;
}
if ( V_17 >= 0 && V_17 < V_25 ) {
V_2 -> V_18 = ( V_17 % 2 == 1 ) ;
V_2 -> V_19 = ( ( ( V_17 >> 1 ) % 2 ) == 1 ) ;
* V_12 = V_17 ;
F_12 ( V_2 -> V_8 -> V_23 , V_2 -> V_18 ) ;
F_12 ( V_2 -> V_8 -> V_24 , V_2 -> V_19 ) ;
} else
return - V_13 ;
return 0 ;
}
static int T_3 F_16 ( struct V_27 * V_5 ,
const struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_5 -> V_32 . V_33 ) ;
struct V_34 * V_8 = V_5 -> V_32 . V_35 ;
struct V_1 * V_2 ;
int V_4 = 0 , V_36 = 0 ;
if ( ! V_8 ) {
F_18 ( & V_5 -> V_32 , L_1 ) ;
return - V_13 ;
}
if ( ! F_19 ( V_31 , V_37 ) )
return - V_38 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_32 = & V_5 -> V_32 ;
V_2 -> V_8 = V_8 ;
F_21 ( & V_2 -> V_41 ) ;
V_2 -> V_11 = F_22 ( & V_42 , V_2 -> V_32 ,
& V_8 -> V_43 , V_2 ) ;
if ( F_23 ( V_2 -> V_11 ) ) {
V_4 = F_24 ( V_2 -> V_11 ) ;
F_18 ( V_2 -> V_32 , L_2 , V_4 ) ;
goto V_44;
}
V_2 -> V_14 = ! ! ( V_8 -> V_43 . V_45 . V_46 ) ;
V_2 -> V_18 = ( V_8 -> V_47 % 2 ) == 1 ;
V_2 -> V_19 = ( ( V_8 -> V_47 >> 1 ) % 2 ) == 1 ;
if ( F_11 ( V_8 -> V_15 ) ) {
if ( ! F_25 ( V_8 -> V_15 , L_3 ) )
F_26 ( V_8 -> V_15 , V_2 -> V_14 ) ;
else
V_36 = 1 ;
} else
V_36 = 2 ;
if ( V_36 ) {
F_27 ( V_2 -> V_32 , L_4
L_5 ) ;
V_2 -> V_14 = 1 ;
V_8 -> V_15 = - 1 ;
}
V_36 = 0 ;
if ( F_11 ( V_8 -> V_23 ) &&
F_11 ( V_8 -> V_24 ) ) {
if ( ! F_25 ( V_8 -> V_23 , L_6 ) )
F_26 ( V_8 -> V_23 ,
( V_8 -> V_47 ) % 2 ) ;
else
V_36 = 1 ;
if ( ! F_25 ( V_8 -> V_24 , L_7 ) )
F_26 ( V_8 -> V_24 ,
( V_8 -> V_47 >> 1 ) % 2 ) ;
else {
if ( ! V_36 )
F_28 ( V_8 -> V_23 ) ;
V_36 = 2 ;
}
} else
V_36 = 3 ;
if ( V_36 ) {
F_29 ( V_2 -> V_32 , L_8
L_9 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_8 -> V_23 = - 1 ;
V_8 -> V_24 = - 1 ;
F_3 ( V_2 , V_48 , 0x60 ) ;
F_18 ( V_2 -> V_32 , L_10
L_11 ) ;
} else {
F_3 ( V_2 , V_48 , 0x0 ) ;
}
F_3 ( V_2 , V_49 ,
( F_1 ( V_2 ,
V_49 ) & 0xC0 ) |
( V_8 -> V_9 [ 0 ] & 0x3F ) ) ;
F_3 ( V_2 , V_50 ,
( F_1 ( V_2 ,
V_50 ) & 0xC0 ) |
( V_8 -> V_9 [ 1 ] & 0x3F ) ) ;
F_3 ( V_2 , V_51 ,
( F_1 ( V_2 ,
V_51 ) & 0xC0 ) |
( V_8 -> V_9 [ 2 ] & 0x3F ) ) ;
F_3 ( V_2 , V_52 ,
( F_1 ( V_2 ,
V_52 ) & 0xC0 ) |
( V_8 -> V_9 [ 3 ] & 0x3F ) ) ;
F_3 ( V_2 , V_53 ,
( F_1 ( V_2 , V_53 ) & 0x3F ) |
( ( V_8 -> V_54 & 0x3 ) << 6 ) ) ;
F_3 ( V_2 , V_55 ,
( F_1 ( V_2 , V_55 ) & 0x1F ) |
( ( V_8 -> V_56 & 0x7 ) << 5 ) ) ;
F_30 ( V_5 , V_2 ) ;
return 0 ;
V_44:
F_31 ( V_2 ) ;
return V_4 ;
}
static int T_4 F_32 ( struct V_27 * V_5 )
{
struct V_1 * V_2 = F_33 ( V_5 ) ;
struct V_34 * V_8 = V_2 -> V_8 ;
struct V_10 * V_11 = V_2 -> V_11 ;
F_34 ( V_11 ) ;
F_28 ( V_8 -> V_23 ) ;
F_28 ( V_8 -> V_24 ) ;
F_28 ( V_8 -> V_15 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_57 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_57 ) ;
}
