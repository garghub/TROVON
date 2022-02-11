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
static void F_4 ( struct V_2 * V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_5 ( V_3 ) ;
V_4 = F_6 ( V_3 , V_7 ) ;
if ( V_4 & 0x40 )
F_7 ( V_3 , V_8 ,
V_4 & 0xBF ) ;
V_6 -> V_9 [ 0 ] = F_6 ( V_3 ,
V_10 ) ;
V_6 -> V_9 [ 1 ] = F_6 ( V_3 ,
V_11 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
T_1 V_16 , V_17 , V_18 ;
if ( ! F_9 ( V_15 , V_19 ) )
return - V_20 ;
V_18 = F_6 ( V_3 , V_21 ) ;
if ( V_18 != 0x4D )
return - V_20 ;
if ( F_6 ( V_3 , 0x04 ) != 0x4D
|| F_6 ( V_3 , 0x06 ) != 0x4D
|| F_6 ( V_3 , 0xff ) != 0x4D )
return - V_20 ;
V_16 = F_6 ( V_3 , V_7 ) ;
if ( ( V_16 & 0x0f ) != 0x00 )
return - V_20 ;
if ( F_6 ( V_3 , 0x04 ) != V_16
|| F_6 ( V_3 , 0x06 ) != V_16
|| F_6 ( V_3 , 0xff ) != V_16 )
return - V_20 ;
V_17 = F_6 ( V_3 , V_22 ) ;
if ( ( V_17 & 0x2b ) != 0x00 )
return - V_20 ;
F_10 ( V_13 -> type , L_1 , V_23 ) ;
return 0 ;
}
static struct V_5 * F_11 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
struct V_5 * V_6 = F_5 ( V_3 ) ;
T_2 V_1 , V_26 ;
F_13 ( & V_6 -> V_27 ) ;
if ( F_14 ( V_28 , V_6 -> V_29 + V_30 ) || ! V_6 -> V_31 ) {
F_15 ( & V_3 -> V_25 , L_2 ) ;
V_1 = F_6 ( V_3 ,
V_32 ) ;
V_26 = ( V_1 >> 6 ) & 3 ;
V_1 = F_6 ( V_3 ,
V_33 ) ;
V_1 = ( V_1 << 2 ) | V_26 ;
V_6 -> V_34 [ 0 ] = V_1 ;
V_1 = F_6 ( V_3 ,
V_35 ) ;
V_26 = ( V_1 >> 6 ) & 3 ;
V_1 = F_6 ( V_3 ,
V_36 ) ;
V_1 = ( V_1 << 2 ) | V_26 ;
V_6 -> V_34 [ 1 ] = V_1 ;
V_6 -> V_37 = F_6 ( V_3 ,
V_22 ) ;
V_6 -> V_29 = V_28 ;
V_6 -> V_31 = 1 ;
}
F_16 ( & V_6 -> V_27 ) ;
return V_6 ;
}
static T_3 F_17 ( struct V_24 * V_25 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_5 * V_6 = F_11 ( V_25 ) ;
struct V_41 * V_42 = F_18 ( V_39 ) ;
return sprintf ( V_40 , L_3 ,
F_1 ( V_6 -> V_34 [ V_42 -> V_43 ] ) ) ;
}
static T_3 F_19 ( struct V_24 * V_25 , struct V_38 * V_42 ,
char * V_40 )
{
struct V_5 * V_6 = F_11 ( V_25 ) ;
struct V_44 * V_45 = F_20 ( V_42 ) ;
return sprintf ( V_40 , L_3 , F_2 ( V_6 -> V_9 [ V_45 -> V_46 ] ) ) ;
}
static T_3 F_21 ( struct V_24 * V_25 , struct V_38 * V_42 ,
const char * V_40 , T_4 V_47 )
{
unsigned long V_1 ;
int V_48 ;
struct V_2 * V_3 = F_12 ( V_25 ) ;
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_44 * V_45 = F_20 ( V_42 ) ;
V_48 = F_22 ( V_40 , 10 , & V_1 ) ;
if ( V_48 < 0 )
return V_48 ;
F_13 ( & V_6 -> V_27 ) ;
V_6 -> V_9 [ V_45 -> V_46 ] = F_23 ( F_3 ( V_1 ) , 0 , 255 ) ;
F_7 ( V_3 , V_45 -> V_43 ,
V_6 -> V_9 [ V_45 -> V_46 ] ) ;
F_16 ( & V_6 -> V_27 ) ;
return V_47 ;
}
static T_3 F_24 ( struct V_24 * V_25 , struct V_38 * V_42 ,
char * V_40 )
{
int V_49 = F_18 ( V_42 ) -> V_43 ;
struct V_5 * V_6 = F_11 ( V_25 ) ;
return sprintf ( V_40 , L_3 , ( V_6 -> V_37 >> V_49 ) & 1 ) ;
}
static int F_25 ( struct V_2 * V_50 ,
const struct V_51 * V_52 )
{
struct V_5 * V_6 ;
int V_48 ;
V_6 = F_26 ( & V_50 -> V_25 , sizeof( struct V_5 ) ,
V_53 ) ;
if ( ! V_6 )
return - V_54 ;
F_27 ( V_50 , V_6 ) ;
F_28 ( & V_6 -> V_27 ) ;
F_4 ( V_50 ) ;
V_48 = F_29 ( & V_50 -> V_25 . V_55 , & V_56 ) ;
if ( V_48 )
return V_48 ;
V_6 -> V_57 = F_30 ( & V_50 -> V_25 ) ;
if ( F_31 ( V_6 -> V_57 ) ) {
V_48 = F_32 ( V_6 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_33 ( & V_50 -> V_25 . V_55 , & V_56 ) ;
return V_48 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
F_35 ( V_6 -> V_57 ) ;
F_33 ( & V_3 -> V_25 . V_55 , & V_56 ) ;
return 0 ;
}
