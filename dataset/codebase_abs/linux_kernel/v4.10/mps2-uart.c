static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , T_1 V_4 , unsigned int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_4 ( V_4 , V_6 -> V_3 . V_7 + V_5 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 , unsigned int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_6 ( V_6 -> V_3 . V_7 + V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 , T_2 V_4 , unsigned int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_8 ( V_4 , V_6 -> V_3 . V_7 + V_5 ) ;
}
static unsigned int F_9 ( struct V_2 * V_3 )
{
T_1 V_8 = F_5 ( V_3 , V_9 ) ;
return ( V_8 & V_10 ) ? 0 : V_11 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned int V_12 )
{
}
static unsigned int F_11 ( struct V_2 * V_3 )
{
return V_13 | V_14 | V_15 ;
}
static void F_12 ( struct V_2 * V_3 )
{
T_1 V_16 = F_5 ( V_3 , V_17 ) ;
V_16 &= ~ V_18 ;
F_3 ( V_3 , V_16 , V_17 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = & V_3 -> V_21 -> V_20 ;
while ( ! ( F_5 ( V_3 , V_9 ) & V_10 ) ) {
if ( V_3 -> V_22 ) {
F_3 ( V_3 , V_3 -> V_22 , V_23 ) ;
V_3 -> V_22 = 0 ;
V_3 -> V_24 . V_25 ++ ;
continue;
}
if ( F_14 ( V_20 ) || F_15 ( V_3 ) )
break;
F_3 ( V_3 , V_20 -> V_26 [ V_20 -> V_27 ] , V_23 ) ;
V_20 -> V_27 = ( V_20 -> V_27 + 1 ) % V_28 ;
V_3 -> V_24 . V_25 ++ ;
}
if ( F_16 ( V_20 ) < V_29 )
F_17 ( V_3 ) ;
if ( F_14 ( V_20 ) )
F_12 ( V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
T_1 V_16 = F_5 ( V_3 , V_17 ) ;
V_16 |= V_18 ;
F_3 ( V_3 , V_16 , V_17 ) ;
F_13 ( V_3 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
T_1 V_16 = F_5 ( V_3 , V_17 ) ;
V_16 &= ~ V_30 ;
F_3 ( V_3 , V_16 , V_17 ) ;
}
static void F_20 ( struct V_2 * V_3 , int V_31 )
{
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_32 * V_33 = & V_3 -> V_21 -> V_3 ;
while ( F_5 ( V_3 , V_9 ) & V_34 ) {
T_1 V_35 = F_5 ( V_3 , V_23 ) ;
V_3 -> V_24 . V_36 ++ ;
F_22 ( & V_3 -> V_21 -> V_3 , V_35 , V_37 ) ;
}
F_23 ( V_33 ) ;
}
static T_3 F_24 ( int V_38 , void * V_39 )
{
struct V_2 * V_3 = V_39 ;
T_1 V_40 = F_5 ( V_3 , V_41 ) ;
if ( F_25 ( ! ( V_40 & V_42 ) ) )
return V_43 ;
F_26 ( & V_3 -> V_44 ) ;
F_3 ( V_3 , V_42 , V_41 ) ;
F_21 ( V_3 ) ;
F_27 ( & V_3 -> V_44 ) ;
return V_45 ;
}
static T_3 F_28 ( int V_38 , void * V_39 )
{
struct V_2 * V_3 = V_39 ;
T_1 V_40 = F_5 ( V_3 , V_41 ) ;
if ( F_25 ( ! ( V_40 & V_46 ) ) )
return V_43 ;
F_26 ( & V_3 -> V_44 ) ;
F_3 ( V_3 , V_46 , V_41 ) ;
F_13 ( V_3 ) ;
F_27 ( & V_3 -> V_44 ) ;
return V_45 ;
}
static T_3 F_29 ( int V_38 , void * V_39 )
{
T_3 V_47 = V_43 ;
struct V_2 * V_3 = V_39 ;
T_1 V_40 = F_5 ( V_3 , V_41 ) ;
F_26 ( & V_3 -> V_44 ) ;
if ( V_40 & V_48 ) {
struct V_32 * V_33 = & V_3 -> V_21 -> V_3 ;
F_3 ( V_3 , V_48 , V_41 ) ;
V_3 -> V_24 . V_49 ++ ;
F_22 ( V_33 , 0 , V_50 ) ;
F_23 ( V_33 ) ;
V_47 = V_45 ;
}
if ( V_40 & V_51 ) {
F_3 ( V_3 , V_51 , V_41 ) ;
V_47 = V_45 ;
}
F_27 ( & V_3 -> V_44 ) ;
return V_47 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_16 = F_5 ( V_3 , V_17 ) ;
int V_52 ;
V_16 &= ~ ( V_30 | V_53 ) ;
F_3 ( V_3 , V_16 , V_17 ) ;
V_52 = F_31 ( V_6 -> V_54 , F_24 , 0 ,
F_32 ( - V_36 ) , V_6 ) ;
if ( V_52 ) {
F_33 ( V_3 -> V_55 , L_1 , V_52 ) ;
return V_52 ;
}
V_52 = F_31 ( V_6 -> V_56 , F_28 , 0 ,
F_32 ( - V_25 ) , V_6 ) ;
if ( V_52 ) {
F_33 ( V_3 -> V_55 , L_2 , V_52 ) ;
goto V_57;
}
V_52 = F_31 ( V_3 -> V_38 , F_29 , V_58 ,
F_32 ( - V_49 ) , V_6 ) ;
if ( V_52 ) {
F_33 ( V_3 -> V_55 , L_3 , V_52 ) ;
goto V_59;
}
V_16 |= V_30 | V_53 ;
F_3 ( V_3 , V_16 , V_17 ) ;
return 0 ;
V_59:
F_34 ( V_6 -> V_56 , V_6 ) ;
V_57:
F_34 ( V_6 -> V_54 , V_6 ) ;
return V_52 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_16 = F_5 ( V_3 , V_17 ) ;
V_16 &= ~ ( V_30 | V_53 ) ;
F_3 ( V_3 , V_16 , V_17 ) ;
F_34 ( V_6 -> V_54 , V_6 ) ;
F_34 ( V_6 -> V_56 , V_6 ) ;
F_34 ( V_3 -> V_38 , V_6 ) ;
}
static void
F_36 ( struct V_2 * V_3 , struct V_60 * V_61 ,
struct V_60 * V_62 )
{
unsigned long V_63 ;
unsigned int V_64 , V_65 ;
V_61 -> V_66 &= ~ ( V_67 | V_68 ) ;
V_61 -> V_66 &= ~ V_69 ;
V_61 -> V_66 |= V_70 ;
V_61 -> V_66 &= ~ V_71 ;
V_61 -> V_66 &= ~ V_72 ;
V_64 = F_37 ( V_3 , V_61 , V_62 ,
F_38 ( V_3 -> V_73 , V_74 ) ,
F_38 ( V_3 -> V_73 , 16 ) ) ;
V_65 = F_38 ( V_3 -> V_73 , V_64 ) ;
F_39 ( & V_3 -> V_44 , V_63 ) ;
F_40 ( V_3 , V_61 -> V_66 , V_64 ) ;
F_7 ( V_3 , V_65 , V_75 ) ;
F_41 ( & V_3 -> V_44 , V_63 ) ;
if ( F_42 ( V_61 ) )
F_43 ( V_61 , V_64 , V_64 ) ;
}
static const char * F_44 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_76 ) ? V_77 : NULL ;
}
static void F_45 ( struct V_2 * V_3 )
{
}
static int F_46 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_47 ( struct V_2 * V_3 , int type )
{
if ( type & V_78 && ! F_46 ( V_3 ) )
V_3 -> type = V_76 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_79 * V_80 )
{
return - V_81 ;
}
static void F_49 ( struct V_2 * V_3 , int V_82 )
{
while ( F_5 ( V_3 , V_9 ) & V_10 )
F_50 () ;
F_3 ( V_3 , V_82 , V_23 ) ;
}
static void F_51 ( struct V_83 * V_84 , const char * V_85 , unsigned int V_86 )
{
struct V_2 * V_3 = & V_87 [ V_84 -> V_88 ] . V_3 ;
F_52 ( V_3 , V_85 , V_86 , F_49 ) ;
}
static int F_53 ( struct V_83 * V_84 , char * V_89 )
{
struct V_1 * V_6 ;
int V_64 = 9600 ;
int V_90 = 8 ;
int V_91 = 'n' ;
int V_92 = 'n' ;
if ( V_84 -> V_88 < 0 || V_84 -> V_88 >= V_93 )
return - V_94 ;
V_6 = & V_87 [ V_84 -> V_88 ] ;
if ( V_89 )
F_54 ( V_89 , & V_64 , & V_91 , & V_90 , & V_92 ) ;
return F_55 ( & V_6 -> V_3 , V_84 , V_64 , V_91 , V_90 , V_92 ) ;
}
static void F_56 ( struct V_2 * V_3 , int V_82 )
{
while ( F_6 ( V_3 -> V_7 + V_9 ) & V_10 )
F_50 () ;
F_4 ( ( unsigned char ) V_82 , V_3 -> V_7 + V_23 ) ;
}
static void F_57 ( struct V_83 * V_95 , const char * V_85 , unsigned int V_96 )
{
struct V_97 * V_55 = V_95 -> V_39 ;
F_52 ( & V_55 -> V_3 , V_85 , V_96 , F_56 ) ;
}
static int T_4 F_58 ( struct V_97 * V_98 ,
const char * V_99 )
{
if ( ! V_98 -> V_3 . V_7 )
return - V_94 ;
V_98 -> V_95 -> V_100 = F_57 ;
return 0 ;
}
static struct V_1 * F_59 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = V_102 -> V_55 . V_105 ;
int V_106 ;
if ( ! V_104 )
return NULL ;
V_106 = F_60 ( V_104 , L_4 ) ;
if ( V_106 < 0 )
V_106 = 0 ;
if ( F_61 ( V_106 >= V_93 ) )
return NULL ;
V_87 [ V_106 ] . V_3 . line = V_106 ;
return & V_87 [ V_106 ] ;
}
static int F_62 ( struct V_1 * V_6 ,
struct V_101 * V_102 )
{
struct V_107 * V_108 ;
int V_52 ;
V_108 = F_63 ( V_102 , V_109 , 0 ) ;
V_6 -> V_3 . V_7 = F_64 ( & V_102 -> V_55 , V_108 ) ;
if ( F_65 ( V_6 -> V_3 . V_7 ) )
return F_66 ( V_6 -> V_3 . V_7 ) ;
V_6 -> V_3 . V_110 = V_108 -> V_111 ;
V_6 -> V_3 . V_112 = F_67 ( V_108 ) ;
V_6 -> V_54 = F_68 ( V_102 , 0 ) ;
V_6 -> V_56 = F_68 ( V_102 , 1 ) ;
V_6 -> V_3 . V_38 = F_68 ( V_102 , 2 ) ;
V_6 -> V_3 . V_113 = V_114 ;
V_6 -> V_3 . V_63 = V_115 ;
V_6 -> V_3 . V_116 = 1 ;
V_6 -> V_3 . V_117 = & V_118 ;
V_6 -> V_3 . V_55 = & V_102 -> V_55 ;
V_6 -> V_119 = F_69 ( & V_102 -> V_55 , NULL ) ;
if ( F_65 ( V_6 -> V_119 ) )
return F_66 ( V_6 -> V_119 ) ;
V_52 = F_70 ( V_6 -> V_119 ) ;
if ( V_52 )
return V_52 ;
V_6 -> V_3 . V_73 = F_71 ( V_6 -> V_119 ) ;
F_72 ( V_6 -> V_119 ) ;
return V_52 ;
}
static int F_73 ( struct V_101 * V_102 )
{
struct V_1 * V_6 ;
int V_52 ;
V_6 = F_59 ( V_102 ) ;
if ( ! V_6 )
return - V_94 ;
V_52 = F_62 ( V_6 , V_102 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_74 ( & V_120 , & V_6 -> V_3 ) ;
if ( V_52 )
return V_52 ;
F_75 ( V_102 , V_6 ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
int V_52 ;
V_52 = F_77 ( & V_120 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_78 ( & V_121 ) ;
if ( V_52 )
F_79 ( & V_120 ) ;
return V_52 ;
}
