static int F_1 ( char * V_1 , const struct V_2 * V_3 )
{
return sprintf ( V_1 , L_1 , F_2 ( ( V_4 * ) V_3 -> V_5 ) ) ;
}
static int F_3 ( const char * V_6 , const struct V_2 * V_3 )
{
F_4 ( ( V_4 * ) V_3 -> V_5 , 0 ) ;
return 0 ;
}
static inline bool F_5 ( const char * V_7 )
{
return ( strncmp ( V_8 , V_7 , strlen ( V_7 ) ) == 0 ) ;
}
static void F_6 ( void )
{
if ( F_7 ( V_9 ) ) {
F_8 ( V_10 ,
1UL << V_11 ) ;
V_12 = V_13 ;
V_14 = V_15 ;
V_16 = 1UL << V_17 ;
F_9 ( L_2 , V_18 ) ;
} else {
V_12 = V_19 ;
V_14 = V_20 ;
V_16 = 1UL << V_21 ;
F_9 ( L_2 , V_22 ) ;
}
}
static inline int F_10 ( struct V_23 * V_24 )
{
V_24 -> V_25 = F_7 ( V_12 ) ;
F_11 ( & V_24 -> V_26 ) ;
return ! ! ( V_24 -> V_25 & V_16 ) ;
}
static inline void F_12 ( void )
{
F_8 ( V_14 , V_16 ) ;
}
static int F_13 ( int V_27 , struct V_23 * V_24 )
{
int V_28 = F_14 ( & V_24 -> V_29 , 1 , 1 ) ;
if ( V_28 ) {
F_15 ( & V_24 -> V_30 , V_27 ) ;
if ( F_14 ( & V_31 , 1 , 1 ) )
F_15 ( & V_32 , V_27 ) ;
F_11 ( & V_24 -> V_33 ) ;
}
return V_28 ;
}
static int F_16 ( struct V_23 * V_24 )
{
int V_27 = F_17 () ;
int V_34 = 0 ;
F_18 ( & V_35 ) ;
V_36 . V_37 ++ ;
do {
V_34 = F_19 ( & V_24 -> V_29 ) ;
if ( V_34 )
break;
if ( F_20 ( & V_24 -> V_38 ) ) {
if ( F_10 ( V_24 ) ) {
F_13 ( V_27 , V_24 ) ;
V_34 = 1 ;
break;
}
F_21 ( & V_24 -> V_38 ) ;
} else {
F_22 () ;
F_23 ( V_39 ) ;
V_34 = F_19 ( & V_24 -> V_29 ) ;
if ( V_34 )
break;
}
if ( ! V_34 ) {
V_34 = F_19 ( & V_31 ) ;
if ( V_34 )
F_13 ( V_27 , V_24 ) ;
}
} while ( 0 );
if ( ! V_34 )
F_18 ( & V_40 ) ;
return V_34 ;
}
static inline void F_24 ( int V_27 )
{
struct V_23 * V_24 = V_41 ;
if ( V_27 == F_19 ( & V_24 -> V_30 ) ) {
F_15 ( & V_24 -> V_30 , - 1 ) ;
F_15 ( & V_24 -> V_29 , 0 ) ;
F_12 () ;
F_21 ( & V_24 -> V_38 ) ;
}
}
static void F_25 ( char * V_42 )
{
static char V_43 [ 1024 ] ;
int V_44 = sizeof( V_43 ) ;
int V_45 = F_26 ( V_46 ) ;
int V_47 = F_27 ( V_43 , V_44 , V_46 ) ;
if ( V_47 >= V_44 - 1 )
strcpy ( & V_43 [ V_44 - 6 ] , L_3 ) ;
F_28 ( V_42 , V_45 , V_43 ) ;
}
static void F_29 ( void )
{
int V_27 ;
F_30 (cpu, uv_nmi_cpu_mask)
F_15 ( & F_31 ( V_27 ) . V_48 , 1 ) ;
V_49 -> V_50 ( V_46 , V_51 ) ;
}
static void F_32 ( void )
{
int V_27 ;
F_30 (cpu, uv_nmi_cpu_mask) {
F_15 ( & F_31 ( V_27 ) . V_48 , 0 ) ;
F_15 ( & F_31 ( V_27 ) . V_52 , V_53 ) ;
F_33 ( V_27 , V_46 ) ;
}
}
static int F_34 ( int V_28 )
{
int V_54 , V_55 , V_56 , V_47 = F_35 () ;
int V_57 = 0 , V_58 = 0 ;
if ( V_28 ) {
F_36 ( V_46 , V_59 ) ;
V_56 = 0 ;
} else {
V_56 = V_47 - F_26 ( V_46 ) ;
}
F_23 ( V_60 ) ;
for ( V_54 = 0 ; V_54 < V_61 ; V_54 ++ ) {
int V_62 = V_63 ;
F_30 (j, uv_nmi_cpu_mask) {
if ( F_19 ( & F_31 ( V_55 ) . V_52 ) ) {
F_33 ( V_55 , V_46 ) ;
if ( ++ V_56 >= V_47 )
break;
}
}
if ( V_56 >= V_47 ) {
V_56 = V_47 ;
break;
}
if ( V_57 != V_56 ) {
V_57 = V_56 ;
V_58 = 0 ;
} else if ( ++ V_58 > V_64 )
break;
if ( V_58 && ( V_47 - V_56 ) == 1 &&
F_37 ( 0 , V_46 ) )
V_62 *= 100 ;
F_23 ( V_62 ) ;
}
F_15 ( & V_65 , V_56 ) ;
return V_47 - V_56 ;
}
static void F_38 ( int V_66 )
{
F_15 ( & V_36 . V_52 , V_67 ) ;
if ( ! V_66 )
return;
do {
if ( ! F_34 ( 1 ) )
break;
F_25 ( V_68
L_4 ) ;
F_29 () ;
if ( ! F_34 ( 0 ) )
break;
F_25 ( V_68
L_5 ) ;
} while ( 0 );
F_39 ( L_6 ,
F_19 ( & V_65 ) , F_35 () ) ;
}
static void F_40 ( void )
{
F_28 ( V_69
L_7 ,
L_8 , L_9 , L_10 , L_11 ) ;
}
static void F_41 ( int V_27 , struct V_70 * V_71 )
{
F_28 ( V_69 L_12 ,
V_27 , V_72 -> V_73 , V_72 -> V_74 ) ;
F_42 ( V_71 -> V_75 ) ;
}
static void F_43 ( int V_27 , struct V_70 * V_71 )
{
const char * V_76 = L_13 ;
if ( F_5 ( L_14 ) ) {
if ( V_27 == 0 )
F_40 () ;
if ( V_72 -> V_73 != 0 )
F_41 ( V_27 , V_71 ) ;
} else if ( F_5 ( L_15 ) ) {
F_28 ( V_69
L_16 , V_76 , V_27 ) ;
F_44 ( V_71 ) ;
}
F_15 ( & V_36 . V_52 , V_77 ) ;
}
static void F_45 ( int V_27 )
{
int V_78 = V_79 ;
if ( F_19 ( & F_31 ( V_27 ) . V_52 ) != V_67 )
return;
F_15 ( & F_31 ( V_27 ) . V_52 , V_80 ) ;
do {
F_22 () ;
F_23 ( 10 ) ;
if ( F_19 ( & F_31 ( V_27 ) . V_52 )
!= V_80 )
return;
} while ( -- V_78 > 0 );
F_46 ( L_17 , V_27 ) ;
F_15 ( & F_31 ( V_27 ) . V_52 , V_77 ) ;
}
static void F_47 ( int V_66 )
{
F_48 ( & V_65 ) ;
if ( V_66 ) {
while ( F_19 ( & V_65 ) > 0 )
F_22 () ;
F_15 ( & V_81 , V_82 ) ;
} else {
while ( F_19 ( & V_81 ) )
F_22 () ;
}
}
static void F_49 ( int V_27 , struct V_70 * V_71 , int V_66 )
{
if ( V_66 ) {
int V_83 ;
int V_84 = 0 ;
int V_85 = V_86 ;
F_39 ( L_18 ,
F_5 ( L_14 ) ? L_19 : L_20 ,
F_19 ( & V_65 ) , V_27 ) ;
V_86 = V_87 ;
F_15 ( & V_81 , V_88 ) ;
F_50 (tcpu) {
if ( F_37 ( V_83 , V_46 ) )
V_84 ++ ;
else if ( V_83 == V_27 )
F_43 ( V_83 , V_71 ) ;
else
F_45 ( V_83 ) ;
}
if ( V_84 )
F_28 ( V_69 L_21 ,
V_84 ) ;
V_86 = V_85 ;
F_39 ( L_22 ) ;
} else {
while ( ! F_19 ( & V_81 ) )
F_22 () ;
while ( F_19 ( & V_36 . V_52 ) != V_80 )
F_22 () ;
F_43 ( V_27 , V_71 ) ;
}
F_47 ( V_66 ) ;
}
static void F_51 ( void )
{
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
}
static void F_56 ( int V_27 , int V_66 , struct V_70 * V_71 )
{
if ( V_66 ) {
F_57 ( L_23 , V_27 ) ;
F_58 ( V_71 ) ;
F_57 ( L_24 ) ;
if ( ! V_89 ) {
F_59 ( L_25 ) ;
F_15 ( & V_90 , 1 ) ;
F_47 ( 1 ) ;
return;
}
F_59 ( L_26 ) ;
}
while ( F_19 ( & V_90 ) == 0 )
F_60 ( 10 ) ;
F_47 ( 0 ) ;
}
static inline void F_56 ( int V_27 , int V_66 , struct V_70 * V_71 )
{
if ( V_66 )
F_61 ( L_27 ) ;
}
static inline int F_62 ( void )
{
return V_91 ;
}
static inline int F_62 ( void )
{
if ( F_5 ( L_28 ) )
return 0 ;
F_61 ( L_29 ) ;
return - 1 ;
}
static void F_63 ( int V_27 , struct V_70 * V_71 , int V_66 )
{
if ( V_66 ) {
int V_92 = F_62 () ;
int V_93 ;
if ( V_92 < 0 )
return;
V_93 = F_64 ( V_27 , V_94 , V_71 , V_92 ,
& V_81 ) ;
if ( V_93 ) {
F_39 ( L_30 ) ;
F_15 ( & V_81 , V_88 ) ;
}
} else {
int V_95 ;
do {
F_22 () ;
V_95 = F_19 ( & V_81 ) ;
} while ( ! V_95 );
if ( V_95 == V_96 )
F_65 ( V_27 , V_71 ) ;
}
F_47 ( V_66 ) ;
}
static inline void F_63 ( int V_27 , struct V_70 * V_71 , int V_66 )
{
F_61 ( L_31 ) ;
}
int F_66 ( unsigned int V_92 , struct V_70 * V_71 )
{
struct V_23 * V_24 = V_41 ;
int V_27 = F_17 () ;
int V_66 = 0 ;
unsigned long V_97 ;
F_67 ( V_97 ) ;
if ( ! F_19 ( & V_36 . V_48 ) && ! F_16 ( V_24 ) ) {
F_68 ( V_97 ) ;
return V_98 ;
}
V_66 = ( F_19 ( & V_32 ) == V_27 ) ;
if ( F_5 ( L_32 ) )
F_56 ( V_27 , V_66 , V_71 ) ;
F_38 ( V_66 ) ;
if ( F_5 ( L_14 ) || F_5 ( L_15 ) )
F_49 ( V_27 , V_71 , V_66 ) ;
else if ( F_5 ( L_33 ) || F_5 ( L_28 ) )
F_63 ( V_27 , V_71 , V_66 ) ;
F_15 ( & V_36 . V_52 , V_53 ) ;
F_24 ( V_27 ) ;
if ( V_66 ) {
if ( F_26 ( V_46 ) )
F_32 () ;
F_15 ( & V_65 , - 1 ) ;
F_15 ( & V_32 , - 1 ) ;
F_15 ( & V_31 , 0 ) ;
}
F_51 () ;
F_68 ( V_97 ) ;
return V_99 ;
}
static int F_69 ( unsigned int V_92 , struct V_70 * V_71 )
{
int V_93 ;
V_36 . V_37 ++ ;
if ( ! F_19 ( & V_36 . V_48 ) ) {
F_18 ( & V_100 ) ;
return V_98 ;
}
V_36 . V_101 ++ ;
F_18 ( & V_102 ) ;
V_93 = F_66 ( V_92 , V_71 ) ;
F_15 ( & V_36 . V_48 , 0 ) ;
return V_93 ;
}
static void F_70 ( void )
{
if ( F_71 ( V_103 , F_66 , 0 , L_34 ) )
F_72 ( L_35 ) ;
if ( F_71 ( V_104 , F_69 , 0 , L_36 ) )
F_72 ( L_37 ) ;
}
void F_73 ( void )
{
unsigned int V_105 ;
V_105 = F_74 ( V_106 ) | V_51 ;
V_105 &= ~ V_107 ;
F_75 ( V_106 , V_105 ) ;
}
void F_76 ( void )
{
int V_108 = sizeof( void * ) * ( 1 << V_109 ) ;
int V_27 , V_110 ;
F_6 () ;
V_111 = F_77 ( V_108 , V_112 ) ;
F_9 ( L_38 , V_111 , V_108 ) ;
F_78 ( ! V_111 ) ;
V_108 = sizeof( struct V_23 ) ;
F_79 (cpu) {
V_110 = F_80 ( V_27 ) ;
if ( V_111 [ V_110 ] == NULL ) {
V_111 [ V_110 ] = F_81 ( V_108 ,
V_112 , V_110 ) ;
F_78 ( ! V_111 [ V_110 ] ) ;
F_82 ( & ( V_111 [ V_110 ] -> V_38 ) ) ;
F_15 ( & V_111 [ V_110 ] -> V_30 , - 1 ) ;
}
F_83 ( V_27 ) = V_111 [ V_110 ] ;
}
F_78 ( ! F_84 ( & V_46 , V_112 ) ) ;
F_70 () ;
}
