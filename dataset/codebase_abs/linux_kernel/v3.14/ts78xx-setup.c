static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static unsigned char F_5 ( unsigned long V_2 )
{
F_6 ( V_2 , V_3 ) ;
return F_7 ( V_4 ) ;
}
static void F_8 ( unsigned char V_5 , unsigned long V_2 )
{
F_6 ( V_2 , V_3 ) ;
F_6 ( V_5 , V_4 ) ;
}
static int F_9 ( void )
{
int V_6 ;
unsigned char V_7 , V_8 ;
V_7 = F_5 ( 126 ) ;
V_8 = F_5 ( 127 ) ;
F_8 ( 0x00 , 126 ) ;
F_8 ( 0x55 , 127 ) ;
if ( F_5 ( 127 ) == 0x55 ) {
F_8 ( 0xaa , 127 ) ;
if ( F_5 ( 127 ) == 0xaa
&& F_5 ( 126 ) == 0x00 ) {
F_8 ( V_7 , 126 ) ;
F_8 ( V_8 , 127 ) ;
if ( V_9 . V_10 . V_11 . V_12 == 0 ) {
V_6 = F_10 ( & V_13 ) ;
if ( ! V_6 )
V_9 . V_10 . V_11 . V_12 = 1 ;
} else
V_6 = F_11 ( & V_13 ) ;
if ( V_6 )
F_12 ( L_1 ,
V_6 ) ;
return V_6 ;
}
}
F_12 ( L_2 ) ;
return - V_14 ;
}
static void F_13 ( void )
{
F_14 ( & V_13 ) ;
}
static void F_15 ( struct V_15 * V_16 , int V_17 ,
unsigned int V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
if ( V_18 & V_22 ) {
unsigned char V_23 ;
V_23 = ( V_18 & V_24 ) << 2 ;
V_23 |= V_18 & V_25 ;
V_23 |= ( V_18 & V_26 ) >> 2 ;
F_6 ( ( F_7 ( V_27 ) & ~ 0x7 ) | V_23 , V_27 ) ;
}
if ( V_17 != V_28 )
F_6 ( V_17 , V_20 -> V_29 ) ;
}
static int F_16 ( struct V_15 * V_16 )
{
return F_7 ( V_27 ) & 0x20 ;
}
static void F_17 ( struct V_15 * V_16 ,
const T_2 * V_30 , int V_31 )
{
struct V_19 * V_32 = V_16 -> V_21 ;
void T_3 * V_33 = V_32 -> V_29 ;
unsigned long V_34 = ( ( unsigned long ) V_30 & 3 ) ;
int V_35 ;
if ( V_34 ) {
V_35 = F_18 ( int , 4 - V_34 , V_31 ) ;
F_19 ( V_33 , V_30 , V_35 ) ;
V_30 += V_35 ;
V_31 -= V_35 ;
}
V_35 = V_31 >> 2 ;
if ( V_35 ) {
T_4 * V_36 = ( T_4 * ) V_30 ;
F_20 ( V_33 , V_36 , V_35 ) ;
V_30 += V_35 << 2 ;
V_31 -= V_35 << 2 ;
}
if ( V_31 )
F_19 ( V_33 , V_30 , V_31 ) ;
}
static void F_21 ( struct V_15 * V_16 ,
T_2 * V_30 , int V_31 )
{
struct V_19 * V_32 = V_16 -> V_21 ;
void T_3 * V_33 = V_32 -> V_37 ;
unsigned long V_34 = ( ( unsigned long ) V_30 & 3 ) ;
int V_35 ;
if ( V_34 ) {
V_35 = F_18 ( int , 4 - V_34 , V_31 ) ;
F_22 ( V_33 , V_30 , V_35 ) ;
V_30 += V_35 ;
V_31 -= V_35 ;
}
V_35 = V_31 >> 2 ;
if ( V_35 ) {
T_4 * V_36 = ( T_4 * ) V_30 ;
F_23 ( V_33 , V_36 , V_35 ) ;
V_30 += V_35 << 2 ;
V_31 -= V_35 << 2 ;
}
if ( V_31 )
F_22 ( V_33 , V_30 , V_31 ) ;
}
static int F_24 ( void )
{
int V_6 ;
if ( V_9 . V_10 . V_38 . V_12 == 0 ) {
V_6 = F_10 ( & V_39 ) ;
if ( ! V_6 )
V_9 . V_10 . V_38 . V_12 = 1 ;
} else
V_6 = F_11 ( & V_39 ) ;
if ( V_6 )
F_12 ( L_3 , V_6 ) ;
return V_6 ;
}
static void F_25 ( void )
{
F_14 ( & V_39 ) ;
}
static int F_26 ( void )
{
int V_6 ;
if ( V_9 . V_10 . V_40 . V_12 == 0 ) {
V_6 = F_10 ( & V_41 ) ;
if ( ! V_6 )
V_9 . V_10 . V_40 . V_12 = 1 ;
} else
V_6 = F_11 ( & V_41 ) ;
if ( V_6 )
F_12 ( L_4 , V_6 ) ;
return V_6 ;
}
static void F_27 ( void )
{
F_14 ( & V_41 ) ;
}
static void F_28 ( void )
{
V_9 . V_10 . V_11 . V_12 = 0 ;
V_9 . V_10 . V_38 . V_12 = 0 ;
V_9 . V_10 . V_40 . V_12 = 0 ;
}
static void F_29 ( void )
{
switch ( V_9 . V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_9 . V_10 . V_11 . V_52 = 1 ;
V_9 . V_10 . V_38 . V_52 = 1 ;
V_9 . V_10 . V_40 . V_52 = 1 ;
break;
default:
switch ( ( V_9 . V_42 >> 8 ) & 0xffffff ) {
case V_53 :
F_30 ( L_5 ,
V_9 . V_42 & 0xff ) ;
V_9 . V_10 . V_11 . V_52 = 1 ;
V_9 . V_10 . V_38 . V_52 = 1 ;
V_9 . V_10 . V_40 . V_52 = 1 ;
break;
default:
V_9 . V_10 . V_11 . V_52 = 0 ;
V_9 . V_10 . V_38 . V_52 = 0 ;
V_9 . V_10 . V_40 . V_52 = 0 ;
}
}
}
static int F_31 ( void )
{
int V_54 , V_55 = 0 ;
if ( V_9 . V_10 . V_11 . V_52 == 1 ) {
V_54 = F_9 () ;
if ( V_54 )
V_9 . V_10 . V_11 . V_52 = 0 ;
V_55 |= V_54 ;
}
if ( V_9 . V_10 . V_38 . V_52 == 1 ) {
V_54 = F_24 () ;
if ( V_54 )
V_9 . V_10 . V_38 . V_52 = 0 ;
V_55 |= V_54 ;
}
if ( V_9 . V_10 . V_40 . V_52 == 1 ) {
V_54 = F_26 () ;
if ( V_54 )
V_9 . V_10 . V_40 . V_52 = 0 ;
V_55 |= V_54 ;
}
return V_55 ;
}
static int F_32 ( void )
{
int V_55 = 0 ;
if ( V_9 . V_10 . V_11 . V_52 == 1 )
F_13 () ;
if ( V_9 . V_10 . V_38 . V_52 == 1 )
F_25 () ;
if ( V_9 . V_10 . V_40 . V_52 == 1 )
F_27 () ;
return V_55 ;
}
static int F_33 ( void )
{
V_9 . V_42 = F_34 ( V_56 ) ;
F_12 ( L_6 ,
( V_9 . V_42 >> 8 ) & 0xffffff ,
V_9 . V_42 & 0xff ) ;
F_29 () ;
if ( F_31 () ) {
V_9 . V_57 = - 1 ;
return - V_58 ;
}
return 0 ;
}
static int F_35 ( void )
{
unsigned int V_59 ;
V_59 = F_34 ( V_56 ) ;
if ( V_9 . V_42 != V_59 ) {
F_36 ( L_7
L_8 ,
( V_9 . V_42 >> 8 ) & 0xffffff , V_9 . V_42 & 0xff ,
( V_59 >> 8 ) & 0xffffff , V_59 & 0xff ) ;
V_9 . V_57 = - 1 ;
return - V_58 ;
}
if ( F_32 () ) {
V_9 . V_57 = - 1 ;
return - V_58 ;
}
return 0 ;
}
static T_5 F_37 ( struct V_60 * V_61 ,
struct V_62 * V_63 , char * V_30 )
{
if ( V_9 . V_57 < 0 )
return sprintf ( V_30 , L_9 ) ;
return sprintf ( V_30 , L_10 , ( V_9 . V_57 ) ? L_11 : L_12 ) ;
}
static T_5 F_38 ( struct V_60 * V_61 ,
struct V_62 * V_63 , const char * V_30 , T_6 V_64 )
{
int V_5 , V_55 ;
if ( V_9 . V_57 < 0 ) {
F_36 ( L_13 ) ;
return - V_58 ;
}
if ( strncmp ( V_30 , L_11 , sizeof( L_11 ) - 1 ) == 0 )
V_5 = 1 ;
else if ( strncmp ( V_30 , L_12 , sizeof( L_12 ) - 1 ) == 0 )
V_5 = 0 ;
else
return - V_65 ;
if ( V_9 . V_57 == V_5 )
return V_64 ;
V_55 = ( V_9 . V_57 == 0 )
? F_33 ()
: F_35 () ;
if ( ! ( V_55 < 0 ) )
V_9 . V_57 = V_5 ;
return V_64 ;
}
static void T_1 F_39 ( void )
{
int V_55 ;
F_40 () ;
F_41 ( V_66 ) ;
F_42 () ;
F_43 () ;
F_44 ( & V_67 ) ;
F_45 ( & V_68 ) ;
F_46 () ;
F_47 () ;
F_48 () ;
F_28 () ;
V_55 = F_33 () ;
V_55 = F_49 ( V_69 , & V_70 . V_63 ) ;
if ( V_55 )
F_36 ( L_14 , V_55 ) ;
}
