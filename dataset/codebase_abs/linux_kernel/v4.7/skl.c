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
if ( V_9 -> V_38 )
F_40 ( & V_9 -> V_17 ) ;
F_41 ( V_17 -> V_23 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
} else {
V_19 = F_31 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_44 ( V_39 ) ) {
V_19 = F_45 ( V_17 , false ) ;
if ( V_19 < 0 )
F_29 ( V_17 -> V_10 ,
L_3 ) ;
}
return V_19 ;
}
static int F_46 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_40 * V_41 = NULL ;
int V_19 ;
if ( F_44 ( V_39 ) ) {
V_19 = F_45 ( V_17 , true ) ;
if ( V_19 < 0 ) {
F_29 ( V_17 -> V_10 ,
L_4 ) ;
return V_19 ;
}
}
if ( V_7 -> V_37 ) {
F_47 ( V_2 ) ;
V_19 = F_48 ( V_2 ) ;
F_49 ( V_9 ) ;
F_50 ( V_17 -> V_23 ) ;
F_51 (hlink, &ebus->hlink_list, list) {
if ( V_41 -> V_42 )
F_52 ( V_41 ) ;
}
if ( V_9 -> V_38 )
F_53 ( & V_9 -> V_17 ) ;
} else {
V_19 = F_36 ( V_9 ) ;
F_51 (hlink, &ebus->hlink_list, list) {
if ( ! V_41 -> V_42 )
F_54 ( V_41 ) ;
}
if ( ! V_9 -> V_38 )
F_40 ( & V_9 -> V_17 ) ;
}
return V_19 ;
}
static int F_55 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_43 ) ;
return F_31 ( V_9 ) ;
}
static int F_56 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
F_5 ( V_17 -> V_10 , L_5 , V_43 ) ;
return F_36 ( V_9 ) ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
V_7 -> V_44 = 1 ;
F_58 ( V_9 ) ;
if ( V_17 -> V_23 >= 0 )
F_59 ( V_17 -> V_23 , ( void * ) V_17 ) ;
F_60 ( V_17 ) ;
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
if ( V_17 -> V_45 )
F_63 ( V_17 -> V_45 ) ;
F_64 ( V_7 -> V_2 ) ;
F_43 ( V_7 -> V_2 ) ;
F_65 ( V_9 ) ;
if ( F_44 ( V_39 ) )
F_66 ( & V_9 -> V_17 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_7 , void * V_46 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_47 * V_48 ;
struct V_49 * V_50 = V_46 ;
int V_19 ;
V_50 = F_68 ( V_50 ) ;
if ( V_50 == NULL ) {
F_29 ( V_17 -> V_10 , L_6 ) ;
return - V_51 ;
}
V_7 -> V_52 = V_50 -> V_53 ;
V_48 = F_69 ( V_50 -> V_54 , - 1 ) ;
if ( V_48 == NULL ) {
F_29 ( V_17 -> V_10 , L_7 ) ;
return - V_55 ;
}
V_19 = F_70 ( V_48 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_8 ) ;
F_71 ( V_48 ) ;
return - V_55 ;
}
V_7 -> V_56 = V_48 ;
return 0 ;
}
static void F_72 ( struct V_7 * V_7 )
{
if ( V_7 -> V_56 )
F_73 ( V_7 -> V_56 ) ;
}
static int F_74 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_47 * V_48 ;
int V_19 ;
V_48 = F_69 ( L_9 , - 1 ) ;
if ( ! V_48 ) {
F_29 ( V_17 -> V_10 , L_10 ) ;
return - V_57 ;
}
V_19 = F_70 ( V_48 ) ;
if ( V_19 ) {
F_29 ( V_17 -> V_10 , L_11 , V_19 ) ;
F_71 ( V_48 ) ;
return V_19 ;
}
V_7 -> V_58 = V_48 ;
return 0 ;
}
static void F_75 ( struct V_7 * V_7 )
{
if ( V_7 -> V_58 )
F_73 ( V_7 -> V_58 ) ;
}
static int F_76 ( struct V_8 * V_9 , int V_59 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_60 = ( V_59 << 28 ) | ( V_61 << 20 ) |
( V_62 << 8 ) | V_63 ;
unsigned int V_64 ;
F_77 ( & V_17 -> V_65 ) ;
F_78 ( V_17 , V_60 ) ;
F_79 ( V_17 , V_59 , & V_64 ) ;
F_80 ( & V_17 -> V_65 ) ;
if ( V_64 == - 1 )
return - V_55 ;
F_5 ( V_17 -> V_10 , L_12 , V_59 ) ;
return F_81 ( V_9 , V_59 ) ;
}
static int F_82 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_66 , V_67 ;
V_67 = V_68 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( ( V_17 -> V_69 & ( 1 << V_66 ) ) ) {
if ( F_76 ( V_9 , V_66 ) < 0 ) {
F_83 ( V_17 -> V_10 ,
L_13 , V_66 ) ;
V_17 -> V_69 &= ~ ( 1 << V_66 ) ;
F_34 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
const struct V_70 * V_71 ,
struct V_7 * * V_72 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_73 ;
* V_72 = NULL ;
V_73 = F_48 ( V_2 ) ;
if ( V_73 < 0 )
return V_73 ;
V_7 = F_85 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_74 ) ;
if ( ! V_7 ) {
F_43 ( V_2 ) ;
return - V_57 ;
}
V_9 = & V_7 -> V_9 ;
F_86 ( V_9 , & V_2 -> V_10 , & V_75 , V_71 ) ;
V_9 -> V_17 . V_76 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_17 . V_77 = 0 ;
* V_72 = V_7 ;
return 0 ;
}
static int F_87 ( struct V_16 * V_17 )
{
int V_73 ;
V_73 = F_88 ( V_17 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_45 ( V_17 , true ) ;
if ( V_73 < 0 ) {
F_29 ( V_17 -> V_10 , L_4 ) ;
return V_73 ;
}
return V_73 ;
}
static int F_89 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_27 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_73 ;
unsigned short V_78 ;
int V_79 , V_80 , V_81 ;
V_73 = F_90 ( V_2 , L_14 ) ;
if ( V_73 < 0 )
return V_73 ;
V_17 -> V_59 = F_91 ( V_2 , 0 ) ;
V_17 -> V_45 = F_92 ( V_2 , 0 ) ;
if ( V_17 -> V_45 == NULL ) {
F_29 ( V_17 -> V_10 , L_15 ) ;
return - V_82 ;
}
F_93 ( V_9 ) ;
if ( F_26 ( V_9 , 0 ) < 0 )
return - V_83 ;
F_94 ( V_2 ) ;
F_95 ( V_17 -> V_23 ) ;
V_78 = F_96 ( V_17 , V_84 ) ;
F_5 ( V_17 -> V_10 , L_16 , V_78 ) ;
if ( ! F_97 ( V_17 -> V_10 , F_98 ( 64 ) ) ) {
F_99 ( V_17 -> V_10 , F_98 ( 64 ) ) ;
} else {
F_97 ( V_17 -> V_10 , F_98 ( 32 ) ) ;
F_99 ( V_17 -> V_10 , F_98 ( 32 ) ) ;
}
V_79 = ( V_78 >> 8 ) & 0x0f ;
V_80 = ( V_78 >> 12 ) & 0x0f ;
if ( ! V_80 && ! V_79 )
return - V_55 ;
V_9 -> V_85 = V_79 + V_80 ;
F_100
( V_9 , 0 , V_79 , V_86 ) ;
V_81 = V_79 ;
F_100
( V_9 , V_81 , V_80 , V_87 ) ;
V_73 = F_101 ( V_17 ) ;
if ( V_73 < 0 )
return V_73 ;
F_4 ( V_7 ) ;
if ( F_44 ( V_39 ) ) {
V_73 = F_87 ( V_17 ) ;
if ( V_73 < 0 )
return V_73 ;
}
F_12 ( V_17 , true ) ;
if ( ! V_17 -> V_69 ) {
F_102 ( V_17 -> V_10 , L_17 ) ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
const struct V_88 * V_89 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_40 * V_41 = NULL ;
int V_73 ;
V_73 = F_84 ( V_2 , NULL , & V_7 ) ;
if ( V_73 < 0 )
return V_73 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_73 = F_89 ( V_9 ) ;
if ( V_73 < 0 )
goto V_90;
V_7 -> V_89 = V_2 -> V_12 ;
V_7 -> V_91 = F_104 ( V_17 -> V_10 ) ;
if ( V_7 -> V_91 == NULL )
goto V_90;
F_105 ( V_7 ) ;
F_106 ( V_7 -> V_2 , V_9 ) ;
if ( V_9 -> V_92 ) {
V_73 = F_67 ( V_7 ,
( void * ) V_89 -> V_46 ) ;
if ( V_73 < 0 )
goto V_93;
V_73 = F_107 ( V_7 ) ;
if ( V_73 < 0 ) {
F_5 ( V_17 -> V_10 , L_18 ) ;
goto V_94;
}
V_7 -> V_95 -> V_96 = F_10 ;
}
if ( V_9 -> V_97 )
F_108 ( V_9 ) ;
V_73 = F_74 ( V_7 ) ;
if ( V_73 < 0 )
goto V_98;
V_73 = F_109 ( V_17 -> V_10 ) ;
if ( V_73 < 0 )
goto V_99;
V_73 = F_82 ( V_9 ) ;
if ( V_73 < 0 )
goto V_100;
if ( F_44 ( V_39 ) ) {
V_73 = F_45 ( V_17 , false ) ;
if ( V_73 < 0 ) {
F_29 ( V_17 -> V_10 , L_19 ) ;
return V_73 ;
}
}
F_51 (hlink, &ebus->hlink_list, list)
F_110 ( V_9 , V_41 ) ;
F_111 ( V_17 -> V_10 ) ;
F_112 ( V_17 -> V_10 ) ;
return 0 ;
V_100:
F_113 ( V_17 -> V_10 ) ;
V_99:
F_75 ( V_7 ) ;
V_98:
F_114 ( V_7 ) ;
V_94:
F_72 ( V_7 ) ;
V_93:
F_115 ( V_7 -> V_91 ) ;
V_90:
V_7 -> V_44 = 1 ;
F_57 ( V_9 ) ;
return V_73 ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_20 * V_101 ;
struct V_102 * V_103 ;
struct V_7 * V_7 ;
if ( V_9 == NULL )
return;
V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_44 )
return;
F_58 ( V_9 ) ;
F_51 (s, &bus->stream_list, list) {
V_103 = F_117 ( V_101 ) ;
F_118 ( V_9 , V_103 , false ) ;
}
F_34 ( V_17 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_39 ( V_2 ) ;
struct V_7 * V_7 = F_27 ( V_9 ) ;
if ( V_7 -> V_104 )
F_120 ( V_7 -> V_104 ) ;
if ( F_121 ( V_2 ) )
F_122 ( & V_2 -> V_10 ) ;
F_123 ( V_9 ) ;
F_113 ( & V_2 -> V_10 ) ;
F_114 ( V_7 ) ;
F_72 ( V_7 ) ;
F_75 ( V_7 ) ;
F_115 ( V_7 -> V_91 ) ;
F_57 ( V_9 ) ;
F_124 ( & V_2 -> V_10 , NULL ) ;
}
