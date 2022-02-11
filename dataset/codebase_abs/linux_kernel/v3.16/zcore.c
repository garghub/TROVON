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
V_65 . V_66 . V_67 * V_68 ) ;
}
static int F_28 ( struct V_56 * V_56 , struct V_43 * V_57 )
{
struct V_69 * V_70 ;
char * V_7 ;
int V_29 = 0 ;
V_7 = F_29 ( V_65 . V_66 . V_67 * V_68 , V_71 ) ;
if ( ! V_7 ) {
return - V_23 ;
}
F_30 (memory, reg) {
sprintf ( V_7 + ( V_29 ++ * V_68 ) , L_4 ,
( unsigned long long ) V_70 -> V_72 ,
( unsigned long long ) V_70 -> V_48 ) ;
}
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
if ( V_73 ) {
F_16 ( V_74 , V_73 ) ;
F_16 ( V_75 , NULL ) ;
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
static char V_76 [ 18 ] ;
if ( V_10 )
snprintf ( V_76 , sizeof( V_76 ) , L_5 , F_19 () ) ;
else
snprintf ( V_76 , sizeof( V_76 ) , L_6 ) ;
return F_27 ( V_7 , V_3 , V_44 , V_76 , strlen ( V_76 ) ) ;
}
static T_3 F_37 ( struct V_43 * V_57 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_44 )
{
char V_77 ;
if ( * V_44 != 0 )
return - V_78 ;
if ( F_38 ( & V_77 , V_7 , 1 ) )
return - V_16 ;
if ( V_77 != '0' )
return - V_53 ;
F_15 () ;
return V_3 ;
}
static void T_2 F_39 ( struct V_21 * V_79 )
{
memset ( & V_79 -> V_80 , 0xff , sizeof( V_79 -> V_80 ) ) ;
memset ( & V_79 -> V_81 , 0xff , sizeof( V_79 -> V_81 ) ) ;
memset ( & V_79 -> V_82 , 0xff , sizeof( V_79 -> V_82 ) ) ;
memset ( & V_79 -> V_83 , 0xff , sizeof( V_79 -> V_83 ) ) ;
memset ( & V_79 -> V_41 , 0xff , sizeof( V_79 -> V_41 ) ) ;
memset ( & V_79 -> V_84 , 0xff , sizeof( V_79 -> V_84 ) ) ;
memset ( & V_79 -> V_85 , 0xff , sizeof( V_79 -> V_85 ) ) ;
memset ( & V_79 -> V_86 , 0xff , sizeof( V_79 -> V_86 ) ) ;
memset ( & V_79 -> V_87 , 0xff , sizeof( V_79 -> V_87 ) ) ;
}
static void T_2 F_39 ( struct V_21 * V_79 )
{
memset ( & V_79 -> V_85 , 0xff , sizeof( V_79 -> V_85 ) ) ;
memset ( & V_79 -> V_86 , 0xff , sizeof( V_79 -> V_86 ) ) ;
memset ( & V_79 -> V_83 , 0xff , sizeof( V_79 -> V_83 ) ) ;
memset ( & V_79 -> V_41 , 0xff , sizeof( V_79 -> V_41 ) ) ;
memset ( & V_79 -> V_88 , 0xff , sizeof( V_79 -> V_88 ) ) ;
memset ( & V_79 -> V_89 , 0xff , sizeof( V_79 -> V_89 ) ) ;
memset ( & V_79 -> V_81 , 0xff , sizeof( V_79 -> V_81 ) ) ;
memset ( & V_79 -> V_82 , 0xff , sizeof( V_79 -> V_82 ) ) ;
memset ( & V_79 -> V_84 , 0xff , sizeof( V_79 -> V_84 ) ) ;
memset ( & V_79 -> V_87 , 0xff , sizeof( V_79 -> V_87 ) ) ;
}
static int T_2 F_40 ( enum V_19 V_20 , unsigned long V_90 )
{
int V_49 ;
switch ( V_20 ) {
case V_91 :
F_41 ( L_7 ) ;
break;
case V_92 :
F_41 ( L_8 ) ;
break;
default:
F_41 ( L_9 , V_20 ) ;
return - V_53 ;
}
V_24 . V_25 = V_93 ;
V_24 . V_26 = sizeof( struct V_21 ) ;
V_24 . V_20 = V_20 ;
F_39 ( & V_24 . V_30 ) ;
V_49 = F_9 ( V_20 ) ;
if ( V_49 )
return V_49 ;
V_24 . V_51 = V_90 ;
return 0 ;
}
static int T_2 F_42 ( void )
{
if ( ! F_19 () ) {
F_4 ( L_10 ) ;
return - V_94 ;
}
return 0 ;
}
static int T_2 F_43 ( unsigned long * V_95 , unsigned long * V_32 )
{
struct V_69 * V_70 ;
F_30 (memory, reg) {
* V_95 += V_70 -> V_48 ;
* V_32 = F_44 (unsigned long, *end, reg->base + reg->size) ;
}
return 0 ;
}
static void T_2 F_45 ( int V_20 , struct V_55 * V_96 ,
unsigned long V_51 )
{
T_5 V_38 ;
int V_29 ;
if ( V_20 == V_91 )
V_96 -> V_19 = V_97 ;
else
V_96 -> V_19 = V_98 ;
V_96 -> V_51 = V_51 ;
V_96 -> V_99 = V_51 ;
V_96 -> V_90 = V_24 . V_51 ;
V_96 -> V_100 = V_51 / V_8 ;
V_96 -> V_101 = F_46 () ;
F_47 ( & V_96 -> V_102 ) ;
for ( V_29 = 0 ; V_29 < V_33 . V_3 ; V_29 ++ ) {
V_38 = V_33 . V_40 [ V_29 ] -> V_41 ;
V_96 -> V_103 ++ ;
if ( ! V_38 )
continue;
V_96 -> V_104 [ V_96 -> V_105 ] = V_38 ;
V_96 -> V_105 ++ ;
}
}
static int T_2 F_48 ( void )
{
struct V_106 V_106 ;
int V_49 ;
V_49 = F_8 ( & V_106 , V_107 , sizeof( V_106 ) ) ;
if ( V_49 )
return V_49 ;
if ( V_106 . V_108 == 0 )
return 0 ;
V_73 = ( void * ) F_49 ( V_71 ) ;
if ( ! V_73 )
return - V_23 ;
if ( V_106 . V_108 < F_19 () )
V_49 = F_8 ( V_73 , V_106 . V_108 , V_8 ) ;
else
V_49 = F_50 ( V_73 , ( void * ) V_106 . V_108 , V_8 ) ;
if ( V_49 || F_51 ( V_73 , V_73 -> V_96 . V_28 , 0 ) !=
V_106 . V_109 ) {
F_4 ( L_11 ) ;
F_52 ( ( unsigned long ) V_73 ) ;
V_73 = NULL ;
}
return 0 ;
}
static int T_2 F_53 ( void )
{
unsigned long V_51 , V_90 ;
unsigned char V_20 ;
int V_49 ;
V_51 = V_90 = 0 ;
if ( V_110 . type != V_111 )
return - V_11 ;
if ( V_112 )
return - V_11 ;
V_113 = F_54 ( L_12 , 4 , 1 , 4 * sizeof( long ) ) ;
F_55 ( V_113 , & V_114 ) ;
F_56 ( V_113 , 6 ) ;
F_4 ( L_13 , V_110 . V_115 . V_116 . V_117 . V_118 ) ;
F_4 ( L_14 , ( unsigned long long ) V_110 . V_115 . V_116 . V_119 ) ;
F_4 ( L_15 , ( unsigned long long ) V_110 . V_115 . V_116 . V_120 ) ;
V_49 = F_57 () ;
if ( V_49 )
goto V_54;
V_49 = F_42 () ;
if ( V_49 )
goto V_54;
V_10 = 1 ;
V_49 = F_8 ( & V_20 , V_121 , 1 ) ;
if ( V_49 )
goto V_54;
#ifdef F_58
if ( V_20 == V_92 ) {
F_41 ( L_16
L_17 ) ;
V_49 = - V_53 ;
goto V_54;
}
#else
if ( V_20 == V_91 ) {
F_41 ( L_18
L_19 ) ;
V_49 = - V_53 ;
goto V_54;
}
#endif
V_49 = F_43 ( & V_51 , & V_90 ) ;
if ( V_49 )
goto V_54;
V_49 = F_40 ( V_20 , V_90 ) ;
if ( V_49 )
goto V_54;
F_45 ( V_20 , & V_55 , V_51 ) ;
V_49 = F_48 () ;
if ( V_49 )
goto V_54;
V_122 = F_59 ( L_12 , NULL ) ;
if ( ! V_122 ) {
V_49 = - V_23 ;
goto V_54;
}
V_123 = F_60 ( L_20 , V_124 , V_122 , NULL ,
& V_125 ) ;
if ( ! V_123 ) {
V_49 = - V_23 ;
goto V_126;
}
V_127 = F_60 ( L_21 , V_124 , V_122 ,
NULL , & V_128 ) ;
if ( ! V_127 ) {
V_49 = - V_23 ;
goto V_129;
}
V_130 = F_60 ( L_22 , V_124 , V_122 ,
NULL , & V_131 ) ;
if ( ! V_130 ) {
V_49 = - V_23 ;
goto V_132;
}
V_133 = F_60 ( L_23 , V_124 | V_134 , V_122 ,
NULL , & V_135 ) ;
if ( ! V_133 ) {
V_49 = - V_23 ;
goto V_136;
}
return 0 ;
V_136:
F_61 ( V_130 ) ;
V_132:
F_61 ( V_127 ) ;
V_129:
F_61 ( V_123 ) ;
V_126:
F_61 ( V_122 ) ;
V_54:
F_16 ( V_42 , NULL ) ;
return V_49 ;
}
static void T_6 F_62 ( void )
{
F_63 ( V_113 ) ;
F_64 () ;
F_52 ( ( unsigned long ) V_73 ) ;
F_61 ( V_133 ) ;
F_61 ( V_130 ) ;
F_61 ( V_127 ) ;
F_61 ( V_123 ) ;
F_61 ( V_122 ) ;
F_16 ( V_42 , NULL ) ;
}
