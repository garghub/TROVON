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
if ( F_8 ( & V_22 -> V_24 , V_25 . V_26 ,
V_25 . V_27 ) < 0 ) {
F_4 ( L_2 ) ;
F_11 ( V_22 ) ;
return - V_12 ;
}
if ( V_28 )
F_12 ( V_22 -> V_29 ) ;
return 0 ;
}
static int F_13 ( void V_15 * V_7 , void * V_24 , int V_30 , int V_31 )
{
int V_32 ;
char * V_33 = ( char * ) & V_25 . V_33 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( ! V_33 [ V_32 + V_30 ] )
continue;
if ( F_6 ( V_7 + V_32 , V_24 + V_30 + V_32 , 1 ) )
return - V_16 ;
}
return 0 ;
}
static int F_14 ( char V_15 * V_7 , unsigned long V_34 , T_1 V_3 )
{
unsigned long V_35 ;
int V_32 ;
if ( V_3 == 0 )
return 0 ;
V_35 = V_34 + V_3 ;
for ( V_32 = 0 ; V_32 < V_36 . V_3 ; V_32 ++ ) {
unsigned long V_37 , V_38 ;
unsigned long V_39 , V_40 ;
unsigned long V_41 ;
unsigned long V_30 , V_31 , V_42 ;
struct V_43 * V_43 = & V_36 . V_44 [ V_32 ] -> V_24 ;
V_41 = V_43 -> V_45 ;
V_39 = V_41 + V_25 . V_26 ;
V_40 = V_41 + V_25 . V_26 + V_25 . V_27 ;
if ( ( V_35 < V_39 ) || ( V_34 > V_40 ) )
continue;
V_37 = F_15 ( V_34 , V_39 ) ;
V_38 = F_5 ( V_35 , V_40 ) ;
V_42 = V_37 - V_34 ;
V_30 = V_37 - V_39 ;
V_31 = V_38 - V_37 ;
F_4 ( L_3 , V_34 ) ;
if ( F_13 ( V_7 + V_42 , V_43 , V_30 , V_31 ) )
return - V_16 ;
}
return 0 ;
}
static void F_16 ( void )
{
F_17 ( V_46 , NULL ) ;
V_10 = 0 ;
}
static T_3 F_18 ( struct V_47 * V_47 , char V_15 * V_7 , T_1 V_3 ,
T_4 * V_48 )
{
unsigned long V_49 ;
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
int V_53 ;
F_19 ( & V_54 ) ;
if ( * V_48 > ( V_25 . V_55 + V_56 ) ) {
V_53 = - V_57 ;
goto V_58;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_25 . V_55 + V_56 - * V_48 ) ) ;
if ( * V_48 < V_56 ) {
V_52 = F_5 ( V_3 , ( T_1 ) ( V_56 - * V_48 ) ) ;
if ( F_6 ( V_7 , & V_59 + * V_48 , V_52 ) ) {
V_53 = - V_16 ;
goto V_58;
}
V_51 = V_52 ;
V_49 = 0 ;
} else {
V_51 = 0 ;
V_49 = * V_48 - V_56 ;
}
V_50 = 0 ;
if ( * V_48 < F_20 () + V_56 ) {
V_52 = F_5 ( ( V_3 - V_51 ) ,
( T_1 ) ( F_20 () - V_49 ) ) ;
V_53 = F_7 ( V_7 + V_51 , V_49 , V_52 ) ;
if ( V_53 )
goto V_58;
V_50 += V_52 ;
}
V_52 = V_3 - V_50 - V_51 ;
V_53 = F_21 ( V_7 + V_51 + V_50 ,
( void * ) V_49 + V_50 , V_52 ) ;
if ( V_53 )
goto V_58;
if ( F_14 ( V_7 + V_51 , V_49 , V_3 - V_51 ) ) {
V_53 = - V_16 ;
goto V_58;
}
* V_48 += V_3 ;
V_58:
F_22 ( & V_54 ) ;
return ( V_53 < 0 ) ? V_53 : V_3 ;
}
static int F_23 ( struct V_60 * V_60 , struct V_47 * V_61 )
{
if ( ! V_10 )
return - V_11 ;
else
return F_24 ( V_62 ) ? 0 : - V_63 ;
}
static int F_25 ( struct V_60 * V_60 , struct V_47 * V_64 )
{
if ( V_10 )
F_16 () ;
return 0 ;
}
static T_4 F_26 ( struct V_47 * V_47 , T_4 V_65 , int V_66 )
{
T_4 V_53 ;
F_19 ( & V_54 ) ;
switch ( V_66 ) {
case 0 :
V_47 -> V_67 = V_65 ;
V_53 = V_47 -> V_67 ;
break;
case 1 :
V_47 -> V_67 += V_65 ;
V_53 = V_47 -> V_67 ;
break;
default:
V_53 = - V_57 ;
}
F_22 ( & V_54 ) ;
return V_53 ;
}
static T_3 F_27 ( struct V_47 * V_61 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
return F_28 ( V_7 , V_3 , V_48 , V_61 -> V_68 ,
V_69 . V_70 . V_71 * V_72 ) ;
}
static int F_29 ( struct V_60 * V_60 , struct V_47 * V_61 )
{
struct V_73 * V_74 ;
char * V_7 ;
int V_32 = 0 ;
V_7 = F_30 ( V_69 . V_70 . V_71 * V_72 , V_75 ) ;
if ( ! V_7 ) {
return - V_23 ;
}
F_31 (memory, reg) {
sprintf ( V_7 + ( V_32 ++ * V_72 ) , L_4 ,
( unsigned long long ) V_74 -> V_76 ,
( unsigned long long ) V_74 -> V_52 ) ;
}
V_61 -> V_68 = V_7 ;
return F_32 ( V_60 , V_61 ) ;
}
static int F_33 ( struct V_60 * V_60 , struct V_47 * V_61 )
{
F_11 ( V_61 -> V_68 ) ;
return 0 ;
}
static T_3 F_34 ( struct V_47 * V_61 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
if ( V_77 ) {
F_17 ( V_78 , V_77 ) ;
F_17 ( V_79 , NULL ) ;
}
return V_3 ;
}
static int F_35 ( struct V_60 * V_60 , struct V_47 * V_61 )
{
return F_32 ( V_60 , V_61 ) ;
}
static int F_36 ( struct V_60 * V_60 , struct V_47 * V_61 )
{
return 0 ;
}
static T_3 F_37 ( struct V_47 * V_61 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
static char V_80 [ 18 ] ;
if ( V_10 )
snprintf ( V_80 , sizeof( V_80 ) , L_5 , F_20 () ) ;
else
snprintf ( V_80 , sizeof( V_80 ) , L_6 ) ;
return F_28 ( V_7 , V_3 , V_48 , V_80 , strlen ( V_80 ) ) ;
}
static T_3 F_38 ( struct V_47 * V_61 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
char V_81 ;
if ( * V_48 != 0 )
return - V_82 ;
if ( F_39 ( & V_81 , V_7 , 1 ) )
return - V_16 ;
if ( V_81 != '0' )
return - V_57 ;
F_16 () ;
return V_3 ;
}
static void T_2 F_40 ( struct V_43 * V_83 )
{
memset ( & V_83 -> V_84 , 0xff , sizeof( V_83 -> V_84 ) ) ;
memset ( & V_83 -> V_85 , 0xff , sizeof( V_83 -> V_85 ) ) ;
memset ( & V_83 -> V_86 , 0xff , sizeof( V_83 -> V_86 ) ) ;
memset ( & V_83 -> V_87 , 0xff , sizeof( V_83 -> V_87 ) ) ;
memset ( & V_83 -> V_45 , 0xff , sizeof( V_83 -> V_45 ) ) ;
memset ( & V_83 -> V_88 , 0xff , sizeof( V_83 -> V_88 ) ) ;
memset ( & V_83 -> V_89 , 0xff , sizeof( V_83 -> V_89 ) ) ;
memset ( & V_83 -> V_90 , 0xff , sizeof( V_83 -> V_90 ) ) ;
memset ( & V_83 -> V_91 , 0xff , sizeof( V_83 -> V_91 ) ) ;
}
static void T_2 F_40 ( struct V_43 * V_83 )
{
memset ( & V_83 -> V_89 , 0xff , sizeof( V_83 -> V_89 ) ) ;
memset ( & V_83 -> V_90 , 0xff , sizeof( V_83 -> V_90 ) ) ;
memset ( & V_83 -> V_87 , 0xff , sizeof( V_83 -> V_87 ) ) ;
memset ( & V_83 -> V_45 , 0xff , sizeof( V_83 -> V_45 ) ) ;
memset ( & V_83 -> V_92 , 0xff , sizeof( V_83 -> V_92 ) ) ;
memset ( & V_83 -> V_93 , 0xff , sizeof( V_83 -> V_93 ) ) ;
memset ( & V_83 -> V_85 , 0xff , sizeof( V_83 -> V_85 ) ) ;
memset ( & V_83 -> V_86 , 0xff , sizeof( V_83 -> V_86 ) ) ;
memset ( & V_83 -> V_88 , 0xff , sizeof( V_83 -> V_88 ) ) ;
memset ( & V_83 -> V_91 , 0xff , sizeof( V_83 -> V_91 ) ) ;
}
static int T_2 F_41 ( enum V_19 V_20 , unsigned long V_94 )
{
int V_53 ;
switch ( V_20 ) {
case V_95 :
F_42 ( L_7 ) ;
break;
case V_96 :
F_42 ( L_8 ) ;
break;
default:
F_42 ( L_9 , V_20 ) ;
return - V_57 ;
}
V_25 . V_26 = V_97 ;
V_25 . V_27 = sizeof( struct V_43 ) ;
V_25 . V_20 = V_20 ;
F_40 ( & V_25 . V_33 ) ;
V_53 = F_9 ( V_20 ) ;
if ( V_53 )
return V_53 ;
V_25 . V_55 = V_94 ;
return 0 ;
}
static int T_2 F_43 ( void )
{
if ( ! F_20 () ) {
F_4 ( L_10 ) ;
return - V_98 ;
}
return 0 ;
}
static int T_2 F_44 ( unsigned long * V_99 , unsigned long * V_35 )
{
struct V_73 * V_74 ;
F_31 (memory, reg) {
* V_99 += V_74 -> V_52 ;
* V_35 = F_45 (unsigned long, *end, reg->base + reg->size) ;
}
return 0 ;
}
static void T_2 F_46 ( int V_20 , struct V_59 * V_100 ,
unsigned long V_55 )
{
T_5 V_41 ;
int V_32 ;
if ( V_20 == V_95 )
V_100 -> V_19 = V_101 ;
else
V_100 -> V_19 = V_102 ;
V_100 -> V_55 = V_55 ;
V_100 -> V_103 = V_55 ;
V_100 -> V_94 = V_25 . V_55 ;
V_100 -> V_104 = V_55 / V_8 ;
V_100 -> V_105 = F_47 () ;
F_48 ( & V_100 -> V_106 ) ;
for ( V_32 = 0 ; V_32 < V_36 . V_3 ; V_32 ++ ) {
V_41 = V_36 . V_44 [ V_32 ] -> V_24 . V_45 ;
V_100 -> V_107 ++ ;
if ( ! V_41 )
continue;
V_100 -> V_108 [ V_100 -> V_109 ] = V_41 ;
V_100 -> V_109 ++ ;
}
}
static int T_2 F_49 ( void )
{
struct V_110 V_110 ;
int V_53 ;
V_53 = F_8 ( & V_110 , V_111 , sizeof( V_110 ) ) ;
if ( V_53 )
return V_53 ;
if ( V_110 . V_112 == 0 )
return 0 ;
V_77 = ( void * ) F_50 ( V_75 ) ;
if ( ! V_77 )
return - V_23 ;
if ( V_110 . V_112 < F_20 () )
V_53 = F_8 ( V_77 , V_110 . V_112 , V_8 ) ;
else
V_53 = F_51 ( V_77 , ( void * ) V_110 . V_112 , V_8 ) ;
if ( V_53 || F_52 ( V_77 , V_77 -> V_100 . V_31 , 0 ) !=
V_110 . V_113 ) {
F_4 ( L_11 ) ;
F_53 ( ( unsigned long ) V_77 ) ;
V_77 = NULL ;
}
return 0 ;
}
static int T_2 F_54 ( void )
{
unsigned long V_55 , V_94 ;
unsigned char V_20 ;
int V_53 ;
V_55 = V_94 = 0 ;
if ( V_114 . type != V_115 )
return - V_11 ;
if ( V_116 )
return - V_11 ;
V_117 = F_55 ( L_12 , 4 , 1 , 4 * sizeof( long ) ) ;
F_56 ( V_117 , & V_118 ) ;
F_57 ( V_117 , 6 ) ;
F_4 ( L_13 , V_114 . V_119 . V_120 . V_121 . V_122 ) ;
F_4 ( L_14 , ( unsigned long long ) V_114 . V_119 . V_120 . V_123 ) ;
F_4 ( L_15 , ( unsigned long long ) V_114 . V_119 . V_120 . V_124 ) ;
V_53 = F_58 () ;
if ( V_53 )
goto V_58;
V_53 = F_43 () ;
if ( V_53 )
goto V_58;
V_10 = 1 ;
V_53 = F_8 ( & V_20 , V_125 , 1 ) ;
if ( V_53 )
goto V_58;
#ifdef F_59
if ( V_20 == V_96 ) {
F_42 ( L_16
L_17 ) ;
V_53 = - V_57 ;
goto V_58;
}
#else
if ( V_20 == V_95 ) {
F_42 ( L_18
L_19 ) ;
V_53 = - V_57 ;
goto V_58;
}
#endif
V_53 = F_44 ( & V_55 , & V_94 ) ;
if ( V_53 )
goto V_58;
V_53 = F_41 ( V_20 , V_94 ) ;
if ( V_53 )
goto V_58;
F_46 ( V_20 , & V_59 , V_55 ) ;
V_53 = F_49 () ;
if ( V_53 )
goto V_58;
V_126 = F_60 ( L_12 , NULL ) ;
if ( ! V_126 ) {
V_53 = - V_23 ;
goto V_58;
}
V_127 = F_61 ( L_20 , V_128 , V_126 , NULL ,
& V_129 ) ;
if ( ! V_127 ) {
V_53 = - V_23 ;
goto V_130;
}
V_131 = F_61 ( L_21 , V_128 , V_126 ,
NULL , & V_132 ) ;
if ( ! V_131 ) {
V_53 = - V_23 ;
goto V_133;
}
V_134 = F_61 ( L_22 , V_128 , V_126 ,
NULL , & V_135 ) ;
if ( ! V_134 ) {
V_53 = - V_23 ;
goto V_136;
}
V_137 = F_61 ( L_23 , V_128 | V_138 , V_126 ,
NULL , & V_139 ) ;
if ( ! V_137 ) {
V_53 = - V_23 ;
goto V_140;
}
return 0 ;
V_140:
F_62 ( V_134 ) ;
V_136:
F_62 ( V_131 ) ;
V_133:
F_62 ( V_127 ) ;
V_130:
F_62 ( V_126 ) ;
V_58:
F_17 ( V_46 , NULL ) ;
return V_53 ;
}
static void T_6 F_63 ( void )
{
F_64 ( V_117 ) ;
F_65 () ;
F_53 ( ( unsigned long ) V_77 ) ;
F_62 ( V_137 ) ;
F_62 ( V_134 ) ;
F_62 ( V_131 ) ;
F_62 ( V_127 ) ;
F_62 ( V_126 ) ;
F_17 ( V_46 , NULL ) ;
}
