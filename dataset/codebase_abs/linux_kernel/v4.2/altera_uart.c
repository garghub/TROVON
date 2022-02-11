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
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_25 * V_27 )
{
unsigned long V_22 ;
unsigned int V_28 , V_29 ;
V_28 = F_16 ( V_2 , V_26 , V_27 , 0 , 4000000 ) ;
V_29 = V_2 -> V_30 / V_28 ;
if ( V_27 )
F_17 ( V_26 , V_27 ) ;
F_18 ( V_26 , V_28 , V_28 ) ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
F_19 ( V_2 , V_26 -> V_31 , V_28 ) ;
F_3 ( V_2 , V_29 , V_32 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
}
static void F_20 ( struct V_10 * V_11 )
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
if ( F_21 ( V_2 ) )
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
if ( F_22 ( V_2 , V_33 ) )
continue;
F_23 ( V_2 , V_35 , V_46 , V_33 ,
V_34 ) ;
}
F_24 ( & V_2 -> V_23 ) ;
F_25 ( & V_2 -> V_54 -> V_2 ) ;
F_26 ( & V_2 -> V_23 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_55 * V_56 = & V_2 -> V_54 -> V_56 ;
if ( V_2 -> V_57 ) {
F_3 ( V_2 , V_2 -> V_57 , V_58 ) ;
V_2 -> V_57 = 0 ;
V_2 -> V_39 . V_59 ++ ;
return;
}
while ( F_1 ( V_2 , V_7 ) &
V_60 ) {
if ( V_56 -> V_61 == V_56 -> V_62 )
break;
F_3 ( V_2 , V_56 -> V_63 [ V_56 -> V_62 ] ,
V_58 ) ;
V_56 -> V_62 = ( V_56 -> V_62 + 1 ) & ( V_64 - 1 ) ;
V_2 -> V_39 . V_59 ++ ;
}
if ( F_28 ( V_56 ) < V_65 )
F_29 ( V_2 ) ;
if ( V_56 -> V_61 == V_56 -> V_62 ) {
V_11 -> V_16 &= ~ V_19 ;
F_3 ( V_2 , V_11 -> V_16 , V_18 ) ;
}
}
static T_2 F_30 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned int V_68 ;
V_68 = F_1 ( V_2 , V_7 ) & V_11 -> V_16 ;
F_26 ( & V_2 -> V_23 ) ;
if ( V_68 & V_36 )
F_20 ( V_11 ) ;
if ( V_68 & V_60 )
F_27 ( V_11 ) ;
F_24 ( & V_2 -> V_23 ) ;
return F_31 ( V_68 ) ;
}
static void F_32 ( unsigned long V_67 )
{
struct V_1 * V_2 = ( void * ) V_67 ;
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
F_30 ( 0 , V_2 ) ;
F_33 ( & V_11 -> V_69 , V_70 + F_34 ( V_2 ) ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_22 )
{
V_2 -> type = V_71 ;
F_3 ( V_2 , 0 , V_18 ) ;
F_3 ( V_2 , 0 , V_7 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned long V_22 ;
int V_72 ;
if ( ! V_2 -> V_66 ) {
F_37 ( & V_11 -> V_69 , F_32 , ( unsigned long ) V_2 ) ;
F_33 ( & V_11 -> V_69 , V_70 + F_34 ( V_2 ) ) ;
return 0 ;
}
V_72 = F_38 ( V_2 -> V_66 , F_30 , 0 ,
V_73 , V_2 ) ;
if ( V_72 ) {
F_39 ( V_73 L_1
L_2 , V_2 -> line , V_2 -> V_66 ) ;
return V_72 ;
}
F_13 ( & V_2 -> V_23 , V_22 ) ;
V_11 -> V_16 = V_20 ;
F_4 ( V_11 -> V_16 , V_2 -> V_4 + V_18 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_7 ( V_2 , struct V_10 , V_2 ) ;
unsigned long V_22 ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
V_11 -> V_16 = 0 ;
F_4 ( V_11 -> V_16 , V_2 -> V_4 + V_18 ) ;
F_14 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_66 )
F_41 ( V_2 -> V_66 , V_2 ) ;
else
F_42 ( & V_11 -> V_69 ) ;
}
static const char * F_43 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_71 ) ? L_3 : NULL ;
}
static int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
}
static int F_46 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
if ( ( V_75 -> type != V_76 ) && ( V_75 -> type != V_71 ) )
return - V_77 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
while ( ! ( F_1 ( V_2 , V_7 ) &
V_36 ) )
F_48 () ;
return F_1 ( V_2 , V_37 ) ;
}
static void F_49 ( struct V_1 * V_2 , unsigned char V_78 )
{
while ( ! ( F_1 ( V_2 , V_7 ) &
V_60 ) )
F_48 () ;
F_3 ( V_2 , V_78 , V_58 ) ;
}
static void F_50 ( struct V_1 * V_2 , int V_78 )
{
while ( ! ( F_1 ( V_2 , V_7 ) &
V_60 ) )
F_48 () ;
F_4 ( V_78 , V_2 -> V_4 + V_58 ) ;
}
static void F_51 ( struct V_79 * V_80 , const char * V_81 ,
unsigned int V_82 )
{
struct V_1 * V_2 = & ( V_83 + V_80 -> V_84 ) -> V_2 ;
F_52 ( V_2 , V_81 , V_82 , F_50 ) ;
}
static int T_3 F_53 ( struct V_79 * V_80 , char * V_85 )
{
struct V_1 * V_2 ;
int V_28 = V_86 ;
int V_87 = 8 ;
int V_45 = 'n' ;
int V_88 = 'n' ;
if ( V_80 -> V_84 < 0 || V_80 -> V_84 >= V_89 )
return - V_77 ;
V_2 = & V_83 [ V_80 -> V_84 ] . V_2 ;
if ( ! V_2 -> V_4 )
return - V_90 ;
if ( V_85 )
F_54 ( V_85 , & V_28 , & V_45 , & V_87 , & V_88 ) ;
return F_55 ( V_2 , V_80 , V_28 , V_45 , V_87 , V_88 ) ;
}
static int T_3 F_56 ( void )
{
F_57 ( & V_91 ) ;
return 0 ;
}
static int F_58 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
int V_94 ;
const T_4 * V_95 ;
V_95 = F_59 ( V_93 -> V_96 . V_97 , L_4 , & V_94 ) ;
if ( ! V_95 || V_94 < sizeof( T_4 ) )
return - V_90 ;
V_2 -> V_30 = F_60 ( V_95 ) ;
return 0 ;
}
static int F_58 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
return - V_90 ;
}
static int F_61 ( struct V_92 * V_93 )
{
struct V_98 * V_99 = F_62 ( & V_93 -> V_96 ) ;
struct V_1 * V_2 ;
struct V_100 * V_101 ;
struct V_100 * V_102 ;
int V_103 = V_93 -> V_104 ;
int V_72 ;
if ( V_103 == - 1 ) {
for ( V_103 = 0 ; V_103 < V_89 ; V_103 ++ )
if ( V_83 [ V_103 ] . V_2 . V_105 == 0 )
break;
}
if ( V_103 < 0 || V_103 >= V_89 )
return - V_77 ;
V_2 = & V_83 [ V_103 ] . V_2 ;
V_101 = F_63 ( V_93 , V_106 , 0 ) ;
if ( V_101 )
V_2 -> V_105 = V_101 -> V_107 ;
else if ( V_99 )
V_2 -> V_105 = V_99 -> V_105 ;
else
return - V_77 ;
V_102 = F_63 ( V_93 , V_108 , 0 ) ;
if ( V_102 )
V_2 -> V_66 = V_102 -> V_107 ;
else if ( V_99 )
V_2 -> V_66 = V_99 -> V_66 ;
if ( V_99 )
V_2 -> V_30 = V_99 -> V_30 ;
else {
V_72 = F_58 ( V_93 , V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_2 -> V_4 = F_64 ( V_2 -> V_105 , V_109 ) ;
if ( ! V_2 -> V_4 )
return - V_110 ;
if ( V_99 )
V_2 -> V_5 = V_99 -> V_111 ;
else
V_2 -> V_5 = 0 ;
V_2 -> line = V_103 ;
V_2 -> type = V_71 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = & V_115 ;
V_2 -> V_22 = V_116 ;
V_2 -> V_96 = & V_93 -> V_96 ;
F_65 ( V_93 , V_2 ) ;
F_66 ( & V_117 , V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_68 ( V_93 ) ;
if ( V_2 ) {
F_69 ( & V_117 , V_2 ) ;
V_2 -> V_105 = 0 ;
}
return 0 ;
}
static int T_3 F_70 ( void )
{
int V_118 ;
V_118 = F_71 ( & V_117 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_72 ( & V_119 ) ;
if ( V_118 )
F_73 ( & V_117 ) ;
return V_118 ;
}
static void T_5 F_74 ( void )
{
F_75 ( & V_119 ) ;
F_73 ( & V_117 ) ;
}
