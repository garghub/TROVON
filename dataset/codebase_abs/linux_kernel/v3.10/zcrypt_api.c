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
F_5 ( V_14 , V_7 , L_3 , V_7 -> V_15 -> V_16 ,
V_7 -> V_11 ) ;
if ( ! V_11 )
F_6 ( V_7 -> V_15 ) ;
return V_12 ;
}
static inline int F_7 ( void )
{
if ( F_8 ( & V_17 ) ) {
F_9 ( & V_17 , 0 ) ;
F_10 ( & V_18 ) ;
F_11 () ;
F_12 ( V_14 , L_4 ,
F_13 ( & V_18 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_6 * V_19 ;
struct V_20 * V_21 ;
if ( V_7 -> V_22 == 0 )
return;
for ( V_21 = V_7 -> V_23 . V_24 ; V_21 != & V_25 ; V_21 = V_21 -> V_24 ) {
V_19 = F_15 ( V_21 , struct V_6 , V_23 ) ;
if ( ( V_19 -> V_26 + 1 ) * V_19 -> V_22 <=
( V_7 -> V_26 + 1 ) * V_7 -> V_22 &&
V_19 -> V_22 != 0 )
break;
}
if ( V_21 == V_7 -> V_23 . V_24 )
return;
F_16 ( & V_7 -> V_23 , V_21 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_6 * V_19 ;
struct V_20 * V_21 ;
if ( V_7 -> V_22 == 0 )
return;
for ( V_21 = V_7 -> V_23 . V_27 ; V_21 != & V_25 ; V_21 = V_21 -> V_27 ) {
V_19 = F_15 ( V_21 , struct V_6 , V_23 ) ;
if ( ( V_19 -> V_26 + 1 ) * V_19 -> V_22 >
( V_7 -> V_26 + 1 ) * V_7 -> V_22 ||
V_19 -> V_22 == 0 )
break;
}
if ( V_21 == V_7 -> V_23 . V_27 )
return;
F_18 ( & V_7 -> V_23 , V_21 ) ;
}
static void F_19 ( struct V_28 * V_28 )
{
struct V_6 * V_7 =
F_20 ( V_28 , struct V_6 , V_29 ) ;
F_21 ( V_7 ) ;
}
void F_22 ( struct V_6 * V_7 )
{
F_23 ( & V_7 -> V_29 ) ;
}
int F_24 ( struct V_6 * V_7 )
{
return F_25 ( & V_7 -> V_29 , F_19 ) ;
}
struct V_6 * F_26 ( T_2 V_30 )
{
struct V_6 * V_7 ;
V_7 = F_27 ( sizeof( struct V_6 ) , V_31 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_32 . V_33 = F_28 ( V_30 , V_31 ) ;
if ( ! V_7 -> V_32 . V_33 )
goto V_34;
V_7 -> V_32 . V_35 = V_30 ;
F_29 ( & V_7 -> V_36 ) ;
F_30 ( & V_7 -> V_23 ) ;
V_7 -> V_37 = V_38 ;
return V_7 ;
V_34:
F_31 ( V_7 ) ;
return NULL ;
}
void F_21 ( struct V_6 * V_7 )
{
F_31 ( V_7 -> V_32 . V_33 ) ;
F_31 ( V_7 ) ;
}
int F_32 ( struct V_6 * V_7 )
{
int V_39 ;
if ( ! V_7 -> V_40 )
return - V_41 ;
V_39 = F_33 ( & V_7 -> V_15 -> V_1 . V_42 ,
& V_43 ) ;
if ( V_39 )
goto V_44;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
F_35 ( & V_7 -> V_29 ) ;
F_36 ( & V_45 ) ;
V_7 -> V_11 = 1 ;
F_5 ( V_14 , V_7 , L_5 , V_7 -> V_15 -> V_16 ,
V_7 -> V_11 ) ;
F_37 ( & V_7 -> V_23 , & V_25 ) ;
F_14 ( V_7 ) ;
V_46 ++ ;
F_38 ( & V_45 ) ;
if ( V_7 -> V_40 -> V_47 ) {
V_39 = F_39 () ;
if ( V_39 )
goto V_48;
}
return 0 ;
V_48:
F_36 ( & V_45 ) ;
V_46 -- ;
F_40 ( & V_7 -> V_23 ) ;
F_38 ( & V_45 ) ;
F_41 ( & V_7 -> V_15 -> V_1 . V_42 ,
& V_43 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
V_44:
return V_39 ;
}
void F_43 ( struct V_6 * V_7 )
{
if ( V_7 -> V_40 -> V_47 )
F_44 () ;
F_36 ( & V_45 ) ;
V_46 -- ;
F_40 ( & V_7 -> V_23 ) ;
F_38 ( & V_45 ) ;
F_41 ( & V_7 -> V_15 -> V_1 . V_42 ,
& V_43 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
}
void F_45 ( struct V_49 * V_50 )
{
if ( V_50 -> V_51 ) {
F_36 ( & V_52 ) ;
F_37 ( & V_50 -> V_23 , & V_53 ) ;
F_38 ( & V_52 ) ;
}
}
void F_46 ( struct V_49 * V_50 )
{
F_36 ( & V_52 ) ;
F_40 ( & V_50 -> V_23 ) ;
F_38 ( & V_52 ) ;
}
static inline
struct V_49 * F_47 ( unsigned char * V_54 , int V_55 )
{
struct V_49 * V_50 ;
int V_56 = 0 ;
F_36 ( & V_52 ) ;
F_48 (zops, &zcrypt_ops_list, list) {
if ( ( V_50 -> V_55 == V_55 ) &&
( ! strncmp ( V_50 -> V_51 -> V_54 , V_54 , V_57 ) ) ) {
V_56 = 1 ;
break;
}
}
F_38 ( & V_52 ) ;
if ( ! V_56 )
return NULL ;
return V_50 ;
}
struct V_49 * F_49 ( unsigned char * V_54 , int V_55 )
{
struct V_49 * V_50 = NULL ;
V_50 = F_47 ( V_54 , V_55 ) ;
if ( ! V_50 ) {
F_50 ( V_54 ) ;
V_50 = F_47 ( V_54 , V_55 ) ;
}
if ( ( ! V_50 ) || ( ! F_51 ( V_50 -> V_51 ) ) )
return NULL ;
return V_50 ;
}
void F_52 ( struct V_49 * V_50 )
{
if ( V_50 )
F_53 ( V_50 -> V_51 ) ;
}
static T_1 F_54 ( struct V_58 * V_59 , char T_3 * V_5 ,
T_2 V_12 , T_4 * V_60 )
{
return - V_61 ;
}
static T_1 F_55 ( struct V_58 * V_59 , const char T_3 * V_5 ,
T_2 V_12 , T_4 * V_60 )
{
return - V_61 ;
}
static int F_56 ( struct V_62 * V_62 , struct V_58 * V_59 )
{
F_10 ( & V_63 ) ;
return F_57 ( V_62 , V_59 ) ;
}
static int F_58 ( struct V_62 * V_62 , struct V_58 * V_59 )
{
F_59 ( & V_63 ) ;
return 0 ;
}
static long F_60 ( struct V_64 * V_65 )
{
struct V_6 * V_7 ;
int V_39 ;
if ( V_65 -> V_66 < V_65 -> V_67 )
return - V_13 ;
V_65 -> V_66 = V_65 -> V_67 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_40 -> V_68 ||
V_7 -> V_69 > V_65 -> V_67 ||
V_7 -> V_70 < V_65 -> V_67 )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_51 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_68 ( V_7 , V_65 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ;
}
else
V_39 = - V_73 ;
V_7 -> V_26 -- ;
F_14 ( V_7 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
F_38 ( & V_45 ) ;
return V_39 ;
}
F_38 ( & V_45 ) ;
return - V_41 ;
}
static long F_61 ( struct V_74 * V_75 )
{
struct V_6 * V_7 ;
unsigned long long V_76 , V_77 , V_78 ;
int V_39 , V_79 ;
if ( V_75 -> V_66 < V_75 -> V_67 ||
( V_75 -> V_67 & 1 ) )
return - V_13 ;
V_75 -> V_66 = V_75 -> V_67 ;
V_79 = 0 ;
V_80:
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_40 -> V_81 ||
V_7 -> V_69 > V_75 -> V_67 ||
V_7 -> V_70 < V_75 -> V_67 )
continue;
if ( V_7 -> V_82 && V_75 -> V_67 > 240 ) {
if ( V_79 == 0 ) {
unsigned int V_83 ;
F_38 ( & V_45 ) ;
if ( V_75 -> V_67 <= 256 )
V_83 = V_75 -> V_67 / 2 - 120 ;
else
V_83 = 8 ;
if ( V_83 > sizeof( V_76 ) )
return - V_84 ;
V_76 = V_77 = V_78 = 0 ;
if ( F_62 ( & V_76 , V_75 -> V_85 , V_83 ) ||
F_62 ( & V_77 , V_75 -> V_86 , V_83 ) ||
F_62 ( & V_78 , V_75 -> V_87 , V_83 ) )
return - V_84 ;
V_76 = V_77 = V_78 = 0 ;
V_79 = 1 ;
goto V_80;
}
if ( V_76 != 0ULL || V_77 != 0ULL || V_78 != 0ULL )
continue;
}
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_51 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_81 ( V_7 , V_75 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ;
}
else
V_39 = - V_73 ;
V_7 -> V_26 -- ;
F_14 ( V_7 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
F_38 ( & V_45 ) ;
return V_39 ;
}
F_38 ( & V_45 ) ;
return - V_41 ;
}
static long F_63 ( struct V_88 * V_89 )
{
struct V_6 * V_7 ;
int V_39 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 || ! V_7 -> V_40 -> V_90 ||
( V_89 -> V_91 != V_92 &&
F_64 ( V_7 -> V_15 -> V_16 ) != V_89 -> V_91 )
)
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_51 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_90 ( V_7 , V_89 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ;
}
else
V_39 = - V_73 ;
V_7 -> V_26 -- ;
F_14 ( V_7 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
F_38 ( & V_45 ) ;
return V_39 ;
}
F_38 ( & V_45 ) ;
return - V_41 ;
}
static long F_65 ( char * V_93 )
{
struct V_6 * V_7 ;
int V_39 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 || ! V_7 -> V_40 -> V_47 )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_51 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_47 ( V_7 , V_93 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ;
} else
V_39 = - V_73 ;
V_7 -> V_26 -- ;
F_14 ( V_7 ) ;
F_42 ( & V_7 -> V_15 -> V_1 ) ;
F_24 ( V_7 ) ;
F_38 ( & V_45 ) ;
return V_39 ;
}
F_38 ( & V_45 ) ;
return - V_41 ;
}
static void F_66 ( char V_94 [ V_95 ] )
{
struct V_6 * V_7 ;
memset ( V_94 , 0 , sizeof( char ) * V_95 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
V_94 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_11 ? V_7 -> V_96 : 0x0d ;
F_38 ( & V_45 ) ;
}
static void F_67 ( char V_97 [ V_95 ] )
{
struct V_6 * V_7 ;
memset ( V_97 , 0 , sizeof( char ) * V_95 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_68 ( & V_7 -> V_15 -> V_36 ) ;
V_97 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_98 +
V_7 -> V_15 -> V_99 ;
F_69 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static void F_70 ( int V_100 [ V_95 ] )
{
struct V_6 * V_7 ;
memset ( V_100 , 0 , sizeof( int ) * V_95 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_68 ( & V_7 -> V_15 -> V_36 ) ;
V_100 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_101 ;
F_69 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static int F_71 ( void )
{
struct V_6 * V_7 ;
int V_98 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_68 ( & V_7 -> V_15 -> V_36 ) ;
V_98 += V_7 -> V_15 -> V_98 ;
F_69 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
return V_98 ;
}
static int F_72 ( void )
{
struct V_6 * V_7 ;
int V_99 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_68 ( & V_7 -> V_15 -> V_36 ) ;
V_99 += V_7 -> V_15 -> V_99 ;
F_69 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
return V_99 ;
}
static int F_73 ( int type )
{
struct V_6 * V_7 ;
int V_102 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( V_7 -> V_96 == type )
V_102 ++ ;
F_38 ( & V_45 ) ;
return V_102 ;
}
static long F_74 ( struct V_58 * V_59 , unsigned long V_103 )
{
struct V_104 * V_105 ;
int V_106 ;
V_105 = F_27 ( sizeof( * V_105 ) , V_31 ) ;
if ( ! V_105 )
return - V_107 ;
V_105 -> V_108 = V_46 ;
V_105 -> V_109 = F_73 ( V_110 ) ;
V_105 -> V_111 = F_73 ( V_112 ) ;
V_105 -> V_113 = F_72 () ;
V_105 -> V_114 = F_71 () ;
V_105 -> V_115 = F_8 ( & V_63 ) ;
V_105 -> V_116 = V_117 ;
F_66 ( V_105 -> V_94 ) ;
F_67 ( V_105 -> V_97 ) ;
V_106 = 0 ;
if ( F_75 ( ( void T_3 * ) V_103 , V_105 , sizeof( * V_105 ) ) )
V_106 = - V_84 ;
F_31 ( V_105 ) ;
return V_106 ;
}
static long F_76 ( struct V_58 * V_59 , unsigned int V_118 ,
unsigned long V_103 )
{
int V_39 ;
switch ( V_118 ) {
case V_119 : {
struct V_64 T_3 * V_120 = ( void T_3 * ) V_103 ;
struct V_64 V_65 ;
if ( F_62 ( & V_65 , V_120 , sizeof( V_65 ) ) )
return - V_84 ;
do {
V_39 = F_60 ( & V_65 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_60 ( & V_65 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_77 ( V_65 . V_66 , & V_120 -> V_66 ) ;
}
case V_121 : {
struct V_74 T_3 * V_122 = ( void T_3 * ) V_103 ;
struct V_74 V_75 ;
if ( F_62 ( & V_75 , V_122 , sizeof( V_75 ) ) )
return - V_84 ;
do {
V_39 = F_61 ( & V_75 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_61 ( & V_75 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_77 ( V_75 . V_66 , & V_122 -> V_66 ) ;
}
case V_123 : {
struct V_88 T_3 * V_124 = ( void T_3 * ) V_103 ;
struct V_88 V_89 ;
if ( F_62 ( & V_89 , V_124 , sizeof( V_89 ) ) )
return - V_84 ;
do {
V_39 = F_63 ( & V_89 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_89 ) ;
} while ( V_39 == - V_73 );
if ( F_75 ( V_124 , & V_89 , sizeof( V_89 ) ) )
return - V_84 ;
return V_39 ;
}
case V_125 : {
char V_94 [ V_95 ] ;
F_66 ( V_94 ) ;
if ( F_75 ( ( char T_3 * ) V_103 , V_94 ,
sizeof( char ) * V_95 ) )
return - V_84 ;
return 0 ;
}
case V_126 : {
char V_97 [ V_95 ] ;
F_67 ( V_97 ) ;
if ( F_75 ( ( char T_3 * ) V_103 , V_97 ,
sizeof( char ) * V_95 ) )
return - V_84 ;
return 0 ;
}
case V_127 : {
int V_100 [ V_95 ] ;
F_70 ( V_100 ) ;
if ( F_75 ( ( int T_3 * ) V_103 , V_100 ,
sizeof( int ) * V_95 ) )
return - V_84 ;
return 0 ;
}
case V_128 :
return F_77 ( F_72 () , ( int T_3 * ) V_103 ) ;
case V_129 :
return F_77 ( F_71 () , ( int T_3 * ) V_103 ) ;
case V_130 :
return F_77 ( F_8 ( & V_63 ) ,
( int T_3 * ) V_103 ) ;
case V_131 :
return F_77 ( V_117 , ( int T_3 * ) V_103 ) ;
case V_132 :
return F_74 ( V_59 , V_103 ) ;
case V_133 :
return F_77 ( V_46 , ( int T_3 * ) V_103 ) ;
case V_134 :
return F_77 ( F_73 ( V_110 ) ,
( int T_3 * ) V_103 ) ;
case V_135 :
return F_77 ( F_73 ( V_112 ) ,
( int T_3 * ) V_103 ) ;
case V_136 :
return F_77 ( F_73 ( V_137 ) ,
( int T_3 * ) V_103 ) ;
case V_138 :
return F_77 ( F_73 ( V_139 ) ,
( int T_3 * ) V_103 ) ;
case V_140 :
return F_77 ( F_73 ( V_137 ) +
F_73 ( V_139 ) ,
( int T_3 * ) V_103 ) ;
case V_141 :
return F_77 ( F_73 ( V_142 ) ,
( int T_3 * ) V_103 ) ;
case V_143 :
return F_77 ( F_73 ( V_144 ) ,
( int T_3 * ) V_103 ) ;
default:
return - V_145 ;
}
}
static long F_78 ( struct V_58 * V_59 , unsigned int V_118 ,
unsigned long V_103 )
{
struct V_146 T_3 * V_147 = F_79 ( V_103 ) ;
struct V_146 V_148 ;
struct V_64 V_149 ;
long V_39 ;
if ( F_62 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_84 ;
V_149 . V_150 = F_79 ( V_148 . V_150 ) ;
V_149 . V_67 = V_148 . V_67 ;
V_149 . V_151 = F_79 ( V_148 . V_151 ) ;
V_149 . V_66 = V_148 . V_66 ;
V_149 . V_152 = F_79 ( V_148 . V_152 ) ;
V_149 . V_153 = F_79 ( V_148 . V_153 ) ;
do {
V_39 = F_60 ( & V_149 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_60 ( & V_149 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_77 ( V_149 . V_66 ,
& V_147 -> V_66 ) ;
}
static long F_80 ( struct V_58 * V_59 , unsigned int V_118 ,
unsigned long V_103 )
{
struct V_154 T_3 * V_155 = F_79 ( V_103 ) ;
struct V_154 V_156 ;
struct V_74 V_157 ;
long V_39 ;
if ( F_62 ( & V_156 , V_155 , sizeof( V_156 ) ) )
return - V_84 ;
V_157 . V_150 = F_79 ( V_156 . V_150 ) ;
V_157 . V_67 = V_156 . V_67 ;
V_157 . V_151 = F_79 ( V_156 . V_151 ) ;
V_157 . V_66 = V_156 . V_66 ;
V_157 . V_86 = F_79 ( V_156 . V_86 ) ;
V_157 . V_158 = F_79 ( V_156 . V_158 ) ;
V_157 . V_85 = F_79 ( V_156 . V_85 ) ;
V_157 . V_159 = F_79 ( V_156 . V_159 ) ;
V_157 . V_87 = F_79 ( V_156 . V_87 ) ;
do {
V_39 = F_61 ( & V_157 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_61 ( & V_157 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_77 ( V_157 . V_66 ,
& V_155 -> V_66 ) ;
}
static long F_81 ( struct V_58 * V_59 , unsigned int V_118 ,
unsigned long V_103 )
{
struct V_160 T_3 * V_161 = F_79 ( V_103 ) ;
struct V_160 V_162 ;
struct V_88 V_163 ;
long V_39 ;
if ( F_62 ( & V_162 , V_161 , sizeof( V_162 ) ) )
return - V_84 ;
V_163 . V_164 = V_162 . V_164 ;
V_163 . V_91 = V_162 . V_91 ;
V_163 . V_165 = V_162 . V_165 ;
V_163 . V_166 =
V_162 . V_166 ;
V_163 . V_167 =
F_79 ( V_162 . V_167 ) ;
V_163 . V_168 =
V_162 . V_168 ;
V_163 . V_169 =
F_79 ( V_162 . V_169 ) ;
V_163 . V_170 =
V_162 . V_170 ;
V_163 . V_171 =
F_79 ( V_162 . V_171 ) ;
V_163 . V_172 = V_162 . V_172 ;
V_163 . V_173 =
F_79 ( V_162 . V_173 ) ;
V_163 . V_174 = V_162 . V_174 ;
V_163 . V_94 = V_162 . V_94 ;
do {
V_39 = F_63 ( & V_163 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_163 ) ;
} while ( V_39 == - V_73 );
V_162 . V_170 = V_163 . V_170 ;
V_162 . V_172 = V_163 . V_172 ;
V_162 . V_94 = V_163 . V_94 ;
if ( F_75 ( V_161 , & V_162 , sizeof( V_162 ) ) )
return - V_84 ;
return V_39 ;
}
static long F_82 ( struct V_58 * V_59 , unsigned int V_118 ,
unsigned long V_103 )
{
if ( V_118 == V_119 )
return F_78 ( V_59 , V_118 , V_103 ) ;
if ( V_118 == V_121 )
return F_80 ( V_59 , V_118 , V_103 ) ;
if ( V_118 == V_123 )
return F_81 ( V_59 , V_118 , V_103 ) ;
return F_76 ( V_59 , V_118 , V_103 ) ;
}
static void F_83 ( struct V_175 * V_176 , unsigned char * V_177 , unsigned int V_83 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_83 ; V_178 ++ )
F_84 ( V_176 , L_6 , ( unsigned int ) V_177 [ V_178 ] ) ;
F_85 ( V_176 , ' ' ) ;
}
static void F_86 ( struct V_175 * V_176 , unsigned char * V_177 , unsigned int V_83 )
{
int V_179 , V_180 , V_181 ;
F_84 ( V_176 , L_7 ) ;
V_179 = 0 ;
for ( V_180 = 0 ; V_180 < ( V_83 / 16 ) ; V_180 ++ ) {
F_83 ( V_176 , V_177 + V_179 , 16 ) ;
V_179 += 16 ;
}
V_181 = V_83 % 16 ;
if ( V_181 ) {
F_83 ( V_176 , V_177 + V_179 , V_181 ) ;
V_179 += V_181 ;
}
F_85 ( V_176 , '\n' ) ;
}
static void F_87 ( unsigned char * V_182 , struct V_175 * V_176 ,
unsigned char * V_177 , unsigned int V_83 )
{
int V_179 , V_183 , V_184 ;
F_84 ( V_176 , L_8 , V_182 ) ;
V_179 = 0 ;
for ( V_183 = 0 ; V_183 < ( V_83 / 64 ) ; V_183 ++ ) {
F_86 ( V_176 , V_177 + V_179 , 64 ) ;
V_179 += 64 ;
}
V_184 = V_83 % 64 ;
if ( V_184 ) {
F_86 ( V_176 , V_177 + V_179 , V_184 ) ;
V_179 += V_184 ;
}
F_85 ( V_176 , '\n' ) ;
}
static void F_88 ( unsigned char * V_182 , struct V_175 * V_176 ,
unsigned int * V_185 , unsigned int V_83 )
{
int V_183 ;
F_84 ( V_176 , L_8 , V_182 ) ;
for ( V_183 = 0 ; V_183 < V_83 ; V_183 ++ ) {
if ( ( V_183 % 8 ) == 0 )
F_84 ( V_176 , L_9 ) ;
F_84 ( V_176 , L_10 , V_185 [ V_183 ] ) ;
if ( ( V_183 % 8 ) == 7 )
F_85 ( V_176 , '\n' ) ;
}
F_85 ( V_176 , '\n' ) ;
}
static int F_89 ( struct V_175 * V_176 , void * V_186 )
{
char V_187 [ sizeof( int ) * V_95 ] ;
F_84 ( V_176 , L_11 ,
V_188 , V_189 , V_190 ) ;
F_84 ( V_176 , L_12 , V_117 ) ;
F_84 ( V_176 , L_13 , V_46 ) ;
F_84 ( V_176 , L_14 , F_73 ( V_110 ) ) ;
F_84 ( V_176 , L_15 , F_73 ( V_112 ) ) ;
F_84 ( V_176 , L_16 ,
F_73 ( V_137 ) ) ;
F_84 ( V_176 , L_17 ,
F_73 ( V_139 ) ) ;
F_84 ( V_176 , L_18 , F_73 ( V_142 ) ) ;
F_84 ( V_176 , L_19 , F_73 ( V_144 ) ) ;
F_84 ( V_176 , L_20 , F_73 ( V_191 ) ) ;
F_84 ( V_176 , L_21 , F_73 ( V_192 ) ) ;
F_84 ( V_176 , L_22 , F_72 () ) ;
F_84 ( V_176 , L_23 , F_71 () ) ;
F_84 ( V_176 , L_24 ,
F_8 ( & V_63 ) ) ;
F_66 ( V_187 ) ;
F_87 ( L_25
L_26 ,
V_176 , V_187 , V_95 ) ;
F_67 ( V_187 ) ;
F_87 ( L_27 , V_176 , V_187 , V_95 ) ;
F_70 ( ( int * ) V_187 ) ;
F_88 ( L_28 ,
V_176 , ( unsigned int * ) V_187 , V_95 ) ;
return 0 ;
}
static int F_90 ( struct V_62 * V_62 , struct V_58 * V_58 )
{
return F_91 ( V_58 , F_89 , NULL ) ;
}
static void F_92 ( int V_193 )
{
struct V_6 * V_7 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( F_64 ( V_7 -> V_15 -> V_16 ) == V_193 ) {
V_7 -> V_11 = 0 ;
F_6 ( V_7 -> V_15 ) ;
break;
}
F_38 ( & V_45 ) ;
}
static void F_93 ( int V_193 )
{
struct V_6 * V_7 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( F_64 ( V_7 -> V_15 -> V_16 ) == V_193 ) {
V_7 -> V_11 = 1 ;
break;
}
F_38 ( & V_45 ) ;
}
static T_1 F_94 ( struct V_58 * V_58 , const char T_3 * V_93 ,
T_2 V_12 , T_4 * V_194 )
{
unsigned char * V_195 , * V_196 ;
T_2 V_197 ;
int V_198 ;
if ( V_12 <= 0 )
return 0 ;
#define F_95 1200UL
V_195 = F_28 ( F_95 , V_31 ) ;
if ( ! V_195 )
return 0 ;
V_197 = F_96 ( F_95 - 1 , V_12 ) ;
if ( F_62 ( V_195 , V_93 , V_197 ) != 0 ) {
F_31 ( V_195 ) ;
return - V_84 ;
}
V_195 [ V_197 ] = '\0' ;
V_196 = strstr ( V_195 , L_29 ) ;
if ( ! V_196 )
goto V_44;
V_196 = strstr ( V_196 , L_30 ) ;
if ( ! V_196 )
goto V_44;
V_196 ++ ;
if ( strstr ( V_196 , L_27 ) == NULL )
goto V_44;
for ( V_198 = 0 ; V_198 < 64 && * V_196 ; V_196 ++ ) {
if ( * V_196 >= '0' && * V_196 <= '8' )
V_198 ++ ;
else if ( * V_196 == 'd' || * V_196 == 'D' )
F_92 ( V_198 ++ ) ;
else if ( * V_196 == 'e' || * V_196 == 'E' )
F_93 ( V_198 ++ ) ;
else if ( * V_196 != ' ' && * V_196 != '\t' )
break;
}
V_44:
F_31 ( V_195 ) ;
return V_12 ;
}
static int F_97 ( struct V_199 * V_47 , T_5 * V_200 )
{
int V_39 ;
if ( V_201 == 0 ) {
V_39 = F_65 ( ( char * ) V_202 ) ;
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
V_39 = F_65 ( ( char * ) V_202 ) ;
if ( V_39 < 0 )
return - V_203 ;
V_201 = V_39 / sizeof *V_200 ;
}
* V_200 = V_202 [ -- V_201 ] ;
return sizeof *V_200 ;
}
static int F_39 ( void )
{
int V_39 = 0 ;
F_98 ( & V_204 ) ;
if ( V_205 == 0 ) {
V_202 = ( T_5 * ) F_99 ( V_31 ) ;
if ( ! V_202 ) {
V_39 = - V_107 ;
goto V_44;
}
V_201 = 0 ;
V_39 = F_100 ( & V_206 ) ;
if ( V_39 )
goto V_34;
V_205 = 1 ;
} else
V_205 ++ ;
F_101 ( & V_204 ) ;
return 0 ;
V_34:
F_102 ( ( unsigned long ) V_202 ) ;
V_44:
F_101 ( & V_204 ) ;
return V_39 ;
}
static void F_44 ( void )
{
F_98 ( & V_204 ) ;
V_205 -- ;
if ( V_205 == 0 ) {
F_103 ( & V_206 ) ;
F_102 ( ( unsigned long ) V_202 ) ;
}
F_101 ( & V_204 ) ;
}
int T_6 F_104 ( void )
{
V_207 = F_105 ( L_31 , NULL ) ;
V_208 = F_106 ( L_32 , 1 , 1 , 16 ) ;
F_107 ( V_208 , & V_209 ) ;
F_108 ( V_208 , V_210 ) ;
V_38 = F_106 ( L_33 , 1 , 1 , 16 ) ;
F_107 ( V_38 , & V_209 ) ;
F_108 ( V_38 , V_210 ) ;
return 0 ;
}
void F_109 ( void )
{
F_110 ( V_207 ) ;
if ( V_208 )
F_111 ( V_208 ) ;
if ( V_38 )
F_111 ( V_38 ) ;
}
int T_6 F_112 ( void )
{
int V_39 ;
V_39 = F_104 () ;
if ( V_39 )
goto V_44;
F_9 ( & V_17 , 0 ) ;
V_39 = F_113 ( & V_211 ) ;
if ( V_39 < 0 )
goto V_44;
V_212 = F_114 ( L_34 , 0644 , NULL , & V_213 ) ;
if ( ! V_212 ) {
V_39 = - V_107 ;
goto V_214;
}
return 0 ;
V_214:
F_115 ( & V_211 ) ;
V_44:
return V_39 ;
}
void F_116 ( void )
{
F_117 ( L_34 , NULL ) ;
F_115 ( & V_211 ) ;
F_109 () ;
}
