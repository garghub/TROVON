static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
return F_2 ( V_5 , struct V_1 , V_7 ) ;
}
static int F_3 ( struct V_4 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
F_4 ( 20 ) ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_9 = F_6 ( V_7 , V_11 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
return ( V_9 & ( V_12 | V_13 ) ) != V_12 ;
}
static int F_8 ( struct V_1 * V_14 ,
T_1 V_15 , T_2 V_16 , T_2 V_17 )
{
unsigned int V_18 ;
unsigned long V_8 ;
struct V_4 * V_7 = & V_14 -> V_7 ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_18 = V_19 | ( ( V_15 << V_20 ) & V_21 ) ;
V_18 |= V_22 ;
V_18 |= V_23 ;
F_9 ( V_7 , V_24 , V_18 ) ;
( void ) F_6 ( V_7 , V_11 ) ;
V_18 = V_17 | ( ( V_16 << V_25 ) & V_26 ) ;
F_9 ( V_7 , V_11 , V_18 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
F_10 ( 2 ) ;
F_11 ( V_14 -> V_27 , F_3 ( V_7 ) ,
V_28 ) ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_18 = F_6 ( V_7 , V_11 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
if ( V_18 & V_12 ) {
F_12 ( V_14 , L_1 , V_15 ,
V_16 , V_17 ) ;
return - V_29 ;
}
if ( V_18 & V_13 ) {
F_12 ( V_14 , L_2 , V_15 ,
V_16 , V_17 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
F_4 ( 20 ) ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_9 = F_6 ( V_7 , V_11 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
return V_9 & ( V_30 | V_13 ) ;
}
static int F_14 ( struct V_1 * V_14 ,
T_1 V_15 , T_2 V_16 , T_2 * V_17 )
{
unsigned int V_18 ;
unsigned long V_8 ;
struct V_4 * V_7 = & V_14 -> V_7 ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_18 = V_19 | ( ( V_15 << V_20 ) & V_21 ) ;
V_18 |= V_22 ;
V_18 |= V_23 ;
F_9 ( V_7 , V_24 , V_18 ) ;
( void ) F_6 ( V_7 , V_11 ) ;
V_18 = V_31 | ( ( V_16 << V_25 ) & V_26 ) ;
F_9 ( V_7 , V_11 , V_18 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
F_11 ( V_14 -> V_27 ,
F_13 ( V_7 ) , V_28 ) ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
V_18 = F_6 ( V_7 , V_11 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
if ( V_18 & V_13 ) {
F_12 ( V_14 , L_3 , V_15 , V_16 ) ;
return - V_29 ;
}
if ( ! ( V_18 & V_30 ) ) {
F_12 ( V_14 , L_4 , V_15 ,
V_16 ) ;
return - V_29 ;
}
* V_17 = V_18 & 0xff ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 , T_1 V_15 ,
unsigned short V_8 , char V_34 , T_2 V_16 ,
int V_35 , union V_36 * V_37 )
{
struct V_1 * V_14 = F_16 ( V_33 ) ;
int V_38 = - V_39 ;
if ( V_35 != V_40 ) {
F_12 ( V_14 , L_5 , V_35 ) ;
return - V_39 ;
}
if ( V_34 == V_41 )
V_38 = F_8 ( V_14 , V_15 , V_16 , V_37 -> V_42 ) ;
else if ( V_34 == V_43 )
V_38 = F_14 ( V_14 , V_15 , V_16 , & V_37 -> V_42 ) ;
return V_38 ;
}
static void F_17 ( struct V_1 * V_14 )
{
unsigned long V_8 ;
F_5 ( & V_14 -> V_7 . V_10 , V_8 ) ;
F_18 ( & V_14 -> V_7 , V_44 , V_45 ) ;
F_7 ( & V_14 -> V_7 . V_10 , V_8 ) ;
}
static T_3 F_19 ( struct V_32 * V_33 )
{
return V_46 |
V_47 ;
}
static int F_20 ( struct V_1 * V_14 )
{
struct V_32 * V_48 ;
int V_38 ;
V_48 = F_21 ( sizeof( * V_48 ) , V_49 ) ;
if ( V_48 == NULL )
return - V_50 ;
V_14 -> V_7 . V_32 = V_48 ;
F_17 ( V_14 ) ;
V_48 -> V_51 = V_52 ;
V_48 -> V_53 = & V_54 ;
strcpy ( V_48 -> V_55 , L_6 ) ;
V_48 -> V_3 . V_56 = & V_14 -> V_57 -> V_3 ;
F_22 ( V_48 , V_14 ) ;
V_38 = F_23 ( V_48 ) ;
if ( V_38 )
F_24 ( V_58 L_7 ) ;
return V_38 ;
}
static void F_25 ( struct V_1 * V_14 )
{
F_26 ( V_14 -> V_7 . V_32 ) ;
F_27 ( V_14 -> V_7 . V_32 ) ;
}
static void F_28 ( struct V_4 * V_7 )
{
unsigned long V_8 ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
F_9 ( V_7 , 0x3038 , 0x8 ) ;
F_9 ( V_7 , 0x315c , 0x80008 ) ;
F_9 ( V_7 , V_59 , V_60 | V_61 ) ;
F_9 ( V_7 , V_59 , V_62 | V_63 ) ;
F_9 ( V_7 , V_59 , V_62 | V_61 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
F_29 ( 5 ) ;
F_5 ( & V_7 -> V_10 , V_8 ) ;
F_9 ( V_7 , V_59 , V_64 | V_62 | V_63 ) ;
F_18 ( V_7 , V_65 , V_66 ) ;
F_9 ( V_7 , V_44 , 0 ) ;
F_7 ( & V_7 -> V_10 , V_8 ) ;
}
static void F_30 ( struct V_4 * V_7 )
{
F_9 ( V_7 , V_67 , V_68 ) ;
F_9 ( V_7 , V_69 , V_70 | V_71 ) ;
F_9 ( V_7 , V_72 , V_73 | V_74 ) ;
F_9 ( V_7 , V_72 , V_73 | V_74 | V_75 ) ;
}
static void F_31 ( struct V_4 * V_7 )
{
F_9 ( V_7 , V_72 , V_73 | V_74 | V_76 ) ;
F_9 ( V_7 , V_67 , V_68 ) ;
F_9 ( V_7 , V_69 , V_70 ) ;
}
static T_4 F_32 ( int V_77 , void * V_37 )
{
struct V_1 * V_14 = V_37 ;
struct V_4 * V_7 = & V_14 -> V_7 ;
unsigned int V_78 , V_79 ;
F_33 ( & V_7 -> V_10 ) ;
V_78 = F_6 ( V_7 , V_80 ) ;
V_79 = V_14 -> V_81 && F_34 ( V_7 , V_78 ) ;
if ( V_78 & V_45 ) {
F_9 ( V_7 , V_80 , V_45 ) ;
F_35 ( & V_14 -> V_27 ) ;
V_79 = 1 ;
}
F_36 ( & V_7 -> V_10 ) ;
return F_37 ( V_79 ) ;
}
static int F_38 ( struct V_82 * V_57 ,
const struct V_83 * V_84 )
{
int V_38 ;
struct V_1 * V_14 ;
struct V_4 * V_7 ;
V_38 = - V_50 ;
V_14 = F_21 ( sizeof( struct V_1 ) , V_49 ) ;
if ( V_14 == NULL )
goto V_85;
V_14 -> V_57 = V_57 ;
V_7 = & V_14 -> V_7 ;
V_7 -> V_86 = V_87 ;
F_39 ( & V_7 -> V_10 ) ;
F_40 ( & V_14 -> V_27 ) ;
V_7 -> V_88 = F_30 ;
V_7 -> V_89 = F_31 ;
V_7 -> V_3 = & V_57 -> V_3 ;
V_7 -> V_90 = 45 ;
V_7 -> V_91 = 1 ;
V_7 -> V_92 = V_93 ;
V_38 = F_41 ( V_57 ) ;
if ( V_38 )
goto V_94;
F_42 ( V_57 ) ;
V_38 = - V_29 ;
V_7 -> V_95 = F_43 ( V_57 , 0 , 0 ) ;
if ( ! V_7 -> V_95 ) {
F_24 ( V_58 L_8 ) ;
goto V_96;
}
V_7 -> V_97 = F_44 ( V_57 , 0 ) ;
V_38 = F_45 ( V_57 -> V_77 , F_32 , V_98 , L_9 , V_14 ) ;
if ( V_38 )
goto V_99;
F_28 ( V_7 ) ;
F_30 ( V_7 ) ;
V_38 = F_20 ( V_14 ) ;
if ( V_38 )
goto V_100;
V_38 = F_46 ( V_7 ) ;
if ( V_38 == 0 ) {
V_14 -> V_81 = 1 ;
return 0 ;
}
F_25 ( V_14 ) ;
V_100:
F_31 ( V_7 ) ;
F_47 ( V_57 -> V_77 , V_14 ) ;
V_99:
F_48 ( V_57 , V_7 -> V_95 ) ;
V_96:
F_49 ( V_57 ) ;
V_94:
F_27 ( V_14 ) ;
V_85:
return V_38 ;
}
static void F_50 ( struct V_1 * V_14 )
{
F_51 ( & V_14 -> V_7 ) ;
F_25 ( V_14 ) ;
F_47 ( V_14 -> V_57 -> V_77 , V_14 ) ;
F_48 ( V_14 -> V_57 , V_14 -> V_7 . V_95 ) ;
}
static void F_52 ( struct V_82 * V_57 )
{
struct V_2 * V_6 = F_53 ( & V_57 -> V_3 ) ;
struct V_1 * V_14 = F_1 ( V_6 ) ;
if ( V_14 == NULL ) {
F_24 ( V_101 L_10 , V_57 ) ;
return;
}
F_50 ( V_14 ) ;
F_27 ( V_14 ) ;
}
static int F_54 ( struct V_82 * V_57 , T_5 V_102 )
{
struct V_2 * V_6 = F_53 ( & V_57 -> V_3 ) ;
struct V_1 * V_14 = F_1 ( V_6 ) ;
int V_38 ;
V_38 = F_55 ( V_57 ) ;
if ( V_38 )
return V_38 ;
F_56 ( & V_14 -> V_7 ) ;
F_49 ( V_57 ) ;
return 0 ;
}
static int F_57 ( struct V_82 * V_57 )
{
struct V_2 * V_6 = F_53 ( & V_57 -> V_3 ) ;
struct V_1 * V_14 = F_1 ( V_6 ) ;
int V_38 = 0 ;
F_58 ( V_57 ) ;
V_38 = F_41 ( V_57 ) ;
if ( V_38 ) {
F_59 ( V_14 , L_11 ) ;
return V_38 ;
}
F_28 ( & V_14 -> V_7 ) ;
return F_60 ( & V_14 -> V_7 ) ;
}
static int T_6 F_61 ( void )
{
int V_38 ;
F_24 ( V_103 L_12 ,
V_104 ) ;
V_38 = F_62 ( & V_105 ) ;
if ( V_38 ) {
F_24 ( V_58 L_13 ) ;
goto V_85;
}
V_38 = 0 ;
V_85:
return V_38 ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_105 ) ;
}
