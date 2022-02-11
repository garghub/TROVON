static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
#ifdef F_2
T_1 V_4 ;
T_2 V_5 ;
#endif
F_3 ( V_2 ) ;
#ifdef F_2
F_4 ( F_5 ( V_6 ) , V_7 ) ;
F_6 ( F_7 ( V_8 ) , V_9 ) ;
F_8 ( V_2 , F_9 ( V_2 ) , F_10 ( 10 ) ) ;
F_6 ( F_7 ( V_8 ) , V_10 ) ;
V_3 = ( int ) F_11 ( F_7 ( V_8 ) ) ;
F_12 ( V_3 ) ;
F_6 ( F_7 ( V_8 ) , V_11 ) ;
F_6 ( F_7 ( V_12 ) , V_13 ) ;
V_5 = F_13 ( F_14 ( V_14 ) ) ;
F_4 ( F_14 ( V_14 ) , V_5 | V_15 ) ;
F_6 ( F_7 ( V_12 ) , V_16 ) ;
F_6 ( F_7 ( V_8 ) , V_17 | V_18 ) ;
V_4 = F_11 ( F_14 ( V_19 ) ) ;
if ( ( V_4 & 0xf0 ) == V_20 || ( V_4 & 0xf0 ) == V_21 ) {
V_2 -> V_22 . V_23 = TRUE ;
} else {
V_2 -> V_22 . V_23 = FALSE ;
}
if ( ! V_2 -> V_22 . V_23 ) {
F_15 ( F_7 ( V_24 ) , V_25 ) ;
F_15 ( F_7 ( V_26 ) , V_27 ) ;
F_15 ( F_7 ( V_28 ) , V_27 ) ;
}
F_6 ( F_7 ( V_8 ) , V_11 ) ;
F_6 ( F_7 ( V_29 ) , V_30 | V_31 | V_32 ) ;
F_15 ( F_7 ( V_33 ) , 0x6FC23AC0 ) ;
V_2 -> V_22 . V_34 = V_35 ;
V_2 -> V_22 . V_36 = V_37 ;
#endif
F_16 ( 0 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
V_2 -> V_22 . V_38 = 0 ;
#ifdef F_2
F_4 ( F_5 ( V_6 ) , V_7 ) ;
F_6 ( F_7 ( V_8 ) , V_9 ) ;
F_8 ( V_2 , F_9 ( V_2 ) , F_10 ( 10 ) ) ;
F_6 ( F_7 ( V_8 ) , V_10 ) ;
F_6 ( F_7 ( V_8 ) , V_11 ) ;
F_6 ( F_7 ( V_29 ) , V_30 | V_39 | V_32 ) ;
V_2 -> V_22 . V_36 = V_37 ;
#endif
}
void F_18 ( struct V_1 * V_2 , T_2 V_40 , T_2 V_41 )
{
int V_42 = 0 ;
V_43:
if ( V_41 & ( V_44 |
V_45 |
V_46 ) ) {
F_19 ( V_2 , V_47 , V_48 ) ;
}
if ( V_41 & ( V_49 |
V_50 |
V_51 ) ) {
F_19 ( V_2 , V_52 , V_53 ) ;
}
if ( ( V_40 & ( V_54 |
V_55 |
V_56 ) ) ||
( V_41 & ( V_57 |
V_58 ) ) ) {
F_20 ( V_2 ) ;
V_42 = 1 ;
V_40 = F_13 ( F_5 ( V_59 ) ) ;
V_41 = F_13 ( F_5 ( V_60 ) ) ;
V_40 &= ~ ( V_61 | V_62 | V_63 ) ;
if ( V_40 || V_41 )
goto V_43 ;
}
if ( V_40 & ( V_62 |
V_63 ) ) {
V_42 = 1 ;
}
if ( V_42 )
F_21 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
T_2 V_64 = F_13 ( F_23 ( V_65 , V_66 ) ) ;
F_24 ( V_2 , V_65 , V_64 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
T_2 V_64 = F_13 ( F_23 ( V_67 , V_66 ) ) ;
F_24 ( V_2 , V_67 , V_64 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
V_2 -> V_22 . V_68 = V_2 -> V_22 . V_69 ;
F_28 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
return V_70 ;
}
void F_30 ( struct V_1 * V_2 , T_1 * V_71 )
{
char V_72 ;
char V_73 ;
int V_3 ;
#ifdef F_2
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_2 -> V_22 . V_74 . V_75 [ V_3 ] =
F_31 ( F_11 ( F_7 ( V_76 + V_3 ) ) ) ;
}
#endif
V_72 = F_11 ( F_7 ( V_77 ) ) ;
V_73 = F_11 ( F_7 ( V_78 ) ) ;
V_2 -> V_79 [ V_67 ] . V_80 [ V_81 ] =
V_2 -> V_79 [ V_65 ] . V_80 [ V_81 ] = V_72 ;
V_2 -> V_79 [ V_67 ] . V_80 [ V_82 ] =
V_2 -> V_79 [ V_65 ] . V_80 [ V_82 ] = V_73 ;
if ( V_71 ) {
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_2 -> V_22 . V_83 . V_75 [ V_3 ] = V_71 [ V_3 ] ;
V_2 -> V_22 . V_84 . V_75 [ V_3 ] = F_31 ( V_71 [ V_3 ] ) ;
}
return ;
}
V_2 -> V_22 . V_84 = V_2 -> V_22 . V_74 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_2 -> V_22 . V_83 . V_75 [ V_3 ] =
F_31 ( V_2 -> V_22 . V_74 . V_75 [ V_3 ] ) ;
}
}
void F_32 ( struct V_1 * V_2 , T_1 * V_71 )
{
F_1 ( V_2 ) ;
F_30 ( V_2 , V_71 ) ;
if ( ! ( F_11 ( F_7 ( V_85 ) ) & V_86 ) )
V_2 -> V_87 . V_88 = V_89 ;
else
V_2 -> V_87 . V_88 = V_90 ;
if ( ! ( F_11 ( F_7 ( V_85 ) ) & V_91 ) )
V_2 -> V_92 . V_93 = 0 ;
else
V_2 -> V_92 . V_93 = 1 ;
}
void F_33 ( struct V_1 * V_2 , int V_94 )
{
F_34 ( 1 , L_1 , ( V_94 == V_95 ) ?
L_2 : L_3 , 0 ) ;
if ( V_2 -> V_87 . V_88 != V_90 )
return ;
#ifdef F_2
switch( V_94 ) {
case V_95 :
F_6 ( F_7 ( V_85 ) , V_96 ) ;
break ;
case V_97 :
F_6 ( F_7 ( V_85 ) , V_98 ) ;
break ;
}
#endif
}
int F_35 ( struct V_1 * V_2 )
{
return ( F_11 ( F_7 ( V_85 ) ) & V_91 ) ? TRUE : FALSE ;
}
void F_36 ( struct V_1 * V_2 , int V_99 )
{
F_12 ( V_99 ) ;
F_12 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_100 )
{
T_2 V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_104 * V_106 ;
V_103 = & V_2 -> V_79 [ V_67 ] ;
V_105 = V_103 -> V_92 ;
V_103 = & V_2 -> V_79 [ V_65 ] ;
V_106 = V_103 -> V_92 ;
#ifdef F_2
V_101 = 0 ;
if ( V_100 == V_107 ) {
V_101 |= V_31 ;
}
else if ( V_100 == V_108 ) {
V_101 |= V_39 ;
}
else {
if ( V_105 -> V_109 == V_110 ) {
V_101 |= V_111 ;
}
else {
V_101 |= V_30 ;
}
if ( V_106 -> V_109 == V_110 ) {
V_101 |= V_112 ;
}
else {
V_101 |= V_32 ;
}
}
F_6 ( F_7 ( V_29 ) , V_101 ) ;
#endif
}
void F_38 ( struct V_1 * V_2 , int V_113 , int V_114 )
{
F_39 ( V_2 , V_113 , V_114 ) ;
F_37 ( V_2 , 0 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_3 )
{
F_41 ( V_2 , V_3 ) ;
F_37 ( V_2 , V_3 ? V_108 : V_107 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
#ifdef F_43
extern int V_115 ;
V_115 = 0 ;
#endif
#ifndef F_44
V_2 -> V_22 . V_116 = 0 ;
#else
F_12 ( V_2 ) ;
#endif
}
static int F_45 ( char V_117 [] , char V_118 [] , int V_119 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_119 ; V_3 ++ ) {
if ( V_117 [ V_3 ] != V_118 [ V_3 ] )
return 0 ;
}
return 1 ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_120 ;
int V_3 ;
int V_121 ;
V_3 = 0 ;
V_120 = - 1 ;
V_121 = FALSE ;
V_2 -> V_22 . V_122 = 0 ;
V_2 -> V_22 . V_123 = V_124 ;
while ( V_125 [ V_3 ] . V_126 ) {
switch ( V_125 [ V_3 ] . V_126 ) {
case V_124 :
V_121 = TRUE ;
if ( V_120 == - 1 )
V_120 = V_3 ;
case V_127 :
case V_128 :
V_3 ++ ;
break ;
default:
return 1 ;
}
}
if ( V_3 == 0 )
return 2 ;
if ( ! V_121 )
return 3 ;
V_2 -> V_22 . V_122 = (struct V_129 * ) & V_125 [ V_120 ] ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_131 -> V_75 [ V_3 ] = F_31 ( V_2 -> V_22 . V_74 . V_75 [ V_3 ] ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
#ifndef F_49
#ifdef F_2
if ( V_2 -> V_22 . V_132 ) {
F_4 ( F_7 ( V_133 ) , V_134 ) ;
}
#endif
#endif
}
static void F_3 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
#ifndef F_49
#ifdef F_2
if ( V_2 -> V_22 . V_132 ) {
F_4 ( F_7 ( V_133 ) , V_135 ) ;
}
#endif
#endif
}
void F_50 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
