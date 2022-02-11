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
V_2 = & V_12 -> V_13 ;
V_24 = F_6 ( & V_2 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 ] ;
if ( F_13 ( & V_26 -> V_27 ) )
F_14 ( & V_26 -> V_27 ) ;
V_24 = F_4 ( V_24 ) ;
}
if ( V_23 ) {
V_2 = & V_12 -> V_28 ;
if ( F_13 ( & V_2 -> V_26 [ 0 ] . V_27 ) )
F_14 ( & V_2 -> V_26 [ 0 ] . V_27 ) ;
}
}
void F_15 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_16 ( V_20 , & V_19 -> V_21 ) )
return;
F_17 ( & V_12 -> V_22 ) ;
F_12 ( V_12 , false ) ;
}
static inline bool F_18 ( struct V_18 * V_19 ,
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
V_10 = F_19 ( ( V_2 -> V_10 + V_29 - 1 ) / V_29 , 4U ) ;
return F_6 ( & V_19 -> V_32 ) < V_10 ;
}
static int F_20 ( struct V_5 * V_6 , unsigned int V_33 ,
bool V_34 )
{
int V_35 , V_36 = V_33 ;
while ( 1 ) {
V_35 = F_21 ( & V_6 -> V_9 , V_6 -> V_10 , V_33 ) ;
if ( F_22 ( V_35 >= V_6 -> V_10 ) ) {
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
static int F_23 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned int * V_37 , struct V_11 * V_12 )
{
unsigned int V_33 , V_36 ;
int V_14 , V_3 , V_35 ;
if ( ! F_18 ( V_19 , V_2 ) )
return - 1 ;
V_33 = V_36 = * V_37 ;
V_14 = F_24 ( V_2 , V_33 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_35 = F_20 ( & V_2 -> V_7 [ V_14 ] , F_25 ( V_2 , V_33 ) ,
F_26 ( V_12 ) ) ;
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
if ( V_35 == V_36 || F_22 ( F_26 ( V_12 ) ) ) {
V_33 = V_35 + 1 ;
if ( V_33 >= V_2 -> V_10 - 1 )
V_33 = 0 ;
* V_37 = V_33 ;
}
return V_35 ;
}
static struct V_25 * F_27 ( struct V_1 * V_2 ,
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
static int F_28 ( struct V_41 * V_42 ,
struct V_1 * V_2 ,
struct V_18 * V_19 ,
unsigned int * V_33 , struct V_11 * V_12 )
{
struct V_25 * V_26 ;
F_29 ( V_27 ) ;
int V_35 ;
V_35 = F_23 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
return V_35 ;
if ( ! ( V_42 -> V_43 & V_44 ) )
return - 1 ;
V_26 = F_27 ( V_2 , V_19 ) ;
do {
F_30 ( & V_26 -> V_27 , & V_27 , V_45 ) ;
V_35 = F_23 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
if ( V_19 )
F_31 ( V_19 , false ) ;
V_35 = F_23 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
F_32 ( V_42 -> V_46 ) ;
F_33 () ;
V_42 -> V_46 = F_34 ( V_42 -> V_47 ) ;
V_42 -> V_19 = V_42 -> V_47 -> V_48 -> V_49 ( V_42 -> V_47 ,
V_42 -> V_46 -> V_50 ) ;
if ( V_42 -> V_51 ) {
V_2 = & V_42 -> V_19 -> V_12 -> V_28 ;
} else {
V_33 = & V_42 -> V_46 -> V_33 ;
V_19 = V_42 -> V_19 ;
V_2 = & V_19 -> V_12 -> V_13 ;
}
F_35 ( & V_26 -> V_27 , & V_27 ) ;
V_26 = F_27 ( V_2 , V_19 ) ;
} while ( 1 );
F_35 ( & V_26 -> V_27 , & V_27 ) ;
return V_35 ;
}
static unsigned int F_36 ( struct V_41 * V_42 )
{
int V_35 ;
V_35 = F_28 ( V_42 , & V_42 -> V_19 -> V_12 -> V_13 , V_42 -> V_19 ,
& V_42 -> V_46 -> V_33 , V_42 -> V_19 -> V_12 ) ;
if ( V_35 >= 0 )
return V_35 + V_42 -> V_19 -> V_12 -> V_52 ;
return V_53 ;
}
static unsigned int F_37 ( struct V_41 * V_42 )
{
int V_35 , V_54 = 0 ;
if ( F_22 ( ! V_42 -> V_19 -> V_12 -> V_52 ) ) {
F_38 ( 1 ) ;
return V_53 ;
}
V_35 = F_28 ( V_42 , & V_42 -> V_19 -> V_12 -> V_28 , NULL , & V_54 ,
V_42 -> V_19 -> V_12 ) ;
if ( V_35 < 0 )
return V_53 ;
return V_35 ;
}
unsigned int F_39 ( struct V_41 * V_42 )
{
if ( ! V_42 -> V_51 )
return F_36 ( V_42 ) ;
return F_37 ( V_42 ) ;
}
static struct V_25 * F_40 ( struct V_1 * V_2 )
{
int V_3 , V_24 ;
V_24 = F_6 ( & V_2 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 ] ;
if ( F_13 ( & V_26 -> V_27 ) ) {
int V_55 = F_6 ( & V_2 -> V_24 ) ;
if ( V_24 != V_55 )
F_7 ( & V_2 -> V_24 , V_55 , V_24 ) ;
return V_26 ;
}
V_24 = F_4 ( V_24 ) ;
}
return NULL ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_35 )
{
const int V_14 = F_24 ( V_2 , V_35 ) ;
struct V_25 * V_26 ;
int V_56 ;
F_42 ( F_25 ( V_2 , V_35 ) , & V_2 -> V_7 [ V_14 ] . V_9 ) ;
F_43 () ;
V_26 = F_40 ( V_2 ) ;
if ( ! V_26 )
return;
V_56 = F_44 ( & V_26 -> V_56 ) ;
if ( F_22 ( V_56 < 0 ) )
V_56 = F_45 ( & V_26 -> V_56 ) ;
if ( V_56 == 0 ) {
F_46 ( V_2 -> V_57 , & V_26 -> V_56 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_14 ( & V_26 -> V_27 ) ;
}
}
void F_47 ( struct V_18 * V_19 , unsigned int V_35 ,
unsigned int * V_33 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_35 >= V_12 -> V_52 ) {
const int V_58 = V_35 - V_12 -> V_52 ;
F_48 ( V_58 >= V_12 -> V_59 ) ;
F_41 ( & V_12 -> V_13 , V_58 ) ;
if ( F_49 ( V_12 -> V_60 == V_61 ) )
* V_33 = V_58 ;
} else {
F_48 ( V_35 >= V_12 -> V_52 ) ;
F_41 ( & V_12 -> V_28 , V_35 ) ;
}
}
static void F_50 ( struct V_18 * V_19 ,
struct V_1 * V_2 , unsigned int V_62 ,
T_2 * V_63 , void * V_42 , bool V_51 )
{
struct V_64 * V_65 ;
int V_66 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_66 = F_51 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_66 < V_6 -> V_10 ;
V_66 = F_52 ( & V_6 -> V_9 , V_6 -> V_10 , V_66 + 1 ) ) {
V_65 = V_19 -> V_12 -> V_67 [ V_62 + V_66 ] ;
if ( V_65 -> V_47 == V_19 -> V_68 )
V_63 ( V_19 , V_65 , V_42 , V_51 ) ;
}
V_62 += ( 1 << V_2 -> V_38 ) ;
}
}
static void F_53 ( struct V_11 * V_12 ,
struct V_1 * V_2 , unsigned int V_62 ,
T_3 * V_63 , void * V_42 , bool V_51 )
{
struct V_64 * V_65 ;
int V_66 , V_3 ;
if ( ! V_12 -> V_67 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_66 = F_51 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_66 < V_6 -> V_10 ;
V_66 = F_52 ( & V_6 -> V_9 , V_6 -> V_10 , V_66 + 1 ) ) {
V_65 = V_12 -> V_67 [ V_62 + V_66 ] ;
V_63 ( V_65 , V_42 , V_51 ) ;
}
V_62 += ( 1 << V_2 -> V_38 ) ;
}
}
void F_54 ( struct V_11 * V_12 , T_3 * V_63 ,
void * V_69 )
{
if ( V_12 -> V_52 )
F_53 ( V_12 , & V_12 -> V_28 , 0 , V_63 , V_69 , true ) ;
F_53 ( V_12 , & V_12 -> V_13 , V_12 -> V_52 , V_63 , V_69 ,
false ) ;
}
void F_55 ( struct V_70 * V_47 , T_2 * V_63 ,
void * V_69 )
{
struct V_18 * V_19 ;
int V_3 ;
F_56 (q, hctx, i) {
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_57 ( V_19 ) )
continue;
if ( V_12 -> V_52 )
F_50 ( V_19 , & V_12 -> V_28 , 0 , V_63 , V_69 , true ) ;
F_50 ( V_19 , & V_12 -> V_13 , V_12 -> V_52 , V_63 , V_69 ,
false ) ;
}
}
static unsigned int F_58 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_71 ;
for ( V_3 = 0 , V_71 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
V_71 += F_59 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
}
return V_2 -> V_10 - V_71 ;
}
static void F_60 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
unsigned int V_72 = 1U << V_2 -> V_38 ;
unsigned int V_73 = V_10 ;
if ( V_10 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = F_61 ( V_73 , V_72 ) ;
V_73 -= V_2 -> V_7 [ V_3 ] . V_10 ;
}
}
V_2 -> V_57 = V_74 ;
if ( V_2 -> V_57 > V_10 / V_15 )
V_2 -> V_57 = F_19 ( 1U , V_10 / V_15 ) ;
V_2 -> V_10 = V_10 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_10 ,
int V_75 , bool V_51 )
{
int V_3 ;
V_2 -> V_38 = F_63 ( V_76 ) ;
if ( V_10 ) {
unsigned int V_77 , V_72 ;
V_72 = ( 1 << V_2 -> V_38 ) ;
if ( V_10 >= 4 ) {
while ( V_72 * 4 > V_10 ) {
V_2 -> V_38 -- ;
V_72 = ( 1 << V_2 -> V_38 ) ;
}
}
V_77 = F_64 ( V_10 , V_72 ) / V_72 ;
V_2 -> V_7 = F_65 ( V_77 * sizeof( struct V_5 ) ,
V_78 , V_75 ) ;
if ( ! V_2 -> V_7 )
return - V_79 ;
V_2 -> V_4 = V_77 ;
}
V_2 -> V_26 = F_66 ( V_15 * sizeof( * V_2 -> V_26 ) , V_78 ) ;
if ( ! V_2 -> V_26 ) {
F_67 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
return - V_79 ;
}
F_60 ( V_2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
F_68 ( & V_2 -> V_26 [ V_3 ] . V_27 ) ;
F_69 ( & V_2 -> V_26 [ V_3 ] . V_56 , V_2 -> V_57 ) ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_67 ( V_2 -> V_7 ) ;
F_67 ( V_2 -> V_26 ) ;
}
static struct V_11 * F_71 ( struct V_11 * V_12 ,
int V_75 , int V_60 )
{
unsigned int V_10 = V_12 -> V_59 - V_12 -> V_52 ;
V_12 -> V_60 = V_60 ;
if ( F_62 ( & V_12 -> V_13 , V_10 , V_75 , false ) )
goto V_80;
if ( F_62 ( & V_12 -> V_28 , V_12 -> V_52 , V_75 , true ) )
goto V_80;
return V_12 ;
V_80:
F_70 ( & V_12 -> V_13 ) ;
F_67 ( V_12 ) ;
return NULL ;
}
struct V_11 * F_72 ( unsigned int V_81 ,
unsigned int V_82 ,
int V_75 , int V_60 )
{
struct V_11 * V_12 ;
if ( V_81 > V_83 ) {
F_73 ( L_1 ) ;
return NULL ;
}
V_12 = F_65 ( sizeof( * V_12 ) , V_78 , V_75 ) ;
if ( ! V_12 )
return NULL ;
if ( ! F_74 ( & V_12 -> V_84 , V_78 ) ) {
F_67 ( V_12 ) ;
return NULL ;
}
V_12 -> V_59 = V_81 ;
V_12 -> V_52 = V_82 ;
return F_71 ( V_12 , V_75 , V_60 ) ;
}
void F_75 ( struct V_11 * V_12 )
{
F_70 ( & V_12 -> V_13 ) ;
F_70 ( & V_12 -> V_28 ) ;
F_76 ( V_12 -> V_84 ) ;
F_67 ( V_12 ) ;
}
void F_77 ( struct V_11 * V_12 , unsigned int * V_35 )
{
unsigned int V_10 = V_12 -> V_59 - V_12 -> V_52 ;
* V_35 = F_78 () % V_10 ;
}
int F_79 ( struct V_11 * V_12 , unsigned int V_85 )
{
V_85 -= V_12 -> V_52 ;
if ( V_85 > V_12 -> V_59 )
return - V_86 ;
F_60 ( & V_12 -> V_13 , V_85 ) ;
F_12 ( V_12 , false ) ;
return 0 ;
}
T_4 F_80 ( struct V_64 * V_65 )
{
struct V_70 * V_47 = V_65 -> V_47 ;
struct V_18 * V_19 ;
int V_87 = 0 ;
if ( V_47 -> V_48 ) {
V_19 = V_47 -> V_48 -> V_49 ( V_47 , V_65 -> V_88 -> V_50 ) ;
V_87 = V_19 -> V_89 ;
}
return ( V_87 << V_90 ) |
( V_65 -> V_35 & V_91 ) ;
}
T_5 F_81 ( struct V_11 * V_12 , char * V_92 )
{
char * V_93 = V_92 ;
unsigned int free , V_94 ;
if ( ! V_12 )
return 0 ;
V_92 += sprintf ( V_92 , L_2
L_3 ,
V_12 -> V_59 , V_12 -> V_52 ,
V_12 -> V_13 . V_38 ) ;
free = F_58 ( & V_12 -> V_13 ) ;
V_94 = F_58 ( & V_12 -> V_28 ) ;
V_92 += sprintf ( V_92 , L_4 , free , V_94 ) ;
V_92 += sprintf ( V_92 , L_5 , F_6 ( & V_12 -> V_22 ) ) ;
return V_92 - V_93 ;
}
