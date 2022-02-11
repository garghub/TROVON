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
unsigned long V_39 )
{
unsigned long V_40 ;
T_3 V_41 = F_26 ( V_37 ) + V_5 ;
if ( ! V_2 )
V_2 = & V_42 ;
if ( ! F_18 ( V_2 , V_41 , V_3 ) )
return V_41 ;
V_40 = F_21 ( V_2 , V_41 , V_3 , V_20 , 0 ) ;
F_9 () ;
return V_40 ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_43 ,
T_1 V_3 , enum V_38 V_20 ,
unsigned long V_39 )
{
unsigned long V_30 ;
int V_29 ;
int V_31 ;
if ( V_43 < V_9 + V_21 * V_10 ||
V_43 >= V_9 + V_44 )
return;
V_30 = ( V_43 - V_9 ) >> V_11 ;
V_29 = F_22 ( V_43 , V_3 , V_10 ) ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
V_35 [ V_30 + V_31 ] = V_45 ;
}
F_7 ( V_30 , V_29 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_46 * V_47 , int V_48 ,
enum V_38 V_20 , unsigned long V_39 )
{
struct V_46 * V_49 ;
int V_31 ;
F_29 (sg, s, nents, i) {
if ( ! V_49 -> V_50 || ! V_49 -> V_51 )
break;
F_27 ( V_2 , V_49 -> V_52 , V_49 -> V_50 , V_20 , 0 ) ;
}
}
static int F_30 ( struct V_1 * V_2 , struct V_46 * V_47 ,
int V_48 , int V_20 )
{
struct V_46 * V_49 ;
int V_31 ;
#ifdef F_31
F_32 ( L_5 ) ;
#endif
F_29 (sg, s, nents, i) {
unsigned long V_26 = F_33 ( V_49 ) ;
if ( F_20 ( V_2 , V_26 , V_49 -> V_51 ) ) {
V_26 = F_21 ( V_2 , V_26 , V_49 -> V_51 , V_20 , 0 ) ;
if ( V_26 == V_33 ) {
if ( V_31 > 0 )
F_28 ( V_2 , V_47 , V_31 , V_20 , 0 ) ;
V_48 = 0 ;
V_47 [ 0 ] . V_50 = 0 ;
break;
}
}
V_49 -> V_52 = V_26 ;
V_49 -> V_50 = V_49 -> V_51 ;
}
F_9 () ;
return V_48 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_46 * V_53 ,
int V_54 , struct V_46 * V_55 ,
unsigned long V_56 )
{
unsigned long V_57 = F_1 ( V_2 , V_56 , 0 ) ;
unsigned long V_30 = V_57 ;
struct V_46 * V_49 ;
int V_31 ;
if ( V_57 == - 1 )
return - 1 ;
F_29 (start, s, nelems, i) {
unsigned long V_56 , V_26 ;
unsigned long V_58 = V_49 -> V_52 ;
F_35 ( V_49 != V_53 && V_49 -> V_5 ) ;
if ( V_49 == V_53 ) {
V_55 -> V_52 = V_9 ;
V_55 -> V_52 += V_30 * V_10 + V_49 -> V_5 ;
V_55 -> V_50 = V_49 -> V_51 ;
} else {
V_55 -> V_50 += V_49 -> V_51 ;
}
V_26 = V_58 ;
V_56 = F_22 ( V_49 -> V_5 , V_49 -> V_51 , V_10 ) ;
while ( V_56 -- ) {
V_35 [ V_30 ] = F_24 ( V_26 ) ;
V_26 += V_10 ;
V_30 ++ ;
}
}
F_35 ( V_30 - V_57 != V_56 ) ;
return 0 ;
}
static inline int
F_36 ( struct V_1 * V_2 , struct V_46 * V_53 , int V_54 ,
struct V_46 * V_55 , unsigned long V_56 , int V_59 )
{
if ( ! V_59 ) {
F_35 ( V_54 != 1 ) ;
V_55 -> V_52 = V_53 -> V_52 ;
V_55 -> V_50 = V_53 -> V_51 ;
return 0 ;
}
return F_34 ( V_2 , V_53 , V_54 , V_55 , V_56 ) ;
}
static int F_37 ( struct V_1 * V_2 , struct V_46 * V_47 , int V_48 ,
enum V_38 V_20 , unsigned long V_39 )
{
struct V_46 * V_49 , * V_60 , * V_61 , * V_62 ;
int V_59 = 0 , V_63 , V_31 , V_64 , V_53 ;
unsigned long V_56 = 0 ;
unsigned int V_65 ;
unsigned int V_66 ;
if ( V_48 == 0 )
return 0 ;
if ( ! V_2 )
V_2 = & V_42 ;
V_64 = 0 ;
V_53 = 0 ;
V_61 = V_47 ;
V_62 = V_47 ;
V_65 = 0 ;
V_66 = F_38 ( V_2 ) ;
V_60 = NULL ;
F_29 (sg, s, nents, i) {
T_2 V_26 = F_33 ( V_49 ) ;
V_49 -> V_52 = V_26 ;
F_35 ( V_49 -> V_51 == 0 ) ;
V_63 = F_18 ( V_2 , V_26 , V_49 -> V_51 ) ;
if ( V_31 > V_53 ) {
if ( ! V_67 || ! V_63 || ! V_59 || V_49 -> V_5 ||
( V_49 -> V_51 + V_65 > V_66 ) ||
( V_60 -> V_5 + V_60 -> V_51 ) % V_10 ) {
if ( F_36 ( V_2 , V_61 , V_31 - V_53 ,
V_62 , V_56 , V_59 ) < 0 )
goto error;
V_64 ++ ;
V_65 = 0 ;
V_62 = F_39 ( V_62 ) ;
V_56 = 0 ;
V_53 = V_31 ;
V_61 = V_49 ;
}
}
V_65 += V_49 -> V_51 ;
V_59 = V_63 ;
V_56 += F_22 ( V_49 -> V_5 , V_49 -> V_51 , V_10 ) ;
V_60 = V_49 ;
}
if ( F_36 ( V_2 , V_61 , V_31 - V_53 , V_62 , V_56 , V_59 ) < 0 )
goto error;
V_64 ++ ;
F_9 () ;
if ( V_64 < V_48 ) {
V_62 = F_39 ( V_62 ) ;
V_62 -> V_50 = 0 ;
}
return V_64 ;
error:
F_9 () ;
F_28 ( V_2 , V_47 , V_64 , V_20 , 0 ) ;
if ( V_27 || V_67 ) {
V_64 = F_30 ( V_2 , V_47 , V_48 , V_20 ) ;
if ( V_64 > 0 )
return V_64 ;
}
if ( V_34 )
F_16 ( L_6 , V_56 ) ;
F_14 ( V_2 , V_56 << V_11 , V_20 ) ;
F_29 (sg, s, nents, i)
V_49 -> V_52 = V_33 ;
return 0 ;
}
static void *
F_40 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_43 ,
T_4 V_68 , unsigned long V_39 )
{
T_2 V_41 ;
unsigned long V_4 ;
struct V_37 * V_37 ;
if ( V_27 && ! ( V_68 & V_69 ) ) {
V_68 &= ~ ( V_70 | V_71 | V_72 ) ;
V_37 = F_41 ( V_68 | V_73 , F_42 ( V_3 ) ) ;
if ( ! V_37 )
return NULL ;
V_4 = ( 1UL << F_42 ( V_3 ) ) - 1 ;
V_41 = F_21 ( V_2 , F_26 ( V_37 ) , V_3 ,
V_74 , V_4 ) ;
F_9 () ;
if ( V_41 != V_33 ) {
* V_43 = V_41 ;
return F_43 ( V_37 ) ;
}
F_44 ( V_37 , F_42 ( V_3 ) ) ;
} else
return F_45 ( V_2 , V_3 , V_43 , V_68 ,
V_39 ) ;
return NULL ;
}
static void
F_46 ( struct V_1 * V_2 , T_1 V_3 , void * V_75 ,
T_2 V_43 , unsigned long V_39 )
{
F_27 ( V_2 , V_43 , V_3 , V_74 , 0 ) ;
F_47 ( V_2 , V_3 , V_75 , V_43 , V_39 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_43 )
{
return ( V_43 == V_33 ) ;
}
static T_5 unsigned long F_49 ( unsigned long V_76 , V_12 V_77 )
{
unsigned long V_78 ;
if ( ! V_44 ) {
V_44 = V_77 ;
if ( ! V_79 )
V_44 /= 2 ;
}
V_78 = V_76 + V_44 ;
V_44 -= F_50 ( V_78 , V_80 ) - V_78 ;
if ( V_44 < 64 * 1024 * 1024 ) {
F_51 (
L_7
L_8 ,
V_44 >> 20 ) ;
}
return V_44 ;
}
static T_5 unsigned F_52 ( struct V_81 * V_2 , T_6 * V_3 )
{
unsigned V_77 = 0 , V_82 , V_83 ;
V_12 V_84 ;
F_53 ( V_2 , V_85 , & V_82 ) ;
F_53 ( V_2 , V_86 , & V_83 ) ;
V_83 = ( V_83 >> 1 ) & 7 ;
V_84 = V_82 & 0x7fff ;
V_84 <<= 25 ;
V_77 = ( 32 * 1024 * 1024 ) << V_83 ;
if ( V_84 + V_77 > 0x100000000UL || ! V_77 )
V_84 = 0 ;
* V_3 = V_77 ;
return V_84 ;
}
static void F_54 ( void )
{
int V_31 ;
if ( ! F_55 ( V_87 ) )
return;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
struct V_81 * V_2 = F_57 ( V_31 ) -> V_88 ;
F_58 ( V_2 , F_59 ( V_89 ) ) ;
}
F_10 () ;
}
void F_60 ( T_6 V_83 , T_6 V_90 )
{
V_91 = true ;
V_92 = V_83 ;
V_93 = V_90 ;
}
static void F_61 ( void )
{
int V_31 ;
if ( ! V_91 )
return;
if ( ! F_55 ( V_87 ) )
return;
F_62 ( L_9 ) ;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
struct V_81 * V_2 = F_57 ( V_31 ) -> V_88 ;
F_63 ( V_2 , V_92 ) ;
F_64 ( V_2 , V_85 , V_93 >> 25 ) ;
}
}
static void F_65 ( void )
{
F_62 ( L_10 ) ;
F_61 () ;
F_54 () ;
}
static T_5 int F_66 ( struct V_94 * V_95 )
{
unsigned V_77 , V_96 , V_97 ;
unsigned V_84 , V_98 ;
struct V_81 * V_2 ;
void * V_99 ;
int V_31 ;
F_62 ( L_11 ) ;
V_77 = V_84 = V_95 -> V_77 = 0 ;
V_2 = NULL ;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
V_2 = F_57 ( V_31 ) -> V_88 ;
V_98 = F_52 ( V_2 , & V_97 ) ;
if ( ! V_98 )
goto V_100;
if ( ! V_84 ) {
V_77 = V_97 ;
V_84 = V_98 ;
}
if ( V_77 != V_97 || V_84 != V_98 )
goto V_100;
}
if ( ! V_84 )
goto V_100;
V_95 -> V_84 = V_84 ;
V_95 -> V_77 = V_77 >> 20 ;
V_96 = ( V_77 >> V_11 ) * sizeof( T_6 ) ;
V_99 = ( void * ) F_67 ( V_101 | V_73 ,
F_42 ( V_96 ) ) ;
if ( ! V_99 )
F_16 ( L_12 ) ;
if ( F_68 ( ( unsigned long ) V_99 , V_96 >> V_11 ) )
F_16 ( L_13 ) ;
V_89 = V_99 ;
F_69 ( & V_102 ) ;
F_9 () ;
F_62 ( L_14 ,
V_84 , V_77 >> 10 ) ;
return 0 ;
V_100:
F_51 ( L_15
L_16 ) ;
return - 1 ;
}
static void F_70 ( void )
{
struct V_81 * V_2 ;
int V_31 ;
if ( ! V_79 )
return;
if ( ! F_55 ( V_87 ) )
return;
for ( V_31 = 0 ; V_31 < F_56 () ; V_31 ++ ) {
T_6 V_103 ;
V_2 = F_57 ( V_31 ) -> V_88 ;
F_53 ( V_2 , V_86 , & V_103 ) ;
V_103 &= ~ V_104 ;
F_64 ( V_2 , V_86 , V_103 ) ;
}
}
int T_5 F_71 ( void )
{
struct V_94 V_95 ;
unsigned long V_57 ;
unsigned long V_84 , V_77 ;
unsigned long V_105 , V_106 ;
unsigned long V_107 ;
long V_31 ;
if ( ! F_55 ( V_87 ) )
return 0 ;
#ifndef F_72
V_79 = 1 ;
#else
V_79 = V_79 ||
( F_73 () < 0 ) ||
( F_74 ( V_108 , & V_95 ) < 0 ) ;
#endif
if ( V_109 ||
( ! V_27 && V_110 <= V_111 ) ||
! V_112 ||
( V_79 && F_66 ( & V_95 ) < 0 ) ) {
if ( V_110 > V_111 ) {
F_51 ( L_17 ) ;
F_51 ( L_16 ) ;
}
return 0 ;
}
V_77 = V_95 . V_77 << 20 ;
V_84 = V_95 . V_84 ;
V_106 = ( V_84 >> V_11 ) + ( V_77 >> V_11 ) ;
V_105 = F_75 ( V_84 ) ;
if ( ! F_76 ( V_105 , V_106 ) )
F_77 ( V_105 << V_11 , V_106 << V_11 ) ;
F_62 ( L_18 ) ;
V_44 = F_49 ( V_95 . V_84 , V_77 ) ;
V_15 = V_44 >> V_11 ;
V_14 = ( void * ) F_67 ( V_101 | V_73 ,
F_42 ( V_15 / 8 ) ) ;
if ( ! V_14 )
F_16 ( L_19 ) ;
#ifdef F_17
if ( V_113 ) {
int V_114 ;
V_114 = F_78 ( V_15 ) ;
if ( V_114 )
F_32 ( L_20 ) ;
}
#endif
F_79 ( V_14 , 0 , V_21 ) ;
F_62 ( L_21 ,
V_44 >> 20 ) ;
V_115 = V_44 ;
V_57 = V_77 - V_44 ;
V_9 = V_95 . V_84 + V_57 ;
V_33 = V_9 ;
V_35 = V_89 + ( V_57 >> V_11 ) ;
F_80 ( ( unsigned long ) F_81 ( V_9 ) ,
V_44 >> V_11 ) ;
F_82 () ;
F_54 () ;
V_107 = F_83 ( V_101 ) ;
if ( ! V_107 )
F_16 ( L_22 ) ;
V_45 = F_24 ( F_59 ( V_107 ) ) ;
for ( V_31 = V_21 ; V_31 < V_15 ; V_31 ++ )
V_35 [ V_31 ] = V_45 ;
F_9 () ;
V_116 = & V_117 ;
V_118 . V_119 = F_70 ;
V_120 = 0 ;
return 0 ;
}
void T_5 F_84 ( char * V_121 )
{
int V_122 ;
#ifdef F_17
if ( ! strncmp ( V_121 , L_23 , 4 ) ) {
V_113 = 1 ;
V_121 += 4 ;
if ( * V_121 == '=' )
++ V_121 ;
if ( isdigit ( * V_121 ) && F_85 ( & V_121 , & V_122 ) )
V_123 = V_122 ;
}
#endif
if ( isdigit ( * V_121 ) && F_85 ( & V_121 , & V_122 ) )
V_44 = V_122 ;
if ( ! strncmp ( V_121 , L_24 , 9 ) )
V_18 = 1 ;
if ( ! strncmp ( V_121 , L_25 , 11 ) )
V_18 = 0 ;
if ( ! strncmp ( V_121 , L_26 , 5 ) )
V_79 = 1 ;
if ( ! strncmp ( V_121 , L_27 , 10 ) )
V_124 = 0 ;
if ( ! strncmp ( V_121 , L_28 , 5 ) )
V_125 = 1 ;
if ( ! strncmp ( V_121 , L_29 , 7 ) )
V_125 = 1 ;
if ( ! strncmp ( V_121 , L_30 , 7 ) ) {
V_126 = 1 ;
V_121 += 7 ;
if ( * V_121 == '=' ) {
++ V_121 ;
if ( F_85 ( & V_121 , & V_122 ) )
V_127 = V_122 ;
}
}
}
