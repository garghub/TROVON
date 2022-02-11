static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_5 , V_3 ) ;
V_6 = V_7 + ( V_8 * V_9 ) ;
F_3 ( & V_2 -> V_10 , F_4 ( V_11 ) ) ;
V_4 = F_5 () ;
V_4 |= V_12 | V_11 ;
F_6 ( V_4 ) ;
F_7 ( 0 ) ;
V_4 = F_5 () ;
V_4 |= V_13 ;
V_4 &= ~ V_14 ;
F_6 ( V_4 ) ;
#ifdef F_8
V_4 = F_9 () ;
V_4 &= ~ V_15 ;
F_10 ( V_4 ) ;
#endif
F_11 ( & V_5 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_5 , V_3 ) ;
F_13 ( & V_2 -> V_10 ) ;
V_4 = F_5 () ;
V_4 &= ~ V_13 ;
F_6 ( V_4 ) ;
F_11 ( & V_5 , V_3 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_5 , V_3 ) ;
V_6 = V_7 + ( V_8 * V_9 ) ;
F_11 ( & V_5 , V_3 ) ;
}
static int F_15 ( int V_16 )
{
unsigned long V_3 ;
if ( F_16 ( V_16 < 1 || V_16 > 3600 ) )
return - V_17 ;
F_2 ( & V_5 , V_3 ) ;
V_8 = V_16 ;
F_11 ( & V_5 , V_3 ) ;
return 0 ;
}
static void F_17 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
unsigned long V_3 ;
F_2 ( & V_5 , V_3 ) ;
if ( F_18 ( V_7 , V_6 ) ) {
T_1 V_4 ;
V_4 = F_5 () ;
V_4 &= ~ V_19 ;
F_6 ( V_4 ) ;
F_7 ( 0 ) ;
F_3 ( & V_2 -> V_10 , F_4 ( V_11 ) ) ;
} else
F_19 ( V_2 -> V_20 , L_1
L_2 ) ;
F_11 ( & V_5 , V_3 ) ;
}
static int F_20 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
if ( F_22 ( 0 , & V_2 -> V_24 ) )
return - V_25 ;
if ( V_26 )
F_23 ( V_27 ) ;
V_22 -> V_28 = V_2 ;
F_1 ( V_2 ) ;
return F_24 ( V_21 , V_22 ) ;
}
static int F_25 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_28 ;
if ( V_2 -> V_29 == 42 ) {
F_12 ( V_2 ) ;
} else {
F_26 ( V_2 -> V_20 , L_3
L_4 ) ;
F_14 ( V_2 ) ;
}
F_27 ( 0 , & V_2 -> V_24 ) ;
V_2 -> V_29 = 0 ;
return 0 ;
}
static T_2 F_28 ( struct V_22 * V_22 , const char * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_1 * V_2 = V_22 -> V_28 ;
if ( V_31 ) {
if ( ! V_26 ) {
T_3 V_33 ;
V_2 -> V_29 = 0 ;
for ( V_33 = 0 ; V_33 != V_31 ; V_33 ++ ) {
char V_34 ;
if ( F_29 ( V_34 , V_30 + V_33 ) )
return - V_35 ;
if ( V_34 == 'V' )
V_2 -> V_29 = 42 ;
}
}
F_14 ( V_2 ) ;
}
return V_31 ;
}
static long F_30 ( struct V_22 * V_22 , unsigned int V_36 ,
unsigned long V_37 )
{
struct V_1 * V_2 = V_22 -> V_28 ;
int V_38 ;
int V_39 , V_40 = - V_17 ;
switch ( V_36 ) {
case V_41 :
return F_31 ( (struct V_42 * ) V_37 ,
& V_43 , sizeof( V_43 ) ) ? - V_35 : 0 ;
case V_44 :
case V_45 :
return F_32 ( 0 , ( int * ) V_37 ) ;
case V_46 :
if ( F_29 ( V_39 , ( int * ) V_37 ) )
return - V_35 ;
if ( V_39 & V_47 ) {
F_12 ( V_2 ) ;
V_40 = 0 ;
}
if ( V_39 & V_48 ) {
F_1 ( V_2 ) ;
V_40 = 0 ;
}
return V_40 ;
case V_49 :
F_14 ( V_2 ) ;
return 0 ;
case V_50 :
if ( F_29 ( V_38 , ( int * ) V_37 ) )
return - V_35 ;
if ( F_15 ( V_38 ) )
return - V_17 ;
F_14 ( V_2 ) ;
case V_51 :
return F_32 ( V_8 , ( int * ) V_37 ) ;
default:
return - V_52 ;
}
return 0 ;
}
static int F_33 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
if ( V_55 == V_57 || V_55 == V_58 )
F_12 ( V_2 ) ;
return V_59 ;
}
static int T_5 F_34 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
struct V_62 * V_63 ;
int V_64 ;
if ( V_61 -> V_65 != - 1 )
return - V_17 ;
V_63 = F_35 ( V_61 , V_66 , 0 ) ;
if ( F_16 ( ! V_63 ) )
return - V_17 ;
if ( ! F_36 ( & V_61 -> V_20 , V_63 -> V_67 ,
F_37 ( V_63 ) , V_68 ) )
return - V_25 ;
V_2 = F_38 ( & V_61 -> V_20 , sizeof( struct V_1 ) , V_69 ) ;
if ( F_16 ( ! V_2 ) ) {
V_64 = - V_70 ;
goto V_71;
}
V_2 -> V_20 = & V_61 -> V_20 ;
V_2 -> V_72 = F_39 ( & V_61 -> V_20 , V_63 -> V_67 , F_37 ( V_63 ) ) ;
if ( F_16 ( ! V_2 -> V_72 ) ) {
V_64 = - V_73 ;
goto V_74;
}
V_64 = F_40 ( & V_75 ) ;
if ( F_16 ( V_64 ) ) {
F_41 ( & V_61 -> V_20 ,
L_5 , V_64 ) ;
goto V_76;
}
V_77 . V_78 = V_2 -> V_20 ;
V_64 = F_42 ( & V_77 ) ;
if ( F_16 ( V_64 ) ) {
F_41 ( & V_61 -> V_20 ,
L_6 ,
V_77 . V_79 , V_64 ) ;
goto V_80;
}
F_43 ( & V_2 -> V_10 ) ;
V_2 -> V_10 . V_81 = F_17 ;
V_2 -> V_10 . V_18 = ( unsigned long ) V_2 ;
V_2 -> V_10 . V_82 = F_4 ( V_11 ) ;
F_44 ( V_61 , V_2 ) ;
V_23 = V_61 ;
F_45 ( & V_61 -> V_20 , L_7 ) ;
return 0 ;
V_80:
F_46 ( & V_75 ) ;
V_76:
F_47 ( & V_61 -> V_20 , V_2 -> V_72 ) ;
V_74:
F_48 ( & V_61 -> V_20 , V_2 ) ;
V_71:
F_49 ( & V_61 -> V_20 , V_63 -> V_67 , F_37 ( V_63 ) ) ;
return V_64 ;
}
static int T_6 F_50 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_21 ( V_61 ) ;
struct V_62 * V_63 = F_35 ( V_61 , V_66 , 0 ) ;
F_44 ( V_61 , NULL ) ;
F_51 ( & V_77 ) ;
V_23 = NULL ;
F_46 ( & V_75 ) ;
F_49 ( & V_61 -> V_20 , V_63 -> V_67 , F_37 ( V_63 ) ) ;
F_47 ( & V_61 -> V_20 , V_2 -> V_72 ) ;
F_48 ( & V_61 -> V_20 , V_2 ) ;
return 0 ;
}
static int T_7 F_52 ( void )
{
int V_64 ;
if ( F_16 ( V_11 < 0x5 ||
V_11 > 0x7 ) ) {
V_11 = V_83 ;
F_53 ( L_8 ,
V_11 ) ;
}
V_64 = F_15 ( V_8 ) ;
if ( F_16 ( V_64 ) ) {
V_8 = V_84 ;
F_53 ( L_9 ,
V_8 ) ;
}
F_53 ( L_10 ,
V_8 , V_26 ) ;
return F_54 ( & V_85 ) ;
}
static void T_8 F_55 ( void )
{
F_56 ( & V_85 ) ;
}
