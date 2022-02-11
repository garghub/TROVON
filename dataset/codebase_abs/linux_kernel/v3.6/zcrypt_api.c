static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
return snprintf ( V_5 , V_9 , L_1 , V_7 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
return snprintf ( V_5 , V_9 , L_2 , V_7 -> V_11 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
int V_11 ;
if ( sscanf ( V_5 , L_2 , & V_11 ) != 1 || V_11 < 0 || V_11 > 1 )
return - V_13 ;
V_7 -> V_11 = V_11 ;
if ( ! V_11 )
F_5 ( V_7 -> V_14 ) ;
return V_12 ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_6 * V_15 ;
struct V_16 * V_17 ;
if ( V_7 -> V_18 == 0 )
return;
for ( V_17 = V_7 -> V_19 . V_20 ; V_17 != & V_21 ; V_17 = V_17 -> V_20 ) {
V_15 = F_7 ( V_17 , struct V_6 , V_19 ) ;
if ( ( V_15 -> V_22 + 1 ) * V_15 -> V_18 <=
( V_7 -> V_22 + 1 ) * V_7 -> V_18 &&
V_15 -> V_18 != 0 )
break;
}
if ( V_17 == V_7 -> V_19 . V_20 )
return;
F_8 ( & V_7 -> V_19 , V_17 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_6 * V_15 ;
struct V_16 * V_17 ;
if ( V_7 -> V_18 == 0 )
return;
for ( V_17 = V_7 -> V_19 . V_23 ; V_17 != & V_21 ; V_17 = V_17 -> V_23 ) {
V_15 = F_7 ( V_17 , struct V_6 , V_19 ) ;
if ( ( V_15 -> V_22 + 1 ) * V_15 -> V_18 >
( V_7 -> V_22 + 1 ) * V_7 -> V_18 ||
V_15 -> V_18 == 0 )
break;
}
if ( V_17 == V_7 -> V_19 . V_23 )
return;
F_10 ( & V_7 -> V_19 , V_17 ) ;
}
static void F_11 ( struct V_24 * V_24 )
{
struct V_6 * V_7 =
F_12 ( V_24 , struct V_6 , V_25 ) ;
F_13 ( V_7 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
F_15 ( & V_7 -> V_25 ) ;
}
int F_16 ( struct V_6 * V_7 )
{
return F_17 ( & V_7 -> V_25 , F_11 ) ;
}
struct V_6 * F_18 ( T_2 V_26 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( sizeof( struct V_6 ) , V_27 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_28 . V_29 = F_20 ( V_26 , V_27 ) ;
if ( ! V_7 -> V_28 . V_29 )
goto V_30;
V_7 -> V_28 . V_31 = V_26 ;
F_21 ( & V_7 -> V_32 ) ;
F_22 ( & V_7 -> V_19 ) ;
return V_7 ;
V_30:
F_23 ( V_7 ) ;
return NULL ;
}
void F_13 ( struct V_6 * V_7 )
{
F_23 ( V_7 -> V_28 . V_29 ) ;
F_23 ( V_7 ) ;
}
int F_24 ( struct V_6 * V_7 )
{
int V_33 ;
V_33 = F_25 ( & V_7 -> V_14 -> V_1 . V_34 ,
& V_35 ) ;
if ( V_33 )
goto V_36;
F_26 ( & V_7 -> V_14 -> V_1 ) ;
F_27 ( & V_7 -> V_25 ) ;
F_28 ( & V_37 ) ;
V_7 -> V_11 = 1 ;
F_29 ( & V_7 -> V_19 , & V_21 ) ;
F_6 ( V_7 ) ;
V_38 ++ ;
F_30 ( & V_37 ) ;
if ( V_7 -> V_39 -> V_40 ) {
V_33 = F_31 () ;
if ( V_33 )
goto V_41;
}
return 0 ;
V_41:
F_28 ( & V_37 ) ;
V_38 -- ;
F_32 ( & V_7 -> V_19 ) ;
F_30 ( & V_37 ) ;
F_33 ( & V_7 -> V_14 -> V_1 . V_34 ,
& V_35 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
V_36:
return V_33 ;
}
void F_35 ( struct V_6 * V_7 )
{
if ( V_7 -> V_39 -> V_40 )
F_36 () ;
F_28 ( & V_37 ) ;
V_38 -- ;
F_32 ( & V_7 -> V_19 ) ;
F_30 ( & V_37 ) ;
F_33 ( & V_7 -> V_14 -> V_1 . V_34 ,
& V_35 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
}
static T_1 F_37 ( struct V_42 * V_43 , char T_3 * V_5 ,
T_2 V_12 , T_4 * V_44 )
{
return - V_45 ;
}
static T_1 F_38 ( struct V_42 * V_43 , const char T_3 * V_5 ,
T_2 V_12 , T_4 * V_44 )
{
return - V_45 ;
}
static int F_39 ( struct V_46 * V_46 , struct V_42 * V_43 )
{
F_40 ( & V_47 ) ;
return F_41 ( V_46 , V_43 ) ;
}
static int F_42 ( struct V_46 * V_46 , struct V_42 * V_43 )
{
F_43 ( & V_47 ) ;
return 0 ;
}
static long F_44 ( struct V_48 * V_49 )
{
struct V_6 * V_7 ;
int V_33 ;
if ( V_49 -> V_50 < V_49 -> V_51 )
return - V_13 ;
V_49 -> V_50 = V_49 -> V_51 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_39 -> V_52 ||
V_7 -> V_53 > V_49 -> V_51 ||
V_7 -> V_54 < V_49 -> V_51 )
continue;
F_14 ( V_7 ) ;
F_26 ( & V_7 -> V_14 -> V_1 ) ;
V_7 -> V_22 ++ ;
F_9 ( V_7 ) ;
if ( F_46 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ) {
F_30 ( & V_37 ) ;
V_33 = V_7 -> V_39 -> V_52 ( V_7 , V_49 ) ;
F_28 ( & V_37 ) ;
F_47 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ;
}
else
V_33 = - V_58 ;
V_7 -> V_22 -- ;
F_6 ( V_7 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
F_30 ( & V_37 ) ;
return V_33 ;
}
F_30 ( & V_37 ) ;
return - V_59 ;
}
static long F_48 ( struct V_60 * V_61 )
{
struct V_6 * V_7 ;
unsigned long long V_62 , V_63 , V_64 ;
int V_33 , V_65 ;
if ( V_61 -> V_50 < V_61 -> V_51 ||
( V_61 -> V_51 & 1 ) )
return - V_13 ;
V_61 -> V_50 = V_61 -> V_51 ;
V_65 = 0 ;
V_66:
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_39 -> V_67 ||
V_7 -> V_53 > V_61 -> V_51 ||
V_7 -> V_54 < V_61 -> V_51 )
continue;
if ( V_7 -> V_68 && V_61 -> V_51 > 240 ) {
if ( V_65 == 0 ) {
unsigned int V_69 ;
F_30 ( & V_37 ) ;
if ( V_61 -> V_51 <= 256 )
V_69 = V_61 -> V_51 / 2 - 120 ;
else
V_69 = 8 ;
if ( V_69 > sizeof( V_62 ) )
return - V_70 ;
V_62 = V_63 = V_64 = 0 ;
if ( F_49 ( & V_62 , V_61 -> V_71 , V_69 ) ||
F_49 ( & V_63 , V_61 -> V_72 , V_69 ) ||
F_49 ( & V_64 , V_61 -> V_73 , V_69 ) )
return - V_70 ;
V_62 = V_63 = V_64 = 0 ;
V_65 = 1 ;
goto V_66;
}
if ( V_62 != 0ULL || V_63 != 0ULL || V_64 != 0ULL )
continue;
}
F_14 ( V_7 ) ;
F_26 ( & V_7 -> V_14 -> V_1 ) ;
V_7 -> V_22 ++ ;
F_9 ( V_7 ) ;
if ( F_46 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ) {
F_30 ( & V_37 ) ;
V_33 = V_7 -> V_39 -> V_67 ( V_7 , V_61 ) ;
F_28 ( & V_37 ) ;
F_47 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ;
}
else
V_33 = - V_58 ;
V_7 -> V_22 -- ;
F_6 ( V_7 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
F_30 ( & V_37 ) ;
return V_33 ;
}
F_30 ( & V_37 ) ;
return - V_59 ;
}
static long F_50 ( struct V_74 * V_75 )
{
struct V_6 * V_7 ;
int V_33 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 || ! V_7 -> V_39 -> V_76 ||
( V_75 -> V_77 != V_78 &&
F_51 ( V_7 -> V_14 -> V_79 ) != V_75 -> V_77 )
)
continue;
F_14 ( V_7 ) ;
F_26 ( & V_7 -> V_14 -> V_1 ) ;
V_7 -> V_22 ++ ;
F_9 ( V_7 ) ;
if ( F_46 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ) {
F_30 ( & V_37 ) ;
V_33 = V_7 -> V_39 -> V_76 ( V_7 , V_75 ) ;
F_28 ( & V_37 ) ;
F_47 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ;
}
else
V_33 = - V_58 ;
V_7 -> V_22 -- ;
F_6 ( V_7 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
F_30 ( & V_37 ) ;
return V_33 ;
}
F_30 ( & V_37 ) ;
return - V_59 ;
}
static long F_52 ( char * V_80 )
{
struct V_6 * V_7 ;
int V_33 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 || ! V_7 -> V_39 -> V_40 )
continue;
F_14 ( V_7 ) ;
F_26 ( & V_7 -> V_14 -> V_1 ) ;
V_7 -> V_22 ++ ;
F_9 ( V_7 ) ;
if ( F_46 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ) {
F_30 ( & V_37 ) ;
V_33 = V_7 -> V_39 -> V_40 ( V_7 , V_80 ) ;
F_28 ( & V_37 ) ;
F_47 ( V_7 -> V_14 -> V_55 -> V_56 . V_57 ) ;
} else
V_33 = - V_58 ;
V_7 -> V_22 -- ;
F_6 ( V_7 ) ;
F_34 ( & V_7 -> V_14 -> V_1 ) ;
F_16 ( V_7 ) ;
F_30 ( & V_37 ) ;
return V_33 ;
}
F_30 ( & V_37 ) ;
return - V_59 ;
}
static void F_53 ( char V_81 [ V_82 ] )
{
struct V_6 * V_7 ;
memset ( V_81 , 0 , sizeof( char ) * V_82 ) ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list)
V_81 [ F_51 ( V_7 -> V_14 -> V_79 ) ] =
V_7 -> V_11 ? V_7 -> V_83 : 0x0d ;
F_30 ( & V_37 ) ;
}
static void F_54 ( char V_84 [ V_82 ] )
{
struct V_6 * V_7 ;
memset ( V_84 , 0 , sizeof( char ) * V_82 ) ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
F_55 ( & V_7 -> V_14 -> V_32 ) ;
V_84 [ F_51 ( V_7 -> V_14 -> V_79 ) ] =
V_7 -> V_14 -> V_85 +
V_7 -> V_14 -> V_86 ;
F_56 ( & V_7 -> V_14 -> V_32 ) ;
}
F_30 ( & V_37 ) ;
}
static void F_57 ( int V_87 [ V_82 ] )
{
struct V_6 * V_7 ;
memset ( V_87 , 0 , sizeof( int ) * V_82 ) ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
F_55 ( & V_7 -> V_14 -> V_32 ) ;
V_87 [ F_51 ( V_7 -> V_14 -> V_79 ) ] =
V_7 -> V_14 -> V_88 ;
F_56 ( & V_7 -> V_14 -> V_32 ) ;
}
F_30 ( & V_37 ) ;
}
static int F_58 ( void )
{
struct V_6 * V_7 ;
int V_85 = 0 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
F_55 ( & V_7 -> V_14 -> V_32 ) ;
V_85 += V_7 -> V_14 -> V_85 ;
F_56 ( & V_7 -> V_14 -> V_32 ) ;
}
F_30 ( & V_37 ) ;
return V_85 ;
}
static int F_59 ( void )
{
struct V_6 * V_7 ;
int V_86 = 0 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list) {
F_55 ( & V_7 -> V_14 -> V_32 ) ;
V_86 += V_7 -> V_14 -> V_86 ;
F_56 ( & V_7 -> V_14 -> V_32 ) ;
}
F_30 ( & V_37 ) ;
return V_86 ;
}
static int F_60 ( int type )
{
struct V_6 * V_7 ;
int V_89 = 0 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list)
if ( V_7 -> V_83 == type )
V_89 ++ ;
F_30 ( & V_37 ) ;
return V_89 ;
}
static long F_61 ( struct V_42 * V_43 , unsigned long V_90 )
{
struct V_91 * V_92 ;
int V_93 ;
V_92 = F_19 ( sizeof( * V_92 ) , V_27 ) ;
if ( ! V_92 )
return - V_94 ;
V_92 -> V_95 = V_38 ;
V_92 -> V_96 = F_60 ( V_97 ) ;
V_92 -> V_98 = F_60 ( V_99 ) ;
V_92 -> V_100 = F_59 () ;
V_92 -> V_101 = F_58 () ;
V_92 -> V_102 = F_62 ( & V_47 ) ;
V_92 -> V_103 = V_104 ;
F_53 ( V_92 -> V_81 ) ;
F_54 ( V_92 -> V_84 ) ;
V_93 = 0 ;
if ( F_63 ( ( void T_3 * ) V_90 , V_92 , sizeof( * V_92 ) ) )
V_93 = - V_70 ;
F_23 ( V_92 ) ;
return V_93 ;
}
static long F_64 ( struct V_42 * V_43 , unsigned int V_105 ,
unsigned long V_90 )
{
int V_33 ;
switch ( V_105 ) {
case V_106 : {
struct V_48 T_3 * V_107 = ( void T_3 * ) V_90 ;
struct V_48 V_49 ;
if ( F_49 ( & V_49 , V_107 , sizeof( V_49 ) ) )
return - V_70 ;
do {
V_33 = F_44 ( & V_49 ) ;
} while ( V_33 == - V_58 );
if ( V_33 )
return V_33 ;
return F_65 ( V_49 . V_50 , & V_107 -> V_50 ) ;
}
case V_108 : {
struct V_60 T_3 * V_109 = ( void T_3 * ) V_90 ;
struct V_60 V_61 ;
if ( F_49 ( & V_61 , V_109 , sizeof( V_61 ) ) )
return - V_70 ;
do {
V_33 = F_48 ( & V_61 ) ;
} while ( V_33 == - V_58 );
if ( V_33 )
return V_33 ;
return F_65 ( V_61 . V_50 , & V_109 -> V_50 ) ;
}
case V_110 : {
struct V_74 T_3 * V_111 = ( void T_3 * ) V_90 ;
struct V_74 V_75 ;
if ( F_49 ( & V_75 , V_111 , sizeof( V_75 ) ) )
return - V_70 ;
do {
V_33 = F_50 ( & V_75 ) ;
} while ( V_33 == - V_58 );
if ( F_63 ( V_111 , & V_75 , sizeof( V_75 ) ) )
return - V_70 ;
return V_33 ;
}
case V_112 : {
char V_81 [ V_82 ] ;
F_53 ( V_81 ) ;
if ( F_63 ( ( char T_3 * ) V_90 , V_81 ,
sizeof( char ) * V_82 ) )
return - V_70 ;
return 0 ;
}
case V_113 : {
char V_84 [ V_82 ] ;
F_54 ( V_84 ) ;
if ( F_63 ( ( char T_3 * ) V_90 , V_84 ,
sizeof( char ) * V_82 ) )
return - V_70 ;
return 0 ;
}
case V_114 : {
int V_87 [ V_82 ] ;
F_57 ( V_87 ) ;
if ( F_63 ( ( int T_3 * ) V_90 , V_87 ,
sizeof( int ) * V_82 ) )
return - V_70 ;
return 0 ;
}
case V_115 :
return F_65 ( F_59 () , ( int T_3 * ) V_90 ) ;
case V_116 :
return F_65 ( F_58 () , ( int T_3 * ) V_90 ) ;
case V_117 :
return F_65 ( F_62 ( & V_47 ) ,
( int T_3 * ) V_90 ) ;
case V_118 :
return F_65 ( V_104 , ( int T_3 * ) V_90 ) ;
case V_119 :
return F_61 ( V_43 , V_90 ) ;
case V_120 :
return F_65 ( V_38 , ( int T_3 * ) V_90 ) ;
case V_121 :
return F_65 ( F_60 ( V_97 ) ,
( int T_3 * ) V_90 ) ;
case V_122 :
return F_65 ( F_60 ( V_99 ) ,
( int T_3 * ) V_90 ) ;
case V_123 :
return F_65 ( F_60 ( V_124 ) ,
( int T_3 * ) V_90 ) ;
case V_125 :
return F_65 ( F_60 ( V_126 ) ,
( int T_3 * ) V_90 ) ;
case V_127 :
return F_65 ( F_60 ( V_124 ) +
F_60 ( V_126 ) ,
( int T_3 * ) V_90 ) ;
case V_128 :
return F_65 ( F_60 ( V_129 ) ,
( int T_3 * ) V_90 ) ;
case V_130 :
return F_65 ( F_60 ( V_131 ) ,
( int T_3 * ) V_90 ) ;
default:
return - V_132 ;
}
}
static long F_66 ( struct V_42 * V_43 , unsigned int V_105 ,
unsigned long V_90 )
{
struct V_133 T_3 * V_134 = F_67 ( V_90 ) ;
struct V_133 V_135 ;
struct V_48 V_136 ;
long V_33 ;
if ( F_49 ( & V_135 , V_134 , sizeof( V_135 ) ) )
return - V_70 ;
V_136 . V_137 = F_67 ( V_135 . V_137 ) ;
V_136 . V_51 = V_135 . V_51 ;
V_136 . V_138 = F_67 ( V_135 . V_138 ) ;
V_136 . V_50 = V_135 . V_50 ;
V_136 . V_139 = F_67 ( V_135 . V_139 ) ;
V_136 . V_140 = F_67 ( V_135 . V_140 ) ;
do {
V_33 = F_44 ( & V_136 ) ;
} while ( V_33 == - V_58 );
if ( ! V_33 )
V_33 = F_65 ( V_136 . V_50 ,
& V_134 -> V_50 ) ;
return V_33 ;
}
static long F_68 ( struct V_42 * V_43 , unsigned int V_105 ,
unsigned long V_90 )
{
struct V_141 T_3 * V_142 = F_67 ( V_90 ) ;
struct V_141 V_143 ;
struct V_60 V_144 ;
long V_33 ;
if ( F_49 ( & V_143 , V_142 , sizeof( V_143 ) ) )
return - V_70 ;
V_144 . V_137 = F_67 ( V_143 . V_137 ) ;
V_144 . V_51 = V_143 . V_51 ;
V_144 . V_138 = F_67 ( V_143 . V_138 ) ;
V_144 . V_50 = V_143 . V_50 ;
V_144 . V_72 = F_67 ( V_143 . V_72 ) ;
V_144 . V_145 = F_67 ( V_143 . V_145 ) ;
V_144 . V_71 = F_67 ( V_143 . V_71 ) ;
V_144 . V_146 = F_67 ( V_143 . V_146 ) ;
V_144 . V_73 = F_67 ( V_143 . V_73 ) ;
do {
V_33 = F_48 ( & V_144 ) ;
} while ( V_33 == - V_58 );
if ( ! V_33 )
V_33 = F_65 ( V_144 . V_50 ,
& V_142 -> V_50 ) ;
return V_33 ;
}
static long F_69 ( struct V_42 * V_43 , unsigned int V_105 ,
unsigned long V_90 )
{
struct V_147 T_3 * V_148 = F_67 ( V_90 ) ;
struct V_147 V_149 ;
struct V_74 V_150 ;
long V_33 ;
if ( F_49 ( & V_149 , V_148 , sizeof( V_149 ) ) )
return - V_70 ;
V_150 . V_151 = V_149 . V_151 ;
V_150 . V_77 = V_149 . V_77 ;
V_150 . V_152 = V_149 . V_152 ;
V_150 . V_153 =
V_149 . V_153 ;
V_150 . V_154 =
F_67 ( V_149 . V_154 ) ;
V_150 . V_155 =
V_149 . V_155 ;
V_150 . V_156 =
F_67 ( V_149 . V_156 ) ;
V_150 . V_157 =
V_149 . V_157 ;
V_150 . V_158 =
F_67 ( V_149 . V_158 ) ;
V_150 . V_159 = V_149 . V_159 ;
V_150 . V_160 =
F_67 ( V_149 . V_160 ) ;
V_150 . V_161 = V_149 . V_161 ;
V_150 . V_81 = V_149 . V_81 ;
do {
V_33 = F_50 ( & V_150 ) ;
} while ( V_33 == - V_58 );
V_149 . V_157 = V_150 . V_157 ;
V_149 . V_159 = V_150 . V_159 ;
V_149 . V_81 = V_150 . V_81 ;
if ( F_63 ( V_148 , & V_149 , sizeof( V_149 ) ) )
return - V_70 ;
return V_33 ;
}
static long F_70 ( struct V_42 * V_43 , unsigned int V_105 ,
unsigned long V_90 )
{
if ( V_105 == V_106 )
return F_66 ( V_43 , V_105 , V_90 ) ;
if ( V_105 == V_108 )
return F_68 ( V_43 , V_105 , V_90 ) ;
if ( V_105 == V_110 )
return F_69 ( V_43 , V_105 , V_90 ) ;
return F_64 ( V_43 , V_105 , V_90 ) ;
}
static void F_71 ( struct V_162 * V_163 , unsigned char * V_164 , unsigned int V_69 )
{
int V_165 ;
for ( V_165 = 0 ; V_165 < V_69 ; V_165 ++ )
F_72 ( V_163 , L_3 , ( unsigned int ) V_164 [ V_165 ] ) ;
F_73 ( V_163 , ' ' ) ;
}
static void F_74 ( struct V_162 * V_163 , unsigned char * V_164 , unsigned int V_69 )
{
int V_166 , V_167 , V_168 ;
F_72 ( V_163 , L_4 ) ;
V_166 = 0 ;
for ( V_167 = 0 ; V_167 < ( V_69 / 16 ) ; V_167 ++ ) {
F_71 ( V_163 , V_164 + V_166 , 16 ) ;
V_166 += 16 ;
}
V_168 = V_69 % 16 ;
if ( V_168 ) {
F_71 ( V_163 , V_164 + V_166 , V_168 ) ;
V_166 += V_168 ;
}
F_73 ( V_163 , '\n' ) ;
}
static void F_75 ( unsigned char * V_169 , struct V_162 * V_163 ,
unsigned char * V_164 , unsigned int V_69 )
{
int V_166 , V_170 , V_171 ;
F_72 ( V_163 , L_5 , V_169 ) ;
V_166 = 0 ;
for ( V_170 = 0 ; V_170 < ( V_69 / 64 ) ; V_170 ++ ) {
F_74 ( V_163 , V_164 + V_166 , 64 ) ;
V_166 += 64 ;
}
V_171 = V_69 % 64 ;
if ( V_171 ) {
F_74 ( V_163 , V_164 + V_166 , V_171 ) ;
V_166 += V_171 ;
}
F_73 ( V_163 , '\n' ) ;
}
static void F_76 ( unsigned char * V_169 , struct V_162 * V_163 ,
unsigned int * V_172 , unsigned int V_69 )
{
int V_170 ;
F_72 ( V_163 , L_5 , V_169 ) ;
for ( V_170 = 0 ; V_170 < V_69 ; V_170 ++ ) {
if ( ( V_170 % 8 ) == 0 )
F_72 ( V_163 , L_6 ) ;
F_72 ( V_163 , L_7 , V_172 [ V_170 ] ) ;
if ( ( V_170 % 8 ) == 7 )
F_73 ( V_163 , '\n' ) ;
}
F_73 ( V_163 , '\n' ) ;
}
static int F_77 ( struct V_162 * V_163 , void * V_173 )
{
char V_174 [ sizeof( int ) * V_82 ] ;
F_72 ( V_163 , L_8 ,
V_175 , V_176 , V_177 ) ;
F_72 ( V_163 , L_9 , V_104 ) ;
F_72 ( V_163 , L_10 , V_38 ) ;
F_72 ( V_163 , L_11 , F_60 ( V_97 ) ) ;
F_72 ( V_163 , L_12 , F_60 ( V_99 ) ) ;
F_72 ( V_163 , L_13 ,
F_60 ( V_124 ) ) ;
F_72 ( V_163 , L_14 ,
F_60 ( V_126 ) ) ;
F_72 ( V_163 , L_15 , F_60 ( V_129 ) ) ;
F_72 ( V_163 , L_16 , F_60 ( V_131 ) ) ;
F_72 ( V_163 , L_17 , F_60 ( V_178 ) ) ;
F_72 ( V_163 , L_18 , F_60 ( V_179 ) ) ;
F_72 ( V_163 , L_19 , F_59 () ) ;
F_72 ( V_163 , L_20 , F_58 () ) ;
F_72 ( V_163 , L_21 ,
F_62 ( & V_47 ) ) ;
F_53 ( V_174 ) ;
F_75 ( L_22
L_23 ,
V_163 , V_174 , V_82 ) ;
F_54 ( V_174 ) ;
F_75 ( L_24 , V_163 , V_174 , V_82 ) ;
F_57 ( ( int * ) V_174 ) ;
F_76 ( L_25 ,
V_163 , ( unsigned int * ) V_174 , V_82 ) ;
return 0 ;
}
static int F_78 ( struct V_46 * V_46 , struct V_42 * V_42 )
{
return F_79 ( V_42 , F_77 , NULL ) ;
}
static void F_80 ( int V_180 )
{
struct V_6 * V_7 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list)
if ( F_51 ( V_7 -> V_14 -> V_79 ) == V_180 ) {
V_7 -> V_11 = 0 ;
F_5 ( V_7 -> V_14 ) ;
break;
}
F_30 ( & V_37 ) ;
}
static void F_81 ( int V_180 )
{
struct V_6 * V_7 ;
F_28 ( & V_37 ) ;
F_45 (zdev, &zcrypt_device_list, list)
if ( F_51 ( V_7 -> V_14 -> V_79 ) == V_180 ) {
V_7 -> V_11 = 1 ;
break;
}
F_30 ( & V_37 ) ;
}
static T_1 F_82 ( struct V_42 * V_42 , const char T_3 * V_80 ,
T_2 V_12 , T_4 * V_181 )
{
unsigned char * V_182 , * V_183 ;
T_2 V_184 ;
int V_185 ;
if ( V_12 <= 0 )
return 0 ;
#define F_83 1200UL
V_182 = F_20 ( F_83 , V_27 ) ;
if ( ! V_182 )
return 0 ;
V_184 = F_84 ( F_83 - 1 , V_12 ) ;
if ( F_49 ( V_182 , V_80 , V_184 ) != 0 ) {
F_23 ( V_182 ) ;
return - V_70 ;
}
V_182 [ V_184 ] = '\0' ;
V_183 = strstr ( V_182 , L_26 ) ;
if ( ! V_183 )
goto V_36;
V_183 = strstr ( V_183 , L_27 ) ;
if ( ! V_183 )
goto V_36;
V_183 ++ ;
if ( strstr ( V_183 , L_24 ) == NULL )
goto V_36;
for ( V_185 = 0 ; V_185 < 64 && * V_183 ; V_183 ++ ) {
if ( * V_183 >= '0' && * V_183 <= '8' )
V_185 ++ ;
else if ( * V_183 == 'd' || * V_183 == 'D' )
F_80 ( V_185 ++ ) ;
else if ( * V_183 == 'e' || * V_183 == 'E' )
F_81 ( V_185 ++ ) ;
else if ( * V_183 != ' ' && * V_183 != '\t' )
break;
}
V_36:
F_23 ( V_182 ) ;
return V_12 ;
}
static int F_85 ( struct V_186 * V_40 , T_5 * V_187 )
{
int V_33 ;
if ( V_188 == 0 ) {
V_33 = F_52 ( ( char * ) V_189 ) ;
if ( V_33 < 0 )
return - V_190 ;
V_188 = V_33 / sizeof *V_187 ;
}
* V_187 = V_189 [ -- V_188 ] ;
return sizeof *V_187 ;
}
static int F_31 ( void )
{
int V_33 = 0 ;
F_86 ( & V_191 ) ;
if ( V_192 == 0 ) {
V_189 = ( T_5 * ) F_87 ( V_27 ) ;
if ( ! V_189 ) {
V_33 = - V_94 ;
goto V_36;
}
V_188 = 0 ;
V_33 = F_88 ( & V_193 ) ;
if ( V_33 )
goto V_30;
V_192 = 1 ;
} else
V_192 ++ ;
F_89 ( & V_191 ) ;
return 0 ;
V_30:
F_90 ( ( unsigned long ) V_189 ) ;
V_36:
F_89 ( & V_191 ) ;
return V_33 ;
}
static void F_36 ( void )
{
F_86 ( & V_191 ) ;
V_192 -- ;
if ( V_192 == 0 ) {
F_91 ( & V_193 ) ;
F_90 ( ( unsigned long ) V_189 ) ;
}
F_89 ( & V_191 ) ;
}
int T_6 F_92 ( void )
{
int V_33 ;
V_33 = F_93 ( & V_194 ) ;
if ( V_33 < 0 )
goto V_36;
V_195 = F_94 ( L_28 , 0644 , NULL , & V_196 ) ;
if ( ! V_195 ) {
V_33 = - V_94 ;
goto V_197;
}
return 0 ;
V_197:
F_95 ( & V_194 ) ;
V_36:
return V_33 ;
}
void F_96 ( void )
{
F_97 ( L_28 , NULL ) ;
F_95 ( & V_194 ) ;
}
