int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
const char * F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
int F_4 ( struct V_1 * V_2 ,
unsigned int V_6 , const unsigned int * * V_9 ,
unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = & V_4 -> V_7 [ V_6 ] . V_9 [ 0 ] ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned int V_13 )
{
F_6 ( V_12 , L_1 , F_7 ( V_2 -> V_14 ) ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_15 ;
}
const char * F_9 ( struct V_1 * V_2 ,
unsigned int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 [ V_16 ] . V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned int V_16 ,
const char * const * * V_7 ,
unsigned int * const V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_7 = V_4 -> V_17 [ V_16 ] . V_7 ;
* V_18 = V_4 -> V_17 [ V_16 ] . V_5 ;
return 0 ;
}
static inline void F_11 (
const struct V_19 * V_20 , bool V_21 , T_1 V_22 )
{
F_12 ( L_2 ,
V_23 [ V_20 -> V_24 ] , V_20 -> V_25 ,
V_20 -> V_26 , V_21 ? V_20 -> V_21 : V_20 -> V_27 ,
( V_22 & V_20 -> V_26 ) >> F_13 ( V_20 -> V_26 ) , V_22 ) ;
}
static int F_14 ( const struct V_19 * V_20 ,
bool V_28 , struct V_29 * V_30 )
{
int V_31 ;
unsigned int V_32 ;
T_1 V_33 ;
if ( ! V_30 )
return - V_34 ;
V_31 = F_15 ( V_30 , V_20 -> V_25 , & V_32 ) ;
if ( V_31 )
return V_31 ;
F_11 ( V_20 , V_28 , V_32 ) ;
V_33 = V_28 ? V_20 -> V_21 : V_20 -> V_27 ;
return ( ( V_32 & V_20 -> V_26 ) >> F_13 ( V_20 -> V_26 ) ) == V_33 ;
}
static int F_16 ( const struct V_35 * V_36 ,
bool V_28 , struct V_29 * const * V_37 )
{
int V_38 ;
int V_31 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
const struct V_19 * V_20 = & V_36 -> V_40 [ V_38 ] ;
V_31 = F_14 ( V_20 , V_28 , V_37 [ V_20 -> V_24 ] ) ;
if ( V_31 <= 0 )
return V_31 ;
}
return 1 ;
}
static int F_17 ( const struct V_35 * V_36 ,
bool V_21 , struct V_29 * const * V_37 )
{
int V_31 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
const struct V_19 * V_20 = & V_36 -> V_40 [ V_38 ] ;
T_1 V_41 = V_21 ? V_20 -> V_21 : V_20 -> V_27 ;
T_1 V_42 = ( V_41 << F_13 ( V_20 -> V_26 ) ) ;
if ( ! V_37 [ V_20 -> V_24 ] )
return - V_34 ;
if ( V_20 -> V_24 == V_43 && V_20 -> V_25 == V_44 &&
! ( V_20 -> V_26 & ( F_18 ( 21 ) | F_18 ( 22 ) ) ) )
continue;
if ( V_20 -> V_24 == V_43 && V_20 -> V_25 == V_45 )
continue;
V_31 = F_19 ( V_37 [ V_20 -> V_24 ] , V_20 -> V_25 ,
V_20 -> V_26 , V_42 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_16 ( V_36 , V_21 , V_37 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_31 )
return - V_46 ;
return 0 ;
}
static int F_20 ( const struct V_35 * V_36 ,
struct V_29 * const * V_37 )
{
int V_31 ;
V_31 = F_16 ( V_36 , true , V_37 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_31 )
return F_17 ( V_36 , true , V_37 ) ;
return 0 ;
}
static int F_21 ( const struct V_35 * V_36 ,
struct V_29 * const * V_37 )
{
int V_31 ;
V_31 = F_16 ( V_36 , true , V_37 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 )
return F_17 ( V_36 , false , V_37 ) ;
return 0 ;
}
static int F_22 ( const struct V_35 * * V_47 ,
struct V_29 * const * V_37 )
{
int V_31 = 0 ;
if ( ! V_47 )
return true ;
while ( * V_47 && ! V_31 ) {
V_31 = F_21 ( * V_47 , V_37 ) ;
V_47 ++ ;
}
return V_31 ;
}
static const struct V_35 * F_23 (
const struct V_35 * * V_47 , const char * V_8 )
{
while ( * V_47 ) {
if ( strcmp ( ( * V_47 ) -> V_16 , V_8 ) == 0 )
return * V_47 ;
V_47 ++ ;
}
return NULL ;
}
static char * F_24 ( const struct V_48 * V_49 ,
const char * (* F_25)(
const struct V_35 * ) )
{
char * V_50 = NULL ;
T_2 V_51 = 0 ;
const struct V_35 * * * V_52 , * * V_53 , * V_36 ;
V_52 = V_49 -> V_52 ;
while ( ( V_53 = * V_52 ) ) {
while ( ( V_36 = * V_53 ) ) {
const char * V_54 = F_25 ( V_36 ) ;
T_2 V_55 = strlen ( V_54 ) + 2 ;
char * V_56 ;
V_56 = F_26 ( V_50 , V_51 + V_55 + 1 , V_57 ) ;
if ( ! V_56 ) {
F_27 ( V_50 ) ;
return V_56 ;
}
V_50 = V_56 ;
V_50 [ V_51 ] = '\0' ;
V_51 += V_55 ;
strcat ( V_50 , V_54 ) ;
strcat ( V_50 , L_3 ) ;
V_53 ++ ;
}
V_52 ++ ;
}
if ( V_51 < 2 ) {
F_27 ( V_50 ) ;
return NULL ;
}
V_50 [ V_51 - 2 ] = '\0' ;
return V_50 ;
}
static const char * F_28 ( const struct V_35 * V_36 )
{
return V_36 -> V_16 ;
}
static char * F_29 ( const struct V_48 * V_49 )
{
return F_24 ( V_49 , F_28 ) ;
}
static const char * F_30 ( const struct V_35 * V_36 )
{
return V_36 -> signal ;
}
static char * F_31 ( const struct V_48 * V_49 )
{
return F_24 ( V_49 , F_30 ) ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_16 ,
unsigned int V_6 )
{
int V_38 ;
int V_31 ;
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_58 * V_59 = & V_4 -> V_7 [ V_6 ] ;
const struct V_60 * V_61 =
& V_4 -> V_17 [ V_16 ] ;
for ( V_38 = 0 ; V_38 < V_59 -> V_10 ; V_38 ++ ) {
int V_62 = V_59 -> V_9 [ V_38 ] ;
const struct V_48 * V_49 = V_4 -> V_9 [ V_62 ] . V_63 ;
const struct V_35 * V_36 = NULL ;
const struct V_35 * * V_53 ;
const struct V_35 * * * V_52 ;
F_12 ( L_4 , V_62 , V_61 -> V_8 ) ;
if ( ! V_49 )
return - V_64 ;
V_52 = V_49 -> V_52 ;
if ( ! V_52 )
continue;
while ( ( V_53 = * V_52 ) ) {
V_36 = F_23 ( V_53 , V_61 -> V_8 ) ;
if ( V_36 )
break;
V_31 = F_22 ( V_53 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
V_52 ++ ;
}
if ( ! V_36 ) {
char * V_17 = F_29 ( V_49 ) ;
char * V_65 = F_31 ( V_49 ) ;
F_33 ( L_5 ,
V_61 -> V_8 , V_49 -> V_8 , V_62 , V_65 ,
V_17 ) ;
F_27 ( V_65 ) ;
F_27 ( V_17 ) ;
return - V_66 ;
}
V_31 = F_20 ( V_36 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_34 ( const struct V_35 * V_36 )
{
return strncmp ( V_36 -> signal , L_6 , 4 ) == 0 ;
}
static bool F_35 ( const struct V_35 * * V_47 )
{
if ( ! V_47 )
return false ;
while ( * V_47 ) {
if ( F_34 ( * V_47 ) )
return true ;
V_47 ++ ;
}
return false ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
unsigned int V_13 )
{
int V_31 ;
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_48 * V_49 = V_4 -> V_9 [ V_13 ] . V_63 ;
const struct V_35 * * * V_52 , * * V_53 , * V_36 ;
if ( ! V_49 )
return - V_64 ;
V_52 = V_49 -> V_52 ;
if ( ! V_52 )
return - V_66 ;
while ( ( V_53 = * V_52 ) ) {
if ( F_35 ( V_53 ) )
break;
V_31 = F_22 ( V_53 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
V_52 ++ ;
}
if ( ! V_53 ) {
char * V_65 = F_31 ( V_49 ) ;
F_33 ( L_7 ,
V_49 -> V_8 , V_13 , V_65 ) ;
F_27 ( V_65 ) ;
return - V_66 ;
}
V_36 = * V_53 ;
if ( ! V_36 )
return 0 ;
return F_20 ( V_36 , V_4 -> V_37 ) ;
}
int F_37 ( struct V_69 * V_70 ,
struct V_71 * V_49 ,
struct V_3 * V_4 )
{
struct V_72 * V_73 ;
struct V_1 * V_74 ;
V_73 = V_70 -> V_14 . V_73 ;
if ( ! V_73 ) {
F_38 ( & V_70 -> V_14 , L_8 ) ;
return - V_34 ;
}
V_4 -> V_37 [ V_43 ] = F_39 ( V_73 -> V_75 ) ;
if ( F_40 ( V_4 -> V_37 [ V_43 ] ) ) {
F_38 ( & V_70 -> V_14 , L_9 ) ;
return F_41 ( V_4 -> V_37 [ V_43 ] ) ;
}
V_74 = F_42 ( V_49 , & V_70 -> V_14 , V_4 ) ;
if ( F_40 ( V_74 ) ) {
F_38 ( & V_70 -> V_14 , L_10 ) ;
return F_41 ( V_74 ) ;
}
F_43 ( V_70 , V_4 ) ;
return 0 ;
}
static inline bool F_44 ( unsigned int V_13 ,
const struct V_76 * V_77 )
{
return V_13 >= V_77 -> V_9 [ 0 ] && V_13 <= V_77 -> V_9 [ 1 ] ;
}
static inline const struct V_76 * F_45 (
const struct V_3 * V_4 ,
unsigned int V_13 ,
enum V_78 V_79 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_80 ; V_38 ++ ) {
if ( V_79 == V_4 -> V_81 [ V_38 ] . V_79 &&
F_44 ( V_13 , & V_4 -> V_81 [ V_38 ] ) )
return & V_4 -> V_81 [ V_38 ] ;
}
return NULL ;
}
static const struct V_82 * F_46 (
enum V_78 V_79 ,
enum V_83 type ,
T_3 V_84 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_47 ( V_85 ) ; V_38 ++ ) {
const struct V_82 * V_86 ;
bool V_87 ;
V_86 = & V_85 [ V_38 ] ;
switch ( type ) {
case V_88 :
V_87 = ( V_86 -> V_89 == - 1 || V_86 -> V_89 == V_84 ) ;
break;
case V_90 :
V_87 = ( V_86 -> V_42 == V_84 ) ;
break;
}
if ( V_79 == V_86 -> V_79 && V_87 )
return V_86 ;
}
return NULL ;
}
int F_48 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned long * V_77 )
{
const enum V_78 V_79 = F_49 ( * V_77 ) ;
const struct V_82 * V_91 ;
const struct V_3 * V_4 ;
const struct V_76 * V_92 ;
unsigned int V_42 ;
int V_93 = 0 ;
T_1 V_89 ;
V_4 = F_2 ( V_2 ) ;
V_92 = F_45 ( V_4 , V_13 , V_79 ) ;
if ( ! V_92 )
return - V_94 ;
V_93 = F_15 ( V_4 -> V_37 [ V_43 ] , V_92 -> V_25 , & V_42 ) ;
if ( V_93 < 0 )
return V_93 ;
V_91 = F_46 ( V_79 , V_90 ,
( V_42 & F_18 ( V_92 -> V_95 ) ) >> V_92 -> V_95 ) ;
if ( ! V_91 )
return - V_64 ;
if ( V_79 == V_96 )
V_89 = ( T_1 ) V_91 -> V_89 ;
else if ( V_79 == V_97 )
V_89 = ! ! V_91 -> V_89 ;
else
V_89 = 1 ;
if ( ! V_89 )
return - V_64 ;
* V_77 = F_50 ( V_79 , V_89 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned long * V_81 , unsigned int V_98 )
{
const struct V_3 * V_4 ;
unsigned int V_38 ;
int V_93 = 0 ;
V_4 = F_2 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < V_98 ; V_38 ++ ) {
const struct V_82 * V_91 ;
const struct V_76 * V_92 ;
enum V_78 V_79 ;
unsigned int V_42 ;
T_1 V_89 ;
V_79 = F_49 ( V_81 [ V_38 ] ) ;
V_89 = F_52 ( V_81 [ V_38 ] ) ;
V_92 = F_45 ( V_4 , V_13 , V_79 ) ;
if ( ! V_92 )
return - V_94 ;
V_91 = F_46 ( V_79 , V_88 , V_89 ) ;
if ( F_53 ( F_54 ( ! V_91 ) ) )
return - V_64 ;
V_42 = V_91 -> V_42 << V_92 -> V_95 ;
V_93 = F_19 ( V_4 -> V_37 [ V_43 ] , V_92 -> V_25 ,
F_18 ( V_92 -> V_95 ) , V_42 ) ;
if ( V_93 < 0 )
return V_93 ;
F_12 ( L_11 ,
V_99 , V_92 -> V_25 , V_92 -> V_95 , V_91 -> V_42 ,
V_79 , V_89 , V_13 ) ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
unsigned int V_100 ,
unsigned long * V_77 )
{
const unsigned int * V_9 ;
unsigned int V_10 ;
int V_93 ;
V_93 = F_4 ( V_2 , V_100 , & V_9 , & V_10 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! V_10 )
return - V_34 ;
V_93 = F_48 ( V_2 , V_9 [ 0 ] , V_77 ) ;
return V_93 ;
}
int F_56 ( struct V_1 * V_2 ,
unsigned int V_100 ,
unsigned long * V_81 ,
unsigned int V_98 )
{
const unsigned int * V_9 ;
unsigned int V_10 ;
int V_93 ;
int V_38 ;
F_12 ( L_12 ,
V_99 , V_100 ) ;
V_93 = F_4 ( V_2 , V_100 , & V_9 , & V_10 ) ;
if ( V_93 < 0 )
return V_93 ;
for ( V_38 = 0 ; V_38 < V_10 ; V_38 ++ ) {
V_93 = F_51 ( V_2 , V_9 [ V_38 ] , V_81 ,
V_98 ) ;
if ( V_93 < 0 )
return V_93 ;
}
return 0 ;
}
