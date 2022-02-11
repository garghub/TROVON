static inline struct V_1 * F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
return F_2 ( V_2 ) ;
}
static inline struct V_1 * F_3 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
if ( -- ( * V_3 ) == 0 )
return NULL ;
return V_2 + 1 ;
}
int F_4 ( struct V_4 * V_5 ,
struct V_1 V_2 [] ,
unsigned int V_6 ,
unsigned int V_7 ,
void * V_8 ,
T_1 V_9 )
{
struct V_1 * V_10 [ 2 ] ;
V_10 [ 0 ] = V_2 ;
V_10 [ 1 ] = V_2 + V_6 ;
return F_5 ( V_5 , V_10 , F_3 ,
V_6 , V_7 , V_6 ? 1 : 0 , V_7 ? 1 : 0 , V_8 , V_9 ) ;
}
int F_6 ( struct V_4 * V_5 ,
struct V_1 * V_10 [] ,
unsigned int V_11 ,
unsigned int V_12 ,
void * V_8 ,
T_1 V_9 )
{
unsigned int V_13 , V_14 , V_15 ;
for ( V_13 = V_14 = V_15 = 0 ; V_13 < V_11 ; V_13 ++ ) {
struct V_1 * V_2 ;
for ( V_2 = V_10 [ V_13 ] ; V_2 ; V_2 = F_2 ( V_2 ) )
V_14 ++ ;
}
for (; V_13 < V_11 + V_12 ; V_13 ++ ) {
struct V_1 * V_2 ;
for ( V_2 = V_10 [ V_13 ] ; V_2 ; V_2 = F_2 ( V_2 ) )
V_15 ++ ;
}
return F_5 ( V_5 , V_10 , F_1 ,
V_14 , V_15 , V_11 , V_12 , V_8 , V_9 ) ;
}
int F_7 ( struct V_4 * V_16 ,
struct V_1 V_2 [] , unsigned int V_17 ,
void * V_8 ,
T_1 V_9 )
{
return F_5 ( V_16 , & V_2 , F_3 , V_17 , 0 , 1 , 0 , V_8 , V_9 ) ;
}
int F_8 ( struct V_4 * V_16 ,
struct V_1 V_2 [] , unsigned int V_17 ,
void * V_8 ,
T_1 V_9 )
{
return F_5 ( V_16 , & V_2 , F_3 , 0 , V_17 , 0 , 1 , V_8 , V_9 ) ;
}
bool F_9 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
T_2 V_19 , V_20 ;
bool V_21 ;
F_11 ( V_16 ) ;
F_12 ( V_16 -> V_22 ) ;
V_20 = V_16 -> V_23 . V_24 -> V_25 - V_16 -> V_26 ;
V_19 = V_16 -> V_23 . V_24 -> V_25 ;
V_16 -> V_26 = 0 ;
#ifdef F_13
if ( V_16 -> V_27 ) {
F_14 ( F_15 ( F_16 ( F_17 () ,
V_16 -> V_28 ) ) > 100 ) ;
}
V_16 -> V_27 = false ;
#endif
if ( V_16 -> V_29 ) {
V_21 = F_18 ( F_19 ( & V_16 -> V_23 ) ,
V_19 , V_20 ) ;
} else {
V_21 = ! ( V_16 -> V_23 . V_30 -> V_31 & V_32 ) ;
}
F_20 ( V_16 ) ;
return V_21 ;
}
void F_21 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
V_16 -> V_33 ( V_5 ) ;
}
void F_22 ( struct V_4 * V_16 )
{
if ( F_9 ( V_16 ) )
F_21 ( V_16 ) ;
}
static void F_23 ( struct V_18 * V_16 , unsigned int V_34 )
{
unsigned int V_13 ;
V_16 -> V_8 [ V_34 ] = NULL ;
V_13 = V_34 ;
if ( V_16 -> V_23 . V_35 [ V_13 ] . V_31 & V_36 )
F_24 ( F_25 ( V_16 -> V_23 . V_35 [ V_13 ] . V_37 ) ) ;
while ( V_16 -> V_23 . V_35 [ V_13 ] . V_31 & V_38 ) {
V_13 = V_16 -> V_23 . V_35 [ V_13 ] . V_39 ;
V_16 -> V_16 . V_40 ++ ;
}
V_16 -> V_23 . V_35 [ V_13 ] . V_39 = V_16 -> V_41 ;
V_16 -> V_41 = V_34 ;
V_16 -> V_16 . V_40 ++ ;
}
static inline bool F_26 ( const struct V_18 * V_16 )
{
return V_16 -> V_42 != V_16 -> V_23 . V_30 -> V_25 ;
}
void * F_27 ( struct V_4 * V_5 , unsigned int * V_43 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
void * V_44 ;
unsigned int V_13 ;
T_2 V_45 ;
F_11 ( V_16 ) ;
if ( F_28 ( V_16 -> V_46 ) ) {
F_20 ( V_16 ) ;
return NULL ;
}
if ( ! F_26 ( V_16 ) ) {
F_29 ( L_1 ) ;
F_20 ( V_16 ) ;
return NULL ;
}
F_30 ( V_16 -> V_22 ) ;
V_45 = ( V_16 -> V_42 & ( V_16 -> V_23 . V_17 - 1 ) ) ;
V_13 = V_16 -> V_23 . V_30 -> V_47 [ V_45 ] . V_48 ;
* V_43 = V_16 -> V_23 . V_30 -> V_47 [ V_45 ] . V_43 ;
if ( F_28 ( V_13 >= V_16 -> V_23 . V_17 ) ) {
F_31 ( V_16 , L_2 , V_13 ) ;
return NULL ;
}
if ( F_28 ( ! V_16 -> V_8 [ V_13 ] ) ) {
F_31 ( V_16 , L_3 , V_13 ) ;
return NULL ;
}
V_44 = V_16 -> V_8 [ V_13 ] ;
F_23 ( V_16 , V_13 ) ;
V_16 -> V_42 ++ ;
if ( ! ( V_16 -> V_23 . V_24 -> V_31 & V_49 ) ) {
F_32 ( & V_16 -> V_23 ) = V_16 -> V_42 ;
F_12 ( V_16 -> V_22 ) ;
}
#ifdef F_13
V_16 -> V_27 = false ;
#endif
F_20 ( V_16 ) ;
return V_44 ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
V_16 -> V_23 . V_24 -> V_31 |= V_49 ;
}
bool F_34 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
F_11 ( V_16 ) ;
V_16 -> V_23 . V_24 -> V_31 &= ~ V_49 ;
F_32 ( & V_16 -> V_23 ) = V_16 -> V_42 ;
F_12 ( V_16 -> V_22 ) ;
if ( F_28 ( F_26 ( V_16 ) ) ) {
F_20 ( V_16 ) ;
return false ;
}
F_20 ( V_16 ) ;
return true ;
}
bool F_35 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
T_2 V_50 ;
F_11 ( V_16 ) ;
V_16 -> V_23 . V_24 -> V_31 &= ~ V_49 ;
V_50 = ( T_2 ) ( V_16 -> V_23 . V_24 -> V_25 - V_16 -> V_42 ) * 3 / 4 ;
F_32 ( & V_16 -> V_23 ) = V_16 -> V_42 + V_50 ;
F_12 ( V_16 -> V_22 ) ;
if ( F_28 ( ( T_2 ) ( V_16 -> V_23 . V_30 -> V_25 - V_16 -> V_42 ) > V_50 ) ) {
F_20 ( V_16 ) ;
return false ;
}
F_20 ( V_16 ) ;
return true ;
}
void * F_36 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
unsigned int V_13 ;
void * V_51 ;
F_11 ( V_16 ) ;
for ( V_13 = 0 ; V_13 < V_16 -> V_23 . V_17 ; V_13 ++ ) {
if ( ! V_16 -> V_8 [ V_13 ] )
continue;
V_51 = V_16 -> V_8 [ V_13 ] ;
F_23 ( V_16 , V_13 ) ;
V_16 -> V_23 . V_24 -> V_25 -- ;
F_20 ( V_16 ) ;
return V_51 ;
}
F_37 ( V_16 -> V_16 . V_40 != V_16 -> V_23 . V_17 ) ;
F_20 ( V_16 ) ;
return NULL ;
}
T_3 F_38 ( int V_52 , void * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
if ( ! F_26 ( V_16 ) ) {
F_29 ( L_4 , V_16 ) ;
return V_53 ;
}
if ( F_28 ( V_16 -> V_46 ) )
return V_54 ;
F_29 ( L_5 , V_16 , V_16 -> V_16 . V_55 ) ;
if ( V_16 -> V_16 . V_55 )
V_16 -> V_16 . V_55 ( & V_16 -> V_16 ) ;
return V_54 ;
}
struct V_4 * F_39 ( unsigned int V_56 ,
unsigned int V_17 ,
unsigned int V_57 ,
struct V_58 * V_59 ,
bool V_22 ,
void * V_60 ,
void (* V_33)( struct V_4 * ) ,
void (* V_55)( struct V_4 * ) ,
const char * V_61 )
{
struct V_18 * V_16 ;
unsigned int V_13 ;
if ( V_17 & ( V_17 - 1 ) ) {
F_40 ( & V_59 -> V_62 , L_6 , V_17 ) ;
return NULL ;
}
V_16 = F_41 ( sizeof( * V_16 ) + sizeof( void * ) * V_17 , V_63 ) ;
if ( ! V_16 )
return NULL ;
F_42 ( & V_16 -> V_23 , V_17 , V_60 , V_57 ) ;
V_16 -> V_16 . V_55 = V_55 ;
V_16 -> V_16 . V_59 = V_59 ;
V_16 -> V_16 . V_61 = V_61 ;
V_16 -> V_16 . V_40 = V_17 ;
V_16 -> V_16 . V_56 = V_56 ;
V_16 -> V_33 = V_33 ;
V_16 -> V_22 = V_22 ;
V_16 -> V_46 = false ;
V_16 -> V_42 = 0 ;
V_16 -> V_26 = 0 ;
F_43 ( & V_16 -> V_16 . V_64 , & V_59 -> V_65 ) ;
#ifdef F_13
V_16 -> V_66 = false ;
V_16 -> V_27 = false ;
#endif
V_16 -> V_67 = F_44 ( V_59 , V_68 ) ;
V_16 -> V_29 = F_44 ( V_59 , V_69 ) ;
if ( ! V_55 )
V_16 -> V_23 . V_24 -> V_31 |= V_49 ;
V_16 -> V_41 = 0 ;
for ( V_13 = 0 ; V_13 < V_17 - 1 ; V_13 ++ ) {
V_16 -> V_23 . V_35 [ V_13 ] . V_39 = V_13 + 1 ;
V_16 -> V_8 [ V_13 ] = NULL ;
}
V_16 -> V_8 [ V_13 ] = NULL ;
return & V_16 -> V_16 ;
}
void F_45 ( struct V_4 * V_16 )
{
F_46 ( & V_16 -> V_64 ) ;
F_24 ( F_10 ( V_16 ) ) ;
}
void F_47 ( struct V_58 * V_59 )
{
unsigned int V_13 ;
for ( V_13 = V_70 ; V_13 < V_71 ; V_13 ++ ) {
switch ( V_13 ) {
case V_68 :
break;
case V_69 :
break;
default:
F_48 ( V_13 , V_59 -> V_72 ) ;
}
}
}
unsigned int F_49 ( struct V_4 * V_5 )
{
struct V_18 * V_16 = F_10 ( V_5 ) ;
return V_16 -> V_23 . V_17 ;
}
