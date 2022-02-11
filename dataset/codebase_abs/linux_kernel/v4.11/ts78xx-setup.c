static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static int F_5 ( void )
{
int V_2 ;
if ( V_3 . V_4 . V_5 . V_6 == 0 ) {
V_2 = F_6 ( & V_7 ) ;
if ( ! V_2 )
V_3 . V_4 . V_5 . V_6 = 1 ;
} else {
V_2 = F_7 ( & V_7 ) ;
}
if ( V_2 )
F_8 ( L_1 , V_2 ) ;
return V_2 ;
}
static void F_9 ( void )
{
F_10 ( & V_7 ) ;
}
static void F_11 ( struct V_8 * V_9 , int V_10 ,
unsigned int V_11 )
{
struct V_12 * V_13 = F_12 ( V_9 ) ;
if ( V_11 & V_14 ) {
unsigned char V_15 ;
V_15 = ( V_11 & V_16 ) << 2 ;
V_15 |= V_11 & V_17 ;
V_15 |= ( V_11 & V_18 ) >> 2 ;
F_13 ( ( F_14 ( V_19 ) & ~ 0x7 ) | V_15 , V_19 ) ;
}
if ( V_10 != V_20 )
F_13 ( V_10 , V_13 -> V_21 ) ;
}
static int F_15 ( struct V_8 * V_9 )
{
return F_14 ( V_19 ) & 0x20 ;
}
static void F_16 ( struct V_8 * V_9 ,
const T_2 * V_22 , int V_23 )
{
struct V_12 * V_24 = F_12 ( V_9 ) ;
void T_3 * V_25 = V_24 -> V_21 ;
unsigned long V_26 = ( ( unsigned long ) V_22 & 3 ) ;
int V_27 ;
if ( V_26 ) {
V_27 = F_17 ( int , 4 - V_26 , V_23 ) ;
F_18 ( V_25 , V_22 , V_27 ) ;
V_22 += V_27 ;
V_23 -= V_27 ;
}
V_27 = V_23 >> 2 ;
if ( V_27 ) {
T_4 * V_28 = ( T_4 * ) V_22 ;
F_19 ( V_25 , V_28 , V_27 ) ;
V_22 += V_27 << 2 ;
V_23 -= V_27 << 2 ;
}
if ( V_23 )
F_18 ( V_25 , V_22 , V_23 ) ;
}
static void F_20 ( struct V_8 * V_9 ,
T_2 * V_22 , int V_23 )
{
struct V_12 * V_24 = F_12 ( V_9 ) ;
void T_3 * V_25 = V_24 -> V_29 ;
unsigned long V_26 = ( ( unsigned long ) V_22 & 3 ) ;
int V_27 ;
if ( V_26 ) {
V_27 = F_17 ( int , 4 - V_26 , V_23 ) ;
F_21 ( V_25 , V_22 , V_27 ) ;
V_22 += V_27 ;
V_23 -= V_27 ;
}
V_27 = V_23 >> 2 ;
if ( V_27 ) {
T_4 * V_28 = ( T_4 * ) V_22 ;
F_22 ( V_25 , V_28 , V_27 ) ;
V_22 += V_27 << 2 ;
V_23 -= V_27 << 2 ;
}
if ( V_23 )
F_21 ( V_25 , V_22 , V_23 ) ;
}
static int F_23 ( void )
{
int V_2 ;
if ( V_3 . V_4 . V_30 . V_6 == 0 ) {
V_2 = F_6 ( & V_31 ) ;
if ( ! V_2 )
V_3 . V_4 . V_30 . V_6 = 1 ;
} else
V_2 = F_7 ( & V_31 ) ;
if ( V_2 )
F_8 ( L_2 , V_2 ) ;
return V_2 ;
}
static void F_24 ( void )
{
F_10 ( & V_31 ) ;
}
static int F_25 ( void )
{
int V_2 ;
if ( V_3 . V_4 . V_32 . V_6 == 0 ) {
V_2 = F_6 ( & V_33 ) ;
if ( ! V_2 )
V_3 . V_4 . V_32 . V_6 = 1 ;
} else
V_2 = F_7 ( & V_33 ) ;
if ( V_2 )
F_8 ( L_3 , V_2 ) ;
return V_2 ;
}
static void F_26 ( void )
{
F_10 ( & V_33 ) ;
}
static void F_27 ( void )
{
V_3 . V_4 . V_5 . V_6 = 0 ;
V_3 . V_4 . V_30 . V_6 = 0 ;
V_3 . V_4 . V_32 . V_6 = 0 ;
}
static void F_28 ( void )
{
switch ( V_3 . V_34 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_3 . V_4 . V_5 . V_44 = 1 ;
V_3 . V_4 . V_30 . V_44 = 1 ;
V_3 . V_4 . V_32 . V_44 = 1 ;
break;
default:
switch ( ( V_3 . V_34 >> 8 ) & 0xffffff ) {
case V_45 :
F_29 ( L_4 ,
V_3 . V_34 & 0xff ) ;
V_3 . V_4 . V_5 . V_44 = 1 ;
V_3 . V_4 . V_30 . V_44 = 1 ;
V_3 . V_4 . V_32 . V_44 = 1 ;
break;
default:
V_3 . V_4 . V_5 . V_44 = 0 ;
V_3 . V_4 . V_30 . V_44 = 0 ;
V_3 . V_4 . V_32 . V_44 = 0 ;
}
}
}
static int F_30 ( void )
{
int V_46 , V_47 = 0 ;
if ( V_3 . V_4 . V_5 . V_44 == 1 ) {
V_46 = F_5 () ;
if ( V_46 )
V_3 . V_4 . V_5 . V_44 = 0 ;
V_47 |= V_46 ;
}
if ( V_3 . V_4 . V_30 . V_44 == 1 ) {
V_46 = F_23 () ;
if ( V_46 )
V_3 . V_4 . V_30 . V_44 = 0 ;
V_47 |= V_46 ;
}
if ( V_3 . V_4 . V_32 . V_44 == 1 ) {
V_46 = F_25 () ;
if ( V_46 )
V_3 . V_4 . V_32 . V_44 = 0 ;
V_47 |= V_46 ;
}
return V_47 ;
}
static int F_31 ( void )
{
int V_47 = 0 ;
if ( V_3 . V_4 . V_5 . V_44 == 1 )
F_9 () ;
if ( V_3 . V_4 . V_30 . V_44 == 1 )
F_24 () ;
if ( V_3 . V_4 . V_32 . V_44 == 1 )
F_26 () ;
return V_47 ;
}
static int F_32 ( void )
{
V_3 . V_34 = F_33 ( V_48 ) ;
F_8 ( L_5 ,
( V_3 . V_34 >> 8 ) & 0xffffff ,
V_3 . V_34 & 0xff ) ;
F_28 () ;
if ( F_30 () ) {
V_3 . V_49 = - 1 ;
return - V_50 ;
}
return 0 ;
}
static int F_34 ( void )
{
unsigned int V_51 ;
V_51 = F_33 ( V_48 ) ;
if ( V_3 . V_34 != V_51 ) {
F_35 ( L_6
L_7 ,
( V_3 . V_34 >> 8 ) & 0xffffff , V_3 . V_34 & 0xff ,
( V_51 >> 8 ) & 0xffffff , V_51 & 0xff ) ;
V_3 . V_49 = - 1 ;
return - V_50 ;
}
if ( F_31 () ) {
V_3 . V_49 = - 1 ;
return - V_50 ;
}
return 0 ;
}
static T_5 F_36 ( struct V_52 * V_53 ,
struct V_54 * V_55 , char * V_22 )
{
if ( V_3 . V_49 < 0 )
return sprintf ( V_22 , L_8 ) ;
return sprintf ( V_22 , L_9 , ( V_3 . V_49 ) ? L_10 : L_11 ) ;
}
static T_5 F_37 ( struct V_52 * V_53 ,
struct V_54 * V_55 , const char * V_22 , T_6 V_56 )
{
int V_57 , V_47 ;
if ( V_3 . V_49 < 0 ) {
F_35 ( L_12 ) ;
return - V_50 ;
}
if ( strncmp ( V_22 , L_10 , sizeof( L_10 ) - 1 ) == 0 )
V_57 = 1 ;
else if ( strncmp ( V_22 , L_11 , sizeof( L_11 ) - 1 ) == 0 )
V_57 = 0 ;
else
return - V_58 ;
if ( V_3 . V_49 == V_57 )
return V_56 ;
V_47 = ( V_3 . V_49 == 0 )
? F_32 ()
: F_34 () ;
if ( ! ( V_47 < 0 ) )
V_3 . V_49 = V_57 ;
return V_56 ;
}
static void T_1 F_38 ( void )
{
int V_47 ;
F_39 () ;
F_40 ( V_59 ) ;
F_41 () ;
F_42 () ;
F_43 ( & V_60 ) ;
F_44 ( & V_61 ) ;
F_45 () ;
F_46 () ;
F_47 () ;
F_27 () ;
V_47 = F_32 () ;
V_47 = F_48 ( V_62 , & V_63 . V_55 ) ;
if ( V_47 )
F_35 ( L_13 , V_47 ) ;
}
