static long F_1 ( struct V_1 * V_1 , void T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 V_7 ;
long V_8 ;
if ( V_4 -> V_9 != V_10 )
return - V_11 ;
if ( F_2 ( & V_7 , V_2 , sizeof( V_7 ) ) )
return - V_12 ;
F_3 () ;
V_8 = F_4 ( V_7 . V_13 ,
V_7 . V_14 [ 0 ] , V_7 . V_14 [ 1 ] ,
V_7 . V_14 [ 2 ] , V_7 . V_14 [ 3 ] ,
V_7 . V_14 [ 4 ] ) ;
F_5 () ;
return V_8 ;
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 , * V_19 ;
F_7 (p, n, pages, lru)
F_8 ( V_18 ) ;
F_9 ( V_16 ) ;
}
static int F_10 ( struct V_15 * V_20 ,
unsigned V_21 , T_2 V_22 ,
const void T_1 * V_4 )
{
unsigned V_23 ;
void * V_24 ;
int V_8 ;
if ( V_22 > V_25 )
return 0 ;
V_23 = V_25 ;
V_24 = NULL ;
while ( V_21 -- ) {
if ( V_23 > V_25 - V_22 ) {
struct V_17 * V_17 = F_11 ( V_26 ) ;
V_8 = - V_27 ;
if ( V_17 == NULL )
goto V_28;
V_24 = F_12 ( V_17 ) ;
F_13 ( & V_17 -> V_29 , V_20 ) ;
V_23 = 0 ;
}
V_8 = - V_12 ;
if ( F_2 ( V_24 + V_23 , V_4 , V_22 ) )
goto V_28;
V_4 += V_22 ;
V_23 += V_22 ;
}
V_8 = 0 ;
V_28:
return V_8 ;
}
static int F_14 ( unsigned V_21 , T_2 V_22 ,
struct V_15 * V_30 ,
int (* F_15)( void * V_4 , void * V_31 ) ,
void * V_31 )
{
void * V_24 ;
unsigned V_23 ;
int V_8 = 0 ;
F_16 ( V_22 > V_25 ) ;
V_23 = V_25 ;
V_24 = NULL ;
while ( V_21 -- ) {
if ( V_23 > V_25 - V_22 ) {
struct V_17 * V_17 ;
V_30 = V_30 -> V_32 ;
V_17 = F_17 ( V_30 , struct V_17 , V_29 ) ;
V_24 = F_12 ( V_17 ) ;
V_23 = 0 ;
}
V_8 = (* F_15)( V_24 + V_23 , V_31 ) ;
if ( V_8 )
break;
V_23 += V_22 ;
}
return V_8 ;
}
static int F_18 ( unsigned V_21 , T_2 V_22 ,
struct V_15 * V_30 ,
int (* F_15)( void * V_4 , int V_33 , void * V_31 ) ,
void * V_31 )
{
void * V_24 ;
unsigned V_23 ;
int V_8 = 0 ;
F_16 ( V_22 > V_25 ) ;
V_23 = V_25 ;
while ( V_21 ) {
int V_33 = ( V_25 / V_22 ) ;
struct V_17 * V_17 ;
if ( V_33 > V_21 )
V_33 = V_21 ;
V_30 = V_30 -> V_32 ;
V_17 = F_17 ( V_30 , struct V_17 , V_29 ) ;
V_24 = F_12 ( V_17 ) ;
V_8 = (* F_15)( V_24 , V_33 , V_31 ) ;
if ( V_8 )
break;
V_21 -= V_33 ;
}
return V_8 ;
}
static int F_19 ( void * V_4 , void * V_31 )
{
struct V_34 * V_35 = V_4 ;
struct V_36 * V_37 = V_31 ;
struct V_38 * V_39 = V_37 -> V_39 ;
int V_40 ;
if ( ( V_35 -> V_41 > ( V_42 >> V_43 ) ) ||
( ( unsigned long ) ( V_35 -> V_41 << V_43 ) >= - V_37 -> V_44 ) )
return - V_45 ;
if ( ( V_35 -> V_44 != V_37 -> V_44 ) ||
( ( V_35 -> V_44 + ( V_35 -> V_41 << V_43 ) ) > V_39 -> V_46 ) )
return - V_45 ;
V_40 = F_20 ( V_39 ,
V_35 -> V_44 & V_47 ,
V_35 -> V_48 , V_35 -> V_41 ,
V_39 -> V_49 ,
V_37 -> V_50 , NULL ) ;
if ( V_40 < 0 )
return V_40 ;
V_37 -> V_44 += V_35 -> V_41 << V_43 ;
return 0 ;
}
static long F_21 ( struct V_1 * V_1 , void T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_51 V_52 ;
struct V_53 * V_54 = V_55 -> V_54 ;
struct V_38 * V_39 ;
int V_40 ;
F_22 ( V_20 ) ;
struct V_36 V_31 ;
if ( F_23 ( V_56 ) )
return - V_57 ;
if ( F_2 ( & V_52 , V_2 , sizeof( V_52 ) ) )
return - V_12 ;
if ( V_4 -> V_9 != V_10 && V_4 -> V_9 != V_52 . V_58 )
return - V_11 ;
V_40 = F_10 ( & V_20 ,
V_52 . V_59 , sizeof( struct V_34 ) ,
V_52 . V_60 ) ;
if ( V_40 || F_24 ( & V_20 ) )
goto V_61;
F_25 ( & V_54 -> V_62 ) ;
{
struct V_17 * V_17 = F_26 ( & V_20 ,
struct V_17 , V_29 ) ;
struct V_34 * V_35 = F_12 ( V_17 ) ;
V_39 = F_27 ( V_54 , V_35 -> V_44 ) ;
V_40 = - V_45 ;
if ( ! V_39 || ( V_35 -> V_44 != V_39 -> V_63 ) || V_39 -> V_64 )
goto V_65;
V_39 -> V_64 = V_66 ;
}
V_31 . V_44 = V_39 -> V_63 ;
V_31 . V_39 = V_39 ;
V_31 . V_50 = V_52 . V_58 ;
V_40 = F_14 ( V_52 . V_59 , sizeof( struct V_34 ) ,
& V_20 ,
F_19 , & V_31 ) ;
V_65:
F_28 ( & V_54 -> V_62 ) ;
V_61:
F_6 ( & V_20 ) ;
return V_40 ;
}
static int F_29 ( void * V_4 , int V_33 , void * V_31 )
{
T_3 * V_67 = V_4 ;
struct V_68 * V_37 = V_31 ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_17 * * V_16 = V_39 -> V_64 ;
struct V_17 * * V_69 = NULL ;
int V_8 ;
if ( F_23 ( V_56 ) )
V_69 = & V_16 [ V_37 -> V_70 ] ;
F_16 ( V_33 < 0 ) ;
V_8 = F_30 ( V_37 -> V_39 , V_37 -> V_44 & V_47 , V_67 , V_33 ,
( int * ) V_67 , V_37 -> V_39 -> V_49 ,
V_37 -> V_50 , V_69 ) ;
if ( V_8 != V_33 ) {
if ( V_8 == - V_71 )
V_37 -> V_72 = - V_71 ;
else {
if ( V_37 -> V_72 == 0 )
V_37 -> V_72 = 1 ;
}
}
V_37 -> V_44 += V_25 * V_33 ;
V_37 -> V_70 += V_33 ;
return 0 ;
}
static int F_31 ( int V_73 , struct V_68 * V_37 )
{
int V_8 ;
if ( V_37 -> V_74 == 1 ) {
if ( V_73 ) {
T_3 V_75 ;
V_8 = F_32 ( V_75 , V_37 -> V_76 ) ;
if ( V_8 < 0 )
return V_8 ;
V_75 |= ( V_73 == - V_71 ) ?
V_77 :
V_78 ;
return F_33 ( V_75 , V_37 -> V_76 ++ ) ;
} else
V_37 -> V_76 ++ ;
} else {
if ( V_73 )
return F_33 ( V_73 , V_37 -> V_79 ++ ) ;
else
V_37 -> V_79 ++ ;
}
return 0 ;
}
static int F_34 ( void * V_4 , int V_33 , void * V_31 )
{
struct V_68 * V_37 = V_31 ;
int * V_80 = V_4 ;
int V_81 ;
int V_8 ;
for ( V_81 = 0 ; V_81 < V_33 ; V_81 ++ ) {
V_8 = F_31 ( V_80 [ V_81 ] , V_37 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_35 ( struct V_38 * V_39 , int V_82 )
{
int V_40 ;
struct V_17 * * V_16 ;
V_16 = F_36 ( V_82 , sizeof( V_16 [ 0 ] ) , V_26 ) ;
if ( V_16 == NULL )
return - V_27 ;
V_40 = F_37 ( V_82 , V_16 ) ;
if ( V_40 != 0 ) {
F_38 ( L_1 , V_83 ,
V_82 , V_40 ) ;
F_39 ( V_16 ) ;
return - V_27 ;
}
F_16 ( V_39 -> V_64 != NULL ) ;
V_39 -> V_64 = V_16 ;
return 0 ;
}
static long F_40 (
struct V_1 * V_1 , void T_1 * V_2 , int V_74 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_8 ;
struct V_84 V_85 ;
struct V_53 * V_54 = V_55 -> V_54 ;
struct V_38 * V_39 ;
unsigned long V_86 ;
F_22 ( V_20 ) ;
struct V_68 V_31 ;
switch ( V_74 ) {
case 1 :
if ( F_2 ( & V_85 , V_2 , sizeof( struct V_87 ) ) )
return - V_12 ;
V_85 . V_73 = NULL ;
if ( ! F_41 ( V_88 , V_85 . V_89 , V_85 . V_59 * sizeof( * V_85 . V_89 ) ) )
return - V_12 ;
break;
case 2 :
if ( F_2 ( & V_85 , V_2 , sizeof( struct V_84 ) ) )
return - V_12 ;
if ( ! F_41 ( V_88 , V_85 . V_73 , V_85 . V_59 * ( sizeof( * V_85 . V_73 ) ) ) )
return - V_12 ;
break;
default:
return - V_45 ;
}
if ( V_4 -> V_9 != V_10 && V_4 -> V_9 != V_85 . V_58 )
return - V_11 ;
V_86 = F_42 ( V_85 . V_59 , V_90 ) ;
if ( ( V_85 . V_59 <= 0 ) || ( V_86 > ( V_42 >> V_43 ) ) )
return - V_45 ;
V_8 = F_10 ( & V_20 , V_85 . V_59 , sizeof( T_3 ) , V_85 . V_89 ) ;
if ( V_8 )
goto V_61;
if ( F_24 ( & V_20 ) ) {
V_8 = - V_45 ;
goto V_61;
}
if ( V_74 == 2 ) {
if ( F_43 ( V_85 . V_73 , sizeof( int ) * V_85 . V_59 ) ) {
V_8 = - V_12 ;
goto V_61;
}
}
F_25 ( & V_54 -> V_62 ) ;
V_39 = F_27 ( V_54 , V_85 . V_91 ) ;
if ( ! V_39 ||
V_39 -> V_92 != & V_93 ) {
V_8 = - V_45 ;
goto V_94;
}
if ( V_39 -> V_64 == NULL ) {
if ( V_85 . V_91 != V_39 -> V_63 ||
V_85 . V_91 + ( V_86 << V_43 ) != V_39 -> V_46 ) {
V_8 = - V_45 ;
goto V_94;
}
if ( F_23 ( V_56 ) ) {
V_8 = F_35 ( V_39 , V_86 ) ;
if ( V_8 < 0 )
goto V_94;
} else
V_39 -> V_64 = V_66 ;
} else {
if ( V_85 . V_91 < V_39 -> V_63 ||
V_85 . V_91 + ( V_86 << V_43 ) > V_39 -> V_46 ) {
V_8 = - V_45 ;
goto V_94;
}
if ( F_44 ( V_39 , V_85 . V_91 , V_86 ) ) {
V_8 = - V_45 ;
goto V_94;
}
}
V_31 . V_50 = V_85 . V_58 ;
V_31 . V_39 = V_39 ;
V_31 . V_44 = V_85 . V_91 ;
V_31 . V_70 = 0 ;
V_31 . V_72 = 0 ;
V_31 . V_74 = V_74 ;
F_45 ( ( ( V_25 / sizeof( T_3 ) ) % V_90 ) != 0 ) ;
F_16 ( F_18 ( V_85 . V_59 , sizeof( T_3 ) ,
& V_20 , F_29 , & V_31 ) ) ;
F_28 ( & V_54 -> V_62 ) ;
if ( V_31 . V_72 ) {
V_31 . V_76 = ( T_3 * ) V_85 . V_89 ;
V_31 . V_79 = V_85 . V_73 ;
V_8 = F_18 ( V_85 . V_59 , sizeof( T_3 ) ,
& V_20 , F_34 , & V_31 ) ;
} else
V_8 = 0 ;
if ( ( V_8 == 0 ) && ( V_31 . V_72 == - V_71 ) )
V_8 = - V_71 ;
V_61:
F_6 ( & V_20 ) ;
return V_8 ;
V_94:
F_28 ( & V_54 -> V_62 ) ;
goto V_61;
}
static int F_46 (
struct V_95 V_96 [] , unsigned int V_59 ,
struct V_17 * V_16 [] , unsigned int V_86 )
{
unsigned int V_81 ;
for ( V_81 = 0 ; V_81 < V_59 ; V_81 ++ ) {
unsigned int V_97 ;
int V_98 ;
V_97 = F_42 (
F_47 ( V_96 [ V_81 ] . V_99 ) + V_96 [ V_81 ] . V_22 ,
V_25 ) ;
if ( V_97 > V_86 )
return - V_100 ;
V_98 = F_48 (
( unsigned long ) V_96 [ V_81 ] . V_99 ,
V_97 , V_101 , V_16 ) ;
if ( V_98 < 0 )
return V_98 ;
V_86 -= V_98 ;
V_16 += V_98 ;
}
return 0 ;
}
static void F_49 ( struct V_17 * V_16 [] , unsigned int V_86 )
{
unsigned int V_81 ;
if ( ! V_16 )
return;
for ( V_81 = 0 ; V_81 < V_86 ; V_81 ++ ) {
if ( V_16 [ V_81 ] )
F_50 ( V_16 [ V_81 ] ) ;
}
}
static long F_51 ( struct V_1 * V_1 , void T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_102 V_103 ;
struct V_95 * V_96 ;
unsigned int V_86 = 0 ;
struct V_17 * * V_16 = NULL ;
struct V_104 * V_105 = NULL ;
unsigned int V_81 ;
long V_40 ;
if ( F_2 ( & V_103 , V_2 , sizeof( V_103 ) ) )
return - V_12 ;
if ( V_4 -> V_9 != V_10 && V_4 -> V_9 != V_103 . V_58 )
return - V_11 ;
if ( V_103 . V_59 == 0 )
return 0 ;
if ( V_103 . V_59 > V_106 )
return - V_107 ;
V_96 = F_36 ( V_103 . V_59 , sizeof( * V_96 ) , V_26 ) ;
if ( ! V_96 )
return - V_27 ;
if ( F_2 ( V_96 , V_103 . V_108 ,
sizeof( * V_96 ) * V_103 . V_59 ) ) {
V_40 = - V_12 ;
goto V_61;
}
for ( V_81 = 0 ; V_81 < V_103 . V_59 ; V_81 ++ ) {
if ( V_96 [ V_81 ] . V_22 > V_109 ) {
V_40 = - V_107 ;
goto V_61;
}
if ( ! F_41 ( V_88 , V_96 [ V_81 ] . V_99 ,
V_96 [ V_81 ] . V_22 ) ) {
V_40 = - V_12 ;
goto V_61;
}
V_86 += F_42 (
F_47 ( V_96 [ V_81 ] . V_99 ) + V_96 [ V_81 ] . V_22 ,
V_25 ) ;
}
V_16 = F_36 ( V_86 , sizeof( * V_16 ) , V_26 ) ;
if ( ! V_16 ) {
V_40 = - V_27 ;
goto V_61;
}
V_105 = F_36 ( V_103 . V_59 , sizeof( * V_105 ) , V_26 ) ;
if ( ! V_105 ) {
V_40 = - V_27 ;
goto V_61;
}
V_40 = F_46 ( V_96 , V_103 . V_59 , V_16 , V_86 ) ;
if ( V_40 )
goto V_61;
for ( V_81 = 0 ; V_81 < V_103 . V_59 ; V_81 ++ ) {
F_52 ( V_105 [ V_81 ] . V_110 , V_96 [ V_81 ] . V_99 ) ;
V_105 [ V_81 ] . V_22 = V_96 [ V_81 ] . V_22 ;
}
F_3 () ;
V_40 = F_53 ( V_103 . V_58 , V_103 . V_59 , V_105 ) ;
F_5 () ;
V_61:
F_49 ( V_16 , V_86 ) ;
F_39 ( V_105 ) ;
F_39 ( V_16 ) ;
F_39 ( V_96 ) ;
return V_40 ;
}
static long F_54 ( struct V_1 * V_1 , void T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
T_4 V_58 ;
if ( F_2 ( & V_58 , V_2 , sizeof( V_58 ) ) )
return - V_12 ;
if ( V_4 -> V_9 == V_10 )
V_4 -> V_9 = V_58 ;
else if ( V_4 -> V_9 != V_58 )
return - V_45 ;
return 0 ;
}
static long F_55 ( struct V_1 * V_1 ,
unsigned int V_111 , unsigned long V_4 )
{
int V_8 = - V_112 ;
void T_1 * V_2 = ( void T_1 * ) V_4 ;
switch ( V_111 ) {
case V_113 :
V_8 = F_1 ( V_1 , V_2 ) ;
break;
case V_114 :
V_8 = F_21 ( V_1 , V_2 ) ;
break;
case V_115 :
V_8 = F_40 ( V_1 , V_2 , 1 ) ;
break;
case V_116 :
V_8 = F_40 ( V_1 , V_2 , 2 ) ;
break;
case V_117 :
V_8 = F_51 ( V_1 , V_2 ) ;
break;
case V_118 :
V_8 = F_54 ( V_1 , V_2 ) ;
break;
default:
break;
}
return V_8 ;
}
static int F_56 ( struct V_119 * V_120 , struct V_1 * V_1 )
{
struct V_3 * V_4 = F_57 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_9 = V_10 ;
V_1 -> V_5 = V_4 ;
return 0 ;
}
static int F_58 ( struct V_119 * V_120 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
F_39 ( V_4 ) ;
return 0 ;
}
static void F_59 ( struct V_38 * V_39 )
{
struct V_17 * * V_16 = V_39 -> V_64 ;
int V_82 = F_60 ( V_39 ) ;
int V_121 = ( V_39 -> V_46 - V_39 -> V_63 ) >> V_122 ;
int V_40 ;
if ( ! F_23 ( V_56 ) || ! V_82 || ! V_16 )
return;
V_40 = F_61 ( V_39 , V_121 , V_16 ) ;
if ( V_40 == 0 )
F_62 ( V_82 , V_16 ) ;
else
F_63 ( L_2 ,
V_82 , V_40 ) ;
F_39 ( V_16 ) ;
}
static int F_64 ( struct V_123 * V_124 )
{
F_65 ( V_125 L_3 ,
V_124 -> V_39 , V_124 -> V_39 -> V_63 , V_124 -> V_39 -> V_46 ,
V_124 -> V_126 , ( void * ) V_124 -> V_127 ) ;
return V_128 ;
}
static int V_51 ( struct V_1 * V_1 , struct V_38 * V_39 )
{
V_39 -> V_129 |= V_130 | V_131 | V_132 |
V_133 | V_134 ;
V_39 -> V_92 = & V_93 ;
V_39 -> V_64 = NULL ;
return 0 ;
}
static int F_66 ( T_5 * V_135 , struct V_17 * V_136 ,
unsigned long V_91 , void * V_4 )
{
return F_67 ( * V_135 ) ? 0 : - V_137 ;
}
static int F_44 (
struct V_38 * V_39 ,
unsigned long V_91 ,
unsigned long V_86 )
{
return F_68 ( V_39 -> V_138 , V_91 , V_86 << V_43 ,
F_66 , NULL ) != 0 ;
}
static int T_6 F_69 ( void )
{
int V_73 ;
if ( ! F_70 () )
return - V_139 ;
V_73 = F_71 ( & V_140 ) ;
if ( V_73 != 0 ) {
F_72 ( L_4 ) ;
return V_73 ;
}
return 0 ;
}
static void T_7 F_73 ( void )
{
F_74 ( & V_140 ) ;
}
