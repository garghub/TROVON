static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] ,
unsigned int V_5 ,
unsigned int V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 ;
unsigned V_10 ;
int V_11 ;
V_9 = F_2 ( ( V_5 + V_6 ) * sizeof( struct V_8 ) , V_7 ) ;
if ( ! V_9 )
return - V_12 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
V_9 [ V_11 ] . V_13 = V_14 ;
V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_9 [ V_11 ] . V_18 = V_11 + 1 ;
V_4 ++ ;
}
for (; V_11 < ( V_5 + V_6 ) ; V_11 ++ ) {
V_9 [ V_11 ] . V_13 = V_14 | V_19 ;
V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_9 [ V_11 ] . V_18 = V_11 + 1 ;
V_4 ++ ;
}
V_9 [ V_11 - 1 ] . V_13 &= ~ V_14 ;
V_9 [ V_11 - 1 ] . V_18 = 0 ;
V_2 -> V_20 -- ;
V_10 = V_2 -> V_21 ;
V_2 -> V_22 . V_9 [ V_10 ] . V_13 = V_23 ;
V_2 -> V_22 . V_9 [ V_10 ] . V_15 = F_4 ( V_9 ) ;
V_2 -> V_22 . V_9 [ V_10 ] . V_16 = V_11 * sizeof( struct V_8 ) ;
V_2 -> V_21 = V_2 -> V_22 . V_9 [ V_10 ] . V_18 ;
return V_10 ;
}
int F_5 ( struct V_24 * V_25 ,
struct V_3 V_4 [] ,
unsigned int V_5 ,
unsigned int V_6 ,
void * V_26 ,
T_1 V_7 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned int V_11 , V_27 , V_28 ( V_29 ) ;
int V_10 ;
F_7 ( V_2 ) ;
F_8 ( V_26 == NULL ) ;
if ( V_2 -> V_30 && ( V_5 + V_6 ) > 1 && V_2 -> V_20 ) {
V_10 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_9 ( V_10 >= 0 ) )
goto V_31;
}
F_8 ( V_5 + V_6 > V_2 -> V_22 . V_32 ) ;
F_8 ( V_5 + V_6 == 0 ) ;
if ( V_2 -> V_20 < V_5 + V_6 ) {
F_10 ( L_1 ,
V_5 + V_6 , V_2 -> V_20 ) ;
if ( V_5 )
V_2 -> V_33 ( & V_2 -> V_2 ) ;
F_11 ( V_2 ) ;
return - V_34 ;
}
V_2 -> V_20 -= V_5 + V_6 ;
V_10 = V_2 -> V_21 ;
for ( V_11 = V_2 -> V_21 ; V_5 ; V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 , V_5 -- ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_13 = V_14 ;
V_2 -> V_22 . V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_2 -> V_22 . V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_29 = V_11 ;
V_4 ++ ;
}
for (; V_6 ; V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 , V_6 -- ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_13 = V_14 | V_19 ;
V_2 -> V_22 . V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_2 -> V_22 . V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_29 = V_11 ;
V_4 ++ ;
}
V_2 -> V_22 . V_9 [ V_29 ] . V_13 &= ~ V_14 ;
V_2 -> V_21 = V_11 ;
V_31:
V_2 -> V_26 [ V_10 ] = V_26 ;
V_27 = ( V_2 -> V_22 . V_27 -> V_35 + V_2 -> V_36 ++ ) % V_2 -> V_22 . V_32 ;
V_2 -> V_22 . V_27 -> V_37 [ V_27 ] = V_10 ;
F_10 ( L_2 , V_10 , V_2 ) ;
F_11 ( V_2 ) ;
return V_2 -> V_20 ;
}
void F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 V_38 , V_39 ;
F_7 ( V_2 ) ;
F_13 () ;
V_39 = V_2 -> V_22 . V_27 -> V_35 ;
V_38 = V_2 -> V_22 . V_27 -> V_35 = V_39 + V_2 -> V_36 ;
V_2 -> V_36 = 0 ;
F_14 () ;
if ( V_2 -> V_40 ?
F_15 ( F_16 ( & V_2 -> V_22 ) , V_38 , V_39 ) :
! ( V_2 -> V_22 . V_41 -> V_13 & V_42 ) )
V_2 -> V_33 ( & V_2 -> V_2 ) ;
F_11 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned int V_11 ;
V_2 -> V_26 [ V_10 ] = NULL ;
V_11 = V_10 ;
if ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_23 )
F_18 ( F_19 ( V_2 -> V_22 . V_9 [ V_11 ] . V_15 ) ) ;
while ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_14 ) {
V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 ;
V_2 -> V_20 ++ ;
}
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_2 -> V_21 ;
V_2 -> V_21 = V_10 ;
V_2 -> V_20 ++ ;
}
static inline bool F_20 ( const struct V_1 * V_2 )
{
return V_2 -> V_43 != V_2 -> V_22 . V_41 -> V_35 ;
}
void * F_21 ( struct V_24 * V_25 , unsigned int * V_16 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
void * V_44 ;
unsigned int V_11 ;
F_7 ( V_2 ) ;
if ( F_22 ( V_2 -> V_45 ) ) {
F_11 ( V_2 ) ;
return NULL ;
}
if ( ! F_20 ( V_2 ) ) {
F_10 ( L_3 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
F_23 () ;
V_11 = V_2 -> V_22 . V_41 -> V_37 [ V_2 -> V_43 % V_2 -> V_22 . V_32 ] . V_46 ;
* V_16 = V_2 -> V_22 . V_41 -> V_37 [ V_2 -> V_43 % V_2 -> V_22 . V_32 ] . V_16 ;
if ( F_22 ( V_11 >= V_2 -> V_22 . V_32 ) ) {
F_24 ( V_2 , L_4 , V_11 ) ;
return NULL ;
}
if ( F_22 ( ! V_2 -> V_26 [ V_11 ] ) ) {
F_24 ( V_2 , L_5 , V_11 ) ;
return NULL ;
}
V_44 = V_2 -> V_26 [ V_11 ] ;
F_17 ( V_2 , V_11 ) ;
V_2 -> V_43 ++ ;
if ( ! ( V_2 -> V_22 . V_27 -> V_13 & V_47 ) ) {
F_25 ( & V_2 -> V_22 ) = V_2 -> V_43 ;
F_14 () ;
}
F_11 ( V_2 ) ;
return V_44 ;
}
void F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_2 -> V_22 . V_27 -> V_13 |= V_47 ;
}
bool F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_7 ( V_2 ) ;
V_2 -> V_22 . V_27 -> V_13 &= ~ V_47 ;
F_25 ( & V_2 -> V_22 ) = V_2 -> V_43 ;
F_14 () ;
if ( F_22 ( F_20 ( V_2 ) ) ) {
F_11 ( V_2 ) ;
return false ;
}
F_11 ( V_2 ) ;
return true ;
}
bool F_28 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 V_48 ;
F_7 ( V_2 ) ;
V_2 -> V_22 . V_27 -> V_13 &= ~ V_47 ;
V_48 = ( T_2 ) ( V_2 -> V_22 . V_27 -> V_35 - V_2 -> V_43 ) * 3 / 4 ;
F_25 ( & V_2 -> V_22 ) = V_2 -> V_43 + V_48 ;
F_14 () ;
if ( F_22 ( ( T_2 ) ( V_2 -> V_22 . V_41 -> V_35 - V_2 -> V_43 ) > V_48 ) ) {
F_11 ( V_2 ) ;
return false ;
}
F_11 ( V_2 ) ;
return true ;
}
void * F_29 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned int V_11 ;
void * V_49 ;
F_7 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_22 . V_32 ; V_11 ++ ) {
if ( ! V_2 -> V_26 [ V_11 ] )
continue;
V_49 = V_2 -> V_26 [ V_11 ] ;
F_17 ( V_2 , V_11 ) ;
V_2 -> V_22 . V_27 -> V_35 -- ;
F_11 ( V_2 ) ;
return V_49 ;
}
F_8 ( V_2 -> V_20 != V_2 -> V_22 . V_32 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
T_3 F_30 ( int V_50 , void * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_20 ( V_2 ) ) {
F_10 ( L_6 , V_2 ) ;
return V_51 ;
}
if ( F_22 ( V_2 -> V_45 ) )
return V_52 ;
F_10 ( L_7 , V_2 , V_2 -> V_2 . V_53 ) ;
if ( V_2 -> V_2 . V_53 )
V_2 -> V_2 . V_53 ( & V_2 -> V_2 ) ;
return V_52 ;
}
struct V_24 * F_31 ( unsigned int V_32 ,
unsigned int V_54 ,
struct V_55 * V_56 ,
void * V_57 ,
void (* V_33)( struct V_24 * ) ,
void (* V_53)( struct V_24 * ) ,
const char * V_58 )
{
struct V_1 * V_2 ;
unsigned int V_11 ;
if ( V_32 & ( V_32 - 1 ) ) {
F_32 ( & V_56 -> V_59 , L_8 , V_32 ) ;
return NULL ;
}
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( void * ) * V_32 , V_60 ) ;
if ( ! V_2 )
return NULL ;
F_33 ( & V_2 -> V_22 , V_32 , V_57 , V_54 ) ;
V_2 -> V_2 . V_53 = V_53 ;
V_2 -> V_2 . V_56 = V_56 ;
V_2 -> V_2 . V_58 = V_58 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_45 = false ;
V_2 -> V_43 = 0 ;
V_2 -> V_36 = 0 ;
F_34 ( & V_2 -> V_2 . V_61 , & V_56 -> V_62 ) ;
#ifdef F_35
V_2 -> V_63 = false ;
#endif
V_2 -> V_30 = F_36 ( V_56 , V_64 ) ;
V_2 -> V_40 = F_36 ( V_56 , V_65 ) ;
if ( ! V_53 )
V_2 -> V_22 . V_27 -> V_13 |= V_47 ;
V_2 -> V_20 = V_32 ;
V_2 -> V_21 = 0 ;
for ( V_11 = 0 ; V_11 < V_32 - 1 ; V_11 ++ ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_11 + 1 ;
V_2 -> V_26 [ V_11 ] = NULL ;
}
V_2 -> V_26 [ V_11 ] = NULL ;
return & V_2 -> V_2 ;
}
void F_37 ( struct V_24 * V_2 )
{
F_38 ( & V_2 -> V_61 ) ;
F_18 ( F_6 ( V_2 ) ) ;
}
void F_39 ( struct V_55 * V_56 )
{
unsigned int V_11 ;
for ( V_11 = V_66 ; V_11 < V_67 ; V_11 ++ ) {
switch ( V_11 ) {
case V_64 :
break;
case V_65 :
break;
default:
F_40 ( V_11 , V_56 -> V_68 ) ;
}
}
}
