static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
if ( ! strcmp ( L_1 , V_1 ) ) {
F_2 (KERN_NOTICE FW_BUG PREFIX
L_2 ,
osi_linux.enable ? L_3 : L_4 ,
osi_linux.cmdline ? L_5 :
osi_linux.dmi ? L_6 : L_7 ) ;
}
return V_2 ;
}
static void T_3 F_3 ( struct V_3 * V_4 ,
unsigned int V_5 , char * V_6 )
{
T_4 V_7 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_5 )
return;
if ( V_4 -> V_9 == V_10 )
F_4 ( V_7 , V_5 , V_6 ) ;
else if ( V_4 -> V_9 == V_11 )
F_5 ( V_7 , V_5 , V_6 ) ;
}
static int T_3 F_6 ( void )
{
F_3 ( & V_12 . V_13 , V_12 . V_14 ,
L_8 ) ;
F_3 ( & V_12 . V_15 , V_12 . V_14 ,
L_9 ) ;
F_3 ( & V_12 . V_16 , V_12 . V_17 ,
L_10 ) ;
F_3 ( & V_12 . V_18 , V_12 . V_17 ,
L_11 ) ;
if ( V_12 . V_19 == 4 )
F_3 ( & V_12 . V_20 , 4 , L_12 ) ;
F_3 ( & V_12 . V_21 , V_12 . V_22 ,
L_13 ) ;
if ( ! ( V_12 . V_23 & 0x1 ) )
F_3 ( & V_12 . V_24 ,
V_12 . V_23 , L_14 ) ;
if ( ! ( V_12 . V_25 & 0x1 ) )
F_3 ( & V_12 . V_26 ,
V_12 . V_25 , L_15 ) ;
return 0 ;
}
void F_7 ( const char * V_27 , ... )
{
T_5 args ;
va_start ( args , V_27 ) ;
F_8 ( V_27 , args ) ;
va_end ( args ) ;
}
void F_8 ( const char * V_27 , T_5 args )
{
static char V_28 [ 512 ] ;
vsprintf ( V_28 , V_27 , args ) ;
#ifdef F_9
if ( V_29 ) {
F_10 ( L_16 , V_28 ) ;
} else {
F_11 ( V_30 L_16 , V_28 ) ;
}
#else
F_11 ( V_30 L_16 , V_28 ) ;
#endif
}
static int T_3 F_12 ( char * V_31 )
{
V_32 = F_13 ( V_31 , NULL , 16 ) ;
return 0 ;
}
T_6 T_3 F_14 ( void )
{
#ifdef F_15
if ( V_32 )
return V_32 ;
#endif
if ( F_16 ( V_33 ) ) {
if ( V_34 . V_35 != V_36 )
return V_34 . V_35 ;
else if ( V_34 . V_37 != V_36 )
return V_34 . V_37 ;
else {
F_11 (KERN_ERR PREFIX
L_17 ) ;
return 0 ;
}
} else {
T_6 V_38 = 0 ;
F_17 ( & V_38 ) ;
return V_38 ;
}
}
static struct V_39 *
F_18 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 *
F_20 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_18 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_8 * F_21 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 = NULL ;
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
F_24 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_19 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 * F_25 ( T_6 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_8 V_51 * ) F_27 ( F_28 ( V_48 ) ) ;
} else
return F_29 ( V_46 , V_47 ) ;
}
static void F_30 ( T_6 V_46 , void T_8 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_26 ( V_48 ) )
F_31 ( F_28 ( V_48 ) ) ;
else
F_32 ( V_52 ) ;
}
void T_8 * T_9
F_33 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 ;
T_6 V_46 ;
T_7 V_47 ;
if ( V_40 > V_53 ) {
F_11 (KERN_ERR PREFIX L_18 ) ;
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
static void F_41 ( struct V_39 * V_42 )
{
if ( ! -- V_42 -> V_45 )
F_42 ( & V_42 -> V_57 ) ;
}
static void F_43 ( struct V_39 * V_42 )
{
if ( ! V_42 -> V_45 ) {
F_44 () ;
F_30 ( V_42 -> V_40 , V_42 -> V_43 ) ;
F_38 ( V_42 ) ;
}
}
void T_10 F_45 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
if ( ! V_54 ) {
F_46 ( V_43 , V_41 ) ;
return;
}
F_22 ( & V_44 ) ;
V_42 = F_24 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
F_47 ( true , V_59 L_19 , V_60 , V_43 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
void T_3 F_48 ( void T_8 * V_43 , T_7 V_41 )
{
if ( ! V_54 )
F_46 ( V_43 , V_41 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
T_4 V_7 ;
void T_8 * V_43 ;
if ( V_4 -> V_9 != V_11 )
return 0 ;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return - V_62 ;
V_43 = F_33 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_43 )
return - V_63 ;
return 0 ;
}
void F_50 ( struct V_3 * V_4 )
{
T_4 V_7 ;
struct V_39 * V_42 ;
if ( V_4 -> V_9 != V_11 )
return;
memcpy ( & V_7 , & V_4 -> V_8 , sizeof( V_7 ) ) ;
if ( ! V_7 || ! V_4 -> V_61 )
return;
F_22 ( & V_44 ) ;
V_42 = F_18 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_23 ( & V_44 ) ;
return;
}
F_41 ( V_42 ) ;
F_23 ( & V_44 ) ;
F_43 ( V_42 ) ;
}
T_11
F_51 ( void * V_43 , T_6 * V_40 )
{
if ( ! V_40 || ! V_43 )
return V_64 ;
* V_40 = F_52 ( V_43 ) ;
return V_65 ;
}
T_11
F_53 ( const struct V_66 * V_67 ,
T_2 * V_68 )
{
if ( ! V_67 || ! V_68 )
return V_64 ;
* V_68 = NULL ;
if ( ! memcmp ( V_67 -> V_69 , L_20 , 4 ) && strlen ( V_70 ) ) {
F_11 (KERN_INFO PREFIX L_21 ,
acpi_os_name) ;
* V_68 = V_70 ;
}
return V_65 ;
}
T_12 T_3 F_54 ( T_12 * V_28 , T_1 V_5 )
{
T_12 V_71 = 0 ;
T_12 * V_72 = V_28 + V_5 ;
while ( V_28 < V_72 )
V_71 = ( T_12 ) ( V_71 + * ( V_28 ++ ) ) ;
return V_71 ;
}
void T_3 F_55 ( void * V_73 , T_13 V_41 )
{
int V_74 , V_75 , V_76 = 0 , V_77 = 0 ;
long V_78 = 0 ;
struct V_79 * V_80 ;
char V_81 [ 32 ] = L_22 ;
struct V_82 V_83 ;
struct V_82 V_84 [ V_85 ] ;
char * V_86 ;
if ( V_73 == NULL || V_41 == 0 )
return;
for ( V_75 = 0 ; V_75 < V_85 ; V_75 ++ ) {
V_83 = F_56 ( V_81 , V_73 , V_41 , & V_78 ) ;
if ( ! V_83 . V_73 )
break;
V_73 += V_78 ;
V_41 -= V_78 ;
if ( V_83 . V_41 < sizeof( struct V_79 ) )
F_57 ( L_23 ,
V_81 , V_83 . V_69 ) ;
V_80 = V_83 . V_73 ;
for ( V_74 = 0 ; V_87 [ V_74 ] ; V_74 ++ )
if ( ! memcmp ( V_80 -> V_88 , V_87 [ V_74 ] , 4 ) )
break;
if ( ! V_87 [ V_74 ] )
F_57 ( L_24 ,
V_81 , V_83 . V_69 ) ;
if ( V_83 . V_41 != V_80 -> V_5 )
F_57 ( L_25 ,
V_81 , V_83 . V_69 ) ;
if ( F_54 ( V_83 . V_73 , V_80 -> V_5 ) )
F_57 ( L_26 ,
V_81 , V_83 . V_69 ) ;
F_58 ( L_27 ,
V_80 -> V_88 , V_81 , V_83 . V_69 , V_80 -> V_5 ) ;
V_89 += V_80 -> V_5 ;
V_84 [ V_76 ] . V_73 = V_83 . V_73 ;
V_84 [ V_76 ] . V_41 = V_83 . V_41 ;
V_76 ++ ;
}
if ( V_76 == 0 )
return;
V_90 =
F_59 ( 0 , V_91 << V_49 ,
V_89 , V_50 ) ;
if ( ! V_90 ) {
F_60 ( 1 ) ;
return;
}
F_61 ( V_90 , V_90 + V_89 ) ;
F_62 ( V_90 , V_89 ) ;
V_86 = F_63 ( V_90 , V_89 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
memcpy ( V_86 + V_77 , V_84 [ V_75 ] . V_73 ,
V_84 [ V_75 ] . V_41 ) ;
V_77 += V_84 [ V_75 ] . V_41 ;
}
F_64 ( V_86 , V_89 ) ;
}
static void F_65 ( struct V_79 * V_80 )
{
F_66 ( V_59
L_28 ,
V_80 -> V_88 , V_80 -> V_92 ) ;
F_67 ( V_93 ) ;
}
T_11
F_68 ( struct V_79 * V_94 ,
struct V_79 * * V_95 )
{
if ( ! V_94 || ! V_95 )
return V_64 ;
* V_95 = NULL ;
#ifdef F_69
if ( strncmp ( V_94 -> V_88 , L_29 , 4 ) == 0 )
* V_95 = (struct V_79 * ) V_96 ;
#endif
if ( * V_95 != NULL )
F_65 ( V_94 ) ;
return V_65 ;
}
T_11
F_70 ( struct V_79 * V_94 ,
T_6 * V_8 ,
T_1 * V_97 )
{
#ifndef F_71
* V_97 = 0 ;
* V_8 = 0 ;
return V_65 ;
#else
int V_98 = 0 ;
struct V_79 * V_80 ;
* V_97 = 0 ;
* V_8 = 0 ;
if ( ! V_90 )
return V_65 ;
do {
if ( V_98 + V_99 > V_89 ) {
F_60 ( 1 ) ;
return V_65 ;
}
V_80 = F_33 ( V_90 + V_98 ,
V_99 ) ;
if ( V_98 + V_80 -> V_5 > V_89 ) {
F_45 ( V_80 , V_99 ) ;
F_60 ( 1 ) ;
return V_65 ;
}
V_98 += V_80 -> V_5 ;
if ( memcmp ( V_94 -> V_88 , V_80 -> V_88 , 4 ) ) {
F_45 ( V_80 ,
V_99 ) ;
continue;
}
if ( memcmp ( V_80 -> V_92 , V_94 -> V_92 ,
V_100 ) ) {
F_45 ( V_80 ,
V_99 ) ;
continue;
}
V_98 -= V_80 -> V_5 ;
* V_97 = V_80 -> V_5 ;
F_45 ( V_80 , V_99 ) ;
* V_8 = V_90 + V_98 ;
break;
} while ( V_98 + V_99 < V_89 );
if ( * V_8 != 0 )
F_65 ( V_94 ) ;
return V_65 ;
#endif
}
static T_14 F_72 ( int V_101 , void * V_102 )
{
T_1 V_103 ;
V_103 = (* F_73) ( V_104 ) ;
if ( V_103 ) {
V_105 ++ ;
return V_106 ;
} else {
V_107 ++ ;
return V_108 ;
}
}
T_11
F_74 ( T_1 V_109 , T_15 V_110 ,
void * V_111 )
{
unsigned int V_101 ;
F_75 () ;
if ( V_109 != V_12 . V_112 )
return V_64 ;
if ( F_73 )
return V_113 ;
if ( F_76 ( V_109 , & V_101 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_30 ,
gsi) ;
return V_65 ;
}
F_73 = V_110 ;
V_104 = V_111 ;
if ( F_77 ( V_101 , F_72 , V_114 , L_31 , F_72 ) ) {
F_11 (KERN_ERR PREFIX L_32 , irq) ;
F_73 = NULL ;
return V_115 ;
}
return V_65 ;
}
T_11 F_78 ( T_1 V_101 , T_15 V_110 )
{
if ( V_101 != V_12 . V_112 )
return V_64 ;
F_79 ( V_101 , F_72 ) ;
F_73 = NULL ;
return V_65 ;
}
void F_80 ( T_4 V_116 )
{
F_81 ( F_82 ( V_116 ) ) ;
}
void F_83 ( T_1 V_117 )
{
while ( V_117 ) {
T_1 V_118 = 1000 ;
if ( V_118 > V_117 )
V_118 = V_117 ;
F_84 ( V_118 ) ;
F_85 () ;
V_117 -= V_118 ;
}
}
T_4 F_86 ( void )
{
static T_4 V_119 ;
#ifdef F_87
#endif
#ifdef F_88
#endif
if ( ! V_119 )
F_11 (KERN_ERR PREFIX L_33 ) ;
return ++ V_119 ;
}
T_11 F_89 ( T_16 V_120 , T_1 * V_121 , T_1 V_122 )
{
T_1 V_123 ;
if ( ! V_121 )
V_121 = & V_123 ;
* V_121 = 0 ;
if ( V_122 <= 8 ) {
* ( T_12 * ) V_121 = F_90 ( V_120 ) ;
} else if ( V_122 <= 16 ) {
* ( V_124 * ) V_121 = F_91 ( V_120 ) ;
} else if ( V_122 <= 32 ) {
* ( T_1 * ) V_121 = F_92 ( V_120 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
T_11 F_94 ( T_16 V_120 , T_1 V_121 , T_1 V_122 )
{
if ( V_122 <= 8 ) {
F_95 ( V_121 , V_120 ) ;
} else if ( V_122 <= 16 ) {
F_96 ( V_121 , V_120 ) ;
} else if ( V_122 <= 32 ) {
F_97 ( V_121 , V_120 ) ;
} else {
F_93 () ;
}
return V_65 ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
return F_99 ( V_7 ) ;
}
static inline T_4 F_98 ( const volatile void T_8 * V_7 )
{
T_4 V_125 , V_126 ;
V_125 = F_100 ( V_7 ) ;
V_126 = F_100 ( V_7 + 4 ) ;
return V_125 | ( V_126 << 32 ) ;
}
T_11
F_101 ( T_6 V_127 , T_4 * V_121 , T_1 V_122 )
{
void T_8 * V_128 ;
unsigned int V_41 = V_122 / 8 ;
bool V_129 = false ;
T_4 V_123 ;
F_102 () ;
V_128 = F_20 ( V_127 , V_41 ) ;
if ( ! V_128 ) {
F_103 () ;
V_128 = F_29 ( V_127 , V_41 ) ;
if ( ! V_128 )
return V_130 ;
V_129 = true ;
}
if ( ! V_121 )
V_121 = & V_123 ;
switch ( V_122 ) {
case 8 :
* ( T_12 * ) V_121 = F_104 ( V_128 ) ;
break;
case 16 :
* ( V_124 * ) V_121 = F_105 ( V_128 ) ;
break;
case 32 :
* ( T_1 * ) V_121 = F_100 ( V_128 ) ;
break;
case 64 :
* ( T_4 * ) V_121 = F_98 ( V_128 ) ;
break;
default:
F_93 () ;
}
if ( V_129 )
F_32 ( V_128 ) ;
else
F_103 () ;
return V_65 ;
}
static inline void F_106 ( T_4 V_131 , volatile void T_8 * V_7 )
{
F_107 ( V_131 , V_7 ) ;
}
static inline void F_106 ( T_4 V_131 , volatile void T_8 * V_7 )
{
F_108 ( V_131 , V_7 ) ;
F_108 ( V_131 >> 32 , V_7 + 4 ) ;
}
T_11
F_109 ( T_6 V_127 , T_4 V_121 , T_1 V_122 )
{
void T_8 * V_128 ;
unsigned int V_41 = V_122 / 8 ;
bool V_129 = false ;
F_102 () ;
V_128 = F_20 ( V_127 , V_41 ) ;
if ( ! V_128 ) {
F_103 () ;
V_128 = F_29 ( V_127 , V_41 ) ;
if ( ! V_128 )
return V_130 ;
V_129 = true ;
}
switch ( V_122 ) {
case 8 :
F_110 ( V_121 , V_128 ) ;
break;
case 16 :
F_111 ( V_121 , V_128 ) ;
break;
case 32 :
F_108 ( V_121 , V_128 ) ;
break;
case 64 :
F_106 ( V_121 , V_128 ) ;
break;
default:
F_93 () ;
}
if ( V_129 )
F_32 ( V_128 ) ;
else
F_103 () ;
return V_65 ;
}
T_11
F_112 ( struct V_132 * V_133 , T_1 V_134 ,
T_4 * V_121 , T_1 V_122 )
{
int V_135 , V_41 ;
T_1 V_136 ;
if ( ! V_121 )
return V_64 ;
switch ( V_122 ) {
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
return V_137 ;
}
V_135 = F_113 ( V_133 -> V_138 , V_133 -> V_139 ,
F_114 ( V_133 -> V_140 , V_133 -> V_141 ) ,
V_134 , V_41 , & V_136 ) ;
* V_121 = V_136 ;
return ( V_135 ? V_137 : V_65 ) ;
}
T_11
F_115 ( struct V_132 * V_133 , T_1 V_134 ,
T_4 V_121 , T_1 V_122 )
{
int V_135 , V_41 ;
switch ( V_122 ) {
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
return V_137 ;
}
V_135 = F_116 ( V_133 -> V_138 , V_133 -> V_139 ,
F_114 ( V_133 -> V_140 , V_133 -> V_141 ) ,
V_134 , V_41 , V_121 ) ;
return ( V_135 ? V_137 : V_65 ) ;
}
static void F_117 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = F_118 ( V_143 , struct V_144 , V_143 ) ;
if ( V_145 -> V_146 )
F_119 () ;
V_145 -> V_141 ( V_145 -> V_111 ) ;
F_38 ( V_145 ) ;
}
static T_11 F_120 ( T_17 type ,
T_18 V_141 , void * V_111 , int V_147 )
{
T_11 V_148 = V_65 ;
struct V_144 * V_145 ;
struct V_149 * V_150 ;
int V_151 ;
F_121 ( ( V_152 ,
L_34 ,
V_141 , V_111 ) ) ;
V_145 = F_35 ( sizeof( struct V_144 ) , V_153 ) ;
if ( ! V_145 )
return V_154 ;
V_145 -> V_141 = V_141 ;
V_145 -> V_111 = V_111 ;
if ( V_147 ) {
V_150 = V_155 ;
V_145 -> V_146 = 1 ;
F_122 ( & V_145 -> V_143 , F_117 ) ;
} else if ( type == V_156 ) {
V_150 = V_157 ;
F_122 ( & V_145 -> V_143 , F_117 ) ;
} else {
V_150 = V_158 ;
F_122 ( & V_145 -> V_143 , F_117 ) ;
}
V_151 = F_123 ( 0 , V_150 , & V_145 -> V_143 ) ;
if ( ! V_151 ) {
F_11 (KERN_ERR PREFIX
L_35 ) ;
V_148 = V_137 ;
F_38 ( V_145 ) ;
}
return V_148 ;
}
T_11 F_124 ( T_17 type ,
T_18 V_141 , void * V_111 )
{
return F_120 ( type , V_141 , V_111 , 0 ) ;
}
T_11 F_125 ( T_18 V_141 ,
void * V_111 )
{
return F_120 ( 0 , V_141 , V_111 , 1 ) ;
}
void F_119 ( void )
{
F_126 ( V_158 ) ;
F_126 ( V_157 ) ;
}
T_11
F_127 ( T_1 V_159 , T_1 V_160 , T_19 * V_161 )
{
struct V_162 * V_163 = NULL ;
V_163 = F_128 ( sizeof( struct V_162 ) ) ;
if ( ! V_163 )
return V_154 ;
memset ( V_163 , 0 , sizeof( struct V_162 ) ) ;
F_129 ( V_163 , V_160 ) ;
* V_161 = ( T_19 * ) V_163 ;
F_121 ( ( V_164 , L_36 ,
* V_161 , V_160 ) ) ;
return V_65 ;
}
T_11 F_130 ( T_19 V_161 )
{
struct V_162 * V_163 = (struct V_162 * ) V_161 ;
if ( ! V_163 )
return V_64 ;
F_121 ( ( V_164 , L_37 , V_161 ) ) ;
F_131 ( ! F_132 ( & V_163 -> V_165 ) ) ;
F_38 ( V_163 ) ;
V_163 = NULL ;
return V_65 ;
}
T_11 F_133 ( T_19 V_161 , T_1 V_166 , V_124 V_167 )
{
T_11 V_148 = V_65 ;
struct V_162 * V_163 = (struct V_162 * ) V_161 ;
long V_168 ;
int V_151 = 0 ;
if ( ! V_163 || ( V_166 < 1 ) )
return V_64 ;
if ( V_166 > 1 )
return V_169 ;
F_121 ( ( V_164 , L_38 ,
V_161 , V_166 , V_167 ) ) ;
if ( V_167 == V_170 )
V_168 = V_171 ;
else
V_168 = F_82 ( V_167 ) ;
V_151 = F_134 ( V_163 , V_168 ) ;
if ( V_151 )
V_148 = V_172 ;
if ( F_135 ( V_148 ) ) {
F_121 ( ( V_164 ,
L_39 ,
V_161 , V_166 , V_167 ,
F_136 ( V_148 ) ) ) ;
} else {
F_121 ( ( V_164 ,
L_40 , V_161 ,
V_166 , V_167 ) ) ;
}
return V_148 ;
}
T_11 F_137 ( T_19 V_161 , T_1 V_166 )
{
struct V_162 * V_163 = (struct V_162 * ) V_161 ;
if ( ! V_163 || ( V_166 < 1 ) )
return V_64 ;
if ( V_166 > 1 )
return V_169 ;
F_121 ( ( V_164 , L_41 , V_161 ,
V_166 ) ) ;
F_138 ( V_163 ) ;
return V_65 ;
}
T_1 F_139 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_173 ;
F_140 ( V_28 , sizeof( V_174 ) ) ;
V_173 = strlen ( V_28 ) - 1 ;
V_28 [ V_173 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_141 ( T_1 V_141 , void * V_175 )
{
switch ( V_141 ) {
case V_176 :
F_11 (KERN_ERR PREFIX L_42 ) ;
break;
case V_177 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_142 ( char * V_178 )
{
char * V_86 = V_70 ;
int V_179 = V_180 - 1 ;
if ( ! V_178 || ! * V_178 )
return 0 ;
for (; V_179 -- && V_178 && * V_178 ; V_178 ++ ) {
if ( isalnum ( * V_178 ) || * V_178 == ' ' || * V_178 == ':' )
* V_86 ++ = * V_178 ;
else if ( * V_178 == '\'' || * V_178 == '"' )
continue;
else
break;
}
* V_86 = 0 ;
return 1 ;
}
void T_3 F_143 ( char * V_178 )
{
struct V_181 * V_182 ;
bool V_183 = true ;
int V_184 ;
if ( ! V_185 )
return;
if ( V_178 == NULL || * V_178 == '\0' ) {
F_11 (KERN_INFO PREFIX L_43 ) ;
V_185 = FALSE ;
return;
}
if ( * V_178 == '!' ) {
V_178 ++ ;
V_183 = false ;
}
for ( V_184 = 0 ; V_184 < V_186 ; V_184 ++ ) {
V_182 = & V_187 [ V_184 ] ;
if ( ! strcmp ( V_182 -> string , V_178 ) ) {
V_182 -> V_183 = V_183 ;
break;
} else if ( V_182 -> string [ 0 ] == '\0' ) {
V_182 -> V_183 = V_183 ;
strncpy ( V_182 -> string , V_178 , V_188 ) ;
break;
}
}
}
static void T_3 F_144 ( unsigned int V_183 )
{
if ( V_189 . V_183 != V_183 )
V_189 . V_183 = V_183 ;
if ( V_189 . V_183 )
F_143 ( L_1 ) ;
else
F_143 ( L_44 ) ;
return;
}
static void T_3 F_145 ( unsigned int V_183 )
{
V_189 . V_190 = 1 ;
V_189 . V_191 = 0 ;
F_144 ( V_183 ) ;
return;
}
void T_3 F_146 ( int V_183 , const struct V_192 * V_193 )
{
F_11 (KERN_NOTICE PREFIX L_45 , d->ident) ;
if ( V_183 == - 1 )
return;
V_189 . V_191 = 1 ;
F_144 ( V_183 ) ;
return;
}
static void T_3 F_147 ( void )
{
struct V_181 * V_182 ;
char * V_178 ;
int V_184 ;
T_11 V_148 ;
for ( V_184 = 0 ; V_184 < V_186 ; V_184 ++ ) {
V_182 = & V_187 [ V_184 ] ;
V_178 = V_182 -> string ;
if ( * V_178 == '\0' )
break;
if ( V_182 -> V_183 ) {
V_148 = F_148 ( V_178 ) ;
if ( F_149 ( V_148 ) )
F_11 (KERN_INFO PREFIX L_46 , str) ;
} else {
V_148 = F_150 ( V_178 ) ;
if ( F_149 ( V_148 ) )
F_11 (KERN_INFO PREFIX L_47 , str) ;
}
}
}
static int T_3 F_151 ( char * V_178 )
{
if ( V_178 && ! strcmp ( L_1 , V_178 ) )
F_145 ( 1 ) ;
else if ( V_178 && ! strcmp ( L_44 , V_178 ) )
F_145 ( 0 ) ;
else
F_143 ( V_178 ) ;
return 1 ;
}
static int T_3 F_152 ( char * V_178 )
{
F_11 (KERN_INFO PREFIX L_48 ) ;
V_194 = TRUE ;
return 1 ;
}
static int T_3 F_153 ( char * V_178 )
{
if ( V_178 == NULL || * V_178 == '\0' )
return 0 ;
if ( ! strcmp ( L_49 , V_178 ) )
V_195 = V_196 ;
else if ( ! strcmp ( L_50 , V_178 ) )
V_195 = V_197 ;
else if ( ! strcmp ( L_51 , V_178 ) )
V_195 = V_198 ;
return 1 ;
}
int F_154 ( const struct V_199 * V_200 )
{
T_20 V_9 ;
T_7 V_5 ;
T_12 V_201 = 0 ;
int V_202 = 0 ;
if ( V_195 == V_198 )
return 0 ;
if ( ! ( V_200 -> V_203 & V_204 ) && ! ( V_200 -> V_203 & V_205 ) )
return 0 ;
if ( V_200 -> V_203 & V_204 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = V_200 -> V_72 - V_200 -> V_206 + 1 ;
if ( V_195 != V_198 )
V_201 = 1 ;
V_202 = F_155 ( V_9 , V_200 -> V_206 , V_5 , V_201 ) ;
if ( V_202 ) {
if ( V_195 != V_198 ) {
if ( V_195 == V_197 )
F_11 ( V_207 L_52
L_53
L_54 ) ;
F_11 ( V_208 L_55
L_56
L_57 ) ;
}
if ( V_195 == V_196 )
return - V_209 ;
}
return 0 ;
}
int F_156 ( T_21 V_206 , T_21 V_210 ,
const char * V_69 )
{
struct V_199 V_200 = {
. V_206 = V_206 ,
. V_72 = V_206 + V_210 - 1 ,
. V_69 = V_69 ,
. V_203 = V_204 ,
} ;
return F_154 ( & V_200 ) ;
}
int F_157 ( void )
{
return V_195 == V_196 ;
}
void F_158 ( T_22 V_161 )
{
F_159 ( V_161 ) ;
}
T_23 F_160 ( T_22 V_211 )
{
T_23 V_203 ;
F_161 ( V_211 , V_203 ) ;
return V_203 ;
}
void F_162 ( T_22 V_211 , T_23 V_203 )
{
F_163 ( V_211 , V_203 ) ;
}
T_11
F_164 ( char * V_69 , V_124 V_41 , V_124 V_212 , T_24 * * V_213 )
{
* V_213 = F_165 ( V_69 , V_41 , 0 , 0 , NULL ) ;
if ( * V_213 == NULL )
return V_137 ;
else
return V_65 ;
}
T_11 F_166 ( T_24 * V_213 )
{
F_167 ( V_213 ) ;
return ( V_65 ) ;
}
T_11 F_168 ( T_24 * V_213 )
{
F_169 ( V_213 ) ;
return ( V_65 ) ;
}
T_11 F_170 ( T_24 * V_213 , void * V_214 )
{
F_171 ( V_213 , V_214 ) ;
return ( V_65 ) ;
}
T_11 T_3 F_172 ( void )
{
F_49 ( & V_12 . V_13 ) ;
F_49 ( & V_12 . V_15 ) ;
F_49 ( & V_12 . V_24 ) ;
F_49 ( & V_12 . V_26 ) ;
return V_65 ;
}
T_11 T_3 F_173 ( void )
{
V_158 = F_174 ( L_58 , 0 , 1 ) ;
V_157 = F_174 ( L_59 , 0 , 1 ) ;
V_155 = F_174 ( L_60 , 0 , 1 ) ;
F_131 ( ! V_158 ) ;
F_131 ( ! V_157 ) ;
F_131 ( ! V_155 ) ;
F_175 ( F_1 ) ;
F_147 () ;
return V_65 ;
}
T_11 F_176 ( void )
{
if ( F_73 ) {
F_78 ( V_12 . V_112 ,
F_73 ) ;
}
F_50 ( & V_12 . V_26 ) ;
F_50 ( & V_12 . V_24 ) ;
F_50 ( & V_12 . V_15 ) ;
F_50 ( & V_12 . V_13 ) ;
F_177 ( V_158 ) ;
F_177 ( V_157 ) ;
F_177 ( V_155 ) ;
return V_65 ;
}
T_11 F_178 ( T_12 V_215 , T_1 V_216 ,
T_1 V_217 )
{
int V_218 = 0 ;
if ( V_219 )
V_218 = V_219 ( V_215 ,
V_216 , V_217 ) ;
if ( V_218 < 0 )
return V_137 ;
else if ( V_218 > 0 )
return V_220 ;
return V_65 ;
}
void F_179 ( int (* F_180)( T_12 V_215 ,
T_1 V_221 , T_1 V_222 ) )
{
V_219 = F_180 ;
}
