static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_2 ( & V_7 ) )
return;
F_3 ( V_8 , L_1 ,
V_9 == V_2 -> V_10 . V_11 ? L_2 :
V_9 == V_2 -> V_12 . V_11 ? L_3 :
V_9 == V_2 -> V_13 . V_11 ? L_4 : V_9 -> V_14 ,
V_3 , V_5 -> V_15 ? : L_5 ,
V_5 -> V_16 == V_2 -> V_10 . V_11 ? L_2 :
V_5 -> V_16 == V_2 -> V_12 . V_11 ? L_3 :
V_5 -> V_16 == V_2 -> V_13 . V_11 ? L_4 : L_5 ) ;
}
void F_4 ( struct V_1 * V_2 , char * V_17 , enum V_18 V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_20 ;
if ( ! V_5 ) {
F_3 ( V_8 , L_6 ) ;
return;
}
V_20 = ! F_5 ( & V_5 -> V_21 ) ;
if ( V_20 ) {
F_6 ( V_8 , L_7 ,
V_9 == V_2 -> V_10 . V_11 ? L_2 :
V_9 == V_2 -> V_12 . V_11 ? L_3 :
V_9 == V_2 -> V_13 . V_11 ? L_4 : V_9 -> V_14 ,
V_17 , V_5 -> V_15 ? : L_5 ,
V_5 -> V_16 == V_2 -> V_10 . V_11 ? L_2 :
V_5 -> V_16 == V_2 -> V_12 . V_11 ? L_3 :
V_5 -> V_16 == V_2 -> V_13 . V_11 ? L_4 : L_5 ) ;
F_7 ( & V_5 -> V_21 ) ;
}
if ( V_22 & V_5 -> V_23 )
F_3 ( V_8 , L_8 ) ;
V_5 -> V_23 |= V_19 & V_22 ;
V_5 -> V_15 = V_17 ;
V_5 -> V_16 = V_9 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_3 ( V_8 , L_9 ) ;
return;
}
if ( ! ( V_22 & V_2 -> V_6 -> V_23 ) )
F_3 ( V_8 , L_10 ) ;
V_5 -> V_23 &= ~ V_22 ;
V_5 -> V_15 = NULL ;
V_5 -> V_16 = NULL ;
F_9 ( & V_5 -> V_21 ) ;
}
static void F_10 ( struct V_24 * V_24 , unsigned long V_25 )
{
F_11 ( 0 != ( V_25 & ~ V_26 ) ) ;
F_12 ( V_24 ) |= V_25 ;
}
static unsigned long F_13 ( struct V_24 * V_24 )
{
return F_12 ( V_24 ) & V_26 ;
}
static void F_14 ( struct V_1 * V_2 , int V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_28 = & F_12 ( V_5 -> V_29 [ V_27 ] ) ;
F_15 ( V_5 -> V_30 , ! F_16 ( V_31 , V_28 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_28 = & F_12 ( V_5 -> V_29 [ V_27 ] ) ;
F_18 ( V_31 , V_28 ) ;
F_19 () ;
F_20 ( & V_2 -> V_6 -> V_30 ) ;
}
static void F_21 ( struct V_24 * V_24 )
{
F_18 ( V_32 , & F_12 ( V_24 ) ) ;
F_18 ( V_33 , & F_12 ( V_24 ) ) ;
}
static void F_22 ( struct V_24 * V_24 )
{
F_23 ( V_32 , & F_12 ( V_24 ) ) ;
}
static int F_24 ( struct V_24 * V_24 )
{
volatile const unsigned long * V_28 = & F_12 ( V_24 ) ;
return ( * V_28 & ( ( 1UL << V_32 ) | ( 1UL << V_33 ) ) ) == 0 ;
}
static void F_25 ( struct V_24 * V_24 )
{
F_23 ( V_34 , & F_12 ( V_24 ) ) ;
}
static void F_26 ( struct V_24 * V_24 )
{
F_18 ( V_34 , & F_12 ( V_24 ) ) ;
}
static void F_27 ( struct V_24 * V_24 )
{
F_23 ( V_33 , & F_12 ( V_24 ) ) ;
}
static int F_28 ( struct V_24 * V_24 )
{
return F_29 ( V_33 , & F_12 ( V_24 ) ) ;
}
static unsigned int F_30 ( struct V_4 * V_5 , unsigned long V_35 )
{
unsigned int V_27 = V_35 >> ( V_36 - V_37 + 3 ) ;
F_11 ( V_27 >= V_5 -> V_38 ) ;
return V_27 ;
}
static unsigned int F_31 ( struct V_4 * V_5 , T_1 V_39 )
{
unsigned int V_27 = V_39 >> ( V_36 + 3 ) ;
F_11 ( V_27 >= V_5 -> V_38 ) ;
return V_27 ;
}
static unsigned long * F_32 ( struct V_4 * V_5 , unsigned int V_25 , const enum V_40 V_41 )
{
struct V_24 * V_24 = V_5 -> V_29 [ V_25 ] ;
return ( unsigned long * ) F_33 ( V_24 , V_41 ) ;
}
static unsigned long * F_34 ( struct V_4 * V_5 , unsigned int V_25 )
{
return F_32 ( V_5 , V_25 , V_42 ) ;
}
static void F_35 ( unsigned long * V_43 , const enum V_40 V_41 )
{
F_36 ( V_43 , V_41 ) ;
}
static void F_37 ( unsigned long * V_43 )
{
return F_35 ( V_43 , V_42 ) ;
}
static void F_38 ( struct V_24 * * V_44 , unsigned long V_45 )
{
unsigned long V_46 ;
if ( ! V_44 )
return;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
if ( ! V_44 [ V_46 ] ) {
F_39 ( V_47 L_11
L_12 ,
V_46 , V_45 ) ;
continue;
}
F_40 ( V_44 [ V_46 ] ) ;
V_44 [ V_46 ] = NULL ;
}
}
static void F_41 ( void * V_48 , int V_49 )
{
if ( V_49 )
F_42 ( V_48 ) ;
else
F_43 ( V_48 ) ;
}
static struct V_24 * * F_44 ( struct V_4 * V_5 , unsigned long V_50 )
{
struct V_24 * * V_51 = V_5 -> V_29 ;
struct V_24 * * V_52 , * V_24 ;
unsigned int V_46 , V_53 , V_54 = 0 ;
unsigned long V_55 = V_5 -> V_38 ;
F_11 ( V_55 == 0 && V_51 != NULL ) ;
F_11 ( V_55 != 0 && V_51 == NULL ) ;
if ( V_55 == V_50 )
return V_51 ;
V_53 = sizeof( struct V_24 * ) * V_50 ;
V_52 = F_45 ( V_53 , V_56 ) ;
if ( ! V_52 ) {
V_52 = F_46 ( V_53 ) ;
if ( ! V_52 )
return NULL ;
V_54 = 1 ;
}
if ( V_50 >= V_55 ) {
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ )
V_52 [ V_46 ] = V_51 [ V_46 ] ;
for (; V_46 < V_50 ; V_46 ++ ) {
V_24 = F_47 ( V_57 ) ;
if ( ! V_24 ) {
F_38 ( V_52 + V_55 , V_46 - V_55 ) ;
F_41 ( V_52 , V_54 ) ;
return NULL ;
}
F_10 ( V_24 , V_46 ) ;
V_52 [ V_46 ] = V_24 ;
}
} else {
for ( V_46 = 0 ; V_46 < V_50 ; V_46 ++ )
V_52 [ V_46 ] = V_51 [ V_46 ] ;
}
if ( V_54 )
V_5 -> V_23 |= V_58 ;
else
V_5 -> V_23 &= ~ V_58 ;
return V_52 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_49 ( V_5 != NULL ) ;
V_5 = F_45 ( sizeof( struct V_4 ) , V_56 ) ;
if ( ! V_5 )
return - V_59 ;
F_50 ( & V_5 -> V_60 ) ;
F_51 ( & V_5 -> V_21 ) ;
F_52 ( & V_5 -> V_30 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_53 ( struct V_1 * V_2 )
{
F_54 (!mdev->bitmap) return 0 ;
return V_2 -> V_6 -> V_61 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_54 (!mdev->bitmap) return;
F_38 ( V_2 -> V_6 -> V_29 , V_2 -> V_6 -> V_38 ) ;
F_41 ( V_2 -> V_6 -> V_29 , ( V_58 & V_2 -> V_6 -> V_23 ) ) ;
F_43 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_56 ( struct V_4 * V_5 )
{
unsigned long V_62 ;
unsigned long * V_43 , * V_63 ;
int V_64 ;
int V_65 = 0 ;
V_64 = ( V_5 -> V_66 & V_67 ) ;
V_62 = ( 1UL << ( V_64 & V_68 ) ) - 1 ;
V_62 = F_57 ( V_62 ) ;
V_43 = F_34 ( V_5 , V_5 -> V_38 - 1 ) ;
V_63 = V_43 + ( V_64 / V_69 ) ;
if ( V_62 ) {
V_65 = F_58 ( * V_63 & ~ V_62 ) ;
* V_63 &= V_62 ;
V_63 ++ ;
}
if ( V_69 == 32 && ( ( V_63 - V_43 ) & 1 ) == 1 ) {
V_65 += F_58 ( * V_63 ) ;
* V_63 = 0 ;
}
F_37 ( V_43 ) ;
return V_65 ;
}
static void F_59 ( struct V_4 * V_5 )
{
unsigned long V_62 ;
unsigned long * V_43 , * V_63 ;
int V_64 ;
V_64 = ( V_5 -> V_66 & V_67 ) ;
V_62 = ( 1UL << ( V_64 & V_68 ) ) - 1 ;
V_62 = F_57 ( V_62 ) ;
V_43 = F_34 ( V_5 , V_5 -> V_38 - 1 ) ;
V_63 = V_43 + ( V_64 / V_69 ) ;
if ( V_62 ) {
* V_63 |= ~ V_62 ;
V_63 ++ ;
}
if ( V_69 == 32 && ( ( V_63 - V_43 ) & 1 ) == 1 ) {
* V_63 = ~ 0UL ;
}
F_37 ( V_43 ) ;
}
static unsigned long F_60 ( struct V_4 * V_5 )
{
unsigned long * V_43 ;
unsigned long V_70 = 0 ;
unsigned long V_62 = ( 1UL << ( V_5 -> V_66 & V_68 ) ) - 1 ;
int V_25 , V_46 , V_71 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_38 - 1 ; V_25 ++ ) {
V_43 = F_32 ( V_5 , V_25 , V_72 ) ;
for ( V_46 = 0 ; V_46 < V_73 ; V_46 ++ )
V_70 += F_58 ( V_43 [ V_46 ] ) ;
F_35 ( V_43 , V_72 ) ;
F_61 () ;
}
V_71 = ( ( V_5 -> V_66 - 1 ) & V_67 ) >> V_37 ;
V_43 = F_32 ( V_5 , V_25 , V_72 ) ;
for ( V_46 = 0 ; V_46 < V_71 ; V_46 ++ )
V_70 += F_58 ( V_43 [ V_46 ] ) ;
V_43 [ V_71 ] &= F_57 ( V_62 ) ;
V_70 += F_58 ( V_43 [ V_71 ] ) ;
if ( V_69 == 32 && ( V_71 & 1 ) == 0 )
V_43 [ V_71 + 1 ] = 0 ;
F_35 ( V_43 , V_72 ) ;
return V_70 ;
}
static void F_62 ( struct V_4 * V_5 , T_3 V_74 , int V_75 , T_3 V_76 )
{
unsigned long * V_43 , * V_63 ;
unsigned int V_25 ;
T_3 V_77 , V_78 ;
V_78 = V_74 + V_76 ;
if ( V_78 > V_5 -> V_79 ) {
F_39 ( V_47 L_13 ) ;
return;
}
while ( V_74 < V_78 ) {
V_77 = F_63 ( T_3 , F_64 ( V_74 + 1 , V_73 ) , V_78 ) - V_74 ;
V_25 = F_30 ( V_5 , V_74 ) ;
V_43 = F_34 ( V_5 , V_25 ) ;
V_63 = V_43 + F_65 ( V_74 ) ;
if ( V_63 + V_77 > V_43 + V_73 ) {
F_39 ( V_47 L_14 ,
V_43 , V_63 , ( int ) V_77 ) ;
} else
memset ( V_63 , V_75 , V_77 * sizeof( long ) ) ;
F_37 ( V_43 ) ;
F_22 ( V_5 -> V_29 [ V_25 ] ) ;
V_74 += V_77 ;
}
}
int F_66 ( struct V_1 * V_2 , T_2 V_80 , int V_81 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_70 , V_82 , V_83 , V_84 ;
unsigned long V_50 , V_55 , V_85 ;
struct V_24 * * V_86 , * * V_87 = NULL ;
int V_88 = 0 , V_89 ;
int V_90 ;
F_54 (!b) return - V_59 ;
F_4 ( V_2 , L_15 , V_22 ) ;
F_67 ( V_8 , L_16 ,
( unsigned long long ) V_80 ) ;
if ( V_80 == V_5 -> V_61 )
goto V_91;
V_90 = ( V_58 & V_5 -> V_23 ) ;
if ( V_80 == 0 ) {
F_68 ( & V_5 -> V_60 ) ;
V_87 = V_5 -> V_29 ;
V_85 = V_5 -> V_38 ;
V_83 = V_5 -> V_79 ;
V_5 -> V_29 = NULL ;
V_5 -> V_38 =
V_5 -> V_92 =
V_5 -> V_66 =
V_5 -> V_79 =
V_5 -> V_61 = 0 ;
F_69 ( & V_5 -> V_60 ) ;
F_38 ( V_87 , V_85 ) ;
F_41 ( V_87 , V_90 ) ;
goto V_91;
}
V_70 = F_70 ( F_64 ( V_80 , V_93 ) ) ;
V_82 = F_64 ( V_70 , 64 ) >> V_37 ;
if ( F_71 ( V_2 ) ) {
T_1 V_94 = ( ( T_1 ) V_2 -> V_95 -> V_96 . V_97 - V_98 ) << 12 ;
F_72 ( V_2 ) ;
if ( V_70 > V_94 ) {
F_67 ( V_8 , L_17 , V_70 ) ;
F_67 ( V_8 , L_18 , V_94 ) ;
V_88 = - V_99 ;
goto V_91;
}
}
V_50 = F_64 ( V_82 * sizeof( long ) , V_100 ) >> V_36 ;
V_55 = V_5 -> V_38 ;
if ( V_50 == V_55 ) {
F_73 ( V_5 -> V_29 != NULL ) ;
V_86 = V_5 -> V_29 ;
} else {
if ( F_74 ( V_2 , V_101 ) )
V_86 = NULL ;
else
V_86 = F_44 ( V_5 , V_50 ) ;
}
if ( ! V_86 ) {
V_88 = - V_59 ;
goto V_91;
}
F_68 ( & V_5 -> V_60 ) ;
V_87 = V_5 -> V_29 ;
V_83 = V_5 -> V_79 ;
V_84 = V_5 -> V_66 ;
V_89 = V_70 > V_84 ;
if ( V_87 && V_89 && V_81 )
F_59 ( V_5 ) ;
V_5 -> V_29 = V_86 ;
V_5 -> V_38 = V_50 ;
V_5 -> V_66 = V_70 ;
V_5 -> V_79 = V_82 ;
V_5 -> V_61 = V_80 ;
if ( V_89 ) {
if ( V_81 ) {
F_62 ( V_5 , V_83 , 0xff , V_82 - V_83 ) ;
V_5 -> V_92 += V_70 - V_84 ;
} else
F_62 ( V_5 , V_83 , 0x00 , V_82 - V_83 ) ;
}
if ( V_50 < V_55 ) {
F_38 ( V_87 + V_50 , V_55 - V_50 ) ;
}
( void ) F_56 ( V_5 ) ;
F_69 ( & V_5 -> V_60 ) ;
if ( V_87 != V_86 )
F_41 ( V_87 , V_90 ) ;
if ( ! V_89 )
V_5 -> V_92 = F_60 ( V_5 ) ;
F_67 ( V_8 , L_19 , V_70 , V_82 , V_50 ) ;
V_91:
F_8 ( V_2 ) ;
return V_88 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_102 ;
unsigned long V_19 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_60 , V_19 ) ;
V_102 = V_5 -> V_92 ;
F_77 ( & V_5 -> V_60 , V_19 ) ;
return V_102 ;
}
unsigned long F_78 ( struct V_1 * V_2 )
{
unsigned long V_102 ;
if ( ! F_79 ( V_2 , V_103 ) )
return 0 ;
V_102 = F_75 ( V_2 ) ;
F_72 ( V_2 ) ;
return V_102 ;
}
T_3 F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
return V_5 -> V_79 ;
}
unsigned long F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return 0 ;
return V_5 -> V_66 ;
}
void F_82 ( struct V_1 * V_2 , T_3 V_74 , T_3 V_45 ,
unsigned long * V_104 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 , * V_63 ;
unsigned long V_105 , V_70 ;
unsigned int V_25 ;
T_3 V_78 , V_77 ;
V_78 = V_74 + V_45 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
if ( V_45 == 0 )
return;
F_49 ( V_74 >= V_5 -> V_79 ) ;
F_49 ( V_78 > V_5 -> V_79 ) ;
F_68 ( & V_5 -> V_60 ) ;
while ( V_74 < V_78 ) {
V_77 = F_63 ( T_3 , F_64 ( V_74 + 1 , V_73 ) , V_78 ) - V_74 ;
V_25 = F_30 ( V_5 , V_74 ) ;
V_43 = F_34 ( V_5 , V_25 ) ;
V_63 = V_43 + F_65 ( V_74 ) ;
V_74 += V_77 ;
while ( V_77 -- ) {
V_70 = F_58 ( * V_63 ) ;
V_105 = * V_63 | * V_104 ++ ;
* V_63 ++ = V_105 ;
V_5 -> V_92 += F_58 ( V_105 ) - V_70 ;
}
F_37 ( V_43 ) ;
F_22 ( V_5 -> V_29 [ V_25 ] ) ;
}
if ( V_78 == V_5 -> V_79 )
V_5 -> V_92 -= F_56 ( V_5 ) ;
F_69 ( & V_5 -> V_60 ) ;
}
void F_83 ( struct V_1 * V_2 , T_3 V_74 , T_3 V_45 ,
unsigned long * V_104 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 , * V_63 ;
T_3 V_78 , V_77 ;
V_78 = V_74 + V_45 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_60 ) ;
if ( ( V_74 >= V_5 -> V_79 ) ||
( V_78 > V_5 -> V_79 ) ||
( V_45 <= 0 ) )
F_3 ( V_8 , L_20 ,
( unsigned long ) V_74 ,
( unsigned long ) V_45 ,
( unsigned long ) V_5 -> V_79 ) ;
else {
while ( V_74 < V_78 ) {
V_77 = F_63 ( T_3 , F_64 ( V_74 + 1 , V_73 ) , V_78 ) - V_74 ;
V_43 = F_34 ( V_5 , F_30 ( V_5 , V_74 ) ) ;
V_63 = V_43 + F_65 ( V_74 ) ;
V_74 += V_77 ;
while ( V_77 -- )
* V_104 ++ = * V_63 ++ ;
F_37 ( V_43 ) ;
}
}
F_69 ( & V_5 -> V_60 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_60 ) ;
F_62 ( V_5 , 0 , 0xff , V_5 -> V_79 ) ;
( void ) F_56 ( V_5 ) ;
V_5 -> V_92 = V_5 -> V_66 ;
F_69 ( & V_5 -> V_60 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_60 ) ;
F_62 ( V_5 , 0 , 0 , V_5 -> V_79 ) ;
V_5 -> V_92 = 0 ;
F_69 ( & V_5 -> V_60 ) ;
}
static void F_86 ( struct V_106 * V_106 , int error )
{
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_25 = F_13 ( V_106 -> V_110 [ 0 ] . V_111 ) ;
int V_112 = F_87 ( V_106 , V_113 ) ;
if ( ! error && ! V_112 )
error = - V_114 ;
if ( ( V_108 -> V_19 & V_115 ) == 0 &&
! F_24 ( V_5 -> V_29 [ V_25 ] ) )
F_6 ( V_8 , L_21 , V_25 ) ;
if ( error ) {
V_108 -> error = error ;
F_25 ( V_5 -> V_29 [ V_25 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_8 , L_22 ,
error , V_25 ) ;
} else {
F_26 ( V_5 -> V_29 [ V_25 ] ) ;
F_88 ( V_8 , L_23 , V_25 ) ;
}
F_17 ( V_2 , V_25 ) ;
if ( V_108 -> V_19 & V_115 )
F_89 ( V_106 -> V_110 [ 0 ] . V_111 ) ;
F_90 ( V_106 ) ;
if ( F_91 ( & V_108 -> V_116 ) )
F_92 ( & V_108 -> V_117 ) ;
}
static void F_93 ( struct V_107 * V_108 , int V_27 , int V_118 ) __must_hold( T_4 )
{
struct V_106 * V_106 = F_94 ( V_56 , 1 ) ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_24 ;
unsigned int V_76 ;
T_2 V_119 =
V_2 -> V_95 -> V_96 . V_120 + V_2 -> V_95 -> V_96 . V_121 ;
V_119 += ( ( T_2 ) V_27 ) << ( V_36 - 9 ) ;
V_76 = F_63 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(mdev->ldev) - on_disk_sector + 1)<<9 ) ;
F_14 ( V_2 , V_27 ) ;
F_21 ( V_5 -> V_29 [ V_27 ] ) ;
if ( V_108 -> V_19 & V_115 ) {
void * V_122 , * V_123 ;
V_24 = F_47 ( V_124 | V_125 ) ;
V_123 = F_33 ( V_24 , V_72 ) ;
V_122 = F_33 ( V_5 -> V_29 [ V_27 ] , V_126 ) ;
memcpy ( V_123 , V_122 , V_100 ) ;
F_36 ( V_122 , V_126 ) ;
F_36 ( V_123 , V_72 ) ;
F_10 ( V_24 , V_27 ) ;
} else
V_24 = V_5 -> V_29 [ V_27 ] ;
V_106 -> V_127 = V_2 -> V_95 -> V_128 ;
V_106 -> V_129 = V_119 ;
F_95 ( V_106 , V_24 , V_76 , 0 ) ;
V_106 -> V_109 = V_108 ;
V_106 -> V_130 = F_86 ;
if ( F_74 ( V_2 , ( V_118 & V_131 ) ? V_132 : V_133 ) ) {
V_106 -> V_134 |= V_118 ;
F_96 ( V_106 , - V_114 ) ;
} else {
F_97 ( V_118 , V_106 ) ;
F_98 ( V_76 >> 9 , & V_2 -> V_135 ) ;
}
}
static int F_99 ( struct V_1 * V_2 , int V_118 , unsigned V_136 ) __must_hold( T_4 )
{
struct V_107 V_108 = {
. V_2 = V_2 ,
. V_116 = F_100 ( 1 ) ,
. V_117 = F_101 ( V_108 . V_117 ) ,
. V_19 = V_136 ? V_115 : 0 ,
} ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_137 , V_46 , V_138 = 0 ;
unsigned long V_139 ;
char V_140 [ 10 ] ;
int V_88 = 0 ;
if ( ! V_108 . V_19 )
F_49 ( ! ( V_22 & V_5 -> V_23 ) ) ;
V_137 = V_5 -> V_38 ;
V_139 = V_141 ;
for ( V_46 = 0 ; V_46 < V_137 ; V_46 ++ ) {
if ( V_136 && V_46 == V_136 )
break;
if ( V_118 & V_131 ) {
if ( F_24 ( V_5 -> V_29 [ V_46 ] ) ) {
F_88 ( V_8 , L_24 , V_46 ) ;
continue;
}
if ( V_136 &&
! F_28 ( V_5 -> V_29 [ V_46 ] ) ) {
F_88 ( V_8 , L_25 , V_46 ) ;
continue;
}
}
F_102 ( & V_108 . V_116 ) ;
F_93 ( & V_108 , V_46 , V_118 ) ;
++ V_138 ;
F_61 () ;
}
if ( ! F_91 ( & V_108 . V_116 ) )
F_103 ( & V_108 . V_117 ) ;
F_67 ( V_8 , L_26 ,
V_118 == V_131 ? L_27 : L_28 ,
V_138 , V_141 - V_139 ) ;
if ( V_108 . error ) {
F_104 ( V_8 , L_29 ) ;
F_105 ( V_2 , 1 , true ) ;
V_88 = - V_114 ;
}
V_139 = V_141 ;
if ( V_118 == V_131 ) {
F_106 ( V_2 ) ;
} else {
V_5 -> V_92 = F_60 ( V_5 ) ;
F_67 ( V_8 , L_30 ,
V_141 - V_139 ) ;
}
V_139 = V_5 -> V_92 ;
F_67 ( V_8 , L_31 ,
F_107 ( V_140 , V_139 << ( V_142 - 10 ) ) , V_139 ) ;
return V_88 ;
}
int F_108 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_143 , 0 ) ;
}
int F_109 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_131 , 0 ) ;
}
int F_110 ( struct V_1 * V_2 , unsigned V_144 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_131 , V_144 ) ;
}
int F_111 ( struct V_1 * V_2 , unsigned int V_25 ) __must_hold( T_4 )
{
struct V_107 V_108 = {
. V_2 = V_2 ,
. V_116 = F_100 ( 1 ) ,
. V_117 = F_101 ( V_108 . V_117 ) ,
. V_19 = V_115 ,
} ;
if ( F_24 ( V_2 -> V_6 -> V_29 [ V_25 ] ) ) {
F_88 ( V_8 , L_32 , V_25 ) ;
return 0 ;
}
F_93 ( & V_108 , V_25 , V_145 ) ;
F_103 ( & V_108 . V_117 ) ;
if ( V_108 . error )
F_105 ( V_2 , 1 , true ) ;
V_2 -> V_146 ++ ;
return V_108 . error ;
}
static unsigned long F_112 ( struct V_1 * V_2 , unsigned long V_147 ,
const int V_148 , const enum V_40 V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 ;
unsigned long V_149 ;
unsigned V_46 ;
if ( V_147 > V_5 -> V_66 ) {
F_3 ( V_8 , L_33 , V_147 , V_5 -> V_66 ) ;
V_147 = V_150 ;
} else {
while ( V_147 < V_5 -> V_66 ) {
V_149 = V_147 & ~ V_67 ;
V_43 = F_32 ( V_5 , F_31 ( V_5 , V_147 ) , V_41 ) ;
if ( V_148 )
V_46 = F_113 ( V_43 ,
V_100 * 8 , V_147 & V_67 ) ;
else
V_46 = F_114 ( V_43 ,
V_100 * 8 , V_147 & V_67 ) ;
F_35 ( V_43 , V_41 ) ;
if ( V_46 < V_100 * 8 ) {
V_147 = V_149 + V_46 ;
if ( V_147 >= V_5 -> V_66 )
break;
goto V_151;
}
V_147 = V_149 + V_100 * 8 ;
}
V_147 = V_150 ;
}
V_151:
return V_147 ;
}
static unsigned long F_115 ( struct V_1 * V_2 ,
unsigned long V_147 , const int V_148 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_46 = V_150 ;
F_54 (!b) return V_46 ;
F_54 (!b->bm_pages) return V_46 ;
F_68 ( & V_5 -> V_60 ) ;
if ( V_152 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_46 = F_112 ( V_2 , V_147 , V_148 , V_42 ) ;
F_69 ( & V_5 -> V_60 ) ;
return V_46 ;
}
unsigned long F_117 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_115 ( V_2 , V_147 , 0 ) ;
}
unsigned long F_118 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_112 ( V_2 , V_147 , 0 , V_126 ) ;
}
unsigned long F_119 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_112 ( V_2 , V_147 , 1 , V_126 ) ;
}
static int F_120 ( struct V_1 * V_2 , const unsigned long V_102 ,
unsigned long V_153 , int V_154 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 = NULL ;
unsigned long V_39 ;
unsigned int V_155 = - 1U ;
int V_75 = 0 ;
int V_156 = 0 ;
if ( V_153 >= V_5 -> V_66 ) {
F_3 ( V_8 , L_34 ,
V_102 , V_153 , V_5 -> V_66 ) ;
V_153 = V_5 -> V_66 ? V_5 -> V_66 - 1 : 0 ;
}
for ( V_39 = V_102 ; V_39 <= V_153 ; V_39 ++ ) {
unsigned int V_27 = F_31 ( V_5 , V_39 ) ;
if ( V_27 != V_155 ) {
if ( V_43 )
F_35 ( V_43 , V_42 ) ;
if ( V_75 < 0 )
F_27 ( V_5 -> V_29 [ V_155 ] ) ;
else if ( V_75 > 0 )
F_22 ( V_5 -> V_29 [ V_155 ] ) ;
V_156 += V_75 ;
V_75 = 0 ;
V_43 = F_32 ( V_5 , V_27 , V_42 ) ;
V_155 = V_27 ;
}
if ( V_154 )
V_75 += ( 0 == F_121 ( V_39 & V_67 , V_43 ) ) ;
else
V_75 -= ( 0 != F_122 ( V_39 & V_67 , V_43 ) ) ;
}
if ( V_43 )
F_35 ( V_43 , V_42 ) ;
if ( V_75 < 0 )
F_27 ( V_5 -> V_29 [ V_155 ] ) ;
else if ( V_75 > 0 )
F_22 ( V_5 -> V_29 [ V_155 ] ) ;
V_156 += V_75 ;
V_5 -> V_92 += V_156 ;
return V_156 ;
}
static int F_123 ( struct V_1 * V_2 , const unsigned long V_102 ,
const unsigned long V_153 , int V_154 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_75 = 0 ;
F_54 (!b) return 1 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_60 , V_19 ) ;
if ( ( V_154 ? V_157 : V_158 ) & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_75 = F_120 ( V_2 , V_102 , V_153 , V_154 ) ;
F_77 ( & V_5 -> V_60 , V_19 ) ;
return V_75 ;
}
int F_124 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_153 )
{
return F_123 ( V_2 , V_102 , V_153 , 1 ) ;
}
int F_125 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_153 )
{
return - F_123 ( V_2 , V_102 , V_153 , 0 ) ;
}
static inline void F_126 ( struct V_4 * V_5 ,
int V_27 , int V_159 , int V_71 )
{
int V_46 ;
int V_70 ;
unsigned long * V_160 = F_33 ( V_5 -> V_29 [ V_27 ] , V_42 ) ;
for ( V_46 = V_159 ; V_46 < V_71 ; V_46 ++ ) {
V_70 = F_58 ( V_160 [ V_46 ] ) ;
V_160 [ V_46 ] = ~ 0UL ;
V_5 -> V_92 += V_69 - V_70 ;
}
F_36 ( V_160 , V_42 ) ;
}
void F_127 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_161 = F_64 ( V_102 , V_69 ) ;
unsigned long V_162 = ( V_153 + 1 ) & ~ ( ( unsigned long ) V_69 - 1 ) ;
int V_163 ;
int V_164 ;
int V_27 ;
int V_159 ;
int V_71 ;
if ( V_153 - V_102 <= 3 * V_69 ) {
F_68 ( & V_5 -> V_60 ) ;
F_120 ( V_2 , V_102 , V_153 , 1 ) ;
F_69 ( & V_5 -> V_60 ) ;
return;
}
F_68 ( & V_5 -> V_60 ) ;
if ( V_161 )
F_120 ( V_2 , V_102 , V_161 - 1 , 1 ) ;
V_163 = V_161 >> ( 3 + V_36 ) ;
V_164 = V_162 >> ( 3 + V_36 ) ;
V_159 = F_65 ( V_161 >> V_37 ) ;
V_71 = V_73 ;
for ( V_27 = V_163 ; V_27 < V_164 ; V_27 ++ ) {
F_126 ( V_2 -> V_6 , V_27 , V_159 , V_71 ) ;
F_69 ( & V_5 -> V_60 ) ;
F_61 () ;
V_159 = 0 ;
F_68 ( & V_5 -> V_60 ) ;
}
V_71 = F_65 ( V_162 >> V_37 ) ;
F_126 ( V_2 -> V_6 , V_164 , V_159 , V_71 ) ;
if ( V_162 <= V_153 )
F_120 ( V_2 , V_162 , V_153 , 1 ) ;
F_69 ( & V_5 -> V_60 ) ;
}
int F_128 ( struct V_1 * V_2 , const unsigned long V_39 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 ;
int V_46 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_60 , V_19 ) ;
if ( V_152 & V_5 -> V_23 )
F_116 ( V_2 ) ;
if ( V_39 < V_5 -> V_66 ) {
V_43 = F_34 ( V_5 , F_31 ( V_5 , V_39 ) ) ;
V_46 = F_129 ( V_39 & V_67 , V_43 ) ? 1 : 0 ;
F_37 ( V_43 ) ;
} else if ( V_39 == V_5 -> V_66 ) {
V_46 = - 1 ;
} else {
F_3 ( V_8 , L_35 , V_39 , V_5 -> V_66 ) ;
V_46 = 0 ;
}
F_77 ( & V_5 -> V_60 , V_19 ) ;
return V_46 ;
}
int F_130 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_153 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 = NULL ;
unsigned long V_39 ;
unsigned int V_27 = - 1U ;
int V_75 = 0 ;
F_54 (!b) return 1 ;
F_54 (!b->bm_pages) return 1 ;
F_76 ( & V_5 -> V_60 , V_19 ) ;
if ( V_152 & V_5 -> V_23 )
F_116 ( V_2 ) ;
for ( V_39 = V_102 ; V_39 <= V_153 ; V_39 ++ ) {
unsigned int V_25 = F_31 ( V_5 , V_39 ) ;
if ( V_27 != V_25 ) {
V_27 = V_25 ;
if ( V_43 )
F_37 ( V_43 ) ;
V_43 = F_34 ( V_5 , V_25 ) ;
}
F_54 (bitnr >= b->bm_bits) {
F_3 ( V_8 , L_36 , V_39 , V_5 -> V_66 ) ;
} else {
V_75 += ( 0 != F_129 ( V_39 - ( V_27 << ( V_36 + 3 ) ) , V_43 ) ) ;
}
}
if ( V_43 )
F_37 ( V_43 ) ;
F_77 ( & V_5 -> V_60 , V_19 ) ;
return V_75 ;
}
int F_131 ( struct V_1 * V_2 , unsigned long V_165 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_138 , V_102 , V_153 ;
unsigned long V_19 ;
unsigned long * V_43 , * V_63 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_60 , V_19 ) ;
if ( V_152 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_102 = F_132 ( V_165 ) ;
V_153 = F_133 ( ( T_3 ) F_132 ( V_165 + 1 ) , V_5 -> V_79 ) ;
V_138 = 0 ;
if ( V_102 < V_5 -> V_79 ) {
int V_166 = V_153 - V_102 ;
V_43 = F_34 ( V_5 , F_30 ( V_5 , V_102 ) ) ;
V_63 = V_43 + F_65 ( V_102 ) ;
while ( V_166 -- )
V_138 += F_58 ( * V_63 ++ ) ;
F_37 ( V_43 ) ;
} else {
F_3 ( V_8 , L_37 , V_102 ) ;
}
F_77 ( & V_5 -> V_60 , V_19 ) ;
return V_138 ;
}
unsigned long F_134 ( struct V_1 * V_2 , unsigned long V_167 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_43 , * V_63 ;
unsigned long V_168 ;
unsigned long V_102 , V_153 ;
int V_138 , V_46 , V_77 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_68 ( & V_5 -> V_60 ) ;
if ( V_157 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_168 = V_5 -> V_92 ;
V_102 = V_167 * V_169 ;
V_153 = F_63 ( T_3 , V_102 + V_169 , V_5 -> V_79 ) ;
F_73 ( ( V_153 - 1 ) >> ( V_36 - V_37 + 3 )
== V_102 >> ( V_36 - V_37 + 3 ) ) ;
V_138 = 0 ;
if ( V_102 < V_5 -> V_79 ) {
V_46 = V_77 = V_153 - V_102 ;
V_43 = F_34 ( V_5 , F_30 ( V_5 , V_102 ) ) ;
V_63 = V_43 + F_65 ( V_102 ) ;
while ( V_46 -- ) {
V_138 += F_58 ( * V_63 ) ;
* V_63 = - 1UL ;
V_63 ++ ;
}
F_37 ( V_43 ) ;
V_5 -> V_92 += V_77 * V_69 - V_138 ;
if ( V_153 == V_5 -> V_79 )
V_5 -> V_92 -= F_56 ( V_5 ) ;
} else {
F_3 ( V_8 , L_38 , V_102 ) ;
}
V_168 = V_5 -> V_92 - V_168 ;
F_69 ( & V_5 -> V_60 ) ;
return V_168 ;
}
