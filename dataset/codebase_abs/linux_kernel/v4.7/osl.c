static void T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , char * V_4 )
{
T_2 V_5 ;
memcpy ( & V_5 , & V_2 -> V_6 , sizeof( V_5 ) ) ;
if ( ! V_5 || ! V_3 )
return;
if ( V_2 -> V_7 == V_8 )
F_2 ( V_5 , V_3 , V_4 ) ;
else if ( V_2 -> V_7 == V_9 )
F_3 ( V_5 , V_3 , V_4 ) ;
}
static int T_1 F_4 ( void )
{
F_1 ( & V_10 . V_11 , V_10 . V_12 ,
L_1 ) ;
F_1 ( & V_10 . V_13 , V_10 . V_12 ,
L_2 ) ;
F_1 ( & V_10 . V_14 , V_10 . V_15 ,
L_3 ) ;
F_1 ( & V_10 . V_16 , V_10 . V_15 ,
L_4 ) ;
if ( V_10 . V_17 == 4 )
F_1 ( & V_10 . V_18 , 4 , L_5 ) ;
F_1 ( & V_10 . V_19 , V_10 . V_20 ,
L_6 ) ;
if ( ! ( V_10 . V_21 & 0x1 ) )
F_1 ( & V_10 . V_22 ,
V_10 . V_21 , L_7 ) ;
if ( ! ( V_10 . V_23 & 0x1 ) )
F_1 ( & V_10 . V_24 ,
V_10 . V_23 , L_8 ) ;
return 0 ;
}
void F_5 ( const char * V_25 , ... )
{
T_3 args ;
va_start ( args , V_25 ) ;
F_6 ( V_25 , args ) ;
va_end ( args ) ;
}
void F_6 ( const char * V_25 , T_3 args )
{
static char V_26 [ 512 ] ;
vsprintf ( V_26 , V_25 , args ) ;
#ifdef F_7
if ( V_27 ) {
F_8 ( L_9 , V_26 ) ;
} else {
F_9 ( V_28 L_9 , V_26 ) ;
}
#else
if ( F_10 ( V_26 ) < 0 )
F_9 ( V_28 L_9 , V_26 ) ;
#endif
}
static int T_1 F_11 ( char * V_29 )
{
if ( F_12 ( V_29 , 16 , & V_30 ) )
return - V_31 ;
return 0 ;
}
T_4 T_1 F_13 ( void )
{
#ifdef F_14
if ( V_30 )
return V_30 ;
#endif
if ( F_15 ( V_32 ) ) {
if ( V_33 . V_34 != V_35 )
return V_33 . V_34 ;
else if ( V_33 . V_36 != V_35 )
return V_33 . V_36 ;
else {
F_9 (KERN_ERR PREFIX
L_10 ) ;
return 0 ;
}
} else if ( F_16 ( V_37 ) ) {
T_4 V_38 = 0 ;
F_17 ( & V_38 ) ;
return V_38 ;
}
return 0 ;
}
static struct V_39 *
F_18 ( T_4 V_40 , T_5 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_6 *
F_20 ( T_4 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_6 * F_21 ( T_4 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_6 * V_43 = NULL ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_43 = V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
V_42 -> V_45 ++ ;
}
F_23 ( & V_44 ) ;
return V_43 ;
}
static struct V_39 *
F_24 ( void T_6 * V_43 , T_5 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_6 * F_25 ( T_4 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_6 V_51 * ) F_27 ( F_28 ( V_48 ) ) ;
} else
return F_29 ( V_46 , V_47 ) ;
}
static void F_30 ( T_4 V_46 , void T_6 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) )
F_31 ( F_28 ( V_48 ) ) ;
else
F_32 ( V_52 ) ;
}
void T_6 * T_7
F_33 ( T_4 V_40 , T_5 V_41 )
{
struct V_39 * V_42 ;
void T_6 * V_43 ;
T_4 V_46 ;
T_5 V_47 ;
if ( V_40 > V_53 ) {
F_9 (KERN_ERR PREFIX L_11 ) ;
return NULL ;
}
if ( ! V_54 )
return F_34 ( ( unsigned long ) V_40 , V_41 ) ;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_45 ++ ;
goto V_55;
}
V_42 = F_35 ( sizeof( * V_42 ) , V_56 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return NULL ;
}
V_46 = F_36 ( V_40 , V_50 ) ;
V_47 = F_37 ( V_40 + V_41 , V_50 ) - V_46 ;
V_43 = F_25 ( V_46 , V_47 ) ;
if ( ! V_43 ) {
F_23 ( & V_44 ) ;
F_38 ( V_42 ) ;
return NULL ;
}
F_39 ( & V_42 -> V_57 ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_40 = V_46 ;
V_42 -> V_41 = V_47 ;
V_42 -> V_45 = 1 ;
F_40 ( & V_42 -> V_57 , & V_58 ) ;
V_55:
F_23 ( & V_44 ) ;
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
}
void * T_7
F_41 ( T_4 V_40 , T_5 V_41 )
{
return ( void * ) F_33 ( V_40 , V_41 ) ;
}
static void F_42 ( struct V_39 * V_42 )
{
if ( ! -- V_42 -> V_45 )
F_43 ( & V_42 -> V_57 ) ;
}
static void F_44 ( struct V_39 * V_42 )
{
if ( ! V_42 -> V_45 ) {
F_45 () ;
F_30 ( V_42 -> V_40 , V_42 -> V_43 ) ;
F_38 ( V_42 ) ;
}
}
void T_8 F_46 ( void T_6 * V_43 , T_5 V_41 )
{
struct V_39 * V_42 ;
if ( ! V_54 ) {
F_47 ( V_43 , V_41 ) ;
return;
}
F_22 ( & V_44 ) ;
V_42 = F_24 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
F_48 ( true , V_59 L_12 , V_60 , V_43 ) ;
return;
}
F_42 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_44 ( V_42 ) ;
}
void T_8 F_49 ( void * V_43 , T_5 V_41 )
{
return F_46 ( ( void T_6 * ) V_43 , V_41 ) ;
}
void T_1 F_50 ( void T_6 * V_43 , T_5 V_41 )
{
if ( ! V_54 )
F_47 ( V_43 , V_41 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
T_2 V_5 ;
void T_6 * V_43 ;
if ( V_2 -> V_7 != V_9 )
return 0 ;
memcpy ( & V_5 , & V_2 -> V_6 , sizeof( V_5 ) ) ;
if ( ! V_5 || ! V_2 -> V_61 )
return - V_31 ;
V_43 = F_33 ( V_5 , V_2 -> V_61 / 8 ) ;
if ( ! V_43 )
return - V_62 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
T_2 V_5 ;
struct V_39 * V_42 ;
if ( V_2 -> V_7 != V_9 )
return;
memcpy ( & V_5 , & V_2 -> V_6 , sizeof( V_5 ) ) ;
if ( ! V_5 || ! V_2 -> V_61 )
return;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_5 , V_2 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return;
}
F_42 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_44 ( V_42 ) ;
}
T_9
F_53 ( void * V_43 , T_4 * V_40 )
{
if ( ! V_40 || ! V_43 )
return V_63 ;
* V_40 = F_54 ( V_43 ) ;
return V_64 ;
}
int T_1 F_55 ( char * V_65 )
{
V_66 = true ;
return 1 ;
}
T_9
F_56 ( const struct V_67 * V_68 ,
T_10 * V_69 )
{
if ( ! V_68 || ! V_69 )
return V_63 ;
* V_69 = NULL ;
if ( ! memcmp ( V_68 -> V_70 , L_13 , 4 ) && strlen ( V_71 ) ) {
F_9 (KERN_INFO PREFIX L_14 ,
acpi_os_name) ;
* V_69 = V_71 ;
}
if ( ! memcmp ( V_68 -> V_70 , L_15 , 4 ) && V_66 ) {
F_9 (KERN_INFO PREFIX L_16 ) ;
* V_69 = ( char * ) 5 ;
}
return V_64 ;
}
static T_11 F_57 ( int V_72 , void * V_73 )
{
T_12 V_74 ;
V_74 = (* F_58) ( V_75 ) ;
if ( V_74 ) {
V_76 ++ ;
return V_77 ;
} else {
V_78 ++ ;
return V_79 ;
}
}
T_9
F_59 ( T_12 V_80 , T_13 V_81 ,
void * V_82 )
{
unsigned int V_72 ;
F_60 () ;
if ( V_80 != V_10 . V_83 )
return V_63 ;
if ( F_58 )
return V_84 ;
if ( F_61 ( V_80 , & V_72 ) < 0 ) {
F_9 (KERN_ERR PREFIX L_17 ,
gsi) ;
return V_64 ;
}
F_58 = V_81 ;
V_75 = V_82 ;
if ( F_62 ( V_72 , F_57 , V_85 , L_18 , F_57 ) ) {
F_9 (KERN_ERR PREFIX L_19 , irq) ;
F_58 = NULL ;
return V_86 ;
}
V_87 = V_72 ;
return V_64 ;
}
T_9 F_63 ( T_12 V_80 , T_13 V_81 )
{
if ( V_80 != V_10 . V_83 || ! F_64 () )
return V_63 ;
F_65 ( V_87 , F_57 ) ;
F_58 = NULL ;
V_87 = V_88 ;
return V_64 ;
}
void F_66 ( T_2 V_89 )
{
F_67 ( V_89 ) ;
}
void F_68 ( T_12 V_90 )
{
while ( V_90 ) {
T_12 V_91 = 1000 ;
if ( V_91 > V_90 )
V_91 = V_90 ;
F_69 ( V_91 ) ;
F_70 () ;
V_90 -= V_91 ;
}
}
T_2 F_71 ( void )
{
T_2 V_92 = F_72 ( F_73 () ) ;
F_74 ( V_92 , 100 ) ;
return V_92 ;
}
T_9 F_75 ( T_14 V_93 , T_12 * V_94 , T_12 V_95 )
{
T_12 V_96 ;
if ( ! V_94 )
V_94 = & V_96 ;
* V_94 = 0 ;
if ( V_95 <= 8 ) {
* ( V_97 * ) V_94 = F_76 ( V_93 ) ;
} else if ( V_95 <= 16 ) {
* ( V_98 * ) V_94 = F_77 ( V_93 ) ;
} else if ( V_95 <= 32 ) {
* ( T_12 * ) V_94 = F_78 ( V_93 ) ;
} else {
F_79 () ;
}
return V_64 ;
}
T_9 F_80 ( T_14 V_93 , T_12 V_94 , T_12 V_95 )
{
if ( V_95 <= 8 ) {
F_81 ( V_94 , V_93 ) ;
} else if ( V_95 <= 16 ) {
F_82 ( V_94 , V_93 ) ;
} else if ( V_95 <= 32 ) {
F_83 ( V_94 , V_93 ) ;
} else {
F_79 () ;
}
return V_64 ;
}
T_9
F_84 ( T_4 V_99 , T_2 * V_94 , T_12 V_95 )
{
void T_6 * V_100 ;
unsigned int V_41 = V_95 / 8 ;
bool V_101 = false ;
T_2 V_96 ;
F_85 () ;
V_100 = F_20 ( V_99 , V_41 ) ;
if ( ! V_100 ) {
F_86 () ;
V_100 = F_29 ( V_99 , V_41 ) ;
if ( ! V_100 )
return V_102 ;
V_101 = true ;
}
if ( ! V_94 )
V_94 = & V_96 ;
switch ( V_95 ) {
case 8 :
* ( V_97 * ) V_94 = F_87 ( V_100 ) ;
break;
case 16 :
* ( V_98 * ) V_94 = F_88 ( V_100 ) ;
break;
case 32 :
* ( T_12 * ) V_94 = F_89 ( V_100 ) ;
break;
case 64 :
* ( T_2 * ) V_94 = F_90 ( V_100 ) ;
break;
default:
F_79 () ;
}
if ( V_101 )
F_32 ( V_100 ) ;
else
F_86 () ;
return V_64 ;
}
T_9
F_91 ( T_4 V_99 , T_2 V_94 , T_12 V_95 )
{
void T_6 * V_100 ;
unsigned int V_41 = V_95 / 8 ;
bool V_101 = false ;
F_85 () ;
V_100 = F_20 ( V_99 , V_41 ) ;
if ( ! V_100 ) {
F_86 () ;
V_100 = F_29 ( V_99 , V_41 ) ;
if ( ! V_100 )
return V_102 ;
V_101 = true ;
}
switch ( V_95 ) {
case 8 :
F_92 ( V_94 , V_100 ) ;
break;
case 16 :
F_93 ( V_94 , V_100 ) ;
break;
case 32 :
F_94 ( V_94 , V_100 ) ;
break;
case 64 :
F_95 ( V_94 , V_100 ) ;
break;
default:
F_79 () ;
}
if ( V_101 )
F_32 ( V_100 ) ;
else
F_86 () ;
return V_64 ;
}
T_9
F_96 ( struct V_103 * V_104 , T_12 V_105 ,
T_2 * V_94 , T_12 V_95 )
{
int V_106 , V_41 ;
T_12 V_107 ;
if ( ! V_94 )
return V_63 ;
switch ( V_95 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_108 ;
}
V_106 = F_97 ( V_104 -> V_109 , V_104 -> V_110 ,
F_98 ( V_104 -> V_111 , V_104 -> V_112 ) ,
V_105 , V_41 , & V_107 ) ;
* V_94 = V_107 ;
return ( V_106 ? V_108 : V_64 ) ;
}
T_9
F_99 ( struct V_103 * V_104 , T_12 V_105 ,
T_2 V_94 , T_12 V_95 )
{
int V_106 , V_41 ;
switch ( V_95 ) {
case 8 :
V_41 = 1 ;
break;
case 16 :
V_41 = 2 ;
break;
case 32 :
V_41 = 4 ;
break;
default:
return V_108 ;
}
V_106 = F_100 ( V_104 -> V_109 , V_104 -> V_110 ,
F_98 ( V_104 -> V_111 , V_104 -> V_112 ) ,
V_105 , V_41 , V_94 ) ;
return ( V_106 ? V_108 : V_64 ) ;
}
static void F_101 ( struct V_113 * V_114 )
{
struct V_115 * V_116 = F_102 ( V_114 , struct V_115 , V_114 ) ;
V_116 -> V_112 ( V_116 -> V_82 ) ;
F_38 ( V_116 ) ;
}
int F_103 ( struct V_117 * V_118 ,
const struct V_119 * V_120 )
{
int V_121 = 0 ;
F_22 ( & V_122 . V_123 ) ;
if ( V_122 . V_120 ) {
V_121 = - V_124 ;
goto V_125;
}
V_122 . V_118 = V_118 ;
V_122 . V_120 = V_120 ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
void F_104 ( const struct V_119 * V_120 )
{
F_22 ( & V_122 . V_123 ) ;
if ( V_120 == V_122 . V_120 ) {
V_122 . V_120 = NULL ;
V_122 . V_118 = NULL ;
}
F_23 ( & V_122 . V_123 ) ;
}
int F_105 ( T_15 V_112 , void * V_82 )
{
int V_121 ;
int (* F_106)( T_15 , void * );
struct V_117 * V_118 ;
if ( ! V_126 )
return - V_127 ;
F_22 ( & V_122 . V_123 ) ;
if ( ! V_122 . V_120 ) {
V_121 = - V_127 ;
goto V_125;
}
if ( ! F_107 ( V_122 . V_118 ) ) {
V_121 = - V_127 ;
goto V_125;
}
F_106 = V_122 . V_120 -> V_128 ;
V_118 = V_122 . V_118 ;
F_23 ( & V_122 . V_123 ) ;
V_121 = F_106 ( V_112 , V_82 ) ;
F_22 ( & V_122 . V_123 ) ;
F_108 ( V_118 ) ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
T_16 F_10 ( const char * V_129 )
{
T_16 V_121 ;
T_16 (* F_106)( const char * );
struct V_117 * V_118 ;
if ( ! V_126 )
return - V_127 ;
F_22 ( & V_122 . V_123 ) ;
if ( ! V_122 . V_120 ) {
V_121 = - V_127 ;
goto V_125;
}
if ( ! F_107 ( V_122 . V_118 ) ) {
V_121 = - V_127 ;
goto V_125;
}
F_106 = V_122 . V_120 -> V_130 ;
V_118 = V_122 . V_118 ;
F_23 ( & V_122 . V_123 ) ;
V_121 = F_106 ( V_129 ) ;
F_22 ( & V_122 . V_123 ) ;
F_108 ( V_118 ) ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
T_16 F_109 ( char * V_26 , T_17 V_131 )
{
T_16 V_121 ;
T_16 (* F_106)( char * , T_17 );
struct V_117 * V_118 ;
if ( ! V_126 )
return - V_127 ;
F_22 ( & V_122 . V_123 ) ;
if ( ! V_122 . V_120 ) {
V_121 = - V_127 ;
goto V_125;
}
if ( ! F_107 ( V_122 . V_118 ) ) {
V_121 = - V_127 ;
goto V_125;
}
F_106 = V_122 . V_120 -> V_132 ;
V_118 = V_122 . V_118 ;
F_23 ( & V_122 . V_123 ) ;
V_121 = F_106 ( V_26 , V_131 ) ;
F_22 ( & V_122 . V_123 ) ;
F_108 ( V_118 ) ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
int F_110 ( void )
{
int V_121 ;
int (* F_106)( bool , char * , T_17 );
struct V_117 * V_118 ;
if ( ! V_126 )
return - V_127 ;
F_22 ( & V_122 . V_123 ) ;
if ( ! V_122 . V_120 ) {
V_121 = - V_127 ;
goto V_125;
}
if ( ! F_107 ( V_122 . V_118 ) ) {
V_121 = - V_127 ;
goto V_125;
}
F_106 = V_122 . V_120 -> V_133 ;
V_118 = V_122 . V_118 ;
F_23 ( & V_122 . V_123 ) ;
V_121 = F_106 ( V_134 ,
V_135 , V_136 ) ;
F_22 ( & V_122 . V_123 ) ;
F_108 ( V_118 ) ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
int F_111 ( void )
{
int V_121 ;
int (* F_106)( void );
struct V_117 * V_118 ;
if ( ! V_126 )
return - V_127 ;
F_22 ( & V_122 . V_123 ) ;
if ( ! V_122 . V_120 ) {
V_121 = - V_127 ;
goto V_125;
}
if ( ! F_107 ( V_122 . V_118 ) ) {
V_121 = - V_127 ;
goto V_125;
}
F_106 = V_122 . V_120 -> V_137 ;
V_118 = V_122 . V_118 ;
F_23 ( & V_122 . V_123 ) ;
V_121 = F_106 () ;
F_22 ( & V_122 . V_123 ) ;
F_108 ( V_118 ) ;
V_125:
F_23 ( & V_122 . V_123 ) ;
return V_121 ;
}
int T_1 F_112 ( void )
{
F_113 ( & V_122 . V_123 ) ;
V_126 = true ;
return 0 ;
}
T_9 F_114 ( T_18 type ,
T_15 V_112 , void * V_82 )
{
T_9 V_138 = V_64 ;
struct V_115 * V_116 ;
struct V_139 * V_140 ;
int V_121 ;
F_115 ( ( V_141 ,
L_20 ,
V_112 , V_82 ) ) ;
if ( type == V_142 ) {
V_121 = F_105 ( V_112 , V_82 ) ;
if ( V_121 ) {
F_116 ( L_21 ) ;
V_138 = V_108 ;
}
goto V_143;
}
V_116 = F_35 ( sizeof( struct V_115 ) , V_144 ) ;
if ( ! V_116 )
return V_145 ;
V_116 -> V_112 = V_112 ;
V_116 -> V_82 = V_82 ;
if ( type == V_146 ) {
V_140 = V_147 ;
F_117 ( & V_116 -> V_114 , F_101 ) ;
} else if ( type == V_148 ) {
V_140 = V_149 ;
F_117 ( & V_116 -> V_114 , F_101 ) ;
} else {
F_116 ( L_22 , type ) ;
V_138 = V_108 ;
}
if ( F_118 ( V_138 ) )
goto V_150;
V_121 = F_119 ( 0 , V_140 , & V_116 -> V_114 ) ;
if ( ! V_121 ) {
F_9 (KERN_ERR PREFIX
L_23 ) ;
V_138 = V_108 ;
}
V_150:
if ( F_118 ( V_138 ) )
F_38 ( V_116 ) ;
V_143:
return V_138 ;
}
void F_120 ( void )
{
if ( F_64 () )
F_121 ( V_87 ) ;
F_122 ( V_149 ) ;
F_122 ( V_147 ) ;
}
static void F_123 ( struct V_113 * V_114 )
{
struct V_151 * V_152 = F_102 ( V_114 , struct V_151 , V_114 ) ;
F_120 () ;
F_124 ( V_152 -> V_153 , V_152 -> V_154 ) ;
F_38 ( V_152 ) ;
}
T_9 F_125 ( struct V_155 * V_153 , T_12 V_154 )
{
struct V_151 * V_152 ;
F_115 ( ( V_141 ,
L_24 ,
V_153 , V_154 ) ) ;
V_152 = F_126 ( sizeof( * V_152 ) , V_56 ) ;
if ( ! V_152 )
return V_145 ;
F_117 ( & V_152 -> V_114 , F_123 ) ;
V_152 -> V_153 = V_153 ;
V_152 -> V_154 = V_154 ;
if ( ! F_127 ( V_156 , & V_152 -> V_114 ) ) {
F_38 ( V_152 ) ;
return V_108 ;
}
return V_64 ;
}
bool F_128 ( struct V_113 * V_114 )
{
return F_127 ( V_156 , V_114 ) ;
}
T_9
F_129 ( T_12 V_157 , T_12 V_158 , T_19 * V_159 )
{
struct V_160 * V_161 = NULL ;
V_161 = F_130 ( sizeof( struct V_160 ) ) ;
if ( ! V_161 )
return V_145 ;
F_131 ( V_161 , V_158 ) ;
* V_159 = ( T_19 * ) V_161 ;
F_115 ( ( V_162 , L_25 ,
* V_159 , V_158 ) ) ;
return V_64 ;
}
T_9 F_132 ( T_19 V_159 )
{
struct V_160 * V_161 = (struct V_160 * ) V_159 ;
if ( ! V_161 )
return V_63 ;
F_115 ( ( V_162 , L_26 , V_159 ) ) ;
F_133 ( ! F_134 ( & V_161 -> V_163 ) ) ;
F_38 ( V_161 ) ;
V_161 = NULL ;
return V_64 ;
}
T_9 F_135 ( T_19 V_159 , T_12 V_164 , V_98 V_165 )
{
T_9 V_138 = V_64 ;
struct V_160 * V_161 = (struct V_160 * ) V_159 ;
long V_166 ;
int V_121 = 0 ;
if ( ! V_167 )
return V_64 ;
if ( ! V_161 || ( V_164 < 1 ) )
return V_63 ;
if ( V_164 > 1 )
return V_168 ;
F_115 ( ( V_162 , L_27 ,
V_159 , V_164 , V_165 ) ) ;
if ( V_165 == V_169 )
V_166 = V_170 ;
else
V_166 = F_136 ( V_165 ) ;
V_121 = F_137 ( V_161 , V_166 ) ;
if ( V_121 )
V_138 = V_171 ;
if ( F_118 ( V_138 ) ) {
F_115 ( ( V_162 ,
L_28 ,
V_159 , V_164 , V_165 ,
F_138 ( V_138 ) ) ) ;
} else {
F_115 ( ( V_162 ,
L_29 , V_159 ,
V_164 , V_165 ) ) ;
}
return V_138 ;
}
T_9 F_139 ( T_19 V_159 , T_12 V_164 )
{
struct V_160 * V_161 = (struct V_160 * ) V_159 ;
if ( ! V_167 )
return V_64 ;
if ( ! V_161 || ( V_164 < 1 ) )
return V_63 ;
if ( V_164 > 1 )
return V_168 ;
F_115 ( ( V_162 , L_30 , V_159 ,
V_164 ) ) ;
F_140 ( V_161 ) ;
return V_64 ;
}
T_9 F_141 ( char * V_26 , T_12 V_131 , T_12 * V_172 )
{
#ifdef F_7
if ( V_27 ) {
T_12 V_173 ;
F_142 ( V_26 , V_131 ) ;
V_173 = strlen ( V_26 ) - 1 ;
V_26 [ V_173 ] = '\0' ;
}
#else
int V_121 ;
V_121 = F_109 ( V_26 , V_131 ) ;
if ( V_121 < 0 )
return V_108 ;
if ( V_172 )
* V_172 = V_121 ;
#endif
return V_64 ;
}
T_9 F_143 ( void )
{
int V_121 ;
V_121 = F_110 () ;
if ( V_121 < 0 )
return V_108 ;
return V_64 ;
}
T_9 F_144 ( void )
{
int V_121 ;
V_121 = F_111 () ;
if ( V_121 < 0 )
return V_108 ;
return V_64 ;
}
T_9 F_145 ( T_12 V_112 , void * V_174 )
{
switch ( V_112 ) {
case V_175 :
F_9 (KERN_ERR PREFIX L_31 ) ;
break;
case V_176 :
break;
default:
break;
}
return V_64 ;
}
static int T_1 F_146 ( char * V_65 )
{
char * V_177 = V_71 ;
int V_178 = V_179 - 1 ;
if ( ! V_65 || ! * V_65 )
return 0 ;
for (; V_178 -- && * V_65 ; V_65 ++ ) {
if ( isalnum ( * V_65 ) || * V_65 == ' ' || * V_65 == ':' )
* V_177 ++ = * V_65 ;
else if ( * V_65 == '\'' || * V_65 == '"' )
continue;
else
break;
}
* V_177 = 0 ;
return 1 ;
}
static int T_1 F_147 ( char * V_65 )
{
V_180 = FALSE ;
F_148 ( L_32 ) ;
return 1 ;
}
static int T_1 F_149 ( char * V_65 )
{
if ( V_65 == NULL || * V_65 == '\0' )
return 0 ;
if ( ! strcmp ( L_33 , V_65 ) )
V_181 = V_182 ;
else if ( ! strcmp ( L_34 , V_65 ) )
V_181 = V_183 ;
else if ( ! strcmp ( L_35 , V_65 ) )
V_181 = V_184 ;
return 1 ;
}
int F_150 ( const struct V_185 * V_186 )
{
T_20 V_7 ;
T_5 V_3 ;
V_97 V_187 = 0 ;
int V_188 = 0 ;
if ( V_181 == V_184 )
return 0 ;
if ( ! ( V_186 -> V_189 & V_190 ) && ! ( V_186 -> V_189 & V_191 ) )
return 0 ;
if ( V_186 -> V_189 & V_190 )
V_7 = V_8 ;
else
V_7 = V_9 ;
V_3 = F_151 ( V_186 ) ;
if ( V_181 != V_184 )
V_187 = 1 ;
V_188 = F_152 ( V_7 , V_186 -> V_192 , V_3 , V_187 ) ;
if ( V_188 ) {
if ( V_181 != V_184 ) {
if ( V_181 == V_183 )
F_9 ( V_193 L_36
L_37
L_38 ) ;
F_9 ( V_194 L_39
L_40
L_41 ) ;
}
if ( V_181 == V_182 )
return - V_124 ;
}
return 0 ;
}
int F_153 ( T_21 V_192 , T_21 V_195 ,
const char * V_70 )
{
struct V_185 V_186 = {
. V_192 = V_192 ,
. V_196 = V_192 + V_195 - 1 ,
. V_70 = V_70 ,
. V_189 = V_190 ,
} ;
return F_150 ( & V_186 ) ;
}
int F_154 ( void )
{
return V_181 == V_182 ;
}
void F_155 ( T_22 V_159 )
{
F_156 ( V_159 ) ;
}
T_23 F_157 ( T_22 V_197 )
{
T_23 V_189 ;
F_158 ( V_197 , V_189 ) ;
return V_189 ;
}
void F_159 ( T_22 V_197 , T_23 V_189 )
{
F_160 ( V_197 , V_189 ) ;
}
T_9
F_161 ( char * V_70 , V_98 V_41 , V_98 V_198 , T_24 * * V_199 )
{
* V_199 = F_162 ( V_70 , V_41 , 0 , 0 , NULL ) ;
if ( * V_199 == NULL )
return V_108 ;
else
return V_64 ;
}
T_9 F_163 ( T_24 * V_199 )
{
F_164 ( V_199 ) ;
return ( V_64 ) ;
}
T_9 F_165 ( T_24 * V_199 )
{
F_166 ( V_199 ) ;
return ( V_64 ) ;
}
T_9 F_167 ( T_24 * V_199 , void * V_200 )
{
F_168 ( V_199 , V_200 ) ;
return ( V_64 ) ;
}
static int T_1 F_169 ( char * V_201 )
{
V_202 = TRUE ;
F_148 ( L_42 ) ;
return 0 ;
}
static int T_1 F_170 ( char * V_201 )
{
F_9 (KERN_NOTICE PREFIX
L_43 ) ;
V_203 = TRUE ;
return 1 ;
}
T_9 T_1 F_171 ( void )
{
F_51 ( & V_10 . V_11 ) ;
F_51 ( & V_10 . V_13 ) ;
F_51 ( & V_10 . V_22 ) ;
F_51 ( & V_10 . V_24 ) ;
if ( V_10 . V_189 & V_204 ) {
int V_205 ;
V_205 = F_51 ( & V_10 . V_206 ) ;
F_172 ( V_59 L_44 , V_60 , V_205 ) ;
}
V_167 = true ;
return V_64 ;
}
T_9 T_1 F_173 ( void )
{
V_149 = F_174 ( L_45 , 0 , 1 ) ;
V_147 = F_174 ( L_46 , 0 , 1 ) ;
V_156 = F_175 ( L_47 , 0 ) ;
F_133 ( ! V_149 ) ;
F_133 ( ! V_147 ) ;
F_133 ( ! V_156 ) ;
F_176 () ;
return V_64 ;
}
T_9 F_177 ( void )
{
if ( F_58 ) {
F_63 ( V_10 . V_83 ,
F_58 ) ;
}
F_52 ( & V_10 . V_24 ) ;
F_52 ( & V_10 . V_22 ) ;
F_52 ( & V_10 . V_13 ) ;
F_52 ( & V_10 . V_11 ) ;
if ( V_10 . V_189 & V_204 )
F_52 ( & V_10 . V_206 ) ;
F_178 ( V_149 ) ;
F_178 ( V_147 ) ;
F_178 ( V_156 ) ;
return V_64 ;
}
T_9 F_179 ( V_97 V_207 , T_12 V_208 ,
T_12 V_209 )
{
int V_210 = 0 ;
if ( V_211 )
V_210 = V_211 ( V_207 ,
V_208 , V_209 ) ;
if ( V_210 < 0 )
return V_108 ;
else if ( V_210 > 0 )
return V_212 ;
return V_64 ;
}
void F_180 ( int (* F_106)( V_97 V_207 ,
T_12 V_213 , T_12 V_214 ) )
{
V_211 = F_106 ;
}
T_9 F_181 ( V_97 V_207 , T_12 V_215 ,
T_12 V_216 )
{
int V_210 = 0 ;
if ( V_217 )
V_210 = V_217 ( V_207 ,
V_215 , V_216 ) ;
if ( V_210 < 0 )
return V_108 ;
else if ( V_210 > 0 )
return V_212 ;
return V_64 ;
}
void F_182 ( int (* F_106)( V_97 V_207 ,
T_12 V_215 , T_12 V_216 ) )
{
V_217 = F_106 ;
}
