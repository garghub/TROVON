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
T_1 long F_19 ( T_3 T_2 * V_14 , T_3 T_2 * V_15 , T_3 T_2 * V_16 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_9 , V_10 , V_13 ;
V_9 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_11 ) ) ;
V_10 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_10 ) ) ;
V_13 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_13 ) ) ;
if ( ! ( V_18 = F_23 ( V_9 , V_14 ) ) &&
! ( V_18 = F_23 ( V_10 , V_15 ) ) )
V_18 = F_23 ( V_13 , V_16 ) ;
return V_18 ;
}
T_1 long F_24 ( T_3 V_5 , T_3 V_6 , T_3 V_20 )
{
return F_25 ( F_4 ( V_5 ) , F_4 ( V_6 ) ,
F_4 ( V_20 ) ) ;
}
T_1 long F_26 ( T_3 T_2 * V_21 , T_3 T_2 * V_22 , T_3 T_2 * V_23 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_5 , V_6 , V_20 ;
V_5 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_7 ) ) ;
V_6 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_6 ) ) ;
V_20 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_20 ) ) ;
if ( ! ( V_18 = F_23 ( V_5 , V_21 ) ) &&
! ( V_18 = F_23 ( V_6 , V_22 ) ) )
V_18 = F_23 ( V_20 , V_23 ) ;
return V_18 ;
}
T_1 long F_29 ( T_3 V_11 )
{
return F_30 ( ( V_12 ) V_11 ) ;
}
T_1 long F_31 ( T_3 V_7 )
{
return F_32 ( ( V_8 ) V_7 ) ;
}
static int F_33 ( T_3 T_2 * V_24 , struct V_25 * V_25 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
V_28 = F_35 ( V_25 , V_27 ) ;
V_3 = ( T_3 ) F_28 ( V_19 , V_28 ) ;
if ( F_23 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
}
return 0 ;
}
static int F_36 ( struct V_25 * V_25 , T_3 T_2 * V_24 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
if ( F_37 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
V_28 = F_38 ( V_19 , ( V_8 ) V_3 ) ;
if ( ! F_39 ( V_28 ) )
return - V_31 ;
F_35 ( V_25 , V_27 ) = V_28 ;
}
return 0 ;
}
T_1 long F_40 ( int V_32 , T_3 T_2 * V_24 )
{
int V_27 ;
if ( V_32 < 0 )
return - V_31 ;
F_41 ( V_33 -> V_17 -> V_25 ) ;
V_27 = V_33 -> V_17 -> V_25 -> V_29 ;
if ( V_32 ) {
if ( V_27 > V_32 ) {
V_27 = - V_31 ;
goto V_34;
}
if ( F_33 ( V_24 , V_33 -> V_17 -> V_25 ) ) {
V_27 = - V_30 ;
goto V_34;
}
}
V_34:
F_42 ( V_33 -> V_17 -> V_25 ) ;
return V_27 ;
}
T_1 long F_43 ( int V_32 , T_3 T_2 * V_24 )
{
struct V_25 * V_25 ;
int V_18 ;
if ( ! F_44 ( V_35 ) )
return - V_36 ;
if ( ( unsigned ) V_32 > V_37 )
return - V_31 ;
V_25 = F_45 ( V_32 ) ;
if ( ! V_25 )
return - V_38 ;
V_18 = F_36 ( V_25 , V_24 ) ;
if ( V_18 ) {
F_42 ( V_25 ) ;
return V_18 ;
}
V_18 = F_46 ( V_25 ) ;
F_42 ( V_25 ) ;
return V_18 ;
}
T_1 long F_47 ( void )
{
return F_21 ( F_22 ( F_34 () , F_48 () ) ) ;
}
T_1 long F_49 ( void )
{
return F_21 ( F_22 ( F_34 () , F_50 () ) ) ;
}
T_1 long F_51 ( void )
{
return F_27 ( F_28 ( F_34 () , F_52 () ) ) ;
}
T_1 long F_53 ( void )
{
return F_27 ( F_28 ( F_34 () , F_54 () ) ) ;
}
T_1 long F_55 ( T_5 V_39 , int V_40 , int V_41 , int V_42 , T_5 V_43 )
{
if ( V_39 >> 16 )
return - V_31 ;
switch ( V_39 ) {
case V_44 :
return F_56 ( V_40 , F_57 ( V_43 ) ,
V_41 , F_57 ( V_42 ) ) ;
case V_45 :
return F_58 ( V_40 , F_57 ( V_43 ) ,
V_41 , NULL ) ;
case V_46 :
return F_59 ( V_40 , V_41 , V_42 ) ;
case V_47 :
return F_60 ( V_40 , V_41 , V_42 ,
F_57 ( V_43 ) ) ;
case V_48 :
return F_61 ( V_40 , V_41 , V_42 ,
F_57 ( V_43 ) ) ;
case V_49 :
return F_62 ( V_40 , V_41 , 0 , V_42 ,
0 , F_57 ( V_43 ) ) ;
case V_50 :
return F_63 ( ( V_51 ) V_40 , V_41 ) ;
case V_52 :
return F_64 ( V_40 , V_41 , F_57 ( V_43 ) ) ;
case V_53 :
return F_65 ( V_40 , V_41 , V_42 ,
0 , F_57 ( V_43 ) ) ;
case V_54 :
return F_66 ( F_57 ( V_43 ) ) ;
case V_55 :
return F_67 ( V_40 , ( unsigned ) V_41 , V_42 ) ;
case V_56 :
return F_68 ( V_40 , V_41 , F_57 ( V_43 ) ) ;
}
return - V_57 ;
}
T_1 long F_69 ( const char T_2 * V_58 , unsigned long V_59 , unsigned long V_60 )
{
if ( ( int ) V_59 < 0 )
return - V_31 ;
else
return F_70 ( V_58 , ( V_59 << 32 ) | V_60 ) ;
}
T_1 long F_71 ( unsigned int V_4 , unsigned long V_59 , unsigned long V_60 )
{
if ( ( int ) V_59 < 0 )
return - V_31 ;
else
return F_72 ( V_4 , ( V_59 << 32 ) | V_60 ) ;
}
T_1 long F_73 ( T_6 V_61 ,
struct V_62 T_2 * V_63 )
{
struct V_64 V_65 ;
int V_66 ;
T_7 V_67 = F_74 () ;
F_75 ( V_68 ) ;
V_66 = F_76 ( V_61 ,
(struct V_64 V_69 T_2 * ) & V_65 ) ;
F_75 ( V_67 ) ;
if ( F_77 ( & V_65 , V_63 ) )
return - V_30 ;
return V_66 ;
}
T_1 long F_78 ( int V_70 , T_8 T_2 * V_71 ,
T_8 T_2 * V_72 , T_9 V_73 )
{
T_10 V_74 ;
T_8 V_75 ;
int V_66 ;
T_7 V_67 = F_74 () ;
if ( V_71 ) {
if ( F_79 ( & V_75 , V_71 , sizeof( T_8 ) ) )
return - V_30 ;
V_74 . V_76 [ 0 ] = V_75 . V_76 [ 0 ] | ( ( ( long ) V_75 . V_76 [ 1 ] ) << 32 ) ;
}
F_75 ( V_68 ) ;
V_66 = F_80 ( V_70 ,
V_71 ? ( T_10 V_69 T_2 * ) & V_74 : NULL ,
V_72 ? ( T_10 V_69 T_2 * ) & V_74 : NULL ,
V_73 ) ;
F_75 ( V_67 ) ;
if ( V_66 ) return V_66 ;
if ( V_72 ) {
V_75 . V_76 [ 1 ] = ( V_74 . V_76 [ 0 ] >> 32 ) ;
V_75 . V_76 [ 0 ] = V_74 . V_76 [ 0 ] ;
if ( F_81 ( V_72 , & V_75 , sizeof( T_8 ) ) )
return - V_30 ;
}
return 0 ;
}
T_1 long F_82 ( T_8 T_2 * V_71 ,
T_9 V_73 )
{
T_10 V_74 ;
T_8 V_75 ;
int V_66 ;
T_7 V_67 = F_74 () ;
F_75 ( V_68 ) ;
V_66 = F_83 ( ( T_10 V_69 T_2 * ) & V_74 , V_73 ) ;
F_75 ( V_67 ) ;
if ( ! V_66 ) {
V_75 . V_76 [ 1 ] = ( V_74 . V_76 [ 0 ] >> 32 ) ;
V_75 . V_76 [ 0 ] = V_74 . V_76 [ 0 ] ;
if ( F_81 ( V_71 , & V_75 , sizeof( T_8 ) ) )
return - V_30 ;
}
return V_66 ;
}
T_1 long
F_84 ( int V_61 , int V_76 , T_11 T_2 * V_77 )
{
T_12 V_78 ;
int V_66 ;
T_7 V_67 = F_74 () ;
if ( F_85 ( & V_78 , V_77 ) )
return - V_30 ;
F_75 ( V_68 ) ;
V_66 = F_86 ( V_61 , V_76 , ( T_12 V_69 T_2 * ) & V_78 ) ;
F_75 ( V_67 ) ;
return V_66 ;
}
T_1 long F_87 ( unsigned int V_4 , char T_2 * V_79 ,
T_9 V_80 , T_5 V_81 , T_5 V_82 )
{
if ( ( V_83 ) V_80 < 0 )
return - V_31 ;
return F_88 ( V_4 , V_79 , V_80 , ( ( V_84 ) F_89 ( V_81 ) << 32 ) | F_89 ( V_82 ) ) ;
}
T_1 long F_90 ( unsigned int V_4 , const char T_2 * V_79 ,
T_9 V_80 , T_5 V_81 , T_5 V_82 )
{
if ( ( V_83 ) V_80 < 0 )
return - V_31 ;
return F_91 ( V_4 , V_79 , V_80 , ( ( V_84 ) F_89 ( V_81 ) << 32 ) | F_89 ( V_82 ) ) ;
}
T_1 V_83 F_92 ( int V_4 , T_5 V_85 , T_5 V_86 , V_75 V_80 )
{
return F_93 ( V_4 , ( ( V_84 ) F_89 ( V_85 ) << 32 ) | F_89 ( V_86 ) , V_80 ) ;
}
T_1 long F_94 ( int V_87 , int V_88 , T_13 T_2 * V_89 , T_9 V_80 )
{
T_7 V_67 = F_74 () ;
int V_66 ;
T_14 V_90 ;
if ( V_89 && F_37 ( V_90 , V_89 ) )
return - V_30 ;
F_75 ( V_68 ) ;
V_66 = F_95 ( V_87 , V_88 ,
V_89 ? ( T_14 V_69 T_2 * ) & V_90 : NULL , V_80 ) ;
F_75 ( V_67 ) ;
if ( V_89 && F_23 ( V_90 , V_89 ) )
return - V_30 ;
return V_66 ;
}
T_1 long F_96 ( int V_87 , int V_88 ,
T_15 T_2 * V_89 , V_75 V_80 )
{
T_7 V_67 = F_74 () ;
int V_66 ;
V_84 V_91 ;
if ( V_89 && F_37 ( V_91 , V_89 ) )
return - V_30 ;
F_75 ( V_68 ) ;
V_66 = F_97 ( V_87 , V_88 ,
V_89 ? ( V_84 V_69 T_2 * ) & V_91 : NULL ,
V_80 ) ;
F_75 ( V_67 ) ;
if ( V_89 && F_23 ( V_91 , V_89 ) )
return - V_30 ;
return V_66 ;
}
static int F_98 ( struct V_92 T_2 * V_79 , struct V_93 * V_94 )
{
struct V_92 V_95 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_96 = F_99 ( V_94 -> V_97 ) ;
V_95 . V_98 = V_94 -> V_99 ;
V_95 . V_100 = ( T_5 ) V_94 -> V_99 ;
V_95 . V_101 = V_94 -> V_102 ;
V_95 . V_103 = ( unsigned int ) V_94 -> V_104 ;
V_95 . V_105 = F_22 ( F_34 () , V_94 -> V_11 ) ;
V_95 . V_106 = F_28 ( F_34 () , V_94 -> V_7 ) ;
V_95 . V_107 = F_99 ( V_94 -> V_108 ) ;
V_95 . V_109 = V_94 -> V_110 ;
V_95 . V_111 = ( T_5 ) V_94 -> V_112 ;
V_95 . V_113 = ( T_5 ) V_94 -> V_114 ;
V_95 . V_115 = ( T_5 ) V_94 -> V_116 . V_117 ;
V_95 . V_118 = ( T_5 ) V_94 -> V_119 . V_117 ;
V_95 . V_120 = ( T_5 ) V_94 -> ctime . V_117 ;
return F_81 ( V_79 , & V_95 , sizeof( V_95 ) ) ? - V_30 : 0 ;
}
T_1 long F_100 ( const char T_2 * V_1 , struct V_92 T_2 * V_121 )
{
struct V_93 V_94 ;
int V_66 = F_101 ( V_1 , & V_94 ) ;
if ( ! V_66 )
V_66 = F_98 ( V_121 , & V_94 ) ;
return V_66 ;
}
T_1 long F_102 ( const char T_2 * V_1 , struct V_92 T_2 * V_121 )
{
struct V_93 V_94 ;
int V_66 = F_103 ( V_1 , & V_94 ) ;
if ( ! V_66 )
V_66 = F_98 ( V_121 , & V_94 ) ;
return V_66 ;
}
T_1 long F_104 ( unsigned long V_4 , struct V_92 T_2 * V_121 )
{
struct V_93 V_94 ;
int V_66 = F_105 ( V_4 , & V_94 ) ;
if ( ! V_66 )
V_66 = F_98 ( V_121 , & V_94 ) ;
return V_66 ;
}
T_1 long F_106 ( unsigned int V_122 , const char T_2 * V_1 ,
struct V_92 T_2 * V_121 , int V_123 )
{
struct V_93 V_94 ;
int error ;
error = F_107 ( V_122 , V_1 , & V_94 , V_123 ) ;
if ( error )
return error ;
return F_98 ( V_121 , & V_94 ) ;
}
T_1 unsigned long F_108 ( struct V_124 T_2 * V_125 )
{
struct V_124 V_126 ;
if ( F_79 ( & V_126 , V_125 , sizeof( V_126 ) ) )
return - V_30 ;
if ( V_126 . V_89 & ~ V_127 )
return - V_31 ;
return F_109 ( V_126 . V_128 , V_126 . V_129 , V_126 . V_130 , V_126 . V_131 , V_126 . V_4 ,
V_126 . V_89 >> V_132 ) ;
}
T_1 long F_110 ( struct V_124 T_2 * V_125 )
{
struct V_124 V_126 ;
if ( F_79 ( & V_126 , V_125 , sizeof( V_126 ) ) )
return - V_30 ;
return F_109 ( V_126 . V_128 , V_126 . V_129 , V_126 . V_130 , V_126 . V_131 , V_126 . V_4 , V_126 . V_89 ) ;
}
T_1 long F_111 ( unsigned int V_4 , char T_2 * V_133 , T_9 V_80 )
{
if ( ( V_83 ) V_80 < 0 )
return - V_31 ;
return F_112 ( V_4 , V_133 , V_80 ) ;
}
T_1 long F_113 ( unsigned int V_4 , const char T_2 * V_133 , T_9 V_80 )
{
if ( ( V_83 ) V_80 < 0 )
return - V_31 ;
return F_114 ( V_4 , V_133 , V_80 ) ;
}
T_1 long
F_115 ( int V_4 , V_84 V_89 , T_9 V_129 , int V_134 )
{
if ( V_134 == 4 )
V_134 = V_135 ;
else if ( V_134 == 5 )
V_134 = V_136 ;
return F_116 ( V_4 , V_89 , V_129 , V_134 ) ;
}
T_1 long
F_117 ( struct V_137 T_2 * args )
{
struct V_137 V_126 ;
if ( F_79 ( & V_126 , args , sizeof( V_126 ) ) )
return - V_30 ;
if ( V_126 . V_138 == 4 )
V_126 . V_138 = V_135 ;
else if ( V_126 . V_138 == 5 )
V_126 . V_138 = V_136 ;
return F_118 ( V_126 . V_4 , V_126 . V_89 , V_126 . V_129 , V_126 . V_138 ) ;
}
