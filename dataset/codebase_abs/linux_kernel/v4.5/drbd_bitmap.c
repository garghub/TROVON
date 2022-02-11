static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_2 ( & V_7 ) )
return;
F_3 ( V_2 , L_1 ,
V_8 -> V_9 , F_4 ( V_8 ) ,
V_3 , V_5 -> V_10 ? : L_2 ,
V_5 -> V_11 -> V_9 , F_4 ( V_5 -> V_11 ) ) ;
}
void F_5 ( struct V_1 * V_2 , char * V_12 , enum V_13 V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_15 ;
if ( ! V_5 ) {
F_3 ( V_2 , L_3 ) ;
return;
}
V_15 = ! F_6 ( & V_5 -> V_16 ) ;
if ( V_15 ) {
F_7 ( V_2 , L_4 ,
V_8 -> V_9 , F_4 ( V_8 ) ,
V_12 , V_5 -> V_10 ? : L_2 ,
V_5 -> V_11 -> V_9 , F_4 ( V_5 -> V_11 ) ) ;
F_8 ( & V_5 -> V_16 ) ;
}
if ( V_17 & V_5 -> V_18 )
F_3 ( V_2 , L_5 ) ;
V_5 -> V_18 |= V_14 & V_17 ;
V_5 -> V_10 = V_12 ;
V_5 -> V_11 = V_8 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_3 ( V_2 , L_6 ) ;
return;
}
if ( ! ( V_17 & V_2 -> V_6 -> V_18 ) )
F_3 ( V_2 , L_7 ) ;
V_5 -> V_18 &= ~ V_17 ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = NULL ;
F_10 ( & V_5 -> V_16 ) ;
}
static void F_11 ( struct V_19 * V_19 , unsigned long V_20 )
{
F_12 ( 0 != ( V_20 & ~ V_21 ) ) ;
F_13 ( V_19 , V_20 ) ;
}
static unsigned long F_14 ( struct V_19 * V_19 )
{
return F_15 ( V_19 ) & V_21 ;
}
static void F_16 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_23 = & F_15 ( V_5 -> V_24 [ V_22 ] ) ;
F_17 ( V_5 -> V_25 , ! F_18 ( V_26 , V_23 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_23 = & F_15 ( V_5 -> V_24 [ V_22 ] ) ;
F_20 ( V_26 , V_23 ) ;
F_21 ( & V_2 -> V_6 -> V_25 ) ;
}
static void F_22 ( struct V_19 * V_19 )
{
F_23 ( V_27 , & F_15 ( V_19 ) ) ;
F_23 ( V_28 , & F_15 ( V_19 ) ) ;
}
static void F_24 ( struct V_19 * V_19 )
{
F_25 ( V_27 , & F_15 ( V_19 ) ) ;
}
void F_26 ( struct V_1 * V_2 , int V_22 )
{
struct V_19 * V_19 ;
if ( V_22 >= V_2 -> V_6 -> V_29 ) {
F_7 ( V_2 , L_8 ,
V_22 , ( int ) V_2 -> V_6 -> V_29 ) ;
return;
}
V_19 = V_2 -> V_6 -> V_24 [ V_22 ] ;
F_25 ( V_30 , & F_15 ( V_19 ) ) ;
}
static int F_27 ( struct V_19 * V_19 )
{
volatile const unsigned long * V_23 = & F_15 ( V_19 ) ;
return ( * V_23 & ( ( 1UL << V_27 ) | ( 1UL << V_28 ) ) ) == 0 ;
}
static void F_28 ( struct V_19 * V_19 )
{
F_25 ( V_31 , & F_15 ( V_19 ) ) ;
}
static void F_29 ( struct V_19 * V_19 )
{
F_23 ( V_31 , & F_15 ( V_19 ) ) ;
}
static void F_30 ( struct V_19 * V_19 )
{
F_25 ( V_28 , & F_15 ( V_19 ) ) ;
}
static int F_31 ( struct V_19 * V_19 )
{
return F_32 ( V_28 , & F_15 ( V_19 ) ) ;
}
static unsigned int F_33 ( struct V_4 * V_5 , unsigned long V_32 )
{
unsigned int V_22 = V_32 >> ( V_33 - V_34 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_29 ) ;
return V_22 ;
}
static unsigned int F_34 ( struct V_4 * V_5 , T_1 V_35 )
{
unsigned int V_22 = V_35 >> ( V_33 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_29 ) ;
return V_22 ;
}
static unsigned long * F_35 ( struct V_4 * V_5 , unsigned int V_20 )
{
struct V_19 * V_19 = V_5 -> V_24 [ V_20 ] ;
return ( unsigned long * ) F_36 ( V_19 ) ;
}
static unsigned long * F_37 ( struct V_4 * V_5 , unsigned int V_20 )
{
return F_35 ( V_5 , V_20 ) ;
}
static void F_38 ( unsigned long * V_36 )
{
F_39 ( V_36 ) ;
}
static void F_40 ( unsigned long * V_36 )
{
return F_38 ( V_36 ) ;
}
static void F_41 ( struct V_19 * * V_37 , unsigned long V_38 )
{
unsigned long V_39 ;
if ( ! V_37 )
return;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
if ( ! V_37 [ V_39 ] ) {
F_42 ( L_9 ,
V_39 , V_38 ) ;
continue;
}
F_43 ( V_37 [ V_39 ] ) ;
V_37 [ V_39 ] = NULL ;
}
}
static inline void F_44 ( void * V_40 )
{
F_45 ( V_40 ) ;
}
static struct V_19 * * F_46 ( struct V_4 * V_5 , unsigned long V_41 )
{
struct V_19 * * V_42 = V_5 -> V_24 ;
struct V_19 * * V_43 , * V_19 ;
unsigned int V_39 , V_44 ;
unsigned long V_45 = V_5 -> V_29 ;
F_12 ( V_45 == 0 && V_42 != NULL ) ;
F_12 ( V_45 != 0 && V_42 == NULL ) ;
if ( V_45 == V_41 )
return V_42 ;
V_44 = sizeof( struct V_19 * ) * V_41 ;
V_43 = F_47 ( V_44 , V_46 | V_47 ) ;
if ( ! V_43 ) {
V_43 = F_48 ( V_44 ,
V_46 | V_48 | V_49 ,
V_50 ) ;
if ( ! V_43 )
return NULL ;
}
if ( V_41 >= V_45 ) {
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
V_43 [ V_39 ] = V_42 [ V_39 ] ;
for (; V_39 < V_41 ; V_39 ++ ) {
V_19 = F_49 ( V_46 | V_48 ) ;
if ( ! V_19 ) {
F_41 ( V_43 + V_45 , V_39 - V_45 ) ;
F_44 ( V_43 ) ;
return NULL ;
}
F_11 ( V_19 , V_39 ) ;
V_43 [ V_39 ] = V_19 ;
}
} else {
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ )
V_43 [ V_39 ] = V_42 [ V_39 ] ;
}
return V_43 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_51 ( V_5 != NULL ) ;
V_5 = F_47 ( sizeof( struct V_4 ) , V_51 ) ;
if ( ! V_5 )
return - V_52 ;
F_52 ( & V_5 -> V_53 ) ;
F_53 ( & V_5 -> V_16 ) ;
F_54 ( & V_5 -> V_25 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_55 ( struct V_1 * V_2 )
{
if ( ! F_56 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_54 ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( ! F_56 ( V_2 -> V_6 ) )
return;
F_41 ( V_2 -> V_6 -> V_24 , V_2 -> V_6 -> V_29 ) ;
F_44 ( V_2 -> V_6 -> V_24 ) ;
F_58 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned long V_55 ;
unsigned long * V_36 , * V_56 ;
int V_57 ;
int V_58 = 0 ;
V_57 = ( V_5 -> V_59 & V_60 ) ;
V_55 = ( 1UL << ( V_57 & V_61 ) ) - 1 ;
V_55 = F_60 ( V_55 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_56 = V_36 + ( V_57 / V_62 ) ;
if ( V_55 ) {
V_58 = F_61 ( * V_56 & ~ V_55 ) ;
* V_56 &= V_55 ;
V_56 ++ ;
}
if ( V_62 == 32 && ( ( V_56 - V_36 ) & 1 ) == 1 ) {
V_58 += F_61 ( * V_56 ) ;
* V_56 = 0 ;
}
F_40 ( V_36 ) ;
return V_58 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned long V_55 ;
unsigned long * V_36 , * V_56 ;
int V_57 ;
V_57 = ( V_5 -> V_59 & V_60 ) ;
V_55 = ( 1UL << ( V_57 & V_61 ) ) - 1 ;
V_55 = F_60 ( V_55 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_56 = V_36 + ( V_57 / V_62 ) ;
if ( V_55 ) {
* V_56 |= ~ V_55 ;
V_56 ++ ;
}
if ( V_62 == 32 && ( ( V_56 - V_36 ) & 1 ) == 1 ) {
* V_56 = ~ 0UL ;
}
F_40 ( V_36 ) ;
}
static unsigned long F_63 ( struct V_4 * V_5 )
{
unsigned long * V_36 ;
unsigned long V_63 = 0 ;
unsigned long V_55 = ( 1UL << ( V_5 -> V_59 & V_61 ) ) - 1 ;
int V_20 , V_64 ;
for ( V_20 = 0 ; V_20 < V_5 -> V_29 - 1 ; V_20 ++ ) {
V_36 = F_35 ( V_5 , V_20 ) ;
V_63 += F_64 ( V_36 , V_65 ) ;
F_38 ( V_36 ) ;
F_65 () ;
}
V_64 = ( ( V_5 -> V_59 - 1 ) & V_60 ) >> V_34 ;
V_36 = F_35 ( V_5 , V_20 ) ;
V_63 += F_64 ( V_36 , V_64 * V_62 ) ;
V_36 [ V_64 ] &= F_60 ( V_55 ) ;
V_63 += F_61 ( V_36 [ V_64 ] ) ;
if ( V_62 == 32 && ( V_64 & 1 ) == 0 )
V_36 [ V_64 + 1 ] = 0 ;
F_38 ( V_36 ) ;
return V_63 ;
}
static void F_66 ( struct V_4 * V_5 , T_3 V_66 , int V_67 , T_3 V_68 )
{
unsigned long * V_36 , * V_56 ;
unsigned int V_20 ;
T_3 V_69 , V_70 ;
V_70 = V_66 + V_68 ;
if ( V_70 > V_5 -> V_71 ) {
F_42 ( L_10 ) ;
return;
}
while ( V_66 < V_70 ) {
V_69 = F_67 ( T_3 , F_68 ( V_66 + 1 , V_72 ) , V_70 ) - V_66 ;
V_20 = F_33 ( V_5 , V_66 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_56 = V_36 + F_69 ( V_66 ) ;
if ( V_56 + V_69 > V_36 + V_72 ) {
F_42 ( L_11 ,
V_36 , V_56 , ( int ) V_69 ) ;
} else
memset ( V_56 , V_67 , V_69 * sizeof( long ) ) ;
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
V_66 += V_69 ;
}
}
static T_1 F_70 ( struct V_73 * V_74 )
{
T_1 V_75 ;
if ( V_74 -> V_76 . V_77 == 8 )
V_75 = V_74 -> V_76 . V_78 - V_74 -> V_76 . V_79 ;
else
V_75 = V_74 -> V_76 . V_77 - V_74 -> V_76 . V_79 ;
return V_75 << ( 9 + 3 ) ;
}
int F_71 ( struct V_1 * V_2 , T_2 V_80 , int V_81 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_63 , V_82 , V_83 , V_84 ;
unsigned long V_41 , V_45 , V_85 ;
struct V_19 * * V_86 , * * V_87 = NULL ;
int V_88 = 0 , V_89 ;
if ( ! F_56 ( V_5 ) )
return - V_52 ;
F_5 ( V_2 , L_12 , V_17 ) ;
F_72 ( V_2 , L_13 ,
( unsigned long long ) V_80 ) ;
if ( V_80 == V_5 -> V_54 )
goto V_90;
if ( V_80 == 0 ) {
F_73 ( & V_5 -> V_53 ) ;
V_87 = V_5 -> V_24 ;
V_85 = V_5 -> V_29 ;
V_83 = V_5 -> V_71 ;
V_5 -> V_24 = NULL ;
V_5 -> V_29 =
V_5 -> V_91 =
V_5 -> V_59 =
V_5 -> V_71 =
V_5 -> V_54 = 0 ;
F_74 ( & V_5 -> V_53 ) ;
F_41 ( V_87 , V_85 ) ;
F_44 ( V_87 ) ;
goto V_90;
}
V_63 = F_75 ( F_68 ( V_80 , V_92 ) ) ;
V_82 = F_68 ( V_63 , 64 ) >> V_34 ;
if ( F_76 ( V_2 ) ) {
T_1 V_93 = F_70 ( V_2 -> V_74 ) ;
F_77 ( V_2 ) ;
if ( V_63 > V_93 ) {
F_72 ( V_2 , L_14 , V_63 ) ;
F_72 ( V_2 , L_15 , V_93 ) ;
V_88 = - V_94 ;
goto V_90;
}
}
V_41 = F_68 ( V_82 * sizeof( long ) , V_95 ) >> V_33 ;
V_45 = V_5 -> V_29 ;
if ( V_41 == V_45 ) {
F_78 ( V_2 , V_5 -> V_24 != NULL ) ;
V_86 = V_5 -> V_24 ;
} else {
if ( F_79 ( V_2 , V_96 ) )
V_86 = NULL ;
else
V_86 = F_46 ( V_5 , V_41 ) ;
}
if ( ! V_86 ) {
V_88 = - V_52 ;
goto V_90;
}
F_73 ( & V_5 -> V_53 ) ;
V_87 = V_5 -> V_24 ;
V_83 = V_5 -> V_71 ;
V_84 = V_5 -> V_59 ;
V_89 = V_63 > V_84 ;
if ( V_87 && V_89 && V_81 )
F_62 ( V_5 ) ;
V_5 -> V_24 = V_86 ;
V_5 -> V_29 = V_41 ;
V_5 -> V_59 = V_63 ;
V_5 -> V_71 = V_82 ;
V_5 -> V_54 = V_80 ;
if ( V_89 ) {
if ( V_81 ) {
F_66 ( V_5 , V_83 , 0xff , V_82 - V_83 ) ;
V_5 -> V_91 += V_63 - V_84 ;
} else
F_66 ( V_5 , V_83 , 0x00 , V_82 - V_83 ) ;
}
if ( V_41 < V_45 ) {
F_41 ( V_87 + V_41 , V_45 - V_41 ) ;
}
( void ) F_59 ( V_5 ) ;
F_74 ( & V_5 -> V_53 ) ;
if ( V_87 != V_86 )
F_44 ( V_87 ) ;
if ( ! V_89 )
V_5 -> V_91 = F_63 ( V_5 ) ;
F_72 ( V_2 , L_16 , V_63 , V_82 , V_41 ) ;
V_90:
F_9 ( V_2 ) ;
return V_88 ;
}
unsigned long F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_97 ;
unsigned long V_14 ;
if ( ! F_56 ( V_5 ) )
return 0 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 0 ;
F_81 ( & V_5 -> V_53 , V_14 ) ;
V_97 = V_5 -> V_91 ;
F_82 ( & V_5 -> V_53 , V_14 ) ;
return V_97 ;
}
unsigned long F_83 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
if ( ! F_84 ( V_2 , V_98 ) )
return 0 ;
V_97 = F_80 ( V_2 ) ;
F_77 ( V_2 ) ;
return V_97 ;
}
T_3 F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_56 ( V_5 ) )
return 0 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 0 ;
return V_5 -> V_71 ;
}
unsigned long F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_56 ( V_5 ) )
return 0 ;
return V_5 -> V_59 ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_66 , T_3 V_38 ,
unsigned long * V_99 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_56 ;
unsigned long V_100 , V_63 ;
unsigned int V_20 ;
T_3 V_70 , V_69 ;
V_70 = V_66 + V_38 ;
if ( ! F_56 ( V_5 ) )
return;
if ( ! F_56 ( V_5 -> V_24 ) )
return;
if ( V_38 == 0 )
return;
F_51 ( V_66 >= V_5 -> V_71 ) ;
F_51 ( V_70 > V_5 -> V_71 ) ;
F_73 ( & V_5 -> V_53 ) ;
while ( V_66 < V_70 ) {
V_69 = F_67 ( T_3 , F_68 ( V_66 + 1 , V_72 ) , V_70 ) - V_66 ;
V_20 = F_33 ( V_5 , V_66 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_56 = V_36 + F_69 ( V_66 ) ;
V_66 += V_69 ;
while ( V_69 -- ) {
V_63 = F_61 ( * V_56 ) ;
V_100 = * V_56 | * V_99 ++ ;
* V_56 ++ = V_100 ;
V_5 -> V_91 += F_61 ( V_100 ) - V_63 ;
}
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
}
if ( V_70 == V_5 -> V_71 )
V_5 -> V_91 -= F_59 ( V_5 ) ;
F_74 ( & V_5 -> V_53 ) ;
}
void F_88 ( struct V_1 * V_2 , T_3 V_66 , T_3 V_38 ,
unsigned long * V_99 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_56 ;
T_3 V_70 , V_69 ;
V_70 = V_66 + V_38 ;
if ( ! F_56 ( V_5 ) )
return;
if ( ! F_56 ( V_5 -> V_24 ) )
return;
F_73 ( & V_5 -> V_53 ) ;
if ( ( V_66 >= V_5 -> V_71 ) ||
( V_70 > V_5 -> V_71 ) ||
( V_38 <= 0 ) )
F_3 ( V_2 , L_17 ,
( unsigned long ) V_66 ,
( unsigned long ) V_38 ,
( unsigned long ) V_5 -> V_71 ) ;
else {
while ( V_66 < V_70 ) {
V_69 = F_67 ( T_3 , F_68 ( V_66 + 1 , V_72 ) , V_70 ) - V_66 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_66 ) ) ;
V_56 = V_36 + F_69 ( V_66 ) ;
V_66 += V_69 ;
while ( V_69 -- )
* V_99 ++ = * V_56 ++ ;
F_40 ( V_36 ) ;
}
}
F_74 ( & V_5 -> V_53 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_56 ( V_5 ) )
return;
if ( ! F_56 ( V_5 -> V_24 ) )
return;
F_73 ( & V_5 -> V_53 ) ;
F_66 ( V_5 , 0 , 0xff , V_5 -> V_71 ) ;
( void ) F_59 ( V_5 ) ;
V_5 -> V_91 = V_5 -> V_59 ;
F_74 ( & V_5 -> V_53 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_56 ( V_5 ) )
return;
if ( ! F_56 ( V_5 -> V_24 ) )
return;
F_73 ( & V_5 -> V_53 ) ;
F_66 ( V_5 , 0 , 0 , V_5 -> V_71 ) ;
V_5 -> V_91 = 0 ;
F_74 ( & V_5 -> V_53 ) ;
}
static void F_91 ( struct V_101 * V_101 )
{
struct V_102 * V_103 = F_92 ( V_101 , struct V_102 , V_101 ) ;
unsigned long V_14 ;
F_81 ( & V_103 -> V_2 -> V_104 -> V_105 , V_14 ) ;
F_93 ( & V_103 -> V_106 ) ;
F_82 ( & V_103 -> V_2 -> V_104 -> V_105 , V_14 ) ;
F_77 ( V_103 -> V_2 ) ;
F_58 ( V_103 ) ;
}
static void F_94 ( struct V_107 * V_107 )
{
struct V_102 * V_103 = V_107 -> V_108 ;
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 = F_14 ( V_107 -> V_109 [ 0 ] . V_110 ) ;
if ( ( V_103 -> V_14 & V_111 ) == 0 &&
! F_27 ( V_5 -> V_24 [ V_20 ] ) )
F_7 ( V_2 , L_18 , V_20 ) ;
if ( V_107 -> V_112 ) {
V_103 -> error = V_107 -> V_112 ;
F_28 ( V_5 -> V_24 [ V_20 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_2 , L_19 ,
V_107 -> V_112 , V_20 ) ;
} else {
F_29 ( V_5 -> V_24 [ V_20 ] ) ;
F_95 ( V_2 , L_20 , V_20 ) ;
}
F_19 ( V_2 , V_20 ) ;
if ( V_103 -> V_14 & V_111 )
F_96 ( V_107 -> V_109 [ 0 ] . V_110 , V_113 ) ;
F_97 ( V_107 ) ;
if ( F_98 ( & V_103 -> V_114 ) ) {
V_103 -> V_115 = 1 ;
F_21 ( & V_2 -> V_116 ) ;
F_99 ( & V_103 -> V_101 , & F_91 ) ;
}
}
static void F_100 ( struct V_102 * V_103 , int V_22 ) __must_hold( T_4 )
{
struct V_107 * V_107 = F_101 ( V_46 ) ;
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_19 ;
unsigned int V_68 ;
unsigned int V_117 = ( V_103 -> V_14 & V_118 ) ? V_119 : V_120 ;
T_2 V_121 =
V_2 -> V_74 -> V_76 . V_122 + V_2 -> V_74 -> V_76 . V_79 ;
V_121 += ( ( T_2 ) V_22 ) << ( V_33 - 9 ) ;
V_68 = F_67 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(device->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_22 ) ;
F_22 ( V_5 -> V_24 [ V_22 ] ) ;
if ( V_103 -> V_14 & V_111 ) {
V_19 = F_102 ( V_113 , V_48 | V_123 ) ;
F_103 ( V_19 , V_5 -> V_24 [ V_22 ] ) ;
F_11 ( V_19 , V_22 ) ;
} else
V_19 = V_5 -> V_24 [ V_22 ] ;
V_107 -> V_124 = V_2 -> V_74 -> V_125 ;
V_107 -> V_126 . V_127 = V_121 ;
F_104 ( V_107 , V_19 , V_68 , 0 ) ;
V_107 -> V_108 = V_103 ;
V_107 -> V_128 = F_94 ;
if ( F_79 ( V_2 , ( V_117 & V_120 ) ? V_129 : V_130 ) ) {
V_107 -> V_131 |= V_117 ;
F_105 ( V_107 ) ;
} else {
F_106 ( V_117 , V_107 ) ;
F_107 ( V_68 >> 9 , & V_2 -> V_132 ) ;
}
}
static int F_108 ( struct V_1 * V_2 , const unsigned int V_14 , unsigned V_133 ) __must_hold( T_4 )
{
struct V_102 * V_103 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_134 , V_39 , V_135 = 0 ;
unsigned long V_136 ;
char V_137 [ 10 ] ;
int V_88 = 0 ;
V_103 = F_109 ( sizeof( struct V_102 ) , V_46 ) ;
if ( ! V_103 )
return - V_52 ;
* V_103 = (struct V_102 ) {
. V_2 = V_2 ,
. V_138 = V_139 ,
. V_114 = F_110 ( 1 ) ,
. V_115 = 0 ,
. V_14 = V_14 ,
. error = 0 ,
. V_101 = { F_110 ( 2 ) } ,
} ;
if ( ! F_84 ( V_2 , V_140 ) ) {
F_3 ( V_2 , L_21 ) ;
F_58 ( V_103 ) ;
return - V_141 ;
}
if ( 0 == ( V_103 -> V_14 & ~ V_118 ) )
F_51 ( ! ( V_17 & V_5 -> V_18 ) ) ;
F_73 ( & V_2 -> V_104 -> V_105 ) ;
F_111 ( & V_103 -> V_106 , & V_2 -> V_142 ) ;
F_74 ( & V_2 -> V_104 -> V_105 ) ;
V_134 = V_5 -> V_29 ;
V_136 = V_139 ;
for ( V_39 = 0 ; V_39 < V_134 ; V_39 ++ ) {
if ( V_133 && V_39 == V_133 )
break;
if ( ! ( V_14 & V_118 ) ) {
if ( ( V_14 & V_143 ) &&
! F_112 ( V_30 ,
& F_15 ( V_5 -> V_24 [ V_39 ] ) ) )
continue;
if ( ! ( V_14 & V_144 ) &&
F_27 ( V_5 -> V_24 [ V_39 ] ) ) {
F_95 ( V_2 , L_22 , V_39 ) ;
continue;
}
if ( V_133 &&
! F_31 ( V_5 -> V_24 [ V_39 ] ) ) {
F_95 ( V_2 , L_23 , V_39 ) ;
continue;
}
}
F_113 ( & V_103 -> V_114 ) ;
F_100 ( V_103 , V_39 ) ;
++ V_135 ;
F_65 () ;
}
if ( ! F_98 ( & V_103 -> V_114 ) )
F_114 ( V_2 , V_2 -> V_74 , & V_103 -> V_115 ) ;
else
F_99 ( & V_103 -> V_101 , & F_91 ) ;
if ( V_14 == 0 )
F_72 ( V_2 , L_24 ,
( V_14 & V_118 ) ? L_25 : L_26 ,
V_135 , V_139 - V_136 ) ;
if ( V_103 -> error ) {
F_115 ( V_2 , L_27 ) ;
F_116 ( V_2 , 1 , V_145 ) ;
V_88 = - V_146 ;
}
if ( F_117 ( & V_103 -> V_114 ) )
V_88 = - V_146 ;
V_136 = V_139 ;
if ( V_14 & V_118 ) {
V_5 -> V_91 = F_63 ( V_5 ) ;
F_72 ( V_2 , L_28 ,
V_139 - V_136 ) ;
}
V_136 = V_5 -> V_91 ;
if ( ( V_14 & ~ V_118 ) == 0 )
F_72 ( V_2 , L_29 ,
F_118 ( V_137 , V_136 << ( V_147 - 10 ) ) , V_136 ) ;
F_99 ( & V_103 -> V_101 , & F_91 ) ;
return V_88 ;
}
int F_119 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_108 ( V_2 , V_118 , 0 ) ;
}
int F_120 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_108 ( V_2 , 0 , 0 ) ;
}
int F_121 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_108 ( V_2 , V_144 , 0 ) ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_148 ) __must_hold( T_4 )
{
return F_108 ( V_2 , V_111 , V_148 ) ;
}
int F_123 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_108 ( V_2 , V_111 , 0 ) ;
}
int F_124 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_108 ( V_2 , V_143 | V_111 , 0 ) ;
}
static unsigned long F_125 ( struct V_1 * V_2 , unsigned long V_149 ,
const int V_150 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
unsigned long V_151 ;
unsigned V_39 ;
if ( V_149 > V_5 -> V_59 ) {
F_3 ( V_2 , L_30 , V_149 , V_5 -> V_59 ) ;
V_149 = V_152 ;
} else {
while ( V_149 < V_5 -> V_59 ) {
V_151 = V_149 & ~ V_60 ;
V_36 = F_35 ( V_5 , F_34 ( V_5 , V_149 ) ) ;
if ( V_150 )
V_39 = F_126 ( V_36 ,
V_95 * 8 , V_149 & V_60 ) ;
else
V_39 = F_127 ( V_36 ,
V_95 * 8 , V_149 & V_60 ) ;
F_38 ( V_36 ) ;
if ( V_39 < V_95 * 8 ) {
V_149 = V_151 + V_39 ;
if ( V_149 >= V_5 -> V_59 )
break;
goto V_153;
}
V_149 = V_151 + V_95 * 8 ;
}
V_149 = V_152 ;
}
V_153:
return V_149 ;
}
static unsigned long F_128 ( struct V_1 * V_2 ,
unsigned long V_149 , const int V_150 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_39 = V_152 ;
if ( ! F_56 ( V_5 ) )
return V_39 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return V_39 ;
F_73 ( & V_5 -> V_53 ) ;
if ( V_154 & V_5 -> V_18 )
F_129 ( V_2 ) ;
V_39 = F_125 ( V_2 , V_149 , V_150 ) ;
F_74 ( & V_5 -> V_53 ) ;
return V_39 ;
}
unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_128 ( V_2 , V_149 , 0 ) ;
}
unsigned long F_131 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_125 ( V_2 , V_149 , 0 ) ;
}
unsigned long F_132 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_125 ( V_2 , V_149 , 1 ) ;
}
static int F_133 ( struct V_1 * V_2 , const unsigned long V_97 ,
unsigned long V_155 , int V_156 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_157 = - 1U ;
int V_67 = 0 ;
int V_158 = 0 ;
if ( V_155 >= V_5 -> V_59 ) {
F_3 ( V_2 , L_31 ,
V_97 , V_155 , V_5 -> V_59 ) ;
V_155 = V_5 -> V_59 ? V_5 -> V_59 - 1 : 0 ;
}
for ( V_35 = V_97 ; V_35 <= V_155 ; V_35 ++ ) {
unsigned int V_22 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_157 ) {
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_67 < 0 )
F_30 ( V_5 -> V_24 [ V_157 ] ) ;
else if ( V_67 > 0 )
F_24 ( V_5 -> V_24 [ V_157 ] ) ;
V_158 += V_67 ;
V_67 = 0 ;
V_36 = F_35 ( V_5 , V_22 ) ;
V_157 = V_22 ;
}
if ( V_156 )
V_67 += ( 0 == F_134 ( V_35 & V_60 , V_36 ) ) ;
else
V_67 -= ( 0 != F_135 ( V_35 & V_60 , V_36 ) ) ;
}
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_67 < 0 )
F_30 ( V_5 -> V_24 [ V_157 ] ) ;
else if ( V_67 > 0 )
F_24 ( V_5 -> V_24 [ V_157 ] ) ;
V_158 += V_67 ;
V_5 -> V_91 += V_158 ;
return V_158 ;
}
static int F_136 ( struct V_1 * V_2 , const unsigned long V_97 ,
const unsigned long V_155 , int V_156 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_67 = 0 ;
if ( ! F_56 ( V_5 ) )
return 1 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 0 ;
F_81 ( & V_5 -> V_53 , V_14 ) ;
if ( ( V_156 ? V_159 : V_160 ) & V_5 -> V_18 )
F_129 ( V_2 ) ;
V_67 = F_133 ( V_2 , V_97 , V_155 , V_156 ) ;
F_82 ( & V_5 -> V_53 , V_14 ) ;
return V_67 ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_97 , const unsigned long V_155 )
{
return F_136 ( V_2 , V_97 , V_155 , 1 ) ;
}
int F_138 ( struct V_1 * V_2 , const unsigned long V_97 , const unsigned long V_155 )
{
return - F_136 ( V_2 , V_97 , V_155 , 0 ) ;
}
static inline void F_139 ( struct V_4 * V_5 ,
int V_22 , int V_161 , int V_64 )
{
int V_39 ;
int V_63 ;
int V_162 = 0 ;
unsigned long * V_163 = F_36 ( V_5 -> V_24 [ V_22 ] ) ;
for ( V_39 = V_161 ; V_39 < V_64 ; V_39 ++ ) {
V_63 = F_61 ( V_163 [ V_39 ] ) ;
V_163 [ V_39 ] = ~ 0UL ;
V_162 += V_62 - V_63 ;
}
F_39 ( V_163 ) ;
if ( V_162 ) {
F_30 ( V_5 -> V_24 [ V_22 ] ) ;
V_5 -> V_91 += V_162 ;
}
}
void F_140 ( struct V_1 * V_2 , const unsigned long V_97 , const unsigned long V_155 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_164 = F_68 ( V_97 , V_62 ) ;
unsigned long V_165 = ( V_155 + 1 ) & ~ ( ( unsigned long ) V_62 - 1 ) ;
int V_166 ;
int V_167 ;
int V_22 ;
int V_161 ;
int V_64 ;
if ( V_155 - V_97 <= 3 * V_62 ) {
F_73 ( & V_5 -> V_53 ) ;
F_133 ( V_2 , V_97 , V_155 , 1 ) ;
F_74 ( & V_5 -> V_53 ) ;
return;
}
F_73 ( & V_5 -> V_53 ) ;
if ( V_164 )
F_133 ( V_2 , V_97 , V_164 - 1 , 1 ) ;
V_166 = V_164 >> ( 3 + V_33 ) ;
V_167 = V_165 >> ( 3 + V_33 ) ;
V_161 = F_69 ( V_164 >> V_34 ) ;
V_64 = V_72 ;
for ( V_22 = V_166 ; V_22 < V_167 ; V_22 ++ ) {
F_139 ( V_2 -> V_6 , V_22 , V_161 , V_64 ) ;
F_74 ( & V_5 -> V_53 ) ;
F_65 () ;
V_161 = 0 ;
F_73 ( & V_5 -> V_53 ) ;
}
V_64 = F_69 ( V_165 >> V_34 ) ;
if ( V_64 )
F_139 ( V_2 -> V_6 , V_167 , V_161 , V_64 ) ;
if ( V_165 <= V_155 )
F_133 ( V_2 , V_165 , V_155 , 1 ) ;
F_74 ( & V_5 -> V_53 ) ;
}
int F_141 ( struct V_1 * V_2 , const unsigned long V_35 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
int V_39 ;
if ( ! F_56 ( V_5 ) )
return 0 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 0 ;
F_81 ( & V_5 -> V_53 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_129 ( V_2 ) ;
if ( V_35 < V_5 -> V_59 ) {
V_36 = F_37 ( V_5 , F_34 ( V_5 , V_35 ) ) ;
V_39 = F_142 ( V_35 & V_60 , V_36 ) ? 1 : 0 ;
F_40 ( V_36 ) ;
} else if ( V_35 == V_5 -> V_59 ) {
V_39 = - 1 ;
} else {
F_3 ( V_2 , L_32 , V_35 , V_5 -> V_59 ) ;
V_39 = 0 ;
}
F_82 ( & V_5 -> V_53 , V_14 ) ;
return V_39 ;
}
int F_143 ( struct V_1 * V_2 , const unsigned long V_97 , const unsigned long V_155 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_22 = - 1U ;
int V_67 = 0 ;
if ( ! F_56 ( V_5 ) )
return 1 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 1 ;
F_81 ( & V_5 -> V_53 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_129 ( V_2 ) ;
for ( V_35 = V_97 ; V_35 <= V_155 ; V_35 ++ ) {
unsigned int V_20 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_20 ) {
V_22 = V_20 ;
if ( V_36 )
F_40 ( V_36 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
}
if ( F_56 ( V_35 < V_5 -> V_59 ) )
V_67 += ( 0 != F_142 ( V_35 - ( V_22 << ( V_33 + 3 ) ) , V_36 ) ) ;
else
F_3 ( V_2 , L_33 , V_35 , V_5 -> V_59 ) ;
}
if ( V_36 )
F_40 ( V_36 ) ;
F_82 ( & V_5 -> V_53 , V_14 ) ;
return V_67 ;
}
int F_144 ( struct V_1 * V_2 , unsigned long V_168 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_135 , V_97 , V_155 ;
unsigned long V_14 ;
unsigned long * V_36 , * V_56 ;
if ( ! F_56 ( V_5 ) )
return 0 ;
if ( ! F_56 ( V_5 -> V_24 ) )
return 0 ;
F_81 ( & V_5 -> V_53 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_129 ( V_2 ) ;
V_97 = F_145 ( V_168 ) ;
V_155 = F_146 ( ( T_3 ) F_145 ( V_168 + 1 ) , V_5 -> V_71 ) ;
V_135 = 0 ;
if ( V_97 < V_5 -> V_71 ) {
int V_169 = V_155 - V_97 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_97 ) ) ;
V_56 = V_36 + F_69 ( V_97 ) ;
V_135 += F_64 ( V_56 , V_169 * V_62 ) ;
F_40 ( V_36 ) ;
} else {
F_3 ( V_2 , L_34 , V_97 ) ;
}
F_82 ( & V_5 -> V_53 , V_14 ) ;
return V_135 ;
}
