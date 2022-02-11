static int F_1 ( int V_1 )
{
return V_1 * 250 ;
}
static int F_2 ( int V_1 )
{
return V_1 * 1000 ;
}
static int F_3 ( int V_1 )
{
return V_1 / 1000 ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
V_6 = F_5 ( V_5 , V_7 ) ;
if ( V_6 & 0x40 )
F_6 ( V_5 , V_8 ,
V_6 & 0xBF ) ;
V_3 -> V_9 [ 0 ] = F_5 ( V_5 ,
V_10 ) ;
V_3 -> V_9 [ 1 ] = F_5 ( V_5 ,
V_11 ) ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
T_1 V_16 , V_17 , V_18 ;
if ( ! F_8 ( V_15 , V_19 ) )
return - V_20 ;
V_18 = F_5 ( V_5 , V_21 ) ;
if ( V_18 != 0x4D )
return - V_20 ;
if ( F_5 ( V_5 , 0x04 ) != 0x4D
|| F_5 ( V_5 , 0x06 ) != 0x4D
|| F_5 ( V_5 , 0xff ) != 0x4D )
return - V_20 ;
V_16 = F_5 ( V_5 , V_7 ) ;
if ( ( V_16 & 0x0f ) != 0x00 )
return - V_20 ;
if ( F_5 ( V_5 , 0x04 ) != V_16
|| F_5 ( V_5 , 0x06 ) != V_16
|| F_5 ( V_5 , 0xff ) != V_16 )
return - V_20 ;
V_17 = F_5 ( V_5 , V_22 ) ;
if ( ( V_17 & 0x2b ) != 0x00 )
return - V_20 ;
F_9 ( V_13 -> type , L_1 , V_23 ) ;
return 0 ;
}
static struct V_2 * F_10 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_11 ( V_25 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_1 , V_26 ;
F_12 ( & V_3 -> V_27 ) ;
if ( F_13 ( V_28 , V_3 -> V_29 + V_30 ) || ! V_3 -> V_31 ) {
F_14 ( V_25 , L_2 ) ;
V_1 = F_5 ( V_5 ,
V_32 ) ;
V_26 = ( V_1 >> 6 ) & 3 ;
V_1 = F_5 ( V_5 ,
V_33 ) ;
V_1 = ( V_1 << 2 ) | V_26 ;
V_3 -> V_34 [ 0 ] = V_1 ;
V_1 = F_5 ( V_5 ,
V_35 ) ;
V_26 = ( V_1 >> 6 ) & 3 ;
V_1 = F_5 ( V_5 ,
V_36 ) ;
V_1 = ( V_1 << 2 ) | V_26 ;
V_3 -> V_34 [ 1 ] = V_1 ;
V_3 -> V_37 = F_5 ( V_5 ,
V_22 ) ;
V_3 -> V_29 = V_28 ;
V_3 -> V_31 = 1 ;
}
F_15 ( & V_3 -> V_27 ) ;
return V_3 ;
}
static T_3 F_16 ( struct V_24 * V_25 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_41 * V_42 = F_17 ( V_39 ) ;
struct V_2 * V_3 = F_10 ( V_25 ) ;
return sprintf ( V_40 , L_3 ,
F_1 ( V_3 -> V_34 [ V_42 -> V_43 ] ) ) ;
}
static T_3 F_18 ( struct V_24 * V_25 , struct V_38 * V_42 ,
char * V_40 )
{
struct V_44 * V_45 = F_19 ( V_42 ) ;
struct V_2 * V_3 = F_10 ( V_25 ) ;
return sprintf ( V_40 , L_3 , F_2 ( V_3 -> V_9 [ V_45 -> V_46 ] ) ) ;
}
static T_3 F_20 ( struct V_24 * V_25 , struct V_38 * V_42 ,
const char * V_40 , T_4 V_47 )
{
struct V_44 * V_45 = F_19 ( V_42 ) ;
struct V_2 * V_3 = F_11 ( V_25 ) ;
unsigned long V_1 ;
int V_48 ;
V_48 = F_21 ( V_40 , 10 , & V_1 ) ;
if ( V_48 < 0 )
return V_48 ;
F_12 ( & V_3 -> V_27 ) ;
V_3 -> V_9 [ V_45 -> V_46 ] = F_22 ( F_3 ( V_1 ) , 0 , 255 ) ;
F_6 ( V_3 -> V_5 , V_45 -> V_43 ,
V_3 -> V_9 [ V_45 -> V_46 ] ) ;
F_15 ( & V_3 -> V_27 ) ;
return V_47 ;
}
static T_3 F_23 ( struct V_24 * V_25 , struct V_38 * V_42 ,
char * V_40 )
{
int V_49 = F_17 ( V_42 ) -> V_43 ;
struct V_2 * V_3 = F_10 ( V_25 ) ;
return sprintf ( V_40 , L_3 , ( V_3 -> V_37 >> V_49 ) & 1 ) ;
}
static int F_24 ( struct V_4 * V_5 ,
const struct V_50 * V_51 )
{
struct V_24 * V_25 = & V_5 -> V_25 ;
struct V_2 * V_3 ;
struct V_24 * V_52 ;
V_3 = F_25 ( V_25 , sizeof( struct V_2 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
V_3 -> V_5 = V_5 ;
F_26 ( & V_3 -> V_27 ) ;
F_4 ( V_3 , V_5 ) ;
V_52 = F_27 ( & V_5 -> V_25 ,
V_5 -> V_55 , V_3 ,
V_56 ) ;
return F_28 ( V_52 ) ;
}
