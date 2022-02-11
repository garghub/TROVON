static inline void F_1 ( unsigned V_1 )
{
unsigned long V_2 = V_3 | V_1 ;
int V_4 ;
V_5 . V_6 = V_2 ;
V_2 &= ~ 1L ;
#define F_2 cache_tags.tags[0]
F_3 ( V_7 , V_2 ) ;
F_2 [ 0 ] . V_8 = F_4 () ;
F_2 [ 0 ] . V_9 = F_5 () ;
F_3 ( V_7 , V_2 | 1L ) ;
F_2 [ 1 ] . V_8 = F_4 () ;
F_2 [ 1 ] . V_9 = F_5 () ;
#undef F_2
V_2 &= ( 0xffL << 56 ) | ( ( 1 << 12 ) - 1 ) ;
#define F_2 cache_tags.tagd[i]
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 , V_2 += ( 1 << 12 ) ) {
F_3 ( V_10 , V_2 ) ;
F_2 [ 0 ] . V_8 = F_4 () ;
F_2 [ 0 ] . V_9 = F_5 () ;
F_3 ( V_10 , V_2 | 1L ) ;
F_2 [ 1 ] . V_8 = F_4 () ;
F_2 [ 1 ] . V_9 = F_5 () ;
}
#undef F_2
V_2 &= ( 0xffL << 56 ) | ( ( 1 << 12 ) - 1 ) ;
#define F_2 cache_tags.tagi[i]
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 , V_2 += ( 1 << 12 ) ) {
F_3 ( V_11 , V_2 ) ;
F_2 [ 0 ] . V_8 = F_4 () ;
F_2 [ 0 ] . V_9 = F_5 () ;
F_3 ( V_11 , V_2 | 1L ) ;
F_2 [ 1 ] . V_8 = F_4 () ;
F_2 [ 1 ] . V_9 = F_5 () ;
}
#undef F_2
}
static void F_6 ( void )
{
int V_4 ;
V_12 = V_13 -> V_14 ;
V_15 = V_13 -> V_16 ;
V_17 = V_13 -> V_18 ;
V_19 = V_13 -> V_20 ;
V_21 = V_22 -> V_23 ;
V_24 = V_25 -> V_26 ;
V_27 . V_28 [ 0 ] . V_2 = ( unsigned long ) & V_25 -> V_29 ;
V_27 . V_28 [ 0 ] . V_30 = V_25 -> V_29 . V_30 ;
V_27 . V_28 [ 0 ] . V_31 = V_25 -> V_29 . V_32 ;
V_27 . V_28 [ 0 ] . V_33 = V_25 -> V_29 . V_33 ;
V_27 . V_28 [ 1 ] . V_2 = ( unsigned long ) & V_25 -> V_34 ;
V_27 . V_28 [ 1 ] . V_30 = V_25 -> V_34 . V_30 ;
V_27 . V_28 [ 1 ] . V_31 = V_25 -> V_34 . V_32 ;
V_27 . V_28 [ 1 ] . V_33 = V_25 -> V_34 . V_33 ;
V_27 . V_35 . V_2 = ( unsigned long ) & V_25 -> V_36 . V_37 ;
V_27 . V_35 . V_30 = V_25 -> V_36 . V_38 ;
V_27 . V_35 . V_31 = V_25 -> V_36 . V_37 ;
V_27 . V_35 . V_33 = V_25 -> V_36 . V_39 ;
V_27 . V_40 . V_2 = ( unsigned long ) & V_25 -> V_36 . V_41 ;
V_27 . V_40 . V_30 = V_25 -> V_36 . V_42 ;
V_27 . V_40 . V_31 = V_25 -> V_36 . V_41 ;
V_27 . V_40 . V_33 = V_25 -> V_36 . V_43 ;
for ( V_4 = 0 ; V_4 < 8 ; ++ V_4 ) {
V_27 . V_44 [ V_4 ] . V_2 = ( unsigned long ) & V_25 -> V_44 [ V_4 ] ;
V_27 . V_44 [ V_4 ] . V_30 = V_25 -> V_44 [ V_4 ] . V_45 ;
V_27 . V_44 [ V_4 ] . V_31 = V_25 -> V_44 [ V_4 ] . V_46 ;
V_27 . V_44 [ V_4 ] . V_33 = V_25 -> V_44 [ V_4 ] . V_47 ;
}
V_4 = 0 ;
if ( V_19 & V_48 )
V_4 = V_17 ;
if ( V_15 & V_48 )
V_4 = V_12 ;
F_1 ( V_4 ) ;
V_13 -> V_16 = V_13 -> V_20 = 0 ;
}
static void F_7 ( void )
{
T_1 V_49 , V_50 ;
int V_4 ;
F_8 ( V_51 L_1 , ( unsigned ) V_5 . V_6 ) ;
V_50 = ( V_5 . V_6 >> 4 ) & 0x0fffff00 ;
V_49 = V_5 . V_6 & ( ( 1 << 12 ) - 1 ) & ~ ( ( 1 << 5 ) - 1 ) ;
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( ( V_5 . V_52 [ V_4 ] [ 0 ] . V_8 & 0x0fffff00 ) != V_50 &&
( V_5 . V_52 [ V_4 ] [ 1 ] . V_8 & 0x0fffff00 ) != V_50 )
continue;
F_8 ( V_51
L_2 ,
V_5 . V_52 [ V_4 ] [ 0 ] . V_9 , V_5 . V_52 [ V_4 ] [ 0 ] . V_8 ,
V_5 . V_52 [ V_4 ] [ 1 ] . V_9 , V_5 . V_52 [ V_4 ] [ 1 ] . V_8 ,
V_49 | ( 1 << 12 ) * V_4 ) ;
}
V_49 = V_5 . V_6 & ( ( 1 << 12 ) - 1 ) & ~ ( ( 1 << 6 ) - 1 ) ;
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( ( V_5 . V_53 [ V_4 ] [ 0 ] . V_8 & 0x0fffff00 ) != V_50 &&
( V_5 . V_53 [ V_4 ] [ 1 ] . V_8 & 0x0fffff00 ) != V_50 )
continue;
F_8 ( V_51
L_3 ,
V_5 . V_53 [ V_4 ] [ 0 ] . V_9 , V_5 . V_53 [ V_4 ] [ 0 ] . V_8 ,
V_5 . V_53 [ V_4 ] [ 1 ] . V_9 , V_5 . V_53 [ V_4 ] [ 1 ] . V_8 ,
V_49 | ( 1 << 12 ) * V_4 ) ;
}
V_4 = F_9 () ;
V_49 = V_4 & ( 1 << 13 ) ? 7 : 6 ;
V_50 = ( ( V_4 >> 16 ) & 7 ) + 19 - 1 ;
V_4 = ( ( 1 << V_50 ) - 1 ) & ~ ( ( 1 << V_49 ) - 1 ) ;
F_8 ( V_51 L_4 ,
V_5 . V_54 [ 0 ] [ 0 ] . V_9 , V_5 . V_54 [ 0 ] [ 0 ] . V_8 ,
V_5 . V_54 [ 0 ] [ 1 ] . V_9 , V_5 . V_54 [ 0 ] [ 1 ] . V_8 ,
V_50 - 1 , V_49 , V_4 & ( unsigned ) V_5 . V_6 ) ;
}
static inline const char * F_10 ( int V_55 )
{
static const char * V_56 [ 32 ] =
{ L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 , L_22 , L_23 , L_24 , L_25 , L_26 , L_27 ,
L_28 ,
L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 ,
} ;
return V_56 [ ( V_55 & 0x7c ) >> 2 ] ;
}
static void F_11 ( const struct V_57 * V_58 )
{
const int V_59 = 2 * sizeof( unsigned long ) ;
int error = 0 ;
if ( V_21 & V_60 ) {
F_8 ( V_51 L_37 ) ;
error |= 1 ;
}
if ( V_21 & V_61 ) {
F_8 ( V_51 L_38 ,
V_24 ,
( V_24 & V_62 ) >>
V_63 ,
( V_24 & V_64 ) ? L_39 : L_40 ,
V_24 & V_65 ) ;
error |= 2 ;
}
if ( V_21 & V_66 ) {
F_8 ( V_51 L_41 ) ;
error |= 4 ;
}
if ( V_15 & V_48 ) {
F_8 ( V_51 L_42 ,
V_15 ,
V_15 & V_67 ? L_43 : L_44 ,
V_15 & V_68 ? L_45 : L_44 ,
V_15 & V_69 ? L_46 : L_44 ,
V_15 & V_70 ? L_47 : L_44 ,
V_15 & V_71 ? L_48 : L_44 ,
V_15 & V_72 ? L_49 : L_44 ,
V_12 ) ;
error |= 8 ;
}
if ( V_19 & V_73 ) {
F_8 ( V_51 L_50 ,
V_19 ,
V_19 & V_74 ? L_43 : L_44 ,
V_19 & V_75 ? L_51 : L_44 ,
V_19 & V_76 ? L_52 : L_44 ,
V_19 & V_77 ? L_53 : L_44 ,
V_19 & V_78 ? L_46 : L_44 ,
V_19 & V_79 ? L_54 : L_44 ,
V_19 & V_80 ? L_55 : L_44 ,
V_19 & V_81 ? L_56 : L_44 ,
V_17 ) ;
error |= 16 ;
}
if ( ! error )
F_8 ( V_51 L_57 ) ;
else {
F_8 ( V_51 L_58
L_59
L_60 ,
F_9 () ,
V_13 -> V_82 , V_13 -> V_82 , V_13 -> V_83 ,
V_13 -> V_84 , V_13 -> V_85 ,
V_13 -> V_86 , V_13 -> V_87 ) ;
F_7 () ;
}
F_8 ( V_88 L_61 ,
F_10 ( V_58 -> V_89 ) ,
V_59 , V_58 -> V_90 , V_59 , V_58 -> V_58 [ 31 ] ) ;
}
static int F_12 ( unsigned long V_2 , unsigned V_91 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_92 . V_93 ; V_4 ++ ) {
unsigned long V_94 = V_92 . V_95 [ V_4 ] . V_2 ;
if ( V_94 <= V_2 && V_2 + V_91 <= V_94 + V_92 . V_95 [ V_4 ] . V_96 )
return 1 ;
}
return 0 ;
}
static int F_13 ( T_1 V_9 , T_1 V_8 , unsigned long V_97 )
{
V_97 &= 0x7fffffff ;
if ( ( V_8 & 2 ) && ( V_97 >> 21 ) == ( ( V_9 << 1 ) >> 22 ) ) {
T_1 V_98 = V_13 -> V_99 ;
if ( V_98 & 1 ) {
unsigned int V_100 = ( V_98 & 2 ) ? 14 : 12 ;
unsigned long V_101 = ( V_8 >> 6 ) << 12 ;
V_101 += 8 * ( ( V_97 >> V_100 ) & 0x1ff ) ;
if ( F_12 ( V_101 , 8 ) ) {
unsigned long V_94 = * ( unsigned long * )
F_14 ( V_101 ) ;
V_94 = ( V_94 & 0x3f ) << 6 ;
V_94 += V_97 & ( ( 1 << V_100 ) - 1 ) ;
return V_12 == V_94 ;
}
}
}
return 0 ;
}
static int F_15 ( void )
{
if ( V_15 & V_48 ) {
T_1 V_94 = V_13 -> V_102 ;
if ( ! ( V_13 -> V_99 & 0x100 ) )
return V_12 == V_94 ;
if ( F_13 ( V_13 -> V_103 , V_13 -> V_104 , V_94 ) ||
F_13 ( V_13 -> V_105 , V_13 -> V_106 , V_94 ) ||
F_13 ( V_13 -> V_107 , V_13 -> V_108 , V_94 ) ||
F_13 ( V_13 -> V_109 , V_13 -> V_110 , V_94 ) )
return 1 ;
}
return 0 ;
}
static int F_16 ( void )
{
if ( V_19 & V_73 ) {
T_1 V_94 = V_13 -> V_111 ;
V_94 = ( V_13 -> V_112 & ~ V_94 ) | ( V_13 -> V_113 & V_94 ) ;
return V_17 == V_94 ;
}
return 0 ;
}
static int F_17 ( const struct V_57 * V_58 )
{
int V_4 ;
F_6 () ;
if ( V_58 -> V_89 & V_114 )
goto V_115;
if ( ( V_58 -> V_89 & V_116 ) != V_116 )
goto V_115;
if ( V_21 & ( V_61 | V_66 ) )
goto V_115;
if ( V_15 & V_48 & ~ V_69 )
goto V_115;
if ( V_19 & V_73 & ~ V_76 )
goto V_115;
for ( V_4 = 0 ; V_4 < sizeof( V_27 ) / sizeof( struct V_117 ) ; ++ V_4 ) {
struct V_117 * V_118 = (struct V_117 * ) & V_27 + V_4 ;
if ( ( V_15 & V_48 ) &&
( V_12 == V_118 -> V_33 || V_12 == V_118 -> V_31 ) )
break;
if ( ( V_19 & V_73 ) &&
( V_17 == V_118 -> V_33 || V_17 == V_118 -> V_31 ) )
break;
}
if ( V_4 < sizeof( V_27 ) / sizeof( struct V_117 ) ) {
struct V_117 * V_118 = (struct V_117 * ) & V_27 + V_4 ;
F_8 ( V_51 L_62
L_63 ,
F_18 ( V_118 -> V_2 ) , V_118 -> V_30 , V_118 -> V_33 , V_118 -> V_31 ) ;
goto V_115;
}
if ( F_15 () ) {
F_8 ( V_51 L_64 ,
V_13 -> V_102 ) ;
goto V_115;
}
if ( F_16 () ) {
F_8 ( V_51 L_65 ,
V_13 -> V_112 ) ;
goto V_115;
}
if ( V_119 ) {
F_11 ( V_58 ) ;
F_8 ( V_51 L_66 ) ;
}
return V_120 ;
V_115:
F_11 ( V_58 ) ;
return V_121 ;
}
void F_19 ( int V_122 )
{
struct V_57 * V_58 = F_20 () ;
V_123 ++ ;
if ( F_17 ( V_58 ) != V_120 ) {
F_21 ( L_67 , V_58 ) ;
F_22 ( V_124 , V_125 ) ;
} else if ( V_119 )
F_23 ( (struct V_57 * ) V_58 ) ;
}
static int F_24 ( struct V_57 * V_58 , int V_126 )
{
if ( V_126 ) {
V_127 ++ ;
F_6 () ;
return V_128 ;
}
V_129 ++ ;
return F_17 ( V_58 ) ;
}
void T_2 F_25 ( void )
{
V_130 = F_24 ;
}
int F_26 ( struct V_131 * V_132 )
{
F_27 ( V_132 , L_68 , V_127 ) ;
F_27 ( V_132 , L_69 , V_123 ) ;
F_27 ( V_132 , L_70 , V_129 ) ;
return 0 ;
}
static int T_2 F_28 ( char * V_133 )
{
V_119 ++ ;
return 1 ;
}
