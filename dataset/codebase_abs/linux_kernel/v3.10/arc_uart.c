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
unsigned int V_21 , V_12 , V_22 = 0 ;
while ( ! ( ( V_21 = F_5 ( V_4 ) ) & V_23 ) ) {
V_12 = F_17 ( V_4 ) ;
V_4 -> V_2 . V_14 . V_24 ++ ;
if ( F_10 ( V_21 & ( V_25 | V_26 ) ) ) {
if ( V_21 & V_25 ) {
V_4 -> V_2 . V_14 . V_27 ++ ;
V_22 = V_28 ;
F_18 ( V_4 , V_25 ) ;
}
if ( V_21 & V_26 ) {
V_4 -> V_2 . V_14 . V_29 ++ ;
V_22 = V_30 ;
F_18 ( V_4 , V_26 ) ;
}
} else
V_22 = V_31 ;
if ( F_10 ( F_19 ( & V_4 -> V_2 , V_12 ) ) )
goto V_32;
F_20 ( & V_4 -> V_2 , V_21 , V_25 , V_12 , V_22 ) ;
V_32:
F_21 ( & V_4 -> V_2 . V_10 -> V_2 ) ;
}
}
static T_1 F_22 ( int V_33 , void * V_34 )
{
struct V_3 * V_4 = V_34 ;
unsigned int V_21 ;
V_21 = F_5 ( V_4 ) ;
if ( ( V_21 & V_35 ) && ! ( V_21 & V_23 ) ) {
F_23 ( & V_4 -> V_2 . V_36 ) ;
F_16 ( V_4 ) ;
F_24 ( & V_4 -> V_2 . V_36 ) ;
}
if ( ( V_21 & V_37 ) && ( V_21 & V_5 ) ) {
F_7 ( V_4 ) ;
F_23 ( & V_4 -> V_2 . V_36 ) ;
if ( ! F_25 ( & V_4 -> V_2 ) )
F_9 ( V_4 ) ;
F_24 ( & V_4 -> V_2 . V_36 ) ;
}
return V_38 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_39 | V_40 | V_41 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_42 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 , int V_43 )
{
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_4 ) ;
if ( F_32 ( V_4 -> V_2 . V_33 , F_22 , 0 , L_1 ,
V_4 ) ) {
F_33 ( V_4 -> V_2 . V_44 , L_2 ) ;
return - V_45 ;
}
F_34 ( V_4 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_4 -> V_2 . V_33 , V_4 ) ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_46 * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_49 , V_50 , V_51 , V_52 ;
unsigned long V_53 ;
V_49 = F_38 ( V_2 , V_47 , V_48 , 0 , 460800 ) ;
V_52 = V_2 -> V_54 / ( V_4 -> V_49 * 4 ) - 1 ;
V_50 = V_52 & 0xFF ;
V_51 = ( V_52 >> 8 ) & 0xFF ;
if ( V_4 -> V_55 )
V_51 = 1 ;
F_39 ( & V_2 -> V_36 , V_53 ) ;
F_31 ( V_4 ) ;
F_40 ( V_4 , V_50 ) ;
F_41 ( V_4 , V_51 ) ;
F_34 ( V_4 ) ;
V_47 -> V_56 &= ~ ( V_57 | V_58 | V_59 ) ;
V_47 -> V_56 |= V_60 ;
if ( V_48 )
F_42 ( V_47 , V_48 ) ;
if ( F_43 ( V_47 ) )
F_44 ( V_47 , V_49 , V_49 ) ;
F_45 ( V_2 , V_47 -> V_56 , V_49 ) ;
F_46 ( & V_2 -> V_36 , V_53 ) ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_2 . type == V_61 ? V_62 : NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
if ( V_2 -> type != V_65 && V_64 -> type != V_61 )
return - V_66 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , int V_53 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_53 & V_67 )
V_4 -> V_2 . type = V_61 ;
}
static void F_52 ( struct V_1 * V_2 , unsigned char V_68 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_68 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_68 ;
while ( ! ( F_5 ( V_4 ) & V_23 ) )
F_6 () ;
V_68 = F_17 ( V_4 ) ;
return V_68 ;
}
static int
F_54 ( struct V_69 * V_70 , int V_34 )
{
struct V_71 * V_72 , * V_73 ;
unsigned long * V_74 ;
struct V_3 * V_4 = & V_75 [ V_34 ] ;
V_74 = ( ( unsigned long * ) ( V_70 -> V_44 . V_76 ) ) ;
if ( ! V_74 )
return - V_77 ;
V_4 -> V_55 = ! ! V_74 [ 0 ] ;
if ( F_55 ( V_70 ) ) {
V_4 -> V_2 . V_54 = V_74 [ 1 ] ;
V_4 -> V_49 = V_74 [ 2 ] ;
} else {
struct V_78 * V_79 = V_70 -> V_44 . V_80 ;
T_2 V_81 ;
if ( F_56 ( V_79 , L_3 , & V_81 ) ) {
F_57 ( & V_70 -> V_44 , L_4 ) ;
return - V_66 ;
}
V_4 -> V_2 . V_54 = V_81 ;
if ( F_56 ( V_79 , L_5 , & V_81 ) ) {
F_57 ( & V_70 -> V_44 , L_6 ) ;
return - V_66 ;
}
V_4 -> V_49 = V_81 ;
}
V_72 = F_58 ( V_70 , V_82 , 0 ) ;
if ( ! V_72 )
return - V_77 ;
V_73 = F_58 ( V_70 , V_83 , 0 ) ;
if ( ! V_73 )
return - V_77 ;
V_4 -> V_2 . V_84 = V_72 -> V_85 ;
V_4 -> V_2 . V_86 = F_59 ( V_72 -> V_85 , F_60 ( V_72 ) ) ;
if ( ! V_4 -> V_2 . V_86 )
return - V_87 ;
V_4 -> V_2 . V_33 = V_73 -> V_85 ;
V_4 -> V_2 . V_44 = & V_70 -> V_44 ;
V_4 -> V_2 . V_88 = V_89 ;
V_4 -> V_2 . V_53 = V_90 ;
V_4 -> V_2 . line = V_34 ;
V_4 -> V_2 . V_91 = & V_92 ;
V_4 -> V_2 . V_93 = V_94 ;
V_4 -> V_2 . V_95 = 0 ;
return 0 ;
}
static int F_61 ( struct V_96 * V_97 , char * V_98 )
{
struct V_1 * V_2 ;
int V_49 = 115200 ;
int V_99 = 8 ;
int V_100 = 'n' ;
int V_101 = 'n' ;
if ( V_97 -> V_102 < 0 || V_97 -> V_102 >= V_103 )
return - V_77 ;
V_2 = & V_75 [ V_97 -> V_102 ] . V_2 ;
if ( ! V_2 -> V_86 )
return - V_77 ;
if ( V_98 )
F_62 ( V_98 , & V_49 , & V_100 , & V_99 , & V_101 ) ;
return F_63 ( V_2 , V_97 , V_49 , V_100 , V_99 , V_101 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_12 )
{
F_52 ( V_2 , ( unsigned char ) V_12 ) ;
}
static void F_65 ( struct V_96 * V_97 , const char * V_104 ,
unsigned int V_105 )
{
struct V_1 * V_2 = & V_75 [ V_97 -> V_102 ] . V_2 ;
unsigned long V_53 ;
F_39 ( & V_2 -> V_36 , V_53 ) ;
F_66 ( V_2 , V_104 , V_105 , F_64 ) ;
F_46 ( & V_2 -> V_36 , V_53 ) ;
}
static T_3 void F_67 ( struct V_96 * V_106 , const char * V_104 ,
unsigned int V_107 )
{
struct V_1 * V_2 = & V_75 [ V_106 -> V_102 ] . V_2 ;
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < V_107 ; V_108 ++ , V_104 ++ ) {
if ( * V_104 == '\n' )
F_52 ( V_2 , '\r' ) ;
F_52 ( V_2 , * V_104 ) ;
}
}
static int T_3 F_68 ( struct V_69 * V_70 )
{
int V_34 = V_70 -> V_109 < 0 ? 0 : V_70 -> V_109 ;
int V_110 ;
V_111 . V_102 = V_34 ;
V_110 = F_54 ( V_70 , V_34 ) ;
if ( V_110 )
F_69 ( L_7 ) ;
F_61 ( & V_111 , NULL ) ;
F_70 ( & V_111 ) ;
return 0 ;
}
static int F_71 ( struct V_69 * V_70 )
{
int V_110 , V_34 ;
struct V_78 * V_79 = V_70 -> V_44 . V_80 ;
if ( ! V_79 )
return - V_77 ;
V_34 = F_72 ( V_79 , L_8 ) ;
if ( V_34 < 0 )
V_34 = 0 ;
V_110 = F_54 ( V_70 , V_34 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_73 ( & V_112 , & V_75 [ V_34 ] . V_2 ) ;
return V_110 ;
}
static int F_74 ( struct V_69 * V_70 )
{
return 0 ;
}
static int T_3 F_75 ( void )
{
int V_113 ;
V_113 = F_76 ( & V_112 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_77 ( & V_114 ) ;
if ( V_113 )
F_78 ( & V_112 ) ;
return V_113 ;
}
static void T_4 F_79 ( void )
{
F_80 ( & V_114 ) ;
F_78 ( & V_112 ) ;
}
