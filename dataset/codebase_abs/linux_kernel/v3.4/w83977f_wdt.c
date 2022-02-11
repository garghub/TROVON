static int F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF2 , V_4 ) ;
F_3 ( V_7 , V_6 ) ;
F_3 ( 0xF3 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF4 , V_4 ) ;
F_3 ( 0x00 , V_6 ) ;
F_3 ( 0x30 , V_4 ) ;
F_3 ( 0x01 , V_6 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x07 , V_6 ) ;
if ( ! V_8 ) {
unsigned V_9 ;
F_3 ( 0xE6 , V_4 ) ;
F_3 ( 0x0A , V_6 ) ;
F_3 ( 0x2C , V_4 ) ;
V_9 = F_4 ( V_6 ) ;
V_9 |= 0x10 ;
V_9 &= ~ ( 0x20 ) ;
F_3 ( 0x2C , V_4 ) ;
F_3 ( V_9 , V_6 ) ;
}
F_3 ( 0xE3 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0x30 , V_4 ) ;
F_3 ( 0x01 , V_6 ) ;
F_3 ( V_10 , V_4 ) ;
F_5 ( & V_2 , V_1 ) ;
F_6 ( L_1 ) ;
return 0 ;
}
static int F_7 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF2 , V_4 ) ;
F_3 ( 0xFF , V_6 ) ;
F_3 ( 0xF3 , V_4 ) ;
F_3 ( 0x00 , V_6 ) ;
F_3 ( 0xF4 , V_4 ) ;
F_3 ( 0x00 , V_6 ) ;
F_3 ( 0xF2 , V_4 ) ;
F_3 ( 0x00 , V_6 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x07 , V_6 ) ;
if ( ! V_8 ) {
F_3 ( 0xE6 , V_4 ) ;
F_3 ( 0x01 , V_6 ) ;
}
F_3 ( 0xE3 , V_4 ) ;
F_3 ( 0x01 , V_6 ) ;
F_3 ( V_10 , V_4 ) ;
F_5 ( & V_2 , V_1 ) ;
F_6 ( L_2 ) ;
return 0 ;
}
static int F_8 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF2 , V_4 ) ;
F_3 ( V_7 , V_6 ) ;
F_3 ( V_10 , V_4 ) ;
F_5 ( & V_2 , V_1 ) ;
return 0 ;
}
static int F_9 ( int V_11 )
{
int V_12 ;
if ( V_11 < 15 )
return - V_13 ;
V_12 = ( ( V_11 + 15 ) + 29 ) / 30 ;
if ( V_12 > 255 )
return - V_13 ;
V_7 = V_12 ;
V_14 = ( V_7 * 30 ) - 15 ;
return 0 ;
}
static int F_10 ( int * V_15 )
{
int V_16 ;
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF4 , V_4 ) ;
V_16 = F_4 ( V_6 ) ;
F_3 ( V_10 , V_4 ) ;
F_5 ( & V_2 , V_1 ) ;
* V_15 = 0 ;
if ( V_16 & 1 )
* V_15 |= V_17 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( F_12 ( 0 , & V_20 ) )
return - V_21 ;
if ( V_22 )
F_13 ( V_23 ) ;
F_1 () ;
return F_14 ( V_18 , V_19 ) ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( V_24 == 42 ) {
F_7 () ;
F_16 ( 0 , & V_20 ) ;
} else {
F_8 () ;
F_17 ( L_3 ) ;
}
V_24 = 0 ;
return 0 ;
}
static T_1 F_18 ( struct V_19 * V_19 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
if ( V_26 ) {
if ( ! V_22 ) {
T_3 V_28 ;
V_24 = 0 ;
for ( V_28 = 0 ; V_28 != V_26 ; V_28 ++ ) {
char V_29 ;
if ( F_19 ( V_29 , V_25 + V_28 ) )
return - V_30 ;
if ( V_29 == 'V' )
V_24 = 42 ;
}
}
F_8 () ;
}
return V_26 ;
}
static long F_20 ( struct V_19 * V_19 , unsigned int V_31 , unsigned long V_32 )
{
int V_15 ;
int V_33 , V_34 = - V_13 ;
int V_35 ;
union {
struct V_36 T_2 * V_37 ;
int T_2 * V_38 ;
} V_39 ;
V_39 . V_38 = ( int T_2 * ) V_32 ;
switch ( V_31 ) {
case V_40 :
return F_21 ( V_39 . V_37 , & V_37 ,
sizeof( V_37 ) ) ? - V_30 : 0 ;
case V_41 :
F_10 ( & V_15 ) ;
return F_22 ( V_15 , V_39 . V_38 ) ;
case V_42 :
return F_22 ( 0 , V_39 . V_38 ) ;
case V_43 :
if ( F_19 ( V_33 , V_39 . V_38 ) )
return - V_30 ;
if ( V_33 & V_44 ) {
F_7 () ;
V_34 = 0 ;
}
if ( V_33 & V_45 ) {
F_1 () ;
V_34 = 0 ;
}
return V_34 ;
case V_46 :
F_8 () ;
return 0 ;
case V_47 :
if ( F_19 ( V_35 , V_39 . V_38 ) )
return - V_30 ;
if ( F_9 ( V_35 ) )
return - V_13 ;
F_8 () ;
case V_48 :
return F_22 ( V_14 , V_39 . V_38 ) ;
default:
return - V_49 ;
}
}
static int F_23 ( struct V_50 * V_51 , unsigned long V_52 ,
void * V_53 )
{
if ( V_52 == V_54 || V_52 == V_55 )
F_7 () ;
return V_56 ;
}
static int T_5 F_24 ( void )
{
int V_57 ;
F_6 ( L_4 , V_58 ) ;
if ( F_9 ( V_14 ) ) {
F_9 ( V_59 ) ;
F_6 ( L_5 ,
V_59 ) ;
}
if ( ! F_25 ( V_4 , 2 , V_60 ) ) {
F_26 ( L_6 , V_4 ) ;
V_57 = - V_61 ;
goto V_62;
}
V_57 = F_27 ( & V_63 ) ;
if ( V_57 ) {
F_26 ( L_7 , V_57 ) ;
goto V_64;
}
V_57 = F_28 ( & V_65 ) ;
if ( V_57 ) {
F_26 ( L_8 ,
V_65 . V_66 , V_57 ) ;
goto V_67;
}
F_6 ( L_9 ,
V_14 , V_22 , V_8 ) ;
return 0 ;
V_67:
F_29 ( & V_63 ) ;
V_64:
F_30 ( V_4 , 2 ) ;
V_62:
return V_57 ;
}
static void T_6 F_31 ( void )
{
F_7 () ;
F_32 ( & V_65 ) ;
F_29 ( & V_63 ) ;
F_30 ( V_4 , 2 ) ;
}
