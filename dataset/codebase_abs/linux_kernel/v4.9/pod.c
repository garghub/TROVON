static char * F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
return F_2 ( & V_2 -> V_5 , V_6 , V_3 ,
V_4 ) ;
}
static void F_3 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
const unsigned char * V_8 = V_2 -> V_5 . V_9 ;
if ( memcmp ( V_8 , V_10 , sizeof( V_10 ) ) == 0 ) {
V_2 -> V_11 = V_8 [ 13 ] * 100 + V_8 [ 14 ] * 10 + V_8 [ 15 ] ;
V_2 -> V_12 = ( ( int ) V_8 [ 8 ] << 16 ) | ( ( int ) V_8 [ 9 ] << 8 ) |
( int ) V_8 [ 10 ] ;
F_4 ( V_2 ) ;
return;
}
if ( V_8 [ 0 ] != ( V_13 | V_14 ) &&
V_8 [ 0 ] != ( V_13 | V_15 ) ) {
return;
}
if ( memcmp ( V_8 + 1 , V_16 , sizeof( V_16 ) ) != 0 )
return;
if ( V_8 [ 5 ] == V_17 && V_8 [ 6 ] == V_18 ) {
short V_19 = ( ( int ) V_8 [ 7 ] << 12 ) | ( ( int ) V_8 [ 8 ] << 8 ) |
( ( int ) V_8 [ 9 ] << 4 ) | ( int ) V_8 [ 10 ] ;
V_2 -> V_20 = V_19 ;
}
}
static int F_5 ( struct V_1 * V_2 , int V_19 ,
int V_3 )
{
char * V_21 ;
static const int V_4 = 5 ;
V_21 = F_1 ( V_2 , V_17 , V_4 ) ;
if ( ! V_21 )
return - V_22 ;
V_21 [ V_23 ] = V_3 ;
V_21 [ V_23 + 1 ] = ( V_19 >> 12 ) & 0x0f ;
V_21 [ V_23 + 2 ] = ( V_19 >> 8 ) & 0x0f ;
V_21 [ V_23 + 3 ] = ( V_19 >> 4 ) & 0x0f ;
V_21 [ V_23 + 4 ] = ( V_19 ) & 0x0f ;
F_6 ( & V_2 -> V_5 , V_21 , V_4 ) ;
F_7 ( V_21 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_8 )
{
struct V_28 * V_29 = F_9 ( V_25 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
return sprintf ( V_8 , L_1 , V_2 -> V_31 ) ;
}
static T_1 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_8 )
{
struct V_28 * V_29 = F_9 ( V_25 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
return sprintf ( V_8 , L_2 , V_2 -> V_11 / 100 ,
V_2 -> V_11 % 100 ) ;
}
static T_1 F_11 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_8 )
{
struct V_28 * V_29 = F_9 ( V_25 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
return sprintf ( V_8 , L_3 , V_2 -> V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_32 , V_33 ) ;
F_14 ( & V_2 -> V_34 , V_35 , V_36 ,
( unsigned long ) V_2 ) ;
}
static void V_36 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_7 * V_5 = & V_2 -> V_5 ;
F_13 ( V_2 -> V_32 , V_38 ) ;
F_15 ( V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_32 , V_39 ) ;
F_16 ( & V_2 -> V_40 ) ;
}
static void F_17 ( struct V_41 * V_42 )
{
struct V_1 * V_2 =
F_18 ( V_42 , struct V_1 , V_40 ) ;
struct V_7 * V_5 = & V_2 -> V_5 ;
F_13 ( V_2 -> V_32 , V_43 ) ;
F_19 ( & V_2 -> V_5 , & V_2 -> V_31 ) ;
F_20 ( V_5 -> V_29 ) ;
}
static int F_21 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
V_47 -> type = V_48 ;
V_47 -> V_49 = 1 ;
V_47 -> V_19 . integer . V_50 = 0 ;
V_47 -> V_19 . integer . V_51 = 65535 ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_23 ( V_45 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_5 ;
V_53 -> V_19 . integer . V_19 [ 0 ] = V_2 -> V_20 ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_23 ( V_45 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_5 ;
if ( V_53 -> V_19 . integer . V_19 [ 0 ] == V_2 -> V_20 )
return 0 ;
V_2 -> V_20 = V_53 -> V_19 . integer . V_19 [ 0 ] ;
F_5 ( V_2 , V_53 -> V_19 . integer . V_19 [ 0 ] ,
V_18 ) ;
return 1 ;
}
static void F_25 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_26 ( & V_2 -> V_34 ) ;
F_27 ( & V_2 -> V_40 ) ;
}
static int F_28 ( struct V_7 * V_5 ,
const struct V_56 * V_57 )
{
int V_58 ;
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
V_5 -> V_59 = F_3 ;
V_5 -> V_60 = F_25 ;
F_29 ( & V_2 -> V_34 ) ;
F_30 ( & V_2 -> V_40 , F_17 ) ;
V_58 = F_31 ( V_5 -> V_29 , & V_61 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_32 ( V_5 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_33 ( V_5 , & V_62 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_34 ( V_5 -> V_29 ,
F_35 ( & V_63 , V_5 -> V_55 ) ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_2 -> V_5 . V_64 -> V_65 & V_66 ) {
V_2 -> V_20 = V_67 ;
F_12 ( V_2 ) ;
}
return 0 ;
}
static int F_36 ( struct V_68 * V_69 ,
const struct V_56 * V_57 )
{
return F_37 ( V_69 , V_57 , L_4 ,
& V_70 [ V_57 -> V_71 ] ,
F_28 , sizeof( struct V_1 ) ) ;
}
