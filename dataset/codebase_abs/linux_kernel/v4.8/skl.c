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
struct V_1 * V_2 = F_11 ( V_17 -> V_10 ) ;
int V_19 ;
F_32 ( V_9 ) ;
V_19 = F_33 ( V_7 ) ;
if ( V_19 < 0 )
return V_19 ;
F_34 ( V_17 ) ;
F_7 ( V_2 , V_37 ,
V_38 , V_38 ) ;
F_10 ( V_17 -> V_10 , false ) ;
F_35 ( V_17 ) ;
F_10 ( V_17 -> V_10 , true ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_4 ( V_7 ) ;
F_12 ( V_17 , true ) ;
return F_38 ( V_7 ) ;
}
static int F_39 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 = 0 ;
if ( V_7 -> V_39 ) {
F_32 ( V_9 ) ;
if ( V_9 -> V_40 )
F_41 ( & V_9 -> V_17 ) ;
F_42 ( V_17 -> V_23 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
} else {
V_19 = F_31 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
V_7 -> V_41 -> V_42 = false ;
}
if ( F_45 ( V_43 ) ) {
V_19 = F_46 ( V_17 , false ) ;
if ( V_19 < 0 )
F_29 ( V_17 -> V_10 ,
L_3 ) ;
}
return V_19 ;
}
static int F_47 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_44 * V_45 = NULL ;
int V_19 ;
if ( F_45 ( V_43 ) ) {
V_19 = F_46 ( V_17 , true ) ;
if ( V_19 < 0 ) {
F_29 ( V_17 -> V_10 ,
L_4 ) ;
return V_19 ;
}
}
if ( V_7 -> V_39 ) {
F_48 ( V_2 ) ;
V_19 = F_49 ( V_2 ) ;
F_50 ( V_9 ) ;
F_51 ( V_17 -> V_23 ) ;
F_52 (hlink, &ebus->hlink_list, list) {
if ( V_45 -> V_46 )
F_53 ( V_45 ) ;
}
if ( V_9 -> V_40 )
F_54 ( & V_9 -> V_17 ) ;
} else {
V_19 = F_37 ( V_9 ) ;
F_52 (hlink, &ebus->hlink_list, list) {
if ( ! V_45 -> V_46 )
F_55 ( V_45 ) ;
}
if ( ! V_9 -> V_40 )
F_41 ( & V_9 -> V_17 ) ;
}
return V_19 ;
}
static int F_56 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_47 ) ;
return F_31 ( V_9 ) ;
}
static int F_57 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_47 ) ;
return F_37 ( V_9 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
V_7 -> V_48 = 1 ;
F_59 ( V_9 ) ;
if ( V_17 -> V_23 >= 0 )
F_60 ( V_17 -> V_23 , ( void * ) V_17 ) ;
F_61 ( V_17 ) ;
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
if ( V_17 -> V_49 )
F_64 ( V_17 -> V_49 ) ;
F_65 ( V_7 -> V_2 ) ;
F_44 ( V_7 -> V_2 ) ;
F_66 ( V_9 ) ;
if ( F_45 ( V_43 ) )
F_67 ( & V_9 -> V_17 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_7 , void * V_50 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 = V_50 ;
int V_19 ;
V_54 = F_69 ( V_54 ) ;
if ( V_54 == NULL ) {
F_29 ( V_17 -> V_10 , L_6 ) ;
return - V_55 ;
}
V_7 -> V_56 = V_54 -> V_57 ;
V_52 = F_70 ( V_54 -> V_58 , - 1 ) ;
if ( V_52 == NULL ) {
F_29 ( V_17 -> V_10 , L_7 ) ;
return - V_59 ;
}
V_19 = F_71 ( V_52 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_8 ) ;
F_72 ( V_52 ) ;
return - V_59 ;
}
if ( V_54 -> V_60 )
F_73 ( & V_52 -> V_10 , V_54 -> V_60 ) ;
V_7 -> V_61 = V_52 ;
return 0 ;
}
static void F_74 ( struct V_7 * V_7 )
{
if ( V_7 -> V_61 )
F_75 ( V_7 -> V_61 ) ;
}
static int F_76 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_51 * V_52 ;
int V_19 ;
V_52 = F_70 ( L_9 , - 1 ) ;
if ( ! V_52 ) {
F_29 ( V_17 -> V_10 , L_10 ) ;
return - V_62 ;
}
V_19 = F_71 ( V_52 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_11 , V_19 ) ;
F_72 ( V_52 ) ;
return V_19 ;
}
V_7 -> V_63 = V_52 ;
return 0 ;
}
static void F_77 ( struct V_7 * V_7 )
{
if ( V_7 -> V_63 )
F_75 ( V_7 -> V_63 ) ;
}
static int F_78 ( struct V_8 * V_9 , int V_64 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_65 = ( V_64 << 28 ) | ( V_66 << 20 ) |
( V_67 << 8 ) | V_68 ;
unsigned int V_69 ;
F_79 ( & V_17 -> V_70 ) ;
F_80 ( V_17 , V_65 ) ;
F_81 ( V_17 , V_64 , & V_69 ) ;
F_82 ( & V_17 -> V_70 ) ;
if ( V_69 == - 1 )
return - V_59 ;
F_5 ( V_17 -> V_10 , L_12 , V_64 ) ;
return F_83 ( V_9 , V_64 ) ;
}
static int F_84 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_71 , V_72 ;
V_72 = V_73 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
if ( ( V_17 -> V_74 & ( 1 << V_71 ) ) ) {
if ( F_78 ( V_9 , V_71 ) < 0 ) {
F_85 ( V_17 -> V_10 ,
L_13 , V_71 ) ;
V_17 -> V_74 &= ~ ( 1 << V_71 ) ;
F_34 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_75 * V_76 ,
struct V_7 * * V_77 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_78 ;
* V_77 = NULL ;
V_78 = F_49 ( V_2 ) ;
if ( V_78 < 0 )
return V_78 ;
V_7 = F_87 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 ) {
F_44 ( V_2 ) ;
return - V_62 ;
}
V_9 = & V_7 -> V_9 ;
F_88 ( V_9 , & V_2 -> V_10 , & V_80 , V_76 ) ;
V_9 -> V_17 . V_81 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_17 . V_82 = 0 ;
* V_77 = V_7 ;
return 0 ;
}
static int F_89 ( struct V_16 * V_17 )
{
int V_78 ;
V_78 = F_90 ( V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_46 ( V_17 , true ) ;
if ( V_78 < 0 ) {
F_29 ( V_17 -> V_10 , L_4 ) ;
return V_78 ;
}
return V_78 ;
}
static int F_91 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_78 ;
unsigned short V_83 ;
int V_84 , V_85 , V_86 ;
V_78 = F_92 ( V_2 , L_14 ) ;
if ( V_78 < 0 )
return V_78 ;
V_17 -> V_64 = F_93 ( V_2 , 0 ) ;
V_17 -> V_49 = F_94 ( V_2 , 0 ) ;
if ( V_17 -> V_49 == NULL ) {
F_29 ( V_17 -> V_10 , L_15 ) ;
return - V_87 ;
}
F_95 ( V_9 ) ;
if ( F_26 ( V_9 , 0 ) < 0 )
return - V_88 ;
F_96 ( V_2 ) ;
F_97 ( V_17 -> V_23 ) ;
V_83 = F_98 ( V_17 , V_89 ) ;
F_5 ( V_17 -> V_10 , L_16 , V_83 ) ;
if ( ! F_99 ( V_17 -> V_10 , F_100 ( 64 ) ) ) {
F_101 ( V_17 -> V_10 , F_100 ( 64 ) ) ;
} else {
F_99 ( V_17 -> V_10 , F_100 ( 32 ) ) ;
F_101 ( V_17 -> V_10 , F_100 ( 32 ) ) ;
}
V_84 = ( V_83 >> 8 ) & 0x0f ;
V_85 = ( V_83 >> 12 ) & 0x0f ;
if ( ! V_85 && ! V_84 )
return - V_59 ;
V_9 -> V_90 = V_84 + V_85 ;
F_102
( V_9 , 0 , V_84 , V_91 ) ;
V_86 = V_84 ;
F_102
( V_9 , V_86 , V_85 , V_92 ) ;
V_78 = F_103 ( V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
F_4 ( V_7 ) ;
if ( F_45 ( V_43 ) ) {
V_78 = F_89 ( V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
}
F_12 ( V_17 , true ) ;
if ( ! V_17 -> V_74 ) {
F_104 ( V_17 -> V_10 , L_17 ) ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 ,
const struct V_93 * V_94 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_44 * V_45 = NULL ;
int V_78 ;
V_78 = F_86 ( V_2 , NULL , & V_7 ) ;
if ( V_78 < 0 )
return V_78 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_78 = F_91 ( V_9 ) ;
if ( V_78 < 0 )
goto V_95;
V_7 -> V_94 = V_2 -> V_12 ;
F_106 ( V_17 -> V_10 ) ;
V_7 -> V_96 = F_107 ( V_17 -> V_10 ) ;
if ( V_7 -> V_96 == NULL ) {
V_78 = - V_55 ;
goto V_95;
}
F_108 ( V_7 ) ;
F_109 ( V_7 -> V_2 , V_9 ) ;
V_97 . V_98 = F_110 ( V_7 ) ;
if ( V_9 -> V_99 ) {
V_78 = F_68 ( V_7 ,
( void * ) V_94 -> V_50 ) ;
if ( V_78 < 0 )
goto V_100;
V_78 = F_111 ( V_7 ) ;
if ( V_78 < 0 ) {
F_5 ( V_17 -> V_10 , L_18 ) ;
goto V_101;
}
V_7 -> V_41 -> V_102 = F_10 ;
}
if ( V_9 -> V_103 )
F_112 ( V_9 ) ;
V_78 = F_76 ( V_7 ) ;
if ( V_78 < 0 )
goto V_104;
V_78 = F_113 ( V_17 -> V_10 ) ;
if ( V_78 < 0 )
goto V_105;
V_78 = F_84 ( V_9 ) ;
if ( V_78 < 0 )
goto V_106;
if ( F_45 ( V_43 ) ) {
V_78 = F_46 ( V_17 , false ) ;
if ( V_78 < 0 ) {
F_29 ( V_17 -> V_10 , L_19 ) ;
return V_78 ;
}
}
F_52 (hlink, &ebus->hlink_list, list)
F_114 ( V_9 , V_45 ) ;
F_115 ( V_17 -> V_10 ) ;
F_116 ( V_17 -> V_10 ) ;
return 0 ;
V_106:
F_117 ( V_17 -> V_10 ) ;
V_105:
F_77 ( V_7 ) ;
V_104:
F_118 ( V_7 ) ;
V_101:
F_74 ( V_7 ) ;
V_100:
F_119 ( V_7 -> V_96 ) ;
V_95:
V_7 -> V_48 = 1 ;
F_58 ( V_9 ) ;
return V_78 ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_20 * V_107 ;
struct V_108 * V_109 ;
struct V_7 * V_7 ;
if ( V_9 == NULL )
return;
V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_48 )
return;
F_59 ( V_9 ) ;
F_52 (s, &bus->stream_list, list) {
V_109 = F_121 ( V_107 ) ;
F_122 ( V_9 , V_109 , false ) ;
}
F_34 ( V_17 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_40 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
F_124 ( V_7 -> V_110 ) ;
if ( F_125 ( V_2 ) )
F_126 ( & V_2 -> V_10 ) ;
F_127 ( V_9 ) ;
F_117 ( & V_2 -> V_10 ) ;
F_118 ( V_7 ) ;
F_74 ( V_7 ) ;
F_77 ( V_7 ) ;
F_119 ( V_7 -> V_96 ) ;
F_58 ( V_9 ) ;
F_73 ( & V_2 -> V_10 , NULL ) ;
}
