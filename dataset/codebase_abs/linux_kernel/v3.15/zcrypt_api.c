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
( V_7 -> V_40 -> V_55 == V_91 ) ||
( V_89 -> V_92 != V_93 &&
F_64 ( V_7 -> V_15 -> V_16 ) != V_89 -> V_92 ) )
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
static bool F_65 ( unsigned int V_94 ,
struct V_95 V_96 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_96 . V_98 ; V_97 ++ , V_96 . V_99 ++ ) {
if ( ( F_64 ( V_94 ) == V_96 . V_99 -> V_100 ) &&
( F_66 ( V_94 ) == V_96 . V_99 -> V_101 ) ) {
return true ;
}
}
return false ;
}
static long F_67 ( struct V_102 * V_103 )
{
struct V_6 * V_7 ;
bool V_104 = false ;
int V_39 ;
struct V_95 V_105 = {
. V_98 = 0x00 ,
. V_99 = NULL ,
} ;
V_105 . V_98 = ( unsigned short ) V_103 -> V_98 ;
if ( V_105 . V_98 == 0 )
V_104 = true ;
else {
V_105 . V_99 = F_68 ( ( unsigned short )
V_103 -> V_98 ,
sizeof( struct V_106 ) ,
V_31 ) ;
if ( ! V_105 . V_99 )
return - V_107 ;
if ( F_62 ( V_105 . V_99 ,
(struct V_106 V_108 T_3 * )
V_103 -> V_99 , V_103 -> V_98 *
sizeof( struct V_106 ) ) )
return - V_84 ;
}
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
V_7 -> V_40 -> V_55 != V_91 )
continue;
if ( ! F_65 ( V_7 -> V_15 -> V_16 , V_105 ) &&
! V_104 )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_51 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_109 ( V_7 , V_103 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_71 -> V_72 . V_51 ) ;
} else {
V_39 = - V_73 ;
}
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
static long F_69 ( char * V_110 )
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
V_39 = V_7 -> V_40 -> V_47 ( V_7 , V_110 ) ;
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
static void F_70 ( char V_111 [ V_112 ] )
{
struct V_6 * V_7 ;
memset ( V_111 , 0 , sizeof( char ) * V_112 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
V_111 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_11 ? V_7 -> V_113 : 0x0d ;
F_38 ( & V_45 ) ;
}
static void F_71 ( char V_114 [ V_112 ] )
{
struct V_6 * V_7 ;
memset ( V_114 , 0 , sizeof( char ) * V_112 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_114 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_115 +
V_7 -> V_15 -> V_116 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static void F_74 ( int V_117 [ V_112 ] )
{
struct V_6 * V_7 ;
memset ( V_117 , 0 , sizeof( int ) * V_112 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_117 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_118 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static int F_75 ( void )
{
struct V_6 * V_7 ;
int V_115 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_115 += V_7 -> V_15 -> V_115 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
return V_115 ;
}
static int F_76 ( void )
{
struct V_6 * V_7 ;
int V_116 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_116 += V_7 -> V_15 -> V_116 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
return V_116 ;
}
static int F_77 ( int type )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( V_7 -> V_113 == type )
V_119 ++ ;
F_38 ( & V_45 ) ;
return V_119 ;
}
static long F_78 ( struct V_58 * V_59 , unsigned long V_120 )
{
struct V_121 * V_122 ;
int V_123 ;
V_122 = F_27 ( sizeof( * V_122 ) , V_31 ) ;
if ( ! V_122 )
return - V_107 ;
V_122 -> V_124 = V_46 ;
V_122 -> V_125 = F_77 ( V_126 ) ;
V_122 -> V_127 = F_77 ( V_128 ) ;
V_122 -> V_129 = F_76 () ;
V_122 -> V_130 = F_75 () ;
V_122 -> V_131 = F_8 ( & V_63 ) ;
V_122 -> V_132 = V_133 ;
F_70 ( V_122 -> V_111 ) ;
F_71 ( V_122 -> V_114 ) ;
V_123 = 0 ;
if ( F_79 ( ( void T_3 * ) V_120 , V_122 , sizeof( * V_122 ) ) )
V_123 = - V_84 ;
F_31 ( V_122 ) ;
return V_123 ;
}
static long F_80 ( struct V_58 * V_59 , unsigned int V_134 ,
unsigned long V_120 )
{
int V_39 ;
switch ( V_134 ) {
case V_135 : {
struct V_64 T_3 * V_136 = ( void T_3 * ) V_120 ;
struct V_64 V_65 ;
if ( F_62 ( & V_65 , V_136 , sizeof( V_65 ) ) )
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
return F_81 ( V_65 . V_66 , & V_136 -> V_66 ) ;
}
case V_137 : {
struct V_74 T_3 * V_138 = ( void T_3 * ) V_120 ;
struct V_74 V_75 ;
if ( F_62 ( & V_75 , V_138 , sizeof( V_75 ) ) )
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
return F_81 ( V_75 . V_66 , & V_138 -> V_66 ) ;
}
case V_139 : {
struct V_88 T_3 * V_140 = ( void T_3 * ) V_120 ;
struct V_88 V_89 ;
if ( F_62 ( & V_89 , V_140 , sizeof( V_89 ) ) )
return - V_84 ;
do {
V_39 = F_63 ( & V_89 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_89 ) ;
} while ( V_39 == - V_73 );
if ( F_79 ( V_140 , & V_89 , sizeof( V_89 ) ) )
return - V_84 ;
return V_39 ;
}
case V_141 : {
struct V_102 T_3 * V_142 = ( void T_3 * ) V_120 ;
struct V_102 V_103 ;
if ( F_62 ( & V_103 , V_142 , sizeof( V_103 ) ) )
return - V_84 ;
do {
V_39 = F_67 ( & V_103 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_67 ( & V_103 ) ;
} while ( V_39 == - V_73 );
if ( F_79 ( V_142 , & V_103 , sizeof( V_103 ) ) )
return - V_84 ;
return V_39 ;
}
case V_143 : {
char V_111 [ V_112 ] ;
F_70 ( V_111 ) ;
if ( F_79 ( ( char T_3 * ) V_120 , V_111 ,
sizeof( char ) * V_112 ) )
return - V_84 ;
return 0 ;
}
case V_144 : {
char V_114 [ V_112 ] ;
F_71 ( V_114 ) ;
if ( F_79 ( ( char T_3 * ) V_120 , V_114 ,
sizeof( char ) * V_112 ) )
return - V_84 ;
return 0 ;
}
case V_145 : {
int V_117 [ V_112 ] ;
F_74 ( V_117 ) ;
if ( F_79 ( ( int T_3 * ) V_120 , V_117 ,
sizeof( int ) * V_112 ) )
return - V_84 ;
return 0 ;
}
case V_146 :
return F_81 ( F_76 () , ( int T_3 * ) V_120 ) ;
case V_147 :
return F_81 ( F_75 () , ( int T_3 * ) V_120 ) ;
case V_148 :
return F_81 ( F_8 ( & V_63 ) ,
( int T_3 * ) V_120 ) ;
case V_149 :
return F_81 ( V_133 , ( int T_3 * ) V_120 ) ;
case V_150 :
return F_78 ( V_59 , V_120 ) ;
case V_151 :
return F_81 ( V_46 , ( int T_3 * ) V_120 ) ;
case V_152 :
return F_81 ( F_77 ( V_126 ) ,
( int T_3 * ) V_120 ) ;
case V_153 :
return F_81 ( F_77 ( V_128 ) ,
( int T_3 * ) V_120 ) ;
case V_154 :
return F_81 ( F_77 ( V_155 ) ,
( int T_3 * ) V_120 ) ;
case V_156 :
return F_81 ( F_77 ( V_157 ) ,
( int T_3 * ) V_120 ) ;
case V_158 :
return F_81 ( F_77 ( V_155 ) +
F_77 ( V_157 ) ,
( int T_3 * ) V_120 ) ;
case V_159 :
return F_81 ( F_77 ( V_160 ) ,
( int T_3 * ) V_120 ) ;
case V_161 :
return F_81 ( F_77 ( V_162 ) ,
( int T_3 * ) V_120 ) ;
default:
return - V_163 ;
}
}
static long F_82 ( struct V_58 * V_59 , unsigned int V_134 ,
unsigned long V_120 )
{
struct V_164 T_3 * V_165 = F_83 ( V_120 ) ;
struct V_164 V_166 ;
struct V_64 V_167 ;
long V_39 ;
if ( F_62 ( & V_166 , V_165 , sizeof( V_166 ) ) )
return - V_84 ;
V_167 . V_168 = F_83 ( V_166 . V_168 ) ;
V_167 . V_67 = V_166 . V_67 ;
V_167 . V_169 = F_83 ( V_166 . V_169 ) ;
V_167 . V_66 = V_166 . V_66 ;
V_167 . V_170 = F_83 ( V_166 . V_170 ) ;
V_167 . V_171 = F_83 ( V_166 . V_171 ) ;
do {
V_39 = F_60 ( & V_167 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_60 ( & V_167 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_81 ( V_167 . V_66 ,
& V_165 -> V_66 ) ;
}
static long F_84 ( struct V_58 * V_59 , unsigned int V_134 ,
unsigned long V_120 )
{
struct V_172 T_3 * V_173 = F_83 ( V_120 ) ;
struct V_172 V_174 ;
struct V_74 V_175 ;
long V_39 ;
if ( F_62 ( & V_174 , V_173 , sizeof( V_174 ) ) )
return - V_84 ;
V_175 . V_168 = F_83 ( V_174 . V_168 ) ;
V_175 . V_67 = V_174 . V_67 ;
V_175 . V_169 = F_83 ( V_174 . V_169 ) ;
V_175 . V_66 = V_174 . V_66 ;
V_175 . V_86 = F_83 ( V_174 . V_86 ) ;
V_175 . V_176 = F_83 ( V_174 . V_176 ) ;
V_175 . V_85 = F_83 ( V_174 . V_85 ) ;
V_175 . V_177 = F_83 ( V_174 . V_177 ) ;
V_175 . V_87 = F_83 ( V_174 . V_87 ) ;
do {
V_39 = F_61 ( & V_175 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_61 ( & V_175 ) ;
} while ( V_39 == - V_73 );
if ( V_39 )
return V_39 ;
return F_81 ( V_175 . V_66 ,
& V_173 -> V_66 ) ;
}
static long F_85 ( struct V_58 * V_59 , unsigned int V_134 ,
unsigned long V_120 )
{
struct V_178 T_3 * V_179 = F_83 ( V_120 ) ;
struct V_178 V_180 ;
struct V_88 V_181 ;
long V_39 ;
if ( F_62 ( & V_180 , V_179 , sizeof( V_180 ) ) )
return - V_84 ;
V_181 . V_182 = V_180 . V_182 ;
V_181 . V_92 = V_180 . V_92 ;
V_181 . V_183 = V_180 . V_183 ;
V_181 . V_184 =
V_180 . V_184 ;
V_181 . V_185 =
F_83 ( V_180 . V_185 ) ;
V_181 . V_186 =
V_180 . V_186 ;
V_181 . V_187 =
F_83 ( V_180 . V_187 ) ;
V_181 . V_188 =
V_180 . V_188 ;
V_181 . V_189 =
F_83 ( V_180 . V_189 ) ;
V_181 . V_190 = V_180 . V_190 ;
V_181 . V_191 =
F_83 ( V_180 . V_191 ) ;
V_181 . V_192 = V_180 . V_192 ;
V_181 . V_111 = V_180 . V_111 ;
do {
V_39 = F_63 ( & V_181 ) ;
} while ( V_39 == - V_73 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_181 ) ;
} while ( V_39 == - V_73 );
V_180 . V_188 = V_181 . V_188 ;
V_180 . V_190 = V_181 . V_190 ;
V_180 . V_111 = V_181 . V_111 ;
if ( F_79 ( V_179 , & V_180 , sizeof( V_180 ) ) )
return - V_84 ;
return V_39 ;
}
static long F_86 ( struct V_58 * V_59 , unsigned int V_134 ,
unsigned long V_120 )
{
if ( V_134 == V_135 )
return F_82 ( V_59 , V_134 , V_120 ) ;
if ( V_134 == V_137 )
return F_84 ( V_59 , V_134 , V_120 ) ;
if ( V_134 == V_139 )
return F_85 ( V_59 , V_134 , V_120 ) ;
return F_80 ( V_59 , V_134 , V_120 ) ;
}
static void F_87 ( struct V_193 * V_194 , unsigned char * V_195 , unsigned int V_83 )
{
int V_196 ;
for ( V_196 = 0 ; V_196 < V_83 ; V_196 ++ )
F_88 ( V_194 , L_6 , ( unsigned int ) V_195 [ V_196 ] ) ;
F_89 ( V_194 , ' ' ) ;
}
static void F_90 ( struct V_193 * V_194 , unsigned char * V_195 , unsigned int V_83 )
{
int V_197 , V_198 , V_199 ;
F_88 ( V_194 , L_7 ) ;
V_197 = 0 ;
for ( V_198 = 0 ; V_198 < ( V_83 / 16 ) ; V_198 ++ ) {
F_87 ( V_194 , V_195 + V_197 , 16 ) ;
V_197 += 16 ;
}
V_199 = V_83 % 16 ;
if ( V_199 ) {
F_87 ( V_194 , V_195 + V_197 , V_199 ) ;
V_197 += V_199 ;
}
F_89 ( V_194 , '\n' ) ;
}
static void F_91 ( unsigned char * V_200 , struct V_193 * V_194 ,
unsigned char * V_195 , unsigned int V_83 )
{
int V_197 , V_201 , V_202 ;
F_88 ( V_194 , L_8 , V_200 ) ;
V_197 = 0 ;
for ( V_201 = 0 ; V_201 < ( V_83 / 64 ) ; V_201 ++ ) {
F_90 ( V_194 , V_195 + V_197 , 64 ) ;
V_197 += 64 ;
}
V_202 = V_83 % 64 ;
if ( V_202 ) {
F_90 ( V_194 , V_195 + V_197 , V_202 ) ;
V_197 += V_202 ;
}
F_89 ( V_194 , '\n' ) ;
}
static void F_92 ( unsigned char * V_200 , struct V_193 * V_194 ,
unsigned int * V_203 , unsigned int V_83 )
{
int V_201 ;
F_88 ( V_194 , L_8 , V_200 ) ;
for ( V_201 = 0 ; V_201 < V_83 ; V_201 ++ ) {
if ( ( V_201 % 8 ) == 0 )
F_88 ( V_194 , L_9 ) ;
F_88 ( V_194 , L_10 , V_203 [ V_201 ] ) ;
if ( ( V_201 % 8 ) == 7 )
F_89 ( V_194 , '\n' ) ;
}
F_89 ( V_194 , '\n' ) ;
}
static int F_93 ( struct V_193 * V_194 , void * V_204 )
{
char V_205 [ sizeof( int ) * V_112 ] ;
F_88 ( V_194 , L_11 ,
V_206 , V_207 , V_208 ) ;
F_88 ( V_194 , L_12 , V_133 ) ;
F_88 ( V_194 , L_13 , V_46 ) ;
F_88 ( V_194 , L_14 , F_77 ( V_126 ) ) ;
F_88 ( V_194 , L_15 , F_77 ( V_128 ) ) ;
F_88 ( V_194 , L_16 ,
F_77 ( V_155 ) ) ;
F_88 ( V_194 , L_17 ,
F_77 ( V_157 ) ) ;
F_88 ( V_194 , L_18 , F_77 ( V_160 ) ) ;
F_88 ( V_194 , L_19 , F_77 ( V_162 ) ) ;
F_88 ( V_194 , L_20 , F_77 ( V_209 ) ) ;
F_88 ( V_194 , L_21 , F_77 ( V_210 ) ) ;
F_88 ( V_194 , L_22 , F_76 () ) ;
F_88 ( V_194 , L_23 , F_75 () ) ;
F_88 ( V_194 , L_24 ,
F_8 ( & V_63 ) ) ;
F_70 ( V_205 ) ;
F_91 ( L_25
L_26 ,
V_194 , V_205 , V_112 ) ;
F_71 ( V_205 ) ;
F_91 ( L_27 , V_194 , V_205 , V_112 ) ;
F_74 ( ( int * ) V_205 ) ;
F_92 ( L_28 ,
V_194 , ( unsigned int * ) V_205 , V_112 ) ;
return 0 ;
}
static int F_94 ( struct V_62 * V_62 , struct V_58 * V_58 )
{
return F_95 ( V_58 , F_93 , NULL ) ;
}
static void F_96 ( int V_211 )
{
struct V_6 * V_7 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( F_64 ( V_7 -> V_15 -> V_16 ) == V_211 ) {
V_7 -> V_11 = 0 ;
F_6 ( V_7 -> V_15 ) ;
break;
}
F_38 ( & V_45 ) ;
}
static void F_97 ( int V_211 )
{
struct V_6 * V_7 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( F_64 ( V_7 -> V_15 -> V_16 ) == V_211 ) {
V_7 -> V_11 = 1 ;
break;
}
F_38 ( & V_45 ) ;
}
static T_1 F_98 ( struct V_58 * V_58 , const char T_3 * V_110 ,
T_2 V_12 , T_4 * V_212 )
{
unsigned char * V_213 , * V_214 ;
T_2 V_215 ;
int V_216 ;
if ( V_12 <= 0 )
return 0 ;
#define F_99 1200UL
V_213 = F_28 ( F_99 , V_31 ) ;
if ( ! V_213 )
return 0 ;
V_215 = F_100 ( F_99 - 1 , V_12 ) ;
if ( F_62 ( V_213 , V_110 , V_215 ) != 0 ) {
F_31 ( V_213 ) ;
return - V_84 ;
}
V_213 [ V_215 ] = '\0' ;
V_214 = strstr ( V_213 , L_29 ) ;
if ( ! V_214 )
goto V_44;
V_214 = strstr ( V_214 , L_30 ) ;
if ( ! V_214 )
goto V_44;
V_214 ++ ;
if ( strstr ( V_214 , L_27 ) == NULL )
goto V_44;
for ( V_216 = 0 ; V_216 < 64 && * V_214 ; V_214 ++ ) {
if ( * V_214 >= '0' && * V_214 <= '8' )
V_216 ++ ;
else if ( * V_214 == 'd' || * V_214 == 'D' )
F_96 ( V_216 ++ ) ;
else if ( * V_214 == 'e' || * V_214 == 'E' )
F_97 ( V_216 ++ ) ;
else if ( * V_214 != ' ' && * V_214 != '\t' )
break;
}
V_44:
F_31 ( V_213 ) ;
return V_12 ;
}
static int F_101 ( struct V_217 * V_47 , T_5 * V_218 )
{
int V_39 ;
if ( V_219 == 0 ) {
V_39 = F_69 ( ( char * ) V_220 ) ;
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
V_39 = F_69 ( ( char * ) V_220 ) ;
if ( V_39 < 0 )
return - V_221 ;
V_219 = V_39 / sizeof *V_218 ;
}
* V_218 = V_220 [ -- V_219 ] ;
return sizeof *V_218 ;
}
static int F_39 ( void )
{
int V_39 = 0 ;
F_102 ( & V_222 ) ;
if ( V_223 == 0 ) {
V_220 = ( T_5 * ) F_103 ( V_31 ) ;
if ( ! V_220 ) {
V_39 = - V_107 ;
goto V_44;
}
V_219 = 0 ;
V_39 = F_104 ( & V_224 ) ;
if ( V_39 )
goto V_34;
V_223 = 1 ;
} else
V_223 ++ ;
F_105 ( & V_222 ) ;
return 0 ;
V_34:
F_106 ( ( unsigned long ) V_220 ) ;
V_44:
F_105 ( & V_222 ) ;
return V_39 ;
}
static void F_44 ( void )
{
F_102 ( & V_222 ) ;
V_223 -- ;
if ( V_223 == 0 ) {
F_107 ( & V_224 ) ;
F_106 ( ( unsigned long ) V_220 ) ;
}
F_105 ( & V_222 ) ;
}
int T_6 F_108 ( void )
{
V_225 = F_109 ( L_31 , NULL ) ;
V_226 = F_110 ( L_32 , 1 , 1 , 16 ) ;
F_111 ( V_226 , & V_227 ) ;
F_112 ( V_226 , V_228 ) ;
V_38 = F_110 ( L_33 , 1 , 1 , 16 ) ;
F_111 ( V_38 , & V_227 ) ;
F_112 ( V_38 , V_228 ) ;
return 0 ;
}
void F_113 ( void )
{
F_114 ( V_225 ) ;
if ( V_226 )
F_115 ( V_226 ) ;
if ( V_38 )
F_115 ( V_38 ) ;
}
int T_6 F_116 ( void )
{
int V_39 ;
V_39 = F_108 () ;
if ( V_39 )
goto V_44;
F_9 ( & V_17 , 0 ) ;
V_39 = F_117 ( & V_229 ) ;
if ( V_39 < 0 )
goto V_44;
V_230 = F_118 ( L_34 , 0644 , NULL , & V_231 ) ;
if ( ! V_230 ) {
V_39 = - V_107 ;
goto V_232;
}
return 0 ;
V_232:
F_119 ( & V_229 ) ;
V_44:
return V_39 ;
}
void F_120 ( void )
{
F_121 ( L_34 , NULL ) ;
F_119 ( & V_229 ) ;
F_113 () ;
}
