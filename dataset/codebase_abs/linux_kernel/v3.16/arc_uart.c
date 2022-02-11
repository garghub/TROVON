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
} else if ( ! F_12 ( V_9 ) ) {
V_12 = V_9 -> V_16 [ V_9 -> V_17 ] ;
V_9 -> V_17 = ( V_9 -> V_17 + 1 ) & ( V_18 - 1 ) ;
V_4 -> V_2 . V_14 . V_15 ++ ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_12 ) ;
V_11 = 1 ;
}
if ( F_13 ( V_9 ) < V_19 )
F_14 ( & V_4 -> V_2 ) ;
if ( V_11 )
F_15 ( V_4 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 ) ;
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_20 )
{
unsigned int V_12 , V_21 = 0 ;
do {
if ( F_10 ( V_20 & ( V_22 | V_23 ) ) ) {
if ( V_20 & V_22 ) {
V_4 -> V_2 . V_14 . V_24 ++ ;
V_21 = V_25 ;
F_18 ( V_4 , V_22 ) ;
}
if ( V_20 & V_23 ) {
V_4 -> V_2 . V_14 . V_26 ++ ;
V_21 = V_27 ;
F_18 ( V_4 , V_23 ) ;
}
} else
V_21 = V_28 ;
if ( V_20 & V_29 )
continue;
V_12 = F_19 ( V_4 ) ;
V_4 -> V_2 . V_14 . V_30 ++ ;
if ( ! ( F_20 ( & V_4 -> V_2 , V_12 ) ) )
F_21 ( & V_4 -> V_2 , V_20 , V_22 , V_12 , V_21 ) ;
F_22 ( & V_4 -> V_2 . V_31 ) ;
F_23 ( & V_4 -> V_2 . V_10 -> V_2 ) ;
F_24 ( & V_4 -> V_2 . V_31 ) ;
} while ( ! ( ( V_20 = F_5 ( V_4 ) ) & V_29 ) );
}
static T_1 F_25 ( int V_32 , void * V_33 )
{
struct V_3 * V_4 = V_33 ;
unsigned int V_20 ;
V_20 = F_5 ( V_4 ) ;
if ( V_20 & V_34 ) {
F_24 ( & V_4 -> V_2 . V_31 ) ;
F_17 ( V_4 , V_20 ) ;
F_22 ( & V_4 -> V_2 . V_31 ) ;
}
if ( ( V_20 & V_35 ) && ( V_20 & V_5 ) ) {
F_7 ( V_4 ) ;
F_24 ( & V_4 -> V_2 . V_31 ) ;
if ( ! F_26 ( & V_4 -> V_2 ) )
F_9 ( V_4 ) ;
F_22 ( & V_4 -> V_2 . V_31 ) ;
}
return V_36 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
return V_37 | V_38 | V_39 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_40 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 , int V_41 )
{
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_32 ( V_4 ) ;
if ( F_33 ( V_4 -> V_2 . V_32 , F_25 , 0 , L_1 ,
V_4 ) ) {
F_34 ( V_4 -> V_2 . V_42 , L_2 ) ;
return - V_43 ;
}
F_35 ( V_4 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( V_4 -> V_2 . V_32 , V_4 ) ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_44 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_47 , V_48 , V_49 , V_50 ;
unsigned long V_51 ;
V_47 = F_39 ( V_2 , V_45 , V_46 , 0 , 460800 ) ;
V_50 = V_2 -> V_52 / ( V_4 -> V_47 * 4 ) - 1 ;
V_48 = V_50 & 0xFF ;
V_49 = ( V_50 >> 8 ) & 0xFF ;
if ( V_4 -> V_53 )
V_49 = 1 ;
F_40 ( & V_2 -> V_31 , V_51 ) ;
F_32 ( V_4 ) ;
F_41 ( V_4 , V_48 ) ;
F_42 ( V_4 , V_49 ) ;
F_35 ( V_4 ) ;
V_45 -> V_54 &= ~ ( V_55 | V_56 | V_57 ) ;
V_45 -> V_54 |= V_58 ;
if ( V_46 )
F_43 ( V_45 , V_46 ) ;
if ( F_44 ( V_45 ) )
F_45 ( V_45 , V_47 , V_47 ) ;
F_46 ( V_2 , V_45 -> V_54 , V_47 ) ;
F_47 ( & V_2 -> V_31 , V_51 ) ;
}
static const char * F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_2 . type == V_59 ? V_60 : NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
}
static int F_50 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
if ( V_2 -> type != V_63 && V_62 -> type != V_59 )
return - V_64 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , int V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_51 & V_65 )
V_4 -> V_2 . type = V_59 ;
}
static void F_53 ( struct V_1 * V_2 , unsigned char V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_66 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_66 ;
while ( ! ( F_5 ( V_4 ) & V_29 ) )
F_6 () ;
V_66 = F_19 ( V_4 ) ;
return V_66 ;
}
static int
F_55 ( struct V_67 * V_68 , int V_33 )
{
struct V_69 * V_70 , * V_71 ;
unsigned long * V_72 ;
struct V_3 * V_4 = & V_73 [ V_33 ] ;
V_72 = F_56 ( & V_68 -> V_42 ) ;
if ( ! V_72 )
return - V_74 ;
V_4 -> V_53 = ! ! V_72 [ 0 ] ;
if ( F_57 ( V_68 ) ) {
V_4 -> V_2 . V_52 = V_72 [ 1 ] ;
V_4 -> V_47 = V_72 [ 2 ] ;
} else {
struct V_75 * V_76 = V_68 -> V_42 . V_77 ;
T_2 V_78 ;
if ( F_58 ( V_76 , L_3 , & V_78 ) ) {
F_59 ( & V_68 -> V_42 , L_4 ) ;
return - V_64 ;
}
V_4 -> V_2 . V_52 = V_78 ;
if ( F_58 ( V_76 , L_5 , & V_78 ) ) {
F_59 ( & V_68 -> V_42 , L_6 ) ;
return - V_64 ;
}
V_4 -> V_47 = V_78 ;
}
V_70 = F_60 ( V_68 , V_79 , 0 ) ;
if ( ! V_70 )
return - V_74 ;
V_71 = F_60 ( V_68 , V_80 , 0 ) ;
if ( ! V_71 )
return - V_74 ;
V_4 -> V_2 . V_81 = V_70 -> V_82 ;
V_4 -> V_2 . V_83 = F_61 ( V_70 -> V_82 , F_62 ( V_70 ) ) ;
if ( ! V_4 -> V_2 . V_83 )
return - V_84 ;
V_4 -> V_2 . V_32 = V_71 -> V_82 ;
V_4 -> V_2 . V_42 = & V_68 -> V_42 ;
V_4 -> V_2 . V_85 = V_86 ;
V_4 -> V_2 . V_51 = V_87 ;
V_4 -> V_2 . line = V_33 ;
V_4 -> V_2 . V_88 = & V_89 ;
V_4 -> V_2 . V_90 = V_91 ;
V_4 -> V_2 . V_92 = 0 ;
return 0 ;
}
static int F_63 ( struct V_93 * V_94 , char * V_95 )
{
struct V_1 * V_2 ;
int V_47 = 115200 ;
int V_96 = 8 ;
int V_97 = 'n' ;
int V_98 = 'n' ;
if ( V_94 -> V_99 < 0 || V_94 -> V_99 >= V_100 )
return - V_74 ;
V_2 = & V_73 [ V_94 -> V_99 ] . V_2 ;
if ( ! V_2 -> V_83 )
return - V_74 ;
if ( V_95 )
F_64 ( V_95 , & V_47 , & V_97 , & V_96 , & V_98 ) ;
return F_65 ( V_2 , V_94 , V_47 , V_97 , V_96 , V_98 ) ;
}
static void F_66 ( struct V_1 * V_2 , int V_12 )
{
F_53 ( V_2 , ( unsigned char ) V_12 ) ;
}
static void F_67 ( struct V_93 * V_94 , const char * V_101 ,
unsigned int V_102 )
{
struct V_1 * V_2 = & V_73 [ V_94 -> V_99 ] . V_2 ;
unsigned long V_51 ;
F_40 ( & V_2 -> V_31 , V_51 ) ;
F_68 ( V_2 , V_101 , V_102 , F_66 ) ;
F_47 ( & V_2 -> V_31 , V_51 ) ;
}
static T_3 void F_69 ( struct V_93 * V_103 , const char * V_101 ,
unsigned int V_104 )
{
struct V_1 * V_2 = & V_73 [ V_103 -> V_99 ] . V_2 ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ , V_101 ++ ) {
if ( * V_101 == '\n' )
F_53 ( V_2 , '\r' ) ;
F_53 ( V_2 , * V_101 ) ;
}
}
static int T_3 F_70 ( struct V_67 * V_68 )
{
int V_33 = V_68 -> V_106 < 0 ? 0 : V_68 -> V_106 ;
int V_107 ;
V_108 . V_99 = V_33 ;
V_107 = F_55 ( V_68 , V_33 ) ;
if ( V_107 )
F_71 ( L_7 ) ;
F_63 ( & V_108 , NULL ) ;
F_72 ( & V_108 ) ;
return 0 ;
}
static int F_73 ( struct V_67 * V_68 )
{
int V_107 , V_33 ;
struct V_75 * V_76 = V_68 -> V_42 . V_77 ;
if ( ! V_76 )
return - V_74 ;
V_33 = F_74 ( V_76 , L_8 ) ;
if ( V_33 < 0 )
V_33 = 0 ;
V_107 = F_55 ( V_68 , V_33 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_75 ( & V_109 , & V_73 [ V_33 ] . V_2 ) ;
return V_107 ;
}
static int F_76 ( struct V_67 * V_68 )
{
return 0 ;
}
static int T_3 F_77 ( void )
{
int V_110 ;
V_110 = F_78 ( & V_109 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_79 ( & V_111 ) ;
if ( V_110 )
F_80 ( & V_109 ) ;
return V_110 ;
}
static void T_4 F_81 ( void )
{
F_82 ( & V_111 ) ;
F_80 ( & V_109 ) ;
}
