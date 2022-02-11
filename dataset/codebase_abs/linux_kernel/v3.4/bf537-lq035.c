static void F_1 ( void )
{
int V_1 ;
if ( ! V_2 )
return;
V_1 = F_2 ( V_2 , 0x00 , V_3 ) ;
if ( V_1 )
F_3 ( L_1 , V_1 ) ;
}
static int T_1 F_4 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
int V_8 ;
if ( ! F_5 ( V_5 -> V_9 ,
V_10 ) ) {
F_6 ( & V_5 -> V_11 , L_2 ) ;
return - V_12 ;
}
V_8 = F_2 ( V_5 , 0x00 , V_3 ) ;
if ( V_8 ) {
F_6 ( & V_5 -> V_11 , L_3 , V_8 ) ;
return V_8 ;
}
V_2 = V_5 ;
return 0 ;
}
static int T_2 F_7 ( struct V_4 * V_5 )
{
V_2 = NULL ;
return 0 ;
}
static void F_8 ( void )
{
unsigned long V_13 ;
F_9 ( V_13 ) ;
F_10 ( V_14 ) ;
F_11 () ;
while ( F_12 () <= 11 )
continue;
F_10 ( V_15 ) ;
F_11 () ;
while ( F_13 () < 3 )
continue;
F_10 ( V_16 | V_17 | V_18 ) ;
F_11 () ;
V_19 = 1 ;
F_14 ( V_13 ) ;
}
static void F_15 ( void )
{
F_16 ( V_20 | V_21 | V_22 |
V_23 | V_24 ) ;
F_11 () ;
F_17 ( V_25 | V_26 ) ;
F_18 ( 1 ) ;
F_19 ( V_27 ) ;
F_11 () ;
F_20 ( V_25 | V_26 ) ;
F_21 ( V_27 * 2 ) ;
F_22 ( ( V_27 * ( V_28 + V_29 ) ) ) ;
F_11 () ;
F_23 ( V_25 | V_26 ) ;
F_24 ( 1 ) ;
F_25 ( V_27 ) ;
F_11 () ;
F_26 ( V_25 ) ;
F_27 ( V_30 + V_31 ) ;
F_28 ( V_27 ) ;
F_11 () ;
#ifdef F_29
F_30 ( V_25 | V_26 ) ;
F_31 ( V_27 ) ;
F_32 ( V_27 * 2 ) ;
F_11 () ;
#endif
}
static void F_33 ( void )
{
F_34 ( V_32 ) ;
F_35 ( V_30 - 1 ) ;
F_36 ( ( V_33 | 0x10 ) & ( ~ V_34 ) ) ;
}
static int F_37 ( void )
{
T_3 V_35 ;
if ( V_36 ) {
for ( V_35 = 0 ; V_35 < V_29 ; ++ V_35 ) {
V_37 [ 2 * V_35 ] = ( unsigned long ) & V_37 [ 2 * V_35 + 2 ] ;
V_37 [ 2 * V_35 + 1 ] = ( unsigned long ) V_38 ;
}
for ( V_35 = V_29 ; V_35 < V_29 + V_28 ; ++ V_35 ) {
V_37 [ 2 * V_35 ] = ( unsigned long ) & V_37 [ 2 * V_35 + 2 ] ;
V_37 [ 2 * V_35 + 1 ] = ( unsigned long ) V_38 +
( V_28 + V_29 - 1 - V_35 ) * 2 ;
}
V_37 [ 2 * ( V_28 + V_29 - 1 ) ] = ( unsigned long ) & V_37 [ 0 ] ;
F_38 ( V_39 , V_30 ) ;
F_39 ( V_39 , V_28 * ( V_40 / 8 ) ) ;
F_40 ( V_39 , 0 ) ;
F_41 ( V_39 , 0 ) ;
F_42 ( V_39 , ( void * ) V_37 [ 0 ] ) ;
F_43 ( V_39 , V_41 | V_42 | V_43 ) ;
} else {
F_43 ( V_39 , F_44 ( V_44 ,
V_45 ,
V_46 ,
V_47 ,
V_48 ,
V_49 ) ) ;
F_38 ( V_39 , V_30 ) ;
F_39 ( V_39 , V_40 / 8 ) ;
F_40 ( V_39 , V_28 + V_29 ) ;
F_41 ( V_39 , V_40 / 8 ) ;
F_45 ( V_39 , ( unsigned long ) V_38 ) ;
}
return 0 ;
}
static int T_1 F_46 ( void )
{
T_4 V_50 [] = V_51 ;
if ( F_47 ( V_52 , V_53 ) ) {
F_3 ( L_4 ) ;
return - V_54 ;
}
if ( F_47 ( V_50 , V_53 ) ) {
F_48 ( V_52 ) ;
F_3 ( L_5 ) ;
return - V_54 ;
}
#if ( F_49 ( V_55 ) && F_49 ( V_56 ) )
if ( F_50 ( V_55 , V_57 , V_53 ) ) {
F_3 ( L_6 , V_55 ) ;
return - V_54 ;
}
if ( F_50 ( V_56 , V_58 , V_53 ) ) {
F_3 ( L_6 , V_56 ) ;
F_51 ( V_55 ) ;
return - V_54 ;
}
#endif
if ( F_50 ( V_59 , V_58 , V_53 ) ) {
F_3 ( L_6 , V_59 ) ;
#if ( F_49 ( V_55 ) && F_49 ( V_56 ) )
F_51 ( V_56 ) ;
F_51 ( V_55 ) ;
#endif
return - V_54 ;
}
F_11 () ;
return 0 ;
}
static void F_52 ( void )
{
T_4 V_50 [] = V_51 ;
F_48 ( V_52 ) ;
F_48 ( V_50 ) ;
#if F_49 ( V_55 ) && F_49 ( V_56 )
F_51 ( V_56 ) ;
F_51 ( V_55 ) ;
#endif
F_51 ( V_59 ) ;
}
static int F_53 ( struct V_60 * V_61 , int V_62 )
{
unsigned long V_13 ;
F_54 ( & V_63 , V_13 ) ;
V_64 ++ ;
F_55 ( & V_63 , V_13 ) ;
if ( V_64 <= 1 ) {
F_36 ( 0 ) ;
F_11 () ;
F_1 () ;
F_37 () ;
F_33 () ;
F_56 ( V_39 ) ;
F_11 () ;
F_36 ( F_57 () | V_65 ) ;
F_11 () ;
if ( ! V_19 ) {
F_15 () ;
F_8 () ;
}
}
return 0 ;
}
static int F_58 ( struct V_60 * V_61 , int V_62 )
{
unsigned long V_13 ;
F_54 ( & V_63 , V_13 ) ;
V_64 -- ;
F_55 ( & V_63 , V_13 ) ;
if ( V_64 <= 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_59 ( V_39 ) ;
}
return 0 ;
}
static int F_60 ( struct V_66 * V_67 ,
struct V_60 * V_61 )
{
switch ( V_67 -> V_68 ) {
case 16 :
V_67 -> V_69 . V_70 = V_61 -> V_67 . V_69 . V_70 ;
V_67 -> V_71 . V_70 = V_61 -> V_67 . V_71 . V_70 ;
V_67 -> V_72 . V_70 = V_61 -> V_67 . V_72 . V_70 ;
V_67 -> V_69 . V_73 = V_61 -> V_67 . V_69 . V_73 ;
V_67 -> V_71 . V_73 = V_61 -> V_67 . V_71 . V_73 ;
V_67 -> V_72 . V_73 = V_61 -> V_67 . V_72 . V_73 ;
V_67 -> V_74 . V_70 = 0 ;
V_67 -> V_74 . V_73 = 0 ;
V_67 -> V_74 . V_75 = 0 ;
V_67 -> V_69 . V_75 = 0 ;
V_67 -> V_71 . V_75 = 0 ;
V_67 -> V_72 . V_75 = 0 ;
break;
default:
F_61 ( L_7 , V_76 ,
V_67 -> V_68 ) ;
return - V_77 ;
}
if ( V_61 -> V_67 . V_78 != V_67 -> V_78 ||
V_61 -> V_67 . V_79 != V_67 -> V_79 ||
V_61 -> V_67 . V_80 != V_67 -> V_80 ||
V_61 -> V_67 . V_81 != V_67 -> V_81 ) {
F_61 ( L_8 ,
V_76 , V_67 -> V_78 , V_67 -> V_79 ) ;
return - V_77 ;
}
if ( ( V_61 -> V_82 . V_83 * V_67 -> V_81 ) > V_61 -> V_82 . V_84 ) {
F_61 ( L_9 ,
V_76 , V_67 -> V_81 ) ;
return - V_85 ;
}
return 0 ;
}
static void F_62 ( struct V_60 * V_86 , int V_87 )
{
F_61 ( L_10 , V_76 , V_86 , V_87 ) ;
#if ( F_49 ( V_55 ) && F_49 ( V_56 ) )
switch ( V_87 ) {
case 180 :
F_63 ( V_56 , 0 ) ;
F_63 ( V_55 , 1 ) ;
break;
default:
F_63 ( V_56 , 1 ) ;
F_63 ( V_55 , 0 ) ;
break;
}
#endif
}
static int F_64 ( struct V_60 * V_61 , struct V_88 * V_89 )
{
if ( V_90 )
return 0 ;
else
return - V_77 ;
}
static int F_65 ( T_5 V_91 , T_5 V_69 , T_5 V_71 ,
T_5 V_72 , T_5 V_74 ,
struct V_60 * V_61 )
{
if ( V_91 >= V_92 )
return - V_77 ;
if ( V_61 -> V_67 . V_93 )
V_69 = V_71 = V_72 = ( V_69 * 77 + V_71 * 151 + V_72 * 28 ) >> 8 ;
if ( V_61 -> V_82 . V_94 == V_95 ) {
T_3 V_96 ;
if ( V_91 > 16 )
return - V_77 ;
V_69 >>= ( 16 - V_61 -> V_67 . V_69 . V_73 ) ;
V_71 >>= ( 16 - V_61 -> V_67 . V_71 . V_73 ) ;
V_72 >>= ( 16 - V_61 -> V_67 . V_72 . V_73 ) ;
V_96 = ( V_69 << V_61 -> V_67 . V_69 . V_70 ) |
( V_71 << V_61 -> V_67 . V_71 . V_70 ) |
( V_72 << V_61 -> V_67 . V_72 . V_70 ) ;
V_96 &= 0xFFFF ;
( ( T_3 * ) ( V_61 -> V_97 ) ) [ V_91 ] = V_96 ;
}
return 0 ;
}
static int F_66 ( struct V_98 * V_99 )
{
return V_100 ;
}
static int F_67 ( struct V_101 * V_11 )
{
return 0 ;
}
static int F_68 ( struct V_101 * V_11 , int V_102 )
{
return 0 ;
}
static int F_69 ( struct V_101 * V_11 )
{
return ( int ) V_3 ;
}
static int F_70 ( struct V_101 * V_11 , int V_103 )
{
if ( V_103 > 255 )
V_103 = 255 ;
if ( V_103 < 0 )
V_103 = 0 ;
V_3 = ( unsigned char ) V_103 ;
F_1 () ;
return 0 ;
}
static int F_71 ( struct V_101 * V_104 , struct V_60 * V_105 )
{
if ( ! V_105 || ( V_105 == & V_106 ) )
return 1 ;
return 0 ;
}
static int T_1 F_72 ( struct V_107 * V_108 )
{
struct V_109 V_110 ;
T_6 V_111 ;
int V_8 ;
if ( F_73 ( V_39 , V_53 ) ) {
F_3 ( L_11 ) ;
return - V_112 ;
}
if ( F_46 () ) {
F_3 ( L_12 ) ;
V_8 = - V_112 ;
goto V_113;
}
V_38 = F_74 ( NULL , V_114 ,
& V_111 , V_115 ) ;
if ( V_38 == NULL ) {
F_3 ( L_13 ) ;
V_8 = - V_85 ;
goto V_116;
}
if ( V_117 )
V_37 = F_75 ( V_118 ) ;
else
V_37 = F_74 ( NULL , V_118 ,
& V_111 , 0 ) ;
if ( V_37 == NULL ) {
F_3 ( L_14 ) ;
V_8 = - V_85 ;
goto V_119;
}
V_106 . V_120 = ( void * ) V_38 ;
V_121 . V_122 = ( int ) V_38 ;
if ( V_36 ) {
V_123 . V_78 = V_28 ;
V_123 . V_79 = V_30 ;
V_123 . V_80 = V_28 ;
V_123 . V_81 = V_30 ;
V_121 . V_83 = V_28 * ( V_40 / 8 ) ;
} else {
V_106 . V_120 += V_124 ;
V_121 . V_122 += V_124 ;
}
V_123 . V_71 . V_75 = 0 ;
V_123 . V_69 . V_75 = 0 ;
V_123 . V_72 . V_75 = 0 ;
V_123 . V_71 . V_70 = 5 ;
V_123 . V_71 . V_73 = 6 ;
V_123 . V_69 . V_73 = 5 ;
V_123 . V_72 . V_73 = 5 ;
if ( V_125 ) {
V_123 . V_69 . V_70 = 0 ;
V_123 . V_72 . V_70 = 11 ;
} else {
V_123 . V_69 . V_70 = 11 ;
V_123 . V_72 . V_70 = 0 ;
}
V_106 . V_126 = & V_127 ;
V_106 . V_67 = V_123 ;
V_106 . V_82 = V_121 ;
V_106 . V_13 = V_128 ;
V_106 . V_97 = F_76 ( sizeof( T_3 ) * 16 , V_115 ) ;
if ( V_106 . V_97 == NULL ) {
F_3 ( L_15 ) ;
V_8 = - V_85 ;
goto V_129;
}
if ( F_77 ( & V_106 . V_130 , V_92 , 0 ) < 0 ) {
F_3 ( L_16 ,
V_92 ) ;
V_8 = - V_112 ;
goto V_131;
}
if ( F_78 ( & V_106 ) < 0 ) {
F_3 ( L_17 ) ;
V_8 = - V_77 ;
goto V_132;
}
F_79 ( & V_133 ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . type = V_134 ;
V_110 . V_135 = V_136 ;
V_137 = F_80 ( L_18 , NULL , NULL ,
& V_138 , & V_110 ) ;
V_139 = F_81 ( V_53 , & V_108 -> V_11 , NULL ,
& V_140 ) ;
if ( F_82 ( V_139 ) ) {
F_3 ( L_19 ) ;
V_8 = F_83 ( V_139 ) ;
goto V_141;
}
V_139 -> V_110 . V_142 = 255 ,
F_84 ( L_20 ) ;
return 0 ;
V_141:
F_85 ( & V_106 ) ;
V_132:
F_86 ( & V_106 . V_130 ) ;
V_131:
F_87 ( V_106 . V_97 ) ;
V_129:
V_119:
F_88 ( NULL , V_114 , V_38 , 0 ) ;
V_38 = NULL ;
V_116:
F_52 () ;
V_113:
F_89 ( V_39 ) ;
return V_8 ;
}
static int T_2 F_90 ( struct V_107 * V_108 )
{
if ( V_38 != NULL )
F_88 ( NULL , V_114 , V_38 , 0 ) ;
if ( V_117 )
F_91 ( V_37 ) ;
else
F_88 ( NULL , V_118 , NULL , 0 ) ;
F_16 ( V_16 | V_17 | V_18 |
V_15 | V_14 ) ;
V_19 = 0 ;
F_89 ( V_39 ) ;
F_87 ( V_106 . V_97 ) ;
F_86 ( & V_106 . V_130 ) ;
F_92 ( V_139 ) ;
F_93 ( V_137 ) ;
F_85 ( & V_106 ) ;
F_94 ( & V_133 ) ;
F_52 () ;
F_84 ( L_21 ) ;
return 0 ;
}
static int F_95 ( struct V_107 * V_108 , T_7 V_143 )
{
if ( V_64 > 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_59 ( V_39 ) ;
}
return 0 ;
}
static int F_96 ( struct V_107 * V_108 )
{
if ( V_64 > 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_37 () ;
F_33 () ;
F_56 ( V_39 ) ;
F_36 ( F_57 () | V_65 ) ;
F_11 () ;
F_15 () ;
F_8 () ;
} else {
V_19 = 0 ;
}
return 0 ;
}
static int T_8 F_97 ( void )
{
F_98 ( L_22 ) ;
return F_99 ( & V_144 ) ;
}
static void T_9 F_100 ( void )
{
F_101 ( & V_144 ) ;
}
