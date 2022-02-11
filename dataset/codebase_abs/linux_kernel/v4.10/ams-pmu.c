static void F_1 ( struct V_1 * V_2 )
{
F_2 ( (struct V_3 * ) V_2 -> V_4 ) ;
}
static void F_3 ( T_1 V_5 , T_1 V_6 )
{
static struct V_1 V_2 ;
F_4 ( V_7 ) ;
V_2 . V_4 = & V_7 ;
if ( F_5 ( & V_2 , F_1 , 4 , V_8 , 0x00 , V_5 , V_6 ) )
return;
F_6 ( & V_7 ) ;
}
static T_1 F_7 ( T_1 V_5 )
{
static struct V_1 V_2 ;
F_4 ( V_7 ) ;
V_2 . V_4 = & V_7 ;
if ( F_5 ( & V_2 , F_1 , 3 , V_8 , 0x01 , V_5 ) )
return 0 ;
F_6 ( & V_7 ) ;
if ( V_2 . V_9 > 0 )
return V_2 . V_10 [ 0 ] ;
else
return 0 ;
}
static void F_8 ( enum V_11 V_5 , char V_12 )
{
if ( V_5 & V_13 ) {
T_1 V_14 = F_7 ( V_15 ) ;
if ( V_12 )
V_14 |= 0x80 ;
else
V_14 &= ~ 0x80 ;
F_3 ( V_15 , V_14 ) ;
}
if ( V_5 & V_16 ) {
T_1 V_14 = F_7 ( V_17 ) ;
if ( V_12 )
V_14 |= 0x80 ;
else
V_14 &= ~ 0x80 ;
F_3 ( V_17 , V_14 ) ;
}
if ( V_5 & V_18 ) {
T_1 V_14 = F_7 ( V_19 ) ;
if ( V_12 )
V_14 |= 0x80 ;
else
V_14 &= ~ 0x80 ;
F_3 ( V_19 , V_14 ) ;
}
}
static void F_9 ( enum V_11 V_5 )
{
if ( V_5 & V_13 )
F_3 ( V_20 , 0x00 ) ;
if ( V_5 & V_16 )
F_3 ( V_21 , 0x00 ) ;
}
static T_1 F_10 ( void )
{
return F_7 ( V_22 ) ;
}
static void F_11 ( T_2 * V_23 , T_2 * V_24 , T_2 * V_25 )
{
* V_23 = F_7 ( V_26 ) ;
* V_24 = F_7 ( V_27 ) ;
* V_25 = F_7 ( V_28 ) ;
}
static void F_12 ( void )
{
F_13 () ;
F_8 ( V_29 , 0 ) ;
F_9 ( V_29 ) ;
V_30 . V_31 = 0 ;
F_14 ( V_32 L_1 ) ;
}
int T_3 F_15 ( struct V_33 * V_34 )
{
const T_4 * V_35 ;
int V_36 ;
V_30 . V_37 = V_34 ;
V_30 . exit = F_12 ;
V_30 . V_38 = F_10 ;
V_30 . V_39 = F_11 ;
V_30 . V_40 = F_9 ;
V_30 . V_41 = V_42 ;
V_35 = F_16 ( V_30 . V_37 , L_2 , NULL ) ;
if ( ! V_35 )
return - V_43 ;
V_8 = ( ( * V_35 ) >> 8 ) & 0xff ;
F_8 ( V_29 , 0 ) ;
F_9 ( V_29 ) ;
V_36 = F_17 () ;
if ( V_36 < 0 )
return V_36 ;
F_3 ( V_44 , 0x15 ) ;
F_3 ( V_15 , 0x08 ) ;
F_3 ( V_45 , 0x14 ) ;
F_3 ( V_46 , 0x60 ) ;
F_3 ( V_17 , 0x0f ) ;
F_3 ( V_47 , 0x14 ) ;
F_3 ( V_19 , 0x4f ) ;
F_9 ( V_29 ) ;
V_30 . V_31 = 1 ;
F_8 ( V_29 , 1 ) ;
F_14 ( V_32 L_3 ) ;
return 0 ;
}
