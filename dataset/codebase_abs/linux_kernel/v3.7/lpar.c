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
int V_26 , int V_27 )
{
unsigned long V_28 ;
unsigned long V_29 ;
unsigned long V_30 ;
unsigned long V_31 , V_32 ;
if ( ! ( V_25 & V_33 ) )
F_13 ( L_7
L_8 ,
V_21 , V_22 , V_23 , V_24 , V_25 , V_26 ) ;
V_31 = F_14 ( V_22 , V_26 , V_27 ) | V_25 | V_34 ;
V_32 = F_15 ( V_23 , V_26 ) | V_24 ;
if ( ! ( V_25 & V_33 ) )
F_13 ( L_9 , V_31 , V_32 ) ;
V_29 = 0 ;
if ( ( V_24 & V_35 ) & ! ( V_24 & V_36 ) )
V_32 &= ~ V_37 ;
if ( F_8 ( V_38 ) && ! ( V_32 & V_39 ) )
V_29 |= V_40 ;
V_28 = F_16 ( V_29 , V_21 , V_31 , V_32 , & V_30 ) ;
if ( F_17 ( V_28 == V_41 ) ) {
if ( ! ( V_25 & V_33 ) )
F_13 ( L_10 ) ;
return - 1 ;
}
if ( F_17 ( V_28 != V_42 ) ) {
if ( ! ( V_25 & V_33 ) )
F_13 ( L_11 , V_28 ) ;
return - 2 ;
}
if ( ! ( V_25 & V_33 ) )
F_13 ( L_12 , V_30 & 7 ) ;
return ( V_30 & 7 ) | ( ! ! ( V_25 & V_43 ) << 3 ) ;
}
static long F_18 ( unsigned long V_21 )
{
unsigned long V_44 ;
unsigned long V_28 ;
int V_45 ;
unsigned long V_46 , V_47 ;
V_44 = F_19 () & 0x7 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_28 = F_20 ( V_49 , V_21 + V_44 ,
( 0x1UL << 4 ) , & V_46 , & V_47 ) ;
if ( V_28 == V_42 )
return V_45 ;
F_21 ( V_28 != V_50 ) ;
V_44 ++ ;
V_44 &= 0x7 ;
}
return - 1 ;
}
static void F_22 ( void )
{
unsigned long V_51 = 1UL << V_52 ;
unsigned long V_53 = V_51 >> 4 ;
struct {
unsigned long V_54 ;
unsigned long V_55 ;
} V_56 [ 4 ] ;
long V_28 ;
unsigned long V_45 , V_57 ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 += 4 ) {
V_28 = F_23 ( 0 , V_45 , ( void * ) V_56 ) ;
if ( V_28 != V_42 )
continue;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
if ( ( V_56 [ V_57 ] . V_54 & V_58 ) ==
V_58 )
continue;
if ( V_56 [ V_57 ] . V_54 & V_34 )
F_24 ( 0 , V_45 + V_57 , 0 ,
& ( V_56 [ V_57 ] . V_54 ) , & ( V_56 [ V_57 ] . V_55 ) ) ;
}
}
}
static long F_25 ( unsigned long V_30 ,
unsigned long V_59 ,
unsigned long V_22 ,
int V_26 , int V_27 , int V_60 )
{
unsigned long V_28 ;
unsigned long V_29 = ( V_59 & 7 ) | V_61 ;
unsigned long V_62 ;
V_62 = F_26 ( V_22 , V_26 , V_27 ) ;
F_13 ( L_13 ,
V_62 , V_30 , V_29 , V_26 ) ;
V_28 = F_27 ( V_29 , V_30 , V_62 ) ;
if ( V_28 == V_50 ) {
F_13 ( L_14 ) ;
return - 1 ;
}
F_13 ( L_15 ) ;
F_21 ( V_28 != V_42 ) ;
return 0 ;
}
static unsigned long F_28 ( unsigned long V_30 )
{
unsigned long V_63 ;
unsigned long V_28 ;
unsigned long V_64 ;
unsigned long V_29 ;
V_29 = 0 ;
V_28 = F_29 ( V_29 , V_30 , & V_63 , & V_64 ) ;
F_21 ( V_28 != V_42 ) ;
return V_63 ;
}
static long F_30 ( unsigned long V_22 , int V_26 , int V_27 )
{
unsigned long V_65 ;
unsigned long V_45 ;
long V_30 ;
unsigned long V_62 , V_31 ;
V_65 = F_31 ( V_22 , V_66 [ V_26 ] . V_67 , V_27 ) ;
V_62 = F_26 ( V_22 , V_26 , V_27 ) ;
V_30 = ( V_65 & V_68 ) * V_48 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_31 = F_28 ( V_30 ) ;
if ( F_32 ( V_31 , V_62 ) && ( V_31 & V_34 ) )
return V_30 ;
++ V_30 ;
}
return - 1 ;
}
static void F_33 ( unsigned long V_59 ,
unsigned long V_69 ,
int V_26 , int V_27 )
{
unsigned long V_22 ;
unsigned long V_28 , V_30 , V_70 , V_29 ;
V_70 = F_34 ( V_69 , V_27 ) ;
V_22 = F_35 ( V_69 , V_70 , V_27 ) ;
V_30 = F_30 ( V_22 , V_26 , V_27 ) ;
F_21 ( V_30 == - 1 ) ;
V_29 = V_59 & 7 ;
V_28 = F_27 ( V_29 , V_30 , 0 ) ;
F_21 ( V_28 != V_42 ) ;
}
static void F_36 ( unsigned long V_30 , unsigned long V_22 ,
int V_26 , int V_27 , int V_60 )
{
unsigned long V_62 ;
unsigned long V_28 ;
unsigned long V_46 , V_47 ;
F_13 ( L_16 ,
V_30 , V_22 , V_26 , V_60 ) ;
V_62 = F_26 ( V_22 , V_26 , V_27 ) ;
V_28 = F_20 ( V_61 , V_30 , V_62 , & V_46 , & V_47 ) ;
if ( V_28 == V_50 )
return;
F_21 ( V_28 != V_42 ) ;
}
static void F_37 ( unsigned long V_69 ,
int V_26 , int V_27 )
{
unsigned long V_22 ;
unsigned long V_30 , V_70 ;
V_70 = F_34 ( V_69 , V_27 ) ;
V_22 = F_35 ( V_69 , V_70 , V_27 ) ;
V_30 = F_30 ( V_22 , V_26 , V_27 ) ;
F_21 ( V_30 == - 1 ) ;
F_36 ( V_30 , V_22 , V_26 , V_27 , 0 ) ;
}
static void F_38 ( unsigned long V_71 , int V_60 )
{
unsigned long V_22 ;
unsigned long V_45 , V_72 , V_73 ;
unsigned long V_29 = 0 ;
struct V_74 * V_75 = & F_39 ( V_74 ) ;
int V_76 = ! F_40 ( V_77 ) ;
unsigned long V_78 [ 9 ] ;
unsigned long V_65 , V_79 , V_67 , V_80 , V_30 ;
T_1 V_81 ;
int V_26 , V_27 ;
if ( V_76 )
F_41 ( & V_82 , V_29 ) ;
V_26 = V_75 -> V_26 ;
V_27 = V_75 -> V_27 ;
V_72 = 0 ;
for ( V_45 = 0 ; V_45 < V_71 ; V_45 ++ ) {
V_22 = V_75 -> V_22 [ V_45 ] ;
V_81 = V_75 -> V_81 [ V_45 ] ;
F_42 (pte, psize, vpn, index, shift) {
V_65 = F_31 ( V_22 , V_67 , V_27 ) ;
V_80 = F_43 ( V_81 , V_79 ) ;
if ( V_80 & V_83 )
V_65 = ~ V_65 ;
V_30 = ( V_65 & V_68 ) * V_48 ;
V_30 += V_80 & V_84 ;
if ( ! F_8 ( V_85 ) ) {
F_36 ( V_30 , V_22 , V_26 ,
V_27 , V_60 ) ;
} else {
V_78 [ V_72 ] = V_86 | V_87 | V_30 ;
V_78 [ V_72 + 1 ] = F_26 ( V_22 , V_26 ,
V_27 ) ;
V_72 += 2 ;
if ( V_72 == 8 ) {
V_73 = F_44 ( V_88 , V_78 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] ,
V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_21 ( V_73 != V_42 ) ;
V_72 = 0 ;
}
}
} F_45 () ;
}
if ( V_72 ) {
V_78 [ V_72 ] = V_89 ;
V_73 = F_44 ( V_88 , V_78 , V_78 [ 0 ] , V_78 [ 1 ] ,
V_78 [ 2 ] , V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_21 ( V_73 != V_42 ) ;
}
if ( V_76 )
F_46 ( & V_82 , V_29 ) ;
}
static int T_2 F_47 ( char * V_90 )
{
if ( strcmp ( V_90 , L_17 ) == 0 &&
F_8 ( V_85 ) ) {
F_48 ( V_91 L_18 ) ;
V_92 &= ~ V_85 ;
}
return 1 ;
}
void T_2 F_49 ( void )
{
V_93 . V_94 = F_36 ;
V_93 . V_95 = F_25 ;
V_93 . V_96 = F_33 ;
V_93 . V_97 = F_12 ;
V_93 . V_98 = F_18 ;
V_93 . V_99 = F_37 ;
V_93 . V_100 = F_38 ;
V_93 . V_101 = F_22 ;
}
static int T_2 F_50 ( char * V_90 )
{
char * V_102 ;
V_102 = F_51 ( V_90 ) ;
if ( strcasecmp ( V_102 , L_19 ) == 0 || strcasecmp ( V_102 , L_17 ) == 0 ) {
F_48 ( V_91 L_20 ) ;
V_103 = 0 ;
return 1 ;
}
V_103 = 1 ;
F_48 ( V_91 L_21 ) ;
if ( strcasecmp ( V_102 , L_22 ) == 0 || strcasecmp ( V_102 , L_23 ) == 0 )
return 1 ;
return 0 ;
}
static void F_52 ( struct V_104 * V_104 , int V_105 ,
unsigned long V_106 )
{
int V_45 , V_57 ;
unsigned long V_107 , V_3 ;
V_107 = F_53 () ;
V_3 = F_5 ( ( unsigned long ) F_54 ( V_104 ) ) ;
for ( V_45 = 0 ; V_45 < ( 1 << V_105 ) ; V_45 ++ , V_3 += V_108 ) {
for ( V_57 = 0 ; V_57 < V_108 ; V_57 += V_107 )
F_55 ( V_109 , V_106 , V_3 + V_57 , 0 ) ;
}
}
void F_56 ( struct V_104 * V_104 , int V_105 )
{
if ( ! V_103 || ! F_8 ( V_110 ) )
return;
F_52 ( V_104 , V_105 , V_111 ) ;
}
void F_57 ( void )
{
V_112 ++ ;
}
void F_58 ( void )
{
V_112 -- ;
}
void F_59 ( unsigned long V_113 , unsigned long * args )
{
unsigned long V_29 ;
unsigned int * V_114 ;
if ( V_113 == V_115 )
return;
F_60 ( V_29 ) ;
V_114 = & F_39 ( V_116 ) ;
if ( * V_114 )
goto V_117;
( * V_114 ) ++ ;
F_61 () ;
F_62 ( V_113 , args ) ;
( * V_114 ) -- ;
V_117:
F_63 ( V_29 ) ;
}
void F_64 ( long V_113 , unsigned long V_118 ,
unsigned long * V_119 )
{
unsigned long V_29 ;
unsigned int * V_114 ;
if ( V_113 == V_115 )
return;
F_60 ( V_29 ) ;
V_114 = & F_39 ( V_116 ) ;
if ( * V_114 )
goto V_117;
( * V_114 ) ++ ;
F_65 ( V_113 , V_118 , V_119 ) ;
F_66 () ;
( * V_114 ) -- ;
V_117:
F_63 ( V_29 ) ;
}
int F_67 ( struct V_120 * V_121 )
{
int V_73 ;
unsigned long V_119 [ V_122 ] ;
V_73 = F_44 ( V_123 , V_119 ) ;
V_121 -> V_124 = V_119 [ 0 ] ;
V_121 -> V_125 = V_119 [ 1 ] ;
V_121 -> V_126 = ( V_119 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_121 -> V_127 = V_119 [ 2 ] & 0xffff ;
V_121 -> V_128 = ( V_119 [ 3 ] >> 7 * 8 ) & 0xff ;
V_121 -> V_129 = ( V_119 [ 3 ] >> 6 * 8 ) & 0xff ;
V_121 -> V_130 = V_119 [ 3 ] & 0xffffffffffff ;
V_121 -> V_131 = V_119 [ 4 ] ;
V_121 -> V_132 = V_119 [ 5 ] ;
V_121 -> V_133 = V_119 [ 6 ] ;
return V_73 ;
}
int F_68 ( struct V_134 * V_135 )
{
int V_73 ;
unsigned long V_119 [ V_122 ] = { 0 } ;
V_73 = F_44 ( V_136 , V_119 ) ;
V_135 -> V_137 = V_119 [ 0 ] ;
V_135 -> V_138 = V_119 [ 1 ] ;
V_135 -> V_139 = V_119 [ 2 ] ;
V_135 -> V_140 = V_119 [ 3 ] ;
return V_73 ;
}
