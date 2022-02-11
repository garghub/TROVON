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
F_42 ( V_40 L_9
L_10 ,
V_39 , V_38 ) ;
continue;
}
F_43 ( V_37 [ V_39 ] ) ;
V_37 [ V_39 ] = NULL ;
}
}
static void F_44 ( void * V_41 , int V_42 )
{
if ( V_42 )
F_45 ( V_41 ) ;
else
F_46 ( V_41 ) ;
}
static struct V_19 * * F_47 ( struct V_4 * V_5 , unsigned long V_43 )
{
struct V_19 * * V_44 = V_5 -> V_24 ;
struct V_19 * * V_45 , * V_19 ;
unsigned int V_39 , V_46 , V_47 = 0 ;
unsigned long V_48 = V_5 -> V_29 ;
F_12 ( V_48 == 0 && V_44 != NULL ) ;
F_12 ( V_48 != 0 && V_44 == NULL ) ;
if ( V_48 == V_43 )
return V_44 ;
V_46 = sizeof( struct V_19 * ) * V_43 ;
V_45 = F_48 ( V_46 , V_49 | V_50 ) ;
if ( ! V_45 ) {
V_45 = F_49 ( V_46 ,
V_49 | V_51 | V_52 ,
V_53 ) ;
if ( ! V_45 )
return NULL ;
V_47 = 1 ;
}
if ( V_43 >= V_48 ) {
for ( V_39 = 0 ; V_39 < V_48 ; V_39 ++ )
V_45 [ V_39 ] = V_44 [ V_39 ] ;
for (; V_39 < V_43 ; V_39 ++ ) {
V_19 = F_50 ( V_49 | V_51 ) ;
if ( ! V_19 ) {
F_41 ( V_45 + V_48 , V_39 - V_48 ) ;
F_44 ( V_45 , V_47 ) ;
return NULL ;
}
F_11 ( V_19 , V_39 ) ;
V_45 [ V_39 ] = V_19 ;
}
} else {
for ( V_39 = 0 ; V_39 < V_43 ; V_39 ++ )
V_45 [ V_39 ] = V_44 [ V_39 ] ;
}
if ( V_47 )
V_5 -> V_18 |= V_54 ;
else
V_5 -> V_18 &= ~ V_54 ;
return V_45 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_52 ( V_5 != NULL ) ;
V_5 = F_48 ( sizeof( struct V_4 ) , V_55 ) ;
if ( ! V_5 )
return - V_56 ;
F_53 ( & V_5 -> V_57 ) ;
F_54 ( & V_5 -> V_16 ) ;
F_55 ( & V_5 -> V_25 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_58 ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return;
F_41 ( V_2 -> V_6 -> V_24 , V_2 -> V_6 -> V_29 ) ;
F_44 ( V_2 -> V_6 -> V_24 , ( V_54 & V_2 -> V_6 -> V_18 ) ) ;
F_46 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_36 , * V_60 ;
int V_61 ;
int V_62 = 0 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_60 ( V_59 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_60 = V_36 + ( V_61 / V_66 ) ;
if ( V_59 ) {
V_62 = F_61 ( * V_60 & ~ V_59 ) ;
* V_60 &= V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_36 ) & 1 ) == 1 ) {
V_62 += F_61 ( * V_60 ) ;
* V_60 = 0 ;
}
F_40 ( V_36 ) ;
return V_62 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_36 , * V_60 ;
int V_61 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_60 ( V_59 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_60 = V_36 + ( V_61 / V_66 ) ;
if ( V_59 ) {
* V_60 |= ~ V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_36 ) & 1 ) == 1 ) {
* V_60 = ~ 0UL ;
}
F_40 ( V_36 ) ;
}
static unsigned long F_63 ( struct V_4 * V_5 )
{
unsigned long * V_36 ;
unsigned long V_67 = 0 ;
unsigned long V_59 = ( 1UL << ( V_5 -> V_63 & V_65 ) ) - 1 ;
int V_20 , V_39 , V_68 ;
for ( V_20 = 0 ; V_20 < V_5 -> V_29 - 1 ; V_20 ++ ) {
V_36 = F_35 ( V_5 , V_20 ) ;
for ( V_39 = 0 ; V_39 < V_69 ; V_39 ++ )
V_67 += F_61 ( V_36 [ V_39 ] ) ;
F_38 ( V_36 ) ;
F_64 () ;
}
V_68 = ( ( V_5 -> V_63 - 1 ) & V_64 ) >> V_34 ;
V_36 = F_35 ( V_5 , V_20 ) ;
for ( V_39 = 0 ; V_39 < V_68 ; V_39 ++ )
V_67 += F_61 ( V_36 [ V_39 ] ) ;
V_36 [ V_68 ] &= F_60 ( V_59 ) ;
V_67 += F_61 ( V_36 [ V_68 ] ) ;
if ( V_66 == 32 && ( V_68 & 1 ) == 0 )
V_36 [ V_68 + 1 ] = 0 ;
F_38 ( V_36 ) ;
return V_67 ;
}
static void F_65 ( struct V_4 * V_5 , T_3 V_70 , int V_71 , T_3 V_72 )
{
unsigned long * V_36 , * V_60 ;
unsigned int V_20 ;
T_3 V_73 , V_74 ;
V_74 = V_70 + V_72 ;
if ( V_74 > V_5 -> V_75 ) {
F_42 ( V_40 L_11 ) ;
return;
}
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_20 = F_33 ( V_5 , V_70 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_60 = V_36 + F_68 ( V_70 ) ;
if ( V_60 + V_73 > V_36 + V_69 ) {
F_42 ( V_40 L_12 ,
V_36 , V_60 , ( int ) V_73 ) ;
} else
memset ( V_60 , V_71 , V_73 * sizeof( long ) ) ;
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
V_70 += V_73 ;
}
}
static T_1 F_69 ( struct V_76 * V_77 )
{
T_1 V_78 ;
if ( V_77 -> V_79 . V_80 == 8 )
V_78 = V_77 -> V_79 . V_81 - V_77 -> V_79 . V_82 ;
else
V_78 = V_77 -> V_79 . V_80 - V_77 -> V_79 . V_82 ;
return V_78 << ( 9 + 3 ) ;
}
int F_70 ( struct V_1 * V_2 , T_2 V_83 , int V_84 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_67 , V_85 , V_86 , V_87 ;
unsigned long V_43 , V_48 , V_88 ;
struct V_19 * * V_89 , * * V_90 = NULL ;
int V_91 = 0 , V_92 ;
int V_93 ;
if ( ! F_57 ( V_5 ) )
return - V_56 ;
F_5 ( V_2 , L_13 , V_17 ) ;
F_71 ( V_2 , L_14 ,
( unsigned long long ) V_83 ) ;
if ( V_83 == V_5 -> V_58 )
goto V_94;
V_93 = ( V_54 & V_5 -> V_18 ) ;
if ( V_83 == 0 ) {
F_72 ( & V_5 -> V_57 ) ;
V_90 = V_5 -> V_24 ;
V_88 = V_5 -> V_29 ;
V_86 = V_5 -> V_75 ;
V_5 -> V_24 = NULL ;
V_5 -> V_29 =
V_5 -> V_95 =
V_5 -> V_63 =
V_5 -> V_75 =
V_5 -> V_58 = 0 ;
F_73 ( & V_5 -> V_57 ) ;
F_41 ( V_90 , V_88 ) ;
F_44 ( V_90 , V_93 ) ;
goto V_94;
}
V_67 = F_74 ( F_67 ( V_83 , V_96 ) ) ;
V_85 = F_67 ( V_67 , 64 ) >> V_34 ;
if ( F_75 ( V_2 ) ) {
T_1 V_97 = F_69 ( V_2 -> V_77 ) ;
F_76 ( V_2 ) ;
if ( V_67 > V_97 ) {
F_71 ( V_2 , L_15 , V_67 ) ;
F_71 ( V_2 , L_16 , V_97 ) ;
V_91 = - V_98 ;
goto V_94;
}
}
V_43 = F_67 ( V_85 * sizeof( long ) , V_99 ) >> V_33 ;
V_48 = V_5 -> V_29 ;
if ( V_43 == V_48 ) {
F_77 ( V_2 , V_5 -> V_24 != NULL ) ;
V_89 = V_5 -> V_24 ;
} else {
if ( F_78 ( V_2 , V_100 ) )
V_89 = NULL ;
else
V_89 = F_47 ( V_5 , V_43 ) ;
}
if ( ! V_89 ) {
V_91 = - V_56 ;
goto V_94;
}
F_72 ( & V_5 -> V_57 ) ;
V_90 = V_5 -> V_24 ;
V_86 = V_5 -> V_75 ;
V_87 = V_5 -> V_63 ;
V_92 = V_67 > V_87 ;
if ( V_90 && V_92 && V_84 )
F_62 ( V_5 ) ;
V_5 -> V_24 = V_89 ;
V_5 -> V_29 = V_43 ;
V_5 -> V_63 = V_67 ;
V_5 -> V_75 = V_85 ;
V_5 -> V_58 = V_83 ;
if ( V_92 ) {
if ( V_84 ) {
F_65 ( V_5 , V_86 , 0xff , V_85 - V_86 ) ;
V_5 -> V_95 += V_67 - V_87 ;
} else
F_65 ( V_5 , V_86 , 0x00 , V_85 - V_86 ) ;
}
if ( V_43 < V_48 ) {
F_41 ( V_90 + V_43 , V_48 - V_43 ) ;
}
( void ) F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_57 ) ;
if ( V_90 != V_89 )
F_44 ( V_90 , V_93 ) ;
if ( ! V_92 )
V_5 -> V_95 = F_63 ( V_5 ) ;
F_71 ( V_2 , L_17 , V_67 , V_85 , V_43 ) ;
V_94:
F_9 ( V_2 ) ;
return V_91 ;
}
unsigned long F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_101 ;
unsigned long V_14 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_57 , V_14 ) ;
V_101 = V_5 -> V_95 ;
F_81 ( & V_5 -> V_57 , V_14 ) ;
return V_101 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
unsigned long V_101 ;
if ( ! F_83 ( V_2 , V_102 ) )
return 0 ;
V_101 = F_79 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_101 ;
}
T_3 F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
return V_5 -> V_75 ;
}
unsigned long F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
return V_5 -> V_63 ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_38 ,
unsigned long * V_103 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_60 ;
unsigned long V_104 , V_67 ;
unsigned int V_20 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_38 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
if ( V_38 == 0 )
return;
F_52 ( V_70 >= V_5 -> V_75 ) ;
F_52 ( V_74 > V_5 -> V_75 ) ;
F_72 ( & V_5 -> V_57 ) ;
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_20 = F_33 ( V_5 , V_70 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_60 = V_36 + F_68 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- ) {
V_67 = F_61 ( * V_60 ) ;
V_104 = * V_60 | * V_103 ++ ;
* V_60 ++ = V_104 ;
V_5 -> V_95 += F_61 ( V_104 ) - V_67 ;
}
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
}
if ( V_74 == V_5 -> V_75 )
V_5 -> V_95 -= F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_57 ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_38 ,
unsigned long * V_103 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_60 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_38 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_57 ) ;
if ( ( V_70 >= V_5 -> V_75 ) ||
( V_74 > V_5 -> V_75 ) ||
( V_38 <= 0 ) )
F_3 ( V_2 , L_18 ,
( unsigned long ) V_70 ,
( unsigned long ) V_38 ,
( unsigned long ) V_5 -> V_75 ) ;
else {
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_70 ) ) ;
V_60 = V_36 + F_68 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- )
* V_103 ++ = * V_60 ++ ;
F_40 ( V_36 ) ;
}
}
F_73 ( & V_5 -> V_57 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_57 ) ;
F_65 ( V_5 , 0 , 0xff , V_5 -> V_75 ) ;
( void ) F_59 ( V_5 ) ;
V_5 -> V_95 = V_5 -> V_63 ;
F_73 ( & V_5 -> V_57 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_57 ) ;
F_65 ( V_5 , 0 , 0 , V_5 -> V_75 ) ;
V_5 -> V_95 = 0 ;
F_73 ( & V_5 -> V_57 ) ;
}
static void F_90 ( struct V_105 * V_105 )
{
struct V_106 * V_107 = F_91 ( V_105 , struct V_106 , V_105 ) ;
F_76 ( V_107 -> V_2 ) ;
F_46 ( V_107 ) ;
}
static void F_92 ( struct V_108 * V_108 , int error )
{
struct V_106 * V_107 = V_108 -> V_109 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 = F_14 ( V_108 -> V_110 [ 0 ] . V_111 ) ;
int V_112 = F_93 ( V_108 , V_113 ) ;
if ( ! error && ! V_112 )
error = - V_114 ;
if ( ( V_107 -> V_14 & V_115 ) == 0 &&
! F_27 ( V_5 -> V_24 [ V_20 ] ) )
F_7 ( V_2 , L_19 , V_20 ) ;
if ( error ) {
V_107 -> error = error ;
F_28 ( V_5 -> V_24 [ V_20 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_2 , L_20 ,
error , V_20 ) ;
} else {
F_29 ( V_5 -> V_24 [ V_20 ] ) ;
F_94 ( V_2 , L_21 , V_20 ) ;
}
F_19 ( V_2 , V_20 ) ;
if ( V_107 -> V_14 & V_115 )
F_95 ( V_108 -> V_110 [ 0 ] . V_111 , V_116 ) ;
F_96 ( V_108 ) ;
if ( F_97 ( & V_107 -> V_117 ) ) {
V_107 -> V_118 = 1 ;
F_21 ( & V_2 -> V_119 ) ;
F_98 ( & V_107 -> V_105 , & F_90 ) ;
}
}
static void F_99 ( struct V_106 * V_107 , int V_22 , int V_120 ) __must_hold( T_4 )
{
struct V_108 * V_108 = F_100 ( V_49 ) ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_19 ;
unsigned int V_72 ;
T_2 V_121 =
V_2 -> V_77 -> V_79 . V_122 + V_2 -> V_77 -> V_79 . V_82 ;
V_121 += ( ( T_2 ) V_22 ) << ( V_33 - 9 ) ;
V_72 = F_66 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(device->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_22 ) ;
F_22 ( V_5 -> V_24 [ V_22 ] ) ;
if ( V_107 -> V_14 & V_115 ) {
V_19 = F_101 ( V_116 , V_51 | V_123 ) ;
F_102 ( V_19 , V_5 -> V_24 [ V_22 ] ) ;
F_11 ( V_19 , V_22 ) ;
} else
V_19 = V_5 -> V_24 [ V_22 ] ;
V_108 -> V_124 = V_2 -> V_77 -> V_125 ;
V_108 -> V_126 . V_127 = V_121 ;
F_103 ( V_108 , V_19 , V_72 , 0 ) ;
V_108 -> V_109 = V_107 ;
V_108 -> V_128 = F_92 ;
if ( F_78 ( V_2 , ( V_120 & V_129 ) ? V_130 : V_131 ) ) {
V_108 -> V_132 |= V_120 ;
F_104 ( V_108 , - V_114 ) ;
} else {
F_105 ( V_120 , V_108 ) ;
F_106 ( V_72 >> 9 , & V_2 -> V_133 ) ;
}
}
static int F_107 ( struct V_1 * V_2 , int V_120 , unsigned V_14 , unsigned V_134 ) __must_hold( T_4 )
{
struct V_106 * V_107 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_135 , V_39 , V_136 = 0 ;
unsigned long V_137 ;
char V_138 [ 10 ] ;
int V_91 = 0 ;
V_107 = F_108 ( sizeof( struct V_106 ) , V_49 ) ;
if ( ! V_107 )
return - V_56 ;
* V_107 = (struct V_106 ) {
. V_2 = V_2 ,
. V_117 = F_109 ( 1 ) ,
. V_118 = 0 ,
. V_14 = V_14 ,
. error = 0 ,
. V_105 = { F_109 ( 2 ) } ,
} ;
if ( ! F_83 ( V_2 , V_139 ) ) {
F_3 ( V_2 , L_22 ) ;
F_46 ( V_107 ) ;
return - V_140 ;
}
if ( ! V_107 -> V_14 )
F_52 ( ! ( V_17 & V_5 -> V_18 ) ) ;
V_135 = V_5 -> V_29 ;
V_137 = V_141 ;
for ( V_39 = 0 ; V_39 < V_135 ; V_39 ++ ) {
if ( V_134 && V_39 == V_134 )
break;
if ( V_120 & V_129 ) {
if ( ( V_14 & V_142 ) &&
! F_110 ( V_30 ,
& F_15 ( V_5 -> V_24 [ V_39 ] ) ) )
continue;
if ( ! ( V_14 & V_143 ) &&
F_27 ( V_5 -> V_24 [ V_39 ] ) ) {
F_94 ( V_2 , L_23 , V_39 ) ;
continue;
}
if ( V_134 &&
! F_31 ( V_5 -> V_24 [ V_39 ] ) ) {
F_94 ( V_2 , L_24 , V_39 ) ;
continue;
}
}
F_111 ( & V_107 -> V_117 ) ;
F_99 ( V_107 , V_39 , V_120 ) ;
++ V_136 ;
F_64 () ;
}
if ( ! F_97 ( & V_107 -> V_117 ) )
F_112 ( V_2 , V_2 -> V_77 , & V_107 -> V_118 ) ;
else
F_98 ( & V_107 -> V_105 , & F_90 ) ;
if ( V_14 == 0 )
F_71 ( V_2 , L_25 ,
V_120 == V_129 ? L_26 : L_27 ,
V_136 , V_141 - V_137 ) ;
if ( V_107 -> error ) {
F_113 ( V_2 , L_28 ) ;
F_114 ( V_2 , 1 , V_144 ) ;
V_91 = - V_114 ;
}
if ( F_115 ( & V_107 -> V_117 ) )
V_91 = - V_114 ;
V_137 = V_141 ;
if ( V_120 == V_129 ) {
F_116 ( V_2 ) ;
} else {
V_5 -> V_95 = F_63 ( V_5 ) ;
F_71 ( V_2 , L_29 ,
V_141 - V_137 ) ;
}
V_137 = V_5 -> V_95 ;
if ( V_14 == 0 )
F_71 ( V_2 , L_30 ,
F_117 ( V_138 , V_137 << ( V_145 - 10 ) ) , V_137 ) ;
F_98 ( & V_107 -> V_105 , & F_90 ) ;
return V_91 ;
}
int F_118 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_146 , 0 , 0 ) ;
}
int F_119 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_129 , 0 , 0 ) ;
}
int F_120 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_129 , V_143 , 0 ) ;
}
int F_121 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_129 , V_115 , 0 ) ;
}
int F_122 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_129 , V_142 | V_115 , 0 ) ;
}
int F_123 ( struct V_1 * V_2 , unsigned int V_20 ) __must_hold( T_4 )
{
struct V_106 * V_107 ;
int V_91 ;
if ( F_27 ( V_2 -> V_6 -> V_24 [ V_20 ] ) ) {
F_94 ( V_2 , L_31 , V_20 ) ;
return 0 ;
}
V_107 = F_108 ( sizeof( struct V_106 ) , V_49 ) ;
if ( ! V_107 )
return - V_56 ;
* V_107 = (struct V_106 ) {
. V_2 = V_2 ,
. V_117 = F_109 ( 1 ) ,
. V_118 = 0 ,
. V_14 = V_115 ,
. error = 0 ,
. V_105 = { F_109 ( 2 ) } ,
} ;
if ( ! F_83 ( V_2 , V_139 ) ) {
F_3 ( V_2 , L_32 ) ;
F_46 ( V_107 ) ;
return - V_140 ;
}
F_99 ( V_107 , V_20 , V_147 ) ;
F_112 ( V_2 , V_2 -> V_77 , & V_107 -> V_118 ) ;
if ( V_107 -> error )
F_114 ( V_2 , 1 , V_144 ) ;
V_2 -> V_148 ++ ;
V_91 = F_115 ( & V_107 -> V_117 ) ? - V_114 : V_107 -> error ;
F_98 ( & V_107 -> V_105 , & F_90 ) ;
return V_91 ;
}
static unsigned long F_124 ( struct V_1 * V_2 , unsigned long V_149 ,
const int V_150 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
unsigned long V_151 ;
unsigned V_39 ;
if ( V_149 > V_5 -> V_63 ) {
F_3 ( V_2 , L_33 , V_149 , V_5 -> V_63 ) ;
V_149 = V_152 ;
} else {
while ( V_149 < V_5 -> V_63 ) {
V_151 = V_149 & ~ V_64 ;
V_36 = F_35 ( V_5 , F_34 ( V_5 , V_149 ) ) ;
if ( V_150 )
V_39 = F_125 ( V_36 ,
V_99 * 8 , V_149 & V_64 ) ;
else
V_39 = F_126 ( V_36 ,
V_99 * 8 , V_149 & V_64 ) ;
F_38 ( V_36 ) ;
if ( V_39 < V_99 * 8 ) {
V_149 = V_151 + V_39 ;
if ( V_149 >= V_5 -> V_63 )
break;
goto V_153;
}
V_149 = V_151 + V_99 * 8 ;
}
V_149 = V_152 ;
}
V_153:
return V_149 ;
}
static unsigned long F_127 ( struct V_1 * V_2 ,
unsigned long V_149 , const int V_150 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_39 = V_152 ;
if ( ! F_57 ( V_5 ) )
return V_39 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return V_39 ;
F_72 ( & V_5 -> V_57 ) ;
if ( V_154 & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_39 = F_124 ( V_2 , V_149 , V_150 ) ;
F_73 ( & V_5 -> V_57 ) ;
return V_39 ;
}
unsigned long F_129 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_127 ( V_2 , V_149 , 0 ) ;
}
unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_124 ( V_2 , V_149 , 0 ) ;
}
unsigned long F_131 ( struct V_1 * V_2 , unsigned long V_149 )
{
return F_124 ( V_2 , V_149 , 1 ) ;
}
static int F_132 ( struct V_1 * V_2 , const unsigned long V_101 ,
unsigned long V_155 , int V_156 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_157 = - 1U ;
int V_71 = 0 ;
int V_158 = 0 ;
if ( V_155 >= V_5 -> V_63 ) {
F_3 ( V_2 , L_34 ,
V_101 , V_155 , V_5 -> V_63 ) ;
V_155 = V_5 -> V_63 ? V_5 -> V_63 - 1 : 0 ;
}
for ( V_35 = V_101 ; V_35 <= V_155 ; V_35 ++ ) {
unsigned int V_22 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_157 ) {
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_71 < 0 )
F_30 ( V_5 -> V_24 [ V_157 ] ) ;
else if ( V_71 > 0 )
F_24 ( V_5 -> V_24 [ V_157 ] ) ;
V_158 += V_71 ;
V_71 = 0 ;
V_36 = F_35 ( V_5 , V_22 ) ;
V_157 = V_22 ;
}
if ( V_156 )
V_71 += ( 0 == F_133 ( V_35 & V_64 , V_36 ) ) ;
else
V_71 -= ( 0 != F_134 ( V_35 & V_64 , V_36 ) ) ;
}
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_71 < 0 )
F_30 ( V_5 -> V_24 [ V_157 ] ) ;
else if ( V_71 > 0 )
F_24 ( V_5 -> V_24 [ V_157 ] ) ;
V_158 += V_71 ;
V_5 -> V_95 += V_158 ;
return V_158 ;
}
static int F_135 ( struct V_1 * V_2 , const unsigned long V_101 ,
const unsigned long V_155 , int V_156 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_71 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_57 , V_14 ) ;
if ( ( V_156 ? V_159 : V_160 ) & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_71 = F_132 ( V_2 , V_101 , V_155 , V_156 ) ;
F_81 ( & V_5 -> V_57 , V_14 ) ;
return V_71 ;
}
int F_136 ( struct V_1 * V_2 , const unsigned long V_101 , const unsigned long V_155 )
{
return F_135 ( V_2 , V_101 , V_155 , 1 ) ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_101 , const unsigned long V_155 )
{
return - F_135 ( V_2 , V_101 , V_155 , 0 ) ;
}
static inline void F_138 ( struct V_4 * V_5 ,
int V_22 , int V_161 , int V_68 )
{
int V_39 ;
int V_67 ;
int V_162 = 0 ;
unsigned long * V_163 = F_36 ( V_5 -> V_24 [ V_22 ] ) ;
for ( V_39 = V_161 ; V_39 < V_68 ; V_39 ++ ) {
V_67 = F_61 ( V_163 [ V_39 ] ) ;
V_163 [ V_39 ] = ~ 0UL ;
V_162 += V_66 - V_67 ;
}
F_39 ( V_163 ) ;
if ( V_162 ) {
F_30 ( V_5 -> V_24 [ V_22 ] ) ;
V_5 -> V_95 += V_162 ;
}
}
void F_139 ( struct V_1 * V_2 , const unsigned long V_101 , const unsigned long V_155 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_164 = F_67 ( V_101 , V_66 ) ;
unsigned long V_165 = ( V_155 + 1 ) & ~ ( ( unsigned long ) V_66 - 1 ) ;
int V_166 ;
int V_167 ;
int V_22 ;
int V_161 ;
int V_68 ;
if ( V_155 - V_101 <= 3 * V_66 ) {
F_72 ( & V_5 -> V_57 ) ;
F_132 ( V_2 , V_101 , V_155 , 1 ) ;
F_73 ( & V_5 -> V_57 ) ;
return;
}
F_72 ( & V_5 -> V_57 ) ;
if ( V_164 )
F_132 ( V_2 , V_101 , V_164 - 1 , 1 ) ;
V_166 = V_164 >> ( 3 + V_33 ) ;
V_167 = V_165 >> ( 3 + V_33 ) ;
V_161 = F_68 ( V_164 >> V_34 ) ;
V_68 = V_69 ;
for ( V_22 = V_166 ; V_22 < V_167 ; V_22 ++ ) {
F_138 ( V_2 -> V_6 , V_22 , V_161 , V_68 ) ;
F_73 ( & V_5 -> V_57 ) ;
F_64 () ;
V_161 = 0 ;
F_72 ( & V_5 -> V_57 ) ;
}
V_68 = F_68 ( V_165 >> V_34 ) ;
if ( V_68 )
F_138 ( V_2 -> V_6 , V_167 , V_161 , V_68 ) ;
if ( V_165 <= V_155 )
F_132 ( V_2 , V_165 , V_155 , 1 ) ;
F_73 ( & V_5 -> V_57 ) ;
}
int F_140 ( struct V_1 * V_2 , const unsigned long V_35 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
int V_39 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_57 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_128 ( V_2 ) ;
if ( V_35 < V_5 -> V_63 ) {
V_36 = F_37 ( V_5 , F_34 ( V_5 , V_35 ) ) ;
V_39 = F_141 ( V_35 & V_64 , V_36 ) ? 1 : 0 ;
F_40 ( V_36 ) ;
} else if ( V_35 == V_5 -> V_63 ) {
V_39 = - 1 ;
} else {
F_3 ( V_2 , L_35 , V_35 , V_5 -> V_63 ) ;
V_39 = 0 ;
}
F_81 ( & V_5 -> V_57 , V_14 ) ;
return V_39 ;
}
int F_142 ( struct V_1 * V_2 , const unsigned long V_101 , const unsigned long V_155 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_22 = - 1U ;
int V_71 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 1 ;
F_80 ( & V_5 -> V_57 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_128 ( V_2 ) ;
for ( V_35 = V_101 ; V_35 <= V_155 ; V_35 ++ ) {
unsigned int V_20 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_20 ) {
V_22 = V_20 ;
if ( V_36 )
F_40 ( V_36 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
}
if ( F_57 ( V_35 < V_5 -> V_63 ) )
V_71 += ( 0 != F_141 ( V_35 - ( V_22 << ( V_33 + 3 ) ) , V_36 ) ) ;
else
F_3 ( V_2 , L_36 , V_35 , V_5 -> V_63 ) ;
}
if ( V_36 )
F_40 ( V_36 ) ;
F_81 ( & V_5 -> V_57 , V_14 ) ;
return V_71 ;
}
int F_143 ( struct V_1 * V_2 , unsigned long V_168 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_136 , V_101 , V_155 ;
unsigned long V_14 ;
unsigned long * V_36 , * V_60 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_57 , V_14 ) ;
if ( V_154 & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_101 = F_144 ( V_168 ) ;
V_155 = F_145 ( ( T_3 ) F_144 ( V_168 + 1 ) , V_5 -> V_75 ) ;
V_136 = 0 ;
if ( V_101 < V_5 -> V_75 ) {
int V_169 = V_155 - V_101 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_101 ) ) ;
V_60 = V_36 + F_68 ( V_101 ) ;
while ( V_169 -- )
V_136 += F_61 ( * V_60 ++ ) ;
F_40 ( V_36 ) ;
} else {
F_3 ( V_2 , L_37 , V_101 ) ;
}
F_81 ( & V_5 -> V_57 , V_14 ) ;
return V_136 ;
}
