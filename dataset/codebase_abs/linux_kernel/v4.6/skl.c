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
int V_19 = 0 ;
if ( V_7 -> V_37 ) {
F_32 ( V_9 ) ;
F_40 ( V_17 -> V_23 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
} else {
V_19 = F_31 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_43 ( V_38 ) ) {
V_19 = F_44 ( V_17 , false ) ;
if ( V_19 < 0 )
F_29 ( V_17 -> V_10 ,
L_3 ) ;
}
return V_19 ;
}
static int F_45 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 ;
if ( F_43 ( V_38 ) ) {
V_19 = F_44 ( V_17 , true ) ;
if ( V_19 < 0 ) {
F_29 ( V_17 -> V_10 ,
L_4 ) ;
return V_19 ;
}
}
if ( V_7 -> V_37 ) {
F_46 ( V_2 ) ;
V_19 = F_47 ( V_2 ) ;
F_48 ( V_9 ) ;
F_49 ( V_17 -> V_23 ) ;
} else {
V_19 = F_36 ( V_9 ) ;
}
return V_19 ;
}
static int F_50 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_39 ) ;
return F_31 ( V_9 ) ;
}
static int F_51 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_39 ) ;
return F_36 ( V_9 ) ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
V_7 -> V_40 = 1 ;
F_53 ( V_9 ) ;
if ( V_17 -> V_23 >= 0 )
F_54 ( V_17 -> V_23 , ( void * ) V_17 ) ;
F_55 ( V_17 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
if ( V_17 -> V_41 )
F_58 ( V_17 -> V_41 ) ;
F_59 ( V_7 -> V_2 ) ;
F_42 ( V_7 -> V_2 ) ;
F_60 ( V_9 ) ;
if ( F_43 ( V_38 ) )
F_61 ( & V_9 -> V_17 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_7 , void * V_42 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_43 * V_44 ;
struct V_45 * V_46 = V_42 ;
int V_19 ;
V_46 = F_63 ( V_46 ) ;
if ( V_46 == NULL ) {
F_29 ( V_17 -> V_10 , L_6 ) ;
return - V_47 ;
}
V_7 -> V_48 = V_46 -> V_49 ;
V_44 = F_64 ( V_46 -> V_50 , - 1 ) ;
if ( V_44 == NULL ) {
F_29 ( V_17 -> V_10 , L_7 ) ;
return - V_51 ;
}
V_19 = F_65 ( V_44 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_8 ) ;
F_66 ( V_44 ) ;
return - V_51 ;
}
V_7 -> V_52 = V_44 ;
return 0 ;
}
static void F_67 ( struct V_7 * V_7 )
{
if ( V_7 -> V_52 )
F_68 ( V_7 -> V_52 ) ;
}
static int F_69 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_43 * V_44 ;
int V_19 ;
V_44 = F_64 ( L_9 , - 1 ) ;
if ( ! V_44 ) {
F_29 ( V_17 -> V_10 , L_10 ) ;
return - V_53 ;
}
V_19 = F_65 ( V_44 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_11 , V_19 ) ;
F_66 ( V_44 ) ;
return V_19 ;
}
V_7 -> V_54 = V_44 ;
return 0 ;
}
static void F_70 ( struct V_7 * V_7 )
{
if ( V_7 -> V_54 )
F_68 ( V_7 -> V_54 ) ;
}
static int F_71 ( struct V_8 * V_9 , int V_55 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_56 = ( V_55 << 28 ) | ( V_57 << 20 ) |
( V_58 << 8 ) | V_59 ;
unsigned int V_60 ;
F_72 ( & V_17 -> V_61 ) ;
F_73 ( V_17 , V_56 ) ;
F_74 ( V_17 , V_55 , & V_60 ) ;
F_75 ( & V_17 -> V_61 ) ;
if ( V_60 == - 1 )
return - V_51 ;
F_5 ( V_17 -> V_10 , L_12 , V_55 ) ;
return F_76 ( V_9 , V_55 ) ;
}
static int F_77 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_62 , V_63 ;
V_63 = V_64 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
if ( ( V_17 -> V_65 & ( 1 << V_62 ) ) ) {
if ( F_71 ( V_9 , V_62 ) < 0 ) {
F_78 ( V_17 -> V_10 ,
L_13 , V_62 ) ;
V_17 -> V_65 &= ~ ( 1 << V_62 ) ;
F_34 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
const struct V_66 * V_67 ,
struct V_7 * * V_68 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_69 ;
* V_68 = NULL ;
V_69 = F_47 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
V_7 = F_80 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_70 ) ;
if ( ! V_7 ) {
F_42 ( V_2 ) ;
return - V_53 ;
}
V_9 = & V_7 -> V_9 ;
F_81 ( V_9 , & V_2 -> V_10 , & V_71 , V_67 ) ;
V_9 -> V_17 . V_72 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_17 . V_73 = 0 ;
* V_68 = V_7 ;
return 0 ;
}
static int F_82 ( struct V_16 * V_17 )
{
int V_69 ;
V_69 = F_83 ( V_17 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_44 ( V_17 , true ) ;
if ( V_69 < 0 ) {
F_29 ( V_17 -> V_10 , L_4 ) ;
return V_69 ;
}
return V_69 ;
}
static int F_84 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_69 ;
unsigned short V_74 ;
int V_75 , V_76 , V_77 ;
V_69 = F_85 ( V_2 , L_14 ) ;
if ( V_69 < 0 )
return V_69 ;
V_17 -> V_55 = F_86 ( V_2 , 0 ) ;
V_17 -> V_41 = F_87 ( V_2 , 0 ) ;
if ( V_17 -> V_41 == NULL ) {
F_29 ( V_17 -> V_10 , L_15 ) ;
return - V_78 ;
}
F_88 ( V_9 ) ;
if ( F_26 ( V_9 , 0 ) < 0 )
return - V_79 ;
F_89 ( V_2 ) ;
F_90 ( V_17 -> V_23 ) ;
V_74 = F_91 ( V_17 , V_80 ) ;
F_5 ( V_17 -> V_10 , L_16 , V_74 ) ;
if ( ! F_92 ( V_17 -> V_10 , F_93 ( 64 ) ) ) {
F_94 ( V_17 -> V_10 , F_93 ( 64 ) ) ;
} else {
F_92 ( V_17 -> V_10 , F_93 ( 32 ) ) ;
F_94 ( V_17 -> V_10 , F_93 ( 32 ) ) ;
}
V_75 = ( V_74 >> 8 ) & 0x0f ;
V_76 = ( V_74 >> 12 ) & 0x0f ;
if ( ! V_76 && ! V_75 )
return - V_51 ;
V_9 -> V_81 = V_75 + V_76 ;
F_95
( V_9 , 0 , V_75 , V_82 ) ;
V_77 = V_75 ;
F_95
( V_9 , V_77 , V_76 , V_83 ) ;
V_69 = F_96 ( V_17 ) ;
if ( V_69 < 0 )
return V_69 ;
F_4 ( V_7 ) ;
if ( F_43 ( V_38 ) ) {
V_69 = F_82 ( V_17 ) ;
if ( V_69 < 0 )
return V_69 ;
}
F_12 ( V_17 , true ) ;
if ( ! V_17 -> V_65 ) {
F_97 ( V_17 -> V_10 , L_17 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
const struct V_84 * V_85 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
int V_69 ;
V_69 = F_79 ( V_2 , NULL , & V_7 ) ;
if ( V_69 < 0 )
return V_69 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_69 = F_84 ( V_9 ) ;
if ( V_69 < 0 )
goto V_86;
V_7 -> V_85 = V_2 -> V_12 ;
V_7 -> V_87 = F_99 ( V_17 -> V_10 ) ;
if ( V_7 -> V_87 == NULL )
goto V_86;
F_100 ( V_7 ) ;
F_101 ( V_7 -> V_2 , V_9 ) ;
if ( V_9 -> V_88 ) {
V_69 = F_62 ( V_7 ,
( void * ) V_85 -> V_42 ) ;
if ( V_69 < 0 )
goto V_86;
V_69 = F_102 ( V_7 ) ;
if ( V_69 < 0 ) {
F_5 ( V_17 -> V_10 , L_18 ) ;
goto V_89;
}
V_7 -> V_90 -> V_91 = F_10 ;
}
if ( V_9 -> V_92 )
F_103 ( V_9 ) ;
V_69 = F_69 ( V_7 ) ;
if ( V_69 < 0 )
goto V_93;
V_69 = F_104 ( V_17 -> V_10 ) ;
if ( V_69 < 0 )
goto V_94;
V_69 = F_77 ( V_9 ) ;
if ( V_69 < 0 )
goto V_95;
if ( F_43 ( V_38 ) ) {
V_69 = F_44 ( V_17 , false ) ;
if ( V_69 < 0 ) {
F_29 ( V_17 -> V_10 , L_19 ) ;
return V_69 ;
}
}
F_105 ( V_17 -> V_10 ) ;
F_106 ( V_17 -> V_10 ) ;
return 0 ;
V_95:
F_107 ( V_17 -> V_10 ) ;
V_94:
F_70 ( V_7 ) ;
V_93:
F_108 ( V_7 ) ;
V_89:
F_67 ( V_7 ) ;
V_86:
V_7 -> V_40 = 1 ;
F_52 ( V_9 ) ;
return V_69 ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_20 * V_96 ;
struct V_97 * V_98 ;
struct V_7 * V_7 ;
if ( V_9 == NULL )
return;
V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_40 )
return;
F_53 ( V_9 ) ;
F_110 (s, &bus->stream_list, list) {
V_98 = F_111 ( V_96 ) ;
F_112 ( V_9 , V_98 , false ) ;
}
F_34 ( V_17 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_99 )
F_114 ( V_7 -> V_99 ) ;
if ( F_115 ( V_2 ) )
F_116 ( & V_2 -> V_10 ) ;
F_117 ( V_9 ) ;
F_107 ( & V_2 -> V_10 ) ;
F_108 ( V_7 ) ;
F_67 ( V_7 ) ;
F_70 ( V_7 ) ;
F_52 ( V_9 ) ;
F_118 ( & V_2 -> V_10 , NULL ) ;
}
