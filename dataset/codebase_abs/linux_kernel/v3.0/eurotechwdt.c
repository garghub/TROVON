static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_3 + 1 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0xaa , V_3 ) ;
}
static inline void F_4 ( void )
{
F_2 ( 0x55 , V_3 ) ;
F_1 ( 0x07 , 0x08 ) ;
}
static inline void F_5 ( int V_4 )
{
F_1 ( V_5 , ( T_1 ) V_4 ) ;
}
static inline void F_6 ( void )
{
F_5 ( 0 ) ;
}
static void F_7 ( void )
{
F_6 () ;
F_1 ( V_6 , 0x01 ) ;
F_1 ( V_7 ,
! strcmp ( L_1 , V_8 ) ? V_9 : V_10 ) ;
if ( V_11 == 2 || V_11 > 15 || V_11 < 0 ) {
F_8 ( V_12 L_2 ) ;
V_11 = 0 ;
}
if ( V_11 == 0 )
F_8 ( V_13 L_3 ) ;
F_1 ( V_14 , V_11 << 4 ) ;
F_1 ( V_15 , V_16 ) ;
F_5 ( 0 ) ;
}
static T_2 F_9 ( int V_11 , void * V_17 )
{
F_8 ( V_18 L_4 ) ;
#ifdef F_10
F_8 ( V_18 L_5 ) ;
#else
F_8 ( V_18 L_6 ) ;
F_11 () ;
#endif
return V_19 ;
}
static void F_12 ( void )
{
F_5 ( V_20 ) ;
}
static T_3 F_13 ( struct V_21 * V_21 , const char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
if ( V_23 ) {
if ( ! V_25 ) {
T_5 V_26 ;
V_27 = 0 ;
for ( V_26 = 0 ; V_26 != V_23 ; V_26 ++ ) {
char V_28 ;
if ( F_14 ( V_28 , V_22 + V_26 ) )
return - V_29 ;
if ( V_28 == 'V' )
V_27 = 42 ;
}
}
F_15 ( & V_30 ) ;
F_12 () ;
F_16 ( & V_30 ) ;
}
return V_23 ;
}
static long F_17 ( struct V_21 * V_21 ,
unsigned int V_31 , unsigned long V_32 )
{
void T_4 * V_33 = ( void T_4 * ) V_32 ;
int T_4 * V_34 = V_33 ;
static const struct V_35 V_36 = {
. V_37 = V_38 | V_39
| V_40 ,
. V_41 = 1 ,
. V_42 = L_7 ,
} ;
int time ;
int V_37 , V_43 = - V_44 ;
switch ( V_31 ) {
case V_45 :
return F_18 ( V_33 , & V_36 , sizeof( V_36 ) ) ? - V_29 : 0 ;
case V_46 :
case V_47 :
return F_19 ( 0 , V_34 ) ;
case V_48 :
if ( F_14 ( V_37 , V_34 ) )
return - V_29 ;
F_15 ( & V_30 ) ;
if ( V_37 & V_49 ) {
F_6 () ;
V_43 = 0 ;
}
if ( V_37 & V_50 ) {
F_7 () ;
F_12 () ;
V_43 = 0 ;
}
F_16 ( & V_30 ) ;
return V_43 ;
case V_51 :
F_15 ( & V_30 ) ;
F_12 () ;
F_16 ( & V_30 ) ;
return 0 ;
case V_52 :
if ( F_20 ( & time , V_34 , sizeof( int ) ) )
return - V_29 ;
if ( time < 0 || time > 255 )
return - V_44 ;
F_15 ( & V_30 ) ;
V_20 = time ;
F_5 ( time ) ;
F_16 ( & V_30 ) ;
case V_53 :
return F_19 ( V_20 , V_34 ) ;
default:
return - V_54 ;
}
}
static int F_21 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
if ( F_22 ( 0 , & V_56 ) )
return - V_57 ;
V_20 = V_58 ;
F_7 () ;
return F_23 ( V_55 , V_21 ) ;
}
static int F_24 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
if ( V_27 == 42 )
F_6 () ;
else {
F_8 ( V_18
L_8 ) ;
F_12 () ;
}
F_25 ( 0 , & V_56 ) ;
V_27 = 0 ;
return 0 ;
}
static int F_26 ( struct V_59 * V_60 , unsigned long V_61 ,
void * V_62 )
{
if ( V_61 == V_63 || V_61 == V_64 )
F_6 () ;
return V_65 ;
}
static void T_7 F_27 ( void )
{
F_3 () ;
F_28 ( & V_66 ) ;
F_29 ( & V_67 ) ;
F_30 ( V_3 , 2 ) ;
F_31 ( V_11 , NULL ) ;
}
static int T_8 F_32 ( void )
{
int V_68 ;
V_68 = F_33 ( V_11 , F_9 , V_69 , L_9 , NULL ) ;
if ( V_68 ) {
F_8 ( V_12 L_10 , V_11 ) ;
goto V_70;
}
if ( ! F_34 ( V_3 , 2 , L_9 ) ) {
F_8 ( V_12 L_11 , V_3 ) ;
V_68 = - V_57 ;
goto V_71;
}
V_68 = F_35 ( & V_67 ) ;
if ( V_68 ) {
F_8 ( V_12
L_12 , V_68 ) ;
goto V_72;
}
F_36 ( & V_30 ) ;
V_68 = F_37 ( & V_66 ) ;
if ( V_68 ) {
F_8 ( V_12 L_13 ,
V_73 ) ;
goto V_74;
}
F_4 () ;
V_68 = 0 ;
F_8 ( V_13 L_14
L_15 ,
V_3 , V_11 , ( ! strcmp ( L_1 , V_8 ) ? L_1 : L_16 ) ) ;
V_70:
return V_68 ;
V_74:
F_29 ( & V_67 ) ;
V_72:
F_30 ( V_3 , 2 ) ;
V_71:
F_31 ( V_11 , NULL ) ;
goto V_70;
}
