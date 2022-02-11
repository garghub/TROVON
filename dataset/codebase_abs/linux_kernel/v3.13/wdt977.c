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
F_3 ( 0x00 , V_6 ) ;
F_3 ( 0xF4 , V_4 ) ;
F_3 ( 0x00 , V_6 ) ;
if ( ! V_8 ) {
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x07 , V_6 ) ;
F_3 ( 0xE6 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
}
F_3 ( V_9 , V_4 ) ;
F_4 ( & V_2 , V_1 ) ;
F_5 ( L_1 ) ;
return 0 ;
}
static int F_6 ( void )
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
F_3 ( 0xE6 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( V_9 , V_4 ) ;
F_4 ( & V_2 , V_1 ) ;
F_5 ( L_2 ) ;
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
F_3 ( V_7 , V_6 ) ;
F_3 ( V_9 , V_4 ) ;
F_4 ( & V_2 , V_1 ) ;
return 0 ;
}
static int F_8 ( int V_10 )
{
int V_11 ;
V_11 = ( V_10 + 59 ) / 60 ;
if ( F_9 () ) {
V_11 += V_11 ;
}
if ( V_11 < 1 || V_11 > 255 )
return - V_12 ;
V_13 = V_10 ;
V_7 = V_11 ;
return 0 ;
}
static int F_10 ( int * V_14 )
{
int V_15 ;
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 ) ;
F_3 ( 0x08 , V_6 ) ;
F_3 ( 0xF4 , V_4 ) ;
V_15 = F_11 ( V_6 ) ;
F_3 ( V_9 , V_4 ) ;
F_4 ( & V_2 , V_1 ) ;
* V_14 = 0 ;
if ( V_15 & 1 )
* V_14 |= V_16 ;
return 0 ;
}
static int F_12 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( F_13 ( 0 , & V_19 ) )
return - V_20 ;
if ( V_21 )
F_14 ( V_22 ) ;
F_1 () ;
return F_15 ( V_17 , V_18 ) ;
}
static int F_16 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( V_23 == 42 ) {
F_6 () ;
F_17 ( 0 , & V_19 ) ;
} else {
F_7 () ;
F_18 ( L_3 ) ;
}
V_23 = 0 ;
return 0 ;
}
static T_1 F_19 ( struct V_18 * V_18 , const char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
if ( V_25 ) {
if ( ! V_21 ) {
T_3 V_27 ;
V_23 = 0 ;
for ( V_27 = 0 ; V_27 != V_25 ; V_27 ++ ) {
char V_28 ;
if ( F_20 ( V_28 , V_24 + V_27 ) )
return - V_29 ;
if ( V_28 == 'V' )
V_23 = 42 ;
}
}
F_7 () ;
}
return V_25 ;
}
static long F_21 ( struct V_18 * V_18 , unsigned int V_30 ,
unsigned long V_31 )
{
int V_14 ;
int V_32 , V_33 = - V_12 ;
int V_34 ;
union {
struct V_35 T_2 * V_36 ;
int T_2 * V_27 ;
} V_37 ;
V_37 . V_27 = ( int T_2 * ) V_31 ;
switch ( V_30 ) {
case V_38 :
return F_22 ( V_37 . V_36 , & V_36 ,
sizeof( V_36 ) ) ? - V_29 : 0 ;
case V_39 :
F_10 ( & V_14 ) ;
return F_23 ( V_14 , V_37 . V_27 ) ;
case V_40 :
return F_23 ( 0 , V_37 . V_27 ) ;
case V_41 :
if ( F_20 ( V_32 , V_37 . V_27 ) )
return - V_29 ;
if ( V_32 & V_42 ) {
F_6 () ;
V_33 = 0 ;
}
if ( V_32 & V_43 ) {
F_1 () ;
V_33 = 0 ;
}
return V_33 ;
case V_44 :
F_7 () ;
return 0 ;
case V_45 :
if ( F_20 ( V_34 , V_37 . V_27 ) )
return - V_29 ;
if ( F_8 ( V_34 ) )
return - V_12 ;
F_7 () ;
case V_46 :
return F_23 ( V_13 , V_37 . V_27 ) ;
default:
return - V_47 ;
}
}
static int F_24 ( struct V_48 * V_49 , unsigned long V_50 ,
void * V_51 )
{
if ( V_50 == V_52 || V_50 == V_53 )
F_6 () ;
return V_54 ;
}
static int T_5 F_25 ( void )
{
int V_55 ;
F_5 ( L_4 , V_56 ) ;
if ( F_8 ( V_13 ) ) {
F_8 ( V_57 ) ;
F_5 ( L_5 ,
V_57 ) ;
}
if ( ! F_9 () ) {
if ( ! F_26 ( V_4 , 2 , V_58 ) ) {
F_27 ( L_6 ,
V_4 ) ;
V_55 = - V_59 ;
goto V_60;
}
}
V_55 = F_28 ( & V_61 ) ;
if ( V_55 ) {
F_27 ( L_7 , V_55 ) ;
goto V_62;
}
V_55 = F_29 ( & V_63 ) ;
if ( V_55 ) {
F_27 ( L_8 ,
V_63 . V_64 , V_55 ) ;
goto V_65;
}
F_5 ( L_9 ,
V_13 , V_21 , V_8 ) ;
return 0 ;
V_65:
F_30 ( & V_61 ) ;
V_62:
if ( ! F_9 () )
F_31 ( V_4 , 2 ) ;
V_60:
return V_55 ;
}
static void T_6 F_32 ( void )
{
F_6 () ;
F_33 ( & V_63 ) ;
F_30 ( & V_61 ) ;
F_31 ( V_4 , 2 ) ;
}
