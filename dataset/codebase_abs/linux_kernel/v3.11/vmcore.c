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
static T_1 F_8 ( struct V_14 * V_14 , char T_4 * V_15 ,
T_2 V_16 , T_5 * V_17 )
{
T_1 V_18 = 0 , V_12 ;
T_2 V_19 ;
T_3 V_20 ;
struct V_21 * V_22 = NULL ;
if ( V_16 == 0 || * V_17 >= V_23 )
return 0 ;
if ( V_16 > V_23 - * V_17 )
V_16 = V_23 - * V_17 ;
if ( * V_17 < V_24 ) {
V_19 = F_9 ( V_24 - ( T_2 ) * V_17 , V_16 ) ;
if ( F_10 ( V_15 , V_25 + * V_17 , V_19 ) )
return - V_26 ;
V_16 -= V_19 ;
* V_17 += V_19 ;
V_15 += V_19 ;
V_18 += V_19 ;
if ( V_16 == 0 )
return V_18 ;
}
if ( * V_17 < V_24 + V_27 ) {
void * V_28 ;
V_19 = F_9 ( V_24 + V_27 - ( T_2 ) * V_17 , V_16 ) ;
V_28 = V_29 + * V_17 - V_24 ;
if ( F_10 ( V_15 , V_28 , V_19 ) )
return - V_26 ;
V_16 -= V_19 ;
* V_17 += V_19 ;
V_15 += V_19 ;
V_18 += V_19 ;
if ( V_16 == 0 )
return V_18 ;
}
F_11 (m, &vmcore_list, list) {
if ( * V_17 < V_22 -> V_9 + V_22 -> V_30 ) {
V_19 = F_12 ( T_2 , V_22 -> V_9 + V_22 -> V_30 - * V_17 , V_16 ) ;
V_20 = V_22 -> V_31 + * V_17 - V_22 -> V_9 ;
V_12 = F_6 ( V_15 , V_19 , & V_20 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_16 -= V_19 ;
* V_17 += V_19 ;
V_15 += V_19 ;
V_18 += V_19 ;
if ( V_16 == 0 )
return V_18 ;
}
}
return V_18 ;
}
static inline char * F_13 ( T_2 V_32 )
{
#ifdef F_14
return F_15 ( V_32 ) ;
#else
return F_16 ( V_32 ) ;
#endif
}
static int F_17 ( struct V_14 * V_14 , struct V_33 * V_34 )
{
T_2 V_30 = V_34 -> V_35 - V_34 -> V_36 ;
T_3 V_20 , V_37 , V_38 , V_19 ;
struct V_21 * V_22 ;
V_20 = ( T_3 ) V_34 -> V_39 << V_40 ;
V_37 = V_20 + V_30 ;
if ( V_30 > V_23 || V_37 > V_23 )
return - V_41 ;
if ( V_34 -> V_42 & ( V_43 | V_44 ) )
return - V_45 ;
V_34 -> V_42 &= ~ ( V_46 | V_47 ) ;
V_34 -> V_42 |= V_48 ;
V_38 = 0 ;
if ( V_20 < V_24 ) {
T_3 V_1 ;
V_19 = F_9 ( V_24 - ( T_2 ) V_20 , V_30 ) ;
V_1 = F_18 ( V_25 + V_20 ) >> V_40 ;
if ( F_19 ( V_34 , V_34 -> V_36 , V_1 , V_19 ,
V_34 -> V_49 ) )
return - V_50 ;
V_30 -= V_19 ;
V_20 += V_19 ;
V_38 += V_19 ;
if ( V_30 == 0 )
return 0 ;
}
if ( V_20 < V_24 + V_27 ) {
void * V_28 ;
V_19 = F_9 ( V_24 + V_27 - ( T_2 ) V_20 , V_30 ) ;
V_28 = V_29 + V_20 - V_24 ;
if ( F_20 ( V_34 , V_34 -> V_36 + V_38 ,
V_28 , V_19 ) )
goto V_51;
V_30 -= V_19 ;
V_20 += V_19 ;
V_38 += V_19 ;
if ( V_30 == 0 )
return 0 ;
}
F_11 (m, &vmcore_list, list) {
if ( V_20 < V_22 -> V_9 + V_22 -> V_30 ) {
T_3 V_31 = 0 ;
V_19 = F_12 ( T_2 , V_22 -> V_9 + V_22 -> V_30 - V_20 , V_30 ) ;
V_31 = V_22 -> V_31 + V_20 - V_22 -> V_9 ;
if ( F_19 ( V_34 , V_34 -> V_36 + V_38 ,
V_31 >> V_40 , V_19 ,
V_34 -> V_49 ) )
goto V_51;
V_30 -= V_19 ;
V_20 += V_19 ;
V_38 += V_19 ;
if ( V_30 == 0 )
return 0 ;
}
}
return 0 ;
V_51:
F_21 ( V_34 -> V_52 , V_34 -> V_36 , V_38 ) ;
return - V_50 ;
}
static int F_17 ( struct V_14 * V_14 , struct V_33 * V_34 )
{
return - V_53 ;
}
static struct V_21 * T_6 F_22 ( void )
{
return F_23 ( sizeof( struct V_21 ) , V_54 ) ;
}
static T_3 T_6 F_24 ( T_2 V_55 , T_2 V_56 ,
struct V_57 * V_58 )
{
T_3 V_30 ;
struct V_21 * V_22 ;
V_30 = V_55 + V_56 ;
F_11 (m, vc_list, list) {
V_30 += V_22 -> V_30 ;
}
return V_30 ;
}
static int T_6 F_25 ( const T_7 * V_59 )
{
int V_60 , V_61 = 0 ;
T_8 * V_62 ;
T_9 * V_63 ;
V_62 = ( T_8 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
void * V_65 ;
T_3 V_9 , V_66 , V_67 , V_68 = 0 ;
if ( V_62 -> V_69 != V_70 )
continue;
V_66 = V_62 -> V_71 ;
V_9 = V_62 -> V_72 ;
V_65 = F_26 ( V_66 , V_54 ) ;
if ( ! V_65 )
return - V_73 ;
V_61 = F_6 ( V_65 , V_66 , & V_9 , 0 ) ;
if ( V_61 < 0 ) {
F_27 ( V_65 ) ;
return V_61 ;
}
V_63 = V_65 ;
while ( V_68 < V_66 ) {
if ( V_63 -> V_74 == 0 )
break;
V_67 = sizeof( T_9 ) +
( ( V_63 -> V_74 + 3 ) & ~ 3 ) +
( ( V_63 -> V_75 + 3 ) & ~ 3 ) ;
V_68 += V_67 ;
V_63 = ( T_9 * ) ( ( char * ) V_63 + V_67 ) ;
}
F_27 ( V_65 ) ;
V_62 -> V_71 = V_68 ;
}
return 0 ;
}
static int T_6 F_28 ( const T_7 * V_59 ,
int * V_76 , T_3 * V_77 )
{
int V_60 ;
T_8 * V_62 ;
* V_76 = * V_77 = 0 ;
V_62 = ( T_8 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
if ( V_62 -> V_69 != V_70 )
continue;
* V_76 += 1 ;
* V_77 += V_62 -> V_71 ;
}
return 0 ;
}
static int T_6 F_29 ( const T_7 * V_59 , char * V_78 )
{
int V_60 , V_61 = 0 ;
T_8 * V_62 ;
V_62 = ( T_8 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
T_3 V_9 ;
if ( V_62 -> V_69 != V_70 )
continue;
V_9 = V_62 -> V_72 ;
V_61 = F_6 ( V_78 , V_62 -> V_71 , & V_9 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
V_78 += V_62 -> V_71 ;
}
return 0 ;
}
static int T_6 F_30 ( char * V_79 , T_2 * V_55 ,
char * * V_78 , T_2 * V_32 )
{
int V_60 , V_76 = 0 , V_61 = 0 ;
char * V_12 ;
T_7 * V_59 ;
T_8 V_80 ;
T_3 V_81 = 0 , V_82 ;
V_59 = ( T_7 * ) V_79 ;
V_61 = F_25 ( V_59 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_28 ( V_59 , & V_76 , & V_81 ) ;
if ( V_61 < 0 )
return V_61 ;
* V_32 = F_31 ( V_81 , V_13 ) ;
* V_78 = F_13 ( * V_32 ) ;
if ( ! * V_78 )
return - V_73 ;
V_61 = F_29 ( V_59 , * V_78 ) ;
if ( V_61 < 0 )
return V_61 ;
V_80 . V_69 = V_70 ;
V_80 . V_83 = 0 ;
V_82 = sizeof( T_7 ) +
( V_59 -> V_64 - V_76 + 1 ) * sizeof( T_8 ) ;
V_80 . V_72 = F_31 ( V_82 , V_13 ) ;
V_80 . V_84 = V_80 . V_85 = 0 ;
V_80 . V_86 = V_80 . V_71 = V_81 ;
V_80 . V_87 = 0 ;
V_12 = V_79 + sizeof( T_7 ) ;
memcpy ( V_12 , & V_80 , sizeof( V_80 ) ) ;
V_12 += sizeof( V_80 ) ;
V_60 = ( V_76 - 1 ) * sizeof( T_8 ) ;
* V_55 = * V_55 - V_60 ;
memmove ( V_12 , V_12 + V_60 , ( ( * V_55 ) - sizeof( T_7 ) - sizeof( T_8 ) ) ) ;
memset ( V_79 + * V_55 , 0 , V_60 ) ;
* V_55 = F_31 ( * V_55 , V_13 ) ;
V_59 -> V_64 = V_59 -> V_64 - V_76 + 1 ;
return 0 ;
}
static int T_6 F_32 ( const T_10 * V_59 )
{
int V_60 , V_61 = 0 ;
T_11 * V_62 ;
T_12 * V_63 ;
V_62 = ( T_11 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
void * V_65 ;
T_3 V_9 , V_66 , V_67 , V_68 = 0 ;
if ( V_62 -> V_69 != V_70 )
continue;
V_66 = V_62 -> V_71 ;
V_9 = V_62 -> V_72 ;
V_65 = F_26 ( V_66 , V_54 ) ;
if ( ! V_65 )
return - V_73 ;
V_61 = F_6 ( V_65 , V_66 , & V_9 , 0 ) ;
if ( V_61 < 0 ) {
F_27 ( V_65 ) ;
return V_61 ;
}
V_63 = V_65 ;
while ( V_68 < V_66 ) {
if ( V_63 -> V_74 == 0 )
break;
V_67 = sizeof( T_12 ) +
( ( V_63 -> V_74 + 3 ) & ~ 3 ) +
( ( V_63 -> V_75 + 3 ) & ~ 3 ) ;
V_68 += V_67 ;
V_63 = ( T_12 * ) ( ( char * ) V_63 + V_67 ) ;
}
F_27 ( V_65 ) ;
V_62 -> V_71 = V_68 ;
}
return 0 ;
}
static int T_6 F_33 ( const T_10 * V_59 ,
int * V_76 , T_3 * V_77 )
{
int V_60 ;
T_11 * V_62 ;
* V_76 = * V_77 = 0 ;
V_62 = ( T_11 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
if ( V_62 -> V_69 != V_70 )
continue;
* V_76 += 1 ;
* V_77 += V_62 -> V_71 ;
}
return 0 ;
}
static int T_6 F_34 ( const T_10 * V_59 , char * V_78 )
{
int V_60 , V_61 = 0 ;
T_11 * V_62 ;
V_62 = ( T_11 * ) ( V_59 + 1 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
T_3 V_9 ;
if ( V_62 -> V_69 != V_70 )
continue;
V_9 = V_62 -> V_72 ;
V_61 = F_6 ( V_78 , V_62 -> V_71 , & V_9 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
V_78 += V_62 -> V_71 ;
}
return 0 ;
}
static int T_6 F_35 ( char * V_79 , T_2 * V_55 ,
char * * V_78 , T_2 * V_32 )
{
int V_60 , V_76 = 0 , V_61 = 0 ;
char * V_12 ;
T_10 * V_59 ;
T_11 V_80 ;
T_3 V_81 = 0 , V_82 ;
V_59 = ( T_10 * ) V_79 ;
V_61 = F_32 ( V_59 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_33 ( V_59 , & V_76 , & V_81 ) ;
if ( V_61 < 0 )
return V_61 ;
* V_32 = F_31 ( V_81 , V_13 ) ;
* V_78 = F_13 ( * V_32 ) ;
if ( ! * V_78 )
return - V_73 ;
V_61 = F_34 ( V_59 , * V_78 ) ;
if ( V_61 < 0 )
return V_61 ;
V_80 . V_69 = V_70 ;
V_80 . V_83 = 0 ;
V_82 = sizeof( T_10 ) +
( V_59 -> V_64 - V_76 + 1 ) * sizeof( T_11 ) ;
V_80 . V_72 = F_31 ( V_82 , V_13 ) ;
V_80 . V_84 = V_80 . V_85 = 0 ;
V_80 . V_86 = V_80 . V_71 = V_81 ;
V_80 . V_87 = 0 ;
V_12 = V_79 + sizeof( T_10 ) ;
memcpy ( V_12 , & V_80 , sizeof( V_80 ) ) ;
V_12 += sizeof( V_80 ) ;
V_60 = ( V_76 - 1 ) * sizeof( T_11 ) ;
* V_55 = * V_55 - V_60 ;
memmove ( V_12 , V_12 + V_60 , ( ( * V_55 ) - sizeof( T_10 ) - sizeof( T_11 ) ) ) ;
memset ( V_79 + * V_55 , 0 , V_60 ) ;
* V_55 = F_31 ( * V_55 , V_13 ) ;
V_59 -> V_64 = V_59 -> V_64 - V_76 + 1 ;
return 0 ;
}
static int T_6 F_36 ( char * V_79 ,
T_2 V_55 ,
T_2 V_27 ,
struct V_57 * V_58 )
{
int V_60 ;
T_7 * V_59 ;
T_8 * V_62 ;
T_5 V_88 ;
struct V_21 * V_89 ;
V_59 = ( T_7 * ) V_79 ;
V_62 = ( T_8 * ) ( V_79 + sizeof( T_7 ) ) ;
V_88 = V_55 + V_27 ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
T_3 V_31 , V_20 , V_37 , V_30 ;
if ( V_62 -> V_69 != V_90 )
continue;
V_31 = V_62 -> V_72 ;
V_20 = F_37 ( V_31 , V_13 ) ;
V_37 = F_31 ( V_31 + V_62 -> V_71 , V_13 ) ;
V_30 = V_37 - V_20 ;
V_89 = F_22 () ;
if ( ! V_89 )
return - V_73 ;
V_89 -> V_31 = V_20 ;
V_89 -> V_30 = V_30 ;
F_38 ( & V_89 -> V_91 , V_58 ) ;
V_62 -> V_72 = V_88 + ( V_31 - V_20 ) ;
V_88 = V_88 + V_30 ;
}
return 0 ;
}
static int T_6 F_39 ( char * V_79 ,
T_2 V_55 ,
T_2 V_27 ,
struct V_57 * V_58 )
{
int V_60 ;
T_10 * V_59 ;
T_11 * V_62 ;
T_5 V_88 ;
struct V_21 * V_89 ;
V_59 = ( T_10 * ) V_79 ;
V_62 = ( T_11 * ) ( V_79 + sizeof( T_10 ) ) ;
V_88 = V_55 + V_27 ;
for ( V_60 = 0 ; V_60 < V_59 -> V_64 ; V_60 ++ , V_62 ++ ) {
T_3 V_31 , V_20 , V_37 , V_30 ;
if ( V_62 -> V_69 != V_90 )
continue;
V_31 = V_62 -> V_72 ;
V_20 = F_37 ( V_31 , V_13 ) ;
V_37 = F_31 ( V_31 + V_62 -> V_71 , V_13 ) ;
V_30 = V_37 - V_20 ;
V_89 = F_22 () ;
if ( ! V_89 )
return - V_73 ;
V_89 -> V_31 = V_20 ;
V_89 -> V_30 = V_30 ;
F_38 ( & V_89 -> V_91 , V_58 ) ;
V_62 -> V_72 = V_88 + ( V_31 - V_20 ) ;
V_88 = V_88 + V_30 ;
}
return 0 ;
}
static void T_6 F_40 ( T_2 V_55 , T_2 V_27 ,
struct V_57 * V_58 )
{
T_5 V_88 ;
struct V_21 * V_22 ;
V_88 = V_55 + V_27 ;
F_11 (m, vc_list, list) {
V_22 -> V_9 = V_88 ;
V_88 += V_22 -> V_30 ;
}
}
static void F_41 ( void )
{
F_42 ( ( unsigned long ) V_25 , F_43 ( V_92 ) ) ;
V_25 = NULL ;
F_44 ( V_29 ) ;
V_29 = NULL ;
}
static int T_6 F_45 ( void )
{
int V_61 = 0 ;
T_7 V_93 ;
T_3 V_94 ;
V_94 = V_95 ;
V_61 = F_6 ( ( char * ) & V_93 , sizeof( T_7 ) , & V_94 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( memcmp ( V_93 . V_96 , V_97 , V_98 ) != 0 ||
( V_93 . V_99 != V_100 ) ||
! F_46 ( & V_93 ) ||
V_93 . V_96 [ V_101 ] != V_102 ||
V_93 . V_96 [ V_103 ] != V_104 ||
V_93 . V_105 != V_104 ||
V_93 . V_106 != sizeof( T_7 ) ||
V_93 . V_107 != sizeof( T_8 ) ||
V_93 . V_64 == 0 ) {
F_47 ( L_1 ) ;
return - V_41 ;
}
V_92 = sizeof( T_7 ) +
V_93 . V_64 * sizeof( T_8 ) ;
V_24 = V_92 ;
V_25 = ( void * ) F_48 ( V_54 | V_108 ,
F_43 ( V_92 ) ) ;
if ( ! V_25 )
return - V_73 ;
V_94 = V_95 ;
V_61 = F_6 ( V_25 , V_92 , & V_94 , 0 ) ;
if ( V_61 < 0 )
goto V_51;
V_61 = F_30 ( V_25 , & V_24 ,
& V_29 , & V_27 ) ;
if ( V_61 )
goto V_51;
V_61 = F_36 ( V_25 , V_24 ,
V_27 , & V_109 ) ;
if ( V_61 )
goto V_51;
F_40 ( V_24 , V_27 , & V_109 ) ;
return 0 ;
V_51:
F_41 () ;
return V_61 ;
}
static int T_6 F_49 ( void )
{
int V_61 = 0 ;
T_10 V_93 ;
T_3 V_94 ;
V_94 = V_95 ;
V_61 = F_6 ( ( char * ) & V_93 , sizeof( T_10 ) , & V_94 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( memcmp ( V_93 . V_96 , V_97 , V_98 ) != 0 ||
( V_93 . V_99 != V_100 ) ||
! F_50 ( & V_93 ) ||
V_93 . V_96 [ V_101 ] != V_110 ||
V_93 . V_96 [ V_103 ] != V_104 ||
V_93 . V_105 != V_104 ||
V_93 . V_106 != sizeof( T_10 ) ||
V_93 . V_107 != sizeof( T_11 ) ||
V_93 . V_64 == 0 ) {
F_47 ( L_1 ) ;
return - V_41 ;
}
V_92 = sizeof( T_10 ) + V_93 . V_64 * sizeof( T_11 ) ;
V_24 = V_92 ;
V_25 = ( void * ) F_48 ( V_54 | V_108 ,
F_43 ( V_92 ) ) ;
if ( ! V_25 )
return - V_73 ;
V_94 = V_95 ;
V_61 = F_6 ( V_25 , V_92 , & V_94 , 0 ) ;
if ( V_61 < 0 )
goto V_51;
V_61 = F_35 ( V_25 , & V_24 ,
& V_29 , & V_27 ) ;
if ( V_61 )
goto V_51;
V_61 = F_39 ( V_25 , V_24 ,
V_27 , & V_109 ) ;
if ( V_61 )
goto V_51;
F_40 ( V_24 , V_27 , & V_109 ) ;
return 0 ;
V_51:
F_41 () ;
return V_61 ;
}
static int T_6 F_51 ( void )
{
unsigned char V_96 [ V_111 ] ;
T_3 V_94 ;
int V_61 = 0 ;
V_94 = V_95 ;
V_61 = F_6 ( V_96 , V_111 , & V_94 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( memcmp ( V_96 , V_97 , V_98 ) != 0 ) {
F_47 ( L_2 ) ;
return - V_41 ;
}
if ( V_96 [ V_101 ] == V_102 ) {
V_61 = F_45 () ;
if ( V_61 )
return V_61 ;
} else if ( V_96 [ V_101 ] == V_110 ) {
V_61 = F_49 () ;
if ( V_61 )
return V_61 ;
} else {
F_47 ( L_1 ) ;
return - V_41 ;
}
V_23 = F_24 ( V_24 , V_27 ,
& V_109 ) ;
return 0 ;
}
static int T_6 F_52 ( void )
{
int V_61 = 0 ;
if ( ! ( F_53 () ) )
return V_61 ;
V_61 = F_51 () ;
if ( V_61 ) {
F_47 ( L_3 ) ;
return V_61 ;
}
V_112 = F_54 ( L_4 , V_113 , NULL , & V_114 ) ;
if ( V_112 )
V_112 -> V_30 = V_23 ;
return 0 ;
}
void F_55 ( void )
{
struct V_57 * V_115 , * V_116 ;
if ( V_112 ) {
F_56 ( V_112 ) ;
V_112 = NULL ;
}
F_57 (pos, next, &vmcore_list) {
struct V_21 * V_22 ;
V_22 = F_58 ( V_115 , struct V_21 , V_91 ) ;
F_59 ( & V_22 -> V_91 ) ;
F_27 ( V_22 ) ;
}
F_41 () ;
}
