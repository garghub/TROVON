static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_2 ( V_4 -> V_5 , V_6 , 0x7f , 0 ) ;
F_3 ( V_4 -> V_7 , 1 , V_8 | V_9 ) ;
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 , unsigned char * V_13 , int V_14 )
{
if ( V_14 < V_15 )
return - V_16 ;
V_12 -> V_17 = ( V_13 [ V_18 ] >> 4 ) * 1000
+ ( V_13 [ V_18 ] & 0xf ) * 100
+ ( V_13 [ V_19 ] >> 4 ) * 10
+ ( V_13 [ V_19 ] & 0xf ) ;
V_12 -> V_17 -= 1900 ;
V_12 -> V_20 = ( ( V_13 [ V_21 ] >> 4 ) & 0x01 ) * 10
+ ( V_13 [ V_21 ] & 0x0f ) ;
V_12 -> V_22 = ( ( V_13 [ V_23 ] >> 4 ) & 0x03 ) * 10
+ ( V_13 [ V_23 ] & 0x0f ) ;
V_12 -> V_24 = V_13 [ V_25 ] & 0x07 ;
if ( V_13 [ V_26 ] & V_27 ) {
V_12 -> V_28 = ( ( V_13 [ V_26 ] >> 4 ) & 0x1 ) * 10
+ ( V_13 [ V_26 ] & 0x0f ) ;
if ( V_13 [ V_26 ] & V_29 )
V_12 -> V_28 += 12 ;
} else
V_12 -> V_28 = ( ( V_13 [ V_26 ] >> 4 ) & 0x03 ) * 10
+ ( V_13 [ V_26 ] & 0x0f ) ;
V_12 -> V_30 = ( ( V_13 [ V_31 ] >> 4 ) & 0x7 ) * 10
+ ( V_13 [ V_31 ] & 0x0f ) ;
V_12 -> V_32 = ( ( V_13 [ V_33 ] >> 4 ) & 0x7 ) * 10
+ ( V_13 [ V_33 ] & 0x0f ) ;
return 0 ;
}
static int F_5 ( unsigned char * V_13 , struct V_11 * V_12 , int V_14 )
{
unsigned char V_34 , V_35 ;
if ( V_14 < V_15 )
return - V_16 ;
V_34 = ( V_12 -> V_17 + 1900 ) / 1000 ;
V_35 = ( V_12 -> V_17 + 1900 ) / 100 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_18 ] = ( V_34 << 4 ) + V_35 ;
V_34 = ( V_12 -> V_17 + 1900 ) / 10 ;
V_35 = V_12 -> V_17 + 1900 ;
V_35 = V_35 - V_34 * 10 ;
V_34 = V_34 - ( V_34 / 10 ) * 10 ;
V_13 [ V_19 ] = ( V_34 << 4 ) + V_35 ;
V_34 = V_12 -> V_20 / 10 ;
V_35 = V_12 -> V_20 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_21 ] = ( V_34 << 4 ) + V_35 ;
V_34 = V_12 -> V_22 / 10 ;
V_35 = V_12 -> V_22 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_23 ] = ( V_34 << 4 ) + V_35 ;
V_13 [ V_25 ] = V_12 -> V_24 ;
V_34 = V_12 -> V_28 / 10 ;
V_35 = V_12 -> V_28 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_26 ] = ( V_34 << 4 ) + V_35 ;
V_34 = V_12 -> V_30 / 10 ;
V_35 = V_12 -> V_30 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_31 ] = ( V_34 << 4 ) + V_35 ;
V_34 = V_12 -> V_32 / 10 ;
V_35 = V_12 -> V_32 ;
V_35 = V_35 - V_34 * 10 ;
V_13 [ V_33 ] = ( V_34 << 4 ) + V_35 ;
return 0 ;
}
static int F_6 ( struct V_36 * V_37 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_7 ( V_37 ) ;
unsigned char V_13 [ V_15 ] ;
int V_38 ;
V_38 = F_8 ( V_4 -> V_5 , V_39 , V_15 , V_13 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_4 ( V_12 , V_13 , V_15 ) ;
V_40:
return V_38 ;
}
static int F_9 ( struct V_36 * V_37 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_7 ( V_37 ) ;
unsigned char V_13 [ V_15 ] ;
int V_38 ;
V_38 = F_5 ( V_13 , V_12 , V_15 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_10 ( V_4 -> V_5 , V_39 , V_15 , V_13 ) ;
V_40:
return V_38 ;
}
static int F_11 ( struct V_36 * V_37 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_7 ( V_37 ) ;
unsigned char V_13 [ V_15 ] ;
int V_38 ;
V_38 = F_8 ( V_4 -> V_5 , V_43 , V_15 , V_13 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_4 ( & V_42 -> time , V_13 , V_15 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_12 ( V_4 -> V_5 , V_44 ) ;
if ( V_38 < 0 )
goto V_40;
if ( V_38 & V_45 ) {
V_42 -> V_46 = 0 ;
} else {
V_38 = F_12 ( V_4 -> V_5 , V_6 ) ;
if ( V_38 < 0 )
goto V_40;
if ( ! V_38 )
V_42 -> V_46 = 0 ;
else
V_42 -> V_46 = 1 ;
}
V_38 = F_12 ( V_4 -> V_5 , V_47 ) ;
if ( V_38 < 0 )
goto V_40;
if ( V_38 & V_48 )
V_42 -> V_49 = 1 ;
else
V_42 -> V_49 = 0 ;
return 0 ;
V_40:
return V_38 ;
}
static int F_13 ( struct V_36 * V_37 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_7 ( V_37 ) ;
unsigned char V_13 [ V_15 ] ;
int V_38 ;
V_38 = F_5 ( V_13 , & V_42 -> time , V_15 ) ;
if ( V_38 < 0 )
goto V_40;
V_38 = F_10 ( V_4 -> V_5 , V_43 , V_15 , V_13 ) ;
if ( V_38 < 0 )
goto V_40;
if ( V_42 -> V_46 )
V_38 = F_14 ( V_4 -> V_5 , V_6 , 0x77 ) ;
else
V_38 = F_14 ( V_4 -> V_5 , V_6 , 0x0 ) ;
if ( V_38 < 0 )
goto V_40;
V_40:
return V_38 ;
}
static int T_2 F_15 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_7 ( V_51 -> V_37 . V_54 ) ;
struct V_3 * V_4 ;
int V_1 , V_38 ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_55 ) ;
if ( ! V_4 )
return - V_56 ;
V_4 -> V_53 = V_53 ;
V_4 -> V_5 = V_53 -> V_5 ;
V_4 -> V_37 = & V_51 -> V_37 ;
V_1 = V_53 -> V_57 + V_58 ;
V_38 = F_17 ( V_1 , NULL , F_1 ,
V_59 , L_1 , V_4 ) ;
if ( V_38 < 0 ) {
F_18 ( V_53 -> V_37 , L_2 ,
V_1 , V_38 ) ;
goto V_60;
}
F_19 ( & V_51 -> V_37 , V_4 ) ;
F_20 ( V_51 , V_4 ) ;
F_21 ( & V_51 -> V_37 , 1 ) ;
V_4 -> V_7 = F_22 ( L_3 , & V_51 -> V_37 ,
& V_61 , V_62 ) ;
V_38 = F_23 ( V_4 -> V_7 ) ;
if ( F_24 ( V_4 -> V_7 ) ) {
F_18 ( & V_51 -> V_37 , L_4 , V_38 ) ;
goto V_63;
}
return 0 ;
V_63:
F_20 ( V_51 , NULL ) ;
F_25 ( V_53 -> V_57 + V_58 , V_4 ) ;
V_60:
F_26 ( V_4 ) ;
return V_38 ;
}
static int T_3 F_27 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = F_28 ( V_51 ) ;
if ( V_4 ) {
F_25 ( V_4 -> V_53 -> V_57 + V_58 , V_4 ) ;
F_29 ( V_4 -> V_7 ) ;
F_26 ( V_4 ) ;
}
return 0 ;
}
static int F_30 ( struct V_36 * V_37 )
{
struct V_50 * V_51 = F_31 ( V_37 ) ;
struct V_52 * V_53 = F_7 ( V_51 -> V_37 . V_54 ) ;
if ( F_32 ( V_37 ) )
V_53 -> V_64 |= 1 << V_58 ;
return 0 ;
}
static int F_33 ( struct V_36 * V_37 )
{
struct V_50 * V_51 = F_31 ( V_37 ) ;
struct V_52 * V_53 = F_7 ( V_51 -> V_37 . V_54 ) ;
if ( F_32 ( V_37 ) )
V_53 -> V_64 &= ~ ( 1 << V_58 ) ;
return 0 ;
}
