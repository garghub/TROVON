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
F_36 ( & V_51 ) ;
F_37 ( & V_50 -> V_23 , & V_52 ) ;
F_38 ( & V_51 ) ;
}
void F_46 ( struct V_49 * V_50 )
{
F_36 ( & V_51 ) ;
F_40 ( & V_50 -> V_23 ) ;
F_38 ( & V_51 ) ;
}
static inline
struct V_49 * F_47 ( unsigned char * V_53 , int V_54 )
{
struct V_49 * V_50 ;
int V_55 = 0 ;
F_36 ( & V_51 ) ;
F_48 (zops, &zcrypt_ops_list, list) {
if ( ( V_50 -> V_54 == V_54 ) &&
( ! strncmp ( V_50 -> V_53 , V_53 , sizeof( V_50 -> V_53 ) ) ) ) {
V_55 = 1 ;
break;
}
}
if ( ! V_55 || ! F_49 ( V_50 -> V_56 ) )
V_50 = NULL ;
F_38 ( & V_51 ) ;
return V_50 ;
}
struct V_49 * F_50 ( unsigned char * V_53 , int V_54 )
{
struct V_49 * V_50 = NULL ;
V_50 = F_47 ( V_53 , V_54 ) ;
if ( ! V_50 ) {
F_51 ( L_6 , V_53 ) ;
V_50 = F_47 ( V_53 , V_54 ) ;
}
return V_50 ;
}
void F_52 ( struct V_49 * V_50 )
{
if ( V_50 )
F_53 ( V_50 -> V_56 ) ;
}
static T_1 F_54 ( struct V_57 * V_58 , char T_3 * V_5 ,
T_2 V_12 , T_4 * V_59 )
{
return - V_60 ;
}
static T_1 F_55 ( struct V_57 * V_58 , const char T_3 * V_5 ,
T_2 V_12 , T_4 * V_59 )
{
return - V_60 ;
}
static int F_56 ( struct V_61 * V_61 , struct V_57 * V_58 )
{
F_10 ( & V_62 ) ;
return F_57 ( V_61 , V_58 ) ;
}
static int F_58 ( struct V_61 * V_61 , struct V_57 * V_58 )
{
F_59 ( & V_62 ) ;
return 0 ;
}
static long F_60 ( struct V_63 * V_64 )
{
struct V_6 * V_7 ;
int V_39 ;
if ( V_64 -> V_65 < V_64 -> V_66 )
return - V_13 ;
V_64 -> V_65 = V_64 -> V_66 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_40 -> V_67 ||
V_7 -> V_68 > V_64 -> V_66 ||
V_7 -> V_69 < V_64 -> V_66 )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_49 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_67 ( V_7 , V_64 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ;
}
else
V_39 = - V_72 ;
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
static long F_61 ( struct V_73 * V_74 )
{
struct V_6 * V_7 ;
unsigned long long V_75 , V_76 , V_77 ;
int V_39 , V_78 ;
if ( V_74 -> V_65 < V_74 -> V_66 )
return - V_13 ;
V_74 -> V_65 = V_74 -> V_66 ;
V_78 = 0 ;
V_79:
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
! V_7 -> V_40 -> V_80 ||
V_7 -> V_68 > V_74 -> V_66 ||
V_7 -> V_69 < V_74 -> V_66 )
continue;
if ( V_7 -> V_81 && V_74 -> V_66 > 240 ) {
if ( V_78 == 0 ) {
unsigned int V_82 ;
F_38 ( & V_45 ) ;
if ( V_74 -> V_66 <= 256 )
V_82 = V_74 -> V_66 / 2 - 120 ;
else
V_82 = 8 ;
if ( V_82 > sizeof( V_75 ) )
return - V_83 ;
V_75 = V_76 = V_77 = 0 ;
if ( F_62 ( & V_75 , V_74 -> V_84 , V_82 ) ||
F_62 ( & V_76 , V_74 -> V_85 , V_82 ) ||
F_62 ( & V_77 , V_74 -> V_86 , V_82 ) )
return - V_83 ;
V_75 = V_76 = V_77 = 0 ;
V_78 = 1 ;
goto V_79;
}
if ( V_75 != 0ULL || V_76 != 0ULL || V_77 != 0ULL )
continue;
}
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_49 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_80 ( V_7 , V_74 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ;
}
else
V_39 = - V_72 ;
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
static long F_63 ( struct V_87 * V_88 )
{
struct V_6 * V_7 ;
int V_39 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 || ! V_7 -> V_40 -> V_89 ||
( V_7 -> V_40 -> V_54 == V_90 ) ||
( V_88 -> V_91 != V_92 &&
F_64 ( V_7 -> V_15 -> V_16 ) != V_88 -> V_91 ) )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_49 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_89 ( V_7 , V_88 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ;
}
else
V_39 = - V_72 ;
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
static bool F_65 ( unsigned int V_93 ,
struct V_94 V_95 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_95 . V_97 ; V_96 ++ , V_95 . V_98 ++ ) {
if ( ( F_64 ( V_93 ) == V_95 . V_98 -> V_99 ) &&
( F_66 ( V_93 ) == V_95 . V_98 -> V_100 ) ) {
return true ;
}
}
return false ;
}
static long F_67 ( struct V_101 * V_102 )
{
struct V_6 * V_7 ;
bool V_103 = false ;
int V_39 ;
struct V_94 V_104 = {
. V_97 = 0x00 ,
. V_98 = NULL ,
} ;
V_104 . V_97 = ( unsigned short ) V_102 -> V_97 ;
if ( V_104 . V_97 == 0 )
V_103 = true ;
else {
V_104 . V_98 = F_68 ( ( unsigned short )
V_102 -> V_97 ,
sizeof( struct V_105 ) ,
V_31 ) ;
if ( ! V_104 . V_98 )
return - V_106 ;
if ( F_62 ( V_104 . V_98 ,
(struct V_105 V_107 T_3 * )
V_102 -> V_98 , V_102 -> V_97 *
sizeof( struct V_105 ) ) )
return - V_83 ;
}
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
if ( ! V_7 -> V_11 ||
V_7 -> V_40 -> V_54 != V_90 )
continue;
if ( ! F_65 ( V_7 -> V_15 -> V_16 , V_104 ) &&
! V_103 )
continue;
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_15 -> V_1 ) ;
V_7 -> V_26 ++ ;
F_17 ( V_7 ) ;
if ( F_49 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_108 ( V_7 , V_102 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ;
} else {
V_39 = - V_72 ;
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
static long F_69 ( char * V_109 )
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
if ( F_49 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ) {
F_38 ( & V_45 ) ;
V_39 = V_7 -> V_40 -> V_47 ( V_7 , V_109 ) ;
F_36 ( & V_45 ) ;
F_53 ( V_7 -> V_15 -> V_70 -> V_71 . V_56 ) ;
} else
V_39 = - V_72 ;
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
static void F_70 ( char V_110 [ V_111 ] )
{
struct V_6 * V_7 ;
memset ( V_110 , 0 , sizeof( char ) * V_111 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
V_110 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_11 ? V_7 -> V_112 : 0x0d ;
F_38 ( & V_45 ) ;
}
static void F_71 ( char V_113 [ V_111 ] )
{
struct V_6 * V_7 ;
memset ( V_113 , 0 , sizeof( char ) * V_111 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_113 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_114 +
V_7 -> V_15 -> V_115 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static void F_74 ( int V_116 [ V_111 ] )
{
struct V_6 * V_7 ;
memset ( V_116 , 0 , sizeof( int ) * V_111 ) ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_116 [ F_64 ( V_7 -> V_15 -> V_16 ) ] =
V_7 -> V_15 -> V_117 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
}
static int F_75 ( void )
{
struct V_6 * V_7 ;
int V_114 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list) {
F_72 ( & V_7 -> V_15 -> V_36 ) ;
V_114 += V_7 -> V_15 -> V_114 ;
F_73 ( & V_7 -> V_15 -> V_36 ) ;
}
F_38 ( & V_45 ) ;
return V_114 ;
}
static int F_76 ( void )
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
static int F_77 ( int type )
{
struct V_6 * V_7 ;
int V_118 = 0 ;
F_36 ( & V_45 ) ;
F_48 (zdev, &zcrypt_device_list, list)
if ( V_7 -> V_112 == type )
V_118 ++ ;
F_38 ( & V_45 ) ;
return V_118 ;
}
static long F_78 ( struct V_57 * V_58 , unsigned long V_119 )
{
struct V_120 * V_121 ;
int V_122 ;
V_121 = F_27 ( sizeof( * V_121 ) , V_31 ) ;
if ( ! V_121 )
return - V_106 ;
V_121 -> V_123 = V_46 ;
V_121 -> V_124 = F_77 ( V_125 ) ;
V_121 -> V_126 = F_77 ( V_127 ) ;
V_121 -> V_128 = F_76 () ;
V_121 -> V_129 = F_75 () ;
V_121 -> V_130 = F_8 ( & V_62 ) ;
V_121 -> V_131 = V_132 ;
F_70 ( V_121 -> V_110 ) ;
F_71 ( V_121 -> V_113 ) ;
V_122 = 0 ;
if ( F_79 ( ( void T_3 * ) V_119 , V_121 , sizeof( * V_121 ) ) )
V_122 = - V_83 ;
F_31 ( V_121 ) ;
return V_122 ;
}
static long F_80 ( struct V_57 * V_58 , unsigned int V_133 ,
unsigned long V_119 )
{
int V_39 ;
switch ( V_133 ) {
case V_134 : {
struct V_63 T_3 * V_135 = ( void T_3 * ) V_119 ;
struct V_63 V_64 ;
if ( F_62 ( & V_64 , V_135 , sizeof( V_64 ) ) )
return - V_83 ;
do {
V_39 = F_60 ( & V_64 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_60 ( & V_64 ) ;
} while ( V_39 == - V_72 );
if ( V_39 )
return V_39 ;
return F_81 ( V_64 . V_65 , & V_135 -> V_65 ) ;
}
case V_136 : {
struct V_73 T_3 * V_137 = ( void T_3 * ) V_119 ;
struct V_73 V_74 ;
if ( F_62 ( & V_74 , V_137 , sizeof( V_74 ) ) )
return - V_83 ;
do {
V_39 = F_61 ( & V_74 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_61 ( & V_74 ) ;
} while ( V_39 == - V_72 );
if ( V_39 )
return V_39 ;
return F_81 ( V_74 . V_65 , & V_137 -> V_65 ) ;
}
case V_138 : {
struct V_87 T_3 * V_139 = ( void T_3 * ) V_119 ;
struct V_87 V_88 ;
if ( F_62 ( & V_88 , V_139 , sizeof( V_88 ) ) )
return - V_83 ;
do {
V_39 = F_63 ( & V_88 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_88 ) ;
} while ( V_39 == - V_72 );
if ( F_79 ( V_139 , & V_88 , sizeof( V_88 ) ) )
return - V_83 ;
return V_39 ;
}
case V_140 : {
struct V_101 T_3 * V_141 = ( void T_3 * ) V_119 ;
struct V_101 V_102 ;
if ( F_62 ( & V_102 , V_141 , sizeof( V_102 ) ) )
return - V_83 ;
do {
V_39 = F_67 ( & V_102 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_67 ( & V_102 ) ;
} while ( V_39 == - V_72 );
if ( F_79 ( V_141 , & V_102 , sizeof( V_102 ) ) )
return - V_83 ;
return V_39 ;
}
case V_142 : {
char V_110 [ V_111 ] ;
F_70 ( V_110 ) ;
if ( F_79 ( ( char T_3 * ) V_119 , V_110 ,
sizeof( char ) * V_111 ) )
return - V_83 ;
return 0 ;
}
case V_143 : {
char V_113 [ V_111 ] ;
F_71 ( V_113 ) ;
if ( F_79 ( ( char T_3 * ) V_119 , V_113 ,
sizeof( char ) * V_111 ) )
return - V_83 ;
return 0 ;
}
case V_144 : {
int V_116 [ V_111 ] ;
F_74 ( V_116 ) ;
if ( F_79 ( ( int T_3 * ) V_119 , V_116 ,
sizeof( int ) * V_111 ) )
return - V_83 ;
return 0 ;
}
case V_145 :
return F_81 ( F_76 () , ( int T_3 * ) V_119 ) ;
case V_146 :
return F_81 ( F_75 () , ( int T_3 * ) V_119 ) ;
case V_147 :
return F_81 ( F_8 ( & V_62 ) ,
( int T_3 * ) V_119 ) ;
case V_148 :
return F_81 ( V_132 , ( int T_3 * ) V_119 ) ;
case V_149 :
return F_78 ( V_58 , V_119 ) ;
case V_150 :
return F_81 ( V_46 , ( int T_3 * ) V_119 ) ;
case V_151 :
return F_81 ( F_77 ( V_125 ) ,
( int T_3 * ) V_119 ) ;
case V_152 :
return F_81 ( F_77 ( V_127 ) ,
( int T_3 * ) V_119 ) ;
case V_153 :
return F_81 ( F_77 ( V_154 ) ,
( int T_3 * ) V_119 ) ;
case V_155 :
return F_81 ( F_77 ( V_156 ) ,
( int T_3 * ) V_119 ) ;
case V_157 :
return F_81 ( F_77 ( V_154 ) +
F_77 ( V_156 ) ,
( int T_3 * ) V_119 ) ;
case V_158 :
return F_81 ( F_77 ( V_159 ) ,
( int T_3 * ) V_119 ) ;
case V_160 :
return F_81 ( F_77 ( V_161 ) ,
( int T_3 * ) V_119 ) ;
default:
return - V_162 ;
}
}
static long F_82 ( struct V_57 * V_58 , unsigned int V_133 ,
unsigned long V_119 )
{
struct V_163 T_3 * V_164 = F_83 ( V_119 ) ;
struct V_163 V_165 ;
struct V_63 V_166 ;
long V_39 ;
if ( F_62 ( & V_165 , V_164 , sizeof( V_165 ) ) )
return - V_83 ;
V_166 . V_167 = F_83 ( V_165 . V_167 ) ;
V_166 . V_66 = V_165 . V_66 ;
V_166 . V_168 = F_83 ( V_165 . V_168 ) ;
V_166 . V_65 = V_165 . V_65 ;
V_166 . V_169 = F_83 ( V_165 . V_169 ) ;
V_166 . V_170 = F_83 ( V_165 . V_170 ) ;
do {
V_39 = F_60 ( & V_166 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_60 ( & V_166 ) ;
} while ( V_39 == - V_72 );
if ( V_39 )
return V_39 ;
return F_81 ( V_166 . V_65 ,
& V_164 -> V_65 ) ;
}
static long F_84 ( struct V_57 * V_58 , unsigned int V_133 ,
unsigned long V_119 )
{
struct V_171 T_3 * V_172 = F_83 ( V_119 ) ;
struct V_171 V_173 ;
struct V_73 V_174 ;
long V_39 ;
if ( F_62 ( & V_173 , V_172 , sizeof( V_173 ) ) )
return - V_83 ;
V_174 . V_167 = F_83 ( V_173 . V_167 ) ;
V_174 . V_66 = V_173 . V_66 ;
V_174 . V_168 = F_83 ( V_173 . V_168 ) ;
V_174 . V_65 = V_173 . V_65 ;
V_174 . V_85 = F_83 ( V_173 . V_85 ) ;
V_174 . V_175 = F_83 ( V_173 . V_175 ) ;
V_174 . V_84 = F_83 ( V_173 . V_84 ) ;
V_174 . V_176 = F_83 ( V_173 . V_176 ) ;
V_174 . V_86 = F_83 ( V_173 . V_86 ) ;
do {
V_39 = F_61 ( & V_174 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_61 ( & V_174 ) ;
} while ( V_39 == - V_72 );
if ( V_39 )
return V_39 ;
return F_81 ( V_174 . V_65 ,
& V_172 -> V_65 ) ;
}
static long F_85 ( struct V_57 * V_58 , unsigned int V_133 ,
unsigned long V_119 )
{
struct V_177 T_3 * V_178 = F_83 ( V_119 ) ;
struct V_177 V_179 ;
struct V_87 V_180 ;
long V_39 ;
if ( F_62 ( & V_179 , V_178 , sizeof( V_179 ) ) )
return - V_83 ;
V_180 . V_181 = V_179 . V_181 ;
V_180 . V_91 = V_179 . V_91 ;
V_180 . V_182 = V_179 . V_182 ;
V_180 . V_183 =
V_179 . V_183 ;
V_180 . V_184 =
F_83 ( V_179 . V_184 ) ;
V_180 . V_185 =
V_179 . V_185 ;
V_180 . V_186 =
F_83 ( V_179 . V_186 ) ;
V_180 . V_187 =
V_179 . V_187 ;
V_180 . V_188 =
F_83 ( V_179 . V_188 ) ;
V_180 . V_189 = V_179 . V_189 ;
V_180 . V_190 =
F_83 ( V_179 . V_190 ) ;
V_180 . V_191 = V_179 . V_191 ;
V_180 . V_110 = V_179 . V_110 ;
do {
V_39 = F_63 ( & V_180 ) ;
} while ( V_39 == - V_72 );
if ( ( V_39 == - V_41 ) && ( F_7 () ) )
do {
V_39 = F_63 ( & V_180 ) ;
} while ( V_39 == - V_72 );
V_179 . V_187 = V_180 . V_187 ;
V_179 . V_189 = V_180 . V_189 ;
V_179 . V_110 = V_180 . V_110 ;
if ( F_79 ( V_178 , & V_179 , sizeof( V_179 ) ) )
return - V_83 ;
return V_39 ;
}
static long F_86 ( struct V_57 * V_58 , unsigned int V_133 ,
unsigned long V_119 )
{
if ( V_133 == V_134 )
return F_82 ( V_58 , V_133 , V_119 ) ;
if ( V_133 == V_136 )
return F_84 ( V_58 , V_133 , V_119 ) ;
if ( V_133 == V_138 )
return F_85 ( V_58 , V_133 , V_119 ) ;
return F_80 ( V_58 , V_133 , V_119 ) ;
}
static void F_87 ( struct V_192 * V_193 , unsigned char * V_194 , unsigned int V_82 )
{
int V_195 ;
for ( V_195 = 0 ; V_195 < V_82 ; V_195 ++ )
F_88 ( V_193 , L_7 , ( unsigned int ) V_194 [ V_195 ] ) ;
F_89 ( V_193 , ' ' ) ;
}
static void F_90 ( struct V_192 * V_193 , unsigned char * V_194 , unsigned int V_82 )
{
int V_196 , V_197 , V_198 ;
F_88 ( V_193 , L_8 ) ;
V_196 = 0 ;
for ( V_197 = 0 ; V_197 < ( V_82 / 16 ) ; V_197 ++ ) {
F_87 ( V_193 , V_194 + V_196 , 16 ) ;
V_196 += 16 ;
}
V_198 = V_82 % 16 ;
if ( V_198 ) {
F_87 ( V_193 , V_194 + V_196 , V_198 ) ;
V_196 += V_198 ;
}
F_89 ( V_193 , '\n' ) ;
}
static void F_91 ( unsigned char * V_199 , struct V_192 * V_193 ,
unsigned char * V_194 , unsigned int V_82 )
{
int V_196 , V_200 , V_201 ;
F_88 ( V_193 , L_9 , V_199 ) ;
V_196 = 0 ;
for ( V_200 = 0 ; V_200 < ( V_82 / 64 ) ; V_200 ++ ) {
F_90 ( V_193 , V_194 + V_196 , 64 ) ;
V_196 += 64 ;
}
V_201 = V_82 % 64 ;
if ( V_201 ) {
F_90 ( V_193 , V_194 + V_196 , V_201 ) ;
V_196 += V_201 ;
}
F_89 ( V_193 , '\n' ) ;
}
static void F_92 ( unsigned char * V_199 , struct V_192 * V_193 ,
unsigned int * V_202 , unsigned int V_82 )
{
F_88 ( V_193 , L_9 , V_199 ) ;
F_93 ( V_193 , L_10 , V_203 , 32 , 4 , V_202 , V_82 , false ) ;
F_89 ( V_193 , '\n' ) ;
}
static int F_94 ( struct V_192 * V_193 , void * V_204 )
{
char V_205 [ sizeof( int ) * V_111 ] ;
F_88 ( V_193 , L_11 ,
V_206 , V_207 , V_208 ) ;
F_88 ( V_193 , L_12 , V_132 ) ;
F_88 ( V_193 , L_13 , V_46 ) ;
F_88 ( V_193 , L_14 , F_77 ( V_125 ) ) ;
F_88 ( V_193 , L_15 , F_77 ( V_127 ) ) ;
F_88 ( V_193 , L_16 ,
F_77 ( V_154 ) ) ;
F_88 ( V_193 , L_17 ,
F_77 ( V_156 ) ) ;
F_88 ( V_193 , L_18 , F_77 ( V_159 ) ) ;
F_88 ( V_193 , L_19 , F_77 ( V_161 ) ) ;
F_88 ( V_193 , L_20 , F_77 ( V_209 ) ) ;
F_88 ( V_193 , L_21 , F_77 ( V_210 ) ) ;
F_88 ( V_193 , L_22 , F_76 () ) ;
F_88 ( V_193 , L_23 , F_75 () ) ;
F_88 ( V_193 , L_24 ,
F_8 ( & V_62 ) ) ;
F_70 ( V_205 ) ;
F_91 ( L_25
L_26 ,
V_193 , V_205 , V_111 ) ;
F_71 ( V_205 ) ;
F_91 ( L_27 , V_193 , V_205 , V_111 ) ;
F_74 ( ( int * ) V_205 ) ;
F_92 ( L_28 ,
V_193 , ( unsigned int * ) V_205 , V_111 ) ;
return 0 ;
}
static int F_95 ( struct V_61 * V_61 , struct V_57 * V_57 )
{
return F_96 ( V_57 , F_94 , NULL ) ;
}
static void F_97 ( int V_211 )
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
static void F_98 ( int V_211 )
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
static T_1 F_99 ( struct V_57 * V_57 , const char T_3 * V_109 ,
T_2 V_12 , T_4 * V_212 )
{
unsigned char * V_213 , * V_214 ;
T_2 V_215 ;
int V_216 ;
if ( V_12 <= 0 )
return 0 ;
#define F_100 1200UL
V_213 = F_28 ( F_100 , V_31 ) ;
if ( ! V_213 )
return 0 ;
V_215 = F_101 ( F_100 - 1 , V_12 ) ;
if ( F_62 ( V_213 , V_109 , V_215 ) != 0 ) {
F_31 ( V_213 ) ;
return - V_83 ;
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
F_97 ( V_216 ++ ) ;
else if ( * V_214 == 'e' || * V_214 == 'E' )
F_98 ( V_216 ++ ) ;
else if ( * V_214 != ' ' && * V_214 != '\t' )
break;
}
V_44:
F_31 ( V_213 ) ;
return V_12 ;
}
static int F_102 ( struct V_217 * V_47 , T_5 * V_218 )
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
F_103 ( & V_222 ) ;
if ( V_223 == 0 ) {
V_220 = ( T_5 * ) F_104 ( V_31 ) ;
if ( ! V_220 ) {
V_39 = - V_106 ;
goto V_44;
}
V_219 = 0 ;
if ( ! V_224 )
V_225 . V_226 = 0 ;
V_39 = F_105 ( & V_225 ) ;
if ( V_39 )
goto V_34;
V_223 = 1 ;
} else
V_223 ++ ;
F_106 ( & V_222 ) ;
return 0 ;
V_34:
F_107 ( ( unsigned long ) V_220 ) ;
V_44:
F_106 ( & V_222 ) ;
return V_39 ;
}
static void F_44 ( void )
{
F_103 ( & V_222 ) ;
V_223 -- ;
if ( V_223 == 0 ) {
F_108 ( & V_225 ) ;
F_107 ( ( unsigned long ) V_220 ) ;
}
F_106 ( & V_222 ) ;
}
int T_6 F_109 ( void )
{
V_227 = F_110 ( L_31 , NULL ) ;
V_228 = F_111 ( L_32 , 1 , 1 , 16 ) ;
F_112 ( V_228 , & V_229 ) ;
F_113 ( V_228 , V_230 ) ;
V_38 = F_111 ( L_33 , 1 , 1 , 16 ) ;
F_112 ( V_38 , & V_229 ) ;
F_113 ( V_38 , V_230 ) ;
return 0 ;
}
void F_114 ( void )
{
F_115 ( V_227 ) ;
if ( V_228 )
F_116 ( V_228 ) ;
if ( V_38 )
F_116 ( V_38 ) ;
}
int T_6 F_117 ( void )
{
int V_39 ;
V_39 = F_109 () ;
if ( V_39 )
goto V_44;
F_9 ( & V_17 , 0 ) ;
V_39 = F_118 ( & V_231 ) ;
if ( V_39 < 0 )
goto V_44;
V_232 = F_119 ( L_34 , 0644 , NULL , & V_233 ) ;
if ( ! V_232 ) {
V_39 = - V_106 ;
goto V_234;
}
return 0 ;
V_234:
F_120 ( & V_231 ) ;
V_44:
return V_39 ;
}
void F_121 ( void )
{
F_122 ( L_34 , NULL ) ;
F_120 ( & V_231 ) ;
F_114 () ;
}
