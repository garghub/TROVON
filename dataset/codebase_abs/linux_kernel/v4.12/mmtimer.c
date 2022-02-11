static int F_1 ( int V_1 )
{
if ( F_2 ( ( unsigned long * ) F_3 ( V_2 ) ) &
V_3 << V_1 )
return 1 ;
else
return 0 ;
}
static void F_4 ( int V_1 )
{
F_5 ( ( V_4 * ) F_3 ( V_5 ) ,
V_3 << V_1 ) ;
}
static void F_6 ( int V_6 , V_4 V_7 )
{
V_4 V_8 ;
F_5 ( ( V_4 * ) F_3 ( V_9 ) , 0UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_10 ) , - 1L ) ;
F_4 ( 0 ) ;
V_8 = ( ( V_4 ) V_11 << V_12 ) |
( ( V_4 ) F_7 ( V_6 ) <<
V_13 ) ;
F_5 ( ( V_4 * ) F_3 ( V_14 ) , V_8 ) ;
F_5 ( ( V_4 * ) F_3 ( V_9 ) , 1UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_10 ) , V_7 ) ;
}
static void F_8 ( int V_6 , V_4 V_7 )
{
V_4 V_8 ;
F_5 ( ( V_4 * ) F_3 ( V_15 ) , 0UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_16 ) , - 1L ) ;
F_4 ( 1 ) ;
V_8 = ( ( V_4 ) V_11 << V_17 ) |
( ( V_4 ) F_7 ( V_6 ) <<
V_18 ) ;
F_5 ( ( V_4 * ) F_3 ( V_19 ) , V_8 ) ;
F_5 ( ( V_4 * ) F_3 ( V_15 ) , 1UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_16 ) , V_7 ) ;
}
static void F_9 ( int V_6 , V_4 V_7 )
{
V_4 V_8 ;
F_5 ( ( V_4 * ) F_3 ( V_20 ) , 0UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_21 ) , - 1L ) ;
F_4 ( 2 ) ;
V_8 = ( ( V_4 ) V_11 << V_22 ) |
( ( V_4 ) F_7 ( V_6 ) <<
V_23 ) ;
F_5 ( ( V_4 * ) F_3 ( V_24 ) , V_8 ) ;
F_5 ( ( V_4 * ) F_3 ( V_20 ) , 1UL ) ;
F_5 ( ( V_4 * ) F_3 ( V_21 ) , V_7 ) ;
}
static int F_10 ( int V_6 , int V_1 , unsigned long V_7 ,
V_4 * V_25 )
{
switch ( V_1 ) {
case 0 :
F_6 ( V_6 , V_7 ) ;
break;
case 1 :
F_8 ( V_6 , V_7 ) ;
break;
case 2 :
F_9 ( V_6 , V_7 ) ;
break;
}
* V_25 = F_11 () ;
if ( * V_25 <= V_7 )
return 1 ;
return F_1 ( V_1 ) ;
}
static int F_12 ( long V_26 , int V_1 )
{
switch ( V_1 ) {
case 0 :
V_26 == - 1 ? F_5 ( ( V_4 * ) F_3 ( V_9 ) ,
0UL ) : F_13 ( V_26 , V_9 , 0UL ) ;
break;
case 1 :
V_26 == - 1 ? F_5 ( ( V_4 * ) F_3 ( V_15 ) ,
0UL ) : F_13 ( V_26 , V_15 , 0UL ) ;
break;
case 2 :
V_26 == - 1 ? F_5 ( ( V_4 * ) F_3 ( V_20 ) ,
0UL ) : F_13 ( V_26 , V_20 , 0UL ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static void F_14 ( struct V_28 * V_29 )
{
int V_30 = V_29 -> V_31 -> V_32 . V_28 . V_33 ;
unsigned long V_7 = V_29 -> V_31 -> V_32 . V_28 . V_7 ;
struct V_34 * * V_35 = & V_36 [ V_30 ] . V_37 . V_34 ;
struct V_34 * V_38 = NULL ;
struct V_28 * V_39 ;
while ( * V_35 ) {
V_38 = * V_35 ;
V_39 = F_15 ( V_38 , struct V_28 , V_40 ) ;
if ( V_7 < V_39 -> V_31 -> V_32 . V_28 . V_7 )
V_35 = & ( * V_35 ) -> V_41 ;
else
V_35 = & ( * V_35 ) -> V_42 ;
}
F_16 ( & V_29 -> V_40 , V_38 , V_35 ) ;
F_17 ( & V_29 -> V_40 , & V_36 [ V_30 ] . V_37 ) ;
if ( ! V_36 [ V_30 ] . V_43 || V_7 < F_15 ( V_36 [ V_30 ] . V_43 ,
struct V_28 , V_40 ) -> V_31 -> V_32 . V_28 . V_7 )
V_36 [ V_30 ] . V_43 = & V_29 -> V_40 ;
}
static void F_18 ( int V_30 )
{
struct V_44 * V_29 = & V_36 [ V_30 ] ;
struct V_28 * V_39 ;
struct V_45 * V_46 ;
V_4 V_7 , exp , V_25 ;
int V_47 ;
V_48:
if ( V_29 -> V_43 == NULL )
return;
V_39 = F_15 ( V_29 -> V_43 , struct V_28 , V_40 ) ;
V_46 = V_39 -> V_31 ;
if ( ! V_46 -> V_32 . V_28 . V_49 ) {
if ( ! F_10 ( V_39 -> V_6 , V_50 ,
V_46 -> V_32 . V_28 . V_7 ,
& V_25 ) ) {
F_19 ( & V_29 -> V_51 ) ;
}
return;
}
V_47 = 0 ;
V_7 = exp = V_46 -> V_32 . V_28 . V_7 ;
while ( ! F_10 ( V_39 -> V_6 , V_50 , V_7 ,
& V_25 ) ) {
int V_52 ;
V_47 ++ ;
V_7 = V_25 +
V_53 + ( 1 << V_47 ) ;
V_52 = ( ( V_4 ) ( V_7 - exp ) / V_46 -> V_32 . V_28 . V_49 ) ;
if ( V_52 ) {
V_46 -> V_54 += V_52 ;
V_46 -> V_32 . V_28 . V_7 += V_46 -> V_32 . V_28 . V_49 * V_52 ;
exp = V_46 -> V_32 . V_28 . V_7 ;
}
if ( V_47 > 20 ) {
F_20 ( V_55 L_1 ) ;
V_46 -> V_32 . V_28 . clock = V_56 ;
V_29 -> V_43 = F_21 ( & V_39 -> V_40 ) ;
F_22 ( & V_39 -> V_40 , & V_29 -> V_37 ) ;
F_23 ( V_39 ) ;
goto V_48;
}
}
}
static long F_24 ( struct V_57 * V_57 , unsigned int V_58 ,
unsigned long V_59 )
{
int V_60 = 0 ;
F_25 ( & V_61 ) ;
switch ( V_58 ) {
case V_62 :
if( V_63 <= ( 1 << 16 ) )
V_60 = ( ( ( long ) V_64 ) & ( V_63 - 1 ) ) / 8 ;
else
V_60 = - V_65 ;
break;
case V_66 :
if( F_26 ( ( unsigned long V_67 * ) V_59 ,
& V_68 , sizeof( unsigned long ) ) )
V_60 = - V_27 ;
break;
case V_69 :
if( F_26 ( ( unsigned long V_67 * ) V_59 ,
& V_70 ,
sizeof( unsigned long ) ) )
V_60 = - V_27 ;
break;
case V_71 :
V_60 = V_72 ;
break;
case V_73 :
V_60 = ( V_63 <= ( 1 << 16 ) ) ? 1 : 0 ;
break;
case V_74 :
if( F_26 ( ( unsigned long V_67 * ) V_59 ,
V_64 , sizeof( unsigned long ) ) )
V_60 = - V_27 ;
break;
default:
V_60 = - V_75 ;
break;
}
F_27 ( & V_61 ) ;
return V_60 ;
}
static int F_28 ( struct V_57 * V_57 , struct V_76 * V_77 )
{
unsigned long V_78 ;
if ( V_77 -> V_79 - V_77 -> V_80 != V_63 )
return - V_81 ;
if ( V_77 -> V_82 & V_83 )
return - V_84 ;
if ( V_63 > ( 1 << 16 ) )
return - V_65 ;
V_77 -> V_85 = F_29 ( V_77 -> V_85 ) ;
V_78 = F_30 ( V_64 ) ;
V_78 &= ~ ( V_63 - 1 ) ;
V_78 &= 0xfffffffffffffffUL ;
if ( F_31 ( V_77 , V_77 -> V_80 , V_78 >> V_86 ,
V_63 , V_77 -> V_85 ) ) {
F_20 ( V_87 L_2 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_32 ( T_1 V_89 , struct V_90 * V_91 )
{
V_4 V_92 ;
V_92 = F_11 () * V_93
+ V_94 . V_95 ;
* V_91 = F_33 ( V_92 ) ;
V_91 -> V_96 += V_94 . V_96 ;
return 0 ;
}
static int F_34 ( const T_1 V_89 , const struct V_90 * V_91 )
{
V_4 V_92 ;
T_2 V_97 ;
V_92 = F_11 () * V_93 ;
V_94 . V_96 = V_91 -> V_96 - F_35 ( V_92 , V_98 , & V_97 ) ;
if ( V_97 <= V_91 -> V_95 )
V_94 . V_95 = V_91 -> V_96 - V_97 ;
else {
V_94 . V_95 = V_91 -> V_96 + V_98 - V_97 ;
V_94 . V_96 -- ;
}
return 0 ;
}
static T_3
F_36 ( int V_99 , void * V_100 )
{
unsigned long V_7 = 0 ;
int V_101 = V_102 ;
unsigned V_103 = F_37 ( F_38 () ) ;
struct V_28 * V_104 ;
F_39 ( & V_36 [ V_103 ] . V_105 ) ;
V_104 = F_15 ( V_36 [ V_103 ] . V_43 , struct V_28 , V_40 ) ;
if ( V_104 == NULL ) {
F_40 ( & V_36 [ V_103 ] . V_105 ) ;
return V_101 ;
}
if ( V_104 -> V_6 == F_38 () ) {
if ( V_104 -> V_31 )
V_7 = V_104 -> V_31 -> V_32 . V_28 . V_7 ;
if ( ( F_1 ( V_50 ) > 0 ) ||
( V_7 && ( V_7 <= F_11 () ) ) ) {
F_4 ( V_50 ) ;
F_19 ( & V_36 [ V_103 ] . V_51 ) ;
V_101 = V_106 ;
}
}
F_40 ( & V_36 [ V_103 ] . V_105 ) ;
return V_101 ;
}
static void F_41 ( unsigned long V_107 )
{
int V_30 = V_107 ;
struct V_44 * V_108 = & V_36 [ V_30 ] ;
struct V_28 * V_39 ;
struct V_45 * V_46 ;
unsigned long V_109 ;
F_42 ( & V_108 -> V_105 , V_109 ) ;
if ( ! V_108 -> V_43 )
goto V_110;
V_39 = F_15 ( V_108 -> V_43 , struct V_28 , V_40 ) ;
V_46 = V_39 -> V_31 ;
if ( V_46 -> V_32 . V_28 . clock == V_56 )
goto V_110;
V_46 -> V_54 = 0 ;
V_108 -> V_43 = F_21 ( & V_39 -> V_40 ) ;
F_22 ( & V_39 -> V_40 , & V_108 -> V_37 ) ;
if ( F_43 ( V_46 , 0 ) != 0 )
V_46 -> V_54 ++ ;
if( V_46 -> V_32 . V_28 . V_49 ) {
V_46 -> V_32 . V_28 . V_7 += V_46 -> V_32 . V_28 . V_49 ;
F_14 ( V_39 ) ;
} else {
V_46 -> V_32 . V_28 . clock = V_56 ;
V_46 -> V_32 . V_28 . V_7 = 0 ;
F_23 ( V_39 ) ;
}
F_18 ( V_30 ) ;
V_46 -> V_111 = V_46 -> V_54 ;
V_110:
F_44 ( & V_108 -> V_105 , V_109 ) ;
}
static int F_45 ( struct V_45 * V_31 )
{
V_31 -> V_32 . V_28 . clock = V_56 ;
return 0 ;
}
static int F_46 ( struct V_45 * V_112 )
{
T_4 V_30 = V_112 -> V_32 . V_28 . V_33 ;
unsigned long V_113 ;
F_42 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
if ( V_112 -> V_32 . V_28 . clock != V_56 ) {
unsigned long V_7 = V_112 -> V_32 . V_28 . V_7 ;
struct V_34 * V_29 = V_36 [ V_30 ] . V_37 . V_34 ;
struct V_28 * V_114 ( V_46 ) ;
int V_115 = 0 ;
V_112 -> V_32 . V_28 . clock = V_56 ;
V_112 -> V_32 . V_28 . V_7 = 0 ;
while ( V_29 ) {
V_46 = F_15 ( V_29 , struct V_28 , V_40 ) ;
if ( V_46 -> V_31 == V_112 )
break;
if ( V_7 < V_46 -> V_31 -> V_32 . V_28 . V_7 )
V_29 = V_29 -> V_41 ;
else
V_29 = V_29 -> V_42 ;
}
if ( ! V_29 ) {
F_44 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
return 0 ;
}
if ( V_36 [ V_30 ] . V_43 == V_29 ) {
V_36 [ V_30 ] . V_43 = F_21 ( V_29 ) ;
V_115 = 1 ;
}
F_22 ( V_29 , & V_36 [ V_30 ] . V_37 ) ;
F_23 ( V_46 ) ;
if ( V_115 ) {
F_12 ( F_47 ( V_30 ) ,
V_50 ) ;
F_18 ( V_30 ) ;
}
}
F_44 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
return 0 ;
}
static void F_48 ( struct V_45 * V_112 , struct V_116 * V_117 )
{
if ( V_112 -> V_32 . V_28 . clock == V_56 ) {
V_117 -> V_118 . V_95 = 0 ;
V_117 -> V_118 . V_96 = 0 ;
V_117 -> V_119 . V_95 = 0 ;
V_117 -> V_119 . V_96 = 0 ;
return;
}
V_117 -> V_118 = F_33 ( V_112 -> V_32 . V_28 . V_49 * V_93 ) ;
V_117 -> V_119 = F_33 ( ( V_112 -> V_32 . V_28 . V_7 - F_11 () ) * V_93 ) ;
}
static int F_49 ( struct V_45 * V_112 , int V_109 ,
struct V_116 * V_120 ,
struct V_116 * V_121 )
{
unsigned long V_122 , V_123 , V_113 ;
int V_124 = 0 ;
T_4 V_30 ;
struct V_28 * V_104 ;
struct V_34 * V_29 ;
if ( V_121 )
F_48 ( V_112 , V_121 ) ;
F_46 ( V_112 ) ;
V_122 = F_50 ( & V_120 -> V_119 ) ;
V_123 = F_50 ( & V_120 -> V_118 ) ;
if ( V_122 == 0 )
return 0 ;
V_104 = F_51 ( sizeof( struct V_28 ) , V_125 ) ;
if ( V_104 == NULL )
return - V_126 ;
if ( V_109 & V_127 ) {
struct V_90 V_29 ;
unsigned long V_128 ;
F_52 ( & V_29 ) ;
V_128 = F_50 ( & V_29 ) ;
if ( V_122 > V_128 )
V_122 -= V_128 ;
else
V_122 = 0 ;
}
V_122 = ( V_122 + V_93 - 1 ) / V_93 + F_11 () ;
V_123 = ( V_123 + V_93 - 1 ) / V_93 ;
F_53 () ;
V_30 = F_37 ( F_38 () ) ;
F_42 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
V_104 -> V_31 = V_112 ;
V_104 -> V_6 = F_38 () ;
V_112 -> V_32 . V_28 . clock = V_129 ;
V_112 -> V_32 . V_28 . V_33 = V_30 ;
V_112 -> V_32 . V_28 . V_49 = V_123 ;
V_112 -> V_32 . V_28 . V_7 = V_122 ;
V_29 = V_36 [ V_30 ] . V_43 ;
F_14 ( V_104 ) ;
if ( V_36 [ V_30 ] . V_43 == V_29 ) {
F_44 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
F_54 () ;
return V_124 ;
}
if ( V_29 )
F_12 ( F_47 ( V_30 ) , V_50 ) ;
F_18 ( V_30 ) ;
F_44 ( & V_36 [ V_30 ] . V_105 , V_113 ) ;
F_54 () ;
return V_124 ;
}
static int F_55 ( const T_1 V_130 , struct V_90 * V_91 )
{
V_91 -> V_96 = 0 ;
V_91 -> V_95 = V_93 ;
return 0 ;
}
static int T_5 F_56 ( void )
{
T_4 V_33 , V_131 = - 1 ;
if ( ! F_57 ( L_3 ) )
return 0 ;
if ( V_70 < 100000 ) {
F_20 ( V_87 L_4 ,
V_132 ) ;
goto V_133;
}
V_68 = ( ( unsigned long ) 1E15 + V_70 /
2 ) / V_70 ;
if ( F_58 ( V_11 , F_36 , V_134 , V_132 , NULL ) ) {
F_20 ( V_135 L_5 ,
V_132 ) ;
goto V_133;
}
if ( F_59 ( & V_136 ) ) {
F_20 ( V_87 L_6 ,
V_132 ) ;
goto V_137;
}
F_60 (node) {
V_131 = V_33 ;
}
V_131 ++ ;
V_36 = F_61 ( sizeof( struct V_44 ) * V_131 , V_125 ) ;
if ( ! V_36 ) {
F_20 ( V_87 L_7 ,
V_132 ) ;
goto V_138;
}
F_60 (node) {
F_62 ( & V_36 [ V_33 ] . V_105 ) ;
F_63 ( & V_36 [ V_33 ] . V_51 , F_41 ,
( unsigned long ) V_33 ) ;
}
V_93 = V_98 / V_70 ;
F_64 ( V_139 , & V_140 ) ;
F_20 ( V_141 L_8 , V_142 , V_143 ,
V_70 / ( unsigned long ) 1E6 ) ;
return 0 ;
V_138:
F_65 ( & V_136 ) ;
V_137:
F_66 ( V_11 , NULL ) ;
V_133:
return - 1 ;
}
