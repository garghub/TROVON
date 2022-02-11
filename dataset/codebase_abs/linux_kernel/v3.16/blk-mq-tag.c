static bool F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
int V_8 ;
V_8 = F_2 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
if ( V_8 < V_6 -> V_10 )
return true ;
}
return false ;
}
bool F_3 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return true ;
return F_1 ( & V_12 -> V_13 ) ;
}
static inline int F_4 ( int V_14 )
{
return ( V_14 + 1 ) & ( V_15 - 1 ) ;
}
static inline void F_5 ( T_1 * V_14 )
{
int V_16 = F_6 ( V_14 ) ;
int V_17 = F_4 ( V_16 ) ;
F_7 ( V_14 , V_16 , V_17 ) ;
}
bool F_8 ( struct V_18 * V_19 )
{
if ( ! F_9 ( V_20 , & V_19 -> V_21 ) &&
! F_10 ( V_20 , & V_19 -> V_21 ) )
F_11 ( & V_19 -> V_12 -> V_22 ) ;
return true ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_3 , V_23 ;
V_2 = & V_12 -> V_13 ;
V_23 = F_6 ( & V_2 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_24 * V_25 = & V_2 -> V_25 [ V_23 ] ;
if ( F_13 ( & V_25 -> V_26 ) )
F_14 ( & V_25 -> V_26 ) ;
V_23 = F_4 ( V_23 ) ;
}
}
void F_15 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_16 ( V_20 , & V_19 -> V_21 ) )
return;
F_17 ( & V_12 -> V_22 ) ;
F_12 ( V_12 ) ;
}
static inline bool F_18 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
unsigned int V_10 , V_27 ;
if ( ! V_19 || ! ( V_19 -> V_28 & V_29 ) )
return true ;
if ( ! F_9 ( V_20 , & V_19 -> V_21 ) )
return true ;
if ( V_2 -> V_10 == 1 )
return true ;
V_27 = F_6 ( & V_19 -> V_12 -> V_22 ) ;
if ( ! V_27 )
return true ;
V_10 = F_19 ( ( V_2 -> V_10 + V_27 - 1 ) / V_27 , 4U ) ;
return F_6 ( & V_19 -> V_30 ) < V_10 ;
}
static int F_20 ( struct V_5 * V_6 , unsigned int V_31 )
{
int V_32 , V_33 , V_34 ;
V_33 = V_31 ;
V_34 = V_6 -> V_10 ;
do {
V_35:
V_32 = F_21 ( & V_6 -> V_9 , V_34 , V_31 ) ;
if ( F_22 ( V_32 >= V_34 ) ) {
if ( V_33 && V_31 ) {
V_34 = V_31 ;
V_31 = 0 ;
goto V_35;
}
return - 1 ;
}
V_31 = V_32 + 1 ;
} while ( F_23 ( V_32 , & V_6 -> V_9 ) );
return V_32 ;
}
static int F_24 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned int * V_36 )
{
unsigned int V_31 , V_33 ;
int V_14 , V_3 , V_32 ;
if ( ! F_18 ( V_19 , V_2 ) )
return - 1 ;
V_31 = V_33 = * V_36 ;
V_14 = F_25 ( V_2 , V_31 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_32 = F_20 ( & V_2 -> V_7 [ V_14 ] , F_26 ( V_2 , V_31 ) ) ;
if ( V_32 != - 1 ) {
V_32 += ( V_14 << V_2 -> V_37 ) ;
goto V_38;
}
V_31 = 0 ;
if ( ++ V_14 >= V_2 -> V_4 )
V_14 = 0 ;
}
* V_36 = 0 ;
return - 1 ;
V_38:
if ( V_32 == V_33 ) {
V_31 = V_32 + 1 ;
if ( V_31 >= V_2 -> V_10 - 1 )
V_31 = 0 ;
* V_36 = V_31 ;
}
return V_32 ;
}
static struct V_24 * F_27 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_24 * V_25 ;
int V_39 ;
if ( ! V_19 )
return & V_2 -> V_25 [ 0 ] ;
V_39 = F_6 ( & V_19 -> V_39 ) ;
V_25 = & V_2 -> V_25 [ V_39 ] ;
F_5 ( & V_19 -> V_39 ) ;
return V_25 ;
}
static int F_28 ( struct V_40 * V_41 ,
struct V_1 * V_2 ,
struct V_18 * V_19 ,
unsigned int * V_31 )
{
struct V_24 * V_25 ;
F_29 ( V_26 ) ;
int V_32 ;
V_32 = F_24 ( V_19 , V_2 , V_31 ) ;
if ( V_32 != - 1 )
return V_32 ;
if ( ! ( V_41 -> V_42 & V_43 ) )
return - 1 ;
V_25 = F_27 ( V_2 , V_19 ) ;
do {
F_30 ( & V_25 -> V_26 , & V_26 , V_44 ) ;
V_32 = F_24 ( V_19 , V_2 , V_31 ) ;
if ( V_32 != - 1 )
break;
F_31 ( V_41 -> V_45 ) ;
F_32 () ;
V_41 -> V_45 = F_33 ( V_41 -> V_46 ) ;
V_41 -> V_19 = V_41 -> V_46 -> V_47 -> V_48 ( V_41 -> V_46 ,
V_41 -> V_45 -> V_49 ) ;
if ( V_41 -> V_50 ) {
V_2 = & V_41 -> V_19 -> V_12 -> V_51 ;
} else {
V_31 = & V_41 -> V_45 -> V_31 ;
V_19 = V_41 -> V_19 ;
V_2 = & V_19 -> V_12 -> V_13 ;
}
F_34 ( & V_25 -> V_26 , & V_26 ) ;
V_25 = F_27 ( V_2 , V_19 ) ;
} while ( 1 );
F_34 ( & V_25 -> V_26 , & V_26 ) ;
return V_32 ;
}
static unsigned int F_35 ( struct V_40 * V_41 )
{
int V_32 ;
V_32 = F_28 ( V_41 , & V_41 -> V_19 -> V_12 -> V_13 , V_41 -> V_19 ,
& V_41 -> V_45 -> V_31 ) ;
if ( V_32 >= 0 )
return V_32 + V_41 -> V_19 -> V_12 -> V_52 ;
return V_53 ;
}
static unsigned int F_36 ( struct V_40 * V_41 )
{
int V_32 , V_54 = 0 ;
if ( F_22 ( ! V_41 -> V_19 -> V_12 -> V_52 ) ) {
F_37 ( 1 ) ;
return V_53 ;
}
V_32 = F_28 ( V_41 , & V_41 -> V_19 -> V_12 -> V_51 , NULL , & V_54 ) ;
if ( V_32 < 0 )
return V_53 ;
return V_32 ;
}
unsigned int F_38 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_50 )
return F_35 ( V_41 ) ;
return F_36 ( V_41 ) ;
}
static struct V_24 * F_39 ( struct V_1 * V_2 )
{
int V_3 , V_23 ;
V_23 = F_6 ( & V_2 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_24 * V_25 = & V_2 -> V_25 [ V_23 ] ;
if ( F_13 ( & V_25 -> V_26 ) ) {
int V_55 = F_6 ( & V_2 -> V_23 ) ;
if ( V_23 != V_55 )
F_7 ( & V_2 -> V_23 , V_55 , V_23 ) ;
return V_25 ;
}
V_23 = F_4 ( V_23 ) ;
}
return NULL ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_32 )
{
const int V_14 = F_25 ( V_2 , V_32 ) ;
struct V_24 * V_25 ;
int V_56 ;
F_41 ( F_26 ( V_2 , V_32 ) , & V_2 -> V_7 [ V_14 ] . V_9 ) ;
V_25 = F_39 ( V_2 ) ;
if ( ! V_25 )
return;
V_56 = F_42 ( & V_25 -> V_56 ) ;
if ( V_56 == 0 ) {
V_57:
F_43 ( V_2 -> V_58 , & V_25 -> V_56 ) ;
F_5 ( & V_2 -> V_23 ) ;
F_14 ( & V_25 -> V_26 ) ;
} else if ( V_56 < 0 ) {
V_56 = F_44 ( & V_25 -> V_56 ) ;
if ( ! V_56 )
goto V_57;
}
}
static void F_45 ( struct V_11 * V_12 , unsigned int V_32 )
{
F_46 ( V_32 >= V_12 -> V_59 ) ;
F_40 ( & V_12 -> V_13 , V_32 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
unsigned int V_32 )
{
F_46 ( V_32 >= V_12 -> V_52 ) ;
F_40 ( & V_12 -> V_51 , V_32 ) ;
}
void F_48 ( struct V_18 * V_19 , unsigned int V_32 ,
unsigned int * V_31 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_32 >= V_12 -> V_52 ) {
const int V_60 = V_32 - V_12 -> V_52 ;
F_45 ( V_12 , V_60 ) ;
* V_31 = V_60 ;
} else
F_47 ( V_12 , V_32 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
unsigned long * V_61 , unsigned int V_62 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
int V_63 = 0 ;
do {
V_63 = F_21 ( & V_6 -> V_9 , V_6 -> V_10 , V_63 ) ;
if ( V_63 >= V_6 -> V_10 )
break;
F_50 ( V_63 + V_62 , V_61 ) ;
V_63 ++ ;
} while ( 1 );
V_62 += ( 1 << V_2 -> V_37 ) ;
}
}
void F_51 ( struct V_11 * V_12 ,
void (* F_52)( void * , unsigned long * ) , void * V_41 )
{
unsigned long * V_64 ;
T_2 V_65 ;
V_65 = F_53 ( V_12 -> V_59 , V_66 ) / V_66 ;
V_64 = F_54 ( V_65 * sizeof( unsigned long ) , V_67 ) ;
if ( ! V_64 )
return;
F_49 ( & V_12 -> V_13 , V_64 , V_12 -> V_52 ) ;
if ( V_12 -> V_52 )
F_49 ( & V_12 -> V_51 , V_64 , 0 ) ;
F_52 ( V_41 , V_64 ) ;
F_55 ( V_64 ) ;
}
static unsigned int F_56 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_68 ;
for ( V_3 = 0 , V_68 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
V_68 += F_57 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
}
return V_2 -> V_10 - V_68 ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
unsigned int V_69 = 1U << V_2 -> V_37 ;
unsigned int V_70 = V_10 ;
if ( V_10 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = F_59 ( V_70 , V_69 ) ;
V_70 -= V_2 -> V_7 [ V_3 ] . V_10 ;
}
}
V_2 -> V_58 = V_71 ;
if ( V_2 -> V_58 > V_10 / 4 )
V_2 -> V_58 = F_19 ( 1U , V_10 / 4 ) ;
V_2 -> V_10 = V_10 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_10 ,
int V_72 , bool V_50 )
{
int V_3 ;
V_2 -> V_37 = F_61 ( V_66 ) ;
if ( V_10 ) {
unsigned int V_73 , V_69 ;
V_69 = ( 1 << V_2 -> V_37 ) ;
if ( V_10 >= 4 ) {
while ( V_69 * 4 > V_10 ) {
V_2 -> V_37 -- ;
V_69 = ( 1 << V_2 -> V_37 ) ;
}
}
V_73 = F_53 ( V_10 , V_69 ) / V_69 ;
V_2 -> V_7 = F_62 ( V_73 * sizeof( struct V_5 ) ,
V_74 , V_72 ) ;
if ( ! V_2 -> V_7 )
return - V_75 ;
V_2 -> V_4 = V_73 ;
}
V_2 -> V_25 = F_54 ( V_15 * sizeof( * V_2 -> V_25 ) , V_74 ) ;
if ( ! V_2 -> V_25 ) {
F_55 ( V_2 -> V_7 ) ;
return - V_75 ;
}
F_58 ( V_2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
F_63 ( & V_2 -> V_25 [ V_3 ] . V_26 ) ;
F_64 ( & V_2 -> V_25 [ V_3 ] . V_56 , V_2 -> V_58 ) ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_7 ) ;
F_55 ( V_2 -> V_25 ) ;
}
static struct V_11 * F_66 ( struct V_11 * V_12 ,
int V_72 )
{
unsigned int V_10 = V_12 -> V_59 - V_12 -> V_52 ;
if ( F_60 ( & V_12 -> V_13 , V_10 , V_72 , false ) )
goto V_76;
if ( F_60 ( & V_12 -> V_51 , V_12 -> V_52 , V_72 , true ) )
goto V_76;
return V_12 ;
V_76:
F_65 ( & V_12 -> V_13 ) ;
F_55 ( V_12 ) ;
return NULL ;
}
struct V_11 * F_67 ( unsigned int V_77 ,
unsigned int V_78 , int V_72 )
{
struct V_11 * V_12 ;
if ( V_77 > V_79 ) {
F_68 ( L_1 ) ;
return NULL ;
}
V_12 = F_62 ( sizeof( * V_12 ) , V_74 , V_72 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_59 = V_77 ;
V_12 -> V_52 = V_78 ;
return F_66 ( V_12 , V_72 ) ;
}
void F_69 ( struct V_11 * V_12 )
{
F_65 ( & V_12 -> V_13 ) ;
F_65 ( & V_12 -> V_51 ) ;
F_55 ( V_12 ) ;
}
void F_70 ( struct V_11 * V_12 , unsigned int * V_32 )
{
unsigned int V_10 = V_12 -> V_59 - V_12 -> V_52 ;
* V_32 = F_71 () % V_10 ;
}
int F_72 ( struct V_11 * V_12 , unsigned int V_80 )
{
V_80 -= V_12 -> V_52 ;
if ( V_80 > V_12 -> V_59 )
return - V_81 ;
F_58 ( & V_12 -> V_13 , V_80 ) ;
F_12 ( V_12 ) ;
return 0 ;
}
T_3 F_73 ( struct V_11 * V_12 , char * V_82 )
{
char * V_83 = V_82 ;
unsigned int free , V_84 ;
if ( ! V_12 )
return 0 ;
V_82 += sprintf ( V_82 , L_2
L_3 ,
V_12 -> V_59 , V_12 -> V_52 ,
V_12 -> V_13 . V_37 ) ;
free = F_56 ( & V_12 -> V_13 ) ;
V_84 = F_56 ( & V_12 -> V_51 ) ;
V_82 += sprintf ( V_82 , L_4 , free , V_84 ) ;
V_82 += sprintf ( V_82 , L_5 , F_6 ( & V_12 -> V_22 ) ) ;
return V_82 - V_83 ;
}
