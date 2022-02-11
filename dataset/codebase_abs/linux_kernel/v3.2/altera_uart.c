static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << V_2 -> V_5 ) ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 , int V_3 )
{
F_4 ( V_6 , V_2 -> V_4 + ( V_3 << V_2 -> V_5 ) ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , V_7 ) &
V_8 ) ? V_9 : 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned int V_12 ;
V_12 = ( F_1 ( V_2 , V_7 ) &
V_13 ) ? V_14 : 0 ;
V_12 |= ( V_11 -> V_12 & V_15 ) ;
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_12 = V_12 ;
if ( V_12 & V_15 )
V_11 -> V_16 |= V_17 ;
else
V_11 -> V_16 &= ~ V_17 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_16 |= V_19 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_16 &= ~ V_19 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_16 &= ~ V_20 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_21 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned long V_22 ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
if ( V_21 == - 1 )
V_11 -> V_16 |= V_24 ;
else
V_11 -> V_16 &= ~ V_24 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
}
static void F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_25 * V_27 )
{
unsigned long V_22 ;
unsigned int V_28 , V_29 ;
V_28 = F_17 ( V_2 , V_26 , V_27 , 0 , 4000000 ) ;
V_29 = V_2 -> V_30 / V_28 ;
if ( V_27 )
F_18 ( V_26 , V_27 ) ;
F_19 ( V_26 , V_28 , V_28 ) ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
F_20 ( V_2 , V_26 -> V_31 , V_28 ) ;
F_3 ( V_2 , V_29 , V_32 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_2 ;
unsigned char V_33 , V_34 ;
unsigned short V_35 ;
while ( ( V_35 = F_1 ( V_2 , V_7 ) ) &
V_36 ) {
V_33 = F_1 ( V_2 , V_37 ) ;
V_34 = V_38 ;
V_2 -> V_39 . V_40 ++ ;
if ( V_35 & V_41 ) {
F_3 ( V_2 , V_35 ,
V_7 ) ;
if ( V_35 & V_42 ) {
V_2 -> V_39 . V_43 ++ ;
if ( F_22 ( V_2 ) )
continue;
} else if ( V_35 & V_44 ) {
V_2 -> V_39 . V_45 ++ ;
} else if ( V_35 & V_46 ) {
V_2 -> V_39 . V_47 ++ ;
} else if ( V_35 & V_48 ) {
V_2 -> V_39 . V_49 ++ ;
}
V_35 &= V_2 -> V_50 ;
if ( V_35 & V_42 )
V_34 = V_51 ;
else if ( V_35 & V_44 )
V_34 = V_52 ;
else if ( V_35 & V_48 )
V_34 = V_53 ;
}
if ( F_23 ( V_2 , V_33 ) )
continue;
F_24 ( V_2 , V_35 , V_46 , V_33 ,
V_34 ) ;
}
F_25 ( V_2 -> V_54 -> V_2 . V_55 ) ;
}
static void F_26 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_56 * V_57 = & V_2 -> V_54 -> V_57 ;
if ( V_2 -> V_58 ) {
F_3 ( V_2 , V_2 -> V_58 , V_59 ) ;
V_2 -> V_58 = 0 ;
V_2 -> V_39 . V_60 ++ ;
return;
}
while ( F_1 ( V_2 , V_7 ) &
V_61 ) {
if ( V_57 -> V_62 == V_57 -> V_63 )
break;
F_3 ( V_2 , V_57 -> V_64 [ V_57 -> V_63 ] ,
V_59 ) ;
V_57 -> V_63 = ( V_57 -> V_63 + 1 ) & ( V_65 - 1 ) ;
V_2 -> V_39 . V_60 ++ ;
}
if ( F_27 ( V_57 ) < V_66 )
F_28 ( V_2 ) ;
if ( V_57 -> V_62 == V_57 -> V_63 ) {
V_11 -> V_16 &= ~ V_19 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
}
static T_2 F_29 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned int V_69 ;
V_69 = F_1 ( V_2 , V_7 ) & V_11 -> V_16 ;
F_30 ( & V_2 -> V_23 ) ;
if ( V_69 & V_36 )
F_21 ( V_11 ) ;
if ( V_69 & V_61 )
F_26 ( V_11 ) ;
F_31 ( & V_2 -> V_23 ) ;
return F_32 ( V_69 ) ;
}
static void F_33 ( unsigned long V_68 )
{
struct V_1 * V_2 = ( void * ) V_68 ;
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
F_29 ( 0 , V_2 ) ;
F_34 ( & V_11 -> V_70 , V_71 + F_35 ( V_2 ) ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_22 )
{
V_2 -> type = V_72 ;
F_3 ( V_2 , 0 , V_18 ) ;
F_3 ( V_2 , 0 , V_7 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned long V_22 ;
int V_73 ;
if ( ! V_2 -> V_67 ) {
F_38 ( & V_11 -> V_70 , F_33 , ( unsigned long ) V_2 ) ;
F_34 ( & V_11 -> V_70 , V_71 + F_35 ( V_2 ) ) ;
return 0 ;
}
V_73 = F_39 ( V_2 -> V_67 , F_29 , 0 ,
V_74 , V_2 ) ;
if ( V_73 ) {
F_40 ( V_74 L_1
L_2 , V_2 -> line , V_2 -> V_67 ) ;
return V_73 ;
}
F_13 ( & V_2 -> V_23 , V_22 ) ;
V_11 -> V_16 = V_20 ;
F_4 ( V_11 -> V_16 , V_2 -> V_4 + V_18 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned long V_22 ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
V_11 -> V_16 = 0 ;
F_4 ( V_11 -> V_16 , V_2 -> V_4 + V_18 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_67 )
F_42 ( V_2 -> V_67 , V_2 ) ;
else
F_43 ( & V_11 -> V_70 ) ;
}
static const char * F_44 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_72 ) ? L_3 : NULL ;
}
static int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
}
static int F_47 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
if ( ( V_76 -> type != V_77 ) && ( V_76 -> type != V_72 ) )
return - V_78 ;
return 0 ;
}
int T_3 F_48 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_82 && V_80 [ V_81 ] . V_83 ; V_81 ++ ) {
V_2 = & V_84 [ V_81 ] . V_2 ;
V_2 -> line = V_81 ;
V_2 -> type = V_72 ;
V_2 -> V_83 = V_80 [ V_81 ] . V_83 ;
V_2 -> V_4 = F_49 ( V_2 -> V_83 , V_85 ) ;
V_2 -> V_86 = V_87 ;
V_2 -> V_67 = V_80 [ V_81 ] . V_67 ;
V_2 -> V_30 = V_80 [ V_81 ] . V_30 ;
V_2 -> V_22 = V_88 ;
V_2 -> V_89 = & V_90 ;
V_2 -> V_91 = V_80 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , const char V_92 )
{
while ( ! ( F_1 ( V_2 , V_7 ) &
V_61 ) )
F_51 () ;
F_4 ( V_92 , V_2 -> V_4 + V_59 ) ;
}
static void F_52 ( struct V_93 * V_94 , const char * V_95 ,
unsigned int V_96 )
{
struct V_1 * V_2 = & ( V_84 + V_94 -> V_97 ) -> V_2 ;
for (; V_96 ; V_96 -- , V_95 ++ ) {
F_50 ( V_2 , * V_95 ) ;
if ( * V_95 == '\n' )
F_50 ( V_2 , '\r' ) ;
}
}
static int T_3 F_53 ( struct V_93 * V_94 , char * V_98 )
{
struct V_1 * V_2 ;
int V_28 = V_99 ;
int V_100 = 8 ;
int V_45 = 'n' ;
int V_101 = 'n' ;
if ( V_94 -> V_97 < 0 || V_94 -> V_97 >= V_82 )
return - V_78 ;
V_2 = & V_84 [ V_94 -> V_97 ] . V_2 ;
if ( ! V_2 -> V_4 )
return - V_102 ;
if ( V_98 )
F_54 ( V_98 , & V_28 , & V_45 , & V_100 , & V_101 ) ;
return F_55 ( V_2 , V_94 , V_28 , V_45 , V_100 , V_101 ) ;
}
static int T_3 F_56 ( void )
{
F_57 ( & V_103 ) ;
return 0 ;
}
static int F_58 ( struct V_104 * V_105 ,
struct V_1 * V_2 )
{
int V_106 ;
const T_4 * V_107 ;
V_107 = F_59 ( V_105 -> V_108 . V_109 , L_4 , & V_106 ) ;
if ( ! V_107 || V_106 < sizeof( T_4 ) )
return - V_102 ;
V_2 -> V_30 = F_60 ( V_107 ) ;
return 0 ;
}
static int F_58 ( struct V_104 * V_105 ,
struct V_1 * V_2 )
{
return - V_102 ;
}
static int T_5 F_61 ( struct V_104 * V_105 )
{
struct V_79 * V_80 = V_105 -> V_108 . V_110 ;
struct V_1 * V_2 ;
struct V_111 * V_112 ;
struct V_111 * V_113 ;
int V_81 = V_105 -> V_114 ;
int V_73 ;
if ( V_81 == - 1 ) {
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
if ( V_84 [ V_81 ] . V_2 . V_83 == 0 )
break;
}
if ( V_81 < 0 || V_81 >= V_82 )
return - V_78 ;
V_2 = & V_84 [ V_81 ] . V_2 ;
V_112 = F_62 ( V_105 , V_115 , 0 ) ;
if ( V_112 )
V_2 -> V_83 = V_112 -> V_116 ;
else if ( V_80 -> V_83 )
V_2 -> V_83 = V_80 -> V_83 ;
else
return - V_78 ;
V_113 = F_62 ( V_105 , V_117 , 0 ) ;
if ( V_113 )
V_2 -> V_67 = V_113 -> V_116 ;
else if ( V_80 -> V_67 )
V_2 -> V_67 = V_80 -> V_67 ;
if ( V_80 )
V_2 -> V_30 = V_80 -> V_30 ;
else {
V_73 = F_58 ( V_105 , V_2 ) ;
if ( V_73 )
return V_73 ;
}
V_2 -> V_4 = F_49 ( V_2 -> V_83 , V_85 ) ;
if ( ! V_2 -> V_4 )
return - V_118 ;
if ( V_80 )
V_2 -> V_5 = V_80 -> V_119 ;
else
V_2 -> V_5 = 0 ;
V_2 -> line = V_81 ;
V_2 -> type = V_72 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_89 = & V_90 ;
V_2 -> V_22 = V_88 ;
F_63 ( & V_105 -> V_108 , V_2 ) ;
F_64 ( & V_120 , V_2 ) ;
return 0 ;
}
static int T_6 F_65 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_66 ( & V_105 -> V_108 ) ;
if ( V_2 ) {
F_67 ( & V_120 , V_2 ) ;
F_63 ( & V_105 -> V_108 , NULL ) ;
V_2 -> V_83 = 0 ;
}
return 0 ;
}
static int T_3 F_68 ( void )
{
int V_121 ;
V_121 = F_69 ( & V_120 ) ;
if ( V_121 )
return V_121 ;
V_121 = F_70 ( & V_122 ) ;
if ( V_121 ) {
F_71 ( & V_120 ) ;
return V_121 ;
}
return 0 ;
}
static void T_7 F_72 ( void )
{
F_73 ( & V_122 ) ;
F_71 ( & V_120 ) ;
}
