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
if ( V_33 ) {
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
F_16 ( & V_38 ) ;
return V_38 ;
}
}
static struct V_39 *
F_17 ( T_6 V_40 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_42 -> V_40 <= V_40 &&
V_40 + V_41 <= V_42 -> V_40 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 *
F_19 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 )
return V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
return NULL ;
}
void T_8 * F_20 ( T_6 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
void T_8 * V_43 = NULL ;
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_43 = V_42 -> V_43 + ( V_40 - V_42 -> V_40 ) ;
V_42 -> V_45 ++ ;
}
F_22 ( & V_44 ) ;
return V_43 ;
}
static struct V_39 *
F_23 ( void T_8 * V_43 , T_7 V_41 )
{
struct V_39 * V_42 ;
F_18 (map, &acpi_ioremaps, list)
if ( V_42 -> V_43 <= V_43 &&
V_43 + V_41 <= V_42 -> V_43 + V_42 -> V_41 )
return V_42 ;
return NULL ;
}
static void T_8 * F_24 ( T_6 V_46 , unsigned long V_47 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_25 ( V_48 ) ) {
if ( V_47 > V_50 )
return NULL ;
return ( void T_8 V_51 * ) F_26 ( F_27 ( V_48 ) ) ;
} else
return F_28 ( V_46 , V_47 ) ;
}
static void F_29 ( T_6 V_46 , void T_8 * V_52 )
{
unsigned long V_48 ;
V_48 = V_46 >> V_49 ;
if ( F_30 ( V_48 ) )
F_31 ( F_27 ( V_48 ) ) ;
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
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_45 ++ ;
goto V_55;
}
V_42 = F_35 ( sizeof( * V_42 ) , V_56 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
return NULL ;
}
V_46 = F_36 ( V_40 , V_50 ) ;
V_47 = F_37 ( V_40 + V_41 , V_50 ) - V_46 ;
V_43 = F_24 ( V_46 , V_47 ) ;
if ( ! V_43 ) {
F_22 ( & V_44 ) ;
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
F_22 ( & V_44 ) ;
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
F_29 ( V_42 -> V_40 , V_42 -> V_43 ) ;
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
F_21 ( & V_44 ) ;
V_42 = F_23 ( V_43 , V_41 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
F_47 ( true , V_59 L_19 , V_60 , V_43 ) ;
return;
}
F_41 ( V_42 ) ;
F_22 ( & V_44 ) ;
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
F_21 ( & V_44 ) ;
V_42 = F_17 ( V_7 , V_4 -> V_61 / 8 ) ;
if ( ! V_42 ) {
F_22 ( & V_44 ) ;
return;
}
F_41 ( V_42 ) ;
F_22 ( & V_44 ) ;
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
T_11
F_54 ( struct V_71 * V_72 ,
struct V_71 * * V_73 )
{
if ( ! V_72 || ! V_73 )
return V_64 ;
* V_73 = NULL ;
#ifdef F_55
if ( strncmp ( V_72 -> V_74 , L_22 , 4 ) == 0 )
* V_73 = (struct V_71 * ) V_75 ;
#endif
if ( * V_73 != NULL ) {
F_11 (KERN_WARNING PREFIX L_23
L_24 ,
existing_table->signature,
existing_table->oem_table_id) ;
F_56 ( V_76 ) ;
}
return V_65 ;
}
static T_12 F_57 ( int V_77 , void * V_78 )
{
T_1 V_79 ;
V_79 = (* F_58) ( V_80 ) ;
if ( V_79 ) {
V_81 ++ ;
return V_82 ;
} else {
V_83 ++ ;
return V_84 ;
}
}
T_11
F_59 ( T_1 V_85 , T_13 V_86 ,
void * V_87 )
{
unsigned int V_77 ;
F_60 () ;
if ( V_85 != V_12 . V_88 )
return V_64 ;
if ( F_58 )
return V_89 ;
if ( F_61 ( V_85 , & V_77 ) < 0 ) {
F_11 (KERN_ERR PREFIX L_25 ,
gsi) ;
return V_65 ;
}
F_58 = V_86 ;
V_80 = V_87 ;
if ( F_62 ( V_77 , F_57 , V_90 , L_26 , F_57 ) ) {
F_11 (KERN_ERR PREFIX L_27 , irq) ;
F_58 = NULL ;
return V_91 ;
}
return V_65 ;
}
T_11 F_63 ( T_1 V_77 , T_13 V_86 )
{
if ( V_77 != V_12 . V_88 )
return V_64 ;
F_64 ( V_77 , F_57 ) ;
F_58 = NULL ;
return V_65 ;
}
void F_65 ( T_4 V_92 )
{
F_66 ( F_67 ( V_92 ) ) ;
}
void F_68 ( T_1 V_93 )
{
while ( V_93 ) {
T_1 V_94 = 1000 ;
if ( V_94 > V_93 )
V_94 = V_93 ;
F_69 ( V_94 ) ;
F_70 () ;
V_93 -= V_94 ;
}
}
T_4 F_71 ( void )
{
static T_4 V_95 ;
#ifdef F_72
#endif
#ifdef F_73
#endif
if ( ! V_95 )
F_11 (KERN_ERR PREFIX L_28 ) ;
return ++ V_95 ;
}
T_11 F_74 ( T_14 V_96 , T_1 * V_97 , T_1 V_98 )
{
T_1 V_99 ;
if ( ! V_97 )
V_97 = & V_99 ;
* V_97 = 0 ;
if ( V_98 <= 8 ) {
* ( V_100 * ) V_97 = F_75 ( V_96 ) ;
} else if ( V_98 <= 16 ) {
* ( V_101 * ) V_97 = F_76 ( V_96 ) ;
} else if ( V_98 <= 32 ) {
* ( T_1 * ) V_97 = F_77 ( V_96 ) ;
} else {
F_78 () ;
}
return V_65 ;
}
T_11 F_79 ( T_14 V_96 , T_1 V_97 , T_1 V_98 )
{
if ( V_98 <= 8 ) {
F_80 ( V_97 , V_96 ) ;
} else if ( V_98 <= 16 ) {
F_81 ( V_97 , V_96 ) ;
} else if ( V_98 <= 32 ) {
F_82 ( V_97 , V_96 ) ;
} else {
F_78 () ;
}
return V_65 ;
}
T_11
F_83 ( T_6 V_102 , T_1 * V_97 , T_1 V_98 )
{
void T_8 * V_103 ;
unsigned int V_41 = V_98 / 8 ;
bool V_104 = false ;
T_1 V_99 ;
F_84 () ;
V_103 = F_19 ( V_102 , V_41 ) ;
if ( ! V_103 ) {
F_85 () ;
V_103 = F_28 ( V_102 , V_41 ) ;
if ( ! V_103 )
return V_105 ;
V_104 = true ;
}
if ( ! V_97 )
V_97 = & V_99 ;
switch ( V_98 ) {
case 8 :
* ( V_100 * ) V_97 = F_86 ( V_103 ) ;
break;
case 16 :
* ( V_101 * ) V_97 = F_87 ( V_103 ) ;
break;
case 32 :
* ( T_1 * ) V_97 = F_88 ( V_103 ) ;
break;
default:
F_78 () ;
}
if ( V_104 )
F_32 ( V_103 ) ;
else
F_85 () ;
return V_65 ;
}
static inline T_4 F_89 ( const volatile void T_8 * V_7 )
{
return F_90 ( V_7 ) ;
}
static inline T_4 F_89 ( const volatile void T_8 * V_7 )
{
T_4 V_106 , V_107 ;
V_106 = F_88 ( V_7 ) ;
V_107 = F_88 ( V_7 + 4 ) ;
return V_106 | ( V_107 << 32 ) ;
}
T_11
F_91 ( T_6 V_102 , T_4 * V_97 , T_1 V_98 )
{
void T_8 * V_103 ;
unsigned int V_41 = V_98 / 8 ;
bool V_104 = false ;
T_4 V_99 ;
F_84 () ;
V_103 = F_19 ( V_102 , V_41 ) ;
if ( ! V_103 ) {
F_85 () ;
V_103 = F_28 ( V_102 , V_41 ) ;
if ( ! V_103 )
return V_105 ;
V_104 = true ;
}
if ( ! V_97 )
V_97 = & V_99 ;
switch ( V_98 ) {
case 8 :
* ( V_100 * ) V_97 = F_86 ( V_103 ) ;
break;
case 16 :
* ( V_101 * ) V_97 = F_87 ( V_103 ) ;
break;
case 32 :
* ( T_1 * ) V_97 = F_88 ( V_103 ) ;
break;
case 64 :
* ( T_4 * ) V_97 = F_89 ( V_103 ) ;
break;
default:
F_78 () ;
}
if ( V_104 )
F_32 ( V_103 ) ;
else
F_85 () ;
return V_65 ;
}
T_11
F_92 ( T_6 V_102 , T_1 V_97 , T_1 V_98 )
{
void T_8 * V_103 ;
unsigned int V_41 = V_98 / 8 ;
bool V_104 = false ;
F_84 () ;
V_103 = F_19 ( V_102 , V_41 ) ;
if ( ! V_103 ) {
F_85 () ;
V_103 = F_28 ( V_102 , V_41 ) ;
if ( ! V_103 )
return V_105 ;
V_104 = true ;
}
switch ( V_98 ) {
case 8 :
F_93 ( V_97 , V_103 ) ;
break;
case 16 :
F_94 ( V_97 , V_103 ) ;
break;
case 32 :
F_95 ( V_97 , V_103 ) ;
break;
default:
F_78 () ;
}
if ( V_104 )
F_32 ( V_103 ) ;
else
F_85 () ;
return V_65 ;
}
static inline void F_96 ( T_4 V_108 , volatile void T_8 * V_7 )
{
F_97 ( V_108 , V_7 ) ;
}
static inline void F_96 ( T_4 V_108 , volatile void T_8 * V_7 )
{
F_95 ( V_108 , V_7 ) ;
F_95 ( V_108 >> 32 , V_7 + 4 ) ;
}
T_11
F_98 ( T_6 V_102 , T_4 V_97 , T_1 V_98 )
{
void T_8 * V_103 ;
unsigned int V_41 = V_98 / 8 ;
bool V_104 = false ;
F_84 () ;
V_103 = F_19 ( V_102 , V_41 ) ;
if ( ! V_103 ) {
F_85 () ;
V_103 = F_28 ( V_102 , V_41 ) ;
if ( ! V_103 )
return V_105 ;
V_104 = true ;
}
switch ( V_98 ) {
case 8 :
F_93 ( V_97 , V_103 ) ;
break;
case 16 :
F_94 ( V_97 , V_103 ) ;
break;
case 32 :
F_95 ( V_97 , V_103 ) ;
break;
case 64 :
F_96 ( V_97 , V_103 ) ;
break;
default:
F_78 () ;
}
if ( V_104 )
F_32 ( V_103 ) ;
else
F_85 () ;
return V_65 ;
}
T_11
F_99 ( struct V_109 * V_110 , T_1 V_111 ,
T_4 * V_97 , T_1 V_98 )
{
int V_112 , V_41 ;
T_1 V_113 ;
if ( ! V_97 )
return V_64 ;
switch ( V_98 ) {
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
return V_114 ;
}
V_112 = F_100 ( V_110 -> V_115 , V_110 -> V_116 ,
F_101 ( V_110 -> V_117 , V_110 -> V_118 ) ,
V_111 , V_41 , & V_113 ) ;
* V_97 = V_113 ;
return ( V_112 ? V_114 : V_65 ) ;
}
T_11
F_102 ( struct V_109 * V_110 , T_1 V_111 ,
T_4 V_97 , T_1 V_98 )
{
int V_112 , V_41 ;
switch ( V_98 ) {
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
return V_114 ;
}
V_112 = F_103 ( V_110 -> V_115 , V_110 -> V_116 ,
F_101 ( V_110 -> V_117 , V_110 -> V_118 ) ,
V_111 , V_41 , V_97 ) ;
return ( V_112 ? V_114 : V_65 ) ;
}
static void F_104 ( struct V_119 * V_120 )
{
struct V_121 * V_122 = F_105 ( V_120 , struct V_121 , V_120 ) ;
if ( V_122 -> V_123 )
F_106 ( NULL ) ;
V_122 -> V_118 ( V_122 -> V_87 ) ;
F_38 ( V_122 ) ;
}
static T_11 F_107 ( T_15 type ,
T_16 V_118 , void * V_87 , int V_124 )
{
T_11 V_125 = V_65 ;
struct V_121 * V_122 ;
struct V_126 * V_127 ;
int V_128 ;
F_108 ( ( V_129 ,
L_29 ,
V_118 , V_87 ) ) ;
V_122 = F_109 ( sizeof( struct V_121 ) , V_130 ) ;
if ( ! V_122 )
return V_131 ;
V_122 -> V_118 = V_118 ;
V_122 -> V_87 = V_87 ;
V_127 = V_124 ? V_132 :
( type == V_133 ? V_134 : V_135 ) ;
V_122 -> V_123 = V_124 ? 1 : 0 ;
if ( V_127 == V_132 )
F_110 ( & V_122 -> V_120 , F_104 ) ;
else if ( V_127 == V_134 )
F_110 ( & V_122 -> V_120 , F_104 ) ;
else
F_110 ( & V_122 -> V_120 , F_104 ) ;
V_128 = F_111 ( 0 , V_127 , & V_122 -> V_120 ) ;
if ( ! V_128 ) {
F_11 (KERN_ERR PREFIX
L_30 ) ;
V_125 = V_114 ;
F_38 ( V_122 ) ;
}
return V_125 ;
}
T_11 F_112 ( T_15 type ,
T_16 V_118 , void * V_87 )
{
return F_107 ( type , V_118 , V_87 , 0 ) ;
}
T_11 F_113 ( T_16 V_118 ,
void * V_87 )
{
return F_107 ( 0 , V_118 , V_87 , 1 ) ;
}
void F_106 ( void * V_87 )
{
F_114 ( V_135 ) ;
F_114 ( V_134 ) ;
}
T_11
F_115 ( T_1 V_136 , T_1 V_137 , T_17 * V_138 )
{
struct V_139 * V_140 = NULL ;
V_140 = F_116 ( sizeof( struct V_139 ) ) ;
if ( ! V_140 )
return V_131 ;
memset ( V_140 , 0 , sizeof( struct V_139 ) ) ;
F_117 ( V_140 , V_137 ) ;
* V_138 = ( T_17 * ) V_140 ;
F_108 ( ( V_141 , L_31 ,
* V_138 , V_137 ) ) ;
return V_65 ;
}
T_11 F_118 ( T_17 V_138 )
{
struct V_139 * V_140 = (struct V_139 * ) V_138 ;
if ( ! V_140 )
return V_64 ;
F_108 ( ( V_141 , L_32 , V_138 ) ) ;
F_119 ( ! F_120 ( & V_140 -> V_142 ) ) ;
F_38 ( V_140 ) ;
V_140 = NULL ;
return V_65 ;
}
T_11 F_121 ( T_17 V_138 , T_1 V_143 , V_101 V_144 )
{
T_11 V_125 = V_65 ;
struct V_139 * V_140 = (struct V_139 * ) V_138 ;
long V_145 ;
int V_128 = 0 ;
if ( ! V_140 || ( V_143 < 1 ) )
return V_64 ;
if ( V_143 > 1 )
return V_146 ;
F_108 ( ( V_141 , L_33 ,
V_138 , V_143 , V_144 ) ) ;
if ( V_144 == V_147 )
V_145 = V_148 ;
else
V_145 = F_67 ( V_144 ) ;
V_128 = F_122 ( V_140 , V_145 ) ;
if ( V_128 )
V_125 = V_149 ;
if ( F_123 ( V_125 ) ) {
F_108 ( ( V_141 ,
L_34 ,
V_138 , V_143 , V_144 ,
F_124 ( V_125 ) ) ) ;
} else {
F_108 ( ( V_141 ,
L_35 , V_138 ,
V_143 , V_144 ) ) ;
}
return V_125 ;
}
T_11 F_125 ( T_17 V_138 , T_1 V_143 )
{
struct V_139 * V_140 = (struct V_139 * ) V_138 ;
if ( ! V_140 || ( V_143 < 1 ) )
return V_64 ;
if ( V_143 > 1 )
return V_146 ;
F_108 ( ( V_141 , L_36 , V_138 ,
V_143 ) ) ;
F_126 ( V_140 ) ;
return V_65 ;
}
T_1 F_127 ( char * V_28 )
{
#ifdef F_9
if ( V_29 ) {
T_1 V_150 ;
F_128 ( V_28 , sizeof( V_151 ) ) ;
V_150 = strlen ( V_28 ) - 1 ;
V_28 [ V_150 ] = '\0' ;
}
#endif
return 0 ;
}
T_11 F_129 ( T_1 V_118 , void * V_152 )
{
switch ( V_118 ) {
case V_153 :
F_11 (KERN_ERR PREFIX L_37 ) ;
break;
case V_154 :
break;
default:
break;
}
return V_65 ;
}
static int T_3 F_130 ( char * V_155 )
{
char * V_156 = V_70 ;
int V_157 = V_158 - 1 ;
if ( ! V_155 || ! * V_155 )
return 0 ;
for (; V_157 -- && V_155 && * V_155 ; V_155 ++ ) {
if ( isalnum ( * V_155 ) || * V_155 == ' ' || * V_155 == ':' )
* V_156 ++ = * V_155 ;
else if ( * V_155 == '\'' || * V_155 == '"' )
continue;
else
break;
}
* V_156 = 0 ;
return 1 ;
}
void T_3 F_131 ( char * V_155 )
{
struct V_159 * V_160 ;
bool V_161 = true ;
int V_162 ;
if ( ! V_163 )
return;
if ( V_155 == NULL || * V_155 == '\0' ) {
F_11 (KERN_INFO PREFIX L_38 ) ;
V_163 = FALSE ;
return;
}
if ( * V_155 == '!' ) {
V_155 ++ ;
V_161 = false ;
}
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ ) {
V_160 = & V_165 [ V_162 ] ;
if ( ! strcmp ( V_160 -> string , V_155 ) ) {
V_160 -> V_161 = V_161 ;
break;
} else if ( V_160 -> string [ 0 ] == '\0' ) {
V_160 -> V_161 = V_161 ;
strncpy ( V_160 -> string , V_155 , V_166 ) ;
break;
}
}
}
static void T_3 F_132 ( unsigned int V_161 )
{
if ( V_167 . V_161 != V_161 )
V_167 . V_161 = V_161 ;
if ( V_167 . V_161 )
F_131 ( L_1 ) ;
else
F_131 ( L_39 ) ;
return;
}
static void T_3 F_133 ( unsigned int V_161 )
{
V_167 . V_168 = 1 ;
V_167 . V_169 = 0 ;
F_132 ( V_161 ) ;
return;
}
void T_3 F_134 ( int V_161 , const struct V_170 * V_171 )
{
F_11 (KERN_NOTICE PREFIX L_40 , d->ident) ;
if ( V_161 == - 1 )
return;
V_167 . V_169 = 1 ;
F_132 ( V_161 ) ;
return;
}
static void T_3 F_135 ( void )
{
struct V_159 * V_160 ;
char * V_155 ;
int V_162 ;
T_11 V_125 ;
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ ) {
V_160 = & V_165 [ V_162 ] ;
V_155 = V_160 -> string ;
if ( * V_155 == '\0' )
break;
if ( V_160 -> V_161 ) {
V_125 = F_136 ( V_155 ) ;
if ( F_137 ( V_125 ) )
F_11 (KERN_INFO PREFIX L_41 , str) ;
} else {
V_125 = F_138 ( V_155 ) ;
if ( F_137 ( V_125 ) )
F_11 (KERN_INFO PREFIX L_42 , str) ;
}
}
}
static int T_3 F_139 ( char * V_155 )
{
if ( V_155 && ! strcmp ( L_1 , V_155 ) )
F_133 ( 1 ) ;
else if ( V_155 && ! strcmp ( L_39 , V_155 ) )
F_133 ( 0 ) ;
else
F_131 ( V_155 ) ;
return 1 ;
}
static int T_3 F_140 ( char * V_155 )
{
F_11 (KERN_INFO PREFIX L_43 ) ;
V_172 = TRUE ;
return 1 ;
}
static int T_3 F_141 ( char * V_155 )
{
if ( V_155 == NULL || * V_155 == '\0' )
return 0 ;
if ( ! strcmp ( L_44 , V_155 ) )
V_173 = V_174 ;
else if ( ! strcmp ( L_45 , V_155 ) )
V_173 = V_175 ;
else if ( ! strcmp ( L_46 , V_155 ) )
V_173 = V_176 ;
return 1 ;
}
int F_142 ( const struct V_177 * V_178 )
{
T_18 V_9 ;
T_7 V_5 ;
V_100 V_179 = 0 ;
int V_180 = 0 ;
if ( V_173 == V_176 )
return 0 ;
if ( ! ( V_178 -> V_181 & V_182 ) && ! ( V_178 -> V_181 & V_183 ) )
return 0 ;
if ( V_178 -> V_181 & V_182 )
V_9 = V_10 ;
else
V_9 = V_11 ;
V_5 = V_178 -> V_184 - V_178 -> V_185 + 1 ;
if ( V_173 != V_176 )
V_179 = 1 ;
V_180 = F_143 ( V_9 , V_178 -> V_185 , V_5 , V_179 ) ;
if ( V_180 ) {
if ( V_173 != V_176 ) {
if ( V_173 == V_175 )
F_11 ( V_186 L_47
L_48
L_49 ) ;
F_11 ( V_187 L_50
L_51
L_52 ) ;
}
if ( V_173 == V_174 )
return - V_188 ;
}
return 0 ;
}
int F_144 ( T_19 V_185 , T_19 V_189 ,
const char * V_69 )
{
struct V_177 V_178 = {
. V_185 = V_185 ,
. V_184 = V_185 + V_189 - 1 ,
. V_69 = V_69 ,
. V_181 = V_182 ,
} ;
return F_142 ( & V_178 ) ;
}
int F_145 ( void )
{
return V_173 == V_174 ;
}
void F_146 ( T_20 V_138 )
{
F_147 ( V_138 ) ;
}
T_21 F_148 ( T_20 V_190 )
{
T_21 V_181 ;
F_149 ( V_190 , V_181 ) ;
return V_181 ;
}
void F_150 ( T_20 V_190 , T_21 V_181 )
{
F_151 ( V_190 , V_181 ) ;
}
T_11
F_152 ( char * V_69 , V_101 V_41 , V_101 V_191 , T_22 * * V_192 )
{
* V_192 = F_153 ( V_69 , V_41 , 0 , 0 , NULL ) ;
if ( * V_192 == NULL )
return V_114 ;
else
return V_65 ;
}
T_11 F_154 ( T_22 * V_192 )
{
F_155 ( V_192 ) ;
return ( V_65 ) ;
}
T_11 F_156 ( T_22 * V_192 )
{
F_157 ( V_192 ) ;
return ( V_65 ) ;
}
T_11 F_158 ( T_22 * V_192 , void * V_193 )
{
F_159 ( V_192 , V_193 ) ;
return ( V_65 ) ;
}
T_11 T_3 F_160 ( void )
{
F_49 ( & V_12 . V_13 ) ;
F_49 ( & V_12 . V_15 ) ;
F_49 ( & V_12 . V_24 ) ;
F_49 ( & V_12 . V_26 ) ;
return V_65 ;
}
T_11 T_3 F_161 ( void )
{
V_135 = F_162 ( L_53 , 0 , 1 ) ;
V_134 = F_162 ( L_54 , 0 , 1 ) ;
V_132 = F_162 ( L_55 , 0 , 1 ) ;
F_119 ( ! V_135 ) ;
F_119 ( ! V_134 ) ;
F_119 ( ! V_132 ) ;
F_163 ( F_1 ) ;
F_135 () ;
return V_65 ;
}
T_11 F_164 ( void )
{
if ( F_58 ) {
F_63 ( V_12 . V_88 ,
F_58 ) ;
}
F_50 ( & V_12 . V_26 ) ;
F_50 ( & V_12 . V_24 ) ;
F_50 ( & V_12 . V_15 ) ;
F_50 ( & V_12 . V_13 ) ;
F_165 ( V_135 ) ;
F_165 ( V_134 ) ;
F_165 ( V_132 ) ;
return V_65 ;
}
