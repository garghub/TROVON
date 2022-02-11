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
static struct V_22 * F_17 ( T_1 V_23 )
{
struct V_22 * V_24 ;
int V_25 ;
V_24 = F_18 ( sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_27 = L_1 ;
V_24 -> V_28 = V_29 | V_30 ;
V_25 = F_19 ( & V_31 , V_24 ,
V_23 , 0 , - 1 ,
V_32 * V_33 , NULL , NULL ) ;
if ( V_25 < 0 ) {
F_20 ( L_2 ) ;
F_21 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
static void F_22 ( struct V_22 * V_22 )
{
if ( ! V_22 )
return;
F_23 ( V_22 ) ;
F_21 ( V_22 ) ;
}
static enum V_11 F_24 ( void )
{
long V_34 ;
struct V_22 * V_22 ;
int V_35 , V_36 ;
unsigned long V_37 ;
V_34 = V_4 . V_38 + V_4 . V_39
- V_4 . V_40 ;
if ( V_34 <= 0 )
return V_13 ;
V_37 = F_25 ( V_34 , V_32 ) ;
V_22 = F_17 ( V_37 * V_33 ) ;
if ( ! V_22 )
goto V_41;
V_35 = F_26 ( V_22 -> V_42 ) ;
#ifdef F_27
F_28 ( V_43 != V_33 ) ;
if ( ! F_29 ( V_44 ) ) {
unsigned long V_45 , V_46 ;
V_45 = F_30 ( V_22 -> V_42 ) ;
for ( V_46 = 0 ; V_46 < V_37 ; V_46 ++ ) {
if ( ! F_31 ( V_45 + V_46 , V_47 ) ) {
F_32 ( L_3 ) ;
goto V_41;
}
}
}
#endif
V_36 = F_33 ( V_35 , V_22 ) ;
if ( V_36 ) {
F_32 ( L_4 , V_36 ) ;
goto V_41;
}
V_4 . V_40 += V_37 ;
return V_13 ;
V_41:
F_22 ( V_22 ) ;
return V_14 ;
}
static void F_34 ( struct V_1 * V_1 )
{
F_35 ( V_1 ) ;
F_36 ( & V_48 ) ;
F_4 ( V_1 ) ;
F_37 ( & V_48 ) ;
}
static int F_38 ( struct V_49 * V_50 , unsigned long V_51 , void * V_52 )
{
if ( V_51 == V_53 )
F_39 ( & V_54 , 0 ) ;
return V_55 ;
}
static enum V_11 F_24 ( void )
{
V_4 . V_38 = V_4 . V_56 ;
return V_14 ;
}
static long F_40 ( void )
{
return V_4 . V_38 - V_4 . V_56 ;
}
static bool F_41 ( void )
{
return V_4 . V_6 || V_4 . V_5 ;
}
static enum V_11 F_42 ( unsigned long V_57 )
{
int V_36 ;
unsigned long V_46 ;
struct V_1 * V_1 ;
struct V_58 V_59 = {
. V_60 = 0 ,
. V_61 = V_62 ,
. V_63 = V_64
} ;
if ( V_57 > F_43 ( V_65 ) )
V_57 = F_43 ( V_65 ) ;
V_1 = F_44 ( & V_3 , struct V_1 , V_2 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ ) {
if ( ! V_1 ) {
V_57 = V_46 ;
break;
}
V_65 [ V_46 ] = F_45 ( V_1 ) ;
V_1 = F_15 ( V_1 ) ;
}
F_46 ( V_59 . V_66 , V_65 ) ;
V_59 . V_67 = V_57 ;
V_36 = F_47 ( V_68 , & V_59 ) ;
if ( V_36 <= 0 )
return V_21 ;
for ( V_46 = 0 ; V_46 < V_36 ; V_46 ++ ) {
V_1 = F_11 ( false ) ;
F_48 ( V_1 == NULL ) ;
#ifdef F_27
F_28 ( V_43 != V_33 ) ;
if ( ! F_29 ( V_44 ) ) {
unsigned long V_45 = F_49 ( V_1 ) ;
F_31 ( V_45 , V_65 [ V_46 ] ) ;
if ( ! F_5 ( V_1 ) ) {
int V_25 ;
V_25 = F_50 (
( unsigned long ) F_51 ( V_45 << V_69 ) ,
F_52 ( V_65 [ V_46 ] , V_70 ) ,
0 ) ;
F_48 ( V_25 ) ;
}
}
#endif
F_53 ( V_1 ) ;
}
V_4 . V_56 += V_36 ;
return V_15 ;
}
static enum V_11 F_54 ( unsigned long V_57 , T_2 V_71 )
{
enum V_11 V_12 = V_15 ;
unsigned long V_46 ;
struct V_1 * V_1 , * V_72 ;
int V_25 ;
struct V_58 V_59 = {
. V_60 = 0 ,
. V_61 = V_62 ,
. V_63 = V_64
} ;
F_55 ( V_73 ) ;
if ( V_57 > F_43 ( V_65 ) )
V_57 = F_43 ( V_65 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ ) {
V_1 = F_56 ( V_71 ) ;
if ( V_1 == NULL ) {
V_57 = V_46 ;
V_12 = V_21 ;
break;
}
F_1 ( V_1 ) ;
F_7 ( & V_1 -> V_2 , & V_73 ) ;
}
F_57 () ;
V_46 = 0 ;
F_58 (page, tmp, &pages, lru) {
V_65 [ V_46 ++ ] = F_59 ( V_1 ) ;
#ifdef F_27
F_28 ( V_43 != V_33 ) ;
if ( ! F_29 ( V_44 ) ) {
unsigned long V_45 = F_49 ( V_1 ) ;
if ( ! F_5 ( V_1 ) ) {
V_25 = F_50 (
( unsigned long ) F_51 ( V_45 << V_69 ) ,
F_60 ( 0 ) , 0 ) ;
F_48 ( V_25 ) ;
}
F_61 ( V_45 , V_47 ) ;
}
#endif
F_14 ( & V_1 -> V_2 ) ;
F_9 ( V_1 ) ;
}
F_62 () ;
F_46 ( V_59 . V_66 , V_65 ) ;
V_59 . V_67 = V_57 ;
V_25 = F_47 ( V_74 , & V_59 ) ;
F_48 ( V_25 != V_57 ) ;
V_4 . V_56 -= V_57 ;
return V_12 ;
}
static void F_63 ( struct V_75 * V_76 )
{
enum V_11 V_12 = V_15 ;
long V_34 ;
do {
F_36 ( & V_48 ) ;
V_34 = F_40 () ;
if ( V_34 > 0 ) {
if ( F_41 () )
V_12 = F_42 ( V_34 ) ;
else
V_12 = F_24 () ;
}
if ( V_34 < 0 )
V_12 = F_54 ( - V_34 , V_77 ) ;
V_12 = F_16 ( V_12 ) ;
F_37 ( & V_48 ) ;
F_64 () ;
} while ( V_34 && V_12 == V_15 );
if ( V_12 == V_21 )
F_39 ( & V_54 , V_4 . V_16 * V_78 ) ;
}
void F_65 ( unsigned long V_79 )
{
V_4 . V_38 = V_79 ;
F_39 ( & V_54 , 0 ) ;
}
static int F_66 ( int V_57 )
{
enum V_11 V_80 ;
if ( V_81 ) {
V_80 = F_24 () ;
if ( V_80 != V_14 ) {
F_37 ( & V_48 ) ;
F_67 ( V_7 ,
! F_12 ( & V_3 ) ) ;
F_36 ( & V_48 ) ;
return 0 ;
}
}
V_80 = F_54 ( V_57 , V_82 ) ;
if ( V_80 != V_15 )
return - V_83 ;
return 0 ;
}
int F_68 ( int V_57 , struct V_1 * * V_73 )
{
int V_84 = 0 ;
struct V_1 * V_1 ;
int V_25 ;
F_36 ( & V_48 ) ;
V_4 . V_39 += V_57 ;
while ( V_84 < V_57 ) {
V_1 = F_11 ( true ) ;
if ( V_1 ) {
V_73 [ V_84 ++ ] = V_1 ;
#ifdef F_27
F_28 ( V_43 != V_33 ) ;
V_25 = F_69 ( F_49 ( V_1 ) ) ;
if ( V_25 < 0 )
goto V_85;
#endif
} else {
V_25 = F_66 ( V_57 - V_84 ) ;
if ( V_25 < 0 )
goto V_85;
}
}
F_37 ( & V_48 ) ;
return 0 ;
V_85:
F_37 ( & V_48 ) ;
F_70 ( V_84 , V_73 ) ;
return V_25 ;
}
void F_70 ( int V_57 , struct V_1 * * V_73 )
{
int V_46 ;
F_36 ( & V_48 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ ) {
if ( V_73 [ V_46 ] )
F_9 ( V_73 [ V_46 ] ) ;
}
V_4 . V_39 -= V_57 ;
if ( F_40 () )
F_39 ( & V_54 , 0 ) ;
F_37 ( & V_48 ) ;
}
static void T_3 F_71 ( unsigned long V_86 ,
unsigned long V_73 )
{
unsigned long V_45 , V_87 ;
struct V_1 * V_1 ;
V_87 = F_72 ( V_88 , V_86 + V_73 ) ;
for ( V_45 = V_86 ; V_45 < V_87 ; V_45 ++ ) {
V_1 = F_73 ( V_45 ) ;
F_4 ( V_1 ) ;
}
V_4 . V_40 += V_87 - V_86 ;
}
static int T_3 F_74 ( void )
{
int V_46 ;
if ( ! F_75 () )
return - V_89 ;
F_76 ( L_5 ) ;
V_4 . V_56 = F_77 ()
? F_72 ( V_90 -> V_57 - V_91 , V_88 )
: F_78 () ;
V_4 . V_38 = V_4 . V_56 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_40 = V_4 . V_56 ;
V_4 . V_16 = 1 ;
V_4 . V_20 = 32 ;
V_4 . V_17 = 1 ;
V_4 . V_18 = V_19 ;
#ifdef F_79
F_80 ( & F_34 ) ;
F_81 ( & V_92 ) ;
F_82 ( V_93 ) ;
#endif
for ( V_46 = 0 ; V_46 < V_94 ; V_46 ++ )
if ( V_95 [ V_46 ] . V_96 )
F_71 ( V_95 [ V_46 ] . V_86 ,
V_95 [ V_46 ] . V_96 ) ;
return 0 ;
}
