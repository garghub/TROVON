void F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned long V_3 ;
long V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( F_3 ( V_9 ) )
F_4 ( V_1 ) . V_10 = 1 ;
V_3 = F_5 ( & F_4 ( V_1 ) ) ;
V_4 = F_6 ( V_2 , V_3 ) ;
if ( V_4 ) {
F_7 ( L_1
L_2 , V_1 , V_2 , V_3 , V_4 ) ;
return;
}
V_3 = F_5 ( & V_11 [ V_1 ] ) ;
if ( F_8 ( V_12 ) ) {
V_4 = F_9 ( V_2 , V_3 ) ;
if ( V_4 )
F_7 ( L_3
L_4 ,
V_1 , V_2 , V_3 , V_4 ) ;
}
V_6 = & V_13 [ V_1 ] ;
V_8 = V_6 -> V_14 ;
if ( V_8 ) {
V_6 -> V_15 = 0 ;
V_6 -> V_16 = V_8 ;
F_4 ( V_1 ) . V_17 = 0 ;
V_8 -> V_18 = V_19 ;
V_4 = F_10 ( V_2 , F_5 ( V_8 ) ) ;
if ( V_4 )
F_7 ( L_5
L_6 , F_11 () ,
V_2 , V_4 ) ;
F_4 ( V_1 ) . V_20 = 2 ;
}
}
static long F_12 ( unsigned long V_21 ,
unsigned long V_22 , unsigned long V_23 ,
unsigned long V_24 , unsigned long V_25 ,
int V_26 , int V_27 , int V_28 )
{
unsigned long V_29 ;
unsigned long V_30 ;
unsigned long V_31 ;
unsigned long V_32 , V_33 ;
if ( ! ( V_25 & V_34 ) )
F_13 ( L_7
L_8 ,
V_21 , V_22 , V_23 , V_24 , V_25 , V_26 ) ;
V_32 = F_14 ( V_22 , V_26 , V_27 , V_28 ) | V_25 | V_35 ;
V_33 = F_15 ( V_23 , V_26 , V_27 ) | V_24 ;
if ( ! ( V_25 & V_34 ) )
F_13 ( L_9 , V_32 , V_33 ) ;
V_30 = 0 ;
if ( ( V_24 & V_36 ) & ! ( V_24 & V_37 ) )
V_33 &= ~ V_38 ;
if ( F_8 ( V_39 ) && ! ( V_33 & V_40 ) )
V_30 |= V_41 ;
V_29 = F_16 ( V_30 , V_21 , V_32 , V_33 , & V_31 ) ;
if ( F_17 ( V_29 == V_42 ) ) {
if ( ! ( V_25 & V_34 ) )
F_13 ( L_10 ) ;
return - 1 ;
}
if ( F_17 ( V_29 != V_43 ) ) {
if ( ! ( V_25 & V_34 ) )
F_13 ( L_11 , V_29 ) ;
return - 2 ;
}
if ( ! ( V_25 & V_34 ) )
F_13 ( L_12 , V_31 & 7 ) ;
return ( V_31 & 7 ) | ( ! ! ( V_25 & V_44 ) << 3 ) ;
}
static long F_18 ( unsigned long V_21 )
{
unsigned long V_45 ;
unsigned long V_29 ;
int V_46 ;
unsigned long V_47 , V_48 ;
V_45 = F_19 () & 0x7 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_29 = F_20 ( V_50 , V_21 + V_45 ,
( 0x1UL << 4 ) , & V_47 , & V_48 ) ;
if ( V_29 == V_43 )
return V_46 ;
F_21 ( V_29 != V_51 && V_29 != V_52 ) ;
V_45 ++ ;
V_45 &= 0x7 ;
}
return - 1 ;
}
static void F_22 ( void )
{
unsigned long V_53 = 1UL << V_54 ;
unsigned long V_55 = V_53 >> 4 ;
struct {
unsigned long V_56 ;
unsigned long V_57 ;
} V_58 [ 4 ] ;
long V_29 ;
unsigned long V_46 , V_59 ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 += 4 ) {
V_29 = F_23 ( 0 , V_46 , ( void * ) V_58 ) ;
if ( V_29 != V_43 )
continue;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
if ( ( V_58 [ V_59 ] . V_56 & V_60 ) ==
V_60 )
continue;
if ( V_58 [ V_59 ] . V_56 & V_35 )
F_24 ( 0 , V_46 + V_59 , 0 ,
& ( V_58 [ V_59 ] . V_56 ) , & ( V_58 [ V_59 ] . V_57 ) ) ;
}
}
}
static long F_25 ( unsigned long V_31 ,
unsigned long V_61 ,
unsigned long V_22 ,
int V_26 , int V_28 , int V_62 )
{
unsigned long V_29 ;
unsigned long V_30 = ( V_61 & 7 ) | V_63 ;
unsigned long V_64 ;
V_64 = F_26 ( V_22 , V_26 , V_28 ) ;
F_13 ( L_13 ,
V_64 , V_31 , V_30 , V_26 ) ;
V_29 = F_27 ( V_30 , V_31 , V_64 ) ;
if ( V_29 == V_51 ) {
F_13 ( L_14 ) ;
return - 1 ;
}
F_13 ( L_15 ) ;
F_21 ( V_29 != V_43 ) ;
return 0 ;
}
static unsigned long F_28 ( unsigned long V_31 )
{
unsigned long V_65 ;
unsigned long V_29 ;
unsigned long V_66 ;
unsigned long V_30 ;
V_30 = 0 ;
V_29 = F_29 ( V_30 , V_31 , & V_65 , & V_66 ) ;
F_21 ( V_29 != V_43 ) ;
return V_65 ;
}
static long F_30 ( unsigned long V_22 , int V_26 , int V_28 )
{
unsigned long V_67 ;
unsigned long V_46 ;
long V_31 ;
unsigned long V_64 , V_32 ;
V_67 = F_31 ( V_22 , V_68 [ V_26 ] . V_69 , V_28 ) ;
V_64 = F_26 ( V_22 , V_26 , V_28 ) ;
V_31 = ( V_67 & V_70 ) * V_49 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_32 = F_28 ( V_31 ) ;
if ( F_32 ( V_32 , V_64 ) && ( V_32 & V_35 ) )
return V_31 ;
++ V_31 ;
}
return - 1 ;
}
static void F_33 ( unsigned long V_61 ,
unsigned long V_71 ,
int V_26 , int V_28 )
{
unsigned long V_22 ;
unsigned long V_29 , V_31 , V_72 , V_30 ;
V_72 = F_34 ( V_71 , V_28 ) ;
V_22 = F_35 ( V_71 , V_72 , V_28 ) ;
V_31 = F_30 ( V_22 , V_26 , V_28 ) ;
F_21 ( V_31 == - 1 ) ;
V_30 = V_61 & 7 ;
V_29 = F_27 ( V_30 , V_31 , 0 ) ;
F_21 ( V_29 != V_43 ) ;
}
static void F_36 ( unsigned long V_31 , unsigned long V_22 ,
int V_26 , int V_28 , int V_62 )
{
unsigned long V_64 ;
unsigned long V_29 ;
unsigned long V_47 , V_48 ;
F_13 ( L_16 ,
V_31 , V_22 , V_26 , V_62 ) ;
V_64 = F_26 ( V_22 , V_26 , V_28 ) ;
V_29 = F_20 ( V_63 , V_31 , V_64 , & V_47 , & V_48 ) ;
if ( V_29 == V_51 )
return;
F_21 ( V_29 != V_43 ) ;
}
static void F_37 ( unsigned long V_71 ,
int V_26 , int V_28 )
{
unsigned long V_22 ;
unsigned long V_31 , V_72 ;
V_72 = F_34 ( V_71 , V_28 ) ;
V_22 = F_35 ( V_71 , V_72 , V_28 ) ;
V_31 = F_30 ( V_22 , V_26 , V_28 ) ;
F_21 ( V_31 == - 1 ) ;
F_36 ( V_31 , V_22 , V_26 , V_28 , 0 ) ;
}
static void F_38 ( unsigned long V_73 , int V_62 )
{
unsigned long V_22 ;
unsigned long V_46 , V_74 , V_75 ;
unsigned long V_30 = 0 ;
struct V_76 * V_77 = & F_39 ( V_76 ) ;
int V_78 = ! F_40 ( V_79 ) ;
unsigned long V_80 [ 9 ] ;
unsigned long V_67 , V_81 , V_69 , V_82 , V_31 ;
T_1 V_83 ;
int V_26 , V_28 ;
if ( V_78 )
F_41 ( & V_84 , V_30 ) ;
V_26 = V_77 -> V_26 ;
V_28 = V_77 -> V_28 ;
V_74 = 0 ;
for ( V_46 = 0 ; V_46 < V_73 ; V_46 ++ ) {
V_22 = V_77 -> V_22 [ V_46 ] ;
V_83 = V_77 -> V_83 [ V_46 ] ;
F_42 (pte, psize, vpn, index, shift) {
V_67 = F_31 ( V_22 , V_69 , V_28 ) ;
V_82 = F_43 ( V_83 , V_81 ) ;
if ( V_82 & V_85 )
V_67 = ~ V_67 ;
V_31 = ( V_67 & V_70 ) * V_49 ;
V_31 += V_82 & V_86 ;
if ( ! F_8 ( V_87 ) ) {
F_36 ( V_31 , V_22 , V_26 ,
V_28 , V_62 ) ;
} else {
V_80 [ V_74 ] = V_88 | V_89 | V_31 ;
V_80 [ V_74 + 1 ] = F_26 ( V_22 , V_26 ,
V_28 ) ;
V_74 += 2 ;
if ( V_74 == 8 ) {
V_75 = F_44 ( V_90 , V_80 ,
V_80 [ 0 ] , V_80 [ 1 ] , V_80 [ 2 ] ,
V_80 [ 3 ] , V_80 [ 4 ] , V_80 [ 5 ] ,
V_80 [ 6 ] , V_80 [ 7 ] ) ;
F_21 ( V_75 != V_43 ) ;
V_74 = 0 ;
}
}
} F_45 () ;
}
if ( V_74 ) {
V_80 [ V_74 ] = V_91 ;
V_75 = F_44 ( V_90 , V_80 , V_80 [ 0 ] , V_80 [ 1 ] ,
V_80 [ 2 ] , V_80 [ 3 ] , V_80 [ 4 ] , V_80 [ 5 ] ,
V_80 [ 6 ] , V_80 [ 7 ] ) ;
F_21 ( V_75 != V_43 ) ;
}
if ( V_78 )
F_46 ( & V_84 , V_30 ) ;
}
static int T_2 F_47 ( char * V_92 )
{
if ( strcmp ( V_92 , L_17 ) == 0 &&
F_8 ( V_87 ) ) {
F_48 ( V_93 L_18 ) ;
V_94 &= ~ V_87 ;
}
return 1 ;
}
void T_2 F_49 ( void )
{
V_95 . V_96 = F_36 ;
V_95 . V_97 = F_25 ;
V_95 . V_98 = F_33 ;
V_95 . V_99 = F_12 ;
V_95 . V_100 = F_18 ;
V_95 . V_101 = F_37 ;
V_95 . V_102 = F_38 ;
V_95 . V_103 = F_22 ;
}
static int T_2 F_50 ( char * V_92 )
{
char * V_104 ;
V_104 = F_51 ( V_92 ) ;
if ( strcasecmp ( V_104 , L_19 ) == 0 || strcasecmp ( V_104 , L_17 ) == 0 ) {
F_48 ( V_93 L_20 ) ;
V_105 = 0 ;
return 1 ;
}
V_105 = 1 ;
F_48 ( V_93 L_21 ) ;
if ( strcasecmp ( V_104 , L_22 ) == 0 || strcasecmp ( V_104 , L_23 ) == 0 )
return 1 ;
return 0 ;
}
static void F_52 ( struct V_106 * V_106 , int V_107 ,
unsigned long V_108 )
{
int V_46 , V_59 ;
unsigned long V_109 , V_3 ;
V_109 = F_53 () ;
V_3 = F_5 ( ( unsigned long ) F_54 ( V_106 ) ) ;
for ( V_46 = 0 ; V_46 < ( 1 << V_107 ) ; V_46 ++ , V_3 += V_110 ) {
for ( V_59 = 0 ; V_59 < V_110 ; V_59 += V_109 )
F_55 ( V_111 , V_108 , V_3 + V_59 , 0 ) ;
}
}
void F_56 ( struct V_106 * V_106 , int V_107 )
{
if ( ! V_105 || ! F_8 ( V_112 ) )
return;
F_52 ( V_106 , V_107 , V_113 ) ;
}
void F_57 ( void )
{
V_114 ++ ;
}
void F_58 ( void )
{
V_114 -- ;
}
void F_59 ( unsigned long V_115 , unsigned long * args )
{
unsigned long V_30 ;
unsigned int * V_116 ;
if ( V_115 == V_117 )
return;
F_60 ( V_30 ) ;
V_116 = & F_39 ( V_118 ) ;
if ( * V_116 )
goto V_119;
( * V_116 ) ++ ;
F_61 () ;
F_62 ( V_115 , args ) ;
( * V_116 ) -- ;
V_119:
F_63 ( V_30 ) ;
}
void F_64 ( long V_115 , unsigned long V_120 ,
unsigned long * V_121 )
{
unsigned long V_30 ;
unsigned int * V_116 ;
if ( V_115 == V_117 )
return;
F_60 ( V_30 ) ;
V_116 = & F_39 ( V_118 ) ;
if ( * V_116 )
goto V_119;
( * V_116 ) ++ ;
F_65 ( V_115 , V_120 , V_121 ) ;
F_66 () ;
( * V_116 ) -- ;
V_119:
F_63 ( V_30 ) ;
}
int F_67 ( struct V_122 * V_123 )
{
int V_75 ;
unsigned long V_121 [ V_124 ] ;
V_75 = F_44 ( V_125 , V_121 ) ;
V_123 -> V_126 = V_121 [ 0 ] ;
V_123 -> V_127 = V_121 [ 1 ] ;
V_123 -> V_128 = ( V_121 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_123 -> V_129 = V_121 [ 2 ] & 0xffff ;
V_123 -> V_130 = ( V_121 [ 3 ] >> 7 * 8 ) & 0xff ;
V_123 -> V_131 = ( V_121 [ 3 ] >> 6 * 8 ) & 0xff ;
V_123 -> V_132 = V_121 [ 3 ] & 0xffffffffffff ;
V_123 -> V_133 = V_121 [ 4 ] ;
V_123 -> V_134 = V_121 [ 5 ] ;
V_123 -> V_135 = V_121 [ 6 ] ;
return V_75 ;
}
int F_68 ( struct V_136 * V_137 )
{
int V_75 ;
unsigned long V_121 [ V_124 ] = { 0 } ;
V_75 = F_44 ( V_138 , V_121 ) ;
V_137 -> V_139 = V_121 [ 0 ] ;
V_137 -> V_140 = V_121 [ 1 ] ;
V_137 -> V_141 = V_121 [ 2 ] ;
V_137 -> V_142 = V_121 [ 3 ] ;
return V_75 ;
}
