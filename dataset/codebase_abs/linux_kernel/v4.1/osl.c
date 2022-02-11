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
static void T_3 F_7 ( void )
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
T_11
F_57 ( const struct V_69 * V_70 ,
T_2 * V_71 )
{
if ( ! V_70 || ! V_71 )
return V_67 ;
* V_71 = NULL ;
if ( ! memcmp ( V_70 -> V_72 , L_21 , 4 ) && strlen ( V_73 ) ) {
F_12 (KERN_INFO PREFIX L_22 ,
acpi_os_name) ;
* V_71 = V_73 ;
}
return V_68 ;
}
static T_12 T_3 F_58 ( T_12 * V_30 , T_1 V_7 )
{
T_12 V_74 = 0 ;
T_12 * V_75 = V_30 + V_7 ;
while ( V_30 < V_75 )
V_74 = ( T_12 ) ( V_74 + * ( V_30 ++ ) ) ;
return V_74 ;
}
void T_3 F_59 ( void * V_76 , T_13 V_45 )
{
int V_77 , V_78 , V_79 = 0 , V_80 = 0 ;
long V_81 = 0 ;
struct V_82 * V_83 ;
char V_84 [ 32 ] = L_23 ;
struct V_85 V_86 ;
if ( V_76 == NULL || V_45 == 0 )
return;
for ( V_78 = 0 ; V_78 < V_87 ; V_78 ++ ) {
V_86 = F_60 ( V_84 , V_76 , V_45 , & V_81 ) ;
if ( ! V_86 . V_76 )
break;
V_76 += V_81 ;
V_45 -= V_81 ;
if ( V_86 . V_45 < sizeof( struct V_82 ) ) {
F_61 ( L_24 ,
V_84 , V_86 . V_72 ) ;
continue;
}
V_83 = V_86 . V_76 ;
for ( V_77 = 0 ; V_88 [ V_77 ] ; V_77 ++ )
if ( ! memcmp ( V_83 -> V_89 , V_88 [ V_77 ] , 4 ) )
break;
if ( ! V_88 [ V_77 ] ) {
F_61 ( L_25 ,
V_84 , V_86 . V_72 ) ;
continue;
}
if ( V_86 . V_45 != V_83 -> V_7 ) {
F_61 ( L_26 ,
V_84 , V_86 . V_72 ) ;
continue;
}
if ( F_58 ( V_86 . V_76 , V_83 -> V_7 ) ) {
F_61 ( L_27 ,
V_84 , V_86 . V_72 ) ;
continue;
}
F_62 ( L_28 ,
V_83 -> V_89 , V_84 , V_86 . V_72 , V_83 -> V_7 ) ;
V_90 += V_83 -> V_7 ;
V_91 [ V_79 ] . V_76 = V_86 . V_76 ;
V_91 [ V_79 ] . V_45 = V_86 . V_45 ;
V_79 ++ ;
}
if ( V_79 == 0 )
return;
V_92 =
F_63 ( 0 , V_93 << V_53 ,
V_90 , V_54 ) ;
if ( ! V_92 ) {
F_64 ( 1 ) ;
return;
}
F_65 ( V_92 , V_90 ) ;
F_66 ( V_92 , V_90 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
unsigned char * V_94 = V_91 [ V_78 ] . V_76 ;
T_14 V_45 = V_91 [ V_78 ] . V_45 ;
T_14 V_95 = V_92 + V_80 ;
T_14 V_96 , V_97 ;
char * V_98 ;
V_80 += V_45 ;
while ( V_45 ) {
V_96 = V_95 & ~ V_99 ;
V_97 = V_45 ;
if ( V_97 > V_100 - V_96 )
V_97 = V_100 - V_96 ;
V_98 = F_67 ( V_95 & V_99 ,
V_97 + V_96 ) ;
memcpy ( V_98 + V_96 , V_94 , V_97 ) ;
F_68 ( V_98 , V_97 + V_96 ) ;
V_94 += V_97 ;
V_95 += V_97 ;
V_45 -= V_97 ;
}
}
}
static void F_69 ( struct V_82 * V_83 )
{
F_70 ( V_63
L_29 ,
V_83 -> V_89 , V_83 -> V_101 ) ;
F_71 ( V_102 , V_103 ) ;
}
T_11
F_72 ( struct V_82 * V_104 ,
struct V_82 * * V_105 )
{
if ( ! V_104 || ! V_105 )
return V_67 ;
* V_105 = NULL ;
#ifdef F_73
if ( strncmp ( V_104 -> V_89 , L_30 , 4 ) == 0 )
* V_105 = (struct V_82 * ) V_106 ;
#endif
if ( * V_105 != NULL )
F_69 ( V_104 ) ;
return V_68 ;
}
T_11
F_74 ( struct V_82 * V_104 ,
T_6 * V_10 ,
T_1 * V_107 )
{
#ifndef F_75
* V_107 = 0 ;
* V_10 = 0 ;
return V_68 ;
#else
int V_108 = 0 ;
struct V_82 * V_83 ;
* V_107 = 0 ;
* V_10 = 0 ;
if ( ! V_92 )
return V_68 ;
do {
if ( V_108 + V_109 > V_90 ) {
F_64 ( 1 ) ;
return V_68 ;
}
V_83 = F_43 ( V_92 + V_108 ,
V_109 ) ;
if ( V_108 + V_83 -> V_7 > V_90 ) {
F_51 ( V_83 , V_109 ) ;
F_64 ( 1 ) ;
return V_68 ;
}
V_108 += V_83 -> V_7 ;
if ( memcmp ( V_104 -> V_89 , V_83 -> V_89 , 4 ) ) {
F_51 ( V_83 ,
V_109 ) ;
continue;
}
if ( memcmp ( V_83 -> V_101 , V_104 -> V_101 ,
V_110 ) ) {
F_51 ( V_83 ,
V_109 ) ;
continue;
}
V_108 -= V_83 -> V_7 ;
* V_107 = V_83 -> V_7 ;
F_51 ( V_83 , V_109 ) ;
* V_10 = V_92 + V_108 ;
break;
} while ( V_108 + V_109 < V_90 );
if ( * V_10 != 0 )
F_69 ( V_104 ) ;
return V_68 ;
#endif
}
static T_15 F_76 ( int V_111 , void * V_112 )
{
T_1 V_113 ;
V_113 = (* F_77) ( V_114 ) ;
if ( V_113 ) {
V_115 ++ ;
return V_116 ;
} else {
V_117 ++ ;
return V_118 ;
}
}
T_11
F_78 ( T_1 V_119 , T_16 V_120 ,
void * V_121 )
{
unsigned int V_111 ;
F_79 () ;
if ( V_119 != V_14 . V_122 )
return V_67 ;
if ( F_77 )
return V_123 ;
if ( F_80 ( V_119 , & V_111 ) < 0 ) {
F_12 (KERN_ERR PREFIX L_31 ,
gsi) ;
return V_68 ;
}
F_77 = V_120 ;
V_114 = V_121 ;
if ( F_81 ( V_111 , F_76 , V_124 , L_32 , F_76 ) ) {
F_12 (KERN_ERR PREFIX L_33 , irq) ;
F_77 = NULL ;
return V_125 ;
}
return V_68 ;
}
T_11 F_82 ( T_1 V_111 , T_16 V_120 )
{
if ( V_111 != V_14 . V_122 )
return V_67 ;
F_83 ( V_111 , F_76 ) ;
F_77 = NULL ;
return V_68 ;
}
void F_84 ( T_4 V_126 )
{
F_85 ( V_126 ) ;
}
void F_86 ( T_1 V_127 )
{
while ( V_127 ) {
T_1 V_128 = 1000 ;
if ( V_128 > V_127 )
V_128 = V_127 ;
F_87 ( V_128 ) ;
F_88 () ;
V_127 -= V_128 ;
}
}
T_4 F_89 ( void )
{
T_4 V_129 = F_90 ( F_91 () ) ;
F_92 ( V_129 , 100 ) ;
return V_129 ;
}
T_11 F_93 ( T_17 V_130 , T_1 * V_131 , T_1 V_132 )
{
T_1 V_133 ;
if ( ! V_131 )
V_131 = & V_133 ;
* V_131 = 0 ;
if ( V_132 <= 8 ) {
* ( T_12 * ) V_131 = F_94 ( V_130 ) ;
} else if ( V_132 <= 16 ) {
* ( V_134 * ) V_131 = F_95 ( V_130 ) ;
} else if ( V_132 <= 32 ) {
* ( T_1 * ) V_131 = F_96 ( V_130 ) ;
} else {
F_97 () ;
}
return V_68 ;
}
T_11 F_98 ( T_17 V_130 , T_1 V_131 , T_1 V_132 )
{
if ( V_132 <= 8 ) {
F_99 ( V_131 , V_130 ) ;
} else if ( V_132 <= 16 ) {
F_100 ( V_131 , V_130 ) ;
} else if ( V_132 <= 32 ) {
F_101 ( V_131 , V_130 ) ;
} else {
F_97 () ;
}
return V_68 ;
}
static inline T_4 F_102 ( const volatile void T_8 * V_9 )
{
return F_103 ( V_9 ) ;
}
static inline T_4 F_102 ( const volatile void T_8 * V_9 )
{
T_4 V_135 , V_136 ;
V_135 = F_104 ( V_9 ) ;
V_136 = F_104 ( V_9 + 4 ) ;
return V_135 | ( V_136 << 32 ) ;
}
T_11
F_105 ( T_6 V_137 , T_4 * V_131 , T_1 V_132 )
{
void T_8 * V_138 ;
unsigned int V_45 = V_132 / 8 ;
bool V_139 = false ;
T_4 V_133 ;
F_106 () ;
V_138 = F_22 ( V_137 , V_45 ) ;
if ( ! V_138 ) {
F_107 () ;
V_138 = F_31 ( V_137 , V_45 ) ;
if ( ! V_138 )
return V_140 ;
V_139 = true ;
}
if ( ! V_131 )
V_131 = & V_133 ;
switch ( V_132 ) {
case 8 :
* ( T_12 * ) V_131 = F_108 ( V_138 ) ;
break;
case 16 :
* ( V_134 * ) V_131 = F_109 ( V_138 ) ;
break;
case 32 :
* ( T_1 * ) V_131 = F_104 ( V_138 ) ;
break;
case 64 :
* ( T_4 * ) V_131 = F_102 ( V_138 ) ;
break;
default:
F_97 () ;
}
if ( V_139 )
F_34 ( V_138 ) ;
else
F_107 () ;
return V_68 ;
}
static inline void F_110 ( T_4 V_141 , volatile void T_8 * V_9 )
{
F_111 ( V_141 , V_9 ) ;
}
static inline void F_110 ( T_4 V_141 , volatile void T_8 * V_9 )
{
F_112 ( V_141 , V_9 ) ;
F_112 ( V_141 >> 32 , V_9 + 4 ) ;
}
T_11
F_113 ( T_6 V_137 , T_4 V_131 , T_1 V_132 )
{
void T_8 * V_138 ;
unsigned int V_45 = V_132 / 8 ;
bool V_139 = false ;
F_106 () ;
V_138 = F_22 ( V_137 , V_45 ) ;
if ( ! V_138 ) {
F_107 () ;
V_138 = F_31 ( V_137 , V_45 ) ;
if ( ! V_138 )
return V_140 ;
V_139 = true ;
}
switch ( V_132 ) {
case 8 :
F_114 ( V_131 , V_138 ) ;
break;
case 16 :
F_115 ( V_131 , V_138 ) ;
break;
case 32 :
F_112 ( V_131 , V_138 ) ;
break;
case 64 :
F_110 ( V_131 , V_138 ) ;
break;
default:
F_97 () ;
}
if ( V_139 )
F_34 ( V_138 ) ;
else
F_107 () ;
return V_68 ;
}
T_11
F_116 ( struct V_142 * V_143 , T_1 V_144 ,
T_4 * V_131 , T_1 V_132 )
{
int V_145 , V_45 ;
T_1 V_146 ;
if ( ! V_131 )
return V_67 ;
switch ( V_132 ) {
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
return V_147 ;
}
V_145 = F_117 ( V_143 -> V_148 , V_143 -> V_149 ,
F_118 ( V_143 -> V_150 , V_143 -> V_151 ) ,
V_144 , V_45 , & V_146 ) ;
* V_131 = V_146 ;
return ( V_145 ? V_147 : V_68 ) ;
}
T_11
F_119 ( struct V_142 * V_143 , T_1 V_144 ,
T_4 V_131 , T_1 V_132 )
{
int V_145 , V_45 ;
switch ( V_132 ) {
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
return V_147 ;
}
V_145 = F_120 ( V_143 -> V_148 , V_143 -> V_149 ,
F_118 ( V_143 -> V_150 , V_143 -> V_151 ) ,
V_144 , V_45 , V_131 ) ;
return ( V_145 ? V_147 : V_68 ) ;
}
static void F_121 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_122 ( V_153 , struct V_154 , V_153 ) ;
V_155 -> V_151 ( V_155 -> V_121 ) ;
F_40 ( V_155 ) ;
}
T_11 F_123 ( T_18 type ,
T_19 V_151 , void * V_121 )
{
T_11 V_156 = V_68 ;
struct V_154 * V_155 ;
struct V_157 * V_158 ;
int V_159 ;
F_124 ( ( V_160 ,
L_34 ,
V_151 , V_121 ) ) ;
V_155 = F_37 ( sizeof( struct V_154 ) , V_161 ) ;
if ( ! V_155 )
return V_162 ;
V_155 -> V_151 = V_151 ;
V_155 -> V_121 = V_121 ;
if ( type == V_163 ) {
V_158 = V_164 ;
F_125 ( & V_155 -> V_153 , F_121 ) ;
} else {
V_158 = V_165 ;
F_125 ( & V_155 -> V_153 , F_121 ) ;
}
V_159 = F_126 ( 0 , V_158 , & V_155 -> V_153 ) ;
if ( ! V_159 ) {
F_12 (KERN_ERR PREFIX
L_35 ) ;
V_156 = V_147 ;
F_40 ( V_155 ) ;
}
return V_156 ;
}
void F_127 ( void )
{
if ( F_77 )
F_128 ( V_14 . V_122 ) ;
F_129 ( V_165 ) ;
F_129 ( V_164 ) ;
}
static void F_130 ( struct V_152 * V_153 )
{
struct V_166 * V_167 = F_122 ( V_153 , struct V_166 , V_153 ) ;
F_127 () ;
F_131 ( V_167 -> V_168 , V_167 -> V_169 ) ;
F_40 ( V_167 ) ;
}
T_11 F_132 ( struct V_170 * V_168 , T_1 V_169 )
{
struct V_166 * V_167 ;
F_124 ( ( V_160 ,
L_36 ,
V_168 , V_169 ) ) ;
V_167 = F_133 ( sizeof( * V_167 ) , V_60 ) ;
if ( ! V_167 )
return V_162 ;
F_125 ( & V_167 -> V_153 , F_130 ) ;
V_167 -> V_168 = V_168 ;
V_167 -> V_169 = V_169 ;
if ( ! F_134 ( V_171 , & V_167 -> V_153 ) ) {
F_40 ( V_167 ) ;
return V_147 ;
}
return V_68 ;
}
bool F_135 ( struct V_152 * V_153 )
{
return F_134 ( V_171 , V_153 ) ;
}
T_11
F_136 ( T_1 V_172 , T_1 V_173 , T_20 * V_174 )
{
struct V_175 * V_176 = NULL ;
V_176 = F_137 ( sizeof( struct V_175 ) ) ;
if ( ! V_176 )
return V_162 ;
F_138 ( V_176 , V_173 ) ;
* V_174 = ( T_20 * ) V_176 ;
F_124 ( ( V_177 , L_37 ,
* V_174 , V_173 ) ) ;
return V_68 ;
}
T_11 F_139 ( T_20 V_174 )
{
struct V_175 * V_176 = (struct V_175 * ) V_174 ;
if ( ! V_176 )
return V_67 ;
F_124 ( ( V_177 , L_38 , V_174 ) ) ;
F_140 ( ! F_141 ( & V_176 -> V_178 ) ) ;
F_40 ( V_176 ) ;
V_176 = NULL ;
return V_68 ;
}
T_11 F_142 ( T_20 V_174 , T_1 V_179 , V_134 V_180 )
{
T_11 V_156 = V_68 ;
struct V_175 * V_176 = (struct V_175 * ) V_174 ;
long V_181 ;
int V_159 = 0 ;
if ( ! V_176 || ( V_179 < 1 ) )
return V_67 ;
if ( V_179 > 1 )
return V_182 ;
F_124 ( ( V_177 , L_39 ,
V_174 , V_179 , V_180 ) ) ;
if ( V_180 == V_183 )
V_181 = V_184 ;
else
V_181 = F_143 ( V_180 ) ;
V_159 = F_144 ( V_176 , V_181 ) ;
if ( V_159 )
V_156 = V_185 ;
if ( F_145 ( V_156 ) ) {
F_124 ( ( V_177 ,
L_40 ,
V_174 , V_179 , V_180 ,
F_146 ( V_156 ) ) ) ;
} else {
F_124 ( ( V_177 ,
L_41 , V_174 ,
V_179 , V_180 ) ) ;
}
return V_156 ;
}
T_11 F_147 ( T_20 V_174 , T_1 V_179 )
{
struct V_175 * V_176 = (struct V_175 * ) V_174 ;
if ( ! V_176 || ( V_179 < 1 ) )
return V_67 ;
if ( V_179 > 1 )
return V_182 ;
F_124 ( ( V_177 , L_42 , V_174 ,
V_179 ) ) ;
F_148 ( V_176 ) ;
return V_68 ;
}
T_1 F_149 ( char * V_30 )
{
#ifdef F_10
if ( V_31 ) {
T_1 V_186 ;
F_150 ( V_30 , sizeof( V_187 ) ) ;
V_186 = strlen ( V_30 ) - 1 ;
V_30 [ V_186 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_151 ( T_1 V_151 , void * V_188 )
{
switch ( V_151 ) {
case V_189 :
F_12 (KERN_ERR PREFIX L_43 ) ;
break;
case V_190 :
break;
default:
break;
}
return V_68 ;
}
static int T_3 F_152 ( char * V_191 )
{
char * V_192 = V_73 ;
int V_193 = V_194 - 1 ;
if ( ! V_191 || ! * V_191 )
return 0 ;
for (; V_193 -- && * V_191 ; V_191 ++ ) {
if ( isalnum ( * V_191 ) || * V_191 == ' ' || * V_191 == ':' )
* V_192 ++ = * V_191 ;
else if ( * V_191 == '\'' || * V_191 == '"' )
continue;
else
break;
}
* V_192 = 0 ;
return 1 ;
}
void T_3 F_153 ( char * V_191 )
{
struct V_195 * V_196 ;
bool V_197 = true ;
int V_198 ;
if ( ! V_199 )
return;
if ( V_191 == NULL || * V_191 == '\0' ) {
F_12 (KERN_INFO PREFIX L_44 ) ;
V_199 = FALSE ;
return;
}
if ( * V_191 == '!' ) {
V_191 ++ ;
if ( * V_191 == '\0' ) {
V_200 . V_201 = 1 ;
return;
} else if ( * V_191 == '*' ) {
F_3 ( V_202 ) ;
for ( V_198 = 0 ; V_198 < V_203 ; V_198 ++ ) {
V_196 = & V_204 [ V_198 ] ;
V_196 -> V_197 = false ;
}
return;
}
V_197 = false ;
}
for ( V_198 = 0 ; V_198 < V_203 ; V_198 ++ ) {
V_196 = & V_204 [ V_198 ] ;
if ( ! strcmp ( V_196 -> string , V_191 ) ) {
V_196 -> V_197 = V_197 ;
break;
} else if ( V_196 -> string [ 0 ] == '\0' ) {
V_196 -> V_197 = V_197 ;
strncpy ( V_196 -> string , V_191 , V_205 ) ;
break;
}
}
}
static void T_3 F_154 ( unsigned int V_197 )
{
if ( V_200 . V_197 != V_197 )
V_200 . V_197 = V_197 ;
if ( V_200 . V_197 )
F_153 ( L_1 ) ;
else
F_153 ( L_45 ) ;
return;
}
static void T_3 F_155 ( unsigned int V_197 )
{
V_200 . V_206 = 1 ;
V_200 . V_207 = 0 ;
F_154 ( V_197 ) ;
return;
}
void T_3 F_156 ( int V_197 , const struct V_208 * V_209 )
{
F_12 (KERN_NOTICE PREFIX L_46 , d->ident) ;
if ( V_197 == - 1 )
return;
V_200 . V_207 = 1 ;
F_154 ( V_197 ) ;
return;
}
static void T_3 F_157 ( void )
{
struct V_195 * V_196 ;
char * V_191 ;
int V_198 ;
T_11 V_156 ;
if ( V_200 . V_201 ) {
V_156 = F_3 ( V_3 ) ;
if ( F_158 ( V_156 ) )
F_12 (KERN_INFO PREFIX L_47 ) ;
}
for ( V_198 = 0 ; V_198 < V_203 ; V_198 ++ ) {
V_196 = & V_204 [ V_198 ] ;
V_191 = V_196 -> string ;
if ( * V_191 == '\0' )
break;
if ( V_196 -> V_197 ) {
V_156 = F_159 ( V_191 ) ;
if ( F_158 ( V_156 ) )
F_12 (KERN_INFO PREFIX L_48 , str) ;
} else {
V_156 = F_160 ( V_191 ) ;
if ( F_158 ( V_156 ) )
F_12 (KERN_INFO PREFIX L_49 , str) ;
}
}
}
static int T_3 F_161 ( char * V_191 )
{
if ( V_191 && ! strcmp ( L_1 , V_191 ) )
F_155 ( 1 ) ;
else if ( V_191 && ! strcmp ( L_45 , V_191 ) )
F_155 ( 0 ) ;
else
F_153 ( V_191 ) ;
return 1 ;
}
static int T_3 F_162 ( char * V_191 )
{
V_210 = FALSE ;
F_62 ( L_50 ) ;
return 1 ;
}
static int T_3 F_163 ( char * V_191 )
{
if ( V_191 == NULL || * V_191 == '\0' )
return 0 ;
if ( ! strcmp ( L_51 , V_191 ) )
V_211 = V_212 ;
else if ( ! strcmp ( L_52 , V_191 ) )
V_211 = V_213 ;
else if ( ! strcmp ( L_53 , V_191 ) )
V_211 = V_214 ;
return 1 ;
}
int F_164 ( const struct V_215 * V_216 )
{
T_21 V_11 ;
T_7 V_7 ;
T_12 V_217 = 0 ;
int V_218 = 0 ;
if ( V_211 == V_214 )
return 0 ;
if ( ! ( V_216 -> V_219 & V_220 ) && ! ( V_216 -> V_219 & V_221 ) )
return 0 ;
if ( V_216 -> V_219 & V_220 )
V_11 = V_12 ;
else
V_11 = V_13 ;
V_7 = F_165 ( V_216 ) ;
if ( V_211 != V_214 )
V_217 = 1 ;
V_218 = F_166 ( V_11 , V_216 -> V_222 , V_7 , V_217 ) ;
if ( V_218 ) {
if ( V_211 != V_214 ) {
if ( V_211 == V_213 )
F_12 ( V_223 L_54
L_55
L_56 ) ;
F_12 ( V_224 L_57
L_58
L_59 ) ;
}
if ( V_211 == V_212 )
return - V_225 ;
}
return 0 ;
}
int F_167 ( T_22 V_222 , T_22 V_226 ,
const char * V_72 )
{
struct V_215 V_216 = {
. V_222 = V_222 ,
. V_75 = V_222 + V_226 - 1 ,
. V_72 = V_72 ,
. V_219 = V_220 ,
} ;
return F_164 ( & V_216 ) ;
}
int F_168 ( void )
{
return V_211 == V_212 ;
}
void F_169 ( T_23 V_174 )
{
F_170 ( V_174 ) ;
}
T_24 F_171 ( T_23 V_227 )
{
T_24 V_219 ;
F_172 ( V_227 , V_219 ) ;
return V_219 ;
}
void F_173 ( T_23 V_227 , T_24 V_219 )
{
F_174 ( V_227 , V_219 ) ;
}
T_11
F_175 ( char * V_72 , V_134 V_45 , V_134 V_228 , T_25 * * V_229 )
{
* V_229 = F_176 ( V_72 , V_45 , 0 , 0 , NULL ) ;
if ( * V_229 == NULL )
return V_147 ;
else
return V_68 ;
}
T_11 F_177 ( T_25 * V_229 )
{
F_178 ( V_229 ) ;
return ( V_68 ) ;
}
T_11 F_179 ( T_25 * V_229 )
{
F_180 ( V_229 ) ;
return ( V_68 ) ;
}
T_11 F_181 ( T_25 * V_229 , void * V_230 )
{
F_182 ( V_229 , V_230 ) ;
return ( V_68 ) ;
}
static int T_3 F_183 ( char * V_231 )
{
V_232 = TRUE ;
F_62 ( L_60 ) ;
return 0 ;
}
static int T_3 F_184 ( char * V_231 )
{
F_12 (KERN_NOTICE PREFIX
L_61 ) ;
V_233 = TRUE ;
return 1 ;
}
T_11 T_3 F_185 ( void )
{
F_53 ( & V_14 . V_15 ) ;
F_53 ( & V_14 . V_17 ) ;
F_53 ( & V_14 . V_26 ) ;
F_53 ( & V_14 . V_28 ) ;
if ( V_14 . V_219 & V_234 ) {
int V_235 ;
V_235 = F_53 ( & V_14 . V_236 ) ;
F_186 ( V_63 L_62 , V_64 , V_235 ) ;
}
return V_68 ;
}
T_11 T_3 F_187 ( void )
{
F_7 () ;
V_165 = F_188 ( L_63 , 0 , 1 ) ;
V_164 = F_188 ( L_64 , 0 , 1 ) ;
V_171 = F_189 ( L_65 , 0 ) ;
F_140 ( ! V_165 ) ;
F_140 ( ! V_164 ) ;
F_140 ( ! V_171 ) ;
F_190 ( F_1 ) ;
F_157 () ;
return V_68 ;
}
T_11 F_191 ( void )
{
if ( F_77 ) {
F_82 ( V_14 . V_122 ,
F_77 ) ;
}
F_54 ( & V_14 . V_28 ) ;
F_54 ( & V_14 . V_26 ) ;
F_54 ( & V_14 . V_17 ) ;
F_54 ( & V_14 . V_15 ) ;
if ( V_14 . V_219 & V_234 )
F_54 ( & V_14 . V_236 ) ;
F_192 ( V_165 ) ;
F_192 ( V_164 ) ;
F_192 ( V_171 ) ;
return V_68 ;
}
T_11 F_193 ( T_12 V_237 , T_1 V_238 ,
T_1 V_239 )
{
int V_240 = 0 ;
if ( V_241 )
V_240 = V_241 ( V_237 ,
V_238 , V_239 ) ;
if ( V_240 < 0 )
return V_147 ;
else if ( V_240 > 0 )
return V_242 ;
return V_68 ;
}
void F_194 ( int (* F_195)( T_12 V_237 ,
T_1 V_243 , T_1 V_244 ) )
{
V_241 = F_195 ;
}
T_11 F_196 ( T_12 V_237 , T_1 V_245 ,
T_1 V_246 )
{
int V_240 = 0 ;
if ( V_247 )
V_240 = V_247 ( V_237 ,
V_245 , V_246 ) ;
if ( V_240 < 0 )
return V_147 ;
else if ( V_240 > 0 )
return V_242 ;
return V_68 ;
}
void F_197 ( int (* F_195)( T_12 V_237 ,
T_1 V_245 , T_1 V_246 ) )
{
V_247 = F_195 ;
}
