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
static unsigned long * F_32 ( struct V_4 * V_5 , unsigned int V_25 )
{
struct V_24 * V_24 = V_5 -> V_29 [ V_25 ] ;
return ( unsigned long * ) F_33 ( V_24 ) ;
}
static unsigned long * F_34 ( struct V_4 * V_5 , unsigned int V_25 )
{
return F_32 ( V_5 , V_25 ) ;
}
static void F_35 ( unsigned long * V_40 )
{
F_36 ( V_40 ) ;
}
static void F_37 ( unsigned long * V_40 )
{
return F_35 ( V_40 ) ;
}
static void F_38 ( struct V_24 * * V_41 , unsigned long V_42 )
{
unsigned long V_43 ;
if ( ! V_41 )
return;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( ! V_41 [ V_43 ] ) {
F_39 ( V_44 L_11
L_12 ,
V_43 , V_42 ) ;
continue;
}
F_40 ( V_41 [ V_43 ] ) ;
V_41 [ V_43 ] = NULL ;
}
}
static void F_41 ( void * V_45 , int V_46 )
{
if ( V_46 )
F_42 ( V_45 ) ;
else
F_43 ( V_45 ) ;
}
static struct V_24 * * F_44 ( struct V_4 * V_5 , unsigned long V_47 )
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
V_49 = F_45 ( V_50 , V_53 ) ;
if ( ! V_49 ) {
V_49 = F_46 ( V_50 ) ;
if ( ! V_49 )
return NULL ;
V_51 = 1 ;
}
if ( V_47 >= V_52 ) {
for ( V_43 = 0 ; V_43 < V_52 ; V_43 ++ )
V_49 [ V_43 ] = V_48 [ V_43 ] ;
for (; V_43 < V_47 ; V_43 ++ ) {
V_24 = F_47 ( V_54 ) ;
if ( ! V_24 ) {
F_38 ( V_49 + V_52 , V_43 - V_52 ) ;
F_41 ( V_49 , V_51 ) ;
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
int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_49 ( V_5 != NULL ) ;
V_5 = F_45 ( sizeof( struct V_4 ) , V_53 ) ;
if ( ! V_5 )
return - V_56 ;
F_50 ( & V_5 -> V_57 ) ;
F_51 ( & V_5 -> V_21 ) ;
F_52 ( & V_5 -> V_30 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_53 ( struct V_1 * V_2 )
{
F_54 (!mdev->bitmap) return 0 ;
return V_2 -> V_6 -> V_58 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_54 (!mdev->bitmap) return;
F_38 ( V_2 -> V_6 -> V_29 , V_2 -> V_6 -> V_38 ) ;
F_41 ( V_2 -> V_6 -> V_29 , ( V_55 & V_2 -> V_6 -> V_23 ) ) ;
F_43 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_56 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_40 , * V_60 ;
int V_61 ;
int V_62 = 0 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_57 ( V_59 ) ;
V_40 = F_34 ( V_5 , V_5 -> V_38 - 1 ) ;
V_60 = V_40 + ( V_61 / V_66 ) ;
if ( V_59 ) {
V_62 = F_58 ( * V_60 & ~ V_59 ) ;
* V_60 &= V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_40 ) & 1 ) == 1 ) {
V_62 += F_58 ( * V_60 ) ;
* V_60 = 0 ;
}
F_37 ( V_40 ) ;
return V_62 ;
}
static void F_59 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_40 , * V_60 ;
int V_61 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_57 ( V_59 ) ;
V_40 = F_34 ( V_5 , V_5 -> V_38 - 1 ) ;
V_60 = V_40 + ( V_61 / V_66 ) ;
if ( V_59 ) {
* V_60 |= ~ V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_40 ) & 1 ) == 1 ) {
* V_60 = ~ 0UL ;
}
F_37 ( V_40 ) ;
}
static unsigned long F_60 ( struct V_4 * V_5 )
{
unsigned long * V_40 ;
unsigned long V_67 = 0 ;
unsigned long V_59 = ( 1UL << ( V_5 -> V_63 & V_65 ) ) - 1 ;
int V_25 , V_43 , V_68 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_38 - 1 ; V_25 ++ ) {
V_40 = F_32 ( V_5 , V_25 ) ;
for ( V_43 = 0 ; V_43 < V_69 ; V_43 ++ )
V_67 += F_58 ( V_40 [ V_43 ] ) ;
F_35 ( V_40 ) ;
F_61 () ;
}
V_68 = ( ( V_5 -> V_63 - 1 ) & V_64 ) >> V_37 ;
V_40 = F_32 ( V_5 , V_25 ) ;
for ( V_43 = 0 ; V_43 < V_68 ; V_43 ++ )
V_67 += F_58 ( V_40 [ V_43 ] ) ;
V_40 [ V_68 ] &= F_57 ( V_59 ) ;
V_67 += F_58 ( V_40 [ V_68 ] ) ;
if ( V_66 == 32 && ( V_68 & 1 ) == 0 )
V_40 [ V_68 + 1 ] = 0 ;
F_35 ( V_40 ) ;
return V_67 ;
}
static void F_62 ( struct V_4 * V_5 , T_3 V_70 , int V_71 , T_3 V_72 )
{
unsigned long * V_40 , * V_60 ;
unsigned int V_25 ;
T_3 V_73 , V_74 ;
V_74 = V_70 + V_72 ;
if ( V_74 > V_5 -> V_75 ) {
F_39 ( V_44 L_13 ) ;
return;
}
while ( V_70 < V_74 ) {
V_73 = F_63 ( T_3 , F_64 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_25 = F_30 ( V_5 , V_70 ) ;
V_40 = F_34 ( V_5 , V_25 ) ;
V_60 = V_40 + F_65 ( V_70 ) ;
if ( V_60 + V_73 > V_40 + V_69 ) {
F_39 ( V_44 L_14 ,
V_40 , V_60 , ( int ) V_73 ) ;
} else
memset ( V_60 , V_71 , V_73 * sizeof( long ) ) ;
F_37 ( V_40 ) ;
F_22 ( V_5 -> V_29 [ V_25 ] ) ;
V_70 += V_73 ;
}
}
int F_66 ( struct V_1 * V_2 , T_2 V_76 , int V_77 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_67 , V_78 , V_79 , V_80 ;
unsigned long V_47 , V_52 , V_81 ;
struct V_24 * * V_82 , * * V_83 = NULL ;
int V_84 = 0 , V_85 ;
int V_86 ;
F_54 (!b) return - V_56 ;
F_4 ( V_2 , L_15 , V_22 ) ;
F_67 ( V_8 , L_16 ,
( unsigned long long ) V_76 ) ;
if ( V_76 == V_5 -> V_58 )
goto V_87;
V_86 = ( V_55 & V_5 -> V_23 ) ;
if ( V_76 == 0 ) {
F_68 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_29 ;
V_81 = V_5 -> V_38 ;
V_79 = V_5 -> V_75 ;
V_5 -> V_29 = NULL ;
V_5 -> V_38 =
V_5 -> V_88 =
V_5 -> V_63 =
V_5 -> V_75 =
V_5 -> V_58 = 0 ;
F_69 ( & V_5 -> V_57 ) ;
F_38 ( V_83 , V_81 ) ;
F_41 ( V_83 , V_86 ) ;
goto V_87;
}
V_67 = F_70 ( F_64 ( V_76 , V_89 ) ) ;
V_78 = F_64 ( V_67 , 64 ) >> V_37 ;
if ( F_71 ( V_2 ) ) {
T_1 V_90 = ( ( T_1 ) V_2 -> V_91 -> V_92 . V_93 - V_94 ) << 12 ;
F_72 ( V_2 ) ;
if ( V_67 > V_90 ) {
F_67 ( V_8 , L_17 , V_67 ) ;
F_67 ( V_8 , L_18 , V_90 ) ;
V_84 = - V_95 ;
goto V_87;
}
}
V_47 = F_64 ( V_78 * sizeof( long ) , V_96 ) >> V_36 ;
V_52 = V_5 -> V_38 ;
if ( V_47 == V_52 ) {
F_73 ( V_5 -> V_29 != NULL ) ;
V_82 = V_5 -> V_29 ;
} else {
if ( F_74 ( V_2 , V_97 ) )
V_82 = NULL ;
else
V_82 = F_44 ( V_5 , V_47 ) ;
}
if ( ! V_82 ) {
V_84 = - V_56 ;
goto V_87;
}
F_68 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_29 ;
V_79 = V_5 -> V_75 ;
V_80 = V_5 -> V_63 ;
V_85 = V_67 > V_80 ;
if ( V_83 && V_85 && V_77 )
F_59 ( V_5 ) ;
V_5 -> V_29 = V_82 ;
V_5 -> V_38 = V_47 ;
V_5 -> V_63 = V_67 ;
V_5 -> V_75 = V_78 ;
V_5 -> V_58 = V_76 ;
if ( V_85 ) {
if ( V_77 ) {
F_62 ( V_5 , V_79 , 0xff , V_78 - V_79 ) ;
V_5 -> V_88 += V_67 - V_80 ;
} else
F_62 ( V_5 , V_79 , 0x00 , V_78 - V_79 ) ;
}
if ( V_47 < V_52 ) {
F_38 ( V_83 + V_47 , V_52 - V_47 ) ;
}
( void ) F_56 ( V_5 ) ;
F_69 ( & V_5 -> V_57 ) ;
if ( V_83 != V_82 )
F_41 ( V_83 , V_86 ) ;
if ( ! V_85 )
V_5 -> V_88 = F_60 ( V_5 ) ;
F_67 ( V_8 , L_19 , V_67 , V_78 , V_47 ) ;
V_87:
F_8 ( V_2 ) ;
return V_84 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_98 ;
unsigned long V_19 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_57 , V_19 ) ;
V_98 = V_5 -> V_88 ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
return V_98 ;
}
unsigned long F_78 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
if ( ! F_79 ( V_2 , V_99 ) )
return 0 ;
V_98 = F_75 ( V_2 ) ;
F_72 ( V_2 ) ;
return V_98 ;
}
T_3 F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
return V_5 -> V_75 ;
}
unsigned long F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return 0 ;
return V_5 -> V_63 ;
}
void F_82 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_42 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
unsigned long V_101 , V_67 ;
unsigned int V_25 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_42 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
if ( V_42 == 0 )
return;
F_49 ( V_70 >= V_5 -> V_75 ) ;
F_49 ( V_74 > V_5 -> V_75 ) ;
F_68 ( & V_5 -> V_57 ) ;
while ( V_70 < V_74 ) {
V_73 = F_63 ( T_3 , F_64 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_25 = F_30 ( V_5 , V_70 ) ;
V_40 = F_34 ( V_5 , V_25 ) ;
V_60 = V_40 + F_65 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- ) {
V_67 = F_58 ( * V_60 ) ;
V_101 = * V_60 | * V_100 ++ ;
* V_60 ++ = V_101 ;
V_5 -> V_88 += F_58 ( V_101 ) - V_67 ;
}
F_37 ( V_40 ) ;
F_22 ( V_5 -> V_29 [ V_25 ] ) ;
}
if ( V_74 == V_5 -> V_75 )
V_5 -> V_88 -= F_56 ( V_5 ) ;
F_69 ( & V_5 -> V_57 ) ;
}
void F_83 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_42 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_42 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_57 ) ;
if ( ( V_70 >= V_5 -> V_75 ) ||
( V_74 > V_5 -> V_75 ) ||
( V_42 <= 0 ) )
F_3 ( V_8 , L_20 ,
( unsigned long ) V_70 ,
( unsigned long ) V_42 ,
( unsigned long ) V_5 -> V_75 ) ;
else {
while ( V_70 < V_74 ) {
V_73 = F_63 ( T_3 , F_64 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_40 = F_34 ( V_5 , F_30 ( V_5 , V_70 ) ) ;
V_60 = V_40 + F_65 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- )
* V_100 ++ = * V_60 ++ ;
F_37 ( V_40 ) ;
}
}
F_69 ( & V_5 -> V_57 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_57 ) ;
F_62 ( V_5 , 0 , 0xff , V_5 -> V_75 ) ;
( void ) F_56 ( V_5 ) ;
V_5 -> V_88 = V_5 -> V_63 ;
F_69 ( & V_5 -> V_57 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_54 (!b) return;
F_54 (!b->bm_pages) return;
F_68 ( & V_5 -> V_57 ) ;
F_62 ( V_5 , 0 , 0 , V_5 -> V_75 ) ;
V_5 -> V_88 = 0 ;
F_69 ( & V_5 -> V_57 ) ;
}
static void F_86 ( struct V_102 * V_102 , int error )
{
struct V_103 * V_104 = V_102 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_25 = F_13 ( V_102 -> V_106 [ 0 ] . V_107 ) ;
int V_108 = F_87 ( V_102 , V_109 ) ;
if ( ! error && ! V_108 )
error = - V_110 ;
if ( ( V_104 -> V_19 & V_111 ) == 0 &&
! F_24 ( V_5 -> V_29 [ V_25 ] ) )
F_6 ( V_8 , L_21 , V_25 ) ;
if ( error ) {
V_104 -> error = error ;
F_25 ( V_5 -> V_29 [ V_25 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_8 , L_22 ,
error , V_25 ) ;
} else {
F_26 ( V_5 -> V_29 [ V_25 ] ) ;
F_88 ( V_8 , L_23 , V_25 ) ;
}
F_17 ( V_2 , V_25 ) ;
if ( V_104 -> V_19 & V_111 )
F_89 ( V_102 -> V_106 [ 0 ] . V_107 ) ;
F_90 ( V_102 ) ;
if ( F_91 ( & V_104 -> V_112 ) )
F_92 ( & V_104 -> V_113 ) ;
}
static void F_93 ( struct V_103 * V_104 , int V_27 , int V_114 ) __must_hold( T_4 )
{
struct V_102 * V_102 = F_94 ( V_53 , 1 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_24 ;
unsigned int V_72 ;
T_2 V_115 =
V_2 -> V_91 -> V_92 . V_116 + V_2 -> V_91 -> V_92 . V_117 ;
V_115 += ( ( T_2 ) V_27 ) << ( V_36 - 9 ) ;
V_72 = F_63 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(mdev->ldev) - on_disk_sector + 1)<<9 ) ;
F_14 ( V_2 , V_27 ) ;
F_21 ( V_5 -> V_29 [ V_27 ] ) ;
if ( V_104 -> V_19 & V_111 ) {
void * V_118 , * V_119 ;
V_24 = F_47 ( V_120 | V_121 ) ;
V_119 = F_33 ( V_24 ) ;
V_118 = F_33 ( V_5 -> V_29 [ V_27 ] ) ;
memcpy ( V_119 , V_118 , V_96 ) ;
F_36 ( V_118 ) ;
F_36 ( V_119 ) ;
F_10 ( V_24 , V_27 ) ;
} else
V_24 = V_5 -> V_29 [ V_27 ] ;
V_102 -> V_122 = V_2 -> V_91 -> V_123 ;
V_102 -> V_124 = V_115 ;
F_95 ( V_102 , V_24 , V_72 , 0 ) ;
V_102 -> V_105 = V_104 ;
V_102 -> V_125 = F_86 ;
if ( F_74 ( V_2 , ( V_114 & V_126 ) ? V_127 : V_128 ) ) {
V_102 -> V_129 |= V_114 ;
F_96 ( V_102 , - V_110 ) ;
} else {
F_97 ( V_114 , V_102 ) ;
F_98 ( V_72 >> 9 , & V_2 -> V_130 ) ;
}
}
static int F_99 ( struct V_1 * V_2 , int V_114 , unsigned V_131 ) __must_hold( T_4 )
{
struct V_103 V_104 = {
. V_2 = V_2 ,
. V_112 = F_100 ( 1 ) ,
. V_113 = F_101 ( V_104 . V_113 ) ,
. V_19 = V_131 ? V_111 : 0 ,
} ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_132 , V_43 , V_133 = 0 ;
unsigned long V_134 ;
char V_135 [ 10 ] ;
int V_84 = 0 ;
if ( ! V_104 . V_19 )
F_49 ( ! ( V_22 & V_5 -> V_23 ) ) ;
V_132 = V_5 -> V_38 ;
V_134 = V_136 ;
for ( V_43 = 0 ; V_43 < V_132 ; V_43 ++ ) {
if ( V_131 && V_43 == V_131 )
break;
if ( V_114 & V_126 ) {
if ( F_24 ( V_5 -> V_29 [ V_43 ] ) ) {
F_88 ( V_8 , L_24 , V_43 ) ;
continue;
}
if ( V_131 &&
! F_28 ( V_5 -> V_29 [ V_43 ] ) ) {
F_88 ( V_8 , L_25 , V_43 ) ;
continue;
}
}
F_102 ( & V_104 . V_112 ) ;
F_93 ( & V_104 , V_43 , V_114 ) ;
++ V_133 ;
F_61 () ;
}
if ( ! F_91 ( & V_104 . V_112 ) )
F_103 ( & V_104 . V_113 ) ;
F_67 ( V_8 , L_26 ,
V_114 == V_126 ? L_27 : L_28 ,
V_133 , V_136 - V_134 ) ;
if ( V_104 . error ) {
F_104 ( V_8 , L_29 ) ;
F_105 ( V_2 , 1 , true ) ;
V_84 = - V_110 ;
}
V_134 = V_136 ;
if ( V_114 == V_126 ) {
F_106 ( V_2 ) ;
} else {
V_5 -> V_88 = F_60 ( V_5 ) ;
F_67 ( V_8 , L_30 ,
V_136 - V_134 ) ;
}
V_134 = V_5 -> V_88 ;
F_67 ( V_8 , L_31 ,
F_107 ( V_135 , V_134 << ( V_137 - 10 ) ) , V_134 ) ;
return V_84 ;
}
int F_108 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_138 , 0 ) ;
}
int F_109 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_126 , 0 ) ;
}
int F_110 ( struct V_1 * V_2 , unsigned V_139 ) __must_hold( T_4 )
{
return F_99 ( V_2 , V_126 , V_139 ) ;
}
int F_111 ( struct V_1 * V_2 , unsigned int V_25 ) __must_hold( T_4 )
{
struct V_103 V_104 = {
. V_2 = V_2 ,
. V_112 = F_100 ( 1 ) ,
. V_113 = F_101 ( V_104 . V_113 ) ,
. V_19 = V_111 ,
} ;
if ( F_24 ( V_2 -> V_6 -> V_29 [ V_25 ] ) ) {
F_88 ( V_8 , L_32 , V_25 ) ;
return 0 ;
}
F_93 ( & V_104 , V_25 , V_140 ) ;
F_103 ( & V_104 . V_113 ) ;
if ( V_104 . error )
F_105 ( V_2 , 1 , true ) ;
V_2 -> V_141 ++ ;
return V_104 . error ;
}
static unsigned long F_112 ( struct V_1 * V_2 , unsigned long V_142 ,
const int V_143 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 ;
unsigned long V_144 ;
unsigned V_43 ;
if ( V_142 > V_5 -> V_63 ) {
F_3 ( V_8 , L_33 , V_142 , V_5 -> V_63 ) ;
V_142 = V_145 ;
} else {
while ( V_142 < V_5 -> V_63 ) {
V_144 = V_142 & ~ V_64 ;
V_40 = F_32 ( V_5 , F_31 ( V_5 , V_142 ) ) ;
if ( V_143 )
V_43 = F_113 ( V_40 ,
V_96 * 8 , V_142 & V_64 ) ;
else
V_43 = F_114 ( V_40 ,
V_96 * 8 , V_142 & V_64 ) ;
F_35 ( V_40 ) ;
if ( V_43 < V_96 * 8 ) {
V_142 = V_144 + V_43 ;
if ( V_142 >= V_5 -> V_63 )
break;
goto V_146;
}
V_142 = V_144 + V_96 * 8 ;
}
V_142 = V_145 ;
}
V_146:
return V_142 ;
}
static unsigned long F_115 ( struct V_1 * V_2 ,
unsigned long V_142 , const int V_143 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_43 = V_145 ;
F_54 (!b) return V_43 ;
F_54 (!b->bm_pages) return V_43 ;
F_68 ( & V_5 -> V_57 ) ;
if ( V_147 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_43 = F_112 ( V_2 , V_142 , V_143 ) ;
F_69 ( & V_5 -> V_57 ) ;
return V_43 ;
}
unsigned long F_117 ( struct V_1 * V_2 , unsigned long V_142 )
{
return F_115 ( V_2 , V_142 , 0 ) ;
}
unsigned long F_118 ( struct V_1 * V_2 , unsigned long V_142 )
{
return F_112 ( V_2 , V_142 , 0 ) ;
}
unsigned long F_119 ( struct V_1 * V_2 , unsigned long V_142 )
{
return F_112 ( V_2 , V_142 , 1 ) ;
}
static int F_120 ( struct V_1 * V_2 , const unsigned long V_98 ,
unsigned long V_148 , int V_149 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 = NULL ;
unsigned long V_39 ;
unsigned int V_150 = - 1U ;
int V_71 = 0 ;
int V_151 = 0 ;
if ( V_148 >= V_5 -> V_63 ) {
F_3 ( V_8 , L_34 ,
V_98 , V_148 , V_5 -> V_63 ) ;
V_148 = V_5 -> V_63 ? V_5 -> V_63 - 1 : 0 ;
}
for ( V_39 = V_98 ; V_39 <= V_148 ; V_39 ++ ) {
unsigned int V_27 = F_31 ( V_5 , V_39 ) ;
if ( V_27 != V_150 ) {
if ( V_40 )
F_35 ( V_40 ) ;
if ( V_71 < 0 )
F_27 ( V_5 -> V_29 [ V_150 ] ) ;
else if ( V_71 > 0 )
F_22 ( V_5 -> V_29 [ V_150 ] ) ;
V_151 += V_71 ;
V_71 = 0 ;
V_40 = F_32 ( V_5 , V_27 ) ;
V_150 = V_27 ;
}
if ( V_149 )
V_71 += ( 0 == F_121 ( V_39 & V_64 , V_40 ) ) ;
else
V_71 -= ( 0 != F_122 ( V_39 & V_64 , V_40 ) ) ;
}
if ( V_40 )
F_35 ( V_40 ) ;
if ( V_71 < 0 )
F_27 ( V_5 -> V_29 [ V_150 ] ) ;
else if ( V_71 > 0 )
F_22 ( V_5 -> V_29 [ V_150 ] ) ;
V_151 += V_71 ;
V_5 -> V_88 += V_151 ;
return V_151 ;
}
static int F_123 ( struct V_1 * V_2 , const unsigned long V_98 ,
const unsigned long V_148 , int V_149 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_71 = 0 ;
F_54 (!b) return 1 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_57 , V_19 ) ;
if ( ( V_149 ? V_152 : V_153 ) & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_71 = F_120 ( V_2 , V_98 , V_148 , V_149 ) ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
return V_71 ;
}
int F_124 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_148 )
{
return F_123 ( V_2 , V_98 , V_148 , 1 ) ;
}
int F_125 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_148 )
{
return - F_123 ( V_2 , V_98 , V_148 , 0 ) ;
}
static inline void F_126 ( struct V_4 * V_5 ,
int V_27 , int V_154 , int V_68 )
{
int V_43 ;
int V_67 ;
unsigned long * V_155 = F_33 ( V_5 -> V_29 [ V_27 ] ) ;
for ( V_43 = V_154 ; V_43 < V_68 ; V_43 ++ ) {
V_67 = F_58 ( V_155 [ V_43 ] ) ;
V_155 [ V_43 ] = ~ 0UL ;
V_5 -> V_88 += V_66 - V_67 ;
}
F_36 ( V_155 ) ;
}
void F_127 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_148 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_156 = F_64 ( V_98 , V_66 ) ;
unsigned long V_157 = ( V_148 + 1 ) & ~ ( ( unsigned long ) V_66 - 1 ) ;
int V_158 ;
int V_159 ;
int V_27 ;
int V_154 ;
int V_68 ;
if ( V_148 - V_98 <= 3 * V_66 ) {
F_68 ( & V_5 -> V_57 ) ;
F_120 ( V_2 , V_98 , V_148 , 1 ) ;
F_69 ( & V_5 -> V_57 ) ;
return;
}
F_68 ( & V_5 -> V_57 ) ;
if ( V_156 )
F_120 ( V_2 , V_98 , V_156 - 1 , 1 ) ;
V_158 = V_156 >> ( 3 + V_36 ) ;
V_159 = V_157 >> ( 3 + V_36 ) ;
V_154 = F_65 ( V_156 >> V_37 ) ;
V_68 = V_69 ;
for ( V_27 = V_158 ; V_27 < V_159 ; V_27 ++ ) {
F_126 ( V_2 -> V_6 , V_27 , V_154 , V_68 ) ;
F_69 ( & V_5 -> V_57 ) ;
F_61 () ;
V_154 = 0 ;
F_68 ( & V_5 -> V_57 ) ;
}
V_68 = F_65 ( V_157 >> V_37 ) ;
F_126 ( V_2 -> V_6 , V_159 , V_154 , V_68 ) ;
if ( V_157 <= V_148 )
F_120 ( V_2 , V_157 , V_148 , 1 ) ;
F_69 ( & V_5 -> V_57 ) ;
}
int F_128 ( struct V_1 * V_2 , const unsigned long V_39 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 ;
int V_43 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_57 , V_19 ) ;
if ( V_147 & V_5 -> V_23 )
F_116 ( V_2 ) ;
if ( V_39 < V_5 -> V_63 ) {
V_40 = F_34 ( V_5 , F_31 ( V_5 , V_39 ) ) ;
V_43 = F_129 ( V_39 & V_64 , V_40 ) ? 1 : 0 ;
F_37 ( V_40 ) ;
} else if ( V_39 == V_5 -> V_63 ) {
V_43 = - 1 ;
} else {
F_3 ( V_8 , L_35 , V_39 , V_5 -> V_63 ) ;
V_43 = 0 ;
}
F_77 ( & V_5 -> V_57 , V_19 ) ;
return V_43 ;
}
int F_130 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_148 )
{
unsigned long V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 = NULL ;
unsigned long V_39 ;
unsigned int V_27 = - 1U ;
int V_71 = 0 ;
F_54 (!b) return 1 ;
F_54 (!b->bm_pages) return 1 ;
F_76 ( & V_5 -> V_57 , V_19 ) ;
if ( V_147 & V_5 -> V_23 )
F_116 ( V_2 ) ;
for ( V_39 = V_98 ; V_39 <= V_148 ; V_39 ++ ) {
unsigned int V_25 = F_31 ( V_5 , V_39 ) ;
if ( V_27 != V_25 ) {
V_27 = V_25 ;
if ( V_40 )
F_37 ( V_40 ) ;
V_40 = F_34 ( V_5 , V_25 ) ;
}
F_54 (bitnr >= b->bm_bits) {
F_3 ( V_8 , L_36 , V_39 , V_5 -> V_63 ) ;
} else {
V_71 += ( 0 != F_129 ( V_39 - ( V_27 << ( V_36 + 3 ) ) , V_40 ) ) ;
}
}
if ( V_40 )
F_37 ( V_40 ) ;
F_77 ( & V_5 -> V_57 , V_19 ) ;
return V_71 ;
}
int F_131 ( struct V_1 * V_2 , unsigned long V_160 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_133 , V_98 , V_148 ;
unsigned long V_19 ;
unsigned long * V_40 , * V_60 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_76 ( & V_5 -> V_57 , V_19 ) ;
if ( V_147 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_98 = F_132 ( V_160 ) ;
V_148 = F_133 ( ( T_3 ) F_132 ( V_160 + 1 ) , V_5 -> V_75 ) ;
V_133 = 0 ;
if ( V_98 < V_5 -> V_75 ) {
int V_161 = V_148 - V_98 ;
V_40 = F_34 ( V_5 , F_30 ( V_5 , V_98 ) ) ;
V_60 = V_40 + F_65 ( V_98 ) ;
while ( V_161 -- )
V_133 += F_58 ( * V_60 ++ ) ;
F_37 ( V_40 ) ;
} else {
F_3 ( V_8 , L_37 , V_98 ) ;
}
F_77 ( & V_5 -> V_57 , V_19 ) ;
return V_133 ;
}
unsigned long F_134 ( struct V_1 * V_2 , unsigned long V_162 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_40 , * V_60 ;
unsigned long V_163 ;
unsigned long V_98 , V_148 ;
int V_133 , V_43 , V_73 ;
F_54 (!b) return 0 ;
F_54 (!b->bm_pages) return 0 ;
F_68 ( & V_5 -> V_57 ) ;
if ( V_152 & V_5 -> V_23 )
F_116 ( V_2 ) ;
V_163 = V_5 -> V_88 ;
V_98 = V_162 * V_164 ;
V_148 = F_63 ( T_3 , V_98 + V_164 , V_5 -> V_75 ) ;
F_73 ( ( V_148 - 1 ) >> ( V_36 - V_37 + 3 )
== V_98 >> ( V_36 - V_37 + 3 ) ) ;
V_133 = 0 ;
if ( V_98 < V_5 -> V_75 ) {
V_43 = V_73 = V_148 - V_98 ;
V_40 = F_34 ( V_5 , F_30 ( V_5 , V_98 ) ) ;
V_60 = V_40 + F_65 ( V_98 ) ;
while ( V_43 -- ) {
V_133 += F_58 ( * V_60 ) ;
* V_60 = - 1UL ;
V_60 ++ ;
}
F_37 ( V_40 ) ;
V_5 -> V_88 += V_73 * V_66 - V_133 ;
if ( V_148 == V_5 -> V_75 )
V_5 -> V_88 -= F_56 ( V_5 ) ;
} else {
F_3 ( V_8 , L_38 , V_98 ) ;
}
V_163 = V_5 -> V_88 - V_163 ;
F_69 ( & V_5 -> V_57 ) ;
return V_163 ;
}
