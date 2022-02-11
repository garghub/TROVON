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
struct V_20 * V_21 = F_31 () ;
int V_22 ;
T_3 V_3 ;
T_4 V_23 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_24 ; V_22 ++ ) {
V_23 = F_32 ( V_19 , V_22 ) ;
V_3 = ( T_3 ) F_33 ( V_21 , V_23 ) ;
if ( F_20 ( V_3 , V_18 + V_22 ) )
return - V_25 ;
}
return 0 ;
}
static int F_34 ( struct V_19 * V_19 , T_3 T_2 * V_18 )
{
struct V_20 * V_21 = F_31 () ;
int V_22 ;
T_3 V_3 ;
T_4 V_23 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_24 ; V_22 ++ ) {
if ( F_35 ( V_3 , V_18 + V_22 ) )
return - V_25 ;
V_23 = F_36 ( V_21 , ( V_8 ) V_3 ) ;
if ( ! F_37 ( V_23 ) )
return - V_26 ;
F_32 ( V_19 , V_22 ) = V_23 ;
}
return 0 ;
}
T_1 long F_38 ( int V_27 , T_3 T_2 * V_18 )
{
int V_22 ;
if ( V_27 < 0 )
return - V_26 ;
F_39 ( V_15 -> V_16 -> V_19 ) ;
V_22 = V_15 -> V_16 -> V_19 -> V_24 ;
if ( V_27 ) {
if ( V_22 > V_27 ) {
V_22 = - V_26 ;
goto V_28;
}
if ( F_30 ( V_18 , V_15 -> V_16 -> V_19 ) ) {
V_22 = - V_25 ;
goto V_28;
}
}
V_28:
F_40 ( V_15 -> V_16 -> V_19 ) ;
return V_22 ;
}
T_1 long F_41 ( int V_27 , T_3 T_2 * V_18 )
{
struct V_19 * V_19 ;
int V_14 ;
if ( ! F_42 ( V_29 ) )
return - V_30 ;
if ( ( unsigned ) V_27 > V_31 )
return - V_26 ;
V_19 = F_43 ( V_27 ) ;
if ( ! V_19 )
return - V_32 ;
V_14 = F_34 ( V_19 , V_18 ) ;
if ( V_14 ) {
F_40 ( V_19 ) ;
return V_14 ;
}
V_14 = F_44 ( V_19 ) ;
F_40 ( V_19 ) ;
return V_14 ;
}
T_1 long F_45 ( void )
{
return F_21 ( V_15 -> V_16 -> V_11 ) ;
}
T_1 long F_46 ( void )
{
return F_21 ( V_15 -> V_16 -> V_10 ) ;
}
T_1 long F_47 ( void )
{
return F_25 ( V_15 -> V_16 -> V_7 ) ;
}
T_1 long F_48 ( void )
{
return F_25 ( V_15 -> V_16 -> V_6 ) ;
}
T_1 long F_49 ( T_5 V_33 , int V_34 , int V_35 , int V_36 , T_5 V_37 )
{
if ( V_33 >> 16 )
return - V_26 ;
switch ( V_33 ) {
case V_38 :
return F_50 ( V_34 , F_51 ( V_37 ) ,
V_35 , F_51 ( V_36 ) ) ;
case V_39 :
return F_52 ( V_34 , F_51 ( V_37 ) ,
V_35 , NULL ) ;
case V_40 :
return F_53 ( V_34 , V_35 , V_36 ) ;
case V_41 :
return F_54 ( V_34 , V_35 , V_36 ,
F_51 ( V_37 ) ) ;
case V_42 :
return F_55 ( V_34 , V_35 , V_36 ,
F_51 ( V_37 ) ) ;
case V_43 :
return F_56 ( V_34 , V_35 , 0 , V_36 ,
0 , F_51 ( V_37 ) ) ;
case V_44 :
return F_57 ( ( V_45 ) V_34 , V_35 ) ;
case V_46 :
return F_58 ( V_34 , V_35 , F_51 ( V_37 ) ) ;
case V_47 :
return F_59 ( V_34 , V_35 , V_36 ,
0 , F_51 ( V_37 ) ) ;
case V_48 :
return F_60 ( F_51 ( V_37 ) ) ;
case V_49 :
return F_61 ( V_34 , ( unsigned ) V_35 , V_36 ) ;
case V_50 :
return F_62 ( V_34 , V_35 , F_51 ( V_37 ) ) ;
}
return - V_51 ;
}
T_1 long F_63 ( const char T_2 * V_52 , unsigned long V_53 , unsigned long V_54 )
{
if ( ( int ) V_53 < 0 )
return - V_26 ;
else
return F_64 ( V_52 , ( V_53 << 32 ) | V_54 ) ;
}
T_1 long F_65 ( unsigned int V_4 , unsigned long V_53 , unsigned long V_54 )
{
if ( ( int ) V_53 < 0 )
return - V_26 ;
else
return F_66 ( V_4 , ( V_53 << 32 ) | V_54 ) ;
}
T_1 long F_67 ( T_6 V_55 ,
struct V_56 T_2 * V_57 )
{
struct V_58 V_59 ;
int V_60 ;
T_7 V_61 = F_68 () ;
F_69 ( V_62 ) ;
V_60 = F_70 ( V_55 ,
(struct V_58 V_63 T_2 * ) & V_59 ) ;
F_69 ( V_61 ) ;
if ( F_71 ( & V_59 , V_57 ) )
return - V_25 ;
return V_60 ;
}
T_1 long F_72 ( int V_64 , T_8 T_2 * V_65 ,
T_8 T_2 * V_66 , T_9 V_67 )
{
T_10 V_68 ;
T_8 V_69 ;
int V_60 ;
T_7 V_61 = F_68 () ;
if ( V_65 ) {
if ( F_73 ( & V_69 , V_65 , sizeof( T_8 ) ) )
return - V_25 ;
V_68 . V_70 [ 0 ] = V_69 . V_70 [ 0 ] | ( ( ( long ) V_69 . V_70 [ 1 ] ) << 32 ) ;
}
F_69 ( V_62 ) ;
V_60 = F_74 ( V_64 ,
V_65 ? ( T_10 V_63 T_2 * ) & V_68 : NULL ,
V_66 ? ( T_10 V_63 T_2 * ) & V_68 : NULL ,
V_67 ) ;
F_69 ( V_61 ) ;
if ( V_60 ) return V_60 ;
if ( V_66 ) {
V_69 . V_70 [ 1 ] = ( V_68 . V_70 [ 0 ] >> 32 ) ;
V_69 . V_70 [ 0 ] = V_68 . V_70 [ 0 ] ;
if ( F_75 ( V_66 , & V_69 , sizeof( T_8 ) ) )
return - V_25 ;
}
return 0 ;
}
T_1 long F_76 ( T_8 T_2 * V_65 ,
T_9 V_67 )
{
T_10 V_68 ;
T_8 V_69 ;
int V_60 ;
T_7 V_61 = F_68 () ;
F_69 ( V_62 ) ;
V_60 = F_77 ( ( T_10 V_63 T_2 * ) & V_68 , V_67 ) ;
F_69 ( V_61 ) ;
if ( ! V_60 ) {
V_69 . V_70 [ 1 ] = ( V_68 . V_70 [ 0 ] >> 32 ) ;
V_69 . V_70 [ 0 ] = V_68 . V_70 [ 0 ] ;
if ( F_75 ( V_65 , & V_69 , sizeof( T_8 ) ) )
return - V_25 ;
}
return V_60 ;
}
T_1 long
F_78 ( int V_55 , int V_70 , T_11 T_2 * V_71 )
{
T_12 V_72 ;
int V_60 ;
T_7 V_61 = F_68 () ;
if ( F_79 ( & V_72 , V_71 ) )
return - V_25 ;
F_69 ( V_62 ) ;
V_60 = F_80 ( V_55 , V_70 , ( T_12 V_63 T_2 * ) & V_72 ) ;
F_69 ( V_61 ) ;
return V_60 ;
}
T_1 long F_81 ( const char T_2 * V_73 , T_13 T_2 * V_74 ,
T_13 T_2 * V_75 )
{
struct V_76 * V_77 = F_82 ( V_15 ) ;
char * V_1 ;
long V_78 ;
V_1 = F_83 ( V_73 ) ;
V_78 = F_84 ( V_1 ) ;
if ( F_85 ( V_1 ) )
return V_78 ;
V_78 = F_86 ( V_1 , V_74 , V_75 , V_77 ) ;
if ( V_78 )
goto V_28;
V_15 -> V_79 . V_80 . V_81 = 0 ;
asm volatile("sfpc %0,0" : : "d" (0));
V_78 = V_77 -> V_82 [ 2 ] ;
V_28:
F_87 ( V_1 ) ;
return V_78 ;
}
T_1 long F_88 ( unsigned int V_4 , char T_2 * V_83 ,
T_9 V_84 , T_5 V_85 , T_5 V_86 )
{
if ( ( V_87 ) V_84 < 0 )
return - V_26 ;
return F_89 ( V_4 , V_83 , V_84 , ( ( V_88 ) F_90 ( V_85 ) << 32 ) | F_90 ( V_86 ) ) ;
}
T_1 long F_91 ( unsigned int V_4 , const char T_2 * V_83 ,
T_9 V_84 , T_5 V_85 , T_5 V_86 )
{
if ( ( V_87 ) V_84 < 0 )
return - V_26 ;
return F_92 ( V_4 , V_83 , V_84 , ( ( V_88 ) F_90 ( V_85 ) << 32 ) | F_90 ( V_86 ) ) ;
}
T_1 V_87 F_93 ( int V_4 , T_5 V_89 , T_5 V_90 , V_69 V_84 )
{
return F_94 ( V_4 , ( ( V_88 ) F_90 ( V_89 ) << 32 ) | F_90 ( V_90 ) , V_84 ) ;
}
T_1 long F_95 ( int V_91 , int V_92 , T_14 T_2 * V_93 , T_9 V_84 )
{
T_7 V_61 = F_68 () ;
int V_60 ;
T_15 V_94 ;
if ( V_93 && F_35 ( V_94 , V_93 ) )
return - V_25 ;
F_69 ( V_62 ) ;
V_60 = F_96 ( V_91 , V_92 ,
V_93 ? ( T_15 V_63 T_2 * ) & V_94 : NULL , V_84 ) ;
F_69 ( V_61 ) ;
if ( V_93 && F_20 ( V_94 , V_93 ) )
return - V_25 ;
return V_60 ;
}
T_1 long F_97 ( int V_91 , int V_92 ,
T_16 T_2 * V_93 , V_69 V_84 )
{
T_7 V_61 = F_68 () ;
int V_60 ;
V_88 V_95 ;
if ( V_93 && F_35 ( V_95 , V_93 ) )
return - V_25 ;
F_69 ( V_62 ) ;
V_60 = F_98 ( V_91 , V_92 ,
V_93 ? ( V_88 V_63 T_2 * ) & V_95 : NULL ,
V_84 ) ;
F_69 ( V_61 ) ;
if ( V_93 && F_20 ( V_95 , V_93 ) )
return - V_25 ;
return V_60 ;
}
static int F_99 ( struct V_96 T_2 * V_83 , struct V_97 * V_98 )
{
struct V_96 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = F_100 ( V_98 -> V_101 ) ;
V_99 . V_102 = V_98 -> V_103 ;
V_99 . V_104 = ( T_5 ) V_98 -> V_103 ;
V_99 . V_105 = V_98 -> V_106 ;
V_99 . V_107 = ( unsigned int ) V_98 -> V_108 ;
V_99 . V_109 = F_101 ( F_31 () , V_98 -> V_11 ) ;
V_99 . V_110 = F_33 ( F_31 () , V_98 -> V_7 ) ;
V_99 . V_111 = F_100 ( V_98 -> V_112 ) ;
V_99 . V_113 = V_98 -> V_114 ;
V_99 . V_115 = ( T_5 ) V_98 -> V_116 ;
V_99 . V_117 = ( T_5 ) V_98 -> V_118 ;
V_99 . V_119 = ( T_5 ) V_98 -> V_120 . V_121 ;
V_99 . V_122 = ( T_5 ) V_98 -> V_123 . V_121 ;
V_99 . V_124 = ( T_5 ) V_98 -> ctime . V_121 ;
return F_75 ( V_83 , & V_99 , sizeof( V_99 ) ) ? - V_25 : 0 ;
}
T_1 long F_102 ( const char T_2 * V_1 , struct V_96 T_2 * V_125 )
{
struct V_97 V_98 ;
int V_60 = F_103 ( V_1 , & V_98 ) ;
if ( ! V_60 )
V_60 = F_99 ( V_125 , & V_98 ) ;
return V_60 ;
}
T_1 long F_104 ( const char T_2 * V_1 , struct V_96 T_2 * V_125 )
{
struct V_97 V_98 ;
int V_60 = F_105 ( V_1 , & V_98 ) ;
if ( ! V_60 )
V_60 = F_99 ( V_125 , & V_98 ) ;
return V_60 ;
}
T_1 long F_106 ( unsigned long V_4 , struct V_96 T_2 * V_125 )
{
struct V_97 V_98 ;
int V_60 = F_107 ( V_4 , & V_98 ) ;
if ( ! V_60 )
V_60 = F_99 ( V_125 , & V_98 ) ;
return V_60 ;
}
T_1 long F_108 ( unsigned int V_126 , const char T_2 * V_1 ,
struct V_96 T_2 * V_125 , int V_127 )
{
struct V_97 V_98 ;
int error ;
error = F_109 ( V_126 , V_1 , & V_98 , V_127 ) ;
if ( error )
return error ;
return F_99 ( V_125 , & V_98 ) ;
}
T_1 unsigned long F_110 ( struct V_128 T_2 * V_129 )
{
struct V_128 V_130 ;
if ( F_73 ( & V_130 , V_129 , sizeof( V_130 ) ) )
return - V_25 ;
if ( V_130 . V_93 & ~ V_131 )
return - V_26 ;
V_130 . V_132 = ( unsigned long ) F_51 ( V_130 . V_132 ) ;
return F_111 ( V_130 . V_132 , V_130 . V_133 , V_130 . V_134 , V_130 . V_135 , V_130 . V_4 ,
V_130 . V_93 >> V_136 ) ;
}
T_1 long F_112 ( struct V_128 T_2 * V_129 )
{
struct V_128 V_130 ;
if ( F_73 ( & V_130 , V_129 , sizeof( V_130 ) ) )
return - V_25 ;
V_130 . V_132 = ( unsigned long ) F_51 ( V_130 . V_132 ) ;
return F_111 ( V_130 . V_132 , V_130 . V_133 , V_130 . V_134 , V_130 . V_135 , V_130 . V_4 , V_130 . V_93 ) ;
}
T_1 long F_113 ( unsigned int V_4 , char T_2 * V_137 , T_9 V_84 )
{
if ( ( V_87 ) V_84 < 0 )
return - V_26 ;
return F_114 ( V_4 , V_137 , V_84 ) ;
}
T_1 long F_115 ( unsigned int V_4 , const char T_2 * V_137 , T_9 V_84 )
{
if ( ( V_87 ) V_84 < 0 )
return - V_26 ;
return F_116 ( V_4 , V_137 , V_84 ) ;
}
T_1 long
F_117 ( int V_4 , V_88 V_93 , T_9 V_133 , int V_138 )
{
if ( V_138 == 4 )
V_138 = V_139 ;
else if ( V_138 == 5 )
V_138 = V_140 ;
return F_118 ( V_4 , V_93 , V_133 , V_138 ) ;
}
T_1 long
F_119 ( struct V_141 T_2 * args )
{
struct V_141 V_130 ;
if ( F_73 ( & V_130 , args , sizeof( V_130 ) ) )
return - V_25 ;
if ( V_130 . V_142 == 4 )
V_130 . V_142 = V_139 ;
else if ( V_130 . V_142 == 5 )
V_130 . V_142 = V_140 ;
return F_120 ( V_130 . V_4 , V_130 . V_93 , V_130 . V_133 , V_130 . V_142 ) ;
}
