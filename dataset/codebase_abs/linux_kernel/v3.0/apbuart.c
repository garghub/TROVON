static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 ) ;
V_3 &= ~ V_4 ;
F_3 ( V_2 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 ) ;
V_3 |= V_4 ;
F_3 ( V_2 , V_3 ) ;
if ( F_5 ( V_2 ) & V_5 )
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 ) ;
V_3 &= ~ ( V_6 ) ;
F_3 ( V_2 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_2 . V_8 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
unsigned int V_14 = V_2 -> V_15 ;
V_10 = F_5 ( V_2 ) ;
while ( F_10 ( V_10 ) && ( V_14 -- ) ) {
V_11 = F_11 ( V_2 ) ;
V_13 = V_16 ;
V_2 -> V_17 . V_18 ++ ;
V_12 = F_5 ( V_2 ) | V_19 ;
F_12 ( V_2 , 0 ) ;
if ( V_12 & V_20 ) {
if ( V_12 & V_21 ) {
V_12 &= ~ ( V_22 | V_23 ) ;
V_2 -> V_17 . V_24 ++ ;
if ( F_13 ( V_2 ) )
goto V_25;
} else if ( V_12 & V_23 ) {
V_2 -> V_17 . V_26 ++ ;
} else if ( V_12 & V_22 ) {
V_2 -> V_17 . V_27 ++ ;
}
if ( V_12 & V_28 )
V_2 -> V_17 . V_29 ++ ;
V_12 &= V_2 -> V_30 ;
if ( V_12 & V_23 )
V_13 = V_31 ;
else if ( V_12 & V_22 )
V_13 = V_32 ;
}
if ( F_14 ( V_2 , V_11 ) )
goto V_25;
F_15 ( V_2 , V_12 , V_28 , V_11 , V_13 ) ;
V_25:
V_10 = F_5 ( V_2 ) ;
}
F_16 ( V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_9 -> V_34 ;
int V_35 ;
if ( V_2 -> V_36 ) {
F_17 ( V_2 , V_2 -> V_36 ) ;
V_2 -> V_17 . V_37 ++ ;
V_2 -> V_36 = 0 ;
return;
}
if ( F_18 ( V_34 ) || F_19 ( V_2 ) ) {
F_1 ( V_2 ) ;
return;
}
V_35 = V_2 -> V_15 >> 1 ;
do {
F_17 ( V_2 , V_34 -> V_38 [ V_34 -> V_39 ] ) ;
V_34 -> V_39 = ( V_34 -> V_39 + 1 ) & ( V_40 - 1 ) ;
V_2 -> V_17 . V_37 ++ ;
if ( F_18 ( V_34 ) )
break;
} while ( -- V_35 > 0 );
if ( F_20 ( V_34 ) < V_41 )
F_21 ( V_2 ) ;
if ( F_18 ( V_34 ) )
F_1 ( V_2 ) ;
}
static T_1 F_22 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
unsigned int V_10 ;
F_23 ( & V_2 -> V_44 ) ;
V_10 = F_5 ( V_2 ) ;
if ( V_10 & V_45 )
F_9 ( V_2 ) ;
if ( V_10 & V_5 )
F_6 ( V_2 ) ;
F_24 ( & V_2 -> V_44 ) ;
return V_46 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
unsigned int V_10 = F_5 ( V_2 ) ;
return V_10 & V_5 ? V_47 : 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_48 | V_49 | V_50 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_51 )
{
}
static void F_28 ( struct V_1 * V_2 , int V_52 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
int V_53 ;
unsigned int V_3 ;
V_53 = F_30 ( V_2 -> V_42 , F_22 , 0 , L_1 , V_2 ) ;
if ( V_53 )
return V_53 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ,
V_3 | V_54 | V_55 |
V_6 | V_4 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ,
V_3 & ~ ( V_54 | V_55 |
V_6 | V_4 ) ) ;
F_32 ( V_2 -> V_42 , V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_56 * V_57 , struct V_56 * V_58 )
{
unsigned int V_3 ;
unsigned long V_59 ;
unsigned int V_60 , V_61 ;
V_60 = F_34 ( V_2 , V_57 , V_58 , 0 , V_2 -> V_62 / 16 ) ;
if ( V_60 == 0 )
F_35 ( L_2 , V_2 -> V_62 / 16 ) ;
V_61 = ( F_36 ( V_2 , V_60 ) ) * 2 ;
V_3 = F_2 ( V_2 ) ;
V_3 &= ~ ( V_63 | V_64 ) ;
if ( V_57 -> V_65 & V_66 ) {
V_3 |= V_63 ;
if ( ( V_57 -> V_65 & V_67 ) )
V_3 |= V_64 ;
}
if ( V_57 -> V_65 & V_68 )
V_3 |= V_69 ;
F_37 ( & V_2 -> V_44 , V_59 ) ;
F_38 ( V_2 , V_57 -> V_65 , V_60 ) ;
V_2 -> V_30 = V_28 ;
if ( V_57 -> V_70 & V_71 )
V_2 -> V_30 |= V_22 | V_23 ;
V_2 -> V_72 = 0 ;
if ( V_57 -> V_70 & V_73 )
V_2 -> V_72 |= V_22 | V_23 ;
if ( ( V_57 -> V_65 & V_74 ) == 0 )
V_2 -> V_72 |= V_19 ;
V_61 -= 1 ;
F_39 ( V_2 , V_61 ) ;
F_3 ( V_2 , V_3 ) ;
F_40 ( & V_2 -> V_44 , V_59 ) ;
}
static const char * F_41 ( struct V_1 * V_2 )
{
return V_2 -> type == V_75 ? L_3 : NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_76 , 0x100 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
return F_45 ( V_2 -> V_76 , 0x100 , L_4 )
!= NULL ? 0 : - V_77 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_59 )
{
if ( V_59 & V_78 ) {
V_2 -> type = V_75 ;
F_44 ( V_2 ) ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
int V_81 = 0 ;
if ( V_80 -> type != V_82 && V_80 -> type != V_75 )
V_81 = - V_83 ;
if ( V_80 -> V_42 < 0 || V_80 -> V_42 >= V_84 )
V_81 = - V_83 ;
if ( V_80 -> V_85 < 9600 )
V_81 = - V_83 ;
return V_81 ;
}
static int F_48 ( struct V_1 * V_2 , int V_86 )
{
int V_87 , V_88 = 0 ;
int V_10 ;
int V_15 ;
unsigned long V_59 ;
V_87 = F_2 ( V_2 ) ;
F_49 ( V_59 ) ;
F_3 ( V_2 , V_87 | V_55 ) ;
while ( ! F_50 ( F_5 ( V_2 ) ) )
V_88 ++ ;
F_3 ( V_2 , V_87 & ~ ( V_55 ) ) ;
V_15 = 1 ;
F_17 ( V_2 , 0 ) ;
V_10 = F_5 ( V_2 ) ;
while ( ( ( V_10 >> 20 ) & 0x3F ) == V_15 ) {
V_15 ++ ;
F_17 ( V_2 , 0 ) ;
V_10 = F_5 ( V_2 ) ;
}
V_15 -- ;
F_3 ( V_2 , V_87 ) ;
F_51 ( V_59 ) ;
if ( V_15 == 0 )
V_15 = 1 ;
return V_15 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_15 ; V_89 ++ )
F_11 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , int V_11 )
{
unsigned int V_10 ;
do {
V_10 = F_5 ( V_2 ) ;
} while ( ! F_50 ( V_10 ) );
F_17 ( V_2 , V_11 ) ;
}
static void
F_54 ( struct V_90 * V_91 , const char * V_92 , unsigned int V_35 )
{
struct V_1 * V_2 = & V_93 [ V_91 -> V_94 ] ;
unsigned int V_10 , V_95 , V_96 ;
V_95 = F_2 ( V_2 ) ;
V_96 = V_95 & ~ ( V_6 | V_4 ) ;
F_3 ( V_2 , V_96 ) ;
F_55 ( V_2 , V_92 , V_35 , F_53 ) ;
do {
V_10 = F_5 ( V_2 ) ;
} while ( ! F_50 ( V_10 ) );
F_3 ( V_2 , V_95 ) ;
}
static void T_2
F_56 ( struct V_1 * V_2 , int * V_60 ,
int * V_26 , int * V_97 )
{
if ( F_2 ( V_2 ) & ( V_54 | V_55 ) ) {
unsigned int V_61 , V_10 ;
V_10 = F_5 ( V_2 ) ;
* V_26 = 'n' ;
if ( V_10 & V_63 ) {
if ( ( V_10 & V_64 ) == 0 )
* V_26 = 'e' ;
else
* V_26 = 'o' ;
}
* V_97 = 8 ;
V_61 = F_57 ( V_2 ) / 8 ;
* V_60 = V_2 -> V_62 / ( 16 * ( V_61 + 1 ) ) ;
}
}
static int T_2 F_58 ( struct V_90 * V_91 , char * V_98 )
{
struct V_1 * V_2 ;
int V_60 = 38400 ;
int V_97 = 8 ;
int V_26 = 'n' ;
int V_99 = 'n' ;
F_59 ( L_5 ,
V_91 , V_91 -> V_94 , V_98 ) ;
if ( V_91 -> V_94 >= V_100 )
V_91 -> V_94 = 0 ;
V_2 = & V_93 [ V_91 -> V_94 ] ;
F_60 ( & V_2 -> V_44 ) ;
if ( V_98 )
F_61 ( V_98 , & V_60 , & V_26 , & V_97 , & V_99 ) ;
else
F_56 ( V_2 , & V_60 , & V_26 , & V_97 ) ;
return F_62 ( V_2 , V_91 , V_60 , V_26 , V_97 , V_99 ) ;
}
static int T_2 F_63 ( void )
{
if ( F_64 () )
return - V_101 ;
F_65 ( & V_102 ) ;
return 0 ;
}
static int T_3 F_66 ( struct V_103 * V_104 )
{
int V_89 ;
struct V_1 * V_2 = NULL ;
for ( V_89 = 0 ; V_89 < V_100 ; V_89 ++ ) {
if ( V_104 -> V_105 . V_106 == V_107 [ V_89 ] )
break;
}
V_2 = & V_93 [ V_89 ] ;
V_2 -> V_105 = & V_104 -> V_105 ;
V_2 -> V_42 = V_104 -> V_108 . V_109 [ 0 ] ;
F_67 ( & V_110 , (struct V_1 * ) V_2 ) ;
F_52 ( (struct V_1 * ) V_2 ) ;
F_68 ( V_111 L_6 ,
( unsigned long long ) V_2 -> V_76 , V_2 -> V_42 ) ;
return 0 ;
}
static int F_64 ( void )
{
struct V_112 * V_113 ;
int line = 0 ;
F_69 (np, apbuart_match) {
const int * V_114 ;
const T_4 * V_115 ;
const struct V_116 * V_117 ;
struct V_1 * V_2 ;
unsigned long V_118 ;
V_114 = F_70 ( V_113 , L_7 , NULL ) ;
if ( V_114 && ( * V_114 == 0 ) )
continue;
V_117 = F_70 ( V_113 , L_8 , NULL ) ;
V_115 = F_70 ( V_113 , L_9 , NULL ) ;
if ( ! V_117 || ! V_115 || ( * V_115 == 0 ) )
continue;
V_107 [ line ] = V_113 ;
V_118 = V_117 -> V_119 ;
V_2 = & V_93 [ line ] ;
V_2 -> V_76 = V_118 ;
V_2 -> V_120 = F_71 ( V_118 , sizeof( struct V_121 ) ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_122 = V_123 ;
V_2 -> V_124 = & V_125 ;
V_2 -> V_59 = V_126 ;
V_2 -> line = line ;
V_2 -> V_62 = * V_115 ;
V_2 -> V_15 = F_48 ( (struct V_1 * ) V_2 , line ) ;
line ++ ;
if ( line == V_127 )
break;
}
V_110 . V_128 = V_100 = line ;
return line ? 0 : - V_101 ;
}
static int T_2 F_72 ( void )
{
int V_81 ;
V_81 = F_64 () ;
if ( V_81 )
return V_81 ;
F_68 ( V_111 L_10 ) ;
V_81 = F_73 ( & V_110 ) ;
if ( V_81 ) {
F_68 ( V_129 L_11 ,
__FILE__ , V_81 ) ;
return V_81 ;
}
V_81 = F_74 ( & V_130 ) ;
if ( V_81 ) {
F_68 ( V_129
L_12 ,
__FILE__ , V_81 ) ;
F_75 ( & V_110 ) ;
return V_81 ;
}
return V_81 ;
}
static void T_5 F_76 ( void )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_100 ; V_89 ++ )
F_77 ( & V_110 ,
& V_93 [ V_89 ] ) ;
F_75 ( & V_110 ) ;
F_78 ( & V_130 ) ;
}
