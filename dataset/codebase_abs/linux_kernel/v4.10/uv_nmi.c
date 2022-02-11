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
F_19 ( V_36 . V_37 ) ;
do {
V_34 = F_20 ( & V_24 -> V_29 ) ;
if ( V_34 )
break;
if ( F_21 ( & V_24 -> V_38 ) ) {
if ( F_10 ( V_24 ) ) {
F_13 ( V_27 , V_24 ) ;
V_34 = 1 ;
break;
}
F_22 ( & V_24 -> V_38 ) ;
} else {
F_23 () ;
F_24 ( V_39 ) ;
V_34 = F_20 ( & V_24 -> V_29 ) ;
if ( V_34 )
break;
}
if ( ! V_34 ) {
V_34 = F_20 ( & V_31 ) ;
if ( V_34 )
F_13 ( V_27 , V_24 ) ;
}
} while ( 0 );
if ( ! V_34 )
F_18 ( & V_40 ) ;
return V_34 ;
}
static inline void F_25 ( int V_27 )
{
struct V_23 * V_24 = V_41 ;
if ( V_27 == F_20 ( & V_24 -> V_30 ) ) {
F_15 ( & V_24 -> V_30 , - 1 ) ;
F_15 ( & V_24 -> V_29 , 0 ) ;
F_12 () ;
F_22 ( & V_24 -> V_38 ) ;
}
}
static void F_26 ( void )
{
int V_27 ;
F_27 (cpu, uv_nmi_cpu_mask)
F_28 ( V_27 ) . V_42 = 1 ;
V_43 -> V_44 ( V_45 , V_46 ) ;
}
static void F_29 ( void )
{
int V_27 ;
F_27 (cpu, uv_nmi_cpu_mask) {
F_28 ( V_27 ) . V_42 = 0 ;
F_28 ( V_27 ) . V_47 = V_48 ;
F_30 ( V_27 , V_45 ) ;
}
}
static int F_31 ( int V_28 )
{
int V_49 , V_50 , V_51 , V_52 = F_32 () ;
int V_53 = 0 , V_54 = 0 ;
if ( V_28 ) {
F_33 ( V_45 , V_55 ) ;
V_51 = 0 ;
} else {
V_51 = V_52 - F_34 ( V_45 ) ;
}
F_24 ( V_56 ) ;
for ( V_49 = 0 ; V_49 < V_57 ; V_49 ++ ) {
int V_58 = V_59 ;
F_27 (j, uv_nmi_cpu_mask) {
if ( F_28 ( V_50 ) . V_47 ) {
F_30 ( V_50 , V_45 ) ;
if ( ++ V_51 >= V_52 )
break;
}
}
if ( V_51 >= V_52 ) {
V_51 = V_52 ;
break;
}
if ( V_53 != V_51 ) {
V_53 = V_51 ;
V_54 = 0 ;
} else if ( ++ V_54 > V_60 )
break;
if ( V_54 && ( V_52 - V_51 ) == 1 &&
F_35 ( 0 , V_45 ) )
V_58 *= 100 ;
F_24 ( V_58 ) ;
}
F_15 ( & V_61 , V_51 ) ;
return V_52 - V_51 ;
}
static void F_36 ( int V_62 )
{
F_37 ( V_36 . V_47 , V_63 ) ;
if ( ! V_62 )
return;
do {
if ( ! F_31 ( 1 ) )
break;
F_38 ( L_3 ,
F_34 ( V_45 ) ,
F_39 ( V_45 ) ) ;
F_26 () ;
if ( ! F_31 ( 0 ) )
break;
F_38 ( L_4 ,
F_34 ( V_45 ) ,
F_39 ( V_45 ) ) ;
} while ( 0 );
F_38 ( L_5 ,
F_20 ( & V_61 ) , F_32 () ) ;
}
static void F_40 ( void )
{
F_9 ( L_6 ,
L_7 , L_8 , L_9 , L_10 ) ;
}
static void F_41 ( int V_27 , struct V_64 * V_65 )
{
F_9 ( L_11 ,
V_27 , V_66 -> V_67 , V_66 -> V_68 , ( void * ) V_65 -> V_69 ) ;
}
static void F_42 ( int V_27 , struct V_64 * V_65 )
{
const char * V_70 = L_12 ;
if ( V_27 == 0 )
F_40 () ;
if ( V_66 -> V_67 != 0 || ! F_5 ( L_13 ) )
F_41 ( V_27 , V_65 ) ;
if ( F_5 ( L_14 ) ) {
F_9 ( L_15 , V_70 , V_27 ) ;
F_43 ( V_65 ) ;
}
F_37 ( V_36 . V_47 , V_71 ) ;
}
static void F_44 ( int V_27 )
{
int V_72 = V_73 ;
if ( F_28 ( V_27 ) . V_47 != V_63 )
return;
F_28 ( V_27 ) . V_47 = V_74 ;
do {
F_23 () ;
F_24 ( 10 ) ;
if ( F_28 ( V_27 ) . V_47
!= V_74 )
return;
} while ( -- V_72 > 0 );
F_45 ( L_16 , V_27 ) ;
F_28 ( V_27 ) . V_47 = V_71 ;
}
static void F_46 ( int V_62 )
{
F_47 ( & V_61 ) ;
if ( V_62 ) {
while ( F_20 ( & V_61 ) > 0 )
F_23 () ;
F_15 ( & V_75 , V_76 ) ;
} else {
while ( F_20 ( & V_75 ) )
F_23 () ;
}
}
static void F_48 ( int V_27 , struct V_64 * V_65 , int V_62 )
{
if ( V_62 ) {
int V_77 ;
int V_78 = 0 ;
int V_79 = V_80 ;
F_38 ( L_17 ,
F_5 ( L_13 ) ? L_18 : L_19 ,
F_20 ( & V_61 ) , V_27 ) ;
V_80 = V_81 ;
F_15 ( & V_75 , V_82 ) ;
F_49 (tcpu) {
if ( F_35 ( V_77 , V_45 ) )
V_78 ++ ;
else if ( V_77 == V_27 )
F_42 ( V_77 , V_65 ) ;
else
F_44 ( V_77 ) ;
}
if ( V_78 )
F_38 ( L_20 , V_78 ) ;
V_80 = V_79 ;
F_38 ( L_21 ) ;
} else {
while ( ! F_20 ( & V_75 ) )
F_23 () ;
while ( F_50 ( V_36 . V_47 ) != V_74 )
F_23 () ;
F_42 ( V_27 , V_65 ) ;
}
F_46 ( V_62 ) ;
}
static void F_51 ( void )
{
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
}
static void F_56 ( int V_27 , int V_62 , struct V_64 * V_65 )
{
if ( V_62 ) {
F_57 ( L_22 , V_27 ) ;
F_58 ( V_65 ) ;
F_57 ( L_23 ) ;
F_15 ( & V_83 , 1 ) ;
if ( ! V_84 ) {
F_59 ( L_24 ) ;
return;
}
F_59 ( L_25 ) ;
}
while ( F_20 ( & V_83 ) == 0 )
F_60 ( 10 ) ;
}
static inline void F_56 ( int V_27 , int V_62 , struct V_64 * V_65 )
{
if ( V_62 )
F_61 ( L_26 ) ;
F_15 ( & V_83 , 1 ) ;
}
static inline int F_62 ( void )
{
return V_85 ;
}
static inline int F_62 ( void )
{
if ( F_5 ( L_27 ) )
return 0 ;
F_61 ( L_28 ) ;
return - 1 ;
}
static void F_63 ( int V_27 , struct V_64 * V_65 , int V_62 )
{
if ( V_62 ) {
int V_86 = F_62 () ;
int V_87 ;
if ( V_86 < 0 )
return;
V_87 = F_64 ( V_27 , V_88 , V_65 , V_86 ,
& V_75 ) ;
if ( V_87 ) {
F_38 ( L_29 ) ;
F_15 ( & V_75 , V_82 ) ;
}
} else {
int V_89 ;
do {
F_23 () ;
V_89 = F_20 ( & V_75 ) ;
} while ( ! V_89 );
if ( V_89 == V_90 )
F_65 ( V_27 , V_65 ) ;
}
F_46 ( V_62 ) ;
}
static inline void F_63 ( int V_27 , struct V_64 * V_65 , int V_62 )
{
F_61 ( L_30 ) ;
}
int F_66 ( unsigned int V_86 , struct V_64 * V_65 )
{
struct V_23 * V_24 = V_41 ;
int V_27 = F_17 () ;
int V_62 = 0 ;
unsigned long V_91 ;
F_67 ( V_91 ) ;
if ( ! F_50 ( V_36 . V_42 ) && ! F_16 ( V_24 ) ) {
F_68 ( V_91 ) ;
return V_92 ;
}
V_62 = ( F_20 ( & V_32 ) == V_27 ) ;
if ( F_5 ( L_31 ) ) {
F_56 ( V_27 , V_62 , V_65 ) ;
if ( V_62 )
strncpy ( V_8 , L_14 , strlen ( V_8 ) ) ;
}
F_36 ( V_62 ) ;
if ( F_5 ( L_13 ) || F_5 ( L_14 ) )
F_48 ( V_27 , V_65 , V_62 ) ;
else if ( F_5 ( L_32 ) || F_5 ( L_27 ) )
F_63 ( V_27 , V_65 , V_62 ) ;
F_37 ( V_36 . V_47 , V_48 ) ;
F_25 ( V_27 ) ;
if ( V_62 ) {
if ( F_34 ( V_45 ) )
F_29 () ;
F_15 ( & V_61 , - 1 ) ;
F_15 ( & V_32 , - 1 ) ;
F_15 ( & V_31 , 0 ) ;
F_15 ( & V_83 , 0 ) ;
}
F_51 () ;
F_68 ( V_91 ) ;
return V_93 ;
}
static int F_69 ( unsigned int V_86 , struct V_64 * V_65 )
{
int V_87 ;
F_19 ( V_36 . V_37 ) ;
if ( ! F_50 ( V_36 . V_42 ) ) {
F_18 ( & V_94 ) ;
return V_92 ;
}
F_19 ( V_36 . V_95 ) ;
F_18 ( & V_96 ) ;
V_87 = F_66 ( V_86 , V_65 ) ;
F_37 ( V_36 . V_42 , 0 ) ;
return V_87 ;
}
static void F_70 ( void )
{
if ( F_71 ( V_97 , F_66 , 0 , L_33 ) )
F_72 ( L_34 ) ;
if ( F_71 ( V_98 , F_69 , 0 , L_35 ) )
F_72 ( L_36 ) ;
}
void F_73 ( void )
{
unsigned int V_99 ;
V_99 = F_74 ( V_100 ) | V_46 ;
V_99 &= ~ V_101 ;
F_75 ( V_100 , V_99 ) ;
}
void F_76 ( void )
{
int V_102 = sizeof( void * ) * ( 1 << V_103 ) ;
int V_27 , V_104 ;
F_6 () ;
V_105 = F_77 ( V_102 , V_106 ) ;
F_9 ( L_37 , V_105 , V_102 ) ;
F_78 ( ! V_105 ) ;
V_102 = sizeof( struct V_23 ) ;
F_79 (cpu) {
V_104 = F_80 ( V_27 ) ;
if ( V_105 [ V_104 ] == NULL ) {
V_105 [ V_104 ] = F_81 ( V_102 ,
V_106 , V_104 ) ;
F_78 ( ! V_105 [ V_104 ] ) ;
F_82 ( & ( V_105 [ V_104 ] -> V_38 ) ) ;
F_15 ( & V_105 [ V_104 ] -> V_30 , - 1 ) ;
}
F_83 ( V_27 ) = V_105 [ V_104 ] ;
}
F_78 ( ! F_84 ( & V_45 , V_106 ) ) ;
F_70 () ;
}
