static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , NULL , 256 , 0 ,
V_12 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void
F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_15 ( V_14 ) ;
struct V_17 * V_3 = F_5 ( V_14 ) ;
struct V_1 * V_18 ;
struct V_19 * V_10 = ( void * ) V_14 ;
T_1 V_20 = F_6 ( V_10 , 0x10401c ) ;
T_1 V_21 = F_6 ( V_10 , 0x104008 ) & V_20 & ~ ( V_20 >> 16 ) ;
T_2 V_22 = F_6 ( V_10 , 0x104050 ) & 0x3fffffff ;
T_1 V_23 = F_6 ( V_10 , 0x104040 ) & 0x0000ffff ;
T_1 V_24 = F_6 ( V_10 , 0x104040 ) >> 16 ;
T_1 V_25 = ( V_24 & 0x07ff ) << 2 ;
T_1 V_26 = ( V_24 & 0x3800 ) >> 11 ;
T_1 V_6 = F_6 ( V_10 , 0x104044 ) ;
int V_27 ;
V_18 = F_7 ( V_3 , V_22 ) ;
V_27 = V_16 -> V_27 ( V_16 , V_18 ) ;
if ( V_21 & 0x00000040 ) {
F_8 ( V_10 , L_1 ) ;
F_9 ( V_28 , V_23 ) ;
F_10 ( L_2 ,
V_27 , V_22 << 12 , V_26 , V_25 , V_6 ) ;
F_11 ( V_10 , 0x104004 , 0x00000040 ) ;
V_21 &= ~ 0x00000040 ;
}
if ( V_21 ) {
F_8 ( V_10 , L_3 , V_21 ) ;
F_11 ( V_10 , 0x104004 , V_21 ) ;
}
F_12 ( F_13 ( V_10 ) , 1 ) ;
F_14 ( V_18 ) ;
}
static int
F_15 ( struct V_17 * V_3 )
{
F_16 ( & V_3 -> V_29 , 0x0d ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
bool V_30 = ( F_18 ( V_2 ) -> V_31 != 0xaf ) ;
struct V_19 * V_10 ;
int V_11 ;
V_11 = F_19 ( V_2 , V_3 , V_5 , V_30 , 0 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
F_20 ( V_10 ) -> V_32 = 0x00802000 ;
F_20 ( V_10 ) -> V_33 = F_4 ;
F_5 ( V_10 ) -> V_34 = & V_35 ;
F_5 ( V_10 ) -> V_36 = V_37 ;
F_5 ( V_10 ) -> V_38 = F_15 ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_39 )
{
struct V_19 * V_10 = ( void * ) V_39 ;
int V_11 , V_40 ;
V_11 = F_22 ( & V_10 -> V_29 ) ;
if ( V_11 )
return V_11 ;
F_11 ( V_10 , 0x104014 , 0xffffffff ) ;
F_11 ( V_10 , 0x1041c0 , 0x01000000 ) ;
for ( V_40 = 0 ; V_40 < sizeof( V_41 ) / 4 ; V_40 ++ )
F_11 ( V_10 , 0x1041c4 , V_41 [ V_40 ] ) ;
F_11 ( V_10 , 0x104180 , 0x01000000 ) ;
for ( V_40 = 0 ; V_40 < sizeof( V_42 ) / 4 ; V_40 ++ ) {
if ( ( V_40 & 0x3f ) == 0 )
F_11 ( V_10 , 0x104188 , V_40 >> 6 ) ;
F_11 ( V_10 , 0x104184 , V_42 [ V_40 ] ) ;
}
F_11 ( V_10 , 0x10410c , 0x00000000 ) ;
F_11 ( V_10 , 0x104104 , 0x00000000 ) ;
F_11 ( V_10 , 0x104100 , 0x00000002 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_39 , bool V_43 )
{
struct V_19 * V_10 = ( void * ) V_39 ;
F_24 ( V_10 , 0x104048 , 0x00000003 , 0x00000000 ) ;
F_11 ( V_10 , 0x104014 , 0xffffffff ) ;
return F_25 ( & V_10 -> V_29 , V_43 ) ;
}
