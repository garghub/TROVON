static void F_1 ( void )
{
int V_1 ;
if ( ! V_2 )
return;
V_1 = F_2 ( V_2 , 0x00 , V_3 ) ;
if ( V_1 )
F_3 ( L_1 , V_1 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
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
static int F_7 ( struct V_4 * V_5 )
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
T_1 V_35 ;
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
static int F_46 ( void )
{
T_2 V_50 [] = V_51 ;
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
T_2 V_50 [] = V_51 ;
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
static int F_62 ( struct V_60 * V_61 , struct V_86 * V_87 )
{
if ( V_88 )
return 0 ;
else
return - V_77 ;
}
static int F_63 ( T_3 V_89 , T_3 V_69 , T_3 V_71 ,
T_3 V_72 , T_3 V_74 ,
struct V_60 * V_61 )
{
if ( V_89 >= V_90 )
return - V_77 ;
if ( V_61 -> V_67 . V_91 )
V_69 = V_71 = V_72 = ( V_69 * 77 + V_71 * 151 + V_72 * 28 ) >> 8 ;
if ( V_61 -> V_82 . V_92 == V_93 ) {
T_1 V_94 ;
if ( V_89 > 16 )
return - V_77 ;
V_69 >>= ( 16 - V_61 -> V_67 . V_69 . V_73 ) ;
V_71 >>= ( 16 - V_61 -> V_67 . V_71 . V_73 ) ;
V_72 >>= ( 16 - V_61 -> V_67 . V_72 . V_73 ) ;
V_94 = ( V_69 << V_61 -> V_67 . V_69 . V_70 ) |
( V_71 << V_61 -> V_67 . V_71 . V_70 ) |
( V_72 << V_61 -> V_67 . V_72 . V_70 ) ;
V_94 &= 0xFFFF ;
( ( T_1 * ) ( V_61 -> V_95 ) ) [ V_89 ] = V_94 ;
}
return 0 ;
}
static int F_64 ( struct V_96 * V_97 )
{
return V_98 ;
}
static int F_65 ( struct V_99 * V_11 )
{
return 0 ;
}
static int F_66 ( struct V_99 * V_11 , int V_100 )
{
return 0 ;
}
static int F_67 ( struct V_99 * V_11 )
{
return ( int ) V_3 ;
}
static int F_68 ( struct V_99 * V_11 , int V_101 )
{
if ( V_101 > 255 )
V_101 = 255 ;
if ( V_101 < 0 )
V_101 = 0 ;
V_3 = ( unsigned char ) V_101 ;
F_1 () ;
return 0 ;
}
static int F_69 ( struct V_99 * V_102 , struct V_60 * V_103 )
{
if ( ! V_103 || ( V_103 == & V_104 ) )
return 1 ;
return 0 ;
}
static int F_70 ( struct V_105 * V_106 )
{
struct V_107 V_108 ;
T_4 V_109 ;
int V_8 ;
if ( F_71 ( V_39 , V_53 ) ) {
F_3 ( L_10 ) ;
return - V_110 ;
}
if ( F_46 () ) {
F_3 ( L_11 ) ;
V_8 = - V_110 ;
goto V_111;
}
V_38 = F_72 ( NULL , V_112 ,
& V_109 , V_113 ) ;
if ( V_38 == NULL ) {
F_3 ( L_12 ) ;
V_8 = - V_85 ;
goto V_114;
}
if ( V_115 )
V_37 = F_73 ( V_116 ) ;
else
V_37 = F_72 ( NULL , V_116 ,
& V_109 , 0 ) ;
if ( V_37 == NULL ) {
F_3 ( L_13 ) ;
V_8 = - V_85 ;
goto V_117;
}
V_104 . V_118 = ( void * ) V_38 ;
V_119 . V_120 = ( int ) V_38 ;
if ( V_36 ) {
V_121 . V_78 = V_28 ;
V_121 . V_79 = V_30 ;
V_121 . V_80 = V_28 ;
V_121 . V_81 = V_30 ;
V_119 . V_83 = V_28 * ( V_40 / 8 ) ;
} else {
V_104 . V_118 += V_122 ;
V_119 . V_120 += V_122 ;
}
V_121 . V_71 . V_75 = 0 ;
V_121 . V_69 . V_75 = 0 ;
V_121 . V_72 . V_75 = 0 ;
V_121 . V_71 . V_70 = 5 ;
V_121 . V_71 . V_73 = 6 ;
V_121 . V_69 . V_73 = 5 ;
V_121 . V_72 . V_73 = 5 ;
if ( V_123 ) {
V_121 . V_69 . V_70 = 0 ;
V_121 . V_72 . V_70 = 11 ;
} else {
V_121 . V_69 . V_70 = 11 ;
V_121 . V_72 . V_70 = 0 ;
}
V_104 . V_124 = & V_125 ;
V_104 . V_67 = V_121 ;
V_104 . V_82 = V_119 ;
V_104 . V_13 = V_126 ;
V_104 . V_95 = F_74 ( & V_106 -> V_11 ,
sizeof( T_1 ) * 16 ,
V_113 ) ;
if ( V_104 . V_95 == NULL ) {
F_3 ( L_14 ) ;
V_8 = - V_85 ;
goto V_117;
}
if ( F_75 ( & V_104 . V_127 , V_90 , 0 ) < 0 ) {
F_3 ( L_15 ,
V_90 ) ;
V_8 = - V_110 ;
goto V_117;
}
if ( F_76 ( & V_104 ) < 0 ) {
F_3 ( L_16 ) ;
V_8 = - V_77 ;
goto V_128;
}
F_77 ( & V_129 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . type = V_130 ;
V_108 . V_131 = V_132 ;
V_133 = F_78 ( L_17 , NULL , NULL ,
& V_134 , & V_108 ) ;
V_135 = F_79 ( V_53 , & V_106 -> V_11 , NULL ,
& V_136 ) ;
if ( F_80 ( V_135 ) ) {
F_3 ( L_18 ) ;
V_8 = F_81 ( V_135 ) ;
goto V_137;
}
V_135 -> V_108 . V_138 = 255 ,
F_82 ( L_19 ) ;
return 0 ;
V_137:
F_83 ( & V_104 ) ;
V_128:
F_84 ( & V_104 . V_127 ) ;
V_117:
F_85 ( NULL , V_112 , V_38 , 0 ) ;
V_38 = NULL ;
V_114:
F_52 () ;
V_111:
F_86 ( V_39 ) ;
return V_8 ;
}
static int F_87 ( struct V_105 * V_106 )
{
if ( V_38 != NULL )
F_85 ( NULL , V_112 , V_38 , 0 ) ;
if ( V_115 )
F_88 ( V_37 ) ;
else
F_85 ( NULL , V_116 , NULL , 0 ) ;
F_16 ( V_16 | V_17 | V_18 |
V_15 | V_14 ) ;
V_19 = 0 ;
F_86 ( V_39 ) ;
F_84 ( & V_104 . V_127 ) ;
F_89 ( V_135 ) ;
F_90 ( V_133 ) ;
F_83 ( & V_104 ) ;
F_91 ( & V_129 ) ;
F_52 () ;
F_82 ( L_20 ) ;
return 0 ;
}
static int F_92 ( struct V_105 * V_106 , T_5 V_139 )
{
if ( V_64 > 0 ) {
F_36 ( 0 ) ;
F_11 () ;
F_59 ( V_39 ) ;
}
return 0 ;
}
static int F_93 ( struct V_105 * V_106 )
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
static int T_6 F_94 ( void )
{
F_95 ( L_21 ) ;
return F_96 ( & V_140 ) ;
}
static void T_7 F_97 ( void )
{
F_98 ( & V_140 ) ;
}
