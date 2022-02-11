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
F_7 ( V_10 , F_8 ( F_9 () , V_9 -> V_10 ) ) ;
F_10 ( V_11 , F_11 ( F_9 () , V_9 -> V_11 ) ) ;
if ( ! F_12 ( V_12 , V_7 , sizeof( struct V_6 ) ) ||
F_13 ( F_14 ( V_9 -> V_13 ) , & V_7 -> V_14 ) ||
F_13 ( V_9 -> V_15 , & V_7 -> V_16 ) ||
F_13 ( V_9 -> V_15 , & V_7 -> V_17 ) ||
F_13 ( V_9 -> V_18 , & V_7 -> V_19 ) ||
F_13 ( V_9 -> V_20 , & V_7 -> V_21 ) ||
F_13 ( V_10 , & V_7 -> V_22 ) ||
F_13 ( V_11 , & V_7 -> V_23 ) ||
F_13 ( F_14 ( V_9 -> V_24 ) , & V_7 -> V_25 ) ||
F_13 ( V_9 -> V_26 , & V_7 -> V_27 ) ||
F_13 ( V_9 -> V_28 . V_29 , & V_7 -> V_30 ) ||
F_13 ( V_9 -> V_28 . V_31 , & V_7 -> V_32 ) ||
F_13 ( V_9 -> V_33 . V_29 , & V_7 -> V_34 ) ||
F_13 ( V_9 -> V_33 . V_31 , & V_7 -> V_35 ) ||
F_13 ( V_9 -> ctime . V_29 , & V_7 -> V_36 ) ||
F_13 ( V_9 -> ctime . V_31 , & V_7 -> V_37 ) ||
F_13 ( V_9 -> V_38 , & V_7 -> V_39 ) ||
F_13 ( V_9 -> V_40 , & V_7 -> V_41 ) )
return - V_42 ;
return 0 ;
}
T_1 long F_15 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_16 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_17 ( const char T_2 * V_1 ,
struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_18 ( V_1 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_19 ( unsigned int V_5 , struct V_6 T_2 * V_43 )
{
struct V_8 V_9 ;
int V_44 = F_20 ( V_5 , & V_9 ) ;
if ( ! V_44 )
V_44 = F_5 ( V_43 , & V_9 ) ;
return V_44 ;
}
T_1 long F_21 ( unsigned int V_45 , const char T_2 * V_1 ,
struct V_6 T_2 * V_43 , int V_46 )
{
struct V_8 V_9 ;
int error ;
error = F_22 ( V_45 , V_1 , & V_9 , V_46 ) ;
if ( error )
return error ;
return F_5 ( V_43 , & V_9 ) ;
}
T_1 long F_23 ( struct V_47 T_2 * V_48 )
{
struct V_47 V_49 ;
if ( F_24 ( & V_49 , V_48 , sizeof( V_49 ) ) )
return - V_42 ;
if ( V_49 . V_50 & ~ V_51 )
return - V_52 ;
return F_25 ( V_49 . V_53 , V_49 . V_54 , V_49 . V_55 , V_49 . V_56 , V_49 . V_5 ,
V_49 . V_50 >> V_57 ) ;
}
T_1 long F_26 ( unsigned long V_58 , T_3 V_54 ,
unsigned long V_55 )
{
return F_27 ( V_58 , V_54 , V_55 ) ;
}
T_1 long F_28 ( int V_59 , struct V_60 T_2 * V_61 ,
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
if ( ! F_12 ( V_70 , V_61 , sizeof( * V_61 ) ) ||
F_29 ( V_68 , & V_61 -> V_71 ) ||
F_29 ( V_65 . V_72 . V_73 , & V_61 -> V_73 ) ||
F_29 ( V_69 , & V_61 -> V_74 ) ||
F_30 ( & V_67 , & V_61 -> V_75 ,
sizeof( T_4 ) ) )
return - V_42 ;
V_65 . V_72 . V_71 = F_31 ( V_68 ) ;
V_65 . V_72 . V_74 = F_31 ( V_69 ) ;
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
V_44 = F_32 ( V_59 , V_61 ? & V_65 : NULL , V_62 ? & V_66 : NULL ) ;
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
if ( ! F_12 ( V_12 , V_62 , sizeof( * V_62 ) ) ||
F_13 ( F_33 ( V_66 . V_72 . V_71 ) ,
& V_62 -> V_71 ) ||
F_13 ( F_33 ( V_66 . V_72 . V_74 ) ,
& V_62 -> V_74 ) ||
F_13 ( V_66 . V_72 . V_73 , & V_62 -> V_73 ) ||
F_34 ( & V_62 -> V_75 , & V_67 ,
sizeof( T_4 ) ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_35 ( int V_59 , struct V_77 T_2 * V_61 ,
struct V_77 T_2 * V_62 )
{
struct V_64 V_65 , V_66 ;
int V_44 ;
if ( V_61 ) {
T_6 V_78 ;
T_5 V_68 , V_69 ;
if ( ! F_12 ( V_70 , V_61 , sizeof( * V_61 ) ) ||
F_29 ( V_68 , & V_61 -> V_71 ) ||
F_29 ( V_65 . V_72 . V_73 , & V_61 -> V_73 ) ||
F_29 ( V_69 , & V_61 -> V_74 ) ||
F_29 ( V_78 , & V_61 -> V_75 ) )
return - V_42 ;
V_65 . V_72 . V_71 = F_31 ( V_68 ) ;
V_65 . V_72 . V_74 = F_31 ( V_69 ) ;
F_36 ( & V_65 . V_72 . V_75 , V_78 ) ;
}
V_44 = F_32 ( V_59 , V_61 ? & V_65 : NULL , V_62 ? & V_66 : NULL ) ;
if ( ! V_44 && V_62 ) {
if ( ! F_12 ( V_12 , V_62 , sizeof( * V_62 ) ) ||
F_13 ( F_33 ( V_66 . V_72 . V_71 ) ,
& V_62 -> V_71 ) ||
F_13 ( F_33 ( V_66 . V_72 . V_74 ) ,
& V_62 -> V_74 ) ||
F_13 ( V_66 . V_72 . V_73 , & V_62 -> V_73 ) ||
F_13 ( V_66 . V_72 . V_75 . V_59 [ 0 ] , & V_62 -> V_75 ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_37 ( T_7 V_79 , unsigned int T_2 * V_80 ,
int V_81 )
{
return F_38 ( V_79 , V_80 , V_81 , NULL ) ;
}
T_1 long F_39 ( T_7 V_79 ,
struct V_82 T_2 * V_83 )
{
struct V_84 V_85 ;
int V_44 ;
T_8 V_86 = F_40 () ;
F_41 ( V_87 ) ;
V_44 = F_42 ( V_79 , (struct V_84 T_2 * ) & V_85 ) ;
F_41 ( V_86 ) ;
if ( F_43 ( & V_85 , V_83 ) )
return - V_42 ;
return V_44 ;
}
T_1 long F_44 ( T_4 T_2 * V_88 ,
T_9 V_63 )
{
T_10 V_89 ;
T_4 V_90 ;
int V_44 ;
T_8 V_86 = F_40 () ;
F_41 ( V_87 ) ;
V_44 = F_45 ( ( T_10 T_2 * ) & V_89 , V_63 ) ;
F_41 ( V_86 ) ;
if ( ! V_44 ) {
switch ( V_76 ) {
case 4 : V_90 . V_59 [ 7 ] = ( V_89 . V_59 [ 3 ] >> 32 ) ; V_90 . V_59 [ 6 ] = V_89 . V_59 [ 3 ] ;
case 3 : V_90 . V_59 [ 5 ] = ( V_89 . V_59 [ 2 ] >> 32 ) ; V_90 . V_59 [ 4 ] = V_89 . V_59 [ 2 ] ;
case 2 : V_90 . V_59 [ 3 ] = ( V_89 . V_59 [ 1 ] >> 32 ) ; V_90 . V_59 [ 2 ] = V_89 . V_59 [ 1 ] ;
case 1 : V_90 . V_59 [ 1 ] = ( V_89 . V_59 [ 0 ] >> 32 ) ; V_90 . V_59 [ 0 ] = V_89 . V_59 [ 0 ] ;
}
if ( F_46 ( V_88 , & V_90 , sizeof( T_4 ) ) )
return - V_42 ;
}
return V_44 ;
}
T_1 long F_47 ( int V_79 , int V_59 ,
T_11 T_2 * V_91 )
{
T_12 V_92 ;
int V_44 ;
T_8 V_86 = F_40 () ;
if ( F_48 ( & V_92 , V_91 ) )
return - V_42 ;
F_41 ( V_87 ) ;
V_44 = F_49 ( V_79 , V_59 , ( T_12 T_2 * ) & V_92 ) ;
F_41 ( V_86 ) ;
return V_44 ;
}
T_1 long F_50 ( unsigned int V_5 , char T_2 * V_7 , T_13 V_93 ,
T_13 V_94 , T_13 V_95 )
{
return F_51 ( V_5 , V_7 , V_93 ,
( ( V_4 ) F_52 ( V_95 ) << 32 ) | F_52 ( V_94 ) ) ;
}
T_1 long F_53 ( unsigned int V_5 , const char T_2 * V_7 ,
T_13 V_93 , T_13 V_94 , T_13 V_95 )
{
return F_54 ( V_5 , V_7 , V_93 ,
( ( V_4 ) F_52 ( V_95 ) << 32 ) | F_52 ( V_94 ) ) ;
}
T_1 long F_55 ( int V_96 , int V_97 ,
T_14 T_2 * V_50 , V_90 V_93 )
{
T_8 V_86 = F_40 () ;
int V_44 ;
T_15 V_98 ;
if ( V_50 && F_56 ( V_98 , V_50 ) )
return - V_42 ;
F_41 ( V_87 ) ;
V_44 = F_57 ( V_96 , V_97 , V_50 ? ( T_15 T_2 * ) & V_98 : NULL ,
V_93 ) ;
F_41 ( V_86 ) ;
if ( V_50 && F_58 ( V_98 , V_50 ) )
return - V_42 ;
return V_44 ;
}
long F_59 ( unsigned int V_5 , int V_50 , unsigned int V_99 )
{
return F_60 ( V_5 , V_50 , V_99 ) ;
}
long F_61 ( int V_79 , int V_59 )
{
return F_62 ( V_79 , V_59 ) ;
}
long F_63 ( int V_5 , T_16 V_2 , T_16 V_3 ,
T_16 V_100 , T_16 V_101 , int V_102 )
{
return F_64 ( V_5 ,
( ( ( V_103 ) V_3 ) << 32 ) | V_2 ,
( ( ( V_103 ) V_101 ) << 32 ) | V_100 ,
V_102 ) ;
}
long F_65 ( void )
{
struct V_104 * V_105 = V_106 ;
static char V_107 [ sizeof( V_105 -> V_108 ) ] ;
if ( strncmp ( V_107 , V_105 -> V_108 , sizeof( V_107 ) ) ) {
F_66 ( V_109
L_1 ,
V_105 -> V_108 ) ;
strncpy ( V_107 , V_105 -> V_108 , sizeof( V_107 ) ) ;
}
return - V_110 ;
}
long F_67 ( T_13 V_111 , T_13 V_112 ,
char T_2 * V_113 , T_3 V_54 )
{
return F_68 ( ( ( V_103 ) V_112 << 32 ) | V_111 , V_113 , V_54 ) ;
}
T_1 T_17 F_69 ( int V_5 , unsigned V_114 , unsigned V_115 ,
T_3 V_93 )
{
return F_70 ( V_5 , ( ( V_103 ) V_115 << 32 ) | V_114 , V_93 ) ;
}
T_1 long F_71 ( int V_5 , unsigned V_116 , unsigned V_115 ,
unsigned V_117 , unsigned V_118 , int V_56 )
{
return F_72 ( V_5 ,
( ( V_103 ) V_115 << 32 ) | V_116 ,
( ( V_103 ) V_118 << 32 ) | V_117 , V_56 ) ;
}
T_1 long F_73 ( int V_5 , unsigned V_119 , unsigned V_120 ,
T_3 V_54 , int V_102 )
{
return F_64 ( V_5 , ( ( V_103 ) V_120 << 32 ) | V_119 ,
V_54 , V_102 ) ;
}
T_1 long F_74 ( int V_5 , int V_18 , unsigned V_119 ,
unsigned V_120 , unsigned V_121 ,
unsigned V_122 )
{
return F_75 ( V_5 , V_18 , ( ( V_103 ) V_120 << 32 ) | V_119 ,
( ( V_103 ) V_122 << 32 ) | V_121 ) ;
}
T_1 long F_76 ( int V_123 , unsigned int V_56 ,
T_13 V_124 , T_13 V_125 ,
int V_5 , const char T_2 * V_126 )
{
return F_77 ( V_123 , V_56 ,
( ( V_103 ) V_125 << 32 ) | V_124 ,
V_5 , V_126 ) ;
}
