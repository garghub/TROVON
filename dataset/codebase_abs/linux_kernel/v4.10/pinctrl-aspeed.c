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
F_12 ( L_2 , V_20 -> V_23 ,
V_20 -> V_24 , V_21 ? V_20 -> V_21 : V_20 -> V_25 ,
( V_22 & V_20 -> V_24 ) >> F_13 ( V_20 -> V_24 ) , V_22 ) ;
}
static bool F_14 ( const struct V_19 * V_20 ,
bool V_26 , struct V_27 * V_28 )
{
unsigned int V_29 ;
T_1 V_30 ;
if ( F_15 ( V_28 , V_20 -> V_23 , & V_29 ) < 0 )
return false ;
F_11 ( V_20 , V_26 , V_29 ) ;
V_30 = V_26 ? V_20 -> V_21 : V_20 -> V_25 ;
return ( ( V_29 & V_20 -> V_24 ) >> F_13 ( V_20 -> V_24 ) ) == V_30 ;
}
static bool F_16 ( const struct V_31 * V_32 ,
bool V_26 , struct V_27 * V_28 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_34 ; V_33 ++ ) {
const struct V_19 * V_20 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_14 ( V_20 , V_26 , V_28 ) )
return false ;
}
return true ;
}
static bool F_17 ( const struct V_31 * V_32 ,
bool V_21 , struct V_27 * V_28 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_34 ; V_33 ++ ) {
bool V_36 ;
const struct V_19 * V_20 = & V_32 -> V_35 [ V_33 ] ;
T_1 V_37 = V_21 ? V_20 -> V_21 : V_20 -> V_25 ;
if ( V_20 -> V_23 == V_38 || V_20 -> V_23 == V_39 )
continue;
V_36 = F_18 ( V_28 , V_20 -> V_23 , V_20 -> V_24 ,
V_37 << F_13 ( V_20 -> V_24 ) ) == 0 ;
if ( ! V_36 )
return V_36 ;
}
return F_16 ( V_32 , V_21 , V_28 ) ;
}
static bool F_19 ( const struct V_31 * V_32 ,
struct V_27 * V_28 )
{
if ( F_16 ( V_32 , true , V_28 ) )
return true ;
return F_17 ( V_32 , true , V_28 ) ;
}
static bool F_20 ( const struct V_31 * V_32 ,
struct V_27 * V_28 )
{
if ( ! F_16 ( V_32 , true , V_28 ) )
return true ;
return F_17 ( V_32 , false , V_28 ) ;
}
static bool F_21 ( const struct V_31 * * V_40 ,
struct V_27 * V_28 )
{
bool V_41 = true ;
if ( ! V_40 )
return true ;
while ( * V_40 ) {
bool V_36 ;
V_36 = F_20 ( * V_40 , V_28 ) ;
V_41 = V_41 && V_36 ;
V_40 ++ ;
}
return V_41 ;
}
static const struct V_31 * F_22 (
const struct V_31 * * V_40 , const char * V_8 )
{
while ( * V_40 ) {
if ( strcmp ( ( * V_40 ) -> V_16 , V_8 ) == 0 )
return * V_40 ;
V_40 ++ ;
}
return NULL ;
}
static char * F_23 ( const struct V_42 * V_43 ,
const char * (* F_24)(
const struct V_31 * ) )
{
char * V_44 = NULL ;
T_2 V_45 = 0 ;
const struct V_31 * * * V_46 , * * V_47 , * V_32 ;
V_46 = V_43 -> V_46 ;
while ( ( V_47 = * V_46 ) ) {
while ( ( V_32 = * V_47 ) ) {
const char * V_48 = F_24 ( V_32 ) ;
T_2 V_49 = strlen ( V_48 ) + 2 ;
char * V_50 ;
V_50 = F_25 ( V_44 , V_45 + V_49 + 1 , V_51 ) ;
if ( ! V_50 ) {
F_26 ( V_44 ) ;
return V_50 ;
}
V_44 = V_50 ;
V_44 [ V_45 ] = '\0' ;
V_45 += V_49 ;
strcat ( V_44 , V_48 ) ;
strcat ( V_44 , L_3 ) ;
V_47 ++ ;
}
V_46 ++ ;
}
if ( V_45 < 2 ) {
F_26 ( V_44 ) ;
return NULL ;
}
V_44 [ V_45 - 2 ] = '\0' ;
return V_44 ;
}
static const char * F_27 ( const struct V_31 * V_32 )
{
return V_32 -> V_16 ;
}
static char * F_28 ( const struct V_42 * V_43 )
{
return F_23 ( V_43 , F_27 ) ;
}
static const char * F_29 ( const struct V_31 * V_32 )
{
return V_32 -> signal ;
}
static char * F_30 ( const struct V_42 * V_43 )
{
return F_23 ( V_43 , F_29 ) ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_16 ,
unsigned int V_6 )
{
int V_33 ;
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_52 * V_53 = & V_4 -> V_7 [ V_6 ] ;
const struct V_54 * V_55 =
& V_4 -> V_17 [ V_16 ] ;
for ( V_33 = 0 ; V_33 < V_53 -> V_10 ; V_33 ++ ) {
int V_56 = V_53 -> V_9 [ V_33 ] ;
const struct V_42 * V_43 = V_4 -> V_9 [ V_56 ] . V_57 ;
const struct V_31 * V_32 = NULL ;
const struct V_31 * * V_47 ;
const struct V_31 * * * V_46 ;
if ( ! V_43 )
return - V_58 ;
V_46 = V_43 -> V_46 ;
if ( ! V_46 )
continue;
while ( ( V_47 = * V_46 ) ) {
V_32 = F_22 ( V_47 , V_55 -> V_8 ) ;
if ( V_32 )
break;
if ( ! F_21 ( V_47 , V_4 -> V_28 ) )
return - V_59 ;
V_46 ++ ;
}
if ( ! V_32 ) {
char * V_17 = F_28 ( V_43 ) ;
char * V_60 = F_30 ( V_43 ) ;
F_32 ( L_4 ,
V_55 -> V_8 , V_43 -> V_8 , V_56 , V_60 ,
V_17 ) ;
F_26 ( V_60 ) ;
F_26 ( V_17 ) ;
return - V_61 ;
}
if ( ! F_19 ( V_32 , V_4 -> V_28 ) )
return - V_59 ;
}
return 0 ;
}
static bool F_33 ( const struct V_31 * V_32 )
{
return strncmp ( V_32 -> signal , L_5 , 4 ) == 0 ;
}
static bool F_34 ( const struct V_31 * * V_40 )
{
if ( ! V_40 )
return false ;
while ( * V_40 ) {
if ( F_33 ( * V_40 ) )
return true ;
V_40 ++ ;
}
return false ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
unsigned int V_13 )
{
const struct V_3 * V_4 =
F_2 ( V_2 ) ;
const struct V_42 * V_43 = V_4 -> V_9 [ V_13 ] . V_57 ;
const struct V_31 * * * V_46 , * * V_47 , * V_32 ;
if ( ! V_43 )
return - V_58 ;
V_46 = V_43 -> V_46 ;
if ( ! V_46 )
return - V_61 ;
while ( ( V_47 = * V_46 ) ) {
if ( F_34 ( V_47 ) )
break;
if ( ! F_21 ( V_47 , V_4 -> V_28 ) )
return - V_59 ;
V_46 ++ ;
}
if ( ! V_47 ) {
char * V_60 = F_30 ( V_43 ) ;
F_32 ( L_6 ,
V_43 -> V_8 , V_13 , V_60 ) ;
F_26 ( V_60 ) ;
return - V_61 ;
}
V_32 = * V_47 ;
if ( ! V_32 )
return 0 ;
if ( ! F_19 ( V_32 , V_4 -> V_28 ) )
return - V_59 ;
return 0 ;
}
int F_36 ( struct V_64 * V_65 ,
struct V_66 * V_43 ,
struct V_3 * V_4 )
{
struct V_67 * V_68 ;
struct V_1 * V_69 ;
V_68 = V_65 -> V_14 . V_68 ;
if ( ! V_68 ) {
F_37 ( & V_65 -> V_14 , L_7 ) ;
return - V_70 ;
}
V_4 -> V_28 = F_38 ( V_68 -> V_71 ) ;
if ( F_39 ( V_4 -> V_28 ) ) {
F_37 ( & V_65 -> V_14 , L_8 ) ;
return F_40 ( V_4 -> V_28 ) ;
}
V_69 = F_41 ( V_43 , & V_65 -> V_14 , V_4 ) ;
if ( F_39 ( V_69 ) ) {
F_37 ( & V_65 -> V_14 , L_9 ) ;
return F_40 ( V_69 ) ;
}
F_42 ( V_65 , V_4 ) ;
return 0 ;
}
