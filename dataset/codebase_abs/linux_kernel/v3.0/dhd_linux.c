int F_1 ( unsigned long * V_1 )
{
if ( V_2 ) {
* V_1 = V_2 -> V_3 & V_4 ;
return ( int ) V_2 -> V_5 ;
}
#ifdef F_2
return F_2 ;
#else
return - 1 ;
#endif
}
int F_3 ( int V_6 )
{
F_4 ( V_7 L_1 , V_8 , V_6 ) ;
if ( V_9 && V_9 -> V_10 )
V_9 -> V_10 ( V_6 ) ;
return 0 ;
}
int F_5 ( int V_6 , unsigned long V_11 )
{
F_4 ( V_7 L_1 , V_8 , V_6 ) ;
if ( V_9 && V_9 -> V_12 )
V_9 -> V_12 ( V_6 ) ;
if ( V_11 )
F_6 ( V_11 ) ;
return 0 ;
}
int F_7 ( int V_6 , unsigned long V_11 )
{
F_4 ( V_7 L_1 , V_8 , V_6 ) ;
if ( V_9 && V_9 -> V_13 )
V_9 -> V_13 ( V_6 ) ;
if ( V_11 )
F_6 ( V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
(struct V_16 * ) ( V_15 -> V_18 . V_19 ) ;
F_4 ( V_7 L_2 , V_8 ) ;
V_2 =
F_9 ( V_15 , V_20 ,
L_3 ) ;
V_9 = V_17 ;
F_5 ( 1 , 0 ) ;
F_3 ( 1 ) ;
F_10 ( & V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
(struct V_16 * ) ( V_15 -> V_18 . V_19 ) ;
F_4 ( V_7 L_2 , V_8 ) ;
V_9 = V_17 ;
F_3 ( 0 ) ;
F_5 ( 0 , 0 ) ;
F_10 ( & V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , T_1 V_22 )
{
F_13 ( ( L_4 , V_8 ) ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
F_13 ( ( L_4 , V_8 ) ) ;
return 0 ;
}
int F_15 ( void )
{
F_13 ( ( L_5 ) ) ;
return F_16 ( & V_23 ) ;
}
void F_17 ( void )
{
F_13 ( ( L_6 ) ) ;
F_18 ( & V_23 ) ;
}
static int F_19 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
switch ( V_26 ) {
case V_28 :
case V_29 :
F_20 ( & V_30 , true ) ;
return V_31 ;
case V_32 :
case V_33 :
F_20 ( & V_30 , false ) ;
return V_31 ;
}
return 0 ;
}
static void F_21 ( int V_34 , T_2 * V_35 )
{
#ifdef F_22
F_13 ( ( L_7 , V_8 , V_34 ) ) ;
if ( V_36 ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_37 ++ ) {
F_23 ( V_35 , V_35 -> V_39 [ V_37 ] ) ;
F_24 ( V_35 , V_35 -> V_39 [ V_37 ] ,
V_34 , V_40 ) ;
}
}
#endif
}
static int F_25 ( int V_34 , T_2 * V_35 )
{
int V_41 = V_42 ;
char V_43 [ 32 ] ;
int V_44 = 3 ;
#ifdef F_26
T_3 V_45 = 1 ;
#endif
F_13 ( ( L_8 ,
V_8 , V_34 , V_35 -> V_46 ) ) ;
if ( V_35 && V_35 -> F_10 ) {
if ( V_34 && V_35 -> V_46 ) {
F_13 ( ( L_9 ,
V_8 ) ) ;
F_27 ( V_35 , 0 , V_47 ,
( char * ) & V_41 ,
sizeof( V_41 ) ) ;
F_21 ( 1 , V_35 ) ;
if ( ( V_35 -> V_48 == 0 ) || ( V_35 -> V_48 == 1 ) )
V_44 = 3 ;
else
V_44 = V_35 -> V_48 ;
F_28 ( L_10 , ( char * ) & V_44 ,
4 , V_43 , sizeof( V_43 ) ) ;
F_27 ( V_35 , 0 , V_49 , V_43 ,
sizeof( V_43 ) ) ;
#ifdef F_26
F_28 ( L_11 , ( char * ) & V_45 , 4 ,
V_43 , sizeof( V_43 ) ) ;
F_27 ( V_35 , 0 , V_49 , V_43 ,
sizeof( V_43 ) ) ;
#endif
} else {
F_13 ( ( L_12 ,
V_8 ) ) ;
V_41 = V_50 ;
F_27 ( V_35 , 0 , V_47 ,
( char * ) & V_41 ,
sizeof( V_41 ) ) ;
F_21 ( 0 , V_35 ) ;
F_28 ( L_10 , ( char * ) & V_35 -> V_48 ,
4 , V_43 , sizeof( V_43 ) ) ;
F_27 ( V_35 , 0 , V_49 , V_43 ,
sizeof( V_43 ) ) ;
#ifdef F_26
V_45 = 0 ;
F_28 ( L_11 , ( char * ) & V_45 , 4 , V_43 ,
sizeof( V_43 ) ) ;
F_27 ( V_35 , 0 , V_49 , V_43 ,
sizeof( V_43 ) ) ;
#endif
}
}
return 0 ;
}
static void F_29 ( struct V_51 * V_35 , int V_52 )
{
T_2 * V_53 = & V_35 -> V_54 ;
F_30 ( V_53 ) ;
V_53 -> V_46 = V_52 ;
if ( ! V_53 -> V_55 )
F_25 ( V_52 , V_53 ) ;
F_31 ( V_53 ) ;
}
static void F_32 ( struct V_56 * V_57 )
{
struct V_51 * V_35 = F_33 ( V_57 , struct V_51 , V_56 ) ;
F_13 ( ( L_13 , V_8 ) ) ;
if ( V_35 )
F_29 ( V_35 , 1 ) ;
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_51 * V_35 = F_33 ( V_57 , struct V_51 , V_56 ) ;
F_13 ( ( L_13 , V_8 ) ) ;
if ( V_35 )
F_29 ( V_35 , 0 ) ;
}
void F_35 ( T_4 * V_58 , T_3 V_59 )
{
V_58 -> V_60 = V_59 ;
V_58 -> V_61 = 0 ;
V_58 -> V_62 = 0 ;
V_58 -> V_63 = 1000000 / V_64 ;
}
int F_36 ( T_4 * V_58 )
{
if ( V_58 -> V_61 == 0 ) {
V_58 -> V_61 = 1 ;
return 0 ;
}
if ( V_58 -> V_62 >= V_58 -> V_60 )
return 1 ;
V_58 -> V_62 += V_58 -> V_61 ;
if ( V_58 -> V_61 < V_58 -> V_63 ) {
F_37 ( V_58 -> V_61 ) ;
V_58 -> V_61 *= 2 ;
if ( V_58 -> V_61 > V_58 -> V_63 )
V_58 -> V_61 = V_58 -> V_63 ;
} else {
T_5 V_65 ;
F_38 ( V_66 , V_67 ) ;
int V_68 ;
F_39 ( & V_65 ) ;
F_40 ( & V_65 , & V_66 ) ;
F_41 ( V_69 ) ;
F_42 ( 1 ) ;
V_68 = F_43 ( V_67 ) ;
F_44 ( & V_65 , & V_66 ) ;
F_41 ( V_70 ) ;
if ( V_68 )
return 1 ;
}
return 0 ;
}
static int F_45 ( T_6 * V_35 , struct V_71 * V_72 )
{
int V_37 = 0 ;
ASSERT ( V_35 ) ;
while ( V_37 < V_73 ) {
if ( V_35 -> V_74 [ V_37 ] && ( V_35 -> V_74 [ V_37 ] -> V_72 == V_72 ) )
return V_37 ;
V_37 ++ ;
}
return V_75 ;
}
int F_46 ( T_6 * V_35 , char * V_76 )
{
int V_37 = V_73 ;
ASSERT ( V_35 ) ;
if ( V_76 == NULL || * V_76 == '\0' )
return 0 ;
while ( -- V_37 > 0 )
if ( V_35 -> V_74 [ V_37 ]
&& ! strncmp ( V_35 -> V_74 [ V_37 ] -> V_76 , V_76 , V_77 ) )
break;
F_13 ( ( L_14 , V_8 , V_37 , V_76 ) ) ;
return V_37 ;
}
char * F_47 ( T_2 * V_53 , int V_78 )
{
T_6 * V_35 = ( T_6 * ) V_53 -> V_79 ;
ASSERT ( V_35 ) ;
if ( V_78 < 0 || V_78 >= V_73 ) {
F_48 ( ( L_15 , V_8 , V_78 ) ) ;
return L_16 ;
}
if ( V_35 -> V_74 [ V_78 ] == NULL ) {
F_48 ( ( L_17 , V_8 , V_78 ) ) ;
return L_18 ;
}
if ( V_35 -> V_74 [ V_78 ] -> V_72 )
return V_35 -> V_74 [ V_78 ] -> V_72 -> V_76 ;
return L_19 ;
}
static void F_49 ( T_6 * V_35 , int V_78 )
{
struct V_71 * V_18 ;
struct V_80 * V_81 ;
T_7 V_82 , V_83 ;
T_8 V_84 ;
char * V_85 , * V_86 ;
T_3 V_87 ;
int V_88 ;
ASSERT ( V_35 && V_35 -> V_74 [ V_78 ] ) ;
V_18 = V_35 -> V_74 [ V_78 ] -> V_72 ;
V_83 = F_50 ( V_18 ) ;
V_82 = ( V_18 -> V_3 & V_89 ) ? true : false ;
V_87 = sizeof( L_20 ) + sizeof( V_83 ) + ( V_83 * V_90 ) ;
V_86 = V_85 = F_51 ( V_87 , V_91 ) ;
if ( ! V_86 ) {
F_48 ( ( L_21 ,
F_47 ( & V_35 -> V_54 , V_78 ) , V_83 ) ) ;
return;
}
strcpy ( V_86 , L_20 ) ;
V_86 += strlen ( L_20 ) + 1 ;
V_83 = F_52 ( V_83 ) ;
memcpy ( V_86 , & V_83 , sizeof( V_83 ) ) ;
V_86 += sizeof( V_83 ) ;
F_53 (ha, dev) {
if ( ! V_83 )
break;
memcpy ( V_86 , V_81 -> V_92 , V_90 ) ;
V_86 += V_90 ;
V_83 -- ;
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_49 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = V_87 ;
V_84 . V_95 = true ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_22 ,
F_47 ( & V_35 -> V_54 , V_78 ) , V_83 ) ) ;
V_82 = V_83 ? true : V_82 ;
}
F_55 ( V_85 ) ;
V_87 = sizeof( L_23 ) + sizeof( V_82 ) ;
V_85 = F_51 ( V_87 , V_91 ) ;
if ( ! V_85 ) {
F_48 ( ( L_24 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
return;
}
V_82 = F_52 ( V_82 ) ;
if ( ! F_28
( L_23 , ( void * ) & V_82 , sizeof( V_82 ) , V_85 , V_87 ) ) {
F_48 ( ( L_25
L_26 , F_47 ( & V_35 -> V_54 , V_78 ) ,
( int ) sizeof( V_82 ) , V_87 ) ) ;
F_55 ( V_85 ) ;
return;
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_49 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = V_87 ;
V_84 . V_95 = true ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_27 ,
F_47 ( & V_35 -> V_54 , V_78 ) ,
F_56 ( V_82 ) ) ) ;
}
F_55 ( V_85 ) ;
V_82 = ( V_18 -> V_3 & V_96 ) ? true : false ;
V_82 = F_52 ( V_82 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_97 ;
V_84 . V_85 = & V_82 ;
V_84 . V_94 = sizeof( V_82 ) ;
V_84 . V_95 = true ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_28 ,
F_47 ( & V_35 -> V_54 , V_78 ) ,
F_56 ( V_82 ) ) ) ;
}
}
static int
F_57 ( T_6 * V_35 , int V_78 , T_9 * V_92 )
{
char V_85 [ 32 ] ;
T_8 V_84 ;
int V_88 ;
F_13 ( ( L_29 , V_8 ) ) ;
if ( ! F_28
( L_30 , ( char * ) V_92 , V_90 , V_85 , 32 ) ) {
F_48 ( ( L_31 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
return - 1 ;
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_49 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = 32 ;
V_84 . V_95 = true ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_32 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
} else {
memcpy ( V_35 -> V_74 [ V_78 ] -> V_72 -> V_98 , V_92 , V_90 ) ;
}
return V_88 ;
}
static void F_58 ( T_10 * V_99 )
{
T_6 * V_35 ;
int V_88 = 0 , V_100 = 0 ;
ASSERT ( V_99 && V_99 -> V_79 && V_99 -> V_101 ) ;
V_35 = V_99 -> V_79 ;
F_13 ( ( L_33 , V_8 , V_99 -> V_101 , V_99 -> V_22 ) ) ;
switch ( V_99 -> V_22 ) {
case V_102 :
if ( V_99 -> V_72 != NULL ) {
F_48 ( ( L_34
L_35 ,
V_8 , V_99 -> V_72 -> V_76 ) ) ;
F_59 ( V_99 -> V_72 ) ;
F_60 ( V_99 -> V_72 ) ;
F_61 ( V_99 -> V_72 ) ;
}
V_99 -> V_72 = F_62 ( sizeof( V_35 ) ) ;
if ( ! V_99 -> V_72 ) {
F_48 ( ( L_36 , V_8 ) ) ;
V_88 = - V_103 ;
}
if ( V_88 == 0 ) {
strcpy ( V_99 -> V_72 -> V_76 , V_99 -> V_76 ) ;
memcpy ( F_63 ( V_99 -> V_72 ) , & V_35 , sizeof( V_35 ) ) ;
V_100 = F_64 ( & V_35 -> V_54 , V_99 -> V_101 ) ;
if ( V_100 != 0 ) {
F_48 ( ( L_37
L_38 ,
V_8 , V_100 ) ) ;
V_88 = - V_104 ;
} else {
#ifdef F_65
extern struct V_105 V_106 ;
V_107 = V_99 -> V_72 ;
F_10 ( & V_106 ) ;
#endif
F_13 ( ( L_39
L_40 ,
V_67 -> V_108 , V_99 -> V_72 -> V_76 ) ) ;
V_99 -> V_22 = 0 ;
}
}
break;
case V_109 :
if ( V_99 -> V_72 != NULL ) {
F_13 ( ( L_41 ,
V_8 ) ) ;
F_59 ( V_99 -> V_72 ) ;
F_60 ( V_99 -> V_72 ) ;
V_88 = V_110 ;
}
break;
default:
F_48 ( ( L_42 , V_8 , V_99 -> V_22 ) ) ;
ASSERT ( ! V_99 -> V_22 ) ;
break;
}
if ( V_88 < 0 ) {
if ( V_99 -> V_72 )
F_61 ( V_99 -> V_72 ) ;
V_35 -> V_74 [ V_99 -> V_101 ] = NULL ;
F_55 ( V_99 ) ;
#ifdef F_65
if ( V_99 -> V_72 == V_107 )
V_107 = NULL ;
#endif
}
}
static int F_66 ( void * V_111 )
{
T_6 * V_35 = ( T_6 * ) V_111 ;
int V_37 ;
#ifdef F_65
bool V_112 = false ;
#endif
F_67 ( V_113 ) ;
while ( F_68 ( & V_35 -> V_114 ) == 0 ) {
if ( F_69 () )
break;
for ( V_37 = 0 ; V_37 < V_73 ; V_37 ++ ) {
if ( V_35 -> V_74 [ V_37 ] ) {
#ifdef F_65
V_112 = ( V_107 != NULL ) ;
#endif
if ( V_35 -> V_74 [ V_37 ] -> V_22 )
F_58 ( V_35 -> V_74 [ V_37 ] ) ;
#ifdef F_65
if ( V_35 -> V_74 [ V_37 ] == NULL ) {
F_13 ( ( L_43
L_44 , V_8 , V_37 ) ) ;
continue;
}
if ( V_112 && V_35 -> V_115 ) {
F_13 ( ( L_45
L_46 L_47 ,
V_35 -> V_74 [ V_37 ] -> V_72 -> V_76 ) ) ;
V_35 -> V_115 = false ;
continue;
}
if ( V_112 && V_35 -> V_116 ) {
F_13 ( ( L_48 L_49 ,
V_35 -> V_74 [ V_37 ] -> V_72 -> V_76 ) ) ;
V_35 -> V_116 = false ;
continue;
}
#endif
if ( V_35 -> V_116 ) {
V_35 -> V_116 = false ;
F_49 ( V_35 , V_37 ) ;
}
if ( V_35 -> V_115 ) {
V_35 -> V_115 = false ;
F_57 ( V_35 , V_37 ,
V_35 -> V_117 ) ;
}
}
}
}
return 0 ;
}
static int F_70 ( struct V_71 * V_18 , void * V_92 )
{
int V_88 = 0 ;
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
struct V_118 * V_119 = (struct V_118 * ) V_92 ;
int V_78 ;
V_78 = F_45 ( V_35 , V_18 ) ;
if ( V_78 == V_75 )
return - 1 ;
ASSERT ( V_35 -> V_120 ) ;
memcpy ( & V_35 -> V_117 , V_119 -> V_121 , V_90 ) ;
V_35 -> V_115 = true ;
F_10 ( & V_35 -> V_114 ) ;
return V_88 ;
}
static void F_71 ( struct V_71 * V_18 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
int V_78 ;
V_78 = F_45 ( V_35 , V_18 ) ;
if ( V_78 == V_75 )
return;
ASSERT ( V_35 -> V_120 ) ;
V_35 -> V_116 = true ;
F_10 ( & V_35 -> V_114 ) ;
}
int F_72 ( T_2 * V_53 , int V_78 , struct V_122 * V_123 )
{
int V_88 ;
T_6 * V_35 = ( T_6 * ) ( V_53 -> V_79 ) ;
if ( ! V_53 -> F_10 || ( V_53 -> V_124 == V_125 ) )
return - V_126 ;
if ( V_123 -> V_94 >= V_90 ) {
T_9 * V_127 = ( T_9 * ) ( V_123 -> V_111 ) ;
struct V_128 * V_129 = (struct V_128 * ) V_127 ;
if ( F_73 ( V_129 -> V_130 ) )
V_53 -> V_131 ++ ;
if ( F_74 ( V_129 -> V_132 ) == V_133 )
F_75 ( & V_35 -> V_134 ) ;
}
F_76 ( V_53 , V_78 , V_123 ) ;
#ifdef F_77
V_88 = F_78 ( V_53 -> V_135 , V_123 , NULL ) ;
#else
V_88 = F_79 ( V_53 -> V_136 , V_123 ) ;
#endif
return V_88 ;
}
static inline void *
F_80 ( struct V_122 * V_137 )
{
return ( void * ) V_137 ;
}
static inline struct V_122 *
F_81 ( void * V_138 )
{
return (struct V_122 * ) V_138 ;
}
static int F_82 ( struct V_122 * V_137 , struct V_71 * V_72 )
{
int V_88 ;
void * V_123 ;
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
int V_78 ;
F_13 ( ( L_50 , V_8 ) ) ;
if ( ! V_35 -> V_54 . F_10 || ( V_35 -> V_54 . V_124 == V_125 ) ) {
F_48 ( ( L_51 ,
V_8 , V_35 -> V_54 . F_10 , V_35 -> V_54 . V_124 ) ) ;
F_59 ( V_72 ) ;
return - V_126 ;
}
V_78 = F_45 ( V_35 , V_72 ) ;
if ( V_78 == V_75 ) {
F_48 ( ( L_52 , V_8 , V_78 ) ) ;
F_59 ( V_72 ) ;
return - V_126 ;
}
if ( F_83 ( V_137 ) < V_35 -> V_54 . V_139 ) {
struct V_122 * V_140 ;
F_84 ( ( L_53 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
V_35 -> V_54 . V_141 ++ ;
V_140 = F_85 ( V_137 , V_35 -> V_54 . V_139 ) ;
F_86 ( V_137 ) ;
V_137 = V_140 ;
if ( V_137 == NULL ) {
F_48 ( ( L_54 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
V_88 = - V_103 ;
goto V_142;
}
}
V_123 = F_87 ( V_35 -> V_54 . V_143 , V_137 ) ;
if ( ! V_123 ) {
F_48 ( ( L_55 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
F_88 ( V_137 ) ;
V_88 = - V_103 ;
goto V_142;
}
V_88 = F_72 ( & V_35 -> V_54 , V_78 , V_123 ) ;
V_142:
if ( V_88 )
V_35 -> V_54 . V_144 . V_145 ++ ;
else
V_35 -> V_54 . V_146 ++ ;
return 0 ;
}
void F_89 ( T_2 * V_53 , int V_78 , bool V_22 )
{
struct V_71 * V_72 ;
T_6 * V_35 = V_53 -> V_79 ;
F_13 ( ( L_50 , V_8 ) ) ;
V_53 -> V_147 = V_22 ;
ASSERT ( V_35 && V_35 -> V_74 [ V_78 ] ) ;
V_72 = V_35 -> V_74 [ V_78 ] -> V_72 ;
if ( V_22 == V_148 )
F_59 ( V_72 ) ;
else
F_90 ( V_72 ) ;
}
void F_91 ( T_2 * V_53 , int V_78 , struct V_122 * V_123 ,
int V_149 )
{
T_6 * V_35 = ( T_6 * ) V_53 -> V_79 ;
struct V_122 * V_137 ;
unsigned char * V_150 ;
T_3 V_94 ;
void * V_111 ;
struct V_122 * V_151 , * V_152 ;
int V_37 ;
T_10 * V_99 ;
T_11 V_153 ;
F_13 ( ( L_50 , V_8 ) ) ;
V_152 = V_123 ;
for ( V_37 = 0 ; V_123 && V_37 < V_149 ; V_37 ++ , V_123 = V_151 ) {
V_151 = V_123 -> V_154 ;
V_123 -> V_154 = NULL ;
V_137 = F_92 ( V_53 -> V_143 , V_123 ) ;
V_150 = V_137 -> V_111 ;
V_94 = V_137 -> V_94 ;
V_99 = V_35 -> V_74 [ V_78 ] ;
if ( V_99 == NULL )
V_99 = V_35 -> V_74 [ 0 ] ;
ASSERT ( V_99 ) ;
V_137 -> V_18 = V_99 -> V_72 ;
V_137 -> V_155 = F_93 ( V_137 , V_137 -> V_18 ) ;
if ( V_137 -> V_156 == V_157 )
V_35 -> V_54 . V_158 ++ ;
V_137 -> V_111 = V_150 ;
V_137 -> V_94 = V_94 ;
F_94 ( V_137 , V_159 ) ;
if ( F_74 ( V_137 -> V_155 ) == V_160 )
F_95 ( V_35 , & V_78 ,
F_96 ( V_137 ) ,
& V_153 , & V_111 ) ;
ASSERT ( V_78 < V_73 && V_35 -> V_74 [ V_78 ] ) ;
if ( V_35 -> V_74 [ V_78 ] && ! V_35 -> V_74 [ V_78 ] -> V_22 )
V_99 = V_35 -> V_74 [ V_78 ] ;
if ( V_99 -> V_72 )
V_99 -> V_72 -> V_161 = V_162 ;
V_53 -> V_144 . V_163 += V_137 -> V_94 ;
V_53 -> V_164 ++ ;
if ( F_97 () ) {
F_98 ( V_137 ) ;
} else {
F_99 ( V_137 ) ;
}
}
}
void F_100 ( struct V_51 * V_35 , char * V_165 , int V_166 , int V_78 )
{
return;
}
void F_101 ( T_2 * V_53 , struct V_122 * V_167 , bool V_168 )
{
T_3 V_78 ;
T_6 * V_35 = ( T_6 * ) ( V_53 -> V_79 ) ;
struct V_128 * V_129 ;
T_12 type ;
F_102 ( V_53 , & V_78 , V_167 ) ;
V_129 = (struct V_128 * ) ( V_167 -> V_111 ) ;
type = F_74 ( V_129 -> V_132 ) ;
if ( type == V_133 )
F_103 ( & V_35 -> V_134 ) ;
}
static struct V_169 * F_104 ( struct V_71 * V_72 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
T_10 * V_99 ;
int V_78 ;
F_13 ( ( L_50 , V_8 ) ) ;
V_78 = F_45 ( V_35 , V_72 ) ;
if ( V_78 == V_75 )
return NULL ;
V_99 = V_35 -> V_74 [ V_78 ] ;
ASSERT ( V_35 && V_99 ) ;
if ( V_35 -> V_54 . F_10 ) {
F_105 ( & V_35 -> V_54 ) ;
}
V_99 -> V_170 . V_164 = V_35 -> V_54 . V_144 . V_164 ;
V_99 -> V_170 . V_146 = V_35 -> V_54 . V_144 . V_146 ;
V_99 -> V_170 . V_163 = V_35 -> V_54 . V_144 . V_163 ;
V_99 -> V_170 . V_171 = V_35 -> V_54 . V_144 . V_171 ;
V_99 -> V_170 . V_172 = V_35 -> V_54 . V_144 . V_172 ;
V_99 -> V_170 . V_173 = V_35 -> V_54 . V_144 . V_173 ;
V_99 -> V_170 . V_174 = V_35 -> V_54 . V_144 . V_174 ;
V_99 -> V_170 . V_145 = V_35 -> V_54 . V_144 . V_145 ;
V_99 -> V_170 . V_175 = V_35 -> V_54 . V_144 . V_175 ;
return & V_99 -> V_170 ;
}
static int F_106 ( void * V_111 )
{
T_6 * V_35 = ( T_6 * ) V_111 ;
#ifdef F_107
if ( V_176 > 0 ) {
struct V_177 V_178 ;
V_178 . V_179 = ( V_176 < V_180 ) ?
V_176 : ( V_180 - 1 ) ;
F_108 ( V_67 , V_181 , & V_178 ) ;
}
#endif
F_67 ( V_113 ) ;
while ( 1 ) {
if ( F_69 () )
break;
if ( F_68 ( & V_35 -> V_182 ) == 0 ) {
if ( V_35 -> V_54 . V_183 == false ) {
F_109 ( & V_35 -> V_54 ) ;
}
V_35 -> V_54 . V_184 ++ ;
} else
break;
}
return 0 ;
}
static void F_110 ( unsigned long V_111 )
{
T_6 * V_35 = ( T_6 * ) V_111 ;
if ( V_35 -> V_185 ) {
F_10 ( & V_35 -> V_182 ) ;
if ( V_35 -> V_186 ) {
F_111 ( & V_35 -> V_187 ,
V_162 + V_188 * V_64 / 1000 ) ;
}
return;
}
F_109 ( & V_35 -> V_54 ) ;
V_35 -> V_54 . V_184 ++ ;
if ( V_35 -> V_186 )
F_111 ( & V_35 -> V_187 , V_162 + V_188 * V_64 / 1000 ) ;
}
static int F_112 ( void * V_111 )
{
T_6 * V_35 = ( T_6 * ) V_111 ;
#ifdef F_107
if ( V_189 > 0 ) {
struct V_177 V_178 ;
V_178 . V_179 =
( V_189 <
V_180 ) ? V_189 : ( V_180 - 1 ) ;
F_108 ( V_67 , V_181 , & V_178 ) ;
}
#endif
F_67 ( V_113 ) ;
while ( 1 ) {
if ( F_69 () )
break;
if ( F_68 ( & V_35 -> V_190 ) == 0 ) {
if ( V_35 -> V_54 . V_124 != V_125 ) {
if ( F_113 ( V_35 -> V_54 . V_136 ) ) {
F_10 ( & V_35 -> V_190 ) ;
}
} else {
F_114 ( V_35 -> V_54 . V_136 , true ) ;
}
} else
break;
}
return 0 ;
}
static void F_115 ( unsigned long V_111 )
{
T_6 * V_35 ;
V_35 = ( T_6 * ) V_111 ;
if ( V_35 -> V_54 . V_124 != V_125 ) {
if ( F_113 ( V_35 -> V_54 . V_136 ) )
F_116 ( & V_35 -> V_191 ) ;
} else {
F_114 ( V_35 -> V_54 . V_136 , true ) ;
}
}
void F_117 ( T_2 * V_53 )
{
T_6 * V_35 = ( T_6 * ) V_53 -> V_79 ;
if ( V_35 -> V_192 ) {
F_10 ( & V_35 -> V_190 ) ;
return;
}
F_116 ( & V_35 -> V_191 ) ;
}
static int F_118 ( T_6 * V_35 , int V_78 , T_7 * V_193 )
{
T_8 V_84 ;
char V_85 [ 32 ] ;
int V_88 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_194 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = ( T_3 ) sizeof( V_85 ) ;
V_84 . V_95 = false ;
strcpy ( V_85 , L_56 ) ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
if ( V_88 == - V_195 ) {
F_48 ( ( L_57 ,
F_47 ( & V_35 -> V_54 , V_78 ) ) ) ;
return - V_104 ;
}
F_84 ( ( L_58 ,
F_47 ( & V_35 -> V_54 , V_78 ) , V_88 ) ) ;
return V_88 ;
}
memcpy ( V_193 , V_85 , sizeof( T_7 ) ) ;
return 0 ;
}
static int F_119 ( T_6 * V_35 , int V_78 , T_7 V_193 )
{
T_8 V_84 ;
char V_85 [ 32 ] ;
int V_196 , V_88 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_49 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = ( T_3 ) sizeof( V_85 ) ;
V_84 . V_95 = true ;
strcpy ( V_85 , L_56 ) ;
memcpy ( & V_85 [ sizeof( L_56 ) ] , & V_193 , sizeof( T_7 ) ) ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_59 ,
F_47 ( & V_35 -> V_54 , V_78 ) , V_88 ) ) ;
return V_88 ;
}
V_196 = ( V_193 != 0 ) ;
strcpy ( V_85 , L_60 ) ;
memcpy ( & V_85 [ sizeof( L_60 ) ] , & V_196 , sizeof( T_7 ) ) ;
V_88 = F_54 ( & V_35 -> V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( V_88 < 0 ) {
F_48 ( ( L_61 ,
F_47 ( & V_35 -> V_54 , V_78 ) , V_88 ) ) ;
return V_88 ;
}
return 0 ;
}
static void F_120 ( struct V_71 * V_72 ,
struct V_197 * V_79 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
sprintf ( V_79 -> V_198 , V_199 ) ;
sprintf ( V_79 -> V_200 , L_62 , V_35 -> V_54 . V_201 ) ;
sprintf ( V_79 -> V_202 , L_63 , F_121 () ) ;
sprintf ( V_79 -> V_203 , L_63 , F_122 ( & F_123 () -> V_18 ) ) ;
}
static int F_124 ( T_6 * V_35 , void * V_204 )
{
struct V_197 V_79 ;
char V_205 [ sizeof( V_79 . V_198 ) ] ;
T_7 V_93 ;
#ifdef F_125
struct V_206 V_207 ;
T_7 V_208 , V_209 ;
int V_88 ;
#endif
F_13 ( ( L_50 , V_8 ) ) ;
if ( F_126 ( & V_93 , V_204 , sizeof( T_7 ) ) )
return - V_210 ;
switch ( V_93 ) {
case V_211 :
if ( F_126 ( & V_79 , V_204 , sizeof( V_79 ) ) )
return - V_210 ;
strncpy ( V_205 , V_79 . V_198 , sizeof( V_79 . V_198 ) ) ;
V_205 [ sizeof( V_79 . V_198 ) - 1 ] = '\0' ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_93 = V_93 ;
if ( strcmp ( V_205 , L_64 ) == 0 ) {
sprintf ( V_79 . V_198 , L_65 ) ;
strcpy ( V_79 . V_200 , V_212 ) ;
}
else if ( ! V_35 -> V_54 . F_10 ) {
F_48 ( ( L_66 , V_8 ) ) ;
return - V_126 ;
}
else if ( V_35 -> V_54 . V_213 )
sprintf ( V_79 . V_198 , L_67 ) ;
else
sprintf ( V_79 . V_198 , L_68 ) ;
sprintf ( V_79 . V_200 , L_62 , V_35 -> V_54 . V_201 ) ;
if ( F_127 ( V_204 , & V_79 , sizeof( V_79 ) ) )
return - V_210 ;
F_128 ( ( L_69 , V_8 ,
( int ) sizeof( V_205 ) , V_205 , V_79 . V_198 ) ) ;
break;
#ifdef F_125
case V_214 :
case V_215 :
V_88 = F_118 ( V_35 , 0 , & V_208 ) ;
if ( V_88 < 0 )
return V_88 ;
V_209 =
( V_93 == V_215 ) ? V_216 : V_217 ;
V_207 . V_93 = V_93 ;
V_207 . V_111 = ( V_208 & V_209 ) ? 1 : 0 ;
if ( F_127 ( V_204 , & V_207 , sizeof( V_207 ) ) )
return - V_210 ;
break;
case V_218 :
case V_219 :
if ( F_126 ( & V_207 , V_204 , sizeof( V_207 ) ) )
return - V_210 ;
V_88 = F_118 ( V_35 , 0 , & V_208 ) ;
if ( V_88 < 0 )
return V_88 ;
V_209 =
( V_93 == V_219 ) ? V_216 : V_217 ;
if ( V_207 . V_111 != 0 )
V_208 |= V_209 ;
else
V_208 &= ~ V_209 ;
V_88 = F_119 ( V_35 , 0 , V_208 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( V_93 == V_219 ) {
if ( V_207 . V_111 )
V_35 -> V_74 [ 0 ] -> V_72 -> V_220 |=
V_221 ;
else
V_35 -> V_74 [ 0 ] -> V_72 -> V_220 &=
~ V_221 ;
}
break;
#endif
default:
return - V_104 ;
}
return 0 ;
}
static int F_129 ( struct V_71 * V_72 , struct V_222 * V_223 , int V_93 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
T_13 V_84 ;
int V_224 = 0 ;
int V_87 = 0 ;
void * V_85 = NULL ;
T_3 V_198 = 0 ;
int V_78 ;
bool V_225 ;
V_78 = F_45 ( V_35 , V_72 ) ;
F_13 ( ( L_70 , V_8 , V_78 , V_93 ) ) ;
if ( V_78 == V_75 )
return - 1 ;
#if F_130 ( V_226 )
if ( ( V_93 >= V_227 ) && ( V_93 <= V_228 ) ) {
return F_131 ( V_72 , V_223 , V_93 ) ;
}
#endif
if ( V_93 == V_229 )
return F_124 ( V_35 , ( void * ) V_223 -> V_230 ) ;
if ( V_93 != V_231 )
return - V_104 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( F_126 ( & V_84 , V_223 -> V_230 , sizeof( T_8 ) ) ) {
V_224 = - V_232 ;
goto V_142;
}
if ( V_84 . V_85 ) {
V_87 = F_132 ( int , V_84 . V_94 , V_233 ) ;
{
V_85 = F_51 ( V_87 , V_91 ) ;
if ( ! V_85 ) {
V_224 = - V_103 ;
goto V_142;
}
if ( F_126 ( V_85 , V_84 . V_85 , V_87 ) ) {
V_224 = - V_232 ;
goto V_142;
}
}
}
if ( ( F_126 ( & V_198 , ( char * ) V_223 -> V_230 + sizeof( T_8 ) ,
sizeof( T_3 ) ) != 0 ) ) {
V_224 = - V_232 ;
goto V_142;
}
if ( ! F_133 ( V_234 ) ) {
V_224 = - V_235 ;
goto V_142;
}
if ( V_198 == V_236 ) {
V_224 = F_134 ( ( void * ) & V_35 -> V_54 , & V_84 , V_85 , V_87 ) ;
if ( V_224 )
V_35 -> V_54 . V_224 = V_224 ;
goto V_142;
}
if ( ( V_35 -> V_54 . V_124 != V_237 ) ) {
F_48 ( ( L_71 , V_8 ) ) ;
V_224 = - V_195 ;
goto V_142;
}
if ( ! V_35 -> V_54 . V_213 ) {
V_224 = - V_195 ;
goto V_142;
}
V_225 = ( ( V_84 . V_93 == V_238 ) ||
( ( V_84 . V_93 == V_49 ) &&
! ( strncmp ( L_72 , V_84 . V_85 , 9 ) ) ) ||
( ( V_84 . V_93 == V_49 ) &&
! ( strncmp ( L_73 , V_84 . V_85 , 15 ) ) ) ) ;
if ( V_225 )
F_135 ( V_72 ) ;
V_224 =
F_54 ( & V_35 -> V_54 , V_78 , ( T_8 * ) & V_84 , V_85 , V_87 ) ;
V_142:
if ( ! V_224 && V_85 && V_84 . V_85 ) {
if ( F_127 ( V_84 . V_85 , V_85 , V_87 ) )
V_224 = - V_210 ;
}
F_55 ( V_85 ) ;
if ( V_224 > 0 )
V_224 = 0 ;
return V_224 ;
}
static int F_136 ( struct V_71 * V_72 )
{
#if ! F_130 ( V_239 )
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
F_13 ( ( L_50 , V_8 ) ) ;
if ( F_137 () ) {
F_138 () ;
}
if ( V_35 -> V_54 . F_10 == 0 )
return 0 ;
V_35 -> V_54 . F_10 = 0 ;
F_59 ( V_72 ) ;
#else
F_48 ( ( L_74 ,
V_8 ) ) ;
#endif
return 0 ;
}
static int F_139 ( struct V_71 * V_72 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_72 ) ;
#ifdef F_125
T_7 V_193 ;
#endif
int V_78 = F_45 ( V_35 , V_72 ) ;
T_14 V_88 = 0 ;
F_13 ( ( L_75 , V_8 , V_78 ) ) ;
if ( V_78 == 0 ) {
V_88 = F_140 ( & V_35 -> V_54 ) ;
if ( V_88 != 0 ) {
F_48 ( ( L_76 , V_8 , V_88 ) ) ;
return - 1 ;
}
F_20 ( & V_35 -> V_134 , 0 ) ;
memcpy ( V_72 -> V_98 , V_35 -> V_54 . V_240 , V_90 ) ;
#ifdef F_125
if ( F_118 ( V_35 , V_78 , & V_193 ) >= 0
&& ( V_193 & V_216 ) != 0 )
V_35 -> V_74 [ V_78 ] -> V_72 -> V_220 |= V_221 ;
else
V_35 -> V_74 [ V_78 ] -> V_72 -> V_220 &= ~ V_221 ;
#endif
}
F_141 ( V_72 ) ;
V_35 -> V_54 . F_10 = 1 ;
if ( F_137 () ) {
if ( F_142 ( F_143 () ) ) {
F_48 ( ( L_77 ,
V_8 ) ) ;
return - 1 ;
}
}
return V_88 ;
}
int
F_144 ( T_6 * V_35 , int V_78 , void * V_241 , char * V_76 ,
T_9 * V_242 , T_7 V_3 , T_9 V_243 )
{
T_10 * V_99 ;
F_13 ( ( L_78 , V_8 , V_78 , V_241 ) ) ;
ASSERT ( V_35 && ( V_78 < V_73 ) ) ;
V_99 = V_35 -> V_74 [ V_78 ] ;
if ( ! V_99 && ! ( V_99 = F_51 ( sizeof( T_10 ) , V_91 ) ) ) {
F_48 ( ( L_79 , V_8 ) ) ;
return - V_103 ;
}
memset ( V_99 , 0 , sizeof( T_10 ) ) ;
V_99 -> V_79 = V_35 ;
V_35 -> V_74 [ V_78 ] = V_99 ;
F_145 ( V_99 -> V_76 , V_76 , V_77 ) ;
if ( V_242 != NULL )
memcpy ( & V_99 -> V_242 , V_242 , V_90 ) ;
if ( V_241 == NULL ) {
V_99 -> V_22 = V_102 ;
V_99 -> V_101 = V_78 ;
ASSERT ( V_35 -> V_120 ) ;
F_10 ( & V_35 -> V_114 ) ;
} else
V_99 -> V_72 = (struct V_71 * ) V_241 ;
return 0 ;
}
void F_146 ( T_6 * V_35 , int V_78 )
{
T_10 * V_99 ;
F_13 ( ( L_80 , V_8 , V_78 ) ) ;
ASSERT ( V_35 && V_78 && ( V_78 < V_73 ) ) ;
V_99 = V_35 -> V_74 [ V_78 ] ;
if ( ! V_99 ) {
F_48 ( ( L_81 , V_8 ) ) ;
return;
}
V_99 -> V_22 = V_109 ;
V_99 -> V_101 = V_78 ;
ASSERT ( V_35 -> V_120 ) ;
F_10 ( & V_35 -> V_114 ) ;
}
T_2 * F_147 ( struct V_244 * V_136 , T_3 V_245 )
{
T_6 * V_35 = NULL ;
struct V_71 * V_72 ;
F_13 ( ( L_50 , V_8 ) ) ;
if ( ( V_246 != NULL ) && ( V_246 [ 0 ] != '\0' ) )
strcpy ( V_247 , V_246 ) ;
if ( ( V_248 != NULL ) && ( V_248 [ 0 ] != '\0' ) )
strcpy ( V_249 , V_248 ) ;
V_72 = F_62 ( sizeof( V_35 ) ) ;
if ( ! V_72 ) {
F_48 ( ( L_36 , V_8 ) ) ;
goto V_250;
}
V_35 = F_148 ( sizeof( T_6 ) , V_91 ) ;
if ( ! V_35 ) {
F_48 ( ( L_82 , V_8 ) ) ;
goto V_250;
}
memcpy ( F_63 ( V_72 ) , & V_35 , sizeof( V_35 ) ) ;
if ( V_251 [ 0 ] ) {
int V_94 ;
char V_252 ;
strncpy ( V_72 -> V_76 , V_251 , V_77 ) ;
V_72 -> V_76 [ V_77 - 1 ] = 0 ;
V_94 = strlen ( V_72 -> V_76 ) ;
V_252 = V_72 -> V_76 [ V_94 - 1 ] ;
if ( ( V_252 > '9' || V_252 < '0' ) && ( V_94 < V_77 - 2 ) )
strcat ( V_72 -> V_76 , L_83 ) ;
}
if ( F_144 ( V_35 , 0 , ( void * ) V_72 , V_72 -> V_76 , NULL , 0 , 0 ) ==
V_75 )
goto V_250;
V_72 -> V_253 = NULL ;
F_149 ( & V_35 -> V_254 , 1 ) ;
F_39 ( & V_35 -> V_255 ) ;
F_39 ( & V_35 -> V_256 ) ;
F_150 ( & V_35 -> V_257 ) ;
F_150 ( & V_35 -> V_258 ) ;
V_35 -> V_54 . V_79 = V_35 ;
V_35 -> V_54 . V_136 = V_136 ;
V_35 -> V_54 . V_139 = V_245 ;
if ( F_151 ( & V_35 -> V_54 ) != 0 ) {
F_48 ( ( L_84 ) ) ;
goto V_250;
}
#if F_130 ( V_226 )
if ( F_152 ( V_72 , ( void * ) & V_35 -> V_54 ) != 0 ) {
F_48 ( ( L_85 ) ) ;
goto V_250;
}
#endif
if ( F_137 () ) {
if ( F_142 ( F_153 ( V_72 , & V_35 -> V_54 ) ) ) {
F_48 ( ( L_86 ) ) ;
goto V_250;
}
if ( ! F_154 () ) {
strcpy ( V_247 , F_121 () ) ;
strcpy ( V_249 , F_155 () ) ;
}
}
F_156 ( & V_35 -> V_187 ) ;
V_35 -> V_187 . V_111 = ( unsigned long ) V_35 ;
V_35 -> V_187 . V_259 = F_110 ;
F_149 ( & V_35 -> V_260 , 1 ) ;
if ( ( V_176 >= 0 ) && ( V_189 >= 0 ) )
V_35 -> V_261 = true ;
else
V_35 -> V_261 = false ;
if ( V_189 >= 0 ) {
F_149 ( & V_35 -> V_182 , 0 ) ;
V_35 -> V_185 = F_157 ( F_106 , V_35 ,
L_87 ) ;
if ( F_158 ( V_35 -> V_185 ) ) {
F_4 ( V_262
L_88 ) ;
V_35 -> V_185 = NULL ;
}
} else {
V_35 -> V_185 = NULL ;
}
if ( V_189 >= 0 ) {
F_149 ( & V_35 -> V_190 , 0 ) ;
V_35 -> V_192 = F_157 ( F_112 , V_35 , L_89 ) ;
if ( F_158 ( V_35 -> V_192 ) ) {
F_4 ( V_262
L_90 ) ;
V_35 -> V_192 = NULL ;
}
} else {
F_159 ( & V_35 -> V_191 , F_115 , ( unsigned long ) V_35 ) ;
V_35 -> V_192 = NULL ;
}
if ( V_263 ) {
F_149 ( & V_35 -> V_114 , 0 ) ;
V_35 -> V_120 = F_157 ( F_66 , V_35 ,
L_91 ) ;
if ( F_158 ( V_35 -> V_120 ) ) {
F_4 ( V_262
L_92 ) ;
V_35 -> V_120 = NULL ;
}
} else
V_35 -> V_120 = NULL ;
memcpy ( F_63 ( V_72 ) , & V_35 , sizeof( V_35 ) ) ;
#if F_130 ( F_26 ) && F_130 ( V_264 )
V_265 = V_136 ;
#endif
#if F_130 ( V_266 )
F_20 ( & V_30 , false ) ;
if ( ! F_137 () )
F_160 ( & V_267 ) ;
#endif
#ifdef F_161
V_35 -> V_56 . V_268 = V_269 + 20 ;
V_35 -> V_56 . V_270 = F_32 ;
V_35 -> V_56 . V_271 = F_34 ;
F_162 ( & V_35 -> V_56 ) ;
#endif
return & V_35 -> V_54 ;
V_250:
if ( V_72 )
F_61 ( V_72 ) ;
if ( V_35 )
F_163 ( & V_35 -> V_54 ) ;
return NULL ;
}
int F_140 ( T_2 * V_53 )
{
int V_88 = - 1 ;
T_6 * V_35 = ( T_6 * ) V_53 -> V_79 ;
#ifdef F_164
char V_43 [ V_272 + 12 ] ;
#endif
ASSERT ( V_35 ) ;
F_13 ( ( L_93 , V_8 ) ) ;
if ( V_35 -> V_54 . V_124 == V_125 ) {
if ( ! ( F_165 ( V_35 -> V_54 . V_136 ,
V_247 , V_249 ) ) ) {
F_48 ( ( L_94
L_95 ,
V_8 , V_247 , V_249 ) ) ;
return - 1 ;
}
}
V_35 -> V_54 . V_184 = 0 ;
F_166 ( & V_35 -> V_54 , V_188 ) ;
V_88 = F_167 ( & V_35 -> V_54 , true ) ;
if ( V_88 != 0 ) {
F_48 ( ( L_96 , V_8 , V_88 ) ) ;
return V_88 ;
}
#if F_130 ( V_273 )
if ( F_168 ( V_53 ) ) {
F_169 ( & V_35 -> V_187 ) ;
V_35 -> V_186 = false ;
F_48 ( ( L_97 , V_8 ) ) ;
return - V_126 ;
}
F_170 ( V_35 -> V_54 . V_136 , true ) ;
#endif
if ( V_35 -> V_54 . V_124 != V_237 ) {
F_169 ( & V_35 -> V_187 ) ;
V_35 -> V_186 = false ;
F_48 ( ( L_98 , V_8 ) ) ;
return - V_126 ;
}
#ifdef F_164
F_28 ( L_99 , V_53 -> V_274 , V_272 , V_43 ,
sizeof( V_43 ) ) ;
F_171 ( V_53 , 0 , V_194 , V_43 , sizeof( V_43 ) ) ;
memcpy ( V_53 -> V_274 , V_43 , V_272 ) ;
F_172 ( V_53 -> V_274 , V_275 ) ;
F_172 ( V_53 -> V_274 , V_276 ) ;
F_172 ( V_53 -> V_274 , V_277 ) ;
F_172 ( V_53 -> V_274 , V_278 ) ;
F_172 ( V_53 -> V_274 , V_279 ) ;
F_172 ( V_53 -> V_274 , V_280 ) ;
F_172 ( V_53 -> V_274 , V_281 ) ;
F_172 ( V_53 -> V_274 , V_282 ) ;
F_172 ( V_53 -> V_274 , V_283 ) ;
F_172 ( V_53 -> V_274 , V_284 ) ;
F_172 ( V_53 -> V_274 , V_285 ) ;
F_172 ( V_53 -> V_274 , V_286 ) ;
F_172 ( V_53 -> V_274 , V_287 ) ;
F_172 ( V_53 -> V_274 , V_288 ) ;
F_172 ( V_53 -> V_274 , V_289 ) ;
F_172 ( V_53 -> V_274 , V_290 ) ;
F_172 ( V_53 -> V_274 , V_291 ) ;
F_172 ( V_53 -> V_274 , V_292 ) ;
#ifdef F_173
F_172 ( V_53 -> V_274 , V_293 ) ;
#endif
V_53 -> V_38 = 1 ;
V_53 -> V_39 [ 0 ] = L_100 ;
#endif
V_88 = F_174 ( & V_35 -> V_54 ) ;
if ( V_88 < 0 )
return V_88 ;
return 0 ;
}
int
F_175 ( T_2 * V_54 , int V_78 , char * V_76 , char * V_294 , T_3 V_295 ,
int V_95 )
{
char V_85 [ strlen ( V_76 ) + 1 + V_295 ] ;
int V_94 = sizeof( V_85 ) ;
T_8 V_84 ;
int V_88 ;
V_94 = F_28 ( V_76 , V_294 , V_295 , V_85 , V_94 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_93 = V_95 ? V_49 : V_194 ;
V_84 . V_85 = V_85 ;
V_84 . V_94 = V_94 ;
V_84 . V_95 = V_95 ;
V_88 = F_54 ( V_54 , V_78 , & V_84 , V_84 . V_85 , V_84 . V_94 ) ;
if ( ! V_95 && V_88 >= 0 )
memcpy ( V_294 , V_85 , V_295 ) ;
return V_88 ;
}
int F_64 ( T_2 * V_53 , int V_78 )
{
T_6 * V_35 = ( T_6 * ) V_53 -> V_79 ;
struct V_71 * V_72 ;
T_9 V_296 [ V_90 ] = {
0x00 , 0x90 , 0x4c , 0x11 , 0x22 , 0x33 } ;
F_13 ( ( L_75 , V_8 , V_78 ) ) ;
ASSERT ( V_35 && V_35 -> V_74 [ V_78 ] ) ;
V_72 = V_35 -> V_74 [ V_78 ] -> V_72 ;
ASSERT ( V_72 ) ;
ASSERT ( ! V_72 -> V_253 ) ;
V_72 -> V_253 = & V_297 ;
if ( V_78 != 0 ) {
memcpy ( V_296 , V_35 -> V_54 . V_240 , V_90 ) ;
}
if ( V_78 == 1 ) {
F_13 ( ( L_101 , V_8 ) ) ;
V_296 [ 0 ] |= 0X02 ;
}
V_72 -> V_298 = V_159 + V_35 -> V_54 . V_139 ;
V_72 -> V_299 = & V_300 ;
V_35 -> V_54 . V_301 = V_72 -> V_302 + V_72 -> V_298 + V_35 -> V_54 . V_139 ;
memcpy ( V_72 -> V_98 , V_296 , V_90 ) ;
if ( F_176 ( V_72 ) != 0 ) {
F_48 ( ( L_102 ,
V_8 ) ) ;
goto V_250;
}
F_84 ( ( L_103 , V_72 -> V_76 ) ) ;
return 0 ;
V_250:
V_72 -> V_253 = NULL ;
return - V_303 ;
}
void F_177 ( T_2 * V_53 )
{
T_6 * V_35 ;
F_13 ( ( L_50 , V_8 ) ) ;
if ( V_53 ) {
V_35 = ( T_6 * ) V_53 -> V_79 ;
if ( V_35 ) {
F_178 ( & V_35 -> V_54 ) ;
F_114 ( V_35 -> V_54 . V_136 , true ) ;
#if F_130 ( V_273 )
F_179 () ;
#endif
F_169 ( & V_35 -> V_187 ) ;
V_35 -> V_186 = false ;
}
}
}
void F_163 ( T_2 * V_53 )
{
T_6 * V_35 ;
F_13 ( ( L_50 , V_8 ) ) ;
if ( V_53 ) {
V_35 = ( T_6 * ) V_53 -> V_79 ;
if ( V_35 ) {
T_10 * V_99 ;
int V_37 ;
#if F_130 ( F_161 )
if ( V_35 -> V_56 . V_270 )
F_180 ( & V_35 -> V_56 ) ;
#endif
for ( V_37 = 1 ; V_37 < V_73 ; V_37 ++ )
if ( V_35 -> V_74 [ V_37 ] )
F_146 ( V_35 , V_37 ) ;
V_99 = V_35 -> V_74 [ 0 ] ;
ASSERT ( V_99 ) ;
if ( V_99 -> V_72 -> V_253 == & V_297 ) {
F_136 ( V_99 -> V_72 ) ;
F_60 ( V_99 -> V_72 ) ;
}
if ( V_35 -> V_185 ) {
F_181 ( V_113 , V_35 -> V_185 , 1 ) ;
F_182 ( V_35 -> V_185 ) ;
V_35 -> V_185 = NULL ;
}
if ( V_35 -> V_192 ) {
F_181 ( V_113 , V_35 -> V_192 , 1 ) ;
F_182 ( V_35 -> V_192 ) ;
V_35 -> V_192 = NULL ;
} else
F_183 ( & V_35 -> V_191 ) ;
if ( V_35 -> V_120 ) {
F_181 ( V_113 , V_35 -> V_120 , 1 ) ;
F_182 ( V_35 -> V_120 ) ;
V_35 -> V_120 = NULL ;
}
F_177 ( V_53 ) ;
if ( V_53 -> V_304 )
F_184 ( V_53 ) ;
#if F_130 ( V_226 )
F_185 () ;
#endif
if ( F_137 () )
F_186 () ;
#if F_130 ( V_266 )
if ( ! F_137 () )
F_187 ( & V_267 ) ;
#endif
F_61 ( V_99 -> V_72 ) ;
F_55 ( V_99 ) ;
F_55 ( V_35 ) ;
}
}
}
static void T_15 F_188 ( void )
{
F_13 ( ( L_50 , V_8 ) ) ;
F_189 () ;
#if F_130 ( F_26 ) && F_130 ( V_264 )
F_17 () ;
#endif
F_190 ( V_305 ) ;
}
static int T_16 F_191 ( void )
{
int error ;
F_13 ( ( L_50 , V_8 ) ) ;
do {
if ( ( V_176 < 0 ) && ( V_189 < 0 ) )
break;
if ( ( V_176 >= 0 ) && ( V_189 >= 0 )
&& V_306 )
break;
F_48 ( ( L_104 ) ) ;
return - V_232 ;
} while ( 0 );
F_190 ( V_307 ) ;
#if F_130 ( F_26 ) && F_130 ( V_264 )
F_149 ( & V_21 , 0 ) ;
error = F_15 () ;
if ( error ) {
F_48 ( ( L_105 , V_8 ) ) ;
goto V_308;
}
if ( F_192 ( & V_21 , F_193 ( 1000 ) ) != 0 ) {
F_4 ( V_7 L_106 ,
V_8 ) ;
F_17 () ;
goto V_308;
}
#endif
error = F_194 () ;
if ( error ) {
F_48 ( ( L_107 , V_8 ) ) ;
goto V_308;
}
return error ;
V_308:
F_190 ( V_305 ) ;
return - V_232 ;
}
int F_30 ( T_2 * V_54 )
{
T_6 * V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
if ( V_35 ) {
F_195 ( & V_35 -> V_254 ) ;
return 1 ;
}
return 0 ;
}
int F_31 ( T_2 * V_54 )
{
T_6 * V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
if ( V_35 ) {
F_10 ( & V_35 -> V_254 ) ;
return 1 ;
}
return 0 ;
}
unsigned int F_196 ( void )
{
return ( unsigned int ) V_309 ;
}
void F_197 ( unsigned int V_310 )
{
V_309 = ( int ) V_310 ;
}
int F_198 ( T_2 * V_54 , T_3 * V_311 , bool * V_68 )
{
T_6 * V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
F_38 ( V_66 , V_67 ) ;
int V_312 = V_309 ;
V_312 = V_312 * V_64 / 1000 ;
F_40 ( & V_35 -> V_255 , & V_66 ) ;
F_41 ( V_69 ) ;
while ( ! ( * V_311 ) && ( ! F_43 ( V_67 ) && V_312 ) )
V_312 = F_42 ( V_312 ) ;
if ( F_43 ( V_67 ) )
* V_68 = true ;
F_41 ( V_70 ) ;
F_44 ( & V_35 -> V_255 , & V_66 ) ;
return V_312 ;
}
int F_199 ( T_2 * V_54 )
{
T_6 * V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
if ( F_200 ( & V_35 -> V_255 ) )
F_201 ( & V_35 -> V_255 ) ;
return 0 ;
}
void F_166 ( void * V_136 , T_3 V_313 )
{
T_2 * V_54 = V_136 ;
static T_3 V_314 ;
T_6 * V_35 = ( T_6 * ) V_54 -> V_79 ;
if ( V_54 -> V_124 == V_125 )
return;
if ( ! V_313 && V_35 -> V_186 == true ) {
F_169 ( & V_35 -> V_187 ) ;
V_35 -> V_186 = false ;
V_314 = V_313 ;
return;
}
if ( V_313 ) {
V_188 = ( T_3 ) V_313 ;
if ( V_314 != V_188 ) {
if ( V_35 -> V_186 == true )
F_169 ( & V_35 -> V_187 ) ;
V_35 -> V_187 . V_315 =
V_162 + V_188 * V_64 / 1000 ;
F_202 ( & V_35 -> V_187 ) ;
} else {
F_111 ( & V_35 -> V_187 ,
V_162 + V_188 * V_64 / 1000 ) ;
}
V_35 -> V_186 = true ;
V_314 = V_313 ;
}
}
void * F_203 ( char * V_316 )
{
struct V_317 * V_318 ;
if ( F_137 () && ! F_154 () )
return F_204 ( V_316 ) ;
V_318 = F_205 ( V_316 , V_319 , 0 ) ;
if ( F_158 ( V_318 ) )
V_318 = NULL ;
return V_318 ;
}
int F_206 ( char * V_85 , int V_94 , void * V_320 )
{
struct V_317 * V_318 = (struct V_317 * ) V_320 ;
int V_321 ;
if ( F_137 () && ! F_154 () )
return F_207 ( V_85 , V_94 ) ;
if ( ! V_320 )
return 0 ;
V_321 = F_208 ( V_318 , V_318 -> V_322 , V_85 , V_94 ) ;
if ( V_321 > 0 )
V_318 -> V_322 += V_321 ;
return V_321 ;
}
void F_209 ( void * V_320 )
{
if ( F_137 () && ! F_154 () )
return F_210 () ;
if ( V_320 )
F_211 ( (struct V_317 * ) V_320 , NULL ) ;
}
void F_212 ( T_2 * V_54 )
{
T_6 * V_35 ;
V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
if ( V_35 -> V_261 )
F_195 ( & V_35 -> V_260 ) ;
else
F_213 ( & V_35 -> V_257 ) ;
}
void F_214 ( T_2 * V_54 )
{
T_6 * V_35 ;
V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
if ( V_35 -> V_261 )
F_10 ( & V_35 -> V_260 ) ;
else
F_215 ( & V_35 -> V_257 ) ;
}
void F_216 ( T_2 * V_54 )
{
T_6 * V_35 ;
V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
F_213 ( & V_35 -> V_258 ) ;
}
void F_217 ( T_2 * V_54 )
{
T_6 * V_35 ;
V_35 = ( T_6 * ) ( V_54 -> V_79 ) ;
F_215 ( & V_35 -> V_258 ) ;
}
void F_218 ( T_2 * V_54 )
{
}
void F_219 ( T_2 * V_54 )
{
}
void F_220 ( T_2 * V_54 )
{
F_212 ( V_54 ) ;
}
void F_221 ( T_2 * V_54 )
{
F_214 ( V_54 ) ;
}
static int
F_95 ( T_6 * V_35 , int * V_78 , void * V_127 ,
T_11 * V_153 , void * * V_111 )
{
int V_224 = 0 ;
ASSERT ( V_35 != NULL ) ;
V_224 = F_222 ( V_35 , V_78 , V_127 , V_153 , V_111 ) ;
if ( V_224 != 0 )
return V_224 ;
#if F_130 ( V_226 )
if ( ! F_137 () ) {
if ( ( V_35 -> V_74 [ * V_78 ] == NULL )
|| ( V_35 -> V_74 [ * V_78 ] -> V_72 == NULL ) ) {
F_48 ( ( L_108 , V_8 ) ) ;
return V_224 ;
}
if ( V_35 -> V_74 [ * V_78 ] -> V_72 )
F_223 ( V_35 -> V_74 [ * V_78 ] -> V_72 , V_153 , * V_111 ) ;
}
#endif
if ( F_137 () ) {
ASSERT ( V_35 -> V_74 [ * V_78 ] != NULL ) ;
ASSERT ( V_35 -> V_74 [ * V_78 ] -> V_72 != NULL ) ;
if ( V_35 -> V_74 [ * V_78 ] -> V_72 )
F_224 ( V_35 -> V_74 [ * V_78 ] -> V_72 , V_153 ,
* V_111 ) ;
}
return V_224 ;
}
void F_225 ( T_2 * V_53 , T_11 * V_153 , void * V_111 )
{
switch ( F_226 ( V_153 -> V_323 ) ) {
default:
break;
}
}
void F_227 ( T_2 * V_35 , bool * V_324 )
{
struct V_51 * V_325 = V_35 -> V_79 ;
F_214 ( V_35 ) ;
F_228 ( V_325 -> V_256 ,
( * V_324 == false ) , V_64 * 2 ) ;
F_212 ( V_35 ) ;
return;
}
void F_229 ( T_2 * V_35 )
{
struct V_51 * V_325 = V_35 -> V_79 ;
if ( F_200 ( & V_325 -> V_256 ) )
F_201 ( & V_325 -> V_256 ) ;
return;
}
int F_230 ( struct V_71 * V_18 , T_9 V_326 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
if ( V_326 )
F_166 ( & V_35 -> V_54 , 0 ) ;
F_231 ( & V_35 -> V_54 , V_326 ) ;
if ( ! V_326 )
F_166 ( & V_35 -> V_54 , V_188 ) ;
F_48 ( ( L_109 , V_8 ) ) ;
return 1 ;
}
int F_232 ( struct V_71 * V_18 , int V_52 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
int V_88 = 0 ;
if ( V_35 ) {
V_88 = V_35 -> V_54 . V_55 ;
V_35 -> V_54 . V_55 = V_52 ;
}
return V_88 ;
}
int F_233 ( struct V_71 * V_18 , int V_52 )
{
int V_88 = 0 ;
#if F_130 ( F_161 )
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
if ( V_35 ) {
F_30 ( & V_35 -> V_54 ) ;
V_88 = F_25 ( V_52 , & V_35 -> V_54 ) ;
F_31 ( & V_35 -> V_54 ) ;
}
#endif
return V_88 ;
}
int F_234 ( struct V_71 * V_18 , int V_52 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
if ( V_35 )
V_35 -> V_54 . V_48 = V_52 ;
return 0 ;
}
int F_235 ( struct V_71 * V_18 , int V_52 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
int V_88 = 0 ;
if ( V_35 && V_35 -> V_54 . F_10 ) {
F_30 ( & V_35 -> V_54 ) ;
if ( V_35 -> V_54 . V_46 ) {
if ( ! V_52 || ( V_52 && ! V_35 -> V_54 . V_55 ) )
F_21 ( V_52 , & V_35 -> V_54 ) ;
}
F_31 ( & V_35 -> V_54 ) ;
}
return V_88 ;
}
void F_236 ( struct V_71 * V_18 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
F_237 ( & V_35 -> V_54 ) ;
}
int F_238 ( struct V_71 * V_18 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
return F_239 ( & V_35 -> V_54 ) ;
}
int F_240 ( struct V_71 * V_18 , int V_327 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
return F_241 ( & V_35 -> V_54 , V_327 ) ;
}
int
F_242 ( struct V_71 * V_18 , T_17 * V_328 , int V_329 ,
unsigned char V_330 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
return F_243 ( & V_35 -> V_54 , V_328 , V_329 , V_330 ) ;
}
int F_244 ( struct V_71 * V_18 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
return F_245 ( & V_35 -> V_54 ) ;
}
static int F_246 ( T_6 * V_35 )
{
return F_247 ( & V_35 -> V_134 ) ;
}
int F_135 ( struct V_71 * V_18 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_18 ) ;
int V_312 = 10 * V_64 / 1000 ;
int V_331 = V_332 ;
int V_333 = F_246 ( V_35 ) ;
while ( V_331 && V_333 ) {
if ( V_333 ) {
F_41 ( V_69 ) ;
F_42 ( V_312 ) ;
F_41 ( V_70 ) ;
V_331 -- ;
}
V_333 = F_246 ( V_35 ) ;
}
return V_333 ;
}
void F_248 ( struct V_71 * V_334 , T_3 V_313 )
{
T_6 * V_35 = * ( T_6 * * ) F_63 ( V_334 ) ;
F_166 ( & V_35 -> V_54 , V_313 ) ;
}
int F_249 ( T_2 * V_35 , T_9 * V_85 , int V_335 )
{
int V_88 = 0 ;
struct V_317 * V_318 ;
T_18 V_336 ;
T_19 V_337 = 0 ;
V_336 = F_250 () ;
F_251 ( V_338 ) ;
V_318 = F_205 ( L_110 , V_339 | V_340 , 0640 ) ;
if ( ! V_318 ) {
F_48 ( ( L_111 , V_8 ) ) ;
V_88 = - 1 ;
goto exit;
}
V_318 -> V_341 -> V_342 ( V_318 , V_85 , V_335 , & V_337 ) ;
exit:
F_55 ( V_85 ) ;
if ( V_318 )
F_211 ( V_318 , V_67 -> V_343 ) ;
F_251 ( V_336 ) ;
return V_88 ;
}
