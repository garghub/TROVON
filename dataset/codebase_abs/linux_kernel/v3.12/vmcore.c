int F_1 ( int (* F_2)( unsigned long V_1 ) )
{
if ( V_2 )
return - V_3 ;
V_2 = F_2 ;
return 0 ;
}
void F_3 ( void )
{
V_2 = NULL ;
F_4 () ;
}
static int F_5 ( unsigned long V_1 )
{
int (* F_2)( unsigned long V_1 );
int V_4 = 1 ;
F_2 = V_2 ;
if ( F_2 )
V_4 = F_2 ( V_1 ) ;
return V_4 ;
}
static T_1 F_6 ( char * V_5 , T_2 V_6 ,
T_3 * V_7 , int V_8 )
{
unsigned long V_1 , V_9 ;
T_2 V_10 ;
T_1 V_11 = 0 , V_12 ;
if ( ! V_6 )
return 0 ;
V_9 = ( unsigned long ) ( * V_7 % V_13 ) ;
V_1 = ( unsigned long ) ( * V_7 / V_13 ) ;
do {
if ( V_6 > ( V_13 - V_9 ) )
V_10 = V_13 - V_9 ;
else
V_10 = V_6 ;
if ( F_5 ( V_1 ) == 0 )
memset ( V_5 , 0 , V_10 ) ;
else {
V_12 = F_7 ( V_1 , V_5 , V_10 ,
V_9 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
}
* V_7 += V_10 ;
V_6 -= V_10 ;
V_5 += V_10 ;
V_11 += V_10 ;
++ V_1 ;
V_9 = 0 ;
} while ( V_6 );
return V_11 ;
}
int __weak F_8 ( unsigned long long * V_14 , unsigned long long * V_15 )
{
return 0 ;
}
void __weak F_9 ( unsigned long long V_14 )
{}
T_1 __weak F_10 ( char * V_5 , T_2 V_6 , T_3 * V_7 )
{
return F_6 ( V_5 , V_6 , V_7 , 0 ) ;
}
T_1 __weak F_11 ( char * V_5 , T_2 V_6 , T_3 * V_7 )
{
return F_6 ( V_5 , V_6 , V_7 , 0 ) ;
}
int __weak F_12 ( struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_1 ,
unsigned long V_15 , T_4 V_19 )
{
return F_13 ( V_17 , V_18 , V_1 , V_15 , V_19 ) ;
}
static int F_14 ( void * V_20 , void * V_21 , T_2 V_15 , int V_8 )
{
if ( V_8 ) {
if ( F_15 ( ( char V_22 * ) V_20 , V_21 , V_15 ) )
return - V_23 ;
} else {
memcpy ( V_20 , V_21 , V_15 ) ;
}
return 0 ;
}
static T_1 F_16 ( char * V_24 , T_2 V_25 , T_5 * V_26 ,
int V_8 )
{
T_1 V_27 = 0 , V_12 ;
T_2 V_28 ;
T_3 V_29 ;
struct V_30 * V_31 = NULL ;
if ( V_25 == 0 || * V_26 >= V_32 )
return 0 ;
if ( V_25 > V_32 - * V_26 )
V_25 = V_32 - * V_26 ;
if ( * V_26 < V_33 ) {
V_28 = F_17 ( V_33 - ( T_2 ) * V_26 , V_25 ) ;
if ( F_14 ( V_24 , V_34 + * V_26 , V_28 , V_8 ) )
return - V_23 ;
V_25 -= V_28 ;
* V_26 += V_28 ;
V_24 += V_28 ;
V_27 += V_28 ;
if ( V_25 == 0 )
return V_27 ;
}
if ( * V_26 < V_33 + V_35 ) {
void * V_36 ;
V_28 = F_17 ( V_33 + V_35 - ( T_2 ) * V_26 , V_25 ) ;
V_36 = V_37 + * V_26 - V_33 ;
if ( F_14 ( V_24 , V_36 , V_28 , V_8 ) )
return - V_23 ;
V_25 -= V_28 ;
* V_26 += V_28 ;
V_24 += V_28 ;
V_27 += V_28 ;
if ( V_25 == 0 )
return V_27 ;
}
F_18 (m, &vmcore_list, list) {
if ( * V_26 < V_31 -> V_9 + V_31 -> V_15 ) {
V_28 = F_19 ( T_2 , V_31 -> V_9 + V_31 -> V_15 - * V_26 , V_25 ) ;
V_29 = V_31 -> V_38 + * V_26 - V_31 -> V_9 ;
V_12 = F_6 ( V_24 , V_28 , & V_29 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_25 -= V_28 ;
* V_26 += V_28 ;
V_24 += V_28 ;
V_27 += V_28 ;
if ( V_25 == 0 )
return V_27 ;
}
}
return V_27 ;
}
static T_1 F_20 ( struct V_39 * V_39 , char V_22 * V_24 ,
T_2 V_25 , T_5 * V_26 )
{
return F_16 ( ( V_40 char * ) V_24 , V_25 , V_26 , 1 ) ;
}
static int F_21 ( struct V_16 * V_17 , struct V_41 * V_42 )
{
#ifdef F_22
struct V_43 * V_44 = V_17 -> V_45 -> V_46 ;
T_6 V_47 = V_42 -> V_48 ;
struct V_49 * V_49 ;
T_5 V_9 ;
char * V_5 ;
int V_50 ;
V_49 = F_23 ( V_44 , V_47 , V_51 ) ;
if ( ! V_49 )
return V_52 ;
if ( ! F_24 ( V_49 ) ) {
V_9 = ( T_5 ) V_47 << V_53 ;
V_5 = F_25 ( ( F_26 ( V_49 ) << V_54 ) ) ;
V_50 = F_16 ( V_5 , V_13 , & V_9 , 0 ) ;
if ( V_50 < 0 ) {
F_27 ( V_49 ) ;
F_28 ( V_49 ) ;
return ( V_50 == - V_55 ) ? V_52 : V_56 ;
}
F_29 ( V_49 ) ;
}
F_27 ( V_49 ) ;
V_42 -> V_49 = V_49 ;
return 0 ;
#else
return V_56 ;
#endif
}
static inline char * F_30 ( T_2 V_57 )
{
#ifdef F_31
return F_32 ( V_57 ) ;
#else
return F_33 ( V_57 ) ;
#endif
}
static int F_34 ( struct V_39 * V_39 , struct V_16 * V_17 )
{
T_2 V_15 = V_17 -> V_58 - V_17 -> V_59 ;
T_3 V_29 , V_60 , V_61 , V_28 ;
struct V_30 * V_31 ;
V_29 = ( T_3 ) V_17 -> V_62 << V_54 ;
V_60 = V_29 + V_15 ;
if ( V_15 > V_32 || V_60 > V_32 )
return - V_63 ;
if ( V_17 -> V_64 & ( V_65 | V_66 ) )
return - V_67 ;
V_17 -> V_64 &= ~ ( V_68 | V_69 ) ;
V_17 -> V_64 |= V_70 ;
V_17 -> V_71 = & V_72 ;
V_61 = 0 ;
if ( V_29 < V_33 ) {
T_3 V_1 ;
V_28 = F_17 ( V_33 - ( T_2 ) V_29 , V_15 ) ;
V_1 = F_35 ( V_34 + V_29 ) >> V_54 ;
if ( F_13 ( V_17 , V_17 -> V_59 , V_1 , V_28 ,
V_17 -> V_73 ) )
return - V_74 ;
V_15 -= V_28 ;
V_29 += V_28 ;
V_61 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
if ( V_29 < V_33 + V_35 ) {
void * V_36 ;
V_28 = F_17 ( V_33 + V_35 - ( T_2 ) V_29 , V_15 ) ;
V_36 = V_37 + V_29 - V_33 ;
if ( F_36 ( V_17 , V_17 -> V_59 + V_61 ,
V_36 , V_28 ) )
goto V_75;
V_15 -= V_28 ;
V_29 += V_28 ;
V_61 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
F_18 (m, &vmcore_list, list) {
if ( V_29 < V_31 -> V_9 + V_31 -> V_15 ) {
T_3 V_38 = 0 ;
V_28 = F_19 ( T_2 , V_31 -> V_9 + V_31 -> V_15 - V_29 , V_15 ) ;
V_38 = V_31 -> V_38 + V_29 - V_31 -> V_9 ;
if ( F_12 ( V_17 , V_17 -> V_59 + V_61 ,
V_38 >> V_54 , V_28 ,
V_17 -> V_73 ) )
goto V_75;
V_15 -= V_28 ;
V_29 += V_28 ;
V_61 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
}
return 0 ;
V_75:
F_37 ( V_17 -> V_76 , V_17 -> V_59 , V_61 ) ;
return - V_74 ;
}
static int F_34 ( struct V_39 * V_39 , struct V_16 * V_17 )
{
return - V_77 ;
}
static struct V_30 * T_7 F_38 ( void )
{
return F_39 ( sizeof( struct V_30 ) , V_51 ) ;
}
static T_3 T_7 F_40 ( T_2 V_78 , T_2 V_79 ,
struct V_80 * V_81 )
{
T_3 V_15 ;
struct V_30 * V_31 ;
V_15 = V_78 + V_79 ;
F_18 (m, vc_list, list) {
V_15 += V_31 -> V_15 ;
}
return V_15 ;
}
static int T_7 F_41 ( const T_8 * V_82 )
{
int V_83 , V_50 = 0 ;
T_9 * V_84 ;
T_10 * V_85 ;
V_84 = ( T_9 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
void * V_87 ;
T_3 V_9 , V_88 , V_89 , V_90 = 0 ;
if ( V_84 -> V_91 != V_92 )
continue;
V_88 = V_84 -> V_93 ;
V_9 = V_84 -> V_94 ;
V_87 = F_42 ( V_88 , V_51 ) ;
if ( ! V_87 )
return - V_55 ;
V_50 = F_11 ( V_87 , V_88 , & V_9 ) ;
if ( V_50 < 0 ) {
F_43 ( V_87 ) ;
return V_50 ;
}
V_85 = V_87 ;
while ( V_90 < V_88 ) {
if ( V_85 -> V_95 == 0 )
break;
V_89 = sizeof( T_10 ) +
( ( V_85 -> V_95 + 3 ) & ~ 3 ) +
( ( V_85 -> V_96 + 3 ) & ~ 3 ) ;
V_90 += V_89 ;
V_85 = ( T_10 * ) ( ( char * ) V_85 + V_89 ) ;
}
F_43 ( V_87 ) ;
V_84 -> V_93 = V_90 ;
}
return 0 ;
}
static int T_7 F_44 ( const T_8 * V_82 ,
int * V_97 , T_3 * V_98 )
{
int V_83 ;
T_9 * V_84 ;
* V_97 = * V_98 = 0 ;
V_84 = ( T_9 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
if ( V_84 -> V_91 != V_92 )
continue;
* V_97 += 1 ;
* V_98 += V_84 -> V_93 ;
}
return 0 ;
}
static int T_7 F_45 ( const T_8 * V_82 , char * V_99 )
{
int V_83 , V_50 = 0 ;
T_9 * V_84 ;
V_84 = ( T_9 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
T_3 V_9 ;
if ( V_84 -> V_91 != V_92 )
continue;
V_9 = V_84 -> V_94 ;
V_50 = F_11 ( V_99 , V_84 -> V_93 ,
& V_9 ) ;
if ( V_50 < 0 )
return V_50 ;
V_99 += V_84 -> V_93 ;
}
return 0 ;
}
static int T_7 F_46 ( char * V_100 , T_2 * V_78 ,
char * * V_99 , T_2 * V_57 )
{
int V_83 , V_97 = 0 , V_50 = 0 ;
char * V_12 ;
T_8 * V_82 ;
T_9 V_101 ;
T_3 V_102 = 0 , V_103 ;
V_82 = ( T_8 * ) V_100 ;
V_50 = F_41 ( V_82 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_44 ( V_82 , & V_97 , & V_102 ) ;
if ( V_50 < 0 )
return V_50 ;
* V_57 = F_47 ( V_102 , V_13 ) ;
* V_99 = F_30 ( * V_57 ) ;
if ( ! * V_99 )
return - V_55 ;
V_50 = F_45 ( V_82 , * V_99 ) ;
if ( V_50 < 0 )
return V_50 ;
V_101 . V_91 = V_92 ;
V_101 . V_104 = 0 ;
V_103 = sizeof( T_8 ) +
( V_82 -> V_86 - V_97 + 1 ) * sizeof( T_9 ) ;
V_101 . V_94 = F_47 ( V_103 , V_13 ) ;
V_101 . V_105 = V_101 . V_106 = 0 ;
V_101 . V_107 = V_101 . V_93 = V_102 ;
V_101 . V_108 = 0 ;
V_12 = V_100 + sizeof( T_8 ) ;
memcpy ( V_12 , & V_101 , sizeof( V_101 ) ) ;
V_12 += sizeof( V_101 ) ;
V_83 = ( V_97 - 1 ) * sizeof( T_9 ) ;
* V_78 = * V_78 - V_83 ;
memmove ( V_12 , V_12 + V_83 , ( ( * V_78 ) - sizeof( T_8 ) - sizeof( T_9 ) ) ) ;
memset ( V_100 + * V_78 , 0 , V_83 ) ;
* V_78 = F_47 ( * V_78 , V_13 ) ;
V_82 -> V_86 = V_82 -> V_86 - V_97 + 1 ;
return 0 ;
}
static int T_7 F_48 ( const T_11 * V_82 )
{
int V_83 , V_50 = 0 ;
T_12 * V_84 ;
T_13 * V_85 ;
V_84 = ( T_12 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
void * V_87 ;
T_3 V_9 , V_88 , V_89 , V_90 = 0 ;
if ( V_84 -> V_91 != V_92 )
continue;
V_88 = V_84 -> V_93 ;
V_9 = V_84 -> V_94 ;
V_87 = F_42 ( V_88 , V_51 ) ;
if ( ! V_87 )
return - V_55 ;
V_50 = F_11 ( V_87 , V_88 , & V_9 ) ;
if ( V_50 < 0 ) {
F_43 ( V_87 ) ;
return V_50 ;
}
V_85 = V_87 ;
while ( V_90 < V_88 ) {
if ( V_85 -> V_95 == 0 )
break;
V_89 = sizeof( T_13 ) +
( ( V_85 -> V_95 + 3 ) & ~ 3 ) +
( ( V_85 -> V_96 + 3 ) & ~ 3 ) ;
V_90 += V_89 ;
V_85 = ( T_13 * ) ( ( char * ) V_85 + V_89 ) ;
}
F_43 ( V_87 ) ;
V_84 -> V_93 = V_90 ;
}
return 0 ;
}
static int T_7 F_49 ( const T_11 * V_82 ,
int * V_97 , T_3 * V_98 )
{
int V_83 ;
T_12 * V_84 ;
* V_97 = * V_98 = 0 ;
V_84 = ( T_12 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
if ( V_84 -> V_91 != V_92 )
continue;
* V_97 += 1 ;
* V_98 += V_84 -> V_93 ;
}
return 0 ;
}
static int T_7 F_50 ( const T_11 * V_82 , char * V_99 )
{
int V_83 , V_50 = 0 ;
T_12 * V_84 ;
V_84 = ( T_12 * ) ( V_82 + 1 ) ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
T_3 V_9 ;
if ( V_84 -> V_91 != V_92 )
continue;
V_9 = V_84 -> V_94 ;
V_50 = F_11 ( V_99 , V_84 -> V_93 ,
& V_9 ) ;
if ( V_50 < 0 )
return V_50 ;
V_99 += V_84 -> V_93 ;
}
return 0 ;
}
static int T_7 F_51 ( char * V_100 , T_2 * V_78 ,
char * * V_99 , T_2 * V_57 )
{
int V_83 , V_97 = 0 , V_50 = 0 ;
char * V_12 ;
T_11 * V_82 ;
T_12 V_101 ;
T_3 V_102 = 0 , V_103 ;
V_82 = ( T_11 * ) V_100 ;
V_50 = F_48 ( V_82 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_49 ( V_82 , & V_97 , & V_102 ) ;
if ( V_50 < 0 )
return V_50 ;
* V_57 = F_47 ( V_102 , V_13 ) ;
* V_99 = F_30 ( * V_57 ) ;
if ( ! * V_99 )
return - V_55 ;
V_50 = F_50 ( V_82 , * V_99 ) ;
if ( V_50 < 0 )
return V_50 ;
V_101 . V_91 = V_92 ;
V_101 . V_104 = 0 ;
V_103 = sizeof( T_11 ) +
( V_82 -> V_86 - V_97 + 1 ) * sizeof( T_12 ) ;
V_101 . V_94 = F_47 ( V_103 , V_13 ) ;
V_101 . V_105 = V_101 . V_106 = 0 ;
V_101 . V_107 = V_101 . V_93 = V_102 ;
V_101 . V_108 = 0 ;
V_12 = V_100 + sizeof( T_11 ) ;
memcpy ( V_12 , & V_101 , sizeof( V_101 ) ) ;
V_12 += sizeof( V_101 ) ;
V_83 = ( V_97 - 1 ) * sizeof( T_12 ) ;
* V_78 = * V_78 - V_83 ;
memmove ( V_12 , V_12 + V_83 , ( ( * V_78 ) - sizeof( T_11 ) - sizeof( T_12 ) ) ) ;
memset ( V_100 + * V_78 , 0 , V_83 ) ;
* V_78 = F_47 ( * V_78 , V_13 ) ;
V_82 -> V_86 = V_82 -> V_86 - V_97 + 1 ;
return 0 ;
}
static int T_7 F_52 ( char * V_100 ,
T_2 V_78 ,
T_2 V_35 ,
struct V_80 * V_81 )
{
int V_83 ;
T_8 * V_82 ;
T_9 * V_84 ;
T_5 V_109 ;
struct V_30 * V_110 ;
V_82 = ( T_8 * ) V_100 ;
V_84 = ( T_9 * ) ( V_100 + sizeof( T_8 ) ) ;
V_109 = V_78 + V_35 ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
T_3 V_38 , V_29 , V_60 , V_15 ;
if ( V_84 -> V_91 != V_111 )
continue;
V_38 = V_84 -> V_94 ;
V_29 = F_53 ( V_38 , V_13 ) ;
V_60 = F_47 ( V_38 + V_84 -> V_93 , V_13 ) ;
V_15 = V_60 - V_29 ;
V_110 = F_38 () ;
if ( ! V_110 )
return - V_55 ;
V_110 -> V_38 = V_29 ;
V_110 -> V_15 = V_15 ;
F_54 ( & V_110 -> V_112 , V_81 ) ;
V_84 -> V_94 = V_109 + ( V_38 - V_29 ) ;
V_109 = V_109 + V_15 ;
}
return 0 ;
}
static int T_7 F_55 ( char * V_100 ,
T_2 V_78 ,
T_2 V_35 ,
struct V_80 * V_81 )
{
int V_83 ;
T_11 * V_82 ;
T_12 * V_84 ;
T_5 V_109 ;
struct V_30 * V_110 ;
V_82 = ( T_11 * ) V_100 ;
V_84 = ( T_12 * ) ( V_100 + sizeof( T_11 ) ) ;
V_109 = V_78 + V_35 ;
for ( V_83 = 0 ; V_83 < V_82 -> V_86 ; V_83 ++ , V_84 ++ ) {
T_3 V_38 , V_29 , V_60 , V_15 ;
if ( V_84 -> V_91 != V_111 )
continue;
V_38 = V_84 -> V_94 ;
V_29 = F_53 ( V_38 , V_13 ) ;
V_60 = F_47 ( V_38 + V_84 -> V_93 , V_13 ) ;
V_15 = V_60 - V_29 ;
V_110 = F_38 () ;
if ( ! V_110 )
return - V_55 ;
V_110 -> V_38 = V_29 ;
V_110 -> V_15 = V_15 ;
F_54 ( & V_110 -> V_112 , V_81 ) ;
V_84 -> V_94 = V_109 + ( V_38 - V_29 ) ;
V_109 = V_109 + V_15 ;
}
return 0 ;
}
static void T_7 F_56 ( T_2 V_78 , T_2 V_35 ,
struct V_80 * V_81 )
{
T_5 V_109 ;
struct V_30 * V_31 ;
V_109 = V_78 + V_35 ;
F_18 (m, vc_list, list) {
V_31 -> V_9 = V_109 ;
V_109 += V_31 -> V_15 ;
}
}
static void F_57 ( void )
{
F_58 ( ( unsigned long ) V_34 , F_59 ( V_113 ) ) ;
V_34 = NULL ;
F_60 ( V_37 ) ;
V_37 = NULL ;
}
static int T_7 F_61 ( void )
{
int V_50 = 0 ;
T_8 V_114 ;
T_3 V_14 ;
V_14 = V_115 ;
V_50 = F_10 ( ( char * ) & V_114 , sizeof( T_8 ) , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_114 . V_116 , V_117 , V_118 ) != 0 ||
( V_114 . V_119 != V_120 ) ||
! F_62 ( & V_114 ) ||
V_114 . V_116 [ V_121 ] != V_122 ||
V_114 . V_116 [ V_123 ] != V_124 ||
V_114 . V_125 != V_124 ||
V_114 . V_126 != sizeof( T_8 ) ||
V_114 . V_127 != sizeof( T_9 ) ||
V_114 . V_86 == 0 ) {
F_63 ( L_1 ) ;
return - V_63 ;
}
V_113 = sizeof( T_8 ) +
V_114 . V_86 * sizeof( T_9 ) ;
V_33 = V_113 ;
V_34 = ( void * ) F_64 ( V_51 | V_128 ,
F_59 ( V_113 ) ) ;
if ( ! V_34 )
return - V_55 ;
V_14 = V_115 ;
V_50 = F_10 ( V_34 , V_113 , & V_14 ) ;
if ( V_50 < 0 )
goto V_75;
V_50 = F_46 ( V_34 , & V_33 ,
& V_37 , & V_35 ) ;
if ( V_50 )
goto V_75;
V_50 = F_52 ( V_34 , V_33 ,
V_35 , & V_129 ) ;
if ( V_50 )
goto V_75;
F_56 ( V_33 , V_35 , & V_129 ) ;
return 0 ;
V_75:
F_57 () ;
return V_50 ;
}
static int T_7 F_65 ( void )
{
int V_50 = 0 ;
T_11 V_114 ;
T_3 V_14 ;
V_14 = V_115 ;
V_50 = F_10 ( ( char * ) & V_114 , sizeof( T_11 ) , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_114 . V_116 , V_117 , V_118 ) != 0 ||
( V_114 . V_119 != V_120 ) ||
! F_66 ( & V_114 ) ||
V_114 . V_116 [ V_121 ] != V_130 ||
V_114 . V_116 [ V_123 ] != V_124 ||
V_114 . V_125 != V_124 ||
V_114 . V_126 != sizeof( T_11 ) ||
V_114 . V_127 != sizeof( T_12 ) ||
V_114 . V_86 == 0 ) {
F_63 ( L_1 ) ;
return - V_63 ;
}
V_113 = sizeof( T_11 ) + V_114 . V_86 * sizeof( T_12 ) ;
V_33 = V_113 ;
V_34 = ( void * ) F_64 ( V_51 | V_128 ,
F_59 ( V_113 ) ) ;
if ( ! V_34 )
return - V_55 ;
V_14 = V_115 ;
V_50 = F_10 ( V_34 , V_113 , & V_14 ) ;
if ( V_50 < 0 )
goto V_75;
V_50 = F_51 ( V_34 , & V_33 ,
& V_37 , & V_35 ) ;
if ( V_50 )
goto V_75;
V_50 = F_55 ( V_34 , V_33 ,
V_35 , & V_129 ) ;
if ( V_50 )
goto V_75;
F_56 ( V_33 , V_35 , & V_129 ) ;
return 0 ;
V_75:
F_57 () ;
return V_50 ;
}
static int T_7 F_67 ( void )
{
unsigned char V_116 [ V_131 ] ;
T_3 V_14 ;
int V_50 = 0 ;
V_14 = V_115 ;
V_50 = F_10 ( V_116 , V_131 , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_116 , V_117 , V_118 ) != 0 ) {
F_63 ( L_2 ) ;
return - V_63 ;
}
if ( V_116 [ V_121 ] == V_122 ) {
V_50 = F_61 () ;
if ( V_50 )
return V_50 ;
} else if ( V_116 [ V_121 ] == V_130 ) {
V_50 = F_65 () ;
if ( V_50 )
return V_50 ;
} else {
F_63 ( L_1 ) ;
return - V_63 ;
}
V_32 = F_40 ( V_33 , V_35 ,
& V_129 ) ;
return 0 ;
}
static int T_7 F_68 ( void )
{
int V_50 = 0 ;
V_50 = F_8 ( & V_115 , & V_132 ) ;
if ( V_50 )
return V_50 ;
if ( ! ( F_69 () ) )
return V_50 ;
V_50 = F_67 () ;
if ( V_50 ) {
F_63 ( L_3 ) ;
return V_50 ;
}
F_9 ( V_115 ) ;
V_115 = V_133 ;
V_134 = F_70 ( L_4 , V_135 , NULL , & V_136 ) ;
if ( V_134 )
V_134 -> V_15 = V_32 ;
return 0 ;
}
void F_71 ( void )
{
struct V_80 * V_137 , * V_138 ;
if ( V_134 ) {
F_72 ( V_134 ) ;
V_134 = NULL ;
}
F_73 (pos, next, &vmcore_list) {
struct V_30 * V_31 ;
V_31 = F_74 ( V_137 , struct V_30 , V_112 ) ;
F_75 ( & V_31 -> V_112 ) ;
F_43 ( V_31 ) ;
}
F_57 () ;
}
