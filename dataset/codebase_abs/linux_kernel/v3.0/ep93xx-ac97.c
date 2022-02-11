static inline unsigned F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static unsigned short F_5 ( struct V_6 * V_7 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_1 ;
unsigned short V_5 ;
F_6 ( & V_2 -> V_8 ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
F_3 ( V_2 , V_10 , V_11 ) ;
if ( ! F_7 ( & V_2 -> V_12 , V_13 ) ) {
F_8 ( V_2 -> V_14 , L_1 , V_3 ) ;
F_9 ( & V_2 -> V_8 ) ;
return - V_15 ;
}
V_5 = ( unsigned short ) F_1 ( V_2 , V_16 ) ;
F_9 ( & V_2 -> V_8 ) ;
return V_5 ;
}
static void F_10 ( struct V_6 * V_7 ,
unsigned short V_3 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_1 ;
F_6 ( & V_2 -> V_8 ) ;
F_3 ( V_2 , V_16 , V_5 ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
F_3 ( V_2 , V_10 , V_17 ) ;
if ( ! F_7 ( & V_2 -> V_12 , V_13 ) )
F_8 ( V_2 -> V_14 , L_2 , V_3 ) ;
F_9 ( & V_2 -> V_8 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_1 ;
F_6 ( & V_2 -> V_8 ) ;
F_3 ( V_2 , V_18 , V_19 ) ;
F_3 ( V_2 , V_10 , V_20 ) ;
if ( ! F_7 ( & V_2 -> V_12 , V_13 ) )
F_8 ( V_2 -> V_14 , L_3 ) ;
F_9 ( & V_2 -> V_8 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_1 ;
F_6 ( & V_2 -> V_8 ) ;
F_3 ( V_2 , V_21 , 0 ) ;
F_3 ( V_2 , V_22 , V_23 | V_24 ) ;
F_3 ( V_2 , V_21 , V_25 ) ;
F_3 ( V_2 , V_26 , V_27 ) ;
F_3 ( V_2 , V_10 , V_20 ) ;
if ( ! F_7 ( & V_2 -> V_12 , V_13 ) )
F_8 ( V_2 -> V_14 , L_4 ) ;
F_13 ( 15000 , 20000 ) ;
F_9 ( & V_2 -> V_8 ) ;
}
static T_1 F_14 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
unsigned V_30 , V_31 ;
V_30 = F_1 ( V_2 , V_32 ) ;
V_31 = F_1 ( V_2 , V_10 ) ;
V_31 &= ~ V_30 ;
F_3 ( V_2 , V_10 , V_31 ) ;
F_15 ( & V_2 -> V_12 ) ;
return V_33 ;
}
static int F_16 ( struct V_34 * V_35 ,
int V_36 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_17 ( V_38 ) ;
unsigned V_39 = 0 ;
switch ( V_36 ) {
case V_40 :
case V_41 :
case V_42 :
if ( V_35 -> V_43 == V_44 ) {
V_39 |= V_45 ;
V_39 |= V_46 | V_47 ;
V_39 |= V_48 ;
F_3 ( V_2 , F_18 ( 1 ) , V_39 ) ;
} else {
V_39 |= V_49 ;
V_39 |= V_50 | V_51 ;
V_39 |= V_52 ;
F_3 ( V_2 , F_19 ( 1 ) , V_39 ) ;
}
break;
case V_53 :
case V_54 :
case V_55 :
if ( V_35 -> V_43 == V_44 ) {
unsigned long V_56 = V_57 + V_13 ;
do {
V_39 = F_1 ( V_2 , F_20 ( 1 ) ) ;
if ( F_21 ( V_57 , V_56 ) ) {
F_8 ( V_2 -> V_14 , L_5 ) ;
break;
}
} while ( ! ( V_39 & ( V_58 | V_59 ) ) );
F_3 ( V_2 , F_18 ( 1 ) , 0 ) ;
} else {
F_3 ( V_2 , F_19 ( 1 ) , 0 ) ;
}
break;
default:
F_8 ( V_2 -> V_14 , L_6 , V_36 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_22 ( struct V_34 * V_35 ,
struct V_37 * V_38 )
{
struct V_61 * V_62 ;
if ( V_35 -> V_43 == V_44 )
V_62 = & V_63 ;
else
V_62 = & V_64 ;
F_23 ( V_38 , V_35 , V_62 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
int V_67 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
F_26 ( & V_66 -> V_14 , V_2 ) ;
F_27 ( & V_2 -> V_8 ) ;
F_28 ( & V_2 -> V_12 ) ;
V_2 -> V_14 = & V_66 -> V_14 ;
V_2 -> V_70 = F_29 ( V_66 , V_71 , 0 ) ;
if ( ! V_2 -> V_70 ) {
V_67 = - V_72 ;
goto V_73;
}
V_2 -> V_28 = F_30 ( V_66 , 0 ) ;
if ( ! V_2 -> V_28 ) {
V_67 = - V_72 ;
goto V_73;
}
if ( ! F_31 ( V_2 -> V_70 -> V_74 , F_32 ( V_2 -> V_70 ) ,
V_66 -> V_75 ) ) {
V_67 = - V_76 ;
goto V_73;
}
V_2 -> V_4 = F_33 ( V_2 -> V_70 -> V_74 , F_32 ( V_2 -> V_70 ) ) ;
if ( ! V_2 -> V_4 ) {
V_67 = - V_69 ;
goto V_77;
}
V_67 = F_34 ( V_2 -> V_28 , F_14 , V_78 ,
V_66 -> V_75 , V_2 ) ;
if ( V_67 )
goto V_79;
V_1 = V_2 ;
F_35 ( V_66 , V_2 ) ;
V_67 = F_36 ( & V_66 -> V_14 , & V_80 ) ;
if ( V_67 )
goto V_81;
return 0 ;
V_81:
F_35 ( V_66 , NULL ) ;
F_37 ( V_2 -> V_28 , V_2 ) ;
V_79:
F_38 ( V_2 -> V_4 ) ;
V_77:
F_39 ( V_2 -> V_70 -> V_74 , F_32 ( V_2 -> V_70 ) ) ;
V_73:
F_40 ( V_2 ) ;
return V_67 ;
}
static int T_3 F_41 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_42 ( V_66 ) ;
F_43 ( & V_66 -> V_14 ) ;
F_3 ( V_2 , V_21 , 0 ) ;
F_37 ( V_2 -> V_28 , V_2 ) ;
F_38 ( V_2 -> V_4 ) ;
F_39 ( V_2 -> V_70 -> V_74 , F_32 ( V_2 -> V_70 ) ) ;
F_35 ( V_66 , NULL ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_82 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_82 ) ;
}
