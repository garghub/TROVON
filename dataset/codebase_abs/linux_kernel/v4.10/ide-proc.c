static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_5 ;
const char * V_6 ;
switch ( V_4 -> V_7 ) {
case V_8 : V_6 = L_1 ; break;
case V_9 : V_6 = L_2 ; break;
case V_10 : V_6 = L_3 ; break;
case V_11 : V_6 = L_4 ; break;
case V_12 : V_6 = L_5 ; break;
case V_13 : V_6 = L_6 ; break;
case V_14 : V_6 = L_7 ; break;
case V_15 : V_6 = L_8 ; break;
case V_16 : V_6 = L_9 ; break;
case V_17 : V_6 = L_10 ; break;
case V_18 : V_6 = L_11 ; break;
case V_19 : V_6 = L_12 ; break;
case V_20 : V_6 = L_13 ; break;
default: V_6 = L_14 ; break;
}
F_2 ( V_2 , L_15 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_1 , F_5 ( V_21 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_5 ;
if ( V_4 && V_4 -> V_23 )
F_2 ( V_2 , L_15 , V_4 -> V_23 -> V_6 ) ;
else
F_2 ( V_2 , L_16 ) ;
return 0 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_6 , F_5 ( V_21 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_5 ;
F_2 ( V_2 , L_17 , V_4 -> V_24 ? '1' : '0' ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_8 , F_5 ( V_21 ) ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 ;
T_3 * V_26 ;
if ( ! V_25 ) {
F_11 ( V_2 , '\n' ) ;
return 0 ;
}
V_26 = F_12 ( V_27 , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
if ( F_13 ( V_25 , V_26 ) == 0 ) {
T_4 * V_30 = ( T_4 * ) V_26 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_27 / 2 ; V_31 ++ ) {
F_2 ( V_2 , L_18 , F_14 ( V_30 [ V_31 ] ) ,
( V_31 % 8 ) == 7 ? '\n' : ' ' ) ;
}
} else
F_11 ( V_2 , V_26 [ 0 ] ) ;
F_15 ( V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_10 , F_5 ( V_21 ) ) ;
}
static
const struct V_32 * F_17 ( const struct V_32 * V_33 ,
char * V_6 )
{
while ( V_33 -> V_6 ) {
if ( strcmp ( V_33 -> V_6 , V_6 ) == 0 )
break;
V_33 ++ ;
}
return V_33 -> V_6 ? V_33 : NULL ;
}
static int F_18 ( T_2 * V_25 ,
const struct V_32 * V_34 )
{
const struct V_35 * V_36 = V_34 -> V_34 ;
int V_30 = - V_37 ;
if ( V_36 -> V_38 )
V_30 = V_36 -> V_38 ( V_25 ) ;
return V_30 ;
}
static int F_19 ( T_2 * V_25 ,
const struct V_32 * V_34 , int V_30 )
{
const struct V_35 * V_36 = V_34 -> V_34 ;
if ( ! F_20 ( V_39 ) )
return - V_40 ;
if ( ! V_36 -> V_41 )
return - V_42 ;
if ( ( V_36 -> V_43 & V_44 )
&& ( V_30 < V_34 -> V_45 || V_30 > V_34 -> V_46 ) )
return - V_37 ;
return F_21 ( V_25 , V_36 , V_30 ) ;
}
static int F_22 ( T_2 * V_25 , int V_47 )
{
struct V_48 V_49 ;
if ( V_47 < V_50 || V_47 > V_51 )
return - V_37 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_52 . V_53 = V_54 ;
V_49 . V_52 . V_55 = V_56 ;
V_49 . V_52 . V_57 = ( T_3 ) V_47 ;
V_49 . V_58 . V_59 . V_52 = V_60 | V_61 ;
V_49 . V_58 . V_62 . V_52 = V_61 ;
V_49 . V_63 = V_64 ;
return F_23 ( V_25 , & V_49 ) ;
}
static void F_24 ( void )
{
F_25 ( V_65 L_19
L_20 ) ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_32 * V_34 , * V_66 , * V_67 ;
const struct V_35 * V_36 ;
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 ;
int V_68 , V_69 , V_70 ;
F_24 () ;
F_27 ( & V_71 ) ;
V_66 = V_72 ;
V_67 = V_25 -> V_73 ;
F_2 ( V_2 , L_21 ) ;
F_2 ( V_2 , L_22 ) ;
while ( V_66 -> V_6 || ( V_67 && V_67 -> V_6 ) ) {
if ( V_66 -> V_6 && V_67 && V_67 -> V_6 ) {
if ( strcmp ( V_67 -> V_6 , V_66 -> V_6 ) < 0 )
V_34 = V_67 ++ ;
else
V_34 = V_66 ++ ;
} else if ( V_67 && V_67 -> V_6 ) {
V_34 = V_67 ++ ;
} else
V_34 = V_66 ++ ;
V_69 = V_34 -> V_74 ? V_34 -> V_74 ( V_25 ) : 1 ;
V_70 = V_34 -> V_75 ? V_34 -> V_75 ( V_25 ) : 1 ;
F_2 ( V_2 , L_23 , V_34 -> V_6 ) ;
V_68 = F_18 ( V_25 , V_34 ) ;
if ( V_68 >= 0 )
F_2 ( V_2 , L_24 , V_68 * V_69 / V_70 ) ;
else
F_2 ( V_2 , L_25 , L_26 ) ;
F_2 ( V_2 , L_27 , ( V_34 -> V_45 * V_69 + V_70 - 1 ) / V_70 , V_34 -> V_46 * V_69 / V_70 ) ;
V_36 = V_34 -> V_34 ;
if ( V_36 -> V_38 )
F_2 ( V_2 , L_28 ) ;
if ( V_36 -> V_41 )
F_2 ( V_2 , L_29 ) ;
F_2 ( V_2 , L_30 ) ;
}
F_28 ( & V_71 ) ;
return 0 ;
}
static int F_29 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_26 , F_5 ( V_21 ) ) ;
}
static T_5 F_30 ( struct V_22 * V_22 , const char T_6 * V_76 ,
T_7 V_77 , T_8 * V_78 )
{
T_2 * V_25 = F_5 ( F_31 ( V_22 ) ) ;
char V_6 [ V_79 + 1 ] ;
int V_80 = 0 , V_69 , V_70 ;
unsigned long V_81 ;
const struct V_32 * V_34 ;
char * V_26 , * V_82 ;
if ( ! F_20 ( V_39 ) )
return - V_40 ;
F_24 () ;
if ( V_77 >= V_83 )
return - V_37 ;
V_82 = V_26 = ( char * ) F_32 ( V_84 ) ;
if ( ! V_26 )
return - V_29 ;
if ( F_33 ( V_26 , V_76 , V_77 ) ) {
F_34 ( ( unsigned long ) V_26 ) ;
return - V_85 ;
}
V_26 [ V_77 ] = '\0' ;
while ( V_77 && isspace ( * V_82 ) ) {
-- V_77 ;
++ V_82 ;
}
do {
char * V_86 = V_82 ;
V_81 = V_77 ;
while ( V_81 > 0 ) {
unsigned V_30 ;
char * V_87 = V_86 ;
while ( V_81 > 0 && * V_86 != ':' ) {
-- V_81 ;
V_86 ++ ;
}
if ( * V_86 != ':' )
goto V_88;
if ( V_86 - V_87 > V_79 )
goto V_88;
memcpy ( V_6 , V_87 , V_86 - V_87 ) ;
V_6 [ V_86 - V_87 ] = 0 ;
if ( V_81 > 0 ) {
-- V_81 ;
V_86 ++ ;
} else
goto V_88;
V_30 = F_35 ( V_86 , & V_87 , 10 ) ;
V_81 -= V_87 - V_86 ;
V_86 = V_87 ;
if ( V_81 > 0 && ! isspace ( * V_86 ) )
goto V_88;
while ( V_81 > 0 && isspace ( * V_86 ) ) {
-- V_81 ;
++ V_86 ;
}
F_27 ( & V_71 ) ;
V_34 = F_17 ( V_72 , V_6 ) ;
if ( ! V_34 ) {
if ( V_25 -> V_73 )
V_34 = F_17 ( V_25 -> V_73 , V_6 ) ;
if ( ! V_34 ) {
F_28 ( & V_71 ) ;
goto V_88;
}
}
if ( V_80 ) {
V_69 = V_34 -> V_74 ? V_34 -> V_74 ( V_25 ) : 1 ;
V_70 = V_34 -> V_75 ? V_34 -> V_75 ( V_25 ) : 1 ;
F_19 ( V_25 , V_34 , V_30 * V_70 / V_69 ) ;
}
F_28 ( & V_71 ) ;
}
} while ( ! V_80 ++ );
F_34 ( ( unsigned long ) V_26 ) ;
return V_77 ;
V_88:
F_34 ( ( unsigned long ) V_26 ) ;
F_36 ( L_31 , V_89 ) ;
return - V_37 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_32 , ( long long ) 0x7fffffff ) ;
return 0 ;
}
static int F_38 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_37 , NULL ) ;
}
static int F_39 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 ;
F_2 ( V_2 , L_33 ,
V_25 -> V_90 , V_25 -> V_91 , V_25 -> V_92 ) ;
F_2 ( V_2 , L_34 ,
V_25 -> V_93 , V_25 -> V_94 , V_25 -> V_95 ) ;
return 0 ;
}
static int F_40 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_39 , F_5 ( V_21 ) ) ;
}
static int F_41 ( struct V_1 * V_96 , void * V_3 )
{
T_2 * V_25 = ( T_2 * ) V_96 -> V_5 ;
char * V_2 = ( char * ) & V_25 -> V_97 [ V_98 ] ;
F_2 ( V_96 , L_35 , V_2 [ 0 ] ? V_2 : L_36 ) ;
return 0 ;
}
static int F_42 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_41 , F_5 ( V_21 ) ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 ;
struct V_99 * V_100 = & V_25 -> V_101 ;
struct V_102 * V_103 ;
if ( V_100 -> V_104 ) {
V_103 = F_44 ( V_100 -> V_104 ) ;
F_2 ( V_2 , L_37 ,
V_100 -> V_104 -> V_6 , V_103 -> V_105 ) ;
} else
F_2 ( V_2 , L_38 ) ;
return 0 ;
}
static int F_45 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_43 , F_5 ( V_21 ) ) ;
}
static int F_46 ( T_2 * V_25 , const char * V_104 )
{
struct V_99 * V_100 = & V_25 -> V_101 ;
int V_106 = 1 ;
int V_107 ;
F_47 ( V_100 ) ;
F_48 ( V_25 -> V_108 , V_104 , sizeof( V_25 -> V_108 ) ) ;
V_107 = F_49 ( V_100 ) ;
if ( V_107 < 0 )
F_36 ( V_65 L_39 ,
V_89 , V_107 ) ;
V_25 -> V_108 [ 0 ] = 0 ;
if ( V_100 -> V_104 == NULL ) {
V_107 = F_49 ( V_100 ) ;
if ( V_107 < 0 )
F_36 ( V_65
L_40 ,
V_89 , V_107 ) ;
}
if ( V_100 -> V_104 && ! strcmp ( V_100 -> V_104 -> V_6 , V_104 ) )
V_106 = 0 ;
return V_106 ;
}
static T_5 F_50 ( struct V_22 * V_22 , const char T_6 * V_76 ,
T_7 V_77 , T_8 * V_78 )
{
T_2 * V_25 = F_5 ( F_31 ( V_22 ) ) ;
char V_6 [ 32 ] ;
if ( ! F_20 ( V_39 ) )
return - V_40 ;
if ( V_77 > 31 )
V_77 = 31 ;
if ( F_33 ( V_6 , V_76 , V_77 ) )
return - V_85 ;
V_6 [ V_77 ] = '\0' ;
if ( F_46 ( V_25 , V_6 ) )
return - V_37 ;
return V_77 ;
}
static int F_51 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_25 = ( T_2 * ) V_2 -> V_5 ;
const char * V_109 ;
switch ( V_25 -> V_109 ) {
case V_110 : V_109 = L_41 ; break;
case V_111 : V_109 = L_42 ; break;
case V_112 : V_109 = L_43 ; break;
case V_113 : V_109 = L_44 ; break;
case V_114 : V_109 = L_45 ; break;
default: V_109 = L_46 ; break;
}
F_52 ( V_2 , V_109 ) ;
return 0 ;
}
static int F_53 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_51 , F_5 ( V_21 ) ) ;
}
static void F_54 ( struct V_115 * V_116 , T_9 * V_86 , void * V_117 )
{
struct V_115 * V_118 ;
if ( ! V_116 || ! V_86 )
return;
while ( V_86 -> V_6 != NULL ) {
V_118 = F_55 ( V_86 -> V_6 , V_86 -> V_119 , V_116 , V_86 -> V_120 , V_117 ) ;
if ( ! V_118 ) return;
V_86 ++ ;
}
}
static void F_56 ( struct V_115 * V_116 , T_9 * V_86 )
{
if ( ! V_116 || ! V_86 )
return;
while ( V_86 -> V_6 != NULL ) {
F_57 ( V_86 -> V_6 , V_116 ) ;
V_86 ++ ;
}
}
void F_58 ( T_2 * V_25 , struct V_102 * V_104 )
{
F_27 ( & V_71 ) ;
V_25 -> V_73 = V_104 -> V_121 ( V_25 ) ;
F_28 ( & V_71 ) ;
F_54 ( V_25 -> V_122 , V_104 -> V_123 ( V_25 ) , V_25 ) ;
}
void F_59 ( T_2 * V_25 , struct V_102 * V_104 )
{
F_56 ( V_25 -> V_122 , V_104 -> V_123 ( V_25 ) ) ;
F_27 ( & V_71 ) ;
V_25 -> V_73 = NULL ;
F_28 ( & V_71 ) ;
}
void F_60 ( T_1 * V_4 )
{
struct V_115 * V_118 ;
struct V_115 * V_124 = V_4 -> V_122 ;
T_2 * V_25 ;
char V_6 [ 64 ] ;
int V_31 ;
F_61 (i, drive, hwif) {
if ( ( V_25 -> V_125 & V_126 ) == 0 )
continue;
V_25 -> V_122 = F_62 ( V_25 -> V_6 , V_124 ) ;
if ( V_25 -> V_122 )
F_54 ( V_25 -> V_122 , V_127 , V_25 ) ;
sprintf ( V_6 , L_47 , ( V_25 -> V_6 [ 2 ] - 'a' ) / 2 , V_25 -> V_6 ) ;
V_118 = F_63 ( V_25 -> V_6 , V_128 , V_6 ) ;
if ( ! V_118 ) return;
}
}
void F_64 ( T_2 * V_25 )
{
if ( V_25 -> V_122 ) {
F_56 ( V_25 -> V_122 , V_127 ) ;
F_57 ( V_25 -> V_6 , V_128 ) ;
F_57 ( V_25 -> V_6 , V_25 -> V_4 -> V_122 ) ;
V_25 -> V_122 = NULL ;
}
}
void F_65 ( T_1 * V_4 )
{
if ( ! V_4 -> V_122 ) {
V_4 -> V_122 = F_62 ( V_4 -> V_6 , V_128 ) ;
if ( ! V_4 -> V_122 )
return;
F_54 ( V_4 -> V_122 , V_129 , V_4 ) ;
}
}
void F_66 ( T_1 * V_4 )
{
if ( V_4 -> V_122 ) {
F_56 ( V_4 -> V_122 , V_129 ) ;
F_57 ( V_4 -> V_6 , V_128 ) ;
V_4 -> V_122 = NULL ;
}
}
static int F_67 ( struct V_130 * V_131 , void * V_117 )
{
struct V_102 * V_103 = F_44 ( V_131 ) ;
struct V_1 * V_82 = V_117 ;
F_2 ( V_82 , L_37 , V_131 -> V_6 , V_103 -> V_105 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_82 , void * V_86 )
{
int V_107 ;
V_107 = F_69 ( & V_132 , NULL , V_82 , F_67 ) ;
if ( V_107 < 0 )
F_36 ( V_65 L_48 ,
V_89 , V_107 ) ;
return 0 ;
}
static int F_70 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , & F_68 , NULL ) ;
}
void F_71 ( void )
{
V_128 = F_62 ( L_49 , NULL ) ;
if ( ! V_128 )
return;
F_72 ( L_50 , 0 , V_128 , & V_133 ) ;
}
void F_73 ( void )
{
F_57 ( L_50 , V_128 ) ;
F_57 ( L_49 , NULL ) ;
}
