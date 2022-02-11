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
struct V_1 * V_6 [] ,
unsigned int V_7 ,
unsigned int V_8 ,
void * V_9 ,
T_1 V_10 )
{
unsigned int V_11 , V_12 , V_13 ;
for ( V_11 = V_12 = V_13 = 0 ; V_11 < V_7 ; V_11 ++ ) {
struct V_1 * V_2 ;
for ( V_2 = V_6 [ V_11 ] ; V_2 ; V_2 = F_2 ( V_2 ) )
V_12 ++ ;
}
for (; V_11 < V_7 + V_8 ; V_11 ++ ) {
struct V_1 * V_2 ;
for ( V_2 = V_6 [ V_11 ] ; V_2 ; V_2 = F_2 ( V_2 ) )
V_13 ++ ;
}
return F_5 ( V_5 , V_6 , F_1 ,
V_12 , V_13 , V_7 , V_8 , V_9 , V_10 ) ;
}
int F_6 ( struct V_4 * V_14 ,
struct V_1 V_2 [] , unsigned int V_15 ,
void * V_9 ,
T_1 V_10 )
{
return F_5 ( V_14 , & V_2 , F_3 , V_15 , 0 , 1 , 0 , V_9 , V_10 ) ;
}
int F_7 ( struct V_4 * V_14 ,
struct V_1 V_2 [] , unsigned int V_15 ,
void * V_9 ,
T_1 V_10 )
{
return F_5 ( V_14 , & V_2 , F_3 , 0 , V_15 , 0 , 1 , V_9 , V_10 ) ;
}
bool F_8 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
T_2 V_17 , V_18 ;
bool V_19 ;
F_10 ( V_14 ) ;
F_11 ( V_14 -> V_20 ) ;
V_18 = V_14 -> V_21 . V_22 -> V_23 - V_14 -> V_24 ;
V_17 = V_14 -> V_21 . V_22 -> V_23 ;
V_14 -> V_24 = 0 ;
#ifdef F_12
if ( V_14 -> V_25 ) {
F_13 ( F_14 ( F_15 ( F_16 () ,
V_14 -> V_26 ) ) > 100 ) ;
}
V_14 -> V_25 = false ;
#endif
if ( V_14 -> V_27 ) {
V_19 = F_17 ( F_18 ( & V_14 -> V_21 ) ,
V_17 , V_18 ) ;
} else {
V_19 = ! ( V_14 -> V_21 . V_28 -> V_29 & V_30 ) ;
}
F_19 ( V_14 ) ;
return V_19 ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
V_14 -> V_31 ( V_5 ) ;
}
void F_21 ( struct V_4 * V_14 )
{
if ( F_8 ( V_14 ) )
F_20 ( V_14 ) ;
}
static void F_22 ( struct V_16 * V_14 , unsigned int V_32 )
{
unsigned int V_11 ;
V_14 -> V_9 [ V_32 ] = NULL ;
V_11 = V_32 ;
if ( V_14 -> V_21 . V_33 [ V_11 ] . V_29 & V_34 )
F_23 ( F_24 ( V_14 -> V_21 . V_33 [ V_11 ] . V_35 ) ) ;
while ( V_14 -> V_21 . V_33 [ V_11 ] . V_29 & V_36 ) {
V_11 = V_14 -> V_21 . V_33 [ V_11 ] . V_37 ;
V_14 -> V_14 . V_38 ++ ;
}
V_14 -> V_21 . V_33 [ V_11 ] . V_37 = V_14 -> V_39 ;
V_14 -> V_39 = V_32 ;
V_14 -> V_14 . V_38 ++ ;
}
static inline bool F_25 ( const struct V_16 * V_14 )
{
return V_14 -> V_40 != V_14 -> V_21 . V_28 -> V_23 ;
}
void * F_26 ( struct V_4 * V_5 , unsigned int * V_41 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
void * V_42 ;
unsigned int V_11 ;
T_2 V_43 ;
F_10 ( V_14 ) ;
if ( F_27 ( V_14 -> V_44 ) ) {
F_19 ( V_14 ) ;
return NULL ;
}
if ( ! F_25 ( V_14 ) ) {
F_28 ( L_1 ) ;
F_19 ( V_14 ) ;
return NULL ;
}
F_29 ( V_14 -> V_20 ) ;
V_43 = ( V_14 -> V_40 & ( V_14 -> V_21 . V_15 - 1 ) ) ;
V_11 = V_14 -> V_21 . V_28 -> V_45 [ V_43 ] . V_46 ;
* V_41 = V_14 -> V_21 . V_28 -> V_45 [ V_43 ] . V_41 ;
if ( F_27 ( V_11 >= V_14 -> V_21 . V_15 ) ) {
F_30 ( V_14 , L_2 , V_11 ) ;
return NULL ;
}
if ( F_27 ( ! V_14 -> V_9 [ V_11 ] ) ) {
F_30 ( V_14 , L_3 , V_11 ) ;
return NULL ;
}
V_42 = V_14 -> V_9 [ V_11 ] ;
F_22 ( V_14 , V_11 ) ;
V_14 -> V_40 ++ ;
if ( ! ( V_14 -> V_21 . V_22 -> V_29 & V_47 ) ) {
F_31 ( & V_14 -> V_21 ) = V_14 -> V_40 ;
F_11 ( V_14 -> V_20 ) ;
}
#ifdef F_12
V_14 -> V_25 = false ;
#endif
F_19 ( V_14 ) ;
return V_42 ;
}
void F_32 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
V_14 -> V_21 . V_22 -> V_29 |= V_47 ;
}
unsigned F_33 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
T_2 V_40 ;
F_10 ( V_14 ) ;
V_14 -> V_21 . V_22 -> V_29 &= ~ V_47 ;
F_31 ( & V_14 -> V_21 ) = V_40 = V_14 -> V_40 ;
F_19 ( V_14 ) ;
return V_40 ;
}
bool F_34 ( struct V_4 * V_5 , unsigned V_40 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
F_11 ( V_14 -> V_20 ) ;
return ( T_2 ) V_40 != V_14 -> V_21 . V_28 -> V_23 ;
}
bool F_35 ( struct V_4 * V_5 )
{
unsigned V_40 = F_33 ( V_5 ) ;
return ! F_34 ( V_5 , V_40 ) ;
}
bool F_36 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
T_2 V_48 ;
F_10 ( V_14 ) ;
V_14 -> V_21 . V_22 -> V_29 &= ~ V_47 ;
V_48 = ( T_2 ) ( V_14 -> V_21 . V_22 -> V_23 - V_14 -> V_40 ) * 3 / 4 ;
F_31 ( & V_14 -> V_21 ) = V_14 -> V_40 + V_48 ;
F_11 ( V_14 -> V_20 ) ;
if ( F_27 ( ( T_2 ) ( V_14 -> V_21 . V_28 -> V_23 - V_14 -> V_40 ) > V_48 ) ) {
F_19 ( V_14 ) ;
return false ;
}
F_19 ( V_14 ) ;
return true ;
}
void * F_37 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
unsigned int V_11 ;
void * V_49 ;
F_10 ( V_14 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_21 . V_15 ; V_11 ++ ) {
if ( ! V_14 -> V_9 [ V_11 ] )
continue;
V_49 = V_14 -> V_9 [ V_11 ] ;
F_22 ( V_14 , V_11 ) ;
V_14 -> V_21 . V_22 -> V_23 -- ;
F_19 ( V_14 ) ;
return V_49 ;
}
F_38 ( V_14 -> V_14 . V_38 != V_14 -> V_21 . V_15 ) ;
F_19 ( V_14 ) ;
return NULL ;
}
T_3 F_39 ( int V_50 , void * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
if ( ! F_25 ( V_14 ) ) {
F_28 ( L_4 , V_14 ) ;
return V_51 ;
}
if ( F_27 ( V_14 -> V_44 ) )
return V_52 ;
F_28 ( L_5 , V_14 , V_14 -> V_14 . V_53 ) ;
if ( V_14 -> V_14 . V_53 )
V_14 -> V_14 . V_53 ( & V_14 -> V_14 ) ;
return V_52 ;
}
struct V_4 * F_40 ( unsigned int V_54 ,
unsigned int V_15 ,
unsigned int V_55 ,
struct V_56 * V_57 ,
bool V_20 ,
void * V_58 ,
void (* V_31)( struct V_4 * ) ,
void (* V_53)( struct V_4 * ) ,
const char * V_59 )
{
struct V_16 * V_14 ;
unsigned int V_11 ;
if ( V_15 & ( V_15 - 1 ) ) {
F_41 ( & V_57 -> V_60 , L_6 , V_15 ) ;
return NULL ;
}
V_14 = F_42 ( sizeof( * V_14 ) + sizeof( void * ) * V_15 , V_61 ) ;
if ( ! V_14 )
return NULL ;
F_43 ( & V_14 -> V_21 , V_15 , V_58 , V_55 ) ;
V_14 -> V_14 . V_53 = V_53 ;
V_14 -> V_14 . V_57 = V_57 ;
V_14 -> V_14 . V_59 = V_59 ;
V_14 -> V_14 . V_38 = V_15 ;
V_14 -> V_14 . V_54 = V_54 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_20 = V_20 ;
V_14 -> V_44 = false ;
V_14 -> V_40 = 0 ;
V_14 -> V_24 = 0 ;
F_44 ( & V_14 -> V_14 . V_62 , & V_57 -> V_63 ) ;
#ifdef F_12
V_14 -> V_64 = false ;
V_14 -> V_25 = false ;
#endif
V_14 -> V_65 = F_45 ( V_57 , V_66 ) ;
V_14 -> V_27 = F_45 ( V_57 , V_67 ) ;
if ( ! V_53 )
V_14 -> V_21 . V_22 -> V_29 |= V_47 ;
V_14 -> V_39 = 0 ;
for ( V_11 = 0 ; V_11 < V_15 - 1 ; V_11 ++ ) {
V_14 -> V_21 . V_33 [ V_11 ] . V_37 = V_11 + 1 ;
V_14 -> V_9 [ V_11 ] = NULL ;
}
V_14 -> V_9 [ V_11 ] = NULL ;
return & V_14 -> V_14 ;
}
void F_46 ( struct V_4 * V_14 )
{
F_47 ( & V_14 -> V_62 ) ;
F_23 ( F_9 ( V_14 ) ) ;
}
void F_48 ( struct V_56 * V_57 )
{
unsigned int V_11 ;
for ( V_11 = V_68 ; V_11 < V_69 ; V_11 ++ ) {
switch ( V_11 ) {
case V_66 :
break;
case V_67 :
break;
default:
F_49 ( V_11 , V_57 -> V_70 ) ;
}
}
}
unsigned int F_50 ( struct V_4 * V_5 )
{
struct V_16 * V_14 = F_9 ( V_5 ) ;
return V_14 -> V_21 . V_15 ;
}
