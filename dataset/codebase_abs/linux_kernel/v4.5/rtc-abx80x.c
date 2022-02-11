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
static T_2 F_12 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_33 * V_34 = F_13 ( V_2 ) ;
int V_35 ;
V_35 = F_14 ( V_2 , V_36 ) ;
if ( V_35 < 0 )
return V_37 ;
if ( V_35 & V_38 )
F_15 ( V_34 , 1 , V_39 | V_40 ) ;
F_2 ( V_2 , V_36 , 0 ) ;
return V_41 ;
}
static int F_16 ( struct V_11 * V_7 , struct V_42 * V_43 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned char V_14 [ 7 ] ;
int V_44 , V_4 ;
if ( V_2 -> V_31 <= 0 )
return - V_30 ;
V_4 = F_6 ( V_2 , V_45 ,
sizeof( V_14 ) , V_14 ) ;
if ( V_4 )
return V_4 ;
V_44 = F_14 ( V_2 , V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
V_43 -> time . V_16 = F_7 ( V_14 [ 0 ] & 0x7F ) ;
V_43 -> time . V_18 = F_7 ( V_14 [ 1 ] & 0x7F ) ;
V_43 -> time . V_20 = F_7 ( V_14 [ 2 ] & 0x3F ) ;
V_43 -> time . V_24 = F_7 ( V_14 [ 3 ] & 0x3F ) ;
V_43 -> time . V_26 = F_7 ( V_14 [ 4 ] & 0x1F ) - 1 ;
V_43 -> time . V_22 = V_14 [ 5 ] & 0x7 ;
V_43 -> V_47 = ! ! ( V_44 & V_48 ) ;
V_43 -> V_49 = ( V_14 [ 6 ] & V_38 ) && V_43 -> V_47 ;
return V_4 ;
}
static int F_17 ( struct V_11 * V_7 , struct V_42 * V_43 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_50 [ 6 ] ;
int V_4 ;
if ( V_2 -> V_31 <= 0 )
return - V_30 ;
V_50 [ 0 ] = 0x0 ;
V_50 [ 1 ] = F_10 ( V_43 -> time . V_16 ) ;
V_50 [ 2 ] = F_10 ( V_43 -> time . V_18 ) ;
V_50 [ 3 ] = F_10 ( V_43 -> time . V_20 ) ;
V_50 [ 4 ] = F_10 ( V_43 -> time . V_24 ) ;
V_50 [ 5 ] = F_10 ( V_43 -> time . V_26 + 1 ) ;
V_4 = F_11 ( V_2 , V_51 ,
sizeof( V_50 ) , V_50 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_6 ) ;
return - V_8 ;
}
if ( V_43 -> V_47 ) {
V_4 = F_2 ( V_2 , V_46 ,
( V_52 |
V_48 ) ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static int F_18 ( struct V_11 * V_7 , unsigned int V_47 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_4 ;
if ( V_47 )
V_4 = F_2 ( V_2 , V_46 ,
( V_52 |
V_48 ) ) ;
else
V_4 = F_2 ( V_2 , V_46 ,
V_52 ) ;
return V_4 ;
}
static int F_19 ( struct V_53 * V_54 )
{
const char * V_55 ;
int V_3 = 0 ;
int V_56 , V_57 ;
T_3 V_58 ;
V_57 = F_20 ( V_54 , L_7 , & V_55 ) ;
if ( V_57 )
return V_57 ;
if ( ! strcmp ( V_55 , L_8 ) )
V_3 |= V_59 ;
else if ( ! strcmp ( V_55 , L_9 ) )
V_3 |= V_60 ;
else
return - V_30 ;
V_57 = F_21 ( V_54 , L_10 , & V_58 ) ;
if ( V_57 )
return V_57 ;
for ( V_56 = 0 ; V_56 < sizeof( V_61 ) ; V_56 ++ )
if ( V_61 [ V_56 ] == V_58 )
break;
if ( V_56 == sizeof( V_61 ) )
return - V_30 ;
return ( V_3 | V_56 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_53 * V_54 = V_2 -> V_7 . V_64 ;
struct V_33 * V_34 ;
int V_56 , V_65 , V_4 , V_3 = - V_30 ;
char V_14 [ 7 ] ;
unsigned int V_66 = V_63 -> V_67 ;
unsigned int V_68 ;
unsigned int V_69 , V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
if ( ! F_23 ( V_2 -> V_74 , V_75 ) )
return - V_76 ;
V_4 = F_6 ( V_2 , V_77 ,
sizeof( V_14 ) , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_11 ) ;
return - V_8 ;
}
V_68 = ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ;
V_69 = V_14 [ 2 ] >> 3 ;
V_70 = V_14 [ 2 ] & 0x7 ;
V_71 = ( ( V_14 [ 4 ] & 0x80 ) << 2 ) | ( ( V_14 [ 6 ] & 0x80 ) << 1 ) | V_14 [ 3 ] ;
V_73 = ( ( V_14 [ 4 ] & 0x7f ) << 8 ) | V_14 [ 5 ] ;
V_72 = ( V_14 [ 6 ] & 0x7c ) >> 2 ;
F_24 ( & V_2 -> V_7 , L_12 ,
V_68 , V_69 , V_70 , V_71 , V_72 , V_73 ) ;
V_65 = F_14 ( V_2 , V_78 ) ;
if ( V_65 < 0 ) {
F_3 ( & V_2 -> V_7 , L_13 ) ;
return - V_8 ;
}
V_4 = F_2 ( V_2 , V_78 ,
( ( V_65 & ~ ( V_79 |
V_80 ) ) |
V_81 ) ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_7 , L_14 ) ;
return - V_8 ;
}
if ( V_66 == V_82 ) {
for ( V_56 = 0 ; V_83 [ V_56 ] . V_84 ; V_56 ++ )
if ( V_68 == V_83 [ V_56 ] . V_84 )
break;
if ( V_83 [ V_56 ] . V_84 == 0 ) {
F_3 ( & V_2 -> V_7 , L_15 ,
V_68 ) ;
return - V_30 ;
}
V_66 = V_56 ;
}
if ( V_68 != V_83 [ V_66 ] . V_84 ) {
F_3 ( & V_2 -> V_7 , L_16 ,
V_68 , V_83 [ V_66 ] . V_84 ) ;
return - V_30 ;
}
if ( V_54 && V_83 [ V_66 ] . V_85 )
V_3 = F_19 ( V_54 ) ;
if ( V_3 > 0 ) {
F_24 ( & V_2 -> V_7 , L_17 ,
V_3 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_4 = F_2 ( V_2 , V_86 ,
F_25 ( 2 ) ) ;
if ( V_4 )
return V_4 ;
V_34 = F_26 ( & V_2 -> V_7 , L_18 ,
& V_87 , V_88 ) ;
if ( F_27 ( V_34 ) )
return F_28 ( V_34 ) ;
F_29 ( V_2 , V_34 ) ;
if ( V_2 -> V_31 > 0 ) {
F_24 ( & V_2 -> V_7 , L_19 , V_2 -> V_31 ) ;
V_4 = F_30 ( & V_2 -> V_7 , V_2 -> V_31 , NULL ,
F_12 ,
V_89 | V_90 ,
L_18 ,
V_2 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_7 , L_20 ) ;
V_2 -> V_31 = 0 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
