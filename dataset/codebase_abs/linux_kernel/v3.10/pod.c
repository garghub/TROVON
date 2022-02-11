static char * F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
return F_2 ( & V_2 -> V_5 , V_6 , V_3 ,
V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
const unsigned char * V_7 = V_2 -> V_5 . V_8 ;
if ( memcmp ( V_7 , V_9 , sizeof( V_9 ) ) == 0 ) {
V_2 -> V_10 = V_7 [ 13 ] * 100 + V_7 [ 14 ] * 10 + V_7 [ 15 ] ;
V_2 -> V_11 = ( ( int ) V_7 [ 8 ] << 16 ) | ( ( int ) V_7 [ 9 ] << 8 ) |
( int ) V_7 [ 10 ] ;
F_4 ( V_2 ) ;
return;
}
if ( V_7 [ 0 ] != ( V_12 | V_13 ) &&
V_7 [ 0 ] != ( V_12 | V_14 ) ) {
return;
}
if ( memcmp ( V_7 + 1 , V_15 , sizeof( V_15 ) ) != 0 )
return;
if ( V_7 [ 5 ] == V_16 && V_7 [ 6 ] == V_17 ) {
short V_18 = ( ( int ) V_7 [ 7 ] << 12 ) | ( ( int ) V_7 [ 8 ] << 8 ) |
( ( int ) V_7 [ 9 ] << 4 ) | ( int ) V_7 [ 10 ] ;
V_2 -> V_19 = V_18 ;
}
}
void F_5 ( struct V_1 * V_2 , int V_20 ,
T_1 V_18 )
{
F_6 ( & V_2 -> V_5 , V_20 , V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_18 ,
int V_3 )
{
char * V_21 ;
static const int V_4 = 5 ;
V_21 = F_1 ( V_2 , V_16 , V_4 ) ;
if ( ! V_21 )
return - V_22 ;
V_21 [ V_23 ] = V_3 ;
V_21 [ V_23 + 1 ] = ( V_18 >> 12 ) & 0x0f ;
V_21 [ V_23 + 2 ] = ( V_18 >> 8 ) & 0x0f ;
V_21 [ V_23 + 3 ] = ( V_18 >> 4 ) & 0x0f ;
V_21 [ V_23 + 4 ] = ( V_18 ) & 0x0f ;
F_8 ( & V_2 -> V_5 , V_21 , V_4 ) ;
F_9 ( V_21 ) ;
return 0 ;
}
static T_2 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_11 ( V_25 ) ;
struct V_1 * V_2 = F_12 ( V_29 ) ;
return sprintf ( V_7 , L_1 , V_2 -> V_30 ) ;
}
static T_2 F_13 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_7 )
{
struct V_28 * V_29 = F_11 ( V_25 ) ;
struct V_1 * V_2 = F_12 ( V_29 ) ;
return sprintf ( V_7 , L_2 , V_2 -> V_10 / 100 ,
V_2 -> V_10 % 100 ) ;
}
static T_2 F_14 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_11 ( V_25 ) ;
struct V_1 * V_2 = F_12 ( V_29 ) ;
return sprintf ( V_7 , L_1 , V_2 -> V_11 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_31 , V_32 ) ;
F_17 ( & V_2 -> V_33 , V_34 , V_35 ,
( unsigned long ) V_2 ) ;
}
static void V_35 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
struct V_37 * V_5 = & V_2 -> V_5 ;
F_16 ( V_2 -> V_31 , V_38 ) ;
F_18 ( V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_31 , V_39 ) ;
F_19 ( & V_2 -> V_40 ) ;
}
static void F_20 ( struct V_41 * V_42 )
{
struct V_1 * V_2 =
F_21 ( V_42 , struct V_1 , V_40 ) ;
struct V_37 * V_5 = & V_2 -> V_5 ;
F_16 ( V_2 -> V_31 , V_43 ) ;
F_22 ( & V_2 -> V_5 , & V_2 -> V_30 ) ;
F_23 ( V_5 ) ;
}
static int F_24 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
V_47 -> type = V_48 ;
V_47 -> V_49 = 1 ;
V_47 -> V_18 . integer . V_50 = 0 ;
V_47 -> V_18 . integer . V_51 = 65535 ;
return 0 ;
}
static int F_25 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_45 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_5 ;
V_53 -> V_18 . integer . V_18 [ 0 ] = V_2 -> V_19 ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_45 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_5 ;
if ( V_53 -> V_18 . integer . V_18 [ 0 ] == V_2 -> V_19 )
return 0 ;
V_2 -> V_19 = V_53 -> V_18 . integer . V_18 [ 0 ] ;
F_7 ( V_2 , V_53 -> V_18 . integer . V_18 [ 0 ] ,
V_17 ) ;
return 1 ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_12 ( V_29 ) ;
if ( V_2 == NULL )
return;
F_29 ( & V_2 -> V_5 ) ;
F_30 ( & V_2 -> V_33 ) ;
F_31 ( & V_2 -> V_40 ) ;
}
static int F_32 ( struct V_24 * V_25 )
{
int V_56 ;
F_33 ( F_34 ( V_25 , & V_57 ) ) ;
F_33 ( F_34 ( V_25 , & V_58 ) ) ;
F_33 ( F_34 ( V_25 , & V_59 ) ) ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 ,
struct V_1 * V_2 )
{
int V_56 ;
struct V_37 * V_5 = & V_2 -> V_5 ;
F_36 ( & V_2 -> V_33 ) ;
F_37 ( & V_2 -> V_40 , F_20 ) ;
if ( ( V_29 == NULL ) || ( V_2 == NULL ) )
return - V_60 ;
V_56 = F_32 ( & V_29 -> V_25 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_38 ( V_5 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_39 ( V_5 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_40 ( V_5 , & V_61 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_41 ( V_5 -> V_62 ,
F_42 ( & V_63 , V_5 -> V_55 ) ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_2 -> V_5 . V_64 -> V_65 & V_66 ) {
V_2 -> V_19 = V_67 ;
F_15 ( V_2 ) ;
}
return 0 ;
}
int F_43 ( struct V_28 * V_29 , struct V_1 * V_2 )
{
int V_56 = F_35 ( V_29 , V_2 ) ;
if ( V_56 < 0 )
F_28 ( V_29 ) ;
return V_56 ;
}
void F_44 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
if ( V_29 == NULL )
return;
V_2 = F_12 ( V_29 ) ;
if ( V_2 != NULL ) {
struct V_54 * V_55 = V_2 -> V_5 . V_55 ;
struct V_24 * V_25 = & V_29 -> V_25 ;
if ( V_55 != NULL )
F_45 ( V_55 ) ;
if ( V_25 != NULL ) {
F_46 ( V_25 , & V_57 ) ;
F_46 ( V_25 , & V_58 ) ;
F_46 ( V_25 , & V_59 ) ;
}
}
F_28 ( V_29 ) ;
}
