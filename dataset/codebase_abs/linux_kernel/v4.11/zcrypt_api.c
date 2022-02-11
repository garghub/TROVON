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
if ( V_42 )
return V_42 ;
return F_71 ( V_39 . V_45 , & V_126 -> V_45 ) ;
}
case V_128 : {
struct V_57 T_2 * V_129 = ( void T_2 * ) V_110 ;
struct V_57 V_58 ;
if ( F_52 ( & V_58 , V_129 , sizeof( V_58 ) ) )
return - V_87 ;
do {
V_42 = F_42 ( & V_58 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_42 ( & V_58 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
return V_42 ;
return F_71 ( V_58 . V_45 , & V_129 -> V_45 ) ;
}
case V_130 : {
struct V_61 T_2 * V_131 = ( void T_2 * ) V_110 ;
struct V_61 V_62 ;
if ( F_52 ( & V_62 , V_131 , sizeof( V_62 ) ) )
return - V_87 ;
do {
V_42 = F_44 ( & V_62 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_44 ( & V_62 ) ;
} while ( V_42 == - V_127 );
if ( F_69 ( V_131 , & V_62 , sizeof( V_62 ) ) )
return - V_87 ;
return V_42 ;
}
case V_132 : {
struct V_79 T_2 * V_133 = ( void T_2 * ) V_110 ;
struct V_79 V_80 ;
if ( F_52 ( & V_80 , V_133 , sizeof( V_80 ) ) )
return - V_87 ;
do {
V_42 = F_50 ( & V_80 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_50 ( & V_80 ) ;
} while ( V_42 == - V_127 );
if ( F_69 ( V_133 , & V_80 , sizeof( V_80 ) ) )
return - V_87 ;
return V_42 ;
}
case V_134 : {
struct V_93 * V_135 ;
V_135 = F_68 ( sizeof( struct V_93 ) ,
V_84 ) ;
if ( ! V_135 )
return - V_85 ;
F_58 ( V_135 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_135 ,
sizeof( struct V_93 ) ) ) {
F_55 ( V_135 ) ;
return - V_87 ;
}
F_55 ( V_135 ) ;
return 0 ;
}
case V_136 : {
char V_100 [ V_101 ] ;
F_59 ( V_100 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_100 ,
sizeof( char ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_137 : {
char V_104 [ V_101 ] ;
F_60 ( V_104 ) ;
if ( F_69 ( ( char T_2 * ) V_110 , V_104 ,
sizeof( char ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_138 : {
int V_108 [ V_101 ] ;
F_63 ( V_108 ) ;
if ( F_69 ( ( int T_2 * ) V_110 , V_108 ,
sizeof( int ) * V_101 ) )
return - V_87 ;
return 0 ;
}
case V_139 :
return F_71 ( F_65 () , ( int T_2 * ) V_110 ) ;
case V_140 :
return F_71 ( F_64 () , ( int T_2 * ) V_110 ) ;
case V_141 :
return F_71 ( F_2 ( & V_17 ) ,
( int T_2 * ) V_110 ) ;
case V_142 :
return F_71 ( V_102 , ( int T_2 * ) V_110 ) ;
case V_143 :
return F_67 ( V_11 , V_110 ) ;
case V_144 :
return F_71 ( V_115 , ( int T_2 * ) V_110 ) ;
case V_145 :
return F_71 ( F_66 ( V_117 ) ,
( int T_2 * ) V_110 ) ;
case V_146 :
return F_71 ( F_66 ( V_119 ) ,
( int T_2 * ) V_110 ) ;
case V_147 :
return F_71 ( F_66 ( V_148 ) ,
( int T_2 * ) V_110 ) ;
case V_149 :
return F_71 ( F_66 ( V_150 ) ,
( int T_2 * ) V_110 ) ;
case V_151 :
return F_71 ( F_66 ( V_148 ) +
F_66 ( V_150 ) ,
( int T_2 * ) V_110 ) ;
case V_152 :
return F_71 ( F_66 ( V_153 ) ,
( int T_2 * ) V_110 ) ;
case V_154 :
return F_71 ( F_66 ( V_155 ) ,
( int T_2 * ) V_110 ) ;
default:
return - V_156 ;
}
}
static long F_72 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_157 T_2 * V_158 = F_73 ( V_110 ) ;
struct V_157 V_159 ;
struct V_38 V_160 ;
long V_42 ;
if ( F_52 ( & V_159 , V_158 , sizeof( V_159 ) ) )
return - V_87 ;
V_160 . V_161 = F_73 ( V_159 . V_161 ) ;
V_160 . V_46 = V_159 . V_46 ;
V_160 . V_162 = F_73 ( V_159 . V_162 ) ;
V_160 . V_45 = V_159 . V_45 ;
V_160 . V_163 = F_73 ( V_159 . V_163 ) ;
V_160 . V_164 = F_73 ( V_159 . V_164 ) ;
do {
V_42 = F_32 ( & V_160 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_32 ( & V_160 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
return V_42 ;
return F_71 ( V_160 . V_45 ,
& V_158 -> V_45 ) ;
}
static long F_74 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_165 T_2 * V_166 = F_73 ( V_110 ) ;
struct V_165 V_167 ;
struct V_57 V_168 ;
long V_42 ;
if ( F_52 ( & V_167 , V_166 , sizeof( V_167 ) ) )
return - V_87 ;
V_168 . V_161 = F_73 ( V_167 . V_161 ) ;
V_168 . V_46 = V_167 . V_46 ;
V_168 . V_162 = F_73 ( V_167 . V_162 ) ;
V_168 . V_45 = V_167 . V_45 ;
V_168 . V_169 = F_73 ( V_167 . V_169 ) ;
V_168 . V_170 = F_73 ( V_167 . V_170 ) ;
V_168 . V_171 = F_73 ( V_167 . V_171 ) ;
V_168 . V_172 = F_73 ( V_167 . V_172 ) ;
V_168 . V_173 = F_73 ( V_167 . V_173 ) ;
do {
V_42 = F_42 ( & V_168 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_42 ( & V_168 ) ;
} while ( V_42 == - V_127 );
if ( V_42 )
return V_42 ;
return F_71 ( V_168 . V_45 ,
& V_166 -> V_45 ) ;
}
static long F_75 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
struct V_174 T_2 * V_175 = F_73 ( V_110 ) ;
struct V_174 V_176 ;
struct V_61 V_177 ;
long V_42 ;
if ( F_52 ( & V_176 , V_175 , sizeof( V_176 ) ) )
return - V_87 ;
V_177 . V_178 = V_176 . V_178 ;
V_177 . V_67 = V_176 . V_67 ;
V_177 . V_179 = V_176 . V_179 ;
V_177 . V_180 =
V_176 . V_180 ;
V_177 . V_181 =
F_73 ( V_176 . V_181 ) ;
V_177 . V_182 =
V_176 . V_182 ;
V_177 . V_183 =
F_73 ( V_176 . V_183 ) ;
V_177 . V_184 =
V_176 . V_184 ;
V_177 . V_185 =
F_73 ( V_176 . V_185 ) ;
V_177 . V_186 = V_176 . V_186 ;
V_177 . V_187 =
F_73 ( V_176 . V_187 ) ;
V_177 . V_188 = V_176 . V_188 ;
V_177 . V_100 = V_176 . V_100 ;
do {
V_42 = F_44 ( & V_177 ) ;
} while ( V_42 == - V_127 );
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
do {
V_42 = F_44 ( & V_177 ) ;
} while ( V_42 == - V_127 );
V_176 . V_184 = V_177 . V_184 ;
V_176 . V_186 = V_177 . V_186 ;
V_176 . V_100 = V_177 . V_100 ;
if ( F_69 ( V_175 , & V_176 , sizeof( V_176 ) ) )
return - V_87 ;
return V_42 ;
}
static long F_76 ( struct V_10 * V_11 , unsigned int V_124 ,
unsigned long V_110 )
{
if ( V_124 == V_125 )
return F_72 ( V_11 , V_124 , V_110 ) ;
if ( V_124 == V_128 )
return F_74 ( V_11 , V_124 , V_110 ) ;
if ( V_124 == V_130 )
return F_75 ( V_11 , V_124 , V_110 ) ;
return F_70 ( V_11 , V_124 , V_110 ) ;
}
static void F_77 ( struct V_189 * V_190 , unsigned char * V_191 , unsigned int V_192 )
{
int V_193 ;
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ )
F_78 ( V_190 , L_2 , ( unsigned int ) V_191 [ V_193 ] ) ;
F_79 ( V_190 , ' ' ) ;
}
static void F_80 ( struct V_189 * V_190 , unsigned char * V_191 , unsigned int V_192 )
{
int V_194 , V_195 , V_196 ;
F_78 ( V_190 , L_3 ) ;
V_194 = 0 ;
for ( V_195 = 0 ; V_195 < ( V_192 / 16 ) ; V_195 ++ ) {
F_77 ( V_190 , V_191 + V_194 , 16 ) ;
V_194 += 16 ;
}
V_196 = V_192 % 16 ;
if ( V_196 ) {
F_77 ( V_190 , V_191 + V_194 , V_196 ) ;
V_194 += V_196 ;
}
F_79 ( V_190 , '\n' ) ;
}
static void F_81 ( unsigned char * V_197 , struct V_189 * V_190 ,
unsigned char * V_191 , unsigned int V_192 )
{
int V_194 , V_198 , V_199 ;
F_78 ( V_190 , L_4 , V_197 ) ;
V_194 = 0 ;
for ( V_198 = 0 ; V_198 < ( V_192 / 64 ) ; V_198 ++ ) {
F_80 ( V_190 , V_191 + V_194 , 64 ) ;
V_194 += 64 ;
}
V_199 = V_192 % 64 ;
if ( V_199 ) {
F_80 ( V_190 , V_191 + V_194 , V_199 ) ;
V_194 += V_199 ;
}
F_79 ( V_190 , '\n' ) ;
}
static void F_82 ( unsigned char * V_197 , struct V_189 * V_190 ,
unsigned int * V_200 , unsigned int V_192 )
{
F_78 ( V_190 , L_4 , V_197 ) ;
F_83 ( V_190 , L_5 , V_201 , 32 , 4 , V_200 , V_192 , false ) ;
F_79 ( V_190 , '\n' ) ;
}
static int F_84 ( struct V_189 * V_190 , void * V_202 )
{
char V_203 [ sizeof( int ) * V_101 ] ;
F_78 ( V_190 , L_6 ,
V_204 , V_205 , V_206 ) ;
F_78 ( V_190 , L_7 , V_102 ) ;
F_78 ( V_190 , L_8 , V_115 ) ;
F_78 ( V_190 , L_9 , F_66 ( V_117 ) ) ;
F_78 ( V_190 , L_10 , F_66 ( V_119 ) ) ;
F_78 ( V_190 , L_11 ,
F_66 ( V_148 ) ) ;
F_78 ( V_190 , L_12 ,
F_66 ( V_150 ) ) ;
F_78 ( V_190 , L_13 , F_66 ( V_153 ) ) ;
F_78 ( V_190 , L_14 , F_66 ( V_155 ) ) ;
F_78 ( V_190 , L_15 , F_66 ( V_207 ) ) ;
F_78 ( V_190 , L_16 , F_66 ( V_208 ) ) ;
F_78 ( V_190 , L_17 , F_65 () ) ;
F_78 ( V_190 , L_18 , F_64 () ) ;
F_78 ( V_190 , L_19 ,
F_2 ( & V_17 ) ) ;
F_59 ( V_203 ) ;
F_81 ( L_20
L_21 ,
V_190 , V_203 , V_101 ) ;
F_60 ( V_203 ) ;
F_81 ( L_22 , V_190 , V_203 , V_101 ) ;
F_63 ( ( int * ) V_203 ) ;
F_82 ( L_23 ,
V_190 , ( unsigned int * ) V_203 , V_101 ) ;
return 0 ;
}
static int F_85 ( struct V_16 * V_16 , struct V_10 * V_10 )
{
return F_86 ( V_10 , F_84 , NULL ) ;
}
static void F_87 ( int V_209 )
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
static void F_89 ( int V_209 )
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
T_3 V_13 , T_4 * V_210 )
{
unsigned char * V_211 , * V_212 ;
T_3 V_213 ;
int V_214 ;
if ( V_13 <= 0 )
return 0 ;
#define F_91 1200UL
V_211 = F_92 ( F_91 , V_84 ) ;
if ( ! V_211 )
return 0 ;
V_213 = F_93 ( F_91 - 1 , V_13 ) ;
if ( F_52 ( V_211 , V_90 , V_213 ) != 0 ) {
F_55 ( V_211 ) ;
return - V_87 ;
}
V_211 [ V_213 ] = '\0' ;
V_212 = strstr ( V_211 , L_24 ) ;
if ( ! V_212 )
goto V_48;
V_212 = strstr ( V_212 , L_25 ) ;
if ( ! V_212 )
goto V_48;
V_212 ++ ;
if ( strstr ( V_212 , L_22 ) == NULL )
goto V_48;
for ( V_214 = 0 ; V_214 < 64 && * V_212 ; V_212 ++ ) {
if ( * V_212 >= '0' && * V_212 <= '8' )
V_214 ++ ;
else if ( * V_212 == 'd' || * V_212 == 'D' )
F_87 ( V_214 ++ ) ;
else if ( * V_212 == 'e' || * V_212 == 'E' )
F_89 ( V_214 ++ ) ;
else if ( * V_212 != ' ' && * V_212 != '\t' )
break;
}
V_48:
F_55 ( V_211 ) ;
return V_13 ;
}
static int F_94 ( struct V_215 * V_92 , T_5 * V_216 )
{
int V_42 ;
if ( V_217 == 0 ) {
V_42 = F_56 ( ( char * ) V_218 ) ;
if ( ( V_42 == - V_43 ) && ( F_1 () ) )
V_42 = F_56 ( ( char * ) V_218 ) ;
if ( V_42 < 0 )
return - V_219 ;
V_217 = V_42 / sizeof *V_216 ;
}
* V_216 = V_218 [ -- V_217 ] ;
return sizeof *V_216 ;
}
int F_95 ( void )
{
int V_42 = 0 ;
F_96 ( & V_220 ) ;
if ( V_221 == 0 ) {
V_218 = ( T_5 * ) F_97 ( V_84 ) ;
if ( ! V_218 ) {
V_42 = - V_85 ;
goto V_48;
}
V_217 = 0 ;
if ( ! V_222 )
V_223 . V_224 = 0 ;
V_42 = F_98 ( & V_223 ) ;
if ( V_42 )
goto V_88;
V_221 = 1 ;
} else
V_221 ++ ;
F_99 ( & V_220 ) ;
return 0 ;
V_88:
F_100 ( ( unsigned long ) V_218 ) ;
V_48:
F_99 ( & V_220 ) ;
return V_42 ;
}
void F_101 ( void )
{
F_96 ( & V_220 ) ;
V_221 -- ;
if ( V_221 == 0 ) {
F_102 ( & V_223 ) ;
F_100 ( ( unsigned long ) V_218 ) ;
}
F_99 ( & V_220 ) ;
}
int T_6 F_103 ( void )
{
V_225 = F_104 ( L_26 , 1 , 1 ,
V_226 * sizeof( long ) ) ;
F_105 ( V_225 , & V_227 ) ;
F_106 ( V_225 , V_228 ) ;
return 0 ;
}
void F_107 ( void )
{
F_108 ( V_225 ) ;
}
int T_6 F_109 ( void )
{
int V_42 ;
V_42 = F_103 () ;
if ( V_42 )
goto V_48;
F_3 ( & V_1 , 0 ) ;
V_42 = F_110 ( & V_229 ) ;
if ( V_42 < 0 )
goto V_48;
V_230 = F_111 ( L_27 , 0644 , NULL ,
& V_231 ) ;
if ( ! V_230 ) {
V_42 = - V_85 ;
goto V_232;
}
F_112 () ;
F_113 () ;
return 0 ;
V_232:
F_114 ( & V_229 ) ;
V_48:
return V_42 ;
}
void T_7 F_115 ( void )
{
F_116 ( L_27 , NULL ) ;
F_114 ( & V_229 ) ;
F_117 () ;
F_118 () ;
F_107 () ;
}
