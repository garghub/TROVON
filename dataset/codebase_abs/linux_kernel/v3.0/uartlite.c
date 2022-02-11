static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_2 . V_5 ;
unsigned char V_7 = 0 ;
char V_8 = V_9 ;
if ( ( V_3 & ( V_10 | V_11
| V_12 ) ) == 0 )
return 0 ;
if ( V_3 & V_10 ) {
V_2 -> V_13 . V_14 ++ ;
V_7 = F_2 ( V_2 -> V_15 + V_16 ) ;
if ( V_3 & V_17 )
V_2 -> V_13 . V_18 ++ ;
}
if ( V_3 & V_11 )
V_2 -> V_13 . V_19 ++ ;
if ( V_3 & V_12 )
V_2 -> V_13 . V_20 ++ ;
if ( V_3 & V_2 -> V_21 & V_17 )
V_3 &= ~ V_10 ;
V_3 &= V_2 -> V_22 ;
if ( V_3 & V_17 )
V_8 = V_23 ;
V_3 &= ~ V_2 -> V_21 ;
if ( V_3 & V_10 )
F_3 ( V_5 , V_7 , V_8 ) ;
if ( V_3 & V_12 )
F_3 ( V_5 , 0 , V_24 ) ;
if ( V_3 & V_11 )
F_3 ( V_5 , 0 , V_25 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_26 * V_27 = & V_2 -> V_6 -> V_27 ;
if ( V_3 & V_28 )
return 0 ;
if ( V_2 -> V_29 ) {
F_5 ( V_2 -> V_29 , V_2 -> V_15 + V_30 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_13 . V_31 ++ ;
return 1 ;
}
if ( F_6 ( V_27 ) || F_7 ( V_2 ) )
return 0 ;
F_5 ( V_27 -> V_32 [ V_27 -> V_33 ] , V_2 -> V_15 + V_30 ) ;
V_27 -> V_33 = ( V_27 -> V_33 + 1 ) & ( V_34 - 1 ) ;
V_2 -> V_13 . V_31 ++ ;
if ( F_8 ( V_27 ) < V_35 )
F_9 ( V_2 ) ;
return 1 ;
}
static T_1 F_10 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
int V_38 , V_39 = 0 ;
do {
int V_3 = F_2 ( V_2 -> V_15 + V_40 ) ;
V_38 = F_1 ( V_2 , V_3 ) ;
V_38 |= F_4 ( V_2 , V_3 ) ;
V_39 ++ ;
} while ( V_38 );
if ( V_39 > 1 ) {
F_11 ( V_2 -> V_6 -> V_2 . V_5 ) ;
return V_41 ;
} else {
return V_42 ;
}
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned int V_44 ;
F_13 ( & V_2 -> V_45 , V_43 ) ;
V_44 = F_2 ( V_2 -> V_15 + V_40 ) ;
F_14 ( & V_2 -> V_45 , V_43 ) ;
return V_44 & V_46 ? V_47 : 0 ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
return V_48 | V_49 | V_50 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_51 )
{
}
static void F_17 ( struct V_1 * V_2 )
{
}
static void F_18 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_2 ( V_2 -> V_15 + V_40 ) ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_21 = V_10 | V_17
| V_12 | V_11 ;
}
static void F_20 ( struct V_1 * V_2 )
{
}
static void F_21 ( struct V_1 * V_2 , int V_52 )
{
}
static int F_22 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_23 ( V_2 -> V_36 , F_10 ,
V_53 | V_54 , L_1 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_5 ( V_55 | V_56 ,
V_2 -> V_15 + V_57 ) ;
F_5 ( V_58 , V_2 -> V_15 + V_57 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_5 ( 0 , V_2 -> V_15 + V_57 ) ;
F_2 ( V_2 -> V_15 + V_57 ) ;
F_25 ( V_2 -> V_36 , V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_59 * V_60 ,
struct V_59 * V_61 )
{
unsigned long V_43 ;
unsigned int V_62 ;
F_13 ( & V_2 -> V_45 , V_43 ) ;
V_2 -> V_22 = V_10 | V_11
| V_28 ;
if ( V_60 -> V_63 & V_64 )
V_2 -> V_22 |=
V_17 | V_12 ;
V_2 -> V_21 = 0 ;
if ( V_60 -> V_63 & V_65 )
V_2 -> V_21 |= V_17
| V_12 | V_11 ;
if ( ( V_60 -> V_66 & V_67 ) == 0 )
V_2 -> V_21 |=
V_10 | V_17
| V_12 | V_11 ;
V_62 = F_27 ( V_2 , V_60 , V_61 , 0 , 460800 ) ;
F_28 ( V_2 , V_60 -> V_66 , V_62 ) ;
F_14 ( & V_2 -> V_45 , V_43 ) ;
}
static const char * F_29 ( struct V_1 * V_2 )
{
return V_2 -> type == V_68 ? L_1 : NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_69 , V_70 ) ;
F_32 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_34 ( L_2 ,
V_2 , ( unsigned long long ) V_2 -> V_69 ) ;
if ( ! F_35 ( V_2 -> V_69 , V_70 , L_1 ) ) {
F_36 ( V_2 -> V_71 , L_3 ) ;
return - V_72 ;
}
V_2 -> V_15 = F_37 ( V_2 -> V_69 , V_70 ) ;
if ( ! V_2 -> V_15 ) {
F_36 ( V_2 -> V_71 , L_4 ) ;
F_31 ( V_2 -> V_69 , V_70 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_43 )
{
if ( ! F_33 ( V_2 ) )
V_2 -> type = V_68 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
return - V_75 ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( ! ( F_2 ( V_2 -> V_15 + V_40 )
& V_10 ) )
return V_76 ;
return F_2 ( V_2 -> V_15 + V_16 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned char V_7 )
{
while ( F_2 ( V_2 -> V_15 + V_40 ) & V_28 )
F_42 () ;
F_5 ( V_7 , V_2 -> V_15 + V_30 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_77 ;
T_2 V_78 ;
for ( V_77 = 0 ; V_77 < 100000 ; V_77 ++ ) {
V_78 = F_2 ( V_2 -> V_15 + V_40 ) ;
if ( ( V_78 & V_28 ) == 0 )
break;
F_42 () ;
}
}
static void F_44 ( struct V_1 * V_2 , int V_7 )
{
F_43 ( V_2 ) ;
F_5 ( V_7 , V_2 -> V_15 + V_30 ) ;
}
static void F_45 ( struct V_79 * V_80 , const char * V_81 ,
unsigned int V_82 )
{
struct V_1 * V_2 = & V_83 [ V_80 -> V_84 ] ;
unsigned long V_43 ;
unsigned int V_85 ;
int V_86 = 1 ;
if ( V_87 ) {
V_86 = F_46 ( & V_2 -> V_45 , V_43 ) ;
} else
F_13 ( & V_2 -> V_45 , V_43 ) ;
V_85 = F_2 ( V_2 -> V_15 + V_40 ) & V_88 ;
F_5 ( 0 , V_2 -> V_15 + V_57 ) ;
F_47 ( V_2 , V_81 , V_82 , F_44 ) ;
F_43 ( V_2 ) ;
if ( V_85 )
F_5 ( V_58 , V_2 -> V_15 + V_57 ) ;
if ( V_86 )
F_14 ( & V_2 -> V_45 , V_43 ) ;
}
static int T_3 F_48 ( struct V_79 * V_80 , char * V_89 )
{
struct V_1 * V_2 ;
int V_62 = 9600 ;
int V_90 = 8 ;
int V_18 = 'n' ;
int V_91 = 'n' ;
if ( V_80 -> V_84 < 0 || V_80 -> V_84 >= V_92 )
return - V_75 ;
V_2 = & V_83 [ V_80 -> V_84 ] ;
if ( ! V_2 -> V_69 ) {
F_34 ( L_5 , V_80 -> V_84 ) ;
return - V_93 ;
}
if ( ! V_2 -> V_15 ) {
if ( F_33 ( V_2 ) )
return - V_93 ;
}
if ( V_89 )
F_49 ( V_89 , & V_62 , & V_18 , & V_90 , & V_91 ) ;
return F_50 ( V_2 , V_80 , V_62 , V_18 , V_90 , V_91 ) ;
}
static int T_4 F_51 ( void )
{
F_52 ( & V_94 ) ;
return 0 ;
}
static int T_3 F_53 ( struct V_95 * V_71 , int V_96 , T_5 V_97 , int V_36 )
{
struct V_1 * V_2 ;
int V_98 ;
if ( V_96 < 0 ) {
for ( V_96 = 0 ; V_96 < V_92 ; V_96 ++ )
if ( V_83 [ V_96 ] . V_69 == 0 )
break;
}
if ( V_96 < 0 || V_96 >= V_92 ) {
F_36 ( V_71 , L_6 , V_99 , V_96 ) ;
return - V_75 ;
}
if ( ( V_83 [ V_96 ] . V_69 ) && ( V_83 [ V_96 ] . V_69 != V_97 ) ) {
F_36 ( V_71 , L_7 ,
V_99 , V_96 ) ;
return - V_72 ;
}
V_2 = & V_83 [ V_96 ] ;
F_54 ( & V_2 -> V_45 ) ;
V_2 -> V_100 = 16 ;
V_2 -> V_101 = 2 ;
V_2 -> V_102 = V_103 ;
V_2 -> V_104 = 1 ;
V_2 -> V_69 = V_97 ;
V_2 -> V_15 = NULL ;
V_2 -> V_105 = & V_106 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_43 = V_107 ;
V_2 -> V_71 = V_71 ;
V_2 -> type = V_108 ;
V_2 -> line = V_96 ;
F_55 ( V_71 , V_2 ) ;
V_98 = F_56 ( & V_109 , V_2 ) ;
if ( V_98 ) {
F_36 ( V_71 , L_8 , V_98 ) ;
V_2 -> V_69 = 0 ;
F_55 ( V_71 , NULL ) ;
return V_98 ;
}
return 0 ;
}
static int T_6 F_57 ( struct V_95 * V_71 )
{
struct V_1 * V_2 = F_58 ( V_71 ) ;
int V_98 = 0 ;
if ( V_2 ) {
V_98 = F_59 ( & V_109 , V_2 ) ;
F_55 ( V_71 , NULL ) ;
V_2 -> V_69 = 0 ;
}
return V_98 ;
}
static int T_3 F_60 ( struct V_110 * V_111 )
{
struct V_112 * V_113 , * V_114 ;
int V_96 = V_111 -> V_96 ;
#ifdef F_61
const T_7 * V_115 ;
V_115 = F_62 ( V_111 -> V_71 . V_116 , L_9 , NULL ) ;
if ( V_115 )
V_96 = F_63 ( V_115 ) ;
#endif
V_113 = F_64 ( V_111 , V_117 , 0 ) ;
if ( ! V_113 )
return - V_93 ;
V_114 = F_64 ( V_111 , V_118 , 0 ) ;
if ( ! V_114 )
return - V_93 ;
return F_53 ( & V_111 -> V_71 , V_96 , V_113 -> V_119 , V_114 -> V_119 ) ;
}
static int T_6 F_65 ( struct V_110 * V_111 )
{
return F_57 ( & V_111 -> V_71 ) ;
}
int T_4 F_66 ( void )
{
int V_44 ;
F_34 ( L_10 ) ;
V_44 = F_67 ( & V_109 ) ;
if ( V_44 )
goto V_120;
F_34 ( L_11 ) ;
V_44 = F_68 ( & V_121 ) ;
if ( V_44 )
goto V_122;
return 0 ;
V_122:
F_69 ( & V_109 ) ;
V_120:
F_70 ( V_123 L_12 , V_44 ) ;
return V_44 ;
}
void T_8 F_71 ( void )
{
F_72 ( & V_121 ) ;
F_69 ( & V_109 ) ;
}
