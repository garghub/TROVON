static int F_1 ( char * V_1 , const struct V_2 * V_3 )
{
return sprintf ( V_1 , L_1 , F_2 ( ( V_4 * ) V_3 -> V_5 ) ) ;
}
static int F_3 ( const char * V_6 , const struct V_2 * V_3 )
{
F_4 ( ( V_4 * ) V_3 -> V_5 , 0 ) ;
return 0 ;
}
static int F_5 ( char * V_1 , const struct V_2 * V_3 )
{
return sprintf ( V_1 , L_2 , V_7 ) ;
}
static int F_6 ( const char * V_6 , const struct V_2 * V_3 )
{
int V_8 ;
int V_9 = F_7 ( V_10 ) ;
char V_5 [ V_11 ] , * V_12 ;
strncpy ( V_5 , V_6 , V_11 - 1 ) ;
V_5 [ V_11 - 1 ] = '\0' ;
V_12 = strchr ( V_5 , '\n' ) ;
if ( V_12 )
* V_12 = '\0' ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
if ( ! strcmp ( V_5 , V_10 [ V_8 ] . V_13 ) )
break;
if ( V_8 < V_9 ) {
strcpy ( V_7 , V_5 ) ;
F_8 ( L_3 , V_7 ) ;
return 0 ;
}
F_9 ( L_4 , V_5 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_9 ( L_5 ,
V_10 [ V_8 ] . V_13 , V_10 [ V_8 ] . V_14 ) ;
return - V_15 ;
}
static inline bool F_10 ( const char * V_13 )
{
return ( strncmp ( V_7 , V_13 , strlen ( V_13 ) ) == 0 ) ;
}
static void F_11 ( void )
{
if ( F_12 ( V_16 ) ) {
F_13 ( V_17 ,
1UL << V_18 ) ;
V_19 = V_20 ;
V_21 = V_22 ;
V_23 = 1UL << V_24 ;
F_8 ( L_6 , V_25 ) ;
} else {
V_19 = V_26 ;
V_21 = V_27 ;
V_23 = 1UL << V_28 ;
F_8 ( L_6 , V_29 ) ;
}
}
static inline int F_14 ( struct V_30 * V_31 )
{
V_31 -> V_32 = F_12 ( V_19 ) ;
F_15 ( & V_31 -> V_33 ) ;
return ! ! ( V_31 -> V_32 & V_23 ) ;
}
static inline void F_16 ( void )
{
F_13 ( V_21 , V_23 ) ;
}
static inline void F_17 ( void )
{
F_18 ( 0x8f , V_34 ) ;
F_19 ( V_35 ) ;
F_18 ( 0x0f , V_34 ) ;
F_19 ( V_35 ) ;
}
static void F_20 ( int V_36 , int V_37 , int V_38 )
{
int * V_39 = F_21 ( V_36 ) ;
int V_40 = F_22 ( V_39 ) ;
if ( V_37 ) {
int V_41 = ( V_40 & ~ V_37 ) | V_38 ;
F_23 ( L_7 ,
V_39 , V_40 , ~ V_37 , V_38 , V_41 ) ;
F_24 ( V_41 , V_39 ) ;
} else if ( V_40 & V_38 ) {
F_23 ( L_8 , V_39 , V_38 ) ;
F_24 ( V_38 , V_39 ) ;
}
( void ) F_22 ( V_39 ) ;
}
static void F_25 ( void )
{
V_42 = V_43 ;
F_20 (
V_44 , V_45 ,
V_42 ? V_45 : 0 ) ;
F_23 ( L_9 ,
V_42 ? L_10 : L_11 ) ;
}
static void F_26 ( void )
{
int V_8 , V_46 ;
V_46 = * F_21 ( V_47 ) ;
if ( V_46 != 0 ) {
F_8 ( L_12 ) ;
return;
}
F_23 ( L_13 ) ;
for ( V_8 = 0 ; V_8 < F_7 ( V_48 ) ; V_8 ++ ) {
F_20 ( V_48 [ V_8 ] . V_36 ,
V_48 [ V_8 ] . V_37 ,
V_48 [ V_8 ] . V_38 ) ;
}
}
static int F_27 ( struct V_30 * V_31 )
{
int * V_49 = F_21 ( V_50 ) ;
int V_51 = * V_49 ;
V_31 -> V_32 = V_51 ;
F_15 ( & V_31 -> V_33 ) ;
if ( ! ( V_51 & V_52 ) )
return 0 ;
* V_49 = V_52 ;
( void ) * V_49 ;
return 1 ;
}
static int F_28 ( struct V_30 * V_31 )
{
if ( V_31 -> V_53 )
return F_14 ( V_31 ) ;
if ( V_31 -> V_54 )
return F_27 ( V_31 ) ;
return - 1 ;
}
static int F_29 ( int V_55 , struct V_30 * V_31 )
{
int V_56 = F_30 ( & V_31 -> V_57 , 1 , 1 ) ;
if ( V_56 ) {
F_31 ( & V_31 -> V_58 , V_55 ) ;
if ( F_30 ( & V_59 , 1 , 1 ) )
F_31 ( & V_60 , V_55 ) ;
F_15 ( & V_31 -> V_61 ) ;
}
return V_56 ;
}
static int F_32 ( struct V_30 * V_31 )
{
int V_55 = F_33 () ;
int V_62 = 0 ;
int V_63 = 0 ;
F_34 ( & V_64 ) ;
F_35 ( V_65 . V_66 ) ;
do {
V_62 = F_36 ( & V_31 -> V_57 ) ;
if ( V_62 )
break;
if ( F_37 ( & V_31 -> V_67 ) ) {
V_63 = F_28 ( V_31 ) ;
if ( V_63 > 0 ) {
F_29 ( V_55 , V_31 ) ;
V_62 = 1 ;
break;
}
else if ( V_63 < 0 )
goto V_68;
F_38 ( & V_31 -> V_67 ) ;
} else {
V_68: F_39 () ;
F_40 ( V_69 ) ;
V_62 = F_36 ( & V_31 -> V_57 ) ;
if ( V_62 )
break;
}
if ( ! V_62 ) {
V_62 = F_36 ( & V_59 ) ;
if ( V_62 )
F_29 ( V_55 , V_31 ) ;
}
if ( V_63 < 0 )
F_38 ( & V_31 -> V_67 ) ;
} while ( 0 );
if ( ! V_62 )
F_34 ( & V_70 ) ;
return V_62 ;
}
static inline void F_41 ( int V_55 )
{
struct V_30 * V_31 = V_71 ;
if ( V_55 == F_36 ( & V_31 -> V_58 ) ) {
F_31 ( & V_31 -> V_58 , - 1 ) ;
F_31 ( & V_31 -> V_57 , 0 ) ;
if ( V_31 -> V_53 )
F_16 () ;
else
F_17 () ;
F_38 ( & V_31 -> V_67 ) ;
}
}
static void F_42 ( void )
{
int V_55 ;
F_43 (cpu, uv_nmi_cpu_mask)
F_44 ( V_55 ) . V_72 = 1 ;
V_73 -> V_74 ( V_75 , V_76 ) ;
}
static void F_45 ( void )
{
int V_55 ;
F_43 (cpu, uv_nmi_cpu_mask) {
F_44 ( V_55 ) . V_72 = 0 ;
F_44 ( V_55 ) . V_77 = V_78 ;
F_46 ( V_55 , V_75 ) ;
}
}
static int F_47 ( int V_56 )
{
int V_8 , V_79 , V_80 , V_9 = F_48 () ;
int V_81 = 0 , V_82 = 0 ;
int V_55 = F_33 () ;
if ( V_56 ) {
F_49 ( V_75 , V_83 ) ;
V_80 = 0 ;
} else {
V_80 = V_9 - F_50 ( V_75 ) ;
}
if ( V_56 && V_42 ) {
F_46 ( V_55 , V_75 ) ;
return V_9 - V_80 - 1 ;
}
F_40 ( V_84 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
int V_86 = V_87 ;
F_43 (j, uv_nmi_cpu_mask) {
if ( F_44 ( V_79 ) . V_77 ) {
F_46 ( V_79 , V_75 ) ;
if ( ++ V_80 >= V_9 )
break;
}
}
if ( V_80 >= V_9 ) {
V_80 = V_9 ;
break;
}
if ( V_81 != V_80 ) {
V_81 = V_80 ;
V_82 = 0 ;
} else if ( ++ V_82 > V_88 )
break;
if ( V_82 && ( V_9 - V_80 ) == 1 &&
F_51 ( 0 , V_75 ) )
V_86 *= 100 ;
F_40 ( V_86 ) ;
}
F_31 ( & V_89 , V_80 ) ;
return V_9 - V_80 ;
}
static void F_52 ( int V_90 )
{
F_53 ( V_65 . V_77 , V_91 ) ;
if ( ! V_90 )
return;
do {
if ( ! F_47 ( 1 ) )
break;
F_54 ( L_14 ,
F_50 ( V_75 ) ,
F_55 ( V_75 ) ) ;
F_42 () ;
if ( ! F_47 ( 0 ) )
break;
F_54 ( L_15 ,
F_50 ( V_75 ) ,
F_55 ( V_75 ) ) ;
} while ( 0 );
F_54 ( L_16 ,
F_36 ( & V_89 ) , F_48 () ) ;
}
static void F_56 ( void )
{
F_8 ( L_17 ,
L_18 , L_19 , L_20 , L_21 ) ;
}
static void F_57 ( int V_55 , struct V_92 * V_93 )
{
F_8 ( L_22 ,
V_55 , V_94 -> V_95 , V_94 -> V_96 , ( void * ) V_93 -> V_97 ) ;
}
static void F_58 ( int V_55 , struct V_92 * V_93 )
{
const char * V_98 = L_23 ;
if ( V_55 == 0 )
F_56 () ;
if ( V_94 -> V_95 != 0 || ! F_10 ( L_24 ) )
F_57 ( V_55 , V_93 ) ;
if ( F_10 ( L_25 ) ) {
F_8 ( L_26 , V_98 , V_55 ) ;
F_59 ( V_93 ) ;
}
F_53 ( V_65 . V_77 , V_99 ) ;
}
static void F_60 ( int V_55 )
{
int V_100 = V_101 ;
if ( F_44 ( V_55 ) . V_77 != V_91 )
return;
F_44 ( V_55 ) . V_77 = V_102 ;
do {
F_39 () ;
F_40 ( 10 ) ;
if ( F_44 ( V_55 ) . V_77
!= V_102 )
return;
} while ( -- V_100 > 0 );
F_61 ( L_27 , V_55 ) ;
F_44 ( V_55 ) . V_77 = V_99 ;
}
static void F_62 ( int V_90 )
{
F_63 ( & V_89 ) ;
if ( V_90 ) {
while ( F_36 ( & V_89 ) > 0 )
F_39 () ;
F_31 ( & V_103 , V_104 ) ;
} else {
while ( F_36 ( & V_103 ) )
F_39 () ;
}
}
static void F_64 ( int V_55 , struct V_92 * V_93 , int V_90 )
{
if ( V_90 ) {
int V_105 = F_36 ( & V_89 ) ;
int V_106 = F_48 () - V_105 ;
F_54 ( L_28 , V_106 ) ;
F_31 ( & V_103 , V_107 ) ;
} else {
while ( ! F_36 ( & V_103 ) )
F_39 () ;
}
F_62 ( V_90 ) ;
}
static void F_65 ( int V_55 , struct V_92 * V_93 , int V_90 )
{
if ( V_90 ) {
int V_108 ;
int V_109 = 0 ;
int V_110 = V_111 ;
F_54 ( L_29 ,
F_10 ( L_24 ) ? L_30 : L_31 ,
F_36 ( & V_89 ) , V_55 ) ;
V_111 = V_112 ;
F_31 ( & V_103 , V_107 ) ;
F_66 (tcpu) {
if ( F_51 ( V_108 , V_75 ) )
V_109 ++ ;
else if ( V_108 == V_55 )
F_58 ( V_108 , V_93 ) ;
else
F_60 ( V_108 ) ;
}
if ( V_109 )
F_54 ( L_32 , V_109 ) ;
V_111 = V_110 ;
F_54 ( L_33 ) ;
} else {
while ( ! F_36 ( & V_103 ) )
F_39 () ;
while ( F_67 ( V_65 . V_77 ) != V_102 )
F_39 () ;
F_58 ( V_55 , V_93 ) ;
}
F_62 ( V_90 ) ;
}
static void F_68 ( void )
{
F_69 () ;
F_70 () ;
F_71 () ;
F_72 () ;
}
static void F_73 ( int V_55 , int V_90 , struct V_92 * V_93 )
{
if ( V_90 ) {
F_74 ( L_34 , V_55 ) ;
F_75 ( V_93 ) ;
F_74 ( L_35 ) ;
F_31 ( & V_113 , 1 ) ;
if ( ! V_114 ) {
F_76 ( L_36 ) ;
return;
}
F_76 ( L_37 ) ;
}
while ( F_36 ( & V_113 ) == 0 )
F_77 ( 10 ) ;
}
static inline void F_73 ( int V_55 , int V_90 , struct V_92 * V_93 )
{
if ( V_90 )
F_9 ( L_38 ) ;
F_31 ( & V_113 , 1 ) ;
}
static inline int F_78 ( void )
{
return V_115 ;
}
static inline int F_78 ( void )
{
if ( F_10 ( L_39 ) )
return 0 ;
F_9 ( L_40 ) ;
return - 1 ;
}
static void F_79 ( int V_55 , struct V_92 * V_93 , int V_90 )
{
if ( V_90 ) {
int V_116 = F_78 () ;
int V_117 ;
if ( V_116 < 0 )
return;
V_117 = F_80 ( V_55 , V_118 , V_93 , V_116 ,
& V_103 ) ;
if ( V_117 ) {
F_54 ( L_41 ) ;
F_31 ( & V_103 , V_107 ) ;
}
} else {
int V_119 ;
do {
F_39 () ;
V_119 = F_36 ( & V_103 ) ;
} while ( ! V_119 );
if ( V_119 == V_120 )
F_81 ( V_55 , V_93 ) ;
}
F_62 ( V_90 ) ;
}
static inline void F_79 ( int V_55 , struct V_92 * V_93 , int V_90 )
{
F_9 ( L_42 ) ;
}
int F_82 ( unsigned int V_116 , struct V_92 * V_93 )
{
struct V_30 * V_31 = V_71 ;
int V_55 = F_33 () ;
int V_90 = 0 ;
unsigned long V_121 ;
F_83 ( V_121 ) ;
if ( ! F_67 ( V_65 . V_72 ) && ! F_32 ( V_31 ) ) {
F_84 ( V_121 ) ;
return V_122 ;
}
V_90 = ( F_36 ( & V_60 ) == V_55 ) ;
if ( F_10 ( L_43 ) ) {
F_73 ( V_55 , V_90 , V_93 ) ;
if ( V_90 )
strncpy ( V_7 , L_25 , strlen ( V_7 ) ) ;
}
F_52 ( V_90 ) ;
if ( F_10 ( L_44 ) ) {
F_64 ( V_55 , V_93 , V_90 ) ;
} else if ( F_10 ( L_24 ) || F_10 ( L_25 ) ) {
F_65 ( V_55 , V_93 , V_90 ) ;
} else if ( F_10 ( L_45 ) || F_10 ( L_39 ) ) {
F_79 ( V_55 , V_93 , V_90 ) ;
} else {
if ( V_90 )
F_54 ( L_46 , V_7 ) ;
F_62 ( V_90 ) ;
}
F_53 ( V_65 . V_77 , V_78 ) ;
F_41 ( V_55 ) ;
if ( V_90 ) {
if ( F_50 ( V_75 ) )
F_45 () ;
F_31 ( & V_89 , - 1 ) ;
F_31 ( & V_60 , - 1 ) ;
F_31 ( & V_59 , 0 ) ;
F_31 ( & V_113 , 0 ) ;
F_31 ( & V_103 , V_104 ) ;
}
F_68 () ;
F_84 ( V_121 ) ;
return V_123 ;
}
static int F_85 ( unsigned int V_116 , struct V_92 * V_93 )
{
int V_117 ;
F_35 ( V_65 . V_66 ) ;
if ( ! F_67 ( V_65 . V_72 ) ) {
F_34 ( & V_124 ) ;
return V_122 ;
}
F_35 ( V_65 . V_125 ) ;
F_34 ( & V_126 ) ;
V_117 = F_82 ( V_116 , V_93 ) ;
F_53 ( V_65 . V_72 , 0 ) ;
return V_117 ;
}
static void F_86 ( void )
{
if ( F_87 ( V_127 , F_82 , 0 , L_47 ) )
F_88 ( L_48 ) ;
if ( F_87 ( V_128 , F_85 , 0 , L_49 ) )
F_88 ( L_50 ) ;
}
void F_89 ( void )
{
unsigned int V_129 ;
V_129 = F_90 ( V_130 ) | V_76 ;
V_129 &= ~ V_131 ;
F_91 ( V_130 , V_129 ) ;
}
void T_1 F_92 ( bool V_132 )
{
int V_133 = sizeof( void * ) * ( 1 << V_134 ) ;
int V_55 ;
V_135 = F_93 ( V_133 , V_136 ) ;
F_23 ( L_51 , V_135 , V_133 ) ;
F_94 ( ! V_135 ) ;
V_133 = sizeof( struct V_30 ) ;
F_95 (cpu) {
int V_137 = F_96 ( V_55 ) ;
if ( V_135 [ V_137 ] == NULL ) {
V_135 [ V_137 ] = F_97 ( V_133 ,
V_136 , V_137 ) ;
F_94 ( ! V_135 [ V_137 ] ) ;
F_98 ( & ( V_135 [ V_137 ] -> V_67 ) ) ;
F_31 ( & V_135 [ V_137 ] -> V_58 , - 1 ) ;
V_135 [ V_137 ] -> V_53 = V_132 ;
V_135 [ V_137 ] -> V_54 = ( V_137 == 0 ) ;
}
F_99 ( V_55 ) = V_135 [ V_137 ] ;
}
F_94 ( ! F_100 ( & V_75 , V_136 ) ) ;
}
void T_1 F_101 ( void )
{
F_11 () ;
F_92 ( true ) ;
F_86 () ;
F_8 ( L_52 ) ;
}
void T_1 F_102 ( void )
{
F_92 ( false ) ;
V_138 = F_103 ( V_139 ) ;
F_23 ( L_53 ,
V_138 , V_139 ) ;
if ( V_140 )
F_26 () ;
F_20 ( V_141 ,
V_52 , V_52 ) ;
F_25 () ;
F_17 () ;
F_86 () ;
F_8 ( L_54 ) ;
}
