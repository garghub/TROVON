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
static int F_20 ( struct V_5 * V_6 , unsigned int V_33 )
{
int V_34 , V_35 , V_36 ;
bool V_37 = V_33 != 0 ;
V_35 = V_33 ;
V_36 = V_6 -> V_10 ;
do {
V_38:
V_34 = F_21 ( & V_6 -> V_9 , V_36 , V_33 ) ;
if ( F_22 ( V_34 >= V_36 ) ) {
if ( V_37 ) {
V_37 = false ;
V_36 = V_35 ;
V_33 = 0 ;
goto V_38;
}
return - 1 ;
}
V_33 = V_34 + 1 ;
} while ( F_10 ( V_34 , & V_6 -> V_9 ) );
return V_34 ;
}
static int F_23 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned int * V_39 )
{
unsigned int V_33 , V_35 ;
int V_14 , V_3 , V_34 ;
if ( ! F_18 ( V_19 , V_2 ) )
return - 1 ;
V_33 = V_35 = * V_39 ;
V_14 = F_24 ( V_2 , V_33 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_34 = F_20 ( & V_2 -> V_7 [ V_14 ] , F_25 ( V_2 , V_33 ) ) ;
if ( V_34 != - 1 ) {
V_34 += ( V_14 << V_2 -> V_40 ) ;
goto V_41;
}
V_33 = 0 ;
if ( ++ V_14 >= V_2 -> V_4 )
V_14 = 0 ;
}
* V_39 = 0 ;
return - 1 ;
V_41:
if ( V_34 == V_35 ) {
V_33 = V_34 + 1 ;
if ( V_33 >= V_2 -> V_10 - 1 )
V_33 = 0 ;
* V_39 = V_33 ;
}
return V_34 ;
}
static struct V_25 * F_26 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_25 * V_26 ;
int V_42 ;
if ( ! V_19 )
return & V_2 -> V_26 [ 0 ] ;
V_42 = F_6 ( & V_19 -> V_42 ) ;
V_26 = & V_2 -> V_26 [ V_42 ] ;
F_5 ( & V_19 -> V_42 ) ;
return V_26 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_1 * V_2 ,
struct V_18 * V_19 ,
unsigned int * V_33 )
{
struct V_25 * V_26 ;
F_28 ( V_27 ) ;
int V_34 ;
V_34 = F_23 ( V_19 , V_2 , V_33 ) ;
if ( V_34 != - 1 )
return V_34 ;
if ( ! ( V_44 -> V_45 & V_46 ) )
return - 1 ;
V_26 = F_26 ( V_2 , V_19 ) ;
do {
F_29 ( & V_26 -> V_27 , & V_27 , V_47 ) ;
V_34 = F_23 ( V_19 , V_2 , V_33 ) ;
if ( V_34 != - 1 )
break;
F_30 ( V_19 , false ) ;
V_34 = F_23 ( V_19 , V_2 , V_33 ) ;
if ( V_34 != - 1 )
break;
F_31 ( V_44 -> V_48 ) ;
F_32 () ;
V_44 -> V_48 = F_33 ( V_44 -> V_49 ) ;
V_44 -> V_19 = V_44 -> V_49 -> V_50 -> V_51 ( V_44 -> V_49 ,
V_44 -> V_48 -> V_52 ) ;
if ( V_44 -> V_53 ) {
V_2 = & V_44 -> V_19 -> V_12 -> V_28 ;
} else {
V_33 = & V_44 -> V_48 -> V_33 ;
V_19 = V_44 -> V_19 ;
V_2 = & V_19 -> V_12 -> V_13 ;
}
F_34 ( & V_26 -> V_27 , & V_27 ) ;
V_26 = F_26 ( V_2 , V_19 ) ;
} while ( 1 );
F_34 ( & V_26 -> V_27 , & V_27 ) ;
return V_34 ;
}
static unsigned int F_35 ( struct V_43 * V_44 )
{
int V_34 ;
V_34 = F_27 ( V_44 , & V_44 -> V_19 -> V_12 -> V_13 , V_44 -> V_19 ,
& V_44 -> V_48 -> V_33 ) ;
if ( V_34 >= 0 )
return V_34 + V_44 -> V_19 -> V_12 -> V_54 ;
return V_55 ;
}
static unsigned int F_36 ( struct V_43 * V_44 )
{
int V_34 , V_56 = 0 ;
if ( F_22 ( ! V_44 -> V_19 -> V_12 -> V_54 ) ) {
F_37 ( 1 ) ;
return V_55 ;
}
V_34 = F_27 ( V_44 , & V_44 -> V_19 -> V_12 -> V_28 , NULL , & V_56 ) ;
if ( V_34 < 0 )
return V_55 ;
return V_34 ;
}
unsigned int F_38 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_53 )
return F_35 ( V_44 ) ;
return F_36 ( V_44 ) ;
}
static struct V_25 * F_39 ( struct V_1 * V_2 )
{
int V_3 , V_24 ;
V_24 = F_6 ( & V_2 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 ] ;
if ( F_13 ( & V_26 -> V_27 ) ) {
int V_57 = F_6 ( & V_2 -> V_24 ) ;
if ( V_24 != V_57 )
F_7 ( & V_2 -> V_24 , V_57 , V_24 ) ;
return V_26 ;
}
V_24 = F_4 ( V_24 ) ;
}
return NULL ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_34 )
{
const int V_14 = F_24 ( V_2 , V_34 ) ;
struct V_25 * V_26 ;
int V_58 ;
F_41 ( F_25 ( V_2 , V_34 ) , & V_2 -> V_7 [ V_14 ] . V_9 ) ;
F_42 () ;
V_26 = F_39 ( V_2 ) ;
if ( ! V_26 )
return;
V_58 = F_43 ( & V_26 -> V_58 ) ;
if ( F_22 ( V_58 < 0 ) )
V_58 = F_44 ( & V_26 -> V_58 ) ;
if ( V_58 == 0 ) {
F_45 ( V_2 -> V_59 , & V_26 -> V_58 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_14 ( & V_26 -> V_27 ) ;
}
}
void F_46 ( struct V_18 * V_19 , unsigned int V_34 ,
unsigned int * V_33 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_34 >= V_12 -> V_54 ) {
const int V_60 = V_34 - V_12 -> V_54 ;
F_47 ( V_60 >= V_12 -> V_61 ) ;
F_40 ( & V_12 -> V_13 , V_60 ) ;
* V_33 = V_60 ;
} else {
F_47 ( V_34 >= V_12 -> V_54 ) ;
F_40 ( & V_12 -> V_28 , V_34 ) ;
}
}
static void F_48 ( struct V_18 * V_19 ,
struct V_1 * V_2 , unsigned int V_62 ,
T_2 * V_63 , void * V_44 , bool V_53 )
{
struct V_64 * V_65 ;
int V_66 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
for ( V_66 = F_49 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
V_66 < V_6 -> V_10 ;
V_66 = F_50 ( & V_6 -> V_9 , V_6 -> V_10 , V_66 + 1 ) ) {
V_65 = F_51 ( V_19 -> V_12 , V_62 + V_66 ) ;
if ( V_65 -> V_49 == V_19 -> V_67 )
V_63 ( V_19 , V_65 , V_44 , V_53 ) ;
}
V_62 += ( 1 << V_2 -> V_40 ) ;
}
}
void F_52 ( struct V_18 * V_19 , T_2 * V_63 ,
void * V_68 )
{
struct V_11 * V_12 = V_19 -> V_12 ;
if ( V_12 -> V_54 )
F_48 ( V_19 , & V_12 -> V_28 , 0 , V_63 , V_68 , true ) ;
F_48 ( V_19 , & V_12 -> V_13 , V_12 -> V_54 , V_63 , V_68 ,
false ) ;
}
static unsigned int F_53 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_69 ;
for ( V_3 = 0 , V_69 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
V_69 += F_54 ( & V_6 -> V_9 , V_6 -> V_10 ) ;
}
return V_2 -> V_10 - V_69 ;
}
static void F_55 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
unsigned int V_70 = 1U << V_2 -> V_40 ;
unsigned int V_71 = V_10 ;
if ( V_10 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_2 -> V_7 [ V_3 ] . V_10 = F_56 ( V_71 , V_70 ) ;
V_71 -= V_2 -> V_7 [ V_3 ] . V_10 ;
}
}
V_2 -> V_59 = V_72 ;
if ( V_2 -> V_59 > V_10 / V_15 )
V_2 -> V_59 = F_19 ( 1U , V_10 / V_15 ) ;
V_2 -> V_10 = V_10 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_10 ,
int V_73 , bool V_53 )
{
int V_3 ;
V_2 -> V_40 = F_58 ( V_74 ) ;
if ( V_10 ) {
unsigned int V_75 , V_70 ;
V_70 = ( 1 << V_2 -> V_40 ) ;
if ( V_10 >= 4 ) {
while ( V_70 * 4 > V_10 ) {
V_2 -> V_40 -- ;
V_70 = ( 1 << V_2 -> V_40 ) ;
}
}
V_75 = F_59 ( V_10 , V_70 ) / V_70 ;
V_2 -> V_7 = F_60 ( V_75 * sizeof( struct V_5 ) ,
V_76 , V_73 ) ;
if ( ! V_2 -> V_7 )
return - V_77 ;
V_2 -> V_4 = V_75 ;
}
V_2 -> V_26 = F_61 ( V_15 * sizeof( * V_2 -> V_26 ) , V_76 ) ;
if ( ! V_2 -> V_26 ) {
F_62 ( V_2 -> V_7 ) ;
return - V_77 ;
}
F_55 ( V_2 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ ) {
F_63 ( & V_2 -> V_26 [ V_3 ] . V_27 ) ;
F_64 ( & V_2 -> V_26 [ V_3 ] . V_58 , V_2 -> V_59 ) ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_7 ) ;
F_62 ( V_2 -> V_26 ) ;
}
static struct V_11 * F_66 ( struct V_11 * V_12 ,
int V_73 )
{
unsigned int V_10 = V_12 -> V_61 - V_12 -> V_54 ;
if ( F_57 ( & V_12 -> V_13 , V_10 , V_73 , false ) )
goto V_78;
if ( F_57 ( & V_12 -> V_28 , V_12 -> V_54 , V_73 , true ) )
goto V_78;
return V_12 ;
V_78:
F_65 ( & V_12 -> V_13 ) ;
F_62 ( V_12 ) ;
return NULL ;
}
struct V_11 * F_67 ( unsigned int V_79 ,
unsigned int V_80 , int V_73 )
{
struct V_11 * V_12 ;
if ( V_79 > V_81 ) {
F_68 ( L_1 ) ;
return NULL ;
}
V_12 = F_60 ( sizeof( * V_12 ) , V_76 , V_73 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_61 = V_79 ;
V_12 -> V_54 = V_80 ;
return F_66 ( V_12 , V_73 ) ;
}
void F_69 ( struct V_11 * V_12 )
{
F_65 ( & V_12 -> V_13 ) ;
F_65 ( & V_12 -> V_28 ) ;
F_62 ( V_12 ) ;
}
void F_70 ( struct V_11 * V_12 , unsigned int * V_34 )
{
unsigned int V_10 = V_12 -> V_61 - V_12 -> V_54 ;
* V_34 = F_71 () % V_10 ;
}
int F_72 ( struct V_11 * V_12 , unsigned int V_82 )
{
V_82 -= V_12 -> V_54 ;
if ( V_82 > V_12 -> V_61 )
return - V_83 ;
F_55 ( & V_12 -> V_13 , V_82 ) ;
F_12 ( V_12 , false ) ;
return 0 ;
}
T_3 F_73 ( struct V_64 * V_65 )
{
struct V_84 * V_49 = V_65 -> V_49 ;
struct V_18 * V_19 ;
int V_85 = 0 ;
if ( V_49 -> V_50 ) {
V_19 = V_49 -> V_50 -> V_51 ( V_49 , V_65 -> V_86 -> V_52 ) ;
V_85 = V_19 -> V_87 ;
}
return ( V_85 << V_88 ) |
( V_65 -> V_34 & V_89 ) ;
}
T_4 F_74 ( struct V_11 * V_12 , char * V_90 )
{
char * V_91 = V_90 ;
unsigned int free , V_92 ;
if ( ! V_12 )
return 0 ;
V_90 += sprintf ( V_90 , L_2
L_3 ,
V_12 -> V_61 , V_12 -> V_54 ,
V_12 -> V_13 . V_40 ) ;
free = F_53 ( & V_12 -> V_13 ) ;
V_92 = F_53 ( & V_12 -> V_28 ) ;
V_90 += sprintf ( V_90 , L_4 , free , V_92 ) ;
V_90 += sprintf ( V_90 , L_5 , F_6 ( & V_12 -> V_22 ) ) ;
return V_90 - V_91 ;
}
