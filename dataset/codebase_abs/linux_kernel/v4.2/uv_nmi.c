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
F_41 ( V_64
L_6 ,
L_7 , L_8 , L_9 , L_10 ) ;
}
static void F_42 ( int V_27 , struct V_65 * V_66 )
{
F_41 ( V_64 L_11 ,
V_27 , V_67 -> V_68 , V_67 -> V_69 ) ;
F_43 ( V_66 -> V_70 ) ;
}
static void F_44 ( int V_27 , struct V_65 * V_66 )
{
const char * V_71 = L_12 ;
if ( F_5 ( L_13 ) ) {
if ( V_27 == 0 )
F_40 () ;
if ( V_67 -> V_68 != 0 )
F_42 ( V_27 , V_66 ) ;
} else if ( F_5 ( L_14 ) ) {
F_41 ( V_64
L_15 , V_71 , V_27 ) ;
F_45 ( V_66 ) ;
}
F_37 ( V_36 . V_47 , V_72 ) ;
}
static void F_46 ( int V_27 )
{
int V_73 = V_74 ;
if ( F_28 ( V_27 ) . V_47 != V_63 )
return;
F_28 ( V_27 ) . V_47 = V_75 ;
do {
F_23 () ;
F_24 ( 10 ) ;
if ( F_28 ( V_27 ) . V_47
!= V_75 )
return;
} while ( -- V_73 > 0 );
F_47 ( L_16 , V_27 ) ;
F_28 ( V_27 ) . V_47 = V_72 ;
}
static void F_48 ( int V_62 )
{
F_49 ( & V_61 ) ;
if ( V_62 ) {
while ( F_20 ( & V_61 ) > 0 )
F_23 () ;
F_15 ( & V_76 , V_77 ) ;
} else {
while ( F_20 ( & V_76 ) )
F_23 () ;
}
}
static void F_50 ( int V_27 , struct V_65 * V_66 , int V_62 )
{
if ( V_62 ) {
int V_78 ;
int V_79 = 0 ;
int V_80 = V_81 ;
F_38 ( L_17 ,
F_5 ( L_13 ) ? L_18 : L_19 ,
F_20 ( & V_61 ) , V_27 ) ;
V_81 = V_82 ;
F_15 ( & V_76 , V_83 ) ;
F_51 (tcpu) {
if ( F_35 ( V_78 , V_45 ) )
V_79 ++ ;
else if ( V_78 == V_27 )
F_44 ( V_78 , V_66 ) ;
else
F_46 ( V_78 ) ;
}
if ( V_79 )
F_41 ( V_64 L_20 ,
V_79 ) ;
V_81 = V_80 ;
F_38 ( L_21 ) ;
} else {
while ( ! F_20 ( & V_76 ) )
F_23 () ;
while ( F_52 ( V_36 . V_47 ) != V_75 )
F_23 () ;
F_44 ( V_27 , V_66 ) ;
}
F_48 ( V_62 ) ;
}
static void F_53 ( void )
{
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
}
static void F_58 ( int V_27 , int V_62 , struct V_65 * V_66 )
{
if ( V_62 ) {
F_59 ( L_22 , V_27 ) ;
F_60 ( V_66 ) ;
F_59 ( L_23 ) ;
if ( ! V_84 ) {
F_61 ( L_24 ) ;
F_15 ( & V_85 , 1 ) ;
F_48 ( 1 ) ;
return;
}
F_61 ( L_25 ) ;
}
while ( F_20 ( & V_85 ) == 0 )
F_62 ( 10 ) ;
F_48 ( 0 ) ;
}
static inline void F_58 ( int V_27 , int V_62 , struct V_65 * V_66 )
{
if ( V_62 )
F_63 ( L_26 ) ;
}
static inline int F_64 ( void )
{
return V_86 ;
}
static inline int F_64 ( void )
{
if ( F_5 ( L_27 ) )
return 0 ;
F_63 ( L_28 ) ;
return - 1 ;
}
static void F_65 ( int V_27 , struct V_65 * V_66 , int V_62 )
{
if ( V_62 ) {
int V_87 = F_64 () ;
int V_88 ;
if ( V_87 < 0 )
return;
V_88 = F_66 ( V_27 , V_89 , V_66 , V_87 ,
& V_76 ) ;
if ( V_88 ) {
F_38 ( L_29 ) ;
F_15 ( & V_76 , V_83 ) ;
}
} else {
int V_90 ;
do {
F_23 () ;
V_90 = F_20 ( & V_76 ) ;
} while ( ! V_90 );
if ( V_90 == V_91 )
F_67 ( V_27 , V_66 ) ;
}
F_48 ( V_62 ) ;
}
static inline void F_65 ( int V_27 , struct V_65 * V_66 , int V_62 )
{
F_63 ( L_30 ) ;
}
int F_68 ( unsigned int V_87 , struct V_65 * V_66 )
{
struct V_23 * V_24 = V_41 ;
int V_27 = F_17 () ;
int V_62 = 0 ;
unsigned long V_92 ;
F_69 ( V_92 ) ;
if ( ! F_52 ( V_36 . V_42 ) && ! F_16 ( V_24 ) ) {
F_70 ( V_92 ) ;
return V_93 ;
}
V_62 = ( F_20 ( & V_32 ) == V_27 ) ;
if ( F_5 ( L_31 ) )
F_58 ( V_27 , V_62 , V_66 ) ;
F_36 ( V_62 ) ;
if ( F_5 ( L_13 ) || F_5 ( L_14 ) )
F_50 ( V_27 , V_66 , V_62 ) ;
else if ( F_5 ( L_32 ) || F_5 ( L_27 ) )
F_65 ( V_27 , V_66 , V_62 ) ;
F_37 ( V_36 . V_47 , V_48 ) ;
F_25 ( V_27 ) ;
if ( V_62 ) {
if ( F_34 ( V_45 ) )
F_29 () ;
F_15 ( & V_61 , - 1 ) ;
F_15 ( & V_32 , - 1 ) ;
F_15 ( & V_31 , 0 ) ;
}
F_53 () ;
F_70 ( V_92 ) ;
return V_94 ;
}
static int F_71 ( unsigned int V_87 , struct V_65 * V_66 )
{
int V_88 ;
F_19 ( V_36 . V_37 ) ;
if ( ! F_52 ( V_36 . V_42 ) ) {
F_18 ( & V_95 ) ;
return V_93 ;
}
F_19 ( V_36 . V_96 ) ;
F_18 ( & V_97 ) ;
V_88 = F_68 ( V_87 , V_66 ) ;
F_37 ( V_36 . V_42 , 0 ) ;
return V_88 ;
}
static void F_72 ( void )
{
if ( F_73 ( V_98 , F_68 , 0 , L_33 ) )
F_74 ( L_34 ) ;
if ( F_73 ( V_99 , F_71 , 0 , L_35 ) )
F_74 ( L_36 ) ;
}
void F_75 ( void )
{
unsigned int V_100 ;
V_100 = F_76 ( V_101 ) | V_46 ;
V_100 &= ~ V_102 ;
F_77 ( V_101 , V_100 ) ;
}
void F_78 ( void )
{
int V_103 = sizeof( void * ) * ( 1 << V_104 ) ;
int V_27 , V_105 ;
F_6 () ;
V_106 = F_79 ( V_103 , V_107 ) ;
F_9 ( L_37 , V_106 , V_103 ) ;
F_80 ( ! V_106 ) ;
V_103 = sizeof( struct V_23 ) ;
F_81 (cpu) {
V_105 = F_82 ( V_27 ) ;
if ( V_106 [ V_105 ] == NULL ) {
V_106 [ V_105 ] = F_83 ( V_103 ,
V_107 , V_105 ) ;
F_80 ( ! V_106 [ V_105 ] ) ;
F_84 ( & ( V_106 [ V_105 ] -> V_38 ) ) ;
F_15 ( & V_106 [ V_105 ] -> V_30 , - 1 ) ;
}
F_85 ( V_27 ) = V_106 [ V_105 ] ;
}
F_80 ( ! F_86 ( & V_45 , V_107 ) ) ;
F_72 () ;
}
