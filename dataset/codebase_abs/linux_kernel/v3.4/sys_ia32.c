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
T_1 long F_34 ( unsigned int V_79 )
{
return F_35 ( V_79 ) ;
}
T_1 long F_36 ( T_7 V_80 , unsigned int * V_81 ,
int V_82 )
{
return F_37 ( V_80 , V_81 , V_82 , NULL ) ;
}
T_1 long F_38 ( int V_83 , T_8 V_84 , T_8 V_85 )
{
return F_39 ( V_83 , V_84 , V_85 ) ;
}
T_1 long F_40 ( T_7 V_80 ,
struct V_86 T_2 * V_87 )
{
struct V_88 V_89 ;
int V_44 ;
T_9 V_90 = F_41 () ;
F_42 ( V_91 ) ;
V_44 = F_43 ( V_80 , (struct V_88 T_2 * ) & V_89 ) ;
F_42 ( V_90 ) ;
if ( F_44 ( & V_89 , V_87 ) )
return - V_42 ;
return V_44 ;
}
T_1 long F_45 ( T_4 T_2 * V_92 ,
T_10 V_63 )
{
T_11 V_93 ;
T_4 V_94 ;
int V_44 ;
T_9 V_90 = F_41 () ;
F_42 ( V_91 ) ;
V_44 = F_46 ( ( T_11 T_2 * ) & V_93 , V_63 ) ;
F_42 ( V_90 ) ;
if ( ! V_44 ) {
switch ( V_76 ) {
case 4 : V_94 . V_59 [ 7 ] = ( V_93 . V_59 [ 3 ] >> 32 ) ; V_94 . V_59 [ 6 ] = V_93 . V_59 [ 3 ] ;
case 3 : V_94 . V_59 [ 5 ] = ( V_93 . V_59 [ 2 ] >> 32 ) ; V_94 . V_59 [ 4 ] = V_93 . V_59 [ 2 ] ;
case 2 : V_94 . V_59 [ 3 ] = ( V_93 . V_59 [ 1 ] >> 32 ) ; V_94 . V_59 [ 2 ] = V_93 . V_59 [ 1 ] ;
case 1 : V_94 . V_59 [ 1 ] = ( V_93 . V_59 [ 0 ] >> 32 ) ; V_94 . V_59 [ 0 ] = V_93 . V_59 [ 0 ] ;
}
if ( F_47 ( V_92 , & V_94 , sizeof( T_4 ) ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_48 ( int V_80 , int V_59 ,
T_12 T_2 * V_95 )
{
T_13 V_96 ;
int V_44 ;
T_9 V_90 = F_41 () ;
if ( F_49 ( & V_96 , V_95 ) )
return - V_42 ;
F_42 ( V_91 ) ;
V_44 = F_50 ( V_80 , V_59 , ( T_13 T_2 * ) & V_96 ) ;
F_42 ( V_90 ) ;
return V_44 ;
}
T_1 long F_51 ( unsigned int V_5 , char T_2 * V_7 , T_8 V_97 ,
T_8 V_98 , T_8 V_99 )
{
return F_52 ( V_5 , V_7 , V_97 ,
( ( V_4 ) F_53 ( V_99 ) << 32 ) | F_53 ( V_98 ) ) ;
}
T_1 long F_54 ( unsigned int V_5 , const char T_2 * V_7 ,
T_8 V_97 , T_8 V_98 , T_8 V_99 )
{
return F_55 ( V_5 , V_7 , V_97 ,
( ( V_4 ) F_53 ( V_99 ) << 32 ) | F_53 ( V_98 ) ) ;
}
T_1 long F_56 ( unsigned long V_100 )
{
int V_44 ;
if ( V_100 ( V_101 -> V_100 ) == V_102 &&
V_100 == V_103 )
V_100 = V_102 ;
V_44 = F_57 ( V_100 ) ;
if ( V_44 == V_102 )
V_44 = V_103 ;
return V_44 ;
}
T_1 long F_58 ( int V_104 , int V_105 ,
T_14 T_2 * V_50 , V_94 V_97 )
{
T_9 V_90 = F_41 () ;
int V_44 ;
T_15 V_106 ;
if ( V_50 && F_59 ( V_106 , V_50 ) )
return - V_42 ;
F_42 ( V_91 ) ;
V_44 = F_60 ( V_104 , V_105 , V_50 ? ( T_15 T_2 * ) & V_106 : NULL ,
V_97 ) ;
F_42 ( V_90 ) ;
if ( V_50 && F_61 ( V_106 , V_50 ) )
return - V_42 ;
return V_44 ;
}
T_1 long F_62 ( const char T_2 * V_107 , T_5 T_2 * V_108 ,
T_5 T_2 * V_109 , struct V_110 * V_111 )
{
long error ;
char * V_1 ;
V_1 = F_63 ( V_107 ) ;
error = F_64 ( V_1 ) ;
if ( F_65 ( V_1 ) )
return error ;
error = F_66 ( V_1 , V_108 , V_109 , V_111 ) ;
F_67 ( V_1 ) ;
return error ;
}
T_1 long F_68 ( unsigned int V_112 , unsigned int V_113 ,
struct V_110 * V_111 )
{
void T_2 * V_114 = ( void T_2 * ) V_111 -> V_115 ;
void T_2 * V_116 = ( void T_2 * ) V_111 -> V_117 ;
if ( ! V_113 )
V_113 = V_111 -> V_118 ;
return F_69 ( V_112 , V_113 , V_111 , 0 , V_114 , V_116 ) ;
}
long F_70 ( unsigned int V_5 , int V_50 , unsigned int V_119 )
{
return F_71 ( V_5 , V_50 , V_119 ) ;
}
long F_72 ( int V_80 , int V_59 )
{
return F_73 ( V_80 , V_59 ) ;
}
long F_74 ( int V_5 , T_16 V_2 , T_16 V_3 ,
T_16 V_120 , T_16 V_121 , int V_122 )
{
return F_75 ( V_5 ,
( ( ( V_123 ) V_3 ) << 32 ) | V_2 ,
( ( ( V_123 ) V_121 ) << 32 ) | V_120 ,
V_122 ) ;
}
long F_76 ( void )
{
struct V_124 * V_125 = V_101 ;
static char V_126 [ sizeof( V_125 -> V_127 ) ] ;
if ( strncmp ( V_126 , V_125 -> V_127 , sizeof( V_126 ) ) ) {
F_77 ( V_128
L_1 ,
V_125 -> V_127 ) ;
strncpy ( V_126 , V_125 -> V_127 , sizeof( V_126 ) ) ;
}
return - V_129 ;
}
long F_78 ( T_8 V_130 , T_8 V_131 ,
char T_2 * V_132 , T_3 V_54 )
{
return F_79 ( ( ( V_123 ) V_131 << 32 ) | V_130 , V_132 , V_54 ) ;
}
T_1 T_17 F_80 ( int V_5 , unsigned V_133 , unsigned V_134 ,
T_3 V_97 )
{
return F_81 ( V_5 , ( ( V_123 ) V_134 << 32 ) | V_133 , V_97 ) ;
}
T_1 long F_82 ( int V_5 , unsigned V_135 , unsigned V_134 ,
unsigned V_136 , unsigned V_137 , int V_56 )
{
return F_83 ( V_5 ,
( ( V_123 ) V_134 << 32 ) | V_135 ,
( ( V_123 ) V_137 << 32 ) | V_136 , V_56 ) ;
}
T_1 long F_84 ( int V_5 , unsigned V_138 , unsigned V_139 ,
T_3 V_54 , int V_122 )
{
return F_75 ( V_5 , ( ( V_123 ) V_139 << 32 ) | V_138 ,
V_54 , V_122 ) ;
}
T_1 long F_85 ( int V_5 , int V_18 , unsigned V_138 ,
unsigned V_139 , unsigned V_140 ,
unsigned V_141 )
{
return F_86 ( V_5 , V_18 , ( ( V_123 ) V_139 << 32 ) | V_138 ,
( ( V_123 ) V_141 << 32 ) | V_140 ) ;
}
T_1 long F_87 ( int V_142 , unsigned int V_56 ,
T_8 V_143 , T_8 V_144 ,
int V_5 , const char T_2 * V_145 )
{
return F_88 ( V_142 , V_56 ,
( ( V_123 ) V_144 << 32 ) | V_143 ,
V_5 , V_145 ) ;
}
