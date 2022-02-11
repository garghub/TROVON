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
int F_5 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
return V_2 -> V_26 ;
}
int F_7 ( struct V_24 * V_25 ,
struct V_3 V_4 [] ,
unsigned int V_5 ,
unsigned int V_6 ,
void * V_27 ,
T_1 V_7 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned int V_11 , V_28 , V_29 ( V_30 ) ;
int V_10 ;
F_8 ( V_2 ) ;
F_9 ( V_27 == NULL ) ;
#ifdef F_10
{
T_2 V_31 = F_11 () ;
if ( V_2 -> V_32 )
F_12 ( F_13 ( F_14 ( V_31 , V_2 -> V_33 ) )
> 100 ) ;
V_2 -> V_33 = V_31 ;
V_2 -> V_32 = true ;
}
#endif
if ( V_2 -> V_34 && ( V_5 + V_6 ) > 1 && V_2 -> V_20 ) {
V_10 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_15 ( V_10 >= 0 ) )
goto V_35;
}
F_9 ( V_5 + V_6 > V_2 -> V_22 . V_36 ) ;
F_9 ( V_5 + V_6 == 0 ) ;
if ( V_2 -> V_20 < V_5 + V_6 ) {
F_16 ( L_1 ,
V_5 + V_6 , V_2 -> V_20 ) ;
if ( V_5 )
V_2 -> V_37 ( & V_2 -> V_2 ) ;
F_17 ( V_2 ) ;
return - V_38 ;
}
V_2 -> V_20 -= V_5 + V_6 ;
V_10 = V_2 -> V_21 ;
for ( V_11 = V_2 -> V_21 ; V_5 ; V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 , V_5 -- ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_13 = V_14 ;
V_2 -> V_22 . V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_2 -> V_22 . V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_30 = V_11 ;
V_4 ++ ;
}
for (; V_6 ; V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 , V_6 -- ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_13 = V_14 | V_19 ;
V_2 -> V_22 . V_9 [ V_11 ] . V_15 = F_3 ( V_4 ) ;
V_2 -> V_22 . V_9 [ V_11 ] . V_16 = V_4 -> V_17 ;
V_30 = V_11 ;
V_4 ++ ;
}
V_2 -> V_22 . V_9 [ V_30 ] . V_13 &= ~ V_14 ;
V_2 -> V_21 = V_11 ;
V_35:
V_2 -> V_27 [ V_10 ] = V_27 ;
V_28 = ( V_2 -> V_22 . V_28 -> V_39 & ( V_2 -> V_22 . V_36 - 1 ) ) ;
V_2 -> V_22 . V_28 -> V_40 [ V_28 ] = V_10 ;
F_18 ( V_2 ) ;
V_2 -> V_22 . V_28 -> V_39 ++ ;
V_2 -> V_41 ++ ;
if ( F_19 ( V_2 -> V_41 == ( 1 << 16 ) - 1 ) )
F_20 ( V_25 ) ;
F_16 ( L_2 , V_10 , V_2 ) ;
F_17 ( V_2 ) ;
return V_2 -> V_20 ;
}
bool F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_3 V_42 , V_43 ;
bool V_44 ;
F_8 ( V_2 ) ;
F_22 ( V_2 ) ;
V_43 = V_2 -> V_22 . V_28 -> V_39 - V_2 -> V_41 ;
V_42 = V_2 -> V_22 . V_28 -> V_39 ;
V_2 -> V_41 = 0 ;
#ifdef F_10
if ( V_2 -> V_32 ) {
F_12 ( F_13 ( F_14 ( F_11 () ,
V_2 -> V_33 ) ) > 100 ) ;
}
V_2 -> V_32 = false ;
#endif
if ( V_2 -> V_45 ) {
V_44 = F_23 ( F_24 ( & V_2 -> V_22 ) ,
V_42 , V_43 ) ;
} else {
V_44 = ! ( V_2 -> V_22 . V_46 -> V_13 & V_47 ) ;
}
F_17 ( V_2 ) ;
return V_44 ;
}
void F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_2 -> V_37 ( V_25 ) ;
}
void F_20 ( struct V_24 * V_2 )
{
if ( F_21 ( V_2 ) )
F_25 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned int V_11 ;
V_2 -> V_27 [ V_10 ] = NULL ;
V_11 = V_10 ;
if ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_23 )
F_27 ( F_28 ( V_2 -> V_22 . V_9 [ V_11 ] . V_15 ) ) ;
while ( V_2 -> V_22 . V_9 [ V_11 ] . V_13 & V_14 ) {
V_11 = V_2 -> V_22 . V_9 [ V_11 ] . V_18 ;
V_2 -> V_20 ++ ;
}
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_2 -> V_21 ;
V_2 -> V_21 = V_10 ;
V_2 -> V_20 ++ ;
}
static inline bool F_29 ( const struct V_1 * V_2 )
{
return V_2 -> V_48 != V_2 -> V_22 . V_46 -> V_39 ;
}
void * F_30 ( struct V_24 * V_25 , unsigned int * V_16 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
void * V_49 ;
unsigned int V_11 ;
T_3 V_50 ;
F_8 ( V_2 ) ;
if ( F_19 ( V_2 -> V_51 ) ) {
F_17 ( V_2 ) ;
return NULL ;
}
if ( ! F_29 ( V_2 ) ) {
F_16 ( L_3 ) ;
F_17 ( V_2 ) ;
return NULL ;
}
F_31 ( V_2 ) ;
V_50 = ( V_2 -> V_48 & ( V_2 -> V_22 . V_36 - 1 ) ) ;
V_11 = V_2 -> V_22 . V_46 -> V_40 [ V_50 ] . V_52 ;
* V_16 = V_2 -> V_22 . V_46 -> V_40 [ V_50 ] . V_16 ;
if ( F_19 ( V_11 >= V_2 -> V_22 . V_36 ) ) {
F_32 ( V_2 , L_4 , V_11 ) ;
return NULL ;
}
if ( F_19 ( ! V_2 -> V_27 [ V_11 ] ) ) {
F_32 ( V_2 , L_5 , V_11 ) ;
return NULL ;
}
V_49 = V_2 -> V_27 [ V_11 ] ;
F_26 ( V_2 , V_11 ) ;
V_2 -> V_48 ++ ;
if ( ! ( V_2 -> V_22 . V_28 -> V_13 & V_53 ) ) {
F_33 ( & V_2 -> V_22 ) = V_2 -> V_48 ;
F_22 ( V_2 ) ;
}
#ifdef F_10
V_2 -> V_32 = false ;
#endif
F_17 ( V_2 ) ;
return V_49 ;
}
void F_34 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_2 -> V_22 . V_28 -> V_13 |= V_53 ;
}
bool F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_8 ( V_2 ) ;
V_2 -> V_22 . V_28 -> V_13 &= ~ V_53 ;
F_33 ( & V_2 -> V_22 ) = V_2 -> V_48 ;
F_22 ( V_2 ) ;
if ( F_19 ( F_29 ( V_2 ) ) ) {
F_17 ( V_2 ) ;
return false ;
}
F_17 ( V_2 ) ;
return true ;
}
bool F_36 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_3 V_54 ;
F_8 ( V_2 ) ;
V_2 -> V_22 . V_28 -> V_13 &= ~ V_53 ;
V_54 = ( T_3 ) ( V_2 -> V_22 . V_28 -> V_39 - V_2 -> V_48 ) * 3 / 4 ;
F_33 ( & V_2 -> V_22 ) = V_2 -> V_48 + V_54 ;
F_22 ( V_2 ) ;
if ( F_19 ( ( T_3 ) ( V_2 -> V_22 . V_46 -> V_39 - V_2 -> V_48 ) > V_54 ) ) {
F_17 ( V_2 ) ;
return false ;
}
F_17 ( V_2 ) ;
return true ;
}
void * F_37 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned int V_11 ;
void * V_55 ;
F_8 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_22 . V_36 ; V_11 ++ ) {
if ( ! V_2 -> V_27 [ V_11 ] )
continue;
V_55 = V_2 -> V_27 [ V_11 ] ;
F_26 ( V_2 , V_11 ) ;
V_2 -> V_22 . V_28 -> V_39 -- ;
F_17 ( V_2 ) ;
return V_55 ;
}
F_9 ( V_2 -> V_20 != V_2 -> V_22 . V_36 ) ;
F_17 ( V_2 ) ;
return NULL ;
}
T_4 F_38 ( int V_56 , void * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_29 ( V_2 ) ) {
F_16 ( L_6 , V_2 ) ;
return V_57 ;
}
if ( F_19 ( V_2 -> V_51 ) )
return V_58 ;
F_16 ( L_7 , V_2 , V_2 -> V_2 . V_59 ) ;
if ( V_2 -> V_2 . V_59 )
V_2 -> V_2 . V_59 ( & V_2 -> V_2 ) ;
return V_58 ;
}
struct V_24 * F_39 ( unsigned int V_60 ,
unsigned int V_36 ,
unsigned int V_61 ,
struct V_62 * V_63 ,
bool V_64 ,
void * V_65 ,
void (* V_37)( struct V_24 * ) ,
void (* V_59)( struct V_24 * ) ,
const char * V_66 )
{
struct V_1 * V_2 ;
unsigned int V_11 ;
if ( V_36 & ( V_36 - 1 ) ) {
F_40 ( & V_63 -> V_67 , L_8 , V_36 ) ;
return NULL ;
}
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( void * ) * V_36 , V_68 ) ;
if ( ! V_2 )
return NULL ;
F_41 ( & V_2 -> V_22 , V_36 , V_65 , V_61 ) ;
V_2 -> V_2 . V_59 = V_59 ;
V_2 -> V_2 . V_63 = V_63 ;
V_2 -> V_2 . V_66 = V_66 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_51 = false ;
V_2 -> V_48 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_26 = V_60 ;
F_42 ( & V_2 -> V_2 . V_69 , & V_63 -> V_70 ) ;
#ifdef F_10
V_2 -> V_71 = false ;
V_2 -> V_32 = false ;
#endif
V_2 -> V_34 = F_43 ( V_63 , V_72 ) ;
V_2 -> V_45 = F_43 ( V_63 , V_73 ) ;
if ( ! V_59 )
V_2 -> V_22 . V_28 -> V_13 |= V_53 ;
V_2 -> V_20 = V_36 ;
V_2 -> V_21 = 0 ;
for ( V_11 = 0 ; V_11 < V_36 - 1 ; V_11 ++ ) {
V_2 -> V_22 . V_9 [ V_11 ] . V_18 = V_11 + 1 ;
V_2 -> V_27 [ V_11 ] = NULL ;
}
V_2 -> V_27 [ V_11 ] = NULL ;
return & V_2 -> V_2 ;
}
void F_44 ( struct V_24 * V_2 )
{
F_45 ( & V_2 -> V_69 ) ;
F_27 ( F_6 ( V_2 ) ) ;
}
void F_46 ( struct V_62 * V_63 )
{
unsigned int V_11 ;
for ( V_11 = V_74 ; V_11 < V_75 ; V_11 ++ ) {
switch ( V_11 ) {
case V_72 :
break;
case V_73 :
break;
default:
F_47 ( V_11 , V_63 -> V_76 ) ;
}
}
}
unsigned int F_48 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
return V_2 -> V_22 . V_36 ;
}
