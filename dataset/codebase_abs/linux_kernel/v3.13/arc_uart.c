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
static void F_16 ( struct V_3 * V_4 , unsigned int V_21 )
{
unsigned int V_12 , V_22 = 0 ;
do {
if ( F_10 ( V_21 & ( V_23 | V_24 ) ) ) {
if ( V_21 & V_23 ) {
V_4 -> V_2 . V_14 . V_25 ++ ;
V_22 = V_26 ;
F_17 ( V_4 , V_23 ) ;
}
if ( V_21 & V_24 ) {
V_4 -> V_2 . V_14 . V_27 ++ ;
V_22 = V_28 ;
F_17 ( V_4 , V_24 ) ;
}
} else
V_22 = V_29 ;
if ( V_21 & V_30 )
continue;
V_12 = F_18 ( V_4 ) ;
V_4 -> V_2 . V_14 . V_31 ++ ;
if ( ! ( F_19 ( & V_4 -> V_2 , V_12 ) ) )
F_20 ( & V_4 -> V_2 , V_21 , V_23 , V_12 , V_22 ) ;
F_21 ( & V_4 -> V_2 . V_32 ) ;
F_22 ( & V_4 -> V_2 . V_10 -> V_2 ) ;
F_23 ( & V_4 -> V_2 . V_32 ) ;
} while ( ! ( ( V_21 = F_5 ( V_4 ) ) & V_30 ) );
}
static T_1 F_24 ( int V_33 , void * V_34 )
{
struct V_3 * V_4 = V_34 ;
unsigned int V_21 ;
V_21 = F_5 ( V_4 ) ;
if ( V_21 & V_35 ) {
F_23 ( & V_4 -> V_2 . V_32 ) ;
F_16 ( V_4 , V_21 ) ;
F_21 ( & V_4 -> V_2 . V_32 ) ;
}
if ( ( V_21 & V_36 ) && ( V_21 & V_5 ) ) {
F_7 ( V_4 ) ;
F_23 ( & V_4 -> V_2 . V_32 ) ;
if ( ! F_25 ( & V_4 -> V_2 ) )
F_9 ( V_4 ) ;
F_21 ( & V_4 -> V_2 . V_32 ) ;
}
return V_37 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_38 | V_39 | V_40 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_41 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 , int V_42 )
{
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_4 ) ;
if ( F_32 ( V_4 -> V_2 . V_33 , F_24 , 0 , L_1 ,
V_4 ) ) {
F_33 ( V_4 -> V_2 . V_43 , L_2 ) ;
return - V_44 ;
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
F_37 ( struct V_1 * V_2 , struct V_45 * V_46 ,
struct V_45 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_48 , V_49 , V_50 , V_51 ;
unsigned long V_52 ;
V_48 = F_38 ( V_2 , V_46 , V_47 , 0 , 460800 ) ;
V_51 = V_2 -> V_53 / ( V_4 -> V_48 * 4 ) - 1 ;
V_49 = V_51 & 0xFF ;
V_50 = ( V_51 >> 8 ) & 0xFF ;
if ( V_4 -> V_54 )
V_50 = 1 ;
F_39 ( & V_2 -> V_32 , V_52 ) ;
F_31 ( V_4 ) ;
F_40 ( V_4 , V_49 ) ;
F_41 ( V_4 , V_50 ) ;
F_34 ( V_4 ) ;
V_46 -> V_55 &= ~ ( V_56 | V_57 | V_58 ) ;
V_46 -> V_55 |= V_59 ;
if ( V_47 )
F_42 ( V_46 , V_47 ) ;
if ( F_43 ( V_46 ) )
F_44 ( V_46 , V_48 , V_48 ) ;
F_45 ( V_2 , V_46 -> V_55 , V_48 ) ;
F_46 ( & V_2 -> V_32 , V_52 ) ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_2 . type == V_60 ? V_61 : NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
if ( V_2 -> type != V_64 && V_63 -> type != V_60 )
return - V_65 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , int V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_52 & V_66 )
V_4 -> V_2 . type = V_60 ;
}
static void F_52 ( struct V_1 * V_2 , unsigned char V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ! ( F_5 ( V_4 ) & V_5 ) )
F_6 () ;
F_11 ( V_4 , V_67 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_67 ;
while ( ! ( F_5 ( V_4 ) & V_30 ) )
F_6 () ;
V_67 = F_18 ( V_4 ) ;
return V_67 ;
}
static int
F_54 ( struct V_68 * V_69 , int V_34 )
{
struct V_70 * V_71 , * V_72 ;
unsigned long * V_73 ;
struct V_3 * V_4 = & V_74 [ V_34 ] ;
V_73 = F_55 ( & V_69 -> V_43 ) ;
if ( ! V_73 )
return - V_75 ;
V_4 -> V_54 = ! ! V_73 [ 0 ] ;
if ( F_56 ( V_69 ) ) {
V_4 -> V_2 . V_53 = V_73 [ 1 ] ;
V_4 -> V_48 = V_73 [ 2 ] ;
} else {
struct V_76 * V_77 = V_69 -> V_43 . V_78 ;
T_2 V_79 ;
if ( F_57 ( V_77 , L_3 , & V_79 ) ) {
F_58 ( & V_69 -> V_43 , L_4 ) ;
return - V_65 ;
}
V_4 -> V_2 . V_53 = V_79 ;
if ( F_57 ( V_77 , L_5 , & V_79 ) ) {
F_58 ( & V_69 -> V_43 , L_6 ) ;
return - V_65 ;
}
V_4 -> V_48 = V_79 ;
}
V_71 = F_59 ( V_69 , V_80 , 0 ) ;
if ( ! V_71 )
return - V_75 ;
V_72 = F_59 ( V_69 , V_81 , 0 ) ;
if ( ! V_72 )
return - V_75 ;
V_4 -> V_2 . V_82 = V_71 -> V_83 ;
V_4 -> V_2 . V_84 = F_60 ( V_71 -> V_83 , F_61 ( V_71 ) ) ;
if ( ! V_4 -> V_2 . V_84 )
return - V_85 ;
V_4 -> V_2 . V_33 = V_72 -> V_83 ;
V_4 -> V_2 . V_43 = & V_69 -> V_43 ;
V_4 -> V_2 . V_86 = V_87 ;
V_4 -> V_2 . V_52 = V_88 ;
V_4 -> V_2 . line = V_34 ;
V_4 -> V_2 . V_89 = & V_90 ;
V_4 -> V_2 . V_91 = V_92 ;
V_4 -> V_2 . V_93 = 0 ;
return 0 ;
}
static int F_62 ( struct V_94 * V_95 , char * V_96 )
{
struct V_1 * V_2 ;
int V_48 = 115200 ;
int V_97 = 8 ;
int V_98 = 'n' ;
int V_99 = 'n' ;
if ( V_95 -> V_100 < 0 || V_95 -> V_100 >= V_101 )
return - V_75 ;
V_2 = & V_74 [ V_95 -> V_100 ] . V_2 ;
if ( ! V_2 -> V_84 )
return - V_75 ;
if ( V_96 )
F_63 ( V_96 , & V_48 , & V_98 , & V_97 , & V_99 ) ;
return F_64 ( V_2 , V_95 , V_48 , V_98 , V_97 , V_99 ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_12 )
{
F_52 ( V_2 , ( unsigned char ) V_12 ) ;
}
static void F_66 ( struct V_94 * V_95 , const char * V_102 ,
unsigned int V_103 )
{
struct V_1 * V_2 = & V_74 [ V_95 -> V_100 ] . V_2 ;
unsigned long V_52 ;
F_39 ( & V_2 -> V_32 , V_52 ) ;
F_67 ( V_2 , V_102 , V_103 , F_65 ) ;
F_46 ( & V_2 -> V_32 , V_52 ) ;
}
static T_3 void F_68 ( struct V_94 * V_104 , const char * V_102 ,
unsigned int V_105 )
{
struct V_1 * V_2 = & V_74 [ V_104 -> V_100 ] . V_2 ;
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ , V_102 ++ ) {
if ( * V_102 == '\n' )
F_52 ( V_2 , '\r' ) ;
F_52 ( V_2 , * V_102 ) ;
}
}
static int T_3 F_69 ( struct V_68 * V_69 )
{
int V_34 = V_69 -> V_107 < 0 ? 0 : V_69 -> V_107 ;
int V_108 ;
V_109 . V_100 = V_34 ;
V_108 = F_54 ( V_69 , V_34 ) ;
if ( V_108 )
F_70 ( L_7 ) ;
F_62 ( & V_109 , NULL ) ;
F_71 ( & V_109 ) ;
return 0 ;
}
static int F_72 ( struct V_68 * V_69 )
{
int V_108 , V_34 ;
struct V_76 * V_77 = V_69 -> V_43 . V_78 ;
if ( ! V_77 )
return - V_75 ;
V_34 = F_73 ( V_77 , L_8 ) ;
if ( V_34 < 0 )
V_34 = 0 ;
V_108 = F_54 ( V_69 , V_34 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_74 ( & V_110 , & V_74 [ V_34 ] . V_2 ) ;
return V_108 ;
}
static int F_75 ( struct V_68 * V_69 )
{
return 0 ;
}
static int T_3 F_76 ( void )
{
int V_111 ;
V_111 = F_77 ( & V_110 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_78 ( & V_112 ) ;
if ( V_111 )
F_79 ( & V_110 ) ;
return V_111 ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_112 ) ;
F_79 ( & V_110 ) ;
}
