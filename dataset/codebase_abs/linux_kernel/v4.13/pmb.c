static T_1 unsigned long F_1 ( unsigned int V_1 )
{
return ( V_1 & V_2 ) << V_3 ;
}
static T_1 unsigned long F_2 ( unsigned int V_1 )
{
return F_1 ( V_1 ) | V_4 ;
}
static T_1 unsigned long F_3 ( unsigned int V_1 )
{
return F_1 ( V_1 ) | V_5 ;
}
static T_1 unsigned int F_4 ( unsigned long V_6 )
{
return V_6 >= F_5 ( V_7 ) && V_6 < F_5 ( V_8 ) ;
}
static T_1 unsigned long F_6 ( void )
{
unsigned long V_9 = 0 ;
#if F_7 ( V_10 )
V_9 |= V_11 | V_12 ;
#elif F_7 ( V_13 )
V_9 |= V_14 | V_11 | V_12 ;
#elif F_7 ( V_15 )
V_9 |= V_14 ;
#endif
return V_9 ;
}
static inline unsigned long F_8 ( T_2 V_16 )
{
unsigned long V_17 = 0 ;
T_3 V_9 = F_9 ( V_16 ) ;
if ( V_9 & V_18 )
V_17 |= V_14 ;
if ( V_9 & V_19 )
V_17 |= V_11 | V_12 ;
return V_17 ;
}
static inline bool F_10 ( struct V_20 * V_21 , struct V_20 * V_22 )
{
return ( V_22 -> V_23 == ( V_21 -> V_23 + V_21 -> V_24 ) ) &&
( V_22 -> V_6 == ( V_21 -> V_6 + V_21 -> V_24 ) ) &&
( V_22 -> V_9 == V_21 -> V_9 ) ;
}
static bool F_11 ( unsigned long V_25 , T_4 V_26 ,
unsigned long V_24 )
{
int V_27 ;
F_12 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
struct V_20 * V_30 , * V_31 ;
unsigned long V_32 ;
if ( ! F_14 ( V_27 , V_33 ) )
continue;
V_30 = & V_29 [ V_27 ] ;
if ( ( V_25 < V_30 -> V_23 ) || ( V_25 >= ( V_30 -> V_23 + V_30 -> V_24 ) ) )
continue;
if ( ( V_26 < V_30 -> V_6 ) || ( V_26 >= ( V_30 -> V_6 + V_30 -> V_24 ) ) )
continue;
if ( V_24 <= V_30 -> V_24 ) {
F_15 ( & V_28 ) ;
return true ;
}
V_32 = V_30 -> V_24 ;
for ( V_31 = V_30 -> V_34 ; V_31 ; V_31 = V_31 -> V_34 )
V_32 += V_31 -> V_24 ;
if ( V_24 <= V_32 ) {
F_15 ( & V_28 ) ;
return true ;
}
}
F_15 ( & V_28 ) ;
return false ;
}
static bool F_16 ( unsigned long V_24 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_13 ( V_35 ) ; V_27 ++ )
if ( V_35 [ V_27 ] . V_24 == V_24 )
return true ;
return false ;
}
static inline bool F_17 ( unsigned long V_36 , unsigned long V_24 )
{
return ( V_36 >= V_37 && ( V_36 + V_24 - 1 ) < V_38 ) ;
}
static inline bool F_18 ( T_2 V_16 )
{
return ( F_9 ( V_16 ) & V_39 ) == 0 ;
}
static int F_19 ( unsigned long V_24 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_13 ( V_35 ) ; V_27 ++ )
if ( V_35 [ V_27 ] . V_24 == V_24 )
return V_35 [ V_27 ] . V_40 ;
return 0 ;
}
static int F_20 ( void )
{
int V_41 ;
V_41 = F_21 ( V_33 , V_42 ) ;
if ( V_41 >= 0 && V_41 < V_42 )
F_22 ( V_41 , V_33 ) ;
else
V_41 = - V_43 ;
return V_41 ;
}
static struct V_20 * F_23 ( unsigned long V_23 , unsigned long V_6 ,
unsigned long V_9 , int V_1 )
{
struct V_20 * V_30 ;
unsigned long V_44 ;
void * V_45 = NULL ;
int V_41 ;
F_24 ( & V_28 , V_44 ) ;
if ( V_1 == V_46 ) {
V_41 = F_20 () ;
if ( F_25 ( V_41 < 0 ) ) {
V_45 = F_26 ( V_41 ) ;
goto V_47;
}
} else {
if ( F_27 ( V_1 , V_33 ) ) {
V_45 = F_26 ( - V_43 ) ;
goto V_47;
}
V_41 = V_1 ;
}
F_28 ( & V_28 , V_44 ) ;
V_30 = & V_29 [ V_41 ] ;
memset ( V_30 , 0 , sizeof( struct V_20 ) ) ;
F_29 ( & V_30 -> V_48 ) ;
V_30 -> V_23 = V_23 ;
V_30 -> V_6 = V_6 ;
V_30 -> V_9 = V_9 ;
V_30 -> V_1 = V_41 ;
return V_30 ;
V_47:
F_28 ( & V_28 , V_44 ) ;
return V_45 ;
}
static void F_30 ( struct V_20 * V_30 )
{
F_31 ( V_30 -> V_1 , V_33 ) ;
V_30 -> V_1 = V_46 ;
V_30 -> V_34 = NULL ;
}
static void F_32 ( struct V_20 * V_30 )
{
unsigned long V_36 , V_49 ;
V_36 = F_2 ( V_30 -> V_1 ) ;
V_49 = F_3 ( V_30 -> V_1 ) ;
F_33 () ;
F_34 ( V_30 -> V_23 | V_50 , V_36 ) ;
F_34 ( V_30 -> V_6 | V_30 -> V_9 | V_50 , V_49 ) ;
F_35 () ;
}
static void F_36 ( struct V_20 * V_30 )
{
unsigned long V_36 , V_49 ;
unsigned long V_51 , V_52 ;
V_36 = F_2 ( V_30 -> V_1 ) ;
V_49 = F_3 ( V_30 -> V_1 ) ;
V_51 = F_37 ( V_36 ) ;
V_52 = F_37 ( V_49 ) ;
F_38 ( V_51 & ~ V_50 , V_36 ) ;
F_38 ( V_52 & ~ V_50 , V_49 ) ;
}
static void F_39 ( struct V_20 * V_30 )
{
unsigned long V_9 ;
F_40 ( & V_30 -> V_48 , V_9 ) ;
F_32 ( V_30 ) ;
F_41 ( & V_30 -> V_48 , V_9 ) ;
}
int F_42 ( unsigned long V_25 , T_4 V_26 ,
unsigned long V_24 , T_2 V_16 )
{
struct V_20 * V_53 , * V_30 ;
unsigned long V_54 , V_55 ;
unsigned long V_9 , V_17 ;
int V_27 , V_56 ;
if ( V_24 < V_57 )
return - V_58 ;
if ( ! F_17 ( V_25 , V_24 ) )
return - V_59 ;
if ( F_11 ( V_25 , V_26 , V_24 ) )
return 0 ;
V_54 = V_25 ;
V_55 = V_24 ;
F_43 ( V_25 , V_25 + V_24 ) ;
V_17 = F_8 ( V_16 ) ;
V_53 = NULL ;
do {
for ( V_27 = V_56 = 0 ; V_27 < F_13 ( V_35 ) ; V_27 ++ ) {
if ( V_24 < V_35 [ V_27 ] . V_24 )
continue;
V_30 = F_23 ( V_25 , V_26 , V_17 |
V_35 [ V_27 ] . V_40 , V_46 ) ;
if ( F_44 ( V_30 ) ) {
F_45 ( V_53 , V_56 ) ;
return F_46 ( V_30 ) ;
}
F_40 ( & V_30 -> V_48 , V_9 ) ;
V_30 -> V_24 = V_35 [ V_27 ] . V_24 ;
F_32 ( V_30 ) ;
V_26 += V_30 -> V_24 ;
V_25 += V_30 -> V_24 ;
V_24 -= V_30 -> V_24 ;
if ( F_47 ( V_53 ) ) {
F_48 ( & V_53 -> V_48 ,
V_60 ) ;
V_53 -> V_34 = V_30 ;
F_49 ( & V_53 -> V_48 ) ;
}
V_53 = V_30 ;
V_27 -- ;
V_56 ++ ;
F_41 ( & V_30 -> V_48 , V_9 ) ;
}
} while ( V_24 >= V_57 );
F_50 ( V_54 , V_54 + V_55 ) ;
return 0 ;
}
void T_5 * F_51 ( T_4 V_26 , unsigned long V_24 ,
T_2 V_16 , void * V_61 )
{
unsigned long V_25 ;
T_4 V_62 , V_63 ;
T_4 V_64 ;
unsigned long V_65 ;
struct V_66 * V_67 ;
int V_27 , V_45 ;
if ( ! V_68 )
return NULL ;
if ( V_24 < V_57 )
return F_26 ( - V_58 ) ;
if ( ! F_18 ( V_16 ) )
return F_26 ( - V_58 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_35 ) ; V_27 ++ )
if ( V_24 >= V_35 [ V_27 ] . V_24 )
break;
V_63 = V_26 + V_24 ;
V_64 = ~ ( V_35 [ V_27 ] . V_24 - 1 ) ;
V_62 = V_26 & ~ V_64 ;
V_26 &= V_64 ;
V_65 = F_52 ( V_63 , V_35 [ V_27 ] . V_24 ) - V_26 ;
V_67 = F_53 ( V_65 , V_69 , 0xb0000000 ,
V_38 , V_61 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_70 = V_26 ;
V_25 = ( unsigned long ) V_67 -> V_36 ;
V_45 = F_42 ( V_25 , V_26 , V_24 , V_16 ) ;
if ( F_25 ( V_45 != 0 ) )
return F_26 ( V_45 ) ;
return ( void T_5 * ) ( V_62 + ( char * ) V_25 ) ;
}
int F_54 ( void T_5 * V_36 )
{
struct V_20 * V_30 = NULL ;
unsigned long V_25 = ( unsigned long V_71 ) V_36 ;
int V_27 , V_72 = 0 ;
F_12 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
if ( F_14 ( V_27 , V_33 ) ) {
V_30 = & V_29 [ V_27 ] ;
if ( V_30 -> V_23 == V_25 ) {
V_72 = 1 ;
break;
}
}
}
F_15 ( & V_28 ) ;
if ( V_72 ) {
F_45 ( V_30 , V_42 ) ;
return 0 ;
}
return - V_58 ;
}
static void F_55 ( struct V_20 * V_30 , int V_73 )
{
do {
struct V_20 * V_74 = V_30 ;
F_36 ( V_30 ) ;
F_56 ( V_30 -> V_23 , V_30 -> V_23 + V_30 -> V_24 ) ;
V_30 = V_74 -> V_34 ;
F_30 ( V_74 ) ;
} while ( V_30 && -- V_73 );
}
static void F_45 ( struct V_20 * V_30 , int V_73 )
{
unsigned long V_9 ;
if ( F_25 ( ! V_30 ) )
return;
F_24 ( & V_28 , V_9 ) ;
F_55 ( V_30 , V_73 ) ;
F_28 ( & V_28 , V_9 ) ;
}
static void T_6 F_57 ( void )
{
int V_27 ;
F_58 ( L_1 ) ;
F_12 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
struct V_20 * V_30 ;
if ( ! F_14 ( V_27 , V_33 ) )
continue;
V_30 = & V_29 [ V_27 ] ;
F_58 ( L_2 ,
V_30 -> V_23 >> V_75 , V_30 -> V_6 >> V_75 ,
V_30 -> V_24 >> 20 , ( V_30 -> V_9 & V_14 ) ? L_3 : L_4 ) ;
}
F_15 ( & V_28 ) ;
}
static void T_6 F_59 ( void )
{
struct V_20 * V_53 = NULL ;
int V_27 , V_76 ;
for ( V_27 = 0 ; V_27 < V_42 ; V_27 ++ ) {
unsigned long V_36 , V_49 ;
unsigned long V_51 , V_52 ;
unsigned long V_6 , V_23 , V_9 ;
unsigned long V_44 ;
unsigned int V_24 ;
struct V_20 * V_30 ;
V_36 = F_2 ( V_27 ) ;
V_49 = F_3 ( V_27 ) ;
V_51 = F_37 ( V_36 ) ;
V_52 = F_37 ( V_49 ) ;
if ( ! ( V_52 & V_50 ) || ! ( V_51 & V_50 ) )
continue;
V_6 = V_52 & V_77 ;
V_23 = V_51 & V_77 ;
if ( ! F_4 ( V_6 ) ) {
F_38 ( V_51 & ~ V_50 , V_36 ) ;
F_38 ( V_52 & ~ V_50 , V_49 ) ;
continue;
}
if ( V_52 & V_14 ) {
V_52 &= ~ V_78 ;
V_52 |= F_6 () ;
F_38 ( V_52 , V_49 ) ;
}
V_24 = V_52 & V_79 ;
V_9 = V_24 | ( V_52 & V_78 ) ;
V_30 = F_23 ( V_23 , V_6 , V_9 , V_27 ) ;
if ( F_44 ( V_30 ) ) {
F_60 ( 1 ) ;
continue;
}
F_40 ( & V_30 -> V_48 , V_44 ) ;
for ( V_76 = 0 ; V_76 < F_13 ( V_35 ) ; V_76 ++ )
if ( V_35 [ V_76 ] . V_40 == V_24 )
V_30 -> V_24 = V_35 [ V_76 ] . V_24 ;
if ( V_53 ) {
F_48 ( & V_53 -> V_48 , V_60 ) ;
if ( F_10 ( V_53 , V_30 ) )
V_53 -> V_34 = V_30 ;
F_49 ( & V_53 -> V_48 ) ;
}
V_53 = V_30 ;
F_41 ( & V_30 -> V_48 , V_44 ) ;
}
}
static void T_6 F_61 ( struct V_20 * V_80 )
{
unsigned long V_32 , V_81 ;
struct V_20 * V_82 ;
int V_27 = 1 , V_73 = 0 ;
V_32 = V_81 = V_80 -> V_24 ;
V_82 = V_80 -> V_34 ;
while ( V_82 ) {
V_32 += V_82 -> V_24 ;
if ( F_16 ( V_32 ) ) {
V_81 = V_32 ;
V_73 = V_27 ;
}
if ( ! V_82 -> V_34 )
break;
V_82 = V_82 -> V_34 ;
V_27 ++ ;
}
if ( ! V_73 || ! F_16 ( V_81 ) )
return;
V_80 -> V_9 &= ~ V_79 ;
V_80 -> V_9 |= F_19 ( V_81 ) ;
V_80 -> V_24 = V_81 ;
F_55 ( V_80 -> V_34 , V_73 ) ;
F_32 ( V_80 ) ;
}
static void T_6 F_62 ( void )
{
unsigned long V_9 ;
int V_27 ;
F_24 ( & V_28 , V_9 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
struct V_20 * V_30 ;
if ( ! F_14 ( V_27 , V_33 ) )
continue;
V_30 = & V_29 [ V_27 ] ;
if ( ! V_30 -> V_34 )
continue;
if ( V_30 -> V_24 == V_83 )
continue;
F_61 ( V_30 ) ;
}
F_28 ( & V_28 , V_9 ) ;
}
static void T_6 F_63 ( void )
{
int V_27 ;
if ( V_84 == V_57 )
return;
F_12 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
struct V_20 * V_30 ;
unsigned long V_9 ;
if ( ! F_14 ( V_27 , V_33 ) )
continue;
V_30 = & V_29 [ V_27 ] ;
if ( V_30 -> V_23 != V_85 )
continue;
F_40 ( & V_30 -> V_48 , V_9 ) ;
V_30 -> V_24 = V_57 ;
V_30 -> V_9 &= ~ V_79 ;
V_30 -> V_9 |= F_19 ( V_30 -> V_24 ) ;
F_64 ( V_30 -> V_24 ) ;
F_32 ( V_30 ) ;
F_41 ( & V_30 -> V_48 , V_9 ) ;
}
F_15 ( & V_28 ) ;
}
static int T_6 F_65 ( char * V_86 )
{
if ( ! V_86 )
return 0 ;
if ( strstr ( V_86 , L_5 ) )
V_68 = 1 ;
return 0 ;
}
void T_6 F_66 ( void )
{
F_59 () ;
F_62 () ;
#ifdef F_67
F_63 () ;
#endif
F_57 () ;
F_38 ( 0 , V_87 ) ;
F_68 () ;
F_69 () ;
}
bool F_70 ( void )
{
return ( F_37 ( V_88 ) & V_89 ) == 0 ;
}
static int F_71 ( struct V_90 * V_91 , void * V_31 )
{
int V_27 ;
F_72 ( V_91 , L_6
L_7 ) ;
F_72 ( V_91 , L_8 ) ;
for ( V_27 = 0 ; V_27 < V_42 ; V_27 ++ ) {
unsigned long V_36 , V_49 ;
unsigned int V_24 ;
char * V_92 = NULL ;
V_36 = F_37 ( F_2 ( V_27 ) ) ;
V_49 = F_37 ( F_3 ( V_27 ) ) ;
V_24 = V_49 & V_79 ;
V_92 = ( V_24 == V_93 ) ? L_9 :
( V_24 == V_94 ) ? L_10 :
( V_24 == V_95 ) ? L_11 :
L_12 ;
F_72 ( V_91 , L_13 ,
V_27 , ( ( V_36 & V_50 ) && ( V_49 & V_50 ) ) ? 'V' : ' ' ,
( V_36 >> 24 ) & 0xff , ( V_49 >> 24 ) & 0xff ,
V_92 , ( V_49 & V_14 ) ? 'C' : ' ' ,
( V_49 & V_11 ) ? L_14 : L_15 ,
( V_49 & V_12 ) ? L_16 : L_17 ) ;
}
return 0 ;
}
static int F_73 ( struct V_96 * V_96 , struct V_91 * V_91 )
{
return F_74 ( V_91 , F_71 , NULL ) ;
}
static int T_6 F_75 ( void )
{
struct V_97 * V_97 ;
V_97 = F_76 ( L_18 , V_98 | V_99 ,
V_100 , NULL , & V_101 ) ;
if ( ! V_97 )
return - V_102 ;
return 0 ;
}
static void F_77 ( void )
{
struct V_20 * V_30 ;
int V_27 ;
F_12 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_29 ) ; V_27 ++ ) {
if ( F_14 ( V_27 , V_33 ) ) {
V_30 = & V_29 [ V_27 ] ;
F_39 ( V_30 ) ;
}
}
F_15 ( & V_28 ) ;
}
static int T_6 F_78 ( void )
{
F_79 ( & V_103 ) ;
return 0 ;
}
