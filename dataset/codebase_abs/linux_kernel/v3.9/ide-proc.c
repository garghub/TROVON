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
return F_4 ( V_22 , F_1 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_5 ;
if ( V_4 && V_4 -> V_24 )
F_2 ( V_2 , L_15 , V_4 -> V_24 -> V_6 ) ;
else
F_2 ( V_2 , L_16 ) ;
return 0 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_6 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 -> V_5 ;
F_2 ( V_2 , L_17 , V_4 -> V_25 ? '1' : '0' ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_8 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_26 = ( T_2 * ) V_2 -> V_5 ;
T_3 * V_27 ;
if ( ! V_26 ) {
F_11 ( V_2 , '\n' ) ;
return 0 ;
}
V_27 = F_12 ( V_28 , V_29 ) ;
if ( ! V_27 )
return - V_30 ;
if ( F_13 ( V_26 , V_27 ) == 0 ) {
T_4 * V_31 = ( T_4 * ) V_27 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_28 / 2 ; V_32 ++ ) {
F_2 ( V_2 , L_18 , F_14 ( V_31 [ V_32 ] ) ,
( V_32 % 8 ) == 7 ? '\n' : ' ' ) ;
}
} else
F_11 ( V_2 , V_27 [ 0 ] ) ;
F_15 ( V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_10 , F_5 ( V_21 ) -> V_23 ) ;
}
static
const struct V_33 * F_17 ( const struct V_33 * V_34 ,
char * V_6 )
{
while ( V_34 -> V_6 ) {
if ( strcmp ( V_34 -> V_6 , V_6 ) == 0 )
break;
V_34 ++ ;
}
return V_34 -> V_6 ? V_34 : NULL ;
}
static int F_18 ( T_2 * V_26 ,
const struct V_33 * V_35 )
{
const struct V_36 * V_37 = V_35 -> V_35 ;
int V_31 = - V_38 ;
if ( V_37 -> V_39 )
V_31 = V_37 -> V_39 ( V_26 ) ;
return V_31 ;
}
static int F_19 ( T_2 * V_26 ,
const struct V_33 * V_35 , int V_31 )
{
const struct V_36 * V_37 = V_35 -> V_35 ;
if ( ! F_20 ( V_40 ) )
return - V_41 ;
if ( ! V_37 -> V_42 )
return - V_43 ;
if ( ( V_37 -> V_44 & V_45 )
&& ( V_31 < V_35 -> V_46 || V_31 > V_35 -> V_47 ) )
return - V_38 ;
return F_21 ( V_26 , V_37 , V_31 ) ;
}
static int F_22 ( T_2 * V_26 , int V_48 )
{
struct V_49 V_50 ;
if ( V_48 < V_51 || V_48 > V_52 )
return - V_38 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_53 . V_54 = V_55 ;
V_50 . V_53 . V_56 = V_57 ;
V_50 . V_53 . V_58 = ( T_3 ) V_48 ;
V_50 . V_59 . V_60 . V_53 = V_61 | V_62 ;
V_50 . V_59 . V_63 . V_53 = V_62 ;
V_50 . V_64 = V_65 ;
return F_23 ( V_26 , & V_50 ) ;
}
static void F_24 ( void )
{
F_25 ( V_66 L_19
L_20 ) ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_33 * V_35 , * V_67 , * V_68 ;
const struct V_36 * V_37 ;
T_2 * V_26 = ( T_2 * ) V_2 -> V_5 ;
int V_69 , V_70 , V_71 ;
F_24 () ;
F_27 ( & V_72 ) ;
V_67 = V_73 ;
V_68 = V_26 -> V_74 ;
F_2 ( V_2 , L_21 ) ;
F_2 ( V_2 , L_22 ) ;
while ( V_67 -> V_6 || ( V_68 && V_68 -> V_6 ) ) {
if ( V_67 -> V_6 && V_68 && V_68 -> V_6 ) {
if ( strcmp ( V_68 -> V_6 , V_67 -> V_6 ) < 0 )
V_35 = V_68 ++ ;
else
V_35 = V_67 ++ ;
} else if ( V_68 && V_68 -> V_6 ) {
V_35 = V_68 ++ ;
} else
V_35 = V_67 ++ ;
V_70 = V_35 -> V_75 ? V_35 -> V_75 ( V_26 ) : 1 ;
V_71 = V_35 -> V_76 ? V_35 -> V_76 ( V_26 ) : 1 ;
F_2 ( V_2 , L_23 , V_35 -> V_6 ) ;
V_69 = F_18 ( V_26 , V_35 ) ;
if ( V_69 >= 0 )
F_2 ( V_2 , L_24 , V_69 * V_70 / V_71 ) ;
else
F_2 ( V_2 , L_25 , L_26 ) ;
F_2 ( V_2 , L_27 , ( V_35 -> V_46 * V_70 + V_71 - 1 ) / V_71 , V_35 -> V_47 * V_70 / V_71 ) ;
V_37 = V_35 -> V_35 ;
if ( V_37 -> V_39 )
F_2 ( V_2 , L_28 ) ;
if ( V_37 -> V_42 )
F_2 ( V_2 , L_29 ) ;
F_2 ( V_2 , L_30 ) ;
}
F_28 ( & V_72 ) ;
return 0 ;
}
static int F_29 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_26 , F_5 ( V_21 ) -> V_23 ) ;
}
static T_5 F_30 ( struct V_22 * V_22 , const char T_6 * V_77 ,
T_7 V_78 , T_8 * V_79 )
{
T_2 * V_26 = ( T_2 * ) F_5 ( F_31 ( V_22 ) ) -> V_23 ;
char V_6 [ V_80 + 1 ] ;
int V_81 = 0 , V_70 , V_71 ;
unsigned long V_82 ;
const struct V_33 * V_35 ;
char * V_27 , * V_83 ;
if ( ! F_20 ( V_40 ) )
return - V_41 ;
F_24 () ;
if ( V_78 >= V_84 )
return - V_38 ;
V_83 = V_27 = ( char * ) F_32 ( V_85 ) ;
if ( ! V_27 )
return - V_30 ;
if ( F_33 ( V_27 , V_77 , V_78 ) ) {
F_34 ( ( unsigned long ) V_27 ) ;
return - V_86 ;
}
V_27 [ V_78 ] = '\0' ;
while ( V_78 && isspace ( * V_83 ) ) {
-- V_78 ;
++ V_83 ;
}
do {
char * V_87 = V_83 ;
V_82 = V_78 ;
while ( V_82 > 0 ) {
unsigned V_31 ;
char * V_88 = V_87 ;
while ( V_82 > 0 && * V_87 != ':' ) {
-- V_82 ;
V_87 ++ ;
}
if ( * V_87 != ':' )
goto V_89;
if ( V_87 - V_88 > V_80 )
goto V_89;
memcpy ( V_6 , V_88 , V_87 - V_88 ) ;
V_6 [ V_87 - V_88 ] = 0 ;
if ( V_82 > 0 ) {
-- V_82 ;
V_87 ++ ;
} else
goto V_89;
V_31 = F_35 ( V_87 , & V_88 , 10 ) ;
V_82 -= V_88 - V_87 ;
V_87 = V_88 ;
if ( V_82 > 0 && ! isspace ( * V_87 ) )
goto V_89;
while ( V_82 > 0 && isspace ( * V_87 ) ) {
-- V_82 ;
++ V_87 ;
}
F_27 ( & V_72 ) ;
V_35 = F_17 ( V_73 , V_6 ) ;
if ( ! V_35 ) {
if ( V_26 -> V_74 )
V_35 = F_17 ( V_26 -> V_74 , V_6 ) ;
if ( ! V_35 ) {
F_28 ( & V_72 ) ;
goto V_89;
}
}
if ( V_81 ) {
V_70 = V_35 -> V_75 ? V_35 -> V_75 ( V_26 ) : 1 ;
V_71 = V_35 -> V_76 ? V_35 -> V_76 ( V_26 ) : 1 ;
F_19 ( V_26 , V_35 , V_31 * V_71 / V_70 ) ;
}
F_28 ( & V_72 ) ;
}
} while ( ! V_81 ++ );
F_34 ( ( unsigned long ) V_27 ) ;
return V_78 ;
V_89:
F_34 ( ( unsigned long ) V_27 ) ;
F_36 ( L_31 , V_90 ) ;
return - V_38 ;
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
T_2 * V_26 = ( T_2 * ) V_2 -> V_5 ;
F_2 ( V_2 , L_33 ,
V_26 -> V_91 , V_26 -> V_92 , V_26 -> V_93 ) ;
F_2 ( V_2 , L_34 ,
V_26 -> V_94 , V_26 -> V_95 , V_26 -> V_96 ) ;
return 0 ;
}
static int F_40 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_39 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_41 ( struct V_1 * V_97 , void * V_3 )
{
T_2 * V_26 = ( T_2 * ) V_97 -> V_5 ;
char * V_2 = ( char * ) & V_26 -> V_98 [ V_99 ] ;
F_2 ( V_97 , L_35 , V_2 [ 0 ] ? V_2 : L_36 ) ;
return 0 ;
}
static int F_42 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_41 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_26 = ( T_2 * ) V_2 -> V_5 ;
struct V_100 * V_101 = & V_26 -> V_102 ;
struct V_103 * V_104 ;
if ( V_101 -> V_105 ) {
V_104 = F_44 ( V_101 -> V_105 ) ;
F_2 ( V_2 , L_37 ,
V_101 -> V_105 -> V_6 , V_104 -> V_106 ) ;
} else
F_2 ( V_2 , L_38 ) ;
return 0 ;
}
static int F_45 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_43 , F_5 ( V_21 ) -> V_23 ) ;
}
static int F_46 ( T_2 * V_26 , const char * V_105 )
{
struct V_100 * V_101 = & V_26 -> V_102 ;
int V_107 = 1 ;
int V_108 ;
F_47 ( V_101 ) ;
F_48 ( V_26 -> V_109 , V_105 , sizeof( V_26 -> V_109 ) ) ;
V_108 = F_49 ( V_101 ) ;
if ( V_108 < 0 )
F_36 ( V_66 L_39 ,
V_90 , V_108 ) ;
V_26 -> V_109 [ 0 ] = 0 ;
if ( V_101 -> V_105 == NULL ) {
V_108 = F_49 ( V_101 ) ;
if ( V_108 < 0 )
F_36 ( V_66
L_40 ,
V_90 , V_108 ) ;
}
if ( V_101 -> V_105 && ! strcmp ( V_101 -> V_105 -> V_6 , V_105 ) )
V_107 = 0 ;
return V_107 ;
}
static T_5 F_50 ( struct V_22 * V_22 , const char T_6 * V_77 ,
T_7 V_78 , T_8 * V_79 )
{
T_2 * V_26 = ( T_2 * ) F_5 ( F_31 ( V_22 ) ) -> V_23 ;
char V_6 [ 32 ] ;
if ( ! F_20 ( V_40 ) )
return - V_41 ;
if ( V_78 > 31 )
V_78 = 31 ;
if ( F_33 ( V_6 , V_77 , V_78 ) )
return - V_86 ;
V_6 [ V_78 ] = '\0' ;
if ( F_46 ( V_26 , V_6 ) )
return - V_38 ;
return V_78 ;
}
static int F_51 ( struct V_1 * V_2 , void * V_3 )
{
T_2 * V_26 = ( T_2 * ) V_2 -> V_5 ;
const char * V_110 ;
switch ( V_26 -> V_110 ) {
case V_111 : V_110 = L_41 ; break;
case V_112 : V_110 = L_42 ; break;
case V_113 : V_110 = L_43 ; break;
case V_114 : V_110 = L_44 ; break;
case V_115 : V_110 = L_45 ; break;
default: V_110 = L_46 ; break;
}
F_52 ( V_2 , V_110 ) ;
return 0 ;
}
static int F_53 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_4 ( V_22 , F_51 , F_5 ( V_21 ) -> V_23 ) ;
}
static void F_54 ( struct V_116 * V_117 , T_9 * V_87 , void * V_23 )
{
struct V_116 * V_118 ;
if ( ! V_117 || ! V_87 )
return;
while ( V_87 -> V_6 != NULL ) {
V_118 = F_55 ( V_87 -> V_6 , V_87 -> V_119 , V_117 , V_87 -> V_120 , V_23 ) ;
if ( ! V_118 ) return;
V_87 ++ ;
}
}
static void F_56 ( struct V_116 * V_117 , T_9 * V_87 )
{
if ( ! V_117 || ! V_87 )
return;
while ( V_87 -> V_6 != NULL ) {
F_57 ( V_87 -> V_6 , V_117 ) ;
V_87 ++ ;
}
}
void F_58 ( T_2 * V_26 , struct V_103 * V_105 )
{
F_27 ( & V_72 ) ;
V_26 -> V_74 = V_105 -> V_121 ( V_26 ) ;
F_28 ( & V_72 ) ;
F_54 ( V_26 -> V_122 , V_105 -> V_123 ( V_26 ) , V_26 ) ;
}
void F_59 ( T_2 * V_26 , struct V_103 * V_105 )
{
F_56 ( V_26 -> V_122 , V_105 -> V_123 ( V_26 ) ) ;
F_27 ( & V_72 ) ;
V_26 -> V_74 = NULL ;
F_28 ( & V_72 ) ;
}
void F_60 ( T_1 * V_4 )
{
struct V_116 * V_118 ;
struct V_116 * V_124 = V_4 -> V_122 ;
T_2 * V_26 ;
char V_6 [ 64 ] ;
int V_32 ;
F_61 (i, drive, hwif) {
if ( ( V_26 -> V_125 & V_126 ) == 0 )
continue;
V_26 -> V_122 = F_62 ( V_26 -> V_6 , V_124 ) ;
if ( V_26 -> V_122 )
F_54 ( V_26 -> V_122 , V_127 , V_26 ) ;
sprintf ( V_6 , L_47 , ( V_26 -> V_6 [ 2 ] - 'a' ) / 2 , V_26 -> V_6 ) ;
V_118 = F_63 ( V_26 -> V_6 , V_128 , V_6 ) ;
if ( ! V_118 ) return;
}
}
void F_64 ( T_2 * V_26 )
{
if ( V_26 -> V_122 ) {
F_56 ( V_26 -> V_122 , V_127 ) ;
F_57 ( V_26 -> V_6 , V_128 ) ;
F_57 ( V_26 -> V_6 , V_26 -> V_4 -> V_122 ) ;
V_26 -> V_122 = NULL ;
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
static int F_67 ( struct V_130 * V_131 , void * V_23 )
{
struct V_103 * V_104 = F_44 ( V_131 ) ;
struct V_1 * V_83 = V_23 ;
F_2 ( V_83 , L_37 , V_131 -> V_6 , V_104 -> V_106 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_83 , void * V_87 )
{
int V_108 ;
V_108 = F_69 ( & V_132 , NULL , V_83 , F_67 ) ;
if ( V_108 < 0 )
F_36 ( V_66 L_48 ,
V_90 , V_108 ) ;
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
