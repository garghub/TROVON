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
F_8 ( L_2 ) ;
V_11 = 0 ;
}
if ( V_11 == 0 )
F_9 ( L_3 ) ;
F_1 ( V_12 , V_11 << 4 ) ;
F_1 ( V_13 , V_14 ) ;
F_5 ( 0 ) ;
}
static T_2 F_10 ( int V_11 , void * V_15 )
{
F_11 ( L_4 ) ;
#ifdef F_12
F_11 ( L_5 ) ;
#else
F_11 ( L_6 ) ;
F_13 () ;
#endif
return V_16 ;
}
static void F_14 ( void )
{
F_5 ( V_17 ) ;
}
static T_3 F_15 ( struct V_18 * V_18 , const char T_4 * V_19 ,
T_5 V_20 , T_6 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_5 V_23 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_25 ;
if ( F_16 ( V_25 , V_19 + V_23 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_24 = 42 ;
}
}
F_17 ( & V_27 ) ;
F_14 () ;
F_18 ( & V_27 ) ;
}
return V_20 ;
}
static long F_19 ( struct V_18 * V_18 ,
unsigned int V_28 , unsigned long V_29 )
{
void T_4 * V_30 = ( void T_4 * ) V_29 ;
int T_4 * V_31 = V_30 ;
static const struct V_32 V_33 = {
. V_34 = V_35 | V_36
| V_37 ,
. V_38 = 1 ,
. V_39 = L_7 ,
} ;
int time ;
int V_34 , V_40 = - V_41 ;
switch ( V_28 ) {
case V_42 :
return F_20 ( V_30 , & V_33 , sizeof( V_33 ) ) ? - V_26 : 0 ;
case V_43 :
case V_44 :
return F_21 ( 0 , V_31 ) ;
case V_45 :
if ( F_16 ( V_34 , V_31 ) )
return - V_26 ;
F_17 ( & V_27 ) ;
if ( V_34 & V_46 ) {
F_6 () ;
V_40 = 0 ;
}
if ( V_34 & V_47 ) {
F_7 () ;
F_14 () ;
V_40 = 0 ;
}
F_18 ( & V_27 ) ;
return V_40 ;
case V_48 :
F_17 ( & V_27 ) ;
F_14 () ;
F_18 ( & V_27 ) ;
return 0 ;
case V_49 :
if ( F_22 ( & time , V_31 , sizeof( int ) ) )
return - V_26 ;
if ( time < 0 || time > 255 )
return - V_41 ;
F_17 ( & V_27 ) ;
V_17 = time ;
F_5 ( time ) ;
F_18 ( & V_27 ) ;
case V_50 :
return F_21 ( V_17 , V_31 ) ;
default:
return - V_51 ;
}
}
static int F_23 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
if ( F_24 ( 0 , & V_53 ) )
return - V_54 ;
V_17 = V_55 ;
F_7 () ;
return F_25 ( V_52 , V_18 ) ;
}
static int F_26 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
if ( V_24 == 42 )
F_6 () ;
else {
F_11 ( L_8 ) ;
F_14 () ;
}
F_27 ( 0 , & V_53 ) ;
V_24 = 0 ;
return 0 ;
}
static int F_28 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_59 )
{
if ( V_58 == V_60 || V_58 == V_61 )
F_6 () ;
return V_62 ;
}
static void T_7 F_29 ( void )
{
F_3 () ;
F_30 ( & V_63 ) ;
F_31 ( & V_64 ) ;
F_32 ( V_3 , 2 ) ;
F_33 ( V_11 , NULL ) ;
}
static int T_8 F_34 ( void )
{
int V_65 ;
V_65 = F_35 ( V_11 , F_10 , 0 , L_9 , NULL ) ;
if ( V_65 ) {
F_8 ( L_10 , V_11 ) ;
goto V_66;
}
if ( ! F_36 ( V_3 , 2 , L_9 ) ) {
F_8 ( L_11 , V_3 ) ;
V_65 = - V_54 ;
goto V_67;
}
V_65 = F_37 ( & V_64 ) ;
if ( V_65 ) {
F_8 ( L_12 , V_65 ) ;
goto V_68;
}
V_65 = F_38 ( & V_63 ) ;
if ( V_65 ) {
F_8 ( L_13 , V_69 ) ;
goto V_70;
}
F_4 () ;
V_65 = 0 ;
F_9 ( L_14 ,
V_3 , V_11 , ( ! strcmp ( L_1 , V_8 ) ? L_1 : L_15 ) ) ;
V_66:
return V_65 ;
V_70:
F_31 ( & V_64 ) ;
V_68:
F_32 ( V_3 , 2 ) ;
V_67:
F_33 ( V_11 , NULL ) ;
goto V_66;
}
