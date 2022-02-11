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
V_44 = F_23 ( V_2 -> V_36 , F_10 , V_53 , L_1 , V_2 ) ;
if ( V_44 )
return V_44 ;
F_5 ( V_54 | V_55 ,
V_2 -> V_15 + V_56 ) ;
F_5 ( V_57 , V_2 -> V_15 + V_56 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_5 ( 0 , V_2 -> V_15 + V_56 ) ;
F_2 ( V_2 -> V_15 + V_56 ) ;
F_25 ( V_2 -> V_36 , V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_58 * V_59 ,
struct V_58 * V_60 )
{
unsigned long V_43 ;
unsigned int V_61 ;
F_13 ( & V_2 -> V_45 , V_43 ) ;
V_2 -> V_22 = V_10 | V_11
| V_28 ;
if ( V_59 -> V_62 & V_63 )
V_2 -> V_22 |=
V_17 | V_12 ;
V_2 -> V_21 = 0 ;
if ( V_59 -> V_62 & V_64 )
V_2 -> V_21 |= V_17
| V_12 | V_11 ;
if ( ( V_59 -> V_65 & V_66 ) == 0 )
V_2 -> V_21 |=
V_10 | V_17
| V_12 | V_11 ;
V_61 = F_27 ( V_2 , V_59 , V_60 , 0 , 460800 ) ;
F_28 ( V_2 , V_59 -> V_65 , V_61 ) ;
F_14 ( & V_2 -> V_45 , V_43 ) ;
}
static const char * F_29 ( struct V_1 * V_2 )
{
return V_2 -> type == V_67 ? L_1 : NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_68 , V_69 ) ;
F_32 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_34 ( L_2 ,
V_2 , ( unsigned long long ) V_2 -> V_68 ) ;
if ( ! F_35 ( V_2 -> V_68 , V_69 , L_1 ) ) {
F_36 ( V_2 -> V_70 , L_3 ) ;
return - V_71 ;
}
V_2 -> V_15 = F_37 ( V_2 -> V_68 , V_69 ) ;
if ( ! V_2 -> V_15 ) {
F_36 ( V_2 -> V_70 , L_4 ) ;
F_31 ( V_2 -> V_68 , V_69 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_43 )
{
if ( ! F_33 ( V_2 ) )
V_2 -> type = V_67 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
return - V_74 ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( ! ( F_2 ( V_2 -> V_15 + V_40 )
& V_10 ) )
return V_75 ;
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
int V_76 ;
T_2 V_77 ;
for ( V_76 = 0 ; V_76 < 100000 ; V_76 ++ ) {
V_77 = F_2 ( V_2 -> V_15 + V_40 ) ;
if ( ( V_77 & V_28 ) == 0 )
break;
F_42 () ;
}
}
static void F_44 ( struct V_1 * V_2 , int V_7 )
{
F_43 ( V_2 ) ;
F_5 ( V_7 , V_2 -> V_15 + V_30 ) ;
}
static void F_45 ( struct V_78 * V_79 , const char * V_80 ,
unsigned int V_81 )
{
struct V_1 * V_2 = & V_82 [ V_79 -> V_83 ] ;
unsigned long V_43 ;
unsigned int V_84 ;
int V_85 = 1 ;
if ( V_86 ) {
V_85 = F_46 ( & V_2 -> V_45 , V_43 ) ;
} else
F_13 ( & V_2 -> V_45 , V_43 ) ;
V_84 = F_2 ( V_2 -> V_15 + V_40 ) & V_87 ;
F_5 ( 0 , V_2 -> V_15 + V_56 ) ;
F_47 ( V_2 , V_80 , V_81 , F_44 ) ;
F_43 ( V_2 ) ;
if ( V_84 )
F_5 ( V_57 , V_2 -> V_15 + V_56 ) ;
if ( V_85 )
F_14 ( & V_2 -> V_45 , V_43 ) ;
}
static int F_48 ( struct V_78 * V_79 , char * V_88 )
{
struct V_1 * V_2 ;
int V_61 = 9600 ;
int V_89 = 8 ;
int V_18 = 'n' ;
int V_90 = 'n' ;
if ( V_79 -> V_83 < 0 || V_79 -> V_83 >= V_91 )
return - V_74 ;
V_2 = & V_82 [ V_79 -> V_83 ] ;
if ( ! V_2 -> V_68 ) {
F_34 ( L_5 , V_79 -> V_83 ) ;
return - V_92 ;
}
if ( ! V_2 -> V_15 ) {
if ( F_33 ( V_2 ) )
return - V_92 ;
}
if ( V_88 )
F_49 ( V_88 , & V_61 , & V_18 , & V_89 , & V_90 ) ;
return F_50 ( V_2 , V_79 , V_61 , V_18 , V_89 , V_90 ) ;
}
static int T_3 F_51 ( void )
{
F_52 ( & V_93 ) ;
return 0 ;
}
static int F_53 ( struct V_94 * V_70 , int V_95 , T_4 V_96 , int V_36 )
{
struct V_1 * V_2 ;
int V_97 ;
if ( V_95 < 0 ) {
for ( V_95 = 0 ; V_95 < V_91 ; V_95 ++ )
if ( V_82 [ V_95 ] . V_68 == 0 )
break;
}
if ( V_95 < 0 || V_95 >= V_91 ) {
F_36 ( V_70 , L_6 , V_98 , V_95 ) ;
return - V_74 ;
}
if ( ( V_82 [ V_95 ] . V_68 ) && ( V_82 [ V_95 ] . V_68 != V_96 ) ) {
F_36 ( V_70 , L_7 ,
V_98 , V_95 ) ;
return - V_71 ;
}
V_2 = & V_82 [ V_95 ] ;
F_54 ( & V_2 -> V_45 ) ;
V_2 -> V_99 = 16 ;
V_2 -> V_100 = 2 ;
V_2 -> V_101 = V_102 ;
V_2 -> V_103 = 1 ;
V_2 -> V_68 = V_96 ;
V_2 -> V_15 = NULL ;
V_2 -> V_104 = & V_105 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_43 = V_106 ;
V_2 -> V_70 = V_70 ;
V_2 -> type = V_107 ;
V_2 -> line = V_95 ;
F_55 ( V_70 , V_2 ) ;
V_97 = F_56 ( & V_108 , V_2 ) ;
if ( V_97 ) {
F_36 ( V_70 , L_8 , V_97 ) ;
V_2 -> V_68 = 0 ;
F_55 ( V_70 , NULL ) ;
return V_97 ;
}
return 0 ;
}
static int F_57 ( struct V_94 * V_70 )
{
struct V_1 * V_2 = F_58 ( V_70 ) ;
int V_97 = 0 ;
if ( V_2 ) {
V_97 = F_59 ( & V_108 , V_2 ) ;
F_55 ( V_70 , NULL ) ;
V_2 -> V_68 = 0 ;
}
return V_97 ;
}
static int F_60 ( struct V_109 * V_110 )
{
struct V_111 * V_112 , * V_113 ;
int V_95 = V_110 -> V_95 ;
#ifdef F_61
const T_5 * V_114 ;
V_114 = F_62 ( V_110 -> V_70 . V_115 , L_9 , NULL ) ;
if ( V_114 )
V_95 = F_63 ( V_114 ) ;
#endif
V_112 = F_64 ( V_110 , V_116 , 0 ) ;
if ( ! V_112 )
return - V_92 ;
V_113 = F_64 ( V_110 , V_117 , 0 ) ;
if ( ! V_113 )
return - V_92 ;
return F_53 ( & V_110 -> V_70 , V_95 , V_112 -> V_118 , V_113 -> V_118 ) ;
}
static int F_65 ( struct V_109 * V_110 )
{
return F_57 ( & V_110 -> V_70 ) ;
}
int T_3 F_66 ( void )
{
int V_44 ;
F_34 ( L_10 ) ;
V_44 = F_67 ( & V_108 ) ;
if ( V_44 )
goto V_119;
F_34 ( L_11 ) ;
V_44 = F_68 ( & V_120 ) ;
if ( V_44 )
goto V_121;
return 0 ;
V_121:
F_69 ( & V_108 ) ;
V_119:
F_70 ( V_122 L_12 , V_44 ) ;
return V_44 ;
}
void T_6 F_71 ( void )
{
F_72 ( & V_120 ) ;
F_69 ( & V_108 ) ;
}
