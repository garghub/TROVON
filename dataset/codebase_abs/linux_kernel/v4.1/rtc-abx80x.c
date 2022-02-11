static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 ,
V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_1 ) ;
return - V_8 ;
}
V_4 = F_2 ( V_2 , V_9 ,
V_10 |
V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_2 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_4 ( struct V_11 * V_7 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned char V_14 [ 8 ] ;
int V_4 ;
V_4 = F_6 ( V_2 , V_15 ,
sizeof( V_14 ) , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_3 ) ;
return - V_8 ;
}
V_13 -> V_16 = F_7 ( V_14 [ V_17 ] & 0x7F ) ;
V_13 -> V_18 = F_7 ( V_14 [ V_19 ] & 0x7F ) ;
V_13 -> V_20 = F_7 ( V_14 [ V_21 ] & 0x3F ) ;
V_13 -> V_22 = V_14 [ V_23 ] & 0x7 ;
V_13 -> V_24 = F_7 ( V_14 [ V_25 ] & 0x3F ) ;
V_13 -> V_26 = F_7 ( V_14 [ V_27 ] & 0x1F ) - 1 ;
V_13 -> V_28 = F_7 ( V_14 [ V_29 ] ) + 100 ;
V_4 = F_8 ( V_13 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_7 , L_4 ) ;
return V_4 ;
}
static int F_9 ( struct V_11 * V_7 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned char V_14 [ 8 ] ;
int V_4 ;
if ( V_13 -> V_28 < 100 )
return - V_30 ;
V_14 [ V_15 ] = 0 ;
V_14 [ V_17 ] = F_10 ( V_13 -> V_16 ) ;
V_14 [ V_19 ] = F_10 ( V_13 -> V_18 ) ;
V_14 [ V_21 ] = F_10 ( V_13 -> V_20 ) ;
V_14 [ V_25 ] = F_10 ( V_13 -> V_24 ) ;
V_14 [ V_27 ] = F_10 ( V_13 -> V_26 + 1 ) ;
V_14 [ V_29 ] = F_10 ( V_13 -> V_28 - 100 ) ;
V_14 [ V_23 ] = V_13 -> V_22 ;
V_4 = F_11 ( V_2 , V_15 ,
sizeof( V_14 ) , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_5 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_12 ( struct V_31 * V_32 )
{
const char * V_33 ;
int V_3 = 0 ;
int V_34 , V_35 ;
T_2 V_36 ;
V_35 = F_13 ( V_32 , L_6 , & V_33 ) ;
if ( V_35 )
return V_35 ;
if ( ! strcmp ( V_33 , L_7 ) )
V_3 |= V_37 ;
else if ( ! strcmp ( V_33 , L_8 ) )
V_3 |= V_38 ;
else
return - V_30 ;
V_35 = F_14 ( V_32 , L_9 , & V_36 ) ;
if ( V_35 )
return V_35 ;
for ( V_34 = 0 ; V_34 < sizeof( V_39 ) ; V_34 ++ )
if ( V_39 [ V_34 ] == V_36 )
break;
if ( V_34 == sizeof( V_39 ) )
return - V_30 ;
return ( V_3 | V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_31 * V_32 = V_2 -> V_7 . V_42 ;
struct V_43 * V_44 ;
int V_34 , V_45 , V_4 , V_3 = - V_30 ;
char V_14 [ 7 ] ;
unsigned int V_46 = V_41 -> V_47 ;
unsigned int V_48 ;
unsigned int V_49 , V_50 ;
unsigned int V_51 ;
unsigned int V_52 ;
unsigned int V_53 ;
if ( ! F_16 ( V_2 -> V_54 , V_55 ) )
return - V_56 ;
V_4 = F_6 ( V_2 , V_57 ,
sizeof( V_14 ) , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_10 ) ;
return - V_8 ;
}
V_48 = ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ;
V_49 = V_14 [ 2 ] >> 3 ;
V_50 = V_14 [ 2 ] & 0x7 ;
V_51 = ( ( V_14 [ 4 ] & 0x80 ) << 2 ) | ( ( V_14 [ 6 ] & 0x80 ) << 1 ) | V_14 [ 3 ] ;
V_53 = ( ( V_14 [ 4 ] & 0x7f ) << 8 ) | V_14 [ 5 ] ;
V_52 = ( V_14 [ 6 ] & 0x7c ) >> 2 ;
F_17 ( & V_2 -> V_7 , L_11 ,
V_48 , V_49 , V_50 , V_51 , V_52 , V_53 ) ;
V_45 = F_18 ( V_2 , V_58 ) ;
if ( V_45 < 0 ) {
F_3 ( & V_2 -> V_7 , L_12 ) ;
return - V_8 ;
}
V_4 = F_2 ( V_2 , V_58 ,
( ( V_45 & ~ V_59 ) |
V_60 ) ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_13 ) ;
return - V_8 ;
}
if ( V_46 == V_61 ) {
for ( V_34 = 0 ; V_62 [ V_34 ] . V_63 ; V_34 ++ )
if ( V_48 == V_62 [ V_34 ] . V_63 )
break;
if ( V_62 [ V_34 ] . V_63 == 0 ) {
F_3 ( & V_2 -> V_7 , L_14 ,
V_48 ) ;
return - V_30 ;
}
V_46 = V_34 ;
}
if ( V_48 != V_62 [ V_46 ] . V_63 ) {
F_3 ( & V_2 -> V_7 , L_15 ,
V_48 , V_62 [ V_46 ] . V_63 ) ;
return - V_30 ;
}
if ( V_32 && V_62 [ V_46 ] . V_64 )
V_3 = F_12 ( V_32 ) ;
if ( V_3 > 0 ) {
F_17 ( & V_2 -> V_7 , L_16 ,
V_3 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_44 = F_19 ( & V_2 -> V_7 , V_65 . V_66 . V_67 ,
& V_68 , V_69 ) ;
if ( F_20 ( V_44 ) )
return F_21 ( V_44 ) ;
F_22 ( V_2 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
