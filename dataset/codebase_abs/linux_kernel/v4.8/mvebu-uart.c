static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
return ( V_4 & V_8 ) ? V_9 : 0 ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
return V_10 | V_11 | V_12 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_14 = F_3 ( V_2 -> V_6 + V_15 ) ;
V_14 &= ~ V_16 ;
F_8 ( V_14 , V_2 -> V_6 + V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_14 = F_3 ( V_2 -> V_6 + V_15 ) ;
V_14 |= V_16 ;
F_8 ( V_14 , V_2 -> V_6 + V_15 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_14 = F_3 ( V_2 -> V_6 + V_15 ) ;
V_14 &= ~ V_17 ;
F_8 ( V_14 , V_2 -> V_6 + V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_18 )
{
unsigned int V_14 ;
unsigned long V_3 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_14 = F_3 ( V_2 -> V_6 + V_15 ) ;
if ( V_18 == - 1 )
V_14 |= V_19 ;
else
V_14 &= ~ V_19 ;
F_8 ( V_14 , V_2 -> V_6 + V_15 ) ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_20 )
{
struct V_21 * V_22 = & V_2 -> V_23 -> V_2 ;
unsigned char V_24 = 0 ;
char V_25 = 0 ;
do {
if ( V_20 & V_26 ) {
V_24 = F_3 ( V_2 -> V_6 + V_27 ) ;
V_24 &= 0xff ;
V_25 = V_28 ;
V_2 -> V_29 . V_30 ++ ;
if ( V_20 & V_31 )
V_2 -> V_29 . V_32 ++ ;
}
if ( V_20 & V_33 ) {
V_2 -> V_29 . V_18 ++ ;
V_20 &= ~ ( V_34 | V_31 ) ;
if ( F_13 ( V_2 ) )
goto V_35;
}
if ( V_20 & V_36 )
V_2 -> V_29 . V_37 ++ ;
if ( V_20 & V_34 )
V_2 -> V_29 . V_38 ++ ;
if ( F_14 ( V_2 , V_24 ) )
goto V_35;
if ( V_20 & V_2 -> V_39 & V_31 )
V_20 &= ~ V_26 ;
V_20 &= V_2 -> V_40 ;
if ( V_20 & V_31 )
V_25 = V_41 ;
V_20 &= ~ V_2 -> V_39 ;
if ( V_20 & V_26 )
F_15 ( V_22 , V_24 , V_25 ) ;
if ( V_20 & V_33 )
F_15 ( V_22 , 0 , V_42 ) ;
if ( V_20 & V_34 )
F_15 ( V_22 , 0 , V_43 ) ;
if ( V_20 & V_36 )
F_15 ( V_22 , 0 , V_44 ) ;
V_35:
V_20 = F_3 ( V_2 -> V_6 + V_7 ) ;
} while ( V_20 & ( V_26 | V_33 ) );
F_16 ( V_22 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_20 )
{
struct V_45 * V_46 = & V_2 -> V_23 -> V_46 ;
unsigned int V_47 ;
unsigned int V_4 ;
if ( V_2 -> V_48 ) {
F_8 ( V_2 -> V_48 , V_2 -> V_6 + V_49 ) ;
V_2 -> V_29 . V_50 ++ ;
V_2 -> V_48 = 0 ;
return;
}
if ( F_18 ( V_46 ) || F_19 ( V_2 ) ) {
F_7 ( V_2 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_51 ; V_47 ++ ) {
F_8 ( V_46 -> V_52 [ V_46 -> V_53 ] , V_2 -> V_6 + V_49 ) ;
V_46 -> V_53 = ( V_46 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_29 . V_50 ++ ;
if ( F_18 ( V_46 ) )
break;
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 & V_55 )
break;
}
if ( F_20 ( V_46 ) < V_56 )
F_21 ( V_2 ) ;
if ( F_18 ( V_46 ) )
F_7 ( V_2 ) ;
}
static T_1 F_22 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
unsigned int V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 & ( V_26 | V_36 | V_34 | V_33 ) )
F_12 ( V_2 , V_4 ) ;
if ( V_4 & V_59 )
F_17 ( V_2 , V_4 ) ;
return V_60 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_61 ;
F_8 ( V_62 | V_63 ,
V_2 -> V_6 + V_15 ) ;
F_24 ( 1 ) ;
F_8 ( V_17 , V_2 -> V_6 + V_15 ) ;
V_61 = F_25 ( V_2 -> V_57 , F_22 , V_2 -> V_64 , L_1 ,
V_2 ) ;
if ( V_61 ) {
F_26 ( V_2 -> V_65 , L_2 ) ;
return V_61 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_6 + V_15 ) ;
F_28 ( V_2 -> V_57 , V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_66 * V_68 )
{
unsigned long V_3 ;
unsigned int V_69 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_40 = V_26 | V_36 |
V_59 | V_55 ;
if ( V_67 -> V_70 & V_71 )
V_2 -> V_40 |= V_34 | V_31 ;
V_2 -> V_39 = 0 ;
if ( V_67 -> V_70 & V_72 )
V_2 -> V_39 |=
V_34 | V_31 | V_36 ;
if ( ( V_67 -> V_73 & V_74 ) == 0 )
V_2 -> V_39 |= V_26 | V_75 ;
if ( V_68 )
F_30 ( V_67 , V_68 ) ;
V_69 = F_31 ( V_2 , V_67 , V_68 , 0 , 460800 ) ;
F_32 ( V_2 , V_67 -> V_73 , V_69 ) ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static const char * F_33 ( struct V_1 * V_2 )
{
return V_76 ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static int F_35 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_4 & V_26 ) )
return V_77 ;
return F_3 ( V_2 -> V_6 + V_27 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned char V_78 )
{
unsigned int V_4 ;
for (; ; ) {
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_4 & V_55 ) )
break;
F_24 ( 1 ) ;
}
F_8 ( V_78 , V_2 -> V_6 + V_49 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_78 )
{
unsigned int V_4 ;
for (; ; ) {
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_4 & V_55 ) )
break;
}
F_8 ( V_78 , V_2 -> V_6 + V_49 ) ;
for (; ; ) {
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 & V_8 )
break;
}
}
static void F_39 ( struct V_79 * V_80 ,
const char * V_81 ,
unsigned V_82 )
{
struct V_83 * V_65 = V_80 -> V_84 ;
F_40 ( & V_65 -> V_2 , V_81 , V_82 , F_38 ) ;
}
static int T_2
F_41 ( struct V_83 * V_85 ,
const char * V_86 )
{
if ( ! V_85 -> V_2 . V_6 )
return - V_87 ;
V_85 -> V_80 -> V_88 = F_39 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_3 V_89 ;
F_43 ( V_2 -> V_6 + V_7 , V_89 ,
( V_89 & V_90 ) , 1 , 10000 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_24 )
{
F_42 ( V_2 ) ;
F_8 ( V_24 , V_2 -> V_6 + V_49 ) ;
}
static void F_45 ( struct V_79 * V_91 , const char * V_81 ,
unsigned int V_47 )
{
struct V_1 * V_2 = & V_92 [ V_91 -> V_93 ] ;
unsigned long V_3 ;
unsigned int V_94 ;
int V_95 = 1 ;
if ( V_96 )
V_95 = F_46 ( & V_2 -> V_5 , V_3 ) ;
else
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_94 = F_3 ( V_2 -> V_6 + V_15 ) &
( V_17 | V_16 ) ;
F_8 ( 0 , V_2 -> V_6 + V_15 ) ;
F_40 ( V_2 , V_81 , V_47 , F_44 ) ;
F_42 ( V_2 ) ;
if ( V_94 )
F_8 ( V_94 , V_2 -> V_6 + V_15 ) ;
if ( V_95 )
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static int F_47 ( struct V_79 * V_91 , char * V_97 )
{
struct V_1 * V_2 ;
int V_69 = 9600 ;
int V_98 = 8 ;
int V_32 = 'n' ;
int V_99 = 'n' ;
if ( V_91 -> V_93 < 0 || V_91 -> V_93 >= V_100 )
return - V_101 ;
V_2 = & V_92 [ V_91 -> V_93 ] ;
if ( ! V_2 -> V_102 || ! V_2 -> V_6 ) {
F_48 ( L_3 , V_91 -> V_93 ) ;
return - V_87 ;
}
if ( V_97 )
F_49 ( V_97 , & V_69 , & V_32 , & V_98 , & V_99 ) ;
return F_50 ( V_2 , V_91 , V_69 , V_32 , V_98 , V_99 ) ;
}
static int T_2 F_51 ( void )
{
F_52 ( & V_103 ) ;
return 0 ;
}
static int F_53 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_54 ( V_105 , V_108 , 0 ) ;
struct V_106 * V_57 = F_54 ( V_105 , V_109 , 0 ) ;
struct V_1 * V_2 ;
struct V_110 * V_84 ;
int V_61 ;
if ( ! V_107 || ! V_57 ) {
F_26 ( & V_105 -> V_65 , L_4 ) ;
return - V_101 ;
}
V_2 = & V_92 [ 0 ] ;
F_55 ( & V_2 -> V_5 ) ;
V_2 -> V_65 = & V_105 -> V_65 ;
V_2 -> type = V_111 ;
V_2 -> V_112 = & V_113 ;
V_2 -> V_114 = 0 ;
V_2 -> V_51 = 32 ;
V_2 -> V_115 = V_116 ;
V_2 -> V_3 = V_117 ;
V_2 -> line = 0 ;
V_2 -> V_57 = V_57 -> V_118 ;
V_2 -> V_64 = 0 ;
V_2 -> V_102 = V_107 -> V_118 ;
V_2 -> V_6 = F_56 ( & V_105 -> V_65 , V_107 ) ;
if ( F_57 ( V_2 -> V_6 ) )
return - F_58 ( V_2 -> V_6 ) ;
V_84 = F_59 ( & V_105 -> V_65 , sizeof( struct V_110 ) ,
V_119 ) ;
if ( ! V_84 )
return - V_120 ;
V_84 -> V_2 = V_2 ;
V_2 -> V_121 = V_84 ;
F_60 ( V_105 , V_84 ) ;
V_61 = F_61 ( & V_122 , V_2 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int T_2 F_62 ( void )
{
int V_61 ;
V_61 = F_63 ( & V_122 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_64 ( & V_123 ) ;
if ( V_61 )
F_65 ( & V_122 ) ;
return V_61 ;
}
