static inline void F_1 ( void )
{
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x87 , V_1 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0xAA , V_1 ) ;
}
static unsigned char F_4 ( unsigned char V_2 )
{
F_2 ( V_2 , V_3 ) ;
return F_5 ( V_4 ) ;
}
static void F_6 ( unsigned char V_2 , unsigned char V_5 )
{
F_2 ( V_2 , V_3 ) ;
F_2 ( V_5 , V_4 ) ;
}
static void F_7 ( int V_6 )
{
F_6 ( 0xF4 , V_6 ) ;
}
static void F_8 ( void )
{
F_1 () ;
F_6 ( 0x07 , 0x08 ) ;
}
static inline void F_9 ( void )
{
F_3 () ;
}
static void F_10 ( void )
{
unsigned char V_7 ;
F_8 () ;
V_7 = F_4 ( 0x29 ) ;
V_7 &= ~ 0x60 ;
V_7 |= 0x20 ;
F_6 ( 0x29 , V_7 ) ;
V_7 = F_4 ( 0xF3 ) ;
V_7 &= ~ 0x04 ;
F_6 ( 0xF3 , V_7 ) ;
F_9 () ;
}
static void F_11 ( void )
{
F_12 ( & V_8 ) ;
F_8 () ;
F_7 ( V_6 ) ;
F_9 () ;
F_13 ( & V_8 ) ;
}
static void F_14 ( void )
{
F_12 ( & V_8 ) ;
F_8 () ;
F_7 ( V_6 ) ;
F_6 ( 0x30 , 1 ) ;
F_9 () ;
F_13 ( & V_8 ) ;
}
static void F_15 ( void )
{
F_12 ( & V_8 ) ;
F_8 () ;
F_6 ( 0x30 , 0 ) ;
F_7 ( 0 ) ;
F_9 () ;
F_13 ( & V_8 ) ;
}
static unsigned char F_16 ( void )
{
unsigned char V_9 ;
F_12 ( & V_8 ) ;
F_8 () ;
V_9 = F_4 ( 0xF4 ) ;
F_9 () ;
F_13 ( & V_8 ) ;
return V_9 ;
}
static int F_17 ( int V_9 )
{
if ( V_9 < 1 || V_9 > 255 )
return - V_10 ;
V_6 = V_9 ;
return 0 ;
}
static T_1 F_18 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
if ( V_13 ) {
if ( ! V_15 ) {
T_3 V_16 ;
V_17 = 0 ;
for ( V_16 = 0 ; V_16 != V_13 ; V_16 ++ ) {
char V_18 ;
if ( F_19 ( V_18 , V_12 + V_16 ) )
return - V_19 ;
if ( V_18 == 'V' )
V_17 = 42 ;
}
}
F_11 () ;
}
return V_13 ;
}
static long F_20 ( struct V_11 * V_11 , unsigned int V_20 , unsigned long V_21 )
{
void T_2 * V_22 = ( void T_2 * ) V_21 ;
int T_2 * V_23 = V_22 ;
int V_24 ;
static const struct V_25 V_26 = {
. V_27 = V_28 | V_29
| V_30 ,
. V_31 = 1 ,
. V_32 = L_1 ,
} ;
switch ( V_20 ) {
case V_33 :
if ( F_21 ( V_22 , & V_26 , sizeof( V_26 ) ) )
return - V_19 ;
break;
case V_34 :
case V_35 :
return F_22 ( 0 , V_23 ) ;
case V_36 :
{
int V_27 , V_37 = - V_10 ;
if ( F_19 ( V_27 , V_23 ) )
return - V_19 ;
if ( V_27 & V_38 ) {
F_15 () ;
V_37 = 0 ;
}
if ( V_27 & V_39 ) {
F_14 () ;
V_37 = 0 ;
}
return V_37 ;
}
case V_40 :
F_11 () ;
break;
case V_41 :
if ( F_19 ( V_24 , V_23 ) )
return - V_19 ;
if ( F_17 ( V_24 ) )
return - V_10 ;
F_11 () ;
case V_42 :
return F_22 ( V_6 , V_23 ) ;
default:
return - V_43 ;
}
return 0 ;
}
static int F_23 ( struct V_44 * V_44 , struct V_11 * V_11 )
{
if ( F_24 ( 0 , & V_45 ) )
return - V_46 ;
F_14 () ;
return F_25 ( V_44 , V_11 ) ;
}
static int F_26 ( struct V_44 * V_44 , struct V_11 * V_11 )
{
if ( V_17 == 42 )
F_15 () ;
else {
F_27 ( L_2 ) ;
F_11 () ;
}
V_17 = 0 ;
F_28 ( 0 , & V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_50 )
{
if ( V_49 == V_51 || V_49 == V_52 )
F_15 () ;
return V_53 ;
}
static int F_30 ( void )
{
if ( ! F_31 ( V_54 , 2 , V_55 ) ) {
F_32 ( L_3 , V_54 ) ;
return - V_56 ;
}
F_33 ( L_4 , V_54 ) ;
F_1 () ;
if ( F_4 ( 0x20 ) == 0x60 ) {
F_34 ( L_5 , V_54 ) ;
F_3 () ;
return 0 ;
}
F_3 () ;
F_34 ( L_6 , V_54 ) ;
F_35 ( V_54 , 2 ) ;
return - V_56 ;
}
static int T_5 F_36 ( void )
{
int V_57 , V_16 , V_58 = 0 ;
F_34 ( L_7 ) ;
if ( V_54 == 0 ) {
for ( V_16 = 0 ; ( ( ! V_58 ) && ( V_59 [ V_16 ] != 0 ) ) ; V_16 ++ ) {
V_54 = V_59 [ V_16 ] ;
if ( ! F_30 () )
V_58 ++ ;
}
} else {
if ( ! F_30 () )
V_58 ++ ;
}
if ( ! V_58 ) {
F_32 ( L_8 ) ;
V_57 = - V_60 ;
goto V_61;
}
F_10 () ;
if ( V_62 ) {
if ( F_16 () )
F_37 ( L_9 ) ;
F_15 () ;
}
if ( F_17 ( V_6 ) ) {
F_17 ( V_63 ) ;
F_34 ( L_10 ,
V_63 ) ;
}
V_57 = F_38 ( & V_64 ) ;
if ( V_57 != 0 ) {
F_32 ( L_11 , V_57 ) ;
goto V_65;
}
V_57 = F_39 ( & V_66 ) ;
if ( V_57 != 0 ) {
F_32 ( L_12 ,
V_67 , V_57 ) ;
goto V_68;
}
F_34 ( L_13 ,
V_6 , V_15 ) ;
V_61:
return V_57 ;
V_68:
F_40 ( & V_64 ) ;
V_65:
F_35 ( V_54 , 2 ) ;
goto V_61;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_66 ) ;
F_40 ( & V_64 ) ;
F_35 ( V_54 , 2 ) ;
}
