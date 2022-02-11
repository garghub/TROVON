static inline unsigned long F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 ;
unsigned long V_4 , V_5 , V_6 ;
do {
V_1 = F_2 ( V_7 ) ;
V_2 = F_2 ( V_8 ) ;
V_3 = F_2 ( V_9 ) ;
V_4 = F_2 ( V_7 ) ;
V_5 = F_2 ( V_8 ) ;
V_6 = F_2 ( V_9 ) ;
} while ( V_1 != V_4 || V_2 != V_5 ||
V_3 != V_6 );
return ( V_3 << 17 ) | ( V_2 << 1 ) | ( V_1 >> 15 ) ;
}
static inline void F_3 ( unsigned long V_10 )
{
F_4 ( & V_11 ) ;
F_5 ( V_7 , ( V_12 ) ( V_10 << 15 ) ) ;
F_5 ( V_8 , ( V_12 ) ( V_10 >> 1 ) ) ;
F_5 ( V_9 , ( V_12 ) ( V_10 >> 17 ) ) ;
F_6 ( & V_11 ) ;
}
static void F_7 ( struct V_13 * V_14 )
{
F_4 ( & V_11 ) ;
F_5 ( V_15 , 0 ) ;
F_5 ( V_16 , 0 ) ;
F_5 ( V_17 , 0 ) ;
F_5 ( V_18 , 0 ) ;
F_5 ( V_19 , 0 ) ;
F_6 ( & V_11 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
}
static int F_9 ( struct V_13 * V_14 , struct V_22 * time )
{
unsigned long V_23 , V_24 ;
V_23 = mktime ( V_25 , 1 , 1 , 0 , 0 , 0 ) ;
V_24 = F_1 () ;
F_10 ( V_23 + V_24 , time ) ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 , struct V_22 * time )
{
unsigned long V_23 , V_26 ;
V_23 = mktime ( V_25 , 1 , 1 , 0 , 0 , 0 ) ;
V_26 = mktime ( time -> V_27 + 1900 , time -> V_28 + 1 , time -> V_29 ,
time -> V_30 , time -> V_31 , time -> V_32 ) ;
F_3 ( V_26 - V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
unsigned long V_35 , V_36 , V_37 ;
struct V_22 * time = & V_34 -> time ;
F_4 ( & V_11 ) ;
V_35 = F_2 ( V_15 ) ;
V_36 = F_2 ( V_16 ) ;
V_37 = F_2 ( V_17 ) ;
V_34 -> V_38 = V_39 ;
F_6 ( & V_11 ) ;
F_10 ( ( V_37 << 17 ) | ( V_36 << 1 ) | ( V_35 >> 15 ) , time ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
unsigned long V_40 ;
struct V_22 * time = & V_34 -> time ;
V_40 = mktime ( time -> V_27 + 1900 , time -> V_28 + 1 , time -> V_29 ,
time -> V_30 , time -> V_31 , time -> V_32 ) ;
F_4 ( & V_11 ) ;
if ( V_39 )
F_8 ( V_20 ) ;
F_5 ( V_15 , ( V_12 ) ( V_40 << 15 ) ) ;
F_5 ( V_16 , ( V_12 ) ( V_40 >> 1 ) ) ;
F_5 ( V_17 , ( V_12 ) ( V_40 >> 17 ) ) ;
if ( V_34 -> V_38 )
F_14 ( V_20 ) ;
V_39 = V_34 -> V_38 ;
F_6 ( & V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , unsigned int V_41 , unsigned long V_42 )
{
switch ( V_41 ) {
case V_43 :
return F_16 ( V_25 , ( unsigned long V_44 * ) V_42 ) ;
case V_45 :
if ( V_42 < 1900 )
return - V_46 ;
V_25 = V_42 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_17 ( struct V_13 * V_14 , unsigned int V_38 )
{
F_4 ( & V_11 ) ;
if ( V_38 ) {
if ( ! V_39 ) {
F_14 ( V_20 ) ;
V_39 = 1 ;
}
} else {
if ( V_39 ) {
F_8 ( V_20 ) ;
V_39 = 0 ;
}
}
F_6 ( & V_11 ) ;
return 0 ;
}
static T_1 F_18 ( int V_48 , void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_49 ;
struct V_52 * V_53 = F_19 ( V_51 ) ;
F_20 ( V_54 , V_55 ) ;
F_21 ( V_53 , 1 , V_56 ) ;
return V_57 ;
}
static T_1 F_22 ( int V_48 , void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_49 ;
struct V_52 * V_53 = F_19 ( V_51 ) ;
unsigned long V_58 = V_59 ;
F_20 ( V_54 , V_60 ) ;
F_5 ( V_18 , V_58 ) ;
F_5 ( V_19 , V_58 >> 16 ) ;
F_21 ( V_53 , 1 , V_61 ) ;
return V_57 ;
}
static int T_2 F_23 ( struct V_50 * V_51 )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
int V_64 ;
if ( V_51 -> V_65 != 4 )
return - V_66 ;
V_63 = F_24 ( V_51 , V_67 , 0 ) ;
if ( ! V_63 )
return - V_66 ;
V_68 = F_25 ( V_63 -> V_69 , F_26 ( V_63 ) ) ;
if ( ! V_68 )
return - V_66 ;
V_63 = F_24 ( V_51 , V_67 , 1 ) ;
if ( ! V_63 ) {
V_64 = - V_66 ;
goto V_70;
}
V_71 = F_25 ( V_63 -> V_69 , F_26 ( V_63 ) ) ;
if ( ! V_71 ) {
V_64 = - V_66 ;
goto V_70;
}
V_53 = F_27 ( V_72 , & V_51 -> V_14 , & V_73 , V_74 ) ;
if ( F_28 ( V_53 ) ) {
V_64 = F_29 ( V_53 ) ;
goto V_75;
}
V_53 -> V_76 = V_77 ;
F_4 ( & V_11 ) ;
F_5 ( V_15 , 0 ) ;
F_5 ( V_16 , 0 ) ;
F_5 ( V_17 , 0 ) ;
F_5 ( V_18 , 0 ) ;
F_5 ( V_19 , 0 ) ;
F_6 ( & V_11 ) ;
V_20 = F_30 ( V_51 , 0 ) ;
if ( V_20 <= 0 ) {
V_64 = - V_66 ;
goto V_78;
}
V_64 = F_31 ( V_20 , F_18 , V_79 ,
L_1 , V_51 ) ;
if ( V_64 < 0 )
goto V_78;
V_21 = F_30 ( V_51 , 1 ) ;
if ( V_21 <= 0 )
goto V_80;
V_64 = F_31 ( V_21 , F_22 , V_79 ,
L_2 , V_51 ) ;
if ( V_64 < 0 )
goto V_80;
F_32 ( V_51 , V_53 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_33 ( V_81 L_3 ) ;
return 0 ;
V_80:
F_34 ( V_20 , V_51 ) ;
V_78:
F_35 ( V_53 ) ;
V_75:
F_36 ( V_71 ) ;
V_71 = NULL ;
V_70:
F_36 ( V_68 ) ;
V_68 = NULL ;
return V_64 ;
}
static int T_3 F_37 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
V_53 = F_19 ( V_51 ) ;
if ( V_53 )
F_35 ( V_53 ) ;
F_32 ( V_51 , NULL ) ;
F_34 ( V_20 , V_51 ) ;
F_34 ( V_21 , V_51 ) ;
if ( V_68 )
F_36 ( V_68 ) ;
if ( V_71 )
F_36 ( V_71 ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_82 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_82 ) ;
}
