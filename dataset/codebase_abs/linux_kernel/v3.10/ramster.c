static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
V_6 = & F_2 ( V_7 ) ;
V_4 = V_6 -> V_4 ;
F_3 ( V_4 == NULL ) ;
V_6 -> V_4 = NULL ;
F_4 () ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
F_6 () ;
F_3 ( V_8 < 0 ) ;
F_7 ( V_9 , V_4 ) ;
}
int F_8 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
struct V_1 * V_4 ;
int V_10 = - V_11 ;
F_3 ( ! F_9 () ) ;
if ( F_10 ( V_9 == NULL ) )
F_11 () ;
V_6 = & F_2 ( V_7 ) ;
V_4 = F_12 ( V_9 , V_12 ) ;
if ( F_10 ( V_4 == NULL ) && V_6 -> V_4 == NULL )
F_11 () ;
else if ( V_6 -> V_4 == NULL )
V_6 -> V_4 = V_4 ;
else
F_7 ( V_9 , V_4 ) ;
return V_10 ;
}
int F_13 ( int V_13 , struct V_14 * V_15 , T_1 V_16 ,
char * V_17 , unsigned int V_18 , void * V_19 )
{
int V_10 = - V_20 ;
unsigned long V_21 ;
struct V_2 * V_3 ;
bool V_22 , V_23 = false ;
void * V_24 , * V_25 ;
struct V_26 * V_27 ;
V_3 = F_14 ( V_28 , V_13 ) ;
if ( F_10 ( V_3 == NULL ) )
goto V_29;
V_22 = F_15 ( V_3 ) ;
F_16 ( V_21 ) ;
V_24 = F_17 ( V_3 , V_15 , V_16 , & V_27 , & V_25 ) ;
if ( V_24 == NULL ) {
#ifdef F_18
F_19 ( L_1 ) ;
#endif
if ( V_22 )
F_20 () ;
else
F_21 () ;
V_27 = NULL ;
goto V_30;
} else if ( F_10 ( ! F_22 ( V_24 ) ) ) {
#ifdef F_18
F_19 ( L_2 ) ;
#endif
if ( V_22 )
F_20 () ;
else
F_21 () ;
V_27 = NULL ;
V_24 = NULL ;
V_10 = - V_31 ;
goto V_30;
} else if ( V_18 == 0 ) {
V_24 = NULL ;
if ( V_22 )
F_20 () ;
else
F_11 () ;
V_23 = true ;
goto V_30;
}
if ( F_23 ( V_24 ) ) {
F_3 ( V_22 ) ;
V_24 = F_24 ( V_24 ) ;
F_25 ( V_24 , V_17 , V_18 ) ;
} else {
V_24 = NULL ;
V_27 = NULL ;
}
F_3 ( V_19 == NULL ) ;
F_26 ( V_17 , V_18 , (struct V_32 * ) V_19 ) ;
if ( V_22 )
F_27 () ;
else
F_28 () ;
V_10 = 0 ;
V_30:
F_29 ( V_27 , V_16 , V_24 , V_25 , V_23 ) ;
F_30 ( V_3 ) ;
F_31 ( V_21 ) ;
V_29:
return V_10 ;
}
void F_32 ( struct V_26 * V_27 )
{
V_27 -> V_19 = NULL ;
}
void F_33 ( struct V_2 * V_3 , struct V_26 * V_27 ,
bool V_33 )
{
struct V_1 * V_4 ;
F_3 ( F_34 () ) ;
if ( V_27 -> V_19 == NULL )
return;
if ( V_33 && F_15 ( V_3 ) )
return;
F_3 ( ! F_22 ( V_27 -> V_19 ) ) ;
V_4 = F_1 ( V_3 ) ;
V_4 -> V_34 . V_35 = F_35 ( V_27 -> V_19 ) ;
V_4 -> V_34 . V_13 = V_3 -> V_13 ;
V_4 -> V_34 . V_36 = V_27 -> V_36 ;
V_4 -> V_34 . V_16 = V_37 ;
V_4 -> V_38 . V_39 = V_40 ;
F_36 ( & V_41 ) ;
F_37 ( & V_4 -> V_38 . V_42 , & V_43 ) ;
F_38 ( & V_41 ) ;
}
void * F_39 ( void * V_24 , struct V_2 * V_3 ,
struct V_14 * V_15 , T_1 V_16 ,
bool * V_44 )
{
int V_45 = F_40 ( V_24 ) , V_46 ;
void * V_47 = NULL ;
unsigned long V_21 ;
struct V_48 V_49 ;
F_3 ( ! F_22 ( V_24 ) ) ;
F_3 ( F_15 ( V_3 ) ) ;
if ( V_50 )
goto V_29;
if ( F_23 ( V_24 ) ) {
* V_44 = true ;
goto V_29;
}
* V_44 = false ;
F_16 ( V_21 ) ;
V_49 . V_35 = F_35 ( V_24 ) ;
V_49 . V_13 = V_3 -> V_13 ;
V_49 . V_36 = * V_15 ;
V_49 . V_16 = V_16 ;
V_47 = F_41 ( NULL , V_45 , true , false , & V_49 ) ;
if ( V_47 != NULL ) {
V_47 = F_42 ( V_47 ) ;
V_46 = F_43 ( & V_51 ) ;
F_44 ( V_46 < 0 ) ;
} else {
F_45 () ;
}
F_31 ( V_21 ) ;
V_29:
return V_47 ;
}
int F_46 ( void * V_52 , void * V_53 ,
struct V_2 * V_3 ,
struct V_14 * V_36 , T_1 V_16 ,
bool free , void * V_19 )
{
struct V_54 V_34 ;
int V_10 ;
if ( F_23 ( V_53 ) )
free = true ;
V_34 = F_47 ( V_28 , V_3 , V_36 , V_16 ) ;
V_10 = F_48 ( & V_34 , free ,
F_35 ( V_52 ) ,
F_40 ( V_52 ) ,
F_49 ( V_52 ) ,
V_19 ) ;
return V_10 ;
}
bool F_50 ( void * V_24 )
{
return F_22 ( V_24 ) ;
}
int F_51 ( void * V_55 , struct V_26 * V_27 )
{
int V_10 = - 1 ;
if ( V_55 != NULL ) {
if ( V_27 -> V_19 == NULL )
V_27 -> V_19 = V_55 ;
else if ( F_35 ( V_55 ) !=
F_35 ( ( void * ) ( V_27 -> V_19 ) ) )
F_11 () ;
V_10 = 0 ;
}
return V_10 ;
}
void * F_52 ( void * V_24 , struct V_2 * V_3 ,
struct V_14 * V_36 , T_1 V_16 , bool V_56 )
{
bool V_22 = F_15 ( V_3 ) ;
void * V_57 = NULL ;
int V_46 ;
F_3 ( F_34 () ) ;
F_3 ( ! F_22 ( V_24 ) ) ;
F_53 ( V_56 == false ) ;
if ( V_36 == NULL ) {
} else if ( V_22 ) {
} else if ( F_23 ( V_24 ) ) {
V_57 = F_24 ( V_24 ) ;
} else {
struct V_1 * V_4 =
F_1 ( V_3 ) ;
V_4 -> V_34 . V_35 = F_35 ( V_24 ) ;
V_4 -> V_34 . V_13 = V_3 -> V_13 ;
V_4 -> V_34 . V_36 = * V_36 ;
V_4 -> V_34 . V_16 = V_16 ;
V_4 -> V_38 . V_39 = V_58 ;
F_36 ( & V_41 ) ;
F_37 ( & V_4 -> V_38 . V_42 , & V_43 ) ;
F_38 ( & V_41 ) ;
V_46 = F_43 ( & V_51 ) ;
F_44 ( V_46 < 0 ) ;
}
return V_57 ;
}
void F_54 ( bool V_22 , int V_59 )
{
F_3 ( V_59 != 1 && V_59 != - 1 ) ;
if ( V_22 ) {
if ( V_59 > 0 ) {
F_55 () ;
} else {
F_56 () ;
#ifdef F_57
F_44 ( V_60 < 0 ) ;
#endif
}
} else {
if ( V_59 > 0 ) {
F_58 () ;
} else {
F_59 () ;
#ifdef F_57
F_44 ( V_61 < 0 ) ;
#endif
}
}
}
static void F_60 ( unsigned long V_62 )
{
if ( ! F_61 ( V_63 ,
& V_64 , V_62 ) )
F_19 ( L_3 ) ;
}
static void F_62 ( struct V_1 * V_4 )
{
struct V_54 * V_34 ;
int V_65 , V_10 ;
F_63 () ;
V_34 = & V_4 -> V_34 ;
V_65 = V_4 -> V_34 . V_35 ;
V_10 = F_64 ( V_34 , V_65 ) ;
if ( V_10 >= 0 )
F_65 () ;
else
F_66 () ;
F_67 () ;
F_5 ( V_4 , NULL ) ;
}
static void F_68 ( struct V_1 * V_4 )
{
struct V_54 * V_34 ;
int V_65 , V_10 ;
F_63 () ;
V_34 = & V_4 -> V_34 ;
V_65 = V_4 -> V_34 . V_35 ;
V_10 = F_69 ( V_34 , V_65 ) ;
if ( V_10 >= 0 )
F_70 () ;
else
F_71 () ;
F_67 () ;
F_5 ( V_4 , NULL ) ;
}
int F_72 ( bool V_22 )
{
struct V_54 V_34 ;
unsigned int V_18 ;
int V_65 , V_10 , V_66 ;
struct V_2 * V_3 ;
unsigned long V_21 ;
unsigned char V_67 ;
char * V_68 ;
int V_69 , V_70 ;
unsigned char * V_71 [ 2 ] ;
struct V_48 V_49 [ 2 ] ;
unsigned int V_72 [ 2 ] ;
V_71 [ 0 ] = F_2 ( V_73 ) ;
V_71 [ 1 ] = F_2 ( V_74 ) ;
F_73 () ;
V_66 = F_74 ( & V_49 [ 0 ] , & V_71 [ 0 ] , & V_72 [ 0 ] , V_22 ) ;
F_75 () ;
if ( V_66 == 0 )
goto V_29;
F_3 ( V_66 > 2 ) ;
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
V_34 . V_35 = V_49 [ V_69 ] . V_35 ;
V_34 . V_13 = V_49 [ V_69 ] . V_13 ;
V_34 . V_36 = V_49 [ V_69 ] . V_36 ;
V_34 . V_16 = V_49 [ V_69 ] . V_16 ;
V_18 = V_72 [ V_69 ] ;
F_3 ( V_18 == 0 || V_18 > F_76 () ) ;
for ( V_68 = V_71 [ V_69 ] , V_67 = 0 , V_70 = 0 ; V_70 < V_18 ; V_70 ++ )
V_67 += * V_68 ++ ;
V_10 = F_77 ( & V_34 , V_71 [ V_69 ] , V_18 , V_22 , & V_65 ) ;
if ( V_10 != 0 ) {
if ( V_22 )
F_78 () ;
else
F_79 () ;
break;
} else {
if ( ! V_22 )
F_80 ( & V_51 ) ;
}
if ( V_22 )
F_81 () ;
else
F_82 () ;
F_73 () ;
V_3 = F_14 ( V_28 , V_34 . V_13 ) ;
F_16 ( V_21 ) ;
( void ) F_83 ( V_3 , & V_34 . V_36 , V_34 . V_16 ,
F_84 ( V_65 , V_18 , V_67 ) ) ;
F_31 ( V_21 ) ;
F_30 ( V_3 ) ;
F_75 () ;
}
V_29:
return V_66 ;
}
static void F_85 ( void )
{
struct V_75 * V_38 ;
union V_76 * V_77 ;
while ( 1 ) {
F_36 ( & V_41 ) ;
if ( F_86 ( & V_43 ) ) {
F_38 ( & V_41 ) ;
goto V_29;
}
V_38 = F_87 ( & V_43 ,
struct V_75 , V_42 ) ;
F_88 ( & V_38 -> V_42 ) ;
F_38 ( & V_41 ) ;
V_77 = (union V_76 * ) V_38 ;
switch ( V_38 -> V_39 ) {
case V_58 :
F_62 ( (struct V_1 * ) V_77 ) ;
break;
case V_40 :
F_68 ( (struct V_1 * ) V_77 ) ;
break;
default:
F_11 () ;
}
}
V_29:
return;
}
static void F_89 ( struct V_78 * V_79 )
{
static bool V_80 ;
int V_69 ;
F_3 ( F_9 () ) ;
if ( V_80 )
goto V_81;
if ( V_82 == - 1 )
goto V_81;
V_80 = true ;
if ( V_83 && V_84 ) {
for ( V_69 = 0 ; V_69 < 100 ; V_69 ++ ) {
F_85 () ;
( void ) F_72 ( true ) ;
}
}
if ( V_85 && V_86 ) {
for ( V_69 = 0 ; V_69 < 100 ; V_69 ++ ) {
F_85 () ;
( void ) F_72 ( false ) ;
}
}
V_80 = false ;
V_81:
F_60 ( V_87 ) ;
}
void F_90 ( void )
{
unsigned long V_88 = 60UL ;
V_63 =
F_91 ( L_4 ) ;
F_60 ( V_88 * V_87 ) ;
}
static T_2 F_92 ( struct V_89 * V_90 ,
struct V_91 * V_92 , char * V_93 )
{
int V_69 ;
char * V_68 = V_93 ;
for ( V_69 = 0 ; V_69 < V_94 ; V_69 ++ )
if ( V_95 [ V_69 ] )
V_68 += sprintf ( V_68 , L_5 , V_69 ) ;
V_68 += sprintf ( V_68 , L_6 ) ;
return V_68 - V_93 ;
}
static T_2 F_93 ( struct V_89 * V_90 ,
struct V_91 * V_92 , const char * V_93 , T_3 V_59 )
{
int V_96 ;
unsigned long V_97 ;
V_96 = F_94 ( V_93 , 10 , & V_97 ) ;
if ( V_96 ) {
F_19 ( L_7 ) ;
return - V_98 ;
}
if ( V_97 >= V_94 ) {
F_19 ( L_8 , V_97 ) ;
return - V_98 ;
}
if ( V_95 [ V_97 ] ) {
F_19 ( L_9 ,
( int ) V_97 ) ;
} else {
V_95 [ V_97 ] = true ;
F_95 ( ( int ) V_97 ) ;
}
return V_59 ;
}
static T_2 F_96 ( struct V_89 * V_90 ,
struct V_91 * V_92 , char * V_93 )
{
if ( V_82 == - 1UL )
return sprintf ( V_93 , L_10 ) ;
else
return sprintf ( V_93 , L_11 , V_82 ) ;
}
static T_2 F_97 ( struct V_89 * V_90 ,
struct V_91 * V_92 , const char * V_93 , T_3 V_59 )
{
int V_96 ;
unsigned long V_97 ;
V_96 = F_94 ( V_93 , 10 , & V_97 ) ;
if ( V_96 ) {
F_19 ( L_7 ) ;
return - V_98 ;
} else if ( V_97 == - 1UL ) {
F_19 ( L_12
L_13 ) ;
return - V_98 ;
} else if ( V_97 >= V_94 ) {
F_19 ( L_8 , V_97 ) ;
return - V_98 ;
} else if ( ! V_95 [ V_97 ] ) {
F_19 ( L_14
L_15 , ( int ) V_97 ) ;
} else if ( F_98 ( ( int ) V_97 ) >= 0 ) {
F_99 ( L_16 ,
( int ) V_97 ) ;
V_82 = ( int ) V_97 ;
} else {
F_19 ( L_17 ,
( int ) V_97 ) ;
return - V_98 ;
}
return V_59 ;
}
static void F_100 ( void )
{
static unsigned long V_99 ;
static unsigned long V_100 ;
static unsigned long V_101 ;
V_100 = V_99 ;
V_99 = F_101 () ;
if ( ! V_99 ||
( V_99 > V_100 ) ) {
V_102 = V_103 ;
return;
}
if ( V_102 && -- V_102 )
return;
if ( V_99 <= V_104 )
V_101 = 0 ;
else
V_101 = V_99 -
( V_99 / V_104 ) ;
F_102 ( V_101 ) ;
}
static int T_4 F_103 ( char * V_105 )
{
V_106 = false ;
return 1 ;
}
static void F_104 ( struct V_78 * V_79 )
{
if ( V_107 && V_108 ) {
F_100 () ;
F_105 ( & V_109 ,
V_110 * V_87 ) ;
}
}
void F_106 ( int V_111 )
{
unsigned char * V_112 = F_107 ( V_113 , V_114 | V_115 ) ;
unsigned char * V_116 = F_107 ( V_113 , V_114 | V_115 ) ;
F_3 ( ! V_112 || ! V_116 ) ;
F_108 ( V_73 , V_111 ) = V_112 ;
F_108 ( V_74 , V_111 ) = V_116 ;
}
void F_109 ( int V_111 )
{
struct V_5 * V_6 ;
F_110 ( F_108 ( V_73 , V_111 ) ) ;
F_108 ( V_73 , V_111 ) = NULL ;
F_110 ( F_108 ( V_74 , V_111 ) ) ;
F_108 ( V_74 , V_111 ) = NULL ;
V_6 = & F_108 ( V_7 , V_111 ) ;
if ( V_6 -> V_4 ) {
F_7 ( V_9 , V_6 -> V_4 ) ;
V_6 -> V_4 = NULL ;
}
}
void F_111 ( struct V_117 * V_118 )
{
V_118 -> V_119 = F_33 ;
V_118 -> V_120 = F_32 ;
V_118 -> V_121 = F_51 ;
V_118 -> V_122 = F_50 ;
V_118 -> V_123 = F_46 ;
V_118 -> V_124 = F_39 ;
}
void F_112 ( bool V_125 , bool V_126 ,
bool V_127 ,
bool F_100 )
{
int V_10 = 0 ;
if ( V_125 )
V_83 = true ;
if ( V_126 )
V_85 = true ;
if ( V_127 )
V_50 = true ;
F_113 () ;
V_10 = F_114 ( V_128 , & V_129 ) ;
if ( V_10 )
F_19 ( L_18 ) ;
( void ) F_115 () ;
#ifdef F_116
V_10 = F_117 () ;
if ( V_10 )
F_19 ( L_19 ) ;
V_107 = F_100 ;
#else
V_107 = V_106 ;
#endif
F_118 ( & V_43 ) ;
V_9 = F_119 ( L_20 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( V_107 ) {
F_99 ( L_21 ) ;
F_105 ( & V_109 ,
V_110 * V_87 ) ;
}
F_90 () ;
}
