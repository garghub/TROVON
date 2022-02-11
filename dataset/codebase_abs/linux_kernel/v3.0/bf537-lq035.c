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
if ( F_50 ( V_55 , V_53 ) ) {
F_3 ( L_6 , V_55 ) ;
return - V_54 ;
}
if ( F_50 ( V_56 , V_53 ) ) {
F_3 ( L_6 , V_56 ) ;
F_51 ( V_55 ) ;
return - V_54 ;
}
F_52 ( V_55 , 0 ) ;
F_52 ( V_56 , 1 ) ;
#endif
if ( F_50 ( V_57 , V_53 ) ) {
F_3 ( L_6 , V_57 ) ;
#if ( F_49 ( V_55 ) && F_49 ( V_56 ) )
F_51 ( V_56 ) ;
F_51 ( V_55 ) ;
#endif
return - V_54 ;
}
F_52 ( V_57 , 1 ) ;
F_11 () ;
return 0 ;
}
static void F_53 ( void )
{
T_4 V_50 [] = V_51 ;
F_48 ( V_52 ) ;
F_48 ( V_50 ) ;
#if F_49 ( V_55 ) && F_49 ( V_56 )
F_51 ( V_56 ) ;
F_51 ( V_55 ) ;
#endif
F_51 ( V_57 ) ;
}
static int F_54 ( struct V_58 * V_59 , int V_60 )
{
unsigned long V_13 ;
F_55 ( & V_61 , V_13 ) ;
V_62 ++ ;
F_56 ( & V_61 , V_13 ) ;
if ( V_62 <= 1 ) {
F_36 ( 0 ) ;
F_11 () ;
F_1 () ;
F_37 () ;
F_33 () ;
F_57 ( V_39 ) ;
F_11 () ;
F_36 ( F_58 () | V_63 ) ;
F_11 () ;
if ( ! V_19 ) {
F_15 () ;
F_8 () ;
}
}
return 0 ;
}
static int F_59 ( struct V_58 * V_59 , int V_60 )
{
unsigned long V_13 ;
F_55 ( & V_61 , V_13 ) ;
V_62 -- ;
F_56 ( & V_61 , V_13 ) ;
if ( V_62 <= 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_60 ( V_39 ) ;
}
return 0 ;
}
static int F_61 ( struct V_64 * V_65 ,
struct V_58 * V_59 )
{
switch ( V_65 -> V_66 ) {
case 16 :
V_65 -> V_67 . V_68 = V_59 -> V_65 . V_67 . V_68 ;
V_65 -> V_69 . V_68 = V_59 -> V_65 . V_69 . V_68 ;
V_65 -> V_70 . V_68 = V_59 -> V_65 . V_70 . V_68 ;
V_65 -> V_67 . V_71 = V_59 -> V_65 . V_67 . V_71 ;
V_65 -> V_69 . V_71 = V_59 -> V_65 . V_69 . V_71 ;
V_65 -> V_70 . V_71 = V_59 -> V_65 . V_70 . V_71 ;
V_65 -> V_72 . V_68 = 0 ;
V_65 -> V_72 . V_71 = 0 ;
V_65 -> V_72 . V_73 = 0 ;
V_65 -> V_67 . V_73 = 0 ;
V_65 -> V_69 . V_73 = 0 ;
V_65 -> V_70 . V_73 = 0 ;
break;
default:
F_62 ( L_7 , V_74 ,
V_65 -> V_66 ) ;
return - V_75 ;
}
if ( V_59 -> V_65 . V_76 != V_65 -> V_76 ||
V_59 -> V_65 . V_77 != V_65 -> V_77 ||
V_59 -> V_65 . V_78 != V_65 -> V_78 ||
V_59 -> V_65 . V_79 != V_65 -> V_79 ) {
F_62 ( L_8 ,
V_74 , V_65 -> V_76 , V_65 -> V_77 ) ;
return - V_75 ;
}
if ( ( V_59 -> V_80 . V_81 * V_65 -> V_79 ) > V_59 -> V_80 . V_82 ) {
F_62 ( L_9 ,
V_74 , V_65 -> V_79 ) ;
return - V_83 ;
}
return 0 ;
}
static void F_63 ( struct V_58 * V_84 , int V_85 )
{
F_62 ( L_10 , V_74 , V_84 , V_85 ) ;
#if ( F_49 ( V_55 ) && F_49 ( V_56 ) )
switch ( V_85 ) {
case 180 :
F_64 ( V_56 , 0 ) ;
F_64 ( V_55 , 1 ) ;
break;
default:
F_64 ( V_56 , 1 ) ;
F_64 ( V_55 , 0 ) ;
break;
}
#endif
}
static int F_65 ( struct V_58 * V_59 , struct V_86 * V_87 )
{
if ( V_88 )
return 0 ;
else
return - V_75 ;
}
static int F_66 ( T_5 V_89 , T_5 V_67 , T_5 V_69 ,
T_5 V_70 , T_5 V_72 ,
struct V_58 * V_59 )
{
if ( V_89 >= V_90 )
return - V_75 ;
if ( V_59 -> V_65 . V_91 )
V_67 = V_69 = V_70 = ( V_67 * 77 + V_69 * 151 + V_70 * 28 ) >> 8 ;
if ( V_59 -> V_80 . V_92 == V_93 ) {
T_3 V_94 ;
if ( V_89 > 16 )
return - V_75 ;
V_67 >>= ( 16 - V_59 -> V_65 . V_67 . V_71 ) ;
V_69 >>= ( 16 - V_59 -> V_65 . V_69 . V_71 ) ;
V_70 >>= ( 16 - V_59 -> V_65 . V_70 . V_71 ) ;
V_94 = ( V_67 << V_59 -> V_65 . V_67 . V_68 ) |
( V_69 << V_59 -> V_65 . V_69 . V_68 ) |
( V_70 << V_59 -> V_65 . V_70 . V_68 ) ;
V_94 &= 0xFFFF ;
( ( T_3 * ) ( V_59 -> V_95 ) ) [ V_89 ] = V_94 ;
}
return 0 ;
}
static int F_67 ( struct V_96 * V_97 )
{
return V_98 ;
}
static int F_68 ( struct V_99 * V_11 )
{
return 0 ;
}
static int F_69 ( struct V_99 * V_11 , int V_100 )
{
return 0 ;
}
static int F_70 ( struct V_99 * V_11 )
{
return ( int ) V_3 ;
}
static int F_71 ( struct V_99 * V_11 , int V_101 )
{
if ( V_101 > 255 )
V_101 = 255 ;
if ( V_101 < 0 )
V_101 = 0 ;
V_3 = ( unsigned char ) V_101 ;
F_1 () ;
return 0 ;
}
static int F_72 ( struct V_99 * V_102 , struct V_58 * V_103 )
{
if ( ! V_103 || ( V_103 == & V_104 ) )
return 1 ;
return 0 ;
}
static int T_1 F_73 ( struct V_105 * V_106 )
{
struct V_107 V_108 ;
T_6 V_109 ;
int V_8 ;
if ( F_74 ( V_39 , V_53 ) ) {
F_3 ( L_11 ) ;
return - V_110 ;
}
if ( F_46 () ) {
F_3 ( L_12 ) ;
V_8 = - V_110 ;
goto V_111;
}
V_38 = F_75 ( NULL , V_112 ,
& V_109 , V_113 ) ;
if ( V_38 == NULL ) {
F_3 ( L_13 ) ;
V_8 = - V_83 ;
goto V_114;
}
if ( V_115 )
V_37 = F_76 ( V_116 ) ;
else
V_37 = F_75 ( NULL , V_116 ,
& V_109 , 0 ) ;
if ( V_37 == NULL ) {
F_3 ( L_14 ) ;
V_8 = - V_83 ;
goto V_117;
}
V_104 . V_118 = ( void * ) V_38 ;
V_119 . V_120 = ( int ) V_38 ;
if ( V_36 ) {
V_121 . V_76 = V_28 ;
V_121 . V_77 = V_30 ;
V_121 . V_78 = V_28 ;
V_121 . V_79 = V_30 ;
V_119 . V_81 = V_28 * ( V_40 / 8 ) ;
} else {
V_104 . V_118 += V_122 ;
V_119 . V_120 += V_122 ;
}
V_121 . V_69 . V_73 = 0 ;
V_121 . V_67 . V_73 = 0 ;
V_121 . V_70 . V_73 = 0 ;
V_121 . V_69 . V_68 = 5 ;
V_121 . V_69 . V_71 = 6 ;
V_121 . V_67 . V_71 = 5 ;
V_121 . V_70 . V_71 = 5 ;
if ( V_123 ) {
V_121 . V_67 . V_68 = 0 ;
V_121 . V_70 . V_68 = 11 ;
} else {
V_121 . V_67 . V_68 = 11 ;
V_121 . V_70 . V_68 = 0 ;
}
V_104 . V_124 = & V_125 ;
V_104 . V_65 = V_121 ;
V_104 . V_80 = V_119 ;
V_104 . V_13 = V_126 ;
V_104 . V_95 = F_77 ( sizeof( T_3 ) * 16 , V_113 ) ;
if ( V_104 . V_95 == NULL ) {
F_3 ( L_15 ) ;
V_8 = - V_83 ;
goto V_127;
}
if ( F_78 ( & V_104 . V_128 , V_90 , 0 ) < 0 ) {
F_3 ( L_16 ,
V_90 ) ;
V_8 = - V_110 ;
goto V_129;
}
if ( F_79 ( & V_104 ) < 0 ) {
F_3 ( L_17 ) ;
V_8 = - V_75 ;
goto V_130;
}
F_80 ( & V_131 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . type = V_132 ;
V_108 . V_133 = V_134 ;
V_135 = F_81 ( L_18 , NULL , NULL ,
& V_136 , & V_108 ) ;
V_137 = F_82 ( V_53 , & V_106 -> V_11 , NULL ,
& V_138 ) ;
if ( F_83 ( V_137 ) ) {
F_3 ( L_19 ) ;
V_8 = F_84 ( V_137 ) ;
goto V_139;
}
V_137 -> V_108 . V_140 = 255 ,
F_85 ( L_20 ) ;
return 0 ;
V_139:
F_86 ( & V_104 ) ;
V_130:
F_87 ( & V_104 . V_128 ) ;
V_129:
F_88 ( V_104 . V_95 ) ;
V_127:
V_117:
F_89 ( NULL , V_112 , V_38 , 0 ) ;
V_38 = NULL ;
V_114:
F_53 () ;
V_111:
F_90 ( V_39 ) ;
return V_8 ;
}
static int T_2 F_91 ( struct V_105 * V_106 )
{
if ( V_38 != NULL )
F_89 ( NULL , V_112 , V_38 , 0 ) ;
if ( V_115 )
F_92 ( V_37 ) ;
else
F_89 ( NULL , V_116 , NULL , 0 ) ;
F_16 ( V_16 | V_17 | V_18 |
V_15 | V_14 ) ;
V_19 = 0 ;
F_90 ( V_39 ) ;
F_88 ( V_104 . V_95 ) ;
F_87 ( & V_104 . V_128 ) ;
F_93 ( V_137 ) ;
F_94 ( V_135 ) ;
F_86 ( & V_104 ) ;
F_95 ( & V_131 ) ;
F_53 () ;
F_85 ( L_21 ) ;
return 0 ;
}
static int F_96 ( struct V_105 * V_106 , T_7 V_141 )
{
if ( V_62 > 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_60 ( V_39 ) ;
}
return 0 ;
}
static int F_97 ( struct V_105 * V_106 )
{
if ( V_62 > 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_37 () ;
F_33 () ;
F_57 ( V_39 ) ;
F_36 ( F_58 () | V_63 ) ;
F_11 () ;
F_15 () ;
F_8 () ;
} else {
V_19 = 0 ;
}
return 0 ;
}
static int T_8 F_98 ( void )
{
F_99 ( L_22 ) ;
return F_100 ( & V_142 ) ;
}
static void T_9 F_101 ( void )
{
F_102 ( & V_142 ) ;
}
