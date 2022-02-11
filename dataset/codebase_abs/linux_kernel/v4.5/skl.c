static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 , unsigned char V_5 )
{
unsigned char V_6 ;
F_2 ( V_2 , V_3 , & V_6 ) ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
static void F_4 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
F_5 ( F_6 ( V_9 ) -> V_10 , L_1 ) ;
F_1 ( V_7 -> V_2 , V_11 , 0x07 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = 0 ;
F_8 ( V_2 , V_3 , & V_6 ) ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
F_9 ( V_2 , V_3 , V_6 ) ;
}
static void F_10 ( struct V_12 * V_10 , bool V_13 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_1 V_5 ;
V_5 = V_13 ? V_14 : 0 ;
F_7 ( V_2 , V_15 , V_14 , V_5 ) ;
}
static int F_12 ( struct V_16 * V_17 , bool V_18 )
{
int V_19 ;
F_10 ( V_17 -> V_10 , false ) ;
V_19 = F_13 ( V_17 , V_18 ) ;
F_10 ( V_17 -> V_10 , true ) ;
return V_19 ;
}
static void F_14 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
F_15 ( V_21 -> V_22 ) ;
}
static T_2 F_16 ( int V_23 , void * V_24 )
{
struct V_8 * V_9 = V_24 ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
T_1 V_25 ;
if ( ! F_17 ( V_17 -> V_10 ) )
return V_26 ;
F_18 ( & V_17 -> V_27 ) ;
V_25 = F_19 ( V_17 , V_28 ) ;
if ( V_25 == 0 || V_25 == 0xffffffff ) {
F_20 ( & V_17 -> V_27 ) ;
return V_26 ;
}
V_25 = F_21 ( V_17 , V_29 ) ;
if ( V_25 & V_30 ) {
if ( V_25 & V_31 )
F_22 ( V_17 ) ;
F_23 ( V_17 , V_29 , V_30 ) ;
}
F_20 ( & V_17 -> V_27 ) ;
return F_19 ( V_17 , V_28 ) ? V_32 : V_33 ;
}
static T_2 F_24 ( int V_23 , void * V_24 )
{
struct V_8 * V_9 = V_24 ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
T_1 V_25 ;
V_25 = F_19 ( V_17 , V_28 ) ;
F_25 ( V_17 , V_25 , F_14 ) ;
return V_33 ;
}
static int F_26 ( struct V_8 * V_9 , int V_34 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 ;
V_19 = F_28 ( V_7 -> V_2 -> V_23 , F_16 ,
F_24 ,
V_35 ,
V_36 , V_9 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 ,
L_2 ,
V_7 -> V_2 -> V_23 ) ;
return V_19 ;
}
V_17 -> V_23 = V_7 -> V_2 -> V_23 ;
F_30 ( V_7 -> V_2 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 ;
F_32 ( V_9 ) ;
V_19 = F_33 ( V_7 ) ;
if ( V_19 < 0 )
return V_19 ;
F_34 ( V_17 ) ;
F_10 ( V_17 -> V_10 , false ) ;
F_35 ( V_17 ) ;
F_10 ( V_17 -> V_10 , true ) ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_4 ( V_7 ) ;
F_12 ( V_17 , true ) ;
return F_37 ( V_7 ) ;
}
static int F_38 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
if ( V_7 -> V_37 ) {
F_32 ( V_9 ) ;
F_40 ( V_17 -> V_23 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
return 0 ;
} else {
return F_31 ( V_9 ) ;
}
}
static int F_43 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 ;
if ( V_7 -> V_37 ) {
F_44 ( V_2 ) ;
V_19 = F_45 ( V_2 ) ;
F_46 ( V_9 ) ;
F_47 ( V_17 -> V_23 ) ;
} else {
V_19 = F_36 ( V_9 ) ;
}
return V_19 ;
}
static int F_48 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_3 , V_38 ) ;
return F_31 ( V_9 ) ;
}
static int F_49 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_3 , V_38 ) ;
return F_36 ( V_9 ) ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
V_7 -> V_39 = 1 ;
F_51 ( V_9 ) ;
if ( V_17 -> V_23 >= 0 )
F_52 ( V_17 -> V_23 , ( void * ) V_17 ) ;
if ( V_17 -> V_40 )
F_53 ( V_17 -> V_40 ) ;
F_54 ( V_17 ) ;
F_55 ( V_9 ) ;
F_56 ( V_9 ) ;
F_57 ( V_7 -> V_2 ) ;
F_42 ( V_7 -> V_2 ) ;
F_58 ( V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_7 , void * V_41 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_42 * V_43 ;
struct V_44 * V_45 = V_41 ;
int V_19 ;
V_45 = F_60 ( V_45 ) ;
if ( V_45 == NULL ) {
F_29 ( V_17 -> V_10 , L_4 ) ;
return - V_46 ;
}
V_7 -> V_47 = V_45 -> V_48 ;
V_43 = F_61 ( V_45 -> V_49 , - 1 ) ;
if ( V_43 == NULL ) {
F_29 ( V_17 -> V_10 , L_5 ) ;
return - V_50 ;
}
V_19 = F_62 ( V_43 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_6 ) ;
F_63 ( V_43 ) ;
return - V_50 ;
}
V_7 -> V_51 = V_43 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_7 )
{
if ( V_7 -> V_51 )
F_65 ( V_7 -> V_51 ) ;
}
static int F_66 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_42 * V_43 ;
int V_19 ;
V_43 = F_61 ( L_7 , - 1 ) ;
if ( ! V_43 ) {
F_29 ( V_17 -> V_10 , L_8 ) ;
return - V_52 ;
}
V_19 = F_62 ( V_43 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_9 , V_19 ) ;
F_63 ( V_43 ) ;
return V_19 ;
}
V_7 -> V_53 = V_43 ;
return 0 ;
}
static void F_67 ( struct V_7 * V_7 )
{
if ( V_7 -> V_53 )
F_65 ( V_7 -> V_53 ) ;
}
static int F_68 ( struct V_8 * V_9 , int V_54 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_55 = ( V_54 << 28 ) | ( V_56 << 20 ) |
( V_57 << 8 ) | V_58 ;
unsigned int V_59 ;
F_69 ( & V_17 -> V_60 ) ;
F_70 ( V_17 , V_55 ) ;
F_71 ( V_17 , V_54 , & V_59 ) ;
F_72 ( & V_17 -> V_60 ) ;
if ( V_59 == - 1 )
return - V_50 ;
F_5 ( V_17 -> V_10 , L_10 , V_54 ) ;
return F_73 ( V_9 , V_54 ) ;
}
static int F_74 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_61 , V_62 ;
V_62 = V_63 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
if ( ( V_17 -> V_64 & ( 1 << V_61 ) ) ) {
if ( F_68 ( V_9 , V_61 ) < 0 ) {
F_75 ( V_17 -> V_10 ,
L_11 , V_61 ) ;
V_17 -> V_64 &= ~ ( 1 << V_61 ) ;
F_34 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_65 * V_66 ,
struct V_7 * * V_67 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_68 ;
* V_67 = NULL ;
V_68 = F_45 ( V_2 ) ;
if ( V_68 < 0 )
return V_68 ;
V_7 = F_77 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_69 ) ;
if ( ! V_7 ) {
F_42 ( V_2 ) ;
return - V_52 ;
}
V_9 = & V_7 -> V_9 ;
F_78 ( V_9 , & V_2 -> V_10 , & V_70 , V_66 ) ;
V_9 -> V_17 . V_71 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_17 . V_72 = 0 ;
* V_67 = V_7 ;
return 0 ;
}
static int F_79 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_68 ;
unsigned short V_73 ;
int V_74 , V_75 , V_76 ;
V_68 = F_80 ( V_2 , L_12 ) ;
if ( V_68 < 0 )
return V_68 ;
V_17 -> V_54 = F_81 ( V_2 , 0 ) ;
V_17 -> V_40 = F_82 ( V_2 , 0 ) ;
if ( V_17 -> V_40 == NULL ) {
F_29 ( V_17 -> V_10 , L_13 ) ;
return - V_77 ;
}
F_83 ( V_9 ) ;
if ( F_26 ( V_9 , 0 ) < 0 )
return - V_78 ;
F_84 ( V_2 ) ;
F_85 ( V_17 -> V_23 ) ;
V_73 = F_86 ( V_17 , V_79 ) ;
F_5 ( V_17 -> V_10 , L_14 , V_73 ) ;
if ( ! F_87 ( V_17 -> V_10 , F_88 ( 64 ) ) ) {
F_89 ( V_17 -> V_10 , F_88 ( 64 ) ) ;
} else {
F_87 ( V_17 -> V_10 , F_88 ( 32 ) ) ;
F_89 ( V_17 -> V_10 , F_88 ( 32 ) ) ;
}
V_74 = ( V_73 >> 8 ) & 0x0f ;
V_75 = ( V_73 >> 12 ) & 0x0f ;
if ( ! V_75 && ! V_74 )
return - V_50 ;
V_9 -> V_80 = V_74 + V_75 ;
F_90
( V_9 , 0 , V_74 , V_81 ) ;
V_76 = V_74 ;
F_90
( V_9 , V_76 , V_75 , V_82 ) ;
V_68 = F_91 ( V_17 ) ;
if ( V_68 < 0 )
return V_68 ;
F_4 ( V_7 ) ;
F_12 ( V_17 , true ) ;
if ( ! V_17 -> V_64 ) {
F_92 ( V_17 -> V_10 , L_15 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
const struct V_83 * V_84 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
int V_68 ;
V_68 = F_76 ( V_2 , NULL , & V_7 ) ;
if ( V_68 < 0 )
return V_68 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_68 = F_79 ( V_9 ) ;
if ( V_68 < 0 )
goto V_85;
V_7 -> V_86 = F_94 ( V_17 -> V_10 ) ;
if ( V_7 -> V_86 == NULL )
goto V_85;
F_95 ( V_7 -> V_2 , V_9 ) ;
if ( V_9 -> V_87 ) {
V_68 = F_59 ( V_7 ,
( void * ) V_84 -> V_41 ) ;
if ( V_68 < 0 )
goto V_85;
V_68 = F_96 ( V_7 ) ;
if ( V_68 < 0 ) {
F_5 ( V_17 -> V_10 , L_16 ) ;
goto V_88;
}
V_7 -> V_89 -> V_90 = F_10 ;
}
if ( V_9 -> V_91 )
F_97 ( V_9 ) ;
V_68 = F_66 ( V_7 ) ;
if ( V_68 < 0 )
goto V_92;
V_68 = F_98 ( V_17 -> V_10 ) ;
if ( V_68 < 0 )
goto V_93;
V_68 = F_74 ( V_9 ) ;
if ( V_68 < 0 )
goto V_94;
F_99 ( V_17 -> V_10 ) ;
F_100 ( V_17 -> V_10 ) ;
return 0 ;
V_94:
F_101 ( V_17 -> V_10 ) ;
V_93:
F_67 ( V_7 ) ;
V_92:
F_102 ( V_7 ) ;
V_88:
F_64 ( V_7 ) ;
V_85:
V_7 -> V_39 = 1 ;
F_50 ( V_9 ) ;
return V_68 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_95 )
F_104 ( V_7 -> V_95 ) ;
if ( F_105 ( V_2 ) )
F_106 ( & V_2 -> V_10 ) ;
F_107 ( V_2 ) ;
F_101 ( & V_2 -> V_10 ) ;
F_102 ( V_7 ) ;
F_64 ( V_7 ) ;
F_67 ( V_7 ) ;
F_50 ( V_9 ) ;
F_108 ( & V_2 -> V_10 , NULL ) ;
}
