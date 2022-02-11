static inline unsigned char F_1 ( unsigned V_1 , unsigned div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static inline long F_3 ( T_1 V_2 )
{
long V_3 ;
V_2 >>= 4 ;
if ( V_2 < 0x0800 )
V_3 = 625 * ( long ) V_2 ;
else
V_3 = ( ( long ) V_2 - 0x01000 ) * 625 ;
return V_3 / 10 ;
}
static T_2 F_4 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_7 ( V_12 -> V_13 [ V_9 ] ) ) ;
}
static T_2 F_8 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_3 V_14 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_15 * V_16 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_16 ) ;
long V_17 = F_11 ( V_8 , NULL , 10 ) ;
F_12 ( & V_12 -> V_18 ) ;
V_12 -> V_19 [ V_9 ] = F_1 ( V_17 , F_7 ( V_12 -> V_13 [ V_9 ] ) ) ;
F_13 ( V_16 , F_14 ( V_9 + 1 ) , V_12 -> V_19 [ V_9 ] ) ;
F_15 ( & V_12 -> V_18 ) ;
return V_14 ;
}
static T_2 F_16 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_3 V_14 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_15 * V_16 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_16 ) ;
unsigned long V_20 , V_17 = F_11 ( V_8 , NULL , 10 ) ;
T_4 V_21 ;
F_12 ( & V_12 -> V_18 ) ;
V_20 = F_17 ( V_12 -> V_19 [ V_9 ] ,
F_7 ( V_12 -> V_13 [ V_9 ] ) ) ;
switch ( V_17 ) {
case 1 :
V_12 -> V_13 [ V_9 ] = 0 ;
break;
case 2 :
V_12 -> V_13 [ V_9 ] = 1 ;
break;
case 4 :
V_12 -> V_13 [ V_9 ] = 2 ;
break;
case 8 :
V_12 -> V_13 [ V_9 ] = 3 ;
break;
default:
F_18 ( & V_16 -> V_5 , L_2
L_3 , V_17 ) ;
F_15 ( & V_12 -> V_18 ) ;
return - V_22 ;
}
V_21 = ( F_19 ( V_16 , V_23 ) & ~ ( 3 << ( 2 * ( V_9 + 1 ) ) ) )
| ( V_12 -> V_13 [ V_9 ] << ( 2 * ( V_9 + 1 ) ) ) ;
F_13 ( V_16 , V_23 , V_21 ) ;
V_12 -> V_19 [ V_9 ] = F_1 ( V_20 , F_7 ( V_12 -> V_13 [ V_9 ] ) ) ;
F_13 ( V_16 , F_14 ( V_9 + 1 ) , V_12 -> V_19 [ V_9 ] ) ;
F_15 ( & V_12 -> V_18 ) ;
return V_14 ;
}
static T_2 F_20 ( struct V_4 * V_5 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
return sprintf ( V_8 , L_4 , F_3 ( V_12 -> V_2 ) ) ;
}
static T_2 F_21 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
return sprintf ( V_8 , L_5 , V_12 -> V_24 ) ;
}
static T_2 F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
int V_25 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
return sprintf ( V_8 , L_5 , ( V_12 -> V_24 >> V_25 ) & 1 ) ;
}
static int F_23 ( struct V_15 * V_16 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_16 -> V_29 ;
int V_30 , V_31 ;
if ( ! F_24 ( V_29 , V_32 ) )
return - V_33 ;
if ( F_19 ( V_16 , V_34 ) & 0xc0 )
return - V_33 ;
for ( V_30 = 0x2a ; V_30 <= 0x3d ; V_30 ++ ) {
V_31 = F_25 ( V_16 , V_30 ) ;
if ( ( F_25 ( V_16 , V_30 + 0x40 ) != V_31 )
|| ( F_25 ( V_16 , V_30 + 0x80 ) != V_31 )
|| ( F_25 ( V_16 , V_30 + 0xc0 ) != V_31 ) )
return - V_33 ;
}
F_26 ( V_27 -> type , L_6 , V_35 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 ,
const struct V_36 * V_37 )
{
struct V_11 * V_12 ;
int V_38 ;
V_12 = F_28 ( sizeof( struct V_11 ) , V_39 ) ;
if ( ! V_12 ) {
V_38 = - V_40 ;
goto exit;
}
F_29 ( V_16 , V_12 ) ;
F_30 ( & V_12 -> V_18 ) ;
F_31 ( V_16 ) ;
V_12 -> V_19 [ 0 ] = F_19 ( V_16 , F_14 ( 1 ) ) ;
V_12 -> V_19 [ 1 ] = F_19 ( V_16 , F_14 ( 2 ) ) ;
V_38 = F_32 ( & V_16 -> V_5 . V_41 , & V_42 ) ;
if ( V_38 )
goto V_43;
V_12 -> V_44 = F_33 ( & V_16 -> V_5 ) ;
if ( F_34 ( V_12 -> V_44 ) ) {
V_38 = F_35 ( V_12 -> V_44 ) ;
goto V_45;
}
return 0 ;
V_45:
F_36 ( & V_16 -> V_5 . V_41 , & V_42 ) ;
V_43:
F_37 ( V_12 ) ;
exit:
return V_38 ;
}
static int F_38 ( struct V_15 * V_16 )
{
struct V_11 * V_12 = F_10 ( V_16 ) ;
F_39 ( V_12 -> V_44 ) ;
F_36 ( & V_16 -> V_5 . V_41 , & V_42 ) ;
F_37 ( V_12 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 , T_4 V_21 )
{
return F_25 ( V_16 , V_21 ) ;
}
static int F_13 ( struct V_15 * V_16 , T_4 V_21 , T_4 V_46 )
{
return F_40 ( V_16 , V_21 , V_46 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
F_13 ( V_16 , V_47 , 0x80 ) ;
F_13 ( V_16 , V_48 , 0x08 ) ;
F_13 ( V_16 , V_47 , 0x01 ) ;
}
static struct V_11 * F_6 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_16 ) ;
int V_30 ;
F_12 ( & V_12 -> V_18 ) ;
if ( F_41 ( V_49 , V_12 -> V_50 + 2 * V_51 ) || ! V_12 -> V_52 ) {
F_42 ( & V_16 -> V_5 , L_7 ) ;
for ( V_30 = 0 ; V_30 <= 6 ; V_30 ++ ) {
V_12 -> V_53 [ V_30 ] =
F_19 ( V_16 , F_43 ( V_30 ) ) ;
V_12 -> V_54 [ V_30 ] =
F_19 ( V_16 , F_44 ( V_30 ) ) ;
V_12 -> V_55 [ V_30 ] =
F_19 ( V_16 , F_45 ( V_30 ) ) ;
}
V_12 -> V_56 [ 0 ] = F_19 ( V_16 , V_57 ) ;
V_12 -> V_19 [ 0 ] =
F_19 ( V_16 , F_14 ( 1 ) ) ;
V_12 -> V_56 [ 1 ] = F_19 ( V_16 , V_58 ) ;
V_12 -> V_19 [ 1 ] =
F_19 ( V_16 , F_14 ( 2 ) ) ;
V_12 -> V_2 =
( F_19 ( V_16 , V_59 ) << 8 ) |
( F_19 ( V_16 , V_48 ) & 0xf0 ) ;
V_12 -> V_60 =
F_19 ( V_16 , V_61 ) ;
V_12 -> V_62 =
F_19 ( V_16 , V_63 ) ;
V_12 -> V_64 =
F_19 ( V_16 , V_65 ) ;
V_12 -> V_66 =
F_19 ( V_16 , V_67 ) ;
V_30 = F_19 ( V_16 , V_23 ) ;
V_12 -> V_13 [ 0 ] = ( V_30 >> 2 ) & 0x03 ;
V_12 -> V_13 [ 1 ] = ( V_30 >> 4 ) & 0x03 ;
V_12 -> V_24 = F_19 ( V_16 , V_68 ) +
( F_19 ( V_16 , V_34 ) << 8 ) ;
V_12 -> V_50 = V_49 ;
V_12 -> V_52 = 1 ;
}
F_15 ( & V_12 -> V_18 ) ;
return V_12 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_69 ) ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_69 ) ;
}
