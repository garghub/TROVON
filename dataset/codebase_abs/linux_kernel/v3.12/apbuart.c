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
unsigned int V_7 , V_8 , V_9 , V_10 ;
unsigned int V_11 = V_2 -> V_12 ;
V_7 = F_5 ( V_2 ) ;
while ( F_10 ( V_7 ) && ( V_11 -- ) ) {
V_8 = F_11 ( V_2 ) ;
V_10 = V_13 ;
V_2 -> V_14 . V_15 ++ ;
V_9 = F_5 ( V_2 ) | V_16 ;
F_12 ( V_2 , 0 ) ;
if ( V_9 & V_17 ) {
if ( V_9 & V_18 ) {
V_9 &= ~ ( V_19 | V_20 ) ;
V_2 -> V_14 . V_21 ++ ;
if ( F_13 ( V_2 ) )
goto V_22;
} else if ( V_9 & V_20 ) {
V_2 -> V_14 . V_23 ++ ;
} else if ( V_9 & V_19 ) {
V_2 -> V_14 . V_24 ++ ;
}
if ( V_9 & V_25 )
V_2 -> V_14 . V_26 ++ ;
V_9 &= V_2 -> V_27 ;
if ( V_9 & V_20 )
V_10 = V_28 ;
else if ( V_9 & V_19 )
V_10 = V_29 ;
}
if ( F_14 ( V_2 , V_8 ) )
goto V_22;
F_15 ( V_2 , V_9 , V_25 , V_8 , V_10 ) ;
V_22:
V_7 = F_5 ( V_2 ) ;
}
F_16 ( & V_2 -> V_30 ) ;
F_17 ( & V_2 -> V_31 -> V_2 ) ;
F_18 ( & V_2 -> V_30 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = & V_2 -> V_31 -> V_33 ;
int V_34 ;
if ( V_2 -> V_35 ) {
F_19 ( V_2 , V_2 -> V_35 ) ;
V_2 -> V_14 . V_36 ++ ;
V_2 -> V_35 = 0 ;
return;
}
if ( F_20 ( V_33 ) || F_21 ( V_2 ) ) {
F_1 ( V_2 ) ;
return;
}
V_34 = V_2 -> V_12 >> 1 ;
do {
F_19 ( V_2 , V_33 -> V_37 [ V_33 -> V_38 ] ) ;
V_33 -> V_38 = ( V_33 -> V_38 + 1 ) & ( V_39 - 1 ) ;
V_2 -> V_14 . V_36 ++ ;
if ( F_20 ( V_33 ) )
break;
} while ( -- V_34 > 0 );
if ( F_22 ( V_33 ) < V_40 )
F_23 ( V_2 ) ;
if ( F_20 ( V_33 ) )
F_1 ( V_2 ) ;
}
static T_1 F_24 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned int V_7 ;
F_18 ( & V_2 -> V_30 ) ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 & V_43 )
F_9 ( V_2 ) ;
if ( V_7 & V_5 )
F_6 ( V_2 ) ;
F_16 ( & V_2 -> V_30 ) ;
return V_44 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
unsigned int V_7 = F_5 ( V_2 ) ;
return V_7 & V_5 ? V_45 : 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_46 | V_47 | V_48 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_49 )
{
}
static void F_28 ( struct V_1 * V_2 , int V_50 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
int V_51 ;
unsigned int V_3 ;
V_51 = F_30 ( V_2 -> V_41 , F_24 , 0 , L_1 , V_2 ) ;
if ( V_51 )
return V_51 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ,
V_3 | V_52 | V_53 |
V_6 | V_4 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ,
V_3 & ~ ( V_52 | V_53 |
V_6 | V_4 ) ) ;
F_32 ( V_2 -> V_41 , V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_54 * V_56 )
{
unsigned int V_3 ;
unsigned long V_57 ;
unsigned int V_58 , V_59 ;
V_58 = F_34 ( V_2 , V_55 , V_56 , 0 , V_2 -> V_60 / 16 ) ;
if ( V_58 == 0 )
F_35 ( L_2 , V_2 -> V_60 / 16 ) ;
V_59 = ( F_36 ( V_2 , V_58 ) ) * 2 ;
V_3 = F_2 ( V_2 ) ;
V_3 &= ~ ( V_61 | V_62 ) ;
if ( V_55 -> V_63 & V_64 ) {
V_3 |= V_61 ;
if ( ( V_55 -> V_63 & V_65 ) )
V_3 |= V_62 ;
}
if ( V_55 -> V_63 & V_66 )
V_3 |= V_67 ;
F_37 ( & V_2 -> V_30 , V_57 ) ;
F_38 ( V_2 , V_55 -> V_63 , V_58 ) ;
V_2 -> V_27 = V_25 ;
if ( V_55 -> V_68 & V_69 )
V_2 -> V_27 |= V_19 | V_20 ;
V_2 -> V_70 = 0 ;
if ( V_55 -> V_68 & V_71 )
V_2 -> V_70 |= V_19 | V_20 ;
if ( ( V_55 -> V_63 & V_72 ) == 0 )
V_2 -> V_70 |= V_16 ;
V_59 -= 1 ;
F_39 ( V_2 , V_59 ) ;
F_3 ( V_2 , V_3 ) ;
F_40 ( & V_2 -> V_30 , V_57 ) ;
}
static const char * F_41 ( struct V_1 * V_2 )
{
return V_2 -> type == V_73 ? L_3 : NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_74 , 0x100 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
return F_45 ( V_2 -> V_74 , 0x100 , L_4 )
!= NULL ? 0 : - V_75 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_57 )
{
if ( V_57 & V_76 ) {
V_2 -> type = V_73 ;
F_44 ( V_2 ) ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
int V_79 = 0 ;
if ( V_78 -> type != V_80 && V_78 -> type != V_73 )
V_79 = - V_81 ;
if ( V_78 -> V_41 < 0 || V_78 -> V_41 >= V_82 )
V_79 = - V_81 ;
if ( V_78 -> V_83 < 9600 )
V_79 = - V_81 ;
return V_79 ;
}
static int F_48 ( struct V_1 * V_2 , int V_84 )
{
int V_85 , V_86 = 0 ;
int V_7 ;
int V_12 ;
unsigned long V_57 ;
V_85 = F_2 ( V_2 ) ;
F_49 ( V_57 ) ;
F_3 ( V_2 , V_85 | V_53 ) ;
while ( ! F_50 ( F_5 ( V_2 ) ) )
V_86 ++ ;
F_3 ( V_2 , V_85 & ~ ( V_53 ) ) ;
V_12 = 1 ;
F_19 ( V_2 , 0 ) ;
V_7 = F_5 ( V_2 ) ;
while ( ( ( V_7 >> 20 ) & 0x3F ) == V_12 ) {
V_12 ++ ;
F_19 ( V_2 , 0 ) ;
V_7 = F_5 ( V_2 ) ;
}
V_12 -- ;
F_3 ( V_2 , V_85 ) ;
F_51 ( V_57 ) ;
if ( V_12 == 0 )
V_12 = 1 ;
return V_12 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_12 ; V_87 ++ )
F_11 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , int V_8 )
{
unsigned int V_7 ;
do {
V_7 = F_5 ( V_2 ) ;
} while ( ! F_50 ( V_7 ) );
F_19 ( V_2 , V_8 ) ;
}
static void
F_54 ( struct V_88 * V_89 , const char * V_90 , unsigned int V_34 )
{
struct V_1 * V_2 = & V_91 [ V_89 -> V_92 ] ;
unsigned int V_7 , V_93 , V_94 ;
V_93 = F_2 ( V_2 ) ;
V_94 = V_93 & ~ ( V_6 | V_4 ) ;
F_3 ( V_2 , V_94 ) ;
F_55 ( V_2 , V_90 , V_34 , F_53 ) ;
do {
V_7 = F_5 ( V_2 ) ;
} while ( ! F_50 ( V_7 ) );
F_3 ( V_2 , V_93 ) ;
}
static void T_2
F_56 ( struct V_1 * V_2 , int * V_58 ,
int * V_23 , int * V_95 )
{
if ( F_2 ( V_2 ) & ( V_52 | V_53 ) ) {
unsigned int V_59 , V_7 ;
V_7 = F_5 ( V_2 ) ;
* V_23 = 'n' ;
if ( V_7 & V_61 ) {
if ( ( V_7 & V_62 ) == 0 )
* V_23 = 'e' ;
else
* V_23 = 'o' ;
}
* V_95 = 8 ;
V_59 = F_57 ( V_2 ) / 8 ;
* V_58 = V_2 -> V_60 / ( 16 * ( V_59 + 1 ) ) ;
}
}
static int T_2 F_58 ( struct V_88 * V_89 , char * V_96 )
{
struct V_1 * V_2 ;
int V_58 = 38400 ;
int V_95 = 8 ;
int V_23 = 'n' ;
int V_97 = 'n' ;
F_59 ( L_5 ,
V_89 , V_89 -> V_92 , V_96 ) ;
if ( V_89 -> V_92 >= V_98 )
V_89 -> V_92 = 0 ;
V_2 = & V_91 [ V_89 -> V_92 ] ;
F_60 ( & V_2 -> V_30 ) ;
if ( V_96 )
F_61 ( V_96 , & V_58 , & V_23 , & V_95 , & V_97 ) ;
else
F_56 ( V_2 , & V_58 , & V_23 , & V_95 ) ;
return F_62 ( V_2 , V_89 , V_58 , V_23 , V_95 , V_97 ) ;
}
static int T_2 F_63 ( void )
{
if ( F_64 () )
return - V_99 ;
F_65 ( & V_100 ) ;
return 0 ;
}
static int F_66 ( struct V_101 * V_102 )
{
int V_87 ;
struct V_1 * V_2 = NULL ;
for ( V_87 = 0 ; V_87 < V_98 ; V_87 ++ ) {
if ( V_102 -> V_103 . V_104 == V_105 [ V_87 ] )
break;
}
V_2 = & V_91 [ V_87 ] ;
V_2 -> V_103 = & V_102 -> V_103 ;
V_2 -> V_41 = V_102 -> V_106 . V_107 [ 0 ] ;
F_67 ( & V_108 , (struct V_1 * ) V_2 ) ;
F_52 ( (struct V_1 * ) V_2 ) ;
F_68 ( V_109 L_6 ,
( unsigned long long ) V_2 -> V_74 , V_2 -> V_41 ) ;
return 0 ;
}
static int T_2 F_64 ( void )
{
struct V_110 * V_111 ;
int line = 0 ;
F_69 (np, apbuart_match) {
const int * V_112 ;
const T_3 * V_113 ;
const struct V_114 * V_115 ;
struct V_1 * V_2 ;
unsigned long V_116 ;
V_112 = F_70 ( V_111 , L_7 , NULL ) ;
if ( V_112 && ( * V_112 == 0 ) )
continue;
V_115 = F_70 ( V_111 , L_8 , NULL ) ;
V_113 = F_70 ( V_111 , L_9 , NULL ) ;
if ( ! V_115 || ! V_113 || ( * V_113 == 0 ) )
continue;
V_105 [ line ] = V_111 ;
V_116 = V_115 -> V_117 ;
V_2 = & V_91 [ line ] ;
V_2 -> V_74 = V_116 ;
V_2 -> V_118 = F_71 ( V_116 , sizeof( struct V_119 ) ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_120 = V_121 ;
V_2 -> V_122 = & V_123 ;
V_2 -> V_57 = V_124 ;
V_2 -> line = line ;
V_2 -> V_60 = * V_113 ;
V_2 -> V_12 = F_48 ( (struct V_1 * ) V_2 , line ) ;
line ++ ;
if ( line == V_125 )
break;
}
V_108 . V_126 = V_98 = line ;
return line ? 0 : - V_99 ;
}
static int T_2 F_72 ( void )
{
int V_79 ;
V_79 = F_64 () ;
if ( V_79 )
return V_79 ;
F_68 ( V_109 L_10 ) ;
V_79 = F_73 ( & V_108 ) ;
if ( V_79 ) {
F_68 ( V_127 L_11 ,
__FILE__ , V_79 ) ;
return V_79 ;
}
V_79 = F_74 ( & V_128 ) ;
if ( V_79 ) {
F_68 ( V_127
L_12 ,
__FILE__ , V_79 ) ;
F_75 ( & V_108 ) ;
return V_79 ;
}
return V_79 ;
}
static void T_4 F_76 ( void )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_98 ; V_87 ++ )
F_77 ( & V_108 ,
& V_91 [ V_87 ] ) ;
F_75 ( & V_108 ) ;
F_78 ( & V_128 ) ;
}
