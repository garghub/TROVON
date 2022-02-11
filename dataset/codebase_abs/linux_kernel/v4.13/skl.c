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
V_7 -> V_52 = 0 ;
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
F_70 ( & V_7 -> V_54 ) ;
if ( F_48 ( V_47 ) )
F_71 ( & V_9 -> V_17 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_7 , void * V_55 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_55 ;
int V_19 ;
V_59 = F_73 ( V_59 ) ;
if ( V_59 == NULL ) {
F_18 ( V_17 -> V_10 , L_9 ) ;
return - V_60 ;
}
V_7 -> V_61 = V_59 -> V_62 ;
V_57 = F_74 ( V_59 -> V_63 , - 1 ) ;
if ( V_57 == NULL ) {
F_18 ( V_17 -> V_10 , L_10 ) ;
return - V_64 ;
}
V_19 = F_75 ( V_57 ) ;
if ( V_19 ) {
F_18 ( V_17 -> V_10 , L_11 ) ;
F_76 ( V_57 ) ;
return - V_64 ;
}
if ( V_59 -> V_65 )
F_77 ( & V_57 -> V_10 , V_59 -> V_65 ) ;
V_7 -> V_66 = V_57 ;
return 0 ;
}
static void F_78 ( struct V_7 * V_7 )
{
if ( V_7 -> V_66 )
F_79 ( V_7 -> V_66 ) ;
}
static int F_80 ( struct V_7 * V_7 )
{
struct V_16 * V_17 = F_6 ( & V_7 -> V_9 ) ;
struct V_56 * V_57 ;
int V_19 ;
V_57 = F_74 ( L_12 , - 1 ) ;
if ( ! V_57 ) {
F_18 ( V_17 -> V_10 , L_13 ) ;
return - V_67 ;
}
V_19 = F_75 ( V_57 ) ;
if ( V_19 ) {
F_18 ( V_17 -> V_10 , L_14 , V_19 ) ;
F_76 ( V_57 ) ;
return V_19 ;
}
V_7 -> V_68 = V_57 ;
return 0 ;
}
static void F_81 ( struct V_7 * V_7 )
{
if ( V_7 -> V_68 )
F_79 ( V_7 -> V_68 ) ;
}
static int F_82 ( struct V_8 * V_9 , int V_69 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
unsigned int V_70 = ( V_69 << 28 ) | ( V_71 << 20 ) |
( V_72 << 8 ) | V_73 ;
unsigned int V_74 = - 1 ;
F_83 ( & V_17 -> V_75 ) ;
F_84 ( V_17 , V_70 ) ;
F_85 ( V_17 , V_69 , & V_74 ) ;
F_86 ( & V_17 -> V_75 ) ;
if ( V_74 == - 1 )
return - V_64 ;
F_5 ( V_17 -> V_10 , L_15 , V_69 ) ;
return F_87 ( V_9 , V_69 ) ;
}
static int F_88 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_6 ( V_9 ) ;
int V_76 , V_77 ;
V_77 = V_78 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
if ( ( V_17 -> V_79 & ( 1 << V_76 ) ) ) {
if ( F_82 ( V_9 , V_76 ) < 0 ) {
F_89 ( V_17 -> V_10 ,
L_16 , V_76 ) ;
V_17 -> V_79 &= ~ ( 1 << V_76 ) ;
F_39 ( V_17 ) ;
F_12 ( V_17 , true ) ;
}
}
}
return 0 ;
}
static int F_90 ( struct V_16 * V_17 )
{
int V_80 ;
V_80 = F_91 ( V_17 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_49 ( V_17 , true ) ;
if ( V_80 < 0 )
F_18 ( V_17 -> V_10 , L_7 ) ;
return V_80 ;
}
static void F_92 ( struct V_81 * V_82 )
{
struct V_7 * V_7 = F_93 ( V_82 , struct V_7 , V_54 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_48 * V_49 = NULL ;
int V_80 ;
if ( F_48 ( V_47 ) ) {
V_80 = F_90 ( V_17 ) ;
if ( V_80 < 0 )
return;
}
V_80 = F_12 ( V_17 , true ) ;
if ( V_80 < 0 ) {
F_18 ( V_17 -> V_10 , L_17 , V_80 ) ;
goto V_83;
}
if ( ! V_17 -> V_79 )
F_94 ( V_17 -> V_10 , L_18 ) ;
V_80 = F_88 ( V_9 ) ;
if ( V_80 < 0 )
goto V_83;
if ( F_48 ( V_47 ) ) {
V_80 = F_49 ( V_17 , false ) ;
if ( V_80 < 0 ) {
F_18 ( V_17 -> V_10 , L_19 ) ;
return;
}
}
V_80 = F_95 ( V_17 -> V_10 ) ;
if ( V_80 < 0 )
return;
F_54 (hlink, &ebus->hlink_list, list)
F_96 ( V_9 , V_49 ) ;
F_97 ( V_17 -> V_10 ) ;
F_98 ( V_17 -> V_10 ) ;
V_7 -> V_52 = 1 ;
return;
V_83:
if ( F_48 ( V_47 ) )
V_80 = F_49 ( V_17 , false ) ;
}
static int F_99 ( struct V_1 * V_2 ,
const struct V_84 * V_85 ,
struct V_7 * * V_86 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_80 ;
* V_86 = NULL ;
V_80 = F_100 ( V_2 ) ;
if ( V_80 < 0 )
return V_80 ;
V_7 = F_101 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_87 ) ;
if ( ! V_7 ) {
F_68 ( V_2 ) ;
return - V_67 ;
}
V_9 = & V_7 -> V_9 ;
F_102 ( V_9 , & V_2 -> V_10 , & V_88 , V_85 ) ;
V_9 -> V_17 . V_89 = 1 ;
V_7 -> V_2 = V_2 ;
F_103 ( & V_7 -> V_54 , F_92 ) ;
V_9 -> V_17 . V_90 = 0 ;
* V_86 = V_7 ;
return 0 ;
}
static int F_104 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_31 ( V_9 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_80 ;
unsigned short V_91 ;
int V_92 , V_93 , V_94 ;
V_80 = F_105 ( V_2 , L_20 ) ;
if ( V_80 < 0 )
return V_80 ;
V_17 -> V_69 = F_106 ( V_2 , 0 ) ;
V_17 -> V_53 = F_107 ( V_2 , 0 ) ;
if ( V_17 -> V_53 == NULL ) {
F_18 ( V_17 -> V_10 , L_21 ) ;
return - V_95 ;
}
F_108 ( V_17 ) ;
if ( F_30 ( V_9 , 0 ) < 0 )
return - V_96 ;
F_109 ( V_2 ) ;
F_110 ( V_17 -> V_27 ) ;
V_91 = F_111 ( V_17 , V_97 ) ;
F_5 ( V_17 -> V_10 , L_22 , V_91 ) ;
if ( ! F_112 ( V_17 -> V_10 , F_113 ( 64 ) ) ) {
F_114 ( V_17 -> V_10 , F_113 ( 64 ) ) ;
} else {
F_112 ( V_17 -> V_10 , F_113 ( 32 ) ) ;
F_114 ( V_17 -> V_10 , F_113 ( 32 ) ) ;
}
V_92 = ( V_91 >> 8 ) & 0x0f ;
V_93 = ( V_91 >> 12 ) & 0x0f ;
if ( ! V_93 && ! V_92 )
return - V_64 ;
V_9 -> V_98 = V_92 + V_93 ;
F_115
( V_9 , 0 , V_92 , V_99 ) ;
V_94 = V_92 ;
F_115
( V_9 , V_94 , V_93 , V_100 ) ;
V_80 = F_116 ( V_17 ) ;
if ( V_80 < 0 )
return V_80 ;
F_4 ( V_7 ) ;
return F_12 ( V_17 , true ) ;
}
static int F_117 ( struct V_1 * V_2 ,
const struct V_101 * V_102 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_16 * V_17 = NULL ;
int V_80 ;
V_80 = F_99 ( V_2 , NULL , & V_7 ) ;
if ( V_80 < 0 )
return V_80 ;
V_9 = & V_7 -> V_9 ;
V_17 = F_6 ( V_9 ) ;
V_80 = F_104 ( V_9 ) ;
if ( V_80 < 0 )
goto V_103;
V_7 -> V_102 = V_2 -> V_12 ;
F_118 ( V_17 -> V_10 ) ;
V_7 -> V_104 = F_119 ( V_17 -> V_10 ) ;
if ( V_7 -> V_104 == NULL ) {
V_80 = - V_60 ;
goto V_103;
}
V_80 = F_120 ( V_7 ) ;
if ( V_80 < 0 )
goto V_105;
F_121 ( V_7 ) ;
F_122 ( V_7 -> V_2 , V_9 ) ;
V_106 . V_107 = F_123 ( V_7 ) ;
if ( V_17 -> V_108 ) {
V_80 = F_72 ( V_7 ,
( void * ) V_102 -> V_55 ) ;
if ( V_80 < 0 )
goto V_105;
V_80 = F_124 ( V_7 ) ;
if ( V_80 < 0 ) {
F_5 ( V_17 -> V_10 , L_23 ) ;
goto V_109;
}
V_7 -> V_45 -> V_110 = F_10 ;
}
if ( V_17 -> V_111 )
F_125 ( V_9 ) ;
F_39 ( V_17 ) ;
V_80 = F_80 ( V_7 ) ;
if ( V_80 < 0 )
goto V_112;
F_126 ( & V_7 -> V_54 ) ;
return 0 ;
V_112:
F_127 ( V_7 ) ;
V_109:
F_78 ( V_7 ) ;
V_105:
F_128 ( V_7 -> V_104 ) ;
V_103:
F_60 ( V_9 ) ;
return V_80 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_16 * V_17 = F_6 ( V_9 ) ;
struct V_24 * V_113 ;
struct V_114 * V_115 ;
struct V_7 * V_7 ;
if ( V_9 == NULL )
return;
V_7 = F_31 ( V_9 ) ;
if ( ! V_7 -> V_52 )
return;
F_61 ( V_9 ) ;
F_54 (s, &bus->stream_list, list) {
V_115 = F_130 ( V_113 ) ;
F_131 ( V_9 , V_115 , false ) ;
}
F_39 ( V_17 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_15 ( V_2 ) ;
struct V_7 * V_7 = F_31 ( V_9 ) ;
F_133 ( V_7 -> V_116 ) ;
F_134 ( & V_2 -> V_10 ) ;
F_135 ( V_9 ) ;
V_7 -> V_117 = NULL ;
F_136 ( & V_2 -> V_10 ) ;
F_127 ( V_7 ) ;
F_78 ( V_7 ) ;
F_81 ( V_7 ) ;
F_137 ( V_7 ) ;
F_128 ( V_7 -> V_104 ) ;
F_60 ( V_9 ) ;
F_77 ( & V_2 -> V_10 , NULL ) ;
}
