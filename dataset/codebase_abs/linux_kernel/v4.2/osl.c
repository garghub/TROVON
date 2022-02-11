static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
if ( ! strcmp ( L_8 , V_1 ) ) {
F_3 ( V_3 ) ;
V_2 = V_4 ;
}
return V_2 ;
}
static void T_3 F_4 ( struct V_5 * V_6 ,
unsigned int V_7 , char * V_8 )
{
T_4 V_9 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_7 )
return;
if ( V_6 -> V_11 == V_12 )
F_5 ( V_9 , V_7 , V_8 ) ;
else if ( V_6 -> V_11 == V_13 )
F_6 ( V_9 , V_7 , V_8 ) ;
}
static int T_3 F_7 ( void )
{
F_4 ( & V_14 . V_15 , V_14 . V_16 ,
L_9 ) ;
F_4 ( & V_14 . V_17 , V_14 . V_16 ,
L_10 ) ;
F_4 ( & V_14 . V_18 , V_14 . V_19 ,
L_11 ) ;
F_4 ( & V_14 . V_20 , V_14 . V_19 ,
L_12 ) ;
if ( V_14 . V_21 == 4 )
F_4 ( & V_14 . V_22 , 4 , L_13 ) ;
F_4 ( & V_14 . V_23 , V_14 . V_24 ,
L_14 ) ;
if ( ! ( V_14 . V_25 & 0x1 ) )
F_4 ( & V_14 . V_26 ,
V_14 . V_25 , L_15 ) ;
if ( ! ( V_14 . V_27 & 0x1 ) )
F_4 ( & V_14 . V_28 ,
V_14 . V_27 , L_16 ) ;
return 0 ;
}
void F_8 ( const char * V_29 , ... )
{
T_5 args ;
va_start ( args , V_29 ) ;
F_9 ( V_29 , args ) ;
va_end ( args ) ;
}
void F_9 ( const char * V_29 , T_5 args )
{
static char V_30 [ 512 ] ;
vsprintf ( V_30 , V_29 , args ) ;
#ifdef F_10
if ( V_31 ) {
F_11 ( L_17 , V_30 ) ;
} else {
F_12 ( V_32 L_17 , V_30 ) ;
}
#else
F_12 ( V_32 L_17 , V_30 ) ;
#endif
}
static int T_3 F_13 ( char * V_33 )
{
if ( F_14 ( V_33 , 16 , & V_34 ) )
return - V_35 ;
return 0 ;
}
T_6 T_3 F_15 ( void )
{
#ifdef F_16
if ( V_34 )
return V_34 ;
#endif
if ( F_17 ( V_36 ) ) {
if ( V_37 . V_38 != V_39 )
return V_37 . V_38 ;
else if ( V_37 . V_40 != V_39 )
return V_37 . V_40 ;
else {
F_12 (KERN_ERR PREFIX
L_18 ) ;
return 0 ;
}
} else if ( F_18 ( V_41 ) ) {
T_6 V_42 = 0 ;
F_19 ( & V_42 ) ;
return V_42 ;
}
return 0 ;
}
static struct V_43 *
F_20 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_21 (map, &acpi_ioremaps, list)
if ( V_46 -> V_44 <= V_44 &&
V_44 + V_45 <= V_46 -> V_44 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 *
F_22 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 )
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
return NULL ;
}
void T_8 * F_23 ( T_6 V_44 , unsigned int V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 = NULL ;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_47 = V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
V_46 -> V_49 ++ ;
}
F_25 ( & V_48 ) ;
return V_47 ;
}
static struct V_43 *
F_26 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
F_21 (map, &acpi_ioremaps, list)
if ( V_46 -> V_47 <= V_47 &&
V_47 + V_45 <= V_46 -> V_47 + V_46 -> V_45 )
return V_46 ;
return NULL ;
}
static void T_8 * F_27 ( T_6 V_50 , unsigned long V_51 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_28 ( V_52 ) ) {
if ( V_51 > V_54 )
return NULL ;
return ( void T_8 V_55 * ) F_29 ( F_30 ( V_52 ) ) ;
} else
return F_31 ( V_50 , V_51 ) ;
}
static void F_32 ( T_6 V_50 , void T_8 * V_56 )
{
unsigned long V_52 ;
V_52 = V_50 >> V_53 ;
if ( F_28 ( V_52 ) )
F_33 ( F_30 ( V_52 ) ) ;
else
F_34 ( V_56 ) ;
}
void T_8 * T_9
F_35 ( T_6 V_44 , T_7 V_45 )
{
struct V_43 * V_46 ;
void T_8 * V_47 ;
T_6 V_50 ;
T_7 V_51 ;
if ( V_44 > V_57 ) {
F_12 (KERN_ERR PREFIX L_19 ) ;
return NULL ;
}
if ( ! V_58 )
return F_36 ( ( unsigned long ) V_44 , V_45 ) ;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_44 , V_45 ) ;
if ( V_46 ) {
V_46 -> V_49 ++ ;
goto V_59;
}
V_46 = F_37 ( sizeof( * V_46 ) , V_60 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
return NULL ;
}
V_50 = F_38 ( V_44 , V_54 ) ;
V_51 = F_39 ( V_44 + V_45 , V_54 ) - V_50 ;
V_47 = F_27 ( V_50 , V_51 ) ;
if ( ! V_47 ) {
F_25 ( & V_48 ) ;
F_40 ( V_46 ) ;
return NULL ;
}
F_41 ( & V_46 -> V_61 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_44 = V_50 ;
V_46 -> V_45 = V_51 ;
V_46 -> V_49 = 1 ;
F_42 ( & V_46 -> V_61 , & V_62 ) ;
V_59:
F_25 ( & V_48 ) ;
return V_46 -> V_47 + ( V_44 - V_46 -> V_44 ) ;
}
void * T_9
F_43 ( T_6 V_44 , T_7 V_45 )
{
return ( void * ) F_35 ( V_44 , V_45 ) ;
}
static void F_44 ( struct V_43 * V_46 )
{
if ( ! -- V_46 -> V_49 )
F_45 ( & V_46 -> V_61 ) ;
}
static void F_46 ( struct V_43 * V_46 )
{
if ( ! V_46 -> V_49 ) {
F_47 () ;
F_32 ( V_46 -> V_44 , V_46 -> V_47 ) ;
F_40 ( V_46 ) ;
}
}
void T_10 F_48 ( void T_8 * V_47 , T_7 V_45 )
{
struct V_43 * V_46 ;
if ( ! V_58 ) {
F_49 ( V_47 , V_45 ) ;
return;
}
F_24 ( & V_48 ) ;
V_46 = F_26 ( V_47 , V_45 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
F_50 ( true , V_63 L_20 , V_64 , V_47 ) ;
return;
}
F_44 ( V_46 ) ;
F_25 ( & V_48 ) ;
F_46 ( V_46 ) ;
}
void T_10 F_51 ( void * V_47 , T_7 V_45 )
{
return F_48 ( ( void T_8 * ) V_47 , V_45 ) ;
}
void T_3 F_52 ( void T_8 * V_47 , T_7 V_45 )
{
if ( ! V_58 )
F_49 ( V_47 , V_45 ) ;
}
int F_53 ( struct V_5 * V_6 )
{
T_4 V_9 ;
void T_8 * V_47 ;
if ( V_6 -> V_11 != V_13 )
return 0 ;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return - V_35 ;
V_47 = F_35 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_47 )
return - V_66 ;
return 0 ;
}
void F_54 ( struct V_5 * V_6 )
{
T_4 V_9 ;
struct V_43 * V_46 ;
if ( V_6 -> V_11 != V_13 )
return;
memcpy ( & V_9 , & V_6 -> V_10 , sizeof( V_9 ) ) ;
if ( ! V_9 || ! V_6 -> V_65 )
return;
F_24 ( & V_48 ) ;
V_46 = F_20 ( V_9 , V_6 -> V_65 / 8 ) ;
if ( ! V_46 ) {
F_25 ( & V_48 ) ;
return;
}
F_44 ( V_46 ) ;
F_25 ( & V_48 ) ;
F_46 ( V_46 ) ;
}
T_11
F_55 ( void * V_47 , T_6 * V_44 )
{
if ( ! V_44 || ! V_47 )
return V_67 ;
* V_44 = F_56 ( V_47 ) ;
return V_68 ;
}
int T_3 F_57 ( char * V_69 )
{
V_70 = true ;
return 1 ;
}
T_11
F_58 ( const struct V_71 * V_72 ,
char * * V_73 )
{
if ( ! V_72 || ! V_73 )
return V_67 ;
* V_73 = NULL ;
if ( ! memcmp ( V_72 -> V_74 , L_21 , 4 ) && strlen ( V_75 ) ) {
F_12 (KERN_INFO PREFIX L_22 ,
acpi_os_name) ;
* V_73 = V_75 ;
}
if ( ! memcmp ( V_72 -> V_74 , L_23 , 4 ) && V_70 ) {
F_12 (KERN_INFO PREFIX L_24 ) ;
* V_73 = ( char * ) 5 ;
}
return V_68 ;
}
static T_12 T_3 F_59 ( T_12 * V_30 , T_1 V_7 )
{
T_12 V_76 = 0 ;
T_12 * V_77 = V_30 + V_7 ;
while ( V_30 < V_77 )
V_76 = ( T_12 ) ( V_76 + * ( V_30 ++ ) ) ;
return V_76 ;
}
void T_3 F_60 ( void * V_78 , T_13 V_45 )
{
int V_79 , V_80 , V_81 = 0 , V_82 = 0 ;
long V_83 = 0 ;
struct V_84 * V_85 ;
char V_86 [ 32 ] = L_25 ;
struct V_87 V_88 ;
if ( V_78 == NULL || V_45 == 0 )
return;
for ( V_80 = 0 ; V_80 < V_89 ; V_80 ++ ) {
V_88 = F_61 ( V_86 , V_78 , V_45 , & V_83 ) ;
if ( ! V_88 . V_78 )
break;
V_78 += V_83 ;
V_45 -= V_83 ;
if ( V_88 . V_45 < sizeof( struct V_84 ) ) {
F_62 ( L_26 ,
V_86 , V_88 . V_74 ) ;
continue;
}
V_85 = V_88 . V_78 ;
for ( V_79 = 0 ; V_90 [ V_79 ] ; V_79 ++ )
if ( ! memcmp ( V_85 -> V_91 , V_90 [ V_79 ] , 4 ) )
break;
if ( ! V_90 [ V_79 ] ) {
F_62 ( L_27 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( V_88 . V_45 != V_85 -> V_7 ) {
F_62 ( L_28 ,
V_86 , V_88 . V_74 ) ;
continue;
}
if ( F_59 ( V_88 . V_78 , V_85 -> V_7 ) ) {
F_62 ( L_29 ,
V_86 , V_88 . V_74 ) ;
continue;
}
F_63 ( L_30 ,
V_85 -> V_91 , V_86 , V_88 . V_74 , V_85 -> V_7 ) ;
V_92 += V_85 -> V_7 ;
V_93 [ V_81 ] . V_78 = V_88 . V_78 ;
V_93 [ V_81 ] . V_45 = V_88 . V_45 ;
V_81 ++ ;
}
if ( V_81 == 0 )
return;
V_94 =
F_64 ( 0 , V_95 << V_53 ,
V_92 , V_54 ) ;
if ( ! V_94 ) {
F_65 ( 1 ) ;
return;
}
F_66 ( V_94 , V_92 ) ;
F_67 ( V_94 , V_92 ) ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
unsigned char * V_96 = V_93 [ V_80 ] . V_78 ;
T_14 V_45 = V_93 [ V_80 ] . V_45 ;
T_14 V_97 = V_94 + V_82 ;
T_14 V_98 , V_99 ;
char * V_100 ;
V_82 += V_45 ;
while ( V_45 ) {
V_98 = V_97 & ~ V_101 ;
V_99 = V_45 ;
if ( V_99 > V_102 - V_98 )
V_99 = V_102 - V_98 ;
V_100 = F_68 ( V_97 & V_101 ,
V_99 + V_98 ) ;
memcpy ( V_100 + V_98 , V_96 , V_99 ) ;
F_69 ( V_100 , V_99 + V_98 ) ;
V_96 += V_99 ;
V_97 += V_99 ;
V_45 -= V_99 ;
}
}
}
static void F_70 ( struct V_84 * V_85 )
{
F_71 ( V_63
L_31 ,
V_85 -> V_91 , V_85 -> V_103 ) ;
F_72 ( V_104 , V_105 ) ;
}
T_11
F_73 ( struct V_84 * V_106 ,
struct V_84 * * V_107 )
{
if ( ! V_106 || ! V_107 )
return V_67 ;
* V_107 = NULL ;
#ifdef F_74
if ( strncmp ( V_106 -> V_91 , L_32 , 4 ) == 0 )
* V_107 = (struct V_84 * ) V_108 ;
#endif
if ( * V_107 != NULL )
F_70 ( V_106 ) ;
return V_68 ;
}
T_11
F_75 ( struct V_84 * V_106 ,
T_6 * V_10 ,
T_1 * V_109 )
{
#ifndef F_76
* V_109 = 0 ;
* V_10 = 0 ;
return V_68 ;
#else
int V_110 = 0 ;
struct V_84 * V_85 ;
* V_109 = 0 ;
* V_10 = 0 ;
if ( ! V_94 )
return V_68 ;
do {
if ( V_110 + V_111 > V_92 ) {
F_65 ( 1 ) ;
return V_68 ;
}
V_85 = F_43 ( V_94 + V_110 ,
V_111 ) ;
if ( V_110 + V_85 -> V_7 > V_92 ) {
F_51 ( V_85 , V_111 ) ;
F_65 ( 1 ) ;
return V_68 ;
}
V_110 += V_85 -> V_7 ;
if ( memcmp ( V_106 -> V_91 , V_85 -> V_91 , 4 ) ) {
F_51 ( V_85 ,
V_111 ) ;
continue;
}
if ( memcmp ( V_85 -> V_103 , V_106 -> V_103 ,
V_112 ) ) {
F_51 ( V_85 ,
V_111 ) ;
continue;
}
V_110 -= V_85 -> V_7 ;
* V_109 = V_85 -> V_7 ;
F_51 ( V_85 , V_111 ) ;
* V_10 = V_94 + V_110 ;
break;
} while ( V_110 + V_111 < V_92 );
if ( * V_10 != 0 )
F_70 ( V_106 ) ;
return V_68 ;
#endif
}
static T_15 F_77 ( int V_113 , void * V_114 )
{
T_1 V_115 ;
V_115 = (* F_78) ( V_116 ) ;
if ( V_115 ) {
V_117 ++ ;
return V_118 ;
} else {
V_119 ++ ;
return V_120 ;
}
}
T_11
F_79 ( T_1 V_121 , T_16 V_122 ,
void * V_123 )
{
unsigned int V_113 ;
F_80 () ;
if ( V_121 != V_14 . V_124 )
return V_67 ;
if ( F_78 )
return V_125 ;
if ( F_81 ( V_121 , & V_113 ) < 0 ) {
F_12 (KERN_ERR PREFIX L_33 ,
gsi) ;
return V_68 ;
}
F_78 = V_122 ;
V_116 = V_123 ;
if ( F_82 ( V_113 , F_77 , V_126 , L_34 , F_77 ) ) {
F_12 (KERN_ERR PREFIX L_35 , irq) ;
F_78 = NULL ;
return V_127 ;
}
return V_68 ;
}
T_11 F_83 ( T_1 V_113 , T_16 V_122 )
{
if ( V_113 != V_14 . V_124 )
return V_67 ;
F_84 ( V_113 , F_77 ) ;
F_78 = NULL ;
return V_68 ;
}
void F_85 ( T_4 V_128 )
{
F_86 ( V_128 ) ;
}
void F_87 ( T_1 V_129 )
{
while ( V_129 ) {
T_1 V_130 = 1000 ;
if ( V_130 > V_129 )
V_130 = V_129 ;
F_88 ( V_130 ) ;
F_89 () ;
V_129 -= V_130 ;
}
}
T_4 F_90 ( void )
{
T_4 V_131 = F_91 ( F_92 () ) ;
F_93 ( V_131 , 100 ) ;
return V_131 ;
}
T_11 F_94 ( T_17 V_132 , T_1 * V_133 , T_1 V_134 )
{
T_1 V_135 ;
if ( ! V_133 )
V_133 = & V_135 ;
* V_133 = 0 ;
if ( V_134 <= 8 ) {
* ( T_12 * ) V_133 = F_95 ( V_132 ) ;
} else if ( V_134 <= 16 ) {
* ( V_136 * ) V_133 = F_96 ( V_132 ) ;
} else if ( V_134 <= 32 ) {
* ( T_1 * ) V_133 = F_97 ( V_132 ) ;
} else {
F_98 () ;
}
return V_68 ;
}
T_11 F_99 ( T_17 V_132 , T_1 V_133 , T_1 V_134 )
{
if ( V_134 <= 8 ) {
F_100 ( V_133 , V_132 ) ;
} else if ( V_134 <= 16 ) {
F_101 ( V_133 , V_132 ) ;
} else if ( V_134 <= 32 ) {
F_102 ( V_133 , V_132 ) ;
} else {
F_98 () ;
}
return V_68 ;
}
static inline T_4 F_103 ( const volatile void T_8 * V_9 )
{
return F_104 ( V_9 ) ;
}
static inline T_4 F_103 ( const volatile void T_8 * V_9 )
{
T_4 V_137 , V_138 ;
V_137 = F_105 ( V_9 ) ;
V_138 = F_105 ( V_9 + 4 ) ;
return V_137 | ( V_138 << 32 ) ;
}
T_11
F_106 ( T_6 V_139 , T_4 * V_133 , T_1 V_134 )
{
void T_8 * V_140 ;
unsigned int V_45 = V_134 / 8 ;
bool V_141 = false ;
T_4 V_135 ;
F_107 () ;
V_140 = F_22 ( V_139 , V_45 ) ;
if ( ! V_140 ) {
F_108 () ;
V_140 = F_31 ( V_139 , V_45 ) ;
if ( ! V_140 )
return V_142 ;
V_141 = true ;
}
if ( ! V_133 )
V_133 = & V_135 ;
switch ( V_134 ) {
case 8 :
* ( T_12 * ) V_133 = F_109 ( V_140 ) ;
break;
case 16 :
* ( V_136 * ) V_133 = F_110 ( V_140 ) ;
break;
case 32 :
* ( T_1 * ) V_133 = F_105 ( V_140 ) ;
break;
case 64 :
* ( T_4 * ) V_133 = F_103 ( V_140 ) ;
break;
default:
F_98 () ;
}
if ( V_141 )
F_34 ( V_140 ) ;
else
F_108 () ;
return V_68 ;
}
static inline void F_111 ( T_4 V_143 , volatile void T_8 * V_9 )
{
F_112 ( V_143 , V_9 ) ;
}
static inline void F_111 ( T_4 V_143 , volatile void T_8 * V_9 )
{
F_113 ( V_143 , V_9 ) ;
F_113 ( V_143 >> 32 , V_9 + 4 ) ;
}
T_11
F_114 ( T_6 V_139 , T_4 V_133 , T_1 V_134 )
{
void T_8 * V_140 ;
unsigned int V_45 = V_134 / 8 ;
bool V_141 = false ;
F_107 () ;
V_140 = F_22 ( V_139 , V_45 ) ;
if ( ! V_140 ) {
F_108 () ;
V_140 = F_31 ( V_139 , V_45 ) ;
if ( ! V_140 )
return V_142 ;
V_141 = true ;
}
switch ( V_134 ) {
case 8 :
F_115 ( V_133 , V_140 ) ;
break;
case 16 :
F_116 ( V_133 , V_140 ) ;
break;
case 32 :
F_113 ( V_133 , V_140 ) ;
break;
case 64 :
F_111 ( V_133 , V_140 ) ;
break;
default:
F_98 () ;
}
if ( V_141 )
F_34 ( V_140 ) ;
else
F_108 () ;
return V_68 ;
}
T_11
F_117 ( struct V_144 * V_145 , T_1 V_146 ,
T_4 * V_133 , T_1 V_134 )
{
int V_147 , V_45 ;
T_1 V_148 ;
if ( ! V_133 )
return V_67 ;
switch ( V_134 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_149 ;
}
V_147 = F_118 ( V_145 -> V_150 , V_145 -> V_151 ,
F_119 ( V_145 -> V_152 , V_145 -> V_153 ) ,
V_146 , V_45 , & V_148 ) ;
* V_133 = V_148 ;
return ( V_147 ? V_149 : V_68 ) ;
}
T_11
F_120 ( struct V_144 * V_145 , T_1 V_146 ,
T_4 V_133 , T_1 V_134 )
{
int V_147 , V_45 ;
switch ( V_134 ) {
case 8 :
V_45 = 1 ;
break;
case 16 :
V_45 = 2 ;
break;
case 32 :
V_45 = 4 ;
break;
default:
return V_149 ;
}
V_147 = F_121 ( V_145 -> V_150 , V_145 -> V_151 ,
F_119 ( V_145 -> V_152 , V_145 -> V_153 ) ,
V_146 , V_45 , V_133 ) ;
return ( V_147 ? V_149 : V_68 ) ;
}
static void F_122 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_123 ( V_155 , struct V_156 , V_155 ) ;
V_157 -> V_153 ( V_157 -> V_123 ) ;
F_40 ( V_157 ) ;
}
T_11 F_124 ( T_18 type ,
T_19 V_153 , void * V_123 )
{
T_11 V_158 = V_68 ;
struct V_156 * V_157 ;
struct V_159 * V_160 ;
int V_161 ;
F_125 ( ( V_162 ,
L_36 ,
V_153 , V_123 ) ) ;
V_157 = F_37 ( sizeof( struct V_156 ) , V_163 ) ;
if ( ! V_157 )
return V_164 ;
V_157 -> V_153 = V_153 ;
V_157 -> V_123 = V_123 ;
if ( type == V_165 ) {
V_160 = V_166 ;
F_126 ( & V_157 -> V_155 , F_122 ) ;
} else {
V_160 = V_167 ;
F_126 ( & V_157 -> V_155 , F_122 ) ;
}
V_161 = F_127 ( 0 , V_160 , & V_157 -> V_155 ) ;
if ( ! V_161 ) {
F_12 (KERN_ERR PREFIX
L_37 ) ;
V_158 = V_149 ;
F_40 ( V_157 ) ;
}
return V_158 ;
}
void F_128 ( void )
{
if ( F_78 )
F_129 ( V_14 . V_124 ) ;
F_130 ( V_167 ) ;
F_130 ( V_166 ) ;
}
static void F_131 ( struct V_154 * V_155 )
{
struct V_168 * V_169 = F_123 ( V_155 , struct V_168 , V_155 ) ;
F_128 () ;
F_132 ( V_169 -> V_170 , V_169 -> V_171 ) ;
F_40 ( V_169 ) ;
}
T_11 F_133 ( struct V_172 * V_170 , T_1 V_171 )
{
struct V_168 * V_169 ;
F_125 ( ( V_162 ,
L_38 ,
V_170 , V_171 ) ) ;
V_169 = F_134 ( sizeof( * V_169 ) , V_60 ) ;
if ( ! V_169 )
return V_164 ;
F_126 ( & V_169 -> V_155 , F_131 ) ;
V_169 -> V_170 = V_170 ;
V_169 -> V_171 = V_171 ;
if ( ! F_135 ( V_173 , & V_169 -> V_155 ) ) {
F_40 ( V_169 ) ;
return V_149 ;
}
return V_68 ;
}
bool F_136 ( struct V_154 * V_155 )
{
return F_135 ( V_173 , V_155 ) ;
}
T_11
F_137 ( T_1 V_174 , T_1 V_175 , T_20 * V_176 )
{
struct V_177 * V_178 = NULL ;
V_178 = F_138 ( sizeof( struct V_177 ) ) ;
if ( ! V_178 )
return V_164 ;
F_139 ( V_178 , V_175 ) ;
* V_176 = ( T_20 * ) V_178 ;
F_125 ( ( V_179 , L_39 ,
* V_176 , V_175 ) ) ;
return V_68 ;
}
T_11 F_140 ( T_20 V_176 )
{
struct V_177 * V_178 = (struct V_177 * ) V_176 ;
if ( ! V_178 )
return V_67 ;
F_125 ( ( V_179 , L_40 , V_176 ) ) ;
F_141 ( ! F_142 ( & V_178 -> V_180 ) ) ;
F_40 ( V_178 ) ;
V_178 = NULL ;
return V_68 ;
}
T_11 F_143 ( T_20 V_176 , T_1 V_181 , V_136 V_182 )
{
T_11 V_158 = V_68 ;
struct V_177 * V_178 = (struct V_177 * ) V_176 ;
long V_183 ;
int V_161 = 0 ;
if ( ! V_178 || ( V_181 < 1 ) )
return V_67 ;
if ( V_181 > 1 )
return V_184 ;
F_125 ( ( V_179 , L_41 ,
V_176 , V_181 , V_182 ) ) ;
if ( V_182 == V_185 )
V_183 = V_186 ;
else
V_183 = F_144 ( V_182 ) ;
V_161 = F_145 ( V_178 , V_183 ) ;
if ( V_161 )
V_158 = V_187 ;
if ( F_146 ( V_158 ) ) {
F_125 ( ( V_179 ,
L_42 ,
V_176 , V_181 , V_182 ,
F_147 ( V_158 ) ) ) ;
} else {
F_125 ( ( V_179 ,
L_43 , V_176 ,
V_181 , V_182 ) ) ;
}
return V_158 ;
}
T_11 F_148 ( T_20 V_176 , T_1 V_181 )
{
struct V_177 * V_178 = (struct V_177 * ) V_176 ;
if ( ! V_178 || ( V_181 < 1 ) )
return V_67 ;
if ( V_181 > 1 )
return V_184 ;
F_125 ( ( V_179 , L_44 , V_176 ,
V_181 ) ) ;
F_149 ( V_178 ) ;
return V_68 ;
}
T_1 F_150 ( char * V_30 )
{
#ifdef F_10
if ( V_31 ) {
T_1 V_188 ;
F_151 ( V_30 , sizeof( V_189 ) ) ;
V_188 = strlen ( V_30 ) - 1 ;
V_30 [ V_188 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_152 ( T_1 V_153 , void * V_190 )
{
switch ( V_153 ) {
case V_191 :
F_12 (KERN_ERR PREFIX L_45 ) ;
break;
case V_192 :
break;
default:
break;
}
return V_68 ;
}
static int T_3 F_153 ( char * V_69 )
{
char * V_193 = V_75 ;
int V_194 = V_195 - 1 ;
if ( ! V_69 || ! * V_69 )
return 0 ;
for (; V_194 -- && * V_69 ; V_69 ++ ) {
if ( isalnum ( * V_69 ) || * V_69 == ' ' || * V_69 == ':' )
* V_193 ++ = * V_69 ;
else if ( * V_69 == '\'' || * V_69 == '"' )
continue;
else
break;
}
* V_193 = 0 ;
return 1 ;
}
void T_3 F_154 ( char * V_69 )
{
struct V_196 * V_197 ;
bool V_198 = true ;
int V_199 ;
if ( ! V_200 )
return;
if ( V_69 == NULL || * V_69 == '\0' ) {
F_12 (KERN_INFO PREFIX L_46 ) ;
V_200 = FALSE ;
return;
}
if ( * V_69 == '!' ) {
V_69 ++ ;
if ( * V_69 == '\0' ) {
V_201 . V_202 = 1 ;
return;
} else if ( * V_69 == '*' ) {
F_3 ( V_203 ) ;
for ( V_199 = 0 ; V_199 < V_204 ; V_199 ++ ) {
V_197 = & V_205 [ V_199 ] ;
V_197 -> V_198 = false ;
}
return;
}
V_198 = false ;
}
for ( V_199 = 0 ; V_199 < V_204 ; V_199 ++ ) {
V_197 = & V_205 [ V_199 ] ;
if ( ! strcmp ( V_197 -> string , V_69 ) ) {
V_197 -> V_198 = V_198 ;
break;
} else if ( V_197 -> string [ 0 ] == '\0' ) {
V_197 -> V_198 = V_198 ;
strncpy ( V_197 -> string , V_69 , V_206 ) ;
break;
}
}
}
static void T_3 F_155 ( unsigned int V_198 )
{
if ( V_201 . V_198 != V_198 )
V_201 . V_198 = V_198 ;
if ( V_201 . V_198 )
F_154 ( L_1 ) ;
else
F_154 ( L_47 ) ;
return;
}
static void T_3 F_156 ( unsigned int V_198 )
{
V_201 . V_207 = 1 ;
V_201 . V_208 = 0 ;
F_155 ( V_198 ) ;
return;
}
void T_3 F_157 ( int V_198 , const struct V_209 * V_210 )
{
F_12 (KERN_NOTICE PREFIX L_48 , d->ident) ;
if ( V_198 == - 1 )
return;
V_201 . V_208 = 1 ;
F_155 ( V_198 ) ;
return;
}
static void T_3 F_158 ( void )
{
struct V_196 * V_197 ;
char * V_69 ;
int V_199 ;
T_11 V_158 ;
if ( V_201 . V_202 ) {
V_158 = F_3 ( V_3 ) ;
if ( F_159 ( V_158 ) )
F_12 (KERN_INFO PREFIX L_49 ) ;
}
for ( V_199 = 0 ; V_199 < V_204 ; V_199 ++ ) {
V_197 = & V_205 [ V_199 ] ;
V_69 = V_197 -> string ;
if ( * V_69 == '\0' )
break;
if ( V_197 -> V_198 ) {
V_158 = F_160 ( V_69 ) ;
if ( F_159 ( V_158 ) )
F_12 (KERN_INFO PREFIX L_50 , str) ;
} else {
V_158 = F_161 ( V_69 ) ;
if ( F_159 ( V_158 ) )
F_12 (KERN_INFO PREFIX L_51 , str) ;
}
}
}
static int T_3 F_162 ( char * V_69 )
{
if ( V_69 && ! strcmp ( L_1 , V_69 ) )
F_156 ( 1 ) ;
else if ( V_69 && ! strcmp ( L_47 , V_69 ) )
F_156 ( 0 ) ;
else
F_154 ( V_69 ) ;
return 1 ;
}
static int T_3 F_163 ( char * V_69 )
{
V_211 = FALSE ;
F_63 ( L_52 ) ;
return 1 ;
}
static int T_3 F_164 ( char * V_69 )
{
if ( V_69 == NULL || * V_69 == '\0' )
return 0 ;
if ( ! strcmp ( L_53 , V_69 ) )
V_212 = V_213 ;
else if ( ! strcmp ( L_54 , V_69 ) )
V_212 = V_214 ;
else if ( ! strcmp ( L_55 , V_69 ) )
V_212 = V_215 ;
return 1 ;
}
int F_165 ( const struct V_216 * V_217 )
{
T_21 V_11 ;
T_7 V_7 ;
T_12 V_218 = 0 ;
int V_219 = 0 ;
if ( V_212 == V_215 )
return 0 ;
if ( ! ( V_217 -> V_220 & V_221 ) && ! ( V_217 -> V_220 & V_222 ) )
return 0 ;
if ( V_217 -> V_220 & V_221 )
V_11 = V_12 ;
else
V_11 = V_13 ;
V_7 = F_166 ( V_217 ) ;
if ( V_212 != V_215 )
V_218 = 1 ;
V_219 = F_167 ( V_11 , V_217 -> V_223 , V_7 , V_218 ) ;
if ( V_219 ) {
if ( V_212 != V_215 ) {
if ( V_212 == V_214 )
F_12 ( V_224 L_56
L_57
L_58 ) ;
F_12 ( V_225 L_59
L_60
L_61 ) ;
}
if ( V_212 == V_213 )
return - V_226 ;
}
return 0 ;
}
int F_168 ( T_22 V_223 , T_22 V_227 ,
const char * V_74 )
{
struct V_216 V_217 = {
. V_223 = V_223 ,
. V_77 = V_223 + V_227 - 1 ,
. V_74 = V_74 ,
. V_220 = V_221 ,
} ;
return F_165 ( & V_217 ) ;
}
int F_169 ( void )
{
return V_212 == V_213 ;
}
bool F_170 ( void )
{
return V_228 >= V_229 ;
}
void F_171 ( T_23 V_176 )
{
F_172 ( V_176 ) ;
}
T_24 F_173 ( T_23 V_230 )
{
T_24 V_220 ;
F_174 ( V_230 , V_220 ) ;
return V_220 ;
}
void F_175 ( T_23 V_230 , T_24 V_220 )
{
F_176 ( V_230 , V_220 ) ;
}
T_11
F_177 ( char * V_74 , V_136 V_45 , V_136 V_231 , T_25 * * V_232 )
{
* V_232 = F_178 ( V_74 , V_45 , 0 , 0 , NULL ) ;
if ( * V_232 == NULL )
return V_149 ;
else
return V_68 ;
}
T_11 F_179 ( T_25 * V_232 )
{
F_180 ( V_232 ) ;
return ( V_68 ) ;
}
T_11 F_181 ( T_25 * V_232 )
{
F_182 ( V_232 ) ;
return ( V_68 ) ;
}
T_11 F_183 ( T_25 * V_232 , void * V_233 )
{
F_184 ( V_232 , V_233 ) ;
return ( V_68 ) ;
}
static int T_3 F_185 ( char * V_234 )
{
V_235 = TRUE ;
F_63 ( L_62 ) ;
return 0 ;
}
static int T_3 F_186 ( char * V_234 )
{
F_12 (KERN_NOTICE PREFIX
L_63 ) ;
V_236 = TRUE ;
return 1 ;
}
T_11 T_3 F_187 ( void )
{
F_53 ( & V_14 . V_15 ) ;
F_53 ( & V_14 . V_17 ) ;
F_53 ( & V_14 . V_26 ) ;
F_53 ( & V_14 . V_28 ) ;
if ( V_14 . V_220 & V_237 ) {
int V_238 ;
V_238 = F_53 ( & V_14 . V_239 ) ;
F_188 ( V_63 L_64 , V_64 , V_238 ) ;
}
return V_68 ;
}
T_11 T_3 F_189 ( void )
{
V_167 = F_190 ( L_65 , 0 , 1 ) ;
V_166 = F_190 ( L_66 , 0 , 1 ) ;
V_173 = F_191 ( L_67 , 0 ) ;
F_141 ( ! V_167 ) ;
F_141 ( ! V_166 ) ;
F_141 ( ! V_173 ) ;
F_192 ( F_1 ) ;
F_158 () ;
return V_68 ;
}
T_11 F_193 ( void )
{
if ( F_78 ) {
F_83 ( V_14 . V_124 ,
F_78 ) ;
}
F_54 ( & V_14 . V_28 ) ;
F_54 ( & V_14 . V_26 ) ;
F_54 ( & V_14 . V_17 ) ;
F_54 ( & V_14 . V_15 ) ;
if ( V_14 . V_220 & V_237 )
F_54 ( & V_14 . V_239 ) ;
F_194 ( V_167 ) ;
F_194 ( V_166 ) ;
F_194 ( V_173 ) ;
return V_68 ;
}
T_11 F_195 ( T_12 V_240 , T_1 V_241 ,
T_1 V_242 )
{
int V_243 = 0 ;
if ( V_244 )
V_243 = V_244 ( V_240 ,
V_241 , V_242 ) ;
if ( V_243 < 0 )
return V_149 ;
else if ( V_243 > 0 )
return V_245 ;
return V_68 ;
}
void F_196 ( int (* F_197)( T_12 V_240 ,
T_1 V_246 , T_1 V_247 ) )
{
V_244 = F_197 ;
}
T_11 F_198 ( T_12 V_240 , T_1 V_248 ,
T_1 V_249 )
{
int V_243 = 0 ;
if ( V_250 )
V_243 = V_250 ( V_240 ,
V_248 , V_249 ) ;
if ( V_243 < 0 )
return V_149 ;
else if ( V_243 > 0 )
return V_245 ;
return V_68 ;
}
void F_199 ( int (* F_197)( T_12 V_240 ,
T_1 V_248 , T_1 V_249 ) )
{
V_250 = F_197 ;
}
