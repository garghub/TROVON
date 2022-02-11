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
if ( V_20 -> V_24 == V_43 && V_20 -> V_25 == V_44 ) {
unsigned int V_46 ;
V_31 = F_15 ( V_37 [ V_43 ] ,
V_47 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( 0x04 == ( V_46 >> 24 ) ) {
T_1 V_48 = ~ V_42 & V_20 -> V_26 ;
if ( V_48 ) {
V_31 = F_19 ( V_37 [ V_20 -> V_24 ] ,
V_47 , V_48 ) ;
if ( V_31 < 0 )
return V_31 ;
}
}
}
V_31 = F_20 ( V_37 [ V_20 -> V_24 ] , V_20 -> V_25 ,
V_20 -> V_26 , V_42 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_16 ( V_36 , V_21 , V_37 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_31 )
return - V_49 ;
return 0 ;
}
static int F_21 ( const struct V_35 * V_36 ,
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
static int F_22 ( const struct V_35 * V_36 ,
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
static int F_23 ( const struct V_35 * * V_50 ,
struct V_29 * const * V_37 )
{
int V_31 = 0 ;
if ( ! V_50 )
return true ;
while ( * V_50 && ! V_31 ) {
V_31 = F_22 ( * V_50 , V_37 ) ;
V_50 ++ ;
}
return V_31 ;
}
static const struct V_35 * F_24 (
const struct V_35 * * V_50 , const char * V_8 )
{
while ( * V_50 ) {
if ( strcmp ( ( * V_50 ) -> V_16 , V_8 ) == 0 )
return * V_50 ;
V_50 ++ ;
}
return NULL ;
}
static char * F_25 ( const struct V_51 * V_52 ,
const char * (* F_26)(
const struct V_35 * ) )
{
char * V_53 = NULL ;
T_2 V_54 = 0 ;
const struct V_35 * * * V_55 , * * V_56 , * V_36 ;
V_55 = V_52 -> V_55 ;
while ( ( V_56 = * V_55 ) ) {
while ( ( V_36 = * V_56 ) ) {
const char * V_57 = F_26 ( V_36 ) ;
T_2 V_58 = strlen ( V_57 ) + 2 ;
char * V_59 ;
V_59 = F_27 ( V_53 , V_54 + V_58 + 1 , V_60 ) ;
if ( ! V_59 ) {
F_28 ( V_53 ) ;
return V_59 ;
}
V_53 = V_59 ;
V_53 [ V_54 ] = '\0' ;
V_54 += V_58 ;
strcat ( V_53 , V_57 ) ;
strcat ( V_53 , L_3 ) ;
V_56 ++ ;
}
V_55 ++ ;
}
if ( V_54 < 2 ) {
F_28 ( V_53 ) ;
return NULL ;
}
V_53 [ V_54 - 2 ] = '\0' ;
return V_53 ;
}
static const char * F_29 ( const struct V_35 * V_36 )
{
return V_36 -> V_16 ;
}
static char * F_30 ( const struct V_51 * V_52 )
{
return F_25 ( V_52 , F_29 ) ;
}
static const char * F_31 ( const struct V_35 * V_36 )
{
return V_36 -> signal ;
}
static char * F_32 ( const struct V_51 * V_52 )
{
return F_25 ( V_52 , F_31 ) ;
}
int F_33 ( struct V_1 * V_2 , unsigned int V_16 ,
unsigned int V_6 )
{
int V_38 ;
int V_31 ;
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_61 * V_62 = & V_4 -> V_7 [ V_6 ] ;
const struct V_63 * V_64 =
& V_4 -> V_17 [ V_16 ] ;
for ( V_38 = 0 ; V_38 < V_62 -> V_10 ; V_38 ++ ) {
int V_65 = V_62 -> V_9 [ V_38 ] ;
const struct V_51 * V_52 = V_4 -> V_9 [ V_65 ] . V_66 ;
const struct V_35 * V_36 = NULL ;
const struct V_35 * * V_56 ;
const struct V_35 * * * V_55 ;
F_12 ( L_4 , V_65 , V_64 -> V_8 ) ;
if ( ! V_52 )
return - V_67 ;
V_55 = V_52 -> V_55 ;
if ( ! V_55 )
continue;
while ( ( V_56 = * V_55 ) ) {
V_36 = F_24 ( V_56 , V_64 -> V_8 ) ;
if ( V_36 )
break;
V_31 = F_23 ( V_56 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
V_55 ++ ;
}
if ( ! V_36 ) {
char * V_17 = F_30 ( V_52 ) ;
char * V_68 = F_32 ( V_52 ) ;
F_34 ( L_5 ,
V_64 -> V_8 , V_52 -> V_8 , V_65 , V_68 ,
V_17 ) ;
F_28 ( V_68 ) ;
F_28 ( V_17 ) ;
return - V_69 ;
}
V_31 = F_21 ( V_36 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static bool F_35 ( const struct V_35 * V_36 )
{
return strncmp ( V_36 -> signal , L_6 , 4 ) == 0 ;
}
static bool F_36 ( const struct V_35 * * V_50 )
{
if ( ! V_50 )
return false ;
while ( * V_50 ) {
if ( F_35 ( * V_50 ) )
return true ;
V_50 ++ ;
}
return false ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
unsigned int V_13 )
{
int V_31 ;
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_51 * V_52 = V_4 -> V_9 [ V_13 ] . V_66 ;
const struct V_35 * * * V_55 , * * V_56 , * V_36 ;
if ( ! V_52 )
return - V_67 ;
V_55 = V_52 -> V_55 ;
if ( ! V_55 )
return - V_69 ;
while ( ( V_56 = * V_55 ) ) {
if ( F_36 ( V_56 ) )
break;
V_31 = F_23 ( V_56 , V_4 -> V_37 ) ;
if ( V_31 )
return V_31 ;
V_55 ++ ;
}
if ( ! V_56 ) {
char * V_68 = F_32 ( V_52 ) ;
F_34 ( L_7 ,
V_52 -> V_8 , V_13 , V_68 ) ;
F_28 ( V_68 ) ;
return - V_69 ;
}
V_36 = * V_56 ;
if ( ! V_36 )
return 0 ;
return F_21 ( V_36 , V_4 -> V_37 ) ;
}
int F_38 ( struct V_72 * V_73 ,
struct V_74 * V_52 ,
struct V_3 * V_4 )
{
struct V_75 * V_76 ;
struct V_1 * V_77 ;
V_76 = V_73 -> V_14 . V_76 ;
if ( ! V_76 ) {
F_39 ( & V_73 -> V_14 , L_8 ) ;
return - V_34 ;
}
V_4 -> V_37 [ V_43 ] = F_40 ( V_76 -> V_78 ) ;
if ( F_41 ( V_4 -> V_37 [ V_43 ] ) ) {
F_39 ( & V_73 -> V_14 , L_9 ) ;
return F_42 ( V_4 -> V_37 [ V_43 ] ) ;
}
V_77 = F_43 ( V_52 , & V_73 -> V_14 , V_4 ) ;
if ( F_41 ( V_77 ) ) {
F_39 ( & V_73 -> V_14 , L_10 ) ;
return F_42 ( V_77 ) ;
}
F_44 ( V_73 , V_4 ) ;
return 0 ;
}
static inline bool F_45 ( unsigned int V_13 ,
const struct V_79 * V_80 )
{
return V_13 >= V_80 -> V_9 [ 0 ] && V_13 <= V_80 -> V_9 [ 1 ] ;
}
static inline const struct V_79 * F_46 (
const struct V_3 * V_4 ,
unsigned int V_13 ,
enum V_81 V_82 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_83 ; V_38 ++ ) {
if ( V_82 == V_4 -> V_84 [ V_38 ] . V_82 &&
F_45 ( V_13 , & V_4 -> V_84 [ V_38 ] ) )
return & V_4 -> V_84 [ V_38 ] ;
}
return NULL ;
}
static const struct V_85 * F_47 (
enum V_81 V_82 ,
enum V_86 type ,
T_3 V_48 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_48 ( V_87 ) ; V_38 ++ ) {
const struct V_85 * V_88 ;
bool V_89 ;
V_88 = & V_87 [ V_38 ] ;
switch ( type ) {
case V_90 :
V_89 = ( V_88 -> V_91 == - 1 || V_88 -> V_91 == V_48 ) ;
break;
case V_92 :
V_89 = ( V_88 -> V_42 == V_48 ) ;
break;
}
if ( V_82 == V_88 -> V_82 && V_89 )
return V_88 ;
}
return NULL ;
}
int F_49 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned long * V_80 )
{
const enum V_81 V_82 = F_50 ( * V_80 ) ;
const struct V_85 * V_93 ;
const struct V_3 * V_4 ;
const struct V_79 * V_94 ;
unsigned int V_42 ;
int V_95 = 0 ;
T_1 V_91 ;
V_4 = F_2 ( V_2 ) ;
V_94 = F_46 ( V_4 , V_13 , V_82 ) ;
if ( ! V_94 )
return - V_96 ;
V_95 = F_15 ( V_4 -> V_37 [ V_43 ] , V_94 -> V_25 , & V_42 ) ;
if ( V_95 < 0 )
return V_95 ;
V_93 = F_47 ( V_82 , V_92 ,
( V_42 & F_18 ( V_94 -> V_97 ) ) >> V_94 -> V_97 ) ;
if ( ! V_93 )
return - V_67 ;
if ( V_82 == V_98 )
V_91 = ( T_1 ) V_93 -> V_91 ;
else if ( V_82 == V_99 )
V_91 = ! ! V_93 -> V_91 ;
else
V_91 = 1 ;
if ( ! V_91 )
return - V_67 ;
* V_80 = F_51 ( V_82 , V_91 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned long * V_84 , unsigned int V_100 )
{
const struct V_3 * V_4 ;
unsigned int V_38 ;
int V_95 = 0 ;
V_4 = F_2 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < V_100 ; V_38 ++ ) {
const struct V_85 * V_93 ;
const struct V_79 * V_94 ;
enum V_81 V_82 ;
unsigned int V_42 ;
T_1 V_91 ;
V_82 = F_50 ( V_84 [ V_38 ] ) ;
V_91 = F_53 ( V_84 [ V_38 ] ) ;
V_94 = F_46 ( V_4 , V_13 , V_82 ) ;
if ( ! V_94 )
return - V_96 ;
V_93 = F_47 ( V_82 , V_90 , V_91 ) ;
if ( F_54 ( F_55 ( ! V_93 ) ) )
return - V_67 ;
V_42 = V_93 -> V_42 << V_94 -> V_97 ;
V_95 = F_20 ( V_4 -> V_37 [ V_43 ] , V_94 -> V_25 ,
F_18 ( V_94 -> V_97 ) , V_42 ) ;
if ( V_95 < 0 )
return V_95 ;
F_12 ( L_11 ,
V_101 , V_94 -> V_25 , V_94 -> V_97 , V_93 -> V_42 ,
V_82 , V_91 , V_13 ) ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
unsigned int V_102 ,
unsigned long * V_80 )
{
const unsigned int * V_9 ;
unsigned int V_10 ;
int V_95 ;
V_95 = F_4 ( V_2 , V_102 , & V_9 , & V_10 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! V_10 )
return - V_34 ;
V_95 = F_49 ( V_2 , V_9 [ 0 ] , V_80 ) ;
return V_95 ;
}
int F_57 ( struct V_1 * V_2 ,
unsigned int V_102 ,
unsigned long * V_84 ,
unsigned int V_100 )
{
const unsigned int * V_9 ;
unsigned int V_10 ;
int V_95 ;
int V_38 ;
F_12 ( L_12 ,
V_101 , V_102 ) ;
V_95 = F_4 ( V_2 , V_102 , & V_9 , & V_10 ) ;
if ( V_95 < 0 )
return V_95 ;
for ( V_38 = 0 ; V_38 < V_10 ; V_38 ++ ) {
V_95 = F_52 ( V_2 , V_9 [ V_38 ] , V_84 ,
V_100 ) ;
if ( V_95 < 0 )
return V_95 ;
}
return 0 ;
}
