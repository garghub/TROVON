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
struct V_19 * V_20 = F_16 ( V_16 ) ;
if ( V_18 & V_21 ) {
unsigned char V_22 ;
V_22 = ( V_18 & V_23 ) << 2 ;
V_22 |= V_18 & V_24 ;
V_22 |= ( V_18 & V_25 ) >> 2 ;
F_6 ( ( F_7 ( V_26 ) & ~ 0x7 ) | V_22 , V_26 ) ;
}
if ( V_17 != V_27 )
F_6 ( V_17 , V_20 -> V_28 ) ;
}
static int F_17 ( struct V_15 * V_16 )
{
return F_7 ( V_26 ) & 0x20 ;
}
static void F_18 ( struct V_15 * V_16 ,
const T_2 * V_29 , int V_30 )
{
struct V_19 * V_31 = F_16 ( V_16 ) ;
void T_3 * V_32 = V_31 -> V_28 ;
unsigned long V_33 = ( ( unsigned long ) V_29 & 3 ) ;
int V_34 ;
if ( V_33 ) {
V_34 = F_19 ( int , 4 - V_33 , V_30 ) ;
F_20 ( V_32 , V_29 , V_34 ) ;
V_29 += V_34 ;
V_30 -= V_34 ;
}
V_34 = V_30 >> 2 ;
if ( V_34 ) {
T_4 * V_35 = ( T_4 * ) V_29 ;
F_21 ( V_32 , V_35 , V_34 ) ;
V_29 += V_34 << 2 ;
V_30 -= V_34 << 2 ;
}
if ( V_30 )
F_20 ( V_32 , V_29 , V_30 ) ;
}
static void F_22 ( struct V_15 * V_16 ,
T_2 * V_29 , int V_30 )
{
struct V_19 * V_31 = F_16 ( V_16 ) ;
void T_3 * V_32 = V_31 -> V_36 ;
unsigned long V_33 = ( ( unsigned long ) V_29 & 3 ) ;
int V_34 ;
if ( V_33 ) {
V_34 = F_19 ( int , 4 - V_33 , V_30 ) ;
F_23 ( V_32 , V_29 , V_34 ) ;
V_29 += V_34 ;
V_30 -= V_34 ;
}
V_34 = V_30 >> 2 ;
if ( V_34 ) {
T_4 * V_35 = ( T_4 * ) V_29 ;
F_24 ( V_32 , V_35 , V_34 ) ;
V_29 += V_34 << 2 ;
V_30 -= V_34 << 2 ;
}
if ( V_30 )
F_23 ( V_32 , V_29 , V_30 ) ;
}
static int F_25 ( void )
{
int V_6 ;
if ( V_9 . V_10 . V_37 . V_12 == 0 ) {
V_6 = F_10 ( & V_38 ) ;
if ( ! V_6 )
V_9 . V_10 . V_37 . V_12 = 1 ;
} else
V_6 = F_11 ( & V_38 ) ;
if ( V_6 )
F_12 ( L_3 , V_6 ) ;
return V_6 ;
}
static void F_26 ( void )
{
F_14 ( & V_38 ) ;
}
static int F_27 ( void )
{
int V_6 ;
if ( V_9 . V_10 . V_39 . V_12 == 0 ) {
V_6 = F_10 ( & V_40 ) ;
if ( ! V_6 )
V_9 . V_10 . V_39 . V_12 = 1 ;
} else
V_6 = F_11 ( & V_40 ) ;
if ( V_6 )
F_12 ( L_4 , V_6 ) ;
return V_6 ;
}
static void F_28 ( void )
{
F_14 ( & V_40 ) ;
}
static void F_29 ( void )
{
V_9 . V_10 . V_11 . V_12 = 0 ;
V_9 . V_10 . V_37 . V_12 = 0 ;
V_9 . V_10 . V_39 . V_12 = 0 ;
}
static void F_30 ( void )
{
switch ( V_9 . V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
V_9 . V_10 . V_11 . V_51 = 1 ;
V_9 . V_10 . V_37 . V_51 = 1 ;
V_9 . V_10 . V_39 . V_51 = 1 ;
break;
default:
switch ( ( V_9 . V_41 >> 8 ) & 0xffffff ) {
case V_52 :
F_31 ( L_5 ,
V_9 . V_41 & 0xff ) ;
V_9 . V_10 . V_11 . V_51 = 1 ;
V_9 . V_10 . V_37 . V_51 = 1 ;
V_9 . V_10 . V_39 . V_51 = 1 ;
break;
default:
V_9 . V_10 . V_11 . V_51 = 0 ;
V_9 . V_10 . V_37 . V_51 = 0 ;
V_9 . V_10 . V_39 . V_51 = 0 ;
}
}
}
static int F_32 ( void )
{
int V_53 , V_54 = 0 ;
if ( V_9 . V_10 . V_11 . V_51 == 1 ) {
V_53 = F_9 () ;
if ( V_53 )
V_9 . V_10 . V_11 . V_51 = 0 ;
V_54 |= V_53 ;
}
if ( V_9 . V_10 . V_37 . V_51 == 1 ) {
V_53 = F_25 () ;
if ( V_53 )
V_9 . V_10 . V_37 . V_51 = 0 ;
V_54 |= V_53 ;
}
if ( V_9 . V_10 . V_39 . V_51 == 1 ) {
V_53 = F_27 () ;
if ( V_53 )
V_9 . V_10 . V_39 . V_51 = 0 ;
V_54 |= V_53 ;
}
return V_54 ;
}
static int F_33 ( void )
{
int V_54 = 0 ;
if ( V_9 . V_10 . V_11 . V_51 == 1 )
F_13 () ;
if ( V_9 . V_10 . V_37 . V_51 == 1 )
F_26 () ;
if ( V_9 . V_10 . V_39 . V_51 == 1 )
F_28 () ;
return V_54 ;
}
static int F_34 ( void )
{
V_9 . V_41 = F_35 ( V_55 ) ;
F_12 ( L_6 ,
( V_9 . V_41 >> 8 ) & 0xffffff ,
V_9 . V_41 & 0xff ) ;
F_30 () ;
if ( F_32 () ) {
V_9 . V_56 = - 1 ;
return - V_57 ;
}
return 0 ;
}
static int F_36 ( void )
{
unsigned int V_58 ;
V_58 = F_35 ( V_55 ) ;
if ( V_9 . V_41 != V_58 ) {
F_37 ( L_7
L_8 ,
( V_9 . V_41 >> 8 ) & 0xffffff , V_9 . V_41 & 0xff ,
( V_58 >> 8 ) & 0xffffff , V_58 & 0xff ) ;
V_9 . V_56 = - 1 ;
return - V_57 ;
}
if ( F_33 () ) {
V_9 . V_56 = - 1 ;
return - V_57 ;
}
return 0 ;
}
static T_5 F_38 ( struct V_59 * V_60 ,
struct V_61 * V_62 , char * V_29 )
{
if ( V_9 . V_56 < 0 )
return sprintf ( V_29 , L_9 ) ;
return sprintf ( V_29 , L_10 , ( V_9 . V_56 ) ? L_11 : L_12 ) ;
}
static T_5 F_39 ( struct V_59 * V_60 ,
struct V_61 * V_62 , const char * V_29 , T_6 V_63 )
{
int V_5 , V_54 ;
if ( V_9 . V_56 < 0 ) {
F_37 ( L_13 ) ;
return - V_57 ;
}
if ( strncmp ( V_29 , L_11 , sizeof( L_11 ) - 1 ) == 0 )
V_5 = 1 ;
else if ( strncmp ( V_29 , L_12 , sizeof( L_12 ) - 1 ) == 0 )
V_5 = 0 ;
else
return - V_64 ;
if ( V_9 . V_56 == V_5 )
return V_63 ;
V_54 = ( V_9 . V_56 == 0 )
? F_34 ()
: F_36 () ;
if ( ! ( V_54 < 0 ) )
V_9 . V_56 = V_5 ;
return V_63 ;
}
static void T_1 F_40 ( void )
{
int V_54 ;
F_41 () ;
F_42 ( V_65 ) ;
F_43 () ;
F_44 () ;
F_45 ( & V_66 ) ;
F_46 ( & V_67 ) ;
F_47 () ;
F_48 () ;
F_49 () ;
F_29 () ;
V_54 = F_34 () ;
V_54 = F_50 ( V_68 , & V_69 . V_62 ) ;
if ( V_54 )
F_37 ( L_14 , V_54 ) ;
}
