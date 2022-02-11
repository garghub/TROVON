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
#ifdef F_9
{
T_2 V_30 = F_10 () ;
if ( V_2 -> V_31 )
F_11 ( F_12 ( F_13 ( V_30 , V_2 -> V_32 ) )
> 100 ) ;
V_2 -> V_32 = V_30 ;
V_2 -> V_31 = true ;
}
#endif
if ( V_2 -> V_33 && ( V_5 + V_6 ) > 1 && V_2 -> V_20 ) {
V_10 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_14 ( V_10 >= 0 ) )
goto V_34;
}
F_8 ( V_5 + V_6 > V_2 -> V_22 . V_35 ) ;
F_8 ( V_5 + V_6 == 0 ) ;
if ( V_2 -> V_20 < V_5 + V_6 ) {
F_15 ( L_1 ,
V_5 + V_6 , V_2 -> V_20 ) ;
if ( V_5 )
V_2 -> V_36 ( & V_2 -> V_2 ) ;
F_16 ( V_2 ) ;
return - V_37 ;
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
V_34:
V_2 -> V_26 [ V_10 ] = V_26 ;
V_27 = ( V_2 -> V_22 . V_27 -> V_38 & ( V_2 -> V_22 . V_35 - 1 ) ) ;
V_2 -> V_22 . V_27 -> V_39 [ V_27 ] = V_10 ;
F_17 ( V_2 ) ;
V_2 -> V_22 . V_27 -> V_38 ++ ;
V_2 -> V_40 ++ ;
if ( F_18 ( V_2 -> V_40 == ( 1 << 16 ) - 1 ) )
F_19 ( V_25 ) ;
F_15 ( L_2 , V_10 , V_2 ) ;
F_16 ( V_2 ) ;
return V_2 -> V_20 ;
}
bool F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_3 V_41 , V_42 ;
bool V_43 ;
F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
V_42 = V_2 -> V_22 . V_27 -> V_38 - V_2 -> V_40 ;
V_41 = V_2 -> V_22 . V_27 -> V_38 ;
V_2 -> V_40 = 0 ;
#ifdef F_9
if ( V_2 -> V_31 ) {
F_11 ( F_12 ( F_13 ( F_10 () ,
V_2 -> V_32 ) ) > 100 ) ;
}
V_2 -> V_31 = false ;
#endif
if ( V_2 -> V_44 ) {
V_43 = F_22 ( F_23 ( & V_2 -> V_22 ) ,
V_41 , V_42 ) ;
} else {
V_43 = ! ( V_2 -> V_22 . V_45 -> V_13 & V_46 ) ;
}
F_16 ( V_2 ) ;
return V_43 ;
}
void F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_2 -> V_36 ( V_25 ) ;
}
void F_19 ( struct V_24 * V_2 )
{
if ( F_20 ( V_2 ) )
F_24 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned int V_11 ;
V_2 -> V_26 [ V_10 ] = NULL ;
V_11 = V_10 ;
if ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_23 )
F_26 ( F_27 ( V_2 -> V_22 . V_9 [ V_11 ] . V_15 ) ) ;
while ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_14 ) {
V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 ;
V_2 -> V_20 ++ ;
}
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_2 -> V_21 ;
V_2 -> V_21 = V_10 ;
V_2 -> V_20 ++ ;
}
static inline bool F_28 ( const struct V_1 * V_2 )
{
return V_2 -> V_47 != V_2 -> V_22 . V_45 -> V_38 ;
}
void * F_29 ( struct V_24 * V_25 , unsigned int * V_16 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
void * V_48 ;
unsigned int V_11 ;
T_3 V_49 ;
F_7 ( V_2 ) ;
if ( F_18 ( V_2 -> V_50 ) ) {
F_16 ( V_2 ) ;
return NULL ;
}
if ( ! F_28 ( V_2 ) ) {
F_15 ( L_3 ) ;
F_16 ( V_2 ) ;
return NULL ;
}
F_30 ( V_2 ) ;
V_49 = ( V_2 -> V_47 & ( V_2 -> V_22 . V_35 - 1 ) ) ;
V_11 = V_2 -> V_22 . V_45 -> V_39 [ V_49 ] . V_51 ;
* V_16 = V_2 -> V_22 . V_45 -> V_39 [ V_49 ] . V_16 ;
if ( F_18 ( V_11 >= V_2 -> V_22 . V_35 ) ) {
F_31 ( V_2 , L_4 , V_11 ) ;
return NULL ;
}
if ( F_18 ( ! V_2 -> V_26 [ V_11 ] ) ) {
F_31 ( V_2 , L_5 , V_11 ) ;
return NULL ;
}
V_48 = V_2 -> V_26 [ V_11 ] ;
F_25 ( V_2 , V_11 ) ;
V_2 -> V_47 ++ ;
if ( ! ( V_2 -> V_22 . V_27 -> V_13 & V_52 ) ) {
F_32 ( & V_2 -> V_22 ) = V_2 -> V_47 ;
F_21 ( V_2 ) ;
}
#ifdef F_9
V_2 -> V_31 = false ;
#endif
F_16 ( V_2 ) ;
return V_48 ;
}
void F_33 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_2 -> V_22 . V_27 -> V_13 |= V_52 ;
}
bool F_34 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_7 ( V_2 ) ;
V_2 -> V_22 . V_27 -> V_13 &= ~ V_52 ;
F_32 ( & V_2 -> V_22 ) = V_2 -> V_47 ;
F_21 ( V_2 ) ;
if ( F_18 ( F_28 ( V_2 ) ) ) {
F_16 ( V_2 ) ;
return false ;
}
F_16 ( V_2 ) ;
return true ;
}
bool F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_3 V_53 ;
F_7 ( V_2 ) ;
V_2 -> V_22 . V_27 -> V_13 &= ~ V_52 ;
V_53 = ( T_3 ) ( V_2 -> V_22 . V_27 -> V_38 - V_2 -> V_47 ) * 3 / 4 ;
F_32 ( & V_2 -> V_22 ) = V_2 -> V_47 + V_53 ;
F_21 ( V_2 ) ;
if ( F_18 ( ( T_3 ) ( V_2 -> V_22 . V_45 -> V_38 - V_2 -> V_47 ) > V_53 ) ) {
F_16 ( V_2 ) ;
return false ;
}
F_16 ( V_2 ) ;
return true ;
}
void * F_36 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned int V_11 ;
void * V_54 ;
F_7 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_22 . V_35 ; V_11 ++ ) {
if ( ! V_2 -> V_26 [ V_11 ] )
continue;
V_54 = V_2 -> V_26 [ V_11 ] ;
F_25 ( V_2 , V_11 ) ;
V_2 -> V_22 . V_27 -> V_38 -- ;
F_16 ( V_2 ) ;
return V_54 ;
}
F_8 ( V_2 -> V_20 != V_2 -> V_22 . V_35 ) ;
F_16 ( V_2 ) ;
return NULL ;
}
T_4 F_37 ( int V_55 , void * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_28 ( V_2 ) ) {
F_15 ( L_6 , V_2 ) ;
return V_56 ;
}
if ( F_18 ( V_2 -> V_50 ) )
return V_57 ;
F_15 ( L_7 , V_2 , V_2 -> V_2 . V_58 ) ;
if ( V_2 -> V_2 . V_58 )
V_2 -> V_2 . V_58 ( & V_2 -> V_2 ) ;
return V_57 ;
}
struct V_24 * F_38 ( unsigned int V_35 ,
unsigned int V_59 ,
struct V_60 * V_61 ,
bool V_62 ,
void * V_63 ,
void (* V_36)( struct V_24 * ) ,
void (* V_58)( struct V_24 * ) ,
const char * V_64 )
{
struct V_1 * V_2 ;
unsigned int V_11 ;
if ( V_35 & ( V_35 - 1 ) ) {
F_39 ( & V_61 -> V_65 , L_8 , V_35 ) ;
return NULL ;
}
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( void * ) * V_35 , V_66 ) ;
if ( ! V_2 )
return NULL ;
F_40 ( & V_2 -> V_22 , V_35 , V_63 , V_59 ) ;
V_2 -> V_2 . V_58 = V_58 ;
V_2 -> V_2 . V_61 = V_61 ;
V_2 -> V_2 . V_64 = V_64 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_50 = false ;
V_2 -> V_47 = 0 ;
V_2 -> V_40 = 0 ;
F_41 ( & V_2 -> V_2 . V_67 , & V_61 -> V_68 ) ;
#ifdef F_9
V_2 -> V_69 = false ;
V_2 -> V_31 = false ;
#endif
V_2 -> V_33 = F_42 ( V_61 , V_70 ) ;
V_2 -> V_44 = F_42 ( V_61 , V_71 ) ;
if ( ! V_58 )
V_2 -> V_22 . V_27 -> V_13 |= V_52 ;
V_2 -> V_20 = V_35 ;
V_2 -> V_21 = 0 ;
for ( V_11 = 0 ; V_11 < V_35 - 1 ; V_11 ++ ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_11 + 1 ;
V_2 -> V_26 [ V_11 ] = NULL ;
}
V_2 -> V_26 [ V_11 ] = NULL ;
return & V_2 -> V_2 ;
}
void F_43 ( struct V_24 * V_2 )
{
F_44 ( & V_2 -> V_67 ) ;
F_26 ( F_6 ( V_2 ) ) ;
}
void F_45 ( struct V_60 * V_61 )
{
unsigned int V_11 ;
for ( V_11 = V_72 ; V_11 < V_73 ; V_11 ++ ) {
switch ( V_11 ) {
case V_70 :
break;
case V_71 :
break;
default:
F_46 ( V_11 , V_61 -> V_74 ) ;
}
}
}
unsigned int F_47 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
return V_2 -> V_22 . V_35 ;
}
