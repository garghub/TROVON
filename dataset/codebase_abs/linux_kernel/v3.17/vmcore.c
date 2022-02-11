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
static int F_34 ( struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_1 ,
unsigned long V_15 , T_4 V_19 )
{
unsigned long V_58 ;
unsigned long V_59 , V_60 , V_61 ;
unsigned long V_62 = F_35 ( 0 ) ;
T_2 V_63 = 0 ;
V_59 = V_1 ;
V_60 = V_1 + ( V_15 >> V_54 ) ;
for ( V_61 = V_59 ; V_61 < V_60 ; ++ V_61 ) {
if ( ! F_5 ( V_61 ) ) {
if ( V_61 > V_59 ) {
V_58 = ( V_61 - V_59 ) << V_54 ;
if ( F_12 ( V_17 , V_18 + V_63 ,
V_59 , V_58 ,
V_19 ) )
goto V_64;
V_63 += V_58 ;
}
if ( F_12 ( V_17 , V_18 + V_63 ,
V_62 ,
V_13 , V_19 ) )
goto V_64;
V_63 += V_13 ;
V_59 = V_61 + 1 ;
}
}
if ( V_61 > V_59 ) {
V_58 = ( V_61 - V_59 ) << V_54 ;
if ( F_12 ( V_17 , V_18 + V_63 , V_59 ,
V_58 , V_19 ) )
goto V_64;
}
return 0 ;
V_64:
F_36 ( V_17 -> V_65 , V_18 , V_63 ) ;
return - V_66 ;
}
static int F_37 ( struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_1 ,
unsigned long V_15 , T_4 V_19 )
{
if ( V_2 )
return F_34 ( V_17 , V_18 , V_1 , V_15 , V_19 ) ;
else
return F_12 ( V_17 , V_18 , V_1 , V_15 , V_19 ) ;
}
static int F_38 ( struct V_39 * V_39 , struct V_16 * V_17 )
{
T_2 V_15 = V_17 -> V_67 - V_17 -> V_68 ;
T_3 V_29 , V_69 , V_63 , V_28 ;
struct V_30 * V_31 ;
V_29 = ( T_3 ) V_17 -> V_70 << V_54 ;
V_69 = V_29 + V_15 ;
if ( V_15 > V_32 || V_69 > V_32 )
return - V_71 ;
if ( V_17 -> V_72 & ( V_73 | V_74 ) )
return - V_75 ;
V_17 -> V_72 &= ~ ( V_76 | V_77 ) ;
V_17 -> V_72 |= V_78 ;
V_17 -> V_79 = & V_80 ;
V_63 = 0 ;
if ( V_29 < V_33 ) {
T_3 V_1 ;
V_28 = F_17 ( V_33 - ( T_2 ) V_29 , V_15 ) ;
V_1 = F_39 ( V_34 + V_29 ) >> V_54 ;
if ( F_13 ( V_17 , V_17 -> V_68 , V_1 , V_28 ,
V_17 -> V_81 ) )
return - V_66 ;
V_15 -= V_28 ;
V_29 += V_28 ;
V_63 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
if ( V_29 < V_33 + V_35 ) {
void * V_36 ;
V_28 = F_17 ( V_33 + V_35 - ( T_2 ) V_29 , V_15 ) ;
V_36 = V_37 + V_29 - V_33 ;
if ( F_40 ( V_17 , V_17 -> V_68 + V_63 ,
V_36 , V_28 ) )
goto V_64;
V_15 -= V_28 ;
V_29 += V_28 ;
V_63 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
F_18 (m, &vmcore_list, list) {
if ( V_29 < V_31 -> V_9 + V_31 -> V_15 ) {
T_3 V_38 = 0 ;
V_28 = F_19 ( T_2 , V_31 -> V_9 + V_31 -> V_15 - V_29 , V_15 ) ;
V_38 = V_31 -> V_38 + V_29 - V_31 -> V_9 ;
if ( F_37 ( V_17 , V_17 -> V_68 + V_63 ,
V_38 >> V_54 , V_28 ,
V_17 -> V_81 ) )
goto V_64;
V_15 -= V_28 ;
V_29 += V_28 ;
V_63 += V_28 ;
if ( V_15 == 0 )
return 0 ;
}
}
return 0 ;
V_64:
F_36 ( V_17 -> V_65 , V_17 -> V_68 , V_63 ) ;
return - V_66 ;
}
static int F_38 ( struct V_39 * V_39 , struct V_16 * V_17 )
{
return - V_82 ;
}
static struct V_30 * T_7 F_41 ( void )
{
return F_42 ( sizeof( struct V_30 ) , V_51 ) ;
}
static T_3 T_7 F_43 ( T_2 V_83 , T_2 V_84 ,
struct V_85 * V_86 )
{
T_3 V_15 ;
struct V_30 * V_31 ;
V_15 = V_83 + V_84 ;
F_18 (m, vc_list, list) {
V_15 += V_31 -> V_15 ;
}
return V_15 ;
}
static int T_7 F_44 ( const T_8 * V_87 )
{
int V_88 , V_50 = 0 ;
T_9 * V_89 ;
T_10 * V_90 ;
V_89 = ( T_9 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
void * V_92 ;
T_3 V_9 , V_93 , V_94 , V_95 = 0 ;
if ( V_89 -> V_96 != V_97 )
continue;
V_93 = V_89 -> V_98 ;
V_9 = V_89 -> V_99 ;
V_92 = F_45 ( V_93 , V_51 ) ;
if ( ! V_92 )
return - V_55 ;
V_50 = F_11 ( V_92 , V_93 , & V_9 ) ;
if ( V_50 < 0 ) {
F_46 ( V_92 ) ;
return V_50 ;
}
V_90 = V_92 ;
while ( V_90 -> V_100 != 0 ) {
V_94 = sizeof( T_10 ) +
( ( V_90 -> V_100 + 3 ) & ~ 3 ) +
( ( V_90 -> V_101 + 3 ) & ~ 3 ) ;
if ( ( V_95 + V_94 ) > V_93 ) {
F_47 ( L_1 ,
V_90 -> V_100 , V_90 -> V_101 ) ;
break;
}
V_95 += V_94 ;
V_90 = ( T_10 * ) ( ( char * ) V_90 + V_94 ) ;
}
F_46 ( V_92 ) ;
V_89 -> V_98 = V_95 ;
if ( V_95 == 0 ) {
F_47 ( L_2 ) ;
}
}
return 0 ;
}
static int T_7 F_48 ( const T_8 * V_87 ,
int * V_102 , T_3 * V_103 )
{
int V_88 ;
T_9 * V_89 ;
* V_102 = * V_103 = 0 ;
V_89 = ( T_9 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
if ( V_89 -> V_96 != V_97 )
continue;
* V_102 += 1 ;
* V_103 += V_89 -> V_98 ;
}
return 0 ;
}
static int T_7 F_49 ( const T_8 * V_87 , char * V_104 )
{
int V_88 , V_50 = 0 ;
T_9 * V_89 ;
V_89 = ( T_9 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
T_3 V_9 ;
if ( V_89 -> V_96 != V_97 )
continue;
V_9 = V_89 -> V_99 ;
V_50 = F_11 ( V_104 , V_89 -> V_98 ,
& V_9 ) ;
if ( V_50 < 0 )
return V_50 ;
V_104 += V_89 -> V_98 ;
}
return 0 ;
}
static int T_7 F_50 ( char * V_105 , T_2 * V_83 ,
char * * V_104 , T_2 * V_57 )
{
int V_88 , V_102 = 0 , V_50 = 0 ;
char * V_12 ;
T_8 * V_87 ;
T_9 V_106 ;
T_3 V_107 = 0 , V_108 ;
V_87 = ( T_8 * ) V_105 ;
V_50 = F_44 ( V_87 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_48 ( V_87 , & V_102 , & V_107 ) ;
if ( V_50 < 0 )
return V_50 ;
* V_57 = F_51 ( V_107 , V_13 ) ;
* V_104 = F_30 ( * V_57 ) ;
if ( ! * V_104 )
return - V_55 ;
V_50 = F_49 ( V_87 , * V_104 ) ;
if ( V_50 < 0 )
return V_50 ;
V_106 . V_96 = V_97 ;
V_106 . V_109 = 0 ;
V_108 = sizeof( T_8 ) +
( V_87 -> V_91 - V_102 + 1 ) * sizeof( T_9 ) ;
V_106 . V_99 = F_51 ( V_108 , V_13 ) ;
V_106 . V_110 = V_106 . V_111 = 0 ;
V_106 . V_112 = V_106 . V_98 = V_107 ;
V_106 . V_113 = 0 ;
V_12 = V_105 + sizeof( T_8 ) ;
memcpy ( V_12 , & V_106 , sizeof( V_106 ) ) ;
V_12 += sizeof( V_106 ) ;
V_88 = ( V_102 - 1 ) * sizeof( T_9 ) ;
* V_83 = * V_83 - V_88 ;
memmove ( V_12 , V_12 + V_88 , ( ( * V_83 ) - sizeof( T_8 ) - sizeof( T_9 ) ) ) ;
memset ( V_105 + * V_83 , 0 , V_88 ) ;
* V_83 = F_51 ( * V_83 , V_13 ) ;
V_87 -> V_91 = V_87 -> V_91 - V_102 + 1 ;
return 0 ;
}
static int T_7 F_52 ( const T_11 * V_87 )
{
int V_88 , V_50 = 0 ;
T_12 * V_89 ;
T_13 * V_90 ;
V_89 = ( T_12 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
void * V_92 ;
T_3 V_9 , V_93 , V_94 , V_95 = 0 ;
if ( V_89 -> V_96 != V_97 )
continue;
V_93 = V_89 -> V_98 ;
V_9 = V_89 -> V_99 ;
V_92 = F_45 ( V_93 , V_51 ) ;
if ( ! V_92 )
return - V_55 ;
V_50 = F_11 ( V_92 , V_93 , & V_9 ) ;
if ( V_50 < 0 ) {
F_46 ( V_92 ) ;
return V_50 ;
}
V_90 = V_92 ;
while ( V_90 -> V_100 != 0 ) {
V_94 = sizeof( T_13 ) +
( ( V_90 -> V_100 + 3 ) & ~ 3 ) +
( ( V_90 -> V_101 + 3 ) & ~ 3 ) ;
if ( ( V_95 + V_94 ) > V_93 ) {
F_47 ( L_1 ,
V_90 -> V_100 , V_90 -> V_101 ) ;
break;
}
V_95 += V_94 ;
V_90 = ( T_13 * ) ( ( char * ) V_90 + V_94 ) ;
}
F_46 ( V_92 ) ;
V_89 -> V_98 = V_95 ;
if ( V_95 == 0 ) {
F_47 ( L_2 ) ;
}
}
return 0 ;
}
static int T_7 F_53 ( const T_11 * V_87 ,
int * V_102 , T_3 * V_103 )
{
int V_88 ;
T_12 * V_89 ;
* V_102 = * V_103 = 0 ;
V_89 = ( T_12 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
if ( V_89 -> V_96 != V_97 )
continue;
* V_102 += 1 ;
* V_103 += V_89 -> V_98 ;
}
return 0 ;
}
static int T_7 F_54 ( const T_11 * V_87 , char * V_104 )
{
int V_88 , V_50 = 0 ;
T_12 * V_89 ;
V_89 = ( T_12 * ) ( V_87 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
T_3 V_9 ;
if ( V_89 -> V_96 != V_97 )
continue;
V_9 = V_89 -> V_99 ;
V_50 = F_11 ( V_104 , V_89 -> V_98 ,
& V_9 ) ;
if ( V_50 < 0 )
return V_50 ;
V_104 += V_89 -> V_98 ;
}
return 0 ;
}
static int T_7 F_55 ( char * V_105 , T_2 * V_83 ,
char * * V_104 , T_2 * V_57 )
{
int V_88 , V_102 = 0 , V_50 = 0 ;
char * V_12 ;
T_11 * V_87 ;
T_12 V_106 ;
T_3 V_107 = 0 , V_108 ;
V_87 = ( T_11 * ) V_105 ;
V_50 = F_52 ( V_87 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_53 ( V_87 , & V_102 , & V_107 ) ;
if ( V_50 < 0 )
return V_50 ;
* V_57 = F_51 ( V_107 , V_13 ) ;
* V_104 = F_30 ( * V_57 ) ;
if ( ! * V_104 )
return - V_55 ;
V_50 = F_54 ( V_87 , * V_104 ) ;
if ( V_50 < 0 )
return V_50 ;
V_106 . V_96 = V_97 ;
V_106 . V_109 = 0 ;
V_108 = sizeof( T_11 ) +
( V_87 -> V_91 - V_102 + 1 ) * sizeof( T_12 ) ;
V_106 . V_99 = F_51 ( V_108 , V_13 ) ;
V_106 . V_110 = V_106 . V_111 = 0 ;
V_106 . V_112 = V_106 . V_98 = V_107 ;
V_106 . V_113 = 0 ;
V_12 = V_105 + sizeof( T_11 ) ;
memcpy ( V_12 , & V_106 , sizeof( V_106 ) ) ;
V_12 += sizeof( V_106 ) ;
V_88 = ( V_102 - 1 ) * sizeof( T_12 ) ;
* V_83 = * V_83 - V_88 ;
memmove ( V_12 , V_12 + V_88 , ( ( * V_83 ) - sizeof( T_11 ) - sizeof( T_12 ) ) ) ;
memset ( V_105 + * V_83 , 0 , V_88 ) ;
* V_83 = F_51 ( * V_83 , V_13 ) ;
V_87 -> V_91 = V_87 -> V_91 - V_102 + 1 ;
return 0 ;
}
static int T_7 F_56 ( char * V_105 ,
T_2 V_83 ,
T_2 V_35 ,
struct V_85 * V_86 )
{
int V_88 ;
T_8 * V_87 ;
T_9 * V_89 ;
T_5 V_114 ;
struct V_30 * V_115 ;
V_87 = ( T_8 * ) V_105 ;
V_89 = ( T_9 * ) ( V_105 + sizeof( T_8 ) ) ;
V_114 = V_83 + V_35 ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
T_3 V_38 , V_29 , V_69 , V_15 ;
if ( V_89 -> V_96 != V_116 )
continue;
V_38 = V_89 -> V_99 ;
V_29 = F_57 ( V_38 , V_13 ) ;
V_69 = F_51 ( V_38 + V_89 -> V_98 , V_13 ) ;
V_15 = V_69 - V_29 ;
V_115 = F_41 () ;
if ( ! V_115 )
return - V_55 ;
V_115 -> V_38 = V_29 ;
V_115 -> V_15 = V_15 ;
F_58 ( & V_115 -> V_117 , V_86 ) ;
V_89 -> V_99 = V_114 + ( V_38 - V_29 ) ;
V_114 = V_114 + V_15 ;
}
return 0 ;
}
static int T_7 F_59 ( char * V_105 ,
T_2 V_83 ,
T_2 V_35 ,
struct V_85 * V_86 )
{
int V_88 ;
T_11 * V_87 ;
T_12 * V_89 ;
T_5 V_114 ;
struct V_30 * V_115 ;
V_87 = ( T_11 * ) V_105 ;
V_89 = ( T_12 * ) ( V_105 + sizeof( T_11 ) ) ;
V_114 = V_83 + V_35 ;
for ( V_88 = 0 ; V_88 < V_87 -> V_91 ; V_88 ++ , V_89 ++ ) {
T_3 V_38 , V_29 , V_69 , V_15 ;
if ( V_89 -> V_96 != V_116 )
continue;
V_38 = V_89 -> V_99 ;
V_29 = F_57 ( V_38 , V_13 ) ;
V_69 = F_51 ( V_38 + V_89 -> V_98 , V_13 ) ;
V_15 = V_69 - V_29 ;
V_115 = F_41 () ;
if ( ! V_115 )
return - V_55 ;
V_115 -> V_38 = V_29 ;
V_115 -> V_15 = V_15 ;
F_58 ( & V_115 -> V_117 , V_86 ) ;
V_89 -> V_99 = V_114 + ( V_38 - V_29 ) ;
V_114 = V_114 + V_15 ;
}
return 0 ;
}
static void T_7 F_60 ( T_2 V_83 , T_2 V_35 ,
struct V_85 * V_86 )
{
T_5 V_114 ;
struct V_30 * V_31 ;
V_114 = V_83 + V_35 ;
F_18 (m, vc_list, list) {
V_31 -> V_9 = V_114 ;
V_114 += V_31 -> V_15 ;
}
}
static void F_61 ( void )
{
F_62 ( ( unsigned long ) V_34 , F_63 ( V_118 ) ) ;
V_34 = NULL ;
F_64 ( V_37 ) ;
V_37 = NULL ;
}
static int T_7 F_65 ( void )
{
int V_50 = 0 ;
T_8 V_119 ;
T_3 V_14 ;
V_14 = V_120 ;
V_50 = F_10 ( ( char * ) & V_119 , sizeof( T_8 ) , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_119 . V_121 , V_122 , V_123 ) != 0 ||
( V_119 . V_124 != V_125 ) ||
! F_66 ( & V_119 ) ||
V_119 . V_121 [ V_126 ] != V_127 ||
V_119 . V_121 [ V_128 ] != V_129 ||
V_119 . V_130 != V_129 ||
V_119 . V_131 != sizeof( T_8 ) ||
V_119 . V_132 != sizeof( T_9 ) ||
V_119 . V_91 == 0 ) {
F_47 ( L_3 ) ;
return - V_71 ;
}
V_118 = sizeof( T_8 ) +
V_119 . V_91 * sizeof( T_9 ) ;
V_33 = V_118 ;
V_34 = ( void * ) F_67 ( V_51 | V_133 ,
F_63 ( V_118 ) ) ;
if ( ! V_34 )
return - V_55 ;
V_14 = V_120 ;
V_50 = F_10 ( V_34 , V_118 , & V_14 ) ;
if ( V_50 < 0 )
goto V_64;
V_50 = F_50 ( V_34 , & V_33 ,
& V_37 , & V_35 ) ;
if ( V_50 )
goto V_64;
V_50 = F_56 ( V_34 , V_33 ,
V_35 , & V_134 ) ;
if ( V_50 )
goto V_64;
F_60 ( V_33 , V_35 , & V_134 ) ;
return 0 ;
V_64:
F_61 () ;
return V_50 ;
}
static int T_7 F_68 ( void )
{
int V_50 = 0 ;
T_11 V_119 ;
T_3 V_14 ;
V_14 = V_120 ;
V_50 = F_10 ( ( char * ) & V_119 , sizeof( T_11 ) , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_119 . V_121 , V_122 , V_123 ) != 0 ||
( V_119 . V_124 != V_125 ) ||
! F_69 ( & V_119 ) ||
V_119 . V_121 [ V_126 ] != V_135 ||
V_119 . V_121 [ V_128 ] != V_129 ||
V_119 . V_130 != V_129 ||
V_119 . V_131 != sizeof( T_11 ) ||
V_119 . V_132 != sizeof( T_12 ) ||
V_119 . V_91 == 0 ) {
F_47 ( L_3 ) ;
return - V_71 ;
}
V_118 = sizeof( T_11 ) + V_119 . V_91 * sizeof( T_12 ) ;
V_33 = V_118 ;
V_34 = ( void * ) F_67 ( V_51 | V_133 ,
F_63 ( V_118 ) ) ;
if ( ! V_34 )
return - V_55 ;
V_14 = V_120 ;
V_50 = F_10 ( V_34 , V_118 , & V_14 ) ;
if ( V_50 < 0 )
goto V_64;
V_50 = F_55 ( V_34 , & V_33 ,
& V_37 , & V_35 ) ;
if ( V_50 )
goto V_64;
V_50 = F_59 ( V_34 , V_33 ,
V_35 , & V_134 ) ;
if ( V_50 )
goto V_64;
F_60 ( V_33 , V_35 , & V_134 ) ;
return 0 ;
V_64:
F_61 () ;
return V_50 ;
}
static int T_7 F_70 ( void )
{
unsigned char V_121 [ V_136 ] ;
T_3 V_14 ;
int V_50 = 0 ;
V_14 = V_120 ;
V_50 = F_10 ( V_121 , V_136 , & V_14 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( memcmp ( V_121 , V_122 , V_123 ) != 0 ) {
F_47 ( L_4 ) ;
return - V_71 ;
}
if ( V_121 [ V_126 ] == V_127 ) {
V_50 = F_65 () ;
if ( V_50 )
return V_50 ;
} else if ( V_121 [ V_126 ] == V_135 ) {
V_50 = F_68 () ;
if ( V_50 )
return V_50 ;
} else {
F_47 ( L_3 ) ;
return - V_71 ;
}
V_32 = F_43 ( V_33 , V_35 ,
& V_134 ) ;
return 0 ;
}
static int T_7 F_71 ( void )
{
int V_50 = 0 ;
V_50 = F_8 ( & V_120 , & V_137 ) ;
if ( V_50 )
return V_50 ;
if ( ! ( F_72 () ) )
return V_50 ;
V_50 = F_70 () ;
if ( V_50 ) {
F_47 ( L_5 ) ;
return V_50 ;
}
F_9 ( V_120 ) ;
V_120 = V_138 ;
V_139 = F_73 ( L_6 , V_140 , NULL , & V_141 ) ;
if ( V_139 )
V_139 -> V_15 = V_32 ;
return 0 ;
}
void F_74 ( void )
{
struct V_85 * V_61 , * V_142 ;
if ( V_139 ) {
F_75 ( V_139 ) ;
V_139 = NULL ;
}
F_76 (pos, next, &vmcore_list) {
struct V_30 * V_31 ;
V_31 = F_77 ( V_61 , struct V_30 , V_117 ) ;
F_78 ( & V_31 -> V_117 ) ;
F_46 ( V_31 ) ;
}
F_61 () ;
}
