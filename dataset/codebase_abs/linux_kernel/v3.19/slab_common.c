static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
unsigned int F_2 ( struct V_3 * V_4 )
{
return V_4 -> V_5 ;
}
static int F_3 ( const char * V_6 , T_2 V_7 )
{
struct V_3 * V_4 = NULL ;
if ( ! V_6 || F_4 () || V_7 < sizeof( void * ) ||
V_7 > V_8 ) {
F_5 ( L_1 , V_6 ) ;
return - V_9 ;
}
F_6 (s, &slab_caches, list) {
char V_10 ;
int V_11 ;
V_11 = F_7 ( V_4 -> V_6 , V_10 ) ;
if ( V_11 ) {
F_5 ( L_2 ,
V_4 -> V_5 ) ;
continue;
}
}
F_8 ( strchr ( V_6 , ' ' ) ) ;
return 0 ;
}
static inline int F_3 ( const char * V_6 , T_2 V_7 )
{
return 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_3 * V_4 , struct V_3 * V_14 )
{
T_2 V_7 ;
if ( ! F_10 () )
return 0 ;
if ( ! V_13 ) {
V_7 = F_11 ( struct V_15 , V_16 ) ;
V_7 += V_17 * sizeof( void * ) ;
} else
V_7 = sizeof( struct V_15 ) ;
V_4 -> V_18 = F_12 ( V_7 , V_19 ) ;
if ( ! V_4 -> V_18 )
return - V_20 ;
if ( V_13 ) {
V_4 -> V_18 -> V_13 = V_13 ;
V_4 -> V_18 -> V_14 = V_14 ;
} else
V_4 -> V_18 -> V_21 = true ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_18 ) ;
}
static int F_15 ( struct V_3 * V_4 , int V_22 )
{
int V_7 ;
struct V_15 * V_23 , * V_24 ;
F_16 ( ! V_21 ( V_4 ) ) ;
V_7 = F_11 ( struct V_15 , V_16 ) ;
V_7 += V_22 * sizeof( void * ) ;
V_23 = F_12 ( V_7 , V_19 ) ;
if ( ! V_23 )
return - V_20 ;
V_24 = V_4 -> V_18 ;
memcpy ( V_23 -> V_16 , V_24 -> V_16 ,
V_17 * sizeof( void * ) ) ;
V_23 -> V_21 = true ;
F_17 ( V_4 -> V_18 , V_23 ) ;
if ( V_24 )
F_18 ( V_24 , V_25 ) ;
return 0 ;
}
int F_19 ( int V_22 )
{
struct V_3 * V_4 ;
int V_26 = 0 ;
F_20 ( & V_27 ) ;
F_6 (s, &slab_caches, list) {
if ( ! V_21 ( V_4 ) )
continue;
V_26 = F_15 ( V_4 , V_22 ) ;
if ( V_26 )
goto V_28;
}
F_21 ( V_22 ) ;
V_28:
F_22 ( & V_27 ) ;
return V_26 ;
}
static inline int F_9 ( struct V_12 * V_13 ,
struct V_3 * V_4 , struct V_3 * V_14 )
{
return 0 ;
}
static inline void F_13 ( struct V_3 * V_4 )
{
}
int F_23 ( struct V_3 * V_4 )
{
if ( V_2 || ( V_4 -> V_29 & V_30 ) )
return 1 ;
if ( ! V_21 ( V_4 ) )
return 1 ;
if ( V_4 -> V_31 )
return 1 ;
if ( V_4 -> V_32 < 0 )
return 1 ;
return 0 ;
}
struct V_3 * F_24 ( T_2 V_7 , T_2 V_33 ,
unsigned long V_29 , const char * V_6 , void (* V_31)( void * ) )
{
struct V_3 * V_4 ;
if ( V_2 || ( V_29 & V_30 ) )
return NULL ;
if ( V_31 )
return NULL ;
V_7 = F_25 ( V_7 , sizeof( void * ) ) ;
V_33 = F_26 ( V_29 , V_33 , V_7 ) ;
V_7 = F_25 ( V_7 , V_33 ) ;
V_29 = F_27 ( V_7 , V_29 , V_6 , NULL ) ;
F_28 (s, &slab_caches, list) {
if ( F_23 ( V_4 ) )
continue;
if ( V_7 > V_4 -> V_7 )
continue;
if ( ( V_29 & V_34 ) != ( V_4 -> V_29 & V_34 ) )
continue;
if ( ( V_4 -> V_7 & ~ ( V_33 - 1 ) ) != V_4 -> V_7 )
continue;
if ( V_4 -> V_7 - V_7 >= sizeof( void * ) )
continue;
if ( F_29 ( V_35 ) && V_33 &&
( V_33 > V_4 -> V_33 || V_4 -> V_33 % V_33 ) )
continue;
return V_4 ;
}
return NULL ;
}
unsigned long F_26 ( unsigned long V_29 ,
unsigned long V_33 , unsigned long V_7 )
{
if ( V_29 & V_36 ) {
unsigned long V_37 = F_30 () ;
while ( V_7 <= V_37 / 2 )
V_37 /= 2 ;
V_33 = F_31 ( V_33 , V_37 ) ;
}
if ( V_33 < V_38 )
V_33 = V_38 ;
return F_25 ( V_33 , sizeof( void * ) ) ;
}
static struct V_3 *
F_32 ( char * V_6 , T_2 V_5 , T_2 V_7 , T_2 V_33 ,
unsigned long V_29 , void (* V_31)( void * ) ,
struct V_12 * V_13 , struct V_3 * V_14 )
{
struct V_3 * V_4 ;
int V_39 ;
V_39 = - V_20 ;
V_4 = F_33 ( V_3 , V_19 ) ;
if ( ! V_4 )
goto V_28;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_31 = V_31 ;
V_39 = F_9 ( V_13 , V_4 , V_14 ) ;
if ( V_39 )
goto V_40;
V_39 = F_34 ( V_4 , V_29 ) ;
if ( V_39 )
goto V_40;
V_4 -> V_32 = 1 ;
F_35 ( & V_4 -> V_41 , & V_42 ) ;
V_28:
if ( V_39 )
return F_36 ( V_39 ) ;
return V_4 ;
V_40:
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
goto V_28;
}
struct V_3 *
F_37 ( const char * V_6 , T_2 V_7 , T_2 V_33 ,
unsigned long V_29 , void (* V_31)( void * ) )
{
struct V_3 * V_4 ;
char * V_43 ;
int V_39 ;
F_38 () ;
F_39 () ;
F_20 ( & V_27 ) ;
V_39 = F_3 ( V_6 , V_7 ) ;
if ( V_39 ) {
V_4 = NULL ;
goto V_44;
}
V_29 &= V_45 ;
V_4 = F_40 ( V_6 , V_7 , V_33 , V_29 , V_31 ) ;
if ( V_4 )
goto V_44;
V_43 = F_41 ( V_6 , V_19 ) ;
if ( ! V_43 ) {
V_39 = - V_20 ;
goto V_44;
}
V_4 = F_32 ( V_43 , V_7 , V_7 ,
F_26 ( V_29 , V_33 , V_7 ) ,
V_29 , V_31 , NULL , NULL ) ;
if ( F_42 ( V_4 ) ) {
V_39 = F_43 ( V_4 ) ;
F_14 ( V_43 ) ;
}
V_44:
F_22 ( & V_27 ) ;
F_44 () ;
F_45 () ;
if ( V_39 ) {
if ( V_29 & V_46 )
F_46 ( L_3 ,
V_6 , V_39 ) ;
else {
F_47 ( V_47 L_4 ,
V_6 , V_39 ) ;
F_48 () ;
}
return NULL ;
}
return V_4 ;
}
struct V_3 * F_49 ( struct V_12 * V_13 ,
struct V_3 * V_14 ,
const char * V_48 )
{
struct V_3 * V_4 = NULL ;
char * V_43 ;
F_38 () ;
F_39 () ;
F_20 ( & V_27 ) ;
V_43 = F_50 ( V_19 , L_5 , V_14 -> V_6 ,
F_51 ( V_13 ) , V_48 ) ;
if ( ! V_43 )
goto V_44;
V_4 = F_32 ( V_43 , V_14 -> V_5 ,
V_14 -> V_7 , V_14 -> V_33 ,
V_14 -> V_29 , V_14 -> V_31 ,
V_13 , V_14 ) ;
if ( F_42 ( V_4 ) ) {
F_14 ( V_43 ) ;
V_4 = NULL ;
}
V_44:
F_22 ( & V_27 ) ;
F_44 () ;
F_45 () ;
return V_4 ;
}
static int F_52 ( struct V_3 * V_4 )
{
int V_49 ;
if ( ! V_4 -> V_18 ||
! V_4 -> V_18 -> V_21 )
return 0 ;
F_22 ( & V_27 ) ;
V_49 = F_53 ( V_4 ) ;
F_20 ( & V_27 ) ;
return V_49 ;
}
static int F_52 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_54 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_6 ) ;
F_55 ( V_3 , V_4 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
F_38 () ;
F_39 () ;
F_20 ( & V_27 ) ;
V_4 -> V_32 -- ;
if ( V_4 -> V_32 )
goto V_44;
if ( F_52 ( V_4 ) != 0 )
goto V_44;
if ( F_57 ( V_4 ) != 0 ) {
F_47 ( V_50 L_6
L_7 , V_4 -> V_6 ) ;
F_48 () ;
goto V_44;
}
F_58 ( & V_4 -> V_41 ) ;
F_22 ( & V_27 ) ;
if ( V_4 -> V_29 & V_51 )
F_59 () ;
F_13 ( V_4 ) ;
#ifdef F_60
F_61 ( V_4 ) ;
#else
F_54 ( V_4 ) ;
#endif
goto V_28;
V_44:
F_22 ( & V_27 ) ;
V_28:
F_44 () ;
F_45 () ;
}
int F_62 ( struct V_3 * V_52 )
{
int V_26 ;
F_38 () ;
F_39 () ;
V_26 = F_63 ( V_52 ) ;
F_44 () ;
F_45 () ;
return V_26 ;
}
int F_64 ( void )
{
return V_53 >= V_54 ;
}
void T_1 F_65 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_29 )
{
int V_39 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_33 = F_26 ( V_29 , V_55 , V_7 ) ;
V_39 = F_34 ( V_4 , V_29 ) ;
if ( V_39 )
F_46 ( L_8 ,
V_6 , V_7 , V_39 ) ;
V_4 -> V_32 = - 1 ;
}
struct V_3 * T_1 F_66 ( const char * V_6 , T_2 V_7 ,
unsigned long V_29 )
{
struct V_3 * V_4 = F_33 ( V_3 , V_56 ) ;
if ( ! V_4 )
F_46 ( L_9 , V_6 ) ;
F_65 ( V_4 , V_6 , V_7 , V_29 ) ;
F_35 ( & V_4 -> V_41 , & V_42 ) ;
V_4 -> V_32 = 1 ;
return V_4 ;
}
static inline int F_67 ( T_2 V_57 )
{
return ( V_57 - 1 ) / 8 ;
}
struct V_3 * F_68 ( T_2 V_7 , T_3 V_29 )
{
int V_58 ;
if ( F_69 ( V_7 > V_8 ) ) {
F_70 ( ! ( V_29 & V_59 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_60 ;
V_58 = V_61 [ F_67 ( V_7 ) ] ;
} else
V_58 = F_71 ( V_7 - 1 ) ;
#ifdef F_72
if ( F_69 ( ( V_29 & V_62 ) ) )
return V_63 [ V_58 ] ;
#endif
return V_64 [ V_58 ] ;
}
void T_1 F_73 ( unsigned long V_29 )
{
int V_65 ;
F_74 ( V_66 > 256 ||
( V_66 & ( V_66 - 1 ) ) ) ;
for ( V_65 = 8 ; V_65 < V_66 ; V_65 += 8 ) {
int V_67 = F_67 ( V_65 ) ;
if ( V_67 >= F_75 ( V_61 ) )
break;
V_61 [ V_67 ] = V_68 ;
}
if ( V_66 >= 64 ) {
for ( V_65 = 64 + 8 ; V_65 <= 96 ; V_65 += 8 )
V_61 [ F_67 ( V_65 ) ] = 7 ;
}
if ( V_66 >= 128 ) {
for ( V_65 = 128 + 8 ; V_65 <= 192 ; V_65 += 8 )
V_61 [ F_67 ( V_65 ) ] = 8 ;
}
for ( V_65 = V_68 ; V_65 <= V_69 ; V_65 ++ ) {
if ( ! V_64 [ V_65 ] ) {
V_64 [ V_65 ] = F_66 ( NULL ,
1 << V_65 , V_29 ) ;
}
if ( V_66 <= 32 && ! V_64 [ 1 ] && V_65 == 6 )
V_64 [ 1 ] = F_66 ( NULL , 96 , V_29 ) ;
if ( V_66 <= 64 && ! V_64 [ 2 ] && V_65 == 7 )
V_64 [ 2 ] = F_66 ( NULL , 192 , V_29 ) ;
}
V_53 = V_54 ;
for ( V_65 = 0 ; V_65 <= V_69 ; V_65 ++ ) {
struct V_3 * V_4 = V_64 [ V_65 ] ;
char * V_70 ;
if ( V_4 ) {
V_70 = F_50 ( V_56 , L_10 , F_76 ( V_65 ) ) ;
F_16 ( ! V_70 ) ;
V_4 -> V_6 = V_70 ;
}
}
#ifdef F_72
for ( V_65 = 0 ; V_65 <= V_69 ; V_65 ++ ) {
struct V_3 * V_4 = V_64 [ V_65 ] ;
if ( V_4 ) {
int V_7 = F_76 ( V_65 ) ;
char * V_70 = F_50 ( V_56 ,
L_11 , V_7 ) ;
F_16 ( ! V_70 ) ;
V_63 [ V_65 ] = F_66 ( V_70 ,
V_7 , V_71 | V_29 ) ;
}
}
#endif
}
void * F_77 ( T_2 V_7 , T_3 V_29 , unsigned int V_72 )
{
void * V_26 ;
struct V_73 * V_73 ;
V_29 |= V_74 ;
V_73 = F_78 ( V_29 , V_72 ) ;
V_26 = V_73 ? F_79 ( V_73 ) : NULL ;
F_80 ( V_26 , V_7 , 1 , V_29 ) ;
return V_26 ;
}
void * F_81 ( T_2 V_7 , T_3 V_29 , unsigned int V_72 )
{
void * V_26 = F_77 ( V_7 , V_29 , V_72 ) ;
F_82 ( V_75 , V_26 , V_7 , V_76 << V_72 , V_29 ) ;
return V_26 ;
}
static void F_83 ( struct V_77 * V_78 )
{
#ifdef F_84
F_85 ( V_78 , L_12 ) ;
#else
F_85 ( V_78 , L_13 ) ;
#endif
F_85 ( V_78 , L_14
L_15 ) ;
F_85 ( V_78 , L_16 ) ;
F_85 ( V_78 , L_17 ) ;
#ifdef F_84
F_85 ( V_78 , L_18
L_19 ) ;
F_85 ( V_78 , L_20 ) ;
#endif
F_86 ( V_78 , '\n' ) ;
}
void * F_87 ( struct V_77 * V_78 , T_4 * V_79 )
{
F_20 ( & V_27 ) ;
return F_88 ( & V_42 , * V_79 ) ;
}
void * F_89 ( struct V_77 * V_78 , void * V_80 , T_4 * V_79 )
{
return F_90 ( V_80 , & V_42 , V_79 ) ;
}
void F_91 ( struct V_77 * V_78 , void * V_80 )
{
F_22 ( & V_27 ) ;
}
static void
F_92 ( struct V_3 * V_4 , struct V_81 * V_82 )
{
struct V_3 * V_83 ;
struct V_81 V_84 ;
int V_65 ;
if ( ! V_21 ( V_4 ) )
return;
F_93 (i) {
V_83 = F_94 ( V_4 , V_65 ) ;
if ( ! V_83 )
continue;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_95 ( V_83 , & V_84 ) ;
V_82 -> V_85 += V_84 . V_85 ;
V_82 -> V_86 += V_84 . V_86 ;
V_82 -> V_87 += V_84 . V_87 ;
V_82 -> V_88 += V_84 . V_88 ;
V_82 -> V_89 += V_84 . V_89 ;
}
}
static void F_96 ( struct V_3 * V_4 , struct V_77 * V_78 )
{
struct V_81 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_95 ( V_4 , & V_84 ) ;
F_92 ( V_4 , & V_84 ) ;
F_97 ( V_78 , L_21 ,
V_43 ( V_4 ) , V_84 . V_88 , V_84 . V_89 , V_4 -> V_7 ,
V_84 . V_90 , ( 1 << V_84 . V_91 ) ) ;
F_97 ( V_78 , L_22 ,
V_84 . V_92 , V_84 . V_93 , V_84 . V_94 ) ;
F_97 ( V_78 , L_23 ,
V_84 . V_85 , V_84 . V_86 , V_84 . V_87 ) ;
F_98 ( V_78 , V_4 ) ;
F_86 ( V_78 , '\n' ) ;
}
static int F_99 ( struct V_77 * V_78 , void * V_80 )
{
struct V_3 * V_4 = F_100 ( V_80 , struct V_3 , V_41 ) ;
if ( V_80 == V_42 . V_95 )
F_83 ( V_78 ) ;
if ( V_21 ( V_4 ) )
F_96 ( V_4 , V_78 ) ;
return 0 ;
}
int F_101 ( struct V_77 * V_78 , void * V_80 )
{
struct V_3 * V_4 = F_100 ( V_80 , struct V_3 , V_41 ) ;
struct V_12 * V_13 = F_102 ( F_103 ( V_78 ) ) ;
if ( V_80 == V_42 . V_95 )
F_83 ( V_78 ) ;
if ( ! V_21 ( V_4 ) && V_4 -> V_18 -> V_13 == V_13 )
F_96 ( V_4 , V_78 ) ;
return 0 ;
}
static int F_104 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
return F_105 ( V_97 , & V_98 ) ;
}
static int T_1 F_106 ( void )
{
F_107 ( L_24 , V_99 , NULL ,
& V_100 ) ;
return 0 ;
}
static T_5 void * F_108 ( const void * V_80 , T_2 V_101 ,
T_3 V_29 )
{
void * V_26 ;
T_2 V_102 = 0 ;
if ( V_80 )
V_102 = F_109 ( V_80 ) ;
if ( V_102 >= V_101 )
return ( void * ) V_80 ;
V_26 = F_110 ( V_101 , V_29 ) ;
if ( V_26 && V_80 )
memcpy ( V_26 , V_80 , V_102 ) ;
return V_26 ;
}
void * F_111 ( const void * V_80 , T_2 V_101 , T_3 V_29 )
{
if ( F_69 ( ! V_101 ) )
return V_60 ;
return F_108 ( V_80 , V_101 , V_29 ) ;
}
void * F_112 ( const void * V_80 , T_2 V_101 , T_3 V_29 )
{
void * V_26 ;
if ( F_69 ( ! V_101 ) ) {
F_14 ( V_80 ) ;
return V_60 ;
}
V_26 = F_108 ( V_80 , V_101 , V_29 ) ;
if ( V_26 && V_80 != V_26 )
F_14 ( V_80 ) ;
return V_26 ;
}
void F_113 ( const void * V_80 )
{
T_2 V_102 ;
void * V_103 = ( void * ) V_80 ;
if ( F_69 ( F_114 ( V_103 ) ) )
return;
V_102 = F_109 ( V_103 ) ;
memset ( V_103 , 0 , V_102 ) ;
F_14 ( V_103 ) ;
}
