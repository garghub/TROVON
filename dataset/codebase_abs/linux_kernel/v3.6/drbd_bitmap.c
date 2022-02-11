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
F_12 ( V_24 , V_25 ) ;
}
static unsigned long F_13 ( struct V_24 * V_24 )
{
return F_14 ( V_24 ) & V_26 ;
}
static void F_15 ( struct V_1 * V_2 , int V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_28 = & F_14 ( V_5 -> V_29 [ V_27 ] ) ;
F_16 ( V_5 -> V_30 , ! F_17 ( V_31 , V_28 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_28 = & F_14 ( V_5 -> V_29 [ V_27 ] ) ;
F_19 ( V_31 , V_28 ) ;
F_20 () ;
F_21 ( & V_2 -> V_6 -> V_30 ) ;
}
static void F_22 ( struct V_24 * V_24 )
{
F_19 ( V_32 , & F_14 ( V_24 ) ) ;
F_19 ( V_33 , & F_14 ( V_24 ) ) ;
}
static void F_23 ( struct V_24 * V_24 )
{
F_24 ( V_32 , & F_14 ( V_24 ) ) ;
}
static int F_25 ( struct V_24 * V_24 )
{
volatile const unsigned long * V_28 = & F_14 ( V_24 ) ;
return ( * V_28 & ( ( 1UL << V_32 ) | ( 1UL << V_33 ) ) ) == 0 ;
}
static void F_26 ( struct V_24 * V_24 )
{
F_24 ( V_34 , & F_14 ( V_24 ) ) ;
}
static void F_27 ( struct V_24 * V_24 )
{
F_19 ( V_34 , & F_14 ( V_24 ) ) ;
}
static void F_28 ( struct V_24 * V_24 )
{
F_24 ( V_33 , & F_14 ( V_24 ) ) ;
}
static int F_29 ( struct V_24 * V_24 )
{
return F_30 ( V_33 , & F_14 ( V_24 ) ) ;
}
static unsigned int F_31 ( struct V_4 * V_5 , unsigned long V_35 )
{
unsigned int V_27 = V_35 >> ( V_36 - V_37 + 3 ) ;
F_11 ( V_27 >= V_5 -> V_38 ) ;
return V_27 ;
}
static unsigned int F_32 ( struct V_4 * V_5 , T_1 V_39 )
{
unsigned int V_27 = V_39 >> ( V_36 + 3 ) ;
F_11 ( V_27 >= V_5 -> V_38 ) ;
return V_27 ;
}
static unsigned long * F_33 ( struct V_4 * V_5 , unsigned int V_25 )
{
struct V_24 * V_24 = V_5 -> V_29 [ V_25 ] ;
return ( unsigned long * ) F_34 ( V_24 ) ;
}
static unsigned long * F_35 ( struct V_4 * V_5 , unsigned int V_25 )
{
return F_33 ( V_5 , V_25 ) ;
}
static void F_36 ( unsigned long * V_40 )
{
F_37 ( V_40 ) ;
}
static void F_38 ( unsigned long * V_40 )
{
return F_36 ( V_40 ) ;
}
static void F_39 ( struct V_24 * * V_41 , unsigned long V_42 )
{
unsigned long V_43 ;
if ( ! V_41 )
return;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( ! V_41 [ V_43 ] ) {
F_40 ( V_44 L_11
L_12 ,
V_43 , V_42 ) ;
continue;
}
F_41 ( V_41 [ V_43 ] ) ;
V_41 [ V_43 ] = NULL ;
}
}
static void F_42 ( void * V_45 , int V_46 )
{
if ( V_46 )
F_43 ( V_45 ) ;
else
F_44 ( V_45 ) ;
}
static struct V_24 * * F_45 ( struct V_4 * V_5 , unsigned long V_47 )
{
struct V_24 * * V_48 = V_5 -> V_29 ;
struct V_24 * * V_49 , * V_24 ;
unsigned int V_43 , V_50 , V_51 = 0 ;
unsigned long V_52 = V_5 -> V_38 ;
F_11 ( V_52 == 0 && V_48 != NULL ) ;
F_11 ( V_52 != 0 && V_48 == NULL ) ;
if ( V_52 == V_47 )
return V_48 ;
V_50 = sizeof( struct V_24 * ) * V_47 ;
V_49 = F_46 ( V_50 , V_53 ) ;
if ( ! V_49 ) {
V_49 = F_47 ( V_50 ) ;
if ( ! V_49 )
return NULL ;
V_51 = 1 ;
}
if ( V_47 >= V_52 ) {
for ( V_43 = 0 ; V_43 < V_52 ; V_43 ++ )
V_49 [ V_43 ] = V_48 [ V_43 ] ;
for (; V_43 < V_47 ; V_43 ++ ) {
V_24 = F_48 ( V_54 ) ;
if ( ! V_24 ) {
F_39 ( V_49 + V_52 , V_43 - V_52 ) ;
F_42 ( V_49 , V_51 ) ;
return NULL ;
}
F_10 ( V_24 , V_43 ) ;
V_49 [ V_43 ] = V_24 ;
}
} else {
for ( V_43 = 0 ; V_43 < V_47 ; V_43 ++ )
V_49 [ V_43 ] = V_48 [ V_43 ] ;
}
if ( V_51 )
V_5 -> V_23 |= V_55 ;
else
V_5 -> V_23 &= ~ V_55 ;
return V_49 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_50 ( V_5 != NULL ) ;
V_5 = F_46 ( sizeof( struct V_4 ) , V_53 ) ;
if ( ! V_5 )
return - V_56 ;
F_51 ( & V_5 -> V_57 ) ;
F_52 ( & V_5 -> V_21 ) ;
F_53 ( & V_5 -> V_30 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_54 ( struct V_1 * V_2 )
{
F_55 (!mdev->bitmap) return 0 ;
return V_2 -> V_6 -> V_58 ;
}
void F_56 ( struct V_1 * V_2 )
{
F_55 (!mdev->bitmap) return;
F_39 ( V_2 -> V_6 -> V_29 , V_2 -> V_6 -> V_38 ) ;
F_42 ( V_2 -> V_6 -> V_29 , ( V_55 & V_2 -> V_6 -> V_23 ) ) ;
F_44 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_57 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_40 , * V_60 ;
int V_61 ;
int V_62 = 0 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_58 ( V_59 ) ;
V_40 = F_35 ( V_5 , V_5 -> V_38 - 1 ) ;
V_60 = V_40 + ( V_61 / V_66 ) ;
if ( V_59 ) {
V_62 = F_59 ( * V_60 & ~ V_59 ) ;
* V_60 &= V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_40 ) & 1 ) == 1 ) {
V_62 += F_59 ( * V_60 ) ;
* V_60 = 0 ;
}
F_38 ( V_40 ) ;
return V_62 ;
}
static void F_60 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_40 , * V_60 ;
int V_61 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_58 ( V_59 ) ;
V_40 = F_35 ( V_5 , V_5 -> V_38 - 1 ) ;
V_60 = V_40 + ( V_61 / V_66 ) ;
if ( V_59 ) {
* V_60 |= ~ V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_40 ) & 1 ) == 1 ) {
* V_60 = ~ 0UL ;
}
F_38 ( V_40 ) ;
}
static unsigned long F_61 ( struct V_4 * V_5 )
{
unsigned long * V_40 ;
unsigned long V_67 = 0 ;
unsigned long V_59 = ( 1UL << ( V_5 -> V_63 & V_65 ) ) - 1 ;
int V_25 , V_43 , V_68 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_38 - 1 ; V_25 ++ ) {
V_40 = F_33 ( V_5 , V_25 ) ;
for ( V_43 = 0 ; V_43 < V_69 ; V_43 ++ )
V_67 += F_59 ( V_40 [ V_43 ] ) ;
F_36 ( V_40 ) ;
F_62 () ;
}
V_68 = ( ( V_5 -> V_63 - 1 ) & V_64 ) >> V_37 ;
V_40 = F_33 ( V_5 , V_25 ) ;
for ( V_43 = 0 ; V_43 < V_68 ; V_43 ++ )
V_67 += F_59 ( V_40 [ V_43 ] ) ;
V_40 [ V_68 ] &= F_58 ( V_59 ) ;
V_67 += F_59 ( V_40 [ V_68 ] ) ;
if ( V_66 == 32 && ( V_68 & 1 ) == 0 )
V_40 [ V_68 + 1 ] = 0 ;
F_36 ( V_40 ) ;
return V_67 ;
}
static void F_63 ( struct V_4 * V_5 , T_3 V_70 , int V_71 , T_3 V_72 )
{
unsigned long * V_40 , * V_60 ;
unsigned int V_25 ;
T_3 V_73 , V_74 ;
V_74 = V_70 + V_72 ;
if ( V_74 > V_5 -> V_75 ) {
F_40 ( V_44 L_13 ) ;
return;
}
while ( V_70 < V_74 ) {
V_73 = F_64 ( T_3 , F_65 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_25 = F_31 ( V_5 , V_70 ) ;
V_40 = F_35 ( V_5 , V_25 ) ;
V_60 = V_40 + F_66 ( V_70 ) ;
if ( V_60 + V_73 > V_40 + V_69 ) {
F_40 ( V_44 L_14 ,
V_40 , V_60 , ( int ) V_73 ) ;
} else
memset ( V_60 , V_71 , V_73 * sizeof( long ) ) ;
F_38 ( V_40 ) ;
F_23 ( V_5 -> V_29 [ V_25 ] ) ;
V_70 += V_73 ;
}
}
int F_67 ( struct V_1 * V_2 , T_2 V_76 , int V_77 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_67 , V_78 , V_79 , V_80 ;
unsigned long V_47 , V_52 , V_81 ;
struct V_24 * * V_82 , * * V_83 = NULL ;
int V_84 = 0 , V_85 ;
int V_86 ;
F_55 (!b) return - V_56 ;
F_4 ( V_2 , L_15 , V_22 ) ;
F_68 ( V_8 , L_16 ,
( unsigned long long ) V_76 ) ;
if ( V_76 == V_5 -> V_58 )
goto V_87;
V_86 = ( V_55 & V_5 -> V_23 ) ;
if ( V_76 == 0 ) {
F_69 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_29 ;
V_81 = V_5 -> V_38 ;
V_79 = V_5 -> V_75 ;
V_5 -> V_29 = NULL ;
V_5 -> V_38 =
V_5 -> V_88 =
V_5 -> V_63 =
V_5 -> V_75 =
V_5 -> V_58 = 0 ;
F_70 ( & V_5 -> V_57 ) ;
F_39 ( V_83 , V_81 ) ;
F_42 ( V_83 , V_86 ) ;
goto V_87;
}
V_67 = F_71 ( F_65 ( V_76 , V_89 ) ) ;
V_78 = F_65 ( V_67 , 64 ) >> V_37 ;
if ( F_72 ( V_2 ) ) {
T_1 V_90 = ( ( T_1 ) V_2 -> V_91 -> V_92 . V_93 - V_94 ) << 12 ;
F_73 ( V_2 ) ;
if ( V_67 > V_90 ) {
F_68 ( V_8 , L_17 , V_67 ) ;
F_68 ( V_8 , L_18 , V_90 ) ;
V_84 = - V_95 ;
goto V_87;
}
}
V_47 = F_65 ( V_78 * sizeof( long ) , V_96 ) >> V_36 ;
V_52 = V_5 -> V_38 ;
if ( V_47 == V_52 ) {
F_74 ( V_5 -> V_29 != NULL ) ;
V_82 = V_5 -> V_29 ;
} else {
if ( F_75 ( V_2 , V_97 ) )
V_82 = NULL ;
else
V_82 = F_45 ( V_5 , V_47 ) ;
}
if ( ! V_82 ) {
V_84 = - V_56 ;
goto V_87;
}
F_69 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_29 ;
V_79 = V_5 -> V_75 ;
V_80 = V_5 -> V_63 ;
V_85 = V_67 > V_80 ;
if ( V_83 && V_85 && V_77 )
F_60 ( V_5 ) ;
V_5 -> V_29 = V_82 ;
V_5 -> V_38 = V_47 ;
V_5 -> V_63 = V_67 ;
V_5 -> V_75 = V_78 ;
V_5 -> V_58 = V_76 ;
if ( V_85 ) {
if ( V_77 ) {
F_63 ( V_5 , V_79 , 0xff , V_78 - V_79 ) ;
V_5 -> V_88 += V_67 - V_80 ;
} else
F_63 ( V_5 , V_79 , 0x00 , V_78 - V_79 ) ;
}
if ( V_47 < V_52 ) {
F_39 ( V_83 + V_47 , V_52 - V_47 ) ;
}
( void ) F_57 ( V_5 ) ;
F_70 ( & V_5 -> V_57 ) ;
if ( V_83 != V_82 )
F_42 ( V_83 , V_86 ) ;
if ( ! V_85 )
V_5 -> V_88 = F_61 ( V_5 ) ;
F_68 ( V_8 , L_19 , V_67 , V_78 , V_47 ) ;
V_87:
F_8 ( V_2 ) ;
return V_84 ;
}
unsigned long F_76 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_98 ;
unsigned long V_19 ;
F_55 (!b) return 0 ;
F_55 (!b->bm_pages) return 0 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
V_98 = V_5 -> V_88 ;
F_78 ( & V_5 -> V_57 , V_19 ) ;
return V_98 ;
}
unsigned long F_79 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
if ( ! F_80 ( V_2 , V_99 ) )
return 0 ;
V_98 = F_76 ( V_2 ) ;
F_73 ( V_2 ) ;
return V_98 ;
}
T_3 F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_55 (!b) return 0 ;
F_55 (!b->bm_pages) return 0 ;
return V_5 -> V_75 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_55 (!b) return 0 ;
return V_5 -> V_63 ;
}
void F_83 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_42 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
unsigned long V_101 , V_67 ;
unsigned int V_25 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_42 ;
F_55 (!b) return;
F_55 (!b->bm_pages) return;
if ( V_42 == 0 )
return;
F_50 ( V_70 >= V_5 -> V_75 ) ;
F_50 ( V_74 > V_5 -> V_75 ) ;
F_69 ( & V_5 -> V_57 ) ;
while ( V_70 < V_74 ) {
V_73 = F_64 ( T_3 , F_65 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_25 = F_31 ( V_5 , V_70 ) ;
V_40 = F_35 ( V_5 , V_25 ) ;
V_60 = V_40 + F_66 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- ) {
V_67 = F_59 ( * V_60 ) ;
V_101 = * V_60 | * V_100 ++ ;
* V_60 ++ = V_101 ;
V_5 -> V_88 += F_59 ( V_101 ) - V_67 ;
}
F_38 ( V_40 ) ;
F_23 ( V_5 -> V_29 [ V_25 ] ) ;
}
if ( V_74 == V_5 -> V_75 )
V_5 -> V_88 -= F_57 ( V_5 ) ;
F_70 ( & V_5 -> V_57 ) ;
}
void F_84 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_42 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_42 ;
F_55 (!b) return;
F_55 (!b->bm_pages) return;
F_69 ( & V_5 -> V_57 ) ;
if ( ( V_70 >= V_5 -> V_75 ) ||
( V_74 > V_5 -> V_75 ) ||
( V_42 <= 0 ) )
F_3 ( V_8 , L_20 ,
( unsigned long ) V_70 ,
( unsigned long ) V_42 ,
( unsigned long ) V_5 -> V_75 ) ;
else {
while ( V_70 < V_74 ) {
V_73 = F_64 ( T_3 , F_65 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_40 = F_35 ( V_5 , F_31 ( V_5 , V_70 ) ) ;
V_60 = V_40 + F_66 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- )
* V_100 ++ = * V_60 ++ ;
F_38 ( V_40 ) ;
}
}
F_70 ( & V_5 -> V_57 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_55 (!b) return;
F_55 (!b->bm_pages) return;
F_69 ( & V_5 -> V_57 ) ;
F_63 ( V_5 , 0 , 0xff , V_5 -> V_75 ) ;
( void ) F_57 ( V_5 ) ;
V_5 -> V_88 = V_5 -> V_63 ;
F_70 ( & V_5 -> V_57 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_55 (!b) return;
F_55 (!b->bm_pages) return;
F_69 ( & V_5 -> V_57 ) ;
F_63 ( V_5 , 0 , 0 , V_5 -> V_75 ) ;
V_5 -> V_88 = 0 ;
F_70 ( & V_5 -> V_57 ) ;
}
static void F_87 ( struct V_102 * V_102 )
{
struct V_103 * V_104 = F_88 ( V_102 , struct V_103 , V_102 ) ;
F_73 ( V_104 -> V_2 ) ;
F_44 ( V_104 ) ;
}
static void F_89 ( struct V_105 * V_105 , int error )
{
struct V_103 * V_104 = V_105 -> V_106 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_25 = F_13 ( V_105 -> V_107 [ 0 ] . V_108 ) ;
int V_109 = F_90 ( V_105 , V_110 ) ;
if ( ! error && ! V_109 )
error = - V_111 ;
if ( ( V_104 -> V_19 & V_112 ) == 0 &&
! F_25 ( V_5 -> V_29 [ V_25 ] ) )
F_6 ( V_8 , L_21 , V_25 ) ;
if ( error ) {
V_104 -> error = error ;
F_26 ( V_5 -> V_29 [ V_25 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_8 , L_22 ,
error , V_25 ) ;
} else {
F_27 ( V_5 -> V_29 [ V_25 ] ) ;
F_91 ( V_8 , L_23 , V_25 ) ;
}
F_18 ( V_2 , V_25 ) ;
if ( V_104 -> V_19 & V_112 )
F_92 ( V_105 -> V_107 [ 0 ] . V_108 , V_113 ) ;
F_93 ( V_105 ) ;
if ( F_94 ( & V_104 -> V_114 ) ) {
V_104 -> V_115 = 1 ;
F_21 ( & V_2 -> V_116 ) ;
F_95 ( & V_104 -> V_102 , & F_87 ) ;
}
}
static void F_96 ( struct V_103 * V_104 , int V_27 , int V_117 ) __must_hold( T_4 )
{
struct V_105 * V_105 = F_97 ( V_118 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_24 ;
unsigned int V_72 ;
T_2 V_119 =
V_2 -> V_91 -> V_92 . V_120 + V_2 -> V_91 -> V_92 . V_121 ;
V_119 += ( ( T_2 ) V_27 ) << ( V_36 - 9 ) ;
V_72 = F_64 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(mdev->ldev) - on_disk_sector + 1)<<9 ) ;
F_15 ( V_2 , V_27 ) ;
F_22 ( V_5 -> V_29 [ V_27 ] ) ;
if ( V_104 -> V_19 & V_112 ) {
void * V_122 , * V_123 ;
V_24 = F_98 ( V_113 , V_124 | V_125 ) ;
V_123 = F_34 ( V_24 ) ;
V_122 = F_34 ( V_5 -> V_29 [ V_27 ] ) ;
memcpy ( V_123 , V_122 , V_96 ) ;
F_37 ( V_122 ) ;
F_37 ( V_123 ) ;
F_10 ( V_24 , V_27 ) ;
} else
V_24 = V_5 -> V_29 [ V_27 ] ;
V_105 -> V_126 = V_2 -> V_91 -> V_127 ;
V_105 -> V_128 = V_119 ;
F_99 ( V_105 , V_24 , V_72 , 0 ) ;
V_105 -> V_106 = V_104 ;
V_105 -> V_129 = F_89 ;
if ( F_75 ( V_2 , ( V_117 & V_130 ) ? V_131 : V_132 ) ) {
V_105 -> V_133 |= V_117 ;
F_100 ( V_105 , - V_111 ) ;
} else {
F_101 ( V_117 , V_105 ) ;
F_102 ( V_72 >> 9 , & V_2 -> V_134 ) ;
}
}
static int F_103 ( struct V_1 * V_2 , int V_117 , unsigned V_19 , unsigned V_135 ) __must_hold( T_4 )
{
struct V_103 * V_104 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_136 , V_43 , V_137 = 0 ;
unsigned long V_138 ;
char V_139 [ 10 ] ;
int V_84 = 0 ;
V_104 = F_104 ( sizeof( struct V_103 ) , V_118 ) ;
if ( ! V_104 )
return - V_56 ;
* V_104 = (struct V_103 ) {
. V_2 = V_2 ,
. V_114 = F_105 ( 1 ) ,
. V_115 = 0 ,
. V_19 = V_19 ,
. error = 0 ,
. V_102 = { F_105 ( 2 ) } ,
} ;
if ( ! F_80 ( V_2 , V_140 ) ) {
F_3 ( V_8 , L_24 ) ;
F_44 ( V_104 ) ;
return - V_141 ;
}
if ( ! V_104 -> V_19 )
F_50 ( ! ( V_22 & V_5 -> V_23 ) ) ;
V_136 = V_5 -> V_38 ;
V_138 = V_142 ;
for ( V_43 = 0 ; V_43 < V_136 ; V_43 ++ ) {
if ( V_135 && V_43 == V_135 )
break;
if ( V_117 & V_130 ) {
if ( ! ( V_19 & V_143 ) &&
F_25 ( V_5 -> V_29 [ V_43 ] ) ) {
F_91 ( V_8 , L_25 , V_43 ) ;
continue;
}
if ( V_135 &&
! F_29 ( V_5 -> V_29 [ V_43 ] ) ) {
F_91 ( V_8 , L_26 , V_43 ) ;
continue;
}
}
F_106 ( & V_104 -> V_114 ) ;
F_96 ( V_104 , V_43 , V_117 ) ;
++ V_137 ;
F_62 () ;
}
if ( ! F_94 ( & V_104 -> V_114 ) )
F_107 ( V_2 , V_2 -> V_91 , & V_104 -> V_115 ) ;
else
F_95 ( & V_104 -> V_102 , & F_87 ) ;
F_68 ( V_8 , L_27 ,
V_117 == V_130 ? L_28 : L_29 ,
V_137 , V_142 - V_138 ) ;
if ( V_104 -> error ) {
F_108 ( V_8 , L_30 ) ;
F_109 ( V_2 , 1 , V_144 ) ;
V_84 = - V_111 ;
}
if ( F_110 ( & V_104 -> V_114 ) )
V_84 = - V_111 ;
V_138 = V_142 ;
if ( V_117 == V_130 ) {
F_111 ( V_2 ) ;
} else {
V_5 -> V_88 = F_61 ( V_5 ) ;
F_68 ( V_8 , L_31 ,
V_142 - V_138 ) ;
}
V_138 = V_5 -> V_88 ;
F_68 ( V_8 , L_32 ,
F_112 ( V_139 , V_138 << ( V_145 - 10 ) ) , V_138 ) ;
F_95 ( & V_104 -> V_102 , & F_87 ) ;
return V_84 ;
}
int F_113 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_103 ( V_2 , V_146 , 0 , 0 ) ;
}
int F_114 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_103 ( V_2 , V_130 , 0 , 0 ) ;
}
int F_115 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_103 ( V_2 , V_130 , V_143 , 0 ) ;
}
int F_116 ( struct V_1 * V_2 , unsigned V_147 ) __must_hold( T_4 )
{
return F_103 ( V_2 , V_130 , V_112 , V_147 ) ;
}
int F_117 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_103 ( V_2 , V_130 , V_112 , 0 ) ;
}
int F_118 ( struct V_1 * V_2 , unsigned int V_25 ) __must_hold( T_4 )
{
struct V_103 * V_104 ;
int V_84 ;
if ( F_25 ( V_2 -> V_6 -> V_29 [ V_25 ] ) ) {
F_91 ( V_8 , L_33 , V_25 ) ;
return 0 ;
}
V_104 = F_104 ( sizeof( struct V_103 ) , V_118 ) ;
if ( ! V_104 )
return - V_56 ;
* V_104 = (struct V_103 ) {
. V_2 = V_2 ,
. V_114 = F_105 ( 1 ) ,
. V_115 = 0 ,
. V_19 = V_112 ,
. error = 0 ,
. V_102 = { F_105 ( 2 ) } ,
} ;
if ( ! F_80 ( V_2 , V_140 ) ) {
F_3 ( V_8 , L_34 ) ;
F_44 ( V_104 ) ;
return - V_141 ;
}
F_96 ( V_104 , V_25 , V_148 ) ;
F_107 ( V_2 , V_2 -> V_91 , & V_104 -> V_115 ) ;
if ( V_104 -> error )
F_109 ( V_2 , 1 , V_144 ) ;
V_2 -> V_149 ++ ;
V_84 = F_110 ( & V_104 -> V_114 ) ? - V_111 : V_104 -> error ;
F_95 ( & V_104 -> V_102 , & F_87 ) ;
return V_84 ;
}
static unsigned long F_119 ( struct V_1 * V_2 , unsigned long V_150 ,
const int V_151 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 ;
unsigned long V_152 ;
unsigned V_43 ;
if ( V_150 > V_5 -> V_63 ) {
F_3 ( V_8 , L_35 , V_150 , V_5 -> V_63 ) ;
V_150 = V_153 ;
} else {
while ( V_150 < V_5 -> V_63 ) {
V_152 = V_150 & ~ V_64 ;
V_40 = F_33 ( V_5 , F_32 ( V_5 , V_150 ) ) ;
if ( V_151 )
V_43 = F_120 ( V_40 ,
V_96 * 8 , V_150 & V_64 ) ;
else
V_43 = F_121 ( V_40 ,
V_96 * 8 , V_150 & V_64 ) ;
F_36 ( V_40 ) ;
if ( V_43 < V_96 * 8 ) {
V_150 = V_152 + V_43 ;
if ( V_150 >= V_5 -> V_63 )
break;
goto V_154;
}
V_150 = V_152 + V_96 * 8 ;
}
V_150 = V_153 ;
}
V_154:
return V_150 ;
}
static unsigned long F_122 ( struct V_1 * V_2 ,
unsigned long V_150 , const int V_151 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_43 = V_153 ;
F_55 (!b) return V_43 ;
F_55 (!b->bm_pages) return V_43 ;
F_69 ( & V_5 -> V_57 ) ;
if ( V_155 & V_5 -> V_23 )
F_123 ( V_2 ) ;
V_43 = F_119 ( V_2 , V_150 , V_151 ) ;
F_70 ( & V_5 -> V_57 ) ;
return V_43 ;
}
unsigned long F_124 ( struct V_1 * V_2 , unsigned long V_150 )
{
return F_122 ( V_2 , V_150 , 0 ) ;
}
unsigned long F_125 ( struct V_1 * V_2 , unsigned long V_150 )
{
return F_119 ( V_2 , V_150 , 0 ) ;
}
unsigned long F_126 ( struct V_1 * V_2 , unsigned long V_150 )
{
return F_119 ( V_2 , V_150 , 1 ) ;
}
static int F_127 ( struct V_1 * V_2 , const unsigned long V_98 ,
unsigned long V_156 , int V_157 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 = NULL ;
unsigned long V_39 ;
unsigned int V_158 = - 1U ;
int V_71 = 0 ;
int V_159 = 0 ;
if ( V_156 >= V_5 -> V_63 ) {
F_3 ( V_8 , L_36 ,
V_98 , V_156 , V_5 -> V_63 ) ;
V_156 = V_5 -> V_63 ? V_5 -> V_63 - 1 : 0 ;
}
for ( V_39 = V_98 ; V_39 <= V_156 ; V_39 ++ ) {
unsigned int V_27 = F_32 ( V_5 , V_39 ) ;
if ( V_27 != V_158 ) {
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_71 < 0 )
F_28 ( V_5 -> V_29 [ V_158 ] ) ;
else if ( V_71 > 0 )
F_23 ( V_5 -> V_29 [ V_158 ] ) ;
V_159 += V_71 ;
V_71 = 0 ;
V_40 = F_33 ( V_5 , V_27 ) ;
V_158 = V_27 ;
}
if ( V_157 )
V_71 += ( 0 == F_128 ( V_39 & V_64 , V_40 ) ) ;
else
V_71 -= ( 0 != F_129 ( V_39 & V_64 , V_40 ) ) ;
}
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_71 < 0 )
F_28 ( V_5 -> V_29 [ V_158 ] ) ;
else if ( V_71 > 0 )
F_23 ( V_5 -> V_29 [ V_158 ] ) ;
V_159 += V_71 ;
V_5 -> V_88 += V_159 ;
return V_159 ;
}
static int F_130 ( struct V_1 * V_2 , const unsigned long V_98 ,
const unsigned long V_156 , int V_157 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_71 = 0 ;
F_55 (!b) return 1 ;
F_55 (!b->bm_pages) return 0 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
if ( ( V_157 ? V_160 : V_161 ) & V_5 -> V_23 )
F_123 ( V_2 ) ;
V_71 = F_127 ( V_2 , V_98 , V_156 , V_157 ) ;
F_78 ( & V_5 -> V_57 , V_19 ) ;
return V_71 ;
}
int F_131 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_156 )
{
return F_130 ( V_2 , V_98 , V_156 , 1 ) ;
}
int F_132 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_156 )
{
return - F_130 ( V_2 , V_98 , V_156 , 0 ) ;
}
static inline void F_133 ( struct V_4 * V_5 ,
int V_27 , int V_162 , int V_68 )
{
int V_43 ;
int V_67 ;
unsigned long * V_163 = F_34 ( V_5 -> V_29 [ V_27 ] ) ;
for ( V_43 = V_162 ; V_43 < V_68 ; V_43 ++ ) {
V_67 = F_59 ( V_163 [ V_43 ] ) ;
V_163 [ V_43 ] = ~ 0UL ;
V_5 -> V_88 += V_66 - V_67 ;
}
F_37 ( V_163 ) ;
}
void F_134 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_156 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_164 = F_65 ( V_98 , V_66 ) ;
unsigned long V_165 = ( V_156 + 1 ) & ~ ( ( unsigned long ) V_66 - 1 ) ;
int V_166 ;
int V_167 ;
int V_27 ;
int V_162 ;
int V_68 ;
if ( V_156 - V_98 <= 3 * V_66 ) {
F_69 ( & V_5 -> V_57 ) ;
F_127 ( V_2 , V_98 , V_156 , 1 ) ;
F_70 ( & V_5 -> V_57 ) ;
return;
}
F_69 ( & V_5 -> V_57 ) ;
if ( V_164 )
F_127 ( V_2 , V_98 , V_164 - 1 , 1 ) ;
V_166 = V_164 >> ( 3 + V_36 ) ;
V_167 = V_165 >> ( 3 + V_36 ) ;
V_162 = F_66 ( V_164 >> V_37 ) ;
V_68 = V_69 ;
for ( V_27 = V_166 ; V_27 < V_167 ; V_27 ++ ) {
F_133 ( V_2 -> V_6 , V_27 , V_162 , V_68 ) ;
F_70 ( & V_5 -> V_57 ) ;
F_62 () ;
V_162 = 0 ;
F_69 ( & V_5 -> V_57 ) ;
}
V_68 = F_66 ( V_165 >> V_37 ) ;
if ( V_68 )
F_133 ( V_2 -> V_6 , V_167 , V_162 , V_68 ) ;
if ( V_165 <= V_156 )
F_127 ( V_2 , V_165 , V_156 , 1 ) ;
F_70 ( & V_5 -> V_57 ) ;
}
int F_135 ( struct V_1 * V_2 , const unsigned long V_39 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 ;
int V_43 ;
F_55 (!b) return 0 ;
F_55 (!b->bm_pages) return 0 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
if ( V_155 & V_5 -> V_23 )
F_123 ( V_2 ) ;
if ( V_39 < V_5 -> V_63 ) {
V_40 = F_35 ( V_5 , F_32 ( V_5 , V_39 ) ) ;
V_43 = F_136 ( V_39 & V_64 , V_40 ) ? 1 : 0 ;
F_38 ( V_40 ) ;
} else if ( V_39 == V_5 -> V_63 ) {
V_43 = - 1 ;
} else {
F_3 ( V_8 , L_37 , V_39 , V_5 -> V_63 ) ;
V_43 = 0 ;
}
F_78 ( & V_5 -> V_57 , V_19 ) ;
return V_43 ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_156 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 = NULL ;
unsigned long V_39 ;
unsigned int V_27 = - 1U ;
int V_71 = 0 ;
F_55 (!b) return 1 ;
F_55 (!b->bm_pages) return 1 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
if ( V_155 & V_5 -> V_23 )
F_123 ( V_2 ) ;
for ( V_39 = V_98 ; V_39 <= V_156 ; V_39 ++ ) {
unsigned int V_25 = F_32 ( V_5 , V_39 ) ;
if ( V_27 != V_25 ) {
V_27 = V_25 ;
if ( V_40 )
F_38 ( V_40 ) ;
V_40 = F_35 ( V_5 , V_25 ) ;
}
F_55 (bitnr >= b->bm_bits) {
F_3 ( V_8 , L_38 , V_39 , V_5 -> V_63 ) ;
} else {
V_71 += ( 0 != F_136 ( V_39 - ( V_27 << ( V_36 + 3 ) ) , V_40 ) ) ;
}
}
if ( V_40 )
F_38 ( V_40 ) ;
F_78 ( & V_5 -> V_57 , V_19 ) ;
return V_71 ;
}
int F_138 ( struct V_1 * V_2 , unsigned long V_168 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_137 , V_98 , V_156 ;
unsigned long V_19 ;
unsigned long * V_40 , * V_60 ;
F_55 (!b) return 0 ;
F_55 (!b->bm_pages) return 0 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
if ( V_155 & V_5 -> V_23 )
F_123 ( V_2 ) ;
V_98 = F_139 ( V_168 ) ;
V_156 = F_140 ( ( T_3 ) F_139 ( V_168 + 1 ) , V_5 -> V_75 ) ;
V_137 = 0 ;
if ( V_98 < V_5 -> V_75 ) {
int V_169 = V_156 - V_98 ;
V_40 = F_35 ( V_5 , F_31 ( V_5 , V_98 ) ) ;
V_60 = V_40 + F_66 ( V_98 ) ;
while ( V_169 -- )
V_137 += F_59 ( * V_60 ++ ) ;
F_38 ( V_40 ) ;
} else {
F_3 ( V_8 , L_39 , V_98 ) ;
}
F_78 ( & V_5 -> V_57 , V_19 ) ;
return V_137 ;
}
unsigned long F_141 ( struct V_1 * V_2 , unsigned long V_170 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
unsigned long V_171 ;
unsigned long V_98 , V_156 ;
int V_137 , V_43 , V_73 ;
F_55 (!b) return 0 ;
F_55 (!b->bm_pages) return 0 ;
F_69 ( & V_5 -> V_57 ) ;
if ( V_160 & V_5 -> V_23 )
F_123 ( V_2 ) ;
V_171 = V_5 -> V_88 ;
V_98 = V_170 * V_172 ;
V_156 = F_64 ( T_3 , V_98 + V_172 , V_5 -> V_75 ) ;
F_74 ( ( V_156 - 1 ) >> ( V_36 - V_37 + 3 )
== V_98 >> ( V_36 - V_37 + 3 ) ) ;
V_137 = 0 ;
if ( V_98 < V_5 -> V_75 ) {
V_43 = V_73 = V_156 - V_98 ;
V_40 = F_35 ( V_5 , F_31 ( V_5 , V_98 ) ) ;
V_60 = V_40 + F_66 ( V_98 ) ;
while ( V_43 -- ) {
V_137 += F_59 ( * V_60 ) ;
* V_60 = - 1UL ;
V_60 ++ ;
}
F_38 ( V_40 ) ;
V_5 -> V_88 += V_73 * V_66 - V_137 ;
if ( V_156 == V_5 -> V_75 )
V_5 -> V_88 -= F_57 ( V_5 ) ;
} else {
F_3 ( V_8 , L_40 , V_98 ) ;
}
V_171 = V_5 -> V_88 - V_171 ;
F_70 ( & V_5 -> V_57 ) ;
return V_171 ;
}
