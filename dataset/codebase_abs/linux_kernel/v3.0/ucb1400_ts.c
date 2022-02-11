static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
V_4 | V_5 |
V_6 | V_7 |
V_8 ) ;
}
static inline unsigned int F_3 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_2 , V_3 ,
V_4 | V_5 |
V_6 | V_7 |
V_11 | V_12 ) ;
F_4 ( V_13 ) ;
return F_5 ( V_10 -> V_2 , V_14 , V_15 ) ;
}
static inline unsigned int F_6 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_2 , V_3 ,
V_16 | V_5 |
V_11 | V_12 ) ;
F_2 ( V_10 -> V_2 , V_3 ,
V_16 | V_5 |
V_11 | V_12 ) ;
F_2 ( V_10 -> V_2 , V_3 ,
V_16 | V_5 |
V_17 | V_12 ) ;
F_4 ( V_18 ) ;
return F_5 ( V_10 -> V_2 , V_14 , V_15 ) ;
}
static inline unsigned int F_7 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_2 , V_3 ,
V_6 | V_19 |
V_11 | V_12 ) ;
F_2 ( V_10 -> V_2 , V_3 ,
V_6 | V_19 |
V_11 | V_12 ) ;
F_2 ( V_10 -> V_2 , V_3 ,
V_6 | V_19 |
V_17 | V_12 ) ;
F_4 ( V_18 ) ;
return F_5 ( V_10 -> V_2 , V_20 , V_15 ) ;
}
static inline unsigned int F_8 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_2 , V_3 ,
V_16 | V_5 |
V_11 | V_12 ) ;
return F_5 ( V_10 -> V_2 , 0 , V_15 ) ;
}
static inline unsigned int F_9 ( struct V_9 * V_10 )
{
F_2 ( V_10 -> V_2 , V_3 ,
V_6 | V_19 |
V_11 | V_12 ) ;
return F_5 ( V_10 -> V_2 , 0 , V_15 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
unsigned short V_21 = F_11 ( V_2 , V_3 ) ;
return V_21 & ( V_22 | V_23 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_24 , V_25 ) ;
F_2 ( V_2 , V_24 , 0 ) ;
F_2 ( V_2 , V_26 , V_25 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_26 , 0 ) ;
}
static void F_14 ( struct V_27 * V_28 , T_1 V_29 , T_1 V_30 , T_1 V_31 )
{
F_15 ( V_28 , V_32 , V_30 ) ;
F_15 ( V_28 , V_33 , V_31 ) ;
F_15 ( V_28 , V_34 , V_29 ) ;
F_16 ( V_28 , V_35 , 1 ) ;
F_17 ( V_28 ) ;
}
static void F_18 ( struct V_27 * V_28 )
{
F_15 ( V_28 , V_34 , 0 ) ;
F_16 ( V_28 , V_35 , 0 ) ;
F_17 ( V_28 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
unsigned int V_36 ;
V_36 = F_11 ( V_10 -> V_2 , V_37 ) ;
F_2 ( V_10 -> V_2 , V_24 , V_36 ) ;
F_2 ( V_10 -> V_2 , V_24 , 0 ) ;
if ( V_36 & V_25 )
F_13 ( V_10 -> V_2 ) ;
else
F_20 ( & V_10 -> V_38 -> V_39 , L_1 , V_36 ) ;
F_21 ( V_10 -> V_40 ) ;
}
static int F_22 ( void * V_41 )
{
struct V_9 * V_10 = V_41 ;
struct V_42 * V_43 = V_44 ;
int V_45 = 0 ;
struct V_46 V_47 = { . V_48 = 1 } ;
F_23 ( V_43 , V_49 , & V_47 ) ;
F_24 () ;
while ( ! F_25 () ) {
unsigned int V_30 , V_31 , V_50 ;
long V_51 ;
V_10 -> V_52 = 0 ;
if ( V_10 -> V_53 ) {
V_10 -> V_53 = 0 ;
F_19 ( V_10 ) ;
}
F_26 ( V_10 -> V_2 ) ;
V_30 = F_6 ( V_10 ) ;
V_31 = F_7 ( V_10 ) ;
V_50 = F_3 ( V_10 ) ;
F_27 ( V_10 -> V_2 ) ;
F_1 ( V_10 -> V_2 ) ;
F_28 ( 10 ) ;
if ( F_10 ( V_10 -> V_2 ) ) {
F_12 ( V_10 -> V_2 ) ;
if ( V_45 ) {
F_18 ( V_10 -> V_38 ) ;
V_45 = 0 ;
}
V_51 = V_54 ;
} else {
V_45 = 1 ;
F_14 ( V_10 -> V_38 , V_50 , V_30 , V_31 ) ;
V_51 = F_29 ( 10 ) ;
}
F_30 ( V_10 -> V_55 ,
V_10 -> V_53 || V_10 -> V_52 ||
F_25 () , V_51 ) ;
}
if ( V_45 )
F_18 ( V_10 -> V_38 ) ;
V_10 -> V_56 = NULL ;
return 0 ;
}
static T_2 F_31 ( int V_57 , void * V_58 )
{
struct V_9 * V_10 = V_58 ;
if ( V_57 == V_10 -> V_40 ) {
F_32 ( V_10 -> V_40 ) ;
V_10 -> V_53 = 1 ;
F_33 ( & V_10 -> V_55 ) ;
return V_59 ;
}
return V_60 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_35 ( V_28 ) ;
int V_61 = 0 ;
F_36 ( V_10 -> V_56 ) ;
V_10 -> V_56 = F_37 ( F_22 , V_10 , L_2 ) ;
if ( F_38 ( V_10 -> V_56 ) ) {
V_61 = F_39 ( V_10 -> V_56 ) ;
V_10 -> V_56 = NULL ;
}
return V_61 ;
}
static void F_40 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_35 ( V_28 ) ;
if ( V_10 -> V_56 )
F_41 ( V_10 -> V_56 ) ;
F_13 ( V_10 -> V_2 ) ;
F_2 ( V_10 -> V_2 , V_3 , 0 ) ;
}
static int F_42 ( struct V_9 * V_10 )
{
unsigned long V_62 , V_51 ;
V_62 = F_43 () ;
F_2 ( V_10 -> V_2 , V_63 , V_64 ) ;
F_2 ( V_10 -> V_2 , V_26 , V_64 ) ;
F_2 ( V_10 -> V_2 , V_24 , 0xffff ) ;
F_2 ( V_10 -> V_2 , V_24 , 0 ) ;
F_2 ( V_10 -> V_2 , V_65 , V_66 ) ;
F_2 ( V_10 -> V_2 , V_65 , V_66 | V_67 ) ;
V_51 = V_68 + V_69 / 2 ;
while ( ! ( F_11 ( V_10 -> V_2 , V_70 ) &
V_71 ) ) {
F_44 () ;
if ( F_45 ( V_68 , V_51 ) ) {
F_46 ( V_72 L_3 ) ;
F_47 ( V_62 ) ;
return - V_73 ;
}
}
F_2 ( V_10 -> V_2 , V_65 , 0 ) ;
F_2 ( V_10 -> V_2 , V_63 , 0 ) ;
F_2 ( V_10 -> V_2 , V_26 , 0 ) ;
F_2 ( V_10 -> V_2 , V_24 , 0xffff ) ;
F_2 ( V_10 -> V_2 , V_24 , 0 ) ;
V_10 -> V_40 = F_47 ( V_62 ) ;
if ( V_10 -> V_40 < 0 || V_10 -> V_40 == V_74 )
return - V_73 ;
return 0 ;
}
static int F_48 ( struct V_75 * V_39 )
{
int error , V_76 , V_77 ;
T_1 V_78 ;
struct V_9 * V_10 = V_39 -> V_39 . V_79 ;
V_10 -> V_38 = F_49 () ;
if ( ! V_10 -> V_38 ) {
error = - V_80 ;
goto V_81;
}
if ( V_10 -> V_40 < 0 ) {
error = F_42 ( V_10 ) ;
if ( error ) {
F_46 ( V_72 L_4 ) ;
goto V_82;
}
}
F_50 ( & V_10 -> V_55 ) ;
error = F_51 ( V_10 -> V_40 , F_31 , V_83 ,
L_5 , V_10 ) ;
if ( error ) {
F_46 ( V_72 L_6 ,
V_10 -> V_40 , error ) ;
goto V_82;
}
F_46 ( V_84 L_7 , V_10 -> V_40 ) ;
F_52 ( V_10 -> V_38 , V_10 ) ;
V_10 -> V_38 -> V_39 . V_85 = & V_39 -> V_39 ;
V_10 -> V_38 -> V_86 = L_8 ;
V_10 -> V_38 -> V_87 . V_88 = F_11 ( V_10 -> V_2 ,
V_89 ) ;
V_10 -> V_38 -> V_87 . V_90 = V_10 -> V_87 ;
V_10 -> V_38 -> V_91 = F_34 ;
V_10 -> V_38 -> V_92 = F_40 ;
V_10 -> V_38 -> V_93 [ 0 ] = F_53 ( V_94 ) | F_53 ( V_95 ) ;
V_10 -> V_38 -> V_96 [ F_54 ( V_35 ) ] = F_53 ( V_35 ) ;
V_78 = F_11 ( V_10 -> V_2 , V_97 ) ;
F_2 ( V_10 -> V_2 , V_97 , V_78 | V_98 ) ;
F_26 ( V_10 -> V_2 ) ;
V_76 = F_8 ( V_10 ) ;
V_77 = F_9 ( V_10 ) ;
F_27 ( V_10 -> V_2 ) ;
F_46 ( V_84 L_9 , V_76 , V_77 ) ;
F_55 ( V_10 -> V_38 , V_32 , 0 , V_76 , 0 , 0 ) ;
F_55 ( V_10 -> V_38 , V_33 , 0 , V_77 , 0 , 0 ) ;
F_55 ( V_10 -> V_38 , V_34 , 0 , 0 , 0 , 0 ) ;
error = F_56 ( V_10 -> V_38 ) ;
if ( error )
goto V_99;
return 0 ;
V_99:
F_57 ( V_10 -> V_40 , V_10 ) ;
V_82:
F_58 ( V_10 -> V_38 ) ;
V_81:
return error ;
}
static int F_59 ( struct V_75 * V_39 )
{
struct V_9 * V_10 = V_39 -> V_39 . V_79 ;
F_57 ( V_10 -> V_40 , V_10 ) ;
F_60 ( V_10 -> V_38 ) ;
return 0 ;
}
static int F_61 ( struct V_75 * V_39 )
{
struct V_9 * V_10 = V_39 -> V_39 . V_79 ;
if ( V_10 -> V_56 ) {
V_10 -> V_52 = 1 ;
F_33 ( & V_10 -> V_55 ) ;
}
return 0 ;
}
static int T_3 F_62 ( void )
{
return F_63 ( & V_100 ) ;
}
static void T_4 F_64 ( void )
{
F_65 ( & V_100 ) ;
}
