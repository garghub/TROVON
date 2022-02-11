T_1 long F_1 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_2 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_5 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_6 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_7 ( unsigned int V_4 , T_3 V_2 , T_3 V_3 )
{
return F_8 ( V_4 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_9 ( T_3 V_5 , T_3 V_6 )
{
return F_10 ( F_4 ( V_5 ) , F_4 ( V_6 ) ) ;
}
T_1 long F_11 ( T_3 V_7 )
{
return F_12 ( ( V_8 ) V_7 ) ;
}
T_1 long F_13 ( T_3 V_9 , T_3 V_10 )
{
return F_14 ( F_3 ( V_9 ) , F_3 ( V_10 ) ) ;
}
T_1 long F_15 ( T_3 V_11 )
{
return F_16 ( ( V_12 ) V_11 ) ;
}
T_1 long F_17 ( T_3 V_9 , T_3 V_10 , T_3 V_13 )
{
return F_18 ( F_3 ( V_9 ) , F_3 ( V_10 ) ,
F_3 ( V_13 ) ) ;
}
T_1 long F_19 ( T_3 T_2 * V_9 , T_3 T_2 * V_10 , T_3 T_2 * V_13 )
{
int V_14 ;
if ( ! ( V_14 = F_20 ( F_21 ( V_15 -> V_16 -> V_11 ) , V_9 ) ) &&
! ( V_14 = F_20 ( F_21 ( V_15 -> V_16 -> V_10 ) , V_10 ) ) )
V_14 = F_20 ( F_21 ( V_15 -> V_16 -> V_13 ) , V_13 ) ;
return V_14 ;
}
T_1 long F_22 ( T_3 V_5 , T_3 V_6 , T_3 V_17 )
{
return F_23 ( F_4 ( V_5 ) , F_4 ( V_6 ) ,
F_4 ( V_17 ) ) ;
}
T_1 long F_24 ( T_3 T_2 * V_5 , T_3 T_2 * V_6 , T_3 T_2 * V_17 )
{
int V_14 ;
if ( ! ( V_14 = F_20 ( F_25 ( V_15 -> V_16 -> V_7 ) , V_5 ) ) &&
! ( V_14 = F_20 ( F_25 ( V_15 -> V_16 -> V_6 ) , V_6 ) ) )
V_14 = F_20 ( F_25 ( V_15 -> V_16 -> V_17 ) , V_17 ) ;
return V_14 ;
}
T_1 long F_26 ( T_3 V_11 )
{
return F_27 ( ( V_12 ) V_11 ) ;
}
T_1 long F_28 ( T_3 V_7 )
{
return F_29 ( ( V_8 ) V_7 ) ;
}
static int F_30 ( T_3 T_2 * V_18 , struct V_19 * V_19 )
{
int V_20 ;
T_3 V_3 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ ) {
V_3 = ( T_3 ) F_31 ( V_19 , V_20 ) ;
if ( F_20 ( V_3 , V_18 + V_20 ) )
return - V_22 ;
}
return 0 ;
}
static int F_32 ( struct V_19 * V_19 , T_3 T_2 * V_18 )
{
int V_20 ;
T_3 V_3 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ ) {
if ( F_33 ( V_3 , V_18 + V_20 ) )
return - V_22 ;
F_31 ( V_19 , V_20 ) = ( V_8 ) V_3 ;
}
return 0 ;
}
T_1 long F_34 ( int V_23 , T_3 T_2 * V_18 )
{
int V_20 ;
if ( V_23 < 0 )
return - V_24 ;
F_35 ( V_15 -> V_16 -> V_19 ) ;
V_20 = V_15 -> V_16 -> V_19 -> V_21 ;
if ( V_23 ) {
if ( V_20 > V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
if ( F_30 ( V_18 , V_15 -> V_16 -> V_19 ) ) {
V_20 = - V_22 ;
goto V_25;
}
}
V_25:
F_36 ( V_15 -> V_16 -> V_19 ) ;
return V_20 ;
}
T_1 long F_37 ( int V_23 , T_3 T_2 * V_18 )
{
struct V_19 * V_19 ;
int V_14 ;
if ( ! F_38 ( V_26 ) )
return - V_27 ;
if ( ( unsigned ) V_23 > V_28 )
return - V_24 ;
V_19 = F_39 ( V_23 ) ;
if ( ! V_19 )
return - V_29 ;
V_14 = F_32 ( V_19 , V_18 ) ;
if ( V_14 ) {
F_36 ( V_19 ) ;
return V_14 ;
}
V_14 = F_40 ( V_19 ) ;
F_36 ( V_19 ) ;
return V_14 ;
}
T_1 long F_41 ( void )
{
return F_21 ( V_15 -> V_16 -> V_11 ) ;
}
T_1 long F_42 ( void )
{
return F_21 ( V_15 -> V_16 -> V_10 ) ;
}
T_1 long F_43 ( void )
{
return F_25 ( V_15 -> V_16 -> V_7 ) ;
}
T_1 long F_44 ( void )
{
return F_25 ( V_15 -> V_16 -> V_6 ) ;
}
T_1 long F_45 ( T_4 V_30 , int V_31 , int V_32 , int V_33 , T_4 V_34 )
{
if ( V_30 >> 16 )
return - V_24 ;
switch ( V_30 ) {
case V_35 :
return F_46 ( V_31 , F_47 ( V_34 ) ,
V_32 , F_47 ( V_33 ) ) ;
case V_36 :
return F_48 ( V_31 , F_47 ( V_34 ) ,
V_32 , NULL ) ;
case V_37 :
return F_49 ( V_31 , V_32 , V_33 ) ;
case V_38 :
return F_50 ( V_31 , V_32 , V_33 ,
F_47 ( V_34 ) ) ;
case V_39 :
return F_51 ( V_31 , V_32 , V_33 ,
F_47 ( V_34 ) ) ;
case V_40 :
return F_52 ( V_31 , V_32 , 0 , V_33 ,
0 , F_47 ( V_34 ) ) ;
case V_41 :
return F_53 ( ( V_42 ) V_31 , V_32 ) ;
case V_43 :
return F_54 ( V_31 , V_32 , F_47 ( V_34 ) ) ;
case V_44 :
return F_55 ( V_31 , V_32 , V_33 ,
0 , F_47 ( V_34 ) ) ;
case V_45 :
return F_56 ( F_47 ( V_34 ) ) ;
case V_46 :
return F_57 ( V_31 , ( unsigned ) V_32 , V_33 ) ;
case V_47 :
return F_58 ( V_31 , V_32 , F_47 ( V_34 ) ) ;
}
return - V_48 ;
}
T_1 long F_59 ( const char T_2 * V_49 , unsigned long V_50 , unsigned long V_51 )
{
if ( ( int ) V_50 < 0 )
return - V_24 ;
else
return F_60 ( V_49 , ( V_50 << 32 ) | V_51 ) ;
}
T_1 long F_61 ( unsigned int V_4 , unsigned long V_50 , unsigned long V_51 )
{
if ( ( int ) V_50 < 0 )
return - V_24 ;
else
return F_62 ( V_4 , ( V_50 << 32 ) | V_51 ) ;
}
T_1 long F_63 ( T_5 V_52 ,
struct V_53 T_2 * V_54 )
{
struct V_55 V_56 ;
int V_57 ;
T_6 V_58 = F_64 () ;
F_65 ( V_59 ) ;
V_57 = F_66 ( V_52 ,
(struct V_55 V_60 T_2 * ) & V_56 ) ;
F_65 ( V_58 ) ;
if ( F_67 ( & V_56 , V_54 ) )
return - V_22 ;
return V_57 ;
}
T_1 long F_68 ( int V_61 , T_7 T_2 * V_62 ,
T_7 T_2 * V_63 , T_8 V_64 )
{
T_9 V_65 ;
T_7 V_66 ;
int V_57 ;
T_6 V_58 = F_64 () ;
if ( V_62 ) {
if ( F_69 ( & V_66 , V_62 , sizeof( T_7 ) ) )
return - V_22 ;
V_65 . V_67 [ 0 ] = V_66 . V_67 [ 0 ] | ( ( ( long ) V_66 . V_67 [ 1 ] ) << 32 ) ;
}
F_65 ( V_59 ) ;
V_57 = F_70 ( V_61 ,
V_62 ? ( T_9 V_60 T_2 * ) & V_65 : NULL ,
V_63 ? ( T_9 V_60 T_2 * ) & V_65 : NULL ,
V_64 ) ;
F_65 ( V_58 ) ;
if ( V_57 ) return V_57 ;
if ( V_63 ) {
V_66 . V_67 [ 1 ] = ( V_65 . V_67 [ 0 ] >> 32 ) ;
V_66 . V_67 [ 0 ] = V_65 . V_67 [ 0 ] ;
if ( F_71 ( V_63 , & V_66 , sizeof( T_7 ) ) )
return - V_22 ;
}
return 0 ;
}
T_1 long F_72 ( T_7 T_2 * V_62 ,
T_8 V_64 )
{
T_9 V_65 ;
T_7 V_66 ;
int V_57 ;
T_6 V_58 = F_64 () ;
F_65 ( V_59 ) ;
V_57 = F_73 ( ( T_9 V_60 T_2 * ) & V_65 , V_64 ) ;
F_65 ( V_58 ) ;
if ( ! V_57 ) {
V_66 . V_67 [ 1 ] = ( V_65 . V_67 [ 0 ] >> 32 ) ;
V_66 . V_67 [ 0 ] = V_65 . V_67 [ 0 ] ;
if ( F_71 ( V_62 , & V_66 , sizeof( T_7 ) ) )
return - V_22 ;
}
return V_57 ;
}
T_1 long
F_74 ( int V_52 , int V_67 , T_10 T_2 * V_68 )
{
T_11 V_69 ;
int V_57 ;
T_6 V_58 = F_64 () ;
if ( F_75 ( & V_69 , V_68 ) )
return - V_22 ;
F_65 ( V_59 ) ;
V_57 = F_76 ( V_52 , V_67 , ( T_11 V_60 T_2 * ) & V_69 ) ;
F_65 ( V_58 ) ;
return V_57 ;
}
T_1 long F_77 ( const char T_2 * V_70 , T_12 T_2 * V_71 ,
T_12 T_2 * V_72 )
{
struct V_73 * V_74 = F_78 ( V_15 ) ;
char * V_1 ;
long V_75 ;
V_1 = F_79 ( V_70 ) ;
V_75 = F_80 ( V_1 ) ;
if ( F_81 ( V_1 ) )
return V_75 ;
V_75 = F_82 ( V_1 , V_71 , V_72 , V_74 ) ;
if ( V_75 )
goto V_25;
V_15 -> V_76 . V_77 . V_78 = 0 ;
asm volatile("sfpc %0,0" : : "d" (0));
V_75 = V_74 -> V_79 [ 2 ] ;
V_25:
F_83 ( V_1 ) ;
return V_75 ;
}
T_1 long F_84 ( unsigned int V_4 , char T_2 * V_80 ,
T_8 V_81 , T_4 V_82 , T_4 V_83 )
{
if ( ( V_84 ) V_81 < 0 )
return - V_24 ;
return F_85 ( V_4 , V_80 , V_81 , ( ( V_85 ) F_86 ( V_82 ) << 32 ) | F_86 ( V_83 ) ) ;
}
T_1 long F_87 ( unsigned int V_4 , const char T_2 * V_80 ,
T_8 V_81 , T_4 V_82 , T_4 V_83 )
{
if ( ( V_84 ) V_81 < 0 )
return - V_24 ;
return F_88 ( V_4 , V_80 , V_81 , ( ( V_85 ) F_86 ( V_82 ) << 32 ) | F_86 ( V_83 ) ) ;
}
T_1 V_84 F_89 ( int V_4 , T_4 V_86 , T_4 V_87 , V_66 V_81 )
{
return F_90 ( V_4 , ( ( V_85 ) F_86 ( V_86 ) << 32 ) | F_86 ( V_87 ) , V_81 ) ;
}
T_1 long F_91 ( int V_88 , int V_89 , T_13 T_2 * V_90 , T_8 V_81 )
{
T_6 V_58 = F_64 () ;
int V_57 ;
T_14 V_91 ;
if ( V_90 && F_33 ( V_91 , V_90 ) )
return - V_22 ;
F_65 ( V_59 ) ;
V_57 = F_92 ( V_88 , V_89 ,
V_90 ? ( T_14 V_60 T_2 * ) & V_91 : NULL , V_81 ) ;
F_65 ( V_58 ) ;
if ( V_90 && F_20 ( V_91 , V_90 ) )
return - V_22 ;
return V_57 ;
}
T_1 long F_93 ( int V_88 , int V_89 ,
T_15 T_2 * V_90 , V_66 V_81 )
{
T_6 V_58 = F_64 () ;
int V_57 ;
V_85 V_92 ;
if ( V_90 && F_33 ( V_92 , V_90 ) )
return - V_22 ;
F_65 ( V_59 ) ;
V_57 = F_94 ( V_88 , V_89 ,
V_90 ? ( V_85 V_60 T_2 * ) & V_92 : NULL ,
V_81 ) ;
F_65 ( V_58 ) ;
if ( V_90 && F_20 ( V_92 , V_90 ) )
return - V_22 ;
return V_57 ;
}
static int F_95 ( struct V_93 T_2 * V_80 , struct V_94 * V_95 )
{
struct V_93 V_96 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_97 = F_96 ( V_95 -> V_98 ) ;
V_96 . V_99 = V_95 -> V_100 ;
V_96 . V_101 = ( T_4 ) V_95 -> V_100 ;
V_96 . V_102 = V_95 -> V_103 ;
V_96 . V_104 = ( unsigned int ) V_95 -> V_105 ;
V_96 . V_106 = V_95 -> V_11 ;
V_96 . V_107 = V_95 -> V_7 ;
V_96 . V_108 = F_96 ( V_95 -> V_109 ) ;
V_96 . V_110 = V_95 -> V_111 ;
V_96 . V_112 = ( T_4 ) V_95 -> V_113 ;
V_96 . V_114 = ( T_4 ) V_95 -> V_115 ;
V_96 . V_116 = ( T_4 ) V_95 -> V_117 . V_118 ;
V_96 . V_119 = ( T_4 ) V_95 -> V_120 . V_118 ;
V_96 . V_121 = ( T_4 ) V_95 -> ctime . V_118 ;
return F_71 ( V_80 , & V_96 , sizeof( V_96 ) ) ? - V_22 : 0 ;
}
T_1 long F_97 ( const char T_2 * V_1 , struct V_93 T_2 * V_122 )
{
struct V_94 V_95 ;
int V_57 = F_98 ( V_1 , & V_95 ) ;
if ( ! V_57 )
V_57 = F_95 ( V_122 , & V_95 ) ;
return V_57 ;
}
T_1 long F_99 ( const char T_2 * V_1 , struct V_93 T_2 * V_122 )
{
struct V_94 V_95 ;
int V_57 = F_100 ( V_1 , & V_95 ) ;
if ( ! V_57 )
V_57 = F_95 ( V_122 , & V_95 ) ;
return V_57 ;
}
T_1 long F_101 ( unsigned long V_4 , struct V_93 T_2 * V_122 )
{
struct V_94 V_95 ;
int V_57 = F_102 ( V_4 , & V_95 ) ;
if ( ! V_57 )
V_57 = F_95 ( V_122 , & V_95 ) ;
return V_57 ;
}
T_1 long F_103 ( unsigned int V_123 , const char T_2 * V_1 ,
struct V_93 T_2 * V_122 , int V_124 )
{
struct V_94 V_95 ;
int error ;
error = F_104 ( V_123 , V_1 , & V_95 , V_124 ) ;
if ( error )
return error ;
return F_95 ( V_122 , & V_95 ) ;
}
T_1 unsigned long F_105 ( struct V_125 T_2 * V_126 )
{
struct V_125 V_127 ;
if ( F_69 ( & V_127 , V_126 , sizeof( V_127 ) ) )
return - V_22 ;
if ( V_127 . V_90 & ~ V_128 )
return - V_24 ;
V_127 . V_129 = ( unsigned long ) F_47 ( V_127 . V_129 ) ;
return F_106 ( V_127 . V_129 , V_127 . V_130 , V_127 . V_131 , V_127 . V_132 , V_127 . V_4 ,
V_127 . V_90 >> V_133 ) ;
}
T_1 long F_107 ( struct V_125 T_2 * V_126 )
{
struct V_125 V_127 ;
if ( F_69 ( & V_127 , V_126 , sizeof( V_127 ) ) )
return - V_22 ;
V_127 . V_129 = ( unsigned long ) F_47 ( V_127 . V_129 ) ;
return F_106 ( V_127 . V_129 , V_127 . V_130 , V_127 . V_131 , V_127 . V_132 , V_127 . V_4 , V_127 . V_90 ) ;
}
T_1 long F_108 ( unsigned int V_4 , char T_2 * V_134 , T_8 V_81 )
{
if ( ( V_84 ) V_81 < 0 )
return - V_24 ;
return F_109 ( V_4 , V_134 , V_81 ) ;
}
T_1 long F_110 ( unsigned int V_4 , const char T_2 * V_134 , T_8 V_81 )
{
if ( ( V_84 ) V_81 < 0 )
return - V_24 ;
return F_111 ( V_4 , V_134 , V_81 ) ;
}
T_1 long
F_112 ( int V_4 , V_85 V_90 , T_8 V_130 , int V_135 )
{
if ( V_135 == 4 )
V_135 = V_136 ;
else if ( V_135 == 5 )
V_135 = V_137 ;
return F_113 ( V_4 , V_90 , V_130 , V_135 ) ;
}
T_1 long
F_114 ( struct V_138 T_2 * args )
{
struct V_138 V_127 ;
if ( F_69 ( & V_127 , args , sizeof( V_127 ) ) )
return - V_22 ;
if ( V_127 . V_139 == 4 )
V_127 . V_139 = V_136 ;
else if ( V_127 . V_139 == 5 )
V_127 . V_139 = V_137 ;
return F_115 ( V_127 . V_4 , V_127 . V_90 , V_127 . V_130 , V_127 . V_139 ) ;
}
