static inline void F_1 ( unsigned char V_1 ,
unsigned char * V_2 )
{
F_2 ( V_1 , V_3 ) ;
* V_2 = F_3 ( V_4 ) ;
}
static void F_4 ( unsigned char V_1 , unsigned char * V_2 )
{
F_5 ( & V_5 ) ;
F_1 ( V_1 , V_2 ) ;
F_6 ( & V_5 ) ;
}
static inline void F_7 ( unsigned char V_1 ,
unsigned char V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_8 ( V_2 , V_4 ) ;
}
static inline void F_9 ( unsigned char V_1 ,
unsigned char V_2 )
{
F_5 ( & V_5 ) ;
F_7 ( V_1 , V_2 ) ;
F_6 ( & V_5 ) ;
}
static void F_10 ( void )
{
unsigned char V_6 ;
F_5 ( & V_5 ) ;
F_1 ( V_7 , & V_6 ) ;
V_6 |= ( V_8 | V_9 | V_10 | V_11 ) ;
F_7 ( V_7 , V_6 ) ;
F_7 ( V_12 , V_13 ) ;
F_6 ( & V_5 ) ;
}
static void F_11 ( void )
{
F_9 ( V_12 , 0 ) ;
}
static inline int F_12 ( void )
{
unsigned char V_14 ;
F_4 ( V_15 , & V_14 ) ;
return ( V_14 & 0x01 ) ? 0 : V_16 ;
}
static int F_13 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( F_14 ( 0 , & V_19 ) )
return - V_20 ;
if ( V_13 > V_21 )
V_13 = V_21 ;
F_10 () ;
F_15 ( L_1 , V_13 ) ;
return F_16 ( V_17 , V_18 ) ;
}
static long F_17 ( struct V_18 * V_18 , unsigned int V_22 ,
unsigned long V_23 )
{
int V_24 ;
void T_1 * V_25 = ( void T_1 * ) V_23 ;
int T_1 * V_26 = V_25 ;
static const struct V_27 V_28 = {
. V_29 = V_16 | V_30 |
V_31 ,
. V_32 = 0 ,
. V_33 = L_2 ,
} ;
switch ( V_22 ) {
case V_34 :
if ( F_18 ( V_25 , & V_28 , sizeof( V_28 ) ) )
return - V_35 ;
return 0 ;
case V_36 :
return F_19 ( F_12 () , V_26 ) ;
case V_37 :
return F_19 ( 0 , V_26 ) ;
case V_38 :
{
int V_29 , V_39 = - V_40 ;
if ( F_20 ( V_29 , V_26 ) )
return - V_35 ;
if ( V_29 & V_41 ) {
F_11 () ;
V_39 = 0 ;
}
if ( V_29 & V_42 ) {
F_10 () ;
V_39 = 0 ;
}
return V_39 ;
}
case V_43 :
F_9 ( V_12 , V_13 ) ;
return 0 ;
case V_44 :
if ( F_20 ( V_24 , V_26 ) )
return - V_35 ;
V_24 /= 60 ;
if ( V_24 < 0 || V_24 > V_21 )
return - V_40 ;
V_13 = V_24 ;
F_9 ( V_12 , V_13 ) ;
case V_45 :
return F_19 ( V_13 * 60 , V_26 ) ;
default:
return - V_46 ;
}
}
static int F_21 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( V_47 == 42 ) {
F_11 () ;
F_15 ( L_3 ) ;
} else {
F_9 ( V_12 , V_13 ) ;
F_22 ( L_4 , V_13 ) ;
}
F_23 ( 0 , & V_19 ) ;
V_47 = 0 ;
return 0 ;
}
static T_2 F_24 ( struct V_18 * V_18 , const char T_1 * V_2 ,
T_3 V_48 , T_4 * V_49 )
{
if ( V_48 ) {
if ( ! V_50 ) {
T_3 V_51 ;
V_47 = 0 ;
for ( V_51 = 0 ; V_51 != V_48 ; V_51 ++ ) {
char V_52 ;
if ( F_20 ( V_52 , V_2 + V_51 ) )
return - V_35 ;
if ( V_52 == 'V' )
V_47 = 42 ;
}
}
F_9 ( V_12 , V_13 ) ;
return V_48 ;
}
return 0 ;
}
static int F_25 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
if ( V_55 == V_57 || V_55 == V_58 )
F_11 () ;
return V_59 ;
}
static int T_5 F_26 ( void )
{
unsigned char V_6 ;
F_4 ( V_60 , & V_6 ) ;
V_6 &= 0x0f ;
return ( V_6 == 0x0e ) ? 0 : - V_61 ;
}
static int F_27 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
if ( V_66 || ! V_67 )
return - V_20 ;
V_66 = V_63 ;
V_68 = F_28 ( V_66 , 0 ) ;
V_69 = F_29 ( V_66 , 0 ) ;
if ( ! F_30 ( V_68 , V_69 , V_70 ) ) {
F_31 ( L_5 , V_68 ) ;
return - V_20 ;
}
F_15 ( L_6 , V_68 , V_69 ) ;
return 0 ;
}
static void F_32 ( struct V_62 * V_63 )
{
if ( V_66 ) {
F_33 ( V_68 , V_69 ) ;
V_66 = NULL ;
}
}
static int T_5 F_34 ( void )
{
int V_14 ;
F_15 ( L_7 , V_71 ) ;
#if V_72 V_73
if ( V_67 ) {
V_14 = F_35 ( & V_74 ) ;
if ( V_14 )
goto V_75;
}
#endif
if ( V_68 == - 1 ) {
F_31 ( L_8 ) ;
V_14 = - V_40 ;
goto V_76;
}
#if V_72 V_73
V_67 = 0 ;
F_36 ( & V_74 ) ;
#endif
if ( ! F_30 ( V_68 , V_69 , V_70 ) ) {
F_31 ( L_5 , V_68 ) ;
V_14 = - V_20 ;
goto V_76;
}
V_14 = F_26 () ;
if ( V_14 )
goto V_77;
V_14 = F_37 ( & V_78 ) ;
if ( V_14 ) {
F_31 ( L_9 , V_14 ) ;
goto V_77;
}
V_14 = F_38 ( & V_79 ) ;
if ( V_14 ) {
F_31 ( L_10 ,
V_80 ) ;
goto V_81;
}
V_75:
return V_14 ;
V_81:
F_39 ( & V_78 ) ;
V_77:
F_33 ( V_68 , V_69 ) ;
V_76:
#if V_72 V_73
if ( V_67 )
F_36 ( & V_74 ) ;
#endif
goto V_75;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_79 ) ;
F_39 ( & V_78 ) ;
#if V_72 V_73
if ( V_67 )
F_36 ( & V_74 ) ;
else
#endif
F_33 ( V_68 , V_69 ) ;
}
