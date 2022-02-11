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
if ( V_42 -> V_30 & V_43 )
return - 1 ;
V_26 = F_28 ( V_2 , V_19 ) ;
do {
F_31 ( & V_26 -> V_27 , & V_27 , V_44 ) ;
V_35 = F_24 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
if ( V_19 )
F_32 ( V_19 , false ) ;
V_35 = F_24 ( V_19 , V_2 , V_33 , V_12 ) ;
if ( V_35 != - 1 )
break;
F_33 ( V_42 -> V_45 ) ;
F_34 () ;
V_42 -> V_45 = F_35 ( V_42 -> V_46 ) ;
V_42 -> V_19 = V_42 -> V_46 -> V_47 -> V_48 ( V_42 -> V_46 ,
V_42 -> V_45 -> V_49 ) ;
if ( V_42 -> V_30 & V_50 ) {
V_2 = & V_42 -> V_19 -> V_12 -> V_28 ;
} else {
V_33 = & V_42 -> V_45 -> V_33 ;
V_19 = V_42 -> V_19 ;
V_2 = & V_19 -> V_12 -> V_13 ;
}
F_36 ( & V_26 -> V_27 , & V_27 ) ;
V_26 = F_28 ( V_2 , V_19 ) ;
} while ( 1 );
F_36 ( & V_26 -> V_27 , & V_27 ) ;
return V_35 ;
}
static unsigned int F_37 ( struct V_41 * V_42 )
{
int V_35 ;
V_35 = F_29 ( V_42 , & V_42 -> V_19 -> V_12 -> V_13 , V_42 -> V_19 ,
& V_42 -> V_45 -> V_33 , V_42 -> V_19 -> V_12 ) ;
if ( V_35 >= 0 )
return V_35 + V_42 -> V_19 -> V_12 -> V_51 ;
return V_52 ;
}
static unsigned int F_38 ( struct V_41 * V_42 )
{
int V_35 , V_53 = 0 ;
if ( F_23 ( ! V_42 -> V_19 -> V_12 -> V_51 ) ) {
F_39 ( 1 ) ;
return V_52 ;
}
V_35 = F_29 ( V_42 , & V_42 -> V_19 -> V_12 -> V_28 , NULL , & V_53 ,
V_42 -> V_19 -> V_12 ) ;
if ( V_35 < 0 )
return V_52 ;
return V_35 ;
}
unsigned int F_40 ( struct V_41 * V_42 )
{
if ( V_42 -> V_30 & V_50 )
return F_38 ( V_42 ) ;
return F_37 ( V_42 ) ;
}
static struct V_25 * F_41 ( struct V_1 * V_2 )
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
static void F_42 ( struct V_1 * V_2 , unsigned int V_35 )
{
const int V_14 = F_25 ( V_2 , V_35 ) ;
struct V_25 * V_26 ;
int V_55 ;
F_43 ( F_26 ( V_2 , V_35 ) , & V_2 -> V_7 [ V_14 ] . V_9 ) ;
F_13 () ;
V_26 = F_41 ( V_2 ) ;
if ( ! V_26 )
return;
V_55 = F_44 ( & V_26 -> V_55 ) ;
if ( F_23 ( V_55 < 0 ) )
V_55 = F_45 ( & V_26 -> V_55 ) ;
if ( V_55 == 0 ) {
F_46 ( V_2 -> V_56 , & V_26 -> V_55 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_15 ( & V_26 -> V_27 ) ;
}
}
void F_47 ( struct V_18 * V_19 , unsigned int V_35 ,
unsigned int * V_33 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_35 >= V_12 -> V_51 ) {
const int V_57 = V_35 - V_12 -> V_51 ;
F_48 ( V_57 >= V_12 -> V_58 ) ;
F_42 ( & V_12 -> V_13 , V_57 ) ;
if ( F_49 ( V_12 -> V_59 == V_60 ) )
* V_33 = V_57 ;
} else {
F_48 ( V_35 >= V_12 -> V_51 ) ;
F_42 ( & V_12 -> V_28 , V_35 ) ;
}
}
static void F_50 ( struct V_18 * V_19 ,
struct V_1 * V_2 , unsigned int V_61 ,
T_2 * V_62 , void * V_42 , bool V_63 )
{
struct V_64 * V_65 ;
int V_66 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_66 = F_51 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_66 < V_6 -> V_10 ;
V_66 = F_52 ( & V_6 -> V_9 , V_6 -> V_10 , V_66 + 1 ) ) {
V_65 = V_19 -> V_12 -> V_67 [ V_61 + V_66 ] ;
if ( V_65 -> V_46 == V_19 -> V_68 )
V_62 ( V_19 , V_65 , V_42 , V_63 ) ;
}
V_61 += ( 1 << V_2 -> V_38 ) ;
}
}
static void F_53 ( struct V_11 * V_12 ,
struct V_1 * V_2 , unsigned int V_61 ,
T_3 * V_62 , void * V_42 , bool V_63 )
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
V_65 = V_12 -> V_67 [ V_61 + V_66 ] ;
V_62 ( V_65 , V_42 , V_63 ) ;
}
V_61 += ( 1 << V_2 -> V_38 ) ;
}
}
static void F_54 ( struct V_11 * V_12 ,
T_3 * V_62 , void * V_69 )
{
if ( V_12 -> V_51 )
F_53 ( V_12 , & V_12 -> V_28 , 0 , V_62 , V_69 , true ) ;
F_53 ( V_12 , & V_12 -> V_13 , V_12 -> V_51 , V_62 , V_69 ,
false ) ;
}
void F_55 ( struct V_70 * V_71 ,
T_3 * V_62 , void * V_69 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_71 -> V_72 ; V_3 ++ ) {
if ( V_71 -> V_12 && V_71 -> V_12 [ V_3 ] )
F_54 ( V_71 -> V_12 [ V_3 ] , V_62 , V_69 ) ;
}
}
int F_56 ( struct V_70 * V_73 )
{
int V_3 , V_74 , V_8 = 0 ;
if ( ! V_73 -> V_75 -> V_76 )
goto V_77;
for ( V_3 = 0 ; V_3 < V_73 -> V_72 ; V_3 ++ ) {
struct V_11 * V_12 = V_73 -> V_12 [ V_3 ] ;
for ( V_74 = 0 ; V_74 < V_12 -> V_58 ; V_74 ++ ) {
if ( ! V_12 -> V_67 [ V_74 ] )
continue;
V_8 = V_73 -> V_75 -> V_76 ( V_73 -> V_78 ,
V_12 -> V_67 [ V_74 ] ) ;
if ( V_8 )
goto V_77;
}
}
V_77:
return V_8 ;
}
void F_57 ( struct V_79 * V_46 , T_2 * V_62 ,
void * V_69 )
{
struct V_18 * V_19 ;
int V_3 ;
F_58 (q, hctx, i) {
struct V_11 * V_12 = V_19 -> V_12 ;
if ( ! F_59 ( V_19 ) )
continue;
if ( V_12 -> V_51 )
F_50 ( V_19 , & V_12 -> V_28 , 0 , V_62 , V_69 , true ) ;
F_50 ( V_19 , & V_12 -> V_13 , V_12 -> V_51 , V_62 , V_69 ,
false ) ;
}
}
static unsigned int F_60 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_80 ;
for ( V_3 = 0 , V_80 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
V_80 += F_61 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
}
return V_2 -> V_10 - V_80 ;
}
static void F_62 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
unsigned int V_81 = 1U << V_2 -> V_38 ;
unsigned int V_82 = V_10 ;
if ( V_10 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = F_63 ( V_82 , V_81 ) ;
V_82 -= V_2 -> V_7 [ V_3 ] . V_10 ;
}
}
V_2 -> V_56 = V_83 ;
if ( V_2 -> V_56 > V_10 / V_15 )
V_2 -> V_56 = F_20 ( 1U , V_10 / V_15 ) ;
V_2 -> V_10 = V_10 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_10 ,
int V_84 , bool V_63 )
{
int V_3 ;
V_2 -> V_38 = F_65 ( V_85 ) ;
if ( V_10 ) {
unsigned int V_86 , V_81 ;
V_81 = ( 1 << V_2 -> V_38 ) ;
if ( V_10 >= 4 ) {
while ( V_81 * 4 > V_10 ) {
V_2 -> V_38 -- ;
V_81 = ( 1 << V_2 -> V_38 ) ;
}
}
V_86 = F_66 ( V_10 , V_81 ) / V_81 ;
V_2 -> V_7 = F_67 ( V_86 * sizeof( struct V_5 ) ,
V_87 , V_84 ) ;
if ( ! V_2 -> V_7 )
return - V_88 ;
V_2 -> V_4 = V_86 ;
}
V_2 -> V_26 = F_68 ( V_15 * sizeof( * V_2 -> V_26 ) , V_87 ) ;
if ( ! V_2 -> V_26 ) {
F_69 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
return - V_88 ;
}
F_62 ( V_2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
F_70 ( & V_2 -> V_26 [ V_3 ] . V_27 ) ;
F_71 ( & V_2 -> V_26 [ V_3 ] . V_55 , V_2 -> V_56 ) ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_69 ( V_2 -> V_7 ) ;
F_69 ( V_2 -> V_26 ) ;
}
static struct V_11 * F_73 ( struct V_11 * V_12 ,
int V_84 , int V_59 )
{
unsigned int V_10 = V_12 -> V_58 - V_12 -> V_51 ;
V_12 -> V_59 = V_59 ;
if ( F_64 ( & V_12 -> V_13 , V_10 , V_84 , false ) )
goto V_89;
if ( F_64 ( & V_12 -> V_28 , V_12 -> V_51 , V_84 , true ) )
goto V_89;
return V_12 ;
V_89:
F_72 ( & V_12 -> V_13 ) ;
F_69 ( V_12 ) ;
return NULL ;
}
struct V_11 * F_74 ( unsigned int V_90 ,
unsigned int V_91 ,
int V_84 , int V_59 )
{
struct V_11 * V_12 ;
if ( V_90 > V_92 ) {
F_75 ( L_1 ) ;
return NULL ;
}
V_12 = F_67 ( sizeof( * V_12 ) , V_87 , V_84 ) ;
if ( ! V_12 )
return NULL ;
if ( ! F_76 ( & V_12 -> V_93 , V_87 ) ) {
F_69 ( V_12 ) ;
return NULL ;
}
V_12 -> V_58 = V_90 ;
V_12 -> V_51 = V_91 ;
return F_73 ( V_12 , V_84 , V_59 ) ;
}
void F_77 ( struct V_11 * V_12 )
{
F_72 ( & V_12 -> V_13 ) ;
F_72 ( & V_12 -> V_28 ) ;
F_78 ( V_12 -> V_93 ) ;
F_69 ( V_12 ) ;
}
void F_79 ( struct V_11 * V_12 , unsigned int * V_35 )
{
unsigned int V_10 = V_12 -> V_58 - V_12 -> V_51 ;
* V_35 = F_80 () % V_10 ;
}
int F_81 ( struct V_11 * V_12 , unsigned int V_94 )
{
V_94 -= V_12 -> V_51 ;
if ( V_94 > V_12 -> V_58 )
return - V_95 ;
F_62 ( & V_12 -> V_13 , V_94 ) ;
F_12 ( V_12 , false ) ;
return 0 ;
}
T_4 F_82 ( struct V_64 * V_65 )
{
struct V_79 * V_46 = V_65 -> V_46 ;
struct V_18 * V_19 ;
int V_96 = 0 ;
if ( V_46 -> V_47 ) {
V_19 = V_46 -> V_47 -> V_48 ( V_46 , V_65 -> V_97 -> V_49 ) ;
V_96 = V_19 -> V_98 ;
}
return ( V_96 << V_99 ) |
( V_65 -> V_35 & V_100 ) ;
}
T_5 F_83 ( struct V_11 * V_12 , char * V_101 )
{
char * V_102 = V_101 ;
unsigned int free , V_103 ;
if ( ! V_12 )
return 0 ;
V_101 += sprintf ( V_101 , L_2
L_3 ,
V_12 -> V_58 , V_12 -> V_51 ,
V_12 -> V_13 . V_38 ) ;
free = F_60 ( & V_12 -> V_13 ) ;
V_103 = F_60 ( & V_12 -> V_28 ) ;
V_101 += sprintf ( V_101 , L_4 , free , V_103 ) ;
V_101 += sprintf ( V_101 , L_5 , F_6 ( & V_12 -> V_22 ) ) ;
return V_101 - V_102 ;
}
