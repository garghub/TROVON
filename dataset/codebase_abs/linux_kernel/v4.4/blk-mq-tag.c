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
void F_12 ( struct V_11 * V_12 , bool V_23 )
{
struct V_1 * V_2 ;
int V_3 , V_24 ;
F_13 () ;
V_2 = & V_12 -> V_13 ;
V_24 = F_6 ( & V_2 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 ] ;
if ( F_14 ( & V_26 -> V_27 ) )
F_15 ( & V_26 -> V_27 ) ;
V_24 = F_4 ( V_24 ) ;
}
if ( V_23 ) {
V_2 = & V_12 -> V_28 ;
if ( F_14 ( & V_2 -> V_26 [ 0 ] . V_27 ) )
F_15 ( & V_2 -> V_26 [ 0 ] . V_27 ) ;
}
}
void F_16 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_17 ( V_20 , & V_19 -> V_21 ) )
return;
F_18 ( & V_12 -> V_22 ) ;
F_12 ( V_12 , false ) ;
}
static inline bool F_19 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
unsigned int V_10 , V_29 ;
if ( ! V_19 || ! ( V_19 -> V_30 & V_31 ) )
return true ;
if ( ! F_9 ( V_20 , & V_19 -> V_21 ) )
return true ;
if ( V_2 -> V_10 == 1 )
return true ;
V_29 = F_6 ( & V_19 -> V_12 -> V_22 ) ;
if ( ! V_29 )
return true ;
V_10 = F_20 ( ( V_2 -> V_10 + V_29 - 1 ) / V_29 , 4U ) ;
return F_6 ( & V_19 -> V_32 ) < V_10 ;
}
static int F_21 ( struct V_5 * V_6 , unsigned int V_33 ,
bool V_34 )
{
int V_35 , V_36 = V_33 ;
while ( 1 ) {
V_35 = F_22 ( & V_6 -> V_9 , V_6 -> V_10 , V_33 ) ;
if ( F_23 ( V_35 >= V_6 -> V_10 ) ) {
if ( V_36 && V_33 && ! V_34 ) {
V_33 = V_36 = 0 ;
continue;
}
return - 1 ;
}
if ( ! F_10 ( V_35 , & V_6 -> V_9 ) )
break;
V_33 = V_35 + 1 ;
if ( V_33 >= V_6 -> V_10 - 1 )
V_33 = 0 ;
}
return V_35 ;
}
static int F_24 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned int * V_37 , struct V_11 * V_12 )
{
unsigned int V_33 , V_36 ;
int V_14 , V_3 , V_35 ;
if ( ! F_19 ( V_19 , V_2 ) )
return - 1 ;
V_33 = V_36 = * V_37 ;
V_14 = F_25 ( V_2 , V_33 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_35 = F_21 ( & V_2 -> V_7 [ V_14 ] , F_26 ( V_2 , V_33 ) ,
F_27 ( V_12 ) ) ;
if ( V_35 != - 1 ) {
V_35 += ( V_14 << V_2 -> V_38 ) ;
goto V_39;
}
V_14 ++ ;
V_33 = ( V_14 << V_2 -> V_38 ) ;
if ( V_14 >= V_2 -> V_4 ) {
V_14 = 0 ;
V_33 = 0 ;
}
}
* V_37 = 0 ;
return - 1 ;
V_39:
if ( V_35 == V_36 || F_23 ( F_27 ( V_12 ) ) ) {
V_33 = V_35 + 1 ;
if ( V_33 >= V_2 -> V_10 - 1 )
V_33 = 0 ;
* V_37 = V_33 ;
}
return V_35 ;
}
static struct V_25 * F_28 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_25 * V_26 ;
int V_40 ;
if ( ! V_19 )
return & V_2 -> V_26 [ 0 ] ;
V_40 = F_6 ( & V_19 -> V_40 ) ;
V_26 = & V_2 -> V_26 [ V_40 ] ;
F_5 ( & V_19 -> V_40 ) ;
return V_26 ;
}
static int F_29 ( struct V_41 * V_42 ,
struct V_1 * V_2 ,
struct V_18 * V_19 ,
unsigned int * V_33 , struct V_11 * V_12 )
{
struct V_25 * V_26 ;
F_30 ( V_27 ) ;
int V_35 ;
V_35 = F_24 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
return V_35 ;
if ( ! F_31 ( V_42 -> V_43 ) )
return - 1 ;
V_26 = F_28 ( V_2 , V_19 ) ;
do {
F_32 ( & V_26 -> V_27 , & V_27 , V_44 ) ;
V_35 = F_24 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
if ( V_19 )
F_33 ( V_19 , false ) ;
V_35 = F_24 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
F_34 ( V_42 -> V_45 ) ;
F_35 () ;
V_42 -> V_45 = F_36 ( V_42 -> V_46 ) ;
V_42 -> V_19 = V_42 -> V_46 -> V_47 -> V_48 ( V_42 -> V_46 ,
V_42 -> V_45 -> V_49 ) ;
if ( V_42 -> V_50 ) {
V_2 = & V_42 -> V_19 -> V_12 -> V_28 ;
} else {
V_33 = & V_42 -> V_45 -> V_33 ;
V_19 = V_42 -> V_19 ;
V_2 = & V_19 -> V_12 -> V_13 ;
}
F_37 ( & V_26 -> V_27 , & V_27 ) ;
V_26 = F_28 ( V_2 , V_19 ) ;
} while ( 1 );
F_37 ( & V_26 -> V_27 , & V_27 ) ;
return V_35 ;
}
static unsigned int F_38 ( struct V_41 * V_42 )
{
int V_35 ;
V_35 = F_29 ( V_42 , & V_42 -> V_19 -> V_12 -> V_13 , V_42 -> V_19 ,
& V_42 -> V_45 -> V_33 , V_42 -> V_19 -> V_12 ) ;
if ( V_35 >= 0 )
return V_35 + V_42 -> V_19 -> V_12 -> V_51 ;
return V_52 ;
}
static unsigned int F_39 ( struct V_41 * V_42 )
{
int V_35 , V_53 = 0 ;
if ( F_23 ( ! V_42 -> V_19 -> V_12 -> V_51 ) ) {
F_40 ( 1 ) ;
return V_52 ;
}
V_35 = F_29 ( V_42 , & V_42 -> V_19 -> V_12 -> V_28 , NULL , & V_53 ,
V_42 -> V_19 -> V_12 ) ;
if ( V_35 < 0 )
return V_52 ;
return V_35 ;
}
unsigned int F_41 ( struct V_41 * V_42 )
{
if ( ! V_42 -> V_50 )
return F_38 ( V_42 ) ;
return F_39 ( V_42 ) ;
}
static struct V_25 * F_42 ( struct V_1 * V_2 )
{
int V_3 , V_24 ;
V_24 = F_6 ( & V_2 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 ] ;
if ( F_14 ( & V_26 -> V_27 ) ) {
int V_54 = F_6 ( & V_2 -> V_24 ) ;
if ( V_24 != V_54 )
F_7 ( & V_2 -> V_24 , V_54 , V_24 ) ;
return V_26 ;
}
V_24 = F_4 ( V_24 ) ;
}
return NULL ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_35 )
{
const int V_14 = F_25 ( V_2 , V_35 ) ;
struct V_25 * V_26 ;
int V_55 ;
F_44 ( F_26 ( V_2 , V_35 ) , & V_2 -> V_7 [ V_14 ] . V_9 ) ;
F_13 () ;
V_26 = F_42 ( V_2 ) ;
if ( ! V_26 )
return;
V_55 = F_45 ( & V_26 -> V_55 ) ;
if ( F_23 ( V_55 < 0 ) )
V_55 = F_46 ( & V_26 -> V_55 ) ;
if ( V_55 == 0 ) {
F_47 ( V_2 -> V_56 , & V_26 -> V_55 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_15 ( & V_26 -> V_27 ) ;
}
}
void F_48 ( struct V_18 * V_19 , unsigned int V_35 ,
unsigned int * V_33 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_35 >= V_12 -> V_51 ) {
const int V_57 = V_35 - V_12 -> V_51 ;
F_49 ( V_57 >= V_12 -> V_58 ) ;
F_43 ( & V_12 -> V_13 , V_57 ) ;
if ( F_50 ( V_12 -> V_59 == V_60 ) )
* V_33 = V_57 ;
} else {
F_49 ( V_35 >= V_12 -> V_51 ) ;
F_43 ( & V_12 -> V_28 , V_35 ) ;
}
}
static void F_51 ( struct V_18 * V_19 ,
struct V_1 * V_2 , unsigned int V_61 ,
T_2 * V_62 , void * V_42 , bool V_50 )
{
struct V_63 * V_64 ;
int V_65 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_65 = F_52 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_65 < V_6 -> V_10 ;
V_65 = F_53 ( & V_6 -> V_9 , V_6 -> V_10 , V_65 + 1 ) ) {
V_64 = V_19 -> V_12 -> V_66 [ V_61 + V_65 ] ;
if ( V_64 -> V_46 == V_19 -> V_67 )
V_62 ( V_19 , V_64 , V_42 , V_50 ) ;
}
V_61 += ( 1 << V_2 -> V_38 ) ;
}
}
static void F_54 ( struct V_11 * V_12 ,
struct V_1 * V_2 , unsigned int V_61 ,
T_3 * V_62 , void * V_42 , bool V_50 )
{
struct V_63 * V_64 ;
int V_65 , V_3 ;
if ( ! V_12 -> V_66 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_65 = F_52 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_65 < V_6 -> V_10 ;
V_65 = F_53 ( & V_6 -> V_9 , V_6 -> V_10 , V_65 + 1 ) ) {
V_64 = V_12 -> V_66 [ V_61 + V_65 ] ;
V_62 ( V_64 , V_42 , V_50 ) ;
}
V_61 += ( 1 << V_2 -> V_38 ) ;
}
}
void F_55 ( struct V_11 * V_12 , T_3 * V_62 ,
void * V_68 )
{
if ( V_12 -> V_51 )
F_54 ( V_12 , & V_12 -> V_28 , 0 , V_62 , V_68 , true ) ;
F_54 ( V_12 , & V_12 -> V_13 , V_12 -> V_51 , V_62 , V_68 ,
false ) ;
}
void F_56 ( struct V_69 * V_46 , T_2 * V_62 ,
void * V_68 )
{
struct V_18 * V_19 ;
int V_3 ;
F_57 (q, hctx, i) {
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_58 ( V_19 ) )
continue;
if ( V_12 -> V_51 )
F_51 ( V_19 , & V_12 -> V_28 , 0 , V_62 , V_68 , true ) ;
F_51 ( V_19 , & V_12 -> V_13 , V_12 -> V_51 , V_62 , V_68 ,
false ) ;
}
}
static unsigned int F_59 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_70 ;
for ( V_3 = 0 , V_70 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
V_70 += F_60 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
}
return V_2 -> V_10 - V_70 ;
}
static void F_61 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
unsigned int V_71 = 1U << V_2 -> V_38 ;
unsigned int V_72 = V_10 ;
if ( V_10 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = F_62 ( V_72 , V_71 ) ;
V_72 -= V_2 -> V_7 [ V_3 ] . V_10 ;
}
}
V_2 -> V_56 = V_73 ;
if ( V_2 -> V_56 > V_10 / V_15 )
V_2 -> V_56 = F_20 ( 1U , V_10 / V_15 ) ;
V_2 -> V_10 = V_10 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_10 ,
int V_74 , bool V_50 )
{
int V_3 ;
V_2 -> V_38 = F_64 ( V_75 ) ;
if ( V_10 ) {
unsigned int V_76 , V_71 ;
V_71 = ( 1 << V_2 -> V_38 ) ;
if ( V_10 >= 4 ) {
while ( V_71 * 4 > V_10 ) {
V_2 -> V_38 -- ;
V_71 = ( 1 << V_2 -> V_38 ) ;
}
}
V_76 = F_65 ( V_10 , V_71 ) / V_71 ;
V_2 -> V_7 = F_66 ( V_76 * sizeof( struct V_5 ) ,
V_77 , V_74 ) ;
if ( ! V_2 -> V_7 )
return - V_78 ;
V_2 -> V_4 = V_76 ;
}
V_2 -> V_26 = F_67 ( V_15 * sizeof( * V_2 -> V_26 ) , V_77 ) ;
if ( ! V_2 -> V_26 ) {
F_68 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
return - V_78 ;
}
F_61 ( V_2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
F_69 ( & V_2 -> V_26 [ V_3 ] . V_27 ) ;
F_70 ( & V_2 -> V_26 [ V_3 ] . V_55 , V_2 -> V_56 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_7 ) ;
F_68 ( V_2 -> V_26 ) ;
}
static struct V_11 * F_72 ( struct V_11 * V_12 ,
int V_74 , int V_59 )
{
unsigned int V_10 = V_12 -> V_58 - V_12 -> V_51 ;
V_12 -> V_59 = V_59 ;
if ( F_63 ( & V_12 -> V_13 , V_10 , V_74 , false ) )
goto V_79;
if ( F_63 ( & V_12 -> V_28 , V_12 -> V_51 , V_74 , true ) )
goto V_79;
return V_12 ;
V_79:
F_71 ( & V_12 -> V_13 ) ;
F_68 ( V_12 ) ;
return NULL ;
}
struct V_11 * F_73 ( unsigned int V_80 ,
unsigned int V_81 ,
int V_74 , int V_59 )
{
struct V_11 * V_12 ;
if ( V_80 > V_82 ) {
F_74 ( L_1 ) ;
return NULL ;
}
V_12 = F_66 ( sizeof( * V_12 ) , V_77 , V_74 ) ;
if ( ! V_12 )
return NULL ;
if ( ! F_75 ( & V_12 -> V_83 , V_77 ) ) {
F_68 ( V_12 ) ;
return NULL ;
}
V_12 -> V_58 = V_80 ;
V_12 -> V_51 = V_81 ;
return F_72 ( V_12 , V_74 , V_59 ) ;
}
void F_76 ( struct V_11 * V_12 )
{
F_71 ( & V_12 -> V_13 ) ;
F_71 ( & V_12 -> V_28 ) ;
F_77 ( V_12 -> V_83 ) ;
F_68 ( V_12 ) ;
}
void F_78 ( struct V_11 * V_12 , unsigned int * V_35 )
{
unsigned int V_10 = V_12 -> V_58 - V_12 -> V_51 ;
* V_35 = F_79 () % V_10 ;
}
int F_80 ( struct V_11 * V_12 , unsigned int V_84 )
{
V_84 -= V_12 -> V_51 ;
if ( V_84 > V_12 -> V_58 )
return - V_85 ;
F_61 ( & V_12 -> V_13 , V_84 ) ;
F_12 ( V_12 , false ) ;
return 0 ;
}
T_4 F_81 ( struct V_63 * V_64 )
{
struct V_69 * V_46 = V_64 -> V_46 ;
struct V_18 * V_19 ;
int V_86 = 0 ;
if ( V_46 -> V_47 ) {
V_19 = V_46 -> V_47 -> V_48 ( V_46 , V_64 -> V_87 -> V_49 ) ;
V_86 = V_19 -> V_88 ;
}
return ( V_86 << V_89 ) |
( V_64 -> V_35 & V_90 ) ;
}
T_5 F_82 ( struct V_11 * V_12 , char * V_91 )
{
char * V_92 = V_91 ;
unsigned int free , V_93 ;
if ( ! V_12 )
return 0 ;
V_91 += sprintf ( V_91 , L_2
L_3 ,
V_12 -> V_58 , V_12 -> V_51 ,
V_12 -> V_13 . V_38 ) ;
free = F_59 ( & V_12 -> V_13 ) ;
V_93 = F_59 ( & V_12 -> V_28 ) ;
V_91 += sprintf ( V_91 , L_4 , free , V_93 ) ;
V_91 += sprintf ( V_91 , L_5 , F_6 ( & V_12 -> V_22 ) ) ;
return V_91 - V_92 ;
}
