static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_7 ( V_4 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_6 ;
V_6 = F_5 ( V_4 ) ;
if ( V_6 & V_5 )
return V_7 ;
return 0 ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_2 . V_10 -> V_9 ;
int V_11 = 0 ;
unsigned char V_12 ;
if ( F_10 ( V_4 -> V_2 . V_13 ) ) {
F_11 ( V_4 , V_4 -> V_2 . V_13 ) ;
V_4 -> V_2 . V_14 . V_15 ++ ;
V_4 -> V_2 . V_13 = 0 ;
V_11 = 1 ;
} else if ( V_9 -> V_16 != V_9 -> V_17 ) {
V_12 = V_9 -> V_18 [ V_9 -> V_16 ] ;
V_9 -> V_16 = ( V_9 -> V_16 + 1 ) & ( V_19 - 1 ) ;
V_4 -> V_2 . V_14 . V_15 ++ ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_12 ) ;
V_11 = 1 ;
}
if ( F_12 ( V_9 ) < V_20 )
F_13 ( & V_4 -> V_2 ) ;
if ( V_11 )
F_14 ( V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_17 ( & V_4 -> V_2 . V_10 -> V_2 ) ;
unsigned int V_23 , V_12 , V_24 = 0 ;
if ( ! V_22 )
return;
while ( ! ( ( V_23 = F_5 ( V_4 ) ) & V_25 ) ) {
V_12 = F_18 ( V_4 ) ;
V_4 -> V_2 . V_14 . V_26 ++ ;
if ( F_10 ( V_23 & ( V_27 | V_28 ) ) ) {
if ( V_23 & V_27 ) {
V_4 -> V_2 . V_14 . V_29 ++ ;
V_24 = V_30 ;
F_19 ( V_4 , V_27 ) ;
}
if ( V_23 & V_28 ) {
V_4 -> V_2 . V_14 . V_31 ++ ;
V_24 = V_32 ;
F_19 ( V_4 , V_28 ) ;
}
} else
V_24 = V_33 ;
if ( F_10 ( F_20 ( & V_4 -> V_2 , V_12 ) ) )
goto V_34;
F_21 ( & V_4 -> V_2 , V_23 , V_27 , V_12 , V_24 ) ;
V_34:
F_22 ( V_22 ) ;
}
F_23 ( V_22 ) ;
}
static T_1 F_24 ( int V_35 , void * V_36 )
{
struct V_3 * V_4 = V_36 ;
unsigned int V_23 ;
V_23 = F_5 ( V_4 ) ;
if ( ( V_23 & V_37 ) && ! ( V_23 & V_25 ) ) {
F_25 ( & V_4 -> V_2 . V_38 ) ;
F_16 ( V_4 ) ;
F_26 ( & V_4 -> V_2 . V_38 ) ;
}
if ( ( V_23 & V_39 ) && ( V_23 & V_5 ) ) {
F_7 ( V_4 ) ;
F_25 ( & V_4 -> V_2 . V_38 ) ;
if ( ! F_27 ( & V_4 -> V_2 ) )
F_9 ( V_4 ) ;
F_26 ( & V_4 -> V_2 . V_38 ) ;
}
return V_40 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
return V_41 | V_42 | V_43 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_44 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 , int V_45 )
{
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_33 ( V_4 ) ;
if ( F_34 ( V_4 -> V_2 . V_35 , F_24 , 0 , L_1 ,
V_4 ) ) {
F_35 ( V_4 -> V_2 . V_46 , L_2 ) ;
return - V_47 ;
}
F_36 ( V_4 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_2 . V_35 , V_4 ) ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_48 * V_49 ,
struct V_48 * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_51 , V_52 , V_53 , V_54 ;
unsigned long V_55 ;
V_51 = F_40 ( V_2 , V_49 , V_50 , 0 , 460800 ) ;
V_54 = V_2 -> V_56 / ( V_4 -> V_51 * 4 ) - 1 ;
V_52 = V_54 & 0xFF ;
V_53 = ( V_54 >> 8 ) & 0xFF ;
if ( V_4 -> V_57 )
V_53 = 1 ;
F_41 ( & V_2 -> V_38 , V_55 ) ;
F_33 ( V_4 ) ;
F_42 ( V_4 , V_52 ) ;
F_43 ( V_4 , V_53 ) ;
F_36 ( V_4 ) ;
V_49 -> V_58 &= ~ ( V_59 | V_60 | V_61 ) ;
V_49 -> V_58 |= V_62 ;
if ( V_50 )
F_44 ( V_49 , V_50 ) ;
if ( F_45 ( V_49 ) )
F_46 ( V_49 , V_51 , V_51 ) ;
F_47 ( V_2 , V_49 -> V_58 , V_51 ) ;
F_48 ( & V_2 -> V_38 , V_55 ) ;
}
static const char * F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_2 . type == V_63 ? V_64 : NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
}
static int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( V_2 -> type != V_67 && V_66 -> type != V_63 )
return - V_68 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , int V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_55 & V_69 )
V_4 -> V_2 . type = V_63 ;
}
static void F_54 ( struct V_1 * V_2 , unsigned char V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_70 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_70 ;
while ( ! ( F_5 ( V_4 ) & V_25 ) )
F_6 () ;
V_70 = F_18 ( V_4 ) ;
return V_70 ;
}
static int
F_56 ( struct V_71 * V_72 , struct V_3 * V_4 )
{
struct V_73 * V_74 , * V_75 ;
unsigned long * V_76 ;
if ( V_72 -> V_77 < 0 || V_72 -> V_77 >= V_78 ) {
F_57 ( & V_72 -> V_46 , L_3 ) ;
return - V_79 ;
}
V_76 = ( ( unsigned long * ) ( V_72 -> V_46 . V_80 ) ) ;
V_4 -> V_51 = V_76 [ 0 ] ;
V_74 = F_58 ( V_72 , V_81 , 0 ) ;
if ( ! V_74 )
return - V_82 ;
V_75 = F_58 ( V_72 , V_83 , 0 ) ;
if ( ! V_75 )
return - V_82 ;
V_4 -> V_2 . V_84 = V_74 -> V_85 ;
V_4 -> V_2 . V_86 = F_59 ( V_74 -> V_85 , F_60 ( V_74 ) ) ;
if ( ! V_4 -> V_2 . V_86 )
return - V_87 ;
V_4 -> V_2 . V_35 = V_75 -> V_85 ;
V_4 -> V_2 . V_46 = & V_72 -> V_46 ;
V_4 -> V_2 . V_88 = V_89 ;
V_4 -> V_2 . V_55 = V_90 ;
V_4 -> V_2 . line = V_72 -> V_77 ;
V_4 -> V_2 . V_91 = & V_92 ;
V_4 -> V_2 . V_56 = V_76 [ 1 ] ;
V_4 -> V_2 . V_93 = V_94 ;
V_4 -> V_2 . V_95 = 0 ;
V_4 -> V_57 = ! ! V_76 [ 2 ] ;
return 0 ;
}
static int F_61 ( struct V_96 * V_97 , char * V_98 )
{
struct V_1 * V_2 ;
int V_51 = 115200 ;
int V_99 = 8 ;
int V_100 = 'n' ;
int V_101 = 'n' ;
if ( V_97 -> V_102 < 0 || V_97 -> V_102 >= V_78 )
return - V_82 ;
V_2 = & V_103 [ V_97 -> V_102 ] . V_2 ;
if ( ! V_2 -> V_86 )
return - V_82 ;
if ( V_98 )
F_62 ( V_98 , & V_51 , & V_100 , & V_99 , & V_101 ) ;
return F_63 ( V_2 , V_97 , V_51 , V_100 , V_99 , V_101 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_12 )
{
F_54 ( V_2 , ( unsigned char ) V_12 ) ;
}
static void F_65 ( struct V_96 * V_97 , const char * V_104 ,
unsigned int V_105 )
{
struct V_1 * V_2 = & V_103 [ V_97 -> V_102 ] . V_2 ;
unsigned long V_55 ;
F_41 ( & V_2 -> V_38 , V_55 ) ;
F_66 ( V_2 , V_104 , V_105 , F_64 ) ;
F_48 ( & V_2 -> V_38 , V_55 ) ;
}
static T_2 void F_67 ( struct V_96 * V_106 , const char * V_104 ,
unsigned int V_107 )
{
struct V_1 * V_2 = & V_103 [ V_106 -> V_102 ] . V_2 ;
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < V_107 ; V_108 ++ , V_104 ++ ) {
if ( * V_104 == '\n' )
F_54 ( V_2 , '\r' ) ;
F_54 ( V_2 , * V_104 ) ;
}
}
static int F_68 ( struct V_71 * V_72 )
{
V_109 . V_102 = V_72 -> V_77 ;
F_56 ( V_72 , & V_103 [ V_72 -> V_77 ] ) ;
F_61 ( & V_109 , NULL ) ;
F_69 ( & V_109 ) ;
return 0 ;
}
static int F_68 ( struct V_71 * V_72 )
{
return - V_82 ;
}
static int F_70 ( struct V_71 * V_72 )
{
struct V_3 * V_4 ;
int V_110 ;
if ( F_71 ( V_72 ) )
return F_68 ( V_72 ) ;
V_4 = & V_103 [ V_72 -> V_77 ] ;
V_110 = F_56 ( V_72 , V_4 ) ;
if ( V_110 )
return V_110 ;
return F_72 ( & V_111 , & V_4 -> V_2 ) ;
}
static int F_73 ( struct V_71 * V_72 )
{
return 0 ;
}
static int T_2 F_74 ( void )
{
int V_112 ;
V_112 = F_75 ( & V_111 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_76 ( & V_113 ) ;
if ( V_112 )
F_77 ( & V_111 ) ;
return V_112 ;
}
static void T_3 F_78 ( void )
{
F_79 ( & V_113 ) ;
F_77 ( & V_111 ) ;
}
