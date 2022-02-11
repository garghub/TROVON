static unsigned short F_1 ( unsigned char V_1 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( V_3 ) ;
}
static inline void F_4 ( unsigned char V_4 )
{
F_5 ( V_5 , V_4 ) ;
}
static inline unsigned short F_6 ( void )
{
return F_1 ( V_6 ) ;
}
static inline void F_7 ( unsigned short V_4 )
{
F_8 ( V_6 , V_4 ) ;
}
static inline void F_9 ( unsigned short V_4 , unsigned char V_7 )
{
switch ( V_7 ) {
case V_8 :
F_8 ( V_9 , V_4 ) ;
case V_10 :
F_5 ( V_11 , V_4 > 0xff ? 0xff : V_4 ) ;
default:
return;
}
}
static void F_10 ( void )
{
unsigned int V_12 = 0 ;
unsigned long V_13 ;
F_11 ( & V_14 ) ;
F_12 ( & V_15 , V_13 ) ;
V_12 = F_6 () ;
V_12 |= ( V_16 | V_17 ) ;
V_12 &= ~ ( V_16 | V_17 ) ;
F_7 ( V_12 ) ;
F_13 ( & V_15 , V_13 ) ;
F_14 (KERN_INFO PFX L_1 ) ;
}
static void F_15 ( void )
{
unsigned int V_12 = 0 ;
unsigned long V_13 ;
F_12 ( & V_15 , V_13 ) ;
F_5 ( V_18 , 0xff ) ;
F_9 ( V_19 , V_8 ) ;
V_20 = V_21 + V_22 ;
F_16 ( & V_14 , V_21 + V_23 ) ;
V_12 = F_6 () ;
V_12 |= ( V_16 | V_24 ) ;
F_7 ( V_12 ) ;
F_13 ( & V_15 , V_13 ) ;
F_14 (KERN_INFO PFX L_2 ) ;
}
static void F_17 ( unsigned long V_25 )
{
unsigned int V_12 = 0 ;
unsigned long V_13 ;
F_5 ( V_11 , 0xff ) ;
if ( F_18 ( V_21 , V_20 ) ) {
F_19 ( L_3 , V_20 - V_21 ) ;
F_12 ( & V_15 , V_13 ) ;
V_12 = F_6 () ;
V_12 |= V_26 ;
F_7 ( V_12 ) ;
V_12 &= ~ ( V_26 ) ;
F_7 ( V_12 ) ;
F_13 ( & V_15 , V_13 ) ;
F_16 ( & V_14 , V_21 + V_23 ) ;
} else
F_14 (KERN_CRIT PFX L_4 ) ;
}
static T_1 F_20 ( struct V_27 * V_27 , const char T_2 * V_28 , T_3 V_29 ,
T_4 * V_30 )
{
if ( V_29 ) {
if ( ! V_31 ) {
T_3 V_32 ;
V_33 = 0 ;
for ( V_32 = 0 ; V_32 != V_29 ; V_32 ++ ) {
char V_34 ;
if ( F_21 ( V_34 , V_28 + V_32 ) )
return - V_35 ;
if ( V_34 == 'V' ) {
V_33 = 42 ;
F_19 ( L_5 ) ;
}
}
}
V_20 = V_21 + V_22 ;
F_19 ( L_6 , V_21 ) ;
}
return V_29 ;
}
static long F_22 ( struct V_27 * V_27 , unsigned int V_36 , unsigned long V_37 )
{
void T_2 * V_38 = ( void T_2 * ) V_37 ;
int T_2 * V_39 = V_38 ;
switch ( V_36 ) {
case V_40 :
if ( F_23 ( V_38 , & V_41 , sizeof( V_41 ) ) )
return - V_35 ;
break;
case V_42 :
case V_43 :
return F_24 ( 0 , V_39 ) ;
case V_44 :
F_17 ( 0 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_25 ( struct V_46 * V_46 , struct V_27 * V_27 )
{
if ( F_26 ( 0 , & V_47 ) )
return - V_48 ;
if ( V_31 )
F_27 ( V_49 ) ;
F_15 () ;
return F_28 ( V_46 , V_27 ) ;
}
static int F_29 ( struct V_46 * V_46 , struct V_27 * V_27 )
{
if ( V_33 == 42 )
F_10 () ;
else {
F_30 ( & V_14 ) ;
F_14 (KERN_ERR PFX L_7
L_8 ) ;
}
F_31 ( 0 , & V_47 ) ;
V_33 = 0 ;
return 0 ;
}
static int F_32 ( struct V_50 * V_51 , unsigned long V_52 ,
void * V_53 )
{
if ( V_52 == V_54 || V_52 == V_55 )
F_10 () ;
return V_56 ;
}
static void T_5 F_33 ( int V_57 )
{
static const char * const V_58 [] = { L_9 , L_10 , L_11 , L_12 } ;
F_14 (KERN_INFO PFX L_13 , str[act]) ;
}
static int T_5 F_34 ( void )
{
int V_59 ;
F_14 (KERN_INFO PFX
L_14 ) ;
V_59 = F_35 () ;
if ( ! V_59 || V_59 == 0xffff ) {
F_14 (KERN_WARNING PFX L_15 ) ;
return - V_60 ;
}
if ( V_61 <= 3 && V_61 >= 0 )
V_24 = V_24 >> V_61 ;
else
V_61 = 0 ;
F_33 ( V_61 ) ;
if ( ! F_36 ( V_62 , 3 , L_16 ) ) {
F_14 ( V_63 L_17 ,
V_62 ) ;
V_59 = - V_48 ;
goto V_64;
}
V_59 = F_37 ( & V_65 ) ;
if ( V_59 ) {
F_14 ( V_63 L_18 ,
V_59 ) ;
goto V_66;
}
V_59 = F_38 ( & V_67 ) ;
if ( V_59 ) {
F_14 ( V_63 L_19 ,
V_68 ) ;
goto V_69;
}
F_4 ( 0 ) ;
F_7 ( 0 ) ;
return 0 ;
V_69:
F_39 ( & V_65 ) ;
V_66:
F_40 ( V_62 , 3 ) ;
V_64:
return V_59 ;
}
static void T_6 F_41 ( void )
{
F_10 () ;
F_42 ( & V_67 ) ;
F_39 ( & V_65 ) ;
F_40 ( V_62 , 3 ) ;
}
