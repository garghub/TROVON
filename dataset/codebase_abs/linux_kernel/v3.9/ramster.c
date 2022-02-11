static int T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 ( L_1 , NULL ) ;
if ( V_2 == NULL )
return - V_3 ;
F_3 ( L_2 , V_4 , V_2 , & V_5 ) ;
F_3 ( L_3 , V_4 , V_2 , & V_6 ) ;
F_3 ( L_4 , V_4 , V_2 ,
& V_7 ) ;
F_3 ( L_5 , V_4 , V_2 ,
& V_8 ) ;
F_3 ( L_6 , V_4 , V_2 ,
& V_9 ) ;
F_3 ( L_7 , V_4 , V_2 ,
& V_10 ) ;
F_3 ( L_8 , V_4 , V_2 ,
& V_11 ) ;
F_3 ( L_9 , V_4 , V_2 ,
& V_12 ) ;
F_3 ( L_10 , V_4 , V_2 ,
& V_13 ) ;
F_3 ( L_11 , V_4 , V_2 ,
& V_14 ) ;
F_3 ( L_12 , V_4 , V_2 ,
& V_15 ) ;
F_3 ( L_13 , V_4 , V_2 ,
& V_16 ) ;
F_3 ( L_14 , V_4 , V_2 ,
& V_17 ) ;
F_3 ( L_15 , V_4 , V_2 ,
& V_18 ) ;
F_3 ( L_16 , V_4 , V_2 ,
& V_19 ) ;
F_3 ( L_17 , V_4 , V_2 ,
& V_20 ) ;
F_3 ( L_18 , V_4 , V_2 ,
& V_21 ) ;
return 0 ;
}
static struct V_22 * F_4 ( struct V_23 * V_24 )
{
struct V_22 * V_25 = NULL ;
struct V_26 * V_27 ;
V_27 = & F_5 ( V_28 ) ;
V_25 = V_27 -> V_25 ;
F_6 ( V_25 == NULL ) ;
V_27 -> V_25 = NULL ;
V_29 = F_7 ( & V_30 ) ;
if ( V_29 > V_31 )
V_31 = V_29 ;
return V_25 ;
}
static void F_8 ( struct V_22 * V_25 ,
struct V_23 * V_24 )
{
int V_32 ;
V_32 = F_9 ( & V_30 ) ;
F_6 ( V_32 < 0 ) ;
F_10 ( V_33 , V_25 ) ;
}
int F_11 ( struct V_23 * V_24 )
{
struct V_26 * V_27 ;
struct V_22 * V_25 ;
int V_34 = - V_35 ;
F_6 ( ! F_12 () ) ;
if ( F_13 ( V_33 == NULL ) )
F_14 () ;
V_27 = & F_5 ( V_28 ) ;
V_25 = F_15 ( V_33 , V_36 ) ;
if ( F_13 ( V_25 == NULL ) && V_27 -> V_25 == NULL )
F_14 () ;
else if ( V_27 -> V_25 == NULL )
V_27 -> V_25 = V_25 ;
else
F_10 ( V_33 , V_25 ) ;
return V_34 ;
}
int F_16 ( int V_37 , struct V_38 * V_39 , T_2 V_40 ,
char * V_41 , unsigned int V_42 , void * V_43 )
{
int V_34 = - V_44 ;
unsigned long V_45 ;
struct V_23 * V_24 ;
bool V_46 , V_47 = false ;
void * V_48 , * V_49 ;
struct V_50 * V_51 ;
V_24 = F_17 ( V_52 , V_37 ) ;
if ( F_13 ( V_24 == NULL ) )
goto V_53;
V_46 = F_18 ( V_24 ) ;
F_19 ( V_45 ) ;
V_48 = F_20 ( V_24 , V_39 , V_40 , & V_51 , & V_49 ) ;
if ( V_48 == NULL ) {
#ifdef F_21
F_22 ( L_19 ) ;
#endif
if ( V_46 )
V_11 ++ ;
else
V_12 ++ ;
V_51 = NULL ;
goto V_54;
} else if ( F_13 ( ! F_23 ( V_48 ) ) ) {
#ifdef F_21
F_22 ( L_20 ) ;
#endif
if ( V_46 )
V_11 ++ ;
else
V_12 ++ ;
V_51 = NULL ;
V_48 = NULL ;
V_34 = - V_55 ;
goto V_54;
} else if ( V_42 == 0 ) {
V_48 = NULL ;
if ( V_46 )
V_11 ++ ;
else
F_14 () ;
V_47 = true ;
goto V_54;
}
if ( F_24 ( V_48 ) ) {
F_6 ( V_46 ) ;
V_48 = F_25 ( V_48 ) ;
F_26 ( V_48 , V_41 , V_42 ) ;
} else {
V_48 = NULL ;
V_51 = NULL ;
}
F_6 ( V_43 == NULL ) ;
F_27 ( V_41 , V_42 , (struct V_56 * ) V_43 ) ;
if ( V_46 )
V_9 ++ ;
else
V_10 ++ ;
V_34 = 0 ;
V_54:
F_28 ( V_51 , V_40 , V_48 , V_49 , V_47 ) ;
F_29 ( V_24 ) ;
F_30 ( V_45 ) ;
V_53:
return V_34 ;
}
void F_31 ( struct V_50 * V_51 )
{
V_51 -> V_43 = NULL ;
}
void F_32 ( struct V_23 * V_24 , struct V_50 * V_51 ,
bool V_57 )
{
struct V_22 * V_25 ;
F_6 ( F_33 () ) ;
if ( V_51 -> V_43 == NULL )
return;
if ( V_57 && F_18 ( V_24 ) )
return;
F_6 ( ! F_23 ( V_51 -> V_43 ) ) ;
V_25 = F_4 ( V_24 ) ;
V_25 -> V_58 . V_59 = F_34 ( V_51 -> V_43 ) ;
V_25 -> V_58 . V_37 = V_24 -> V_37 ;
V_25 -> V_58 . V_60 = V_51 -> V_60 ;
V_25 -> V_58 . V_40 = V_61 ;
V_25 -> V_62 . V_63 = V_64 ;
F_35 ( & V_65 ) ;
F_36 ( & V_25 -> V_62 . V_66 , & V_67 ) ;
F_37 ( & V_65 ) ;
}
void * F_38 ( void * V_48 , struct V_23 * V_24 ,
struct V_38 * V_39 , T_2 V_40 ,
bool * V_68 )
{
int V_69 = F_39 ( V_48 ) , V_70 ;
void * V_71 = NULL ;
unsigned long V_45 ;
struct V_72 V_73 ;
F_6 ( ! F_23 ( V_48 ) ) ;
F_6 ( F_18 ( V_24 ) ) ;
if ( V_74 )
goto V_53;
if ( F_24 ( V_48 ) ) {
* V_68 = true ;
goto V_53;
}
* V_68 = false ;
F_19 ( V_45 ) ;
V_73 . V_59 = F_34 ( V_48 ) ;
V_73 . V_37 = V_24 -> V_37 ;
V_73 . V_60 = * V_39 ;
V_73 . V_40 = V_40 ;
V_71 = F_40 ( NULL , V_69 , true , false , & V_73 ) ;
if ( V_71 != NULL ) {
V_71 = F_41 ( V_71 ) ;
V_70 = F_9 ( & V_75 ) ;
F_42 ( V_70 < 0 ) ;
} else {
V_13 ++ ;
}
F_30 ( V_45 ) ;
V_53:
return V_71 ;
}
int F_43 ( void * V_76 , void * V_77 ,
struct V_23 * V_24 ,
struct V_38 * V_60 , T_2 V_40 ,
bool free , void * V_43 )
{
struct V_78 V_58 ;
int V_34 ;
if ( F_24 ( V_77 ) )
free = true ;
V_58 = F_44 ( V_52 , V_24 , V_60 , V_40 ) ;
V_34 = F_45 ( & V_58 , free ,
F_34 ( V_76 ) ,
F_39 ( V_76 ) ,
F_46 ( V_76 ) ,
V_43 ) ;
return V_34 ;
}
bool F_47 ( void * V_48 )
{
return F_23 ( V_48 ) ;
}
int F_48 ( void * V_79 , struct V_50 * V_51 )
{
int V_34 = - 1 ;
if ( V_79 != NULL ) {
if ( V_51 -> V_43 == NULL )
V_51 -> V_43 = V_79 ;
else if ( F_34 ( V_79 ) !=
F_34 ( ( void * ) ( V_51 -> V_43 ) ) )
F_14 () ;
V_34 = 0 ;
}
return V_34 ;
}
void * F_49 ( void * V_48 , struct V_23 * V_24 ,
struct V_38 * V_60 , T_2 V_40 , bool V_80 )
{
bool V_46 = F_18 ( V_24 ) ;
void * V_81 = NULL ;
int V_70 ;
F_6 ( F_33 () ) ;
F_6 ( ! F_23 ( V_48 ) ) ;
F_50 ( V_80 == false ) ;
if ( V_60 == NULL ) {
} else if ( V_46 ) {
} else if ( F_24 ( V_48 ) ) {
V_81 = F_25 ( V_48 ) ;
} else {
struct V_22 * V_25 =
F_4 ( V_24 ) ;
V_25 -> V_58 . V_59 = F_34 ( V_48 ) ;
V_25 -> V_58 . V_37 = V_24 -> V_37 ;
V_25 -> V_58 . V_60 = * V_60 ;
V_25 -> V_58 . V_40 = V_40 ;
V_25 -> V_62 . V_63 = V_82 ;
F_35 ( & V_65 ) ;
F_36 ( & V_25 -> V_62 . V_66 , & V_67 ) ;
F_37 ( & V_65 ) ;
V_70 = F_9 ( & V_75 ) ;
F_42 ( V_70 < 0 ) ;
}
return V_81 ;
}
void F_51 ( bool V_46 , int V_83 )
{
int V_70 ;
F_6 ( V_83 != 1 && V_83 != - 1 ) ;
if ( V_46 ) {
if ( V_83 > 0 ) {
V_70 = F_7 (
& V_84 ) ;
if ( V_70 > V_19 )
V_19 = V_70 ;
} else {
V_70 = F_9 ( & V_84 ) ;
F_42 ( V_70 < 0 ) ;
}
V_18 = V_70 ;
} else {
if ( V_83 > 0 ) {
V_70 = F_7 (
& V_85 ) ;
if ( V_70 > V_21 )
V_21 = V_70 ;
} else {
V_70 = F_9 (
& V_85 ) ;
F_42 ( V_70 < 0 ) ;
}
V_20 = V_70 ;
}
}
static void F_52 ( unsigned long V_86 )
{
if ( ! F_53 ( V_87 ,
& V_88 , V_86 ) )
F_22 ( L_21 ) ;
}
static void F_54 ( struct V_22 * V_25 )
{
struct V_78 * V_58 ;
int V_89 , V_34 ;
F_55 () ;
V_58 = & V_25 -> V_58 ;
V_89 = V_25 -> V_58 . V_59 ;
V_34 = F_56 ( V_58 , V_89 ) ;
if ( V_34 >= 0 )
V_15 ++ ;
else
V_17 ++ ;
F_57 () ;
F_8 ( V_25 , NULL ) ;
}
static void F_58 ( struct V_22 * V_25 )
{
struct V_78 * V_58 ;
int V_89 , V_34 ;
F_55 () ;
V_58 = & V_25 -> V_58 ;
V_89 = V_25 -> V_58 . V_59 ;
V_34 = F_59 ( V_58 , V_89 ) ;
if ( V_34 >= 0 )
V_14 ++ ;
else
V_16 ++ ;
F_57 () ;
F_8 ( V_25 , NULL ) ;
}
int F_60 ( bool V_46 )
{
struct V_78 V_58 ;
unsigned int V_42 ;
int V_89 , V_34 , V_90 ;
struct V_23 * V_24 ;
unsigned long V_45 ;
unsigned char V_91 ;
char * V_92 ;
int V_93 , V_94 ;
unsigned char * V_95 [ 2 ] ;
struct V_72 V_73 [ 2 ] ;
unsigned int V_96 [ 2 ] ;
V_95 [ 0 ] = F_5 ( V_97 ) ;
V_95 [ 1 ] = F_5 ( V_98 ) ;
F_61 () ;
V_90 = F_62 ( & V_73 [ 0 ] , & V_95 [ 0 ] , & V_96 [ 0 ] , V_46 ) ;
F_63 () ;
if ( V_90 == 0 )
goto V_53;
F_6 ( V_90 > 2 ) ;
for ( V_93 = 0 ; V_93 < V_90 ; V_93 ++ ) {
V_58 . V_59 = V_73 [ V_93 ] . V_59 ;
V_58 . V_37 = V_73 [ V_93 ] . V_37 ;
V_58 . V_60 = V_73 [ V_93 ] . V_60 ;
V_58 . V_40 = V_73 [ V_93 ] . V_40 ;
V_42 = V_96 [ V_93 ] ;
F_6 ( V_42 == 0 || V_42 > F_64 () ) ;
for ( V_92 = V_95 [ V_93 ] , V_91 = 0 , V_94 = 0 ; V_94 < V_42 ; V_94 ++ )
V_91 += * V_92 ++ ;
V_34 = F_65 ( & V_58 , V_95 [ V_93 ] , V_42 , V_46 , & V_89 ) ;
if ( V_34 != 0 ) {
if ( V_46 )
V_7 ++ ;
else
V_8 ++ ;
break;
} else {
if ( ! V_46 )
F_66 ( & V_75 ) ;
}
if ( V_46 )
V_5 ++ ;
else
V_6 ++ ;
F_61 () ;
V_24 = F_17 ( V_52 , V_58 . V_37 ) ;
F_19 ( V_45 ) ;
( void ) F_67 ( V_24 , & V_58 . V_60 , V_58 . V_40 ,
F_68 ( V_89 , V_42 , V_91 ) ) ;
F_30 ( V_45 ) ;
F_29 ( V_24 ) ;
F_63 () ;
}
V_53:
return V_90 ;
}
static void F_69 ( void )
{
struct V_99 * V_62 ;
union V_100 * V_101 ;
while ( 1 ) {
F_35 ( & V_65 ) ;
if ( F_70 ( & V_67 ) ) {
F_37 ( & V_65 ) ;
goto V_53;
}
V_62 = F_71 ( & V_67 ,
struct V_99 , V_66 ) ;
F_72 ( & V_62 -> V_66 ) ;
F_37 ( & V_65 ) ;
V_101 = (union V_100 * ) V_62 ;
switch ( V_62 -> V_63 ) {
case V_82 :
F_54 ( (struct V_22 * ) V_101 ) ;
break;
case V_64 :
F_58 ( (struct V_22 * ) V_101 ) ;
break;
default:
F_14 () ;
}
}
V_53:
return;
}
static void F_73 ( struct V_102 * V_103 )
{
static bool V_104 ;
int V_93 ;
F_6 ( F_12 () ) ;
if ( V_104 )
goto V_105;
if ( V_106 == - 1 )
goto V_105;
V_104 = true ;
if ( V_107 && V_108 ) {
for ( V_93 = 0 ; V_93 < 100 ; V_93 ++ ) {
F_69 () ;
( void ) F_60 ( true ) ;
}
}
if ( V_109 && V_110 ) {
for ( V_93 = 0 ; V_93 < 100 ; V_93 ++ ) {
F_69 () ;
( void ) F_60 ( false ) ;
}
}
V_104 = false ;
V_105:
F_52 ( V_111 ) ;
}
void T_1 F_74 ( void )
{
unsigned long V_112 = 60UL ;
V_87 =
F_75 ( L_22 ) ;
F_52 ( V_112 * V_111 ) ;
}
static T_3 F_76 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_117 )
{
int V_93 ;
char * V_92 = V_117 ;
for ( V_93 = 0 ; V_93 < V_118 ; V_93 ++ )
if ( V_119 [ V_93 ] )
V_92 += sprintf ( V_92 , L_23 , V_93 ) ;
V_92 += sprintf ( V_92 , L_24 ) ;
return V_92 - V_117 ;
}
static T_3 F_77 ( struct V_113 * V_114 ,
struct V_115 * V_116 , const char * V_117 , T_4 V_83 )
{
int V_120 ;
unsigned long V_121 ;
V_120 = F_78 ( V_117 , 10 , & V_121 ) ;
if ( V_120 ) {
F_22 ( L_25 ) ;
return - V_122 ;
}
if ( V_121 >= V_118 ) {
F_22 ( L_26 , V_121 ) ;
return - V_122 ;
}
if ( V_119 [ V_121 ] ) {
F_22 ( L_27 ,
( int ) V_121 ) ;
} else {
V_119 [ V_121 ] = true ;
F_79 ( ( int ) V_121 ) ;
}
return V_83 ;
}
static T_3 F_80 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_117 )
{
if ( V_106 == - 1UL )
return sprintf ( V_117 , L_28 ) ;
else
return sprintf ( V_117 , L_29 , V_106 ) ;
}
static T_3 F_81 ( struct V_113 * V_114 ,
struct V_115 * V_116 , const char * V_117 , T_4 V_83 )
{
int V_120 ;
unsigned long V_121 ;
V_120 = F_78 ( V_117 , 10 , & V_121 ) ;
if ( V_120 ) {
F_22 ( L_25 ) ;
return - V_122 ;
} else if ( V_121 == - 1UL ) {
F_22 ( L_30
L_31 ) ;
return - V_122 ;
} else if ( V_121 >= V_118 ) {
F_22 ( L_26 , V_121 ) ;
return - V_122 ;
} else if ( ! V_119 [ V_121 ] ) {
F_22 ( L_32
L_33 , ( int ) V_121 ) ;
} else if ( F_82 ( ( int ) V_121 ) >= 0 ) {
F_83 ( L_34 ,
( int ) V_121 ) ;
V_106 = ( int ) V_121 ;
} else {
F_22 ( L_35 ,
( int ) V_121 ) ;
return - V_122 ;
}
return V_83 ;
}
static void F_84 ( void )
{
static unsigned long V_123 ;
static unsigned long V_124 ;
static unsigned long V_125 ;
V_124 = V_123 ;
V_123 = F_85 () ;
if ( ! V_123 ||
( V_123 > V_124 ) ) {
V_126 = V_127 ;
return;
}
if ( V_126 && -- V_126 )
return;
if ( V_123 <= V_128 )
V_125 = 0 ;
else
V_125 = V_123 -
( V_123 / V_128 ) ;
F_86 ( V_125 ) ;
}
static int T_1 F_87 ( char * V_129 )
{
V_130 = false ;
return 1 ;
}
static void F_88 ( struct V_102 * V_103 )
{
if ( V_131 && V_132 ) {
F_84 () ;
F_89 ( & V_133 ,
V_134 * V_111 ) ;
}
}
void F_90 ( int V_135 )
{
unsigned char * V_136 = F_91 ( V_137 , V_138 | V_139 ) ;
unsigned char * V_140 = F_91 ( V_137 , V_138 | V_139 ) ;
F_6 ( ! V_136 || ! V_140 ) ;
F_92 ( V_97 , V_135 ) = V_136 ;
F_92 ( V_98 , V_135 ) = V_140 ;
}
void F_93 ( int V_135 )
{
struct V_26 * V_27 ;
F_94 ( F_92 ( V_97 , V_135 ) ) ;
F_92 ( V_97 , V_135 ) = NULL ;
F_94 ( F_92 ( V_98 , V_135 ) ) ;
F_92 ( V_98 , V_135 ) = NULL ;
V_27 = & F_92 ( V_28 , V_135 ) ;
if ( V_27 -> V_25 ) {
F_10 ( V_33 , V_27 -> V_25 ) ;
V_27 -> V_25 = NULL ;
}
}
void F_95 ( struct V_141 * V_142 )
{
V_142 -> V_143 = F_32 ;
V_142 -> V_144 = F_31 ;
V_142 -> V_145 = F_48 ;
V_142 -> V_146 = F_47 ;
V_142 -> V_147 = F_43 ;
V_142 -> V_148 = F_38 ;
}
void T_1 F_96 ( bool V_149 , bool V_150 ,
bool V_151 )
{
int V_34 = 0 ;
if ( V_149 )
V_107 = true ;
if ( V_150 )
V_109 = true ;
if ( V_151 )
V_74 = true ;
F_1 () ;
V_34 = F_97 ( V_152 , & V_153 ) ;
if ( V_34 )
F_22 ( L_36 ) ;
( void ) F_98 () ;
F_99 ( & V_67 ) ;
V_33 = F_100 ( L_37 ,
sizeof( struct V_22 ) , 0 , 0 , NULL ) ;
V_131 = V_130 ;
if ( V_131 ) {
F_83 ( L_38 ) ;
F_89 ( & V_133 ,
V_134 * V_111 ) ;
}
F_74 () ;
}
