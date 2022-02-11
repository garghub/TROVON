static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
while ( ! ( F_4 ( V_2 ) & V_3 ) )
F_5 () ;
F_6 ( V_2 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
V_4 = F_4 ( V_2 ) ;
if ( V_4 & V_3 )
return V_5 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 -> V_7 ;
int V_9 = 0 ;
unsigned char V_10 ;
if ( F_9 ( V_2 -> V_11 ) ) {
F_10 ( V_2 , V_2 -> V_11 ) ;
V_2 -> V_12 . V_13 ++ ;
V_2 -> V_11 = 0 ;
V_9 = 1 ;
} else if ( ! F_11 ( V_7 ) ) {
V_10 = V_7 -> V_14 [ V_7 -> V_15 ] ;
V_7 -> V_15 = ( V_7 -> V_15 + 1 ) & ( V_16 - 1 ) ;
V_2 -> V_12 . V_13 ++ ;
while ( ! ( F_4 ( V_2 ) & V_3 ) )
F_5 () ;
F_10 ( V_2 , V_10 ) ;
V_9 = 1 ;
}
if ( F_12 ( V_7 ) < V_17 )
F_13 ( V_2 ) ;
if ( V_9 )
F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_18 )
{
unsigned int V_10 , V_19 = 0 ;
do {
if ( F_9 ( V_18 & ( V_20 | V_21 ) ) ) {
if ( V_18 & V_20 ) {
V_2 -> V_12 . V_22 ++ ;
V_19 = V_23 ;
F_17 ( V_2 , V_20 ) ;
}
if ( V_18 & V_21 ) {
V_2 -> V_12 . V_24 ++ ;
V_19 = V_25 ;
F_17 ( V_2 , V_21 ) ;
}
} else
V_19 = V_26 ;
if ( V_18 & V_27 )
continue;
V_10 = F_18 ( V_2 ) ;
V_2 -> V_12 . V_28 ++ ;
if ( ! ( F_19 ( V_2 , V_10 ) ) )
F_20 ( V_2 , V_18 , V_20 , V_10 , V_19 ) ;
F_21 ( & V_2 -> V_29 ) ;
F_22 ( & V_2 -> V_8 -> V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
} while ( ! ( ( V_18 = F_4 ( V_2 ) ) & V_27 ) );
}
static T_1 F_24 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
unsigned int V_18 ;
V_18 = F_4 ( V_2 ) ;
if ( V_18 & V_32 ) {
F_23 ( & V_2 -> V_29 ) ;
F_16 ( V_2 , V_18 ) ;
F_21 ( & V_2 -> V_29 ) ;
}
if ( ( V_18 & V_33 ) && ( V_18 & V_3 ) ) {
F_6 ( V_2 ) ;
F_23 ( & V_2 -> V_29 ) ;
if ( ! F_25 ( V_2 ) )
F_8 ( V_2 ) ;
F_21 ( & V_2 -> V_29 ) ;
}
return V_34 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_35 | V_36 | V_37 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_38 )
{
}
static void F_28 ( struct V_1 * V_2 , int V_39 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
if ( F_31 ( V_2 -> V_30 , F_24 , 0 , L_1 , V_2 ) ) {
F_32 ( V_2 -> V_40 , L_2 ) ;
return - V_41 ;
}
F_33 ( V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_30 , V_2 ) ;
}
static void
F_36 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_42 * V_44 )
{
struct V_45 * V_46 = F_37 ( V_2 ) ;
unsigned int V_47 , V_48 , V_49 , V_50 ;
unsigned long V_51 ;
V_47 = F_38 ( V_2 , V_43 , V_44 , 0 , 460800 ) ;
V_50 = V_2 -> V_52 / ( V_46 -> V_47 * 4 ) - 1 ;
V_48 = V_50 & 0xFF ;
V_49 = ( V_50 >> 8 ) & 0xFF ;
F_39 ( & V_2 -> V_29 , V_51 ) ;
F_30 ( V_2 ) ;
F_40 ( V_2 , V_48 ) ;
F_41 ( V_2 , V_49 ) ;
F_33 ( V_2 ) ;
V_43 -> V_53 &= ~ ( V_54 | V_55 | V_56 ) ;
V_43 -> V_53 |= V_57 ;
if ( V_44 )
F_42 ( V_43 , V_44 ) ;
if ( F_43 ( V_43 ) )
F_44 ( V_43 , V_47 , V_47 ) ;
F_45 ( V_2 , V_43 -> V_53 , V_47 ) ;
F_46 ( & V_2 -> V_29 , V_51 ) ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
return V_2 -> type == V_58 ? V_59 : NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
if ( V_2 -> type != V_62 && V_61 -> type != V_58 )
return - V_63 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 & V_64 )
V_2 -> type = V_58 ;
}
static void F_52 ( struct V_1 * V_2 , unsigned char V_65 )
{
while ( ! ( F_4 ( V_2 ) & V_3 ) )
F_5 () ;
F_10 ( V_2 , V_65 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned char V_65 ;
while ( ! ( F_4 ( V_2 ) & V_27 ) )
F_5 () ;
V_65 = F_18 ( V_2 ) ;
return V_65 ;
}
static int F_54 ( struct V_66 * V_67 , char * V_68 )
{
struct V_1 * V_2 ;
int V_47 = 115200 ;
int V_69 = 8 ;
int V_70 = 'n' ;
int V_71 = 'n' ;
if ( V_67 -> V_72 < 0 || V_67 -> V_72 >= V_73 )
return - V_74 ;
V_2 = & V_75 [ V_67 -> V_72 ] . V_2 ;
if ( ! V_2 -> V_76 )
return - V_74 ;
if ( V_68 )
F_55 ( V_68 , & V_47 , & V_70 , & V_69 , & V_71 ) ;
return F_56 ( V_2 , V_67 , V_47 , V_70 , V_69 , V_71 ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_10 )
{
while ( ! ( F_4 ( V_2 ) & V_3 ) )
F_5 () ;
F_10 ( V_2 , ( unsigned char ) V_10 ) ;
}
static void F_58 ( struct V_66 * V_67 , const char * V_77 ,
unsigned int V_78 )
{
struct V_1 * V_2 = & V_75 [ V_67 -> V_72 ] . V_2 ;
unsigned long V_51 ;
F_39 ( & V_2 -> V_29 , V_51 ) ;
F_59 ( V_2 , V_77 , V_78 , F_57 ) ;
F_46 ( & V_2 -> V_29 , V_51 ) ;
}
static void F_60 ( struct V_66 * V_79 , const char * V_77 ,
unsigned int V_80 )
{
struct V_81 * V_40 = V_79 -> V_82 ;
F_59 ( & V_40 -> V_2 , V_77 , V_80 , F_57 ) ;
}
static int T_2 F_61 ( struct V_81 * V_40 ,
const char * V_83 )
{
struct V_1 * V_2 = & V_40 -> V_2 ;
unsigned int V_84 , V_85 , V_50 ;
if ( ! V_40 -> V_2 . V_76 )
return - V_74 ;
V_50 = V_2 -> V_52 / ( V_40 -> V_47 * 4 ) - 1 ;
V_84 = V_50 & 0xFF ;
V_85 = ( V_50 >> 8 ) & 0xFF ;
F_40 ( V_2 , V_84 ) ;
F_41 ( V_2 , V_85 ) ;
V_40 -> V_79 -> V_86 = F_60 ;
return 0 ;
}
static int F_62 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = V_88 -> V_40 . V_91 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
int V_31 ;
T_3 V_92 ;
if ( ! V_90 )
return - V_74 ;
V_31 = F_63 ( V_90 , L_3 ) ;
if ( V_31 < 0 )
V_31 = 0 ;
V_46 = & V_75 [ V_31 ] ;
V_2 = & V_46 -> V_2 ;
if ( F_64 ( V_90 , L_4 , & V_92 ) ) {
F_65 ( & V_88 -> V_40 , L_5 ) ;
return - V_63 ;
}
V_2 -> V_52 = V_92 ;
if ( F_64 ( V_90 , L_6 , & V_92 ) ) {
F_65 ( & V_88 -> V_40 , L_7 ) ;
return - V_63 ;
}
V_46 -> V_47 = V_92 ;
V_2 -> V_76 = F_66 ( V_90 , 0 ) ;
if ( ! V_2 -> V_76 )
return - V_93 ;
V_2 -> V_30 = F_67 ( V_90 , 0 ) ;
V_2 -> V_40 = & V_88 -> V_40 ;
V_2 -> V_94 = V_95 ;
V_2 -> V_51 = V_96 ;
V_2 -> line = V_31 ;
V_2 -> V_97 = & V_98 ;
V_2 -> V_99 = V_100 ;
V_2 -> V_101 = 0 ;
return F_68 ( & V_102 , & V_75 [ V_31 ] . V_2 ) ;
}
static int F_69 ( struct V_87 * V_88 )
{
return 0 ;
}
static int T_2 F_70 ( void )
{
int V_103 ;
V_103 = F_71 ( & V_102 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_72 ( & V_104 ) ;
if ( V_103 )
F_73 ( & V_102 ) ;
return V_103 ;
}
static void T_4 F_74 ( void )
{
F_75 ( & V_104 ) ;
F_73 ( & V_102 ) ;
}
