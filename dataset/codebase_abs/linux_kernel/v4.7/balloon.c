static void F_1 ( struct V_1 * V_1 )
{
#ifdef F_2
F_3 ( V_1 ) ;
#endif
}
static void F_4 ( struct V_1 * V_1 )
{
if ( F_5 ( V_1 ) ) {
F_6 ( & V_1 -> V_2 , & V_3 ) ;
V_4 . V_5 ++ ;
} else {
F_7 ( & V_1 -> V_2 , & V_3 ) ;
V_4 . V_6 ++ ;
}
F_8 ( & V_7 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
F_4 ( V_1 ) ;
F_10 ( V_1 , - 1 ) ;
}
static struct V_1 * F_11 ( bool V_8 )
{
struct V_1 * V_1 ;
if ( F_12 ( & V_3 ) )
return NULL ;
V_1 = F_13 ( V_3 . V_9 , struct V_1 , V_2 ) ;
if ( V_8 && F_5 ( V_1 ) )
return NULL ;
F_14 ( & V_1 -> V_2 ) ;
if ( F_5 ( V_1 ) )
V_4 . V_5 -- ;
else
V_4 . V_6 -- ;
F_10 ( V_1 , 1 ) ;
return V_1 ;
}
static struct V_1 * F_15 ( struct V_1 * V_1 )
{
struct V_10 * V_9 = V_1 -> V_2 . V_9 ;
if ( V_9 == & V_3 )
return NULL ;
return F_13 ( V_9 , struct V_1 , V_2 ) ;
}
static enum V_11 F_16 ( enum V_11 V_12 )
{
if ( V_12 == V_13 )
return V_13 ;
if ( V_12 == V_14 )
return V_14 ;
if ( V_12 == V_15 ) {
V_4 . V_16 = 1 ;
V_4 . V_17 = 1 ;
return V_15 ;
}
++ V_4 . V_17 ;
if ( V_4 . V_18 != V_19 &&
V_4 . V_17 > V_4 . V_18 ) {
V_4 . V_16 = 1 ;
V_4 . V_17 = 1 ;
return V_14 ;
}
V_4 . V_16 <<= 1 ;
if ( V_4 . V_16 > V_4 . V_20 )
V_4 . V_16 = V_4 . V_20 ;
return V_21 ;
}
static void F_17 ( struct V_22 * V_22 )
{
if ( ! V_22 )
return;
F_18 ( V_22 ) ;
F_19 ( V_22 ) ;
}
static struct V_22 * F_20 ( T_1 V_23 )
{
struct V_22 * V_24 ;
int V_25 ;
V_24 = F_21 ( sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_27 = L_1 ;
V_24 -> V_28 = V_29 | V_30 ;
V_25 = F_22 ( & V_31 , V_24 ,
V_23 , 0 , - 1 ,
V_32 * V_33 , NULL , NULL ) ;
if ( V_25 < 0 ) {
F_23 ( L_2 ) ;
F_19 ( V_24 ) ;
return NULL ;
}
#ifdef F_24
{
unsigned long V_34 = 1UL << ( V_35 - V_36 ) ;
unsigned long V_37 = V_24 -> V_38 >> V_36 ;
if ( V_37 > V_34 ) {
F_23 ( L_3 ,
V_37 , V_34 ) ;
F_17 ( V_24 ) ;
return NULL ;
}
}
#endif
return V_24 ;
}
static enum V_11 F_25 ( void )
{
long V_39 ;
struct V_22 * V_22 ;
int V_40 , V_41 ;
unsigned long V_42 ;
V_39 = V_4 . V_43 + V_4 . V_44
- V_4 . V_45 ;
if ( V_39 <= 0 )
return V_13 ;
V_42 = F_26 ( V_39 , V_32 ) ;
V_22 = F_20 ( V_42 * V_33 ) ;
if ( ! V_22 )
goto V_46;
V_40 = F_27 ( V_22 -> V_38 ) ;
#ifdef F_28
F_29 ( V_47 != V_33 ) ;
if ( ! F_30 ( V_48 ) ) {
unsigned long V_37 , V_49 ;
V_37 = F_31 ( V_22 -> V_38 ) ;
for ( V_49 = 0 ; V_49 < V_42 ; V_49 ++ ) {
if ( ! F_32 ( V_37 + V_49 , V_50 ) ) {
F_33 ( L_4 ) ;
goto V_46;
}
}
}
#endif
F_34 ( & V_51 ) ;
V_41 = F_35 ( V_40 , V_22 , V_52 ) ;
F_36 ( & V_51 ) ;
if ( V_41 ) {
F_33 ( L_5 , V_41 ) ;
goto V_46;
}
V_4 . V_45 += V_42 ;
return V_13 ;
V_46:
F_17 ( V_22 ) ;
return V_14 ;
}
static void F_37 ( struct V_1 * V_1 )
{
F_38 ( V_1 ) ;
F_36 ( & V_51 ) ;
F_4 ( V_1 ) ;
F_34 ( & V_51 ) ;
}
static int F_39 ( struct V_53 * V_54 , unsigned long V_55 , void * V_56 )
{
if ( V_55 == V_57 )
F_40 ( & V_58 , 0 ) ;
return V_59 ;
}
static enum V_11 F_25 ( void )
{
V_4 . V_43 = V_4 . V_60 ;
return V_14 ;
}
static long F_41 ( void )
{
return V_4 . V_43 - V_4 . V_60 ;
}
static bool F_42 ( void )
{
return V_4 . V_6 || V_4 . V_5 ;
}
static enum V_11 F_43 ( unsigned long V_61 )
{
int V_41 ;
unsigned long V_49 ;
struct V_1 * V_1 ;
struct V_62 V_63 = {
. V_64 = 0 ,
. V_65 = V_66 ,
. V_67 = V_68
} ;
if ( V_61 > F_44 ( V_69 ) )
V_61 = F_44 ( V_69 ) ;
V_1 = F_45 ( & V_3 , struct V_1 , V_2 ) ;
for ( V_49 = 0 ; V_49 < V_61 ; V_49 ++ ) {
if ( ! V_1 ) {
V_61 = V_49 ;
break;
}
V_69 [ V_49 ] = F_46 ( V_1 ) ;
V_1 = F_15 ( V_1 ) ;
}
F_47 ( V_63 . V_70 , V_69 ) ;
V_63 . V_71 = V_61 ;
V_41 = F_48 ( V_72 , & V_63 ) ;
if ( V_41 <= 0 )
return V_21 ;
for ( V_49 = 0 ; V_49 < V_41 ; V_49 ++ ) {
V_1 = F_11 ( false ) ;
F_49 ( V_1 == NULL ) ;
#ifdef F_28
F_29 ( V_47 != V_33 ) ;
if ( ! F_30 ( V_48 ) ) {
unsigned long V_37 = F_50 ( V_1 ) ;
F_32 ( V_37 , V_69 [ V_49 ] ) ;
if ( ! F_5 ( V_1 ) ) {
int V_25 ;
V_25 = F_51 (
( unsigned long ) F_52 ( V_37 << V_36 ) ,
F_53 ( V_69 [ V_49 ] , V_73 ) ,
0 ) ;
F_49 ( V_25 ) ;
}
}
#endif
F_54 ( V_1 ) ;
}
V_4 . V_60 += V_41 ;
return V_15 ;
}
static enum V_11 F_55 ( unsigned long V_61 , T_2 V_74 )
{
enum V_11 V_12 = V_15 ;
unsigned long V_49 ;
struct V_1 * V_1 , * V_75 ;
int V_25 ;
struct V_62 V_63 = {
. V_64 = 0 ,
. V_65 = V_66 ,
. V_67 = V_68
} ;
F_56 ( V_76 ) ;
if ( V_61 > F_44 ( V_69 ) )
V_61 = F_44 ( V_69 ) ;
for ( V_49 = 0 ; V_49 < V_61 ; V_49 ++ ) {
V_1 = F_57 ( V_74 ) ;
if ( V_1 == NULL ) {
V_61 = V_49 ;
V_12 = V_21 ;
break;
}
F_1 ( V_1 ) ;
F_7 ( & V_1 -> V_2 , & V_76 ) ;
}
F_58 () ;
V_49 = 0 ;
F_59 (page, tmp, &pages, lru) {
V_69 [ V_49 ++ ] = F_60 ( V_1 ) ;
#ifdef F_28
F_29 ( V_47 != V_33 ) ;
if ( ! F_30 ( V_48 ) ) {
unsigned long V_37 = F_50 ( V_1 ) ;
if ( ! F_5 ( V_1 ) ) {
V_25 = F_51 (
( unsigned long ) F_52 ( V_37 << V_36 ) ,
F_61 ( 0 ) , 0 ) ;
F_49 ( V_25 ) ;
}
F_62 ( V_37 , V_50 ) ;
}
#endif
F_14 ( & V_1 -> V_2 ) ;
F_9 ( V_1 ) ;
}
F_63 () ;
F_47 ( V_63 . V_70 , V_69 ) ;
V_63 . V_71 = V_61 ;
V_25 = F_48 ( V_77 , & V_63 ) ;
F_49 ( V_25 != V_61 ) ;
V_4 . V_60 -= V_61 ;
return V_12 ;
}
static void F_64 ( struct V_78 * V_79 )
{
enum V_11 V_12 = V_15 ;
long V_39 ;
do {
F_36 ( & V_51 ) ;
V_39 = F_41 () ;
if ( V_39 > 0 ) {
if ( F_42 () )
V_12 = F_43 ( V_39 ) ;
else
V_12 = F_25 () ;
}
if ( V_39 < 0 )
V_12 = F_55 ( - V_39 , V_80 ) ;
V_12 = F_16 ( V_12 ) ;
F_34 ( & V_51 ) ;
F_65 () ;
} while ( V_39 && V_12 == V_15 );
if ( V_12 == V_21 )
F_40 ( & V_58 , V_4 . V_16 * V_81 ) ;
}
void F_66 ( unsigned long V_82 )
{
V_4 . V_43 = V_82 ;
F_40 ( & V_58 , 0 ) ;
}
static int F_67 ( int V_61 )
{
enum V_11 V_83 ;
if ( V_84 ) {
V_83 = F_25 () ;
if ( V_83 != V_14 ) {
F_34 ( & V_51 ) ;
F_68 ( V_7 ,
! F_12 ( & V_3 ) ) ;
F_36 ( & V_51 ) ;
return 0 ;
}
}
V_83 = F_55 ( V_61 , V_85 ) ;
if ( V_83 != V_15 )
return - V_86 ;
return 0 ;
}
int F_69 ( int V_61 , struct V_1 * * V_76 )
{
int V_87 = 0 ;
struct V_1 * V_1 ;
int V_25 ;
F_36 ( & V_51 ) ;
V_4 . V_44 += V_61 ;
while ( V_87 < V_61 ) {
V_1 = F_11 ( true ) ;
if ( V_1 ) {
V_76 [ V_87 ++ ] = V_1 ;
#ifdef F_28
F_29 ( V_47 != V_33 ) ;
V_25 = F_70 ( F_50 ( V_1 ) ) ;
if ( V_25 < 0 )
goto V_88;
#endif
} else {
V_25 = F_67 ( V_61 - V_87 ) ;
if ( V_25 < 0 )
goto V_88;
}
}
F_34 ( & V_51 ) ;
return 0 ;
V_88:
F_34 ( & V_51 ) ;
F_71 ( V_87 , V_76 ) ;
return V_25 ;
}
void F_71 ( int V_61 , struct V_1 * * V_76 )
{
int V_49 ;
F_36 ( & V_51 ) ;
for ( V_49 = 0 ; V_49 < V_61 ; V_49 ++ ) {
if ( V_76 [ V_49 ] )
F_9 ( V_76 [ V_49 ] ) ;
}
V_4 . V_44 -= V_61 ;
if ( F_41 () )
F_40 ( & V_58 , 0 ) ;
F_34 ( & V_51 ) ;
}
static void T_3 F_72 ( unsigned long V_89 ,
unsigned long V_76 )
{
unsigned long V_37 , V_90 ;
struct V_1 * V_1 ;
V_90 = F_73 ( V_91 , V_89 + V_76 ) ;
for ( V_37 = V_89 ; V_37 < V_90 ; V_37 ++ ) {
V_1 = F_74 ( V_37 ) ;
F_4 ( V_1 ) ;
}
V_4 . V_45 += V_90 - V_89 ;
}
static int T_3 F_75 ( void )
{
int V_49 ;
if ( ! F_76 () )
return - V_92 ;
F_77 ( L_6 ) ;
V_4 . V_60 = F_78 ()
? F_73 ( V_93 -> V_61 - V_94 , V_91 )
: F_79 () ;
V_4 . V_43 = V_4 . V_60 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_45 = V_4 . V_60 ;
V_4 . V_16 = 1 ;
V_4 . V_20 = 32 ;
V_4 . V_17 = 1 ;
V_4 . V_18 = V_19 ;
#ifdef F_80
F_81 ( & F_37 ) ;
F_82 ( & V_95 ) ;
F_83 ( V_96 ) ;
#endif
for ( V_49 = 0 ; V_49 < V_97 ; V_49 ++ )
if ( V_98 [ V_49 ] . V_99 )
F_72 ( V_98 [ V_49 ] . V_89 ,
V_98 [ V_49 ] . V_99 ) ;
return 0 ;
}
