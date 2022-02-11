static unsigned long F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_4 )
{
unsigned long V_5 , V_6 ;
unsigned long V_7 ;
unsigned long V_8 ;
V_8 = F_2 ( V_9 & F_3 ( V_2 ) ,
V_10 ) >> V_11 ;
V_7 = F_2 ( ( V_12 ) F_3 ( V_2 ) + 1 ,
V_10 ) >> V_11 ;
F_4 ( & V_13 , V_6 ) ;
V_5 = F_5 ( V_14 , V_15 , V_16 ,
V_3 , V_8 , V_7 , V_4 ) ;
if ( V_5 == - 1 ) {
V_17 = true ;
V_5 = F_5 ( V_14 , V_15 , 0 ,
V_3 , V_8 , V_7 ,
V_4 ) ;
}
if ( V_5 != - 1 ) {
V_16 = V_5 + V_3 ;
if ( V_16 >= V_15 ) {
V_16 = 0 ;
V_17 = true ;
}
}
if ( V_18 )
V_17 = true ;
F_6 ( & V_13 , V_6 ) ;
return V_5 ;
}
static void F_7 ( unsigned long V_5 , int V_3 )
{
unsigned long V_6 ;
F_4 ( & V_13 , V_6 ) ;
F_8 ( V_14 , V_5 , V_3 ) ;
if ( V_5 >= V_16 )
V_16 = V_5 + V_3 ;
F_6 ( & V_13 , V_6 ) ;
}
static void F_9 ( void )
{
unsigned long V_6 ;
F_4 ( & V_13 , V_6 ) ;
if ( V_17 ) {
F_10 () ;
V_17 = false ;
}
F_6 ( & V_13 , V_6 ) ;
}
static void F_11 ( void )
{
static int V_19 ;
if ( V_19 )
return;
V_19 = 1 ;
F_12 ( NULL , NULL ) ;
F_13 ( NULL ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 , int V_20 )
{
F_15 ( V_2 , L_1 , V_3 ) ;
if ( V_3 > V_10 * V_21 ) {
if ( V_20 == V_22 || V_20 == V_23 )
F_16 ( L_2 ) ;
if ( V_20 == V_24 || V_20 == V_23 )
F_16 ( V_25
L_3 ) ;
}
#ifdef F_17
F_11 () ;
#endif
}
static inline int
F_18 ( struct V_1 * V_2 , unsigned long V_26 , T_1 V_3 )
{
return V_27 || ! F_19 ( V_2 , V_26 , V_3 ) ;
}
static inline int
F_20 ( struct V_1 * V_2 , unsigned long V_26 , T_1 V_3 )
{
return ! F_19 ( V_2 , V_26 , V_3 ) ;
}
static T_2 F_21 ( struct V_1 * V_2 , T_2 V_28 ,
T_1 V_3 , int V_20 , unsigned long V_4 )
{
unsigned long V_29 = F_22 ( V_28 , V_3 , V_10 ) ;
unsigned long V_30 ;
int V_31 ;
if ( F_23 ( V_28 + V_3 > V_32 ) )
return V_33 ;
V_30 = F_1 ( V_2 , V_29 , V_4 ) ;
if ( V_30 == - 1 ) {
if ( ! F_20 ( V_2 , V_28 , V_3 ) )
return V_28 ;
if ( V_34 )
F_16 ( L_4 , V_3 ) ;
F_14 ( V_2 , V_3 , V_20 ) ;
return V_33 ;
}
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
V_35 [ V_30 + V_31 ] = F_24 ( V_28 ) ;
V_28 += V_10 ;
}
return V_9 + V_30 * V_10 + ( V_28 & ~ V_36 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , struct V_37 * V_37 ,
unsigned long V_5 , T_1 V_3 ,
enum V_38 V_20 ,
struct V_39 * V_40 )
{
unsigned long V_41 ;
T_3 V_42 = F_26 ( V_37 ) + V_5 ;
if ( ! V_2 )
V_2 = & V_43 ;
if ( ! F_18 ( V_2 , V_42 , V_3 ) )
return V_42 ;
V_41 = F_21 ( V_2 , V_42 , V_3 , V_20 , 0 ) ;
F_9 () ;
return V_41 ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_44 ,
T_1 V_3 , enum V_38 V_20 ,
struct V_39 * V_40 )
{
unsigned long V_30 ;
int V_29 ;
int V_31 ;
if ( V_44 < V_9 + V_21 * V_10 ||
V_44 >= V_9 + V_45 )
return;
V_30 = ( V_44 - V_9 ) >> V_11 ;
V_29 = F_22 ( V_44 , V_3 , V_10 ) ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
V_35 [ V_30 + V_31 ] = V_46 ;
}
F_7 ( V_30 , V_29 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_47 * V_48 , int V_49 ,
enum V_38 V_20 , struct V_39 * V_40 )
{
struct V_47 * V_50 ;
int V_31 ;
F_29 (sg, s, nents, i) {
if ( ! V_50 -> V_51 || ! V_50 -> V_52 )
break;
F_27 ( V_2 , V_50 -> V_53 , V_50 -> V_51 , V_20 , NULL ) ;
}
}
static int F_30 ( struct V_1 * V_2 , struct V_47 * V_48 ,
int V_49 , int V_20 )
{
struct V_47 * V_50 ;
int V_31 ;
#ifdef F_31
F_32 ( L_5 ) ;
#endif
F_29 (sg, s, nents, i) {
unsigned long V_26 = F_33 ( V_50 ) ;
if ( F_20 ( V_2 , V_26 , V_50 -> V_52 ) ) {
V_26 = F_21 ( V_2 , V_26 , V_50 -> V_52 , V_20 , 0 ) ;
if ( V_26 == V_33 ) {
if ( V_31 > 0 )
F_28 ( V_2 , V_48 , V_31 , V_20 , NULL ) ;
V_49 = 0 ;
V_48 [ 0 ] . V_51 = 0 ;
break;
}
}
V_50 -> V_53 = V_26 ;
V_50 -> V_51 = V_50 -> V_52 ;
}
F_9 () ;
return V_49 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_47 * V_54 ,
int V_55 , struct V_47 * V_56 ,
unsigned long V_57 )
{
unsigned long V_58 = F_1 ( V_2 , V_57 , 0 ) ;
unsigned long V_30 = V_58 ;
struct V_47 * V_50 ;
int V_31 ;
if ( V_58 == - 1 )
return - 1 ;
F_29 (start, s, nelems, i) {
unsigned long V_57 , V_26 ;
unsigned long V_59 = V_50 -> V_53 ;
F_35 ( V_50 != V_54 && V_50 -> V_5 ) ;
if ( V_50 == V_54 ) {
V_56 -> V_53 = V_9 ;
V_56 -> V_53 += V_30 * V_10 + V_50 -> V_5 ;
V_56 -> V_51 = V_50 -> V_52 ;
} else {
V_56 -> V_51 += V_50 -> V_52 ;
}
V_26 = V_59 ;
V_57 = F_22 ( V_50 -> V_5 , V_50 -> V_52 , V_10 ) ;
while ( V_57 -- ) {
V_35 [ V_30 ] = F_24 ( V_26 ) ;
V_26 += V_10 ;
V_30 ++ ;
}
}
F_35 ( V_30 - V_58 != V_57 ) ;
return 0 ;
}
static inline int
F_36 ( struct V_1 * V_2 , struct V_47 * V_54 , int V_55 ,
struct V_47 * V_56 , unsigned long V_57 , int V_60 )
{
if ( ! V_60 ) {
F_35 ( V_55 != 1 ) ;
V_56 -> V_53 = V_54 -> V_53 ;
V_56 -> V_51 = V_54 -> V_52 ;
return 0 ;
}
return F_34 ( V_2 , V_54 , V_55 , V_56 , V_57 ) ;
}
static int F_37 ( struct V_1 * V_2 , struct V_47 * V_48 , int V_49 ,
enum V_38 V_20 , struct V_39 * V_40 )
{
struct V_47 * V_50 , * V_61 , * V_62 , * V_63 ;
int V_60 = 0 , V_64 , V_31 , V_65 , V_54 ;
unsigned long V_57 = 0 ;
unsigned int V_66 ;
unsigned int V_67 ;
if ( V_49 == 0 )
return 0 ;
if ( ! V_2 )
V_2 = & V_43 ;
V_65 = 0 ;
V_54 = 0 ;
V_62 = V_48 ;
V_63 = V_48 ;
V_66 = 0 ;
V_67 = F_38 ( V_2 ) ;
V_61 = NULL ;
F_29 (sg, s, nents, i) {
T_2 V_26 = F_33 ( V_50 ) ;
V_50 -> V_53 = V_26 ;
F_35 ( V_50 -> V_52 == 0 ) ;
V_64 = F_18 ( V_2 , V_26 , V_50 -> V_52 ) ;
if ( V_31 > V_54 ) {
if ( ! V_68 || ! V_64 || ! V_60 || V_50 -> V_5 ||
( V_50 -> V_52 + V_66 > V_67 ) ||
( V_61 -> V_5 + V_61 -> V_52 ) % V_10 ) {
if ( F_36 ( V_2 , V_62 , V_31 - V_54 ,
V_63 , V_57 , V_60 ) < 0 )
goto error;
V_65 ++ ;
V_66 = 0 ;
V_63 = F_39 ( V_63 ) ;
V_57 = 0 ;
V_54 = V_31 ;
V_62 = V_50 ;
}
}
V_66 += V_50 -> V_52 ;
V_60 = V_64 ;
V_57 += F_22 ( V_50 -> V_5 , V_50 -> V_52 , V_10 ) ;
V_61 = V_50 ;
}
if ( F_36 ( V_2 , V_62 , V_31 - V_54 , V_63 , V_57 , V_60 ) < 0 )
goto error;
V_65 ++ ;
F_9 () ;
if ( V_65 < V_49 ) {
V_63 = F_39 ( V_63 ) ;
V_63 -> V_51 = 0 ;
}
return V_65 ;
error:
F_9 () ;
F_28 ( V_2 , V_48 , V_65 , V_20 , NULL ) ;
if ( V_27 || V_68 ) {
V_65 = F_30 ( V_2 , V_48 , V_49 , V_20 ) ;
if ( V_65 > 0 )
return V_65 ;
}
if ( V_34 )
F_16 ( L_6 , V_57 ) ;
F_14 ( V_2 , V_57 << V_11 , V_20 ) ;
F_29 (sg, s, nents, i)
V_50 -> V_53 = V_33 ;
return 0 ;
}
static void *
F_40 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_44 ,
T_4 V_69 , struct V_39 * V_40 )
{
T_2 V_42 ;
unsigned long V_4 ;
struct V_37 * V_37 ;
if ( V_27 && ! ( V_69 & V_70 ) ) {
V_69 &= ~ ( V_71 | V_72 | V_73 ) ;
V_37 = F_41 ( V_69 | V_74 , F_42 ( V_3 ) ) ;
if ( ! V_37 )
return NULL ;
V_4 = ( 1UL << F_42 ( V_3 ) ) - 1 ;
V_42 = F_21 ( V_2 , F_26 ( V_37 ) , V_3 ,
V_75 , V_4 ) ;
F_9 () ;
if ( V_42 != V_33 ) {
* V_44 = V_42 ;
return F_43 ( V_37 ) ;
}
F_44 ( V_37 , F_42 ( V_3 ) ) ;
} else
return F_45 ( V_2 , V_3 , V_44 , V_69 ,
V_40 ) ;
return NULL ;
}
static void
F_46 ( struct V_1 * V_2 , T_1 V_3 , void * V_76 ,
T_2 V_44 , struct V_39 * V_40 )
{
F_27 ( V_2 , V_44 , V_3 , V_75 , NULL ) ;
F_47 ( ( unsigned long ) V_76 , F_42 ( V_3 ) ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_44 )
{
return ( V_44 == V_33 ) ;
}
static T_5 unsigned long F_49 ( unsigned long V_77 , V_12 V_78 )
{
unsigned long V_79 ;
if ( ! V_45 ) {
V_45 = V_78 ;
if ( ! V_80 )
V_45 /= 2 ;
}
V_79 = V_77 + V_45 ;
V_45 -= F_50 ( V_79 , V_81 ) - V_79 ;
if ( V_45 < 64 * 1024 * 1024 ) {
F_51 (
L_7
L_8 ,
V_45 >> 20 ) ;
}
return V_45 ;
}
static T_5 unsigned F_52 ( struct V_82 * V_2 , T_6 * V_3 )
{
unsigned V_78 = 0 , V_83 , V_84 ;
V_12 V_85 ;
F_53 ( V_2 , V_86 , & V_83 ) ;
F_53 ( V_2 , V_87 , & V_84 ) ;
V_84 = ( V_84 >> 1 ) & 7 ;
V_85 = V_83 & 0x7fff ;
V_85 <<= 25 ;
V_78 = ( 32 * 1024 * 1024 ) << V_84 ;
if ( V_85 + V_78 > 0x100000000UL || ! V_78 )
V_85 = 0 ;
* V_3 = V_78 ;
return V_85 ;
}
static void F_54 ( void )
{
int V_31 ;
if ( ! F_55 ( V_88 ) )
return;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
struct V_82 * V_2 = F_57 ( V_31 ) -> V_89 ;
F_58 ( V_2 , F_59 ( V_90 ) ) ;
}
F_10 () ;
}
void F_60 ( T_6 V_84 , T_6 V_91 )
{
V_92 = true ;
V_93 = V_84 ;
V_94 = V_91 ;
}
static void F_61 ( void )
{
int V_31 ;
if ( ! V_92 )
return;
if ( ! F_55 ( V_88 ) )
return;
F_62 ( L_9 ) ;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
struct V_82 * V_2 = F_57 ( V_31 ) -> V_89 ;
F_63 ( V_2 , V_93 ) ;
F_64 ( V_2 , V_86 , V_94 >> 25 ) ;
}
}
static void F_65 ( void )
{
F_62 ( L_10 ) ;
F_61 () ;
F_54 () ;
}
static T_5 int F_66 ( struct V_95 * V_96 )
{
unsigned V_78 , V_97 , V_98 ;
unsigned V_85 , V_99 ;
struct V_82 * V_2 ;
void * V_100 ;
int V_31 ;
F_62 ( L_11 ) ;
V_78 = V_85 = V_96 -> V_78 = 0 ;
V_2 = NULL ;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
V_2 = F_57 ( V_31 ) -> V_89 ;
V_99 = F_52 ( V_2 , & V_98 ) ;
if ( ! V_99 )
goto V_101;
if ( ! V_85 ) {
V_78 = V_98 ;
V_85 = V_99 ;
}
if ( V_78 != V_98 || V_85 != V_99 )
goto V_101;
}
if ( ! V_85 )
goto V_101;
V_96 -> V_85 = V_85 ;
V_96 -> V_78 = V_78 >> 20 ;
V_97 = ( V_78 >> V_11 ) * sizeof( T_6 ) ;
V_100 = ( void * ) F_67 ( V_102 | V_74 ,
F_42 ( V_97 ) ) ;
if ( ! V_100 )
F_16 ( L_12 ) ;
if ( F_68 ( ( unsigned long ) V_100 , V_97 >> V_11 ) )
F_16 ( L_13 ) ;
V_90 = V_100 ;
F_69 ( & V_103 ) ;
F_9 () ;
F_62 ( L_14 ,
V_85 , V_78 >> 10 ) ;
return 0 ;
V_101:
F_51 ( L_15
L_16 ) ;
return - 1 ;
}
static void F_70 ( void )
{
struct V_82 * V_2 ;
int V_31 ;
if ( ! V_80 )
return;
if ( ! F_55 ( V_88 ) )
return;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
T_6 V_104 ;
V_2 = F_57 ( V_31 ) -> V_89 ;
F_53 ( V_2 , V_87 , & V_104 ) ;
V_104 &= ~ V_105 ;
F_64 ( V_2 , V_87 , V_104 ) ;
}
}
int T_5 F_71 ( void )
{
struct V_95 V_96 ;
unsigned long V_58 ;
unsigned long V_85 , V_78 ;
unsigned long V_106 , V_107 ;
unsigned long V_108 ;
long V_31 ;
if ( ! F_55 ( V_88 ) )
return 0 ;
#ifndef F_72
V_80 = 1 ;
#else
V_80 = V_80 ||
( F_73 () < 0 ) ||
( F_74 ( V_109 , & V_96 ) < 0 ) ;
#endif
if ( V_110 ||
( ! V_27 && V_111 <= V_112 ) ||
! V_113 ||
( V_80 && F_66 ( & V_96 ) < 0 ) ) {
if ( V_111 > V_112 ) {
F_51 ( L_17 ) ;
F_51 ( L_16 ) ;
}
return 0 ;
}
V_78 = V_96 . V_78 << 20 ;
V_85 = V_96 . V_85 ;
V_107 = ( V_85 >> V_11 ) + ( V_78 >> V_11 ) ;
V_106 = F_75 ( V_85 ) ;
if ( ! F_76 ( V_106 , V_107 ) )
F_77 ( V_106 << V_11 , V_107 << V_11 ) ;
F_62 ( L_18 ) ;
V_45 = F_49 ( V_96 . V_85 , V_78 ) ;
V_15 = V_45 >> V_11 ;
V_14 = ( void * ) F_67 ( V_102 | V_74 ,
F_42 ( V_15 / 8 ) ) ;
if ( ! V_14 )
F_16 ( L_19 ) ;
#ifdef F_17
if ( V_114 ) {
int V_115 ;
V_115 = F_78 ( V_15 ) ;
if ( V_115 )
F_32 ( L_20 ) ;
}
#endif
F_79 ( V_14 , 0 , V_21 ) ;
F_62 ( L_21 ,
V_45 >> 20 ) ;
V_116 = V_45 ;
V_58 = V_78 - V_45 ;
V_9 = V_96 . V_85 + V_58 ;
V_33 = V_9 ;
V_35 = V_90 + ( V_58 >> V_11 ) ;
F_80 ( ( unsigned long ) F_81 ( V_9 ) ,
V_45 >> V_11 ) ;
F_82 () ;
F_54 () ;
V_108 = F_83 ( V_102 ) ;
if ( ! V_108 )
F_16 ( L_22 ) ;
V_46 = F_24 ( F_59 ( V_108 ) ) ;
for ( V_31 = V_21 ; V_31 < V_15 ; V_31 ++ )
V_35 [ V_31 ] = V_46 ;
F_9 () ;
V_117 = & V_118 ;
V_119 . V_120 = F_70 ;
V_121 = 0 ;
return 0 ;
}
void T_5 F_84 ( char * V_122 )
{
int V_123 ;
#ifdef F_17
if ( ! strncmp ( V_122 , L_23 , 4 ) ) {
V_114 = 1 ;
V_122 += 4 ;
if ( * V_122 == '=' )
++ V_122 ;
if ( isdigit ( * V_122 ) && F_85 ( & V_122 , & V_123 ) )
V_124 = V_123 ;
}
#endif
if ( isdigit ( * V_122 ) && F_85 ( & V_122 , & V_123 ) )
V_45 = V_123 ;
if ( ! strncmp ( V_122 , L_24 , 9 ) )
V_18 = 1 ;
if ( ! strncmp ( V_122 , L_25 , 11 ) )
V_18 = 0 ;
if ( ! strncmp ( V_122 , L_26 , 5 ) )
V_80 = 1 ;
if ( ! strncmp ( V_122 , L_27 , 10 ) )
V_125 = 0 ;
if ( ! strncmp ( V_122 , L_28 , 5 ) )
V_126 = 1 ;
if ( ! strncmp ( V_122 , L_29 , 7 ) )
V_126 = 1 ;
if ( ! strncmp ( V_122 , L_30 , 7 ) ) {
V_127 = 1 ;
V_122 += 7 ;
if ( * V_122 == '=' ) {
++ V_122 ;
if ( F_85 ( & V_122 , & V_123 ) )
V_128 = V_123 ;
}
}
}
