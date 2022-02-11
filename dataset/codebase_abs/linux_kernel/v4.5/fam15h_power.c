static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_6 , V_7 , V_8 ;
T_3 V_9 ;
T_4 V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 5 ) ,
V_18 , & V_6 ) ;
if ( V_19 . V_20 == 0x15 && V_19 . V_21 >= 0x60 ) {
V_9 = V_6 >> 4 ;
V_9 = F_6 ( V_9 , 27 ) ;
} else {
V_9 = ( V_6 >> 4 ) & 0x3fffff ;
V_9 = F_6 ( V_9 , 21 ) ;
}
V_8 = ( V_6 & 0xf ) + 1 ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 5 ) ,
V_22 , & V_6 ) ;
if ( V_19 . V_20 == 0x15 && V_19 . V_21 >= 0x60 )
V_7 = V_6 >> 16 ;
else
V_7 = ( V_6 >> 16 ) & 0x1fff ;
V_10 = ( ( T_4 ) ( V_7 +
V_12 -> V_23 ) ) << V_8 ;
V_10 -= V_9 ;
V_10 *= V_12 -> V_24 ;
V_10 = ( V_10 * 15625 ) >> ( 10 + V_8 ) ;
return sprintf ( V_5 , L_1 , ( unsigned int ) V_10 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_12 -> V_25 ) ;
}
static int F_8 ( struct V_13 * V_15 ,
struct V_11 * V_12 )
{
int V_26 = V_27 ;
struct V_28 * * V_29 ;
struct V_30 * V_31 = & V_19 ;
if ( V_31 -> V_20 == 0x15 &&
( V_31 -> V_21 <= 0xf ||
( V_31 -> V_21 >= 0x60 && V_31 -> V_21 <= 0x7f ) ) )
V_26 += 1 ;
V_29 = F_9 ( & V_15 -> V_2 , V_26 ,
sizeof( * V_29 ) ,
V_32 ) ;
if ( ! V_29 )
return - V_33 ;
V_26 = 0 ;
V_29 [ V_26 ++ ] = & V_34 . V_4 ;
if ( V_31 -> V_20 == 0x15 &&
( V_31 -> V_21 <= 0xf ||
( V_31 -> V_21 >= 0x60 && V_31 -> V_21 <= 0x7f ) ) )
V_29 [ V_26 ++ ] = & V_35 . V_4 ;
V_12 -> V_36 . V_37 = V_29 ;
return 0 ;
}
static bool F_10 ( struct V_13 * V_14 )
{
T_2 V_6 ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 3 ) ,
V_38 , & V_6 ) ;
if ( ( V_6 & F_11 ( 29 ) ) && ( ( V_6 >> 30 ) & 3 ) )
return false ;
return true ;
}
static void F_12 ( struct V_13 * V_15 )
{
T_2 V_6 ;
if ( ! F_13 ( V_39 , V_15 ) )
return;
F_3 ( V_15 -> V_16 ,
F_4 ( F_5 ( V_15 -> V_17 ) , 5 ) ,
V_18 , & V_6 ) ;
if ( ( V_6 & 0xf ) != 0xe )
return;
V_6 &= ~ 0xf ;
V_6 |= 0x9 ;
F_14 ( V_15 -> V_16 ,
F_4 ( F_5 ( V_15 -> V_17 ) , 5 ) ,
V_18 , V_6 ) ;
}
static int F_15 ( struct V_13 * V_15 )
{
F_12 ( V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_11 * V_12 )
{
T_2 V_6 , V_40 , V_41 , V_42 , V_43 ;
T_4 V_44 ;
int V_45 ;
F_17 ( V_14 , V_46 , & V_6 ) ;
V_12 -> V_23 = V_6 >> 16 ;
V_44 = V_6 & 0xffff ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 5 ) ,
V_22 , & V_6 ) ;
V_12 -> V_24 = ( ( V_6 & 0x3ff ) << 6 ) | ( ( V_6 >> 10 ) & 0x3f ) ;
V_44 *= V_12 -> V_24 ;
if ( ( V_44 >> 16 ) >= 256 )
F_18 ( & V_14 -> V_2 ,
L_2 ,
( unsigned int ) ( V_44 >> 16 ) ) ;
V_12 -> V_25 = ( V_44 * 15625 ) >> 10 ;
V_45 = F_8 ( V_14 , V_12 ) ;
if ( V_45 )
return V_45 ;
F_19 ( 0x80000007 , & V_40 , & V_41 , & V_42 , & V_43 ) ;
if ( ! ( V_43 & F_11 ( 12 ) ) )
return 0 ;
V_12 -> V_47 = V_42 ;
if ( F_20 ( V_48 , & V_44 ) ) {
F_21 ( L_3 ) ;
return - V_49 ;
}
V_12 -> V_50 = V_44 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_15 ,
const struct V_51 * V_52 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_1 * V_53 ;
int V_45 ;
F_12 ( V_15 ) ;
if ( ! F_10 ( V_15 ) )
return - V_49 ;
V_12 = F_23 ( V_2 , sizeof( struct V_11 ) , V_32 ) ;
if ( ! V_12 )
return - V_33 ;
V_45 = F_16 ( V_15 , V_12 ) ;
if ( V_45 )
return V_45 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_54 [ 0 ] = & V_12 -> V_36 ;
V_53 = F_24 ( V_2 , L_4 ,
V_12 ,
& V_12 -> V_54 [ 0 ] ) ;
return F_25 ( V_53 ) ;
}
