T_1 long F_1 ( const char T_2 * V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
return F_2 ( V_1 , ( ( V_4 ) V_3 << 32 ) | V_2 ) ;
}
T_1 long F_3 ( unsigned int V_5 , unsigned long V_2 ,
unsigned long V_3 )
{
return F_4 ( V_5 , ( ( V_4 ) V_3 << 32 ) | V_2 ) ;
}
static int F_5 ( struct V_6 T_2 * V_7 , struct V_8 * V_9 )
{
F_6 (ubuf->st_uid) V_10 = 0 ;
F_6 (ubuf->st_gid) V_11 = 0 ;
F_7 ( V_10 , V_9 -> V_10 ) ;
F_8 ( V_11 , V_9 -> V_11 ) ;
if ( ! F_9 ( V_12 , V_7 , sizeof( struct V_6 ) ) ||
F_10 ( F_11 ( V_9 -> V_13 ) , & V_7 -> V_14 ) ||
F_10 ( V_9 -> V_15 , & V_7 -> V_16 ) ||
F_10 ( V_9 -> V_15 , & V_7 -> V_17 ) ||
F_10 ( V_9 -> V_18 , & V_7 -> V_19 ) ||
F_10 ( V_9 -> V_20 , & V_7 -> V_21 ) ||
F_10 ( V_10 , & V_7 -> V_22 ) ||
F_10 ( V_11 , & V_7 -> V_23 ) ||
F_10 ( F_11 ( V_9 -> V_24 ) , & V_7 -> V_25 ) ||
F_10 ( V_9 -> V_26 , & V_7 -> V_27 ) ||
F_10 ( V_9 -> V_28 . V_29 , & V_7 -> V_30 ) ||
F_10 ( V_9 -> V_28 . V_31 , & V_7 -> V_32 ) ||
F_10 ( V_9 -> V_33 . V_29 , & V_7 -> V_34 ) ||
F_10 ( V_9 -> V_33 . V_31 , & V_7 -> V_35 ) ||
F_10 ( V_9 -> ctime . V_29 , & V_7 -> V_36 ) ||
F_10 ( V_9 -> ctime . V_31 , & V_7 -> V_37 ) ||
F_10 ( V_9 -> V_38 , & V_7 -> V_39 ) ||
F_10 ( V_9 -> V_40 , & V_7 -> V_41 ) )
return - V_42 ;
return 0 ;
}
T_1 long F_12 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_13 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_14 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_15 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_16 ( unsigned int V_5 , struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_17 ( V_5 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_18 ( unsigned int V_45 , const char T_2 * V_1 ,
struct V_6 T_2 * V_43 , int V_46 )
{
struct V_8 V_9 ;
int error ;
error = F_19 ( V_45 , V_1 , & V_9 , V_46 ) ;
if ( error )
return error ;
return F_5 ( V_43 , & V_9 ) ;
}
T_1 long F_20 ( struct V_47 T_2 * V_48 )
{
struct V_47 V_49 ;
if ( F_21 ( & V_49 , V_48 , sizeof( V_49 ) ) )
return - V_42 ;
if ( V_49 . V_50 & ~ V_51 )
return - V_52 ;
return F_22 ( V_49 . V_53 , V_49 . V_54 , V_49 . V_55 , V_49 . V_56 , V_49 . V_5 ,
V_49 . V_50 >> V_57 ) ;
}
T_1 long F_23 ( unsigned long V_58 , T_3 V_54 ,
unsigned long V_55 )
{
return F_24 ( V_58 , V_54 , V_55 ) ;
}
T_1 long F_25 ( int V_59 , struct V_60 T_2 * V_61 ,
struct V_60 T_2 * V_62 ,
unsigned int V_63 )
{
struct V_64 V_65 , V_66 ;
int V_44 ;
T_4 V_67 ;
if ( V_63 != sizeof( T_4 ) )
return - V_52 ;
if ( V_61 ) {
T_5 V_68 , V_69 ;
if ( ! F_9 ( V_70 , V_61 , sizeof( * V_61 ) ) ||
F_26 ( V_68 , & V_61 -> V_71 ) ||
F_26 ( V_65 . V_72 . V_73 , & V_61 -> V_73 ) ||
F_26 ( V_69 , & V_61 -> V_74 ) ||
F_27 ( & V_67 , & V_61 -> V_75 ,
sizeof( T_4 ) ) )
return - V_42 ;
V_65 . V_72 . V_71 = F_28 ( V_68 ) ;
V_65 . V_72 . V_74 = F_28 ( V_69 ) ;
switch ( V_76 ) {
case 4 : V_65 . V_72 . V_75 . V_59 [ 3 ] = V_67 . V_59 [ 6 ]
| ( ( ( long ) V_67 . V_59 [ 7 ] ) << 32 ) ;
case 3 : V_65 . V_72 . V_75 . V_59 [ 2 ] = V_67 . V_59 [ 4 ]
| ( ( ( long ) V_67 . V_59 [ 5 ] ) << 32 ) ;
case 2 : V_65 . V_72 . V_75 . V_59 [ 1 ] = V_67 . V_59 [ 2 ]
| ( ( ( long ) V_67 . V_59 [ 3 ] ) << 32 ) ;
case 1 : V_65 . V_72 . V_75 . V_59 [ 0 ] = V_67 . V_59 [ 0 ]
| ( ( ( long ) V_67 . V_59 [ 1 ] ) << 32 ) ;
}
}
V_44 = F_29 ( V_59 , V_61 ? & V_65 : NULL , V_62 ? & V_66 : NULL ) ;
if ( ! V_44 && V_62 ) {
switch ( V_76 ) {
case 4 :
V_67 . V_59 [ 7 ] = ( V_66 . V_72 . V_75 . V_59 [ 3 ] >> 32 ) ;
V_67 . V_59 [ 6 ] = V_66 . V_72 . V_75 . V_59 [ 3 ] ;
case 3 :
V_67 . V_59 [ 5 ] = ( V_66 . V_72 . V_75 . V_59 [ 2 ] >> 32 ) ;
V_67 . V_59 [ 4 ] = V_66 . V_72 . V_75 . V_59 [ 2 ] ;
case 2 :
V_67 . V_59 [ 3 ] = ( V_66 . V_72 . V_75 . V_59 [ 1 ] >> 32 ) ;
V_67 . V_59 [ 2 ] = V_66 . V_72 . V_75 . V_59 [ 1 ] ;
case 1 :
V_67 . V_59 [ 1 ] = ( V_66 . V_72 . V_75 . V_59 [ 0 ] >> 32 ) ;
V_67 . V_59 [ 0 ] = V_66 . V_72 . V_75 . V_59 [ 0 ] ;
}
if ( ! F_9 ( V_12 , V_62 , sizeof( * V_62 ) ) ||
F_10 ( F_30 ( V_66 . V_72 . V_71 ) ,
& V_62 -> V_71 ) ||
F_10 ( F_30 ( V_66 . V_72 . V_74 ) ,
& V_62 -> V_74 ) ||
F_10 ( V_66 . V_72 . V_73 , & V_62 -> V_73 ) ||
F_31 ( & V_62 -> V_75 , & V_67 ,
sizeof( T_4 ) ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_32 ( int V_59 , struct V_77 T_2 * V_61 ,
struct V_77 T_2 * V_62 )
{
struct V_64 V_65 , V_66 ;
int V_44 ;
if ( V_61 ) {
T_6 V_78 ;
T_5 V_68 , V_69 ;
if ( ! F_9 ( V_70 , V_61 , sizeof( * V_61 ) ) ||
F_26 ( V_68 , & V_61 -> V_71 ) ||
F_26 ( V_65 . V_72 . V_73 , & V_61 -> V_73 ) ||
F_26 ( V_69 , & V_61 -> V_74 ) ||
F_26 ( V_78 , & V_61 -> V_75 ) )
return - V_42 ;
V_65 . V_72 . V_71 = F_28 ( V_68 ) ;
V_65 . V_72 . V_74 = F_28 ( V_69 ) ;
F_33 ( & V_65 . V_72 . V_75 , V_78 ) ;
}
V_44 = F_29 ( V_59 , V_61 ? & V_65 : NULL , V_62 ? & V_66 : NULL ) ;
if ( ! V_44 && V_62 ) {
if ( ! F_9 ( V_12 , V_62 , sizeof( * V_62 ) ) ||
F_10 ( F_30 ( V_66 . V_72 . V_71 ) ,
& V_62 -> V_71 ) ||
F_10 ( F_30 ( V_66 . V_72 . V_74 ) ,
& V_62 -> V_74 ) ||
F_10 ( V_66 . V_72 . V_73 , & V_62 -> V_73 ) ||
F_10 ( V_66 . V_72 . V_75 . V_59 [ 0 ] , & V_62 -> V_75 ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_34 ( int V_79 , T_4 T_2 * V_80 ,
T_4 T_2 * V_81 ,
unsigned int V_63 )
{
T_7 V_82 ;
T_4 V_83 ;
int V_44 ;
T_8 V_84 = F_35 () ;
if ( V_80 ) {
if ( F_21 ( & V_83 , V_80 , sizeof( T_4 ) ) )
return - V_42 ;
switch ( V_76 ) {
case 4 : V_82 . V_59 [ 3 ] = V_83 . V_59 [ 6 ] | ( ( ( long ) V_83 . V_59 [ 7 ] ) << 32 ) ;
case 3 : V_82 . V_59 [ 2 ] = V_83 . V_59 [ 4 ] | ( ( ( long ) V_83 . V_59 [ 5 ] ) << 32 ) ;
case 2 : V_82 . V_59 [ 1 ] = V_83 . V_59 [ 2 ] | ( ( ( long ) V_83 . V_59 [ 3 ] ) << 32 ) ;
case 1 : V_82 . V_59 [ 0 ] = V_83 . V_59 [ 0 ] | ( ( ( long ) V_83 . V_59 [ 1 ] ) << 32 ) ;
}
}
F_36 ( V_85 ) ;
V_44 = F_37 ( V_79 ,
V_80 ? ( T_7 T_2 * ) & V_82 : NULL ,
V_81 ? ( T_7 T_2 * ) & V_82 : NULL ,
V_63 ) ;
F_36 ( V_84 ) ;
if ( V_44 )
return V_44 ;
if ( V_81 ) {
switch ( V_76 ) {
case 4 : V_83 . V_59 [ 7 ] = ( V_82 . V_59 [ 3 ] >> 32 ) ; V_83 . V_59 [ 6 ] = V_82 . V_59 [ 3 ] ;
case 3 : V_83 . V_59 [ 5 ] = ( V_82 . V_59 [ 2 ] >> 32 ) ; V_83 . V_59 [ 4 ] = V_82 . V_59 [ 2 ] ;
case 2 : V_83 . V_59 [ 3 ] = ( V_82 . V_59 [ 1 ] >> 32 ) ; V_83 . V_59 [ 2 ] = V_82 . V_59 [ 1 ] ;
case 1 : V_83 . V_59 [ 1 ] = ( V_82 . V_59 [ 0 ] >> 32 ) ; V_83 . V_59 [ 0 ] = V_82 . V_59 [ 0 ] ;
}
if ( F_38 ( V_81 , & V_83 , sizeof( T_4 ) ) )
return - V_42 ;
}
return 0 ;
}
T_1 long F_39 ( unsigned int V_86 )
{
return F_40 ( V_86 ) ;
}
T_1 long F_41 ( T_9 V_87 , unsigned int * V_88 ,
int V_89 )
{
return F_42 ( V_87 , V_88 , V_89 , NULL ) ;
}
T_1 long F_43 ( int V_90 , T_10 V_91 , T_10 V_92 )
{
return F_44 ( V_90 , V_91 , V_92 ) ;
}
T_1 long F_45 ( T_9 V_87 ,
struct V_93 T_2 * V_94 )
{
struct V_95 V_96 ;
int V_44 ;
T_8 V_84 = F_35 () ;
F_36 ( V_85 ) ;
V_44 = F_46 ( V_87 , (struct V_95 T_2 * ) & V_96 ) ;
F_36 ( V_84 ) ;
if ( F_47 ( & V_96 , V_94 ) )
return - V_42 ;
return V_44 ;
}
T_1 long F_48 ( T_4 T_2 * V_80 ,
T_11 V_63 )
{
T_7 V_82 ;
T_4 V_83 ;
int V_44 ;
T_8 V_84 = F_35 () ;
F_36 ( V_85 ) ;
V_44 = F_49 ( ( T_7 T_2 * ) & V_82 , V_63 ) ;
F_36 ( V_84 ) ;
if ( ! V_44 ) {
switch ( V_76 ) {
case 4 : V_83 . V_59 [ 7 ] = ( V_82 . V_59 [ 3 ] >> 32 ) ; V_83 . V_59 [ 6 ] = V_82 . V_59 [ 3 ] ;
case 3 : V_83 . V_59 [ 5 ] = ( V_82 . V_59 [ 2 ] >> 32 ) ; V_83 . V_59 [ 4 ] = V_82 . V_59 [ 2 ] ;
case 2 : V_83 . V_59 [ 3 ] = ( V_82 . V_59 [ 1 ] >> 32 ) ; V_83 . V_59 [ 2 ] = V_82 . V_59 [ 1 ] ;
case 1 : V_83 . V_59 [ 1 ] = ( V_82 . V_59 [ 0 ] >> 32 ) ; V_83 . V_59 [ 0 ] = V_82 . V_59 [ 0 ] ;
}
if ( F_38 ( V_80 , & V_83 , sizeof( T_4 ) ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_50 ( int V_87 , int V_59 ,
T_12 T_2 * V_97 )
{
T_13 V_98 ;
int V_44 ;
T_8 V_84 = F_35 () ;
if ( F_51 ( & V_98 , V_97 ) )
return - V_42 ;
F_36 ( V_85 ) ;
V_44 = F_52 ( V_87 , V_59 , ( T_13 T_2 * ) & V_98 ) ;
F_36 ( V_84 ) ;
return V_44 ;
}
T_1 long F_53 ( unsigned int V_5 , char T_2 * V_7 , T_10 V_99 ,
T_10 V_100 , T_10 V_101 )
{
return F_54 ( V_5 , V_7 , V_99 ,
( ( V_4 ) F_55 ( V_101 ) << 32 ) | F_55 ( V_100 ) ) ;
}
T_1 long F_56 ( unsigned int V_5 , const char T_2 * V_7 ,
T_10 V_99 , T_10 V_100 , T_10 V_101 )
{
return F_57 ( V_5 , V_7 , V_99 ,
( ( V_4 ) F_55 ( V_101 ) << 32 ) | F_55 ( V_100 ) ) ;
}
T_1 long F_58 ( unsigned long V_102 )
{
int V_44 ;
if ( V_102 ( V_103 -> V_102 ) == V_104 &&
V_102 == V_105 )
V_102 = V_104 ;
V_44 = F_59 ( V_102 ) ;
if ( V_44 == V_104 )
V_44 = V_105 ;
return V_44 ;
}
T_1 long F_60 ( int V_106 , int V_107 ,
T_14 T_2 * V_50 , V_83 V_99 )
{
T_8 V_84 = F_35 () ;
int V_44 ;
T_15 V_108 ;
if ( V_50 && F_61 ( V_108 , V_50 ) )
return - V_42 ;
F_36 ( V_85 ) ;
V_44 = F_62 ( V_106 , V_107 , V_50 ? ( T_15 T_2 * ) & V_108 : NULL ,
V_99 ) ;
F_36 ( V_84 ) ;
if ( V_50 && F_63 ( V_108 , V_50 ) )
return - V_42 ;
return V_44 ;
}
T_1 long F_64 ( const char T_2 * V_109 , T_5 T_2 * V_110 ,
T_5 T_2 * V_111 , struct V_112 * V_113 )
{
long error ;
char * V_1 ;
V_1 = F_65 ( V_109 ) ;
error = F_66 ( V_1 ) ;
if ( F_67 ( V_1 ) )
return error ;
error = F_68 ( V_1 , V_110 , V_111 , V_113 ) ;
F_69 ( V_1 ) ;
return error ;
}
T_1 long F_70 ( unsigned int V_114 , unsigned int V_115 ,
struct V_112 * V_113 )
{
void T_2 * V_116 = ( void T_2 * ) V_113 -> V_117 ;
void T_2 * V_118 = ( void T_2 * ) V_113 -> V_119 ;
if ( ! V_115 )
V_115 = V_113 -> V_120 ;
return F_71 ( V_114 , V_115 , V_113 , 0 , V_116 , V_118 ) ;
}
long F_72 ( unsigned int V_5 , int V_50 , unsigned int V_121 )
{
return F_73 ( V_5 , V_50 , V_121 ) ;
}
long F_74 ( int V_87 , int V_59 )
{
return F_75 ( V_87 , V_59 ) ;
}
long F_76 ( int V_5 , T_16 V_2 , T_16 V_3 ,
T_16 V_122 , T_16 V_123 , int V_124 )
{
return F_77 ( V_5 ,
( ( ( V_125 ) V_3 ) << 32 ) | V_2 ,
( ( ( V_125 ) V_123 ) << 32 ) | V_122 ,
V_124 ) ;
}
long F_78 ( void )
{
struct V_126 * V_127 = V_103 ;
static char V_128 [ sizeof( V_127 -> V_129 ) ] ;
if ( strncmp ( V_128 , V_127 -> V_129 , sizeof( V_128 ) ) ) {
F_79 ( V_130
L_1 ,
V_127 -> V_129 ) ;
strncpy ( V_128 , V_127 -> V_129 , sizeof( V_128 ) ) ;
}
return - V_131 ;
}
long F_80 ( T_10 V_132 , T_10 V_133 ,
char T_2 * V_134 , T_3 V_54 )
{
return F_81 ( ( ( V_125 ) V_133 << 32 ) | V_132 , V_134 , V_54 ) ;
}
T_1 T_17 F_82 ( int V_5 , unsigned V_135 , unsigned V_136 ,
T_3 V_99 )
{
return F_83 ( V_5 , ( ( V_125 ) V_136 << 32 ) | V_135 , V_99 ) ;
}
T_1 long F_84 ( int V_5 , unsigned V_137 , unsigned V_136 ,
unsigned V_138 , unsigned V_139 , int V_56 )
{
return F_85 ( V_5 ,
( ( V_125 ) V_136 << 32 ) | V_137 ,
( ( V_125 ) V_139 << 32 ) | V_138 , V_56 ) ;
}
T_1 long F_86 ( int V_5 , unsigned V_140 , unsigned V_141 ,
T_3 V_54 , int V_124 )
{
return F_77 ( V_5 , ( ( V_125 ) V_141 << 32 ) | V_140 ,
V_54 , V_124 ) ;
}
T_1 long F_87 ( int V_5 , int V_18 , unsigned V_140 ,
unsigned V_141 , unsigned V_142 ,
unsigned V_143 )
{
return F_88 ( V_5 , V_18 , ( ( V_125 ) V_141 << 32 ) | V_140 ,
( ( V_125 ) V_143 << 32 ) | V_142 ) ;
}
T_1 long F_89 ( int V_144 , unsigned int V_56 ,
T_10 V_145 , T_10 V_146 ,
int V_5 , const char T_2 * V_147 )
{
return F_90 ( V_144 , V_56 ,
( ( V_125 ) V_146 << 32 ) | V_145 ,
V_5 , V_147 ) ;
}
