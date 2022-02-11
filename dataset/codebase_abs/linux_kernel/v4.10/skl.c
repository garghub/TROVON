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
void F_14 ( struct V_12 * V_10 , bool V_13 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
T_2 V_3 ;
int V_20 = 50 ;
V_3 = F_16 ( V_17 , V_21 ) ;
while ( ( V_3 & V_22 ) && -- V_20 ) {
F_17 ( 10 ) ;
V_3 = F_16 ( V_17 , V_21 ) ;
}
if ( ! V_20 ) {
F_18 ( V_17 -> V_10 , L_2 ) ;
return;
}
if ( V_13 )
V_3 = V_3 | V_23 ;
else
V_3 = V_3 & ( ~ V_23 ) ;
F_19 ( V_17 , V_21 , V_3 ) ;
V_20 = 50 ;
V_3 = F_16 ( V_17 , V_21 ) ;
while ( ( V_3 & V_22 ) && -- V_20 ) {
F_17 ( 10 ) ;
V_3 = F_16 ( V_17 , V_21 ) ;
}
if ( ! V_20 ) {
F_18 ( V_17 -> V_10 , L_3 ) ;
return;
}
F_5 ( V_17 -> V_10 , L_4 ,
F_16 ( V_17 , V_21 ) ) ;
}
static void F_20 ( struct V_16 * V_17 , struct V_24 * V_25 )
{
F_21 ( V_25 -> V_26 ) ;
}
static T_3 F_22 ( int V_27 , void * V_28 )
{
struct V_8 * V_9 = V_28 ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
T_1 V_29 ;
if ( ! F_23 ( V_17 -> V_10 ) )
return V_30 ;
F_24 ( & V_17 -> V_31 ) ;
V_29 = F_25 ( V_17 , V_32 ) ;
if ( V_29 == 0 || V_29 == 0xffffffff ) {
F_26 ( & V_17 -> V_31 ) ;
return V_30 ;
}
V_29 = F_16 ( V_17 , V_33 ) ;
if ( V_29 & V_34 ) {
if ( V_29 & V_35 )
F_27 ( V_17 ) ;
F_19 ( V_17 , V_33 , V_34 ) ;
}
F_26 ( & V_17 -> V_31 ) ;
return F_25 ( V_17 , V_32 ) ? V_36 : V_37 ;
}
static T_3 F_28 ( int V_27 , void * V_28 )
{
struct V_8 * V_9 = V_28 ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
T_1 V_29 ;
V_29 = F_25 ( V_17 , V_32 ) ;
F_29 ( V_17 , V_29 , F_20 ) ;
return V_37 ;
}
static int F_30 ( struct V_8 * V_9 , int V_38 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 ;
V_19 = F_32 ( V_7 -> V_2 -> V_27 , F_22 ,
F_28 ,
V_39 ,
V_40 , V_9 ) ;
if ( V_19 ) {
F_18 ( V_17 -> V_10 ,
L_5 ,
V_7 -> V_2 -> V_27 ) ;
return V_19 ;
}
V_17 -> V_27 = V_7 -> V_2 -> V_27 ;
F_33 ( V_7 -> V_2 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_7 * V_7 = F_31 ( V_9 ) ;
return F_35 ( V_7 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = F_11 ( V_17 -> V_10 ) ;
int V_19 ;
F_37 ( V_9 ) ;
V_19 = F_38 ( V_7 ) ;
if ( V_19 < 0 )
return V_19 ;
F_39 ( V_17 ) ;
F_7 ( V_2 , V_41 ,
V_42 , V_42 ) ;
F_10 ( V_17 -> V_10 , false ) ;
F_40 ( V_17 ) ;
F_10 ( V_17 -> V_10 , true ) ;
F_41 ( V_7 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_4 ( V_7 ) ;
F_12 ( V_17 , true ) ;
return F_43 ( V_7 ) ;
}
static int F_44 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_19 = 0 ;
if ( V_7 -> V_43 ) {
F_37 ( V_9 ) ;
if ( V_9 -> V_44 )
F_45 ( & V_9 -> V_17 ) ;
F_46 ( V_17 -> V_27 ) ;
F_47 ( V_2 ) ;
} else {
V_19 = F_36 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
V_7 -> V_45 -> V_46 = false ;
}
if ( F_48 ( V_47 ) ) {
V_19 = F_49 ( V_17 , false ) ;
if ( V_19 < 0 )
F_18 ( V_17 -> V_10 ,
L_6 ) ;
}
return V_19 ;
}
static int F_50 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_48 * V_49 = NULL ;
int V_19 ;
if ( F_48 ( V_47 ) ) {
V_19 = F_49 ( V_17 , true ) ;
if ( V_19 < 0 ) {
F_18 ( V_17 -> V_10 ,
L_7 ) ;
return V_19 ;
}
}
if ( V_7 -> V_43 ) {
F_51 ( V_2 ) ;
F_52 ( V_9 ) ;
F_53 ( V_17 -> V_27 ) ;
F_54 (hlink, &ebus->hlink_list, list) {
if ( V_49 -> V_50 )
F_55 ( V_49 ) ;
}
if ( V_9 -> V_44 )
F_56 ( & V_9 -> V_17 ) ;
} else {
V_19 = F_42 ( V_9 ) ;
F_54 (hlink, &ebus->hlink_list, list) {
if ( ! V_49 -> V_50 )
F_57 ( V_49 ) ;
}
if ( ! V_9 -> V_44 )
F_45 ( & V_9 -> V_17 ) ;
}
return V_19 ;
}
static int F_58 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_8 , V_51 ) ;
return F_36 ( V_9 ) ;
}
static int F_59 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_8 , V_51 ) ;
return F_42 ( V_9 ) ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
V_7 -> V_52 = 1 ;
F_61 ( V_9 ) ;
if ( V_17 -> V_27 >= 0 )
F_62 ( V_17 -> V_27 , ( void * ) V_17 ) ;
F_63 ( V_17 ) ;
F_64 ( V_9 ) ;
F_65 ( V_9 ) ;
if ( V_17 -> V_53 )
F_66 ( V_17 -> V_53 ) ;
F_67 ( V_7 -> V_2 ) ;
F_68 ( V_7 -> V_2 ) ;
F_69 ( V_9 ) ;
if ( F_48 ( V_47 ) )
F_70 ( & V_9 -> V_17 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_7 , void * V_54 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_55 * V_56 ;
struct V_57 * V_58 = V_54 ;
int V_19 ;
V_58 = F_72 ( V_58 ) ;
if ( V_58 == NULL ) {
F_18 ( V_17 -> V_10 , L_9 ) ;
return - V_59 ;
}
V_7 -> V_60 = V_58 -> V_61 ;
V_56 = F_73 ( V_58 -> V_62 , - 1 ) ;
if ( V_56 == NULL ) {
F_18 ( V_17 -> V_10 , L_10 ) ;
return - V_63 ;
}
V_19 = F_74 ( V_56 ) ;
if ( V_19 ) {
F_18 ( V_17 -> V_10 , L_11 ) ;
F_75 ( V_56 ) ;
return - V_63 ;
}
if ( V_58 -> V_64 )
F_76 ( & V_56 -> V_10 , V_58 -> V_64 ) ;
V_7 -> V_65 = V_56 ;
return 0 ;
}
static void F_77 ( struct V_7 * V_7 )
{
if ( V_7 -> V_65 )
F_78 ( V_7 -> V_65 ) ;
}
static int F_79 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_55 * V_56 ;
int V_19 ;
V_56 = F_73 ( L_12 , - 1 ) ;
if ( ! V_56 ) {
F_18 ( V_17 -> V_10 , L_13 ) ;
return - V_66 ;
}
V_19 = F_74 ( V_56 ) ;
if ( V_19 ) {
F_18 ( V_17 -> V_10 , L_14 , V_19 ) ;
F_75 ( V_56 ) ;
return V_19 ;
}
V_7 -> V_67 = V_56 ;
return 0 ;
}
static void F_80 ( struct V_7 * V_7 )
{
if ( V_7 -> V_67 )
F_78 ( V_7 -> V_67 ) ;
}
static int F_81 ( struct V_8 * V_9 , int V_68 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_69 = ( V_68 << 28 ) | ( V_70 << 20 ) |
( V_71 << 8 ) | V_72 ;
unsigned int V_73 ;
F_82 ( & V_17 -> V_74 ) ;
F_83 ( V_17 , V_69 ) ;
F_84 ( V_17 , V_68 , & V_73 ) ;
F_85 ( & V_17 -> V_74 ) ;
if ( V_73 == - 1 )
return - V_63 ;
F_5 ( V_17 -> V_10 , L_15 , V_68 ) ;
return F_86 ( V_9 , V_68 ) ;
}
static int F_87 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_75 , V_76 ;
V_76 = V_77 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
if ( ( V_17 -> V_78 & ( 1 << V_75 ) ) ) {
if ( F_81 ( V_9 , V_75 ) < 0 ) {
F_88 ( V_17 -> V_10 ,
L_16 , V_75 ) ;
V_17 -> V_78 &= ~ ( 1 << V_75 ) ;
F_39 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
const struct V_79 * V_80 ,
struct V_7 * * V_81 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_82 ;
* V_81 = NULL ;
V_82 = F_90 ( V_2 ) ;
if ( V_82 < 0 )
return V_82 ;
V_7 = F_91 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_83 ) ;
if ( ! V_7 ) {
F_68 ( V_2 ) ;
return - V_66 ;
}
V_9 = & V_7 -> V_9 ;
F_92 ( V_9 , & V_2 -> V_10 , & V_84 , V_80 ) ;
V_9 -> V_17 . V_85 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_17 . V_86 = 0 ;
* V_81 = V_7 ;
return 0 ;
}
static int F_93 ( struct V_16 * V_17 )
{
int V_82 ;
V_82 = F_94 ( V_17 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_49 ( V_17 , true ) ;
if ( V_82 < 0 ) {
F_18 ( V_17 -> V_10 , L_7 ) ;
return V_82 ;
}
return V_82 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_82 ;
unsigned short V_87 ;
int V_88 , V_89 , V_90 ;
V_82 = F_96 ( V_2 , L_17 ) ;
if ( V_82 < 0 )
return V_82 ;
V_17 -> V_68 = F_97 ( V_2 , 0 ) ;
V_17 -> V_53 = F_98 ( V_2 , 0 ) ;
if ( V_17 -> V_53 == NULL ) {
F_18 ( V_17 -> V_10 , L_18 ) ;
return - V_91 ;
}
F_99 ( V_17 ) ;
if ( F_30 ( V_9 , 0 ) < 0 )
return - V_92 ;
F_100 ( V_2 ) ;
F_101 ( V_17 -> V_27 ) ;
V_87 = F_102 ( V_17 , V_93 ) ;
F_5 ( V_17 -> V_10 , L_19 , V_87 ) ;
if ( ! F_103 ( V_17 -> V_10 , F_104 ( 64 ) ) ) {
F_105 ( V_17 -> V_10 , F_104 ( 64 ) ) ;
} else {
F_103 ( V_17 -> V_10 , F_104 ( 32 ) ) ;
F_105 ( V_17 -> V_10 , F_104 ( 32 ) ) ;
}
V_88 = ( V_87 >> 8 ) & 0x0f ;
V_89 = ( V_87 >> 12 ) & 0x0f ;
if ( ! V_89 && ! V_88 )
return - V_63 ;
V_9 -> V_94 = V_88 + V_89 ;
F_106
( V_9 , 0 , V_88 , V_95 ) ;
V_90 = V_88 ;
F_106
( V_9 , V_90 , V_89 , V_96 ) ;
V_82 = F_107 ( V_17 ) ;
if ( V_82 < 0 )
return V_82 ;
F_4 ( V_7 ) ;
if ( F_48 ( V_47 ) ) {
V_82 = F_93 ( V_17 ) ;
if ( V_82 < 0 )
return V_82 ;
}
F_12 ( V_17 , true ) ;
if ( ! V_17 -> V_78 ) {
F_108 ( V_17 -> V_10 , L_20 ) ;
}
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_48 * V_49 = NULL ;
int V_82 ;
V_82 = F_89 ( V_2 , NULL , & V_7 ) ;
if ( V_82 < 0 )
return V_82 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_82 = F_95 ( V_9 ) ;
if ( V_82 < 0 )
goto V_99;
V_7 -> V_98 = V_2 -> V_12 ;
F_110 ( V_17 -> V_10 ) ;
V_7 -> V_100 = F_111 ( V_17 -> V_10 ) ;
if ( V_7 -> V_100 == NULL ) {
V_82 = - V_59 ;
goto V_101;
}
F_112 ( V_7 ) ;
F_113 ( V_7 -> V_2 , V_9 ) ;
V_102 . V_103 = F_114 ( V_7 ) ;
if ( V_17 -> V_104 ) {
V_82 = F_71 ( V_7 ,
( void * ) V_98 -> V_54 ) ;
if ( V_82 < 0 )
goto V_105;
V_82 = F_115 ( V_7 ) ;
if ( V_82 < 0 ) {
F_5 ( V_17 -> V_10 , L_21 ) ;
goto V_106;
}
V_7 -> V_45 -> V_107 = F_10 ;
}
if ( V_17 -> V_108 )
F_116 ( V_9 ) ;
V_82 = F_79 ( V_7 ) ;
if ( V_82 < 0 )
goto V_109;
V_82 = F_117 ( V_17 -> V_10 ) ;
if ( V_82 < 0 )
goto V_110;
V_82 = F_87 ( V_9 ) ;
if ( V_82 < 0 )
goto V_111;
if ( F_48 ( V_47 ) ) {
V_82 = F_49 ( V_17 , false ) ;
if ( V_82 < 0 ) {
F_18 ( V_17 -> V_10 , L_22 ) ;
return V_82 ;
}
}
F_54 (hlink, &ebus->hlink_list, list)
F_118 ( V_9 , V_49 ) ;
F_119 ( V_17 -> V_10 ) ;
F_120 ( V_17 -> V_10 ) ;
return 0 ;
V_111:
F_121 ( V_17 -> V_10 ) ;
V_110:
F_80 ( V_7 ) ;
V_109:
F_122 ( V_7 ) ;
V_106:
F_77 ( V_7 ) ;
V_105:
F_123 ( V_7 -> V_100 ) ;
V_101:
if ( F_48 ( V_47 ) )
F_49 ( V_17 , false ) ;
V_99:
V_7 -> V_52 = 1 ;
F_60 ( V_9 ) ;
return V_82 ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_24 * V_112 ;
struct V_113 * V_114 ;
struct V_7 * V_7 ;
if ( V_9 == NULL )
return;
V_7 = F_31 ( V_9 ) ;
if ( V_7 -> V_52 )
return;
F_61 ( V_9 ) ;
F_54 (s, &bus->stream_list, list) {
V_114 = F_125 ( V_112 ) ;
F_126 ( V_9 , V_114 , false ) ;
}
F_39 ( V_17 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_7 * V_7 = F_31 ( V_9 ) ;
F_128 ( V_7 -> V_115 ) ;
F_129 ( & V_2 -> V_10 ) ;
F_130 ( V_9 ) ;
F_121 ( & V_2 -> V_10 ) ;
F_122 ( V_7 ) ;
F_77 ( V_7 ) ;
F_80 ( V_7 ) ;
F_123 ( V_7 -> V_100 ) ;
F_60 ( V_9 ) ;
F_76 ( & V_2 -> V_10 , NULL ) ;
}
