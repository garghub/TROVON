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
static int F_7 ( struct V_13 * V_14 , struct V_15 * time )
{
unsigned long V_16 , V_17 ;
V_16 = mktime ( V_18 , 1 , 1 , 0 , 0 , 0 ) ;
V_17 = F_1 () ;
F_8 ( V_16 + V_17 , time ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , struct V_15 * time )
{
unsigned long V_16 , V_19 ;
V_16 = mktime ( V_18 , 1 , 1 , 0 , 0 , 0 ) ;
V_19 = mktime ( time -> V_20 + 1900 , time -> V_21 + 1 , time -> V_22 ,
time -> V_23 , time -> V_24 , time -> V_25 ) ;
F_3 ( V_19 - V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
unsigned long V_28 , V_29 , V_30 ;
struct V_15 * time = & V_27 -> time ;
F_4 ( & V_11 ) ;
V_28 = F_2 ( V_31 ) ;
V_29 = F_2 ( V_32 ) ;
V_30 = F_2 ( V_33 ) ;
V_27 -> V_34 = V_35 ;
F_6 ( & V_11 ) ;
F_8 ( ( V_30 << 17 ) | ( V_29 << 1 ) | ( V_28 >> 15 ) , time ) ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
unsigned long V_36 ;
struct V_15 * time = & V_27 -> time ;
V_36 = mktime ( time -> V_20 + 1900 , time -> V_21 + 1 , time -> V_22 ,
time -> V_23 , time -> V_24 , time -> V_25 ) ;
F_4 ( & V_11 ) ;
if ( V_35 )
F_12 ( V_37 ) ;
F_5 ( V_31 , ( V_12 ) ( V_36 << 15 ) ) ;
F_5 ( V_32 , ( V_12 ) ( V_36 >> 1 ) ) ;
F_5 ( V_33 , ( V_12 ) ( V_36 >> 17 ) ) ;
if ( V_27 -> V_34 )
F_13 ( V_37 ) ;
V_35 = V_27 -> V_34 ;
F_6 ( & V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , unsigned int V_38 , unsigned long V_39 )
{
switch ( V_38 ) {
case V_40 :
return F_15 ( V_18 , ( unsigned long V_41 * ) V_39 ) ;
case V_42 :
if ( V_39 < 1900 )
return - V_43 ;
V_18 = V_39 ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , unsigned int V_34 )
{
F_4 ( & V_11 ) ;
if ( V_34 ) {
if ( ! V_35 ) {
F_13 ( V_37 ) ;
V_35 = 1 ;
}
} else {
if ( V_35 ) {
F_12 ( V_37 ) ;
V_35 = 0 ;
}
}
F_6 ( & V_11 ) ;
return 0 ;
}
static T_1 F_17 ( int V_45 , void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
struct V_49 * V_50 = F_18 ( V_48 ) ;
F_19 ( V_51 , V_52 ) ;
F_20 ( V_50 , 1 , V_53 ) ;
return V_54 ;
}
static T_1 F_21 ( int V_45 , void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
struct V_49 * V_50 = F_18 ( V_48 ) ;
unsigned long V_55 = V_56 ;
F_19 ( V_51 , V_57 ) ;
F_5 ( V_58 , V_55 ) ;
F_5 ( V_59 , V_55 >> 16 ) ;
F_20 ( V_50 , 1 , V_60 ) ;
return V_54 ;
}
static int F_22 ( struct V_47 * V_48 )
{
struct V_61 * V_62 ;
struct V_49 * V_50 ;
int V_63 ;
if ( V_48 -> V_64 != 4 )
return - V_65 ;
V_62 = F_23 ( V_48 , V_66 , 0 ) ;
if ( ! V_62 )
return - V_65 ;
V_67 = F_24 ( & V_48 -> V_14 , V_62 -> V_68 , F_25 ( V_62 ) ) ;
if ( ! V_67 )
return - V_65 ;
V_62 = F_23 ( V_48 , V_66 , 1 ) ;
if ( ! V_62 ) {
V_63 = - V_65 ;
goto V_69;
}
V_70 = F_24 ( & V_48 -> V_14 , V_62 -> V_68 , F_25 ( V_62 ) ) ;
if ( ! V_70 ) {
V_63 = - V_65 ;
goto V_69;
}
V_50 = F_26 ( & V_48 -> V_14 , V_71 , & V_72 ,
V_73 ) ;
if ( F_27 ( V_50 ) ) {
V_63 = F_28 ( V_50 ) ;
goto V_74;
}
V_50 -> V_75 = V_76 ;
F_4 ( & V_11 ) ;
F_5 ( V_31 , 0 ) ;
F_5 ( V_32 , 0 ) ;
F_5 ( V_33 , 0 ) ;
F_5 ( V_58 , 0 ) ;
F_5 ( V_59 , 0 ) ;
F_6 ( & V_11 ) ;
V_37 = F_29 ( V_48 , 0 ) ;
if ( V_37 <= 0 ) {
V_63 = - V_65 ;
goto V_74;
}
V_63 = F_30 ( & V_48 -> V_14 , V_37 , F_17 , 0 ,
L_1 , V_48 ) ;
if ( V_63 < 0 )
goto V_74;
V_77 = F_29 ( V_48 , 1 ) ;
if ( V_77 <= 0 ) {
V_63 = - V_65 ;
goto V_74;
}
V_63 = F_30 ( & V_48 -> V_14 , V_77 , F_21 , 0 ,
L_2 , V_48 ) ;
if ( V_63 < 0 )
goto V_74;
F_31 ( V_48 , V_50 ) ;
F_12 ( V_37 ) ;
F_12 ( V_77 ) ;
F_32 ( & V_48 -> V_14 , L_3 ) ;
return 0 ;
V_74:
V_70 = NULL ;
V_69:
V_67 = NULL ;
return V_63 ;
}
