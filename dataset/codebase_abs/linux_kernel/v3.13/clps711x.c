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
unsigned int V_9 , V_10 , V_11 ;
for (; ; ) {
V_9 = F_11 ( F_12 ( V_2 ) ) ;
if ( V_9 & V_12 )
break;
V_10 = F_13 ( F_14 ( V_2 ) ) ;
V_9 = V_10 & ( V_13 | V_14 | V_15 ) ;
V_10 &= 0xff ;
V_2 -> V_16 . V_17 ++ ;
V_11 = V_18 ;
if ( F_15 ( V_9 ) ) {
if ( V_9 & V_14 )
V_2 -> V_16 . V_19 ++ ;
else if ( V_9 & V_13 )
V_2 -> V_16 . V_20 ++ ;
else if ( V_9 & V_15 )
V_2 -> V_16 . V_21 ++ ;
V_9 &= V_2 -> V_22 ;
if ( V_9 & V_14 )
V_11 = V_23 ;
else if ( V_9 & V_13 )
V_11 = V_24 ;
else if ( V_9 & V_15 )
V_11 = V_25 ;
}
if ( F_16 ( V_2 , V_10 ) )
continue;
if ( V_9 & V_2 -> V_26 )
continue;
F_17 ( V_2 , V_9 , V_15 , V_10 , V_11 ) ;
}
F_18 ( & V_2 -> V_27 -> V_2 ) ;
return V_28 ;
}
static T_1 F_19 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_29 * V_30 = & V_2 -> V_27 -> V_30 ;
if ( V_2 -> V_31 ) {
F_20 ( V_2 -> V_31 , F_14 ( V_2 ) ) ;
V_2 -> V_16 . V_32 ++ ;
V_2 -> V_31 = 0 ;
return V_28 ;
}
if ( F_21 ( V_30 ) || F_22 ( V_2 ) ) {
F_23 ( F_4 ( V_2 ) ) ;
V_4 -> V_6 [ V_2 -> line ] = 0 ;
return V_28 ;
}
while ( ! F_21 ( V_30 ) ) {
F_20 ( V_30 -> V_33 [ V_30 -> V_34 ] , F_14 ( V_2 ) ) ;
V_30 -> V_34 = ( V_30 -> V_34 + 1 ) & ( V_35 - 1 ) ;
V_2 -> V_16 . V_32 ++ ;
if ( F_11 ( F_12 ( V_2 ) & V_36 ) )
break;
}
if ( F_24 ( V_30 ) < V_37 )
F_25 ( V_2 ) ;
return V_28 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return ( F_11 ( F_12 ( V_2 ) & V_38 ) ) ? 0 : V_39 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
unsigned int V_9 , V_40 = 0 ;
if ( V_2 -> line == 0 ) {
V_9 = F_11 ( V_41 ) ;
if ( V_9 & V_42 )
V_40 |= V_43 ;
if ( V_9 & V_44 )
V_40 |= V_45 ;
if ( V_9 & V_46 )
V_40 |= V_47 ;
} else
V_40 = V_45 | V_47 | V_43 ;
return V_40 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_48 )
{
}
static void F_29 ( struct V_1 * V_2 , int V_49 )
{
unsigned long V_50 ;
unsigned int V_51 ;
F_30 ( & V_2 -> V_52 , V_50 ) ;
V_51 = F_11 ( F_31 ( V_2 ) ) ;
if ( V_49 )
V_51 |= V_53 ;
else
V_51 &= ~ V_53 ;
F_32 ( V_51 , F_31 ( V_2 ) ) ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_54 ;
V_4 -> V_6 [ V_2 -> line ] = 1 ;
V_54 = F_35 ( V_2 -> V_5 , F_4 ( V_2 ) , F_19 ,
0 , V_55 L_1 , V_2 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_35 ( V_2 -> V_5 , F_8 ( V_2 ) , F_10 ,
0 , V_55 L_2 , V_2 ) ;
if ( V_54 ) {
F_36 ( V_2 -> V_5 , F_4 ( V_2 ) , V_2 ) ;
return V_54 ;
}
F_32 ( F_11 ( F_31 ( V_2 ) ) & ~ V_53 , F_31 ( V_2 ) ) ;
F_32 ( F_11 ( F_37 ( V_2 ) ) | V_56 , F_37 ( V_2 ) ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_5 , F_4 ( V_2 ) , V_2 ) ;
F_36 ( V_2 -> V_5 , F_8 ( V_2 ) , V_2 ) ;
F_32 ( F_11 ( F_37 ( V_2 ) ) & ~ V_56 , F_37 ( V_2 ) ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_59 )
{
unsigned int V_51 , V_60 , V_61 ;
unsigned long V_50 ;
V_58 -> V_62 &= ~ V_63 ;
V_58 -> V_64 &= ~ ( V_65 | V_66 ) ;
V_60 = F_40 ( V_2 , V_58 , V_59 , V_2 -> V_67 / 4096 ,
V_2 -> V_67 / 16 ) ;
V_61 = F_41 ( V_2 , V_60 ) ;
switch ( V_58 -> V_62 & V_68 ) {
case V_69 :
V_51 = V_70 ;
break;
case V_71 :
V_51 = V_72 ;
break;
case V_73 :
V_51 = V_74 ;
break;
case V_75 :
default:
V_51 = V_76 ;
break;
}
if ( V_58 -> V_62 & V_77 )
V_51 |= V_78 ;
if ( V_58 -> V_62 & V_79 ) {
V_51 |= V_80 ;
if ( ! ( V_58 -> V_62 & V_81 ) )
V_51 |= V_82 ;
}
V_51 |= V_83 ;
F_30 ( & V_2 -> V_52 , V_50 ) ;
V_2 -> V_22 = V_15 ;
if ( V_58 -> V_64 & V_84 )
V_2 -> V_22 |= V_14 | V_13 ;
V_2 -> V_26 = 0 ;
if ( ! ( V_58 -> V_62 & V_85 ) )
V_2 -> V_26 |= V_15 | V_14 |
V_13 ;
F_42 ( V_2 , V_58 -> V_62 , V_60 ) ;
F_32 ( V_51 | ( V_61 - 1 ) , F_31 ( V_2 ) ) ;
F_33 ( & V_2 -> V_52 , V_50 ) ;
}
static const char * F_43 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_86 ) ? L_3 : NULL ;
}
static void F_44 ( struct V_1 * V_2 , int V_50 )
{
if ( V_50 & V_87 )
V_2 -> type = V_86 ;
}
static void F_45 ( struct V_1 * V_2 )
{
}
static int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , int V_10 )
{
while ( F_11 ( F_12 ( V_2 ) ) & V_36 )
F_48 () ;
F_20 ( V_10 , F_14 ( V_2 ) ) ;
}
static void F_49 ( struct V_88 * V_89 , const char * V_90 ,
unsigned V_91 )
{
struct V_3 * V_4 = (struct V_3 * ) V_89 -> V_92 ;
struct V_1 * V_2 = & V_4 -> V_2 [ V_89 -> V_93 ] ;
T_2 V_94 ;
V_94 = F_11 ( F_37 ( V_2 ) ) ;
F_32 ( V_94 | V_56 , F_37 ( V_2 ) ) ;
F_50 ( V_2 , V_90 , V_91 , F_47 ) ;
while ( F_11 ( F_12 ( V_2 ) ) & V_38 )
F_48 () ;
F_32 ( V_94 , F_37 ( V_2 ) ) ;
}
static void F_51 ( struct V_1 * V_2 ,
int * V_60 , int * V_19 ,
int * V_95 )
{
if ( F_11 ( F_37 ( V_2 ) ) & V_56 ) {
unsigned int V_51 , V_61 ;
V_51 = F_11 ( F_31 ( V_2 ) ) ;
* V_19 = 'n' ;
if ( V_51 & V_80 ) {
if ( V_51 & V_82 )
* V_19 = 'e' ;
else
* V_19 = 'o' ;
}
if ( ( V_51 & V_96 ) == V_74 )
* V_95 = 7 ;
else
* V_95 = 8 ;
V_61 = V_51 & V_97 ;
* V_60 = V_2 -> V_67 / ( 16 * ( V_61 + 1 ) ) ;
}
}
static int F_52 ( struct V_88 * V_89 , char * V_98 )
{
int V_60 = 38400 , V_95 = 8 , V_19 = 'n' , V_99 = 'n' ;
struct V_3 * V_4 = (struct V_3 * ) V_89 -> V_92 ;
struct V_1 * V_2 = & V_4 -> V_2 [ ( V_89 -> V_93 > 0 ) ? V_89 -> V_93 : 0 ] ;
if ( V_98 )
F_53 ( V_98 , & V_60 , & V_19 , & V_95 , & V_99 ) ;
else
F_51 ( V_2 , & V_60 , & V_19 , & V_95 ) ;
return F_54 ( V_2 , V_89 , V_60 , V_19 , V_95 , V_99 ) ;
}
static int F_55 ( struct V_100 * V_101 )
{
struct V_3 * V_4 ;
int V_54 , V_102 ;
V_4 = F_56 ( & V_101 -> V_5 , sizeof( struct V_3 ) , V_103 ) ;
if ( ! V_4 ) {
F_57 ( & V_101 -> V_5 , L_4 ) ;
return - V_104 ;
}
F_58 ( V_101 , V_4 ) ;
V_4 -> V_105 = F_59 ( & V_101 -> V_5 , L_5 ) ;
if ( F_60 ( V_4 -> V_105 ) ) {
F_57 ( & V_101 -> V_5 , L_6 ) ;
return F_61 ( V_4 -> V_105 ) ;
}
V_4 -> V_106 . V_107 = V_108 ;
V_4 -> V_106 . V_109 = L_7 ;
V_4 -> V_106 . V_110 = V_111 ;
V_4 -> V_106 . V_112 = V_113 ;
V_4 -> V_106 . V_114 = V_115 ;
#ifdef F_62
V_4 -> V_106 . V_116 = & V_4 -> V_88 ;
V_4 -> V_106 . V_116 -> V_117 = V_118 ;
V_4 -> V_106 . V_116 -> V_119 = F_49 ;
V_4 -> V_106 . V_116 -> V_120 = F_52 ;
V_4 -> V_106 . V_116 -> V_50 = V_121 ;
V_4 -> V_106 . V_116 -> V_93 = - 1 ;
V_4 -> V_106 . V_116 -> V_92 = V_4 ;
strcpy ( V_4 -> V_106 . V_116 -> V_122 , L_7 ) ;
#endif
V_54 = F_63 ( & V_4 -> V_106 ) ;
if ( V_54 ) {
F_57 ( & V_101 -> V_5 , L_8 ) ;
return V_54 ;
}
for ( V_102 = 0 ; V_102 < V_115 ; V_102 ++ ) {
V_4 -> V_2 [ V_102 ] . line = V_102 ;
V_4 -> V_2 [ V_102 ] . V_5 = & V_101 -> V_5 ;
V_4 -> V_2 [ V_102 ] . V_7 = F_4 ( & V_4 -> V_2 [ V_102 ] ) ;
V_4 -> V_2 [ V_102 ] . V_123 = F_37 ( & V_4 -> V_2 [ V_102 ] ) ;
V_4 -> V_2 [ V_102 ] . type = V_86 ;
V_4 -> V_2 [ V_102 ] . V_124 = 16 ;
V_4 -> V_2 [ V_102 ] . V_50 = V_125 | V_126 ;
V_4 -> V_2 [ V_102 ] . V_67 = F_64 ( V_4 -> V_105 ) ;
V_4 -> V_2 [ V_102 ] . V_127 = & V_128 ;
F_65 ( F_66 ( & V_4 -> V_106 , & V_4 -> V_2 [ V_102 ] ) ) ;
}
return 0 ;
}
static int F_67 ( struct V_100 * V_101 )
{
struct V_3 * V_4 = F_68 ( V_101 ) ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_115 ; V_102 ++ )
F_69 ( & V_4 -> V_106 , & V_4 -> V_2 [ V_102 ] ) ;
F_70 ( & V_4 -> V_106 ) ;
return 0 ;
}
static int T_3 F_71 ( void )
{
return F_72 ( & V_129 ) ;
}
static void T_4 F_73 ( void )
{
F_74 ( & V_129 ) ;
}
