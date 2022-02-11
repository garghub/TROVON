int F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 , int V_4 )
{
int V_5 , V_6 ;
static char V_7 [ V_8 ] V_9 ( ( F_2 ( V_8 ) ) ) ;
if ( ! V_10 )
return - V_11 ;
if ( V_3 == 0 )
return 0 ;
V_5 = 0 ;
if ( ( V_2 % V_8 ) != 0 ) {
V_6 = V_2 / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
V_5 = F_5 ( ( V_8 - ( V_2 % V_8 ) ) , V_3 ) ;
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 ,
V_7 + ( V_2 % V_8 ) , V_5 ) )
return - V_16 ;
} else
memcpy ( V_1 , V_7 + ( V_2 % V_8 ) , V_5 ) ;
}
if ( V_5 == V_3 )
goto V_17;
for (; ( V_5 + V_8 ) <= V_3 ; V_5 += V_8 ) {
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 + V_5 ,
V_7 , V_8 ) )
return - V_16 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_8 ) ;
}
if ( V_5 == V_3 )
goto V_17;
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 + V_5 , V_7 ,
V_3 - V_5 ) )
return - V_16 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_3 - V_5 ) ;
V_17:
return 0 ;
}
static int F_7 ( void V_15 * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( ( void V_14 * ) V_1 , V_2 , V_3 , V_13 ) ;
}
static int F_8 ( void * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , V_18 ) ;
}
static int T_2 F_9 ( enum V_19 V_20 )
{
struct V_21 * V_22 ;
V_22 = F_10 ( 0 ) ;
if ( ! V_22 )
return - V_23 ;
if ( F_8 ( V_22 , V_24 . V_25 , V_24 . V_26 ) < 0 ) {
F_4 ( L_2 ) ;
F_11 ( V_22 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_12 ( void V_15 * V_7 , void * V_22 , int V_27 , int V_28 )
{
int V_29 ;
char * V_30 = ( char * ) & V_24 . V_30 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
if ( ! V_30 [ V_29 + V_27 ] )
continue;
if ( F_6 ( V_7 + V_29 , V_22 + V_27 + V_29 , 1 ) )
return - V_16 ;
}
return 0 ;
}
static int F_13 ( char V_15 * V_7 , unsigned long V_31 , T_1 V_3 )
{
unsigned long V_32 ;
int V_29 ;
if ( V_3 == 0 )
return 0 ;
V_32 = V_31 + V_3 ;
for ( V_29 = 0 ; V_29 < V_33 . V_3 ; V_29 ++ ) {
unsigned long V_34 , V_35 ;
unsigned long V_36 , V_37 ;
unsigned long V_38 ;
unsigned long V_27 , V_28 , V_39 ;
struct V_21 * V_21 = V_33 . V_40 [ V_29 ] ;
V_38 = V_21 -> V_41 ;
V_36 = V_38 + V_24 . V_25 ;
V_37 = V_38 + V_24 . V_25 + V_24 . V_26 ;
if ( ( V_32 < V_36 ) || ( V_31 > V_37 ) )
continue;
V_34 = F_14 ( V_31 , V_36 ) ;
V_35 = F_5 ( V_32 , V_37 ) ;
V_39 = V_34 - V_31 ;
V_27 = V_34 - V_36 ;
V_28 = V_35 - V_34 ;
F_4 ( L_3 , V_31 ) ;
if ( F_12 ( V_7 + V_39 , V_21 , V_27 , V_28 ) )
return - V_16 ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( V_42 , NULL ) ;
V_10 = 0 ;
}
static T_3 F_17 ( struct V_43 * V_43 , char V_15 * V_7 , T_1 V_3 ,
T_4 * V_44 )
{
unsigned long V_45 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_48 ;
int V_49 ;
F_18 ( & V_50 ) ;
if ( * V_44 > ( V_24 . V_51 + V_52 ) ) {
V_49 = - V_53 ;
goto V_54;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_24 . V_51 + V_52 - * V_44 ) ) ;
if ( * V_44 < V_52 ) {
V_48 = F_5 ( V_3 , ( T_1 ) ( V_52 - * V_44 ) ) ;
if ( F_6 ( V_7 , & V_55 + * V_44 , V_48 ) ) {
V_49 = - V_16 ;
goto V_54;
}
V_47 = V_48 ;
V_45 = 0 ;
} else {
V_47 = 0 ;
V_45 = * V_44 - V_52 ;
}
V_46 = 0 ;
if ( * V_44 < F_19 () + V_52 ) {
V_48 = F_5 ( ( V_3 - V_47 ) ,
( T_1 ) ( F_19 () - V_45 ) ) ;
V_49 = F_7 ( V_7 + V_47 , V_45 , V_48 ) ;
if ( V_49 )
goto V_54;
V_46 += V_48 ;
}
V_48 = V_3 - V_46 - V_47 ;
V_49 = F_20 ( V_7 + V_47 + V_46 ,
( void * ) V_45 + V_46 , V_48 ) ;
if ( V_49 )
goto V_54;
if ( F_13 ( V_7 + V_47 , V_45 , V_3 - V_47 ) ) {
V_49 = - V_16 ;
goto V_54;
}
* V_44 += V_3 ;
V_54:
F_21 ( & V_50 ) ;
return ( V_49 < 0 ) ? V_49 : V_3 ;
}
static int F_22 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
if ( ! V_10 )
return - V_11 ;
else
return F_23 ( V_58 ) ? 0 : - V_59 ;
}
static int F_24 ( struct V_56 * V_56 , struct V_43 * V_60 )
{
if ( V_10 )
F_15 () ;
return 0 ;
}
static T_4 F_25 ( struct V_43 * V_43 , T_4 V_61 , int V_62 )
{
T_4 V_49 ;
F_18 ( & V_50 ) ;
switch ( V_62 ) {
case 0 :
V_43 -> V_63 = V_61 ;
V_49 = V_43 -> V_63 ;
break;
case 1 :
V_43 -> V_63 += V_61 ;
V_49 = V_43 -> V_63 ;
break;
default:
V_49 = - V_53 ;
}
F_21 ( & V_50 ) ;
return V_49 ;
}
static T_3 F_26 ( struct V_43 * V_57 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_44 )
{
return F_27 ( V_7 , V_3 , V_44 , V_57 -> V_64 ,
V_65 * V_66 ) ;
}
static int F_28 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
int V_29 ;
char * V_7 ;
struct V_67 * V_68 ;
V_68 = F_29 ( V_65 * sizeof( struct V_67 ) ,
V_69 ) ;
if ( ! V_68 )
return - V_23 ;
F_30 ( V_68 , 0 ) ;
V_7 = F_29 ( V_65 * V_66 , V_69 ) ;
if ( ! V_7 ) {
F_11 ( V_68 ) ;
return - V_23 ;
}
for ( V_29 = 0 ; V_29 < V_65 ; V_29 ++ ) {
sprintf ( V_7 + ( V_29 * V_66 ) , L_4 ,
( unsigned long long ) V_68 [ V_29 ] . V_70 ,
( unsigned long long ) V_68 [ V_29 ] . V_48 ) ;
if ( V_68 [ V_29 ] . V_48 == 0 )
break;
}
F_11 ( V_68 ) ;
V_57 -> V_64 = V_7 ;
return F_31 ( V_56 , V_57 ) ;
}
static int F_32 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
F_11 ( V_57 -> V_64 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_43 * V_57 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_44 )
{
if ( V_71 ) {
F_16 ( V_72 , V_71 ) ;
F_16 ( V_73 , NULL ) ;
}
return V_3 ;
}
static int F_34 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
return F_31 ( V_56 , V_57 ) ;
}
static int F_35 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
return 0 ;
}
static T_3 F_36 ( struct V_43 * V_57 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_44 )
{
static char V_74 [ 18 ] ;
if ( V_10 )
snprintf ( V_74 , sizeof( V_74 ) , L_5 , F_19 () ) ;
else
snprintf ( V_74 , sizeof( V_74 ) , L_6 ) ;
return F_27 ( V_7 , V_3 , V_44 , V_74 , strlen ( V_74 ) ) ;
}
static T_3 F_37 ( struct V_43 * V_57 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_44 )
{
char V_75 ;
if ( * V_44 != 0 )
return - V_76 ;
if ( F_38 ( & V_75 , V_7 , 1 ) )
return - V_16 ;
if ( V_75 != '0' )
return - V_53 ;
F_15 () ;
return V_3 ;
}
static void T_2 F_39 ( struct V_21 * V_77 )
{
memset ( & V_77 -> V_78 , 0xff , sizeof( V_77 -> V_78 ) ) ;
memset ( & V_77 -> V_79 , 0xff , sizeof( V_77 -> V_79 ) ) ;
memset ( & V_77 -> V_80 , 0xff , sizeof( V_77 -> V_80 ) ) ;
memset ( & V_77 -> V_81 , 0xff , sizeof( V_77 -> V_81 ) ) ;
memset ( & V_77 -> V_41 , 0xff , sizeof( V_77 -> V_41 ) ) ;
memset ( & V_77 -> V_82 , 0xff , sizeof( V_77 -> V_82 ) ) ;
memset ( & V_77 -> V_83 , 0xff , sizeof( V_77 -> V_83 ) ) ;
memset ( & V_77 -> V_84 , 0xff , sizeof( V_77 -> V_84 ) ) ;
memset ( & V_77 -> V_85 , 0xff , sizeof( V_77 -> V_85 ) ) ;
}
static void T_2 F_39 ( struct V_21 * V_77 )
{
memset ( & V_77 -> V_83 , 0xff , sizeof( V_77 -> V_83 ) ) ;
memset ( & V_77 -> V_84 , 0xff , sizeof( V_77 -> V_84 ) ) ;
memset ( & V_77 -> V_81 , 0xff , sizeof( V_77 -> V_81 ) ) ;
memset ( & V_77 -> V_41 , 0xff , sizeof( V_77 -> V_41 ) ) ;
memset ( & V_77 -> V_86 , 0xff , sizeof( V_77 -> V_86 ) ) ;
memset ( & V_77 -> V_87 , 0xff , sizeof( V_77 -> V_87 ) ) ;
memset ( & V_77 -> V_79 , 0xff , sizeof( V_77 -> V_79 ) ) ;
memset ( & V_77 -> V_80 , 0xff , sizeof( V_77 -> V_80 ) ) ;
memset ( & V_77 -> V_82 , 0xff , sizeof( V_77 -> V_82 ) ) ;
memset ( & V_77 -> V_85 , 0xff , sizeof( V_77 -> V_85 ) ) ;
}
static int T_2 F_40 ( enum V_19 V_20 , unsigned long V_88 )
{
int V_49 ;
switch ( V_20 ) {
case V_89 :
F_41 ( L_7 ) ;
break;
case V_90 :
F_41 ( L_8 ) ;
break;
default:
F_41 ( L_9 , V_20 ) ;
return - V_53 ;
}
V_24 . V_25 = V_91 ;
V_24 . V_26 = sizeof( struct V_21 ) ;
V_24 . V_20 = V_20 ;
F_39 ( & V_24 . V_30 ) ;
V_49 = F_9 ( V_20 ) ;
if ( V_49 )
return V_49 ;
V_24 . V_51 = V_88 ;
return 0 ;
}
static int T_2 F_42 ( void )
{
if ( ! F_19 () ) {
F_4 ( L_10 ) ;
return - V_92 ;
}
return 0 ;
}
static int T_2 F_43 ( unsigned long * V_93 , unsigned long * V_32 )
{
int V_29 ;
struct V_67 * V_68 ;
V_68 = F_29 ( V_65 * sizeof( struct V_67 ) ,
V_69 ) ;
if ( ! V_68 )
return - V_23 ;
F_30 ( V_68 , 0 ) ;
for ( V_29 = 0 ; V_29 < V_65 ; V_29 ++ ) {
if ( V_68 [ V_29 ] . V_48 == 0 )
break;
* V_93 += V_68 [ V_29 ] . V_48 ;
* V_32 = F_14 ( * V_32 , V_68 [ V_29 ] . V_70 + V_68 [ V_29 ] . V_48 ) ;
}
F_11 ( V_68 ) ;
return 0 ;
}
static void T_2 F_44 ( int V_20 , struct V_55 * V_94 ,
unsigned long V_51 )
{
T_5 V_38 ;
int V_29 ;
if ( V_20 == V_89 )
V_94 -> V_19 = V_95 ;
else
V_94 -> V_19 = V_96 ;
V_94 -> V_51 = V_51 ;
V_94 -> V_97 = V_51 ;
V_94 -> V_88 = V_24 . V_51 ;
V_94 -> V_98 = V_51 / V_8 ;
V_94 -> V_99 = F_45 () ;
F_46 ( & V_94 -> V_100 ) ;
for ( V_29 = 0 ; V_29 < V_33 . V_3 ; V_29 ++ ) {
V_38 = V_33 . V_40 [ V_29 ] -> V_41 ;
V_94 -> V_101 ++ ;
if ( ! V_38 )
continue;
V_94 -> V_102 [ V_94 -> V_103 ] = V_38 ;
V_94 -> V_103 ++ ;
}
}
static int T_2 F_47 ( void )
{
struct V_104 V_104 ;
int V_49 ;
V_49 = F_8 ( & V_104 , V_105 , sizeof( V_104 ) ) ;
if ( V_49 )
return V_49 ;
if ( V_104 . V_106 == 0 )
return 0 ;
V_71 = ( void * ) F_48 ( V_69 ) ;
if ( ! V_71 )
return - V_23 ;
if ( V_104 . V_106 < F_19 () )
V_49 = F_8 ( V_71 , V_104 . V_106 , V_8 ) ;
else
V_49 = F_49 ( V_71 , ( void * ) V_104 . V_106 , V_8 ) ;
if ( V_49 || F_50 ( V_71 , V_71 -> V_94 . V_28 , 0 ) !=
V_104 . V_107 ) {
F_4 ( L_11 ) ;
F_51 ( ( unsigned long ) V_71 ) ;
V_71 = NULL ;
}
return 0 ;
}
static int T_2 F_52 ( void )
{
unsigned long V_51 , V_88 ;
unsigned char V_20 ;
int V_49 ;
V_51 = V_88 = 0 ;
if ( V_108 . type != V_109 )
return - V_11 ;
if ( V_110 )
return - V_11 ;
V_111 = F_53 ( L_12 , 4 , 1 , 4 * sizeof( long ) ) ;
F_54 ( V_111 , & V_112 ) ;
F_55 ( V_111 , 6 ) ;
F_4 ( L_13 , V_108 . V_113 . V_114 . V_115 . V_116 ) ;
F_4 ( L_14 , ( unsigned long long ) V_108 . V_113 . V_114 . V_117 ) ;
F_4 ( L_15 , ( unsigned long long ) V_108 . V_113 . V_114 . V_118 ) ;
V_49 = F_56 () ;
if ( V_49 )
goto V_54;
V_49 = F_42 () ;
if ( V_49 )
goto V_54;
V_10 = 1 ;
V_49 = F_8 ( & V_20 , V_119 , 1 ) ;
if ( V_49 )
goto V_54;
#ifdef F_57
if ( V_20 == V_90 ) {
F_41 ( L_16
L_17 ) ;
V_49 = - V_53 ;
goto V_54;
}
#else
if ( V_20 == V_89 ) {
F_41 ( L_18
L_19 ) ;
V_49 = - V_53 ;
goto V_54;
}
#endif
V_49 = F_43 ( & V_51 , & V_88 ) ;
if ( V_49 )
goto V_54;
V_49 = F_40 ( V_20 , V_88 ) ;
if ( V_49 )
goto V_54;
F_44 ( V_20 , & V_55 , V_51 ) ;
V_49 = F_47 () ;
if ( V_49 )
goto V_54;
V_120 = F_58 ( L_12 , NULL ) ;
if ( ! V_120 ) {
V_49 = - V_23 ;
goto V_54;
}
V_121 = F_59 ( L_20 , V_122 , V_120 , NULL ,
& V_123 ) ;
if ( ! V_121 ) {
V_49 = - V_23 ;
goto V_124;
}
V_125 = F_59 ( L_21 , V_122 , V_120 ,
NULL , & V_126 ) ;
if ( ! V_125 ) {
V_49 = - V_23 ;
goto V_127;
}
V_128 = F_59 ( L_22 , V_122 , V_120 ,
NULL , & V_129 ) ;
if ( ! V_128 ) {
V_49 = - V_23 ;
goto V_130;
}
V_131 = F_59 ( L_23 , V_122 | V_132 , V_120 ,
NULL , & V_133 ) ;
if ( ! V_131 ) {
V_49 = - V_23 ;
goto V_134;
}
return 0 ;
V_134:
F_60 ( V_128 ) ;
V_130:
F_60 ( V_125 ) ;
V_127:
F_60 ( V_121 ) ;
V_124:
F_60 ( V_120 ) ;
V_54:
F_16 ( V_42 , NULL ) ;
return V_49 ;
}
static void T_6 F_61 ( void )
{
F_62 ( V_111 ) ;
F_63 () ;
F_51 ( ( unsigned long ) V_71 ) ;
F_60 ( V_131 ) ;
F_60 ( V_128 ) ;
F_60 ( V_125 ) ;
F_60 ( V_121 ) ;
F_60 ( V_120 ) ;
F_16 ( V_42 , NULL ) ;
}
