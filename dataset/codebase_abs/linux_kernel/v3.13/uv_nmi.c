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
static void F_62 ( int V_27 , struct V_70 * V_71 , int V_66 )
{
int V_91 ;
if ( V_66 ) {
V_91 = F_63 ( V_27 , V_92 , V_71 ,
& V_81 ) ;
if ( V_91 ) {
F_39 ( L_28 ) ;
F_15 ( & V_81 , V_88 ) ;
}
} else {
int V_93 ;
do {
F_22 () ;
V_93 = F_19 ( & V_81 ) ;
} while ( ! V_93 );
if ( V_93 == V_94 )
F_64 ( V_27 , V_71 ) ;
}
F_47 ( V_66 ) ;
}
static inline void F_62 ( int V_27 , struct V_70 * V_71 , int V_66 )
{
F_61 ( L_29 ) ;
}
int F_65 ( unsigned int V_95 , struct V_70 * V_71 )
{
struct V_23 * V_24 = V_41 ;
int V_27 = F_17 () ;
int V_66 = 0 ;
unsigned long V_96 ;
F_66 ( V_96 ) ;
if ( ! F_19 ( & V_36 . V_48 ) && ! F_16 ( V_24 ) ) {
F_67 ( V_96 ) ;
return V_97 ;
}
V_66 = ( F_19 ( & V_32 ) == V_27 ) ;
if ( F_5 ( L_30 ) )
F_56 ( V_27 , V_66 , V_71 ) ;
F_38 ( V_66 ) ;
if ( F_5 ( L_14 ) || F_5 ( L_15 ) )
F_49 ( V_27 , V_71 , V_66 ) ;
else if ( F_5 ( L_31 ) )
F_62 ( V_27 , V_71 , V_66 ) ;
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
F_67 ( V_96 ) ;
return V_98 ;
}
int F_68 ( unsigned int V_95 , struct V_70 * V_71 )
{
int V_91 ;
V_36 . V_37 ++ ;
if ( ! F_19 ( & V_36 . V_48 ) ) {
F_18 ( & V_99 ) ;
return V_97 ;
}
V_36 . V_100 ++ ;
F_18 ( & V_101 ) ;
V_91 = F_65 ( V_95 , V_71 ) ;
F_15 ( & V_36 . V_48 , 0 ) ;
return V_91 ;
}
void F_69 ( void )
{
if ( F_70 ( V_102 , F_65 , 0 , L_32 ) )
F_71 ( L_33 ) ;
if ( F_70 ( V_103 , F_68 , 0 , L_34 ) )
F_71 ( L_35 ) ;
}
void F_72 ( void )
{
unsigned int V_104 ;
V_104 = F_73 ( V_105 ) | V_51 ;
V_104 &= ~ V_106 ;
F_74 ( V_105 , V_104 ) ;
}
void F_75 ( void )
{
int V_107 = sizeof( void * ) * ( 1 << V_108 ) ;
int V_27 , V_109 ;
F_6 () ;
V_110 = F_76 ( V_107 , V_111 ) ;
F_9 ( L_36 , V_110 , V_107 ) ;
F_77 ( ! V_110 ) ;
V_107 = sizeof( struct V_23 ) ;
F_78 (cpu) {
V_109 = F_79 ( V_27 ) ;
if ( V_110 [ V_109 ] == NULL ) {
V_110 [ V_109 ] = F_80 ( V_107 ,
V_111 , V_109 ) ;
F_77 ( ! V_110 [ V_109 ] ) ;
F_81 ( & ( V_110 [ V_109 ] -> V_38 ) ) ;
F_15 ( & V_110 [ V_109 ] -> V_30 , - 1 ) ;
}
F_82 ( V_27 ) = V_110 [ V_109 ] ;
}
F_77 ( ! F_83 ( & V_46 , V_111 ) ) ;
}
