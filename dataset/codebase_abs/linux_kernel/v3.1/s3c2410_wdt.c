static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 , V_3 + V_4 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
unsigned long V_5 ;
V_5 = F_6 ( V_3 + V_6 ) ;
V_5 &= ~ ( V_7 | V_8 ) ;
F_3 ( V_5 , V_3 + V_6 ) ;
}
static void F_7 ( void )
{
F_2 ( & V_1 ) ;
F_5 () ;
F_4 ( & V_1 ) ;
}
static void F_8 ( void )
{
unsigned long V_5 ;
F_2 ( & V_1 ) ;
F_5 () ;
V_5 = F_6 ( V_3 + V_6 ) ;
V_5 |= V_7 | V_9 ;
if ( V_10 ) {
V_5 |= V_11 ;
V_5 &= ~ V_8 ;
} else {
V_5 &= ~ V_11 ;
V_5 |= V_8 ;
}
F_9 ( L_1 ,
V_12 , V_2 , V_5 ) ;
F_3 ( V_2 , V_3 + V_13 ) ;
F_3 ( V_2 , V_3 + V_4 ) ;
F_3 ( V_5 , V_3 + V_6 ) ;
F_4 ( & V_1 ) ;
}
static inline int F_10 ( void )
{
return F_6 ( V_3 + V_6 ) & V_7 ;
}
static int F_11 ( int V_14 )
{
unsigned long V_15 = F_12 ( V_16 ) ;
unsigned int V_17 ;
unsigned int V_18 = 1 ;
unsigned long V_5 ;
if ( V_14 < 1 )
return - V_19 ;
V_15 /= 128 ;
V_17 = V_14 * V_15 ;
F_9 ( L_2 ,
V_12 , V_17 , V_14 , V_15 ) ;
if ( V_17 >= 0x10000 ) {
for ( V_18 = 1 ; V_18 <= 0x100 ; V_18 ++ ) {
if ( ( V_17 / V_18 ) < 0x10000 )
break;
}
if ( ( V_17 / V_18 ) >= 0x10000 ) {
F_13 ( V_20 , L_3 , V_14 ) ;
return - V_19 ;
}
}
V_21 = V_14 ;
F_9 ( L_4 ,
V_12 , V_14 , V_18 , V_17 , V_17 / V_18 ) ;
V_17 /= V_18 ;
V_2 = V_17 ;
V_5 = F_6 ( V_3 + V_6 ) ;
V_5 &= ~ V_22 ;
V_5 |= F_14 ( V_18 - 1 ) ;
F_3 ( V_17 , V_3 + V_13 ) ;
F_3 ( V_5 , V_3 + V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
if ( F_16 ( 0 , & V_25 ) )
return - V_26 ;
if ( V_27 )
F_17 ( V_28 ) ;
V_29 = 0 ;
F_8 () ;
return F_18 ( V_23 , V_24 ) ;
}
static int F_19 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
if ( V_29 == 42 )
F_7 () ;
else {
F_13 ( V_20 , L_5 ) ;
F_1 () ;
}
V_29 = 0 ;
F_20 ( 0 , & V_25 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_24 * V_24 , const char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
if ( V_31 ) {
if ( ! V_27 ) {
T_3 V_33 ;
V_29 = 0 ;
for ( V_33 = 0 ; V_33 != V_31 ; V_33 ++ ) {
char V_34 ;
if ( F_22 ( V_34 , V_30 + V_33 ) )
return - V_35 ;
if ( V_34 == 'V' )
V_29 = 42 ;
}
}
F_1 () ;
}
return V_31 ;
}
static long F_23 ( struct V_24 * V_24 , unsigned int V_36 ,
unsigned long V_37 )
{
void T_2 * V_38 = ( void T_2 * ) V_37 ;
int T_2 * V_39 = V_38 ;
int V_40 ;
switch ( V_36 ) {
case V_41 :
return F_24 ( V_38 , & V_42 ,
sizeof( V_42 ) ) ? - V_35 : 0 ;
case V_43 :
case V_44 :
return F_25 ( 0 , V_39 ) ;
case V_45 :
F_1 () ;
return 0 ;
case V_46 :
if ( F_22 ( V_40 , V_39 ) )
return - V_35 ;
if ( F_11 ( V_40 ) )
return - V_19 ;
F_1 () ;
return F_25 ( V_21 , V_39 ) ;
case V_47 :
return F_25 ( V_21 , V_39 ) ;
default:
return - V_48 ;
}
}
static T_5 F_26 ( int V_49 , void * V_50 )
{
F_27 ( V_20 , L_6 ) ;
F_1 () ;
return V_51 ;
}
static int F_28 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_30 )
{
int V_55 ;
if ( ! F_10 () )
goto V_56;
if ( V_54 == V_57 ) {
F_1 () ;
} else if ( V_54 == V_58 ) {
F_7 () ;
V_55 = F_11 ( V_21 ) ;
if ( V_55 >= 0 )
F_8 () ;
else
goto V_59;
}
V_56:
return 0 ;
V_59:
F_13 ( V_20 , L_7 , V_21 ) ;
return V_55 ;
}
static inline int F_29 ( void )
{
return F_30 ( & V_60 ,
V_61 ) ;
}
static inline void F_31 ( void )
{
F_32 ( & V_60 ,
V_61 ) ;
}
static inline int F_29 ( void )
{
return 0 ;
}
static inline void F_31 ( void )
{
}
static int T_6 F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
unsigned int V_5 ;
int V_66 = 0 ;
int V_55 ;
int V_67 ;
F_9 ( L_8 , V_12 , V_63 ) ;
V_65 = & V_63 -> V_65 ;
V_20 = & V_63 -> V_65 ;
V_68 = F_34 ( V_63 , V_69 , 0 ) ;
if ( V_68 == NULL ) {
F_13 ( V_65 , L_9 ) ;
return - V_70 ;
}
V_67 = F_35 ( V_68 ) ;
if ( ! F_36 ( V_68 -> V_71 , V_67 , V_63 -> V_72 ) ) {
F_13 ( V_65 , L_10 ) ;
return - V_26 ;
}
V_3 = F_37 ( V_68 -> V_71 , V_67 ) ;
if ( V_3 == NULL ) {
F_13 ( V_65 , L_11 ) ;
V_55 = - V_19 ;
goto V_73;
}
F_9 ( L_12 , V_3 ) ;
V_74 = F_34 ( V_63 , V_75 , 0 ) ;
if ( V_74 == NULL ) {
F_13 ( V_65 , L_13 ) ;
V_55 = - V_70 ;
goto V_76;
}
V_55 = F_38 ( V_74 -> V_71 , F_26 , 0 , V_63 -> V_72 , V_63 ) ;
if ( V_55 != 0 ) {
F_13 ( V_65 , L_14 , V_55 ) ;
goto V_76;
}
V_16 = F_39 ( & V_63 -> V_65 , L_15 ) ;
if ( F_40 ( V_16 ) ) {
F_13 ( V_65 , L_16 ) ;
V_55 = F_41 ( V_16 ) ;
goto V_77;
}
F_42 ( V_16 ) ;
if ( F_29 () < 0 ) {
F_43 (KERN_ERR PFX L_17 ) ;
goto V_78;
}
if ( F_11 ( V_21 ) ) {
V_66 = F_11 (
V_79 ) ;
if ( V_66 == 0 )
F_27 ( V_65 ,
L_18 ,
V_79 ) ;
else
F_27 ( V_65 , L_19
L_20 ) ;
}
V_55 = F_44 ( & V_80 ) ;
if ( V_55 ) {
F_13 ( V_65 , L_21 ,
V_81 , V_55 ) ;
goto V_82;
}
if ( V_83 && V_66 == 0 ) {
F_27 ( V_65 , L_22 ) ;
F_8 () ;
} else if ( ! V_83 ) {
F_7 () ;
}
V_5 = F_6 ( V_3 + V_6 ) ;
F_27 ( V_65 , L_23 ,
( V_5 & V_7 ) ? L_24 : L_25 ,
( V_5 & V_8 ) ? L_24 : L_26 ,
( V_5 & V_11 ) ? L_24 : L_27 ) ;
return 0 ;
V_82:
F_31 () ;
V_78:
F_45 ( V_16 ) ;
F_46 ( V_16 ) ;
V_77:
F_47 ( V_74 -> V_71 , V_63 ) ;
V_76:
F_48 ( V_3 ) ;
V_73:
F_49 ( V_68 -> V_71 , V_67 ) ;
V_68 = NULL ;
return V_55 ;
}
static int T_7 F_50 ( struct V_62 * V_65 )
{
F_51 ( & V_80 ) ;
F_31 () ;
F_45 ( V_16 ) ;
F_46 ( V_16 ) ;
V_16 = NULL ;
F_47 ( V_74 -> V_71 , V_65 ) ;
V_74 = NULL ;
F_48 ( V_3 ) ;
F_49 ( V_68 -> V_71 , F_35 ( V_68 ) ) ;
V_68 = NULL ;
return 0 ;
}
static void F_52 ( struct V_62 * V_65 )
{
F_7 () ;
}
static int F_53 ( struct V_62 * V_65 , T_8 V_84 )
{
V_85 = F_6 ( V_3 + V_6 ) ;
V_86 = F_6 ( V_3 + V_13 ) ;
F_7 () ;
return 0 ;
}
static int F_54 ( struct V_62 * V_65 )
{
F_3 ( V_86 , V_3 + V_13 ) ;
F_3 ( V_86 , V_3 + V_4 ) ;
F_3 ( V_85 , V_3 + V_6 ) ;
F_43 (KERN_INFO PFX L_28 ,
(wtcon_save & S3C2410_WTCON_ENABLE) ? L_27 : L_26 ) ;
return 0 ;
}
static int T_9 F_55 ( void )
{
F_43 ( V_87 ) ;
return F_56 ( & V_88 ) ;
}
static void T_10 F_57 ( void )
{
F_58 ( & V_88 ) ;
}
