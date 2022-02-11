static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_4 -> V_6 [ V_2 -> line ] ) {
F_3 ( F_4 ( V_2 ) ) ;
V_4 -> V_6 [ V_2 -> line ] = 0 ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_6 [ V_2 -> line ] ) {
F_6 ( F_4 ( V_2 ) ) ;
V_4 -> V_6 [ V_2 -> line ] = 1 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( F_8 ( V_2 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static T_1 F_10 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = F_11 ( & V_2 -> V_11 -> V_2 ) ;
unsigned int V_12 , V_13 , V_14 ;
if ( ! V_10 )
return V_15 ;
for (; ; ) {
V_12 = F_12 ( F_13 ( V_2 ) ) ;
if ( V_12 & V_16 )
break;
V_13 = F_14 ( F_15 ( V_2 ) ) ;
V_12 = V_13 & ( V_17 | V_18 | V_19 ) ;
V_13 &= 0xff ;
V_2 -> V_20 . V_21 ++ ;
V_14 = V_22 ;
if ( F_16 ( V_12 ) ) {
if ( V_12 & V_18 )
V_2 -> V_20 . V_23 ++ ;
else if ( V_12 & V_17 )
V_2 -> V_20 . V_24 ++ ;
else if ( V_12 & V_19 )
V_2 -> V_20 . V_25 ++ ;
V_12 &= V_2 -> V_26 ;
if ( V_12 & V_18 )
V_14 = V_27 ;
else if ( V_12 & V_17 )
V_14 = V_28 ;
else if ( V_12 & V_19 )
V_14 = V_29 ;
}
if ( F_17 ( V_2 , V_13 ) )
continue;
if ( V_12 & V_2 -> V_30 )
continue;
F_18 ( V_2 , V_12 , V_19 , V_13 , V_14 ) ;
}
F_19 ( V_10 ) ;
F_20 ( V_10 ) ;
return V_15 ;
}
static T_1 F_21 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_31 * V_32 = & V_2 -> V_11 -> V_32 ;
if ( V_2 -> V_33 ) {
F_22 ( V_2 -> V_33 , F_15 ( V_2 ) ) ;
V_2 -> V_20 . V_34 ++ ;
V_2 -> V_33 = 0 ;
return V_15 ;
}
if ( F_23 ( V_32 ) || F_24 ( V_2 ) ) {
F_25 ( F_4 ( V_2 ) ) ;
V_4 -> V_6 [ V_2 -> line ] = 0 ;
return V_15 ;
}
while ( ! F_23 ( V_32 ) ) {
F_22 ( V_32 -> V_35 [ V_32 -> V_36 ] , F_15 ( V_2 ) ) ;
V_32 -> V_36 = ( V_32 -> V_36 + 1 ) & ( V_37 - 1 ) ;
V_2 -> V_20 . V_34 ++ ;
if ( F_12 ( F_13 ( V_2 ) & V_38 ) )
break;
}
if ( F_26 ( V_32 ) < V_39 )
F_27 ( V_2 ) ;
return V_15 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
return ( F_12 ( F_13 ( V_2 ) & V_40 ) ) ? 0 : V_41 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
unsigned int V_12 , V_42 = 0 ;
if ( V_2 -> line == 0 ) {
V_12 = F_12 ( V_43 ) ;
if ( V_12 & V_44 )
V_42 |= V_45 ;
if ( V_12 & V_46 )
V_42 |= V_47 ;
if ( V_12 & V_48 )
V_42 |= V_49 ;
} else
V_42 = V_47 | V_49 | V_45 ;
return V_42 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_50 )
{
}
static void F_31 ( struct V_1 * V_2 , int V_51 )
{
unsigned long V_52 ;
unsigned int V_53 ;
F_32 ( & V_2 -> V_54 , V_52 ) ;
V_53 = F_12 ( F_33 ( V_2 ) ) ;
if ( V_51 )
V_53 |= V_55 ;
else
V_53 &= ~ V_55 ;
F_34 ( V_53 , F_33 ( V_2 ) ) ;
F_35 ( & V_2 -> V_54 , V_52 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_56 ;
V_4 -> V_6 [ V_2 -> line ] = 1 ;
V_56 = F_37 ( V_2 -> V_5 , F_4 ( V_2 ) , F_21 ,
0 , V_57 L_1 , V_2 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_37 ( V_2 -> V_5 , F_8 ( V_2 ) , F_10 ,
0 , V_57 L_2 , V_2 ) ;
if ( V_56 ) {
F_38 ( V_2 -> V_5 , F_4 ( V_2 ) , V_2 ) ;
return V_56 ;
}
F_34 ( F_12 ( F_33 ( V_2 ) ) & ~ V_55 , F_33 ( V_2 ) ) ;
F_34 ( F_12 ( F_39 ( V_2 ) ) | V_58 , F_39 ( V_2 ) ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_5 , F_4 ( V_2 ) , V_2 ) ;
F_38 ( V_2 -> V_5 , F_8 ( V_2 ) , V_2 ) ;
F_34 ( F_12 ( F_39 ( V_2 ) ) & ~ V_58 , F_39 ( V_2 ) ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_59 * V_61 )
{
unsigned int V_53 , V_62 , V_63 ;
unsigned long V_52 ;
V_60 -> V_64 &= ~ V_65 ;
V_60 -> V_66 &= ~ ( V_67 | V_68 ) ;
V_62 = F_42 ( V_2 , V_60 , V_61 , V_2 -> V_69 / 4096 ,
V_2 -> V_69 / 16 ) ;
V_63 = F_43 ( V_2 , V_62 ) ;
switch ( V_60 -> V_64 & V_70 ) {
case V_71 :
V_53 = V_72 ;
break;
case V_73 :
V_53 = V_74 ;
break;
case V_75 :
V_53 = V_76 ;
break;
case V_77 :
default:
V_53 = V_78 ;
break;
}
if ( V_60 -> V_64 & V_79 )
V_53 |= V_80 ;
if ( V_60 -> V_64 & V_81 ) {
V_53 |= V_82 ;
if ( ! ( V_60 -> V_64 & V_83 ) )
V_53 |= V_84 ;
}
V_53 |= V_85 ;
F_32 ( & V_2 -> V_54 , V_52 ) ;
V_2 -> V_26 = V_19 ;
if ( V_60 -> V_66 & V_86 )
V_2 -> V_26 |= V_18 | V_17 ;
V_2 -> V_30 = 0 ;
if ( ! ( V_60 -> V_64 & V_87 ) )
V_2 -> V_30 |= V_19 | V_18 |
V_17 ;
F_44 ( V_2 , V_60 -> V_64 , V_62 ) ;
F_34 ( V_53 | ( V_63 - 1 ) , F_33 ( V_2 ) ) ;
F_35 ( & V_2 -> V_54 , V_52 ) ;
}
static const char * F_45 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_88 ) ? L_3 : NULL ;
}
static void F_46 ( struct V_1 * V_2 , int V_52 )
{
if ( V_52 & V_89 )
V_2 -> type = V_88 ;
}
static void F_47 ( struct V_1 * V_2 )
{
}
static int F_48 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , int V_13 )
{
while ( F_12 ( F_13 ( V_2 ) ) & V_38 )
F_50 () ;
F_22 ( V_13 , F_15 ( V_2 ) ) ;
}
static void F_51 ( struct V_90 * V_91 , const char * V_92 ,
unsigned V_93 )
{
struct V_3 * V_4 = (struct V_3 * ) V_91 -> V_94 ;
struct V_1 * V_2 = & V_4 -> V_2 [ V_91 -> V_95 ] ;
T_2 V_96 ;
V_96 = F_12 ( F_39 ( V_2 ) ) ;
F_34 ( V_96 | V_58 , F_39 ( V_2 ) ) ;
F_52 ( V_2 , V_92 , V_93 , F_49 ) ;
while ( F_12 ( F_13 ( V_2 ) ) & V_40 )
F_50 () ;
F_34 ( V_96 , F_39 ( V_2 ) ) ;
}
static void F_53 ( struct V_1 * V_2 ,
int * V_62 , int * V_23 ,
int * V_97 )
{
if ( F_12 ( F_39 ( V_2 ) ) & V_58 ) {
unsigned int V_53 , V_63 ;
V_53 = F_12 ( F_33 ( V_2 ) ) ;
* V_23 = 'n' ;
if ( V_53 & V_82 ) {
if ( V_53 & V_84 )
* V_23 = 'e' ;
else
* V_23 = 'o' ;
}
if ( ( V_53 & V_98 ) == V_76 )
* V_97 = 7 ;
else
* V_97 = 8 ;
V_63 = V_53 & V_99 ;
* V_62 = V_2 -> V_69 / ( 16 * ( V_63 + 1 ) ) ;
}
}
static int F_54 ( struct V_90 * V_91 , char * V_100 )
{
int V_62 = 38400 , V_97 = 8 , V_23 = 'n' , V_101 = 'n' ;
struct V_3 * V_4 = (struct V_3 * ) V_91 -> V_94 ;
struct V_1 * V_2 = & V_4 -> V_2 [ ( V_91 -> V_95 > 0 ) ? V_91 -> V_95 : 0 ] ;
if ( V_100 )
F_55 ( V_100 , & V_62 , & V_23 , & V_97 , & V_101 ) ;
else
F_53 ( V_2 , & V_62 , & V_23 , & V_97 ) ;
return F_56 ( V_2 , V_91 , V_62 , V_23 , V_97 , V_101 ) ;
}
static int F_57 ( struct V_102 * V_103 )
{
struct V_3 * V_4 ;
int V_56 , V_104 ;
V_4 = F_58 ( & V_103 -> V_5 , sizeof( struct V_3 ) , V_105 ) ;
if ( ! V_4 ) {
F_59 ( & V_103 -> V_5 , L_4 ) ;
return - V_106 ;
}
F_60 ( V_103 , V_4 ) ;
V_4 -> V_107 = F_61 ( & V_103 -> V_5 , L_5 ) ;
if ( F_62 ( V_4 -> V_107 ) ) {
F_59 ( & V_103 -> V_5 , L_6 ) ;
V_56 = F_63 ( V_4 -> V_107 ) ;
goto V_108;
}
V_4 -> V_109 . V_110 = V_111 ;
V_4 -> V_109 . V_112 = L_7 ;
V_4 -> V_109 . V_113 = V_114 ;
V_4 -> V_109 . V_115 = V_116 ;
V_4 -> V_109 . V_117 = V_118 ;
#ifdef F_64
V_4 -> V_109 . V_119 = & V_4 -> V_90 ;
V_4 -> V_109 . V_119 -> V_120 = V_121 ;
V_4 -> V_109 . V_119 -> V_122 = F_51 ;
V_4 -> V_109 . V_119 -> V_123 = F_54 ;
V_4 -> V_109 . V_119 -> V_52 = V_124 ;
V_4 -> V_109 . V_119 -> V_95 = - 1 ;
V_4 -> V_109 . V_119 -> V_94 = V_4 ;
strcpy ( V_4 -> V_109 . V_119 -> V_125 , L_7 ) ;
#endif
V_56 = F_65 ( & V_4 -> V_109 ) ;
if ( V_56 ) {
F_59 ( & V_103 -> V_5 , L_8 ) ;
F_66 ( & V_103 -> V_5 , V_4 -> V_107 ) ;
goto V_108;
}
for ( V_104 = 0 ; V_104 < V_118 ; V_104 ++ ) {
V_4 -> V_2 [ V_104 ] . line = V_104 ;
V_4 -> V_2 [ V_104 ] . V_5 = & V_103 -> V_5 ;
V_4 -> V_2 [ V_104 ] . V_7 = F_4 ( & V_4 -> V_2 [ V_104 ] ) ;
V_4 -> V_2 [ V_104 ] . V_126 = F_39 ( & V_4 -> V_2 [ V_104 ] ) ;
V_4 -> V_2 [ V_104 ] . type = V_88 ;
V_4 -> V_2 [ V_104 ] . V_127 = 16 ;
V_4 -> V_2 [ V_104 ] . V_52 = V_128 | V_129 ;
V_4 -> V_2 [ V_104 ] . V_69 = F_67 ( V_4 -> V_107 ) ;
V_4 -> V_2 [ V_104 ] . V_130 = & V_131 ;
F_68 ( F_69 ( & V_4 -> V_109 , & V_4 -> V_2 [ V_104 ] ) ) ;
}
return 0 ;
V_108:
F_60 ( V_103 , NULL ) ;
return V_56 ;
}
static int F_70 ( struct V_102 * V_103 )
{
struct V_3 * V_4 = F_71 ( V_103 ) ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_118 ; V_104 ++ )
F_72 ( & V_4 -> V_109 , & V_4 -> V_2 [ V_104 ] ) ;
F_66 ( & V_103 -> V_5 , V_4 -> V_107 ) ;
F_73 ( & V_4 -> V_109 ) ;
F_60 ( V_103 , NULL ) ;
return 0 ;
}
static int T_3 F_74 ( void )
{
return F_75 ( & V_132 ) ;
}
static void T_4 F_76 ( void )
{
F_77 ( & V_132 ) ;
}
