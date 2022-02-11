static inline int F_1 ( void )
{
if ( F_2 ( & V_1 ) ) {
F_3 ( & V_1 , 0 ) ;
F_4 ( & V_2 ) ;
F_5 () ;
F_6 ( V_3 , L_1 ,
F_7 ( & V_2 ) ) ;
return 1 ;
}
return 0 ;
}
void F_8 ( struct V_4 * V_5 )
{
F_9 ( & V_5 -> V_6 , & V_7 ) ;
}
void F_10 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_6 ) ;
}
struct V_4 * F_12 ( unsigned char * V_8 , int V_9 )
{
struct V_4 * V_5 ;
F_13 (zops, &zcrypt_ops_list, list)
if ( ( V_5 -> V_9 == V_9 ) &&
( ! strncmp ( V_5 -> V_8 , V_8 , sizeof( V_5 -> V_8 ) ) ) )
return V_5 ;
return NULL ;
}
static T_1 F_14 ( struct V_10 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
return - V_15 ;
}
static T_1 F_15 ( struct V_10 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
return - V_15 ;
}
static int F_16 ( struct V_16 * V_16 , struct V_10 * V_11 )
{
F_4 ( & V_17 ) ;
return F_17 ( V_16 , V_11 ) ;
}
static int F_18 ( struct V_16 * V_16 , struct V_10 * V_11 )
{
F_19 ( & V_17 ) ;
return 0 ;
}
static inline struct V_18 * F_20 ( struct V_19 * V_20 ,
struct V_18 * V_21 ,
unsigned int V_22 )
{
if ( ! V_21 || ! F_21 ( V_21 -> V_23 -> V_24 . V_25 -> V_26 . V_27 ) )
return NULL ;
F_22 ( V_21 ) ;
F_23 ( & V_21 -> V_23 -> V_24 . V_28 ) ;
F_24 ( V_22 , & V_20 -> V_29 ) ;
F_24 ( V_22 , & V_21 -> V_29 ) ;
V_21 -> V_30 ++ ;
return V_21 ;
}
static inline void F_25 ( struct V_19 * V_20 ,
struct V_18 * V_21 ,
unsigned int V_22 )
{
struct V_31 * V_32 = V_21 -> V_23 -> V_24 . V_25 -> V_26 . V_27 ;
V_21 -> V_30 -- ;
F_26 ( V_22 , & V_20 -> V_29 ) ;
F_26 ( V_22 , & V_21 -> V_29 ) ;
F_27 ( & V_21 -> V_23 -> V_24 . V_28 ) ;
F_28 ( V_21 ) ;
F_29 ( V_32 ) ;
}
static inline bool F_30 ( struct V_19 * V_20 ,
struct V_19 * V_33 ,
unsigned V_22 , unsigned V_34 )
{
if ( ! V_33 )
return false ;
V_22 += F_2 ( & V_20 -> V_29 ) ;
V_34 += F_2 ( & V_33 -> V_29 ) ;
if ( V_22 == V_34 )
return F_2 ( & V_20 -> V_35 -> V_36 ) >
F_2 ( & V_33 -> V_35 -> V_36 ) ;
return V_22 > V_34 ;
}
static inline bool F_31 ( struct V_18 * V_21 ,
struct V_18 * V_37 ,
unsigned V_22 , unsigned V_34 )
{
if ( ! V_37 )
return false ;
V_22 += F_2 ( & V_21 -> V_29 ) ;
V_34 += F_2 ( & V_37 -> V_29 ) ;
if ( V_22 == V_34 )
return & V_21 -> V_23 -> V_36 >
& V_37 -> V_23 -> V_36 ;
return V_22 > V_34 ;
}
static long F_32 ( struct V_38 * V_39 )
{
struct V_19 * V_20 , * V_33 ;
struct V_18 * V_21 , * V_37 ;
unsigned int V_22 , V_34 ;
unsigned int V_40 ;
int V_41 = 0 , V_42 = - V_43 ;
F_33 ( V_39 , V_44 ) ;
if ( V_39 -> V_45 < V_39 -> V_46 ) {
V_42 = - V_47 ;
goto V_48;
}
V_39 -> V_45 = V_39 -> V_46 ;
V_42 = F_34 ( V_39 , & V_40 ) ;
if ( V_42 )
goto V_48;
V_33 = NULL ;
V_37 = NULL ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( ! V_20 -> V_50 || ! ( V_20 -> V_35 -> V_51 & 0x18000000 ) )
continue;
if ( V_20 -> V_52 > V_39 -> V_46 ||
V_20 -> V_53 < V_39 -> V_46 )
continue;
V_22 = V_20 -> V_54 [ V_40 ] ;
if ( F_30 ( V_20 , V_33 , V_22 , V_34 ) )
continue;
F_37 (zq, zc) {
if ( ! V_21 -> V_50 || ! V_21 -> V_55 -> V_56 )
continue;
if ( F_31 ( V_21 , V_37 ,
V_22 , V_34 ) )
continue;
V_33 = V_20 ;
V_37 = V_21 ;
V_34 = V_22 ;
}
}
V_37 = F_20 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
if ( ! V_37 ) {
V_42 = - V_43 ;
goto V_48;
}
V_41 = V_37 -> V_23 -> V_41 ;
V_42 = V_37 -> V_55 -> V_56 ( V_37 , V_39 ) ;
F_35 ( & V_49 ) ;
F_25 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
V_48:
F_39 ( V_39 , V_40 , V_42 ,
F_40 ( V_41 ) , F_41 ( V_41 ) ) ;
return V_42 ;
}
static long F_42 ( struct V_57 * V_58 )
{
struct V_19 * V_20 , * V_33 ;
struct V_18 * V_21 , * V_37 ;
unsigned int V_22 , V_34 ;
unsigned int V_40 ;
int V_41 = 0 , V_42 = - V_43 ;
F_33 ( V_58 , V_59 ) ;
if ( V_58 -> V_45 < V_58 -> V_46 ) {
V_42 = - V_47 ;
goto V_48;
}
V_58 -> V_45 = V_58 -> V_46 ;
V_42 = F_43 ( V_58 , & V_40 ) ;
if ( V_42 )
goto V_48;
V_33 = NULL ;
V_37 = NULL ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( ! V_20 -> V_50 || ! ( V_20 -> V_35 -> V_51 & 0x18000000 ) )
continue;
if ( V_20 -> V_52 > V_58 -> V_46 ||
V_20 -> V_53 < V_58 -> V_46 )
continue;
V_22 = V_20 -> V_54 [ V_40 ] ;
if ( F_30 ( V_20 , V_33 , V_22 , V_34 ) )
continue;
F_37 (zq, zc) {
if ( ! V_21 -> V_50 || ! V_21 -> V_55 -> V_60 )
continue;
if ( F_31 ( V_21 , V_37 ,
V_22 , V_34 ) )
continue;
V_33 = V_20 ;
V_37 = V_21 ;
V_34 = V_22 ;
}
}
V_37 = F_20 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
if ( ! V_37 ) {
V_42 = - V_43 ;
goto V_48;
}
V_41 = V_37 -> V_23 -> V_41 ;
V_42 = V_37 -> V_55 -> V_60 ( V_37 , V_58 ) ;
F_35 ( & V_49 ) ;
F_25 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
V_48:
F_39 ( V_58 , V_40 , V_42 ,
F_40 ( V_41 ) , F_41 ( V_41 ) ) ;
return V_42 ;
}
long F_44 ( struct V_61 * V_62 )
{
struct V_19 * V_20 , * V_33 ;
struct V_18 * V_21 , * V_37 ;
struct V_63 V_64 ;
unsigned int V_22 , V_34 ;
unsigned int V_40 ;
unsigned short * V_65 ;
int V_41 = 0 , V_42 = - V_43 ;
F_33 ( V_62 , V_66 ) ;
V_42 = F_45 ( V_62 , & V_64 , & V_40 , & V_65 ) ;
if ( V_42 )
goto V_48;
V_33 = NULL ;
V_37 = NULL ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( ! V_20 -> V_50 || ! ( V_20 -> V_35 -> V_51 & 0x10000000 ) )
continue;
if ( V_62 -> V_67 != V_68 &&
V_62 -> V_67 != V_20 -> V_35 -> V_69 )
continue;
V_22 = F_46 ( V_40 ) * V_20 -> V_54 [ V_70 ] ;
if ( F_30 ( V_20 , V_33 , V_22 , V_34 ) )
continue;
F_37 (zq, zc) {
if ( ! V_21 -> V_50 ||
! V_21 -> V_55 -> V_71 ||
( ( * V_65 != ( unsigned short ) V_68 ) &&
( * V_65 != F_41 ( V_21 -> V_23 -> V_41 ) ) ) )
continue;
if ( F_31 ( V_21 , V_37 ,
V_22 , V_34 ) )
continue;
V_33 = V_20 ;
V_37 = V_21 ;
V_34 = V_22 ;
}
}
V_37 = F_20 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
if ( ! V_37 ) {
V_42 = - V_43 ;
goto V_48;
}
V_41 = V_37 -> V_23 -> V_41 ;
if ( * V_65 == ( unsigned short ) V_68 )
* V_65 = F_41 ( V_41 ) ;
V_42 = V_37 -> V_55 -> V_71 ( V_37 , V_62 , & V_64 ) ;
F_35 ( & V_49 ) ;
F_25 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
V_48:
F_39 ( V_62 , V_40 , V_42 ,
F_40 ( V_41 ) , F_41 ( V_41 ) ) ;
return V_42 ;
}
static bool F_47 ( unsigned int V_72 ,
unsigned short V_73 ,
struct V_74 * V_75 )
{
while ( V_73 -- > 0 ) {
if ( V_72 == V_75 -> V_76 )
return true ;
V_75 ++ ;
}
return false ;
}
static bool F_48 ( unsigned int V_77 ,
unsigned short V_73 ,
struct V_74 * V_75 )
{
while ( V_73 -- > 0 ) {
if ( F_49 ( V_75 -> V_76 , V_75 -> V_78 ) == V_77 )
return true ;
V_75 ++ ;
}
return false ;
}
static long F_50 ( struct V_79 * V_80 )
{
struct V_19 * V_20 , * V_33 ;
struct V_18 * V_21 , * V_37 ;
struct V_74 * V_75 ;
unsigned short V_73 ;
unsigned int V_22 , V_34 ;
unsigned int V_40 ;
struct V_63 V_64 ;
int V_41 = 0 , V_42 = - V_43 ;
F_33 ( V_80 , V_81 ) ;
V_73 = ( unsigned short ) V_80 -> V_82 ;
V_75 = NULL ;
if ( V_73 != 0 ) {
struct V_74 T_2 * V_83 ;
V_75 = F_51 ( V_73 , sizeof( * V_75 ) , V_84 ) ;
if ( ! V_75 ) {
V_42 = - V_85 ;
goto V_48;
}
V_83 = (struct V_74 V_86 T_2 * ) V_80 -> V_75 ;
if ( F_52 ( V_75 , V_83 ,
V_73 * sizeof( * V_75 ) ) ) {
V_42 = - V_87 ;
goto V_48;
}
}
V_42 = F_53 ( V_80 , & V_64 , & V_40 ) ;
if ( V_42 )
goto V_88;
V_33 = NULL ;
V_37 = NULL ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( ! V_20 -> V_50 || ! ( V_20 -> V_35 -> V_51 & 0x04000000 ) )
continue;
if ( V_75 &&
! F_47 ( V_20 -> V_35 -> V_69 , V_73 , V_75 ) )
continue;
V_22 = F_54 ( V_40 ) * V_20 -> V_54 [ V_70 ] ;
if ( F_30 ( V_20 , V_33 , V_22 , V_34 ) )
continue;
F_37 (zq, zc) {
if ( ! V_21 -> V_50 ||
! V_21 -> V_55 -> V_89 ||
( V_75 &&
! F_48 ( V_21 -> V_23 -> V_41 ,
V_73 , V_75 ) ) )
continue;
if ( F_31 ( V_21 , V_37 ,
V_22 , V_34 ) )
continue;
V_33 = V_20 ;
V_37 = V_21 ;
V_34 = V_22 ;
}
}
V_37 = F_20 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
if ( ! V_37 ) {
V_42 = - V_43 ;
goto V_88;
}
V_41 = V_37 -> V_23 -> V_41 ;
V_42 = V_37 -> V_55 -> V_89 ( V_37 , V_80 , & V_64 ) ;
F_35 ( & V_49 ) ;
F_25 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
V_88:
F_55 ( V_75 ) ;
V_48:
F_39 ( V_80 , V_40 , V_42 ,
F_40 ( V_41 ) , F_41 ( V_41 ) ) ;
return V_42 ;
}
static long F_56 ( char * V_90 )
{
struct V_19 * V_20 , * V_33 ;
struct V_18 * V_21 , * V_37 ;
unsigned int V_22 , V_34 ;
unsigned int V_40 ;
struct V_63 V_64 ;
unsigned int V_65 ;
int V_41 = 0 , V_42 = - V_43 ;
F_33 ( V_90 , V_91 ) ;
V_42 = F_57 ( & V_64 , & V_40 , & V_65 ) ;
if ( V_42 )
goto V_48;
V_33 = NULL ;
V_37 = NULL ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( ! V_20 -> V_50 || ! ( V_20 -> V_35 -> V_51 & 0x10000000 ) )
continue;
V_22 = V_20 -> V_54 [ V_40 ] ;
if ( F_30 ( V_20 , V_33 , V_22 , V_34 ) )
continue;
F_37 (zq, zc) {
if ( ! V_21 -> V_50 || ! V_21 -> V_55 -> V_92 )
continue;
if ( F_31 ( V_21 , V_37 ,
V_22 , V_34 ) )
continue;
V_33 = V_20 ;
V_37 = V_21 ;
V_34 = V_22 ;
}
}
V_37 = F_20 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
if ( ! V_37 )
return - V_43 ;
V_41 = V_37 -> V_23 -> V_41 ;
V_42 = V_37 -> V_55 -> V_92 ( V_37 , V_90 , & V_64 ) ;
F_35 ( & V_49 ) ;
F_25 ( V_33 , V_37 , V_22 ) ;
F_38 ( & V_49 ) ;
V_48:
F_39 ( V_90 , V_40 , V_42 ,
F_40 ( V_41 ) , F_41 ( V_41 ) ) ;
return V_42 ;
}
void F_58 ( struct V_93 * V_94 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
struct V_95 * V_96 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
F_35 ( & V_49 ) ;
F_36 (zc) {
F_37 (zq, zc) {
V_96 = V_94 -> V_28 ;
V_96 += F_40 ( V_21 -> V_23 -> V_41 ) * V_97 ;
V_96 += F_41 ( V_21 -> V_23 -> V_41 ) ;
V_96 -> V_98 = V_20 -> V_35 -> V_24 . V_99 ;
V_96 -> V_51 = V_20 -> V_35 -> V_51 >> 26 ;
V_96 -> V_41 = V_21 -> V_23 -> V_41 ;
V_96 -> V_50 = V_21 -> V_50 ? 0x01 : 0x00 ;
}
}
F_38 ( & V_49 ) ;
}
static void F_59 ( char V_100 [ V_101 ] )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
memset ( V_100 , 0 , sizeof( char ) * V_101 ) ;
F_35 ( & V_49 ) ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
V_100 [ F_40 ( V_21 -> V_23 -> V_41 ) ] =
V_20 -> V_50 ? V_20 -> V_103 : 0x0d ;
}
}
F_38 ( & V_49 ) ;
}
static void F_60 ( char V_104 [ V_101 ] )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
memset ( V_104 , 0 , sizeof( char ) * V_101 ) ;
F_35 ( & V_49 ) ;
F_61 () ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
F_35 ( & V_21 -> V_23 -> V_105 ) ;
V_104 [ F_40 ( V_21 -> V_23 -> V_41 ) ] =
V_21 -> V_23 -> V_106 +
V_21 -> V_23 -> V_107 ;
F_38 ( & V_21 -> V_23 -> V_105 ) ;
}
}
F_62 () ;
F_38 ( & V_49 ) ;
}
static void F_63 ( int V_108 [ V_101 ] )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
memset ( V_108 , 0 , sizeof( int ) * V_101 ) ;
F_35 ( & V_49 ) ;
F_61 () ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
F_35 ( & V_21 -> V_23 -> V_105 ) ;
V_108 [ F_40 ( V_21 -> V_23 -> V_41 ) ] =
V_21 -> V_23 -> V_36 ;
F_38 ( & V_21 -> V_23 -> V_105 ) ;
}
}
F_62 () ;
F_38 ( & V_49 ) ;
}
static int F_64 ( void )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
int V_106 ;
V_106 = 0 ;
F_35 ( & V_49 ) ;
F_61 () ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
F_35 ( & V_21 -> V_23 -> V_105 ) ;
V_106 += V_21 -> V_23 -> V_106 ;
F_38 ( & V_21 -> V_23 -> V_105 ) ;
}
}
F_62 () ;
F_38 ( & V_49 ) ;
return V_106 ;
}
static int F_65 ( void )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
int V_107 ;
V_107 = 0 ;
F_35 ( & V_49 ) ;
F_61 () ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
F_35 ( & V_21 -> V_23 -> V_105 ) ;
V_107 += V_21 -> V_23 -> V_107 ;
F_38 ( & V_21 -> V_23 -> V_105 ) ;
}
}
F_62 () ;
F_38 ( & V_49 ) ;
return V_107 ;
}
static int F_66 ( int type )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
int V_109 ;
V_109 = 0 ;
F_35 ( & V_49 ) ;
F_36 (zc) {
if ( V_20 -> V_35 -> V_69 != type )
continue;
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
V_109 ++ ;
}
}
F_38 ( & V_49 ) ;
return V_109 ;
}
static long F_67 ( struct V_10 * V_11 , unsigned long V_110 )
{
struct V_111 * V_112 ;
int V_113 ;
V_112 = F_68 ( sizeof( * V_112 ) , V_84 ) ;
if ( ! V_112 )
return - V_85 ;
V_112 -> V_114 = V_115 ;
V_112 -> V_116 = F_66 ( V_117 ) ;
V_112 -> V_118 = F_66 ( V_119 ) ;
V_112 -> V_120 = F_65 () ;
V_112 -> V_121 = F_64 () ;
V_112 -> V_122 = F_2 ( & V_17 ) ;
V_112 -> V_123 = V_102 ;
F_59 ( V_112 -> V_100 ) ;
F_60 ( V_112 -> V_104 ) ;
V_113 = 0 ;
if ( F_69 ( ( void T_2 * ) V_110 , V_112 , sizeof( * V_112 ) ) )
V_113 = - V_87 ;
F_55 ( V_112 ) ;
return V_113 ;
}
static long F_70 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
int V_42 ;
switch ( V_124 ) {
case V_125 : {
struct V_38 T_2 * V_126 = ( void T_2 * ) V_110 ;
struct V_38 V_39 ;
if ( F_52 ( & V_39 , V_126 , sizeof( V_39 ) ) )
return - V_87 ;
do {
V_42 = F_32 ( & V_39 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_32 ( & V_39 ) ;
} while ( V_42 == - V_127 );
if ( V_42 ) {
F_6 ( V_128 , L_2 , V_42 ) ;
return V_42 ;
}
return F_71 ( V_39 . V_45 , & V_126 -> V_45 ) ;
}
case V_129 : {
struct V_57 T_2 * V_130 = ( void T_2 * ) V_110 ;
struct V_57 V_58 ;
if ( F_52 ( & V_58 , V_130 , sizeof( V_58 ) ) )
return - V_87 ;
do {
V_42 = F_42 ( & V_58 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_42 ( & V_58 ) ;
} while ( V_42 == - V_127 );
if ( V_42 ) {
F_6 ( V_128 , L_3 , V_42 ) ;
return V_42 ;
}
return F_71 ( V_58 . V_45 , & V_130 -> V_45 ) ;
}
case V_131 : {
struct V_61 T_2 * V_132 = ( void T_2 * ) V_110 ;
struct V_61 V_62 ;
if ( F_52 ( & V_62 , V_132 , sizeof( V_62 ) ) )
return - V_87 ;
do {
V_42 = F_44 ( & V_62 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_44 ( & V_62 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
F_6 ( V_128 , L_4 , V_42 ) ;
if ( F_69 ( V_132 , & V_62 , sizeof( V_62 ) ) )
return - V_87 ;
return V_42 ;
}
case V_133 : {
struct V_79 T_2 * V_134 = ( void T_2 * ) V_110 ;
struct V_79 V_80 ;
if ( F_52 ( & V_80 , V_134 , sizeof( V_80 ) ) )
return - V_87 ;
do {
V_42 = F_50 ( & V_80 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_50 ( & V_80 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
F_6 ( V_128 , L_5 , V_42 ) ;
if ( F_69 ( V_134 , & V_80 , sizeof( V_80 ) ) )
return - V_87 ;
return V_42 ;
}
case V_135 : {
struct V_93 * V_136 ;
V_136 = F_68 ( sizeof( struct V_93 ) ,
V_84 ) ;
if ( ! V_136 )
return - V_85 ;
F_58 ( V_136 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_136 ,
sizeof( struct V_93 ) ) ) {
F_55 ( V_136 ) ;
return - V_87 ;
}
F_55 ( V_136 ) ;
return 0 ;
}
case V_137 : {
char V_100 [ V_101 ] ;
F_59 ( V_100 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_100 ,
sizeof( char ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_138 : {
char V_104 [ V_101 ] ;
F_60 ( V_104 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_104 ,
sizeof( char ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_139 : {
int V_108 [ V_101 ] ;
F_63 ( V_108 ) ;
if ( F_69 ( ( int T_2 * ) V_110 , V_108 ,
sizeof( int ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_140 :
return F_71 ( F_65 () , ( int T_2 * ) V_110 ) ;
case V_141 :
return F_71 ( F_64 () , ( int T_2 * ) V_110 ) ;
case V_142 :
return F_71 ( F_2 ( & V_17 ) ,
( int T_2 * ) V_110 ) ;
case V_143 :
return F_71 ( V_102 , ( int T_2 * ) V_110 ) ;
case V_144 :
return F_67 ( V_11 , V_110 ) ;
case V_145 :
return F_71 ( V_115 , ( int T_2 * ) V_110 ) ;
case V_146 :
return F_71 ( F_66 ( V_117 ) ,
( int T_2 * ) V_110 ) ;
case V_147 :
return F_71 ( F_66 ( V_119 ) ,
( int T_2 * ) V_110 ) ;
case V_148 :
return F_71 ( F_66 ( V_149 ) ,
( int T_2 * ) V_110 ) ;
case V_150 :
return F_71 ( F_66 ( V_151 ) ,
( int T_2 * ) V_110 ) ;
case V_152 :
return F_71 ( F_66 ( V_149 ) +
F_66 ( V_151 ) ,
( int T_2 * ) V_110 ) ;
case V_153 :
return F_71 ( F_66 ( V_154 ) ,
( int T_2 * ) V_110 ) ;
case V_155 :
return F_71 ( F_66 ( V_156 ) ,
( int T_2 * ) V_110 ) ;
default:
return - V_157 ;
}
}
static long F_72 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_158 T_2 * V_159 = F_73 ( V_110 ) ;
struct V_158 V_160 ;
struct V_38 V_161 ;
long V_42 ;
if ( F_52 ( & V_160 , V_159 , sizeof( V_160 ) ) )
return - V_87 ;
V_161 . V_162 = F_73 ( V_160 . V_162 ) ;
V_161 . V_46 = V_160 . V_46 ;
V_161 . V_163 = F_73 ( V_160 . V_163 ) ;
V_161 . V_45 = V_160 . V_45 ;
V_161 . V_164 = F_73 ( V_160 . V_164 ) ;
V_161 . V_165 = F_73 ( V_160 . V_165 ) ;
do {
V_42 = F_32 ( & V_161 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_32 ( & V_161 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
return V_42 ;
return F_71 ( V_161 . V_45 ,
& V_159 -> V_45 ) ;
}
static long F_74 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_166 T_2 * V_167 = F_73 ( V_110 ) ;
struct V_166 V_168 ;
struct V_57 V_169 ;
long V_42 ;
if ( F_52 ( & V_168 , V_167 , sizeof( V_168 ) ) )
return - V_87 ;
V_169 . V_162 = F_73 ( V_168 . V_162 ) ;
V_169 . V_46 = V_168 . V_46 ;
V_169 . V_163 = F_73 ( V_168 . V_163 ) ;
V_169 . V_45 = V_168 . V_45 ;
V_169 . V_170 = F_73 ( V_168 . V_170 ) ;
V_169 . V_171 = F_73 ( V_168 . V_171 ) ;
V_169 . V_172 = F_73 ( V_168 . V_172 ) ;
V_169 . V_173 = F_73 ( V_168 . V_173 ) ;
V_169 . V_174 = F_73 ( V_168 . V_174 ) ;
do {
V_42 = F_42 ( & V_169 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_42 ( & V_169 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
return V_42 ;
return F_71 ( V_169 . V_45 ,
& V_167 -> V_45 ) ;
}
static long F_75 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_175 T_2 * V_176 = F_73 ( V_110 ) ;
struct V_175 V_177 ;
struct V_61 V_178 ;
long V_42 ;
if ( F_52 ( & V_177 , V_176 , sizeof( V_177 ) ) )
return - V_87 ;
V_178 . V_179 = V_177 . V_179 ;
V_178 . V_67 = V_177 . V_67 ;
V_178 . V_180 = V_177 . V_180 ;
V_178 . V_181 =
V_177 . V_181 ;
V_178 . V_182 =
F_73 ( V_177 . V_182 ) ;
V_178 . V_183 =
V_177 . V_183 ;
V_178 . V_184 =
F_73 ( V_177 . V_184 ) ;
V_178 . V_185 =
V_177 . V_185 ;
V_178 . V_186 =
F_73 ( V_177 . V_186 ) ;
V_178 . V_187 = V_177 . V_187 ;
V_178 . V_188 =
F_73 ( V_177 . V_188 ) ;
V_178 . V_189 = V_177 . V_189 ;
V_178 . V_100 = V_177 . V_100 ;
do {
V_42 = F_44 ( & V_178 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_44 ( & V_178 ) ;
} while ( V_42 == - V_127 );
V_177 . V_185 = V_178 . V_185 ;
V_177 . V_187 = V_178 . V_187 ;
V_177 . V_100 = V_178 . V_100 ;
if ( F_69 ( V_176 , & V_177 , sizeof( V_177 ) ) )
return - V_87 ;
return V_42 ;
}
static long F_76 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
if ( V_124 == V_125 )
return F_72 ( V_11 , V_124 , V_110 ) ;
if ( V_124 == V_129 )
return F_74 ( V_11 , V_124 , V_110 ) ;
if ( V_124 == V_131 )
return F_75 ( V_11 , V_124 , V_110 ) ;
return F_70 ( V_11 , V_124 , V_110 ) ;
}
static void F_77 ( struct V_190 * V_191 , unsigned char * V_192 , unsigned int V_193 )
{
int V_194 ;
for ( V_194 = 0 ; V_194 < V_193 ; V_194 ++ )
F_78 ( V_191 , L_6 , ( unsigned int ) V_192 [ V_194 ] ) ;
F_79 ( V_191 , ' ' ) ;
}
static void F_80 ( struct V_190 * V_191 , unsigned char * V_192 , unsigned int V_193 )
{
int V_195 , V_196 , V_197 ;
F_78 ( V_191 , L_7 ) ;
V_195 = 0 ;
for ( V_196 = 0 ; V_196 < ( V_193 / 16 ) ; V_196 ++ ) {
F_77 ( V_191 , V_192 + V_195 , 16 ) ;
V_195 += 16 ;
}
V_197 = V_193 % 16 ;
if ( V_197 ) {
F_77 ( V_191 , V_192 + V_195 , V_197 ) ;
V_195 += V_197 ;
}
F_79 ( V_191 , '\n' ) ;
}
static void F_81 ( unsigned char * V_198 , struct V_190 * V_191 ,
unsigned char * V_192 , unsigned int V_193 )
{
int V_195 , V_199 , V_200 ;
F_78 ( V_191 , L_8 , V_198 ) ;
V_195 = 0 ;
for ( V_199 = 0 ; V_199 < ( V_193 / 64 ) ; V_199 ++ ) {
F_80 ( V_191 , V_192 + V_195 , 64 ) ;
V_195 += 64 ;
}
V_200 = V_193 % 64 ;
if ( V_200 ) {
F_80 ( V_191 , V_192 + V_195 , V_200 ) ;
V_195 += V_200 ;
}
F_79 ( V_191 , '\n' ) ;
}
static void F_82 ( unsigned char * V_198 , struct V_190 * V_191 ,
unsigned int * V_201 , unsigned int V_193 )
{
F_78 ( V_191 , L_8 , V_198 ) ;
F_83 ( V_191 , L_9 , V_202 , 32 , 4 , V_201 , V_193 , false ) ;
F_79 ( V_191 , '\n' ) ;
}
static int F_84 ( struct V_190 * V_191 , void * V_203 )
{
char V_204 [ sizeof( int ) * V_101 ] ;
F_78 ( V_191 , L_10 ,
V_205 , V_206 , V_207 ) ;
F_78 ( V_191 , L_11 , V_102 ) ;
F_78 ( V_191 , L_12 , V_115 ) ;
F_78 ( V_191 , L_13 , F_66 ( V_117 ) ) ;
F_78 ( V_191 , L_14 , F_66 ( V_119 ) ) ;
F_78 ( V_191 , L_15 ,
F_66 ( V_149 ) ) ;
F_78 ( V_191 , L_16 ,
F_66 ( V_151 ) ) ;
F_78 ( V_191 , L_17 , F_66 ( V_154 ) ) ;
F_78 ( V_191 , L_18 , F_66 ( V_156 ) ) ;
F_78 ( V_191 , L_19 , F_66 ( V_208 ) ) ;
F_78 ( V_191 , L_20 , F_66 ( V_209 ) ) ;
F_78 ( V_191 , L_21 , F_65 () ) ;
F_78 ( V_191 , L_22 , F_64 () ) ;
F_78 ( V_191 , L_23 ,
F_2 ( & V_17 ) ) ;
F_59 ( V_204 ) ;
F_81 ( L_24
L_25 ,
V_191 , V_204 , V_101 ) ;
F_60 ( V_204 ) ;
F_81 ( L_26 , V_191 , V_204 , V_101 ) ;
F_63 ( ( int * ) V_204 ) ;
F_82 ( L_27 ,
V_191 , ( unsigned int * ) V_204 , V_101 ) ;
return 0 ;
}
static int F_85 ( struct V_16 * V_16 , struct V_10 * V_10 )
{
return F_86 ( V_10 , F_84 , NULL ) ;
}
static void F_87 ( int V_210 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
F_35 ( & V_49 ) ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
V_21 -> V_50 = 0 ;
F_88 ( V_21 -> V_23 ) ;
}
}
F_38 ( & V_49 ) ;
}
static void F_89 ( int V_210 )
{
struct V_19 * V_20 ;
struct V_18 * V_21 ;
F_35 ( & V_49 ) ;
F_36 (zc) {
F_37 (zq, zc) {
if ( F_41 ( V_21 -> V_23 -> V_41 ) != V_102 )
continue;
V_21 -> V_50 = 1 ;
F_88 ( V_21 -> V_23 ) ;
}
}
F_38 ( & V_49 ) ;
}
static T_1 F_90 ( struct V_10 * V_10 , const char T_2 * V_90 ,
T_3 V_13 , T_4 * V_211 )
{
unsigned char * V_212 , * V_213 ;
T_3 V_214 ;
int V_215 ;
if ( V_13 <= 0 )
return 0 ;
#define F_91 1200UL
V_212 = F_92 ( F_91 , V_84 ) ;
if ( ! V_212 )
return 0 ;
V_214 = F_93 ( F_91 - 1 , V_13 ) ;
if ( F_52 ( V_212 , V_90 , V_214 ) != 0 ) {
F_55 ( V_212 ) ;
return - V_87 ;
}
V_212 [ V_214 ] = '\0' ;
V_213 = strstr ( V_212 , L_28 ) ;
if ( ! V_213 )
goto V_48;
V_213 = strstr ( V_213 , L_29 ) ;
if ( ! V_213 )
goto V_48;
V_213 ++ ;
if ( strstr ( V_213 , L_26 ) == NULL )
goto V_48;
for ( V_215 = 0 ; V_215 < 64 && * V_213 ; V_213 ++ ) {
if ( * V_213 >= '0' && * V_213 <= '8' )
V_215 ++ ;
else if ( * V_213 == 'd' || * V_213 == 'D' )
F_87 ( V_215 ++ ) ;
else if ( * V_213 == 'e' || * V_213 == 'E' )
F_89 ( V_215 ++ ) ;
else if ( * V_213 != ' ' && * V_213 != '\t' )
break;
}
V_48:
F_55 ( V_212 ) ;
return V_13 ;
}
static int F_94 ( struct V_216 * V_92 , T_5 * V_217 )
{
int V_42 ;
if ( V_218 == 0 ) {
V_42 = F_56 ( ( char * ) V_219 ) ;
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
V_42 = F_56 ( ( char * ) V_219 ) ;
if ( V_42 < 0 )
return - V_220 ;
V_218 = V_42 / sizeof *V_217 ;
}
* V_217 = V_219 [ -- V_218 ] ;
return sizeof *V_217 ;
}
int F_95 ( void )
{
int V_42 = 0 ;
F_96 ( & V_221 ) ;
if ( V_222 == 0 ) {
V_219 = ( T_5 * ) F_97 ( V_84 ) ;
if ( ! V_219 ) {
V_42 = - V_85 ;
goto V_48;
}
V_218 = 0 ;
if ( ! V_223 )
V_224 . V_225 = 0 ;
V_42 = F_98 ( & V_224 ) ;
if ( V_42 )
goto V_88;
V_222 = 1 ;
} else
V_222 ++ ;
F_99 ( & V_221 ) ;
return 0 ;
V_88:
F_100 ( ( unsigned long ) V_219 ) ;
V_48:
F_99 ( & V_221 ) ;
return V_42 ;
}
void F_101 ( void )
{
F_96 ( & V_221 ) ;
V_222 -- ;
if ( V_222 == 0 ) {
F_102 ( & V_224 ) ;
F_100 ( ( unsigned long ) V_219 ) ;
}
F_99 ( & V_221 ) ;
}
int T_6 F_103 ( void )
{
V_226 = F_104 ( L_30 , 1 , 1 ,
V_227 * sizeof( long ) ) ;
F_105 ( V_226 , & V_228 ) ;
F_106 ( V_226 , V_229 ) ;
return 0 ;
}
void F_107 ( void )
{
F_108 ( V_226 ) ;
}
int T_6 F_109 ( void )
{
int V_42 ;
V_42 = F_103 () ;
if ( V_42 )
goto V_48;
F_3 ( & V_1 , 0 ) ;
V_42 = F_110 ( & V_230 ) ;
if ( V_42 < 0 )
goto V_48;
V_231 = F_111 ( L_31 , 0644 , NULL ,
& V_232 ) ;
if ( ! V_231 ) {
V_42 = - V_85 ;
goto V_233;
}
F_112 () ;
F_113 () ;
return 0 ;
V_233:
F_114 ( & V_230 ) ;
V_48:
return V_42 ;
}
void T_7 F_115 ( void )
{
F_116 ( L_31 , NULL ) ;
F_114 ( & V_230 ) ;
F_117 () ;
F_118 () ;
F_107 () ;
}
