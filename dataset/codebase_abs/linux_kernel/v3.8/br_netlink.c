static inline T_1 F_1 ( void )
{
return F_2 ( 1 )
+ F_2 ( 2 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ 0 ;
}
static inline T_1 F_3 ( void )
{
return F_4 ( sizeof( struct V_1 ) )
+ F_2 ( V_2 )
+ F_2 ( V_3 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( F_1 () ) ;
}
static int F_5 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
T_2 V_8 = ! ! ( V_7 -> V_9 & V_10 ) ;
if ( F_6 ( V_5 , V_11 , V_7 -> V_12 ) ||
F_7 ( V_5 , V_13 , V_7 -> V_14 ) ||
F_8 ( V_5 , V_15 , V_7 -> V_16 ) ||
F_6 ( V_5 , V_17 , V_8 ) ||
F_6 ( V_5 , V_18 , ! ! ( V_7 -> V_9 & V_19 ) ) ||
F_6 ( V_5 , V_20 , ! ! ( V_7 -> V_9 & V_21 ) ) ||
F_6 ( V_5 , V_22 , ! ! ( V_7 -> V_9 & V_23 ) ) )
return - V_24 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , const struct V_6 * V_25 ,
T_3 V_26 , T_3 V_27 , int V_28 , unsigned int V_9 )
{
const struct V_29 * V_30 = V_25 -> V_30 ;
const struct V_31 * V_32 = V_25 -> V_32 ;
struct V_1 * V_33 ;
struct V_34 * V_35 ;
T_2 V_36 = F_10 ( V_32 ) ? V_32 -> V_36 : V_37 ;
F_11 ( V_30 , L_1 ,
V_28 , V_32 -> V_38 , V_30 -> V_32 -> V_38 ) ;
V_35 = F_12 ( V_5 , V_26 , V_27 , V_28 , sizeof( * V_33 ) , V_9 ) ;
if ( V_35 == NULL )
return - V_24 ;
V_33 = F_13 ( V_35 ) ;
V_33 -> V_39 = V_40 ;
V_33 -> V_41 = 0 ;
V_33 -> V_42 = V_32 -> type ;
V_33 -> V_43 = V_32 -> V_44 ;
V_33 -> V_45 = F_14 ( V_32 ) ;
V_33 -> V_46 = 0 ;
if ( F_15 ( V_5 , V_47 , V_32 -> V_38 ) ||
F_8 ( V_5 , V_48 , V_30 -> V_32 -> V_44 ) ||
F_8 ( V_5 , V_49 , V_32 -> V_50 ) ||
F_6 ( V_5 , V_51 , V_36 ) ||
( V_32 -> V_52 &&
F_16 ( V_5 , V_53 , V_32 -> V_52 , V_32 -> V_54 ) ) ||
( V_32 -> V_44 != V_32 -> V_55 &&
F_8 ( V_5 , V_56 , V_32 -> V_55 ) ) )
goto V_57;
if ( V_28 == V_58 ) {
struct V_59 * V_60
= F_17 ( V_5 , V_61 | V_62 ) ;
if ( V_60 == NULL || F_5 ( V_5 , V_25 ) < 0 )
goto V_57;
F_18 ( V_5 , V_60 ) ;
}
return F_19 ( V_5 , V_35 ) ;
V_57:
F_20 ( V_5 , V_35 ) ;
return - V_24 ;
}
void F_21 ( int V_28 , struct V_6 * V_25 )
{
struct V_63 * V_63 = F_22 ( V_25 -> V_32 ) ;
struct V_4 * V_5 ;
int V_64 = - V_65 ;
F_11 ( V_25 -> V_30 , L_2 ,
( unsigned int ) V_25 -> V_66 , V_25 -> V_32 -> V_38 , V_28 ) ;
V_5 = F_23 ( F_3 () , V_67 ) ;
if ( V_5 == NULL )
goto V_68;
V_64 = F_9 ( V_5 , V_25 , 0 , 0 , V_28 , 0 ) ;
if ( V_64 < 0 ) {
F_24 ( V_64 == - V_24 ) ;
F_25 ( V_5 ) ;
goto V_68;
}
F_26 ( V_5 , V_63 , 0 , V_69 , NULL , V_67 ) ;
return;
V_68:
if ( V_64 < 0 )
F_27 ( V_63 , V_69 , V_64 ) ;
}
int F_28 ( struct V_4 * V_5 , T_3 V_26 , T_3 V_27 ,
struct V_31 * V_32 )
{
int V_64 = 0 ;
struct V_6 * V_25 = F_29 ( V_32 ) ;
if ( ! V_25 )
goto V_70;
V_64 = F_9 ( V_5 , V_25 , V_26 , V_27 , V_58 , V_71 ) ;
V_70:
return V_64 ;
}
static int F_30 ( struct V_6 * V_7 , T_2 V_12 )
{
if ( V_12 > V_72 )
return - V_73 ;
if ( V_7 -> V_30 -> V_74 == V_75 )
return - V_76 ;
if ( ! F_10 ( V_7 -> V_32 ) ||
( ! F_31 ( V_7 -> V_32 ) && V_12 != V_77 ) )
return - V_78 ;
V_7 -> V_12 = V_12 ;
F_32 ( V_7 ) ;
F_33 ( V_7 -> V_30 ) ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 , struct V_59 * V_79 [] ,
int V_80 , unsigned long V_81 )
{
if ( V_79 [ V_80 ] ) {
T_2 V_82 = F_35 ( V_79 [ V_80 ] ) ;
if ( V_82 )
V_7 -> V_9 |= V_81 ;
else
V_7 -> V_9 &= ~ V_81 ;
}
}
static int F_36 ( struct V_6 * V_7 , struct V_59 * V_79 [] )
{
int V_64 ;
F_34 ( V_7 , V_79 , V_17 , V_10 ) ;
F_34 ( V_7 , V_79 , V_18 , V_19 ) ;
F_34 ( V_7 , V_79 , V_22 , V_23 ) ;
if ( V_79 [ V_15 ] ) {
V_64 = F_37 ( V_7 , F_38 ( V_79 [ V_15 ] ) ) ;
if ( V_64 )
return V_64 ;
}
if ( V_79 [ V_13 ] ) {
V_64 = F_39 ( V_7 , F_40 ( V_79 [ V_13 ] ) ) ;
if ( V_64 )
return V_64 ;
}
if ( V_79 [ V_11 ] ) {
V_64 = F_30 ( V_7 , F_35 ( V_79 [ V_11 ] ) ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
int F_41 ( struct V_31 * V_32 , struct V_34 * V_35 )
{
struct V_1 * V_83 ;
struct V_59 * V_84 ;
struct V_6 * V_7 ;
struct V_59 * V_79 [ V_85 + 1 ] ;
int V_64 ;
V_83 = F_13 ( V_35 ) ;
V_84 = F_42 ( V_35 , sizeof( * V_83 ) , V_61 ) ;
if ( ! V_84 )
return 0 ;
V_7 = F_43 ( V_32 ) ;
if ( ! V_7 )
return - V_73 ;
if ( V_84 -> V_86 & V_62 ) {
V_64 = F_44 ( V_79 , V_85 ,
V_84 , V_87 ) ;
if ( V_64 )
return V_64 ;
F_45 ( & V_7 -> V_30 -> V_88 ) ;
V_64 = F_36 ( V_7 , V_79 ) ;
F_46 ( & V_7 -> V_30 -> V_88 ) ;
} else {
if ( F_47 ( V_84 ) < sizeof( T_2 ) )
return - V_73 ;
F_45 ( & V_7 -> V_30 -> V_88 ) ;
V_64 = F_30 ( V_7 , F_35 ( V_84 ) ) ;
F_46 ( & V_7 -> V_30 -> V_88 ) ;
}
if ( V_64 == 0 )
F_21 ( V_58 , V_7 ) ;
return V_64 ;
}
static int F_48 ( struct V_59 * V_79 [] , struct V_59 * V_89 [] )
{
if ( V_79 [ V_53 ] ) {
if ( F_47 ( V_79 [ V_53 ] ) != V_90 )
return - V_73 ;
if ( ! F_49 ( F_50 ( V_79 [ V_53 ] ) ) )
return - V_91 ;
}
return 0 ;
}
int T_4 F_51 ( void )
{
int V_64 ;
F_52 () ;
V_64 = F_53 ( & V_92 ) ;
if ( V_64 )
goto V_70;
return 0 ;
V_70:
F_54 () ;
return V_64 ;
}
void T_5 F_55 ( void )
{
F_54 () ;
F_56 ( & V_92 ) ;
}
