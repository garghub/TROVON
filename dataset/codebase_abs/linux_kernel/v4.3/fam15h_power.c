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
V_7 = V_6 >> 16 ;
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
static T_5 F_8 ( struct V_26 * V_27 ,
struct V_28 * V_4 ,
int V_29 )
{
if ( V_4 == & V_30 . V_4 &&
( V_19 . V_20 != 0x15 || V_19 . V_21 > 0xf ) )
return 0 ;
return V_4 -> V_31 ;
}
static bool F_9 ( struct V_13 * V_14 )
{
T_2 V_6 ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 3 ) ,
V_32 , & V_6 ) ;
if ( ( V_6 & F_10 ( 29 ) ) && ( ( V_6 >> 30 ) & 3 ) )
return false ;
return true ;
}
static void F_11 ( struct V_13 * V_15 )
{
T_2 V_6 ;
if ( ! F_12 ( V_33 , V_15 ) )
return;
F_3 ( V_15 -> V_16 ,
F_4 ( F_5 ( V_15 -> V_17 ) , 5 ) ,
V_18 , & V_6 ) ;
if ( ( V_6 & 0xf ) != 0xe )
return;
V_6 &= ~ 0xf ;
V_6 |= 0x9 ;
F_13 ( V_15 -> V_16 ,
F_4 ( F_5 ( V_15 -> V_17 ) , 5 ) ,
V_18 , V_6 ) ;
}
static int F_14 ( struct V_13 * V_15 )
{
F_11 ( V_15 ) ;
return 0 ;
}
static void F_15 ( struct V_13 * V_14 ,
struct V_11 * V_12 )
{
T_2 V_6 , V_34 , V_35 , V_36 , V_37 ;
T_4 V_38 ;
F_16 ( V_14 , V_39 , & V_6 ) ;
V_12 -> V_23 = V_6 >> 16 ;
V_38 = V_6 & 0xffff ;
F_3 ( V_14 -> V_16 , F_4 ( F_5 ( V_14 -> V_17 ) , 5 ) ,
V_22 , & V_6 ) ;
V_12 -> V_24 = ( ( V_6 & 0x3ff ) << 6 ) | ( ( V_6 >> 10 ) & 0x3f ) ;
V_38 *= V_12 -> V_24 ;
if ( ( V_38 >> 16 ) >= 256 )
F_17 ( & V_14 -> V_2 ,
L_2 ,
( unsigned int ) ( V_38 >> 16 ) ) ;
V_12 -> V_25 = ( V_38 * 15625 ) >> 10 ;
F_18 ( 0x80000007 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( ! ( V_37 & F_10 ( 12 ) ) )
return;
V_12 -> V_40 = V_36 ;
}
static int F_19 ( struct V_13 * V_15 ,
const struct V_41 * V_42 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_1 * V_43 ;
F_11 ( V_15 ) ;
if ( ! F_9 ( V_15 ) )
return - V_44 ;
V_12 = F_20 ( V_2 , sizeof( struct V_11 ) , V_45 ) ;
if ( ! V_12 )
return - V_46 ;
F_15 ( V_15 , V_12 ) ;
V_12 -> V_15 = V_15 ;
V_43 = F_21 ( V_2 , L_3 ,
V_12 ,
V_47 ) ;
return F_22 ( V_43 ) ;
}
